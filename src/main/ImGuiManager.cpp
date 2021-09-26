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

#include "ImGuiBackend.h"
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
bool gbOverlayDebug = false;

static mq::PlatformHotkey gToggleConsoleHotkey;
static const char gToggleConsoleDefaultBind[] = "ctrl+`";
static bool gbToggleConsoleHotkeyReady = false;

// Critical error occurred and imgui needs to be reset
bool gbManualResetRequired = false;

extern bool gbToggleConsoleRequested;

void InitializeMQ2Overlay();
void ShutdownMQ2Overlay();
void PulseMQ2Overlay();

void SetOverlayEnabled(bool visible)
{
	gbRenderImGui = visible;
}

bool IsOverlayEnabled()
{
	return gbRenderImGui;
}

static void StartupOverlayComponents()
{
	InitializeMQ2Overlay();
	InitializeImGuiConsole();
}

static void ShutdownOverlayComponents()
{
	ShutdownMQ2Overlay();
	ShutdownImGuiConsole();
}

void DoImGuiUpdateInternal()
{
	// This updates the dockspace first, then the console.
	// TODO: Move dockspace management here.
	UpdateImGuiConsole();

	// After the dockspace is set up, run the imgui update on all modules.
	ModulesUpdateImGui();
}

void UpdateImGuiDebugInfo()
{
	ImGuiIO& io = ImGui::GetIO();

	// Display ImGuiIO output flags
	ImGui::Text("WantCaptureMouse: %d", io.WantCaptureMouse);
	ImGui::Text("WantCaptureMouseUnlessPopupClose: %d", io.WantCaptureMouseUnlessPopupClose);
	ImGui::Text("WantCaptureKeyboard: %d", io.WantCaptureKeyboard);
	ImGui::Text("WantTextInput: %d", io.WantTextInput);
	ImGui::Text("WantSetMousePos: %d", io.WantSetMousePos);
	ImGui::Text("NavActive: %d, NavVisible: %d", io.NavActive, io.NavVisible);

	// Display Mouse state
	if (ImGui::IsMousePosValid())
		ImGui::Text("Mouse pos: (%g, %g)", io.MousePos.x, io.MousePos.y);
	else
		ImGui::Text("Mouse pos: <INVALID>");
	ImGui::Text("Mouse delta: (%g, %g)", io.MouseDelta.x, io.MouseDelta.y);
	ImGui::Text("Mouse down:");     for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++) if (ImGui::IsMouseDown(i)) { ImGui::SameLine(); ImGui::Text("b%d (%.02f secs)", i, io.MouseDownDuration[i]); }
	ImGui::Text("Mouse clicked:");  for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++) if (ImGui::IsMouseClicked(i)) { ImGui::SameLine(); ImGui::Text("b%d", i); }
	ImGui::Text("Mouse dblclick:"); for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++) if (ImGui::IsMouseDoubleClicked(i)) { ImGui::SameLine(); ImGui::Text("b%d", i); }
	ImGui::Text("Mouse released:"); for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++) if (ImGui::IsMouseReleased(i)) { ImGui::SameLine(); ImGui::Text("b%d", i); }
	ImGui::Text("Mouse wheel: %.1f", io.MouseWheel);
	ImGui::Text("Pen Pressure: %.1f", io.PenPressure); // Note: currently unused
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
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();

	try
	{
		ImGui::NewFrame();

		{
			MQScopedBenchmark bm1(bmUpdateImGui);
			DoImGuiUpdateInternal();

			// Plugins will get disabled if an error occurs.
			if (!gbManualResetRequired)
			{
				MQScopedBenchmark bm2(bmPluginsUpdateImGui);
				PluginsUpdateImGui();
			}

			if (gbOverlayDebug)
			{
				UpdateImGuiDebugInfo();
			}
		}

		// Render the ui
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

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
		WriteChatf("\arPlugin ImGui has been temporarily paused. To resume imgui, run: \ay/mqoverlay resume\ar");
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

void* ImGuiManager_GetCursorForImGui(ImGuiMouseCursor imguiCursor)
{
	if (pWndMgr)
	{
		const CursorClass* cc = pWndMgr->GetCursorClass();

		// Show OS mouse cursor
		CursorClass::eCursorTypes cursorType = CursorClass::eArrow;

		switch (imguiCursor)
		{
		case ImGuiMouseCursor_ResizeEW:
			cursorType = CursorClass::eEastWest;
			break;
		case ImGuiMouseCursor_ResizeNS:
			cursorType = CursorClass::eNorthSouth;
			break;
		case ImGuiMouseCursor_ResizeNESW:
			cursorType = CursorClass::eNorthEastSouthWest;
			break;
		case ImGuiMouseCursor_ResizeNWSE:
			cursorType = CursorClass::eNorthWestSouthEast;
			break;
		case ImGuiMouseCursor_TextInput:
			cursorType = CursorClass::eBeam;
			break;
		case ImGuiMouseCursor_Arrow:
			break;
		case ImGuiMouseCursor_ResizeAll:
			cursorType = CursorClass::eMove;
			break;

		case ImGuiMouseCursor_Hand:
		default:
			return nullptr;
		}

		return cc->CursorList[cursorType];
	}

	return nullptr;
}

void MQOverlayCommand(SPAWNINFO* pSpawh, char* szLine)
{
	if (ci_equals(szLine, "reload"))
	{
		ResetOverlay();
	}
	else if (ci_equals(szLine, "resume"))
	{
		gbManualResetRequired = false;
	}
	else if (ci_equals(szLine, "stop"))
	{
		ShutdownOverlayComponents();
	}
	else if (ci_equals(szLine, "debug"))
	{
		gbOverlayDebug = !gbOverlayDebug;
		WriteChatf("Overlay debug info is now: %s", gbOverlayDebug ? "\agOn" : "\arOff");
		WritePrivateProfileBool("MacroQuest", "OverlayDebug", gbOverlayDebug, mq::internal_paths::MQini);
	}
	else if (ci_equals(szLine, "start"))
	{
		StartupOverlayComponents();
	}
	else
	{
		WriteChatf("Usage: /mqoverlay [reload | resume | debug | stop | start]");
	}
}

void ImGuiManager_Initialize()
{
	bmUpdateImGui = AddMQ2Benchmark("UpdateImGui");
	bmPluginsUpdateImGui = AddMQ2Benchmark("UpdateImGuiPlugins");

	gbRenderImGui = GetPrivateProfileBool("MacroQuest", "RenderImGui", gbRenderImGui, mq::internal_paths::MQini);
	gbOverlayDebug = GetPrivateProfileBool("MacroQuest", "OverlayDebug", gbOverlayDebug, mq::internal_paths::MQini);

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
		WritePrivateProfileBool("MacroQuest", "OverlayDebug", gbOverlayDebug, mq::internal_paths::MQini);
	}

	AddCommand("/mqoverlay", MQOverlayCommand);

	StartupOverlayComponents();
}

void ImGuiManager_Shutdown()
{
	RemoveCommand("/mqoverlay");

	RemoveMQ2Benchmark(bmUpdateImGui);
	RemoveMQ2Benchmark(bmPluginsUpdateImGui);

	ShutdownOverlayComponents();
}

void ImGuiManager_Pulse()
{
	PulseMQ2Overlay();
}

} // namespace mq
