!include "../global.mak"

ALL : "$(OUTDIR)\MQ2MoveUtils.dll"

CLEAN :
	-@erase "$(INTDIR)\MQ2MoveUtils.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\MQ2MoveUtils.dll"
	-@erase "$(OUTDIR)\MQ2MoveUtils.exp"
	-@erase "$(OUTDIR)\MQ2MoveUtils.lib"
	-@erase "$(OUTDIR)\MQ2MoveUtils.pdb"


LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib $(DETLIB) ..\Release\MQ2Main.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\MQ2MoveUtils.pdb" /debug /machine:I386 /out:"$(OUTDIR)\MQ2MoveUtils.dll" /implib:"$(OUTDIR)\MQ2MoveUtils.lib" /OPT:NOICF /OPT:NOREF 
LINK32_OBJS= \
	"$(INTDIR)\MQ2MoveUtils.obj" \
	"$(OUTDIR)\MQ2Main.lib"

"$(OUTDIR)\MQ2MoveUtils.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) $(LINK32_FLAGS) $(LINK32_OBJS)


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("MQ2MoveUtils.dep")
!INCLUDE "MQ2MoveUtils.dep"
!ELSE 
!MESSAGE Warning: cannot find "MQ2MoveUtils.dep"
!ENDIF 
!ENDIF 


SOURCE=.\MQ2MoveUtils.cpp

"$(INTDIR)\MQ2MoveUtils.obj" : $(SOURCE) "$(INTDIR)"

