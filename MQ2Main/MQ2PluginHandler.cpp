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

#include "stdafx.h"
#include "MQ2Main.h"

/*
Plugin Interface Specification
GetName
InitializeMQPlugin
ShutdownMQPlugin

*/




PMQPLUGIN pPlugins=0;
CRITICAL_SECTION gPluginCS;

DWORD LoadMQ2Plugin(const PCHAR Filename)
{
//	CAutoLock Lock(&gPluginCS);
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
			return 2; // already loaded
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

	if (pPlugin->Initialize)
		pPlugin->Initialize();

	pPlugin->pLast=0;
	pPlugin->pNext=pPlugins;
	if (pPlugins)
		pPlugins->pLast=pPlugin;
	pPlugins=pPlugin;

	return 1;
}

BOOL UnloadMQ2Plugin(const PCHAR Filename)
{
	// find plugin in list
//	CAutoLock Lock(&gPluginCS);
	PMQPLUGIN pPlugin=pPlugins;
	while(pPlugin)
	{
		if (!stricmp(Filename,pPlugin->szFilename))
		{
			if (pPlugin->Shutdown)
				pPlugin->Shutdown();
			FreeLibrary(pPlugin->hModule);
			if (pPlugin->pLast)
				pPlugin->pLast->pNext=pPlugin->pNext;
			else
				pPlugins=pPlugin->pNext;
			if (pPlugin->pNext)
				pPlugin->pNext->pLast=pPlugin->pLast;
			delete pPlugin;
			return 1;
		}
		pPlugin=pPlugin->pNext;
	}

	return 0;
}

VOID RewriteMQ2Plugins(VOID)
{
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
	{
	//	CAutoLock Lock(&gPluginCS);
		while(pPlugins)
		{
			UnloadMQ2Plugin(pPlugins->szFilename);
		}
	}
	DeleteCriticalSection(&gPluginCS);
}

VOID WriteChatColor(PCHAR Line, DWORD Color, DWORD Filter)
{
	DebugSpew("WriteChatColor(%s)",Line);
//	CAutoLock Lock(&gPluginCS);
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
//	CAutoLock Lock(&gPluginCS);
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
//	CAutoLock Lock(&gPluginCS);
	PMQPLUGIN pPlugin=pPlugins;
	while(pPlugin)
	{
		if (pPlugin->Pulse)
		{
			pPlugin->Pulse();
		}
		pPlugin=pPlugin->pNext;
	}
}

VOID PluginsZoned()
{
//	CAutoLock Lock(&gPluginCS);
	PMQPLUGIN pPlugin=pPlugins;
	while(pPlugin)
	{
		if (pPlugin->Zoned)
		{
			pPlugin->Zoned();
		}
		pPlugin=pPlugin->pNext;
	}
}