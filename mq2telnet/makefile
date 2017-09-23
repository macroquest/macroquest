!include "../global.mak"

ALL : "$(OUTDIR)\mq2telnet.dll"

CLEAN :
	-@erase "$(INTDIR)\MQ2Telnet.obj"
	-@erase "$(INTDIR)\WinTelnet.obj"
	-@erase "$(INTDIR)\TelnetServer.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\mq2telnet.dll"
	-@erase "$(OUTDIR)\mq2telnet.exp"
	-@erase "$(OUTDIR)\mq2telnet.lib"
	-@erase "$(OUTDIR)\mq2telnet.pdb"


LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ..\Detours\lib60\detours.lib ..\Release\MQ2Main.lib wsock32.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\mq2telnet.pdb" /debug /machine:I386 /out:"$(OUTDIR)\mq2telnet.dll" /implib:"$(OUTDIR)\mq2telnet.lib" /OPT:NOICF /OPT:NOREF 
LINK32_OBJS= \
	"$(INTDIR)\MQ2Telnet.obj" \
        "$(INTDIR)\WinTelnet.obj" \
        "$(INTDIR)\TelnetServer.obj" \
	"$(OUTDIR)\MQ2Main.lib"

"$(OUTDIR)\mq2telnet.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) $(LINK32_FLAGS) $(LINK32_OBJS)


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("mq2telnet.dep")
!INCLUDE "mq2telnet.dep"
!ELSE 
!MESSAGE Warning: cannot find "mq2telnet.dep"
!ENDIF 
!ENDIF 


SOURCE=.\MQ2Telnet.cpp

"$(INTDIR)\MQ2Telnet.obj" : $(SOURCE) "$(INTDIR)"



