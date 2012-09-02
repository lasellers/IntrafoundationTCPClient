// Log.h: interface for the Log class.
/*

 Copyright 2003, 2004 by Lewis A. Sellers (AKA Min)
 http://www.intrafoundation.com
 webmaster@intrafoundation.com

 */

//
#if !defined(CLOG_H)
#define CLOG_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//
#include <sstream>
#include <string>
using namespace std;

/*
 */
class CLog {
public:
	CLog();
	virtual ~CLog();

	void AddLog(wchar_t const* file, const int line,
			wchar_t const* class_and_function, wchar_t const* format, ...);
	const wchar_t* Logs();
	void Clear();

//private:
	static wstring aggregate_string;
};

#endif
