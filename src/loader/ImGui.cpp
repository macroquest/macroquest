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

#include "ImGui.h"
#include "MacroQuest.h"

#include "imgui_backend/imgui_engine.h"
#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"

#include "imgui/ImGuiTreePanelWindow.h"
#include "login/AutoLogin.h"

#include "spdlog/spdlog.h"

 // map of panels in the main GUI window
static mq::imgui::ImGuiTreePanelWindow* s_mainWindow = nullptr;
static std::map<const char*, void(*)()> s_pendingPanels;

// map of viewport windows to render
static std::map<std::string, std::function<bool()>> s_viewports;
static std::optional<std::string> s_focusViewport;

// vector (to preserve order) of groups that the context menu should render
static std::vector<std::pair<std::string, std::function<void()>>> s_menus;

// we want the context menu to call OpenPopup exactly once per right click, so we need a state toggle
static bool s_contextOpen;

// storage for filename strings for the backend
static std::string s_iniFilename;
static std::string s_logFilename;

static ImGuiWindowClass s_viewportClass = []
	{
		ImGuiWindowClass cl;
		cl.ViewportFlagsOverrideSet |= ImGuiViewportFlags_NoAutoMerge | ImGuiViewportFlags_CanHostOtherWindows;
		return cl;
	}();

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
	ImGuiViewportFlags OriginalFlagsSet = ImGuiViewportFlags_None;
	ImGuiViewportFlags OriginalFlagsClear = ImGuiViewportFlags_None;
	ImGuiID ParentViewportID = 0;
};

static std::map<std::string, Modal> s_modals;

struct DimRatio
{
	float Ratio = 0.f;
	bool Open = true;
};

static std::map<ImGuiID, DimRatio> s_dimRatios;

static bool DimParentViewport(ImGuiViewportP* viewport, DimRatio& ratio)
{
	if (ratio.Ratio > 0.f)
	{
		const ImU32 dim_bg_col = ImGui::GetColorU32(ImGuiCol_ModalWindowDimBg, ratio.Ratio);

		ImDrawList* draw_list = ImGui::GetForegroundDrawList(viewport);
		draw_list->AddRectFilled(viewport->Pos, viewport->Pos + viewport->Size, dim_bg_col);
	}

	const ImGuiIO io = ImGui::GetIO();
	if (ratio.Open&& ratio.Ratio < 1.f)
		ratio.Ratio = std::min(ratio.Ratio + io.DeltaTime * 6.f, 1.f);
	else if (!ratio.Open)
		ratio.Ratio = std::max(ratio.Ratio - io.DeltaTime * 10.f, 0.f);

	return ratio.Open || ratio.Ratio > 0.f;
}

namespace LauncherImGui {

bool SmallCheckbox(const char* label, bool* v)
{
	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 0.f, ImGui::GetStyle().FramePadding.y });
	const bool pressed = ImGui::Checkbox(label, v);
	ImGui::PopStyleVar();
	return pressed;
}

void RenderTableCheckmark()
{
	const auto square_sz = ImGui::GetFrameHeight();
	const auto pad = ImMax(1.0f, IM_TRUNC(square_sz / 6.0f));
	ImGui::RenderCheckMark(
		ImGui::GetCurrentWindow()->DrawList,
		ImGui::GetCursorScreenPos() + ImVec2(pad, 0.f),
		ImGui::GetColorU32(ImGuiCol_Text),
		square_sz - pad * 2.0f);
}

void RenderTableCircle(ImU32 color, bool filled)
{
	auto radius = ImGui::GetFrameHeight() * 0.5f;
	const auto center = ImGui::GetCursorScreenPos() + ImVec2{ radius, radius * 0.75f };

	radius *= 0.85f;
	if (filled)
		ImGui::GetCurrentWindow()->DrawList->AddCircleFilled(center, radius, color);
	else
		ImGui::GetCurrentWindow()->DrawList->AddCircle(center, radius, color);
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
	modal.ParentViewportID = viewport->ID;

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

	for (auto window : g.Windows)
	{
		if (window != nullptr && window->ViewportId == modal.ParentViewportID)
			window->Flags |= ImGuiWindowFlags_NoInputs;
	}

	const auto viewport = static_cast<ImGuiViewportP*>(ImGui::FindViewportByID(modal.ParentViewportID));
	if (viewport != nullptr && (g.NextWindowData.HasFlags & ImGuiNextWindowDataFlags_HasPos) == 0)
	{
		ImGui::SetNextWindowPos(viewport->GetCenter(), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.5f));
	}

	if (viewport && viewport->PlatformUserData && ImGui::GetPlatformIO().Platform_GetWindowFocus(viewport))
	{
		const auto window = ImGui::FindWindowByName(name.c_str());
		if (window != nullptr && window->Viewport != nullptr && window->Viewport->PlatformHandle != nullptr)
			ImGui::GetPlatformIO().Platform_SetWindowFocus(window->Viewport);

		ImGui::SetNextWindowFocus();
	}

	if ((g.NextWindowData.HasFlags & ImGuiNextWindowDataFlags_HasSize) == 0)
		flags |= ImGuiWindowFlags_AlwaysAutoResize;

	flags |= ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoSavedSettings;
	ImGui::SetNextWindowClass(&s_viewportClass);
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
	IM_ASSERT(g.WithinEndChildID != 0);
	const ImGuiID backup_within_end_child_id = g.WithinEndChildID;
	if (window->Flags & ImGuiWindowFlags_ChildWindow)
		g.WithinEndChildID = window->ID;
	ImGui::End();
	g.WithinEndChildID = backup_within_end_child_id;
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
	s_focusViewport = label;
}

void SelectMainPanel(const std::string& name)
{
	OpenMainWindow();

	if (s_mainWindow != nullptr)
		s_mainWindow->FocusPanel(name);
}

void AddMainPanel(const char* name, void(*callback)())
{
	if (s_mainWindow == nullptr)
		s_pendingPanels.emplace(name, callback);
	else
		s_mainWindow->AddPanel(name, callback);
}

void RemoveMainPanel(const char* name)
{
	if (s_mainWindow != nullptr)
		s_mainWindow->RemovePanel(name);
}

bool AddContextGroup(const std::string& name, const std::function<void()>& callback)
{
	s_menus.emplace_back(name, callback);
	return true;
}

bool RemoveContextGroup(const std::string& name)
{
	const auto it = std::find_if(
		s_menus.begin(), s_menus.end(),
		[&name](const auto& pair) { return pair.first == name; });

	if (it != s_menus.end())
	{
		s_menus.erase(it);
		return true;
	}

	return false;
}

void MaybeShowContextMenu();
void Run(const std::function<bool()>& mainLoop)
{
	s_mainWindow = new mq::imgui::ImGuiTreePanelWindow("MacroQuest", { 640.f, 480.f });
	for (const auto& [name, callback] : s_pendingPanels)
		s_mainWindow->AddPanel(name, callback);

	s_pendingPanels.clear();

	s_iniFilename = (std::filesystem::path{ internal_paths::Config } / "MacroQuest_LauncherUI.ini").string();
	s_logFilename = (std::filesystem::path{ internal_paths::Logs } / "MacroQuest_LauncherUI.log").string();
	Backend::Init(hMainWnd, s_iniFilename.c_str(), s_logFilename.c_str());

	auto draw_main = []()
		{
			if (s_focusViewport)
			{
				const auto window = ImGui::FindWindowByName(s_focusViewport->c_str());
				if (window != nullptr && window->Viewport != nullptr)
					ImGui::GetPlatformIO().Platform_SetWindowFocus(window->Viewport);
			}

			static bool showPathError = false;
			if (!EQPathErrorMessage.empty())
			{
				LauncherImGui::OpenModal("EverQuest Launch Error");
				showPathError = true;
			}

			if (showPathError)
			{
				ImGui::SetNextWindowSize(ImVec2(800, 400), ImGuiCond_Appearing);
				if (LauncherImGui::BeginModal("EverQuest Launch Error", &showPathError, 0))
				{
					ImGui::Text("Failed to launch one or more EverQuest instances:");
					ImGui::Separator();

					ImVec2 size = ImGui::GetContentRegionAvail() - ImVec2(1, ImGui::GetFrameHeightWithSpacing());
					ImGui::BeginChild("##TextArea", size);
					ImGui::TextWrapped("%s", EQPathErrorMessage.c_str());

					ImGui::EndChild();

					if (ImGui::Button("Close"))
					{
						EQPathErrorMessage.clear();
						showPathError = false;
						LauncherImGui::CloseModal();
					}

					LauncherImGui::EndModal();
				}
			}
			if (!showPathError && !EQPathErrorMessage.empty())
			{
				EQPathErrorMessage.clear();
			}

			for (auto it = s_viewports.begin(); it != s_viewports.end();)
			{
				if (s_focusViewport && it->first == *s_focusViewport)
				{
					ImGui::SetNextWindowFocus();
					s_focusViewport.reset();
				}

				ImGui::SetNextWindowClass(&s_viewportClass);
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

	static std::chrono::time_point<std::chrono::steady_clock> s_nextFrame = std::chrono::steady_clock::now();
	while (mainLoop())
	{
		LauncherImGui::Backend::DrawFrame(draw_main);
		std::this_thread::sleep_until(s_nextFrame);

		// 33 1/3 FPS
		s_nextFrame = s_nextFrame + std::chrono::milliseconds(30);
	}

	LauncherImGui::Backend::Cleanup();
	delete s_mainWindow;
	s_mainWindow = nullptr;
}

bool HandleWndProc(HWND hWnd, uint32_t msg, uintptr_t wParam, intptr_t lParam)
{
	return LauncherImGui::Backend::HandleWndProc(hWnd, msg, wParam, lParam);
}

void OpenMainWindow()
{
	OpenWindow(
		[]
		{
			ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.f);

			bool is_open = true;

			const auto monitor = ImGui::GetViewportPlatformMonitor(ImGui::GetMainViewport());
			ImGui::SetNextWindowPos(monitor->WorkPos + (monitor->WorkSize * 0.5f), ImGuiCond_FirstUseEver, { 0.5f, 0.5f });

			if (s_mainWindow != nullptr)
				s_mainWindow->Draw(&is_open);

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

void OpenMessageBox(ImGuiViewport* viewport, const std::string& message, const std::string& title, const ImVec2& size)
{
	OpenWindow(
		[viewport, message, title, size]
		{
			bool is_open = true;

			const auto monitor = ImGui::GetViewportPlatformMonitor(viewport != nullptr ? viewport : ImGui::GetMainViewport());
			ImGui::SetNextWindowSize(size, ImGuiCond_Appearing);
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
			if (strncmp(name.c_str(), "##", 2) != 0)
				ImGui::TextColored({ 0.69f, 0.55f, 0.26f, 1.f }, name.c_str());

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
