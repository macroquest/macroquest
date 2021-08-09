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

#include "pch.h"
#include "LuaImGui.h"
#include "LuaThread.h"
#include "contrib/imgui/sol_ImGui.h"

#include <mq/Plugin.h>
#include <mq/imgui/Widgets.h>

namespace mq::lua {

//============================================================================

LuaImGuiProcessor::LuaImGuiProcessor(const LuaThread* thread)
	: m_thread(thread)
{
}

LuaImGuiProcessor::~LuaImGuiProcessor()
{
}

void LuaImGuiProcessor::AddCallback(std::string_view name, sol::function callback)
{
	m_imguis.emplace_back(new LuaImGui(name, m_thread->GetLuaThread(), callback));
}

void LuaImGuiProcessor::RemoveCallback(std::string_view name)
{
	m_imguis.erase(std::remove_if(m_imguis.begin(), m_imguis.end(),
		[&name](const std::unique_ptr<LuaImGui>& im) { return im->GetName() == name; }), m_imguis.end());
}

bool LuaImGuiProcessor::HasCallback(std::string_view name)
{
	return std::find_if(m_imguis.cbegin(), m_imguis.cend(),
		[&name](const std::unique_ptr<LuaImGui>& im) { return im->GetName() == name; }
	) != m_imguis.cend();
}

void LuaImGuiProcessor::Pulse()
{
	// remove any existing hooks, they will be re-installed when running in onpulse
	lua_sethook(m_thread->GetLuaThread().lua_state(), nullptr, 0, 0);

	for (std::unique_ptr<LuaImGui>& im : m_imguis)
	{
		if (!im->Pulse())
			RemoveCallback(im->GetName());
	}
}

//============================================================================

static void lua_addimgui(std::string_view name, sol::function function, sol::this_state s)
{
	if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s))
	{
		if (LuaImGuiProcessor* imgui = thread_ptr->GetImGuiProcessor())
			imgui->AddCallback(name, function);
	}
}

static void lua_removeimgui(std::string_view name, sol::this_state s)
{
	if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s))
	{
		if (LuaImGuiProcessor* imgui = thread_ptr->GetImGuiProcessor())
			imgui->RemoveCallback(name);
	}
}

static bool lua_hasimgui(std::string_view name, sol::this_state s)
{
	if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(s))
	{
		if (LuaImGuiProcessor* imgui = thread_ptr->GetImGuiProcessor())
			return imgui->HasCallback(name);
	}

	return false;
}

void MQ_RegisterLua_ImGui(sol::table& lua)
{
	lua["imgui"] = lua.create_with(
		"init", &lua_addimgui,
		"destroy", &lua_removeimgui,
		"exists", &lua_hasimgui
	);
}

//============================================================================

LuaImGui::LuaImGui(std::string_view name, const sol::thread& parent_thread, const sol::function& callback)
	: m_name(name)
	, m_parentThread(parent_thread), m_callback(callback)
{
	m_thread = sol::thread::create(m_parentThread.state());
	ImGui_RegisterLua(m_thread.state());

	m_coroutine = sol::coroutine(m_thread.state(), m_callback);
}

LuaImGui::~LuaImGui()
{
}

bool LuaImGui::Pulse() const
{
	bool success = true;
	try
	{
		auto result = m_coroutine();
		if (!result.valid())
		{
			LuaError("ImGui Failure:\n%s", sol::stack::get<std::string>(result.lua_state(), result.stack_index()).c_str());
			result.abandon();

			success = false;
		}
	}
	catch (std::runtime_error& e)
	{
		LuaError("ImGui Failure:\n%s", e.what());
		success = false;
	}

	if (!success)
	{
		// ImGui failure: terminate the script
		if (m_parentThread)
		{
			if (std::shared_ptr<LuaThread> thread_ptr = LuaThread::get_from(m_parentThread.state()))
			{
				thread_ptr->Exit();
			}
		}

		// Critical error occurred, reset the overlay to prevent bad state from killing the whole process.
		ResetOverlay();
	}

	return success;
}

//============================================================================

// MQ-Specific functions
inline bool DrawTextureAnimation(const std::unique_ptr<CTextureAnimation>& anim, int x, int y, bool drawBorder) { return mq::imgui::DrawTextureAnimation(anim.get(), CXSize(x, y), drawBorder); }
inline bool DrawTextureAnimation(const std::unique_ptr<CTextureAnimation>& anim, int x, int y) { return mq::imgui::DrawTextureAnimation(anim.get(), CXSize(x, y)); }
inline bool DrawTextureAnimation(const std::unique_ptr<CTextureAnimation>& anim) { return mq::imgui::DrawTextureAnimation(anim.get()); }

void ImGui_RegisterLua(sol::state_view state)
{
	sol::table ImGui = state.get_or("ImGui", sol::lua_nil);

	if (ImGui == sol::lua_nil)
	{
		ImGui = sol_ImGui::Init(state);

#pragma region MQ Specific Functions
		ImGui.set_function("DrawTextureAnimation", sol::overload(
			sol::resolve<bool(const std::unique_ptr<CTextureAnimation>&, int, int, bool)>(DrawTextureAnimation),
			sol::resolve<bool(const std::unique_ptr<CTextureAnimation>&, int, int)>(DrawTextureAnimation),
			sol::resolve<bool(const std::unique_ptr<CTextureAnimation>&)>(DrawTextureAnimation)
		));
#pragma endregion

		ImGui.set_function("Register", lua_addimgui);
		ImGui.set_function("Unregister", lua_removeimgui);
	}
}


} // namespace mq::lua
