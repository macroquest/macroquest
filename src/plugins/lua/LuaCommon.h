#pragma once

#include <sol/sol.hpp>

namespace mq::lua {
void DebugStackTrace(lua_State* L);
std::string join(sol::this_state L, std::string delim, sol::variadic_args va);
void delay(sol::object delayObj, sol::object conditionObj, sol::this_state s);
}
