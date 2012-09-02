// harness_csv.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"

#include "stdio.h"
#include <stdlib.h>
#include <string.h>

typedef unsigned char BYTE;


//
int main(int argc, char* argv[])
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
	
	int clength=strlen(csv);
	
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
    
	
	return 0;
}
