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

#include "windows.h"
#include <conio.h>
//#include "stdio.h"

/*
// _open file handling
#include "io.h"
#include <fcntl.h>

//#include <comdef.h> //BSTR
#include "sys\stat.h" // _stat

//
#include "string.h"
#include <time.h>
*/
#include "winbase.h" //GetCurrentThreadId

//
//#include "..\..\tcpclientcom\tcp.h"
//#include "ErrorStringWSA.h"

//#include "..\..\tcpclientcom\Log.h"
//#include "..\..\tcpclientcom\tcp.h"
#include "..\..\tcpclientcom\Mutex.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CMutex mutex;

	//
	printf("A****\n");
	mutex.isLocked();
	mutex.Lock();


	mutex.Unlock();
	mutex.isLocked();


	//
	printf("B****\n");
	mutex.isLocked();
	mutex.Lock();
	mutex.Lock();
	mutex.Lock();


	mutex.Unlock();
	mutex.isLocked();


	//
	printf("C****\n");
	mutex.isLocked();
	mutex.Lock();

	mutex.isLocked();
	mutex.Lock();

	mutex.Unlock();
	mutex.isLocked();

	mutex.isLocked();

	printf("PRESS"); _getch();
	return 0;
}

