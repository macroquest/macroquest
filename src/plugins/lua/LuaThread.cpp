#include "LuaThread.h"
#include "LuaEvent.h"

#include <mq/Plugin.h>

// this is the special sauce that lets us execute everything on the main thread without blocking
static void ForceYield(lua_State* L, lua_Debug* D)
{
	std::optional<std::weak_ptr<mq::lua::thread::LuaThread>> thread = sol::state_view(L)["mqthread"];
	if (thread && !thread->expired())
		thread->lock()->YieldToFrame = true;

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
	WriteChatf("Pausing running lua script '%s' with PID %d", thread.Name.c_str(), thread.PID);
	thread.State = std::make_unique<PausedState>();
}

void PausedState::pause(LuaThread& thread, uint32_t turbo)
{
	thread.yield_at(turbo);
	WriteChatf("Resuming paused lua script '%s' with PID %d", thread.Name.c_str(), thread.PID);
	thread.State = std::make_unique<RunningState>();
}

LuaThread::LuaThread(const sol::state_view& state, std::string_view name) :
	Thread(sol::thread::create(state)),
	GlobalState(state),
	Environment(sol::environment(state, sol::create, state.globals())),
	Name(name),
	State(std::make_unique<RunningState>()),
	EventProcessor(std::make_unique<events::LuaEventProcessor>()),
	PID(next_id()),
	HookProtectionCount(0)
{
	Environment.set_on(Thread);
}

sol::thread_status run_co(sol::coroutine& co, const std::vector<std::string>& args)
{
	try
	{
		auto result = co(sol::as_args(args));
		if (result.valid())
			return static_cast<sol::thread_status>(result.status());

		sol::error err = std::move(result);
		throw err;
	}
	catch (sol::error& e)
	{
		MacroError("%s", e.what());
		DebugStackTrace(co.lua_state());
	}

	return sol::thread_status::runtime;
}

sol::thread_status LuaThread::start_file(std::string_view luaDir, uint32_t turbo, const std::vector<std::string>& args)
{
	auto script_path = std::filesystem::path(Name);
	if (script_path.is_relative()) script_path = luaDir / script_path;
	if (!script_path.has_extension()) script_path += ".lua";

	Coroutine = Thread.state().load_file(script_path.string());
	yield_at(turbo);

	run_co(Coroutine, args);
	return Thread.status();
}

sol::thread_status LuaThread::start_string(uint32_t turbo, std::string_view script)
{
	Coroutine = Thread.state().load(script);
	yield_at(turbo);

	run_co(Coroutine);
	return Thread.status();
}

sol::thread_status LuaThread::run(uint32_t turbo)
{
	if (!Thread.valid())
		return sol::thread_status::dead;

	if (Thread.status() != sol::thread_status::ok && Thread.status() != sol::thread_status::yielded)
	{
		MacroError("Detected invalid thread status in %s: %d", Name.c_str(), static_cast<int>(Thread.status()));
		return Thread.status();
	}

	if (!State->should_run(*this, turbo))
		return Thread.status();

	yield_at(turbo);

	YieldToFrame = false;
	EventProcessor->run_events(*this);

	if (!YieldToFrame)
		run_co(Coroutine);

	return Thread.status();
}

void LuaThread::yield_at(int count) const
{
	lua_sethook(Thread.state(), ForceYield, count == 0 ? LUA_MASKLINE : LUA_MASKCOUNT, count);
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
}
}
