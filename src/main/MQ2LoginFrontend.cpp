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

// "LoginFrontend" or just "Frontend" refers to the UI part of EQ that contains login
// and server select. This is contained in eqmain, and its functions are only available
// while this dll is loaded at startup.

// Once login is completed, this dll is unloaded and the functions are no longer available.

namespace mq {

//============================================================================

// From MQ2Pulse.cpp
void DoLoginPulse();

// From MQ2Overlay.cpp
bool OverlayWndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam, bool fromLogin);

static uintptr_t __FreeLibrary = 0;
static bool gbDetoursInstalled = false;

class LoginController_Hook
{
public:
	// This is called continually during the login mainloop so we can use it as our pulse when the MAIN
	// gameloop pulse is not active but login is.
	// that will allow plugins to work and execute commands all the way back pre login and server select etc.
	void GiveTime_Trampoline();
	void GiveTime_Detour()
	{
		DoLoginPulse();

		if (g_pLoginController)
		{
			if (ImGui::GetCurrentContext() != nullptr)
			{
				ImGuiIO& io = ImGui::GetIO();

				g_pLoginController->bIsKeyboardActive = !io.WantCaptureKeyboard;
				g_pLoginController->bIsMouseActive = !io.WantCaptureMouse;
			}
			else
			{
				//g_pLoginController->bIsKeyboardActive = true;
				//g_pLoginController->bIsMouseActive = true;
			}
		}

		GiveTime_Trampoline();
	}
};
DETOUR_TRAMPOLINE_EMPTY(void LoginController_Hook::GiveTime_Trampoline());

// Forwards events to ImGui. If ImGui consumes the event, we won't pass it to the game.
DETOUR_TRAMPOLINE_EMPTY(LRESULT WINAPI EQMain__WndProc_Trampoline(HWND, UINT, WPARAM, LPARAM));
LRESULT WINAPI EQMain__WndProc_Detour(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (OverlayWndProcHandler(hWnd, msg, wParam, lParam, true))
		return 1;

	return EQMain__WndProc_Trampoline(hWnd, msg, wParam, lParam);
}

// LoginViewController will continuously override the cursor. Do not let it change the cursor
// if we want to change the cursor.
class CXWndManager_Hook
{
public:
	HCURSOR GetCursorToDisplay_Trampoline() const;
	HCURSOR GetCursorToDisplay_Detour() const
	{
		if (ImGui::GetCurrentContext() != nullptr && ImGui::GetIO().WantCaptureMouse)
		{
			return GetCursor();
		}

		return GetCursorToDisplay_Trampoline();
	}
};
DETOUR_TRAMPOLINE_EMPTY(HCURSOR CXWndManager_Hook::GetCursorToDisplay_Trampoline() const);

void InitializeLoginDetours()
{
	if (gbDetoursInstalled)
		return;

	EzDetour(LoginController__GiveTime, &LoginController_Hook::GiveTime_Detour, &LoginController_Hook::GiveTime_Trampoline);
	EzDetour(EQMain__WndProc, EQMain__WndProc_Detour, EQMain__WndProc_Trampoline);

	if (EQMain__CXWndManager__GetCursorToDisplay)
	{
		EzDetour(EQMain__CXWndManager__GetCursorToDisplay, &CXWndManager_Hook::GetCursorToDisplay_Detour,
			&CXWndManager_Hook::GetCursorToDisplay_Trampoline);
	}

	gbDetoursInstalled = true;
}

void RemoveLoginDetours()
{
	if (!gbDetoursInstalled)
		return;

	RemoveDetour(LoginController__GiveTime);
	RemoveDetour(EQMain__WndProc);
	if (EQMain__CXWndManager__GetCursorToDisplay)
	{
		RemoveDetour(EQMain__CXWndManager__GetCursorToDisplay);
	}

	gbDetoursInstalled = false;
}

void TryInitializeLoginDetours()
{
	// leave if the dll isn't loaded
	if (!*ghEQMainInstance)
		return;

	if (InitializeEQMainOffsets())
	{
		// these are the offsets that we need to move forward.
		bool pulseSuccess = LoginController__GiveTime != 0
			&& EQMain__CXWndManager != 0
			&& EQMain__CSidlManager != 0;

		if (pulseSuccess)
		{
			// means it was loaded properly
			InitializeLoginDetours();

			PluginsSetGameState(GAMESTATE_POSTFRONTLOAD);
		}

		bool overlaySuccess = EQMain__WndProc != 0
			&& LoginController__ProcessKeyboardEvents
			&& LoginController__ProcessMouseEvents
			&& LoginController__FlushDxKeyboard;
	}
	else
	{
		MessageBox(nullptr, "MQ2 needs an update.", "Failed to locate offsets required by MQ2LoginFrontend", MB_SYSTEMMODAL | MB_OK);
	}
}

// Purpose of this hook is to detect when we are loading the frontend. This is only necessary if MQ2 is
// injected before eqmain.dll is loaded.
DETOUR_TRAMPOLINE_EMPTY(int LoadFrontEnd_Trampoline());
int LoadFrontEnd_Detour()
{
	gGameState = GetGameState();

	DebugTry(Benchmark(bmPluginsSetGameState, PluginsSetGameState(gGameState)));

	int ret = LoadFrontEnd_Trampoline();
	if (ret)
	{
		TryInitializeLoginDetours();
	}

	return ret;
}

DETOUR_TRAMPOLINE_EMPTY(BOOL WINAPI FreeLibrary_Trampoline(HMODULE));
BOOL WINAPI FreeLibrary_Detour(HMODULE hModule)
{
	if (hModule == (HMODULE)*ghEQMainInstance)
	{
		RemoveLoginDetours();
		CleanupEQMainOffsets();
	}

	return FreeLibrary_Trampoline(hModule);
}

void InitializeLoginFrontend()
{
	EzDetour(__LoadFrontEnd, LoadFrontEnd_Detour, LoadFrontEnd_Trampoline);

	__FreeLibrary = (uintptr_t)&::FreeLibrary;
	EzDetour(__FreeLibrary, FreeLibrary_Detour, FreeLibrary_Trampoline);

	TryInitializeLoginDetours();
}

void ShutdownLoginFrontend()
{
	RemoveDetour(__LoadFrontEnd);
	RemoveDetour(__FreeLibrary);
	RemoveLoginDetours();
}

} // namespace mq
