/*****************************************************************************
    eqlib.dll: MacroQuest's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic

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
#include "stdafx.h"
#include "MQ2Main.h"

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
    WriteChatBuffer(ToUnloadString,USERCOLOR_DEFAULT);
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
        WriteChatBuffer("Couldn't find any macros",USERCOLOR_DEFAULT);
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

    WriteChatBuffer("Macro list",USERCOLOR_WHO);
    WriteChatBuffer("----------------",USERCOLOR_WHO);
    for (a=0;a<Count;a++) {
        WriteChatBuffer(szName[a],USERCOLOR_WHO);
    }

}

// ***************************************************************************
// Function:    Items
// Description: Our '/items' command
//              Lists ground item info
// Usage:       /items <filter>
// ***************************************************************************
PCHAR GetFriendlyNameForGroundItem(PGROUNDITEM pItem)
{
    CHAR szName[MAX_STRING] = {0};
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
    return strdup(szName);
}

VOID Items(PSPAWNINFO pChar, PCHAR szLine)
{
    bRunNextCommand = TRUE;

    if (!EQADDR_ITEMS) return;
    if (!*EQADDR_ITEMS) return;
    PGROUNDITEM pItem = *EQADDR_ITEMS;
    DWORD Count=0;
    CHAR szBuffer[MAX_STRING] = {0};
    PCHAR szName = NULL;
    WriteChatColor("Items on the ground:", USERCOLOR_DEFAULT);
    WriteChatColor("---------------------------", USERCOLOR_DEFAULT);
    while (pItem) {
        szName = GetFriendlyNameForGroundItem(pItem);

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
        free(szName);

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

    if (!EQADDR_ITEMS) return;
    if (!*EQADDR_ITEMS) return;
    PGROUNDITEM pItem = *EQADDR_ITEMS;
    CHAR Arg1[MAX_STRING] = {0};
    CHAR Arg2[MAX_STRING] = {0};
    CHAR szBuffer[MAX_STRING] = {0};
    PCHAR szName = NULL;
    FLOAT cDistance = 100000.0f;
    ZeroMemory(&EnviroTarget,sizeof(EnviroTarget));
    pGroundTarget = NULL;
    GetArg(Arg1,szLine,1);
    GetArg(Arg2,szLine,2);
    while (pItem) {
        szName = GetFriendlyNameForGroundItem(pItem);
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
            tSpawn.GuildID=pItem->DxID;
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
        gLastError[0]=0;
        WriteChatBuffer(szBuffer,USERCOLOR_DEFAULT);
        if (stricmp(Arg2,"notarget") && EQADDR_TARGET) *EQADDR_TARGET = &EnviroTarget;
    } else {
        if (EQADDR_TARGET && (*EQADDR_TARGET == &EnviroTarget))
            *EQADDR_TARGET = NULL;
        sprintf(szBuffer,"Couldn't find '%s'.",szLine);
        strcpy(gLastError,"ITEM_NOTFOUND");
        WriteChatBuffer(szBuffer,CONCOLOR_RED);
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

   if (!EQADDR_DOORS) return;
   if (!*EQADDR_DOORS) return;
       PDOORTABLE pDoorTable = *EQADDR_DOORS;
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

   if (!EQADDR_DOORS) return;
   if (!*EQADDR_DOORS) return;
    PDOORTABLE pDoorTable = *EQADDR_DOORS;
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
         WriteChatBuffer("DoorTarget: id specified but no number provided.", CONCOLOR_RED);
         strcpy(gLastError, "DOORTARGET_BADCOMMAND");
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
      gLastError[0]=0;
      WriteChatBuffer(szBuffer,USERCOLOR_DEFAULT);
	  if (stricmp(Arg2,"notarget") && EQADDR_TARGET) *EQADDR_TARGET = &DoorEnviroTarget;
   } else {
      if (EQADDR_TARGET) *EQADDR_TARGET = NULL;
      sprintf(szBuffer,"Couldn't find door '%s'.",szLine);
      strcpy(gLastError,"ITEM_NOTFOUND");
      WriteChatBuffer(szBuffer,CONCOLOR_RED);
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
      if (pCharInfo->Inventory[nInvIdx] != NULL) {
         BOOL Found = FALSE;
         PITEMDB ItemDB = gItemDB;
         while (ItemDB) {
            if (ItemDB->ID == pCharInfo->Inventory[nInvIdx]->Item->ItemNumber) {
               Found = TRUE;
            }
            ItemDB = ItemDB->pNext;
         }
         if (!Found) {
            PITEMDB Item = (PITEMDB)malloc(sizeof(ITEMDB));
            Item->pNext = gItemDB;
            Item->ID = pCharInfo->Inventory[nInvIdx]->Item->ItemNumber;
            strcpy(Item->szName, pCharInfo->Inventory[nInvIdx]->Item->Name);
            DebugSpew("   New Item found - %d: %s", Item->ID, Item->szName);
            gItemDB = Item;
         }
         if (pCharInfo->Inventory[nInvIdx]->Item->Type == ITEMTYPE_PACK) {
			 pContainer = pCharInfo->Inventory[nInvIdx];
            DebugSpew("   Opening Pack");
            for (int nPackIdx = 0; nPackIdx < pCharInfo->Inventory[nInvIdx]->Item->Container.Slots; nPackIdx++) {
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

            for (nPackIdx = 0; nPackIdx < pCharInfo->Bank[nInvIdx]->Item->Container.Slots; nPackIdx++) {
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
    if (!EQADDR_SPELLBOOKWND || !cmdLoadSpells) return;
    DWORD Favorite = (DWORD)&MemSpellFavorite;
   CHAR szGem[MAX_STRING] = {0};
    DWORD sp;
   WORD Gem = -1;
   CHAR SpellName[MAX_STRING] = {0};
   PCHARINFO pCharInfo = NULL;
    DWORD SpellBookWnd = *EQADDR_SPELLBOOKWND;
    if (!SpellBookWnd) return;
   if (NULL == (pCharInfo = GetCharInfo())) return;

   GetArg(szGem,szLine,1);
   GetArg(SpellName,szLine,2);
   Gem = atoi(szGem);
   if (Gem<1 || Gem>8) return;
   Gem--;

   PSPELLLIST pSpell = GetSpellByName(SpellName);
    if (!pSpell) return;
    if (pSpell->Level[pChar->Class-1]>pChar->Level) return;

    ZeroMemory(&MemSpellFavorite,sizeof(MemSpellFavorite));
    strcpy(MemSpellFavorite.Name,"Mem a Spell");
    MemSpellFavorite.Byte_3A=1;
    for (sp=0;sp<8;sp++) MemSpellFavorite.SpellId[sp]=0xFFFFFFFF;
    MemSpellFavorite.SpellId[Gem] = pSpell->ID;

   __asm {
    push ecx;
    mov ecx, dword ptr [SpellBookWnd];
        push 8;
        push dword ptr [Favorite];
        call dword ptr [cmdLoadSpells];
    pop ecx;
   }
}

// ***************************************************************************
// Function:    Macro
// Description: Our '/macro' command
// Usage:       /macro <filename>
// ***************************************************************************
VOID Macro(PSPAWNINFO pChar, PCHAR szLine)
{
    bRunNextCommand = TRUE;
    CHAR szTemp[MAX_STRING] = {0};
    CHAR Filename[MAX_STRING] = {0};
    PCHAR Params = NULL;
    PCHAR szNext = NULL;
    BOOL InBlockComment = FALSE;
    if (szLine[0] == 0) {
        WriteChatBuffer("Usage: /macro <filename> [param [param...]]", USERCOLOR_DEFAULT);
        return;
    }

    GetArg(szTemp,szLine,1);
    Params = GetNextArg(szLine);

    strcpy(gszMacroName,szTemp);
    if (!strstr(szTemp,".")) strcat(szTemp,".mac");
    sprintf(Filename,"%s\\%s",gszMacroPath, szTemp);

    FILE *fMacro = fopen(Filename,"rt");
    if (!fMacro) {
        sprintf(szTemp,"Couldn't open macro file: %s",Filename);
        WriteChatBuffer(szTemp,CONCOLOR_RED);
        gszMacroName[0]=0;
        gRunning = 0;
        return;
    }
    if (gMacroBlock) EndMacro(pChar,"keep keys vars arrays timers");
    gRunning = GetTickCount();
    gEventChat = 0;
    strcpy(gszMacroName,szTemp);
    DebugSpew("Macro - Loading macro: %s",Filename);
    DWORD LineNumber = 0;
    PMACROBLOCK pAddedLine = NULL;
    while (!feof(fMacro)) {
        fgets(szTemp,MAX_STRING,fMacro);
        LineNumber++;
        while ((strlen(szTemp)>0) && (szTemp[strlen(szTemp)-1] < 32)) szTemp[strlen(szTemp)-1]=0;
        if (!strncmp(szTemp,"|**",3)) {
            InBlockComment=TRUE;
        }
        if (!InBlockComment) {
            if (NULL == (pAddedLine=AddMacroLine(szTemp))) {
                WriteChatBuffer("Unable to add macro line.",CONCOLOR_RED);
                fclose(fMacro);
                gszMacroName[0]=0;
                gRunning = 0;
                return;
            } else if (1 != (DWORD)pAddedLine) {
                pAddedLine->LineNumber = LineNumber;
                strcpy(pAddedLine->SourceFile, GetFilenameFromFullPath(Filename));
            }
        } else {
            DebugSpew("Macro - BlockComment: %s",szTemp);
            if (!strncmp(&szTemp[strlen(szTemp)-3],"**|",3)) {
                InBlockComment=FALSE;
            }
        }
    }
    fclose(fMacro);
    PDEFINE pDef;
    while (pDefines) {
        pDef = pDefines->pNext;
        free(pDefines);
        pDefines = pDef;
    }
    strcpy(szTemp, "Main");
    if (Params[0] !=0) {
        strcat(szTemp, " ");
        strcat(szTemp, Params);
    }
    DebugSpew("Macro - Starting macro with '/call %s'",szTemp);
    Call(pChar, szTemp);
    if ((gMacroBlock) && (gMacroBlock->pNext)) gMacroBlock = gMacroBlock->pNext;
    if ((!gMacroBlock) || (!gMacroStack)) {
        gszMacroName[0]=0;
        gRunning = 0;
    }
}


// ***************************************************************************
// Function:    FindItem
// Description: Our '/finditem' command
//              Brings the named item onto the cursor.
// Usage:       /finditem itemname
// ***************************************************************************
VOID FindItem(PSPAWNINFO pChar, PCHAR szLine)
{
   bRunNextCommand = TRUE;
   UCHAR PriSlot;
   CHAR szSearch[MAX_STRING] = {0};
   CHAR szBuffer[MAX_STRING] = {0};
   BOOL Exact= TRUE;
   BOOL ByID=FALSE;
   gLastFind = LASTFIND_NOTFOUND;
   gLastFindSlot[0]=0;
   PCONTENTS pContainer = NULL;
   PCHARINFO pCharInfo = NULL;
   if (NULL == (pCharInfo = GetCharInfo())) return;
   if (szLine[0] == 0) {
      WriteChatBuffer("Usage: /finditem [similar|id] \"item name\"|\"item id\"",USERCOLOR_DEFAULT);
      strcpy(gLastError,"FIND_NOTFOUND");
      return;
   }
   if (pCharInfo->Cursor) {
      WriteChatBuffer("Your hands must be empty to find an item.",CONCOLOR_RED);
      strcpy(gLastError,"FIND_HANDSFULL");
      return;
   }
   GetArg(szSearch,szLine,1);
   if (!stricmp(szSearch,"similar")) {
      Exact=FALSE;
      GetArg(szSearch,szLine,2);
   }
   if (!stricmp(szSearch,"id")) {
      ByID=TRUE;
      GetArg(szSearch,szLine,2);
   }

   _strlwr(szSearch);
   for (PriSlot=0;PriSlot<8;PriSlot++) {
       if (!pCharInfo->Inventory[22+PriSlot]) continue;
      PCONTENTS pSlot = pCharInfo->Inventory[22+PriSlot]; 
	  pContainer = pCharInfo->Inventory[22+PriSlot];
      CHAR szTemp[MAX_STRING] = {0};
      if (!pSlot) continue;
      _strlwr(strcpy(szTemp,pSlot->Item->Name)); 
      if (
            (
               (!Exact) &&
               (strstr(szTemp,szSearch))
            ) || (
               (Exact) &&
               (!strcmp(szTemp,szSearch))
            ) || (
                (ByID) &&
				(pSlot->Item->ItemNumber == (DWORD)atoi(szSearch)) 
           )
      ) {
         CHAR szBuf[MAX_STRING] = {0};
         gLastFind = LASTFIND_PRIMARY;
         DebugSpew("FindItem - Found '%s' in primary inventory slot %d",pSlot->Item->Name,PriSlot); 
         sprintf(gLastFindSlot,"inv,%d",PriSlot);
         sprintf(szBuf,"left inv %d",PriSlot);
         Click(pChar,szBuf);
         gLastError[0]=0;
         return;
      }
      if (pSlot->Item->Type == ITEMTYPE_PACK) { 
         UCHAR BagSlot;
         DebugSpew("FindItem - Looking inside pack %d: '%s'",PriSlot,pSlot->Item->Name); 
         for (BagSlot=0;BagSlot < (DWORD)pSlot->Item->Container.Slots;BagSlot++) { 
             if (!pContainer->Contents[BagSlot]) continue;
             PITEMINFO pItem = pContainer->Contents[BagSlot]->Item;
            if (!pItem) continue;
            _strlwr(strcpy(szTemp,pItem->Name));
            if (
                  (
                     (!Exact) &&
                     (strstr(szTemp,szSearch))
                  ) || (
                     (Exact) &&
                     (!strcmp(szTemp,szSearch))
                  ) || (
                     (ByID) &&
                     (pItem->ItemNumber == (DWORD)atoi(szSearch))
                  )
            ) {
               CHAR szBuf[MAX_STRING] = {0};
               CHAR tempstr[MAX_STRING] = {0};
               BOOL WasOpen = FALSE;
               DebugSpew("FindItem - Found '%s' in slot %d of '%s' (primary slot %d)",pItem->Name,BagSlot,pSlot->Item->Name,PriSlot); 
               gLastFind = PriSlot;
             if (pContainer->Open == 0) {
                  sprintf(szBuf,"right inv %d",PriSlot);
                  Click(pChar,szBuf);
                  WasOpen = TRUE;
             }
             if (pContainer->Open == 0) {
                  strcpy(gLastError,"FIND_PACKNOTOPEN");
                return;
               }
               sprintf(gLastFindSlot,"%d,%d",PriSlot,BagSlot);
               sprintf(szBuf,"left pack %d %d",PriSlot,BagSlot);
               Click(pChar,szBuf);
               if (WasOpen) {
                  sprintf(szBuf,"left pack %d done",PriSlot);
                  Click(pChar,szBuf);
               }
               gLastError[0]=0;
               return;
            }
         }
      }
   }
   sprintf(szBuffer,"Couldn't find a '%s'",szSearch);
   strcpy(gLastError,"FIND_NOTFOUND");
   WriteChatBuffer(szBuffer,CONCOLOR_RED);
}


// ***************************************************************************
// Function:    SelectItem
// Description: Our '/SelectItem' command
//              targets an item.
// Usage:       /SelectItem list || "item name" || slot <slotnumber> && merchant || self
// ***************************************************************************
// uses public: void __thiscall CMerchantWnd::SelectBuySellSlot(int,class CTextureAnimation *)
// ***************************************************************************
DWORD SelectFind(char* szSearch, char* szOption )
{
	UCHAR PriSlot;
	CHAR szBuffer[MAX_STRING] = {0};
	BOOL Exact= TRUE;
	PCHARINFO pCharInfo = NULL;
	PCONTENTS pContainer = NULL;
	DWORD slotcounter = 250;
	DWORD BagCounter = 21;
	gLastFind = LASTFIND_NOTFOUND; 
	gLastFindSlot[0]=0;
	PEQSLOTLIST pSlotList = (PEQSLOTLIST)*EQADDR_SLOTLIST;
	PEQCURRENTSELECTION CurrentSelection = NULL;
	if (NULL == (pCharInfo = GetCharInfo())) return (0);
	char Link[256];
	for (PriSlot=0;PriSlot<8;PriSlot++)
	{
		if (!pCharInfo->Inventory[22+PriSlot]) {
			BagCounter++;
			continue;
		}
		PCONTENTS pSlot = pCharInfo->Inventory[22+PriSlot];
		pContainer = pCharInfo->Inventory[22+PriSlot];
		DebugSpew("pContainer %d open staus = %d",pContainer->ItemSlot,pContainer->Open);
		CHAR szTemp[MAX_STRING] = {0};
		BagCounter++;//first bag set counter to 22
		DebugSpew("SelectFind - real bag is %d)",BagCounter);
		if (!pSlot)
		{
			continue;
		}
		if (!stricmp(szOption,"list"))
		{
			if (pSlot->Item->Type == ITEMTYPE_NORMAL)
			{
				GetItemLink(pSlot,Link);
				slotcounter = slotcounter+10;
				sprintf(szBuffer,"%d:	'%s'	:(slot %d)",pSlot->Item->ItemNumber,Link,BagCounter);
				WriteChatBuffer(szBuffer,CONCOLOR_YELLOW);
			}
		} else {
			_strlwr(strcpy(szTemp,pSlot->Item->Name));
			if (((!Exact) && (strstr(szTemp,szSearch))) || ((Exact) && (!_stricmp(szTemp,szSearch))))
			{
				PCSIDLWND pInvWindow = NULL;
				pInvWindow = (PCSIDLWND)*EQADDR_INVENTORYWND;
				gLastFind = LASTFIND_PRIMARY;
				sprintf(gLastFindSlot,"inv %d",PriSlot); 
				gLastError[0]=0;
				if (!EQADDR_INVENTORYWND || !pInvWindow)
					strcpy(gLastError,"EQADDR_INVENTORYWND bad offset");
				if(pInvWindow->Show) {
					return (BagCounter);
				} else {
					strcpy(gLastError,"INV_NOTOPEN");
				}
			}
		}
		if (pSlot->Item->Type == ITEMTYPE_PACK)
		{	
			UCHAR BagSlot;
			DebugSpew("SelectFind - Looking inside pack %d: '%s' %d slots, real slot is %d",PriSlot,pSlot->Item->Name,pSlot->Item->Container.Slots,BagCounter);
			for (BagSlot=0;BagSlot<10;BagSlot++)
			{
				if (!pContainer->Contents[BagSlot]) {
					slotcounter++;
					continue;
				}
				PITEMINFO pItem = pContainer->Contents[BagSlot]->Item;
				slotcounter++;
				if (!pItem)
				{
					continue;
				}

				if (!stricmp(szOption,"list"))
				{
					GetItemLink(pContainer->Contents[BagSlot],Link);
					sprintf(szBuffer,"%d:	'%s'	:(slot %d)",pItem->ItemNumber,Link,slotcounter);
					WriteChatBuffer(szBuffer,CONCOLOR_YELLOW);
				}
				else
				{
					_strlwr(strcpy(szTemp,pItem->Name));
					if (((!Exact) && (strstr(szTemp,szSearch))) || ((Exact) && (!_stricmp(szTemp,szSearch))))
					{
						gLastFind = PriSlot; 
						sprintf(gLastFindSlot,"pack %d %d",PriSlot,BagSlot);
						gLastError[0]=0;
						if (pContainer->Open) {
							return (slotcounter);
						} else {
							strcpy(gLastError,"PACK_NOTOPEN");
						}

					}
				}
			}
		}
	}
	sprintf(szBuffer,"Couldn't find a '%s'",szSearch); 
	strcpy(gLastError,"FIND_NOTFOUND"); 
	WriteChatBuffer(szBuffer,CONCOLOR_RED);
	return (59999);
}
VOID SelectItem(PSPAWNINFO pChar, PCHAR szLine)
{
	bRunNextCommand = FALSE;
	PEQSLOTLIST pSlotList = (PEQSLOTLIST)*EQADDR_SLOTLIST;
	PEQCURRENTSELECTION CurrentSelection = NULL;
	PEQCURRENTSELECTION FixedSelection = NULL;
	PCSIDLWND Slot = NULL;
	PCSIDLWND FixedSlot = NULL;

   PEQMERCHWINDOW pMainWindow = (PEQMERCHWINDOW)*EQADDR_CLASSMERCHWND;
	PEQCURRENTSELECTION pSelectedSlot = (PEQCURRENTSELECTION)*EQADDR_CLASSTEXTUREANIMATION;
   PCSIDLWND pCurSlot = NULL;
   PCSIDLWND pDestSlot = NULL;
	PCHARINFO pCharInfo = NULL;
	PITEMINFO pItemInfo = NULL;
	DWORD MerchTraderWnd = *EQADDR_CLASSMERCHWND;
	BOOL Found, Force;
	CHAR szBuffer[MAX_STRING] = {0};
	CHAR szArg1[MAX_STRING] = {0};
	CHAR szArg2[MAX_STRING] = {0};
	CHAR szArg3[MAX_STRING] = {0};
	int SelectSlot, i;
	DebugSpew("/selectitem : yes the command works at least to this point");
	if (szLine[0] == 0) {
		WriteChatBuffer("Usage: /selectitem 'item name' merchant || self : slot <number> merchant || self : list merchant || self",USERCOLOR_DEFAULT);
		strcpy(gLastError,"FIND_NOTFOUND");
		return;
	}
	if (NULL == (pCharInfo = GetCharInfo())) return;
	if (!MerchTraderWnd || !cmdSelectItem) return;
	GetArg(szArg1,szLine,1);
	GetArg(szArg2,szLine,2);
	GetArg(szArg3,szLine,3);
	Found = FALSE;
	Force = FALSE;
	BOOL PlayerSelection = FALSE;
   
	if ((!_stricmp(szArg1,"slot") && (szArg2[0]!=0) && (!_stricmp(szArg3,"merchant"))))
	{   
		i = atoi(szArg2);
		i--;
		if (pMainWindow->ItemDesc[i] == NULL)
		return;
		SelectSlot = (int)pMainWindow->SlotsHandles[i]->SlotID;
		Found = TRUE;
	}

	if ((!_stricmp(szArg1,"slot") && (szArg2[0]!=0) && (!_stricmp(szArg3,"self"))))
	{	
		i = atoi(szArg2);
		SelectSlot = (int)i;//+250;
		{
			int j=0;
			for (j=0;j<362;j++)
			{
				if (pSlotList->InvSlots[j])
				{
					CurrentSelection = (PEQCURRENTSELECTION)pSlotList->InvSlots[j];
					Slot = (PCSIDLWND)CurrentSelection->SelectedWnd;
					if ((int)Slot->SlotID == SelectSlot)
					{
						FixedSelection=CurrentSelection;
						FixedSlot = Slot;
						PlayerSelection = TRUE;
						Found = TRUE;
						break;
					}
				}
			}
			i = 0;
		}
	}
	//list merchant inventory
	if ((!_stricmp(szArg1,"list") && (!_stricmp(szArg2,"merchant") && (Found == FALSE))))
   {
      WriteChatBuffer("Merchant Inventory:",USERCOLOR_DEFAULT);
      WriteChatBuffer("--------------------------",USERCOLOR_DEFAULT);
      i=0;
	  char Link[256];
      while (i < 79)
      {
            if (pMainWindow->ItemDesc[i] != NULL)
            {
				GetItemLink(pMainWindow->ItemDesc[i],Link);
				sprintf(szBuffer,"%d:'%s' : (slot %d)",pMainWindow->ItemDesc[i]->Item->ItemNumber,Link,(pMainWindow->SlotsHandles[i]->SlotID-5999));
               WriteChatBuffer(szBuffer,CONCOLOR_YELLOW);
            }else
				return;
         i++;
      }
		
	}
	//list characters inventory
	if ((!_stricmp(szArg1,"list") && (!_stricmp(szArg2,"self") && (Found == FALSE))))
	{
		WriteChatBuffer("Your Inventory:",USERCOLOR_DEFAULT);
		WriteChatBuffer("--------------------------",USERCOLOR_DEFAULT);
		SelectFind("list","list");
		return;
	}
	//search merchant inventory
	if ((_stricmp(szArg1,"list") && (!_stricmp(szArg2,"merchant") && (Found == FALSE))))
	{
		for (i=0;i<79 && !Found;i++) {
			if (pMainWindow->ItemDesc[i]!=NULL) {
				if (!_stricmp(pMainWindow->ItemDesc[i]->Item->Name, szArg1)) {
					sprintf(szBuffer,"'%s' Found in slot '%d'",pMainWindow->ItemDesc[i]->Item->Name,pMainWindow->SlotsHandles[i]->SlotID-5999);
					WriteChatBuffer(szBuffer,USERCOLOR_DEFAULT);
					SelectSlot=(int)pMainWindow->SlotsHandles[i]->SlotID;
					Found = TRUE;
					break;
				}
			}
		}
	}

	//search character bags 
	if ((_stricmp(szArg1,"list") && (!_stricmp(szArg2,"self") && (Found == FALSE))))
	{
		i = (DWORD)SelectFind(szArg1,"self");
		if(i==59999) return;
		if(i>=30)
		{
			int j=0;
			SelectSlot = (int)i;
			for (j=281;j<362;j++)
			{
				if (pSlotList->InvSlots[j])
				{
					CurrentSelection = (PEQCURRENTSELECTION)pSlotList->InvSlots[j];
					Slot = (PCSIDLWND)CurrentSelection->SelectedWnd;
					if ((int)Slot->SlotID == SelectSlot)
					{
						FixedSelection=CurrentSelection;
						FixedSlot = Slot;
						PlayerSelection = TRUE;
						Found = TRUE;
						break;
					}
				}
			}
			i = 0;
		} else {
			int j=0;
			SelectSlot = (int)i;
			for (j=0;j<30;j++)
			{
				if (pSlotList->InvSlots[j])
				{
					CurrentSelection = (PEQCURRENTSELECTION)pSlotList->InvSlots[j];
					Slot = (PCSIDLWND)CurrentSelection->SelectedWnd;
					if ((int)Slot->SlotID == SelectSlot)
					{
						FixedSelection=CurrentSelection;
						FixedSlot = Slot;
						PlayerSelection = TRUE;
						Found = TRUE;
						break;
					}
				}
			}
			i = 0;
		}
	}
	if (Found == TRUE)
	{	
		int TextureAnim;
		if (pMainWindow->ItemDesc[i])
		{   
			if (PlayerSelection == FALSE)
			{
				pCurSlot = (PCSIDLWND)((int *)pSelectedSlot->SelectedWnd);
				pCurSlot->Selector = 0;
				if (!pMainWindow->SlotsHandles[i]) return;
				pDestSlot = (PCSIDLWND)((int *)pMainWindow->SlotsHandles[i]);
				pDestSlot->Selector = 1;
				*((int *)EQADDR_CLASSTEXTUREANIMATION) = ((int)pDestSlot->PushToSelector);
				TextureAnim = (int)pDestSlot->TextureAnim;
				if (!TextureAnim) return;
				if (!SelectSlot) return;
				
			}
			if (PlayerSelection == TRUE)
			{
				pCurSlot = (PCSIDLWND)((int *)pSelectedSlot->SelectedWnd);
				pCurSlot->Selector = 0;
				if (!FixedSelection) return;
				if (!FixedSlot) return;
				pDestSlot = FixedSlot;
				pDestSlot->Selector = 1;
				*((int *)EQADDR_CLASSTEXTUREANIMATION) = ((int)FixedSelection);
				TextureAnim = (int)pDestSlot->TextureAnim;
				SelectSlot = FixedSlot->SlotID;
				if (!TextureAnim) return;
				if (!SelectSlot) return;
			}
			__asm {
				push ecx;
				push TextureAnim;
				mov ecx, dword ptr [MerchTraderWnd];
				push SelectSlot;
				call dword ptr [cmdSelectItem];
				pop ecx;
			}
		}
	}
	return;   
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
   DWORD MerchTraderWnd = *EQADDR_CLASSMERCHWND;
   PCSIDLWND pMerchWnd = (PCSIDLWND)*EQADDR_CLASSMERCHWND;
   CHAR szBuffer[MAX_STRING] = {0};
   CHAR szQty[MAX_STRING] = {0};
   PCHARINFO pCharInfo = NULL;
   DWORD Qty;
   DebugSpew("/buyitem : yes the command works at least to this point");

   if (!MerchTraderWnd || !cmdBuyItem) return;
   if (NULL == (pCharInfo = GetCharInfo())) return;
   GetArg(szQty,szLine,1);
   Qty = (DWORD)atoi(szQty);
   if (Qty > 20 || Qty < 1) return;
   __asm {
      push ecx;
      mov ecx, dword ptr [MerchTraderWnd];
      push Qty;
        call dword ptr [cmdBuyItem];
      pop ecx;
   }
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
    DWORD MerchTraderWnd = *EQADDR_CLASSMERCHWND;
    PCSIDLWND pMerchWnd = (PCSIDLWND)*EQADDR_CLASSMERCHWND;
    CHAR szBuffer[MAX_STRING] = {0};
    CHAR szQty[MAX_STRING] = {0};
    PCHARINFO pCharInfo = NULL;
    DWORD Qty;
    DebugSpew("/sellitem : yes the command works at least to this point");

    if (!MerchTraderWnd || !cmdSellItem) return;
    if (NULL == (pCharInfo = GetCharInfo())) return;
    GetArg(szQty,szLine,1);
    Qty = (DWORD)atoi(szQty);
    if (Qty > 20 || Qty < 1) return;
    __asm {
        push ecx;
        mov ecx, dword ptr [MerchTraderWnd];
        push Qty;
        call dword ptr [cmdSellItem];
        pop ecx;
    }
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
	WriteChatBuffer(szTemp,USERCOLOR_DEFAULT);
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
	} else { 
        WriteChatBuffer("Usage: /whofilter <lastname|class|race|level|gm|guild|holding|ld|anon|lfg|npctag|spawnid|trader|afk|concolor> [on|off]",USERCOLOR_DEFAULT); 
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
        "on",
        "off",
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
        if (gFilterMacro != FILTERMACRO_NONE) WriteChatColor("skills, target, money, encumber, food, name, zrange, macros, map, debug", USERCOLOR_DEFAULT);
        return;
    }

    if ((stricmp("skills",szArg)) &&
        (stricmp("macros",szArg)) &&
        (stricmp("target",szArg)) &&
        (stricmp("name",szArg)) &&
        (stricmp("food",szArg)) &&
        (stricmp("money",szArg)) &&
        (stricmp("encumber",szArg)) &&
        (stricmp("debug",szArg)) &&
		(stricmp("mqchat",szArg)) &&
        (stricmp("zrange",szArg))) {
        cmdFilter(pChar,szArg);
        return;
    }
    if (!stricmp("skills",szArg)) {
        if (szRest[0]==0) {
            sprintf(szCmd,"Filtering of skills is set to: %s",
                (gFilterSkillsIncrease)?"None":(gFilterSkillsAll)?"Increase":"All");
            WriteChatBuffer(szCmd,USERCOLOR_DEFAULT);
            return;
        }
        for (Command=0;szFilterSkills[Command];Command++) {
            if (!stricmp(szRest,szFilterSkills[Command])) {
                gFilterSkillsAll = (0!=Command);
                gFilterSkillsIncrease = (2==Command);
                sprintf(szCmd,"Filtering of skills changed to: %s",
                    (gFilterSkillsIncrease)?"None":(gFilterSkillsAll)?"Increase":"All");
                WriteChatBuffer(szCmd,USERCOLOR_DEFAULT);
                itoa(Command,szCmd,10); WritePrivateProfileString("MacroQuest","FilterSkills",szCmd,gszINIFilename);
                return;
            }
        }
        WriteChatBuffer("Usage: /filter skills [all|increase|none]",USERCOLOR_DEFAULT);

    } else if (!stricmp("macros",szArg)) {
        if (szRest[0]==0) {
            sprintf(szCmd,"Filtering of macros is set to: %s",szFilterMacro[gFilterMacro]);
            WriteChatBuffer(szCmd,USERCOLOR_DEFAULT);
            return;
        }
        for (Command=0;szFilterMacro[Command];Command++) {
            if (!stricmp(szRest,szFilterMacro[Command])) {
                gFilterMacro = Command;
                sprintf(szCmd,"Filtering of macros changed to: %s",szFilterMacro[gFilterMacro]);
                WriteChatBuffer(szCmd,USERCOLOR_DEFAULT);
                itoa(gFilterMacro,szCmd,10); WritePrivateProfileString("MacroQuest","FilterMacro",szCmd,gszINIFilename);
                return;
            }
        }
        WriteChatBuffer("Usage: /filter macros [all|enhanced|none]",USERCOLOR_DEFAULT);

    } else if (!stricmp("target",szArg)) {
        if (szRest[0]==0) {
            sprintf(szCmd,"Filtering of target lost messages is set to: %s",szFilterTarget[gFilterTarget]);
            WriteChatBuffer(szCmd,USERCOLOR_DEFAULT);
            return;
        }
        for (Command=0;szFilterTarget[Command];Command++) {
            if (!stricmp(szRest,szFilterTarget[Command])) {
                gFilterTarget = Command;
                sprintf(szCmd,"Filtering of target lost messages changed to: %s",szFilterTarget[gFilterTarget]);
                WriteChatBuffer(szCmd,USERCOLOR_DEFAULT);
                itoa(gFilterTarget,szCmd,10); WritePrivateProfileString("MacroQuest","FilterTarget",szCmd,gszINIFilename);
                return;
            }
        }
        WriteChatBuffer("Usage: /filter target [on|off]",USERCOLOR_DEFAULT);

    } else if (!stricmp("debug",szArg)) {
        if (szRest[0]==0) {
            sprintf(szCmd,"Filtering of debug messages is set to: %s",szFilterTarget[gFilterDebug]);
            WriteChatBuffer(szCmd,USERCOLOR_DEFAULT);
            return;
        }
        for (Command=0;szFilterTarget[Command];Command++) {
            if (!stricmp(szRest,szFilterTarget[Command])) {
                gFilterDebug = Command;
                sprintf(szCmd,"Filtering of debug messages changed to: %s",szFilterTarget[gFilterDebug]);
                WriteChatBuffer(szCmd,USERCOLOR_DEFAULT);
                itoa(gFilterTarget,szCmd,10); WritePrivateProfileString("MacroQuest","FilterDebug",szCmd,gszINIFilename);
                return;
            }
        }
        WriteChatBuffer("Usage: /filter debug [on|off]",USERCOLOR_DEFAULT);

    } else if (!stricmp("money",szArg)) {
        if (szRest[0]==0) {
            sprintf(szCmd,"Filtering of money messages is set to: %s",szFilterTarget[gFilterMoney]);
            WriteChatBuffer(szCmd,USERCOLOR_DEFAULT);
            return;
        }
        for (Command=0;szFilterTarget[Command];Command++) {
            if (!stricmp(szRest,szFilterTarget[Command])) {
                gFilterMoney = Command;
                sprintf(szCmd,"Filtering of money messages changed to: %s",szFilterTarget[gFilterMoney]);
                WriteChatBuffer(szCmd,USERCOLOR_DEFAULT);
                itoa(gFilterMoney,szCmd,10); WritePrivateProfileString("MacroQuest","FilterMoney",szCmd,gszINIFilename);
                return;
            }
        }
        WriteChatBuffer("Usage: /filter money [on|off]",USERCOLOR_DEFAULT);
    } else if (!stricmp("encumber",szArg)) {
        if (szRest[0]==0) {
            sprintf(szCmd,"Filtering of encumber messages is set to: %s",szFilterTarget[gFilterEncumber]);
            WriteChatBuffer(szCmd,USERCOLOR_DEFAULT);
            return;
        }
        for (Command=0;szFilterTarget[Command];Command++) {
            if (!stricmp(szRest,szFilterTarget[Command])) {
                gFilterEncumber = Command;
                sprintf(szCmd,"Filtering of encumber messages changed to: %s",szFilterTarget[gFilterEncumber]);
                WriteChatBuffer(szCmd,USERCOLOR_DEFAULT);
                itoa(gFilterEncumber,szCmd,10); WritePrivateProfileString("MacroQuest","FilterEncumber",szCmd,gszINIFilename);
                return;
            }
        }
        WriteChatBuffer("Usage: /filter encumber [on|off]",USERCOLOR_DEFAULT);
    } else if (!stricmp("food",szArg)) {
        if (szRest[0]==0) {
            sprintf(szCmd,"Filtering of food messages is set to: %s",szFilterTarget[gFilterFood]);
            WriteChatBuffer(szCmd,USERCOLOR_DEFAULT);
            return;
        }
        for (Command=0;szFilterTarget[Command];Command++) {
            if (!stricmp(szRest,szFilterTarget[Command])) {
                gFilterFood = Command;
                sprintf(szCmd,"Filtering of food messages changed to: %s",szFilterTarget[gFilterFood]);
                WriteChatBuffer(szCmd,USERCOLOR_DEFAULT);
                itoa(gFilterFood,szCmd,10); WritePrivateProfileString("MacroQuest","FilterFood",szCmd,gszINIFilename);
                return;
            }
        }
        WriteChatBuffer("Usage: /filter food [on|off]",USERCOLOR_DEFAULT);
    } else if (!stricmp("name",szArg)) {
        if (szRest[0]==0) {
            WriteChatBuffer("Names currently filtered:", USERCOLOR_DEFAULT);
            WriteChatBuffer("---------------------------", USERCOLOR_DEFAULT);
            PFILTER pFilter = gpFilters;
            while (pFilter) {
                if (pFilter->pEnabled == &gFilterCustom) {
                    sprintf(szCmd, "   %s", pFilter->FilterText);
                    WriteChatBuffer(szCmd,USERCOLOR_DEFAULT);
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
                        WriteChatBuffer(szCmd,USERCOLOR_DEFAULT);
                        itoa(gFilterCustom,szCmd,10); WritePrivateProfileString("MacroQuest","FilterCustom",szCmd,gszINIFilename);
                        return;
                    }
                }
            } else if (!stricmp(szArg,"remove")) {
                if (szRest[0]==0) {
                    WriteChatBuffer("Remove what?",USERCOLOR_DEFAULT);
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
                    WriteChatBuffer("Cleared all name filters.",USERCOLOR_DEFAULT);
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
                            WriteChatBuffer(szCmd,USERCOLOR_DEFAULT);
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
                    WriteChatBuffer("Add what?",USERCOLOR_DEFAULT);
                }
                PFILTER pFilter = gpFilters;
                while (pFilter) {
                    if ((pFilter->pEnabled == &gFilterCustom) && (!stricmp(pFilter->FilterText,szRest))) {
                        sprintf(szCmd,"Name '%s' is already being filtered.",szRest);
                        WriteChatBuffer(szCmd,USERCOLOR_DEFAULT);
                        return;
                    }
                    pFilter = pFilter->pNext;
                }

                AddFilter(szRest,-1,&gFilterCustom);
                WriteFilterNames();
                sprintf(szCmd,"Started filtering on: %s",szRest);
                WriteChatBuffer(szCmd,USERCOLOR_DEFAULT);
                return;
            } else {
                WriteChatBuffer("Usage: /filter name on|off|add|remove <name>",USERCOLOR_DEFAULT);
                return;
            }
        }
    } else if (!stricmp("zrange",szArg)) {
        if (szRest[0]==0) {
            if (gZFilter>=10000.0f) {
                WriteChatBuffer("Z range is not currently set.", USERCOLOR_DEFAULT);
            } else {
                sprintf(szArg,"Z range is set to: %1.2f",gZFilter);
                WriteChatBuffer(szArg, USERCOLOR_DEFAULT);
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
        WriteChatBuffer("Syntax: /spewfile [on|off]",USERCOLOR_DEFAULT);
    } else {
        Pause = !gSpewToFile;
    }
    if (gSpewToFile) {
        sprintf(szBuffer,"Debug Spew is being logged to a file.");
    } else {
        sprintf(szBuffer,"Debug Spew is not being logged to a file.");
    }
    WriteChatBuffer(szBuffer,USERCOLOR_DEFAULT);
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
        WriteChatColor("You must be holding an item to identify it.",CONCOLOR_RED);
        return;
    }

	DebugSpew("Identify - %s", pCharInfo->Cursor->Item->LoreName);
    WriteChatColor(" ",USERCOLOR_SPELLS);
	if		( pCharInfo->Cursor->Item->Type == ITEMTYPE_NORMAL && pCharInfo->Cursor->Item->Common.ItemType < MAX_ITEMTYPES && szItemTypes[pCharInfo->Cursor->Item->Common.ItemType] != NULL  )
	    sprintf(szMsg,"Item: %s (Slot: %s, Weight: %d.%d, Value: %dcp, Type: %s)",pCharInfo->Cursor->Item->Name,szSize[pCharInfo->Cursor->Item->Size], (INT)(pCharInfo->Cursor->Item->Weight/10),(pCharInfo->Cursor->Item->Weight) % 10, pCharInfo->Cursor->Item->Cost, szItemTypes[pCharInfo->Cursor->Item->Common.ItemType] );
	else if ( pCharInfo->Cursor->Item->Type == ITEMTYPE_PACK && pCharInfo->Cursor->Item->Container.Combine < MAX_COMBINES && szCombineTypes[pCharInfo->Cursor->Item->Container.Combine] != NULL )
	    sprintf(szMsg,"Item: %s (Slot: %s, Weight: %d.%d, Value: %dcp, Type: %s)",pCharInfo->Cursor->Item->Name,szSize[pCharInfo->Cursor->Item->Size], (INT)(pCharInfo->Cursor->Item->Weight/10),(pCharInfo->Cursor->Item->Weight) % 10, pCharInfo->Cursor->Item->Cost, szCombineTypes[pCharInfo->Cursor->Item->Container.Combine] );
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
		if (pCharInfo->Cursor->Item->Common.Magic == 1) strcat(szMsg,"MAGIC ");
		BYTE Light = pCharInfo->Cursor->Item->Common.Light;
        if ((Light>0) && (Light<=LIGHT_COUNT)) {
            strcat(szMsg,"(Light: ");
            strcat(szMsg,szLights[Light]);
            strcat(szMsg,") ");
        }
    }
    if (strlen(szMsg) > 7) WriteChatColor(szMsg,USERCOLOR_SPELLS);

	if (pCharInfo->Cursor->Item->Type == ITEMTYPE_PACK) {
        CHAR szCombine[MAX_STRING] = {0};
		if ((pCharInfo->Cursor->Item->Container.Combine < MAX_COMBINES) && (szCombineTypes[pCharInfo->Cursor->Item->Container.Combine] != NULL)) {
			strcpy(szCombine,szCombineTypes[pCharInfo->Cursor->Item->Container.Combine]);
        } else {
			sprintf(szCombine,"*Unknown%d",pCharInfo->Cursor->Item->Container.Combine);
        }
		sprintf(szMsg,"Container: %d Slot %s, %d%% Reduction, Combine=%s",pCharInfo->Cursor->Item->Container.Slots,szSize[pCharInfo->Cursor->Item->Container.SizeCapacity],pCharInfo->Cursor->Item->Container.WeightReduction,szCombine);
	} else if (pCharInfo->Cursor->Item->Type == ITEMTYPE_BOOK) {
//		sprintf(szMsg,"Book file: %s", pCharInfo->Cursor->Item->Book.File);
    } else {
            strcpy(szMsg,"Item: ");
			if (pCharInfo->Cursor->Item->Common.AC) {
				sprintf(szTmp,"AC%d ",pCharInfo->Cursor->Item->Common.AC);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->Common.Damage) {
				sprintf(szTmp,"%dDam ",pCharInfo->Cursor->Item->Common.Damage);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->Common.Delay) {
				sprintf(szTmp,"%dDly ",pCharInfo->Cursor->Item->Common.Delay);
                strcat(szMsg,szTmp);
            }
			
			if (pCharInfo->Cursor->Item->Common.Range) {
				sprintf(szTmp,"%dRng ",pCharInfo->Cursor->Item->Common.Range);
                strcat(szMsg,szTmp);
            }
			if ((pCharInfo->Cursor->Item->Common.Skill)) {
				sprintf(szTmp,"%s ",szSkills[pCharInfo->Cursor->Item->Common.Skill]);
                //strcat(szMsg,szTmp);
            }
			
			if (pCharInfo->Cursor->Item->Common.HP) {
				sprintf(szTmp,"%dHP ",pCharInfo->Cursor->Item->Common.HP);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->Common.Mana) {
				sprintf(szTmp,"%dMana ",pCharInfo->Cursor->Item->Common.Mana);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->Common.STR) {
				sprintf(szTmp,"%dSTR ",pCharInfo->Cursor->Item->Common.STR);
                strcat(szMsg,szTmp) ;
            }
			if (pCharInfo->Cursor->Item->Common.STA) {
				sprintf(szTmp,"%dSTA ",pCharInfo->Cursor->Item->Common.STA);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->Common.DEX) {
				sprintf(szTmp,"%dDEX ",pCharInfo->Cursor->Item->Common.DEX);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->Common.AGI) {
				sprintf(szTmp,"%dAGI ",pCharInfo->Cursor->Item->Common.AGI);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->Common.WIS) {
				sprintf(szTmp,"%dWIS ",pCharInfo->Cursor->Item->Common.WIS);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->Common.INT) {
				sprintf(szTmp,"%dINT ",pCharInfo->Cursor->Item->Common.INT);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->Common.CHA) {
				sprintf(szTmp,"%dCHA ",pCharInfo->Cursor->Item->Common.CHA);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->Common.SvMagic) {
				sprintf(szTmp,"%dSvM ",pCharInfo->Cursor->Item->Common.SvMagic);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->Common.SvDisease) {
				sprintf(szTmp,"%dSvD ",pCharInfo->Cursor->Item->Common.SvDisease);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->Common.SvPoison) {
				sprintf(szTmp,"%dSvP ",pCharInfo->Cursor->Item->Common.SvPoison);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->Common.SvFire) {
				sprintf(szTmp,"%dSvF ",pCharInfo->Cursor->Item->Common.SvFire);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->Common.SvCold) {
				sprintf(szTmp,"%dSvC ",pCharInfo->Cursor->Item->Common.SvCold);
                strcat(szMsg,szTmp);
            }
			if (pCharInfo->Cursor->Item->Common.Stackable==1) {
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
    WriteChatBuffer(szBuffer,USERCOLOR_DEFAULT);
}

PSPAWNINFO GetClosestAlert(PSPAWNINFO pChar, DWORD List, DWORD* pdwCount)
{
    CHAR szName[MAX_STRING] = {0};
    if (!EQADDR_SPAWNLIST) return NULL;
    if (!*EQADDR_SPAWNLIST) return NULL;
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
                    WriteChatBuffer("No alerts active.",USERCOLOR_DEFAULT);

                } else {
                    CHAR Buffer[MAX_STRING] = {0};
                    DWORD Count=0;
                    WriteChatBuffer(" ",USERCOLOR_DEFAULT);
                    WriteChatBuffer("Current alerts:",USERCOLOR_DEFAULT);
                    while (pAlert) {
                        FormatSearchSpawn(Buffer,&(pAlert->SearchSpawn));
                        WriteChatBuffer(Buffer,USERCOLOR_DEFAULT);
                        Count++;
                        pAlert = pAlert->pNext;
                    }
                    sprintf(Buffer,"%d alerts listed.",Count);
                    WriteChatBuffer(Buffer,USERCOLOR_DEFAULT);
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
                    WriteChatBuffer("Couldn't create alert.",CONCOLOR_RED);
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
                WriteChatBuffer(Buffer,USERCOLOR_DEFAULT);
                DidSomething = TRUE;
            }
        }
    }
    if (!DidSomething) {
        WriteChatBuffer("Usage: /alert [clear #] [list #] [add # [pc|npc|corpse|any] [radius radius] [zradius radius] [range min max] spawn]",USERCOLOR_DEFAULT);
    }
}


// ***************************************************************************
// Function:    Breakin
// Description: Our '/breakin' command
//              Breaks into the debugger
// Usage:       /breakin
// ***************************************************************************
/*
VOID Breakin(PSPAWNINFO pChar, PCHAR szLine)
{
    if (!IsDebuggerPresent()) {
        WriteChatBuffer("Cannot break in when a debugger is not present.",CONCOLOR_RED);
        return;
    }
    DebugSpewAlways("Breakin - pChar=%p, gMacroBlock=%p, gMacroStack=%p",pChar,gMacroBlock,gMacroStack);
    DebugBreak();
}
/**/

// ***************************************************************************
// Function:    CleanupName
// Description: Cleans up NPC names
//              an_iksar_marauder23 = iksar marauder, an
// ***************************************************************************
PCHAR CleanupName(PCHAR szName, BOOL Article)
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
// Function:    SwapSWho
// Description: Swaps two PSWHOSORTs
// ***************************************************************************
VOID SwapSWho(PSWHOSORT pSWho1, PSWHOSORT pSWho2)
{
    SWHOSORT SWhoTemp;
    CopyMemory(&SWhoTemp,pSWho1,sizeof(SWHOSORT));
    CopyMemory(pSWho1,pSWho2,sizeof(SWHOSORT));
    CopyMemory(pSWho2,&SWhoTemp,sizeof(SWHOSORT));
}


// ***************************************************************************
// Function:    SortSWho
// Description: Sorts an array of PSWHOSORT
// ***************************************************************************
VOID SortSWho(PSWHOSORT pSWhoSort, DWORD SpawnCount, DWORD SortBy) 
{
    DWORD Index1, Index2;
/*   -- For reference purposes only 
   PCHAR szSortBy[] = { 
      "level",   // Default sort by 
      "name", 
      "race", 
      "class", 
      "distance", 
      "guild", 
      "id", 
      NULL 
   }; 
*/ 

   // Pre-sort the entire list by name 
   for (Index1=0;Index1<SpawnCount;Index1++) { 
      for (Index2=SpawnCount-1;Index2>Index1;Index2--) { 
         if (stricmp(pSWhoSort[Index2].szName, pSWhoSort[Index2-1].szName)<0) { 
            SwapSWho(&pSWhoSort[Index2], &pSWhoSort[Index2-1]); 
         } 
      } 
   } 

   switch (SortBy) { 
      case 0: 
         //Sort by Level 
         for (Index1=0;Index1<SpawnCount;Index1++) { 
            for (Index2=SpawnCount-1;Index2>Index1;Index2--) { 
               if (pSWhoSort[Index2].Level < pSWhoSort[Index2-1].Level) { 
                  SwapSWho(&pSWhoSort[Index2], &pSWhoSort[Index2-1]); 
               } 
            } 
         } 
         break; 

      case 1: 
         //Sort by Name - we already pre-did this
         break; 

      case 2: 
         //Sort by Race 
         for (Index1=0;Index1<SpawnCount;Index1++) { 
            for (Index2=SpawnCount-1;Index2>Index1;Index2--) { 
               if (stricmp(GetRaceByID(pSWhoSort[Index2].Race), GetRaceByID(pSWhoSort[Index2-1].Race))<0) { 
                  SwapSWho(&pSWhoSort[Index2], &pSWhoSort[Index2-1]); 
               } 
            } 
         } 
         break; 

      case 3: 
         //Sort by Class 
         for (Index1=0;Index1<SpawnCount;Index1++) { 
            for (Index2=SpawnCount-1;Index2>Index1;Index2--) { 
               if (stricmp(GetClassByID(pSWhoSort[Index2].Class), GetClassByID(pSWhoSort[Index2-1].Class))<0) { 
                  SwapSWho(&pSWhoSort[Index2], &pSWhoSort[Index2-1]); 
               } 
            } 
         } 
         break; 

      case 4: 
         //Sort by Distance 
    for (Index1=0;Index1<SpawnCount;Index1++) {
        for (Index2=SpawnCount-1;Index2>Index1;Index2--) {
            if (pSWhoSort[Index2].Distance < pSWhoSort[Index2-1].Distance) {
                SwapSWho(&pSWhoSort[Index2], &pSWhoSort[Index2-1]);
            }
        }
    }
         break; 

      case 5: 
         //Sort by Guild 
        for (Index1=0;Index1<SpawnCount;Index1++) {
            for (Index2=SpawnCount-1;Index2>Index1;Index2--) {
               if (pSWhoSort[Index2].GuildID < pSWhoSort[Index2-1].GuildID) { 
                    SwapSWho(&pSWhoSort[Index2], &pSWhoSort[Index2-1]);
                }
            }
        }
         break; 

      case 6: 
         //Sort by Level 
        for (Index1=0;Index1<SpawnCount;Index1++) {
            for (Index2=SpawnCount-1;Index2>Index1;Index2--) {
               if (pSWhoSort[Index2].SpawnID < pSWhoSort[Index2-1].SpawnID) { 
                    SwapSWho(&pSWhoSort[Index2], &pSWhoSort[Index2-1]);
                }
            }
        }
         break; 
    }
}


// ***************************************************************************
// Function:    SuperWhoFindPets
// Description: Find pets to display
//              Broken as all hell
// ***************************************************************************

PSPAWNINFO GetPet(DWORD OwnerID)
{
    PSPAWNINFO pSpawn = NULL;
    if (EQADDR_SPAWNLIST && *EQADDR_SPAWNLIST) {
        pSpawn = *EQADDR_SPAWNLIST;
    }
    while (pSpawn) {
        if ((pSpawn->MasterID == OwnerID) && (pSpawn->Type != SPAWN_PLAYER) && (pSpawn->Type != SPAWN_CORPSE)){
            return pSpawn;
        }
        pSpawn = pSpawn->pNext;
    }
    return NULL;
}


VOID SuperWhoFindPets(PSPAWNINFO pChar, DWORD SpawnID, BOOL Color)
{
    PSPAWNINFO pPet = GetPet(SpawnID);
    if (!pPet) return;
//    DWORD dwColor=USERCOLOR_WHO;
    DebugSpew("SuperWhoFindPets - Spawn%d has pet %s",SpawnID,pPet->Name);
//    if (Color) dwColor=ConColor(pChar->Level, pPet->Level);
    SuperWhoDisplay(pChar, NULL, pPet, 5, Color);
}


// ***************************************************************************
// Function:    SuperWhoDisplay
// Description: Displays our SuperWho / SuperWhoTarget
// ***************************************************************************
VOID SuperWhoDisplay(PSPAWNINFO pChar, PSEARCHSPAWN pFilter, PSPAWNINFO pTarget, WORD Padding, DWORD Color)
{
    PSPAWNINFO pSpawn = NULL;
    CHAR szMsg[MAX_STRING] = {0};
    CHAR szName[MAX_STRING] = {0};
    CHAR szMsgL[MAX_STRING] = {0};
    CHAR szTemp[MAX_STRING] = {0};
    PSWHOSORT pSWhoSort = (PSWHOSORT)malloc(sizeof(SWHOSORT)*500);
    DWORD SpawnCount = 0, Index;
    FLOAT Distance;
    INT Angle;

        if (EQADDR_SPAWNLIST && *EQADDR_SPAWNLIST) for (pSpawn = *EQADDR_SPAWNLIST;(pSpawn) && (SpawnCount<500);pSpawn = pSpawn->pNext) {
        if ((pTarget) && (pTarget != pSpawn)) continue;
        if ((!pTarget) && (pSpawn->Type == SPAWN_NPC) && (pSpawn->MasterID != 0)) continue;
        Distance =  DistanceToSpawn(pChar,pSpawn);
        if (pFilter) {
            if ((pFilter->SpawnType == SPAWN_PLAYER) && (pSpawn->Type != SPAWN_PLAYER)) continue;
            if ((pFilter->SpawnType == SPAWN_NPC) && ((pSpawn->Type != SPAWN_NPC) || (pSpawn->MasterID!=0))) continue;
            if ((pFilter->SpawnType == SPAWN_PET) && ((pSpawn->Type != SPAWN_NPC) || (pSpawn->MasterID==0))) continue;
            if ((pFilter->SpawnType == SPAWN_CORPSE) && (pSpawn->Type != SPAWN_CORPSE)) continue;
            if ((pFilter->Radius>0.0f) && (IsPCNear(pSpawn,pFilter->Radius))) continue;
            if ((pFilter->ZRadius<10000.0f) && (fabs(pSpawn->Z - pChar->Z) > pFilter->ZRadius)) continue;
            if ((pFilter->FRadius<10000.0f) && (DistanceToSpawn(pChar,pSpawn)>pFilter->FRadius)) continue;
            if (pFilter->MinLevel> pSpawn->Level) continue;
            if (pFilter->MaxLevel< pSpawn->Level) continue;
            if ((pFilter->szBodyType[0]!=0) && (strnicmp(pFilter->szBodyType,GetBodyTypeByID(pSpawn->BodyType),strlen(pFilter->szBodyType)))) continue;
            if ((pFilter->szRace[0]!=0) && (strnicmp(pFilter->szRace,GetRaceByID(pSpawn->Race),strlen(pFilter->szRace)))) continue;
            if ((pFilter->szClass[0]!=0) && (strnicmp(pFilter->szClass,GetClassByID(pSpawn->Class),strlen(pFilter->szClass)))) continue;
            if ((pFilter->GuildID != 0xFFFF) && (pFilter->GuildID!=pSpawn->GuildID)) continue;
			if ((pFilter->bLight) && (!stricmp(GetLightForSpawn(pSpawn),"NONE"))) continue;
			if ((pFilter->bLight) && (pFilter->szLight[0]) && (stricmp(GetLightForSpawn(pSpawn),pFilter->szLight))) continue;
            if ((pFilter->bLFG) && (!pSpawn->LFG)) continue;
            if ((pFilter->bGroup) && (!IsInGroup(pSpawn))) continue;
			if ((!pFilter->bTargInvis) && (pSpawn->BodyType>0x40)) continue;
            if ((pFilter->bTrader) && (!pSpawn->pActorInfo->Trader)) continue;
            if ((pFilter->bAlert) && (!IsAlert(pChar,pSpawn,pFilter->AlertList))) continue;
            if ((pFilter->bNoAlert) && (IsAlert(pChar,pSpawn,pFilter->NoAlertList))) continue;
            if ((pFilter->bNearAlert) && (!GetClosestAlert(pSpawn,pFilter->NearAlertList,NULL))) continue;
            if ((pFilter->bNotNearAlert) && (GetClosestAlert(pSpawn,pFilter->NotNearAlertList,NULL))) continue;
        }
        strcpy(szName,pSpawn->Name);
        if (pSpawn->Type == SPAWN_PLAYER) {
            if (gFilterSWho.Lastname && strlen(pSpawn->Lastname)>0) {
                strcat(szName," ");
                strcat(szName,pSpawn->Lastname);
            }
            if (gFilterSWho.Guild && pSpawn->GuildID < 0xFFFD && EQADDR_GUILDLIST) {
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
        strcpy(pSWhoSort[SpawnCount].szName,szName);
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
			switch(ConColor(pChar->Level,pSpawn->Level))
			{
			case CONCOLOR_BLACK:
				//strcpy(szMsg,"\aw-");
				szMsg[1]='w';
				break;
			case CONCOLOR_YELLOW:
				szMsg[1]='y';
//				strcpy(szMsg,"\ay-");
				break;
			case CONCOLOR_RED:
				szMsg[1]='r';
//				strcpy(szMsg,"\ar-");
				break;
			case CONCOLOR_BLUE:
				szMsg[1]='u';
//				strcpy(szMsg,"\au-");
				break;
			case CONCOLOR_LIGHTBLUE:
				szMsg[1]='t';
//				strcpy(szMsg,"\at-");
				break;
			case CONCOLOR_GREEN:
				szMsg[1]='g';
//				strcpy(szMsg,"\ag-");
				break;
			default:
				szMsg[1]='m';
//				strcpy(szMsg,"\am-");
				break;
			}
		}
		else
		{
//			strcpy(szMsg,"\aw-");
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
				strcat(szMsg,GetRaceByID(pSpawn->Race));
				strcat(szMsg," ");
			}
			if (gFilterSWho.Body) {
				strcat(szMsg,GetBodyTypeByID(pSpawn->BodyType));
				strcat(szMsg," ");
			}
			if (gFilterSWho.Class) {
				strcat(szMsg,GetClassByID(pSpawn->Class));
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
        if (pFilter) {
            if (!strstr(_strlwr(szMsgL),pFilter->szName)) continue;
        }
		if (gFilterSWho.Distance) {
	        Angle = (INT)((atan2f(pChar->X - pSpawn->X, pChar->Y - pSpawn->Y) * 180.0f / PI + 360.0f) / 22.5f + 0.5f) % 16;
			sprintf(szTemp," \a-u(\ax%1.2f %s", Distance, szHeadingShort[Angle]);
			strcat(szMsg,szTemp);
        if ((!pFilter) && (Padding == 0)) {
            sprintf(szTemp,"\a-u,\ax %1.2fZ", pSpawn->Z-pChar->Z);
				strcat(szMsg,szTemp);
			}
			strcat(szMsg,"\a-u)\ax");
		}
		if (gFilterSWho.SpawnID) {
			strcat(szMsg," \a-u(\axID:");
			itoa(pSpawn->SpawnID,szTemp,10);
			strcat(szMsg,szTemp);
			strcat(szMsg,"\a-u)\ax");
        }
		if (gFilterSWho.Holding && (pSpawn->Equipment.Unique.Primary || pSpawn->Equipment.Unique.Offhand )) {
			strcat(szMsg," \a-u(\ax");
			//itoa(pSpawn->SpawnID,szTemp,10);
			//strcat(szMsg,szTemp);
			if (pSpawn->Equipment.Unique.Primary)
			{
				itoa(pSpawn->Equipment.Unique.Primary,szTemp,10);
				strcat(szMsg,"Pri: ");
				strcat(szMsg,szTemp);
				if (pSpawn->Equipment.Unique.Offhand)
					strcat(szMsg," ");
			}
			if (pSpawn->Equipment.Unique.Offhand)
			{
				itoa(pSpawn->Equipment.Unique.Offhand,szTemp,10);
				strcat(szMsg,"Off: ");
				strcat(szMsg,szTemp);
			}
			strcat(szMsg,"\a-u)\ax");
		}

		strcpy(pSWhoSort[SpawnCount].szLine,szMsg);
        pSWhoSort[SpawnCount].Level = pSpawn->Level;
        pSWhoSort[SpawnCount].Distance = Distance;
        pSWhoSort[SpawnCount].SpawnID = pSpawn->SpawnID;
        pSWhoSort[SpawnCount].Class = pSpawn->Class; 
        pSWhoSort[SpawnCount].Race = pSpawn->Race; 
        pSWhoSort[SpawnCount].GuildID = pSpawn->GuildID; 
        SpawnCount++;
    }
    if (pFilter) {
		SortSWho(pSWhoSort,SpawnCount,pFilter->SortBy);
    } else {
        SortSWho(pSWhoSort,SpawnCount,0);
    }
    if (pFilter) {
        WriteChatColor(" ",USERCOLOR_WHO);
        if (pFilter->SpawnType == SPAWN_ANY) {
            WriteChatColor("List of all spawns",USERCOLOR_WHO);
        } else {
            sprintf(szMsg,"List of %ss",szSpawnType[pFilter->SpawnType]);
            WriteChatColor(szMsg,USERCOLOR_WHO);
        }
        WriteChatColor("--------------------------------",USERCOLOR_WHO);
    }
    for (Index=0;Index<SpawnCount;Index++) {
        CHAR szOutput[MAX_STRING] = {0};
        WORD pad;
        for (pad=0;pad<Padding;pad++) strcat(szOutput," ");
        strcat(szOutput,pSWhoSort[Index].szLine);
        WriteChatColor(szOutput,USERCOLOR_WHO);
        if ((!pFilter) || (!pFilter->bNoPet)) SuperWhoFindPets(pChar, pSWhoSort[Index].SpawnID,Color);
    }
    if (pFilter) {
        if (SpawnCount==0) {
            FormatSearchSpawn(szMsg,pFilter);
            strcat(szMsg," was not found.");
        } else {
            sprintf(szMsg,"There %s \ag%d\ax%s %s%s in %s.",(SpawnCount == 1)?"is":"are",SpawnCount,(SpawnCount<500)?"":" (cut short)", (pFilter->SpawnType==SPAWN_ANY)?"spawn":szSpawnType[pFilter->SpawnType], (SpawnCount==1)?"":"s", GetFullZone(pChar->Zone));
        }
        WriteChatColor(szMsg,USERCOLOR_WHO);
    }
    free(pSWhoSort);
}

// ***************************************************************************
// Function:    SuperWhoTarget
// Description: Our '/whotarget' command
//              Displays spawn currently selected
// Usage:       /whotarget
// ***************************************************************************
VOID SuperWhoTarget(PSPAWNINFO pChar, PCHAR szLine)
{
    PSPAWNINFO pTarget = NULL;
    bRunNextCommand = TRUE;
    if (gFilterMacro == FILTERMACRO_NONE) cmdWhoTarget(pChar, szLine);

    if (EQADDR_TARGET && *EQADDR_TARGET) {
        pTarget = *EQADDR_TARGET;
    }

    if (!pTarget) {
        WriteChatColor("You must have a target selected for /whotarget.",CONCOLOR_RED);
        return;
    }
    DebugSpew("SuperWhoTarget - %s",pTarget->Name);
    SuperWhoDisplay(pChar,NULL,pTarget,0,TRUE);
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
    SearchSpawn.SpawnType = SPAWN_PLAYER;

    if ((!stricmp(szLine,"all")) ||
        (!strnicmp(szLine,"all ",4)) ||
        (!strnicmp(szLine+strlen(szLine)-4," all",4)) ||
        (strstr(szLine," all ")))
    {
        cmdWho(pChar, szLine);
        return;
    }
/*
	if (gFilterMacro == FILTERMACRO_NONE) {
		gPauseTelnetOutput = TRUE;
		cmdWho(pChar, szLine);
		gPauseTelnetOutput = FALSE;
	}
/**/

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
    SuperWhoDisplay(pChar, &SearchSpawn,0,0,bConColor);

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
        gLastError[0]=0;
    } else {
        strcpy(gLastError,szLine);
    }
}


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
                sprintf(szBuffer,"Log path doesn't appear valid: %s",Filename);
                WriteChatColor(szBuffer,CONCOLOR_RED);
                return;
            }
        }
    }
    if (!stricmp(szLine,"clear")) {
        fOut = fopen(Filename,"wt");
        if (!fOut) {
            sprintf(szBuffer,"Couldn't open log file: %s",Filename);
            WriteChatColor(szBuffer,CONCOLOR_RED);
            return;
        }
        WriteChatBuffer("Cleared log.",USERCOLOR_DEFAULT);
        fclose(fOut);
        return;
    }

    fOut = fopen(Filename,"at");
    if (!fOut) {
        sprintf(szBuffer,"Couldn't open log file: %s",Filename);
        WriteChatBuffer(szBuffer,CONCOLOR_RED);
        return;
    }

    sprintf(szBuffer, "[$date() $time()] %s",szLine);
    ParseMacroParameter(pChar,szBuffer);
    fprintf(fOut,"%s\r\n", szBuffer);
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
    if (!EQADDR_SPAWNLIST) return;
    if (!*EQADDR_SPAWNLIST) return;
    PSPAWNINFO pSpawnClosest = NULL;
    PSPAWNINFO pTarget = NULL;
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
            WriteChatBuffer("Face: loc specified but <y>,<x> not found.",CONCOLOR_RED);
            strcpy(gLastError,"FACE_BADCOMMAND");
            return;
        }
            pSpawnClosest->Y = (FLOAT)atof(szFilter);
            while ((szFilter[0]!=',') && (szFilter[0]!=0)) szFilter++;
            if (szFilter[0]==0) {
            WriteChatBuffer("Face: loc specified but <y>,<x> not found.",CONCOLOR_RED);
            strcpy(gLastError,"FACE_BADCOMMAND");
            return;
        }
            szFilter++;
            pSpawnClosest->X = (FLOAT)atof(szFilter);
        } else if (!stricmp(szArg, "item")) {
        if (EnviroTarget.Name[0]==0) {
            WriteChatBuffer("Face: item but no item targetted.",CONCOLOR_RED);
            strcpy(gLastError,"FACE_NOITEM");
            return;
        }
        pSpawnClosest = &EnviroTarget;
        } else if (!stricmp(szArg, "door")) {
        if (DoorEnviroTarget.Name[0]==0) {
            WriteChatBuffer("Face: item but no item targetted.",CONCOLOR_RED);
            strcpy(gLastError,"FACE_NOITEM");
            return;
        }
        pSpawnClosest = &DoorEnviroTarget;
        } else if (!stricmp(szArg, "heading")) {
            if (szFilter[0]==0) {
                WriteChatBuffer("Face: heading specified but angle not found.",CONCOLOR_RED);
                strcpy(gLastError,"FACE_BADCOMMAND");
    } else {
                FLOAT Heading = (FLOAT)(atof(szFilter));
                gFaceAngle = Heading/0.703125f;
                if (gFaceAngle>=512.0f) gFaceAngle -= 512.0f;
                if (gFaceAngle<0.0f) gFaceAngle += 512.0f;
                if (Fast) {
					(*EQADDR_CHAR)->Heading = (FLOAT)gFaceAngle;
                    gFaceAngle=10000.0f;
                    bRunNextCommand = TRUE;
                    }
                }
            return;
        } else if (!strcmp(szArg,"help")) {
            WriteChatBuffer("Usage: /face [spawn] [item] [door] [id #] [heading <ang>] [loc <y>,<x>] [away] [alert #]",USERCOLOR_DEFAULT);
            bRunNextCommand = TRUE;
            return;
        } else {
            bOtherArgs = TRUE;
            szFilter = ParseSearchSpawnArgs(szArg,szFilter,&SearchSpawn);
        }
            }

    if (!pSpawnClosest) {
    if (!bOtherArgs) {
        if (EQADDR_TARGET && *EQADDR_TARGET) {
            pSpawnClosest = *EQADDR_TARGET;
        }
    } else {
            pSpawnClosest = SearchThroughSpawns(&SearchSpawn,pChar);
        }
    }

    if (!pSpawnClosest) {
        sprintf(szMsg,"There were no matches for: %s",FormatSearchSpawn(szArg,&SearchSpawn));
        strcpy(gLastError,"FACE_NOTFOUND");
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
            (*EQADDR_CHAR)->Heading = (FLOAT)gFaceAngle;
            gFaceAngle=10000.0f;
            bRunNextCommand = TRUE;
        }
        sprintf(szMsg,"Facing %s'%s'...",(Away)?"away from ":"", CleanupName(strcpy(szName,pSpawnClosest->Name),FALSE));
    }
    gLastError[0]=0;
    if (EQADDR_TARGET && *EQADDR_TARGET) {
        pTarget = *EQADDR_TARGET;
    }
    if ((pSpawnClosest != &LocSpawn) && ((Away) || (pSpawnClosest != pTarget))) WriteChatBuffer(szMsg,USERCOLOR_WHO);
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
      sprintf(szTemp,"/look -- Angle %f out of range.",fLookAngle);
      WriteChatBuffer(szTemp,CONCOLOR_RED);
      return;
   }

   pChar->CameraAngle = fLookAngle;

}


// ***************************************************************************
// Function:    Where
// Description: Our '/where' command
//              Displays the direction and distance to the closest spawn
// Usage:       /where <spawn>
// ***************************************************************************
VOID Where(PSPAWNINFO pChar, PCHAR szLine)
{
    if (!EQADDR_SPAWNLIST) return;
    if (!*EQADDR_SPAWNLIST) return;
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
            GetRaceByID(pSpawnClosest->Race),
            GetClassByID(pSpawnClosest->Class),
            DistanceToSpawn(pChar,pSpawnClosest),
            szHeading[Angle],
            pSpawnClosest->Z-pChar->Z);
        DebugSpew("Where - %s",szMsg);
    }
    WriteChatBuffer(szMsg,USERCOLOR_WHO);
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
        WriteChatBuffer("You do not seem to have that ability on a /doability button",USERCOLOR_DEFAULT);
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
        if (!stricmp(EQADDR_SPELLFAVORITES[Index].Name,szName)) return Index;
    }
    return -1;
}

VOID LoadSpells(PSPAWNINFO pChar, PCHAR szLine)
{
    if (!cmdLoadSpells || !EQADDR_SPELLFAVORITES || !EQADDR_SPELLBOOKWND || szLine[0]==0) return;

    DWORD Index, DoIndex = 0xFFFFFFFF;
    CHAR szArg1[MAX_STRING] = {0};
    CHAR szArg2[MAX_STRING] = {0};
    CHAR szBuffer[MAX_STRING] = {0};
    DWORD SpellBookWnd = *EQADDR_SPELLBOOKWND;

    if (!SpellBookWnd) return;

    GetArg(szArg1,szLine,1);
    GetArg(szArg2,szLine,2);

    if ((!stricmp(szArg1,"list")) && (szArg2[0]==0)) {
        WriteChatBuffer("Spell favorites list:",USERCOLOR_DEFAULT);
        WriteChatBuffer("--------------------------",USERCOLOR_DEFAULT);
        for (Index=0;Index<10;Index++) {
            if (EQADDR_SPELLFAVORITES[Index].Name[0]!=0) {
                WriteChatBuffer(EQADDR_SPELLFAVORITES[Index].Name,USERCOLOR_DEFAULT);
            }
        }
        return;
    }

    if (!stricmp(szArg1,"list")) {
        DoIndex = FindSpellListByName(szArg2);
        if (DoIndex==-1) {
            sprintf(szBuffer,"Unable to find favorite list '%s'",szArg2);
            WriteChatBuffer(szBuffer,USERCOLOR_DEFAULT);
            return;
        }
        sprintf(szBuffer,"Favorite list '%s':",szArg2);
        WriteChatBuffer(szBuffer,USERCOLOR_DEFAULT);
        for (Index=0;Index<8;Index++) {
            if (EQADDR_SPELLFAVORITES[DoIndex].SpellId[Index]!=0xFFFFFFFF) {
                sprintf(szBuffer,"%d) %s",Index,GetSpellByID(EQADDR_SPELLFAVORITES[DoIndex].SpellId[Index]));
                WriteChatBuffer(szBuffer,USERCOLOR_DEFAULT);
            }
        }
        return;
    }

    DoIndex = FindSpellListByName(szArg1);
    if (DoIndex!=-1) {
        Index = (DWORD)&EQADDR_SPELLFAVORITES[DoIndex];

        __asm {
            push ecx;
            mov ecx, dword ptr [SpellBookWnd];
            push 8;
            push dword ptr [Index];
            call dword ptr [cmdLoadSpells];
            pop ecx;
        }
    } else {
        sprintf(szBuffer,"Unable to find favorite list '%s'",szArg1);
        WriteChatBuffer(szBuffer,USERCOLOR_DEFAULT);
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

   if (szLine[0]==0 || atoi(szLine) || !EQADDR_SPELLS || !EQADDR_CHAR_INFO || !*EQADDR_CHAR_INFO) {
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
      for (Index=0;Index<8;Index++) {
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
      SpawnFooter = (DWORD)*EQADDR_SPAWNTAIL;
      for (int i=0;i<30;i++) {
         if (pCharInfo->Inventory[i])
            if (!_stricmp(szArg2,pCharInfo->Inventory[i]->Item->Name)) { 
            DebugSpew("cast test slot %d = %s address is %x",i,pCharInfo->Inventory[i]->Item->Name,&(pCharInfo->Inventory[i])); 
            item = (DWORD)&pCharInfo->Inventory[i];
               slot = (DWORD)i;
               FOUND = TRUE;
               break;
            }
      }
      if (FOUND) {
         __asm {
            push eax;
            push ecx;
            push edi;
            mov ecx, dword ptr [pCharInfo];
            mov edi, dword ptr [SpawnFooter];
            push slot;//slot item is in
            push item; //the address of inventory[i] in charinfo that points to the item
            push 0x00000000;//always 0
            push 0x0000000A;//always 10
            call dword ptr [EQADDR_CASTSPELL];
            pop edi;
            pop ecx;
            pop eax;
         }
         return;
      }
   }
   GetArg(szBuffer,szLine,1);
   for (Index=0;Index<8;Index++) {
      if (pCharInfo->MemorizedSpells[Index]!=0xFFFFFFFF) {
         PCHAR SpellName = GetSpellByID(pCharInfo->MemorizedSpells[Index]);
         if (!strnicmp(szBuffer,SpellName,strlen(SpellName))) {
            DebugSpew("SpellName = %s",SpellName);
            cmdCast(pChar,itoa(Index+1,szBuffer,10));
            DebugSpew("pChar = %x SpellName = %s %s",pChar,SpellName,itoa(Index+1,szBuffer,10));
            return;
         }
      }
   }
   WriteChatBuffer("You do not seem to have that spell memorized.",USERCOLOR_DEFAULT);
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
    if (EQADDR_SPAWNLIST && *EQADDR_SPAWNLIST) {
        pClose = *EQADDR_SPAWNLIST;
        }
    while (pClose) {
        BOOL InGroup = FALSE;
        DWORD i;
        if (pClose==GetCharInfo()->pSpawn) InGroup=TRUE;
        if (EQADDR_GROUP) for (i=0;i<5;i++) if (EQADDR_GROUP[i]==pClose) InGroup=TRUE;
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
    if (!EQADDR_GROUP) return FALSE;
	for (i=0;i<5;i++) if (EQADDR_GROUP[i]==pSpawn) return TRUE;
	return FALSE;
}


PCHAR FormatSearchSpawn(PCHAR Buffer, PSEARCHSPAWN pSearchSpawn)
{
    CHAR szTemp[MAX_STRING] = {0};
    if (!Buffer) return NULL;
    if (!pSearchSpawn) return strcpy(Buffer,"None");

    sprintf(Buffer,"(%d-%d) %s",pSearchSpawn->MinLevel,pSearchSpawn->MaxLevel,szSpawnType[pSearchSpawn->SpawnType]);

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
    if (pSearchSpawn->bTrader) strcat(Buffer," Trader");
    if (pSearchSpawn->bLFG) strcat(Buffer," LFG");
    if (pSearchSpawn->bTargInvis) strcat(Buffer," Invis");
	if (pSearchSpawn->bLight) {
		strcat(Buffer," Light");
		if (pSearchSpawn->szLight[0]) {
			strcat(Buffer,":");
			strcat(Buffer,pSearchSpawn->szLight);
		}
	}

    return Buffer;
}

PSPAWNINFO SearchThroughSpawns(PSEARCHSPAWN pSearchSpawn, PSPAWNINFO pChar)
{
    PSPAWNINFO pSpawnInfo = *EQADDR_SPAWNLIST;
    PSPAWNINFO pSpawn, pSpawnClosest = NULL;
    PSPAWNINFO pFromSpawn = NULL;
    CHAR szName[MAX_STRING] = {0};
    FLOAT Distance = 50000.0f;
        FLOAT DistanceToTarget = 0.0f;

    if (pSearchSpawn->bTargPrev) {
            DistanceToTarget = 50000.0f;
            Distance = 0.0f;
        }

    if (pSearchSpawn->FromSpawnID>0) {
        for (pSpawn=pSpawnInfo;pSpawn && !pFromSpawn;pSpawn=pSpawn->pNext) {
            if (pSpawn->SpawnID == pSearchSpawn->FromSpawnID) pFromSpawn=pSpawn;
        }
        if (!pFromSpawn) return NULL;
    }

    if (pFromSpawn) DistanceToTarget = DistanceToSpawn(pChar,pFromSpawn);

        for (pSpawn = pSpawnInfo; pSpawn; pSpawn=pSpawn->pNext) {
            if (
            (strstr(CleanupName(_strlwr(strcpy(szName,pSpawn->Name)),FALSE),pSearchSpawn->szName)) &&
                (!strstr(CleanupName(_strlwr(strcpy(szName,pSpawn->Name)),FALSE),"`s mount")) &&
            (pSpawn->Level >= pSearchSpawn->MinLevel) &&
            (pSpawn->Level <= pSearchSpawn->MaxLevel) &&
                (
                    (
                        (pSpawn != pChar) &&
                    (pSearchSpawn->SpawnID == 0)
                    ) || (
                    (pSearchSpawn->SpawnID == pSpawn->SpawnID)
                    )
                ) && (
                (pSearchSpawn->NotID == 0) ||
                (pSearchSpawn->NotID != pSpawn->SpawnID)
                ) && (
                (pSearchSpawn->szClass[0] == 0) ||
                (!strnicmp(pSearchSpawn->szClass, GetClassByID(pSpawn->Class),strlen(pSearchSpawn->szClass)))
                ) && (
                (pSearchSpawn->szBodyType[0] == 0) ||
                (!strnicmp(pSearchSpawn->szBodyType, GetBodyTypeByID(pSpawn->BodyType),strlen(pSearchSpawn->szBodyType)))
                ) && (
                (pSearchSpawn->szRace[0] == 0) ||
                (!strnicmp(pSearchSpawn->szRace, GetRaceByID(pSpawn->Race),strlen(pSearchSpawn->szRace)))
                ) && (
                (pSearchSpawn->GuildID == 0xFFFF) ||
                (pSearchSpawn->GuildID == pSpawn->GuildID)
            ) && (
                (!pSearchSpawn->bLFG) ||
                (pSpawn->LFG)
            ) && (
                (!pSearchSpawn->bTrader) ||
                (pSpawn->pActorInfo->Trader)
            ) && (
                (pSearchSpawn->bTargInvis) ||
                    (pSpawn->BodyType < 0x41)
                ) && (
                    (
                    (pSearchSpawn->bKnownLocation == FALSE)
                                        ) || (
                    (pSearchSpawn->bKnownLocation == TRUE) &&
                    (pSpawn->X == pSearchSpawn->xLoc) &&
                    (pSpawn->Y == pSearchSpawn->yLoc)
                                        )
                                ) && (
                                        (
                        (
                        (pSearchSpawn->SpawnType==SPAWN_ANY)
                        ) || (
                        (pSearchSpawn->SpawnType == SPAWN_PLAYER) &&
                            (pSpawn->Type == SPAWN_PLAYER)
                        ) || (
                        (pSearchSpawn->SpawnType == SPAWN_NPC) &&
                            (pSpawn->Type == SPAWN_NPC) &&
                            (pSpawn->MasterID == 0)
                        ) || (
                        (pSearchSpawn->SpawnType == SPAWN_PET) &&
                            (pSpawn->Type == SPAWN_NPC) &&
                            (pSpawn->MasterID != 0)
                        ) || (
                        (pSearchSpawn->SpawnType == SPAWN_CORPSE) &&
                            (pSpawn->Type == SPAWN_CORPSE)
                        )
                    )
                )
            ) {
                FLOAT SpawnDistance =  DistanceToSpawn(pChar,pSpawn);
                BOOL AlertOK = FALSE;
                BOOL NoAlertOK = FALSE;
                if (
                        (
                        (!pSearchSpawn->bTargNext) &&
                        (!pSearchSpawn->bTargPrev) &&
                            (SpawnDistance < Distance)
                        ) || (
                        (pSearchSpawn->bTargPrev) &&
                            (     Distance < SpawnDistance   ) &&
                            (SpawnDistance < DistanceToTarget)
                        ) || (
                        (pSearchSpawn->bTargNext) &&
                            (     Distance > SpawnDistance   ) &&
                            (SpawnDistance > DistanceToTarget)
                        )
                ) {
                    BOOL TooClose = FALSE;
                    PALERT pCurrent = NULL;
                if (pSearchSpawn->Radius>0.0f) {
                    if (IsPCNear(pSpawn,pSearchSpawn->Radius)) TooClose=TRUE;
                    }
                    if (gZFilter<10000.0f) {
                        if ((pSpawn->Z > pChar->Z + gZFilter) ||
                            (pSpawn->Z < pChar->Z - gZFilter)) TooClose=TRUE;
                    }
                if (pSearchSpawn->ZRadius<10000.0f) {
                    if ((pSpawn->Z > pChar->Z + pSearchSpawn->ZRadius) ||
                        (pSpawn->Z < pChar->Z - pSearchSpawn->ZRadius)) TooClose=TRUE;
                    }
                if (pSearchSpawn->FRadius<10000.0f) {
                    if (DistanceToSpawn(pChar, pSpawn)>pSearchSpawn->FRadius) TooClose=TRUE;
                    }

                    AlertOK = FALSE;
                    NoAlertOK = FALSE;
                if ((pSearchSpawn->bAlert) && (pCurrent = GetAlert(pSearchSpawn->AlertList))) {
                    if (IsAlert(pChar,pSpawn,pSearchSpawn->AlertList)) AlertOK = TRUE;
                    }
                if ((pSearchSpawn->bNoAlert) && (pCurrent = GetAlert(pSearchSpawn->NoAlertList))) {
                    if (!IsAlert(pChar,pSpawn,pSearchSpawn->NoAlertList)) NoAlertOK = TRUE;
                    }

                if ((pSearchSpawn->bNotNearAlert) && (GetClosestAlert(pSpawn, pSearchSpawn->NotNearAlertList,NULL))) TooClose=TRUE;
                if ((pSearchSpawn->bNearAlert) && (!GetClosestAlert(pSpawn,pSearchSpawn->NearAlertList,NULL))) TooClose=TRUE;
				if (pSearchSpawn->bLight) {
					if (!stricmp(GetLightForSpawn(pSpawn),"NONE")) {
						TooClose=TRUE;
					} else if (pSearchSpawn->szLight[0] && stricmp(GetLightForSpawn(pSpawn),pSearchSpawn->szLight)) {
						TooClose=TRUE;
					}
				}

                if ((!TooClose) && ((!pSearchSpawn->bAlert) || (AlertOK)) && ((!pSearchSpawn->bNoAlert) || (NoAlertOK))) {
                        pSpawnClosest = pSpawn;
                        Distance = SpawnDistance;
                    }
                }
            }
        }
    return (pSpawnClosest);
}

BOOL SpawnMatchesSearch(PSEARCHSPAWN pSearchSpawn, PSPAWNINFO pChar, PSPAWNINFO pSpawn)
{
    CHAR szName[MAX_STRING] = {0};

    if (
            (strstr(CleanupName(_strlwr(strcpy(szName,pSpawn->Name)),FALSE),pSearchSpawn->szName)) &&
                (!strstr(CleanupName(_strlwr(strcpy(szName,pSpawn->Name)),FALSE),"`s mount")) &&
            (pSpawn->Level >= pSearchSpawn->MinLevel) &&
            (pSpawn->Level <= pSearchSpawn->MaxLevel) &&
                (
                    (
                        (pSpawn != pChar) &&
                    (pSearchSpawn->SpawnID == 0)
                    ) || (
                    (pSearchSpawn->SpawnID == pSpawn->SpawnID)
                    )
                ) && (
                (pSearchSpawn->NotID == 0) ||
                (pSearchSpawn->NotID != pSpawn->SpawnID)
                ) && (
                (pSearchSpawn->szClass[0] == 0) ||
                (!strnicmp(pSearchSpawn->szClass, GetClassByID(pSpawn->Class),strlen(pSearchSpawn->szClass)))
                ) && (
                (pSearchSpawn->szBodyType[0] == 0) ||
                (!strnicmp(pSearchSpawn->szBodyType, GetBodyTypeByID(pSpawn->BodyType),strlen(pSearchSpawn->szBodyType)))
                ) && (
                (pSearchSpawn->szRace[0] == 0) ||
                (!strnicmp(pSearchSpawn->szRace, GetRaceByID(pSpawn->Race),strlen(pSearchSpawn->szRace)))
                ) && (
                (pSearchSpawn->GuildID == 0xFFFF) ||
                (pSearchSpawn->GuildID == pSpawn->GuildID)
            ) && (
                (!pSearchSpawn->bLFG) ||
                (pSpawn->LFG)
            ) && (
                (!pSearchSpawn->bGroup) ||
                (IsInGroup(pSpawn))
            ) && (
                (!pSearchSpawn->bTrader) ||
                (pSpawn->pActorInfo->Trader)
            ) && (
                (pSearchSpawn->bTargInvis) ||
                    (pSpawn->BodyType < 0x41)
                ) && (
                    (
                    (pSearchSpawn->bKnownLocation == FALSE)
                                        ) || (
                    (pSearchSpawn->bKnownLocation == TRUE) &&
                    (pSpawn->X == pSearchSpawn->xLoc) &&
                    (pSpawn->Y == pSearchSpawn->yLoc)
                                        )
                                ) && (
                                        (
                        (
                        (pSearchSpawn->SpawnType==SPAWN_ANY)
                        ) || (
                        (pSearchSpawn->SpawnType == SPAWN_PLAYER) &&
                            (pSpawn->Type == SPAWN_PLAYER)
                        ) || (
                        (pSearchSpawn->SpawnType == SPAWN_NPC) &&
                            (pSpawn->Type == SPAWN_NPC) &&
                            (pSpawn->MasterID == 0)
                        ) || (
                        (pSearchSpawn->SpawnType == SPAWN_PET) &&
                            (pSpawn->Type == SPAWN_NPC) &&
                            (pSpawn->MasterID != 0)
                        ) || (
                        (pSearchSpawn->SpawnType == SPAWN_CORPSE) &&
                            (pSpawn->Type == SPAWN_CORPSE)
                        )
                    )
                )
            )
	{

            if (pSearchSpawn->Radius>0.0f) {
				if (IsPCNear(pSpawn,pSearchSpawn->Radius)) return FALSE;
	        }
			if (gZFilter<10000.0f) {
				if ((pSpawn->Z > pChar->Z + gZFilter) ||
					(pSpawn->Z < pChar->Z - gZFilter)) return FALSE;
			}
            if (pSearchSpawn->ZRadius<10000.0f) {
				if ((pSpawn->Z > pChar->Z + pSearchSpawn->ZRadius) ||
					(pSpawn->Z < pChar->Z - pSearchSpawn->ZRadius)) return FALSE;
            }
			if (pSearchSpawn->FRadius<10000.0f) {
				if (DistanceToSpawn(pChar, pSpawn)>pSearchSpawn->FRadius) return FALSE;
            }
			if (pSearchSpawn->bLight) {
				if (!stricmp(GetLightForSpawn(pSpawn),"NONE")) return FALSE;
				if (pSearchSpawn->szLight[0] && stricmp(GetLightForSpawn(pSpawn),pSearchSpawn->szLight)) return FALSE;
			}
			return TRUE;

    }
    return FALSE;
}

PCHAR ParseSearchSpawnArgs(PCHAR szArg, PCHAR szRest, PSEARCHSPAWN pSearchSpawn)
{
    if (szArg && pSearchSpawn) {
        if (!strcmp(szArg,"pc")) {
            pSearchSpawn->SpawnType = SPAWN_PLAYER;
        } else if (!strcmp(szArg,"npc")) {
            pSearchSpawn->SpawnType = SPAWN_NPC;
        } else if (!strcmp(szArg,"pet")) {
            pSearchSpawn->SpawnType = SPAWN_PET;
        } else if (!strcmp(szArg,"nopet")) { 
            pSearchSpawn->bNoPet = TRUE; 
        } else if (!strcmp(szArg,"corpse")) {
            pSearchSpawn->SpawnType = SPAWN_CORPSE;
        } else if (!strcmp(szArg,"any")) {
            pSearchSpawn->SpawnType = SPAWN_ANY;
        } else if (!strcmp(szArg,"invis")) {
            pSearchSpawn->bTargInvis = TRUE;
        } else if (!strcmp(szArg,"next")) {
            pSearchSpawn->bTargNext = TRUE;
        } else if (!strcmp(szArg,"prev")) {
            pSearchSpawn->bTargPrev = TRUE;
        } else if (!strcmp(szArg,"lfg")) {
            pSearchSpawn->bLFG = TRUE;
        } else if (!strcmp(szArg,"group")) {
            pSearchSpawn->bGroup = TRUE;
        } else if (!strcmp(szArg,"trader")) {
            pSearchSpawn->bTrader = TRUE;
        } else if (!strcmp(szArg,"range")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->MinLevel = atoi(szArg);
            GetArg(szArg,szRest,2);
            pSearchSpawn->MaxLevel = atoi(szArg);
            szRest = GetNextArg(szRest,2);
        } else if (!strcmp(szArg,"loc")) {
            pSearchSpawn->bKnownLocation = TRUE;
            GetArg(szArg,szRest,1);
            pSearchSpawn->xLoc = (FLOAT)atof(szArg);
            GetArg(szArg,szRest,2);
            pSearchSpawn->yLoc = (FLOAT)atof(szArg);
            szRest = GetNextArg(szRest,2);
        } else if (!strcmp(szArg,"id")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->SpawnID = atoi(szArg);
            szRest = GetNextArg(szRest,1);
        } else if (!strcmp(szArg,"radius")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->FRadius = atof(szArg);
            szRest = GetNextArg(szRest,1);
        } else if (!strcmp(szArg,"body")) {
            GetArg(szArg,szRest,1);
            strcpy(pSearchSpawn->szBodyType,szArg);
            szRest = GetNextArg(szRest,1);
        } else if (!strcmp(szArg,"class")) {
            GetArg(szArg,szRest,1);
            strcpy(pSearchSpawn->szClass,szArg);
            szRest = GetNextArg(szRest,1);
        } else if (!strcmp(szArg,"race")) {
            GetArg(szArg,szRest,1);
            strcpy(pSearchSpawn->szRace,szArg);
            szRest = GetNextArg(szRest,1);
        } else if (!strcmp(szArg,"light")) {
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
        } else if (!strcmp(szArg,"guild")) {
            DWORD GuildID = 0xFFFF;
            GetArg(szArg,szRest,1);
            if (szArg[0]!=0) GuildID = GetGuildIDByName(szArg);
            if (GuildID!=0xFFFF) {
                pSearchSpawn->GuildID = GuildID;
                szRest = GetNextArg(szRest,1);
            } else {
                pSearchSpawn->GuildID = GetCharInfo()->pSpawn->GuildID;
            }
        } else if (!strcmp(szArg,"alert")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->AlertList = atoi(szArg);
            szRest = GetNextArg(szRest,1);
            pSearchSpawn->bAlert = TRUE;
        } else if (!strcmp(szArg,"noalert")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->NoAlertList = atoi(szArg);
            szRest = GetNextArg(szRest,1);
            pSearchSpawn->bNoAlert = TRUE;
        } else if (!strcmp(szArg,"notnearalert")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->NotNearAlertList = atoi(szArg);
            szRest = GetNextArg(szRest,1);
            pSearchSpawn->bNotNearAlert = TRUE;
        } else if (!strcmp(szArg,"nearalert")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->NearAlertList = atoi(szArg);
            szRest = GetNextArg(szRest,1);
            pSearchSpawn->bNearAlert = TRUE;
        } else if (!strcmp(szArg,"zradius")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->ZRadius = atof(szArg);
            szRest = GetNextArg(szRest,1);
        } else if (!strcmp(szArg,"notid")) {
            GetArg(szArg,szRest,1);
            pSearchSpawn->NotID = atoi(szArg);
            szRest = GetNextArg(szRest,1);
        } else if (!strcmp(szArg,"nopcnear")) {
            GetArg(szArg,szRest,1);

            if ((szArg[0]==0) || (0.0f == (pSearchSpawn->Radius = (FLOAT)atof(szArg)))) {
                pSearchSpawn->Radius = 200.0f;
            } else {
                szRest = GetNextArg(szRest,1);
            }
        } else {
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
    if (!EQADDR_SPAWNLIST) return;
    if (!*EQADDR_SPAWNLIST) return;
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
            if ((*EQADDR_CHAR_INFO)->pSpawn) {
                pSpawnClosest = (*EQADDR_CHAR_INFO)->pSpawn;
                DidTarget = TRUE;
            }
        } else if (!strcmp(szArg,"mycorpse")) {
            if ((*EQADDR_CHAR_INFO)->pSpawn) {
                sprintf(szFilter,"%s's Corpse",(*EQADDR_CHAR_INFO)->pSpawn->Name);
                _strlwr(szFilter);
            }
        } else if (!strcmp(szArg,"clear")) {
            *EQADDR_TARGET = NULL;
            DebugSpew("Target cleared.");
            WriteChatBuffer("Target cleared.",USERCOLOR_WHO);
            return;
        } else {
            szFilter = ParseSearchSpawnArgs(szArg,szFilter,&SearchSpawn);
        }
    }
    if (*EQADDR_TARGET) SearchSpawn.FromSpawnID = (*EQADDR_TARGET)->SpawnID;

    if (!DidTarget) {
        pSpawnClosest = SearchThroughSpawns(&SearchSpawn,pChar);
    }

    if (!pSpawnClosest) {
        CHAR szTemp[MAX_STRING] = {0};
        sprintf(szMsg,"There are no spawns matching: %s",FormatSearchSpawn(szTemp,&SearchSpawn));
        strcpy(gLastError,"TARGET_NOTFOUND");
    } else {
        PSPAWNINFO *pTarget = NULL;
        if (EQADDR_TARGET) {
            pTarget = EQADDR_TARGET;
            *pTarget = pSpawnClosest;
            DebugSpew("Target - %s selected",pSpawnClosest->Name);
//            sprintf(szMsg,"Selected '%s'...",CleanupName(strcpy(szArg,pSpawnClosest->Name),FALSE));
//			sprintf(szMsg,"Selected '%s'...",CleanupName(strcpy(szArg,pSpawnClosest->Name),FALSE));
			szMsg[0]=0;
            gLastError[0]=0;
        } else {
            sprintf(szMsg,"Unable to target, address = 0");
            strcpy(gLastError,"TARGET_NOTFOUND");
        }
    }
	if (szMsg[0])
    if (!gFilterTarget) WriteChatBuffer(szMsg,USERCOLOR_WHO);
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
        WriteChatBuffer(szBuffer,USERCOLOR_DEFAULT);
        return;
    }

    if (!gMacroBlock) {
        WriteChatBuffer("You cannot pause a macro when one isn't running.",CONCOLOR_RED);
        return;
    }

   for (Command=0;szPause[Command];Command++) { 
      if (!stricmp(szArg,szPause[Command])) { 
         Pause = Command; 
      } 
   } 

   if (szLine[0]!=0) { 
      WriteChatBuffer("Syntax: /mqpause [on|off] [chat [on|off]]",USERCOLOR_DEFAULT); 
    } else {
        Pause = !gMacroPause;
    }
    if (gMacroPause == Pause) {
        sprintf(szBuffer,"Macro is already %s.",(Pause)?"paused":"running");
    } else {
        sprintf(szBuffer,"Macro is %s.",(Pause)?"paused":"running again");
        gMacroPause = Pause;
    }
    WriteChatBuffer(szBuffer,USERCOLOR_DEFAULT);
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
    sprintf(szServerAndName,"%s.%s",(*EQADDR_CHAR_INFO)->Server,(*EQADDR_CHAR_INFO)->Name);
    WritePrivateProfileString(szServerAndName,"AutoRun",szLine,gszINIFilename);
    sprintf(szServerAndName,"Set autorun to: '%s'",szLine);
    WriteChatBuffer(szServerAndName,USERCOLOR_DEFAULT);
}


// ***************************************************************************
// Function:    Hotkey
// Description: Our '/hotkey' command
//              Add command hotkeys
// Usage:       /hotkey name [delete|command]
// ***************************************************************************

VOID WriteHotkeyProfile(PCHAR szName, PCHAR szCommand)
{
    CHAR szHotkey[MAX_STRING] = {0};
    strcpy(szHotkey,szName);
    if (!stricmp(szHotkey,"=")) strcpy(szHotkey,"EQUALSIGN");
    if (!stricmp(szHotkey,";")) strcpy(szHotkey,"SEMICOLON");
    if (!stricmp(szHotkey,"[")) strcpy(szHotkey,"LEFTBRACKET");
    WritePrivateProfileString("Hotkeys",szHotkey,szCommand,gszINIFilename);
}

VOID RewriteHotkeys(VOID)
{
    PHOTKEY pLoop = pHotkey;
    WritePrivateProfileSection("Hotkeys","",gszINIFilename);
    while (pLoop) {
        WriteHotkeyProfile(pLoop->szName,pLoop->szCommand);
        pLoop = pLoop->pNext;
    }
}


VOID Hotkey(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szBuffer[MAX_STRING] = {0};
    CHAR szName[MAX_STRING] = {0};
    PCHAR szCommand = NULL;
    GetArg(szName,szLine,1);
    szCommand = GetNextArg(szLine);
    if (!stricmp(szName,"list")) {
        PHOTKEY pLoop = pHotkey;
        DWORD Count=0;
        WriteChatColor("Hotkeys",USERCOLOR_WHO);
        WriteChatColor("--------------------------",USERCOLOR_WHO);
        while (pLoop) {
            sprintf(szName,"%s: %s",pLoop->szName,pLoop->szCommand);
            WriteChatColor(szName,USERCOLOR_WHO);
            Count++;
            pLoop = pLoop->pNext;
        }
        if (Count==0) {
            WriteChatColor("No hotkeys defined.",USERCOLOR_WHO);
        } else {
            sprintf(szName,"%d hotkey%s displayed.",Count,(Count==1)?"":"s");
            WriteChatColor(szName,USERCOLOR_WHO);
        }
        return;
    }
    if ((szName[0]==0) || (szCommand[0]==0)) {
        WriteChatBuffer("Usage: /hotkey name [delete|command], or /hotkey list",USERCOLOR_DEFAULT);
        return;
    }

    if (!stricmp(szCommand,"delete")) {
        PHOTKEY pLoop = pHotkey;
        PHOTKEY pLast = NULL;
        while (pLoop) {
            if (!stricmp(pLoop->szName,szName)) {

                if (!pLast) {
                    pHotkey = pLoop->pNext;
                } else {
                    pLast->pNext = pLoop->pNext;
                }
                free(pLoop);
                sprintf(szBuffer,"Hotkey '%s' deleted.",szName);
                RewriteHotkeys();
                WriteChatBuffer(szBuffer,USERCOLOR_DEFAULT);
                return;
            }
            pLast = pLoop;
            pLoop = pLoop->pNext;
        }
        sprintf(szBuffer,"Hotkey '%s' not found.",szName);
        WriteChatBuffer(szBuffer,USERCOLOR_DEFAULT);
    } else {
        PHOTKEY pNewHotkey = pHotkey;
        PHOTKEY pNew = NULL;
        while (pNewHotkey) {
            if (!stricmp(szName,pNewHotkey->szName)) break;
            pNewHotkey = pNewHotkey->pNext;
        }
        if (!pNewHotkey) {
            pNew = (PHOTKEY)malloc(sizeof(HOTKEY));
            pNewHotkey = pNew;
            pNew->pNext = pHotkey;
            pHotkey=pNew;
        }
        strcpy(pNewHotkey->szName,szName);
        strcpy(pNewHotkey->szCommand,szCommand);
        DWORD i;
        for (i=0;gDiKeyID[i].szName[0];i++) {
            if (!stricmp(gDiKeyID[i].szName,szName)) {
                pNewHotkey->DIKey = gDiKeyID[i].Id;
            }
        }
        WriteHotkeyProfile(szName,szCommand);
        sprintf(szBuffer,"Hotkey '%s' %sed.",szName,(pNew)?"add":"updat");
        WriteChatBuffer(szBuffer,USERCOLOR_DEFAULT);
    }
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
        WriteChatBuffer("Usage: /alias name [delete|command], or /alias list",USERCOLOR_DEFAULT);
        return;
    }

    if (!stricmp(szCommand,"delete")) {
		if (RemoveAlias(szName))
		{
            sprintf(szBuffer,"Alias '%s' deleted.",szName);
            RewriteAliases();
            WriteChatBuffer(szBuffer,USERCOLOR_DEFAULT);
		}
		else
		{
	        sprintf(szBuffer,"Alias '%s' not found.",szName);
			WriteChatBuffer(szBuffer,USERCOLOR_DEFAULT);
		}
    } else {
		BOOL New=1;
		if (RemoveAlias(szName))
			New=0;
		AddAlias(szName,szCommand);
        sprintf(szBuffer,"Alias '%s' %sed.",szName,(New)?"add":"updat");
        WriteChatBuffer(szBuffer,USERCOLOR_DEFAULT);
        RewriteAliases();
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
    if (!strstr(szArg1,"\\")) {
        sprintf(szOutput,"%s\\%s",gszMacroPath, szArg1);
        strcpy(szArg1,szOutput);
    }
    if (!strstr(szArg1,".")) strcat(szArg1,".ini");
   ZeroMemory(szOutput,MAX_STRING);

   if (!WritePrivateProfileString(szArg2,szArg3,szArg4,szArg1)) {
      sprintf(szOutput,"IniOutput ERROR -- during WritePrivateProfileString: %s",szLine);
      DebugSpew(szOutput);
      //WriteChatBuffer(szOutput, CONCOLOR_RED);
   } else {
      sprintf(szOutput,"IniOutput Write Successful!");
      DebugSpew("%s: %s",szOutput,szLine);
      //WriteChatBuffer(szOutput, CONCOLOR_GREEN);
   }
}

// ***************************************************************************
// Function:   DisplayZem
// Description: Displays the ZEM of the current zone to chat screen
// 2003-05-17   anOrcPawn00
// ***************************************************************************
VOID DisplayZem(PSPAWNINFO pChar, PCHAR szLine)
{
   float BASE_ZEM = 75.0;
   float zem = 0;
   float bonus = 0;

   if (!EQADDR_ZONEINFO) return;

   CHAR out[MAX_STRING] = {0};

   PZONEINFO ZoneInfo = EQADDR_ZONEINFO;

   if (ZoneInfo && ZoneInfo->ZoneExpModifier) {
      zem = ZoneInfo->ZoneExpModifier * 100;
      bonus = zem - BASE_ZEM;
      sprintf(out, "\awZone experience modifier: \ag%.1f%%\ax (\a%c%.1f%% %s\ax)", zem, (bonus<0) ? 'r' : 't', (bonus<0) ? 0-bonus : bonus, (bonus<0) ? "penalty" : "bonus" ); 
      WriteChatColor(out,0);
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
        sprintf(szTemp,"/banklist -- Bad offset: CharInfo");
        WriteChatBuffer(szTemp,CONCOLOR_RED);
        return;
    }
    WriteChatBuffer("Listing of Bank Inventory",USERCOLOR_DEFAULT);
    WriteChatBuffer("-------------------------",USERCOLOR_DEFAULT);
	char Link[256];
    for (int a=0;a<18;a++) {
		pContainer=pCharInfo->Bank[a];
        if (pContainer) {
			GetItemLink(pContainer,&Link[0]);
			sprintf(szTemp,"Slot %d: %dx %s (%s)",a,pContainer->StackCount ? pContainer->StackCount : 1,Link,pContainer->Item->LoreName);
            WriteChatBuffer(szTemp,USERCOLOR_DEFAULT);
            for (int b=0;b<10;b++) {
                if (pContainer->Contents[b]) {
					GetItemLink(pContainer->Contents[b],&Link[0]);
                    sprintf(szTemp,"- Slot %d: %dx %s (%s)",b,pContainer->Contents[b]->StackCount ? pContainer->Contents[b]->StackCount : 1,Link,pContainer->Contents[b]->Item->LoreName);
                    WriteChatBuffer(szTemp,USERCOLOR_DEFAULT);
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
	struct _WINDOWSTATELIST 
		{ PCHAR szName;	PCSIDLWND* pWindow; }
	WindowList[] = {
		{ "inventory",	(PCSIDLWND*)EQADDR_INVENTORYWND },
		{ "merchant",	(PCSIDLWND*)EQADDR_CLASSMERCHWND },
		{ "corpse",		(PCSIDLWND*)EQADDR_LOOTWND },
		{ "spellbook",	(PCSIDLWND*)EQADDR_SPELLBOOKWND },
		{ "map",		(PCSIDLWND*)EQADDR_CLASSMAPWND },
		{ "notes",		(PCSIDLWND*)EQADDR_CLASSNOTESWND },
//		{ "MQChat",		(PCSIDLWND*)&MQChatWnd },
		{ NULL, NULL }
	};

	CHAR Arg1[MAX_STRING] = {0};
	CHAR Arg2[MAX_STRING] = {0};
	DWORD i;
	GetArg(Arg1,szLine,1);
	GetArg(Arg2,szLine,2);
	if (Arg1[0]!=0) for (i=0;WindowList[i].szName;i++) {
		if (!strnicmp(WindowList[i].szName,Arg1,strlen(Arg1))) {
			PCSIDLWND pWnd = *WindowList[i].pWindow;
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
			WriteChatBuffer(szBuffer,USERCOLOR_DEFAULT);
			return;
		}
	}
	WriteChatBuffer("Usage: /windowstate <window> [open|close]",USERCOLOR_DEFAULT);
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
      WriteChatBuffer(szCmd,USERCOLOR_DEFAULT);
      return;
   }
   for (Command=0;szKeepKeys[Command];Command++) {
      if (!stricmp(szArg,szKeepKeys[Command])) {
         gKeepKeys = Command;
         sprintf(szCmd,"Auto-Keep Keys changed to: %s",szKeepKeys[gKeepKeys]);
         WriteChatBuffer(szCmd,USERCOLOR_DEFAULT);
         itoa(gKeepKeys,szCmd,10); WritePrivateProfileString("MacroQuest","KeepKeys",szCmd,gszINIFilename);
         return;
      }
   }
   WriteChatBuffer("Usage: /keepkeys [on|off]",USERCOLOR_DEFAULT);
}


// ***************************************************************************
// Function:      DisplayLoginName
// Description:   Our /loginname command.
// ***************************************************************************
VOID DisplayLoginName(PSPAWNINFO pChar, PCHAR szLine) 
{
	CHAR Buffer[MAX_STRING] = {0};
	PCHAR szLogin = GetLoginName();
	if (!szLogin) {
		strcpy(Buffer,"Unable to retrieve login name.");
	} else {
		sprintf(Buffer,"Login name: \ay%s\ax",szLogin);
		free(szLogin);
	}
	WriteChatBuffer(Buffer,USERCOLOR_DEFAULT);
}
