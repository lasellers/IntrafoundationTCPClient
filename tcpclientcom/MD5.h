// MD5.h: interface for the CMD5 class.
/*

  Copyright 2004 by Lewis A. Sellers (AKA Min)
  http://www.intrafoundation.com
  webmaster@intrafoundation.com
  
*/

//////////////////////////////////////////////////////////////////////
#if !defined(MD5_H)
#define MD5_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//
#include "Log.h"

//
class CMD5
{
public:
	typedef unsigned char BYTE;
	typedef unsigned short WORD;
	typedef unsigned int DWORD;
	
	CLog log;
	
	CMD5(void);
	virtual ~CMD5(void);
	
	void start(void);
	void update(BYTE* input, DWORD length);
	void finish(void);
	void get_digest(BYTE digest[16]);
	
	bool Validate(const char* validation_checksum);
	
	void Hash(const char* input, char hash[33]);
	void Hash(const char* input, const int length, char hash[33]);
	int HashFile(const char* filename, char hash[33], const int blocksize);
	
	bool Hash_Validate(const char* input, const char* validation_checksum);
	bool Hash_Validate
		(
		const char* input,
		const int length,
		const char* validation_checksum
		);
	bool HashFile_Validate
		(
		const char* filename,
		const char* validation_checksum,
		const int blocksize
		);
	
private:
	//
	DWORD X[16];
	DWORD A, B, C, D;
	
	//
	DWORD AA, BB, CC, DD;
	DWORD m_total_byte_length;
	DWORD m_total_byte_overflow;
	BYTE m_partial_buffer[64];
	
	// static constants
	static BYTE padding[64];
	
	//
	void process(BYTE *data);
	inline DWORD ROL(DWORD x, int n);
	inline DWORD F(DWORD x, DWORD y, DWORD z);
	inline DWORD G(DWORD x, DWORD y, DWORD z);
	inline DWORD H(DWORD x, DWORD y, DWORD z);
	inline DWORD I(DWORD x, DWORD y, DWORD z);
	void FF(DWORD &a, DWORD b, DWORD c, DWORD d, DWORD Xk, int s, DWORD Ti);
	void GG(DWORD &a, DWORD b, DWORD c, DWORD d, DWORD Xk, int s, DWORD Ti);
	void HH(DWORD &a, DWORD b, DWORD c, DWORD d, DWORD Xk, int s, DWORD Ti);
	void II(DWORD &a, DWORD b, DWORD c, DWORD d, DWORD Xk, int s, DWORD Ti);
	
	void DWORDToBYTE(BYTE* data, int i, DWORD d);
	void BYTEToDWORDStream(BYTE* input, DWORD* output);
	
	enum S_CONSTANT
	{
		S11 =7,
			S12 =12,
			S13 =17,
			S14 =22,
			S21 =5,
			S22 =9,
			S23 =14,
			S24 =20,
			S31 =4,
			S32 =11,
			S33 =16,
			S34 =23,
			S41 =6,
			S42 =10,
			S43 =15,
			S44 =21
	};
	
public:
	typedef struct HASH
	{
		unsigned char hash[16];
	} _HASH;
	typedef struct SZHASH
	{
		char hash[33];
	} _SZHASH;
};
#endif
