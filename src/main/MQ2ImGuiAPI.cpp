/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
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
#include "MQ2Main.h"

#include "imgui/ImGuiTreePanelWindow.h"

namespace mq {

static bool gbShowDemoWindow = false;
imgui::ImGuiTreePanelWindow gSettingsWindow("MacroQuest Settings");
static bool gbShowSettingsWindow = false;
imgui::ImGuiTreePanelWindow gDebugWindow("MacroQuest Debug Tools");
static bool gbShowDebugWindow = false;
static int gRenderCallbacksId = 0;

static void InitializeMQ2ImGuiAPI();
static void ShutdownMQ2ImGuiAPI();
static void PulseMQ2ImGuiAPI();

static MQModule gImGuiModule = {
	"ImGuiAPI",                   // Name
	false,                        // CanUnload
	InitializeMQ2ImGuiAPI,        // Initialize
	ShutdownMQ2ImGuiAPI,          // Shutdown
	PulseMQ2ImGuiAPI,             // Pulse
};
MQModule* GetImGuiAPIModule() { return &gImGuiModule; }

void AddSettingsPanel(const char* name, fPanelDrawFunction drawFunction)
{
	gSettingsWindow.AddPanel(name, drawFunction);
}

void RemoveSettingsPanel(const char* name)
{
	gSettingsWindow.RemovePanel(name);
}

void AddDebugPanel(const char* name, fPanelDrawFunction drawFunction)
{
	gDebugWindow.AddPanel(name, drawFunction);
}

void RemoveDebugPanel(const char* name)
{
	gDebugWindow.RemovePanel(name);
}

static void DoToggleImGuiOverlay(const char* name, bool down)
{
	if (down)
	{
		SetOverlayEnabled(!IsOverlayEnabled());
	}
}

static void UpdateOverlayUI()
{
	if (gbShowDemoWindow)
	{
		ImGui::ShowDemoWindow(&gbShowDemoWindow);
	}

	if (gbShowSettingsWindow)
	{
		gSettingsWindow.Draw(&gbShowSettingsWindow);
	}

	if (gbShowDebugWindow)
	{
		gDebugWindow.Draw(&gbShowDebugWindow);
	}
}

static void InitializeMQ2ImGuiAPI()
{
	// Init settings
	gbShowDemoWindow = GetPrivateProfileBool("MacroQuest", "ShowDemoWindow", gbShowDemoWindow, mq::internal_paths::MQini);
	gbShowDebugWindow = GetPrivateProfileBool("MacroQuest", "ShowDebugWindow", gbShowDebugWindow, mq::internal_paths::MQini);

	if (gbWriteAllConfig)
	{
		WritePrivateProfileBool("MacroQuest", "ShowDemoWindow", gbShowDemoWindow, mq::internal_paths::MQini);
		WritePrivateProfileBool("MacroQuest", "ShowDebugWindow", gbShowDebugWindow, mq::internal_paths::MQini);
	}

	// Set up imgui render function
	MQRenderCallbacks callbacks;
	callbacks.ImGuiRender = UpdateOverlayUI;

	gRenderCallbacksId = AddRenderCallbacks(callbacks);

	// Add keybind to toggle imgui
	AddMQ2KeyBind("TOGGLE_IMGUI_OVERLAY", DoToggleImGuiOverlay);

	AddCascadeMenuItem("Settings", []() { gbShowSettingsWindow = true; }, 2);
	AddCascadeMenuItem("Debug Window", []() { gbShowDebugWindow = true; });
	AddCascadeMenuItem("ImGui Demo", []() { gbShowDemoWindow = true; });
}

static void ShutdownMQ2ImGuiAPI()
{
	RemoveMQ2KeyBind("TOGGLE_IMGUI_OVERLAY");

	// Remove the imgui render function
	RemoveRenderCallbacks(gRenderCallbacksId);
}

static void PulseMQ2ImGuiAPI()
{
	static bool bShowDebugWindowLast = gbShowDebugWindow;
	if (bShowDebugWindowLast != gbShowDebugWindow)
	{
		WritePrivateProfileBool("MacroQuest", "ShowDebugWindow", gbShowDebugWindow, mq::internal_paths::MQini);
		bShowDebugWindowLast = gbShowDebugWindow;
	}

	static bool bShowDemoWindowLast = gbShowDemoWindow;
	if (bShowDemoWindowLast != gbShowDemoWindow)
	{
		WritePrivateProfileBool("MacroQuest", "ShowDemoWindow", gbShowDemoWindow, mq::internal_paths::MQini);
		bShowDemoWindowLast = gbShowDemoWindow;
	}
}

} // namespace mq
