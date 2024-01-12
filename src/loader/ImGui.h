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

#pragma once

#include <functional>
#include <string>

#include "hello_imgui/screen_bounds.h"

namespace LauncherImGui {

void Run(
	const std::function<void()>& render,
	const std::string& windowTitle = "",
	bool windowSizeAuto = false,
	bool windowRestorePreviousGeometry = false,
	const HelloImGui::ScreenSize& windowSize = HelloImGui::DefaultWindowSize,
	float fpsIdle = 10.f
);

bool AddWindow(const std::string& name, const std::function<void()> callback);
bool RemoveWindow(const std::string& name);
void Run();

} // namespace LauncherImGui
