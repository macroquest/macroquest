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

#include "pch.h"
#include "LuaThread.h"
#include "LuaEvent.h"
#include "LuaImGui.h"
#include "bindings/lua_MQBindings.h"

#include <mq/Plugin.h>
#include <luajit.h>

#if LUAJIT_VERSION_NUM == 20005
bool lua_isyieldable(lua_State* L)
{
	// this is defined in luajit 2.1, but not in 2.0.5 -- this is a hack that is steady because
	// it's a single version, and it's preferable to pulling in 2 internal luajit headers to do
	// this nicely (lj_obj.h and lj_frame.h)

	// return ((intptr_t)(L->cframe) & CFRAME_RESUME);
	return (*(intptr_t*)((char*)L + 0x28) & 1);
}
#endif

void RegisterBitwiseOps(sol::state_view state);

namespace mq::lua {

//============================================================================

static uint32_t NextID()
{
	// no need to do anything special, this will be fine
	static uint32_t current = 0;
	return ++current;
}

CoroutineResult RunCoroutine(sol::coroutine& co, const std::vector<std::string>& args)
{
	try
	{
		auto result = co(sol::as_args(args));
		if (result.valid())
			return result;

		LuaError("%s", sol::stack::get<std::string>(result.lua_state(), result.stack_index()).c_str());
		DebugStackTrace(result.lua_state());
		result.abandon();
	}
	catch (const sol::error& ex)
	{
		LuaError("%s", ex.what());
		DebugStackTrace(co.lua_state());
	}

	return std::nullopt;
}

//============================================================================

void LuaThreadInfo::SetResult(const sol::protected_function_result& result, bool evaluate)
{
	if (result.status() != sol::call_status::yielded)
	{
		EndRun();

		if (result.return_count() >= 1)
		{
			returnValues = std::vector<std::string>(result.return_count());

			// need to skip the first "return" (which is not a return, it's at index + 0) which is the function itself
			for (int i = 0; i < result.return_count(); ++i)
			{
				returnValues[i] = luaL_tolstring(result.lua_state(), result.stack_index() + i, nullptr);
			}

			if (evaluate)
			{
				std::string results;

				for (const std::string& returnValue : returnValues)
				{
					if (!results.empty())
						results.append("\t");

					results.append(returnValue);
				}

				WriteChatColor(results.c_str(), USERCOLOR_CHAT_CHANNEL);
			}
		}
	}
}

void LuaThreadInfo::EndRun()
{
	status = LuaThreadStatus::Exited;
	endTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

//============================================================================
//============================================================================

LuaThread::LuaThread(this_is_private&&, LuaEnvironmentSettings* environment)
	: m_luaEnvironmentSettings(environment)
	, m_name("(unnamed)")
	, m_pid(NextID())
{
	m_globalState.open_libraries();
	m_luaEnvironmentSettings->ConfigureLuaState(m_globalState);

	m_environment = sol::environment(m_globalState, sol::create, m_globalState.globals());
	m_thread = sol::thread::create(m_globalState);
	m_environment.set_on(m_thread);
}

/*static*/ std::shared_ptr<LuaThread> LuaThread::Create(LuaEnvironmentSettings* environment)
{
	std::shared_ptr<LuaThread> luaThread = std::make_shared<LuaThread>(this_is_private{}, environment);
	luaThread->Initialize();

	return luaThread;
}

void LuaThread::Initialize()
{
	RegisterBitwiseOps(m_globalState);

	m_globalState["_old_dofile"] = m_globalState["dofile"];
	m_globalState["dofile"] = [this](std::string_view file, sol::variadic_args args)
	{
		std::filesystem::path file_path = std::filesystem::path(m_luaEnvironmentSettings->luaDir) / file;
		return m_globalState["_old_dofile"](file_path.string(), args);
	};

	// Replace os.exit with mq.exit
	m_globalState["os"]["exit"] = LuaThread::lua_exit;

	m_globalState["mqthread"] = LuaThreadRef(shared_from_this());
	m_globalState["print"] = [](sol::variadic_args va, sol::this_state s) {
		WriteChatColorf("%s", USERCOLOR_CHAT_CHANNEL, lua_join(s, "", va).c_str());
	};

	m_globalState.add_package_loader(LuaThread::lua_PackageLoader);
}

void LuaThread::EnableImGui()
{
	if (!m_imguiProcessor)
	{
		m_imguiProcessor = std::make_unique<LuaImGuiProcessor>(this);
	}
}

void LuaThread::EnableEvents()
{
	if (!m_eventProcessor)
	{
		m_eventProcessor = std::make_unique<LuaEventProcessor>(this);
	}
}

void LuaThread::InjectMQNamespace()
{
	if (m_mqTable.has_value())
		return;

	m_mqTable = m_globalState.create_table();
	RegisterLuaBindings(*m_mqTable);

	m_globalState["mq"] = *m_mqTable;
}

void LuaThread::Delay(sol::object delayObj, sol::object conditionObj)
{
	using namespace std::chrono_literals;

	auto delay_int = delayObj.as<std::optional<const int64_t>>();
	if (!delay_int)
	{
		auto delay_str = delayObj.as<std::optional<std::string_view>>();
		if (delay_str)
		{
			if (delay_str->length() > 1 && delay_str->compare(delay_str->length() - 1, 1, "m") == 0)
			{
				delay_int.emplace(std::chrono::duration_cast<std::chrono::milliseconds>(
					std::chrono::minutes(GetIntFromString(*delay_str, 0))).count());
			}
			else if (delay_str->length() > 2 && delay_str->compare(delay_str->length() - 2, 2, "ms") == 0)
			{
				delay_int.emplace(std::chrono::milliseconds(GetIntFromString(*delay_str, 0)).count());
			}
			else if (delay_str->length() > 1 && delay_str->compare(delay_str->length() - 1, 1, "s") == 0)
			{
				delay_int.emplace(std::chrono::duration_cast<std::chrono::milliseconds>(
					std::chrono::seconds(GetIntFromString(*delay_str, 0))).count());
			}
		}
	}

	if (delay_int.has_value())
	{
		uint64_t delay_ms = std::max(0ms, std::chrono::milliseconds(*delay_int)).count();
		std::optional<sol::function> condition = conditionObj.as<std::optional<sol::function>>();

		SetDelay(delay_ms + MQGetTickCount64(), condition);
	}
}

/*static*/ void LuaThread::lua_delay(sol::object delayObj, sol::object conditionObj, sol::this_state s)
{
	if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s))
	{
		thread_ptr->Delay(delayObj, conditionObj);
	}
}

void LuaThread::Exit(LuaThreadExitReason reason)
{
	m_exitReason = reason;
	YieldAt(0);
	m_thread.abandon();
}

/*static*/ void LuaThread::lua_exit(sol::this_state s)
{
	if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s))
	{
		thread_ptr->Exit(LuaThreadExitReason::Exit);
	}
}

void LuaThread::RegisterLuaBindings(sol::table mq)
{
	MQ_RegisterLua_MQBindings(mq);

	mq.set_function("delay",                     &LuaThread::lua_delay);
	mq.set_function("exit",                      &LuaThread::lua_exit);
	mq.set("luaDir",                             m_luaEnvironmentSettings->luaDir);

	MQ_RegisterLua_Events(mq);
	MQ_RegisterLua_ImGui(mq);
}

int LuaThread::PackageLoader(const std::string& pkg, lua_State* L)
{
	sol::state_view sv{ L };

	if (pkg == "mq")
	{
		if (!m_mqTable.has_value())
		{
			m_mqTable = sv.create_table();
			RegisterLuaBindings(*m_mqTable);
		}

		m_globalState.set("_mq_internal_table", *m_mqTable);

		std::string script("return _mq_internal_table");
		luaL_loadbuffer(sv, script.data(), script.size(), pkg.c_str());
		return 1;
	}
	else if (pkg == "ImGui")
	{
		ImGui_RegisterLua(sv);

		std::string script("return nil");
		luaL_loadbuffer(sv, script.data(), script.size(), pkg.c_str());
		return 1;
	}

	return 0;
}

/*static*/ int LuaThread::lua_PackageLoader(lua_State* L)
{
	std::string pkg = sol::stack::get<std::string>(L);

	if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(L))
	{
		return thread_ptr->PackageLoader(pkg, L);
	}

	return 0;
}

//============================================================================
//============================================================================

bool LuaThread::IsValid() const
{
	return m_thread.valid();
}

sol::state_view LuaThread::GetState() const
{
	return m_globalState;
}

//----------------------------------------------------------------------------

std::optional<LuaThreadInfo> LuaThread::StartFile(
	std::string_view filename, const std::vector<std::string>& args)
{
	std::filesystem::path script_path = std::filesystem::path{ m_luaEnvironmentSettings->luaDir } / filename;
	if (!script_path.has_extension()) script_path.replace_extension(".lua");

	m_name = filename;
	m_path = script_path.string();

	std::error_code ec;
	if (!std::filesystem::exists(script_path, ec))
	{
		LuaError("Could not find script at path %s", script_path.c_str());
		return std::nullopt;
	}

	auto co = m_thread.state().load_file(script_path.string());
	if (!co.valid())
	{
		sol::error err = co;
		LuaError("Failed to load script %s with error: %s", m_name.c_str(), err.what());
		return std::nullopt;
	}

	m_coroutine = co;
	YieldAt(m_turboNum);

	auto start_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	CoroutineResult result = RunCoroutine(m_coroutine, args);

	LuaThreadInfo ret{
		m_pid,
		m_name,
		script_path.string(),
		args,
		start_time,
		0ULL,
		{},
		LuaThreadStatus::Starting,
		false
	};

	if (result)
		ret.SetResult(*result, m_evaluateResult);
	else if (m_coroutine.status() != sol::call_status::yielded)
		ret.EndRun();

	return ret;
}

std::optional<LuaThreadInfo> LuaThread::StartString(std::string_view script,
	std::string_view name /* = "" */)
{
	m_isString = true;

	if (!name.empty())
	{
		m_name = name;
	}

	if (m_evaluateResult)
	{
		std::string evalScript = fmt::format("return {}", script);
		sol::load_result co = m_thread.state().load(evalScript);

		if (co.valid())
		{
			m_coroutine = co;
		}
	}

	if (!m_coroutine.valid())
	{
		// Failed to evaluate as an expression.
		m_evaluateResult = false;
		sol::load_result co = m_thread.state().load(script);
		if (!co.valid())
		{
			sol::error err = co;
			LuaError("Failed to load script with error: %s", err.what());
			return std::nullopt;
		}
		else
		{
			m_coroutine = co;
		}
	}

	YieldAt(m_turboNum);

	auto start_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	CoroutineResult result = RunCoroutine(m_coroutine);

	LuaThreadInfo ret{
		m_pid,
		m_name,
		std::string(script),
		{},
		start_time,
		0ULL,
		{},
		LuaThreadStatus::Starting,
		true
	};

	if (result)
		ret.SetResult(*result, m_evaluateResult);
	else if (m_coroutine.status() != sol::call_status::yielded)
		ret.EndRun();

	return ret;
}

LuaThread::RunResult LuaThread::Run()
{
	if (m_coroutine.status() == sol::call_status::yielded)
	{
		return RunOnce();
	}

	return { static_cast<sol::thread_status>(m_coroutine.status()), std::nullopt };
}

LuaThread::RunResult LuaThread::RunOnce()
{
	if (!m_thread.valid())
		return { sol::thread_status::dead, std::nullopt };

	if (m_thread.status() != sol::thread_status::ok && m_thread.status() != sol::thread_status::yielded)
	{
		return { m_thread.status(), std::nullopt };
	}

	if (!ShouldRun())
	{
		return { m_thread.status(), std::nullopt };
	}

	if (m_eventProcessor)
	{
		// TODO: allow the user to set "aggressive" events (which gets prepared here) and "passive" binds (which would Get prepared in `doevents`)
		m_eventProcessor->PrepareBinds();
	}

	YieldAt(m_turboNum);
	m_yieldToFrame = false;

	if (m_eventProcessor)
	{
		m_eventProcessor->RunEvents(*this);
	}

	if (!m_yieldToFrame)
	{
		CoroutineResult result = RunCoroutine(m_coroutine);
		sol::thread_status status = result ? static_cast<sol::thread_status>(result->status()) : sol::thread_status::dead;
		return std::make_pair(std::move(status), std::move(result));
	}

	if (!m_thread.valid())
	{
		return { sol::thread_status::dead, std::nullopt };
	}

	return { m_thread.status(), std::nullopt };
}

bool LuaThread::ShouldRun()
{
	if (m_paused)
	{
		return false;
	}

	// check delayed status
	if (m_delayTime <= MQGetTickCount64() || CheckCondition(m_delayCondition))
	{
		YieldAt(m_turboNum);
		m_delayTime = 0;
		m_delayCondition = std::nullopt;
		return true;
	}

	return false;
}

void LuaThread::SetDelay(uint64_t time, std::optional<sol::function> condition /* = std::nullopt */)
{
	if (m_paused)
		return;

	if (time > MQGetTickCount64() && !CheckCondition(condition))
	{
		YieldAt(0);
		m_delayTime = time;
		m_delayCondition = condition;
	}
}

LuaThreadStatus LuaThread::Pause()
{
	if (m_paused)
	{
		YieldAt(m_turboNum);

		WriteChatStatus("Resuming paused lua script '%s' with PID %d", m_name.c_str(), m_pid);
		m_paused = false;
		m_delayTime = 0L;
		m_delayCondition = std::nullopt;

		return LuaThreadStatus::Running;
	}

	// this will force the coroutine to yield, and removing this thread from the vector will cause it to gc
	YieldAt(0);

	WriteChatStatus("Pausing running lua script '%s' with PID %d", m_name.c_str(), m_pid);
	m_paused = true;

	return LuaThreadStatus::Paused;
}

bool LuaThread::CheckCondition(std::optional<sol::function>& func)
{
	if (!func)
		return false;

	try
	{
		sol::function check(m_globalState, *func);
		m_environment.set_on(check);
		return check();
	}
	catch (sol::error& ex)
	{
		LuaError("Failed to check delay condition check with error '%s'", ex.what());
		func = std::nullopt;
	}

	return false;
}

// this is the special sauce that lets us execute everything on the main thread without blocking
/*static*/ void LuaThread::lua_forceYield(lua_State* L, lua_Debug* D)
{
	if (lua_isyieldable(L))
	{
		if (std::shared_ptr<LuaThread> thread_ptr = get_from(L))
		{
			thread_ptr->m_yieldToFrame = true;
		}

		lua_yield(L, 0);
	}
	else if (D->event != LUA_HOOKRET && D->event != LUA_HOOKTAILRET) // if we have either of these, we know we've already set the hook
	{
		// we can just keep retrying at every return (every chance we get to possibly change boundaries)
		lua_sethook(L, LuaThread::lua_forceYield, LUA_MASKRET, 0);
	}
}

void LuaThread::YieldAt(int count) const
{
	lua_sethook(m_thread.state(), &LuaThread::lua_forceYield, count == 0 ? LUA_MASKLINE : LUA_MASKCOUNT, count);
}

//============================================================================

} // namespace mq::lua
