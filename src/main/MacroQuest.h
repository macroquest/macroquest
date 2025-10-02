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

class MacroQuest 
	: public eqlib::EventInterface
	, public MainInterface
{
public:
	MacroQuest();
	virtual ~MacroQuest() override;

	// First chance initialization and last chance shutdown occur on the injection thread.
	// This may be the main thread if injection happens at startup through static binding.
	bool CoreInitialize();
	void CoreShutdown();

	// Initialization in the first frame of the main game loop
	void Initialize();
	void Shutdown();

	bool InitializeEQLib();
	void InitializeLogging();
	void InitializeLoggingStage2();

	// EventInterface
	virtual void OnEQMainDllLoadedStateChanged(bool loaded) override;

	// TLOs
	virtual bool AddTopLevelObject(const char* name, MQTopLevelObjectFunction callback, const MQPluginHandle& pluginHandle) override;
	virtual bool RemoveTopLevelObject(const char* name, const MQPluginHandle& pluginHandle) override;
	virtual MQTopLevelObject* FindTopLevelObject(const char* name) override;

	// Actors
	virtual void SendToActor(postoffice::Dropbox* dropbox, const postoffice::Address& address, const std::string& data,
		const postoffice::ResponseCallbackAPI& callback, const MQPluginHandle& pluginHandle) override;
	virtual void ReplyToActor(postoffice::Dropbox* dropbox, const std::shared_ptr<postoffice::Message>& message,
		const std::string& data, uint8_t status, const MQPluginHandle& pluginHandle) override;
	virtual postoffice::Dropbox* AddActor(const char* localAddress, postoffice::ReceiveCallbackAPI&& receive,
		const MQPluginHandle& pluginHandle) override;
	virtual void RemoveActor(postoffice::Dropbox*& dropbox, const MQPluginHandle& pluginHandle) override;

	// Commands
	virtual bool AddCommand(std::string_view command, MQCommandHandler handler, bool eq, bool parse, bool inGame,
		const MQPluginHandle& pluginHandle) override;
	virtual bool RemoveCommand(std::string_view command, const MQPluginHandle& pluginHandle) override;
	virtual bool IsCommand(std::string_view command) const override;
	virtual void DoCommand(const char* command, bool delayed, const MQPluginHandle& pluginHandle) override;
	virtual void TimedCommand(const char* command, int msDelay, const MQPluginHandle& pluginHandle) override;

	// Aliases
	virtual bool AddAlias(const std::string& shortCommand, const std::string& longCommand, bool persist,
		const MQPluginHandle& pluginHandle) override;
	virtual bool RemoveAlias(const std::string& shortCommand, const MQPluginHandle& pluginHandle) override;
	virtual bool IsAlias(const std::string& alias) const override;

	// Detours
	virtual bool CreateDetour(uintptr_t address, void** target, void* detour, std::string_view name,
		const MQPluginHandle& pluginHandle) override;
	virtual bool RemoveDetour(uintptr_t address, const MQPluginHandle& pluginHandle) override;
	virtual bool AddPatch(uintptr_t address, size_t width, std::string_view name, const MQPluginHandle& pluginHandle) override;
	virtual bool AddPatch(uintptr_t address, const uint8_t* newBytes, size_t numBytes, const uint8_t* expectedBytes,
		std::string_view name, const MQPluginHandle& pluginHandle) override;
	virtual bool RemovePatch(uintptr_t address, const MQPluginHandle& pluginHandle) override;

	std::vector<eqlib::MemoryPatch*> FindPatches(uintptr_t address, size_t width);
	bool IsAddressPatched(uintptr_t address, size_t width);

private:
	bool ValidateNewPatch(uintptr_t address, size_t numBytes, std::string_view name,
		const MQPluginHandle& pluginHandle) const;

private:
	std::shared_ptr<spdlog::logger> m_logger;                        // logger for MacroQuest
	std::shared_ptr<spdlog::logger> m_eqlibLogger;                   // logger for EQLib

	bool m_coreInitialized = false;
	bool m_eqmainLoaded = false;
	eqlib::EQLibInterface* m_eqlib = nullptr;
	eqlib::MemoryPatcher* m_memoryPatcher = nullptr;                 // Memory patcher for detours and patches
};

extern MacroQuest* g_mq;

} // namespace mq
