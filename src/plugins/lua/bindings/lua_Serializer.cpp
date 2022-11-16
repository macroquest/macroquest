/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2022 MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "pch.h"

#include "LuaCommon.h"
#include "LuaThread.h"

#include <mq/Plugin.h>

namespace mq::lua {
static std::string serialize(sol::object obj)
{
	switch (obj.get_type())
	{
	case sol::type::lua_nil:
		return "nil";
	case sol::type::string:
		if (ci_find_substr(obj.as<std::string_view>(), "'"))
			return fmt::format("\"{}\"", obj.as<std::string_view>());

		return fmt::format("'{}'", obj.as<std::string_view>());
	case sol::type::number:
		if (obj.is<int>())
			return std::to_string(obj.as<int64_t>());

		return std::to_string(obj.as<double>());
	case sol::type::boolean:
		return std::to_string(obj.as<bool>());
	case sol::type::table:
	{
		fmt::memory_buffer buf;
		fmt::format_to(fmt::appender(buf), "{ ");

		for (const auto& [key, val] : obj.as<sol::table>())
		{
			fmt::format_to(fmt::appender(buf), "{} = {}", serialize(key), serialize(val));
		}

		fmt::format_to(fmt::appender(buf), " }");
	}
	// keep these here as reference. We don't want to serialize these things though, so they will all fall through to default (no serialization)
	case sol::type::none:
	case sol::type::thread:
	case sol::type::function:
	case sol::type::userdata:
	case sol::type::lightuserdata:
	case sol::type::poly:
	default:
		return "";
	}
}

} // namespace mq::lua
