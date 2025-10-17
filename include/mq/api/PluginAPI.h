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
#include "mq/base/PluginHandle.h"

#include <string_view>
#include <string>

namespace eqlib {
	class PlayerClient;
	class EQGroundItem;
}

namespace mq {

class PluginInterface;

// Plugin Function Types
using fMQWriteChatColor      = int (*)(const char*, uint32_t, uint32_t);
using fMQPulse               = void(*)();
using fMQIncomingChat        = bool(*)(const char* Line, uint32_t Color);
using fMQInitializePlugin    = void(*)();
using fMQShutdownPlugin      = void(*)();
using fMQZoned               = void(*)();
using fMQReloadUI            = void(*)();
using fMQCleanUI             = void(*)();
using fMQDrawHUD             = void(*)();
using fMQSetGameState        = void(*)(int GameState);
using fMQSpawn               = void(*)(eqlib::PlayerClient*);
using fMQGroundItem          = void(*)(eqlib::EQGroundItem*);
using fMQBeginZone           = void(*)();
using fMQEndZone             = void(*)();
using fMQUpdateImGui         = void(*)();
using fMQMacroStart          = void(*)(const char*);
using fMQMacroStop           = void(*)(const char*);
using fMQLoadPlugin          = void(*)(const char*);
using fMQUnloadPlugin        = void(*)(const char*);
using fMQGetPluginInterface  = PluginInterface* (*)();
using fMQPostUnloadPlugin    = void(*)(const char*);

/**
 * Structure representing a loaded plugin.
 */
struct MQPlugin
{
	char                 szFilename[MAX_PATH] = { 0 };
	std::string          name;
	HMODULE              hModule = nullptr;
	float                fpVersion = 1.0;
	bool                 bCustom = false;
	fMQInitializePlugin  Initialize = nullptr;
	fMQShutdownPlugin    Shutdown = nullptr;
	fMQZoned             Zoned = nullptr;
	fMQWriteChatColor    WriteChatColor = nullptr;
	fMQPulse             Pulse = nullptr;
	fMQIncomingChat      IncomingChat = nullptr;
	fMQCleanUI           CleanUI = nullptr;
	fMQReloadUI          ReloadUI = nullptr;
	fMQDrawHUD           DrawHUD = nullptr;
	fMQSetGameState      SetGameState = nullptr;
	fMQSpawn             AddSpawn = nullptr;
	fMQSpawn             RemoveSpawn = nullptr;
	fMQGroundItem        AddGroundItem = nullptr;
	fMQGroundItem        RemoveGroundItem = nullptr;
	fMQBeginZone         BeginZone = nullptr;
	fMQEndZone           EndZone = nullptr;
	fMQUpdateImGui       UpdateImGui = nullptr;
	fMQMacroStart        MacroStart = nullptr;
	fMQMacroStop         MacroStop = nullptr;
	fMQLoadPlugin        LoadPlugin = nullptr;
	fMQUnloadPlugin      UnloadPlugin = nullptr;
	fMQGetPluginInterface GetPluginInterface = nullptr;
	fMQPostUnloadPlugin  OnPostUnloadPlugin = nullptr;

	MQPlugin*            pLast = nullptr;
	MQPlugin*            pNext = nullptr;
};

/**
 * LoadPlugin result values.
 */
enum LoadPluginResult
{
	/** Plugin load failed. Additional information may be logged */
	LoadPluginResult_Failed = 0,

	/** Plugin load was successful. */
	LoadPluginResult_Success = 1,

	/** Plugin is already loaded */
	LoadPluginResult_AlreadyLoaded = 2,

	/** Plugin was previously unloaded, but that unload attempt had failed. */
	LoadPluginResult_PreviousUnloadFailed = 3,
};

/**
 * Load a plugin by name.
 *
 * @param pluginName Name of the plugin to load. MQ or MQ2 prefix is not required.
 * @param save If true, save this plugin so that it is loaded automatically.
 * 
 * @return A value from the LoadPluginResult enumeration, indicating the result of this
 * plugin load attempt.
 */
MQLIB_OBJECT int LoadPlugin(std::string_view pluginName, bool save = false);

/**
 * Unload a plugin by name.
 *
 * @param pluginName The name of the plugin to unload.
 * @param save If true, save this plugin so that it is not loaded automatically.
 * @return True if the unload was successful.
 */
MQLIB_OBJECT bool UnloadPlugin(std::string_view pluginName, bool save = false);

/**
 * Get the address of an exported symbol from a loaded plugin.
 *
 * @param plugin Name of the plugin
 * @param proc Name of the exported symbol.
 * @return Address to the exported symbol, or nullptr if not found.
 */
MQLIB_API void* GetPluginProc(const char* plugin, const char* proc);

/**
 * Get a plugin object by name.
 *
 * @param pluginName Name of a loaded plugin.
 * @return Plugin object, or nullptr if not found.
 */
MQLIB_API MQPlugin* GetPlugin(std::string_view pluginName);

/**
 * Get a plugin object by plugin handle.
 *
 * @param pluginHandle Handle of the loaded plugin.
 * @param noMain If true, and the pluginHandle represents MQ2Main, then nullptr will be
 * returned instead.
 * @return Plugin object, or nullptr if not found.
 */
MQLIB_API MQPlugin* GetPluginByHandle(MQPluginHandle pluginHandle, bool noMain = false);

/**
 * Check if a plugin is loaded.
 *
 * @param pluginName Name of the plugin.
 * @return True if the plugin is loaded.
 */
MQLIB_API bool IsPluginLoaded(std::string_view pluginName);


/**
 * Base Class for all Plugin interface subclasses.
 *
 * A plugin can subclass this interface and add its own virtual functions to create an
 * exported interface. Other plugins can call `GetPluginInterface` to retrieve an instance
 * of this interface.
 */
class MQLIB_OBJECT PluginInterface
{
public:
	virtual ~PluginInterface() {}
};

/**
 * If a plugin implements its own PluginInterface, this function can be used to retrive that
 * plugin's custom interface.
 *
 * @param pluginName Name of the plugin to retrieve an interface from.
 * @return The plugin's interface object, or nullptr if it is not found or does not exist.
 */
MQLIB_API PluginInterface* GetPluginInterface(std::string_view pluginName);


MQLIB_API DEPRECATE("Use mq::LoadPlugin instead of LoadMQ2Plugin")
inline int LoadMQ2Plugin(const char* pszFilename, bool bCustom = false) { return mq::LoadPlugin(pszFilename, false); }

MQLIB_API DEPRECATE("Use mq::UnloadPlugin instead of UnloadMQ2Plugin")
inline bool UnloadMQ2Plugin(const char* pszFilename) { return mq::UnloadPlugin(pszFilename); }

} // namespace mq
