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

#include "main/ImGuiZepEditor.h"
#include "mq/imgui/ConsoleWidget.h"
#include "mq/imgui/ImGuiUtils.h"
#include "mq/imgui/Widgets.h"
#include "mq/Plugin.h"

#include <imgui/imgui.h>
#include <sol/sol.hpp>

#include <string>

#pragma comment(lib, "zep.lib")

namespace mq::lua::bindings {

//============================================================================

void lua_addimgui(std::string_view name, sol::function function, sol::this_state s);
void lua_removeimgui(std::string_view name, sol::this_state s);

void RegisterBindings_ImGuiCustom(sol::table& ImGui, sol::state_view lua)
{
	// Variables
	ImGui.set("ConsoleFont", mq::imgui::ConsoleFont);

	// Core: Register/Unregister
	ImGui.set_function("Register", lua_addimgui);
	ImGui.set_function("Unregister", lua_removeimgui);

	ImGui.set_function("DrawTextureAnimation", sol::overload(
		[](CTextureAnimation* anim, const ImVec2& size, std::optional<int> tintColor, std::optional<int> borderColor) {
			return mq::imgui::DrawTextureAnimation(anim, size,
			MQColor(MQColor::format_abgr, tintColor.value_or(mq::imgui::DefaultTintColor.ToImU32())),
			MQColor(MQColor::format_abgr, borderColor.value_or(mq::imgui::NoBorderColor.ToImU32())));
		},
		[](CTextureAnimation* anim, const ImVec2& size, bool drawBorder) { return mq::imgui::DrawTextureAnimation(anim, size, drawBorder); },
		[](CTextureAnimation* anim, int x, int y, std::optional<bool> drawBorder) { return mq::imgui::DrawTextureAnimation(anim, CXSize(x, y), drawBorder.value_or(false)); },
		[](CTextureAnimation* anim) { return mq::imgui::DrawTextureAnimation(anim); }
	));

	// Widgets: Utility
	ImGui.set_function("HelpMarker", [](const char* text, std::optional<float> width, std::optional<ImFont*> font) { mq::imgui::HelpMarker(text, width.value_or(450), font.value_or(nullptr)); });

	// Widgets: Console Widget
	ImGui.new_usertype<mq::imgui::ConsoleWidget>(
		"ConsoleWidget"              , sol::factories(&mq::imgui::ConsoleWidget::Create),
		"Render", sol::overload(
			                         [](mq::imgui::ConsoleWidget* pThis) { pThis->Render(); },
			                         [](mq::imgui::ConsoleWidget* pThis, ImVec2 displaySize) { pThis->Render(displaySize); }
		),
		"Clear"                      , &mq::imgui::ConsoleWidget::Clear,
		"IsCursorAtEnd"              , &mq::imgui::ConsoleWidget::IsCursorAtEnd,
		"ScrollToBottom"             , &mq::imgui::ConsoleWidget::ScrollToBottom,
		"autoScroll"                 , sol::property(&mq::imgui::ConsoleWidget::GetAutoScroll, &mq::imgui::ConsoleWidget::SetAutoScroll),
		"maxBufferLines"             , sol::property(&mq::imgui::ConsoleWidget::GetMaxBufferLines, &mq::imgui::ConsoleWidget::SetMaxBufferLines),
		"opacity"                    , sol::property(&mq::imgui::ConsoleWidget::GetOpacity, &mq::imgui::ConsoleWidget::SetOpacity),

		"AppendText",                sol::overload(
			[](mq::imgui::ConsoleWidget* pThis, std::string_view text) { pThis->AppendText(text, mq::imgui::ConsoleWidget::DEFAULT_COLOR, true); },
			[](mq::imgui::ConsoleWidget* pThis, std::string_view format, sol::variadic_args va, sol::this_state s) {
				sol::function string_format = sol::state_view(s)["string"]["format"];
				std::string text = string_format(format, va);

				pThis->AppendText(text, mq::imgui::ConsoleWidget::DEFAULT_COLOR, true);
			},
			[](mq::imgui::ConsoleWidget* pThis, int col, std::string_view text) { pThis->AppendText(text, MQColor(MQColor::format_abgr, col), true); },
			[](mq::imgui::ConsoleWidget* pThis, int col, std::string_view format, sol::variadic_args va, sol::this_state s) {
				sol::function string_format = sol::state_view(s)["string"]["format"];
				std::string text = string_format(format, va);

				pThis->AppendText(text, MQColor(MQColor::format_abgr, col), true);
			},
			[](mq::imgui::ConsoleWidget* pThis, const ImVec4& col, std::string_view text) { pThis->AppendText(text, MQColor(col), true); },
			[](mq::imgui::ConsoleWidget* pThis, const ImVec4& col, std::string_view format, sol::variadic_args va, sol::this_state s) {
				sol::function string_format = sol::state_view(s)["string"]["format"];
				std::string text = string_format(format, va);

				pThis->AppendText(text, MQColor(col), true);
			}
		),
		"AppendTextUnformatted", sol::overload(
			[](mq::imgui::ConsoleWidget* pThis, std::string_view text) { pThis->AppendText(text, mq::imgui::ConsoleWidget::DEFAULT_COLOR, false); },
			[](mq::imgui::ConsoleWidget* pThis, int col, std::string_view text) { pThis->AppendText(text, MQColor(MQColor::format_abgr, col), false); },
			[](mq::imgui::ConsoleWidget* pThis, const ImVec4& col, std::string_view text) { pThis->AppendText(text, MQColor(col), false); }
		)
	);

	// Widgets: ZepInputBox
	ImGui.new_usertype<mq::imgui::ImGuiZepEditor>(
		"TextEditor", sol::factories(&mq::imgui::ImGuiZepEditor::Create),
		"Render", sol::overload(
			[](mq::imgui::ImGuiZepEditor* pThis) { pThis->Render(); },
			[](mq::imgui::ImGuiZepEditor* pThis, ImVec2 displaySize) { pThis->Render(displaySize); }
		),
		"Clear", &mq::imgui::ImGuiZepEditor::Clear,
		"SetSyntax", [](mq::imgui::ImGuiZepEditor* pThis, const char* syntaxName) { pThis->SetSyntaxProvider(syntaxName); },
		"text", sol::property(
			[](mq::imgui::ImGuiZepEditor* pThis) -> std::string { size_t bufferSize = pThis->GetTextLength(); std::string text; text.reserve(bufferSize); pThis->GetText(text); return text; }/* read only */),
		"LoadContents", [](mq::imgui::ImGuiZepEditor* pThis, std::string_view text) { pThis->SetText(text); },
		"windowFlags", sol::property(&mq::imgui::ImGuiZepEditor::GetWindowFlags, &mq::imgui::ImGuiZepEditor::SetWindowFlags)
	);

	// ZepEditor Flags
	lua.new_enum("TextEditorWindowFlags",
		"None"						, Zep::WindowFlags::None,
		"ShowWhiteSpace"			, Zep::WindowFlags::ShowWhiteSpace,
		"ShowCR"					, Zep::WindowFlags::ShowCR,
		"ShowLineNumbers"			, Zep::WindowFlags::ShowLineNumbers,
		"ShowIndicators"			, Zep::WindowFlags::ShowIndicators,
		"HideScrollBar"				, Zep::WindowFlags::HideScrollBar,
		"Modal"						, Zep::WindowFlags::Modal,
		"WrapText"					, Zep::WindowFlags::WrapText,
		"HideSplitMark"				, Zep::WindowFlags::HideSplitMark,
		"GridStyle"					, Zep::WindowFlags::GridStyle,
		"ShowLineBackground"		, Zep::WindowFlags::ShowLineBackground,
		"ShowWrappedLineNumbers"	, Zep::WindowFlags::ShowWrappedLineNumbers,
		"ShowAirLine"				, Zep::WindowFlags::ShowAirLine,
		"HideTrailingNewline"		, Zep::WindowFlags::HideTrailingNewline
	);
}
} // namespace mq::lua::bindings
