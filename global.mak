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

!if ("$(_NMAKE_VER)"=="7.00.9466") || ("$(_NMAKE_VER)"=="7.10.3077") || ("$(COMPILER)"=="7") || ("$(COMPILER)"=="8") || ("$(_NMAKE_VER)"=="9.00.30729.01") || ("$(_NMAKE_VER)"=="8.00.50727.762")
DETLIB=..\Detours\lib\detours.lib
COMPILER=7
!elseif ("$(_NMAKE_VER)"=="6.00.8168.0") || ("$(_NMAKE_VER)"=="6.00.9782.0") || ("$(COMPILER)"=="6")
DETLIB=..\Detours\lib60\detours.lib
!else
!message $(_NMAKE_VER)
!message Cannot determine compiler version.
!message use set COMPILER=6
!message or set COMPILER=7
!message or set COMPILER=8
!message as appropriate
!endif

!if ($(COMPILER)>=7)
!else
EH=/EHsc
!endif

CPP=cl.exe
CPP_PROJ=/nologo /Zp1 /Zi /MT $(EH) /W3 /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "CINTERFACE"  /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c


.c{$(INTDIR)}.obj::
   $(CPP) $(CPP_PROJ) $< 

.cpp{$(INTDIR)}.obj::
   $(CPP) $(CPP_PROJ) $< 

.cpp.cod:
   $(CPP) $(CPP_PROJ) $< -FAcs -Fa$*.cod

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
