/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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

#include <imgui.h>

namespace mq {

void ImGuiManager_Initialize();
void ImGuiManager_Shutdown();
void ImGuiManager_Pulse();

void ImGuiManager_DrawFrame();
bool ImGuiManager_HandleWndProc(uint32_t msg, uintptr_t wparam, intptr_t lparam);

void ImGuiManager_BuildFonts(ImFontAtlas* fontAtlas);

// Returns HCURSOR
void* ImGuiManager_GetCursorForImGui(ImGuiMouseCursor imguiCursor);

// Set to true to put imgui into partial recovery mode.
extern bool gbManualResetRequired;

} // namespace mq
