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

#include "pch.h"
#include "MQ2Main.h"
#include "CrashHandler.h"

#include "common/NamedPipes.h"

#include <wil/resource.h>

#pragma warning(disable : 4091) // 'keyword' : ignored on left of 'type' when no variable is declared

namespace mq {

static void Pulse_Initialize();
static void Pulse_Shutdown();

static MQModule s_pulseModule = {
	"Pulse",                       // Name
	false,                         // CanUnload
	Pulse_Initialize,
	Pulse_Shutdown,
};
DECLARE_MODULE_INITIALIZER(s_pulseModule);

//----------------------------------------------------------------------------

extern NamedPipeClient gPipeClient;

bool TurnNotDone = false;
static std::recursive_mutex s_pulseMutex;

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

static bool DoNextCommand(MQMacroBlockPtr pBlock)
{
	if (!pCharSpawn)
		return false;

	SPAWNINFO* pCharOrMount = nullptr;
	CHARINFO* pCharInfo = GetCharInfo();
	SPAWNINFO* pChar = pCharOrMount = pCharSpawn;

	if (pCharInfo && pCharInfo->pSpawn)
		pChar = pCharInfo->pSpawn;
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

		ParseMacroParameter(GetCharInfo()->pSpawn, szCond);

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

	if (!gDelay && pBlock && !pBlock->Paused && (!gMQPauseOnChat || *EQADDR_NOTINCHATMODE) && gMacroStack)
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
						iter++;
						if (iter != pCurrentBlock->Line.end())
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

			int lastindex = pCurrentBlock->Line.rbegin()->first;
			if (pCurrentBlock->CurrIndex > lastindex)
			{
				FatalError("Reached end of macro.");
			}
			else
			{
				auto iter = pCurrentBlock->Line.find(pCurrentBlock->CurrIndex);
				if (iter != pCurrentBlock->Line.end())
				{
					iter++;
					if (iter != pCurrentBlock->Line.end())
					{
						pCurrentBlock->CurrIndex = iter->first;
					}
				}
				else
				{
					FatalError("Reached end of macro.");
				}
			}

			return true;
		}
	}

	return false;
}

// added these so I can work on making face look natural - eqmule
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

static void Pulse()
{
	static HWND EQhWnd = *(HWND*)EQADDR_HWND;
	if (EQW_GetDisplayWindow)
		EQhWnd = EQW_GetDisplayWindow();

	gbInForeground = (GetForegroundWindow() == EQhWnd);

	// handle queued events.
	ProcessQueuedEvents();

	if (!pCharSpawn) return;

	SPAWNINFO* pCharOrMount = nullptr;
	CHARINFO* pCharInfo = GetCharInfo();
	PcProfile* pProfile = GetPcProfile();
	SPAWNINFO* pChar = pCharOrMount = (SPAWNINFO*)pCharSpawn;

	// Drop out here if we're waiting for something.
	if (!pChar || gZoning) return;
	if (!pCharInfo) return;

	if (pCharInfo && pCharInfo->pSpawn)
		pChar = pCharInfo->pSpawn;

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
		EnviroTarget.Name[0] = 0;
		pGroundTarget = nullptr;
		ZeroMemory(&GroundObject, sizeof(GroundObject));
		DoorEnviroTarget.Name[0] = 0;
		DoorEnviroTarget.DisplayedName[0] = 0;
		pDoorTarget = nullptr;

		// see if we're on a pvp server
		if (!_strnicmp(EQADDR_SERVERNAME, "zek", 3))
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

	if (!pTarget)
		gTargetbuffs = false;

	if (pMerchantWnd && !pMerchantWnd->IsVisible())
		gItemsReceived = false;

	if (gbDoAutoRun && pChar && pCharInfo)
	{
		gbDoAutoRun = false;
		InitKeyRings();
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
		sprintf_s(szServerAndName, "%s.%s", EQADDR_SERVERNAME, pCharInfo->Name);
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
	EQSTRINGTABLE* pTable = pStringTable;
	for (int index = 0; index < pTable->Count; index++)
	{
		if (EQSTRING* pStr = pTable->StringItems[index])
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
	static fMQPulse pEQPlayNicePulse = nullptr;
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

	if (!gStringTableFixed && pStringTable) // Please dont remove the second condition
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

	gPipeClient.Process();

	DebugTry(DrawHUD());

	bRunNextCommand = true;

	DebugTry(Pulse());
	DebugTry(Benchmark(bmPluginsPulse, DebugTry(PulsePlugins())));

	if (pEQPlayNicePulse)
	{
		pEQPlayNicePulse();
	}
	else
	{
		HMODULE hmEQPlayNice;
		if (((BeatCount % 63) == 0) && (hmEQPlayNice = GetModuleHandle("EQPlayNice.dll")))
		{
			if (pEQPlayNicePulse = (fMQPulse)GetProcAddress(hmEQPlayNice, "Compat_ProcessFrame"))
				pEQPlayNicePulse();
		}
	}

	static bool ShownNews = false;
	if (gGameState == GAMESTATE_CHARSELECT && !ShownNews)
	{
		ShownNews = true;
		if (gCreateMQ2NewsWindow)
			CreateMQ2NewsWindow();
	}

	DebugTry(PulseMQ2Overlay());

	if (gGameState == -1)
	{
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

template <unsigned int _Size>
static void make_minidump(char* filename, EXCEPTION_POINTERS* e, char(&dumppath)[_Size])
//void make_minidump(char*filename, EXCEPTION_POINTERS* e,char*dumppath)
{
	std::filesystem::path dumpFilePath = filename;
	dumpFilePath = dumpFilePath.filename();

	std::string dumpFileName = dumpFilePath.string();
	if (dumpFileName.find('.') != std::string::npos)
	{
		dumpFileName = dumpFileName.substr(0, dumpFileName.find('.'));
	}

	SYSTEMTIME t;
	GetSystemTime(&t);

	dumpFileName = fmt::format("{FileName}_{Year:0=4d}{Month:0=2d}{Day:0=2d}_{Hour:0=2d}{Minute:0=2d}{Second:0=2d}.dmp",
	              fmt::arg("FileName", dumpFileName),
	                    fmt::arg("Year", t.wYear),
	                    fmt::arg("Month", t.wMonth),
	                    fmt::arg("Day", t.wDay),
	                    fmt::arg("Hour", t.wHour),
	                    fmt::arg("Minute", t.wMinute),
	                    fmt::arg("Second", t.wSecond));
	dumpFilePath = std::filesystem::path(mq::internal_paths::CrashDumps) / dumpFileName;

	auto hFile = CreateFileA(dumpFilePath.string().c_str(),
		GENERIC_WRITE, FILE_SHARE_READ, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	if (hFile == INVALID_HANDLE_VALUE)
		return;

	MINIDUMP_EXCEPTION_INFORMATION exceptionInfo;
	exceptionInfo.ThreadId = GetCurrentThreadId();
	exceptionInfo.ExceptionPointers = e;
	exceptionInfo.ClientPointers = false;

	bool dumped = MiniDumpWriteDump(
		GetCurrentProcess(),
		GetCurrentProcessId(),
		hFile,
		MINIDUMP_TYPE(MiniDumpWithUnloadedModules | MiniDumpWithIndirectlyReferencedMemory | MiniDumpScanMemory),
		e ? &exceptionInfo : nullptr,
		nullptr,
		nullptr);
	if (dumped)
		strcpy_s(dumppath, _Size, dumpFilePath.string().c_str());
	CloseHandle(hFile);
}

bool DirectoryExists(LPCTSTR lpszPath)
{
	DWORD dw = ::GetFileAttributes(lpszPath);
	return (dw != INVALID_FILE_ATTRIBUTES && (dw & FILE_ATTRIBUTE_DIRECTORY) != 0);
}

// ***************************************************************************
// Function:    ProcessGameEvents
// Description: Our ProcessGameEvents Hook
// ***************************************************************************

void SetMainThreadId();
void DoInitialization();

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
		DoInitialization();
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
		DebugSpew("Shutdown completed");

		g_Loaded = false;
		ScreenMode = oldscreenmode;
		SetEvent(hUnloadComplete);
	}

	return processGameEventsResult;
}

int Trampoline_ProcessGameEvents();
int Detour_ProcessGameEvents()
{
	DebugTryBeginRet();

	return DoGameEventsPulse(Trampoline_ProcessGameEvents);

	DebugTryEndRet();
}
DETOUR_TRAMPOLINE_EMPTY(int Trampoline_ProcessGameEvents());

void DoLoginPulse()
{
	DebugTryBegin();

	return DoGameEventsPulse(nullptr);

	DebugTryEnd()
}

class CEverQuestHook
{
public:
	void SetGameState_Trampoline(DWORD GameState);
	void SetGameState_Detour(DWORD GameState)
	{
		SetGameState_Trampoline(GameState);

		Benchmark(bmPluginsSetGameState, PluginsSetGameState(GameState));
	}

	void CMerchantWnd__PurchasePageHandler__UpdateList_Trampoline();
	void CMerchantWnd__PurchasePageHandler__UpdateList_Detour()
	{
		gItemsReceived = false;

		CMerchantWnd__PurchasePageHandler__UpdateList_Trampoline();

		gItemsReceived = true;
	}
};

DETOUR_TRAMPOLINE_EMPTY(void CEverQuestHook::SetGameState_Trampoline(DWORD));
DETOUR_TRAMPOLINE_EMPTY(void CEverQuestHook::CMerchantWnd__PurchasePageHandler__UpdateList_Trampoline());

//----------------------------------------------------------------------------

void Pulse_Initialize()
{
	DebugSpew("Initializing Pulse");

	std::scoped_lock lock(s_pulseMutex);

	EzDetour(__ProcessGameEvents, Detour_ProcessGameEvents, Trampoline_ProcessGameEvents);
	EzDetour(CEverQuest__SetGameState, &CEverQuestHook::SetGameState_Detour, &CEverQuestHook::SetGameState_Trampoline);
	EzDetour(CMerchantWnd__PurchasePageHandler__UpdateList, &CEverQuestHook::CMerchantWnd__PurchasePageHandler__UpdateList_Detour, &CEverQuestHook::CMerchantWnd__PurchasePageHandler__UpdateList_Trampoline);

	if (HMODULE EQWhMod = GetModuleHandle("eqw.dll"))
	{
		EQW_GetDisplayWindow = (fEQW_GetDisplayWindow)GetProcAddress(EQWhMod, "EQW_GetDisplayWindow");
	}
}

void Pulse_Shutdown()
{
	std::scoped_lock lock(s_pulseMutex);

	RemoveDetour(__ProcessGameEvents);
	RemoveDetour(CEverQuest__SetGameState);
	RemoveDetour(CMerchantWnd__PurchasePageHandler__UpdateList);
}

} // namespace mq
