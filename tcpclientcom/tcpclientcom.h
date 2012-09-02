

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sat Sep 01 16:15:57 2012
 */
/* Compiler settings for tcpclientcom.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __tcpclientcom_h__
#define __tcpclientcom_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITCPClient_FWD_DEFINED__
#define __ITCPClient_FWD_DEFINED__
typedef interface ITCPClient ITCPClient;
#endif 	/* __ITCPClient_FWD_DEFINED__ */


#ifndef __TCPClient_FWD_DEFINED__
#define __TCPClient_FWD_DEFINED__

#ifdef __cplusplus
typedef class TCPClient TCPClient;
#else
typedef struct TCPClient TCPClient;
#endif /* __cplusplus */

#endif 	/* __TCPClient_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ITCPClient_INTERFACE_DEFINED__
#define __ITCPClient_INTERFACE_DEFINED__

/* interface ITCPClient */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ITCPClient;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EC07F724-40CC-4531-A27C-3AEE86650BD7")
    ITCPClient : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_thread( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_version( 
            /* [retval][out] */ BSTR *pstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_copyright( 
            /* [retval][out] */ BSTR *pstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_description( 
            /* [retval][out] */ BSTR *pstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_instance( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_instances( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Log( 
            /* [retval][out] */ BSTR *pstrText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearLog( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ BSTR strhost,
            /* [in] */ BSTR strport,
            /* [retval][out] */ long *pconnected) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Send( 
            /* [in] */ BSTR inText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Recv( 
            /* [retval][out] */ BSTR *poutText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendRN( 
            /* [in] */ BSTR inText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RecvRN( 
            /* [retval][out] */ BSTR *poutText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FlushRN( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendFile( 
            /* [in] */ BSTR strFilename) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RecvFile( 
            /* [in] */ BSTR strFilename) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RecvFileAppend( 
            /* [in] */ BSTR strFilename) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendCSV( 
            /* [in] */ BSTR inText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RecvCSV( 
            /* [retval][out] */ BSTR *poutText) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendFrame( 
            /* [in] */ BSTR strFrame,
            /* [in] */ long FrameSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RecvFrame( 
            /* [in] */ long FrameSize,
            /* [retval][out] */ BSTR *pstrFrame) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FrameSize( 
            /* [in] */ BSTR strFrameDefinition,
            /* [retval][out] */ long *pFrameSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EncodeFrame( 
            /* [in] */ BSTR strFrameDefinition,
            /* [in] */ BSTR strFieldName,
            /* [in] */ BSTR strFieldValue,
            /* [in] */ BSTR strFrame,
            /* [retval][out] */ BSTR *pstrFrame) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DecodeFrame( 
            /* [in] */ BSTR strFrameDefinition,
            /* [in] */ BSTR strFieldName,
            /* [in] */ BSTR strFrame,
            /* [retval][out] */ BSTR *pstrValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Hash( 
            /* [in] */ BSTR strHashType,
            /* [in] */ BSTR strInput,
            /* [retval][out] */ BSTR *pstrHash) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE HashFile( 
            /* [in] */ BSTR strHashType,
            /* [in] */ BSTR strFilename,
            /* [retval][out] */ BSTR *pstrHash) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_timeout( 
            /* [in] */ double secs) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_cutoff( 
            /* [in] */ long bytes) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_blocksize( 
            /* [in] */ long bytes) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_packetsize( 
            /* [in] */ long bytes) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_timeout( 
            /* [retval][out] */ double *psecs) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_cutoff( 
            /* [retval][out] */ long *pstatus) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_blocksize( 
            /* [retval][out] */ long *pbytes) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_packetsize( 
            /* [retval][out] */ long *pbytes) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_keepalives( 
            /* [in] */ long flag) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_nagledelay( 
            /* [in] */ long flag) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_is_connected( 
            /* [retval][out] */ long *pstatus) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_is_completed( 
            /* [retval][out] */ long *pstatus) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_is_cutoff( 
            /* [retval][out] */ long *pstatus) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_is_keepalives( 
            /* [retval][out] */ long *pstatus) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_is_nagledelay( 
            /* [retval][out] */ long *pstatus) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_last_timeout( 
            /* [retval][out] */ double *psecs) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_socket( 
            /* [retval][out] */ long *psock) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_local( 
            /* [retval][out] */ BSTR *pstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_remote( 
            /* [retval][out] */ BSTR *pstr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_bytessent( 
            /* [retval][out] */ long *pbytes) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_bytesreceived( 
            /* [retval][out] */ long *pbytes) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_byteslastsent( 
            /* [retval][out] */ long *pbytes) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_byteslastreceived( 
            /* [retval][out] */ long *pbytes) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_stack_recv_buffer( 
            /* [retval][out] */ long *pbytes) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_stack_send_buffer( 
            /* [retval][out] */ long *pbytes) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_send_packets( 
            /* [retval][out] */ long *pcount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_recv_packets( 
            /* [retval][out] */ long *pcount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_recv_faults( 
            /* [retval][out] */ long *pcount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_recvbuffer_faults( 
            /* [retval][out] */ long *pcount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_kbpssent( 
            /* [retval][out] */ double *pkbps) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_kbpsreceived( 
            /* [retval][out] */ double *pkbps) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_kbpslastsent( 
            /* [retval][out] */ double *pkbps) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_kbpslastreceived( 
            /* [retval][out] */ double *pkbps) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ping( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_mutex_locks( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_mutex_sleep( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_set_timeout( 
            /* [in] */ double secs) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_set_cutoff( 
            /* [in] */ long bytes) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_set_blocksize( 
            /* [in] */ long bytes) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_set_packetsize( 
            /* [in] */ long bytes) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_set_keepalives( 
            /* [in] */ long flag) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_set_nagledelay( 
            /* [in] */ long flag) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITCPClientVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITCPClient * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITCPClient * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITCPClient * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITCPClient * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITCPClient * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITCPClient * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITCPClient * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_thread )( 
            ITCPClient * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_version )( 
            ITCPClient * This,
            /* [retval][out] */ BSTR *pstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_copyright )( 
            ITCPClient * This,
            /* [retval][out] */ BSTR *pstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_description )( 
            ITCPClient * This,
            /* [retval][out] */ BSTR *pstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_instance )( 
            ITCPClient * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_instances )( 
            ITCPClient * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Log )( 
            ITCPClient * This,
            /* [retval][out] */ BSTR *pstrText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearLog )( 
            ITCPClient * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            ITCPClient * This,
            /* [in] */ BSTR strhost,
            /* [in] */ BSTR strport,
            /* [retval][out] */ long *pconnected);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            ITCPClient * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Send )( 
            ITCPClient * This,
            /* [in] */ BSTR inText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Recv )( 
            ITCPClient * This,
            /* [retval][out] */ BSTR *poutText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SendRN )( 
            ITCPClient * This,
            /* [in] */ BSTR inText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RecvRN )( 
            ITCPClient * This,
            /* [retval][out] */ BSTR *poutText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FlushRN )( 
            ITCPClient * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SendFile )( 
            ITCPClient * This,
            /* [in] */ BSTR strFilename);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RecvFile )( 
            ITCPClient * This,
            /* [in] */ BSTR strFilename);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RecvFileAppend )( 
            ITCPClient * This,
            /* [in] */ BSTR strFilename);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SendCSV )( 
            ITCPClient * This,
            /* [in] */ BSTR inText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RecvCSV )( 
            ITCPClient * This,
            /* [retval][out] */ BSTR *poutText);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SendFrame )( 
            ITCPClient * This,
            /* [in] */ BSTR strFrame,
            /* [in] */ long FrameSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RecvFrame )( 
            ITCPClient * This,
            /* [in] */ long FrameSize,
            /* [retval][out] */ BSTR *pstrFrame);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FrameSize )( 
            ITCPClient * This,
            /* [in] */ BSTR strFrameDefinition,
            /* [retval][out] */ long *pFrameSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EncodeFrame )( 
            ITCPClient * This,
            /* [in] */ BSTR strFrameDefinition,
            /* [in] */ BSTR strFieldName,
            /* [in] */ BSTR strFieldValue,
            /* [in] */ BSTR strFrame,
            /* [retval][out] */ BSTR *pstrFrame);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DecodeFrame )( 
            ITCPClient * This,
            /* [in] */ BSTR strFrameDefinition,
            /* [in] */ BSTR strFieldName,
            /* [in] */ BSTR strFrame,
            /* [retval][out] */ BSTR *pstrValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Hash )( 
            ITCPClient * This,
            /* [in] */ BSTR strHashType,
            /* [in] */ BSTR strInput,
            /* [retval][out] */ BSTR *pstrHash);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *HashFile )( 
            ITCPClient * This,
            /* [in] */ BSTR strHashType,
            /* [in] */ BSTR strFilename,
            /* [retval][out] */ BSTR *pstrHash);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_timeout )( 
            ITCPClient * This,
            /* [in] */ double secs);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_cutoff )( 
            ITCPClient * This,
            /* [in] */ long bytes);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_blocksize )( 
            ITCPClient * This,
            /* [in] */ long bytes);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_packetsize )( 
            ITCPClient * This,
            /* [in] */ long bytes);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_timeout )( 
            ITCPClient * This,
            /* [retval][out] */ double *psecs);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_cutoff )( 
            ITCPClient * This,
            /* [retval][out] */ long *pstatus);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_blocksize )( 
            ITCPClient * This,
            /* [retval][out] */ long *pbytes);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_packetsize )( 
            ITCPClient * This,
            /* [retval][out] */ long *pbytes);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_keepalives )( 
            ITCPClient * This,
            /* [in] */ long flag);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_nagledelay )( 
            ITCPClient * This,
            /* [in] */ long flag);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_is_connected )( 
            ITCPClient * This,
            /* [retval][out] */ long *pstatus);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_is_completed )( 
            ITCPClient * This,
            /* [retval][out] */ long *pstatus);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_is_cutoff )( 
            ITCPClient * This,
            /* [retval][out] */ long *pstatus);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_is_keepalives )( 
            ITCPClient * This,
            /* [retval][out] */ long *pstatus);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_is_nagledelay )( 
            ITCPClient * This,
            /* [retval][out] */ long *pstatus);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_last_timeout )( 
            ITCPClient * This,
            /* [retval][out] */ double *psecs);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_socket )( 
            ITCPClient * This,
            /* [retval][out] */ long *psock);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_local )( 
            ITCPClient * This,
            /* [retval][out] */ BSTR *pstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_remote )( 
            ITCPClient * This,
            /* [retval][out] */ BSTR *pstr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_bytessent )( 
            ITCPClient * This,
            /* [retval][out] */ long *pbytes);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_bytesreceived )( 
            ITCPClient * This,
            /* [retval][out] */ long *pbytes);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_byteslastsent )( 
            ITCPClient * This,
            /* [retval][out] */ long *pbytes);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_byteslastreceived )( 
            ITCPClient * This,
            /* [retval][out] */ long *pbytes);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_stack_recv_buffer )( 
            ITCPClient * This,
            /* [retval][out] */ long *pbytes);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_stack_send_buffer )( 
            ITCPClient * This,
            /* [retval][out] */ long *pbytes);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_send_packets )( 
            ITCPClient * This,
            /* [retval][out] */ long *pcount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_recv_packets )( 
            ITCPClient * This,
            /* [retval][out] */ long *pcount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_recv_faults )( 
            ITCPClient * This,
            /* [retval][out] */ long *pcount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_recvbuffer_faults )( 
            ITCPClient * This,
            /* [retval][out] */ long *pcount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_kbpssent )( 
            ITCPClient * This,
            /* [retval][out] */ double *pkbps);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_kbpsreceived )( 
            ITCPClient * This,
            /* [retval][out] */ double *pkbps);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_kbpslastsent )( 
            ITCPClient * This,
            /* [retval][out] */ double *pkbps);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_kbpslastreceived )( 
            ITCPClient * This,
            /* [retval][out] */ double *pkbps);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ping )( 
            ITCPClient * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_mutex_locks )( 
            ITCPClient * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_mutex_sleep )( 
            ITCPClient * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_set_timeout )( 
            ITCPClient * This,
            /* [in] */ double secs);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_set_cutoff )( 
            ITCPClient * This,
            /* [in] */ long bytes);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_set_blocksize )( 
            ITCPClient * This,
            /* [in] */ long bytes);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_set_packetsize )( 
            ITCPClient * This,
            /* [in] */ long bytes);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_set_keepalives )( 
            ITCPClient * This,
            /* [in] */ long flag);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_set_nagledelay )( 
            ITCPClient * This,
            /* [in] */ long flag);
        
        END_INTERFACE
    } ITCPClientVtbl;

    interface ITCPClient
    {
        CONST_VTBL struct ITCPClientVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITCPClient_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITCPClient_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITCPClient_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITCPClient_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITCPClient_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITCPClient_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITCPClient_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITCPClient_get_thread(This,pVal)	\
    ( (This)->lpVtbl -> get_thread(This,pVal) ) 

#define ITCPClient_get_version(This,pstr)	\
    ( (This)->lpVtbl -> get_version(This,pstr) ) 

#define ITCPClient_get_copyright(This,pstr)	\
    ( (This)->lpVtbl -> get_copyright(This,pstr) ) 

#define ITCPClient_get_description(This,pstr)	\
    ( (This)->lpVtbl -> get_description(This,pstr) ) 

#define ITCPClient_get_instance(This,pVal)	\
    ( (This)->lpVtbl -> get_instance(This,pVal) ) 

#define ITCPClient_get_instances(This,pVal)	\
    ( (This)->lpVtbl -> get_instances(This,pVal) ) 

#define ITCPClient_get_Log(This,pstrText)	\
    ( (This)->lpVtbl -> get_Log(This,pstrText) ) 

#define ITCPClient_ClearLog(This)	\
    ( (This)->lpVtbl -> ClearLog(This) ) 

#define ITCPClient_Open(This,strhost,strport,pconnected)	\
    ( (This)->lpVtbl -> Open(This,strhost,strport,pconnected) ) 

#define ITCPClient_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define ITCPClient_Send(This,inText)	\
    ( (This)->lpVtbl -> Send(This,inText) ) 

#define ITCPClient_Recv(This,poutText)	\
    ( (This)->lpVtbl -> Recv(This,poutText) ) 

#define ITCPClient_SendRN(This,inText)	\
    ( (This)->lpVtbl -> SendRN(This,inText) ) 

#define ITCPClient_RecvRN(This,poutText)	\
    ( (This)->lpVtbl -> RecvRN(This,poutText) ) 

#define ITCPClient_FlushRN(This)	\
    ( (This)->lpVtbl -> FlushRN(This) ) 

#define ITCPClient_SendFile(This,strFilename)	\
    ( (This)->lpVtbl -> SendFile(This,strFilename) ) 

#define ITCPClient_RecvFile(This,strFilename)	\
    ( (This)->lpVtbl -> RecvFile(This,strFilename) ) 

#define ITCPClient_RecvFileAppend(This,strFilename)	\
    ( (This)->lpVtbl -> RecvFileAppend(This,strFilename) ) 

#define ITCPClient_SendCSV(This,inText)	\
    ( (This)->lpVtbl -> SendCSV(This,inText) ) 

#define ITCPClient_RecvCSV(This,poutText)	\
    ( (This)->lpVtbl -> RecvCSV(This,poutText) ) 

#define ITCPClient_SendFrame(This,strFrame,FrameSize)	\
    ( (This)->lpVtbl -> SendFrame(This,strFrame,FrameSize) ) 

#define ITCPClient_RecvFrame(This,FrameSize,pstrFrame)	\
    ( (This)->lpVtbl -> RecvFrame(This,FrameSize,pstrFrame) ) 

#define ITCPClient_FrameSize(This,strFrameDefinition,pFrameSize)	\
    ( (This)->lpVtbl -> FrameSize(This,strFrameDefinition,pFrameSize) ) 

#define ITCPClient_EncodeFrame(This,strFrameDefinition,strFieldName,strFieldValue,strFrame,pstrFrame)	\
    ( (This)->lpVtbl -> EncodeFrame(This,strFrameDefinition,strFieldName,strFieldValue,strFrame,pstrFrame) ) 

#define ITCPClient_DecodeFrame(This,strFrameDefinition,strFieldName,strFrame,pstrValue)	\
    ( (This)->lpVtbl -> DecodeFrame(This,strFrameDefinition,strFieldName,strFrame,pstrValue) ) 

#define ITCPClient_Hash(This,strHashType,strInput,pstrHash)	\
    ( (This)->lpVtbl -> Hash(This,strHashType,strInput,pstrHash) ) 

#define ITCPClient_HashFile(This,strHashType,strFilename,pstrHash)	\
    ( (This)->lpVtbl -> HashFile(This,strHashType,strFilename,pstrHash) ) 

#define ITCPClient_put_timeout(This,secs)	\
    ( (This)->lpVtbl -> put_timeout(This,secs) ) 

#define ITCPClient_put_cutoff(This,bytes)	\
    ( (This)->lpVtbl -> put_cutoff(This,bytes) ) 

#define ITCPClient_put_blocksize(This,bytes)	\
    ( (This)->lpVtbl -> put_blocksize(This,bytes) ) 

#define ITCPClient_put_packetsize(This,bytes)	\
    ( (This)->lpVtbl -> put_packetsize(This,bytes) ) 

#define ITCPClient_get_timeout(This,psecs)	\
    ( (This)->lpVtbl -> get_timeout(This,psecs) ) 

#define ITCPClient_get_cutoff(This,pstatus)	\
    ( (This)->lpVtbl -> get_cutoff(This,pstatus) ) 

#define ITCPClient_get_blocksize(This,pbytes)	\
    ( (This)->lpVtbl -> get_blocksize(This,pbytes) ) 

#define ITCPClient_get_packetsize(This,pbytes)	\
    ( (This)->lpVtbl -> get_packetsize(This,pbytes) ) 

#define ITCPClient_put_keepalives(This,flag)	\
    ( (This)->lpVtbl -> put_keepalives(This,flag) ) 

#define ITCPClient_put_nagledelay(This,flag)	\
    ( (This)->lpVtbl -> put_nagledelay(This,flag) ) 

#define ITCPClient_get_is_connected(This,pstatus)	\
    ( (This)->lpVtbl -> get_is_connected(This,pstatus) ) 

#define ITCPClient_get_is_completed(This,pstatus)	\
    ( (This)->lpVtbl -> get_is_completed(This,pstatus) ) 

#define ITCPClient_get_is_cutoff(This,pstatus)	\
    ( (This)->lpVtbl -> get_is_cutoff(This,pstatus) ) 

#define ITCPClient_get_is_keepalives(This,pstatus)	\
    ( (This)->lpVtbl -> get_is_keepalives(This,pstatus) ) 

#define ITCPClient_get_is_nagledelay(This,pstatus)	\
    ( (This)->lpVtbl -> get_is_nagledelay(This,pstatus) ) 

#define ITCPClient_get_last_timeout(This,psecs)	\
    ( (This)->lpVtbl -> get_last_timeout(This,psecs) ) 

#define ITCPClient_get_socket(This,psock)	\
    ( (This)->lpVtbl -> get_socket(This,psock) ) 

#define ITCPClient_get_local(This,pstr)	\
    ( (This)->lpVtbl -> get_local(This,pstr) ) 

#define ITCPClient_get_remote(This,pstr)	\
    ( (This)->lpVtbl -> get_remote(This,pstr) ) 

#define ITCPClient_get_bytessent(This,pbytes)	\
    ( (This)->lpVtbl -> get_bytessent(This,pbytes) ) 

#define ITCPClient_get_bytesreceived(This,pbytes)	\
    ( (This)->lpVtbl -> get_bytesreceived(This,pbytes) ) 

#define ITCPClient_get_byteslastsent(This,pbytes)	\
    ( (This)->lpVtbl -> get_byteslastsent(This,pbytes) ) 

#define ITCPClient_get_byteslastreceived(This,pbytes)	\
    ( (This)->lpVtbl -> get_byteslastreceived(This,pbytes) ) 

#define ITCPClient_get_stack_recv_buffer(This,pbytes)	\
    ( (This)->lpVtbl -> get_stack_recv_buffer(This,pbytes) ) 

#define ITCPClient_get_stack_send_buffer(This,pbytes)	\
    ( (This)->lpVtbl -> get_stack_send_buffer(This,pbytes) ) 

#define ITCPClient_get_send_packets(This,pcount)	\
    ( (This)->lpVtbl -> get_send_packets(This,pcount) ) 

#define ITCPClient_get_recv_packets(This,pcount)	\
    ( (This)->lpVtbl -> get_recv_packets(This,pcount) ) 

#define ITCPClient_get_recv_faults(This,pcount)	\
    ( (This)->lpVtbl -> get_recv_faults(This,pcount) ) 

#define ITCPClient_get_recvbuffer_faults(This,pcount)	\
    ( (This)->lpVtbl -> get_recvbuffer_faults(This,pcount) ) 

#define ITCPClient_get_kbpssent(This,pkbps)	\
    ( (This)->lpVtbl -> get_kbpssent(This,pkbps) ) 

#define ITCPClient_get_kbpsreceived(This,pkbps)	\
    ( (This)->lpVtbl -> get_kbpsreceived(This,pkbps) ) 

#define ITCPClient_get_kbpslastsent(This,pkbps)	\
    ( (This)->lpVtbl -> get_kbpslastsent(This,pkbps) ) 

#define ITCPClient_get_kbpslastreceived(This,pkbps)	\
    ( (This)->lpVtbl -> get_kbpslastreceived(This,pkbps) ) 

#define ITCPClient_get_ping(This,pVal)	\
    ( (This)->lpVtbl -> get_ping(This,pVal) ) 

#define ITCPClient_get_mutex_locks(This,pVal)	\
    ( (This)->lpVtbl -> get_mutex_locks(This,pVal) ) 

#define ITCPClient_get_mutex_sleep(This,pVal)	\
    ( (This)->lpVtbl -> get_mutex_sleep(This,pVal) ) 

#define ITCPClient_put_set_timeout(This,secs)	\
    ( (This)->lpVtbl -> put_set_timeout(This,secs) ) 

#define ITCPClient_put_set_cutoff(This,bytes)	\
    ( (This)->lpVtbl -> put_set_cutoff(This,bytes) ) 

#define ITCPClient_put_set_blocksize(This,bytes)	\
    ( (This)->lpVtbl -> put_set_blocksize(This,bytes) ) 

#define ITCPClient_put_set_packetsize(This,bytes)	\
    ( (This)->lpVtbl -> put_set_packetsize(This,bytes) ) 

#define ITCPClient_put_set_keepalives(This,flag)	\
    ( (This)->lpVtbl -> put_set_keepalives(This,flag) ) 

#define ITCPClient_put_set_nagledelay(This,flag)	\
    ( (This)->lpVtbl -> put_set_nagledelay(This,flag) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITCPClient_INTERFACE_DEFINED__ */



#ifndef __TCPCLIENTCOMLib_LIBRARY_DEFINED__
#define __TCPCLIENTCOMLib_LIBRARY_DEFINED__

/* library TCPCLIENTCOMLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_TCPCLIENTCOMLib;

EXTERN_C const CLSID CLSID_TCPClient;

#ifdef __cplusplus

class DECLSPEC_UUID("B2C4E855-870B-4B6E-8C3C-9910CDC3C1C7")
TCPClient;
#endif
#endif /* __TCPCLIENTCOMLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


