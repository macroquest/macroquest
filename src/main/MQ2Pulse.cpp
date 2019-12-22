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
#include "DebugHandler.h"

#include <dbghelp.h>

#pragma warning(disable : 4091) // 'keyword' : ignored on left of 'type' when no variable is declared

namespace mq {

bool TurnNotDone = false;
static std::recursive_mutex s_pulseMutex;

std::map<int, std::string> targetBuffSlotToCasterMap;
std::map<int, std::map<int, TargetBuff>> CachedBuffsMap;

//----------------------------------------------------------------------------

std::vector<std::function<void()>> s_queuedEvents;
std::recursive_mutex s_queuedEventMutex;

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
	if (!ppCharSpawn || !pCharSpawn)
		return false;

	SPAWNINFO* pCharOrMount = nullptr;
	CHARINFO* pCharInfo = GetCharInfo();
	SPAWNINFO* pChar = pCharOrMount = (SPAWNINFO*)pCharSpawn;

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
		MQMacroLine ml = pBlock->Line[pBlock->CurrIndex];

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
					|| ci_find_substr(ml.Command, "/call") == 0)
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

	if (!ppCharSpawn || !pCharSpawn) return;

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
	EQSTRINGTABLE* pTable = (EQSTRINGTABLE*)pStringTable;
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

		if (gGameState == GAMESTATE_INGAME || gGameState == GAMESTATE_CHARSELECT || gGameState == GAMESTATE_CHARCREATE)
		{
			gbInZone = true;
			PluginsSetGameState(gGameState);
		}
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
			DebugTry(Benchmark(bmPluginsSetGameState, PluginsSetGameState(GameState)));
		}

		// they "zoned" to charselect...
		if (gZoning && (GameState == GAMESTATE_CHARSELECT || GameState == GAMESTATE_CHARCREATE))
		{
			gZoning = false;
			PluginsEndZone();
		}
	}
	else
	{
		return HeartbeatNormal;
	}

	DebugTry(UpdateMQ2SpawnSort());
	DebugTry(DrawHUD());

	if (gGameState == GAMESTATE_INGAME)
	{
		AddAutoBankMenu();
		AutoBankPulse();
	}

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

	DebugTry(ProcessPendingGroundItems());

	static bool ShownNews = false;
	if (gGameState == GAMESTATE_CHARSELECT && !ShownNews)
	{
		ShownNews = true;
		if (gCreateMQ2NewsWindow)
			CreateMQ2NewsWindow();
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

	auto hFile = CreateFileA(dumpFilePath.string().c_str(), GENERIC_WRITE, FILE_SHARE_READ, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
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

int MQ2ExceptionFilter(unsigned int code, struct _EXCEPTION_POINTERS* ex, const char* description, ...)
{
	char szOut[MAX_STRING] = { 0 };
	char szTemp[MAX_STRING] = { 0 };
	char szDumpPath[MAX_STRING] = { 0 };

	HANDLE hProcess;
	SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS | SYMOPT_LOAD_LINES);

	hProcess = GetCurrentProcess();

	SymInitialize(hProcess, nullptr, true);

	GetPrivateProfileString("Debug", "SymbolsPath", "", szTemp, MAX_STRING, mq::internal_paths::MQini);
	if (szTemp[0])
		SymSetSearchPath(hProcess, szTemp);
	SymGetSearchPath(hProcess, szOut, MAX_STRING);

	DWORD64  dwAddress;
	DWORD  dwDisplacement;
	IMAGEHLP_LINE64 line;

	line.SizeOfStruct = sizeof(IMAGEHLP_LINE64);
	dwAddress = (DWORD64)ex->ExceptionRecord->ExceptionAddress; // Address you want to check on.
	HMODULE hModule = nullptr;
	GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCTSTR)dwAddress, &hModule);
	GetModuleFileName(hModule, szOut, MAX_STRING);

	make_minidump(szOut, ex, szDumpPath);
	DWORD64  dwDisplacement2 = 0;
	DWORD64  dwAddress2 = (DWORD64)ex->ExceptionRecord->ExceptionAddress;

	char buffer[sizeof(SYMBOL_INFO) + MAX_SYM_NAME * sizeof(TCHAR)];
	PSYMBOL_INFO pSymbol = (PSYMBOL_INFO)buffer;

	pSymbol->SizeOfStruct = sizeof(SYMBOL_INFO);
	pSymbol->MaxNameLen = MAX_SYM_NAME;

	if (SymFromAddr(hProcess, dwAddress2, &dwDisplacement2, pSymbol))
	{
		if (SymGetLineFromAddr64(hProcess, dwAddress, &dwDisplacement, &line))
		{
			sprintf_s(szTemp, "%s crashed in %s Line: %d (address 0x%llX)\nDump saved to %s\n\nSend it to eqmule@hotmail.com\n\nYou can click retry and hope for the best, or just click cancel to kill the process right now.", pSymbol->Name, line.FileName, line.LineNumber, line.Address - (DWORD)hModule, szDumpPath);
		}
		else
		{
			sprintf_s(szTemp, "%s crashed at address 0x%llX\nDump saved to %s\n\nSend it to eqmule@hotmail.com\n\nYou can click retry and hope for the best, or just click cancel to kill the process right now.", pSymbol->Name, pSymbol->Address - (DWORD)hModule, szDumpPath);
		}
	}
	else
	{
		sprintf_s(szTemp, "%s crashed at address 0x%llX\nDump saved to %s\n\nSend it to eqmule@hotmail.com\n\nYou can click retry and hope for the best, or just click cancel to kill the process right now.", szOut, dwAddress - (DWORD)hModule, szDumpPath);
	}

	SymCleanup(hProcess);

	int mbret = MessageBox(nullptr, szTemp, szOut, MB_ICONERROR | MB_SYSTEMMODAL | MB_RETRYCANCEL | MB_DEFBUTTON1);
	if (mbret == IDCANCEL)
	{
		exit(0);
	}

	return EXCEPTION_EXECUTE_HANDLER;
}

int MQ2ExceptionFilter2(PEXCEPTION_POINTERS ex)
{
	char szOut[MAX_STRING] = { 0 };
	char szTemp[MAX_STRING] = { 0 };
	char szDumpPath[MAX_STRING] = { 0 };

	HANDLE hProcess;

	SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS | SYMOPT_LOAD_LINES);

	hProcess = GetCurrentProcess();

	SymInitialize(hProcess, nullptr, true);

	GetPrivateProfileString("Debug", "SymbolsPath", "", szTemp, MAX_STRING, mq::internal_paths::MQini);
	if (szTemp[0])
		SymSetSearchPath(hProcess, szTemp);
	SymGetSearchPath(hProcess, szOut, MAX_STRING);

	DWORD64  dwAddress;
	DWORD  dwDisplacement;
	IMAGEHLP_LINE64 line;

	line.SizeOfStruct = sizeof(IMAGEHLP_LINE64);
	dwAddress = (DWORD64)ex->ExceptionRecord->ExceptionAddress; // Address you want to check on.
	HMODULE hModule = nullptr;
	GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCTSTR)dwAddress, &hModule);
	GetModuleFileName(hModule, szOut, MAX_STRING);

	make_minidump(szOut, ex, szDumpPath);
	DWORD64  dwDisplacement2 = 0;
	DWORD64  dwAddress2 = (DWORD64)ex->ExceptionRecord->ExceptionAddress;

	char buffer[sizeof(SYMBOL_INFO) + MAX_SYM_NAME * sizeof(TCHAR)];
	PSYMBOL_INFO pSymbol = (PSYMBOL_INFO)buffer;

	pSymbol->SizeOfStruct = sizeof(SYMBOL_INFO);
	pSymbol->MaxNameLen = MAX_SYM_NAME;

	if (SymFromAddr(hProcess, dwAddress2, &dwDisplacement2, pSymbol))
	{
		if (SymGetLineFromAddr64(hProcess, dwAddress, &dwDisplacement, &line))
		{
			sprintf_s(szTemp, "%s crashed in %s Line: %d (address 0x%llX)\nDump saved to %s\n\nYou can click retry and hope for the best, or just click cancel to kill the process right now.", pSymbol->Name, line.FileName, line.LineNumber, line.Address - (DWORD)hModule, szDumpPath);
		}
		else
		{
			sprintf_s(szTemp, "%s crashed at address 0x%llX\nDump saved to %s\n\nYou can click retry and hope for the best, or just click cancel to kill the process right now.", pSymbol->Name, pSymbol->Address - (DWORD)hModule, szDumpPath);
		}
	}
	else
	{
		sprintf_s(szTemp, "%s crashed at address 0x%llX\nDump saved to %s\n\nYou can click retry and hope for the best, or just click cancel to kill the process right now.", szOut, dwAddress - (DWORD)hModule, szDumpPath);
	}

	SymCleanup(hProcess);

	int mbret = MessageBox(nullptr, szTemp, szOut, MB_ICONERROR | MB_SYSTEMMODAL | MB_RETRYCANCEL | MB_DEFBUTTON1);
	if (mbret == IDCANCEL)
	{
		exit(0);
	}

	return EXCEPTION_EXECUTE_HANDLER;
}

void GameLoop_Tramp();
void GameLoop_Detour()
{
	__try
	{
		//MessageBox(nullptr, "Starting EQ", "", MB_SYSTEMMODAL | MB_OK);
		GameLoop_Tramp();
	}
	//__except (MQ2ExceptionFilter(GetExceptionCode(), GetExceptionInformation(), "GameLoop_Detour %d",1))
	__except (MQ2ExceptionFilter2(GetExceptionInformation()))
	{
		//RemoveDetour(__GameLoop);
		MessageBox(nullptr, "Exception caught in GameLoop", "", MB_SYSTEMMODAL | MB_OK);
		exit(0);
	}
}
DETOUR_TRAMPOLINE_EMPTY(void GameLoop_Tramp());

// ***************************************************************************
// Function:    ProcessGameEvents
// Description: Our ProcessGameEvents Hook
// ***************************************************************************

void DoInitialization();

bool Trampoline_ProcessGameEvents();
bool Detour_ProcessGameEvents()
{
	DebugTryBeginRet();

	std::scoped_lock lock(s_pulseMutex);

	HeartbeatState hbState = Heartbeat();
	int pgeResult = Trampoline_ProcessGameEvents();

	if (hbState == HeartbeatLoad && !IsPluginsInitialized())
	{
		OutputDebugString("I am loading in ProcessGameEvents");

		DWORD oldscreenmode = std::exchange(ScreenMode, 3);

		DoInitialization();

		ScreenMode = oldscreenmode;
		SetEvent(hLoadComplete);
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

	return pgeResult;
	DebugTryEndRet();
}
DETOUR_TRAMPOLINE_EMPTY(bool Trampoline_ProcessGameEvents());

void RemoveLoginPulse();

class CEverQuestHook
{
public:
	void EnterZone_Trampoline(void* pVoid);
	void EnterZone_Detour(void* pVoid)
	{
		EnterZone_Trampoline(pVoid);
	}

	void SetGameState_Trampoline(DWORD GameState);
	void SetGameState_Detour(DWORD GameState)
	{
		SetGameState_Trampoline(GameState);

		Benchmark(bmPluginsSetGameState, PluginsSetGameState(GameState));

		if (GameState == GAMESTATE_LOGGINGIN)
		{
			RemoveLoginPulse();
		}
	}

	void CMerchantWnd__PurchasePageHandler__UpdateList_Trampoline();
	void CMerchantWnd__PurchasePageHandler__UpdateList_Detour()
	{
		gItemsReceived = false;

		CMerchantWnd__PurchasePageHandler__UpdateList_Trampoline();

		gItemsReceived = true;
	}

	void CTargetWnd__RefreshTargetBuffs_Trampoline(BYTE*);
	void CTargetWnd__RefreshTargetBuffs_Detour(BYTE* buffer)
	{
		// ok so we can cache songs as well here, they are not displayed in the client for some reason...
		gTargetbuffs = false;

		int count = 0;

		CTargetWnd__RefreshTargetBuffs_Trampoline(buffer);
		CTargetWnd* pTW = (CTargetWnd*)this;

		for (int i : pTW->BuffSpellID)
		{
			if (i > 0)
				count++;
		}
		targetBuffSlotToCasterMap.clear();

		CUnSerializeBuffer* packet = (CUnSerializeBuffer*)buffer;
		packet->Reset();

		struct TargetHeader
		{
			int m_id;
			int m_timeNext;
			bool m_bComplete;
			short m_count;
		};
		TargetHeader header;

		packet->Read(header.m_id);
		packet->Read(header.m_timeNext);
		packet->Read(header.m_bComplete);
		packet->Read(header.m_count);
		TargetBuff curBuff;

		int id = pTarget->SpawnID;
		CachedBuffsMap[id].clear();

		for (int i = 0; i < header.m_count; i++)
		{
			ZeroMemory(&curBuff, sizeof(TargetBuff));
			packet->Read(curBuff.slot);
			packet->Read(curBuff.spellId);
			packet->Read(curBuff.duration);
			packet->Read(curBuff.count);
			packet->ReadpChar(curBuff.casterName);

			if (pTarget)
			{
				curBuff.timeStamp = EQGetTime();
				CachedBuffsMap[pTarget->SpawnID][curBuff.spellId] = curBuff;

				if ((curBuff.slot >= 42 && (pTarget->Type == SPAWN_PLAYER || pTarget->Mercenary)) || (curBuff.slot >= 55) || (curBuff.slot < 0))
				{
					continue;
				}

				targetBuffSlotToCasterMap[curBuff.slot] = curBuff.casterName;
			}
		}

		if (gbAssistComplete == AS_AssistSent)
		{
			gbAssistComplete = AS_AssistReceived;
		}

		gTargetbuffs = true;
	}

	// This is called continually during the login mainloop so we can use it as our pulse when the MAIN
	// gameloop pulse is not active but login is.
	// that will allow plugins to work and execute commands all the way back pre login and server select etc.
	void LoginController__GiveTime_Tramp();
	void LoginController__GiveTime_Detour()
	{
		std::scoped_lock lock(s_pulseMutex);

		PulsePlugins();
		LoginController__GiveTime_Tramp();
	}
};

bool isNotOKToReadMemory(void* ptr, DWORD size)
{
	MEMORY_BASIC_INFORMATION mbi;
	size_t dw = VirtualQuery(ptr, &mbi, sizeof(mbi));

	if ((mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)) != 0)
		return true;

	DWORD flags = PAGE_READONLY | PAGE_READWRITE | PAGE_WRITECOPY | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY;

	return (mbi.Protect & flags) == 0;
}

void RemoveLoginPulse()
{
	if (LoginController__GiveTime)
	{
		if (!isNotOKToReadMemory((void*)LoginController__GiveTime, 4))
		{
			RemoveDetour(LoginController__GiveTime);
		}
		else
		{
			DeleteDetour(LoginController__GiveTime);
		}

		LoginController__GiveTime = 0;
	}
}

// patterns
// LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
// Feb 16 2018 Test
// IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static BYTE* lpPattern = (BYTE*)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";

void InitializeLoginPulse()
{
	if (*(DWORD*)__heqmain && !LoginController__GiveTime)
	{
		if (!(LoginController__GiveTime = FindPattern(*(DWORD*)__heqmain, 0x200000, lpPattern, lpMask)))
		{
			MessageBox(nullptr, "MQ2 needs an update.", "Couldn't find LoginController__GiveTime", MB_SYSTEMMODAL | MB_OK);
			return;
		}

		if (LoginController__GiveTime)
		{
			if (*(BYTE*)LoginController__GiveTime != 0xe9)
			{
				EzDetour(LoginController__GiveTime, &CEverQuestHook::LoginController__GiveTime_Detour, &CEverQuestHook::LoginController__GiveTime_Tramp);
			}
		}
	}
}
DETOUR_TRAMPOLINE_EMPTY(void CEverQuestHook::LoginController__GiveTime_Tramp());
DETOUR_TRAMPOLINE_EMPTY(void CEverQuestHook::EnterZone_Trampoline(void*));
DETOUR_TRAMPOLINE_EMPTY(void CEverQuestHook::SetGameState_Trampoline(DWORD));
DETOUR_TRAMPOLINE_EMPTY(void CEverQuestHook::CTargetWnd__RefreshTargetBuffs_Trampoline(BYTE*));
DETOUR_TRAMPOLINE_EMPTY(void CEverQuestHook::CMerchantWnd__PurchasePageHandler__UpdateList_Trampoline());

void InitializeMQ2Pulse()
{
	DebugSpew("Initializing Pulse");

	std::scoped_lock lock(s_pulseMutex);

	//EzDetour(__GameLoop, GameLoop_Detour, GameLoop_Tramp);
	EzDetour(ProcessGameEvents, Detour_ProcessGameEvents, Trampoline_ProcessGameEvents);
	//EzDetour(CEverQuest__EnterZone, &CEverQuestHook::EnterZone_Detour, &CEverQuestHook::EnterZone_Trampoline);
	EzDetour(CEverQuest__SetGameState, &CEverQuestHook::SetGameState_Detour, &CEverQuestHook::SetGameState_Trampoline);
	EzDetour(CTargetWnd__RefreshTargetBuffs, &CEverQuestHook::CTargetWnd__RefreshTargetBuffs_Detour, &CEverQuestHook::CTargetWnd__RefreshTargetBuffs_Trampoline);
	EzDetour(CMerchantWnd__PurchasePageHandler__UpdateList, &CEverQuestHook::CMerchantWnd__PurchasePageHandler__UpdateList_Detour, &CEverQuestHook::CMerchantWnd__PurchasePageHandler__UpdateList_Trampoline);

	InitializeLoginPulse();

	if (HMODULE EQWhMod = GetModuleHandle("eqw.dll"))
	{
		EQW_GetDisplayWindow = (fEQW_GetDisplayWindow)GetProcAddress(EQWhMod, "EQW_GetDisplayWindow");
	}
}

void ShutdownMQ2Pulse()
{
	std::scoped_lock lock(s_pulseMutex);

	RemoveDetour((DWORD)ProcessGameEvents);
	RemoveLoginPulse();
	//RemoveDetour(CEverQuest__EnterZone);
	RemoveDetour(CEverQuest__SetGameState);
	RemoveDetour(CMerchantWnd__PurchasePageHandler__UpdateList);
	RemoveDetour(CTargetWnd__RefreshTargetBuffs);
}

} // namespace mq
