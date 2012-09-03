// test_harness_finger.cpp : Defines the entry point for the console application.
//

// C/C++ / Processor / Processor Definitions: _UNICODE;_CRT_SECURE_NO_WARNINGS;
// Linker / input: ws2_32.lib;

#include "stdafx.h"

// _open file handling
#include "io.h"
#include <fcntl.h>

// _stat
#include "sys\stat.h"

#include "string.h"

#include <time.h>

#include <conio.h>

//
#include "..\..\tcpclientcom\Log.h"
#include "..\..\tcpclientcom\tcp.h"

int _tmain(int argc, _TCHAR* argv[])
{
    printf("This is a tcp class debugging test harness.\n");
    printf("Tests FINGER protocol functions.\n");
    printf("-------------------------------------------\n");
	
    
    ///////////////////////////////////////////////////////////////////////
	{
		printf("\n");
		printf("///////////////////////////////////////////////////////////\n");
		printf("\n");
		tcp *w=new tcp("127.0.0.1","79");
		if(w)
		{
			//
			w->timeout(10,0);
			
			//
			w->SendCRLF("");
			
			//
			char *r=NULL;
			w->Recv(r);
			if(r) printf("RECV:\n%s\n\n",r);
			
			delete w;
		}
	}
    
	
    ///////////////////////////////////////////////////////////////////////
	{
		printf("\n");
		printf("///////////////////////////////////////////////////////////\n");
		printf("\n");
		tcp *w=new tcp("127.0.0.1","79");
		if(w)
		{
			//
			w->timeout(10,0);
			
			//
			w->SendCRLF("postmaster");
			
			//
			char *r=NULL;
			w->Recv(r);
			if(r) printf("RECV:\n%s\n\n",r);
			
			delete w;
		}
	}

    	
    ///////////////////////////////////////////////////////////////////////
	{
		printf("\n");
		printf("///////////////////////////////////////////////////////////\n");
		printf("\n");
		tcp *w=new tcp("127.0.0.1","79");
		if(w)
		{
			//
			w->timeout(10,0);
			
			//
			w->SendCRLF("tcpclient");
			
			//
			char *r=NULL;
			w->Recv(r);
			if(r) printf("RECV:\n%s\n\n",r);
			
			delete w;
		}
	}


	    ///////////////////////////////////////////////////////////////////////
	{
		printf("\n");
		printf("///////////////////////////////////////////////////////////\n");
		printf("\n");
		tcp *w=new tcp("finger.kernel.org","79");
		if(w)
		{
			//
			w->timeout(10,0);
			
			//
			int sendlength=0;
			char *s="finger";
			sendlength=w->SendCRLF(s,strlen(s));
			
			//
			int recvlength=0;
			char *r=NULL;
			recvlength=w->Recv(r);
			if(r) printf("RECV:\n%s\n\n",r);
			
			delete w;
		}
	}

	
    ///////////////////////////////////////////////////////////////////////
	{
		printf("\n");
		printf("///////////////////////////////////////////////////////////\n");
		printf("\n");
		tcp *w=new tcp("idsoftware.com","79");
		if(w)
		{
			//
			w->timeout(10,0);
			
			//
			int sendlength=0;
			char *s="";
			sendlength=w->SendCRLF(s,strlen(s));
			
			//
			int recvlength=0;
			char *r=NULL;
			recvlength=w->Recv(r);
			if(r) printf("RECV:\n%s\n\n",r);
			
			delete w;
		}
	}
    
	
    ///////////////////////////////////////////////////////////////////////
	{
		printf("\n");
		printf("///////////////////////////////////////////////////////////\n");
		printf("\n");
		tcp *w=new tcp("idsoftware.com","79");
		if(w)
		{
			//
			w->timeout(10,0);
			
			//
			int sendlength=0;
			char *s="johnc";
			sendlength=w->SendCRLF(s,strlen(s));
			
			//
			int recvlength=0;
			char *r=NULL;
			recvlength=w->Recv(r);
			if(r) printf("RECV:\n%s\n\n",r);
			
			delete w;
		}
	}
    
    
    ///////////////////////////////////////////////////////////////////////
	{
		printf("\n");
		printf("///////////////////////////////////////////////////////////\n");
		printf("\n");
		tcp *w=new tcp("idsoftware.com","79");
		if(w)
		{
			//
			w->timeout(10,0);
			
			//
			int sendlength=0;
			char *s="adrianc";
			sendlength=w->SendCRLF(s,strlen(s));
			
			//
			int recvlength=0;
			char *r=NULL;
			recvlength=w->Recv(r);
			if(r) printf("RECV:\n%s\n\n",r);
			
			delete w;
		}
	}

    
	    ///////////////////////////////////////////////////////////////////////
	{
		printf("\n");
		printf("///////////////////////////////////////////////////////////\n");
		printf("\n");
		tcp *w=new tcp("idsoftware.com","79");
		if(w)
		{
			//
			w->timeout(10,0);
			
			//
			int sendlength=0;
			char *s="donnaj";
			sendlength=w->SendCRLF(s,strlen(s));
			
			//
			int recvlength=0;
			char *r=NULL;
			recvlength=w->Recv(r);
			if(r) printf("RECV:\n%s\n\n",r);
			
			delete w;
		}
	}
    
    

	
    
	    ///////////////////////////////////////////////////////////////////////
	{
		printf("\n");
		printf("///////////////////////////////////////////////////////////\n");
		printf("\n");
		tcp *w=new tcp("idsoftware.com","79");
		if(w)
		{
			//
			w->timeout(10,0);
			
			//
			int sendlength=0;
			char *s="kevinc";
			sendlength=w->SendCRLF(s,strlen(s));
			
			//
			int recvlength=0;
			char *r=NULL;
			recvlength=w->Recv(r);
			if(r) printf("RECV:\n%s\n\n",r);
			
			delete w;
		}
	}
    

    
	
	
    
	    ///////////////////////////////////////////////////////////////////////
	{
		printf("\n");
		printf("///////////////////////////////////////////////////////////\n");
		printf("\n");
		tcp *w=new tcp("legendent.com","79");
		if(w)
		{
			//
			w->timeout(10,0);
			
			//
			int sendlength=0;
			char *s="kevinc";
			sendlength=w->SendCRLF(s,strlen(s));
			
			//
			int recvlength=0;
			char *r=NULL;
			recvlength=w->Recv(r);
			if(r) printf("RECV:\n%s\n\n",r);
			
			delete w;
		}
	}
    

	
	
    
	    ///////////////////////////////////////////////////////////////////////
	{
		printf("\n");
		printf("///////////////////////////////////////////////////////////\n");
		printf("\n");
		tcp *w=new tcp("ravensoft.com","79");
		if(w)
		{
			//
			w->timeout(10,0);
			
			//
			int sendlength=0;
			char *s="kevinc";
			sendlength=w->SendCRLF(s,strlen(s));
			
			//
			int recvlength=0;
			char *r=NULL;
			recvlength=w->Recv(r);
			if(r) printf("RECV:\n%s\n\n",r);
			
			delete w;
		}
	}
    

    
	//
	printf("END OF TEST HARNESS\n");
//	printf("Press a key..."); _getch();
	return 0;
}

