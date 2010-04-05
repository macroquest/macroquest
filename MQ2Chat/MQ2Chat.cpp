// MQ2Chat.cpp : Defines the entry point for the DLL application.
// The "old" chat plugin



#include "../MQ2Plugin.h"

PreSetup("MQ2Chat");


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
    dsp_chat_no_events(Stripped,Color,1);
    return 0;
}

