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
#include "GraphicsEngine.h"
#include "ImGuiBackend.h"
#include "ImGuiManager.h"
#include "MQ2DeveloperTools.h"    // For DeveloperTools_WindowInspector_HandleClick
#include "Logging.h"

#include "mq/api/RenderDoc.h"
#include "imgui/imgui_internal.h"

#include <cfenv>

using namespace eqlib;

namespace mq {

//============================================================================

static bool s_flushNextMouse = false;

// Pointer to our MQ graphics engine
static MQGraphicsEngine* s_gfxEngine = nullptr;
eqlib::Direct3DDevice9* gpD3D9Device = nullptr;

static bool s_enableImGuiDocking = true;
bool gbEnableImGuiViewports = false;
bool gbDeviceAcquired = false;

static bool s_inObjectPreview = false;

//============================================================================
//============================================================================

bool OverlayWndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

#pragma region Hooks

// This hooks into an area of the rendering pipeline that is suitable to perform
// our own 3d rendering before the scene is completed.
class CParticleSystemHook
{
public:
	DETOUR_TRAMPOLINE_DEF(void, Render_Trampoline, ())
	void Render_Detour()
	{
		if (s_gfxEngine)
		{
			s_gfxEngine->UpdateScene();
		}

		Render_Trampoline();
	}
};

// This hooks the ResetDevice function which is called when we want to reset the device. Hooking
// this function ensures that even if our hook of the Direct3D device fails, we can still release our objects.
class CRenderHook
{
public:
	DETOUR_TRAMPOLINE_DEF(bool, ResetDevice_Trampoline, (bool))
	bool ResetDevice_Detour(bool a)
	{
		bool success = ResetDevice_Trampoline(a);

		if (!success)
		{
			LOG_DEBUG("CRender::ResetDevice: Reset failed, invalidating device objects and trying again.");

			if (s_gfxEngine)
			{
				s_gfxEngine->InvalidateDeviceObjects();
			}

			success = ResetDevice_Trampoline(a);
		}

		//LOG_DEBUG("CRender::ResetDevice: result={}", success);
		return success;
	}
};

// Mouse hook prevents mouse events from reaching EQ when imgui captures
// the mouse. Needed because ImGui uses win32 events but EQ uses direct input.
DETOUR_TRAMPOLINE_DEF(void, ProcessMouseEvents_Trampoline, ())
void ProcessMouseEvents_Detour()
{
	if (gbRenderImGui && ImGui::GetCurrentContext() != nullptr && g_pDIMouse != nullptr)
	{
		ImGuiIO& io = ImGui::GetIO();
		bool consumeMouse = io.WantCaptureMouse;

		// Read mouse state from direct input
		DIDEVICEOBJECTDATA data[128];
		DWORD num = 128;

		HRESULT hr = g_pDIMouse->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), data, &num, DIGDD_PEEK);

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
			pEverQuestInfo->MouseInClientRect = 0;
			s_flushNextMouse = true;

			// Consume the mouse state. This won't be very effective for sustained mouse clicks though.
			g_pDIMouse->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), data, &num, 0);
			return;
		}
	}

	// Its time to detour GetDeviceState and have it return the inputs from WndProc that we didn't handle.

	if (s_flushNextMouse && g_pDIMouse != nullptr)
	{
		// Flush the direct input device state so that the wheel data doesn't get
		// picked up by the game later.
		DIDEVICEOBJECTDATA data[128];
		DWORD num = 128;

		g_pDIMouse->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), data, &num, 0);

		DIMOUSESTATE2 dims;
		g_pDIMouse->GetDeviceState(sizeof(DIMOUSESTATE2), &dims);
	}

	ProcessMouseEvents_Trampoline();

	// When we flush the mouse we want it to affect the mouse wheel too. HandleMouseWheel
	// happens inside the trampoline, so we wait to clear the flag until after.
	s_flushNextMouse = false;
}

#if defined(__HandleMouseWheel_x)
// The mouse wheel hook prevents EQ from handling scroll events while imgui has the
// mouse captured.
DETOUR_TRAMPOLINE_DEF(void, HandleMouseWheel_Trampoline, (int))
void HandleMouseWheel_Detour(int offset)
{
	if (gbRenderImGui && ImGui::GetCurrentContext() != nullptr)
	{
		ImGuiIO& io = ImGui::GetIO();

		if (io.WantCaptureMouse)
		{
			return;
		}
	}

	if (!s_flushNextMouse)
	{
		HandleMouseWheel_Trampoline(offset);
	}
}
#endif // defined(__HandleMouseWheel_x)

// Keyboard hook prevents keyboard events from reaching EQ when imgui captures
// the keyboard. Needed because ImGui uses win32 events but EQ uses direct input.
DETOUR_TRAMPOLINE_DEF(uint32_t, ProcessKeyboardEvents_Trampoline, ())
uint32_t ProcessKeyboardEvents_Detour()
{
	if (gbRenderImGui && ImGui::GetCurrentContext() != nullptr)
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

class C2DPrimitiveManager_Hook
{
public:
	DETOUR_TRAMPOLINE_DEF(void, AddCachedText_Trampoline, (CTextObjectBase* obj))
	void AddCachedText_Detour(CTextObjectBase* obj)
	{
		if (this == nullptr)
			return;

		AddCachedText_Trampoline(obj);
	}

#if HAS_DIRECTX_11
	DETOUR_TRAMPOLINE_DEF(void, Render_Trampoline, (bool, bool))
	void Render_Detour(bool postProcessing, bool blind)
	{
		if (!postProcessing)
		{
			RenderDoc_ScopedEvent e(MQColor(170, 255, 255), L"Render UI");
			Render_Trampoline(postProcessing, blind);
		}
		else
		{
			Render_Trampoline(postProcessing, blind);
		}

		if (!postProcessing)
		{
			if (s_gfxEngine)
			{
				s_gfxEngine->PostUpdateScene();
			}
		
		}
	}
#endif
};

#if HAS_DIRECTX_11
class ObjectPreviewView_Hook
{
public:
	DETOUR_TRAMPOLINE_DEF(void, Render_Trampoline, ())
	void Render_Detour()
	{
		RenderDoc_ScopedEvent e(MQColor(170, 255, 255), L"ObjectPreviewView::Render");

		s_inObjectPreview = true;

		Render_Trampoline();

		s_inObjectPreview = false;
	}
};
#endif

// Forwards events to ImGui. If ImGui consumes the event, we won't pass it to the game.
DETOUR_TRAMPOLINE_DEF(LRESULT WINAPI, WndProc_Trampoline, (HWND, UINT, WPARAM, LPARAM))
LRESULT WINAPI WndProc_Detour(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (OverlayWndProcHandler(hWnd, msg, wParam, lParam))
		return 1;

	return WndProc_Trampoline(hWnd, msg, wParam, lParam);
}

#pragma endregion

bool OverlayWndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (!gbRenderImGui)
		return false;

	if (ImGuiManager_HandleWndProc(hWnd, msg, wParam, lParam))
		return true;

	return false;
}

// Returns true if this event should be "erased" from eq while not within the imgui
// capture. This lets us intercepts clicks into the game world.
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

	if (consume && mouseButton < NUM_MOUSE_BUTTONS)
	{
		// Update EQ to act like we already handled this click
		MouseConsume(mouseButton, pressed);
	}

	return consume;
}


//============================================================================

MQGraphicsEngine::MQGraphicsEngine()
{
}

MQGraphicsEngine::~MQGraphicsEngine()
{
	
}

//============================================================================

void MQGraphicsEngine::InstallHook(HookInfo hi)
{
	auto iter = std::find_if(std::begin(m_hooks), std::end(m_hooks),
		[&hi](const HookInfo& hookInfo)
		{
			return hi.name == hookInfo.name;
		});

	if (iter != std::end(m_hooks))
	{
		// hook already installed. just skip.
		return;
	}

	hi.patch(hi);
	m_hooks.push_back(std::move(hi));
}

void MQGraphicsEngine::RemoveDetours()
{
	for (HookInfo& hook : m_hooks)
	{
		if (hook.address != 0)
		{
			RemoveDetour(hook.address);
			hook.address = 0;
		}
	}
}

/* static */
int MQGraphicsEngine::AddRenderCallbacks(const MQRenderCallbacks& callbacks)
{
	// Find an unused index.
	int index = -1;
	for (int i = 0; i < (int)s_renderCallbacks.size(); ++i)
	{
		if (s_renderCallbacks[i] == nullptr)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		s_renderCallbacks.emplace_back();
		index = static_cast<int>(s_renderCallbacks.size()) - 1;
	}

	auto pCallbacks = std::make_unique<CallbackRecord>();
	pCallbacks->callbacks = callbacks;
	pCallbacks->id = index;

	// Make sure that we initialize if we're already acquired by
	// calling CreateDeviceObjects.
	if (s_gfxEngine && s_gfxEngine->m_deviceAcquired && pCallbacks->callbacks.CreateDeviceObjects)
	{
		pCallbacks->callbacks.CreateDeviceObjects();
	}

	s_renderCallbacks[index] = std::move(pCallbacks);
	return index;
}

/* static */
void MQGraphicsEngine::RemoveRenderCallbacks(int id)
{
	if (id >= 0 && id < static_cast<int>(s_renderCallbacks.size()))
	{
		// not sure if we should do this here or in the calling plugin...
		if (s_renderCallbacks[id] && s_renderCallbacks[id]->callbacks.InvalidateDeviceObjects)
		{
			s_renderCallbacks[id]->callbacks.InvalidateDeviceObjects();
		}

		s_renderCallbacks[id].reset();
	}
}

//============================================================================

void MQGraphicsEngine::Initialize()
{
	// Should this go to ImGuiManager?
	ImGuiManager_CreateContext();

	InitializeOverlay_Internal();
}

void MQGraphicsEngine::Shutdown()
{
	ShutdownOverlay_Internal();

	ImGuiManager_DestroyContext();
}

void MQGraphicsEngine::InvalidateDeviceObjects()
{
	LOG_DEBUG("MQGraphicsEngine: InvalidateDeviceObjects");

	m_deviceAcquired = false;
	gbDeviceAcquired = false;

	InvalidateDeviceObjects_Internal();

	for (const auto& pCallbacks : MQGraphicsEngine::s_renderCallbacks)
	{
		if (pCallbacks && pCallbacks->callbacks.InvalidateDeviceObjects)
		{
			pCallbacks->callbacks.InvalidateDeviceObjects();
		}
	}
}

void MQGraphicsEngine::CreateDeviceObjects()
{
	LOG_DEBUG("MQGraphicsEngine: CreateDeviceObjects");

	m_deviceAcquired = true;
	gbDeviceAcquired = true;

	CreateDeviceObjects_Internal();

	for (const auto& pCallbacks : s_renderCallbacks)
	{
		if (pCallbacks && pCallbacks->callbacks.CreateDeviceObjects)
		{
			pCallbacks->callbacks.CreateDeviceObjects();
		}
	}
}

void MQGraphicsEngine::UpdateScene()
{
	if (!m_deviceAcquired)
		return;
	if (s_inObjectPreview)
		return;

	RenderDoc_ScopedEvent e(MQColor(104, 149, 255), L"MQGraphicsEngine::UpdateScene");

	UpdateScene_Internal();
}

void MQGraphicsEngine::UpdateScene_Internal()
{
	for (const auto& pCallbacks : s_renderCallbacks)
	{
		if (pCallbacks && pCallbacks->callbacks.GraphicsSceneRender)
		{
			pCallbacks->callbacks.GraphicsSceneRender();
		}
	}
}

void MQGraphicsEngine::PostUpdateScene()
{
	if (m_deviceAcquired && m_imguiReady && !m_needResetOverlay)
	{
		if (gGameState != GAMESTATE_LOGGINGIN && gbRenderImGui)
		{
			ImGui_DrawFrame();
		}
	}
}

void MQGraphicsEngine::ImGui_DrawFrame()
{
	// we can't expect that the rounding mode is valid, and imgui respects the rounding mode so set it here and ensure that we reset it before the return
	auto round = fegetround();
	fesetround(FE_TONEAREST);

	try
	{
		ImGuiManager_NewFrame();

		ImGuiManager_DrawFrame();

		// Render the ui
		ImGui::Render();
		ImGui_RenderDrawData();

		ImGui::UpdatePlatformWindows();

		// Update and Render additional Platform Windows
		ImGuiIO& io = ImGui::GetIO();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			ImGui::RenderPlatformWindowsDefault();
		}
	}
	catch (const ImGuiException& ex)
	{
		gbManualResetRequired = true;

		WriteChatf("\arImGui Critical Failure: %s", ex.what());
		WriteChatf("\arPlugin ImGui has been temporarily paused. To resume imgui, run: \ay/mqoverlay resume\ar");
	}

	fesetround(round);
}

void MQGraphicsEngine::PostEndScene()
{
	PostEndScene_Internal();
}

void MQGraphicsEngine::OnUpdateFrame()
{
	OnUpdateFrame_Internal();

	// Reset the device hooks between game states. Some of them may alter
	// the device and we might need to start over.
	if (gGameState != m_lastGameState)
	{
		DebugSpewAlways("Game State Changed: %d, resetting device", gGameState);

		m_lastGameState = gGameState;
		RestartOverlay();
	}
	else if (m_needResetOverlay)
	{
		RestartOverlay();

		m_needResetOverlay = false;
		m_resetOverlayFrameDelay = 1;
	}

	if (m_retryHooks)
	{
		m_retryHooks = false;
		InitializeOverlay_Internal();
	}
}

//============================================================================

void MQGraphicsEngine::InitializeOverlay_Internal()
{
	OverlayHookStatus status = InitializeOverlayHooks();

	if (status != OverlayHookStatus::Success)
	{
		m_retryHooks = (status == OverlayHookStatus::MissingDevice);
		m_initializationFailed = (status == OverlayHookStatus::Failed);
	}
}

void MQGraphicsEngine::ShutdownOverlay_Internal()
{
	if (!m_deviceHooksInstalled)
		return;

	RemoveDetours();
	m_deviceHooksInstalled = false;
	m_hooks.clear();

	ImGui_Shutdown();

	m_initializationFailed = false;
	m_retryHooks = false;
	m_deviceAcquired = false;
	gbDeviceAcquired = false;

	s_flushNextMouse = false;
}

void MQGraphicsEngine::RestartOverlay()
{
	if (!m_deviceHooksInstalled)
		return;

	LOG_INFO("MQ2Overlay: Resetting overlay");

	if (m_deviceAcquired)
	{
		InvalidateDeviceObjects();
	}

	ImGui_Shutdown();
	ImGuiManager_ReloadContext();
}

void MQGraphicsEngine::ImGui_Initialize()
{
	if (m_imguiInitialized)
		return;

	// Enable Multi-Viewport / Platform windows
	m_lastFullScreenState = IsFullScreen();
	ImGui_EnableViewports(!m_lastFullScreenState && gbEnableImGuiViewports);

	// Enable Docking
	ImGui_EnableDocking(s_enableImGuiDocking);

	InitializeImGui_Internal();

	m_imguiInitialized = true;
}

void MQGraphicsEngine::ImGui_Shutdown()
{
	if (!m_imguiInitialized)
		return;

	ImGui_ImplWin32_Shutdown();
	ShutdownImGui_Internal();

	m_imguiReady = false;
	m_imguiInitialized = false;
}

//============================================================================

void engine::Initialize()
{
	if (s_gfxEngine) {
		return;
	}

	// Intercept mouse events
	EzDetour(__ProcessMouseEvents, ProcessMouseEvents_Detour, ProcessMouseEvents_Trampoline);

#if defined(__HandleMouseWheel_x)
	// Intercept mouse wheel events
	EzDetour(__HandleMouseWheel, HandleMouseWheel_Detour, HandleMouseWheel_Trampoline);
#endif

	// Intercept keyboard events
	EzDetour(__ProcessKeyboardEvents, ProcessKeyboardEvents_Detour, ProcessKeyboardEvents_Trampoline);

	// Hook the main window proc.
	EzDetour(__WndProc, WndProc_Detour, WndProc_Trampoline);

	// Hook particle render function
	EzDetour(CParticleSystem__Render, &CParticleSystemHook::Render_Detour, &CParticleSystemHook::Render_Trampoline);

	// Hook the reset device function
	EzDetour(CRender__ResetDevice, &CRenderHook::ResetDevice_Detour, &CRenderHook::ResetDevice_Trampoline);

	EzDetour(C2DPrimitiveManager__AddCachedText, &C2DPrimitiveManager_Hook::AddCachedText_Detour, &C2DPrimitiveManager_Hook::AddCachedText_Trampoline);
#if HAS_DIRECTX_11
	EzDetour(C2DPrimitiveManager__Render, &C2DPrimitiveManager_Hook::Render_Detour, &C2DPrimitiveManager_Hook::Render_Trampoline);
	EzDetour(ObjectPreviewView__Render, &ObjectPreviewView_Hook::Render_Detour, &ObjectPreviewView_Hook::Render_Trampoline);
#endif

#if HAS_DIRECTX_11
	s_gfxEngine = CreateRendererDX11();
#else
	s_gfxEngine = CreateRendererDX9();
#endif
	s_gfxEngine->Initialize();
}

void engine::Shutdown()
{
	if (!s_gfxEngine)
		return;

	s_gfxEngine->Shutdown();

	delete s_gfxEngine;
	s_gfxEngine = nullptr;

	RemoveDetour(__ProcessMouseEvents);
#if defined(__HandleMouseWheel_x)
	RemoveDetour(__HandleMouseWheel);
#endif
	RemoveDetour(__ProcessKeyboardEvents);
	RemoveDetour(__WndProc);
	RemoveDetour(CParticleSystem__Render);
	RemoveDetour(CRender__ResetDevice);
	RemoveDetour(C2DPrimitiveManager__AddCachedText);
#if HAS_DIRECTX_11
	RemoveDetour(C2DPrimitiveManager__Render);
	RemoveDetour(ObjectPreviewView__Render);
#endif
}

void engine::OnUpdateFrame()
{
	if (s_gfxEngine) {
		s_gfxEngine->OnUpdateFrame();
	}
}

void engine::ImGuiRenderDebug_UpdateImGui()
{
	if (s_gfxEngine) {
		s_gfxEngine->ImGuiRenderDebug_UpdateImGui();
	}
}

void ResetOverlay()
{
	if (s_gfxEngine) {
		s_gfxEngine->ResetOverlay();
	}
}

//============================================================================

// Exported
int AddRenderCallbacks(const MQRenderCallbacks& callbacks)
{
	return MQGraphicsEngine::AddRenderCallbacks(callbacks);
}

// Exported
void RemoveRenderCallbacks(int id)
{
	MQGraphicsEngine::RemoveRenderCallbacks(id);
}


} // namespace mq
