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

#include "pch.h"

#include "ImGuiBackend.h"
#include "ImGuiManager.h"
#include "../common/Common.h"

#include <wil/com.h>
#include <imgui.h>
#include <d3d9.h>

namespace mq {

extern "C" HINSTANCE ghInstance;

#pragma region ImGui Modified DirectX 9 renderer for Everquest

//============================================================================
// Custom ImGui renderer for win32 and directx 9, integrated into EverQuest,
// written by Brainiac, based off of example code from github.com/ocornut/imgui

// Implemented features:
//  [X] Renderer: User texture binding. Use 'LPDIRECT3DTEXTURE9' as ImTextureID. Read the FAQ about ImTextureID!
//  [X] Renderer: Multi-viewport support. Enable with 'io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable'.
//  [X] Renderer: Support for large meshes (64k+ vertices) with 16-bit indices.

// You can use unmodified imgui_impl_* files in your project. See examples/ folder for examples of using this.
// Prefer including the entire imgui/ repository into your project (either as a copy or as a submodule), and only build the backends you need.
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

// CHANGELOG
// (minor and older changes stripped away, please see git history for details)
//  2021-XX-XX: Platform: Added support for multiple windows via the ImGuiPlatformIO interface.
//  2021-06-29: Reorganized backend to pull data from a single structure to facilitate usage with multiple-contexts (all g_XXXX access changed to bd->XXXX).
//  2021-06-25: DirectX9: Explicitly disable texture state stages after >= 1.
//  2021-05-19: DirectX9: Replaced direct access to ImDrawCmd::TextureId with a call to ImDrawCmd::GetTexID(). (will become a requirement)
//  2021-04-23: DirectX9: Explicitly setting up more graphics states to increase compatibility with unusual non-default states.
//  2021-03-18: DirectX9: Calling IDirect3DStateBlock9::Capture() after CreateStateBlock() as a workaround for state restoring issues (see #3857).
//  2021-03-03: DirectX9: Added support for IMGUI_USE_BGRA_PACKED_COLOR in user's imconfig file.
//  2021-02-18: DirectX9: Change blending equation to preserve alpha in output buffer.
//  2019-05-29: DirectX9: Added support for large mesh (64K+ vertices), enable ImGuiBackendFlags_RendererHasVtxOffset flag.
//  2019-04-30: DirectX9: Added support for special ImDrawCallback_ResetRenderState callback to reset render state.
//  2019-03-29: Misc: Fixed erroneous assert in ImGui_ImplDX9_InvalidateDeviceObjects().
//  2019-01-16: Misc: Disabled fog before drawing UI's. Fixes issue #2288.
//  2018-11-30: Misc: Setting up io.BackendRendererName so it can be displayed in the About Window.
//  2018-06-08: Misc: Extracted imgui_impl_dx9.cpp/.h away from the old combined DX9+Win32 example.
//  2018-06-08: DirectX9: Use draw_data->DisplayPos and draw_data->DisplaySize to setup projection matrix and clipping rectangle.
//  2018-05-07: Render: Saving/restoring Transform because they don't seem to be included in the StateBlock. Setting shading mode to Gouraud.
//  2018-02-16: Misc: Obsoleted the io.RenderDrawListsFn callback and exposed ImGui_ImplDX9_RenderDrawData() in the .h file so you can call it yourself.
//  2018-02-06: Misc: Removed call to ImGui::Shutdown() which is not available from 1.60 WIP, user needs to call CreateContext/DestroyContext themselves.

struct ImGui_ImplDX9_Data
{
	wil::com_ptr_nothrow<IDirect3DDevice9>         pd3dDevice;
	wil::com_ptr_nothrow<IDirect3DVertexBuffer9>   pVB;
	wil::com_ptr_nothrow<IDirect3DIndexBuffer9>    pIB;
	wil::com_ptr_nothrow<IDirect3DTexture9>        FontTexture;
	int                                            VertexBufferSize = 5000;
	int                                            IndexBufferSize = 10000;

	ImGui_ImplDX9_Data()
	{
	}
};

struct CUSTOMVERTEX
{
	float    pos[3];
	D3DCOLOR col;
	float    uv[2];
};
constexpr int D3DFVF_CUSTOMVERTEX = (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

#ifdef IMGUI_USE_BGRA_PACKED_COLOR
#define IMGUI_COL_TO_DX9_ARGB(_COL)     (_COL)
#else
#define IMGUI_COL_TO_DX9_ARGB(_COL)     (((_COL) & 0xFF00FF00) | (((_COL) & 0xFF0000) >> 16) | (((_COL) & 0xFF) << 16))
#endif

// Backend data stored in io.BackendRendererUserData to allow support for multiple Dear ImGui contexts
// It is STRONGLY preferred that you use docking branch with multi-viewports (== single Dear ImGui context + multiple windows) instead of multiple Dear ImGui contexts.
static ImGui_ImplDX9_Data* ImGui_ImplDX9_GetBackendData()
{
	return ImGui::GetCurrentContext() ? (ImGui_ImplDX9_Data*)ImGui::GetIO().BackendRendererUserData : nullptr;
}

//----------------------------------------------------------------------------
// Forward Declarations
static void ImGui_ImplDX9_InitPlatformInterface();
static void ImGui_ImplDX9_ShutdownPlatformInterface();
static void ImGui_ImplDX9_CreateDeviceObjectsForPlatformWindows();
static void ImGui_ImplDX9_InvalidateDeviceObjectsForPlatformWindows();

//----------------------------------------------------------------------------
//
void ImGui_ImplDX9_SetupRenderState(ImDrawData* drawData)
{
	ImGui_ImplDX9_Data* bd = ImGui_ImplDX9_GetBackendData();
	// Setup viewport
	D3DVIEWPORT9 vp;
	vp.X = vp.Y = 0;
	vp.Width = (DWORD)drawData->DisplaySize.x;
	vp.Height = (DWORD)drawData->DisplaySize.y;
	vp.MinZ = 0.0f;
	vp.MaxZ = 1.0f;
	bd->pd3dDevice->SetViewport(&vp);

	// Setup render state: fixed-pipeline, alpha-blending, no face culling, no depth testing, shade mode (for gradient)
	bd->pd3dDevice->SetPixelShader(NULL);
	bd->pd3dDevice->SetVertexShader(NULL);
	bd->pd3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
	bd->pd3dDevice->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);
	bd->pd3dDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
	bd->pd3dDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	bd->pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	bd->pd3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
	bd->pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	bd->pd3dDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	bd->pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	bd->pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	bd->pd3dDevice->SetRenderState(D3DRS_SEPARATEALPHABLENDENABLE, TRUE);
	bd->pd3dDevice->SetRenderState(D3DRS_SRCBLENDALPHA, D3DBLEND_ONE);
	bd->pd3dDevice->SetRenderState(D3DRS_DESTBLENDALPHA, D3DBLEND_INVSRCALPHA);
	bd->pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, TRUE);
	bd->pd3dDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);
	bd->pd3dDevice->SetRenderState(D3DRS_RANGEFOGENABLE, FALSE);
	bd->pd3dDevice->SetRenderState(D3DRS_SPECULARENABLE, FALSE);
	bd->pd3dDevice->SetRenderState(D3DRS_STENCILENABLE, FALSE);
	bd->pd3dDevice->SetRenderState(D3DRS_CLIPPING, TRUE);
	bd->pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	bd->pd3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	bd->pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	bd->pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	bd->pd3dDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	bd->pd3dDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	bd->pd3dDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
	bd->pd3dDevice->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE);
	bd->pd3dDevice->SetTextureStageState(1, D3DTSS_ALPHAOP, D3DTOP_DISABLE);
	bd->pd3dDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	bd->pd3dDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);

	// Setup orthographic projection matrix
	// Our visible imgui space lies from draw_data->DisplayPos (top left) to draw_data->DisplayPos+data_data->DisplaySize (bottom right). DisplayPos is (0,0) for single viewport apps.
	// Being agnostic of whether <d3dx9.h> or <DirectXMath.h> can be used, we aren't relying on D3DXMatrixIdentity()/D3DXMatrixOrthoOffCenterLH() or DirectX::XMMatrixIdentity()/DirectX::XMMatrixOrthographicOffCenterLH()
	{
		float L = drawData->DisplayPos.x + 0.5f;
		float R = drawData->DisplayPos.x + drawData->DisplaySize.x + 0.5f;
		float T = drawData->DisplayPos.y + 0.5f;
		float B = drawData->DisplayPos.y + drawData->DisplaySize.y + 0.5f;
		D3DMATRIX mat_identity = { { { 1.0f, 0.0f, 0.0f, 0.0f,  0.0f, 1.0f, 0.0f, 0.0f,  0.0f, 0.0f, 1.0f, 0.0f,  0.0f, 0.0f, 0.0f, 1.0f } } };
		D3DMATRIX mat_projection =
		{ { {
			2.0f/(R-L),   0.0f,         0.0f,  0.0f,
			0.0f,         2.0f/(T-B),   0.0f,  0.0f,
			0.0f,         0.0f,         0.5f,  0.0f,
			(L+R)/(L-R),  (T+B)/(B-T),  0.5f,  1.0f
		} } };
		bd->pd3dDevice->SetTransform(D3DTS_WORLD, &mat_identity);
		bd->pd3dDevice->SetTransform(D3DTS_VIEW, &mat_identity);
		bd->pd3dDevice->SetTransform(D3DTS_PROJECTION, &mat_projection);
	}
}

// Render function.
void ImGui_ImplDX9_RenderDrawData(ImDrawData* drawData)
{
	// Avoid rendering when minimized
	if (drawData->DisplaySize.x <= 0.0f || drawData->DisplaySize.y <= 0.0f)
		return;

	// Create and grow buffers if needed
	ImGui_ImplDX9_Data* bd = ImGui_ImplDX9_GetBackendData();
	if (!bd->pVB || bd->VertexBufferSize < drawData->TotalVtxCount)
	{
		bd->VertexBufferSize = drawData->TotalVtxCount + 5000;

		if (bd->pd3dDevice->CreateVertexBuffer(
			bd->VertexBufferSize * sizeof(CUSTOMVERTEX),
			D3DUSAGE_DYNAMIC | D3DUSAGE_WRITEONLY,
			D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &bd->pVB, nullptr) < 0)
		{
			return;
		}
	}

	if (!bd->pIB || bd->IndexBufferSize < drawData->TotalIdxCount)
	{
		bd->IndexBufferSize = drawData->TotalIdxCount + 10000;

		if (bd->pd3dDevice->CreateIndexBuffer(
			bd->IndexBufferSize * sizeof(ImDrawIdx),
			D3DUSAGE_DYNAMIC | D3DUSAGE_WRITEONLY,
			sizeof(ImDrawIdx) == 2 ? D3DFMT_INDEX16 : D3DFMT_INDEX32, D3DPOOL_DEFAULT, &bd->pIB, nullptr) < 0)
		{
			return;
		}
	}

	// Backup the DX9 state
	wil::com_ptr_nothrow<IDirect3DStateBlock9> d3d9StateBlock;
	if (bd->pd3dDevice->CreateStateBlock(D3DSBT_ALL, &d3d9StateBlock) < 0)
		return;
	if (d3d9StateBlock->Capture() < 0)
		return;

	// Backup the DX9 transform (DX9 documentation suggests that it is included in the StateBlock but it doesn't appear to)
	D3DMATRIX lastWorld, lastView, lastProjection;
	bd->pd3dDevice->GetTransform(D3DTS_WORLD, &lastWorld);
	bd->pd3dDevice->GetTransform(D3DTS_VIEW, &lastView);
	bd->pd3dDevice->GetTransform(D3DTS_PROJECTION, &lastProjection);

	// Allocate buffers
	CUSTOMVERTEX* vtxDst;
	ImDrawIdx* idxDst;
	if (bd->pVB->Lock(0, (UINT)(drawData->TotalVtxCount * sizeof(CUSTOMVERTEX)), (void**)&vtxDst, D3DLOCK_DISCARD) < 0)
		return;

	if (bd->pIB->Lock(0, (UINT)(drawData->TotalIdxCount * sizeof(ImDrawIdx)), (void**)&idxDst, D3DLOCK_DISCARD) < 0)
	{
		bd->pVB->Unlock();
		return;
	}

	// Copy and convert all vertices into a single contiguous buffer, convert colors to DX9 default format.
	// FIXME-OPT: This is a waste of resource, the ideal is to use imconfig.h and
	//  1) to avoid repacking colors:   #define IMGUI_USE_BGRA_PACKED_COLOR
	//  2) to avoid repacking vertices: #define IMGUI_OVERRIDE_DRAWVERT_STRUCT_LAYOUT struct ImDrawVert { ImVec2 pos; float z; ImU32 col; ImVec2 uv; }
	for (int n = 0; n < drawData->CmdListsCount; n++)
	{
		const ImDrawList* cmdList = drawData->CmdLists[n];
		const ImDrawVert* vtxSrc = cmdList->VtxBuffer.Data;

		for (int i = 0; i < cmdList->VtxBuffer.Size; i++)
		{
			vtxDst->pos[0] = vtxSrc->pos.x;
			vtxDst->pos[1] = vtxSrc->pos.y;
			vtxDst->pos[2] = 0.0f;
			vtxDst->col = IMGUI_COL_TO_DX9_ARGB(vtxSrc->col);
			vtxDst->uv[0] = vtxSrc->uv.x;
			vtxDst->uv[1] = vtxSrc->uv.y;
			vtxDst++;
			vtxSrc++;
		}

		memcpy(idxDst, cmdList->IdxBuffer.Data, cmdList->IdxBuffer.Size * sizeof(ImDrawIdx));
		idxDst += cmdList->IdxBuffer.Size;
	}

	bd->pVB->Unlock();
	bd->pIB->Unlock();
	bd->pd3dDevice->SetStreamSource(0, bd->pVB.get(), 0, sizeof(CUSTOMVERTEX));
	bd->pd3dDevice->SetIndices(bd->pIB.get());
	bd->pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	// Setup desired DX state
	ImGui_ImplDX9_SetupRenderState(drawData);

	// Render command lists
	// (Because we merged all buffers into a single one, we maintain our own offset into them)
	int globalVtxOffset = 0;
	int globalIdxOffset = 0;
	ImVec2 clipOff = drawData->DisplayPos;
	for (int n = 0; n < drawData->CmdListsCount; n++)
	{
		const ImDrawList* cmdList = drawData->CmdLists[n];
		for (int cmdIndex = 0; cmdIndex < cmdList->CmdBuffer.Size; cmdIndex++)
		{
			const ImDrawCmd* pCmd = &cmdList->CmdBuffer[cmdIndex];
			if (pCmd->UserCallback != nullptr)
			{
				// User callback, registered via ImDrawList::AddCallback()
				// (ImDrawCallback_ResetRenderState is a special callback value used by the user to request the renderer to reset render state.)
				if (pCmd->UserCallback == ImDrawCallback_ResetRenderState)
					ImGui_ImplDX9_SetupRenderState(drawData);
				else
					pCmd->UserCallback(cmdList, pCmd);
			}
			else
			{
				// Project scissor/clipping rectangles into framebuffer space
				ImVec2 clipMin(pCmd->ClipRect.x - clipOff.x, pCmd->ClipRect.y - clipOff.y);
				ImVec2 clipMax(pCmd->ClipRect.z - clipOff.x, pCmd->ClipRect.w - clipOff.y);
				if (clipMax.x < clipMin.x || clipMax.y < clipMin.y)
					continue;

				// Apply Scissor/clipping rectangle, Bind texture, Draw
				const RECT r = { (LONG)clipMin.x, (LONG)clipMin.y, (LONG)clipMax.x, (LONG)clipMax.y };
				const LPDIRECT3DTEXTURE9 texture = (LPDIRECT3DTEXTURE9)pCmd->GetTexID();
				bd->pd3dDevice->SetTexture(0, texture);
				bd->pd3dDevice->SetScissorRect(&r);
				bd->pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, pCmd->VtxOffset + globalVtxOffset, 0, (UINT)cmdList->VtxBuffer.Size, pCmd->IdxOffset + globalIdxOffset, pCmd->ElemCount / 3);
			}
		}

		globalIdxOffset += cmdList->IdxBuffer.Size;
		globalVtxOffset += cmdList->VtxBuffer.Size;
	}

	// When using multi-viewports, it appears that there's an odd logic in DirectX9 which prevent subsequent windows
	// from rendering until the first window submits at least one draw call, even once. That's our workaround. (see #2560)
	if (globalVtxOffset == 0)
		bd->pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 0, 0, 0);

	// Restore the DX9 transform
	bd->pd3dDevice->SetTransform(D3DTS_WORLD, &lastWorld);
	bd->pd3dDevice->SetTransform(D3DTS_VIEW, &lastView);
	bd->pd3dDevice->SetTransform(D3DTS_PROJECTION, &lastProjection);

	// Restore the DX9 state
	d3d9StateBlock->Apply();
}

bool ImGui_ImplDX9_Init(IDirect3DDevice9* device)
{
	ImGuiIO& io = ImGui::GetIO();
	IM_ASSERT(io.BackendRendererUserData == nullptr && "Already initialized a renderer backend!");

	// Setup back-end capabilities flags
	ImGui_ImplDX9_Data* bd = new ImGui_ImplDX9_Data();
	io.BackendRendererUserData = (void*)bd;
	io.BackendRendererName = "imgui_impl_dx9";
	io.BackendFlags |= ImGuiBackendFlags_RendererHasVtxOffset;  // We can honor the ImDrawCmd::VtxOffset field, allowing for large meshes.
	io.BackendFlags |= ImGuiBackendFlags_RendererHasViewports;  // We can create multi-viewports on the Renderer side (optional)

	bd->pd3dDevice = device;

	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		ImGui_ImplDX9_InitPlatformInterface();

	return true;
}

void ImGui_ImplDX9_Shutdown()
{
	if (!ImGui::GetCurrentContext())
		return;

	ImGui_ImplDX9_Data* bd = ImGui_ImplDX9_GetBackendData();
	IM_ASSERT(bd != nullptr && "No renderer backend to shutdown, or already shutdown?");
	ImGuiIO& io = ImGui::GetIO();

	ImGui_ImplDX9_ShutdownPlatformInterface();
	ImGui_ImplDX9_InvalidateDeviceObjects();

	io.BackendRendererName = nullptr;
	io.BackendRendererUserData = nullptr;
	delete bd;
}

bool ImGui_ImplDX9_CreateFontsTexture()
{
	// Build texture atlas
	ImGuiIO& io = ImGui::GetIO();
	ImGui_ImplDX9_Data* bd = ImGui_ImplDX9_GetBackendData();

	unsigned char* pixels;
	int width, height, bytes_per_pixel;
	io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height, &bytes_per_pixel);

	// Convert RGBA32 to BGRA32 (because RGBA32 is not well supported by DX9 devices)
#ifndef IMGUI_USE_BGRA_PACKED_COLOR
	if (io.Fonts->TexPixelsUseColors)
	{
		ImU32* dstStart = (ImU32*)ImGui::MemAlloc((size_t)width * height * bytes_per_pixel);
		for (ImU32* src = (ImU32*)pixels, *dst = dstStart, *dst_end = dstStart + (size_t)width * height; dst < dst_end; src++, dst++)
			*dst = IMGUI_COL_TO_DX9_ARGB(*src);
		pixels = (unsigned char*)dstStart;
	}
#endif

	// Upload texture to graphics system
	if (bd->pd3dDevice->CreateTexture(width, height, 1, D3DUSAGE_DYNAMIC, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &bd->FontTexture, nullptr) < 0)
		return false;

	D3DLOCKED_RECT tex_locked_rect;
	if (bd->FontTexture->LockRect(0, &tex_locked_rect, nullptr, 0) != D3D_OK)
		return false;

	for (int y = 0; y < height; y++)
		memcpy((unsigned char*)tex_locked_rect.pBits + (size_t)tex_locked_rect.Pitch * y, pixels + (size_t)width * bytes_per_pixel * y, (size_t)width * bytes_per_pixel);
	bd->FontTexture->UnlockRect(0);

	// Store our identifier
	io.Fonts->SetTexID((ImTextureID)bd->FontTexture.get());

#ifndef IMGUI_USE_BGRA_PACKED_COLOR
	if (io.Fonts->TexPixelsUseColors)
		ImGui::MemFree(pixels);
#endif

	return true;
}

bool ImGui_ImplDX9_CreateDeviceObjects()
{
	ImGui_ImplDX9_Data* bd = ImGui_ImplDX9_GetBackendData();
	if (!bd || !bd->pd3dDevice)
		return false;
	if (!ImGui_ImplDX9_CreateFontsTexture())
		return false;
	ImGui_ImplDX9_CreateDeviceObjectsForPlatformWindows();
	return true;
}

void ImGui_ImplDX9_InvalidateDeviceObjects()
{
	ImGui_ImplDX9_Data* bd = ImGui_ImplDX9_GetBackendData();
	if (bd)
	{
		bd->pVB.reset();
		bd->pIB.reset();
		bd->FontTexture.reset();
	}

	// We copied g_pFontTextureView to io.Fonts->TexID so let's clear that as well.
	ImGui::GetIO().Fonts->SetTexID(nullptr);

	ImGui_ImplDX9_InvalidateDeviceObjectsForPlatformWindows();
}

void ImGui_ImplDX9_NewFrame()
{
	ImGui_ImplDX9_Data* bd = ImGui_ImplDX9_GetBackendData();
	IM_ASSERT(bd != NULL && "Did you call ImGui_ImplDX9_Init()?");

	if (!bd->FontTexture)
		ImGui_ImplDX9_CreateDeviceObjects();
}

#pragma endregion

#pragma region Dx9 Renderer Multi-Viewport Support

//--------------------------------------------------------------------------------------------------------
// MULTI-VIEWPORT / PLATFORM INTERFACE SUPPORT
// This is an _advanced_ and _optional_ feature, allowing the back-end to create and handle multiple viewports simultaneously.
// If you are new to dear imgui or creating a new binding for dear imgui, it is recommended that you completely ignore this section first..
//--------------------------------------------------------------------------------------------------------

struct ImGuiViewportDataDx9 : public ImGuiViewportData
{
	wil::com_ptr_nothrow<IDirect3DSwapChain9> SwapChain;
	D3DPRESENT_PARAMETERS   d3dpp;

	ImGuiViewportDataDx9() { ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS)); }
	~ImGuiViewportDataDx9() { IM_ASSERT(SwapChain == nullptr); }
};

static void ImGui_ImplDX9_CreateWindow(ImGuiViewport* viewport)
{
	ImGui_ImplDX9_Data* bd = ImGui_ImplDX9_GetBackendData();
	ImGuiViewportDataDx9* vd = new ImGuiViewportDataDx9();
	viewport->RendererUserData = vd;

	// PlatformHandleRaw should always be a HWND, whereas PlatformHandle might be a higher-level handle (e.g. GLFWWindow*, SDL_Window*).
	// Some back-ends will leave PlatformHandleRaw NULL, in which case we assume PlatformHandle will contain the HWND.
	HWND hwnd = viewport->PlatformHandleRaw ? (HWND)viewport->PlatformHandleRaw : (HWND)viewport->PlatformHandle;
	IM_ASSERT(hwnd != nullptr);

	ZeroMemory(&vd->d3dpp, sizeof(D3DPRESENT_PARAMETERS));
	vd->d3dpp.Windowed = TRUE;
	vd->d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	vd->d3dpp.BackBufferWidth = (UINT)viewport->Size.x;
	vd->d3dpp.BackBufferHeight = (UINT)viewport->Size.y;
	vd->d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	vd->d3dpp.hDeviceWindow = hwnd;
	vd->d3dpp.EnableAutoDepthStencil = FALSE;
	vd->d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	vd->d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;   // Present without vsync
	vd->hDeviceWindow = hwnd;

	HRESULT hr = bd->pd3dDevice->CreateAdditionalSwapChain(&vd->d3dpp, &vd->SwapChain); IM_UNUSED(hr);
	IM_ASSERT(hr == D3D_OK);
	IM_ASSERT(vd->SwapChain != nullptr);
}

static void ImGui_ImplDX9_DestroyWindow(ImGuiViewport* viewport)
{
	// The main viewport (owned by the application) will always have RendererUserData == NULL since we didn't create the data for it.
	ImGuiViewportDataDx9* vd = (ImGuiViewportDataDx9*)viewport->RendererUserData;
	if (vd) vd->SwapChain.reset();
	delete vd;

	viewport->RendererUserData = nullptr;
}

static void ImGui_ImplDX9_SetWindowSize(ImGuiViewport* viewport, ImVec2 size)
{
	ImGui_ImplDX9_Data* bd = ImGui_ImplDX9_GetBackendData();
	ImGuiViewportDataDx9* vd = (ImGuiViewportDataDx9*)viewport->RendererUserData;
	if (vd->SwapChain)
	{
		ImGuiViewportDataDx9 newData;
		newData.SwapChain = nullptr;
		newData.d3dpp = vd->d3dpp;
		newData.d3dpp.BackBufferWidth = (UINT)size.x;
		newData.d3dpp.BackBufferHeight = (UINT)size.y;
		HRESULT hr = bd->pd3dDevice->CreateAdditionalSwapChain(&newData.d3dpp, &newData.SwapChain);
		IM_ASSERT(hr == D3D_OK);

		if (hr == D3D_OK)
		{
			vd->SwapChain = std::move(newData.SwapChain);
			vd->d3dpp = newData.d3dpp;
		}
	}
}

static void ImGui_ImplDX9_RenderWindow(ImGuiViewport* viewport, void*)
{
	ImGui_ImplDX9_Data* bd = ImGui_ImplDX9_GetBackendData();
	ImGuiViewportDataDx9* vd = (ImGuiViewportDataDx9*)viewport->RendererUserData;
	ImVec4 clear_color = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);

	wil::com_ptr_nothrow<IDirect3DSurface9> render_target;
	wil::com_ptr_nothrow<IDirect3DSurface9> last_render_target;
	wil::com_ptr_nothrow<IDirect3DSurface9> last_depth_stencil;

	vd->SwapChain->GetBackBuffer(0, D3DBACKBUFFER_TYPE_MONO, &render_target);
	bd->pd3dDevice->GetRenderTarget(0, &last_render_target);
	bd->pd3dDevice->GetDepthStencilSurface(&last_depth_stencil);
	bd->pd3dDevice->SetRenderTarget(0, render_target.get());
	bd->pd3dDevice->SetDepthStencilSurface(nullptr);

	if (!(viewport->Flags & ImGuiViewportFlags_NoRendererClear))
	{
		D3DCOLOR clear_col_dx = D3DCOLOR_RGBA((int)(clear_color.x * 255.0f), (int)(clear_color.y * 255.0f), (int)(clear_color.z * 255.0f), (int)(clear_color.w * 255.0f));
		bd->pd3dDevice->Clear(0, nullptr, D3DCLEAR_TARGET, clear_col_dx, 1.0f, 0);
	}

	ImGui_ImplDX9_RenderDrawData(viewport->DrawData);

	// Restore render target
	bd->pd3dDevice->SetRenderTarget(0, last_render_target.get());
	bd->pd3dDevice->SetDepthStencilSurface(last_depth_stencil.get());
}

static void ImGui_ImplDX9_SwapBuffers(ImGuiViewport* viewport, void*)
{
	ImGuiViewportDataDx9* vd = (ImGuiViewportDataDx9*)viewport->RendererUserData;
	HRESULT hr = vd->SwapChain->Present(nullptr, nullptr, vd->hDeviceWindow, nullptr, 0);

	if (hr != D3D_OK && hr != D3DERR_DEVICELOST)
	{
		SPDLOG_ERROR("Overlay Error: failed to call Present() viewport={} hr={}", viewport->ID, hr);
	}
}

static void ImGui_ImplDX9_InitPlatformInterface()
{
	ImGuiPlatformIO& platform_io = ImGui::GetPlatformIO();
	platform_io.Renderer_CreateWindow = ImGui_ImplDX9_CreateWindow;
	platform_io.Renderer_DestroyWindow = ImGui_ImplDX9_DestroyWindow;
	platform_io.Renderer_SetWindowSize = ImGui_ImplDX9_SetWindowSize;
	platform_io.Renderer_RenderWindow = ImGui_ImplDX9_RenderWindow;
	platform_io.Renderer_SwapBuffers = ImGui_ImplDX9_SwapBuffers;
}

static void ImGui_ImplDX9_ShutdownPlatformInterface()
{
	ImGui::DestroyPlatformWindows();
}

static void ImGui_ImplDX9_CreateDeviceObjectsForPlatformWindows()
{
	ImGuiPlatformIO& platform_io = ImGui::GetPlatformIO();
	for (int i = 1; i < platform_io.Viewports.Size; i++)
	{
		if (!platform_io.Viewports[i]->RendererUserData)
			ImGui_ImplDX9_CreateWindow(platform_io.Viewports[i]);
	}
}

static void ImGui_ImplDX9_InvalidateDeviceObjectsForPlatformWindows()
{
	ImGuiPlatformIO& platform_io = ImGui::GetPlatformIO();
	for (int i = 1; i < platform_io.Viewports.Size; i++)
	{
		if (platform_io.Viewports[i]->RendererUserData)
			ImGui_ImplDX9_DestroyWindow(platform_io.Viewports[i]);
	}
}

#pragma endregion

} // namespace mq
