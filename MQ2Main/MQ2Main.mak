# Microsoft Developer Studio Generated NMAKE File, Based on MQ2Main.dsp
!IF "$(CFG)" == ""
CFG=MQ2Main - Win32 Release
!MESSAGE No configuration specified. Defaulting to MQ2Main - Win32 Release.
!ENDIF 

!IF "$(CFG)" != "MQ2Main - Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MQ2Main.mak" CFG="MQ2Main - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MQ2Main - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
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

ALL : "$(OUTDIR)\MQ2Main.dll"

!ELSE 

ALL : "macroquest - Win32 Release" "$(OUTDIR)\MQ2Main.dll"

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"macroquest - Win32 ReleaseCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase "$(INTDIR)\EQClasses.obj"
	-@erase "$(INTDIR)\MQ2ChatHook.obj"
	-@erase "$(INTDIR)\MQ2CleanUI.obj"
	-@erase "$(INTDIR)\MQ2CommandAPI.obj"
	-@erase "$(INTDIR)\MQ2Commands.obj"
	-@erase "$(INTDIR)\MQ2Data.obj"
	-@erase "$(INTDIR)\MQ2DataAPI.obj"
	-@erase "$(INTDIR)\MQ2DataTypes.obj"
	-@erase "$(INTDIR)\MQ2DataVars.obj"
	-@erase "$(INTDIR)\MQ2DetourAPI.obj"
	-@erase "$(INTDIR)\MQ2DInput.obj"
	-@erase "$(INTDIR)\MQ2Globals.obj"
	-@erase "$(INTDIR)\MQ2KeyBinds.obj"
	-@erase "$(INTDIR)\MQ2MacroCommands.obj"
	-@erase "$(INTDIR)\MQ2Main.obj"
	-@erase "$(INTDIR)\MQ2Mouse.obj"
	-@erase "$(INTDIR)\MQ2ParseAPI.obj"
	-@erase "$(INTDIR)\MQ2PluginHandler.obj"
	-@erase "$(INTDIR)\MQ2Pulse.obj"
	-@erase "$(INTDIR)\MQ2Utilities.obj"
	-@erase "$(INTDIR)\MQ2Spawns.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\MQ2Main.dll"
	-@erase "$(OUTDIR)\MQ2Main.exp"
	-@erase "$(OUTDIR)\MQ2Main.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /Zp1 /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "CINTERFACE" /D "EQLIB_EXPORTS" /Fp"$(INTDIR)\MQ2Main.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
BSC32_FLAGS=/nologo /o"$(OUTDIR)\MQ2Main.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ..\Detours\lib60\detours.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\MQ2Main.pdb" /machine:I386 /out:"$(OUTDIR)\MQ2Main.dll" /implib:"$(OUTDIR)\MQ2Main.lib" /OPT:ICF 
LINK32_OBJS= \
	"$(INTDIR)\EQClasses.obj" \
	"$(INTDIR)\MQ2ChatHook.obj" \
	"$(INTDIR)\MQ2CleanUI.obj" \
	"$(INTDIR)\MQ2CommandAPI.obj" \
	"$(INTDIR)\MQ2Commands.obj" \
	"$(INTDIR)\MQ2Data.obj" \
	"$(INTDIR)\MQ2DataAPI.obj" \
	"$(INTDIR)\MQ2DataTypes.obj" \
	"$(INTDIR)\MQ2DataVars.obj" \
	"$(INTDIR)\MQ2DetourAPI.obj" \
	"$(INTDIR)\MQ2DInput.obj" \
	"$(INTDIR)\MQ2Globals.obj" \
	"$(INTDIR)\MQ2KeyBinds.obj" \
	"$(INTDIR)\MQ2MacroCommands.obj" \
	"$(INTDIR)\MQ2Main.obj" \
	"$(INTDIR)\MQ2Mouse.obj" \
	"$(INTDIR)\MQ2ParseAPI.obj" \
	"$(INTDIR)\MQ2PluginHandler.obj" \
	"$(INTDIR)\MQ2Pulse.obj" \
	"$(INTDIR)\MQ2Utilities.obj" \
	"$(INTDIR)\MQ2Spawns.obj"

"$(OUTDIR)\MQ2Main.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("MQ2Main.dep")
!INCLUDE "MQ2Main.dep"
!ELSE 
!MESSAGE Warning: cannot find "MQ2Main.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "MQ2Main - Win32 Release"
SOURCE=.\EQClasses.cpp

"$(INTDIR)\EQClasses.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2ChatHook.cpp

"$(INTDIR)\MQ2ChatHook.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2CleanUI.cpp

"$(INTDIR)\MQ2CleanUI.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2CommandAPI.cpp

"$(INTDIR)\MQ2CommandAPI.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2Commands.cpp

"$(INTDIR)\MQ2Commands.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2DetourAPI.cpp

"$(INTDIR)\MQ2DetourAPI.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2Data.cpp

"$(INTDIR)\MQ2Data.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2DataAPI.cpp

"$(INTDIR)\MQ2DataAPI.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2DataTypes.cpp

"$(INTDIR)\MQ2DataTypes.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2DataVars.cpp

"$(INTDIR)\MQ2DataVars.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2DInput.cpp

"$(INTDIR)\MQ2DInput.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2Globals.cpp

"$(INTDIR)\MQ2Globals.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2KeyBinds.cpp

"$(INTDIR)\MQ2KeyBinds.obj" : $(SOURCE) "$(INTDIR)"

SOURCE=.\MQ2MacroCommands.cpp

"$(INTDIR)\MQ2MacroCommands.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2Main.cpp

"$(INTDIR)\MQ2Main.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2Mouse.cpp

"$(INTDIR)\MQ2Mouse.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2ParseAPI.cpp

"$(INTDIR)\MQ2ParseAPI.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2PluginHandler.cpp

"$(INTDIR)\MQ2PluginHandler.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2Pulse.cpp

"$(INTDIR)\MQ2Pulse.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2Utilities.cpp

"$(INTDIR)\MQ2Utilities.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2Spawns.cpp

"$(INTDIR)\MQ2Spawns.obj" : $(SOURCE) "$(INTDIR)"


!IF  "$(CFG)" == "MQ2Main - Win32 Release"

"macroquest - Win32 Release" : 
   cd "\mq2\macroquest2\MacroQuest"
   $(MAKE) /$(MAKEFLAGS) /F .\MacroQuest.mak CFG="macroquest - Win32 Release" 
   cd "..\MQ2Main"

"macroquest - Win32 ReleaseCLEAN" : 
   cd "\mq2\macroquest2\MacroQuest"
   $(MAKE) /$(MAKEFLAGS) /F .\MacroQuest.mak CFG="macroquest - Win32 Release" RECURSE=1 CLEAN 
   cd "..\MQ2Main"

!ENDIF 


!ENDIF 

