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

#include <mq/Plugin.h>

#if !defined(SOL_LUAJIT)
#define SOL_LUAJIT 1
#endif

#include <sol/sol.hpp>
#include <memory>

namespace mq::lua {

class LuaThread;
using LuaScript = LuaThread;
using LuaScriptPtr = std::shared_ptr<LuaScript>;

class LuaPluginInterface : public PluginInterface
{
public:
	// Create a new lua thread that can be used to execute some lua.
	virtual LuaScriptPtr CreateLuaScript() = 0;

	// Terminate a lua thread
	virtual void DestroyLuaScript(const LuaScriptPtr& scriptPtr) = 0;

	// Executes a lua script file
	virtual void ExecuteFile(const LuaScriptPtr& scriptPtr, std::string_view filename, const std::vector<std::string>& arguments = {}) = 0;

	// Execute a lua script
	virtual void ExecuteString(const LuaScriptPtr& scriptPtr, std::string_view script, std::string_view name = "") = 0;

	// Change the turbo value for a thread
	virtual void SetTurbo(const LuaScriptPtr& scriptPtr, uint32_t turbo) = 0;

	// Inject the mq namespace into the thread automatically
	virtual void InjectMQNamespace(const LuaScriptPtr& scriptPtr) = 0;

	// Check if thread is paused
	virtual bool IsPaused(const LuaScriptPtr& scriptPtr) = 0;

	// Get the pid for a thread.
	virtual int GetPid(const LuaScriptPtr& scriptPtr) = 0;

	// Get the name for a thread.
	virtual const std::string& GetName(const LuaScriptPtr& scriptPtr) = 0;

	// Get the lua state for a thread
	virtual sol::state_view GetLuaState(const LuaScriptPtr& scriptPtr) = 0;

};

// Convenience function to get the Lua interface from MQ2Lua.
inline LuaPluginInterface* GetLuaInterface()
{
	return static_cast<LuaPluginInterface*>(GetPluginInterface("Lua"));
}

} // namespace mq::lua
