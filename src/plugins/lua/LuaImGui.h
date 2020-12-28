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

void register_lua(sol::table& lua);

struct LuaImGui
{
	std::string Name;
	sol::function Callback;

	LuaImGui(std::string_view name, const sol::function& callback);
	~LuaImGui();

	void pulse() const;
};

struct LuaImGuiProcessor
{
	const thread::LuaThread* Thread;
	std::vector<std::unique_ptr<LuaImGui>> ImGuis;

	LuaImGuiProcessor(const thread::LuaThread* thread);
	~LuaImGuiProcessor();

	void add_callback(std::string_view name, sol::function callback);
	void remove_callback(std::string_view name);
	void pulse() const;
};

} // namespace mq::lua::imgui
