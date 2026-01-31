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

#include "LuaInterface.h"

#include <mq/Plugin.h>
#include <optional>
#include <mutex>
#include <string>
#include <unordered_map>

namespace mq::lua {

struct LuaModuleEntry
{
	LuaModuleFactory factory;
	MQPluginHandle owner;
	std::string ownerName;
};

class LuaModuleRegistry
{
public:
	// Returns false if name already registered or parameters are invalid.
	bool Register(const char* name, LuaModuleFactory factory, MQPluginHandle owner, const char* ownerName);

	// Returns false if caller is not owner or name not found.
	bool Unregister(const char* name, MQPluginHandle owner);

	// Returns empty if not found (copy by value avoids dangling references).
	std::optional<LuaModuleEntry> Find(const std::string& name) const;

	// Check if module exists.
	bool IsRegistered(const std::string& name) const;

	// Unregister all modules owned by a plugin.
	void UnregisterAll(MQPluginHandle owner);

	// Unregister all modules owned by a plugin name.
	void UnregisterAllByName(std::string_view ownerName);

private:
	mutable std::mutex m_mutex;
	std::unordered_map<std::string, LuaModuleEntry> m_modules;
};

LuaModuleRegistry& GetLuaModuleRegistry();

} // namespace mq::lua
