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

#include "LuaImGui.h"
#include "LuaThread.h"

#include "contrib/imgui/sol_ImGui.h"

#include <mq/Plugin.h>

namespace mq::lua::imgui {

LuaImGuiProcessor::LuaImGuiProcessor(const thread::LuaThread* thread)
	: Thread(thread)
{}

LuaImGuiProcessor::~LuaImGuiProcessor() {}

void LuaImGuiProcessor::add_callback(std::string_view name, sol::function callback)
{
	auto im_state = sol::thread::create(Thread->Thread.state()).state();
	sol_ImGui::Init(im_state);
	ImGuis.emplace_back(new LuaImGui(name, sol::function(im_state, callback)));
}

void LuaImGuiProcessor::remove_callback(std::string_view name)
{
	ImGuis.erase(std::remove_if(ImGuis.begin(), ImGuis.end(), [&name](const std::unique_ptr<LuaImGui>& im)
		{
			return im->Name == name;
		}), ImGuis.end());
}

void LuaImGuiProcessor::pulse() const
{
	for (auto& im : ImGuis)
		im->pulse();
}

static void addimgui(std::string_view name, sol::function function, sol::this_state s)
{
	std::optional<std::weak_ptr<mq::lua::thread::LuaThread>> thread = sol::state_view(s)["mqthread"];
	if (auto thread_ptr = thread.value_or(std::weak_ptr<mq::lua::thread::LuaThread>()).lock())
		thread_ptr->ImGuiProcessor->add_callback(name, function);
}

static void removeimgui(std::string_view name, sol::this_state s)
{
	std::optional<std::weak_ptr<mq::lua::thread::LuaThread>> thread = sol::state_view(s)["mqthread"];
	if (auto thread_ptr = thread.value_or(std::weak_ptr<mq::lua::thread::LuaThread>()).lock())
		thread_ptr->ImGuiProcessor->remove_callback(name);
}

void register_lua(sol::table& lua)
{
	lua["imgui"] = lua.create_with(
		"init", &addimgui,
		"destroy", &removeimgui
	);
}

LuaImGui::LuaImGui(std::string_view name, const sol::function& callback) :
	Name(name), Callback(callback) {}

LuaImGui::~LuaImGui() {}

void LuaImGui::pulse() const
{
	try
	{
		lua_sethook(Callback.lua_state(), NULL, 0, 0); // remove any existing hooks, they will be re-installed when running in onpulse
		auto result = Callback();
		if (!result.valid())
		{
			sol::error err = std::move(result);
			throw err;
		}
	}
	catch (sol::error& e)
	{
		MacroError("ImGui Failure:\n%s", e.what());
	}
}

} // namespace mq::lua::imgui
