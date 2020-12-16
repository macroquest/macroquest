#pragma once

#include <sol/sol.hpp>

namespace mq::lua::events {
struct LuaEventProcessor;
}

namespace mq::lua::thread {

struct ThreadState;
struct LuaThread
{
	sol::thread Thread;
	sol::coroutine MainCoroutine;
	sol::state_view GlobalState;
	sol::environment Environment;
	std::string Name;
	std::unique_ptr<ThreadState> State;
	std::unique_ptr<events::LuaEventProcessor> EventProcessor;
	uint32_t PID;

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
	//LuaThread(LuaThread&&) noexcept;
	LuaThread(LuaThread&&) = delete;
	LuaThread& operator=(const LuaThread&) = delete;
	//LuaThread& operator=(LuaThread&&) noexcept;
	LuaThread& operator=(LuaThread&&) = delete;

	int start_file(std::string_view luaDir, uint32_t turbo, const std::vector<std::string>& args);
	int start_string(uint32_t turbo, std::string_view script);
	void yield_at(int count);

	void register_lua_state();
};

struct ThreadState
{
	virtual bool should_run(const std::shared_ptr<LuaThread>& thread, uint32_t turbo) = 0;
	virtual bool is_paused() = 0;
	virtual void set_delay(const std::shared_ptr<LuaThread>& thread, uint64_t time, std::optional<sol::function> condition = std::nullopt) = 0;
	virtual void pause(const std::shared_ptr<LuaThread>& thread, uint32_t turbo) = 0;

	static bool check_condition(const std::shared_ptr<LuaThread>& thread, std::optional<sol::function>& func);
};

struct RunningState : public ThreadState
{
	bool should_run(const std::shared_ptr<LuaThread>& thread, uint32_t turbo) override;
	bool is_paused() override { return false; }
	void set_delay(const std::shared_ptr<LuaThread>& thread, uint64_t time, std::optional<sol::function> condition = std::nullopt) override;
	void pause(const std::shared_ptr<LuaThread>&, uint32_t) override;

private:
	uint64_t m_delayTime = 0L;
	std::optional<sol::function> m_delayCondition = std::nullopt;
};

struct PausedState : public ThreadState
{
	bool should_run(const std::shared_ptr<LuaThread>&, uint32_t) override { return false; }
	bool is_paused() override { return true; }
	void set_delay(const std::shared_ptr<LuaThread>& thread, uint64_t time, std::optional<sol::function> condition = std::nullopt) override {}
	void pause(const std::shared_ptr<LuaThread>& thread, uint32_t turbo) override;
};

} // namespace mq::lua::thread
