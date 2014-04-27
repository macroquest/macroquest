// MQ2EQBugFix.cpp : Defines the entry point for the DLL application.
//

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup, do NOT do it in DllMain.



#include "../MQ2Plugin.h"

PreSetup("MQ2EQBugFix");

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

DETOUR_TRAMPOLINE_EMPTY(int CDisplay_Hook::is_3dON_Trampoline());

PLUGIN_API VOID InitializePlugin(VOID)
{
    DebugSpewAlways("Initializing MQ2EQBugFix");
    EzDetour(CDisplay__is3dON, &CDisplay_Hook::is_3dON_Detour, &CDisplay_Hook::is_3dON_Trampoline);
}

PLUGIN_API VOID ShutdownPlugin(VOID)
{
    DebugSpewAlways("Shutting down MQ2EQBugFix");
    RemoveDetour(CDisplay__is3dON);
}