#pragma once

#include "LuaCommon.h"

#include <queue>

class Blech;

namespace mq::lua::thread {
struct LuaThread;
struct ThreadState;
}

namespace mq::lua::events {
struct LuaEvent
{
	std::string Name;
	std::string Expression;
	sol::function Function;
	std::weak_ptr<thread::LuaThread> Thread;
	uint32_t ID;
};

struct LuaEventInstance
{
	LuaEvent* Definition;
	std::vector<std::string> Args;
	sol::thread Thread;
};

struct LuaEventProcessor
{
	std::unique_ptr<Blech> Trie;
	std::vector<LuaEvent*> Definitions;
	std::vector<LuaEventInstance> Pending;
	std::vector<std::pair<sol::coroutine, std::vector<std::string>>> Running;

	LuaEventProcessor();
	~LuaEventProcessor();

	void add_event(std::string_view name, std::string_view expression, const sol::function& function, const std::shared_ptr<thread::LuaThread>& thread);
	void remove_event(std::string_view name);
	void process(std::string_view line) const;
	void run_events(const thread::LuaThread& thread);
	void prepare_events();
};
}
