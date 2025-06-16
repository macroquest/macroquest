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

#ifndef MQ2MAIN_EXPORTS
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

class MQPluginProvider
{
public:
	virtual ~MQPluginProvider() = default;

	virtual void OnPluginInitialized(MQPluginModule* pPlugin) = 0;

	virtual void OnBeforePluginShutdown(MQPluginModule* pPlugin) = 0;
	virtual void OnAfterPluginShutdown(MQPluginModule* pPlugin) = 0;
};

//=================================================================================================

class MQPluginModule : public MQDynamicModule
{
public:
	MQPluginModule(MQPluginProvider* provider, HMODULE hModule, std::string path);
	virtual ~MQPluginModule() override;

	virtual MQPlugin* GetPlugin() override { return &m_plugin; }
	virtual const char* GetPluginFilename() const { return m_plugin.szFilename; }
	virtual PluginInterface* GetPluginInterface() = 0;

	const std::string& GetFilename() const { return m_path; }

protected:
	std::string m_path;

	MQPlugin m_plugin;
	MQPluginProvider* m_provider;
};

//=================================================================================================

class MQPluginV1Module final : public MQPluginModule
{
public:
	MQPluginV1Module(MQPluginProvider* provider, HMODULE hModule, std::string path);
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
	virtual bool OnIncomingChat(const char* message, int color) override;
	virtual void OnZoned() override;
	virtual void OnDrawHUD() override;
	virtual void OnSpawnAdded(eqlib::PlayerClient* player) override;
	virtual void OnSpawnRemoved(eqlib::PlayerClient* player) override;
	virtual void OnGroundItemAdded(eqlib::EQGroundItem* groundItem) override;
	virtual void OnGroundItemRemoved(eqlib::EQGroundItem* groundItem) override;
	virtual void OnModuleLoaded(MQModuleBase* module) override;
	virtual void OnBeforeModuleUnloaded(MQModuleBase* module) override;
	virtual void OnAfterModuleUnloaded(MQModuleBase* module) override;
	virtual void OnMacroStart(const char* macroName) override;
	virtual void OnMacroStop(const char* macroName) override;

	virtual PluginInterface* GetPluginInterface() override;
};

//=================================================================================================

class MQPluginHandler : public MQModuleBase,
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

	MQPlugin* GetPlugin(std::string_view name);
	void* GetPluginProc(std::string_view pluginName, const char* procName);
	PluginInterface* GetPluginInterface(std::string_view pluginName);

	int GetPluginUnloadFailedCount() const { return static_cast<int>(m_pluginUnloadFailedMap.size()); }

private:
	void LoadPlugins();
	bool CleanupPlugin(MQPluginModule* pluginModule);
	void PluginCommand(const char* szLine);

	std::pair<wil::unique_hmodule, std::string> LoadPluginModule(std::string_view name);

	bool UnloadFailedPlugins();
	void ShutdownFailedPlugins();
	bool IsPluginUnloadFailed(std::string_view name);

	virtual void OnPluginInitialized(MQPluginModule* plugin) override;
	virtual void OnBeforePluginShutdown(MQPluginModule* plugin) override;
	virtual void OnAfterPluginShutdown(MQPluginModule* plugin) override;

	using PluginMap = ci_unordered::map<std::string_view, MQPluginModule*>;

	// a map of plugin names to plugins. The string_view is a reference to the name in the
	// MQPlugin instance.
	PluginMap m_pluginMap;

	// List of plugins that failed to unload. These modules are no longer loaded, but we hold
	// onto them because we can't remove them.
	ci_unordered::map<std::string_view, std::unique_ptr<MQPluginModule>> m_pluginUnloadFailedMap;

	// load failure string for reporting error message out of the plugin load command.
	std::string m_pluginLoadFailure;

	bool m_unloadingModule = false;
};

extern MQPluginHandler* g_pluginHandler;

} // namespace mq
