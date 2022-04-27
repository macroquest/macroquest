/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2022 MacroQuest Authors
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

#define DIRECTINPUT_VERSION    0x800
#include <dxsdk90\include\dinput.h>

namespace mq {

static bool gbInDState = false;
static bool gbInDAcquire = false;
static bool gbInDInput = false;

// ***************************************************************************
// Function:    DInputDataDetour
// Description: Our DirectInput GetDeviceState Hook
// ***************************************************************************

DETOUR_TRAMPOLINE_DEF(HRESULT CALLBACK, DInputDataTrampoline, (IDirectInputDevice8A* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags))
HRESULT CALLBACK DInputDataDetour(IDirectInputDevice8A* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
	gbInDInput = true;
	HRESULT hResult = 0;
	MQKeyPress* pNext = nullptr;
	DWORD didAdd = 0;
	bool bLoop;
	bool bRemoveItem = false;
	DWORD dwInOutSave = *pdwInOut;
	DWORD dwTimeStamp = 0;
	DWORD dwSequence = 0;

	if (!gbUnload)
	{
		if (EQADDR_DIMOUSE && (This == *EQADDR_DIMOUSE))
		{
			// If we are waiting for a click-event to be confirmed by EQ, don't
			// pull any data, just return DI_OK and set the pdwInOut value to 0
			if (IsMouseWaitingForButton())
			{
				hResult = DI_OK;
				*pdwInOut = 0;
				gbInDInput = false;
				return hResult;
			}

			if (EQADDR_MOUSE && gMouseData)
			{
				*pdwInOut = 0;
				bLoop = true;

				while (bLoop && gMouseData)
				{
					bRemoveItem = true;

					if (*pdwInOut < dwInOutSave)
					{
						rgdod[*pdwInOut].dwSequence = dwSequence;
						rgdod[*pdwInOut].dwTimeStamp = dwTimeStamp;
						rgdod[0].uAppData = 0;

						switch (gMouseData->mdType)
						{
						case MD_Button0Click:
							DebugSpew("Trying to click left button.");
							rgdod[*pdwInOut].dwData = 0x80;
							rgdod[*pdwInOut].dwOfs = DIMOFS_BUTTON0;
							gMouseData->mdType = MD_Button0;
							gMouseData->dwData = 0x00;
							bRemoveItem = false;
							bLoop = false;
							(*pdwInOut)++;
							break;

						case MD_Button1Click:
							DebugSpew("Trying to click right button.");
							rgdod[*pdwInOut].dwData = 0x80;
							rgdod[*pdwInOut].dwOfs = DIMOFS_BUTTON1;
							gMouseData->mdType = MD_Button1;
							gMouseData->dwData = 0x00;
							bRemoveItem = false;
							bLoop = false;
							(*pdwInOut)++;
							break;

						case MD_Button0:
							rgdod[*pdwInOut].dwData = gMouseData->dwData;
							rgdod[*pdwInOut].dwOfs = DIMOFS_BUTTON0;
							(*pdwInOut)++;
							break;

						case MD_Button1:
							rgdod[*pdwInOut].dwData = gMouseData->dwData;
							rgdod[*pdwInOut].dwOfs = DIMOFS_BUTTON1;
							(*pdwInOut)++;
							break;

						case MD_Unknown:
							break;
						}

						if (bRemoveItem)
						{
							MOUSESPOOF* pTemp = gMouseData;
							gMouseData = gMouseData->pNext;
							if (pTemp)
								delete pTemp;
						}
					}
					else
					{
						bLoop = false;
					}
				}

				gbInDInput = false;
				return (HRESULT)DI_OK;
			}
		}
	}

	// If we didn't add any keyboard data, and we aren't waiting for a click,
	// and we didn't add any mouse data
	hResult = DInputDataTrampoline(This, cbObjectData, rgdod, pdwInOut, dwFlags);

	if (gbUnload)
	{
		gbInDInput = false;
		return hResult;
	}

	gbInDInput = false;
	return hResult;
}

DETOUR_TRAMPOLINE_DEF(HRESULT CALLBACK, DInputStateTrampoline, (IDirectInputDevice8A* This, DWORD cbData, void* lpvData))
HRESULT CALLBACK DInputStateDetour(IDirectInputDevice8A* This, DWORD cbData, void* lpvData)
{
	HRESULT hResult = S_OK;
	DWORD dwBuffSize = 0;
	bool bOneTime = false;

	gbInDState = true;
	hResult = DInputStateTrampoline(This, cbData, lpvData);

	// We could alter the return here if so desired, if a macro is executing that requires keyboard and mouse input.
	// by setting hResult to DI_OK;
	if (hResult == DIERR_INPUTLOST || hResult == DIERR_NOTACQUIRED)
	{
		bDetMouse = false;
	}

	if (gbUnload)
	{
		gbInDState = false;
		return hResult;
	}

	if ((cbData == sizeof(DIMOUSESTATE)) || (cbData == sizeof(DIMOUSESTATE2)))
	{
		if (IsMouseWaitingForButton() && (EQADDR_MOUSECLICK))
		{
			((LPDIMOUSESTATE)lpvData)->rgbButtons[0] = EQADDR_MOUSECLICK->Click[0];
			((LPDIMOUSESTATE)lpvData)->rgbButtons[1] = EQADDR_MOUSECLICK->Click[1];
		}
	}

	gbInDState = false;
	return hResult;
}

DETOUR_TRAMPOLINE_DEF(HRESULT CALLBACK, DInputAcquireTrampoline, (IDirectInputDevice8A* This))
HRESULT CALLBACK DInputAcquireDetour(IDirectInputDevice8A* This)
{
	HRESULT hResult = S_OK;
	DWORD dwBuffSize = 0;

	gbInDAcquire = true;
	hResult = DInputAcquireTrampoline(This);

	// Could alter the return here to allow background macro execution with keyboard and mouse input
	if (hResult != DI_OK && hResult != S_FALSE) // Mouse wasn't acquired successfully
	{
		bDetMouse = true;
	}

	if (gbUnload)
	{
		gbInDAcquire = false;
		return hResult;
	}

	gbInDAcquire = false;
	return hResult;
}

uintptr_t GetDeviceData = 0;
uintptr_t GetDeviceState = 0;
uintptr_t Acquire = 0;

void InitializeMQ2DInput()
{
	DebugSpew("Initializing DInput");

	IDirectInputDevice8A* IDIDevice = nullptr;
	IDirectInputDevice8A* IDIMouse = nullptr;

	// Keyboard patching
	if ((EQADDR_DIKEYBOARD) && (*EQADDR_DIKEYBOARD) && (EQADDR_DIMOUSE) && (*EQADDR_DIMOUSE))
	{
		IDIDevice = *EQADDR_DIKEYBOARD;
		IDIMouse = *EQADDR_DIMOUSE;
	}

	if ((EQADDR_DIKEYBOARD) && (*EQADDR_DIKEYBOARD))
	{
		IDIDevice = *EQADDR_DIKEYBOARD;

		// typedef HRESULT    (__cdecl *fGetDeviceData)(DWORD,LPDIDEVICEOBJECTDATA,LPDWORD,DWORD);
		uintptr_t* vptr = *(uintptr_t**)&IDIDevice;
		uintptr_t* vtable = (uintptr_t*)*vptr;
		//fGetDeviceData fp = (fGetDeviceData)vtable[10];//GetDeviceData

		// GetDeviceData = IDIDevice->lpVtbl->GetDeviceData;
		GetDeviceData = vtable[10];//GetDeviceData
		EzDetour(GetDeviceData, DInputDataDetour, DInputDataTrampoline);

		// GetDeviceState = IDIDevice->lpVtbl->GetDeviceState;
		GetDeviceState = vtable[9];//GetDeviceState
		EzDetour(GetDeviceState, DInputStateDetour, DInputStateTrampoline);

		// Acquire = IDIDevice->lpVtbl->Acquire;
		Acquire = vtable[7];//Acquire
		EzDetour(Acquire, DInputAcquireDetour, DInputAcquireTrampoline);
	}
}

void ShutdownMQ2DInput()
{
	RemoveDetour(GetDeviceData);
	RemoveDetour(GetDeviceState);
	RemoveDetour(Acquire);
}

} // namespace mq
