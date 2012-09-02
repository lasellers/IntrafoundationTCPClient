# Microsoft Developer Studio Generated NMAKE File, Based on tcpclientcom.dsp
!IF "$(CFG)" == ""
CFG=tcpclientcom - Win32 Debug
!MESSAGE No configuration specified. Defaulting to tcpclientcom - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "tcpclientcom - Win32 Debug" && "$(CFG)" != "tcpclientcom - Win32 Unicode Debug" && "$(CFG)" != "tcpclientcom - Win32 Release MinSize" && "$(CFG)" != "tcpclientcom - Win32 Release MinDependency" && "$(CFG)" != "tcpclientcom - Win32 Unicode Release MinSize" && "$(CFG)" != "tcpclientcom - Win32 Unicode Release MinDependency"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "tcpclientcom.mak" CFG="tcpclientcom - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "tcpclientcom - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "tcpclientcom - Win32 Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "tcpclientcom - Win32 Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "tcpclientcom - Win32 Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "tcpclientcom - Win32 Unicode Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "tcpclientcom - Win32 Unicode Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "tcpclientcom - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\tcpclientcom.dll" ".\tcpclientcom.tlb" ".\tcpclientcom.h" ".\tcpclientcom_i.c" ".\Debug\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\BSTR.obj"
	-@erase "$(INTDIR)\DES.obj"
	-@erase "$(INTDIR)\Log.obj"
	-@erase "$(INTDIR)\MD5.obj"
	-@erase "$(INTDIR)\Mutex.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\tcp.obj"
	-@erase "$(INTDIR)\TCPClient.obj"
	-@erase "$(INTDIR)\tcpclientcom.obj"
	-@erase "$(INTDIR)\tcpclientcom.pch"
	-@erase "$(INTDIR)\tcpclientcom.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\tcpclientcom.dll"
	-@erase "$(OUTDIR)\tcpclientcom.exp"
	-@erase "$(OUTDIR)\tcpclientcom.ilk"
	-@erase "$(OUTDIR)\tcpclientcom.lib"
	-@erase "$(OUTDIR)\tcpclientcom.pdb"
	-@erase ".\tcpclientcom.h"
	-@erase ".\tcpclientcom.tlb"
	-@erase ".\tcpclientcom_i.c"
	-@erase ".\Debug\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\tcpclientcom.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\tcpclientcom.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\tcpclientcom.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ws2_32.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\tcpclientcom.pdb" /debug /machine:I386 /def:".\tcpclientcom.def" /out:"$(OUTDIR)\tcpclientcom.dll" /implib:"$(OUTDIR)\tcpclientcom.lib" /pdbtype:sept 
DEF_FILE= \
	".\tcpclientcom.def"
LINK32_OBJS= \
	"$(INTDIR)\BSTR.obj" \
	"$(INTDIR)\Log.obj" \
	"$(INTDIR)\MD5.obj" \
	"$(INTDIR)\Mutex.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\tcp.obj" \
	"$(INTDIR)\TCPClient.obj" \
	"$(INTDIR)\tcpclientcom.obj" \
	"$(INTDIR)\tcpclientcom.res" \
	"$(INTDIR)\DES.obj"

"$(OUTDIR)\tcpclientcom.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\Debug
TargetPath=.\Debug\tcpclientcom.dll
InputPath=.\Debug\tcpclientcom.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "tcpclientcom - Win32 Unicode Debug"

OUTDIR=.\DebugU
INTDIR=.\DebugU
# Begin Custom Macros
OutDir=.\DebugU
# End Custom Macros

ALL : "$(OUTDIR)\tcpclientcom.dll" ".\tcpclientcom.tlb" ".\tcpclientcom.h" ".\tcpclientcom_i.c" ".\DebugU\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\BSTR.obj"
	-@erase "$(INTDIR)\DES.obj"
	-@erase "$(INTDIR)\Log.obj"
	-@erase "$(INTDIR)\MD5.obj"
	-@erase "$(INTDIR)\Mutex.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\tcp.obj"
	-@erase "$(INTDIR)\TCPClient.obj"
	-@erase "$(INTDIR)\tcpclientcom.obj"
	-@erase "$(INTDIR)\tcpclientcom.pch"
	-@erase "$(INTDIR)\tcpclientcom.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\tcpclientcom.dll"
	-@erase "$(OUTDIR)\tcpclientcom.exp"
	-@erase "$(OUTDIR)\tcpclientcom.ilk"
	-@erase "$(OUTDIR)\tcpclientcom.lib"
	-@erase "$(OUTDIR)\tcpclientcom.pdb"
	-@erase ".\tcpclientcom.h"
	-@erase ".\tcpclientcom.tlb"
	-@erase ".\tcpclientcom_i.c"
	-@erase ".\DebugU\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\tcpclientcom.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\tcpclientcom.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\tcpclientcom.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ws2_32.lib /nologo /subsystem:windows /verbose /dll /incremental:yes /pdb:"$(OUTDIR)\tcpclientcom.pdb" /debug /machine:I386 /def:".\tcpclientcom.def" /out:"$(OUTDIR)\tcpclientcom.dll" /implib:"$(OUTDIR)\tcpclientcom.lib" /pdbtype:sept 
DEF_FILE= \
	".\tcpclientcom.def"
LINK32_OBJS= \
	"$(INTDIR)\BSTR.obj" \
	"$(INTDIR)\Log.obj" \
	"$(INTDIR)\MD5.obj" \
	"$(INTDIR)\Mutex.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\tcp.obj" \
	"$(INTDIR)\TCPClient.obj" \
	"$(INTDIR)\tcpclientcom.obj" \
	"$(INTDIR)\tcpclientcom.res" \
	"$(INTDIR)\DES.obj"

"$(OUTDIR)\tcpclientcom.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\DebugU
TargetPath=.\DebugU\tcpclientcom.dll
InputPath=.\DebugU\tcpclientcom.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	if "%OS%"=="" goto NOTNT 
	if not "%OS%"=="Windows_NT" goto NOTNT 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	goto end 
	:NOTNT 
	echo Warning : Cannot register Unicode DLL on Windows 95 
	:end 
<< 
	

!ELSEIF  "$(CFG)" == "tcpclientcom - Win32 Release MinSize"

OUTDIR=.\ReleaseMinSize
INTDIR=.\ReleaseMinSize
# Begin Custom Macros
OutDir=.\ReleaseMinSize
# End Custom Macros

ALL : "$(OUTDIR)\tcpclientcom.dll" ".\tcpclientcom.tlb" ".\tcpclientcom.h" ".\tcpclientcom_i.c" ".\ReleaseMinSize\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\BSTR.obj"
	-@erase "$(INTDIR)\DES.obj"
	-@erase "$(INTDIR)\Log.obj"
	-@erase "$(INTDIR)\MD5.obj"
	-@erase "$(INTDIR)\Mutex.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\tcp.obj"
	-@erase "$(INTDIR)\TCPClient.obj"
	-@erase "$(INTDIR)\tcpclientcom.obj"
	-@erase "$(INTDIR)\tcpclientcom.pch"
	-@erase "$(INTDIR)\tcpclientcom.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\tcpclientcom.dll"
	-@erase "$(OUTDIR)\tcpclientcom.exp"
	-@erase "$(OUTDIR)\tcpclientcom.lib"
	-@erase ".\tcpclientcom.h"
	-@erase ".\tcpclientcom.tlb"
	-@erase ".\tcpclientcom_i.c"
	-@erase ".\ReleaseMinSize\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Fp"$(INTDIR)\tcpclientcom.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\tcpclientcom.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\tcpclientcom.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ws2_32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\tcpclientcom.pdb" /machine:I386 /def:".\tcpclientcom.def" /out:"$(OUTDIR)\tcpclientcom.dll" /implib:"$(OUTDIR)\tcpclientcom.lib" 
DEF_FILE= \
	".\tcpclientcom.def"
LINK32_OBJS= \
	"$(INTDIR)\BSTR.obj" \
	"$(INTDIR)\Log.obj" \
	"$(INTDIR)\MD5.obj" \
	"$(INTDIR)\Mutex.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\tcp.obj" \
	"$(INTDIR)\TCPClient.obj" \
	"$(INTDIR)\tcpclientcom.obj" \
	"$(INTDIR)\tcpclientcom.res" \
	"$(INTDIR)\DES.obj"

"$(OUTDIR)\tcpclientcom.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseMinSize
TargetPath=.\ReleaseMinSize\tcpclientcom.dll
InputPath=.\ReleaseMinSize\tcpclientcom.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "tcpclientcom - Win32 Release MinDependency"

OUTDIR=.\ReleaseMinDependency
INTDIR=.\ReleaseMinDependency
# Begin Custom Macros
OutDir=.\ReleaseMinDependency
# End Custom Macros

ALL : "$(OUTDIR)\tcpclientcom.dll" ".\tcpclientcom.tlb" ".\tcpclientcom.h" ".\tcpclientcom_i.c" ".\ReleaseMinDependency\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\BSTR.obj"
	-@erase "$(INTDIR)\DES.obj"
	-@erase "$(INTDIR)\Log.obj"
	-@erase "$(INTDIR)\MD5.obj"
	-@erase "$(INTDIR)\Mutex.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\tcp.obj"
	-@erase "$(INTDIR)\TCPClient.obj"
	-@erase "$(INTDIR)\tcpclientcom.obj"
	-@erase "$(INTDIR)\tcpclientcom.pch"
	-@erase "$(INTDIR)\tcpclientcom.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\tcpclientcom.dll"
	-@erase "$(OUTDIR)\tcpclientcom.exp"
	-@erase "$(OUTDIR)\tcpclientcom.lib"
	-@erase ".\tcpclientcom.h"
	-@erase ".\tcpclientcom.tlb"
	-@erase ".\tcpclientcom_i.c"
	-@erase ".\ReleaseMinDependency\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Fp"$(INTDIR)\tcpclientcom.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\tcpclientcom.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\tcpclientcom.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ws2_32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\tcpclientcom.pdb" /machine:I386 /def:".\tcpclientcom.def" /out:"$(OUTDIR)\tcpclientcom.dll" /implib:"$(OUTDIR)\tcpclientcom.lib" 
DEF_FILE= \
	".\tcpclientcom.def"
LINK32_OBJS= \
	"$(INTDIR)\BSTR.obj" \
	"$(INTDIR)\Log.obj" \
	"$(INTDIR)\MD5.obj" \
	"$(INTDIR)\Mutex.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\tcp.obj" \
	"$(INTDIR)\TCPClient.obj" \
	"$(INTDIR)\tcpclientcom.obj" \
	"$(INTDIR)\tcpclientcom.res" \
	"$(INTDIR)\DES.obj"

"$(OUTDIR)\tcpclientcom.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseMinDependency
TargetPath=.\ReleaseMinDependency\tcpclientcom.dll
InputPath=.\ReleaseMinDependency\tcpclientcom.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
<< 
	

!ELSEIF  "$(CFG)" == "tcpclientcom - Win32 Unicode Release MinSize"

OUTDIR=.\ReleaseUMinSize
INTDIR=.\ReleaseUMinSize
# Begin Custom Macros
OutDir=.\ReleaseUMinSize
# End Custom Macros

ALL : "$(OUTDIR)\tcpclientcom.dll" ".\tcpclientcom.tlb" ".\tcpclientcom.h" ".\tcpclientcom_i.c" ".\ReleaseUMinSize\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\BSTR.obj"
	-@erase "$(INTDIR)\DES.obj"
	-@erase "$(INTDIR)\Log.obj"
	-@erase "$(INTDIR)\MD5.obj"
	-@erase "$(INTDIR)\Mutex.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\tcp.obj"
	-@erase "$(INTDIR)\TCPClient.obj"
	-@erase "$(INTDIR)\tcpclientcom.obj"
	-@erase "$(INTDIR)\tcpclientcom.pch"
	-@erase "$(INTDIR)\tcpclientcom.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\tcpclientcom.dll"
	-@erase "$(OUTDIR)\tcpclientcom.exp"
	-@erase "$(OUTDIR)\tcpclientcom.lib"
	-@erase ".\tcpclientcom.h"
	-@erase ".\tcpclientcom.tlb"
	-@erase ".\tcpclientcom_i.c"
	-@erase ".\ReleaseUMinSize\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Fp"$(INTDIR)\tcpclientcom.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\tcpclientcom.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\tcpclientcom.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ws2_32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\tcpclientcom.pdb" /machine:I386 /def:".\tcpclientcom.def" /out:"$(OUTDIR)\tcpclientcom.dll" /implib:"$(OUTDIR)\tcpclientcom.lib" 
DEF_FILE= \
	".\tcpclientcom.def"
LINK32_OBJS= \
	"$(INTDIR)\BSTR.obj" \
	"$(INTDIR)\Log.obj" \
	"$(INTDIR)\MD5.obj" \
	"$(INTDIR)\Mutex.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\tcp.obj" \
	"$(INTDIR)\TCPClient.obj" \
	"$(INTDIR)\tcpclientcom.obj" \
	"$(INTDIR)\tcpclientcom.res" \
	"$(INTDIR)\DES.obj"

"$(OUTDIR)\tcpclientcom.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseUMinSize
TargetPath=.\ReleaseUMinSize\tcpclientcom.dll
InputPath=.\ReleaseUMinSize\tcpclientcom.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	if "%OS%"=="" goto NOTNT 
	if not "%OS%"=="Windows_NT" goto NOTNT 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	goto end 
	:NOTNT 
	echo Warning : Cannot register Unicode DLL on Windows 95 
	:end 
<< 
	

!ELSEIF  "$(CFG)" == "tcpclientcom - Win32 Unicode Release MinDependency"

OUTDIR=.\ReleaseUMinDependency
INTDIR=.\ReleaseUMinDependency
# Begin Custom Macros
OutDir=.\ReleaseUMinDependency
# End Custom Macros

ALL : "$(OUTDIR)\tcpclientcom.dll" ".\tcpclientcom.tlb" ".\tcpclientcom.h" ".\tcpclientcom_i.c" ".\ReleaseUMinDependency\regsvr32.trg"


CLEAN :
	-@erase "$(INTDIR)\BSTR.obj"
	-@erase "$(INTDIR)\DES.obj"
	-@erase "$(INTDIR)\Log.obj"
	-@erase "$(INTDIR)\MD5.obj"
	-@erase "$(INTDIR)\Mutex.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\tcp.obj"
	-@erase "$(INTDIR)\TCPClient.obj"
	-@erase "$(INTDIR)\tcpclientcom.obj"
	-@erase "$(INTDIR)\tcpclientcom.pch"
	-@erase "$(INTDIR)\tcpclientcom.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\tcpclientcom.dll"
	-@erase "$(OUTDIR)\tcpclientcom.exp"
	-@erase "$(OUTDIR)\tcpclientcom.lib"
	-@erase ".\tcpclientcom.h"
	-@erase ".\tcpclientcom.tlb"
	-@erase ".\tcpclientcom_i.c"
	-@erase ".\ReleaseUMinDependency\regsvr32.trg"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\tcpclientcom.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\tcpclientcom.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\tcpclientcom.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ws2_32.lib /nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\tcpclientcom.pdb" /machine:I386 /def:".\tcpclientcom.def" /out:"$(OUTDIR)\tcpclientcom.dll" /implib:"$(OUTDIR)\tcpclientcom.lib" 
DEF_FILE= \
	".\tcpclientcom.def"
LINK32_OBJS= \
	"$(INTDIR)\BSTR.obj" \
	"$(INTDIR)\Log.obj" \
	"$(INTDIR)\MD5.obj" \
	"$(INTDIR)\Mutex.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\tcp.obj" \
	"$(INTDIR)\TCPClient.obj" \
	"$(INTDIR)\tcpclientcom.obj" \
	"$(INTDIR)\tcpclientcom.res" \
	"$(INTDIR)\DES.obj"

"$(OUTDIR)\tcpclientcom.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

OutDir=.\ReleaseUMinDependency
TargetPath=.\ReleaseUMinDependency\tcpclientcom.dll
InputPath=.\ReleaseUMinDependency\tcpclientcom.dll
SOURCE="$(InputPath)"

"$(OUTDIR)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	if "%OS%"=="" goto NOTNT 
	if not "%OS%"=="Windows_NT" goto NOTNT 
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	goto end 
	:NOTNT 
	echo Warning : Cannot register Unicode DLL on Windows 95 
	:end 
<< 
	

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL_PROJ=

!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("tcpclientcom.dep")
!INCLUDE "tcpclientcom.dep"
!ELSE 
!MESSAGE Warning: cannot find "tcpclientcom.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "tcpclientcom - Win32 Debug" || "$(CFG)" == "tcpclientcom - Win32 Unicode Debug" || "$(CFG)" == "tcpclientcom - Win32 Release MinSize" || "$(CFG)" == "tcpclientcom - Win32 Release MinDependency" || "$(CFG)" == "tcpclientcom - Win32 Unicode Release MinSize" || "$(CFG)" == "tcpclientcom - Win32 Unicode Release MinDependency"
SOURCE=.\BSTR.cpp

"$(INTDIR)\BSTR.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tcpclientcom.pch"


SOURCE=.\DES.cpp

"$(INTDIR)\DES.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tcpclientcom.pch"


SOURCE=.\Log.cpp

"$(INTDIR)\Log.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tcpclientcom.pch"


SOURCE=.\MD5.cpp

"$(INTDIR)\MD5.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tcpclientcom.pch"


SOURCE=.\Mutex.cpp

"$(INTDIR)\Mutex.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tcpclientcom.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "tcpclientcom - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\tcpclientcom.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\tcpclientcom.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "tcpclientcom - Win32 Unicode Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /Fp"$(INTDIR)\tcpclientcom.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\tcpclientcom.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "tcpclientcom - Win32 Release MinSize"

CPP_SWITCHES=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Fp"$(INTDIR)\tcpclientcom.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\tcpclientcom.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "tcpclientcom - Win32 Release MinDependency"

CPP_SWITCHES=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_STATIC_REGISTRY" /D "_ATL_MIN_CRT" /Fp"$(INTDIR)\tcpclientcom.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\tcpclientcom.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "tcpclientcom - Win32 Unicode Release MinSize"

CPP_SWITCHES=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Fp"$(INTDIR)\tcpclientcom.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\tcpclientcom.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "tcpclientcom - Win32 Unicode Release MinDependency"

CPP_SWITCHES=/nologo /MT /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "_UNICODE" /D "_ATL_STATIC_REGISTRY" /Fp"$(INTDIR)\tcpclientcom.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\tcpclientcom.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\tcp.cpp

"$(INTDIR)\tcp.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tcpclientcom.pch"


SOURCE=.\TCPClient.cpp

"$(INTDIR)\TCPClient.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tcpclientcom.pch"


SOURCE=.\tcpclientcom.cpp

"$(INTDIR)\tcpclientcom.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\tcpclientcom.pch"


SOURCE=.\tcpclientcom.idl
MTL_SWITCHES=/tlb ".\tcpclientcom.tlb" /h "tcpclientcom.h" /iid "tcpclientcom_i.c" /Oicf 

".\tcpclientcom.tlb"	".\tcpclientcom.h"	".\tcpclientcom_i.c" : $(SOURCE) "$(INTDIR)"
	$(MTL) @<<
  $(MTL_SWITCHES) $(SOURCE)
<<


SOURCE=.\tcpclientcom.rc

"$(INTDIR)\tcpclientcom.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

