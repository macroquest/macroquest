// MQ2ChatWnd.cpp : Defines the entry point for the DLL application.
//

// Single-window MQ Chat


#include "../MQ2Plugin.h"

PEQCHATWINDOW MQChatWnd=0;
#define pMQChatWnd ((CChatWindow*)MQChatWnd)
#define pStmlWnd ((CStmlWnd*)MQChatWnd)
#define pXWnd ((CXWnd*)MQChatWnd)

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	if (ul_reason_for_call==DLL_PROCESS_ATTACH)
		DebugSpewAlways("MQ2ChatWnd Module Loaded");
	else if (ul_reason_for_call==DLL_PROCESS_DETACH)
		DebugSpewAlways("MQ2ChatWnd Module Unloaded");
    return TRUE;
}

PLUGIN_API VOID InitializePlugin(VOID)
{
	DebugSpewAlways("Initializing MQ2ChatWnd");

	// Add commands, macro parameters, hooks, etc.
}

PLUGIN_API VOID ShutdownPlugin(VOID)
{
	DebugSpewAlways("Shutting down MQ2ChatWnd");

	// Remove commands, macro parameters, hooks, etc.
	if (MQChatWnd)
	{
		DebugSpewAlways("MQ2ChatWnd: OnCleanUI not called!");
		// hmmm this wasnt destroyed!
		delete pMQChatWnd;
		MQChatWnd=0;
	}
}

// This is called every time WriteChatColor is called by MQ2Main or any plugin,
// IGNORING FILTERS, IF YOU NEED THEM MAKE SURE TO IMPLEMENT THEM. IF YOU DONT
// CALL CEverQuest::dsp_chat MAKE SURE TO IMPLEMENT EVENTS HERE
PLUGIN_API DWORD OnWriteChatColor(PCHAR Line, DWORD Color, DWORD Filter)
{
	DebugSpewAlways("MQ2ChatWnd::OnWriteChatColor(%s)",Line);
	if (!MQChatWnd)
		return 0; // no need to check gamestate, we have it hooked

	PFILTER pFilter = gpFilters; 

	while (pFilter) { 
		if (!pFilter->pEnabled || (*pFilter->pEnabled)) { 
			if (!strnicmp(Line,pFilter->FilterText,pFilter->Length)) {return 0;}
		} 
		pFilter = pFilter->pNext; 
	} 

	CHAR szProcessed[MAX_STRING];
	StripMQChat(Line,szProcessed);
	CheckChatForEvent(szProcessed);
	MQToSTML(Line,szProcessed,MAX_STRING,Color);
	strcat(szProcessed,"<br>");
	CXStr NewText(szProcessed);
	ConvertItemTags(NewText);
	pStmlWnd->AppendSTML(NewText);
	pXWnd->SetVScrollPos(MQChatWnd->OutputWnd->VScrollMax);
	return 0;
}

// Called once directly before shutdown of the cleanui system, and also
// every time the game calls CDisplay::CleanGameUI()
PLUGIN_API VOID OnCleanUI(VOID)
{
	DebugSpewAlways("MQ2ChatWnd::OnCleanUI()");
	// destroy chat window
	if (MQChatWnd)
	{
		delete pMQChatWnd;
		MQChatWnd=0;
	}
}

// Called once directly after initialization, and then every time the gamestate changes
PLUGIN_API VOID SetGameState(DWORD GameState)
{
	if (GameState==GAMESTATE_INGAME)
	{
		// we entered the game, set up shop
		if (!pChatManager)
		{
			DebugSpewAlways("MQChatWnd: In-game and no pChatManager, sorry!");
			return; // fuck.. how did thishappen while in game?!
		}

		MQChatWnd=(PEQCHATWINDOW)new CChatWindow(0);
		MQChatWnd->Wnd.ContextMenu=(LPVOID)pChatManager->InitContextMenu(pMQChatWnd);
		((CXWnd*)MQChatWnd)->Show(1,1);
		BitOff(MQChatWnd->Wnd.WindowStyle,CWS_CLOSE);
		// load from INI
	}
}



