#include "LuaThread.h"
#include "LuaEvent.h"

#include <mq/Plugin.h>

using namespace mq::lua::thread;

// this is the special sauce that lets us execute everything on the main thread without blocking
static void ForceYield(lua_State* L, lua_Debug* D)
{
	lua_yield(L, 0);
}

bool ThreadState::check_condition(const std::shared_ptr<LuaThread>& thread, std::optional<sol::function>& func)
{
	if (func)
	{
		try
		{
			auto check = sol::function(thread->GlobalState, *func);
			thread->Environment.set_on(check);
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

bool RunningState::should_run(const std::shared_ptr<LuaThread>& thread, uint32_t turbo)
{
	// check delayed status here
	bool delay_condition = check_condition(thread, m_delayCondition);

	if (m_delayTime <= MQGetTickCount64() || delay_condition)
	{
		lua_sethook(thread->Thread.state(), ForceYield, LUA_MASKCOUNT, turbo);
		m_delayTime = 0L;
		m_delayCondition = std::nullopt;
		return true;
	}

	return false;
}

void RunningState::set_delay(const std::shared_ptr<LuaThread>& thread, uint64_t time, std::optional<sol::function> condition)
{
	bool delay_condition = check_condition(thread, condition);

	if (time > MQGetTickCount64() && !delay_condition)
	{
		lua_sethook(thread->Thread.state(), ForceYield, LUA_MASKLINE, 0);
		m_delayTime = time;
		m_delayCondition = condition;
	}
}

void RunningState::pause(const std::shared_ptr<LuaThread>& thread, uint32_t)
{
	// this will force the coroutine to yield, and removing this thread from the vector will cause it to gc
	lua_sethook(thread->Thread.state(), ForceYield, LUA_MASKLINE, 0);
	WriteChatf("Pausing running lua script '%s' with PID %d", thread->Name.c_str(), thread->PID);
	thread->State = std::make_unique<PausedState>();
}

void PausedState::pause(const std::shared_ptr<LuaThread>& thread, uint32_t turbo)
{
	lua_sethook(thread->Thread.state(), ForceYield, LUA_MASKCOUNT, turbo);
	WriteChatf("Resuming paused lua script '%s' with PID %d", thread->Name.c_str(), thread->PID);
	thread->State = std::make_unique<RunningState>();
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

int LuaThread::start_file(std::string_view luaDir, uint32_t turbo, const std::vector<std::string>& args)
{
	auto script_path = std::filesystem::path(Name);
	if (script_path.is_relative()) script_path = luaDir / script_path;
	if (!script_path.has_extension()) script_path += ".lua";

	register_lua_state();

	//sol::coroutine co = Thread.state().load_file(script_path.string());
	MainCoroutine = Thread.state().load_file(script_path.string());
	yield_at(turbo);

	auto result = MainCoroutine(sol::as_args(args));
	if (result.valid())
		return static_cast<int>(result.status());

	sol::error err = std::move(result);
	throw err;
}

int LuaThread::start_string(uint32_t turbo, std::string_view script)
{
	MainCoroutine = Thread.state().load(script);
	yield_at(turbo);

	auto result = MainCoroutine();
	if (result.valid())
		return static_cast<int>(result.status());

	sol::error err = std::move(result);
	throw err;
}

void LuaThread::yield_at(int count)
{
	lua_sethook(Thread.state(), ForceYield, LUA_MASKCOUNT, count);
}

void LuaThread::register_lua_state()
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
}
