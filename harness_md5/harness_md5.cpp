// harness_md5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <stdlib.h>
#include <stdio.h>

#include <string.h>

typedef unsigned char BYTE;

#include <comdef.h> //_bstr_t

#include "..\tcpclientcom\BSTR.h"
CBSTR bstr_fns;
#include "..\tcpclientcom\Log.h"
CLog log;

#include "..\tcpclientcom\md5.h"

/*
* those are the standard RFC 1321 test vectors
*/

static char *msg[] = 
{
	"",
		"a",
		"abc",
		"message digest",
		"abcdefghijklmnopqrstuvwxyz",
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789",
		"12345678901234567890123456789012345678901234567890123456789012" \
		"345678901234567890"
};

static char *val[] =
{
	"d41d8cd98f00b204e9800998ecf8427e",
		"0cc175b9c0f1b6a831c399e269772661",
		"900150983cd24fb0d6963f7d28e17f72",
		"f96b697d7cb7938d525a2f31aaf161d0",
		"c3fcd3d76192e4007dfb496cca67e13b",
		"d174ab98d277d9f5a5611c2c9f419d9f",
		"57edf4a22be3c955ac49da2e2107b67a"
};


int HashFile(
  		BSTR strHashType,
		BSTR strFilename,
		BSTR *pstrHash
)
{
//#ifdef _DEBUG
	printf("\nTCPClient::HashFile strHashType=%S strFilename=%S pstrHash=%p\n",strHashType,strFilename,pstrHash);
//#endif

	//
	HRESULT retval=S_OK;
	
	CMD5 md5;
	
	//
	const int strFilename_length=bstr_fns.sz_length(strFilename);
	char *szFilename=new char[strFilename_length+1];
	if(szFilename==NULL)
		{
			log.Error(
				__FILE__,
				__LINE__,
				"CTCPClient::HashFile",
				"Memory allocation failure (%d bytes).",strFilename_length+1);
			
			retval=E_OUTOFMEMORY;
		}
		else
		{
			//
			wcstombs(szFilename,strFilename,strFilename_length+1);
			
			char md5hash[32+1];
			const int blocksize=65536;
			md5.HashFile(szFilename,md5hash,blocksize);
			
			wchar_t bstr[32+1];
			mbstowcs(bstr,md5hash,32+1);
			*pstrHash=SysAllocString(bstr);

			delete[] szFilename;
		}
	
	return retval;
}


int main(int argc, char* argv[])
{
	printf( "\n MD5 Validation Tests:\n\n" );
	
	//
	CMD5 md5;
	unsigned char md5sum[33]; //16];

	/*
	//
	for(int i = 0; i < 7; i++ )
	//for( i = 6; i >=0; i-- )
	//for( int i = 1; i<=1; i++ )
	{
		printf("\nTest %d\n", i + 1 );
		
		md5.start();
		md5.update( (unsigned char *)msg[i], strlen( msg[i] ) );
		md5.finish();
		md5.get_digest( md5sum );
		
		if(md5.validate(val[i]))
			printf( "\t\tPASSED\n" );
		else
			printf( "\t\t**FAILED!**\n" );
	}
	
	printf( "\n" );
*/

	{
		printf("\nhashfile\n" );
		char szhash[33];
		BSTR pHash;

		HashFile(L"MD5",L"",&pHash);
		printf("phash= %S\n",pHash);

		HashFile(L"MD5",L"bogus.txt",&pHash);
		printf("phash= %S\n",pHash);

		HashFile(L"MD5",L"c:\\inetpub\\wwwroot\\tcpclientcom\\send\\1mb.txt",&pHash);
		printf("phash= %S\n",pHash);


		md5.HashFile("c:\\inetpub\\wwwroot\\tcpclientcom\\send\\1mb.txt",szhash,1024);
		printf("szhash=%s\n",szhash);
	}
	
	printf( "\n" );


	return 0;
}

