/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2020 MacroQuest Authors
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

namespace mq::lua::thread {
	struct LuaThread;
}

namespace mq::lua::imgui {

void RegisterLua(sol::table& lua);

struct LuaImGui
{
	std::string name;
	sol::function callback;

	LuaImGui(std::string_view name, const sol::function& callback);
	~LuaImGui();

	void Pulse() const;
};

struct LuaImGuiProcessor
{
	const thread::LuaThread* thread;
	std::vector<std::unique_ptr<LuaImGui>> imguis;

	LuaImGuiProcessor(const thread::LuaThread* thread);
	~LuaImGuiProcessor();

	void AddCallback(std::string_view name, sol::function callback);
	void RemoveCallback(std::string_view name);
	void Pulse() const;
};

} // namespace mq::lua::imgui
