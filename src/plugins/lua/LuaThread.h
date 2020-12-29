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

#include <sol/sol.hpp>
#include <stack>

namespace mq::lua::events {
struct LuaEventProcessor;
}

namespace mq::lua::imgui {
struct LuaImGuiProcessor;
}

namespace mq::lua::thread {

std::optional<sol::protected_function_result> RunCoroutine(sol::coroutine& co, const std::vector<std::string>& args = {});

struct LuaThreadInfo
{
	uint32_t pid;
	std::string name;
	std::string path;
	std::vector<std::string> arguments;
	uint64_t startTime;
	uint64_t endTime;
	std::vector<std::string> returnValues;

	void SetResult(const sol::protected_function_result& result);
};

struct ThreadState;
struct LuaThread
{
	// this needs to be first in initialization order because other things depend on it
	sol::state globalState;

	sol::thread thread;
	sol::coroutine coroutine;
	sol::environment environment;
	std::optional<sol::table> globalTable;
	std::string name;
	std::string path;
	std::unique_ptr<ThreadState> state;
	std::unique_ptr<events::LuaEventProcessor> eventProcessor;
	std::unique_ptr<imgui::LuaImGuiProcessor> imguiProcessor;
	uint32_t pid;
	bool yieldToFrame;

	uint32_t hookProtectionCount;

	static uint32_t NextID()
	{
		// no need to do anything special, this will be fine
		static uint32_t current = 0;
		return ++current;
	}

	LuaThread(std::string_view name, std::string_view luaDir, const std::vector<std::string>& luaRequire, const std::vector<std::string>& dllRequire);
	LuaThread() = delete;
	LuaThread(const LuaThread&) = delete;
	LuaThread(LuaThread&&) = delete;
	LuaThread& operator=(const LuaThread&) = delete;
	LuaThread& operator=(LuaThread&&) = delete;

	std::optional<LuaThreadInfo> StartFile(std::string_view luaDir, uint32_t turbo, const std::vector<std::string>& args);
	std::optional<LuaThreadInfo> StartString(uint32_t turbo, std::string_view script);
	std::pair<sol::thread_status, std::optional<sol::protected_function_result>> Run(uint32_t turbo);
	void YieldAt(int count) const;

	void RegisterLuaState(std::shared_ptr<LuaThread> self_ptr);
};

struct ThreadState
{
	virtual bool ShouldRun(const LuaThread& thread, uint32_t turbo) = 0;
	virtual bool IsPaused() = 0;
	virtual void SetDelay(const LuaThread& thread, uint64_t time, std::optional<sol::function> condition = std::nullopt) = 0;
	virtual void Pause(LuaThread& thread, uint32_t turbo) = 0;

	static bool CheckCondition(const LuaThread& thread, std::optional<sol::function>& func);
};

struct RunningState : public ThreadState
{
	bool ShouldRun(const LuaThread& thread, uint32_t turbo) override;
	bool IsPaused() override { return false; }
	void SetDelay(const LuaThread& thread, uint64_t time, std::optional<sol::function> condition = std::nullopt) override;
	void Pause(LuaThread&, uint32_t) override;

private:
	uint64_t m_delayTime = 0L;
	std::optional<sol::function> m_delayCondition = std::nullopt;
};

struct PausedState : public ThreadState
{
	bool ShouldRun(const LuaThread&, uint32_t) override { return false; }
	bool IsPaused() override { return true; }
	void SetDelay(const LuaThread& thread, uint64_t time, std::optional<sol::function> condition = std::nullopt) override {}
	void Pause(LuaThread& thread, uint32_t turbo) override;
};

} // namespace mq::lua::thread
