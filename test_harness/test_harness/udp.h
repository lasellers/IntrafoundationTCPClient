// udp.h: interface for the Winsock class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UDP_H)
#define UDP_H

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
//
#include "winsock2.h" //project/settings/object/link: ws2_32.lib 
//
#define EXTRA_PADDING		16
#define DWORD_EXPANSION 	32
#define MAX_DWORDEXPANSION	32
#define DWORD_BOOLEAN		2
#define MAX_ADDRESS 		(26+5+1)*4

//#define MAX_PACKET_SIZE 32768 //8192 //65536 //6144 //8192 //1536 //BUFSIZ
#define MAX_PACKET_SIZE 	65507

//
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

//
#include "Log.h"

//
class udp {
public:
	CLog log;

public:
	udp();
	udp(char* const host, char* const port);
	virtual ~udp();

	//
	void load_winsock();
	void unload_winsock();
	void reset();

	//
	long Send(char * const buffer);
	long Send(char * const sp, size_t const len);
	long Recv(char* &recvp);
	void timeout(int const secs, int const msecs);
	void get_timeout(int &secs, int &msecs);

	SOCKET udpsocket();
	int endpoints(char* &local_ip, int &local_port, char* &remote_ip,
			int &remote_port);
	void bytestransferred(size_t &this_bytes_sent, size_t &this_bytes_received);
	void bufferlengths(size_t &sendlength, size_t &recvlength,
			size_t &buffersize, size_t &messagelength);
	double kbps_sending();
	double kbps_receiving();
	bool is_connected();
	DWORD ping();

	int instance();
	int instances();

	void statistics();

	size_t send_packets();
	size_t recv_packets();

private:
	size_t m_bytes_sent; //running count of total bytes sent
	size_t m_bytes_received; //running count of total bytes received
	size_t m_msecs_sending;
	size_t m_msecs_receiving;

	size_t m_last_bytes_sent;
	size_t m_last_bytes_received;

	size_t m_send_packets;
	size_t m_recv_packets;

private:
	int m_instance;
	static int m_last_instance;

	SOCKET m_sock; //socket id
	bool m_connected;

	LARGE_INTEGER m_last_time_sending;
	LARGE_INTEGER m_last_time_receiving;
	LARGE_INTEGER m_time_sending;
	LARGE_INTEGER m_time_receiving;
	LARGE_INTEGER m_start_of_ping;
	LARGE_INTEGER m_ping;
	LARGE_INTEGER m_frequency;

	struct sockaddr_in m_socka; //socket in sockaddr_in binary format
	struct sockaddr_in m_locala; //local point
	int m_secs, m_msecs; //the timeout peroid. by default 0 seconds, 200 milliseconds
	double m_last_timeout;
	char m_localname[MAX_ADDRESS];
	int m_localport;
	char m_remotename[MAX_ADDRESS];
	int m_remoteport;

public:
	double kbps_sent(void);
	double last_kbps_sent(void);
	double kbps_received(void);
	double last_kbps_received(void);
	size_t bytes_sent(void);

	double milliseconds_sending(void);
	double milliseconds_receiving(void);
	double last_milliseconds_sending(void);
	double last_milliseconds_receiving(void);
};

#endif
