# Microsoft Developer Studio Generated NMAKE File, Based on harness_threadsafe.dsp
!IF "$(CFG)" == ""
CFG=harness_threadsafe - Win32 Debug
!MESSAGE No configuration specified. Defaulting to harness_threadsafe - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "harness_threadsafe - Win32 Release" && "$(CFG)" != "harness_threadsafe - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "harness_threadsafe.mak" CFG="harness_threadsafe - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "harness_threadsafe - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "harness_threadsafe - Win32 Debug" (based on "Win32 (x86) Console Application")
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

!IF  "$(CFG)" == "harness_threadsafe - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\harness_threadsafe.exe"


CLEAN :
	-@erase "$(INTDIR)\BSTR.obj"
	-@erase "$(INTDIR)\harness_threadsafe.obj"
	-@erase "$(INTDIR)\harness_threadsafe.pch"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\harness_threadsafe.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\harness_threadsafe.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\harness_threadsafe.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib LIBCMT.LIB /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\harness_threadsafe.pdb" /machine:I386 /out:"$(OUTDIR)\harness_threadsafe.exe" 
LINK32_OBJS= \
	"$(INTDIR)\BSTR.obj" \
	"$(INTDIR)\harness_threadsafe.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\harness_threadsafe.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "harness_threadsafe - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\harness_threadsafe.exe" "$(OUTDIR)\harness_threadsafe.pch"


CLEAN :
	-@erase "$(INTDIR)\BSTR.obj"
	-@erase "$(INTDIR)\harness_threadsafe.obj"
	-@erase "$(INTDIR)\harness_threadsafe.pch"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\harness_threadsafe.exe"
	-@erase "$(OUTDIR)\harness_threadsafe.ilk"
	-@erase "$(OUTDIR)\harness_threadsafe.map"
	-@erase "$(OUTDIR)\harness_threadsafe.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\harness_threadsafe.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\harness_threadsafe.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib LIBCMT.LIB /nologo /subsystem:console /verbose /incremental:yes /pdb:"$(OUTDIR)\harness_threadsafe.pdb" /map:"$(INTDIR)\harness_threadsafe.map" /debug /machine:I386 /nodefaultlib /out:"$(OUTDIR)\harness_threadsafe.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\BSTR.obj" \
	"$(INTDIR)\harness_threadsafe.obj" \
	"$(INTDIR)\StdAfx.obj"

"$(OUTDIR)\harness_threadsafe.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("harness_threadsafe.dep")
!INCLUDE "harness_threadsafe.dep"
!ELSE 
!MESSAGE Warning: cannot find "harness_threadsafe.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "harness_threadsafe - Win32 Release" || "$(CFG)" == "harness_threadsafe - Win32 Debug"
SOURCE=..\tcpclientcom\BSTR.cpp

!IF  "$(CFG)" == "harness_threadsafe - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\harness_threadsafe.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\BSTR.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\harness_threadsafe.pch"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "harness_threadsafe - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\BSTR.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\harness_threadsafe.cpp

!IF  "$(CFG)" == "harness_threadsafe - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\harness_threadsafe.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\harness_threadsafe.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\harness_threadsafe.pch"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "harness_threadsafe - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\harness_threadsafe.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "harness_threadsafe - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\harness_threadsafe.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\harness_threadsafe.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "harness_threadsafe - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\harness_threadsafe.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\harness_threadsafe.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

