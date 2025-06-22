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

#ifndef MQ2MAIN_IMPL
#error This header should only be included from the MQ2Main project
#endif

#include "ModuleSystem.h"

#include <cstdint>

namespace eqlib
{
	class PlayerClient;
	class EQGroundItem;
}

namespace mq {

class MQPluginModule;

//=================================================================================================

std::string_view GetCanonicalPluginName(std::string_view name, bool stripExtension = true);

//=================================================================================================

class MQPluginV1Module final : public MQPluginModule
{
public:
	MQPluginV1Module(MQPluginProvider* provider, HMODULE hModule, std::string_view path);
	virtual ~MQPluginV1Module() override;

protected:
	virtual void Initialize() override;
	virtual void Shutdown() override;

	virtual void OnProcessFrame() override;
	virtual void OnGameStateChanged(int gameState) override;
	virtual void OnUpdateImGui() override;
	virtual void OnCleanUI() override;
	virtual void OnReloadUI(const eqlib::ReloadUIParams& params) override;
	virtual void OnPreZoneUI() override;
	virtual void OnPostZoneUI() override;
	virtual void OnWriteChatColor(const char* message, int color, int filter) override;
	virtual bool OnIncomingChat(const IncomingChatParams& params) override;
	virtual void OnZoned() override;
	virtual void OnDrawHUD() override;
	virtual void OnSpawnAdded(eqlib::PlayerClient* player) override;
	virtual void OnSpawnRemoved(eqlib::PlayerClient* player) override;
	virtual void OnGroundItemAdded(eqlib::EQGroundItem* groundItem) override;
	virtual void OnGroundItemRemoved(eqlib::EQGroundItem* groundItem) override;
	virtual void OnModuleLoaded(MQModule* module) override;
	virtual void OnBeforeModuleUnloaded(MQModule* module) override;
	virtual void OnAfterModuleUnloaded(MQModule* module) override;
	virtual void OnMacroStart(const char* macroName) override;
	virtual void OnMacroStop(const char* macroName) override;

	virtual PluginInterface* GetPluginInterface() override;
};

//=================================================================================================

class MQPluginHandler : public MQModule,
	public MQPluginProvider
{
public:
	MQPluginHandler();
	virtual ~MQPluginHandler() override;

	virtual void Initialize() override;
	virtual void Shutdown() override;

	LoadPluginResult LoadPlugin(std::string_view pluginName, bool save = false);
	bool UnloadPlugin(std::string_view pluginName, bool save = false);

	bool IsPluginLoaded(std::string_view pluginName) const;

	MQPlugin* GetPluginPtr(std::string_view name);
	void* GetPluginProcFromPlugin(std::string_view pluginName, const char* procName);
	PluginInterface* GetPluginInterfaceFromPlugin(std::string_view pluginName);

	int GetPluginUnloadFailedCount() const { return static_cast<int>(m_pluginUnloadFailedMap.size()); }

private:
	void LoadPlugins();
	void PluginCommand(const char* szLine);

	std::pair<wil::unique_hmodule, std::string> LoadPluginModule(std::string_view name);

	bool UnloadFailedPlugins();
	void ShutdownFailedPlugins();
	bool IsPluginUnloadFailed(std::string_view name);

	virtual void OnBeforePluginInitialized(MQPluginModule* plugin) override;
	virtual void OnAfterPluginInitialized(MQPluginModule* plugin) override;
	virtual void OnBeforePluginShutdown(MQPluginModule* plugin) override;
	virtual void OnAfterPluginShutdown(MQPluginModule* plugin) override;

	void DeletePluginModule(MQPluginModule* module, fMQDestroyModule destroyProc = nullptr);
	bool CleanupPluginModule(std::string_view pluginName, HMODULE hModule);

	using PluginMap = ci_unordered::map<std::string_view, MQModule*>;

	// a map of plugin names to plugins. The string_view is a reference to the name in the
	// MQPlugin instance.
	PluginMap m_pluginMap;

	struct UnloadFailedItem
	{
		std::string fileName;      // Name of plugin file (non-canonicalized)
		HMODULE hModule;           // Handle to the plugin module
	};
	// List of plugins that failed to unload. These modules are no longer loaded, but we hold
	// onto them because we can't remove them. Key is canonicalized plugin name, and a view into
	// the fileName in the value.
	ci_unordered::map<std::string_view, UnloadFailedItem> m_pluginUnloadFailedMap;

	// load failure string for reporting error message out of the plugin load command.
	std::string m_pluginLoadFailure;

	bool m_shutdown = false;
};

extern MQPluginHandler* g_pluginHandler;

} // namespace mq
