#pragma once

#include <sol/sol.hpp>
#include <utility>

namespace mq::lua {
void DebugStackTrace(lua_State* L);
bool DoStatus();

using Writer = void(*)(const char*, ...);
template <typename... Args>
void StatusMessage(Writer writer, const char* format, Args&&... args)
{
	if (DoStatus())
		writer(format, std::forward<Args>(args)...);
}

namespace thread {
std::string join(sol::this_state L, std::string delim, sol::variadic_args va);
}
}
