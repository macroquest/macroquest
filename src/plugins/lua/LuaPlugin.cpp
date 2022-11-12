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

#include "pch.h"
#include "common/StringUtils.h"
#include "LuaPlugin.h"
#include "LuaThread.h"

#include <luajit.h>

namespace mq::lua {

static ci_unordered::map<std::string, std::shared_ptr<LuaPlugin>> s_pluginMap;

#pragma region Type Helper

MQ2LuaGenericType::MQ2LuaGenericType(const std::string& typeName, sol::table members, sol::function toString, sol::function fromData, sol::function fromString)
	: m_typeName(typeName)
	, m_toString(toString)
	, m_fromData(fromData)
	, m_fromString(fromString)
	, MQ2Type(typeName.c_str())
{
	for (const auto& [first, second] : members)
	{
		auto maybe_name = first.as<std::optional<std::string>>();
		auto maybe_val = second.as<std::optional<sol::function>>();
		if (maybe_name && maybe_val)
		{
			m_memberMap[*maybe_name] = *maybe_val;
		}
	}
}

bool MQ2LuaGenericType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
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
					const char* val_str = luaL_tolstring(stack_val.lua_state(), stack_val.stack_index(), &len);
					lua_pop(stack_val.lua_state(), 1);

					return type->FromString(Dest, val_str);
				}
			}
		}
	}

	return false;
}

bool MQ2LuaGenericType::ToString(MQVarPtr VarPtr, char* Destination)
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

bool MQ2LuaGenericType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
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

bool MQ2LuaGenericType::FromString(MQVarPtr& VarPtr, const char* Source)
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

void MQ2LuaGenericType::Abandon()
{
	for (auto& [_, member] : m_memberMap)
		member.abandon();

	m_toString.abandon();
	m_fromData.abandon();
	m_fromString.abandon();
}

#pragma endregion

#pragma region Callbacks

void LuaPlugin::InitializePlugin()
{
	if (m_InitializePlugin != sol::lua_nil) m_InitializePlugin(m_pluginTable);
}

void LuaPlugin::ShutdownPlugin()
{
	if (m_ShutdownPlugin != sol::lua_nil) m_ShutdownPlugin(m_pluginTable);
}

void LuaPlugin::OnCleanUI()
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnCleanUI != sol::lua_nil)
			plugin->m_OnCleanUI(plugin->m_pluginTable);
}

void LuaPlugin::OnReloadUI()
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnReloadUI != sol::lua_nil)
			plugin->m_OnReloadUI(plugin->m_pluginTable);
}

void LuaPlugin::OnDrawHUD()
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnDrawHUD != sol::lua_nil)
			plugin->m_OnDrawHUD(plugin->m_pluginTable);
}

void LuaPlugin::SetGameState(int GameState)
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_SetGameState != sol::lua_nil)
			plugin->m_SetGameState(plugin->m_pluginTable, GameState);
}

void LuaPlugin::OnPulse()
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnPulse != sol::lua_nil)
			plugin->m_OnPulse(plugin->m_pluginTable);
}

void LuaPlugin::OnWriteChatColor(const char* Line, int Color, int Filter)
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnWriteChatColor != sol::lua_nil)
			plugin->m_OnWriteChatColor(plugin->m_pluginTable, Line, Color, Filter);
}

bool LuaPlugin::OnIncomingChat(const char* Line, unsigned long Color)
{
	return std::accumulate(s_pluginMap.begin(), s_pluginMap.end(), false,
		[&Line, &Color](bool acc, const auto& pair)
		{
			const auto& plugin = pair.second;
			if (plugin->m_OnIncomingChat != sol::lua_nil)
			{
				auto result = plugin->m_OnIncomingChat(plugin->m_pluginTable, Line, Color);
				if (result.valid() && result.return_count() > 0)
				{
					std::optional<bool> r = result;
					if (r) return *r || acc;
				}
			}

			return acc;
		});
}

void LuaPlugin::OnAddSpawn(PlayerClient* pNewSpawn)
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnAddSpawn != sol::lua_nil && pNewSpawn != nullptr)
			plugin->m_OnAddSpawn(plugin->m_pluginTable, pNewSpawn->SpawnID); // TODO: spawns could be userdata
}

void LuaPlugin::OnRemoveSpawn(PlayerClient* pSpawn)
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnRemoveSpawn != sol::lua_nil && pSpawn != nullptr)
			plugin->m_OnRemoveSpawn(plugin->m_pluginTable, pSpawn->SpawnID); // TODO: spawns could be userdata
}

void LuaPlugin::OnAddGroundItem(EQGroundItem* pNewGroundItem)
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnAddGroundItem != sol::lua_nil && pNewGroundItem != nullptr && pNewGroundItem->Item)
			plugin->m_OnAddGroundItem(plugin->m_pluginTable, pNewGroundItem->Item->ID); // TODO: needs to be userdata
}

void LuaPlugin::OnRemoveGroundItem(EQGroundItem* pGroundItem)
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnRemoveGroundItem != sol::lua_nil && pGroundItem != nullptr && pGroundItem->Item)
			plugin->m_OnRemoveGroundItem(plugin->m_pluginTable, pGroundItem->Item->ID); // TODO: needs to be userdata
}

void LuaPlugin::OnBeginZone()
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnBeginZone != sol::lua_nil)
			plugin->m_OnBeginZone(plugin->m_pluginTable);
}

void LuaPlugin::OnEndZone()
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnEndZone != sol::lua_nil)
			plugin->m_OnEndZone(plugin->m_pluginTable);
}

void LuaPlugin::OnZoned()
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnZoned != sol::lua_nil)
			plugin->m_OnZoned(plugin->m_pluginTable);
}

void LuaPlugin::OnUpdateImGui()
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnUpdateImGui != sol::lua_nil)
			plugin->m_OnUpdateImGui(plugin->m_pluginTable);
}

void LuaPlugin::OnMacroStart(const char* Name)
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnMacroStart != sol::lua_nil)
			plugin->m_OnMacroStart(plugin->m_pluginTable, Name);
}

void LuaPlugin::OnMacroStop(const char* Name)
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnMacroStop != sol::lua_nil)
			plugin->m_OnMacroStop(plugin->m_pluginTable, Name);
}

void LuaPlugin::OnLoadPlugin(const char* Name)
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnLoadPlugin != sol::lua_nil)
			plugin->m_OnLoadPlugin(plugin->m_pluginTable, Name);
}

void LuaPlugin::OnUnloadPlugin(const char* Name)
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnUnloadPlugin != sol::lua_nil)
			plugin->m_OnUnloadPlugin(plugin->m_pluginTable, Name);
}

#pragma endregion

#pragma region Commands

void LuaPlugin::RegisterCommand(const std::string& name, sol::function func)
{
	if (IsCommand(name.c_str()) || m_commands.find(name) != m_commands.end())
	{
		LuaError("Cannot create command %s, already a command in MQ.", name.c_str());
	}
	else if (name.empty() || name[0] != '/')
	{
		LuaError("Cannot create command %s, not a valid command string.", name.c_str());
	}
	else
	{
		m_commands[name] = func;
	}
}

void LuaPlugin::AddCommands()
{
	for (auto it = m_commands.begin(); it != m_commands.end();)
	{
		const auto& [command, func] = *it;
		std::tuple<int, bool> arginfo = m_pluginTable["__command_arginfo"](func);
		auto [numargs, vararg] = arginfo;

		if (vararg)
		{
			LuaError("Invalid command %s: commands do not support variadic arguments.", command.c_str());
			it = m_commands.erase(it);
		}
		else if (numargs != 1 && numargs != 2)
		{
			LuaError("Invalid number of arguments (%d) for command %s", numargs, command.c_str());
			it = m_commands.erase(it);
		}
		else
		{
			AddFunction(command.c_str(), [func = func, this, numargs = numargs](PlayerClient*, char* Buffer) -> void
				{
					if (numargs == 1)
						func(Buffer);
					else if (numargs == 2)
						func(m_pluginTable, Buffer);
				}); // TODO: we might want to pass the optional booleans here
			++it;
		}
	}
}

void LuaPlugin::UnregisterCommands()
{
	for (const auto& [command, _] : m_commands)
	{
		RemoveCommand(command.c_str());
	}

	m_commands.clear();
}

#pragma endregion

#pragma region Datatypes

void LuaPlugin::RegisterDatatype(const std::string& name, sol::table members, sol::function toString, sol::function fromData, sol::function fromString)
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

void LuaPlugin::UnregisterDatatypes()
{
	m_dataTypes.clear();
}

#pragma endregion

#pragma region TLOs

fMQData LuaPlugin::CreateData(sol::function func)
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
					const char* val_str = luaL_tolstring(stack_val.lua_state(), stack_val.stack_index(), &len);
					lua_pop(stack_val.lua_state(), 1);

					return type->FromString(Dest, val_str);
				}
			}
		}

		return false;
	};

	return FPtr::ptr(ret_func);
}

void LuaPlugin::RegisterData(const std::string& name, sol::function func)
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

void LuaPlugin::UnregisterData()
{
	for (const auto& tlo : m_dataTLOs)
	{
		RemoveMQ2Data(tlo.first.c_str());
	}
	m_dataTLOs.clear();
}

#pragma endregion

#pragma region Interface

LuaPlugin::LuaPlugin(const std::string& name, const std::string& version, sol::this_state s)
	: m_name(name)
	, m_version(version)
	, m_thread(LuaThread::get_from(s))
{}

LuaPlugin::~LuaPlugin()
{
	m_InitializePlugin = sol::lua_nil;
	m_ShutdownPlugin = sol::lua_nil;
	m_OnCleanUI = sol::lua_nil;
	m_OnReloadUI = sol::lua_nil;
	m_OnDrawHUD = sol::lua_nil;
	m_SetGameState = sol::lua_nil;
	m_OnPulse = sol::lua_nil;
	m_OnWriteChatColor = sol::lua_nil;
	m_OnIncomingChat = sol::lua_nil;
	m_OnAddSpawn = sol::lua_nil;
	m_OnRemoveSpawn = sol::lua_nil;
	m_OnAddGroundItem = sol::lua_nil;
	m_OnRemoveGroundItem = sol::lua_nil;
	m_OnBeginZone = sol::lua_nil;
	m_OnEndZone = sol::lua_nil;
	m_OnZoned = sol::lua_nil;
	m_OnUpdateImGui = sol::lua_nil;
	m_OnMacroStart = sol::lua_nil;
	m_OnMacroStop = sol::lua_nil;
	m_OnLoadPlugin = sol::lua_nil;
	m_OnUnloadPlugin = sol::lua_nil;

	UnregisterCommands();
	UnregisterDatatypes();
	UnregisterData();
}

// the first argument here is the self argument, which will always be the mq.plugin table
sol::table LuaPlugin::Create(sol::table, const std::string& name, const std::string& version, sol::this_state s)
{
	auto ptr = std::make_shared<LuaPlugin>(name, version, s);
	ptr->m_pluginTable = sol::state_view(s).create_table_with(
		"__plugin", ptr,
		"bindcommand", [](sol::table self, const std::string& command, sol::function func)
			{ self.get<std::shared_ptr<LuaPlugin>>("__plugin")->RegisterCommand(command, func); },
		"name", ptr->m_name,
		"version", ptr->m_version
	);

	sol::function arginfo = sol::state_view(s).script(R"(
		return function(f)
			local info = debug.getinfo(f)
			return info.nparams, info.isvararg
		end
	)");

	ptr->m_pluginTable["__command_arginfo"] = arginfo;

	return ptr->m_pluginTable;
}

void LuaPlugin::Start(sol::table plugin)
{
	// this is where we would differ from a universal plugin interface. We can't just put it in a local map, we'd need to provide it to the larger interface
	if (IsPlugin(plugin))
	{
		auto ptr = plugin.get<std::shared_ptr<LuaPlugin>>("__plugin");
		for (const auto& [k, v] : plugin)
		{
			if (k.is<std::string>() && v.get_type() == sol::type::function)
				ptr->Set(k.as<const std::string&>(), v, plugin.lua_state());
		}

		ptr->InitializePlugin();
		ptr->AddCommands();
		s_pluginMap.insert_or_assign(ptr->Name(), ptr);

		// we no longer need to hold the pointer to the LuaPlugin, and if we don't get rid of it, we'll always have one ref
		// which will cause the state to hold pointer which in turn is held by the LuaPlugin, need to make sure to get rid
		// of this circular dependency
		plugin["__plugin"] = sol::nil;

		// force gc in case we assigned instead of inserted to prevent dual definitions
		sol::state_view(plugin.lua_state()).collect_garbage(); 
	}
}

void LuaPlugin::Stop(const std::string& name)
{
	auto it = s_pluginMap.find(name);
	if (it != s_pluginMap.end())
	{
		s_pluginMap.erase(it);
	}
}

void LuaPlugin::StopAll()
{
	s_pluginMap.clear();
}

std::shared_ptr<LuaPlugin> LuaPlugin::Lookup(const std::string& name)
{
	auto it = s_pluginMap.find(name);
	if (it != s_pluginMap.end())
	{
		return it->second;
	}

	return {};
}

bool LuaPlugin::IsRunning(const std::string& name)
{
	return s_pluginMap.find(name) != s_pluginMap.end();
}

std::vector<std::string> LuaPlugin::GetRunning()
{
	std::vector<std::string> keys(s_pluginMap.size());
	std::transform(s_pluginMap.begin(), s_pluginMap.end(), keys.begin(), [](auto pair) { return pair.first; });
	return keys;
}

void LuaPlugin::Set(const std::string& name, sol::object val, sol::this_state s)
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
}

void LuaPlugin::RegisterLua(sol::table& mq)
{
	// create a plugin with local plugin = mq.plugin.new(name, version), then you can do plugin:callback(...) etc
	// finally, you'd do plugin:start() to add it to the map and plugin:stop() will remove it from the map
	sol::usertype<LuaPlugin> plugin = mq.new_usertype<LuaPlugin>(
		"__plugin",
		sol::meta_function::construct, sol::no_constructor,
		"datatype", &LuaPlugin::RegisterDatatype,
		"tlo", &LuaPlugin::RegisterData
	);

	mq["plugin"] = sol::state_view(mq.lua_state()).create_table_with(
		"start", &LuaPlugin::Start,
		"stop", &LuaPlugin::Stop,
		sol::metatable_key, sol::state_view(mq.lua_state()).create_table_with(
			"__call", &LuaPlugin::Create
		)
	);
}

bool LuaPlugin::IsPlugin(sol::table table)
{
	sol::object plugin = table["__plugin"];
	return plugin.is<LuaPlugin>();
}

#pragma endregion

} // namespace mq::lua
