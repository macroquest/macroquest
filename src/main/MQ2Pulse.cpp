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
#include "MQPostOffice.h"
#include "CrashHandler.h"
#include "ImGuiManager.h"

#include <wil/resource.h>

#pragma warning(disable : 4091) // 'keyword' : ignored on left of 'type' when no variable is declared

namespace mq {

bool TurnNotDone = false;
static std::recursive_mutex s_pulseMutex;

void UpdateMQ2SpawnSort();

//----------------------------------------------------------------------------

std::vector<std::function<void()>> s_queuedEvents;
std::recursive_mutex s_queuedEventMutex;
extern wil::unique_event g_hLoadComplete;

void PostToMainThread(std::function<void()>&& callback)
{
	std::scoped_lock lock(s_queuedEventMutex);

	s_queuedEvents.push_back(std::move(callback));
}

static void ProcessQueuedEvents()
{
	std::unique_lock lock(s_queuedEventMutex);

	if (s_queuedEvents.empty())
		return;

	std::vector<std::function<void()>> events;
	events.swap(s_queuedEvents);

	lock.unlock();

	for (auto& ev : events)
		std::invoke(ev);
}

//----------------------------------------------------------------------------
extern uint64_t s_commandCount;

static bool DoNextCommand(MQMacroBlockPtr pBlock)
{
	if (!pControlledPlayer || !pLocalPC)
		return false;

	SPAWNINFO* pCharOrMount = nullptr;
	SPAWNINFO* pChar = pCharOrMount = pControlledPlayer;

	if (pLocalPlayer)
		pChar = pLocalPlayer;
	if (!pChar)
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
			DoCommand(pChar, (char*)ml.Command.c_str());
			MQMacroBlockPtr pCurrentBlock = GetCurrentMacroBlock();

			if (!pCurrentBlock)
				return false;

			if (!pCurrentBlock->BindCmd.empty() && pCurrentBlock->BindStackIndex == -1)
			{
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

					Call(pChar, (char*)pCurrentBlock->BindCmd.c_str());
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

void NaturalTurnOld(PSPAWNINFO pCharOrMount, PSPAWNINFO pChar)
{
	if (abs((INT)(pCharOrMount->Heading - gFaceAngle)) < 10.0f)
	{
		pCharOrMount->Heading = (float)gFaceAngle;
		pCharOrMount->SpeedHeading = 0.0f;
		gFaceAngle = 10000.0f;
	}
	else
	{
		TurnNotDone = true;
		double c1 = pCharOrMount->Heading + 256.0;
		double c2 = gFaceAngle;

		if (c2 < pChar->Heading) c2 += 512.0f;
		double turn = (double)(rand() % 200) / 10;

		if (c2 < c1)
		{
			pCharOrMount->Heading += (float)turn;
			pCharOrMount->SpeedHeading = 12.0f;

			if (pCharOrMount->Heading >= 512.0f)
				pCharOrMount->Heading -= 512.0f;
		}
		else
		{
			pCharOrMount->Heading -= (float)turn;
			pCharOrMount->SpeedHeading = -12.0f;

			if (pCharOrMount->Heading < 0.0f)
				pCharOrMount->Heading += 512.0f;
		}
	}
}

void NaturalTurn(SPAWNINFO* pCharOrMount, SPAWNINFO* pChar)
{
	// calc the turn rate
	float TurnRate = 4.0f;
	float fHeadingDiff = 0.0f;
	float AbsHeadingDiff = HeadingDiff(pCharOrMount->Heading, (float)gFaceAngle, &fHeadingDiff);

	if (AbsHeadingDiff < 1.0f)
	{
		// small enough to just set the heading.
		pCharOrMount->Heading = (float)gFaceAngle;
		pCharOrMount->SpeedHeading = 0.0f;
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

		if (((pCharOrMount->Heading < gFaceAngle) && (fHeadingDiff < 0.0f))
			|| ((gFaceAngle < pCharOrMount->Heading) && (fHeadingDiff > 0.0f)))
		{
			pCharOrMount->Heading = pCharOrMount->Heading - TurnRate;
		}
		else
		{
			pCharOrMount->Heading = pCharOrMount->Heading + TurnRate;
		}

		pCharOrMount->Heading = FixHeading(pCharOrMount->Heading);
	}
}

static void CheckGameState()
{
	static int lastGameState = gGameState;

	if (lastGameState != gGameState)
	{
		SPDLOG_INFO("GameState Change: {} -> {}", lastGameState, gGameState);
		lastGameState = gGameState;
	}

	// Testing for in game flags
	if (gGameState == GAMESTATE_INGAME)
	{
		if (!pLocalPC)
			SPDLOG_ERROR("InGame with no pLocalPC");

		if (pLocalPC)
		{
			if (pLocalPC->me != pLocalPlayer)
				SPDLOG_ERROR("pLocalPC->me ({}) is different than pLocalPlayer ({})",
					(void*)pLocalPC->me, (void*)pLocalPlayer.get());
		}

		if (!pControlledPlayer)
			SPDLOG_ERROR("InGame with no pControlledPlayer");
		if (!pLocalPlayer)
			SPDLOG_ERROR("InGame with no pLocalPlayer");

		// Check UI state
		if (!pPlayerWnd)
			SPDLOG_ERROR("InGame with no pPlayerWnd");
		if (!gbInZone)
			SPDLOG_ERROR("InGame but not gbInZone");
	}
	else if (gGameState == GAMESTATE_CHARSELECT)
	{
		if (!pLocalPC)
			SPDLOG_ERROR("At CharSelect without pLocalPC");
		else if (pLocalPC->me != nullptr)
		{
			// Me should be null
			SPDLOG_ERROR("At CharSelect with pLocalPC->me ({} {})", (void*)pLocalPC->me, pLocalPC->me->Name);
		}

		if (!pLocalPlayer)
			SPDLOG_ERROR("At CharSelect without pLocalPlayer");
		if (!pControlledPlayer)
			SPDLOG_ERROR("At CharSelect without pControlledPlayer");

		// Check UI state
		if (pPlayerWnd)
			SPDLOG_ERROR("Not InGame with pPlayerWnd");

		if (!gbInZone)
			SPDLOG_ERROR("At CharSelect without gbInZone");
	}

	if (pLocalPC)
	{
		if (pLocalPC->ProfileManager.GetCurrentProfile() == nullptr)
			SPDLOG_ERROR("pLocalPC exists but CurrentProfile does not");
	}
	else if (pLocalPlayer)
	{
		SPDLOG_ERROR("pLocalPlayer exists but pLocalPC doesn't");
	}

	if (pLocalPlayer && !pControlledPlayer)
	{
		SPDLOG_ERROR("pLocalPlayer ({}) exists but no pControlledPlayer ({})",
			(void*)pLocalPlayer.get(), (void*)pControlledPlayer.get());
	}

	// Check for changes.
	static PcClient* OldLocalPC = nullptr;
	static PlayerClient* OldControlledPlayer = nullptr;
	static PlayerClient* OldLocalPlayer = nullptr;
	static PlayerClient* OldMe = nullptr;

	if (test_and_set(OldLocalPC, pLocalPC.get()))
		SPDLOG_INFO("pLocalPC Changed: {}", (void*)pLocalPC.get());

	if (test_and_set(OldControlledPlayer, pControlledPlayer.get()))
		SPDLOG_INFO("pControlledPlayer Changed: {} {}", (void*)pControlledPlayer.get(), pControlledPlayer ? pControlledPlayer->Name : "<null>");
	if (test_and_set(OldLocalPlayer, pLocalPlayer.get()))
		SPDLOG_INFO("pLocalPlayer Changed: {} {}", (void*)pLocalPlayer.get(), pLocalPlayer ? pLocalPlayer->Name : "<null>");

	PlayerClient* pMe = pLocalPC ? pLocalPC->me : nullptr;
	if (test_and_set(OldMe, pMe))
		SPDLOG_INFO("pLocalPC->Me Changed: {} {}", (void*)pMe, pMe ? pMe->Name : "<null>");
}

static void Pulse()
{
	static HWND EQhWnd = *(HWND*)EQADDR_HWND;
	if (EQW_GetDisplayWindow)
		EQhWnd = EQW_GetDisplayWindow();

	if (mq::test_and_set(gbInForeground, (GetForegroundWindow() == EQhWnd)))
	{
		pipeclient::NotifyIsForegroundWindow(gbInForeground);
	}

	// handle queued events.
	ProcessQueuedEvents();

	//CheckGameState();

	if (!pControlledPlayer) return;

	SPAWNINFO* pCharOrMount = nullptr;
	PcProfile* pProfile = GetPcProfile();
	SPAWNINFO* pChar = pCharOrMount = pControlledPlayer;

	// Drop out here if we're waiting for something.
	if (!pChar || gZoning) return;
	if (!pLocalPC) return;

	if (pLocalPlayer)
		pChar = pLocalPlayer;

	static int16_t LastZone = -1;
	static SPAWNINFO* pCharOld = nullptr;
	static float LastX = 0.0f;
	static float LastY = 0.0f;
	static uint64_t LastMoveTick = 0;
	static uint32_t MapDelay = 0;

	if (pChar != pCharOld && WereWeZoning)
	{
		// Reset after zoning completes
		WereWeZoning = false;
		pCharOld = pChar;
		gFaceAngle = 10000.0f;
		gLookAngle = 10000.0f;
		gbMoving = false;
		LastX = pChar->X;
		LastY = pChar->Y;
		LastMoveTick = MQGetTickCount64();
		SetSwitchTarget(nullptr);

		// see if we're on a pvp server
		if (!_strnicmp(GetServerShortName(), "zek", 3))
		{
			PVPServer = PVP_RALLOS;
		}
		else
		{
			PVPServer = PVP_NONE;
		}

		srand((unsigned int)time(nullptr)); // reseed

		Benchmark(bmPluginsOnZoned, PluginsZoned());
	}
	else if ((LastX != pChar->X) || (LastY != pChar->Y) || LastMoveTick > MQGetTickCount64() - 100)
	{
		if ((LastX != pChar->X) || (LastY != pChar->Y)) LastMoveTick = MQGetTickCount64();
		gbMoving = true;
		LastX = pChar->X;
		LastY = pChar->Y;
	}
	else
	{
		gbMoving = false;
	}

	static PlayerClient* lastTarget = pTarget;
	if (test_and_set(lastTarget, pTarget.get()))
	{
		gTargetbuffs = false;
	}

	if (pMerchantWnd && !pMerchantWnd->IsVisible())
		gItemsReceived = false;

	if (gbDoAutoRun && pChar && pLocalPC)
	{
		gbDoAutoRun = false;

		char szAutoRun[MAX_STRING] = { 0 };
		char* pAutoRun = szAutoRun;

		// autorun command for everyone
		GetPrivateProfileString("AutoRun", "ALL", "", szAutoRun, MAX_STRING, mq::internal_paths::MQini);
		while (pAutoRun[0] == ' ' || pAutoRun[0] == '\t') pAutoRun++;
		if (szAutoRun[0] != 0)
			DoCommand(pChar, pAutoRun);

		// autorun command for toon
		szAutoRun[0] = 0;
		pAutoRun = szAutoRun;
		char szServerAndName[128] = { 0 };
		sprintf_s(szServerAndName, "%s.%s", GetServerShortName(), pLocalPC->Name);
		GetPrivateProfileString("AutoRun", szServerAndName, "", szAutoRun, MAX_STRING, mq::internal_paths::MQini);
		while (pAutoRun[0] == ' ' || pAutoRun[0] == '\t') pAutoRun++;
		if (szAutoRun[0] != 0)
			DoCommand(pChar, pAutoRun);
	}

	if (gbShowCurrentCamera)
	{
		if (pWndMgr && pSelectorWnd)
		{
			// See Also /usercamera code
			if (gOldCameraType != *(DWORD*)CDisplay__cameraType)
			{
				gOldCameraType = *(DWORD*)CDisplay__cameraType;

				char szOut[64] = { 0 };
				sprintf_s(szOut, "Selector Window (Camera %d)", gOldCameraType);

				pSelectorWnd->SetWindowText(szOut);
			}
		}
	}

	if ((gFaceAngle != 10000.0f) || (gLookAngle != 10000.0f))
	{
		TurnNotDone = false;

		if (gFaceAngle != 10000.0f)
		{
			NaturalTurn(pCharOrMount, pChar);
		}

		if (gLookAngle != 10000.0f)
		{
			if (abs((INT)(pChar->CameraAngle - gLookAngle)) < 5.0f)
			{
				pChar->CameraAngle = (float)gLookAngle;
				gLookAngle = 10000.0f;
				TurnNotDone = false;
			}
			else
			{
				TurnNotDone = true;
				float c1 = pChar->CameraAngle;
				float c2 = (float)gLookAngle;

				double turn = (double)(rand() % 200) / 20;

				if (c1 < c2)
				{
					pChar->CameraAngle += (float)turn;
					if (pChar->CameraAngle >= 128.0f) pChar->CameraAngle -= 128.0f;
				}
				else
				{
					pChar->CameraAngle -= (float)turn;
					if (pChar->CameraAngle <= -128.0f) pChar->CameraAngle += 128.0f;
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

// Trims trailing whitespace from strings in the string table.
static void FixStringTable()
{
	for (int index = 0; index < pStringTable->Count; index++)
	{
		if (StringItem* pStr = pStringTable->StringItems[index])
		{
			if (char* p = pStr->String)
			{
				while (*p)
					p++;
				p--;
				while (*p == ' ' && p != pStr->String)
				{
					*p = 0;
					p--;
				}
			}
		}
	}
}


enum HeartbeatState
{
	HeartbeatNormal = 0,
	HeartbeatUnload = 1,
	HeartbeatLoad = 2,
};

static HeartbeatState Heartbeat()
{
	if (gbUnload)
	{
		return HeartbeatUnload;
	}

	if (gbLoad)
	{
		gbLoad = false;
		return HeartbeatLoad;
	}

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

	if (!gStringTableFixed && pStringTable)
	{
		FixStringTable();
		gStringTableFixed = true;
	}

	DebugTry(int GameState = GetGameState());
	if (GameState != -1)
	{
		if ((DWORD)GameState != gGameState)
		{
			DebugSpew("GetGameState()=%d vs %d", GameState, gGameState);
			gGameState = GameState;
			gbInZone = (gGameState == GAMESTATE_INGAME || gGameState == GAMESTATE_CHARSELECT || gGameState == GAMESTATE_CHARCREATE);
			DebugTry(Benchmark(bmPluginsSetGameState, PluginsSetGameState(GameState)));
		}

		// they "zoned" to charselect...
		if (gZoning && (GameState == GAMESTATE_CHARSELECT || GameState == GAMESTATE_CHARCREATE))
		{
			gZoning = false;
			PluginsEndZone();
		}
	}

	UpdateMQ2SpawnSort();

	DebugTry(DrawHUD());
	DebugTry(PulseMQ2AutoInventory());

	bRunNextCommand = true;
	DebugTry(Pulse());
	DebugTry(Benchmark(bmPluginsPulse, DebugTry(PulsePlugins())));

	static bool ShownNews = false;
	if (gGameState == GAMESTATE_CHARSELECT && !ShownNews)
	{
		ShownNews = true;
		if (gCreateMQ2NewsWindow)
			CreateMQ2NewsWindow();
	}

	ImGuiManager_Pulse();

	if (gGameState == -1)
	{
		PulseCommands();

		return HeartbeatNormal;
	}

	int CurTurbo = 0;

	MQMacroBlockPtr pBlock = GetNextMacroBlock();
	while (bRunNextCommand)
	{
		if (!pBlock)
			break;
		if (!DoNextCommand(pBlock))
			break;
		if (gbUnload)
			return HeartbeatUnload;
		if (!gTurbo)
			break;
		if (++CurTurbo > gMaxTurbo)
			break;

		// re-fetch current macro block in case one of the previous instructions changed it
		pBlock = GetCurrentMacroBlock();
	}

	PulseCommands();

	return HeartbeatNormal;
}

// ***************************************************************************
// Function:    ProcessGameEvents
// Description: Our ProcessGameEvents Hook
// ***************************************************************************

void SetMainThreadId();
void DoMainThreadInitialization();

bool DoGameEventsPulse(int (*pEventFunc)())
{
	SetMainThreadId();
	HeartbeatState hbState;

	{
		std::scoped_lock lock(s_pulseMutex);
		hbState = Heartbeat();
	}

	int processGameEventsResult = 0;
	if (pEventFunc)
		processGameEventsResult = pEventFunc();

	if (hbState == HeartbeatLoad && !IsPluginsInitialized())
	{
		OutputDebugString("I am loading in ProcessGameEvents");

		DWORD oldscreenmode = std::exchange(ScreenMode, 3);
		DoMainThreadInitialization();
		ScreenMode = oldscreenmode;

		g_hLoadComplete.SetEvent();
	}
	else if (hbState == HeartbeatUnload && g_Loaded)
	{
		// we are unloading stuff
		OutputDebugString("I am unloading in ProcessGameEvents");

		DWORD oldscreenmode = std::exchange(ScreenMode, 3);
		WriteChatColor(UnloadedString, USERCOLOR_DEFAULT);
		DebugSpewAlways("%s", UnloadedString);

		// cant unload these here there are detours still in use that call functions from plugins...
		//UnloadMQ2Plugins();

		MQ2Shutdown();

		g_Loaded = false;
		ScreenMode = oldscreenmode;
		SetEvent(hUnloadComplete);
	}

	return processGameEventsResult;
}

static int(*Trampoline_ProcessGameEvents)();
int Detour_ProcessGameEvents()
{
	return DoGameEventsPulse(Trampoline_ProcessGameEvents);
}

void DoLoginPulse()
{
	DoGameEventsPulse(nullptr);
}

class CEverQuestHook
{
public:
	DETOUR_TRAMPOLINE_DEF(void, SetGameState_Trampoline, (DWORD GameState))
	void SetGameState_Detour(DWORD GameState)
	{
		SetGameState_Trampoline(GameState);

		Benchmark(bmPluginsSetGameState, PluginsSetGameState(GameState));
	}

	DETOUR_TRAMPOLINE_DEF(void, CMerchantWnd__PurchasePageHandler__UpdateList_Trampoline, ())
	void CMerchantWnd__PurchasePageHandler__UpdateList_Detour()
	{
		gItemsReceived = false;

		CMerchantWnd__PurchasePageHandler__UpdateList_Trampoline();

		gItemsReceived = true;
	}
};

void InitializeMQ2Pulse()
{
	DebugSpew("Initializing Pulse");

	std::scoped_lock lock(s_pulseMutex);

	AddDetour(reinterpret_cast<uintptr_t>(ProcessGameEvents), Detour_ProcessGameEvents, Trampoline_ProcessGameEvents, "ProcessGameEvents");
	EzDetour(CEverQuest__SetGameState, &CEverQuestHook::SetGameState_Detour, &CEverQuestHook::SetGameState_Trampoline);
	EzDetour(CMerchantWnd__PurchasePageHandler__UpdateList, &CEverQuestHook::CMerchantWnd__PurchasePageHandler__UpdateList_Detour, &CEverQuestHook::CMerchantWnd__PurchasePageHandler__UpdateList_Trampoline);

	if (HMODULE EQWhMod = GetModuleHandle("eqw.dll"))
	{
		EQW_GetDisplayWindow = (fEQW_GetDisplayWindow)GetProcAddress(EQWhMod, "EQW_GetDisplayWindow");
	}
}

void ShutdownMQ2Pulse()
{
	std::scoped_lock lock(s_pulseMutex);

	RemoveDetour(reinterpret_cast<uintptr_t>(ProcessGameEvents));
	RemoveDetour(CEverQuest__SetGameState);
	RemoveDetour(CMerchantWnd__PurchasePageHandler__UpdateList);
}

} // namespace mq
