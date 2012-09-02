/////////////////////////////////////////////////////////////////////////////
//
// Intrafoundation.Tcpclient.3
//
// Copyright 1999, 200, 2001, 2003, 2004 by Lewis A. Sellers (AKA Min)
// http://www.intrafoundation.com
// webmaster@intrafoundation.com
//
// Software Homepage: http://www.intrafoundation.com/tcpclient.asp
//
//
/////////////////////////////////////////////////////////////////////////////

// TCPClient.h: Definition of the CTCPClient class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TCPCLIENT_H__7C902352_0661_4166_A511_4F979858CC9F__INCLUDED_)
#define AFX_TCPCLIENT_H__7C902352_0661_4166_A511_4F979858CC9F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"		// main symbols

#include "Mutex.h"
#include "Log.h"
#include "BSTR.h"
#include "tcp.h"

/////////////////////////////////////////////////////////////////////////////
// CTCPClient

class CTCPClient : 
public IDispatchImpl<ITCPClient, &IID_ITCPClient, &LIBID_TCPCLIENTCOMLib>, 
public CComObjectRoot,
public CComCoClass<CTCPClient,&CLSID_TCPClient>
{
public:
	typedef unsigned char BYTE;
	typedef unsigned short WORD;
	typedef unsigned int DWORD;
	
	//	static const int TRUE;
	//	static const int FALSE;
	
public:
	CTCPClient();
	virtual ~CTCPClient();
	
	BEGIN_COM_MAP(CTCPClient)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(ITCPClient)
		END_COM_MAP()
		//DECLARE_NOT_AGGREGATABLE(CTCPClient) 
		// Remove the comment from the line above if you don't want your object to 
		// support aggregation. 
		
		DECLARE_REGISTRY_RESOURCEID(IDR_TCPClient)
		
		//
	STDMETHOD(get_thread)(long* pthread);
	STDMETHOD(get_version)(BSTR* pstr);
	STDMETHOD(get_copyright)(BSTR* pstr);
	STDMETHOD(get_description)(BSTR* pstr);
	STDMETHOD(get_instance)(long* pVal);
	STDMETHOD(get_instances)(long* pVal);
	STDMETHOD(get_Log)(BSTR* pVal);
	STDMETHODIMP ClearLog();

	//
	STDMETHOD(Open)(BSTR bstrhost, BSTR bstrport,long* pconnected);
	STDMETHOD(Close)();
	STDMETHOD(Send)(BSTR inText);
	STDMETHOD(Recv)(BSTR* poutText);
	STDMETHOD(SendFile)(BSTR strFilename);
	STDMETHOD(RecvFile)(BSTR strFilename);
	STDMETHOD(RecvFileAppend)(BSTR strFilename);
	STDMETHOD(SendRN)(BSTR inText);
	STDMETHOD(RecvRN)(BSTR* poutText);
	STDMETHOD(FlushRN)();
	STDMETHOD(SendCSV)(BSTR inText);
	STDMETHOD(RecvCSV)(BSTR* poutText);
	
	//
	STDMETHODIMP SendFrame(
		BSTR strFrame,
		long FrameSize
		);
	STDMETHODIMP RecvFrame(
		long FrameSize,
		BSTR* pstrFrame
		);
	STDMETHODIMP FrameSize(
		BSTR strFrameDefinition,
		long* pFrameSize
		);
	STDMETHODIMP EncodeFrame(
		BSTR strFrameDefinition,
		BSTR strFieldName,
		BSTR strFieldValue,
		BSTR strFrame,
		BSTR* pstrFrame
		);
	STDMETHODIMP DecodeFrame(
		BSTR strFrameDefinition,
		BSTR strFieldName,
		BSTR strFrame,
		BSTR* pstrValue
		);
	
	//
	STDMETHODIMP Hash(
		BSTR strHashType,
		BSTR strInput,
		BSTR* pstrHash
		);
	STDMETHODIMP HashFile(
		BSTR strHashType,
		BSTR strFilename,
		BSTR* pstrHash
		);
	
	//
	STDMETHOD(put_timeout)(double secs);
	STDMETHOD(put_cutoff)(long bytes);
	STDMETHOD(put_packetsize)(long bytes);
	STDMETHOD(put_blocksize)(long bytes);
	
	STDMETHOD(put_keepalives)(long flag);
	STDMETHOD(put_nagledelay)(long flag);
	
	STDMETHOD(get_timeout)(double* psecs);
	STDMETHOD(get_cutoff)(long* pstatus);
	STDMETHOD(get_blocksize)(long* pbytes);
	STDMETHOD(get_packetsize)(long* pbytes);
	
	STDMETHOD(get_last_timeout)(double* psecs);
	
	STDMETHOD(get_is_cutoff)(long* pstatus);
	STDMETHOD(get_is_connected)(long* pstatus);
	STDMETHOD(get_is_completed)(long* pstatus);
	STDMETHOD(get_is_keepalives)(long* pstatus);
	STDMETHOD(get_is_nagledelay)(long* pstatus);
	
	STDMETHOD(get_byteslastreceived)(long* pbytes);
	STDMETHOD(get_byteslastsent)(long* pbytes);
	STDMETHOD(get_bytesreceived)(long* pbytes);
	STDMETHOD(get_bytessent)(long* pbytes);
	STDMETHOD(get_remote)(BSTR *pstr);
	STDMETHOD(get_local)(BSTR* pstr);
	STDMETHOD(get_socket)(long* psock);
	STDMETHOD(get_stack_recv_buffer)(long* pbytes);
	STDMETHOD(get_stack_send_buffer)(long* pbytes);
	STDMETHOD(get_send_packets)(long* pcount);
	STDMETHOD(get_recv_packets)(long* pcount);
	STDMETHOD(get_recv_faults)(long* pcount);
	STDMETHOD(get_recvbuffer_faults)(long* pcount);
	STDMETHOD(get_kbpssent)(double* pkbps);
	STDMETHOD(get_kbpsreceived)(double* pkbps);
	STDMETHOD(get_kbpslastsent)(double* pkbps);
	STDMETHOD(get_kbpslastreceived)(double* pkbps);
	STDMETHOD(get_ping)(long* pVal);
	STDMETHOD(get_mutex_locks)(long* pVal);
	STDMETHOD(get_mutex_sleep)(long* pVal);
	
	//
	STDMETHOD(put_set_timeout)(double secs);
	STDMETHOD(put_set_cutoff)(long bytes);
	STDMETHOD(put_set_packetsize)(long bytes);
	STDMETHOD(put_set_blocksize)(long bytes);
	STDMETHOD(put_set_keepalives)(long flag);
	STDMETHOD(put_set_nagledelay)(long flag);

private:
	_int64 changeEndian(_int64 d, short bits);
	
private:
	tcp *w;
	
	CLog log;
	static CMutex mutex;
	
	static unsigned _int64 bitmask[64];
	
	int m_instance;
	static int m_last_instance;
	
	// ITCPClient
public:
};

#endif // !defined(AFX_TCPCLIENT_H__7C902352_0661_4166_A511_4F979858CC9F__INCLUDED_)
