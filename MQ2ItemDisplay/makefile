!include "../global.mak"

ALL : "$(OUTDIR)\MQ2ItemDisplay.dll"

CLEAN :
	-@erase "$(INTDIR)\MQ2ItemDisplay.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\MQ2ItemDisplay.dll"
	-@erase "$(OUTDIR)\MQ2ItemDisplay.exp"
	-@erase "$(OUTDIR)\MQ2ItemDisplay.lib"
	-@erase "$(OUTDIR)\MQ2ItemDisplay.pdb"


LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ..\Detours\lib60\detours.lib ..\Release\MQ2Main.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\MQ2ItemDisplay.pdb" /debug /machine:I386 /out:"$(OUTDIR)\MQ2ItemDisplay.dll" /implib:"$(OUTDIR)\MQ2ItemDisplay.lib" /OPT:NOICF /OPT:NOREF 
LINK32_OBJS= \
	"$(INTDIR)\MQ2ItemDisplay.obj" \
	"$(OUTDIR)\MQ2Main.lib"

"$(OUTDIR)\MQ2ItemDisplay.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    -@!if "$(USERNAME)" == "Zerix"  nmake clean
    $(LINK32) $(LINK32_FLAGS) $(LINK32_OBJS)


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("MQ2ItemDisplay.dep")
!INCLUDE "MQ2ItemDisplay.dep"
!ELSE 
!MESSAGE Warning: cannot find "MQ2ItemDisplay.dep"
!ENDIF 
!ENDIF 


SOURCE=.\MQ2ItemDisplay.cpp

"$(INTDIR)\MQ2ItemDisplay.obj" : $(SOURCE) "$(INTDIR)"

