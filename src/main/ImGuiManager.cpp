/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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
#include "ImGuiManager.h"

#include "ImGuiBackend.h"
#include "imgui/ImGuiUtils.h"
#include "MQ2ImGuiTools.h"

#include <imgui/imgui.h>
#define IMGUI_DEFINE_MATH_OPERATORS
#include <imgui/imgui_internal.h>

 // I was trying to avoid including main, but we just got too many globals
#include "MQ2Main.h"

// move to mq/utils? or do we need a new static lib?
#include "common/HotKeys.h"
#include <mq/utils/Benchmarks.h>

#include <cfenv>

namespace ImGui
{
	// https://github.com/forrestthewoods/lib_fts

	// Forward declarations for "private" implementation
	namespace fuzzy_internal {
		static bool fuzzy_match_recursive(const char* pattern, const char* str, int& outScore, const char* strBegin,
			uint8_t const* srcMatches, uint8_t* newMatches, int maxMatches, int nextMatch,
			int& recursionCount, int recursionLimit);
	}
	// Private implementation
	static bool fuzzy_internal::fuzzy_match_recursive(const char* pattern, const char* str, int& outScore,
		const char* strBegin, uint8_t const* srcMatches, uint8_t* matches, int maxMatches,
		int nextMatch, int& recursionCount, int recursionLimit)
	{
		// Count recursions
		++recursionCount;
		if (recursionCount >= recursionLimit)
			return false;

		// Detect end of strings
		if (*pattern == '\0' || *str == '\0')
			return false;

		// Recursion params
		bool recursiveMatch = false;
		uint8_t bestRecursiveMatches[256];
		int bestRecursiveScore = 0;

		// Loop through pattern and str looking for a match
		bool first_match = true;
		while (*pattern != '\0' && *str != '\0') {

			// Found match
			if (tolower(*pattern) == tolower(*str)) {

				// Supplied matches buffer was too short
				if (nextMatch >= maxMatches)
					return false;

				// "Copy-on-Write" srcMatches into matches
				if (first_match && srcMatches) {
					memcpy(matches, srcMatches, nextMatch);
					first_match = false;
				}

				// Recursive call that "skips" this match
				uint8_t recursiveMatches[256];
				int recursiveScore;
				if (fuzzy_match_recursive(pattern, str + 1, recursiveScore, strBegin, matches, recursiveMatches, sizeof(recursiveMatches), nextMatch, recursionCount, recursionLimit)) {

					// Pick best recursive score
					if (!recursiveMatch || recursiveScore > bestRecursiveScore) {
						memcpy(bestRecursiveMatches, recursiveMatches, 256);
						bestRecursiveScore = recursiveScore;
					}
					recursiveMatch = true;
				}

				// Advance
				matches[nextMatch++] = (uint8_t)(str - strBegin);
				++pattern;
			}
			++str;
		}

		// Determine if full pattern was matched
		bool matched = *pattern == '\0' ? true : false;

		// Calculate score
		if (matched) {
			const int sequential_bonus = 15;            // bonus for adjacent matches
			const int separator_bonus = 30;             // bonus if match occurs after a separator
			const int camel_bonus = 30;                 // bonus if match is uppercase and prev is lower
			const int first_letter_bonus = 15;          // bonus if the first letter is matched

			const int leading_letter_penalty = -5;      // penalty applied for every letter in str before the first match
			const int max_leading_letter_penalty = -15; // maximum penalty for leading letters
			const int unmatched_letter_penalty = -1;    // penalty for every letter that doesn't matter

			// Iterate str to end
			while (*str != '\0')
				++str;

			// Initialize score
			outScore = 100;

			// Apply leading letter penalty
			int penalty = leading_letter_penalty * matches[0];
			if (penalty < max_leading_letter_penalty)
				penalty = max_leading_letter_penalty;
			outScore += penalty;

			// Apply unmatched penalty
			int unmatched = (int)(str - strBegin) - nextMatch;
			outScore += unmatched_letter_penalty * unmatched;

			// Apply ordering bonuses
			for (int i = 0; i < nextMatch; ++i) {
				uint8_t currIdx = matches[i];

				if (i > 0) {
					uint8_t prevIdx = matches[i - 1];

					// Sequential
					if (currIdx == (prevIdx + 1))
						outScore += sequential_bonus;
				}

				// Check for bonuses based on neighbor character value
				if (currIdx > 0) {
					// Camel case
					char neighbor = strBegin[currIdx - 1];
					char curr = strBegin[currIdx];
					if (::islower(neighbor) && ::isupper(curr))
						outScore += camel_bonus;

					// Separator
					bool neighborSeparator = neighbor == '_' || neighbor == ' ';
					if (neighborSeparator)
						outScore += separator_bonus;
				}
				else {
					// First letter
					outScore += first_letter_bonus;
				}
			}
		}

		// Return best result
		if (recursiveMatch && (!matched || bestRecursiveScore > outScore)) {
			// Recursive score is better than "this"
			memcpy(matches, bestRecursiveMatches, maxMatches);
			outScore = bestRecursiveScore;
			return true;
		}
		else if (matched) {
			// "this" score is better than recursive
			return true;
		}
		else {
			// no match
			return false;
		}
	}

	static bool fuzzy_match(char const* pattern, char const* str, int& outScore, uint8_t* matches, int maxMatches) {
		int recursionCount = 0;
		int recursionLimit = 10;

		return fuzzy_internal::fuzzy_match_recursive(pattern, str, outScore, str, nullptr, matches, maxMatches, 0, recursionCount, recursionLimit);
	}

	// Public interface
	bool fuzzy_match_simple(char const* pattern, char const* str) {
		while (*pattern != '\0' && *str != '\0') {
			if (tolower(*pattern) == tolower(*str))
				++pattern;
			++str;
		}

		return *pattern == '\0' ? true : false;
	}

	bool fuzzy_match(char const* pattern, char const* str, int& outScore) {
		uint8_t matches[256];
		return fuzzy_match(pattern, str, outScore, matches, sizeof(matches));
	}

	static bool sortbysec_desc(const std::pair<int, int>& a, const std::pair<int, int>& b)
	{
		return (b.second < a.second);
	}

	template <typename T, typename Accessor>
	bool ComboWithFilter(const char* label, int* current_item, const std::vector<T>& items, Accessor&& accessor)
	{
		ImGuiContext& g = *GImGui;

		ImGuiWindow* window = GetCurrentWindow();
		if (window->SkipItems)
			return false;

		const ImGuiStyle& style = ImGui::GetStyle();
		int items_count = items.size();

		// Call the getter to obtain the preview string which is a parameter to BeginCombo()
		const char* preview_value = NULL;
		if (*current_item >= 0 && *current_item < items_count)
			preview_value = accessor(items, *current_item).c_str();

		static char pattern_buffer[256] = { 0 };
		bool isNeedFilter = false;

		char comboButtonName[512] = { 0 };
		ImFormatString(comboButtonName, IM_ARRAYSIZE(comboButtonName), "%s##name_ComboWithFilter_button_%s", preview_value ? preview_value : "", label);

		char name_popup[256 + 10];
		ImFormatString(name_popup, IM_ARRAYSIZE(name_popup), "##name_popup_%s", label);

		// Display items
		// FIXME-OPT: Use clipper (but we need to disable it on the appearing frame to make sure our call to SetItemDefaultFocus() is processed)
		bool value_changed = false;

		const float expected_w = CalcItemWidth();
		ImVec2 item_min = GetItemRectMin();
		bool isNewOpen = false;
		float sz = GetFrameHeight();
		ImVec2 size(sz, sz);
		ImVec2 CursorPos = window->DC.CursorPos;
		ImVec2 pos = CursorPos + ImVec2(expected_w - sz, 0);
		const ImRect bb(pos, pos + size);

		float ButtonTextAlignX = g.Style.ButtonTextAlign.x;
		g.Style.ButtonTextAlign.x = 0;
		if (ImGui::Button(comboButtonName, ImVec2(expected_w, 0)))
		{
			ImGui::OpenPopup(name_popup);
			isNewOpen = true;
		}
		g.Style.ButtonTextAlign.x = ButtonTextAlignX;
		bool hovered = IsItemHovered();
		bool active = IsItemActivated();
		bool pressed = IsItemClicked();

		// Render
		//const ImU32 bg_col = GetColorU32((active && hovered) ? ImGuiCol_ButtonActive : hovered ? ImGuiCol_ButtonHovered : ImGuiCol_Button);
		//RenderFrame(bb.Min, bb.Max, bg_col, true, g.Style.FrameRounding);
		const ImU32 text_col = GetColorU32(ImGuiCol_Text);
		RenderArrow(window->DrawList, bb.Min + ImVec2(ImMax(0.0f, (size.x - g.FontSize) * 0.5f), ImMax(0.0f, (size.y - g.FontSize) * 0.5f)), text_col, ImGuiDir_Down);

		if (isNewOpen)
		{
			memset(pattern_buffer, 0, IM_ARRAYSIZE(pattern_buffer));
		}
		ImVec2 item_max = GetItemRectMax();
		SetNextWindowPos({ CursorPos.x, item_max.y });
		ImGui::SetNextWindowSize({ ImGui::GetItemRectSize().x, 0 });
		if (ImGui::BeginPopup(name_popup))
		{
			//ImGui::PushStyleColor(ImGuiCol_FrameBg, (ImVec4)ImColor(240, 240, 240, 255));
			//ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor(0, 0, 0, 255));
			ImGui::PushItemWidth(-FLT_MIN);
			// Filter input
			if (isNewOpen)
				ImGui::SetKeyboardFocusHere();
			InputText("##ComboWithFilter_inputText", pattern_buffer, 256);

			// Search Icon, you can use it if you load IconsFontAwesome5 https://github.com/juliettef/IconFontCppHeaders
			const ImVec2 label_size = CalcTextSize(ICON_FA_SEARCH, NULL, true);
			const ImVec2 search_icon_pos(ImGui::GetItemRectMax().x - label_size.x - style.ItemInnerSpacing.x * 2, window->DC.CursorPos.y + style.FramePadding.y + g.FontSize * 0.1f);
			RenderText(search_icon_pos, ICON_FA_SEARCH);

			//ImGui::PopStyleColor(2);
			if (pattern_buffer[0] != '\0')
			{
				isNeedFilter = true;
			}

			std::vector<std::pair<int, int> > itemScoreVector;
			if (isNeedFilter)
			{
				for (int i = 0; i < items_count; i++)
				{
					int score = 0;
					bool matched = fuzzy_match(pattern_buffer, accessor(items, i).c_str(), score);
					if (matched)
						itemScoreVector.push_back(std::make_pair(i, score));
				}
				std::sort(itemScoreVector.begin(), itemScoreVector.end(), sortbysec_desc);
			}

			int show_count = isNeedFilter ? itemScoreVector.size() : items_count;
			if (ImGui::ListBoxHeader("##ComboWithFilter_itemList", show_count))
			{
				for (int i = 0; i < show_count; i++)
				{
					int idx = isNeedFilter ? itemScoreVector[i].first : i;
					PushID((void*)(intptr_t)idx);
					const bool item_selected = (idx == *current_item);
					const char* item_text = accessor(items, idx).c_str();
					if (Selectable(item_text, item_selected))
					{
						value_changed = true;
						*current_item = idx;
						CloseCurrentPopup();
					}
					if (item_selected)
						SetItemDefaultFocus();
					PopID();
				}
				ImGui::ListBoxFooter();
			}
			ImGui::PopItemWidth();
			ImGui::EndPopup();
		}


		if (value_changed)
			MarkItemEdited(g.LastItemData.ID);

		return value_changed;
	}
}


namespace mq {

// Benchmarks for ImGui updates
uint32_t bmUpdateImGui = 0;
uint32_t bmPluginsUpdateImGui = 0;

// global imgui toggle
bool gbRenderImGui = true;

enum class DebugTab {
	MouseInput = 0,
	Graphics = 1,
	Fonts = 2,

	None = -1,
};
static DebugTab s_selectDebugTab = DebugTab::None;
static bool s_bOverlayDebug = false;

static mq::PlatformHotkey gToggleConsoleHotkey;
static const char gToggleConsoleDefaultBind[] = "ctrl+`";
static bool gbToggleConsoleHotkeyReady = false;

// Critical error occurred and imgui needs to be reset
bool gbManualResetRequired = false;

extern bool gbToggleConsoleRequested;

void InitializeMQ2Overlay();
void ShutdownMQ2Overlay();
void PulseMQ2Overlay();

void SetOverlayEnabled(bool visible)
{
	gbRenderImGui = visible;
}

bool IsOverlayEnabled()
{
	return gbRenderImGui;
}

static void StartupOverlayComponents()
{
	InitializeMQ2Overlay();
	InitializeImGuiConsole();
}

static void ShutdownOverlayComponents()
{
	ShutdownMQ2Overlay();
	ShutdownImGuiConsole();
}

void DoImGuiUpdateInternal()
{
	// This updates the dockspace first, then the console.
	// TODO: Move dockspace management here.
	UpdateImGuiConsole();

	// After the dockspace is set up, run the imgui update on all modules.
	ModulesUpdateImGui();
}

//============================================================================
// Font Handling

struct FontInfo
{
	std::string name;
	std::string fullname;
	bool fixedWidth = false;
};
std::vector<FontInfo> s_fontInfo;

int CALLBACK FontNameProc(
	const ENUMLOGFONTEXW* lpelfe,   /* pointer to logical-font data */
	const NEWTEXTMETRICEXW* lpntme, /* pointer to physical-font data */
	int FontType,                   /* type of font */
	LPARAM lParam)
{
	if (FontType == TRUETYPE_FONTTYPE && lpelfe->elfLogFont.lfFaceName[0] != L'@')
	{
		FontInfo fontInfo;
		fontInfo.name = wstring_to_utf8(lpelfe->elfLogFont.lfFaceName);
		fontInfo.fullname = wstring_to_utf8(lpelfe->elfFullName);
		fontInfo.fixedWidth = (lpelfe->elfLogFont.lfPitchAndFamily & FIXED_PITCH) != 0;

		s_fontInfo.push_back(std::move(fontInfo));
	}
	return 1;
}

void LoadFonts()
{
	s_fontInfo.clear();

	LOGFONTW logfont;
	ZeroMemory(&logfont, sizeof(logfont));

	logfont.lfCharSet = ANSI_CHARSET;
	wcscpy_s(logfont.lfFaceName, L"\0");

	HDC hdc = GetDC(0);

	EnumFontFamiliesExW(hdc, &logfont, (FONTENUMPROCW)FontNameProc, 0, 0);

	std::sort(std::begin(s_fontInfo), std::end(s_fontInfo),
		[](const FontInfo& a, const FontInfo& b) { return a.fullname.compare(b.fullname) < 0; });

	ReleaseDC(0, hdc);
}

void ImGuiManager_BuildFonts(ImFontAtlas* fontAtlas)
{
	LoadFonts();

	mq::imgui::ConfigureFonts(fontAtlas);
}

void FontPicker()
{
	static int currentfont = 0;
	ImGui::ComboWithFilter("Fonts", &currentfont, s_fontInfo, [](const std::vector<FontInfo>& items, int index) -> const std::string& { return items[index].fullname; });
}

void PulseFonts()
{
}

//============================================================================

void UpdateImGuiDebugInfo()
{
	ImGui::SetNextWindowSize(ImVec2(640, 480), ImGuiCond_FirstUseEver);
	if (ImGui::Begin("ImGui Debug", &s_bOverlayDebug))
	{
		if (ImGui::BeginTabBar("#DebugTabs"))
		{
			if (ImGui::BeginTabItem("Mouse", nullptr, (s_selectDebugTab == DebugTab::MouseInput) ? ImGuiTabItemFlags_SetSelected : 0))
			{
				ImGuiIO& io = ImGui::GetIO();

				// Display ImGuiIO output flags
				ImGui::Text("WantCaptureMouse: %d", io.WantCaptureMouse);
				ImGui::Text("WantCaptureMouseUnlessPopupClose: %d", io.WantCaptureMouseUnlessPopupClose);
				ImGui::Text("WantCaptureKeyboard: %d", io.WantCaptureKeyboard);
				ImGui::Text("WantTextInput: %d", io.WantTextInput);
				ImGui::Text("WantSetMousePos: %d", io.WantSetMousePos);
				ImGui::Text("NavActive: %d, NavVisible: %d", io.NavActive, io.NavVisible);

				// Display Mouse state
				if (ImGui::IsMousePosValid())
					ImGui::Text("Mouse pos: (%g, %g)", io.MousePos.x, io.MousePos.y);
				else
					ImGui::Text("Mouse pos: <INVALID>");
				ImGui::Text("Mouse delta: (%g, %g)", io.MouseDelta.x, io.MouseDelta.y);
				ImGui::Text("Mouse down:");     for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++) if (ImGui::IsMouseDown(i)) { ImGui::SameLine(); ImGui::Text("b%d (%.02f secs)", i, io.MouseDownDuration[i]); }
				ImGui::Text("Mouse clicked:");  for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++) if (ImGui::IsMouseClicked(i)) { ImGui::SameLine(); ImGui::Text("b%d", i); }
				ImGui::Text("Mouse dblclick:"); for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++) if (ImGui::IsMouseDoubleClicked(i)) { ImGui::SameLine(); ImGui::Text("b%d", i); }
				ImGui::Text("Mouse released:"); for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++) if (ImGui::IsMouseReleased(i)) { ImGui::SameLine(); ImGui::Text("b%d", i); }
				ImGui::Text("Mouse wheel: %.1f", io.MouseWheel);

				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("Graphics", nullptr, (s_selectDebugTab == DebugTab::Graphics) ? ImGuiTabItemFlags_SetSelected : 0))
			{
				ImGuiRenderDebug_UpdateImGui();
				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("Fonts", nullptr, (s_selectDebugTab == DebugTab::Fonts) ? ImGuiTabItemFlags_SetSelected : 0))
			{
				FontPicker();
				ImGui::EndTabItem();
			}

			s_selectDebugTab = DebugTab::None;

			ImGui::EndTabBar();
		}
	}
	if (!s_bOverlayDebug)
	{
		WritePrivateProfileBool("MacroQuest", "OverlayDebug", false, mq::internal_paths::MQini);
	}
	ImGui::End();
}

void ImGuiManager_DrawFrame()
{
	if (!gbRenderImGui)
		return;

	// we can't expect that the rounding mode is valid, and imgui respects the rounding mode so set it here and ensure that we reset it before the return
	auto round = fegetround();
	fesetround(FE_TONEAREST);

	IDirect3DStateBlock9* stateBlock = nullptr;
	gpD3D9Device->CreateStateBlock(D3DSBT_ALL, &stateBlock);

	// Prepare the new frame
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();

	try
	{
		ImGui::NewFrame();

		{
			MQScopedBenchmark bm1(bmUpdateImGui);
			DoImGuiUpdateInternal();

			// Plugins will get disabled if an error occurs.
			if (!gbManualResetRequired)
			{
				MQScopedBenchmark bm2(bmPluginsUpdateImGui);
				PluginsUpdateImGui();
			}

			if (s_bOverlayDebug)
			{
				UpdateImGuiDebugInfo();
			}
		}

		// Render the ui
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

		ImGui::UpdatePlatformWindows();

		// Update and Render additional Platform Windows
		ImGuiIO& io = ImGui::GetIO();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			ImGui::RenderPlatformWindowsDefault();
		}
	}
	catch (const ImGuiException& ex)
	{
		gbManualResetRequired = true;

		WriteChatf("\arImGui Critical Failure: %s", ex.what());
		WriteChatf("\arPlugin ImGui has been temporarily paused. To resume imgui, run: \ay/mqoverlay resume\ar");
	}

	stateBlock->Apply();
	stateBlock->Release();

	fesetround(round);
}

bool ImGuiManager_HandleWndProc(uint32_t msg, uintptr_t wparam, intptr_t lparam)
{
	if (msg == WM_KEYDOWN
		&& gbToggleConsoleHotkeyReady)
	{
		// Match the vkey and modifiers
		if (wparam == gToggleConsoleHotkey.virtualKey)
		{
			// Check the modifiers, don't allow repeats.
			if ((HIWORD(lparam) & KF_REPEAT) == 0
				&& mq::IsHotKeyModifiersPressed(gToggleConsoleHotkey))
			{
				gbToggleConsoleRequested = true;
				return true;
			}
		}
	}

	return false;
}

void* ImGuiManager_GetCursorForImGui(ImGuiMouseCursor imguiCursor)
{
	if (pWndMgr)
	{
		const CursorClass* cc = pWndMgr->GetCursorClass();

		// Show OS mouse cursor
		CursorClass::eCursorTypes cursorType = CursorClass::eArrow;

		switch (imguiCursor)
		{
		case ImGuiMouseCursor_ResizeEW:
			cursorType = CursorClass::eEastWest;
			break;
		case ImGuiMouseCursor_ResizeNS:
			cursorType = CursorClass::eNorthSouth;
			break;
		case ImGuiMouseCursor_ResizeNESW:
			cursorType = CursorClass::eNorthEastSouthWest;
			break;
		case ImGuiMouseCursor_ResizeNWSE:
			cursorType = CursorClass::eNorthWestSouthEast;
			break;
		case ImGuiMouseCursor_TextInput:
			cursorType = CursorClass::eBeam;
			break;
		case ImGuiMouseCursor_Arrow:
			break;
		case ImGuiMouseCursor_ResizeAll:
			cursorType = CursorClass::eMove;
			break;

		case ImGuiMouseCursor_Hand:
		default:
			return nullptr;
		}

		return cc->CursorList[cursorType];
	}

	return nullptr;
}

//============================================================================

void MQOverlayCommand(SPAWNINFO* pSpawn, char* szLine)
{
	char szArg[MAX_STRING] = { 0 };
	GetArg(szArg, szLine, 1);

	if (ci_equals(szArg, "reload"))
	{
		ResetOverlay();
	}
	else if (ci_equals(szArg, "resume"))
	{
		gbManualResetRequired = false;
	}
	else if (ci_equals(szArg, "stop"))
	{
		ShutdownOverlayComponents();
	}
	else if (ci_equals(szArg, "debug"))
	{
		char szParam[MAX_STRING] = { 0 };
		GetArg(szParam, szLine, 2);

		bool newOverlayDebug = s_bOverlayDebug;

		if (szParam[0] == 0)
		{
			newOverlayDebug = !newOverlayDebug;
		}
		else if (ci_equals(szParam, "mouse"))
		{
			s_selectDebugTab = DebugTab::MouseInput;
			s_bOverlayDebug = true;
		}
		else if (ci_equals(szParam, "graphics"))
		{
			s_selectDebugTab = DebugTab::Graphics;
			s_bOverlayDebug = true;
		}

		if (newOverlayDebug != s_bOverlayDebug)
		{
			s_bOverlayDebug = newOverlayDebug;
			WriteChatf("Overlay debug info is now: %s", s_bOverlayDebug ? "\agOn" : "\arOff");
			WritePrivateProfileBool("MacroQuest", "OverlayDebug", s_bOverlayDebug, mq::internal_paths::MQini);
		}
	}
	else if (ci_equals(szLine, "start"))
	{
		StartupOverlayComponents();
	}
	else
	{
		WriteChatf("Usage: /mqoverlay [reload | resume | debug | stop | start]");
	}
}

void ImGuiManager_Initialize()
{
	bmUpdateImGui = AddMQ2Benchmark("UpdateImGui");
	bmPluginsUpdateImGui = AddMQ2Benchmark("UpdateImGuiPlugins");

	gbRenderImGui = GetPrivateProfileBool("MacroQuest", "RenderImGui", gbRenderImGui, mq::internal_paths::MQini);
	s_bOverlayDebug = GetPrivateProfileBool("MacroQuest", "OverlayDebug", s_bOverlayDebug, mq::internal_paths::MQini);

	// TODO: application-wide keybinds could use an encapsulated interface. For now I'm just dumping his here since we need it to
	// connect to the win32 hook and control the imgui console.
	::GetPrivateProfileStringA("MacroQuest", "ToggleConsoleKey", gToggleConsoleDefaultBind,
		gToggleConsoleHotkey.keybind, lengthof(gToggleConsoleHotkey.keybind), mq::internal_paths::MQini.c_str());

	if (!gbToggleConsoleHotkeyReady)
	{
		if (mq::ConvertStringToModifiersAndVirtualKey(gToggleConsoleHotkey.keybind,
			gToggleConsoleHotkey.modifiers, gToggleConsoleHotkey.virtualKey))
		{
			SPDLOG_INFO("Toggle console keybind: {0}", gToggleConsoleHotkey.keybind);
			gbToggleConsoleHotkeyReady = true;
		}
		else if (strlen(gToggleConsoleHotkey.keybind) > 0)
		{
			SPDLOG_WARN("Unable to parse toggle console keybind: {0}", gToggleConsoleHotkey.keybind);
			strcpy_s(gToggleConsoleHotkey.keybind, "");

			gbToggleConsoleHotkeyReady = false;
		}
	}

	if (gbWriteAllConfig)
	{
		WritePrivateProfileBool("MacroQuest", "RenderImGui", gbRenderImGui, mq::internal_paths::MQini);
		WritePrivateProfileBool("MacroQuest", "OverlayDebug", s_bOverlayDebug, mq::internal_paths::MQini);
	}

	AddCommand("/mqoverlay", MQOverlayCommand);

	StartupOverlayComponents();
}

void ImGuiManager_Shutdown()
{
	RemoveCommand("/mqoverlay");

	RemoveMQ2Benchmark(bmUpdateImGui);
	RemoveMQ2Benchmark(bmPluginsUpdateImGui);

	ShutdownOverlayComponents();
}

void ImGuiManager_Pulse()
{
	PulseMQ2Overlay();
	PulseFonts();
}

} // namespace mq
