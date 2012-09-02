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
#ifdef _DEBUG
	printf("CMutex::  thread %u = GetCurrentThreadId %u\n",m_thread,GetCurrentThreadId());
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
	printf("CMutex::Try: thread %u this->thread %u\n",
        thread,m_thread);
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
	else
		return false;
}


/*
*/
bool CMutex::Untry()
{
    int thread=GetCurrentThreadId();

    return Unlock(); //thread);
}


/*
*/
bool CMutex::Lock()
{
    int thread=GetCurrentThreadId();

#ifdef _DEBUG
	printf("CMutex::Lock: thread %u this->thread %u\n",thread,this->m_thread);
#endif
	
	if(isUnlocked()) //thread))
	{
		this->m_thread=thread;
		return true;
	}
	else
		return false;
}

/*
*/
bool CMutex::Unlock()
{
    int thread=GetCurrentThreadId();

#ifdef _DEBUG
	printf("CMutex::Unlock:  thread %u this->thread %u\n",thread,this->m_thread);
#endif

	if(isUnlocked()) //thread))
	{
		this->m_thread=NULL;
		return true;
	}
	else
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
	printf("CMutex::isUnlocked:  thread %u this->thread %u threadid %u\n",thread,this->m_thread);
	printf("CMutex::isUnlocked? %s\n",(thread==this->m_thread || this->m_thread==NULL)?"UNLOCKED":"LOCKED");
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
	printf("CMutex::isLocked:  thread %u this->thread %u\n",thread,this->m_thread);
	printf("CMutex::isLocked? %s\n",(thread==this->m_thread || this->m_thread==NULL)?"UNLOCKED":"LOCKED");
#endif
	
	return (!(thread==this->m_thread || this->m_thread==NULL));
}


/*
*/
long CMutex::get_lock_count()
{
    int thread=GetCurrentThreadId();
#ifdef _DEBUG
	printf("CMutex::get_lock_count: thread %u this->thread %u\n",thread,this->m_thread);
#endif
	return m_lock_count;	
}

/*
*/
long CMutex::get_sleep_milliseconds()
{
    int thread=GetCurrentThreadId();
#ifdef _DEBUG
	printf("CMutex::get_sleep_milliseconds: thread %u this->thread %u\n",thread,this->m_thread);
#endif
	return m_sleep;	
}
