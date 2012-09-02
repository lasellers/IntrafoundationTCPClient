// harness_mutex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "windows.h"
#include "winbase.h"

#include "..\tcpclientcom\Mutex.h"

int main(int argc, char* argv[])
{
	CMutex mutex;

	//
	printf("A****\n");
	mutex.isLocked(GetCurrentThreadId());
	mutex.Lock(GetCurrentThreadId());


	mutex.Unlock(GetCurrentThreadId());
	mutex.isLocked(GetCurrentThreadId());

	
	//
	printf("B****\n");
		mutex.isLocked(GetCurrentThreadId());
	mutex.Lock(GetCurrentThreadId());
	mutex.Lock(GetCurrentThreadId());
	mutex.Lock(GetCurrentThreadId());


	mutex.Unlock(GetCurrentThreadId());
	mutex.isLocked(GetCurrentThreadId());


	//
	printf("C****\n");
	mutex.isLocked(GetCurrentThreadId());
	mutex.Lock(GetCurrentThreadId());

	mutex.isLocked(1);
	mutex.Lock(1);

	mutex.Unlock(1);
	mutex.isLocked(1);

	mutex.isLocked(GetCurrentThreadId());
	
	return 0;
}

