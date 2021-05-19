// MQ2Pizza.cpp : Defines the entry point for the DLL application.
//

// PLUGIN_API is only to be used for callbacks.  All existing callbacks at this time
// are shown below. Remove the ones your plugin does not use.  Always use Initialize
// and Shutdown for setup and cleanup.
// Created by Cybris
// Adding /Pizza back to the game.

#include <mq/Plugin.h>

PreSetup("MQ2Pizza");
PLUGIN_VERSION(0.1);

void Pizza(PSPAWNINFO pCHAR, PCHAR szLine)
{
	DoCommand(GetCharInfo()->pSpawn,"/www pizzahut.com");
}

PLUGIN_API void InitializePlugin()
{
	DebugSpewAlways("MQ2Pizza::Initializing version %f", MQ2Version);
	AddCommand("/pizza", Pizza);
}


PLUGIN_API void ShutdownPlugin()
{
	DebugSpewAlways("MQ2Pizza::Shutting down");
	RemoveCommand("/pizza");
}

