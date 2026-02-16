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

#include "pch.h"
#include "LuaImGui.h"
#include "LuaThread.h"

#include "bindings/lua_Bindings.h"
#include "imgui/implot/implot.h"
#include "imgui/imanim/im_anim.h"
#include "imgui/imgui_internal.h"
#include <mq/Plugin.h>

namespace mq::lua {

//============================================================================

LuaImGuiProcessor::LuaImGuiProcessor(const LuaThread* thread)
	: m_thread(thread)
	, m_imPlotContext(std::shared_ptr<ImPlotContext>(ImPlot::CreateContext(), &ImPlot::DestroyContext))
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

struct ScopedImAnimContext
{
	ScopedImAnimContext(std::unique_ptr<LuaImAnimState>& state)
	{
		if (state)
		{
			orig_context = iam_context_get_current();
			iam_context_set_current(state->ctx);
		}
	}

	~ScopedImAnimContext()
	{
		if (orig_context)
		{
			iam_context_set_current(orig_context);
		}
	}

	iam_context* orig_context = nullptr;
};

void LuaImGuiProcessor::Pulse()
{
	if (m_thread->IsPaused()) return;

	// Backup context and set our own
	ImPlotContext* context = ImPlot::GetCurrentContext();
	ImPlot::SetCurrentContext(m_imPlotContext.get());

	ScopedImAnimContext scoped_iam_context(m_imAnimState);

	// remove any existing hooks, they will be re-installed when running in onpulse
	// this is to help prevent us from yielding from the thread while we're running imgui stuff.
	lua_sethook(m_thread->GetLuaThread().lua_state(), nullptr, 0, 0);

	for (std::unique_ptr<LuaImGui>& im : m_imguis)
	{
		if (!im->Pulse())
			RemoveCallback(im->GetName());
	}

	// Restore context
	ImPlot::SetCurrentContext(context);
}

LuaImAnimState::LuaImAnimState()
{
	ctx = iam_context_create();
}

LuaImAnimState::~LuaImAnimState()
{
	iam_context_destroy(ctx);
	ctx = nullptr;
}

void LuaImGuiProcessor::InitImAnimContext()
{
	m_imAnimState = std::make_unique<LuaImAnimState>();
}

//============================================================================

LuaImGui::LuaImGui(std::string_view name, const sol::thread& parent_thread, const sol::function& callback)
	: m_name(name)
	, m_parentThread(parent_thread), m_callback(callback)
{
	m_thread = sol::thread::create(m_parentThread.state());
	m_coroutine = sol::coroutine(m_thread.state(), m_callback);

	// This implements the automatic registration of ImGui namespace when calling mq.imgui.init
	bindings::RegisterBindings_ImGui(m_thread.state());
}

LuaImGui::~LuaImGui()
{
}

bool LuaImGui::Pulse() const
{
	bool success = true;
	try
	{
		std::shared_ptr<LuaThread> luaThread = LuaThread::get_from(m_thread.state());
		ScopedYieldDisabler disableYield(luaThread);

		sol::function_result result = m_coroutine();

		if (!result.valid())
		{
			sol::table stackTraces = luaThread->GetState().registry()["mq2lua.tracebacks"];
			sol::error err = result;

			DebugStackTrace(result.lua_state(), err, stackTraces);
			result.abandon();
			success = false;
		}
	}
	catch (const ImGuiException& e)
	{
		LuaError("ImGui Exception:\n%s", e.what());
		success = false;
	}
	catch (const sol::error& e)
	{
		LuaError("ImGui Failure:\n%s", e.what());
		success = false;
	}
	catch (const std::runtime_error& e)
	{
		LuaError("ImGui Failure:\n%s", e.what());
		success = false;
	}
	catch (const std::exception& e)
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
