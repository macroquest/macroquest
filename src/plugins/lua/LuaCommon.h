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
#define SOL_LUAJIT 1
#include <sol/sol.hpp>
#include <utility>

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

namespace thread {
	std::string join(sol::this_state L, std::string delim, sol::variadic_args va);
}

} // namespace mq::lua
