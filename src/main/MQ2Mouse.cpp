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

#include "pch.h"
#include "MQ2Main.h"

#include <DirectXMath.h>

namespace mq {

static void MouseButtonUp(DWORD x, DWORD y, char* szButton);

// if we don't track item clicks like this, then _any_ click will result in a ground item click attempt
enum class ItemClickStatus
{
	MouseDown,
	MouseUp,
	None
};

ItemClickStatus itemClickStatus = ItemClickStatus::None;


class CDisplay_Detour
{
public:
	DETOUR_TRAMPOLINE_DEF(CActorInterface*, GetClickedActor_Tramp, (int, int, bool, CVector3&, CVector3&))
	CActorInterface* GetClickedActor_Detour(int X, int Y, bool bFlag, CVector3& Vector1, CVector3& Vector2)
	{
		if (itemClickStatus != ItemClickStatus::None)
		{
			if (itemClickStatus == ItemClickStatus::MouseDown)
				itemClickStatus = ItemClickStatus::MouseUp;
			else
				itemClickStatus = ItemClickStatus::None;

			auto pGroundSpawn = CurrentGroundSpawn();
			if (pGroundSpawn)
			{
				auto pActor = pGroundSpawn.Actor();
				if (pActor)
					return pActor;
			}
		}

		return GetClickedActor_Tramp(X, Y, bFlag, Vector1, Vector2);
	}
};

void InitializeMouseHooks()
{
	EzDetour(CDisplay__GetClickedActor, &CDisplay_Detour::GetClickedActor_Detour, &CDisplay_Detour::GetClickedActor_Tramp);
}

void ShutdownMouseHooks()
{
	RemoveDetour(CDisplay__GetClickedActor);
}

// ***************************************************************************
// Function: ParseMouseLoc
// Description: Parses mouseloc for /click and /mouseto
// ***************************************************************************
//Function used by ParseLocationXML to extract parameter
// ExtractValue - gets value between specified start and end markers
// - Parameters:
// szFile - pointer to string to look in
// szStart - pointer to string to mark start of value
// szEnd - pointer to string to mark end of value
// szValue - pointer to string to contain the value found
// - Return Value:
// if successful, return TRUE, szValue contains the value between the start and end markers
// if unsuccessful, return FALSE
static bool ExtractValue(char* szFile, char* szStart, char* szEnd, char* szValue)
{
	// verify we have legal pointers passed to us
	if (!szValue)
		return false;

	if (!szFile || !szStart || !szEnd)
	{
		szValue[0] = 0;
		return false;
	}

	size_t lenStart = strlen(szStart);
	char* fence = strstr(szFile, "ScreenID"); // needed to make sure we don't start into another element

	char* sub = strstr(szFile, szStart);
	char* sub2 = strstr(szFile, szEnd);
	if (!sub || !sub2 || (fence && (sub > fence))) {
		szValue[0] = 0;
		return false;
	}

	memcpy(szValue, sub + lenStart, (sub2 - sub) - lenStart);
	szValue[(sub2 - sub) - lenStart] = 0;
	DebugSpew("Value extracted for %s was %s", szStart, szValue);
	return true;
}

bool MoveMouse(int x, int y, bool bClick)
{
	if (!EQADDR_MOUSE)
		return false;

	HWND EQhWnd = *(HWND*)EQADDR_HWND;
	if (!EQhWnd)
		return false;

	CXPoint pt{ x, y };

	ClientToScreen(EQhWnd, (LPPOINT)& pt);
	SetCursorPos(pt.x, pt.y);

	pEverQuestInfo->MouseY = y;
	pEverQuestInfo->MouseX = x;
	EQADDR_MOUSE->Y = pEverQuestInfo->MouseY;
	EQADDR_DIMOUSECHECK->y = pEverQuestInfo->MouseY;
	EQADDR_MOUSE->X = pEverQuestInfo->MouseX;
	EQADDR_DIMOUSECHECK->x = pEverQuestInfo->MouseX;

	pWndMgr->MousePoint = pt;
	pWndMgr->StoredMousePos = pt;

	if (bClick)
	{
		MouseButtonUp(x, y, "left");
	}

	WeDidStuff();
	DebugSpew("Moved mouse to: %d,%d", x, y);
	return true;
}

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

// TODO: Expand this to support mouse buttons 3->8
void ClickMouse(DWORD button)
{
	if (button > 1)
		return;

	DWORD mdType = (DWORD)MD_Button0 + button;

	if (!((pEverQuestInfo->MouseButtons[button] == 0x80) && !pEverQuestInfo->OldMouseButtons[button]))
		pEverQuestInfo->MouseButtons[button] = 0x80;

	gMouseClickInProgress[button] = true;

	WeDidStuff();

	if (MOUSESPOOF* pData = new MOUSESPOOF)
	{
		pData->mdType = (MOUSE_DATA_TYPES)mdType;
		pData->dwData = 0;
		pData->pNext = nullptr;

		if (!gMouseData)
		{
			gMouseData = pData;
		}
		else
		{
			MOUSESPOOF* pTemp = gMouseData;
			while (pTemp->pNext)
			{
				pTemp = pTemp->pNext;
			}
			pTemp->pNext = pData;
		}
	}
}

void MouseButtonUp(DWORD x, DWORD y, char* szButton)
{
	CVector3 cv1, cv2;
	gLClickedObject = false;

	if (!_strnicmp(szButton, "left", 4))
	{
		// click will fail if this isn't set to a time less than TimeStamp minus 750ms
		pEverQuestInfo->LMouseDown = pDisplay->TimeStamp - 69;
		pEverQuest->LMouseUp(x, y);

		if (pDisplay->GetClickedActor(x, y, false, cv1, cv2))
		{
			gLClickedObject = true;
		}
	}
}

void ClickMouseLoc(char* szMouseLoc, char* szButton)
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

		MouseButtonUp(ClickX, ClickY, szButton);
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

	auto distance = GroundSpawn.Distance3D(pLocalPlayer);
	if (distance >= 20.f)
	{
		WriteChatf("You are %.2f away from the %s, move within 20 feet of it to click it.", distance, GroundSpawn.Name().c_str());
		return false;
	}

	if (!left) // implied right click
	{
		pEverQuestInfo->RMouseDown = pDisplay->TimeStamp - 70;

		if (pWndMgr)
		{
			itemClickStatus = ItemClickStatus::MouseDown;
			pEverQuest->RMouseUp(pWndMgr->MousePoint.x, pWndMgr->MousePoint.y);
			return true;
		}
	}
	else
	{
		pEverQuestInfo->LMouseDown = pDisplay->TimeStamp - 70;

		// we "click" at -10000,-10000 because we expect that the user doesnt have any windows there.

		itemClickStatus = ItemClickStatus::MouseDown;
		pEverQuest->LMouseUp(-10000, -10000);
		return true;
	}

	return false;
}

// ***************************************************************************
// Function: Click
// Description: Our '/click' command
// Clicks the mouse button (calls EQ's mouse up commands)
// Usage: /click left|right [<mouseloc>]
// ***************************************************************************
bool IsMouseWaitingForButton()
{
	return !((pEverQuestInfo->MouseButtons[1] == pEverQuestInfo->OldMouseButtons[1])
		&& (pEverQuestInfo->MouseButtons[0] == pEverQuestInfo->OldMouseButtons[0]));
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
			if (!((!pEverQuestInfo->MouseButtons[0])
				&& (pEverQuestInfo->OldMouseButtons[0] == 0x80))) pEverQuestInfo->MouseButtons[0] = 0;
			gMouseClickInProgress[0] = false;
			Result = true;
		}

		if (gMouseClickInProgress[1])
		{
			if (!((!pEverQuestInfo->MouseButtons[1])
				&& (pEverQuestInfo->OldMouseButtons[1] == 0x80))) pEverQuestInfo->MouseButtons[1] = 0;
			gMouseClickInProgress[1] = false;
			Result = true;
		}
	}

	return Result;
}

void Click(SPAWNINFO* pChar, char* szLine)
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
			auto GroundSpawn = CurrentGroundSpawn();
			if (GroundSpawn)
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
		if (!_strnicmp(szArg1, "left", 4))
		{
			ClickMouse(0);
		}
		else if (!_strnicmp(szArg1, "right", 5))
		{
			ClickMouse(1);
		}
		else
		{
			WriteChatColor("Usage: /click <left|right>", USERCOLOR_DEFAULT);
			DebugSpew("Bad command: %s", szLine);
			return;
		}
	}
}

// ***************************************************************************
// Function: MouseTo
// Description: Our '/mouseto' command
// Moves the mouse
// Usage: /mouseto <mouseloc>
// ***************************************************************************
void MouseTo(SPAWNINFO* pChar, char* szLine)
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

	MoveMouse(x, y, bClick);
	WriteChatf("%s is at %d, %d, %.2f after adjustment and mouse is at %d, %d",
		pPlayer->DisplayedName, x, y, z, EQADDR_MOUSE->X, EQADDR_MOUSE->Y);

	return true;
}

} // namespace mq
