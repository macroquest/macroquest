/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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
				fmt::format_to(str, "{}{}", del, value);
				del = delim;
			}
		}

		return fmt::to_string(str);
	}

	return "";
}

//============================================================================

#pragma region Command Bindings

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
		fmt::format_to(cmd, "{}", command);

		for (const auto& a : va)
		{
			auto value = luaL_tolstring(a.lua_state(), a.stack_index(), nullptr);
			if (value != nullptr && strlen(value) > 0)
				fmt::format_to(cmd, " {}", value);
		}

		HideDoCommand(pLocalPlayer, fmt::to_string(cmd).c_str(), false);

		if (!bRunNextCommand)
		{
			if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s))
			{
				thread_ptr->DoYield();
			}
		}
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

		HideDoCommand(pLocalPlayer, command.c_str(), false);

		if (!bRunNextCommand)
		{
			if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s))
			{
				thread_ptr->DoYield();
			}
		}
	}

	static void command(sol::variadic_args va, sol::this_state s)
	{
		// replicate string.format
		std::string command = lua_join(s, " ", va);

		HideDoCommand(pLocalPlayer, command.c_str(), false);

		if (!bRunNextCommand)
		{
			if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s))
			{
				thread_ptr->DoYield();
			}
		}
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
			self->Type = type;
		}
	}

	/**
	 * \brief wraps an MQ type var in a lua implementation
	 * \param self the MQ type var data source to be represented in lua
	 */
	lua_MQTypeVar(const MQTypeVar& self)
		: self(std::make_unique<MQTypeVar>(self)) {}

	bool operator==(const lua_MQTypeVar& right) const;
	bool EqualData(const lua_MQDataItem& right) const;
	bool EqualNil(const sol::lua_nil_t&) const;
	MQTypeVar EvaluateMember(char* index = nullptr) const;
	static std::string ToString(const lua_MQTypeVar& obj);
	sol::object Call(std::string index, sol::this_state L) const;
	sol::object CallInt(int index, sol::this_state L) const;
	sol::object CallVA(sol::this_state L, sol::variadic_args args) const;
	sol::object CallEmpty(sol::this_state L) const;
	sol::object Get(sol::stack_object key, sol::this_state L) const;

private:
	std::unique_ptr<MQTypeVar> self;
	std::string member;
};

bool lua_MQTypeVar::operator==(const lua_MQTypeVar& right) const
{
	return EvaluateMember() == right.EvaluateMember();
}

bool lua_MQTypeVar::EqualNil(const sol::lua_nil_t&) const
{
	return EvaluateMember().Type == nullptr;
}

MQTypeVar lua_MQTypeVar::EvaluateMember(char* index) const
{
	if (self->Type == nullptr || member.empty())
		return *self;

	// the ternary in index is because datatypes are all over the place on whether or not they can
	// accept null pointers. They all seem to agree that an empty string is the same thing, though.
	MQTypeVar var;
	if (self->Type->GetMember(self->GetVarPtr(), member.c_str(), index ? index : "", var))
		return std::move(var);

	// can't guarantee result didn't Get modified, but we want to return nil if GetMember was false
	return MQTypeVar();
}

std::string lua_MQTypeVar::ToString(const lua_MQTypeVar& obj)
{
	auto var = obj.EvaluateMember();
	if (var.Type != nullptr)
	{
		char buf[2048] = { 0 };
		var.Type->ToString(var, buf);
		return std::string(std::move(buf));
	}

	return "null";
}

sol::object lua_MQTypeVar::Call(std::string index, sol::this_state L) const
{
	return sol::object(L, sol::in_place, lua_MQTypeVar(EvaluateMember(&index[0])));
}

sol::object lua_MQTypeVar::CallInt(int index, sol::this_state L) const
{
	return Call(std::to_string(index), L);
}

sol::object lua_MQTypeVar::CallVA(sol::this_state L, sol::variadic_args args) const
{
	return Call(lua_join(L, ",", args), L);
}

sol::object lua_MQTypeVar::CallEmpty(sol::this_state L) const
{
	MQTypeVar result = EvaluateMember();

	if (result.Type == nullptr)
		return sol::object(L, sol::in_place, sol::lua_nil);

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

	// There are seven basic types in Lua: nil, number, string, function, CFunction, userdata, and table.
	// We only care about nil, number, and string, but multiple MQ types decay into the various types, so
	// we need to capture that.
	switch (result.GetType())
	{
	case MQVarPtr::VariantIdx::Float:
	case MQVarPtr::VariantIdx::Double:
		// lua's number type is the same for integral and floating, but sol handles them each slightly differently
		return sol::object(L, sol::in_place, result.Get<double>());
	case MQVarPtr::VariantIdx::UInt64:
		return sol::object(L, sol::in_place, result.Get<int64_t>());
	case MQVarPtr::VariantIdx::Bool:
		return sol::object(L, sol::in_place, result.Get<bool>());
	case MQVarPtr::VariantIdx::String:
		// if we know it's a string, let's Get a string explicitly
		return sol::object(L, sol::in_place, result.Get<CXStr>().c_str());
	default:
		// by default run it through the tostring conversion because we are assuming calling with empty parens means
		// to actualize the data in the native lua space
		char buf[MAX_STRING] = { 0 };
		if (result.Type->ToString(result.GetVarPtr(), buf))
			return sol::object(L, sol::in_place, buf);

		return sol::object(L, sol::in_place, sol::lua_nil);
	}
}

sol::object lua_MQTypeVar::Get(sol::stack_object key, sol::this_state L) const
{
	auto var = lua_MQTypeVar(EvaluateMember());
	auto maybe_key = key.as<std::optional<std::string_view>>();

	if (maybe_key)
		var.member = *maybe_key;

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
	return EvaluateSelf().self->Type == nullptr;
}

std::string lua_MQDataItem::ToString(const lua_MQDataItem& data)
{
	return lua_MQTypeVar::ToString(data.EvaluateSelf());
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

std::ostream& operator<<(std::ostream& os, const lua_MQDataItem& item)
{
	os << lua_MQDataItem::ToString(item);
	return os;
}

std::ostream& operator<<(std::ostream& os, const lua_MQTypeVar& item)
{
	os << lua_MQTypeVar::ToString(item);
	return os;
}
#pragma endregion

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

	//----------------------------------------------------------------------------

	mq.new_usertype<CTextureAnimation>(
		"CTextureAnimation",                     sol::no_constructor,
		"SetTextureCell",                        &CTextureAnimation::SetCurCell
	);

	mq.set_function("FindTextureAnimation",      &FindTextureAnimation);
}

} // namespace mq::lua
