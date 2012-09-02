// BSTR.h: interface for the CBSTR class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BSTR_H__9E30D182_B9A2_4CC8_9A4E_C2B492996752__INCLUDED_)
#define AFX_BSTR_H__9E30D182_B9A2_4CC8_9A4E_C2B492996752__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//
//#include "Oleauto.h"
//#include <comdef.h>

//#include <afxwin.h>
#include <objbase.h>

 

//
class CBSTR  
{
public:
	CBSTR();
	virtual ~CBSTR();

	unsigned int character_length(BSTR& bstr);
	unsigned int bytes(BSTR& bstr);
	unsigned int sz_length(BSTR& bstr);
	/*
	void * operator new(unsigned int count, const wchar_t *cwsz);
	void * operator new(unsigned int count, wchar_t *wsz);
	void * operator new(unsigned int count, const char *csz);
	void * operator new(unsigned int count, char *sz);
	void operator delete(void *);
	*/

private:
	//static BSTR m_bstr;
};

#endif
