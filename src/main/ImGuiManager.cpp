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
#include "ImGuiManager.h"

#include "GraphicsEngine.h"
#include "Logging.h"
#include "MQ2ImGuiTools.h"
#include "MQPluginHandler.h"
#include "imgui/ImGuiUtils.h"

#include "mq/base/WString.h"
#include "mq/imgui/Widgets.h"
#include "mq/utils/Benchmarks.h"
#include "mq/utils/HotKeys.h"

#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
#include "imgui/implot/implot.h"
#include "imgui/implot/implot_internal.h"

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
		int items_count = static_cast<int>(items.size());

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

			int show_count = isNeedFilter ? static_cast<int>(itemScoreVector.size()) : items_count;
			float height = GetTextLineHeightWithSpacing() * ((items_count < 7 ? items_count : 7) + 0.25f) + GetStyle().FramePadding.y * 2.0f;
			if (ImGui::BeginListBox("##ComboWithFilter_itemList", ImVec2(0.0f, height)))
			{
				for (int i = 0; i < show_count; i++)
				{
					int idx = isNeedFilter ? itemScoreVector[i].first : i;
					PushID(idx);
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
				ImGui::EndListBox();
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

bool gbHideCursorAttachment = false;
int gDrawWindowFrameSkipCount = -1;

enum class DebugTab {
	MouseInput = 0,
	Graphics = 1,
	Fonts = 2,
	Cursor = 3,

	None = -1,
};
static DebugTab s_selectedDebugTab = DebugTab::None;
static DebugTab s_selectDebugTab = DebugTab::None;
static bool s_overlayDebug = false;
static bool s_enableCursorAttachment = true;
static bool s_shiftToDock = false;
static bool s_keyboardNavImGui = false;
static bool s_imguiIgnoreClampWindow = false;
static ImGuiWindow* s_cursorLastHoveredWindow = nullptr;  // only used for comparison. might be invalid.
static std::string s_cursorLastHoveredWindowName;
static bool s_showCursorAttachment = false;

static mq::PlatformHotkey gToggleConsoleHotkey;
static const char gToggleConsoleDefaultBind[] = "ctrl+`";
static bool gbToggleConsoleHotkeyReady = false;

// Critical error occurred and imgui needs to be reset
bool gbManualResetRequired = false;

static ImFontAtlas* s_fontAtlas = nullptr;

static char ImGuiSettingsFile[MAX_PATH] = { 0 };
static char ImGuiLogFile[MAX_PATH] = { 0 };

static bool s_deferredClearSettings = false;
extern bool gbToggleConsoleRequested;
extern bool gbAutoDockspaceViewport;
extern bool gbAutoDockspacePreserveRatio;

// We forward declare this so that we don't need windows.h types in the header
LRESULT  ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT  ImGui_ImplWin32_WndProcHandlerEx(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam, ImGuiIO& io);

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
	engine::Initialize();
	InitializeImGuiConsole();

	AddSettingsPanel("Overlay", ImGuiManager_OverlaySettings);
}

static void ShutdownOverlayComponents()
{
	RemoveSettingsPanel("Overlay");

	ShutdownImGuiConsole();
	engine::Shutdown();
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

//----------------------------------------------------------------------------
//============================================================================

struct EQFontData
{
	std::string      fontName;
	int              fontSize = 0;
	int              fontID = 0;
	bool             valid = false;

	HFONT            hFont;
	HDC              hDC;

	ImFont*          pImFont = nullptr;
	ImFontConfig     fontConfig;
	CCachedFont*     pCachedFont = nullptr;
};

static std::vector<EQFontData> s_eqFontData;
static bool s_eqFontsLoaded = false;

ImFont* ImGuiManager_GetEQImFont(int fontID)
{
	if (fontID >= 0 && fontID < static_cast<int>(s_eqFontData.size()))
		return s_eqFontData[fontID].pImFont;

	return nullptr;
}

std::unique_ptr<uint8_t[]> GetRawFontData(HFONT hFont, HDC hdc, uint32_t& dataSize)
{
	std::unique_ptr<uint8_t[]> fontData;
	HFONT oldFont = static_cast<HFONT>(SelectObject(hdc, hFont));

	// Get the size of the font data
	dataSize = GetFontData(hdc, 0, 0, nullptr, 0);
	if (dataSize != GDI_ERROR)
	{
		fontData = std::make_unique<uint8_t[]>(dataSize);

		// Actually get the font data
		if (GetFontData(hdc, 0, 0, fontData.get(), dataSize) == GDI_ERROR)
		{
			fontData.reset();
		}
	}

	SelectObject(hdc, oldFont);
	return fontData;
}

static bool LoadFontData(ImFontAtlas* fontAtlas, EQFontData& fontData)
{
	// Load font data from HFONT
	uint32_t fontDataSize = 0;
	auto fontDataBuffer = GetRawFontData(fontData.hFont, fontData.hDC, fontDataSize);
	if (!fontDataBuffer)
		return false;

	fontData.fontConfig = ImFontConfig();
	fontData.fontConfig.FontData = fontDataBuffer.get();
	fontData.fontConfig.FontDataSize = fontDataSize;
	fontData.fontConfig.FontDataOwnedByAtlas = false;
	fontData.fontConfig.OversampleH = 2;
	fontData.fontConfig.OversampleV = 2;
	fontData.fontConfig.PixelSnapH = true;
	strcpy_s(fontData.fontConfig.Name, fontData.fontName.c_str());

	// FreeType renders the fonts slightly bigger than the renderer that EQ uses. To compensate, we
	// adjust the font size slightly. It isn't perfect, however. Unless we use the same font rasterizer,
	// the appearance will be slightly different if you look close enough.
	switch (fontData.fontSize)
	{
	case 10:
		fontData.fontConfig.SizePixels = 9;
		break;

	default:
		fontData.fontConfig.SizePixels = static_cast<float>(fontData.fontSize) - 2;
		break;
	}

	ImFont* newFont = fontAtlas->AddFont(&fontData.fontConfig);

	// Preserve existing pointer so that we don't invalidate any client code using the font.
	if (fontData.pImFont)
	{
		*fontData.pImFont = *newFont;
	}
	else
	{
		fontData.pImFont = newFont;
	}

	fontData.valid = true;
	return true;
}

static std::string CreateFontDisplayName(SLogFontEntry& fontEntry, int num)
{
	std::string name = fmt::format("EQ Font {} - {} {}", num, fontEntry.lf.lfFaceName, fontEntry.lf.lfHeight);
	if (fontEntry.lf.lfWeight == FW_THIN)
		name += " Thin";
	if (fontEntry.lf.lfWeight == FW_BOLD)
		name += " Bold";

	return name;
}

static bool LoadEQFonts(ImFontAtlas* fontAtlas)
{
	s_eqFontData.resize(NumFontStyles);

	for (int i = 0; i < NumFontStyles; ++i)
	{
		CCachedFont* font = CCachedFont::Get(i);
		if (!font) break;
		CFontManager* pFontMgr = font->pFontManager;

		SLogFontEntry& fontEntry = pFontMgr->arLogFonts[i];

		if (font->hDC == INVALID_HANDLE_VALUE || font->hFont == INVALID_HANDLE_VALUE)
			continue;

		EQFontData& fontData = s_eqFontData[i];

		fontData.pCachedFont = font;
		fontData.fontID = i;
		fontData.fontName = CreateFontDisplayName(fontEntry, i);
		fontData.fontSize = font->nHeight;
		fontData.hDC = font->hDC;
		fontData.hFont = font->hFont;
		fontData.valid = false;

		LoadFontData(fontAtlas, fontData);
	}

	return true;
}

void ImGuiManager_BuildFonts(ImFontAtlas* fontAtlas)
{
	LoadFonts();

	mq::imgui::ConfigureFonts(fontAtlas);
	s_eqFontsLoaded = LoadEQFonts(fontAtlas);
}

void ImGuiManager_CleanupFonts()
{
	delete s_fontAtlas;
	s_fontAtlas = nullptr;

	s_eqFontsLoaded = false;
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
	if (ImGui::Begin("ImGui Debug", &s_overlayDebug))
	{
		if (ImGui::BeginTabBar("#DebugTabs"))
		{
			if (ImGui::BeginTabItem("Mouse", nullptr, (s_selectDebugTab == DebugTab::MouseInput) ? ImGuiTabItemFlags_SetSelected : 0))
			{
				s_selectedDebugTab = DebugTab::MouseInput;
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
				s_selectedDebugTab = DebugTab::Graphics;

				engine::ImGuiRenderDebug_UpdateImGui();
				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("Fonts", nullptr, (s_selectDebugTab == DebugTab::Fonts) ? ImGuiTabItemFlags_SetSelected : 0))
			{
				s_selectedDebugTab = DebugTab::Fonts;

				FontPicker();
				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("Cursor", nullptr, (s_selectDebugTab == DebugTab::Cursor) ? ImGuiTabItemFlags_SetSelected : 0))
			{
				s_selectedDebugTab = DebugTab::Cursor;

				ImGui::TextUnformatted("Hovered Window:");
				ImGui::SameLine();
				if (!s_cursorLastHoveredWindowName.empty())
				{
					ImGui::TextColored(MQColor(255, 255, 0).ToImColor(), "%s", s_cursorLastHoveredWindowName.c_str());
				}
				else
				{
					ImGui::TextColored(MQColor(128, 128, 128).ToImColor(), "None");
				}

				ImGui::TextUnformatted("Has Cursor Attachment:");
				ImGui::SameLine();
				if (pCursorAttachment && pCursorAttachment->IsActive())
				{
					ImGui::TextColored(MQColor(0, 255, 0).ToImColor(), "Yes");
				}
				else
				{
					ImGui::TextColored(MQColor(255, 0, 0).ToImColor(), "No");
				}

				ImGui::TextUnformatted("Show Cursor Attachment:");
				ImGui::SameLine();
				if (s_showCursorAttachment)
				{
					ImGui::TextColored(MQColor(0, 255, 0).ToImColor(), "Yes");
				}
				else
				{
					ImGui::TextColored(MQColor(255, 0, 0).ToImColor(), "No");
				}

				ImGui::EndTabItem();
			}

			s_selectDebugTab = DebugTab::None;

			ImGui::EndTabBar();
		}
	}
	if (!s_overlayDebug)
	{
		WritePrivateProfileBool("MacroQuest", "OverlayDebug", false, mq::internal_paths::MQini);
	}
	ImGui::End();
}

static void ResumeOverlay()
{
	// Reset Implot context because it might be dirty after unexpected abort.
	if (auto imPlotContext = ImPlot::GetCurrentContext())
	{
		ImPlot::ResetCtxForNextPlot(imPlotContext);
		ImPlot::ResetCtxForNextSubplot(imPlotContext);
	}

	gbManualResetRequired = false;
}

static int s_showForFrames = 0;

static bool ImGuiManager_DetectCursorAttachment()
{
	if (!s_enableCursorAttachment || !pCursorAttachment || !pCursorAttachment->IsActive())
	{
		s_cursorLastHoveredWindow = nullptr;
		s_cursorLastHoveredWindowName.clear();
		return false;
	}

	auto& io = ImGui::GetIO();
	auto* context = ImGui::GetCurrentContext();
	bool show = false;
	ImGuiWindow* overlappedWindow = nullptr;

	if (context->HoveredWindow)
	{
		show = true;
		overlappedWindow = context->HoveredWindow;
	}
	else
	{
		// Check to see if the cursor would overlap a window
		ImVec2 attachmentSize(50, 50);

		ImGuiWindow* attachmentWindow = ImGui::FindWindowByName("##CursorAttachment");
		if (attachmentWindow)
		{
			attachmentSize = attachmentWindow->Size;
		}

		// Create rect
		ImRect attachmentRect(io.MousePos + ImVec2(1, 1), io.MousePos + ImVec2(1, 1) + attachmentSize);

		for (int i = context->Windows.Size - 1; i >= 0; --i)
		{
			ImGuiWindow* window = context->Windows[i];

			if (!window->Active)
				continue;
			if (window->Hidden || window->IsFallbackWindow)
				continue;
			if (window->Flags & ImGuiWindowFlags_NoMouseInputs)
				continue;
			if (window->Viewport != context->MouseViewport)
				continue;

			// Using the clipped AABB, a child window will typically be clipped by its parent (not always)
			if (!window->OuterRectClipped.Overlaps(attachmentRect))
				continue;

			// Support for one rectangular hole in any given window
			// FIXME: Consider generalizing hit-testing override (with more generic data, callback, etc.) (#1512)
			if (window->HitTestHoleSize.x != 0)
			{
				ImVec2 hole_pos(window->Pos.x + (float)window->HitTestHoleOffset.x, window->Pos.y + (float)window->HitTestHoleOffset.y);
				ImVec2 hole_size(window->HitTestHoleSize.x, window->HitTestHoleSize.y);
				if (ImRect(hole_pos, hole_pos + hole_size).Contains(io.MousePos))
					continue;
			}

			show = true;
			overlappedWindow = window;
			break;
		}
	}

	if (show)
	{
		s_showForFrames = 3;
	}
	else if (s_showForFrames > 0)
	{
		--s_showForFrames;
	}

	if (s_cursorLastHoveredWindow != overlappedWindow && s_selectedDebugTab == DebugTab::Cursor)
	{
		s_cursorLastHoveredWindow = overlappedWindow;

		if (overlappedWindow)
			s_cursorLastHoveredWindowName = overlappedWindow->Name;
		else
			s_cursorLastHoveredWindowName.clear();
	}

	gbHideCursorAttachment = s_showForFrames > 0;
	return s_showForFrames > 0;
}

void ImGuiManager_NewFrame()
{
	ImGuiContext* g = ImGui::GetCurrentContext();
	const bool has_textures = (g->IO.BackendFlags & ImGuiBackendFlags_RendererHasTextures) != 0;

	if (s_fontAtlas)
	{
		ImFontAtlasUpdateNewFrame(s_fontAtlas, g->FrameCount, has_textures);
	}
	
	ImGui::NewFrame();
}

void ImGuiManager_DrawFrame()
{
	MQScopedBenchmark bm1(bmUpdateImGui);

	DoImGuiUpdateInternal();

	// Plugins will get disabled if an error occurs.
	if (!gbManualResetRequired)
	{
		MQScopedBenchmark bm2(bmPluginsUpdateImGui);
		PluginsUpdateImGui();
	}
	else
	{
		ImGuiViewport* mainViewport = ImGui::GetMainViewport();
		ImVec2 pos = ImVec2(mainViewport->Size.x / 2 - 180, 60);
		ImVec2 size = ImVec2(360, 120);

		ImGui::SetNextWindowPos(pos, ImGuiCond_Appearing);
		ImGui::SetNextWindowSize(size, ImGuiCond_Appearing);

		ImGui::Begin("MQOverlay Paused", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);

		float windowWidth = ImGui::GetWindowSize().x;

		{
			const char* message = "The Overlay is paused due to an ImGui error.";
			float textWidth = ImGui::CalcTextSize(message).x;

			ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
			ImGui::TextColored(MQColor(255, 255, 0).ToImColor(), message);
		}

		{
			const char* message = "Please fix the problem before resuming.";
			float textWidth = ImGui::CalcTextSize(message).x;

			ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
			ImGui::TextColored(MQColor(255, 255, 0).ToImColor(), message);
		}

		ImGui::NewLine();

		{
			ImGui::SetCursorPosX((windowWidth - 160) * .5f);

			if (ImGui::Button("Resume Overlay", ImVec2(160, 0)))
				ResumeOverlay();
		}

		ImGui::End();
	}

	if (s_overlayDebug)
	{
		UpdateImGuiDebugInfo();
	}

	s_showCursorAttachment = ImGuiManager_DetectCursorAttachment();
	if (s_showCursorAttachment)
	{
		ImGuiManager_DrawCursorAttachment();
	}
}

void ImGuiManager_DrawCursorAttachment()
{
	if (!pCursorAttachment || !pCursorAttachment->IsActive())
		return;

	ImVec2 pos = ImGui::GetMousePos() + ImVec2(1, 1);
	ImVec2 size = pCursorAttachment->GetClientRect().GetSize();

	ImGui::SetNextWindowPos(pos, ImGuiCond_Always);
	ImGui::SetNextWindowSize(size, ImGuiCond_Always);

	bool show = ImGui::Begin("##CursorAttachment", nullptr,
		ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoFocusOnAppearing
		| ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoDocking);
	if (show)
	{
		ImGuiWindow* window = ImGui::GetCurrentWindow();
		CXRect rect = CXRect(CXPoint(pos), CXSize(size));

		if (pCursorAttachment->pBGStaticAnim)
		{
			mq::imgui::DrawScreenPiece(window->DrawList, pCursorAttachment->pBGStaticAnim, rect);
		}

		if (pCursorAttachment->pOverlayStaticAnim)
		{
			mq::imgui::DrawScreenPiece(window->DrawList, pCursorAttachment->pOverlayStaticAnim, rect);
		}

		ECursorAttachmentType type = static_cast<ECursorAttachmentType>(pCursorAttachment->Type);

		if (type == eCursorAttachment_SpellGem)
		{
			if (pCursorAttachment->pSpellGem && pCursorAttachment->pSpellGem->IsVisible())
			{
				// Draw the spell gem using the widget API because we want it to also reserve space in the window.
				ImGui::SetCursorPos(pCursorAttachment->pSpellGem->Location.TopLeft());
				mq::imgui::SpellGem("##SpellGem", pCursorAttachment->pSpellGem, ImGuiSpellGemFlags_None);
			}
		}

		// Draw button text
		if (!pCursorAttachment->ButtonText.empty())
		{
			CXRect textRect;
			if (pCursorAttachment->pBGStaticAnim)
			{
				textRect = pCursorAttachment->pBGStaticAnim->rect;
				textRect += pos;
			}
			else
			{
				textRect = rect;
			}

			mq::imgui::DrawEQText(window->DrawList, FontStyle_14, pCursorAttachment->ButtonText.c_str(),
				textRect, MQColor(255, 255, 255), DrawText_VCenter | DrawText_HCenter);
		}

		// Draw currency/stack size
		if (pCursorAttachment->Quantity > 0)
		{
			window->DrawList->PushClipRectFullScreen();

			CCachedFont* eqFont = CCachedFont::Get(pCursorAttachment->TextFontStyle);
			ImFont* font = ImGuiManager_GetEQImFont(pCursorAttachment->TextFontStyle);

			if (font && eqFont)
			{
				fmt::memory_buffer buf;
				fmt::format_to(fmt::appender(buf), "{:d}", pCursorAttachment->Quantity);
				buf.push_back(0);

				if (type == eCursorAttachment_Item
					|| type == eCursorAttachment_InvSlot
					|| type == eCursorAttachment_ItemLink
					|| type == eCursorAttachment_KronoSlot)
				{
					int textWidth = static_cast<int>(font->CalcTextSizeA(static_cast<float>(eqFont->nHeight), FLT_MAX, -1.0f, buf.data(), nullptr).x);
					if (textWidth < 10) textWidth = 10;

					CXRect textRect = rect;
					textRect.bottom -= 6;
					textRect.right -= 6;
					textRect.top = textRect.bottom - 10;
					textRect.left = textRect.right - textWidth;

					window->DrawList->AddRectFilled(textRect.TopLeft(), textRect.BottomRight(),
						MQColor(64, 64, 64).ToImU32());

					mq::imgui::DrawEQText(window->DrawList, pCursorAttachment->TextFontStyle, buf.data(),
						textRect);
				}
				else
				{
					CXRect textRect = rect;
					textRect.top = rect.bottom - 4;
					textRect.bottom = textRect.top + eqFont->nHeight;

					window->DrawList->AddRectFilled(textRect.TopLeft(), textRect.BottomRight(),
						MQColor(64, 64, 64).ToImU32());

					mq::imgui::DrawEQText(window->DrawList, pCursorAttachment->TextFontStyle, buf.data(),
						textRect, MQColor(255, 255, 255), DrawText_NoWrap | DrawText_HCenter);
				}
			}

			window->DrawList->PopClipRect();
		}

		// Ensure that this window is last in the viewport
		ImGui::BringWindowToDisplayFront(window);
	}

	ImGui::End();
}

static bool HandleWndProcEvent(HWND hWnd, uint32_t msg, uintptr_t wParam, intptr_t lParam)
{
	if (msg == WM_KEYDOWN
		&& gbToggleConsoleHotkeyReady)
	{
		// Match the vkey and modifiers
		if (wParam == gToggleConsoleHotkey.virtualKey)
		{
			// Check the modifiers, don't allow repeats.
			if ((HIWORD(lParam) & KF_REPEAT) == 0
				&& mq::IsHotKeyModifiersPressed(gToggleConsoleHotkey))
			{
				gbToggleConsoleRequested = true;
				return true;
			}
		}
	}

	return false;
}

bool ImGuiManager_HandleWndProc(HWND hWnd, uint32_t msg, uintptr_t wParam, intptr_t lParam)
{
	if (HandleWndProcEvent(hWnd, msg, wParam, lParam))
		return true;

	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	return false;
}

bool ImGuiManager_HandleWndProcEx(HWND hWnd, uint32_t msg, uintptr_t wParam, intptr_t lParam, ImGuiIO& io)
{
	if (HandleWndProcEvent(hWnd, msg, wParam, lParam))
		return true;

	if (ImGui_ImplWin32_WndProcHandlerEx(hWnd, msg, wParam, lParam, io))
		return true;

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

void ImGuiManager_ReloadContext()
{
	if (ImGui::GetCurrentContext() != nullptr)
	{
		ImGui::DestroyContext();
	}

	ImGuiManager_CreateContext();
}

void ImGuiManager_CreateContext()
{
	bool buildFonts = false;
	if (s_fontAtlas == nullptr)
	{
		s_fontAtlas = new ImFontAtlas();
		buildFonts = true;
	}
	else
	{
		// If we crashed in the middle of a frame, the atlas might be locked.
		s_fontAtlas->Locked = false;
	}

	// Initialize ImGui context
	ImGui::CreateContext(s_fontAtlas);
	ImPlot::CreateContext();

	if (buildFonts)
	{
		ImGuiManager_BuildFonts(s_fontAtlas);
	}

	ImGuiIO& io = ImGui::GetIO();

	fmt::format_to(ImGuiSettingsFile, "{}/MacroQuest_Overlay.ini", mq::internal_paths::Config);

	if (s_deferredClearSettings)
	{
		std::error_code ec;
		if (std::filesystem::is_regular_file(ImGuiSettingsFile, ec))
			std::filesystem::remove(ImGuiSettingsFile, ec);
	}
	io.IniFilename = &ImGuiSettingsFile[0];

	fmt::format_to(ImGuiLogFile, "{}/MacroQuest_Overlay.log", mq::internal_paths::Logs);
	io.LogFilename = &ImGuiLogFile[0];

	ImGui::StyleColorsDark();
	mq::imgui::ConfigureStyle();

	io.IgnoreClampWindow = s_imguiIgnoreClampWindow;
	io.ConfigDockingWithShift = s_shiftToDock;

	if (s_keyboardNavImGui)
	{
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	}
	else
	{
		io.ConfigFlags &= ~ImGuiConfigFlags_NavEnableKeyboard;
	}
}

void ImGuiManager_DestroyContext()
{
	ImPlot::DestroyContext();
	ImGui::DestroyContext();

	ImGuiManager_CleanupFonts();
}

void ImGuiManager_OverlaySettings()
{
	if (ImGui::Checkbox("Enable Viewports", &gbEnableImGuiViewports))
	{
		WritePrivateProfileBool("Overlay", "EnableViewports", gbEnableImGuiViewports, mq::internal_paths::MQini);
		ResetOverlay();
	}

	ImGui::SameLine();
	mq::imgui::HelpMarker("The viewports feature allows ImGui windows to be dragged out of the window into "
		"their own floating windows. This feature is BETA quality and has some known issues.\n"
		"\n"
		"Viewports are disabled when running in full screen mode.");

	if (ImGui::Checkbox("Resize EverQuest viewport to fit dockspace (Experimental)", &gbAutoDockspaceViewport))
	{
		if (!gbAutoDockspaceViewport)
		{
			ImGuiManager_ResetGameViewport();
		}

		WritePrivateProfileBool("Overlay", "ResizeEQViewport", gbAutoDockspaceViewport, mq::internal_paths::MQini);
	}

	ImGui::SameLine();
	mq::imgui::HelpMarker("When enabled, if a window is docked to the side of the screen,\n"
		"the EverQuest viewport will be resized to fit the available screen space");

	ImGui::BeginDisabled(!gbAutoDockspaceViewport);
	ImGui::Indent();
	{
		if (ImGui::Checkbox("Preserve aspect ratio", &gbAutoDockspacePreserveRatio))
		{
			WritePrivateProfileBool("Overlay", "ResizeEQViewportPreserveRatio", gbAutoDockspacePreserveRatio, mq::internal_paths::MQini);
		}
	}
	ImGui::Unindent();
	ImGui::EndDisabled();

	if (ImGui::Checkbox("Emulate EverQuest Cursor", &s_enableCursorAttachment))
	{
		WritePrivateProfileBool("Overlay", "CursorAttachment", s_enableCursorAttachment, mq::internal_paths::MQini);
	}
	ImGui::SameLine();
	mq::imgui::HelpMarker("When enabled, MacroQuest will take over drawing the EQ Cursor when\n"
		"it is near to or hovering over an ImGui window.");

	if (ImGui::Checkbox("Require Shift to Dock", &s_shiftToDock))
	{
		WritePrivateProfileBool("Overlay", "DockingWithShift", s_shiftToDock, mq::internal_paths::MQini);

		auto& io = ImGui::GetIO();
		io.ConfigDockingWithShift = s_shiftToDock;
	}
	ImGui::SameLine();
	mq::imgui::HelpMarker("When enabled, HOLD Shift to Dock a Window");

	if (ImGui::Checkbox("Navigate with Keyboard", &s_keyboardNavImGui))
	{
		auto& io = ImGui::GetIO();
		if (s_keyboardNavImGui)
		{
			io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		}
		else
		{
			io.ConfigFlags &= ~ImGuiConfigFlags_NavEnableKeyboard;
		}

		WritePrivateProfileBool("Overlay", "EnableKeyboardNav", s_keyboardNavImGui, mq::internal_paths::MQini);
	}
	ImGui::SameLine();
	mq::imgui::HelpMarker("When enabled, Tab and Arrow Keys will navigate active ImGui window.");

	if (ImGui::Checkbox("Ignore Window Clamping", &s_imguiIgnoreClampWindow))
	{
		WritePrivateProfileBool("Overlay", "ImGuiIgnoreClampWindow", s_imguiIgnoreClampWindow, mq::internal_paths::MQini);

		auto& io = ImGui::GetIO();
		io.IgnoreClampWindow = s_imguiIgnoreClampWindow;
	}

	ImGui::SameLine();
	mq::imgui::HelpMarker("For ISBoxer users, enable this if your ImGui window positions reset when switching windows");

	ImGui::NewLine();

	if (ImGui::Button("Clear Saved ImGui Window Settings"))
	{
		s_deferredClearSettings = true;
		ResetOverlay();
	}
}

void ImGuiManager_ResetGameViewport()
{
	if (pEverQuestInfo)
	{
		pEverQuestInfo->Render_MinX = 0;
		pEverQuestInfo->Render_MinY = 0;
		pEverQuestInfo->Render_MaxX = pEverQuestInfo->ScreenXRes;
		pEverQuestInfo->Render_MaxY = pEverQuestInfo->ScreenYRes;
	}
}


//============================================================================

void MQOverlayCommand(SPAWNINFO* pSpawn, char* szLine)
{
	char szArg[MAX_STRING] = { 0 };
	GetArg(szArg, szLine, 1);

	bool showUsage = false;

	if (ci_equals(szArg, "help"))
	{
		showUsage = true;
	}
	else if (ci_equals(szArg, "reload"))
	{
		ResetOverlay();
	}
	else if (ci_equals(szArg, "resume"))
	{
		if (gbManualResetRequired)
		{
			WriteChatf("Resuming overlay...");
			ResumeOverlay();
		}
		else
		{
			WriteChatf("Overlay is not suspended; Can not resume.");
		}
	}
	else if (ci_equals(szArg, "stop"))
	{
		ShutdownOverlayComponents();
	}
	else if (ci_equals(szArg, "debug"))
	{
		char szParam[MAX_STRING] = { 0 };
		GetArg(szParam, szLine, 2);

		bool newOverlayDebug = s_overlayDebug;
		s_selectDebugTab = DebugTab::None;

		if (szParam[0] == 0)
		{
			newOverlayDebug = !newOverlayDebug;
		}
		else if (ci_equals(szParam, "mouse"))
		{
			s_selectDebugTab = DebugTab::MouseInput;
			s_overlayDebug = true;
		}
		else if (ci_equals(szParam, "graphics"))
		{
			s_selectDebugTab = DebugTab::Graphics;
			s_overlayDebug = true;
		}
		else if (ci_equals(szParam, "fonts"))
		{
			s_selectDebugTab = DebugTab::Fonts;
			s_overlayDebug = true;
		}
		else if (ci_equals(szParam, "cursor"))
		{
			s_selectDebugTab = DebugTab::Cursor;
			s_overlayDebug = true;
		}

		if (newOverlayDebug != s_overlayDebug)
		{
			s_overlayDebug = newOverlayDebug;
			WriteChatf("Overlay debug info is now: %s", s_overlayDebug ? "\agOn" : "\arOff");
			WritePrivateProfileBool("MacroQuest", "OverlayDebug", s_overlayDebug, mq::internal_paths::MQini);
		}
	}
	else if (ci_equals(szLine, "start"))
	{
		StartupOverlayComponents();
	}
	else if (ci_equals(szArg, "cursor"))
	{
		char szParam[MAX_STRING] = { 0 };
		GetArg(szParam, szLine, 2);

		if (ci_equals(szParam, "on"))
		{
			s_enableCursorAttachment = true;
		}
		else if (ci_equals(szParam, "off"))
		{
			s_enableCursorAttachment = false;
		}
		else if (szParam[0])
		{
			showUsage = true;
		}
		else
		{
			s_enableCursorAttachment = !s_enableCursorAttachment;
		}

		WriteChatf("Overlay cursor attachment emulation is now: %s",
			s_enableCursorAttachment ? "\agOn" : "\arOff");

		WritePrivateProfileBool("Overlay", "CursorAttachment", s_enableCursorAttachment, mq::internal_paths::MQini);
	}
	else
	{
		showUsage = true;
	}

	if (showUsage)
	{
		WriteChatf("\ayUsage: /mqoverlay <options>");
		WriteChatf("\ayOverlay Control Options:");
		//WriteChatf("\ay  [reload | resume | debug | stop | start]")
		WriteChatf("\ay  reload\ax    - Reload the overlay by shutting it down and starting it back up again.");
		WriteChatf("\ay  resume\ax    - Resumes the overlay in the event that an error has occurred.");
		WriteChatf("\ay  stop\ax      - Turns off the overlay. This state does not persist between MQ sessions.");
		WriteChatf("\ay  start\ax     - Turns on the overlay.");
		WriteChatf("\ay  cursor\ax \ag[on|off]\ax - Turn cursor attachment emulation on/off (no parma will toggle).");
	}
}

void ImGuiManager_Initialize()
{
	bmUpdateImGui = AddMQ2Benchmark("UpdateImGui");
	bmPluginsUpdateImGui = AddMQ2Benchmark("UpdateImGuiPlugins");

	gbRenderImGui = GetPrivateProfileBool("MacroQuest", "RenderImGui", gbRenderImGui, mq::internal_paths::MQini);
	s_overlayDebug = GetPrivateProfileBool("MacroQuest", "OverlayDebug", s_overlayDebug, mq::internal_paths::MQini);

	gbEnableImGuiViewports = GetPrivateProfileBool("Overlay", "EnableViewports", false, mq::internal_paths::MQini);
	gbAutoDockspaceViewport = GetPrivateProfileBool("Overlay", "ResizeEQViewport", false, mq::internal_paths::MQini);
	gbAutoDockspacePreserveRatio = GetPrivateProfileBool("Overlay", "ResizeEQViewportPreserveRatio", false, mq::internal_paths::MQini);
	s_imguiIgnoreClampWindow = GetPrivateProfileBool("Overlay", "ImGuiIgnoreClampWindow", false, mq::internal_paths::MQini);
	s_enableCursorAttachment = GetPrivateProfileBool("Overlay", "CursorAttachment", s_enableCursorAttachment, mq::internal_paths::MQini);
	s_shiftToDock = GetPrivateProfileBool("Overlay", "DockingWithShift", false, mq::internal_paths::MQini);
	s_keyboardNavImGui = GetPrivateProfileBool("Overlay", "EnableKeyboardNav", false, mq::internal_paths::MQini);

	if (gbWriteAllConfig)
	{
		WritePrivateProfileBool("Overlay", "EnableViewports", gbEnableImGuiViewports, mq::internal_paths::MQini);
		WritePrivateProfileBool("Overlay", "ResizeEQViewport", gbAutoDockspaceViewport, mq::internal_paths::MQini);
		WritePrivateProfileBool("Overlay", "ResizeEQViewportPreserveRatio", gbAutoDockspacePreserveRatio, mq::internal_paths::MQini);
		WritePrivateProfileBool("Overlay", "ImGuiIgnoreClampWindow", s_imguiIgnoreClampWindow, mq::internal_paths::MQini);
		WritePrivateProfileBool("Overlay", "CursorAttachment", s_enableCursorAttachment, mq::internal_paths::MQini);
		WritePrivateProfileBool("Overlay", "DockingWithShift", s_shiftToDock, mq::internal_paths::MQini);
		WritePrivateProfileBool("Overlay", "EnableKeyboardNav", s_keyboardNavImGui, mq::internal_paths::MQini);
	}

	// TODO: application-wide keybinds could use an encapsulated interface. For now I'm just dumping his here since we need it to
	// connect to the win32 hook and control the imgui console.
	::GetPrivateProfileStringA("MacroQuest", "ToggleConsoleKey", gToggleConsoleDefaultBind,
		gToggleConsoleHotkey.keybind, static_cast<DWORD>(lengthof(gToggleConsoleHotkey.keybind)), mq::internal_paths::MQini.c_str());

	if (!gbToggleConsoleHotkeyReady)
	{
		if (mq::ConvertStringToModifiersAndVirtualKey(gToggleConsoleHotkey.keybind,
			gToggleConsoleHotkey.modifiers, gToggleConsoleHotkey.virtualKey))
		{
			LOG_INFO("Toggle console keybind: {0}", gToggleConsoleHotkey.keybind);
			gbToggleConsoleHotkeyReady = true;
		}
		else if (strlen(gToggleConsoleHotkey.keybind) > 0)
		{
			LOG_WARN("Unable to parse toggle console keybind: {0}", gToggleConsoleHotkey.keybind);
			strcpy_s(gToggleConsoleHotkey.keybind, "");

			gbToggleConsoleHotkeyReady = false;
		}
	}

	if (gbWriteAllConfig)
	{
		WritePrivateProfileBool("MacroQuest", "RenderImGui", gbRenderImGui, mq::internal_paths::MQini);
		WritePrivateProfileBool("MacroQuest", "OverlayDebug", s_overlayDebug, mq::internal_paths::MQini);
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
	engine::OnUpdateFrame();
	PulseFonts();
}

} // namespace mq
