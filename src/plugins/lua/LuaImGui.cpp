/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
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

#include "bindings/lua_Bindings.h"
#include <mq/Plugin.h>

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
	if (m_thread->IsPaused()) return;

	// remove any existing hooks, they will be re-installed when running in onpulse
	// this is to help prevent us from yielding from the thread while we're running imgui stuff.
	lua_sethook(m_thread->GetLuaThread().lua_state(), nullptr, 0, 0);

	for (std::unique_ptr<LuaImGui>& im : m_imguis)
	{
		if (!im->Pulse())
			RemoveCallback(im->GetName());
	}
}

//============================================================================

LuaImGui::LuaImGui(std::string_view name, const sol::thread& parent_thread, const sol::function& callback)
	: m_name(name)
	, m_parentThread(parent_thread), m_callback(callback)
{
	m_thread = sol::thread::create(m_parentThread.state());
	bindings::RegisterBindings_ImGui(m_thread.state());

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
		int yield_count = 0;
		constexpr int max_yields = 20;
		ScopedYieldDisabler disableYield(LuaThread::get_from(m_thread.state()));

		sol::protected_function_result result;
		do
		{
			result = m_coroutine();
			if (!result.valid())
			{
				LuaError("ImGui Failure:\n%s", sol::stack::get<std::string>(result.lua_state(), result.stack_index()).c_str());
				result.abandon();

				success = false;
			}
			++yield_count;
		} while (success && result.status() == sol::call_status::yielded && yield_count <= max_yields);
		if (yield_count > max_yields)
		{
			LuaError("ImGui thread tried to yield %d or more times!", max_yields);
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

} // namespace mq::lua
