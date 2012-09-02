// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#if !defined(AFX_STDAFX_H__74116597_0457_424F_9ED6_C9636A6AC47B__INCLUDED_)
#define AFX_STDAFX_H__74116597_0457_424F_9ED6_C9636A6AC47B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// exclude the damn winsock.h (1.1) that VC++ PSDK 2001 will try to pull in
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

// remove ,_ATL_MIN_CRT

//
/*#define STRICT
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif */
#define _ATL_APARTMENT_THREADED

#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
extern CComModule _Module;
#include <atlcom.h>

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__74116597_0457_424F_9ED6_C9636A6AC47B__INCLUDED)
