/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
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
	state["dofile"] = [thread](std::string_view file, sol::variadic_args args, sol::this_state s)
	{
		std::filesystem::path file_path = std::filesystem::path(thread->GetLuaDir()) / file;
		sol::function dofile = sol::state_view(s)["_old_dofile"];

		return dofile(file_path.string(), args);
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

	state["_old_require"] = state["require"];
	state["require"] = [](sol::variadic_args args, sol::this_state s)
	{
		ScopedYieldDisabler disabler(s, YieldDisabledReason::Require);

		sol::unsafe_function require = sol::state_view(s)["_old_require"];
		return require(args);
	};

	//----------------------------------------------------------------------------
	// Internal helpers

	sol::function arginfo = state.script(R"(
		return function(f)
			local info = debug.getinfo(f, "nu")
			return info.name or 'unknown', info.namewhat or 'unk', info.nparams or -1, info.isvararg or false
		end
	)");
	state.set_function("__command_arginfo", arginfo);
}

} // namespace mq::lua::bindings
