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

#include "imgui_backend/imgui_engine.h"

#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"

#include "imgui/ImGuiUtils.h"

#include "spdlog/spdlog.h"

static std::map<std::string, std::function<void()>> s_windows;
static std::map<std::string, std::function<bool()>> s_viewports;

// for the context  menu
static std::map<std::string, std::function<void()>> s_menuGroups;
static bool s_contextOpen;

bool ImGui::SmallCheckbox(const char* label, bool* v)
{
	float backup_padding_y = ImGui::GetStyle().FramePadding.y;
	ImGui::GetStyle().FramePadding.y = 0.f;
	bool pressed = ImGui::Checkbox(label, v);
	ImGui::GetStyle().FramePadding.y = backup_padding_y;
	return pressed;
}

namespace LauncherImGui {

void AddViewport(
	const std::function<bool()>& render,
	const std::string& label
)
{
	s_viewports.emplace(label, render);
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

ImGuiWindowClass cl;

void MaybeShowContextMenu();
void Run(const std::function<bool()>& mainWindow, const std::function<bool()>& mainLoop)
{
	cl.ViewportFlagsOverrideSet = ImGuiViewportFlags_NoAutoMerge | ImGuiViewportFlags_TopMost;
	cl.ViewportFlagsOverrideClear |= ImGuiViewportFlags_NoFocusOnAppearing | ImGuiViewportFlags_NoFocusOnClick;
	cl.ParentViewportId = 0;
	cl.ClassId = 1;

	LauncherImGui::Backend::Init(hMainWnd);

	auto drawMain = [&mainWindow]() -> bool
	{

		bool ret = false;
		if (ImGui::Begin("Main Window", nullptr, ImGuiWindowFlags_NoDecoration))
		{
			ret = mainWindow();
		}
		ImGui::End();

		for (auto it = s_viewports.begin(); it != s_viewports.end();)
		{
			ImGui::SetNextWindowClass(&cl);
			if (!it->second())
				it = s_viewports.erase(it);
			else
				++it;
		}

		// we do this as a popup to let imgui handle styling as a popup. _However_ imgui fails to handle some
		// things correctly because we aren't popping up over an imgui window, but are instead implicitly
		// creating a viewport.
		if (s_contextOpen)
		{
			ImGui::OpenPopup("Context Popup");
			s_contextOpen = false;
		}

		MaybeShowContextMenu();

		return ret;
	};

	while (LauncherImGui::Backend::DrawFrame(drawMain) && mainLoop())
	{
	}

	LauncherImGui::Backend::Cleanup();
}

bool HandleWndProc(HWND hWnd, uint32_t msg, uintptr_t wParam, intptr_t lParam)
{
	return LauncherImGui::Backend::HandleWndProc(hWnd, msg, wParam, lParam);
}

void OpenMainWindow()
{
	AddViewport(
		[]()
		{
			ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.f);

			bool is_open = true;
			if (ImGui::Begin("MacroQuest", &is_open))
			{
				static std::optional<const std::function<void()>*> current_callback;

				ImGui::BeginChild("Window Selection", ImVec2(ImGui::GetContentRegionAvail().x * 0.2f, 0), ImGuiChildFlags_Border, ImGuiWindowFlags_HorizontalScrollbar);
				for (const auto& [name, callback] : s_windows)
				{
					bool is_selected = current_callback && &callback == *current_callback;
					if (ImGui::Selectable(name.c_str(), is_selected))
						current_callback = &callback;

					if (is_selected) ImGui::SetItemDefaultFocus();
				}
				ImGui::EndChild();

				ImGui::SameLine();

				ImGui::BeginChild("Window Display", ImVec2(0, 0), ImGuiChildFlags_None, ImGuiWindowFlags_HorizontalScrollbar);

				if (current_callback && *current_callback != nullptr)
					(*current_callback.value())();

				ImGui::EndChild();
			}

			ImGui::End();
			ImGui::PopStyleVar();

			return is_open;
		},
		"MacroQuest"
	);
}

void OpenContextMenu()
{
	// force a mouse position update for 2 reasons:
	// first, mouse position is completely invalid unless it has been clicked inside an imgui window
	// second, this makes the animation cleaner by hinting at the correct rendering position on the screen
	POINT cursorPos = { 0 };
	GetCursorPos(&cursorPos);
	ImGui::GetIO().AddMousePosEvent((float)cursorPos.x, (float)cursorPos.y);
	s_contextOpen = true;
}

void MaybeShowContextMenu()
{
	ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.f);
	static ImVec2 cr = ImGui::GetContentRegionMax();

	ImGui::SetNextWindowClass(&cl);

	if (ImGui::BeginPopup("Context Popup", ImGuiWindowFlags_NoMove))
	{
		ImGui::MenuItem("Menu Item 1");
		ImGui::MenuItem("Menu Item 2");
		ImGui::MenuItem("Menu Item 3");
		ImGui::MenuItem("Menu Item 4");
		ImGui::MenuItem("Menu Item 5");
		if (ImGui::BeginMenu("SubMenu"))
		{
			ImGui::MenuItem("Menu Item 1");
			ImGui::MenuItem("Menu Item 2");
			ImGui::MenuItem("Menu Item 3");

			if (ImGui::BeginMenu("Another SubMenu"))
			{
				ImGui::MenuItem("Menu Item 1");
				ImGui::MenuItem("Menu Item 2");
				ImGui::MenuItem("Menu Item 3");

				ImGui::EndMenu();
			}

			ImGui::EndMenu();
		}

		ImGui::EndPopup();
	}

	ImGui::PopStyleVar();
}

} // namespace LauncherImGui
