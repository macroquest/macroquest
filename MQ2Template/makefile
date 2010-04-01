!include "../global.mak"

ALL : "$(OUTDIR)\MQ2Template.dll"

CLEAN :
	-@erase "$(INTDIR)\MQ2Template.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\MQ2Template.dll"
	-@erase "$(OUTDIR)\MQ2Template.exp"
	-@erase "$(OUTDIR)\MQ2Template.lib"
	-@erase "$(OUTDIR)\MQ2Template.pdb"


LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib $(DETLIB) ..\Release\MQ2Main.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\MQ2Template.pdb" /debug /machine:I386 /out:"$(OUTDIR)\MQ2Template.dll" /implib:"$(OUTDIR)\MQ2Template.lib" /OPT:NOICF /OPT:NOREF 
LINK32_OBJS= \
	"$(INTDIR)\MQ2Template.obj" \
	"$(OUTDIR)\MQ2Main.lib"

"$(OUTDIR)\MQ2Template.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) $(LINK32_FLAGS) $(LINK32_OBJS)


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("MQ2Template.dep")
!INCLUDE "MQ2Template.dep"
!ELSE 
!MESSAGE Warning: cannot find "MQ2Template.dep"
!ENDIF 
!ENDIF 


SOURCE=.\MQ2Template.cpp

"$(INTDIR)\MQ2Template.obj" : $(SOURCE) "$(INTDIR)"

