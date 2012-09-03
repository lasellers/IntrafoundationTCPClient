// test_harness_mutex.cpp : Defines the entry point for the console application.
//

// C/C++ / Processor / Processor Definitions: _UNICODE;_CRT_SECURE_NO_WARNINGS;
// Linker / input: ws2_32.lib;

#include "stdafx.h"

#include "windows.h"
#include <conio.h>
//#include "stdio.h"

#include "winbase.h" //GetCurrentThreadId

#include "..\..\tcpclientcom\Mutex.h"

int _tmain(int argc, _TCHAR* argv[])
{
	printf("Test Mutex locking...\n");


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

	//
	printf("END OF TEST HARNESS\n");
	printf("Press a key..."); _getch();
	return 0;
}

