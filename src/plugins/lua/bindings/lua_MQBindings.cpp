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
#include "lua_MQBindings.h"

#include "LuaCommon.h"
#include "LuaThread.h"

#include <mq/Plugin.h>

namespace mq::lua {

std::string lua_join(sol::this_state L, std::string_view delim, sol::variadic_args va)
{
	if (va.size() > 0)
	{
		fmt::memory_buffer str;
		std::string_view del;
		for (const auto& arg : va)
		{
			auto value = luaL_tolstring(arg.lua_state(), arg.stack_index(), nullptr);
			if (value != nullptr && strlen(value) > 0)
			{
				fmt::format_to(fmt::appender(str), "{}{}", del, value);
				del = delim;
			}
		}

		return fmt::to_string(str);
	}

	return "";
}

//============================================================================

#pragma region Command Bindings

void ExecuteCommand(const std::string& cmdString, sol::this_state s)
{
	bool delayed = false;
	std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s);
	if (thread_ptr && !thread_ptr->GetAllowYield())
		delayed = true;

	HideDoCommand(pLocalPlayer, cmdString.c_str(), delayed);

	if (thread_ptr && thread_ptr->GetAllowYield() && !bRunNextCommand)
		thread_ptr->DoYield();
}

struct lua_MQCommand
{
	std::string command;

	lua_MQCommand(std::string_view command)
		: command(command)
	{
	}

	void operator()(sol::variadic_args va, sol::this_state s)
	{
		fmt::memory_buffer cmd;
		fmt::format_to(fmt::appender(cmd), "{}", command);

		for (const auto& a : va)
		{
			auto value = luaL_tolstring(a.lua_state(), a.stack_index(), nullptr);
			if (value != nullptr && strlen(value) > 0)
				fmt::format_to(fmt::appender(cmd), " {}", value);
		}

		ExecuteCommand(fmt::to_string(cmd).c_str(), s);
	}
};

struct lua_MQDoCommand
{
	// this is only used to provide a namespace for commands
	sol::object Get(sol::stack_object key, sol::this_state L) const
	{
		auto maybe_key = key.as<std::optional<std::string>>();
		if (maybe_key)
		{
			std::string cmd("/");
			cmd += *maybe_key;
			// do no validation. Any thing prefixed with `cmd` will be attempted to be submitted (they are pure side effect anyway)
			return sol::object(L, sol::in_place, lua_MQCommand(cmd));
		}

		return sol::object(L, sol::in_place, sol::lua_nil);
	}

	static void command_format(sol::variadic_args va, sol::this_state s)
	{
		// replicate string.format
		sol::function string_format = sol::state_view(s)["string"]["format"];
		std::string command = string_format(va);

		ExecuteCommand(command, s);
	}

	static void command(sol::variadic_args va, sol::this_state s)
	{
		// replicate string.format
		std::string command = lua_join(s, " ", va);

		ExecuteCommand(command, s);
	}

	// Provide direct access to DoCommand
	void operator()(sol::variadic_args va, sol::this_state s)
	{
		command(va, s);
	}
};

#pragma endregion

#pragma region Macro Bindings

class lua_MQDataItem;

class lua_MQTypeVar
{
	friend class lua_MQDataItem;

public:
	lua_MQTypeVar(const std::string& str)
	{
		auto* const type = FindMQ2DataType(str.c_str());
		if (type != nullptr)
		{
			m_self->Type = type;
		}
	}

	/**
	 * \brief wraps an MQ type var in a lua implementation
	 * \param self the MQ type var data source to be represented in lua
	 */
	lua_MQTypeVar(const MQTypeVar& self)
		: m_self(std::make_unique<MQTypeVar>(self)) {}

	bool operator==(const lua_MQTypeVar& right) const;
	bool EqualData(const lua_MQDataItem& right) const;
	bool EqualNil(const sol::lua_nil_t&) const;
	MQTypeVar EvaluateMember(const char* index = nullptr) const;
	static std::string ToString(const lua_MQTypeVar& obj);
	sol::object Call(std::string index, sol::this_state L) const;
	sol::object CallInt(int index, sol::this_state L) const;
	sol::object CallVA(sol::this_state L, sol::variadic_args args) const;
	sol::object CallEmpty(sol::this_state L) const;
	sol::object Get(sol::stack_object key, sol::this_state L) const;
	MQ2Type* GetType() const;

private:
	std::unique_ptr<MQTypeVar> m_self;
	std::string m_member;
};

bool lua_MQTypeVar::operator==(const lua_MQTypeVar& right) const
{
	return EvaluateMember() == right.EvaluateMember();
}

bool lua_MQTypeVar::EqualNil(const sol::lua_nil_t&) const
{
	if (!m_self || m_self->Type == nullptr)
		return true;

	return EvaluateMember().Type == nullptr;
}

MQTypeVar lua_MQTypeVar::EvaluateMember(const char* index) const
{
	if (m_self->Type == nullptr || m_member.empty())
		return *m_self;

	// the ternary in index is because datatypes are all over the place on whether or not they can
	// accept null pointers. They all seem to agree that an empty string is the same thing, though.
	MQTypeVar var;
	if (EvaluateMacroDataMember(m_self->Type, m_self->GetVarPtr(), var, m_member.c_str(), index ? index : "") == 1)
		return std::move(var);

	// can't guarantee result didn't Get modified, but we want to return nil if GetMember was false
	return MQTypeVar();
}

MQ2Type* lua_MQTypeVar::GetType() const
{
	return EvaluateMember().Type;
}

std::string lua_MQTypeVar::ToString(const lua_MQTypeVar& obj)
{
	MQTypeVar var = obj.EvaluateMember();

	if (var.Type != nullptr)
	{
		char buf[MAX_STRING] = { 0 };
		if (var.Type->ToString(var, buf))
			return std::string(buf);
	}

	return "NULL";
}

sol::object lua_MQTypeVar::Call(std::string index, sol::this_state L) const
{
	return sol::object(L, sol::in_place, lua_MQTypeVar(EvaluateMember(index.c_str())));
}

sol::object lua_MQTypeVar::CallInt(int index, sol::this_state L) const
{
	return Call(std::to_string(index), L);
}

sol::object lua_MQTypeVar::CallVA(sol::this_state L, sol::variadic_args args) const
{
	return Call(lua_join(L, ",", args), L);
}

static sol::table fill_extent(const std::shared_ptr<datatypes::CDataArray>& arr, int extent, int curr_index, sol::state_view s)
{
	int local_size = arr->GetExtents(extent);
	auto table = s.create_table(local_size);
	if (extent + 1 == arr->GetNumExtents())
	{
		// this is the final extent, we need to build values
		for (int index = 0; index < local_size; ++index)
		{
			MQTypeVar var;
			var.Type = arr->GetType();
			var.SetVarPtr(arr->GetData((curr_index * local_size) + index));
			table.add(lua_MQTypeVar(var));
		}
	}
	else
	{
		for (int index = 0; index < local_size; ++index)
			table.add(fill_extent(arr, extent + 1, index, s));
	}

	return table;
}

sol::object lua_MQTypeVar::CallEmpty(sol::this_state L) const
{
	MQTypeVar result = EvaluateMember();

	if (result.Type == nullptr)
		return sol::object(L, sol::in_place, sol::lua_nil);

	if (result.Type == mq::datatypes::pArrayType)
		return sol::object(L, sol::in_place, fill_extent(result.Get<datatypes::CDataArray>(), 0, 0, sol::state_view(L)));
	if (result.Type == mq::datatypes::pBoolType)
		return sol::object(L, sol::in_place, result.Get<bool>());
	if (result.Type == mq::datatypes::pIntType)
		return sol::object(L, sol::in_place, result.Get<int>());
	if (result.Type == mq::datatypes::pInt64Type)
		return sol::object(L, sol::in_place, result.Get<int64_t>());
	if (result.Type == mq::datatypes::pByteType)
		return sol::object(L, sol::in_place, result.Get<uint8_t>());
	if (result.Type == mq::datatypes::pFloatType)
		return sol::object(L, sol::in_place, result.Get<float>());
	if (result.Type == mq::datatypes::pDoubleType)
		return sol::object(L, sol::in_place, result.Get<double>());
	if (result.Type == mq::datatypes::pStringType)
		return sol::object(L, sol::in_place, (const char*)result.Ptr);
	if (result.Type == mq::datatypes::pTimeStampType)
		return sol::object(L, sol::in_place, result.Get<int64_t>());

	// by default run it through the tostring conversion because we are assuming calling with empty parens means
	// to actualize the data in the native lua space
	char buf[MAX_STRING] = { 0 };
	if (result.Type->ToString(result.GetVarPtr(), buf))
		return sol::object(L, sol::in_place, buf);

	return sol::object(L, sol::in_place, sol::lua_nil);
}

sol::object lua_MQTypeVar::Get(sol::stack_object key, sol::this_state L) const
{
	lua_MQTypeVar var = EvaluateMember();

	if (var.m_self->Type && var.m_self->Type == datatypes::pArrayType)
	{
		auto arr = var.m_self->Get<datatypes::CDataArray>();
		if (auto maybe_index = key.as<std::optional<int>>())
		{
			// we have an integer -- let's just assume single extent for now
			// TODO: will need to keep track of extents to allow for access like this: arr[2][1]
			// would rather return an array with a subset, but that would require slicing and copying the underlying array data
			var.m_member = "";
			var.m_self->Type = arr->GetType();
			var.m_self->SetVarPtr(arr->GetData(*maybe_index));
		}
		else if (auto maybe_index = key.as<std::optional<std::string_view>>())
		{
			// we have a string, so we can use the array's internal string index parsing here
			if (!arr->GetElement(*maybe_index, *var.m_self))
			{
				return sol::object(L, sol::in_place, sol::lua_nil);
			}

			var.m_member = "";
		}
	}
	else if (auto maybe_key = key.as<std::optional<std::string_view>>())
	{
		// the nominal case is that the index is the key to the type member
		var.m_member = *maybe_key;

		// make sure the macro data member even exists if we have the type info
		if (var.m_self->Type && !FindMacroDataMember(var.m_self->Type, var.m_member))
		{
			return sol::object(L, sol::in_place, sol::lua_nil);
		}
	}

	return sol::object(L, sol::in_place, std::move(var));
}

//----------------------------------------------------------------------------

class lua_MQDataItem
{
public:
	lua_MQDataItem() = default;

	// this will allow users an alternate way to Get data items
	lua_MQDataItem(const std::string& str)
		: self(FindMQ2Data(str.c_str())) {}
	lua_MQDataItem(const MQDataItem* const self)
		: self(self) {}

	lua_MQTypeVar EvaluateSelf() const;
	bool operator==(const lua_MQDataItem& right) const;
	bool EqualVar(const lua_MQTypeVar& right) const;
	bool EqualNil(const sol::lua_nil_t&) const;

	static std::string ToString(const lua_MQDataItem& data);

	sol::object Call(const std::string& index, sol::this_state L) const;
	sol::object CallInt(int index, sol::this_state L) const;
	sol::object CallVA(sol::this_state L, sol::variadic_args args) const;
	sol::object CallEmpty(sol::this_state L) const;
	sol::object Get(sol::stack_object key, sol::this_state L) const;

	MQ2Type* GetType() const;

private:
	const MQDataItem* const self = nullptr;
};

lua_MQTypeVar lua_MQDataItem::EvaluateSelf() const
{
	MQTypeVar result;
	if (self != nullptr)
		self->Function("", result);

	return lua_MQTypeVar(result);
}

bool lua_MQDataItem::operator==(const lua_MQDataItem& right) const
{
	return EvaluateSelf() == right.EvaluateSelf();
}

bool lua_MQDataItem::EqualVar(const lua_MQTypeVar& right) const
{
	return EvaluateSelf() == right;
}

bool lua_MQDataItem::EqualNil(const sol::lua_nil_t&) const
{
	return EvaluateSelf().m_self->Type == nullptr;
}

std::string lua_MQDataItem::ToString(const lua_MQDataItem& data)
{
	return lua_MQTypeVar::ToString(data.EvaluateSelf());
}

MQ2Type* lua_MQDataItem::GetType() const
{
	return EvaluateSelf().m_self->Type;
}

sol::object lua_MQDataItem::Call(const std::string& index, sol::this_state L) const
{
	MQTypeVar result;
	if (self != nullptr && self->Function(index.c_str(), result))
		return sol::object(L, sol::in_place, lua_MQTypeVar(result));

	return sol::object(L, sol::in_place, lua_MQTypeVar(MQTypeVar()));
}

sol::object lua_MQDataItem::CallInt(int index, sol::this_state L) const
{
	return Call(std::to_string(index), L);
}

sol::object lua_MQDataItem::CallVA(sol::this_state L, sol::variadic_args args) const
{
	return Call(lua_join(L, ",", args), L);
}

sol::object lua_MQDataItem::CallEmpty(sol::this_state L) const
{
	MQTypeVar result;
	if (self != nullptr && self->Function("", result))
		return lua_MQTypeVar(result).CallEmpty(L);

	return sol::object(L, sol::in_place, sol::lua_nil);
}

sol::object lua_MQDataItem::Get(sol::stack_object key, sol::this_state L) const
{
	MQTypeVar result;
	if (self != nullptr && self->Function("", result))
		return lua_MQTypeVar(result).Get(key, L);

	return sol::object(L, sol::in_place, lua_MQTypeVar(MQTypeVar()));
}

template <typename Handler>
bool sol_lua_check(sol::types<lua_MQDataItem>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking)
{
	if (!sol::stack::check_usertype<lua_MQDataItem>(L, index) &&
		!sol::stack::check<sol::lua_nil_t>(L, index))
	{
		handler(L, index, sol::type_of(L, index), sol::type::userdata, "Expected an MQ type");
		return false;
	}
	tracking.use(1);
	return true;
}

lua_MQDataItem sol_lua_get(sol::types<lua_MQDataItem>, lua_State* L, int index, sol::stack::record& tracking)
{
	if (sol::stack::check_usertype<lua_MQDataItem>(L, index))
	{
		lua_MQDataItem& data = sol::stack::get_usertype<lua_MQDataItem>(L, index, tracking);
		return data;
	}

	return lua_MQDataItem();
}

bool lua_MQTypeVar::EqualData(const lua_MQDataItem& right) const
{
	return *this == right.EvaluateSelf();
}

//----------------------------------------------------------------------------

template <typename Handler>
bool sol_lua_check(sol::types<lua_MQTypeVar>, lua_State* L, int index, Handler&& handler, sol::stack::record& tracking)
{
	if (!sol::stack::check_usertype<lua_MQTypeVar>(L, index) &&
		!sol::stack::check_usertype<lua_MQDataItem>(L, index) &&
		!sol::stack::check<sol::lua_nil_t>(L, index))
	{
		handler(L, index, sol::type_of(L, index), sol::type::userdata, "Expected an MQ type");
		return false;
	}
	tracking.use(1);
	return true;
}

lua_MQTypeVar sol_lua_get(sol::types<lua_MQTypeVar>, lua_State* L, int index, sol::stack::record& tracking)
{
	if (sol::stack::check_usertype<lua_MQTypeVar>(L, index))
	{
		lua_MQTypeVar& var = sol::stack::get_usertype<lua_MQTypeVar>(L, index, tracking);
		return lua_MQTypeVar(var.EvaluateMember());
	}

	if (sol::stack::check_usertype<lua_MQDataItem>(L, index))
	{
		lua_MQDataItem& data = sol::stack::get_usertype<lua_MQDataItem>(L, index, tracking);
		return data.EvaluateSelf();
	}

	return lua_MQTypeVar(MQTypeVar()); // this will eventually evaluate to a nil, but we need it to stay in userdata until actual evaluation
}

struct lua_MQTLO
{
	sol::object Get(sol::stack_object key, sol::this_state L) const
	{
		auto maybe_key = key.as<std::optional<std::string>>();
		if (maybe_key)
		{
			MQDataItem* result = FindMQ2Data(maybe_key->c_str());
			if (result != nullptr)
				return sol::object(L, sol::in_place, lua_MQDataItem(result));
		}

		return sol::object(L, sol::in_place, sol::lua_nil);
	}
};

std::string to_string(const lua_MQDataItem& item)
{
	return lua_MQDataItem::ToString(item);
}

std::string to_string(const lua_MQTypeVar& item)
{
	return lua_MQTypeVar::ToString(item);
}

std::string to_string(const lua_MQTLO& item)
{
	return "TLO";
}

std::optional<std::string> mq_gettype_MQDataItem(const lua_MQDataItem& item)
{
	MQ2Type* type = item.GetType();
	if (!type)
		return std::nullopt;

	return std::string(type->GetName());
}

std::optional<std::string> mq_gettype_MQTypeVar(const lua_MQTypeVar& item)
{
	MQ2Type* type = item.GetType();
	if (!type)
		return std::nullopt;

	return std::string(type->GetName());
}

#pragma endregion

//============================================================================

static std::string lua_Parse(const char* text)
{
	char buffer[MAX_STRING] = { 0 };
	strncpy_s(buffer, text, sizeof(buffer));
	auto old_parser = std::exchange(gParserVersion, 2);
	ParseMacroData(buffer, sizeof(buffer));
	gParserVersion = old_parser;
	return buffer;
}

//============================================================================

static std::unique_ptr<CTextureAnimation> FindTextureAnimation(std::string_view name, sol::this_state s)
{
	auto anim = std::make_unique<CTextureAnimation>();

	if (pSidlMgr)
	{
		if (CTextureAnimation* temp = pSidlMgr->FindAnimation(CXStr(name)))
			*anim = *temp;
	}

	return anim;
}

//============================================================================

#pragma region MQ Data Bindings

static sol::table lua_getAllSpawns(sol::this_state L)
{
	auto table = sol::state_view(L).create_table();

	if (pSpawnManager)
	{
		auto spawn = pSpawnManager->FirstSpawn;
		while (spawn != nullptr)
		{
			auto lua_spawn = lua_MQTypeVar(datatypes::pSpawnType->MakeTypeVar(spawn));
			table.add(std::move(lua_spawn));

			spawn = spawn->GetNext();
		}
	}

	return table;
}

static sol::table lua_getFilteredSpawns(sol::this_state L, std::optional<sol::function> predicate)
{
	auto table = sol::state_view(L).create_table();

	if (pSpawnManager && predicate)
	{
		auto spawn = pSpawnManager->FirstSpawn;
		const auto& predicate_value = predicate.value();
		while (spawn != nullptr)
		{
			auto lua_spawn = lua_MQTypeVar(datatypes::pSpawnType->MakeTypeVar(spawn));
			if (predicate_value(lua_spawn))
				table.add(std::move(lua_spawn));

			spawn = spawn->GetNext();
		}
	}

	return table;
}

#pragma endregion

//============================================================================

void MQ_RegisterLua_MQBindings(sol::table& mq)
{
	mq.set("configDir",                          gPathConfig);
	mq.set_function("join",                      &lua_join);

	//----------------------------------------------------------------------------
	// command bindings

	mq.new_usertype<lua_MQCommand>(
		"command",                               sol::no_constructor);
	mq.new_usertype<lua_MQDoCommand>(
		"docommand",                             sol::no_constructor,
		sol::meta_function::index,               &lua_MQDoCommand::Get);

	mq.set("cmd",                                lua_MQDoCommand());
	mq.set_function("cmdf",                      &lua_MQDoCommand::command_format);

	//----------------------------------------------------------------------------
	// Macro bindings


	mq.new_usertype<lua_MQTypeVar>(
		"type",                                  sol::constructors<
		                                             lua_MQTypeVar(const std::string&)>(),
		sol::meta_function::call,                sol::overload(
			                                         &lua_MQTypeVar::Call,
			                                         &lua_MQTypeVar::CallInt,
			                                         &lua_MQTypeVar::CallEmpty,
			                                         &lua_MQTypeVar::CallVA),
		sol::meta_function::index,               &lua_MQTypeVar::Get,
		sol::meta_function::equal_to,            sol::overload(
			                                         &lua_MQTypeVar::operator==,
			                                         &lua_MQTypeVar::EqualData,
			                                         &lua_MQTypeVar::EqualNil));

	mq.new_usertype<lua_MQDataItem>(
		"data",                                  sol::constructors<
		                                             lua_MQDataItem(const std::string&)>(),
		sol::meta_function::call,                sol::overload(
			                                         &lua_MQDataItem::Call,
			                                         &lua_MQDataItem::CallInt,
			                                         &lua_MQDataItem::CallEmpty,
			                                         &lua_MQDataItem::CallVA),
		sol::meta_function::index,               &lua_MQDataItem::Get,
		sol::meta_function::equal_to,            sol::overload(
			                                         &lua_MQDataItem::operator==,
			                                         &lua_MQDataItem::EqualVar,
			                                         &lua_MQDataItem::EqualNil));

	mq.new_usertype<lua_MQTLO>(
		"tlo",                                   sol::no_constructor,
		sol::meta_function::index,               &lua_MQTLO::Get);
	mq.set("TLO",                                lua_MQTLO());
	mq.set("null",                               lua_MQTypeVar(MQTypeVar()));
	mq.set("gettype",                            sol::overload(
		                                             mq_gettype_MQDataItem,
		                                             mq_gettype_MQTypeVar));

	//----------------------------------------------------------------------------

	mq.set("parse",                              &lua_Parse);

	//----------------------------------------------------------------------------

	mq.new_usertype<CTextureAnimation>(
		"CTextureAnimation",                     sol::no_constructor,
		"SetTextureCell",                        &CTextureAnimation::SetCurCell
	);

	mq.set_function("FindTextureAnimation",      &FindTextureAnimation);

	//----------------------------------------------------------------------------
	// Direct Data Bindings
	mq.set_function("getAllSpawns", &lua_getAllSpawns);
	mq.set_function("getFilteredSpawns", &lua_getFilteredSpawns);
}

} // namespace mq::lua
