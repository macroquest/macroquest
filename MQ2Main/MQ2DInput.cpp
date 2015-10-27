/***************************************************************************** 
MQ2Main.dll: MacroQuest2's extension DLL for EverQuest 
Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

This program is free software; you can redistribute it and/or modify 
it under the terms of the GNU General Public License, version 2, as published by 
the Free Software Foundation. 

This program is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
GNU General Public License for more details. 
******************************************************************************/ 

#if !defined(CINTERFACE) 
#error /DCINTERFACE 
#endif 

#ifndef ISXEQ
#define DBG_SPEW 

#include "MQ2Main.h" 

// ***************************************************************************
// Function:    DInputDataDetour
// Description: Our DirectInput GetDeviceState Hook
// ***************************************************************************

HRESULT (__stdcall *DInputDataTrampoline)(IDirectInputDevice8A* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);
HRESULT __stdcall DInputDataDetour(IDirectInputDevice8A* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
    gbInDInput = TRUE;
    HRESULT hResult = 0;
    PKEYPRESS pNext = NULL;
    DWORD didAdd = 0;
    BOOL bLoop;
    BOOL bRemoveItem = FALSE;
    DWORD dwInOutSave = *pdwInOut;
    DWORD dwTimeStamp = 0;
    DWORD dwSequence   = 0;


    if (!gbUnload)
    {
        if (EQADDR_DIMOUSE && (This == *EQADDR_DIMOUSE))
        {
            // If we are waiting for a click-event to be confirmed by EQ, don't
            // pull any data, just return DI_OK and set the pdwInOut value to 0
            if (IsMouseWaitingForButton())
            {
                hResult   = DI_OK;
                *pdwInOut =   0;
                gbInDInput   = FALSE;
                return hResult;
            }

            if (EQADDR_MOUSE && gMouseData) {
                *pdwInOut = 0;
                bLoop = TRUE;
                while ((bLoop == TRUE) && (gMouseData)) {
                    bRemoveItem = TRUE;
                    if (*pdwInOut < dwInOutSave) {
                        rgdod[*pdwInOut].dwSequence = dwSequence;
                        rgdod[*pdwInOut].dwTimeStamp = dwTimeStamp;
                        rgdod[0].uAppData = 0;
                        switch (gMouseData->mdType) {
						 case MD_Button0Click:
							 DebugSpew("Trying to click left button.");
							 rgdod[*pdwInOut].dwData = 0x80;
							 rgdod[*pdwInOut].dwOfs = DIMOFS_BUTTON0;
							 gMouseData->mdType = MD_Button0;
							 gMouseData->dwData = 0x00;
							 bRemoveItem = FALSE;
							 bLoop = FALSE;
							 (*pdwInOut)++;
							 break;
						 case MD_Button1Click:
							 DebugSpew("Trying to click right button.");
							 rgdod[*pdwInOut].dwData = 0x80;
							 rgdod[*pdwInOut].dwOfs = DIMOFS_BUTTON1;
							 gMouseData->mdType = MD_Button1;
							 gMouseData->dwData = 0x00;
							 bRemoveItem = FALSE;
							 bLoop = FALSE;
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
                        if (bRemoveItem==TRUE) {
                            PMOUSESPOOF pTemp = gMouseData;
                            gMouseData = gMouseData->pNext;
                            if(pTemp)
								free(pTemp);
                        }
                    } else {
                        bLoop = FALSE;
                    }
                }
                gbInDInput = FALSE;
                return (HRESULT)DI_OK;
            }
        }
    }
    // If we didn't add any keyboard data, and we aren't waiting for a click,
    // and we didn't add any mouse data
    hResult = DInputDataTrampoline(This, cbObjectData, rgdod, pdwInOut, dwFlags);
    if (gbUnload) {
        gbInDInput = FALSE;
        return hResult;
    }

    gbInDInput = FALSE;
    return hResult;
}

HRESULT (__stdcall *DInputStateTrampoline)(IDirectInputDevice8A* This, DWORD cbData, LPVOID lpvData);
HRESULT __stdcall DInputStateDetour(IDirectInputDevice8A* This, DWORD cbData, LPVOID lpvData)
{
    HRESULT hResult = S_OK;
    DWORD dwBuffSize = 0;
    BOOL bOneTime = FALSE;

    gbInDState = TRUE;
    hResult = DInputStateTrampoline(This, cbData, lpvData);
    // We could alter the return here if so desired, if a macro is executing that requires keyboard and mouse input.
    // by setting hResult to DI_OK;
    if (hResult == DIERR_INPUTLOST || hResult == DIERR_NOTACQUIRED)
    {
        bDetMouse = FALSE;
    }
    if (gbUnload) {
        gbInDState = FALSE;
        return hResult;
    }
    if ((cbData == sizeof(DIMOUSESTATE)) || (cbData == sizeof(DIMOUSESTATE2)))
    {
        if(IsMouseWaitingForButton() && (EQADDR_MOUSECLICK))
        {
            ((LPDIMOUSESTATE)lpvData)->rgbButtons[0] = EQADDR_MOUSECLICK->Click[0];
            ((LPDIMOUSESTATE)lpvData)->rgbButtons[1] = EQADDR_MOUSECLICK->Click[1];
        }
    }

    gbInDState = FALSE;
    return hResult;
}

HRESULT (__stdcall *DInputAcquireTrampoline)(IDirectInputDevice8A* This);
HRESULT __stdcall DInputAcquireDetour(IDirectInputDevice8A* This)
{
    HRESULT hResult = S_OK;
    DWORD dwBuffSize = 0;

    gbInDAcquire = TRUE;
    hResult = DInputAcquireTrampoline(This);
    // Could alter the return here to allow background macro execution with keyboard and mouse input
    if (hResult != DI_OK && hResult != S_FALSE) // Mouse wasn't acquired successfully
    {
        bDetMouse = FALSE;
    }
    if (gbUnload) {
        gbInDAcquire = FALSE;
        return hResult;
    }
    gbInDAcquire = FALSE;
    return hResult;
}



// externals from EQLib_Main.cpp 
extern HRESULT (__stdcall *DInputDataTrampoline)(IDirectInputDevice8A* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags); 
extern HRESULT __stdcall DInputDataDetour(IDirectInputDevice8A* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags); 
extern HRESULT (__stdcall *DInputStateTrampoline)(IDirectInputDevice8A* This, DWORD cbData, LPVOID lpvData); 
extern HRESULT __stdcall DInputStateDetour(IDirectInputDevice8A* This, DWORD cbData, LPVOID lpvData); 
extern HRESULT (__stdcall *DInputAcquireTrampoline)(IDirectInputDevice8A* This); 
extern HRESULT __stdcall DInputAcquireDetour(IDirectInputDevice8A* This); 

DWORD GetDeviceData=0;
DWORD GetDeviceState=0;
DWORD Acquire=0;

VOID InitializeMQ2DInput() 
{
    DebugSpew("Initializing DInput");
    IDirectInputDevice8A *IDIDevice = NULL; 
    IDirectInputDevice8A *IDIMouse = NULL; 
    // Keyboard patching 
    if ((EQADDR_DIKEYBOARD) && (*EQADDR_DIKEYBOARD) && (EQADDR_DIMOUSE) && (*EQADDR_DIMOUSE)) 
    { 
        IDIDevice = *EQADDR_DIKEYBOARD; 
        IDIMouse = *EQADDR_DIMOUSE; 
        if ((unsigned int)IDIDevice->lpVtbl->GetDeviceData == (unsigned int)IDIMouse->lpVtbl->GetDeviceData) 
            DebugSpew("Mouse and Keyboard have same GetDeviceData"); 
        if ((unsigned int)IDIDevice->lpVtbl->GetDeviceState == (unsigned int)IDIMouse->lpVtbl->GetDeviceState) 
            DebugSpew("Mouse and Keyboard have same GetDeviceState"); 
        if ((unsigned int)IDIDevice->lpVtbl->Acquire == (unsigned int)IDIMouse->lpVtbl->Acquire) 
            DebugSpew("Mouse and Keyboard have same Acquire"); 
    } 
    if ((EQADDR_DIKEYBOARD) && (*EQADDR_DIKEYBOARD)) { 
        IDIDevice = *EQADDR_DIKEYBOARD; 
        AddDetour(GetDeviceData=(unsigned int) IDIDevice->lpVtbl->GetDeviceData);
        AddDetour(GetDeviceState=(unsigned int) IDIDevice->lpVtbl->GetDeviceState);
        AddDetour(Acquire=(unsigned int) IDIDevice->lpVtbl->Acquire);

        //Grab GetDeviceData 
        (*(PBYTE*)&DInputDataTrampoline) = DetourFunction((PBYTE)GetDeviceData, 
            (PBYTE)DInputDataDetour); 
        //Grab GetDeviceState 
        (*(PBYTE*)&DInputStateTrampoline) = DetourFunction((PBYTE)GetDeviceState, 
            (PBYTE)DInputStateDetour); 
        //Grab Acquire 
        (*(PBYTE*)&DInputAcquireTrampoline) = DetourFunction((PBYTE)Acquire, 
            (PBYTE)DInputAcquireDetour); 
    }
}

VOID ShutdownMQ2DInput() 
{
    if (DetourRemove((PBYTE)DInputDataTrampoline, 
        (PBYTE)DInputDataDetour)) 
    {
        RemoveDetour(GetDeviceData);
        DInputDataTrampoline = NULL; 
    }
    else 
        DebugSpewAlways("Failed to unhook DInputData"); 
    if (DetourRemove((PBYTE)DInputStateTrampoline, 
        (PBYTE)DInputStateDetour)) 
    {
        RemoveDetour(GetDeviceState);
        DInputStateTrampoline = NULL; 
    }
    else 
        DebugSpewAlways("Failed to unhook DInputState"); 
    if (DetourRemove((PBYTE)DInputAcquireTrampoline, 
        (PBYTE)DInputAcquireDetour)) 
    {
        RemoveDetour(Acquire);
        DInputAcquireTrampoline = NULL; 
    }
    else 
        DebugSpewAlways("Failed to unhook DInputAcquire"); 
}

#endif
