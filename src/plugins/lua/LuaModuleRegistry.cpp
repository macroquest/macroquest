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

#include "pch.h"
#include "LuaModuleRegistry.h"

namespace mq::lua {

LuaModuleRegistry& GetLuaModuleRegistry()
{
	static LuaModuleRegistry s_registry;
	return s_registry;
}

bool LuaModuleRegistry::Register(const char* name, LuaModuleFactory factory)
{
	if (!name || !name[0] || !factory)
		return false;

	auto [it, inserted] = m_modules.try_emplace(name, factory);
	return inserted;
}

std::optional<LuaModuleEntry> LuaModuleRegistry::Find(std::string_view name) const
{
	auto it = m_modules.find(std::string(name));
	if (it == m_modules.end())
		return std::nullopt;

	return it->second;
}

} // namespace mq::lua
