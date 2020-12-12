#include "LuaThread.h"
#include "LuaEvent.h"

#include <mq/Plugin.h>

using namespace mq::lua::thread;

// this is the special sauce that lets us execute everything on the main thread without blocking
static void ForceYield(lua_State* L, lua_Debug* D)
{
	lua_yield(L, 0);
}

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
	bool delay_condition = check_condition(thread, m_delayCondition);

	if (m_delayTime <= MQGetTickCount64() || delay_condition)
	{
		lua_sethook(thread.Thread.state(), ForceYield, LUA_MASKCOUNT, turbo);
		m_delayTime = 0L;
		m_delayCondition = std::nullopt;
		return true;
	}

	return false;
}

void RunningState::set_delay(const LuaThread& thread, uint64_t time, std::optional<sol::function> condition)
{
	bool delay_condition = check_condition(thread, condition);

	if (time > MQGetTickCount64() && !delay_condition)
	{
		lua_sethook(thread.Thread.state(), ForceYield, LUA_MASKLINE, 0);
		m_delayTime = time;
		m_delayCondition = condition;
	}
}

void RunningState::pause(LuaThread& thread, uint32_t)
{
	// this will force the coroutine to yield, and removing this thread from the vector will cause it to gc
	lua_sethook(thread.Thread.state(), ForceYield, LUA_MASKLINE, 0);
	WriteChatf("Pausing running lua script '%s' with PID %d", thread.Name.c_str(), thread.PID);
	thread.State = std::make_unique<PausedState>();
}

void PausedState::pause(LuaThread& thread, uint32_t turbo)
{
	lua_sethook(thread.Thread.state(), ForceYield, LUA_MASKCOUNT, turbo);
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
	PID(next_id())
{
	Environment.set_on(Thread);
}

LuaThread::LuaThread(LuaThread&& other) noexcept :
	Thread(std::move(other.Thread)),
	GlobalState(std::move(other.GlobalState)),
	Environment(std::move(other.Environment)),
	Name(std::move(other.Name)),
	State(std::move(other.State)),
	EventProcessor(std::move(other.EventProcessor)),
	PID(std::move(other.PID))
{
	Environment.set_on(Thread);
}

LuaThread& LuaThread::operator=(LuaThread&& other) noexcept
{
	if (this != &other)
	{
		Thread = std::move(other.Thread);
		GlobalState = std::move(other.GlobalState);
		Environment = std::move(other.Environment);
		Name = std::move(other.Name);
		State = std::move(other.State);
		EventProcessor = std::move(other.EventProcessor);
		PID = std::move(other.PID);

		Environment.set_on(Thread);
	}

	return *this;
}

int LuaThread::start_file(std::string_view luaDir, uint32_t turbo, const std::vector<std::string>& args)
{
	auto script_path = std::filesystem::path(Name);
	if (script_path.is_relative()) script_path = luaDir / script_path;
	if (!script_path.has_extension()) script_path += ".lua";

	sol::coroutine co = Thread.state().load_file(script_path.string());
	yield_at(turbo);

	auto result = co(sol::as_args(args));
	return static_cast<int>(result.status());
}

int LuaThread::start_string(uint32_t turbo, std::string_view script)
{
	sol::coroutine co = Thread.state().load(script);
	yield_at(turbo);

	auto result = co();
	return static_cast<int>(result.status());
}

void LuaThread::yield_at(int count)
{
	lua_sethook(Thread.state(), ForceYield, LUA_MASKCOUNT, count);
}
