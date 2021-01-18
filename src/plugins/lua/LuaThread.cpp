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

#include "pch.h"
#include "LuaThread.h"
#include "LuaEvent.h"
#include "LuaImGui.h"
#include "bindings/lua_MQCommand.h"
#include "bindings/lua_MQDataItem.h"
#include "bindings/lua_MQTypeVar.h"

#include <mq/Plugin.h>

namespace mq::lua {

// this is the special sauce that lets us execute everything on the main thread without blocking
static void ForceYield(lua_State* L, lua_Debug* D)
{
	if (auto thread_ptr = LuaThread::get_from(L))
	{
		thread_ptr->yieldToFrame = true;
	}

	lua_yield(L, 0);
}

bool ThreadState::CheckCondition(const LuaThread& thread, std::optional<sol::function>& func)
{
	if (func)
	{
		try
		{
			auto check = sol::function(thread.globalState, *func);
			thread.environment.set_on(check);
			return check();
		}
		catch (sol::error& e)
		{
			LuaError("Failed to check delay condition check with error '%s'", e.what());
			func = std::nullopt;
		}
	}

	return false;
}

bool RunningState::ShouldRun(const LuaThread& thread, uint32_t turbo)
{
	// check delayed status here
	if (m_delayTime <= MQGetTickCount64() || CheckCondition(thread, m_delayCondition))
	{
		thread.YieldAt(turbo);
		m_delayTime = 0L;
		m_delayCondition = std::nullopt;
		return true;
	}

	return false;
}

void RunningState::SetDelay(const LuaThread& thread, uint64_t time, std::optional<sol::function> condition)
{
	if (time > MQGetTickCount64() && !CheckCondition(thread, condition))
	{
		thread.YieldAt(0);
		m_delayTime = time;
		m_delayCondition = condition;
	}
}

void RunningState::Pause(LuaThread& thread, uint32_t)
{
	// this will force the coroutine to yield, and removing this thread from the vector will cause it to gc
	thread.YieldAt(0);
	WriteChatStatus("Pausing running lua script '%s' with PID %d", thread.name.c_str(), thread.pid);
	thread.state = std::make_unique<PausedState>();
}

void PausedState::Pause(LuaThread& thread, uint32_t turbo)
{
	thread.YieldAt(turbo);
	WriteChatStatus("Resuming paused lua script '%s' with PID %d", thread.name.c_str(), thread.pid);
	thread.state = std::make_unique<RunningState>();
}

LuaThread::LuaThread(std::string_view name, std::string_view luaDir,
	const std::vector<std::string>& luaRequire, const std::vector<std::string>& dllRequire)
	: name(name)
	, state(std::make_unique<RunningState>())
	, eventProcessor(std::make_unique<LuaEventProcessor>(this))
	, imguiProcessor(std::make_unique<LuaImGuiProcessor>(this))
	, pid(NextID())
{
	globalState.open_libraries();

	// always search the local dir first, then anything specified by the user, then the default paths
	static auto package_path = globalState["package"]["path"].get<std::string>(); // make this static so we always have the _original_ package paths
	globalState["package"]["path"] = fmt::format("{}\\?.lua;{}{}", luaDir, luaRequire.empty() ? "" : join(luaRequire, ";") + ";", package_path);

	static auto package_cpath = globalState["package"]["cpath"].get<std::string>();
	globalState["package"]["cpath"] = fmt::format("{}\\?.dll;{}{}", luaDir, dllRequire.empty() ? "" : join(dllRequire, ";") + ";", package_cpath);

	environment = sol::environment(globalState, sol::create, globalState.globals());

	thread = sol::thread::create(globalState);
	environment.set_on(thread);
}

std::optional<sol::protected_function_result> RunCoroutine(sol::coroutine& co, const std::vector<std::string>& args)
{
	try
	{
		auto result = co(sol::as_args(args));
		if (result.valid())
			return result;

		LuaError("%s", sol::stack::get<std::string>(result.lua_state(), result.stack_index()));
		DebugStackTrace(result.lua_state());
		result.abandon();
	}
	catch (const sol::error& e)
	{
		LuaError("%s", e.what());
		DebugStackTrace(co.lua_state());
	}

	return std::nullopt;
}

std::optional<LuaThreadInfo> LuaThread::StartFile(std::string_view luaDir, uint32_t turbo, const std::vector<std::string>& args)
{
	std::filesystem::path script_path = std::filesystem::path{ luaDir } / name;
	if (!script_path.has_extension()) script_path.replace_extension(".lua");

	path = script_path.string();

	std::error_code ec;
	if (!std::filesystem::exists(script_path, ec))
	{
		LuaError("Could not find script at path %s", script_path.c_str());
		return std::nullopt;
	}

	auto co = thread.state().load_file(script_path.string());
	if (!co.valid())
	{
		sol::error err = co;
		LuaError("Failed to load script %s with error: %s", name.c_str(), err.what());
		return std::nullopt;
	}

	coroutine = co;
	YieldAt(turbo);

	auto start_time = MQGetTickCount64();
	auto result = RunCoroutine(coroutine, args);

	auto ret = LuaThreadInfo{
		pid,
		name,
		script_path.string(),
		args,
		start_time,
		0ULL,
		{}
	};

	if (result)
		ret.SetResult(*result);
	else if (coroutine.status() != sol::call_status::yielded)
		ret.EndRun();

	return ret;
}

std::optional<LuaThreadInfo> LuaThread::StartString(uint32_t turbo, std::string_view script)
{
	auto co = thread.state().load(script);

	if (!co.valid())
	{
		sol::error err = co;
		LuaError("Failed to load script with error: %s", err.what());
		return std::nullopt;
	}

	coroutine = co;
	YieldAt(turbo);

	auto start_time = MQGetTickCount64();
	auto result = RunCoroutine(coroutine);

	auto ret = LuaThreadInfo{
		pid,
		name,
		"string",
		{},
		start_time,
		0ULL,
		{}
	};

	if (result)
		ret.SetResult(*result);
	else if (coroutine.status() != sol::call_status::yielded)
		ret.EndRun();

	return ret;
}

std::pair<sol::thread_status, std::optional<sol::protected_function_result>> LuaThread::Run(uint32_t turbo)
{
	if (!thread.valid())
		return std::make_pair(sol::thread_status::dead, std::nullopt);

	if (thread.status() != sol::thread_status::ok && thread.status() != sol::thread_status::yielded)
	{
		return std::make_pair(thread.status(), std::nullopt);
	}

	if (!state->ShouldRun(*this, turbo))
		return std::make_pair(thread.status(), std::nullopt);

	// TODO: allow the user to set "aggressive" events (which gets prepared here) and "passive" binds (which would Get prepared in `doevents`)
	eventProcessor->PrepareBinds();

	YieldAt(turbo);

	yieldToFrame = false;
	eventProcessor->RunEvents(*this);

	if (!yieldToFrame)
	{
		auto result = RunCoroutine(coroutine);
		auto status = result ? static_cast<sol::thread_status>(result->status()) : sol::thread_status::dead;
		return std::make_pair(std::move(status), std::move(result));
	}

	return std::make_pair(thread.status(), std::nullopt);
}

void LuaThread::YieldAt(int count) const
{
	lua_sethook(thread.state(), ForceYield, count == 0 ? LUA_MASKLINE : LUA_MASKCOUNT, count);
}

std::string lua_join(sol::this_state L, std::string delim, sol::variadic_args va)
{
	if (va.size() > 0)
	{
		fmt::memory_buffer str;
		const auto* del = "";
		for (const auto& arg : va)
		{
			auto value = luaL_tolstring(arg.lua_state(), arg.stack_index(), nullptr);
			if (value != nullptr && strlen(value) > 0)
			{
				fmt::format_to(str, "{}{}", del, value);
				del = delim.c_str();
			}
		}

		return fmt::to_string(str);
	}

	return "";
}

void delay(sol::object delayObj, sol::object conditionObj, sol::this_state s)
{
	using namespace std::chrono_literals;

	auto delay_int = delayObj.as<std::optional<std::chrono::milliseconds>>();
	if (!delay_int)
	{
		auto delay_str = delayObj.as<std::optional<std::string_view>>();
		if (delay_str)
		{
			if (delay_str->length() > 1 && delay_str->compare(delay_str->length() - 1, 1, "m") == 0)
				delay_int.emplace(std::chrono::minutes(GetIntFromString(*delay_str, 0)));
			else if (delay_str->length() > 2 && delay_str->compare(delay_str->length() - 2, 2, "ms") == 0)
				delay_int.emplace(std::chrono::milliseconds(GetIntFromString(*delay_str, 0)));
			else if (delay_str->length() > 1 && delay_str->compare(delay_str->length() - 1, 1, "s") == 0)
				delay_int.emplace(std::chrono::seconds(GetIntFromString(*delay_str, 0)));
		}
	}

	if (delay_int.has_value())
	{
		if (auto thread_ptr = LuaThread::get_from(s))
		{
			uint64_t delay_ms = std::max(0ms, *delay_int).count();
			auto condition = conditionObj.as<std::optional<sol::function>>();

			thread_ptr->state->SetDelay(*thread_ptr, delay_ms + MQGetTickCount64(), condition);
		}
	}
}

void exit(sol::this_state s)
{
	if (auto thread_ptr = LuaThread::get_from(s))
	{
		WriteChatStatus("Exit() called in Lua script %s with PID %d", thread_ptr->name.c_str(), thread_ptr->pid);
		thread_ptr->YieldAt(0);
		thread_ptr->thread.abandon();
	}
}

static void RegisterMQNamespace(sol::table t)
{
	bindings::lua_MQCommand::RegisterBinding(t);
	bindings::lua_MQDataItem::RegisterBinding(t);
	bindings::lua_MQTypeVar::RegisterBinding(t);

	t["delay"] = &delay;
	t["join"] = &lua_join;
	t["exit"] = &exit;

	Events_RegisterLua(t);
	ImGui_RegisterLua(t);
}

static int LoadMQRequire(lua_State* L)
{
	auto path = sol::stack::get<std::string>(L);
	if (path != "mq") return 0;

	if (auto thread_ptr = LuaThread::get_from(L))
	{
		sol::state_view sv{ L };

		thread_ptr->globalTable = sv.create_table();
		RegisterMQNamespace(*thread_ptr->globalTable);

		sv.set("_mq_internal_table", *thread_ptr->globalTable);

		std::string script("return _mq_internal_table");
		luaL_loadbuffer(sv, script.data(), script.size(), path.c_str());
		return 1;
	}

	return 0;
}

void LuaThread::RegisterLuaState(std::shared_ptr<LuaThread> self_ptr, bool injectMQ)
{
	auto& state = thread.state();

	state["_old_require"] = state["require"];
	state["require"] = [this](std::string_view mod, sol::variadic_args args)
	{
		auto& state = thread.state();

		if (hookProtectionCount++ == 0)
			lua_sethook(state, nullptr, 0, 0);

		auto ret = state["_old_require"](mod, args);

		if (--hookProtectionCount < 0)
			hookProtectionCount = 0;

		if (hookProtectionCount == 0)
			lua_sethook(state, ForceYield, LUA_MASKCOUNT, 50);

		return ret;
	};

	state["_old_dofile"] = state["dofile"];
	state["dofile"] = [this](std::string_view file, sol::variadic_args args)
	{
		auto& state = thread.state();

		auto file_path = std::filesystem::path(path).parent_path() / file;
		if (hookProtectionCount++ == 0)
			lua_sethook(state, nullptr, 0, 0);

		auto ret = state["_old_dofile"](file_path.string(), args);

		if (--hookProtectionCount < 0)
			hookProtectionCount = 0;

		if (hookProtectionCount == 0)
			lua_sethook(state, ForceYield, LUA_MASKCOUNT, 50);

		return ret;
	};

	state["mqthread"] = LuaThreadRef(self_ptr);
	state["print"] = [](sol::variadic_args va, sol::this_state s) {
		WriteChatColorf("[lua] %s", USERCOLOR_CHAT_CHANNEL, lua_join(s, "", va).c_str());
	};

	state.add_package_loader(LoadMQRequire);

	if (injectMQ)
	{
		sol::table mq_table = state.create_table();
		RegisterMQNamespace(mq_table);

		state["mq"] = mq_table;
	}
}

void LuaThreadInfo::SetResult(const sol::protected_function_result& result)
{
	if (result.status() != sol::call_status::yielded && result.return_count() > 1)
	{
		EndRun();
		returnValues = std::vector<std::string>(result.return_count() - 1);
		// need to skip the first "return" (which is not a return, it's at index + 0) which is the function itself
		for (int i = 1; i < result.return_count(); ++i)
		{
			returnValues[i - 1] = luaL_tolstring(result.lua_state(), result.stack_index() + i, nullptr);
		}
	}
}

void LuaThreadInfo::EndRun()
{
	endTime = MQGetTickCount64();
}

} // namespace mq::lua
