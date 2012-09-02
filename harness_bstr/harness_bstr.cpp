// harness_bstr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "stdio.h"
#include <stdlib.h>
#include <string.h>

typedef unsigned char BYTE;

#include <comdef.h> //_bstr_t

#include "..\tcpclientcom\BSTR.h"

//
int bstr_length(BSTR& bstr)
{
	unsigned long *ptr;
	ptr=(unsigned long *)bstr;
	ptr--;
	return *ptr;
}


/*
//
void printbits(DWORD d)
{
printf("bits: %16u ",d);
for(int i=0;i<=31;i++)
{
printf("%c",((d>>31)&1)?'1':'0');
d=d<<1;
}
printf("\n");
}
*/
//
void printbits(_int64 d)
{
	printf("%16I64u ",d);
	for(int i=0;i<=63;i++)
	{
		printf("%c",((d>>63)&1)?'1':'0');
		d=d<<1;
	}
	printf("\n");
}

/*
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
*/
// 8 16 24 32 40 48 56 64
_int64 changeEndian(_int64 d, short bits)
{
	if((bits&7)==0)
	{
		const int bytes=(int)(bits>>3);
		BYTE b[8];
		int i;
		BYTE *p=(BYTE *)&d;
		for(i=0;i<bytes;i++)
		{
			b[i]=*(p+bytes-i-1);
		}
		for(;i<8;i++)
		{
			b[i]=0;
		}
		return *(_int64 *)b;
	}
	else
	{
		return d;
	}
}

/*
DWORD changeEndian(DWORD d, int bits)
{
else if(bits==16)
{
return ((d&255)<<8) + ((d>>8)&255);
}
else if(bits==24)
{
BYTE b0=(BYTE)(d>>16)&255;
BYTE b1=(BYTE)(d>>8)&255;
BYTE b2=(BYTE)(d)&255;
DWORD dw=(DWORD)b0 + ((DWORD)b1<<8) + ((DWORD)b2<<16);
return dw;
}
else if(bits==32)
{
BYTE b0=(BYTE)(d>>24)&255;
BYTE b1=(BYTE)(d>>16)&255;
BYTE b2=(BYTE)(d>>8)&255;
BYTE b3=(BYTE)(d)&255;
DWORD dw=(DWORD)b0 + ((DWORD)b1<<8) + ((DWORD)b2<<16) + ((DWORD)b3<<24);
return dw;
}

  else if(bits==32)
  {
		const int bytes=(int)(bits>>3);
		BYTE b[8];
		int i;
		BYTE *p=(BYTE *)d;
		for(i=0;i<bytes;i++)
		{
		
		  BYTE b0=(BYTE)(d>>24)&255;
		  BYTE b1=(BYTE)(d>>16)&255;
		  BYTE b2=(BYTE)(d>>8)&255;
		  BYTE b3=(BYTE)(d)&255;
		  DWORD dw=(DWORD)b0 + ((DWORD)b1<<8) + ((DWORD)b2<<16) + ((DWORD)b3<<24);
		  }
		  return *(DWORD *)tmp;
		  }
		  }
		  else
		  {
		  return d;
		  }
		  }
*/


CBSTR bstr_fns;

/*
DWORD changeEndian(DWORD d, int bits)
{
if(bits<=8)
{
return d;
}
else if(bits<=16)
{
return ((d&255)<<8) + ((d>>8)&255);
}
else if(bits<=24)
{
BYTE b0=(BYTE)(d>>16)&255;
BYTE b1=(BYTE)(d>>8)&255;
BYTE b2=(BYTE)(d)&255;
DWORD dw=(DWORD)b0 + ((DWORD)b1<<8) + ((DWORD)b2<<16);
return dw;
}
else if(bits<=32)
{
BYTE b0=(BYTE)(d>>24)&255;
BYTE b1=(BYTE)(d>>16)&255;
BYTE b2=(BYTE)(d>>8)&255;
BYTE b3=(BYTE)(d)&255;
DWORD dw=(DWORD)b0 + ((DWORD)b1<<8) + ((DWORD)b2<<16) + ((DWORD)b3<<24);
return dw;
}
else
{
return d;
}
}
*/


unsigned _int64 bitmask[64]={
	0x1,
		0x3,
		0x7,
		0xf,
		0x1f,
		0x3f,
		0x7f,
		0xff,
		0x1ff,
		0x3ff,
		0x7ff,
		0xfff,
		0x1fff,
		0x3fff,
		0x7fff,
		0xffff,
		0x1ffff,
		0x3ffff,
		0x7ffff,
		0xfffff,
		0x1fffff,
		0x3fffff,
		0x7fffff,
		0xffffff,
		0x1ffffff,
		0x3ffffff,
		0x7ffffff,
		0xfffffff,
		0x1fffffff,
		0x3fffffff,
		0x7fffffff,
		0xffffffff,
		0x1ffffffff,
		0x3ffffffff,
		0x7ffffffff,
		0xfffffffff,
		0x1fffffffff,
		0x3fffffffff,
		0x7fffffffff,
		0xffffffffff,
		0x1ffffffffff,
		0x3ffffffffff,
		0x7ffffffffff,
		0xfffffffffff,
		0x1fffffffffff,
		0x3fffffffffff,
		0x7fffffffffff,
		0xffffffffffff,
		0x1ffffffffffff,
		0x3ffffffffffff,
		0x7ffffffffffff,
		0xfffffffffffff,
		0x1fffffffffffff,
		0x3fffffffffffff,
		0x7fffffffffffff,
		0xffffffffffffff,
		0x1ffffffffffffff,
		0x3ffffffffffffff,
		0x7ffffffffffffff,
		0xfffffffffffffff,
		0x1fffffffffffffff,
		0x3fffffffffffffff,
		0x7fffffffffffffff,
		0xffffffffffffffff
};


STDMETHODIMP FrameSize(
					   BSTR strFrameDefinition,
					   long *pFrameSize
					   )
{
#ifdef _DEBUG
	printf("\nCTCPClient::FrameSize strFrameDefinition=%S pFrameSize=%ld\n",strFrameDefinition,pFrameSize);
#endif
	
	if(strFrameDefinition==NULL)
	{
		if(pFrameSize==NULL)
			return S_OK;
		else
		{
			*pFrameSize=0;
			return S_OK;
		}
	}
	
	//
	const int length=bstr_fns.sz_length(strFrameDefinition);
	wchar_t *p=strFrameDefinition;
	wchar_t *pend=strFrameDefinition+length;
#ifdef _DEBUG
	
	printf(" length=%d\n",length);
#endif
	
	long sum=0;
	if(strFrameDefinition!=NULL)
	{
		while(p<pend)
		{
			wchar_t *next;
			
			wchar_t c=*p++;
			int num=_wtoi(p);
			next=wcschr(p,' ');
			if(next==NULL) break;
			
			p=next+1;
			
			next=wcschr(p,',');
			if(next==NULL) p=pend; else p=next+1;
			
#ifdef _DEBUG
			printf("   c=%c num=%u\n",c,num);
#endif
			
			switch(c)
			{
			case '+':
				sum+=num;
				break;
			case 's':
				sum+=8*num;
				break;
			case 'u':
				sum+=16*num;
				break;
			case ' ':
			case '-':
				sum+=num;
				break;
			default:
				p=pend;
			}
		}
	}
	
#ifdef _DEBUG
	printf(" FrameSize=%ld (%f bytes)\n",sum,sum/8.0f);
#endif
	
	*pFrameSize=(long)sum;
	
	return S_OK;
}



STDMETHODIMP DecodeFrame(
						 BSTR strFrameDefinition,
						 BSTR strFieldName,
						 BSTR *pstrValue,
						 BSTR strFrame
						 )
{
#ifdef _DEBUG
	printf("\nCTCPClient::DecodeFrame strFrameDefinition=%S strFrame=%S strFieldName=%S pstrValue=%S\n",
		strFrameDefinition,strFrame,strFieldName,pstrValue);
#endif
	
	//
	if(strFrameDefinition==NULL || strFrame==NULL || strFieldName==NULL || pstrValue==NULL)
	{
		if(pstrValue==NULL)
			return S_OK;
		else
		{
			*pstrValue=SysAllocString(L"");
			return S_OK;
		}
	}
				
	//
	const int length=bstr_fns.sz_length(strFrameDefinition);
	wchar_t *p=strFrameDefinition;
	wchar_t *pend=strFrameDefinition+length;
				
#ifdef _DEBUG
	printf(" length=%d\n",length);
#endif
				
	long sum=0;
	while(p<pend)
	{
		wchar_t *next;
		
		wchar_t c=*p++;
		int num=_wtoi(p);
		next=wcschr(p,' ');
		if(next==NULL) break;
		
		p=next+1;
		
		wchar_t *fieldname=p;
		
		next=wcschr(p,',');
		int fieldname_length;
		if(next==NULL)
		{
			p=pend;
			fieldname_length=(int)(p-fieldname);
		}
		else
		{
			p=next+1;
			fieldname_length=(int)(p-fieldname-1);
		}
		
#ifdef _DEBUG
		{
			wchar_t *tmp=new wchar_t[fieldname_length+1];
			memcpy(tmp,fieldname,fieldname_length*2);
			*(tmp+fieldname_length)=L'\0';
			printf("  <# c=%c num=%u  fieldname_length=%d fieldname=%S\n",
				c,num,fieldname_length,tmp);
			delete[] tmp;
		}
#endif
		
		if(wcsncmp(strFieldName,fieldname,fieldname_length)==0)
		{
			const int byte_offset=(sum>>3);
			const bool aligned=((sum&7)==0);
			const int shift=sum&7;
			const int index=(num-1)&63;
#ifdef _DEBUG
			printf(" num   %u\n",num);
			printf(" byte_offset %u\n",byte_offset);
			printf(" aligned     %u\n",aligned);
			printf(" shift %u\n",shift);
			printf(" index %u\n",index);
			printf(" sum   %u\n",sum);
#endif
			
			BYTE *source=(BYTE *)strFrame;
			_int64 dd;
			_int64 d;
			wchar_t wbuffer[22];
			
			switch(c)
			{
			case ' ':
			case '-':
				dd=*(_int64 *)(source+byte_offset);
				d=(_int64)((dd>>shift)&bitmask[index]);
				_i64tow(d,wbuffer,10);
				*pstrValue=SysAllocString(wbuffer);
#ifdef _DEBUG
				printf(" bitmask   "); printbits(bitmask[index]);
				printf(" dd  "); printbits(dd);
				printf(" d   "); printbits(d);
				printf(" ####decode -%d %I64u %S\n",num,d,wbuffer);
#endif
				return S_OK;
			case '+':
				dd=*(_int64 *)(source+byte_offset);
				d=(_int64)((dd>>shift)&bitmask[index]);
				d=changeEndian(d,num);
				_i64tow(d,wbuffer,10);
				*pstrValue=SysAllocString(wbuffer);
#ifdef _DEBUG
				printf(" bitmask   "); printbits(bitmask[index]);
				printf(" dd  "); printbits(dd);
				printf(" d   "); printbits(d);
				printf(" ####decode +%d %I64u %S\n",num,d,wbuffer);
#endif
				return S_OK;
			case 's':
				{
					wchar_t *tmp=new wchar_t[num+1];
					if(tmp)
					{
						const int wlength=mbstowcs(tmp,(const char *)(source+byte_offset),num);
						*(tmp+num)=L'\0';
						*pstrValue=SysAllocString(tmp);
#ifdef _DEBUG
						printf(" ####decode s%d %S\n",num,tmp);
#endif
						delete[] tmp;
					}
				}
				return S_OK;
			case 'u':
				{
					wchar_t *tmp=new wchar_t[num+1];
					if(tmp)
					{
						wcsncpy(tmp,(const unsigned short*)(source+byte_offset),num);
						*(tmp+num)=L'\0';
						*pstrValue=SysAllocString(tmp);
#ifdef _DEBUG
						printf(" ####decode u%d %S\n",num,tmp);
#endif
						delete[] tmp;
					}
				}
				return S_OK;
			default:
				*pstrValue=SysAllocString(L"");
				return S_OK;
			}
			break;
		}
		
		switch(c)
		{
		case '+':
			sum+=num;
			break;
		case 's':
			sum+=8*num;
			break;
		case 'u':
			sum+=16*num;
			break;
		case ' ':
		case '-':
			sum+=num;
			break;
		default:
			p=pend;
		}
	}
	
#ifdef _DEBUG
	printf(" FrameSize=%ld (%f bytes)\n",sum,sum/8.0f);
#endif
	
	if(pstrValue) *pstrValue=SysAllocString(L"");
	
	return S_OK;
}



STDMETHODIMP EncodeFrame(
						 BSTR strFrameDefinition,
						 BSTR strFieldName,
						 BSTR strFieldValue,
						 BSTR strFrame,
						 BSTR *pstrFrame
						 )
{
#ifdef _DEBUG
	printf("\nCTCPClient::EncodeFrame strFrameDefinition=%S strFieldName=%S strFieldValue=%S strFrame=%S pstrFrame=%S\n",
		strFrameDefinition,strFieldName,strFieldValue,strFrame,pstrFrame);
#endif
	
	//
	if(strFrameDefinition==NULL || strFieldName==NULL || strFieldValue==NULL || strFrame==NULL || pstrFrame==NULL)
	{
		if(pstrFrame==NULL)
			return S_OK;
		else
		{
			*pstrFrame=SysAllocString(L"");
			return S_OK;
		}
	}
	
	//
	const int length=bstr_fns.sz_length(strFrameDefinition);
	wchar_t *p=strFrameDefinition;
	wchar_t *pend=strFrameDefinition+length;
	
#ifdef _DEBUG
	printf(" length=%d\n",length);
#endif
	
	//
	long framesize;
	FrameSize(strFrameDefinition,&framesize);
	const int framebytes=(framesize>>3)+(((framesize&7)==0)?0:1);
	BYTE *Frame=new BYTE[framebytes+2+sizeof(_int64)];
	if(Frame==NULL)
	{
		//memory allocation error
		return S_OK;
	}
	else
	{
		//
		memset(Frame,0,framebytes+2+sizeof(_int64));
		//
		const int strFrame_bytes=bstr_fns.bytes(strFrame);
		if(strFrame) memcpy(Frame,strFrame,(strFrame_bytes<=framebytes)?strFrame_bytes:framebytes);
		
		//
		long sum=0;
		while(p<pend)
		{
			wchar_t *next;
			
			wchar_t c=*p++;
			int num=_wtoi(p);
			next=wcschr(p,' ');
			if(next==NULL) break;
			
			p=next+1;
			
			wchar_t *fieldname=p;
			
			next=wcschr(p,',');
			int fieldname_length;
			if(next==NULL)
			{
				p=pend;
				fieldname_length=(int)(p-fieldname);
			}
			else
			{
				p=next+1;
				fieldname_length=(int)(p-fieldname-1);
			}
			
#ifdef _DEBUG
			{
				wchar_t *tmp=new wchar_t[fieldname_length+1];
				memcpy(tmp,fieldname,fieldname_length*2);
				*(tmp+fieldname_length)=L'\0';
				printf("  ># c=%c num=%u  fieldname_length=%d fieldname=%S\n",
					c,num,fieldname_length,tmp);
				delete[] tmp;
			}
#endif
			
			//
			if(wcsncmp(strFieldName,fieldname,fieldname_length)==0)
			{
				const int byte_offset=(sum>>3);
				const bool aligned=((sum&7)==0);
				const int shift=sum&7;
				const int index=(num-1)&63;
#ifdef _DEBUG
				printf(" num   %u\n",num);
				printf(" byte_offset %u\n",byte_offset);
				printf(" aligned     %u\n",aligned);
				printf(" shift %u\n",shift);
				printf(" index %u\n",index);
				printf(" sum   %u\n",sum);
#endif
				
				BYTE *destination=(BYTE *)Frame;
				_int64 dd;
				_int64 dd_stream;
				_int64 d;
				_int64 inverse_bitmask;
				
				switch(c)
				{
				case ' ':
				case '-':
					d=_wtoi(strFieldValue);
					dd_stream=*(_int64 *)(destination+byte_offset);
					inverse_bitmask=~(bitmask[index]<<shift);
#ifdef _DEBUG
					printf(" ####encode - %I64u\n",d);
					printf(" bitmask   "); printbits(bitmask[index]);
					printf("~bitmask   "); printbits(~bitmask[index]);
					printf("\n");
					printf(" inverse_bitmask "); printbits(inverse_bitmask);
					printf(" dd_stream "); printbits(dd_stream);
					printf("\n");
					printf(" dd  "); printbits(dd_stream&inverse_bitmask);
					printf(" d<<shift  "); printbits(d<<shift);
					printf(" out "); printbits((dd_stream&inverse_bitmask)|(d<<shift));
#endif
					dd=(dd_stream&inverse_bitmask)|(d<<shift);
					*(_int64 *)(destination+byte_offset)=dd;
					p=pend;
					break;
			case '+':
				d=changeEndian(_wtoi(strFieldValue),num);
				dd_stream=*(_int64 *)(destination+byte_offset);
				inverse_bitmask=~(bitmask[index]<<shift);
#ifdef _DEBUG
				printf(" ####encode + %I64u\n",d);
				printf(" bitmask   "); printbits(bitmask[index]);
				printf("~bitmask   "); printbits(~bitmask[index]);
				printf("\n");
				printf(" inverse_bitmask "); printbits(inverse_bitmask);
				printf(" dd_stream "); printbits(dd_stream);
				printf("\n");
				printf(" dd  "); printbits(dd_stream&inverse_bitmask);
				printf(" d<<shift  "); printbits(d<<shift);
				printf(" out "); printbits((dd_stream&inverse_bitmask)|(d<<shift));
#endif
				dd=(dd_stream&inverse_bitmask)|(d<<shift);
				*(_int64 *)(destination+byte_offset)=dd;
				p=pend;
				break;
			case 's':
				{
					char *tmp=new char[num];
					if(tmp)
					{
						const int wlength=wcstombs(tmp,strFieldValue,num);
						memset((char*)(destination+byte_offset),0,num);
						strncpy((char*)(destination+byte_offset),tmp,num);
#ifdef _DEBUG
						printf(" ####encode s %s\n",tmp);
#endif
						delete[] tmp;
					}
				}
				p=pend;
				break;
			case 'u':
				memset((char*)(destination+byte_offset),0,num*2);
				wcsncpy((unsigned short *)(destination+byte_offset),strFieldValue,num);
#ifdef _DEBUG
				printf(" ####encode u %S\n",strFieldValue);
#endif
				p=pend;
				break;
			}			
		}
		
		switch(c)
		{
		case '+':
			sum+=num;
			break;
		case 's':
			sum+=8*num;
			break;
		case 'u':
			sum+=16*num;
			break;
		case ' ':
		case '-':
			sum+=num;
			break;
		default:
			p=pend;
		}
	}
	
#ifdef _DEBUG
	printf(" FrameSize=%ld (%f bytes)\n",sum,sum/8.0f);
#endif
	
	if(pstrFrame) SysFreeString(*pstrFrame);
	*pstrFrame=::SysAllocStringByteLen((const char*)Frame,framebytes);
	
	delete[] Frame;
	}
	
	return S_OK;
}






//
int main(int argc, char* argv[])
{
	int i;
	
	//
	char *str0="This\0 is a test.\0Of Nulls.\n";
	wchar_t *wstr0=L"This\0 is a test.\0Of Nulls.\n";
	
	_bstr_t b(str0);
	
	printf(" wsclen=%d\n",wcslen(b));
	printf(" length=%d\n",b.length());
	
	int cbCount;
	cbCount = WideCharToMultiByte(CP_ACP, 0, b, -1, NULL, 0, NULL, NULL);
	printf(" WideCharToMultiByte=%d\n",cbCount);
	
	//
	BSTR bStr;
	bStr= SysAllocStringLen(wstr0,27);
	printf(" wsclen=%d\n",wcslen(bStr));
	printf(" length=%d\n",_bstr_t(bStr).length());
	cbCount = WideCharToMultiByte(CP_ACP, 0, bStr, -1, NULL, 0, NULL, NULL);
	printf(" WideCharToMultiByte=%d\n",cbCount);
		  
	unsigned long *ptr;
	ptr=(unsigned long *)bStr;
	ptr--;
	printf(" ptr=%u\n",ptr);
	printf(" *ptr=%u\n",*ptr);
		  
	printf(" bstr_length=%u\n",bstr_length(bStr));
		  
		  
	//
	CBSTR bstr;
	printf("CBSTR:: character_length=%u\n",bstr.character_length(bStr));
	printf("CBSTR:: bytes=%u\n",bstr.bytes(bStr));
	printf("CBSTR:: sz_length=%u\n",bstr.sz_length(bStr));
		  
	SysFreeString(bStr);
	bStr= NULL;
		  
		  
	////////////////////////////////////////////////////////////////////////////
		  
	for(i=0;i<=63;i++)
	{
		printf("%2d ",i); printbits(bitmask[i]);
	}
		  
		  
	for(i=8;i<=64;i+=8)
	{
		printf("%2d %16I64x %16I64x\n",i,(_int64)1,(_int64)changeEndian(1,i));
		printf("%2d %16I64x %16I64x\n",i,(_int64)255,(_int64)changeEndian(255,i));
		printf("%2d %16I64x %16I64x\n",i,(_int64)256,(_int64)changeEndian(256,i));
		printf("%2d %16I64x %16I64x\n",i,(_int64)65536,(_int64)changeEndian(65536,i));
		printf("%2d %16I64x %16I64x\n",i,(_int64)4294967295,(_int64)changeEndian(4294967295,i));
		printf("%2d %16I64x %16I64x\n",i,(_int64)4294967296,(_int64)changeEndian(4294967296,i));
		printf("\n");
	}
		  
		  
	{
		unsigned _int64 p=1L;
		for(i=0;i<=63;i++)
		{
			printf("%2d %22I64u %22I64x\n",i,p-1L,p-1L);
			p=p*2L;
		}
	}
	
	
	{
		unsigned _int64 p=1L;
		for(int i=0;i<=64;i++)
		{
			printf("0x%I64x,\n",p-1L);
			p=p*2L;
		}
	}
	
	
	////////////////////////////////////////////////////////////////////////////
	long pFrameSize=0;
	
	BSTR Frame=NULL; 
	Frame=SysAllocString(L"");
	
	BSTR bstrValue=NULL;
	
	BSTR lsntp=L"-2 LI,-3 VN,-3 Mode,-8 Stratum,-8 Poll,-8 Precision,-32 RootDelay,-32 RootDispersion,-64 ReferenceIdentifier,-64 ReferenceTimeStamp,-32 OriginateTimestamp,-64 ReceiveTimestamp,-64 TransmitTimestamp,s12 Authentication";
	BSTR	sntp=L"+2 LI,+3 VN,+3 Mode,+8 Stratum,+8 Poll,+8 Precision,+32 RootDelay,+32 RootDispersion,+64 ReferenceIdentifier,+64 ReferenceTimeStamp,+32 OriginateTimestamp,+64 ReceiveTimestamp,+64 TransmitTimestamp,s12 Authentication";
	
	
	//
	FrameSize(L"",&pFrameSize);
	
	FrameSize(L"+8",&pFrameSize);
	
	FrameSize(L"+8 ",&pFrameSize);
	
	FrameSize(L"+8 Mode",&pFrameSize);
	
	FrameSize(L"+8 Mode,-8 State",&pFrameSize);
	
	FrameSize(sntp,&pFrameSize);
	
	FrameSize(L"s1",&pFrameSize);
	
	FrameSize(L"s1 ",&pFrameSize);
	
	FrameSize(L"s1 myname",&pFrameSize);
	
	FrameSize(L"s20 Name,s20 Genre",&pFrameSize);
	
	FrameSize(L"u20 Name,u20 Genre",&pFrameSize);
	
	FrameSize(L"+2",&pFrameSize);
	
	
	//
	EncodeFrame(NULL,NULL,NULL,NULL,NULL);
	DecodeFrame(NULL,NULL,NULL,NULL);
	
	//
	EncodeFrame(L"",Frame,L"",L"",NULL);
	EncodeFrame(L"",Frame,L"",L"",&Frame);
	
	DecodeFrame(L"",L"",&bstrValue,Frame);
	
	
	//
	EncodeFrame(L"-8 Mode",L"Mode",L"1",Frame,&Frame);
	
	EncodeFrame(L"-16 Mode",L"Mode",L"1000",Frame,&Frame);
	DecodeFrame(L"-16 Mode",L"Mode",&bstrValue,Frame);
	
	EncodeFrame(L"+16 Mode",L"Mode",L"1000",Frame,&Frame);
	DecodeFrame(L"+16 Mode",L"Mode",&bstrValue,Frame);
	
	
	EncodeFrame(L"s20 Name,s20 Genre",L"Name",L"Blue Danube",Frame,&Frame);
	EncodeFrame(L"s20 Name,s20 Genre",L"Genre",L"Classical",Frame,&Frame);
	
	EncodeFrame(L"u20 Name,u20 Genre",L"Name",L"Blue Danube",Frame,&Frame);
	EncodeFrame(L"u20 Name,u20 Genre",L"Genre",L"Classical",Frame,&Frame);
	
	
	
	EncodeFrame(L"u20 Authentication",L"Authentication",L"My password is my tick",Frame,&Frame);
	DecodeFrame(L"u20 Authentication",L"Authentication",&bstrValue,Frame);
	
	EncodeFrame(L"u20 Authentication",L"Authentication",L"short",Frame,&Frame);
	DecodeFrame(L"u20 Authentication",L"Authentication",&bstrValue,Frame);
	
	
	EncodeFrame(lsntp,L"Stratum",L"6",Frame,&Frame);
	EncodeFrame(lsntp,L"VN",L"2",Frame,&Frame);
	EncodeFrame(lsntp,L"LI",L"1",Frame,&Frame);
	EncodeFrame(lsntp,L"Mode",L"3",Frame,&Frame);
	EncodeFrame(lsntp,L"RootDelay",L"255",Frame,&Frame);
	EncodeFrame(lsntp,L"Authentication",L"My password is my tick",Frame,&Frame);
	
	DecodeFrame(lsntp,L"LI",&bstrValue,Frame);
	DecodeFrame(lsntp,L"VN",&bstrValue,Frame);
	DecodeFrame(lsntp,L"Mode",&bstrValue,Frame);
	DecodeFrame(lsntp,L"Stratum",&bstrValue,Frame);
	DecodeFrame(lsntp,L"RootDelay",&bstrValue,Frame);
	DecodeFrame(lsntp,L"bogus",&bstrValue,Frame);
	DecodeFrame(lsntp,L"TransmitTimestamp",&bstrValue,Frame);
	DecodeFrame(lsntp,L"Authentication",&bstrValue,Frame);
	
	
	
	EncodeFrame(sntp,L"Stratum",L"6",Frame,&Frame);
	EncodeFrame(sntp,L"VN",L"2",Frame,&Frame);
	EncodeFrame(sntp,L"LI",L"1",Frame,&Frame);
	EncodeFrame(sntp,L"Mode",L"3",Frame,&Frame);
	EncodeFrame(sntp,L"RootDelay",L"255",Frame,&Frame);
	EncodeFrame(sntp,L"Authentication",L"My password is my tick",Frame,&Frame);
	
	DecodeFrame(sntp,L"LI",&bstrValue,Frame);
	DecodeFrame(sntp,L"VN",&bstrValue,Frame);
	DecodeFrame(sntp,L"Mode",&bstrValue,Frame);
	DecodeFrame(sntp,L"Stratum",&bstrValue,Frame);
	DecodeFrame(sntp,L"RootDelay",&bstrValue,Frame);
	DecodeFrame(sntp,L"bogus",&bstrValue,Frame);
	DecodeFrame(sntp,L"TransmitTimestamp",&bstrValue,Frame);
	DecodeFrame(sntp,L"Authentication",&bstrValue,Frame);
	
	return 0;
}
