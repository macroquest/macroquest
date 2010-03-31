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

#include <direct.h>

#include "MQ2Main.h"
#include <Shellapi.h>

// ***************************************************************************
// Function:    Unload
// Description: Our '/unload' command
//              Triggers the DLL to unload itself
// Usage:       /unload
// ***************************************************************************

VOID Unload(PSPAWNINFO pChar, PCHAR szLine)
{
    bRunNextCommand = TRUE;
	if (gMacroBlock) EndMacro(pChar,szLine);
    DebugSpew(ToUnloadString);
    WriteChatColor(ToUnloadString,USERCOLOR_DEFAULT);
    gbUnload = TRUE;
}

// ***************************************************************************
// Function:    ListMacros
// Description: Our '/listmacros' command
//              Lists macro files
// Usage:       /listmacros <partial filename>
// ***************************************************************************
VOID ListMacros(PSPAWNINFO pChar, PCHAR szLine)
{
    bRunNextCommand = TRUE;
    HANDLE hSearch;
    WIN32_FIND_DATA FileData;
    BOOL fFinished = FALSE;

    DWORD Count = 0, a,b;
    CHAR szFilename[MAX_STRING] = {0};
    CHAR szName[100][MAX_STRING] = {0};
    if (szLine[0]!=0) {
        sprintf(szFilename,"%s\\*%s*.*",gszMacroPath, szLine);
    } else {
        sprintf(szFilename,"%s\\*.*",gszMacroPath, szLine);
    }



    // Start searching for .TXT files in the current directory.

    hSearch = FindFirstFile(szFilename, &FileData);
    if (hSearch == INVALID_HANDLE_VALUE) {
        WriteChatColor("Couldn't find any macros",USERCOLOR_DEFAULT);
        return;
    }


    while (!fFinished)
    {
        strcat(szName[Count],FileData.cFileName);
        Count++;
        if (Count>99) fFinished=TRUE;

        if (!FindNextFile(hSearch, &FileData))
            fFinished = TRUE;
    }
    FindClose(hSearch);
    Count;

    for (a=Count-1;a>0;a--) {
        for (b=0;b<a;b++) {
            if (szName[b]>szName[b+1]) {
                strcat(szFilename,szName[b]);
                strcat(szName[b],szName[b+1]);
                strcat(szName[b+1],szFilename);
            }
        }
    }

    WriteChatColor("Macro list",USERCOLOR_WHO);
    WriteChatColor("----------------",USERCOLOR_WHO);
    for (a=0;a<Count;a++) {
        WriteChatColor(szName[a],USERCOLOR_WHO);
    }

}

// ***************************************************************************
// Function:    Items
// Description: Our '/items' command
//              Lists ground item info
// Usage:       /items <filter>
// ***************************************************************************
PCHAR GetFriendlyNameForGroundItem(PGROUNDITEM pItem, PCHAR szName)
{
	szName[0]=0;
        PITEMDB ItemDB=gItemDB;
    DWORD Item = atoi(pItem->Name + 2);
        while ((ItemDB) && (pItem->ID != ItemDB->ID)) {
            ItemDB = ItemDB->pNext;
        }
        if (ItemDB) {
            strcpy(szName,ItemDB->szName);
        } else if ((Item>=400) && (Item<=MAX_ITEM4xx) && (szItemName4xx[Item-400])) {
            sprintf(szName,"%s%d",szItemName4xx[Item-400],pItem->ID);
        // Regular
        } else if ((Item<=255) && (szItemName[Item])) {
            strcpy(szName,szItemName[Item]);
        // Unknown
        } else {
            sprintf(szName,"Drop%04d/%d",Item,pItem->ID);
        }
    return &szName[0];
}

VOID Items(PSPAWNINFO pChar, PCHAR szLine)
{
    bRunNextCommand = TRUE;

    if (!ppItemList) return;
    if (!pItemList) return;
    PGROUNDITEM pItem = (PGROUNDITEM)pItemList;
    DWORD Count=0;
    CHAR szBuffer[MAX_STRING] = {0};
	CHAR szName[MAX_STRING]={0};
    WriteChatColor("Items on the ground:", USERCOLOR_DEFAULT);
    WriteChatColor("---------------------------", USERCOLOR_DEFAULT);
    while (pItem) {
        GetFriendlyNameForGroundItem(pItem,szName);

        if ((szLine[0]==0) || (!strnicmp(szName,szLine,strlen(szLine)))) {
            SPAWNINFO TempSpawn;
            FLOAT Distance;
            ZeroMemory(&TempSpawn,sizeof(TempSpawn));
            strcpy(TempSpawn.Name,szName);
            TempSpawn.Y=pItem->Y;
            TempSpawn.X=pItem->X;
            TempSpawn.Z=pItem->Z;
            Distance = DistanceToSpawn(pChar,&TempSpawn);
            INT Angle = (INT)((atan2f(pChar->X - pItem->X, pChar->Y - pItem->Y) * 180.0f / PI + 360.0f) / 22.5f + 0.5f) % 16;

            sprintf(szBuffer,"%s: %1.2f away to the %s",szName,Distance,szHeading[Angle]);
            WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
            Count++;
        }

        pItem = pItem->pNext;
    }
    if (Count==0) {
        WriteChatColor("No items found.",USERCOLOR_DEFAULT);
    } else {
        sprintf(szBuffer,"%d item%s found.",Count,(Count==1)?"":"s");
        WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
    }
}


// ***************************************************************************
// Function:    ItemTarget
// Description: Our '/itemtarget' command
//              Lists ground item info
// Usage:       /itemtarget <text>
// ***************************************************************************
VOID ItemTarget(PSPAWNINFO pChar, PCHAR szLine)
{
    bRunNextCommand = TRUE;

    if (!ppItemList) return;
    if (!pItemList) return;
    PGROUNDITEM pItem = (PGROUNDITEM)pItemList;
    CHAR Arg1[MAX_STRING] = {0};
    CHAR Arg2[MAX_STRING] = {0};
    CHAR szBuffer[MAX_STRING] = {0};
	CHAR szName[MAX_STRING]={0};
    FLOAT cDistance = 100000.0f;
    ZeroMemory(&EnviroTarget,sizeof(EnviroTarget));
    pGroundTarget = NULL;
    GetArg(Arg1,szLine,1);
    GetArg(Arg2,szLine,2);
    while (pItem) {
        GetFriendlyNameForGroundItem(pItem,szName);
        if (
                (
                    (szLine[0]==0) ||
                    (!strnicmp(szName,Arg1,strlen(Arg1)))
                ) && (
                    (gZFilter >=10000.0f) ||
                    (
                        (pItem->Z <= pChar->Z + gZFilter) &&
                        (pItem->Z >= pChar->Z - gZFilter)
                    )
                )
            ) {
            SPAWNINFO tSpawn;
            ZeroMemory(&tSpawn,sizeof(tSpawn));
            strcpy(tSpawn.Name,szName);
            tSpawn.Y=pItem->Y;
            tSpawn.X=pItem->X;
            tSpawn.Z=pItem->Z;
            tSpawn.Type = SPAWN_NPC;
            tSpawn.HPCurrent = 1;
            tSpawn.HPMax = 1;
            tSpawn.pActorInfo = &EnviroActor;
            tSpawn.Heading=pItem->Heading;
            tSpawn.Race = pItem->DropID;
            FLOAT Distance = DistanceToSpawn(pChar,&tSpawn);
            if (Distance<cDistance) {
                CopyMemory(&EnviroTarget,&tSpawn,sizeof(EnviroTarget));
                cDistance=Distance;
                pGroundTarget = pItem;
            }
        }

        pItem = pItem->pNext;
    }
    if (EnviroTarget.Name[0]!=0) {
        sprintf(szBuffer,"Item '%s' targeted.",EnviroTarget.Name);
        WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
        if (stricmp(Arg2,"notarget") && ppTarget) pTarget = (EQPlayer*)&EnviroTarget;
    } else {
        if (ppTarget && (pTarget == (EQPlayer*)&EnviroTarget))
            pTarget = NULL;
		MacroError("Couldn't find '%s' to target.",szLine);
    }

}


// ***************************************************************************
// Function:    Doors
// Description: Our '/doors' command
//              Lists door info
// Usage:       /doors <filter>
// ***************************************************************************
VOID Doors(PSPAWNINFO pChar, PCHAR szLine)
{
   bRunNextCommand = TRUE;

   if (!ppSwitchMgr) return;
   if (!pSwitchMgr) return;
       PDOORTABLE pDoorTable = (PDOORTABLE)pSwitchMgr;
   DWORD Count;
   DWORD ActualCount=0;
   CHAR szBuffer[MAX_STRING] = {0};

   WriteChatColor("Doors:", USERCOLOR_DEFAULT);
   WriteChatColor("---------------------------", USERCOLOR_DEFAULT);
   size_t slen = strlen(szLine);

   for (Count=0; Count<pDoorTable->NumEntries; Count++) {
      if ((szLine[0]==0) || (!strnicmp(pDoorTable->pDoor[Count]->Name,szLine,slen))) {
         SPAWNINFO TempSpawn;
         FLOAT Distance;
         ZeroMemory(&TempSpawn,sizeof(TempSpawn));
         strcpy(TempSpawn.Name,pDoorTable->pDoor[Count]->Name);
         TempSpawn.Y=pDoorTable->pDoor[Count]->Y;
         TempSpawn.X=pDoorTable->pDoor[Count]->X;
         TempSpawn.Z=pDoorTable->pDoor[Count]->Z;
         TempSpawn.Heading=pDoorTable->pDoor[Count]->Heading;
         Distance = DistanceToSpawn(pChar,&TempSpawn);
         INT Angle = (INT)((atan2f(pChar->X - pDoorTable->pDoor[Count]->X, pChar->Y - pDoorTable->pDoor[Count]->Y) * 180.0f / PI + 360.0f) / 22.5f + 0.5f) % 16;
         sprintf(szBuffer,"%d: %s: %1.2f away to the %s",pDoorTable->pDoor[Count]->ID, pDoorTable->pDoor[Count]->Name, Distance, szHeading[Angle]);
         WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
         ActualCount++;
      }
   }

   if (ActualCount==0) {
      WriteChatColor("No Doors found.",USERCOLOR_DEFAULT);
   } else {
      sprintf(szBuffer,"%d door%s found.",ActualCount,(ActualCount==1)?"":"s");
      WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
   }
}



// ***************************************************************************
// Function:    DoorTarget
// Description: Our '/doortarget' command
//              Targets the nearest specified door
// Usage:       /doortarget <text>
// ***************************************************************************
VOID DoorTarget(PSPAWNINFO pChar, PCHAR szLine)
{
   bRunNextCommand = TRUE;

   if (!ppSwitchMgr) return;
   if (!pSwitchMgr) return;
    PDOORTABLE pDoorTable = (PDOORTABLE)pSwitchMgr;
   DWORD Count;

   CHAR szBuffer[MAX_STRING] = {0};
   CHAR szSearch[MAX_STRING] = {0};
   CHAR Arg1[MAX_STRING] = {0};
   CHAR Arg2[MAX_STRING] = {0};
   FLOAT cDistance = 100000.0f;
   BYTE ID = -1;
   ZeroMemory(&DoorEnviroTarget,sizeof(DoorEnviroTarget));
   pDoorTarget = NULL;

   GetArg(Arg1,szLine,1);
   GetArg(Arg2,szLine,2);
   if (!stricmp(Arg1, "id")) {
      if (Arg2[0]==0) {
         MacroError("DoorTarget: id specified but no number provided.");
         return;
      }

      ID = atoi(Arg2);
      GetArg(Arg2,szLine,3);
      for (Count=0; Count<pDoorTable->NumEntries; Count++) {
         if (pDoorTable->pDoor[Count]->ID == ID) {
            strcpy(DoorEnviroTarget.Name, pDoorTable->pDoor[Count]->Name);
            DoorEnviroTarget.Y = pDoorTable->pDoor[Count]->Y;
            DoorEnviroTarget.X = pDoorTable->pDoor[Count]->X;
            DoorEnviroTarget.Z = pDoorTable->pDoor[Count]->Z;
            DoorEnviroTarget.Heading = pDoorTable->pDoor[Count]->Heading;
			DoorEnviroTarget.Type = SPAWN_NPC;
			DoorEnviroTarget.HPCurrent = 1;
			DoorEnviroTarget.HPMax = 1;
			DoorEnviroTarget.pActorInfo = &EnviroActor;
            pDoorTarget = pDoorTable->pDoor[Count];
            break;
         }
      }
   } else {
      strcpy(szSearch, Arg1);
      for (Count=0; Count<pDoorTable->NumEntries; Count++) {
         if (((szSearch[0]==0) ||
             (!strnicmp(pDoorTable->pDoor[Count]->Name,szSearch,strlen(szSearch)))) &&
            ((gZFilter >=10000.0f) ||
              ((pDoorTable->pDoor[Count]->Z <= pChar->Z + gZFilter) &&
               (pDoorTable->pDoor[Count]->Z >= pChar->Z - gZFilter)))) {
            SPAWNINFO tSpawn;
            ZeroMemory(&tSpawn,sizeof(tSpawn));
            strcpy(tSpawn.Name,pDoorTable->pDoor[Count]->Name);
            tSpawn.Y=pDoorTable->pDoor[Count]->Y;
            tSpawn.X=pDoorTable->pDoor[Count]->X;
            tSpawn.Z=pDoorTable->pDoor[Count]->Z;
			tSpawn.Type = SPAWN_NPC;
			tSpawn.HPCurrent = 1;
			tSpawn.HPMax = 1;
			tSpawn.pActorInfo = &EnviroActor;
            tSpawn.Heading=pDoorTable->pDoor[Count]->Heading;
            FLOAT Distance = DistanceToSpawn(pChar,&tSpawn);
            if (Distance<cDistance) {
               CopyMemory(&DoorEnviroTarget,&tSpawn,sizeof(DoorEnviroTarget));
               pDoorTarget = pDoorTable->pDoor[Count];
               cDistance=Distance;
            }
         }

      }
   }


   if (DoorEnviroTarget.Name[0]!=0) {
      sprintf(szBuffer,"Door %d '%s' targeted.", pDoorTarget->ID, DoorEnviroTarget.Name);
      WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
	  if (stricmp(Arg2,"notarget") && ppTarget) pTarget = (EQPlayer*)&DoorEnviroTarget;
   } else {
      if (ppTarget) pTarget = NULL;
      MacroError("Couldn't find door '%s' to target.",szLine);
   }
}

// ***************************************************************************
// Function:    CharInfo
// Description: Our '/charinfo' command
//              Displays character bind points
// Usage:       /charinfo
// ***************************************************************************

PCHAR GetModel(PSPAWNINFO pSpawn, DWORD Slot)
{
    if (!pSpawn) return NULL;
    if (!pSpawn->pActorInfo) return NULL;
    if (Slot>20) return NULL;
    PMODELINFO pMod = pSpawn->pActorInfo->Model[Slot];
    if (!pMod) return NULL;
    if (!pMod->pModelInfo) return NULL;
    if (pMod->pModelInfo->Type != 0x48) return NULL;
    PMODELINFO_48 pModInfo = (PMODELINFO_48)pMod->pModelInfo;
    if (!pModInfo->pModelName) return NULL;
    PCHAR szModel = pModInfo->pModelName->Name;
    if (!szModel) return szItemName[0];
    return szItemName[atoi(szModel+2)];
}



VOID CharInfo(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szBuffer[MAX_STRING] = {0};
    bRunNextCommand = TRUE;

    if (gFilterMacro == FILTERMACRO_NONE) cmdCharInfo(pChar, szLine);
    PCHARINFO pCharInfo = NULL;
    if (NULL == (pCharInfo = GetCharInfo())) return;
    sprintf(szBuffer,"You are bound in %s at %1.2f, %1.2f, %1.2f", GetFullZone(pCharInfo->ZoneBoundId), pCharInfo->ZoneBoundX, pCharInfo->ZoneBoundY, pCharInfo->ZoneBoundZ);
    WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
}


VOID UpdateItemInfo(PSPAWNINFO pChar, PCHAR szLine) {
   CHAR szBuffer[MAX_STRING] = {0};
   PCONTENTS pContainer = NULL;

   PCHARINFO pCharInfo = NULL;
   if (NULL == (pCharInfo = GetCharInfo())) return;

   for (int nInvIdx=0; nInvIdx < 30; nInvIdx++) {
      if (pCharInfo->InventoryArray[nInvIdx] != NULL) {
         BOOL Found = FALSE;
         PITEMDB ItemDB = gItemDB;
         while (ItemDB) {
            if (ItemDB->ID == pCharInfo->InventoryArray[nInvIdx]->Item->ItemNumber) {
               Found = TRUE;
            }
            ItemDB = ItemDB->pNext;
         }
         if (!Found) {
            PITEMDB Item = (PITEMDB)malloc(sizeof(ITEMDB));
            Item->pNext = gItemDB;
            Item->ID = pCharInfo->InventoryArray[nInvIdx]->Item->ItemNumber;
            strcpy(Item->szName, pCharInfo->InventoryArray[nInvIdx]->Item->Name);
            DebugSpew("   New Item found - %d: %s", Item->ID, Item->szName);
            gItemDB = Item;
         }
         if (pCharInfo->InventoryArray[nInvIdx]->Item->Type == ITEMTYPE_PACK) {
			 pContainer = pCharInfo->InventoryArray[nInvIdx];
            DebugSpew("   Opening Pack");
            for (int nPackIdx = 0; nPackIdx < pCharInfo->InventoryArray[nInvIdx]->Item->Slots; nPackIdx++) {
               if (pContainer->Contents[nPackIdx] != NULL) {
                  Found = FALSE;
                  PITEMDB ItemDB = gItemDB;
                  while (ItemDB) {
                      if (pContainer->Contents[nPackIdx]) {
                        if (ItemDB->ID == pContainer->Contents[nPackIdx]->Item->ItemNumber) {
                            Found = TRUE;
                        }
                        ItemDB = ItemDB->pNext;
                      }
                  }
                  if (!Found) {
                     PITEMDB Item = (PITEMDB)malloc(sizeof(ITEMDB));
                     Item->pNext = gItemDB;
                     Item->ID = pContainer->Contents[nPackIdx]->Item->ItemNumber;
                     strcpy(Item->szName, pContainer->Contents[nPackIdx]->Item->Name);
                     DebugSpew("      New Item found - %d: %s", Item->ID, Item->szName);
                     gItemDB = Item;
                  }
               }
            }
         }
      }
   }

   for (nInvIdx=0; nInvIdx < NUM_BANK_SLOTS; nInvIdx++) {
      if (pCharInfo->Bank[nInvIdx] != NULL) {
         BOOL Found = FALSE;
         PITEMDB ItemDB = gItemDB;
         while (ItemDB) {
            if (ItemDB->ID == pCharInfo->Bank[nInvIdx]->Item->ItemNumber) {
               Found = TRUE;
            }
            ItemDB = ItemDB->pNext;
         }
         if (!Found) {
            PITEMDB Item = (PITEMDB)malloc(sizeof(ITEMDB));
            Item->pNext = gItemDB;
            Item->ID = pCharInfo->Bank[nInvIdx]->Item->ItemNumber;
            strcpy(Item->szName, pCharInfo->Bank[nInvIdx]->Item->Name);
            DebugSpew("   New Item found - %d: %s", Item->ID, Item->szName);
            gItemDB = Item;
         }
         if (pCharInfo->Bank[nInvIdx]->Item->Type == ITEMTYPE_PACK) {
            LONG nPackIdx;
			 pContainer = pCharInfo->Bank[nInvIdx];

            for (nPackIdx = 0; nPackIdx < pCharInfo->Bank[nInvIdx]->Item->Slots; nPackIdx++) {
               if (pContainer->Contents[nPackIdx] != NULL) {
                  PITEMDB ItemDB = gItemDB;
                  Found = FALSE;
                  while (ItemDB) {
                      if (pContainer->Contents[nPackIdx]) {
                          if (ItemDB->ID == pContainer->Contents[nPackIdx]->Item->ItemNumber) {
                            Found = TRUE;
                          }
                          ItemDB = ItemDB->pNext;
                      }
                  }
                  if (!Found) {
                     PITEMDB Item = (PITEMDB)malloc(sizeof(ITEMDB));
                     Item->pNext = gItemDB;
                     Item->ID = pContainer->Contents[nPackIdx]->Item->ItemNumber;
                     strcpy(Item->szName, pContainer->Contents[nPackIdx]->Item->Name);
                     DebugSpew("      New Item found - %d: %s", Item->ID, Item->szName);
                     gItemDB = Item;
                  }
               }
            }
         }
      }
   }

   PITEMDB ItemDB = gItemDB;
   if (ItemDB) {
      FILE *fDB = fopen(gszItemDB, "wt");
      while (ItemDB) {
         sprintf(szBuffer, "%d\t%s\n", ItemDB->ID, ItemDB->szName);
         fputs(szBuffer, fDB);
         ItemDB = ItemDB->pNext;
      }
      fclose(fDB);
   }
}

// ***************************************************************************
// Function:    MemSpell
// Description: Our '/MemSpell' command
// Usage:       /MemSpell gem# "spell name"
// ***************************************************************************
SPELLFAVORITE MemSpellFavorite;
VOID MemSpell(PSPAWNINFO pChar, PCHAR szLine)
{
    if (!ppSpellBookWnd) return;
    DWORD Favorite = (DWORD)&MemSpellFavorite;
   CHAR szGem[MAX_STRING] = {0};
    DWORD sp;
   WORD Gem = -1;
   CHAR SpellName[MAX_STRING] = {0};
   PCHARINFO pCharInfo = NULL;
    if (!pSpellBookWnd) return;
   if (NULL == (pCharInfo = GetCharInfo())) return;

   GetArg(szGem,szLine,1);
   GetArg(SpellName,szLine,2);
   Gem = atoi(szGem);
   if (Gem<1 || Gem>9) return;
   Gem--;

   pCharInfo->SpellBook;
   PSPELL pSpell=0;
	for (DWORD N = 0 ; N < NUM_BOOK_SLOTS ; N++)
	if (PSPELL pTempSpell=GetSpellByID(pCharInfo->SpellBook[N]))
	{
		if (!stricmp(SpellName,pTempSpell->Name))
		{
			pSpell=pTempSpell;
			break;
		}
	}

    if (!pSpell) return;
    if (pSpell->Level[pChar->Class-1]>pChar->Level) return;

    ZeroMemory(&MemSpellFavorite,sizeof(MemSpellFavorite));
    strcpy(MemSpellFavorite.Name,"Mem a Spell");
    MemSpellFavorite.Byte_3e=1;
    for (sp=0;sp<9;sp++) MemSpellFavorite.SpellId[sp]=0xFFFFFFFF;
    MemSpellFavorite.SpellId[Gem] = pSpell->ID;
	pSpellBookWnd->MemorizeSet((int*)Favorite,9);
}

// ***************************************************************************
// Function:    buyitem
// Description: Our '/buyitem' command
// Usage:       /buyitem Quantity#
// uses private: void __thiscall CMerchantWnd::RequestBuyItem(int)
// will buy the specified quantity of the currently selected item
// ***************************************************************************
VOID BuyItem(PSPAWNINFO pChar, PCHAR szLine)
{
   bRunNextCommand = FALSE;
   if (!pMerchantWnd) return;

   CHAR szBuffer[MAX_STRING] = {0};
   CHAR szQty[MAX_STRING] = {0};
   PCHARINFO pCharInfo = NULL;
   DWORD Qty;
   if (NULL == (pCharInfo = GetCharInfo())) return;
   GetArg(szQty,szLine,1);
   Qty = (DWORD)atoi(szQty);
   if (Qty > 20 || Qty < 1) return;
   pMerchantWnd->RequestBuyItem(Qty);
   return;
}
// ***************************************************************************
// Function:    sellitem
// Description: Our '/sellitem' command
// Usage:       /sellitem Quantity#
// uses private: void __thiscall CMerchantWnd::RequestSellItem(int)
// will buy the specified quantity of the currently selected item
// ***************************************************************************
VOID SellItem(PSPAWNINFO pChar, PCHAR szLine)
{
    bRunNextCommand = FALSE;
    CHAR szBuffer[MAX_STRING] = {0};
    CHAR szQty[MAX_STRING] = {0};
    PCHARINFO pCharInfo = NULL;
    DWORD Qty;

    if (NULL == (pCharInfo = GetCharInfo())) return;
    GetArg(szQty,szLine,1);
    Qty = (DWORD)atoi(szQty);
    if (Qty > 20 || Qty < 1) return;
   pMerchantWnd->RequestSellItem(Qty);
    return;
}
// ***************************************************************************
// Function:    Help
// Description: Our '/help' command
//              Adds our help type (7) to the built-in help command
// Usage:       /help macro
// ***************************************************************************
VOID Help(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szCmd[MAX_STRING] = {0};
    CHAR szArg[MAX_STRING] = {0};
    PMQCOMMAND pCmd=pCommands;

    GetArg(szArg,szLine,1);
    if (szArg[0] == 0) {
        cmdHelp(pChar,szArg);
        if (gFilterMacro != FILTERMACRO_NONE) WriteChatColor("Macro will display a list of MacroQuest commands.", USERCOLOR_DEFAULT);
        return;
    }
    if (stricmp("macro",szArg)) {
        cmdHelp(pChar,szArg);
        return;
    }
    DebugSpew("Help - Displaying MacroQuest help");
    sprintf(szCmd,"MacroQuest - %s",gszVersion);
    WriteChatColor(" ",USERCOLOR_DEFAULT);
    WriteChatColor(szCmd,USERCOLOR_DEFAULT);
    WriteChatColor("List of commands",USERCOLOR_DEFAULT);
    WriteChatColor("------------------------------------------",USERCOLOR_DEFAULT);
	while(pCmd)
	{
		if (pCmd->EQ==0)
		{
	        sprintf(szCmd,"  %s",pCmd->Command);
		    WriteChatColor(szCmd,USERCOLOR_DEFAULT);
		}
		pCmd=pCmd->pNext;
    }
}


// ***************************************************************************
// Function:    MacroBeep
// Description: Our '/beep' command
//              Beeps the system speaker
// Usage:       /beep
// ***************************************************************************
VOID MacroBeep(PSPAWNINFO pChar, PCHAR szLine)
{
    bRunNextCommand = TRUE;
    Beep(0x500,250);
}


// ***************************************************************************
// Function:    SWhoFilter
// Description: Our '/whofilter' command
//              Sets SuperWho filters
// Usage:       /whofilter [options]
// ***************************************************************************
VOID SetDisplaySWhoFilter(PBOOL bToggle, PCHAR szFilter, PCHAR szToggle)
{
	CHAR szTemp[MAX_STRING] = {0};
	if (!stricmp(szToggle,"on")) *bToggle = TRUE;
	else if (!stricmp(szToggle,"off")) *bToggle = FALSE;
	sprintf(szTemp,"%s is: %s",szFilter,(*bToggle)?"on":"off");
	WriteChatColor(szTemp,USERCOLOR_DEFAULT);
	itoa(*bToggle,szTemp,10);
	WritePrivateProfileString("SWho Filter",szFilter,szTemp,gszINIFilename);
}
VOID SWhoFilter(PSPAWNINFO pChar, PCHAR szLine)
{
	CHAR szArg[MAX_STRING] = {0};
	CHAR szToggle[MAX_STRING] = {0};
	CHAR szTemp[MAX_STRING] = {0};
	GetArg(szArg,szLine,1);
	GetArg(szToggle,szLine,2);
	if (!stricmp(szArg,"Lastname")) {
		SetDisplaySWhoFilter(&gFilterSWho.Lastname,"Lastname",szToggle);
	} else if (!stricmp(szArg,"Class")) {
		SetDisplaySWhoFilter(&gFilterSWho.Class,"Class",szToggle);
	} else if (!stricmp(szArg,"Race")) {
		SetDisplaySWhoFilter(&gFilterSWho.Race,"Race",szToggle);
	} else if (!stricmp(szArg,"Body")) {
		SetDisplaySWhoFilter(&gFilterSWho.Body,"Body",szToggle);
	} else if (!stricmp(szArg,"Level")) {
		SetDisplaySWhoFilter(&gFilterSWho.Level,"Level",szToggle);
	} else if (!stricmp(szArg,"GM")) {
		SetDisplaySWhoFilter(&gFilterSWho.GM,"GM",szToggle);
	} else if (!stricmp(szArg,"Guild")) {
		SetDisplaySWhoFilter(&gFilterSWho.Guild,"Guild",szToggle);
	} else if (!stricmp(szArg,"LD")) {
		SetDisplaySWhoFilter(&gFilterSWho.LD,"LD",szToggle);
    } else if (!stricmp(szArg,"Sneak")) { 
      SetDisplaySWhoFilter(&gFilterSWho.Sneak,"Sneak",szToggle);   
	} else if (!stricmp(szArg,"LFG")) {
		SetDisplaySWhoFilter(&gFilterSWho.LFG,"LFG",szToggle);
	} else if (!stricmp(szArg,"NPCTag")) {
		SetDisplaySWhoFilter(&gFilterSWho.NPCTag,"NPCTag",szToggle);
	} else if (!stricmp(szArg,"SpawnID")) {
		SetDisplaySWhoFilter(&gFilterSWho.SpawnID,"SpawnID",szToggle);
	} else if (!stricmp(szArg,"Trader")) {
		SetDisplaySWhoFilter(&gFilterSWho.Trader,"Trader",szToggle);
	} else if (!stricmp(szArg,"AFK")) {
		SetDisplaySWhoFilter(&gFilterSWho.AFK,"AFK",szToggle);
	} else if (!stricmp(szArg,"Anon")) {
		SetDisplaySWhoFilter(&gFilterSWho.Anon,"Anon",szToggle);
	} else if (!stricmp(szArg,"Distance")) {
		SetDisplaySWhoFilter(&gFilterSWho.Distance,"Distance",szToggle);
	} else if (!stricmp(szArg,"Light")) {
		SetDisplaySWhoFilter(&gFilterSWho.Light,"Light",szToggle);
	} else if (!stricmp(szArg,"Holding")) {
		SetDisplaySWhoFilter(&gFilterSWho.Holding,"Holding",szToggle);
	} else if (!stricmp(szArg,"ConColor")) { 
        SetDisplaySWhoFilter(&gFilterSWho.ConColor,"ConColor",szToggle); 
	} else if (!stricmp(szArg,"invisible")) {
        SetDisplaySWhoFilter(&gFilterSWho.Invisible,"Invisible",szToggle);
	} else {
      SyntaxError("Usage: /whofilter <lastname|class|race|level|gm|guild|holding|ld|sneak|anon|lfg|npctag|spawnid|trader|afk|concolor|invisible> [on|off]");
   } 
}

// ***************************************************************************
// Function:    Filter
// Description: Our '/filter' command
//              Adds 'skills' to the built-in filter command
// Usage:       /filter skills
// ***************************************************************************
VOID WriteFilterNames(VOID)
{
    CHAR szBuffer[MAX_STRING] = {0};
    int filternumber=1;
    PFILTER pFilter = gpFilters;
    WritePrivateProfileSection("Filter Names",szBuffer,gszINIFilename);
    while (pFilter) {
        if (pFilter->pEnabled == &gFilterCustom) {
            sprintf(szBuffer,"Filter%d",filternumber++);
            WritePrivateProfileString("Filter Names",szBuffer,pFilter->FilterText, gszINIFilename);
        }
        pFilter = pFilter->pNext;
    }

}

VOID Filter(PSPAWNINFO pChar, PCHAR szLine)
{
    bRunNextCommand = TRUE;
    DWORD Command;
    CHAR szCmd[MAX_STRING] = {0};
    CHAR szArg[MAX_STRING] = {0};
    PCHAR szRest = NULL;
    PCHAR szFilterSkills[] = {
        "all",
        "increase",
        "none",
        NULL
    };

    PCHAR szFilterMacro[] = {
        "all",
        "enhanced",
        "none",
        NULL
    };

    PCHAR szFilterTarget[] = {
        "off",
        "on",
        NULL
    };

    PCHAR szUseChat[] = {
        "off",
        "on",
        NULL
    };

    szRest = szLine;
    GetArg(szArg,szRest,1);
    szRest = GetNextArg(szRest,1);
    if (szArg[0] == 0) {
        cmdFilter(pChar,szArg);
        if (gFilterMacro != FILTERMACRO_NONE) WriteChatColor("skills, target, money, encumber, food, name, zrange, macros, mq, debug", USERCOLOR_DEFAULT);
        return;
    }

    if ((stricmp("skills",szArg)) &&
        (stricmp("macros",szArg)) &&
        (stricmp("target",szArg)) &&
        (stricmp("name",szArg)) &&
        (stricmp("food",szArg)) &&
        (stricmp("money",szArg)) &&
        (stricmp("encumber",szArg)) &&
        (stricmp("mq",szArg)) &&
        (stricmp("debug",szArg)) &&
        (stricmp("zrange",szArg))) {
        cmdFilter(pChar,szArg);
        return;
    }
    if (!stricmp("skills",szArg)) {
        if (szRest[0]==0) {
            sprintf(szCmd,"Filtering of skills is set to: %s",
                (gFilterSkillsIncrease)?"None":(gFilterSkillsAll)?"Increase":"All");
            WriteChatColor(szCmd,USERCOLOR_DEFAULT);
            return;
        }
        for (Command=0;szFilterSkills[Command];Command++) {
            if (!stricmp(szRest,szFilterSkills[Command])) {
                gFilterSkillsAll = (0!=Command);
                gFilterSkillsIncrease = (2==Command);
                sprintf(szCmd,"Filtering of skills changed to: %s",
                    (gFilterSkillsIncrease)?"None":(gFilterSkillsAll)?"Increase":"All");
                WriteChatColor(szCmd,USERCOLOR_DEFAULT);
                itoa(Command,szCmd,10); WritePrivateProfileString("MacroQuest","FilterSkills",szCmd,gszINIFilename);
                return;
            }
        }
        SyntaxError("Usage: /filter skills [all|increase|none]");

    } else if (!stricmp("macros",szArg)) {
        if (szRest[0]==0) {
            sprintf(szCmd,"Filtering of macros is set to: %s",szFilterMacro[gFilterMacro]);
            WriteChatColor(szCmd,USERCOLOR_DEFAULT);
            return;
        }
        for (Command=0;szFilterMacro[Command];Command++) {
            if (!stricmp(szRest,szFilterMacro[Command])) {
                gFilterMacro = Command;
                sprintf(szCmd,"Filtering of macros changed to: %s",szFilterMacro[gFilterMacro]);
                WriteChatColor(szCmd,USERCOLOR_DEFAULT);
                itoa(gFilterMacro,szCmd,10); WritePrivateProfileString("MacroQuest","FilterMacro",szCmd,gszINIFilename);
                return;
            }
        }
        SyntaxError("Usage: /filter macros [all|enhanced|none]");
	} else if (!stricmp("mq",szArg)) {
        if (szRest[0]==0) {
            sprintf(szCmd,"Filtering of MQ is set to: %s",szUseChat[gFilterMQ]);
            WriteChatColor(szCmd,USERCOLOR_DEFAULT);
            return;
        }
        for (Command=0;szUseChat[Command];Command++) {
            if (!stricmp(szRest,szUseChat[Command])) {
                gFilterMQ = Command;
                sprintf(szCmd,"Filtering of MQ changed to: %s",szUseChat[gFilterMQ]);
                WriteChatColor(szCmd,USERCOLOR_DEFAULT);
                itoa(gFilterMQ,szCmd,10); 
				WritePrivateProfileString("MacroQuest","FilterMQ",szCmd,gszINIFilename);
                return;
            }
        }
        SyntaxError("Usage: /filter mq [on|off]");
	} else if (!stricmp("mq2data",szArg)) {
        if (szRest[0]==0) {
            sprintf(szCmd,"Filtering of MQ2Data Errors is set to: %s",szUseChat[gFilterMQ2DataErrors]);
            WriteChatColor(szCmd,USERCOLOR_DEFAULT);
            return;
        }
        for (Command=0;szUseChat[Command];Command++) {
            if (!stricmp(szRest,szUseChat[Command])) {
                gFilterMQ2DataErrors = Command;
                sprintf(szCmd,"Filtering of MQ changed to: %s",szUseChat[gFilterMQ2DataErrors]);
                WriteChatColor(szCmd,USERCOLOR_DEFAULT);
                itoa(gFilterMQ2DataErrors,szCmd,10); 
				WritePrivateProfileString("MacroQuest","FilterMQ2Data",szCmd,gszINIFilename);
                return;
            }
        }
        SyntaxError("Usage: /filter mq2data [on|off]");


    } else if (!stricmp("target",szArg)) {
        if (szRest[0]==0) {
            sprintf(szCmd,"Filtering of target lost messages is set to: %s",szFilterTarget[gFilterTarget]);
            WriteChatColor(szCmd,USERCOLOR_DEFAULT);
            return;
        }
        for (Command=0;szFilterTarget[Command];Command++) {
            if (!stricmp(szRest,szFilterTarget[Command])) {
                gFilterTarget = Command;
                sprintf(szCmd,"Filtering of target lost messages changed to: %s",szFilterTarget[gFilterTarget]);
                WriteChatColor(szCmd,USERCOLOR_DEFAULT);
                itoa(gFilterTarget,szCmd,10); WritePrivateProfileString("MacroQuest","FilterTarget",szCmd,gszINIFilename);
                return;
            }
        }
        SyntaxError("Usage: /filter target [on|off]");

    } else if (!stricmp("debug",szArg)) {
        if (szRest[0]==0) {
            sprintf(szCmd,"Filtering of debug messages is set to: %s",szFilterTarget[gFilterDebug]);
            WriteChatColor(szCmd,USERCOLOR_DEFAULT);
            return;
        }
        for (Command=0;szFilterTarget[Command];Command++) {
            if (!stricmp(szRest,szFilterTarget[Command])) {
                gFilterDebug = Command;
                sprintf(szCmd,"Filtering of debug messages changed to: %s",szFilterTarget[gFilterDebug]);
                WriteChatColor(szCmd,USERCOLOR_DEFAULT);
                itoa(gFilterTarget,szCmd,10); WritePrivateProfileString("MacroQuest","FilterDebug",szCmd,gszINIFilename);
                return;
            }
        }
        SyntaxError("Usage: /filter debug [on|off]");

    } else if (!stricmp("money",szArg)) {
        if (szRest[0]==0) {
            sprintf(szCmd,"Filtering of money messages is set to: %s",szFilterTarget[gFilterMoney]);
            WriteChatColor(szCmd,USERCOLOR_DEFAULT);
            return;
        }
        for (Command=0;szFilterTarget[Command];Command++) {
            if (!stricmp(szRest,szFilterTarget[Command])) {
                gFilterMoney = Command;
                sprintf(szCmd,"Filtering of money messages changed to: %s",szFilterTarget[gFilterMoney]);
                WriteChatColor(szCmd,USERCOLOR_DEFAULT);
                itoa(gFilterMoney,szCmd,10); WritePrivateProfileString("MacroQuest","FilterMoney",szCmd,gszINIFilename);
                return;
            }
        }
        SyntaxError("Usage: /filter money [on|off]");
    } else if (!stricmp("encumber",szArg)) {
        if (szRest[0]==0) {
            sprintf(szCmd,"Filtering of encumber messages is set to: %s",szFilterTarget[gFilterEncumber]);
            WriteChatColor(szCmd,USERCOLOR_DEFAULT);
            return;
        }
        for (Command=0;szFilterTarget[Command];Command++) {
            if (!stricmp(szRest,szFilterTarget[Command])) {
                gFilterEncumber = Command;
                sprintf(szCmd,"Filtering of encumber messages changed to: %s",szFilterTarget[gFilterEncumber]);
                WriteChatColor(szCmd,USERCOLOR_DEFAULT);
                itoa(gFilterEncumber,szCmd,10); WritePrivateProfileString("MacroQuest","FilterEncumber",szCmd,gszINIFilename);
                return;
            }
        }
        SyntaxError("Usage: /filter encumber [on|off]");
    } else if (!stricmp("food",szArg)) {
        if (szRest[0]==0) {
            sprintf(szCmd,"Filtering of food messages is set to: %s",szFilterTarget[gFilterFood]);
            WriteChatColor(szCmd,USERCOLOR_DEFAULT);
            return;
        }
        for (Command=0;szFilterTarget[Command];Command++) {
            if (!stricmp(szRest,szFilterTarget[Command])) {
                gFilterFood = Command;
                sprintf(szCmd,"Filtering of food messages changed to: %s",szFilterTarget[gFilterFood]);
                WriteChatColor(szCmd,USERCOLOR_DEFAULT);
                itoa(gFilterFood,szCmd,10); WritePrivateProfileString("MacroQuest","FilterFood",szCmd,gszINIFilename);
                return;
            }
        }
        SyntaxError("Usage: /filter food [on|off]");
    } else if (!stricmp("name",szArg)) {
        if (szRest[0]==0) {
            WriteChatColor("Names currently filtered:", USERCOLOR_DEFAULT);
            WriteChatColor("---------------------------", USERCOLOR_DEFAULT);
            PFILTER pFilter = gpFilters;
            while (pFilter) {
                if (pFilter->pEnabled == &gFilterCustom) {
                    sprintf(szCmd, "   %s", pFilter->FilterText);
                    WriteChatColor(szCmd,USERCOLOR_DEFAULT);
                }
                pFilter = pFilter->pNext;
            }
        } else {
            GetArg(szArg,szRest,1);
            szRest=GetNextArg(szRest);
            if (!stricmp(szArg,"on") || !stricmp(szArg,"off")) {
                for (Command=0;szFilterTarget[Command];Command++) {
                    if (!stricmp(szArg,szFilterTarget[Command])) {
                        gFilterCustom = Command;
                        sprintf(szCmd,"Filtering of custom messages changed to: %s",szFilterTarget[gFilterCustom]);
                        WriteChatColor(szCmd,USERCOLOR_DEFAULT);
                        itoa(gFilterCustom,szCmd,10); WritePrivateProfileString("MacroQuest","FilterCustom",szCmd,gszINIFilename);
                        return;
                    }
                }
            } else if (!stricmp(szArg,"remove")) {
                if (szRest[0]==0) {
                    WriteChatColor("Remove what?",USERCOLOR_DEFAULT);
                }
                if (!stricmp(szRest,"all")) {

                    PFILTER pFilter = gpFilters;
                    PFILTER pLastFilter = NULL;
                    while (pFilter) {
                        if (pFilter->pEnabled == &gFilterCustom) {
                            if (!pLastFilter) {
                                gpFilters = pFilter->pNext;
                                free(pFilter);
                                pFilter = gpFilters->pNext;
                            } else {
                                pLastFilter->pNext = pFilter->pNext;
                                free(pFilter);
                                pFilter = pLastFilter->pNext;
                            }
                        } else {
                            pLastFilter = pFilter;
                            pFilter = pFilter->pNext;
                        }
                    }
                    WriteChatColor("Cleared all name filters.",USERCOLOR_DEFAULT);
                    WriteFilterNames();
                    return;
                } else {
                    PFILTER pFilter = gpFilters;
                    PFILTER pLastFilter = NULL;
                    while (pFilter) {
                        if ((pFilter->pEnabled == &gFilterCustom) && (!stricmp(pFilter->FilterText,szRest))) {
                            if (!pLastFilter) {
                                gpFilters = pFilter->pNext;
                            } else {
                                pLastFilter->pNext = pFilter->pNext;
                            }
                            free(pFilter);
                            sprintf(szCmd,"Stopped filtering on: %s",szRest);
                            WriteChatColor(szCmd,USERCOLOR_DEFAULT);
                            WriteFilterNames();
                            return;
                        } else {
                            pLastFilter = pFilter;
                            pFilter = pFilter->pNext;
                        }
                    }
                }
            } else if (!stricmp(szArg,"add")) {
                if (szRest[0]==0) {
                    WriteChatColor("Add what?",USERCOLOR_DEFAULT);
                }
                PFILTER pFilter = gpFilters;
                while (pFilter) {
                    if ((pFilter->pEnabled == &gFilterCustom) && (!stricmp(pFilter->FilterText,szRest))) {
                        sprintf(szCmd,"Name '%s' is already being filtered.",szRest);
                        WriteChatColor(szCmd,USERCOLOR_DEFAULT);
                        return;
                    }
                    pFilter = pFilter->pNext;
                }

                AddFilter(szRest,-1,&gFilterCustom);
                WriteFilterNames();
                sprintf(szCmd,"Started filtering on: %s",szRest);
                WriteChatColor(szCmd,USERCOLOR_DEFAULT);
                return;
            } else {
                SyntaxError("Usage: /filter name on|off|add|remove <name>");
                return;
            }
        }
    } else if (!stricmp("zrange",szArg)) {
        if (szRest[0]==0) {
            if (gZFilter>=10000.0f) {
                WriteChatColor("Z range is not currently set.", USERCOLOR_DEFAULT);
            } else {
                sprintf(szArg,"Z range is set to: %1.2f",gZFilter);
                WriteChatColor(szArg, USERCOLOR_DEFAULT);
            }
        } else {
            gZFilter = (FLOAT)atof(szRest);
        }
    }
}


// ***************************************************************************
// Function:    DebugSpewFile
// Description: Our '/spewfile' command
//              Controls logging of DebugSpew to a file
// Usage:       /spewfile [on,off]
// ***************************************************************************
VOID DebugSpewFile(PSPAWNINFO pChar, PCHAR szLine)
{
    BOOL Pause = TRUE;
    CHAR szBuffer[MAX_STRING] = {0};
    bRunNextCommand = TRUE;
    if (!strnicmp(szLine,"off",3)) {
        gSpewToFile = FALSE;
    } else if (!strnicmp(szLine,"on",2)) {
        gSpewToFile = TRUE;
    } else if (szLine[0]!=0) {
        WriteChatColor("Syntax: /spewfile [on|off]",USERCOLOR_DEFAULT);
    } else {
        Pause = !gSpewToFile;
    }
    if (gSpewToFile) {
        sprintf(szBuffer,"Debug Spew is being logged to a file.");
    } else {
        sprintf(szBuffer,"Debug Spew is not being logged to a file.");
    }
    WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
}


// ***************************************************************************
// Function:    Identify
// Description: Our '/identify' command
//              Identifies the item on the cursor, displaying the LORE name.
// Usage:       /identify
// ***************************************************************************
VOID Identify(PSPAWNINFO pChar, PCHAR szLine)
{
    bRunNextCommand = TRUE;
    CHAR szMsg[MAX_STRING] = {0};
    CHAR szTmp[MAX_STRING] = {0};
    PCHARINFO pCharInfo = NULL;
    if (NULL == (pCharInfo = GetCharInfo())) return;
    if (!pCharInfo->Cursor) {
        MacroError("You must be holding an item to identify it.");
        return;
    }

	DebugSpew("Identify - %s", pCharInfo->Cursor->Item->LoreName);
    WriteChatColor(" ",USERCOLOR_SPELLS);
	if		( pCharInfo->Cursor->Item->Type == ITEMTYPE_NORMAL && pCharInfo->Cursor->Item->ItemType < MAX_ITEMTYPES && szItemTypes[pCharInfo->Cursor->Item->ItemType] != NULL  )
	    sprintf(szMsg,"Item: %s (Slot: %s, Weight: %d.%d, Value: %dcp, Type: %s)",pCharInfo->Cursor->Item->Name,szSize[pCharInfo->Cursor->Item->Size], (INT)(pCharInfo->Cursor->Item->Weight/10),(pCharInfo->Cursor->Item->Weight) % 10, pCharInfo->Cursor->Item->Cost, szItemTypes[pCharInfo->Cursor->Item->ItemType] );
	else if ( pCharInfo->Cursor->Item->Type == ITEMTYPE_PACK && pCharInfo->Cursor->Item->Combine < MAX_COMBINES && szCombineTypes[pCharInfo->Cursor->Item->Combine] != NULL )
	    sprintf(szMsg,"Item: %s (Slot: %s, Weight: %d.%d, Value: %dcp, Type: %s)",pCharInfo->Cursor->Item->Name,szSize[pCharInfo->Cursor->Item->Size], (INT)(pCharInfo->Cursor->Item->Weight/10),(pCharInfo->Cursor->Item->Weight) % 10, pCharInfo->Cursor->Item->Cost, szCombineTypes[pCharInfo->Cursor->Item->Combine] );
    else
		sprintf(szMsg,"Item: %s (Slot: %s, Weight: %d.%d, Value: %dcp)",pCharInfo->Cursor->Item->Name,szSize[pCharInfo->Cursor->Item->Size], (INT)(pCharInfo->Cursor->Item->Weight/10),(pCharInfo->Cursor->Item->Weight) % 10, pCharInfo->Cursor->Item->Cost );


    WriteChatColor(szMsg,USERCOLOR_SPELLS);
	if ((pCharInfo->Cursor->Item->LoreName[0] != '*') && (strcmp(pCharInfo->Cursor->Item->LoreName,pCharInfo->Cursor->Item->Name))) {
		sprintf(szMsg,"Lore Name: %s",pCharInfo->Cursor->Item->LoreName);
        WriteChatColor(szMsg,USERCOLOR_SPELLS);
	} else 	if ((pCharInfo->Cursor->Item->LoreName[0] == '*') && (strcmp(pCharInfo->Cursor->Item->LoreName+1,pCharInfo->Cursor->Item->Name))) {
		sprintf(szMsg,"Lore Name: %s",pCharInfo->Cursor->Item->LoreName+1);
        WriteChatColor(szMsg,USERCOLOR_SPELLS);
    }

    strcpy(szMsg,"Flags: ");
	if (pCharInfo->Cursor->Item->LoreName[0] == '*') strcat(szMsg,"LORE ");
	if (pCharInfo->Cursor->Item->NoDrop == 0) strcat(szMsg,"NODROP ");
	if (pCharInfo->Cursor->Item->NoRent == 0) strcat(szMsg,"NORENT ");
	if (pCharInfo->Cursor->Item->Type == ITEMTYPE_NORMAL) {
		if (pCharInfo->Cursor->Item->Magic == 1) strcat(szMsg,"MAGIC ");
		BYTE Light = pCharInfo->Cursor->Item->Light;
        if ((Light>0) && (Light<=LIGHT_COUNT)) {
            strcat(szMsg,"(Light: ");
            strcat(szMsg,szLights[Light]);
            strcat(szMsg,") ");
        }
    }
    if (strlen(szMsg) > 7) WriteChatColor(szMsg,USERCOLOR_SPELLS);

	if (pCharInfo->Cursor->Item->Type == ITEMTYPE_PACK) {
        CHAR szCombine[MAX_STRING] = {0};
		if ((pCharInfo->Cursor->Item->Combine < MAX_COMBINES) && (szCombineTypes[pCharInfo->Cursor->Item->Combine] != NULL)) {
			strcpy(szCombine,szCombineTypes[pCharInfo->Cursor->Item->Combine]);
        } else {
			sprintf(szCombine,"*Unknown%d",pCharInfo->Cursor->Item->Combine);
        }
		sprintf(szMsg,"Container: %d Slot %s, %d%% Reduction, Combine=%s",pCharInfo->Cursor->Item->Slots,szSize[pCharInfo->Cursor->Item->SizeCapacity],pCharInfo->Cursor->Item->WeightReduction,szCombine);
	} else if (pCharInfo->Cursor->Item->Type == ITEMTYPE_BOOK) {
//		sprintf(szMsg,"Book file: %s", pCharInfo->Cursor->Item->Book.File);
    } else {
            strcpy(szMsg,"Item: ");
			if (pCharInfo->Cursor->Item->AC) {
				sprintf(szTmp,"AC%d ",pCharInfo->Cursor->Item->AC);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->Damage) {
				sprintf(szTmp,"%dDam ",pCharInfo->Cursor->Item->Damage);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->Delay) {
				sprintf(szTmp,"%dDly ",pCharInfo->Cursor->Item->Delay);
                strcat(szMsg,szTmp);
            }
			
			if (pCharInfo->Cursor->Item->Range) {
				sprintf(szTmp,"%dRng ",pCharInfo->Cursor->Item->Range);
                strcat(szMsg,szTmp);
            }
			
			if (pCharInfo->Cursor->Item->HP) {
				sprintf(szTmp,"%dHP ",pCharInfo->Cursor->Item->HP);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->Mana) {
				sprintf(szTmp,"%dMana ",pCharInfo->Cursor->Item->Mana);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->STR) {
				sprintf(szTmp,"%dSTR ",pCharInfo->Cursor->Item->STR);
                strcat(szMsg,szTmp) ;
            }
			if (pCharInfo->Cursor->Item->STA) {
				sprintf(szTmp,"%dSTA ",pCharInfo->Cursor->Item->STA);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->DEX) {
				sprintf(szTmp,"%dDEX ",pCharInfo->Cursor->Item->DEX);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->AGI) {
				sprintf(szTmp,"%dAGI ",pCharInfo->Cursor->Item->AGI);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->WIS) {
				sprintf(szTmp,"%dWIS ",pCharInfo->Cursor->Item->WIS);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->INT) {
				sprintf(szTmp,"%dINT ",pCharInfo->Cursor->Item->INT);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->CHA) {
				sprintf(szTmp,"%dCHA ",pCharInfo->Cursor->Item->CHA);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->SvMagic) {
				sprintf(szTmp,"%dSvM ",pCharInfo->Cursor->Item->SvMagic);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->SvDisease) {
				sprintf(szTmp,"%dSvD ",pCharInfo->Cursor->Item->SvDisease);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->SvPoison) {
				sprintf(szTmp,"%dSvP ",pCharInfo->Cursor->Item->SvPoison);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->SvFire) {
				sprintf(szTmp,"%dSvF ",pCharInfo->Cursor->Item->SvFire);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->SvCold) {
				sprintf(szTmp,"%dSvC ",pCharInfo->Cursor->Item->SvCold);
                strcat(szMsg,szTmp);
            }
			if (((EQ_Item*)pCharInfo->Cursor)->IsStackable()==1) {
				sprintf(szTmp,"Stack size = %d ",pCharInfo->Cursor->StackCount);
                strcat(szMsg,szTmp);
            }
    }
    if (strlen(szMsg)>6) WriteChatColor(szMsg,USERCOLOR_SPELLS);
}


// ***************************************************************************
// Function:    Location
// Description: Our '/loc' command
//              Displays your loc and current heading...
//              on a 16 point compass (ie. NNE)
// Usage:       /loc
// ***************************************************************************
VOID Location(PSPAWNINFO pChar, PCHAR szLine)
{
    bRunNextCommand = TRUE;
    if (gFilterMacro == FILTERMACRO_NONE) cmdLocation(pChar,szLine);

    CHAR szMsg[MAX_STRING] = {0};
    INT Angle = (INT)((pChar->Heading / 32.0f) + 8.5f) % 16;
    sprintf(szMsg,"Your Location is %3.2f, %3.2f, %3.2f, and are heading %s.", pChar->Y, pChar->X, pChar->Z, szHeading[Angle]);
    WriteChatColor(szMsg,USERCOLOR_DEFAULT);
}

// ***************************************************************************
// Function:    Alert
// Description: Our '/alert' command
//              Sets up $alert notifications
// Usage:       /alert [clear #] [list #] [add # [pc|npc|corpse|any] [radius ###] [zradius ###] [race race] [class class] [range min max] [name]]
// ***************************************************************************
PALERT GetAlert(DWORD Id) {
    PALERTLIST pAlertList = gpAlertList;
    for (;pAlertList;pAlertList=pAlertList->pNext) {
        if (pAlertList->Id==Id) return (pAlertList->pAlert);
    }
    return NULL;
}

VOID AddNewAlertList(DWORD Id, PALERT pAlert)
{
    PALERTLIST pAlertList = (PALERTLIST)malloc(sizeof(ALERTLIST));
    if (!pAlertList) {
        free(pAlert);
        return;
    }
    pAlertList->Id = Id;
    pAlertList->pAlert = pAlert;
    pAlertList->pNext = gpAlertList;
    gpAlertList = pAlertList;
}

VOID FreeAlertList(PALERTLIST pAlertList)
{
    PALERT pTemp = NULL;
    while (pAlertList->pAlert) {
        pTemp = pAlertList->pAlert->pNext;
        free(pAlertList->pAlert);
        pAlertList->pAlert = pTemp;
    }
    free(pAlertList);
}

VOID FreeAlerts(DWORD List)
{
    PALERTLIST pAlertList = gpAlertList;
    PALERTLIST pTempList = NULL;
    CHAR szBuffer[MAX_STRING] = {0};
    if (gpAlertList) {
        if (gpAlertList->Id == List) {
            pTempList = gpAlertList->pNext;
            FreeAlertList(gpAlertList);
            gpAlertList = pTempList;
        } else {
            while (pAlertList) {
                pTempList = pAlertList->pNext;
                if (pTempList && (pTempList->Id == List)) {
                    pTempList = pTempList->pNext;
                    FreeAlertList(pAlertList->pNext);
                    pAlertList->pNext = pTempList;

                }
                pAlertList = pTempList;
            }
        }
    }
    sprintf(szBuffer,"Alert list %d cleared.",List);
    WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
}

PSPAWNINFO GetClosestAlert(PSPAWNINFO pChar, DWORD List, DWORD* pdwCount)
{
    CHAR szName[MAX_STRING] = {0};
    if (!ppSpawnList) return NULL;
    if (!pSpawnList) return NULL;
    PSPAWNINFO pSpawn, pClosest = NULL;
    FLOAT ClosestDistance = 50000.0f;
    PALERT pCurrent = GetAlert(List);
    if (!pCurrent) return NULL;

    for (; pCurrent; pCurrent = pCurrent->pNext) {
        if (pSpawn = SearchThroughSpawns(&(pCurrent->SearchSpawn),pChar)) {
            if (DistanceToSpawn(pChar,pSpawn)<ClosestDistance) {
                    pClosest = pSpawn;
            }
        }
    }

    return pClosest;
}

BOOL IsAlert(PSPAWNINFO pChar, PSPAWNINFO pSpawn, DWORD List)
{
    CHAR szName[MAX_STRING] = {0};
    SEARCHSPAWN SearchSpawn;
    PALERT pCurrent = GetAlert(List);
    if (!pCurrent) return NULL;

    for (; pCurrent; pCurrent = pCurrent->pNext) {
        CopyMemory(&SearchSpawn,&(pCurrent->SearchSpawn),sizeof(SEARCHSPAWN));
        if ((SearchSpawn.SpawnID>0) && (SearchSpawn.SpawnID!=pSpawn->SpawnID)) continue;
        SearchSpawn.SpawnID = pSpawn->SpawnID;
        if (SearchThroughSpawns(&SearchSpawn,pChar)) {
                return TRUE;
        }
    }
    return FALSE;
}

BOOL CheckAlertForRecursion(PALERT pAlert,DWORD AlertNumber)
{
    PALERT pNextAlert = NULL;
    if (!pAlert) return FALSE;
    for (;pAlert;pAlert=pAlert->pNext) {
        if (pAlert->SearchSpawn.bAlert) {
            if (pAlert->SearchSpawn.AlertList == AlertNumber) {
                return TRUE;
            }
            if (pNextAlert = GetAlert(pAlert->SearchSpawn.AlertList)) {
                if (CheckAlertForRecursion(pNextAlert,AlertNumber)) return TRUE;
                if (CheckAlertForRecursion(pNextAlert,pAlert->SearchSpawn.AlertList)) return TRUE;
            }
        }

        if (pAlert->SearchSpawn.bNoAlert) {
            if (pAlert->SearchSpawn.NoAlertList == AlertNumber) {
                return TRUE;
            }
            if (pNextAlert = GetAlert(pAlert->SearchSpawn.NoAlertList)) {
                if (CheckAlertForRecursion(pNextAlert,AlertNumber)) return TRUE;
                if (CheckAlertForRecursion(pNextAlert,pAlert->SearchSpawn.NoAlertList)) return TRUE;
            }
        }

        if (pAlert->SearchSpawn.bNearAlert) {
            if (pAlert->SearchSpawn.NearAlertList == AlertNumber) {
                return TRUE;
            }
            if (pNextAlert = GetAlert(pAlert->SearchSpawn.NearAlertList)) {
                if (CheckAlertForRecursion(pNextAlert,AlertNumber)) return TRUE;
                if (CheckAlertForRecursion(pNextAlert,pAlert->SearchSpawn.NearAlertList)) return TRUE;
            }
        }

        if (pAlert->SearchSpawn.bNotNearAlert) {
            if (pAlert->SearchSpawn.NotNearAlertList == AlertNumber) {
                return TRUE;
            }
            if (pNextAlert = GetAlert(pAlert->SearchSpawn.NotNearAlertList)) {
                if (CheckAlertForRecursion(pNextAlert,AlertNumber)) return TRUE;
                if (CheckAlertForRecursion(pNextAlert,pAlert->SearchSpawn.NotNearAlertList)) return TRUE;
            }
        }
    }

    return FALSE;
}

VOID Alert(PSPAWNINFO pChar, PCHAR szLine)
{
    bRunNextCommand = TRUE;
    CHAR szArg[MAX_STRING] = {0};
    CHAR szLLine[MAX_STRING] = {0};
    PCHAR szRest = szLLine;
    BOOL Parsing = TRUE;
    BOOL DidSomething = FALSE;

        // if szLLine is not referenced above by szRest
        // the compiler thinks it is not used and optimizes it out
        // don't be too tricky
        strcpy(szLLine,szLine);
        _strlwr(szLLine);

    while (Parsing) {
        if (szRest[0]==0) {
            Parsing = FALSE;
        } else {
            GetArg(szArg,szRest,1);
            szRest = GetNextArg(szRest,1);
            if (!strcmp(szArg,"clear")) {
                GetArg(szArg,szRest,1);
                FreeAlerts(atoi(szArg));
                DidSomething = TRUE;

            } else if (!strcmp(szArg,"list")) {
                PALERT pAlert = NULL;
                GetArg(szArg,szRest,1);
                szRest = GetNextArg(szRest,1);
                pAlert = GetAlert(atoi(szArg));
                if (!pAlert) {
                    WriteChatColor("No alerts active.",USERCOLOR_DEFAULT);

                } else {
                    CHAR Buffer[MAX_STRING] = {0};
                    DWORD Count=0;
                    WriteChatColor(" ",USERCOLOR_DEFAULT);
                    WriteChatColor("Current alerts:",USERCOLOR_DEFAULT);
                    while (pAlert) {
                        FormatSearchSpawn(Buffer,&(pAlert->SearchSpawn));
                        WriteChatColor(Buffer,USERCOLOR_DEFAULT);
                        Count++;
                        pAlert = pAlert->pNext;
                    }
                    sprintf(Buffer,"%d alerts listed.",Count);
                    WriteChatColor(Buffer,USERCOLOR_DEFAULT);
                }
                DidSomething = TRUE;

            } else if (!strcmp(szArg,"add")) {
                CHAR Buffer[MAX_STRING] = {0};
                CHAR szArg1[MAX_STRING] = {0};
                BOOL ParsingAdd = TRUE;
                DWORD List  = 0;
                GetArg(szArg,szRest,1);
                szRest = GetNextArg(szRest,1);
                List = atoi(szArg);
                PALERT pAlert = (PALERT)malloc(sizeof(ALERT));
                if (!pAlert) {
                    MacroError("Couldn't create alert.");
                    DebugSpew("Alert - Unable to allocate memory for new alert.");
                    return;
                }
                ZeroMemory(pAlert,sizeof(ALERT));
                ClearSearchSpawn(&(pAlert->SearchSpawn));


                while (ParsingAdd) {
                    GetArg(szArg1,szRest,1);
                    szRest = GetNextArg(szRest,1);
                    if (szArg1[0]==0) {
                        ParsingAdd = FALSE;
                    } else {
                        szRest = ParseSearchSpawnArgs(szArg1,szRest,&(pAlert->SearchSpawn));
                    }
                }

                // prev/next aren't logical in alerts
                pAlert->SearchSpawn.bTargNext = FALSE;
                pAlert->SearchSpawn.bTargPrev = FALSE;

                CHAR szTemp[MAX_STRING] = {0};
                if (CheckAlertForRecursion(pAlert, List)) {
                    sprintf(Buffer,"Alert would have cause recursion: %s",FormatSearchSpawn(szTemp,&(pAlert->SearchSpawn)));
                    free(pAlert);
                } else {
                    if (!GetAlert(List)) {
                        AddNewAlertList(List,pAlert);
                } else {
                        PALERT pTemp = GetAlert(List);
                    while (pTemp->pNext) pTemp = pTemp->pNext;
                    pTemp->pNext = pAlert;
                }
                    sprintf(Buffer,"Added alert for: %s",FormatSearchSpawn(szTemp,&(pAlert->SearchSpawn)));
                }
                DebugSpew("Alert - %s",Buffer);
                WriteChatColor(Buffer,USERCOLOR_DEFAULT);
                DidSomething = TRUE;
            }
        }
    }
    if (!DidSomething) {
        SyntaxError("Usage: /alert [clear #] [list #] [add # [pc|npc|corpse|any] [radius radius] [zradius radius] [range min max] spawn]");
    }
}


// ***************************************************************************
// Function:    CleanupName
// Description: Cleans up NPC names
//              an_iksar_marauder23 = iksar marauder, an
// ***************************************************************************
PCHAR CleanupName(PCHAR szName, BOOL Article, BOOL ForWhoList)
{
    DWORD i,j=0;
    CHAR szTemp[MAX_STRING] = {0};
    for (i=0;i<strlen(szName);i++) {
        switch (szName[i]) {
            case '_':
                szTemp[j++]=' ';
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                break;
			case '#':
				if (!ForWhoList)
					break;
            default:
                szTemp[j++]=szName[i];
        }
    }
    strcpy(szName,szTemp);

    if (!Article) return szName;

    if (!strnicmp(szName,"a ",2)) {
        sprintf(szTemp, "%s, a",szName+2);
        strcpy(szName,szTemp);
    } else if (!strnicmp(szName,"an ",3)) {
        sprintf(szTemp, "%s, an",szName+3);
        strcpy(szName,szTemp);
    } else if (!strnicmp(szName,"the ",4)) {
        sprintf(szTemp, "%s, the",szName+4);
        strcpy(szName,szTemp);
    }

    return szName;
}

// ***************************************************************************
// Function:    SuperWhoDisplay
// Description: Displays our SuperWho / SuperWhoTarget
// ***************************************************************************
VOID SuperWhoDisplay(PSPAWNINFO pSpawn, DWORD Color)
{
	CHAR szName[MAX_STRING]={0};
	CHAR szMsg[MAX_STRING]={0};
	CHAR szMsgL[MAX_STRING]={0};
	CHAR szTemp[MAX_STRING]={0};
        strcpy(szName,pSpawn->Name);
        if (pSpawn->Type == SPAWN_PLAYER) {
            if (gFilterSWho.Lastname && strlen(pSpawn->Lastname)>0) {
                strcat(szName," ");
                strcat(szName,pSpawn->Lastname);
            }
            if (gFilterSWho.Guild && pSpawn->GuildID < MAX_GUILDS && pGuildList) {
                strcat(szName," <");
                strcat(szName,GetGuildByID(pSpawn->GuildID));
                strcat(szName,">");
            }
        } else {
            CleanupName(szName);
            if (gFilterSWho.Lastname && strlen(pSpawn->Lastname)>0) {
                strcat(szName," (");
                strcat(szName,pSpawn->Lastname);
                strcat(szName,")");
            }
        }
        CHAR GM[MAX_STRING] = {0};

		if (gFilterSWho.GM && pSpawn->GM) {
            if (pSpawn->Level >= 50) {
                strcpy(GM,"\ay*GM*\ax");
			} else if (pSpawn->Level == 20) {
                strcpy(GM,"\a-y*Guide Applicant*\ax");
            } else {
                strcpy(GM,"\a-y*Guide*\ax");
            }
        }

		szMsg[0]='\a';
		szMsg[2]=0;
		if (Color || gFilterSWho.ConColor)
		{
			switch(ConColor(pSpawn))
			{
			case CONCOLOR_BLACK:
				szMsg[1]='w';
				break;
			case CONCOLOR_YELLOW:
				szMsg[1]='y';
				break;
			case CONCOLOR_RED:
				szMsg[1]='r';
				break;
			case CONCOLOR_BLUE:
				szMsg[1]='u';
				break;
			case CONCOLOR_LIGHTBLUE:
				szMsg[1]='t';
				break;
			case CONCOLOR_GREEN:
				szMsg[1]='g';
				break;
			default:
				szMsg[1]='m';
				break;
			}
		}
		else
		{
			szMsg[1]='w';
		}
		if (gFilterSWho.GM) strcat(szMsg,GM);
		if (gFilterSWho.Level || gFilterSWho.Race || gFilterSWho.Body || gFilterSWho.Class) {
			strcat(szMsg,"\a-u[\ax");
			if (gFilterSWho.Level) {
				itoa(pSpawn->Level,szTemp,10);
				strcat(szMsg,szTemp);
				strcat(szMsg," ");
			}
			if (gFilterSWho.Race) {
				strcat(szMsg,pEverQuest->GetRaceDesc(pSpawn->Race));
				strcat(szMsg," ");
			}
			if (gFilterSWho.Body) {
				strcat(szMsg,GetBodyTypeDesc(pSpawn->BodyType));
				strcat(szMsg," ");
			}
			if (gFilterSWho.Class) {
				strcat(szMsg,GetClassDesc(pSpawn->Class));
				strcat(szMsg," ");
			}
			szMsg[strlen(szMsg)-1]=0;
			strcat(szMsg,"\a-u]\ax");
		}
		strcat(szMsg," ");
		strcat(szMsg,szName);
//		strcat(szMsg,"\ax");
		
        if (pSpawn->Type == SPAWN_PLAYER) {
            if (gFilterSWho.Anon && pSpawn->Anon>0) {
                if (pSpawn->Anon==2) {
                    strcat(szMsg," \ag*RP*\ax");
                } else {
                    strcat(szMsg," \ag*Anon*\ax");
                }
            }
            if (gFilterSWho.LD && pSpawn->Linkdead) strcat(szMsg," \ag<LD>\ax");
			if (gFilterSWho.Sneak && pSpawn->Sneak) strcat(szMsg," \ag<Sneak>\ax"); 
            if (gFilterSWho.AFK && pSpawn->AFK) strcat(szMsg," \ag<AFK>\ax");
            if (gFilterSWho.LFG && pSpawn->LFG) strcat(szMsg," \ag<LFG>\ax");
            if (gFilterSWho.Trader && pSpawn->pActorInfo->Trader) strcat(szMsg," \ag<Trader>\ax");
        } else if (gFilterSWho.NPCTag && pSpawn->Type == SPAWN_NPC) {
            if (pSpawn->MasterID != 0) {
                strcat(szMsg," <PET>");
            } else {
                strcat(szMsg," <NPC>");
            }
        }
		if (gFilterSWho.Light) {
			PCHAR szLight = GetLightForSpawn(pSpawn);
			if (stricmp(szLight,"NONE")) {
				strcat(szMsg," (");
				strcat(szMsg,szLight);
				strcat(szMsg,")");
			}
		}
        strcpy(szMsgL,szMsg);
		if (gFilterSWho.Distance) 
		{
	        INT Angle = (INT)((atan2f(GetCharInfo()->pSpawn->X - pSpawn->X, GetCharInfo()->pSpawn->Y - pSpawn->Y) * 180.0f / PI + 360.0f) / 22.5f + 0.5f) % 16;
			sprintf(szTemp," \a-u(\ax%1.2f %s\a-u,\ax %1.2fZ\a-u)\ax", GetDistance(GetCharInfo()->pSpawn,pSpawn), szHeadingShort[Angle], pSpawn->Z-GetCharInfo()->pSpawn->Z);
			strcat(szMsg,szTemp);
		}
		if (gFilterSWho.SpawnID) 
		{
			strcat(szMsg," \a-u(\axID:");
			itoa(pSpawn->SpawnID,szTemp,10);
			strcat(szMsg,szTemp);
			strcat(szMsg,"\a-u)\ax");
        }
		if (gFilterSWho.Holding && (pSpawn->Equipment.Primary || pSpawn->Equipment.Offhand )) 
		{
			strcat(szMsg," \a-u(\ax");
			if (pSpawn->Equipment.Primary)
			{
				itoa(pSpawn->Equipment.Primary,szTemp,10);
				strcat(szMsg,"Pri: ");
				strcat(szMsg,szTemp);
				if (pSpawn->Equipment.Offhand)
					strcat(szMsg," ");
			}
			if (pSpawn->Equipment.Offhand)
			{
				itoa(pSpawn->Equipment.Offhand,szTemp,10);
				strcat(szMsg,"Off: ");
				strcat(szMsg,szTemp);
			}
			strcat(szMsg,"\a-u)\ax");
		}

		switch(GetSpawnType(pSpawn))
		{
		case CHEST:
			strcat(szMsg," \ar*CHEST*\ax");
			break;
		case TRAP:
			strcat(szMsg," \ar*TRAP*\ax");
			break;
		case TRIGGER:
			strcat(szMsg," \ar*TRIGGER*\ax");
			break;
		case TIMER:
			strcat(szMsg," \ar*TIMER*\ax");
			break;
		case UNTARGETABLE:
			strcat(szMsg," \ar*UNTARGETABLE*\ax");
			break;
		}

	WriteChatColor(szMsg,USERCOLOR_WHO);
}

DWORD SWhoSortValue=0;
PSPAWNINFO SWhoSortOrigin=0;

static int pWHOSORTCompare(const void *A, const void *B)
{
	PSPAWNINFO SpawnA=*(PSPAWNINFO*)A;
	PSPAWNINFO SpawnB=*(PSPAWNINFO*)B;
	switch(SWhoSortValue)
	{
	/*
			PCHAR szSortBy[] = { 
				"level",   // Default sort by 
				"name", 
				"race", 
				"class", 
				"distance", 
				"guild", 
				"id", 
				NULL }; 
	/**/
	case 0://level
		if (SpawnA->Level>SpawnB->Level)
			return 1;
		if (SpawnA->Level<SpawnB->Level)
			return -1;
		break;
//	case 1://name   done at the bottom ;)
//		break;
	case 2://race
		{
			int RaceCompare=stricmp(pEverQuest->GetRaceDesc(SpawnA->Race),pEverQuest->GetRaceDesc(SpawnB->Race));
			if (RaceCompare)
				return RaceCompare;
		}
		break;
	case 3://class
		{
			int ClassCompare=stricmp(GetClassDesc(SpawnA->Class),GetClassDesc(SpawnB->Class));
			if (ClassCompare)
				return ClassCompare;
		}
		break;
	case 4://distance
		{
			FLOAT DistA=GetDistance(SWhoSortOrigin,SpawnA);
			FLOAT DistB=GetDistance(SWhoSortOrigin,SpawnB);
			if (DistA>DistB)
				return 1;
			if (DistA<DistB)
				return -1;
		}
		break;
	case 5://guild
		{
			int GuildCompare=stricmp(GetGuildByID(SpawnA->GuildID),GetGuildByID(SpawnB->GuildID));
			if (GuildCompare)
				return GuildCompare;
		}
		break;
	case 6://id
		if (SpawnA->SpawnID>SpawnB->SpawnID)
			return 1;
		if (SpawnA->SpawnID<SpawnB->SpawnID)
			return -1;
		break;
	}
	CHAR szNameA[MAX_STRING]={0};
	CHAR szNameB[MAX_STRING]={0};
	CleanupName(strcpy(szNameA,SpawnA->Name));
	CleanupName(strcpy(szNameB,SpawnB->Name));
	return stricmp(szNameA,szNameB);
}

VOID SuperWhoDisplay(PSPAWNINFO pChar, PSEARCHSPAWN pSearchSpawn, DWORD Color)
{
	if (!pSearchSpawn)
		return;
	CIndex<PSPAWNINFO> SpawnSet;
	PSPAWNINFO pSpawn=(PSPAWNINFO)pSpawnList;
	PSPAWNINFO pOrigin;
	// create our set
	DWORD TotalMatching=0;
	if (pSearchSpawn->FromSpawnID)
		pOrigin=(PSPAWNINFO)GetSpawnByID(pSearchSpawn->FromSpawnID);
	if (!pOrigin)
		pOrigin=pChar;
	while (pSpawn)
	{
		if (SpawnMatchesSearch(pSearchSpawn,pOrigin,pSpawn))
		{
			// matches search, add to our set
			TotalMatching++;
			SpawnSet+=pSpawn;
		}

		pSpawn=pSpawn->pNext;
	}
	if (TotalMatching)
	{
		if (TotalMatching>1)
		{
			// sort our list
			SWhoSortValue=pSearchSpawn->SortBy;
			SWhoSortOrigin=pOrigin;
			qsort(&SpawnSet.List[0],TotalMatching,sizeof(PSPAWNINFO),pWHOSORTCompare);
		}

		WriteChatColor("List of matching spawns",USERCOLOR_WHO);
        WriteChatColor("--------------------------------",USERCOLOR_WHO);
		for (DWORD N=0 ; N < TotalMatching ; N++)
		{
			SuperWhoDisplay(SpawnSet[N],Color);
		}
		PCHAR pszSpawnType;
		switch(pSearchSpawn->SpawnType)
		{
		case NONE:
		default:
			pszSpawnType="any";
			break;
		case PC:
			pszSpawnType="pc";
			break;
		case MOUNT:
			pszSpawnType="mount";
			break;
		case PET:
			pszSpawnType="pet";
			break;
		case NPC:
			pszSpawnType="npc";
			break;
		case CORPSE:
			pszSpawnType="corpse";
			break;
		case TRIGGER:
			pszSpawnType="trigger";
			break;
		case TRAP:
			pszSpawnType="trap";
			break;
		case CHEST:
			pszSpawnType="chest";
			break;
		case TIMER:
			pszSpawnType="timer";
			break;
		case UNTARGETABLE:
			pszSpawnType="untargetable";
			break;
		}
		WriteChatf("There %s \ag%d\ax %s%s in %s.",(TotalMatching == 1)?"is":"are",TotalMatching, pszSpawnType, (TotalMatching==1)?"":"s", GetFullZone(pChar->Zone));

	}
	else
	{
		WriteChatColor("List of matching spawns",USERCOLOR_WHO);
        WriteChatColor("--------------------------------",USERCOLOR_WHO);
		CHAR szMsg[MAX_STRING]={0};
		FormatSearchSpawn(szMsg,pSearchSpawn);
		strcat(szMsg," was not found.");
		WriteChatColor(szMsg,USERCOLOR_WHO);
	}
}

// ***************************************************************************
// Function:    SuperWhoTarget
// Description: Our '/whotarget' command
//              Displays spawn currently selected
// Usage:       /whotarget
// ***************************************************************************
VOID SuperWhoTarget(PSPAWNINFO pChar, PCHAR szLine)
{
    PSPAWNINFO psTarget = NULL;
    bRunNextCommand = TRUE;
    if (gFilterMacro == FILTERMACRO_NONE) cmdWhoTarget(pChar, szLine);

    if (ppTarget && pTarget) {
        psTarget = (PSPAWNINFO)pTarget;
    }

	

    if (!psTarget) {
		MacroError("You must have a target selected for /whotarget.");
        return;
    }
    DebugSpew("SuperWhoTarget - %s",psTarget->Name);
	BOOL Temp=gFilterSWho.Distance;
	gFilterSWho.Distance=TRUE;
	SuperWhoDisplay(psTarget,USERCOLOR_WHO);
	gFilterSWho.Distance=Temp;
//    SuperWhoDisplay(pChar,NULL,psTarget,0,TRUE);
}

// ***************************************************************************
// Function:    SuperWho
// Description: Our '/who' command
//              Displays a list of spawns in the zone
// Usage:       /who <search string>
// ***************************************************************************
VOID SuperWho(PSPAWNINFO pChar, PCHAR szLine)
{
    bRunNextCommand = TRUE;
    CHAR szLLine[MAX_STRING] = {0};
    CHAR szArg[MAX_STRING] = {0};
    PCHAR szRest = szLLine;
    BOOL Parsing = TRUE;
	BOOL bConColor=0;
    SEARCHSPAWN SearchSpawn;

    _strlwr(strcpy(szLLine,szLine));
    ClearSearchSpawn(&SearchSpawn);
    SearchSpawn.SpawnType = PC;


    if ((!stricmp(szLine,"all")) ||
        (!strnicmp(szLine,"all ",4)) ||
        (!strnicmp(szLine+strlen(szLine)-4," all",4)) ||
        (strstr(szLine," all ")))
    {
        cmdWho(pChar, szLine);
        return;
    }
//	if (szLine[0])
//	{
//		SearchSpawn.bTargInvis=true;
//	}

    while (Parsing) {
        GetArg(szArg,szRest,1);
        szRest = GetNextArg(szRest,1);
        if (szArg[0]==0) {
            Parsing=FALSE;
		} else if (!strcmp(szArg,"sort")) { 
			GetArg(szArg,szRest,1); 
			//  <name|level|distance|race|class|guild|id> 
			PCHAR szSortBy[] = { 
				"level",   // Default sort by 
				"name", 
				"race", 
				"class", 
				"distance", 
				"guild", 
				"id", 
				NULL }; 
			DWORD Command=0; 

			for (Command;szSortBy[Command];Command++) { 
				if (!strcmp(szArg,szSortBy[Command])) { 
					SearchSpawn.SortBy = Command; 
					szRest = GetNextArg(szRest,1); 
					break; 
				}
			}
        } 
		else if (!strcmp(szArg,"concolor")) {
			bConColor=1;
		}
		else {
            szRest = ParseSearchSpawnArgs(szArg,szRest,&SearchSpawn);
        }
    }

    DebugSpew("SuperWho - filtering %s",SearchSpawn.szName);
	SuperWhoDisplay(pChar,&SearchSpawn,bConColor);
    //SuperWhoDisplay(pChar, &SearchSpawn,0,0,bConColor);

}

// ***************************************************************************
// Function:    SetError
// Description: Our '/seterror' command
// Usage:       /seterror <clear|errormsg>
// ***************************************************************************

VOID SetError(PSPAWNINFO pChar, PCHAR szLine)
{
    bRunNextCommand = TRUE;
    if ((szLine[0]==0) || (stricmp(szLine,"clear"))) {
        gszLastNormalError[0]=0; // QUIT SETTING THIS MANUALLY, USE MacroError or FatalError!
    } else {
        strcpy(gszLastNormalError,szLine);
    }
}
/**/

// ***************************************************************************
// Function:    MQMsgBox
// Description: Our '/msgbox' command
//              Our message box
// Usage:       /msgbox text
// ***************************************************************************
DWORD WINAPI thrMsgBox(LPVOID lpParameter)
{
    MessageBox(NULL,(PCHAR)lpParameter,"MacroQuest",MB_OK);
    free(lpParameter);
    return 0;
}

VOID MQMsgBox(PSPAWNINFO pChar, PCHAR szLine)
{
    FILE *fOut = NULL;
    CHAR szBuffer[MAX_STRING] = {0};
    DWORD i;
    bRunNextCommand = TRUE;

    sprintf(szBuffer, "$date() $time()\r\n%s",szLine);
    ParseMacroParameter(pChar,szBuffer);

    CreateThread(NULL,0,thrMsgBox,strdup(szBuffer),0,&i);
}


// ***************************************************************************
// Function:    MacroLog
// Description: Our '/mqlog' command
//              Our logging
// Usage:       /mqlog text
// ***************************************************************************
VOID MacroLog(PSPAWNINFO pChar, PCHAR szLine)
{
    FILE *fOut = NULL;
    CHAR Filename[MAX_STRING] = {0};
    CHAR szBuffer[MAX_STRING] = {0};
    DWORD i;
    bRunNextCommand = TRUE;

    if (gszMacroName[0]==0) {
        sprintf(Filename,"%s\\MacroQuest.log",gszLogPath);
    } else {
        sprintf(Filename,"%s\\%s.log",gszLogPath, gszMacroName);
    }

    for (i=0;i<strlen(Filename);i++) {
        if (Filename[i]=='\\') {
            strncpy(szBuffer,Filename,i);
            if (2 == _mkdir(szBuffer)) {
				MacroError("Log path doesn't appear valid: %s",Filename);
                return;
            }
        }
    }
    if (!stricmp(szLine,"clear")) {
        fOut = fopen(Filename,"wt");
        if (!fOut) {
            MacroError("Couldn't open log file: %s",Filename);
            return;
        }
        WriteChatColor("Cleared log.",USERCOLOR_DEFAULT);
        fclose(fOut);
        return;
    }

    fOut = fopen(Filename,"at");
    if (!fOut) {
        MacroError("Couldn't open log file: %s",Filename);
        return;
    }

	sprintf(szBuffer, "[${Time.Date} ${Time.Time24}] %s",szLine);
    ParseMacroParameter(pChar,szBuffer);
    fprintf(fOut,"%s\n", szBuffer);
    DebugSpew("MacroLog - %s", szBuffer);

    fclose(fOut);

}


// ***************************************************************************
// Function:    Face
// Description: Our '/face' command
//              Faces the direction to a spawn
// Usage:       /face <spawn>
// Usage:       /face loc <y>,<x>
// ***************************************************************************
FLOAT StateHeightMultiplier(DWORD StandState) 
{ 
   switch (StandState) { 
      case STANDSTATE_BIND: 
      case STANDSTATE_DUCK: 
         return 0.5f; 
      case STANDSTATE_SIT: 
         return 0.3f; 
      case STANDSTATE_FEIGN: 
      case STANDSTATE_DEAD: 
         return 0.1f; 
      case STANDSTATE_STAND: 
      default: 
         return 0.9f; 
   } 
} 

VOID Face(PSPAWNINFO pChar, PCHAR szLine)
{
    if (!ppSpawnList) return;
    if (!pSpawnList) return;
    PSPAWNINFO pSpawnClosest = NULL;
    PSPAWNINFO psTarget = NULL;
    SPAWNINFO LocSpawn = {0};
    SEARCHSPAWN SearchSpawn;
    ClearSearchSpawn(&SearchSpawn);
    CHAR szMsg[MAX_STRING] = {0};
    CHAR szName[MAX_STRING] = {0};
    CHAR szArg[MAX_STRING] = {0};
    CHAR szLLine[MAX_STRING] = {0};
    PCHAR szFilter = szLLine;
    BOOL bArg = TRUE;
    BOOL bOtherArgs = FALSE;
    BOOL Away = FALSE;
    BOOL Predict = FALSE;
    BOOL Fast = FALSE;
    BOOL Look = TRUE;
    BOOL Parsing = TRUE;
    DOUBLE Distance;
	bRunNextCommand=FALSE;

    _strlwr(strcpy(szLLine,szLine));
    while (bArg) {
        GetArg(szArg,szFilter,1);
        szFilter = GetNextArg(szFilter,1);
        if (szArg[0]==0) {
            bArg = FALSE;
        } else if (!strcmp(szArg,"predict")) {
            Predict=TRUE;
        } else if (!strcmp(szArg,"fast")) {
            Fast = TRUE;
        } else if (!strcmp(szArg,"away")) {
            Away = TRUE;
        } else if (!strcmp(szArg,"nolook")) {
            Look = FALSE;
        } else if (!stricmp(szArg, "loc")) {
        pSpawnClosest = &LocSpawn;
        strcpy(LocSpawn.Name,"location");
            if ((szFilter[0]==0) || (!strstr(szFilter,","))) {
            MacroError("Face: loc specified but <y>,<x> not found.");
            return;
        }
            pSpawnClosest->Y = (FLOAT)atof(szFilter);
            while ((szFilter[0]!=',') && (szFilter[0]!=0)) szFilter++;
            if (szFilter[0]==0) {
            MacroError("Face: loc specified but <y>,<x> not found.");
            return;
        }
            szFilter++;
            pSpawnClosest->X = (FLOAT)atof(szFilter);
        } else if (!stricmp(szArg, "item")) {
        if (EnviroTarget.Name[0]==0) {
            MacroError("Face: item specified but no item targetted.");
            return;
        }
        pSpawnClosest = &EnviroTarget;
        } else if (!stricmp(szArg, "door")) {
        if (DoorEnviroTarget.Name[0]==0) {
            MacroError("Face: door specified but no door targetted.");
            return;
        }
        pSpawnClosest = &DoorEnviroTarget;
        } else if (!stricmp(szArg, "heading")) {
            if (szFilter[0]==0) {
                MacroError("Face: heading specified but angle not found.");
    } else {
                FLOAT Heading = (FLOAT)(atof(szFilter));
                gFaceAngle = Heading/0.703125f;
                if (gFaceAngle>=512.0f) gFaceAngle -= 512.0f;
                if (gFaceAngle<0.0f) gFaceAngle += 512.0f;
                if (Fast) {
					((PSPAWNINFO)pCharSpawn)->Heading = (FLOAT)gFaceAngle;
                    gFaceAngle=10000.0f;
                    bRunNextCommand = TRUE;
                    }
                }
            return;
        } else if (!strcmp(szArg,"help")) {
            SyntaxError("Usage: /face [spawn] [item] [door] [id #] [heading <ang>] [loc <y>,<x>] [away] [alert #]");
            bRunNextCommand = TRUE;
            return;
        } else {
            bOtherArgs = TRUE;
            szFilter = ParseSearchSpawnArgs(szArg,szFilter,&SearchSpawn);
        }
            }

    if (!pSpawnClosest) {
    if (!bOtherArgs) {
        if (ppTarget && pTarget) {
            pSpawnClosest = (PSPAWNINFO)pTarget;
        }
    } else {
            pSpawnClosest = SearchThroughSpawns(&SearchSpawn,pChar);
        }
    }

	szMsg[0]=0;

    if (!pSpawnClosest) {
        MacroError("There were no matches for: %s",FormatSearchSpawn(szArg,&SearchSpawn));
    } else {
        if (Predict) {
            Distance = DistanceToSpawn(pChar, pSpawnClosest);
            gFaceAngle = (
                atan2((pSpawnClosest->X + (pSpawnClosest->SpeedX * Distance)) - pChar->X,
                       (pSpawnClosest->Y + (pSpawnClosest->SpeedY * Distance)) - pChar->Y)
                * 256.0f / PI);
        } else {
            gFaceAngle = (
                atan2(pSpawnClosest->X - pChar->X,
                       pSpawnClosest->Y - pChar->Y)
                * 256.0f / PI);
        }
        if (Look) {
            Distance = DistanceToSpawn(pChar, pSpawnClosest);
            gLookAngle = (
                atan2(pSpawnClosest->Z + pSpawnClosest->AvatarHeight*StateHeightMultiplier(pSpawnClosest->StandState) - pChar->Z - pChar->AvatarHeight*StateHeightMultiplier(pChar->StandState), 
                    (FLOAT)Distance) 
                * 256.0f / PI);
            if (Away) gLookAngle = -gLookAngle;
            if (Fast) {
                pChar->CameraAngle = (FLOAT)gLookAngle;
                gLookAngle=10000.0f;
            }
        }
        if (Away) {
            gFaceAngle += 256.0f;
        }
        if (gFaceAngle>=512.0f) gFaceAngle -= 512.0f;
        if (gFaceAngle<0.0f) gFaceAngle += 512.0f;
        if (Fast) {
            ((PSPAWNINFO)pCharSpawn)->Heading = (FLOAT)gFaceAngle;
            gFaceAngle=10000.0f;
            bRunNextCommand = TRUE;
        }
        sprintf(szMsg,"Facing %s'%s'...",(Away)?"away from ":"", CleanupName(strcpy(szName,pSpawnClosest->Name),FALSE));
    }
    if (ppTarget && pTarget) {
        psTarget = (PSPAWNINFO)pTarget;
    }
    if (szMsg[0] && ((pSpawnClosest != &LocSpawn) && ((Away) || (pSpawnClosest != psTarget)))) WriteChatColor(szMsg,USERCOLOR_WHO);
    DebugSpew("Face - %s",szMsg);
    return;
}


// ***************************************************************************
// Function:      Look
// Description:      Our /look command. Changes camera angle
// 2003-08-30      MacroFiend
// ***************************************************************************
VOID Look(PSPAWNINFO pChar, PCHAR szLine)
{
   CHAR szLookAngle[MAX_STRING]={0};
   CHAR szTemp[MAX_STRING]={0};
   FLOAT fLookAngle=0.0f;

   GetArg(szLookAngle,szLine,1);


   fLookAngle = (FLOAT)atof(szLookAngle);

   if (fLookAngle>128.0f || fLookAngle<-128.0f) {
      MacroError("/look -- Angle %f out of range.",fLookAngle);
      return;
   }

   pChar->CameraAngle = fLookAngle;
	gLookAngle = 10000.0f;
}


// ***************************************************************************
// Function:    Where
// Description: Our '/where' command
//              Displays the direction and distance to the closest spawn
// Usage:       /where <spawn>
// ***************************************************************************
VOID Where(PSPAWNINFO pChar, PCHAR szLine)
{
    if (!ppSpawnList) return;
    if (!pSpawnList) return;
    PSPAWNINFO pSpawnClosest = NULL;
    SEARCHSPAWN SearchSpawn;
    ClearSearchSpawn(&SearchSpawn);
    CHAR szMsg[MAX_STRING] = {0};
    CHAR szName[MAX_STRING] = {0};
    CHAR szArg[MAX_STRING] = {0};
    CHAR szLLine[MAX_STRING] = {0};
    PCHAR szFilter = szLLine;
    BOOL bArg = TRUE;
    bRunNextCommand = TRUE;

        _strlwr(strcpy(szLLine,szLine));

    while (bArg) {
        GetArg(szArg,szFilter,1);
        szFilter = GetNextArg(szFilter,1);
        if (szArg[0]==0) {
            bArg = FALSE;
            } else {
            szFilter = ParseSearchSpawnArgs(szArg,szFilter,&SearchSpawn);
            }
        }


    if (!(pSpawnClosest = SearchThroughSpawns(&SearchSpawn,pChar))) {
        sprintf(szMsg,"There were no matches for: %s",FormatSearchSpawn(szArg,&SearchSpawn));
    } else {
        INT Angle = (INT)((atan2f(pChar->X - pSpawnClosest->X, pChar->Y - pSpawnClosest->Y) * 180.0f / PI + 360.0f) / 22.5f + 0.5f) % 16;
        sprintf(szMsg,"The closest '%s' is a level %d %s %s and %1.2f away to the %s, Z difference = %1.2f",
            CleanupName(strcpy(szName,pSpawnClosest->Name),FALSE),
            pSpawnClosest->Level,
            pEverQuest->GetRaceDesc(pSpawnClosest->Race),
            GetClassDesc(pSpawnClosest->Class),
            DistanceToSpawn(pChar,pSpawnClosest),
            szHeading[Angle],
            pSpawnClosest->Z-pChar->Z);
        DebugSpew("Where - %s",szMsg);
    }
    WriteChatColor(szMsg,USERCOLOR_WHO);
    return;
}


// ***************************************************************************
// Function:    DoAbility
// Description: Our '/doability' command
//              Does (or lists) your abilities
// Usage:       /doability [list|ability|#]
// ***************************************************************************
VOID DoAbility(PSPAWNINFO pChar, PCHAR szLine)
{
    if (!cmdDoAbility) return;

    if (szLine[0]==0 || atoi(szLine) || !EQADDR_DOABILITYLIST) {
        cmdDoAbility(pChar,szLine);
        return;
    }

    DWORD Index, DoIndex = 0xFFFFFFFF;
    CHAR szBuffer[MAX_STRING] = {0};

    GetArg(szBuffer,szLine,1);

    if (!stricmp(szBuffer,"list")) {
        WriteChatColor("Abilities:",USERCOLOR_DEFAULT);
        for (Index=4;Index<10;Index++) {
            if (EQADDR_DOABILITYLIST[Index]==0xFFFFFFFF) {
                sprintf(szBuffer,"%d. <Empty>",Index-3);
            } else if (szSkills[EQADDR_DOABILITYLIST[Index]]) {
                sprintf(szBuffer,"%d. %s",Index-3,szSkills[EQADDR_DOABILITYLIST[Index]]);
            } else {
                sprintf(szBuffer,"%d. *Unknown%d",Index-3,EQADDR_DOABILITYLIST[Index]);
            }
            WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
        }
        WriteChatColor("Combat Skills:",USERCOLOR_DEFAULT);
        for (Index=0;Index<4;Index++) {
            if (EQADDR_DOABILITYLIST[Index]==0xFFFFFFFF) {
                sprintf(szBuffer,"%d. <Empty>",Index+7);
            } else if (szSkills[EQADDR_DOABILITYLIST[Index]]) {
                sprintf(szBuffer,"%d. %s",Index+7,szSkills[EQADDR_DOABILITYLIST[Index]]);
            } else {
                sprintf(szBuffer,"%d. *Unknown%d",Index+7,EQADDR_DOABILITYLIST[Index]);
            }
            WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
        }
        WriteChatColor("Combat Abiilities:",USERCOLOR_DEFAULT);
        for (Index=10;Index<18;Index++) {
            if (EQADDR_DOABILITYLIST[Index]==0xFFFFFFFF) {
                sprintf(szBuffer,"%d. <Empty>",Index+1);
			} else if (EQADDR_DOABILITYLIST[Index] > 132) { // highest number we have defined so far
				sprintf(szBuffer,"%d. *Unknown%d",Index+1,EQADDR_DOABILITYLIST[Index]);
            } else if (szSkills[EQADDR_DOABILITYLIST[Index]]) {
                sprintf(szBuffer,"%d. %s",Index+1,szSkills[EQADDR_DOABILITYLIST[Index]]);
            } else {
                sprintf(szBuffer,"%d. *Unknown%d",Index+1,EQADDR_DOABILITYLIST[Index]);
            }
            WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
        }


        return;
    }

    for (Index=0;Index<10;Index++) {
        if (EQADDR_DOABILITYLIST[Index]!= 0xFFFFFFFF) {
            if (!strnicmp(szBuffer,szSkills[EQADDR_DOABILITYLIST[Index]],strlen(szSkills[EQADDR_DOABILITYLIST[Index]]))) {
                if (Index<4) {
                    DoIndex = Index+7; // 0-3 = Combat abilities (7-10)
                } else {
                    DoIndex = Index-3; // 4-9 = Abilities (1-6)
                }
            }
        }
    }
    if (DoIndex!=0xFFFFFFFF) {
        cmdDoAbility(pChar,itoa(DoIndex,szBuffer,10));
    } else {
        WriteChatColor("You do not seem to have that ability on a /doability button",USERCOLOR_DEFAULT);
    }
}

// ***************************************************************************
// Function:    LoadSpells
// Description: Our '/loadspells' command
//              Loads (or lists) a spell favorite list
// Usage:       /loadspells [list|"name"]
// ***************************************************************************
DWORD FindSpellListByName(PCHAR szName)
{
    DWORD Index;
    for (Index=0;Index<10;Index++) {
        if (!stricmp(pSpellSets[Index].Name,szName)) return Index;
    }
    return -1;
}

VOID LoadSpells(PSPAWNINFO pChar, PCHAR szLine) 
{ 
    if (!pSpellSets || !ppSpellBookWnd || szLine[0]==0) return; 

    DWORD Index, DoIndex = 0xFFFFFFFF; 
    CHAR szArg1[MAX_STRING] = {0}; 
    CHAR szArg2[MAX_STRING] = {0}; 
    CHAR szBuffer[MAX_STRING] = {0}; 

    if (!pSpellBookWnd) return; 

    GetArg(szArg1,szLine,1); 
    GetArg(szArg2,szLine,2); 

    if ((!stricmp(szArg1,"list")) && (szArg2[0]==0)) { 
        WriteChatColor("Spell favorites list:",USERCOLOR_DEFAULT); 
        WriteChatColor("--------------------------",USERCOLOR_DEFAULT); 
        for (Index=0;Index<10;Index++) { 
            if (pSpellSets[Index].Name[0]!=0) { 
            sprintf(szBuffer,"%d) %s",Index,pSpellSets[Index].Name); 
                WriteChatColor(szBuffer,USERCOLOR_DEFAULT); 
            } 
        } 
        return; 
    } 

    if (!stricmp(szArg1,"list")) { 

        DoIndex = IsNumber(szArg2)?atoi(szArg2):FindSpellListByName(szArg2); 
        if (DoIndex < 0 || DoIndex > 9) { 
            sprintf(szBuffer,"Unable to find favorite list '%s'",szArg2); 
            WriteChatColor(szBuffer,USERCOLOR_DEFAULT); 
            return; 
        } 
        sprintf(szBuffer,"Favorite list '%s':",pSpellSets[DoIndex].Name); 
        WriteChatColor(szBuffer,USERCOLOR_DEFAULT); 
        for (Index=0;Index<9;Index++) { 
            if (pSpellSets[DoIndex].SpellId[Index]!=0xFFFFFFFF) { 
                sprintf(szBuffer,"%d) %s",Index,GetSpellByID(pSpellSets[DoIndex].SpellId[Index])->Name ); 
                WriteChatColor(szBuffer,USERCOLOR_DEFAULT); 
            } 
        } 
        return; 
    } 

   DoIndex = IsNumber(szArg1)?atoi(szArg1):FindSpellListByName(szArg1); 
    if (DoIndex >= 0 && DoIndex <=9) { 
      pSpellBookWnd->MemorizeSet((int*)&pSpellSets[DoIndex],9); 
    } else { 
        sprintf(szBuffer,"Unable to find favorite list '%s'",szArg1); 
        WriteChatColor(szBuffer,USERCOLOR_DEFAULT); 
    } 
} 



// ***************************************************************************
// Function:    Cast
// Description: Our '/cast' command
// Usage:       /cast [list|#|"name of spell"|item "name of item"]
// ***************************************************************************
VOID Cast(PSPAWNINFO pChar, PCHAR szLine)
{
   if (!cmdCast) return;

   if (szLine[0]==0 || atoi(szLine) || !ppSpellMgr || !ppCharData || !pCharData) {
      cmdCast(pChar,szLine);
      return;
   }
   PCHARINFO pCharInfo = GetCharInfo();
   if (NULL == pCharInfo) return;
   DWORD Index;
   CHAR szBuffer[MAX_STRING] = {0};
   CHAR szArg1[MAX_STRING] = {0};
   CHAR szArg2[MAX_STRING] = {0};
   if (!stricmp(szLine,"list")) {
      WriteChatColor("Spells:",USERCOLOR_DEFAULT);
      for (Index=0;Index<9;Index++) {
         if (pCharInfo->MemorizedSpells[Index]==0xFFFFFFFF) {
            sprintf(szBuffer,"%d. <Empty>",Index+1);
         } else {
            sprintf(szBuffer,"%d. %s",Index+1,GetSpellByID(pCharInfo->MemorizedSpells[Index]));
         }
         WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
      }

      return;
   }

   GetArg(szArg1,szLine,1);
   GetArg(szArg2,szLine,2);
   DebugSpew("Cast: szArg1 = %s szArg2 = %s",szArg1,szArg2);
if (!stricmp(szArg1,"item"))
   {
      BOOL FOUND = FALSE;
      DWORD item = 0;
      DWORD slot = 0;
      DWORD SpawnFooter = NULL;
      SpawnFooter = (DWORD)pLocalPlayer;
      for (int i=0;i<30;i++) {
         if (pCharInfo->InventoryArray[i])
            if (!_stricmp(szArg2,pCharInfo->InventoryArray[i]->Item->Name)) { 
            DebugSpew("cast test slot %d = %s address is %x",i,pCharInfo->InventoryArray[i]->Item->Name,&(pCharInfo->InventoryArray[i])); 
            item = (DWORD)&pCharInfo->InventoryArray[i];
               slot = (DWORD)i;
               FOUND = TRUE;
               break;
            }
      }
      if (FOUND) {
		  pCharData->CastSpell(10,0,(EQ_Item**)item,0,slot,-1,0,0);
         return;
      }
   }
   GetArg(szBuffer,szLine,1);
   for (Index=0;Index<9;Index++) {
      if (pCharInfo->MemorizedSpells[Index]!=0xFFFFFFFF) {
         PCHAR SpellName = GetSpellNameByID(pCharInfo->MemorizedSpells[Index]);
         if (!stricmp(szBuffer,SpellName)) {
            DebugSpew("SpellName = %s",SpellName);
            cmdCast(pChar,itoa(Index+1,szBuffer,10));
            DebugSpew("pChar = %x SpellName = %s %s",pChar,SpellName,itoa(Index+1,szBuffer,10));
            return;
         }
      }
   }
   WriteChatColor("You do not seem to have that spell memorized.",USERCOLOR_DEFAULT);
   return;
}

// ***************************************************************************
// Function:    Target
// Description: Our '/target' command
//              Selects the closest spawn
// Usage:       /target [spawn|myself|mycorpse]
// ***************************************************************************
BOOL IsPCNear(PSPAWNINFO pSpawn, FLOAT Radius)
{
    PSPAWNINFO pClose = NULL;
    if (ppSpawnList && pSpawnList) {
        pClose = (PSPAWNINFO)pSpawnList;
        }
    while (pClose) {
        BOOL InGroup = FALSE;
        DWORD i;
        if (pClose==GetCharInfo()->pSpawn) InGroup=TRUE;
		if (ppGroup) for (i=0;i<5;i++) if (ppGroup[i]==(EQPlayer*)pClose) InGroup=TRUE;
        if (!InGroup && (pClose->Type == SPAWN_PLAYER)) {
            if ((pClose != pSpawn) && (DistanceToSpawn(pClose, pSpawn)<Radius)) return TRUE;
            }
        pClose = pClose->pNext;
    }
    return false;
            }

BOOL IsInGroup(PSPAWNINFO pSpawn)
{
    DWORD i;
	if (pSpawn==GetCharInfo()->pSpawn) return TRUE;
    if (!ppGroup) return FALSE;
	for (i=0;i<5;i++) if (ppGroup[i]==(EQPlayer*)pSpawn) return TRUE;
	return FALSE;
}

BOOL IsNamed(PSPAWNINFO pSpawn)
{
    CHAR szTemp[MAX_STRING]={0};
	PCSTR szName = {pSpawn->Name};
   
    if (pSpawn->Type != SPAWN_NPC)
		return false;

	if (pSpawn->Class >= 20 && pSpawn->Class <= 35 ) // NPC GMs
		return false;
	if (pSpawn->Class == 41 )  // NPC merchants
		return false;
	if (pSpawn->Class == 60 || pSpawn->Class == 61 )  //Ldon Merchants/Recruiters
		return false;
	if (pSpawn->Class == 63 ) // Tribute Master
		return false;


	GetArg(szTemp,szName,1);

	// Checking for mobs that have 'A' or 'An' as their first name
	if (szTemp[0] == 'A')
	{
		if (szTemp[1] == '_')
			return false;
		else if (szTemp[1] == 'n')
			if (szTemp[2] == '_')
				return false;
	}

    if ( (!strnicmp(szTemp,"Guard",5))			||
	     (!strnicmp(szTemp,"Defender",8))		||
		 (!strnicmp(szTemp,"Soulbinder",10))	||
		 (!strnicmp(szTemp,"Diaku",5)) )
			return false;

    if (isupper(szTemp[0]))
		return true;
	if (szTemp[0] == '#' )
		return true;

	
	return false;
}

PCHAR FormatSearchSpawn(PCHAR Buffer, PSEARCHSPAWN pSearchSpawn)
{
    CHAR szTemp[MAX_STRING] = {0};
    if (!Buffer) return NULL;
    if (!pSearchSpawn) return strcpy(Buffer,"None");
		PCHAR pszSpawnType;
		switch(pSearchSpawn->SpawnType)
		{
		case NONE:
		default:
			pszSpawnType="any";
			break;
		case PC:
			pszSpawnType="pc";
			break;
		case MOUNT:
			pszSpawnType="mount";
			break;
		case PET:
			pszSpawnType="pet";
			break;
		case NPC:
			pszSpawnType="npc";
			break;
		case CORPSE:
			pszSpawnType="corpse";
			break;
		case TRIGGER:
			pszSpawnType="trigger";
			break;
		case TRAP:
			pszSpawnType="trap";
			break;
		case CHEST:
			pszSpawnType="chest";
			break;
		case TIMER:
			pszSpawnType="timer";
			break;
		case UNTARGETABLE:
			pszSpawnType="untargetable";
			break;
		}

    sprintf(Buffer,"(%d-%d) %s",pSearchSpawn->MinLevel,pSearchSpawn->MaxLevel,pszSpawnType);

    if (pSearchSpawn->szName[0]!=0) {
        sprintf(szTemp," %s",pSearchSpawn->szName);
        strcat(Buffer,szTemp);
        }
    if (pSearchSpawn->szRace[0]!=0) {
        sprintf(szTemp," Race:%s",pSearchSpawn->szRace);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->szClass[0]!=0) {
        sprintf(szTemp," Class:%s",pSearchSpawn->szClass);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->szBodyType[0]!=0) {
        sprintf(szTemp," Body:%s",pSearchSpawn->szBodyType);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->GuildID!=0xFFFF) {
        sprintf(szTemp," Guild:%s",GetGuildByID(pSearchSpawn->GuildID));
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->bKnownLocation) {
        sprintf(szTemp," at %1.2f,%1.2f", pSearchSpawn->yLoc, pSearchSpawn->xLoc);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->FRadius<10000.0f) {
        sprintf(szTemp," Radius:%1.2f",pSearchSpawn->FRadius);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->ZRadius<10000.0f) {
        sprintf(szTemp," Z:±%1.2f",pSearchSpawn->ZRadius);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->Radius>0.0f) {
        sprintf(szTemp," NoPC:%1.2f",pSearchSpawn->Radius);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->SpawnID) {
        sprintf(szTemp," ID:%d",pSearchSpawn->SpawnID);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->NotID) {
        sprintf(szTemp," NotID:%d",pSearchSpawn->NotID);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->bAlert) {
        sprintf(szTemp," Alert:%d",pSearchSpawn->AlertList);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->bNoAlert) {
        sprintf(szTemp," NoAlert:%d",pSearchSpawn->NoAlertList);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->bNearAlert) {
        sprintf(szTemp," NearAlert:%d",pSearchSpawn->NearAlertList);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->bNotNearAlert) {
        sprintf(szTemp," NotNearAlert:%d",pSearchSpawn->NotNearAlertList);
        strcat(Buffer,szTemp);
    }
    if (pSearchSpawn->bGM && pSearchSpawn->SpawnType != NPC ) strcat(Buffer," GM");
    if (pSearchSpawn->bTrader) strcat(Buffer," Trader");
    if (pSearchSpawn->bLFG) strcat(Buffer," LFG");
	if (pSearchSpawn->bLight) {
		strcat(Buffer," Light");
		if (pSearchSpawn->szLight[0]) {
			strcat(Buffer,":");
			strcat(Buffer,pSearchSpawn->szLight);
		}
	}

    return Buffer;
}

PSPAWNINFO NthNearestSpawn(PSEARCHSPAWN pSearchSpawn, DWORD Nth, PSPAWNINFO pOrigin, BOOL IncludeOrigin)
{
	if (!pSearchSpawn || !Nth || !pOrigin)
		return 0;
	CIndex<PMQRANK> SpawnSet;
	PSPAWNINFO pSpawn=(PSPAWNINFO)pSpawnList;
	// create our set
	DWORD TotalMatching=0;
	if (IncludeOrigin)
	{
		while (pSpawn)
		{
			if (SpawnMatchesSearch(pSearchSpawn,pOrigin,pSpawn))
			{
				// matches search, add to our set
				TotalMatching++;
				PMQRANK pNewRank=new MQRANK;
				pNewRank->VarPtr.Ptr=pSpawn;
				pNewRank->Value.Float=GetDistance(pOrigin->X,pOrigin->Y,pSpawn->X,pSpawn->Y);
				SpawnSet+=pNewRank;
			}

			pSpawn=pSpawn->pNext;
		}
	}
	else
	{
		while (pSpawn)
		{
			if (pSpawn!=pOrigin && SpawnMatchesSearch(pSearchSpawn,pOrigin,pSpawn))
			{
				// matches search, add to our set
				TotalMatching++;
				PMQRANK pNewRank=new MQRANK;
				pNewRank->VarPtr.Ptr=pSpawn;
				pNewRank->Value.Float=GetDistance(pOrigin->X,pOrigin->Y,pSpawn->X,pSpawn->Y);
				SpawnSet+=pNewRank;
			}

			pSpawn=pSpawn->pNext;
		}
	}
	if (TotalMatching<Nth)
	{// CIndex.Cleanup will call "delete" on every valid pointer in our list.
		SpawnSet.Cleanup();
		return 0;
	}

	// sort our list
	qsort(&SpawnSet.List[0],TotalMatching,sizeof(PMQRANK),pMQRankFloatCompare);
	// get our Nth nearest
	pSpawn=(PSPAWNINFO)SpawnSet[Nth-1]->VarPtr.Ptr;

	SpawnSet.Cleanup();
	return pSpawn;
}

DWORD CountMatchingSpawns(PSEARCHSPAWN pSearchSpawn, PSPAWNINFO pOrigin, BOOL IncludeOrigin)
{
	if (!pSearchSpawn || !pOrigin)
		return 0;
	DWORD TotalMatching=0;
	PSPAWNINFO pSpawn=(PSPAWNINFO)pSpawnList;
	if (IncludeOrigin)
	{
		while (pSpawn)
		{
			if (SpawnMatchesSearch(pSearchSpawn,pOrigin,pSpawn))
			{
				TotalMatching++;
			}

			pSpawn=pSpawn->pNext;
		}
	}
	else
	{
		while (pSpawn)
		{
			if (pSpawn!=pOrigin && SpawnMatchesSearch(pSearchSpawn,pOrigin,pSpawn))
			{
				// matches search, add to our set
				TotalMatching++;
			}

			pSpawn=pSpawn->pNext;
		}
	}
	return TotalMatching;
}


PSPAWNINFO SearchThroughSpawns(PSEARCHSPAWN pSearchSpawn, PSPAWNINFO pChar)
{
    PSPAWNINFO pFromSpawn = NULL;


    if (pSearchSpawn->FromSpawnID>0 && (pSearchSpawn->bTargNext ||pSearchSpawn->bTargPrev)) 
	{
		pFromSpawn=(PSPAWNINFO)GetSpawnByID(pSearchSpawn->FromSpawnID);
		if (!pFromSpawn) return NULL;
		for ( int N=0 ; N < 3000 ; N++)
		{
			if (EQP_DistArray[N].VarPtr.Ptr==pFromSpawn)
			{
				if (pSearchSpawn->bTargPrev)
				{
					N--;
					for (N ; N >= 0 ; N--)
					{
						if (EQP_DistArray[N].VarPtr.Ptr && 
							SpawnMatchesSearch(pSearchSpawn,pFromSpawn,(PSPAWNINFO)EQP_DistArray[N].VarPtr.Ptr))
							return (PSPAWNINFO)EQP_DistArray[N].VarPtr.Ptr;
					}
				}
				else
				{
					N++;
					for (N ; N < 3000 ; N++)
					{
						if (EQP_DistArray[N].VarPtr.Ptr && 
							SpawnMatchesSearch(pSearchSpawn,pFromSpawn,(PSPAWNINFO)EQP_DistArray[N].VarPtr.Ptr))
							return (PSPAWNINFO)EQP_DistArray[N].VarPtr.Ptr;
					}
				}
				return NULL;
			}
		}
	}
	return NthNearestSpawn(pSearchSpawn,1,pChar,TRUE);
}

BOOL SpawnMatchesSearch(PSEARCHSPAWN pSearchSpawn, PSPAWNINFO pChar, PSPAWNINFO pSpawn)
{
    CHAR szName[MAX_STRING] = {0};
	eSpawnType SpawnType = GetSpawnType(pSpawn);
	if (pSearchSpawn->SpawnType!=SpawnType && pSearchSpawn->SpawnType!=NONE)
	{
		if (pSearchSpawn->SpawnType!=NPC || SpawnType!=UNTARGETABLE)
			return FALSE;
	}
	_strlwr(strcpy(szName,pSpawn->Name));
	if (!strstr(szName,pSearchSpawn->szName) && !strstr(CleanupName(szName,FALSE),pSearchSpawn->szName))
		return FALSE;
	if (pSpawn->Level<pSearchSpawn->MinLevel)
		return FALSE;
	if (pSpawn->Level>pSearchSpawn->MaxLevel)
		return FALSE;
	if (pSearchSpawn->NotID==pSpawn->SpawnID)
		return FALSE;
	if (pSearchSpawn->SpawnID && pSearchSpawn->SpawnID!=pSpawn->SpawnID)
		return FALSE;
	if (pSearchSpawn->GuildID!=0xFFFF && pSearchSpawn->GuildID!=pSpawn->GuildID)
		return FALSE;
	if (pSearchSpawn->bGM && pSearchSpawn->SpawnType != NPC )
		if (!pSpawn->GM)
		    return FALSE;
	if (pSearchSpawn->bGM && pSearchSpawn->SpawnType == NPC )
		if (pSpawn->Class < 20 || pSpawn->Class > 35 )
			return FALSE;
	if (pSearchSpawn->bNamed && !IsNamed(pSpawn))
		return FALSE;
	if (pSearchSpawn->bMerchant && pSpawn->Class != 41 )
		return FALSE;
	if (pSearchSpawn->bTributeMaster && pSpawn->Class != 63 )
		return FALSE;
        if (pSearchSpawn->bNoGuild && (pSpawn->GuildID < MAX_GUILDS))
                return FALSE;
	if (pSearchSpawn->bKnight && pSearchSpawn->SpawnType != NPC) 
		if (pSpawn->Class != 3 && pSpawn->Class != 5 )
			return FALSE;
	if (pSearchSpawn->bTank && pSearchSpawn->SpawnType != NPC) 
		if (pSpawn->Class != 3 && pSpawn->Class != 5 && pSpawn->Class != 1 )
			return FALSE;
	if (pSearchSpawn->bHealer && pSearchSpawn->SpawnType != NPC)
		if (pSpawn->Class != 2 && pSpawn->Class != 6)
			return FALSE;
	if (pSearchSpawn->bDps && pSearchSpawn->SpawnType != NPC)
		if (pSpawn->Class != 4 && pSpawn->Class != 9 && pSpawn->Class != 12 )
			return FALSE;
	if (pSearchSpawn->bSlower && pSearchSpawn->SpawnType != NPC)
		if (pSpawn->Class != 10 && pSpawn->Class != 14 && pSpawn->Class != 15)
			return FALSE;
	if (pSearchSpawn->bLFG && !pSpawn->LFG)
		return FALSE;
	if (pSearchSpawn->bTrader && !pSpawn->pActorInfo->Trader)
		return FALSE;
	if (pSearchSpawn->bGroup && !IsInGroup(pSpawn))
		return FALSE;
	if (pSearchSpawn->bKnownLocation) 
	{
		if ((pSearchSpawn->xLoc!=pSpawn->X || pSearchSpawn->yLoc!=pSpawn->Y))
		if (pSearchSpawn->FRadius<10000.0f && DistanceToPoint(pSpawn,pSearchSpawn->xLoc,pSearchSpawn->yLoc)>pSearchSpawn->FRadius)
		return FALSE;
	}
	else if (pSearchSpawn->FRadius<10000.0f && DistanceToSpawn(pChar, pSpawn)>pSearchSpawn->FRadius)
		return FALSE;


	if (pSearchSpawn->Radius>0.0f && IsPCNear(pSpawn,pSearchSpawn->Radius))
		return FALSE;
	if (gZFilter<10000.0f && ( (pSpawn->Z > pChar->Z + gZFilter) || (pSpawn->Z < pChar->Z - gZFilter)))
		return FALSE;
	if (pSearchSpawn->ZRadius<10000.0f &&  (pSpawn->Z > pChar->Z + pSearchSpawn->ZRadius ||pSpawn->Z < pChar->Z - pSearchSpawn->ZRadius))
		return FALSE;
	if (pSearchSpawn->bLight) 
	{
		PCHAR pLight=GetLightForSpawn(pSpawn);
		if (!stricmp(pLight,"NONE")) 
			return FALSE;
		if (pSearchSpawn->szLight[0] && stricmp(pLight,pSearchSpawn->szLight)) 
			return FALSE;
	}
	if ((pSearchSpawn->bAlert) && (GetAlert(pSearchSpawn->AlertList))) 
	{
		if (!IsAlert(pChar,pSpawn,pSearchSpawn->AlertList)) 
			return FALSE;
	}
	if ((pSearchSpawn->bNoAlert) && (GetAlert(pSearchSpawn->NoAlertList))) 
	{
		if (IsAlert(pChar,pSpawn,pSearchSpawn->NoAlertList)) 
			return FALSE;
	}
	if ((pSearchSpawn->bNotNearAlert) && (GetClosestAlert(pSpawn, pSearchSpawn->NotNearAlertList,NULL))) 
		return FALSE;
	if ((pSearchSpawn->bNearAlert) && (!GetClosestAlert(pSpawn,pSearchSpawn->NearAlertList,NULL))) 
		return FALSE;
	
	if (pSearchSpawn->szClass[0] && stricmp(pSearchSpawn->szClass,GetClassDesc(pSpawn->Class)))
		return FALSE;
	if (pSearchSpawn->szBodyType[0] && stricmp(pSearchSpawn->szBodyType,GetBodyTypeDesc(pSpawn->BodyType)))
		return FALSE;
	if (pSearchSpawn->szRace[0] && stricmp(pSearchSpawn->szRace,pEverQuest->GetRaceDesc(pSpawn->Race)))
		return FALSE;


	return TRUE;
}

PCHAR ParseSearchSpawnArgs(PCHAR szArg, PCHAR szRest, PSEARCHSPAWN pSearchSpawn)
{
    if (szArg && pSearchSpawn) {
        if (!stricmp(szArg,"pc")) {
            pSearchSpawn->SpawnType = PC;
        } else if (!stricmp(szArg,"npc")) {
            pSearchSpawn->SpawnType = NPC;
        } else if (!stricmp(szArg,"mount")) {
            pSearchSpawn->SpawnType = MOUNT;
        } else if (!stricmp(szArg,"pet")) {
            pSearchSpawn->SpawnType = PET;
        } else if (!stricmp(szArg,"nopet")) { 
            pSearchSpawn->bNoPet = TRUE; 
        } else if (!stricmp(szArg,"corpse")) {
            pSearchSpawn->SpawnType = CORPSE;
        } else if (!stricmp(szArg,"trigger")) {
            pSearchSpawn->SpawnType = TRIGGER;
        } else if (!stricmp(szArg,"untargetable")) {
            pSearchSpawn->SpawnType = UNTARGETABLE;
        } else if (!stricmp(szArg,"trap")) {
            pSearchSpawn->SpawnType = TRAP;
        } else if (!stricmp(szArg,"chest")) {
            pSearchSpawn->SpawnType = CHEST;
        } else if (!stricmp(szArg,"timer")) {
            pSearchSpawn->SpawnType = TIMER;
        } else if (!stricmp(szArg,"any")) {
            pSearchSpawn->SpawnType = NONE;
        } else if (!stricmp(szArg,"next")) {
            pSearchSpawn->bTargNext = TRUE;
        } else if (!stricmp(szArg,"prev")) {
            pSearchSpawn->bTargPrev = TRUE;
        } else if (!stricmp(szArg,"lfg")) {
            pSearchSpawn->bLFG = TRUE;
        } else if (!stricmp(szArg,"gm")) {
            pSearchSpawn->bGM = TRUE;
        } else if (!stricmp(szArg,"group")) {
            pSearchSpawn->bGroup = TRUE;
        } else if (!stricmp(szArg,"noguild")) {
            pSearchSpawn->bNoGuild = TRUE;
        } else if (!stricmp(szArg,"trader")) {
            pSearchSpawn->bTrader = TRUE;
		} else if (!stricmp(szArg,"named")) {
			pSearchSpawn->bNamed = TRUE;
		} else if (!stricmp(szArg,"merchant")) {
			pSearchSpawn->bMerchant = TRUE;
		} else if (!stricmp(szArg,"tribute")) {
			pSearchSpawn->bTributeMaster = TRUE;
		} else if (!stricmp(szArg,"knight")) {
			pSearchSpawn->bKnight = TRUE;
		} else if (!stricmp(szArg,"tank")) {
			pSearchSpawn->bTank = TRUE;
		} else if (!stricmp(szArg,"healer")) {
			pSearchSpawn->bHealer = TRUE;
		} else if (!stricmp(szArg,"dps")) {
			pSearchSpawn->bDps = TRUE;
		} else if (!stricmp(szArg,"slower")) {
			pSearchSpawn->bSlower = TRUE;
        } else if (!stricmp(szArg,"range")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->MinLevel = atoi(szArg);
            GetArg(szArg,szRest,2);
            pSearchSpawn->MaxLevel = atoi(szArg);
            szRest = GetNextArg(szRest,2);
        } else if (!stricmp(szArg,"loc")) {
            pSearchSpawn->bKnownLocation = TRUE;
            GetArg(szArg,szRest,1);
            pSearchSpawn->xLoc = (FLOAT)atof(szArg);
            GetArg(szArg,szRest,2);
            pSearchSpawn->yLoc = (FLOAT)atof(szArg);
            szRest = GetNextArg(szRest,2);
        } else if (!stricmp(szArg,"id")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->SpawnID = atoi(szArg);
            szRest = GetNextArg(szRest,1);
        } else if (!stricmp(szArg,"radius")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->FRadius = atof(szArg);
            szRest = GetNextArg(szRest,1);
        } else if (!stricmp(szArg,"body")) {
            GetArg(szArg,szRest,1);
            strcpy(pSearchSpawn->szBodyType,szArg);
            szRest = GetNextArg(szRest,1);
        } else if (!stricmp(szArg,"class")) {
            GetArg(szArg,szRest,1);
            strcpy(pSearchSpawn->szClass,szArg);
            szRest = GetNextArg(szRest,1);
		} else if (!stricmp(szArg,"race")) {
            GetArg(szArg,szRest,1);
            strcpy(pSearchSpawn->szRace,szArg);
            szRest = GetNextArg(szRest,1);
        } else if (!stricmp(szArg,"light")) {
            DWORD Light = -1;
			DWORD i=0;
            GetArg(szArg,szRest,1);
			if (szArg[0]!=0) for (i=0;i<LIGHT_COUNT;i++) if (!stricmp(szLights[i],szArg)) Light=i;
            if (Light != -1) {
                strcpy(pSearchSpawn->szLight,szLights[Light]);
                szRest = GetNextArg(szRest,1);
            } else {
                pSearchSpawn->szLight[0]=0;
            }
			pSearchSpawn->bLight=TRUE;
        } else if (!strcmp(szArg,"GUILD")) {
			pSearchSpawn->GuildID=GetCharInfo()->pSpawn->GuildID;
        } else if (!stricmp(szArg,"guild")) {
            DWORD GuildID = 0xFFFF;
            GetArg(szArg,szRest,1);
            if (szArg[0]!=0) GuildID = GetGuildIDByName(szArg);
            if (GuildID!=0xFFFF) {
                pSearchSpawn->GuildID = GuildID;
                szRest = GetNextArg(szRest,1);
            } else {
                pSearchSpawn->GuildID = GetCharInfo()->pSpawn->GuildID;
            }
        } else if (!stricmp(szArg,"alert")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->AlertList = atoi(szArg);
            szRest = GetNextArg(szRest,1);
            pSearchSpawn->bAlert = TRUE;
        } else if (!stricmp(szArg,"noalert")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->NoAlertList = atoi(szArg);
            szRest = GetNextArg(szRest,1);
            pSearchSpawn->bNoAlert = TRUE;
        } else if (!stricmp(szArg,"notnearalert")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->NotNearAlertList = atoi(szArg);
            szRest = GetNextArg(szRest,1);
            pSearchSpawn->bNotNearAlert = TRUE;
        } else if (!stricmp(szArg,"nearalert")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->NearAlertList = atoi(szArg);
            szRest = GetNextArg(szRest,1);
            pSearchSpawn->bNearAlert = TRUE;
        } else if (!stricmp(szArg,"zradius")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->ZRadius = atof(szArg);
            szRest = GetNextArg(szRest,1);
        } else if (!stricmp(szArg,"notid")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->NotID = atoi(szArg);
            szRest = GetNextArg(szRest,1);
        } else if (!stricmp(szArg,"nopcnear")) {
            GetArg(szArg,szRest,1);

            if ((szArg[0]==0) || (0.0f == (pSearchSpawn->Radius = (FLOAT)atof(szArg)))) {
                pSearchSpawn->Radius = 200.0f;
            } else {
                szRest = GetNextArg(szRest,1);
            }
		} else if (IsNumber(szArg)) {
			pSearchSpawn->MinLevel=atoi(szArg);
			pSearchSpawn->MaxLevel=pSearchSpawn->MinLevel;
        } else {
			for (DWORD N=1;N<17;N++)
			{
				if (!stricmp(szArg,ClassInfo[N].Name) || !stricmp(szArg,ClassInfo[N].ShortName))
				{
					strcpy(pSearchSpawn->szClass,pEverQuest->GetClassDesc(N));
					return szRest;
				}
			}
			if (pSearchSpawn->szName[0])
			{// multiple word name
				strcat(pSearchSpawn->szName," ");
				strcat(pSearchSpawn->szName,szArg);
			}
			else
				strcpy(pSearchSpawn->szName,szArg);
        }
    }
    return szRest;
}

VOID ParseSearchSpawn(PCHAR Buffer, PSEARCHSPAWN pSearchSpawn)
{
    CHAR szArg[MAX_STRING] = {0};
    CHAR szMsg[MAX_STRING] = {0};
    CHAR szLLine[MAX_STRING] = {0};
    PCHAR szFilter = szLLine;
    BOOL DidTarget = FALSE;
    BOOL bArg = TRUE;

    bRunNextCommand = TRUE;
    _strlwr(strcpy(szLLine,Buffer));
    while (bArg) {
        GetArg(szArg,szFilter,1);
        szFilter = GetNextArg(szFilter,1);
        if (szArg[0]==0) {
            bArg = FALSE;
        } else {
            szFilter = ParseSearchSpawnArgs(szArg,szFilter,pSearchSpawn);
        }
    }
}


VOID Target(PSPAWNINFO pChar, PCHAR szLine)
{
    if (!ppSpawnList) return;
    if (!pSpawnList) return;
    PSPAWNINFO pSpawnClosest = NULL;
    SEARCHSPAWN SearchSpawn;
    ClearSearchSpawn(&SearchSpawn);
    CHAR szArg[MAX_STRING] = {0};
    CHAR szMsg[MAX_STRING] = {0};
    CHAR szLLine[MAX_STRING] = {0};
    PCHAR szFilter = szLLine;
    BOOL DidTarget = FALSE;
    BOOL bArg = TRUE;

    bRunNextCommand = TRUE;
    _strlwr(strcpy(szLLine,szLine));
    while (bArg) {
        GetArg(szArg,szFilter,1);
        szFilter = GetNextArg(szFilter,1);
        if (szArg[0]==0) {
            bArg = FALSE;
        } else if (!strcmp(szArg,"myself")) {
            if (((PCHARINFO)pCharData)->pSpawn) {
                pSpawnClosest = ((PCHARINFO)pCharData)->pSpawn;
                DidTarget = TRUE;
            }
        } else if (!strcmp(szArg,"mycorpse")) {
            if (((PCHARINFO)pCharData)->pSpawn) {
                sprintf(szFilter,"%s's Corpse",((PCHARINFO)pCharData)->pSpawn->Name);
                _strlwr(szFilter);
            }
        } else if (!strcmp(szArg,"clear")) {
            pTarget = NULL;
            DebugSpew("Target cleared.");
            WriteChatColor("Target cleared.",USERCOLOR_WHO);
            return;
        } else {
            szFilter = ParseSearchSpawnArgs(szArg,szFilter,&SearchSpawn);
        }
    }
    if (pTarget) SearchSpawn.FromSpawnID = ((PSPAWNINFO)pTarget)->SpawnID;

    if (!DidTarget) {
        pSpawnClosest = SearchThroughSpawns(&SearchSpawn,pChar);
    }

    if (!pSpawnClosest) {
        CHAR szTemp[MAX_STRING] = {0};
        sprintf(szMsg,"There are no spawns matching: %s",FormatSearchSpawn(szTemp,&SearchSpawn));
    } else {
        PSPAWNINFO *psTarget = NULL;
        if (ppTarget) {
            psTarget = (PSPAWNINFO*)ppTarget;
            *psTarget = pSpawnClosest;
            DebugSpew("Target - %s selected",pSpawnClosest->Name);
			szMsg[0]=0;
        } else {
            sprintf(szMsg,"Unable to target, address = 0");
        }
    }
	if (szMsg[0])
    if (!gFilterTarget) WriteChatColor(szMsg,USERCOLOR_WHO);
    return;
}


// ***************************************************************************
// Function:    Skills
// Description: Our '/skills' command
//              Displays what your current skill levels are
// Usage:       /skills [skill name]
// ***************************************************************************
VOID Skills(PSPAWNINFO pChar, PCHAR szLine)
{
    DWORD Skill, SkillCount = 0;
    CHAR szMsg[MAX_STRING] = {0};
    bRunNextCommand = TRUE;
    PCHARINFO pCharInfo = NULL;
    if (NULL == (pCharInfo = GetCharInfo())) return;
    if (szLine[0] != 0) _strlwr(szLine);
    WriteChatColor("Skills",USERCOLOR_DEFAULT);
    WriteChatColor("-----------------------",USERCOLOR_DEFAULT);
    for (Skill=0;szSkills[Skill];Skill++) {
        if (szLine[0] != 0) {
            CHAR szName[MAX_STRING] = {0};
            strcpy(szName,szSkills[Skill]);
            _strlwr(szName);
            if (!strstr(szName,szLine)) continue;
        }
        SkillCount++;
        switch (pCharInfo->Skill[Skill]) {
            case 255:
                //Untrainable
                SkillCount--;
                break;
            case 254:
                //Can train
                sprintf(szMsg,"%s: Trainable",szSkills[Skill]);
                WriteChatColor(szMsg,USERCOLOR_DEFAULT);
                break;
            case 253:
                //Unknown
                sprintf(szMsg,"%s: Unknown(253)",szSkills[Skill]);
                WriteChatColor(szMsg,USERCOLOR_DEFAULT);
                break;
            default:
                //Have skill
                sprintf(szMsg,"%s: %d",szSkills[Skill],pCharInfo->Skill[Skill]);
                WriteChatColor(szMsg,USERCOLOR_DEFAULT);
        }
    }
    if (SkillCount == 0) {
        sprintf(szMsg,"No skills matched '%s'.",szLine);
        WriteChatColor(szMsg,USERCOLOR_DEFAULT);
    } else {
        DebugSpew("Skills - %d skills listed",SkillCount);
        sprintf(szMsg,"%d skills displayed.",SkillCount);
        WriteChatColor(szMsg,USERCOLOR_DEFAULT);
    }
}

// ***************************************************************************
// Function:    MacroPause
// Description: Our '/mqpause' command
//              Pause/resume a macro
// Usage:       /mqpause <off> 
//            /mqpause chat [on|off] 
// ***************************************************************************
VOID MacroPause(PSPAWNINFO pChar, PCHAR szLine)
{
    BOOL Pause = TRUE;
    CHAR szBuffer[MAX_STRING] = {0};

   DWORD Command; 
   CHAR szArg[MAX_STRING] = {0}; 
   CHAR szArg1[MAX_STRING] = {0}; 

   PCHAR szPause[] = { 
      "off", 
      "on", 
      NULL 
   }; 

    bRunNextCommand = TRUE;

   GetArg(szArg,szLine,1); 
   if (!stricmp(szArg,"chat")) { 
      GetArg(szArg1,szLine,2); 
      if (szLine[0]==0) { 

        gMQPauseOnChat = !gMQPauseOnChat;
      } else { 
         for (Command=0;szPause[Command];Command++) { 
            if (!stricmp(szArg1,szPause[Command])) { 
               gMQPauseOnChat = Command; 
            } 
         } 
      } 

        WritePrivateProfileString("MacroQuest","MQPauseOnChat",(gMQPauseOnChat)?"1":"0",gszINIFilename);
        sprintf(szBuffer,"Macros will %spause while in chat mode.",(gMQPauseOnChat)?"":"not ");
        WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
        return;
    }

    if (!gMacroBlock) {
        MacroError("You cannot pause a macro when one isn't running.");
        return;
    }

   for (Command=0;szPause[Command];Command++) { 
      if (!stricmp(szArg,szPause[Command])) { 
         Pause = Command; 
      } 
   } 

   if (szLine[0]!=0) { 
      WriteChatColor("Syntax: /mqpause [on|off] [chat [on|off]]",USERCOLOR_DEFAULT); 
    } else {
        Pause = !gMacroPause;
    }
    if (gMacroPause == Pause) {
        sprintf(szBuffer,"Macro is already %s.",(Pause)?"paused":"running");
    } else {
        sprintf(szBuffer,"Macro is %s.",(Pause)?"paused":"running again");
        gMacroPause = Pause;
    }
    WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
}



// ***************************************************************************
// Function:    SetAutoRun
// Description: Our '/setautorun' command
//              Set autorun value
// Usage:       /setautorun [command]
// ***************************************************************************
VOID SetAutoRun(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szServerAndName[MAX_STRING] = {0};
    sprintf(szServerAndName,"%s.%s",((PCHARINFO)pCharData)->Server,((PCHARINFO)pCharData)->Name);
    WritePrivateProfileString(szServerAndName,"AutoRun",szLine,gszINIFilename);
    sprintf(szServerAndName,"Set autorun to: '%s'",szLine);
    WriteChatColor(szServerAndName,USERCOLOR_DEFAULT);
}

// ***************************************************************************
// Function:    Alias
// Description: Our '/alias' command
//              Add command aliases
// Usage:       /alias name [delete|command]
// ***************************************************************************

VOID RewriteAliases(VOID)
{
    PALIAS pLoop = pAliases;
    WritePrivateProfileSection("Aliases","",gszINIFilename);
    while (pLoop) {
        WritePrivateProfileString("Aliases",pLoop->szName,pLoop->szCommand,gszINIFilename);
        pLoop = pLoop->pNext;
    }
}


VOID Alias(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szBuffer[MAX_STRING] = {0};
    CHAR szName[MAX_STRING] = {0};
    PCHAR szCommand = NULL;
    GetArg(szName,szLine,1);
    szCommand = GetNextArg(szLine);
    if (!stricmp(szName,"list")) {
        PALIAS pLoop = pAliases;
        DWORD Count=0;
        WriteChatColor("Aliases",USERCOLOR_WHO);
        WriteChatColor("--------------------------",USERCOLOR_WHO);
        while (pLoop) {
            sprintf(szName,"%s: %s",pLoop->szName,pLoop->szCommand);
            WriteChatColor(szName,USERCOLOR_WHO);
            Count++;
            pLoop = pLoop->pNext;
        }
        if (Count==0) {
            WriteChatColor("No aliases defined.",USERCOLOR_WHO);
        } else {
            sprintf(szName,"%d alias%s displayed.",Count,(Count==1)?"":"es");
            WriteChatColor(szName,USERCOLOR_WHO);
        }
        return;
    }
    if ((szName[0]==0) || (szCommand[0]==0)) {
        SyntaxError("Usage: /alias name [delete|command], or /alias list");
        return;
    }

    if (!stricmp(szCommand,"delete")) {
		if (RemoveAlias(szName))
		{
            sprintf(szBuffer,"Alias '%s' deleted.",szName);
            RewriteAliases();
            WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
		}
		else
		{
	        sprintf(szBuffer,"Alias '%s' not found.",szName);
			WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
		}
    } else {
		BOOL New=1;
		if (RemoveAlias(szName))
			New=0;
		AddAlias(szName,szCommand);
        sprintf(szBuffer,"Alias '%s' %sed.",szName,(New)?"add":"updat");
        WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
        RewriteAliases();
    }
}

// ***************************************************************************
// Function:    Substitute
// Description: Our '/substitute' command
//              Add substitutions
// Usage:       /substitution <original> <new>
//				/substitution list
//				/substitition <original> delete
// ***************************************************************************

VOID RewriteSubstitutions(VOID)
{
    PSUB pSubLoop = pSubs;
    WritePrivateProfileSection("Substitutions","",gszINIFilename);
    while (pSubLoop) {
		WritePrivateProfileString("Substitutions",pSubLoop->szOrig,pSubLoop->szSub,gszINIFilename);
        pSubLoop = pSubLoop->pNext;
    }
}


VOID Substitute(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szBuffer[MAX_STRING] = {0};
    CHAR szName[MAX_STRING] = {0};
    PCHAR szCommand = NULL;
    GetArg(szName,szLine,1);
    szCommand = GetNextArg(szLine);
    if (!stricmp(szName,"list")) {
        PSUB pLoop = pSubs;
        DWORD Count=0;
        WriteChatColor("Substitutions",USERCOLOR_WHO);
        WriteChatColor("--------------------------",USERCOLOR_WHO);
        while (pLoop) {
			sprintf(szName,"%s\t----\t%s",pLoop->szOrig,pLoop->szSub);
            WriteChatColor(szName,USERCOLOR_WHO);
            Count++;
            pLoop = pLoop->pNext;
        }
        if (Count==0) {
            WriteChatColor("No Substitutions defined.",USERCOLOR_WHO);
        } else {
            sprintf(szName,"%d substitution%s displayed.",Count,(Count==1)?"":"s");
            WriteChatColor(szName,USERCOLOR_WHO);
        }
        return;
    }
    if ((szName[0]==0) || (szCommand[0]==0)) {
        SyntaxError("Usage: /substitute <orig> <new>, /substitute <orig> delete, or /substitute list");
        return;
    }

    if (!stricmp(szCommand,"delete")) {
		if (RemoveSubstitute(szName))
		{
            sprintf(szBuffer,"Substitution for '%s' deleted.",szName);
            RewriteSubstitutions();
            WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
		}
		else
		{
	        sprintf(szBuffer,"Substitution for '%s' not found.",szName);
			WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
		}
    } else {
		BOOL New=1;
		if (RemoveSubstitute(szName))
			New=0;
		AddSubstitute(szName,szCommand);
        sprintf(szBuffer,"Substitution for '%s' %sed.",szName,(New)?"add":"updat");
        WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
        RewriteSubstitutions();
    }
}

// ***************************************************************************
// Function:   IniOutput
// Description:   Outputs string data to an INI file using
//            WritePrivateProfileString.
// Usage:      /ini
// ***************************************************************************
VOID IniOutput(PSPAWNINFO pChar, PCHAR szLine)
{
   CHAR szArg1[MAX_STRING] = {0};   //Filename
   CHAR szArg2[MAX_STRING] = {0};   //Section
   CHAR szArg3[MAX_STRING] = {0};   //Key
   CHAR szArg4[MAX_STRING] = {0};   //Data to write

   CHAR szOutput[MAX_STRING] = {0};  //Success / Error Output

   GetArg(szArg1,szLine,1);
   GetArg(szArg2,szLine,2);
   GetArg(szArg3,szLine,3);
   GetArg(szArg4,szLine,4);

   DebugSpew("/ini input -- %s %s %s %s",szArg1,szArg2,szArg3,szArg4);
	PCHAR pTemp=szArg1;
	while(pTemp[0])
	{
		if (pTemp[0]=='/')
			pTemp[0]='\\';
		pTemp++;
	}


    if (szArg1[0]!='\\' && !strchr(szArg1,':')) 
	{
        sprintf(szOutput,"%s\\%s",gszMacroPath, szArg1);
        strcpy(szArg1,szOutput);
    }
    if (!strstr(szArg1,".")) strcat(szArg1,".ini");
   ZeroMemory(szOutput,MAX_STRING);

   if (!WritePrivateProfileString(szArg2,szArg3,szArg4,szArg1)) {
      sprintf(szOutput,"IniOutput ERROR -- during WritePrivateProfileString: %s",szLine);
      DebugSpew(szOutput);
   } else {
      sprintf(szOutput,"IniOutput Write Successful!");
      DebugSpew("%s: %s",szOutput,szLine);
   }
}

// ***************************************************************************
// Function:        BankList
// Description:     Our /banklist command. Lists bank contents to chat buffer.
// 2003-08-30       Valerian
// ***************************************************************************
VOID BankList(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szTemp[MAX_STRING]={0};
    PCHARINFO pCharInfo = NULL;
    PCONTENTS pContainer = NULL;
    if (NULL == (pCharInfo = GetCharInfo())) {
        MacroError("/banklist -- Bad offset: CharInfo");
        return;
    }
    WriteChatColor("Listing of Bank Inventory",USERCOLOR_DEFAULT);
    WriteChatColor("-------------------------",USERCOLOR_DEFAULT);
	char Link[256];
    for (int a=0;a<18;a++) {
		pContainer=pCharInfo->Bank[a];
        if (pContainer) {
			GetItemLink(pContainer,&Link[0]);
			sprintf(szTemp,"Slot %d: %dx %s (%s)",a,pContainer->StackCount ? pContainer->StackCount : 1,Link,pContainer->Item->LoreName);
            WriteChatColor(szTemp,USERCOLOR_DEFAULT);
            for (int b=0;b<pContainer->Item->Slots;b++) {
                if (pContainer->Contents[b]) {
					GetItemLink(pContainer->Contents[b],&Link[0]);
                    sprintf(szTemp,"- Slot %d: %dx %s (%s)",b,pContainer->Contents[b]->StackCount ? pContainer->Contents[b]->StackCount : 1,Link,pContainer->Contents[b]->Item->LoreName);
                    WriteChatColor(szTemp,USERCOLOR_DEFAULT);
                }
            }
        }
    }
}

// ***************************************************************************
// Function:      WindowState
// Description:      Our /windowstate command. Toggles windows open/closed.
// ***************************************************************************
VOID WindowState(PSPAWNINFO pChar, PCHAR szLine)
{
	/*
	struct _WINDOWSTATELIST 
		{ PCHAR szName;	PCSIDLWND* pWindow; }
	WindowList[] = {
		{ "inventory",	(PCSIDLWND*)ppInventoryWnd },
		{ "merchant",	(PCSIDLWND*)ppMerchantWnd },
		{ "corpse",		(PCSIDLWND*)ppLootWnd },
		{ "spellbook",	(PCSIDLWND*)ppSpellBookWnd },
		{ "pet",		(PCSIDLWND*)ppPetInfoWnd },
		{ "map",		(PCSIDLWND*)ppMapViewWnd },
		{ "notes",		(PCSIDLWND*)ppNoteWnd },
		{ NULL, NULL }
	};
	/**/

	CHAR Arg1[MAX_STRING] = {0};
	CHAR Arg2[MAX_STRING] = {0};
//	DWORD i;
	GetArg(Arg1,szLine,1);
	GetArg(Arg2,szLine,2);

	if (PCSIDLWND pWnd=(PCSIDLWND)FindMQ2Window(Arg1)) 
	{
			DWORD ShowWindow = (DWORD)pWnd->pvfTable->ShowWindow;
			CHAR szBuffer[MAX_STRING] = {0};
			BYTE State=99;
			if (!stricmp(Arg2,"open")) State=1;
			if (!stricmp(Arg2,"close")) State=0;
			if (pWnd->Show==State) State=99;
			switch (State) {
				case 0:
					pWnd->Show=0;
					sprintf(szBuffer,"Window '%s' is now closed.",pWnd->WindowText->Text);
					break;
				case 1:
					__asm {
						push ecx;
						mov ecx, [pWnd];
						call dword ptr [ShowWindow];
						pop ecx;
					}
					sprintf(szBuffer,"Window '%s' is now open.",pWnd->WindowText->Text);
					break;
				case 99:
					sprintf(szBuffer,"Window '%s' is currently %s",pWnd->WindowText->Text,(pWnd->Show==0)?"closed":"open");
					break;
			}
			WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
			return;
		}
	SyntaxError("Usage: /windowstate <window> [open|close]");
}

// ***************************************************************************
// Function:      KeepKeys
// Description:      Our /keepkeys command. Toggles if /endmacro will keep keys
//               by default.
// 2003-10-08      MacroFiend
// ***************************************************************************
VOID KeepKeys(PSPAWNINFO pChar, PCHAR szLine)
{
   bRunNextCommand = TRUE;
   DWORD Command;
   CHAR szArg[MAX_STRING] = {0};
   GetArg(szArg,szLine,1);
   CHAR szCmd[MAX_STRING] = {0};

   PCHAR szKeepKeys[] = {
      "off",
      "on",
      NULL
   };

   if (szArg[0]==0) {
      sprintf(szCmd,"Auto-Keep Keys: %s",szKeepKeys[gKeepKeys]);
      WriteChatColor(szCmd,USERCOLOR_DEFAULT);
      return;
   }
   for (Command=0;szKeepKeys[Command];Command++) {
      if (!stricmp(szArg,szKeepKeys[Command])) {
         gKeepKeys = Command;
         sprintf(szCmd,"Auto-Keep Keys changed to: %s",szKeepKeys[gKeepKeys]);
         WriteChatColor(szCmd,USERCOLOR_DEFAULT);
         itoa(gKeepKeys,szCmd,10); WritePrivateProfileString("MacroQuest","KeepKeys",szCmd,gszINIFilename);
         return;
      }
   }
   SyntaxError("Usage: /keepkeys [on|off]");
}


// ***************************************************************************
// Function:      DisplayLoginName
// Description:   Our /loginname command.
// ***************************************************************************
VOID DisplayLoginName(PSPAWNINFO pChar, PCHAR szLine) 
{
	PCHAR szLogin = GetLoginName();
	if (!szLogin) {
		MacroError("Unable to retrieve login name.");
	} else {
		WriteChatf("Login name: \ay%s\ax",szLogin);
		free(szLogin);
	}
}

// ***************************************************************************
// Function:      PluginCommand
// Description:   Our /plugin command.
// ***************************************************************************
VOID PluginCommand(PSPAWNINFO pChar, PCHAR szLine) 
{ 
    CHAR szBuffer[MAX_STRING] = {0}; 
    CHAR szName[MAX_STRING] = {0}; 
    PCHAR szCommand = NULL; 
    GetArg(szName,szLine,1); 
    szCommand = GetNextArg(szLine); 
    if (!stricmp(szName,"list")) { 
        PMQPLUGIN pLoop = pPlugins; 
        DWORD Count=0; 
        WriteChatColor("Active Plugins",USERCOLOR_WHO); 
        WriteChatColor("--------------------------",USERCOLOR_WHO); 
        while (pLoop) { 
            sprintf(szName,"%s",pLoop->szFilename); 
            WriteChatColor(szName,USERCOLOR_WHO); 
            Count++; 
            pLoop = pLoop->pNext; 
        } 
        if (Count==0) { 
            WriteChatColor("No Plugins defined.",USERCOLOR_WHO); 
        } else { 
            sprintf(szName,"%d Plugin%s displayed.",Count,(Count==1)?"":"s"); 
            WriteChatColor(szName,USERCOLOR_WHO); 
        } 
        return; 
    } 
    if (szName[0]==0) { 
        SyntaxError("Usage: /Plugin name [unload] [noauto], or /Plugin list"); 
        return; 
    } 

    if (!strnicmp(szCommand,"unload",6)) { 
      if (UnloadMQ2Plugin(szName)) 
      { 
            sprintf(szBuffer,"Plugin '%s' unloaded.",szName); 
            WriteChatColor(szBuffer,USERCOLOR_DEFAULT); 
			if (!strstr(szCommand,"noauto")) RewriteMQ2Plugins(); 

      } 
      else 
      { 
         MacroError("Plugin '%s' not found.",szName); 
      } 
    } else { 
      if (LoadMQ2Plugin(szName)) 
      { 
         sprintf(szBuffer,"Plugin '%s' loaded.",szName); 
         WriteChatColor(szBuffer,USERCOLOR_DEFAULT); 
         if (stricmp(szCommand,"noauto")) RewriteMQ2Plugins(); 
      } 
      else 
      { 
         MacroError("Plugin '%s' could not be loaded.",szName); 
      } 
    } 
}

VOID EQDestroyHeldItemOrMoney(PSPAWNINFO pChar, PCHAR szLine)
{
	(pPCData)->DestroyHeldItemOrMoney();
}

VOID Exec(PSPAWNINFO pChar,PCHAR szLine) {
   CHAR exepath[MAX_STRING] = {0};

//   CHAR szTemp[MAX_STRING] = {0};
   CHAR szTemp1[MAX_STRING] = {0};
   CHAR szTemp2[MAX_STRING] = {0};
   GetArg(szTemp1,szLine,1);
   GetArg(szTemp2,szLine,2);

   if (szTemp1[0]!=0 && szTemp2[0]!=0) {
      WriteChatf("Opening %s %s",szTemp1,szTemp2);

      GetPrivateProfileString("Application Paths",szTemp1,szTemp1,exepath,MAX_STRING,gszINIFilename);

      if(!strcmp(szTemp2,"bg")) { 
         ShellExecute(NULL, "open", exepath, NULL, NULL, SW_SHOWMINNOACTIVE);
      } else if(!strcmp(szTemp2,"fg")) { 
         ShellExecute(NULL, "open", exepath, NULL, NULL, SW_SHOWNOACTIVATE);
      }
   } else {
      WriteChatColor("/exec [application] [fg | bg]",USERCOLOR_DEFAULT);
   }
} 

// /keypress
VOID DoMappable(PSPAWNINFO pChar, PCHAR szLine)
{
	if (szLine[0]==0)
	{
		SyntaxError("Usage: /keypress <eqcommand|keycombo> [hold|chat]");
		return;
	}
	CHAR szArg1[MAX_STRING]={0};
	CHAR szArg2[MAX_STRING]={0};

    GetArg(szArg1,szLine,1);
    GetArg(szArg2,szLine,2);
	BOOL Hold=(stricmp(szArg2,"hold")==0);

	if (!PressMQ2KeyBind(szArg1,Hold))
	{
		int N=FindMappableCommand(szArg1);
		if (N>=0)
		{
			ExecuteCmd(N,1,0);
			if (!Hold)
				ExecuteCmd(N,0,0);
			return;
		}
		KeyCombo Temp;
		if (ParseKeyCombo(szArg1,Temp))
		{
			if (!stricmp(szArg2,"chat"))
			{
				pWndMgr->HandleKeyboardMsg(Temp.Data[3],1);
				pWndMgr->HandleKeyboardMsg(Temp.Data[3],0);
			}
			else
			{
				MQ2HandleKeyDown(Temp);
				if (!Hold)
					MQ2HandleKeyUp(Temp);
			}
			return;
		}

		MacroError("Invalid mappable command or key combo '%s'",szArg1);
		return;
	}
}

// /popup
VOID PopupText(PSPAWNINFO pChar, PCHAR szLine)
{
   DisplayOverlayText(szLine, CONCOLOR_LIGHTBLUE, 100, 500,500,3000);
}

// /multiline
VOID MultilineCommand(PSPAWNINFO pChar, PCHAR szLine)
{
	if (szLine[0]==0)
	{
		SyntaxError("Usage: /multiline <delimiter> <command>[delimiter<command>[delimiter<command>[. . .]]]");
		return;
	}
    CHAR szArg[MAX_STRING] = {0}; // delimiter(s)
    GetArg(szArg,szLine,1);
    PCHAR szRest = GetNextArg(szLine);
	if (!szRest[0])
		return;
	CHAR Copy[MAX_STRING] = {0};
	strcpy(Copy,szRest);// dont destroy original...
	szRest=strtok(Copy,szArg);
	while(szRest)
	{
		DoCommand(pChar,szRest);
		szRest=strtok(NULL,szArg);
	}
}

// /ranged
VOID do_ranged(PSPAWNINFO pChar, PCHAR szLine)
{
	EQPlayer *pRangedTarget=pTarget;
	if (szLine[0])
	{
		pRangedTarget=GetSpawnByID(atoi(szLine));
		if (!pRangedTarget)
		{
			MacroError("Invalid spawn ID.  Use /ranged with no parameters, or with a spawn ID");
			return;
		}
	}
	if (!pRangedTarget)
	{
		MacroError("No target for ranged attack");
		return;
	}
	if (gbRangedAttackReady)
	{
		pLocalPlayer->DoAttack(0x0B,0,pRangedTarget);
		gbRangedAttackReady=0;
	}
}

// /loadcfg
VOID LoadCfgCommand(PSPAWNINFO pChar, PCHAR szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /loadcfg <filename>");
		return;
	}
	
	if (LoadCfgFile(szLine,false))
		return;
	MacroError("Could not /loadcfg '%s'",szLine);
}

// /dumpbinds
VOID DumpBindsCommand(PSPAWNINFO pChar, PCHAR szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage /dumpbinds <filename>");
		return;
	}
	CHAR szBuffer[MAX_STRING]={0};
	if (!DumpBinds(szLine))
	{
		MacroError("Could not dump binds to %s",szLine);
		return;
	}
	WriteChatColor("Binds dumped to file.");
}

// /squelch
VOID SquelchCommand(PSPAWNINFO pChar, PCHAR szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /squelch <command>");
		return;
	}
	BOOL Temp=gFilterMQ;
	gFilterMQ=true;
	DoCommand(pChar,szLine);
	gFilterMQ=Temp;
}

// /docommand
VOID DoCommandCmd(PSPAWNINFO pChar, PCHAR szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /docommand <command>");
		return;
	}
	DoCommand(pChar,szLine);
}

// /alt
VOID DoAltCmd(PSPAWNINFO pChar, PCHAR szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /alt <command>");
		return;
	}
	bool Old=((PCXWNDMGR)pWndMgr)->KeyboardFlags[2];
	((PCXWNDMGR)pWndMgr)->KeyboardFlags[2]=1;
	DoCommand(pChar,szLine);
	((PCXWNDMGR)pWndMgr)->KeyboardFlags[2]=Old;
}

// /shift
VOID DoShiftCmd(PSPAWNINFO pChar, PCHAR szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /shift <command>");
		return;
	}
	bool Old=((PCXWNDMGR)pWndMgr)->KeyboardFlags[0];
	((PCXWNDMGR)pWndMgr)->KeyboardFlags[0]=1;
	DoCommand(pChar,szLine);
	((PCXWNDMGR)pWndMgr)->KeyboardFlags[0]=Old;
}

// /ctrl
VOID DoCtrlCmd(PSPAWNINFO pChar, PCHAR szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /ctrl <command>");
		return;
	}
	bool Old=((PCXWNDMGR)pWndMgr)->KeyboardFlags[1];
	((PCXWNDMGR)pWndMgr)->KeyboardFlags[1]=1;
	DoCommand(pChar,szLine);
	((PCXWNDMGR)pWndMgr)->KeyboardFlags[1]=Old;
}

VOID NoModKeyCmd(PSPAWNINFO pChar, PCHAR szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /nomodkey <command>");
		return;
	}
	bool KeyboardFlags[4];
	*(DWORD*)&KeyboardFlags=*(DWORD*)&((PCXWNDMGR)pWndMgr)->KeyboardFlags;
	*(DWORD*)&((PCXWNDMGR)pWndMgr)->KeyboardFlags=0;	
	DoCommand(pChar,szLine);
	*(DWORD*)&((PCXWNDMGR)pWndMgr)->KeyboardFlags=*(DWORD*)&KeyboardFlags;
}

 // ***************************************************************************
// Function:    DoSocial
// Description: '/dosocial' command
//              Does (or lists) your programmed socials
// Usage:       /dosocial [list|"social name"]
// ***************************************************************************
VOID DoSocial(PSPAWNINFO pChar, PCHAR szLine)
{
    if (!pSocialList) return;

    DWORD SocialIndex = -1, LineIndex;
   DWORD SocialPage = 0, SocialNum = 0;
   CHAR szBuffer[MAX_STRING] = {0};
   BOOL displayUsage = FALSE;

    GetArg(szBuffer,szLine,1);

    if(  !stricmp(szBuffer,"list")  ) {
        WriteChatColor("Socials: (page,number) name",USERCOLOR_DEFAULT);
        for (SocialIndex=0; SocialIndex < 120; SocialIndex++) {
         SocialPage = SocialIndex/12;
         SocialNum  = SocialIndex - (SocialPage*12);
         if(  strlen(pSocialList[SocialIndex].Name)  ) {
            sprintf(szBuffer,"(%2d,%2d) %s ", SocialPage+1, SocialNum+1, pSocialList[SocialIndex].Name);
            WriteChatColor(szBuffer,USERCOLOR_ECHO_EMOTE);
            for(  LineIndex=0; LineIndex < 5; LineIndex++ ) {
               if(  strlen(pSocialList[SocialIndex].Line[LineIndex])  ) {
                  sprintf(szBuffer,"  %d: %s", LineIndex+1, pSocialList[SocialIndex].Line[LineIndex]);
                  WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
               }
            }
         }
        }
        return;
   } else if(  strlen(szBuffer)  ) { /* assume we have a social name to match */
      for(  unsigned long N = 0; N < 120; N++  ) {
         if(  !stricmp(szBuffer,pSocialList[N].Name)  ) 
		 {
			 SocialIndex=N;
			 break;
		 }
      }
   }
	
   if (gCurrentSocial==-1)
   {
	   gCurrentSocial=SocialIndex<<3;
   }
   else
   {
	if(  SocialIndex < 120  ) {
		for(  LineIndex = 0; LineIndex < 5; LineIndex++  ) {
			if(  strlen(pSocialList[SocialIndex].Line[LineIndex])  ) DoCommand(pChar,pSocialList[SocialIndex].Line[LineIndex]);
		}
	} else {
		if(  strlen(szLine)  ) {
			sprintf( szBuffer, "Invalid Argument(s): %s", szLine );
			WriteChatColor(szBuffer,USERCOLOR_DEFAULT);
		}
		SyntaxError("Usage: /dosocial <list|\"social name\">",USERCOLOR_DEFAULT );
	}
   }
} 

// /timed
VOID DoTimedCmd(PSPAWNINFO pChar, PCHAR szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /timed <deciseconds> <command>");
		return;
	}
    CHAR szArg[MAX_STRING] = {0}; // delay
    GetArg(szArg,szLine,1);
    PCHAR szRest = GetNextArg(szLine);
	if (!szRest[0])
		return;
	TimedCommand(szRest,atoi(szArg)*100);
}

VOID ClearErrorsCmd(PSPAWNINFO pChar, PCHAR szLine)
{
	gszLastNormalError[0]=0;
	gszLastSyntaxError[0]=0;
	gszLastMQ2DataError[0]=0;
}

VOID CombineCmd(PSPAWNINFO pChar, PCHAR szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /combine <pack>");
		return;
	}
	CXWnd *pWnd=FindMQ2Window(szLine);
	if (!pWnd)
	{
		MacroError("Window '%s' not open",szLine);
		return;
	}
	if ((DWORD)pWnd->pvfTable!=CContainerWnd__vftable)
	{
		MacroError("Window '%s' not container window",szLine);
		return;
	}
	((CContainerWnd*)pWnd)->HandleCombine();
}

VOID DropCmd(PSPAWNINFO pChar, PCHAR szLine)
{
	if (((PCHARINFO)pCharData)->Cursor)
	{
		if (((EQ_Item*)((PCHARINFO)pCharData)->Cursor)->CanDrop(1))
		{
			pEverQuest->DropHeldItemOnGround(1);
		}
	}
}

VOID HudCmd(PSPAWNINFO pChar, PCHAR szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /hud <normal|underui|always>");
		WriteChatColor("Note: 'always' forces 'underui' also. The Network Status indicator is not 'always' drawn and is toggled with F11.");
		return;
	}
	else
	if (!stricmp(szLine,"normal"))
	{
		WritePrivateProfileString("MacroQuest","HUDMode","Normal",gszINIFilename);
		gbAlwaysDrawMQHUD=false;
		gbHUDUnderUI=false;
	}
	else
	if (!stricmp(szLine,"underui"))
	{
		WritePrivateProfileString("MacroQuest","HUDMode","UnderUI",gszINIFilename);
		gbHUDUnderUI=true;
		gbAlwaysDrawMQHUD=false;
	}
	else
	if (!stricmp(szLine,"always"))
	{
		WritePrivateProfileString("MacroQuest","HUDMode","Always",gszINIFilename);
		gbHUDUnderUI=true;
		gbAlwaysDrawMQHUD=true;
	}
}

VOID CaptionCmd(PSPAWNINFO pChar, PCHAR szLine)
{
	CHAR Arg1[MAX_STRING]={0};
	GetArg(Arg1,szLine,1);
	if (!Arg1[0])
	{
		SyntaxError("Usage: /caption <list|type <value>|update #>");
		return;
	}
	if (!stricmp(Arg1,"list"))
	{
		WriteChatf("\ayPlayer1\ax: \ag%s\ax",gszSpawnPlayerName[1]);
		WriteChatf("\ayPlayer2\ax: \ag%s\ax",gszSpawnPlayerName[2]);
		WriteChatf("\ayPlayer3\ax: \ag%s\ax",gszSpawnPlayerName[3]);
		WriteChatf("\ayPlayer4\ax: \ag%s\ax",gszSpawnPlayerName[4]);

		WriteChatf("\ayNPC\ax: \ag%s\ax",gszSpawnNPCName);
		WriteChatf("\ayPet\ax: \ag%s\ax",gszSpawnPetName);
		WriteChatf("\ayCorpse\ax: \ag%s\ax",gszSpawnCorpseName);
		return;
	}
	PCHAR pCaption=0;
	if (!stricmp(Arg1,"Player1"))
	{
		pCaption=gszSpawnPlayerName[1];
	} else if (!stricmp(Arg1,"Player2"))
	{
		pCaption=gszSpawnPlayerName[2];
	} else if (!stricmp(Arg1,"Player3"))
	{
		pCaption=gszSpawnPlayerName[3];
	} else if (!stricmp(Arg1,"Player4"))
	{
		pCaption=gszSpawnPlayerName[4];
	} else if (!stricmp(Arg1,"Pet"))
	{
		pCaption=gszSpawnPetName;
	} else if (!stricmp(Arg1,"NPC"))
	{
		pCaption=gszSpawnNPCName;
	} else if (!stricmp(Arg1,"Corpse"))
	{
		pCaption=gszSpawnCorpseName;
	} else if (!stricmp(Arg1,"Update"))
	{
		gMaxSpawnCaptions=atoi(GetNextArg(szLine));
		if (gMaxSpawnCaptions<8)
			gMaxSpawnCaptions=8;
		if (gMaxSpawnCaptions>70)
			gMaxSpawnCaptions=70;
		WritePrivateProfileString("Captions","Update",itoa(gMaxSpawnCaptions,Arg1,10),gszINIFilename);
		WriteChatf("\ay%d\ax nearest spawns will have their caption updated each pass.",gMaxSpawnCaptions);
		return;
	}
	else
	{
		MacroError("Invalid caption type '%s'",Arg1);
		return;
	}
    strcpy(pCaption, GetNextArg(szLine));
	WritePrivateProfileString("Captions",Arg1,pCaption,gszINIFilename);
	ConvertCR(pCaption);
	WriteChatf("\ay%s\ax caption set.",Arg1);
}

VOID NoParseCmd(PSPAWNINFO pChar, PCHAR szLine)
{
	if (!szLine[0])
	{
		SyntaxError("Usage: /noparse <command>");
		return;
	}
	bAllowCommandParse=false;
	DoCommand(pChar,szLine);
	bAllowCommandParse=true;
}

VOID AltAbility(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szBuffer[MAX_STRING] = {0};
    CHAR szCommand[MAX_STRING] = {0};
	CHAR szSpellInfo[MAX_STRING] = {0};
    PCHAR szName = NULL;
    GetArg(szCommand,szLine,1);
    szName = GetNextArg(szLine);
	unsigned long nAbility=0;
	int i=0;
	MQ2TicksType szTime;

    if ((szName[0]==0) || (szCommand[0]==0)) {
        SyntaxError("Usage: /aa list [all|timers], /aa info [ability name], or /aa act [ability name]");
        return;
    }

    if (!stricmp(szCommand,"list")) 
	{
		if (!stricmp(szName,"all"))
		{
			WriteChatColor("Alternative Abilities (Complete List)", CONCOLOR_YELLOW );
			WriteChatColor("-------------------------------------", USERCOLOR_WHO);
			for (nAbility=0 ; nAbility<NUM_ALT_ABILITIES ; nAbility++)
			{
				if ( ((PALTADVMGR)pAltAdvManager)->AltAbilities->AltAbilityList->Abilities[nAbility])
				{
					if ( PALTABILITY pAbility=((PALTADVMGR)pAltAdvManager)->AltAbilities->AltAbilityList->Abilities[nAbility]->Ability) 
					{
						if (PlayerHasAAAbility(pChar->pCharInfo,pAbility->Index))
						{
							sprintf(szBuffer,"[ %d: %s ]", pAbility->ID, pStringTable->getString(pAbility->nName,0) );
							WriteChatColor(szBuffer,USERCOLOR_WHO);
						}
					}
				}
			}
		}
		else if (!stricmp(szName,"timers"))
		{
			WriteChatColor("Alternative Abilities With Timers", CONCOLOR_YELLOW );
			WriteChatColor("---------------------------------", USERCOLOR_WHO);
			for (nAbility=0 ; nAbility<NUM_ALT_ABILITIES ; nAbility++)
			{
				if ( ((PALTADVMGR)pAltAdvManager)->AltAbilities->AltAbilityList->Abilities[nAbility])
				{
					if ( PALTABILITY pAbility=((PALTADVMGR)pAltAdvManager)->AltAbilities->AltAbilityList->Abilities[nAbility]->Ability) 
					{
						if ((pAltAdvManager->GetCalculatedTimer(pPCData,pAbility)) > 0)
						{
							if (pAltAdvManager->IsAbilityReady(pPCData,pAbility,0))
							{
								if (PlayerHasAAAbility(pChar->pCharInfo,pAbility->Index))
								{
									sprintf(szBuffer,"[ %d: %s ] (Reuse Time: %d seconds) <Ready>",
										pAbility->ID, pStringTable->getString(pAbility->nName,0), 
										pAltAdvManager->GetCalculatedTimer(pPCData,pAbility) );
									WriteChatColor(szBuffer,USERCOLOR_WHO);
								}
							}
							else
							{
								pAltAdvManager->IsAbilityReady(pPCData,pAbility,&i);
								if (PlayerHasAAAbility(pChar->pCharInfo,pAbility->Index))
								{
									sprintf(szBuffer,"[ %d: %s ] (Reuse Time: %d seconds) <Ready in %d seconds>",
										pAbility->ID, pStringTable->getString(pAbility->nName,0), 
										pAltAdvManager->GetCalculatedTimer(pPCData,pAbility), i );
									WriteChatColor(szBuffer,USERCOLOR_WHO);
								}
							}
						}
					}
				}
			}
		}
		else 
		{
			SyntaxError("Usage: /aa list [all|timers], /aa info [ability name], or /aa act [ability name]");
			return;
		}
    }
	else if (!stricmp(szCommand,"info")) 
	{
		for (unsigned long nAbility=0 ; nAbility<NUM_ALT_ABILITIES ; nAbility++)
			{
				if ( ((PALTADVMGR)pAltAdvManager)->AltAbilities->AltAbilityList->Abilities[nAbility])
				{
					if ( PALTABILITY pAbility=((PALTADVMGR)pAltAdvManager)->AltAbilities->AltAbilityList->Abilities[nAbility]->Ability) 
					{
						if (!stricmp(pStringTable->getString(pAbility->nName,0),szName))
						{

							WriteChatColor("Alternative Advancement Ability Information", CONCOLOR_YELLOW);
							WriteChatColor("-------------------------------------------", USERCOLOR_WHO);
							
							if ((pAltAdvManager->GetCalculatedTimer(pPCData,pAbility)) > 0)
							{//has a timer
								if (!(pAltAdvManager->IsAbilityReady(pPCData,pAbility,0)))
								{//it's not ready
									pAltAdvManager->IsAbilityReady(pPCData,pAbility,&i);
									sprintf(szBuffer,"[ %d: %s ] %s", pAbility->ID, pStringTable->getString(pAbility->nName,0), pStringTable->getString(pAbility->nDesc,0) );
									WriteChatColor(szBuffer,USERCOLOR_WHO);
									sprintf(szBuffer,"Min Level: %d, Cost: %d, Max Rank: %d, Type: %d, Reuse Time: %d seconds",
										pAbility->MinLevel, pAbility->Cost, pAbility->MaxRank, pAbility->Type, pAltAdvManager->GetCalculatedTimer(pPCData,pAbility));
									WriteChatColor(szBuffer,USERCOLOR_WHO);
									if (pAbility->SpellID > 0)
									{
										sprintf(szBuffer,"Casts Spell: %s", GetSpellNameByID(pAbility->SpellID) );
										WriteChatColor(szBuffer, USERCOLOR_WHO);
									}
									sprintf(szBuffer,"Ready: No (%d seconds until refresh)", i );
									WriteChatColor(szBuffer,USERCOLOR_WHO);
								}
								else
								{
									sprintf(szBuffer,"[ %d: %s ] %s", pAbility->ID, pStringTable->getString(pAbility->nName,0), pStringTable->getString(pAbility->nDesc,0) );
									WriteChatColor(szBuffer,USERCOLOR_WHO);
									sprintf(szBuffer,"Min Level: %d, Cost: %d, Max Rank: %d, Type: %d, Reuse Time: %d seconds",
										pAbility->MinLevel, pAbility->Cost, pAbility->MaxRank, pAbility->Type, pAltAdvManager->GetCalculatedTimer(pPCData,pAbility));
									WriteChatColor(szBuffer,USERCOLOR_WHO);
									if (pAbility->SpellID > 0)
									{
										sprintf(szBuffer,"Casts Spell: %s", GetSpellNameByID(pAbility->SpellID));
										WriteChatColor(szBuffer, USERCOLOR_WHO);
									}
									sprintf(szBuffer,"Ready: Yes");
									WriteChatColor(szBuffer,USERCOLOR_WHO);		
								}
							}
							else
							{
								pAltAdvManager->IsAbilityReady(pPCData,pAbility,&i);
								sprintf(szBuffer,"[ %d: %s ] %s", pAbility->ID, pStringTable->getString(pAbility->nName,0), pStringTable->getString(pAbility->nDesc,0) );
								WriteChatColor(szBuffer,USERCOLOR_WHO);
								sprintf(szBuffer,"Min Level: %d, Cost: %d, Max Rank: %d, Type: %d",
									pAbility->MinLevel, pAbility->Cost, pAbility->MaxRank, pAbility->Type);
								WriteChatColor(szBuffer,USERCOLOR_WHO);
								if (pAbility->SpellID > 0)
								{
									sprintf(szBuffer,"Casts Spell: %s", GetSpellNameByID(pAbility->SpellID) );
									WriteChatColor(szBuffer, USERCOLOR_WHO);
								}
							}
						}
					}
				}
			}
	}
	else if (!stricmp(szCommand,"act")) 
	{
		for (unsigned long nAbility=0 ; nAbility<NUM_ALT_ABILITIES ; nAbility++)
		{
			if ( ((PALTADVMGR)pAltAdvManager)->AltAbilities->AltAbilityList->Abilities[nAbility])
			{
				if ( PALTABILITY pAbility=((PALTADVMGR)pAltAdvManager)->AltAbilities->AltAbilityList->Abilities[nAbility]->Ability) 
				{
					if (!stricmp(pStringTable->getString(pAbility->nName,0),szName))
					{
						sprintf(szBuffer,"/alt act %d", pAbility->ID);
						DoCommand(pChar,szBuffer);
					}
				}
			}
		}
	}
	else
	{
        SyntaxError("Usage: /aa list [all|timers|ready], /aa info [ability name], or /aa act [ability name]");
        return;
	}
	return;
}