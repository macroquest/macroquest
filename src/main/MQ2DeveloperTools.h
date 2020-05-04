/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
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

#include "MQ2Main.h"

namespace mq {

bool DeveloperTools_HandleClick(int mouseButton, bool clicked);

void DeveloperTools_CloseLoginFrontend();

void DeveloperTools_DrawMenu();

// Developer Tools - Window Inspector panel
void DeveloperTools_ShowWindowInspector(CXWnd* pWnd);
void DeveloperTools_RemoveWindow(CXWnd* pWnd);

} // namespace mq

