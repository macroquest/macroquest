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

#include "pch.h"
#include "MQ2Main.h"

#include <imgui/imgui.h>

#include <Shlobj.h>

#ifdef DIRECTINPUT_VERSION
#undef DIRECTINPUT_VERSION
#endif
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <d3d9.h>
#include <fenv.h>

#include <fmt/format.h>
#include <atomic>
#include <vector>

namespace mq {

//----------------------------------------------------------------------------
// globals

// The global direct 3d device that we are using. This belongs to EQ, so we
// need to hook into it to understand when states change.
IDirect3DDevice9* gpD3D9Device = nullptr;

//----------------------------------------------------------------------------
// statics

static bool gbHooksInstalled = false;
static bool gbDeviceAcquired = false;
static HMODULE ghD3D9Module = nullptr;
static DWORD gResetDeviceAddress = 0;

static POINT gMouseLocation;
static bool gbMouseBlocked = false;
static char ImGuiSettingsFile[MAX_PATH] = { 0 };
static bool gbFlushNextMouse = false;

static bool gbRetryHooks = false;
static bool gbInitializationFailed = false;

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

static void UpdateOverlayUI();

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
		// hook already installed. Remove it.
		if (iter->address != 0)
		{
			RemoveDetour(iter->address);
		}

		gHooks.erase(iter);
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

namespace imgui {

//============================================================================
// Custom ImGui renderer for win32 and directx 9, integrated into EverQuest,
// written by Brainiac, based off of example code from github.com/ocornut/imgui

// DirectX data
static LPDIRECT3DDEVICE9        g_pd3dDevice = nullptr;
static LPDIRECT3DVERTEXBUFFER9  g_pVB = nullptr;
static LPDIRECT3DINDEXBUFFER9   g_pIB = nullptr;
static LPDIRECT3DTEXTURE9       g_FontTexture = nullptr;
static int                      g_VertexBufferSize = 5000;
static int                      g_IndexBufferSize = 10000;
static bool                     g_bImGuiReady = false;
static bool                     g_bRenderImGui = false;

struct CUSTOMVERTEX
{
	float    pos[3];
	D3DCOLOR col;
	float    uv[2];
};

constexpr int D3DFVF_CUSTOMVERTEX = (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

// Win32 Data
static HWND                     g_hWnd = nullptr;
static int64_t                  g_Time = 0;
static int64_t                  g_TicksPerSecond = 0;
static ImGuiMouseCursor         g_LastMouseCursor = ImGuiMouseCursor_COUNT;

static void ImGui_ImplDX9_SetupRenderState(ImDrawData* drawData)
{
	// Setup viewport
	D3DVIEWPORT9 vp;
	vp.X = vp.Y = 0;
	vp.Width = (DWORD)drawData->DisplaySize.x;
	vp.Height = (DWORD)drawData->DisplaySize.y;
	vp.MinZ = 0.0f;
	vp.MaxZ = 1.0f;
	g_pd3dDevice->SetViewport(&vp);

	// Setup render state: fixed-pipeline, alpha-blending, no face culling, no depth testing, shade mode (for gradient)
	g_pd3dDevice->SetPixelShader(nullptr);
	g_pd3dDevice->SetVertexShader(nullptr);
	g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, false);
	g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, false);
	g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pd3dDevice->SetRenderState(D3DRS_ALPHATESTENABLE, false);
	g_pd3dDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	g_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, true);
	g_pd3dDevice->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);
	g_pd3dDevice->SetRenderState(D3DRS_FOGENABLE, false);
	g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	g_pd3dDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	g_pd3dDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pd3dDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
	g_pd3dDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	g_pd3dDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);

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
		g_pd3dDevice->SetTransform(D3DTS_WORLD, &mat_identity);
		g_pd3dDevice->SetTransform(D3DTS_VIEW, &mat_identity);
		g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &mat_projection);
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
		if (g_pd3dDevice->CreateVertexBuffer(g_VertexBufferSize * sizeof(CUSTOMVERTEX), D3DUSAGE_DYNAMIC | D3DUSAGE_WRITEONLY, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &g_pVB, nullptr) < 0)
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
		if (g_pd3dDevice->CreateIndexBuffer(g_IndexBufferSize * sizeof(ImDrawIdx), D3DUSAGE_DYNAMIC | D3DUSAGE_WRITEONLY, sizeof(ImDrawIdx) == 2 ? D3DFMT_INDEX16 : D3DFMT_INDEX32, D3DPOOL_DEFAULT, &g_pIB, nullptr) < 0)
			return;
	}

	// Backup the DX9 state
	IDirect3DStateBlock9* d3d9StateBlock = nullptr;
	if (g_pd3dDevice->CreateStateBlock(D3DSBT_ALL, &d3d9StateBlock) < 0)
		return;

	// Backup the DX9 transform (DX9 documentation suggests that it is included in the StateBlock but it doesn't appear to)
	D3DMATRIX lastWorld, lastView, lastProjection;
	g_pd3dDevice->GetTransform(D3DTS_WORLD, &lastWorld);
	g_pd3dDevice->GetTransform(D3DTS_VIEW, &lastView);
	g_pd3dDevice->GetTransform(D3DTS_PROJECTION, &lastProjection);

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
	g_pd3dDevice->SetStreamSource(0, g_pVB, 0, sizeof(CUSTOMVERTEX));
	g_pd3dDevice->SetIndices(g_pIB);
	g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

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

				g_pd3dDevice->SetTexture(0, texture);
				g_pd3dDevice->SetScissorRect(&r);
				g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, pCmd->VtxOffset + globalVtxOffset, 0, (UINT)cmdList->VtxBuffer.Size, pCmd->IdxOffset + globalIdxOffset, pCmd->ElemCount / 3);
			}
		}

		globalIdxOffset += cmdList->IdxBuffer.Size;
		globalVtxOffset += cmdList->VtxBuffer.Size;
	}

	// Restore the DX9 transform
	g_pd3dDevice->SetTransform(D3DTS_WORLD, &lastWorld);
	g_pd3dDevice->SetTransform(D3DTS_VIEW, &lastView);
	g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &lastProjection);

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

	g_pd3dDevice = device;
	g_pd3dDevice->AddRef();
	return true;
}

static void ImGui_ImplDX9_InvalidateDeviceObjects();

static void ImGui_ImplDX9_Shutdown()
{
	ImGui_ImplDX9_InvalidateDeviceObjects();

	if (g_pd3dDevice)
	{
		g_pd3dDevice->Release();
		g_pd3dDevice = nullptr;
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
	if (g_pd3dDevice->CreateTexture(width, height, 1, D3DUSAGE_DYNAMIC, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &g_FontTexture, nullptr) < 0)
		return false;

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
	if (!g_pd3dDevice)
		return false;
	if (!ImGui_ImplDX9_CreateFontsTexture())
		return false;

	return true;
}

static void ImGui_ImplDX9_InvalidateDeviceObjects()
{
	if (!g_pd3dDevice)
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
}

static void ImGui_ImplDX9_NewFrame()
{
	if (!g_FontTexture)
		ImGui_ImplDX9_CreateDeviceObjects();
}

//============================================================================

static bool ImGui_ImplWin32_Init(HWND hWnd)
{
	if (!::QueryPerformanceFrequency((LARGE_INTEGER*)&g_TicksPerSecond))
		return false;
	if (!::QueryPerformanceCounter((LARGE_INTEGER*)&g_Time))
		return false;

	// Setup backend-end capabilities flags
	g_hWnd = (HWND)hWnd;
	ImGuiIO& io = ImGui::GetIO();
	io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;         // We can honor GetMouseCursor() values (optional)
	io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;          // We can honor io.WantSetMousePos requests (optional, rarely used)
	io.BackendPlatformName = "imgui_impl_win32";
	io.ImeWindowHandle = hWnd;

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
	g_hWnd = nullptr;
}

static bool ImGui_ImplWin32_UpdateMouseCursor()
{
	ImGuiIO& io = ImGui::GetIO();
	if (io.ConfigFlags & ImGuiConfigFlags_NoMouseCursorChange)
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

static void ImGui_ImplWin32_UpdateMousePos()
{
	ImGuiIO& io = ImGui::GetIO();

	// Set OS mouse position if requested (rarely used, only when ImGuiConfigFlags_NavEnableSetMousePos is enabled by user)
	if (io.WantSetMousePos)
	{
		POINT pos = { (int)io.MousePos.x, (int)io.MousePos.y };
		::ClientToScreen(g_hWnd, &pos);
		::SetCursorPos(pos.x, pos.y);
	}

	// Set mouse position
	io.MousePos = ImVec2(-FLT_MAX, -FLT_MAX);
	POINT pos;

	if (HWND activeWindow = ::GetForegroundWindow())
	{
		if (activeWindow == g_hWnd || ::IsChild(activeWindow, g_hWnd))
		{
			if (::GetCursorPos(&pos) && ::ScreenToClient(g_hWnd, &pos))
				io.MousePos = ImVec2((float)pos.x, (float)pos.y);
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
	case WM_KEYDOWN:
	case WM_SYSKEYDOWN:
		if (wParam < 256)
			io.KeysDown[wParam] = true;
		return 0;

	case WM_KEYUP:
	case WM_SYSKEYUP:
		if (wParam < 256)
			io.KeysDown[wParam] = false;
		return 0;

	case WM_CHAR:
		// You can also use ToAscii()+GetKeyboardState() to retrieve characters.
		if (wParam > 0 && wParam < 0x10000)
			io.AddInputCharacter((unsigned int)wParam);
		return 0;

	case WM_SETCURSOR:
		if (LOWORD(lParam) == HTCLIENT && ImGui_ImplWin32_UpdateMouseCursor())
			return 1;
		return 0;
	}

	return 0;
}

//============================================================================

void InitializeImGui(IDirect3DDevice9* device)
{
	ImGui::CreateContext();

	ImGuiIO& io = ImGui::GetIO();
	//io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;

	fmt::format_to(ImGuiSettingsFile, "{}/MacroQuest_Overlay.ini", mq::internal_paths::Config.c_str());
	io.IniFilename = &ImGuiSettingsFile[0];

	// Retrieve window handle from device
	D3DDEVICE_CREATION_PARAMETERS params;
	device->GetCreationParameters(&params);

	// Initialize the platform backend and renderer bindings
	ImGui_ImplWin32_Init(params.hFocusWindow);
	ImGui_ImplDX9_Init(device);

	// TODO: Setup style and fonts
}

void ShutdownImGui()
{
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();

	ImGui::DestroyContext();
}

void InvalidateDeviceObjects()
{
	ImGui_ImplDX9_InvalidateDeviceObjects();
	g_bImGuiReady = false;
}

bool CreateDeviceObjects()
{
	g_bImGuiReady = ImGui_ImplDX9_CreateDeviceObjects();
	return g_bImGuiReady;
}

void RenderImGui()
{
	if (!g_bImGuiReady)
		return;
	if (!g_bRenderImGui)
		return;

	// This is loading/transitioning screen
	if (gGameState == GAMESTATE_LOGGINGIN)
		return;

	// Begin a new frame
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	// Update the ui state
	UpdateOverlayUI();

	// Render the ui
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}

//============================================================================

} // namespace imgui

//============================================================================

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
				DebugSpewAlways("Detected a change in the rendering device. Attempting to recover.");
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
			return Reset_Trampoline(pPresentationParameters);
		}

		gbDeviceAcquired = false;

		imgui::InvalidateDeviceObjects();

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
		if (GetThisDevice() != gpD3D9Device)
		{
			return EndScene_Trampoline();
		}

		// When TestCooperativeLevel returns all good, then we can reinitialize.
		// This will let the renderer control our flow instead of having to
		// poll for the state ourselves.
		if (!gbDeviceAcquired && imgui::g_pd3dDevice)
		{
			HRESULT result = GetThisDevice()->TestCooperativeLevel();

			if (result == D3D_OK)
			{
				gbDeviceAcquired = true;

				if (DetectResetDeviceHook())
				{
					imgui::InvalidateDeviceObjects();
				}

				imgui::CreateDeviceObjects();
			}
		}

		// Perform the render within a stateblock so we don't upset the
		// rest of the rendering pipeline
		if (gbDeviceAcquired)
		{
			IDirect3DStateBlock9* stateBlock = nullptr;
			gpD3D9Device->CreateStateBlock(D3DSBT_ALL, &stateBlock);

			imgui::RenderImGui();

			stateBlock->Apply();
			stateBlock->Release();
		}

		return EndScene_Trampoline();
	}
};
DETOUR_TRAMPOLINE_EMPTY(HRESULT RenderHooks::Reset_Trampoline(D3DPRESENT_PARAMETERS* pPresentationParameters));
DETOUR_TRAMPOLINE_EMPTY(HRESULT RenderHooks::BeginScene_Trampoline());
DETOUR_TRAMPOLINE_EMPTY(HRESULT RenderHooks::EndScene_Trampoline());

// Mouse hook prevents mouse events from reaching EQ when imgui captures
// the mouse. Needed because ImGui uses win32 events but EQ uses direct input.
DETOUR_TRAMPOLINE_EMPTY(void ProcessMouseEvents_Trampoline());
void ProcessMouseEvents_Detour()
{
	// Only process the mouse events if we are the foreground window.
	if (!gbInForeground)
	{
		ProcessMouseEvents_Trampoline();
		return;
	}

	if (ImGui::GetCurrentContext() != nullptr)
	{
		ImGuiIO& io = ImGui::GetIO();

		// Read mouse state from direct input
		DIDEVICEOBJECTDATA data[128];
		DWORD num = 128;

		HRESULT hr = (*EQADDR_DIMOUSE)->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), data, &num,
			io.WantCaptureMouse ? 0 : DIGDD_PEEK);
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
					io.MouseDown[d.dwOfs - DIMOFS_BUTTON0] = (d.dwData & 0x80) != 0;
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

		if (io.WantCaptureMouse)
		{
			(*gMouseState)->InWindow = 0;
			gbFlushNextMouse = true;

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

// Forwards events to ImGui. If ImGui consumes the event, we won't pass it to the game.
DETOUR_TRAMPOLINE_EMPTY(LRESULT WINAPI WndProc_Trampoline(HWND, UINT, WPARAM, LPARAM));
LRESULT WINAPI WndProc_Detour(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (imgui::g_pd3dDevice)
	{
		if (imgui::ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
			return 1;

		if (msg == WM_KEYDOWN && ImGui::GetCurrentContext() != nullptr)
		{
			// We need to send an AddInputCharacter because WM_CHAR does not get sent by EQ.
			BYTE keyState[256];

			if (GetKeyboardState(keyState) == 1)
			{
				uint16_t character = 0;

				if (ToAscii(wParam, (lParam & 0x1ff0000) > 16, keyState, &character, 0) == 1)
				{
					ImGuiIO& io = ImGui::GetIO();

					io.AddInputCharacter(character);
				}
			}
		}
	}

	return WndProc_Trampoline(hWnd, msg, wParam, lParam);
}

class CascadeItemKeyBind : public CascadeItemCommandBase
{
public:
	CascadeItemKeyBind(int icon, const char* text, const char* keybind)
	{
		m_icon = icon;
		m_text = text;
		m_keyBind = keybind;

		KeyCombo combo;
		if (GetMQ2KeyBind(keybind, false, combo) && !combo.IsEmpty())
		{
			m_text = m_text + " <" + combo.GetTextDescription() + ">";
		}
	}

	~CascadeItemKeyBind()
	{

	}

	void ExecuteCommand() override
	{
		PressMQ2KeyBind(m_keyBind, false);
	}

	CXStr GetTooltip() const override { return m_text; }

private:
	const char* m_keyBind;
};

DETOUR_TRAMPOLINE_EMPTY(CascadeItemArray* CreateCascadeMenuItems_Trampoline());
CascadeItemArray* CreateCascadeMenuItems_Detour()
{
	CascadeItemArray* array = CreateCascadeMenuItems_Trampoline();

	// Create Submenu Item
	CascadeItemSubMenu* mq2Menu = eqNew<CascadeItemSubMenu>();
	mq2Menu->SetIcon(21);
	mq2Menu->SetText("MacroQuest 2");

	CascadeItemArray* itemArray = eqNew<CascadeItemArray>();
	itemArray->Add(eqNew<CascadeItemKeyBind>(2, "Toggle Debug UI", "TOGGLE_DEBUG_UI"));

	mq2Menu->SetItems(itemArray);

	// Prepend our MQ2 Menu Item to the cascade menu.
	array->InsertElement(0, mq2Menu);

	CascadeItemSeparator* sep = eqNew<CascadeItemSeparator>();
	array->InsertElement(1, sep);

	return array;
}

void InstallCascadeMenuItems()
{
	EzDetour(__CreateCascadeMenuItems, CreateCascadeMenuItems_Detour, CreateCascadeMenuItems_Trampoline);

	if (pEQMainWnd)
	{
		pEQMainWnd->UpdateCascadeMenuItems();
	}
}

void RemoveCascadeMenuItems()
{
	RemoveDetour(__CreateCascadeMenuItems);

	if (pEQMainWnd)
	{
		pEQMainWnd->UpdateCascadeMenuItems();
	}
}

static bool InstallD3D9Hooks()
{
	bool success = false;

	WCHAR lpD3D9Path[MAX_PATH];
	SHGetFolderPathW(nullptr, CSIDL_SYSTEM, nullptr, SHGFP_TYPE_CURRENT, lpD3D9Path);
	wcscat_s(lpD3D9Path, MAX_PATH, L"\\d3d9.dll");

	// Acquire the address of the virtual function table by creating an instance of IDirect3DDevice9Ex.
	if (ghD3D9Module = LoadLibraryW(lpD3D9Path))
	{
		D3D9CREATEEXPROC d3d9CreateEx = (D3D9CREATEEXPROC)GetProcAddress(ghD3D9Module, "Direct3DCreate9Ex");
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

		IDirect3DDevice9Ex* deviceEx;
		hResult = d3d9ex->CreateDeviceEx(
			D3DADAPTER_DEFAULT,
			D3DDEVTYPE_NULLREF,
			nullptr,
			D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_NOWINDOWCHANGES,
			&pp, nullptr, &deviceEx);

		if (SUCCEEDED(hResult))
		{
			success = true;

			// IDirect3DDevice9 virtual function hooks
			DWORD* d3dDevice_vftable = *(DWORD**)deviceEx;

			InstallDetour(d3dDevice_vftable[0x29], &RenderHooks::BeginScene_Detour,
				&RenderHooks::BeginScene_Trampoline, "d3dDevice_BeginScene");
			InstallDetour(d3dDevice_vftable[0x2a], &RenderHooks::EndScene_Detour,
				&RenderHooks::EndScene_Trampoline, "d3dDevice_EndScene");

			deviceEx->Release();
		}
		else
		{
			DebugSpewAlways("InstallD3D9Hooks: failed to CreateDeviceEx. Result: %x", hResult);
		}

		// restore floating point rounding state
		fesetround(round);

		d3d9ex->Release();
	}

	return success;
}

enum class eOverlayHookStatus
{
	Success,
	Failed,
	MissingDevice,
};

static eOverlayHookStatus InitializeHooks()
{
	if (gbHooksInstalled)
	{
		if (!gpD3D9Device)
		{
			return eOverlayHookStatus::MissingDevice;
		}

		return eOverlayHookStatus::Success;
	}

	if (!InstallD3D9Hooks())
	{
		DebugSpewAlways("Failed to hook DirectX, We won't be able to render into the game!");
		return eOverlayHookStatus::Failed;
	}

	// Intercept mouse events
	InstallDetour(__ProcessMouseEvents, ProcessMouseEvents_Detour, ProcessMouseEvents_Trampoline, "__ProcessMouseEvents");

	// Intercept mouse wheel events
	InstallDetour(__HandleMouseWheel, HandleMouseWheel_Detour, HandleMouseWheel_Trampoline, "__HandleMouseWheel");

	// Intercept keyboard events
	InstallDetour(__ProcessKeyboardEvents, ProcessKeyboardEvents_Detour, ProcessKeyboardEvents_Trampoline, "__ProcessKeyboardEvents");

	// Hook the main window proc.
	InstallDetour(__WndProc, WndProc_Detour, WndProc_Trampoline, "__WndProc");

	gbHooksInstalled = true;
	return !gpD3D9Device ? eOverlayHookStatus::MissingDevice : eOverlayHookStatus::Success;
}

static void DoToggleDebugUI(const char* name, bool down)
{
	if (down)
	{
		imgui::g_bRenderImGui = !imgui::g_bRenderImGui;
	}
}

void InitializeMQ2Overlay()
{
	auto status = InitializeHooks();

	if (status != eOverlayHookStatus::Success)
	{
		gbRetryHooks = (status == eOverlayHookStatus::MissingDevice);
		gbInitializationFailed = (status == eOverlayHookStatus::Failed);
		return;
	}

	// Init settings
	imgui::g_bRenderImGui = GetPrivateProfileBool("MacroQuest", "RenderImGui", imgui::g_bRenderImGui, mq::internal_paths::MQini);

	if (gbWriteAllConfig)
	{
		WritePrivateProfileBool("MacroQuest", "RenderImGui", imgui::g_bRenderImGui, mq::internal_paths::MQini);
	}

	imgui::InitializeImGui(gpD3D9Device);
	AddMQ2KeyBind("TOGGLE_DEBUG_UI", DoToggleDebugUI);
	InstallCascadeMenuItems();
}

void ShutdownMQ2Overlay()
{
	if (!gbHooksInstalled)
		return;

	RemoveDetours();
	gbHooksInstalled = false;
	gHooks.clear();

	RemoveCascadeMenuItems();
	RemoveMQ2KeyBind("TOGGLE_DEBUG_UI");
	imgui::ShutdownImGui();

	if (gpD3D9Device)
	{
		gpD3D9Device->Release();
		gpD3D9Device = nullptr;
	}

	if (ghD3D9Module)
	{
		FreeLibrary(ghD3D9Module);
		ghD3D9Module = nullptr;
	}
}

void PulseMQ2Overlay()
{
	if (gbRetryHooks)
	{
		gbRetryHooks = false;

		InitializeMQ2Overlay();
	}
}

void SetOverlayVisible(bool visible)
{
	imgui::g_bRenderImGui = visible;
}

static void UpdateOverlayUI()
{
	ImGui::ShowDemoWindow();

	ImGui::Begin("Test");

	ImGui::LabelText("GameState", "%d", gGameState);

	ImGui::End();
}

} // namespace mq
