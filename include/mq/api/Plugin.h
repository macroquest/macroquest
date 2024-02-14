/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once

#include "mq/base/Common.h"

#include <string_view>
#include <string>

namespace eqlib {
	class PlayerClient;
	class EQGroundItem;
}

namespace mq {

class PluginInterface;

// Plugin Function Types
using fMQWriteChatColor      = DWORD  (*)(const char*, DWORD, DWORD);
using fMQPulse               = void   (*)();
using fMQIncomingChat        = bool   (*)(const char* Line, DWORD Color);
using fMQInitializePlugin    = void   (*)();
using fMQShutdownPlugin      = void   (*)();
using fMQZoned               = void   (*)();
using fMQReloadUI            = void   (*)();
using fMQCleanUI             = void   (*)();
using fMQDrawHUD             = void   (*)();
using fMQSetGameState        = void   (*)(DWORD GameState);
using fMQSpawn               = void   (*)(PlayerClient*);
using fMQGroundItem          = void   (*)(EQGroundItem*);
using fMQBeginZone           = void   (*)();
using fMQEndZone             = void   (*)();
using fMQUpdateImGui         = void   (*)();
using fMQMacroStart          = void   (*)(const char*);
using fMQMacroStop           = void   (*)(const char*);
using fMQLoadPlugin          = void   (*)(const char*);
using fMQUnloadPlugin        = void   (*)(const char*);
using fMQGetPluginInterface  = PluginInterface* (*)();

struct MQPlugin
{
	char                 szFilename[MAX_PATH] = { 0 };
	MQPlugin**           Self = nullptr;
	std::string          name;
	HMODULE              hModule = nullptr;
	float                fpVersion = 1.0;
	bool                 bCustom = false;
	fMQInitializePlugin  Initialize = 0;
	fMQShutdownPlugin    Shutdown = 0;
	fMQZoned             Zoned = 0;
	fMQWriteChatColor    WriteChatColor = 0;
	fMQPulse             Pulse = 0;
	fMQIncomingChat      IncomingChat = 0;
	fMQCleanUI           CleanUI = 0;
	fMQReloadUI          ReloadUI = 0;
	fMQDrawHUD           DrawHUD = 0;
	fMQSetGameState      SetGameState = 0;
	fMQSpawn             AddSpawn = 0;
	fMQSpawn             RemoveSpawn = 0;
	fMQGroundItem        AddGroundItem = 0;
	fMQGroundItem        RemoveGroundItem = 0;
	fMQBeginZone         BeginZone = 0;
	fMQEndZone           EndZone = 0;
	fMQUpdateImGui       UpdateImGui = 0;
	fMQMacroStart        MacroStart = 0;
	fMQMacroStop         MacroStop = 0;
	fMQLoadPlugin        LoadPlugin = 0;
	fMQUnloadPlugin      UnloadPlugin = 0;
	fMQGetPluginInterface GetPluginInterface = 0;

	MQPlugin* pLast = nullptr;
	MQPlugin* pNext = nullptr;
};

MQLIB_API bool IsPluginsInitialized();

MQLIB_API void* GetPluginProc(const char* plugin, const char* proc);

MQLIB_API MQPlugin* GetPlugin(std::string_view PluginName);

MQLIB_API bool IsPluginLoaded(std::string_view PluginName);

// Base Class for all Plugin interface subclasses
class MQLIB_OBJECT PluginInterface
{
public:
	virtual ~PluginInterface() {}
};

MQLIB_API PluginInterface* GetPluginInterface(std::string_view PluginName);

} // namespace mq
