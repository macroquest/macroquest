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

#include "LuaCommon.h"

#include <sol/sol.hpp>
#include <stack>

namespace mq::lua {

class LuaEventProcessor;
class LuaImGuiProcessor;
class LuaThread;

struct ThreadState;

using CoroutineResult = std::optional<sol::protected_function_result>;
CoroutineResult RunCoroutine(sol::coroutine& co, const std::vector<std::string>& args = {});

enum class LuaThreadStatus
{
	Starting,
	Running,
	Paused,
	Exited
};

enum class LuaThreadExitReason
{
	Unspecified = 0,
	Exit = 1,
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
	bool isString;

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

	void SetResult(const sol::protected_function_result& result, bool evaluate);
	void EndRun();
};

//============================================================================

class LuaThread : public std::enable_shared_from_this<LuaThread>
{
private:
	struct this_is_private {};

public:
	LuaThread(this_is_private&&, LuaEnvironmentSettings* environment);
	static std::shared_ptr<LuaThread> Create(LuaEnvironmentSettings* environment);

	LuaThread(const LuaThread&) = delete;
	LuaThread& operator=(const LuaThread&) = delete;

	static std::shared_ptr<LuaThread> get_from(sol::state_view s);

	bool IsPaused() const { return m_paused; }
	bool IsValid() const;
	bool IsString() const { return m_isString; }
	int GetPID() const { return m_pid; }
	const std::string& GetName() const { return m_name; }
	sol::state_view GetState() const;
	sol::thread GetLuaThread() const { return m_thread; }

	void InjectMQNamespace();
	void SetTurbo(uint32_t turboVal) { m_turboNum = turboVal; }
	void SetEvaluateResult(bool evaluate) { m_evaluateResult = evaluate; }
	bool GetEvaluateResult() const { return m_evaluateResult; }

	void EnableImGui();
	void EnableEvents();

	std::optional<LuaThreadInfo> StartFile(std::string_view filename, const std::vector<std::string>& args);
	std::optional<LuaThreadInfo> StartString(std::string_view script, std::string_view name = "");

	// Execute a time slice
	using RunResult = std::pair<sol::thread_status, CoroutineResult>;
	RunResult Run();

	LuaThreadStatus Pause();

	void SetAllowYield(bool allowYield) { m_allowYield = allowYield; }
	bool GetAllowYield() const { return m_allowYield; }

	bool ShouldYield() const { return m_yieldToFrame; }
	void DoYield() { YieldAt(0); }
	void Exit(LuaThreadExitReason reason = LuaThreadExitReason::Unspecified);

	std::pair<uint32_t, sol::thread> CreateThread();
	void RemoveThread(uint32_t index);

	LuaImGuiProcessor* GetImGuiProcessor() const { return m_imguiProcessor.get(); }
	LuaEventProcessor* GetEventProcessor() const { return m_eventProcessor.get(); }

private:
	RunResult RunOnce();

	void RegisterLuaBindings(sol::table mq);
	void Initialize();

	void YieldAt(int count) const;
	bool CheckCondition(std::optional<sol::function>& func);
	void Delay(sol::object delayObj, sol::object conditionObj);
	bool ShouldRun();
	void SetDelay(uint64_t time, std::optional<sol::function> condition = std::nullopt);

	int PackageLoader(const std::string& pkg, lua_State* L);

	static int lua_PackageLoader(lua_State* L);
	static void lua_exit(sol::this_state s);
	static void lua_delay(sol::object delayObj, sol::object conditionObj, sol::this_state s);
	static void lua_forceYield(lua_State* L, lua_Debug* D);

private:
	LuaEnvironmentSettings* m_luaEnvironmentSettings = nullptr;

	// this needs to be first in initialization order because other things depend on it
	sol::state m_globalState;
	sol::thread m_thread;
	sol::coroutine m_coroutine;
	sol::environment m_environment;
	std::optional<sol::table> m_mqTable;
	sol::table m_threadTable;
	uint32_t m_threadIndex = 0;

	std::string m_name;
	std::string m_path;
	uint32_t m_pid = 0;
	uint32_t m_turboNum = 500;
	bool m_yieldToFrame = false;
	bool m_isString = false;
	bool m_paused = false;
	bool m_evaluateResult = false;
	bool m_allowYield = true;
	uint64_t m_delayTime = 0L;
	std::optional<sol::function> m_delayCondition = std::nullopt;
	LuaThreadExitReason m_exitReason = LuaThreadExitReason::Unspecified;

	std::unique_ptr<LuaEventProcessor> m_eventProcessor;
	std::unique_ptr<LuaImGuiProcessor> m_imguiProcessor;
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
