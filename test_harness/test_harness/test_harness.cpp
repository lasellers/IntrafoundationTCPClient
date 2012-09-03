// test_harness.cpp : Defines the entry point for the console application.
//
/*
// tcpClient.cpp : Implementation of CtcpClient
#include "stdafx.h"
#include "tcpclientcom.h"
#include "tcpClient.h"

/////////////////////////////////////////////////////////////////////////////
// CtcpClient

// _open file handling
#include "io.h"
#include <fcntl.h>

//bstr
#include <comdef.h>

// _stat
#include "sys\stat.h"

// wnet*
//Header: Declared in winnetwk.h.
//Import Library: Use mpr.lib.

//
#include "Log.h"*/

#include "stdafx.h"

//#include "windows.h"
//#include "stdio.h"

// _open file handling
#include "io.h"
#include <fcntl.h>

//#include <comdef.h> //BSTR
#include "sys\stat.h" // _stat

//
#include "string.h"
#include <time.h>
#include <conio.h>

//
//#include "..\..\tcpclientcom\tcp.h"
//#include "ErrorStringWSA.h"

#include "..\..\tcpclientcom\Log.h"
#include "..\..\tcpclientcom\tcp.h"

int _tmain(int argc, _TCHAR* argv[])
{
	printf("This is a tcp class debugging test harness.\n");

	tcp *w=NULL;

	///////////////////////////////////////////////////////////////////////
	printf("Do a simple connect to the localhost webserver at 127.0.0.1...\n");
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

		//w->networks();

		delete w;
	}
	///////////////////////////////////////////////////////////////////////

		///////////////////////////////////////////////////////////////////////
	printf("And again to localhost...\n");
	w=new tcp("localhost","80");
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

		//w->networks();

		delete w;
	}
	///////////////////////////////////////////////////////////////////////

	printf("END OF TEST HARNESS\nPress a key..."); _getch();
	return 0;
}

