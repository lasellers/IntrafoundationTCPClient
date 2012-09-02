// Log.cpp: implementation of the CLog class.
/*

  Copyright 2003, 2004 by Lewis A. Sellers (AKA Min)
  http://www.intrafoundation.com
  webmaster@intrafoundation.com
  
*/
/*
Borrowed from v1.3 of Log.
As v1.4 it evoled into a more compilicate unicode version,
the simple Log class here was forever split off for CFX_Execute.
*/
/*

Version History

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

#include <stdio.h>
#include <stdarg.h>

#include "windows.h" //getcurrentthreadid

//
#include "Log.h"

//
string CLog::strError="";

//
CLog::CLog()
{
}

//
CLog::~CLog()
{
}


/*
HARD ERRRORS
hard errors which force the program not to respond such
as hard drive failure or out of memory.

  Error("MyClass::Func",__FILE__,__LINE__,"my error");
  Error(__FILE__,__LINE__,"my error =%d",count);
*/
void CLog::Error(
				 char const* file,
				 const int line,
				 char const* class_and_function,
				 char const* format,
				 ...
				 )
{
	//
	char strv[1024+1];
	va_list argptr;
	va_start(argptr, format);
	_vsnprintf(strv,1024,format,argptr);
	va_end(argptr);
	
	//
	char *pfile=strrchr((char *)file,'\\');
	pfile=(pfile==NULL)?(char *)file:pfile+1;
	
	//
	char str[1024+1];
	_snprintf(
		str,
		1024,
		"[Thread=%u,%s#%d] %s %s\r\n",
		GetCurrentThreadId(),pfile,line,class_and_function,strv
		);
	
	//
	strError.append(str);
	
#ifdef _DEBUG
	printf("\nCLog::ERROR: #####################################################\n     %s\n",str);
#endif
}

/*
Returns error as a const char*
*/
const char* CLog::Errors()
{
	return strError.c_str();
}

/*
Clears the error/warning log.
*/
void CLog::Clear()
{
	strError="";
}
