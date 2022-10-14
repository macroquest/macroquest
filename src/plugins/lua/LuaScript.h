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

#pragma once

#include "LuaCommon.h"

#include <sol/sol.hpp>

namespace mq::lua {
struct LuaScript
{
	sol::function Main;
	sol::function OnPulse;
	sol::function InitializePlugin;
	sol::function SetGameState;

	LuaScript(sol::this_state L)
		: Main(sol::make_reference<sol::function>(L.lua_state(), nullptr))
		, OnPulse(sol::make_reference<sol::function>(L.lua_state(), nullptr))
		, InitializePlugin(sol::make_reference<sol::function>(L.lua_state(), nullptr))
		, SetGameState(sol::make_reference<sol::function>(L.lua_state(), nullptr))
	{}

	// TODO: If we can't use nullptr above, we will need sensible defaults...
	sol::object defaultMain(sol::variadic_args args) { return sol::nil; }
	void defaultOnPulse() {}
	void defaultInitializePlugin() {}
	void defaultSetGameState(int GameState) {}
};
} // namespace mq::lua
