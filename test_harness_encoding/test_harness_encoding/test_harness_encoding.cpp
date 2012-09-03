// test_harness_encoding.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

/*
// harness_encoding.cpp : Defines the entry point for the console application.
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

#include "..\tcpclientcom\EncodeDecode.h"

#include "..\tcpclientcom\Base64.h"
#include "..\tcpclientcom\UU.h"
#include "..\tcpclientcom\XX.h"
#include "..\tcpclientcom\Hex.h"
#include "..\tcpclientcom\Yenc.h"
#include "..\tcpclientcom\QuotedPrintable.h"
#include "..\tcpclientcom\MIME.h"

//
int main(int argc, char *argv[])
{
    
    // 
    // const char *longtext="THis is the test of something... THis is the test 
    // of something... THis is the test of something... THis is the test of
    // something... THis is the test of something... THis is the test of
    // something... THis is the test of something... THis is the test of
    // something... THis is the test of something... THis is the test of
    // something... \n";
    char *longtext = "This is a test of encoding and decoding functions for Base64, UU, XX and Hex.\r\nThis is a $ dollar sign and a\tTAB.\r\n";
    char *longtextend = (char *) longtext + strlen(longtext);
    
    printf(" longtext=\n%s\nlongtextend=%p\n\n\n", longtext, longtextend);
    
    char *enc = NULL;
    char *dec = NULL;
    int len = 0;
    int part = 0;
    int partsize=65536;
    
    char *infilename = new char[MAX_PATH];
    strcpy(infilename, "in.txt");
    
    char *outfilename = new char[MAX_PATH];
    strcpy(outfilename, "out.txt");
    
    // 
    CUU uu;
    CXX xx;
    CYenc yenc;
    CMIME mime;
    
    CHex hex;
    CBase64 base64;
    CQuotedPrintable qp;
    
    CEncodeDecode encodedecode;
    
    printf("\n\n\n\n************************************************\n");
    printf("\n\n\nNULLs\n\n");
    
    // 
    len = base64.encode_binary(NULL, 0, enc);
    len = base64.decode_binary(NULL, 0, dec);
    
    len = hex.encode_binary(NULL, 0, enc);
    len = hex.decode_binary(NULL, 0, dec);
    
    len = uu.encode_binary(NULL, 0, enc);
    len = uu.decode_binary(NULL, 0, dec);
    
    len = xx.encode_binary(NULL, 0, enc);
    len = xx.decode_binary(NULL, 0, dec);
    
    len = yenc.encode_binary(NULL, 0, enc);
    len = yenc.decode_binary(NULL, 0, dec);
    
    len = qp.encode_binary(NULL, 0, enc);
    len = qp.decode_binary(NULL, 0, dec);
    
    printf("\n\n\n\n************************************************\n");
    printf("\n\n\nencode/decode_binary\n\n");
    
    // 
    len = base64.encode_binary(longtext, longtextend, enc);
    len = base64.decode_binary(enc, enc+len, dec);
    
    // 
    len = hex.encode_binary(longtext, longtextend, enc);
    len = hex.decode_binary(enc, enc+len, dec);
    
    // 
    len = uu.encode_binary(longtext, longtextend, enc);
    len = uu.decode_binary(enc, enc+len, dec);
    
    // 
    len = xx.encode_binary(longtext, longtextend, enc);
    len = xx.decode_binary(enc, enc+len, dec);
    
    // 
    len = yenc.encode_binary(longtext, longtextend, enc);
    len = yenc.decode_binary(enc, enc+len, dec);
    
    // 
    len = qp.encode_binary(longtext, longtextend, enc);
    len = qp.decode_binary(enc, enc+len, dec);
    
    // 
    part=1;
    len = mime.encode(longtext, longtextend, enc, infilename, part, partsize);
    len = mime.decode(enc, enc+len, dec, outfilename, part, partsize);
    





    printf("\n\n\n\n************************************************\n");
    printf("\n\n\nfile uue/xxe's\n\n");
    // 
    {
        char *uue = NULL;
        int uue_length = 0;
        
        struct _stat statbuf;
        int result = _stat("noheader.uue", &statbuf);
        
        if (result == -1)
        {
            printf("_stat error\n");
        } else
        {
            printf(" File size     : %ld\n", statbuf.st_size);
            printf(" Drive         : %c:\n", statbuf.st_dev + 'A');
            printf(" Time modified : %s", ctime(&statbuf.st_atime));
            
            FILE *rh = fopen("noheader.uue", "rb");
            
            if (rh != NULL)
            {
                uue_length = (long) statbuf.st_size;
                
                uue = new char[uue_length + 1];
                
                if (uue)
                {
                    printf("\n**** reading %d byte file from disk....\n\n", uue_length);
                    
                    int numread = fread(uue, 1, uue_length, rh);
                    
                    *(uue + uue_length) = '\0';
                    
                    printf("uue_length=%ld\n", uue_length);
                    printf("numread=%d\n", numread);
                }
                fclose(rh);
         }
      }
      printf("uue=\n%s\n\n", uue);
      
      // 
      len = uu.decode_binary(uue, uue+uue_length, dec);
      len = uu.encode_binary(dec, dec+len, enc);
      len = uu.decode_binary(enc, enc+len, dec);
      
      // 
      len = xx.decode_binary(uue, uue+uue_length, dec);
      len = xx.encode_binary(dec, dec+len, enc);
      len = xx.decode_binary(enc, enc+len, dec);
      
      // 
      len = base64.decode_binary(uue, uue+uue_length, dec);
      len = base64.encode_binary(dec, dec+len, enc);
      len = base64.decode_binary(enc, enc+len, dec);
      
      // 
      len = hex.decode_binary(uue, uue+uue_length, dec);
      len = hex.encode_binary(dec, dec+len, enc);
      len = hex.decode_binary(enc, enc+len, dec);
   }
   
   printf("\n\n\n\n************************************************\n");
   printf("\n\n\nheader/filename/multiparts\n\n");
   // 
   {
       char *uue = NULL;
       int uue_length = 0;
       
       struct _stat statbuf;
       int result = _stat("header.uue", &statbuf);
       
       if (result == -1)
       {
           printf("_stat error\n");
       } else
       {
           printf(" File size     : %ld\n", statbuf.st_size);
           printf(" Drive         : %c:\n", statbuf.st_dev + 'A');
           printf(" Time modified : %s", ctime(&statbuf.st_atime));
           
           FILE *rh = fopen("header.uue", "rb");
           
           if (rh != NULL)
           {
               uue_length = (long) statbuf.st_size;
               
               uue = new char[uue_length + 1];
               
               if (uue)
               {
                   printf("\n**** reading %d byte file from disk....\n\n", uue_length);
                   
                   int numread = fread(uue, 1, uue_length, rh);
                   
                   *(uue + uue_length) = '\0';
                   
                   printf("uue_length=%ld\n", uue_length);
                   printf("numread=%d\n", numread);
               }
               fclose(rh);
         }
      }
      printf("uue=\n%s\n\n", uue);
      
      // 
      len = uu.decode(uue, uue+uue_length, dec, outfilename, part);
      len = uu.encode(dec, dec+len, enc, infilename, 1);
      len = uu.decode(enc, enc+len, dec, outfilename, part);
      
      // 
      len = xx.decode(uue, uue+uue_length, dec, outfilename, part);
      len = xx.encode(dec, dec+len, enc, infilename, 1);
      len = xx.decode(enc, enc+len, dec, outfilename, part);
   }
   
   printf("\n\n\n\n************************************************\n");
   printf("#########yenc decoder/encoder test\n\n");
   //
   {
       FILE *rh;
       char *uue = NULL;
       int uue_length = 0;
       
       struct _stat statbuf;
       int result = _stat("test.yenc", &statbuf);
       
       if (result == -1)
       {
           printf("_stat error\n");
       } else
       {
           printf(" File size     : %ld\n", statbuf.st_size);
           printf(" Drive         : %c:\n", statbuf.st_dev + 'A');
           printf(" Time modified : %s", ctime(&statbuf.st_atime));
           
           rh = fopen("test.yenc", "rb");
           if (rh != NULL)
           {
               uue_length = (long) statbuf.st_size;
               
               uue = new char[uue_length + 1];
               
               if (uue)
               {
                   printf("\n**** reading %d byte file from disk....\n\n", uue_length);
                   
                   int numread = fread(uue, 1, uue_length, rh);
                   
                   *(uue + uue_length) = '\0';
                   
                   printf("uue_length=%ld\n", uue_length);
                   printf("numread=%d\n", numread);
               }
               fclose(rh);
         }
      }
      // printf("uue=\n%s\n\n",uue);
      
      len = yenc.decode(uue, uue_length, dec, outfilename, part);
      rh = fopen(outfilename, "wb");
      if (rh != NULL)
      {
          printf("\n**** writing %d byte file to disk....\n\n", len);
          
          int numwrite = fwrite(dec, 1, len, rh);
          
          printf("numwrite=%d\n", numwrite);
          
          fclose(rh);
      }
      len = yenc.encode(dec, len, enc, infilename, 1);
      rh = fopen("test.reencoded.yenc", "wb");
      if (rh != NULL)
      {
          printf("\n**** writing %d byte file to disk....\n\n", len);
          
          int numwrite = fwrite(enc, 1, len, rh);
          
          printf("numwrite=%d\n", numwrite);
          
          fclose(rh);
      }
   }
   
   printf("\n\n\n\n************************************************\n");
   // 
   printf("\n\n\nencoding scheme\n\n");
   
   len = decodeencode.encode(CEncodeDecode::UU, longtext, longtextend, enc, infilename, part);
   len = decodeencode.decode(CEncodeDecode::UU, enc, len, dec, outfilename, part);
   
   len = decodeencode.encode(CEncodeDecode::XX, longtext, longtextend, enc, infilename, part);
   len = decodeencode.decode(CEncodeDecode::XX, enc, len, dec, outfilename, part);
   
   len = decodeencode.encode(CEncodeDecode::YENC, longtext, longtextend, enc, infilename, part);
   len = decodeencode.decode(CEncodeDecode::YENC, enc, len, dec, outfilename, part);
   
   len = decodeencode.encode(CEncodeDecode::MIME, longtext, longtextend, enc, infilename, part);
   len = decodeencode.decode(CEncodeDecode::MIME, enc, len, dec, outfilename, part);
   
   len = decodeencode.encode(CEncodeDecode::HEX, longtext, longtextend, enc, infilename, part);
   len = decodeencode.decode(CEncodeDecode::HEX, enc, len, dec, outfilename, part);
   
   len = decodeencode.encode(CEncodeDecode::BASE64, longtext, longtextend, enc, infilename, part);
   len = decodeencode.decode(CEncodeDecode::BASE64, enc, len, dec, outfilename, part);
   
   len = decodeencode.encode(CEncodeDecode::QUOTED_PRINTABLE, longtext, longtextend, enc, infilename, part);
   len = decodeencode.decode(CEncodeDecode::QUOTED_PRINTABLE, enc, len, dec, outfilename, part);
   
   printf("\n\n\n\n************************************************\n");
   
   // 
   delete[]enc;
   delete[]dec;
   
   delete[]outfilename;
   delete[]infilename;
   
   printf("fini.\n");
   return 0;
}
*/