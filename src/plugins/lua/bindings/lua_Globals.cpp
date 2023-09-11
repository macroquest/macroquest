/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
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
		sol::safe_function_result result;

		{
			ScopedYieldDisabler disabler(s, YieldDisabledReason::Require);

			sol::safe_function require = sol::state_view(s)["_old_require"];
			result = require(args);
		}

		if (!result.valid())
		{
			// If we failed here, we already got an error message, but we need to re-raise. Not sure
			// how to do that without reproducing the stack trace, so just grab the message and trim the
			// stack part off and re-raise it

			std::string message = sol::stack::pop<std::string>(result.lua_state());
			std::string_view svMessage = message;
			auto pos = svMessage.find("stack traceback:");
			if (pos != std::string_view::npos)
			{
				svMessage = svMessage.substr(0, pos);
				svMessage = rtrim(svMessage);
			}

			luaL_error(s, "%s", std::string(svMessage).c_str());
		}
		return result;
	};
}

} // namespace mq::lua::bindings
