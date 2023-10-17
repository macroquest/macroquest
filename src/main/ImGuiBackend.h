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

struct ImDrawData;
struct IDirect3DDevice9;
struct ID3D11Device;
struct ID3D11DeviceContext;

namespace mq {

//----------------------------------------------------------------------------
// DX9 renderer backend
//----------------------------------------------------------------------------

bool     ImGui_ImplDX9_Init(IDirect3DDevice9* device);
void     ImGui_ImplDX9_Shutdown();
void     ImGui_ImplDX9_NewFrame();
void     ImGui_ImplDX9_RenderDrawData(ImDrawData* draw_data);

// Use if you want to reset your rendering device without losing ImGui state.
void     ImGui_ImplDX9_InvalidateDeviceObjects();
bool     ImGui_ImplDX9_CreateDeviceObjects();


//----------------------------------------------------------------------------
// DX11 renderer backend
//----------------------------------------------------------------------------

bool     ImGui_ImplDX11_Init(ID3D11Device* device, ID3D11DeviceContext* device_context);
void     ImGui_ImplDX11_Shutdown();
void     ImGui_ImplDX11_NewFrame();
void     ImGui_ImplDX11_RenderDrawData(ImDrawData* draw_data);

// Use if you want to reset your rendering device without losing Dear ImGui state.
void     ImGui_ImplDX11_InvalidateDeviceObjects();
bool     ImGui_ImplDX11_CreateDeviceObjects();


//----------------------------------------------------------------------------
// Win32 platform backend
//----------------------------------------------------------------------------

bool     ImGui_ImplWin32_Init(void* hwnd);
void     ImGui_ImplWin32_Shutdown();
void     ImGui_ImplWin32_NewFrame();

float    ImGui_ImplWin32_GetDpiScaleForMonitor(void* monitor);

void     ImGui_EnableViewports(bool enable);
void     ImGui_EnableDocking(bool enable);
bool     ImGui_IsImGuiForeground();

// Implemented by ImGuiOverlay.cpp
bool     ImGuiOverlay_HandleMouseEvent(int mouseButton, bool pressed);

struct ImGuiViewportData
{
	HWND hDeviceWindow;
};

} // namespace mq
