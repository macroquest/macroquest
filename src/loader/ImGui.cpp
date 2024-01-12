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

#include "ImGui.h"
#include "MacroQuest.h"

#include "imgui/imgui.h"

#include "hello_imgui/hello_imgui.h"
#include "imgui/ImGuiUtils.h"

static std::map<std::string, std::function<void()>> s_windows;

namespace LauncherImGui {

void Run(
	const std::function<void()>& render,
	const std::string& windowTitle, // = ""
	bool windowSizeAuto, // = false
	bool windowRestorePreviousGeometry, // = false
	const HelloImGui::ScreenSize& windowSize, // = HelloImGui::DefaultWindowSize
	float fpsIdle // = 10.f
)
{
	HelloImGui::RunnerParams params;
	params.callbacks.ShowGui = render;

	params.appWindowParams.windowTitle = windowTitle;
	params.appWindowParams.windowGeometry.sizeAuto = windowSizeAuto;
	params.appWindowParams.restorePreviousGeometry = windowRestorePreviousGeometry;
	params.appWindowParams.windowGeometry.size = windowSize;
	params.fpsIdling.fpsIdle = fpsIdle;

	// This will technically build the font atlas twice, but doing it this way allows us to reuse MQ's font code
	// TODO: test if this matters, if it does then we just have to call the constituent functions
	params.callbacks.LoadAdditionalFonts = []() { mq::imgui::ConfigureFonts(ImGui::GetIO().Fonts); };

	params.callbacks.SetupImGuiStyle = []() { mq::imgui::ConfigureStyle(); };

	HelloImGui::Run(params);
}

bool AddWindow(const std::string& name, const std::function<void()> callback)
{
	const auto& [_, added] = s_windows.emplace(name, callback);
	return added;
}

bool RemoveWindow(const std::string& name)
{
	return s_windows.erase(name) > 0;
}

void Run()
{
	Run(
		[]()
		{
			ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.f);

			static std::optional<std::string> current_window;

			ImGui::BeginChild("Window Selection", ImVec2(ImGui::GetContentRegionAvail().x * 0.2f, 0), ImGuiChildFlags_Border, ImGuiWindowFlags_HorizontalScrollbar);
			for (const auto& [name, callback] : s_windows)
			{
				bool is_selected = current_window && ci_equals(name, *current_window);
				if (ImGui::Selectable(name.c_str(), is_selected))
					current_window = name;

				if (is_selected) ImGui::SetItemDefaultFocus();
			}
			ImGui::EndChild();

			ImGui::SameLine();

			ImGui::BeginChild("Window Display", ImVec2(0, 0), ImGuiChildFlags_None, ImGuiWindowFlags_HorizontalScrollbar);
			if (current_window)
			{
				const auto& window_it = s_windows.find(*current_window);
				if (window_it != s_windows.end())
					window_it->second();
			}
			ImGui::EndChild();

			ImGui::PopStyleVar();
		},
		"MacroQuest",
		false,
		true,
		HelloImGui::DefaultWindowSize
	);
}

} // namespace LauncherImGui
