// test_harness_ssl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

/*
// harness_ssl.cpp : Defines the entry point for the console application.
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
#include "..\tcpclientcom\Log.h"

main()
{
    printf("This is a tcp class debugging test harness.\n");
    printf("Tests HTTPS protocol functions.\n");
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
    w=new tcp("www.ibm.com","443");
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
	
    
    
    
    
	
	//
    printf("\nfini.\n");
    return 0;
}

*/
