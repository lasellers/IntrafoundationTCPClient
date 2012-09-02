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

// tcp.h: interface for the tcp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(TCP_H)
#define TCP_H

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


/*
Required Libraries:
project/settings/object/link:
 ws2_32.lib netapi32.lib 
*/

//#include "windows.h"

// platform sdk ekliminates
//project/settings/object/link: ws2_32.lib 

#ifndef _WINSOCK2API_
#include "winsock2.h"
//#include "ws2spi.h"
#endif

// lib:  netapi32.lib 
#include "nb30.h"


// C:\Program Files\Microsoft SDK\Include
//
#include "stdio.h" //sprintf printf
#include "winbase.h" // sleep

//
#include "Log.h"

//
class tcp
{
public:
    static const int NAGLE_DELAY;
    static const char* crlfA;
    static const wchar_t* crlfW;
    static const int crlfA_LENGTH;
    static const int crlfW_LENGTH;
    
public:
    CLog log;
    
public:
    tcp();
    tcp(
        char* const host,
        char* const port
        );
    tcp(
        char* const host,
        char* const port,
		char* const ciphers
        );
    virtual ~tcp();

	void load_winsock();
	void unload_winsock();

	void reset();
    void open(
        char* const host,
        char* const port
        );
	void close();
    
    int Send(
        char* const sp,
        long const len
        );
    int SendF(
        char const* format,
        ...
        );
    
    int Recv(
        char* &recvp,
        bool bbreakonpause,
		bool ignorebuffer
        );
    int Recv(
        char* &recvp
        );
	int SendFile(
		const char* filename
		);
	int RecvFile(
		const char* filename,
		bool append
		);
    
    int socket();
    void localName(
        char* ip,
        int& port
        );
    void peerName(
        char* ip,
        int& port
        );
    int send_packets();
    int recv_packets();
    int recvbuffer_faults();
    int recv_faults();
	
	int stack_send_buffer();
	int stack_recv_buffer();
	
	bool is_keepalives();
	bool is_nagledelay();
    bool is_connected();
    bool is_completed();
    bool is_cutoff();
	
	void keepalives(bool flag);
	void nagledelay(bool flag);
	
    void timeout(
        int const new_secs,
        int const new_msecs
        );
    double timeout();
    double last_timeout();
    long cutoff();
    void cutoff(
        long bytes
        );
    void blocksize(
        long bytes
        );
    int blocksize();
    void packetsize(int bytes);
    int packetsize();
    
    DWORD ping();
    
    double kbps_sent();
    double kbps_received();
    double last_kbps_sent();
    double last_kbps_received();
    
    long bytes_sent();
    long bytes_received();
    long last_bytes_sent();
    long last_bytes_received();
    
    double milliseconds_sending();
    double milliseconds_receiving();
    double last_milliseconds_sending();
    double last_milliseconds_receiving();
    
    int instance();
    int instances();
    
    int recv_sleep();
    int send_sleep();
    
    void statistics();
    
private:
    SOCKET m_sock; //socket id
    
	char* m_stack_buffer; //[m_packetsize]
	
    int m_secs, m_msecs; //the timeout peroid. by default 0 seconds, 200 milliseconds
    bool m_connected; //boolean state of connection. 0=no connection. 1=connected
    bool m_completed; //
    long m_cutoff_bytes;
    double m_last_timeout;
    bool m_is_cutoff;
    
    int m_send_packets;
    int m_recv_packets;
    int m_recvbuffer_faults;
    int m_recv_faults;
    
    long m_last_bytes_sent;
    long m_last_bytes_received;
    long m_bytes_sent; //running count of total bytes sent
    long m_bytes_received; //running count of total bytes received
    int m_blocksize;
    int m_buffer_length;
    
    LARGE_INTEGER m_last_time_sending;
    LARGE_INTEGER m_last_time_receiving;
    LARGE_INTEGER m_time_sending;
    LARGE_INTEGER m_time_receiving;
    LARGE_INTEGER m_start_of_ping;
    LARGE_INTEGER m_ping;
    LARGE_INTEGER m_frequency;
    
    int m_packetsize;
    
    int m_instance;
    static int m_last_instance;
    
    int m_send_sleep;
    int m_recv_sleep;
    
public:
    int RecvCRLF(
        char* &recvp
        );
    int SendCRLF(
        char* const sp,
        long const length
        );
    int SendCRLF(
        char* const sp
        );
    int RecvFrame(
        char* &recvp,
        long const length
        );
    bool EmptyRecvBuffer();
    
private:
    char* m_recvbuffer;
    int m_recvbuffer_length;
    
public:
    bool is_secure();
    
private:
    bool m_securesocket;
};

#endif
