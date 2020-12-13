#pragma once

#include "LuaCommon.h"

namespace mq::lua::bindings {
struct lua_MQCommand
{
	std::string Command;
	lua_MQCommand(std::string_view command) : Command(command) {}
	void operator()(sol::variadic_args va, sol::this_state s);
	static void register_binding(sol::state& lua);
};

struct lua_MQDoCommand
{
	// this is only used to provide a namespace for commands
	sol::object get(sol::stack_object key, sol::this_state L) const;
};
}
