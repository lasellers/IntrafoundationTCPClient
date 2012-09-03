// test_harness_http.cpp : Defines the entry point for the console application.
//

// C/C++ / Processor / Processor Definitions: _UNICODE;_CRT_SECURE_NO_WARNINGS;
// Linker / input: ws2_32.lib;

//
#include "stdafx.h"

// _open file handling
#include "io.h"
#include <fcntl.h>

//#include <comdef.h> //BSTR
#include "sys\stat.h" // _stat

//
#include "string.h"
#include <time.h>
#include <conio.h>

//
#include "..\..\tcpclientcom\Log.h"
#include "..\..\tcpclientcom\tcp.h"

int _tmain(int argc, _TCHAR* argv[])
{
#ifdef _WIN64
printf("64bit x64\n");
#else
printf("32bit x86\n");
#endif
	printf("This is a tcp class debugging test harness.\n");
	printf("Tests fetching external websites via HTTP protocol functions.\n");
	printf("It is best to output this to a text file for later study...\n");
	printf("-------------------------------------------\n");


	
	const int DEFAULT_TIMEOUT=10; //seconds



	//
	tcp *w=NULL;


	///////////////////////////////////////////////////////////////////////
	printf("\n\n************** www.intrafoundation.com get / http/1.1 (RECV)\n\n ");
	w=new tcp("www.intrafoundation.com","80");
	if(w)
	{
		//
		w->timeout(DEFAULT_TIMEOUT,0);

		//
		size_t sendlength=0;
		char *s="GET / HTTP/1.1\r\nHost: www.intrafoundation.com\r\nUserAgent: Mozilla/4.0 (compatible; MSIE 5.01; Windows NT)\r\n\r\n";
		size_t slen=strlen(s);
		sendlength=w->Send(s,strlen(s));

		//
		size_t recvlength=0;
		char *r=NULL;
		recvlength=w->Recv(r);
		if(r) printf("RECV:\n%s\n\n",r);

		w->statistics();
		delete w;
	}




	///////////////////////////////////////////////////////////////////////
	printf("\n\n************** www.adobe.com get / http/1.1 (RECV)\n\n ");
	w=new tcp("www.adobe.com","80");
	if(w)
	{
		//
		w->timeout(DEFAULT_TIMEOUT,0);

		//
		size_t sendlength=0;
		char *s="GET / HTTP/1.1\r\nHost: www.adobe.com\r\nUserAgent: Mozilla/4.0 (compatible; MSIE 5.01; Windows NT)\r\n\r\n";
		size_t slen=strlen(s);
		sendlength=w->Send(s,strlen(s));

		//
		size_t recvlength=0;
		char *r=NULL;
		recvlength=w->Recv(r);
		if(r) printf("RECV:\n%s\n\n",r);

		w->statistics();
		delete w;
	}




	///////////////////////////////////////////////////////////////////////
	printf("\n\n************** www.microsoft.com get / http/1.1 (RECV)\n\n ");
	w=new tcp("www.microsoft.com","80");
	if(w)
	{
		//
		w->timeout(DEFAULT_TIMEOUT,0);

		//
		size_t sendlength=0;
		char *s="GET / HTTP/1.1\r\nHost: www.microsoft.com\r\nUserAgent: Mozilla/4.0 (compatible; MSIE 5.01; Windows NT)\r\n\r\n";
		size_t slen=strlen(s);
		sendlength=w->Send(s,strlen(s));

		//
		size_t recvlength=0;
		char *r=NULL;
		recvlength=w->Recv(r);
		if(r) printf("RECV:\n%s\n\n",r);

		w->statistics();
		delete w;
	}


	///////////////////////////////////////////////////////////////////////
	printf("\n\n************** www.apple.com get / http/1.1 (RECV)\n\n ");
	w=new tcp("www.apple.com","80");
	if(w)
	{
		//
		w->timeout(DEFAULT_TIMEOUT,0);

		//
		size_t sendlength=0;
		char *s="GET / HTTP/1.1\r\nHost: www.apple.com\r\nUserAgent: Mozilla/4.0 (compatible; MSIE 5.01; Windows NT)\r\n\r\n";
		size_t slen=strlen(s);
		sendlength=w->Send(s,strlen(s));

		//
		size_t recvlength=0;
		char *r=NULL;
		recvlength=w->Recv(r);
		if(r) printf("RECV:\n%s\n\n",r);

		w->statistics();
		delete w;
	}




	///////////////////////////////////////////////////////////////////////
	printf("\n\n************** www.ibm.com get / http/1.1 (RECV)\n\n ");
	w=new tcp("www.ibm.com","80");
	if(w)
	{
		//
		w->timeout(DEFAULT_TIMEOUT,0);

		//
		size_t sendlength=0;
		char *s="GET / HTTP/1.1\r\nHost: www.ibm.com\r\nUserAgent: Mozilla/4.0 (compatible; MSIE 5.01; Windows NT)\r\n\r\n";
		size_t slen=strlen(s);
		sendlength=w->Send(s,strlen(s));

		//
		size_t recvlength=0;
		char *r=NULL;
		recvlength=w->Recv(r);
		if(r) printf("RECV:\n%s\n\n",r);

		w->statistics();
		delete w;
	}



	///////////////////////////////////////////////////////////////////////
	printf("\n\n************** github.com get / http/1.1 (RECV)\n\n ");
	w=new tcp("github.com","80");
	if(w)
	{
		//
		w->timeout(DEFAULT_TIMEOUT,0);

		//
		size_t sendlength=0;
		char *s="GET / HTTP/1.1\r\nHost: github.com\r\nUserAgent: Mozilla/4.0 (compatible; MSIE 5.01; Windows NT)\r\n\r\n";
		size_t slen=strlen(s);
		sendlength=w->Send(s,strlen(s));

		//
		size_t recvlength=0;
		char *r=NULL;
		recvlength=w->Recv(r);
		if(r) printf("RECV:\n%s\n\n",r);

		w->statistics();
		delete w;
	}



	///////////////////////////////////////////////////////////////////////
	printf("\n\n************** msdn.pe.kr get / http/1.1 (RECV)\n\n ");
	w=new tcp("msdn.pe.kr","80");
	if(w)
	{
		//
		w->timeout(DEFAULT_TIMEOUT,0);

		//
		size_t sendlength=0;
		char *s="GET / HTTP/1.1\r\nHost: msdn.pe.kr\r\nUserAgent: Mozilla/4.0 (compatible; MSIE 5.01; Windows NT)\r\n\r\n";
		size_t slen=strlen(s);
		sendlength=w->Send(s,strlen(s));

		//
		size_t recvlength=0;
		char *r=NULL;
		recvlength=w->Recv(r);
		if(r) printf("RECV:\n%s\n\n",r);

		w->statistics();
		delete w;
	}





	///////////////////////////////////////////////////////////////////////
	printf("\n\n************** msdn.pe.kr get / http/1.1 (3 RECVCRLF)\n\n ");
	w=new tcp("msdn.pe.kr","80");
	if(w)
	{
		//
		w->timeout(DEFAULT_TIMEOUT,0);

		//
		size_t sendlength=0;
		char *s="GET / HTTP/1.1\r\nHost: msdn.pe.kr\r\nUserAgent: Mozilla/4.0 (compatible; MSIE 5.01; Windows NT)\r\n\r\n";
		size_t slen=strlen(s);
		sendlength=w->Send(s,strlen(s));

		//
		size_t recvlength=0;
		char *r=NULL;

		recvlength=w->RecvCRLF(r);
		recvlength=w->RecvCRLF(r);
		recvlength=w->RecvCRLF(r);

		w->statistics();
		delete w;
	}




	///////////////////////////////////////////////////////////////////////
	printf("\n\n************** msdn.pe.kr get / http/1.1\n\n ");
	w=new tcp("msdn.pe.kr","80");
	if(w)
	{
		//
		w->timeout(DEFAULT_TIMEOUT,0);

		//
		size_t sendlength=0;
		char *s="GET / HTTP/1.1\r\nHost: msdn.pe.kr\r\nUserAgent: Mozilla/4.0 (compatible; MSIE 5.01; Windows NT)\r\n\r\n";
		size_t slen=strlen(s);
		sendlength=w->Send(s,strlen(s));

		//
		size_t recvlength=0;
		char *r=NULL;

		recvlength=w->Recv(r);
		if(r) printf("RECV:\n%s\n\n",r);

		w->statistics();
		delete w;
	}


	//
	printf("END OF TEST HARNESS\n");
//	printf("Press a key..."); _getch();
	return 0;
}

