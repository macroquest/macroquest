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

struct Modal
{
	float Alpha = 0.f;
	ImGuiViewportFlags OriginalFlagsSet = ImGuiViewportFlags_None;
	ImGuiViewportFlags OriginalFlagsClear = ImGuiViewportFlags_None;
	ImGuiID ParentViewportID = 0;
	std::unique_ptr<ImDrawList> Background;
};

static std::map<std::string, Modal> s_modals;

bool ImGui::SmallCheckbox(const char* label, bool* v)
{
	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, 0.f);
	bool pressed = ImGui::Checkbox(label, v);
	ImGui::PopStyleVar();
	return pressed;
}

static void DimParentViewport(ImGuiViewportP* viewport, Modal& modal)
{
    ImRect viewport_rect = viewport->GetMainRect();
	ImDrawList* draw_list = ImGui::GetForegroundDrawList(viewport);

	// TODO: the ratio should fade in/out like this
    //if (modal_open)
    //    g.DimBgRatio = ImMin(g.DimBgRatio + g.IO.DeltaTime * 6.0f, 1.0f);
    //else // (this means we need to persist the dim until it's 0 or less)
    //    g.DimBgRatio = ImMax(g.DimBgRatio - g.IO.DeltaTime * 10.0f, 0.0f);
	const ImU32 dim_bg_col = ImGui::GetColorU32(ImGuiCol_ModalWindowDimBg, 1.f);

	draw_list->AddRectFilled(viewport->Pos, viewport->Pos + viewport->Size, dim_bg_col);
}

void ImGui::OpenModal(const std::string& name)
{
	auto viewport = (ImGuiViewportP*)ImGui::GetWindowViewport();
	if (viewport == nullptr)
		viewport = (ImGuiViewportP*)ImGui::GetMainViewport();

	if (viewport == nullptr)
		return;

	Modal modal;
	modal.Alpha = viewport->Alpha * ImGui::GetStyle().DisabledAlpha;
	modal.ParentViewportID = viewport->ID;

	if (viewport->Window != nullptr)
	{
		modal.OriginalFlagsSet = viewport->Window->WindowClass.ViewportFlagsOverrideSet;
		modal.OriginalFlagsClear = viewport->Window->WindowClass.ViewportFlagsOverrideClear;
		viewport->Window->WindowClass.ViewportFlagsOverrideSet |= ImGuiViewportFlags_NoInputs | ImGuiViewportFlags_NoFocusOnClick;
		viewport->Window->WindowClass.ViewportFlagsOverrideClear &= ~(ImGuiViewportFlags_NoInputs | ImGuiViewportFlags_NoFocusOnClick);
	}

	s_modals[name] = std::move(modal);
}

bool ImGui::BeginModal(const std::string& name, bool* p_open, ImGuiWindowFlags flags)
{
	ImGui::ShowMetricsWindow();
	auto it = s_modals.find(name);
	if (it == s_modals.end())
		return false;

	Modal& modal = it->second;

	ImGuiContext& g = *ImGui::GetCurrentContext();
	auto viewport = (ImGuiViewportP*)ImGui::FindViewportByID(modal.ParentViewportID);
	if (viewport != nullptr)
	{
		if ((g.NextWindowData.Flags & ImGuiNextWindowDataFlags_HasPos) == 0)
				ImGui::SetNextWindowPos(viewport->GetCenter(), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.5f));

		//viewport->Alpha = modal.Alpha;
		DimParentViewport(viewport, modal);
	}

	if ((g.NextWindowData.Flags & ImGuiNextWindowDataFlags_HasSize) == 0)
		flags |= ImGuiWindowFlags_AlwaysAutoResize;

    flags |= ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoSavedSettings;
	const bool is_open = ImGui::Begin(name.c_str(), p_open, flags);
    if (!is_open || (p_open && !*p_open)) // NB: is_open can be 'false' when the popup is completely clipped (e.g. zero size display)
    {
		EndModal();
		if (is_open)
			CloseModal();
        return false;
    }

    return is_open;
}

void ImGui::EndModal()
{
    ImGuiContext& g = *GImGui;
    ImGuiWindow* window = g.CurrentWindow;

    if (g.NavWindow == window)
        NavMoveRequestTryWrapping(window, ImGuiNavMoveFlags_LoopY);

    // Child-popups don't need to be laid out
    IM_ASSERT(g.WithinEndChild == false);
    if (window->Flags & ImGuiWindowFlags_ChildWindow)
        g.WithinEndChild = true;
    ImGui::End();
    g.WithinEndChild = false;
}

void ImGui::CloseModal()
{
    IM_ASSERT(s_modals.size() > 0);

	ImGuiContext& g = *GImGui;
	ImGuiWindow* window = g.CurrentWindow;

	auto it = s_modals.find(window->Name);
	if (it == s_modals.end())
		return;

	Modal& modal = it->second;
	auto viewport = (ImGuiViewportP*)ImGui::FindViewportByID(modal.ParentViewportID);
	if (viewport != nullptr && viewport->Window != nullptr)
	{
		viewport->Window->WindowClass.ViewportFlagsOverrideSet = modal.OriginalFlagsSet;
		viewport->Window->WindowClass.ViewportFlagsOverrideClear = modal.OriginalFlagsClear;
	}

	s_modals.erase(it);
}

namespace LauncherImGui {

void OpenWindow(
	const std::function<bool()>& draw,
	const std::string& label
)
{
	s_viewports.emplace(label, draw);
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

static ImGuiWindowClass s_contextClass = []()
	{
		ImGuiWindowClass cl;
		cl.ViewportFlagsOverrideSet |= ImGuiViewportFlags_TopMost;
		cl.ViewportFlagsOverrideClear |= ImGuiViewportFlags_NoFocusOnAppearing | ImGuiViewportFlags_NoFocusOnClick;
		cl.ParentViewportId = 0;
		cl.ClassId = 1;
		return cl;
	}();

void MaybeShowContextMenu();
void Run(const std::function<bool()>& mainLoop)
{
	LauncherImGui::Backend::Init(hMainWnd);

	auto drawMain = []()
	{
		for (auto it = s_viewports.begin(); it != s_viewports.end();)
		{
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
	};

	while (mainLoop())
	{
		LauncherImGui::Backend::DrawFrame(drawMain);
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

			auto monitor = ImGui::GetViewportPlatformMonitor(ImGui::GetMainViewport());
			ImGui::SetNextWindowSize({ 640.f, 480.f }, ImGuiCond_FirstUseEver);
			ImGui::SetNextWindowPos(monitor->WorkPos + (monitor->WorkSize * 0.5f), ImGuiCond_FirstUseEver, { 0.5f, 0.5f });

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
			ImGui::SetNextWindowSize({ 300.f, 200.f }, ImGuiCond_Appearing);
			ImGui::SetNextWindowPos(monitor->WorkPos + (monitor->WorkSize * 0.5f), ImGuiCond_Appearing, { 0.5f, 0.5f });

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

	ImGui::SetNextWindowClass(&s_contextClass);

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
