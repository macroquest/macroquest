/*****************************************************************************
    eqlib.dll: MacroQuest's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
******************************************************************************/

#if !defined(CINTERFACE)
#error /DCINTERFACE
#endif

#define DBG_SPEW


#include "MQ2Main.h"


CRITICAL_SECTION gPluginCS;
BOOL bPluginCS=0;

DWORD LoadMQ2Plugin(const PCHAR pszFilename)
{
	CHAR Filename[MAX_PATH]={0};
	strcpy(Filename,pszFilename);
	strlwr(Filename);
	PCHAR Temp=strstr(Filename,".dll");
	if (!Temp)
		strcat(Filename,".dll");
	
	CAutoLock Lock(&gPluginCS);
	DebugSpew("LoadMQ2Plugin(%s)",Filename);
	CHAR FullFilename[MAX_STRING]={0};
	sprintf(FullFilename,"%s\\%s",gszINIPath,Filename);
	HMODULE hmod=LoadLibrary(FullFilename);
	if (!hmod)
	{
		DebugSpew("LoadMQ2Plugin(%s) Failed",Filename);
		return 0;
	}

	PMQPLUGIN pPlugin=pPlugins;
	while(pPlugin)
	{
		if (hmod==pPlugin->hModule)
		{
			DebugSpew("LoadMQ2Plugin(%s) already loaded",Filename);
			// LoadLibrary count must match FreeLibrary count for unloading to work.
			FreeLibrary(hmod);
			return 2; // already loaded
		}
		pPlugin=pPlugin->pNext;
	}

	pPlugin = new MQPLUGIN;
	memset(pPlugin,0,sizeof(MQPLUGIN));
	pPlugin->hModule=hmod;
	strcpy(pPlugin->szFilename,Filename);
	pPlugin->Initialize=(fMQInitializePlugin)GetProcAddress(hmod,"InitializePlugin");
	pPlugin->Shutdown=(fMQShutdownPlugin)GetProcAddress(hmod,"ShutdownPlugin");
	pPlugin->IncomingChat=(fMQIncomingChat)GetProcAddress(hmod,"OnIncomingChat");
	pPlugin->Pulse=(fMQPulse)GetProcAddress(hmod,"OnPulse");
	pPlugin->WriteChatColor=(fMQWriteChatColor)GetProcAddress(hmod,"OnWriteChatColor");
	pPlugin->Zoned=(fMQZoned)GetProcAddress(hmod,"OnZoned");
	pPlugin->CleanUI=(fMQCleanUI)GetProcAddress(hmod,"OnCleanUI");
	pPlugin->DrawHUD=(fMQDrawHUD)GetProcAddress(hmod,"OnDrawHUD");
	pPlugin->SetGameState=(fMQSetGameState)GetProcAddress(hmod,"SetGameState");

	if (pPlugin->Initialize)
		pPlugin->Initialize();
	if (pPlugin->SetGameState)
		pPlugin->SetGameState(gGameState);

	pPlugin->pLast=0;
	pPlugin->pNext=pPlugins;
	if (pPlugins)
		pPlugins->pLast=pPlugin;
	pPlugins=pPlugin;

	return 1;
}

BOOL UnloadMQ2Plugin(const PCHAR pszFilename)
{
	DebugSpew("UnloadMQ2Plugin");
	CHAR Filename[MAX_PATH]={0};
	strcpy(Filename,pszFilename);
	strlwr(Filename);
	PCHAR Temp=strstr(Filename,".dll");
	if (!Temp)
		strcat(Filename,".dll");
	
	// find plugin in list
	CAutoLock Lock(&gPluginCS);
	PMQPLUGIN pPlugin=pPlugins;
	while(pPlugin)
	{
		if (!stricmp(Filename,pPlugin->szFilename))
		{
			if (pPlugin->pLast)
				pPlugin->pLast->pNext=pPlugin->pNext;
			else
				pPlugins=pPlugin->pNext;

			if (pPlugin->pNext)
				pPlugin->pNext->pLast=pPlugin->pLast;
			if (pPlugin->CleanUI)
				pPlugin->CleanUI();
			if (pPlugin->Shutdown)
				pPlugin->Shutdown();
			FreeLibrary(pPlugin->hModule);
			delete pPlugin;
			return 1;
		}
		pPlugin=pPlugin->pNext;
	}

	return 0;
}

VOID RewriteMQ2Plugins(VOID)
{
	CAutoLock Lock(&gPluginCS);
    WritePrivateProfileSection("Plugins","",gszINIFilename);
    PMQPLUGIN pLoop = pPlugins;
	if (!pLoop)
		return;
	// start from the end, we're writing this the order they were added.
	while (pLoop->pNext)
		pLoop=pLoop->pNext; 
    while (pLoop) {
        WritePrivateProfileString("Plugins",pLoop->szFilename,pLoop->szFilename,gszINIFilename);
        pLoop = pLoop->pLast;
    }
}

VOID InitializeMQ2Plugins()
{
	DebugSpew("Initializing plugins");
	InitializeCriticalSection(&gPluginCS);
	bPluginCS=1;

	CHAR PluginList[MAX_STRING*10] = {0};
    CHAR szBuffer[MAX_STRING] = {0};
    CHAR MainINI[MAX_STRING] = {0};
    sprintf(MainINI,"%s\\macroquest.ini",gszINIPath);
	GetPrivateProfileString("Plugins",NULL,"",PluginList,MAX_STRING*10,MainINI);
    PCHAR pPluginList = PluginList;
    while (pPluginList[0]!=0) {
        GetPrivateProfileString("Plugins",pPluginList,"",szBuffer,MAX_STRING,MainINI);
        if (szBuffer[0]!=0) {
			LoadMQ2Plugin(szBuffer);
        }
        pPluginList+=strlen(pPluginList)+1;
    }
}

VOID ShutdownMQ2Plugins()
{
	bPluginCS=0;
	{
	//	CAutoLock Lock(&gPluginCS);
		while(pPlugins)
		{
			DebugSpew("%s->Unload()",pPlugins->szFilename);
			UnloadMQ2Plugin(pPlugins->szFilename);
		}
	}
	DeleteCriticalSection(&gPluginCS);
}

VOID WriteChatColor(PCHAR Line, DWORD Color, DWORD Filter)
{
	if (!bPluginCS)
		return;
	DebugSpew("WriteChatColor(%s)",Line);
	CAutoLock Lock(&gPluginCS);

	PMQPLUGIN pPlugin=pPlugins;
	while(pPlugin)
	{
		if (pPlugin->WriteChatColor)
		{
			pPlugin->WriteChatColor(Line,Color,Filter);
		}
		pPlugin=pPlugin->pNext;
	}
}

VOID PluginsIncomingChat(PCHAR Line, DWORD Color)
{
	if (!bPluginCS)
		return;
    if(!Line[0])
        return;
	CAutoLock Lock(&gPluginCS);
	PMQPLUGIN pPlugin=pPlugins;
	while(pPlugin)
	{
		if (pPlugin->IncomingChat)
		{
			pPlugin->IncomingChat(Line,Color);
		}
		pPlugin=pPlugin->pNext;
	}
}

VOID PulsePlugins()
{
	if (!bPluginCS)
		return;
	CAutoLock Lock(&gPluginCS);
	PMQPLUGIN pPlugin=pPlugins;
	while(pPlugin)
	{
		if (pPlugin->Pulse)
		{
//			DebugSpew("%s->Pulse()",pPlugin->szFilename);
			pPlugin->Pulse();
		}
		pPlugin=pPlugin->pNext;
	}	
}

VOID PluginsZoned()
{
	if (!bPluginCS)
		return;
	CAutoLock Lock(&gPluginCS);
	PMQPLUGIN pPlugin=pPlugins;
	while(pPlugin)
	{
		if (pPlugin->Zoned)
		{
			DebugSpew("%s->Zoned()",pPlugin->szFilename);
			pPlugin->Zoned();
		}
		pPlugin=pPlugin->pNext;
	}
}

VOID PluginsCleanUI()
{
	if (!bPluginCS)
		return;
	CAutoLock Lock(&gPluginCS);
	PMQPLUGIN pPlugin=pPlugins;
	while(pPlugin)
	{
		if (pPlugin->CleanUI)
		{
			DebugSpew("%s->CleanUI()",pPlugin->szFilename);
			pPlugin->CleanUI();
		}
		pPlugin=pPlugin->pNext;
	}
}

VOID PluginsSetGameState(DWORD GameState)
{
	if (!bPluginCS)
		return;
	gGameState=GameState;
	CAutoLock Lock(&gPluginCS);
	DebugSpew("PluginsSetGameState(%d)",GameState);
	PMQPLUGIN pPlugin=pPlugins;
	while(pPlugin)
	{
		if (pPlugin->SetGameState)
		{
			DebugSpew("%s->SetGameState(%d)",pPlugin->szFilename,GameState);
			pPlugin->SetGameState(GameState);
		}
		pPlugin=pPlugin->pNext;
	}
}

VOID PluginsDrawHUD()
{
	if (!bPluginCS)
		return;
	CAutoLock Lock(&gPluginCS);
	PMQPLUGIN pPlugin=pPlugins;
	while(pPlugin)
	{
		if (pPlugin->DrawHUD)
		{
//			DebugSpew("%s->DrawHUD()",pPlugin->szFilename);
			pPlugin->DrawHUD();
		}
		pPlugin=pPlugin->pNext;
	}
}
