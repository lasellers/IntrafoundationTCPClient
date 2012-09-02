// harness_ftp.cpp : Defines the entry point for the console application.
//

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
    printf("Tests FTP protocol functions by creating a (10MB) test file and sending then receiving it against the local anonymous ftp server.\n");
    printf("-------------------------------------------\n");
	
    /*
	packetsize/blocksize = send / recv
512/512 = 
_send_
last bytes sent                  6
     bytes sent                  67
last bytes received              78
     bytes received              300
last milliseconds sending        0.196952
     milliseconds sending        1.751619
last milliseconds receiving      3139.930036
     milliseconds receiving      12377.866914
last time sending                235
     time sending                2090
last time receiving              3746508
     time receiving              14769048
last kbps sent                   29750.216090
     kbps sent                   37353.839900
last kbps recv                   24.259099
     kbps recv                   23.668759
ping                             30680 ms
send sleep                       0 ms
recv sleep                       120 ms
**TIMEDOUT**                     3.000000

_recv_


  */








	//
	const long packetsize=1048576; //32768;
	long blocksize=1048576*8; //512; //10*1048576; //262144;

	//
	int c;

    //
    long kb=0L;
    long testfilesize=0;

    char szhost[132]; //="127.0.0.1";
//    char* const szhost="192.168.0.1"; //Horace
//    char* const szhost="192.168.0.199"; //Sarah
//    char* const szhost="192.168.0.200"; //Horace
    //char* const szhost="192.168.0.68"; //Cynthia
    char* const szport="21";
	
	const int secs=3;

    bool use_tcp_file_functions=false;

	int filebytes=0;
    char filename[MAX_PATH];
    char sfilename[MAX_PATH];
    char rfilename[MAX_PATH];





//
    printf(" remote ftp test host? Y/N (defaults to localhost)\n");
    c=_getch();
    if(c=='Y' || c=='y')
		strcpy(szhost,"192.168.0.68");
	else
		strcpy(szhost,"127.0.0.1");
	printf(" host=%s port=%s\n",szhost,szport);






 


    //
	{
    printf(" test file size? 0=512 byte, 1=1MB, 2=10MB, 3=30MB, 7=700MB 4=4GB\n");
    c=_getch();
    switch(c)
	{
	case '0':
		filebytes=512;
		strcpy(filename,"512.txt");
		strcpy(sfilename,"c:\\InetPub\\wwwroot\\tcpclientcom\\send\\512.txt");
		strcpy(rfilename,"c:\\InetPub\\wwwroot\\tcpclientcom\\recv\\512.txt");
		break;
	case '1':
		filebytes=1000000;
		strcpy(filename,"1mb.txt");
		strcpy(sfilename,"c:\\InetPub\\wwwroot\\tcpclientcom\\send\\1mb.txt");
		strcpy(rfilename,"c:\\InetPub\\wwwroot\\tcpclientcom\\recv\\1mb.txt");
		break;
	case '2':
		filebytes=10000000;
		strcpy(filename,"10mb.txt");
		strcpy(sfilename,"c:\\InetPub\\wwwroot\\tcpclientcom\\send\\10mb.txt");
		strcpy(rfilename,"c:\\InetPub\\wwwroot\\tcpclientcom\\recv\\10mb.txt");
		break;
	case '3':
		filebytes=30000000;
		strcpy(filename,"30mb.txt");
		strcpy(sfilename,"c:\\InetPub\\wwwroot\\tcpclientcom\\send\\30mb.txt");
		strcpy(rfilename,"c:\\InetPub\\wwwroot\\tcpclientcom\\recv\\30mb.txt");
		break;
	case '7':
		filebytes=700000000;
		strcpy(filename,"700mb.txt");
		strcpy(sfilename,"c:\\InetPub\\wwwroot\\tcpclientcom\\send\\700mb.txt");
		strcpy(rfilename,"c:\\InetPub\\wwwroot\\tcpclientcom\\recv\\700mb.txt");
		break;
	case '4':
		filebytes=4000000000;
		strcpy(filename,"4gb.txt");
		strcpy(sfilename,"c:\\InetPub\\wwwroot\\tcpclientcom\\send\\4gb.txt");
		strcpy(rfilename,"c:\\InetPub\\wwwroot\\tcpclientcom\\recv\\4gb.txt");
		break;
	default:
		filebytes=10000000;
		strcpy(filename,"10mb.txt");
		strcpy(sfilename,"c:\\InetPub\\wwwroot\\tcpclientcom\\send\\10mb.txt");
		strcpy(rfilename,"c:\\InetPub\\wwwroot\\tcpclientcom\\recv\\10mb.txt");
		break;
	}
	}



   //
    printf(" create %s? Y/N\n",filename);
    c=_getch();
    if(c=='Y' || c=='y')
    {
        printf("\ncreating test file at %s...\n\n",sfilename);
        char* const line="0123456789012345678901234567890123456789012345678901234567890123456789ABCDEF\r\n";
        char* const finalline="--min+++\r\n";
        FILE *h=fopen(sfilename,"wb");
        if(h!=NULL)
        {
            const int times=filebytes/78;
			const int mb=1000000/78; //12820
            for(int n=0;n<times;n++)
            {
                int numwrite=fwrite(line,1,strlen(line),h);
                testfilesize+=numwrite;
				if((n%12820)==0) printf("#");
            }
            int numwrite=fwrite(finalline,1,strlen(finalline),h);
            testfilesize+=numwrite;
            fclose(h);
        }
        printf("\nDone. File is %d bytes in size.\n\n",testfilesize);
    }
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
    
    ////////////////////////////////////////////////////////////////////////







	//
    printf(" use tcp::sendfile/recvfile (instead of send/recv)? Y/N\n");
    c=_getch();
    if(c=='Y' || c=='y')
	{
		use_tcp_file_functions=true;
		printf(" using optimized file functions.\n");
	}
	else
	{
		use_tcp_file_functions=false;
		printf(" using unoptimized/old send/recv.\n");
	}



	
		    //
	{
    printf(" blocksize? 0=512 byte, 1=65536, 2=1MB, 2=8MB, 3=128MB\n");
    c=_getch();
    switch(c)
	{
	case '0': blocksize=512; break;
	case '1': blocksize=65536; break;
	case '2': blocksize=1048576; break;
	case '3': blocksize=8*1048576; break;
	case '4': blocksize=128*1048576; break;
	}
}

	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
    
    ////////////////////////////////////////////////////////////////////////

    



    

    ////////////////////////////////////////////////////////////////////////
    // put
    printf(" PUT %s to FTP server? Y/N\n",filename);
    c=_getch();
    if(c=='Y' || c=='y')
    {
        tcp *w=new tcp(szhost,szport);
        if(w)
        {
            if(w->isconnected())
            {
				//
				w->timeout(secs,0);
				
				//
				int sendlength=0;
				int recvlength=0;
				char *r=NULL;
				
				//
			w->RecvCRLF(r);
				
				//
				w->SendCRLF("USER anonymous");
				w->RecvCRLF(r);
				
				w->SendCRLF("PASS anonymous");
				w->RecvCRLF(r);
				
				//
				w->SendCRLF("TYPE A");
				w->RecvCRLF(r);
				
				w->SendCRLF("PASV");
				
				int dataport=20;
				do
				{
					recvlength=w->RecvCRLF(r);
					
					if(r && strncmp(r,"227",3)==0)
					{
						char *pl=strchr(r,'(');
						char *pr=strchr(r,')');
						if(pl)
						{
							char *m=pl;
							char *n=pl;
							int i=0;
							do
							{
								n=m;
								m=strchr(m+1,',');
								printf(" ;m=%s n=%s i=%d\n",m,n,i);
							} while(i++<4 && m!=NULL);
							if(m)
							{
								int o1=atoi(n+1); //5 
								int o2=atoi(m+1); //6
								printf("i=%d o1=%d o2=%d\n",i,o1,o2);
								dataport=o1*256+o2;
							}
						}
						break;
					}
				} while (recvlength>0);
				
				printf("*********dataport=%d\n",dataport);
				
				
				//
				char s3[80];
				sprintf(s3,"STOR %s",filename);
				sendlength=w->SendCRLF(s3,strlen(s3));
				
				
				
				
				printf("\n\n");     
				printf("----------------------\n");
				printf("|\n");
				
				char dp[32];
				sprintf(dp,"%d",dataport);
				tcp *t=new tcp(szhost,dp);
				if(t)
				{
					t->timeout(secs,0);
					
					t->packetsize(packetsize);
					t->blocksize(blocksize);

	
					
					if(use_tcp_file_functions)
						t->SendFile(sfilename);
					else
					////////////////////////////////////////////////
					{
					struct _stat statbuf;
					int result=_stat( sfilename, &statbuf);
					if( result == -1 )
					{
						printf("_stat error\n");
					}
					else
					{
						printf( " File size     : %ld\n", statbuf.st_size );
						printf( " Drive         : %c:\n", statbuf.st_dev + 'A' );
						printf( " Time modified : %s", ctime( &statbuf.st_atime ) );
						
						FILE *rh=fopen(sfilename,"rb");
						if(rh!=NULL)
						{
							long size=(long)statbuf.st_size;
							kb=size;
							
							char *tbuf=new char[size+1];
							if(tbuf)
							{
								printf("\n**** reading %d byte file from disk....\n\n",size);
							
							int numread=fread(tbuf,1,size,rh);
							
							printf("size=%ld\n",size);
							printf("numread=%d\n",numread);
							
							long sentbytes=t->Send(tbuf,size);
							
							delete tbuf;
							}
							
							fclose(rh);
						}
					}
					}
					////////////////////////////////////////////////
					
					t->statistics();
					delete t;
					t=NULL;
				}                         
				
				
				//
				w->RecvCRLF(r);
				
				w->SendCRLF("QUIT");
				w->RecvCRLF(r);
				
            }
				delete w;
        }
    }
    
    
    
    
    
    
    
    
    ////////////////////////////////////////////////////////////////////////
    // get
    printf(" GET %s to FTP server? Y/N\n",filename);
    c=_getch();
    if(c=='Y' || c=='y')
    {
        tcp *w=new tcp(szhost,szport);
        if(w)
        {
            if(w->isconnected())
            {
				//
				w->timeout(secs,0);
				
				//
				int sendlength=0;
				int recvlength=0;
				char *r=NULL;
				
				//
			w->RecvCRLF(r);
				
				//
				w->SendCRLF("USER anonymous");
				w->RecvCRLF(r);
				
				w->SendCRLF("PASS anonymous");
				w->RecvCRLF(r);
				
				//
				w->SendCRLF("TYPE A");
				w->RecvCRLF(r);
				
				w->SendCRLF("PASV");
				
				int dataport=20;
				do
				{
					recvlength=w->RecvCRLF(r);
					
					if(r && strncmp(r,"227",3)==0)
					{
						char *pl=strchr(r,'(');
						char *pr=strchr(r,')');
						if(pl)
						{
							char *m=pl;
							char *n=pl;
							int i=0;
							do
							{
								n=m;
								m=strchr(m+1,',');
								printf(" ;m=%s n=%s i=%d\n",m,n,i);
							} while(i++<4 && m!=NULL);
							if(m)
							{
								int o1=atoi(n+1); //5 
								int o2=atoi(m+1); //6
								printf("i=%d o1=%d o2=%d\n",i,o1,o2);
								dataport=o1*256+o2;
							}
						}
						break;
					}
				} while(recvlength>0);
				
				printf("************dataport=%d\n",dataport);
				
				
				//
				char s3[80];
				sprintf(s3,"RETR %s",filename);
				sendlength=w->SendCRLF(s3,strlen(s3));
				
				
				
				char dp[32];
				sprintf(dp,"%d",dataport);
				tcp *t=new tcp(szhost,dp);
				if(t)
				{
					t->timeout(secs,0);
					
					t->packetsize(packetsize);
					t->blocksize(1048576); //
					t->blocksize(blocksize);
			
					if(use_tcp_file_functions)
						t->RecvFile(rfilename,false);
					else
					////////////////////////////////////////////////
					{
					char *rbuf=NULL;
					
					long recvbytes=t->Recv(rbuf);
					if(rbuf)
					{
					FILE *rh=fopen(rfilename,"wb");
					if(rh!=NULL)
					{
						printf("\n**** writing %d byte file to disk....\n\n",recvbytes);

						int numwrite=fwrite(rbuf,1,recvbytes,rh);
						printf("numwrite=%d bytes\n",numwrite);
						fclose(rh);
					}
					}
					}
					////////////////////////////////////////////////

					
					t->statistics();
					delete t;
					t=NULL;
				}                         
				
				
				//
				w->RecvCRLF(r);
				
				w->SendCRLF("QUIT");
				w->RecvCRLF(r);
				
            }
				delete w;
        }
    }
    
    
	//  
    return 0;
}
