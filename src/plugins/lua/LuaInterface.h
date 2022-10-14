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

#pragma once

#include <mq/Plugin.h>

#if !defined(SOL_LUAJIT)
#define SOL_LUAJIT 1
#endif

#include <sol/sol.hpp>
#include <memory>

namespace mq::lua {

class LuaThread;
using LuaThreadPtr = std::shared_ptr<LuaThread>;

class LuaPluginInterface : public PluginInterface
{
public:
	// Create a new lua thread that can be used to execute some lua.
	virtual LuaThreadPtr CreateLuaScript() = 0;

	// Terminate a lua thread
	virtual void DestroyLuaScript(const LuaThreadPtr& scriptPtr) = 0;

	// Executes a lua script file
	virtual void ExecuteFile(const LuaThreadPtr& scriptPtr, std::string_view filename, const std::vector<std::string>& arguments = {}) = 0;

	// Execute a lua script
	virtual void ExecuteString(const LuaThreadPtr& scriptPtr, std::string_view script, std::string_view name = "") = 0;

	// Change the turbo value for a thread
	virtual void SetTurbo(const LuaThreadPtr& scriptPtr, uint32_t turbo) = 0;

	// Inject the mq namespace into the thread automatically
	virtual void InjectMQNamespace(const LuaThreadPtr& scriptPtr) = 0;

	// Check if thread is paused
	virtual bool IsPaused(const LuaThreadPtr& scriptPtr) = 0;

	// Get the pid for a thread.
	virtual int GetPid(const LuaThreadPtr& scriptPtr) = 0;

	// Get the name for a thread.
	virtual const std::string& GetName(const LuaThreadPtr& scriptPtr) = 0;

	// Get the lua state for a thread
	virtual sol::state_view GetLuaState(const LuaThreadPtr& scriptPtr) = 0;
};

} // namespace mq::lua
