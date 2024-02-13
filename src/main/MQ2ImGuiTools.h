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

#include "MQ2MainBase.h"

#include <imgui.h>

namespace mq {

// Toggles the ImGui overlay
MQLIB_API void ToggleImGuiOverlay();

//----------------------------------------------------------------------------

void ImGuiTools_DrawWindowsMenu();

void InitializeImGuiConsole();
void ShutdownImGuiConsole();
void UpdateImGuiConsole();

DWORD ImGuiConsoleAddText(const char* line, DWORD color, DWORD filter);

} // namespace mq
