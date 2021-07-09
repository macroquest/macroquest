/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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

#include "LuaCommon.h"

namespace mq::lua {

struct LuaThread;

// Register ImGui
void ImGui_RegisterLua(sol::state_view state);

// Register imgui commands in mq namespace
void MQ_RegisterLua_ImGui(sol::table& lua);

class LuaImGui
{
public:
	LuaImGui(std::string_view name, const sol::thread& parent_thread, const sol::function& callback);
	~LuaImGui();

	bool Pulse() const;
	std::string_view GetName() { return m_name; }

private:
	std::string m_name;
	sol::thread m_thread;
	sol::function m_callback;
	mutable sol::coroutine m_coroutine;
	sol::thread m_parentThread;
};

struct LuaImGuiProcessor
{
	const LuaThread* thread;
	std::vector<std::unique_ptr<LuaImGui>> imguis;

	LuaImGuiProcessor(const LuaThread* thread);
	~LuaImGuiProcessor();

	void AddCallback(std::string_view name, sol::function callback);
	void RemoveCallback(std::string_view name);
	bool HasCallback(std::string_view name);
	void Pulse();
};

} // namespace mq::lua
