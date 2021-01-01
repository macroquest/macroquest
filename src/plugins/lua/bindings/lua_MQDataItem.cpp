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

#include "lua_MQDataItem.h"
#include "lua_MQTypeVar.h"

#include <mq/Plugin.h>

namespace mq::lua::bindings {

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

lua_MQDataItem::lua_MQDataItem(const std::string& str)
	: self(FindMQ2Data(str.c_str()))
{
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

sol::object lua_MQTLO::Get(sol::stack_object key, sol::this_state L) const
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

std::ostream& operator<<(std::ostream& os, const lua_MQDataItem& item)
{
	os << lua_MQDataItem::ToString(item);
	return os;
}

void lua_MQDataItem::RegisterBinding(sol::table& lua)
{
	lua.new_usertype<lua_MQDataItem>("data",
		sol::constructors<lua_MQDataItem(const std::string&)>(),
		sol::meta_function::call, sol::overload(&lua_MQDataItem::Call, &lua_MQDataItem::CallInt, &lua_MQDataItem::CallEmpty, &lua_MQDataItem::CallVA),
		sol::meta_function::index, &lua_MQDataItem::Get,
		sol::meta_function::equal_to, sol::overload(&lua_MQDataItem::operator==, &lua_MQDataItem::EqualVar, &lua_MQDataItem::EqualNil));

	lua.new_usertype<lua_MQTLO>("tlo",
		sol::no_constructor,
		sol::meta_function::index, &lua_MQTLO::Get);

	lua["TLO"] = lua_MQTLO();
}

} // namespace mq::lua::bindings
