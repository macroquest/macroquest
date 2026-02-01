/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
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

#pragma once

#include <sol/sol.hpp>
#include <optional>
#include <string>
#include <unordered_map>

namespace mq::lua {

using LuaModuleFactory = sol::object (*)(sol::this_state);

struct LuaModuleEntry
{
	explicit LuaModuleEntry(LuaModuleFactory inFactory)
		: factory(inFactory)
	{
	}

	LuaModuleFactory factory;
};

class LuaModuleRegistry
{
public:
	// Returns false if name already registered or parameters are invalid.
	bool Register(const char* name, LuaModuleFactory factory);

	// Returns empty if not found (copy by value avoids dangling references).
	std::optional<LuaModuleEntry> Find(std::string_view name) const;

private:
	std::unordered_map<std::string, LuaModuleEntry> m_modules;
};

LuaModuleRegistry& GetLuaModuleRegistry();

} // namespace mq::lua
