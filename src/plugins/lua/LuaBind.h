#pragma once

#include "LuaCommon.h"

namespace mq::lua::thread {
struct LuaThread;
}

namespace mq::lua::binds {
struct LuaBind
{
	std::string Name;
	sol::function Function;
	std::weak_ptr<thread::LuaThread> Thread;

	bool run(const std::vector<std::string> args) const;
	static void add_bind(std::string_view name, const sol::function& callback);
};
}
