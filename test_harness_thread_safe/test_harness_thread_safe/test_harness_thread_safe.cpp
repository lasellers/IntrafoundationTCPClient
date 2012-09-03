// test_harness_thread_safe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

/*
// harness_threadsafe.cpp : Defines the entry point for the console application.
//

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#if !defined(_MT)
#error _beginthreadex requires a multithreaded C run-time library.
#endif


#import "tcpclientcom.dll" raw_interfaces_only named_guids
//#import "tcpclientcom.dll" no_namespace
//#import "..\tcpclientcom\ReleaseUMinDependency\tcpclientcom.dll" no_namespace

//using namespace std;
#include <process.h> //_beginthread
#include "stdafx.h" 	// Standard MFC libraries

//#include "windows.h"

//LIBCMT.LIB
#include <process.h> //_beginthread

#include "winbase.h" //getcurrentthreadid //WaitForSingleObject

#include "objbase.h" //CoInitializeEx

#include "..\tcpclientcom\tcpclientcom.h"
#include "..\tcpclientcom\tcpclientcom_i.c"

#include "..\tcpclientcom\BSTR.h"


volatile int threadmutex=0;

//
void mythread( void *dummy )
{
	threadmutex++;
	printf("+threadmutex %u thread=%lu\n",threadmutex,GetCurrentThreadId());

	Sleep(100);


	HRESULT hr = NOERROR;

	//			CoInitializeEx(NULL,COINIT_APARTMENTTHREADED);
	//	CoInitialize(NULL);
	CoInitializeEx(NULL, COINIT_MULTITHREADED);

	ITCPClient *ptcpclientcom=NULL;
	//ptcpclientcom=NULL;
	hr = CoCreateInstance(
		CLSID_TCPClient,
		NULL,
		CLSCTX_ALL,
		IID_ITCPClient,
		(void**)&ptcpclientcom
		);

	if(SUCCEEDED(hr))
	{
		printf("ptcpclientcom =%p\n",ptcpclientcom);

		if(ptcpclientcom)
		{
			printf("ptcpclientcom =%p\n",ptcpclientcom);
			ptcpclientcom->put_timeout(5.0);

			//
			BSTR host=L"127.0.0.1";
			BSTR port=L"80";
			long connected;
			HRESULT hrconnected=ptcpclientcom->Open(host,port,&connected);
			if(connected)
			{
				printf("connected...\n");

				ptcpclientcom->put_timeout(5.0);

				BSTR s1=L"GET / HTTP/1.0";
				BSTR s2=L"";

				ptcpclientcom->SendRN(s1);
				ptcpclientcom->SendRN(s2);

				BSTR page;
				HRESULT hrrecv=ptcpclientcom->Recv(&page);

				CBSTR bstr_fn;

				printf("page characterlength=%ld\n",bstr_fn.character_length(page));
				printf("page szlength=%ld\n",bstr_fn.sz_length(page));
				printf("page bytes=%ld\n",bstr_fn.bytes(page));

				//_bstr_t page2=page;
				printf("page=\n%S\n",(char *)page);


				ptcpclientcom->Close();
				printf("closed...\n");
			}
		}

		//
		//////////////////////////////////////////////
		//
		if(ptcpclientcom!=NULL)
			ptcpclientcom->Release();
	}

	//
	CoUninitialize();


	threadmutex--;
	//	_endthread();
	printf("-threadmutex %u thread=%lu\n",threadmutex,GetCurrentThreadId());
}		


//
int main(int argc, char* argv[])
{
	printf("main thread %u\n",GetCurrentThreadId());

	mythread(0);

	int threads=100;
	HANDLE hThread[100];
	for(int n=0;n<threads;n++)
	{
		hThread[n]=(HANDLE)_beginthread(mythread,0,NULL);
		printf("_beginthread %d\n",n);
	}

	int rv = MsgWaitForMultipleObjects(threads,hThread,true,8000,QS_ALLEVENTS); // wait up to 8 seconds
	printf(" thread wait=%d\n",rv);

	while(threadmutex>0)
	{
		printf("#");
		;
	}

	return 0;
}
*/