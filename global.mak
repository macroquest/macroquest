all:

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

OUTDIR=../Release
INTDIR=.\Intermediate

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /Zp1 /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "CINTERFACE" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

!if ("$(_NMAKE_VER)"=="7.00.9466") || ("$(_NMAKE_VER)"=="7.10.3077") || ("$(COMPILER)"=="7")
DETLIB=..\Detours\lib\detours.lib
!elseif "$(_NMAKE_VER)" == "6.00.8168.0" || ("$(COMPILER)"=="6")
DETLIB=..\Detours\lib60\detours.lib
!else
!message $(_NMAKE_VER)
!message Cannot determine compiler version.
!message use set COMPILER=6
!message or set COMPILER=7
!message as appropriate
!endif

.c{$(INTDIR)}.obj::
   $(CPP) $(CPP_PROJ) $< 

.cpp{$(INTDIR)}.obj::
   $(CPP) $(CPP_PROJ) $< 

.cxx{$(INTDIR)}.obj::
   $(CPP) $(CPP_PROJ) $< 

.c{$(INTDIR)}.sbr::
   $(CPP) $(CPP_PROJ) $< 

.cpp{$(INTDIR)}.sbr::
   $(CPP) $(CPP_PROJ) $< 

.cxx{$(INTDIR)}.sbr::
   $(CPP) $(CPP_PROJ) $< 

RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\MacroQuest.res" /d "NDEBUG" 
