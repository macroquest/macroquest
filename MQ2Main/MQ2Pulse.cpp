/*****************************************************************************
MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License, version 2, as published by
the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
******************************************************************************/
#if !defined(CINTERFACE)
#error /DCINTERFACE
#endif

#define DBG_SPEW


//#define DEBUG_TRY 1
#include "MQ2Main.h"
BOOL TurnNotDone = FALSE;
CRITICAL_SECTION gPulseCS;
#ifndef ISXEQ

#include <locale>//for tolower
// templated version of my_equal so it can work with both char and wchar_t
template<typename charT>
struct my_equal {
    my_equal( const std::locale& loc ) : loc_(loc) {}
    bool operator()(charT ch1, charT ch2) {
        return std::tolower(ch1, loc_) == std::tolower(ch2, loc_);
    }
private:
    const std::locale& loc_;
};

// find substring (case insensitive)
template<typename T>
int ci_find_substr( const T& str1, const char* charin, const std::locale& loc = std::locale() )
{
	std::string str2 = charin;
    typename T::const_iterator it = std::search( str1.begin(), str1.end(), 
        str2.begin(), str2.end(), my_equal<typename T::value_type>(loc) );
    if ( it != str1.end() ) return it - str1.begin();
    else return -1; // not found
}

BOOL DoNextCommand(PMACROBLOCK pBlock)
{
	if (!ppCharSpawn || !pCharSpawn) return FALSE;
	PSPAWNINFO pCharOrMount = NULL;
	PCHARINFO pCharInfo = GetCharInfo();
	PSPAWNINFO pChar = pCharOrMount = (PSPAWNINFO)pCharSpawn;
	if (pCharInfo && pCharInfo->pSpawn) pChar = pCharInfo->pSpawn;
	if ((!pChar) || (gZoning)/* || (gDelayZoning)*/) return FALSE;
	if (((gFaceAngle != 10000.0f) || (gLookAngle != 10000.0f)) && (TurnNotDone)) return FALSE;
	if (IsMouseWaiting()) return FALSE;
	if (gDelay && gDelayCondition[0])
	{
		CHAR szCond[MAX_STRING];
		strcpy_s(szCond, gDelayCondition);
		ParseMacroParameter(GetCharInfo()->pSpawn, szCond);
		DOUBLE Result;
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
	if (!gDelay && pBlock && !pBlock->Paused && (!gMQPauseOnChat || *EQADDR_NOTINCHATMODE) && gMacroStack) {
		MACROLINE ml = pBlock->Line[pBlock->CurrIndex];
		if (pBlock->BindStackIndex == pBlock->CurrIndex) {
			//WriteChatf("Ending Bind @ %d %s",pBlock->CurrIndex,ml.Command.c_str());
			gBindInProgress = false;
			pBlock->BindStackIndex = -1;
		}
		gMacroStack->LocationIndex = pBlock->CurrIndex;
#ifdef MQ2_PROFILING
		LARGE_INTEGER BeforeCommand;
		QueryPerformanceCounter(&BeforeCommand);
		int ThisMacroBlock = pBlock->CurrIndex;
#endif
		//CHAR szLine[MAX_STRING];
		//sprintf_s(szLine, "/SetChatTitle MQ - MacroLine: %d", ml.LineNumber);
		//EzCommand(szLine);
		DoCommand(pChar, (PCHAR)ml.Command.c_str());
		PMACROBLOCK pCurrentBlock = GetCurrentMacroBlock();
		if (pCurrentBlock)
		{
			if (pCurrentBlock->BindCmd.size() && pCurrentBlock->BindStackIndex==-1) {
				if (ci_find_substr(ml.Command, "/varset") == 0 || ci_find_substr(ml.Command, "/echo") == 0 || ci_find_substr(ml.Command, "Sub") == 0 || ci_find_substr(ml.Command, "/call") == 0) {
					std::map<int, MACROLINE>::iterator i = pCurrentBlock->Line.find(pCurrentBlock->CurrIndex);
					if (i != pCurrentBlock->Line.end()) {
						i++;
						if (i != pCurrentBlock->Line.end()) {
							//WriteChatf("Starting %s @ %d %s", pBlock->BindCmd.c_str(), i->first, i->second.Command.c_str());
							pCurrentBlock->BindStackIndex = i->first;
						}
						else {
							FatalError("Reached end of macro.");
						}
					}
					Call(pChar, (PCHAR)pCurrentBlock->BindCmd.c_str());
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
			if (pCurrentBlock->CurrIndex>lastindex) {
				FatalError("Reached end of macro.");
			}
			else {
				std::map<int, MACROLINE>::iterator i = pCurrentBlock->Line.find(pCurrentBlock->CurrIndex);
				if (i != pCurrentBlock->Line.end()) {
					i++;
					if (i != pCurrentBlock->Line.end()) {
						pCurrentBlock->CurrIndex = i->first;
					}
				}
				else {
					FatalError("Reached end of macro.");
				}
			}
		}
		else {
			return FALSE;
		}
		return TRUE;
	}
	return FALSE;
}
#endif
//added these so I can work on making face look natural - eqmule
void NaturalTurnOld(PSPAWNINFO pCharOrMount,PSPAWNINFO pChar)
{
	if (abs((INT)(pCharOrMount->Heading - gFaceAngle)) < 10.0f) {
		pCharOrMount->Heading = (FLOAT)gFaceAngle;
		pCharOrMount->SpeedHeading = 0.0f;
		gFaceAngle = 10000.0f;
	}
	else {
		TurnNotDone = TRUE;
		DOUBLE c1 = pCharOrMount->Heading + 256.0f;
		DOUBLE c2 = gFaceAngle;
		if (c2<pChar->Heading) c2 += 512.0f;
		DOUBLE turn = (DOUBLE)(rand() % 200) / 10;
		if (c2<c1) {
			pCharOrMount->Heading += (FLOAT)turn;
			pCharOrMount->SpeedHeading = 12.0f;
			if (pCharOrMount->Heading >= 512.0f) pCharOrMount->Heading -= 512.0f;
		}
		else {
			pCharOrMount->Heading -= (FLOAT)turn;
			pCharOrMount->SpeedHeading = -12.0f;
			if (pCharOrMount->Heading<0.0f) pCharOrMount->Heading += 512.0f;
		}
	}
}
	
void NaturalTurn(PSPAWNINFO pCharOrMount,PSPAWNINFO pChar)
{
	//ok we need to turn now, but there are some things we need to take into account
	//first of all the turn rate mkay...
	float TurnRate = 4.0f;
	float fHeadingDiff = 0.0f;
	float AbsHeadingDiff = HeadingDiff(pCharOrMount->Heading, (float)gFaceAngle, &fHeadingDiff);
	if (AbsHeadingDiff < 1.0f) {
		//thats nothing... just set it...
		pCharOrMount->Heading = (float)gFaceAngle;
		pCharOrMount->SpeedHeading = 0.0f;
		gFaceAngle = 10000.0f;
	}
	else {
		TurnNotDone = TRUE;
		//lets make this look natural mkay...
		if (AbsHeadingDiff < TurnRate) {
			TurnRate = AbsHeadingDiff;
		} else if (AbsHeadingDiff > 128.0f)	{
			TurnRate = 9.0f;
		}
		if (((pCharOrMount->Heading < gFaceAngle) && (fHeadingDiff < 0.0f)) || ((gFaceAngle < pCharOrMount->Heading) && (fHeadingDiff > 0.0f)))	{
			pCharOrMount->Heading = pCharOrMount->Heading - TurnRate;
		} else {
			pCharOrMount->Heading = pCharOrMount->Heading + TurnRate;
		}
		pCharOrMount->Heading = FixHeading(pCharOrMount->Heading);
	}
}
//extern BOOL gbInForeground;
void Pulse()
{
	static HWND EQhWnd = *(HWND*)EQADDR_HWND;
	if (EQW_GetDisplayWindow)
		EQhWnd = EQW_GetDisplayWindow();
	gbInForeground = (GetForegroundWindow() == EQhWnd);

	if (!ppCharSpawn || !pCharSpawn) return;
	PSPAWNINFO pCharOrMount = NULL;
#ifndef NEWCHARINFO
	PCHARINFONEW pCharInfoNew = (PCHARINFONEW)GetCharInfo();
#endif
	PCHARINFO pCharInfo = GetCharInfo();
	PCHARINFO2 pCharInfo2 = GetCharInfo2();
	PSPAWNINFO pChar = pCharOrMount = (PSPAWNINFO)pCharSpawn;
	if (pCharInfo && pCharInfo->pSpawn) pChar = pCharInfo->pSpawn;

	static WORD LastZone = -1;

	static PSPAWNINFO pCharOld = NULL;
	static FLOAT LastX = 0.0f;
	static FLOAT LastY = 0.0f;
	static ULONGLONG LastMoveTick = 0;
	static DWORD MapDelay = 0;

	// Drop out here if we're waiting for something.
	if (!pChar || gZoning /* || gDelayZoning*/) return;
	if (!pCharInfo) {
		//DebugSpew("Pulse: no charinfo returning\n");
		return;
	}

	if ((unsigned int)GetCharInfo()->charinfo_info & 0x80000000) return;

	if (pChar != pCharOld && WereWeZoning)
	{
		WereWeZoning = FALSE;
		pCharOld = pChar;
		gFaceAngle = 10000.0f;
		gLookAngle = 10000.0f;
		gbMoving = FALSE;
		LastX = pChar->X;
		LastY = pChar->Y;
		LastMoveTick = MQGetTickCount64();
		EnviroTarget.Name[0] = 0;
		pGroundTarget = 0;
		ZeroMemory(&GroundObject, sizeof(GroundObject));
		DoorEnviroTarget.Name[0] = 0;
		DoorEnviroTarget.DisplayedName[0] = 0;
		pDoorTarget = 0;

		// see if we're on a pvp server
		if (!_strnicmp(EQADDR_SERVERNAME, "tallon", 6) || !_strnicmp(EQADDR_SERVERNAME, "vallon", 6))
		{
			PVPServer = PVP_TEAM;
		}
		else if (!_strnicmp(EQADDR_SERVERNAME, "sullon", 6))
		{
			PVPServer = PVP_SULLON;
		}
		else if (!_strnicmp(EQADDR_SERVERNAME, "rallos", 6))
		{
			PVPServer = PVP_RALLOS;
		}
		else
			PVPServer = PVP_NONE;
		srand((unsigned int)time(NULL) + (unsigned int)GetCurrentProcessId()); // reseed
		Benchmark(bmPluginsOnZoned, PluginsZoned());
		
	}
	else if ((LastX != pChar->X) || (LastY != pChar->Y) || LastMoveTick>MQGetTickCount64() - 100) {
		if ((LastX != pChar->X) || (LastY != pChar->Y)) LastMoveTick = MQGetTickCount64();
		gbMoving = TRUE;
		LastX = pChar->X;
		LastY = pChar->Y;
	}
	else {
		gbMoving = FALSE;
	}
	if (!pTarget)
		gTargetbuffs = FALSE;
	if (pMerchantWnd && pMerchantWnd->dShow==false)
		gItemsReceived = FALSE;
	if (gbDoAutoRun && pChar && pCharInfo) {
		gbDoAutoRun = FALSE;
#if !defined(ROF2EMU) && !defined(UFEMU)
		InitKeyRings();
#endif
		CHAR szServerAndName[MAX_STRING] = { 0 };
		CHAR szAutoRun[MAX_STRING] = { 0 };
		PCHAR pAutoRun = szAutoRun;
		/* autorun for everyone */
		GetPrivateProfileString("AutoRun", "ALL", "", szAutoRun, MAX_STRING, gszINIFilename);
		while (pAutoRun[0] == ' ' || pAutoRun[0] == '\t') pAutoRun++;
		if (szAutoRun[0] != 0)
			DoCommand(pChar, pAutoRun);
		/* autorun for toon */
		ZeroMemory(szAutoRun, MAX_STRING); pAutoRun = szAutoRun;
		sprintf_s(szServerAndName, "%s.%s", EQADDR_SERVERNAME, pCharInfo->Name);
		GetPrivateProfileString("AutoRun", szServerAndName, "", szAutoRun, MAX_STRING, gszINIFilename);
		while (pAutoRun[0] == ' ' || pAutoRun[0] == '\t') pAutoRun++;
		if (szAutoRun[0] != 0)
			DoCommand(pChar, pAutoRun);
	}
	if (gbShowCurrentCamera) {
		if (pWndMgr && pSelectorWnd) {
			if (oldcameratype != *(DWORD*)CDisplay__cameraType) {
				oldcameratype = *(DWORD*)CDisplay__cameraType;
				sprintf_s(CameraText, "Selector Window (Camera %d)", oldcameratype);
			}
			SetCXStr(&pSelectorWnd->WindowText, CameraText);
		}
	}
	if ((gFaceAngle != 10000.0f) || (gLookAngle != 10000.0f)) {
		TurnNotDone = FALSE;
		if (gFaceAngle != 10000.0f) {
			NaturalTurn(pCharOrMount,pChar);
		}
		if (gLookAngle != 10000.0f) {
			if (abs((INT)(pChar->CameraAngle - gLookAngle)) < 5.0f) {
				pChar->CameraAngle = (FLOAT)gLookAngle;
				gLookAngle = 10000.0f;
				TurnNotDone = FALSE;
			}
			else {
				TurnNotDone = TRUE;
				FLOAT c1 = pChar->CameraAngle;
				FLOAT c2 = (FLOAT)gLookAngle;

				DOUBLE turn = (DOUBLE)(rand() % 200) / 20;
				if (c1<c2) {
					pChar->CameraAngle += (FLOAT)turn;
					if (pChar->CameraAngle >= 128.0f) pChar->CameraAngle -= 128.0f;
				}
				else {
					pChar->CameraAngle -= (FLOAT)turn;
					if (pChar->CameraAngle <= -128.0f) pChar->CameraAngle += 128.0f;
				}
			}
		}

		if (TurnNotDone) {
			bRunNextCommand = FALSE;
			IsMouseWaiting();
			return;
		}
	}
}

int Heartbeat()
{
	if (gbUnload) {
		return 1;
	}
	if (gbLoad) {
		gbLoad = FALSE;
		return 2;
	}

	static ULONGLONG LastGetTick = 0;
	static bool bFirstHeartBeat = true;
	static ULONGLONG TickDiff = 0;
	static fMQPulse pEQPlayNicePulse = NULL;
	static DWORD BeatCount = 0;

	ULONGLONG Tick = MQGetTickCount64();

	BeatCount++;

	if (bFirstHeartBeat)
	{
		LastGetTick = Tick;
		bFirstHeartBeat = false;
	}
	// This accounts for rollover
	TickDiff += (Tick - LastGetTick);
	LastGetTick = Tick;
#ifndef ISXEQ
	while (TickDiff >= 100) {
		TickDiff -= 100;
		if (gDelay>0) gDelay--;
		DropTimers();
	}
#endif
	if (!gStringTableFixed && pStringTable) // Please dont remove the second condition
	{
		FixStringTable();
		gStringTableFixed = TRUE;
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
	}
	else
		return 0;
	DebugTry(UpdateMQ2SpawnSort());
#ifndef ISXEQ_LEGACY
#ifndef ISXEQ
	DebugTry(DrawHUD());
	if (gGameState == GAMESTATE_INGAME)
	{
		AddAutoBankMenu();
		AutoBankPulse();
	}
	//if (gGameState==GAMESTATE_INGAME && !bMouseLook && ScreenMode==3)
	//{
	//    DebugTry(pWndMgr->DrawCursor());
	//}
#endif
#endif

	bRunNextCommand = TRUE;
	DebugTry(Pulse());
#ifndef ISXEQ_LEGACY
#ifndef ISXEQ
	DebugTry(Benchmark(bmPluginsPulse, DebugTry(PulsePlugins())));
#endif
	if (pEQPlayNicePulse) {
		pEQPlayNicePulse();
	}
	else {
		HMODULE hmEQPlayNice;
		if (((BeatCount % 63) == 0) && (hmEQPlayNice = GetModuleHandle("EQPlayNice.dll"))) {
			if (pEQPlayNicePulse = (fMQPulse)GetProcAddress(hmEQPlayNice, "Compat_ProcessFrame"))
				pEQPlayNicePulse();
		}
	}
#endif
	DebugTry(ProcessPendingGroundItems());


	static bool ShownNews = false;
	if (gGameState == GAMESTATE_CHARSELECT && !ShownNews)
	{
		ShownNews = true;
		if (gCreateMQ2NewsWindow)
			CreateMQ2NewsWindow();
	}

#ifndef ISXEQ
	DWORD CurTurbo = 0;

	if (gDelayedCommands) {// delayed commands
		lockit lk(ghLockDelayCommand,"HeartBeat");
		DoCommand((PSPAWNINFO)pLocalPlayer, gDelayedCommands->szText);
		PCHATBUF pNext = gDelayedCommands->pNext;
		//HLOCAL hlret = LocalFree(gDelayedCommands);
		//if (hlret != 0) {
		//	MessageBox(NULL,"LocalFree Failed we have a memory leak in HeartBeat","tell eqmule",MB_SYSTEMMODAL|MB_OK);
		//}
		delete gDelayedCommands;
		gDelayedCommands = pNext;
	}
	PMACROBLOCK pBlock = GetNextMacroBlock();
	while (bRunNextCommand) {
		if (!DoNextCommand(pBlock))
			break;
		if (gbUnload)
			return 1;
		if (!gTurbo)
			break;//bRunNextCommand = FALSE;
		if (++CurTurbo>gMaxTurbo)
			break;//bRunNextCommand =   FALSE;
	}
	DoTimedCommands();
#endif
	return 0;
}

#ifndef ISXEQ_LEGACY
// *************************************************************************** 
// Function:    ProcessGameEvents 
// Description: Our ProcessGameEvents Hook
// *************************************************************************** 
BOOL Trampoline_ProcessGameEvents(VOID);
BOOL Detour_ProcessGameEvents(VOID)
{
	CAutoLock Lock(&gPulseCS);
	int ret = Heartbeat();
#ifdef ISXEQ
	if (!pISInterface->ScriptEngineActive())
		pISInterface->LavishScriptPulse();
#endif
	int ret2 =  Trampoline_ProcessGameEvents();
#ifndef ISXEQ
	if(ret==2 && bPluginCS==0) {
		OutputDebugString("I am loading in ProcessGameEvents");
		//we are loading stuff
		DWORD oldscreenmode = ScreenMode;
		ScreenMode = 3;
		InitializeMQ2Commands();
		InitializeMQ2Windows();
		MQ2MouseHooks(1);
		Sleep(100);
		InitializeMQ2KeyBinds();
		#ifndef ISXEQ
		InitializeMQ2Plugins();
		#endif
		ScreenMode = oldscreenmode;
		SetEvent(hLoadComplete);
	} else if(ret==1) {
		OutputDebugString("I am unloading in ProcessGameEvents");
		//we are unloading stuff
		DWORD oldscreenmode = ScreenMode;
		ScreenMode = 3;
		WriteChatColor(UnloadedString,USERCOLOR_DEFAULT);
		DebugSpewAlways("%s", UnloadedString);
		UnloadMQ2Plugins();
		MQ2Shutdown();
		DebugSpew("Shutdown completed");
		g_Loaded = FALSE;
		ScreenMode = oldscreenmode;
		SetEvent(hUnloadComplete);

	}
#endif
	return ret2;
}

std::map<int, std::string>targetBuffSlotToCasterMap; 

struct cTargetHeader
{
    int m_id;
    int m_timeNext;
    bool m_bComplete;
    short m_count;
};

struct cTargetBuff
{
    int slot;
    int spellId;
    int duration;
    int count;
    CHAR casterName[64];
};
void RemoveLoginPulse();
DETOUR_TRAMPOLINE_EMPTY(BOOL Trampoline_ProcessGameEvents(VOID));
class CEverQuestHook {
public:
	VOID EnterZone_Trampoline(PVOID pVoid);
	VOID EnterZone_Detour(PVOID pVoid)
	{
		EnterZone_Trampoline(pVoid);
		gZoning = TRUE;
		WereWeZoning = TRUE;
	}

	VOID SetGameState_Trampoline(DWORD GameState);
	VOID SetGameState_Detour(DWORD GameState)
	{
		//DebugSpew("SetGameState_Detour(%d)",GameState);
		SetGameState_Trampoline(GameState);
		Benchmark(bmPluginsSetGameState, PluginsSetGameState(GameState));
		if (GameState == GAMESTATE_LOGGINGIN) {
			RemoveLoginPulse();
		}
	}
	VOID CMerchantWnd__PurchasePageHandler__UpdateList_Trampoline();
	VOID CMerchantWnd__PurchasePageHandler__UpdateList_Detour()
	{
		CMerchantWnd*me = (CMerchantWnd*)this;
		CMerchantWnd*me2 = (CMerchantWnd*)pMerchantWnd;
		gItemsReceived = FALSE;
		CMerchantWnd__PurchasePageHandler__UpdateList_Trampoline();
		gItemsReceived = TRUE;
	}
	VOID CTargetWnd__RefreshTargetBuffs_Trampoline(PBYTE);
	VOID CTargetWnd__RefreshTargetBuffs_Detour(PBYTE buffer)
	{
		gTargetbuffs = FALSE;
		CTargetWnd__RefreshTargetBuffs_Trampoline(buffer);

        targetBuffSlotToCasterMap.clear();

        CUnSerializeBuffer* packet = (CUnSerializeBuffer*)buffer;
        packet->Reset();

        cTargetHeader header;
            
        packet->Read( header.m_id );
        packet->Read( header.m_timeNext );
        packet->Read( header.m_bComplete );
        packet->Read( header.m_count );
        cTargetBuff curBuff;

        for( int i = 0; i < header.m_count; i++ ) {
			ZeroMemory(&curBuff, sizeof(cTargetBuff));
            packet->Read( curBuff.slot );
            packet->Read( curBuff.spellId );
            packet->Read( curBuff.duration );
            packet->Read( curBuff.count );
            packet->ReadpChar( curBuff.casterName );
			if (pTarget) {
				if ((curBuff.slot >= 42 && (pTarget->Data.Type == SPAWN_PLAYER || pTarget->Data.Mercenary)) || (curBuff.slot >= 55) || (curBuff.slot < 0)) {
					continue;
				}
				targetBuffSlotToCasterMap[curBuff.slot] = curBuff.casterName;
			}
        }
		if (gbAssistComplete == 1) {
			gbAssistComplete = 2;
		}
		gTargetbuffs = TRUE;
	}
	//This is called continually during the login mainloop so we can use it as our pulse when the MAIN gameloop pulse is not active but login is. -eqmule
	//that will allow plugins to work and execute commands all the way back pre login and server select etc.
	void LoginController__GiveTime_Tramp();
	void LoginController__GiveTime_Detour()
	{
		CAutoLock Lock(&gPulseCS);
		PulsePlugins();
		LoginController__GiveTime_Tramp();
	}
};
int isNotOKToReadMemory(void *ptr, DWORD size)
{
	SIZE_T	dw;
	MEMORY_BASIC_INFORMATION	mbi;
	int	ok;

	dw = VirtualQuery(ptr, &mbi, sizeof(mbi));
	ok = ((mbi.Protect & PAGE_READONLY) ||
		  (mbi.Protect & PAGE_READWRITE) ||
		  (mbi.Protect & PAGE_WRITECOPY) ||
		  (mbi.Protect & PAGE_EXECUTE_READ) ||
		  (mbi.Protect & PAGE_EXECUTE_READWRITE) ||
		  (mbi.Protect & PAGE_EXECUTE_WRITECOPY));
	if (mbi.Protect & PAGE_GUARD)
		ok = FALSE;
	if (mbi.Protect & PAGE_NOACCESS)
		ok = FALSE;
	return !ok;
}

void RemoveLoginPulse()
{
	if (LoginController__GiveTime) {
		try
		{
			if (!isNotOKToReadMemory((PVOID)LoginController__GiveTime, 4)) {
				RemoveDetour(LoginController__GiveTime);
				LoginController__GiveTime = 0;
			}
			else {
				DeleteDetour(LoginController__GiveTime);
				LoginController__GiveTime = 0;
			}
		}
		catch (...)
		{
			//do nothing ita not a crash its just a exception that happens when in fact the memory is not readable
			OutputDebugString("Bad ReadPointer detected in RemoveLoginPulse, no action taken, all is good.");
		}
	}
}
void InitializeLoginPulse()
{
	if (*(DWORD*)__heqmain && !LoginController__GiveTime) {
		if (!(LoginController__GiveTime = FindPattern(*(DWORD*)__heqmain, 0x200000, lpPattern, lpMask)))
		{
			MessageBox(NULL, "MQ2 needs an update.", "Couldn't find LoginController__GiveTime", MB_SYSTEMMODAL | MB_OK);
			return;
		}
		if (LoginController__GiveTime) {
			if (*(BYTE*)LoginController__GiveTime != 0xe9) {
				EzDetourwName(LoginController__GiveTime, &CEverQuestHook::LoginController__GiveTime_Detour, &CEverQuestHook::LoginController__GiveTime_Tramp, "LoginController__GiveTime");
			}
		}
	}
}
DETOUR_TRAMPOLINE_EMPTY(void CEverQuestHook::LoginController__GiveTime_Tramp());
DETOUR_TRAMPOLINE_EMPTY(VOID CEverQuestHook::EnterZone_Trampoline(PVOID));
DETOUR_TRAMPOLINE_EMPTY(VOID CEverQuestHook::SetGameState_Trampoline(DWORD));
DETOUR_TRAMPOLINE_EMPTY(VOID CEverQuestHook::CTargetWnd__RefreshTargetBuffs_Trampoline(PBYTE));
DETOUR_TRAMPOLINE_EMPTY(VOID CEverQuestHook::CMerchantWnd__PurchasePageHandler__UpdateList_Trampoline());

void InitializeMQ2Pulse()
{
	DebugSpew("Initializing Pulse");
	if (!ghLockDelayCommand)
		ghLockDelayCommand = CreateMutex(NULL, FALSE, NULL);
	InitializeCriticalSection(&gPulseCS);
	EzDetourwName(ProcessGameEvents, Detour_ProcessGameEvents, Trampoline_ProcessGameEvents,"ProcessGameEvents");
	EzDetourwName(CEverQuest__EnterZone, &CEverQuestHook::EnterZone_Detour, &CEverQuestHook::EnterZone_Trampoline,"CEverQuest__EnterZone");
	EzDetourwName(CEverQuest__SetGameState, &CEverQuestHook::SetGameState_Detour, &CEverQuestHook::SetGameState_Trampoline,"CEverQuest__SetGameState");
	EzDetourwName(CTargetWnd__RefreshTargetBuffs, &CEverQuestHook::CTargetWnd__RefreshTargetBuffs_Detour, &CEverQuestHook::CTargetWnd__RefreshTargetBuffs_Trampoline, "CTargetWnd__RefreshTargetBuffs");
	EzDetourwName(CMerchantWnd__PurchasePageHandler__UpdateList, &CEverQuestHook::CMerchantWnd__PurchasePageHandler__UpdateList_Detour, &CEverQuestHook::CMerchantWnd__PurchasePageHandler__UpdateList_Trampoline,"CMerchantWnd__PurchasePageHandler__UpdateList");
	
	InitializeLoginPulse();

	if (HMODULE EQWhMod = GetModuleHandle("eqw.dll"))
	{
		EQW_GetDisplayWindow = (fEQW_GetDisplayWindow)GetProcAddress(EQWhMod, "EQW_GetDisplayWindow");
	}
}
void ShutdownMQ2Pulse()
{
	EnterCriticalSection(&gPulseCS);
	RemoveLoginPulse();
	RemoveDetour(CMerchantWnd__PurchasePageHandler__UpdateList);
	RemoveDetour((DWORD)CTargetWnd__RefreshTargetBuffs);
	RemoveDetour((DWORD)ProcessGameEvents);
	RemoveDetour(CEverQuest__EnterZone);
	RemoveDetour(CEverQuest__SetGameState);

	LeaveCriticalSection(&gPulseCS);
	DeleteCriticalSection(&gPulseCS);
}
#endif
