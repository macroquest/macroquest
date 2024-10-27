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

#include "mq/api/MacroAPI.h"
#include "mq/base/GlobalBuffer.h"
#include "mq/base/String.h"
#include "mq/base/Vector.h"

#include <sol/sol.hpp>

#include <chrono>
#include <stack>

namespace eqlib {
	class PlayerClient;
	class EQGroundItem;
}

namespace mq {
	struct MQPlugin;
}

namespace mq::lua {

class LuaEventProcessor;
class LuaImGuiProcessor;
class LuaActors;
class LuaThread;
struct LuaCoroutine;

struct ThreadState;

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
	DependencyRemoved = 2,
};

enum class YieldDisabledReason
{
	Default,
	Require,
};

struct LuaThreadInfo
{
	uint32_t pid;
	std::string name;
	std::string path;
	std::vector<std::string> arguments;
	std::chrono::system_clock::time_point startTime;
	std::chrono::system_clock::time_point endTime;
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

	~LuaThread();

	LuaThread(const LuaThread&) = delete;
	LuaThread& operator=(const LuaThread&) = delete;

	static std::shared_ptr<LuaThread> get_from(sol::state_view s);

	bool IsPaused() const { return m_paused; }
	bool IsValid() const;
	bool IsString() const { return m_isString; }
	int GetPID() const { return m_pid; }
	const std::string& GetName() const { return m_name; }
	const std::string& GetScript() const { return m_path; }
	sol::state_view GetState() const;
	sol::thread GetLuaThread() const;
	sol::thread_status GetThreadStatus() const;

	// Buffer to get swapped in for DataTypeTemp
	char buffer[SGlobalBuffer::bufferSize] = { 0 };

	void InjectMQNamespace();
	void SetTurbo(uint32_t turboVal) { m_turboNum = turboVal; }
	void SetEvaluateResult(bool evaluate) { m_evaluateResult = evaluate; }
	bool GetEvaluateResult() const { return m_evaluateResult; }

	void SetCurrentCoroutine(LuaCoroutine* co = nullptr) { m_currentCoroutine = co; }
	LuaCoroutine* GetCurrentCoroutine() { return m_currentCoroutine; }

	void EnableImGui();
	void EnableEvents();

	std::optional<LuaThreadInfo> StartFile(const ScriptLocationInfo& locationInfo, const std::vector<std::string>& args);
	std::optional<LuaThreadInfo> StartFile(std::string_view filename, const std::vector<std::string>& args);
	std::optional<LuaThreadInfo> StartString(std::string_view script, std::string_view name = "");

	// Execute a time slice
	using RunResult = std::pair<sol::thread_status, CoroutineResult>;
	RunResult Run();

	LuaThreadStatus Pause();

	void SetAllowYield(bool allowYield, YieldDisabledReason reason = YieldDisabledReason::Default);

	bool GetAllowYield() const { return m_allowYield; }
	YieldDisabledReason GetYieldDisabledReason() const { return m_yieldDisabledReason; }

	bool ShouldYield() const { return m_yieldToFrame; }
	void DoYield() { YieldAt(0); }
	void Exit(LuaThreadExitReason reason = LuaThreadExitReason::Unspecified);

	std::pair<uint32_t, sol::thread> CreateThread();
	void RemoveThread(uint32_t index);

	LuaImGuiProcessor* GetImGuiProcessor() const { return m_imguiProcessor.get(); }
	LuaEventProcessor* GetEventProcessor() const { return m_eventProcessor.get(); }

	const std::string& GetLuaDir() const { return m_luaEnvironmentSettings->luaDir; }
	const std::string& GetModuleDir() const { return m_luaEnvironmentSettings->moduleDir; }

	void UpdateLuaDir(const std::filesystem::path& newLuaDir);

	// TLOs
	bool AddTopLevelObject(const char* name, MQTopLevelObjectFunction func);
	bool RemoveTopLevelObject(const char* name);

	void RemoveAllDataObjects();

	void AssociateTopLevelObject(const MQTopLevelObject* tlo);

	bool AddDependency(const void* dep) {
		return mq::insert_unique_sorted(m_dependencies, dep) != end(m_dependencies);
	}
	void RemoveDependency(const void* dep) {
		mq::remove_sorted(m_dependencies, dep);
	}
	bool IsDependency(const void* dep) const {
		return mq::sorted_contains(m_dependencies, dep);
	}

	void AddNamedDependency(const std::string& name) {
		m_namedDependencies.insert(name);
	}

	void InitializeSpawnTable();
	void AddSpawn(eqlib::PlayerClient* spawn);
	void RemoveSpawn(eqlib::PlayerClient* spawn);

	void InitializeGroundItemTable();
	void AddGroundItem(eqlib::EQGroundItem* item);
	void RemoveGroundItem(eqlib::EQGroundItem* item);

private:
	RunResult RunOnce();

	sol::table RegisterMQNamespace(sol::this_state L);
	void Initialize();

	void YieldAt(int count) const;

	int PackageLoader(const std::string& pkg, lua_State* L);

	static int lua_PackageLoader(lua_State* L);
	static void lua_forceYield(lua_State* L, lua_Debug* D);

private:
	LuaEnvironmentSettings* m_luaEnvironmentSettings = nullptr;

	// this needs to be first in initialization order because other things depend on it
	sol::state m_globalState;
	std::shared_ptr<LuaCoroutine> m_coroutine;
	sol::environment m_environment;
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
	YieldDisabledReason m_yieldDisabledReason = YieldDisabledReason::Default;
	LuaThreadExitReason m_exitReason = LuaThreadExitReason::Unspecified;
	std::vector<const void*> m_dependencies;
	std::unordered_set<std::string> m_namedDependencies;

	std::unique_ptr<LuaEventProcessor> m_eventProcessor;
	std::unique_ptr<LuaImGuiProcessor> m_imguiProcessor;
	LuaCoroutine* m_currentCoroutine = nullptr;

	// datatypes
	ci_unordered::set<std::string> m_registeredTLOs;

	// memoized table references
	sol::table m_spawnTable = sol::nil;
	sol::table m_groundItemTable = sol::nil;
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

//============================================================================

class ScopedYieldDisabler
{
public:
	ScopedYieldDisabler(const std::shared_ptr<LuaThread>& thread_ptr, YieldDisabledReason reason = YieldDisabledReason::Default)
		: m_threadPtr(thread_ptr)
	{
		if (m_threadPtr)
		{
			m_origAllowYield = m_threadPtr->GetAllowYield();
			m_origReason = m_threadPtr->GetYieldDisabledReason();
			m_threadPtr->SetAllowYield(false, reason);
		}
	}

	ScopedYieldDisabler(sol::state_view s, YieldDisabledReason reason = YieldDisabledReason::Default)
		: m_threadPtr(LuaThread::get_from(s))
	{
		if (m_threadPtr)
		{
			m_origAllowYield = m_threadPtr->GetAllowYield();
			m_origReason = m_threadPtr->GetYieldDisabledReason();
			m_threadPtr->SetAllowYield(false, reason);
		}
	}

	~ScopedYieldDisabler()
	{
		if (m_threadPtr)
		{
			m_threadPtr->SetAllowYield(m_origAllowYield, m_origReason);
		}
	}

private:
	bool m_origAllowYield = true;
	YieldDisabledReason m_origReason = YieldDisabledReason::Default;
	std::shared_ptr<LuaThread> m_threadPtr;
};

} // namespace mq::lua
