// MQ2EQIM.cpp : Defines the entry point for the DLL application.
//

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup, do NOT do it in DllMain.

#include "../MQ2Plugin.h"

PreSetup("MQ2EQIM");


#define BUDDY_OFFLINE   1
#define BUDDY_EQIM      2
#define BUDDY_EQIMAFK   3
#define BUDDY_ONLINE    5
#define BUDDY_ONLINEAFK 6

PCHAR szBuddyStatus[]=
{
	"\a-wRemoved from list\ax",
	"\a-wOffline\ax",
	"\atEQIM\ax",
	"\a-tEQIM (AFK)\ax",
	"Unknown Status(4)",
	"\agPlaying\ax",
	"\a-gPlaying (AFK)\ax",
};
VOID OnBuddyStatusChange(char *Buddy, DWORD Status);
DWORD PreDetour[10]={0};
BOOL Detoured=false;
// Called once, when the plugin is to initialize

void SetVTable(DWORD index, DWORD value)
{
	DWORD oldperm=0;
	DWORD Address=(DWORD)&(*((DWORD**)pEverQuest))[index];
	DebugSpewAlways("SetVTable writing at address %X to %X",Address,value);
  VirtualProtectEx(GetCurrentProcess(), (LPVOID)Address, 4,PAGE_EXECUTE_READWRITE, &oldperm);
 WriteProcessMemory(
  GetCurrentProcess(),
  (LPVOID)Address,
  (LPVOID)&value,
  4,
  NULL);
 VirtualProtectEx(GetCurrentProcess(), (LPVOID)Address, 4, oldperm, &oldperm);
}

DWORD GetVTable(DWORD index)
{
	DWORD Ret=(*((DWORD**)pEverQuest))[index];
	DebugSpewAlways("GetVTable(%d)=%X",index,Ret);
	return Ret;
}

PLUGIN_API VOID InitializePlugin(VOID)
{
	DebugSpewAlways("Initializing MQ2EQIM");

	// Add commands, macro parameters, hooks, etc.
	// AddCommand("/mycommand",MyCommand);
	// AddParm("$myparm(x)",MyParm);
		
}

// Called once, when the plugin is to shutdown
PLUGIN_API VOID ShutdownPlugin(VOID)
{
	DebugSpewAlways("Shutting down MQ2EQIM");

	// Remove commands, macro parameters, hooks, etc.
	// RemoveParm("$myparm(x)");
	// RemoveCommand("/mycommand");
	if (Detoured && pEverQuest)
		SetVTable(8,PreDetour[8]);
}

// Called after entering a new zone
/*
PLUGIN_API VOID OnZoned(VOID)
{
	DebugSpewAlways("MQ2EQIM::OnZoned()");
}
/**/
// Called once directly before shutdown of the cleanui system, and also
// every time the game calls CDisplay::CleanGameUI()
/*
PLUGIN_API VOID OnCleanUI(VOID)
{
	DebugSpewAlways("MQ2EQIM::OnCleanUI()");
}
/**/
// Called every frame that the "HUD" is drawn -- e.g. net status / packet loss bar
/*
PLUGIN_API VOID OnDrawHUD(VOID)
{
	// DONT leave in this debugspew, even if you leave in all the others
//	DebugSpewAlways("MQ2EQIM::OnDrawHUD()");
}
/**/
// Called once directly after initialization, and then every time the gamestate changes

PLUGIN_API VOID SetGameState(DWORD GameState)
{
//	DebugSpewAlways("MQ2EQIM::SetGameState()");
	if (GameState==GAMESTATE_INGAME && !Detoured)
	{
		PreDetour[8]=GetVTable(8);
		SetVTable(8,(DWORD)OnBuddyStatusChange);
		GetVTable(8);
		Detoured=true;
	}
}
/**/

// This is called every time MQ pulses
PLUGIN_API VOID OnPulse(VOID)
{
	// DONT leave in this debugspew, even if you leave in all the others
//	DebugSpewAlways("MQ2EQIM::OnPulse()");
}

VOID OnBuddyStatusChange(char *Buddy, DWORD Status)
{
//	DebugSpewAlways("DetourTestA(%s,%X)",A,B);
	char out[MAX_STRING]={0};
	if (Status<=6)
	{
		sprintf(out,"\ar*\ax %s: %s",Buddy,szBuddyStatus[Status]);
	}
	else
		sprintf(out,"\ar*\ax %s: Unknown Status(%d)",Status);
	WriteChatColor(out);
}

