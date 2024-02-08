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

#include "spdlog/spdlog.h"

namespace {
// map of panels in the main GUI window
std::map<std::string, std::function<void()>> s_panels;

// map of viewport windows to render
std::map<std::string, std::function<bool()>> s_viewports;

// vector (to preserve order) of groups that the context menu should render
std::vector<std::pair<std::string, std::function<void()>>> s_menus;

// we want the context menu to call OpenPopup exactly once per right click, so we need a state toggle
bool s_contextOpen;

static ImGuiWindowClass s_contextClass = []()
	{
		ImGuiWindowClass cl;
		cl.ViewportFlagsOverrideSet |= ImGuiViewportFlags_TopMost;
		cl.ViewportFlagsOverrideClear |= ImGuiViewportFlags_NoFocusOnAppearing | ImGuiViewportFlags_NoFocusOnClick;
		cl.ParentViewportId = 0;
		cl.ClassId = 1;
		return cl;
	}();

struct Modal
{
	float Alpha = 0.f;
	ImGuiViewportFlags OriginalFlagsSet = ImGuiViewportFlags_None;
	ImGuiViewportFlags OriginalFlagsClear = ImGuiViewportFlags_None;
	ImGuiID ParentViewportID = 0;
};

std::map<std::string, Modal> s_modals;

struct DimRatio
{
	float Ratio = 0.f;
	bool Open = true;
};

std::map<ImGuiID, DimRatio> s_dimRatios;

bool DimParentViewport(ImGuiViewportP* viewport, DimRatio& ratio)
{
	if (ratio.Ratio > 0.f)
	{
		const ImU32 dim_bg_col = ImGui::GetColorU32(ImGuiCol_ModalWindowDimBg, ratio.Ratio);

		ImDrawList* draw_list = ImGui::GetForegroundDrawList(viewport);
		draw_list->AddRectFilled(viewport->Pos, viewport->Pos + viewport->Size, dim_bg_col);
	}

	const ImGuiIO io = ImGui::GetIO();
	if (ratio.Open && ratio.Ratio < 1.f)
		ratio.Ratio = std::min(ratio.Ratio + io.DeltaTime * 6.f, 1.f);
	else if (!ratio.Open)
		ratio.Ratio = std::max(ratio.Ratio - io.DeltaTime * 10.f, 0.f);

	return ratio.Open || ratio.Ratio > 0.f;
}

}

namespace LauncherImGui {

bool SmallCheckbox(const char* label, bool* v)
{
	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 0.f, ImGui::GetStyle().FramePadding.y });
	const bool pressed = ImGui::Checkbox(label, v);
	ImGui::PopStyleVar();
	return pressed;
}

bool ToggleSlider(const char* label, bool* v)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	if (window->SkipItems) return false;

	const ImGuiContext* g = ImGui::GetCurrentContext();
    const ImGuiStyle& style = g->Style;

	const float height = ImGui::GetFrameHeight();
	const float width = height * 1.55f;
	const float radius = height * 0.5f;

    const ImGuiID id = window->GetID(label);
    const ImVec2 label_size = ImGui::CalcTextSize(label, nullptr, true);

	const ImVec2 pos = window->DC.CursorPos;
    const ImRect total_bb(pos, pos + ImVec2(width + (label_size.x > 0.0f ? style.ItemInnerSpacing.x + label_size.x : 0.0f), label_size.y + style.FramePadding.y * 2.0f));

	const bool pressed = ImGui::InvisibleButton(label, ImVec2(width, height), ImGuiButtonFlags_PressedOnClick);
    if (pressed)
    {
        *v = !*v;
        ImGui::MarkItemEdited(id);
    }

    ImGui::RenderNavHighlight(total_bb, id);

	float t = *v ? 1.f : 0.f;

	if (g->LastActiveId == id)
	{
		constexpr float animation_speed = 8.5f;
		const float t_anim = ImSaturate(g->LastActiveIdTimer * animation_speed);
		t = *v ? t_anim : 1.f - t_anim;
	}

	const ImU32 bg_color = ImGui::GetColorU32(style.Colors[ImGuiCol_FrameBg]);

	ImU32 fg_color;
	if (ImGui::IsItemClicked())
		fg_color = ImGui::GetColorU32(style.Colors[ImGuiCol_ButtonActive]);
	else if (ImGui::IsItemHovered())
		fg_color = ImGui::GetColorU32(style.Colors[ImGuiCol_ButtonHovered]);
	else
		fg_color = ImGui::GetColorU32(style.Colors[ImGuiCol_Button]);

	window->DrawList->AddRectFilled(pos, ImVec2(pos.x + width, pos.y + height), bg_color, height * 0.5f);
	window->DrawList->AddCircleFilled(ImVec2(pos.x + radius + t * (width - radius * 2.f), pos.y + radius), radius - 1.5f, fg_color);

	const auto label_pos = ImVec2(pos.x + width + style.ItemInnerSpacing.x, pos.y + style.FramePadding.y);
    if (g->LogEnabled)
	    ImGui::LogRenderedText(&label_pos, *v ? "[x]" : "[ ]");
    if (label_size.x > 0.0f)
	    ImGui::RenderText(label_pos, label);

	return pressed;
}

void OpenModal(const std::string& name)
{
	auto viewport = static_cast<ImGuiViewportP*>(ImGui::GetWindowViewport());
	if (viewport == nullptr)
		viewport = static_cast<ImGuiViewportP*>(ImGui::GetMainViewport());

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

	s_dimRatios[viewport->ID] = DimRatio{ 0.f, true };
	s_modals[name] = modal;
}

void CloseModal(const std::string& modal_name)
{
    IM_ASSERT(!s_modals.empty());

    const ImGuiContext& g = *GImGui;
    const auto it = s_modals.find(modal_name);
	if (it == s_modals.end())
		return;

    const Modal& modal = it->second;
    if (const auto viewport = static_cast<ImGuiViewportP*>(ImGui::FindViewportByID(modal.ParentViewportID));
		viewport != nullptr && viewport->Window != nullptr)
	{
		viewport->Window->WindowClass.ViewportFlagsOverrideSet = modal.OriginalFlagsSet;
		viewport->Window->WindowClass.ViewportFlagsOverrideClear = modal.OriginalFlagsClear;

		if (const auto dim_it = s_dimRatios.find(viewport->ID); dim_it != s_dimRatios.end())
			dim_it->second.Open = false;

		// we need to focus the parent at the platform level here, just doing it in imgui
		// with ImGui::FocusWindow will not actually set the focus
		if (g.PlatformIO.Platform_SetWindowFocus)
			g.PlatformIO.Platform_SetWindowFocus(viewport);

		// after platform focus has been established, we can set the correct child focus
		ImGui::FocusWindow(viewport->Window, ImGuiFocusRequestFlags_RestoreFocusedChild);
	}

	s_modals.erase(it);
}

bool BeginModal(const std::string& name, bool* p_open, ImGuiWindowFlags flags)
{
	const auto it = s_modals.find(name);
	if (it == s_modals.end())
		return false;

	const Modal& modal = it->second;

	const ImGuiContext& g = *ImGui::GetCurrentContext();
	if (const auto viewport = static_cast<ImGuiViewportP*>(ImGui::FindViewportByID(modal.ParentViewportID));
		viewport != nullptr && (g.NextWindowData.Flags & ImGuiNextWindowDataFlags_HasPos) == 0)
	{
		ImGui::SetNextWindowPos(viewport->GetCenter(), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.5f));
	}

	if ((g.NextWindowData.Flags & ImGuiNextWindowDataFlags_HasSize) == 0)
		flags |= ImGuiWindowFlags_AlwaysAutoResize;

    flags |= ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoSavedSettings;
	const bool is_open = ImGui::Begin(name.c_str(), p_open, flags);
    if (!is_open || (p_open && !*p_open)) // NB: is_open can be 'false' when the popup is completely clipped (e.g. zero size display)
    {
		EndModal();
		if (is_open)
			CloseModal(name);
        return false;
    }

    return is_open;
}

void EndModal()
{
    ImGuiContext& g = *GImGui;
    ImGuiWindow* window = g.CurrentWindow;

    if (g.NavWindow == window)
        ImGui::NavMoveRequestTryWrapping(window, ImGuiNavMoveFlags_LoopY);

    // Child-popups don't need to be laid out
    IM_ASSERT(g.WithinEndChild == false);
    if (window->Flags & ImGuiWindowFlags_ChildWindow)
        g.WithinEndChild = true;
    ImGui::End();
    g.WithinEndChild = false;
}

void CloseModal()
{
    const ImGuiContext& g = *GImGui;
    const ImGuiWindow* window = g.CurrentWindow;

	CloseModal(window->Name);
}

void OpenWindow(
	const std::function<bool()>& draw,
	const std::string& label
)
{
	s_viewports.emplace(label, draw);
}

bool AddMainPanel(const std::string& name, const std::function<void()>& callback)
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
	s_menus.emplace_back(name, callback);
	return true;
}

bool RemoveContextGroup(const std::string& name)
{
	if (const auto it = std::find_if(
		s_menus.begin(), s_menus.end(),
		[&name](const auto& pair) { return pair.first == name; });
		it != s_menus.end())
	{
		s_menus.erase(it);
		return true;
	}

	return false;
}

void MaybeShowContextMenu();
void Run(const std::function<bool()>& mainLoop)
{
	LauncherImGui::Backend::Init(hMainWnd);

	auto draw_main = []()
	{
		for (auto it = s_viewports.begin(); it != s_viewports.end();)
		{
			if (!it->second())
				it = s_viewports.erase(it);
			else
				++it;
		}

		for (auto it = s_dimRatios.begin(); it != s_dimRatios.end();)
		{
			if (const auto viewport = static_cast<ImGuiViewportP*>(ImGui::FindViewportByID(it->first));
				viewport == nullptr)
				it = s_dimRatios.erase(it);
			else
			{
				if (DimParentViewport(viewport, it->second))
					++it;
				else
					it = s_dimRatios.erase(it);
			}
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
		LauncherImGui::Backend::DrawFrame(draw_main);
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

			const auto monitor = ImGui::GetViewportPlatformMonitor(ImGui::GetMainViewport());
			ImGui::SetNextWindowSize({ 640.f, 480.f }, ImGuiCond_FirstUseEver);
			ImGui::SetNextWindowPos(monitor->WorkPos + (monitor->WorkSize * 0.5f), ImGuiCond_FirstUseEver, { 0.5f, 0.5f });

			if (ImGui::Begin("MacroQuest", &is_open))
			{
				static std::optional<const std::function<void()>*> current_callback;

				ImGui::BeginChild("Window Selection", ImVec2(ImGui::GetContentRegionAvail().x * 0.2f, 0), ImGuiChildFlags_Border, ImGuiWindowFlags_HorizontalScrollbar);
				for (const auto& [name, callback] : s_panels)
				{
					const bool is_selected = current_callback && &callback == *current_callback;
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
	POINT cursor_pos = { 0, 0 };
	GetCursorPos(&cursor_pos);
	ImGui::GetIO().AddMousePosEvent(static_cast<float>(cursor_pos.x), static_cast<float>(cursor_pos.y));
	s_contextOpen = true;
}

void OpenMessageBox(ImGuiViewport* viewport, const std::string& message, const std::string& title)
{
	OpenWindow(
		[viewport, &message, &title]()
		{
			bool is_open = true;

			const auto monitor = ImGui::GetViewportPlatformMonitor(viewport != nullptr ? viewport : ImGui::GetMainViewport());
			ImGui::SetNextWindowSize({ 300.f, 200.f }, ImGuiCond_Appearing);
			ImGui::SetNextWindowPos(monitor->WorkPos + (monitor->WorkSize * 0.5f), ImGuiCond_Appearing, { 0.5f, 0.5f });

			if (ImGui::Begin(title.c_str(), &is_open))
			{
				ImGui::Spacing();

				const float win_width = ImGui::GetWindowSize().x;
				const float text_width = ImGui::CalcTextSize(message.c_str()).x;

				const float indent = std::max(20.f, (win_width - text_width) * 0.5f);

				ImGui::PushTextWrapPos(win_width - indent);
				ImGui::TextWrapped(message.c_str());
				ImGui::PopTextWrapPos();

				ImGui::Spacing();

				const auto button_size = ImGui::CalcTextSize("OK") + ImGui::GetStyle().FramePadding * 2.f;
				const auto avail = ImGui::GetContentRegionAvail();

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

	ImGui::SetNextWindowClass(&s_contextClass);

	if (ImGui::BeginPopup("Context Popup", ImGuiWindowFlags_NoMove))
	{
		// at the top we always want a way to open the GUI
		if (ImGui::MenuItem("Open UI"))
			OpenMainWindow();

		ImGui::Separator();

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
