// MQ2EQBugFix.cpp : Defines the entry point for the DLL application.
//

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup, do NOT do it in DllMain.



#include "../MQ2Plugin.h"


PreSetup("MQ2EQBugFix");
#define CDisplay__FindZoneTopZ 0x410EF5 
class CDisplayBugFix
{
public:
	float FindZoneTopZ_Trampoline(float X, float Y, float Z);
	float FindZoneTopZ_Detour(float X, float Y, float Z)
	{
		CHAR Temp[MAX_STRING]={0};
		sprintf(Temp,"%f",Temp);
		if (!strstr(Temp,"NAN") && !strstr(Temp,"INF"))
			return FindZoneTopZ_Trampoline(X,Y,Z);
		DebugSpew("FIXING INFINITE LOOP!");
		return FindZoneTopZ_Trampoline(X,Y,0);//(float)1.0e-1;
	}
};

DETOUR_TRAMPOLINE_EMPTY(float CDisplayBugFix::FindZoneTopZ_Trampoline(float,float,float));

// Called once, when the plugin is to initialize
PLUGIN_API VOID InitializePlugin(VOID)
{
	DebugSpewAlways("Initializing MQ2EQBugFix");
	EzDetour(CDisplay__FindZoneTopZ,CDisplayBugFix::FindZoneTopZ_Detour,CDisplayBugFix::FindZoneTopZ_Trampoline);
}

// Called once, when the plugin is to shutdown
PLUGIN_API VOID ShutdownPlugin(VOID)
{
	DebugSpewAlways("Shutting down MQ2EQBugFix");
	RemoveDetour(CDisplay__FindZoneTopZ);
}

