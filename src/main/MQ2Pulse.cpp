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
#include "MQCommandAPI.h"
#include "MQPluginHandler.h"
#include "MQPostOffice.h"

#include <random>

#pragma comment(lib, "argon2")

using namespace eqlib;

namespace mq {

bool TurnNotDone = false;

//----------------------------------------------------------------------------
extern uint64_t s_commandCount;

static bool DoNextCommand(MQMacroBlockPtr pBlock)
{
	if (!pControlledPlayer || !pLocalPC)
		return false;
	if (!pLocalPlayer)
		return false;

	// Don't process commands until current /face is done
	if (((gFaceAngle != 10000.0f) || (gLookAngle != 10000.0f)) && TurnNotDone)
		return false;

	// Don't process command if we're in the middle of a mouse click.
	if (IsMouseWaiting())
		return false;

	if (gDelay && gDelayCondition[0])
	{
		char szCond[MAX_STRING];
		strcpy_s(szCond, gDelayCondition);

		ParseMacroData(szCond, MAX_STRING);

		double Result;
		if (!Calculate(szCond, Result))
		{
			FatalError("Failed to parse /delay condition '%s', non-numeric encountered", szCond);
			return false;
		}

		if (Result != 0)
		{
			DebugSpewNoFile("/delay ending early, conditions met");
			gDelay = 0;
		}
	}

	if (!gDelay && pBlock && !pBlock->Paused && (!gMQPauseOnChat || pEverQuestInfo->KeyboardMode) && gMacroStack)
	{
		const MQMacroLine& ml = pBlock->Line.at(pBlock->CurrIndex);

		if (pBlock->BindStackIndex == pBlock->CurrIndex)
		{
			gBindInProgress = false;
			pBlock->BindStackIndex = -1;
		}

		gMacroStack->LocationIndex = pBlock->CurrIndex;
#ifdef MQ2_PROFILING
		LARGE_INTEGER BeforeCommand;
		QueryPerformanceCounter(&BeforeCommand);
		int ThisMacroBlock = pBlock->CurrIndex;
#endif

		if (gbInZone && !gZoning)
		{
			DoCommand(ml.Command.c_str(), false);
			MQMacroBlockPtr pCurrentBlock = GetCurrentMacroBlock();

			if (!pCurrentBlock)
				return false;

			if (!pCurrentBlock->BindCmd.empty() && pCurrentBlock->BindStackIndex == -1)
			{
				// Only trigger queued bind on select commands
				if (ci_find_substr(ml.Command, "/varset") == 0
					|| ci_find_substr(ml.Command, "/echo") == 0
					|| ci_find_substr(ml.Command, "Sub") == 0
					|| ci_find_substr(ml.Command, "/call") == 0
					|| ci_find_substr(ml.Command, "/invoke") == 0)
				{
					auto iter = pCurrentBlock->Line.find(pCurrentBlock->CurrIndex);
					if (iter != pCurrentBlock->Line.end())
					{
						if (++iter != pCurrentBlock->Line.end())
						{
							pCurrentBlock->BindStackIndex = iter->first;
						}
						else
						{
							FatalError("Reached end of macro.");
						}
					}

					Call(pLocalPlayer, (char*)pCurrentBlock->BindCmd.c_str());
					pCurrentBlock->BindCmd.clear();
				}
			}

#ifdef MQ2_PROFILING
			LARGE_INTEGER AfterCommand;
			QueryPerformanceCounter(&AfterCommand);
			pCurrentBlock->Line[ThisMacroBlock].ExecutionCount++;
			pCurrentBlock->Line[ThisMacroBlock].ExecutionTime += AfterCommand.QuadPart - BeforeCommand.QuadPart;
#endif

			const int lastindex = pCurrentBlock->Line.rbegin()->first;
			if (pCurrentBlock->CurrIndex > lastindex)
			{
				FatalError("Reached end of macro.");
			}
			else
			{
				auto iter = pCurrentBlock->Line.find(pCurrentBlock->CurrIndex);
				if (iter != pCurrentBlock->Line.end())
				{
					if (++iter != pCurrentBlock->Line.end())
					{
						pCurrentBlock->CurrIndex = iter->first;
					}
				}
				else
				{
					FatalError("Reached end of macro.");
				}
			}

			s_commandCount++;
			return true;
		}
	}

	return false;
}

static void Heartbeat()
{
	static uint64_t LastGetTick = 0;
	static bool bFirstHeartBeat = true;
	static uint64_t TickDiff = 0;
	static DWORD BeatCount = 0;

	uint64_t Tick = MQGetTickCount64();

	BeatCount++;

	if (bFirstHeartBeat)
	{
		LastGetTick = Tick;
		bFirstHeartBeat = false;
	}

	// This accounts for rollover
	TickDiff += (Tick - LastGetTick);
	LastGetTick = Tick;

	while (TickDiff >= 100)
	{
		TickDiff -= 100;
		if (gDelay > 0) gDelay--;
		DropTimers();
	}

	bRunNextCommand = true;

	if (gGameState != -1)
	{
		int CurTurbo = 0;

		MQMacroBlockPtr pBlock = GetNextMacroBlock();
		while (bRunNextCommand)
		{
			if (!pBlock)
				break;
			if (!DoNextCommand(pBlock))
				break;
			if (gbUnload)
				return;
			if (!gTurbo)
				break;
			if (++CurTurbo > gMaxTurbo)
				break;

			// re-fetch current macro block in case one of the previous instructions changed it
			pBlock = GetCurrentMacroBlock();
		}
	}
}

class PulseModule : public MQModuleBase
{
public:
	PulseModule() : MQModuleBase("Pulse")
	{
	}

	virtual void Initialize() override
	{
	}

	virtual void OnProcessFrame() override
	{
		gbInForeground = GetForegroundWindow() == GetEQWindowHandle();

		if (pControlledPlayer != nullptr && !gZoning)
		{
			uint64_t ticks = MQGetTickCount64();

			// Update gbMoving
			if (m_lastX != pControlledPlayer->X
				|| m_lastY != pControlledPlayer->Y
				|| m_lastMoveTick + 100 > ticks)
			{
				if (m_lastX != pControlledPlayer->X || m_lastY != pControlledPlayer->Y)
					m_lastMoveTick = ticks;

				gbMoving = true;
				m_lastX = pControlledPlayer->X;
				m_lastY = pControlledPlayer->Y;
			}
			else
			{
				gbMoving = false;
			}

			// update animated facing
			if (gFaceAngle != 10000.0f || gLookAngle != 10000.0f)
			{
				TurnNotDone = false;

				if (gFaceAngle != 10000.0f)
				{
					NaturalTurn(pControlledPlayer);
				}

				if (gLookAngle != 10000.0f)
				{
					if (abs(static_cast<float>(pLocalPlayer->CameraAngle - gLookAngle)) < 5.0f)
					{
						pLocalPlayer->CameraAngle = (float)gLookAngle;
						gLookAngle = 10000.0f;
						TurnNotDone = false;
					}
					else
					{
						TurnNotDone = true;
						float c1 = pLocalPlayer->CameraAngle;
						float c2 = static_cast<float>(gLookAngle);

						float turn = static_cast<float>(rand() % 200) / 20.0f;

						if (c1 < c2)
						{
							pLocalPlayer->CameraAngle += turn;
							if (pLocalPlayer->CameraAngle >= 128.0f)
								pLocalPlayer->CameraAngle -= 128.0f;
						}
						else
						{
							pLocalPlayer->CameraAngle -= turn;
							if (pLocalPlayer->CameraAngle <= -128.0f)
								pLocalPlayer->CameraAngle += 128.0f;
						}
					}
				}

				if (TurnNotDone)
				{
					bRunNextCommand = false;
					IsMouseWaiting();
					return;
				}
			}
		}
		else
		{
			gbMoving = false;
		}

		Heartbeat();
	}

	virtual void OnZoned() override
	{
		gFaceAngle = 10000.0f;
		gLookAngle = 10000.0f;
		gbMoving = false;
		m_lastX = pLocalPlayer->X;
		m_lastY = pLocalPlayer->Y;
		m_lastMoveTick = MQGetTickCount64();
		SetSwitchTarget(nullptr);
	}

private:
	void NaturalTurn(PlayerClient* pPlayer)
	{
		// calc the turn rate
		float TurnRate = 4.0f;
		float fHeadingDiff = 0.0f;
		float AbsHeadingDiff = HeadingDiff(pPlayer->Heading, (float)gFaceAngle, &fHeadingDiff);

		if (AbsHeadingDiff < 1.0f)
		{
			// small enough to just set the heading.
			pPlayer->Heading = (float)gFaceAngle;
			pPlayer->SpeedHeading = 0.0f;
			gFaceAngle = 10000.0f;
		}
		else
		{
			TurnNotDone = true;

			if (AbsHeadingDiff < TurnRate)
			{
				TurnRate = AbsHeadingDiff;
			}
			else if (AbsHeadingDiff > 128.0f)
			{
				TurnRate = 9.0f;
			}

			if ((pPlayer->Heading < gFaceAngle && fHeadingDiff < 0.0f)
				|| (gFaceAngle < pPlayer->Heading && fHeadingDiff > 0.0f))
			{
				pPlayer->Heading = pPlayer->Heading - TurnRate;
			}
			else
			{
				pPlayer->Heading = pPlayer->Heading + TurnRate;
			}

			pPlayer->Heading = FixHeading(pPlayer->Heading);
		}
	}

	float m_lastX = 0.0f;
	float m_lastY = 0.0f;
	uint64_t m_lastMoveTick = 0;
};

DECLARE_MODULE_FACTORY(PulseModule);

//=================================================================================================

#pragma region MerchantWindowTracker

class CMerchantWnd_Detours
{
public:
	DETOUR_TRAMPOLINE_DEF(void, PurchasePageHandler__UpdateList_Trampoline, ())
		void PurchasePageHandler__UpdateList_Detour()
	{
		gItemsReceived = false;

		PurchasePageHandler__UpdateList_Trampoline();

		gItemsReceived = true;
	}
};


// This tracks the state of the merchant window to know if we've received items for it.
class MerchantWindowTracker : public MQModuleBase
{
public:
	MerchantWindowTracker() : MQModuleBase("MerchantWindowTracker")
	{
	}

	virtual void Initialize() override
	{
		EzDetour(CMerchantWnd__PurchasePageHandler__UpdateList,
			&CMerchantWnd_Detours::PurchasePageHandler__UpdateList_Detour,
			&CMerchantWnd_Detours::PurchasePageHandler__UpdateList_Trampoline);
	}

	virtual void Shutdown() override
	{
		RemoveDetour(CMerchantWnd__PurchasePageHandler__UpdateList);
	}

	virtual void OnProcessFrame() override
	{
		if (pMerchantWnd && !pMerchantWnd->IsVisible())
			gItemsReceived = false;
	}
};

#pragma endregion

#pragma region CameraModule

//
// CameraModule - Handles miscellaneous features related to the camera
//

bool gbShowCurrentCamera = false;

// ***************************************************************************
// Function:    UserCameraCmd
// Description: '/usercamera' command
// Purpose:     Adds the ability to load and save the User 1 Camera
// Example:     /usercamera on/off toggle the camera text in the Window Selector on/off
// Example:     /usercamera save saves the user 1 camera settings
// Example:     /usercamera load loades the user 1 camera settings
// ***************************************************************************
void UserCameraCommand(PlayerClient*, const char* szLine)
{
	if (szLine && szLine[0] == '\0')
	{
		WriteChatf("Usage: /usercamera 0-7 sets camera to the number specified.");
		WriteChatf("Usage: /usercamera save <optional charname> to save the user 1 camera");
		WriteChatf("Usage: /usercamera load <optional charname> to load your saved user 1 camera");
		WriteChatf("Usage: /usercamera on/off to toggle Window Selector Display of Current Camera");
		return;
	}

	char szArg1[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);

	char szArg2[MAX_STRING] = { 0 };
	GetArg(szArg2, szLine, 2);

	if (!_stricmp(szArg1, "0"))
	{
		*CDisplay::cameraType = EQ_FIRST_PERSON_CAM;
	}
	else if (!_stricmp(szArg1, "1"))
	{
		*CDisplay::cameraType = EQ_OVERHEAD_CAM;
	}
	else if (!_stricmp(szArg1, "2"))
	{
		*CDisplay::cameraType = EQ_CHASE_CAM;
	}
	else if (!_stricmp(szArg1, "3"))
	{
		*CDisplay::cameraType = EQ_USER_CAM_1;
	}
	else if (!_stricmp(szArg1, "4"))
	{
		*CDisplay::cameraType = EQ_USER_CAM_2;
	}
	else if (!_stricmp(szArg1, "5"))
	{
		*CDisplay::cameraType = 5;
	}
	else if (!_stricmp(szArg1, "6"))
	{
		*CDisplay::cameraType = 6;
	}
	else if (!_stricmp(szArg1, "7"))
	{
		*CDisplay::cameraType = 7;
	}
	else if (!_stricmp(szArg1, "on"))
	{
		gbShowCurrentCamera = true;
		WritePrivateProfileBool("MacroQuest", "ShowCurrentCamera", gbShowCurrentCamera, mq::internal_paths::MQini);

		if (pSelectorWnd)
		{
			char szOut[64] = { 0 };
			sprintf_s(szOut, "Selector Window (Camera %d)", *(DWORD*)CDisplay__cameraType);

			pSelectorWnd->SetWindowText(szOut);
		}
	}
	else if (!_stricmp(szArg1, "off"))
	{
		gbShowCurrentCamera = false;
		WritePrivateProfileBool("MacroQuest", "ShowCurrentCamera", gbShowCurrentCamera, mq::internal_paths::MQini);

		if (pSelectorWnd)
		{
			pSelectorWnd->SetWindowText("Selector Window");
		}
	}
	else if (!_stricmp(szArg1, "save"))
	{
		std::string pathIniFile = mq::internal_paths::MQini;

		if (szArg2 && szArg2[0] != '\0')
		{
			const std::string tmpFileName =
				fmt::format("{}_{}.ini", GetServerShortName(), szArg2);
			pathIniFile = (std::filesystem::path(mq::internal_paths::Config) / tmpFileName).string();
		}

		EQCamera* pUserCam1 = pEverQuestInfo->cameras[EQ_USER_CAM_1];

		WritePrivateProfileBool("User Camera 1", "bAutoHeading", pUserCam1->bAutoHeading, pathIniFile);
		WritePrivateProfileBool("User Camera 1", "bAutoPitch", pUserCam1->bAutoPitch, pathIniFile);
		WritePrivateProfileBool("User Camera 1", "bSkipFrame", pUserCam1->bSkipFrame, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "DirectionalHeading", pUserCam1->DirectionalHeading, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "Distance", pUserCam1->Distance, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "Heading", pUserCam1->Heading, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "Height", pUserCam1->Height, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "OldPosition_X", pUserCam1->OldPosition_X, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "OldPosition_Y", pUserCam1->OldPosition_Y, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "OldPosition_Z", pUserCam1->OldPosition_Z, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "Orientation_X", pUserCam1->Orientation_X, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "Orientation_Y", pUserCam1->Orientation_Y, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "Orientation_Z", pUserCam1->Orientation_Z, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "Pitch", pUserCam1->Pitch, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "SideMovement", pUserCam1->SideMovement, pathIniFile);
		WritePrivateProfileFloat("User Camera 1", "Zoom", pUserCam1->Zoom, pathIniFile);
	}
	else if (!_stricmp(szArg1, "load"))
	{
		std::string pathIniFile = mq::internal_paths::MQini;

		if (szArg2 && szArg2[0] != '\0')
		{
			const std::string tmpFileName = fmt::format("{}_{}.ini", GetServerShortName(), szArg2);
			pathIniFile = (std::filesystem::path(mq::internal_paths::Config) / tmpFileName).string();
		}

		EQCamera* pUserCam1 = pEverQuestInfo->cameras[EQ_USER_CAM_1];

		pUserCam1->bAutoHeading = GetPrivateProfileBool("User Camera 1", "bAutoHeading", pUserCam1->bAutoHeading, pathIniFile);
		pUserCam1->bAutoPitch = GetPrivateProfileBool("User Camera 1", "bAutoPitch", pUserCam1->bAutoPitch, pathIniFile);
		pUserCam1->bSkipFrame = GetPrivateProfileBool("User Camera 1", "bSkipFrame", pUserCam1->bSkipFrame, pathIniFile);
		pUserCam1->DirectionalHeading = GetPrivateProfileFloat("User Camera 1", "DirectionalHeading", pUserCam1->DirectionalHeading, pathIniFile);
		pUserCam1->Distance = GetPrivateProfileFloat("User Camera 1", "Distance", pUserCam1->Distance, pathIniFile);
		pUserCam1->Heading = GetPrivateProfileFloat("User Camera 1", "Heading", pUserCam1->Heading, pathIniFile);
		pUserCam1->Height = GetPrivateProfileFloat("User Camera 1", "Height", pUserCam1->Height, pathIniFile);
		pUserCam1->OldPosition_X = GetPrivateProfileFloat("User Camera 1", "OldPosition_X", pUserCam1->OldPosition_X, pathIniFile);
		pUserCam1->OldPosition_Y = GetPrivateProfileFloat("User Camera 1", "OldPosition_Y", pUserCam1->OldPosition_Y, pathIniFile);
		pUserCam1->OldPosition_Z = GetPrivateProfileFloat("User Camera 1", "OldPosition_Z", pUserCam1->OldPosition_Z, pathIniFile);
		pUserCam1->Orientation_X = GetPrivateProfileFloat("User Camera 1", "Orientation_X", pUserCam1->Orientation_X, pathIniFile);
		pUserCam1->Orientation_Y = GetPrivateProfileFloat("User Camera 1", "Orientation_Y", pUserCam1->Orientation_Y, pathIniFile);
		pUserCam1->Orientation_Z = GetPrivateProfileFloat("User Camera 1", "Orientation_Z", pUserCam1->Orientation_Z, pathIniFile);
		pUserCam1->Pitch = GetPrivateProfileFloat("User Camera 1", "Pitch", pUserCam1->Pitch, pathIniFile);
		pUserCam1->SideMovement = GetPrivateProfileFloat("User Camera 1", "SideMovement", pUserCam1->SideMovement, pathIniFile);
		pUserCam1->Zoom = GetPrivateProfileFloat("User Camera 1", "Zoom", pUserCam1->Zoom, pathIniFile);

		*CDisplay::cameraType = EQ_USER_CAM_1;
	}
}

class CameraModule : public MQModuleBase
{
public:
	CameraModule() : MQModuleBase("Camera")
	{
	}

	virtual void Initialize() override
	{
		gbShowCurrentCamera = GetPrivateProfileBool("MacroQuest", "ShowCurrentCamera", gbShowCurrentCamera, mq::internal_paths::MQini);

		if (gbWriteAllConfig)
		{
			WritePrivateProfileBool("MacroQuest", "ShowCurrentCamera", gbShowCurrentCamera, mq::internal_paths::MQini);
		}

		AddCommand("/usercamera", UserCameraCommand);
	}

	virtual void Shutdown() override
	{
		RemoveCommand("/usercamera");

		// Restore the original window title
		if (gbShowCurrentCamera && pSelectorWnd && m_lastCameraType != -1)
		{
			pSelectorWnd->SetWindowText("Selector Window");
		}
	}

	virtual void OnProcessFrame() override
	{
		if (gbShowCurrentCamera
			&& pSelectorWnd)
		{
			// See Also /usercamera code
			if (m_lastCameraType != *CDisplay::cameraType)
			{
				m_lastCameraType = *CDisplay::cameraType;

				char szOut[64];
				sprintf_s(szOut, "Selector Window (Camera %d)", m_lastCameraType);

				pSelectorWnd->SetWindowText(szOut);
			}
		}
	}

private:
	int m_lastCameraType = -1;
};

DECLARE_MODULE_FACTORY(CameraModule);

#pragma endregion

} // namespace mq
