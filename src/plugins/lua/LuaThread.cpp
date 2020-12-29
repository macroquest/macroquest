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

#include "LuaThread.h"
#include "LuaEvent.h"
#include "LuaImGui.h"

#include "bindings/lua_MQCommand.h"
#include "bindings/lua_MQDataItem.h"
#include "bindings/lua_MQTypeVar.h"

#include <mq/Plugin.h>

// this is the special sauce that lets us execute everything on the main thread without blocking
static void ForceYield(lua_State* L, lua_Debug* D)
{
	std::optional<std::weak_ptr<mq::lua::thread::LuaThread>> thread = sol::state_view(L)["mqthread"];
	if (auto thread_ptr = thread.value_or(std::weak_ptr<mq::lua::thread::LuaThread>()).lock())
		thread_ptr->YieldToFrame = true;

	lua_yield(L, 0);
}

namespace mq::lua::thread {

bool ThreadState::check_condition(const LuaThread& thread, std::optional<sol::function>& func)
{
	if (func)
	{
		try
		{
			auto check = sol::function(thread.GlobalState, *func);
			thread.Environment.set_on(check);
			return check();
		}
		catch (sol::error& e)
		{
			MacroError("Failed to check delay condition check with error '%s'", e.what());
			func = std::nullopt;
		}
	}

	return false;
}

bool RunningState::should_run(const LuaThread& thread, uint32_t turbo)
{
	// check delayed status here
	if (m_delayTime <= MQGetTickCount64() || check_condition(thread, m_delayCondition))
	{
		thread.yield_at(turbo);
		m_delayTime = 0L;
		m_delayCondition = std::nullopt;
		return true;
	}

	return false;
}

void RunningState::set_delay(const LuaThread& thread, uint64_t time, std::optional<sol::function> condition)
{
	if (time > MQGetTickCount64() && !check_condition(thread, condition))
	{
		thread.yield_at(0);
		m_delayTime = time;
		m_delayCondition = condition;
	}
}

void RunningState::pause(LuaThread& thread, uint32_t)
{
	// this will force the coroutine to yield, and removing this thread from the vector will cause it to gc
	thread.yield_at(0);
	StatusMessage(&WriteChatf, "Pausing running lua script '%s' with PID %d", thread.Name.c_str(), thread.PID);
	thread.State = std::make_unique<PausedState>();
}

void PausedState::pause(LuaThread& thread, uint32_t turbo)
{
	thread.yield_at(turbo);
	StatusMessage(&WriteChatf, "Resuming paused lua script '%s' with PID %d", thread.Name.c_str(), thread.PID);
	thread.State = std::make_unique<RunningState>();
}

LuaThread::LuaThread(const sol::state_view& state, std::string_view name) :
	Thread(sol::thread::create(state)),
	GlobalState(state),
	Environment(sol::environment(state, sol::create, state.globals())),
	Name(name),
	State(std::make_unique<RunningState>()),
	EventProcessor(std::make_unique<events::LuaEventProcessor>(this)),
	ImGuiProcessor(std::make_unique<imgui::LuaImGuiProcessor>(this)),
	PID(next_id()),
	HookProtectionCount(0)
{
	Environment.set_on(Thread);
}

std::optional<sol::protected_function_result> run_co(sol::coroutine& co, const std::vector<std::string>& args)
{
	try
	{
		auto result = co(sol::as_args(args));
		if (result.valid())
			return result;

		sol::error err = std::move(result);
		throw err;
	}
	catch (sol::error& e)
	{
		MacroError("%s", e.what());
		DebugStackTrace(co.lua_state());
	}

	return std::nullopt;
}

std::optional<LuaThreadInfo> LuaThread::start_file(std::string_view luaDir, uint32_t turbo, const std::vector<std::string>& args)
{
	auto script_path = std::filesystem::path(Name);
	if (script_path.is_relative()) script_path = luaDir / script_path;
	if (!script_path.has_extension()) script_path += ".lua";

	if (!std::filesystem::exists(script_path))
	{
		MacroError("Could not find script at path %s", script_path.string().c_str());
		return std::nullopt;
	}

	auto co = Thread.state().load_file(script_path.string());
	if (!co.valid())
	{
		sol::error err = co;
		MacroError("Failed to load script %s with error: %s", Name.c_str(), err.what());
		return std::nullopt;
	}

	Coroutine = co;
	yield_at(turbo);

	auto start_time = MQGetTickCount64();
	auto result = run_co(Coroutine, args);

	auto ret = LuaThreadInfo{
		PID,
		Name,
		script_path.string(),
		args,
		start_time,
		0ULL,
		{}
	};

	if (result) ret.set_result(*result);
	return ret;
}

std::optional<LuaThreadInfo> LuaThread::start_string(uint32_t turbo, std::string_view script)
{
	auto co = Thread.state().load(fmt::format("mq = require('mq')\n{}", script));
	if (!co.valid())
	{
		sol::error err = co;
		MacroError("Failed to load script with error: %s", err.what());
		return std::nullopt;
	}

	Coroutine = co;
	yield_at(turbo);

	auto start_time = MQGetTickCount64();
	auto result = run_co(Coroutine);

	auto ret = LuaThreadInfo{
		PID,
		Name,
		"string",
		{},
		start_time,
		0ULL,
		{}
	};

	if (result) ret.set_result(*result);
	return ret;
}

std::pair<sol::thread_status, std::optional<sol::protected_function_result>> LuaThread::run(uint32_t turbo)
{
	if (!Thread.valid())
		return std::make_pair(sol::thread_status::dead, std::nullopt);

	if (Thread.status() != sol::thread_status::ok && Thread.status() != sol::thread_status::yielded)
	{
		return std::make_pair(Thread.status(), std::nullopt);
	}

	if (!State->should_run(*this, turbo))
		return std::make_pair(Thread.status(), std::nullopt);

	// TODO: allow the user to set "aggressive" events (which gets prepared here) and "passive" binds (which would get prepared in `doevents`)
	EventProcessor->prepare_binds();

	yield_at(turbo);

	YieldToFrame = false;
	EventProcessor->run_events(*this);

	if (!YieldToFrame)
	{
		auto result = run_co(Coroutine);
		auto status = result ? static_cast<sol::thread_status>(result->status()) : sol::thread_status::dead;
		return std::make_pair(std::move(status), std::move(result));
	}

	return std::make_pair(Thread.status(), std::nullopt);
}

void LuaThread::yield_at(int count) const
{
	lua_sethook(Thread.state(), ForceYield, count == 0 ? LUA_MASKLINE : LUA_MASKCOUNT, count);
}

std::string join(sol::this_state L, std::string delim, sol::variadic_args va)
{
	if (va.size() > 0)
	{
		fmt::memory_buffer str;
		const auto* del = "";
		for (const auto& arg : va)
		{
			auto value = luaL_tolstring(arg.lua_state(), arg.stack_index(), NULL);
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
	auto delay_int = delayObj.as<std::optional<int>>();
	if (!delay_int)
	{
		auto delay_str = delayObj.as<std::optional<std::string_view>>();
		if (delay_str)
		{
			if (delay_str->length() > 1 && delay_str->compare(delay_str->length() - 1, 1, "m") == 0)
				delay_int.emplace(GetIntFromString(*delay_str, 0) * 600);
			else if (delay_str->length() > 2 && delay_str->compare(delay_str->length() - 2, 2, "ms") == 0)
				delay_int.emplace(GetIntFromString(*delay_str, 0) / 100);
			else if (delay_str->length() > 1 && delay_str->compare(delay_str->length() - 1, 1, "s") == 0)
				delay_int.emplace(GetIntFromString(*delay_str, 0) * 10);
		}
	}

	if (delay_int)
	{
		std::optional<std::weak_ptr<mq::lua::thread::LuaThread>> thread = sol::state_view(s)["mqthread"];

		if (auto thread_ptr = thread.value_or(std::weak_ptr<mq::lua::thread::LuaThread>()).lock())
		{
			uint64_t delay_ms = std::max(0L, *delay_int * 100L);
			auto condition = conditionObj.as<std::optional<sol::function>>();
			if (!condition)
			{
				// let's accept a string too, and assume they want us to loadstring it
				auto condition_str = conditionObj.as<std::optional<std::string_view>>();
				if (condition_str)
				{
					// only allocate the string if we need to, but let's help the user and add the return to make this valid code
					// the temporary string in the else case here only needs to live long enough for the load to happen, it's
					// fine that it gets destroyed after the result here
					auto result = thread_ptr->Thread.state().load(
						condition_str->rfind("return ", 0) == 0 ?
						*condition_str :
						"return " + std::string(*condition_str));

					if (result.valid())
					{
						sol::function f = result;
						condition.emplace(f);
					}
				}
			}

			thread_ptr->State->set_delay(*thread_ptr, delay_ms + MQGetTickCount64(), condition);
		}
	}
}

void exit(sol::this_state s)
{
	std::optional<std::weak_ptr<mq::lua::thread::LuaThread>> thread = sol::state_view(s)["mqthread"];
	if (auto thread_ptr = thread.value_or(std::weak_ptr<mq::lua::thread::LuaThread>()).lock())
	{
		StatusMessage(&WriteChatf, "Exit() called in Lua script %s with PID %d", thread_ptr->Name.c_str(), thread_ptr->PID);
		thread_ptr->yield_at(0);
		thread_ptr->Thread.abandon();
	}
}

int LoadMQRequire(lua_State* L)
{
	std::string path = sol::stack::get<std::string>(L);
	if (path != "mq") return 0;

	std::optional<std::weak_ptr<mq::lua::thread::LuaThread>> thread = sol::state_view(L)["mqthread"];
	if (auto thread_ptr = thread.value_or(std::weak_ptr<mq::lua::thread::LuaThread>()).lock())
	{
		thread_ptr->GlobalTable = thread_ptr->Thread.state().create_table();

		bindings::lua_MQCommand::register_binding(*thread_ptr->GlobalTable);
		bindings::lua_MQDataItem::register_binding(*thread_ptr->GlobalTable);
		bindings::lua_MQTypeVar::register_binding(*thread_ptr->GlobalTable);

		(*thread_ptr->GlobalTable)["delay"] = &delay;
		(*thread_ptr->GlobalTable)["join"] = &join;
		(*thread_ptr->GlobalTable)["exit"] = &exit;

		events::register_lua(*thread_ptr->GlobalTable);
		imgui::register_lua(*thread_ptr->GlobalTable);

		sol::state_view(L).set("_mq_internal_table", *thread_ptr->GlobalTable);
		std::string script("return _mq_internal_table");
		luaL_loadbuffer(L, script.data(), script.size(), path.c_str());
		return 1;
	}

	return 0;
}

void LuaThread::register_lua_state(std::shared_ptr<LuaThread> self_ptr)
{
	Thread.state()["_old_require"] = Thread.state()["require"];
	Thread.state()["require"] = [this](std::string_view mod, sol::variadic_args args) {
		if (HookProtectionCount++ == 0)
			lua_sethook(Thread.state(), NULL, 0, 0);

		auto ret = Thread.state()["_old_require"](mod, args);

		if (--HookProtectionCount < 0)
			HookProtectionCount = 0;

		if (HookProtectionCount == 0)
			lua_sethook(Thread.state(), ForceYield, LUA_MASKCOUNT, 50);

		return ret;
	};

	Thread.state()["_old_dofile"] = Thread.state()["dofile"];
	Thread.state()["dofile"] = [this](std::string_view file, sol::variadic_args args) {
		if (HookProtectionCount++ == 0)
			lua_sethook(Thread.state(), NULL, 0, 0);

		auto ret = Thread.state()["_old_dofile"](file, args);

		if (--HookProtectionCount < 0)
			HookProtectionCount = 0;

		if (HookProtectionCount == 0)
			lua_sethook(Thread.state(), ForceYield, LUA_MASKCOUNT, 50);

		return ret;
	};

	Thread.state()["mqthread"] = std::weak_ptr(self_ptr);

	Thread.state().add_package_loader(LoadMQRequire);
}

void LuaThreadInfo::set_result(const sol::protected_function_result& result)
{
	if (result.status() != sol::call_status::yielded && result.return_count() > 1)
	{
		EndTime = MQGetTickCount64();
		if (result.return_count() > 1)
		{
			Return = std::vector<std::string>(result.return_count() - 1);
			// need to skip the first "return" (which is not a return, it's at index + 0) which is the function itself
			for (int i = 1; i < result.return_count(); ++i)
			{
				Return[i - 1] = luaL_tolstring(result.lua_state(), result.stack_index() + i, NULL);
			}
		}
	}
}
} // namespace mq::lua::thread
