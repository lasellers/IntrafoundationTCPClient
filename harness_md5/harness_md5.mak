# Microsoft Developer Studio Generated NMAKE File, Based on harness_md5.dsp
!IF "$(CFG)" == ""
CFG=harness_md5 - Win32 Debug
!MESSAGE No configuration specified. Defaulting to harness_md5 - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "harness_md5 - Win32 Release" && "$(CFG)" != "harness_md5 - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "harness_md5.mak" CFG="harness_md5 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "harness_md5 - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "harness_md5 - Win32 Debug" (based on "Win32 (x86) Console Application")
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

!IF  "$(CFG)" == "harness_md5 - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\harness_md5.exe" "$(OUTDIR)\harness_md5.bsc"


CLEAN :
	-@erase "$(INTDIR)\BSTR.obj"
	-@erase "$(INTDIR)\BSTR.sbr"
	-@erase "$(INTDIR)\harness_md5.obj"
	-@erase "$(INTDIR)\harness_md5.pch"
	-@erase "$(INTDIR)\harness_md5.sbr"
	-@erase "$(INTDIR)\Log.obj"
	-@erase "$(INTDIR)\Log.sbr"
	-@erase "$(INTDIR)\MD5.obj"
	-@erase "$(INTDIR)\MD5.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\harness_md5.bsc"
	-@erase "$(OUTDIR)\harness_md5.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /Zi /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\harness_md5.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\harness_md5.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\BSTR.sbr" \
	"$(INTDIR)\harness_md5.sbr" \
	"$(INTDIR)\Log.sbr" \
	"$(INTDIR)\MD5.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\harness_md5.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\harness_md5.pdb" /machine:I386 /out:"$(OUTDIR)\harness_md5.exe" 
LINK32_OBJS= \
	"$(INTDIR)\BSTR.obj" \
	"$(INTDIR)\harness_md5.obj" \
	"$(INTDIR)\Log.obj" \
	"$(INTDIR)\MD5.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\harness_md5.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "harness_md5 - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\harness_md5.exe"


CLEAN :
	-@erase "$(INTDIR)\BSTR.obj"
	-@erase "$(INTDIR)\harness_md5.obj"
	-@erase "$(INTDIR)\harness_md5.pch"
	-@erase "$(INTDIR)\Log.obj"
	-@erase "$(INTDIR)\MD5.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\harness_md5.exe"
	-@erase "$(OUTDIR)\harness_md5.ilk"
	-@erase "$(OUTDIR)\harness_md5.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\harness_md5.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\harness_md5.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\harness_md5.pdb" /debug /machine:I386 /out:"$(OUTDIR)\harness_md5.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\BSTR.obj" \
	"$(INTDIR)\harness_md5.obj" \
	"$(INTDIR)\Log.obj" \
	"$(INTDIR)\MD5.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\harness_md5.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("harness_md5.dep")
!INCLUDE "harness_md5.dep"
!ELSE 
!MESSAGE Warning: cannot find "harness_md5.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "harness_md5 - Win32 Release" || "$(CFG)" == "harness_md5 - Win32 Debug"
SOURCE=..\tcpclientcom\BSTR.cpp

!IF  "$(CFG)" == "harness_md5 - Win32 Release"


"$(INTDIR)\BSTR.obj"	"$(INTDIR)\BSTR.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\harness_md5.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "harness_md5 - Win32 Debug"


"$(INTDIR)\BSTR.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\harness_md5.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\harness_md5.cpp

!IF  "$(CFG)" == "harness_md5 - Win32 Release"


"$(INTDIR)\harness_md5.obj"	"$(INTDIR)\harness_md5.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\harness_md5.pch"


!ELSEIF  "$(CFG)" == "harness_md5 - Win32 Debug"


"$(INTDIR)\harness_md5.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\harness_md5.pch"


!ENDIF 

SOURCE=..\tcpclientcom\Log.cpp

!IF  "$(CFG)" == "harness_md5 - Win32 Release"


"$(INTDIR)\Log.obj"	"$(INTDIR)\Log.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\harness_md5.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "harness_md5 - Win32 Debug"


"$(INTDIR)\Log.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\harness_md5.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\tcpclientcom\MD5.cpp

!IF  "$(CFG)" == "harness_md5 - Win32 Release"


"$(INTDIR)\MD5.obj"	"$(INTDIR)\MD5.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\harness_md5.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "harness_md5 - Win32 Debug"


"$(INTDIR)\MD5.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\harness_md5.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "harness_md5 - Win32 Release"

CPP_SWITCHES=/nologo /ML /W3 /GX /Zi /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\harness_md5.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\harness_md5.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "harness_md5 - Win32 Debug"

CPP_SWITCHES=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\harness_md5.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\harness_md5.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

