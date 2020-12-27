#pragma once

#include <sol/sol.hpp>

namespace mq::lua {
void DebugStackTrace(lua_State* L);

namespace thread {
std::string join(sol::this_state L, std::string delim, sol::variadic_args va);
}
}
