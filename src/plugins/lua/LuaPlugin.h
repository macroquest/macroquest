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
	ci_unordered::map<std::string, sol::function> m_memberMap;
	sol::function m_toString;
	sol::function m_fromData;
	sol::function m_fromString;

public:
	MQ2LuaGenericType(const std::string& typeName, sol::table members, sol::function toString, sol::function fromData, sol::function fromString)
		: m_typeName(typeName)
		, m_toString(toString)
		, m_fromData(fromData)
		, m_fromString(fromString)
		, MQ2Type(typeName.c_str())
	{
		for (const auto& member : members)
		{
			auto maybe_name = member.first.as<std::optional<std::string>>();
			auto maybe_val = member.second.as<std::optional<sol::function>>();
			if (maybe_name && maybe_val)
			{
				m_memberMap.emplace(*maybe_name, *maybe_val);
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
				std::tuple<std::optional<std::string>, sol::object> r = result;
				auto& [typeName, typeValue] = r;
				if (typeName)
				{
					// TODO: This should probably use template specializations for known MQ2Type conversions, then fall through to this really inefficient method
					MQ2Type* type = FindMQ2DataType(typeName->c_str());
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
				std::optional<std::string> r = result;
				strcpy_s(Destination, MAX_STRING, r.value_or("").c_str());
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

private:
	// this is a hack because you can't capture in a function pointer, but we need to capture the lua function
	struct FPtr
	{
		template <typename T>
		static bool func_ptr_exec(const char* Index, MQTypeVar& Dest)
		{
			return (bool)(*(T*)fn<T>())(Index, Dest);
		}

		template <typename T>
		static fMQData ptr(T& t)
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

	static fMQData CreateData(sol::function func)
	{
		auto ret_func = [&func](const char* Index, MQTypeVar& Dest) -> bool
		{
			auto result = func(Index);
			if (result.valid() && result.return_count() > 1)
			{
				std::tuple<std::optional<std::string>, sol::object> r = result;
				auto& [typeName, typeValue] = r;
				if (typeName)
				{
					// TODO: This should probably use template specializations for known MQ2Type conversions, then fall through to this really inefficient method
					MQ2Type* type = FindMQ2DataType(typeName->c_str());
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

			return false;
		};

		return FPtr::ptr(ret_func);
	}

public:
	void RegisterData(const std::string& name, sol::function func)
	{
		if (FindMQ2Data(name.c_str()) != nullptr)
		{
			LuaError("Cannot create TLO %s, already a datatype in MQ.", name.c_str());
		}
		else if (name.empty())
		{
			LuaError("Cannot create TLO %s, not a valid name.", name.c_str());
		}
		else
		{
			m_dataTLOs.emplace(name, func);
			AddMQ2Data(name.c_str(), CreateData(func));
		}
	}

	void UnregisterData()
	{
		for (const auto& tlo : m_dataTLOs)
		{
			RemoveMQ2Data(tlo.first.c_str());
		}
		m_dataTLOs.clear();
	}

private:
	ci_unordered::map<std::string, sol::function> m_dataTLOs;
};
} // namespace mq::lua
