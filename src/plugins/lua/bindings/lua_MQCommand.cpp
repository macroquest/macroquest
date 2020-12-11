#include "lua_MQCommand.h"

#include <mq/Plugin.h>

using namespace mq::lua;
using namespace mq::lua::bindings;

void lua_MQCommand::operator()(sol::variadic_args va)
{
	std::stringstream cmd;
	cmd << Command;
	for (const auto& a : va)
	{
		auto value = luaL_tolstring(a.lua_state(), a.stack_index(), NULL);
		if (value != nullptr && strlen(value) > 0)
			cmd << " " << value;
	}

	HideDoCommand(pLocalPlayer, cmd.str().c_str(), false);
}

sol::object lua_MQDoCommand::get(sol::stack_object key, sol::this_state L) const
{
	auto maybe_key = key.as<std::optional<std::string>>();
	if (maybe_key)
	{
		std::string cmd("/");
		cmd += *maybe_key;
		if (IsCommand(cmd.c_str()))
			return sol::object(L, sol::in_place, lua_MQCommand(cmd));
	}

	return sol::object(L, sol::in_place, sol::lua_nil);
}

void mq::lua::bindings::lua_MQCommand::register_binding(sol::state& lua)
{
	lua.new_usertype<lua_MQCommand>("mqcommand",
		sol::no_constructor);

	lua.new_usertype<lua_MQDoCommand>("mqdocommand",
		sol::no_constructor,
		sol::meta_function::index, &lua_MQDoCommand::get);

	lua["cmd"] = lua_MQDoCommand();
}
