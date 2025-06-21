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

#include "mq/base/PluginHandle.h"
#include "mq/base/String.h"
#include "mq/api/CommandAPI.h"

#include <mutex>

namespace mq {

//============================================================================

struct MQTimedCommand;
struct MQCommand;
struct MQPlugin;

class MQCommandAPI : public MQModule
{
public:
	MQCommandAPI();
	virtual ~MQCommandAPI() override;

	// Commands
	bool AddCommand(std::string_view command, MQCommandHandler handler,
		bool EQ = false, bool Parse = true, bool InGame = false,
		const MQPluginHandle& pluginHandle = mqplugin::ThisPluginHandle);
	bool RemoveCommand(std::string_view command,
		const MQPluginHandle& pluginHandle = mqplugin::ThisPluginHandle);

	// Queue a command for execution
	bool DoCommand(const char* szLine, bool delayed,
		const MQPluginHandle& pluginHandle = mqplugin::ThisPluginHandle);

	bool DoCommandInternal(char* szOriginalLine, char* szArg1, char* szParam);

	void TimedCommand(const char* command, int msDelay,
		const MQPluginHandle& pluginHandle = mqplugin::ThisPluginHandle);

	bool IsCommand(std::string_view command) const;
	MQCommand* FindCommand(std::string_view command) const;

	// Aliases
	bool AddAlias(const std::string& shortCommand, const std::string& longCommand,
		bool writeToIni, const MQPluginHandle& pluginHandle = mqplugin::ThisPluginHandle);
	bool RemoveAlias(const std::string& shortCommand,
		const MQPluginHandle& pluginHandle = mqplugin::ThisPluginHandle);
	bool SubstituteAlias(const char* szOriginal, char* szLine, size_t length);

	bool IsAlias(const std::string& alias) const;

	bool InterpretCmd(const char* szLine, const MQCommandHandler& eqHandler);

private:
	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void OnProcessFrame() override;
	virtual void OnAfterModuleUnloaded(MQModule* module) override;

	void Cmd_Help(const char* szLine) const;
	void Cmd_Alias(const char* szLine);

	void LoadAliases();
	void RewriteAliases();

	bool DispatchCommand(char* szCommand, char* szArgs, const MQCommandHandler& eqHandler);

	struct RegisteredAlias
	{
		std::string match;
		std::string replacement;

		MQPluginHandle pluginHandle;

		RegisteredAlias(std::string match, std::string replacement, MQPluginHandle pluginHandle)
			: match(std::move(match)), replacement(std::move(replacement)), pluginHandle(std::move(pluginHandle)) {}
	};

	static void WriteAliasToIni(const RegisteredAlias& alias);

	mq::ci_unordered::map<std::string, RegisteredAlias> m_aliases;

	struct DelayedCommand
	{
		std::string command;
		MQPluginHandle pluginHandle;

		DelayedCommand(std::string command, MQPluginHandle pluginHandle)
			: command(std::move(command)), pluginHandle(std::move(pluginHandle)) {}
	};
	std::vector<DelayedCommand> m_delayedCommands;

	MQCommand* m_pCommands = nullptr;
	MQTimedCommand* m_pTimedCommands = nullptr;
};

extern MQCommandAPI* pCommandAPI;

//============================================================================

} // namespace mq
