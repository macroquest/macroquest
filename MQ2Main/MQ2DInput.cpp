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

#include "MQ2Main.h"

#include "..\Dxsdk90\include\dinput.h"

static bool gbInDState = false;
static bool gbInDAcquire = false;
static bool gbInDInput = false;

// ***************************************************************************
// Function:    DInputDataDetour
// Description: Our DirectInput GetDeviceState Hook
// ***************************************************************************

HRESULT (CALLBACK* DInputDataTrampoline)(IDirectInputDevice8A* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
HRESULT CALLBACK DInputDataDetour(IDirectInputDevice8A* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
	gbInDInput = true;
	HRESULT hResult = 0;
	KEYPRESS* pNext = nullptr;
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
	if (DInputDataTrampoline)
	{
		hResult = DInputDataTrampoline(This, cbObjectData, rgdod, pdwInOut, dwFlags);
	}

	if (gbUnload)
	{
		gbInDInput = false;
		return hResult;
	}

	gbInDInput = false;
	return hResult;
}

HRESULT (CALLBACK* DInputStateTrampoline)(IDirectInputDevice8A* This, DWORD cbData, void* lpvData);
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

HRESULT (CALLBACK* DInputAcquireTrampoline)(IDirectInputDevice8A* This);
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

DWORD GetDeviceData = 0;
DWORD GetDeviceState = 0;
DWORD Acquire = 0;

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
		int* vptr = *(int**)&IDIDevice;
		int* vtable = (int*)*vptr;
		//fGetDeviceData fp = (fGetDeviceData)vtable[10];//GetDeviceData

		// GetDeviceData = (unsigned int)IDIDevice->lpVtbl->GetDeviceData;
		GetDeviceData = (unsigned int)vtable[10];//GetDeviceData
		AddDetour(GetDeviceData);

		// GetDeviceState = (unsigned int)IDIDevice->lpVtbl->GetDeviceState;
		GetDeviceState = (unsigned int)vtable[9];//GetDeviceState
		AddDetour(GetDeviceState);

		// Acquire = (unsigned int)IDIDevice->lpVtbl->Acquire;
		Acquire = (unsigned int)vtable[7];//Acquire
		AddDetour(Acquire);

		// Grab GetDeviceData
		(*(BYTE**)& DInputDataTrampoline) = DetourFunction((BYTE*)GetDeviceData, (BYTE*)DInputDataDetour);
		// Grab GetDeviceState
		(*(BYTE**)&DInputStateTrampoline) = DetourFunction((BYTE*)GetDeviceState, (BYTE*)DInputStateDetour);
		// Grab Acquire
		(*(BYTE**)&DInputAcquireTrampoline) = DetourFunction((BYTE*)Acquire, (BYTE*)DInputAcquireDetour);
	}
}

void ShutdownMQ2DInput()
{
	if (DInputDataTrampoline && DetourRemove((BYTE*)DInputDataTrampoline, (BYTE*)DInputDataDetour))
	{
		RemoveDetour(GetDeviceData);
		DInputDataTrampoline = nullptr;
	}
	else
	{
		if (DInputDataTrampoline)
		{
			DebugSpewAlways("Failed to unhook DInputData");
		}
	}

	if (DInputStateTrampoline && DetourRemove((BYTE*)DInputStateTrampoline, (BYTE*)DInputStateDetour))
	{
		RemoveDetour(GetDeviceState);
		DInputStateTrampoline = nullptr;
	}
	else
	{
		if (DInputStateTrampoline)
		{
			DebugSpewAlways("Failed to unhook DInputState");
		}
	}

	if (DInputAcquireTrampoline && DetourRemove((BYTE*)DInputAcquireTrampoline, (BYTE*)DInputAcquireDetour))
	{
		RemoveDetour(Acquire);
		DInputAcquireTrampoline = nullptr;
	}
	else
	{
		if (DInputAcquireTrampoline)
		{
			DebugSpewAlways("Failed to unhook DInputAcquire");
		}
	}
}
