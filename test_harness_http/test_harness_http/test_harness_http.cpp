// test_harness_http.cpp : Defines the entry point for the console application.
//

// C/C++ / Processor / Processor Definitions: _UNICODE;_CRT_SECURE_NO_WARNINGS;
// Linker / input: ws2_32.lib;

/
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
	printf("Tests HTTP protocol functions.\n");
	printf("It is best to output this to a text file for later study...\n");
	printf(" test_harness_http | y\n");
	printf("-------------------------------------------\n");


	const int DEFAULT_TIMEOUT=8; //seconds
	
	//	
	char* const wfilename="\\InetPub\\wwwroot\\IntrafoundationTCPClient\\test_data\\1mb.csv";
	FILE *ho=fopen(wfilename,"rb");
	if(ho!=NULL)
	{
		fclose(ho);
	}
	else
	{
		size_t testfilesize=0;
		printf("\ncreating 1mb.csv at %s...\n\n",wfilename);
		char* cszline="0123456789012345678901234567890123456789012345678901234567890123456789ABCDEF\r\n\0";
		char* line=new char[132];
		if(line)
		{
			strcpy(line,cszline);

			FILE *h=fopen(wfilename,"wb");
			if(h!=NULL)
			{
				for(int blocks=1;blocks<=999;blocks++)
				{
					for(int n=0;n<=99;n++)
					{
						char tmp[16];

						sprintf(tmp,"%2d",n);
						line[0]=tmp[0];
						line[1]=tmp[1];

						sprintf(tmp,"%3d",blocks);
						line[73]=tmp[0];
						line[74]=tmp[1];
						line[75]=tmp[2];

						size_t numwrite=fwrite(line,1,strlen(line),h);
						testfilesize+=numwrite;
						//printf("%s\n",line);
					}
					//	int numwrite=fwrite("\r\n",1,2,h);
					//	testfilesize+=numwrite;
				}
				fclose(h);
			}
		}
		printf("Done. bytes=%d\n\n",testfilesize);
	}






	//
	tcp *w=NULL;



	///////////////////////////////////////////////////////////////////////
	printf("\n\n************** open 127.0.0.1:80\n\n ");
	printf("press any key\n"); //_getch();
	w=new tcp("127.0.0.1","80");
	if(w)
	{
		//
		w->timeout(DEFAULT_TIMEOUT,0);

		w->statistics();

		w->keepalives(true);
		w->nagledelay(true);
		w->statistics();

		w->keepalives(false);
		w->nagledelay(false);
		w->statistics();

		//		w->networks();

		delete w;
	}



	///////////////////////////////////////////////////////////////////////
	printf("\n\n************** open 127.0.0.1:80, get / http/1.0\n\n ");
	printf("press any key\n"); //_getch();
	w=new tcp("127.0.0.1","80");
	if(w)
	{
		//
		w->timeout(DEFAULT_TIMEOUT,0);

		//
		w->SendCRLF("GET / HTTP/1.0");
		w->SendCRLF(NULL);

		//
		char *r=NULL;
		w->Recv(r);
		if(r) printf("RECV:\n%s\n\n",r);

		w->statistics();
		delete w;
	}





	///////////////////////////////////////////////////////////////////////
	printf("\n\n************** open 127.0.0.1:80, GET /IntrafoundationTCPClient/test_data/1mb.csv HTTP/1.0\n\n ");
	//printf("press any key\n"); //_getch();
	w=new tcp("127.0.0.1","80");
	if(w)
	{
		//
		w->timeout(DEFAULT_TIMEOUT,0);

		//
		w->SendCRLF("GET /IntrafoundationTCPClient/test_data/1mb.csv HTTP/1.0");
		w->SendCRLF(NULL,0);

		//
		char *r=NULL;
		w->Recv(r);
		//	if(r) printf("RECV:\n%s\n\n",r);

		w->statistics();
		delete w;
	}




	///////////////////////////////////////////////////////////////////////
	printf("\n\n************** packsize 1mb, blocksize 1mb, GET /IntrafoundationTCPClient/test_data/1mb.csv HTTP/1.0\n\n ");
	printf("press any key\n"); //_getch();
	w=new tcp("127.0.0.1","80");
	if(w)
	{
		//
		w->packetsize(1048576);
		w->blocksize(1048576);

		//
		w->timeout(DEFAULT_TIMEOUT,0);

		//
		char *s="GET /IntrafoundationTCPClient/test_data/1mb.csv HTTP/1.0";
		w->SendCRLF("GET /IntrafoundationTCPClient/test_data/1mb.csv HTTP/1.0");
		w->SendCRLF("");

		//
		char *r=NULL;
		w->Recv(r);
		//		if(r) printf("RECV:\n%s\n\n",r);


		w->statistics();
		delete w;
	}


	///////////////////////////////////////////////////////////////////////
	printf("\n\n************** packetsize=512, blocksize=1mb, GET /IntrafoundationTCPClient/test_data/1mb.csv HTTP/1.0\n\n ");
	printf("press any key\n"); //_getch();
	w=new tcp("127.0.0.1","80");
	if(w)
	{
		//
		w->packetsize(512);
		w->blocksize(1048576);

		//
		w->timeout(DEFAULT_TIMEOUT,0);

		//
		char *s="GET /IntrafoundationTCPClient/test_data/1mb.csv HTTP/1.0";
		w->SendCRLF("GET /IntrafoundationTCPClient/test_data/1mb.csv HTTP/1.0");
		w->SendCRLF("");

		//
		char *r=NULL;
		w->Recv(r);
		//		if(r) printf("RECV:\n%s\n\n",r);


		w->statistics();
		delete w;
	}



	///////////////////////////////////////////////////////////////////////
	printf("\n\n************** packetsize=512, blocksize=512, GET /IntrafoundationTCPClient/test_data/1mb.csv HTTP/1.0\n\n ");
	printf("press any key\n"); //_getch();
	w=new tcp("127.0.0.1","80");
	if(w)
	{
		//
		w->packetsize(512);
		w->blocksize(512);

		//
		w->timeout(DEFAULT_TIMEOUT,0);

		//
		char *s="GET /IntrafoundationTCPClient/test_data/1mb.csv HTTP/1.0";
		w->SendCRLF("GET /IntrafoundationTCPClient/test_data/1mb.csv HTTP/1.0");
		w->SendCRLF("");

		//
		char *r=NULL;
		w->Recv(r);
		//		if(r) printf("RECV:\n%s\n\n",r);

		w->statistics();
		delete w;
	}

	printf("press any key\n"); //_getch();


	///////////////////////////////////////////////////////////////////////
	printf("\n\n************** head /INDEX.HTML http/1.0\n\n ");
	w=new tcp("127.0.0.1","80");
	if(w)
	{
		//
		w->timeout(DEFAULT_TIMEOUT,0);

		//
		size_t sendlength=0;
		char *s="HEAD /INDEX.HTML HTTP/1.0";
		sendlength=w->SendCRLF(s,strlen(s));
		sendlength=w->SendCRLF(NULL,0);

		//
		int recvlength=0;
		char *r=NULL;
		recvlength=w->Recv(r);
		if(r) printf("RECV:\n%s\n\n",r);

		w->statistics();
		delete w;
	}





	///////////////////////////////////////////////////////////////////////
	printf("\n\n************** head / http/1.0\n\n ");
	printf("then 10 RecvCRLFs\n ");
	w=new tcp("127.0.0.1","80");
	if(w)
	{
		//
		w->timeout(DEFAULT_TIMEOUT,0);

		//
		size_t sendlength=0;
		char *s="HEAD /INDEX.HTML HTTP/1.0";
		sendlength=w->SendCRLF(s,strlen(s));
		sendlength=w->SendCRLF(NULL,0);

		//
		int recvlength=0;
		char *r=NULL;
		recvlength=w->RecvCRLF(r);
		recvlength=w->RecvCRLF(r);
		recvlength=w->RecvCRLF(r);
		recvlength=w->RecvCRLF(r);
		recvlength=w->RecvCRLF(r);
		recvlength=w->RecvCRLF(r);
		recvlength=w->RecvCRLF(r);
		recvlength=w->RecvCRLF(r);
		recvlength=w->RecvCRLF(r);
		recvlength=w->RecvCRLF(r);

		w->statistics();
		delete w;
	}




	///////////////////////////////////////////////////////////////////////
	printf("\n\n************** get /INDEX.TXT http/1.0\n\n ");
	w=new tcp("127.0.0.1","80");
	if(w)
	{
		//
		w->timeout(DEFAULT_TIMEOUT,0);

		//
		size_t sendlength=0;
		char *s="GET /INDEX.TXT HTTP/1.0";
		sendlength=w->SendCRLF(s,strlen(s));
		sendlength=w->SendCRLF(NULL,0);

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

