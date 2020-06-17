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

#ifndef ISXEQ_LEGACY


PMQGROUNDPENDING pPendingGrounds=0;
CRITICAL_SECTION csPendingGrounds;
BOOL ProcessPending=false;

void AddGroundItem()
{
	if (PGROUNDITEM pGroundItem = *(PGROUNDITEM*)pItemList) {
		EnterCriticalSection(&csPendingGrounds);
		PMQGROUNDPENDING pPending = new MQGROUNDPENDING;
		pPending->pGroundItem = pGroundItem;
		pPending->pNext = pPendingGrounds;
		pPending->pLast = 0;
		if (pPendingGrounds)
			pPendingGrounds->pLast = pPending;
		pPendingGrounds = pPending;
		LeaveCriticalSection(&csPendingGrounds);
	}
}

void RemoveGroundItem(PGROUNDITEM pGroundItem)
{
    if (pPendingGrounds)
    {
        EnterCriticalSection(&csPendingGrounds);
        PMQGROUNDPENDING pPending=pPendingGrounds;
        while(pPending)
        {
            if (pGroundItem == pPending->pGroundItem)
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

class MyEQGroundItemListManager
{
public:
	PGROUNDITEM pGItem;
    void FreeItemList_Trampoline();
    void FreeItemList_Detour()
    {
        PGROUNDITEM pItem = *(PGROUNDITEM*)pItemList;

        while(pItem)
        {
            RemoveGroundItem(pItem);

            pItem = pItem->pNext;
        }
        
        FreeItemList_Trampoline();
    }

	//if this IS NOT a PGROUNDITEM you have the wrong offset... -eqmule 2016 Apr 13
    void Add_Trampoline(PGROUNDITEM);
    void Add_Detour(PGROUNDITEM pItem)
    {
		if (pGItem) {
			pGItem->pPrev = pItem;
			pItem->pNext = pGItem;
		}
		pGItem = pItem;
		//if you drop something on the ground and this doesnt get called... you have the wrong offset -eqmule 2016 Apr 13
		//dont call the tramp we just do the exact same thing the tramp does above...
		//if we call the tramp we crash cause reasons... -eqmule
        //Add_Trampoline(pItem);
        AddGroundItem();
    }

    void DeleteItem_Trampoline(PGROUNDITEM);
    void DeleteItem_Detour(PGROUNDITEM pItem)
    {
        RemoveGroundItem(pItem);
        return DeleteItem_Trampoline(pItem);
    }
};
DETOUR_TRAMPOLINE_EMPTY(void MyEQGroundItemListManager::FreeItemList_Trampoline(VOID)); 
DETOUR_TRAMPOLINE_EMPTY(void MyEQGroundItemListManager::Add_Trampoline(PGROUNDITEM));
DETOUR_TRAMPOLINE_EMPTY(void MyEQGroundItemListManager::DeleteItem_Trampoline(PGROUNDITEM));

VOID SetNameSpriteTint(PSPAWNINFO pSpawn);

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
        PluginsAddSpawn(pSpawn);
        __asm {pop edi};
        __asm {pop esi};
        __asm {pop edx};
        __asm {pop ecx};
        __asm {pop ebx};
        __asm {pop eax};
    }
    /**/

    void EQPlayer_Trampoline(void *,int,int,int,char *,char *,char *);
    void EQPlayer_Detour(void* pNetPlayer,int Sex,int Race,int Class,char *PlayerName,char *GroupName, char *ReplaceName)
    {
        PSPAWNINFO pSpawn2 = (PSPAWNINFO)this;
        PSPAWNINFO pSpawn = (PSPAWNINFO)this;
        __asm {mov [pSpawn], ecx};

        EQPlayer_Trampoline(pNetPlayer,Sex,Race,Class,PlayerName,GroupName,ReplaceName);
        EQPlayer_ExtraDetour(pSpawn);
        /**/
		Sleep(0);
    }

    void dEQPlayer_Trampoline(void);
    void dEQPlayer_Detour(void)
    {
        void (EQPlayerHook::*tmp)(void) = &EQPlayerHook::dEQPlayer_Trampoline; 
        __asm {
            push ecx;
            push ecx;
            call PluginsRemoveSpawn;
            pop ecx;
            pop ecx;
            call [tmp];
        };
    }

    int SetNameSpriteState_Trampoline(bool Show);
    int SetNameSpriteState_Detour(bool Show)
    {
        if (!gAnonymize && (gGameState!=GAMESTATE_INGAME || !Show || !gMQCaptions))
            return SetNameSpriteState_Trampoline(Show);
        return 1;
    }

    bool SetNameSpriteTint_Trampoline(void);
    bool SetNameSpriteTint_Detour(void)
    {
        if (!gAnonymize && (gGameState!=GAMESTATE_INGAME || !gMQCaptions))
            return SetNameSpriteTint_Trampoline();
        return 1;
    }

    bool EQPlayerHook::IsTargetable(void);

};
FUNCTION_AT_ADDRESS(bool EQPlayerHook::IsTargetable(void), EQPlayer__IsTargetable);

class CActorEx
{
public:
    bool CanSetName(DWORD);
    void SetNameColor(DWORD &Color);
    void CActorEx::ChangeBoneStringSprite(int, int, char *);
};

FUNCTION_AT_VIRTUAL_ADDRESS(bool CActorEx::CanSetName(DWORD), csnOffset);
FUNCTION_AT_VIRTUAL_ADDRESS(void CActorEx::SetNameColor(DWORD &Color), sncOffset);
FUNCTION_AT_VIRTUAL_ADDRESS(void CActorEx::ChangeBoneStringSprite(int, int, char *), cbssOffset);
#endif

typedef struct _CAPTIONCOLOR {
    PCHAR szName;
    PCHAR szDescription;
    BOOL Enabled;
    BOOL ToggleOnly;
    DWORD Color;
} CAPTIONCOLOR, PCAPTIONCOLOR;

#define CC_PC               0
#define CC_PCConColor       1
#define CC_PCPVPTeamColor   2
#define CC_PCRaidColor      3
#define CC_PCClassColor     4
#define CC_PCGroupColor     5
#define CC_PCTrader         6
#define CC_NPC              7
#define CC_NPCConColor      8
#define CC_NPCClassColor    9
#define CC_NPCMerchant      10
#define CC_NPCBanker        11
#define CC_NPCAssist        12 
#define CC_NPCMark          13 
#define CC_PetNPC           14
#define CC_PetPC            15
#define CC_PetConColor      16
#define CC_PetClassColor    17
#define CC_Corpse           18
#define CC_CorpseClassColor 19


CAPTIONCOLOR CaptionColors[]=
{
    {
/*name*/"PC",
/*desc*/"Default color for PCs",
/* on */0,
/*togl*/0,
/*clr */0x00FF00FF,
    },
    {
/*name*/"PCCon",
/*desc*/"PCs by con color",
/* on */0,
/*togl*/1,
/*clr */0,
    },
    {
/*name*/"PCPVPTeam",
/*desc*/"PCs by PVP team color",
/* on */0,
/*togl*/1,
/*clr */0,
    },
    {
/*name*/"PCRaid",
/*desc*/"Raid members",
/* on */0,
/*togl*/0,
/*clr */0x0000FF7F,
    },
    {
/*name*/"PCClass",
/*desc*/"PCs by class color(raid settings)",
/* on */0,
/*togl*/1,
/*clr */0,
    },
    {
/*name*/"PCGroup",
/*desc*/"Group members",
/* on */0,
/*togl*/0,
/*clr */0x00FFFF00,
    },
    {
/*name*/"PCTrader",
/*desc*/"Traders",
/* on */1,
/*togl*/0,
/*clr */0x00FF7F00,
    },
    {
/*name*/"NPC",
/*desc*/"NPC default color",
/* on */0,
/*togl*/0,
/*clr */0x00FF0000,
    },
    {
/*name*/"NPCCon",
/*desc*/"NPCs by con color",
/* on */1,
/*togl*/1,
/*clr */0,
    },
    {
/*name*/"NPCClass",
/*desc*/"NPCs by class color (raid settings)",
/* on */0,
/*togl*/1,
/*clr */0,
    },
    {
/*name*/"NPCMerchant",
/*desc*/"NPC Merchants",
/* on */1,
/*togl*/0,
/*clr */0x00FF7F00,
    },
    {
/*name*/"NPCBanker",
/*desc*/"NPC Bankers",
/* on */1,
/*togl*/0,
/*clr */0x00C800FF,
    },
    {
/*name*/"NPCAssist",
/*desc*/"NPCs from main assist",
/* on */1,
/*togl*/0,
/*clr */0x00FFFF00,
    },
    {
/*name*/"NPCMark",
/*desc*/"Marked NPCs",
/* on */1,
/*togl*/0,
/*clr */0x00FFFF00,
    },
    {
/*name*/"PetNPC",
/*desc*/"Pet with NPC owner",
/* on */0,
/*togl*/0,
/*clr */0x00FF0000,
    },
    {
/*name*/"PetPC",
/*desc*/"Pet with PC owner",
/* on */0,
/*togl*/0,
/*clr */0x00FFFF00,
    },
    {
/*name*/"PetClass",
/*desc*/"Pet by class color (raid settings)",
/* on */0,
/*togl*/0,
/*clr */0x00FF0000,
    },
    {
/*name*/"Corpse",
/*desc*/"Corpses",
/* on */0,
/*togl*/0,
/*clr */0x00FF0000,
    },
    {
/*name*/"CorpseClass",
/*desc*/"Corpse by class color (raid settings)",
/* on */0,
/*togl*/0,
/*clr */0x00FF0000,
    },
    {
/*name*/"",
/*desc*/"",
/* on */0,
/*togl*/0,
/*clr */0,
    },
};

#ifndef ISXEQ_LEGACY
VOID SetNameSpriteTint(PSPAWNINFO pSpawn)
{
    if (!gMQCaptions)
		return;
    //DebugSpew("SetNameSpriteTint(%s)",pSpawn->Name);
    DWORD NewColor;
    switch(GetSpawnType(pSpawn))
    {
    case PC:
        /*
        #define CC_PC                0
        #define CC_PCConColor        1
        #define CC_PCPVPTeamColor    2
        #define CC_PCRaidColor       3
        #define CC_PCClassColor      4
        #define CC_PCGroupColor      5
        #define CC_PCTrader          6
        /**/
        if (pSpawn->Trader && CaptionColors[CC_PCTrader].Enabled)
            NewColor=CaptionColors[CC_PCTrader].Color;
        else if (CaptionColors[CC_PCGroupColor].Enabled && IsGroupMember(pSpawn))
            NewColor=CaptionColors[CC_PCGroupColor].Color;
        else if (CaptionColors[CC_PCClassColor].Enabled)
            NewColor=((PEQRAIDWINDOW)pRaidWnd)->ClassColors[ClassInfo[pSpawn->mActorClient.Class].RaidColorOrder];
        else if (CaptionColors[CC_PCRaidColor].Enabled && IsRaidMember(pSpawn)!=-1)
            NewColor=CaptionColors[CC_PCRaidColor].Color;
        else if (CaptionColors[CC_PCPVPTeamColor].Enabled)
        {
            // TODO
        }
        else if (CaptionColors[CC_PCConColor].Enabled)
            NewColor=ConColorToARGB(ConColor(pSpawn));
        else if (CaptionColors[CC_PC].Enabled)
            NewColor=CaptionColors[CC_PC].Color;
        else
        {
            ((EQPlayerHook*)pSpawn)->SetNameSpriteTint_Trampoline();
            return;
        }
        break;
    case NPC:
        /*
        #define CC_NPC                7
        #define CC_NPCConColor        8
        #define CC_NPCClassColor      9
        #define CC_NPCMerchant        10
        #define CC_NPCBanker          11
        #define CC_NPCAssist          12 
        #define CC_NPCMark            13 
        /**/
        if (CaptionColors[CC_NPCMark].Enabled && IsMarkedNPC(pSpawn))
            NewColor=CaptionColors[CC_NPCMark].Color;
        if (CaptionColors[CC_NPCAssist].Enabled && IsAssistNPC(pSpawn))
            NewColor=CaptionColors[CC_NPCAssist].Color;
        else if (CaptionColors[CC_NPCBanker].Enabled && pSpawn->mActorClient.Class==40)
            NewColor=CaptionColors[CC_NPCBanker].Color;
        else if (CaptionColors[CC_NPCMerchant].Enabled && (pSpawn->mActorClient.Class==41 || pSpawn->mActorClient.Class==61))
            NewColor=CaptionColors[CC_NPCMerchant].Color;
        else if (CaptionColors[CC_NPCClassColor].Enabled && pSpawn->mActorClient.Class<0x10)
            NewColor=((PEQRAIDWINDOW)pRaidWnd)->ClassColors[ClassInfo[pSpawn->mActorClient.Class].RaidColorOrder];
        else if (CaptionColors[CC_NPCConColor].Enabled)
            NewColor=ConColorToARGB(ConColor(pSpawn));
        else if (CaptionColors[CC_NPC].Enabled)
            NewColor=CaptionColors[CC_NPC].Color;
        else
        {
            ((EQPlayerHook*)pSpawn)->SetNameSpriteTint_Trampoline();
            return;
        }
        break;
    case CORPSE:
        if (CaptionColors[CC_CorpseClassColor].Enabled)
            NewColor=((PEQRAIDWINDOW)pRaidWnd)->ClassColors[ClassInfo[pSpawn->mActorClient.Class].RaidColorOrder];
        else if (CaptionColors[CC_Corpse].Enabled)
            NewColor=CaptionColors[CC_Corpse].Color;
        else
        {
            ((EQPlayerHook*)pSpawn)->SetNameSpriteTint_Trampoline();
            return;
        }
        break;
    case PET:
        if (CaptionColors[CC_PetClassColor].Enabled)
            NewColor=((PEQRAIDWINDOW)pRaidWnd)->ClassColors[ClassInfo[pSpawn->mActorClient.Class].RaidColorOrder];
        else if (CaptionColors[CC_PetConColor].Enabled)
            NewColor=ConColorToARGB(ConColor(pSpawn));
        else if (CaptionColors[CC_PetNPC].Enabled && ((PSPAWNINFO)GetSpawnByID(pSpawn->MasterID))->Type==SPAWN_NPC)
            NewColor=CaptionColors[CC_PetNPC].Color;
        else if (CaptionColors[CC_PetPC].Enabled && ((PSPAWNINFO)GetSpawnByID(pSpawn->MasterID))->Type==SPAWN_PLAYER)
            NewColor=CaptionColors[CC_PetPC].Color;
        else
        {
            ((EQPlayerHook*)pSpawn)->SetNameSpriteTint_Trampoline();
            return;
        }
        break;
    case OBJECT:
    case MERCENARY:
    case UNTARGETABLE:
        ((EQPlayerHook*)pSpawn)->SetNameSpriteTint_Trampoline();
        return;
    }
	if(pSpawn->mActorClient.pcactorex)
		DebugTry(((CActorEx *)pSpawn->mActorClient.pcactorex)->SetNameColor(NewColor));
	else {
#ifdef _DEBUG
		WriteChatf("We got an Empty pSpawn->pcactorex at %x class = 0x%x ",pSpawn,pSpawn->mActorClient.Class);
#endif
	}
}
BOOL SetCaption(PSPAWNINFO pSpawn, char *CaptionString,eSpawnType type)
{
    CHAR NewCaption[MAX_STRING]={0};
    if (CaptionString[0] || gAnonymize) {
        if (PCHARINFO pChar = GetCharInfo()) {
            strcpy_s(NewCaption, CaptionString);
            pNamingSpawn = pSpawn;                                      
            if (gAnonymize)
            {
                CHAR szType[64] = { 0 };
                bool oktoanon = false;
                switch (type) {
                    case MERCENARY:
                        oktoanon = true;
                        strcpy_s(szType, "Mercenary");
                        break;
                   case NPC:
					    ParseMacroParameter(pChar->pSpawn, NewCaption);
						break;
                   case PC:
                        oktoanon = true;
                        strcpy_s(szType, "Player");
                        break;
                    case PET:
						if (pSpawn->MasterID) {
							PSPAWNINFO petMaster = (PSPAWNINFO)GetSpawnByID(pSpawn->MasterID);
							if (petMaster && petMaster->Type == SPAWN_PLAYER) {
								oktoanon = true;
								strcpy_s(szType, "PET");
							}
							else {
								ParseMacroParameter(pChar->pSpawn, NewCaption);
							}
						}
                        break;
					case CORPSE:
						if (pSpawn->Deity) {
							oktoanon = true;
							strcpy_s(szType, "CORPSE");
						}
						else {
							ParseMacroParameter(pChar->pSpawn, NewCaption);
						}
						break;
                };
                if (oktoanon) {
                    if (gszAnonCaption[0] == '\0') {
                        char *therace = pEverQuest->GetRaceDesc(pSpawn->mActorClient.Race);
                        char *theclass = pEverQuest->GetClassDesc(pSpawn->mActorClient.Class);
                        sprintf_s(NewCaption, "[%d] %s %s %s", pSpawn->Level, therace, theclass, szType);
                    }
                    else {
                        strcpy_s(NewCaption, gszAnonCaption);
                        ParseMacroParameter(pChar->pSpawn, NewCaption);
                    }
                }
            }
            else {
                ParseMacroParameter(pChar->pSpawn, NewCaption);
            }
            pNamingSpawn = 0;
        }
        ((EQPlayer*)pSpawn)->ChangeBoneStringSprite(0, NewCaption);
        return 1;
    }
    return 0;
}
BOOL SetNameSpriteState(PSPAWNINFO pSpawn, bool Show)
{
    //DebugSpew("SetNameSpriteState(%s) --race %d body %d)",pSpawn->Name,pSpawn->Race,GetBodyType(pSpawn));
    if (!Show)
    {
        ((EQPlayerHook*)pSpawn)->SetNameSpriteState_Trampoline(Show);
    }
    if (!gMQCaptions && !gAnonymize)
    {
        //DebugSpew("Returning default from SetNameSpriteState");
        return ((EQPlayerHook*)pSpawn)->SetNameSpriteState_Trampoline(Show);
    }
    if (!pSpawn->mActorClient.pcactorex || !((CActorEx*)pSpawn->mActorClient.pcactorex)->CanSetName(0))
    {
        //DebugSpew("CanSetName==0 - %s .. race %d body %d",pSpawn->Name,pSpawn->Race,GetBodyType(pSpawn));
        return 1;
    };

	switch (GetSpawnType(pSpawn))
	{
	case MERCENARY:
		if (gAnonymize) {
			if (SetCaption(pSpawn, "", MERCENARY))
				return 1;
		}
        break;
    case NPC:
		if (SetCaption(pSpawn, gszSpawnNPCName,NPC))
			return 1;
        break;
    case PC:
        if (!gPCNames && pSpawn!=(PSPAWNINFO)pTarget) 
            return 0;
		if (SetCaption(pSpawn, gszSpawnPlayerName[gShowNames],PC))
			return 1;
        break;
    case CORPSE:
		if (SetCaption(pSpawn, gszSpawnCorpseName,CORPSE))
			return 1;
        break;
    case CHEST:
    case UNTARGETABLE:
    case TRAP:
    case TIMER:
    case TRIGGER:// trigger names make it crash!
        return 0;
    case MOUNT://mount names make it crash!
        return 0;
    case PET:
		if (SetCaption(pSpawn, gszSpawnPetName,PET))
			return 1;
        break;
    }
    //DebugSpew("Returning default from SetNameSpriteState");
    return ((EQPlayerHook*)pSpawn)->SetNameSpriteState_Trampoline(Show);
//#undef SetCaption
}

VOID UpdateSpawnCaptions()
{
    //DebugSpew("UpdateSpawnCaptions()");
    DWORD N;
    DWORD Count=0;
	for (N = 0; N < 120; N++)
	{
		if (PSPAWNINFO pSpawn = (PSPAWNINFO)EQP_DistArray[N].VarPtr.Ptr)
			if (pSpawn != (PSPAWNINFO)pTarget)
                if (gAnonymize || (EQP_DistArray[N].Value.Float<=80.0f && gMQCaptions)) {
                    if (SetNameSpriteState(pSpawn,true))
                    {
                        SetNameSpriteTint(pSpawn);
                        Count++;
                        if (Count>=gMaxSpawnCaptions)
                        {
                            return;
                        }
                    }
                }
                else
                {
                    return;
                }
    }
}

DETOUR_TRAMPOLINE_EMPTY(bool EQPlayerHook::SetNameSpriteTint_Trampoline(void));
DETOUR_TRAMPOLINE_EMPTY(int EQPlayerHook::SetNameSpriteState_Trampoline(bool Show));
DETOUR_TRAMPOLINE_EMPTY(VOID EQPlayerHook::dEQPlayer_Trampoline(VOID)); 
DETOUR_TRAMPOLINE_EMPTY(VOID EQPlayerHook::EQPlayer_Trampoline(void *,int,int,int,char *,char *,char *)); 

VOID InitializeMQ2Spawns()
{
    InitializeCriticalSection(&csPendingGrounds);
    DebugSpew("Initializing Spawn-related Hooks");
    bmUpdateSpawnSort=AddMQ2Benchmark("UpdateSpawnSort");
    bmUpdateSpawnCaptions=AddMQ2Benchmark("UpdateSpawnCaptions");
#ifndef GateBind
    ProcessGameEvents=0;
#endif
    EzDetourwName(EQPlayer__EQPlayer,&EQPlayerHook::EQPlayer_Detour,&EQPlayerHook::EQPlayer_Trampoline,"EQPlayer__EQPlayer");
    EzDetourwName(EQPlayer__dEQPlayer,&EQPlayerHook::dEQPlayer_Detour,&EQPlayerHook::dEQPlayer_Trampoline,"EQPlayer__dEQPlayer");
    EzDetourwName(EQPlayer__SetNameSpriteState,&EQPlayerHook::SetNameSpriteState_Detour,&EQPlayerHook::SetNameSpriteState_Trampoline,"EQPlayer__SetNameSpriteState");
    EzDetourwName(EQPlayer__SetNameSpriteTint,&EQPlayerHook::SetNameSpriteTint_Detour,&EQPlayerHook::SetNameSpriteTint_Trampoline,"EQPlayer__SetNameSpriteTint");
    EzDetourwName(EQItemList__FreeItemList, &MyEQGroundItemListManager::FreeItemList_Detour, &MyEQGroundItemListManager::FreeItemList_Trampoline,"EQItemList__FreeItemList");
    EzDetourwName(EQItemList__add_item, &MyEQGroundItemListManager::Add_Detour, &MyEQGroundItemListManager::Add_Trampoline,"EQGroundItemListManager__add");
    EzDetourwName(EQItemList__delete_item, &MyEQGroundItemListManager::DeleteItem_Detour, &MyEQGroundItemListManager::DeleteItem_Trampoline,"EQItemList__delete_item");

    ProcessPending=true;
    ZeroMemory(&EQP_DistArray,sizeof(EQP_DistArray));
    gSpawnCount=0;

    CHAR Temp[MAX_STRING]={0};
    CHAR Name[MAX_STRING]={0};
    // load custom spawn caption colors
    DWORD N;
    for (N = 0 ; CaptionColors[N].szName[0] ; N++)
    {
        if (GetPrivateProfileString("Caption Colors",CaptionColors[N].szName,"",Temp,MAX_STRING,gszINIFilename))
        {
            if (!_stricmp(Temp,"on") || !_stricmp(Temp,"1"))
                CaptionColors[N].Enabled=1;
            else
                CaptionColors[N].Enabled=0;
        }
        sprintf_s(Name,"%s-Color",CaptionColors[N].szName);
        if (GetPrivateProfileString("Caption Colors",Name,"",Temp,MAX_STRING,gszINIFilename))
        {
            if(!sscanf_s(Temp,"%x",&CaptionColors[N].Color)) {
				//should handle this i guess
				return;
			}
        }
    }
    // write custom spawn caption colors
    for (N = 0 ; CaptionColors[N].szName[0] ; N++)
    {
        WritePrivateProfileString("Caption Colors",CaptionColors[N].szName,CaptionColors[N].Enabled?"ON":"OFF",gszINIFilename);
        if (!CaptionColors[N].ToggleOnly)
        {
            sprintf_s(Temp,"%x",CaptionColors[N].Color);
            sprintf_s(Name,"%s-Color",CaptionColors[N].szName);
            WritePrivateProfileString("Caption Colors",Name,Temp,gszINIFilename);
        }
    }
}

VOID ShutdownMQ2Spawns()
{
    DebugSpew("Shutting Down Spawn-related Hooks");
    RemoveDetour(EQPlayer__EQPlayer);
    RemoveDetour(EQPlayer__dEQPlayer);
    //RemoveDetour(EQPlayer__SetNameSpriteState);
    RemoveDetour(EQPlayer__SetNameSpriteTint);
    RemoveDetour(EQItemList__FreeItemList);
    RemoveDetour(EQItemList__add_item);
    RemoveDetour(EQItemList__delete_item);

    ProcessPending=false;
    EnterCriticalSection(&csPendingGrounds);
    while(pPendingGrounds)
    {
        PMQGROUNDPENDING pNext=pPendingGrounds->pNext;
        delete pPendingGrounds;
        pPendingGrounds=pNext;
    }
	LeaveCriticalSection(&csPendingGrounds);
    DeleteCriticalSection(&csPendingGrounds);
    ZeroMemory(EQP_DistArray,sizeof(EQP_DistArray));
    gSpawnCount=0;
    RemoveMQ2Benchmark(bmUpdateSpawnSort);
    RemoveMQ2Benchmark(bmUpdateSpawnCaptions);
}

VOID ProcessPendingGroundItems()
{
	if (gGameState == GAMESTATE_INGAME) {//no point in checking this unless in game
		if (ProcessPending && pPendingGrounds)
		{
			EnterCriticalSection(&csPendingGrounds);
			while (pPendingGrounds)
			{
				PMQGROUNDPENDING pNext = pPendingGrounds->pNext;
				PluginsAddGroundItem(pPendingGrounds->pGroundItem);
				delete pPendingGrounds;
				pPendingGrounds = pNext;
			}
			LeaveCriticalSection(&csPendingGrounds);
		}
	}
}

VOID UpdateMQ2SpawnSort()
{
	if (gGameState == GAMESTATE_INGAME) {//no point in doing any of this stuff unless we are in game
		EnterMQ2Benchmark(bmUpdateSpawnSort);
		ZeroMemory(EQP_DistArray, sizeof(EQP_DistArray));
		gSpawnCount = 0;
		PSPAWNINFO pSpawn = (PSPAWNINFO)pSpawnList;
		while (pSpawn)
		{
			if (gSpawnCount < 4000) {
				EQP_DistArray[gSpawnCount].VarPtr.Ptr = pSpawn;
				EQP_DistArray[gSpawnCount].Value.Float = GetDistance(pSpawn->X, pSpawn->Y);
				gSpawnCount++;
			}
			else {
				//whups... well we might as well exit out of the while now...
				//this CAN happen in a zone with lots of mobs players and corpses
				break;
			}
			pSpawn = pSpawn->pNext;
		}
		std::sort(EQP_DistArray, EQP_DistArray + gSpawnCount, MQRankFloatCompare);
		ExitMQ2Benchmark(bmUpdateSpawnSort);
		static unsigned long nCaptions = 100;
		static unsigned long LastTarget = 0;
		++nCaptions;
		if (LastTarget)
		{
			if (PSPAWNINFO pSpawn = (PSPAWNINFO)GetSpawnByID(LastTarget))
			{
				if (pSpawn != (PSPAWNINFO)pTarget)
				{
					SetNameSpriteState(pSpawn, false);
				}
			}
			LastTarget = 0;
		}
		if (nCaptions > 20)
		{
			nCaptions = 0;
			Benchmark(bmUpdateSpawnCaptions, UpdateSpawnCaptions());
		}
		if (pTarget)
		{
			LastTarget = ((PSPAWNINFO)pTarget)->SpawnID;
			((EQPlayerHook*)pTarget)->SetNameSpriteTint_Trampoline();
			SetNameSpriteState((PSPAWNINFO)pTarget, true);
		}
	}
}
#endif

#ifndef ISXEQ
VOID CaptionColorCmd(PSPAWNINFO pChar, PCHAR szLine)
{
    if (!szLine[0])
    {
        SyntaxError("Usage: /captioncolor <list|<name off|on|#>>");
        return;
    }
    CHAR Arg1[MAX_STRING]={0};
    CHAR Arg2[MAX_STRING]={0};
    GetArg(Arg1,szLine,1);
    GetArg(Arg2,szLine,2);

    if (!_stricmp(Arg1,"list"))
    {
        WriteChatColor("Caption Color Settings");
        WriteChatColor("----------------------");
        for (DWORD N = 0 ; CaptionColors[N].szName[0] ; N++)
        {
            if (!CaptionColors[N].Enabled || CaptionColors[N].ToggleOnly)
                WriteChatf("%s %s (%s)",CaptionColors[N].szName,CaptionColors[N].Enabled?"ON":"OFF",CaptionColors[N].szDescription);
            else
            {
                ARGBCOLOR Color;
                Color.ARGB=CaptionColors[N].Color;
                WriteChatf("%s ON Color: %d %d %d. (%s)",CaptionColors[N].szName,Color.R,Color.G,Color.B,CaptionColors[N].szDescription);
            }
        }
        return;
    }
    for (DWORD N = 0 ; CaptionColors[N].szName[0] ; N++)
        if (!_stricmp(Arg1,CaptionColors[N].szName))
        {
            if (Arg2[0])
            {
                if (!_stricmp(Arg2,"on"))
                    CaptionColors[N].Enabled=1;
                else if (!_stricmp(Arg2,"off"))
                    CaptionColors[N].Enabled=0;
                else if (CaptionColors[N].Enabled && !CaptionColors[N].ToggleOnly)
                {
                    ARGBCOLOR NewColor;
                    NewColor.A=0;
                    NewColor.R=atoi(Arg2);
                    NewColor.G=atoi(GetArg(Arg2,szLine,3));
                    NewColor.B=atoi(GetArg(Arg2,szLine,4));
                    CaptionColors[N].Color=NewColor.ARGB;
                }
                else
                {
                    MacroError("Invalid option '%s' while '%s' is off.",Arg2,Arg1);
                    return;
                }
            }

            if (!CaptionColors[N].Enabled || CaptionColors[N].ToggleOnly)
                WriteChatf("%s %s (%s)",CaptionColors[N].szName,CaptionColors[N].Enabled?"ON":"OFF",CaptionColors[N].szDescription);
            else
            {
                ARGBCOLOR Color;
                Color.ARGB=CaptionColors[N].Color;
                WriteChatf("%s ON Color: %d %d %d. (%s)",CaptionColors[N].szName,Color.R,Color.G,Color.B,CaptionColors[N].szDescription);
            }
            WritePrivateProfileString("Caption Colors",CaptionColors[N].szName,CaptionColors[N].Enabled?"ON":"OFF",gszINIFilename);
            if (!CaptionColors[N].ToggleOnly)
            {
                sprintf_s(Arg2,"%x",CaptionColors[N].Color);
                sprintf_s(Arg1,"%s-Color",CaptionColors[N].szName);
                WritePrivateProfileString("Caption Colors",Arg1,Arg2,gszINIFilename);
            }
            return;
        }
}
#endif

BOOL IsTargetable(PSPAWNINFO pSpawn)
{
    return ((EQPlayerHook*)pSpawn)->IsTargetable();
}
