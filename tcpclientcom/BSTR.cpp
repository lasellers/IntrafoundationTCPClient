// BSTR.cpp: implementation of the CBSTR class.
//
//////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
//
// BSTR CLASS
/*
  Written by Lewis A. Sellers (AKA Min)

  webmaster@intrafoundation.com
  http://www.intrafoundation.com/
  
	(865)828-4024
	Rutledge, TN USA
	
*/
///////////////////////////////////////////////////////////////////////////
/*

  Version History

 v1.0 March 26 2004. Wrote this from scratch in about three hours out of general
 annoyance with BSTR. --min

*/
///////////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "BSTR.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBSTR::CBSTR()
{
	
}

CBSTR::~CBSTR()
{
	
}


/*
There aren't any BSTR functions that will accurately tell you the length of a BSTR
if it has binary data in it (i.e., there are NULL's in the string) so we make one 
for our own use here.

  This works because all BSTR string structures consist of the 16-bit UNICODE string itself,
  a post-pended NULL and a pre-pended unsigned int count of the bytes in the string.
  
	What were doing here is directly returning the true allocated length by 
	looking at the dword before the BSTR string.
*/
unsigned int CBSTR::character_length(BSTR& bstr)
{
	unsigned long *ptr=(unsigned long *)bstr;
	return (*(--ptr))>>1;
}

/*
Returns the bytes allocated for the string.
*/
unsigned int CBSTR::bytes(BSTR& bstr)
{
	unsigned long *ptr=(unsigned long *)bstr;
	return (*(--ptr));
}

/*
Returns the number of characters in the string up to the first NULL.
*/
unsigned int CBSTR::sz_length(BSTR& bstr)
{
	int bytes_remaining=bytes(bstr);

	int count=0;
	unsigned short *ptr=(unsigned short *)bstr;

	while( (bytes_remaining>1) && ((*ptr)!=0) )
	{
		count++;
		ptr++;
		bytes_remaining--;
	}

	return count;
}


/*
*/
/*
void * CBSTR::operator new(unsigned int count, const wchar_t *cwsz)
{
	SysFreeString(m_bstr);
	m_bstr=SysAllocString(cwsz);
	return m_bstr;
}
*/

/*
*/
/*void * CBSTR::operator new(unsigned int count, wchar_t *wsz)
{
	SysFreeString(m_bstr);
	m_bstr=SysAllocString(wsz);
	return m_bstr;
}*/

/*
*/
/*void * CBSTR::operator new(unsigned int count, const char *csz)
{
	wchar_t *wsz=NULL;
	int ccount=mbstowcs( wsz, csz, strlen(csz) );
	SysFreeString(m_bstr);
	m_bstr=SysAllocString(wsz);
	return m_bstr;
}*/

/*
*/
/*void * CBSTR::operator new(unsigned int count, char *sz)
{
	wchar_t *wsz=NULL;
	int ccount=mbstowcs( wsz, (const char *)sz, strlen(sz) );
	SysFreeString(m_bstr);
	m_bstr=SysAllocString(wsz);
	return m_bstr;
}*/

/*
*/
/*
void CBSTR::operator delete(void *ptr)
{
	SysFreeString((BSTR)ptr);
}*/

