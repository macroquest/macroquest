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

#include "imgui/imgui.h"

typedef void (_cdecl * SDL_WindowsMessageHook)(void *userdata, void *hWnd, unsigned int message, uint64_t wParam, int64_t lParam);

namespace HelloImGui {
struct DockableWindow;
} // namespace HelloImGui

namespace LauncherImGui {

void AddViewport(HelloImGui::DockableWindow&& params);
void AddViewport(
	const std::function<void()>& render,
	const std::string& windowTitle,
	const ImVec2& windowSize = ImVec2((float)HelloImGui::DefaultWindowSize[0], (float)HelloImGui::DefaultWindowSize[1]),
	const ImVec2& windowPosition = ImVec2((float)HelloImGui::DefaultScreenPosition[0], (float)HelloImGui::DefaultScreenPosition[1])
);

bool AddWindow(const std::string& name, const std::function<void()> callback);
bool RemoveWindow(const std::string& name);
void Run(SDL_WindowsMessageHook eventHandler, float fpsIdle = 10.f);
void Terminate();
void AddViewport();

} // namespace LauncherImGui
