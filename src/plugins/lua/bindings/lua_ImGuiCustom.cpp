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

#include "pch.h"

#include <mq/imgui/ConsoleWidget.h>
#include <mq/imgui/ImGuiUtils.h>
#include <mq/imgui/Widgets.h>
#include <mq/Plugin.h>

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include <imgui/misc/cpp/imgui_stdlib.h>
#include <sol/sol.hpp>

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
		[](CTextureAnimation* anim, const ImVec2& size, std::optional<bool> drawBorder) { return mq::imgui::DrawTextureAnimation(anim, size, drawBorder.value_or(false)); },
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

		"AppendText",                sol::overload(
			[](mq::imgui::ConsoleWidget* pThis, std::string_view text) { pThis->AppendText(text, mq::imgui::ConsoleWidget::DEFAULT_COLOR, true); },
			[](mq::imgui::ConsoleWidget* pThis, std::string_view format, sol::variadic_args va, sol::this_state s) {
				sol::function string_format = sol::state_view(s)["string"]["format"];
				std::string text = string_format(format, va);

				pThis->AppendText(text, mq::imgui::ConsoleWidget::DEFAULT_COLOR, true);
			},
			[](mq::imgui::ConsoleWidget* pThis, int col, std::string_view text) { pThis->AppendText(text, MQColor(MQColor::format_bgra, col), true); },
			[](mq::imgui::ConsoleWidget* pThis, int col, std::string_view format, sol::variadic_args va, sol::this_state s) {
				sol::function string_format = sol::state_view(s)["string"]["format"];
				std::string text = string_format(format, va);

				pThis->AppendText(text, MQColor(MQColor::format_bgra, col), true);
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
			[](mq::imgui::ConsoleWidget* pThis, int col, std::string_view text) { pThis->AppendText(text, MQColor(MQColor::format_bgra, col), false); },
			[](mq::imgui::ConsoleWidget* pThis, const ImVec4& col, std::string_view text) { pThis->AppendText(text, MQColor(col), false); }
		)
	);
}

} // namespace mq::lua::bindings
