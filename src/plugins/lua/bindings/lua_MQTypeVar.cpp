/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2020 MacroQuest Authors
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

#include "lua_MQTypeVar.h"
#include "lua_MQDataItem.h"

#include <mq/Plugin.h>

namespace mq::lua::bindings {

lua_MQTypeVar::lua_MQTypeVar(const std::string& str)
{
	auto* const type = FindMQ2DataType(str.c_str());
	if (type != nullptr)
	{
		self->Type = type;
	}
}

lua_MQTypeVar::lua_MQTypeVar(const MQTypeVar& self) : self(std::make_unique<MQTypeVar>(self)) {}

bool lua_MQTypeVar::operator==(const lua_MQTypeVar& right) const
{
	return EvaluateMember() == right.EvaluateMember();
}

bool lua_MQTypeVar::EqualData(const lua_MQDataItem& right) const
{
	return *this == right.EvaluateSelf();
}

bool lua_MQTypeVar::EqualNil(const sol::lua_nil_t&) const
{
	return EvaluateMember().Type == nullptr;
}

MQTypeVar& lua_MQTypeVar::EvaluateMember(char* index) const
{
	// the ternary in index is because datatypes are all over the place on whether or not they can accept null pointers. They all seem to agree that an empty string is the same thing, though.
	if (self->Type != nullptr && !member.empty() && !self->Type->GetMember(self->GetVarPtr(), &member[0], index ? index : "", *self))
	{
		// can't guarantee result didn't Get modified, but we want to return nil if GetMember was false
		self->Type = nullptr;
	}

	return *self;
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
	auto result = EvaluateMember();

	if (result.Type == nullptr)
		return sol::object(L, sol::in_place, sol::lua_nil);

	// There are seven basic types in Lua: nil, number, string, function, CFunction, userdata, and table. 
	// We only care about nil, number, and string, but multiple MQ types decay into the various types, so
	// we need to capture that.
	switch (result.GetType())
	{
	case MQVarPtr::VariantIdx::Float:
	case MQVarPtr::VariantIdx::Double:
		// lua's number type is the same for integral and floating, but sol handles them each slightly differently
		return sol::object(L, sol::in_place, result.Get<double>());
	case MQVarPtr::VariantIdx::Int32:
	case MQVarPtr::VariantIdx::Int64:
		return sol::object(L, sol::in_place, result.Get<int64_t>());
	case MQVarPtr::VariantIdx::UInt32:
	case MQVarPtr::VariantIdx::UInt64:
		return sol::object(L, sol::in_place, result.Get<uint64_t>());
	case MQVarPtr::VariantIdx::String:
		// if we know it's a string, let's Get a string explicitly
		return sol::object(L, sol::in_place, result.Get<CXStr>().c_str());
	default:
		// by default run it through the tostring conversion because we are assuming calling with empty parens means
		// to actualize the data in the native lua space
		char buf[MAX_STRING] = { 0 };
		result.Type->ToString(result.GetVarPtr(), buf);
		return sol::object(L, sol::in_place, buf);
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

template <typename Handler>
bool sol_lua_check(sol::types<lua_MQTypeVar>, lua_State* L, int index, Handler && handler, sol::stack::record & tracking)
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

std::ostream& operator<<(std::ostream& os, const lua_MQTypeVar& item)
{
	os << lua_MQTypeVar::ToString(item);
	return os;
}

void lua_MQTypeVar::RegisterBinding(sol::table& lua)
{
	lua.new_usertype<lua_MQTypeVar>("type",
		sol::constructors<lua_MQTypeVar(const std::string&)>(),
		sol::meta_function::call, sol::overload(&lua_MQTypeVar::Call, &lua_MQTypeVar::CallInt, &lua_MQTypeVar::CallEmpty, &lua_MQTypeVar::CallVA),
		sol::meta_function::index, &lua_MQTypeVar::Get,
		sol::meta_function::equal_to, sol::overload(&lua_MQTypeVar::operator==, &lua_MQTypeVar::EqualData, &lua_MQTypeVar::EqualNil));

	lua["null"] = lua_MQTypeVar(MQTypeVar());
}

} // namespace mq::lua::bindings
