/***************************************************************************** 
eqlib.dll: MacroQuest's extension DLL for EverQuest 
Copyright (C) 2002-2003 Plazmic 

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

#define DBG_SPEW 

#include "MQ2Main.h" 

// ***************************************************************************
// Function:    DInputDataDetour
// Description: Our DirectInput GetDeviceState Hook
// ***************************************************************************
VOID TestHotkeys(LPDIDEVICEOBJECTDATA rgdod, DWORD Count)
{
    DWORD index;
    for (index=0;index<Count;index++) {
        if (rgdod[index].dwData != 0x80) continue;
        PHOTKEY pLoop = pHotkey;
		PCHARINFO pCharInfo=GetCharInfo();
		if (!pCharInfo || !pCharInfo->pSpawn)
			return;
        while (pLoop) {
            if (rgdod[index].dwOfs == pLoop->DIKey) {
                DoCommand(pCharInfo->pSpawn,pLoop->szCommand);
            }
            pLoop = pLoop->pNext;
        }
    }
}

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
       if   (EQADDR_DIKEYBOARD && (This   == *EQADDR_DIKEYBOARD))
       {
         if (*pdwInOut >   0)
         {
            if (gKeyStack)
            {
               //DebugSpew("DInputDataDetour::KeyStack");

                  pNext =   gKeyStack->pNext;
                  //DebugSpew("Faking   '%s' as   %s...",gDiKeyID[gKeyStack->KeyId].szName,(gKeyStack->Pressed)?"down":"up");
                  rgdod[didAdd].dwOfs   = gDiKeyID[gKeyStack->KeyId].Id;
                  rgdod[didAdd].dwData = (gKeyStack->Pressed)?0x80:0;
                  rgdod[didAdd].dwSequence = dwSequence;
                  rgdod[didAdd].dwTimeStamp =   dwTimeStamp;
                  rgdod[didAdd].uAppData = 0;
                  (*pdwInOut)--;
                  free(gKeyStack);
                  gKeyStack =   pNext;
                  didAdd++;

               (*pdwInOut)   = didAdd;
               gbInDInput = FALSE;
               return (HRESULT)DI_OK;
         }
                }
       }else if (EQADDR_DIMOUSE && (This == *EQADDR_DIMOUSE))
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
//            PMOUSEINFO MouseInfo = EQADDR_MOUSE;
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
   if (EQADDR_DIKEYBOARD && (This == *EQADDR_DIKEYBOARD) && EQADDR_NOTINCHATMODE && *EQADDR_NOTINCHATMODE && pHotkey) TestHotkeys(&(rgdod[didAdd]),*pdwInOut);
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
         ((LPDIMOUSESTATE)lpvData)->rgbButtons[0] = EQADDR_MOUSECLICK->LeftClick;
         ((LPDIMOUSESTATE)lpvData)->rgbButtons[1] = EQADDR_MOUSECLICK->RightClick;
      }
   }
   // Commented 11-11-2003 Lax
   // Unused..
/*
   if (cbData == 256)  // Checking keyboard state here for keys that are down.  Do we ever get called with this?
   {
      if (!bOneTime)
      {
         bOneTime=TRUE;
         DebugSpew("Well, whadya know, keyboard state checking");
      }
      PBYTE pKeyState = (PBYTE)lpvData;
      if ((pKeyState[0x36] & 0x80) && (pKeyState[0x2A] & 0x80))
      {
         DebugSpewAlways("Simultaneous Shift Characters pressed");
      }
   }
*/
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
			AddDetour((unsigned int) IDIDevice->lpVtbl->GetDeviceData);
			AddDetour((unsigned int) IDIDevice->lpVtbl->GetDeviceState);
			AddDetour((unsigned int) IDIDevice->lpVtbl->Acquire);
                        
         //Grab GetDeviceData 
         (*(PBYTE*)&DInputDataTrampoline) = DetourFunction((PBYTE)IDIDevice->lpVtbl->GetDeviceData, 
            (PBYTE)DInputDataDetour); 
         //Grab GetDeviceState 
         (*(PBYTE*)&DInputStateTrampoline) = DetourFunction((PBYTE)IDIDevice->lpVtbl->GetDeviceState, 
            (PBYTE)DInputStateDetour); 
         //Grab Acquire 
         (*(PBYTE*)&DInputAcquireTrampoline) = DetourFunction((PBYTE)IDIDevice->lpVtbl->Acquire, 
            (PBYTE)DInputAcquireDetour); 
   }
}

VOID ShutdownMQ2DInput() 
{
         if (DetourRemove((PBYTE)DInputDataTrampoline, 
            (PBYTE)DInputDataDetour)) 
            DInputDataTrampoline = NULL; 
         else 
            DebugSpewAlways("Failed to unhook DInputData"); 
         if (DetourRemove((PBYTE)DInputStateTrampoline, 
            (PBYTE)DInputStateDetour)) 
            DInputStateTrampoline = NULL; 
         else 
            DebugSpewAlways("Failed to unhook DInputState"); 
         if (DetourRemove((PBYTE)DInputAcquireTrampoline, 
            (PBYTE)DInputAcquireDetour)) 
            DInputAcquireTrampoline = NULL; 
         else 
            DebugSpewAlways("Failed to unhook DInputAcquire"); 
}

