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

#include <Shlobj.h>
#include <dwmapi.h>

#ifdef DIRECTINPUT_VERSION
#undef DIRECTINPUT_VERSION
#endif
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

namespace mq {

#define IMGUI_IMPL_WIN32_DISABLE_GAMEPAD

	// Using XInput for gamepad (will load DLL dynamically)
#ifndef IMGUI_IMPL_WIN32_DISABLE_GAMEPAD
#include <xinput.h>
	typedef DWORD(WINAPI* PFN_XInputGetCapabilities)(DWORD, DWORD, XINPUT_CAPABILITIES*);
	typedef DWORD(WINAPI* PFN_XInputGetState)(DWORD, XINPUT_STATE*);
#endif
#if defined(_MSC_VER)
#pragma comment(lib, "dwmapi")  // Link with dwmapi.lib. MinGW will require linking with '-ldwmapi'
#endif

	// Allow compilation with old Windows SDK. MinGW doesn't have default _WIN32_WINNT/WINVER versions.
#ifndef WM_MOUSEHWHEEL
#define WM_MOUSEHWHEEL 0x020E
#endif
#ifndef DBT_DEVNODES_CHANGED
#define DBT_DEVNODES_CHANGED 0x0007
#endif

extern "C" HINSTANCE ghInstance;

#pragma region Platform Binding for Windows

// Implemented features:
//  [X] Platform: Clipboard support (for Win32 this is actually part of core dear imgui)
//  [X] Platform: Mouse cursor shape and visibility. Disable with 'io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange'.
//  [X] Platform: Keyboard arrays indexed using VK_* Virtual Key Codes, e.g. ImGui::IsKeyPressed(VK_SPACE).
//  [X] Platform: Gamepad support. Enabled with 'io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad'.
//  [X] Platform: Multi-viewport support (multiple windows). Enable with 'io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable'.

// CHANGELOG
// (minor and older changes stripped away, please see git history for details)
//  2021-XX-XX: Platform: Added support for multiple windows via the ImGuiPlatformIO interface.
//  2021-08-17: Calling io.AddFocusEvent() on WM_SETFOCUS/WM_KILLFOCUS messages.
//  2021-08-02: Inputs: Fixed keyboard modifiers being reported when host windo doesn't have focus.
//  2021-07-29: Inputs: MousePos is correctly reported when the host platform window is hovered but not focused (using TrackMouseEvent() to receive WM_MOUSELEAVE events).
//  2021-06-29: Reorganized backend to pull data from a single structure to facilitate usage with multiple-contexts (all g_XXXX access changed to bd->XXXX).
//  2021-06-08: Fixed ImGui_ImplWin32_EnableDpiAwareness() and ImGui_ImplWin32_GetDpiScaleForMonitor() to handle Windows 8.1/10 features without a manifest (per-monitor DPI, and properly calls SetProcessDpiAwareness() on 8.1).
//  2021-03-23: Inputs: Clearing keyboard down array when losing focus (WM_KILLFOCUS).
//  2021-02-18: Added ImGui_ImplWin32_EnableAlphaCompositing(). Non Visual Studio users will need to link with dwmapi.lib (MinGW/gcc: use -ldwmapi).
//  2021-02-17: Fixed ImGui_ImplWin32_EnableDpiAwareness() attempting to get SetProcessDpiAwareness from shcore.dll on Windows 8 whereas it is only supported on Windows 8.1.
//  2021-01-25: Inputs: Dynamically loading XInput DLL.
//  2020-12-04: Misc: Fixed setting of io.DisplaySize to invalid/uninitialized data when after hwnd has been closed.
//  2020-03-03: Inputs: Calling AddInputCharacterUTF16() to support surrogate pairs leading to codepoint >= 0x10000 (for more complete CJK inputs)
//  2020-02-17: Added ImGui_ImplWin32_EnableDpiAwareness(), ImGui_ImplWin32_GetDpiScaleForHwnd(), ImGui_ImplWin32_GetDpiScaleForMonitor() helper functions.
//  2020-01-14: Inputs: Added support for #define IMGUI_IMPL_WIN32_DISABLE_GAMEPAD/IMGUI_IMPL_WIN32_DISABLE_LINKING_XINPUT.
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

//----------------------------------------------------------------------------
// Forward Declarations
static void ImGui_ImplWin32_InitPlatformInterface();
static void ImGui_ImplWin32_ShutdownPlatformInterface();
static void ImGui_ImplWin32_UpdateMonitors();

struct ImGui_ImplWin32_Data
{
	HWND                        hWnd;
	HWND                        MouseHwnd;
	bool                        MouseTracked;
	int64_t                     Time;
	int64_t                     TicksPerSecond;
	ImGuiMouseCursor            LastMouseCursor;
	bool                        HasGamepad;
	bool                        WantUpdateHasGamepad;
	bool                        WantUpdateMonitors;

#ifndef IMGUI_IMPL_WIN32_DISABLE_GAMEPAD
	HMODULE                     XInputDLL;
	PFN_XInputGetCapabilities   XInputGetCapabilities;
	PFN_XInputGetState          XInputGetState;
#endif

	ImGui_ImplWin32_Data()
	{
		memset(this, 0, sizeof(ImGui_ImplWin32_Data));
	}
};

// Backend data stored in io.BackendPlatformUserData to allow support for multiple Dear ImGui contexts
// It is STRONGLY preferred that you use docking branch with multi-viewports (== single Dear ImGui context + multiple windows) instead of multiple Dear ImGui contexts.
// FIXME: multi-context support is not well tested and probably dysfunctional in this backend.
// FIXME: some shared resources (mouse cursor shape, gamepad) are mishandled when using multi-context.
static ImGui_ImplWin32_Data* ImGui_ImplWin32_GetBackendData()
{
	return ImGui::GetCurrentContext() ? (ImGui_ImplWin32_Data*)ImGui::GetIO().BackendPlatformUserData : NULL;
}

//----------------------------------------------------------------------------
// Functions

bool ImGui_ImplWin32_Init(void* hWnd_)
{
	HWND hWnd = (HWND)hWnd_;

	ImGuiIO& io = ImGui::GetIO();
	IM_ASSERT(io.BackendPlatformUserData == NULL && "Already initialized a platform backend!");

	INT64 perf_frequency, perf_counter;
	if (!::QueryPerformanceFrequency((LARGE_INTEGER*)&perf_frequency))
		return false;
	if (!::QueryPerformanceCounter((LARGE_INTEGER*)&perf_counter))
		return false;

	// Setup backend-end capabilities flags
	ImGui_ImplWin32_Data* bd = new ImGui_ImplWin32_Data();
	io.BackendPlatformUserData = (void*)bd;
	io.BackendPlatformName = "imgui_impl_win32";
	io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;         // We can honor GetMouseCursor() values (optional)
	io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;          // We can honor io.WantSetMousePos requests (optional, rarely used)
	io.BackendFlags |= ImGuiBackendFlags_PlatformHasViewports;    // We can create multi-viewports on the Platform side (optional)
	io.BackendFlags |= ImGuiBackendFlags_HasMouseHoveredViewport; // We can set io.MouseHoveredViewport correctly (optional, not easy).

	bd->hWnd = hWnd;
	bd->WantUpdateHasGamepad = true;
	bd->WantUpdateMonitors = true;
	bd->TicksPerSecond = perf_frequency;
	bd->Time = perf_counter;
	bd->LastMouseCursor = ImGuiMouseCursor_COUNT;

	// Our mouse update function expects PlatformHandle to be filled for the main viewport
	ImGuiViewport* main_viewport = ImGui::GetMainViewport();
	main_viewport->PlatformHandle = main_viewport->PlatformHandleRaw = (void*)bd->hWnd;
	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
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

	// Dynamically load XInput library
#ifndef IMGUI_IMPL_WIN32_DISABLE_GAMEPAD
	const char* xinput_dll_names[] =
	{
		"xinput1_4.dll",   // Windows 8+
		"xinput1_3.dll",   // DirectX SDK
		"xinput9_1_0.dll", // Windows Vista, Windows 7
		"xinput1_2.dll",   // DirectX SDK
		"xinput1_1.dll"    // DirectX SDK
	};
	for (int n = 0; n < IM_ARRAYSIZE(xinput_dll_names); n++)
	{
		if (HMODULE dll = ::LoadLibraryA(xinput_dll_names[n]))
		{
			bd->XInputDLL = dll;
			bd->XInputGetCapabilities = (PFN_XInputGetCapabilities)::GetProcAddress(dll, "XInputGetCapabilities");
			bd->XInputGetState = (PFN_XInputGetState)::GetProcAddress(dll, "XInputGetState");
			break;
		}
	}
#endif // IMGUI_IMPL_WIN32_DISABLE_GAMEPAD

	return true;
}

void ImGui_ImplWin32_Shutdown()
{
	ImGui_ImplWin32_Data* bd = ImGui_ImplWin32_GetBackendData();
	IM_ASSERT(bd != nullptr && "No platform backend to shutdown, or already shutdown?");
	ImGuiIO& io = ImGui::GetIO();
	ImGui_ImplWin32_ShutdownPlatformInterface();

	// Unload XInput library
#ifndef IMGUI_IMPL_WIN32_DISABLE_GAMEPAD
	if (bd->XInputDLL)
		::FreeLibrary(bd->XInputDLL);
#endif // IMGUI_IMPL_WIN32_DISABLE_GAMEPAD

	io.BackendPlatformName = nullptr;
	io.BackendPlatformUserData = nullptr;
	delete bd;
}

static bool ImGui_ImplWin32_UpdateMouseCursor()
{
	ImGuiIO& io = ImGui::GetIO();
	if (io.ConfigFlags & ImGuiConfigFlags_NoMouseCursorChange)
		return false;

	if (!io.WantCaptureMouse)
		return false;

	ImGuiMouseCursor imguiCursor = ImGui::GetMouseCursor();
	if (imguiCursor == ImGuiMouseCursor_None || io.MouseDrawCursor)
	{
		// Hide OS mouse cursor if imgui is drawing it or if it wants no cursor
		::SetCursor(nullptr);
	}
	else if (HCURSOR hCursor = (HCURSOR)ImGuiManager_GetCursorForImGui(imguiCursor))
	{
		::SetCursor(hCursor);
	}
	else
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
	ImGui_ImplWin32_Data* bd = ImGui_ImplWin32_GetBackendData();
	ImGuiIO& io = ImGui::GetIO();
	IM_ASSERT(bd->hWnd != 0);

	const ImVec2 mouse_pos_prev = io.MousePos;
	io.MousePos = ImVec2(-FLT_MAX, -FLT_MAX);
	io.MouseHoveredViewport = 0;

	// Obtain focused and hovered window. We forward mouse input when focused or when hovered (and no other window is capturing)
	HWND focusedWindow = ::GetForegroundWindow();
	HWND hoveredWindow = bd->MouseHwnd;
	HWND mouseWindow = nullptr;
	if (hoveredWindow && (hoveredWindow == bd->hWnd || ::IsChild(hoveredWindow, bd->hWnd) || ImGui::FindViewportByPlatformHandle((void*)hoveredWindow)))
		mouseWindow = hoveredWindow;
	else if (focusedWindow && (focusedWindow == bd->hWnd || ::IsChild(focusedWindow, bd->hWnd) || ImGui::FindViewportByPlatformHandle((void*)focusedWindow)))
		mouseWindow = focusedWindow;
	if (mouseWindow == nullptr)
		return;

	// Set OS mouse position from Dear ImGui if requested (rarely used, only when ImGuiConfigFlags_NavEnableSetMousePos is enabled by user)
	// (When multi-viewports are enabled, all Dear ImGui positions are same as OS positions)
	if (io.WantSetMousePos)
	{
		POINT pos = { (int)mouse_pos_prev.x, (int)mouse_pos_prev.y };
		if ((io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) == 0)
			::ClientToScreen(mouseWindow, &pos);
		::SetCursorPos(pos.x, pos.y);
	}

	// Set Dear ImGui mouse position from OS position
	POINT mouseScreenPos;
	if (!::GetCursorPos(&mouseScreenPos))
		return;
	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		// Multi-viewport mode: mouse position in OS absolute coordinates (io.MousePos is (0,0) when the mouse is on the upper-left of the primary monitor)
		// This is the position you can get with ::GetCursorPos() or WM_MOUSEMOVE + ::ClientToScreen(). In theory adding viewport->Pos to a client position would also be the same.
		io.MousePos = ImVec2((float)mouseScreenPos.x, (float)mouseScreenPos.y);
	}
	else
	{
		// Single viewport mode: mouse position in client window coordinates (io.MousePos is (0,0) when the mouse is on the upper-left corner of the app window)
		// This is the position you can get with ::GetCursorPos() + ::ScreenToClient() or WM_MOUSEMOVE.
		POINT mouseClientPos = mouseScreenPos;
		::ScreenToClient(bd->hWnd, &mouseClientPos);
		io.MousePos = ImVec2((float)mouseClientPos.x, (float)mouseClientPos.y);
	}

	// (Optional) When using multiple viewports: set io.MouseHoveredViewport to the viewport the OS mouse cursor is hovering.
	// Important: this information is not easy to provide and many high-level windowing library won't be able to provide it correctly, because
	// - This is _ignoring_ viewports with the ImGuiViewportFlags_NoInputs flag (pass-through windows).
	// - This is _regardless_ of whether another viewport is focused or being dragged from.
	// If ImGuiBackendFlags_HasMouseHoveredViewport is not set by the backend, imgui will ignore this field and infer the information by relying on the
	// rectangles and last focused time of every viewports it knows about. It will be unaware of foreign windows that may be sitting between or over your windows.
	if (HWND hoveredHwnd = ::WindowFromPoint(mouseScreenPos))
	{
		if (ImGuiViewport* viewport = ImGui::FindViewportByPlatformHandle((void*)hoveredHwnd))
		{
			if ((viewport->Flags & ImGuiViewportFlags_NoInputs) == 0) // FIXME: We still get our NoInputs window with WM_NCHITTEST/HTTRANSPARENT code when decorated?
				io.MouseHoveredViewport = viewport->ID;
		}
	}
}

// Gamepad navigation mapping
static void ImGui_ImplWin32_UpdateGamepads()
{
#ifndef IMGUI_IMPL_WIN32_DISABLE_GAMEPAD
	ImGuiIO& io = ImGui::GetIO();
	ImGui_ImplWin32_Data* bd = ImGui_ImplWin32_GetBackendData();
	memset(io.NavInputs, 0, sizeof(io.NavInputs));
	if ((io.ConfigFlags & ImGuiConfigFlags_NavEnableGamepad) == 0)
		return;

	// Calling XInputGetState() every frame on disconnected gamepads is unfortunately too slow.
	// Instead we refresh gamepad availability by calling XInputGetCapabilities() _only_ after receiving WM_DEVICECHANGE.
	if (bd->WantUpdateHasGamepad)
	{
		XINPUT_CAPABILITIES caps;
		bd->HasGamepad = bd->XInputGetCapabilities ? (bd->XInputGetCapabilities(0, XINPUT_FLAG_GAMEPAD, &caps) == ERROR_SUCCESS) : false;
		bd->WantUpdateHasGamepad = false;
	}

	io.BackendFlags &= ~ImGuiBackendFlags_HasGamepad;
	XINPUT_STATE xinput_state;
	if (bd->HasGamepad && bd->XInputGetState && bd->XInputGetState(0, &xinput_state) == ERROR_SUCCESS)
	{
		const XINPUT_GAMEPAD& gamepad = xinput_state.Gamepad;
		io.BackendFlags |= ImGuiBackendFlags_HasGamepad;

#define MAP_BUTTON(NAV_NO, BUTTON_ENUM)     { io.NavInputs[NAV_NO] = (gamepad.wButtons & BUTTON_ENUM) ? 1.0f : 0.0f; }
#define MAP_ANALOG(NAV_NO, VALUE, V0, V1)   { float vn = (float)(VALUE - V0) / (float)(V1 - V0); if (vn > 1.0f) vn = 1.0f; if (vn > 0.0f && io.NavInputs[NAV_NO] < vn) io.NavInputs[NAV_NO] = vn; }
		MAP_BUTTON(ImGuiNavInput_Activate, XINPUT_GAMEPAD_A);              // Cross / A
		MAP_BUTTON(ImGuiNavInput_Cancel, XINPUT_GAMEPAD_B);              // Circle / B
		MAP_BUTTON(ImGuiNavInput_Menu, XINPUT_GAMEPAD_X);              // Square / X
		MAP_BUTTON(ImGuiNavInput_Input, XINPUT_GAMEPAD_Y);              // Triangle / Y
		MAP_BUTTON(ImGuiNavInput_DpadLeft, XINPUT_GAMEPAD_DPAD_LEFT);      // D-Pad Left
		MAP_BUTTON(ImGuiNavInput_DpadRight, XINPUT_GAMEPAD_DPAD_RIGHT);     // D-Pad Right
		MAP_BUTTON(ImGuiNavInput_DpadUp, XINPUT_GAMEPAD_DPAD_UP);        // D-Pad Up
		MAP_BUTTON(ImGuiNavInput_DpadDown, XINPUT_GAMEPAD_DPAD_DOWN);      // D-Pad Down
		MAP_BUTTON(ImGuiNavInput_FocusPrev, XINPUT_GAMEPAD_LEFT_SHOULDER);  // L1 / LB
		MAP_BUTTON(ImGuiNavInput_FocusNext, XINPUT_GAMEPAD_RIGHT_SHOULDER); // R1 / RB
		MAP_BUTTON(ImGuiNavInput_TweakSlow, XINPUT_GAMEPAD_LEFT_SHOULDER);  // L1 / LB
		MAP_BUTTON(ImGuiNavInput_TweakFast, XINPUT_GAMEPAD_RIGHT_SHOULDER); // R1 / RB
		MAP_ANALOG(ImGuiNavInput_LStickLeft, gamepad.sThumbLX, -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE, -32768);
		MAP_ANALOG(ImGuiNavInput_LStickRight, gamepad.sThumbLX, +XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE, +32767);
		MAP_ANALOG(ImGuiNavInput_LStickUp, gamepad.sThumbLY, +XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE, +32767);
		MAP_ANALOG(ImGuiNavInput_LStickDown, gamepad.sThumbLY, -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE, -32767);
#undef MAP_BUTTON
#undef MAP_ANALOG
	}
#endif // #ifndef IMGUI_IMPL_WIN32_DISABLE_GAMEPAD
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
	ImGui_ImplWin32_Data* bd = ImGui_ImplWin32_GetBackendData();
	ImGui::GetPlatformIO().Monitors.resize(0);
	::EnumDisplayMonitors(nullptr, nullptr, ImGui_ImplWin32_UpdateMonitors_EnumFunc, 0);
	bd->WantUpdateMonitors = false;
}

void ImGui_ImplWin32_NewFrame()
{
	ImGuiIO& io = ImGui::GetIO();
	ImGui_ImplWin32_Data* bd = ImGui_ImplWin32_GetBackendData();
	IM_ASSERT(bd != NULL && "Did you call ImGui_ImplWin32_Init()?");

	// Setup display size (every frame to accommodate for window resizing)
	RECT rect = { 0, 0, 0, 0 };
	::GetClientRect(bd->hWnd, &rect);
	io.DisplaySize = ImVec2((float)(rect.right - rect.left), (float)(rect.bottom - rect.top));
	if (bd->WantUpdateMonitors)
		ImGui_ImplWin32_UpdateMonitors();

	// Setup time step
	INT64 currentTime;
	::QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
	io.DeltaTime = (float)(currentTime - bd->Time) / bd->TicksPerSecond;
	bd->Time = currentTime;

	// Update OS mouse position
	ImGui_ImplWin32_UpdateMousePos();

	// Update OS mouse cursor with the cursor requested by imgui
	ImGuiMouseCursor mouseCursor = io.MouseDrawCursor ? ImGuiMouseCursor_None : ImGui::GetMouseCursor();
	if (bd->LastMouseCursor != mouseCursor)
	{
		bd->LastMouseCursor = mouseCursor;
		ImGui_ImplWin32_UpdateMouseCursor();
	}

	// Update game controllers (if enabled and available)
	ImGui_ImplWin32_UpdateGamepads();
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

	// We may not have initialize yet if we reset.
	ImGui_ImplWin32_Data* bd = ImGui_ImplWin32_GetBackendData();
	if (!bd) return 0;

	ImGuiIO& io = ImGui::GetIO();

	switch (msg)
	{
	case WM_MOUSEMOVE:
		// We need to call TrackMouseEvent in order to receive WM_MOUSELEAVE events
		bd->MouseHwnd = hWnd;
		if (!bd->MouseTracked)
		{
			TRACKMOUSEEVENT tme = { sizeof(TRACKMOUSEEVENT), TME_LEAVE, hWnd, 0 };
			::TrackMouseEvent(&tme);

			bd->MouseTracked = true;
		}
		break;

	case WM_MOUSELEAVE:
		if (bd->MouseHwnd == hWnd)
			bd->MouseHwnd = nullptr;
		bd->MouseTracked = false;
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

		if (ImGuiOverlay_HandleMouseEvent(button, true))
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

		bool capture = ImGuiOverlay_HandleMouseEvent(button, false);

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

	case WM_KEYDOWN:
		// We need to send an AddInputCharacter because WM_CHAR does not get sent by EQ.
		BYTE keyState[256];

		if (GetKeyboardState(keyState) == 1)
		{
			uint16_t character = 0;

			if (ToAscii(static_cast<UINT>(wParam), static_cast<UINT>(lParam & 0x1ff0000) > 16, keyState, &character, 0) == 1)
			{
				io.AddInputCharacter(character);
			}
		}
		// fallthrough
	case WM_SYSKEYDOWN:
	case WM_KEYUP:
	case WM_SYSKEYUP:
	{
		bool down = (msg == WM_SYSKEYDOWN || msg == WM_KEYDOWN);

		if (wParam < 256)
			io.KeysDown[wParam] = down;
		if (wParam == VK_CONTROL)
			io.KeyCtrl = down;
		if (wParam == VK_SHIFT)
			io.KeyShift = down;
		if (wParam == VK_MENU)
			io.KeyAlt = down;
		return 1;
	}

	case WM_SETFOCUS:
	case WM_KILLFOCUS:
		io.AddFocusEvent(msg == WM_SETFOCUS);
		return 0;

	case WM_CHAR:
		return 0;

	case WM_SETCURSOR:
		if (LOWORD(lParam) == HTCLIENT && ImGui_ImplWin32_UpdateMouseCursor())
			return 1;
		return 0;

	case WM_DEVICECHANGE:
		if ((UINT)wParam == DBT_DEVNODES_CHANGED)
			bd->WantUpdateHasGamepad = true;
		return 0;

	case WM_DISPLAYCHANGE:
		bd->WantUpdateMonitors = true;
		return 0;

	case WM_ACTIVATE:
		// Clear any delayed mouse inputs.
		for (int i = 0; i < (int)lengthof(io.MouseDown); ++i)
			ImGuiOverlay_HandleMouseEvent(i, false);
		// Clear any delayed keyboard inputs
		for (bool& n : io.KeysDown)
			n = false;
		return 0;

	default: break;
	}

	return 0;
}

//--------------------------------------------------------------------------------------------------------
// DPI-related helpers (optional)
//--------------------------------------------------------------------------------------------------------
// - Use to enable DPI awareness without having to create an application manifest.
// - Your own app may already do this via a manifest or explicit calls. This is mostly useful for our examples/ apps.
// - In theory we could call simple functions from Windows SDK such as SetProcessDPIAware(), SetProcessDpiAwareness(), etc.
//   but most of the functions provided by Microsoft require Windows 8.1/10+ SDK at compile time and Windows 8/10+ at runtime,
//   neither we want to require the user to have. So we dynamically select and load those functions to avoid dependencies.
//---------------------------------------------------------------------------------------------------------
// This is the scheme successfully used by GLFW (from which we borrowed some of the code) and other apps aiming to be highly portable.
// ImGui_ImplWin32_EnableDpiAwareness() is just a helper called by main.cpp, we don't call it automatically.
// If you are trying to implement your own backend for your own engine, you may ignore that noise.
//---------------------------------------------------------------------------------------------------------

// Perform our own check with RtlVerifyVersionInfo() instead of using functions from <VersionHelpers.h> as they
// require a manifest to be functional for checks above 8.1. See https://github.com/ocornut/imgui/issues/4200
static BOOL _IsWindowsVersionOrGreater(WORD major, WORD minor, WORD)
{
	typedef LONG(WINAPI* PFN_RtlVerifyVersionInfo)(OSVERSIONINFOEXW*, ULONG, ULONGLONG);
	static PFN_RtlVerifyVersionInfo RtlVerifyVersionInfoFn = NULL;
	if (RtlVerifyVersionInfoFn == NULL)
		if (HMODULE ntdllModule = ::GetModuleHandleA("ntdll.dll"))
			RtlVerifyVersionInfoFn = (PFN_RtlVerifyVersionInfo)GetProcAddress(ntdllModule, "RtlVerifyVersionInfo");
	if (RtlVerifyVersionInfoFn == NULL)
		return FALSE;

	RTL_OSVERSIONINFOEXW versionInfo = { };
	ULONGLONG conditionMask = 0;
	versionInfo.dwOSVersionInfoSize = sizeof(RTL_OSVERSIONINFOEXW);
	versionInfo.dwMajorVersion = major;
	versionInfo.dwMinorVersion = minor;
	VER_SET_CONDITION(conditionMask, VER_MAJORVERSION, VER_GREATER_EQUAL);
	VER_SET_CONDITION(conditionMask, VER_MINORVERSION, VER_GREATER_EQUAL);
	return (RtlVerifyVersionInfoFn(&versionInfo, VER_MAJORVERSION | VER_MINORVERSION, conditionMask) == 0) ? TRUE : FALSE;
}

#define _IsWindowsVistaOrGreater()   _IsWindowsVersionOrGreater(HIBYTE(0x0600), LOBYTE(0x0600), 0) // _WIN32_WINNT_VISTA
#define _IsWindows8OrGreater()       _IsWindowsVersionOrGreater(HIBYTE(0x0602), LOBYTE(0x0602), 0) // _WIN32_WINNT_WIN8
#define _IsWindows8Point1OrGreater() _IsWindowsVersionOrGreater(HIBYTE(0x0603), LOBYTE(0x0603), 0) // _WIN32_WINNT_WINBLUE
#define _IsWindows10OrGreater()      _IsWindowsVersionOrGreater(HIBYTE(0x0A00), LOBYTE(0x0A00), 0) // _WIN32_WINNT_WINTHRESHOLD / _WIN32_WINNT_WIN10

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
typedef HRESULT(WINAPI* PFN_SetProcessDpiAwareness)(PROCESS_DPI_AWARENESS);                     // Shcore.lib + dll, Windows 8.1+
typedef HRESULT(WINAPI* PFN_GetDpiForMonitor)(HMONITOR, MONITOR_DPI_TYPE, UINT*, UINT*);        // Shcore.lib + dll, Windows 8.1+
typedef DPI_AWARENESS_CONTEXT(WINAPI* PFN_SetThreadDpiAwarenessContext)(DPI_AWARENESS_CONTEXT); // User32.lib + dll, Windows 10 v1607+ (Creators Update)

// Helper function to enable DPI awareness without setting up a manifest
void ImGui_ImplWin32_EnableDpiAwareness()
{
	// Make sure monitors will be updated with latest correct scaling
	if (ImGui_ImplWin32_Data* bd = ImGui_ImplWin32_GetBackendData())
		bd->WantUpdateMonitors = true;

	if (_IsWindows10OrGreater())
	{
		static HINSTANCE user32_dll = ::LoadLibraryA("user32.dll"); // Reference counted per-process
		if (PFN_SetThreadDpiAwarenessContext SetThreadDpiAwarenessContextFn = (PFN_SetThreadDpiAwarenessContext)::GetProcAddress(user32_dll, "SetThreadDpiAwarenessContext"))
		{
			SetThreadDpiAwarenessContextFn(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
			return;
		}
	}
	if (_IsWindows8Point1OrGreater())
	{
		static HINSTANCE shcore_dll = ::LoadLibraryA("shcore.dll"); // Reference counted per-process
		if (PFN_SetProcessDpiAwareness SetProcessDpiAwarenessFn = (PFN_SetProcessDpiAwareness)::GetProcAddress(shcore_dll, "SetProcessDpiAwareness"))
		{
			SetProcessDpiAwarenessFn(PROCESS_PER_MONITOR_DPI_AWARE);
			return;
		}
	}
#if _WIN32_WINNT >= 0x0600
	::SetProcessDPIAware();
#endif
}

#if defined(_MSC_VER) && !defined(NOGDI)
#pragma comment(lib, "gdi32")   // Link with gdi32.lib for GetDeviceCaps(). MinGW will require linking with '-lgdi32'
#endif

float ImGui_ImplWin32_GetDpiScaleForMonitor(void* monitor)
{
	UINT xdpi = 96, ydpi = 96;
	if (_IsWindows8Point1OrGreater())
	{
		static HINSTANCE shcore_dll = ::LoadLibraryA("shcore.dll"); // Reference counted per-process
		static PFN_GetDpiForMonitor GetDpiForMonitorFn = NULL;
		if (GetDpiForMonitorFn == NULL && shcore_dll != NULL)
			GetDpiForMonitorFn = (PFN_GetDpiForMonitor)::GetProcAddress(shcore_dll, "GetDpiForMonitor");
		if (GetDpiForMonitorFn != NULL)
		{
			GetDpiForMonitorFn((HMONITOR)monitor, MDT_EFFECTIVE_DPI, &xdpi, &ydpi);
			IM_ASSERT(xdpi == ydpi); // Please contact me if you hit this assert!
			return xdpi / 96.0f;
		}
	}

#ifndef NOGDI
	const HDC dc = ::GetDC(NULL);
	xdpi = ::GetDeviceCaps(dc, LOGPIXELSX);
	ydpi = ::GetDeviceCaps(dc, LOGPIXELSY);
	IM_ASSERT(xdpi == ydpi); // Please contact me if you hit this assert!
	::ReleaseDC(NULL, dc);
#endif
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

// Helper structure we store in the void* RenderUserData field of each ImGuiViewport to easily retrieve our backend data.
struct ImGui_ImplWin32_ViewportData
{
	HWND    Hwnd;
	bool    HwndOwned;
	DWORD   DwStyle;
	DWORD   DwExStyle;

	ImGui_ImplWin32_ViewportData() { Hwnd = nullptr; HwndOwned = false;  DwStyle = DwExStyle = 0; }
	~ImGui_ImplWin32_ViewportData() { IM_ASSERT(Hwnd == nullptr); }
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
	ImGui_ImplWin32_ViewportData* vd = new ImGui_ImplWin32_ViewportData();
	viewport->PlatformUserData = vd;

	// Select style and parent window
	ImGui_ImplWin32_GetWin32StyleFromViewportFlags(viewport->Flags, &vd->DwStyle, &vd->DwExStyle);
	HWND parentWindow = nullptr;
	if (viewport->ParentViewportId != 0)
		if (ImGuiViewport* parentViewport = ImGui::FindViewportByID(viewport->ParentViewportId))
			parentWindow = (HWND)parentViewport->PlatformHandle;

	// Create window
	RECT rect = { (LONG)viewport->Pos.x, (LONG)viewport->Pos.y, (LONG)(viewport->Pos.x + viewport->Size.x), (LONG)(viewport->Pos.y + viewport->Size.y) };
	::AdjustWindowRectEx(&rect, vd->DwStyle, FALSE, vd->DwExStyle);
	vd->Hwnd = ::CreateWindowExA(
		vd->DwExStyle, "ImGui Platform", "Untitled", vd->DwStyle,                 // Style, class name, window name
		rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top,      // Window area
		parentWindow, nullptr, ghInstance, nullptr);                              // Parent window, Menu, Instance, Param
	vd->HwndOwned = true;
	viewport->PlatformRequestResize = false;
	viewport->PlatformHandle = viewport->PlatformHandleRaw = vd->Hwnd;
}

static void ImGui_ImplWin32_DestroyWindow(ImGuiViewport* viewport)
{
	ImGui_ImplWin32_Data* bd = ImGui_ImplWin32_GetBackendData();
	if (ImGui_ImplWin32_ViewportData* vd = (ImGui_ImplWin32_ViewportData*)viewport->PlatformUserData)
	{
		if (::GetCapture() == vd->Hwnd)
		{
			// Transfer capture so if we started dragging from a window that later disappears, we'll still receive the MOUSEUP event.
			::ReleaseCapture();
			::SetCapture(bd->hWnd);
		}

		if (vd->Hwnd && vd->HwndOwned)
			::DestroyWindow(vd->Hwnd);
		vd->Hwnd = nullptr;
		delete vd;
	}

	viewport->PlatformUserData = viewport->PlatformHandle = nullptr;
}

static void ImGui_ImplWin32_ShowWindow(ImGuiViewport* viewport)
{
	ImGui_ImplWin32_ViewportData* vd = (ImGui_ImplWin32_ViewportData*)viewport->PlatformUserData;
	IM_ASSERT(vd->Hwnd != 0);

	if (viewport->Flags & ImGuiViewportFlags_NoFocusOnAppearing)
		::ShowWindow(vd->Hwnd, SW_SHOWNA);
	else
		::ShowWindow(vd->Hwnd, SW_SHOW);
}

static void ImGui_ImplWin32_UpdateWindow(ImGuiViewport* viewport)
{
	// (Optional) Update Win32 style if it changed _after_ creation.
	// Generally they won't change unless configuration flags are changed, but advanced uses (such as manually rewriting viewport flags) make this useful.
	ImGui_ImplWin32_ViewportData* vd = (ImGui_ImplWin32_ViewportData*)viewport->PlatformUserData;
	IM_ASSERT(vd->Hwnd != nullptr);
	DWORD new_style;
	DWORD new_ex_style;
	ImGui_ImplWin32_GetWin32StyleFromViewportFlags(viewport->Flags, &new_style, &new_ex_style);

	// Only reapply the flags that have been changed from our point of view (as other flags are being modified by Windows)
	if (vd->DwStyle != new_style || vd->DwExStyle != new_ex_style)
	{
		// (Optional) Update TopMost state if it changed _after_ creation
		bool top_most_changed = (vd->DwExStyle & WS_EX_TOPMOST) != (new_ex_style & WS_EX_TOPMOST);
		HWND insert_after = top_most_changed ? ((viewport->Flags & ImGuiViewportFlags_TopMost) ? HWND_TOPMOST : HWND_NOTOPMOST) : 0;
		UINT swp_flag = top_most_changed ? 0 : SWP_NOZORDER;

		vd->DwStyle = new_style;
		vd->DwExStyle = new_ex_style;
		::SetWindowLong(vd->Hwnd, GWL_STYLE, vd->DwStyle);
		::SetWindowLong(vd->Hwnd, GWL_EXSTYLE, vd->DwExStyle);
		RECT rect = { (LONG)viewport->Pos.x, (LONG)viewport->Pos.y, (LONG)(viewport->Pos.x + viewport->Size.x), (LONG)(viewport->Pos.y + viewport->Size.y) };
		::AdjustWindowRectEx(&rect, vd->DwStyle, FALSE, vd->DwExStyle); // Client to Screen
		::SetWindowPos(vd->Hwnd, nullptr, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, swp_flag | SWP_NOACTIVATE | SWP_FRAMECHANGED);
		::ShowWindow(vd->Hwnd, SW_SHOWNA); // This is necessary when we alter the style

		viewport->PlatformRequestMove = viewport->PlatformRequestResize = true;
	}
}

static ImVec2 ImGui_ImplWin32_GetWindowPos(ImGuiViewport* viewport)
{
	ImGui_ImplWin32_ViewportData* vd = (ImGui_ImplWin32_ViewportData*)viewport->PlatformUserData;
	IM_ASSERT(vd->Hwnd != 0);
	POINT pos = { 0, 0 };
	::ClientToScreen(vd->Hwnd, &pos);
	return ImVec2((float)pos.x, (float)pos.y);
}

static void ImGui_ImplWin32_SetWindowPos(ImGuiViewport* viewport, ImVec2 pos)
{
	ImGui_ImplWin32_ViewportData* vd = (ImGui_ImplWin32_ViewportData*)viewport->PlatformUserData;
	IM_ASSERT(vd->Hwnd != 0);
	RECT rect = { (LONG)pos.x, (LONG)pos.y, (LONG)pos.x, (LONG)pos.y };
	::AdjustWindowRectEx(&rect, vd->DwStyle, FALSE, vd->DwExStyle);
	::SetWindowPos(vd->Hwnd, nullptr, rect.left, rect.top, 0, 0, SWP_NOZORDER | SWP_NOSIZE | SWP_NOACTIVATE);
}

static ImVec2 ImGui_ImplWin32_GetWindowSize(ImGuiViewport* viewport)
{
	ImGui_ImplWin32_ViewportData* vd = (ImGui_ImplWin32_ViewportData*)viewport->PlatformUserData;
	IM_ASSERT(vd->Hwnd != 0);
	RECT rect;
	::GetClientRect(vd->Hwnd, &rect);
	return ImVec2(float(rect.right - rect.left), float(rect.bottom - rect.top));
}

static void ImGui_ImplWin32_SetWindowSize(ImGuiViewport* viewport, ImVec2 size)
{
	ImGui_ImplWin32_ViewportData* vd = (ImGui_ImplWin32_ViewportData*)viewport->PlatformUserData;
	IM_ASSERT(vd->Hwnd != 0);
	RECT rect = { 0, 0, (LONG)size.x, (LONG)size.y };
	::AdjustWindowRectEx(&rect, vd->DwStyle, FALSE, vd->DwExStyle); // Client to Screen
	::SetWindowPos(vd->Hwnd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, SWP_NOZORDER | SWP_NOMOVE | SWP_NOACTIVATE);
}

static void ImGui_ImplWin32_SetWindowFocus(ImGuiViewport* viewport)
{
	ImGui_ImplWin32_ViewportData* vd = (ImGui_ImplWin32_ViewportData*)viewport->PlatformUserData;
	IM_ASSERT(vd->Hwnd != nullptr);
	::BringWindowToTop(vd->Hwnd);
	::SetForegroundWindow(vd->Hwnd);
	::SetFocus(vd->Hwnd);
}

static bool ImGui_ImplWin32_GetWindowFocus(ImGuiViewport* viewport)
{
	ImGui_ImplWin32_ViewportData* vd = (ImGui_ImplWin32_ViewportData*)viewport->PlatformUserData;
	IM_ASSERT(vd->Hwnd != nullptr);
	return ::GetForegroundWindow() == vd->Hwnd;
}

static bool ImGui_ImplWin32_GetWindowMinimized(ImGuiViewport* viewport)
{
	ImGui_ImplWin32_ViewportData* vd = (ImGui_ImplWin32_ViewportData*)viewport->PlatformUserData;
	IM_ASSERT(vd->Hwnd != nullptr);
	return ::IsIconic(vd->Hwnd) != 0;
}

static void ImGui_ImplWin32_SetWindowTitle(ImGuiViewport* viewport, const char* title)
{
	// ::SetWindowTextA() doesn't properly handle UTF-8 so we explicitely convert our string.
	ImGui_ImplWin32_ViewportData* vd = (ImGui_ImplWin32_ViewportData*)viewport->PlatformUserData;
	IM_ASSERT(vd->Hwnd != nullptr);
	int n = ::MultiByteToWideChar(CP_UTF8, 0, title, -1, nullptr, 0);
	ImVector<wchar_t> title_w;
	title_w.resize(n);
	::MultiByteToWideChar(CP_UTF8, 0, title, -1, title_w.Data, n);
	::SetWindowTextW(vd->Hwnd, title_w.Data);
}

static void ImGui_ImplWin32_SetWindowAlpha(ImGuiViewport* viewport, float alpha)
{
	ImGui_ImplWin32_ViewportData* vd = (ImGui_ImplWin32_ViewportData*)viewport->PlatformUserData;
	IM_ASSERT(vd->Hwnd != nullptr);
	IM_ASSERT(alpha >= 0.0f && alpha <= 1.0f);
	if (alpha < 1.0f)
	{
		DWORD style = ::GetWindowLongW(vd->Hwnd, GWL_EXSTYLE) | WS_EX_LAYERED;
		::SetWindowLongW(vd->Hwnd, GWL_EXSTYLE, style);
		::SetLayeredWindowAttributes(vd->Hwnd, 0, (BYTE)(255 * alpha), LWA_ALPHA);
	}
	else
	{
		DWORD style = ::GetWindowLongW(vd->Hwnd, GWL_EXSTYLE) & ~WS_EX_LAYERED;
		::SetWindowLongW(vd->Hwnd, GWL_EXSTYLE, style);
	}
}

static float ImGui_ImplWin32_GetWindowDpiScale(ImGuiViewport* viewport)
{
	ImGui_ImplWin32_ViewportData* vd = (ImGui_ImplWin32_ViewportData*)viewport->PlatformUserData;
	IM_ASSERT(vd->Hwnd != nullptr);
	return ImGui_ImplWin32_GetDpiScaleForHwnd(vd->Hwnd);
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
	if (ImGuiManager_HandleWndProc(hWnd, msg, wParam, lParam))
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
#if HAS_WIN32_IME
	platform_io.Platform_SetImeInputPos = ImGui_ImplWin32_SetImeInputPos;
#endif

	// Register main window handle (which is owned by the main application, not by us)
	// This is mostly for simplicity and consistency, so that our code (e.g. mouse handling etc.) can use same logic for main and secondary viewports.
	ImGuiViewport* main_viewport = ImGui::GetMainViewport();
	ImGui_ImplWin32_Data* bd = ImGui_ImplWin32_GetBackendData();
	ImGui_ImplWin32_ViewportData* vd = new ImGui_ImplWin32_ViewportData();
	vd->Hwnd = bd->hWnd;
	vd->HwndOwned = false;
	main_viewport->PlatformUserData = vd;
	main_viewport->PlatformHandle = (void*)bd->hWnd;
}

static void ImGui_ImplWin32_ShutdownPlatformInterface()
{
	::UnregisterClass("ImGui Platform", ghInstance);
}

//---------------------------------------------------------------------------------------------------------
// Transparency related helpers (optional)
//--------------------------------------------------------------------------------------------------------

// [experimental]
// Borrowed from GLFW's function updateFramebufferTransparency() in src/win32_window.c
// (the Dwm* functions are Vista era functions but we are borrowing logic from GLFW)
void ImGui_ImplWin32_EnableAlphaCompositing(void* hwnd)
{
	if (!_IsWindowsVistaOrGreater())
		return;

	BOOL composition;
	if (FAILED(::DwmIsCompositionEnabled(&composition)) || !composition)
		return;

	BOOL opaque;
	DWORD color;
	if (_IsWindows8OrGreater() || (SUCCEEDED(::DwmGetColorizationColor(&color, &opaque)) && !opaque))
	{
		HRGN region = ::CreateRectRgn(0, 0, -1, -1);
		DWM_BLURBEHIND bb = {};
		bb.dwFlags = DWM_BB_ENABLE | DWM_BB_BLURREGION;
		bb.hRgnBlur = region;
		bb.fEnable = TRUE;
		::DwmEnableBlurBehindWindow((HWND)hwnd, &bb);
		::DeleteObject(region);
	}
	else
	{
		DWM_BLURBEHIND bb = {};
		bb.dwFlags = DWM_BB_ENABLE;
		::DwmEnableBlurBehindWindow((HWND)hwnd, &bb);
	}
}

#pragma endregion

void ImGui_EnableViewports(bool enable)
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

void ImGui_EnableDocking(bool enable)
{
	ImGuiIO& io = ImGui::GetIO();

	if (!enable)
	{
		io.ConfigFlags &= ~ImGuiConfigFlags_DockingEnable;
	}
	else
	{
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	}
}

bool ImGui_IsImGuiForeground()
{
	if (ImGui::GetCurrentContext() == NULL)
		return false;

	const auto& platform_io = ImGui::GetPlatformIO();

	auto hWnd = GetForegroundWindow();
	for (const auto& v : platform_io.Viewports)
	{
		if (v != nullptr)
		{
			auto userdata = static_cast<ImGuiViewportData*>(v->RendererUserData);
			if (userdata != nullptr && userdata->hDeviceWindow == hWnd) return true;
		}
	}

	return false;
}

#pragma endregion

} // namespace mq
