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

static void HelpMarker(const char* text) { mq::imgui::HelpMarker(text); }
static void HelpMarker(const char* text, float width) { mq::imgui::HelpMarker(text, width); }
static void HelpMarker(const char* text, float width, ImFont* font) { mq::imgui::HelpMarker(text, width, font); }

void RegisterBindings_ImGuiCustom(sol::table& ImGui)
{
	ImGui.set_function("DrawTextureAnimation", sol::overload(
		[](const std::unique_ptr<CTextureAnimation>& anim, int x, int y, bool drawBorder) { return mq::imgui::DrawTextureAnimation(anim.get(), CXSize(x, y), drawBorder); },
		[](const std::unique_ptr<CTextureAnimation>& anim, int x, int y) { return mq::imgui::DrawTextureAnimation(anim.get(), CXSize(x, y)); },
		[](const std::unique_ptr<CTextureAnimation>& anim) { return mq::imgui::DrawTextureAnimation(anim.get()); }
	));

	ImGui.set_function("HelpMarker", sol::overload(
		[](const char* text) { mq::imgui::HelpMarker(text); },
		[](const char* text, float width) { mq::imgui::HelpMarker(text, width); },
		[](const char* text, float width, ImFont* font) { mq::imgui::HelpMarker(text, width, font); }
	));

	ImGui.set("ConsoleFont", mq::imgui::ConsoleFont);

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
