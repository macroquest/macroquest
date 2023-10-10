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
#include "GraphicsEngine.h"
#include "ImGuiBackend.h"
#include "ImGuiManager.h"

#include "MQ2DeveloperTools.h"    // For DeveloperTools_WindowInspector_HandleClick

#include "mq/base/Detours.h"

namespace mq {

//============================================================================

static bool s_flushNextMouse = false;

// Pointer to our MQ graphics engine
static engine::MQRendererBase* s_renderer = nullptr;

static bool s_enableImGuiDocking = true;
bool gbEnableImGuiViewports = false;

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
		if (s_renderer)
		{
			s_renderer->UpdateScene();
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
		SPDLOG_DEBUG("CRender::ResetDevice: Resetting device");

		bool success = ResetDevice_Trampoline(a);

		if (!success)
		{
			SPDLOG_DEBUG("CRender::ResetDevice: Reset failed, invalidating device objects and trying again.");

			if (s_renderer)
			{
				s_renderer->InvalidateDeviceObjects();
			}

			success = ResetDevice_Trampoline(a);
		}

		SPDLOG_DEBUG("CRender::ResetDevice: result={}", success);
		return success;
	}
};

// Mouse hook prevents mouse events from reaching EQ when imgui captures
// the mouse. Needed because ImGui uses win32 events but EQ uses direct input.
DETOUR_TRAMPOLINE_DEF(void, ProcessMouseEvents_Trampoline, ())
void ProcessMouseEvents_Detour()
{
	if (gbRenderImGui && ImGui::GetCurrentContext() != nullptr && *EQADDR_DIMOUSE != nullptr)
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
			pEverQuestInfo->MouseInClientRect = 0;
			s_flushNextMouse = true;

			// Consume the mouse state. This won't be very effective for sustained mouse clicks though.
			pMouse->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), data, &num, 0);
			return;
		}
	}

	// Its time to detour GetDeviceState and have it return the inputs from WndProc that we didn't handle.

	if (s_flushNextMouse && *EQADDR_DIMOUSE != nullptr)
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
};

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
		pEverQuestInfo->OldMouseButtons[mouseButton] = pressed;
		pEverQuestInfo->MouseButtons[mouseButton] = pressed;
	}

	return consume;
}


//============================================================================

engine::MQRendererBase::MQRendererBase()
{
}

engine::MQRendererBase::~MQRendererBase()
{
}

//============================================================================

void engine::MQRendererBase::InstallHook(HookInfo hi)
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
	m_hooks.push_back(hi);
}

void engine::MQRendererBase::RemoveDetours()
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
int engine::MQRendererBase::AddRenderCallbacks(const MQRenderCallbacks& callbacks)
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
	if (m_deviceAcquired && pCallbacks->callbacks.CreateDeviceObjects)
	{
		pCallbacks->callbacks.CreateDeviceObjects();
	}

	s_renderCallbacks[index] = std::move(pCallbacks);
	return index;
}

/* static */
void engine::MQRendererBase::RemoveRenderCallbacks(int id)
{
	if (id >= 0 && id < s_renderCallbacks.size())
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

void engine::MQRendererBase::Initialize()
{
	// Should this go to ImGuiManager?
	ImGuiManager_CreateContext();

	InitializeOverlay_Internal();
}

void engine::MQRendererBase::Shutdown()
{
	ShutdownOverlay_Internal();

	ImGuiManager_DestroyContext();
}

void engine::MQRendererBase::InvalidateDeviceObjects()
{
	SPDLOG_DEBUG("MQGraphicsEngine: InvalidateDeviceObjects");

	m_deviceAcquired = false;

	InvalidateDeviceObjects_Internal();

	for (const auto& pCallbacks : MQRendererBase::s_renderCallbacks)
	{
		if (pCallbacks && pCallbacks->callbacks.InvalidateDeviceObjects)
		{
			pCallbacks->callbacks.InvalidateDeviceObjects();
		}
	}
}

void engine::MQRendererBase::CreateDeviceObjects()
{
	SPDLOG_DEBUG("MQGraphicsEngine: CreateDeviceObjects");

	m_deviceAcquired = true;
	CreateDeviceObjects_Internal();

	for (const auto& pCallbacks : s_renderCallbacks)
	{
		if (pCallbacks && pCallbacks->callbacks.CreateDeviceObjects)
		{
			pCallbacks->callbacks.CreateDeviceObjects();
		}
	}
}

void engine::MQRendererBase::UpdateScene()
{
	if (!m_deviceAcquired)
		return;

	UpdateScene_Internal();
}

void engine::MQRendererBase::UpdateScene_Internal()
{
	for (const auto& pCallbacks : s_renderCallbacks)
	{
		if (pCallbacks && pCallbacks->callbacks.GraphicsSceneRender)
		{
			pCallbacks->callbacks.GraphicsSceneRender();
		}
	}
}

void engine::MQRendererBase::PostUpdateScene()
{
	if (m_deviceAcquired && m_imguiReady && !m_needResetOverlay)
	{
		if (gGameState != GAMESTATE_LOGGINGIN)
		{
			ImGuiManager_DrawFrame();
		}
	}
}

void engine::MQRendererBase::PostEndScene()
{
	PostEndScene_Internal();
}

void engine::MQRendererBase::OnUpdateFrame()
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

void engine::MQRendererBase::InitializeOverlay_Internal()
{
	engine::OverlayHookStatus status = InitializeOverlayHooks();

	if (status != engine::OverlayHookStatus::Success)
	{
		m_retryHooks = (status == engine::OverlayHookStatus::MissingDevice);
		m_initializationFailed = (status == engine::OverlayHookStatus::Failed);
	}
}

void engine::MQRendererBase::ShutdownOverlay_Internal()
{
	if (!m_deviceHooksInstalled)
		return;

	RemoveDetours();

	m_deviceHooksInstalled = false;
	m_hooks.clear();

	m_initializationFailed = false;
	m_retryHooks = false;

	engine::ResetInputState();
}

void engine::MQRendererBase::RestartOverlay()
{
	if (!m_deviceHooksInstalled)
		return;

	SPDLOG_INFO("MQ2Overlay: Resetting overlay");

	if (m_deviceAcquired)
	{
		InvalidateDeviceObjects();
		m_deviceAcquired = false;
	}

	ShutdownImGui();
	ImGuiManager_ReloadContext();

	gpD3D9Device = nullptr;
	gResetDeviceAddress = 0;
}

void engine::MQRendererBase::InitializeImGui()
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

void engine::MQRendererBase::ShutdownImGui()
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
	if (s_renderer) {
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

#if HAS_DIRECTX_11 && 0
	s_renderer = new MQRendererDX11();
#else
	s_renderer = CreateRendererDX9();
#endif
	s_renderer->Initialize();
}

void engine::Shutdown()
{
	if (!s_renderer)
		return;

	s_renderer->Shutdown();

	delete s_renderer;
	s_renderer = nullptr;

	RemoveDetour(__ProcessMouseEvents);
#if defined(__HandleMouseWheel_x)
	RemoveDetour(__HandleMouseWheel);
#endif
	RemoveDetour(__ProcessKeyboardEvents);
	RemoveDetour(__WndProc);
	RemoveDetour(CParticleSystem__Render);
	RemoveDetour(CRender__ResetDevice);
	RemoveDetour(C2DPrimitiveManager__AddCachedText);
}

void engine::InvalidateDeviceObjects()
{
	if (s_renderer) {
		s_renderer->InvalidateDeviceObjects();
	}
}

bool engine::CreateDeviceObjects()
{
	if (s_renderer) {
		s_renderer->CreateDeviceObjects();
	}
}

void engine::UpdateScene()
{
	if (s_renderer) {
		s_renderer->UpdateScene();
	}
}

void engine::PostUpdateScene()
{
	if (s_renderer) {
		s_renderer->PostUpdateScene();
	}
}

void engine::PostEndScene()
{
	if (s_renderer) {
		s_renderer->PostEndScene();
	}
}

void engine::ResetInputState()
{
	s_flushNextMouse = false;
}

void engine::OnUpdateFrame()
{
	if (!s_renderer) {
		s_renderer->OnUpdateFrame();
	}
}

void engine::ResetOverlay()
{
	if (s_renderer) {
		s_renderer->ResetOverlay();
	}
}

//============================================================================

// Exported
int AddRenderCallbacks(const MQRenderCallbacks& callbacks)
{
	return engine::MQRendererBase::AddRenderCallbacks(callbacks);
}

// Exported
void RemoveRenderCallbacks(int id)
{
	engine::MQRendererBase::RemoveRenderCallbacks(id);
}


} // namespace mq
