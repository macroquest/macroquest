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
	, public MainInterface
{
public:
	MacroQuest();
	virtual ~MacroQuest() override;

	// First chance initialization and last chance shutdown occur on the injection thread.
	// This may be the main thread if injection happens at startup through static binding.
	bool Initialize();
	void Shutdown();

	MQPluginHandle CreateModuleHandle();

private:
	bool InitializeEQLib();
	void InitializeLogging();

	// Initialization in the first frame of the main game loop
	bool MainThreadInitialize();
	void MainThreadShutdown();

	// Load Preferences from disk
	bool LoadPreferences(const std::string& iniFile);

	virtual void LoadModules();

	void AddModule(std::unique_ptr<MQModuleBase> module);

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
	void OnWriteChatColor(const char* message, int color, int filter);
	bool OnIncomingChat(const char* message, int color);

	void OnUpdateImGui();

	void OnZoned();
	void OnDrawHUD();

	void OnModuleLoaded(MQModuleBase* module);
	void OnBeforeModuleUnloaded(MQModuleBase* module);
	void OnAfterModuleUnloaded(MQModuleBase* module);
	void OnMacroStart(const char* macroName);
	void OnMacroStop(const char* macroName);

	void OnPipeMessage(PipeMessagePtr messagePtr);

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
	virtual bool CreateDetour(uintptr_t address, size_t width, std::string_view name, const MQPluginHandle& pluginHandle) override;
	virtual bool RemoveDetour(uintptr_t address, const MQPluginHandle& pluginHandle) override;

	std::vector<eqlib::MemoryPatch*> FindPatches(uintptr_t address, size_t width);

	bool IsAddressPatched(uintptr_t address, size_t width);

private:
	bool ValidateNewPatch(uintptr_t address, std::string_view name,
		const MQPluginHandle& pluginHandle) const;

private:
	std::shared_ptr<spdlog::logger> m_logger;                        // logger for MacroQuest
	std::shared_ptr<spdlog::logger> m_eqlibLogger;                   // logger for EQLib
	eqlib::EQLibInterface* m_eqlib = nullptr;
	eqlib::MemoryPatcher* m_memoryPatcher = nullptr;                 // Memory patcher for detours and patches

	std::vector<std::unique_ptr<MQModuleBase>> m_modules;            // Modules sorted in priority order
	std::unordered_map<uint64_t, MQModuleBase*> m_moduleHandleMap;   // Modules indexed by handle

	bool m_initializedFirstFrame = false;
	bool m_shuttingDown = false;

	bool m_initializedModules = false;
	bool m_createdUI = false;
};

extern MacroQuest* g_mq;

} // namespace mq
