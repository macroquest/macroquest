# Microsoft Developer Studio Generated NMAKE File, Based on MQ2ChatWnd.dsp
!IF "$(CFG)" == ""
CFG=MQ2ChatWnd - Win32 Release
!MESSAGE No configuration specified. Defaulting to MQ2ChatWnd - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "MQ2ChatWnd - Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MQ2ChatWnd.mak" CFG="MQ2ChatWnd - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MQ2ChatWnd - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF "$(RECURSE)" == "0" 

ALL : "$(OUTDIR)\MQ2ChatWnd.dll"

!ELSE 

ALL : "MQ2Main - Win32 Release" "macroquest - Win32 Release" "$(OUTDIR)\MQ2ChatWnd.dll"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"macroquest - Win32 ReleaseCLEAN" "MQ2Main - Win32 ReleaseCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\MQ2ChatWnd.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\MQ2ChatWnd.dll"
	-@erase "$(OUTDIR)\MQ2ChatWnd.exp"
	-@erase "$(OUTDIR)\MQ2ChatWnd.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /Zp1 /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "CINTERFACE" /Fp"$(INTDIR)\MQ2ChatWnd.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\MQ2ChatWnd.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ..\Detours\lib60\detours.lib ..\Release\MQ2Main.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\MQ2ChatWnd.pdb" /machine:I386 /out:"$(OUTDIR)\MQ2ChatWnd.dll" /implib:"$(OUTDIR)\MQ2ChatWnd.lib" /OPT:ICF 
LINK32_OBJS= \
	"$(INTDIR)\MQ2ChatWnd.obj" \
	"$(OUTDIR)\MQ2Main.lib"

"$(OUTDIR)\MQ2ChatWnd.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("MQ2ChatWnd.dep")
!INCLUDE "MQ2ChatWnd.dep"
!ELSE 
!MESSAGE Warning: cannot find "MQ2ChatWnd.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "MQ2ChatWnd - Win32 Release"
SOURCE=.\MQ2ChatWnd.cpp

"$(INTDIR)\MQ2ChatWnd.obj" : $(SOURCE) "$(INTDIR)"


!IF  "$(CFG)" == "MQ2ChatWnd - Win32 Release"

"macroquest - Win32 Release" : 
   cd "\mq2\macroquest2\MacroQuest"
   $(MAKE) /$(MAKEFLAGS) /F .\MacroQuest.mak CFG="macroquest - Win32 Release" 
   cd "..\MQ2ChatWnd"

"macroquest - Win32 ReleaseCLEAN" : 
   cd "\mq2\macroquest2\MacroQuest"
   $(MAKE) /$(MAKEFLAGS) /F .\MacroQuest.mak CFG="macroquest - Win32 Release" RECURSE=1 CLEAN 
   cd "..\MQ2ChatWnd"

!ENDIF 

!IF  "$(CFG)" == "MQ2ChatWnd - Win32 Release"

"MQ2Main - Win32 Release" : 
   cd "\mq2\macroquest2\MQ2Main"
   $(MAKE) /$(MAKEFLAGS) /F .\MQ2Main.mak CFG="MQ2Main - Win32 Release" 
   cd "..\MQ2ChatWnd"

"MQ2Main - Win32 ReleaseCLEAN" : 
   cd "\mq2\macroquest2\MQ2Main"
   $(MAKE) /$(MAKEFLAGS) /F .\MQ2Main.mak CFG="MQ2Main - Win32 Release" RECURSE=1 CLEAN 
   cd "..\MQ2ChatWnd"

!ENDIF 


!ENDIF 

