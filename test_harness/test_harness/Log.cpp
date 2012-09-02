// Log.cpp: implementation of the CLog class.
/*

 Copyright 2003, 2004 by Lewis A. Sellers (AKA Min)
 http://www.intrafoundation.com
 webmaster@intrafoundation.com

 Version History


 1.5
 http://aegis.sourceforge.net/doxygen-html/classwstring.html
 

 
 v1.4
 Borrowed from v1.3 of Log.
 As v1.4 it evolved into a more complicated unicode version,
 the simple Log class here was forever split off for CFX_Execute.
 
 v1.3 July 13th 2004.

 v1.2 July 10th 2004.

 v1.1 July 2004.
 Cleaned up static declarations, etc and slightly designed for common
 use in udpclientcom, tcpclientcom, networkdiscoverycom and INMaL.

 v1.0 March/April 2004
 Borrowed from another project and added in stripped down form.
 Modified to be a network thread-level mutex.

 */
///////////////////////////////////////////////////////////////////////////
//
#include "stdafx.h"

//
#define WIN32_LEAN_AND_MEAN 	// Exclude rarely-used stuff from Windows headers
//#include <stdio.h>
#include <stdarg.h>

#include "windows.h" //getcurrentthreadid
//
#include "Log.h"

//
wstring CLog::aggregate_string = L"";

//
CLog::CLog() {
}

//
CLog::~CLog() {
}

/*
 HARD ERRRORS
 hard errors which force the program not to respond such
 as hard drive failure or out of memory.

 AddLog("MyClass::Func",__FILE__,__LINE__,"my error");
 AddLog(__FILE__,__LINE__,"my error =%d",count);
 */
void CLog::AddLog(wchar_t const* file, const int line,
		wchar_t const* class_and_function, wchar_t const* format, ...) {
	// get all the variables arguments and sprintf them to strv
	wchar_t strv[1024 + 1];
	va_list argptr;
	va_start(argptr, format);
	_vsnwprintf(strv, 1024, format, argptr);
	va_end(argptr);

	// we want to print the project file name but without the initial slash...
	// pfile points to that.
	wchar_t *pfile = wcschr((wchar_t *) file, '\\');
	pfile = (pfile == NULL) ? (wchar_t *) file : pfile + 1;

	//
	wchar_t str[1024 + 1];
	_snwprintf(str, 1024, L"[Thread=%u,%s#%d] %s %s\r\n", GetCurrentThreadId(),
			pfile, line, class_and_function, strv);

	//
	aggregate_string.append(str);

#ifdef _DEBUG
	printf("\nCLog::ERROR: #####################################################\n     %s\n",str);
#endif
}

/*
 Returns error as a const char*
 */
const wchar_t* CLog::Logs() {
	return aggregate_string.c_str();
}

/*
 Clears the error/warning log.
 */
void CLog::Clear() {
	aggregate_string = L"";
}
