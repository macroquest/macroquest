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

#include "pch.h"
#include "MQ2Main.h"
#include "MQ2DeveloperTools.h"
#include "CrashHandler.h"

#include "common/HotKeys.h"
#include "imgui/ImGuiUtils.h"

#include <imgui.h>
#include <imgui_stdlib.h>

#include <Shlobj.h>

#ifdef DIRECTINPUT_VERSION
#undef DIRECTINPUT_VERSION
#endif
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <d3d9.h>
#include <cfenv>

#include <spdlog/spdlog.h>
#include <fmt/format.h>
#include <atomic>
#include <vector>

namespace mq {

#pragma region MQ2Overlay Integration Internals

//----------------------------------------------------------------------------
// globals

// The global direct 3d device that we are using. This belongs to EQ, so we
// need to hook into it to understand when states change.
IDirect3DDevice9* gpD3D9Device = nullptr;

// Indicates that we've acquired the device and its usable
bool gbDeviceAcquired = false;

// Indicates that the graphics device hooks are installed
bool gbDeviceHooksInstalled = false;

// Indicates that there has been a request to toggle the console.
bool gbToggleConsoleRequested = false;

// Indicates that we need to reset the overlay next frame
bool gbNeedResetOverlay = false;

// Last known full screen state
bool gbLastFullScreenState = false;

// Number of frames to wait before initializing
int gReInitFrameDelay = 0;

// Critical error occurred and imgui needs to be reset
bool gbManualResetRequired = false;

//----------------------------------------------------------------------------
// statics

static DWORD gResetDeviceAddress = 0;
static POINT gMouseLocation;
static bool gbMouseBlocked = false;
static char ImGuiSettingsFile[MAX_PATH] = { 0 };
static bool gbFlushNextMouse = false;
static bool gbRetryHooks = false;
static bool gbInitializationFailed = false;
static bool gbInitializedImGui = false;
static int gLastGameState = GAMESTATE_PRECHARSELECT;

static mq::PlatformHotkey gToggleConsoleHotkey;
static const char gToggleConsoleDefaultBind[] = "ctrl+`";
static bool gbToggleConsoleHotkeyReady = false;

// Mouse state, pointed to by EQADDR_DIMOUSECOPY
struct MouseStateData
{
	DWORD x;
	DWORD y;
	DWORD Scroll;
	DWORD relX;
	DWORD relY;
	DWORD InWindow;
};
static MouseStateData** gMouseState = (MouseStateData**)&EQADDR_DIMOUSECOPY;
static DIMOUSESTATE** gDIMouseState = (DIMOUSESTATE**)&EQADDR_DIMOUSECHECK;

using D3D9CREATEEXPROC = HRESULT(WINAPI*)(UINT, IDirect3D9Ex**);

static void UpdateGraphicsScene();
static void InvalidateDeviceObjects();
static bool CreateDeviceObjects();
static bool RenderImGui();

// Some of our hooks are determined dynamically. Rather than have a variable
// for each one, we store them in a collection of these HookInfo objects.
struct HookInfo
{
	std::string name;
	DWORD address = 0;

	std::function<void(HookInfo&)> patch = nullptr;
};

// List of installed hooks at their address, if they are already patched in
static std::vector<HookInfo> gHooks;

static void InstallHook(HookInfo hi)
{
	auto iter = std::find_if(std::begin(gHooks), std::end(gHooks),
		[&hi](const HookInfo& hookInfo)
	{
		return hi.name == hookInfo.name;
	});

	if (iter != std::end(gHooks))
	{
#if 0
		// hook already installed. Remove it.
		if (iter->address != 0)
		{
			RemoveDetour(iter->address);
		}

		gHooks.erase(iter);
#else
		// hook already installed. just skip.
		return;
#endif
	}

	hi.patch(hi);
	gHooks.push_back(hi);
}

template <typename T>
static void InstallDetour(DWORD address, const T& detour, const T& trampoline, PCHAR name)
{
	HookInfo hookInfo;
	hookInfo.name = name;
	hookInfo.address = 0;
	hookInfo.patch = [&detour, &trampoline, address](HookInfo& hi)
	{
		hi.address = address;
		AddDetourf(hi.address, detour, trampoline, hi.name.c_str());
	};

	InstallHook(hookInfo);
}

static void RemoveDetours()
{
	for (HookInfo& hook : gHooks)
	{
		if (hook.address != 0)
		{
			RemoveDetour(hook.address);
			hook.address = 0;
		}
	}
}

// Returns true if this event should be "erased" from eq.
static bool HandleMouseEvent(int mouseButton, bool pressed)
{
	ImGuiIO& io = ImGui::GetIO();
	bool consume = false;

	if (test_and_set(io.MouseDown[mouseButton], pressed))
	{
		if (!io.WantCaptureMouse)
		{
			if (DeveloperTools_WindowInspector_HandleClick(mouseButton, pressed))
				consume = true;
		}
	}

	if (consume)
	{
		// Update EQ to act like we already handled this click
		EQADDR_MOUSECLICK->Confirm[mouseButton] = pressed;
		EQADDR_MOUSECLICK->Click[mouseButton] = pressed;
	}

	return consume;
}

static bool IsFullScreen(IDirect3DDevice9* device)
{
	if (!device)
		return false;

	// Detect full screen and disable viewports if we're in full screen mode.
	bool fullscreen = true;
	IDirect3DSwapChain9* pSwapChain = nullptr;
	if (SUCCEEDED(device->GetSwapChain(0, &pSwapChain)) && pSwapChain)
	{
		D3DPRESENT_PARAMETERS params;
		pSwapChain->GetPresentParameters(&params);

		fullscreen = !params.Windowed;

		pSwapChain->Release();
	}

	return fullscreen;
}

#pragma region ImGui Integration

namespace imgui {

//============================================================================
// Custom ImGui renderer for win32 and directx 9, integrated into EverQuest,
// written by Brainiac, based off of example code from github.com/ocornut/imgui

#pragma region ImGui: Renderer for DirectX 9

// Implemented features:
//  [X] Renderer: User texture binding. Use 'LPDIRECT3DTEXTURE9' as ImTextureID. Read the FAQ about ImTextureID!
//  [X] Renderer: Multi-viewport support. Enable with 'io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable'.
//  [X] Renderer: Support for large meshes (64k+ vertices) with 16-bit indices.

// You can copy and use unmodified imgui_impl_* files in your project. See main.cpp for an example of using this.
// If you are new to dear imgui, read examples/README.txt and read the documentation at the top of imgui.cpp.
// https://github.com/ocornut/imgui

// CHANGELOG
// (minor and older changes stripped away, please see git history for details)
//  2020-XX-XX: Platform: Added support for multiple windows via the ImGuiPlatformIO interface.
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


// DirectX data
static LPDIRECT3DDEVICE9        g_pImguiDevice = nullptr;
static LPDIRECT3DVERTEXBUFFER9  g_pVB = nullptr;
static LPDIRECT3DINDEXBUFFER9   g_pIB = nullptr;
static LPDIRECT3DTEXTURE9       g_FontTexture = nullptr;
static int                      g_VertexBufferSize = 5000;
static int                      g_IndexBufferSize = 10000;
static bool                     g_bImGuiReady = false;
static bool                     g_bRenderImGui = true;

struct CUSTOMVERTEX
{
	float    pos[3];
	D3DCOLOR col;
	float    uv[2];
};

constexpr int D3DFVF_CUSTOMVERTEX = (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

// Forward Declarations
static void ImGui_ImplDX9_InitPlatformInterface();
static void ImGui_ImplDX9_ShutdownPlatformInterface();
static void ImGui_ImplDX9_CreateDeviceObjectsForPlatformWindows();
static void ImGui_ImplDX9_InvalidateDeviceObjectsForPlatformWindows();
static void ImGui_ImplDX9_InvalidateDeviceObjects();

static void ImGui_ImplDX9_SetupRenderState(ImDrawData* drawData)
{
	// Setup viewport
	D3DVIEWPORT9 vp;
	vp.X = vp.Y = 0;
	vp.Width = (DWORD)drawData->DisplaySize.x;
	vp.Height = (DWORD)drawData->DisplaySize.y;
	vp.MinZ = 0.0f;
	vp.MaxZ = 1.0f;
	g_pImguiDevice->SetViewport(&vp);

	// Setup render state: fixed-pipeline, alpha-blending, no face culling, no depth testing, shade mode (for gradient)
	g_pImguiDevice->SetPixelShader(nullptr);
	g_pImguiDevice->SetVertexShader(nullptr);
	g_pImguiDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	g_pImguiDevice->SetRenderState(D3DRS_LIGHTING, false);
	g_pImguiDevice->SetRenderState(D3DRS_ZENABLE, false);
	g_pImguiDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pImguiDevice->SetRenderState(D3DRS_ALPHATESTENABLE, false);
	g_pImguiDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	g_pImguiDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pImguiDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	g_pImguiDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, true);
	g_pImguiDevice->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);
	g_pImguiDevice->SetRenderState(D3DRS_FOGENABLE, false);
	g_pImguiDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	g_pImguiDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pImguiDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	g_pImguiDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	g_pImguiDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pImguiDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
	g_pImguiDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	g_pImguiDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);

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
		g_pImguiDevice->SetTransform(D3DTS_WORLD, &mat_identity);
		g_pImguiDevice->SetTransform(D3DTS_VIEW, &mat_identity);
		g_pImguiDevice->SetTransform(D3DTS_PROJECTION, &mat_projection);
	}
}

// Render function.
// (this used to be set in io.RenderDrawListsFn and called by ImGui::Render(), but you can now call this directly from your main loop)
static void ImGui_ImplDX9_RenderDrawData(ImDrawData* drawData)
{
	// Avoid rendering when minimized
	if (drawData->DisplaySize.x <= 0.0f || drawData->DisplaySize.y <= 0.0f)
		return;

	// Create and grow buffers if needed
	if (!g_pVB || g_VertexBufferSize < drawData->TotalVtxCount)
	{
		if (g_pVB)
		{
			g_pVB->Release();
			g_pVB = nullptr;
		}

		g_VertexBufferSize = drawData->TotalVtxCount + 5000;
		if (g_pImguiDevice->CreateVertexBuffer(g_VertexBufferSize * sizeof(CUSTOMVERTEX), D3DUSAGE_DYNAMIC | D3DUSAGE_WRITEONLY, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &g_pVB, nullptr) < 0)
			return;
	}

	if (!g_pIB || g_IndexBufferSize < drawData->TotalIdxCount)
	{
		if (g_pIB)
		{
			g_pIB->Release();
			g_pIB = nullptr;
		}

		g_IndexBufferSize = drawData->TotalIdxCount + 10000;
		if (g_pImguiDevice->CreateIndexBuffer(g_IndexBufferSize * sizeof(ImDrawIdx), D3DUSAGE_DYNAMIC | D3DUSAGE_WRITEONLY, sizeof(ImDrawIdx) == 2 ? D3DFMT_INDEX16 : D3DFMT_INDEX32, D3DPOOL_DEFAULT, &g_pIB, nullptr) < 0)
			return;
	}

	// Backup the DX9 state
	IDirect3DStateBlock9* d3d9StateBlock = nullptr;
	if (g_pImguiDevice->CreateStateBlock(D3DSBT_ALL, &d3d9StateBlock) < 0)
		return;

	// Backup the DX9 transform (DX9 documentation suggests that it is included in the StateBlock but it doesn't appear to)
	D3DMATRIX lastWorld, lastView, lastProjection;
	g_pImguiDevice->GetTransform(D3DTS_WORLD, &lastWorld);
	g_pImguiDevice->GetTransform(D3DTS_VIEW, &lastView);
	g_pImguiDevice->GetTransform(D3DTS_PROJECTION, &lastProjection);

	// Copy and convert all vertices into a single contiguous buffer, convert colors to DX9 default format.
	// FIXME-OPT: This is a waste of resource, the ideal is to use imconfig.h and
	//  1) to avoid repacking colors:   #define IMGUI_USE_BGRA_PACKED_COLOR
	//  2) to avoid repacking vertices: #define IMGUI_OVERRIDE_DRAWVERT_STRUCT_LAYOUT struct ImDrawVert { ImVec2 pos; float z; ImU32 col; ImVec2 uv; }
	CUSTOMVERTEX* vtxDst;
	ImDrawIdx* idxDst;
	if (g_pVB->Lock(0, (UINT)(drawData->TotalVtxCount * sizeof(CUSTOMVERTEX)), (void**)&vtxDst, D3DLOCK_DISCARD) < 0)
		return;
	if (g_pIB->Lock(0, (UINT)(drawData->TotalIdxCount * sizeof(ImDrawIdx)), (void**)&idxDst, D3DLOCK_DISCARD) < 0)
		return;

	for (int n = 0; n < drawData->CmdListsCount; n++)
	{
		const ImDrawList* cmdList = drawData->CmdLists[n];
		const ImDrawVert* vtxSrc = cmdList->VtxBuffer.Data;

		for (int i = 0; i < cmdList->VtxBuffer.Size; i++)
		{
			vtxDst->pos[0] = vtxSrc->pos.x;
			vtxDst->pos[1] = vtxSrc->pos.y;
			vtxDst->pos[2] = 0.0f;
			vtxDst->col = (vtxSrc->col & 0xFF00FF00) | ((vtxSrc->col & 0xFF0000) >> 16) | ((vtxSrc->col & 0xFF) << 16);     // RGBA --> ARGB for DirectX9
			vtxDst->uv[0] = vtxSrc->uv.x;
			vtxDst->uv[1] = vtxSrc->uv.y;
			vtxDst++;
			vtxSrc++;
		}

		memcpy(idxDst, cmdList->IdxBuffer.Data, cmdList->IdxBuffer.Size * sizeof(ImDrawIdx));
		idxDst += cmdList->IdxBuffer.Size;
	}

	g_pVB->Unlock();
	g_pIB->Unlock();
	g_pImguiDevice->SetStreamSource(0, g_pVB, 0, sizeof(CUSTOMVERTEX));
	g_pImguiDevice->SetIndices(g_pIB);
	g_pImguiDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

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
				const RECT r = { (LONG)(pCmd->ClipRect.x - clipOff.x), (LONG)(pCmd->ClipRect.y - clipOff.y), (LONG)(pCmd->ClipRect.z - clipOff.x), (LONG)(pCmd->ClipRect.w - clipOff.y) };
				const LPDIRECT3DTEXTURE9 texture = (LPDIRECT3DTEXTURE9)pCmd->TextureId;

				g_pImguiDevice->SetTexture(0, texture);
				g_pImguiDevice->SetScissorRect(&r);
				g_pImguiDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, pCmd->VtxOffset + globalVtxOffset, 0, (UINT)cmdList->VtxBuffer.Size, pCmd->IdxOffset + globalIdxOffset, pCmd->ElemCount / 3);
			}
		}

		globalIdxOffset += cmdList->IdxBuffer.Size;
		globalVtxOffset += cmdList->VtxBuffer.Size;
	}

	// Restore the DX9 transform
	g_pImguiDevice->SetTransform(D3DTS_WORLD, &lastWorld);
	g_pImguiDevice->SetTransform(D3DTS_VIEW, &lastView);
	g_pImguiDevice->SetTransform(D3DTS_PROJECTION, &lastProjection);

	// Restore the DX9 state
	d3d9StateBlock->Apply();
	d3d9StateBlock->Release();
}

static bool ImGui_ImplDX9_Init(IDirect3DDevice9* device)
{
	// Setup back-end capabilities flags
	ImGuiIO& io = ImGui::GetIO();
	io.BackendRendererName = "imgui_impl_dx9";
	io.BackendFlags |= ImGuiBackendFlags_RendererHasVtxOffset;  // We can honor the ImDrawCmd::VtxOffset field, allowing for large meshes.
	io.BackendFlags |= ImGuiBackendFlags_RendererHasViewports;  // We can create multi-viewports on the Renderer side (optional)

	g_pImguiDevice = device;
	g_pImguiDevice->AddRef();

	ImGui_ImplDX9_InitPlatformInterface();

	io.ConfigDockingWithShift = true;

	return true;
}

static void ImGui_ImplDX9_Shutdown()
{
	if (!ImGui::GetCurrentContext())
		return;

	ImGui_ImplDX9_ShutdownPlatformInterface();
	ImGui_ImplDX9_InvalidateDeviceObjects();

	if (g_pImguiDevice)
	{
		g_pImguiDevice->Release();
		g_pImguiDevice = nullptr;
	}
}

static bool ImGui_ImplDX9_CreateFontsTexture()
{
	// Build texture atlas
	ImGuiIO& io = ImGui::GetIO();
	unsigned char* pixels;
	int width, height, bytes_per_pixel;
	io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height, &bytes_per_pixel);

	// Upload texture to graphics system
	g_FontTexture = nullptr;
	HRESULT hr = g_pImguiDevice->CreateTexture(width, height, 1, D3DUSAGE_DYNAMIC, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &g_FontTexture, nullptr);
	if (FAILED(hr))
	{
		return false;
	}

	D3DLOCKED_RECT tex_locked_rect;
	if (g_FontTexture->LockRect(0, &tex_locked_rect, nullptr, 0) != D3D_OK)
		return false;

	for (int y = 0; y < height; y++)
		memcpy((unsigned char*)tex_locked_rect.pBits + tex_locked_rect.Pitch * y, pixels + (width * bytes_per_pixel) * y, (width * bytes_per_pixel));

	g_FontTexture->UnlockRect(0);

	// Store our identifier
	io.Fonts->TexID = (ImTextureID)g_FontTexture;

	return true;
}

static bool ImGui_ImplDX9_CreateDeviceObjects()
{
	if (!g_pImguiDevice)
		return false;
	if (!ImGui_ImplDX9_CreateFontsTexture())
		return false;

	ImGui_ImplDX9_CreateDeviceObjectsForPlatformWindows();
	return true;
}

static void ImGui_ImplDX9_InvalidateDeviceObjects()
{
	if (!g_pImguiDevice)
		return;

	if (g_pVB)
	{
		g_pVB->Release();
		g_pVB = nullptr;
	}

	if (g_pIB)
	{
		g_pIB->Release();
		g_pIB = nullptr;
	}

	if (g_FontTexture)
	{
		g_FontTexture->Release();
		g_FontTexture = nullptr;

		// We copied g_pFontTextureView to io.Fonts->TexID so let's clear that as well.
		ImGui::GetIO().Fonts->TexID = nullptr;
	}

	ImGui_ImplDX9_InvalidateDeviceObjectsForPlatformWindows();
}

static void ImGui_ImplDX9_NewFrame()
{
	if (!g_FontTexture)
		ImGui_ImplDX9_CreateDeviceObjects();
}

#pragma region Multi-Viewport Support

//--------------------------------------------------------------------------------------------------------
// MULTI-VIEWPORT / PLATFORM INTERFACE SUPPORT
// This is an _advanced_ and _optional_ feature, allowing the back-end to create and handle multiple viewports simultaneously.
// If you are new to dear imgui or creating a new binding for dear imgui, it is recommended that you completely ignore this section first..
//--------------------------------------------------------------------------------------------------------

struct ImGuiViewportDataDx9
{
	IDirect3DSwapChain9*    SwapChain;
	D3DPRESENT_PARAMETERS   d3dpp;

	ImGuiViewportDataDx9() { SwapChain = nullptr; ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS)); }
	~ImGuiViewportDataDx9() { IM_ASSERT(SwapChain == nullptr); }
};

static void ImGui_ImplDX9_CreateWindow(ImGuiViewport* viewport)
{
	ImGuiViewportDataDx9* data = IM_NEW(ImGuiViewportDataDx9)();
	viewport->RendererUserData = data;

	// PlatformHandleRaw should always be a HWND, whereas PlatformHandle might be a higher-level handle (e.g. GLFWWindow*, SDL_Window*).
	// Some back-ends will leave PlatformHandleRaw NULL, in which case we assume PlatformHandle will contain the HWND.
	HWND hwnd = viewport->PlatformHandleRaw ? (HWND)viewport->PlatformHandleRaw : (HWND)viewport->PlatformHandle;
	IM_ASSERT(hwnd != nullptr);

	ZeroMemory(&data->d3dpp, sizeof(D3DPRESENT_PARAMETERS));
	data->d3dpp.Windowed = TRUE;
	data->d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	data->d3dpp.BackBufferWidth = (UINT)viewport->Size.x;
	data->d3dpp.BackBufferHeight = (UINT)viewport->Size.y;
	data->d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	data->d3dpp.hDeviceWindow = hwnd;
	data->d3dpp.EnableAutoDepthStencil = FALSE;
	data->d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	data->d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;   // Present without vsync

	HRESULT hr = g_pImguiDevice->CreateAdditionalSwapChain(&data->d3dpp, &data->SwapChain); IM_UNUSED(hr);
	IM_ASSERT(hr == D3D_OK);
	IM_ASSERT(data->SwapChain != nullptr);
}

static void ImGui_ImplDX9_DestroyWindow(ImGuiViewport* viewport)
{
	// The main viewport (owned by the application) will always have RendererUserData == NULL since we didn't create the data for it.
	if (ImGuiViewportDataDx9* data = (ImGuiViewportDataDx9*)viewport->RendererUserData)
	{
		if (data->SwapChain)
			data->SwapChain->Release();

		data->SwapChain = nullptr;
		ZeroMemory(&data->d3dpp, sizeof(D3DPRESENT_PARAMETERS));
		IM_DELETE(data);
	}

	viewport->RendererUserData = nullptr;
}

static void ImGui_ImplDX9_SetWindowSize(ImGuiViewport* viewport, ImVec2 size)
{
	ImGuiViewportDataDx9* data = (ImGuiViewportDataDx9*)viewport->RendererUserData;
	if (data->SwapChain)
	{
		ImGuiViewportDataDx9 newData;
		newData.SwapChain = nullptr;
		newData.d3dpp = data->d3dpp;
		newData.d3dpp.BackBufferWidth = (UINT)size.x;
		newData.d3dpp.BackBufferHeight = (UINT)size.y;
		HRESULT hr = g_pImguiDevice->CreateAdditionalSwapChain(&newData.d3dpp, &newData.SwapChain);
		IM_ASSERT(hr == D3D_OK);

		if (hr == D3D_OK)
		{
			data->SwapChain->Release();
			data->SwapChain = std::exchange(newData.SwapChain, nullptr);
			data->d3dpp = newData.d3dpp;
			return;
		}
	}
}

static void ImGui_ImplDX9_RenderWindow(ImGuiViewport* viewport, void*)
{
	ImGuiViewportDataDx9* data = (ImGuiViewportDataDx9*)viewport->RendererUserData;
	ImVec4 clear_color = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);

	LPDIRECT3DSURFACE9 render_target = nullptr;
	LPDIRECT3DSURFACE9 last_render_target = nullptr;
	LPDIRECT3DSURFACE9 last_depth_stencil = nullptr;
	data->SwapChain->GetBackBuffer(0, D3DBACKBUFFER_TYPE_MONO, &render_target);
	g_pImguiDevice->GetRenderTarget(0, &last_render_target);
	g_pImguiDevice->GetDepthStencilSurface(&last_depth_stencil);
	g_pImguiDevice->SetRenderTarget(0, render_target);
	g_pImguiDevice->SetDepthStencilSurface(nullptr);

	if (!(viewport->Flags & ImGuiViewportFlags_NoRendererClear))
	{
		D3DCOLOR clear_col_dx = D3DCOLOR_RGBA((int)(clear_color.x * 255.0f), (int)(clear_color.y * 255.0f), (int)(clear_color.z * 255.0f), (int)(clear_color.w * 255.0f));
		g_pImguiDevice->Clear(0, nullptr, D3DCLEAR_TARGET, clear_col_dx, 1.0f, 0);
	}

	ImGui_ImplDX9_RenderDrawData(viewport->DrawData);

	// Restore render target
	g_pImguiDevice->SetRenderTarget(0, last_render_target);
	g_pImguiDevice->SetDepthStencilSurface(last_depth_stencil);
	render_target->Release();
	last_render_target->Release();
	if (last_depth_stencil) last_depth_stencil->Release();
}

static void ImGui_ImplDX9_SwapBuffers(ImGuiViewport* viewport, void*)
{
	ImGuiViewportDataDx9* data = (ImGuiViewportDataDx9*)viewport->RendererUserData;
	HRESULT hr = data->SwapChain->Present(nullptr, nullptr, data->d3dpp.hDeviceWindow, nullptr, 0);
	if (hr != D3D_OK)
	{
		if (::IsDebuggerPresent())
			__debugbreak();

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
#pragma endregion

#pragma region ImGui: Platform Binding for Windows

// Implemented features:
//  [X] Platform: Clipboard support (for Win32 this is actually part of core imgui)
//  [X] Platform: Mouse cursor shape and visibility. Disable with 'io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange'.
//  [X] Platform: Keyboard arrays indexed using VK_* Virtual Key Codes, e.g. ImGui::IsKeyPressed(VK_SPACE).
//  [X] Platform: Gamepad support. Enabled with 'io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad'.
//  [X] Platform: Multi-viewport support (multiple windows). Enable with 'io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable'.

// CHANGELOG
// (minor and older changes stripped away, please see git history for details)
//  2020-XX-XX: Platform: Added support for multiple windows via the ImGuiPlatformIO interface.
//  2019-12-05: Inputs: Added support for ImGuiMouseCursor_NotAllowed mouse cursor.
//  2019-05-11: Inputs: Don't filter value from WM_CHAR before calling AddInputCharacter().
//  2019-01-17: Misc: Using GetForegroundWindow()+IsChild() instead of GetActiveWindow() to be compatible with windows created in a different thread or parent.
//  2019-01-17: Inputs: Added support for mouse buttons 4 and 5 via WM_XBUTTON* messages.
//  2019-01-15: Inputs: Added support for XInput gamepads (if ImGuiConfigFlags_NavEnableGamepad is set by user application).
//  2018-11-30: Misc: Setting up io.BackendPlatformName so it can be displayed in the About Window.
//  2018-06-29: Inputs: Added support for the ImGuiMouseCursor_Hand cursor.
//  2018-06-10: Inputs: Fixed handling of mouse wheel messages to support fine position messages (typically sent by track-pads).
//  2018-06-08: Misc: Extracted imgui_impl_win32.cpp/.h away from the old combined DX9/DX10/DX11/DX12 examples.
//  2018-03-20: Misc: Setup io.BackendFlags ImGuiBackendFlags_HasMouseCursors and ImGuiBackendFlags_HasSetMousePos flags + honor ImGuiConfigFlags_NoMouseCursorChange flag.
//  2018-02-20: Inputs: Added support for mouse cursors (ImGui::GetMouseCursor() value and WM_SETCURSOR message handling).
//  2018-02-06: Inputs: Added mapping for ImGuiKey_Space.
//  2018-02-06: Inputs: Honoring the io.WantSetMousePos by repositioning the mouse (when using navigation and ImGuiConfigFlags_NavMoveMouse is set).
//  2018-02-06: Misc: Removed call to ImGui::Shutdown() which is not available from 1.60 WIP, user needs to call CreateContext/DestroyContext themselves.
//  2018-01-20: Inputs: Added Horizontal Mouse Wheel support.
//  2018-01-08: Inputs: Added mapping for ImGuiKey_Insert.
//  2018-01-05: Inputs: Added WM_LBUTTONDBLCLK double-click handlers for window classes with the CS_DBLCLKS flag.
//  2017-10-23: Inputs: Added WM_SYSKEYDOWN / WM_SYSKEYUP handlers so e.g. the VK_MENU key can be read.
//  2017-10-23: Inputs: Using Win32 ::SetCapture/::GetCapture() to retrieve mouse positions outside the client area when dragging.
//  2016-11-12: Inputs: Only call Win32 ::SetCursor(NULL) when io.MouseDrawCursor is set.

// Win32 Data
static HWND                     g_hWnd = nullptr;
static int64_t                  g_Time = 0;
static int64_t                  g_TicksPerSecond = 0;
static ImGuiMouseCursor         g_LastMouseCursor = ImGuiMouseCursor_COUNT;
static bool                     g_WantUpdateMonitors = true;

//============================================================================

static void ImGui_ImplWin32_InitPlatformInterface();
static void ImGui_ImplWin32_ShutdownPlatformInterface();
static void ImGui_ImplWin32_UpdateMonitors();

static bool ImGui_ImplWin32_Init(HWND hWnd)
{
	if (!::QueryPerformanceFrequency((LARGE_INTEGER*)&g_TicksPerSecond))
		return false;
	if (!::QueryPerformanceCounter((LARGE_INTEGER*)&g_Time))
		return false;

	// Setup backend-end capabilities flags
	ImGuiIO& io = ImGui::GetIO();
	io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;         // We can honor GetMouseCursor() values (optional)
	io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;          // We can honor io.WantSetMousePos requests (optional, rarely used)
	io.BackendFlags |= ImGuiBackendFlags_HasMouseHoveredViewport; // We can set io.MouseHoveredViewport correctly (optional, not easy).
	io.BackendFlags |= ImGuiBackendFlags_PlatformHasViewports;    // We can create multi-viewports on the Platform side (optional)
	io.BackendPlatformName = "imgui_impl_win32";

	// Our mouse update function expects PlatformHandle to be filled for the main viewport
	g_hWnd = (HWND)hWnd;
	ImGuiViewport* mainViewport = ImGui::GetMainViewport();
	mainViewport->PlatformHandle = mainViewport->PlatformHandleRaw = (void*)g_hWnd;
	ImGui_ImplWin32_InitPlatformInterface();

	// Keyboard mapping. ImGui will use those indices to peek into the io.KeysDown[] array that we will update during the application lifetime.
	io.KeyMap[ImGuiKey_Tab] = VK_TAB;
	io.KeyMap[ImGuiKey_LeftArrow] = VK_LEFT;
	io.KeyMap[ImGuiKey_RightArrow] = VK_RIGHT;
	io.KeyMap[ImGuiKey_UpArrow] = VK_UP;
	io.KeyMap[ImGuiKey_DownArrow] = VK_DOWN;
	io.KeyMap[ImGuiKey_PageUp] = VK_PRIOR;
	io.KeyMap[ImGuiKey_PageDown] = VK_NEXT;
	io.KeyMap[ImGuiKey_Home] = VK_HOME;
	io.KeyMap[ImGuiKey_End] = VK_END;
	io.KeyMap[ImGuiKey_Insert] = VK_INSERT;
	io.KeyMap[ImGuiKey_Delete] = VK_DELETE;
	io.KeyMap[ImGuiKey_Backspace] = VK_BACK;
	io.KeyMap[ImGuiKey_Space] = VK_SPACE;
	io.KeyMap[ImGuiKey_Enter] = VK_RETURN;
	io.KeyMap[ImGuiKey_Escape] = VK_ESCAPE;
	io.KeyMap[ImGuiKey_KeyPadEnter] = VK_RETURN;
	io.KeyMap[ImGuiKey_A] = 'A';
	io.KeyMap[ImGuiKey_C] = 'C';
	io.KeyMap[ImGuiKey_V] = 'V';
	io.KeyMap[ImGuiKey_X] = 'X';
	io.KeyMap[ImGuiKey_Y] = 'Y';
	io.KeyMap[ImGuiKey_Z] = 'Z';

	return true;
}

static void ImGui_ImplWin32_Shutdown()
{
	ImGui_ImplWin32_ShutdownPlatformInterface();
	g_hWnd = nullptr;
}

static bool ImGui_ImplWin32_UpdateMouseCursor()
{
	ImGuiIO& io = ImGui::GetIO();
	if (io.ConfigFlags & ImGuiConfigFlags_NoMouseCursorChange)
		return false;

	if (!io.WantCaptureMouse)
		return false;

	bool useWin32Cursor = false;

	ImGuiMouseCursor imguiCursor = ImGui::GetMouseCursor();
	if (imguiCursor == ImGuiMouseCursor_None || io.MouseDrawCursor)
	{
		// Hide OS mouse cursor if imgui is drawing it or if it wants no cursor
		::SetCursor(nullptr);
	}
	else if (pWndMgr)
	{
		const CursorClass* cc = pWndMgr->GetCursorClass();

		// Show OS mouse cursor
		CursorClass::eCursorTypes cursorType = CursorClass::eArrow;
		bool useWin32Cursor = false;

		switch (imguiCursor)
		{
		case ImGuiMouseCursor_ResizeEW:
			cursorType = CursorClass::eEastWest;
			break;
		case ImGuiMouseCursor_ResizeNS:
			cursorType = CursorClass::eNorthSouth;
			break;
		case ImGuiMouseCursor_ResizeNESW:
			cursorType = CursorClass::eNorthEastSouthWest;
			break;
		case ImGuiMouseCursor_ResizeNWSE:
			cursorType = CursorClass::eNorthWestSouthEast;
			break;
		case ImGuiMouseCursor_TextInput:
			cursorType = CursorClass::eBeam;
			break;
		case ImGuiMouseCursor_Arrow:
			break;
		case ImGuiMouseCursor_ResizeAll:
			cursorType = CursorClass::eMove;
			break;

		case ImGuiMouseCursor_Hand:
		default:
			useWin32Cursor = true;
			break;
		}

		if (!useWin32Cursor)
		{
			::SetCursor(cc->CursorList[cursorType]);
		}
	}
	else
	{
		useWin32Cursor = true;
	}

	if (useWin32Cursor)
	{
		LPTSTR cursor = IDC_ARROW;
		switch (imguiCursor)
		{
		case ImGuiMouseCursor_Arrow:      cursor = IDC_ARROW; break;
		case ImGuiMouseCursor_TextInput:  cursor = IDC_IBEAM; break;
		case ImGuiMouseCursor_ResizeAll:  cursor = IDC_SIZEALL; break;
		case ImGuiMouseCursor_ResizeEW:   cursor = IDC_SIZEWE; break;
		case ImGuiMouseCursor_ResizeNS:   cursor = IDC_SIZENS; break;
		case ImGuiMouseCursor_ResizeNESW: cursor = IDC_SIZENESW; break;
		case ImGuiMouseCursor_ResizeNWSE: cursor = IDC_SIZENWSE; break;
		case ImGuiMouseCursor_Hand:       cursor = IDC_HAND; break;
		default: break;
		}

		::SetCursor(::LoadCursor(nullptr, cursor));
	}

	return true;
}

// This code supports multi-viewports (multiple OS Windows mapped into different Dear ImGui viewports)
// Because of that, it is a little more complicated than your typical single-viewport binding code!
static void ImGui_ImplWin32_UpdateMousePos()
{
	ImGuiIO& io = ImGui::GetIO();

	// Set OS mouse position if requested (rarely used, only when ImGuiConfigFlags_NavEnableSetMousePos is enabled by user)
	// (When multi-viewports are enabled, all imgui positions are same as OS positions)
	if (io.WantSetMousePos)
	{
		POINT pos = { (int)io.MousePos.x, (int)io.MousePos.y };
		if ((io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) == 0)
			::ClientToScreen(g_hWnd, &pos);
		::SetCursorPos(pos.x, pos.y);
	}

	io.MousePos = ImVec2(-FLT_MAX, -FLT_MAX);
	io.MouseHoveredViewport = 0;

	// Set imgui mouse position
	POINT mouseScreenPos;
	if (!::GetCursorPos(&mouseScreenPos))
		return;

	if (HWND focused_hwnd = ::GetForegroundWindow())
	{
		if (::IsChild(focused_hwnd, g_hWnd))
			focused_hwnd = g_hWnd;
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			// Multi-viewport mode: mouse position is OS absolute coordinates (io.MousePos is (0,0) when mouse is on the upper-left of the primary monitor)
			// This is the position you can get with GetCursorPos(). In theory adding viewport->Pos is also the reverse operation of doing ScreenToClient().
			if (ImGui::FindViewportByPlatformHandle((void*)focused_hwnd) != nullptr)
				io.MousePos = ImVec2((float)mouseScreenPos.x, (float)mouseScreenPos.y);
		}
		else
		{
			// Single viewport mode: mouse position in client window coordinates (io.MousePos is (0,0) when the mouse is on the upper-left corner of the app window.)
			// This is the position you can get with GetCursorPos() + ScreenToClient() or from WM_MOUSEMOVE.
			if (focused_hwnd == g_hWnd)
			{
				POINT mouse_client_pos = mouseScreenPos;
				::ScreenToClient(focused_hwnd, &mouse_client_pos);
				io.MousePos = ImVec2((float)mouse_client_pos.x, (float)mouse_client_pos.y);
			}
		}
	}

	// (Optional) When using multiple viewports: set io.MouseHoveredViewport to the viewport the OS mouse cursor is hovering.
	// Important: this information is not easy to provide and many high-level windowing library won't be able to provide it correctly, because
	// - This is _ignoring_ viewports with the ImGuiViewportFlags_NoInputs flag (pass-through windows).
	// - This is _regardless_ of whether another viewport is focsued or being dragged from.
	// If ImGuiBackendFlags_HasMouseHoveredViewport is not set by the back-end, imgui will ignore this field and infer the information by relying on the
	// rectangles and last focused time of every viewports it knows about. It will be unaware of foreign windows that may be sitting between or over your windows.
	if (HWND hovered_hwnd = ::WindowFromPoint(mouseScreenPos))
	{
		if (ImGuiViewport* viewport = ImGui::FindViewportByPlatformHandle((void*)hovered_hwnd))
		{
			if ((viewport->Flags & ImGuiViewportFlags_NoInputs) == 0) // FIXME: We still get our NoInputs window with WM_NCHITTEST/HTTRANSPARENT code when decorated?
				io.MouseHoveredViewport = viewport->ID;
		}
	}
}

void ImGui_ImplWin32_NewFrame()
{
	ImGuiIO& io = ImGui::GetIO();
	IM_ASSERT(io.Fonts->IsBuilt() && "Font atlas not built! It is generally built by the renderer back-end. Missing call to renderer _NewFrame() function? e.g. ImGui_ImplOpenGL3_NewFrame().");

	// Setup display size (every frame to accommodate for window resizing)
	RECT rect;
	::GetClientRect(g_hWnd, &rect);
	io.DisplaySize = ImVec2((float)(rect.right - rect.left), (float)(rect.bottom - rect.top));
	if (g_WantUpdateMonitors)
		ImGui_ImplWin32_UpdateMonitors();

	// Setup time step
	INT64 currentTime;
	::QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
	io.DeltaTime = (float)(currentTime - g_Time) / g_TicksPerSecond;
	g_Time = currentTime;

	// Read keyboard modifiers inputs
	io.KeyCtrl = (::GetKeyState(VK_CONTROL) & 0x8000) != 0;
	io.KeyShift = (::GetKeyState(VK_SHIFT) & 0x8000) != 0;
	io.KeyAlt = (::GetKeyState(VK_MENU) & 0x8000) != 0;
	io.KeySuper = false;
	// io.KeysDown[], io.MousePos, io.MouseDown[], io.MouseWheel: filled by the WndProc handler below.

	// Update OS mouse position
	ImGui_ImplWin32_UpdateMousePos();

	// Update OS mouse cursor with the cursor requested by imgui
	ImGuiMouseCursor mouseCursor = io.MouseDrawCursor ? ImGuiMouseCursor_None : ImGui::GetMouseCursor();
	if (g_LastMouseCursor != mouseCursor)
	{
		g_LastMouseCursor = mouseCursor;
		ImGui_ImplWin32_UpdateMouseCursor();
	}
}

// Process Win32 mouse/keyboard inputs.
// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
// PS: In this Win32 handler, we use the capture API (GetCapture/SetCapture/ReleaseCapture) to be able to read mouse coordinates when dragging mouse outside of our window bounds.
// PS: We treat DBLCLK messages as regular mouse down messages, so this code will work on windows classes that have the CS_DBLCLKS flag set. Our own example app code doesn't set this flag.
LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui::GetCurrentContext() == nullptr)
		return 0;

	ImGuiIO& io = ImGui::GetIO();

	switch (msg)
	{
	case WM_ACTIVATE:
		// Clear any delayed mouse inputs.
		for (size_t i = 0; i < lengthof(io.MouseDown); ++i)
			HandleMouseEvent(i, false);
		// Clear any delayed keyboard inputs
		for (bool& n : io.KeysDown)
			n = false;
		break;

	case WM_LBUTTONDOWN: case WM_LBUTTONDBLCLK:
	case WM_RBUTTONDOWN: case WM_RBUTTONDBLCLK:
	case WM_MBUTTONDOWN: case WM_MBUTTONDBLCLK:
	case WM_XBUTTONDOWN: case WM_XBUTTONDBLCLK:
	{
		int button = 0;
		if (msg == WM_LBUTTONDOWN || msg == WM_LBUTTONDBLCLK) { button = 0; }
		if (msg == WM_RBUTTONDOWN || msg == WM_RBUTTONDBLCLK) { button = 1; }
		if (msg == WM_MBUTTONDOWN || msg == WM_MBUTTONDBLCLK) { button = 2; }
		if (msg == WM_XBUTTONDOWN || msg == WM_XBUTTONDBLCLK) { button = (GET_XBUTTON_WPARAM(wParam) == XBUTTON1) ? 3 : 4; }
		if (!ImGui::IsAnyMouseDown() && ::GetCapture() == nullptr)
			::SetCapture(hWnd);
		if (HandleMouseEvent(button, true))
			return 1;

		return io.WantCaptureMouse ? 1 : 0;
	}
	case WM_LBUTTONUP:
	case WM_RBUTTONUP:
	case WM_MBUTTONUP:
	case WM_XBUTTONUP:
	{
		int button = 0;
		if (msg == WM_LBUTTONUP) { button = 0; }
		if (msg == WM_RBUTTONUP) { button = 1; }
		if (msg == WM_MBUTTONUP) { button = 2; }
		if (msg == WM_XBUTTONUP) { button = (GET_XBUTTON_WPARAM(wParam) == XBUTTON1) ? 3 : 4; }
		bool capture = HandleMouseEvent(button, false);

		if (!ImGui::IsAnyMouseDown() && ::GetCapture() == hWnd)
			::ReleaseCapture();

		return (capture || io.WantCaptureMouse) ? 1 : 0;
	}
	case WM_MOUSEWHEEL:
		io.MouseWheel += (float)GET_WHEEL_DELTA_WPARAM(wParam) / (float)WHEEL_DELTA;
		return io.WantCaptureMouse ? 1 : 0;

	case WM_MOUSEHWHEEL:
		io.MouseWheelH += (float)GET_WHEEL_DELTA_WPARAM(wParam) / (float)WHEEL_DELTA;
		return io.WantCaptureMouse ? 1 : 0;
	}

	switch (msg)
	{
	case WM_KEYDOWN:
		// We need to send an AddInputCharacter because WM_CHAR does not get sent by EQ.
		BYTE keyState[256];

		if (GetKeyboardState(keyState) == 1)
		{
			uint16_t character = 0;

			if (ToAscii(wParam, (lParam & 0x1ff0000) > 16, keyState, &character, 0) == 1)
			{
				io.AddInputCharacter(character);
			}
		}
		// fallthrough
	case WM_SYSKEYDOWN:
		if (wParam < 256)
			io.KeysDown[wParam] = true;
		return 0;

	case WM_KEYUP:
	case WM_SYSKEYUP:
		if (wParam < 256)
			io.KeysDown[wParam] = false;
		return 0;

	case WM_SETCURSOR:
		if (LOWORD(lParam) == HTCLIENT && ImGui_ImplWin32_UpdateMouseCursor())
			return 1;
		return 0;
	case WM_DISPLAYCHANGE:
		g_WantUpdateMonitors = true;
		return 0;
	}

	return 0;
}

//--------------------------------------------------------------------------------------------------------
// DPI handling
// Those in theory should be simple calls but Windows has multiple ways to handle DPI, and most of them
// require recent Windows versions at runtime or recent Windows SDK at compile-time. Neither we want to depend on.
// So we dynamically select and load those functions to avoid dependencies. This is the scheme successfully
// used by GLFW (from which we borrowed some of the code here) and other applications aiming to be portable.
//---------------------------------------------------------------------------------------------------------
// At this point ImGui_ImplWin32_EnableDpiAwareness() is just a helper called by main.cpp, we don't call it automatically.
//---------------------------------------------------------------------------------------------------------

static bool IsWindowsVersionOrGreater(WORD major, WORD minor, WORD sp)
{
	OSVERSIONINFOEXW osvi = { sizeof(osvi), major, minor, 0, 0,{ 0 }, sp };
	DWORD mask = VER_MAJORVERSION | VER_MINORVERSION | VER_SERVICEPACKMAJOR;
	ULONGLONG cond = VerSetConditionMask(0, VER_MAJORVERSION, VER_GREATER_EQUAL);
	cond = VerSetConditionMask(cond, VER_MINORVERSION, VER_GREATER_EQUAL);
	cond = VerSetConditionMask(cond, VER_SERVICEPACKMAJOR, VER_GREATER_EQUAL);
	return VerifyVersionInfoW(&osvi, mask, cond);
}
#define IsWindows8Point1OrGreater()  IsWindowsVersionOrGreater(HIBYTE(0x0602), LOBYTE(0x0602), 0) // _WIN32_WINNT_WINBLUE
#define IsWindows10OrGreater()       IsWindowsVersionOrGreater(HIBYTE(0x0A00), LOBYTE(0x0A00), 0) // _WIN32_WINNT_WIN10

#ifndef DPI_ENUMS_DECLARED
typedef enum { PROCESS_DPI_UNAWARE = 0, PROCESS_SYSTEM_DPI_AWARE = 1, PROCESS_PER_MONITOR_DPI_AWARE = 2 } PROCESS_DPI_AWARENESS;
typedef enum { MDT_EFFECTIVE_DPI = 0, MDT_ANGULAR_DPI = 1, MDT_RAW_DPI = 2, MDT_DEFAULT = MDT_EFFECTIVE_DPI } MONITOR_DPI_TYPE;
#endif
#ifndef _DPI_AWARENESS_CONTEXTS_
DECLARE_HANDLE(DPI_AWARENESS_CONTEXT);
#define DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE    (DPI_AWARENESS_CONTEXT)-3
#endif
#ifndef DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2
#define DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2 (DPI_AWARENESS_CONTEXT)-4
#endif
typedef HRESULT(WINAPI* PFN_SetProcessDpiAwareness)(PROCESS_DPI_AWARENESS);                     // Shcore.lib+dll, Windows 8.1
typedef HRESULT(WINAPI* PFN_GetDpiForMonitor)(HMONITOR, MONITOR_DPI_TYPE, UINT*, UINT*);        // Shcore.lib+dll, Windows 8.1
typedef DPI_AWARENESS_CONTEXT(WINAPI* PFN_SetThreadDpiAwarenessContext)(DPI_AWARENESS_CONTEXT); // User32.lib+dll, Windows 10 v1607 (Creators Update)

void ImGui_ImplWin32_EnableDpiAwareness()
{
	// if (IsWindows10OrGreater()) // FIXME-DPI: This needs a manifest to succeed. Instead we try to grab the function pointer.
	{
		static HINSTANCE user32_dll = ::LoadLibraryA("user32.dll"); // Reference counted per-process
		static PFN_SetThreadDpiAwarenessContext SetThreadDpiAwarenessContextFn = (PFN_SetThreadDpiAwarenessContext)::GetProcAddress(user32_dll, "SetThreadDpiAwarenessContext");
		if (SetThreadDpiAwarenessContextFn)
		{
			SetThreadDpiAwarenessContextFn(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
			return;
		}
	}

	if (IsWindows8Point1OrGreater())
	{
		static HINSTANCE shcore_dll = ::LoadLibraryA("shcore.dll"); // Reference counted per-process
		static PFN_SetProcessDpiAwareness SetProcessDpiAwarenessFn = (PFN_SetProcessDpiAwareness)::GetProcAddress(shcore_dll, "SetProcessDpiAwareness");
		if (SetProcessDpiAwarenessFn)
			SetProcessDpiAwarenessFn(PROCESS_PER_MONITOR_DPI_AWARE);
	}
	else
	{
		SetProcessDPIAware();
	}
}

float ImGui_ImplWin32_GetDpiScaleForMonitor(void* monitor)
{
	UINT xdpi = 96, ydpi = 96;

	if (IsWindows8Point1OrGreater())
	{
		static HINSTANCE shcore_dll = ::LoadLibraryA("shcore.dll"); // Reference counted per-process
		static PFN_GetDpiForMonitor GetDpiForMonitorFn = (PFN_GetDpiForMonitor)::GetProcAddress(shcore_dll, "GetDpiForMonitor");
		if (GetDpiForMonitorFn)
			GetDpiForMonitorFn((HMONITOR)monitor, MDT_EFFECTIVE_DPI, &xdpi, &ydpi);
	}
	else
	{
		const HDC dc = ::GetDC(nullptr);
		xdpi = ::GetDeviceCaps(dc, LOGPIXELSX);
		ydpi = ::GetDeviceCaps(dc, LOGPIXELSY);
		::ReleaseDC(nullptr, dc);
	}

	IM_ASSERT(xdpi == ydpi); // Please contact me if you hit this assert!
	return xdpi / 96.0f;
}

float ImGui_ImplWin32_GetDpiScaleForHwnd(void* hwnd)
{
	HMONITOR monitor = ::MonitorFromWindow((HWND)hwnd, MONITOR_DEFAULTTONEAREST);
	return ImGui_ImplWin32_GetDpiScaleForMonitor(monitor);
}

#pragma region ImGui Multi-Viewport Support

//--------------------------------------------------------------------------------------------------------
// MULTI-VIEWPORT / PLATFORM INTERFACE SUPPORT
// This is an _advanced_ and _optional_ feature, allowing the back-end to create and handle multiple viewports simultaneously.
// If you are new to dear imgui or creating a new binding for dear imgui, it is recommended that you completely ignore this section first..
//--------------------------------------------------------------------------------------------------------

struct ImGuiViewportDataWin32
{
	HWND    Hwnd;
	bool    HwndOwned;
	DWORD   DwStyle;
	DWORD   DwExStyle;

	ImGuiViewportDataWin32() { Hwnd = nullptr; HwndOwned = false;  DwStyle = DwExStyle = 0; }
	~ImGuiViewportDataWin32() { IM_ASSERT(Hwnd == nullptr); }
};

static void ImGui_ImplWin32_GetWin32StyleFromViewportFlags(ImGuiViewportFlags flags, DWORD* out_style, DWORD* out_ex_style)
{
	if (flags & ImGuiViewportFlags_NoDecoration)
		*out_style = WS_POPUP;
	else
		*out_style = WS_OVERLAPPEDWINDOW;

	if (flags & ImGuiViewportFlags_NoTaskBarIcon)
		*out_ex_style = WS_EX_TOOLWINDOW;
	else
		*out_ex_style = WS_EX_APPWINDOW;

	if (flags & ImGuiViewportFlags_TopMost)
		*out_ex_style |= WS_EX_TOPMOST;
}

static void ImGui_ImplWin32_CreateWindow(ImGuiViewport* viewport)
{
	ImGuiViewportDataWin32* data = IM_NEW(ImGuiViewportDataWin32)();
	viewport->PlatformUserData = data;

	// Select style and parent window
	ImGui_ImplWin32_GetWin32StyleFromViewportFlags(viewport->Flags, &data->DwStyle, &data->DwExStyle);
	HWND parent_window = nullptr;
	if (viewport->ParentViewportId != 0)
		if (ImGuiViewport* parent_viewport = ImGui::FindViewportByID(viewport->ParentViewportId))
			parent_window = (HWND)parent_viewport->PlatformHandle;

	// Create window
	RECT rect = { (LONG)viewport->Pos.x, (LONG)viewport->Pos.y, (LONG)(viewport->Pos.x + viewport->Size.x), (LONG)(viewport->Pos.y + viewport->Size.y) };
	::AdjustWindowRectEx(&rect, data->DwStyle, FALSE, data->DwExStyle);
	data->Hwnd = ::CreateWindowExA(
		data->DwExStyle, "ImGui Platform", "Untitled", data->DwStyle,              // Style, class name, window name
		rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top,       // Window area
		parent_window, nullptr, ghInstance, nullptr);                              // Parent window, Menu, Instance, Param
	data->HwndOwned = true;
	viewport->PlatformRequestResize = false;
	viewport->PlatformHandle = viewport->PlatformHandleRaw = data->Hwnd;
}

static void ImGui_ImplWin32_DestroyWindow(ImGuiViewport* viewport)
{
	if (ImGuiViewportDataWin32* data = (ImGuiViewportDataWin32*)viewport->PlatformUserData)
	{
		if (::GetCapture() == data->Hwnd)
		{
			// Transfer capture so if we started dragging from a window that later disappears, we'll still receive the MOUSEUP event.
			::ReleaseCapture();
			::SetCapture(g_hWnd);
		}

		if (data->Hwnd && data->HwndOwned)
			::DestroyWindow(data->Hwnd);
		data->Hwnd = nullptr;
		IM_DELETE(data);
	}
	viewport->PlatformUserData = viewport->PlatformHandle = nullptr;
}

static void ImGui_ImplWin32_ShowWindow(ImGuiViewport* viewport)
{
	ImGuiViewportDataWin32* data = (ImGuiViewportDataWin32*)viewport->PlatformUserData;
	IM_ASSERT(data->Hwnd != nullptr);
	if (viewport->Flags & ImGuiViewportFlags_NoFocusOnAppearing)
		::ShowWindow(data->Hwnd, SW_SHOWNA);
	else
		::ShowWindow(data->Hwnd, SW_SHOW);
}

static void ImGui_ImplWin32_UpdateWindow(ImGuiViewport* viewport)
{
	// (Optional) Update Win32 style if it changed _after_ creation.
	// Generally they won't change unless configuration flags are changed, but advanced uses (such as manually rewriting viewport flags) make this useful.
	ImGuiViewportDataWin32* data = (ImGuiViewportDataWin32*)viewport->PlatformUserData;
	IM_ASSERT(data->Hwnd != nullptr);
	DWORD new_style;
	DWORD new_ex_style;
	ImGui_ImplWin32_GetWin32StyleFromViewportFlags(viewport->Flags, &new_style, &new_ex_style);

	// Only reapply the flags that have been changed from our point of view (as other flags are being modified by Windows)
	if (data->DwStyle != new_style || data->DwExStyle != new_ex_style)
	{
		data->DwStyle = new_style;
		data->DwExStyle = new_ex_style;
		::SetWindowLong(data->Hwnd, GWL_STYLE, data->DwStyle);
		::SetWindowLong(data->Hwnd, GWL_EXSTYLE, data->DwExStyle);
		RECT rect = { (LONG)viewport->Pos.x, (LONG)viewport->Pos.y, (LONG)(viewport->Pos.x + viewport->Size.x), (LONG)(viewport->Pos.y + viewport->Size.y) };
		::AdjustWindowRectEx(&rect, data->DwStyle, FALSE, data->DwExStyle); // Client to Screen
		::SetWindowPos(data->Hwnd, nullptr, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);
		::ShowWindow(data->Hwnd, SW_SHOWNA); // This is necessary when we alter the style
		viewport->PlatformRequestMove = viewport->PlatformRequestResize = true;
	}
}

static ImVec2 ImGui_ImplWin32_GetWindowPos(ImGuiViewport* viewport)
{
	ImGuiViewportDataWin32* data = (ImGuiViewportDataWin32*)viewport->PlatformUserData;
	IM_ASSERT(data->Hwnd != nullptr);
	POINT pos = { 0, 0 };
	::ClientToScreen(data->Hwnd, &pos);
	return ImVec2((float)pos.x, (float)pos.y);
}

static void ImGui_ImplWin32_SetWindowPos(ImGuiViewport* viewport, ImVec2 pos)
{
	ImGuiViewportDataWin32* data = (ImGuiViewportDataWin32*)viewport->PlatformUserData;
	IM_ASSERT(data->Hwnd != nullptr);
	RECT rect = { (LONG)pos.x, (LONG)pos.y, (LONG)pos.x, (LONG)pos.y };
	::AdjustWindowRectEx(&rect, data->DwStyle, FALSE, data->DwExStyle);
	::SetWindowPos(data->Hwnd, nullptr, rect.left, rect.top, 0, 0, SWP_NOZORDER | SWP_NOSIZE | SWP_NOACTIVATE);
}

static ImVec2 ImGui_ImplWin32_GetWindowSize(ImGuiViewport* viewport)
{
	ImGuiViewportDataWin32* data = (ImGuiViewportDataWin32*)viewport->PlatformUserData;
	IM_ASSERT(data->Hwnd != nullptr);
	RECT rect;
	::GetClientRect(data->Hwnd, &rect);
	return ImVec2(float(rect.right - rect.left), float(rect.bottom - rect.top));
}

static void ImGui_ImplWin32_SetWindowSize(ImGuiViewport* viewport, ImVec2 size)
{
	ImGuiViewportDataWin32* data = (ImGuiViewportDataWin32*)viewport->PlatformUserData;
	IM_ASSERT(data->Hwnd != nullptr);
	RECT rect = { 0, 0, (LONG)size.x, (LONG)size.y };
	::AdjustWindowRectEx(&rect, data->DwStyle, FALSE, data->DwExStyle); // Client to Screen
	::SetWindowPos(data->Hwnd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, SWP_NOZORDER | SWP_NOMOVE | SWP_NOACTIVATE);
}

static void ImGui_ImplWin32_SetWindowFocus(ImGuiViewport* viewport)
{
	ImGuiViewportDataWin32* data = (ImGuiViewportDataWin32*)viewport->PlatformUserData;
	IM_ASSERT(data->Hwnd != nullptr);
	::BringWindowToTop(data->Hwnd);
	::SetForegroundWindow(data->Hwnd);
	::SetFocus(data->Hwnd);
}

static bool ImGui_ImplWin32_GetWindowFocus(ImGuiViewport* viewport)
{
	ImGuiViewportDataWin32* data = (ImGuiViewportDataWin32*)viewport->PlatformUserData;
	IM_ASSERT(data->Hwnd != nullptr);
	return ::GetForegroundWindow() == data->Hwnd;
}

static bool ImGui_ImplWin32_GetWindowMinimized(ImGuiViewport* viewport)
{
	ImGuiViewportDataWin32* data = (ImGuiViewportDataWin32*)viewport->PlatformUserData;
	IM_ASSERT(data->Hwnd != nullptr);
	return ::IsIconic(data->Hwnd) != 0;
}

static void ImGui_ImplWin32_SetWindowTitle(ImGuiViewport* viewport, const char* title)
{
	// ::SetWindowTextA() doesn't properly handle UTF-8 so we explicitely convert our string.
	ImGuiViewportDataWin32* data = (ImGuiViewportDataWin32*)viewport->PlatformUserData;
	IM_ASSERT(data->Hwnd != 0);
	int n = ::MultiByteToWideChar(CP_UTF8, 0, title, -1, nullptr, 0);
	ImVector<wchar_t> title_w;
	title_w.resize(n);
	::MultiByteToWideChar(CP_UTF8, 0, title, -1, title_w.Data, n);
	::SetWindowTextW(data->Hwnd, title_w.Data);
}

static void ImGui_ImplWin32_SetWindowAlpha(ImGuiViewport* viewport, float alpha)
{
	ImGuiViewportDataWin32* data = (ImGuiViewportDataWin32*)viewport->PlatformUserData;
	IM_ASSERT(data->Hwnd != nullptr);
	IM_ASSERT(alpha >= 0.0f && alpha <= 1.0f);
	if (alpha < 1.0f)
	{
		DWORD style = ::GetWindowLongW(data->Hwnd, GWL_EXSTYLE) | WS_EX_LAYERED;
		::SetWindowLongW(data->Hwnd, GWL_EXSTYLE, style);
		::SetLayeredWindowAttributes(data->Hwnd, 0, (BYTE)(255 * alpha), LWA_ALPHA);
	}
	else
	{
		DWORD style = ::GetWindowLongW(data->Hwnd, GWL_EXSTYLE) & ~WS_EX_LAYERED;
		::SetWindowLongW(data->Hwnd, GWL_EXSTYLE, style);
	}
}

static float ImGui_ImplWin32_GetWindowDpiScale(ImGuiViewport* viewport)
{
	ImGuiViewportDataWin32* data = (ImGuiViewportDataWin32*)viewport->PlatformUserData;
	IM_ASSERT(data->Hwnd != nullptr);
	return ImGui_ImplWin32_GetDpiScaleForHwnd(data->Hwnd);
}

// FIXME-DPI: Testing DPI related ideas
static void ImGui_ImplWin32_OnChangedViewport(ImGuiViewport* viewport)
{
	(void)viewport;
#if 0
	ImGuiStyle default_style;
	//default_style.WindowPadding = ImVec2(0, 0);
	//default_style.WindowBorderSize = 0.0f;
	//default_style.ItemSpacing.y = 3.0f;
	//default_style.FramePadding = ImVec2(0, 0);
	default_style.ScaleAllSizes(viewport->DpiScale);
	ImGuiStyle& style = ImGui::GetStyle();
	style = default_style;
#endif
}

static LRESULT CALLBACK ImGui_ImplWin32_WndProcHandler_PlatformWindow(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	if (ImGuiViewport* viewport = ImGui::FindViewportByPlatformHandle((void*)hWnd))
	{
		switch (msg)
		{
		case WM_CLOSE:
			viewport->PlatformRequestClose = true;
			return 0;
		case WM_MOVE:
			viewport->PlatformRequestMove = true;
			break;
		case WM_SIZE:
			viewport->PlatformRequestResize = true;
			break;
		case WM_MOUSEACTIVATE:
			if (viewport->Flags & ImGuiViewportFlags_NoFocusOnClick)
				return MA_NOACTIVATE;
			break;
		case WM_NCHITTEST:
			// Let mouse pass-through the window. This will allow the back-end to set io.MouseHoveredViewport properly (which is OPTIONAL).
			// The ImGuiViewportFlags_NoInputs flag is set while dragging a viewport, as want to detect the window behind the one we are dragging.
			// If you cannot easily access those viewport flags from your windowing/event code: you may manually synchronize its state e.g. in
			// your main loop after calling UpdatePlatformWindows(). Iterate all viewports/platform windows and pass the flag to your windowing system.
			if (viewport->Flags & ImGuiViewportFlags_NoInputs)
				return HTTRANSPARENT;
			break;
		}
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

static BOOL CALLBACK ImGui_ImplWin32_UpdateMonitors_EnumFunc(HMONITOR monitor, HDC, LPRECT, LPARAM)
{
	MONITORINFO info = { 0 };
	info.cbSize = sizeof(MONITORINFO);
	if (!::GetMonitorInfo(monitor, &info))
		return TRUE;
	ImGuiPlatformMonitor imgui_monitor;
	imgui_monitor.MainPos = ImVec2((float)info.rcMonitor.left, (float)info.rcMonitor.top);
	imgui_monitor.MainSize = ImVec2((float)(info.rcMonitor.right - info.rcMonitor.left), (float)(info.rcMonitor.bottom - info.rcMonitor.top));
	imgui_monitor.WorkPos = ImVec2((float)info.rcWork.left, (float)info.rcWork.top);
	imgui_monitor.WorkSize = ImVec2((float)(info.rcWork.right - info.rcWork.left), (float)(info.rcWork.bottom - info.rcWork.top));
	imgui_monitor.DpiScale = ImGui_ImplWin32_GetDpiScaleForMonitor(monitor);
	ImGuiPlatformIO& io = ImGui::GetPlatformIO();
	if (info.dwFlags & MONITORINFOF_PRIMARY)
		io.Monitors.push_front(imgui_monitor);
	else
		io.Monitors.push_back(imgui_monitor);

	return TRUE;
}

static void ImGui_ImplWin32_UpdateMonitors()
{
	ImGui::GetPlatformIO().Monitors.resize(0);
	::EnumDisplayMonitors(nullptr, nullptr, ImGui_ImplWin32_UpdateMonitors_EnumFunc, 0);
	g_WantUpdateMonitors = false;
}

static void ImGui_ImplWin32_InitPlatformInterface()
{
	WNDCLASSEXA wcex;
	wcex.cbSize = sizeof(WNDCLASSEXA);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = ImGui_ImplWin32_WndProcHandler_PlatformWindow;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = ghInstance;
	wcex.hIcon = nullptr;
	wcex.hCursor = nullptr;
	wcex.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = "ImGui Platform";
	wcex.hIconSm = nullptr;
	::RegisterClassExA(&wcex);

	ImGui_ImplWin32_UpdateMonitors();

	// Register platform interface (will be coupled with a renderer interface)
	ImGuiPlatformIO& platform_io = ImGui::GetPlatformIO();
	platform_io.Platform_CreateWindow = ImGui_ImplWin32_CreateWindow;
	platform_io.Platform_DestroyWindow = ImGui_ImplWin32_DestroyWindow;
	platform_io.Platform_ShowWindow = ImGui_ImplWin32_ShowWindow;
	platform_io.Platform_SetWindowPos = ImGui_ImplWin32_SetWindowPos;
	platform_io.Platform_GetWindowPos = ImGui_ImplWin32_GetWindowPos;
	platform_io.Platform_SetWindowSize = ImGui_ImplWin32_SetWindowSize;
	platform_io.Platform_GetWindowSize = ImGui_ImplWin32_GetWindowSize;
	platform_io.Platform_SetWindowFocus = ImGui_ImplWin32_SetWindowFocus;
	platform_io.Platform_GetWindowFocus = ImGui_ImplWin32_GetWindowFocus;
	platform_io.Platform_GetWindowMinimized = ImGui_ImplWin32_GetWindowMinimized;
	platform_io.Platform_SetWindowTitle = ImGui_ImplWin32_SetWindowTitle;
	platform_io.Platform_SetWindowAlpha = ImGui_ImplWin32_SetWindowAlpha;
	platform_io.Platform_UpdateWindow = ImGui_ImplWin32_UpdateWindow;
	platform_io.Platform_GetWindowDpiScale = ImGui_ImplWin32_GetWindowDpiScale; // FIXME-DPI
	platform_io.Platform_OnChangedViewport = ImGui_ImplWin32_OnChangedViewport; // FIXME-DPI

	// Register main window handle (which is owned by the main application, not by us)
	ImGuiViewport* main_viewport = ImGui::GetMainViewport();
	ImGuiViewportDataWin32* data = IM_NEW(ImGuiViewportDataWin32)();
	data->Hwnd = g_hWnd;
	data->HwndOwned = false;
	main_viewport->PlatformUserData = data;
	main_viewport->PlatformHandle = (void*)g_hWnd;
}

static void ImGui_ImplWin32_ShutdownPlatformInterface()
{
	::UnregisterClass("ImGui Platform", ghInstance);
}

static void ImGui_EnableViewports(bool enable)
{
	ImGuiIO& io = ImGui::GetIO();

	if (!enable)
	{
		io.ConfigFlags &= ~ImGuiConfigFlags_ViewportsEnable;
	}
	else
	{
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	}
}
#pragma endregion

#pragma endregion

#pragma region ImGui: Startup / Shutdown


void InitializeImGui(IDirect3DDevice9* device)
{
	if (gbInitializedImGui)
		return;

	gbLastFullScreenState = IsFullScreen(device);
	ImGui_EnableViewports(!gbLastFullScreenState);                // Enable Multi-Viewport / Platform Windows

	// Retrieve window handle from device
	D3DDEVICE_CREATION_PARAMETERS params;
	device->GetCreationParameters(&params);

	// Initialize the platform backend and renderer bindings
	ImGui_ImplWin32_Init(params.hFocusWindow);
	ImGui_ImplDX9_Init(device);

	gbInitializedImGui = true;
}

void ShutdownImGui()
{
	if (!gbInitializedImGui)
		return;

	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();

	g_pImguiDevice = nullptr;
	g_pVB = nullptr;
	g_pIB = nullptr;
	g_FontTexture = nullptr;
	g_VertexBufferSize = 5000;
	g_IndexBufferSize = 10000;
	g_bImGuiReady = false;

	g_hWnd = nullptr;
	g_Time = 0;
	g_TicksPerSecond = 0;
	g_LastMouseCursor = ImGuiMouseCursor_COUNT;
	g_WantUpdateMonitors = true;
	gbInitializedImGui = false;
}

#pragma endregion

//============================================================================

} // namespace imgui

#pragma endregion

//============================================================================

#pragma region Render Hooks

class RenderHooks
{
public:
	//------------------------------------------------------------------------
	// d3d9 hooks

	// this is only valid during a d3d9 hook detour
	IDirect3DDevice9* GetThisDevice() { return reinterpret_cast<IDirect3DDevice9*>(this); }

	// Install hooks on actual instance of the device once we have it.
	bool DetectResetDeviceHook()
	{
		bool changed = false;

		// IDirect3DDevice9 virtual function hooks
		DWORD* d3dDevice_vftable = *(DWORD**)this;

		DWORD resetDevice = d3dDevice_vftable[0x10];

		if (resetDevice != gResetDeviceAddress)
		{
			if (gResetDeviceAddress != 0)
			{
				SPDLOG_DEBUG("Detected a change in the rendering device. Attempting to recover.");
			}

			gResetDeviceAddress = resetDevice;

			InstallDetour(d3dDevice_vftable[0x10], &RenderHooks::Reset_Detour,
				&RenderHooks::Reset_Trampoline, "d3dDevice_Reset");

			changed = true;
		}

		return changed;
	}

	HRESULT WINAPI Reset_Trampoline(D3DPRESENT_PARAMETERS* pPresentationParameters);
	HRESULT WINAPI Reset_Detour(D3DPRESENT_PARAMETERS* pPresentationParameters)
	{
		if (gpD3D9Device != GetThisDevice())
		{
			SPDLOG_INFO("IDirect3DDevice9::Reset hook: instance does not match acquired device, skipping.");
			return Reset_Trampoline(pPresentationParameters);
		}

		SPDLOG_INFO("IDirect3DDevice9::Reset hook: device instance is the acquired device.");
		InvalidateDeviceObjects();

		return Reset_Trampoline(pPresentationParameters);
	}

	HRESULT WINAPI BeginScene_Trampoline();
	HRESULT WINAPI BeginScene_Detour()
	{
		// Whenever a BeginScene occurs, we know that this is the device we want to use.
		gpD3D9Device = GetThisDevice();

		return BeginScene_Trampoline();
	}

	HRESULT WINAPI EndScene_Trampoline();
	HRESULT WINAPI EndScene_Detour()
	{
		// Don't try to use the device if it changed between BeginScene and EndScene.
		if (GetThisDevice() != gpD3D9Device || !gpD3D9Device)
		{
			return EndScene_Trampoline();
		}

		// Prevent re-entrancy. This was happening due to the mumble overlay.
		static bool sbInEndSceneDetour = false;
		if (sbInEndSceneDetour)
		{
			return EndScene_Trampoline();
		}

		sbInEndSceneDetour = true;

		// Check if a full screen mode change occurred before this frame.
		// If it did, we should not render, and instead re-initialize imgui.
		if (test_and_set(gbLastFullScreenState, IsFullScreen(gpD3D9Device)))
		{
			// For some reason, maybe due to a bug, toggling viewports off and
			// then calling CreateDeviceObjects will cause it to still create
			// the additional swap chains, which causes errors. So instead of
			// disabling viewports, we are simply rebooting imgui.
			gbNeedResetOverlay = true;
		}
		// When TestCooperativeLevel returns all good, then we can reinitialize.
		// This will let the renderer control our flow instead of having to
		// poll for the state ourselves.
		else if (!gbDeviceAcquired)
		{
			if (gReInitFrameDelay == 0)
			{
				HRESULT result = GetThisDevice()->TestCooperativeLevel();

				if (result == D3D_OK)
				{
					SPDLOG_INFO("IDirect3DDevice9::EndScene: TestCooperativeLevel was successful, reacquiring device.");

					imgui::InitializeImGui(gpD3D9Device);

					if (DetectResetDeviceHook())
					{
						InvalidateDeviceObjects();
					}

					CreateDeviceObjects();
				}
			}
			else
			{
				--gReInitFrameDelay;
			}
		}

		// Perform the render within a stateblock so we don't upset the
		// rest of the rendering pipeline
		if (gbDeviceAcquired)
		{
			RenderImGui();
		}

		HRESULT result = EndScene_Trampoline();
		sbInEndSceneDetour = false;

		return result;
	}
};
DETOUR_TRAMPOLINE_EMPTY(HRESULT RenderHooks::Reset_Trampoline(D3DPRESENT_PARAMETERS* pPresentationParameters));
DETOUR_TRAMPOLINE_EMPTY(HRESULT RenderHooks::BeginScene_Trampoline());
DETOUR_TRAMPOLINE_EMPTY(HRESULT RenderHooks::EndScene_Trampoline());

// This hooks into an area of the rendering pipeline that is suitable to perform
// our own 3d rendering before the scene is completed.
class CParticleSystemHook
{
public:
	void Render_Trampoline();
	void Render_Detour()
	{
		if (gbDeviceAcquired)
		{
			UpdateGraphicsScene();
		}

		Render_Trampoline();
	}
};
DETOUR_TRAMPOLINE_EMPTY(void CParticleSystemHook::Render_Trampoline());

class CRenderHook
{
public:
	// This hooks the ResetDevice function which is called when we want to reset the device. Hooking
	// this function ensures that even if our hook of the Direct3D device fails, we can still release our objects.
	bool ResetDevice_Trampoline(bool);
	bool ResetDevice_Detour(bool a)
	{
		SPDLOG_DEBUG("CRender::ResetDevice: Resetting device");

		bool success = ResetDevice_Trampoline(a);

		if (!success)
		{
			SPDLOG_DEBUG("CRender::ResetDevice: Reset failed, invalidating device objects and trying again.");
			InvalidateDeviceObjects();

			success = ResetDevice_Trampoline(a);
		}

		SPDLOG_DEBUG("CRender::ResetDevice: result={}", success);
		return success;
	}
};
DETOUR_TRAMPOLINE_EMPTY(bool CRenderHook::ResetDevice_Trampoline(bool));

// Mouse hook prevents mouse events from reaching EQ when imgui captures
// the mouse. Needed because ImGui uses win32 events but EQ uses direct input.
DETOUR_TRAMPOLINE_EMPTY(void ProcessMouseEvents_Trampoline());
void ProcessMouseEvents_Detour()
{
	if (ImGui::GetCurrentContext() != nullptr)
	{
		ImGuiIO& io = ImGui::GetIO();
		bool consumeMouse = io.WantCaptureMouse;

		// Read mouse state from direct input
		DIDEVICEOBJECTDATA data[128];
		DWORD num = 128;

		HRESULT hr = (*EQADDR_DIMOUSE)->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), data, &num, DIGDD_PEEK);

		if (SUCCEEDED(hr))
		{
			for (DWORD i = 0; i < num; i++)
			{
				DIDEVICEOBJECTDATA& d = data[i];

				switch (d.dwOfs)
				{
				case DIMOFS_BUTTON0:
				case DIMOFS_BUTTON1:
				case DIMOFS_BUTTON2:
				case DIMOFS_BUTTON3:
				case DIMOFS_BUTTON4:
					if (HandleMouseEvent(d.dwOfs - DIMOFS_BUTTON0, (d.dwData & 0x80) != 0))
						consumeMouse = true;
					break;

				default:
					if (d.dwOfs == DIMOFS_Z)
					{
						io.MouseWheel += static_cast<int>(d.dwData) / (float)WHEEL_DELTA;
					}
					break;
				}
			}
		}

		if (consumeMouse)
		{
			(*gMouseState)->InWindow = 0;
			gbFlushNextMouse = true;

			// Consume the mouse state. This won't be very effective for sustained mouse clicks though.
			(*EQADDR_DIMOUSE)->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), data, &num, 0);

			return;
		}
	}

	if (gbFlushNextMouse)
	{
		// Flush the direct input device state so that the wheel data doesn't get
		// picked up by the game later.
		DIDEVICEOBJECTDATA data[128];
		DWORD num = 128;

		(*EQADDR_DIMOUSE)->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), data, &num, 0);
	}

	ProcessMouseEvents_Trampoline();

	// When we flush the mouse we want it to affect the mouse wheel too. HandleMouseWheel
	// happens inside the trampoline, so we wait to clear the flag until after.
	gbFlushNextMouse = false;
}

// The mouse wheel hook prevents EQ from handling scroll events while imgui has the
// mouse captured.
DETOUR_TRAMPOLINE_EMPTY(void HandleMouseWheel_Trampoline(int))
void HandleMouseWheel_Detour(int offset)
{
	if (ImGui::GetCurrentContext() != nullptr)
	{
		ImGuiIO& io = ImGui::GetIO();

		if (io.WantCaptureMouse)
		{
			return;
		}
	}

	if (!gbFlushNextMouse)
	{
		HandleMouseWheel_Trampoline(offset);
	}
}

// Keyboard hook prevents keyboard events from reaching EQ when imgui captures
// the keyboard. Needed because ImGui uses win32 events but EQ uses direct input.
DETOUR_TRAMPOLINE_EMPTY(uint32_t ProcessKeyboardEvents_Trampoline())
uint32_t ProcessKeyboardEvents_Detour()
{
	if (ImGui::GetCurrentContext() != nullptr)
	{
		ImGuiIO& io = ImGui::GetIO();

		if (io.WantCaptureKeyboard)
		{
			// FlushDxKeyboard will consume any keyboard data that is currently
			// buffered by direct input so that the keyboard inputs don't get
			// picked up by EQ too.
			eqlib::FlushDxKeyboard();
			return 0;
		}
	}

	return ProcessKeyboardEvents_Trampoline();
}

bool OverlayWndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (msg == WM_KEYDOWN
		&& gbToggleConsoleHotkeyReady)
	{
		// Match the vkey and modifiers
		if (wParam == gToggleConsoleHotkey.virtualKey)
		{
			// Check the modifiers, don't allow repeats.
			if ((HIWORD(lParam) & KF_REPEAT) == 0
				&& mq::IsHotKeyModifiersPressed(gToggleConsoleHotkey))
			{
				gbToggleConsoleRequested = true;
			}
		}
	}

	if (imgui::g_pImguiDevice)
	{
		if (imgui::ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
			return true;
	}

	return false;
}

// Forwards events to ImGui. If ImGui consumes the event, we won't pass it to the game.
DETOUR_TRAMPOLINE_EMPTY(LRESULT WINAPI WndProc_Trampoline(HWND, UINT, WPARAM, LPARAM));
LRESULT WINAPI WndProc_Detour(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (OverlayWndProcHandler(hWnd, msg, wParam, lParam))
		return 1;

	return WndProc_Trampoline(hWnd, msg, wParam, lParam);
}

static IDirect3DDevice9* AcquireDevice()
{
	IDirect3DDevice9* pDevice = nullptr;

	if (pGraphicsEngine && pGraphicsEngine->pRender && pGraphicsEngine->pRender->pD3DDevice)
	{
		return pGraphicsEngine->pRender->pD3DDevice;
	}

	return nullptr;
}

static bool InstallD3D9Hooks()
{
	bool success = false;
	HMODULE hD3D9Module = nullptr;

	if (!hD3D9Module)
	{
		hD3D9Module = GetModuleHandle("d3d9.dll");
	}

	// Acquire the address of the virtual function table by creating an instance of IDirect3DDevice9Ex.
	if (hD3D9Module)
	{
		D3D9CREATEEXPROC d3d9CreateEx = (D3D9CREATEEXPROC)GetProcAddress(hD3D9Module, "Direct3DCreate9Ex");
		if (!d3d9CreateEx)
		{
			DebugSpewAlways("InstallD3D9Hooks: Failed to get address of Direct3DCreate9Ex");
			return false;
		}

		IDirect3D9Ex* d3d9ex;
		HRESULT hResult = (*d3d9CreateEx)(D3D_SDK_VERSION, &d3d9ex);

		if (!SUCCEEDED(hResult))
		{
			DebugSpewAlways("InstallD3D9Hooks: Call to Direct3DCreate9Ex failed. Result: %x", hResult);
			return false;
		}

		D3DPRESENT_PARAMETERS pp;
		ZeroMemory(&pp, sizeof(pp));
		pp.Windowed = 1;
		pp.SwapEffect = D3DSWAPEFFECT_FLIP;
		pp.BackBufferFormat = D3DFMT_A8R8G8B8;
		pp.BackBufferCount = 1;
		pp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

		// save the rounding state. We'll restore it after we're done here.
		// For some reason, CreateDeviceEx seems to tamper with it.
		int round = fegetround();

		IDirect3DDevice9* device = nullptr;
		hResult = d3d9ex->CreateDeviceEx(
			D3DADAPTER_DEFAULT,
			D3DDEVTYPE_NULLREF,
			nullptr,
			D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_NOWINDOWCHANGES,
			&pp, nullptr, (IDirect3DDevice9Ex**)&device);

		if (!SUCCEEDED(hResult))
		{
			DebugSpewAlways("InstallD3D9Hooks: failed to CreateDeviceEx. Result: %x", hResult);

			device = AcquireDevice();
		}

		if (device)
		{
			success = true;

			// IDirect3DDevice9 virtual function hooks
			DWORD* d3dDevice_vftable = *(DWORD**)device;

			InstallDetour(d3dDevice_vftable[0x29], &RenderHooks::BeginScene_Detour,
				&RenderHooks::BeginScene_Trampoline, "d3dDevice_BeginScene");
			InstallDetour(d3dDevice_vftable[0x2a], &RenderHooks::EndScene_Detour,
				&RenderHooks::EndScene_Trampoline, "d3dDevice_EndScene");

			device->Release();
		}

		// restore floating point rounding state
		fesetround(round);

		if (d3d9ex)
		{
			d3d9ex->Release();
		}
	}

	return success;
}

enum class eOverlayHookStatus
{
	Success,
	Failed,
	MissingDevice,
};

static eOverlayHookStatus InitializeOverlayHooks()
{
	if (gbDeviceHooksInstalled)
	{
		if (!gpD3D9Device)
		{
			return eOverlayHookStatus::MissingDevice;
		}

		return eOverlayHookStatus::Success;
	}

	if (!pGraphicsEngine || !pGraphicsEngine->pRender || !pGraphicsEngine->pRender->pD3DDevice)
	{
		return eOverlayHookStatus::MissingDevice;
	}

	if (!InstallD3D9Hooks())
	{
		DebugSpewAlways("Failed to hook DirectX, We won't be able to render into the game!");
		return eOverlayHookStatus::Failed;
	}

	gbDeviceHooksInstalled = true;
	gLastGameState = gGameState;

	return !gpD3D9Device ? eOverlayHookStatus::MissingDevice : eOverlayHookStatus::Success;
}
#pragma endregion

//============================================================================

struct MQRenderCallbackRecord
{
	MQRenderCallbacks callbacks;
	int id;
};

static std::vector<std::unique_ptr<MQRenderCallbackRecord>> gRenderCallbacks;

int AddRenderCallbacks(const MQRenderCallbacks& callbacks)
{
	// Find an unused index.
	int index = -1;
	for (size_t i = 0; i < gRenderCallbacks.size(); ++i)
	{
		if (gRenderCallbacks[i] == nullptr)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		gRenderCallbacks.emplace_back();
		index = gRenderCallbacks.size() - 1;
	}

	auto pCallbacks = std::make_unique<MQRenderCallbackRecord>();
	pCallbacks->callbacks = callbacks;
	pCallbacks->id = index;

	// Make sure that we initialize if we're already acquired by
	// calling CreateDeviceObjects.
	if (gbDeviceAcquired && pCallbacks->callbacks.CreateDeviceObjects)
	{
		pCallbacks->callbacks.CreateDeviceObjects();
	}

	gRenderCallbacks[index] = std::move(pCallbacks);
	return index;
}

void RemoveRenderCallbacks(uint32_t id)
{
	if (id >= 0 && id < gRenderCallbacks.size())
	{
		// not sure if we should do this here or in the calling plugin...
		if (gRenderCallbacks[id] && gRenderCallbacks[id]->callbacks.InvalidateDeviceObjects)
		{
			gRenderCallbacks[id]->callbacks.InvalidateDeviceObjects();
		}

		gRenderCallbacks[id].reset();
	}
}

void SetOverlayEnabled(bool visible)
{
	imgui::g_bRenderImGui = visible;
}

bool IsOverlayEnabled()
{
	return imgui::g_bRenderImGui;
}

static bool RenderImGui()
{
	using namespace imgui;

	if (!g_bImGuiReady)
		return false;

	if (!g_bRenderImGui)
		return false;

	// This is loading/transitioning screen
	if (gGameState == GAMESTATE_LOGGINGIN)
		return false;

	if (gbNeedResetOverlay)
		return false;

	// we can't expect that the rounding mode is valid, and imgui respects the rounding mode so set it here and ensure that we reset it before the return
	auto round = fegetround();
	fesetround(FE_TONEAREST);

	ImGuiIO& io = ImGui::GetIO();

	IDirect3DStateBlock9* stateBlock = nullptr;
	gpD3D9Device->CreateStateBlock(D3DSBT_ALL, &stateBlock);

	// Begin a new frame
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();

	try
	{
		ImGui::NewFrame();

		{
			MQScopedBenchmark bm(bmPluginsUpdateImGui);

			PluginsUpdateImGui();
		}

		// Render the ui
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

		ImGui::UpdatePlatformWindows();

		// Update and Render additional Platform Windows
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			ImGui::RenderPlatformWindowsDefault();
		}
	}
	catch (const ImGuiException& ex)
	{
		gbManualResetRequired = true;

		WriteChatf("\arImGui Critical Failure: %s", ex.what());
		WriteChatf("\arFix the error and then run: \ay/mqoverlay resume\ar");
	}

	stateBlock->Apply();
	stateBlock->Release();

	fesetround(round);

	return true;
}

static void UpdateGraphicsScene()
{
	if (gRenderCallbacks.empty())
		return;

	// Perform the render within a stateblock so we don't upset the rest
	// of the rendering pipeline
	IDirect3DStateBlock9* stateBlock = nullptr;
	gpD3D9Device->CreateStateBlock(D3DSBT_ALL, &stateBlock);

	for (const auto& pCallbacks : gRenderCallbacks)
	{
		if (pCallbacks && pCallbacks->callbacks.GraphicsSceneRender)
		{
			pCallbacks->callbacks.GraphicsSceneRender();
		}
	}

	stateBlock->Apply();
	stateBlock->Release();
}

static void InvalidateDeviceObjects()
{
	SPDLOG_DEBUG("MQ2Overlay: InvalidateDeviceObjects");

	gbDeviceAcquired = false;
	imgui::ImGui_ImplDX9_InvalidateDeviceObjects();
	imgui::g_bImGuiReady = false;

	for (const auto& pCallbacks : gRenderCallbacks)
	{
		if (pCallbacks && pCallbacks->callbacks.InvalidateDeviceObjects)
		{
			pCallbacks->callbacks.InvalidateDeviceObjects();
		}
	}
}

static bool CreateDeviceObjects()
{
	SPDLOG_DEBUG("MQ2Overlay: CreateDeviceObjects");

	gbDeviceAcquired = true;
	imgui::g_bImGuiReady = imgui::ImGui_ImplDX9_CreateDeviceObjects();

	for (const auto& pCallbacks : gRenderCallbacks)
	{
		if (pCallbacks && pCallbacks->callbacks.CreateDeviceObjects)
		{
			pCallbacks->callbacks.CreateDeviceObjects();
		}
	}

	return imgui::g_bImGuiReady;
}

#pragma endregion

//============================================================================

static void InitializeOverlayInternal();
static void ShutdownOverlayInternal();

bool IsImGuiForeground()
{
	if (ImGui::GetCurrentContext() == NULL)
		return false;

	const auto& platform_io = ImGui::GetPlatformIO();

	auto hWnd = GetForegroundWindow();
	for (const auto& v : platform_io.Viewports)
	{
		if (v != nullptr)
		{
			auto userdata = static_cast<imgui::ImGuiViewportDataDx9*>(v->RendererUserData);
			if (userdata != nullptr && userdata->d3dpp.hDeviceWindow == hWnd) return true;
		}
	}

	return false;
}

static ImFontAtlas* s_fontAtlas = nullptr;

void CreateImGuiContext()
{
	if (s_fontAtlas == nullptr)
	{
		s_fontAtlas = new ImFontAtlas();

		mq::imgui::ConfigureFonts(s_fontAtlas);
	}
	
	// Initialize ImGui context
	ImGui::CreateContext(s_fontAtlas);

	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;             // Enable Docking

	fmt::format_to(ImGuiSettingsFile, "{}/MacroQuest_Overlay.ini", mq::internal_paths::Config);
	io.IniFilename = &ImGuiSettingsFile[0];

	ImGui::StyleColorsDark();
	mq::imgui::ConfigureStyle();
}

void DestroyImGuiContext()
{
	ImGui::DestroyContext();

	delete s_fontAtlas;
	s_fontAtlas = nullptr;
}

void ReloadImGuiContext()
{
	if (ImGui::GetCurrentContext() != nullptr)
	{
		ImGui::DestroyContext();
	}

	CreateImGuiContext();
}

void MQOverlayCommand(SPAWNINFO* pSpawh, char* szLine)
{
	if (ci_equals(szLine, "reload"))
	{
		gbNeedResetOverlay = true;
	}
	else if (ci_equals(szLine, "resume"))
	{
		gbManualResetRequired = false;
	}
}

void InitializeMQ2Overlay()
{
	imgui::g_bRenderImGui = GetPrivateProfileBool("MacroQuest", "RenderImGui", imgui::g_bRenderImGui, mq::internal_paths::MQini);
	bmPluginsUpdateImGui = AddMQ2Benchmark("PluginsUpdateImGui");

	// TODO: application-wide keybinds could use an encapsulated interface. For now I'm just dumping his here since we need it to
	// connect to the win32 hook and control the imgui console.
	::GetPrivateProfileStringA("MacroQuest", "ToggleConsoleKey", gToggleConsoleDefaultBind,
		gToggleConsoleHotkey.keybind, lengthof(gToggleConsoleHotkey.keybind), mq::internal_paths::MQini.c_str());

	if (!gbToggleConsoleHotkeyReady)
	{
		if (mq::ConvertStringToModifiersAndVirtualKey(gToggleConsoleHotkey.keybind,
			gToggleConsoleHotkey.modifiers, gToggleConsoleHotkey.virtualKey))
		{
			SPDLOG_INFO("Toggle console keybind: {0}", gToggleConsoleHotkey.keybind);
			gbToggleConsoleHotkeyReady = true;
		}
		else if (strlen(gToggleConsoleHotkey.keybind) > 0)
		{
			SPDLOG_WARN("Unable to parse toggle console keybind: {0}", gToggleConsoleHotkey.keybind);
			strcpy_s(gToggleConsoleHotkey.keybind, "");

			gbToggleConsoleHotkeyReady = false;
		}
	}

	if (gbWriteAllConfig)
	{
		WritePrivateProfileBool("MacroQuest", "RenderImGui", imgui::g_bRenderImGui, mq::internal_paths::MQini);
	}

	// Intercept mouse events
	EzDetour(__ProcessMouseEvents, ProcessMouseEvents_Detour, ProcessMouseEvents_Trampoline);

	// Intercept mouse wheel events
	EzDetour(__HandleMouseWheel, HandleMouseWheel_Detour, HandleMouseWheel_Trampoline);

	// Intercept keyboard events
	EzDetour(__ProcessKeyboardEvents, ProcessKeyboardEvents_Detour, ProcessKeyboardEvents_Trampoline);

	// Hook the main window proc.
	EzDetour(__WndProc, WndProc_Detour, WndProc_Trampoline);

	// Hook particle render function
	EzDetour(CParticleSystem__Render, &CParticleSystemHook::Render_Detour, &CParticleSystemHook::Render_Trampoline);

	// Hook the reset device function
	EzDetour(CRender__ResetDevice, &CRenderHook::ResetDevice_Detour, &CRenderHook::ResetDevice_Trampoline);

	AddCommand("/mqoverlay", MQOverlayCommand);

	CreateImGuiContext();

	InitializeOverlayInternal();
}

void InitializeOverlayInternal()
{
	auto status = InitializeOverlayHooks();

	if (status != eOverlayHookStatus::Success)
	{
		gbRetryHooks = (status == eOverlayHookStatus::MissingDevice);
		gbInitializationFailed = (status == eOverlayHookStatus::Failed);
	}
}

void ShutdownMQ2Overlay()
{
	RemoveDetour(__ProcessMouseEvents);
	RemoveDetour(__HandleMouseWheel);
	RemoveDetour(__ProcessKeyboardEvents);
	RemoveDetour(__WndProc);
	RemoveDetour(CParticleSystem__Render);

	RemoveCommand("/mqoverlay");

	ShutdownOverlayInternal();
	DestroyImGuiContext();
	
	RemoveMQ2Benchmark(bmPluginsUpdateImGui);
}

void ShutdownOverlayInternal()
{
	if (!gbDeviceHooksInstalled)
		return;

	RemoveDetours();
	gbDeviceHooksInstalled = false;
	gHooks.clear();

	imgui::ShutdownImGui();

	gpD3D9Device = nullptr;
	gResetDeviceAddress = 0;
	gMouseLocation = POINT{};
	gbMouseBlocked = false;
	gbFlushNextMouse = false;
	gbRetryHooks = false;
	gbInitializationFailed = false;
	gbDeviceAcquired = false;
}

void DoResetOverlay()
{
	if (!gbDeviceHooksInstalled)
		return;

	SPDLOG_INFO("MQ2Overlay: Resetting overlay");

	if (gbDeviceAcquired)
	{
		InvalidateDeviceObjects();
		gbDeviceAcquired = false;
	}

	imgui::ShutdownImGui();
	ReloadImGuiContext();

	gpD3D9Device = nullptr;
	gResetDeviceAddress = 0;
}

// Exported - should defer to next pulse
void ResetOverlay()
{
	gbNeedResetOverlay = true;
}

void PulseMQ2Overlay()
{
	// Reset the device hooks between game states. Some of them may alter
	// the device and we might need to start over.
	if (gGameState != gLastGameState)
	{
		DebugSpewAlways("Game State Changed: %d, resetting device", gGameState);

		gLastGameState = gGameState;
		DoResetOverlay();
	}
	else if (gbNeedResetOverlay)
	{
		DoResetOverlay();

		gbNeedResetOverlay = false;
		gReInitFrameDelay = 1;
	}

	if (gbRetryHooks)
	{
		gbRetryHooks = false;
		InitializeOverlayInternal();
	}
}

} // namespace mq
