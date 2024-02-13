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

// for hotkey functions
#include "MacroQuest.h"

#include <CommCtrl.h>

// from https://github.com/stefankueng/sktoolslib/blob/master/HotKeyCtrl.cpp
class CHotKeyCtrl
{
public:
	CHotKeyCtrl() {}
	virtual ~CHotKeyCtrl() {}

	bool ConvertEditToHotKeyCtrl(HWND hwndCtl);
	bool ConvertEditToHotKeyCtrl(HWND hwndParent, int uiCtlId)
	{
		return ConvertEditToHotKeyCtrl(GetDlgItem(hwndParent, uiCtlId));
	}

	void SetHotKey(uint16_t mods, uint16_t vk)
	{
		m_mods = mods;
		m_vk = vk;
		SetHKText(mods, vk);
	}

	void SetHotKey(const std::string& text)
	{
		if (!ConvertStringToModifiersAndVirtualKey(text, m_mods, m_vk))
		{
			m_mods = 0;
			m_vk = 0;
		}

		SetHKText(m_mods, m_vk);
	}

	uint16_t GetModifiers() const { return m_mods; }
	uint16_t GetVirtualKey() const { return m_vk; }

	HWND GetHWnd() const { return m_hWnd; }

private:
	static LRESULT CALLBACK HotKeyProc(HWND hwnd, UINT message,
		WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK KeyboardProc(int code, WPARAM wParam, LPARAM lParam);

	void SetHKText(uint16_t modifier, uint16_t virtualKey)
	{
		char result[MAX_PATH] = { 0 };

		if (modifier == 0 && virtualKey == 0)
		{
			::SetWindowText(m_hWnd, "");
			return;
		}

		GetModifiersName(modifier, result, MAX_PATH);

		const char* keyName = GetKeyNameFromVirtualKey(virtualKey);
		if (keyName)
		{
			if (result[0])
				strcat_s(result, "+");

			strcat_s(result, keyName);
		}

		::SetWindowText(m_hWnd, result);
	}

private:
	HWND m_hWnd = nullptr;
	WNDPROC m_pfnOrigCtlProc = nullptr;
	HHOOK m_kbHook = 0;
	bool m_controlDown = false;
	bool m_shiftDown = false;
	bool m_altDown = false;
	bool m_winDown = false;
	uint16_t m_mods = 0;
	uint16_t m_vk = 0;
};
