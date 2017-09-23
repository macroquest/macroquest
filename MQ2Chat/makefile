!INCLUDE "../global.mak"

ALL: "$(OUTDIR)\MQ2Chat.dll"

CLEAN :
	-@erase "$(INTDIR)\MQ2Chat.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc70.idb"
	-@erase "$(OUTDIR)\MQ2Chat.dll"
	-@erase "$(OUTDIR)\MQ2Chat.exp"
	-@erase "$(OUTDIR)\MQ2Chat.lib"
	-@erase "$(OUTDIR)\MQ2Chat.pdb"


LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib $(DETLIB) ..\Release\MQ2Main.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\MQ2Chat.pdb" /debug /machine:I386 /out:"$(OUTDIR)\MQ2Chat.dll" /implib:"$(OUTDIR)\MQ2Chat.lib" /OPT:NOICF /OPT:NOREF 

LINK32_OBJS= $(DETLIB) \
	"$(INTDIR)\MQ2Chat.obj"

"$(OUTDIR)\MQ2Chat.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    -@!if "$(USERNAME)" == "Zerix"  nmake clean
    $(LINK32) $(LINK32_FLAGS) $(LINK32_OBJS)


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("MQ2Chat.dep")
!INCLUDE "MQ2Chat.dep"
!ELSE 
!MESSAGE Warning: cannot find "MQ2Chat.dep"
!ENDIF 
!ENDIF 


SOURCE=.\MQ2Chat.cpp

"$(INTDIR)\MQ2Chat.obj" : $(SOURCE) "$(INTDIR)"

