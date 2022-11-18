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

#include "LuaThread.h"

#include <mq/Plugin.h>

#include <sol/sol.hpp>
#include <filesystem>
#include <cstdint>

namespace mq::lua::bindings {

void lua_exit(sol::this_state s);

void RegisterBindings_Globals(LuaThread* thread, sol::state_view state)
{
	state["_old_dofile"] = state["dofile"];
	state["dofile"] = [thread, &state](std::string_view file, sol::variadic_args args)
	{
		std::filesystem::path file_path = std::filesystem::path(thread->GetLuaDir()) / file;
		return state["_old_dofile"](file_path.string(), args);
	};

	// Replace os.exit with mq.exit
	state["os"]["exit"] = &lua_exit;

	state["mqthread"] = LuaThreadRef(thread->shared_from_this());

	state["print"] = [](sol::variadic_args va, sol::this_state s) {
		WriteChatColorf("%s", USERCOLOR_CHAT_CHANNEL, lua_join(s, "", va).c_str());
	};
	state["printf"] = [](sol::variadic_args va, sol::this_state s) {
		// replicate string.format
		sol::function string_format = sol::state_view(s)["string"]["format"];
		std::string message = string_format(va);

		WriteChatColorf("%s", USERCOLOR_CHAT_CHANNEL, message.c_str());
	};
}

} // namespace mq::lua::bindings
