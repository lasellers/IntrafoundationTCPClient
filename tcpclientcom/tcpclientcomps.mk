
tcpclientcomps.dll: dlldata.obj tcpclientcom_p.obj tcpclientcom_i.obj
	link /dll /out:tcpclientcomps.dll /def:tcpclientcomps.def /entry:DllMain dlldata.obj tcpclientcom_p.obj tcpclientcom_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del tcpclientcomps.dll
	@del tcpclientcomps.lib
	@del tcpclientcomps.exp
	@del dlldata.obj
	@del tcpclientcom_p.obj
	@del tcpclientcom_i.obj
