// test_harness_md5.cpp : Defines the entry point for the console application.
//

// C/C++ / Processor / Processor Definitions: _UNICODE;_CRT_SECURE_NO_WARNINGS;
// Linker / input: ws2_32.lib;


#include "stdafx.h"

//#include <stdlib.h>
//#include <stdio.h>

#include <string.h>

typedef unsigned char BYTE;

#include <comdef.h> //_bstr_t
#include <conio.h> //_getch

#include "..\..\tcpclientcom\BSTR.h"
#include "..\..\tcpclientcom\Log.h"
#include "..\..\tcpclientcom\md5.h"

CBSTR bstr_fns;
CLog log2;

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
			log2.AddLog(
				_T(__FILE__),
				__LINE__,
				L"CTCPClient::HashFile",
				L"Memory allocation failure (%d bytes).",
				strFilename_length+1);
			
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


int _tmain(int argc, _TCHAR* argv[])
{
	printf( "\n MD5 Validation Tests:\n\n" );
	





		//	
	char* const wfilename="\\InetPub\\wwwroot\\IntrafoundationTCPClient\\test_data\\1mb.csv";
	FILE *ho=fopen(wfilename,"rb");
	if(ho!=NULL)
	{
		fclose(ho);
	}
	else
	{
		size_t testfilesize=0;
		printf("\ncreating 1mb.csv at %s...\n\n",wfilename);
		char* cszline="0123456789012345678901234567890123456789012345678901234567890123456789ABCDEF\r\n\0";
		char* line=new char[132];
		if(line)
		{
			strcpy(line,cszline);

			FILE *h=fopen(wfilename,"wb");
			if(h!=NULL)
			{
				for(int blocks=1;blocks<=999;blocks++)
				{
					for(int n=0;n<=99;n++)
					{
						char tmp[16];

						sprintf(tmp,"%2d",n);
						line[0]=tmp[0];
						line[1]=tmp[1];

						sprintf(tmp,"%3d",blocks);
						line[73]=tmp[0];
						line[74]=tmp[1];
						line[75]=tmp[2];

						size_t numwrite=fwrite(line,1,strlen(line),h);
						testfilesize+=numwrite;
						//printf("%s\n",line);
					}
					//	int numwrite=fwrite("\r\n",1,2,h);
					//	testfilesize+=numwrite;
				}
				fclose(h);
			}
		}
		printf("Done. bytes=%d\n\n",testfilesize);
	}









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

		HashFile(L"MD5",L"\\inetpub\\wwwroot\\IntrafoundationTCPClient\\test_data\\1mb.csv",&pHash);
		printf("phash= %S\n",pHash);


		md5.HashFile("\\inetpub\\wwwroot\\IntrafoundationTCPClient\\test_data\\1mb.csv",szhash,1024);
		printf("szhash=%s\n",szhash);
	}
	
	printf( "\n" );


	//
	printf("END OF TEST HARNESS\n");
	printf("Press a key..."); _getch();
	return 0;
}
