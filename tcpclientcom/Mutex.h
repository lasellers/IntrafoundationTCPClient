/////////////////////////////////////////////////////////////////////////////
//
// Intrafoundation.Tcpclient.3
//
// Copyright 1999, 200, 2001, 2003, 2004 by Lewis A. Sellers (AKA Min)
// http://www.intrafoundation.com
// webmaster@intrafoundation.com
//
// Software Homepage: http://www.intrafoundation.com/tcpclient.asp
//
//
/////////////////////////////////////////////////////////////////////////////

// Mutex.h: interface for the CMutex class.
/*

*/
//////////////////////////////////////////////////////////////////////

#if !defined(MUTEX_H)
#define MUTEX_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/*
*/
class CMutex  
{
public:
    CMutex();
    virtual ~CMutex();
	
private:
	typedef int MUTEX;
	typedef unsigned int DWORD;

public:
	static const int MUTEX_UNLOCKED;
	static const int NAGLE_DELAY;
	int m_mutex;
	DWORD m_thread;
	size_t m_sleep;
	size_t m_lock_count;
	size_t m_locks;
	size_t m_unlocks;

#ifdef _DEBUG
private:
	void print_status();
#endif

public:
	bool Try();
	bool Untry();

	bool Lock();
	bool Unlock();
	bool isUnlocked();
	bool isLocked();
	long get_lock_count();
	long get_sleep_milliseconds();
};

#endif
