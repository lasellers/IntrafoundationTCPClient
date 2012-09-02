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
#include "..\tcpclientcom\Log.h"

main()
{
    printf("This is a tcp class debugging test harness.\n");
    printf("Tests HTTP protocol functions.\n");
    printf("-------------------------------------------\n");
	
    
	
	
	
	//	
    printf(" create index.txt? Y/N\n");
    int c=_getch();
    if(c=='Y' || c=='y')
    {
        int testfilesize=0;
		char* const wfilename="c:\\InetPub\\wwwroot\\tcpclientcom\\send\\index.txt";
        printf("\ncreating index.txt at %s...\n\n",wfilename);
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

						int numwrite=fwrite(line,1,strlen(line),h);
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
	printf("\n\n************** get / http/1.0\n\n ");
	printf("press any key\n"); _getch();
    w=new tcp("127.0.0.1","80");
    if(w)
    {
        //
        w->timeout(2,0);
        
        
		w->statistics();

		w->keepalives(true);
		w->nagledelay(true);
        w->statistics();

		w->keepalives(false);
		w->nagledelay(false);
        w->statistics();

		w->networks();

		delete w;
	}
	
    

    ///////////////////////////////////////////////////////////////////////
	printf("\n\n************** get / http/1.0\n\n ");
	printf("press any key\n"); _getch();
    w=new tcp("127.0.0.1","80");
    if(w)
    {
        //
        w->timeout(2,0);
        
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
	printf("\n\n************** GET /tcpclientcom/send/INDEX.txt HTTP/1.0\n\n ");
	printf("press any key\n"); _getch();
    w=new tcp("127.0.0.1","80");
    if(w)
    {
        //
        w->timeout(2,0);
        
        //
        w->SendCRLF("GET /tcpclientcom/send/INDEX.txt HTTP/1.0");
        w->SendCRLF(NULL,0);
        
        //
        char *r=NULL;
        w->Recv(r);
	//	if(r) printf("RECV:\n%s\n\n",r);
        
		w->statistics();
        delete w;
	}
	
    
	
	
    ///////////////////////////////////////////////////////////////////////
	printf("\n\n************** 1mb/1mb GET /tcpclientcom/send/INDEX.txt HTTP/1.0\n\n ");
	printf("press any key\n"); _getch();
    w=new tcp("127.0.0.1","80");
    if(w)
    {
		//
		w->packetsize(1048576);
		w->blocksize(1048576);

        //
        w->timeout(2,0);
        
        //
        char *s="GET /tcpclientcom/send/INDEX.txt HTTP/1.0";
        w->SendCRLF("GET /tcpclientcom/send/INDEX.txt HTTP/1.0");
        w->SendCRLF("");
        
        //
        char *r=NULL;
        w->Recv(r);
//		if(r) printf("RECV:\n%s\n\n",r);
        

		w->statistics();
        delete w;
	}
	

    ///////////////////////////////////////////////////////////////////////
	printf("\n\n************** 512/1mb GET /tcpclientcom/send/INDEX.txt HTTP/1.0\n\n ");
	printf("press any key\n"); _getch();
    w=new tcp("127.0.0.1","80");
    if(w)
    {
		//
		w->packetsize(512);
		w->blocksize(1048576);

        //
        w->timeout(2,0);
        
        //
        char *s="GET /tcpclientcom/send/INDEX.txt HTTP/1.0";
        w->SendCRLF("GET /tcpclientcom/send/INDEX.txt HTTP/1.0");
        w->SendCRLF("");
        
        //
        char *r=NULL;
        w->Recv(r);
//		if(r) printf("RECV:\n%s\n\n",r);
        

		w->statistics();
        delete w;
	}
	

    
    ///////////////////////////////////////////////////////////////////////
	printf("\n\n************** 512/512 GET /tcpclientcom/send/INDEX.txt HTTP/1.0\n\n ");
	printf("press any key\n"); _getch();
    w=new tcp("127.0.0.1","80");
    if(w)
    {
		//
		w->packetsize(512);
		w->blocksize(512);

        //
        w->timeout(2,0);
        
        //
        char *s="GET /tcpclientcom/send/INDEX.txt HTTP/1.0";
        w->SendCRLF("GET /tcpclientcom/send/INDEX.txt HTTP/1.0");
        w->SendCRLF("");
        
        //
        char *r=NULL;
        w->Recv(r);
//		if(r) printf("RECV:\n%s\n\n",r);
        
		w->statistics();
        delete w;
	}
    
    
	

	printf("press any key\n"); _getch();


    ///////////////////////////////////////////////////////////////////////
	printf("\n\n************** head / http/1.0\n\n ");
    w=new tcp("127.0.0.1","80");
    if(w)
    {
        //
        w->timeout(2,0);
        
        //
        int sendlength=0;
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
    w=new tcp("127.0.0.1","80");
    if(w)
    {
        //
        w->timeout(2,0);
        
        //
        int sendlength=0;
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
	printf("\n\n************** get / http/1.0\n\n ");
    w=new tcp("127.0.0.1","80");
    if(w)
    {
        //
        w->timeout(2,0);
        
        //
        int sendlength=0;
        char *s="GET /INDEX.TXT HTTP/1.0";
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
	printf("\n\n************** msdn.pe.kr get / http/1.1 (RECV)\n\n ");
    w=new tcp("msdn.pe.kr","80");
    if(w)
    {
        //
        w->timeout(10,0);
        
        //
        int sendlength=0;
        char *s="GET / HTTP/1.1\r\nHost: msdn.pe.kr\r\nUserAgent: Mozilla/4.0 (compatible; MSIE 5.01; Windows NT)\r\n\r\n";
        int slen=strlen(s);
        sendlength=w->Send(s,strlen(s));
        
        //
        int recvlength=0;
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
        w->timeout(10,0);
        
        //
        int sendlength=0;
        char *s="GET / HTTP/1.1\r\nHost: msdn.pe.kr\r\nUserAgent: Mozilla/4.0 (compatible; MSIE 5.01; Windows NT)\r\n\r\n";
        int slen=strlen(s);
        sendlength=w->Send(s,strlen(s));
        
        //
        int recvlength=0;
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
        w->timeout(10,0);
        
        //
        int sendlength=0;
        char *s="GET / HTTP/1.1\r\nHost: msdn.pe.kr\r\nUserAgent: Mozilla/4.0 (compatible; MSIE 5.01; Windows NT)\r\n\r\n";
        int slen=strlen(s);
        sendlength=w->Send(s,strlen(s));
        
        //
        int recvlength=0;
        char *r=NULL;
        
        recvlength=w->Recv(r);
		if(r) printf("RECV:\n%s\n\n",r);
        
		w->statistics();
        delete w;
    }
    
	
	//
    printf("\nfini.\n");
    return 0;
}
