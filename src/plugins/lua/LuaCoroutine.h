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

#pragma once

#include "LuaCommon.h"

#include <sol/sol.hpp>

namespace mq::lua {

class LuaThread;

struct LuaCoroutine
{
	LuaThread* luaThread;

	sol::coroutine coroutine;
	sol::thread thread;
	uint64_t m_delayTime = 0L;
	std::optional<sol::function> m_delayCondition = std::nullopt;

	bool CheckCondition(std::optional<sol::function>& func);
	void Delay(sol::object delayObj, std::optional<sol::object> conditionObj, sol::state_view s);
	void SetDelay(uint64_t time, std::optional<sol::function> condition = std::nullopt);
	void ClearDelay();

	bool ShouldRun();
	CoroutineResult RunCoroutine();
	CoroutineResult RunCoroutine(const std::vector<std::string>& args);
	CoroutineResult RunCoroutine(const std::vector<sol::object>& args);
	static std::shared_ptr<LuaCoroutine> Create(sol::thread thread, LuaThread* luaThread);

	LuaCoroutine(sol::thread thread, LuaThread* luaThread);
};

} // namespace mq::lua
