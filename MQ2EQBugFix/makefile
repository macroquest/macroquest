!INCLUDE "../global.mak"

ALL : "$(OUTDIR)\MQ2EQBugFix.dll"

CLEAN :
	-@erase "$(INTDIR)\MQ2EQBugFix.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\MQ2EQBugFix.dll"
	-@erase "$(OUTDIR)\MQ2EQBugFix.exp"
	-@erase "$(OUTDIR)\MQ2EQBugFix.lib"
	-@erase "$(OUTDIR)\MQ2EQBugFix.pdb"


LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ..\Detours\lib60\detours.lib ..\Release\MQ2Main.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\MQ2EQBugFix.pdb" /debug /machine:I386 /out:"$(OUTDIR)\MQ2EQBugFix.dll" /implib:"$(OUTDIR)\MQ2EQBugFix.lib" /OPT:NOICF /OPT:NOREF 
LINK32_OBJS= \
	"$(INTDIR)\MQ2EQBugFix.obj" \
	"$(OUTDIR)\MQ2Main.lib"

"$(OUTDIR)\MQ2EQBugFix.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    -@!if "$(USERNAME)" == "Zerix"  nmake clean
    $(LINK32) $(LINK32_FLAGS) $(LINK32_OBJS)


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("MQ2EQBugFix.dep")
!INCLUDE "MQ2EQBugFix.dep"
!ELSE 
!MESSAGE Warning: cannot find "MQ2EQBugFix.dep"
!ENDIF 
!ENDIF 


SOURCE=.\MQ2EQBugFix.cpp

"$(INTDIR)\MQ2EQBugFix.obj" : $(SOURCE) "$(INTDIR)"

