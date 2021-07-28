/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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

namespace mq::lua {

class LuaEventProcessor;
class LuaImGuiProcessor;
class LuaThread;

struct ThreadState;

std::optional<sol::protected_function_result> RunCoroutine(sol::coroutine& co, const std::vector<std::string>& args = {});

enum class LuaThreadStatus
{
	Starting,
	Running,
	Paused,
	Exited
};

struct LuaThreadInfo
{
	uint32_t pid;
	std::string name;
	std::string path;
	std::vector<std::string> arguments;
	std::time_t startTime;
	std::time_t endTime;
	std::vector<std::string> returnValues;
	LuaThreadStatus status;

	std::string_view status_string() const
	{
		switch (status)
		{
		case LuaThreadStatus::Starting:
			return "STARTING";
		case LuaThreadStatus::Running:
			return "RUNNING";
		case LuaThreadStatus::Paused:
			return "PAUSED";
		case LuaThreadStatus::Exited:
			return "EXITED";
		default:
			return "UNKNOWN";
		}
	}

	void SetResult(const sol::protected_function_result& result);
	void EndRun();
};

//============================================================================

class LuaThread : public std::enable_shared_from_this<LuaThread>
{
protected:
	struct this_is_private {};

	LuaThread(const LuaThread&) = delete;
	LuaThread& operator=(const LuaThread&) = delete;

	void Initialize(bool injectMQ);

public:
	LuaThread(this_is_private&&, std::string_view name, std::string_view luaDir, const std::vector<std::string>& luaRequire,
		const std::vector<std::string>& dllRequire);

	static std::shared_ptr<LuaThread> Create(
		std::string_view name,
		std::string_view luaDir,
		const std::vector<std::string>& luaRequire,
		const std::vector<std::string>& dllRequire,
		bool injectMQ);

	static std::shared_ptr<LuaThread> get_from(sol::state_view s);

	bool IsPaused() const { return m_paused; }
	bool IsValid() const;
	int GetPID() const { return m_pid; }
	const std::string& GetName() const { return m_name; }
	sol::state_view GetState() const;
	sol::thread GetLuaThread() const { return m_thread; }

	std::optional<LuaThreadInfo> StartFile(std::string_view luaDir, uint32_t turbo, const std::vector<std::string>& args);
	std::optional<LuaThreadInfo> StartString(uint32_t turbo, std::string_view script);

	// Execute a time slice
	using RunResult = std::pair<sol::thread_status, std::optional<sol::protected_function_result>>;
	RunResult Run(uint32_t turbo);
	LuaThreadStatus Pause(uint32_t turbo);

	bool ShouldYield() const { return m_yieldToFrame; }
	void DoYield() { YieldAt(0); }
	void Exit();

	LuaImGuiProcessor* GetImGuiProcessor() const { return m_imguiProcessor.get(); }
	LuaEventProcessor* GetEventProcessor() const { return m_eventProcessor.get(); }

private:
	RunResult RunOnce(uint32_t turbo);

	void RegisterLuaBindings(sol::table mq);

	void YieldAt(int count) const;
	bool CheckCondition(std::optional<sol::function>& func);
	void Delay(sol::object delayObj, sol::object conditionObj);
	bool ShouldRun(uint32_t turbo);
	void SetDelay(uint64_t time, std::optional<sol::function> condition = std::nullopt);

	int PackageLoader(const std::string& pkg, lua_State* L);

	static int lua_PackageLoader(lua_State* L);
	static void lua_exit(sol::this_state s);
	static void lua_delay(sol::object delayObj, sol::object conditionObj, sol::this_state s);
	static void lua_forceYield(lua_State* L, lua_Debug* D);

private:
	// this needs to be first in initialization order because other things depend on it
	sol::state m_globalState;
	sol::thread m_thread;
	sol::coroutine m_coroutine;
	sol::environment m_environment;
	std::optional<sol::table> m_mqTable;

	std::string m_name;
	std::string m_path;
	std::unique_ptr<LuaEventProcessor> m_eventProcessor;
	std::unique_ptr<LuaImGuiProcessor> m_imguiProcessor;
	uint32_t m_pid;
	bool m_yieldToFrame = false;

	bool m_paused = false;
	uint64_t m_delayTime = 0L;
	std::optional<sol::function> m_delayCondition = std::nullopt;
};

//============================================================================

// Create a discrete type for this weak pointer.
struct LuaThreadRef : public std::weak_ptr<LuaThread>
{
	using weak_ptr::weak_ptr;
};

inline std::shared_ptr<LuaThread> LuaThread::get_from(sol::state_view s)
{
	std::optional<LuaThreadRef> thread = s["mqthread"];
	return thread.value_or(LuaThreadRef()).lock();
}

} // namespace mq::lua
