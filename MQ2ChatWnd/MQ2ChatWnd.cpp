// MQ2ChatWnd.cpp : Defines the entry point for the DLL application.
//

// Single-window MQ Chat


#include "../MQ2Plugin.h"

PEQCHATWINDOW MQChatWnd=0;
#define pMQChatWnd ((CChatWindow*)MQChatWnd)
#define pOutStmlWnd ((CStmlWnd*)MQChatWnd->OutputWnd)
#define pOutXWnd ((CXWnd*)MQChatWnd->OutputWnd)
#define pXWnd ((CXWnd*)MQChatWnd)

//#define DEBUG_TRY 1
#ifdef DEBUG_TRY
#define DebugTry(x) DebugSpew("Trying %s",#x);x;DebugSpew("%s complete",#x)
#else
#define DebugTry(x) x
#endif


PLUGIN_API VOID OnCleanUI(VOID);
PLUGIN_API VOID SetGameState(DWORD GameState);

PreSetup("MQ2ChatWnd");


CHAR szChatINISection[MAX_STRING] = {0};
void LoadChatFromINI(PCSIDLWND pWindow)
{
	CHAR Buffer[MAX_STRING] = {0};
    sprintf(szChatINISection,"%s.%s",((PCHARINFO)pCharData)->Server,((PCHARINFO)pCharData)->Name);
	pWindow->Location.top		= GetPrivateProfileInt(szChatINISection,"ChatTop",    10,INIFileName);
	pWindow->Location.bottom	= GetPrivateProfileInt(szChatINISection,"ChatBottom",210,INIFileName);
	pWindow->Location.left		= GetPrivateProfileInt(szChatINISection,"ChatLeft",   10,INIFileName);
	pWindow->Location.right 	= GetPrivateProfileInt(szChatINISection,"ChatRight", 410,INIFileName);
	pWindow->Locked			 	= GetPrivateProfileInt(szChatINISection,"Locked",	   0,INIFileName);
	MQChatWnd->FontSize			= GetPrivateProfileInt(szChatINISection,"FontSize",	   4,INIFileName);

	pWindow->Fades			 	= GetPrivateProfileInt(szChatINISection,"Fades",	   1,INIFileName);
	pWindow->TimeMouseOver	 	= GetPrivateProfileInt(szChatINISection,"Delay",	 2000,INIFileName);
	pWindow->FadeDuration	 	= GetPrivateProfileInt(szChatINISection,"Duration",	   500,INIFileName);
	pWindow->Alpha				= GetPrivateProfileInt(szChatINISection,"Alpha",	   255,INIFileName);
	pWindow->FadeToAlpha		= GetPrivateProfileInt(szChatINISection,"FadeToAlpha",	   255,INIFileName);
	pWindow->BGType				= GetPrivateProfileInt(szChatINISection,"BGType",	   1,INIFileName);
	pWindow->BGColor.R				= GetPrivateProfileInt(szChatINISection,"BGTint.red",	   255,INIFileName);
	pWindow->BGColor.G				= GetPrivateProfileInt(szChatINISection,"BGTint.green",	   255,INIFileName);
	pWindow->BGColor.B				= GetPrivateProfileInt(szChatINISection,"BGTint.blue",	   255,INIFileName);

	GetPrivateProfileString(szChatINISection,"WindowTitle","MQ",Buffer,MAX_STRING,INIFileName);
	SetCXStr(&pWindow->WindowText,Buffer);
}

void SaveChatToINI(PCSIDLWND pWindow)
{
	CHAR szTemp[MAX_STRING] = {0};
	if (pWindow->Minimized)
	{
		WritePrivateProfileString(szChatINISection,"ChatTop",	itoa(pWindow->OldLocation.top,		szTemp,10),INIFileName);
		WritePrivateProfileString(szChatINISection,"ChatBottom",itoa(pWindow->OldLocation.bottom,	szTemp,10),INIFileName);
		WritePrivateProfileString(szChatINISection,"ChatLeft",	itoa(pWindow->OldLocation.left,		szTemp,10),INIFileName);
		WritePrivateProfileString(szChatINISection,"ChatRight",	itoa(pWindow->OldLocation.right,	szTemp,10),INIFileName);
	}
	else
	{
		WritePrivateProfileString(szChatINISection,"ChatTop",	itoa(pWindow->Location.top,		szTemp,10),INIFileName);
		WritePrivateProfileString(szChatINISection,"ChatBottom",itoa(pWindow->Location.bottom,	szTemp,10),INIFileName);
		WritePrivateProfileString(szChatINISection,"ChatLeft",	itoa(pWindow->Location.left,	szTemp,10),INIFileName);
		WritePrivateProfileString(szChatINISection,"ChatRight",	itoa(pWindow->Location.right,	szTemp,10),INIFileName);
	}
	WritePrivateProfileString(szChatINISection,"Locked",	itoa(pWindow->Locked,			szTemp,10),INIFileName);

	GetCXStr(pWindow->WindowText,szTemp);
	WritePrivateProfileString(szChatINISection,"WindowTitle",	szTemp				  ,INIFileName);

	WritePrivateProfileString(szChatINISection,"Fades",	itoa(pWindow->Fades,			szTemp,10),INIFileName);
	WritePrivateProfileString(szChatINISection,"Delay",	itoa(pWindow->MouseOver,			szTemp,10),INIFileName);
	WritePrivateProfileString(szChatINISection,"Duration",	itoa(pWindow->FadeDuration,			szTemp,10),INIFileName);
	WritePrivateProfileString(szChatINISection,"Alpha",	itoa(pWindow->Alpha,			szTemp,10),INIFileName);
	WritePrivateProfileString(szChatINISection,"FadeToAlpha",	itoa(pWindow->FadeToAlpha,			szTemp,10),INIFileName);
	WritePrivateProfileString(szChatINISection,"BGType",	itoa(pWindow->BGType,			szTemp,10),INIFileName);
	WritePrivateProfileString(szChatINISection,"BGTint.red",	itoa(pWindow->BGColor.R,			szTemp,10),INIFileName);
	WritePrivateProfileString(szChatINISection,"BGTint.green",	itoa(pWindow->BGColor.G,			szTemp,10),INIFileName);
	WritePrivateProfileString(szChatINISection,"BGTint.blue",	itoa(pWindow->BGColor.B,			szTemp,10),INIFileName);

	WritePrivateProfileString(szChatINISection,"FontSize",	itoa(MQChatWnd->FontSize,			szTemp,10),INIFileName);
	
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
	OnCleanUI();
}


// This is called every time WriteChatColor is called by MQ2Main or any plugin,
// IGNORING FILTERS, IF YOU NEED THEM MAKE SURE TO IMPLEMENT THEM. IF YOU DONT
// CALL CEverQuest::dsp_chat MAKE SURE TO IMPLEMENT EVENTS HERE
PLUGIN_API DWORD OnWriteChatColor(PCHAR Line, DWORD Color, DWORD Filter)
{
	DebugSpewAlways("MQ2ChatWnd::OnWriteChatColor(%s)",Line);
	if (!MQChatWnd)
	{
		if (gGameState==GAMESTATE_INGAME)
		{
			SetGameState(gGameState);
		}
		if (!MQChatWnd)
			return 0; 
	}

	PFILTER pFilter = gpFilters; 

	while (pFilter) { 
		if (!pFilter->pEnabled || (*pFilter->pEnabled)) { 
			if (!strnicmp(Line,pFilter->FilterText,pFilter->Length)) {return 0;}
		} 
		pFilter = pFilter->pNext; 
	} 
	Color=pChatManager->GetRGBAFromIndex(Color);

	CHAR szProcessed[MAX_STRING];
	StripMQChat(Line,szProcessed);
	CheckChatForEvent(szProcessed);
	MQToSTML(Line,szProcessed,MAX_STRING,Color);
	strcat(szProcessed,"<br>");
	CXStr NewText(szProcessed);
	DebugTry(ConvertItemTags(NewText));
	CXSize Whatever;
	DebugTry(pOutStmlWnd->AppendSTML(&Whatever,NewText));
	DebugTry(pOutXWnd->SetVScrollPos(MQChatWnd->OutputWnd->VScrollMax));
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
		SaveChatToINI((PCSIDLWND)MQChatWnd);
		DWORD destructor=(DWORD)MQChatWnd->Wnd.pvfTable->vector_deleting_destructor; 
		__asm { 
			push ecx; 
			mov ecx, MQChatWnd; 
			push 1; 
			call [destructor]; 
			pop ecx; 
		}; 
		MQChatWnd=0;
	}
}

// Called once directly after initialization, and then every time the gamestate changes
PLUGIN_API VOID SetGameState(DWORD GameState)
{
	if (GameState==GAMESTATE_INGAME && !MQChatWnd)
	{
		// we entered the game, set up shop
		if (!pChatManager)
		{
			DebugSpewAlways("MQChatWnd: In-game and no pChatManager, sorry!");
			return; // fuck.. how did thishappen while in game?!
		}
		DebugTry(MQChatWnd=(PEQCHATWINDOW)new CChatWindow(0));
		DebugTry(MQChatWnd->Wnd.ContextMenu=(LPVOID)pChatManager->InitContextMenu(pMQChatWnd));
		MQChatWnd->ChatManager=(PEQCHATMGR)pChatManager;
		DebugTry(((CXWnd*)MQChatWnd)->Show(1,1));
		DebugTry(BitOff(MQChatWnd->Wnd.WindowStyle,CWS_CLOSE));
		// load from INI
		LoadChatFromINI((PCSIDLWND)MQChatWnd);
	}
}
// todo
VOID MQChatFont(PSPAWNINFO pChar, PCHAR Line)
{
}

