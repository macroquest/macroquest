#pragma once

#include <sol/sol.hpp>
#include <stack>

namespace mq::lua::events {
struct LuaEventProcessor;
}

namespace mq::lua::thread {

sol::thread_status run_co(sol::coroutine& co, const std::vector<std::string>& args = {});

struct ThreadState;
struct LuaThread
{
	sol::thread Thread;
	sol::coroutine Coroutine;
	sol::state_view GlobalState;
	sol::environment Environment;
	std::string Name;
	std::unique_ptr<ThreadState> State;
	std::unique_ptr<events::LuaEventProcessor> EventProcessor;
	uint32_t PID;
	bool YieldToFrame;

	uint32_t HookProtectionCount;

	static uint32_t next_id()
	{
		// no need to do anything special, this will be fine
		static uint32_t current = 0;
		return ++current;
	}

	LuaThread(const sol::state_view& state, std::string_view name);
	LuaThread() = delete;
	LuaThread(const LuaThread&) = delete;
	LuaThread(LuaThread&&) = delete;
	LuaThread& operator=(const LuaThread&) = delete;
	LuaThread& operator=(LuaThread&&) = delete;

	sol::thread_status start_file(std::string_view luaDir, uint32_t turbo, const std::vector<std::string>& args);
	sol::thread_status start_string(uint32_t turbo, std::string_view script);
	sol::thread_status run(uint32_t turbo);
	void yield_at(int count) const;

	void register_lua_state(std::shared_ptr<LuaThread> self_ptr);
};

struct ThreadState
{
	virtual bool should_run(const LuaThread& thread, uint32_t turbo) = 0;
	virtual bool is_paused() = 0;
	virtual void set_delay(const LuaThread& thread, uint64_t time, std::optional<sol::function> condition = std::nullopt) = 0;
	virtual void pause(LuaThread& thread, uint32_t turbo) = 0;

	static bool check_condition(const LuaThread& thread, std::optional<sol::function>& func);
};

struct RunningState : public ThreadState
{
	bool should_run(const LuaThread& thread, uint32_t turbo) override;
	bool is_paused() override { return false; }
	void set_delay(const LuaThread& thread, uint64_t time, std::optional<sol::function> condition = std::nullopt) override;
	void pause(LuaThread&, uint32_t) override;

private:
	uint64_t m_delayTime = 0L;
	std::optional<sol::function> m_delayCondition = std::nullopt;
};

struct PausedState : public ThreadState
{
	bool should_run(const LuaThread&, uint32_t) override { return false; }
	bool is_paused() override { return true; }
	void set_delay(const LuaThread& thread, uint64_t time, std::optional<sol::function> condition = std::nullopt) override {}
	void pause(LuaThread& thread, uint32_t turbo) override;
};

} // namespace mq::lua::thread
