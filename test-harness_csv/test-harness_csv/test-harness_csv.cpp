// test-harness_csv.cpp : Defines the entry point for the console application.
//

// C/C++ / Processor / Processor Definitions: _UNICODE;_CRT_SECURE_NO_WARNINGS;
// Linker / input: ws2_32.lib;

#include "stdafx.h"

#include "stdio.h"
#include <stdlib.h>
#include <string.h>

typedef unsigned char BYTE;


//
int _tmain(int argc, _TCHAR* argv[])
{
	//
	const char *str="GET / HTTP/1.0\r\n";
	for(int n=0;n<(int)strlen(str);n++)
	{
		printf("%d,",str[n]);
	}
	printf("\n");

	
	//
	char *csv="13,10";

	size_t clength=strlen(csv);

	char *decsv=new char[clength];

	if(decsv==NULL)
	{
		printf("Memory allocation failure (%d bytes)",clength);

	}
	else
	{
		//
		char *s=csv;
		char *d=decsv;
		int count=0;
		char *c=NULL;
		do
		{
			const int i=atoi(s);
			*d=(BYTE)i;
			d++;
			c=strchr(s,',');
			if(c)
				s=c+1;
			count++;
		} while(c!=NULL);

		//
		//                    w->Send( decsv, count);

		//
		delete[] decsv;
	}

	//
	//delete[] csv;


	//
	printf("END OF TEST HARNESS\n");
	//	printf("Press a key..."); _getch();
	return 0;
}
