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

#include "pch.h"
#include "eqlib/BuildType.h"

#if HAS_DIRECTX_9

#include "GraphicsEngine.h"
#include "ImGuiBackend.h"
#include "Logging.h"

#include <d3d9.h>
#include <wil/com.h>
#include <cfenv>

#pragma comment(lib, "d3d9")
#ifdef _DEBUG
#pragma comment(lib, "d3dx9d")
#else
#pragma comment(lib, "d3dx9")
#endif

namespace mq {

// The global direct 3d device that we are using. This belongs to EQ, so we
// need to hook into it to understand when states change.

//============================================================================

static uintptr_t gResetDeviceAddress = 0;
static int s_numBeginSceneCalls = 0;
static bool s_enableImGuiDocking = true;

using D3D9CREATEEXPROC = HRESULT(WINAPI*)(UINT, IDirect3D9Ex**);

class ImGuiRenderDebugDX9;
class RendererDX9Hooks;

class MQGraphicsEngineDX9 : public MQGraphicsEngine
{
public:
	MQGraphicsEngineDX9();
	~MQGraphicsEngineDX9();

	virtual void Initialize() override;
	virtual void Shutdown() override;

	virtual OverlayHookStatus InitializeOverlayHooks() override;
	virtual void ImGuiRenderDebug_UpdateImGui() override;

	virtual void ImGui_DrawFrame() override;
	virtual void ImGui_RenderDrawData() override;

	// Install hooks on actual instance of the device once we have it.
	bool DetectResetDeviceHook(void* thisPtr);

	// Handle the logic of the EndScene hook
	HRESULT EndScene_Hook(RendererDX9Hooks* hooks);

	virtual void InitializeImGui_Internal() override;
	virtual void ShutdownImGui_Internal() override;
	virtual void InvalidateDeviceObjects_Internal() override;
	virtual void CreateDeviceObjects_Internal() override;
	virtual void UpdateScene_Internal() override;
	virtual void PostEndScene_Internal() override;
	virtual void OnUpdateFrame_Internal() override;

	virtual bool IsFullScreen() const override;

private:
	bool InstallHooks();

	ImGuiRenderDebugDX9* m_renderDebug = nullptr;
	int m_renderDebugCallbacksId = -1;
};

static MQGraphicsEngineDX9* s_gfxEngine = nullptr;

class RendererDX9Hooks
{
public:
	//------------------------------------------------------------------------
	// d3d9 hooks

	// this is only valid during a d3d9 hook detour
	IDirect3DDevice9* GetThisDevice() { return reinterpret_cast<IDirect3DDevice9*>(this); }

	DETOUR_TRAMPOLINE_DEF(HRESULT WINAPI, Reset_Trampoline, (D3DPRESENT_PARAMETERS*))
	HRESULT WINAPI Reset_Detour(D3DPRESENT_PARAMETERS* pPresentationParameters)
	{
		if (gpD3D9Device != GetThisDevice())
		{
			LOG_INFO("IDirect3DDevice9::Reset hook: instance does not match acquired device, skipping.");
			return Reset_Trampoline(pPresentationParameters);
		}

		LOG_INFO("IDirect3DDevice9::Reset hook: device instance is the acquired device.");
		s_gfxEngine->InvalidateDeviceObjects();

		return Reset_Trampoline(pPresentationParameters);
	}

	DETOUR_TRAMPOLINE_DEF(HRESULT WINAPI, BeginScene_Trampoline, ())
	HRESULT WINAPI BeginScene_Detour()
	{
		// Whenever a BeginScene occurs, we know that this is the device we want to use.
		gpD3D9Device = GetThisDevice();
		s_numBeginSceneCalls++;

		return BeginScene_Trampoline();
	}

	DETOUR_TRAMPOLINE_DEF(HRESULT WINAPI, EndScene_Trampoline, ())
	HRESULT WINAPI EndScene_Detour()
	{
		IDirect3DDevice9* thisDevice = GetThisDevice();

		// Don't try to use the device if it changed between BeginScene and EndScene.
		if (thisDevice != gpD3D9Device || !gpD3D9Device)
		{
			return EndScene_Trampoline();
		}

		return s_gfxEngine->EndScene_Hook(this);
	}
};

// Install hooks on actual instance of the device once we have it.
bool MQGraphicsEngineDX9::DetectResetDeviceHook(void* thisPtr)
{
	bool changed = false;

	// IDirect3DDevice9 virtual function hooks
	uintptr_t* d3dDevice_vftable = *(uintptr_t**)thisPtr;

	uintptr_t resetDevice = d3dDevice_vftable[0x10];

	if (resetDevice != gResetDeviceAddress)
	{
		if (gResetDeviceAddress != 0)
		{
			LOG_DEBUG("Detected a change in the rendering device. Attempting to recover.");
		}

		gResetDeviceAddress = resetDevice;

		InstallDetour(d3dDevice_vftable[0x10], &RendererDX9Hooks::Reset_Detour, RendererDX9Hooks::Reset_Trampoline_Ptr, "d3dDevice_Reset");

		changed = true;
	}

	return changed;
}

HRESULT MQGraphicsEngineDX9::EndScene_Hook(RendererDX9Hooks* hooks)
{
	// Prevent re-entrancy. This was happening due to the mumble overlay.
	static bool sbInEndSceneDetour = false;
	if (sbInEndSceneDetour)
	{
		return hooks->EndScene_Trampoline();
	}

	bool isMainRenderTarget = false;

	// Make sure that we're hooking the main render target
	wil::com_ptr_nothrow<IDirect3DSurface9> backBuffer;
	HRESULT hr = gpD3D9Device->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backBuffer);
	if (hr == D3D_OK)
	{
		wil::com_ptr_nothrow<IDirect3DSurface9> renderTarget = nullptr;
		HRESULT hr = gpD3D9Device->GetRenderTarget(0, &renderTarget);
		if (hr == D3D_OK)
		{
			isMainRenderTarget = renderTarget == backBuffer;
		}
	}

	sbInEndSceneDetour = true;

	if (isMainRenderTarget)
	{
		// Check if a full screen mode change occurred before this frame.
		// If it did, we should not render, and instead re-initialize imgui.
		if (test_and_set(m_lastFullScreenState, IsFullScreen()))
		{
			// For some reason, maybe due to a bug, toggling viewports off and
			// then calling CreateDeviceObjects will cause it to still create
			// the additional swap chains, which causes errors. So instead of
			// disabling viewports, we are simply rebooting imgui.
			m_needResetOverlay = true;
		}
		// When TestCooperativeLevel returns all good, then we can reinitialize.
		// This will let the renderer control our flow instead of having to
		// poll for the state ourselves.
		else if (!m_deviceAcquired)
		{
			if (m_resetOverlayFrameDelay == 0)
			{
				HRESULT result = hooks->GetThisDevice()->TestCooperativeLevel();

				if (result == D3D_OK)
				{
					LOG_INFO("IDirect3DDevice9::EndScene: TestCooperativeLevel was successful, reacquiring device.");

					ImGui_Initialize();

					if (DetectResetDeviceHook(hooks))
					{
						InvalidateDeviceObjects();
					}

					CreateDeviceObjects();
				}
			}
			else
			{
				--m_resetOverlayFrameDelay;
			}
		}

		// Perform the render within a stateblock so we don't upset the
		// rest of the rendering pipeline
		if (m_deviceAcquired)
		{
			PostUpdateScene();
		}
	}

	HRESULT result = hooks->EndScene_Trampoline();

	if (isMainRenderTarget && m_deviceAcquired)
	{
		PostEndScene();
	}

	sbInEndSceneDetour = false;
	return result;
}

//============================================================================

#pragma region Render Debugger

class ImGuiRenderDebugDX9
{
	static inline D3DCAPS9 s_caps;

	struct RenderTargetInfo
	{
		wil::com_ptr_nothrow<IDirect3DTexture9> texture;

		void* surface = nullptr;         // just the address of the target surface
		bool isBackBuffer = false;
		D3DSURFACE_DESC surfaceDesc;

		bool active = false;
		HRESULT status = S_OK;

		RenderTargetInfo()
		{
		}

		~RenderTargetInfo()
		{
		}
	};
	std::vector<RenderTargetInfo> m_renderTargets;
	bool m_active = false;

public:
	ImGuiRenderDebugDX9()
	{
	}

	~ImGuiRenderDebugDX9()
	{
		m_renderTargets.clear();
	}

	void CreateObjects()
	{
	}

	void InvalidateObjects()
	{
		m_renderTargets.clear();
	}

	void Render()
	{
	}

	void NewFrame()
	{
		for (RenderTargetInfo& info : m_renderTargets)
		{
			info.active = false;
		}
	}

	void DrawSurfaceTexture(ImTextureID my_tex_id, float my_tex_w, float my_tex_h)
	{
		auto& io = ImGui::GetIO();
		ImVec2 pos = ImGui::GetCursorScreenPos();
		ImVec4 tint_col = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);   // No tint
		ImVec4 border_col = ImVec4(1.0f, 1.0f, 1.0f, 0.5f); // 50% opaque white
		const float preview_w = std::min(my_tex_w, 256.f);
		const float preview_h = (preview_w / my_tex_w) * my_tex_h;
		ImGui::Image(my_tex_id, ImVec2(preview_w, preview_h), ImVec2(0, 0), ImVec2(1, 1), tint_col,
			border_col);
		float region_sz = 256.0f;

		if (ImGui::IsItemHovered()
			&& my_tex_w >= region_sz
			&& my_tex_h >= region_sz)
		{
			ImGui::BeginTooltip();

			float region_x = ((io.MousePos.x - pos.x) * (my_tex_w / preview_w)) - region_sz * 0.5f;
			float region_y = ((io.MousePos.y - pos.y) * (my_tex_h / preview_h)) - region_sz * 0.5f;

			if (region_x < 0.0f) { region_x = 0.0f; }
			else if (region_x > my_tex_w - region_sz) { region_x = my_tex_w - region_sz; }
			if (region_y < 0.0f) { region_y = 0.0f; }
			else if (region_y > my_tex_h - region_sz) { region_y = my_tex_h - region_sz; }

			ImGui::Text("Min: (%.2f, %.2f)", region_x, region_y);
			ImGui::Text("Max: (%.2f, %.2f)", region_x + region_sz, region_y + region_sz);
			ImVec2 uv0 = ImVec2((region_x + 0) / my_tex_w, (region_y + 0) / my_tex_h);
			ImVec2 uv1 = ImVec2((region_x + region_sz) / my_tex_w, (region_y + region_sz) / my_tex_h);

			float zoom = 1.0f;
			ImGui::Image(my_tex_id, ImVec2(region_sz * zoom, region_sz * zoom), uv0, uv1, tint_col, border_col);
			ImGui::EndTooltip();
		}
	}

	void RenderImGui()
	{
		m_active = true;
		ImGui::Text("Num BeginScene Calls: %d", s_numBeginSceneCalls);

		auto& io = ImGui::GetIO();
		ImVec2 pos = ImGui::GetCursorScreenPos();

		for (RenderTargetInfo& info : m_renderTargets)
		{
			char szLabel[256];
			sprintf_s(szLabel, "%s: %p (%d x %d)", info.isBackBuffer ? "Back Buffer" : "Render Target", info.surface, info.surfaceDesc.Width, info.surfaceDesc.Height);
			if (!info.active)
				strcat_s(szLabel, " (Inactive)");

			char szId[256];
			sprintf_s(szId, "##%p", info.surface);
			strcat_s(szLabel, szId);

			if (ImGui::CollapsingHeader(szLabel))
			{
				ImGui::Text("Format: %d", info.surfaceDesc.Format);
				ImGui::Text("Type: %d", info.surfaceDesc.Type);
				ImGui::Text("Usage: %d", info.surfaceDesc.Usage);

				char poolName[32];
				switch (info.surfaceDesc.Pool)
				{
				case D3DPOOL_DEFAULT: strcpy_s(poolName, "D3DPOOL_DEFAULT"); break;
				case D3DPOOL_MANAGED: strcpy_s(poolName, "D3DPOOL_MANAGED"); break;
				case D3DPOOL_SYSTEMMEM: strcpy_s(poolName, "D3DPOOL_SYSTEMMEM"); break;
				case D3DPOOL_SCRATCH: strcpy_s(poolName, "D3DPOOL_SCRATCH"); break;
				default: sprintf_s(poolName, "Unknown (%d)", info.surfaceDesc.Pool); break;
				}
				ImGui::Text("Pool: %s", poolName);

				if (info.surfaceDesc.MultiSampleType)
					ImGui::Text("MultiSampleType: %d", info.surfaceDesc.MultiSampleType);
				if (info.surfaceDesc.MultiSampleQuality)
					ImGui::Text("MultiSampleQuality: %d", info.surfaceDesc.MultiSampleQuality);
				if (info.status != 0)
					ImGui::Text("Status: %x", info.status);

				if (info.texture)
				{
					DrawSurfaceTexture((ImTextureID)info.texture.get(), (float)info.surfaceDesc.Width, (float)info.surfaceDesc.Height);
				}
			}
		}

		if (ImGui::Button("Clear Inactive"))
		{
			m_renderTargets.erase(
				std::remove_if(m_renderTargets.begin(), m_renderTargets.end(),
					[](const auto& v) { return !v.active; }), m_renderTargets.end());
		}

		NewFrame();
	}

	RenderTargetInfo* GetRenderTargetInfo(IDirect3DSurface9* surface)
	{
		for (RenderTargetInfo& info : m_renderTargets)
		{
			if (info.surface == surface)
				return &info;
		}

		RenderTargetInfo info;
		info.surface = surface;
		surface->GetDesc(&info.surfaceDesc);

		m_renderTargets.push_back(info);
		return &m_renderTargets[m_renderTargets.size() - 1];
	}

	void UpdateSurface(const wil::com_ptr_nothrow<IDirect3DSurface9>& surface, bool backBuffer)
	{
		RenderTargetInfo* info = GetRenderTargetInfo(surface.get());
		info->isBackBuffer = backBuffer;
		if (info->active)
			return; // already processed this surface this frame
		info->active = true;

		HRESULT hr = S_OK;

		if (info->texture == nullptr)
		{
			hr = gpD3D9Device->CreateTexture(info->surfaceDesc.Width, info->surfaceDesc.Height, 1, D3DUSAGE_RENDERTARGET,
				info->surfaceDesc.Format, D3DPOOL_DEFAULT, &info->texture, 0);
			info->status = hr;

			if (hr != S_OK)
				return;
		}
		// should have texture now.

		wil::com_ptr_nothrow<IDirect3DSurface9> texSurface;
		hr = info->texture->GetSurfaceLevel(0, &texSurface);
		info->status = hr;
		if (hr != S_OK)
			return;

		hr = gpD3D9Device->StretchRect(surface.get(), nullptr, texSurface.get(), nullptr, D3DTEXF_LINEAR);
		info->status = hr;
	}

	void UpdateRenderTargets()
	{
		if (!m_active)
			return;

		gpD3D9Device->GetDeviceCaps(&s_caps);
		for (int i = 0; i < (int)s_caps.NumSimultaneousRTs; ++i)
		{
			wil::com_ptr_nothrow<IDirect3DSurface9> surface;

			HRESULT hr = gpD3D9Device->GetRenderTarget(i, &surface);
			if (hr == S_OK)
			{
				UpdateSurface(surface, false);
			}
		}

		UINT numSwapchains = gpD3D9Device->GetNumberOfSwapChains();
		for (UINT i = 0; i < numSwapchains; ++i)
		{
			wil::com_ptr_nothrow<IDirect3DSwapChain9> swapChain = nullptr;

			HRESULT hr = gpD3D9Device->GetSwapChain(i, &swapChain);
			if (hr == S_OK)
			{
				wil::com_ptr_nothrow<IDirect3DSurface9> surface;
				hr = swapChain->GetBackBuffer(0, D3DBACKBUFFER_TYPE_MONO, &surface);

				if (hr == S_OK)
				{
					UpdateSurface(surface, false);
				}
			}
		}

		wil::com_ptr_nothrow<IDirect3DSurface9> surface;
		HRESULT hr = gpD3D9Device->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &surface);
		if (hr == S_OK)
		{
			UpdateSurface(surface, true);
		}
	}
};

#pragma endregion

//============================================================================

MQGraphicsEngineDX9::MQGraphicsEngineDX9()
{
	s_gfxEngine = this;
}

MQGraphicsEngineDX9::~MQGraphicsEngineDX9()
{
	s_gfxEngine = nullptr;
}

void MQGraphicsEngineDX9::Initialize()
{
	MQGraphicsEngine::Initialize();

	m_renderDebug = new ImGuiRenderDebugDX9();
	m_renderDebugCallbacksId = AddRenderCallbacks({
		[this]() { m_renderDebug->CreateObjects(); },
		[this]() { m_renderDebug->InvalidateObjects(); },
		[this]() { m_renderDebug->Render(); }
	});
}

void MQGraphicsEngineDX9::Shutdown()
{
	RemoveRenderCallbacks(m_renderDebugCallbacksId);
	m_renderDebugCallbacksId = -1;

	delete m_renderDebug;
	m_renderDebug = nullptr;

	MQGraphicsEngine::Shutdown();
}

//----------------------------------------------------------------------------

void MQGraphicsEngineDX9::InitializeImGui_Internal()
{
	assert(gpD3D9Device != nullptr);

	// Retrieve window handle from device
	D3DDEVICE_CREATION_PARAMETERS params;
	gpD3D9Device->GetCreationParameters(&params);

	// Initialize the platform backend and renderer bindings
	ImGui_ImplWin32_Init(params.hFocusWindow);
	ImGui_ImplDX9_Init(gpD3D9Device);
}

void MQGraphicsEngineDX9::ShutdownImGui_Internal()
{
	ImGui_ImplDX9_Shutdown();

	gpD3D9Device = nullptr;
	gResetDeviceAddress = 0;
}

//----------------------------------------------------------------------------

void MQGraphicsEngineDX9::InvalidateDeviceObjects_Internal()
{
	ImGui_ImplDX9_InvalidateDeviceObjects();
	m_imguiReady = false;
}

void MQGraphicsEngineDX9::CreateDeviceObjects_Internal()
{
	m_imguiReady = ImGui_ImplDX9_CreateDeviceObjects();
}

void MQGraphicsEngineDX9::UpdateScene_Internal()
{
	if (s_renderCallbacks.empty())
		return;

	// Perform the render within a stateblock so we don't upset the rest
	// of the rendering pipeline
	wil::com_ptr_nothrow<IDirect3DStateBlock9> stateBlock;
	gpD3D9Device->CreateStateBlock(D3DSBT_ALL, &stateBlock);

	MQGraphicsEngine::UpdateScene_Internal();

	stateBlock->Apply();
}

void MQGraphicsEngineDX9::PostEndScene_Internal()
{
	m_renderDebug->UpdateRenderTargets();
}

void MQGraphicsEngineDX9::OnUpdateFrame_Internal()
{
	s_numBeginSceneCalls = 0;
}

OverlayHookStatus MQGraphicsEngineDX9::InitializeOverlayHooks()
{
	if (m_deviceHooksInstalled)
	{
		if (!gpD3D9Device)
		{
			return OverlayHookStatus::MissingDevice;
		}

		return OverlayHookStatus::Success;
	}

	if (!pGraphicsEngine || !pGraphicsEngine->pRender || !pGraphicsEngine->pRender->pD3DDevice)
	{
		return OverlayHookStatus::MissingDevice;
	}

	if (!InstallHooks())
	{
		DebugSpewAlways("Failed to hook DirectX, We won't be able to render into the game!");
		return OverlayHookStatus::Failed;
	}

	m_deviceHooksInstalled = true;
	m_lastGameState = gGameState;

	return !gpD3D9Device ? OverlayHookStatus::MissingDevice : OverlayHookStatus::Success;
}

bool MQGraphicsEngineDX9::IsFullScreen() const
{
	if (!gpD3D9Device)
		return false;

	// Detect full screen and disable viewports if we're in full screen mode.
	bool fullscreen = true;
	wil::com_ptr_nothrow<IDirect3DSwapChain9> pSwapChain;
	if (SUCCEEDED(gpD3D9Device->GetSwapChain(0, &pSwapChain)) && pSwapChain != nullptr)
	{
		D3DPRESENT_PARAMETERS params;
		pSwapChain->GetPresentParameters(&params);

		fullscreen = !params.Windowed;
	}

	return fullscreen;
}

void MQGraphicsEngineDX9::ImGuiRenderDebug_UpdateImGui()
{
	m_renderDebug->RenderImGui();
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

bool MQGraphicsEngineDX9::InstallHooks()
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

		wil::com_ptr_nothrow<IDirect3D9Ex> d3d9ex;
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

		wil::com_ptr_nothrow<IDirect3DDevice9> device;
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
			uintptr_t* d3dDevice_vftable = *(uintptr_t**)device.get();

			InstallDetour(d3dDevice_vftable[0x29], &RendererDX9Hooks::BeginScene_Detour, RendererDX9Hooks::BeginScene_Trampoline_Ptr, "d3dDevice_BeginScene");
			InstallDetour(d3dDevice_vftable[0x2a], &RendererDX9Hooks::EndScene_Detour, RendererDX9Hooks::EndScene_Trampoline_Ptr, "d3dDevice_EndScene");
		}

		// restore floating point rounding state
		fesetround(round);
	}

	return success;
}

MQGraphicsEngine* CreateRendererDX9()
{
	return new MQGraphicsEngineDX9();
}

void MQGraphicsEngineDX9::ImGui_DrawFrame()
{
	IDirect3DStateBlock9* stateBlock = nullptr;
	gpD3D9Device->CreateStateBlock(D3DSBT_ALL, &stateBlock);

	// Prepare the new frame
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();

	MQGraphicsEngine::ImGui_DrawFrame();

	stateBlock->Apply();
	stateBlock->Release();
}

void MQGraphicsEngineDX9::ImGui_RenderDrawData()
{
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}

} // namespace mq

#endif // HAS_DIRECTX_9
