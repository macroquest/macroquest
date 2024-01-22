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

// map of panels in the main GUI window
static std::map<std::string, std::function<void()>> s_panels;

// map of viewport windows to render
static std::map<std::string, std::function<bool()>> s_viewports;

// vector (to preserve order) of groups that the context menu should render
static std::vector<std::pair<std::string, std::function<void()>>> s_menus;

// we want the context menu to call OpenPopup exactly once per right click, so we need a state toggle
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

void OpenWindow(
	const std::function<bool()>& render,
	const std::string& label
)
{
	s_viewports.emplace(label, render);
}

bool AddMainPanel(const std::string& name, const std::function<void()> callback)
{
	const auto& [_, added] = s_panels.emplace(name, callback);
	return added;
}

bool RemoveMainPanel(const std::string& name)
{
	return s_panels.erase(name) > 0;
}

bool AddContextGroup(const std::string& name, const std::function<void()>& callback)
{
	s_menus.emplace_back(std::make_pair(name, callback));
	return true;
}

bool RemoveContextGroup(const std::string& name)
{
	auto it = std::find_if(s_menus.begin(), s_menus.end(), [&name](const auto& pair) { return pair.first == name; });
	if (it != s_menus.end())
	{
		s_menus.erase(it);
		return true;
	}

	return false;
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
	OpenWindow(
		[]()
		{
			ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.f);

			bool is_open = true;
			if (ImGui::Begin("MacroQuest", &is_open))
			{
				static std::optional<const std::function<void()>*> current_callback;

				ImGui::BeginChild("Window Selection", ImVec2(ImGui::GetContentRegionAvail().x * 0.2f, 0), ImGuiChildFlags_Border, ImGuiWindowFlags_HorizontalScrollbar);
				for (const auto& [name, callback] : s_panels)
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

void OpenMessageBox(ImGuiViewport* viewport, const std::string& message, const std::string& title)
{
	OpenWindow(
		[viewport, message, title]()
		{
			bool is_open = true;

			auto monitor = ImGui::GetViewportPlatformMonitor(viewport != nullptr ? viewport : ImGui::GetMainViewport());
			ImGui::SetNextWindowSize({ 300.f, 200.f }, ImGuiCond_Always);
			ImGui::SetNextWindowPos(monitor->WorkPos + (monitor->WorkSize * 0.5f), ImGuiCond_Always, { 0.5f, 0.5f });

			ImGui::SetNextWindowClass(&cl);
			if (ImGui::Begin(title.c_str(), &is_open))
			{
				ImGui::Spacing();

				float win_width = ImGui::GetWindowSize().x;
				float text_width = ImGui::CalcTextSize(message.c_str()).x;

				float indent = std::max(20.f, (win_width - text_width) * 0.5f);

				ImGui::PushTextWrapPos(win_width - indent);
				ImGui::TextWrapped(message.c_str());
				ImGui::PopTextWrapPos();

				ImGui::Spacing();

				auto button_size = ImGui::CalcTextSize("OK") + ImGui::GetStyle().FramePadding * 2.f;
				auto avail = ImGui::GetContentRegionAvail();

				if (avail.x > button_size.x)
					ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (avail.x - button_size.x) * 0.5f);

				if (avail.y > button_size.y)
					ImGui::SetCursorPosY(ImGui::GetCursorPosY() + avail.y - button_size.y);

				if (ImGui::Button("OK"))
					is_open = false;
			}

			ImGui::End();
			return is_open;
		},
		title
	);
}

void MaybeShowContextMenu()
{
	ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.f);
	static ImVec2 cr = ImGui::GetContentRegionMax();

	ImGui::SetNextWindowClass(&cl);

	if (ImGui::BeginPopup("Context Popup", ImGuiWindowFlags_NoMove))
	{
		for (const auto& [name, callback] : s_menus)
		{
			callback();
			ImGui::Separator();
		}

		if (ImGui::MenuItem("Exit"))
			PostQuitMessage(0);

		ImGui::EndPopup();
	}

	ImGui::PopStyleVar();
}

} // namespace LauncherImGui
