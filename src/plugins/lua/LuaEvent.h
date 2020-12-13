#pragma once

#include "LuaCommon.h"

#include <queue>

class Blech;

namespace mq::lua::thread {
struct LuaThread;
}

namespace mq::lua::events {
struct LuaEvent
{
	std::string Name;
	std::string Expression;
	sol::function Function;
	thread::LuaThread const* Thread;
	uint32_t ID;

	bool run(const std::vector<std::string> args) const;
};

struct LuaEventInstance
{
	LuaEvent* EventDefinition;
	std::vector<std::string> Args;
};

struct LuaEventProcessor
{
	std::unique_ptr<Blech> EventBlech;
	std::vector<LuaEvent*> EventDefinitions;
	std::queue<LuaEventInstance> EventQueue;

	LuaEventProcessor();
	~LuaEventProcessor();

	void add_event(std::string_view name, std::string_view expression, const sol::function& function, const thread::LuaThread& thread);
	void remove_event(std::string_view name);
	void process(std::string_view line, const thread::LuaThread& thread) const;
	void run_events(const thread::LuaThread& thread);
};
}
