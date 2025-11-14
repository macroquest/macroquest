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

#include "common/StringUtils.h"
#include "MQ2DeveloperTools.h"
#include "MQ2ImGuiTools.h"
#include "MQ2KeyBinds.h"

#include "imgui/ImGuiTreePanelWindow.h"
#include "imgui/ImGuiTextEditor.h"
#include <imgui/imgui_internal.h>

#include <fmt/format.h>

using namespace std::chrono_literals;

namespace mq {

static bool gbShowSettingsWindow = false;
imgui::ImGuiTreePanelWindow* gSettingsWindow = nullptr;
std::map<const char*, fPanelDrawFunction> s_pendingPanels;

static void InitializeMQ2ImGuiTools();
static void ShutdownMQ2ImGuiTools();
static void PulseMQ2ImGuiTools();
static void UpdateSettingsUI();

static int WriteChatColorImGuiAPI(const char* line, uint32_t color, uint32_t filter);

static MQModule gImGuiModule = {
	"ImGuiAPI",                   // Name
	false,                        // CanUnload
	InitializeMQ2ImGuiTools,      // Initialize
	ShutdownMQ2ImGuiTools,        // Shutdown
	PulseMQ2ImGuiTools,           // Pulse
	nullptr,                      // SetGameState
	UpdateSettingsUI,             // UpdateImGui
	nullptr,                      // Zoned
	WriteChatColorImGuiAPI,       // WriteChatColor
};
MQModule* GetImGuiToolsModule() { return &gImGuiModule; }

//============================================================================

void AddSettingsPanel(const char* name, fPanelDrawFunction drawFunction)
{
	if (!gSettingsWindow)
		s_pendingPanels.emplace(name, drawFunction);
	else
		gSettingsWindow->AddPanel(name, drawFunction);
}

void RemoveSettingsPanel(const char* name)
{
	if (gSettingsWindow)
		gSettingsWindow->RemovePanel(name);
}

void ImGuiTools_DrawWindowsMenu()
{
	ImGui::MenuItem("Settings", nullptr, &gbShowSettingsWindow);
}

//----------------------------------------------------------------------------

void ToggleImGuiOverlay()
{
	SetOverlayEnabled(!IsOverlayEnabled());
}

static void DoToggleImGuiOverlay(const char* name, bool down)
{
	if (down)
	{
		ToggleImGuiOverlay();
	}
}

void UpdateSettingsUI()
{
	if (gbShowSettingsWindow)
	{
		if (gSettingsWindow)
			gSettingsWindow->Draw(&gbShowSettingsWindow);
	}
}

void MQSettingsCommand(PlayerClient*, const char* szLine)
{
	std::string_view arg{ szLine };
	if (!arg.empty())
	{
		gbShowSettingsWindow = true;

		if (gSettingsWindow)
		{
			gSettingsWindow->FocusPanel(arg);
		}
	}
	else
	{
		gbShowSettingsWindow = !gbShowSettingsWindow;
	}
}

//============================================================================

static void InitializeMQ2ImGuiTools()
{
	// Add keybind to toggle imgui
	AddMQ2KeyBind("TOGGLE_IMGUI_OVERLAY", DoToggleImGuiOverlay);

	AddCommand("/mqsettings", MQSettingsCommand);

	AddCascadeMenuItem("Settings", []() { gbShowSettingsWindow = true; }, 2);

	gSettingsWindow = new imgui::ImGuiTreePanelWindow("MacroQuest Settings", ImVec2(600, 650));

	for (const auto& pair : s_pendingPanels)
	{
		AddSettingsPanel(pair.first, pair.second);
	}

	s_pendingPanels.clear();
}

static void ShutdownMQ2ImGuiTools()
{
	delete gSettingsWindow;
	gSettingsWindow = nullptr;

	RemoveMQ2KeyBind("TOGGLE_IMGUI_OVERLAY");
	RemoveCommand("/mqsettings");
}

static void PulseMQ2ImGuiTools()
{
}

static int WriteChatColorImGuiAPI(const char* line, uint32_t color, uint32_t filter)
{
	return ImGuiConsoleAddText(line, color, filter);
}

} // namespace mq
