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

#include "mq/base/Common.h"
#include "eqlib/BuildType.h"
#include "MQ2Main.h"

#include "GraphicsResources.h"

#if HAS_DIRECTX_9
#include <d3d9.h>
#endif // HAS_DIRECTX_9

#if HAS_DIRECTX_11
#include <d3d11.h>
#endif // HAS_DIRECTX_11

namespace eqlib
{
	struct BMI;
}

namespace mq {

//============================================================================

extern bool gbEnableImGuiViewports;

enum class OverlayHookStatus
{
	Success,
	Failed,
	MissingDevice,
};

// Overlay function types
using fMQCreateDeviceObjects = std::function<void()>;
using fMQInvalidateDeviceObjects = std::function<void()>;
using fMQImGuiRender = std::function<void()>;
using fMQGraphicsSceneRender = std::function<void()>;

struct MQRenderCallbacks
{
	fMQCreateDeviceObjects     CreateDeviceObjects = nullptr;
	fMQInvalidateDeviceObjects InvalidateDeviceObjects = nullptr;
	fMQGraphicsSceneRender     GraphicsSceneRender = nullptr;
};

class MQGraphicsEngine
{
public:
	MQGraphicsEngine();
	virtual ~MQGraphicsEngine();

	virtual void Initialize();
	virtual void Shutdown();

	void InvalidateDeviceObjects();
	void CreateDeviceObjects();
	void UpdateScene();
	void PostUpdateScene();
	void PostEndScene();
	void OnUpdateFrame();

	virtual OverlayHookStatus InitializeOverlayHooks() = 0;
	virtual void ImGuiRenderDebug_UpdateImGui() {}

	// Record for tracking renderer callbacks
	struct CallbackRecord
	{
		MQRenderCallbacks callbacks;
		int id;
	};

	static int AddRenderCallbacks(const MQRenderCallbacks& callbacks);
	static void RemoveRenderCallbacks(int id);

	// Some of our hooks are determined dynamically. Rather than have a variable
	// for each one, we store them in a collection of these HookInfo objects.
	struct HookInfo
	{
		std::string name;
		uintptr_t address = 0;

		std::function<void(HookInfo&)> patch = nullptr;
	};

	void InstallHook(HookInfo hi);
	void RemoveDetours();

	template <typename T>
	void InstallDetour(uintptr_t address, T detour, T& trampoline_ptr, const char* name)
	{
		HookInfo hookInfo;
		hookInfo.name = name;
		hookInfo.address = 0;
		hookInfo.patch = [&detour, address, &trampoline_ptr](HookInfo& hi)
			{
				hi.address = address;
				mq::detail::CreateDetour(hi.address, &(void*&)trampoline_ptr, *(void**)&detour, hi.name);
			};

		InstallHook(hookInfo);
	}

	void ResetOverlay() { m_needResetOverlay = true; }

protected:
	virtual void InitializeImGui_Internal() {}
	virtual void ShutdownImGui_Internal() {}
	virtual void InvalidateDeviceObjects_Internal() {}
	virtual void CreateDeviceObjects_Internal() {}
	virtual void UpdateScene_Internal();
	virtual void PostEndScene_Internal() {}
	virtual void OnUpdateFrame_Internal() {}

	virtual bool IsFullScreen() const = 0;

	void ImGui_Initialize();
	void ImGui_Shutdown();
	virtual void ImGui_DrawFrame();
	virtual void ImGui_RenderDrawData() {}

private:
	virtual void InitializeOverlay_Internal();
	virtual void ShutdownOverlay_Internal();
	void RestartOverlay();

protected:
	// List of registered callbacks. Static because singleton instance might exist before
	// class instance is created.
	static inline std::vector<std::unique_ptr<CallbackRecord>> s_renderCallbacks;

	// List of installed hooks at their address, if they are already patched in
	std::vector<HookInfo> m_hooks;

	// Indicates that the graphics device hooks are installed
	bool m_deviceHooksInstalled = false;

	// Indicates that we've successfully acquired a usable graphics device
	bool m_deviceAcquired = false;

	// Last game state, used to check for changes to the current game state
	int m_lastGameState = GAMESTATE_PRECHARSELECT;

	// Indicates that we need to reset the overlay next frame
	bool m_needResetOverlay = false;

	// Number of frames to wait before initializing
	int m_resetOverlayFrameDelay = 0;

	// Indicates that imgui is ready to be used
	bool m_imguiReady = false;
	bool m_imguiInitialized = false;

	// Last known fullscreen state.
	bool m_lastFullScreenState = false;

private:
	bool m_retryHooks = false;
	bool m_initializationFailed = false;
};

#if HAS_DIRECTX_9

MQGraphicsEngine* CreateRendererDX9();

#endif // HAS_DIRECTX_9

#if HAS_DIRECTX_11

MQGraphicsEngine* CreateRendererDX11();

#endif // HAS_DIRECTX_11

namespace engine {

void Initialize();
void Shutdown();

void ImGuiRenderDebug_UpdateImGui();
void OnUpdateFrame();

} // namespace engine

//============================================================================

class ImGuiRenderDebug
{
public:
	virtual ~ImGuiRenderDebug() {}

	virtual void CreateObjects() = 0;
	virtual void InvalidateObjects() = 0;
	virtual void Render() = 0;
	virtual void NewFrame() = 0;
	virtual void UpdateImGui() = 0;
	virtual void UpdateRenderTargets() = 0;
};

//============================================================================
// Exports

/* OVERLAY GLOBALS */

MQLIB_VAR eqlib::Direct3DDevice9* gpD3D9Device;

#if HAS_DIRECTX_11
MQLIB_VAR IDXGISwapChain* gpDXGISwapChain;
MQLIB_VAR ID3D11Device* gpD3D11Device;
#endif

MQLIB_VAR bool gbDeviceAcquired;

MQLIB_API int AddRenderCallbacks(const MQRenderCallbacks& callbacks);
MQLIB_API void RemoveRenderCallbacks(int id);

MQLIB_API void ResetOverlay();

} // namespace mq
