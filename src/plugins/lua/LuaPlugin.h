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
// TODO: This _really_ needs to be in an implementation file. Refactor this after testing
// safe to key this with string_view since the plugin will have the string
class LuaPlugin;
static ci_unordered::map<std::string_view, std::shared_ptr<LuaPlugin>> s_pluginMap;
		
#pragma region Type Helper

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

#pragma endregion

class LuaPlugin : public std::enable_shared_from_this<LuaPlugin>
{
	// TODO: move some of this into an implementation file
#pragma region Callbacks

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

	void InitializePlugin()
	{
		if (m_InitializePlugin != sol::lua_nil) m_InitializePlugin(shared_from_this());
	}

	void ShutdownPlugin()
	{
		if (m_ShutdownPlugin != sol::lua_nil) m_ShutdownPlugin(shared_from_this());
	}

	void OnCleanUI()
	{
		if (m_OnCleanUI != sol::lua_nil) m_OnCleanUI(shared_from_this());
	}

	void OnReloadUI()
	{
		if (m_OnReloadUI != sol::lua_nil) m_OnReloadUI(shared_from_this());
	}

	void OnDrawHUD()
	{
		if (m_OnDrawHUD != sol::lua_nil) m_OnDrawHUD(shared_from_this());
	}

	void SetGameState(int GameState)
	{
		if (m_SetGameState != sol::lua_nil) m_SetGameState(shared_from_this(), GameState);
	}

	void OnPulse()
	{
		if (m_OnPulse != sol::lua_nil) m_OnPulse(shared_from_this());
	}

	void OnWriteChatColor(const char* Line, int Color, int Filter)
	{
		if (m_OnWriteChatColor != sol::lua_nil) m_OnWriteChatColor(shared_from_this(), Line, Color, Filter);
	}

	bool OnIncomingChat(const char* Line, unsigned long Color)
	{
		if (m_OnIncomingChat != sol::lua_nil)
		{
			auto result = m_OnIncomingChat(shared_from_this(), Line, Color);
			if (result.valid() && result.return_count() > 0)
			{
				std::optional<bool> r = result;
				if (r) return *r;
			}
		}

		return false;
	}

	void OnAddSpawn(PlayerClient* pNewSpawn)
	{
		if (m_OnAddSpawn != sol::lua_nil && pNewSpawn != nullptr)
			m_OnAddSpawn(shared_from_this(), pNewSpawn->SpawnID); // TODO: spawns could be userdata
	}

	void OnRemoveSpawn(PlayerClient* pSpawn)
	{
		if (m_OnRemoveSpawn != sol::lua_nil && pSpawn != nullptr)
			m_OnRemoveSpawn(shared_from_this(), pSpawn->SpawnID); // TODO: spawns could be userdata
	}

	void OnAddGroundItem(EQGroundItem* pNewGroundItem)
	{
		if (m_OnAddGroundItem != sol::lua_nil && pNewGroundItem != nullptr && pNewGroundItem->Item)
			m_OnAddGroundItem(shared_from_this(), pNewGroundItem->Item->ID); // TODO: needs to be userdata
	}

	void OnRemoveGroundItem(EQGroundItem* pGroundItem)
	{
		if (m_OnRemoveGroundItem != sol::lua_nil && pGroundItem != nullptr && pGroundItem->Item)
			m_OnRemoveGroundItem(shared_from_this(), pGroundItem->Item->ID); // TODO: needs to be userdata
	}

	void OnBeginZone()
	{
		if (m_OnBeginZone != sol::lua_nil) m_OnBeginZone(shared_from_this());
	}

	void OnEndZone()
	{
		if (m_OnEndZone != sol::lua_nil) m_OnEndZone(shared_from_this());
	}

	void OnZoned()
	{
		if (m_OnZoned != sol::lua_nil) m_OnZoned(shared_from_this());
	}

	void OnUpdateImGui()
	{
		if (m_OnUpdateImGui != sol::lua_nil) m_OnUpdateImGui(shared_from_this());
	}

	void OnMacroStart(const char* Name)
	{
		if (m_OnMacroStart != sol::lua_nil) m_OnMacroStart(shared_from_this(), Name);
	}

	void OnMacroStop(const char* Name)
	{
		if (m_OnMacroStop != sol::lua_nil) m_OnMacroStop(shared_from_this(), Name);
	}

	void OnLoadPlugin(const char* Name)
	{
		if (m_OnLoadPlugin != sol::lua_nil) m_OnLoadPlugin(shared_from_this(), Name);
	}

	void OnUnloadPlugin(const char* Name)
	{
		if (m_OnUnloadPlugin != sol::lua_nil) m_OnUnloadPlugin(shared_from_this(), Name);
	}

private:
	sol::function m_InitializePlugin = sol::lua_nil;
	sol::function m_ShutdownPlugin = sol::lua_nil;
	sol::function m_OnCleanUI = sol::lua_nil;
	sol::function m_OnReloadUI = sol::lua_nil;
	sol::function m_OnDrawHUD = sol::lua_nil;
	sol::function m_SetGameState = sol::lua_nil;
	sol::function m_OnPulse = sol::lua_nil;
	sol::function m_OnWriteChatColor = sol::lua_nil;
	sol::function m_OnIncomingChat = sol::lua_nil;
	sol::function m_OnAddSpawn = sol::lua_nil;
	sol::function m_OnRemoveSpawn = sol::lua_nil;
	sol::function m_OnAddGroundItem = sol::lua_nil;
	sol::function m_OnRemoveGroundItem = sol::lua_nil;
	sol::function m_OnBeginZone = sol::lua_nil;
	sol::function m_OnEndZone = sol::lua_nil;
	sol::function m_OnZoned = sol::lua_nil;
	sol::function m_OnUpdateImGui = sol::lua_nil;
	sol::function m_OnMacroStart = sol::lua_nil;
	sol::function m_OnMacroStop = sol::lua_nil;
	sol::function m_OnLoadPlugin = sol::lua_nil;
	sol::function m_OnUnloadPlugin = sol::lua_nil;

#pragma endregion

#pragma region Commands

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

#pragma endregion

#pragma region Datatypes

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

#pragma endregion

#pragma region TLOs

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

#pragma endregion

#pragma region Interface

public:
	LuaPlugin(const std::string& name, const std::string& version)
		: m_name(name)
		, m_version(version)
	{}

	[[nodiscard]] static std::shared_ptr<LuaPlugin> Create(const std::string& name, const std::string& version)
	{
		return std::make_shared<LuaPlugin>(name, version);
	}

	void Start()
	{
		// this is where we would differ from a universal plugin interface. We can't just put it in a local map, we'd need to provide it to the larger interface
		InitializePlugin();
		s_pluginMap.emplace(m_name, shared_from_this());
	}

	void Stop()
	{
		s_pluginMap.erase(m_name);
		ShutdownPlugin();
	}

	static std::shared_ptr<LuaPlugin> Lookup(const std::string& name)
	{
		auto it = s_pluginMap.find(name);
		if (it != s_pluginMap.end())
		{
			return it->second;
		}

		return {};
	}
	
	void Set(const std::string& name, sol::object val, sol::this_state s)
	{
		if (name == "InitializePlugin" && val.is<sol::function>())
			m_InitializePlugin = val.as<sol::function>();
		else if (name == "ShutdownPlugin" && val.is<sol::function>())
			m_ShutdownPlugin = val.as<sol::function>();
		else if (name == "OnCleanUI" && val.is<sol::function>())
			m_OnCleanUI = val.as<sol::function>();
		else if (name == "OnReloadUI" && val.is<sol::function>())
			m_OnReloadUI = val.as<sol::function>();
		else if (name == "OnDrawHUD" && val.is<sol::function>())
			m_OnDrawHUD = val.as<sol::function>();
		else if (name == "SetGameState" && val.is<sol::function>())
			m_SetGameState = val.as<sol::function>();
		else if (name == "OnPulse" && val.is<sol::function>())
			m_OnPulse = val.as<sol::function>();
		else if (name == "OnWriteChatColor" && val.is<sol::function>())
			m_OnWriteChatColor = val.as<sol::function>();
		else if (name == "OnIncomingChat" && val.is<sol::function>())
			m_OnIncomingChat = val.as<sol::function>();
		else if (name == "OnAddSpawn" && val.is<sol::function>())
			m_OnAddSpawn = val.as<sol::function>();
		else if (name == "OnRemoveSpawn" && val.is<sol::function>())
			m_OnRemoveSpawn = val.as<sol::function>();
		else if (name == "OnAddGroundItem" && val.is<sol::function>())
			m_OnAddGroundItem = val.as<sol::function>();
		else if (name == "OnRemoveGroundItem" && val.is<sol::function>())
			m_OnRemoveGroundItem = val.as<sol::function>();
		else if (name == "OnBeginZone" && val.is<sol::function>())
			m_OnBeginZone = val.as<sol::function>();
		else if (name == "OnEndZone" && val.is<sol::function>())
			m_OnEndZone = val.as<sol::function>();
		else if (name == "OnZoned" && val.is<sol::function>())
			m_OnZoned = val.as<sol::function>();
		else if (name == "OnUpdateImGui" && val.is<sol::function>())
			m_OnUpdateImGui = val.as<sol::function>();
		else if (name == "OnMacroStart" && val.is<sol::function>())
			m_OnMacroStart = val.as<sol::function>();
		else if (name == "OnMacroStop" && val.is<sol::function>())
			m_OnMacroStop = val.as<sol::function>();
		else if (name == "OnLoadPlugin" && val.is<sol::function>())
			m_OnLoadPlugin = val.as<sol::function>();
		else if (name == "OnUnloadPlugin" && val.is<sol::function>())
			m_OnUnloadPlugin = val.as<sol::function>();
		else
			m_blackboard.insert_or_assign(name, val);
	}

	sol::object Get(const std::string& name, sol::this_state s)
	{
		auto it = m_blackboard.find(name);
		if (it != m_blackboard.end())
		{
			return it->second;
		}

		sol::state_view L(s);
		return sol::object(s, sol::in_place, sol::nil);
	}

	static void RegisterLua(sol::table& mq)
	{
		// create a plugin with local plugin = mq.plugin.new(name, version), then you can do plugin:callback(...) etc
		// finally, you'd do plugin:start() to add it to the map and plugin:stop() will remove it from the map
		// TODO: Need to tie `/lua run` and `/lua stop` to start/stop (especially the latter, we can require that the user start the plugin in the script)
		mq.new_usertype<LuaPlugin>(
			"plugin",
			sol::meta_function::construct, sol::factories(&LuaPlugin::Create),
			sol::call_constructor, &LuaPlugin::Create,
			"command", &LuaPlugin::RegisterCommand,
			"datatype", &LuaPlugin::RegisterDatatype,
			"tlo", &LuaPlugin::RegisterData,
			"start", &LuaPlugin::Start,
			"stop", &LuaPlugin::Stop,
			"lookup", &LuaPlugin::Lookup,
			sol::meta_function::index, &LuaPlugin::Get,
			sol::meta_function::new_index, &LuaPlugin::Set
			);
	}

private:
	std::string m_name;
	std::string m_version;

	ci_unordered::map<std::string, sol::object> m_blackboard;
#pragma endregion
};
} // namespace mq::lua
