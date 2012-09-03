// test_harness_email.cpp : Defines the entry point for the console application.
//

// C/C++ / Processor / Processor Definitions: _UNICODE;_CRT_SECURE_NO_WARNINGS;
// Linker / input: ws2_32.lib;


#include "stdafx.h"

//#include "windows.h"
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

#include "..\..\tcpclientcom\base64.h"
#include "..\..\tcpclientcom\uu.h"
#include "..\..\tcpclientcom\mime.h"
#include "..\..\tcpclientcom\tcp.h"

int _tmain(int argc, _TCHAR* argv[])
{
    printf("This is a tcp class debugging test harness.\n");
    printf("Tests SMTP and POP3 protocols.\n");
    printf("-------------------------------------------\n");
    
    const char *rfilename="\\inetPub\\wwwroot\\IntrafoundationTCPClient\\test_data\\tcpclient.png";
    const char *wfilename="\\inetPub\\wwwroot\\IntrafoundationTCPClient\\test_data\\uu.png";
    char* const szhost="127.0.0.1";
    char* const szport_smtp="25";
    char* const szport_pop="110";
    int c;
	int secs=1;
	int msecs=0;

    









    // 0a
    printf(" list messages? (Y/N) RECV\n");
    c=_getch();
    if(c=='Y' || c=='y')
    {
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        
        
        ///////////////////////////////////////////////////////////////////////
        
        tcp *w=new tcp(szhost,szport_pop);
        if(w)
        {
            //
            int sendlength=0;
            int recvlength=0;
            char *r=NULL;

            //
            w->timeout(10,0);
            
            //
			w->Recv(r); if(r) printf("%s\n",r);
            
            w->SendCRLF("USER tcpclient");
			w->Recv(r); if(r) printf("%s\n",r);
			
            w->SendCRLF("PASS tcpclient");
			w->Recv(r); if(r) printf("%s\n",r);
            
			printf("\n####HELP\n");
            w->SendCRLF("HELP");
			w->Recv(r); if(r) printf("%s\n",r);
            
			printf("\n####LIST\n");
            w->SendCRLF("LIST");
			w->Recv(r); if(r) printf("%s\n",r);
            
            w->SendCRLF("QUIT");
			w->Recv(r); if(r) printf("%s\n",r);
            
            delete w;
            w=NULL;
        }
    }



    // 0b
    printf(" list messages? (Y/N) RECVRN\n");
    c=_getch();
    if(c=='Y' || c=='y')
    {
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        
        
        ///////////////////////////////////////////////////////////////////////
        
        tcp *w=new tcp(szhost,szport_pop);
        if(w)
        {
            //
            //int sendlength=0;
            //int recvlength=0;
            char *r=NULL;

            //
            w->timeout(10,0);
            
            //
			w->RecvCRLF(r); if(r) printf("%s\n",r);
            
            w->SendCRLF("USER tcpclient");
			w->RecvCRLF(r); if(r) printf("%s\n",r);
			
            w->SendCRLF("PASS tcpclient");
			w->RecvCRLF(r); if(r) printf("%s\n",r);
            
			printf("\n####HELP\n");
            w->SendCRLF("HELP");
			while(true)
			{
				w->RecvCRLF(r);
				if(r) printf("%s\n",r);
				if(r && strcmp((const char *)r,".")==0) break;
			}
            
			printf("\n####LIST\n");
            w->SendCRLF("LIST");
			while(true)
			{
				w->RecvCRLF(r);
				if(r) printf("%s\n",r);
				if(r && strcmp((const char *)r,".")==0) break;
			}
            
            w->SendCRLF("QUIT");
			w->RecvCRLF(r); if(r) printf("%s\n",r);
            
            delete w;
            w=NULL;
        }
    }



	
    // 1
    printf(" send u) uu m) mime base64 or N) for no\n");
    c=_getch();
    if(c=='m' || c=='M')
    {
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        
        
        ///////////////////////////////////////////////////////////////////////
        
        tcp *w=new tcp(szhost,szport_smtp);
        if(w)
        {
            //
            char *r=NULL;
            
            //
            w->timeout(5,0);

            w->RecvCRLF(r);
            
            //
            w->timeout(1,0);
            
            w->SendCRLF("HELO");
            w->RecvCRLF(r);
            
            w->SendCRLF("MAIL FROM: tcpclient@localhost");
            w->RecvCRLF(r);
            
            w->SendCRLF("RCPT TO: tcpclient@localhost");
            w->RecvCRLF(r);
            
            w->SendCRLF("DATA");
            w->RecvCRLF(r);
            
			CMIME mime;
			char *boundry=NULL;
			mime.boundry(boundry);
			char tmp[1024];
			


            w->SendCRLF("X-Mailer: TCPClient3, Intrafoundation Software");
            w->SendCRLF("X-Sender: tcpclient@localhost");
            w->SendCRLF("From: Intrafoundation Software");
            w->SendCRLF("Subject: This an encoding test using MIME base-64");
            w->SendCRLF("Mime-Version: 1.0");
            sprintf(tmp,"Content-Type: multipart/mixed; boundary=%s",boundry);
			w->SendCRLF(tmp);
			w->SendCRLF("");
			
			w->SendCRLF(boundry);
			w->SendCRLF("Content-Type: text/plain; charset=\"us-ascii\"");
			w->SendCRLF("");
			w->SendCRLF("This is a test. An attachment called tcpclient.png should be listed.");
			w->SendCRLF("");
			w->SendCRLF("");
			
			w->SendCRLF(boundry);
			w->SendCRLF("Content-Type: application/octet-stream; name=\"tcpclient.png\"");
			w->SendCRLF("Content-Transfer-Encoding: base64");
			w->SendCRLF("Content-Disposition: attachment; filename=\"base64.png\"");
            w->SendCRLF("");

            char rbuf[264144];
            
            struct _stat statbuf;
            int result=_stat( rfilename, &statbuf);
            if( result == -1 )
            {
                printf("_stat error\n");
            }
            else
            {
                printf( "File size     : %ld\n", statbuf.st_size );
                printf( "Drive         : %c:\n", statbuf.st_dev + 'A' );
                printf( "Time modified : %s", ctime( &statbuf.st_atime ) );
                
                FILE *rh=fopen(rfilename,"rb");
                if(rh!=NULL)
                {
                    long size=(long)statbuf.st_size;
                    int numread=fread(rbuf,1,size,rh);
                    
                    printf("size=%ld\n",size);
                    printf("numread=%d\n",numread);
                    
                    CBase64 base64;
                    int bytes=0;
                    char *btbuf=NULL;
                    
                    bytes=base64.encode_binary(rbuf,numread,btbuf);
                    
                    printf("base64 encode bytes:%d\n",bytes);
                    if(bytes) 
                    {
                        printf("btbuf:\n%s\n",btbuf);
                        
                        w->Send(btbuf,bytes);
                    }
                    fclose(rh);
                }
            }
  
            w->SendCRLF("");
            w->SendCRLF("");
			w->SendCRLF(boundry);

			//
            w->SendCRLF(".");
            w->RecvCRLF(r);
            
			//
            w->SendCRLF("QUIT");
            w->RecvCRLF(r);
            
			//
            delete w;
            w=NULL;
        }
    }
    else if(c=='u' || c=='U')
    {
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        
        
        ///////////////////////////////////////////////////////////////////////
        tcp *w=new tcp(szhost,szport_smtp);
        if(w)
        {
            //
            w->timeout(5,0);
            
            //
            int sendlength=0;
            int recvlength=0;
            char *r=NULL;
            
            //
            recvlength=w->RecvCRLF(r);
            
            //
            printf("\n");
            sendlength=w->SendCRLF("HELO");
            
            recvlength=w->RecvCRLF(r);
            
            sendlength=w->SendCRLF("MAIL FROM: tcpclient@localhost");
            recvlength=w->RecvCRLF(r);
			
            sendlength=w->SendCRLF("RCPT TO: tcpclient@localhost");
            recvlength=w->RecvCRLF(r);
            
            sendlength=w->SendCRLF("DATA");
            recvlength=w->RecvCRLF(r);
            
            sendlength=w->SendCRLF("This is a test.");

            sendlength=w->SendCRLF("begin 600 uu.png");
            
            char rbuf[264144];
            
            struct _stat statbuf;
            int result=_stat( rfilename, &statbuf);
            if( result == -1 )
            {
                printf("_stat error\n");
            }
            else
            {
                printf( "File size     : %ld\n", statbuf.st_size );
                printf( "Drive         : %c:\n", statbuf.st_dev + 'A' );
                printf( "Time modified : %s", ctime( &statbuf.st_atime ) );
                
                FILE *rh=fopen(rfilename,"rb");
                if(rh!=NULL)
                {
                    long size=(long)statbuf.st_size;
                    int numread=fread(rbuf,1,size,rh);
                    
                    printf("size=%ld\n",size);
                    printf("numread=%d\n",numread);
                    
                    CUU uu;
                    int bytes=0;
                    char *btbuf=NULL;
                    
                    bytes=uu.encode_binary(rbuf,numread,btbuf);
                    
                    printf("uuencode bytes:%d\n",bytes);
                    if(bytes) 
                    {
                        printf("btbuf:\n%s\n",btbuf);
                        
                        sendlength=w->Send(btbuf,bytes);
                    }
                    fclose(rh);
                }
            }
            
            sendlength=w->SendCRLF("end");
            sendlength=w->SendCRLF(".");
            recvlength=w->RecvCRLF(r);
            
            sendlength=w->SendCRLF("QUIT");
            recvlength=w->RecvCRLF(r);
            
            delete w;
        }
    }
	
	
	
	
	
	
	
	
	
	
	
	
	
	
    
    
    // 2
    printf("\n");
    printf("==========================================\n");
    printf("==========================================\n");
    printf("==========================================\n");
    printf("\n");
    
    
    printf(" retr u) uu  m) mime base64 or N) for no\n");
    c=_getch();
    if(c=='m' || c=='M')
    {
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        
        
        ///////////////////////////////////////////////////////////////////////
        tcp *w=new tcp(szhost,szport_pop);
        if(w)
        {
            //
            w->timeout(5,0);
            
            //
            int sendlength=0;
            int recvlength=0;
            char *r=NULL;
            
            //
            recvlength=w->RecvCRLF(r);
            
            sendlength=w->SendCRLF("USER tcpclient");
            recvlength=w->RecvCRLF(r);
			
            sendlength=w->SendCRLF("PASS tcpclient");
            recvlength=w->RecvCRLF(r);
            
            sendlength=w->SendCRLF("RETR 1");
			
            char *buf=new char[262144];
			if(buf)
			{
				long buf_length=0L;
				memset(buf,0,sizeof(buf));
				int state=0;
				
				//
				int line=0;
				int blank=0;
				do
				{
					recvlength=w->RecvCRLF(r);
					
					//
					if(state==3 && recvlength==0)
						state=0;
					if(state==3)
					{
						memcpy((buf+buf_length),r,recvlength);
						buf_length+=recvlength;
						*(buf+buf_length+0)=13;
						*(buf+buf_length+1)=10;
						buf_length+=2;
						blank=1;
						if(r)
						{
							printf("+%4d %d %s\n",line,state,r);
							line++;
						}
					}
					if(state==2 && recvlength==0)
						state=3;
					if(r && _stricmp(r,"--=====================_977368803==_")==0)
						state=1;
					if(state==1 && r && _strnicmp(r,"Content-Type: application/octet-stream;",39)==0)
						state=2;
					
					if(blank==0)
					{
						printf(" %4d %d %s\n",line,state,r);
						line++;
					}
					blank=0;
					
					if(r && _stricmp(r,".")==0)
						break;
					
				} while( !w->iscompleted() && w->last_timeout()==0.0);
				*(buf+buf_length)=0;
				
				printf("\nbuf_length:%d\n",buf_length);
				printf("buf:%s\n",buf);
				
				
				if(buf_length)
				{
					//
					CBase64 base64;
					int bytes=0;
					char *btbuf=NULL;
					
					bytes=base64.decode_binary(buf,buf_length,btbuf);
					
					printf("\nbytes:%d\n",bytes);
					printf("btbuf:%s\n",btbuf);
					
					FILE *h=fopen("\\inetPub\\wwwroot\\IntrafoundationTCPClient\\test_data\\base64.png","wb");
					if(h)
					{
						int numwrite=fwrite(btbuf,1,bytes,h);
						fclose(h);
					}
				}
				
				delete[] buf;
			}
            
            
            sendlength=w->SendCRLF("QUIT");
            recvlength=w->RecvCRLF(r);
            
            delete w;
        }
    }
    else if(c=='u' || c=='U')
    {
		///////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////
		
		
		///////////////////////////////////////////////////////////////////////
		tcp *w=new tcp(szhost,szport_pop);
		if(w)
		{
			//
			w->timeout(5,0);
			
			//
			int sendlength=0;
			int recvlength=0;
			char *r=NULL;
			
            //
            recvlength=w->RecvCRLF(r);
            
            sendlength=w->SendCRLF("USER tcpclient");
            recvlength=w->RecvCRLF(r);
			
            sendlength=w->SendCRLF("PASS tcpclient");
            recvlength=w->RecvCRLF(r);
            
            sendlength=w->SendCRLF("RETR 1");
			
			
			//
			char *buf=new char[262144];
			if(buf)
			{
				long buf_length=0L;
				memset(buf,0,sizeof(buf));
				int state=FALSE;
				
				//
				do
				{
					recvlength=w->RecvCRLF(r);
					
					if(r && _stricmp(r,".")==0)
						break;
					
					//
					if(state==TRUE)
					{
						memcpy((buf+buf_length),r,recvlength);
						buf_length+=recvlength;
						*(buf+buf_length+0)=13;
						*(buf+buf_length+1)=10;
						buf_length+=2;
					}
					if(r && _strnicmp(r,"begin ",6)==0)
						state=TRUE;
					if(r && _strnicmp(r,"end",3)==0)
						state=FALSE;
					
				} while( !w->iscompleted() && w->last_timeout()==0.0);
				*(buf+buf_length)=0;
				
				printf("\nbuf_length:%d\n",buf_length);
				printf("buf:%s\n",buf);
				
				//
				if(buf_length)
				{
					CUU uu;
					int bytes=0;
					char *btbuf=NULL;
					
					bytes=uu.decode_binary(buf,buf_length,btbuf);
					
					printf("\nbytes:%d\n",bytes);
					printf("btbuf:%s\n",btbuf);
					
					FILE *h=fopen(wfilename,"wb");
					if(h)
					{
						int numwrite=fwrite(btbuf,1,bytes,h);
						fclose(h);
					}
				}
				
				delete[] buf;
			}
			
			
			sendlength=w->SendCRLF("QUIT");
			recvlength=w->RecvCRLF(r);
			
			delete w;
		}
	}   
	
	
	
	
	
	// 3
	printf("\n");
	printf("==========================================\n");
	printf("==========================================\n");
	printf("==========================================\n");
	printf("\n");
	
	printf("DELE after y/n?\n");
	c=_getch();
	if(c=='y' || c=='Y')
	{
		///////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////
		
		
		///////////////////////////////////////////////////////////////////////
		tcp *w=new tcp("127.0.0.1","110");
		if(w)
		{
			//
			w->timeout(5,0);
			
			//
			int sendlength=0;
			int recvlength=0;
			char *r=NULL;
			
			//
			recvlength=w->RecvCRLF(r);
			
			sendlength=w->SendCRLF("USER tcpclient");
			recvlength=w->RecvCRLF(r);
			
			sendlength=w->SendCRLF("PASS tcpclient");
			recvlength=w->RecvCRLF(r);
			
			sendlength=w->SendCRLF("DELE 1");
			recvlength=w->RecvCRLF(r);
			
			sendlength=w->SendCRLF("QUIT");
			recvlength=w->RecvCRLF(r);
			
			delete w;
		}
	}
	
	
	return 0;
}

/*
// /nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"Debug/harness_http.pch" /Yu"stdafx.h" 

// /nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fo"Debug/" /Fd"Debug/" /FD /GZ /c 

// /nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"Debug/harness_email.pch" /Yu"stdafx.h" 
*/

