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

#pragma once

#include <sol/sol.hpp>
#include <utility>

// define some macros so that we don't have to depends on MQ headers in this file
#define WriteChatStatus(format, ...) StatusMessage(&WriteChatf, format, __VA_ARGS__)
#define LuaError(format, ...) ErrorMessage(&WriteChatColorf, format, CONCOLOR_RED, __VA_ARGS__)

namespace mq::lua {

using CoroutineResult = std::optional<sol::protected_function_result>;

void DebugStackTrace(lua_State* L, const char* message);
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

namespace bindings {
	std::string lua_join(sol::this_state L, std::string_view delim, sol::variadic_args va);
}
using bindings::lua_join;

class LuaEnvironmentSettings
{
public:
	LuaEnvironmentSettings();
	~LuaEnvironmentSettings();

	void ConfigureLuaState(sol::state_view sv);

	std::string luaDir;
	std::string moduleDir;
	std::vector<std::string> luaRequirePaths;
	std::vector<std::string> dllRequirePaths;

private:
	bool m_initialized = false;
	std::string m_packagePath;
	std::string m_packageCPath;
	std::string m_version;
	std::string m_jitversion;
};

class LuaThread;

} // namespace mq::lua
