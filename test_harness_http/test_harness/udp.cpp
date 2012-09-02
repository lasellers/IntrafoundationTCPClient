///////////////////////////////////////////////////////////////////////////
//
// INTRAFOUNDATION UDP (CLIENT) CLASS
//
// Written by Lewis A. Sellers, 2001-2004
// lsellers@intrafoundation.com
// http://www.intrafoundation.com/
//
///////////////////////////////////////////////////////////////////////////
/*
 Version History
 v1.5 July 13th 2004
 v1.4 April 21st 2004. Added new Log class. Cleaned up one or two things in passing.
 v1.3 sept 13 2001 cleanup (though not as much as at the WTC). fixed recv buffer bugs.
 v1.2 sept 2 2001.... cleanup for "packet" com functions
 v1.2 august 31 2001, beta/gamma cleanup
 v1.1 august 30 2001, beta/gamma cleanup
 v1.0 august 29/30 2001, major rewrite
 v0.0 august 22 or 26? 2001, from tcp class 2.5
 */
///////////////////////////////////////////////////////////////////////////
//
#include "stdafx.h"


#define WIN32_LEAN_AND_MEAN 	// Exclude rarely-used stuff from Windows headers
//#include <stdarg.h>

//
#include "stdio.h" //sprintf printf
//#include "winbase.h" // sleep
#include "windows.h" //getcurrentthreadid
//#include "winsock2.h" //project/settings/object/link: ws2_32.lib 

//
#include "udp.h"
#include "Log.h"
#include "ErrorStringWSA.h"

//
int udp::m_last_instance = 0;

///////////////////////////////////////////////////////////////////////////
//
//

//
udp::udp() {
	m_instance = ++m_last_instance;

	//
	reset();
	load_winsock();
}

//
udp::udp(char* const host, char* const port) {
	m_instance = ++m_last_instance;

#ifdef _DEBUG
	printf("\n\n\n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("udp::udp creating connectionless socket HOST=%s : PORT=%s (instance %d)\n\n",host,port,m_instance);
#endif

	//
	reset();
	load_winsock();

	//
	struct hostent *hp;
	struct servent *sp;
	int salen = sizeof(m_socka);
	size_t bytessent = 0L;

	//
	m_ping.QuadPart = 0;
	m_start_of_ping.QuadPart = 0;

	//preparations follow that set up socket structures
	if ((hp = gethostbyname(host)) == NULL) {
		log.AddLog(_T(__FILE__), __LINE__, 
			L"udp::udp", 
			L"No such host? (%S).",
				host);
		return;
	}

	// copy needed info out of hp before issuing any other winsock functions
	memmove((char *) &m_socka.sin_addr, (char *) hp->h_addr,hp->h_length);
	m_socka.sin_family = hp->h_addrtype;

	//
	m_socka.sin_port = ntohs(atoi(port));
	if (m_socka.sin_port == 0) {
		if ((sp = getservbyname(port, "udp")) == NULL) {
			log.AddLog(_T(__FILE__), __LINE__, L"udp::udp",
					L"No such well-known service (%S). Valid examples: whois, ftp, etc.",
					port);
			return;
		} else
			m_socka.sin_port = sp->s_port;
	}

	//
	if ((m_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET) {
		//
		log.AddLog(_T(__FILE__), __LINE__, L"udp::udp",
				L"Socket error while requesting a free UDP/SOCK_DGRAM socket handle: (%d) (%s)",
				WSAGetLastError(),
				CErrorStringWSA::ErrorString(WSAGetLastError()));
		return;
	}

	//
	memset(&m_locala, 0, sizeof(struct sockaddr_in));
	m_locala.sin_family = AF_INET;
	m_locala.sin_addr.s_addr = htonl(INADDR_ANY);
	m_locala.sin_port = htons(0);

	int const nbind = bind(m_sock, (struct sockaddr*) &m_locala,
			sizeof(m_locala));
	if (nbind == SOCKET_ERROR) {
		log.AddLog(_T(__FILE__), __LINE__, L"udp::udp",
				L"Bind failure: (%d) (%s)", WSAGetLastError(),
				CErrorStringWSA::ErrorString(WSAGetLastError()));
		return;
	}

	//connect to the server. or try to...
	if (connect(m_sock, (const struct sockaddr*) &m_socka, sizeof(m_socka))
			!= 0) {
		log.AddLog(_T(__FILE__), __LINE__, L"udp::udp",
				L"Connect error: socket=%d host=%S port=%S (%d) (%s)", m_sock,
				host, port, WSAGetLastError(),
				CErrorStringWSA::ErrorString(WSAGetLastError()));
		return;
	}

	//setup non-blocking async mode
	unsigned long argp1 = 1;
	if (ioctlsocket(m_sock, FIONBIO, &argp1) == SOCKET_ERROR) {
		log.AddLog(_T(__FILE__), __LINE__, L"udp::udp",
				L"Async/Non-blocking mode could not be enabled: (%d) (%s)",
				WSAGetLastError(),
				CErrorStringWSA::ErrorString(WSAGetLastError()));
		return;
	}

	//
	struct sockaddr_in sa;

	//
	int gsn;
	salen = sizeof(sa);
	if ((gsn = getsockname(m_sock, (struct sockaddr*) &sa, &salen)) != 0) {
		log.AddLog(_T(__FILE__), __LINE__, L"udp::udp",
				L"getsockname (local address) error: socket=%d.", m_sock);

		strcpy(m_localname, "0.0.0.0");
		m_localport = 0;
	} else {
		sprintf(m_localname, "%d.%d.%d.%d", sa.sin_addr.S_un.S_un_b.s_b1,
				sa.sin_addr.S_un.S_un_b.s_b2, sa.sin_addr.S_un.S_un_b.s_b3,
				sa.sin_addr.S_un.S_un_b.s_b4);
		m_localport = ntohs(sa.sin_port);
	}

	//
	int gpn;
	salen = sizeof(sa);
	if ((gpn = getpeername(m_sock, (struct sockaddr*) &sa, &salen)) != 0) {
		log.AddLog(_T(__FILE__), __LINE__, L"udp::udp",
				L"getpeername (peer address) error: socket=%d.", m_sock);

		strcpy(m_remotename, "0.0.0.0");
		m_remoteport = 0;
	} else {
		sprintf(m_remotename, "%d.%d.%d.%d", sa.sin_addr.S_un.S_un_b.s_b1,
				sa.sin_addr.S_un.S_un_b.s_b2, sa.sin_addr.S_un.S_un_b.s_b3,
				sa.sin_addr.S_un.S_un_b.s_b4);
		m_remoteport = ntohs(sa.sin_port);
	}
#ifdef _DEBUG
	printf("udp::udp connected. sock=%d\n\n",m_sock);
#endif

	//
	m_connected = true;

	// initialize frequency constant
	if (!QueryPerformanceFrequency(&m_frequency)) {
		log.AddLog(_T(__FILE__), __LINE__, L"udp::udp",
				L"QueryPerformanceFrequency failed. Timing functions will be inaccurate.");
	}
}

///////////////////////////////////////////////////////////////////////////
//
//
udp::~udp() {
#ifdef _DEBUG
	printf("udp::~udp releasing connectionless socket. sock=%d (instance %d)\n\n",m_sock,m_instance);
	printf("---------------------------------------------------------------\n");
#endif

	closesocket(m_sock);
	m_sock = 0;

	//
	unload_winsock();
}

///////////////////////////////////////////////////////////////////////////
//
//

/*
 */
void udp::load_winsock() {
#ifdef _DEBUG
	printf("udp::load_winsock\n\n");
#endif

	//verify the winsock version is at least version 2.0
	WORD wVersionRequested = MAKEWORD(2,0);
	WSADATA wsaData;
	int err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		// abort if less than 2.0
		log.AddLog(_T(__FILE__), __LINE__, L"udp::load_winsock",
				L"Current winsock is version %d.%d, but require at least 2.0. WSAStartup failure, (%d) (%s)",
				LOBYTE(wsaData.wVersion), HIBYTE(wsaData.wVersion), err,
				CErrorStringWSA::ErrorString(err));

		m_connected = false;
		return;
	}

#ifdef _DEBUG
	printf("Current winsock version %d.%d\n",LOBYTE(wsaData.wVersion),HIBYTE(wsaData.wVersion));
#endif
	if (LOBYTE(wsaData.wVersion) < 2 && HIBYTE(wsaData.wVersion) < 0) {
		// contine but warn if greater than 2.0
		log.AddLog(_T(__FILE__), __LINE__, L"udp::load_winsock",
				L"Warning: Current winsock is version %d.%d, but class designed for 2.0.",
				LOBYTE(wsaData.wVersion), HIBYTE(wsaData.wVersion) );
	}
}

/*
 */
void udp::unload_winsock() {
#ifdef _DEBUG
	printf("udp::unload_winsock\n\n");
#endif

	int const err = WSACleanup();
	if (err == SOCKET_ERROR) {
		log.AddLog(_T(__FILE__), __LINE__, L"udp::unload_winsock",
				L"WSACleanup can not close winsock: (%d) (%s)", err,
				CErrorStringWSA::ErrorString(err));
	}
}

/*
 */
void udp::reset() {
	// init socket id to null socket
	m_sock = 0;
	m_connected = false;

	//
	m_ping.QuadPart = 0;
	m_start_of_ping.QuadPart = 0;

	//
	m_localport = 0;
	m_remoteport = 0;
	m_localname[0] = '\0';
	m_remotename[0] = '\0';

	// default timeout values for winsock instance
	m_secs = 0L;
	m_msecs = 100L;

	// init sent/received byte count
	m_bytes_sent = 0L;
	m_bytes_received = 0L;

	m_last_bytes_sent = 0L;
	m_last_bytes_received = 0L;

	m_msecs_sending = 0L;
	m_msecs_receiving = 0L;

	m_send_packets = 0L;
	m_recv_packets = 0L;

	// init timedout
	m_last_timeout = 0.0;
}

///////////////////////////////////////////////////////////////////////////
//
//

/*
 */
long udp::Send(char* const buffer) {
	return Send(buffer, strlen(buffer));
}

/*
 */
long udp::Send(char* const buffer, size_t const length) {
#ifdef _DEBUG
	printf("\nudp::Send buffer=%p length=%d\n",buffer,length);
#endif

	if (m_sock == 0)
		return 0L;
	else {
		// get current high resolution time...
		LARGE_INTEGER tmp1;
		QueryPerformanceCounter(&tmp1);

		//???
		//check if length>sizeof(int) allows
		//
		const size_t bytes = sendto(m_sock, buffer, (int) length, 0, //MSG_OOB
				(const struct sockaddr*) &m_socka, sizeof(m_socka));
		m_send_packets++;

#ifdef _DEBUG
		printf(" bytes=%d\n",bytes);
		printf(" m_send_packets=%d\n",m_send_packets);
#endif

		//
		if ((bytes == SOCKET_ERROR)&&
		(WSAGetLastError()==WSAEWOULDBLOCK)
		);
		else if(
				(bytes==SOCKET_ERROR) &&
				(WSAGetLastError()!=WSAEWOULDBLOCK)
		)
		{
			//
			log.AddLog(
					_T(__FILE__),
					__LINE__,
					L"udp::Send",
					L"SEND failed: (bytes attempting to send %ld, address %p) (%d) (%s) ",
					length,buffer,
					WSAGetLastError(),
					CErrorStringWSA::ErrorString(WSAGetLastError()));
		}
		else
		m_bytes_sent+=bytes;

		// do timing updates for statistics functions
		LARGE_INTEGER tmp2;
		QueryPerformanceCounter(&tmp2);

		m_last_time_sending.QuadPart = tmp2.QuadPart - tmp1.QuadPart;
		m_time_sending.QuadPart += m_last_time_sending.QuadPart;

		// init our pseudo "ping" timer
		// (not an actual ICMP one, but close enough for our purposes)
		m_start_of_ping.QuadPart = tmp2.QuadPart;

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

#ifdef _DEBUG
		printf(" m_bytes_sent=%d\n",m_bytes_sent);
#endif

		//
		return (long) bytes;
	}
}

//////////////////////////////////////////////////////////////////////////
//
//

/*
 */
long udp::Recv(char* &recvp) {
#ifdef _DEBUG
	printf("\nudp::Recv recvp=%p\n",recvp);
#endif

	//
	if (m_sock == 0)
		return 0L;
	else {
		//
		delete[] recvp;
		//the recv buffer is always 65507 bytes to handle the binary packet functions of the COM
		recvp = new char[MAX_PACKET_SIZE + 1 + 1];
		if (recvp == NULL) {
			log.AddLog(_T(__FILE__), __LINE__, L"udp::Recv",
					L"Memory allocation of %d bytes failed.",
					MAX_PACKET_SIZE + 1 + 1);
			return 0;
		} else {
			//
			//*recvp='\0';
			memset(recvp, 0, MAX_PACKET_SIZE + 1 + 1);

			// get current high resolution time...
			LARGE_INTEGER tmp1;
			QueryPerformanceCounter(&tmp1);

			//
			int salen = sizeof(m_socka);

			//
			m_last_timeout = 0.0;

			//
			struct timeval tv;
			tv.tv_sec = (long) m_secs;
			tv.tv_usec = (long) m_msecs;
			fd_set readfds;

			//
			int readsocks = 0;
			size_t bytes = 0L;

			//
			do {
				//
				FD_ZERO(&readfds);
				FD_SET(m_sock, &readfds);

				readsocks = select(FD_SETSIZE, &readfds, NULL, NULL, &tv);
#ifdef _DEBUG
				printf(" readsocks=%d\n",readsocks);
#endif
				//
				if (readsocks == SOCKET_ERROR) {
					if (WSAGetLastError() != WSAEWOULDBLOCK) {
						log.AddLog(_T(__FILE__), __LINE__, L"udp::Recv",
								L"SELECT read error: (%d) (%s)",
								WSAGetLastError(),
								CErrorStringWSA::ErrorString(
										WSAGetLastError()));
					}
				} else if (readsocks == 0) {
					m_last_timeout = (double) tv.tv_sec
							+ ((double) tv.tv_usec) * .001;

					//
					log.AddLog(_T(__FILE__), __LINE__, L"udp::Recv",
							L"RECV Error - no response for %lds %lums.",
							tv.tv_sec, tv.tv_usec);
					break;
				} else {
					memset(recvp, 0, MAX_PACKET_SIZE);
					bytes = recvfrom(m_sock, recvp, MAX_PACKET_SIZE, 0,
							(struct sockaddr*) &m_socka, &salen);
					m_recv_packets++;
#ifdef _DEBUG
					printf(" bytes=%d\n",bytes);
					printf(" m_recv_packets=%d\n",m_recv_packets);
#endif

					//
					// compute "ping". For our purposes we mark the time between starting a send and
					// receiving back anything. not accurate in many cases but close enough.
					if (m_start_of_ping.QuadPart > 0) {
						LARGE_INTEGER tmp0;
						QueryPerformanceCounter(&tmp0);
						m_ping.QuadPart = tmp0.QuadPart
								- m_start_of_ping.QuadPart;
					}

					//
					if (bytes == SOCKET_ERROR) {
						if (WSAGetLastError() != WSAEWOULDBLOCK
								&& WSAGetLastError() != WSAECONNRESET) {
							log.AddLog(_T(__FILE__), __LINE__, L"udp::Recv",
									L"RECV socket error: (%d) (%s)",
									WSAGetLastError(),
									CErrorStringWSA::ErrorString(
											WSAGetLastError()));
						}
					} else if (bytes == 0) //eof
						;
					else if (bytes > 0) {
						//
						*(recvp + bytes) = '\0';

						//
						m_bytes_received += bytes;
					}
				}
			} while (((readsocks == SOCKET_ERROR)&& (WSAGetLastError() == WSAEWOULDBLOCK))|| //waiting on (slow) network
			((bytes == SOCKET_ERROR) && (WSAGetLastError() == WSAEWOULDBLOCK))//waiting on (slow) network
			);

			// do timing updates for statistics functions
			LARGE_INTEGER tmp2;
			QueryPerformanceCounter(&tmp2);

			m_last_time_receiving.QuadPart = tmp2.QuadPart - tmp1.QuadPart;
			m_time_receiving.QuadPart += m_last_time_receiving.QuadPart;

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

#ifdef _DEBUG
			printf(" recvp=%p\n",recvp);
			printf(" m_bytes_received=%u\n",m_bytes_received);
#endif

			//
			return (long) bytes;
		}
	}
}

///////////////////////////////////////////////////////////////////////////
//
//

/*
 */
void udp::timeout(int const secs, int const msecs) {
	// pass on timeout values to winsock instance
	m_secs = secs;
	m_msecs = msecs;

#ifdef _DEBUG
	printf("udp::timeout setting timeout: secs=%d msecs=%d\n\n",secs,msecs);
#endif
}

/*
 */
void udp::get_timeout(int &secs, int &msecs) {
	secs = m_secs;
	msecs = m_msecs;

#ifdef _DEBUG
	printf("udp::timeout getting timeout: secs=%d msecs=%d\n\n",secs,msecs);
#endif
}

///////////////////////////////////////////////////////////////////////////
//

/*
 */
SOCKET udp::udpsocket() {
	return m_sock;
}

/*
 local and remote
 */
int udp::endpoints(char* &local_ip, int& local_port, char* &remote_ip,
		int& remote_port) {
	if (m_sock == 0) {
		log.AddLog(_T(__FILE__), __LINE__, L"udp::endpoints",
				L"endpoints() sock==0 error.");

		const char a0000[] = "0.0.0.0";

		//
		local_ip = new char[MAX_ADDRESS + 1];
		if (local_ip)
			memcpy(local_ip, a0000, strlen(a0000) + 1);
		else {
			local_ip = NULL;
			log.AddLog(_T(__FILE__), __LINE__, L"udp::endpoints",
					L"Memory allocation of %d bytes failed.",
					MAX_ADDRESS + 1);
		}

		local_port = 0;

		//
		remote_ip = new char[MAX_ADDRESS + 1];
		if (remote_ip)
			memcpy(remote_ip, a0000, strlen(a0000) + 1);
		else {
			remote_ip = NULL;
			log.AddLog(_T(__FILE__), __LINE__, L"udp::endpoints",
					L"Memory allocation of %d bytes failed.",
					MAX_ADDRESS + 1);
		}

		remote_port = 0;
	} else {
		//
		local_ip = new char[MAX_ADDRESS + 1];
		if (local_ip)
			memcpy(local_ip, m_localname, strlen(m_localname) + 1);
		else {
			local_ip = NULL;
			log.AddLog(_T(__FILE__), __LINE__, L"udp::endpoints",
					L"Memory allocation of %d bytes failed.",
					MAX_ADDRESS + 1);
		}

		local_port = m_localport;

		//
		remote_ip = new char[MAX_ADDRESS + 1];
		if (remote_ip)
			memcpy(remote_ip, m_remotename, strlen(m_remotename) + 1);
		else {
			remote_ip = NULL;
			log.AddLog(_T(__FILE__), __LINE__, L"udp::endpoints",
					L"Memory allocation of %d bytes failed.",
					MAX_ADDRESS + 1);
		}

		remote_port = m_remoteport;
	}

	return 0;
}

/*
 */
void udp::bytestransferred(size_t& bytes_sent, size_t& bytes_received) {
	bytes_sent = m_bytes_sent;
	bytes_received = m_bytes_received;
}

/*
 */
void udp::bufferlengths(size_t& sendlength, size_t& recvlength,
		size_t& buffersize, size_t& messagelength) {
	int len = sizeof(int);

	buffersize = (size_t) MAX_PACKET_SIZE;
	recvlength = 0;
	sendlength = 0;
	messagelength = 0;

	if (m_sock != 0) {
		int i = 0;
		if (getsockopt(m_sock, SOL_SOCKET, SO_RCVBUF, (char *) i, &len) != 0)
			recvlength = i;

		i = 0;
		if (getsockopt(m_sock, SOL_SOCKET, SO_SNDBUF, (char *) i, &len) != 0)
			sendlength = i;

		i = 0;
		if (getsockopt(m_sock, SOL_SOCKET, SO_MAX_MSG_SIZE, (char *) i, &len)
				!= 0)
			messagelength = i;
	}
}

/*
 */
double udp::kbps_sending() {
	if (m_bytes_sent == 0 || m_msecs_sending == 0.0)
		return 0.0;
	else
		return ((double) m_bytes_sent / 1024.0)
				/ ((double) m_msecs_sending / 1000.0);
}

/*
 */
double udp::kbps_receiving() {
	if (m_bytes_received == 0 || m_msecs_receiving == 0.0)
		return 0.0;
	else
		return ((double) m_bytes_received / 1024.0)
				/ ((double) m_msecs_receiving / 1000.0);
}

/*
 */
bool udp::is_connected() {
#ifdef _DEBUG
	printf("udp::is_connected %d m_connected=%s\n",m_connected,m_connected==true?"true":"false");
#endif
	return m_connected;
}

/*
 */
DWORD udp::ping() {
	return (DWORD) (((double) m_ping.QuadPart / (double) m_frequency.QuadPart)
			* 1000.0);
}

/*
 */
size_t udp::send_packets() {
	return m_send_packets;
}

/*
 */
size_t udp::recv_packets() {
	return m_recv_packets;
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

/*
 */
double udp::kbps_sent(void) {
	if (m_time_sending.QuadPart && m_bytes_sent) {
		const double numerator = (double) m_bytes_sent / 1024.0;
		const double divisor = ((double) m_time_sending.QuadPart
				/ (double) m_frequency.QuadPart);
		return numerator / divisor;
	} else
		return 0.0;
}

/*
 */
double udp::last_kbps_sent(void) {
	if (m_last_time_sending.QuadPart && m_last_bytes_sent) {
		const double numerator = (double) m_last_bytes_sent / 1024.0;
		const double divisor = ((double) m_last_time_sending.QuadPart
				/ (double) m_frequency.QuadPart);
		return numerator / divisor;
	} else
		return 0.0;
}

/*
 */
double udp::kbps_received(void) {
	if (m_time_receiving.QuadPart && m_bytes_received) {
		const double numerator = (double) m_bytes_received / 1024.0;
		const double divisor = ((double) m_time_receiving.QuadPart
				/ (double) m_frequency.QuadPart);
		return numerator / divisor;
	} else
		return 0.0;
}

/*
 */
double udp::last_kbps_received(void) {
	if (m_last_time_receiving.QuadPart && m_last_bytes_received) {
		const double numerator = (double) m_last_bytes_received / 1024.0;
		const double divisor = (double) m_last_time_receiving.QuadPart
				/ (double) m_frequency.QuadPart;
		return numerator / divisor;
	} else
		return 0.0;
}

/*
 */
size_t udp::bytes_sent(void) {
	return m_bytes_sent;
}

/*
 */
double udp::milliseconds_sending(void) {
	return ((double) m_time_sending.QuadPart / (double) m_frequency.QuadPart)
			* 1000.0;
}

/*
 */
double udp::milliseconds_receiving(void) {
	return ((double) m_time_receiving.QuadPart / (double) m_frequency.QuadPart)
			* 1000.0;
}

/*
 */
double udp::last_milliseconds_sending(void) {
	return ((double) m_last_time_sending.QuadPart
			/ (double) m_frequency.QuadPart) * 1000.0;
}

/*
 */
double udp::last_milliseconds_receiving(void) {
	return ((double) m_last_time_receiving.QuadPart
			/ (double) m_frequency.QuadPart) * 1000.0;
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

/*
 statistics to be displayed from non-debug (release) compiles of command-line test harnesses.
 */
void udp::statistics() {
	printf("############       STATISTICS     #############################\n");
	printf("###############################################################\n");

	printf("SOCKET   \t %d\n", m_sock);
	printf("INSTANCE \t %d of %d\n", m_instance, m_last_instance);

	printf("last bytes sent            \t %ld\n", m_last_bytes_sent);
	printf("     bytes sent            \t %ld\n", m_bytes_sent);

	printf("last bytes received        \t %ld\n", m_last_bytes_received);
	printf("     bytes received        \t %ld\n", m_bytes_received);

	printf("ping                       \t %ld ms\n", ping());

	printf("send packets               \t %d\n", m_send_packets);
	printf("recv packets               \t %d\n", m_recv_packets);

	if (m_last_timeout > 0.0) {
		printf("**TIMEDOUT**               \t %lf\n", m_last_timeout);
	}

	printf("log:\n%S\n", log.Logs());

	printf("BUFFERLENGTHS##################################################\n");
	size_t sendlength;
	size_t recvlength;
	size_t buffersize;
	size_t messagelength;
	bufferlengths(sendlength, recvlength, buffersize, messagelength);
	printf("sendlength\t%d\n", sendlength);
	printf("recvlength\t%d\n", recvlength);
	printf("buffersize\t%d\n", buffersize);
	printf("messagelength\t%d\n", messagelength);

	printf("ENDPOINTS######################################################\n");
	int lp;
	int rp;
	char *lip = NULL;
	char *rip = NULL;
	endpoints(lip, lp, rip, rp);
	printf("local \t %s:%d\n", lip, lp);
	printf("remote\t %s:%d\n", rip, rp);

	printf("###############################################################\n");
}
