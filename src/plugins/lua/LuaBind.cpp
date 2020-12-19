#include "LuaBind.h"
#include "LuaThread.h"

#include <mq/Plugin.h>

namespace mq::lua::binds {
// this vector is just to make sure we don't double-bind -- TODO: do we care? so what if multiple things get queued to run?
static std::vector<std::string_view> s_currentBinds;

bool LuaBind::run(const std::vector<std::string> args) const
{
	return false;
}

void LuaBind::add_bind(std::string_view name, const sol::function& callback)
{
}
}
