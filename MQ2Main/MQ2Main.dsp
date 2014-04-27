# Microsoft Developer Studio Project File - Name="MQ2Main" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=MQ2Main - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MQ2Main.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MQ2Main.mak" CFG="MQ2Main - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MQ2Main - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe
# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../Release"
# PROP Intermediate_Dir "Intermediate"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /Zp1 /MT /w /W0 /GX /Zi /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "CINTERFACE" /D "EQLIB_EXPORTS" /YX /FD /c
# ADD CPP /Zp1 /MT /w /W0 /GX /Zi /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "CINTERFACE" /D "EQLIB_EXPORTS" /FD /c
# SUBTRACT CPP /nologo /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ..\Detours\lib60\detours.lib /nologo /dll /map /debug /machine:I386 /OPT:ICF
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ..\Detours\lib60\detours.lib winmm.lib /nologo /dll /map /debug /machine:I386 /OPT:NOICF /OPT:NOREF
# SUBTRACT LINK32 /pdb:none
# Begin Target

# Name "MQ2Main - Win32 Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\EQClasses.cpp
# End Source File
# Begin Source File

SOURCE=.\MQ2Auth.cpp
# End Source File
# Begin Source File

SOURCE=.\MQ2Benchmarks.cpp
# End Source File
# Begin Source File

SOURCE=.\MQ2ChatHook.cpp
# End Source File
# Begin Source File

SOURCE=.\MQ2CleanUI.cpp
# End Source File
# Begin Source File

SOURCE=.\MQ2CommandAPI.cpp
# End Source File
# Begin Source File

SOURCE=.\MQ2Commands.cpp
# End Source File
# Begin Source File

SOURCE=.\MQ2Data.cpp
# End Source File
# Begin Source File

SOURCE=.\MQ2DataAPI.cpp
# End Source File
# Begin Source File

SOURCE=.\MQ2DataTypes.cpp
# End Source File
# Begin Source File

SOURCE=.\MQ2DataVars.cpp
# End Source File
# Begin Source File

SOURCE=.\MQ2DetourAPI.cpp
# End Source File
# Begin Source File

SOURCE=.\MQ2DInput.cpp
# End Source File
# Begin Source File

SOURCE=.\MQ2Globals.cpp
# End Source File
# Begin Source File

SOURCE=.\MQ2KeyBinds.cpp
# End Source File
# Begin Source File

SOURCE=.\MQ2MacroCommands.cpp
# End Source File
# Begin Source File

SOURCE=.\MQ2Main.cpp
# End Source File
# Begin Source File

SOURCE=.\MQ2Mouse.cpp
# End Source File
# Begin Source File

SOURCE=.\MQ2ParseAPI.cpp
# End Source File
# Begin Source File

SOURCE=.\MQ2PluginHandler.cpp
# End Source File
# Begin Source File

SOURCE=.\MQ2Pulse.cpp
# End Source File
# Begin Source File

SOURCE=.\MQ2Spawns.cpp
# End Source File
# Begin Source File

SOURCE=.\MQ2Utilities.cpp
# End Source File
# Begin Source File

SOURCE=.\MQ2Windows.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\combines.h
# End Source File
# Begin Source File

SOURCE=.\dikeys.h
# End Source File
# Begin Source File

SOURCE=.\EQClasses.h
# End Source File
# Begin Source File

SOURCE=.\EQData.h
# End Source File
# Begin Source File

SOURCE=.\eqgame.h
# End Source File
# Begin Source File

SOURCE=.\EQUIStructs.h
# End Source File
# Begin Source File

SOURCE=.\itemtypes.h
# End Source File
# Begin Source File

SOURCE=.\MQ2DataTypes.h
# End Source File
# Begin Source File

SOURCE=.\MQ2Globals.h
# End Source File
# Begin Source File

SOURCE=.\MQ2Internal.h
# End Source File
# Begin Source File

SOURCE=.\MQ2Main.h
# End Source File
# Begin Source File

SOURCE=.\MQ2Prototypes.h
# End Source File
# Begin Source File

SOURCE=.\skills.h
# End Source File
# Begin Source File

SOURCE=.\SpellEffects.h
# End Source File
# End Group

SOURCE=.\actordef.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
