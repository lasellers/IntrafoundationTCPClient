/*$T tcp.cpp GC 1.138 06/16/04 13:35:28 */

/////////////////////////////////////////////////////////////////////////////
//
// Intrafoundation.Tcpclient.3
//
// Copyright 1999, 200, 2001, 2003, 2004, 2012 by Lewis A. Sellers (AKA Min)
// http://www.intrafoundation.com
// webmaster@intrafoundation.com
//
// Software Homepage: http://www.intrafoundation.com/tcpclient.asp
//
//
/////////////////////////////////////////////////////////////////////////////
// tcp.cpp: implementation of the tcp class.

/*

  Yes, you can use this class as a basis for your TCP/IP based apps.
  They can even be commercial applications. The only limitations are
  that you must include notice in your documentation you're using this
  source and include the full source of the winsock class with you app,
  whether you've modified it or not.
  If you have modified it and improved on it, email me.
	
Version History

v3.2 August 30th 2012
	V3.1 July 13th 2004
		
	v3.0 (v2.13) - April 2-28th 2004
	Almost a complete rewrite....
		
	v2.12 March 26-April 2 2004
	cleanup. Added static CLog and removed older logging code.
	Added some extra error handling, etc. Lots of tweaking all over the code.
		  
	v2.11 sept 13 2001. fixed recvp bug. added ping
	v2.10 feb 7th 2001. removed some leftover debugging code.
	v2.9 feb 3rd 2001
	v2.8 jan 30th 2001. added blocksize code to handle large files
	v2.7 jan 23-27th 2001 added RecvCRLF and debugged most everything else.
	v2.6 Jan 2001 changed class names. there are now the classes: tcp, udp and icmp
	v2.5
	v2.4 Dec 20 2000 added cutoff
	v2.3 Dec 19 2000 (begin to add a few SSL hooks for future expansion)
	v2.2 Dec 17 2000
	v2.1 Dec 15 2000
	v2.0 Nov-Dec 2000
			
*/

///////////////////////////////////////////////////////////////////////////
// libs:  ws2_32.lib mpr.lib netapi32.lib
//
#include "stdafx.h"

//
#include "sys/stat.h"					//_stat
#include <time.h>						//ctime

//
#include "Log.h"
#include "ErrorStringWSA.h"

//
#include "tcp.h"

///////////////////////////////////////////////////////////////////////////
//
//

//
int tcp:: m_last_instance=0;

const int tcp::NAGLE_DELAY=20;	//milliseconds
const char * tcp::crlfA="\r\n\0";
const wchar_t * tcp::crlfW=L"\r\n\0";
const int tcp::crlfA_LENGTH=2;
const int tcp::crlfW_LENGTH=4;


///////////////////////////////////////////////////////////////////////////
//
//

/*
*/
tcp::tcp(void)
{
	reset();
	load_winsock();
	
#ifdef _DEBUG
	printf("\n\n\n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("tcp::tcp creating instance (instance %d)\n\n",m_instance);
#endif
}

/*
*/
tcp::tcp(char *const host, char *const port)
{
	//
	reset();
	load_winsock();
	
#ifdef _DEBUG
	printf("\n\n\n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("tcp::tcp creating instance HOST=%s : PORT=%s (instance %d)\n\n",host,port,m_instance);
#endif
	
	//
	open(host,port);
}

/*
SSL/TLS. Not implemented.
*/
tcp::tcp(char *const host, char *const port, char *const ciphers)
{
	//
	reset();
	load_winsock();
	
#ifdef _DEBUG
	printf("\n\n\n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("tcp::tcp (SSL/TLS) opening secure tcp connection HOST=%s : PORT=%s / CIPHERS=%s (instance %d)\n\n",
		host,
		port,
		ciphers,
		m_instance);
#endif
	
	//
	open(host,port);
}

/*
*/
tcp::~tcp(void)
{
#ifdef _DEBUG
	printf("tcp::~tcp deleting instance. sock=%d (instance %d)\n\n",m_sock,m_instance);
	printf("---------------------------------------------------------------\n");
#endif
	close();
	unload_winsock();
}

///////////////////////////////////////////////////////////////////////////
//
//

/*
*/
void tcp::reset(void)
{
	//
	m_instance=++m_last_instance;
	
#ifdef _DEBUG
	printf("tcp::reset\n\n");
#endif
	
	//
	log.Clear();
	
	// init socket id to null socket
	m_sock=0;
	
	//
	m_connected=false;
	
	//
	m_ping.QuadPart=0;
	m_start_of_ping.QuadPart=0;
	
	//
	m_send_sleep=0;
	m_recv_sleep=0;
	
	// default timeout values for winsock instance
	m_secs=0L;
	m_msecs=500L;
	
	// disable cutoff
	m_cutoff_bytes=0L;
	
	//init SSL properties to false
	m_securesocket=false;
	
	// init sent/received byte count
	m_bytes_sent=0L;
	m_bytes_received=0L;
	m_last_bytes_sent=0L;
	m_last_bytes_received=0L;
	
	m_time_sending.QuadPart=0;
	m_time_receiving.QuadPart=0;
	m_last_time_sending.QuadPart=0;
	m_last_time_receiving.QuadPart=0;
	
	// init timedout
	m_last_timeout=0.0;
	
	//
	m_is_cutoff=false;
	
	//
	m_send_packets=0;
	m_recv_packets=0;
	m_recvbuffer_faults=0;
	m_recv_faults=0;
	
	//have we completed "normally"? not yet.
	m_completed=false;
	
	//
	m_recvbuffer=NULL;
	m_recvbuffer_length=0;
	
	//
	m_stack_buffer=NULL;
	packetsize(65535);	// set default packet size
	blocksize(65535);
	
	//
	m_buffer_length=0;
}

/*
*/
void tcp::load_winsock(void)
{
#ifdef _DEBUG
	printf("tcp::load_winsock\n\n");
#endif
	
	//verify the winsock version is at least version 2.0
	WORD wVersionRequested=MAKEWORD(2,0);
	WSADATA wsaData;
	int err=WSAStartup(wVersionRequested,&wsaData);
	if(err != 0)
	{
		// abort if less than 2.0
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"tcp::load_winsock",
			L"Current winsock is version %d.%d, but require at least 2.0. WSAStartup failure, (%d) (%s).",
			LOBYTE(wsaData.wVersion),
			HIBYTE(wsaData.wVersion),
			err,
			CErrorStringWSA::ErrorString(err));
		
		m_connected=false;
		return;
	}
	
#ifdef _DEBUG
	printf("Current winsock version %d.%d\n",LOBYTE(wsaData.wVersion),HIBYTE(wsaData.wVersion));
#endif
	if(LOBYTE(wsaData.wVersion) < 2 && HIBYTE(wsaData.wVersion) < 0)
	{
		// contine but warn if greater than 2.0
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"tcp::load_winsock",
			L"Warning: Current winsock is version %d.%d, but class designed for 2.0.",
			LOBYTE(wsaData.wVersion),
			HIBYTE(wsaData.wVersion));
	}
}

/*
*/
void tcp::unload_winsock(void)
{
#ifdef _DEBUG
	printf("tcp::unload_winsock\n\n");
#endif
	
	int const err=WSACleanup();
	if(err==SOCKET_ERROR)
		log.AddLog(
		_T(__FILE__),
		__LINE__,
		L"tcp::unload_winsock",
		L"WSACleanup can not close winsock: (%d) (%s)",
		err,
		CErrorStringWSA::ErrorString(err));
}

/*
*/
void tcp::open(
			   char *const host,
			   char *const port
			   )
{
#ifdef _DEBUG
	printf("tcp::open opening tcp connection HOST=%s : PORT=%s\n\n",host,port);
#endif
	
	// (instance reuse: as of v3 the class supports a limited ability to
	// reuse the settings within it.)
	// are we already connected using this instance?
	if(m_connected)
	{
		//if so then we force the previous connection to be closed.
		close();
		reset();
	}
	
	//////////////////////////////////////////////////////////////
	//
	struct sockaddr_in sa;
	struct hostent* hp;
	struct servent* sp;
	
	//preparations follow that set up socket structures
	if((hp=gethostbyname(host)) == NULL)
	{
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"tcp::tcp",
			L"No such host? (%S).",
			host);
		m_connected=false;
		return;
	}
	
	// copy needed info out of hp before issuing any other winsock functions
	memmove((char*) &sa.sin_addr,(char*)hp->h_addr,hp->h_length);
	sa.sin_family=hp->h_addrtype;
	
	//
	sa.sin_port= (short)ntohs(atoi(port));
	if(sa.sin_port == 0)
	{
		if((sp=getservbyname(port,"tcp")) == NULL)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"tcp::tcp",
				L"No service (%s) on this host.",
				port);
			m_connected=false;
			return;
		}
		else
			sa.sin_port=sp->s_port;
	}
	
	//
	if((m_sock=::socket(hp->h_addrtype,SOCK_STREAM,0)) < 0)
	{
		//
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"tcp::tcp",
			L"Socket error while requesting a free TCP/SOCK_STREAM socket handle (%d) (%s)",
			WSAGetLastError(),
			CErrorStringWSA::ErrorString(WSAGetLastError()));
		m_connected=false;
		return;
	}
	
	//connect to the server. or try to...
	if(connect(m_sock,(const struct sockaddr*) &sa,sizeof(sa)) != 0)
	{
		//oops. winsock connect error. bloody windows.
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"tcp::tcp",
			L"Connect error: socket=%d host=%S port=%S (%d) (%s)",
			m_sock,
			host,
			port,
			WSAGetLastError(),
			CErrorStringWSA::ErrorString(WSAGetLastError()));
		m_connected=false;
		return;
	}
	
	//let us see non-blocking async mode please (and a bloody new keyboard for Yahshua-mass while we're at it. ug.)
	unsigned long argp1=1;
	if(ioctlsocket(m_sock,FIONBIO,&argp1) == SOCKET_ERROR)
	{
		//oops. winsock connect error. bloody windows.
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"tcp::tcp",
			L"Async/Non-blocking mode could not be enabled (%d) (%s)",
			WSAGetLastError(),
			CErrorStringWSA::ErrorString(WSAGetLastError()));
		m_connected=false;
		return;
	}
	
	//are we connected? yep. we are now.
	m_connected=true;
	
#ifdef _DEBUG
	printf("tcp::tcp connected. sock=%d\n\n",m_sock);
#endif
	
	// initialize frequency constant
	if(!QueryPerformanceFrequency(&m_frequency))
	{
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"tcp::tcp",
			L"QueryPerformanceFrequency failed. Timing functions will be inaccurate.");
	}
#ifdef _DEBUG
	printf("tcp::open SUCCESS.\n");
#endif
}

///////////////////////////////////////////////////////////////////////////
//
//

/*
*/
void tcp::close(void)
{
	if(m_sock != 0)
	{
#ifdef _DEBUG
		printf("tcp::close closing tcp connection. sock=%d (instance %d)\n\n",m_sock,m_instance);
		printf("---------------------------------------------------------------\n");
#endif
		
		//statistics
#if _DEBUG
		printf("###############################################################\n");
		printf("last bytes sent            \t %ld\n",last_bytes_sent());
		printf("     bytes sent            \t %ld\n",bytes_sent());
		
		printf("last bytes received        \t %ld\n",last_bytes_received());
		printf("     bytes received        \t %ld\n",bytes_received());
		
		printf("last milliseconds sending  \t %lf\n",last_milliseconds_sending());
		printf("     milliseconds sending  \t %lf\n",milliseconds_sending());
		
		printf("last milliseconds receiving\t %lf\n",last_milliseconds_receiving());
		printf("     milliseconds receiving\t %lf\n",milliseconds_receiving());
		
		printf("last time sending          \t %ld\n",m_last_time_sending.QuadPart);
		printf("     time sending          \t %ld\n",m_time_sending.QuadPart);
		
		printf("last time receiving        \t %ld\n",m_last_time_receiving.QuadPart);
		printf("     time receiving        \t %ld\n",m_time_receiving.QuadPart);
		
		printf("last kbps sent             \t %lf\n",last_kbps_sent());
		printf("     kbps sent             \t %lf\n",kbps_sent());
		
		printf("last kbps recv             \t %lf\n",last_kbps_received());
		printf("     kbps recv             \t %lf\n",kbps_received());
		
		printf("ping                       \t %ld ms\n",ping());
		
		printf("send sleep                 \t %ld ms\n",send_sleep());
		printf("recv sleep                 \t %ld ms\n",recv_sleep());
		
		printf("send packets               \t %d\n",m_send_packets);
		printf("recv packets               \t %d\n",m_recv_packets);
		printf("recvbuffer faults          \t %d\n",m_recvbuffer_faults);
		printf("recv faults                \t %d\n",m_recv_faults);
		
		if(m_last_timeout > 0.0)
		{
			printf("**TIMEDOUT**             \t %lf\n",m_last_timeout);
		}
		
		printf("log:\n%S\n",log.Logs());
		
		printf("###############################################################\n");
		
		printf("\n\n\n");
#endif
		
		//
		if(closesocket(m_sock) == SOCKET_ERROR)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"tcp::close",
				L"Error encountered while closing socket (%d) (%s)",
				WSAGetLastError(),
				CErrorStringWSA::ErrorString(WSAGetLastError()));
			
#if _DEBUG
			printf("tcp::close Error encountered while closing socket (%d) (%s)\n\n",
				WSAGetLastError(),
				CErrorStringWSA::ErrorString(WSAGetLastError()));
#endif
			return;
		}
		
		//
		m_connected=false;
		m_securesocket=false;
		m_sock=0;
		
		//
		delete[] m_stack_buffer;
		m_stack_buffer=NULL;
	}
}

///////////////////////////////////////////////////////////////////////////
//
//

/*
Sends out data buffer out through the current socket... :)
*/
int tcp::Send(char* const sp, long const length)
{
	// get current high resolution time...
	LARGE_INTEGER tmp1;
	QueryPerformanceCounter(&tmp1);
	
	// init
	m_last_bytes_sent=0L;
	
	//
	if(m_connected)
	{
		//
		int writesocks=0;
		
		// setup timeout intervals
		struct timeval tv;
		tv.tv_sec= (long)m_secs;
		
		fd_set writefds;
		tv.tv_usec= (long)m_msecs;
		
		//
		long bytes_remaining=length;
		char* s=sp;
		
		//
		int bytes=0;
		
		// keep trying to send as long as there's data left in the outgoing buffer
		// (unless an error condition in the loop breaks out)
		while(bytes_remaining > 0)
		{
			// can we send? first time into the loop we generally can
			while
				(
				(writesocks == 0)
				||	(writesocks == SOCKET_ERROR && WSAGetLastError() == WSAEWOULDBLOCK)
				)
			{
				// yes...
				// see if we can send data through the socket
				FD_ZERO(&writefds);
				FD_SET(m_sock,&writefds);
				
				writesocks=select(FD_SETSIZE,NULL,&writefds,NULL,&tv);
				
#if _DEBUG
				printf("tcp::Send  writesocks=%d\n",writesocks);
#endif
				
				// send problem?
				if(writesocks == SOCKET_ERROR)
				{
					log.AddLog(
						_T(__FILE__),
						__LINE__,
						L"tcp::Send",
						L"SELECT for write failed with a %d. (%d) (%s)",
						writesocks,
						WSAGetLastError(),
						CErrorStringWSA::ErrorString(WSAGetLastError()));
					break;
				}
			}
			
			// is everything ok?
			if((writesocks == SOCKET_ERROR) && (WSAGetLastError() != WSAEWOULDBLOCK))
				// abort the entire thing if there's a problem....
				break;
			else
			{
				// try to send the most data we can...
				bytes=min(m_packetsize,bytes_remaining);
				m_last_bytes_sent=send(m_sock,s,bytes,0);
				
#if _DEBUG
				printf("tcp::Send  bytes=%d m_last_bytes_sent=%d\n",bytes,m_last_bytes_sent);
#endif
				
				// stat
				m_send_packets++;
				
				// did we send anything?
				if((m_last_bytes_sent == SOCKET_ERROR) && (WSAGetLastError() == WSAEWOULDBLOCK))
				{
					// if we can't send because the buffer is full and we're still waiting
					// for it to be send by the tcp/ip stack, go to sleep 20 milliseconds
					// then try again.
					Sleep(NAGLE_DELAY); //wait for ms equal to nagle's alg
					m_send_sleep+=NAGLE_DELAY;
#if _DEBUG
					printf("+");
#endif
				}
				else if((m_last_bytes_sent == SOCKET_ERROR)
					&&	(WSAGetLastError() != WSAEWOULDBLOCK))
				{
					// hard send error
					log.AddLog(
						_T(__FILE__),
						__LINE__,
						L"tcp::Send",
						L"SEND failed. (bytes sent %ld, bytes remaining %ld, address %p). (%d) (%s)",
						m_bytes_sent,
						bytes_remaining,
						s,
						WSAGetLastError(),
						CErrorStringWSA::ErrorString(WSAGetLastError()));
#if _DEBUG
					printf("tcp::Send  err=%d (%s)\n",
						WSAGetLastError(),
						CErrorStringWSA::ErrorString(WSAGetLastError()));
#endif
					break;
				}
				else
				{
					// the data was successfully sent (at least on our end)
					// so update some stats... and the pointer into the data
					long const tmp= (long)abs(m_last_bytes_sent);
					m_bytes_sent+=tmp;
					bytes_remaining-=tmp;
					s+=tmp; 			//update pointer into data. when data being sent is larger then
					//outgoing buffer we have to send in blocks
				}
			}
		}
	}
	
	// do timing updates for statistics functions
	LARGE_INTEGER tmp2;
	QueryPerformanceCounter(&tmp2);
	
	m_last_time_sending.QuadPart=tmp2.QuadPart - tmp1.QuadPart;
	m_time_sending.QuadPart+=m_last_time_sending.QuadPart;
	
	// init our pseudo "ping" timer
	// (not an actual ICMP one, but close enough for our purposes)
	m_start_of_ping.QuadPart=tmp2.QuadPart;
	
#if _DEBUG
	printf("###############################################################\n");
	printf(" last_kbps_sent            \t %lf\n",last_kbps_sent());
	printf(" kbps_sent                 \t %lf\n",kbps_sent());
	
	printf(" last_milliseconds_sending \t %lf\n",last_milliseconds_sending());
	printf(" milliseconds_sending      \t %lf\n",milliseconds_sending());
	
	printf(" last_bytes_sent           \t %ld\n",m_last_bytes_sent);
	printf(" bytes_sent                \t %ld\n",m_bytes_sent);
	
	printf("###############################################################\n\n");
#endif
	
	// return the total of how many bytes we sent this function call
	return m_last_bytes_sent;
}

///////////////////////////////////////////////////////////////////////////
//
//

/*
*/
int tcp::SendCRLF(char* const sp)
{
	if(sp == NULL)
		return 0;
	else
		return SendCRLF(sp,strlen(sp));
}

/*
*/
int tcp::SendF(char const* format, ...)
{
	//
	char str[4096 + 1];
	va_list argptr;
	va_start(argptr,format);
	_vsnprintf(str,4096,format,argptr);
	va_end(argptr);
	
	//
	int const szlen=strlen(str);
	Send(str,szlen);
	
#ifdef _DEBUG
	printf("\ntcp::SendF %s\n",str);
#endif

	return szlen;
}

/*
This is a funtion of "convenience". Useful when sending single line commands that
we want more debugging output routed through.
There's less overhead to just send commands through Send with the \r\n's already tacked on.
*/
int tcp::SendCRLF(char* const sp, long const length)
{
#ifdef _DEBUG
	printf("<%5d <<< %s\n",length,sp);
#endif

	if(sp == NULL)
		return Send((char*const)crlfA,crlfA_LENGTH);
	else
	{
		//
		int const tmplength=length + crlfA_LENGTH;
		char* tmp=new char[tmplength + 1];
		if(tmp)
		{
			//
			memcpy(tmp,sp,length);
			memcpy(tmp + length,crlfA,crlfA_LENGTH);
			return Send(tmp,tmplength);
			
			delete[] tmp;
			tmp=NULL;
		}
		else
		{
			//
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"tcp::SendCRLF",
				L"Memory allocation failure: %d bytes.",
				tmplength + 1);
			return 0;
		}
	}
}

//////////////////////////////////////////////////////////////////////////
//
//

/*
*/
int tcp::Recv(char *& recvp)
{
	return Recv(recvp,false,false);
}

/*
Receives data from the current socket.
Will return as much data as is available unless cutoff points, etc are engaged.

  Note that it stored the incoming data in memory itself so transfers of multi-MB
  data may need to have cutoffs enabled to make the function less memory intense.
*/
int tcp::Recv(char* &recvp, bool bbreakonpause, bool ignorebuffer)
{
	// inits
	m_last_bytes_received=0;
	m_last_timeout=0.0;
	m_is_cutoff=false;

	//
	if(m_stack_buffer == NULL)
	{
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"tcp::Recv",
			L"Memory allocation for stack buffer has previously failed when setting packetsize. FATAL ERROR.");
		return 0;
	}
	
	// does the recvbuffer have any left over data from RecvCRLF or RecvFrame?
	if(ignorebuffer == false && m_recvbuffer != NULL)
	{
		//if so, then just Recv everything in that buffer first so as to "clear" it.
		int const length=m_recvbuffer_length;
		
		recvp=m_recvbuffer;
		
		m_recvbuffer=NULL;
		m_recvbuffer_length=0;
		return length;
	}
	
	// Ok. assuming there's no leftover buffer data from the other buffered function, we can start...
	// get current high resolution time...
	LARGE_INTEGER tmp1;
	QueryPerformanceCounter(&tmp1);
	
	// ? inits
	
	//
	if(m_connected)
	{
		// setup accumulation buffer
		delete[] recvp;
		recvp=new char[m_blocksize];
		m_buffer_length=m_blocksize;
		*recvp='\0';
		
		//
		struct timeval tv;
		tv.tv_sec= (long)m_secs;
		tv.tv_usec= (long)m_msecs;
		
		fd_set readfds;
		
		int readsocks=0;
		
		int bytes=0;
		
		//
		do
		{
			// see if we can read data from the socket...
			FD_ZERO(&readfds);
			FD_SET(m_sock,&readfds);
			
			readsocks=select(FD_SETSIZE,&readfds,NULL,NULL,&tv);
			
#if _DEBUG
			printf("tcp::Recv readsocks=%d\n",readsocks);
#endif
			
			//
			if(readsocks == SOCKET_ERROR)
			{
				if(WSAGetLastError() != WSAEWOULDBLOCK)
				{
					log.AddLog(
						_T(__FILE__),
						__LINE__,
						L"tcp::Recv",
						L"SELECT read error %d. (%d) (%s)",
						readsocks,
						WSAGetLastError(),
						CErrorStringWSA::ErrorString(WSAGetLastError()));
				}
			}
			else if(readsocks == 0)
			{
				//
				m_last_timeout= (double)tv.tv_sec + ((double)tv.tv_usec) * .001;
				
				//
				log.AddLog(
					_T(__FILE__),
					__LINE__,
					L"tcp::Recv",
					L"RECV Error - no response for %lds %lums.",
					tv.tv_sec,
					tv.tv_usec);
				break;
			}
			else
			{
				// compute "ping". For our purposes we mark the time between starting a send and
				// receiving back anything. not accurate in many cases but close enough.
				if(m_start_of_ping.QuadPart > 0)
				{
					LARGE_INTEGER tmp0;
					QueryPerformanceCounter(&tmp0);
					m_ping.QuadPart=tmp0.QuadPart - m_start_of_ping.QuadPart;
				}
				
				// ////////////////////////////////////////////////////////////
				// buf is out stack buffer that recieves data up to the max packet size.
				//{
				do
				{
					bytes=recv(m_sock,m_stack_buffer,m_packetsize,0);	//if 0 then EOF
#if _DEBUG
					printf("tcp::Recv  bytes=%d\n",bytes);
#endif
					m_recv_packets++;					//update counter of how many times we've done a network recv
					if(bytes == SOCKET_ERROR)			//do we have a problem?
					{
						// yes... a serious one.
						if(WSAGetLastError() != WSAEWOULDBLOCK)
						{
							log.AddLog(
								_T(__FILE__),
								__LINE__,
								L"tcp::Recv",
								L"RECV socket error (%d) (%s)",
								WSAGetLastError(),
								CErrorStringWSA::ErrorString(WSAGetLastError()));
#if _DEBUG
							printf("tcp::Recv  err=%d (%s)\n",
								WSAGetLastError(),
								CErrorStringWSA::ErrorString(WSAGetLastError()));
#endif
							break;
						}
						else
						{								//no, just a pause in stream...
							if(bbreakonpause) break;	//don't wait if there's a pause. return immediately.
							else
							{	// go to sleep for a bit and check the stream again later...
								Sleep(NAGLE_DELAY);
								m_recv_sleep+=NAGLE_DELAY;
#if _DEBUG
								printf("-");
#endif
							}
						}
					}
					else if(bytes == 0)
					{
						// if bytes is 0 then there is no more data to be received
						// (for the moment) so we're done.
						m_completed=true;
						break;
					}
					else if(bytes > 0)
					{
						// there's data waiting to be received so grab it...
						// do we still have enough room in our main buffer to hold the adition of the new recv data?
						if(m_last_bytes_received + bytes < m_buffer_length)
						{
							//if not...
							// A. the dat we've just received will fit in the preallocated accumulation buffer
							// so we go ahead and append it.
							memcpy((recvp + m_last_bytes_received),m_stack_buffer,bytes);
							
							// update out count of how many bytes we've received
							m_last_bytes_received+=bytes;
						}
						else
						{
							// B. is the data we're receiving now more than the buffer we allocated to hold it?
							m_recv_faults++;
							
#if _DEBUG
							printf("tcp::Recv  m_recv_faults %d m_last_bytes_received=%d\n",
								m_recv_faults,
								m_last_bytes_received);
#endif
							
							// we need to append the new data we're received to our accumlation buffer...
							// but as it's too small and c++ new/delete doesn't have a function similiar
							// to remalloc ... we have to do a slow restructuring of the buffer with
							// several new/delete operations.
							// create a temporary buffer
							m_buffer_length+=bytes + (m_blocksize - (bytes % m_blocksize));
#if _DEBUG
							printf(" buffer resized: %d bytes to %d\n",
								bytes + (m_blocksize - (bytes % m_blocksize)),
								m_buffer_length);
#endif
							
							char* tmp=new char[m_buffer_length + 1];					// plus NULL padding
							if(tmp)
							{
								//and copy the accumulated buffer and the buffer we just received to it...
								memcpy(tmp,recvp,m_last_bytes_received);
								memcpy((tmp + m_last_bytes_received),m_stack_buffer,bytes);
								
								// and delete the old accumulation buffer (ie, swap buffers)
								delete[] recvp;
								
								// now change the pointer of the accumulation buffer to the new temp one...
								recvp=tmp;
								
								// update out count of how many bytes we've received
								m_last_bytes_received+=bytes;
							}
							else
							{
								log.AddLog(
								_T(__FILE__),
								__LINE__,
								L"tcp::Recv",
								L"Memory allocation failure: %d bytes.",
								m_buffer_length);
							}
						}
					}
					
					//cutoff (inner loop - while streaming data)
					// we use this to force an artificial break in the receiving
					// of very large amounts of data
					if(m_cutoff_bytes && (m_last_bytes_received > m_cutoff_bytes))
					{
						m_is_cutoff=true;
						break;
					}
					
					// keep grabbing data as long as there's data to be had....
				} while(bytes > 0); //|| //EOF 
				
				//}
				// if the stream has stopped sending and we've recieved at least a little data
				// then assume it's an open communications stream that's sent all it's going
				// to send for now unless we send it more commands.
				// stop trying to receive.
				if(bbreakonpause && (m_last_bytes_received > 0)) break;
			}
			
			// ////////////////////////////////////////////////////////////
			//cutoff (outer loop -- when data pauses)
			if(m_cutoff_bytes && m_last_bytes_received > m_cutoff_bytes)
			{
				m_is_cutoff=true;
				break;
			}
		} while
			(	//keep going unless we run into a soft or hard error...
			(readsocks == 0) ||
			((readsocks == SOCKET_ERROR) && (WSAGetLastError() == WSAEWOULDBLOCK)) || //waiting on (slow) network
			((bytes == SOCKET_ERROR) && (WSAGetLastError() == WSAEWOULDBLOCK)) //waiting on (slow) network
			);
		
		// we're done for now, so...
		*(recvp + m_last_bytes_received)='\0';	//(just in case someone tries a sz string function on it)
		
		// update total bytes received
		m_bytes_received+=m_last_bytes_received;
	}
	
	// do timing updates for statistics functions
	LARGE_INTEGER tmp2;
	QueryPerformanceCounter(&tmp2);
	
	m_last_time_receiving.QuadPart=tmp2.QuadPart - tmp1.QuadPart;
	m_time_receiving.QuadPart+=m_last_time_receiving.QuadPart;
	
#if _DEBUG
	printf("###############################################################\n");
	printf(" kbps_last_received         \t %lf\n",last_kbps_received());
	printf(" kbps_received              \t %lf\n",kbps_received());
	
	printf(" last_milliseconds_receiving\t %lf\n",last_milliseconds_receiving());
	printf(" milliseconds_receiving     \t %lf\n",milliseconds_receiving());
	
	printf(" bytes_received             \t %ld\n",m_bytes_received);
	
	printf(" m_ping                     \t %ld\n",m_ping.QuadPart);
	printf("###############################################################\n\n");
#endif
	
	//
	return m_last_bytes_received;
}

///////////////////////////////////////////////////////////////////////////
//
//

/*
RecvCRLF is a special implimentation of Recv that returns only one \r\n terminated
line per call. It is used when talking to command-line driven text protocols
such as HTTP, FTP, FINGER, etc.
*/
int tcp::RecvCRLF(char *& recvp)
{
	//
	int bytesreturned=0;
	
	// this paragraph exists solely to overcome a post.office 3.5.3 bug that
	// emits a NULL after the CRLF at a mime boundry.
	if(m_recvbuffer != NULL && m_recvbuffer_length >= 1 && *m_recvbuffer == '\0')
	{
		char* tmp=new char[m_recvbuffer_length + 1];
		if(tmp)
		{
			memcpy(tmp,m_recvbuffer + 1,m_recvbuffer_length - 1);
			delete[] m_recvbuffer;

			m_recvbuffer=tmp;
			
			m_recvbuffer_length--;
		}
	}
	
	//
	char* pcrlf;				//pointer to next crlf in the buffer
	
	// check if anything still in cache first
	// A.
	if(
		(m_recvbuffer == NULL) ||
		((m_recvbuffer != NULL) && ((pcrlf=strstr(m_recvbuffer,crlfA)) == NULL))
		)
	{
		// No, there is not another crlf-terminated line in our memory buffer,
		// so we have to try to recveive more data and append that to the unused
		// portion of our buffer.
		m_recvbuffer_faults++;	//we had to call across the network for more data
		
		// call our recv function to get any data in the tcp/ip stacker buffer
		char* r=NULL;
		const int r_length=Recv(r,true,true);		//get data from stream, returning immediately at any pause
		
		// now append that new data to our current crlfbuffer
		const int length=m_recvbuffer_length + r_length;
		char* tmp=new char[length + 1];
		if(tmp)
		{
			memcpy(tmp,m_recvbuffer,m_recvbuffer_length);
			memcpy((tmp + m_recvbuffer_length),r,r_length);
			*(tmp + length)='\0';
			
			delete[] m_recvbuffer;					//delete current crlf buffer
			m_recvbuffer=tmp;						//and make crlfbuffer point to new accumulated buffer
			m_recvbuffer_length=length; 			//update crlf buffer length
		}
		else
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"tcp::RecvCRLF",
				L"Memory allocation failure: %d bytes.",
				length + 1);
		}
	}
	
	// B.
	// There is already a crlf-terminated line in the buffer, so just return that.
	if((m_recvbuffer != NULL) && ((pcrlf=strstr(m_recvbuffer,crlfA)) != NULL))
	{
		//
		const int length=(pcrlf - m_recvbuffer);
		recvp=new char[length + crlfA_LENGTH];
		if(recvp)
		{
			// copy the line from the crlf accumulation buffer to
			// the function output buffer.
			*(m_recvbuffer + length)=NULL;			//(after adding a saftey NULL though)
			memcpy(recvp,m_recvbuffer,length + 1);
			
			//now that we've returned a line we must remove this used data
			//from the buffer...
			// new length of buffer minus returned line
			const int newlength=m_recvbuffer_length - (length + crlfA_LENGTH);
			char* tmp=new char[newlength + 1 + 1]; //plus NULL plus safety
			if(tmp)
			{
				memcpy(tmp,pcrlf + crlfA_LENGTH,newlength + 1);
				delete[] m_recvbuffer;
				
				m_recvbuffer=tmp;
			}
			else
				log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"tcp::RecvCRLF",
				L"Memory allocation failure: %d bytes.",
				newlength + 1 + 1);
			
			m_recvbuffer_length=newlength;
		}
		
		bytesreturned=length;
	}
	
#ifdef _DEBUG
	printf("> %5d>>> %s\n",m_last_bytes_received,recvp);
#endif
	
	//
	return bytesreturned;
}

/*
Flushes the recvcrlf buffer.
*/
bool tcp::EmptyRecvBuffer(void)
{
	if(m_recvbuffer)
	{
		delete[] m_recvbuffer;
		m_recvbuffer=NULL;
		m_recvbuffer_length=0;
		return true;
	}
	else
		return false;
}

/*
*/
int tcp::RecvFrame(
				   char* &recvp,
				   long const length
				   )
{
	//
	int bytesreturned=0;
	
	// check if anything still in cache first
	// A.
	if((m_recvbuffer == NULL) || ((m_recvbuffer != NULL) && (m_recvbuffer_length < length)))
	{
		// No, there is not another full frame in our memory buffer,
		// so we have to try to recveive more data and append that to the unused
		// portion of our buffer.
		m_recvbuffer_faults++;						//we had to call across the network for more data
		
		// call our recv function to get any data in the tcp/ip stacker buffer
		char* r=NULL;
		const int r_length=Recv(r,true,true);		//get data from stream, returning immediately at any pause
		
		// now append that new data to our current recvbuffer
		const int length=m_recvbuffer_length + r_length;
		char* tmp=new char[length + 1];
		if(tmp)
		{
			memcpy(tmp,m_recvbuffer,m_recvbuffer_length);
			memcpy((tmp + m_recvbuffer_length),r,r_length);
			*(tmp + length)='\0';
			
			delete[] m_recvbuffer;					//delete current buffer
			m_recvbuffer=tmp;						//and make crlfbuffer point to new accumulated buffer
			m_recvbuffer_length=length; 			//update buffer length
		}
		else
		{
			log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"tcp::RecvFrame",
			L"Memory allocation failure: %d bytes.",
			length + 1);
		}
	}
	
	// B.
	// There is already a full frame in the buffer, so just return that.
	if((m_recvbuffer != NULL) && (m_recvbuffer_length >= length))
	{
		recvp=new char[length + 1];
		if(recvp)
		{
			// copy the frame from the accumulation buffer to
			// the function output buffer.
			*(m_recvbuffer + length)=NULL;			//(after adding a saftey NULL though)
			memcpy(recvp,m_recvbuffer,length + 1);
			
			//now that we've returned a frame we must remove this used data
			//from the buffer...
			// new length of buffer minus returned frame
			const int newlength=m_recvbuffer_length - length;
			char* tmp=new char[newlength + 1 + 1]; //plus NULL plus safety
			if(tmp)
			{
				memcpy(tmp,m_recvbuffer + length,newlength + 1);
				delete[] m_recvbuffer;
				
				m_recvbuffer=tmp;
			}
			else
			{
				log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"tcp::RecvFrame",
				L"Memory allocation failure: %d bytes.",
				newlength + 1 + 1);
			}
			
			m_recvbuffer_length=newlength;
		}
		
		bytesreturned=length;
	}
	
#ifdef _DEBUG
	printf("> %5d>>> %s\n",m_last_bytes_received,recvp);
#endif
	
	//
	return bytesreturned;
}

///////////////////////////////////////////////////////////////////////////
//
//

/*
*/
void tcp::localName(char* ip, int &port)
{
	//
	struct sockaddr_in sa;
	int salen=sizeof(sa);
	int gpn;
	if((gpn=getsockname(m_sock,(struct sockaddr*) &sa,&salen)) != 0)
		log.AddLog(
		_T(__FILE__),
		__LINE__,
		L"tcp::localName",
		L"Connect error: socket=%d.",
		m_sock);
	else
	{
		sprintf(ip,
			"%d.%d.%d.%d",
			sa.sin_addr.S_un.S_un_b.s_b1,
			sa.sin_addr.S_un.S_un_b.s_b2,
			sa.sin_addr.S_un.S_un_b.s_b3,
			sa.sin_addr.S_un.S_un_b.s_b4);
		port=ntohs(sa.sin_port);
	}
}

///////////////////////////////////////////////////////////////////////////
//
//

/*
*/
void tcp::peerName(char* ip, int &port)
{
	//
	struct sockaddr_in psa;
	int psalen=sizeof(psa);
	int gpn;
	if((gpn=getpeername(m_sock,(struct sockaddr*) &psa,&psalen)) != 0)
	{
		log.AddLog(
		_T(__FILE__),
		__LINE__,
		L"tcp::peerName",
		L"Peer error: socket=%d.",
		m_sock);
	}
	else
	{
		sprintf(ip,
			"%d.%d.%d.%d",
			psa.sin_addr.S_un.S_un_b.s_b1,
			psa.sin_addr.S_un.S_un_b.s_b2,
			psa.sin_addr.S_un.S_un_b.s_b3,
			psa.sin_addr.S_un.S_un_b.s_b4);
		port=ntohs(psa.sin_port);
	}
}

///////////////////////////////////////////////////////////////////////////
//
//

/*
*/
bool tcp::is_connected(void)
{
	return m_connected;
}

/*
*/
bool tcp::is_completed(void)
{
	return m_completed;
}

///////////////////////////////////////////////////////////////////////////
//
//

/*
*/
int tcp::stack_recv_buffer(void)
{
	int len=sizeof(int);
	int i=0;
	if(getsockopt(m_sock,SOL_SOCKET,SO_RCVBUF,(char*)i,&len) == 0)
		return 0;
	else
		return i;
}

/*
*/
int tcp::stack_send_buffer(void)
{
	int len=sizeof(int);
	int i=0;
	if(getsockopt(m_sock,SOL_SOCKET,SO_SNDBUF,(char*)i,&len) == 0)
		return 0;
	else
		return i;
}

///////////////////////////////////////////////////////////////////////////
//
//

/*
*/
int tcp::send_packets(void)
{
	return m_send_packets;
}

/*
*/
int tcp::recv_packets(void)
{
	return m_recv_packets;
}

/*
*/
int tcp::recvbuffer_faults(void)
{
	return m_recvbuffer_faults;
}

/*
*/
int tcp::recv_faults(void)
{
	return m_recv_faults;
}

///////////////////////////////////////////////////////////////////////////
//
//

/*
*/
double tcp::kbps_sent(void)
{
	if(m_time_sending.QuadPart && m_bytes_sent)
	{
		const double numerator= (double)m_bytes_sent / 1024.0;
		const double divisor=((double)m_time_sending.QuadPart / (double)m_frequency.QuadPart);
		return numerator / divisor;
	}
	else
		return 0.0;
}

/*
*/
double tcp::last_kbps_sent(void)
{
	if(m_last_time_sending.QuadPart && m_last_bytes_sent)
	{
		const double numerator= (double)m_last_bytes_sent / 1024.0;
		const double divisor=((double)m_last_time_sending.QuadPart / (double)m_frequency.QuadPart);
		return numerator / divisor;
	}
	else
		return 0.0;
}

/*
*/
double tcp::kbps_received(void)
{
	if(m_time_receiving.QuadPart && m_bytes_received)
	{
		const double numerator= (double)m_bytes_received / 1024.0;
		const double divisor=((double)m_time_receiving.QuadPart / (double)m_frequency.QuadPart);
		return numerator / divisor;
	}
	else
		return 0.0;
}

/*
*/
double tcp::last_kbps_received(void)
{
	if(m_last_time_receiving.QuadPart && m_last_bytes_received)
	{
		const double numerator= (double)m_last_bytes_received / 1024.0;
		const double divisor= (double)m_last_time_receiving.QuadPart /(double)m_frequency.QuadPart;
		return numerator / divisor;
	}
	else
		return 0.0;
}

/*
*/
long tcp::bytes_sent(void)
{
	return m_bytes_sent;
}

/*
*/
long tcp::bytes_received(void)
{
	return m_bytes_received;
}

/*
*/
long tcp::last_bytes_sent(void)
{
	return m_last_bytes_sent;
}

/*
*/
long tcp::last_bytes_received(void)
{
	return m_last_bytes_received;
}

/*
*/
double tcp::milliseconds_sending(void)
{
	return ((double)m_time_sending.QuadPart / (double)m_frequency.QuadPart) * 1000.0;
}

/*
*/
double tcp::milliseconds_receiving(void)
{
	return ((double)m_time_receiving.QuadPart / (double)m_frequency.QuadPart) * 1000.0;
}

/*
*/
double tcp::last_milliseconds_sending(void)
{
	return ((double)m_last_time_sending.QuadPart / (double)m_frequency.QuadPart) * 1000.0;
}

/*
*/
double tcp::last_milliseconds_receiving(void)
{
	return ((double)m_last_time_receiving.QuadPart / (double)m_frequency.QuadPart) * 1000.0;
}

/*
*/
DWORD tcp::ping(void)
{
	return (DWORD) (((double)m_ping.QuadPart / (double)m_frequency.QuadPart) * 1000.0);
}


///////////////////////////////////////////////////////////////////////////
//
//

/*
*/
int tcp::instance(void)
{
	return m_instance;
}

/*
*/
int tcp::instances(void)
{
	return m_last_instance;
}

/*
*/
int tcp::socket(void)
{
	return m_sock;
}

/*
*/
int tcp::recv_sleep(void)
{
	return m_recv_sleep;
}

/*
*/
int tcp::send_sleep(void)
{
	return m_send_sleep;
}

///////////////////////////////////////////////////////////////////////////
//
//

/*
*/
bool tcp::is_secure(void)
{
	return m_securesocket;
}

///////////////////////////////////////////////////////////////////////////
//
//

/*
*/
bool tcp::is_cutoff(void)
{
	return m_is_cutoff;
}

/*
*/
double tcp::last_timeout(void)
{
	return (double)m_last_timeout;
}

/*
*/
double tcp::timeout(void)
{
	return (double)(m_secs * 1000 + m_msecs);
}

/*
*/
void tcp::timeout(int const secs, int const msecs)
{
	// pass on timeout values to winsock instance
	this->m_secs=secs;
	this->m_msecs=msecs;
	
#ifdef _DEBUG
	printf("tcp::timeout setting timeout: secs=%d msecs=%d\n\n",secs,msecs);
#endif
}

/*
*/
void tcp::cutoff(long bytes)
{
	m_cutoff_bytes=bytes;
}

/*
*/
long tcp::cutoff(void)
{
	return m_cutoff_bytes;
}

/*
*/
void tcp::blocksize(long bytes)
{
	if(bytes <= BUFSIZ)
		m_blocksize=BUFSIZ;
	else
		m_blocksize=bytes;
	
#ifdef _DEBUG
	printf("tcp::blocksize blocksize=%ld\n\n",m_blocksize);
#endif
}

/*
*/
int tcp::blocksize(void)
{
	return m_blocksize;
}

/*
32768; //8192 //65536 //6144 //8192 //1536 //BUFSIZ
*/
void tcp::packetsize(int bytes)
{
	//
	if(bytes <= BUFSIZ)
		m_packetsize=BUFSIZ;
	else
		m_packetsize=bytes;
	
#ifdef _DEBUG
	printf("tcp::packetsize packetsize=%ld\n\n",m_packetsize);
#endif
	
	//
	delete[] m_stack_buffer;
	m_stack_buffer=new char[m_packetsize + 1];
	if(m_stack_buffer == NULL)
	{
		log.AddLog(
		_T(__FILE__),
		__LINE__,
		L"tcp::packetsize",
		L"Memory allocation failure for stack buffer. FATAL ERROR. %d bytes.",
		m_packetsize);
	}
}

/*
*/
int tcp::packetsize(void)
{
	return m_packetsize;
}

/*
*/
int tcp::SendFile(const char* filename)
{
#ifdef _DEBUG
	printf("\ntcp::SendFile filename=%s\n",filename);
	printf(" m_blocksize=%d m_cutoff_bytes=%d\n",m_blocksize,m_cutoff_bytes);
#endif
	
	//
	int file_bytes_sent=0;
	
	//
	struct _stat statbuf;
	const int result=_stat(filename,&statbuf);
	if(result == -1)
	{
		log.AddLog(
		_T(__FILE__),
		__LINE__,
		L"tcp::SendFile",
		L"_stat error on file (%S). Could not retrieve file statistics.",
		filename);
	}
	else
	{
#ifdef _DEBUG
		printf(" File size     : %ld\n",statbuf.st_size);
		printf(" Drive         : %c:\n",statbuf.st_dev + 'A');
		printf(" Time modified : %s",ctime(&statbuf.st_atime));
#endif
		
		FILE* h=fopen(filename,"rb");
		if(h == NULL)
		{
			log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"tcp::SendFile",
			L"File (%S) could not be opened for binary read.",
			filename);
		}
		else
		{
			int const filesize=(long)statbuf.st_size;
			
			char* buf=new char[m_blocksize + 1];
			if(buf)
			{
				int bytes_left=filesize;
				while(bytes_left > 0)
				{
#ifdef _DEBUG
					printf(" reading %d bytes from disk...\n\n",m_blocksize);
#endif
					
					int const bytes_read=fread(buf,1,m_blocksize,h);
					int const sent_bytes=Send(buf,bytes_read);
#ifdef _DEBUG
					printf(" read=%d sent=%d\n",bytes_read,sent_bytes);
					printf(" %d of %d bytes remaining.\n",bytes_left,filesize);
#endif
					
					//
					if(sent_bytes != bytes_read)
					{
						log.AddLog(
							_T(__FILE__),
							__LINE__,
							L"tcp::SendFile",
							L"Tried to send %d bytes from file but only sent %d. Possible network error.",
							sent_bytes,
							bytes_read);
						break;
					}
					
					//
					bytes_left-=bytes_read;
				}
				
				//
				delete[] buf;
				buf=NULL;
			}
		}
		
		//
		fclose(h);
	}
	
	//
	return file_bytes_sent;
}

/*
*/
int tcp::RecvFile(const char* filename, bool append)
{
#ifdef _DEBUG
	printf("\ntcp::RecvFile filename=%s\n",filename);
	printf(" m_blocksize=%d m_cutoff_bytes=%d\n",m_blocksize,m_cutoff_bytes);
#endif
	
	//
	int file_bytes_received=0;
	
	//
	FILE* h=fopen(filename,append?"wba":"wb");
	if(h == NULL)
	{
		log.AddLog(
		_T(__FILE__),
		__LINE__,
		L"tcp::RecvFile",
		L"File (%S) could not be opened for binary write.",
		filename);
	}
	else
	{
		//
		int const cutoff_bytes=m_cutoff_bytes;
		cutoff(m_blocksize);
		
		//
		char* buf=NULL;
		do
		{
			int const recv_bytes=Recv(buf);
			if(buf)
			{
#ifdef _DEBUG
				printf(" writing %d bytes to file...\n\n",recv_bytes);
#endif
				
				int const write_bytes=fwrite(buf,1,recv_bytes,h);
				
#ifdef _DEBUG
				printf(" wrote %d bytes\n",write_bytes);
#endif
				
				//
				file_bytes_received+=write_bytes;
				
				//
				if(recv_bytes != write_bytes)
				{
					log.AddLog(
						_T(__FILE__),
						__LINE__,
						L"tcp::RecvFile",
						L"Tried to write %d bytes to file but only wrote %d. Disk/Storage media possibly full.",
						recv_bytes,
						write_bytes);
					break;
				}
			
				//
				delete[] buf;
				buf=NULL;
			}
		} while(is_cutoff());
		
		//
		cutoff(cutoff_bytes);
		
		//
		fclose(h);
	}
	
	//
	return file_bytes_received;
}

/*
// statistics to be displayed from non-debug (release) compiles of command-line test harnesses.
*/
void tcp::statistics(void)
{
	printf("############       STATISTICS     #############################\n");
	printf("###############################################################\n");
	
	printf("SOCKET       \t %d\n",m_sock);
	printf("INSTANCE     \t %d of %d\n",m_instance,m_last_instance);
	
	printf("keepalives  \t %d\n",is_keepalives());
	printf("nagledelay        \t %d\n",is_nagledelay());
	printf("stack_recv_buffer          \t %d\n",stack_recv_buffer());
	printf("stack_send_buffer          \t %d\n",stack_send_buffer());
	
	printf("\n");
	
	printf("last bytes sent            \t %ld\n",last_bytes_sent());
	printf("     bytes sent            \t %ld\n",bytes_sent());
	
	printf("last bytes received        \t %ld\n",last_bytes_received());
	printf("     bytes received        \t %ld\n",bytes_received());
	
	printf("last milliseconds sending  \t %lf\n",last_milliseconds_sending());
	printf("     milliseconds sending  \t %lf\n",milliseconds_sending());
	
	printf("last milliseconds receiving\t %lf\n",last_milliseconds_receiving());
	printf("     milliseconds receiving\t %lf\n",milliseconds_receiving());
	
	printf("last time sending          \t %ld\n",m_last_time_sending.QuadPart);
	printf("     time sending          \t %ld\n",m_time_sending.QuadPart);
	
	printf("last time receiving        \t %ld\n",m_last_time_receiving.QuadPart);
	printf("     time receiving        \t %ld\n",m_time_receiving.QuadPart);
	
	printf("last kbps sent             \t %lf\n",last_kbps_sent());
	printf("     kbps sent             \t %lf\n",kbps_sent());
	
	printf("last kbps recv             \t %lf\n",last_kbps_received());
	printf("     kbps recv             \t %lf\n",kbps_received());
	
	printf("ping                       \t %ld ms\n",ping());
	
	printf("send sleep                 \t %ld ms\n",send_sleep());
	printf("recv sleep                 \t %ld ms\n",recv_sleep());
	
	printf("send packets               \t %d\n",m_send_packets);
	printf("recv packets               \t %d\n",m_recv_packets);
	printf("recvbuffer faults          \t %d\n",m_recvbuffer_faults);
	printf("recv faults                \t %d\n",m_recv_faults);
	
	if(m_last_timeout > 0.0)
	{
		printf("**TIMEDOUT**             \t %lf\n",m_last_timeout);
	}
	
	printf("log:\n%S\n",log.Logs());
	
	printf("###############################################################\n");
}

/*
*/
bool tcp::is_keepalives(void)
{
	int len=sizeof(int);
	int i=0;
	int const err=getsockopt(m_sock,SOL_SOCKET,SO_KEEPALIVE,(char*)&i,&len);
	if(err == SOCKET_ERROR)
	{
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"tcp::is_keepalives",
			L"getsockopt failed. (%d) (%s)",
			WSAGetLastError(),
			CErrorStringWSA::ErrorString(WSAGetLastError()));
		return 0;
	}
	else
		return (bool)(i!=0);
}

/*
*/
bool tcp::is_nagledelay(void)
{
	int len=sizeof(int);
	int i=0;
	int const err=getsockopt(m_sock,IPPROTO_TCP,TCP_NODELAY,(char*) &i,&len);
	if(err == SOCKET_ERROR)
	{
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"tcp::is_nagledelay",
			L"getsockopt failed. (%d) (%s)",
			WSAGetLastError(),
			CErrorStringWSA::ErrorString(WSAGetLastError()));
		return 0;
	}
	else
		return (bool)(i==0);
}

/*
*/
void tcp::keepalives(bool flag)
{
	int i=(flag==0)?0:1;
	int const err=setsockopt(m_sock,SOL_SOCKET,SO_KEEPALIVE,(char*)&i,(int)sizeof(i));
	if(err == SOCKET_ERROR)
	{
		log.AddLog(
		_T(__FILE__),
		__LINE__,
		L"tcp::keepalives",
		L"setsockopt failed. (%d) (%s)",
		WSAGetLastError(),
		CErrorStringWSA::ErrorString(WSAGetLastError()));
	}
}

/*
*/
void tcp::nagledelay(bool flag)
{
	int i=(flag==0)?1:0;
	int const err=setsockopt(m_sock,IPPROTO_TCP,TCP_NODELAY,(char*)&i,(int)sizeof(i));
	if(err == SOCKET_ERROR)
	{
		log.AddLog(
		_T(__FILE__),
		__LINE__,
		L"tcp::nagledelay",
		L"setsockopt failed. (%d) (%s)",
		WSAGetLastError(),
		CErrorStringWSA::ErrorString(WSAGetLastError()));
	}
}
