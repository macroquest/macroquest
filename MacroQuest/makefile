!include "../global.mak"

ALL : "$(OUTDIR)\MacroQuest.exe"

CLEAN :
	-@erase "$(INTDIR)\MacroQuest.obj"
	-@erase "$(INTDIR)\MacroQuest.res"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\MacroQuest.exe"
	-@erase "$(OUTDIR)\MacroQuest.pdb"

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ..\Detours\lib60\detours.lib ..\Release\MQ2Main.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\MacroQuest.pdb" /debug /machine:I386 /out:"$(OUTDIR)\MacroQuest.exe" /OPT:ICF 
LINK32_OBJS= \
	"$(INTDIR)\MacroQuest.obj" \
	"$(INTDIR)\MacroQuest.res"

"$(OUTDIR)\MacroQuest.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) $(LINK32_FLAGS) $(LINK32_OBJS)


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("MacroQuest.dep")
!INCLUDE "MacroQuest.dep"
!ELSE 
!MESSAGE Warning: cannot find "MacroQuest.dep"
!ENDIF 
!ENDIF 


SOURCE=.\MacroQuest.cpp

"$(INTDIR)\MacroQuest.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MacroQuest.rc

"$(INTDIR)\MacroQuest.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)



