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

#include "eqlib/Events.h"
#include "eqlib/Init.h"

#include "mq/api/Main.h"

namespace mq {

class MQModuleEventReceiver
{
public:
	virtual ~MQModuleEventReceiver() {}

	virtual void Initialize() = 0;
	virtual void Shutdown() = 0;

	virtual void OnProcessFrame() = 0; // a.k.a. Pulse

	virtual void OnGameStateChanged(uint32_t newGameState, uint32_t oldGameState) = 0;

	virtual void OnCleanUI() = 0;
	virtual void OnReloadUI() = 0;
	virtual void OnPreZoneUI() = 0;
	virtual void OnPostZoneUI() = 0;
	virtual void OnZoned() = 0;

	virtual void OnPluginLoaded(const char* pluginName) = 0;
	virtual void OnPluginUnloaded(const char* pluginName) = 0;

	virtual void OnMacroStarted(const char* macroName) = 0;
	virtual void OnMacroStopped(const char* macroName) = 0;

	virtual bool OnIncomingChat(const char* text, uint32_t chatColor) = 0;
};


class MacroQuest
	: public eqlib::EventInterface
	, public MainInterface
{
public:
	MacroQuest();
	virtual ~MacroQuest() override;

	// Initialization as soon as we are started
	bool Initialize();

	void Shutdown();

private:
	bool InitializeEQLib();

	// Initialization in the first frame of the main game loop
	bool FirstFrameInitialize();

	// Load Preferences from disk
	bool LoadPreferences(const std::string& iniFile);

	void InitializeLogging();

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

	// Detours
	virtual bool CreateDetour(uintptr_t address, void** target, void* detour, std::string_view name, const MQPluginHandle& pluginHandle) override;
	virtual bool CreateDetour(uintptr_t address, size_t width, std::string_view name, const MQPluginHandle& pluginHandle) override;
	virtual bool RemoveDetour(uintptr_t address, const MQPluginHandle& pluginHandle) override;

private:
	std::shared_ptr<spdlog::logger> m_logger; // logger for MacroQuest
	std::shared_ptr<spdlog::logger> m_eqlibLogger; // logger for EQLib
	eqlib::EQLibInterface* m_eqlib;
	bool m_initializedFirstFrame = false;
};

extern MacroQuest* g_mq;

} // namespace mq
