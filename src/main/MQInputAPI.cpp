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

#define DIRECTINPUT_VERSION    0x800
#include <dinput.h>

#include <DirectXMath.h>

namespace mq {

static void InputAPI_Initialize();
static void InputAPI_Shutdown();
static void InputAPI_Pulse();

static MQModule s_inputAPIModule = {
	"InputAPI",                    // Name
	true,                          // CanUnload
	InputAPI_Initialize,
	InputAPI_Shutdown,
	InputAPI_Pulse,
};
DECLARE_MODULE_INITIALIZER(s_inputAPIModule);

static bool s_inGetDeviceState = false;
static bool s_inGetDeviceData = false;
static bool s_dinputInitialized = false;

static uintptr_t GetDeviceData = 0;
static uintptr_t GetDeviceState = 0;

enum MQMouseEventType
{
	MD_Unknown = -1,
	MD_Button0 = 0,
};

struct MQQueuedMouseEvent
{
	MQMouseEventType    eventType;
	DWORD               dwData;
	MQQueuedMouseEvent* pNext;
};

static MQQueuedMouseEvent* s_queuedMouseEvents = nullptr;

enum class ItemClickStatus
{
	MouseDown,
	MouseUp,
	None
};

static ItemClickStatus s_groundItemClickStatus = ItemClickStatus::None;

class CDisplay_Detour
{
public:
	DETOUR_TRAMPOLINE_DEF(CActorInterface*, GetClickedActor_Tramp, (int, int, bool, CVector3&, CVector3&))
		CActorInterface* GetClickedActor_Detour(int X, int Y, bool bFlag, CVector3& Vector1, CVector3& Vector2)
	{
		if (s_groundItemClickStatus != ItemClickStatus::None)
		{
			if (s_groundItemClickStatus == ItemClickStatus::MouseDown)
				s_groundItemClickStatus = ItemClickStatus::MouseUp;
			else
				s_groundItemClickStatus = ItemClickStatus::None;

			if (MQGroundSpawn pGroundSpawn = CurrentGroundSpawn())
			{
				if (CActorInterface* pActor = pGroundSpawn.Actor())
					return pActor;
			}
		}

		return GetClickedActor_Tramp(X, Y, bFlag, Vector1, Vector2);
	}
};

DETOUR_TRAMPOLINE_DEF(HRESULT CALLBACK, DInput_GetDeviceData_Trampoline, (IDirectInputDevice8A* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags))
HRESULT CALLBACK DInput_GetDeviceData_Detour(IDirectInputDevice8A* This, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
	s_inGetDeviceData = true;
	DWORD dwInOutSave = *pdwInOut;

	if (!gbUnload && This == g_pDIMouse)
	{
		// If we are waiting for a click-event to be confirmed by EQ, don't
		// pull any data, just return DI_OK and set the pdwInOut value to 0
		if (IsMouseWaitingForButton())
		{
			*pdwInOut = 0;
			s_inGetDeviceData = false;
			return DI_OK;
		}

		if (s_queuedMouseEvents)
		{
			*pdwInOut = 0;
			bool bLoop = true;

			while (bLoop && s_queuedMouseEvents)
			{
				if (*pdwInOut < dwInOutSave)
				{
					bool bRemoveItem = true;

					rgdod[*pdwInOut].dwSequence = 0;
					rgdod[*pdwInOut].dwTimeStamp = 0;
					rgdod[0].uAppData = 0;

					if (s_queuedMouseEvents->eventType >= MD_Button0)
					{
						int button = s_queuedMouseEvents->eventType - MD_Button0;

						rgdod[*pdwInOut].dwData = s_queuedMouseEvents->dwData;
						rgdod[*pdwInOut].dwOfs = DIMOFS_BUTTON0 + button;
						(*pdwInOut)++;
					}

					if (bRemoveItem)
					{
						MQQueuedMouseEvent* pTemp = s_queuedMouseEvents;
						s_queuedMouseEvents = s_queuedMouseEvents->pNext;
						if (pTemp)
							delete pTemp;
					}
				}
				else
				{
					bLoop = false;
				}
			}

			s_inGetDeviceData = false;
			return DI_OK;
		}
	}

	// If we didn't add any keyboard data, and we aren't waiting for a click,
	// and we didn't add any mouse data
	HRESULT hResult = DInput_GetDeviceData_Trampoline(This, cbObjectData, rgdod, pdwInOut, dwFlags);

	s_inGetDeviceData = false;
	return hResult;
}

// IDirectInputDevice8_GetDeviceState
DETOUR_TRAMPOLINE_DEF(HRESULT CALLBACK, DInput_GetDeviceState_Trampoline, (IDirectInputDevice8A* This, DWORD cbData, void* lpvData))
HRESULT CALLBACK DInput_GetDeviceState_Detour(IDirectInputDevice8A* This, DWORD cbData, void* lpvData)
{
	s_inGetDeviceState = true;

	HRESULT hResult = DInput_GetDeviceState_Trampoline(This, cbData, lpvData);

	// We could alter the return here if so desired, if a macro is executing that requires keyboard and mouse input.
	// by setting hResult to DI_OK;

	if (!gbUnload && (cbData == sizeof(DIMOUSESTATE) || cbData == sizeof(DIMOUSESTATE2)))
	{
		LPDIMOUSESTATE data = (LPDIMOUSESTATE)lpvData;

		if (IsMouseWaitingForButton())
		{
			data->rgbButtons[0] = g_pDeviceInputProxy->mouse.CurrentClickState[0];
			data->rgbButtons[1] = g_pDeviceInputProxy->mouse.CurrentClickState[1];
		}
	}

	s_inGetDeviceState = false;
	return hResult;
}

DETOUR_TRAMPOLINE_DEF(int64_t, ProcessDeviceEvents_Trampoline, (SDeviceInputEvent* ev))
int64_t ProcessDeviceEvents_Detour(SDeviceInputEvent* ev)
{
	const bool delayed = (ev->EventStateBitmask & (SDeviceInputState_Blocked | SDeviceInputState_Pending)) == ev->EventStateBitmask;
	const uint8_t status = g_pDeviceInputProxy->events.CurrentEventStatus;

	if (g_pDeviceInputProxy->events.LastEventStatus && delayed)
	{
		g_pDeviceInputProxy->events.CurrentEventStatus = g_pDeviceInputProxy->events.LastEventStatus;
		const int64_t timer = ProcessDeviceEvents_Trampoline(ev);
		return timer;
	}

	g_pDeviceInputProxy->events.CurrentEventStatus = status;

	return ProcessDeviceEvents_Trampoline(ev);
}

static void MouseButtonUp(DWORD x, DWORD y, int mouseButton = -1)
{
	gLClickedObject = false;

	if (mouseButton == 0)
	{
		// click will fail if this isn't set to a time less than TimeStamp minus 750ms
		g_pDeviceInputProxy->mouse.LeftButton = pDisplay->TimeStamp - 69;
		pEverQuest->LMouseUp(x, y);

		CVector3 cv1, cv2;
		if (pDisplay->GetClickedActor(x, y, false, cv1, cv2))
		{
			gLClickedObject = true;
		}
	}
}

bool MoveMouse(int x, int y)
{
	if (!g_pDIMouse)
		return false;

	HWND EQhWnd = *reinterpret_cast<HWND*>(EQADDR_HWND);
	if (!EQhWnd)
		return false;

	CXPoint pt{ x, y };

	ClientToScreen(EQhWnd, reinterpret_cast<LPPOINT>(&pt));
	SetCursorPos(pt.x, pt.y);

	g_pDeviceInputProxy->mouse.Position.Y = y;
	g_pDeviceInputProxy->mouse.Position.X = x;
	EQADDR_MOUSE->Y = y;
	EQADDR_MOUSE->X = x;
	g_pDIMouseState->lY = y;
	g_pDIMouseState->lX = x;

	pWndMgr->MousePoint = pt;
	pWndMgr->StoredMousePos = pt;

	WeDidStuff();
	DebugSpew("Moved mouse to: %d,%d", x, y);
	return true;
}

// ***************************************************************************
// Function: ParseMouseLoc
// Description: Parses mouseloc for /click and /mouseto
// ***************************************************************************
static bool ParseMouseLoc(const char* szMouseLoc)
{
	// determine mouse location - x and y given
	if ((szMouseLoc[0] == '+') || (szMouseLoc[0] == '-') || ((szMouseLoc[0] >= '0') && (szMouseLoc[0] <= '9')))
	{
		char szArg1[MAX_STRING] = { 0 };
		char szArg2[MAX_STRING] = { 0 };

		// x and y were given so lets convert them and move mouse
		GetArg(szArg1, szMouseLoc, 1);
		GetArg(szArg2, szMouseLoc, 2);

		// actual location to click, calculated from ButtonX
		int ClickX = GetIntFromString(szArg1, 0);
		int ClickY = GetIntFromString(szArg2, 0);

		if ((szArg1[0] == '+') || (szArg1[0] == '-') || (szArg2[0] == '+') || (szArg2[0] == '-'))
		{
			// relative location was passed so offset from current
			ClickX += EQADDR_MOUSE->X;
			ClickY += EQADDR_MOUSE->Y;
			DebugSpew("Moving mouse by relative offset");
		}
		else
		{
			DebugSpew("Moving mouse to absolute position");
		}

		return MoveMouse(ClickX, ClickY);
	}

	MacroError("'%s' mouse click is either invalid or should be done using /notify", szMouseLoc);
	return false;
}

bool ClickMouseButton(int mouseButton)
{
	if (mouseButton < 0 || mouseButton >= NUM_MOUSE_BUTTONS) // handle buttons 0-7
		return false;

	MQMouseEventType eventType = static_cast<MQMouseEventType>(MD_Button0 + mouseButton);

	if (!((g_pDeviceInputProxy->mouse.CurrentClickState[mouseButton] == 0x80) && !g_pDeviceInputProxy->mouse.CurrentClickState[mouseButton]))
		g_pDeviceInputProxy->mouse.CurrentClickState[mouseButton] = 0x80;

	gMouseClickInProgress[mouseButton] = true;

	MQQueuedMouseEvent* pData = new MQQueuedMouseEvent;
	pData->eventType = eventType;
	pData->dwData = 0;
	pData->pNext = nullptr;

	if (!s_queuedMouseEvents)
	{
		s_queuedMouseEvents = pData;
	}
	else
	{
		MQQueuedMouseEvent* pTemp = s_queuedMouseEvents;
		while (pTemp->pNext)
		{
			pTemp = pTemp->pNext;
		}
		pTemp->pNext = pData;
	}

	WeDidStuff();
	return true;
}

static void ClickMouseLoc(char* szMouseLoc, char* szButton)
{
	// determine mouse location - x and y given
	if ((szMouseLoc[0] == '+') || (szMouseLoc[0] == '-') || ((szMouseLoc[0] >= '0') && (szMouseLoc[0] <= '9')))
	{
		// x and y were given so lets convert them and move mouse
		char szArg1[MAX_STRING] = { 0 };
		char szArg2[MAX_STRING] = { 0 };

		GetArg(szArg1, szMouseLoc, 1);
		GetArg(szArg2, szMouseLoc, 2);

		// actual location to click, calculated from ButtonX
		int ClickX = GetIntFromString(szArg1, 0);
		int ClickY = GetIntFromString(szArg2, 0);

		if ((szArg1[0] == '+') || (szArg1[0] == '-') || (szArg2[0] == '+') || (szArg2[0] == '-'))
		{
			// relative location was passed so offset from current
			ClickX += EQADDR_MOUSE->X;
			ClickY += EQADDR_MOUSE->Y;
			DebugSpew("Clicking mouse by relative offset");
		}
		else
		{
			DebugSpew("Clicking mouse at absolute position");
		}

		MouseButtonUp(ClickX, ClickY, ci_equals(szButton, "left") ? 0 : -1);
	}
	else
	{
		MacroError("'%s' mouse click is either invalid or should be done using /notify", szMouseLoc);
	}
}

bool ClickMouseItem(const MQGroundSpawn& GroundSpawn, bool left)
{
	if (!pLocalPlayer || !GroundSpawn)
		return false;

	float distance = GroundSpawn.Distance3D(pLocalPlayer);
	if (distance >= 20.f)
	{
		WriteChatf("You are %.2f away from the %s, move within 20 feet of it to click it.", distance, GroundSpawn.Name().c_str());
		return false;
	}

	if (!left) // implied right click
	{
		g_pDeviceInputProxy->mouse.RightButton = pDisplay->TimeStamp - 70;

		if (pWndMgr)
		{
			s_groundItemClickStatus = ItemClickStatus::MouseDown;
			pEverQuest->RMouseUp(pWndMgr->MousePoint.x, pWndMgr->MousePoint.y);
			return true;
		}
	}
	else
	{
		g_pDeviceInputProxy->mouse.LeftButton = pDisplay->TimeStamp - 70;

		// we "click" at -10000,-10000 because we expect that the user doesnt have any windows there.

		s_groundItemClickStatus = ItemClickStatus::MouseDown;
		pEverQuest->LMouseUp(-10000, -10000);
		return true;
	}

	return false;
}

bool IsMouseWaitingForButton()
{
	return !((g_pDeviceInputProxy->mouse.CurrentClickState[1] == g_pDeviceInputProxy->mouse.LastClickState[1])
		&& (g_pDeviceInputProxy->mouse.CurrentClickState[0] == g_pDeviceInputProxy->mouse.LastClickState[0]));
}

bool IsMouseWaiting()
{
	bool Result = false;

	if (IsMouseWaitingForButton())
		Result = true;
	else
	{
		// Here we basically force the MQ script engine to wait for the button up on mouse clicks

		if (gMouseClickInProgress[0])
		{
			if (!((!g_pDeviceInputProxy->mouse.CurrentClickState[0])
				&& (g_pDeviceInputProxy->mouse.LastClickState[0] == 0x80))) g_pDeviceInputProxy->mouse.CurrentClickState[0] = 0;
			gMouseClickInProgress[0] = false;
			Result = true;
		}

		if (gMouseClickInProgress[1])
		{
			if (!((!g_pDeviceInputProxy->mouse.CurrentClickState[1])
				&& (g_pDeviceInputProxy->mouse.LastClickState[1] == 0x80))) g_pDeviceInputProxy->mouse.CurrentClickState[1] = 0;
			gMouseClickInProgress[1] = false;
			Result = true;
		}
	}

	return Result;
}


bool MouseToPlayer(PlayerClient* pPlayer, DWORD position, bool bClick)
{
	if (!gpD3D9Device || !pPlayer)
	{
		return false;
	}

	DirectX::XMVECTOR worldLocation;

	if (position == 1)
	{
		// head
		worldLocation = DirectX::XMVectorSet(pPlayer->Y, pPlayer->X, pPlayer->FloorHeight + pPlayer->AvatarHeight, 0);
	}
	else if (position == 2)
	{
		// feet
		worldLocation = DirectX::XMVectorSet(pPlayer->Y, pPlayer->X, pPlayer->FloorHeight, 0);
	}
	else
	{
		worldLocation = DirectX::XMVectorSet(pPlayer->Y, pPlayer->X, pPlayer->Z, 0);
	}

	eqlib::Direct3DDevice9* pDevice = g_pDrawHandler->pD3DDevice;

	D3DVIEWPORT9 viewport;
	pDevice->GetViewport(&viewport);

	D3DMATRIX mtxProj;
	pDevice->GetTransform(D3DTS_PROJECTION, &mtxProj);
	DirectX::FXMMATRIX projection = XMLoadFloat4x4(reinterpret_cast<const DirectX::XMFLOAT4X4*>(&mtxProj));

	D3DMATRIX mtxView;
	pDevice->GetTransform(D3DTS_VIEW, &mtxView);
	DirectX::CXMMATRIX view = XMLoadFloat4x4(reinterpret_cast<const DirectX::XMFLOAT4X4*>(&mtxView));

	D3DMATRIX mtxWorld;
	pDevice->GetTransform(D3DTS_WORLD, &mtxWorld);
	DirectX::CXMMATRIX world = XMLoadFloat4x4(reinterpret_cast<const DirectX::XMFLOAT4X4*>(&mtxWorld));

	DirectX::XMVECTOR v3ScreenCoord = DirectX::XMVector3Project(worldLocation,
		(float)viewport.X, (float)viewport.Y, (float)viewport.Width, (float)viewport.Height, viewport.MinZ, viewport.MaxZ,
		projection, view, world);

	int x = DirectX::XMVectorGetIntX(v3ScreenCoord);
	int y = DirectX::XMVectorGetIntY(v3ScreenCoord);
	int z = DirectX::XMVectorGetIntZ(v3ScreenCoord);
	if (z >= 1)
	{
		WriteChatf("%s is not within view %.2f", pPlayer->DisplayedName, z);
		return false;
	}

	WriteChatf("%s is at %.2f, %.2f, %.2f before adjustment", pPlayer->DisplayedName, x, y, z);

	MoveMouse(x, y);
	WriteChatf("%s is at %d, %d, %.2f after adjustment and mouse is at %d, %d",
		pPlayer->DisplayedName, x, y, z, EQADDR_MOUSE->X, EQADDR_MOUSE->Y);

	if (bClick)
	{
		MouseButtonUp(x, y, 0);
	}

	return true;
}

void MouseConsume(int mouseButton, bool pressed)
{
	g_pDeviceInputProxy->mouse.CurrentClickState[mouseButton] = pressed;
	g_pDeviceInputProxy->mouse.LastClickState[mouseButton] = pressed;
}


// ***************************************************************************
// Function: Click
// Description: Our '/click' command
// Clicks the mouse button (calls EQ's mouse up commands)
// Usage: /click left|right [<mouseloc>]
// ***************************************************************************
void Click(PlayerClient* pChar, const char* szLine)
{
	// This check protects against many of the pointers in this function being uninitialized
	if (GetGameState() != GAMESTATE_INGAME)
	{
		WriteChatf("/click cannot be used when not in game");
		return;
	}

	if (gZoning) return;

	char szArg1[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);                    // left or right

	char szMouseLoc[MAX_STRING] = { 0 };
	strcpy_s(szMouseLoc, GetNextArg(szLine, 1));  // location to click

	// parse location for click location (szMouseLoc) here
	if (szMouseLoc[0] != 0)
	{
		if (!_strnicmp(szMouseLoc, "target", 6))
		{
			if (!pTarget)
			{
				WriteChatColor("You must have a target selected for /click x target.", CONCOLOR_RED);
				return;
			}

			if (!_strnicmp(szArg1, "left", 4))
			{
				pEverQuest->LeftClickedOnPlayer(pTarget);
				WeDidStuff();
			}
			else if (!_strnicmp(szArg1, "right", 5))
			{
				pEverQuest->RightClickedOnPlayer(pTarget, 0);
				WeDidStuff();
			}
			return;
		}
		else if (!_strnicmp(szMouseLoc, "center", 6))
		{
			sprintf_s(szMouseLoc, "%d %d", ScreenXMax / 2, ScreenYMax / 2);
		}
		else if (!_strnicmp(szMouseLoc, "item", 4))
		{
			if (MQGroundSpawn GroundSpawn = CurrentGroundSpawn())
				ClickMouseItem(GroundSpawn, !_strnicmp(szArg1, "left", 4));
			else
				WriteChatf("No Item targeted, use /itemtarget <theid> before issuing a /click left|right item command.");

			return;
		}
		else if (!_strnicmp(szMouseLoc, "door", 4) || !_strnicmp(szMouseLoc, "switch", 6))
		{
			// a right clicked door spawn does nothing
			if (pSwitchTarget)
			{
				if (!_strnicmp(szArg1, "left", 4))
				{
					if (pSwitchTarget->Name[0] != 0)
					{
						// the distance needs to be calculated by the outer radius of the door and the characters reach...
						float BoundingRadius = 0;

						if (pSwitchTarget->pActor)
						{
							BoundingRadius = pSwitchTarget->pActor->GetBoundingRadius();
						}
						else
						{
							BoundingRadius = pSwitchTarget->ScaleFactor * 0.01f;
						}

						float Dist = GetDistance(pControlledPlayer->Y, pControlledPlayer->X, pSwitchTarget->Y, pSwitchTarget->X);
						float reach = pControlledPlayer->Height + 20.0f + BoundingRadius;

						if (Dist <= reach)
						{
							int KeyID = 0;
							int Skill = 0;

							if (ItemPtr pItem = GetPcProfile()->GetInventorySlot(InvSlot_Cursor))
							{
								switch (pItem->GetItemClass())
								{
								case ItemClass_Key:
									KeyID = pItem->GetID();
									Skill = 0;
									break;

								case ItemClass_Misc: // (some keys have this type)
								case ItemClass_LockPicks:
									KeyID = pItem->GetID();
									Skill = GetAdjustedSkill(SKILL_PICKLOCK);
									break;

								default:
									KeyID = pItem->GetID();
									Skill = 0;
									break;
								}
							}

							pSwitchTarget->UseSwitch(pChar->SpawnID, KeyID, Skill);
							return;
						}
						else
						{
							WriteChatf("You are to far away from the door, please move closer before issuing the /click left door command.");
						}
					}
					else
					{
						WriteChatf("No Door targeted, use /doortarget <theid> before issuing a /click left door command.");
					}
				}
				else
				{
					WriteChatf("Invalid click args, use \"/click left door\", aborting: %s", szMouseLoc);
				}
			}
			else
			{
				WriteChatf("No Door targeted, use /doortarget <theid> before issuing a /click left door command.");
			}
			return;
		}

		ClickMouseLoc(szMouseLoc, szArg1);
		return;
	}

	if (szArg1[0] != 0)
	{
		if (ci_equals(szArg1, "left"))
		{
			ClickMouseButton(0);
		}
		else if (ci_equals(szArg1, "right"))
		{
			ClickMouseButton(1);
		}
		else
		{
			WriteChatColor("Usage: /click <left|right>", USERCOLOR_DEFAULT);
			DebugSpew("Bad command: %s", szLine);
		}
	}
}

// ***************************************************************************
// Function: MouseTo
// Description: Our '/mouseto' command
// Moves the mouse
// Usage: /mouseto <mouseloc>
// ***************************************************************************
void MouseTo(PlayerClient* pChar, const char* szLine)
{
	if (szLine && szLine[0])
	{
		if (ParseMouseLoc(szLine))
		{
			return;
		}
	}

	WriteChatColor("Usage: /mouseto <mouseloc>", USERCOLOR_DEFAULT);
	DebugSpew("Help invoked or Bad MouseTo command: %s", szLine);
}

static void InstallDirectInputHooks()
{
	// hook ProcessDeviceEvents
	EzDetour(__ProcessDeviceEvents, ProcessDeviceEvents_Detour, ProcessDeviceEvents_Trampoline);

	if (g_pDIKeyboard)
	{
		uintptr_t* vtable = *reinterpret_cast<uintptr_t**>(g_pDIKeyboard.get());

		// hook GetDeviceState
		GetDeviceState = vtable[9];
		EzDetour(GetDeviceState, DInput_GetDeviceState_Detour, DInput_GetDeviceState_Trampoline);

		// Hook GetDeviceData
		GetDeviceData = vtable[10];
		EzDetour(GetDeviceData, DInput_GetDeviceData_Detour, DInput_GetDeviceData_Trampoline);

		s_dinputInitialized = true;
	}
}

// EQ's message loop doesn't call TranslateMessage before calling DispatchMessageA, so we never
// receive WM_CHAR event messages, which we need to properly power the input system for imgui,
// so we will hook these functions and force calls to them if EQ doesn't do it for us.

static uintptr_t DispatchMessageA_Ptr = 0;
static uintptr_t TranslateMessage_Ptr = 0;
static thread_local const MSG* s_lastTranslateMessagePtr = nullptr;

DETOUR_TRAMPOLINE_DEF(BOOL WINAPI, TranslateMessage_Trampoline, (const MSG* lpMsg));
static BOOL WINAPI TranslateMessage_Detour(const MSG* lpMsg)
{
	s_lastTranslateMessagePtr = lpMsg;

	return TranslateMessage_Trampoline(lpMsg);
}

DETOUR_TRAMPOLINE_DEF(LRESULT WINAPI, DispatchMessageA_Trampoline, (const MSG* lpMsg));
static LRESULT WINAPI DispatchMessageA_Detour(const MSG* lpMsg)
{
	if (s_lastTranslateMessagePtr != lpMsg)
	{
		TranslateMessage_Trampoline(lpMsg);
	}

	s_lastTranslateMessagePtr = nullptr;

	return DispatchMessageA_Trampoline(lpMsg);
}

static void InputAPI_Initialize()
{
	DebugSpew("Initializing Input");

	TranslateMessage_Ptr = (uintptr_t)GetProcAddress(GetModuleHandleA("USER32"), "TranslateMessage");
	EzDetour(TranslateMessage_Ptr, &TranslateMessage_Detour, &TranslateMessage_Trampoline);
	DispatchMessageA_Ptr = (uintptr_t)GetProcAddress(GetModuleHandleA("USER32"), "DispatchMessageA");
	EzDetour(DispatchMessageA_Ptr, &DispatchMessageA_Detour, &DispatchMessageA_Trampoline);

	EzDetour(CDisplay__GetClickedActor, &CDisplay_Detour::GetClickedActor_Detour, &CDisplay_Detour::GetClickedActor_Tramp);
}

void InputAPI_Shutdown()
{
	DebugSpew("Shutting down Input");

	RemoveDetour(CDisplay__GetClickedActor);
	RemoveDetour(TranslateMessage_Ptr);
	RemoveDetour(DispatchMessageA_Ptr);

	if (s_dinputInitialized)
	{
		RemoveDetour(GetDeviceData);
		RemoveDetour(GetDeviceState);
	}

	RemoveDetour(__ProcessDeviceEvents);
}

void InputAPI_Pulse()
{
	if (!s_dinputInitialized)
	{
		InstallDirectInputHooks();

		// If we're initialized we do not need to pulse anymore.
		if (s_dinputInitialized)
		{
			s_inputAPIModule.Pulse = nullptr;
		}
	}
}

} // namespace mq
