/////////////////////////////////////////////////////////////////////////////
//
// Intrafoundation.Tcpclient.3
//
// Copyright 1999, 200, 2001, 2003, 2004 by Lewis A. Sellers (AKA Min)
// http://www.intrafoundation.com
// webmaster@intrafoundation.com
//
// Software Homepage: http://www.intrafoundation.com/software/tcpclient.htm
//
//
/////////////////////////////////////////////////////////////////////////////

// TCPClient.cpp : Implementation of CTcpclientcomApp and DLL registration.

/*
ORIGINAL 2.X:
send stats

secs	kbps
x 1	3636  277.56
x 2	1983  508.945
x 4	1202  839.63
x 8	741   1361.995
x 16	24755  40.76

x 64		 2587
-----
x 128		 318
x 256		  704
x 512		  1229
x 1024		  969

recv stats

secs  kbps
x 1   82909  12.17
x 2   42070  23.98
x 4   20449  48.19
x 8   10786   93.56
x 16  5548	181.91
x 32		349
x 64		618   (32768)
----------------- 32708
x 128		847
x 256		1185
x 512		1975
x 1024		 2242

recv blocksize 30mb
blocksize 		kbps
32768 	  639	22
262144	  562	159
1048576	  642	611
*/
#if !defined(_MT)
#error This software requires a multithreaded C run-time library.
#endif

//
#include "stdafx.h"
#include "tcpclientcom.h"
#include "TCPClient.h"

/////////////////////////////////////////////////////////////////////////////
//

// _open file handling
#include "io.h"
#include <fcntl.h>

//bstr
#include <comdef.h>

// _stat
#include "sys\stat.h"

//
#define MAX_DWORDEXPANSION	32
#define MAX_IPEXPANSION 	(26+60)
#define MAX_PORTEXPANSION	(5+16)
#define MAX_URLEXPANSION	(26+60+1+5)

//
#include "Mutex.h"
#include "Log.h"
#include "BSTR.h"
#include "ErrorStringWSA.h"

#include "MD5.h"

/////////////////////////////////////////////////////////////////////////////
//
//

const char *description="Intrafoundation.TCPClient.3";
const char *copyright="Copyright (c) 2000, 20001, 2003, 2004, 2012 by Lewis Sellers. <a href=\"http://www.intrafoundation.com\">http://intrafoundation.com</a>";
const char *version="3.2, August 30th 2012";

// TRUE and FALSE defined as ints to support old version of CF that don't understand boolean types.
// Annoying.
//const int TRUE=1;
//const int FALSE=0;

/////////////////////////////////////////////////////////////////////////////
//
//

/*
statics
*/
int CTCPClient::m_last_instance=0;
CMutex CTCPClient::mutex;

/*
*/
unsigned _int64 CTCPClient::bitmask[64]={
	0x1,
	0x3,
	0x7,
	0xf,
	0x1f,
	0x3f,
	0x7f,
	0xff,
	0x1ff,
	0x3ff,
	0x7ff,
	0xfff,
	0x1fff,
	0x3fff,
	0x7fff,
	0xffff,
	0x1ffff,
	0x3ffff,
	0x7ffff,
	0xfffff,
	0x1fffff,
	0x3fffff,
	0x7fffff,
	0xffffff,
	0x1ffffff,
	0x3ffffff,
	0x7ffffff,
	0xfffffff,
	0x1fffffff,
	0x3fffffff,
	0x7fffffff,
	0xffffffff,
	0x1ffffffff,
	0x3ffffffff,
	0x7ffffffff,
	0xfffffffff,
	0x1fffffffff,
	0x3fffffffff,
	0x7fffffffff,
	0xffffffffff,
	0x1ffffffffff,
	0x3ffffffffff,
	0x7ffffffffff,
	0xfffffffffff,
	0x1fffffffffff,
	0x3fffffffffff,
	0x7fffffffffff,
	0xffffffffffff,
	0x1ffffffffffff,
	0x3ffffffffffff,
	0x7ffffffffffff,
	0xfffffffffffff,
	0x1fffffffffffff,
	0x3fffffffffffff,
	0x7fffffffffffff,
	0xffffffffffffff,
	0x1ffffffffffffff,
	0x3ffffffffffffff,
	0x7ffffffffffffff,
	0xfffffffffffffff,
	0x1fffffffffffffff,
	0x3fffffffffffffff,
	0x7fffffffffffffff,
	0xffffffffffffffff
};

/////////////////////////////////////////////////////////////////////////////
//
//

/*
*/
CTCPClient::CTCPClient()
{
	m_instance=++m_last_instance;

	//
	if(mutex.Try())
	{
		w=NULL;
	}
}



/*
*/
CTCPClient::~CTCPClient()
{
	Close();
}



/////////////////////////////////////////////////////////////////////////////
//
//

/*

Returns:
a boolean in the form of a long (because old versions of CF4 are too stupid to use a true boolean.)
*/
STDMETHODIMP CTCPClient::Open(
	BSTR strhost,
	BSTR strport,
	long *pconnected
	)
{
#ifdef _DEBUG
	printf("CTCPClient::Open strhost=%S strport=%S (thread %lu)\n",strhost,strport,GetCurrentThreadId());
#endif

	//
	*pconnected=TRUE;

	//
	mutex.Lock();

	//
	if(mutex.Try())
	{
		//
		if(!w)
		{
			//
			char ip[MAX_IPEXPANSION+1];
			char port[MAX_PORTEXPANSION+1];

			wcstombs(ip,strhost,min(wcslen(strhost)+1,MAX_IPEXPANSION));
			wcstombs(port,strport,min(wcslen(strport)+1,MAX_PORTEXPANSION));

			w=new tcp(
				(char* const)ip,
				(char* const)port
				);
			if(w)
			{
				if(w->is_connected())
					*pconnected=TRUE;
				else
				{
					*pconnected=FALSE;
					log.AddLog(
						_T(__FILE__),
						__LINE__,
						L"CTCPClient::Open",
						L"Low-level tcp class is_connected (%s) failed on host %S:%S.",
						w->is_connected()?L"true":L"false",ip,port);
					delete w;
					w=NULL;
				}
			}
		}

		//
		mutex.Untry();
	}

	return S_OK;
}




/////////////////////////////////////////////////////////////////////////////
//
//

/*
*/
STDMETHODIMP CTCPClient::Close()
{
#ifdef _DEBUG
	printf("CTCPClient::Close (thread %lu)\n",GetCurrentThreadId());
#endif

	//
	mutex.Unlock();

	//
	if(!w)
	{
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"CTCPClient::Close",
			L"Socket not open.");
	}
	else
	{
		delete w;
		w=NULL;
	}

	return S_OK;
}



/////////////////////////////////////////////////////////////////////////////
//
//

/*
*/
STDMETHODIMP CTCPClient::Send(BSTR inText)
{
#ifdef _DEBUG
	CBSTR bstr_fns;
	printf("CTCPClient::Send inText=%S inText_length=%d\n",inText,bstr_fns.character_length(inText));
#endif

	//
	HRESULT retval=S_OK;

	//
	if(mutex.Try())
	{
		//
		if(!w)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CTCPClient::Send",
				L"Socket not open.");
		}
		else
		{
			if(inText!=NULL)
			{
				CBSTR bstr;
				const int inText_length=bstr.character_length(inText);
				char *pszstr=new char[inText_length+1];
				if(pszstr)
				{
					wcstombs(pszstr,inText,inText_length);
#ifdef _DEBUG
					printf("inText_length=%d\n",inText_length);
					printf("pszstr=%s\n",pszstr);
#endif
					w->Send(pszstr,inText_length);
					delete[] pszstr;
					pszstr=NULL;
				}
				else
				{
					log.AddLog(
						_T(__FILE__),
						__LINE__,
						L"CTCPClient::Send",
						L"Memory allocation failure (%d bytes).",inText_length);

					retval=E_OUTOFMEMORY;
				}
			}
			else
				retval=E_POINTER;
		}
		//
		mutex.Untry();
	}

	return retval;
}


/*
*/
STDMETHODIMP CTCPClient::Recv(BSTR *poutText)
{
	//
	HRESULT retval=S_OK;

	//
	if(mutex.Try())
	{
		//
		if(!w)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CTCPClient::Recv",
				L"Socket not open.");
			*poutText=SysAllocString(L"");
		}
		else
		{
			char *buf=NULL;
			const int buf_length=w->Recv(buf);
			if(buf_length<=0)
				*poutText=SysAllocString(L"");
			else
			{
				BSTR bstr=new wchar_t[buf_length+1]; //new bstr section to get around iis5's 256kb stack limit
				if(bstr)
				{
					const size_t w_buf_length=mbstowcs(bstr,buf,buf_length+1);
					*poutText=SysAllocStringLen(bstr,(unsigned int)w_buf_length);
					delete[] bstr;
					bstr=NULL;
				}
				else
				{
					log.AddLog(
						_T(__FILE__),
						__LINE__,
						L"CTCPClient::Recv",
						L"Memory allocation failure (%d bytes).",
						buf_length);

					retval=E_OUTOFMEMORY;
				}
			}

			delete[] buf;
			buf=NULL;
		}
		//
		mutex.Untry();
	}
	else
		*poutText=SysAllocString(L"");

	return retval;
}



/////////////////////////////////////////////////////////////////////////////
//
//

/*
*/
STDMETHODIMP CTCPClient::SendRN(BSTR inText)
{
#ifdef _DEBUG
	CBSTR bstr_fns;

	printf("CTCPClient::SendRN inText=%S inText_length=%d\n",inText,bstr_fns.sz_length(inText));

	printf(" sz_length=%d\n",bstr_fns.sz_length(inText));
	printf(" character_length=%d\n",bstr_fns.character_length(inText));
	printf(" bytes=%d\n",bstr_fns.bytes(inText));
#endif

	//
	HRESULT retval=S_OK;

	//
	if(mutex.Try())
	{
		//
		if(!w)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CTCPClient::SendRN",
				L"Socket not open.");
		}
		else
		{
			if(inText!=NULL)
			{
				CBSTR bstr;
				const int inText_length=bstr.sz_length(inText);
				char *pszstr=new char[inText_length+1];
				if(pszstr)
				{
					wcstombs(pszstr,inText,inText_length+1);
#ifdef _DEBUG
					printf("inText_length=%d\n",inText_length);
					printf("pszstr=%s\n",pszstr);
#endif

					w->SendCRLF(pszstr,inText_length);

					delete[] pszstr;
					pszstr=NULL;
				}
				else
				{
					log.AddLog(
						_T(__FILE__),
						__LINE__,
						L"CTCPClient::SendRN",
						L"Memory allocation failure (%d bytes).",
						inText_length);

					retval=E_OUTOFMEMORY;
				}
			}
			else
				w->SendCRLF(NULL,0);
		}
		//
		mutex.Untry();
	}

	//
	return retval;
}


/*
*/
STDMETHODIMP CTCPClient::RecvRN(BSTR * poutText)
{
	//
	HRESULT retval=S_OK;

	//
	if(mutex.Try())
	{
		//
		if(!w)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CTCPClient::RecvRN",
				L"Socket not open.");
			*poutText=SysAllocString(L"");
		}
		else
		{
			char *buf=NULL;

			const int buf_length=w->RecvCRLF(buf);
			if(buf_length<=0)
				*poutText=SysAllocString(L"");
			else
			{
				BSTR bstr=new wchar_t[buf_length+1]; //new bstr section to get around iis5's 256kb stack limit
				if(bstr)
				{
					const size_t w_buf_length=mbstowcs(bstr,buf,buf_length+1);
					*poutText=SysAllocStringLen(bstr,(unsigned int)w_buf_length);
					delete[] bstr;
					bstr=NULL;
				}
				else
				{
					log.AddLog(
						_T(__FILE__),
						__LINE__,
						L"CTCPClient::RecvRN",
						L"Memory allocation failure (%d bytes).",
						buf_length);

					retval=E_OUTOFMEMORY;
				}
			}

			delete[] buf;
			buf=NULL;
		}
		//
		mutex.Untry();
	}
	else
		*poutText=SysAllocString(L"");

	return retval;
}


/*
*/
STDMETHODIMP CTCPClient::FlushRN()
{
	//
	if(mutex.Try())
	{
		//
		if(!w)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CTCPClient::FlushRN",
				L"Socket not open.");
		}
		else
			w->EmptyRecvBuffer();
	}

	return S_OK;
}



/////////////////////////////////////////////////////////////////////////////
//
//

/*
*/
STDMETHODIMP CTCPClient::SendFile(BSTR strFilename)
{
	//
	HRESULT retval=S_OK;

	//
	if(mutex.Try())
	{
		//
		if(!w)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CTCPClient::SendFile",
				L"Socket not open.");
		}
		else
		{
			//get filename contents
			char filename[MAX_PATH+1];
			wcstombs(filename,strFilename,wcslen(strFilename)+1);

			// call optimized network file send function.
			w->SendFile(filename);
		}
		//
		mutex.Untry();
	}

	return retval;
}


/*
*/
STDMETHODIMP CTCPClient::RecvFile(BSTR strFilename)
{
	//
	HRESULT retval=S_OK;

	//
	if(mutex.Try())
	{
		//
		if(!w)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CTCPClient::RecvFile",
				L"Socket not open.");
		}
		else
		{
			//get filename contents
			char filename[MAX_PATH+1];
			wcstombs(filename,strFilename,wcslen(strFilename)+1);

			// call optimized network file recv function. no append.
			w->RecvFile(filename,false);
		}
		//
		mutex.Untry();
	}

	return retval;
}


/*
*/
STDMETHODIMP CTCPClient::RecvFileAppend(BSTR strFilename)
{
	//
	HRESULT retval=S_OK;

	//
	if(mutex.Try())
	{
		//
		if(!w)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CTCPClient::RecvFileAppend",
				L"Socket not open.");
		}
		else
		{
			//get filename contents
			char filename[MAX_PATH+1];
			wcstombs(filename,strFilename,wcslen(strFilename)+1);

			// call optimized network file revc function. append file.
			w->RecvFile(filename,true);
		}
		//
		mutex.Untry();
	}

	return retval;
}



/////////////////////////////////////////////////////////////////////////////
//
//

/*
*/
STDMETHODIMP CTCPClient::SendCSV(BSTR inText)
{
	//
	HRESULT retval=S_OK;

	//
	if(mutex.Try())
	{
		//
		if(!w)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CTCPClient::SendCSV",
				L"Socket not open.");
		}
		else
		{
			if(inText!=NULL)
			{
				//
				const size_t inText_length=wcslen(inText)+1;
				char *csv=new char[inText_length];
				if(csv)
				{
					wcstombs(csv,inText,inText_length);

					//
					char *decsv=new char[inText_length];
					if(decsv==NULL)
					{
						log.AddLog(
							_T(__FILE__),
							__LINE__,
							L"CTCPClient::SendCSV",
							L"Memory allocation failure (%d bytes).",
							inText_length);

						retval=E_OUTOFMEMORY;
					}
					else
					{
						//
						char *s=csv;
						char *d=decsv;
						int count=0;
						char *c=NULL;
						do
						{
							const int i=atoi(s);
							*d=(BYTE)i;
							d++;
							c=strchr(s,',');
							if(c)
								s=c+1;
							count++;
						} while(c!=NULL);

						//
						w->Send( decsv, count);

						//
						delete[] decsv;
						decsv=NULL;
					}

					//
					delete[] csv;
					csv=NULL;
				}
			}
			else
				retval=E_POINTER;
		}
		//
		mutex.Untry();
	}

	return retval;
}



/*
*/
STDMETHODIMP CTCPClient::RecvCSV(BSTR * poutText)
{
	//
	HRESULT retval=S_OK;

	//
	if(mutex.Try())
	{
		//
		if(!w)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CTCPClient::RecvCSV",
				L"Socket not open.");
			*poutText=SysAllocString(L"");
		}
		else
		{
			int buflength=0;

			// get data
			char *buf=NULL;
			buflength=w->Recv(buf);

			// decode raw data to csv
			if(buflength<=0)
				*poutText=SysAllocString(L"");
			else
			{
				//
				const int newbuflength=buflength*4;
				char *newbuf=new char[newbuflength];
				if(newbuf)
				{
					newbuf[0]='\0';

					char *s=buf;
					for(int i=0;i<buflength;i++)
					{
						char tmp[MAX_DWORDEXPANSION];
						_itoa((BYTE)*s,tmp,10);
						if(i!=0)
							strcat(newbuf,",");
						strcat(newbuf,tmp);
						s++;
					}

					//new bstr section to get around iis5's 256kb stack limit
					BSTR wbuf=new wchar_t[newbuflength+1];
					if(wbuf)
					{
						mbstowcs(wbuf,newbuf,newbuflength+1);
						*poutText=SysAllocString(wbuf);
						delete[] wbuf;
						wbuf=NULL;
					}
					else
					{
						log.AddLog(
							_T(__FILE__),
							__LINE__,
							L"CTCPClient::RecvCSV",
							L"Memory allocation failure (%d bytes).",
							newbuflength);

						retval=E_OUTOFMEMORY;
					}

					//
					delete[] newbuf;
					newbuf=NULL;
				}
				else
				{
					log.AddLog(
						_T(__FILE__),
						__LINE__,
						L"CTCPClient::RecvCSV",
						L"Memory allocation failure (%d bytes).",
						newbuflength);

					retval=E_OUTOFMEMORY;
				}
			}

			//
			delete[] buf;
			buf=NULL;
		}
		//
		mutex.Untry();
	}
	else
		*poutText=SysAllocString(L"");

	return retval;
}




/////////////////////////////////////////////////////////////////////////////
//
//

/*
*/
STDMETHODIMP CTCPClient::put_timeout(double secs)
{
	//
	if(mutex.Try())
	{
		//
		if(!w)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CTCPClient::put_timeout",
				L"Socket not open.");
		}
		else
		{
			int s,ms;
			s=(int)secs;
			ms=(int)((secs-(double)s)*1000);
			w->timeout(s,ms);
		}
		//
		mutex.Untry();
	}

	return S_OK;
}

/*
*/
STDMETHODIMP CTCPClient::put_cutoff(long bytes)
{
	//
	if(mutex.Try())
	{
		//
		if(!w)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CTCPClient::put_cutoff",
				L"Socket not open.");
		}
		else
			w->cutoff(bytes);
		//
		mutex.Untry();
	}
	return S_OK;
}


/*
*/
STDMETHODIMP CTCPClient::put_blocksize(long bytes)
{
	//
	if(mutex.Try())
	{
		//
		if(!w)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CTCPClient::put_blocksize",
				L"Socket not open.");
		}
		else
			w->blocksize(bytes);
		//
		mutex.Untry();
	}
	return S_OK;
}



/*
*/
STDMETHODIMP CTCPClient::put_packetsize(long bytes)
{
	//
	if(mutex.Try())
	{
		//
		if(!w)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CTCPClient::put_packetsize",
				L"Socket not open.");
		}
		else
			w->packetsize(bytes);
		//
		mutex.Untry();
	}
	return S_OK;
}



/*
*/
STDMETHODIMP CTCPClient::put_keepalives(long flag)
{
	//
	if(mutex.Try())
	{
		//
		if(!w)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CTCPClient::put_keepalives",
				L"Socket not open.");
		}
		else
			w->keepalives(flag!=0);
		//
		mutex.Untry();
	}
	return S_OK;
}

/*
*/
STDMETHODIMP CTCPClient::put_nagledelay(long flag)
{
	//
	if(mutex.Try())
	{
		//
		if(!w)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CTCPClient::put_nagledelay",
				L"Socket not open.");
		}
		else
			w->nagledelay(flag!=0);
		//
		mutex.Untry();
	}
	return S_OK;
}


/*
*/
STDMETHODIMP CTCPClient::put_set_timeout(double secs)
{
	return put_timeout(secs);
}

/*
*/
STDMETHODIMP CTCPClient::put_set_cutoff(long bytes)
{
	return put_cutoff(bytes);
}

/*
*/
STDMETHODIMP CTCPClient::put_set_blocksize(long bytes)
{
	return put_blocksize(bytes);
}

/*
*/
STDMETHODIMP CTCPClient::put_set_packetsize(long bytes)
{
	return put_packetsize(bytes);
}

/*
*/
STDMETHODIMP CTCPClient::put_set_keepalives(long flag)
{
	return put_keepalives(flag);
}

/*
*/
STDMETHODIMP CTCPClient::put_set_nagledelay(long flag)
{
	return put_nagledelay(flag);
}




/////////////////////////////////////////////////////////////////////////////
//
//

/*
*/
STDMETHODIMP CTCPClient::get_timeout(double *psecs)
{
	if(w)
		*psecs=(double)w->timeout();
	else
		*psecs=0.0;
	return S_OK;
}

/*
*/
STDMETHODIMP CTCPClient::get_last_timeout(double *psecs)
{
	if(w)
		*psecs=(double)w->last_timeout();
	else
		*psecs=0.0;
	return S_OK;
}

/*
*/
STDMETHODIMP CTCPClient::get_cutoff(long *pstatus)
{
	if(w)
		*pstatus=(long)w->cutoff();
	else
		*pstatus=0L;
	return S_OK;
}

/*
*/
STDMETHODIMP CTCPClient::get_blocksize(long *pbytes)
{
	if(w)
		*pbytes=(long)w->blocksize();
	else
		*pbytes=0L;
	return S_OK;
}

/*
*/
STDMETHODIMP CTCPClient::get_packetsize(long *pbytes)
{
	if(w)
		*pbytes=(long)w->packetsize();
	else
		*pbytes=0L;
	return S_OK;
}





/////////////////////////////////////////////////////////////////////////////
//
//

/*
*/
STDMETHODIMP CTCPClient::get_description(BSTR* pstr)
{
	CComBSTR bstrtmp(description);
	if(!bstrtmp)
		return E_POINTER;
	else
	{
		*pstr=bstrtmp.Detach();
		return S_OK;
	}
}


/*
*/
STDMETHODIMP CTCPClient::get_copyright(BSTR* pstr)
{
	CComBSTR bstrtmp(copyright);
	if(!bstrtmp)
		return E_POINTER;
	else
	{
		*pstr=bstrtmp.Detach();
		return S_OK;
	}
}


/*
*/
STDMETHODIMP CTCPClient::get_version(BSTR* pstr)
{
	CComBSTR bstrtmp(version);
	if(!bstrtmp)
		return E_POINTER;
	else
	{
		*pstr=bstrtmp.Detach();
		return S_OK;
	}
}



/////////////////////////////////////////////////////////////////////////////
//
//

/*
*/
STDMETHODIMP CTCPClient::get_thread(long* pthread)
{
	DWORD tid=GetCurrentThreadId();
	*pthread=(long)tid;

	return S_OK;
}


/////////////////////////////////////////////////////////////////////////////
//
//

/*
*/
STDMETHODIMP CTCPClient::get_local(BSTR* pstr)
{
	HRESULT retval=S_OK;

	char tmp[MAX_URLEXPANSION+1];
	if(w)
	{
		char ip[MAX_IPEXPANSION+1];
		int port;
		w->localName(ip,port);
		_snprintf(tmp,MAX_URLEXPANSION,"%S:%d",ip,port);
	}
	else
		tmp[0]='\0';

	CComBSTR bstrtmp(tmp);
	if(!bstrtmp)
		retval=E_OUTOFMEMORY;
	else
		*pstr=bstrtmp.Detach();

	return retval;
}


/*
*/
STDMETHODIMP CTCPClient::get_remote(BSTR* pstr)
{
	HRESULT retval=S_OK;

	char tmp[MAX_URLEXPANSION+1];
	if(w)
	{
		char ip[MAX_IPEXPANSION+1];
		int port;
		w->peerName(ip,port);
		_snprintf(tmp,MAX_URLEXPANSION,"%S:%d",ip,port);
	}
	else
		tmp[0]='\0';

	CComBSTR bstrtmp(tmp);
	if(!bstrtmp)
		retval=E_OUTOFMEMORY;
	else
		*pstr=bstrtmp.Detach();

	return retval;
}


/////////////////////////////////////////////////////////////////////////////
//
//

/*
*/
STDMETHODIMP CTCPClient::get_is_completed(long* pstatus)
{
	if(w)
		*pstatus=(long)w->is_completed();
	else
		*pstatus=FALSE;
	return S_OK;
}


/*
*/
STDMETHODIMP CTCPClient::get_is_connected(long* pstatus)
{
	if(w)
		*pstatus=(long)w->is_connected();
	else
		*pstatus=FALSE;
	return S_OK;
}


/*
*/
STDMETHODIMP CTCPClient::get_is_cutoff(long* pstatus)
{
	if(w)
		*pstatus=(long)w->is_cutoff();
	else
		*pstatus=FALSE;
	return S_OK;
}


/*
*/
STDMETHODIMP CTCPClient::get_is_keepalives(long* pstatus)
{
	if(w)
		*pstatus=(long)w->is_keepalives();
	else
		*pstatus=FALSE;
	return S_OK;
}

/*
*/
STDMETHODIMP CTCPClient::get_is_nagledelay(long* pstatus)
{
	if(w)
		*pstatus=(long)w->is_nagledelay();
	else
		*pstatus=FALSE;
	return S_OK;
}



/////////////////////////////////////////////////////////////////////////////
//
//

/*
*/
STDMETHODIMP CTCPClient::get_socket(long* psock)
{
	if(w)
		*psock=(long)w->socket();
	else
		*psock=0L;
	return S_OK;
}



/*
*/
STDMETHODIMP CTCPClient::get_bytessent(long* pbytes)
{
	if(w)
		*pbytes=(long)w->bytes_sent();
	else
		*pbytes=0L;
	return S_OK;
}


/*
*/
STDMETHODIMP CTCPClient::get_bytesreceived(long* pbytes)
{
	if(w)
		*pbytes=(long)w->bytes_received();
	else
		*pbytes=0L;
	return S_OK;
}


/*
*/
STDMETHODIMP CTCPClient::get_byteslastreceived(long* pbytes)
{
	if(w)
		*pbytes=(long)w->last_bytes_received();
	else
		*pbytes=0L;
	return S_OK;
}


/*
*/
STDMETHODIMP CTCPClient::get_byteslastsent(long* pbytes)
{
	if(w)
		*pbytes=(long)w->last_bytes_sent();
	else
		*pbytes=0L;
	return S_OK;
}




/*
*/
STDMETHODIMP CTCPClient::get_stack_recv_buffer(long* pbytes)
{
	if(w)
		*pbytes=(long)w->stack_recv_buffer();
	else
		*pbytes=0L;
	return S_OK;
}


/*
*/
STDMETHODIMP CTCPClient::get_stack_send_buffer(long* pbytes)
{
	if(w)
		*pbytes=(long)w->stack_send_buffer();
	else
		*pbytes=0L;
	return S_OK;
}



/*
*/
STDMETHODIMP CTCPClient::get_send_packets(long* pcount)
{
	if(w)
		*pcount=(long)w->send_packets();
	else
		*pcount=0L;
	return S_OK;
}

/*
*/
STDMETHODIMP CTCPClient::get_recv_packets(long* pcount)
{
	if(w)
		*pcount=(long)w->recv_packets();
	else
		*pcount=0L;
	return S_OK;
}

/*
*/
STDMETHODIMP CTCPClient::get_recv_faults(long* pcount)
{
	if(w)
		*pcount=(long)w->recv_faults();
	else
		*pcount=0L;
	return S_OK;
}

/*
*/
STDMETHODIMP CTCPClient::get_recvbuffer_faults(long* pcount)
{
	if(w)
		*pcount=(long)w->recvbuffer_faults();
	else
		*pcount=0L;
	return S_OK;
}



/////////////////////////////////////////////////////////////////////////////
//
//

/*
*/
STDMETHODIMP CTCPClient::get_kbpssent(double* pkbps)
{
	if(w)
		*pkbps=(double)w->kbps_sent();
	else
		*pkbps=0.0;
	return S_OK;
}


/*
*/
STDMETHODIMP CTCPClient::get_kbpsreceived(double* pkbps)
{
	if(w)
		*pkbps=(double)w->kbps_received();
	else
		*pkbps=0.0;
	return S_OK;
}


/*
*/
STDMETHODIMP CTCPClient::get_kbpslastsent(double* pkbps)
{
	if(w)
		*pkbps=(double)w->last_kbps_sent();
	else
		*pkbps=0.0;
	return S_OK;
}


/*
*/
STDMETHODIMP CTCPClient::get_kbpslastreceived(double* pkbps)
{
	if(w)
		*pkbps=(double)w->last_kbps_received();
	else
		*pkbps=0.0;
	return S_OK;
}


/*
*/
STDMETHODIMP CTCPClient::get_ping(long* pVal)
{
	if(w)
		*pVal=(long)w->ping();
	else
		*pVal=0L;
	return S_OK;
}


/////////////////////////////////////////////////////////////////////////////
//
//

/*
*/
STDMETHODIMP CTCPClient::get_Log(BSTR* pstr)
{
	CComBSTR bstrtmp(log.Logs());
	if(!bstrtmp)
		return E_OUTOFMEMORY;
	else
	{
		*pstr=bstrtmp.Detach();
		return S_OK;
	}
}

/*
*/
STDMETHODIMP CTCPClient::ClearLog()
{
	//
	if(mutex.Try())
	{
		log.Clear();
	}

	return S_OK;
}

/*
*/
STDMETHODIMP CTCPClient::get_instance(long* pVal)
{
	*pVal=(long)m_instance;
	return S_OK;
}

/*
*/
STDMETHODIMP CTCPClient::get_instances(long* pVal)
{
	*pVal=(long)m_last_instance;
	return S_OK;
}

/*
*/
STDMETHODIMP CTCPClient::get_mutex_locks(long* pVal)
{
	*pVal=(long)mutex.get_lock_count();
	return S_OK;
}

/*
*/
STDMETHODIMP CTCPClient::get_mutex_sleep(long* pVal)
{
	*pVal=(long)mutex.get_sleep_milliseconds();
	return S_OK;
}








/////////////////////////////////////////////////////////////////////////////
//
//

/*
*/
STDMETHODIMP CTCPClient::SendFrame(
	BSTR strFrame,
	long FrameSize
	)
{
#ifdef _DEBUG
	CBSTR bstr_fns;
	printf("CTCPClient::SendFrame strFrame=%S FrameSize=%d (szlen strFrame=%d)\n",
		strFrame,FrameSize,bstr_fns.character_length(strFrame));
#endif

	//
	HRESULT retval=S_OK;

	//
	if(mutex.Try())
	{
		//
		if(!w)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CTCPClient::SendFrame",
				L"Socket not open.");
		}
		else
		{
			if(strFrame!=NULL)
			{
				CBSTR bstr;
				int const strFrame_length=bstr.character_length(strFrame);
				int const frame_length=(FrameSize<strFrame_length)?FrameSize:strFrame_length;
#ifdef _DEBUG
				printf("strFrame_length=%d\n",strFrame_length);
#endif
				w->Send((char *)strFrame,frame_length);
			}
			else
				retval=E_POINTER;
		}
		//
		mutex.Untry();
	}

	return retval;
}

/*
*/
STDMETHODIMP CTCPClient::RecvFrame(
	long FrameSize,
	BSTR* pstrFrame
	)
{
	//
	HRESULT retval=S_OK;

	//
	if(mutex.Try())
	{
		//
		if(!w)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CTCPClient::RecvFrame",
				L"Socket not open.");
			*pstrFrame=SysAllocString(L"");
		}
		else
		{
			char *buf=NULL;
			int const buf_length=w->RecvFrame(buf,FrameSize);
			if(buf_length<=0)
				*pstrFrame=SysAllocString(L"");
			else
			{
				BSTR bstr=new wchar_t[buf_length+1];
				if(bstr)
				{
					const size_t w_buf_length=mbstowcs(bstr,buf,buf_length+1);
					*pstrFrame=SysAllocStringLen(bstr,(unsigned int)w_buf_length);
					delete[] bstr;
					bstr=NULL;
				}
				else
				{
					log.AddLog(
						_T(__FILE__),
						__LINE__,
						L"CTCPClient::RecvFrame",
						L"Memory allocation failure (%d bytes).",
						buf_length);

					retval=E_OUTOFMEMORY;
				}
			}

			delete[] buf;
			buf=NULL;
		}
		//
		mutex.Untry();
	}
	else
		*pstrFrame=SysAllocString(L"");

	return retval;
}





/*
*/
// 8 16 24 32 40 48 56 64
_int64 CTCPClient::changeEndian(
	_int64 d,
	short bits
	)
{
	if((bits&7)==0)
	{
		int const bytes=(int)(bits>>3);
		BYTE b[8];
		int i;
		BYTE *p=(BYTE *)&d;
		for(i=0;i<bytes;i++)
		{
			b[i]=*(p+bytes-i-1);
		}
		for(;i<8;i++)
		{
			b[i]=0;
		}
		return *(_int64 *)b;
	}
	else
	{
		return d;
	}
}




/*
*/
STDMETHODIMP CTCPClient::FrameSize(
	BSTR strFrameDefinition,
	long* pFrameSize
	)
{
	//
	if(strFrameDefinition==NULL)
	{
		if(pFrameSize==NULL)
			return S_OK;
		else
		{
			*pFrameSize=0;
			return S_OK;
		}
	}

	//
	CBSTR bstr;
	const int length=bstr.sz_length(strFrameDefinition);
	wchar_t *p=strFrameDefinition;
	wchar_t *pend=strFrameDefinition+length;

	long sum=0;
	if(strFrameDefinition!=NULL)
	{
		while(p<pend)
		{
			wchar_t *next;

			wchar_t c=*p++;
			int num=_wtoi(p);
			next=wcschr(p,' ');
			if(next==NULL) break;

			p=next+1;

			next=wcschr(p,',');
			if(next==NULL) p=pend; else p=next+1;

			switch(c)
			{
			case '+':
				sum+=num;
				break;
			case 's':
				sum+=8*num;
				break;
			case 'u':
				sum+=16*num;
				break;
			case ' ':
			case '-':
				sum+=num;
				break;
			default:
				p=pend;
			}
		}
	}

	//
	*pFrameSize=(long)sum;

	return S_OK;
}



/*
*/
STDMETHODIMP CTCPClient::DecodeFrame(
	BSTR strFrameDefinition,
	BSTR strFieldName,
	BSTR strFrame,
	BSTR* pstrValue
	)
{
	//
	if(strFrameDefinition==NULL || strFrame==NULL || strFieldName==NULL || pstrValue==NULL)
	{
		if(pstrValue==NULL)
			return S_OK;
		else
		{
			*pstrValue=SysAllocString(L"");
			return S_OK;
		}
	}

	//
	CBSTR bstr;
	int const length=bstr.sz_length(strFrameDefinition);
	wchar_t *p=strFrameDefinition;
	wchar_t *pend=strFrameDefinition+length;

	//
	long sum=0;
	while(p<pend)
	{
		wchar_t *next;

		wchar_t c=*p++;
		int num=_wtoi(p);
		next=wcschr(p,' ');
		if(next==NULL) break;

		p=next+1;

		wchar_t *fieldname=p;

		next=wcschr(p,',');
		int fieldname_length;
		if(next==NULL)
		{
			p=pend;
			fieldname_length=(int)(p-fieldname);
		}
		else
		{
			p=next+1;
			fieldname_length=(int)(p-fieldname-1);
		}

		if(wcsncmp(strFieldName,fieldname,fieldname_length)==0)
		{
			const int byte_offset=(sum>>3);
			const bool aligned=((sum&7)==0);
			const int shift=sum&7;
			const int index=(num-1)&63;

			BYTE *source=(BYTE *)strFrame;
			_int64 dd;
			_int64 d;
			wchar_t wbuffer[22];

			switch(c)
			{
			case ' ':
			case '-':
				dd=*(_int64 *)(source+byte_offset);
				d=(_int64)((dd>>shift)&bitmask[index]);
				_i64tow(d,wbuffer,10);
				*pstrValue=SysAllocString(wbuffer);
				return S_OK;
			case '+':
				dd=*(_int64 *)(source+byte_offset);
				d=(_int64)((dd>>shift)&bitmask[index]);
				d=changeEndian(d,num);
				_i64tow(d,wbuffer,10);
				*pstrValue=SysAllocString(wbuffer);
				return S_OK;
			case 's':
				{
					wchar_t *tmp=new wchar_t[num+1];
					if(tmp)
					{
						const size_t wlength=mbstowcs(tmp,(const char *)(source+byte_offset),num);
						*(tmp+num)=L'\0';
						*pstrValue=SysAllocString(tmp);
						delete[] tmp;
					}
				}
				return S_OK;
			case 'u':
				{
					wchar_t *tmp=new wchar_t[num+1];
					if(tmp)
					{
						wcsncpy(tmp,(const wchar_t*)(source+byte_offset),num);
						*(tmp+num)=L'\0';
						*pstrValue=SysAllocString(tmp);
						delete[] tmp;
					}
				}
				return S_OK;
			default:
				*pstrValue=SysAllocString(L"");
				return S_OK;
			}
			break;
		}

		switch(c)
		{
		case '+':
			sum+=num;
			break;
		case 's':
			sum+=8*num;
			break;
		case 'u':
			sum+=16*num;
			break;
		case ' ':
		case '-':
			sum+=num;
			break;
		default:
			p=pend;
		}
	}

	//
	if(pstrValue) *pstrValue=SysAllocString(L"");

	return S_OK;
}



/*
*/
STDMETHODIMP CTCPClient::EncodeFrame(
	BSTR strFrameDefinition,
	BSTR strFieldName,
	BSTR strFieldValue,
	BSTR strFrame,
	BSTR* pstrFrame
	)
{
	//
	if(strFrameDefinition==NULL || strFieldName==NULL || strFieldValue==NULL || strFrame==NULL || pstrFrame==NULL)
	{
		if(pstrFrame==NULL)
			return S_OK;
		else
		{
			*pstrFrame=SysAllocString(L"");
			return S_OK;
		}
	}

	//
	CBSTR bstr;
	const int length=bstr.sz_length(strFrameDefinition);
	wchar_t *p=strFrameDefinition;
	wchar_t *pend=strFrameDefinition+length;

	//
	long framesize;
	FrameSize(strFrameDefinition,&framesize);
	const int framebytes=(framesize>>3)+(((framesize&7)==0)?0:1);
	BYTE *Frame=new BYTE[framebytes+2+sizeof(_int64)];
	if(Frame==NULL)
	{
		//memory allocation error
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"CTCPClient::EncodeFrame",
			L"Memory allocation failure (%d bytes)",framebytes+2+sizeof(_int64));

		return E_OUTOFMEMORY;
	}
	else
	{
		//
		memset(Frame,0,framebytes+2+sizeof(_int64));

		//
		CBSTR bstr;
		const int strFrame_bytes=bstr.bytes(strFrame);
		if(strFrame) memcpy(Frame,strFrame,(strFrame_bytes<=framebytes)?strFrame_bytes:framebytes);

		//
		long sum=0;
		while(p<pend)
		{
			wchar_t *next;

			wchar_t c=*p++;
			int num=_wtoi(p);
			next=wcschr(p,' ');
			if(next==NULL) break;

			p=next+1;

			wchar_t *fieldname=p;

			next=wcschr(p,',');
			int fieldname_length;
			if(next==NULL)
			{
				p=pend;
				fieldname_length=(int)(p-fieldname);
			}
			else
			{
				p=next+1;
				fieldname_length=(int)(p-fieldname-1);
			}

			//
			if(wcsncmp(strFieldName,fieldname,fieldname_length)==0)
			{
				const int byte_offset=(sum>>3);
				const bool aligned=((sum&7)==0);
				const int shift=sum&7;
				const int index=(num-1)&63;

				BYTE *destination=(BYTE *)Frame;
				_int64 dd;
				_int64 dd_stream;
				_int64 d;
				_int64 inverse_bitmask;

				switch(c)
				{
				case ' ':
				case '-':
					d=_wtoi(strFieldValue);
					dd_stream=*(_int64 *)(destination+byte_offset);
					inverse_bitmask=~(bitmask[index]<<shift);
					dd=(dd_stream&inverse_bitmask)|(d<<shift);
					*(_int64 *)(destination+byte_offset)=dd;
					p=pend;
					break;
				case '+':
					d=changeEndian(_wtoi(strFieldValue),num);
					dd_stream=*(_int64 *)(destination+byte_offset);
					inverse_bitmask=~(bitmask[index]<<shift);
					dd=(dd_stream&inverse_bitmask)|(d<<shift);
					*(_int64 *)(destination+byte_offset)=dd;
					p=pend;
					break;
				case 's':
					{
						char *tmp=new char[num];
						if(tmp)
						{
							const size_t wlength=wcstombs(tmp,strFieldValue,num);
							memset((char*)(destination+byte_offset),0,num);
							strncpy((char*)(destination+byte_offset),tmp,num);
							delete[] tmp;
						}
						p=pend;
					}
					break;
				case 'u':
					memset((char*)(destination+byte_offset),0,num*2);
					wcsncpy((wchar_t *)(destination+byte_offset),strFieldValue,num);
					p=pend;
					break;
				}			
			}

			switch(c)
			{
			case '+':
				sum+=num;
				break;
			case 's':
				sum+=8*num;
				break;
			case 'u':
				sum+=16*num;
				break;
			case ' ':
			case '-':
				sum+=num;
				break;
			default:
				p=pend;
			}
		}

		if(pstrFrame) SysFreeString(*pstrFrame);
		*pstrFrame=::SysAllocStringByteLen((const char*)Frame,framebytes);

		delete[] Frame;
		Frame=NULL;
	}

	return S_OK;
}




/////////////////////////////////////////////////////////////////////////////
//
//

/*
*/
STDMETHODIMP CTCPClient::Hash(
	BSTR strHashType,
	BSTR strInput,
	BSTR* pstrHash
	)
{
	//
	HRESULT retval=S_OK;

	CMD5 md5;

	if(strInput!=NULL)
	{
		//
		const size_t strInput_length=wcslen(strInput)+1;
		char *szInput=new char[strInput_length];
		if(szInput==NULL)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CTCPClient::Hash",
				L"Memory allocation failure (%d bytes).",
				strInput_length);

			retval=E_OUTOFMEMORY;
		}
		else
		{
			//
			wcstombs(szInput,strInput,strInput_length);

			char md5hash[32+1];
			md5.Hash(szInput,md5hash);

			BSTR bstr=new wchar_t[32+1];
			if(bstr==NULL)
			{
				log.AddLog(
					_T(__FILE__),
					__LINE__,
					L"CTCPClient::Hash",
					L"Memory allocation failure (%d bytes).",32+1);

				retval=E_OUTOFMEMORY;
			}
			else
			{
				const size_t w_length=mbstowcs(bstr,md5hash,32+1);
				*pstrHash=SysAllocString(bstr);
				delete[] bstr;
			}

			delete[] szInput;
			szInput=NULL;
		}
	}

	return retval;
}



/*
*/
STDMETHODIMP CTCPClient::HashFile(
	BSTR strHashType,
	BSTR strFilename,
	BSTR *pstrHash
	)
{
	//
	HRESULT retval=S_OK;

	CMD5 md5;
	CBSTR bstr;

	//
	char szFilename[_MAX_PATH+1];
	const int strFilename_length=bstr.sz_length(strFilename);
	wcstombs(szFilename,strFilename,strFilename_length+1);

	//
	char hash[32+1];
	const int blocksize=65536;
	md5.HashFile(szFilename,hash,blocksize);

	wchar_t bstr_hash[32+1];
	mbstowcs(bstr_hash,hash,32+1);
	*pstrHash=SysAllocString(bstr_hash);

	//
	return retval;
}
