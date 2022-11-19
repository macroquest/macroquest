/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2022 MacroQuest Authors
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
#include "lua_Bindings.h"

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/misc/cpp/imgui_stdlib.h>
#include <sol/sol.hpp>

#include <string>

namespace mq::lua::bindings {

//============================================================================

void RegisterBindings_ImGuiCustom(sol::table& ImGui);
void RegisterBindings_ImGuiWidgets(sol::table& ImGui);
void RegisterBindings_ImGuiUserTypes(sol::state_view state);
void RegisterBindings_ImGuiEnums(sol::state_view state);

void lua_addimgui(std::string_view name, sol::function function, sol::this_state s);
void lua_removeimgui(std::string_view name, sol::this_state s);

#pragma region Core Functions
// Main

static ImGuiStyle* GetStyle()                                                                       { return &ImGui::GetStyle(); }

// Windows
static bool Begin(const std::string& name)                                                          { return ImGui::Begin(name.c_str()); }
static std::tuple<bool, bool> Begin(const std::string& name, bool open)
{
	bool shouldDraw = ImGui::Begin(name.c_str(), &open);

	return std::make_tuple(open, shouldDraw);
}
static std::tuple<bool, bool> Begin(const std::string& name, bool open, int flags)
{
	bool shouldDraw = ImGui::Begin(name.c_str(), &open, static_cast<ImGuiWindowFlags_>(flags));

	return std::make_tuple(open, shouldDraw);
}
static void End()                                                                                   { ImGui::End(); }

// Child Windows
static bool BeginChild(const std::string& name)                                                     { return ImGui::BeginChild(name.c_str()); }
static bool BeginChild(const std::string& name, float sizeX)                                        { return ImGui::BeginChild(name.c_str(), { sizeX, 0 }); }
static bool BeginChild(const std::string& name, float sizeX, float sizeY)                           { return ImGui::BeginChild(name.c_str(), { sizeX, sizeY }); }
static bool BeginChild(const std::string& name, float sizeX, float sizeY, bool border)              { return ImGui::BeginChild(name.c_str(), { sizeX, sizeY }, border); }
static bool BeginChild(const std::string& name, float sizeX, float sizeY, bool border, int flags)   { return ImGui::BeginChild(name.c_str(), { sizeX, sizeY }, border, static_cast<ImGuiWindowFlags>(flags)); }
static void EndChild()                                                                              { ImGui::EndChild(); }

// Windows Utilities
static bool IsWindowAppearing()                                                                     { return ImGui::IsWindowAppearing(); }
static bool IsWindowCollapsed()                                                                     { return ImGui::IsWindowCollapsed(); }
static bool IsWindowFocused()                                                                       { return ImGui::IsWindowFocused(); }
static bool IsWindowFocused(int flags)                                                              { return ImGui::IsWindowFocused(static_cast<ImGuiFocusedFlags>(flags)); }
static bool IsWindowHovered()                                                                       { return ImGui::IsWindowHovered(); }
static bool IsWindowHovered(int flags)                                                              { return ImGui::IsWindowHovered(static_cast<ImGuiHoveredFlags>(flags)); }
static float GetWindowDpiScale()                                                                    { return ImGui::GetWindowDpiScale(); }
static ImGuiViewport* GetWindowViewport()                                                           { return nullptr; /* TODO: GetWindowViewport() ==> UNSUPPORTED */ }
static std::tuple<float, float> GetWindowPos()                                                      { const auto vec2{ ImGui::GetWindowPos() };  return std::make_tuple(vec2.x, vec2.y); }
static std::tuple<float, float> GetWindowSize()                                                     { const auto vec2{ ImGui::GetWindowSize() };  return std::make_tuple(vec2.x, vec2.y); }
static float GetWindowWidth()                                                                       { return ImGui::GetWindowWidth(); }
static float GetWindowHeight()                                                                      { return ImGui::GetWindowHeight(); }

// Prefer using SetNext...
static void SetNextWindowPos(float posX, float posY)                                                { ImGui::SetNextWindowPos({ posX, posY }); }
static void SetNextWindowPos(float posX, float posY, int cond)                                      { ImGui::SetNextWindowPos({ posX, posY }, static_cast<ImGuiCond>(cond)); }
static void SetNextWindowPos(float posX, float posY, int cond, float pivotX, float pivotY)          { ImGui::SetNextWindowPos({ posX, posY }, static_cast<ImGuiCond>(cond), { pivotX, pivotY }); }
static void SetNextWindowSize(float sizeX, float sizeY)                                             { ImGui::SetNextWindowSize({ sizeX, sizeY }); }
static void SetNextWindowSize(float sizeX, float sizeY, int cond)                                   { ImGui::SetNextWindowSize({ sizeX, sizeY }, static_cast<ImGuiCond>(cond)); }
static void SetNextWindowSizeConstraints(float minX, float minY, float maxX, float maxY)            { ImGui::SetNextWindowSizeConstraints({ minX, minY }, { maxX, maxY }); }
static void SetNextWindowContentSize(float sizeX, float sizeY)                                      { ImGui::SetNextWindowContentSize({ sizeX, sizeY }); }
static void SetNextWindowCollapsed(bool collapsed)                                                  { ImGui::SetNextWindowCollapsed(collapsed); }
static void SetNextWindowCollapsed(bool collapsed, int cond)                                        { ImGui::SetNextWindowCollapsed(collapsed, static_cast<ImGuiCond>(cond)); }
static void SetNextWindowFocus()                                                                    { ImGui::SetNextWindowFocus(); }
static void SetNextWindowBgAlpha(float alpha)                                                       { ImGui::SetNextWindowBgAlpha(alpha); }
static void SetWindowPos(float posX, float posY)                                                    { ImGui::SetWindowPos({ posX, posY }); }
static void SetWindowPos(float posX, float posY, int cond)                                          { ImGui::SetWindowPos({ posX, posY }, static_cast<ImGuiCond>(cond)); }
static void SetWindowSize(float sizeX, float sizeY)                                                 { ImGui::SetWindowSize({ sizeX, sizeY }); }
static void SetWindowSize(float sizeX, float sizeY, int cond)                                       { ImGui::SetWindowSize({ sizeX, sizeY }, static_cast<ImGuiCond>(cond)); }
static void SetWindowCollapsed(bool collapsed)                                                      { ImGui::SetWindowCollapsed(collapsed); }
static void SetWindowCollapsed(bool collapsed, int cond)                                            { ImGui::SetWindowCollapsed(collapsed, static_cast<ImGuiCond>(cond)); }
static void SetWindowFocus()                                                                        { ImGui::SetWindowFocus(); }
static void SetWindowFontScale(float scale)                                                         { ImGui::SetWindowFontScale(scale); }
static void SetWindowPos(const std::string& name, float posX, float posY)                           { ImGui::SetWindowPos(name.c_str(), { posX, posY }); }
static void SetWindowPos(const std::string& name, float posX, float posY, int cond)                 { ImGui::SetWindowPos(name.c_str(), { posX, posY }, static_cast<ImGuiCond>(cond)); }
static void SetWindowSize(const std::string& name, float sizeX, float sizeY)                        { ImGui::SetWindowSize(name.c_str(), { sizeX, sizeY }); }
static void SetWindowSize(const std::string& name, float sizeX, float sizeY, int cond)              { ImGui::SetWindowSize(name.c_str(), { sizeX, sizeY }, static_cast<ImGuiCond>(cond)); }
static void SetWindowCollapsed(const std::string& name, bool collapsed)                             { ImGui::SetWindowCollapsed(name.c_str(), collapsed); }
static void SetWindowCollapsed(const std::string& name, bool collapsed, int cond)                   { ImGui::SetWindowCollapsed(name.c_str(), collapsed, static_cast<ImGuiCond>(cond)); }
static void SetWindowFocus(const std::string& name)                                                 { ImGui::SetWindowFocus(name.c_str()); }

// Content Region
static std::tuple<float, float> GetContentRegionMax()                                               { const auto vec2{ ImGui::GetContentRegionMax() };  return std::make_tuple(vec2.x, vec2.y); }
static std::tuple<float, float> GetContentRegionAvail()                                             { const auto vec2{ ImGui::GetContentRegionAvail() };  return std::make_tuple(vec2.x, vec2.y); }
static std::tuple<float, float> GetWindowContentRegionMin()                                         { const auto vec2{ ImGui::GetWindowContentRegionMin() };  return std::make_tuple(vec2.x, vec2.y); }
static std::tuple<float, float> GetWindowContentRegionMax()                                         { const auto vec2{ ImGui::GetWindowContentRegionMax() };  return std::make_tuple(vec2.x, vec2.y); }
static float GetWindowContentRegionWidth()                                                          { return ImGui::GetWindowContentRegionWidth(); }

// Windows Scrolling
static float GetScrollX()                                                                           { return ImGui::GetScrollX(); }
static float GetScrollY()                                                                           { return ImGui::GetScrollY(); }
static float GetScrollMaxX()                                                                        { return ImGui::GetScrollMaxX(); }
static float GetScrollMaxY()                                                                        { return ImGui::GetScrollMaxY(); }
static void SetScrollX(float scrollX)                                                               { ImGui::SetScrollX(scrollX); }
static void SetScrollY(float scrollY)                                                               { ImGui::SetScrollY(scrollY); }
static void SetScrollHereX()                                                                        { ImGui::SetScrollHereX(); }
static void SetScrollHereX(float centerXRatio)                                                      { ImGui::SetScrollHereX(centerXRatio); }
static void SetScrollHereY()                                                                        { ImGui::SetScrollHereY(); }
static void SetScrollHereY(float centerYRatio)                                                      { ImGui::SetScrollHereY(centerYRatio); }    
static void SetScrollFromPosX(float localX)                                                         { ImGui::SetScrollFromPosX(localX); }
static void SetScrollFromPosX(float localX, float centerXRatio)                                     { ImGui::SetScrollFromPosX(localX, centerXRatio); }
static void SetScrollFromPosY(float localY)                                                         { ImGui::SetScrollFromPosY(localY); }
static void SetScrollFromPosY(float localY, float centerYRatio)                                     { ImGui::SetScrollFromPosY(localY, centerYRatio); }

// Parameters stacks (shared)
static void PushFont(ImFont* pFont)                                                                 { ImGui::PushFont(pFont); }
static void PopFont()                                                                               { ImGui::PopFont(); }
static void PushStyleColor(int idx, int col)                                                        { ImGui::PushStyleColor(static_cast<ImGuiCol>(idx), ImU32(col)); }
static void PushStyleColor(int idx, float colR, float colG, float colB, float colA)                 { ImGui::PushStyleColor(static_cast<ImGuiCol>(idx), { colR, colG, colB, colA }); }
static void PopStyleColor()                                                                         { ImGui::PopStyleColor(); }
static void PopStyleColor(int count)                                                                { ImGui::PopStyleColor(count); }
static void PushStyleVar(int idx, float val)                                                        { ImGui::PushStyleVar(static_cast<ImGuiStyleVar>(idx), val); }
static void PushStyleVar(int idx, float valX, float valY)                                           { ImGui::PushStyleVar(static_cast<ImGuiStyleVar>(idx), { valX, valY }); }
static void PushStyleVar(int idx, const ImVec2& val)                                                { ImGui::PushStyleVar(static_cast<ImGuiStyleVar>(idx), val); }
static void PopStyleVar()                                                                           { ImGui::PopStyleVar(); }
static void PopStyleVar(int count)                                                                  { ImGui::PopStyleVar(count); }
static std::tuple<float, float, float, float> GetStyleColorVec4(int idx)                            { const auto col{ ImGui::GetStyleColorVec4(static_cast<ImGuiCol>(idx)) };    return std::make_tuple(col.x, col.y, col.z, col.w); }
static ImFont* GetFont()                                                                            { return ImGui::GetFont(); }
static float GetFontSize()                                                                          { return ImGui::GetFontSize(); }
static std::tuple<float, float> GetFontTexUvWhitePixel()                                            { const auto vec2{ ImGui::GetFontTexUvWhitePixel() };    return std::make_tuple(vec2.x, vec2.y); }
static int GetColorU32(int idx, float alphaMul)                                                     { return ImGui::GetColorU32(static_cast<ImGuiCol>(idx), alphaMul); }
static int GetColorU32(float colR, float colG, float colB, float colA)                              { return ImGui::GetColorU32({ colR, colG, colB, colA }); }
static int GetColorU32(int col)                                                                     { return ImGui::GetColorU32(ImU32(col)); }
static int GetColorU32(const ImVec4& imvec4)                                                        { return ImColor(imvec4); }

static int GetColorU32_Int(int colR, int colG, int colB, int colA)                                  { return IM_COL32(colR, colG, colB, colA); }

// Parameters stacks (current window)
static void PushItemWidth(float itemWidth)                                                          { ImGui::PushItemWidth(itemWidth); }
static void PopItemWidth()                                                                          { ImGui::PopItemWidth(); }
static void SetNextItemWidth(float itemWidth)                                                       { ImGui::SetNextItemWidth(itemWidth); }
static float CalcItemWidth()                                                                        { return ImGui::CalcItemWidth(); }
static void PushTextWrapPos()                                                                       { ImGui::PushTextWrapPos(); }
static void PushTextWrapPos(float wrapLocalPosX)                                                    { ImGui::PushTextWrapPos(wrapLocalPosX); }
static void PopTextWrapPos()                                                                        { ImGui::PopTextWrapPos(); }
static void PushAllowKeyboardFocus(bool allowKeyboardFocus)                                         { ImGui::PushAllowKeyboardFocus(allowKeyboardFocus); }
static void PopAllowKeyboardFocus()                                                                 { ImGui::PopAllowKeyboardFocus(); }
static void PushButtonRepeat(bool repeat)                                                           { ImGui::PushButtonRepeat(repeat); }
static void PopButtonRepeat()                                                                       { ImGui::PopButtonRepeat(); }

// Cursor / Layout
static void Separator()                                                                             { ImGui::Separator(); }
static void SameLine()                                                                              { ImGui::SameLine(); }
static void SameLine(float offsetFromStartX)                                                        { ImGui::SameLine(offsetFromStartX); }
static void SameLine(float offsetFromStartX, float spacing)                                         { ImGui::SameLine(offsetFromStartX, spacing); }
static void NewLine()                                                                               { ImGui::NewLine(); }
static void Spacing()                                                                               { ImGui::Spacing(); }
static void Dummy(float sizeX, float sizeY)                                                         { ImGui::Dummy({ sizeX, sizeY }); }
static void Indent()                                                                                { ImGui::Indent(); }
static void Indent(float indentW)                                                                   { ImGui::Indent(indentW); }
static void Unindent()                                                                              { ImGui::Unindent(); }
static void Unindent(float indentW)                                                                 { ImGui::Unindent(indentW); }
static void BeginGroup()                                                                            { ImGui::BeginGroup(); }
static void EndGroup()                                                                              { ImGui::EndGroup(); }
static std::tuple<float, float> GetCursorPos()                                                      { const auto vec2{ ImGui::GetCursorPos() };  return std::make_tuple(vec2.x, vec2.y); }
static float GetCursorPosX()                                                                        { return ImGui::GetCursorPosX(); }
static float GetCursorPosY()                                                                        { return ImGui::GetCursorPosY(); }
static void SetCursorPos(float localX, float localY)                                                { ImGui::SetCursorPos({ localX, localY }); }
static void SetCursorPosX(float localX)                                                             { ImGui::SetCursorPosX(localX); }
static void SetCursorPosY(float localY)                                                             { ImGui::SetCursorPosY(localY); }
static std::tuple<float, float> GetCursorStartPos()                                                 { const auto vec2{ ImGui::GetCursorStartPos() };  return std::make_tuple(vec2.x, vec2.y); }
static std::tuple<float, float> GetCursorScreenPos()                                                { const auto vec2{ ImGui::GetCursorScreenPos() };  return std::make_tuple(vec2.x, vec2.y); }
static void SetCursorScreenPos(float posX, float posY)                                              { ImGui::SetCursorScreenPos({ posX, posY }); }
static void AlignTextToFramePadding()                                                               { ImGui::AlignTextToFramePadding(); }
static float GetTextLineHeight()                                                                    { return ImGui::GetTextLineHeight(); }
static float GetTextLineHeightWithSpacing()                                                         { return ImGui::GetTextLineHeightWithSpacing(); }
static float GetFrameHeight()                                                                       { return ImGui::GetFrameHeight(); }
static float GetFrameHeightWithSpacing()                                                            { return ImGui::GetFrameHeightWithSpacing(); }

// ID stack / scopes
static void PushID(const std::string& stringID)                                                     { ImGui::PushID(stringID.c_str()); }
static void PushID(const std::string& stringIDBegin, const std::string& stringIDEnd)                { ImGui::PushID(stringIDBegin.c_str(), stringIDEnd.c_str()); }
static void PushID(int intID)                                                                       { ImGui::PushID(intID); }
static void PushID(sol::object object)                                                              { ImGui::PushID(object.pointer()); }
static void PopID()                                                                                 { ImGui::PopID(); }
static int GetID(const std::string& stringID)                                                       { return ImGui::GetID(stringID.c_str()); }
static int GetID(const std::string& stringIDBegin, const std::string& stringIDEnd)                  { return ImGui::GetID(stringIDBegin.c_str(), stringIDEnd.c_str()); }
static int GetID(const void*)                                                                       { return 0;  /* TODO: GetID(void*) ==> UNSUPPORTED */ }

#pragma endregion

#pragma region Utilities

// Logging
static void LogToTTY()                                                                              { ImGui::LogToTTY(); }
static void LogToTTY(int auto_open_depth)                                                           { ImGui::LogToTTY(auto_open_depth); }
static void LogToFile()                                                                             { ImGui::LogToFile(); }
static void LogToFile(int auto_open_depth)                                                          { ImGui::LogToFile(auto_open_depth); }
static void LogToFile(int auto_open_depth, const std::string& filename)                             { ImGui::LogToFile(auto_open_depth, filename.c_str()); }
static void LogToClipboard()                                                                        { ImGui::LogToClipboard(); }
static void LogToClipboard(int auto_open_depth)                                                     { ImGui::LogToClipboard(auto_open_depth); }
static void LogFinish()                                                                             { ImGui::LogFinish(); }
static void LogButtons()                                                                            { ImGui::LogButtons(); }
static void LogText(const std::string& fmt)                                                         { ImGui::LogText(fmt.c_str()); }

// Clipping
static void PushClipRect(float min_x, float min_y, float max_x, float max_y, bool intersect_current) { ImGui::PushClipRect({ min_x, min_y }, { max_x, max_y }, intersect_current); }
static void PopClipRect()                                                                           { ImGui::PopClipRect(); }

// Focus, Activation
static void SetItemDefaultFocus()                                                                   { ImGui::SetItemDefaultFocus(); }
static void SetKeyboardFocusHere()                                                                  { ImGui::SetKeyboardFocusHere(); }
static void SetKeyboardFocusHere(int offset)                                                        { ImGui::SetKeyboardFocusHere(offset); }

// Item/Widgets Utilities
static bool IsItemHovered()                                                                         { return ImGui::IsItemHovered(); }
static bool IsItemHovered(int flags)                                                                { return ImGui::IsItemHovered(static_cast<ImGuiHoveredFlags>(flags)); }
static bool IsItemActive()                                                                          { return ImGui::IsItemActive(); }
static bool IsItemFocused()                                                                         { return ImGui::IsItemFocused(); }
static bool IsItemClicked()                                                                         { return ImGui::IsItemClicked(); }
static bool IsItemClicked(int mouse_button)                                                         { return ImGui::IsItemClicked(static_cast<ImGuiMouseButton>(mouse_button)); }
static bool IsItemVisible()                                                                         { return ImGui::IsItemVisible(); }
static bool IsItemEdited()                                                                          { return ImGui::IsItemEdited(); }
static bool IsItemActivated()                                                                       { return ImGui::IsItemActivated(); }
static bool IsItemDeactivated()                                                                     { return ImGui::IsItemDeactivated(); }
static bool IsItemDeactivatedAfterEdit()                                                            { return ImGui::IsItemDeactivatedAfterEdit(); }
static bool IsItemToggledOpen()                                                                     { return ImGui::IsItemToggledOpen(); }
static bool IsAnyItemHovered()                                                                      { return ImGui::IsAnyItemHovered(); }
static bool IsAnyItemActive()                                                                       { return ImGui::IsAnyItemActive(); }
static bool IsAnyItemFocused()                                                                      { return ImGui::IsAnyItemFocused(); }
static std::tuple<float, float> GetItemRectMin()                                                    { const auto vec2{ ImGui::GetItemRectMin() }; return std::make_tuple(vec2.x, vec2.y); }
static std::tuple<float, float> GetItemRectMax()                                                    { const auto vec2{ ImGui::GetItemRectMax() }; return std::make_tuple(vec2.x, vec2.y); }
static std::tuple<float, float> GetItemRectSize()                                                   { const auto vec2{ ImGui::GetItemRectSize() }; return std::make_tuple(vec2.x, vec2.y); }
static void SetItemAllowOverlap()                                                                   { ImGui::SetItemAllowOverlap(); }

// Miscellaneous Utilities
static bool IsRectVisible(float sizeX, float sizeY)                                                 { return ImGui::IsRectVisible({ sizeX, sizeY }); }
static bool IsRectVisible(float minX, float minY, float maxX, float maxY)                           { return ImGui::IsRectVisible({ minX, minY }, { maxX, maxY }); }
static double GetTime()                                                                             { return ImGui::GetTime(); }
static int GetFrameCount()                                                                          { return ImGui::GetFrameCount(); }
/* TODO: GetDrawListSharedData() ==> UNSUPPORTED */
static std::string GetStyleColorName(int idx)                                                       { return std::string(ImGui::GetStyleColorName(static_cast<ImGuiCol>(idx))); }
/* TODO: SetStateStorage(), GetStateStorage(), CalcListClipping() ==> UNSUPPORTED */
static bool BeginChildFrame(unsigned int id, float sizeX, float sizeY)                              { return ImGui::BeginChildFrame(id, { sizeX, sizeY }); }
static bool BeginChildFrame(unsigned int id, float sizeX, float sizeY, int flags)                   { return ImGui::BeginChildFrame(id, { sizeX, sizeY }, static_cast<ImGuiWindowFlags>(flags)); }
static void EndChildFrame()                                                                         { return ImGui::EndChildFrame(); }

// Text Utilities
static std::tuple<float, float> CalcTextSize(const std::string& text)
{
	const auto vec2{ ImGui::CalcTextSize(text.c_str()) };
	return std::make_tuple(vec2.x, vec2.y);
}

static std::tuple<float, float> CalcTextSize(const std::string& text, const std::string& text_end)
{
	const auto vec2{ ImGui::CalcTextSize(text.c_str(), text_end.c_str()) };
	return std::make_tuple(vec2.x, vec2.y);
}

static std::tuple<float, float> CalcTextSize(const std::string& text, const std::string& text_end, bool hide_text_after_double_hash)
{
	const auto vec2{ ImGui::CalcTextSize(text.c_str(), text_end.c_str(), hide_text_after_double_hash) };
	return std::make_tuple(vec2.x, vec2.y);
}

static std::tuple<float, float> CalcTextSize(const std::string& text, const std::string& text_end, bool hide_text_after_double_hash, float wrap_width)
{
	const auto vec2{ ImGui::CalcTextSize(text.c_str(), text_end.c_str(), hide_text_after_double_hash, wrap_width) };
	return std::make_tuple(vec2.x, vec2.y);
}

// Color Utilities
static sol::as_table_t<std::vector<float>> ColorConvertU32ToFloat4(unsigned int in)
{
	const auto vec4 = ImGui::ColorConvertU32ToFloat4(in);
	sol::as_table_t rgba = sol::as_table(std::vector<float>{
		vec4.x, vec4.y, vec4.z, vec4.w
	});

	return rgba;
}
static unsigned int ColorConvertFloat4ToU32(const sol::table& rgba)
{
	const lua_Number
		r{ rgba[1].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
		g{ rgba[2].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
		b{ rgba[3].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) },
		a{ rgba[4].get<std::optional<lua_Number>>().value_or(static_cast<lua_Number>(0)) };

	return ImGui::ColorConvertFloat4ToU32({ float(r), float(g), float(b), float(a) });
}

static std::tuple<float, float, float> ColorConvertRGBtoHSV(float r, float g, float b)
{
	float h{}, s{}, v{};
	ImGui::ColorConvertRGBtoHSV(r, g, b, h, s, v);
	return std::make_tuple(h, s, v);
}

static std::tuple<float, float, float> ColorConvertHSVtoRGB(float h, float s, float v)
{
	float r{}, g{}, b{};
	ImGui::ColorConvertHSVtoRGB(h, s, v, r, g, b);
	return std::make_tuple(r, g, b);
}

// Inputs Utilities: Keyboard
static int GetKeyIndex(int imgui_key)                                                               { return ImGui::GetKeyIndex(static_cast<ImGuiKey>(imgui_key)); }
static bool IsKeyDown(int user_key_index)                                                           { return ImGui::IsKeyDown(user_key_index); }
static bool IsKeyPressed(int user_key_index)                                                        { return ImGui::IsKeyPressed(user_key_index); }
static bool IsKeyPressed(int user_key_index, bool repeat)                                           { return ImGui::IsKeyPressed(user_key_index, repeat); }
static bool IsKeyReleased(int user_key_index)                                                       { return ImGui::IsKeyReleased(user_key_index); }
static int GetKeyPressedAmount(int key_index, float repeat_delay, float rate)                       { return ImGui::GetKeyPressedAmount(key_index, repeat_delay, rate); }
static void CaptureKeyboardFromApp()                                                                { ImGui::CaptureKeyboardFromApp(); }
static void CaptureKeyboardFromApp(bool want_capture_keyboard_value)                                { ImGui::CaptureKeyboardFromApp(want_capture_keyboard_value); }

// Inputs Utilities: Mouse
static bool IsMouseDown(int button)                                                                 { return ImGui::IsMouseDown(static_cast<ImGuiMouseButton>(button)); }
static bool IsMouseClicked(int button)                                                              { return ImGui::IsMouseClicked(static_cast<ImGuiMouseButton>(button)); }
static bool IsMouseClicked(int button, bool repeat)                                                 { return ImGui::IsMouseClicked(static_cast<ImGuiMouseButton>(button), repeat); }
static bool IsMouseReleased(int button)                                                             { return ImGui::IsMouseReleased(static_cast<ImGuiMouseButton>(button)); }
static bool IsMouseDoubleClicked(int button)                                                        { return ImGui::IsMouseDoubleClicked(static_cast<ImGuiMouseButton>(button)); }
static bool IsMouseHoveringRect(float min_x, float min_y, float max_x, float max_y)                 { return ImGui::IsMouseHoveringRect({ min_x, min_y }, { max_x, max_y }); }
static bool IsMouseHoveringRect(float min_x, float min_y, float max_x, float max_y, bool clip)      { return ImGui::IsMouseHoveringRect({ min_x, min_y }, { max_x, max_y }, clip); }
static bool IsMousePosValid()                                                                       { return false; /* TODO: IsMousePosValid() ==> UNSUPPORTED */ }
static bool IsAnyMouseDown()                                                                        { return ImGui::IsAnyMouseDown(); }
static std::tuple<float, float> GetMousePos()                                                       { const auto vec2{ ImGui::GetMousePos() }; return std::make_tuple(vec2.x, vec2.y); }
static std::tuple<float, float> GetMousePosOnOpeningCurrentPopup()                                  { const auto vec2{ ImGui::GetMousePosOnOpeningCurrentPopup() }; return std::make_tuple(vec2.x, vec2.y); }
static bool IsMouseDragging(int button)                                                             { return ImGui::IsMouseDragging(static_cast<ImGuiMouseButton>(button)); }
static bool IsMouseDragging(int button, float lock_threshold)                                       { return ImGui::IsMouseDragging(static_cast<ImGuiMouseButton>(button), lock_threshold); }
static std::tuple<float, float> GetMouseDragDelta()                                                 { const auto vec2{ ImGui::GetMouseDragDelta() }; return std::make_tuple(vec2.x, vec2.y); }
static std::tuple<float, float> GetMouseDragDelta(int button)                                       { const auto vec2{ ImGui::GetMouseDragDelta(static_cast<ImGuiMouseButton>(button)) }; return std::make_tuple(vec2.x, vec2.y); }
static std::tuple<float, float> GetMouseDragDelta(int button, float lock_threshold)                 { const auto vec2{ ImGui::GetMouseDragDelta(static_cast<ImGuiMouseButton>(button), lock_threshold) }; return std::make_tuple(vec2.x, vec2.y); }
static ImVec2 GetMouseDragDeltaVec()                                                                { return ImGui::GetMouseDragDelta(); }
static ImVec2 GetMouseDragDeltaVec(int button)                                                      { return ImGui::GetMouseDragDelta(static_cast<ImGuiMouseButton>(button)); }
static void ResetMouseDragDelta()                                                                   { ImGui::ResetMouseDragDelta(); }
static void ResetMouseDragDelta(int button)                                                         { ImGui::ResetMouseDragDelta(static_cast<ImGuiMouseButton>(button)); }
static int GetMouseCursor()                                                                         { return ImGui::GetMouseCursor(); }
static void SetMouseCursor(int cursor_type)                                                         { ImGui::SetMouseCursor(static_cast<ImGuiMouseCursor>(cursor_type)); }
static void CaptureMouseFromApp()                                                                   { ImGui::CaptureMouseFromApp(); }
static void CaptureMouseFromApp(bool want_capture_mouse_value)                                      { ImGui::CaptureMouseFromApp(want_capture_mouse_value); }

// Clipboard Utilities
static std::string GetClipboardText()
{
	const char* text = ImGui::GetClipboardText();
	return text ? std::string(text) : std::string();
}
static void SetClipboardText(const std::string& text)                                               { ImGui::SetClipboardText(text.c_str()); }


#pragma endregion

void RegisterBindings_ImGui(sol::state_view state)
{
	sol::table ImGui = state.get_or("ImGui", sol::lua_nil);
	if (ImGui != sol::lua_nil) return;

	ImGui = state.create_named_table("ImGui");
	bindings::RegisterBindings_ImGuiEnums(state);
	bindings::RegisterBindings_ImGuiUserTypes(state);

	ImGui.set_function("Register", lua_addimgui);
	ImGui.set_function("Unregister", lua_removeimgui);

	#pragma region Core Functions

	// Main

	// IO
	ImGui.set_function("GetIO", ImGui::GetIO);
	ImGui.set_function("GetStyle", GetStyle);

	// Windows
	ImGui.set_function("Begin", sol::overload(
		sol::resolve<bool(const std::string&)>(Begin),
		sol::resolve<std::tuple<bool, bool>(const std::string&, bool)>(Begin),
		sol::resolve<std::tuple<bool, bool>(const std::string&, bool, int)>(Begin)
	));
	ImGui.set_function("End", End);

	// Child Windows
	ImGui.set_function("BeginChild", sol::overload(
		sol::resolve<bool(const std::string&)>(BeginChild),
		sol::resolve<bool(const std::string&, float)>(BeginChild),
		sol::resolve<bool(const std::string&, float, float)>(BeginChild),
		sol::resolve<bool(const std::string&, float, float, bool)>(BeginChild),
		sol::resolve<bool(const std::string&, float, float, bool, int)>(BeginChild)
	));
	ImGui.set_function("EndChild", EndChild);

	// Window Utilities
	ImGui.set_function("IsWindowAppearing", IsWindowAppearing);
	ImGui.set_function("IsWindowCollapsed", IsWindowCollapsed);
	ImGui.set_function("IsWindowFocused", sol::overload(
		sol::resolve<bool()>(IsWindowFocused),
		sol::resolve<bool(int)>(IsWindowFocused)
	));
	ImGui.set_function("IsWindowHovered", sol::overload(
		sol::resolve<bool()>(IsWindowHovered),
		sol::resolve<bool(int)>(IsWindowHovered)
	));
	ImGui.set_function("GetWindowDrawList", ImGui::GetWindowDrawList);
	ImGui.set_function("GetWindowDpiScale", GetWindowDpiScale);
	ImGui.set_function("GetWindowPos", GetWindowPos);
	ImGui.set_function("GetWindowPosVec", ImGui::GetWindowPos);
	ImGui.set_function("GetWindowSize", GetWindowSize);
	ImGui.set_function("GetWindowSizeVec", ImGui::GetWindowSize);
	ImGui.set_function("GetWindowWidth", GetWindowWidth);
	ImGui.set_function("GetWindowHeight", GetWindowHeight);

	// Prefer  SetNext...
	ImGui.set_function("SetNextWindowPos", sol::overload(
		sol::resolve<void(float, float)>(SetNextWindowPos),
		sol::resolve<void(float, float, int)>(SetNextWindowPos),
		sol::resolve<void(float, float, int, float, float)>(SetNextWindowPos)
	));
	ImGui.set_function("SetNextWindowSize", sol::overload(
		sol::resolve<void(float, float)>(SetNextWindowSize),
		sol::resolve<void(float, float, int)>(SetNextWindowSize)
	));
	ImGui.set_function("SetNextWindowSizeConstraints", SetNextWindowSizeConstraints);
	ImGui.set_function("SetNextWindowContentSize", SetNextWindowContentSize);
	ImGui.set_function("SetNextWindowCollapsed", sol::overload(
		sol::resolve<void(bool)>(SetNextWindowCollapsed),
		sol::resolve<void(bool, int)>(SetNextWindowCollapsed)
	));
	ImGui.set_function("SetNextWindowFocus", SetNextWindowFocus);
	ImGui.set_function("SetNextWindowBgAlpha", SetNextWindowBgAlpha);
	ImGui.set_function("SetWindowPos", sol::overload(
		sol::resolve<void(float, float)>(SetWindowPos),
		sol::resolve<void(float, float, int)>(SetWindowPos),
		sol::resolve<void(const std::string&, float, float)>(SetWindowPos),
		sol::resolve<void(const std::string&, float, float, int)>(SetWindowPos)
	));
	ImGui.set_function("SetWindowSize", sol::overload(
		sol::resolve<void(float, float)>(SetWindowSize),
		sol::resolve<void(float, float, int)>(SetWindowSize),
		sol::resolve<void(const std::string&, float, float)>(SetWindowSize),
		sol::resolve<void(const std::string&, float, float, int)>(SetWindowSize)
	));
	ImGui.set_function("SetWindowCollapsed", sol::overload(
		sol::resolve<void(bool)>(SetWindowCollapsed),
		sol::resolve<void(bool, int)>(SetWindowCollapsed),
		sol::resolve<void(const std::string&, bool)>(SetWindowCollapsed),
		sol::resolve<void(const std::string&, bool, int)>(SetWindowCollapsed)
	));
	ImGui.set_function("SetWindowFocus", sol::overload(
		sol::resolve<void()>(SetWindowFocus),
		sol::resolve<void(const std::string&)>(SetWindowFocus)
	));
	ImGui.set_function("SetWindowFontScale", SetWindowFontScale);

	// Content Region
	ImGui.set_function("GetContentRegionMax", GetContentRegionMax);
	ImGui.set_function("GetContentRegionAvail", GetContentRegionAvail);
	ImGui.set_function("GetContentRegionAvailVec", ImGui::GetContentRegionAvail);
	ImGui.set_function("GetWindowContentRegionMin", GetWindowContentRegionMin);
	ImGui.set_function("GetWindowContentRegionMax", GetWindowContentRegionMax);
	ImGui.set_function("GetWindowContentRegionWidth", GetWindowContentRegionWidth);

	// Windows Scrolling
	ImGui.set_function("GetScrollX", GetScrollX);
	ImGui.set_function("GetScrollY", GetScrollY);
	ImGui.set_function("GetScrollMaxX", GetScrollMaxX);
	ImGui.set_function("GetScrollMaxY", GetScrollMaxY);
	ImGui.set_function("SetScrollX", SetScrollX);
	ImGui.set_function("SetScrollY", SetScrollY);
	ImGui.set_function("SetScrollHereX", sol::overload(
		sol::resolve<void()>(SetScrollHereX),
		sol::resolve<void(float)>(SetScrollHereX)
	));
	ImGui.set_function("SetScrollHereY", sol::overload(
		sol::resolve<void()>(SetScrollHereY),
		sol::resolve<void(float)>(SetScrollHereY)
	));
	ImGui.set_function("SetScrollFromPosX", sol::overload(
		sol::resolve<void(float)>(SetScrollFromPosX),
		sol::resolve<void(float, float)>(SetScrollFromPosX)
	));
	ImGui.set_function("SetScrollFromPosY", sol::overload(
		sol::resolve<void(float)>(SetScrollFromPosY),
		sol::resolve<void(float, float)>(SetScrollFromPosY)
	));

	// Parameters stacks (shared)
	ImGui.set_function("PushFont", PushFont);
	ImGui.set_function("PopFont", PopFont);
	ImGui.set_function("PushStyleColor", sol::overload(
		sol::resolve<void(int, int)>(PushStyleColor),
		sol::resolve<void(int, float, float, float, float)>(PushStyleColor)
	));
	ImGui.set_function("PopStyleColor", sol::overload(
		sol::resolve<void()>(PopStyleColor),
		sol::resolve<void(int)>(PopStyleColor)
	));
	ImGui.set_function("PushStyleVar", sol::overload(
		sol::resolve<void(int, float)>(PushStyleVar),
		sol::resolve<void(int, float, float)>(PushStyleVar),
		sol::resolve<void(int, const ImVec2&)>(PushStyleVar)
	));
	ImGui.set_function("PopStyleVar", sol::overload(
		sol::resolve<void()>(PopStyleVar),
		sol::resolve<void(int)>(PopStyleVar)
	));
	ImGui.set_function("GetStyleColorVec4", GetStyleColorVec4);
	ImGui.set_function("GetFont", GetFont);
	ImGui.set_function("GetFontSize", GetFontSize);
	ImGui.set_function("GetFontTexUvWhitePixel", GetFontTexUvWhitePixel);
	ImGui.set_function("GetColorU32", sol::overload(
		sol::resolve<int(int, float)>(GetColorU32),
		sol::resolve<int(float, float, float, float)>(GetColorU32),
		sol::resolve<int(int)>(GetColorU32),
		sol::resolve<int(const ImVec4&)>(GetColorU32))
	);

	// global "macro"
	state.set_function("IM_COL32", GetColorU32_Int);

	// Parameters stacks (current window)
	ImGui.set_function("PushItemWidth", PushItemWidth);
	ImGui.set_function("PopItemWidth", PopItemWidth);
	ImGui.set_function("SetNextItemWidth", SetNextItemWidth);
	ImGui.set_function("CalcItemWidth", CalcItemWidth);
	ImGui.set_function("PushTextWrapPos", sol::overload(
		sol::resolve<void()>(PushTextWrapPos),
		sol::resolve<void(float)>(PushTextWrapPos)
	));
	ImGui.set_function("PopTextWrapPos", PopTextWrapPos);
	ImGui.set_function("PushAllowKeyboardFocus", PushAllowKeyboardFocus);
	ImGui.set_function("PopAllowKeyboardFocus", PopAllowKeyboardFocus);
	ImGui.set_function("PushButtonRepeat", PushButtonRepeat);
	ImGui.set_function("PopButtonRepeat", PopButtonRepeat);

	// Cursor / Layout
	ImGui.set_function("Separator", Separator);
	ImGui.set_function("SameLine", sol::overload(
		sol::resolve<void()>(SameLine),
		sol::resolve<void(float)>(SameLine),
		sol::resolve<void(float, float)>(SameLine)
	));
	ImGui.set_function("NewLine", NewLine);
	ImGui.set_function("Spacing", Spacing);
	ImGui.set_function("Dummy", Dummy);
	ImGui.set_function("Indent", sol::overload(
		sol::resolve<void()>(Indent),
		sol::resolve<void(float)>(Indent)
	));
	ImGui.set_function("Unindent", sol::overload(
		sol::resolve<void()>(Unindent),
		sol::resolve<void(float)>(Unindent)
	));
	ImGui.set_function("BeginGroup", BeginGroup);
	ImGui.set_function("EndGroup", EndGroup);
	ImGui.set_function("GetCursorPos", GetCursorPos);
	ImGui.set_function("GetCursorPosX", GetCursorPosX);
	ImGui.set_function("GetCursorPosY", GetCursorPosY);
	ImGui.set_function("SetCursorPos", SetCursorPos);
	ImGui.set_function("SetCursorPosX", SetCursorPosX);
	ImGui.set_function("SetCursorPosY", SetCursorPosY);
	ImGui.set_function("GetCursorStartPos", GetCursorStartPos);
	ImGui.set_function("GetCursorScreenPos", GetCursorScreenPos);
	ImGui.set_function("GetCursorScreenPosVec", &ImGui::GetCursorScreenPos);
	ImGui.set_function("SetCursorScreenPos", SetCursorScreenPos);
	ImGui.set_function("AlignTextToFramePadding", AlignTextToFramePadding);
	ImGui.set_function("GetTextLineHeight", GetTextLineHeight);
	ImGui.set_function("GetTextLineHeightWithSpacing", GetTextLineHeightWithSpacing);
	ImGui.set_function("GetFrameHeight", GetFrameHeight);
	ImGui.set_function("GetFrameHeightWithSpacing", GetFrameHeightWithSpacing);

	// ID stack / scopes
	ImGui.set_function("PushID", sol::overload(
		sol::resolve<void(const std::string&)>(PushID),
		sol::resolve<void(const std::string&, const std::string&)>(PushID),
		sol::resolve<void(int)>(PushID),
		sol::resolve<void(sol::object)>(PushID)
	));
	ImGui.set_function("PopID", PopID);
	ImGui.set_function("GetID", sol::overload(
		sol::resolve<int(const std::string&)>(GetID),
		sol::resolve<int(const std::string&, const std::string&)>(GetID)
	));
	#pragma endregion

	#pragma region Utilities

	// Logging / Capture
	ImGui.set_function("LogToTTY", sol::overload(
		sol::resolve<void()>(LogToTTY),
		sol::resolve<void(int)>(LogToTTY)
	));
	ImGui.set_function("LogToFile", sol::overload(
		sol::resolve<void(int)>(LogToFile),
		sol::resolve<void(int, const std::string&)>(LogToFile)
	));
	ImGui.set_function("LogToClipboard", sol::overload(
		sol::resolve<void()>(LogToClipboard),
		sol::resolve<void(int)>(LogToClipboard)
	));
	ImGui.set_function("LogFinish", LogFinish);
	ImGui.set_function("LogButtons", LogButtons);
	ImGui.set_function("LogText", LogText);

	// Clipping
	ImGui.set_function("PushClipRect", PushClipRect);
	ImGui.set_function("PopClipRect", PopClipRect);


	// Focus, Activation
	ImGui.set_function("SetItemDefaultFocus", SetItemDefaultFocus);
	ImGui.set_function("SetKeyboardFocusHere", sol::overload(
		sol::resolve<void()>(SetKeyboardFocusHere),
		sol::resolve<void(int)>(SetKeyboardFocusHere)
	));

	// Item/Widgets Utilities
	ImGui.set_function("IsItemHovered", sol::overload(
		sol::resolve<bool()>(IsItemHovered),
		sol::resolve<bool(int)>(IsItemHovered)
	));
	ImGui.set_function("IsItemActive", IsItemActive);
	ImGui.set_function("IsItemFocused", IsItemFocused);
	ImGui.set_function("IsItemClicked", sol::overload(
		sol::resolve<bool()>(IsItemClicked),
		sol::resolve<bool(int)>(IsItemClicked)
	));
	ImGui.set_function("IsItemVisible", IsItemVisible);
	ImGui.set_function("IsItemEdited", IsItemEdited);
	ImGui.set_function("IsItemActivated", IsItemActivated);
	ImGui.set_function("IsItemDeactivated", IsItemDeactivated);
	ImGui.set_function("IsItemDeactivatedAfterEdit", IsItemDeactivatedAfterEdit);
	ImGui.set_function("IsItemToggledOpen", IsItemToggledOpen);
	ImGui.set_function("IsAnyItemHovered", IsAnyItemHovered);
	ImGui.set_function("IsAnyItemActive", IsAnyItemActive);
	ImGui.set_function("IsAnyItemFocused", IsAnyItemFocused);
	ImGui.set_function("GetItemRectMin", GetItemRectMin);
	ImGui.set_function("GetItemRectMax", GetItemRectMax);
	ImGui.set_function("GetItemRectSize", GetItemRectSize);
	ImGui.set_function("SetItemAllowOverlap", SetItemAllowOverlap);

	// Miscellaneous Utilities
	ImGui.set_function("IsRectVisible", sol::overload(
		sol::resolve<bool(float, float)>(IsRectVisible),
		sol::resolve<bool(float, float, float, float)>(IsRectVisible)
	));
	ImGui.set_function("GetTime", GetTime);
	ImGui.set_function("GetFrameCount", GetFrameCount);
	ImGui.set_function("GetBackgroundDrawList", sol::resolve<ImDrawList*()>(ImGui::GetBackgroundDrawList));
	ImGui.set_function("GetForegroundDrawList", sol::resolve<ImDrawList*()>(ImGui::GetForegroundDrawList));
	ImGui.set_function("GetDrawListSharedData", ImGui::GetDrawListSharedData);
	ImGui.set_function("GetStyleColorName", GetStyleColorName);
	ImGui.set_function("BeginChildFrame", sol::overload(
		sol::resolve<bool(unsigned int, float, float)>(BeginChildFrame),
		sol::resolve<bool(unsigned int, float, float, int)>(BeginChildFrame)
	));
	ImGui.set_function("EndChildFrame", EndChildFrame);

	// Text Utilities
	ImGui.set_function("CalcTextSize", sol::overload(
		sol::resolve<std::tuple<float, float>(const std::string&)>(CalcTextSize),
		sol::resolve<std::tuple<float, float>(const std::string&, const std::string&)>(CalcTextSize),
		sol::resolve<std::tuple<float, float>(const std::string&, const std::string&, bool)>(CalcTextSize),
		sol::resolve<std::tuple<float, float>(const std::string&, const std::string&, bool, float)>(CalcTextSize)
	));

	// Color Utilities
	ImGui.set_function("ColorConvertU32ToFloat4", ColorConvertU32ToFloat4);
	ImGui.set_function("ColorConvertFloat4ToU32", ColorConvertFloat4ToU32);
	ImGui.set_function("ColorConvertRGBtoHSV", ColorConvertRGBtoHSV);
	ImGui.set_function("ColorConvertHSVtoRGB", ColorConvertHSVtoRGB);

	// Inputs Utilities: Keyboard
	ImGui.set_function("GetKeyIndex", GetKeyIndex);
	ImGui.set_function("IsKeyDown", IsKeyDown);
	ImGui.set_function("IsKeyPressed", sol::overload(
		sol::resolve<bool(int)>(IsKeyPressed),
		sol::resolve<bool(int, bool)>(IsKeyPressed)
	));
	ImGui.set_function("IsKeyReleased", IsKeyReleased);
	ImGui.set_function("CaptureKeyboardFromApp", sol::overload(
		sol::resolve<void()>(CaptureKeyboardFromApp),
		sol::resolve<void(bool)>(CaptureKeyboardFromApp)
	));

	// Inputs Utilities: Mouse
	ImGui.set_function("IsMouseDown", IsMouseDown);
	ImGui.set_function("IsMouseClicked", sol::overload(
		sol::resolve<bool(int)>(IsMouseClicked),
		sol::resolve<bool(int, bool)>(IsMouseClicked)
	));
	ImGui.set_function("IsMouseReleased", IsMouseReleased);
	ImGui.set_function("IsMouseDoubleClicked", IsMouseDoubleClicked);
	ImGui.set_function("IsMouseHoveringRect", sol::overload(
		sol::resolve<bool(float, float, float, float)>(IsMouseHoveringRect),
		sol::resolve<bool(float, float, float, float, bool)>(IsMouseHoveringRect)
	));
	ImGui.set_function("IsAnyMouseDown", IsAnyMouseDown);
	ImGui.set_function("GetMousePos", GetMousePos);
	ImGui.set_function("GetMousePosVec", ImGui::GetMousePos);
	ImGui.set_function("GetMousePosOnOpeningCurrentPopup", GetMousePosOnOpeningCurrentPopup);
	ImGui.set_function("IsMouseDragging", sol::overload(
		sol::resolve<bool(int)>(IsMouseDragging),
		sol::resolve<bool(int, float)>(IsMouseDragging)
	));
	ImGui.set_function("GetMouseDragDelta", sol::overload(
		sol::resolve<std::tuple<float, float>()>(GetMouseDragDelta),
		sol::resolve<std::tuple<float, float>(int)>(GetMouseDragDelta),
		sol::resolve<std::tuple<float, float>(int, float)>(GetMouseDragDelta)
	));
	ImGui.set_function("GetMouseDragDeltaVec", sol::overload(
		sol::resolve<ImVec2()>(GetMouseDragDeltaVec),
		sol::resolve<ImVec2(int)>(GetMouseDragDeltaVec),
		sol::resolve<ImVec2(int, float)>(ImGui::GetMouseDragDelta)
	));
	ImGui.set_function("ResetMouseDragDelta", sol::overload(
		sol::resolve<void()>(ResetMouseDragDelta),
		sol::resolve<void(int)>(ResetMouseDragDelta)
	));
	ImGui.set_function("GetMouseCursor", GetMouseCursor);
	ImGui.set_function("SetMouseCursor", SetMouseCursor);
	ImGui.set_function("CaptureMouseFromApp", sol::overload(
		sol::resolve<void()>(CaptureMouseFromApp),
		sol::resolve<void(bool)>(CaptureMouseFromApp)
	));

	// Clipboard Utilities
	ImGui.set_function("GetClipboardText", GetClipboardText);
	ImGui.set_function("SetClipboardText", SetClipboardText);
	#pragma endregion

	bindings::RegisterBindings_ImGuiWidgets(ImGui);
	bindings::RegisterBindings_ImGuiCustom(ImGui);
}

} // namespace mq::lua::bindings
