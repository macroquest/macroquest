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

#include <sol/sol.hpp>
#include <utility>

// define some macros so that we don't have to depends on MQ headers in this file
#define WriteChatStatus(format, ...) StatusMessage(&WriteChatf, format, __VA_ARGS__)
#define LuaError(format, ...) ErrorMessage(&WriteChatColorf, format, CONCOLOR_RED, __VA_ARGS__)

namespace mq::lua {

void DebugStackTrace(lua_State* L);
bool DoStatus();

using Writer = void(*)(const char*, ...);

template <typename... Args>
void StatusMessage(Writer writer, const char* format, Args&&... args)
{
	if (DoStatus())
		writer(format, std::forward<Args>(args)...);
}

using ColorWriter = void(*)(const char*, int, ...);

template <typename... Args>
void ErrorMessage(ColorWriter writer, const char* format, int color, Args&&... args)
{
	writer(format, color, std::forward<Args>(args)...);
}

std::string lua_join(sol::this_state L, std::string delim, sol::variadic_args va);

} // namespace mq::lua
