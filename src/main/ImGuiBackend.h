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

struct ImDrawData;
struct IDirect3DDevice9;
struct IDirect3DSurface9;
struct ID3D11Device;
struct ID3D11DeviceContext;
struct ID3D11Texture2D;
struct ID3D11DepthStencilView;
struct ID3D11DepthStencilState;
struct ID3D11BlendState;
struct ID3D11PixelShader;

namespace mq {

//----------------------------------------------------------------------------
// DX9 renderer backend
//----------------------------------------------------------------------------

#if HAS_DIRECTX_9

bool     ImGui_ImplDX9_Init(IDirect3DDevice9* device);
void     ImGui_ImplDX9_Shutdown();
void     ImGui_ImplDX9_NewFrame();
void     ImGui_ImplDX9_RenderDrawData(ImDrawData* draw_data);

// Use if you want to reset your rendering device without losing ImGui state.
void     ImGui_ImplDX9_InvalidateDeviceObjects();
bool     ImGui_ImplDX9_CreateDeviceObjects();

// (Advanced) Use e.g. if you need to precisely control the timing of texture updates (e.g. for staged rendering), by setting ImDrawData::Textures = NULL to handle this manually.
void     ImGui_ImplDX9_UpdateTexture(ImTextureData* tex);

// Selected render state data shared with callbacks.
// This is temporarily stored in GetPlatformIO().Renderer_RenderState during the ImGui_ImplDX9_RenderDrawData() call.
struct ImGui_ImplDX9_RenderState
{
	IDirect3DDevice9*   Device;
	IDirect3DSurface9*  StencilSurface;      // dedicated D24S8 stencil surface
};

#endif // HAS_DIRECTX_9

//----------------------------------------------------------------------------
// DX11 renderer backend
//----------------------------------------------------------------------------

#if HAS_DIRECTX_11

bool     ImGui_ImplDX11_Init(ID3D11Device* device, ID3D11DeviceContext* device_context);
void     ImGui_ImplDX11_Shutdown();
void     ImGui_ImplDX11_NewFrame();
void     ImGui_ImplDX11_RenderDrawData(ImDrawData* draw_data);

// Use if you want to reset your rendering device without losing Dear ImGui state.
void     ImGui_ImplDX11_InvalidateDeviceObjects();
bool     ImGui_ImplDX11_CreateDeviceObjects();

// (Advanced) Use e.g. if you need to precisely control the timing of texture updates (e.g. for staged rendering), by setting ImDrawData::Textures = NULL to handle this manually.
void     ImGui_ImplDX11_UpdateTexture(ImTextureData* tex);

// [BETA] Selected render state data shared with callbacks.
// This is temporarily stored in GetPlatformIO().Renderer_RenderState during the ImGui_ImplDX11_RenderDrawData() call.
// (Please open an issue if you feel you need access to more data)
struct ImGui_ImplDX11_RenderState
{
	ID3D11Device*               Device;
	ID3D11DeviceContext*        DeviceContext;
	ID3D11SamplerState*         SamplerDefault;
	ID3D11Buffer*               VertexConstantBuffer;

	// Alpha mask / stencil support:
	ID3D11DepthStencilView*     StencilDSV;              // dedicated stencil surface, nullptr until first use
	ID3D11DepthStencilState*    StencilWriteDSS[8];      // [i] = write bit (1<<i); WriteMask=(1<<i), func=ALWAYS
	ID3D11DepthStencilState*    StencilTestEqualDSS;     // (stencil & 0xFF) == ref, no writes
	ID3D11DepthStencilState*    StencilTestNotEqualDSS;  // (stencil & 0xFF) != ref, no writes
	ID3D11DepthStencilState*    DefaultDSS;              // default imgui state (stencil off)
	ID3D11BlendState*           DefaultBlendState;       // normal alpha blend
	ID3D11BlendState*           NoColorBlendState;       // all color channel writes disabled (stencil write pass)
	ID3D11BlendState*           AlphaWriteBlendState;    // writes only fb alpha; RGB unchanged (soft mask phase 1)
	ID3D11BlendState*           ZeroAlphaBlendState;     // forces fb alpha to 0; RGB unchanged (soft mask clear)
	ID3D11BlendState*           DestAlphaBlendState;     // RGB blended by fb alpha coverage (soft mask phase 2)
	ID3D11PixelShader*          DefaultPS;               // normal imgui pixel shader
	ID3D11PixelShader*          AlphaDiscardPS;          // discards pixels with alpha < 0.5
};

#endif // HAS_DIRECTX_11

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
