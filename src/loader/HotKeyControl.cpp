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

#include "HotKeyControl.h"

class CGlobalAtom
{
public:
	CGlobalAtom()
	{
		atom = GlobalAddAtom(TEXT("_HotKeyCtrl_Object_Pointer_")
			TEXT("\\{6C2F5551-091E-45F5-A80E-849414EF7833}"));
	}
	~CGlobalAtom()
	{
		DeleteAtom(atom);
	}

	ATOM atom;
};

static CGlobalAtom ga;

#define PROP_OBJECT_PTR         MAKEINTATOM(ga.atom)
#define PROP_ORIGINAL_PROC      MAKEINTATOM(ga.atom)

bool CHotKeyCtrl::ConvertEditToHotKeyCtrl(HWND hwndCtl)
{
	// Subclass the existing control.
	m_pfnOrigCtlProc = (WNDPROC)GetWindowLongPtrA(hwndCtl, GWLP_WNDPROC);
	SetProp(hwndCtl, PROP_OBJECT_PTR, (HANDLE)this);
	SetWindowLongPtr(hwndCtl, GWLP_WNDPROC, (LONG_PTR)(WNDPROC)HotKeyProc);

	m_kbHook = SetWindowsHookEx(WH_KEYBOARD, KeyboardProc, nullptr, GetCurrentThreadId());
	m_hWnd = hwndCtl;

	return true;
}

LRESULT CALLBACK CHotKeyCtrl::HotKeyProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	CHotKeyCtrl* pHyperLink = (CHotKeyCtrl*)GetProp(hwnd, PROP_OBJECT_PTR);

	switch (message)
	{
	case WM_SHOWWINDOW:
		pHyperLink->SetHKText(pHyperLink->m_mods, pHyperLink->m_vk);
		HideCaret(pHyperLink->m_hWnd);
		break;
	case WM_GETDLGCODE:
		return DLGC_WANTALLKEYS;
	case WM_SYSKEYDOWN:
	case WM_KEYDOWN:
	{
		return 0;
	}
	case WM_SYSKEYUP:
	case WM_KEYUP:
	{
		return 0;
	}
	case WM_SETFOCUS:
		HideCaret(pHyperLink->m_hWnd);
		break;
	case WM_CHAR:
		return 0;
	case WM_DESTROY:
	{
		SetWindowLongPtr(hwnd, GWLP_WNDPROC,
			(LONG_PTR)pHyperLink->m_pfnOrigCtlProc);

		RemoveProp(hwnd, PROP_OBJECT_PTR);
		break;
	}
	}

	return CallWindowProc(pHyperLink->m_pfnOrigCtlProc, hwnd, message,
		wParam, lParam);
}

LRESULT CALLBACK CHotKeyCtrl::KeyboardProc(int code, WPARAM wParam, LPARAM lParam)
{
	HWND hWndFocus = ::GetFocus();
	if (hWndFocus)
	{
		CHotKeyCtrl* pHyperLink = (CHotKeyCtrl*)GetProp(hWndFocus, PROP_OBJECT_PTR);

		if ((pHyperLink) && (pHyperLink->m_hWnd == hWndFocus))
		{
			if (lParam & 0x80000000)
			{
				// WM_KEYUP
				if (wParam == VK_CONTROL)
				{
					pHyperLink->m_controlDown = false;
				}
				else if (wParam == VK_SHIFT)
				{
					pHyperLink->m_shiftDown = false;
				}
				else if (wParam == VK_MENU)
				{
					pHyperLink->m_altDown = false;
				}
				else if (wParam == VK_LWIN)
				{
					pHyperLink->m_winDown = false;
				}
				else
				{
					uint16_t mods = 0;

					if (wParam == VK_ESCAPE)
					{
						pHyperLink->m_controlDown = false;
						pHyperLink->m_shiftDown = false;
						pHyperLink->m_altDown = false;
						pHyperLink->m_winDown = false;
						wParam = 0;
					}

					if (pHyperLink->m_controlDown)
					{
						mods |= MOD_CONTROL;
					}
					if (pHyperLink->m_shiftDown)
					{
						mods |= MOD_SHIFT;
					}
					if (pHyperLink->m_altDown)
					{
						mods |= MOD_ALT;
					}
					if (pHyperLink->m_winDown)
					{
						mods |= MOD_WIN;
					}

					pHyperLink->m_vk = (uint16_t)wParam;
					pHyperLink->m_mods = mods;
					pHyperLink->SetHKText(pHyperLink->m_mods, pHyperLink->m_vk);
					return 1; // we processed it
				}
			}
			else
			{
				// WM_KEYDOWN
				if (wParam == VK_CONTROL)
				{
					pHyperLink->m_controlDown = true;
				}
				else if (wParam == VK_SHIFT)
				{
					pHyperLink->m_shiftDown = true;
				}
				else if (wParam == VK_MENU)
				{
					pHyperLink->m_altDown = true;
				}
				else if (wParam == VK_LWIN)
				{
					pHyperLink->m_winDown = true;
				}
				else
				{
					uint16_t mods = 0;

					if (wParam == VK_ESCAPE)
					{
						pHyperLink->m_controlDown = false;
						pHyperLink->m_shiftDown = false;
						pHyperLink->m_altDown = false;
						pHyperLink->m_winDown = false;
						wParam = 0;
					}

					if (pHyperLink->m_controlDown)
					{
						mods |= MOD_CONTROL;
					}
					if (pHyperLink->m_shiftDown)
					{
						mods |= MOD_SHIFT;
					}
					if (pHyperLink->m_altDown)
					{
						mods |= MOD_ALT;
					}
					if (pHyperLink->m_winDown)
					{
						mods |= MOD_WIN;
					}

					pHyperLink->m_vk = (uint16_t)wParam;
					pHyperLink->m_mods = mods;
					pHyperLink->SetHKText(pHyperLink->m_mods, pHyperLink->m_vk);
					return 1; // we processed it
				}
			}

			return CallNextHookEx(pHyperLink->m_kbHook, code, wParam, lParam);
		}
	}
	return 0;
}
