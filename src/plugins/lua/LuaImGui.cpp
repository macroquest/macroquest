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
	: thread(thread)
{
}

LuaImGuiProcessor::~LuaImGuiProcessor()
{
}

void LuaImGuiProcessor::AddCallback(std::string_view name, sol::function callback)
{
	auto im_thread = sol::thread::create(thread->thread.state());
	sol_ImGui::Init(im_thread.state());
	imguis.emplace_back(new LuaImGui(name, im_thread, callback));
}

void LuaImGuiProcessor::RemoveCallback(std::string_view name)
{
	imguis.erase(std::remove_if(imguis.begin(), imguis.end(), [&name](const std::unique_ptr<LuaImGui>& im)
		{
			return im->name == name;
		}), imguis.end());
}

void LuaImGuiProcessor::Pulse() const
{
	// remove any existing hooks, they will be re-installed when running in onpulse
	lua_sethook(thread->thread.lua_state(), nullptr, 0, 0);

	for (auto& im : imguis)
		im->Pulse();
}

static void addimgui(std::string_view name, sol::function function, sol::this_state s)
{
	if (auto thread_ptr = thread::LuaThread::get_from(s))
	{
		thread_ptr->imguiProcessor->AddCallback(name, function);
	}
}

static void removeimgui(std::string_view name, sol::this_state s)
{
	if (auto thread_ptr = thread::LuaThread::get_from(s))
	{
		thread_ptr->imguiProcessor->RemoveCallback(name);
	}
}

void RegisterLua(sol::table& lua)
{
	lua["imgui"] = lua.create_with(
		"init", &addimgui,
		"destroy", &removeimgui
	);
}

LuaImGui::LuaImGui(std::string_view name, const sol::thread& thread, const sol::function& callback)
	: name(name), thread(thread), callback(callback)
{
}

LuaImGui::~LuaImGui()
{
}

void LuaImGui::Pulse() const
{
	try
	{
		auto result = sol::function(thread.state(), callback)();
		if (!result.valid())
		{
			sol::error err = std::move(result);
			throw err;
		}
	}
	catch (sol::error& e)
	{
		LuaError("ImGui Failure:\n%s", e.what());
	}
}

} // namespace mq::lua::imgui
