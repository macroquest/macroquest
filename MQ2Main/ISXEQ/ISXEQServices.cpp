/*****************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

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
#include "..\MQ2Main.h"
#include "ISXEQServices.h"

//#define DEBUG_PLUGINS

#ifdef DEBUG_PLUGINS
#define PluginDebug DebugSpew
#else
#define PluginDebug //
#endif


// "Chat" service
EQLIB_API BOOL PluginsIncomingChat(PCHAR Line, DWORD Color)
{
	PluginDebug("PluginsIncomingChat()");
    if(!Line[0])
        return 0;
	_EQChat Chat;
	Chat.Line=Line;
	Chat.Color=Color;
	pISInterface->ServiceBroadcast(pExtension,hChatService,CHATSERVICE_INCOMING,&Chat);
	return false;
}


EQLIB_API VOID WriteChatColor(PCHAR Line, DWORD Color, DWORD Filter)
{
	if (gFilterMQ)
		return;
	PluginDebug("Begin WriteChatColor()");
	EnterMQ2Benchmark(bmWriteChatColor);
	CHAR PlainText[MAX_STRING]={0};
	StripMQChat(Line,PlainText);
	CheckChatForEvent(PlainText);
	
	DebugSpew("WriteChatColor(%s)",Line);

	// TEMPORARY
	printf("%s",PlainText);
	if (gFilterMacro != FILTERMACRO_NONE && ppEverQuest && pEverQuest && gGameState==GAMESTATE_INGAME)
	{
		dsp_chat_no_events(PlainText,Color,1);
	}
	// ---------



	// filter parameter is unused anyway
	_EQChat Chat;
	Chat.Line=Line;
	Chat.Color=Color;
	pISInterface->ServiceBroadcast(pExtension,hChatService,CHATSERVICE_OUTGOING,&Chat);

	ExitMQ2Benchmark(bmWriteChatColor);
}


// "UI" service
EQLIB_API VOID PluginsCleanUI()
{
	PluginDebug("PluginsCleanUI()");
	pISInterface->ServiceBroadcast(pExtension,hUIService,UISERVICE_CLEANUP,0);
}
EQLIB_API VOID PluginsReloadUI()
{
	PluginDebug("PluginsReloadUI()");
	pISInterface->ServiceBroadcast(pExtension,hUIService,UISERVICE_RELOAD,0);
}

// "Gamestate" Service
EQLIB_API VOID PluginsSetGameState(DWORD GameState)
{
	PluginDebug("PluginsSetGameState()");
	static bool AutoExec=false;
	static bool CharSelect=true;
	DrawHUDParams[0]=0;
	gGameState=GameState;
	if (GameState==GAMESTATE_INGAME)
	{
		gZoning=false;
		gbDoAutoRun=TRUE;
		if (!AutoExec)
		{
			AutoExec=true;
			pISInterface->RunCommandFile("EQ-AutoExec");
		}
		if (CharSelect)
		{
			CharSelect=false;
			CHAR szBuffer[MAX_STRING]={0};
			if (PCHARINFO pCharInfo=GetCharInfo())
			{
				sprintf(szBuffer,"EQ-%s_%s",EQADDR_SERVERNAME,pCharInfo->Name);
				pISInterface->RunCommandFile("szBuffer");
			}
		}
	}
	else if (GameState==GAMESTATE_CHARSELECT)
	{
		if (!AutoExec)
		{
			AutoExec=true;
			pISInterface->RunCommandFile("EQ-AutoExec");
		}
		CharSelect=true;
		pISInterface->RunCommandFile("EQ-CharSelect");
	}

	DebugSpew("PluginsSetGameState(%d)",GameState);
	pISInterface->ServiceBroadcast(pExtension,hUIService,UISERVICE_RELOAD,0);
}

// "Spawn" service
EQLIB_API VOID PluginsAddSpawn(PSPAWNINFO pNewSpawn)
{
	PluginDebug("PluginsAddSpawn(%s,%d,%d)",pNewSpawn->Name,pNewSpawn->Race,pNewSpawn->BodyType);
	SpawnByName[pNewSpawn->Name]=pNewSpawn;
	if (gGameState>GAMESTATE_CHARSELECT)
		SetNameSpriteState(pNewSpawn,1);
	if (GetBodyTypeDesc(pNewSpawn->BodyType)[0]=='*')
	{
		WriteChatf("Spawn '%s' has unknown bodytype %d",pNewSpawn->Name,pNewSpawn->BodyType);
	}
	pISInterface->ServiceBroadcast(pExtension,hUIService,SPAWNSERVICE_ADDSPAWN,pNewSpawn);
}
EQLIB_API VOID PluginsRemoveSpawn(PSPAWNINFO pSpawn)
{
	PluginDebug("PluginsRemoveSpawn(%s)",pSpawn->Name);
	SpawnByName.erase(pSpawn->Name);
	pISInterface->ServiceBroadcast(pExtension,hUIService,SPAWNSERVICE_REMOVESPAWN,pSpawn);
}
EQLIB_API VOID PluginsAddGroundItem(PGROUNDITEM pNewGroundItem)
{
	DebugSpew("PluginsAddGroundItem(%s) %.1f,%.1f,%.1f",pNewGroundItem->Name,pNewGroundItem->X,pNewGroundItem->Y,pNewGroundItem->Z);
	pISInterface->ServiceBroadcast(pExtension,hUIService,SPAWNSERVICE_ADDITEM,pNewGroundItem);
}
EQLIB_API VOID PluginsRemoveGroundItem(PGROUNDITEM pGroundItem)
{
	PluginDebug("PluginsRemoveGroundItem()");
	pISInterface->ServiceBroadcast(pExtension,hUIService,SPAWNSERVICE_REMOVEITEM,pGroundItem);
}

// "Zone" service
EQLIB_API VOID PluginsBeginZone(VOID)
{
	pISInterface->ServiceBroadcast(pExtension,hZoneService,ZONESERVICE_BEGINZONE,0);
}
EQLIB_API VOID PluginsEndZone(VOID)
{
	pISInterface->ServiceBroadcast(pExtension,hZoneService,ZONESERVICE_ENDZONE,0);
}
EQLIB_API VOID PluginsZoned()
{
	PluginDebug("PluginsZoned()");

	pISInterface->ServiceBroadcast(pExtension,hZoneService,ZONESERVICE_ZONED,0);

	pISInterface->RunCommandFile("EQ-zoned");
	char Temp[256]={0};
	sprintf(Temp,"EQ-%s",((PZONEINFO)pZoneInfo)->ShortName);
	pISInterface->RunCommandFile(Temp);
}

