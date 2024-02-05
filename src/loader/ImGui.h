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

#include "imgui/imgui.h"

#include <windows.h>

typedef void (_cdecl * SDL_WindowsMessageHook)(void *userdata, void *hWnd, unsigned int message, uint64_t wParam, int64_t lParam);

namespace LauncherImGui {
bool SmallCheckbox(const char* label, bool* v);
bool ToggleSlider(const char* label, bool* v);
void OpenModal(const std::string& name);
bool BeginModal(const std::string& name, bool* p_open, ImGuiWindowFlags flags);
void EndModal();
void CloseModal();

struct Viewport
{
	std::function<bool()> DrawFrame;
};

void OpenWindow(
	const std::function<bool()>& draw,
	const std::string& label
);

bool AddMainPanel(const std::string& name, const std::function<void()>& callback);
bool RemoveMainPanel(const std::string& name);
bool AddContextGroup(const std::string& name, const std::function<void()>& callback);
bool RemoveContextGroup(const std::string& name);
void Run(const std::function<bool()>& mainLoop);
bool HandleWndProc(HWND hWnd, uint32_t msg, uintptr_t wParam, intptr_t lParam);
void OpenMainWindow();
void OpenContextMenu();
void OpenMessageBox(ImGuiViewport* viewport, const std::string& message, const std::string& title);

} // namespace LauncherImGui
