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
	// Try our best to copy things into another state. We can't generically handle everything,
	// especially things like functions. But if we have the same state, just return the object
	// back, which will allow us to call functions from outside our state, as long as we don't
	// attempt to copy the object into a local state first.
	if (object.lua_state() == state)
		return object;

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

	type->InitVariable(Dest);
	return type->FromString(Dest, val_str);
}

#pragma endregion

#pragma region Type Helper

void MQ2LuaGenericType::FillMembers(sol::table members)
{
	auto id = 0;
	for (const auto& [key, value] : members)
	{
		auto maybe_name = key.as<std::optional<std::string>>();
		auto maybe_func = value.as<std::optional<sol::function>>();
		if (maybe_name && maybe_func)
		{
			auto [_1, _2, numargs, vararg] = GetArgInfo(m_pluginTable, *maybe_func);

			if (vararg)
			{
				LuaError("Invalid member function %s: functions do not support variadic arguments.", maybe_name->c_str());
			}
			else if (numargs != 2 && numargs != 3)
			{
				LuaError("Invalid number of arguments (%d) for member function %s", numargs, maybe_name->c_str());
			}
			else
			{
				m_memberMap[*maybe_name] = [func = std::move(*maybe_func), this, numargs = numargs](MQVarPtr VarPtr, char* Index, MQTypeVar& Dest)
				{
					auto ptr = VarPtr.Get<sol::object>();
					if (ptr)
					{
						auto result = numargs == 2 ? func(*ptr, Index) : func(m_pluginTable, *ptr, Index);
						if (result.valid() && result.return_count() > 1)
						{
							auto& [typeName, typeValue] = result.get<std::tuple<std::optional<std::string>, sol::object>>();
							if (typeName && typeValue != sol::lua_nil)
							{
								MQ2Type* type = FindMQ2DataType(typeName->c_str());
								Dest.Type = type;
								return EvaluateObject(type, typeValue, Dest);
							}
						}
					}

					return false;
				};

				AddMember(id++, maybe_name->c_str());
			}
		}
	}
}

void MQ2LuaGenericType::FillMethods(sol::table methods)
{
	auto id = 0;
	for (const auto& [key, value] : methods)
	{
		auto maybe_name = key.as<std::optional<std::string>>();
		auto maybe_func = value.as<std::optional<sol::function>>();
		if (maybe_name && maybe_func)
		{
			auto [_1, _2, numargs, vararg] = GetArgInfo(m_pluginTable, *maybe_func);

			if (vararg)
			{
				LuaError("Invalid method function %s: functions do not support variadic arguments.", maybe_name->c_str());
			}
			else if (numargs != 2 && numargs != 3)
			{
				LuaError("Invalid number of arguments (%d) for method function %s", numargs, maybe_name->c_str());
			}
			else
			{
				m_methodMap[*maybe_name] = [func = std::move(*maybe_func), this, numargs = numargs](MQVarPtr VarPtr, char* Index)
				{
					auto ptr = VarPtr.Get<sol::object>();
					if (ptr)
					{
						auto result = numargs == 2 ? func(*ptr, Index) : func(m_pluginTable, *ptr, Index);
						return result.valid();
					}

					return false;
				};

				AddMethod(id++, maybe_name->c_str());
			}
		}
	}
}

void MQ2LuaGenericType::SetToString(sol::function toString)
{
	auto [_1, _2, numargs, vararg] = GetArgInfo(m_pluginTable, toString);

	if (vararg)
	{
		LuaError("Invalid ToString definition: functions do not support variadic arguments.");
	}
	else if (numargs != 1 && numargs != 2)
	{
		LuaError("Invalid number of arguments (%d) for ToString definition", numargs);
	}
	else
	{
		m_toString = [func = std::move(toString), this, numargs = numargs](MQVarPtr VarPtr, char* Destination)
		{
			auto ptr = VarPtr.Get<sol::object>();
			if (ptr)
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

			return false;
		};
	}
}

void MQ2LuaGenericType::SetFromData(sol::function fromData)
{
	auto [_1, _2, numargs, vararg] = GetArgInfo(m_pluginTable, fromData);

	if (vararg)
	{
		LuaError("Invalid ToString definition: functions do not support variadic arguments.");
	}
	else if (numargs != 1 && numargs != 2)
	{
		LuaError("Invalid number of arguments (%d) for ToString definition", numargs);
	}
	else
	{
		m_fromData = [func = std::move(fromData), this, numargs = numargs](MQVarPtr& VarPtr, const MQTypeVar& Source)
		{
			if (Source.Type != nullptr && LuaPlugin::IsDatatype(Source.Type->GetName()))
			{
				auto ptr = Source.Get<sol::object>();
				if (ptr)
				{
					// we need to make sure to do this because we can't be sure the lua state is the same as
					// the local lua state, we need to serde
					sol::object val = CopyObject(*ptr, GetState());
					auto result = numargs == 1 ? func(val) : func(m_pluginTable, val);
					if (result.valid() && result.return_count() > 0)
					{
						sol::object r = result;
						if (r != sol::lua_nil)
						{
							// we can directly set this here because the act of copying the source
							// object into this state means that the result will be in this state
							VarPtr.Set(r);
							return true;
						}
					}
				}
			}

			return false;
		};
	}
}

void MQ2LuaGenericType::SetFromString(sol::function fromString)
{
	auto [_1, _2, numargs, vararg] = GetArgInfo(m_pluginTable, fromString);

	if (vararg)
	{
		LuaError("Invalid ToString definition: functions do not support variadic arguments.");
	}
	else if (numargs != 1 && numargs != 2)
	{
		LuaError("Invalid number of arguments (%d) for ToString definition", numargs);
	}
	else
	{
		m_fromString = [func = std::move(fromString), this, numargs = numargs](MQVarPtr& VarPtr, const char* Source)
		{
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
		};
	}
}

MQ2LuaGenericType::MQ2LuaGenericType(sol::table plugin, const std::string& typeName, sol::table datatype)
	: m_pluginTable(plugin)
	, m_typeName(typeName)
	, MQ2Type(typeName.c_str())
{
	for (auto& [k, v] : datatype)
	{
		auto key = k.as<std::optional<std::string_view>>();
		if (key)
		{
			if (ci_equals(*key, "Members") && v.is<sol::table>())
				FillMembers(v.as<sol::table>());
			else if (ci_equals(*key, "Methods") && v.is<sol::table>())
				FillMethods(v.as<sol::table>());
			else if (ci_equals(*key, "ToString") && v.is<sol::function>())
				SetToString(v.as<sol::function>());
			else if (ci_equals(*key, "FromData") && v.is<sol::function>())
				SetFromData(v.as<sol::function>());
			else if (ci_equals(*key, "FromString") && v.is<sol::function>())
				SetFromString(v.as<sol::function>());
		}
	}
}

bool MQ2LuaGenericType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	auto method_it = m_methodMap.find(Member);
	if (method_it != m_methodMap.end())
	{
		return method_it->second(VarPtr, Index);
	}

	auto member_it = m_memberMap.find(Member);
	if (member_it != m_memberMap.end())
	{
		return member_it->second(VarPtr, Index, Dest);
	}


	return false;
}

bool MQ2LuaGenericType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (m_toString)
	{
		return (*m_toString)(VarPtr, Destination);
	}

	strcpy_s(Destination, MAX_STRING, m_typeName.c_str());
	return true;
}

bool MQ2LuaGenericType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (m_fromData)
	{
		return (*m_fromData)(VarPtr, Source);
	}

	return false;
}

bool MQ2LuaGenericType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	if (m_fromString)
	{
		return (*m_fromString)(VarPtr, Source);
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
	if (val.is<sol::function>())
	{
		auto& func = val.as<sol::function>();
		if (name == "InitializePlugin")
		{
			auto& [n, f] = SetFunction(m_pluginTable, func, 0);
			if (n == 0)
				m_InitializePlugin = [f = f]() { f(); };
			else if (n == 1)
				m_InitializePlugin = [f = f, this]() { f(m_pluginTable); };
		}
		else if (name == "ShutdownPlugin")
		{
			auto& [n, f] = SetFunction(m_pluginTable, func, 0);
			if (n == 0)
				m_ShutdownPlugin = [f = f]() { f(); };
			else if (n == 1)
				m_ShutdownPlugin = [f = f, this]() { f(m_pluginTable); };
		}
		else if (name == "OnCleanUI")
		{
			auto& [n, f] = SetFunction(m_pluginTable, func, 0);
			if (n == 0)
				m_OnCleanUI = [f = f]() { f(); };
			else if (n == 1)
				m_OnCleanUI = [f = f, this]() { f(m_pluginTable); };
		}
		else if (name == "OnReloadUI")
		{
			auto& [n, f] = SetFunction(m_pluginTable, func, 0);
			if (n == 0)
				m_OnReloadUI = [f = f]() { f(); };
			else if (n == 1)
				m_OnReloadUI = [f = f, this]() { f(m_pluginTable); };
		}
		else if (name == "OnDrawHUD")
		{
			auto& [n, f] = SetFunction(m_pluginTable, func, 0);
			if (n == 0)
				m_OnDrawHUD = [f = f]() { f(); };
			else if (n == 1)
				m_OnDrawHUD = [f = f, this]() { f(m_pluginTable); };
		}
		else if (name == "SetGameState")
		{
			auto& [n, f] = SetFunction(m_pluginTable, func, 0);
			if (n == 0)
				m_SetGameState = [f = f](int GameState) { f(GameState); };
			else if (n == 1)
				m_SetGameState = [f = f, this](int GameState) { f(m_pluginTable, GameState); };
		}
		else if (name == "OnPulse")
		{
			auto& [n, f] = SetFunction(m_pluginTable, func, 0);
			if (n == 0)
				m_OnPulse = [f = f]() { f(); };
			else if (n == 1)
				m_OnPulse = [f = f, this]() { f(m_pluginTable); };
		}
		else if (name == "OnWriteChatColor")
		{
			auto& [n, f] = SetFunction(m_pluginTable, func, 0);
			if (n == 0)
				m_OnWriteChatColor = [f = f](const char* Line, int Color, int Filter) { f(Line, Color, Filter); };
			else if (n == 1)
				m_OnWriteChatColor = [f = f, this](const char* Line, int Color, int Filter) { f(m_pluginTable, Line, Color, Filter); };
		}
		else if (name == "OnIncomingChat")
		{
			auto& [n, f] = SetFunction(m_pluginTable, func, 0);
			if (n == 0)
				m_OnIncomingChat = [f = f](const char* Line, unsigned long Color)
				{
					std::optional<bool> ret = f(Line, Color);
					return ret ? *ret : false;
				};
			else if (n == 1)
				m_OnIncomingChat = [f = f, this](const char* Line, unsigned long Color)
				{
					std::optional<bool> ret = f(m_pluginTable, Line, Color);
					return ret ? *ret : false;
				};
		}
		else if (name == "OnAddSpawn")
		{
			auto& [n, f] = SetFunction(m_pluginTable, func, 0);
			if (n == 0)
				m_OnAddSpawn = [f = f](PlayerClient* pNewSpawn) { pNewSpawn == nullptr ? f() : f(pNewSpawn->SpawnID); };
			else if (n == 1)
				m_OnAddSpawn = [f = f, this](PlayerClient* pNewSpawn) { pNewSpawn == nullptr ? f(m_pluginTable) : f(m_pluginTable, pNewSpawn->SpawnID); };
		}
		else if (name == "OnRemoveSpawn")
		{
			auto& [n, f] = SetFunction(m_pluginTable, func, 0);
			if (n == 0)
				m_OnRemoveSpawn = [f = f](PlayerClient* pSpawn) { pSpawn == nullptr ? f() : f(pSpawn->SpawnID); };
			else if (n == 1)
				m_OnRemoveSpawn = [f = f, this](PlayerClient* pSpawn) { pSpawn == nullptr ? f(m_pluginTable) : f(m_pluginTable, pSpawn->SpawnID); };
		}
		else if (name == "OnAddGroundItem")
		{
			auto& [n, f] = SetFunction(m_pluginTable, func, 0);
			if (n == 0)
				m_OnAddGroundItem = [f = f](EQGroundItem* pNewGroundItem) { pNewGroundItem == nullptr ? f() : f(pNewGroundItem->DropID); };
			else if (n == 1)
				m_OnAddGroundItem = [f = f, this](EQGroundItem* pNewGroundItem) { pNewGroundItem == nullptr ? f(m_pluginTable) : f(m_pluginTable, pNewGroundItem->DropID); };
		}
		else if (name == "OnRemoveGroundItem")
		{
			auto& [n, f] = SetFunction(m_pluginTable, func, 0);
			if (n == 0)
				m_OnRemoveGroundItem = [f = f](EQGroundItem* pGroundItem) { pGroundItem == nullptr ? f() : f(pGroundItem->DropID); };
			else if (n == 1)
				m_OnRemoveGroundItem = [f = f, this](EQGroundItem* pGroundItem) { pGroundItem == nullptr ? f(m_pluginTable) : f(m_pluginTable, pGroundItem->DropID); };
		}
		else if (name == "OnBeginZone")
		{
			auto& [n, f] = SetFunction(m_pluginTable, func, 0);
			if (n == 0)
				m_OnBeginZone = [f = f]() { f(); };
			else if (n == 1)
				m_OnBeginZone = [f = f, this]() { f(m_pluginTable); };
		}
		else if (name == "OnEndZone")
		{
			auto& [n, f] = SetFunction(m_pluginTable, func, 0);
			if (n == 0)
				m_OnEndZone = [f = f]() { f(); };
			else if (n == 1)
				m_OnEndZone = [f = f, this]() { f(m_pluginTable); };
		}
		else if (name == "OnZoned")
		{
			auto& [n, f] = SetFunction(m_pluginTable, func, 0);
			if (n == 0)
				m_OnZoned = [f = f]() { f(); };
			else if (n == 1)
				m_OnZoned = [f = f, this]() { f(m_pluginTable); };
		}
		else if (name == "OnUpdateImGui")
		{
			auto& [n, f] = SetFunction(m_pluginTable, func, 0);
			if (n == 0)
				m_OnUpdateImGui = [f = f]() { f(); };
			else if (n == 1)
				m_OnUpdateImGui = [f = f, this]() { f(m_pluginTable); };
		}
		else if (name == "OnMacroStart")
		{
			auto& [n, f] = SetFunction(m_pluginTable, func, 0);
			if (n == 0)
				m_OnMacroStart = [f = f](const char* Name) { f(Name); };
			else if (n == 1)
				m_OnMacroStart = [f = f, this](const char* Name) { f(m_pluginTable, Name); };
		}
		else if (name == "OnMacroStop")
		{
			auto& [n, f] = SetFunction(m_pluginTable, func, 0);
			if (n == 0)
				m_OnMacroStop = [f = f](const char* Name) { f(Name); };
			else if (n == 1)
				m_OnMacroStop = [f = f, this](const char* Name) { f(m_pluginTable, Name); };
		}
		else if (name == "OnLoadPlugin")
		{
			auto& [n, f] = SetFunction(m_pluginTable, func, 0);
			if (n == 0)
				m_OnLoadPlugin = [f = f](const char* Name) { f(Name); };
			else if (n == 1)
				m_OnLoadPlugin = [f = f, this](const char* Name) { f(m_pluginTable, Name); };
		}
		else if (name == "OnUnloadPlugin")
		{
			auto& [n, f] = SetFunction(m_pluginTable, func, 0);
			if (n == 0)
				m_OnUnloadPlugin = [f = f](const char* Name) { f(Name); };
			else if (n == 1)
				m_OnUnloadPlugin = [f = f, this](const char* Name) { f(m_pluginTable, Name); };
		}
	}
}

void LuaPlugin::InitializePlugin()
{
	if (m_InitializePlugin) (*m_InitializePlugin)();
}

void LuaPlugin::ShutdownPlugin()
{
	if (m_ShutdownPlugin) (*m_ShutdownPlugin)();
}

void LuaPlugin::OnCleanUI()
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnCleanUI)
			(*plugin->m_OnCleanUI)();
}

void LuaPlugin::OnReloadUI()
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnReloadUI)
			(*plugin->m_OnReloadUI)();
}

void LuaPlugin::OnDrawHUD()
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnDrawHUD)
			(*plugin->m_OnDrawHUD)();
}

void LuaPlugin::SetGameState(int GameState)
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_SetGameState)
			(*plugin->m_SetGameState)(GameState);
}

void LuaPlugin::OnPulse()
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnPulse)
			(*plugin->m_OnPulse)();
}

void LuaPlugin::OnWriteChatColor(const char* Line, int Color, int Filter)
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnWriteChatColor)
			(*plugin->m_OnWriteChatColor)(Line, Color, Filter);
}

bool LuaPlugin::OnIncomingChat(const char* Line, unsigned long Color)
{
	return std::accumulate(s_pluginMap.begin(), s_pluginMap.end(), false,
		[&Line, &Color](bool acc, const auto& pair)
		{
			const auto& plugin = pair.second;
			if (plugin->m_OnIncomingChat)
			{
				return (*plugin->m_OnIncomingChat)(Line, Color) || acc;
			}

			return acc;
		});
}

void LuaPlugin::OnAddSpawn(PlayerClient* pNewSpawn)
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnAddSpawn && pNewSpawn != nullptr)
			(*plugin->m_OnAddSpawn)(pNewSpawn); // TODO: spawns could be userdata
}

void LuaPlugin::OnRemoveSpawn(PlayerClient* pSpawn)
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnRemoveSpawn && pSpawn != nullptr)
			(*plugin->m_OnRemoveSpawn)(pSpawn); // TODO: spawns could be userdata
}

void LuaPlugin::OnAddGroundItem(EQGroundItem* pNewGroundItem)
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnAddGroundItem && pNewGroundItem != nullptr && pNewGroundItem->Item)
			(*plugin->m_OnAddGroundItem)(pNewGroundItem); // TODO: needs to be userdata
}

void LuaPlugin::OnRemoveGroundItem(EQGroundItem* pGroundItem)
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnRemoveGroundItem && pGroundItem != nullptr && pGroundItem->Item)
			(*plugin->m_OnRemoveGroundItem)(pGroundItem); // TODO: needs to be userdata
}

void LuaPlugin::OnBeginZone()
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnBeginZone)
			(*plugin->m_OnBeginZone)();
}

void LuaPlugin::OnEndZone()
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnEndZone)
			(*plugin->m_OnEndZone)();
}

void LuaPlugin::OnZoned()
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnZoned)
			(*plugin->m_OnZoned)();
}

void LuaPlugin::OnUpdateImGui()
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnUpdateImGui)
			(*plugin->m_OnUpdateImGui)();
}

void LuaPlugin::OnMacroStart(const char* Name)
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnMacroStart)
			(*plugin->m_OnMacroStart)(Name);
}

void LuaPlugin::OnMacroStop(const char* Name)
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnMacroStop)
			(*plugin->m_OnMacroStop)(Name);
}

void LuaPlugin::OnLoadPlugin(const char* Name)
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnLoadPlugin)
			(*plugin->m_OnLoadPlugin)(Name);
}

void LuaPlugin::OnUnloadPlugin(const char* Name)
{
	for (const auto& [_, plugin] : s_pluginMap)
		if (plugin->m_OnUnloadPlugin)
			(*plugin->m_OnUnloadPlugin)(Name);
}

#pragma endregion

#pragma region Commands

void LuaPlugin::RegisterCommand(const std::string& name, sol::function func)
{
	m_commands[name] = func;
}

void LuaPlugin::AddCommands()
{
	for (auto it = m_commands.begin(); it != m_commands.end();)
	{
		const auto& [command, func] = *it;
		auto [_1, _2, numargs, vararg] = GetArgInfo(m_pluginTable, func);

		if (IsCommand(command.c_str()))
		{
			LuaError("Cannot create command %s, already a command in MQ.", command.c_str());
			it = m_commands.erase(it);
		}
		else if (command.empty() || command[0] != '/')
		{
			LuaError("Cannot create command %s, not a valid command string.", command.c_str());
			it = m_commands.erase(it);
		}
		else if (vararg)
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
	m_dataTypeDefs[name] = datatype;
}

void LuaPlugin::AddDatatypes()
{
	for (auto it = m_dataTypeDefs.begin(); it != m_dataTypeDefs.end();)
	{
		const auto& [type, datatype] = *it;
		if (FindMQ2DataType(type.c_str()) != nullptr)
		{
			LuaError("Cannot create datatype %s, already a datatype in MQ.", type.c_str());
			it = m_dataTypeDefs.erase(it);
		}
		else if (type.empty())
		{
			LuaError("Cannot create datatype %s, not a valid name.", type.c_str());
			it = m_dataTypeDefs.erase(it);
		}
		else
		{
			m_dataTypes.emplace(type, std::make_unique<MQ2LuaGenericType>(m_pluginTable, type, datatype));
			++it;
		}
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
	m_dataTypeDefs.clear();
	m_dataTypes.clear();
}

#pragma endregion

#pragma region TLOs

static bool CheckDataResult(sol::function_result& result, MQTypeVar& Dest)
{
	if (result.valid() && result.return_count() > 1)
	{
		auto& [typeName, typeValue] = result.get<std::tuple<std::optional<std::string>, sol::object>>();
		if (typeName && typeValue != sol::lua_nil)
		{
			MQ2Type* type = FindMQ2DataType(typeName->c_str());
			Dest.Type = type;
			return EvaluateObject(type, typeValue, Dest);
		}
	}

	return false;
}

void LuaPlugin::RegisterData(const std::string& name, sol::function func)
{
	m_dataTLOs[name] = func;
}

void LuaPlugin::AddData()
{
	for (auto it = m_dataTLOs.begin(); it != m_dataTLOs.end();)
	{
		const auto& [tlo, func] = *it;
		auto [_1, _2, numargs, vararg] = GetArgInfo(m_pluginTable, func);

		if (FindMQ2Data(tlo.c_str()) != nullptr)
		{
			LuaError("Cannot create TLO %s, already a TLO in MQ.", tlo.c_str());
			it = m_dataTLOs.erase(it);
		}
		else if (tlo.empty())
		{
			LuaError("Cannot create TLO %s, not a valid name.", tlo.c_str());
			it = m_dataTLOs.erase(it);
		}
		else if (vararg)
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
			AddMQ2DataFunction(tlo.c_str(), [func = func, this, numargs = numargs](const char* Index, MQTypeVar& Dest)
				{
					auto result = numargs == 1 ? func(Index) : func(m_pluginTable, Index);
					return CheckDataResult(result, Dest);
				});
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
	m_InitializePlugin = std::nullopt;
	m_ShutdownPlugin = std::nullopt;
	m_OnCleanUI = std::nullopt;
	m_OnReloadUI = std::nullopt;
	m_OnDrawHUD = std::nullopt;
	m_SetGameState = std::nullopt;
	m_OnPulse = std::nullopt;
	m_OnWriteChatColor = std::nullopt;
	m_OnIncomingChat = std::nullopt;
	m_OnAddSpawn = std::nullopt;
	m_OnRemoveSpawn = std::nullopt;
	m_OnAddGroundItem = std::nullopt;
	m_OnRemoveGroundItem = std::nullopt;
	m_OnBeginZone = std::nullopt;
	m_OnEndZone = std::nullopt;
	m_OnZoned = std::nullopt;
	m_OnUpdateImGui = std::nullopt;
	m_OnMacroStart = std::nullopt;
	m_OnMacroStop = std::nullopt;
	m_OnLoadPlugin = std::nullopt;
	m_OnUnloadPlugin = std::nullopt;

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
		"registercommand", [](sol::table self, const std::string& command, sol::function func)
			{ self.get<std::shared_ptr<LuaPlugin>>("__plugin")->RegisterCommand(command, func); },
		"registertype", [](sol::table self, const std::string& name, sol::table datatype)
			{ self.get<std::shared_ptr<LuaPlugin>>("__plugin")->RegisterDatatype(name, datatype); },
		"registertlo", [](sol::table self, const std::string& name, sol::function func)
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
		if (IsRunning(ptr->Name()))
		{
			WriteChatStatus("Lua plugin %s is already running, not starting another instance.", ptr->Name().c_str());
		}
		else
		{
			WriteChatStatus("Starting lua plugin %s.", ptr->Name().c_str());
			for (const auto& [k, v] : plugin)
			{
				if (k.is<std::string>() && v.get_type() == sol::type::function)
					ptr->SetCallback(k.as<const std::string&>(), v, plugin.lua_state());
			}

			ptr->InitializePlugin();
			ptr->AddCommands();
			ptr->AddDatatypes();
			ptr->AddData();
			ptr->m_startTime = std::chrono::system_clock::now();
			s_pluginMap.insert_or_assign(ptr->Name(), ptr);
		}

		// we no longer need to hold the pointer to the LuaPlugin, and if we don't get rid of it, we'll always have one ref
		// which will cause the state to hold pointer which in turn is held by the LuaPlugin, need to make sure to get rid
		// of this circular dependency
		// do this even if we don't start the plugin to ensure that we don't leak memory
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
		if (it->second) it->second->ShutdownPlugin();
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

std::vector<std::shared_ptr<LuaPlugin>> LuaPlugin::GetRunning()
{
	std::vector<std::shared_ptr<LuaPlugin>> values(s_pluginMap.size());
	std::transform(s_pluginMap.begin(), s_pluginMap.end(), values.begin(), [](const auto& pair) { return pair.second; });
	return values;
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
