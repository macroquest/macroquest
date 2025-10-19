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

#pragma once

#include <functional>
#include <windows.h>

//============================================================================
namespace LauncherImGui {
namespace Backend {
void Init(HWND hWnd, const char* iniFilename, const char* logFilename);
void DrawFrame(const std::function<void()>& drawFrame);
void Cleanup();
bool HandleWndProc(HWND hWnd, uint32_t msg, uintptr_t wParam, intptr_t lParam);
} // namespace Backend
} // namespace LauncherImGui
