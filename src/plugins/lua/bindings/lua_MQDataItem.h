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
#pragma once

#include "LuaCommon.h"

namespace mq {
struct MQDataItem;
}

namespace mq::lua::bindings {

struct lua_MQTypeVar;
struct lua_MQDataItem
{
	const MQDataItem* const self;
	lua_MQDataItem() : self(nullptr) {}

	// this will allow users an alternate way to Get data items
	lua_MQDataItem(const std::string& str);
	lua_MQDataItem(const MQDataItem* const self) : self(self) {}
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
	static void RegisterBinding(sol::table& lua);
};

struct lua_MQTLO
{
	sol::object Get(sol::stack_object key, sol::this_state L) const;
};

} // namespace mq::lua::bindings
