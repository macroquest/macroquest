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

void MaybeShowContextMenu();
void Run(const std::function<bool()>& mainWindow, const std::function<bool()>& mainLoop)
{
	LauncherImGui::Backend::Init(hMainWnd);

	auto drawMain = [&mainWindow]() -> bool
		{
			ImGui::Begin("Main Window", nullptr, ImGuiWindowFlags_NoDecoration);
			bool ret = mainWindow();
			MaybeShowContextMenu();

			for (auto it = s_viewports.begin(); it != s_viewports.end();)
			{
				ImGuiWindowClass cl;
				cl.ViewportFlagsOverrideSet |= ImGuiViewportFlags_NoAutoMerge;
				cl.ParentViewportId = 0;
				ImGui::SetNextWindowClass(&cl);
				if (!it->second())
					it = s_viewports.erase(it);
				else
					++it;
			}

			ImGui::End();

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
	// these needs to be be set to true whenever we attempt to show the context menu
	//static bool do_init;
	//do_init = true;

	ImGui::PushID("Context Menu");
	ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.f);

	// we do this as a popup to let imgui handle styling as a popup. _However_ imgui fails to handle some
	// things correctly because we aren't popping up over an imgui window, but are instead implicitly
	// creating a viewport.
	if (s_contextOpen)
	{
		ImGui::OpenPopup("Context Popup");
		s_contextOpen = false;
	}

	static ImVec2 cr = ImGui::GetContentRegionMax();
	ImGuiWindowClass cl;
	cl.ViewportFlagsOverrideSet |= ImGuiViewportFlags_TopMost;
	cl.ParentViewportId = 0;
	ImGui::SetNextWindowClass(&cl);
	//ImGui::SetNextWindowPos(popup_pos, ImGuiCond_Always, popup_pivot);
	if (ImGui::BeginPopup("Context Popup"))
	{
		if (ImGui::Button("Another Popup"))
			ImGui::OpenPopup("Another Popup");

		if (ImGui::BeginPopup("Another Popup"))
		{
			ImGui::Text("Check it out");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");
			ImGui::Text("Right Here Right Here Right Here Right Here Right Here Right Here Right Here Right Here ");

			ImGui::EndPopup();
		}

		static bool test;
		ImGui::SmallCheckbox("Test With Some Really Long Text To See If It Goes Off The Screen", &test);
		ImGui::SmallCheckbox("Test With Some Really Long Text To See If It Goes Off The Screen", &test);
		ImGui::SmallCheckbox("Test With Some Really Long Text To See If It Goes Off The Screen", &test);
		ImGui::SmallCheckbox("Test With Some Really Long Text To See If It Goes Off The Screen", &test);

		ImGui::Separator();

		ImGui::Text("%.2f, %.2f", cr.x, cr.y);

		{
			auto cursorPos = ImGui::GetMousePos();
			ImGui::Text("%.2f %.2f", cursorPos.x, cursorPos.y);

			for (const auto& monitor : ImGui::GetPlatformIO().Monitors)
			{
				ImGui::Text("%.2f %.2f %.2f %.2f", monitor.WorkPos.x, monitor.WorkPos.y, monitor.WorkSize.x, monitor.WorkSize.y);
			}
		}

		ImGui::Separator();

		ImGui::Text("FocusLost: %s", ImGui::GetIO().AppFocusLost ? "true" : "false");
		ImGui::Text("Clicked: %s", ImGui::IsMouseClicked(ImGuiMouseButton_Left) ? "true" : "false");
		ImGui::Text("Focused: %s", ImGui::IsWindowFocused() ? "true" : "false");
		ImGui::Text("WantCaptureMouse: %s (%s)",
			ImGui::GetIO().WantCaptureMouse ? "true" : "false",
			ImGui::GetIO().WantCaptureMouseUnlessPopupClose ? "true" : "false");

		ImGui::Separator();

		auto currentViewport = ImGui::GetWindowViewport();
		auto currentWindow = (HWND)currentViewport->PlatformHandleRaw;
		WINDOWINFO pw;
		::GetWindowInfo(currentWindow, &pw);
		::GetWindow(currentWindow, GW_OWNER);
		ImGui::Text("Current Window: 0x%p", currentViewport->PlatformHandleRaw);
		ImGui::Text("Current Window: 0x%p", currentViewport->PlatformHandle);
		ImGui::Text("Focused Window: 0x%p", ::GetForegroundWindow());

		ImGui::Separator();

		if (ImGui::SmallButton("Close"))
			ImGui::CloseCurrentPopup();

		for (const auto& [name, callback] : s_menuGroups)
		{
			ImGui::PushID(name.c_str());
			ImGui::BeginChild("grouping", ImVec2(0.f, 0.f), ImGuiChildFlags_Border, ImGuiWindowFlags_None);

			callback();

			ImGui::EndChild();
			ImGui::PopID();
		}

		// we need to set the viewport of the popup to active because imgui doesn't automatically
		// but after we do, we need to check if it's lost focus because imgui doesn't handle that
		// outside of imgui windows
		//static auto currentViewport = ImGui::GetWindowViewport();
		//auto newViewport = ImGui::GetWindowViewport();
		//if (currentViewport == newViewport)
		//{
		//	// PlatformHandleRaw should always be the HWND on windows, but some backends
		//	// might leave it nullptr, which means we assume that PlatformHandle is the HWND
		//	HWND currentWindow = currentViewport->PlatformHandleRaw == nullptr ?
		//		(HWND)currentViewport->PlatformHandle :
		//		(HWND)currentViewport->PlatformHandleRaw;

		//	// it can take 2 frames to populate the handles
		//	if (currentWindow)
		//	{
		//		if (do_init)
		//		{
		//			::SetForegroundWindow(currentWindow);
		//			do_init = false;
		//		}
		//		else if (currentWindow != ::GetForegroundWindow())
		//		{
		//			ImGui::CloseContextMenu();
		//		}
		//	}
		//}
		//else
		//{
		//	currentViewport = newViewport;
		//	do_init = true;
		//}

		cr = ImGui::GetContentRegionMax();

		ImGui::EndPopup();
	}

	ImGui::PopStyleVar();
	ImGui::PopID();
}

} // namespace LauncherImGui
