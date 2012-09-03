// test_harness_concurrent.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

/*
// harness_concurrent.cpp : Defines the entry point for the console application.
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
    printf("Tests HTTP protocol functions -- concurrently.\n");
    printf("-------------------------------------------\n");

    
	const int COUNT=16;


	      ///////////////////////////////////////////////////////////////////////
	{
	printf("\n\n************** get / http/1.0\n\n ");

	int n;
		tcp *w[COUNT];
        char *r[COUNT];

		for(n=0;n<COUNT;n++)
		{
			w[n]=new tcp("127.0.0.1","80");
			r[n]=NULL;
		}

        //
        for(n=0;n<COUNT;n++) w[n]->timeout(2,0);
        
        //
        int sendlength=0;
        for(n=0;n<COUNT;n++)
		{
			char tmp[200];
			sprintf(tmp,"GET /%d.HTML HTTP/1.0",n);
			sendlength=w[n]->SendCRLF(tmp,strlen(tmp));
		}
        for(n=0;n<COUNT;n++) sendlength=w[n]->SendCRLF(NULL,0);
        
        //
        int recvlength=0;
        for(n=0;n<COUNT;n++)
		{
			recvlength=w[n]->Recv(r[n]);
			if(r[n]) printf("RECV:\n%s\n\n",r[n]);
		}
        
        for(n=0;n<COUNT;n++) delete w[n];
	}


	//
    printf("\nfini.\n");
    return 0;
}

*/