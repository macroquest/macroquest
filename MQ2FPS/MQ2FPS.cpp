// MQ2FPS.cpp : Defines the entry point for the DLL application.
//

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup, do NOT do it in DllMain.



#include "../MQ2Plugin.h"
#include "MQ2FPS.h"

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	if (ul_reason_for_call==DLL_PROCESS_ATTACH)
		DebugSpewAlways("MQ2FPS Module Loaded");
	else if (ul_reason_for_call==DLL_PROCESS_DETACH)
		DebugSpewAlways("MQ2FPS Module Unloaded");
    return TRUE;
}

// Called once, when the plugin is to initialize
PLUGIN_API VOID InitializePlugin(VOID)
{
	DebugSpewAlways("Initializing MQ2FPS");

	// Add commands, macro parameters, hooks, etc.
	// INI Settings
    DWORD Temp=0;
    Temp = GetPrivateProfileInt("MQ2FPS","ForegroundMaxFPS",0,FPSINIFile);
    SetForegroundMaxFPS(Temp);
    Temp = GetPrivateProfileInt("MQ2FPS","BackgroundMaxFPS",0,FPSINIFile);
    SetBackgroundMaxFPS(Temp);

	// Commands
	AddCommand("/maxfps",MaxFPS,0,1);
}

// Called once, when the plugin is to shutdown
PLUGIN_API VOID ShutdownPlugin(VOID)
{
	DebugSpewAlways("Shutting down MQ2FPS");

	// Remove commands, macro parameters, hooks, etc.
	RemoveCommand("/maxfps");
}

// Called once directly after initialization, and then every time the gamestate changes
PLUGIN_API VOID SetGameState(DWORD GameState)
{
}

DWORD gFG_SLEEP=0;
DWORD gBG_SLEEP=0;

VOID SetForegroundMaxFPS(DWORD MaxFPS)
{
    if (MaxFPS==0)
        gFG_SLEEP=0;
    else
        gFG_SLEEP=1000/MaxFPS;
}

VOID SetBackgroundMaxFPS(DWORD MaxFPS)
{
    if (MaxFPS==0)
        gBG_SLEEP=0;
    else
        gBG_SLEEP=1000/MaxFPS;
}

// This is called every time MQ pulses
PLUGIN_API VOID OnPulse(VOID)
{
	// DONT leave in this debugspew, even if you leave in all the others
//	DebugSpewAlways("MQ2FPS::OnPulse()");
	if (gGameState!=GAMESTATE_INGAME || gZoning || IsMouseWaiting())
		return;


	if (!gDelay && !gMacroPause && (!gMQPauseOnChat || *EQADDR_NOTINCHATMODE) &&
        gMacroBlock && gMacroStack) {
    }
	else
	{ 
		HWND EQhWnd=*(HWND*)EQADDR_HWND;
		HMODULE hMod=GetModuleHandle("eqw.dll");
		if (hMod)
		{
			DWORD GetEQWHWND=(DWORD)hMod+0x12C0;
			__asm
			{
				push eax;
				call [GetEQWHWND];
				mov [EQhWnd], eax;
				pop eax;
			};
		}
		
		if (GetForegroundWindow()==EQhWnd)
		{
			Sleep(gFG_SLEEP);
		}
		else
		{
			Sleep(gBG_SLEEP);
		}
	}

}

// ***************************************************************************
// Function:      MaxFPS
// Description:   Our /MaxFPS command. Sets or displays the max fps setting for
//                foreground or background
// 2003-11-01     Lax
// ***************************************************************************
VOID MaxFPS(PSPAWNINFO pChar, PCHAR szLine)
{
   bRunNextCommand = TRUE;
   CHAR szCmd[MAX_STRING] = {0};
    CHAR Arg1[MAX_STRING] = {0};
    CHAR Arg2[MAX_STRING] = {0};
    GetArg(Arg1,szLine,1);
    GetArg(Arg2,szLine,2);


   if (Arg1[0]==0 || Arg2[0]==0) {
       sprintf(szCmd,"\aw\ayMaxFPS\ax\a-u:\ax \a-u[\ax\at%d\ax Foreground\a-u]\ax \a-u[\ax\at%d\ax Background\a-u]\ax",gFG_SLEEP?1000/gFG_SLEEP:0,gBG_SLEEP?1000/gBG_SLEEP:0);
        WriteChatColor(szCmd,USERCOLOR_DEFAULT);
        WriteChatColor("Usage: /maxfps <fg|bg> <#>",USERCOLOR_DEFAULT);
        return;
   }
   DWORD NewMax=atoi(Arg2);
   if (NewMax>200)
   {
       WriteChatColor("MaxFPS: Please use a number between 0 and 200, 0 being absolute fastest, 1-200 being that many frames per second.",USERCOLOR_DEFAULT);
       return;
   }

   if (!stricmp(Arg1,"fg"))
   {
     SetForegroundMaxFPS(NewMax);
       WritePrivateProfileString("MQ2FPS","ForegroundMaxFPS",Arg2,FPSINIFile);
   }
   else if (!stricmp(Arg1,"bg"))
   {
       SetBackgroundMaxFPS(NewMax);
       WritePrivateProfileString("MQ2FPS","BackgroundMaxFPS",Arg2,FPSINIFile);
   }
       sprintf(szCmd,"\aw\ayMaxFPS\ax\a-u:\ax \a-u[\ax\at%d\ax Foreground\a-u]\ax \a-u[\ax\at%d\ax Background\a-u]\ax",gFG_SLEEP?1000/gFG_SLEEP:0,gBG_SLEEP?1000/gBG_SLEEP:0);
    WriteChatColor(szCmd,USERCOLOR_DEFAULT);
}
