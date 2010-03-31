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
//#define DBG_TRY

#include "..\MQ2Main.h"

/*
// Convert all "Plugin" functions to services, with few exceptions


// "Chat" service
EQLIB_API BOOL PluginsIncomingChat(PCHAR Line, DWORD Color);
EQLIB_API VOID WriteChatColor(PCHAR Line, DWORD Color=USERCOLOR_DEFAULT, DWORD Filter=0);


// "UI" service
EQLIB_API VOID PluginsCleanUI();
EQLIB_API VOID PluginsReloadUI();

// "Gamestate" Service
EQLIB_API VOID PluginsSetGameState(DWORD GameState);

// "Spawn" service
EQLIB_API VOID PluginsAddSpawn(PSPAWNINFO pNewSpawn);
EQLIB_API VOID PluginsRemoveSpawn(PSPAWNINFO pSpawn);
EQLIB_API VOID PluginsAddGroundItem(PGROUNDITEM pNewGroundItem);
EQLIB_API VOID PluginsRemoveGroundItem(PGROUNDITEM pGroundItem);

// "Zone" service
EQLIB_API VOID PluginsBeginZone(VOID); 
EQLIB_API VOID PluginsEndZone(VOID); 
EQLIB_API VOID PluginsZoned();
/**/