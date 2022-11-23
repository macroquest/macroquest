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
}

} // namespace mq::lua::bindings
