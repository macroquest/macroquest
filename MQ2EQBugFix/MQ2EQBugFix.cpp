// MQ2EQBugFix.cpp : Defines the entry point for the DLL application.
//

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup, do NOT do it in DllMain.



#include "../MQ2Plugin.h"

PreSetup("MQ2EQBugFix");
//A1B408 ; int __cdecl startworddisplayexceptionhandler()
int __cdecl startworddisplayexceptionhandler_Trampoline(struct EHExceptionRecord *, struct EHRegistrationNode *, struct _CONTEXT *, void *);   
int __cdecl startworddisplayexceptionhandler_Detour(struct EHExceptionRecord *A, struct EHRegistrationNode *B, struct _CONTEXT *C, void *D)
{
	MessageBox(NULL, "WHY!!?", "Crashed in startworddisplay", MB_SYSTEMMODAL | MB_OK);
	DebugBreak();
	int ret = startworddisplayexceptionhandler_Trampoline(A, B, C, D);
	return ret;
}
DETOUR_TRAMPOLINE_EMPTY(int __cdecl startworddisplayexceptionhandler_Trampoline(struct EHExceptionRecord *, struct EHRegistrationNode *, struct _CONTEXT *, void *));

class CDisplay_Hook
{
public:
    int is_3dON_Trampoline();   
    int is_3dON_Detour()
    {
        if(!this)
        {
            DebugSpew("MQ2EQBugFix::Crash avoided!");
            return 0;
        }
        return is_3dON_Trampoline();
    }
};
#define startworlddisplayexceptionhandler_x 0xA1B408

#define INITIALIZE_EQGAME_OFFSET(var) DWORD var = (((DWORD)var##_x - 0x400000) + (DWORD)GetModuleHandle(NULL))

DETOUR_TRAMPOLINE_EMPTY(int CDisplay_Hook::is_3dON_Trampoline());
INITIALIZE_EQGAME_OFFSET(startworlddisplayexceptionhandler);

PLUGIN_API VOID InitializePlugin(VOID)
{
    DebugSpewAlways("Initializing MQ2EQBugFix");
    EzDetour(CDisplay__is3dON, &CDisplay_Hook::is_3dON_Detour, &CDisplay_Hook::is_3dON_Trampoline);
    //EzDetour(startworlddisplayexceptionhandler, startworddisplayexceptionhandler_Detour, startworddisplayexceptionhandler_Trampoline);
	
}

PLUGIN_API VOID ShutdownPlugin(VOID)
{
    DebugSpewAlways("Shutting down MQ2EQBugFix");
    RemoveDetour(CDisplay__is3dON);
    //RemoveDetour(startworlddisplayexceptionhandler);
}