# Microsoft Developer Studio Generated NMAKE File, Based on harness_https.dsp
!IF "$(CFG)" == ""
CFG=harness_https - Win32 Debug
!MESSAGE No configuration specified. Defaulting to harness_https - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "harness_https - Win32 Release" && "$(CFG)" != "harness_https - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "harness_https.mak" CFG="harness_https - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "harness_https - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "harness_https - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "harness_https - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\harness_https.exe"


CLEAN :
	-@erase "$(INTDIR)\harness_https.obj"
	-@erase "$(INTDIR)\harness_https.pch"
	-@erase "$(INTDIR)\Log.obj"
	-@erase "$(INTDIR)\MD5.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\tcp.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\harness_https.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\harness_https.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\harness_https.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\harness_https.pdb" /machine:I386 /out:"$(OUTDIR)\harness_https.exe" 
LINK32_OBJS= \
	"$(INTDIR)\harness_https.obj" \
	"$(INTDIR)\Log.obj" \
	"$(INTDIR)\MD5.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\tcp.obj"

"$(OUTDIR)\harness_https.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "harness_https - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\harness_https.exe"


CLEAN :
	-@erase "$(INTDIR)\harness_https.obj"
	-@erase "$(INTDIR)\harness_https.pch"
	-@erase "$(INTDIR)\Log.obj"
	-@erase "$(INTDIR)\MD5.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\tcp.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\harness_https.exe"
	-@erase "$(OUTDIR)\harness_https.ilk"
	-@erase "$(OUTDIR)\harness_https.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\harness_https.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\harness_https.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  ws2_32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\harness_https.pdb" /debug /machine:I386 /out:"$(OUTDIR)\harness_https.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\harness_https.obj" \
	"$(INTDIR)\Log.obj" \
	"$(INTDIR)\MD5.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\tcp.obj"

"$(OUTDIR)\harness_https.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
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


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("harness_https.dep")
!INCLUDE "harness_https.dep"
!ELSE 
!MESSAGE Warning: cannot find "harness_https.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "harness_https - Win32 Release" || "$(CFG)" == "harness_https - Win32 Debug"
SOURCE=.\harness_https.cpp

"$(INTDIR)\harness_https.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\harness_https.pch"


SOURCE=..\tcpclientcom\Log.cpp

"$(INTDIR)\Log.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\harness_https.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\tcpclientcom\MD5.cpp

"$(INTDIR)\MD5.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\harness_https.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "harness_https - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\harness_https.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\harness_https.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "harness_https - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\harness_https.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\harness_https.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=..\tcpclientcom\tcp.cpp

"$(INTDIR)\tcp.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\harness_https.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)



!ENDIF 

