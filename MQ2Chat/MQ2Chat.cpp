// MQ2Chat.cpp : Defines the entry point for the DLL application.
// The "old" chat plugin



#include "../MQ2Plugin.h"

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	if (ul_reason_for_call==DLL_PROCESS_ATTACH)
		DebugSpewAlways("MQ2Chat Module Loaded");
	else if (ul_reason_for_call==DLL_PROCESS_DETACH)
		DebugSpewAlways("MQ2Chat Module Unloaded");
    return TRUE;
}

PLUGIN_API VOID InitializePlugin(VOID)
{
	DebugSpewAlways("Initializing MQ2Chat");
	// Add commands, macro parameters, hooks, etc.
}

PLUGIN_API VOID ShutdownPlugin(VOID)
{
	DebugSpewAlways("Shutting down MQ2Chat");

	// Remove commands, macro parameters, hooks, etc.
}

PLUGIN_API DWORD OnWriteChatColor(PCHAR Line, DWORD Color, DWORD Filter)
{
	// This is called every time WriteChatColor is called by MQ2Main or any plugin,
	// IGNORING FILTERS, IF YOU NEED THEM MAKE SURE TO IMPLEMENT THEM. IF YOU DONT
	// CALL CEverQuest::dsp_chat MAKE SURE TO IMPLEMENT EVENTS HERE
	CHAR Stripped[MAX_STRING];
	StripMQChat(Line,Stripped);
	if (gFilterMacro == FILTERMACRO_NONE) return 0;
	if (!ppEverQuest) return 0;
	if (gGameState!=GAMESTATE_INGAME) return 0;

	if (!pEverQuest) 
		return 0;
	pEverQuest->dsp_chat(Stripped,Color,1);
/*
	DWORD clsEverQuest = *EQADDR_CLSEVERQUEST;
	DWORD saddr=(DWORD)&Stripped[0];
	DWORD Func=EQADDR_DSPCHAT; // we can't directly call EQADDR_DSPCHAT. need local copy :)
	if (!clsEverQuest) return 0;
		__asm {
			push ecx;
			mov ecx, [clsEverQuest];
			push 1;
			push [Color];
			push [saddr];
			call Func;
			pop ecx;
		}
/**/
	return 0;
}

