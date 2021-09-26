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
#include "ImGuiManager.h"
#include "ImGuiBackend.h"

#include "common/HotKeys.h"
#include "imgui/ImGuiUtils.h"

#include <imgui.h>
#include <imgui_stdlib.h>

#include <cfenv>

#include <spdlog/spdlog.h>
#include <fmt/format.h>
#include <atomic>
#include <vector>


namespace mq {

//----------------------------------------------------------------------------
// globals

// The global direct 3d device that we are using. This belongs to EQ, so we
// need to hook into it to understand when states change.
IDirect3DDevice9* gpD3D9Device = nullptr;

// Indicates that we've acquired the device and its usable
bool gbDeviceAcquired = false;

// Indicates that the graphics device hooks are installed
bool gbDeviceHooksInstalled = false;

// Indicates that we've initialized the overlay
bool gbOverlayInitialized = false;

// Indicates that we need to reset the overlay next frame
bool gbNeedResetOverlay = false;

// If true, overlay functionality is disabled
bool gbDisableOverlay = false;

// Last known full screen state
bool gbLastFullScreenState = false;

// Number of frames to wait before initializing
int gReInitFrameDelay = 0;

bool gbImGuiReady = false;

extern bool gbToggleConsoleRequested;

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

// Forward declarations
LRESULT  ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

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
bool ImGuiOverlay_HandleMouseEvent(int mouseButton, bool pressed)
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

static void InitializeImGui(IDirect3DDevice9* device)
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

	gbImGuiReady = false;
	gbInitializedImGui = false;
}

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

					InitializeImGui(gpD3D9Device);

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
		auto pMouse = (*EQADDR_DIMOUSE);

		ImGuiIO& io = ImGui::GetIO();
		bool consumeMouse = io.WantCaptureMouse;

		// Read mouse state from direct input
		DIDEVICEOBJECTDATA data[128];
		DWORD num = 128;

		HRESULT hr = pMouse->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), data, &num, DIGDD_PEEK);

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
					if (ImGuiOverlay_HandleMouseEvent(d.dwOfs - DIMOFS_BUTTON0, (d.dwData & 0x80) != 0))
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
			pMouse->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), data, &num, 0);
			return;
		}
	}

	// Its time to detour GetDeviceState and have it return the inputs from WndProc that we didn't handle.

	if (gbFlushNextMouse)
	{
		auto pMouse = (*EQADDR_DIMOUSE);

		// Flush the direct input device state so that the wheel data doesn't get
		// picked up by the game later.
		DIDEVICEOBJECTDATA data[128];
		DWORD num = 128;

		pMouse->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), data, &num, 0);

		DIMOUSESTATE2 dims;
		pMouse->GetDeviceState(sizeof(DIMOUSESTATE2), &dims);
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
	if (ImGuiManager_HandleWndProc(msg, wParam, lParam))
		return true;
	if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

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

static bool RenderImGui()
{
	using namespace imgui;

	if (!gbImGuiReady)
		return false;
	if (gbNeedResetOverlay)
		return false;
	if (!gpD3D9Device)
		return false;

	// This is loading/transitioning screen
	if (gGameState == GAMESTATE_LOGGINGIN)
		return false;

	ImGuiManager_DrawFrame();

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
	ImGui_ImplDX9_InvalidateDeviceObjects();
	gbImGuiReady = false;

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
	gbImGuiReady = ImGui_ImplDX9_CreateDeviceObjects();

	for (const auto& pCallbacks : gRenderCallbacks)
	{
		if (pCallbacks && pCallbacks->callbacks.CreateDeviceObjects)
		{
			pCallbacks->callbacks.CreateDeviceObjects();
		}
	}

	return gbImGuiReady;
}

//============================================================================

static void InitializeOverlayInternal();
static void ShutdownOverlayInternal();

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

void InitializeMQ2Overlay()
{
	if (gbOverlayInitialized)
		return;

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

	CreateImGuiContext();

	InitializeOverlayInternal();

	gbOverlayInitialized = true;
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
	if (!gbOverlayInitialized)
		return;

	RemoveDetour(__ProcessMouseEvents);
	RemoveDetour(__HandleMouseWheel);
	RemoveDetour(__ProcessKeyboardEvents);
	RemoveDetour(__WndProc);
	RemoveDetour(CParticleSystem__Render);

	ShutdownOverlayInternal();
	DestroyImGuiContext();

	gbOverlayInitialized = false;
}

void ShutdownOverlayInternal()
{
	if (!gbDeviceHooksInstalled)
		return;

	RemoveDetours();
	gbDeviceHooksInstalled = false;
	gHooks.clear();

	ShutdownImGui();

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

	ShutdownImGui();
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
	if (!gbOverlayInitialized)
		return;

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
