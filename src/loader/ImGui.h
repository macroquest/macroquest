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

#include "imgui/imgui.h"

#include <functional>
#include <string>

namespace LauncherImGui {
bool SmallCheckbox(const char* label, bool* v);
void RenderTableCheckmark();
void RenderTableCircle(ImU32 color, bool filled);
bool ToggleSlider(const char* label, bool* v);
void OpenModal(const std::string& name);
bool BeginModal(const std::string& name, bool* p_open, ImGuiWindowFlags flags);
void EndModal();
void CloseModal();

void OpenWindow(
	const std::function<bool()>& draw,
	const std::string& label
);

void SelectMainPanel(const std::string& name);
void AddMainPanel(const char* name, void(*callback)());
void RemoveMainPanel(const char* name);
bool AddContextGroup(const std::string& name, const std::function<void()>& callback);
bool RemoveContextGroup(const std::string& name);
void Run(const std::function<bool()>& mainLoop);
void OpenMainWindow();
void OpenContextMenu();
void OpenMessageBox(ImGuiViewport* viewport, const std::string& message, const std::string& title, const ImVec2& size = ImVec2(320.0f, 200.0f));

} // namespace LauncherImGui
