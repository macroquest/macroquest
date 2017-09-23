!INCLUDE "../global.mak"


ALL : "$(OUTDIR)\MQ2Main.dll" 

CLEAN :
	-@erase "$(INTDIR)\EQClasses.obj"
	-@erase "$(INTDIR)\EQClasses.sbr"
	-@erase "$(INTDIR)\MQ2Auth.obj"
	-@erase "$(INTDIR)\MQ2Auth.sbr"
	-@erase "$(INTDIR)\MQ2Benchmarks.obj"
	-@erase "$(INTDIR)\MQ2Benchmarks.sbr"
	-@erase "$(INTDIR)\MQ2ChatHook.obj"
	-@erase "$(INTDIR)\MQ2ChatHook.sbr"
	-@erase "$(INTDIR)\MQ2CleanUI.obj"
	-@erase "$(INTDIR)\MQ2CleanUI.sbr"
	-@erase "$(INTDIR)\MQ2CommandAPI.obj"
	-@erase "$(INTDIR)\MQ2CommandAPI.sbr"
	-@erase "$(INTDIR)\MQ2Commands.obj"
	-@erase "$(INTDIR)\MQ2Commands.sbr"
	-@erase "$(INTDIR)\MQ2Data.obj"
	-@erase "$(INTDIR)\MQ2Data.sbr"
	-@erase "$(INTDIR)\MQ2DataAPI.obj"
	-@erase "$(INTDIR)\MQ2DataAPI.sbr"
	-@erase "$(INTDIR)\MQ2DataTypes.obj"
	-@erase "$(INTDIR)\MQ2DataTypes.sbr"
	-@erase "$(INTDIR)\MQ2DataVars.obj"
	-@erase "$(INTDIR)\MQ2DataVars.sbr"
	-@erase "$(INTDIR)\MQ2DetourAPI.obj"
	-@erase "$(INTDIR)\MQ2DetourAPI.sbr"
	-@erase "$(INTDIR)\MQ2DInput.obj"
	-@erase "$(INTDIR)\MQ2DInput.sbr"
	-@erase "$(INTDIR)\MQ2Globals.obj"
	-@erase "$(INTDIR)\MQ2Globals.sbr"
	-@erase "$(INTDIR)\MQ2KeyBinds.obj"
	-@erase "$(INTDIR)\MQ2KeyBinds.sbr"
	-@erase "$(INTDIR)\MQ2MacroCommands.obj"
	-@erase "$(INTDIR)\MQ2MacroCommands.sbr"
	-@erase "$(INTDIR)\MQ2Main.obj"
	-@erase "$(INTDIR)\MQ2Main.sbr"
	-@erase "$(INTDIR)\MQ2Mouse.obj"
	-@erase "$(INTDIR)\MQ2Mouse.sbr"
	-@erase "$(INTDIR)\MQ2ParseAPI.obj"
	-@erase "$(INTDIR)\MQ2ParseAPI.sbr"
	-@erase "$(INTDIR)\MQ2PluginHandler.obj"
	-@erase "$(INTDIR)\MQ2PluginHandler.sbr"
	-@erase "$(INTDIR)\MQ2Pulse.obj"
	-@erase "$(INTDIR)\MQ2Pulse.sbr"
	-@erase "$(INTDIR)\MQ2Utilities.obj"
	-@erase "$(INTDIR)\MQ2Utilities.sbr"
	-@erase "$(INTDIR)\MQ2Windows.obj"
	-@erase "$(INTDIR)\MQ2Windows.sbr"
	-@erase "$(INTDIR)\MQ2Spawns.obj"
	-@erase "$(INTDIR)\MQ2Spawns.sbr"
	-@erase "$(OUTDIR)\MQ2Main.dll"
	-@erase "$(OUTDIR)\MQ2Main.exp"
	-@erase "$(OUTDIR)\MQ2Main.lib"
	-@erase "$(OUTDIR)\MQ2Main.pdb"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\vc70.idb"
	-@erase "$(INTDIR)\vc70.pdb"
	-@erase "$(INTDIR)\vc80.idb"
	-@erase "$(INTDIR)\vc80.pdb"

CPP_PROJ=$(CPP_PROJ) /D "EQLIB_EXPORTS"
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib winmm.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\MQ2Main.pdb" /debug /machine:I386 /out:"$(OUTDIR)\MQ2Main.dll" /implib:"$(OUTDIR)\MQ2Main.lib" /OPT:NOICF /OPT:NOREF 
LINK32_OBJS= $(DETLIB) \
	"$(INTDIR)\EQClasses.obj" \
	"$(INTDIR)\MQ2Auth.obj" \
	"$(INTDIR)\MQ2Benchmarks.obj" \
	"$(INTDIR)\MQ2ChatHook.obj" \
	"$(INTDIR)\MQ2CleanUI.obj" \
	"$(INTDIR)\MQ2CommandAPI.obj" \
	"$(INTDIR)\MQ2Commands.obj" \
	"$(INTDIR)\MQ2Data.obj" \
	"$(INTDIR)\MQ2DataAPI.obj" \
	"$(INTDIR)\MQ2DataTypes.obj" \
	"$(INTDIR)\MQ2DataVars.obj" \
	"$(INTDIR)\MQ2DetourAPI.obj" \
	"$(INTDIR)\MQ2DInput.obj" \
	"$(INTDIR)\MQ2Globals.obj" \
	"$(INTDIR)\MQ2KeyBinds.obj" \
	"$(INTDIR)\MQ2MacroCommands.obj" \
	"$(INTDIR)\MQ2Main.obj" \
	"$(INTDIR)\MQ2Mouse.obj" \
	"$(INTDIR)\MQ2ParseAPI.obj" \
	"$(INTDIR)\MQ2PluginHandler.obj" \
	"$(INTDIR)\MQ2Pulse.obj" \
	"$(INTDIR)\MQ2Utilities.obj" \
	"$(INTDIR)\MQ2Windows.obj" \
	"$(INTDIR)\MQ2Spawns.obj"

"$(OUTDIR)\MQ2Main.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    -@!if "$(USERNAME)" == "Zerix"  nmake clean
    $(LINK32) $(LINK32_FLAGS) $(LINK32_OBJS)


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("MQ2Main.dep")
!INCLUDE "MQ2Main.dep"
!ELSE 
!MESSAGE Warning: cannot find "MQ2Main.dep"
!ENDIF 
!ENDIF 


SOURCE=.\EQClasses.cpp

"$(INTDIR)\EQClasses.obj"	"$(INTDIR)\EQClasses.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2Auth.cpp

"$(INTDIR)\MQ2Auth.obj"	        "$(INTDIR)\MQ2Auth.sbr" : $(SOURCE) "$(INTDIR)"

SOURCE=.\MQ2Benchmarks.cpp

"$(INTDIR)\MQ2Benchmarks.obj"	"$(INTDIR)\MQ2Benchmarks.sbr" : $(SOURCE) "$(INTDIR)"

SOURCE=.\MQ2ChatHook.cpp

"$(INTDIR)\MQ2ChatHook.obj"	"$(INTDIR)\MQ2ChatHook.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2CleanUI.cpp

"$(INTDIR)\MQ2CleanUI.obj"	"$(INTDIR)\MQ2CleanUI.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2CommandAPI.cpp

"$(INTDIR)\MQ2CommandAPI.obj"	"$(INTDIR)\MQ2CommandAPI.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2Commands.cpp

"$(INTDIR)\MQ2Commands.obj"	"$(INTDIR)\MQ2Commands.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2Data.cpp

"$(INTDIR)\MQ2Data.obj"		"$(INTDIR)\MQ2Data.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2DataAPI.cpp

"$(INTDIR)\MQ2DataAPI.obj"	"$(INTDIR)\MQ2DataAPI.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2DataTypes.cpp

"$(INTDIR)\MQ2DataTypes.obj"	"$(INTDIR)\MQ2DataTypes.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2DataVars.cpp

"$(INTDIR)\MQ2DataVars.obj"	"$(INTDIR)\MQ2DataVars.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2DetourAPI.cpp

"$(INTDIR)\MQ2DetourAPI.obj"	"$(INTDIR)\MQ2DetourAPI.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2DInput.cpp

"$(INTDIR)\MQ2DInput.obj"	"$(INTDIR)\MQ2DInput.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2Globals.cpp

"$(INTDIR)\MQ2Globals.obj"	"$(INTDIR)\MQ2Globals.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2KeyBinds.cpp

"$(INTDIR)\MQ2KeyBinds.obj"	"$(INTDIR)\MQ2KeyBinds.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2MacroCommands.cpp

"$(INTDIR)\MQ2MacroCommands.obj"	"$(INTDIR)\MQ2MacroCommands.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2Main.cpp

"$(INTDIR)\MQ2Main.obj"	"$(INTDIR)\MQ2Main.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2Mouse.cpp

"$(INTDIR)\MQ2Mouse.obj"	"$(INTDIR)\MQ2Mouse.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2ParseAPI.cpp

"$(INTDIR)\MQ2ParseAPI.obj"	"$(INTDIR)\MQ2ParseAPI.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2PluginHandler.cpp

"$(INTDIR)\MQ2PluginHandler.obj"	"$(INTDIR)\MQ2PluginHandler.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2Pulse.cpp

"$(INTDIR)\MQ2Pulse.obj"	"$(INTDIR)\MQ2Pulse.sbr" : $(SOURCE) "$(INTDIR)"


SOURCE=.\MQ2Utilities.cpp

"$(INTDIR)\MQ2Utilities.obj"	"$(INTDIR)\MQ2Utilities.sbr" : $(SOURCE) "$(INTDIR)"

SOURCE=.\MQ2Windows.cpp

"$(INTDIR)\MQ2Windows.obj"	"$(INTDIR)\MQ2Windows.sbr" : $(SOURCE) "$(INTDIR)"



