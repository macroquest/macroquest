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

class EQItemListHook
{
public:
	DWORD EQItemList_Trampoline();
	DWORD EQItemList_Detour()
	{
		PGROUNDITEM pGroundItem;
		__asm {
			mov [pGroundItem], ecx;
			push ecx;
		};
		DWORD Ret=EQItemList_Trampoline();
		EnterCriticalSection(&csPendingGrounds);
		PMQGROUNDPENDING pPending=new MQGROUNDPENDING;
		pPending->pGroundItem=pGroundItem;
		pPending->pNext=pPendingGrounds;
		pPending->pLast=0;
		if (pPendingGrounds)
			pPendingGrounds->pLast=pPending;
		pPendingGrounds=pPending;
		LeaveCriticalSection(&csPendingGrounds);
		__asm {
			pop ecx;
		};
		return Ret;
	}

	void dEQItemList_Trampoline();
	void dEQItemList_Detour()
	{
		PGROUNDITEM pGroundItem;
		__asm {
			mov [pGroundItem], ecx;
			push ecx;
		};
		// check pending ground items
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
					LeaveCriticalSection(&csPendingGrounds);
					__asm {
						pop ecx;
					};
					dEQItemList_Trampoline();
					return;
				}
				pPending=pPending->pNext;
			}
			LeaveCriticalSection(&csPendingGrounds);
		}
		PluginsRemoveGroundItem((PGROUNDITEM)pGroundItem);
		__asm
		{
			pop ecx;
		};
		dEQItemList_Trampoline();
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

	void EQPlayer_Trampoline(class EQPlayer *,unsigned char,unsigned int,unsigned char,char *);
	void EQPlayer_Detour(class EQPlayer *a,unsigned char b,unsigned int c,unsigned char d,char * e)
	{
		PSPAWNINFO pSpawn;
		__asm {mov [pSpawn], ecx};

		EQPlayer_Trampoline(a,b,c,d,e);
		EQPlayer_ExtraDetour(pSpawn);
		//PreserveRegisters(PluginsAddSpawn((PSPAWNINFO)pSpawn));
	}

	void dEQPlayer_Trampoline(void);
	void dEQPlayer_Detour(void)
	{
		PSPAWNINFO pSpawn;
		__asm {mov [pSpawn], ecx};
		__asm {push ecx};
//		PreserveRegisters(PluginsRemoveSpawn((PSPAWNINFO)pSpawn));
		PluginsRemoveSpawn((PSPAWNINFO)pSpawn);
		__asm {pop ecx};
		dEQPlayer_Trampoline();
	}

};

DETOUR_TRAMPOLINE_EMPTY(VOID EQPlayerHook::dEQPlayer_Trampoline(VOID)); 
DETOUR_TRAMPOLINE_EMPTY(VOID EQPlayerHook::EQPlayer_Trampoline(class EQPlayer *,unsigned char,unsigned int,unsigned char,char *)); 

VOID InitializeMQ2Spawns()
{
	DebugSpew("Initializing Spawn-related Hooks");
	EasyClassDetour(EQPlayer__EQPlayer,EQPlayerHook,EQPlayer_Detour,VOID,(class EQPlayer *,unsigned char,unsigned int,unsigned char,char *),EQPlayer_Trampoline);
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
