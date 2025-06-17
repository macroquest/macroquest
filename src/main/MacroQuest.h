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

#include "ModuleSystem.h"

#include "eqlib/Events.h"
#include "eqlib/Init.h"

#include "mq/api/Main.h"
#include "routing/PipeMessage.h"

namespace mq {

class PipeMessage;
using PipeMessagePtr = std::unique_ptr<PipeMessage>;

class MacroQuest
	: public eqlib::EventInterface
	, protected MQDynamicModule
	, public MainInterface
{
public:
	MacroQuest(HMODULE hModule);
	virtual ~MacroQuest() override;

	// First chance initialization and last chance shutdown occur on the injection thread.
	// This may be the main thread if injection happens at startup through static binding.
	bool CoreInitialize();
	void CoreShutdown();

	/**
	 * Look up a module handle and return a pointer to the module if found.
	 * 
	 * @param handle The module handle
	 * @param noMain If true, the return value is nullptr if the handle belongs to the main module
	 * @return A pointer to the module, if found
	 */
	MQModuleBase* GetModuleByHandle(MQPluginHandle handle, bool noMain = false) const;

	/**
	 * Look up a module by its name and return a pointer to the module if found.
	 * 
	 * @param moduleName The name of the module
	 * @return A pointer to the module, if found
	 */
	MQModuleBase* GetModuleByName(std::string_view moduleName) const;

	/**
	 * Adds a module to the module list and initializes it. If the module list is currently
	 * locked, the module add will be queued for when the list is no longer locked.
	 */
	void AddModule(std::unique_ptr<MQModuleBase> module);

	/**
	 * Looks up a module by its handle and removes it from the module list. Returns the
	 * module if it was found.
	 */
	std::unique_ptr<MQModuleBase> RemoveModule(MQPluginHandle handle);

private:
	bool InitializeEQLib();
	void InitializeLogging();

	// Initialization in the first frame of the main game loop
	virtual void Initialize() override;
	virtual void Shutdown() override;

	// Load Preferences from disk
	bool LoadPreferences(const std::string& iniFile);

	virtual void LoadModules();
	MQPluginHandle CreateModuleHandle();

protected:
	// EQLib callbacks
	virtual void OnProcessFrame() override;
	virtual void OnGameStateChanged(int newGameState) override;
	virtual void OnLoginFrontendEntered() override;
	virtual void OnLoginFrontendExited() override;
	virtual void OnReloadUI(const eqlib::ReloadUIParams& params) override;
	virtual void OnCleanUI() override;
	virtual void OnPreZoneUI() override;
	virtual void OnPostZoneUI() override;
	virtual bool OnChatMessage(eqlib::ChatMessageParams& params) override;
	virtual bool OnTellWindowMessage(eqlib::TellWindowMessageParams& params) override;
	virtual bool OnIncomingWorldMessage(eqlib::IncomingWorldMessageParams& params) override;
	virtual void OnSpawnAdded(eqlib::PlayerClient* player) override;
	virtual void OnSpawnRemoved(eqlib::PlayerClient* player) override;
	virtual void OnGroundItemAdded(eqlib::EQGroundItem* groundItem) override;
	virtual void OnGroundItemRemoved(eqlib::EQGroundItem* groundItem) override;

public:
	virtual void OnWriteChatColor(const char* message, int color, int filter) override;
	virtual bool OnIncomingChat(const char* message, int color) override;
	virtual void OnZoned() override;
	virtual void OnDrawHUD() override;
	virtual void OnModuleLoaded(MQModuleBase* module) override;
	virtual void OnBeforeModuleUnloaded(MQModuleBase* module) override;
	virtual void OnAfterModuleUnloaded(MQModuleBase* module) override;
	virtual void OnMacroStart(const char* macroName) override;
	virtual void OnMacroStop(const char* macroName) override;

	void HandlePipeMessage(PipeMessagePtr messagePtr);
	void HandleUpdateImGui(bool internalOnly);

private:
	// Module system
	void InitializeModules();
	void ShutdownModules();

	void InitializeModule(MQModuleBase* module);
	void ShutdownModule(MQModuleBase* module);

public:
	// MainInterface implementation
	virtual bool AddTopLevelObject(const char* name, MQTopLevelObjectFunction callback, const MQPluginHandle& pluginHandle) override;
	virtual bool RemoveTopLevelObject(const char* name, const MQPluginHandle& pluginHandle) override;
	virtual MQTopLevelObject* FindTopLevelObject(const char* name) override;

	virtual void SendToActor(postoffice::Dropbox* dropbox, const postoffice::Address& address, const std::string& data,
		const postoffice::ResponseCallbackAPI& callback, const MQPluginHandle& pluginHandle) override;
	virtual void ReplyToActor(postoffice::Dropbox* dropbox, const std::shared_ptr<postoffice::Message>& message,
		const std::string& data, uint8_t status, const MQPluginHandle& pluginHandle) override;
	virtual postoffice::Dropbox* AddActor(const char* localAddress, postoffice::ReceiveCallbackAPI&& receive, const MQPluginHandle& pluginHandle) override;
	virtual void RemoveActor(postoffice::Dropbox*& dropbox, const MQPluginHandle& pluginHandle) override;

	// Commands
	virtual bool AddCommand(std::string_view command, MQCommandHandler handler, bool eq, bool parse, bool inGame, const MQPluginHandle& pluginHandle) override;
	virtual bool RemoveCommand(std::string_view command, const MQPluginHandle& pluginHandle) override;
	virtual bool IsCommand(std::string_view command) const override;
	virtual void DoCommand(const char* command, bool delayed, const MQPluginHandle& pluginHandle) override;
	virtual void TimedCommand(const char* command, int msDelay, const MQPluginHandle& pluginHandle) override;

	// Aliases
	virtual bool AddAlias(const std::string& shortCommand, const std::string& longCommand, bool persist, const MQPluginHandle& pluginHandle) override;
	virtual bool RemoveAlias(const std::string& shortCommand, const MQPluginHandle& pluginHandle) override;
	virtual bool IsAlias(const std::string& alias) const override;

	//-----------------------------------------------------------------------------------------------------
	// Detours
	virtual bool CreateDetour(uintptr_t address, void** target, void* detour, std::string_view name, const MQPluginHandle& pluginHandle) override;
	virtual bool RemoveDetour(uintptr_t address, const MQPluginHandle& pluginHandle) override;

	virtual bool AddPatch(uintptr_t address, size_t numBytes, std::string_view name, const MQPluginHandle& pluginHandle) override;
	virtual bool AddPatch(uintptr_t address, const uint8_t* newBytes, size_t numBytes, const uint8_t* expectedBytes,
		std::string_view name, const MQPluginHandle& pluginHandle) override;
	virtual bool RemovePatch(uintptr_t address, const MQPluginHandle& pluginHandle) override;

	std::vector<eqlib::MemoryPatch*> FindPatches(uintptr_t address, size_t width);

	bool IsAddressPatched(uintptr_t address, size_t width);

private:
	bool ValidateNewPatch(uintptr_t address, size_t numBytes, std::string_view name,
		const MQPluginHandle& pluginHandle) const;
	void HandlePendingWork();

	virtual MQPlugin* GetPlugin() override { return &m_plugin; }

	std::shared_ptr<spdlog::logger> m_logger;                        // logger for MacroQuest
	std::shared_ptr<spdlog::logger> m_eqlibLogger;                   // logger for EQLib
	eqlib::EQLibInterface* m_eqlib = nullptr;
	eqlib::MemoryPatcher* m_memoryPatcher = nullptr;                 // Memory patcher for detours and patches

	std::vector<std::unique_ptr<MQModuleBase>> m_modules;            // Modules sorted in priority order
	std::unordered_map<uint64_t, MQModuleBase*> m_moduleHandleMap;   // Modules indexed by handle

	bool m_initializedFirstFrame = false;
	bool m_initializedModules = false;
	bool m_shuttingDown = false;
	bool m_createdUI = false;
	bool m_zoningInProgress = true;
	bool m_loginEntered = false;

	// Benchmark handles
	uint32_t bmWriteChatColor = 0;
	uint32_t bmPluginsIncomingChat = 0;
	uint32_t bmPluginsPulse = 0;
	uint32_t bmPluginsOnZoned = 0;
	uint32_t bmPluginsCleanUI = 0;
	uint32_t bmPluginsReloadUI = 0;
	uint32_t bmPluginsDrawHUD = 0;
	uint32_t bmPluginsSetGameState = 0;
	uint32_t bmPluginsUpdateImGui = 0;
	uint32_t bmBeginZone = 0;
	uint32_t bmEndZone = 0;

	// State tracking across frames
	eqlib::PlayerClient* m_lastPlayer = nullptr;
	MQPlugin m_plugin;

	struct ScopedIteratingModules;
	int m_iteratingModules = 0;

	// Pending work to be executed when we are not iterating through modules.
	std::vector<std::function<void()>> m_pendingWork;
	std::vector<std::unique_ptr<MQModuleBase>> m_pendingModuleAdds;
};

extern MacroQuest* g_mq;

} // namespace mq
