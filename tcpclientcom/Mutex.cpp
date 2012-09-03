/////////////////////////////////////////////////////////////////////////////
//
// Intrafoundation.Tcpclient.3
//
// Copyright 1999, 200, 2001, 2003, 2004, 2012 by Lewis A. Sellers (AKA Min)
// http://www.intrafoundation.com
// webmaster@intrafoundation.com
//
// Software Homepage: http://www.intrafoundation.com/tcpclient.asp
//
//
/////////////////////////////////////////////////////////////////////////////

// Mutex.cpp: implementation of the CMutex class.
/*

Version History

v1.0 April 3rd? 2004.
*/

//
#include "stdafx.h"

#define WIN32_LEAN_AND_MEAN
#include "windows.h" //Sleep
#include "stdio.h" //printf

#include "Mutex.h"


//#include "limits.h"
//#include <windef.h>
//#include "winbase.h" //sleep


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//
const int CMutex::MUTEX_UNLOCKED=0;
const int CMutex::NAGLE_DELAY=20; //milliseconds

/*
*/
CMutex::CMutex()
{
	m_mutex=MUTEX_UNLOCKED;
	m_thread=NULL;
	m_sleep=0L;
	m_lock_count=0L;

	m_locks=0;
	m_unlocks=0;

#ifdef _DEBUG
	printf("CMutex::\n");
	print_status();
#endif
}

//
CMutex::~CMutex()
{
}


/*
*/
bool CMutex::Try() //, int& mutexlocks)
{
	int thread=GetCurrentThreadId();

#ifdef _DEBUG
	printf("CMutex::Try:\n");
	print_status();
#endif

	size_t emergency_abort_counter=600;
	while(isLocked()) //thread)) // && countdown>0)
	{
		Sleep(NAGLE_DELAY);
		m_sleep+=NAGLE_DELAY;
		m_lock_count++;
		emergency_abort_counter--;
	}

	if(emergency_abort_counter>0)
	{
		Lock(); //thread);
		return true;
	}

	return false;
}


/*
*/
bool CMutex::Untry()
{
#ifdef _DEBUG
	printf("CMutex::Lock\n");
	print_status();
#endif

	return Unlock(); //thread);
}


/*
*/
bool CMutex::Lock()
{
	int thread=GetCurrentThreadId();

#ifdef _DEBUG
	printf("CMutex::Lock\n");
	print_status();
#endif

	this->m_mutex++;
	this->m_locks++;

	if(isUnlocked()) //thread))
	{
		this->m_thread=thread;
		return true;
	}

	return false;
}

/*
*/
bool CMutex::Unlock()
{
	int thread=GetCurrentThreadId();

#ifdef _DEBUG
	printf("CMutex::Unlock\n");
	print_status();
#endif

	this->m_mutex--;
	this->m_unlocks++;

	if(isUnlocked()) //thread))
	{
		this->m_thread=NULL;
		return true;
	}

	return false;
}

/*
Returns:
true, if safe for us to use mutex.
false, if it is busy
*/
bool CMutex::isUnlocked()
{
	int thread=GetCurrentThreadId();

#ifdef _DEBUG
	printf("CMutex::isUnlocked\n");
	printf("CMutex::isUnlocked? %s\n",(thread==this->m_thread || this->m_thread==NULL)?"UNLOCKED":"LOCKED");
	print_status();
#endif

	return (thread==this->m_thread || this->m_thread==NULL);
}

/*
Returns:
false, if safe for us to use mutex.
true, if it is busy
*/
bool CMutex::isLocked() //DWORD thread)
{
	int thread=GetCurrentThreadId();

#ifdef _DEBUG
	printf("CMutex::isLocked\n");
	printf("CMutex::isLocked? %s\n",(thread==this->m_thread || this->m_thread==NULL)?"UNLOCKED":"LOCKED");
	print_status();
#endif

	return (!(thread==this->m_thread || this->m_thread==NULL));
}


/*
*/
long CMutex::get_lock_count()
{
#ifdef _DEBUG
	printf("CMutex::get_lock_count\n");
	print_status();
#endif
	return (long)m_lock_count;	
}

/*
*/
long CMutex::get_sleep_milliseconds()
{
#ifdef _DEBUG
	printf("CMutex::get_sleep_milliseconds\n");
	print_status();
#endif
	return (long)m_sleep;	
}


#ifdef _DEBUG
void CMutex::print_status()
{
	int thread=GetCurrentThreadId();
	printf("  ## thread=%d (this thread:%d) mutex=%d sleep=%d lock_count=%d locks=%d unlocks=%d ##\n",
		thread,
		this->m_thread,
		m_mutex,
		m_sleep,
		m_lock_count,
		m_locks,
		m_unlocks
		);
}
#endif


