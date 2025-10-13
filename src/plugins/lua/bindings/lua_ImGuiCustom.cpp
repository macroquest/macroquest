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

#include "mq/imgui/ConsoleWidget.h"
#include "mq/imgui/ImGuiUtils.h"
#include "mq/imgui/Widgets.h"
#include "mq/Plugin.h"

#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
#include "imgui/misc/cpp/imgui_stdlib.h"
#include "sol/sol.hpp"

#include <string>

namespace mq::lua::bindings {

//============================================================================

void lua_addimgui(std::string_view name, sol::function function, sol::this_state s);
void lua_removeimgui(std::string_view name, sol::this_state s);

void RegisterBindings_ImGuiCustom(sol::table& ImGui)
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

	using mq::imgui::ConsoleWidget;

	// Widgets: Console Widget
	ImGui.new_usertype<ConsoleWidget>(
		"ConsoleWidget"              , sol::factories(&ConsoleWidget::Create),
		"Render", sol::overload(
			                         [](ConsoleWidget* pThis) { pThis->Render(); },
			                         [](ConsoleWidget* pThis, const ImVec2& displaySize) { pThis->Render(displaySize); }
		),
		"Clear"                      , &ConsoleWidget::Clear,
		"IsCursorAtEnd"              , &ConsoleWidget::IsCursorAtEnd,
		"ScrollToBottom"             , &ConsoleWidget::ScrollToBottom,

		"autoScroll"                 , sol::property(&ConsoleWidget::GetAutoScroll, &ConsoleWidget::SetAutoScroll),
		"maxBufferLines"             , sol::property(&ConsoleWidget::GetMaxBufferLines, &ConsoleWidget::SetMaxBufferLines),
		"opacity"                    , sol::property(&ConsoleWidget::GetOpacity, &ConsoleWidget::SetOpacity),

		"AppendText",                sol::overload(
			[](ConsoleWidget* pThis, std::string_view text) { pThis->AppendText(text, ConsoleWidget::DEFAULT_COLOR, true); },
			[](ConsoleWidget* pThis, std::string_view format, sol::variadic_args va, sol::this_state s) {
				sol::function string_format = sol::state_view(s)["string"]["format"];
				std::string text = string_format(format, va);

				pThis->AppendText(text, ConsoleWidget::DEFAULT_COLOR, true);
			},
			[](ConsoleWidget* pThis, int col, std::string_view text) { pThis->AppendText(text, MQColor(MQColor::format_abgr, col), true); },
			[](ConsoleWidget* pThis, int col, std::string_view format, sol::variadic_args va, sol::this_state s) {
				sol::function string_format = sol::state_view(s)["string"]["format"];
				std::string text = string_format(format, va);

				pThis->AppendText(text, MQColor(MQColor::format_abgr, col), true);
			},
			[](ConsoleWidget* pThis, const ImVec4& col, std::string_view text) { pThis->AppendText(text, MQColor(col), true); },
			[](ConsoleWidget* pThis, const ImVec4& col, std::string_view format, sol::variadic_args va, sol::this_state s) {
				sol::function string_format = sol::state_view(s)["string"]["format"];
				std::string text = string_format(format, va);

				pThis->AppendText(text, MQColor(col), true);
			}
		),
		"AppendTextUnformatted", sol::overload(
			[](ConsoleWidget* pThis, std::string_view text) { pThis->AppendText(text, ConsoleWidget::DEFAULT_COLOR, false); },
			[](ConsoleWidget* pThis, int col, std::string_view text) { pThis->AppendText(text, MQColor(MQColor::format_abgr, col), false); },
			[](ConsoleWidget* pThis, const ImVec4& col, std::string_view text) { pThis->AppendText(text, MQColor(col), false); }
		)
	);
}

} // namespace mq::lua::bindings
