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

#include "lua_MQCommand.h"

#include <mq/Plugin.h>

namespace mq::lua::bindings {

void lua_MQCommand::operator()(sol::variadic_args va, sol::this_state s)
{
	fmt::memory_buffer cmd;
	fmt::format_to(cmd, "{}", Command);
	for (const auto& a : va)
	{
		auto value = luaL_tolstring(a.lua_state(), a.stack_index(), NULL);
		if (value != nullptr && strlen(value) > 0)
			fmt::format_to(cmd, " {}", value);
	}

	HideDoCommand(pLocalPlayer, fmt::to_string(cmd).c_str(), false);
}

sol::object lua_MQDoCommand::get(sol::stack_object key, sol::this_state L) const
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

void mq::lua::bindings::lua_MQCommand::register_binding(sol::table& lua)
{
	lua.new_usertype<lua_MQCommand>("command",
		sol::no_constructor);

	lua.new_usertype<lua_MQDoCommand>("docommand",
		sol::no_constructor,
		sol::meta_function::index, &lua_MQDoCommand::get);

	lua["cmd"] = lua_MQDoCommand();
	lua["print"] = lua["cmd"]["echo"];
}

} // namespace mq::lua::bindings
