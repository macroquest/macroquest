# Microsoft Developer Studio Generated NMAKE File, Based on MacroQuest.dsp
!IF "$(CFG)" == ""
CFG=macroquest - Win32 Release
!MESSAGE No configuration specified. Defaulting to macroquest - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "macroquest - Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MacroQuest.mak" CFG="macroquest - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "macroquest - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

OUTDIR=.\../Release
INTDIR=.\Intermediate
# Begin Custom Macros
OutDir=.\../Release
# End Custom Macros

ALL : "$(OUTDIR)\MacroQuest.exe"


CLEAN :
	-@erase "$(INTDIR)\MacroQuest.obj"
	-@erase "$(INTDIR)\MacroQuest.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\MacroQuest.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\MacroQuest.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\MacroQuest.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\MacroQuest.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\MacroQuest.pdb" /machine:I386 /out:"$(OUTDIR)\MacroQuest.exe" /OPT:ICF 
LINK32_OBJS= \
	"$(INTDIR)\MacroQuest.obj" \
	"$(INTDIR)\MacroQuest.res"

"$(OUTDIR)\MacroQuest.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("MacroQuest.dep")
!INCLUDE "MacroQuest.dep"
!ELSE 
!MESSAGE Warning: cannot find "MacroQuest.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "macroquest - Win32 Release"
SOURCE=.\MacroQuest.cpp

"$(INTDIR)\MacroQuest.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MacroQuest.rc

"$(INTDIR)\MacroQuest.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

