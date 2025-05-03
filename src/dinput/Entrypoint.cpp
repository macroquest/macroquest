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
#include "dinput.h"

#include "mq/base/Common.h"

#define COM_NO_WINDOWS_H
#include <objbase.h>

using DirectInput8Create_t = HRESULT(WINAPI*)(HINSTANCE, DWORD, REFIID, LPVOID*, LPUNKNOWN);

static HMODULE s_realDInput8 = nullptr;
static DirectInput8Create_t s_realDirectInput8Create = nullptr;

HMODULE ghModule;
HINSTANCE ghInstance;

extern "C" __declspec(dllexport)
HRESULT WINAPI DirectInput8Create(HINSTANCE hInst, DWORD dwVersion, REFIID riid, LPVOID* ppOut, LPUNKNOWN pUnknown)
{
	if (!s_realDInput8)
	{
		wchar_t systemPath[MAX_PATH];
		::GetSystemDirectoryW(systemPath, MAX_PATH);

		wcscat_s(systemPath, L"\\dinput8.dll");

		s_realDInput8 = ::LoadLibraryW(systemPath);
		if (!s_realDInput8)
		{
			return E_FAIL;
		}

		s_realDirectInput8Create = (DirectInput8Create_t)GetProcAddress(s_realDInput8, "DirectInput8Create");
		if (!s_realDirectInput8Create)
		{
			return E_FAIL;
		}
	}

	return s_realDirectInput8Create(hInst, dwVersion, riid, ppOut, pUnknown);
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call != DLL_PROCESS_ATTACH && ul_reason_for_call != DLL_PROCESS_DETACH)
	{
		return TRUE;
	}

	char szFilename[MAX_STRING] = { 0 };
	ghModule = (HMODULE)hModule;
	ghInstance = (HINSTANCE)hModule;
}

