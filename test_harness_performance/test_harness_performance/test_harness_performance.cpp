// test_harness_performance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

/*
// harness_performance.cpp : Defines the entry point for the console application.
//

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



#include "..\tcpclientcom\tcp.h"
#include "..\tcpclientcom\Log.h"

main()
{
    
    printf("This is a tcp class debugging test harness.\n");
    printf("Finds packetsize performance sweet-spot via FTP transfers.\n");
    printf("-------------------------------------------\n");
    
	
	char* const szhost="127.0.0.1";
	//    char* const szhost="192.168.0.1"; //Horace
	//    char* const szhost="192.168.0.41"; //Sarah
	//  char* const szhost="192.168.0.40"; //Cynthia
    char* const szport="21";
    const int secs=3;
	
    //
    const int testfile_length=1048576;
    char *testfile=new char[testfile_length];
    memset(testfile,'X',testfile_length);
    
    
	
    //
    struct
    {
        int packetsize;
		long bytes_sent;
		long bytes_recv;
        double kbps_sent;
        double kbps_recv;
    } stat[1000];
    int index=0;
	
	int packetsize_data[]={512,1536,8*1536,16*1536,16384,32768,65535,2*65536,4*65536,8*65536,16*65536};
	//	int packetsize_data[]={8*65536,4*65536,2*65536,65535,32768,16*1536,8*1536,2*1536,1536,512};
	
	//
    for(long psd=0;psd<sizeof(packetsize_data)/sizeof(int);psd++)
    {
		int packetsize=packetsize_data[psd];
		
		printf("********************************************************************\n");
		printf("********************************************************************\n");
		printf("********************************************************************\n");
		
		printf("                    packsetsize=%ld\n",packetsize);
		
		printf("********************************************************************\n");
		printf("********************************************************************\n");
		printf("********************************************************************\n");
		
		const long blocksize=testfile_length+1024;
		
		stat[index].packetsize=packetsize;
		
		
		char filename[256];
		sprintf(filename,"packetsize.%ld.txt",packetsize);
		
		
		
		
		
		////////////////////////////////////////////////////////////////////////
		// put
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
									//	printf(" ;m=%s n=%s i=%d\n",m,n,i);
								} while(i++<4 && m!=NULL);
								if(m)
								{
									int o1=atoi(n+1); //5 
									int o2=atoi(m+1); //6
									//	printf("i=%d o1=%d o2=%d\n",i,o1,o2);
									dataport=o1*256+o2;
								}
							}
							break;
						}
					} while (recvlength>0);
					
					printf("*********send dataport=%d\n",dataport);
					
					
					//
					char s3[80];
					sprintf(s3,"STOR %s",filename);
					sendlength=w->SendCRLF(s3,strlen(s3));
					
					
					
					//
					char dp[32];
					sprintf(dp,"%d",dataport);
					tcp *t=new tcp(szhost,dp);
					if(t)
					{
						t->timeout(secs,0);
						
						t->packetsize(packetsize);
						t->blocksize(blocksize);
						
						long sentbytes=t->Send(testfile,testfile_length);
						
						stat[index].kbps_sent=t->kbps_sent();
						stat[index].bytes_sent=t->bytes_sent();
						
						delete t;
						t=NULL;
					}                         
					
					
					w->RecvCRLF(r);
					
					w->SendCRLF("QUIT");
					w->RecvCRLF(r);
				}
				delete w;
			}
		}
		
		
		
		
		
		
		
		
		////////////////////////////////////////////////////////////////////////
		// get
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
				//
				w->RecvCRLF(r);
				
				//
				w->SendCRLF("USER anonymous");
				w->RecvCRLF(r);
				
				w->SendCRLF("PASS anonymous");
				w->RecvCRLF(r);
				
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
								// printf(" ;m=%s n=%s i=%d\n",m,n,i);
                            } while(i++<4 && m!=NULL);
                            if(m)
                            {
                                int o1=atoi(n+1); //5 
                                int o2=atoi(m+1); //6
								// printf("i=%d o1=%d o2=%d\n",i,o1,o2);
                                dataport=o1*256+o2;
                            }
                        }
                        break;
                    }
                } while(recvlength>0);
                
                printf("********* recv dataport=%d\n",dataport);
                
                
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
                    t->blocksize(blocksize);
                    
                    char *rbuf=NULL;
                    long recvbytes=t->Recv(rbuf);
                    
					if(recvbytes!=testfile_length)
					{
						printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
						printf(" recvbytes=%ld testfile_length=%ld\n",recvbytes,testfile_length);
						printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
					}
					
					stat[index].kbps_recv=t->kbps_received();
					stat[index].bytes_recv=t->bytes_received();
					
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
	
	
	index++;
	
	//
	printf("\n\n");
	printf("#####] sent\t recv\n");
	for(int i=0;i<index;i++)
	{
		printf("%5d] (%16ld\t %16ld)\t (%16lf\t %16lf)\n",
			stat[i].packetsize,
			stat[i].bytes_sent,stat[i].bytes_recv,
			stat[i].kbps_sent,stat[i].kbps_recv
			);
	}
	printf("\n\n");
	}
	
	
	
	
	//
	delete[] testfile;
	
	
	
	
	// final anaylsis
	
	//
	printf("\n\n");
	printf("comparisons against base 512 bytes\n");
	printf("#####] sent\t recv\n");
	for(int i=0;i<index;i++)
	{
		printf("%5d] %lf\t %lf\n",
			stat[i].packetsize,
			100.0*(stat[i].kbps_sent/stat[0].kbps_sent),
			100.0*(stat[i].kbps_recv/stat[0].kbps_recv)
			);
	}
	printf("\n\n");
	
	//  
	return 0;
}
*/