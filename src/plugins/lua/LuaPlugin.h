/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2022 MacroQuest Authors
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

#include "pch.h"
#include "common/StringUtils.h"

#include "LuaCommon.h"

#include <mq/Plugin.h>

namespace mq::lua {
class LuaPlugin
{
public:
	enum class Callback
	{
		InitializePlugin,
		ShutdownPlugin,
		OnCleanUI,
		OnReloadUI,
		OnDrawHUD,
		SetGameState,
		OnPulse,
		OnWriteChatColor,
		OnIncomingChat,
		OnAddSpawn,
		OnRemoveSpawn,
		OnAddGroundItem,
		OnRemoveGroundItem,
		OnBeginZone,
		OnEndZone,
		OnZoned,
		OnUpdateImGui,
		OnMacroStart,
		OnMacroStop,
		OnLoadPlugin,
		OnUnloadPlugin
	};

	void RegisterCallbackEnum(sol::state_view lua)
	{
		lua.new_enum("PluginCallback",
			"InitializePlugin", Callback::InitializePlugin,
			"ShutdownPlugin", Callback::ShutdownPlugin,
			"OnCleanUI", Callback::OnCleanUI,
			"OnReloadUI", Callback::OnReloadUI,
			"OnDrawHUD", Callback::OnDrawHUD,
			"SetGameState", Callback::SetGameState,
			"OnPulse", Callback::OnPulse,
			"OnWriteChatColor", Callback::OnWriteChatColor,
			"OnIncomingChat", Callback::OnIncomingChat,
			"OnAddSpawn", Callback::OnAddSpawn,
			"OnRemoveSpawn", Callback::OnRemoveSpawn,
			"OnAddGroundItem", Callback::OnAddGroundItem,
			"OnRemoveGroundItem", Callback::OnRemoveGroundItem,
			"OnBeginZone", Callback::OnBeginZone,
			"OnEndZone", Callback::OnEndZone,
			"OnZoned", Callback::OnZoned,
			"OnUpdateImGui", Callback::OnUpdateImGui,
			"OnMacroStart", Callback::OnMacroStart,
			"OnMacroStop", Callback::OnMacroStop,
			"OnLoadPlugin", Callback::OnLoadPlugin,
			"OnUnloadPlugin", Callback::OnUnloadPlugin
		);
	}

	void RegisterCallback(const Callback callback, sol::function func)
	{
		auto callback_it = m_callbacks.find(callback);
		if (callback_it != m_callbacks.end())
		{
			callback_it->second.emplace_back(func);
		}
		else
		{
			m_callbacks.emplace(callback, std::vector({ func }));
		}
	}

	template <typename... Args>
	void RunCallback(const Callback callback, Args... args)
	{
		auto callback_it = m_callbacks.find(callback);
		if (callback_it != m_callbacks.end())
		{
			for (auto f : callback_it->second)
			{
				f(std::forward(args)...); // TODO: this should probably do some action on the result, and return a CoroutineResult
			}
		}
	}

private:
	std::unordered_map<Callback, std::vector<sol::function>> m_callbacks;

private:
	// This is a hack because you can't capture in a function pointer, but we need to capture the lua function
	struct FPtr
	{
		template <typename T>
		static void func_ptr_exec(PlayerClient* Player, char* Buffer)
		{
			return (void)(*(T*)fn<T>())(Player, Buffer);
		}

		template <typename T>
		static fEQCommand ptr(T& t)
		{
			fn<T>(&t);
			return func_ptr_exec<T>;
		}

		template <typename T>
		static void* fn(void* new_fn = nullptr)
		{
			static void* fn;
			if (new_fn != nullptr) fn = new_fn;
			return fn;
		}
	};

public:
	static fEQCommand CreateCommand(sol::function func)
	{
		auto ret_func = [&func](PlayerClient*, char* Buffer) -> void
		{
			// TODO: Does Buffer include the command? If so, drop the first arg
			auto args = tokenize_args(Buffer);
			func(sol::as_args(args)); // TODO: should probably do some action on the result, and make sure we don't crash if the command fails
		};

		return FPtr::ptr(ret_func);
	}

	void RegisterCommand(const std::string& name, sol::function func)
	{
		if (IsCommand(name.c_str()))
		{
			LuaError("Cannot create command %s, already a command in MQ.", name.c_str());
		}
		else if (name.empty() || name[0] != '/')
		{
			LuaError("Cannot create command %s, not a valid command string.", name.c_str());
		}
		else
		{
			m_commands.emplace(name, func);
			AddCommand(name.c_str(), CreateCommand(func)); // TODO: we might want to pass the optional booleans here
		}
	}

	void UnregisterCommands()
	{
		for (auto& command : m_commands)
		{
			RemoveCommand(command.first.c_str());
		}

		m_commands.clear();
	}

private:
	ci_unordered::map<std::string, sol::function> m_commands;
	
};
} // namespace mq::lua
