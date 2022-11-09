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
#include <sol/sol.hpp>

namespace mq::lua {
class MQ2LuaGenericType : public MQ2Type
{
private:
	std::string m_typeName;
	ci_unordered::map<const char*, sol::function> m_memberMap;
	sol::function m_toString;
	sol::function m_fromData;
	sol::function m_fromString;

public:
	MQ2LuaGenericType(std::string_view typeName, sol::table members, sol::function toString, sol::function fromData, sol::function fromString)
		: m_typeName(typeName)
		, m_toString(toString)
		, m_fromData(fromData)
		, m_fromString(fromString)
		, MQ2Type(fmt::format("{}", typeName).c_str()) // not a huge fan of this, but the base class will init first, can't use m_typeName
	{
		for (const auto& member : members)
		{
			auto maybe_name = member.first.as<std::optional<std::string_view>>();
			auto maybe_val = member.second.as<std::optional<sol::function>>();
			if (maybe_name && maybe_val)
			{
				m_memberMap.emplace(fmt::format("{}", *maybe_name).c_str(), *maybe_val);
			}
		}
	}

	virtual bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override
	{
		auto member_it = m_memberMap.find(Member);
		auto ptr = VarPtr.Get<sol::object>();
		if (member_it != m_memberMap.end() && ptr)
		{
			auto result = member_it->second(*ptr, Index);
			if (result.valid() && result.return_count() > 1)
			{
				std::tuple<std::optional<std::string_view>, sol::object> r = result;
				std::optional<std::string_view> typeName = std::get<0>(r);
				sol::object typeValue = std::get<1>(r);
				if (typeName)
				{
					MQ2Type* type = FindMQ2DataType(fmt::format("{}", *typeName).c_str());
					if (type != nullptr)
					{
						Dest.Type = type;

						// now take the value, stringify it, then use the type's fromstring to deser it
						auto pp = sol::stack::push_pop(typeValue);
						auto stack_val = sol::stack_object(typeValue.lua_state(), -1);
						std::size_t len;
						const char* val_str = lua_tolstring(stack_val.lua_state(), stack_val.stack_index(), &len);
						lua_pop(stack_val.lua_state(), 1);

						return type->FromString(Dest, val_str);
					}
				}
			}
		}
		
		return false;
	}

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		auto ptr = VarPtr.Get<sol::object>();
		if (ptr)
		{
			auto result = m_toString(*ptr);
			if (result.valid() && result.return_count() > 0)
			{
				std::optional<std::string_view> r = result;
				fmt::format_to(Destination, "{}", r.value_or(""));
				return true;
			}
		}

		return false;
	}

	bool FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
	{
		auto ptr = Source.Get<sol::object>();
		if (ptr)
		{
			auto result = m_fromData(*ptr);
			if (result.valid() && result.return_count() > 0)
			{
				sol::object r = result;
				if (r != sol::lua_nil)
				{
					VarPtr.Set(r);
					return true;
				}
			}
		}

		return false;
	}

	bool FromString(MQVarPtr& VarPtr, const char* Source)
	{
		auto result = m_fromString(Source);
		if (result.valid() && result.return_count() > 0)
		{
			sol::object r = result;
			if (r != sol::lua_nil)
			{
				VarPtr.Set(r);
				return true;
			}
		}

		return false;
	}
};

class LuaPlugin
{
	// TODO: need factory method for plugins
	// TODO: need TLO methods
	// TODO: move some of this into an implementation file
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

public:
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
			AddFunction(name.c_str(), [&func](PlayerClient*, char* Buffer) -> void
				{
					// TODO: Does Buffer include the command? If so, drop the first arg
					auto args = tokenize_args(Buffer);
					func(sol::as_args(args)); // TODO: should probably do some action on the result, and make sure we don't crash if the command fails
				}); // TODO: we might want to pass the optional booleans here
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

public:
	void RegisterDatatype(const std::string& name, sol::table members, sol::function toString, sol::function fromData, sol::function fromString)
	{
		if (FindMQ2DataType(name.c_str()) != nullptr)
		{
			LuaError("Cannot create datatype %s, already a datatype in MQ.", name.c_str());
		}
		else if (name.empty())
		{
			LuaError("Cannot create datatype %s, not a valid name.", name.c_str());
		}
		else
		{
			m_dataTypes.emplace(name, std::make_unique<MQ2LuaGenericType>(name, members, toString, fromData, fromString));
		}
	}

	void UnregisterDatatypes()
	{
		m_dataTypes.clear();
	}

private:
	ci_unordered::map<std::string, std::unique_ptr<MQ2LuaGenericType>> m_dataTypes;
	
};
} // namespace mq::lua
