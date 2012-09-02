// harness_szlist.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"

#include <stdlib.h>

#include "windows.h"
#include "stdio.h"

// _open file handling
#include "io.h"
#include <fcntl.h>

// _stat
#include "sys\stat.h"

#include "string.h"

#include <time.h>

#include <conio.h>

#include "..\tcpclientcom\szList.h"


//
int main(int argc, char* argv[])
{

	const char* delims=" ,\t";
	const char* text1="begin 644 filename.txt\r\nmy test here.\r\nend\r\n";
	int i;
	int els;
	CszList *szList=new CszList();
	char *next=(char *)text1;

	for(int n=0;n<3;n++)
	{
	
	next=(char *)szList->start(next,delims);
	printf("next: %s\n",next);

	els=szList->getElements();
	printf("elements=%d\n",els);

	for(i=1;i<=els;i++)
	{
		printf("getelement %d %s\n",i,szList->getElement(i));
	}




	}

	delete szList;
	
	printf("fini.\n");
	return 0;
}
