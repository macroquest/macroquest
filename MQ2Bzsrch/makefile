!include "../global.mak"

ALL : "$(OUTDIR)\MQ2Bzsrch.dll"

CLEAN :
	-@erase "$(INTDIR)\MQ2Bzsrch.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\MQ2Bzsrch.dll"
	-@erase "$(OUTDIR)\MQ2Bzsrch.exp"
	-@erase "$(OUTDIR)\MQ2Bzsrch.lib"
	-@erase "$(OUTDIR)\MQ2Bzsrch.pdb"


LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ..\Detours\lib60\detours.lib ..\Release\MQ2Main.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\MQ2Bzsrch.pdb" /debug /machine:I386 /out:"$(OUTDIR)\MQ2Bzsrch.dll" /implib:"$(OUTDIR)\MQ2Bzsrch.lib" /OPT:NOICF /OPT:NOREF 
LINK32_OBJS= \
	"$(INTDIR)\MQ2Bzsrch.obj" \
	"$(INTDIR)\netstream.obj" \
	"$(OUTDIR)\MQ2Main.lib"

"$(OUTDIR)\MQ2Bzsrch.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) $(LINK32_FLAGS) $(LINK32_OBJS)


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("MQ2Bzsrch.dep")
!INCLUDE "MQ2Bzsrch.dep"
!ELSE 
!MESSAGE Warning: cannot find "MQ2Bzsrch.dep"
!ENDIF 
!ENDIF 


SOURCE=.\MQ2Bzsrch.cpp

"$(INTDIR)\MQ2Bzsrch.obj" : $(SOURCE) "$(INTDIR)"

