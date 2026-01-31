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

bool LuaModuleRegistry::Register(const char* name, LuaModuleFactory factory, MQPluginHandle owner, const char* ownerName)
{
	if (!name || !name[0] || !factory)
		return false;

	std::scoped_lock lock(m_mutex);

	if (m_modules.find(name) != m_modules.end())
		return false;

	LuaModuleEntry entry{
		factory,
		owner,
		ownerName ? ownerName : ""
	};
	m_modules.emplace(name, std::move(entry));
	return true;
}

bool LuaModuleRegistry::Unregister(const char* name, MQPluginHandle owner)
{
	if (!name || !name[0])
		return false;

	std::scoped_lock lock(m_mutex);

	auto it = m_modules.find(name);
	if (it == m_modules.end())
		return false;

	if (it->second.owner != owner)
		return false;

	m_modules.erase(it);
	return true;
}

std::optional<LuaModuleEntry> LuaModuleRegistry::Find(const std::string& name) const
{
	std::scoped_lock lock(m_mutex);

	auto it = m_modules.find(name);
	if (it == m_modules.end())
		return std::nullopt;

	return it->second;
}

bool LuaModuleRegistry::IsRegistered(const std::string& name) const
{
	std::scoped_lock lock(m_mutex);
	return m_modules.find(name) != m_modules.end();
}

void LuaModuleRegistry::UnregisterAll(MQPluginHandle owner)
{
	std::scoped_lock lock(m_mutex);

	for (auto it = m_modules.begin(); it != m_modules.end();)
	{
		if (it->second.owner == owner)
			it = m_modules.erase(it);
		else
			++it;
	}
}

void LuaModuleRegistry::UnregisterAllByName(std::string_view ownerName)
{
	if (ownerName.empty())
		return;

	std::scoped_lock lock(m_mutex);

	for (auto it = m_modules.begin(); it != m_modules.end();)
	{
		if (it->second.ownerName == ownerName)
			it = m_modules.erase(it);
		else
			++it;
	}
}

} // namespace mq::lua
