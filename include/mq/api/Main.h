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

#include "mq/api/ActorAPI.h"
#include "mq/api/CommandAPI.h"
#include "mq/api/MacroAPI.h"
#include "mq/api/PluginAPI.h"

namespace mq {

class MainInterface
{
public:
	virtual ~MainInterface() {}

	//
	// Actor API
	//

	virtual void SendToActor(
		postoffice::Dropbox* dropbox,
		const postoffice::Address& address,
		const std::string& data,
		const postoffice::ResponseCallbackAPI& callback,
		const MQPluginHandle& pluginHandle) = 0;

	virtual void ReplyToActor(
		postoffice::Dropbox* dropbox,
		const std::shared_ptr<postoffice::Message>& message,
		const std::string& data,
		uint8_t status,
		const MQPluginHandle& pluginHandle) = 0;

	virtual postoffice::Dropbox* AddActor(
		const char* localAddress,
		postoffice::ReceiveCallbackAPI&& receive,
		const MQPluginHandle& pluginHandle) = 0;

	virtual void RemoveActor(
		postoffice::Dropbox*& dropbox,
		const MQPluginHandle& pluginHandle) = 0;

	//
	// Command API
	//

	// Commands
	virtual bool AddCommand(
		std::string_view command,
		MQCommandHandler handler,
		bool eq,
		bool parse,
		bool inGame,
		const MQPluginHandle& pluginHandle) = 0;

	virtual bool RemoveCommand(
		std::string_view command,
		const MQPluginHandle& pluginHandle) = 0;

	virtual bool IsCommand(
		std::string_view command) const = 0;

	virtual void DoCommand(
		const char* command,
		bool delayed,
		const MQPluginHandle& pluginHandle) = 0;

	virtual void TimedCommand(
		const char* command,
		int msDelay,
		const MQPluginHandle& pluginHandle) = 0;

	// Aliases
	virtual bool AddAlias(
		const std::string& shortCommand,
		const std::string& longCommand,
		bool persist,
		const MQPluginHandle& pluginHandle) = 0;

	virtual bool RemoveAlias(
		const std::string& shortCommand,
		const MQPluginHandle& pluginHandle) = 0;

	virtual bool IsAlias(
		const std::string& alias) const = 0;

	//
	// Detour API
	//

	virtual bool CreateDetour(uintptr_t address, void** target, void* detour, std::string_view name,
		const MQPluginHandle& pluginHandle) = 0;
	virtual bool RemoveDetour(uintptr_t address, const MQPluginHandle& pluginHandle) = 0;

	virtual bool AddPatch(uintptr_t address, size_t width, std::string_view name, const MQPluginHandle& pluginHandle) = 0;
	virtual bool AddPatch(uintptr_t address, const uint8_t* newBytes, size_t numBytes, const uint8_t* expectedBytes,
		std::string_view name, const MQPluginHandle& pluginHandle) = 0;
	virtual bool RemovePatch(uintptr_t address, const MQPluginHandle& pluginHandle) = 0;

	//
	// TLO API
	//

	virtual bool AddTopLevelObject(
		const char* name,
		MQTopLevelObjectFunction callback,
		const MQPluginHandle& pluginHandle) = 0;

	virtual bool RemoveTopLevelObject(
		const char* name,
		const MQPluginHandle& pluginHandle) = 0;

	virtual MQTopLevelObject* FindTopLevelObject(
		const char* name) = 0;

};

MQLIB_OBJECT MainInterface* GetMainInterface();

} // namespace mq
