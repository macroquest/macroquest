!include "../global.mak"

ALL : "$(OUTDIR)\MQ2FPS.dll"

CLEAN :
	-@erase "$(INTDIR)\MQ2FPS.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\MQ2FPS.dll"
	-@erase "$(OUTDIR)\MQ2FPS.exp"
	-@erase "$(OUTDIR)\MQ2FPS.lib"
	-@erase "$(OUTDIR)\MQ2FPS.pdb"


LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ..\Detours\lib60\detours.lib ..\Release\MQ2Main.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\MQ2FPS.pdb" /debug /machine:I386 /out:"$(OUTDIR)\MQ2FPS.dll" /implib:"$(OUTDIR)\MQ2FPS.lib" /OPT:NOICF /OPT:NOREF 
LINK32_OBJS= \
	"$(INTDIR)\MQ2FPS.obj" \
	"$(OUTDIR)\MQ2Main.lib"

"$(OUTDIR)\MQ2FPS.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    -@!if "$(USERNAME)" == "Zerix"  nmake clean
    $(LINK32) $(LINK32_FLAGS) $(LINK32_OBJS)


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("MQ2FPS.dep")
!INCLUDE "MQ2FPS.dep"
!ELSE 
!MESSAGE Warning: cannot find "MQ2FPS.dep"
!ENDIF 
!ENDIF 


SOURCE=.\MQ2FPS.cpp

"$(INTDIR)\MQ2FPS.obj" : $(SOURCE) "$(INTDIR)"

