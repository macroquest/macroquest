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

namespace MQ2Prototypes
{
	typedef PCHAR(__stdcall *fEQGetStringByID)(DWORD);
#ifndef ISXEQ
	typedef HRESULT(__stdcall *fGetDeviceState)(THIS_ DWORD, LPVOID);
#endif
	typedef DWORD(__stdcall *fEQScreenItem)(DWORD, DWORD, DWORD);
	typedef DWORD(__stdcall *fEQScreenSpawn)(DWORD, DWORD);
	typedef PCHAR(__stdcall *fEQNewUIINI)(VOID);
	typedef VOID(__cdecl *fEQCommand)(PSPAWNINFO, PCHAR Buffer);
	typedef VOID(__cdecl *fMQCommand)(PSPAWNINFO, PCHAR Buffer,SIZE_T BuffLen);
	typedef VOID(__cdecl *fEQMemSpell)(DWORD, DWORD);
	typedef VOID(__cdecl *fEQLoadSpells)(PSPELLFAVORITE, DWORD);
	typedef VOID(__cdecl *fEQSelectItem)(class ItemGlobalIndex *, int Unknown);
	typedef VOID(__cdecl *fEQBuyItem)(int);
	typedef VOID(__cdecl *fEQSellItem)(int);//CMerchantWnd::PurchasePageHandler::RequestPutItem
	typedef VOID(__cdecl *fEQWriteMapfile)(PCHAR, int);//void __thiscall ZZZ::WriteMapfile(PCHAR zonename, int Layer);
	typedef BOOL(__cdecl *fEQProcGameEvts)(VOID);
	typedef FLOAT(__cdecl *fEQGetMelee)(class EQPlayer *, class EQPlayer *);
	typedef VOID(__cdecl *fMQExecuteCmd)(PCHAR Name, BOOL Down);
	typedef VOID(__cdecl fEQSaveToUIIniFile)(PCHAR Section, PCHAR Key, PCHAR Value);
	typedef DWORD(__cdecl *fMQParm)(PCHAR, PCHAR, PSPAWNINFO);
	typedef bool(__cdecl *fGetLabelFromEQ)(int, class CXStr *, bool *, unsigned long *);
#if !defined(ROF2EMU) && !defined(UFEMU)
	typedef BOOL(__cdecl *fEQToggleKeyRingItem)(DWORD RingType,PCONTENTS*itemptr, DWORD listindex);//0 is mounts, 1 is illusions, 2 is familiars
#endif
#define DoWarp                 0

	/* PLUGINS */
	typedef DWORD(__cdecl *fMQWriteChatColor)(PCHAR Line, DWORD Color, DWORD Filter);
	typedef VOID(__cdecl *fMQPulse)(VOID);
	typedef DWORD(__cdecl *fMQIncomingChat)(PCHAR Line, DWORD Color);
	typedef VOID(__cdecl *fMQInitializePlugin)(VOID);
	typedef VOID(__cdecl *fMQShutdownPlugin)(VOID);
	typedef VOID(__cdecl *fMQZoned)(VOID);
	typedef VOID(__cdecl *fMQReloadUI)(VOID);
	typedef VOID(__cdecl *fMQCleanUI)(VOID);
	typedef VOID(__cdecl *fMQDrawHUD)(VOID);
	typedef VOID(__cdecl *fMQSetGameState)(DWORD GameState);
	typedef VOID(__cdecl *fMQSpawn)(PSPAWNINFO);
	typedef VOID(__cdecl *fMQGroundItem)(PGROUNDITEM);
	typedef VOID(__cdecl *fMQBeginZone)(VOID);
	typedef VOID(__cdecl *fMQEndZone)(VOID);

	/* UTILITIES */
	typedef __int64(__cdecl *fICGetHashData)(void*,int);
	typedef void(__cdecl *fICSetHashData)(void*,int,__int64);
	typedef DWORD(__cdecl *fLoaderSetLoaded)(PCHAR profile, PCHAR stationname, PCHAR servername, PCHAR charactername, DWORD pid);
	typedef DWORD(__cdecl *fLoaderClearLoaded)(PCHAR profile, PCHAR stationname, PCHAR servername, PCHAR charactername, DWORD pid);
	typedef DWORD(__cdecl *fMQ2Unload)(DWORD pid);
	typedef DWORD(__cdecl *fClassLvl)(DWORD playerClass, DWORD playerLevel, DWORD pid);
	typedef HWND(__stdcall *fEQW_GetDisplayWindow )(VOID);
};
using namespace MQ2Prototypes;