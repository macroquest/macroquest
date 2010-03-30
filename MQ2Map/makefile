!include "../global.mak"

ALL : "$(OUTDIR)\MQ2Map.dll"

CLEAN :
	-@erase "$(INTDIR)\MQ2Map.obj"
	-@erase "$(INTDIR)\MQ2MapAPI.obj"
	-@erase "$(INTDIR)\MQ2MapCommands.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\MQ2Map.dll"
	-@erase "$(OUTDIR)\MQ2Map.exp"
	-@erase "$(OUTDIR)\MQ2Map.lib"
	-@erase "$(OUTDIR)\MQ2Map.pdb"


LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ..\Detours\lib60\detours.lib ..\Release\MQ2Main.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\MQ2Map.pdb" /debug /machine:I386 /out:"$(OUTDIR)\MQ2Map.dll" /implib:"$(OUTDIR)\MQ2Map.lib" /OPT:NOICF /OPT:NOREF 
LINK32_OBJS= \
	"$(INTDIR)\MQ2Map.obj" \
	"$(INTDIR)\MQ2MapAPI.obj" \
	"$(INTDIR)\MQ2MapCommands.obj" \
	"$(OUTDIR)\MQ2Main.lib"

"$(OUTDIR)\MQ2Map.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) $(LINK32_FLAGS) $(LINK32_OBJS)


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("MQ2Map.dep")
!INCLUDE "MQ2Map.dep"
!ELSE 
!MESSAGE Warning: cannot find "MQ2Map.dep"
!ENDIF 
!ENDIF 


SOURCE=.\MQ2Map.cpp

"$(INTDIR)\MQ2Map.obj" : $(SOURCE) "$(INTDIR)"

