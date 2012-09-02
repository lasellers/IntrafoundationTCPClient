// ErrorStringWSA.h: interface for the CErrorStringWSA class.
/*

 Copyright 2004 by Lewis A. Sellers (AKA Min)
 http://www.intrafoundation.com
 webmaster@intrafoundation.com

 */
//////////////////////////////////////////////////////////////////////
#if !defined(CERRORSTRINGWSA_H)
#define CERRORSTRINGWSA_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/*
 */
class CErrorStringWSA {
public:
	CErrorStringWSA();
	virtual ~CErrorStringWSA();

	static wchar_t* const ErrorString(int const err);
};

#endif
