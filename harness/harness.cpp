// harness.cpp : Defines the entry point for the console application.
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
    printf("-------------------------------------------\n");
    
	
	
	
	
	//
    tcp *w=NULL;
    


	    ///////////////////////////////////////////////////////////////////////
    w=new tcp("127.0.0.1","80");
    if(w)
    {/*
        //
        w->timeout(2,0);
        
        
		w->statistics();

		w->keepalives(true);
		w->nagledelay(true);
        w->statistics();

		w->keepalives(false);
		w->nagledelay(false);
        w->statistics();*/

		w->networks();

		delete w;
	}
	
    

	//
    printf("\nfini.\n");
    return 0;
}
