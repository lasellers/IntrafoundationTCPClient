// harness_finger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// harness_whois.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "stdafx.h"

#include "windows.h"
#include "stdio.h"

// _open file handling
#include "io.h"
#include <fcntl.h>

//bstr
//#include <comdef.h>

// _stat
#include "sys\stat.h"

#include "string.h"

#include <time.h>

#include <conio.h>


#include "..\tcpclientcom\tcp.h"

main()
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
    printf("\nfini.\n");
    return 0;
}
