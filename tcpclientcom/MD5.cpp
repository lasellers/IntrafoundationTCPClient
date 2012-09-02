// MD5.cpp: implementation of the CMD5 class.
/*

  Copyright 2003, 2004, 2012 by Lewis A. Sellers (AKA Min)
  http://www.intrafoundation.com
  webmaster@intrafoundation.com
  
  Version History

  v1.2 August 30th 2012
	V1.1 July 13th 2004
	v1.0 April, July 2004
	
  T. ( 2** 32 ) * sin[ x ]. Where x goes from 1 to 64 radians.
  
*/

//////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include "MD5.h"

//#include "Log.h"

//
#include "stdio.h"	//sprintf
#include <string.h>

// _stat
#include "sys/stat.h"

//////////////////////////////////////////////////////////////////////

// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CMD5::CMD5(void)
{
}

CMD5::~CMD5(void)
{
}

/*
*/
void CMD5::start(void)
{
#ifdef _DEBUG
	printf("CMD5::start\n");
#endif
	m_total_byte_length=0;
	m_total_byte_overflow=0;
	
	/*
	word A: 01 23 45 67 
	word B: 89 ab cd ef 
	word C: fe dc ba 98 
	word D: 76 54 32 10
	*/
	AA=0x67452301;
	BB=0xEFCDAB89;
	CC=0x98BADCFE;
	DD=0x10325476;
}

//
CMD5::BYTE CMD5:: padding[64]=
{
	0x80,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
};

/*
*/
void CMD5::DWORDToBYTE(
					   BYTE* data,
					   int i,
					   DWORD d
					   )
{
	//	*(DWORD *)(data+i)=d;
	data[i]=(BYTE) (d);
	data[i + 1]=(BYTE) (d >> 8);
	data[i + 2]=(BYTE) (d >> 16);
	data[i + 3]=(BYTE) (d >> 24);
}

/*
*/
void CMD5::BYTEToDWORDStream(
							 BYTE* input,
							 DWORD* output
							 )
{
	int d, b;
	for(d=0, b=0; d <= 15; d++, b+=4)
	{
		DWORD tmp=(DWORD) input[b] |
			(DWORD) input[b + 1] <<
			8 |
			(DWORD) input[b + 2] <<
			16 |
			(DWORD) input[b + 3] <<
			24;
		output[d]=tmp;
		
#ifdef _DEBUG
		//	printf("output/X[%2d]= (%2d) %10X\n",d,b,tmp);
#endif
	}
}

/*
*/
inline CMD5::DWORD CMD5::ROL(DWORD x, int n)
{
	return (x << n) | (x >> (32 - n));
}

// F(X,Y,Z) = XY v not(X) Z
inline CMD5::DWORD CMD5::F(DWORD x, DWORD y, DWORD z)
{
	return (x & y) | (~x & z);
}

// G(X,Y,Z) = XZ v Y not(Z)
inline CMD5::DWORD CMD5::G(DWORD x, DWORD y, DWORD z)
{
	return (x & z) | (y &~z);
}

// H(X,Y,Z) = X xor Y xor Z
inline CMD5::DWORD CMD5::H(DWORD x, DWORD y, DWORD z)
{
	return (x ^ y ^ z);
}

// I(X,Y,Z) = Y xor (X v not(Z))
inline CMD5::DWORD CMD5::I(DWORD x, DWORD y, DWORD z)
{
	return (y ^ (x | ~z));
}

//	T. ( 2** 32 ) * sin[ x ]. Where x goes from 1 to 64 radians.

//a = b + ((a + F(b,c,d) + X[k] + T[i]) <<< s)
void CMD5::FF(DWORD &a, DWORD b, DWORD c, DWORD d, DWORD Xk, int s, DWORD Ti)
{
	a+=F(b,c,d) + Xk + Ti;
	a=ROL(a,s);
	a+=b;
}

//a = b + ((a + G(b,c,d) + X[k] + T[i]) <<< s)
void CMD5::GG(DWORD &a, DWORD b, DWORD c, DWORD d, DWORD Xk, int s, DWORD Ti)
{
	a+=G(b,c,d) + Xk + Ti;
	a=ROL(a,s);
	a+=b;
}

//a = b + ((a + H(b,c,d) + X[k] + T[i]) <<< s)
void CMD5::HH(DWORD &a, DWORD b, DWORD c, DWORD d, DWORD Xk, int s, DWORD Ti)
{
	a+=H(b,c,d) + Xk + Ti;
	a=ROL(a,s);
	a+=b;
}

//a = b + ((a + I(b,c,d) + X[k] + T[i]) <<< s)
void CMD5::II(DWORD &a, DWORD b, DWORD c, DWORD d, DWORD Xk, int s, DWORD Ti)
{
	a+=I(b,c,d) + Xk + Ti;
	a=ROL(a,s);
	a+=b;
}

/*
*/
void CMD5::process(
				   BYTE data[64]
				   )
{
#ifdef _DEBUG
	//printf("CMD5::process data=%p\n",(BYTE *)data);
#endif
	
	//
	BYTEToDWORDStream(data,X);
	
	//
	A=AA;
	B=BB;
	C=CC;
	D=DD;
#ifdef _DEBUG
	//printf("+A=%10x B=%10x C=%10x D=%10x   AA=%10x BB=%10x CC=%10x DD=%10x\n",A,B,C,D,AA,BB,CC,DD);
#endif
	
	// round 1
	FF(A,B,C,D,X[0],S11,0xD76AA478);
	FF(D,A,B,C,X[1],S12,0xE8C7B756);
	FF(C,D,A,B,X[2],S13,0x242070DB);
	FF(B,C,D,A,X[3],S14,0xC1BDCEEE);
	
	FF(A,B,C,D,X[4],S11,0xF57C0FAF);
	FF(D,A,B,C,X[5],S12,0x4787C62A);
	FF(C,D,A,B,X[6],S13,0xA8304613);
	FF(B,C,D,A,X[7],S14,0xFD469501);
	
	FF(A,B,C,D,X[8],S11,0x698098D8);
	FF(D,A,B,C,X[9],S12,0x8B44F7AF);
	FF(C,D,A,B,X[10],S13,0xFFFF5BB1);
	FF(B,C,D,A,X[11],S14,0x895CD7BE);
	
	FF(A,B,C,D,X[12],S11,0x6B901122);
	FF(D,A,B,C,X[13],S12,0xFD987193);
	FF(C,D,A,B,X[14],S13,0xA679438E);
	FF(B,C,D,A,X[15],S14,0x49B40821);
	
	// round 2
	GG(A,B,C,D,X[1],S21,0xF61E2562);
	GG(D,A,B,C,X[6],S22,0xC040B340);
	GG(C,D,A,B,X[11],S23,0x265E5A51);
	GG(B,C,D,A,X[0],S24,0xE9B6C7AA);
	
	GG(A,B,C,D,X[5],S21,0xD62F105D);
	GG(D,A,B,C,X[10],S22,0x02441453);
	GG(C,D,A,B,X[15],S23,0xD8A1E681);
	GG(B,C,D,A,X[4],S24,0xE7D3FBC8);
	
	GG(A,B,C,D,X[9],S21,0x21E1CDE6);
	GG(D,A,B,C,X[14],S22,0xC33707D6);
	GG(C,D,A,B,X[3],S23,0xF4D50D87);
	GG(B,C,D,A,X[8],S24,0x455A14ED);
	
	GG(A,B,C,D,X[13],S21,0xA9E3E905);
	GG(D,A,B,C,X[2],S22,0xFCEFA3F8);
	GG(C,D,A,B,X[7],S23,0x676F02D9);
	GG(B,C,D,A,X[12],S24,0x8D2A4C8A);
	
	// round 3
	HH(A,B,C,D,X[5],S31,0xFFFA3942);
	HH(D,A,B,C,X[8],S32,0x8771F681);
	HH(C,D,A,B,X[11],S33,0x6D9D6122);
	HH(B,C,D,A,X[14],S34,0xFDE5380C);
	
	HH(A,B,C,D,X[1],S31,0xA4BEEA44);
	HH(D,A,B,C,X[4],S32,0x4BDECFA9);
	HH(C,D,A,B,X[7],S33,0xF6BB4B60);
	HH(B,C,D,A,X[10],S34,0xBEBFBC70);
	
	HH(A,B,C,D,X[13],S31,0x289B7EC6);
	HH(D,A,B,C,X[0],S32,0xEAA127FA);
	HH(C,D,A,B,X[3],S33,0xD4EF3085);
	HH(B,C,D,A,X[6],S34,0x04881D05);
	
	HH(A,B,C,D,X[9],S31,0xD9D4D039);
	HH(D,A,B,C,X[12],S32,0xE6DB99E5);
	HH(C,D,A,B,X[15],S33,0x1FA27CF8);
	HH(B,C,D,A,X[2],S34,0xC4AC5665);
	
	// round 4
	II(A,B,C,D,X[0],S41,0xF4292244);
	II(D,A,B,C,X[7],S42,0x432AFF97);
	II(C,D,A,B,X[14],S43,0xAB9423A7);
	II(B,C,D,A,X[5],S44,0xFC93A039);
	
	II(A,B,C,D,X[12],S41,0x655B59C3);
	II(D,A,B,C,X[3],S42,0x8F0CCC92);
	II(C,D,A,B,X[10],S43,0xFFEFF47D);
	II(B,C,D,A,X[1],S44,0x85845DD1);
	
	II(A,B,C,D,X[8],S41,0x6FA87E4F);
	II(D,A,B,C,X[15],S42,0xFE2CE6E0);
	II(C,D,A,B,X[6],S43,0xA3014314);
	II(B,C,D,A,X[13],S44,0x4E0811A1);
	
	II(A,B,C,D,X[4],S41,0xF7537E82);
	II(D,A,B,C,X[11],S42,0xBD3AF235);
	II(C,D,A,B,X[2],S43,0x2AD7D2BB);
	II(B,C,D,A,X[9],S44,0xEB86D391);
	
	//
	AA+=A;
	BB+=B;
	CC+=C;
	DD+=D;
	
#ifdef _DEBUG
	//	printf("-A=%10x B=%10x C=%10x D=%10x   AA=%10x BB=%10x CC=%10x DD=%10x\n",A,B,C,D,AA,BB,CC,DD);
#endif
}

/*
*/
void CMD5::update(
				  BYTE* input,
				  DWORD length
				  )
{
#ifdef _DEBUG
	//	printf("CMD5::update input=%p length=%d ie, %d bits\n",input,length,length*8);
	//	printf(" input=%s\n",input);
#endif
	
	//
	if(length == 0)
	{
		return;
	}
	
	//
	DWORD left=m_total_byte_length & 63;
	DWORD fill=64 - left;
	
	//
	m_total_byte_length+=length;
	m_total_byte_length&=0xFFFFFFFF;
	
	if(m_total_byte_length < length) m_total_byte_overflow++;
	
	// handle remainders left over from last call.
	if(left > 0U && length >= fill)
	{
		memcpy((void *)((BYTE *)m_partial_buffer + left),(void *)input,fill);
		process((BYTE *)m_partial_buffer);
		length-=fill;
		input+=fill;
		left=0;
	}
	
	// main processing loop.
	while(length >= 64)
	{
		process(input);
		length-=64;
		input+=64;
	}
	
	// buffer the remaining input. finalize function will take care of it.
	if(length > 0)
	{
		memcpy((void *)((BYTE *)m_partial_buffer + left),(void *)input,length);
	}
}

/*
*/
void CMD5::finish(void)
{
#ifdef _DEBUG
	printf("CMD5::finish\n");
#endif
	
	const DWORD bitlength=m_total_byte_length;
	const DWORD bitoverflow=m_total_byte_overflow;
	
	// append padding bits. congruent 448, moduls 512 bits
	DWORD last=bitlength & 63;
	DWORD padn=(last < 56) ? (56 - last) : (120 - last);
#ifdef _DEBUG
	printf("\n\n\n padn=%d\n",padn);
#endif
	update(padding,padn);
#ifdef _DEBUG
	printf("pad A=%10x B=%10x C=%10x D=%10x   AA=%10x BB=%10x CC=%10x DD=%10x\n",
		A,
		B,
		C,
		D,
		AA,
		BB,
		CC,
		DD);
#endif
	
	// append 64-bit length (b) of data before padding bits were added.
	//DWORD high = ( bitlength >> 29 ) | ( bitoverflow <<  3 );
	//DWORD low  = ( bitlength << 3 );
	DWORD high=(bitlength >> 29);
	DWORD low=(bitlength << 3);
	BYTE msglen[8];
	DWORDToBYTE(msglen,0,low);
	DWORDToBYTE(msglen,4,high);
#ifdef _DEBUG
	printf("\n\n\n msglen=%d %X\n",msglen,msglen);
#endif
	update(msglen,8);
	
#ifdef _DEBUG
	printf("msglen A=%10x B=%10x C=%10x D=%10x   AA=%10x BB=%10x CC=%10x DD=%10x\n",
		A,
		B,
		C,
		D,
		AA,
		BB,
		CC,
		DD);
#endif
}

/*
*/
void CMD5::get_digest(
					  BYTE digest[16]
					  )
{
#ifdef _DEBUG
	printf("CMD5::get_digest\n");
#endif
#ifdef _DEBUG
	printf(" A=%10x B=%10x C=%10x D=%10x\n",A,B,C,D);
#endif
	
	//
	DWORDToBYTE(digest,0,AA);
	DWORDToBYTE(digest,4,BB);
	DWORDToBYTE(digest,8,CC);
	DWORDToBYTE(digest,12,DD);
}

/*
*/
bool CMD5::Validate(
					const char* validation_checksum
					)
{
	//
	HASH MD5_checksum;
	get_digest(MD5_checksum.hash);
	
	//
	SZHASH sz_MD5_checksum;
	for(int i=0; i < 16; i++)
	{
		sprintf(sz_MD5_checksum.hash + i * 2,"%02x",MD5_checksum.hash[i]);
	}
	
	//		
	bool result=(memcmp(sz_MD5_checksum.hash,validation_checksum,32) == 0);
	
#ifdef _DEBUG
	printf("MD5_checksum:        %s\n",sz_MD5_checksum.hash);
	printf("validation_checksum: %s\n",validation_checksum);
	
	if(result)
		printf("\t\tPASSED\n");
	else
		printf("\t\t**FAILED!**\n");
#endif
	
	return result;
}

/*
*/
void CMD5::Hash(
				const char* input,
				const int length,
				char hash[33]
				)
{
	//
	start();
	update((unsigned char *)input,length);
	finish();
	
	//
	HASH checksum;
	get_digest(checksum.hash);
	for(int i=0; i < 16; i++)
	{
		sprintf(hash + i * 2,"%02x",checksum.hash[i]);
	}
}

/*
*/
void CMD5::Hash(
				const char* input,
				char hash[33]
				)
{
	//
	start();
	update((unsigned char *)input,strlen(input));
	finish();
	
	//
	HASH checksum;
	get_digest(checksum.hash);
	for(int i=0; i < 16; i++)
	{
		sprintf(hash + i * 2,"%02x",checksum.hash[i]);
	}
}

/*
*/
int CMD5::HashFile(
				   const char* filename,
				   char hash[33],
				   const int blocksize
				   )
{
#ifdef _DEBUG
	printf("\nCMD5::HashFile filename=%s blocksize=%d\n",filename,blocksize);
#endif
	
	// reset variables so if hash fails prematurely we don't get an old digest later on.
	start();
	
	//
	memset(hash,'0',32);
	hash[32]='\0';
	
	//
	int bytes=0;
	
	//
	struct _stat statbuf;
	const int result=_stat(filename,&statbuf);
	if(result == -1)
	{
		log.AddLog(
			_T(__FILE__),
			__LINE__,
			L"CMD5::HashFileEmit",
			L"_stat error on file (%s). Could not retrieve file statistics.",
			filename
			);
	}
	else
	{
#ifdef _DEBUG
		printf(" File size     : %ld\n",statbuf.st_size);
		printf(" Drive         : %c:\n",statbuf.st_dev + 'A');
		
		//		printf(" Time modified : %s", ctime( &statbuf.st_atime ) );
#endif
		
		FILE *h=fopen(filename,"rb");
		if(h == NULL)
		{
			log.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CMD5::HashFileEmit",
				L"File (%s) could not be opened for binary read.",
				filename);
		}
		else
		{
			//
			const int filesize= (long)statbuf.st_size;
			
			//
			//			start();
			//
			char *buf=new char[blocksize + 1];
			if(buf)
			{
				int bytes_left=filesize;
				while(bytes_left > 0)
				{
#ifdef _DEBUG
					printf(" reading %d bytes from disk...\n\n",blocksize);
#endif
					
					const int bytes_read=fread(buf,1,blocksize,h);
					update((unsigned char *)buf,bytes_read);
					
#ifdef _DEBUG
					printf(" read=%d\n",bytes_read);
					printf(" %d of %d bytes remaining.\n",bytes_left,filesize);
#endif
					
					//
					bytes_left-=bytes_read;
				}
				
				//
				finish();
				
				//
				HASH checksum;
				get_digest(checksum.hash);
				for(int i=0; i < 16; i++)
				{
					sprintf(hash + i * 2,"%02x",checksum.hash[i]);
				}
				
				//
				delete[] buf;
				buf=NULL;
			}
		}
		
		//
		fclose(h);
	}
	
	//
	return bytes;
}

/*
*/
bool CMD5::Hash_Validate(
					   const char* input,
					   const char* validation_checksum
					   )
{
	SZHASH h;
	Hash(input,h.hash);
	return Validate(validation_checksum);
}
				   
/*
*/
bool CMD5::Hash_Validate(
						 const char* input,
						 const int length,
						 const char* validation_checksum
						 )
{
	SZHASH h;
	Hash(input,length,h.hash);
	return Validate(validation_checksum);
}

/*
*/
bool CMD5::HashFile_Validate(
							 const char* filename,
							 const char* validation_checksum,
							 const int blocksize
							 )
{
	SZHASH h;
	HashFile(filename,h.hash,blocksize);
	return Validate(validation_checksum);
}
