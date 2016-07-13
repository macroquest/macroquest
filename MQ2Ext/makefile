DXSDK=..\dxsdk81
OUTDIR=..\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\mqext.dll"


CLEAN :
	-@erase "$(INTDIR)\*.obj"
	-@erase "$(INTDIR)\*.res"
	-@erase "$(INTDIR)\*.idb"
	-@erase "$(OUTDIR)\mqext.dll"
	-@erase "$(OUTDIR)\mqext.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
#CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /I "d:\DXSDK\include" /D "_USRDLL" /D "MQEXT_EXPORTS" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "CINTERFACE" /Fp"$(INTDIR)\eqlib.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

CPP_PROJ=/nologo /MT /W3 /GX /O2 /I "$(DXSDK)\include" /D "_USRDLL" /D "MQEXT_EXPORTS" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "CINTERFACE" /Fp"$(INTDIR)\mqext.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c  /Zi /Zp1

.cpp{$(INTDIR)}.obj::
   $(CPP) $(CPP_PROJ) $< 

.c{$(INTDIR)}.obj::
   $(CPP) $(CPP_PROJ) $< 

.cpp.cod:
   $(CPP) $(CPP_PROJ) $< -FAcs -Fa$*.cod

.rc{$(INTDIR)}.res::
    $(RSC) $(RSC_PROJ) $<

RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\mqext.res" /d "NDEBUG" 
	
LINK32=link.exe

LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ws2_32.lib /nologo /dll /incremental:no /debug /pdb:"$(OUTDIR)\mqext.pdb"         /machine:I386 /out:"$(OUTDIR)\mqext.dll" /implib:"$(OUTDIR)\mqext.lib" /def:mqext.def

!if "$(_NMAKE_VER)" == "7.00.9466"
LINK32_FLAGS=$(LINK32_FLAGS)  /libpath:"..\Detours\lib"
!elseif "$(_NMAKE_VER)" == "6.00.8168.0"
LINK32_FLAGS=$(LINK32_FLAGS)  /libpath:"..\Detours\lib60"
!elseif "$(COMPILER)" == "6"
LINK32_FLAGS=$(LINK32_FLAGS)  /libpath:"..\Detours\lib"
!elseif "$(COMPILER)" == "7"
LINK32_FLAGS=$(LINK32_FLAGS)  /libpath:"..\Detours\lib60"
!else
!message Cannot determine compiler version.
!message use set COMPILER=6
!message or set COMPILER=7
!message as appropriate
!endif
LINK32_OBJS= \
	"$(INTDIR)\exts.obj" \
	"$(INTDIR)\exts2.obj" \
	"$(INTDIR)\mqext.obj" \
	"$(INTDIR)\mqext.res"

"$(OUTDIR)\mqext.dll" : "$(INTDIR)" "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) $(LINK32_FLAGS) $(LINK32_OBJS)

