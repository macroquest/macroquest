/*****************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2004 Lax

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


PMQGROUNDPENDING pPendingGrounds=0;
CRITICAL_SECTION csPendingGrounds;
BOOL ProcessPending=false;

void AddGroundItem()
{
	PGROUNDITEM pGroundItem=(PGROUNDITEM)pItemList;
	EnterCriticalSection(&csPendingGrounds);
	PMQGROUNDPENDING pPending=new MQGROUNDPENDING;
	pPending->pGroundItem=pGroundItem;
	pPending->pNext=pPendingGrounds;
	pPending->pLast=0;
	if (pPendingGrounds)
		pPendingGrounds->pLast=pPending;
	pPendingGrounds=pPending;
	LeaveCriticalSection(&csPendingGrounds);
}

void RemoveGroundItem(PGROUNDITEM pGroundItem)
{
	if (pPendingGrounds)
	{
		EnterCriticalSection(&csPendingGrounds);
		PMQGROUNDPENDING pPending=pPendingGrounds;
		while(pPending)
		{
			if (pGroundItem==pPending->pGroundItem)
			{
				if (pPending->pNext)
					pPending->pNext->pLast=pPending->pLast;
				if (pPending->pLast)
					pPending->pLast->pNext=pPending->pNext;
				else
					pPendingGrounds=pPending->pNext;
				delete pPending;
				break;
			}
			pPending=pPending->pNext;
		}
		LeaveCriticalSection(&csPendingGrounds);
	}
	PluginsRemoveGroundItem((PGROUNDITEM)pGroundItem);
}

class EQItemListHook
{
public:
	DWORD EQItemList_Trampoline();
	DWORD EQItemList_Detour()
	{
		__asm {
			call EQItemList_Trampoline;
			push eax;
			push ebx;
			push ecx;
			push edx;
			push esi;
			push edi;
			call AddGroundItem;
			pop edi;
			pop esi;
			pop edx;
			pop ecx;
			pop ebx;
			pop eax;
		};
	}

	void dEQItemList_Trampoline();
	void dEQItemList_Detour()
	{
		__asm {
			push ecx;
			push ecx;
			call RemoveGroundItem;
			pop ecx;
			pop ecx;
			call dEQItemList_Trampoline;
		};
	}
};

DETOUR_TRAMPOLINE_EMPTY(DWORD EQItemListHook::EQItemList_Trampoline(VOID)); 
DETOUR_TRAMPOLINE_EMPTY(VOID EQItemListHook::dEQItemList_Trampoline(VOID)); 

class EQPlayerHook
{
public:

	
	void EQPlayer_ExtraDetour(PSPAWNINFO pSpawn)
	{// note: we need to keep the original registers.
		__asm {push eax};
		__asm {push ebx};
		__asm {push ecx};
		__asm {push edx};
		__asm {push esi};
		__asm {push edi};
		PluginsAddSpawn((PSPAWNINFO)pSpawn);
		__asm {pop edi};
		__asm {pop esi};
		__asm {pop edx};
		__asm {pop ecx};
		__asm {pop ebx};
		__asm {pop eax};
	}
	/**/

	void EQPlayer_Trampoline(DWORD,DWORD,DWORD,DWORD,DWORD);
	void EQPlayer_Detour(DWORD a,DWORD b,DWORD c,DWORD d,DWORD e)
	{
		PSPAWNINFO pSpawn;
		__asm {mov [pSpawn], ecx};

		EQPlayer_Trampoline(a,b,c,d,e);
		EQPlayer_ExtraDetour(pSpawn);
		/**/
	}

	void dEQPlayer_Trampoline(void);
	void dEQPlayer_Detour(void)
	{
		__asm {
			push ecx;
			push ecx;
			call PluginsRemoveSpawn;
			pop ecx;
			pop ecx;
			call dEQPlayer_Trampoline;
		};
/*
		PSPAWNINFO pSpawn;
		__asm {mov [pSpawn], ecx};
		__asm {push ecx};
//		PreserveRegisters(PluginsRemoveSpawn((PSPAWNINFO)pSpawn));
		PluginsRemoveSpawn((PSPAWNINFO)pSpawn);
		__asm {pop ecx};
		dEQPlayer_Trampoline();
/**/
	}

};

DETOUR_TRAMPOLINE_EMPTY(VOID EQPlayerHook::dEQPlayer_Trampoline(VOID)); 
DETOUR_TRAMPOLINE_EMPTY(VOID EQPlayerHook::EQPlayer_Trampoline(DWORD,DWORD,DWORD,DWORD,DWORD)); 

VOID InitializeMQ2Spawns()
{
	DebugSpew("Initializing Spawn-related Hooks");
	EasyClassDetour(EQPlayer__EQPlayer,EQPlayerHook,EQPlayer_Detour,VOID,(DWORD,DWORD,DWORD,DWORD,DWORD),EQPlayer_Trampoline);
	EasyClassDetour(EQPlayer__dEQPlayer,EQPlayerHook,dEQPlayer_Detour,VOID,(VOID),dEQPlayer_Trampoline);

	EasyClassDetour(EQItemList__EQItemList,EQItemListHook,EQItemList_Detour,DWORD,(VOID),EQItemList_Trampoline);
	EasyClassDetour(EQItemList__dEQItemList,EQItemListHook,dEQItemList_Detour,VOID,(VOID),dEQItemList_Trampoline);

	InitializeCriticalSection(&csPendingGrounds);
	ProcessPending=true;
}

VOID ShutdownMQ2Spawns()
{
	DebugSpew("Shutting Down Spawn-related Hooks");
	RemoveDetour(EQPlayer__EQPlayer);
	RemoveDetour(EQPlayer__dEQPlayer);
	RemoveDetour(EQItemList__EQItemList);
	RemoveDetour(EQItemList__dEQItemList);
	ProcessPending=false;
	EnterCriticalSection(&csPendingGrounds);
	DeleteCriticalSection(&csPendingGrounds);
	while(pPendingGrounds)
	{
		PMQGROUNDPENDING pNext=pPendingGrounds->pNext;
		delete pPendingGrounds;
		pPendingGrounds=pNext;
	}
}

VOID ProcessPendingGroundItems()
{
	if (ProcessPending && pPendingGrounds)
	{
		EnterCriticalSection(&csPendingGrounds);
		while(pPendingGrounds)
		{
			PMQGROUNDPENDING pNext=pPendingGrounds->pNext;
			PluginsAddGroundItem(pPendingGrounds->pGroundItem);
			delete pPendingGrounds;
			pPendingGrounds=pNext;
		}
		LeaveCriticalSection(&csPendingGrounds);
	}
}
