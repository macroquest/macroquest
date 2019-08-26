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

#pragma once

namespace MQ2Prototypes {

using fEQGetStringByID = char* (__stdcall*)(DWORD);
using fEQScreenItem = DWORD (__stdcall*)(DWORD, DWORD, DWORD);

typedef DWORD(__stdcall *fEQScreenSpawn)(DWORD, DWORD);
typedef char*(__stdcall *fEQNewUIINI)();
typedef void(__cdecl* fEQCommand)(SPAWNINFO*, char* Buffer);
typedef void(__cdecl* fEQCommand)(SPAWNINFO*, char* Buffer);
typedef void(__cdecl *fMQCommand)(SPAWNINFO*, char* Buffer,size_t BuffLen);
typedef void(__cdecl *fEQMemSpell)(DWORD, DWORD);
typedef void(__cdecl *fEQLoadSpells)(PSPELLFAVORITE, DWORD);
typedef void(__cdecl *fEQSelectItem)(class ItemGlobalIndex *, int Unknown);
typedef void(__cdecl *fEQBuyItem)(int);
typedef void(__cdecl *fEQSellItem)(int);//CMerchantWnd::PurchasePageHandler::RequestPutItem
typedef void(__cdecl *fEQWriteMapfile)(char*, int);//void __thiscall ZZZ::WriteMapfile(char* zonename, int Layer);
typedef BOOL(__cdecl *fEQProcGameEvts)();
typedef float(__cdecl *fEQGetMelee)(PlayerClient *, PlayerClient*);
typedef void(__cdecl *fMQExecuteCmd)(char* Name, BOOL Down);
typedef void(__cdecl fEQSaveToUIIniFile)(char* Section, char* Key, char* Value);
typedef DWORD(__cdecl *fMQParm)(char*, char*, PSPAWNINFO);
typedef bool(__cdecl *fGetLabelFromEQ)(int, class CXStr *, bool *, unsigned long *);
typedef BOOL(__cdecl *fEQToggleKeyRingItem)(DWORD RingType, CONTENTS** itemptr, DWORD listindex);//0 is mounts, 1 is illusions, 2 is familiars

/* PLUGINS */
typedef DWORD(__cdecl *fMQWriteChatColor)(const char* Line, DWORD Color, DWORD Filter);
typedef void(__cdecl *fMQPulse)();
typedef bool(__cdecl *fMQIncomingChat)(const char* Line, DWORD Color);
typedef void(__cdecl *fMQInitializePlugin)();
typedef void(__cdecl *fMQShutdownPlugin)();
typedef void(__cdecl *fMQZoned)();
typedef void(__cdecl *fMQReloadUI)();
typedef void(__cdecl *fMQCleanUI)();
typedef void(__cdecl *fMQDrawHUD)();
typedef void(__cdecl *fMQSetGameState)(DWORD GameState);
typedef void(__cdecl *fMQSpawn)(PSPAWNINFO);
typedef void(__cdecl *fMQGroundItem)(PGROUNDITEM);
typedef void(__cdecl *fMQBeginZone)();
typedef void(__cdecl *fMQEndZone)();

/* UTILITIES */
typedef int64_t(__cdecl *fICGetHashData)(void*,int);
typedef void(__cdecl *fICSetHashData)(void*,int,int64_t);
typedef DWORD(__cdecl *fLoaderSetLoaded)(char* profile, char* stationname, char* servername, char* charactername, DWORD pid);
typedef DWORD(__cdecl *fLoaderClearLoaded)(char* profile, char* stationname, char* servername, char* charactername, DWORD pid);
typedef DWORD(__cdecl *fMQ2Unload)(DWORD pid);
typedef DWORD(__cdecl *fClassLvl)(DWORD playerClass, DWORD playerLevel, DWORD pid);
typedef HWND(__stdcall *fEQW_GetDisplayWindow )();

} // namespace MQ2Prototypes

using namespace MQ2Prototypes;