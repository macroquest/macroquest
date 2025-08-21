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
#include "MQPluginHandler.h"
#include "Logging.h"

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

static bool s_waitingForFrontend = false;
static bool s_inFrontend = false;
static bool s_initialized = false;

//----------------------------------------------------------------------------
// Login Pulse detour

class LoginController_Hook
{
public:
	// This is called continually during the login mainloop so we can use it as our pulse when the MAIN
	// gameloop pulse is not active but login is.
	// that will allow plugins to work and execute commands all the way back pre login and server select etc.
	DETOUR_TRAMPOLINE_DEF(void, GiveTime_Trampoline, ())
	void GiveTime_Detour()
	{
		if (!s_inFrontend)
		{
			gGameState = GetGameState();
			DebugTry(Benchmark(bmPluginsSetGameState, PluginsSetGameState(gGameState)));
		}

		s_inFrontend = true;

		if (s_waitingForFrontend)
		{
			// Only do this on the first pass through the login main loop.
			s_waitingForFrontend = false;

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

		GiveTime_Trampoline();
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

void InitializeLoginFrontend()
{
	if (!s_initialized)
	{
		s_waitingForFrontend = true;

		LOG_DEBUG("Initializing Login Detours");

		EzDetour(EQMain__LoginController__GiveTime, &LoginController_Hook::GiveTime_Detour, &LoginController_Hook::GiveTime_Trampoline);
		EzDetour(EQMain__WndProc, EQMain__WndProc_Detour, EQMain__WndProc_Trampoline);

#if defined(EQMain__CXWndManager__GetCursorToDisplay_x)
		if (EQMain__CXWndManager__GetCursorToDisplay && EQMain__CXWndManager__GetCursorToDisplay_x != 0)
		{
			EzDetour(EQMain__CXWndManager__GetCursorToDisplay, &CXWndManager_Hook::GetCursorToDisplay_Detour,
				&CXWndManager_Hook::GetCursorToDisplay_Trampoline);
		}
#endif

		s_initialized = true;
	}
}

void ShutdownLoginFrontend()
{
	if (s_initialized)
	{
		LOG_DEBUG("Removing Login Detours");

		DeveloperTools_CloseLoginFrontend();

		uintptr_t detours[] = {
			EQMain__LoginController__GiveTime,
			EQMain__WndProc,
	#if defined(EQMain__CXWndManager__GetCursorToDisplay_x)
			EQMain__CXWndManager__GetCursorToDisplay
	#endif // defined(EQMain__CXWndManager__GetCursorToDisplay_x)
		};

		for (uintptr_t detour : detours)
			RemoveDetour(detour);

		if (s_inFrontend)
		{
			s_inFrontend = false;
			s_waitingForFrontend = true;

			ReinitializeWindowList();
		}

		s_initialized = false;
	}
}

} // namespace mq
