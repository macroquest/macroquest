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

static ci_unordered::map<std::string_view, std::shared_ptr<LuaPlugin>> s_pluginMap;

#pragma region Static Helpers

static std::tuple<const std::string&, const std::string&, int, bool> GetArgInfo(sol::table plugin, sol::function func)
{
	return plugin["__command_arginfo"](func);
}

static std::tuple<int, sol::function> SetFunction(sol::table plugin, sol::function func, int local_args)
{
	auto [name, namewhat, numargs, vararg] = GetArgInfo(plugin, func);
	if (vararg)
	{
		LuaError("Invalid function %s %s: no support for variadic arguments.", namewhat.c_str(), name.c_str());
		return std::make_tuple(-1, sol::lua_nil);
	}
	else if (numargs != local_args && numargs != local_args + 1)
	{
		LuaError("Invalid number of arguments (%d) for function %s %s", numargs, namewhat.c_str(), name.c_str());
		return std::make_tuple(-1, sol::lua_nil);
	}

	return std::make_tuple(numargs, func);
}

static sol::object CopyObject(sol::object object, lua_State* state)
{
	sol::type type = object.get_type();
	if (type == sol::type::string)
	{
		auto val = object.as<std::string>();
		return sol::make_object(state, val);
	}

	if (type == sol::type::number)
	{
		auto val = object.as<double>();
		return sol::make_object(state, val);
	}

	if (type == sol::type::boolean)
	{
		auto val = object.as<bool>();
		return sol::make_object(state, val);
	}

	if (type == sol::type::function)
	{
		auto val = object.as<sol::function>();
		sol::bytecode bc = val.dump();

		auto result = sol::state_view(state).safe_script(bc.as_string_view(), sol::script_pass_on_error);
		if (result.valid())
		{
			sol::function func = result;
			return result;
		}
	}

	if (type == sol::type::table)
	{
		auto val = object.as<sol::table>();
		auto new_table = sol::state_view(state).create_table();
		for (auto& [k, v] : val)
		{
			new_table.set(CopyObject(k, state), CopyObject(v, state));
		}

		return new_table;
	}

	// any type we don't support will automatically become nil (specifically thread, userdata, and lightuserdata)
	// userdata could potentially be copyable if we require that there is a :copy() function on it, but that 
	// can be added later if it is actually important. 
	return sol::make_object(state, sol::lua_nil);
}

static bool EvaluateObject(MQ2Type* type, sol::object object, MQVarPtr& Dest)
{
	if (type == nullptr || object == sol::lua_nil)
		return false;

	// These all return false if the value doesn't come back as the correct type because we want
	// to be able to assume that the user, who specified the type, correctly knows what they 
	// wanted to get from the return value
	if (type == mq::datatypes::pBoolType)
	{
		auto maybe = object.as<std::optional<bool>>();
		if (maybe)
		{
			Dest.Set(*maybe);
			return true;
		}

		return false;
	}

	if (type == mq::datatypes::pIntType)
	{
		auto maybe = object.as<std::optional<int>>();
		if (maybe)
		{
			Dest.Set(*maybe);
			return true;
		}

		return false;
	}

	if (type == mq::datatypes::pInt64Type)
	{
		auto maybe = object.as<std::optional<int64_t>>();
		if (maybe)
		{
			Dest.Set(*maybe);
			return true;
		}

		return false;
	}

	if (type == mq::datatypes::pByteType)
	{
		auto maybe = object.as<std::optional<uint8_t>>();
		if (maybe)
		{
			Dest.Set(*maybe);
			return true;
		}

		return false;
	}

	if (type == mq::datatypes::pFloatType)
	{
		auto maybe = object.as<std::optional<float>>();
		if (maybe)
		{
			Dest.Set(*maybe);
			return true;
		}

		return false;
	}

	if (type == mq::datatypes::pDoubleType)
	{
		auto maybe = object.as<std::optional<double>>();
		if (maybe)
		{
			Dest.Set(*maybe);
			return true;
		}

		return false;
	}

	if (type == mq::datatypes::pTimeStampType)
	{
		auto maybe = object.as<std::optional<int64_t>>();
		if (maybe)
		{
			Dest.Set(*maybe);
			return true;
		}

		return false;
	}

	// we want to specifically specialize the lua generic type because we need to serde from
	// another lua state in general.
	if (LuaPlugin::IsDatatype(type->GetName()))
	{
		Dest.Set(CopyObject(object, static_cast<MQ2LuaGenericType*>(type)->GetState()));
		return true;
	}

	// no need to specialize string, we want to do the string conversion default on that anyway

	// This is the generic handler. It is safe because it's copying a string into the local lua state
	// as a way to serde values. It's not super efficient, but we can't make assumptions about
	// non-primitiive types.
	auto pp = sol::stack::push_pop(object);
	auto stack_val = sol::stack_object(object.lua_state(), -1);
	std::size_t len;
	const char* val_str = luaL_tolstring(stack_val.lua_state(), stack_val.stack_index(), &len);
	lua_pop(stack_val.lua_state(), 1);

	return type->FromString(Dest, val_str);
}

#pragma endregion

#pragma region Type Helper

MQ2LuaGenericType::MQ2LuaGenericType(sol::table plugin, const std::string& typeName, sol::table members, sol::function toString, sol::function fromData, sol::function fromString)
	: m_pluginTable(plugin)
	, m_typeName(typeName)
	, m_toString(SetFunction(m_pluginTable, toString, 1))
	, m_fromData(SetFunction(m_pluginTable, fromData, 1))
	, m_fromString(SetFunction(m_pluginTable, fromString, 1))
	, MQ2Type(typeName.c_str())
{
	for (const auto& [first, second] : members)
	{
		auto maybe_name = first.as<std::optional<std::string>>();
		auto maybe_val = second.as<std::optional<sol::function>>();
		if (maybe_name && maybe_val)
		{
			m_memberMap[*maybe_name] = SetFunction(m_pluginTable, *maybe_val, 2);
		}
	}
}

bool MQ2LuaGenericType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	auto member_it = m_memberMap.find(Member);
	auto ptr = VarPtr.Get<sol::object>();
	if (member_it != m_memberMap.end() && ptr)
	{
		auto& [numargs, func] = member_it->second;
		auto result = numargs == 2 ? func(*ptr, Index) : func(m_pluginTable, *ptr, Index);
		if (result.valid() && result.return_count() > 1)
		{
			std::tuple<std::optional<std::string>, sol::object> r = result;
			auto& [typeName, typeValue] = r;
			if (typeName && typeValue != sol::lua_nil)
			{
				MQ2Type* type = FindMQ2DataType(typeName->c_str());
				Dest.Type = type;
				return EvaluateObject(type, typeValue, Dest);
			}
		}
	}

	return false;
}

bool MQ2LuaGenericType::ToString(MQVarPtr VarPtr, char* Destination)
{
	auto ptr = VarPtr.Get<sol::object>();
	auto [numargs, func] = m_toString;
	if (ptr && numargs >= 0)
	{
		auto result = numargs == 1 ? func(*ptr) : func(m_pluginTable, *ptr);
		if (result.valid() && result.return_count() > 0)
		{
			std::optional<std::string> r = result;
			if (r)
			{
				strcpy_s(Destination, MAX_STRING, r->c_str());
				return true;
			}
		}
	}

	strcpy_s(Destination, MAX_STRING, m_typeName.c_str());
	return true;
}

bool MQ2LuaGenericType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type != nullptr && LuaPlugin::IsDatatype(Source.Type->GetName()))
	{
		auto ptr = Source.Get<sol::object>();
		auto [numargs, func] = m_fromData;
		if (ptr && numargs >= 0)
		{
			// we need to make sure to do this because we can't be sure the lua state is the same as
			// the local lua state, we need to serde
			sol::object val = CopyObject(*ptr, GetState());
			MQTypeVar temp_var;
			temp_var.Type = Source.Type;
			auto result = numargs == 1 ? func(val) : func(m_pluginTable, val);
			if (result.valid() && result.return_count() > 0)
			{
				sol::object r = result;
				if (r != sol::lua_nil)
				{
					// we can directly set this here because the act of copying the source
					// object into this state means that the result will be in this state
					VarPtr.Set(r);
				}
			}
		}
	}

	return false;
}

bool MQ2LuaGenericType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	auto [numargs, func] = m_fromString;
	auto result = numargs == 1 ? func(Source) : func(m_pluginTable, Source);
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

lua_State* MQ2LuaGenericType::GetState()
{
	return m_pluginTable.lua_state();
}

#pragma endregion

#pragma region Callbacks

void LuaPlugin::SetCallback(const std::string& name, sol::object val, sol::this_state s)
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
		auto [_1, _2, numargs, vararg] = GetArgInfo(m_pluginTable, func);

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
					numargs == 1 ? func(Buffer) : func(m_pluginTable, Buffer);
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

//void LuaPlugin::RegisterDatatype(const std::string& name, sol::table members, sol::function toString, sol::function fromData, sol::function fromString)
void LuaPlugin::RegisterDatatype(const std::string& name, sol::table datatype)
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
		sol::table members = datatype.get_or("Members", sol::lua_nil);
		sol::function toString = datatype.get_or("ToString", sol::lua_nil);
		sol::function fromData = datatype.get_or("FromData", sol::lua_nil);
		sol::function fromString = datatype.get_or("FromString", sol::lua_nil);

		// This breaks symmetry because the ctor for all types automatically registers the type.
		// We can't defer the registration to the plugin start.
		// This means that the datatypes will get registered even if the user fails to return the plugin
		// from the script. Theoretically, the LuaPlugin will destruct and the type will get unregistered
		// in that process, but it seems a bit shaky.
		// TODO: Test this hypothesis
		m_dataTypes.emplace(name, std::make_unique<MQ2LuaGenericType>(m_pluginTable, name, members, toString, fromData, fromString));
	}
}

bool LuaPlugin::IsDatatype(const std::string& name)
{
	return std::find_if(s_pluginMap.begin(), s_pluginMap.end(), [&name](const auto& it)
		{
			const auto& datatypes = it.second->m_dataTypes;
			return datatypes.find(name) != datatypes.end();
		}) != s_pluginMap.end();
}

void LuaPlugin::UnregisterDatatypes()
{
	m_dataTypes.clear();
}

#pragma endregion

#pragma region TLOs

fMQData LuaPlugin::CreateData(sol::table plugin, sol::function func, int numargs)
{
	auto ret_func = [&plugin, &func, numargs](const char* Index, MQTypeVar& Dest) -> bool
	{
		auto result = numargs == 1 ? func(Index) : func(plugin, Index);
		if (result.valid() && result.return_count() > 1)
		{
			std::tuple<std::optional<std::string>, sol::object> r = result;
			auto& [typeName, typeValue] = r;
			if (typeName && typeValue != sol::lua_nil)
			{
				MQ2Type* type = FindMQ2DataType(typeName->c_str());
				Dest.Type = type;
				return EvaluateObject(type, typeValue, Dest);
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
	}
}

void LuaPlugin::AddData()
{
	for (auto it = m_dataTLOs.begin(); it != m_dataTLOs.end();)
	{
		const auto& [tlo, func] = *it;
		auto [_1, _2, numargs, vararg] = GetArgInfo(m_pluginTable, func);

		if (vararg)
		{
			LuaError("Invalid TLO %s: TLOs do not support variadic arguments.", tlo.c_str());
			it = m_dataTLOs.erase(it);
		}
		else if (numargs != 1 && numargs != 2)
		{
			LuaError("Invalid number of arguments (%d) for TLO %s", numargs, tlo.c_str());
			it = m_dataTLOs.erase(it);
		}
		else
		{
			AddMQ2Data(tlo.c_str(), CreateData(m_pluginTable, func, numargs));
			++it;
		}
	}
}

void LuaPlugin::UnregisterData()
{
	for (const auto& [tlo, _] : m_dataTLOs)
	{
		RemoveMQ2Data(tlo.c_str());
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

sol::object LuaPlugin::Get(sol::object key, sol::this_state s) const
{
	// this is not a very efficient indexer, but the only way to index this userdata
	// is via a require, and we are forced to call into C and then do state copies
	// of the result into the state that called this index

	// this will handle primitive type conversions, but if m_pluginTable is indexed by a table or userdata,
	// then we can't possibly get the value from the local table with a remote key, so this will fail
	// inside lua.
	auto local_key = CopyObject(key, m_pluginTable.lua_state());
	sol::object local_obj = m_pluginTable[local_key];

	// now that we have a local object, we need to copy it into the target state s
	return CopyObject(local_obj, s.lua_state());
}

// the first argument here is the self argument, which will always be the mq.plugin table
sol::table LuaPlugin::Create(sol::table, const std::string& name, const std::string& version, sol::this_state s)
{
	auto ptr = std::make_shared<LuaPlugin>(name, version, s);
	ptr->m_pluginTable = sol::state_view(s).create_table_with(
		"__plugin", ptr,
		"bindcommand", [](sol::table self, const std::string& command, sol::function func)
			{ self.get<std::shared_ptr<LuaPlugin>>("__plugin")->RegisterCommand(command, func); },
		"bindtype", [](sol::table self, const std::string& name, sol::table datatype)
			{ self.get<std::shared_ptr<LuaPlugin>>("__plugin")->RegisterDatatype(name, datatype); },
		"bindtlo", [](sol::table self, const std::string& name, sol::function func)
			{ self.get<std::shared_ptr<LuaPlugin>>("__plugin")->RegisterData(name, func); },
		"name", ptr->m_name,
		"version", ptr->m_version
	);

	sol::function arginfo = sol::state_view(s).script(R"(
		return function(f)
			local info = debug.getinfo(f, "nu")
			return info.name or 'unknown', info.namewhat or 'unk', info.nparams or -1, info.isvararg or false
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
				ptr->SetCallback(k.as<const std::string&>(), v, plugin.lua_state());
		}

		ptr->InitializePlugin();
		ptr->AddCommands();
		ptr->AddData();
		s_pluginMap.insert_or_assign(ptr->Name(), ptr);

		// we no longer need to hold the pointer to the LuaPlugin, and if we don't get rid of it, we'll always have one ref
		// which will cause the state to hold pointer which in turn is held by the LuaPlugin, need to make sure to get rid
		// of this circular dependency
		plugin["__plugin"] = sol::nil;

		// force gc in case we assigned instead of inserted to prevent dual definitions
		sol::state_view(plugin.lua_state()).collect_garbage(); 
	}
}

void LuaPlugin::Stop(std::string_view name)
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

std::shared_ptr<LuaPlugin> LuaPlugin::Lookup(std::string_view name)
{
	auto it = s_pluginMap.find(name);
	if (it != s_pluginMap.end())
	{
		return it->second;
	}

	return {};
}

bool LuaPlugin::IsRunning(std::string_view name)
{
	return s_pluginMap.find(name) != s_pluginMap.end();
}

std::vector<std::string_view> LuaPlugin::GetRunning()
{
	std::vector<std::string_view> keys(s_pluginMap.size());
	std::transform(s_pluginMap.begin(), s_pluginMap.end(), keys.begin(), [](const auto& pair) { return pair.first; });
	return keys;
}

void LuaPlugin::RegisterLua(sol::table& mq)
{
	sol::usertype<LuaPlugin> plugin = mq.new_usertype<LuaPlugin>(
		"__plugin",
		sol::meta_function::construct, sol::no_constructor,
		sol::meta_function::index, &LuaPlugin::Get
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
