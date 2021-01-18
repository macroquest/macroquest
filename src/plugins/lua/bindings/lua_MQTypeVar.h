/*
 * MacroQuest: The extension platform for EverQuest
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
	struct MQTypeVar;
}

namespace mq::lua::bindings {

struct lua_MQDataItem;
struct lua_MQTypeVar
{
	std::unique_ptr<MQTypeVar> self;
	std::string member;

	lua_MQTypeVar(const std::string& str);

	/**
	 * \brief wraps an MQ type var in a lua implementation
	 * \param self the MQ type var data source to be represented in lua
	 */
	lua_MQTypeVar(const MQTypeVar& self);
	bool operator==(const lua_MQTypeVar& right) const;
	bool EqualData(const lua_MQDataItem& right) const;
	bool EqualNil(const sol::lua_nil_t&) const;
	MQTypeVar& EvaluateMember(char* index = nullptr) const;
	static std::string ToString(const lua_MQTypeVar& obj);
	sol::object Call(std::string index, sol::this_state L) const;
	sol::object CallInt(int index, sol::this_state L) const;
	sol::object CallVA(sol::this_state L, sol::variadic_args args) const;
	sol::object CallEmpty(sol::this_state L) const;
	sol::object Get(sol::stack_object key, sol::this_state L) const;
	static void RegisterBinding(sol::table& lua);
};

} // namespace mq::lua::bindings
