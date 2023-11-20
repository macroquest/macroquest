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

#include <imgui/implot/implot.h>
#include <sol/sol.hpp>

#include <string>

namespace mq::lua::bindings {

//============================================================================

sol::table RegisterBindings_ImPlot(sol::this_state L)
{
	// The creation of this namespace is gated by the ImGui namespace.
	sol::state_view state{ L };

	sol::table ImPlot = state.create_table();

	ImPlot["hello"] = 3;

	return ImPlot;

}

} // namespace mq::lua::bindings
