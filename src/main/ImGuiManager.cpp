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
#include "ImGuiManager.h"

#include "MQ2DeveloperTools.h"
#include "MQ2ImGuiTools.h"

#include <imgui/imgui.h>
#include <mq/utils/Benchmarks.h>

 // I was trying to avoid including main, but we just got too many globals
#include "MQ2Main.h"

// move to mq/utils? or do we need a new static lib?
#include "common/HotKeys.h"

#include <cfenv>

namespace mq {

// Benchmarks for ImGui updates
uint32_t bmUpdateImGui = 0;
uint32_t bmPluginsUpdateImGui = 0;

// global imgui toggle
bool gbRenderImGui = true;

static mq::PlatformHotkey gToggleConsoleHotkey;
static const char gToggleConsoleDefaultBind[] = "ctrl+`";
static bool gbToggleConsoleHotkeyReady = false;

// Critical error occurred and imgui needs to be reset
bool gbManualResetRequired = false;

extern bool gbToggleConsoleRequested;

namespace imgui
{
	// Imported from MQ2Overlay.cpp
	void ImGui_ImplDX9_NewFrame();
	void ImGui_ImplWin32_NewFrame();
	void ImGui_ImplDX9_RenderDrawData(ImDrawData* drawData);
}

void SetOverlayEnabled(bool visible)
{
	gbRenderImGui = visible;
}

bool IsOverlayEnabled()
{
	return gbRenderImGui;
}

void DoImGuiUpdateInternal()
{
	UpdateImGuiConsole();

	DeveloperTools_UpdateImGui();
	UpdateSettingsUI();
}

void ImGuiManager_DrawFrame()
{
	if (!gbRenderImGui)
		return;

	// we can't expect that the rounding mode is valid, and imgui respects the rounding mode so set it here and ensure that we reset it before the return
	auto round = fegetround();
	fesetround(FE_TONEAREST);

	IDirect3DStateBlock9* stateBlock = nullptr;
	gpD3D9Device->CreateStateBlock(D3DSBT_ALL, &stateBlock);

	// Prepare the new frame
	imgui::ImGui_ImplDX9_NewFrame();
	imgui::ImGui_ImplWin32_NewFrame();

	try
	{
		ImGui::NewFrame();

		{
			MQScopedBenchmark bm1(bmUpdateImGui);
			DoImGuiUpdateInternal();

			if (!gbManualResetRequired)
			{
				MQScopedBenchmark bm2(bmPluginsUpdateImGui);
				PluginsUpdateImGui();
			}
		}

		// Render the ui
		ImGui::Render();
		imgui::ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

		ImGui::UpdatePlatformWindows();

		// Update and Render additional Platform Windows
		ImGuiIO& io = ImGui::GetIO();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			ImGui::RenderPlatformWindowsDefault();
		}
	}
	catch (const ImGuiException& ex)
	{
		gbManualResetRequired = true;

		WriteChatf("\arImGui Critical Failure: %s", ex.what());
		WriteChatf("\arFix the error and then run: \ay/mqoverlay resume\ar");
	}

	stateBlock->Apply();
	stateBlock->Release();

	fesetround(round);
}

bool ImGuiManager_HandleWndProc(uint32_t msg, uintptr_t wparam, intptr_t lparam)
{
	if (msg == WM_KEYDOWN
		&& gbToggleConsoleHotkeyReady)
	{
		// Match the vkey and modifiers
		if (wparam == gToggleConsoleHotkey.virtualKey)
		{
			// Check the modifiers, don't allow repeats.
			if ((HIWORD(lparam) & KF_REPEAT) == 0
				&& mq::IsHotKeyModifiersPressed(gToggleConsoleHotkey))
			{
				gbToggleConsoleRequested = true;
				return true;
			}
		}
	}

	return false;
}

void ImGuiManager_Initialize()
{
	bmUpdateImGui = AddMQ2Benchmark("UpdateImGui");
	bmPluginsUpdateImGui = AddMQ2Benchmark("UpdateImGuiPlugins");

	gbRenderImGui = GetPrivateProfileBool("MacroQuest", "RenderImGui", gbRenderImGui, mq::internal_paths::MQini);

	// TODO: application-wide keybinds could use an encapsulated interface. For now I'm just dumping his here since we need it to
	// connect to the win32 hook and control the imgui console.
	::GetPrivateProfileStringA("MacroQuest", "ToggleConsoleKey", gToggleConsoleDefaultBind,
		gToggleConsoleHotkey.keybind, lengthof(gToggleConsoleHotkey.keybind), mq::internal_paths::MQini.c_str());

	if (!gbToggleConsoleHotkeyReady)
	{
		if (mq::ConvertStringToModifiersAndVirtualKey(gToggleConsoleHotkey.keybind,
			gToggleConsoleHotkey.modifiers, gToggleConsoleHotkey.virtualKey))
		{
			SPDLOG_INFO("Toggle console keybind: {0}", gToggleConsoleHotkey.keybind);
			gbToggleConsoleHotkeyReady = true;
		}
		else if (strlen(gToggleConsoleHotkey.keybind) > 0)
		{
			SPDLOG_WARN("Unable to parse toggle console keybind: {0}", gToggleConsoleHotkey.keybind);
			strcpy_s(gToggleConsoleHotkey.keybind, "");

			gbToggleConsoleHotkeyReady = false;
		}
	}

	if (gbWriteAllConfig)
	{
		WritePrivateProfileBool("MacroQuest", "RenderImGui", gbRenderImGui, mq::internal_paths::MQini);
	}
}

void ImGuiManager_Shutdown()
{
	RemoveMQ2Benchmark(bmUpdateImGui);
	RemoveMQ2Benchmark(bmPluginsUpdateImGui);
}

} // namespace mq
