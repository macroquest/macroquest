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

namespace mq::lua::bindings {

struct lua_MQCommand
{
	std::string command;
	lua_MQCommand(std::string_view command) : command(command) {}
	void operator()(sol::variadic_args va, sol::this_state s);
	static void RegisterBinding(sol::table& lua);
};

struct lua_MQDoCommand
{
	// this is only used to provide a namespace for commands
	sol::object Get(sol::stack_object key, sol::this_state L) const;
};

} // namespace mq::lua::bindings
