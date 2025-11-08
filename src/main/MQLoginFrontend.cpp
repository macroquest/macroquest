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

#include "Logging.h"
#include "MQMain.h"
#include "MQDeveloperTools.h"

// "LoginFrontend" or just "Frontend" refers to the UI part of EQ that contains login
// and server select. This is contained in eqmain, and its functions are only available
// while this dll is loaded at startup.

// Once login is completed, this dll is unloaded and the functions are no longer available.

using namespace eqlib;

namespace mq {

//============================================================================

// From MQ2Overlay.cpp
bool OverlayWndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


// FIXME: Hook these when entering login

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

class LoginModule : public MQModule
{
public:
	LoginModule() : MQModule("Login")
	{
	}

	virtual void Initialize() override
	{
	}

	virtual void Shutdown() override
	{
	}

	virtual void OnProcessFrame() override
	{
		if (g_pLoginController)
		{
			if (ImGui::GetCurrentContext() != nullptr)
			{
				ImGuiIO& io = ImGui::GetIO();

				g_pLoginController->bIsKeyboardActive = !io.WantCaptureKeyboard;
				g_pLoginController->bIsMouseActive = !io.WantCaptureMouse;
			}
		}
	}

	virtual void OnLoginFrontendEntered() override
	{
		InstallLoginDetours();

		ReinitializeWindowList();
	}

	virtual void OnLoginFrontendExited() override
	{
		DeveloperTools_CloseLoginFrontend();
		RemoveLoginDetours();

		ReinitializeWindowList();
	}

private:
	void InstallLoginDetours()
	{
		if (!m_detoursInstalled)
		{
			LOG_DEBUG("Initializing Login Detours");

			EzDetour(EQMain__WndProc, EQMain__WndProc_Detour, EQMain__WndProc_Trampoline);

#if defined(EQMain__CXWndManager__GetCursorToDisplay_x)
			if (EQMain__CXWndManager__GetCursorToDisplay && EQMain__CXWndManager__GetCursorToDisplay_x != 0)
			{
				EzDetour(EQMain__CXWndManager__GetCursorToDisplay, &CXWndManager_Hook::GetCursorToDisplay_Detour,
					&CXWndManager_Hook::GetCursorToDisplay_Trampoline);
			}
#endif

			m_detoursInstalled = true;
		}
	}

	void RemoveLoginDetours()
	{
		if (m_detoursInstalled)
		{
			LOG_DEBUG("Removing Login Detours");

			RemoveDetour(EQMain__WndProc);

			m_detoursInstalled = false;
		}
	}

	bool m_detoursInstalled = false;
};

DECLARE_MODULE_FACTORY(LoginModule);

} // namespace mq
