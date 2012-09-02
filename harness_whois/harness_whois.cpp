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
    printf("Tests WHOIS protocol functions.\n");
    printf("-------------------------------------------\n");
	
    
	
    ///////////////////////////////////////////////////////////////////////
	{
		// try to force a timeout across the internet just to see what happens...
		printf("\n");
		printf("///////////////////////////////////////////////////////////\n");
		printf("\n");
		tcp *w=new tcp("whois.networksolutions.com","whois");
		if(w)
		{
			//
			w->timeout(0,20);
			
			//
			w->SendCRLF("intrafoundation.com");
			
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
		tcp *w=new tcp("whois.networksolutions.com","whois");
		if(w)
		{
			//
			w->timeout(5,0);
			
			//
			w->SendCRLF("intrafoundation.com");
			
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
		tcp *w=new tcp("whois.networksolutions.com","whois");
		if(w)
		{
			//
			w->timeout(5,0);
			
			//
			w->SendCRLF("allaire.com");
			
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
		tcp *w=new tcp("whois.networksolutions.com","whois");
		if(w)
		{
			//
			w->timeout(5,0);
			
			//
			int sendlength=0;
			char *s="macromedia.com";
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
		tcp *w=new tcp("whois.networksolutions.com","whois");
		if(w)
		{
			//
			w->timeout(5,0);
			
			//
			int sendlength=0;
			char *s="houseoffusion.com";
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
		tcp *w=new tcp("whois.networksolutions.com","whois");
		if(w)
		{
			//
			w->timeout(5,0);
			
			//
			int sendlength=0;
			char *s="microsoft.com";
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
		tcp *w=new tcp("whois.networksolutions.com","whois");
		if(w)
		{
			//
			w->timeout(5,0);
			
			//
			int sendlength=0;
			char *s="idsoftware.com";
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
		tcp *w=new tcp("whois.networksolutions.com","whois");
		if(w)
		{
			//
			w->timeout(5,0);
			
			//
			int sendlength=0;
			char *s="cflib.org";
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
		tcp *w=new tcp("whois.networksolutions.com","whois");
		if(w)
		{
			//
			w->timeout(5,0);
			
			//
			int sendlength=0;
			char *s="gov.ru";
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
		tcp *w=new tcp("whois.nic.mil","whois");
		if(w)
		{
			//
			w->timeout(5,0);
			
			//
			int sendlength=0;
			char *s="usmc.mil";
			sendlength=w->SendCRLF(s,strlen(s));
			
			//
			int recvlength=0;
			char *r=NULL;
			recvlength=w->Recv(r);
			if(r) printf("RECV:\n%s\n\n",r);

			recvlength=w->Recv(r);
			if(r) printf("RECV:\n%s\n\n",r);
			
			delete w;
		}
	}
    
	
	//
    printf("\nfini.\n");
    return 0;
}
