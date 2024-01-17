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

#include "spdlog/spdlog.h"

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_system.h>

static std::map<std::string, std::function<void()>> s_windows;
static std::vector<HelloImGui::DockableWindow> s_pendingViewports;

namespace LauncherImGui {

void AddViewport(HelloImGui::DockableWindow&& params)
{
	s_pendingViewports.emplace_back(std::move(params));
}

void AddViewport(
	const std::function<void()>& render,
	const std::string& windowTitle,
	const ImVec2& windowSize, // = HelloImGui::DefaultWindowSize
	const ImVec2& windowPosition // = HelloImGui::DefaultWindowSize
)
{
	HelloImGui::DockableWindow viewport;
	viewport.GuiFunction = render;

	viewport.label = windowTitle; // this must be unique
	viewport.dockSpaceName = fmt::format("{}Space", windowTitle);
	viewport.windowSize = windowSize;
	viewport.windowPosition = windowPosition;

	viewport.focusWindowAtNextFrame = true;

	AddViewport(std::move(viewport));
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

void Run(SDL_WindowsMessageHook eventHandler, float fpsIdle)
{
	HelloImGui::RunnerParams params;

	//params.imGuiWindowParams.defaultImGuiWindowType = HelloImGui::DefaultImGuiWindowType::NoDefaultWindow;
	params.imGuiWindowParams.enableViewports = true;

	params.fpsIdling.fpsIdle = fpsIdle;

	// prevent begin/end from being called at all
	params.imGuiWindowParams.defaultImGuiWindowType = HelloImGui::DefaultImGuiWindowType::NoDefaultWindow;
	params.appWindowParams.hidden = true;
	params.appWindowParams.borderless = true;

	params.callbacks.PostInit = [&eventHandler]()
		{
			SDL_SetWindowsMessageHook(eventHandler, nullptr);
		};

	params.callbacks.PreNewFrame = []()
		{
			auto& viewports = HelloImGui::GetRunnerParams()->dockingParams.dockableWindows;

			// first clear out all removed viewports
			viewports.erase(std::remove_if(viewports.begin(), viewports.end(),
				[](const HelloImGui::DockableWindow& viewport) { return !viewport.isVisible; }), viewports.end());

			// and then add in pending viewports
			for (auto& viewport : s_pendingViewports)
			{
				auto it = std::find_if(viewports.begin(), viewports.end(),
					[&label = viewport.label](const HelloImGui::DockableWindow& vp)
					{ return ci_equals(vp.label, label); });

				if (it == viewports.end())
					viewports.emplace_back(std::move(viewport));
			}

			s_pendingViewports.clear();
		};

	params.callbacks.SetupImGuiConfig = []()
		{
			HelloImGui::ImGuiDefaultSettings::SetupDefaultImGuiConfig();

			ImGuiIO& io = ImGui::GetIO();

			io.ConfigViewportsNoTaskBarIcon = true;
			io.ConfigViewportsNoDefaultParent = true;
			io.ConfigViewportsNoAutoMerge = true;
			io.ConfigViewportsNoDecoration = true;
		};

	// This will technically build the font atlas twice, but doing it this way allows us to reuse MQ's font code
	// TODO: test if this matters, if it does then we just have to call the constituent functions
	params.callbacks.LoadAdditionalFonts = []()
		{
			//HelloImGui::ImGuiDefaultSettings::LoadDefaultFont_WithFontAwesomeIcons();

			mq::imgui::ConfigureFonts(ImGui::GetIO().Fonts);
		};

	params.callbacks.SetupImGuiStyle = []()
		{
			HelloImGui::ImGuiDefaultSettings::SetupDefaultImGuiStyle();

			mq::imgui::ConfigureStyle();
		};

	HelloImGui::Run(params);
}

void Terminate()
{
	// This throws if Run has not been called
	try
	{
		HelloImGui::GetRunnerParams()->appShallExit = true;
	}
	catch (std::runtime_error&)
	{
		SPDLOG_ERROR("Failed to initialize ImGui before attempting to exit.");
	}
}

void AddViewport()
{
	AddViewport(
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
		"MacroQuest"
	);
}

} // namespace LauncherImGui
