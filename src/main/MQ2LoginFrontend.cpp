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
#include "MQ2Main.h"
#include "MQ2DeveloperTools.h"

// "LoginFrontend" or just "Frontend" refers to the UI part of EQ that contains login
// and server select. This is contained in eqmain, and its functions are only available
// while this dll is loaded at startup.

// Once login is completed, this dll is unloaded and the functions are no longer available.

namespace mq {

//============================================================================

// From MQ2Pulse.cpp
void DoLoginPulse();

// From MQ2Overlay.cpp
bool OverlayWndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

static uintptr_t __FreeLibrary = 0;
static bool gbDetoursInstalled = false;
static bool gbWaitingForFrontend = false;
static bool gbInFrontend = false;

//----------------------------------------------------------------------------
// Login Pulse detour

class LoginController_Hook
{
public:
	// This is called continually during the login mainloop so we can use it as our pulse when the MAIN
	// gameloop pulse is not active but login is.
	// that will allow plugins to work and execute commands all the way back pre login and server select etc.
	inline static void (LoginController_Hook::* GiveTime_Trampoline)() = nullptr;
	void GiveTime_Detour()
	{
		if (!gbInFrontend)
		{
			gGameState = GetGameState();
			DebugTry(Benchmark(bmPluginsSetGameState, PluginsSetGameState(gGameState)));
		}

		gbInFrontend = true;

		if (gbWaitingForFrontend)
		{
			// Only do this on the first pass through the login main loop.
			gbWaitingForFrontend = false;

			// Redirect CXWndManager and CSidlManager to the login instances now that we know that the
			// frontend is actually running now.
			pWndMgr = EQMain__pinstCXWndManager;
			pSidlMgr = EQMain__pinstCSidlManager;

			// Since we have ensured that we have window and sidl managers, load the pre-charselect windows
			ReinitializeWindowList();

			// Signal to others that we are loaded properly.
			// Note: this is not really the proper way to do this since this isn't a game state, but autologin
			// is the only one listening for it.
		}

		DoLoginPulse();

		if (g_pLoginController)
		{
			if (ImGui::GetCurrentContext() != nullptr)
			{
				ImGuiIO& io = ImGui::GetIO();

				g_pLoginController->bIsKeyboardActive = !io.WantCaptureKeyboard;
				g_pLoginController->bIsMouseActive = !io.WantCaptureMouse;
			}
		}

		(this->*GiveTime_Trampoline)();
	}
};

// End Login pulse detour
//----------------------------------------------------------------------------

// Forwards events to ImGui. If ImGui consumes the event, we won't pass it to the game.
DETOUR_TRAMPOLINE_DEF(LRESULT WINAPI, EQMain__WndProc_Trampoline, (HWND, UINT, WPARAM, LPARAM))
LRESULT WINAPI EQMain__WndProc_Detour(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (OverlayWndProcHandler(hWnd, msg, wParam, lParam))
		return 1;

	return EQMain__WndProc_Trampoline(hWnd, msg, wParam, lParam);
}

// LoginViewController will continuously override the cursor. Do not let it change the cursor
// if we want to change the cursor.
class CXWndManager_Hook
{
public:
	DETOUR_TRAMPOLINE_DEF(HCURSOR, GetCursorToDisplay_Trampoline, ())
	HCURSOR GetCursorToDisplay_Detour()
	{
		if (ImGui::GetCurrentContext() != nullptr && ImGui::GetIO().WantCaptureMouse)
		{
			return GetCursor();
		}

		return GetCursorToDisplay_Trampoline();
	}
};

void InitializeLoginDetours()
{
	if (gbDetoursInstalled)
		return;

	DebugSpewAlways("Initializing Login Detours");

	AddDetour(EQMain__LoginController__GiveTime, &LoginController_Hook::GiveTime_Detour, &LoginController_Hook::GiveTime_Trampoline, "GiveTime");
	EzDetour(EQMain__WndProc, EQMain__WndProc_Detour, EQMain__WndProc_Trampoline);

#if defined(EQMain__CXWndManager__GetCursorToDisplay_x)
	if (EQMain__CXWndManager__GetCursorToDisplay && EQMain__CXWndManager__GetCursorToDisplay_x != 0)
	{
		EzDetour(EQMain__CXWndManager__GetCursorToDisplay, &CXWndManager_Hook::GetCursorToDisplay_Detour,
			&CXWndManager_Hook::GetCursorToDisplay_Trampoline);
	}
#endif

	gbDetoursInstalled = true;
}

void RemoveLoginDetours()
{
	if (!gbDetoursInstalled)
		return;

	DebugSpewAlways("Removing Login Detours");

	uintptr_t detours[] = {
		EQMain__LoginController__GiveTime,
		EQMain__WndProc,
#if defined(EQMain__CXWndManager__GetCursorToDisplay_x)
		EQMain__CXWndManager__GetCursorToDisplay
#endif // defined(EQMain__CXWndManager__GetCursorToDisplay_x)
	};

	for (uintptr_t detour : detours)
		RemoveDetour(detour);

	gbDetoursInstalled = false;
}

// This also gets called from our GetProcAddress detour when the client tries to load eqmain.dll
void TryInitializeLogin()
{
	// leave if the dll isn't loaded
	if (!*ghEQMainInstance)
		return;

	if (InitializeEQMainOffsets())
	{
		// these are the offsets that we need to move forward.
		bool pulseSuccess = EQMain__LoginController__GiveTime != 0
			&& EQMain__pinstCXWndManager != 0
			&& EQMain__pinstCSidlManager != 0;

		if (pulseSuccess)
		{
			InitializeLoginDetours();
		}

		bool overlaySuccess = EQMain__WndProc != 0
			&& EQMain__LoginController__ProcessKeyboardEvents
			&& EQMain__LoginController__ProcessMouseEvents;

		// We'll continue in the first iteration of LoginPulse. This is important
		// because it means the frontend is actually running.
	}
	else
	{
		MessageBox(nullptr, "MQ2 needs an update.", "Failed to locate offsets required by MQ2LoginFrontend", MB_SYSTEMMODAL | MB_OK);
	}
}

void TryRemoveLogin()
{
	if (gbInFrontend)
	{
		gbInFrontend = false;
		gbWaitingForFrontend = true;

		DebugSpewAlways("Cleaning up EQMain Offsets");

		DeveloperTools_CloseLoginFrontend();

		RemoveLoginDetours();
		CleanupEQMainOffsets();

		// we also need to make sure to reset the manager pointers and reset the window list we are tracking with them
		pWndMgr = pinstCXWndManager;
		pSidlMgr = pinstCSidlManager;
		ReinitializeWindowList();
	}
}

namespace RemoveLoginHook
{
#if defined(__InitMouse_x) // If __InitMouse_x is defined, we use this hook instead of FlushDxKeyboard
	DETOUR_TRAMPOLINE_DEF(int, Trampoline, (HWND, bool))
		int Detour(HWND hWnd, bool b)
	{
		TryRemoveLogin();
		return Trampoline(hWnd, b);
	}

	uintptr_t GetAddress() { return __InitMouse; }
#else
	// Right after leaving the frontend, we get a call to FlushDxKeyboard in ExecuteEverQuest(). We
	// hook this function and use it to determine that we've exited the frontend.
	DETOUR_TRAMPOLINE_DEF(int, Trampoline, ());
	int Detour()
	{
		TryRemoveLogin();
		return Trampoline();
	}

	uintptr_t GetAddress() { return __FlushDxKeyboard; }
#endif
}

void InitializeLoginFrontend()
{
	EzDetour(RemoveLoginHook::GetAddress(), RemoveLoginHook::Detour, RemoveLoginHook::Trampoline);

	gbWaitingForFrontend = true;

	// Try to initialize login detours. This will succeed if eqmain.dll is already loaded. If it isn't,
	// well try again in LoadFrontend_Detour(), which is called when eqmain.dll is actually loaded.
	TryInitializeLogin();
}

void ShutdownLoginFrontend()
{
	RemoveDetour(RemoveLoginHook::GetAddress());

	RemoveLoginDetours();
}

} // namespace mq
