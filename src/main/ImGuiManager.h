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

#include <imgui/imgui.h>

namespace mq {

void ImGuiManager_Initialize();
void ImGuiManager_Shutdown();
void ImGuiManager_Pulse();

void ImGuiManager_NewFrame();
void ImGuiManager_DrawFrame();
void ImGuiManager_DrawCursorAttachment();

bool ImGuiManager_HandleWndProcEx(HWND hWnd, uint32_t msg, uintptr_t wparam, intptr_t lparam, ImGuiIO& io);
bool ImGuiManager_HandleWndProc(HWND hWnd, uint32_t msg, uintptr_t wparam, intptr_t lparam);

void ImGuiManager_BuildFonts(ImFontAtlas* fontAtlas);
ImFont* ImGuiManager_GetEQImFont(int fontID);


void ImGuiManager_ReloadContext();
void ImGuiManager_CreateContext();
void ImGuiManager_DestroyContext();

void ImGuiManager_OverlaySettings();

void ImGuiManager_ResetGameViewport();

// Returns HCURSOR
void* ImGuiManager_GetCursorForImGui(ImGuiMouseCursor imguiCursor);

// Set to true to put imgui into partial recovery mode.
extern bool gbManualResetRequired;

// global imgui toggle
extern bool gbRenderImGui;

// When true, hides the cursor attachment
extern bool gbHideCursorAttachment;

// When greater than 0, we will skip this number of frames of tampering with the ui
extern int gDrawWindowFrameSkipCount;

} // namespace mq
