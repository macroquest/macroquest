// MQ2EQBugFix.cpp : Defines the entry point for the DLL application.
//

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup, do NOT do it in DllMain.



#include "../MQ2Plugin.h"


PreSetup("MQ2EQBugFix");

DETOUR_TRAMPOLINE_EMPTY(DWORD __cdecl JournalNPCCrash_Trampoline(DWORD)); 
DWORD __cdecl JournalNPCCrash_Detour(DWORD Param)
{
	// SOE: This is fixing a crash when newbies exit and have no journal npc
	// entries.  The problem is you have a function that does this:
	// return *JournalNPC::m_strings.Insert(x)
	// and sometimes Insert returns 0!  All I'm doing is checking the return
	// value from Insert.  If it's 0, return 0 instead of *0.
	int ToRet=0;
	__asm
	{
		push [Param];
		mov ecx, 614D20h;
		mov eax, 51B653h;
		call eax;
		mov [ToRet], eax;
	};
	if (ToRet)
	{
		return *(DWORD*)ToRet;
	}
	return 0;
}
DWORD JournalNPCCrash=0x4050F6;

// Called once, when the plugin is to initialize
PLUGIN_API VOID InitializePlugin(VOID)
{
	DebugSpewAlways("Initializing MQ2EQBugFix");

	// Add commands, macro parameters, hooks, etc.
	// AddCommand("/mycommand",MyCommand);
	// AddParm("$myparm(x)",MyParm);
	// removed after 11-25 patch
	
//	DWORD (__cdecl *pfDetour)(DWORD) = JournalNPCCrash_Detour; 
//	DWORD (__cdecl *pfTrampoline)(DWORD) = JournalNPCCrash_Trampoline; 

	if (pinstCEverQuest==0x788de0)
	{
//		AddDetour(JournalNPCCrash,*(PBYTE*)&pfDetour,*(PBYTE*)&pfTrampoline);
		EasyDetour(JournalNPCCrash,JournalNPCCrash_Detour,DWORD,(DWORD),JournalNPCCrash_Trampoline);
	}
	/**/
	// do nothing at this time.
}

// Called once, when the plugin is to shutdown
PLUGIN_API VOID ShutdownPlugin(VOID)
{
	DebugSpewAlways("Shutting down MQ2EQBugFix");

	// Remove commands, macro parameters, hooks, etc.
	// RemoveParm("$myparm(x)");
	// RemoveCommand("/mycommand");
	RemoveDetour(JournalNPCCrash);
}

