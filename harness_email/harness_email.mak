# Microsoft Developer Studio Generated NMAKE File, Based on harness_email.dsp
!IF "$(CFG)" == ""
CFG=harness_email - Win32 Debug
!MESSAGE No configuration specified. Defaulting to harness_email - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "harness_email - Win32 Release" && "$(CFG)" != "harness_email - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "harness_email.mak" CFG="harness_email - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "harness_email - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "harness_email - Win32 Debug" (based on "Win32 (x86) Console Application")
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

!IF  "$(CFG)" == "harness_email - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\harness_email.exe"


CLEAN :
	-@erase "$(INTDIR)\Base64.obj"
	-@erase "$(INTDIR)\harness_email.obj"
	-@erase "$(INTDIR)\harness_email.pch"
	-@erase "$(INTDIR)\Log.obj"
	-@erase "$(INTDIR)\MIME.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\szList.obj"
	-@erase "$(INTDIR)\tcp.obj"
	-@erase "$(INTDIR)\UU.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\XX.obj"
	-@erase "$(OUTDIR)\harness_email.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\harness_email.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\harness_email.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ws2_32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\harness_email.pdb" /machine:I386 /out:"$(OUTDIR)\harness_email.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Base64.obj" \
	"$(INTDIR)\harness_email.obj" \
	"$(INTDIR)\Log.obj" \
	"$(INTDIR)\MIME.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\szList.obj" \
	"$(INTDIR)\tcp.obj" \
	"$(INTDIR)\UU.obj" \
	"$(INTDIR)\XX.obj"

"$(OUTDIR)\harness_email.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "harness_email - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\harness_email.exe" "$(OUTDIR)\harness_email.pch"


CLEAN :
	-@erase "$(INTDIR)\Base64.obj"
	-@erase "$(INTDIR)\harness_email.obj"
	-@erase "$(INTDIR)\harness_email.pch"
	-@erase "$(INTDIR)\Log.obj"
	-@erase "$(INTDIR)\MIME.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\szList.obj"
	-@erase "$(INTDIR)\tcp.obj"
	-@erase "$(INTDIR)\UU.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\XX.obj"
	-@erase "$(OUTDIR)\harness_email.exe"
	-@erase "$(OUTDIR)\harness_email.ilk"
	-@erase "$(OUTDIR)\harness_email.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\harness_email.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ws2_32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\harness_email.pdb" /debug /machine:I386 /out:"$(OUTDIR)\harness_email.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\Base64.obj" \
	"$(INTDIR)\harness_email.obj" \
	"$(INTDIR)\Log.obj" \
	"$(INTDIR)\MIME.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\szList.obj" \
	"$(INTDIR)\tcp.obj" \
	"$(INTDIR)\UU.obj" \
	"$(INTDIR)\XX.obj"

"$(OUTDIR)\harness_email.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("harness_email.dep")
!INCLUDE "harness_email.dep"
!ELSE 
!MESSAGE Warning: cannot find "harness_email.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "harness_email - Win32 Release" || "$(CFG)" == "harness_email - Win32 Debug"
SOURCE=..\tcpclientcom\Base64.cpp

"$(INTDIR)\Base64.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\harness_email.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\harness_email.cpp

"$(INTDIR)\harness_email.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\harness_email.pch"


SOURCE=..\tcpclientcom\Log.cpp

"$(INTDIR)\Log.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\harness_email.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\tcpclientcom\MIME.cpp

"$(INTDIR)\MIME.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\harness_email.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "harness_email - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\harness_email.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\harness_email.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "harness_email - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\harness_email.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\harness_email.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=..\tcpclientcom\szList.cpp

"$(INTDIR)\szList.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\harness_email.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\tcpclientcom\tcp.cpp

"$(INTDIR)\tcp.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\harness_email.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\tcpclientcom\UU.cpp

"$(INTDIR)\UU.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\harness_email.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\tcpclientcom\XX.cpp

"$(INTDIR)\XX.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\harness_email.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)



!ENDIF 

