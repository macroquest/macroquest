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


#include "MQ2Main.h"


DWORD parmGetLastFindSlot(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    // $getlastfindslot
    if (gLastFindSlot[0] == 0) {
        strcat(szOutput,"NULL");
    } else {
        strcat(szOutput,gLastFindSlot);
    }
    return 14;
}

DWORD parmCursor(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    // $cursor(xxx)
    int i=0;
    CHAR szTmp[MAX_STRING]={0};
    PCHARINFO pCharInfo = NULL;
    if (NULL == (pCharInfo = GetCharInfo())) return PMP_ERROR_BADPARM;
    PITEMINFO pItem=NULL;
    if (pCharInfo->Cursor) pItem = pCharInfo->Cursor->Item;

    if (!strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $cursor() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    } else if (!pItem) {
        while ((szVar[i] != ')') && (szVar[i] != 0)) i++;
        strcat(szOutput,"NULL");

    // $cursor()
    } else if (!strncmp("cursor()",szVar,8)) {
        i+=7;
        strcat(szOutput,"TRUE");

    // $cursor(lore)
    } else if (!strncmp("cursor(lore)",szVar,12)) {
        i+=11;
        if (pItem->LoreName[0]=='*') {
            strcat(szOutput,"TRUE");
        } else {
            strcat(szOutput,"FALSE");
        }

    // $cursor(nodrop)
    } else if (!strncmp("cursor(nodrop)",szVar,14)) {
        i+=13;
        if (!pItem->NoDrop) {
            strcat(szOutput,"TRUE");
        } else {
            strcat(szOutput,"FALSE");
        }

    // $cursor(norent)
    } else if (!strncmp("cursor(norent)",szVar,14)) {
        i+=13;
        if (!pItem->NoRent) {
            strcat(szOutput,"TRUE");
        } else {
            strcat(szOutput,"FALSE");
        }

    // $cursor(magic)
    } else if (!strncmp("cursor(magic)",szVar,13)) {
        i+=12;
        if ((pItem->Type == ITEMTYPE_NORMAL) && (pItem->Common.Magic)) {
            strcat(szOutput,"TRUE");
        } else {
            strcat(szOutput,"FALSE");
        }

    // $cursor(name)
    } else if (!strncmp("cursor(name)",szVar,12)) {
        i+=11;
        strcat(szOutput,pItem->Name);

    // $cursor(type)
    } else if (!strncmp("cursor(type)",szVar, 12)) {
        i+=11;
        if (pItem->Type == ITEMTYPE_NORMAL) {
            if ((pItem->Common.ItemType < MAX_ITEMTYPES) && (szItemTypes[pItem->Common.ItemType] != NULL)) {
                strcat(szOutput,szItemTypes[pItem->Common.ItemType]);
            } else {
                sprintf(szTmp,"*UnknownType%d",pItem->Common.ItemType);
                strcat(szOutput, szTmp);
            }
        }
        else if (pItem->Type == ITEMTYPE_PACK) {
            if ((pItem->Container.Combine < MAX_COMBINES) && (szCombineTypes[pItem->Container.Combine] != NULL)) {
                strcat(szOutput,szCombineTypes[pItem->Container.Combine]);
            } else {
                sprintf(szTmp,"*UnknownType%d",pItem->Container.Combine);
                strcat(szOutput, szTmp);
            }
        }
        else if (pItem->Type == ITEMTYPE_BOOK) {
            strcat(szOutput, "Book");
        }

    // $cursor(value)
    } else if (!strncmp("cursor(value)",szVar,13)) {
        i+=12;
        CHAR szTemp[MAX_STRING] = {0};
        itoa(pItem->Cost,szTemp,10);
        strcat(szOutput,szTemp);

    // $cursor(size)
    } else if (!strncmp("cursor(size)",szVar,12)) {
        i+=11;
        CHAR szTemp[MAX_STRING] = {0};
        itoa(pItem->Size,szTemp,10);
        strcat(szOutput,szTemp);

    // $cursor(weight)
    } else if (!strncmp("cursor(weight)",szVar,14)) {
        i+=13;
        CHAR szTemp[MAX_STRING] = {0};
        itoa(pItem->Weight,szTemp,10);
        strcat(szOutput,szTemp);

    // $cursor(stack)
    } else if (!strncmp("cursor(stack)",szVar,13)) {
        i+=12;
        CHAR szTemp[MAX_STRING] = {0};
        if ((pItem->Type != ITEMTYPE_NORMAL) || (pItem->Common.Stackable!=1)) {
            strcpy(szTemp,"1");
        } else {
            itoa(pCharInfo->Cursor->StackCount,szTemp,10);
        }
        strcat(szOutput,szTemp);

    // $cursor(id)
    } else if (!strncmp("cursor(id)",szVar,10)) {
        i+=9;
        CHAR szTemp[MAX_STRING] = {0};
        sprintf(szTemp,"%d",pItem->ItemNumber);
        strcat(szOutput,szTemp);


    // $cursor(unknown)
    } else {
        DebugSpewNoFile("PMP - Bad $cursor() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    }
    return i;
}

DWORD parmItem(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    // $item(xxx)
    DWORD i=0;
    WORD Offset = 5;
    WORD Pack = 99;
    WORD Slot = 99;
    WORD Bank = 0;
    WORD MainSlot = 0;
    BOOL Enviro = FALSE;
    PCONTENTS pItem = NULL;
    PCHARINFO pCharInfo = NULL;
    if (NULL == (pCharInfo = GetCharInfo())) return PMP_ERROR_BADPARM;

    if (!strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $item() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    } else {
        if (!strnicmp("bank,",szVar+Offset,5)) {
            Offset+=5;
            Bank = 1;
        }
        if (!strnicmp("inv,",szVar+Offset,4)) {
            Offset+=4;
            MainSlot = 1;
        }
        Pack = atoi(szVar+Offset);
        if (szVar[Offset]=='e' || szVar[Offset]=='E') Enviro = TRUE;
        while ((szVar[Offset] != ',') && (szVar[Offset] != ')')) Offset++;
        if (szVar[Offset] != ')') Offset++;
        if ((MainSlot==0) && (szVar[Offset] != ')')) {
            Slot = atoi(szVar+Offset);
            while ((szVar[Offset] != ',') && (szVar[Offset] != ')')) Offset++;
            if (szVar[Offset] != ')') Offset++;
        }
        if (Pack<8) {
            if (Bank==0) {
                if (!Enviro) {
                    if (!pCharInfo->Inventory[22+Pack]) return PMP_ERROR_BADPARM;
                    pItem = pCharInfo->Inventory[22+Pack];
                } else {
                    pItem = GetEnviroContainer();
                }
                if (MainSlot==0) {
                    if ((!pItem) || (pItem->Item->Type != ITEMTYPE_PACK && !Enviro) || (pItem->Item->Container.Slots<=Slot)) {
                        pItem=NULL;
                    } else if (pItem->Contents[Slot]) {
                        pItem = pItem->Contents[Slot];
                        Enviro=FALSE;
                    } else {
                        pItem=NULL;
                    }
                }
            } else {
                if (!pCharInfo->Bank[Pack]) return PMP_ERROR_BADPARM;
                pItem = pCharInfo->Bank[Pack];
                if (MainSlot==0) {
                    if ((!pItem) || (pItem->Item->Type != ITEMTYPE_PACK) || (pItem->Item->Container.Slots<=Slot)) {
                        pItem=NULL;
                    } else if (pItem->Contents[Slot]) {
                        pItem = pItem->Contents[Slot];
                    } else {
                        pItem=NULL;
                    }
                }
            }
        }
        if (!pItem) {
            while ((szVar[i] != ')') && (szVar[i] != 0)) i++;
            strcat(szOutput,"NULL");

        // $item()
        } else if (!strncmp(")",szVar+Offset,1)) {
            i+=Offset;
            strcat(szOutput,"TRUE");

        // $item(lore)
        } else if (!strncmp("lore)",szVar+Offset,5)) {
            i+=Offset+4;
            if (pItem->Item->LoreName[0]=='*') {
                strcat(szOutput,"TRUE");
            } else {
                strcat(szOutput,"FALSE");
            }

        // $item(nodrop)
        } else if (!strncmp("nodrop)",szVar+Offset,7)) {
            i+=Offset+6;
            if (!pItem->Item->NoDrop) {
                strcat(szOutput,"TRUE");
            } else {
                strcat(szOutput,"FALSE");
            }

        // $item(norent)
        } else if (!strncmp("norent)",szVar+Offset,7)) {
            i+=Offset+6;
            if (!pItem->Item->NoRent) {
                strcat(szOutput,"TRUE");
            } else {
                strcat(szOutput,"FALSE");
            }

        // $item(magic)
        } else if (!strncmp("magic)",szVar+Offset,7)) {
            i+=Offset+6;
            if ((pItem->Item->Type == ITEMTYPE_NORMAL) && (pItem->Item->Common.Magic)) {
                strcat(szOutput,"TRUE");
            } else {
                strcat(szOutput,"FALSE");
            }

        // $item(name)
        } else if (!strncmp("name)",szVar+Offset,5)) {
            i+=Offset+4;
            strcat(szOutput,pItem->Item->Name);

        // $item(value)
        } else if (!strncmp("value)",szVar+Offset,6)) {
            i+=Offset+5;
            CHAR szTemp[MAX_STRING] = {0};
            itoa(pItem->Item->Cost,szTemp,10);
            strcat(szOutput,szTemp);

        // $item(size)
        } else if (!strncmp("size)",szVar+Offset,5)) {
            i+=Offset+4;
            CHAR szTemp[MAX_STRING] = {0};
            itoa(pItem->Item->Size,szTemp,10);
            strcat(szOutput,szTemp);

        // $item(weight)
        } else if (!strncmp("weight)",szVar+Offset,7)) {
            i+=Offset+6;
            CHAR szTemp[MAX_STRING] = {0};
            itoa(pItem->Item->Weight,szTemp,10);
            strcat(szOutput,szTemp);

        // $item(stack)
        } else if (!strncmp("stack)",szVar+Offset,6)) {
            i+=Offset+5;
            CHAR szTemp[MAX_STRING] = {0};
            if ((pItem->Item->Type != ITEMTYPE_NORMAL) || (pItem->Item->Common.Stackable!=1)) {
                strcpy(szTemp,"1");
            } else {
                itoa(pItem->StackCount,szTemp,10);
            }
            strcat(szOutput,szTemp);

        // $item(id)
        } else if (!strncmp("id)",szVar+Offset,3)) {
            i+=Offset+2;
            CHAR szTemp[MAX_STRING] = {0};
            sprintf(szTemp,"%d",pItem->Item->ItemNumber);
            strcat(szOutput,szTemp);

        // $item(type)
        } else if (!strncmp("type)",szVar+Offset,5)) {
            i+=Offset+4;
            CHAR szTmp[MAX_STRING] = {0};
            if ((pItem->Item->Type == ITEMTYPE_PACK) || Enviro) {
                if ((pItem->Item->Container.Combine < MAX_COMBINES) && (szCombineTypes[pItem->Item->Container.Combine] != NULL)) {
                    strcat(szOutput,szCombineTypes[pItem->Item->Container.Combine]);
                } else {
                    sprintf(szTmp,"*UnknownType%d",pItem->Item->Container.Combine);
                    strcat(szOutput, szTmp);
                }
            }
            else if (pItem->Item->Type == ITEMTYPE_NORMAL) {
                if ((pItem->Item->Common.ItemType < MAX_ITEMTYPES) && (szItemTypes[pItem->Item->Common.ItemType] != NULL)) {
                    strcat(szOutput,szItemTypes[pItem->Item->Common.ItemType]);
                } else {
                    sprintf(szTmp,"*UnknownType%d",pItem->Item->Common.ItemType);
                    strcat(szOutput, szTmp);
                }
            }
            else if (pItem->Item->Type == ITEMTYPE_BOOK) {
                strcat(szOutput, "Book");
            }

        // $item(unknown)
        } else {
            DebugSpewNoFile("PMP - Bad $item() '%s'",szVar);
            return PMP_ERROR_BADPARM;
        }
    }
    return i;
}

DWORD parmEquip(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    // $equip(xxx)
    WORD Offset = 6;
    WORD Slot = 99;
    WORD Index;
    DWORD i=0;
    PCHARINFO pCharInfo = NULL;
    if (NULL == (pCharInfo = GetCharInfo())) return PMP_ERROR_BADPARM;
    PCHAR szEquipSlot[] = {
        "charm",
        "ear1",
        "head",
        "face",
        "ear2",
        "neck",
        "shoulder",
        "arms",
        "back",
        "wrist1",
        "wrist2",
        "ranged",
        "hands",
        "primary",
        "secondary",
        "finger1",
        "finger2",
        "chest",
        "legs",
        "feet",
        "waist",
        "ammo",
        NULL
    };
    PCONTENTS pItem = NULL;

    if (!strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $equip() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    } else {
        for (Index=0;(Slot==99) &&(szEquipSlot[Index]!=NULL);Index++) {
            if (!strnicmp(szVar+Offset,szEquipSlot[Index],strlen(szEquipSlot[Index]))) {
                Slot=Index;
            }
        }
        while ((szVar[Offset] != ',') && (szVar[Offset] != ')')) Offset++;
        if (szVar[Offset] != ')') Offset++;
        if (!pCharInfo->Inventory[Slot]) return PMP_ERROR_BADPARM;
        if (Slot!=99 && pCharInfo->Inventory[Slot]) pItem = pCharInfo->Inventory[Slot];
        if (!pItem) {
            while ((szVar[i] != ')') && (szVar[i] != 0)) i++;
            strcat(szOutput,"NULL");

        // $equip()
        } else if (!strncmp(")",szVar+Offset,1)) {
            i+=Offset;
            strcat(szOutput,"TRUE");

        // $equip(lore)
        } else if (!strncmp("lore)",szVar+Offset,5)) {
            i+=Offset+4;
            if (pItem->Item->LoreName[0]=='*') {
                strcat(szOutput,"TRUE");
            } else {
                strcat(szOutput,"FALSE");
            }

        // $equip(nodrop)
        } else if (!strncmp("nodrop)",szVar+Offset,7)) {
            i+=Offset+6;
            if (!pItem->Item->NoDrop) {
                strcat(szOutput,"TRUE");
            } else {
                strcat(szOutput,"FALSE");
            }

        // $equip(norent)
        } else if (!strncmp("norent)",szVar+Offset,7)) {
            i+=Offset+6;
            if (!pItem->Item->NoRent) {
                strcat(szOutput,"TRUE");
            } else {
                strcat(szOutput,"FALSE");
            }

        // $equip(magic)
        } else if (!strncmp("magic)",szVar+Offset,7)) {
            i+=Offset+6;
            if ((pItem->Item->Type == ITEMTYPE_NORMAL) && (pItem->Item->Common.Magic)) {
                strcat(szOutput,"TRUE");
            } else {
                strcat(szOutput,"FALSE");
            }

        // $equip(name)
        } else if (!strncmp("name)",szVar+Offset,5)) {
            i+=Offset+4;
            strcat(szOutput,pItem->Item->Name);

        // $equip(id)
        } else if (!strncmp("id)",szVar+Offset,3)) {
            i+=Offset+2;
            CHAR szTemp[MAX_STRING] = {0};
            itoa(pItem->Item->ItemNumber,szTemp,10);
            strcat(szOutput,szTemp);

        // $equip(value)
        } else if (!strncmp("value)",szVar+Offset,6)) {
            i+=Offset+5;
            CHAR szTemp[MAX_STRING] = {0};
            itoa(pItem->Item->Cost,szTemp,10);
            strcat(szOutput,szTemp);

        // $equip(size)
        } else if (!strncmp("size)",szVar+Offset,5)) {
            i+=Offset+4;
            CHAR szTemp[MAX_STRING] = {0};
            itoa(pItem->Item->Size,szTemp,10);
            strcat(szOutput,szTemp);

        // $equip(weight)
        } else if (!strncmp("weight)",szVar+Offset,7)) {
            i+=Offset+6;
            CHAR szTemp[MAX_STRING] = {0};
            itoa(pItem->Item->Weight,szTemp,10);
            strcat(szOutput,szTemp);

        // $equip(stack)
        } else if (!strncmp("stack)",szVar+Offset,6)) {
            i+=Offset+5;
            CHAR szTemp[MAX_STRING] = {0};
            if ((pItem->Item->Type != ITEMTYPE_NORMAL) || (pItem->Item->Common.Stackable!=1)) {
                strcpy(szTemp,"1");
            } else {
                itoa(pItem->StackCount,szTemp,10);
            }
            strcat(szOutput,szTemp);

        // $equip(type)
        } else if (!strncmp("type)",szVar+Offset,5)) {
            CHAR szTmp[MAX_STRING] = {0};
            i+=Offset+4;
            if (pItem->Item->Type == ITEMTYPE_NORMAL) {
                if ((pItem->Item->Common.ItemType < MAX_ITEMTYPES) && (szItemTypes[pItem->Item->Common.ItemType] != NULL)) {
                    strcat(szOutput,szItemTypes[pItem->Item->Common.ItemType]);
                } else {
                    sprintf(szTmp,"*UnknownType%d",pItem->Item->Common.ItemType);
                    strcat(szOutput, szTmp);
                }
            }
            else if (pItem->Item->Type == ITEMTYPE_PACK) {
                if ((pItem->Item->Container.Combine < MAX_COMBINES) && (szCombineTypes[pItem->Item->Container.Combine] != NULL)) {
                    strcat(szOutput,szCombineTypes[pItem->Item->Container.Combine]);
                } else {
                    sprintf(szTmp,"*UnknownType%d",pItem->Item->Container.Combine);
                    strcat(szOutput, szTmp);
                }
            }
            else if (pItem->Item->Type == ITEMTYPE_BOOK) {
                strcat(szOutput, "Book");
            }

        // $equip(unknown)
        } else {
            DebugSpewNoFile("PMP - Bad $item() '%s'",szVar);
            return PMP_ERROR_BADPARM;
        }
    }
    return i;
}

DWORD parmGroup(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $group(xxx)
    PSPAWNINFO psTarget = NULL;
    if (ppTarget && pTarget) {
        psTarget = (PSPAWNINFO)pTarget;
    }

    // $group(count)
    if (!strncmp("group(count)",szVar,12)) {
        i+=11;
        DWORD c=1, index;
        CHAR szTemp[MAX_STRING] = {0};
        if (EQADDR_GROUPCOUNT) for (index=0;index<5;index++) if (EQADDR_GROUPCOUNT[index]) c++;
        itoa(c,szTemp,10);
        strcat(szOutput,szTemp);

    // $group(#)
    } else if (strstr(szVar,")")) {
        CHAR szTemp[MAX_STRING] = {0};
        DWORD c=atoi(szVar+6);
        DWORD d,index=6;
        i+=strstr(szVar,")")-szVar;
        if (c==0) {
            itoa(GetCharInfo()->pSpawn->SpawnID,szTemp,10);
        } else if (EQADDR_GROUPCOUNT && ppGroup && (c<6)) {
            for (d=0;d<5 && c>0;d++) {
                if (EQADDR_GROUPCOUNT[d]) c--;
                if (!c) index=d;
            }
            if (index==6) {
                strcat(szTemp,"-1");
            } else if (ppGroup[index]) {
                itoa(((PSPAWNINFO)ppGroup[index])->SpawnID,szTemp,10);
            } else {
                strcat(szTemp,"0");
            }
        } else {
            strcat(szTemp,"-1");
        }
        strcat(szOutput,szTemp);

    // $group(unknown)
    } else {
            DebugSpewNoFile("PMP - Bad $group() '%s'",szVar);
            return PMP_ERROR_BADPARM;
    }
    return i;
}

DWORD parmTarget(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    // $target(xxx)
    DWORD i=0;
    PSPAWNINFO psTarget = NULL;
    if (ppTarget && pTarget) {
        psTarget = (PSPAWNINFO)pTarget;
    }

    // $target()
    if (!strncmp("target()",szVar,8)) {
        i+=7;
        if (!psTarget) {
            strcat(szOutput,"FALSE");
        } else {
            strcat(szOutput,"TRUE");
        }

   // $target(animation)
    } else if (!strncmp("target(animation)",szVar,17)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=16;
      itoa(psTarget->pActorInfo->Animation,szTemp,10);
        strcat(szOutput,szTemp);

    // $target(distance,x)
    } else if (!strncmp("target(distance,x)",szVar,18)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=17;

        if (!psTarget) {
            strcat(szOutput,"0");
        } else {
            itoa((INT)fabs(pChar->X-psTarget->X),szTemp,10);
            strcat(szOutput,szTemp);
        }

    // $target(distance,y)
    } else if (!strncmp("target(distance,y)",szVar,18)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=17;

        if (!psTarget) {
            strcat(szOutput,"0");
        } else {
            itoa((INT)fabs(pChar->Y-psTarget->Y),szTemp,10);
            strcat(szOutput,szTemp);
        }

    // $target(distance,z)
    } else if (!strncmp("target(distance,z)",szVar,18)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=17;

        if (!psTarget) {
            strcat(szOutput,"0");
        } else {
            itoa((INT)fabs(pChar->Z-psTarget->Z),szTemp,10);
            strcat(szOutput,szTemp);
        }

    // $target(distance)
    } else if (!strncmp("target(distance)",szVar,16)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=15;

        if (!psTarget) {
            strcat(szOutput,"0");
        } else {
            itoa((INT)DistanceToSpawn(pChar,psTarget),szTemp,10);
            strcat(szOutput,szTemp);
        }

    // $target(distance,3d)
    } else if (!strncmp("target(distance,3d)",szVar,19)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=18;

        if (!psTarget) {
            strcat(szOutput,"0");
        } else {
            itoa((INT)DistanceToSpawn3D(pChar,psTarget),szTemp,10);
            strcat(szOutput,szTemp);
        }

    // $target(distance,predict)
    } else if (!strncmp("target(distance,predict)",szVar,24)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=23;

        if (!psTarget) {
            strcat(szOutput,"0");
        } else {
            itoa((INT)EstimatedDistanceToSpawn(pChar,psTarget),szTemp,10);
            strcat(szOutput,szTemp);
        }

     // $target(direction)   
    } else if (!strncmp("target(direction)",szVar,17)) {
        i+=16;
        if (!psTarget) {
            strcat(szOutput,"NULL");
        } else {
      CHAR szTemp[MAX_STRING] = {0};
      INT Angle = (INT)((atan2f(pChar->X - psTarget->X, pChar->Y - psTarget->Y) * 180.0f / PI + 360.0f) / 22.5f + 0.5f) % 16;
      sprintf(szTemp,szHeadingShort[Angle]);
        strcat(szOutput,szTemp);
           }

    // $target(Holding)   returns 0 if target is holding NOTHING in their primary,
                        //secondary, or range slots. Otherwise, you get an integer that seems to
                        //represent the types of graphics being held in one or the other or both hands
                        //(and range, though it's rarely visible).   Therefore, a target that returns
                        //a number higher than zero is actually holding something in their hand(s).
                        //(NOTE: Having something in your 'range' slot also counts as holding it.
                        //though it typically doesn't show up graphically).
    } else if (!strncmp("target(holding)",szVar,15)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=14;
      itoa(psTarget->Holding,szTemp,10);
        strcat(szOutput,szTemp);
    // $target(level)
    } else if (!strncmp("target(level)",szVar,13)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=12;
        if (!psTarget) {
            strcat(szOutput,"0");
        } else {
            itoa(psTarget->Level,szTemp,10);
            strcat(szOutput,szTemp);
        }

    // $target(id)
    } else if (!strncmp("target(id)",szVar,10)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=9;
        if (!psTarget) {
            strcat(szOutput,"0");
        } else {
            itoa(psTarget->SpawnID,szTemp,10);
            strcat(szOutput,szTemp);
        }

    // $target(next)
    } else if (!strncmp("target(next)",szVar,12)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=11;
        if (!psTarget) {
            strcat(szOutput,"0");
        } else if (!psTarget->pNext) {
            strcat(szOutput,"0");
        } else {
            itoa(psTarget->pNext->SpawnID,szTemp,10);
            strcat(szOutput,szTemp);
        }

    // $target(prev)
    } else if (!strncmp("target(prev)",szVar,12)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=11;
        if (!psTarget) {
            strcat(szOutput,"0");
        } else if (!psTarget->pPrev) {
            strcat(szOutput,"0");
        } else {
            itoa(psTarget->pPrev->SpawnID,szTemp,10);
            strcat(szOutput,szTemp);
        }

    // $target(x)
    } else if (!strncmp("target(x)",szVar,9)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=8;
        if (!psTarget) {
            strcat(szOutput,"0");
        } else {
            sprintf(szTemp,"%1.2f",psTarget->X);
            strcat(szOutput,szTemp);
        }

    // $target(y)
    } else if (!strncmp("target(y)",szVar,9)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=8;
        if (!psTarget) {
            strcat(szOutput,"0");
        } else {
            sprintf(szTemp,"%1.2f",psTarget->Y);
            strcat(szOutput,szTemp);
        }

    // $target(z)
    } else if (!strncmp("target(z)",szVar,9)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=8;
        if (!psTarget) {
            strcat(szOutput,"0");
        } else {
            sprintf(szTemp,"%1.2f",psTarget->Z);
            strcat(szOutput,szTemp);
        }

    // $target(heading)
    } else if (!strncmp("target(heading)",szVar,15)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=14;
        if (!psTarget) {
            strcat(szOutput,"0");
        } else {
            sprintf(szTemp,"%1.2f",psTarget->Heading*0.703125f);
            strcat(szOutput,szTemp);
        }

    // $target(speed)
    } else if (!strncmp("target(speed)",szVar,13)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=12;
        if (!psTarget) {
            strcat(szOutput,"0");
        } else {
            sprintf(szTemp,"%1.2f",FindSpeed(psTarget));
            strcat(szOutput,szTemp);
        }

    // $target(headingto)
    } else if (!strncmp("target(headingto)",szVar,17)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=16;
        if (!psTarget) {
            strcat(szOutput,"0");
        } else {
            DOUBLE HeadingTo = atan2f(pChar->Y - psTarget->Y, psTarget->X - pChar->X) * 180.0f / PI + 90.0f;
            if (HeadingTo<0.0f) HeadingTo += 360.0f;
            if (HeadingTo>=360.0f) HeadingTo -= 360.0f;
            sprintf(szTemp,"%1.2f",HeadingTo);
            strcat(szOutput,szTemp);
        }

    // $target(light)
    } else if (!strncmp("target(light)",szVar,13)) {
        i+=12;
        if (!psTarget) {
            strcat(szOutput,"NONE");
        } else {
            PCHAR szLight = GetLightForSpawn(psTarget);
            strcat(szOutput,szLight);
        }

    // $target(state)
    } else if (!strncmp("target(state)",szVar,13)) {
        i+=12;
        if (!psTarget) {
            strcat(szOutput,"UNKNOWN");
        } else {
            switch (psTarget->StandState) {
                case STANDSTATE_STAND:
                    strcat(szOutput,"STAND");
                    break;
                case STANDSTATE_SIT:
                    strcat(szOutput,"SIT");
                    break;
                case STANDSTATE_DUCK:
                    strcat(szOutput,"DUCK");
                    break;
                case STANDSTATE_BIND:
                    strcat(szOutput,"BIND");
                    break;
                case STANDSTATE_FEIGN:
                    strcat(szOutput,"FEIGN");
                    break;
                case STANDSTATE_DEAD:
                    strcat(szOutput,"DEAD");
                    break;
                default:
                    strcat(szOutput,"UNKNOWN");
                    break;
            }
        }

    // $target(held,right)
    } else if (!strncmp("target(held,right)",szVar,18)) {
        i+=17;
        PCHAR Model = GetModel(psTarget,MODEL_HELD_R);
        if (Model) {
            strcat(szOutput,Model);
        } else {
            strcat(szOutput,"NULL");
        }

    // $target(held,left)
    } else if (!strncmp("target(held,left)",szVar,17)) {
        i+=16;
        PCHAR Model = GetModel(psTarget,MODEL_HELD_L);
        if (Model) {
            strcat(szOutput,Model);
        } else {
            strcat(szOutput,"NULL");
        }

    // $target(held,shield)
    } else if (!strncmp("target(held,shield)",szVar,19)) {
        i+=18;
        PCHAR Model = GetModel(psTarget,MODEL_SHIELD);
        if (Model) {
            strcat(szOutput,Model);
        } else {
            strcat(szOutput,"NULL");
        }

    // $target(hp,cur)
    } else if (!strncmp("target(hp,cur)",szVar,14)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=13;
        if (!psTarget) {
            strcat(szOutput,"0");
        } else {
            itoa((INT)(psTarget->HPCurrent),szTemp,10);
            strcat(szOutput,szTemp);
        }

    // $target(hp,max)
    } else if (!strncmp("target(hp,max)",szVar,14)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=13;
        if (!psTarget) {
            strcat(szOutput,"0");
        } else {
            itoa((INT)(psTarget->HPMax),szTemp,10);
            strcat(szOutput,szTemp);
        }

    // $target(hp,pct)
    } else if (!strncmp("target(hp,pct)",szVar,14)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=13;
        if (!psTarget) {
            strcat(szOutput,"0");
        } else {
            itoa((INT)(psTarget->HPCurrent*100/psTarget->HPMax),szTemp,10);
            strcat(szOutput,szTemp);
        }

    // return NULL for all following $target(xxx) commands if no target
    } else if (!psTarget) {
        while ((szVar[i] != ')') && (szVar[i] != 0)) i++;
        strcat(szOutput,"NULL");

    // $target(deity)
    } else if (!strncmp("target(deity)",szVar,13)) {
        i+=12;
        CHAR szTemp[MAX_STRING] = {0};
        strcpy(szTemp,pEverQuest->GetDeityDesc(psTarget->Deity));
        strcat(szOutput,szTemp);

    // $target(deity,team)
    } else if (!strncmp("target(deity,team)",szVar,18)) {
        i+=17;
        CHAR szTemp[MAX_STRING] = {0};
        strcpy(szTemp,szDeityTeam[GetDeityTeamByID(psTarget->Deity)]);
        strcat(szOutput,szTemp);

    // $target(type)
    } else if (!strncmp("target(type)",szVar,12)) {
        i+=11;
        strcat(szOutput,szSpawnType[psTarget->Type]);

    // $target(body)
    } else if (!strncmp("target(body)",szVar,12)) {
        i+=11;
        strcat(szOutput,pEverQuest->GetBodyTypeDesc(psTarget->BodyType));

    // $target(name)
    } else if (!strncmp("target(name)",szVar,12)) {
        i+=11;
        strcat(szOutput,psTarget->Name);

    // $target(surname)
    } else if (!strncmp("target(surname)",szVar,15)) {
        i+=14;
        strcat(szOutput,psTarget->Lastname);

    // $target(guild)
    } else if (!strncmp("target(guild)",szVar,13)) {
        i+=12;
        if (psTarget->GuildID < 0xFFFE && EQADDR_GUILDLIST) {
            strcat(szOutput,GetGuildByID(psTarget->GuildID));
        } else {
            strcat(szOutput,"NULL");
        }

    // $target(guild,status)
    } else if (!strncmp("target(guild,status)",szVar,20)) {
        i+=19;
        if (psTarget->GuildID < 0xFFFE && EQADDR_GUILDLIST) {
            strcat(szOutput,szGuildStatus[psTarget->GuildStatus]);
        } else {
            strcat(szOutput,"NULL");
        }

    // $target(name,clean)
    } else if (!strncmp("target(name,clean)",szVar,18)) {
        CHAR szName[MAX_STRING] = {0};
        i+=17;
        strcpy(szName,psTarget->Name);
        strcat(szOutput,CleanupName(szName,FALSE));


    // $target(surname)
    } else if (!strncmp("target(surname)",szVar,15)) {
        i+=14;
        strcat(szOutput,psTarget->Lastname);

    // $target(master)
    } else if (!strncmp("target(master)",szVar,14)) {
        i+=13;
        CHAR szMaster[MAX_STRING] = {0};
        ltoa(psTarget->MasterID,szMaster,10);
        strcat(szOutput,szMaster);

    // $target(pet)
    } else if (!strncmp("target(pet)",szVar,11)) {
        PSPAWNINFO pPet = GetPet(psTarget->SpawnID);
        i+=10;
        if (pPet) {
            CHAR szPet[MAX_STRING] = {0};
            ltoa(pPet->SpawnID,szPet,10);
            strcat(szOutput,szPet);
        } else {
            strcat(szOutput,"0");
        }

    // $target(class)
    } else if (!strncmp("target(class)",szVar,13)) {
        i+=12;
        CHAR szTemp[MAX_STRING] = {0};
        strcpy(szTemp,pEverQuest->GetClassDesc(psTarget->Class));
        strcat(szOutput,szTemp);

    // $target(race)
    } else if (!strncmp("target(race)",szVar,12)) {
        i+=11;
        CHAR szTemp[MAX_STRING] = {0};
        strcpy(szTemp,pEverQuest->GetRaceDesc(psTarget->Race));
        strcat(szOutput,szTemp);

    // $target(gender)
    } else if (!strncmp("target(gender)",szVar,14)) {
        i+=13;
        CHAR szTemp[MAX_STRING] = {0};
        strcpy(szTemp,szGender[psTarget->Gender]);
        strcat(szOutput,szTemp);

    // $target(gm)
    } else if (!strncmp("target(gm)",szVar,10)) {
        i+=9;
        if (psTarget->GM) {
            strcat(szOutput,"TRUE");
        } else {
            strcat(szOutput,"FALSE");
        }

    // $target(unknown)
    } else {
        DebugSpewNoFile("PMP - Bad $target() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    }
    return i;
}


DWORD parmSearchSpawn(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    // $searchspawn(xxx)
    DWORD i=0,argindex=12,j1=0,j2=0;
    PSPAWNINFO pSpawn = NULL;
    SEARCHSPAWN SearchSpawn;
    ClearSearchSpawn(&SearchSpawn);
    CHAR szTemp[MAX_STRING] = {0};
    CHAR szArg[MAX_STRING] = {0};
    CHAR szFullArg[MAX_STRING] = {0};

    if (!strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $searchspawn() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    } else {
        PSPAWNINFO pSpawn = NULL;
        i+=strstr(szVar,")")-szVar;
        szFullArg[0]=1;
        while (szVar[argindex]!=')' && szFullArg[0]) {
            GetArg(szFullArg,szVar+argindex,1,true,true,true);
            strlwr(szFullArg);
            if (szFullArg[strlen(szFullArg)-1]==')') szFullArg[strlen(szFullArg)-1]=0;
            //DebugSpewAlways("%s[%d]=%s",szVar,argindex,szVar[argindex],szArg);
            ZeroMemory(szArg,2048);
            j2=0;
            for (j1=0;j1<strlen(szFullArg);j1++) if (szFullArg[j1]!='"') szArg[j2++]=szFullArg[j1];

            if (!strcmp(szArg,"pc")) {
                SearchSpawn.SpawnType = SPAWN_PLAYER;
            } else if (!strcmp(szArg,"npc")) {
                SearchSpawn.SpawnType = SPAWN_NPC;
            } else if (!strcmp(szArg,"pet")) {
                SearchSpawn.SpawnType = SPAWN_PET;
            } else if (!strcmp(szArg,"corpse")) {
                SearchSpawn.SpawnType = SPAWN_CORPSE;
            } else if (!strcmp(szArg,"invis")) {
                SearchSpawn.bTargInvis = TRUE;
            } else if (!strcmp(szArg,"next")) {
                SearchSpawn.bTargNext = TRUE;
            } else if (!strcmp(szArg,"trader")) {
                SearchSpawn.bTrader = TRUE;
            } else if (!strcmp(szArg,"group")) {
                SearchSpawn.bGroup = TRUE;
            } else if (!strcmp(szArg,"lfg")) {
                SearchSpawn.bLFG = TRUE;
            } else if (!strcmp(szArg,"prev")) {
                SearchSpawn.bTargPrev = TRUE;
            } else if (!strcmp(szArg,"guild")) {
                SearchSpawn.GuildID = pChar->GuildID;
            } else if (!strncmp(szArg,"guild:",6)) {
                SearchSpawn.GuildID = GetGuildIDByName(szArg+6);
            } else if (!strncmp(szArg,"range:",6)) {
                if (!strstr(szArg+6,":")) {
                    DebugSpewNoFile("PMP - Bad $searchspawn() '%s'",szArg);
                    return PMP_ERROR_BADPARM;
                }
                SearchSpawn.MinLevel = atoi(szArg+6);
                SearchSpawn.MaxLevel = atoi(strstr(szArg+6,":")+1);
            } else if (!strncmp(szArg,"loc:",4)) {
                if (!strstr(szArg+4,":")) {
                    DebugSpewNoFile("PMP - Bad $searchspawn() '%s'",szArg);
                    return PMP_ERROR_BADPARM;
                }
                SearchSpawn.bKnownLocation = TRUE;
                SearchSpawn.xLoc = (FLOAT)atof(szArg+4);
                SearchSpawn.yLoc = (FLOAT)atof(strstr(szArg+4,":")+1);
            } else if (!strncmp(szArg,"light:",6)) {
                SearchSpawn.bLight=TRUE;
                strcpy(SearchSpawn.szLight,szArg+6);
            } else if (!strncmp(szArg,"light",5)) {
                SearchSpawn.bLight=TRUE;
                SearchSpawn.szLight[0]=0;
            } else if (!strncmp(szArg,"id:",3)) {
                SearchSpawn.FromSpawnID = atoi(szArg+3);
            } else if (!strncmp(szArg,"radius:",7)) {
                SearchSpawn.FRadius = atof(szArg+7);
            } else if (!strncmp(szArg,"body:",5)) {
                strcpy(SearchSpawn.szBodyType,szArg+5);
            } else if (!strncmp(szArg,"class:",6)) {
                strcpy(SearchSpawn.szClass,szArg+6);
            } else if (!strncmp(szArg,"race:",5)) {
                strcpy(SearchSpawn.szRace,szArg+5);
            } else if (!strncmp(szArg,"alert:",6)) {
                SearchSpawn.AlertList = atoi(szArg+6);
                SearchSpawn.bAlert = TRUE;
            } else if (!strncmp(szArg,"noalert:",8)) {
                SearchSpawn.NoAlertList = atoi(szArg+8);
                SearchSpawn.bNoAlert = TRUE;
            } else if (!strncmp(szArg,"notnearalert:",13)) {
                SearchSpawn.NotNearAlertList = atoi(szArg+13);
                SearchSpawn.bNotNearAlert = TRUE;
            } else if (!strncmp(szArg,"nearalert:",10)) {
                SearchSpawn.NearAlertList = atoi(szArg+10);
                SearchSpawn.bNearAlert = TRUE;
            } else if (!strncmp(szArg,"zradius:",8)) {
                SearchSpawn.ZRadius = atof(szArg+8);
            } else if (!strncmp(szArg,"notid:",6)) {
                SearchSpawn.NotID = atoi(szArg+6);
            } else if (!strncmp(szArg,"nopcnear:",9)) {
                SearchSpawn.Radius = (FLOAT)atof(szArg+9);
            } else if (!strcmp(szArg,"nopcnear")) {
                SearchSpawn.Radius = 200.0f;
            } else {
                strcpy(SearchSpawn.szName,szArg);
            }

            argindex+=strlen(szFullArg);
            if (szVar[argindex]==',') argindex++;
        }

        if (!(pSpawn = SearchThroughSpawns(&SearchSpawn,pChar))) {
            strcat(szOutput,"0");
        } else {
            itoa(pSpawn->SpawnID,szTemp,10);
            strcat(szOutput,szTemp);
        }
    }
    return i;
}

DWORD parmSpawn(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    // $spawn(#,xxx)
    DWORD i=0;
    PSPAWNINFO pSpawn = NULL;

    if (!strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $spawn() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    } else {
        DWORD ID = atoi(szVar+6);
        pSpawn = (PSPAWNINFO)pSpawnList;
        while (pSpawn && pSpawn->SpawnID!=ID) pSpawn=pSpawn->pNext;

        // $spawn(#)
        if (!strstr(szVar,",")) {
            i+=strstr(szVar,")")-szVar;
            if (!pSpawn) {
                strcat(szOutput,"FALSE");
            } else {
                strcat(szOutput,"TRUE");
            }
        } else {
            PCHAR szRest = strstr(szVar,",")+1;
            // $spawn(#,distance,x)
            DebugSpewNoFile("$spawn(): id=%d (%p), rest=%s (len=%d)",ID,pSpawn,szRest,strlen(szRest));
            if (!strncmp("distance,x)",szRest,11)) {
                CHAR szTemp[MAX_STRING] = {0};
                i+=strstr(szVar,")")-szVar;

                if (!pSpawn) {
                    strcat(szOutput,"0");
                } else {
                    itoa((INT)fabs(pChar->X-pSpawn->X),szTemp,10);
                    strcat(szOutput,szTemp);
                }

            // $spawn(#,distance,y)
            } else if (!strncmp("distance,y)",szRest,11)) {
                CHAR szTemp[MAX_STRING] = {0};
                i+=strstr(szVar,")")-szVar;

                if (!pSpawn) {
                    strcat(szOutput,"0");
                } else {
                    itoa((INT)fabs(pChar->Y-pSpawn->Y),szTemp,10);
                    strcat(szOutput,szTemp);
                }

            // $spawn(#,distance,z)
            } else if (!strncmp("distance,z)",szRest,11)) {
                CHAR szTemp[MAX_STRING] = {0};
                i+=strstr(szVar,")")-szVar;

                if (!pSpawn) {
                    strcat(szOutput,"0");
                } else {
                    itoa((INT)fabs(pChar->Z-pSpawn->Z),szTemp,10);
                    strcat(szOutput,szTemp);
                }

            // $spawn(#,distance)
            } else if (!strncmp("distance)",szRest,9)) {
                CHAR szTemp[MAX_STRING] = {0};
                i+=strstr(szVar,")")-szVar;

                if (!pSpawn) {
                    strcat(szOutput,"0");
                } else {
                    itoa((INT)DistanceToSpawn(pChar,pSpawn),szTemp,10);
                    strcat(szOutput,szTemp);
                }

            // $spawn(#,distance,3d)
            } else if (!strncmp("distance,3d)",szRest,12)) {
                CHAR szTemp[MAX_STRING] = {0};
                i+=strstr(szVar,")")-szVar;

                if (!pSpawn) {
                    strcat(szOutput,"0");
                } else {
                    itoa((INT)DistanceToSpawn3D(pChar,pSpawn),szTemp,10);
                    strcat(szOutput,szTemp);
                }

            // $spawn(#,distance,predict)
            } else if (!strncmp("distance,predict)",szRest,17)) {
                CHAR szTemp[MAX_STRING] = {0};
                i+=strstr(szVar,")")-szVar;

                if (!pSpawn) {
                    strcat(szOutput,"0");
                } else {
                    itoa((INT)EstimatedDistanceToSpawn(pChar,pSpawn),szTemp,10);
                    strcat(szOutput,szTemp);
                }

            // $spawn(#,level)
            } else if (!strncmp("level)",szRest,6)) {
                CHAR szTemp[MAX_STRING] = {0};
                i+=strstr(szVar,")")-szVar;
                if (!pSpawn) {
                    strcat(szOutput,"0");
                } else {
                    itoa(pSpawn->Level,szTemp,10);
                    strcat(szOutput,szTemp);
                }

            // $spawn(#,id)
            } else if (!strncmp("id)",szRest,3)) {
                CHAR szTemp[MAX_STRING] = {0};
                i+=strstr(szVar,")")-szVar;
                if (!pSpawn) {
                    strcat(szOutput,"0");
                } else {
                    itoa(pSpawn->SpawnID,szTemp,10);
                    strcat(szOutput,szTemp);
                }

            // $spawn(#,next)
            } else if (!strncmp("next)",szRest,5)) {
                CHAR szTemp[MAX_STRING] = {0};
                i+=strstr(szVar,")")-szVar;
                if (!pSpawn) {
                    strcat(szOutput,"0");
                } else if (!pSpawn->pNext) {
                    strcat(szOutput,"0");
                } else {
                    itoa(pSpawn->pNext->SpawnID,szTemp,10);
                    strcat(szOutput,szTemp);
                }

            // $spawn(#,prev)
            } else if (!strncmp("prev)",szRest,5)) {
                CHAR szTemp[MAX_STRING] = {0};
                i+=strstr(szVar,")")-szVar;
                if (!pSpawn) {
                    strcat(szOutput,"0");
                } else if (!pSpawn->pPrev) {
                    strcat(szOutput,"0");
                } else {
                    itoa(pSpawn->pPrev->SpawnID,szTemp,10);
                    strcat(szOutput,szTemp);
                }

            // $spawn(#,x)
            } else if (!strncmp("x)",szRest,2)) {
                CHAR szTemp[MAX_STRING] = {0};
                i+=strstr(szVar,")")-szVar;
                if (!pSpawn) {
                    strcat(szOutput,"0");
                } else {
                    sprintf(szTemp,"%1.2f",pSpawn->X);
                    strcat(szOutput,szTemp);
                }

            // $spawn(#,y)
            } else if (!strncmp("y)",szRest,2)) {
                CHAR szTemp[MAX_STRING] = {0};
                i+=strstr(szVar,")")-szVar;
                if (!pSpawn) {
                    strcat(szOutput,"0");
                } else {
                    sprintf(szTemp,"%1.2f",pSpawn->Y);
                    strcat(szOutput,szTemp);
                }

            // $spawn(#,z)
            } else if (!strncmp("z)",szRest,2)) {
                CHAR szTemp[MAX_STRING] = {0};
                i+=strstr(szVar,")")-szVar;
                if (!pSpawn) {
                    strcat(szOutput,"0");
                } else {
                    sprintf(szTemp,"%1.2f",pSpawn->Z);
                    strcat(szOutput,szTemp);
                }

            // $spawn(#,heading)
            } else if (!strncmp("heading)",szRest,8)) {
                CHAR szTemp[MAX_STRING] = {0};
                i+=strstr(szVar,")")-szVar;
                if (!pSpawn) {
                    strcat(szOutput,"0");
                } else {
                    sprintf(szTemp,"%1.2f",pSpawn->Heading*0.703125f);
                    strcat(szOutput,szTemp);
                }

            // $spawn(#,speed)
            } else if (!strncmp("speed)",szRest,6)) {
                CHAR szTemp[MAX_STRING] = {0};
                i+=strstr(szVar,")")-szVar;
                if (!pSpawn) {
                    strcat(szOutput,"0");
                } else {
                    sprintf(szTemp,"%1.2f",FindSpeed(pSpawn));
                    strcat(szOutput,szTemp);
                }

            // $spawn(#,headingto)
            } else if (!strncmp("headingto)",szRest,10)) {
                CHAR szTemp[MAX_STRING] = {0};
                i+=strstr(szVar,")")-szVar;
                if (!pSpawn) {
                    strcat(szOutput,"0");
                } else {
                    DOUBLE HeadingTo = atan2f(pChar->Y - pSpawn->Y, pSpawn->X - pChar->X) * 180.0f / PI + 90.0f;
                    if (HeadingTo<0.0f) HeadingTo += 360.0f;
                    if (HeadingTo>=360.0f) HeadingTo -= 360.0f;
                    sprintf(szTemp,"%1.2f",HeadingTo);
                    strcat(szOutput,szTemp);
                }

            // $spawn(light)
            } else if (!strncmp("light)",szRest,6)) {
                i+=strstr(szVar,")")-szVar;
                if (!pSpawn) {
                    strcat(szOutput,"NONE");
                } else {
                    PCHAR szLight = GetLightForSpawn(pSpawn);
                    strcat(szOutput,szLight);
                }

            // $spawn(body)
            } else if (!strncmp("body)",szRest,5)) {
                i+=strstr(szVar,")")-szVar;
                if (!pSpawn) {
                    strcat(szOutput,"NONE");
                } else {
                    strcat(szOutput,pEverQuest->GetBodyTypeDesc(pSpawn->BodyType));
                }

            // $spawn(state)
            } else if (!strncmp("state)",szRest,6)) {
                i+=strstr(szVar,")")-szVar;
                if (!pSpawn) {
                    strcat(szOutput,"UNKNOWN");
                } else {
                    switch (pSpawn->StandState) {
                        case STANDSTATE_STAND:
                            strcat(szOutput,"STAND");
                            break;
                        case STANDSTATE_SIT:
                            strcat(szOutput,"SIT");
                            break;
                        case STANDSTATE_DUCK:
                            strcat(szOutput,"DUCK");
                            break;
                        case STANDSTATE_BIND:
                            strcat(szOutput,"BIND");
                            break;
                        case STANDSTATE_FEIGN:
                            strcat(szOutput,"FEIGN");
                            break;
                        case STANDSTATE_DEAD:
                            strcat(szOutput,"DEAD");
                            break;
                        default:
                            strcat(szOutput,"UNKNOWN");
                            break;
                    }
                }

            // $spawn(#,held,right)
            } else if (!strncmp("held,right)",szRest,11)) {
                i+=strstr(szVar,")")-szVar;
                PCHAR Model = GetModel(pSpawn,MODEL_HELD_R);
                if (Model) {
                    strcat(szOutput,Model);
                } else {
                    strcat(szOutput,"NULL");
                }

            // $spawn(#,held,left)
            } else if (!strncmp("held,left)",szRest,10)) {
                i+=strstr(szVar,")")-szVar;
                PCHAR Model = GetModel(pSpawn,MODEL_HELD_L);
                if (Model) {
                    strcat(szOutput,Model);
                } else {
                    strcat(szOutput,"NULL");
                }

            // $spawn(#,held,shield)
            } else if (!strncmp("held,shield)",szRest,12)) {
                i+=strstr(szVar,")")-szVar;
                PCHAR Model = GetModel(pSpawn,MODEL_SHIELD);
                if (Model) {
                    strcat(szOutput,Model);
                } else {
                    strcat(szOutput,"NULL");
                }

            // $spawn(#,hp,cur)
            } else if (!strncmp("hp,cur)",szRest,7)) {
                CHAR szTemp[MAX_STRING] = {0};
                i+=strstr(szVar,")")-szVar;
                if (!pSpawn) {
                    strcat(szOutput,"0");
                } else {
                    itoa((INT)(pSpawn->HPCurrent),szTemp,10);
                    strcat(szOutput,szTemp);
                }

            // $spawn(#,hp,max)
            } else if (!strncmp("hp,max)",szRest,7)) {
                CHAR szTemp[MAX_STRING] = {0};
                i+=strstr(szVar,")")-szVar;
                if (!pSpawn) {
                    strcat(szOutput,"0");
                } else {
                    itoa((INT)(pSpawn->HPMax),szTemp,10);
                    strcat(szOutput,szTemp);
                }

            // $spawn(#,hp,pct)
            } else if (!strncmp("hp,pct)",szRest,7)) {
                CHAR szTemp[MAX_STRING] = {0};
                i+=strstr(szVar,")")-szVar;
                if (!pSpawn) {
                    strcat(szOutput,"0");
                } else {
                    itoa((INT)(pSpawn->HPCurrent*100/pSpawn->HPMax),szTemp,10);
                    strcat(szOutput,szTemp);
                }

            // return NULL for all following $spawn(#,xxx) commands if no spawn
            } else if (!pSpawn) {
                while ((szVar[i] != ')') && (szVar[i] != 0)) i++;
                strcat(szOutput,"NULL");

            // $spawn(#,deity)
            } else if (!strncmp("deity)",szRest,6)) {
                i+=strstr(szVar,")")-szVar;
                CHAR szTemp[MAX_STRING] = {0};
                strcpy(szTemp,pEverQuest->GetDeityDesc(pSpawn->Deity));
                strcat(szOutput,szTemp);

            // $spawn(#,deity,team)
            } else if (!strncmp("deity,team)",szRest,11)) {
                i+=strstr(szVar,")")-szVar;
                CHAR szTemp[MAX_STRING] = {0};
                strcpy(szTemp,szDeityTeam[GetDeityTeamByID(pSpawn->Deity)]);
                strcat(szOutput,szTemp);

            // $spawn(#,type)
            } else if (!strncmp("type)",szRest,5)) {
                i+=strstr(szVar,")")-szVar;
                strcat(szOutput,szSpawnType[pSpawn->Type]);

            // $spawn(#,name)
            } else if (!strncmp("name)",szRest,5)) {
                i+=strstr(szVar,")")-szVar;
                strcat(szOutput,pSpawn->Name);

            // $spawn(#,name,clean)
            } else if (!strncmp("name,clean)",szRest,11)) {
                CHAR szName[MAX_STRING] = {0};
                i+=strstr(szVar,")")-szVar;
                strcpy(szName,pSpawn->Name);
                strcat(szOutput,CleanupName(szName,FALSE));

            // $spawn(#,surname)
            } else if (!strncmp("surname)",szRest,8)) {
                i+=strstr(szVar,")")-szVar;
                strcat(szOutput,pSpawn->Lastname);

            // $spawn(#,guild)
            } else if (!strncmp("guild)",szRest,6)) {
                i+=strstr(szVar,")")-szVar;
                if (pSpawn->GuildID < 0xFFFE && EQADDR_GUILDLIST) {
                    strcat(szOutput,GetGuildByID(pSpawn->GuildID));
                } else {
                    strcat(szOutput,"NULL");
                }

            // $spawn(#,guild,status)
			} else if (!strncmp("guild,status)",szRest,13)) {
				i+=strstr(szVar,")")-szVar;
                if (pSpawn->GuildID < 0xFFFE) {
                    strcat(szOutput,szGuildStatus[pSpawn->GuildStatus]);
                } else {
                    strcat(szOutput,"NULL");
                }

            // $spawn(#,surname)
            } else if (!strncmp("surname)",szRest,8)) {
                i+=strstr(szVar,")")-szVar;
                strcat(szOutput,pSpawn->Lastname);

            // $spawn(#,master)
            } else if (!strncmp("master)",szRest,7)) {
                i+=strstr(szVar,")")-szVar;
                CHAR szMaster[MAX_STRING] = {0};
                ltoa(pSpawn->MasterID,szMaster,10);
                strcat(szOutput,szMaster);

            // $spawn(#,pet)
            } else if (!strncmp("pet)",szRest,4)) {
                PSPAWNINFO pPet = GetPet(pSpawn->SpawnID);
                i+=strstr(szVar,")")-szVar;
                if (pPet) {
                    CHAR szPet[MAX_STRING] = {0};
                    ltoa(pPet->SpawnID,szPet,10);
                    strcat(szOutput,szPet);
                } else {
                    strcat(szOutput,"0");
                }

            // $spawn(#,class)
            } else if (!strncmp("class)",szRest,6)) {
                i+=strstr(szVar,")")-szVar;
                CHAR szTemp[MAX_STRING] = {0};
                strcpy(szTemp,pEverQuest->GetClassDesc(pSpawn->Class));
                strcat(szOutput,szTemp);

            // $spawn(#,race)
            } else if (!strncmp("race)",szRest,5)) {
                i+=strstr(szVar,")")-szVar;
                CHAR szTemp[MAX_STRING] = {0};
                strcpy(szTemp,pEverQuest->GetRaceDesc(pSpawn->Race));
                strcat(szOutput,szTemp);

            // $spawn(#,gender)
            } else if (!strncmp("gender)",szRest,7)) {
                i+=strstr(szVar,")")-szVar;
                CHAR szTemp[MAX_STRING] = {0};
                strcpy(szTemp,szGender[pSpawn->Gender]);
                strcat(szOutput,szTemp);

            // $spawn(#,gm)
            } else if (!strncmp("gm)",szRest,3)) {
                i+=strstr(szVar,")")-szVar;
                if (pSpawn->GM) {
                    strcat(szOutput,"TRUE");
                } else {
                    strcat(szOutput,"FALSE");
                }

            // $spawn(#,unknown)
            } else {
                DebugSpewNoFile("PMP - Bad $spawn() '%s'",szVar);
                return PMP_ERROR_BADPARM;
            }
        }
    }
    return i;
}

DWORD parmHeading(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $heading(y,x)
    CHAR szTemp[MAX_STRING] = {0};
    if ((!strstr(szVar,",")) || (!strstr(szVar,")")) ) {
        DebugSpewNoFile("PMP - Bad $heading() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    } else {
        i += (strstr(szVar,")")-szVar);
        float Y = (FLOAT)atof(szVar+8);
        float X = (FLOAT)atof(strstr(szVar,",")+1);
        DOUBLE HeadingTo = atan2f(pChar->Y - Y, X - pChar->X) * 180.0f / PI + 90.0f;
        if (HeadingTo<0.0f) HeadingTo += 360.0f;
        if (HeadingTo>=360.0f) HeadingTo -= 360.0f;
        sprintf(szTemp,"%1.2f",HeadingTo);
        strcat(szOutput,szTemp);
    }
    return i;
}

DWORD parmID(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $id(xxx)
    if (!strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $id() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    } else {
        CHAR SpawnName[MAX_STRING] = {0};
        DWORD Num=atoi(szVar+3);
        if ((Num==0) && szVar[3]!='0') {
            strncpy(SpawnName,szVar+3,strstr(szVar+3,")")-szVar-3);
            Num=-1;
        }

        PSPAWNINFO pSpawn = NULL;
        if (ppSpawnList && pSpawnList) {
            pSpawn = (PSPAWNINFO)pSpawnList;
        }
        while (szVar[i]!=')') i++;
        if (Num!=-1) {
            while ((Num>0) && (pSpawn)) {
                Num--;
                pSpawn=pSpawn->pNext;
            }
        } else {
            while ((Num==-1) && (pSpawn)) {
                if (!stricmp(SpawnName,pSpawn->Name)) {
                    Num=0;
                } else {
                    pSpawn=pSpawn->pNext;
                }
            }
        }
        if (!pSpawn) {
            strcat(szOutput,"0");
        } else {
            CHAR szID[MAX_STRING] = {0};
            itoa(pSpawn->SpawnID,szID,10);
            strcat(szOutput,szID);
        }
    }
    return i;
}

DWORD parmMouse(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $mouse(xxx)
    PMOUSEINFO pMouse = (PMOUSEINFO)EQADDR_MOUSE;
    if (!pMouse) return PMP_ERROR_BADPARM;
    CHAR szTemp[MAX_STRING] = {0};

    // $mouse(x)
    if (!strncmp("mouse(x)",szVar,8)) {
        i+=7;
        itoa(pMouse->X,szTemp,10);
        strcat(szOutput,szTemp);

    // $mouse(y)
    } else if (!strncmp("mouse(y)",szVar,8)) {
        i+=7;
        itoa(pMouse->Y,szTemp,10);
        strcat(szOutput,szTemp);

    // $mouse(unknown)
    } else {
        DebugSpewNoFile("PMP - Bad $mouse() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    }
    return i;
}

DWORD parmChar(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    PCHARINFO pCharInfo = NULL;
    if (NULL == (pCharInfo = GetCharInfo())) return PMP_ERROR_BADPARM;
    // $char(xxx)

    // $char(level)
    if (!strncmp("char(level)",szVar,11)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=10;
        itoa(GetCharInfo()->pSpawn->Level,szTemp,10);
        strcat(szOutput,szTemp);

    // $char(id)
    } else if (!strncmp("char(id)",szVar,8)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=7;
        itoa(GetCharInfo()->pSpawn->SpawnID,szTemp,10);
        strcat(szOutput,szTemp);

    // $char(DAR)
    } else if (!strncmp("char(dar)",szVar,9)) {
        CHAR szTemp[MAX_STRING] = {0};
        DWORD k=0;
        i+=8;
        for ( int l=0; l <= 14; l++ )
            k += pCharInfo->Buff[l].DamageAbsorbRemaining;
        itoa(k,szTemp,10);
        strcat(szOutput,szTemp);

    // $char(x)
    } else if (!strncmp("char(x)",szVar,7)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=6;
        sprintf(szTemp,"%1.2f",pChar->X);
        strcat(szOutput,szTemp);

    // $char(y)
    } else if (!strncmp("char(y)",szVar,7)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=6;
        sprintf(szTemp,"%1.2f",pChar->Y);
        strcat(szOutput,szTemp);

    // $char(z)
    } else if (!strncmp("char(z)",szVar,7)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=6;
        sprintf(szTemp,"%1.2f",pChar->Z);
        strcat(szOutput,szTemp);

   // $char(look)
   } else if (!strncmp("char(look)",szVar,10)) {
      CHAR szTemp[MAX_STRING] = {0};
      i+=9;
      sprintf(szTemp,"%1.2f",pChar->CameraAngle);
      strcat(szOutput,szTemp);

    // $char(heading)
    } else if (!strncmp("char(heading)",szVar,13)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=12;
        sprintf(szTemp,"%1.2f",pChar->Heading*0.703125f);
        strcat(szOutput,szTemp);

    // $char(speed)
    } else if (!strncmp("char(speed)",szVar,11)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=10;
        sprintf(szTemp,"%1.2f",FindSpeed(pChar) );
       strcat(szOutput,szTemp);

    // $char(ismoving)
    } else if (!strncmp("char(ismoving)",szVar,14)) {
        i+=13;
        if (gbMoving && (pChar->SpeedRun==0.0f)) {
            strcat(szOutput,"TRUE");
    } else if (FindSpeed(pChar) > 0.0f ) {
        strcat(szOutput,"TRUE");
    } else {
        strcat(szOutput,"FALSE");
    }

    // $char(light)
    } else if (!strncmp("char(light)",szVar,11)) {
        i+=10;
        PCHAR szLight = GetLightForSpawn(pChar);
        strcat(szOutput,szLight);

    // $char(state)
    } else if (!strncmp("char(state)",szVar,11)) {
        i+=10;
        if (pCharInfo->Stunned==1) {
            strcat(szOutput,"STUN");
        } else {
            switch (GetCharInfo()->pSpawn->StandState) {
                case STANDSTATE_STAND:
                    strcat(szOutput,"STAND");
                    break;
                case STANDSTATE_SIT:
                    strcat(szOutput,"SIT");
                    break;
                case STANDSTATE_DUCK:
                    strcat(szOutput,"DUCK");
                    break;
                case STANDSTATE_BIND:
                    strcat(szOutput,"BIND");
                    break;
                case STANDSTATE_FEIGN:
                    strcat(szOutput,"FEIGN");
                    break;
                case STANDSTATE_DEAD:
                    strcat(szOutput,"DEAD");
                    break;
                default:
                    strcat(szOutput,"UNKNOWN");
                    break;
            }
        }

    // $char(held,right)
    } else if (!strncmp("char(held,right)",szVar,16)) {
        i+=15;
        PCHAR Model = GetModel(pChar,MODEL_HELD_R);
        if (Model) {
            strcat(szOutput,Model);
        } else {
            strcat(szOutput,"NULL");
        }

    // $char(held,left)
    } else if (!strncmp("char(held,left)",szVar,15)) {
        i+=14;
        PCHAR Model = GetModel(pChar,MODEL_HELD_L);
        if (Model) {
            strcat(szOutput,Model);
        } else {
            strcat(szOutput,"NULL");
        }

    // $char(held,shield)
    } else if (!strncmp("char(held,shield)",szVar,17)) {
        i+=16;
        PCHAR Model = GetModel(pChar,MODEL_SHIELD);
        if (Model) {
            strcat(szOutput,Model);
        } else {
            strcat(szOutput,"NULL");
        }

    // $char(type)
    } else if (!strncmp("char(type)",szVar,10)) {
        i+=9;
        CHAR szType[MAX_STRING] = {0};
        strcpy(szType, "PC");
        strcat(szOutput,szType);

    // $char(exp)
    } else if (!strncmp("char(exp)",szVar,9)) {
        i+=8;
        CHAR szExp[MAX_STRING] = {0};
        sprintf(szExp,"%1.2f",(DOUBLE)pCharInfo->Exp/3.30f);
        strcat(szOutput,szExp);

	// $char(exp,val)  -- i.e. out of 330
    } else if (!strncmp("char(exp,val)",szVar,13)) {
        i+=12;
        CHAR szExp[MAX_STRING] = {0};
		itoa(pCharInfo->Exp,szExp,10);
        strcat(szOutput,szExp);

    // $char(aa,exp)
    } else if (!strncmp("char(aa,exp)",szVar,12)) {
        i+=11;
        CHAR szExp[MAX_STRING] = {0};
        sprintf(szExp,"%1.2f",(DOUBLE)pCharInfo->AAExp/3.30f);
        strcat(szOutput,szExp);

	// $char(aa,exp,val)  -- i.e. out of 330
    } else if (!strncmp("char(aa,exp,val)",szVar,16)) {
        i+=15;
        CHAR szExp[MAX_STRING] = {0};
		itoa(pCharInfo->AAExp,szExp,10);
        strcat(szOutput,szExp);

	// $char(aa,points)
    } else if (!strncmp("char(aa,points)",szVar,15)) {
        i+=14;
        CHAR szPoints[MAX_STRING] = {0};
        itoa(pCharInfo->AAPoints,szPoints,10);
        strcat(szOutput,szPoints);

    // $char(aa,rank)
    } else if (!strncmp("char(aa,rank)",szVar,13)) {
        i+=12;
        CHAR szRank[MAX_STRING] = {0};
        itoa(GetCharInfo()->pSpawn->AARank,szRank,10);
        strcat(szOutput,szRank);

    // $char(hp,max)
    } else if (!strncmp("char(hp,max)",szVar,12)) {
        i+=11;
        CHAR szTemp[MAX_STRING] = {0};
        itoa(GetCharInfo()->pSpawn->HPMax,szTemp,10);
        strcat(szOutput,szTemp);

    // $char(hp,cur)
    } else if (!strncmp("char(hp,cur)",szVar,12)) {
        i+=11;
        CHAR szTemp[MAX_STRING] = {0};
        itoa(GetCharInfo()->pSpawn->HPCurrent,szTemp,10);
        strcat(szOutput,szTemp);

    // $char(hp,regen)     note: heals count in this "regen"
    } else if (!strncmp("char(hp,regen)",szVar,14)) {
        i+=13;
        CHAR szTemp[MAX_STRING] = {0};
        itoa(HealthGained,szTemp,10);
        strcat(szOutput,szTemp);

	// $char(hp,pct)
    } else if (!strncmp("char(hp,pct)",szVar,12)) {
        i+=11;
        CHAR szTemp[MAX_STRING] = {0};
        itoa((INT)(GetCharInfo()->pSpawn->HPCurrent*100/GetCharInfo()->pSpawn->HPMax),szTemp,10);
        strcat(szOutput,szTemp);

    // $char(mana,max)
    } else if (!strncmp("char(mana,max)",szVar,14)) {
        i+=13;
        CHAR szTemp[MAX_STRING] = {0};
        itoa(GetMaxMana(),szTemp,10);
        strcat(szOutput,szTemp);

    // $char(mana,cur)
    } else if (!strncmp("char(mana,cur)",szVar,14)) {
        i+=13;
        CHAR szTemp[MAX_STRING] = {0};
        itoa(pCharInfo->Mana,szTemp,10);
        strcat(szOutput,szTemp);

    // $char(mana,regen)
    } else if (!strncmp("char(mana,regen)",szVar,16)) {
        i+=15;
        CHAR szTemp[MAX_STRING] = {0};
        itoa(ManaGained,szTemp,10);
        strcat(szOutput,szTemp);

    // $char(mana,pct)
    } else if (!strncmp("char(mana,pct)",szVar,14)) {
        i+=13;
        CHAR szTemp[MAX_STRING] = {0};
        DWORD MaxMana = GetMaxMana();
        if (MaxMana==0) {
            strcpy(szTemp,"0");
        } else {
            itoa((INT)(100*(FLOAT)pCharInfo->Mana/(FLOAT)MaxMana),szTemp,10);
        }
        strcat(szOutput,szTemp);

    // $char(stamina,max) 
    } else if (!strncmp("char(stamina,max)",szVar,17)) { 
        i+=16; 
        CHAR szTemp[MAX_STRING] = {0}; 
        strcpy(szTemp,"100"); // Fixed cap 
        strcat(szOutput,szTemp); 

    // $char(stamina,cur) 
    } else if (!strncmp("char(stamina,cur)",szVar,17)) { 
        i+=16; 
        CHAR szTemp[MAX_STRING] = {0}; 
        itoa(100-GetCharInfo()->Fatigue,szTemp,10); 
        strcat(szOutput,szTemp); 

    // $char(stamina,pct) 
    } else if (!strncmp("char(stamina,pct)",szVar,17)) { 
        i+=16; 
        CHAR szTemp[MAX_STRING] = {0}; 
        itoa(100-GetCharInfo()->Fatigue,szTemp,10); 
        strcat(szOutput,szTemp);

    // $char(deity)
    } else if (!strncmp("char(deity)",szVar,11)) {
        i+=10;
        CHAR szTemp[MAX_STRING] = {0};
        strcpy(szTemp,pEverQuest->GetDeityDesc(GetCharInfo()->pSpawn->Deity));
        strcat(szOutput,szTemp);

    // $char(deity,team)
    } else if (!strncmp("char(deity,team)",szVar,16)) {
        i+=15;
        CHAR szTemp[MAX_STRING] = {0};
        strcpy(szTemp,szDeityTeam[GetDeityTeamByID(GetCharInfo()->pSpawn->Deity)]);
        strcat(szOutput,szTemp);

    // $char(casting)
    } else if (!strncmp("char(casting)",szVar,13)) {
        i+=12;
        if (!pCastingWnd) return PMP_ERROR_BADPARM;
        PCSIDLWND pCastingWindow = NULL;
        pCastingWindow = (PCSIDLWND)pCastingWnd;
        if (pCastingWindow->Show==1) {
            strcat(szOutput,"TRUE");
        } else {
            strcat(szOutput,"FALSE");
        }
    // $char(gem,xxx)
    } else if (!strncmp("char(gem,",szVar,9)) {
        if (!strstr(szVar,")")) {
            DebugSpewNoFile("PMP - Bad $char() '%s'",szVar);
            return PMP_ERROR_BADPARM;
        } else {
            PEQCASTSPELLWINDOW pCastSpellWindow = NULL;
            PEQCASTSPELLGEM pSpellSlot = NULL;
            pCastSpellWindow = (PEQCASTSPELLWINDOW)pCastSpellWnd;
            i += (strstr(szVar,")")-szVar);
            CHAR szTemp[MAX_STRING] = "0";
            PCHAR szArg = szVar+9;
            WORD Gem = atoi(szArg);
            if (Gem==0 && szArg[0]!='0') {
                if (szArg[0]=='"') szArg++;
                DWORD sp;
                for (sp=0;sp<8;sp++) {
                    if (pCharInfo->MemorizedSpells[sp] != 0xFFFFFFFF) {
                        PCHAR SpellName = GetSpellByID(pCharInfo->MemorizedSpells[sp]);
                        if (!strnicmp(szArg,SpellName,strlen(SpellName))) {
                            if (!pCastSpellWnd) {
                                itoa(sp+1,szTemp,10);
                            } else {
                                pSpellSlot = (PEQCASTSPELLGEM)pCastSpellWindow->SpellSlots[sp];
                                if (pSpellSlot->spellstate != 0) {
                                    strcpy(szTemp,"-2");
                                } else {
                                    itoa(sp+1,szTemp,10);
                                }
                            }
                        }
                    }
                }
            } else {
                if (Gem>0 && Gem<9) {
                    if (pCharInfo->MemorizedSpells[Gem-1] != 0xFFFFFFFF) {
                        strcpy(szTemp,GetSpellByID(pCharInfo->MemorizedSpells[Gem-1]));
                    } else {
                        strcpy(szTemp,"NULL");
                    }
                } else {
                    strcpy(szTemp,"NULL");
                }
            }
            strcat(szOutput,szTemp);
        }
    // $char(hotbutton,x) example: /echo $char(hotbutton,1)
    } else if (!strncmp("char(hotbutton,",szVar,15)) {
        if (!strstr(szVar,")")) {
            DebugSpewNoFile("PMP - Bad $char() '%s'",szVar);
            return 10000;
        } else {
            CHAR szTemp[MAX_STRING] = {0};
            if (ppHotButtonWnd) {
                PEQHOTBUTTONWINDOW pHotButtonWindow = NULL;
                PEQHOTBUTTONWINDOW pHotButton = NULL;
                pHotButtonWindow = (PEQHOTBUTTONWINDOW)pHotButtonWnd;
                i += (strstr(szVar,")")-szVar);

                PCHAR szArg = szVar+15;
                DWORD HB = atoi(szArg);
                if (HB>0 && HB<11) {
                    HB--;
                    if (pHotButtonWindow->HotButtons[HB]){
                        pHotButton = NULL;
                        pHotButton = (PEQHOTBUTTONWINDOW)pHotButtonWindow->HotButtons[HB];
                        DebugSpewNoFile("hotbutton check for HB %x and arg passed was %s",HB,szArg);
                        if (pHotButton->Wnd.Checked != 0) {
                            strcpy(szTemp,"FALSE");
                        } else {
                            strcpy(szTemp,"TRUE");
                        }
                    } else {
                        strcpy(szTemp,"NULL");
                    }
                }
            } else {
                strcpy(szTemp,"offset error");
            }
            strcat(szOutput,szTemp);
        }

    // $char(buff,xxx)
    } else if (!strncmp("char(buff,",szVar,10)) {
        if (!strstr(szVar,")")) {
            DebugSpewNoFile("PMP - Bad $char() '%s'",szVar);
            return PMP_ERROR_BADPARM;
        } else {
            i += (strstr(szVar,")")-szVar);
            CHAR szTemp[MAX_STRING] = "0";
            PCHAR szArg = szVar+10;
            WORD Buff = atoi(szArg);
            if (Buff==0 && szArg[0]!='0') {
                if (szArg[0]=='"') szArg++;
                DWORD bf;
                for (bf=0;bf<15;bf++) {
                    if (pCharInfo->Buff[bf].SpellID != 0x0000FFFF) {
                        PCHAR SpellName = GetSpellByID(pCharInfo->Buff[bf].SpellID);
                        if (!strnicmp(szArg,SpellName,strlen(SpellName))) {
                            itoa(bf+1,szTemp,10);
                        }
                    }
                }
            } else {
                if (Buff>0 && Buff<16) {
                    if (pCharInfo->Buff[Buff-1].SpellID != 0x0000FFFF) {
                        itoa(Buff,szTemp,10);
                        szArg += strlen(szTemp);
                        if (!strncmp(szArg,",duration)",10)) {
                            itoa(pCharInfo->Buff[Buff-1].Duration,szTemp,10);
						} else if (!strncmp(szArg,",durationsecs)",14)) {
							int Secs=(pCharInfo->Buff[Buff-1].Duration+1)*6;
							int Mins=Secs/60;
							Secs=Secs%60;
							sprintf(szTemp,"%d:%02d",Mins,Secs);
						} else if (!strncmp(szArg,",mod)",5)) {
							if (pCharInfo->Buff[Buff-1].Modifier && pCharInfo->Buff[Buff-1].Modifier!=10)
								sprintf(szTemp,"%.1f",(float)((float)pCharInfo->Buff[Buff-1].Modifier/(float)10));
							else
								strcpy(szTemp,"NULL");
                        } else if (!strncmp(szArg,",level)",7)) {
                            itoa(pCharInfo->Buff[Buff-1].Level,szTemp,10);
                        } else if (!strncmp(szArg,",id)",4)) {
                            itoa(pCharInfo->Buff[Buff-1].SpellID,szTemp,10);
                        } else if (!strncmp(szArg,",dar)",5)) {
                            if (pCharInfo->Buff[Buff-1].DamageAbsorbRemaining > 0 )
                                itoa(pCharInfo->Buff[Buff-1].DamageAbsorbRemaining,szTemp,10);
                            else
                                strcpy(szTemp,"0");
                        } else {
                            strcpy(szTemp,GetSpellByID(pCharInfo->Buff[Buff-1].SpellID));
                        }
                    } else {
                        strcpy(szTemp,"NULL");
                    }
                } else {
                    strcpy(szTemp,"NULL");
                }
            }
            strcat(szOutput,szTemp);
        }

    // $char(song,xxx)
    } else if (!strncmp("char(song,",szVar,10)) {
        if (!strstr(szVar,")")) {
            DebugSpewNoFile("PMP - Bad $char() '%s'",szVar);
            return PMP_ERROR_BADPARM;
        } else {
            i += (strstr(szVar,")")-szVar);
            CHAR szTemp[MAX_STRING] = "0";
            PCHAR szArg = szVar+10;
            WORD Buff = atoi(szArg);
            if (Buff==0 && szArg[0]!='0') {
                if (szArg[0]=='"') szArg++;
                DWORD bf;
                for (bf=0;bf<6;bf++) {
                    if ((pCharInfo->ShortBuff[bf].SpellID != 0x0000FFFF) && (pCharInfo->ShortBuff[bf].SpellID != 0)) {
                        PCHAR SpellName = GetSpellByID(pCharInfo->ShortBuff[bf].SpellID);
                        if (!strnicmp(szArg,SpellName,strlen(SpellName))) {
                            itoa(bf+1,szTemp,10);
                        }
                    }
                }
            } else {
                if (Buff>0 && Buff<7) {
                    if ((pCharInfo->ShortBuff[Buff-1].SpellID != 0x0000FFFF) && (pCharInfo->ShortBuff[Buff-1].SpellID != 0)) {
                        itoa(Buff,szTemp,10);
                        szArg += strlen(szTemp);
                        if (!strncmp(szArg,",duration)",10)) {
                            itoa(pCharInfo->ShortBuff[Buff-1].Duration,szTemp,10);
						} else if (!strncmp(szArg,",durationsecs)",14)) {
							int Secs=(pCharInfo->ShortBuff[Buff-1].Duration+1)*6;
							int Mins=Secs/60;
							Secs=Secs%60;
							sprintf(szTemp,"%d:%02d",Mins,Secs);
						} else if (!strncmp(szArg,",mod)",5)) {
							if (pCharInfo->ShortBuff[Buff-1].Modifier && pCharInfo->ShortBuff[Buff-1].Modifier!=10)
								sprintf(szTemp,"%.1f",(float)((float)pCharInfo->ShortBuff[Buff-1].Modifier/(float)10));
							else
								strcpy(szTemp,"NULL");
                        } else if (!strncmp(szArg,",level)",7)) {
                            itoa(pCharInfo->ShortBuff[Buff-1].Level,szTemp,10);
                        } else if (!strncmp(szArg,",id)",4)) {
                            itoa(pCharInfo->ShortBuff[Buff-1].SpellID,szTemp,10);
                        } else {
                            strcpy(szTemp,GetSpellByID(pCharInfo->ShortBuff[Buff-1].SpellID));
                        }
                    } else {
                        strcpy(szTemp,"NULL");
                    }
                } else {
                    strcpy(szTemp,"NULL");
                }
            }
            strcat(szOutput,szTemp);
        }

    // $char(book,xxx)
    } else if (!strncmp("char(book,",szVar,10)) {
        if (!strstr(szVar,")")) {
            DebugSpewNoFile("PMP - Bad $char() '%s'",szVar);
            return PMP_ERROR_BADPARM;
        } else {
            i += (strstr(szVar,")")-szVar);
            CHAR szTemp[MAX_STRING] = "NULL";
            PCHAR szArg = szVar+10;
            WORD Gem = atoi(szArg);
            if (Gem==0 && szArg[0]!='0') {
                if (szArg[0]=='"') szArg++;
                DWORD sp;
                for (sp=0;sp<250;sp++) {
                    if (pCharInfo->SpellBook[sp] != 0xFFFFFFFF) {
                        PCHAR SpellName = GetSpellByID(pCharInfo->SpellBook[sp]);
                        if (!strnicmp(szArg,SpellName,strlen(SpellName))) {
                            itoa(sp+1,szTemp,10);
                        }
                    }
                }
            } else {
                if (Gem>0 && Gem<251) {
                    if (pCharInfo->SpellBook[Gem-1] != 0xFFFFFFFF) {
                        strcpy(szTemp,GetSpellByID(pCharInfo->SpellBook[Gem-1]));
                    } else {
                        strcpy(szTemp,"NULL");
                    }
                } else {
                    strcpy(szTemp,"NULL");
                }
            }
            strcat(szOutput,szTemp);
        }

    // $char(skill,xxx)
    } else if (!strncmp("char(skill,",szVar,11)) {
        if (!strstr(szVar,")")) {
            DebugSpewNoFile("PMP - Bad $char() '%s'",szVar);
            return PMP_ERROR_BADPARM;
        } else {
            i += (strstr(szVar,")")-szVar);
            PCHAR szArg = szVar+11;
            if (szArg[0]=='"') szArg++;
            CHAR szTemp[MAX_STRING] = "0";
            DWORD sk;
            for (sk=0;szSkills[sk];sk++) {
                if (!strnicmp(szArg,szSkills[sk],strlen(szSkills[sk]))) itoa(pCharInfo->Skill[sk],szTemp,10);
            }
            strcat(szOutput,szTemp);
        }

    // $char(ability,xxx)
    } else if (!strncmp("char(ability,",szVar,13)) {
        if (!strstr(szVar,")")) {
            return PMP_ERROR_BADPARM;
        } else {
            i += (strstr(szVar,")")-szVar);
            PCHAR szArg = szVar+13;
            WORD Skill = atoi(szArg);
            CHAR szTemp[MAX_STRING] = "0";
            if (Skill==0 && szArg[0]!='0') {
                if (szArg[0]=='"') szArg++;
                DWORD sk;
                for (sk=0;szSkills[sk];sk++) {
                    if (!strnicmp(szArg,szSkills[sk],strlen(szSkills[sk]))) {
                        if (pCharInfo->Skill[sk]>252) {
                            strcpy(szTemp,"-1");
                        } else {
                            DWORD DoIndex;
                            for (DoIndex=0;DoIndex<10;DoIndex++) {
                                if (EQADDR_DOABILITYLIST[DoIndex] == sk) {
                                    if (DoIndex<4) {
                                        DoIndex+=7; // 0-3 = Combat abilities (7-10)
                                    } else {
                                        DoIndex-=3; // 4-9 = Abilities (1-6)
                                    }
                                    if (!EQADDR_DOABILITYAVAILABLE[sk]) {
                                        strcpy(szTemp,"-2");
                                    } else {
                                        itoa(DoIndex,szTemp,10);
                                    }
                                    DoIndex=10;
                                }
                            }
                        }
                    }
                }
            } else {
                if (Skill>0 && Skill<11) {
                    if (Skill<7) {
                        Skill+=3; // 1-6 = Abilities (4-9)
                    } else {
                        Skill-=7; // 7-10 = Combat abilities (0-3)
                    }
                    if (EQADDR_DOABILITYLIST[Skill]!=0xFFFFFFFF) {
                        strcpy(szTemp,szSkills[EQADDR_DOABILITYLIST[Skill]]);
                    } else {
                        strcpy(szTemp,"NULL");
                    }
                } else {
                    strcpy(szTemp,"NULL");
                }
            }
            strcat(szOutput,szTemp);
        }

    // $char(name)
    } else if (!strncmp("char(name)",szVar,10)) {
        i+=9;
        strcat(szOutput,GetCharInfo()->pSpawn->Name);

    // $char(surname)
    } else if (!strncmp("char(surname)",szVar,13)) {
        i+=12;
        strcat(szOutput,GetCharInfo()->pSpawn->Lastname);

    // $char(guild)
    } else if (!strncmp("char(guild)",szVar,11)) {
        i+=10;
        if (GetCharInfo()->pSpawn->GuildID < 0xFFFE && EQADDR_GUILDLIST) {
            strcat(szOutput,GetGuildByID(GetCharInfo()->pSpawn->GuildID));
        } else {
            strcat(szOutput,"NULL");
        }

    // $char(guild,status)
    } else if (!strncmp("char(guild,status)",szVar,18)) {
        i+=17;
        if (GetCharInfo()->pSpawn->GuildID < 0xFFFE && EQADDR_GUILDLIST) {
            strcat(szOutput,szGuildStatus[GetCharInfo()->pSpawn->GuildStatus]);
        } else {
            strcat(szOutput,"NULL");
        }

    // $char(pet)
    } else if (!strncmp("char(pet)",szVar,9)) {
        PSPAWNINFO pPet = GetPet(GetCharInfo()->pSpawn->SpawnID);
        i+=8;
        if (pPet) {
            CHAR szPet[MAX_STRING] = {0};
            ltoa(pPet->SpawnID,szPet,10);
            strcat(szOutput,szPet);
        } else {
            strcat(szOutput,"0");
        }

    // $char(class)
    } else if (!strncmp("char(class)",szVar,11)) {
        i+=10;
        CHAR szTemp[MAX_STRING] = {0};
        strcpy(szTemp,pEverQuest->GetClassDesc(GetCharInfo()->pSpawn->Class));
        strcat(szOutput,szTemp);

    // $char(race)
    } else if (!strncmp("char(race)",szVar,10)) {
        i+=9;
        CHAR szTemp[MAX_STRING] = {0};
        strcpy(szTemp,pEverQuest->GetRaceDesc(GetCharInfo()->pSpawn->Race));
        strcat(szOutput,szTemp);

    // $char(gender)
    } else if (!strncmp("char(gender)",szVar,12)) {
        i+=11;
        CHAR szTemp[MAX_STRING] = {0};
        strcpy(szTemp,szGender[GetCharInfo()->pSpawn->Gender]);
        strcat(szOutput,szTemp);

    // $char(cash)
    } else if (!strncmp("char(cash)",szVar,10)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=9;
        itoa(pCharInfo->Plat*1000+pCharInfo->Gold*100+pCharInfo->Silver*10+pCharInfo->Copper,szTemp,10);
        strcat(szOutput,szTemp);
    // $char(cash,bank)
    } else if (!strncmp("char(cash,bank)",szVar,15)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=14;
        itoa(pCharInfo->BankPlat*1000+pCharInfo->BankGold*100+pCharInfo->BankSilver*10+pCharInfo->BankCopper,szTemp,10);
        strcat(szOutput,szTemp);

    // $char(plat)
    } else if (!strncmp("char(plat)",szVar,10)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=9;
        itoa(pCharInfo->Plat,szTemp,10);
        strcat(szOutput,szTemp);
    // $char(plat,bank)
    } else if (!strncmp("char(plat,bank)",szVar,15)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=14;
        itoa(pCharInfo->BankPlat,szTemp,10);
        strcat(szOutput,szTemp);
	// $char(plat,shared) 
    } else if (!strncmp("char(plat,shared)",szVar,17)) { 
        CHAR szTemp[MAX_STRING] = {0}; 
        i+=16; 
        itoa(GetCharInfo()->BankSharedPlat,szTemp,10); 
        strcat(szOutput,szTemp); 

    // $char(gold)
    } else if (!strncmp("char(gold)",szVar,10)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=9;
        itoa(pCharInfo->Gold,szTemp,10);
        strcat(szOutput,szTemp);
    // $char(gold,bank)
    } else if (!strncmp("char(gold,bank)",szVar,15)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=14;
        itoa(pCharInfo->BankGold,szTemp,10);
        strcat(szOutput,szTemp);

    // $char(silver)
    } else if (!strncmp("char(silver)",szVar,12)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=11;
        itoa(pCharInfo->Silver,szTemp,10);
        strcat(szOutput,szTemp);

    // $char(silver,bank)
    } else if (!strncmp("char(silver,bank)",szVar,17)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=16;
        itoa(pCharInfo->BankSilver,szTemp,10);
        strcat(szOutput,szTemp);

    // $char(copper)
    } else if (!strncmp("char(copper)",szVar,12)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=11;
        itoa(pCharInfo->Copper,szTemp,10);
        strcat(szOutput,szTemp);
    // $char(copper,bank)
    } else if (!strncmp("char(copper,bank)",szVar,17)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=16;
        itoa(pCharInfo->BankCopper,szTemp,10);
        strcat(szOutput,szTemp);

    // $char(spellbook)
   } else if (!strncmp("char(spellbook)",szVar,15)) {
      i+=14;
      if (!ppSpellBookWnd) {
                   return PMP_ERROR_BADPARM;
                }
      PCSIDLWND pBookWindow = NULL;
      pBookWindow = (PCSIDLWND)pSpellBookWnd;
      if (pBookWindow->Show==1) {
         strcat(szOutput,"TRUE");
      } else {
         strcat(szOutput,"FALSE");
      }

    // $char(Holding)
    } else if (!strncmp("char(holding)",szVar,13)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=12;
      itoa(pCharInfo->pSpawn->Holding,szTemp,10);
        strcat(szOutput,szTemp);

   // $char(underwater) returns 5 if the character is completely under water, zero otherwise
    } else if (!strncmp("char(underwater)",szVar,16)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=15;
      itoa(pCharInfo->pSpawn->pActorInfo->UnderWater,szTemp,10);
        strcat(szOutput,szTemp);

   // $char(swimming) returns 5 if the character is currently swimming, zero otherwise
    } else if (!strncmp("char(swimming)",szVar,14)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=13;
      itoa(pCharInfo->pSpawn->pActorInfo->Swimming,szTemp,10);
        strcat(szOutput,szTemp);

   // $char(feetwet) returns 5 if the character's feet are just in the water
    } else if (!strncmp("char(feetwet)",szVar,13)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=12;
      itoa(pCharInfo->pSpawn->pActorInfo->FeetWet,szTemp,10);
        strcat(szOutput,szTemp);

   // $char(animation) returns the animation number currently playing for the target's avatar
    } else if (!strncmp("char(animation)",szVar,15)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=14;
      itoa(pCharInfo->pSpawn->pActorInfo->Animation,szTemp,10);
        strcat(szOutput,szTemp);

   // $char(mounted)
    } else if (!strncmp("char(mounted)",szVar,13)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=12;
      if(pCharInfo->pSpawn->pActorInfo->Mount ==  NULL )
         strcat(szOutput, "FALSE" );
      else
         strcat(szOutput, "TRUE" );

   // $char(invited)
    } else if (!strncmp("char(invited)",szVar,13)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=12;
      itoa(pCharInfo->pSpawn->pActorInfo->InvitedToGroup,szTemp,10);
        strcat(szOutput,szTemp);

   // $char(following)
    } else if (!strncmp("char(following)",szVar,15)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=14;
      if(pCharInfo->pSpawn->pActorInfo->WhoFollowing == NULL )
         strcat(szOutput, "FALSE" );
      else
         strcat(szOutput, "TRUE" );

   // $char(grouped)
    } else if (!strncmp("char(grouped)",szVar,13)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=12;
      if(pCharInfo->Grouped != 0 )
         strcat(szOutput, "1" );
      else
         strcat(szOutput, "0" );

   // $char(unknown)
    } else {
        DebugSpewNoFile("PMP - Bad $char() '%s'",szVar);
            return PMP_ERROR_BADPARM;
    }


    return i;
}

DWORD parmSpell(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $spell(name,xxx)
    if (!strstr(szVar,",") || !strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $spell() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    } else {
        i += (strstr(szVar,")")-szVar);
        PCHAR szSpell = szVar+6;
        PCHAR szArg = strstr(szVar,",")+1;
        DWORD Length = strstr(szSpell,",")-szSpell;
        CHAR szTemp[MAX_STRING] = {0};
        BOOL IsValid = FALSE;
        if (szSpell[0]=='"') { szSpell++; Length-=2; }
        DebugSpewNoFile("%s -> %s|%d, %s",szVar,szSpell,Length,szArg);
        strncpy(szTemp,szSpell,Length);
        PSPELLLIST pSpell = GetSpellByName(szTemp);
        DebugSpewNoFile("pSpell = %x",pSpell);
        if (!pSpell) {
            strcpy(szTemp,"-1");
        } else if (!strncmp(szArg,"id",2)) {
            itoa(pSpell->ID,szTemp,10);
        } else if (!strncmp(szArg,"level",5)) {
            itoa(pSpell->Level[GetCharInfo()->pSpawn->Class-1],szTemp,10);
        } else if (!strncmp(szArg,"skill",5)) {
            strcpy(szTemp,szSkills[pSpell->Skill]);
        } else if (!strncmp(szArg,"mana",4)) {
            itoa(pSpell->Mana,szTemp,10);
        } else if (!strncmp(szArg,"range",5)) {
            sprintf(szTemp,"%1.2f",pSpell->Range);
        } else if (!strncmp(szArg,"casttime",8)) {
            sprintf(szTemp,"%1.2f",(FLOAT)pSpell->CastTime/1000);
        } else if (!strncmp(szArg,"mycasttime",10)) {
//            DWORD CharInfo = NULL;
//            CharInfo = (DWORD)pCharData;
            DWORD mycasttime = pCharData->GetFocusCastingTimeModifier((EQ_Spell*)pSpell,0);
			/*
            __asm{
                push ecx;
                mov ecx, dword ptr [CharInfo];
                push 0;
                push dword ptr [pSpell];
                call dword ptr [EQADDR_GETFOCUSCASTINGTIMEMODIFIER];
                mov [mycasttime], eax;
                pop ecx;
            };
			/**/
            mycasttime = pSpell->CastTime + mycasttime;
            DebugSpewNoFile("mycasttime %d pSpell->CastTime = %d",mycasttime,pSpell->CastTime);
            sprintf(szTemp,"%1.2f",(FLOAT)mycasttime/1000);
        } else if (!strncmp(szArg,"recoverytime",12)) {
            sprintf(szTemp,"%1.2f",(FLOAT)pSpell->FizzleTime/1000);
        } else if (!strncmp(szArg,"recasttime",10)) {
            sprintf(szTemp,"%1.2f",(FLOAT)pSpell->RecastTime/1000);
        } else if (!strncmp(szArg,"duration",8)) {
            DWORD Tics=GetSpellDuration(pSpell,pChar);
            if (Tics==0xFFFFFFFF) {
                strcpy(szTemp,"PERMANENT");
            } else if (Tics==0xFFFFFFFE) {
                strcpy(szTemp,"UNKNOWN");
            } else if (Tics==0) {
                strcpy(szTemp,"INSTANT");
            } else {
                itoa(Tics*6,szTemp,10);
            }
        } else {
            strcpy(szTemp,"0");
        }
        strcat(szOutput,szTemp);
    }
    return i;
}

DWORD parmReturn(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $return
    i+=5;
    if (gMacroStack) {
        strcat(szOutput,gMacroStack->Return);
    } else
        strcat(szOutput,"NULL");
    return i;
}

DWORD parmZone(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    PCHARINFO pCharInfo = NULL;
    if (NULL == (pCharInfo = GetCharInfo())) return PMP_ERROR_BADPARM;
    DWORD i=0;
    // $zone(xxx)
    if (!strncmp("zone(",szVar,5))
    {
        // $zone()
        if (!strncmp("zone()",szVar,6)) {
            i+=5;
            strcat(szOutput,GetFullZone(GetCharInfo()->pSpawn->Zone));
        // $zone(bound)
        } else if (!strncmp("zone(bound)",szVar,11)) {
            i+=10;
            strcat(szOutput,GetFullZone(pCharInfo->ZoneBoundId));
        // $zone(zem)
        } else if (!strncmp("zone(zem)",szVar,9)) {
            i+=8;
            FLOAT zem = 0.0f;

            if (pZoneInfo && ((PZONEINFO)pZoneInfo)->ZoneExpModifier) {
                zem = ((PZONEINFO)pZoneInfo)->ZoneExpModifier;
            }
            CHAR szTemp[MAX_STRING] = {0};
            sprintf(szTemp,"%1.2f",zem);
            strcat(szOutput,szTemp);

        // $zone(Unknown)
        } else {
            DebugSpewNoFile("PMP - Bad $zone() '%s'",szVar);
            return PMP_ERROR_BADPARM;
        }
    // $zone
    } else {
        i+=3;
        strcat(szOutput,GetFullZone(GetCharInfo()->pSpawn->Zone));
    }
    return i;
}

DWORD parmFind(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $find(xxx)
    // $find()
    if (!strncmp("find()",szVar,6)) {
        i+=5;
        if (gLastFind == LASTFIND_NOTFOUND) {
            strcat(szOutput,"FALSE");
        } else {
            strcat(szOutput,"TRUE");
        }

    // $find(pack)
    } else if (!strncmp("find(pack)",szVar,10)) {
        i+=9;
        if ((gLastFind == LASTFIND_PRIMARY) || (gLastFind == LASTFIND_NOTFOUND)) {
            strcat(szOutput,"FALSE");
        } else {
            CHAR szTemp[MAX_STRING] = {0};
            itoa(gLastFind,szTemp,10);
            strcat(szOutput,szTemp);
        }

    // $find(Unknown)
    } else {
        DebugSpewNoFile("PMP - Bad $find() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    }
    return i;
}

DWORD parmAlert(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $alert
    if (!strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $alert() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    } else if (strstr(szVar,",count)")) {
        PCHAR szArg = szVar+6;
        DWORD dwCount = 0;
        i += (strstr(szVar,")")-szVar);
        GetClosestAlert(pChar,atoi(szArg),&dwCount);
        CHAR szTemp[MAX_STRING] = {0};
        itoa(dwCount,szTemp,10);
        strcat(szOutput,szTemp);
    } else if (strstr(szVar,",id)")) {
        PCHAR szArg = szVar+6;
        PSPAWNINFO pSpawn = NULL;
        DWORD dwID = 0;
        i += (strstr(szVar,")")-szVar);
        pSpawn = GetClosestAlert(pChar,atoi(szArg),NULL);
        if (pSpawn) dwID = pSpawn->SpawnID;
        CHAR szTemp[MAX_STRING] = {0};
        itoa(dwID,szTemp,10);
        strcat(szOutput,szTemp);
    } else {
        PCHAR szArg = szVar+6;
        i += (strstr(szVar,")")-szVar);
        if (!GetClosestAlert(pChar,atoi(szArg),NULL)) {
            strcat(szOutput,"FALSE");
        } else {
            strcat(szOutput,"TRUE");
        }
    }
    return i;
}

DWORD parmGM(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $gm
    i++;
    BOOL bGM = FALSE;
    PSPAWNINFO pSpawn = NULL;
    if (ppSpawnList && pSpawnList) {
        pSpawn = (PSPAWNINFO)pSpawnList;
    }
    while (pSpawn && !bGM) {
        if (pSpawn->GM) bGM = TRUE;
        //if (pSpawn->Guide) bGM = TRUE;
        pSpawn = pSpawn->pNext;
    }
    if (bGM) {
        strcat(szOutput,"TRUE");
    } else {
        strcat(szOutput,"FALSE");
    }
    return i;
}

DWORD parmCombat(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $combat
    if (!EQADDR_ATTACK) return PMP_ERROR_BADPARM;
    BYTE bAttack = *EQADDR_ATTACK;
    i+=5;
    if (bAttack == 0) {
        strcat(szOutput,"TRUE");
    } else {
        strcat(szOutput,"FALSE");
    }
    return i;
}

DWORD parmFreeInv(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    PCHARINFO pCharInfo = NULL;
    PCONTENTS pItem = NULL;
    if (NULL == (pCharInfo = GetCharInfo())) return PMP_ERROR_BADPARM;
    // $freeinv(xxx)
    // $freeinv(space)
    if (!strncmp("freeinv(space)",szVar,14)) {
        DWORD count=0;
        DWORD slot,pslot;
        i+=13;
        CHAR szTemp[MAX_STRING] = {0};
        for (slot=22;slot<30;slot++) {
            if (pItem = pCharInfo->Inventory[slot]) {
                if (pItem->Item->Type == ITEMTYPE_PACK) {
                    for (pslot=0;pslot<pItem->Item->Container.Slots;pslot++) {
                        if (!pItem->Contents[pslot]) count++;
                    }
                }
            } else {
                count++;
            }
        }
        itoa(count,szTemp,10);
        strcat(szOutput,szTemp);

    // $freeinv(size)
    } else if (!strncmp("freeinv(size)",szVar,13)) {
        DWORD size=0;
        DWORD slot,pslot;
        BOOL hasfree = FALSE;
        i+=12;
        CHAR szTemp[MAX_STRING] = {0};
        for (slot=22;slot<30;slot++) {
            if (pItem = pCharInfo->Inventory[slot]) {
                if (pItem->Item->Type == ITEMTYPE_PACK) {
                    hasfree=FALSE;
                    for (pslot=0;pslot<pItem->Item->Container.Slots;pslot++) {
                        if (!pItem->Contents[pslot]) hasfree=TRUE;
                }
                    if (hasfree && (pItem->Item->Container.SizeCapacity>size)) size=pItem->Item->Container.SizeCapacity;
                }
            } else {
                size=4;
            }
        }
        itoa(size,szTemp,10);
        strcat(szOutput,szTemp);

    // $freeinv(Unknown)
    } else {
        DebugSpewNoFile("PMP - Bad $freeinv() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    }
    return i;
}

DWORD parmDistance(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $distance(item)
    if (!strncmp("distance(item)",szVar,14)) {
        if (EnviroTarget.Name[0]==0) {
            DebugSpewNoFile("PMP - Bad $distance(item) 'No item targetted'");
            return PMP_ERROR_BADPARM;
        } else {
            CHAR szTemp[MAX_STRING] = {0};
            DWORD Distance = (DWORD)DistanceToSpawn(pChar,&EnviroTarget);
            i +=13;
            itoa(Distance,szTemp,10);
            strcat(szOutput,szTemp);
        }

    // $distance(door)
    } else if (!strncmp("distance(door)",szVar,14)) {
        if (DoorEnviroTarget.Name[0]==0) {
            DebugSpewNoFile("PMP - Bad $distance(door) 'No door targetted'");
            return PMP_ERROR_BADPARM;
        } else {
            CHAR szTemp[MAX_STRING] = {0};
            DWORD Distance = (DWORD)DistanceToSpawn(pChar,&DoorEnviroTarget);
            i +=13;
            itoa(Distance,szTemp,10);
            strcat(szOutput,szTemp);
        }

    // $distance(y,x)
    } else if (!strncmp("distance(",szVar,9)) {
        CHAR szTemp[MAX_STRING] = {0};
        SPAWNINFO LocSpawn;
        if ((!strstr(szVar,")")) || (!strstr(szVar,","))) {
            DebugSpewNoFile("PMP - Bad $distance# '%s'",szVar);
            return PMP_ERROR_BADPARM;
        } else {
            PCHAR szArg = szVar+9;
            i += (strstr(szVar,")")-szVar);
            LocSpawn.Y = (FLOAT)atof(szArg);
            while (szArg[0]!=',') szArg++;
            szArg++;
            LocSpawn.X = (FLOAT)atof(szArg);
            LocSpawn.Z = 0.0f;

            itoa((INT)DistanceToSpawn(pChar,&LocSpawn),szTemp,10);
            strcat(szOutput,szTemp);
        }
    }
    return i;
}

DWORD parmRand(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0, j;
    // $rand(x)
    CHAR szTemp[MAX_STRING] = {0};
    if (!strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $rand(#) '%s'",szVar);
        return PMP_ERROR_BADPARM;
    } else {
        PCHAR szArg = szVar+5;
        i += (strstr(szVar,")")-szVar);

        j = atol(szArg);
        if (j==0 || j==0xffffffff) {
            DebugSpewNoFile("PMP - Bad $rand(#) '%s'",szVar);
            return PMP_ERROR_BADPARM;
        }
        itoa(rand() % j,szTemp,10);
        strcat(szOutput,szTemp);
    }
    return i;
}

DWORD parmGetLastError(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $GetLastError
    i += 11;
    if (gLastError[0] == 0) {
        strcat(szOutput,"NULL");
    } else {
        strcat(szOutput,gLastError);
    }
    return i;
}

DWORD parmLastTell(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $lasttell
    i += 7;
	if (EQADDR_LASTTELL && EQADDR_LASTTELL[0]!=0) {
		strcat(szOutput,EQADDR_LASTTELL);
    } else {
        strcat(szOutput,"NULL");
    }
    return i;
}

DWORD parmLastCommand(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $lastcommand
    i += 10;
    strcat(szOutput,szLastCommand);
    return i;
}

DWORD parmInvPanel(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $invpanel
    //this can be expanded to actually open the inventorywindow by setting pInvWindow->Open = 1 and pInvWindow->Selector to 1;
    if (!ppInventoryWnd) return PMP_ERROR_BADPARM;
    PCSIDLWND pInvWindow = NULL;
    pInvWindow = (PCSIDLWND)pInventoryWnd;
    if (!pInvWindow) return PMP_ERROR_BADPARM;
    DWORD PanelStatus = pInvWindow->Show;
    i += 7;
    if (PanelStatus == 1) {
        strcat(szOutput,"TRUE");
    } else {
        strcat(szOutput,"FALSE");
    }
    return i;
}

DWORD parmIfN(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $if(n,a,b,c)
    if (!strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $if() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    } else {
        BOOL Bad = FALSE;
        CHAR szCond[MAX_STRING] = {0};
        CHAR szTrue[MAX_STRING] = {0};
        CHAR szFalse[MAX_STRING] = {0};
        PCHAR szArg = szVar+5;
        strncpy(szCond,"n ",2);
        if (strstr(szArg,",")) {
            strncpy(szCond+2,szArg,strstr(szArg,",")-szArg);
            szArg = strstr(szArg,",")+1;
        } else Bad=TRUE;
        if (strstr(szArg,",") && !Bad) {
            strncpy(szTrue,szArg,strstr(szArg,",")-szArg);
            szArg = strstr(szArg,",")+1;
        } else Bad=TRUE;
        if (strstr(szArg,")") && !Bad) {
            strncpy(szFalse,szArg,strstr(szArg,")")-szArg);
        }
        if (!Bad) {
            i = strlen(szVar)-1;
            CHAR szOut[MAX_STRING] = {0};
            DebugSpewNoFile("If (%s) then %s else %s",szCond,szTrue,szFalse);
            if (IfCompare(szCond)) {
                GetArg(szOut,szTrue,1,FALSE);
            } else {
                GetArg(szOut,szFalse,1,FALSE);
            }
            strcat(szOutput,szOut);
        } else {
            return PMP_ERROR_BADPARM;
        }
    }
    return i;
}

DWORD parmIf(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $if(a,b,c)
    if (!strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $if() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    } else {
        BOOL Bad = FALSE;
        CHAR szCond[MAX_STRING] = {0};
        CHAR szTrue[MAX_STRING] = {0};
        CHAR szFalse[MAX_STRING] = {0};
        PCHAR szArg = szVar+3;
        if (strstr(szArg,",")) {
            strncpy(szCond,szArg,strstr(szArg,",")-szArg);
            szArg = strstr(szArg,",")+1;
        } else Bad=TRUE;
        if (strstr(szArg,",") && !Bad) {
            strncpy(szTrue,szArg,strstr(szArg,",")-szArg);
            szArg = strstr(szArg,",")+1;
        } else Bad=TRUE;
        if (strstr(szArg,")") && !Bad) {
            strncpy(szFalse,szArg,strstr(szArg,")")-szArg);
        }
        if (!Bad) {
            i = strlen(szVar)-1;
            CHAR szOut[MAX_STRING] = {0};
            DebugSpewNoFile("If (%s) then %s else %s",szCond,szTrue,szFalse);
            if (IfCompare(szCond)) {
                GetArg(szOut,szTrue,1,FALSE);
            } else {
                GetArg(szOut,szFalse,1,FALSE);
            }
            strcat(szOutput,szOut);
        } else {
            DebugSpewNoFile("PMP - Bad $if() '%s'",szVar);
            return PMP_ERROR_BADPARM;
        }
    }
    return i;
}

DWORD parmMerchantName(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    DebugSpewNoFile("in parmMerchantName");
    // $merchant(name)
    CHAR szTemp[MAX_STRING] = {0};
    CHAR* szOut;
    i += 13;
    if (!ppActiveMerchant || !pActiveMerchant) {
        strcat(szOutput,"NULL");
        return i;
    }
    sprintf(szTemp,"%s",*pActiveMerchant);
    szOut = (char*)&szTemp[1];
    CleanupName(szOut);
    strcat(szOutput,szOut);
    return i;
}

DWORD parmMerchantXXX(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0,argindex=9;;
    CHAR szTemp[MAX_STRING] = {0};
    CHAR szArg[MAX_STRING] = {0};

    CHAR* szOut;
   // $merchant(open)
    if (strstr(szVar,"open)")) {
        i += 13;
        if (!ppMerchantWnd) return PMP_ERROR_BADPARM;
        if (!pMerchantWnd) {
            strcat(szOutput,"FALSE");
        }
        PCSIDLWND pWind = (PCSIDLWND )pMerchantWnd;
        if (pWind->Show==1) {
            strcat(szOutput,"TRUE");
        } else {
            strcat(szOutput,"FALSE");
        }
        return i;
    // $merchant(has,xxx)
    } if (strstr(szVar,"has,")) {
        if (!ppMerchantWnd) return PMP_ERROR_BADPARM;
    PEQMERCHWINDOW pMerchWindow = NULL;
    pMerchWindow = (PEQMERCHWINDOW)pMerchantWnd;
        if (!strstr(szVar,")")) {
            DebugSpewNoFile("PMP - Bad $merchant() '%s'",szVar);
            return PMP_ERROR_BADPARM;
        } else {
            i += (strstr(szVar,")")-szVar);
        if (pMerchWindow->Wnd.Show == 1) {
                PCHAR szArg = szVar+13;
                if (szArg[0]=='"') szArg++;
                // strip off trailing '  ")  ' if it exists... 
                if (szArg[strlen(szArg)-1]==')') szArg[strlen(szArg)-1]=0; 
                if (szArg[strlen(szArg)-1]=='"') szArg[strlen(szArg)-1]=0;
                CHAR szTemp[MAX_STRING] = {0};
                DebugSpewNoFile("$merchant(has) -- looking for '%s'", szArg);
                DWORD i;
                BOOL Found = FALSE;
            for (i=0;i<79;i++) {
                if (pMerchWindow->ItemDesc[i]) {
                    if (!stricmp(szArg,pMerchWindow->ItemDesc[i]->Item->Name)) { 
                            Found=TRUE; 
                            DebugSpewNoFile("Merchant does have: %s",pMerchWindow->ItemDesc[i]->Item->Name); 
                            break; 
                        } 
                    } 
                } 
                if (Found) { 
                    strcat(szOutput,"TRUE"); 
                } else { 
                    strcat(szOutput,"FALSE"); 
                } 
            } else { 
                strcat(szOutput,"NULL"); 
            } 
        } 
        return i; 
    }
    if (!strstr(szVar,")")) {
        sprintf("PMP - Bad $merchant() '%s'",szVar);
        strcat(szOutput,szVar);
        return PMP_ERROR_BADPARM;
    // $merchant("merchname here") || $merchant()
    // example1: /if $merchant()==TRUE /call mybuyroutine
    // example2: /if $merchant("Bodbin Gimple")==TRUE /call mybuyroutine
    } else {
        i+=strstr(szVar,")")-szVar;
        GetArg(szArg,szVar+argindex,1,false,true,true);
        strlwr(szArg);
        if (szArg[strlen(szArg)-1]==')')
            szArg[strlen(szArg)-1]=0;
        DebugSpewNoFile("$merchant(xxx) szArg = %s",szArg);
        if (!ppActiveMerchant || !pActiveMerchant) {
            strcat(szOutput,"FALSE");
            return i;
        }
        sprintf(szTemp,"%s",pActiveMerchant);
        szOut = (char*)&szTemp[1];
        CleanupName(szOut);
        if (!_stricmp(szOut, szArg) || strlen(szArg)==0) {
            strcat(szOutput,"TRUE");
        } else {
            strcat(szOutput,"FALSE");
        }
    }
    return i;
}

DWORD parmCorpse(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
   DWORD i=0;
   DWORD iSlotCnt=0;

   // $corpse(xxx)
   if (!ppLootWnd) return PMP_ERROR_BADPARM;
   PEQLOOTWINDOW pLootWindow = NULL;
   pLootWindow = (PEQLOOTWINDOW)pLootWnd;
   CHAR szTemp[MAX_STRING] = {0};
   if (!strncmp("corpse()",szVar,8)) {
      i += 7;
      if (pLootWindow->Wnd.Show == 1) {
         strcat(szOutput,"TRUE");
      } else {
         strcat(szOutput,"FALSE");
      }
   // $corpse(has,xxx)
   } else if (!strncmp("corpse(has,",szVar,11)) {
      if (!strstr(szVar,")")) {
         DebugSpewNoFile("PMP - Bad $merchant() '%s'",szVar);
         return PMP_ERROR_BADPARM;
      } else {
         i += (strstr(szVar,")")-szVar);
         if (pLootWindow->Wnd.Show == 1) {
            PCHAR szArg = szVar+11;
            if (szArg[0]=='"') szArg++;
            CHAR szTemp[MAX_STRING] = {0};
            DebugSpewNoFile("$corpse(has) -- looking for '%s'", szArg);
            BOOL Found = FALSE;
            for (iSlotCnt=0;iSlotCnt<30;iSlotCnt++) {
               if (pLootWindow->ItemDesc[iSlotCnt]) {
                  if (!strnicmp(szArg,pLootWindow->ItemDesc[iSlotCnt]->Item->Name,strlen(pLootWindow->ItemDesc[iSlotCnt]->Item->Name))) {
                        Found=TRUE;
                        DebugSpewNoFile("Corpse does have: %s",pLootWindow->ItemDesc[iSlotCnt]->Item->Name);
                        break;
                  }
               }
            }
            if (Found) {
               strcat(szOutput,"TRUE");
            } else {
               strcat(szOutput,"FALSE");
            }
         } else {
            strcat(szOutput,"FALSE");
         }
      }
   // $corpse(empty)
   } else if (!strncmp("corpse(empty)",szVar,13)) {
      i += 12;
      if (pLootWindow->Wnd.Show == 1) {
         DebugSpewNoFile("$corpse(empty)");
         BOOL Found = FALSE;
         for (iSlotCnt=0;iSlotCnt<30;iSlotCnt++) {
            if (pLootWindow->ItemDesc[iSlotCnt]) {
               Found=TRUE;
               break;
            }
         }
         if (Found) {
            DebugSpewNoFile("Corpse is not empty");
            strcat(szOutput,"FALSE");
         } else {
            strcat(szOutput,"TRUE");
         }
      } else {
         strcat(szOutput,"TRUE");
      }
   // $corpse(Unknown)
   } else {
      DebugSpewNoFile("PMP - Bad $corpse() '%s'",szVar);
      return PMP_ERROR_BADPARM;
   }
   return i;
}

DWORD parm(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    return i;
}

DWORD parmRunning(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $running
    CHAR szTemp[MAX_STRING] = {0};
    DWORD Running = 0;
    i += 6;
    if (gRunning>0) Running = (DWORD)((GetTickCount()-gRunning)/1000);
    itoa(Running,szTemp,10);
    strcat(szOutput,szTemp);
    return i;
}

DWORD parmTime(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $time(xxx)
    time_t CurTime;
    tm tmTime;
    time(&CurTime);
    tmTime = *localtime( &CurTime );

    // $time()
    if (!strncmp("time()",szVar,6)) {
        i+=5;
        CHAR szTemp[MAX_STRING] = {0};
        sprintf(szTemp,"%02d:%02d:%02d",tmTime.tm_hour,tmTime.tm_min, tmTime.tm_sec);
        strcat(szOutput,szTemp);

        // $time(h)
    } else if (!strncmp("time(h)",szVar,7)) {
        i+=6;
        CHAR szTemp[MAX_STRING] = {0};
        itoa(tmTime.tm_hour,szTemp,10);
        strcat(szOutput,szTemp);

    // $time(m)
    } else if (!strncmp("time(m)",szVar,7)) {
        i+=6;
        CHAR szTemp[MAX_STRING] = {0};
        itoa(tmTime.tm_min,szTemp,10);
        strcat(szOutput,szTemp);

    // $time(s)
    } else if (!strncmp("time(s)",szVar,7)) {
        i+=6;
        CHAR szTemp[MAX_STRING] = {0};
        itoa(tmTime.tm_sec,szTemp,10);
        strcat(szOutput,szTemp);

    // $time(Unknown)
    } else {
        DebugSpewNoFile("PMP - Bad $time() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    }
    return i;
}

DWORD parmDate(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $date(xxx)
    time_t CurTime;
    tm tmTime;
    time(&CurTime);
    tmTime = *localtime( &CurTime );

    // $date()
    if (!strncmp("date()",szVar,6)) {
        i+=5;
        CHAR szTemp[MAX_STRING] = {0};
        sprintf(szTemp,"%04d/%02d/%02d",tmTime.tm_year+1900,tmTime.tm_mon+1, tmTime.tm_mday);
        strcat(szOutput,szTemp);

        // $date(y)
    } else if (!strncmp("date(y)",szVar,7)) {
        i+=6;
        CHAR szTemp[MAX_STRING] = {0};
        itoa(tmTime.tm_year+1900,szTemp,10);
        strcat(szOutput,szTemp);

    // $date(m)
    } else if (!strncmp("date(m)",szVar,7)) {
        i+=6;
        CHAR szTemp[MAX_STRING] = {0};
        itoa(tmTime.tm_mon+1,szTemp,10);
        strcat(szOutput,szTemp);

    // $date(d)
    } else if (!strncmp("date(d)",szVar,7)) {
        i+=6;
        CHAR szTemp[MAX_STRING] = {0};
        itoa(tmTime.tm_mday,szTemp,10);
        strcat(szOutput,szTemp);

    // $date(Unknown)
    } else {
        DebugSpewNoFile("PMP - Bad $date() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    }
    return i;
}

DWORD parmPack(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $pack([bank,]#,xxx)
    DWORD Bank = 0;
    BOOL Enviro = FALSE;
    PCONTENTS pItem = NULL;
    PCHARINFO pCharInfo = NULL;
    CHAR szArg[MAX_STRING]={0};
    CHAR szTemp[MAX_STRING]={0};
    CHAR szParm1[MAX_STRING]={0};
    CHAR szParm2[MAX_STRING]={0};
    CHAR szParm3[MAX_STRING]={0};

    if (NULL == (pCharInfo = GetCharInfo())) return PMP_ERROR_BADPARM;

    if (!strstr(szVar,")")) {
        return PMP_ERROR_BADPARM;
    } else {
        i += (strstr(szVar,")")-szVar);
        if (szVar[5]=='e' || szVar[5]=='E') {
            pItem = GetEnviroContainer();
            Enviro = TRUE;
            GetArg(szTemp,szVar+5,2,FALSE,FALSE,TRUE);
        } else {

        DWORD slot = 8;
        GetArg(szParm1,szVar+5,1,FALSE,FALSE,TRUE);
        if (!stricmp(szParm1,"bank"))
            Bank=1;
        else
            slot=atoi(szParm1);
        GetArg(szParm2,szVar+5,2,FALSE,FALSE,TRUE);
        if (Bank)
            slot=atoi(szParm2);
        else
            strcpy(szTemp,szParm2);
        GetArg(szParm3,szVar+5,3,FALSE,FALSE,TRUE);
        if (szParm3[0] && Bank)
            strcpy(szTemp,szParm3);


        if (
            ((slot > 7) && (!Bank)) ||
            ((slot > 17) && (Bank))
            ) {
            return PMP_ERROR_BADPARM;
        } else {
            DebugSpewNoFile("Pack-- Bank = %d, Slot = %d",Bank, slot);
            if (Bank==1) {
                DebugSpewNoFile("Pack-- pCharInfo->Bank[slot] = %x, pCharInfo = %x",(DWORD)(pCharInfo->Bank[slot]),(DWORD)pCharInfo);
                if (pCharInfo->Bank[slot]!=NULL) {
                    pItem = pCharInfo->Bank[slot];
                }
            } else {
                if (pCharInfo->Inventory[22+slot]!=NULL) {
                    pItem = pCharInfo->Inventory[22+slot];
                }
            }
            }
        }
            if (!pItem) {
                strcat(szOutput,"NULL");
        } else if ((pItem->Item->Type != ITEMTYPE_PACK) && !Enviro) {
                strcat(szOutput,"NULL");
            } else {

                // $pack(#)
                DebugSpewNoFile("Pack-- szTemp=='%s'",szTemp);
                if (szTemp[0]=='\0') {
                    strcat(szOutput,"TRUE");

                // $pack(#,name)
                } else if (!strncmp(szTemp,"name)",5)) {
                    strcat(szOutput,pItem->Item->Name);

                // $pack(#,combine)
                } else if (!strncmp(szTemp,"combine)",8)) {
                    CHAR szCombine[MAX_STRING] = {0};
                    if ((pItem->Item->Container.Combine < MAX_COMBINES) && (szCombineTypes[pItem->Item->Container.Combine] != NULL)) {
                        strcpy(szCombine,szCombineTypes[pItem->Item->Container.Combine]);
                    } else {
                        sprintf(szCombine,"*Unknown%d",pItem->Item->Container.Combine);
                    }
                    strcat(szOutput,szCombine);

                // $pack(#,open)
                } else if (!strncmp(szTemp,"open)",5)) {
                    if (pItem->Open) {
                        strcat(szOutput,"TRUE");
                    } else {
                        strcat(szOutput,"FALSE");
                    }

                // $pack(#,size)
                } else if (!strncmp(szTemp,"size)",5)) {
                    CHAR szTemp[MAX_STRING] = {0};
                    itoa(pItem->Item->Container.SizeCapacity,szTemp,10);
                    strcat(szOutput,szTemp);

                // $pack(#,weight)
                } else if (!strncmp(szTemp,"weight)",7)) {
                    CHAR szTemp[MAX_STRING] = {0};
                    itoa(pItem->Item->Container.WeightReduction,szTemp,10);
                    strcat(szOutput,szTemp);

                // $pack(#,slots)
                } else if (!strncmp(szTemp,"slots)",6)) {
                    CHAR szTemp[MAX_STRING] = {0};
                    itoa(pItem->Item->Container.Slots,szTemp,10);
                    strcat(szOutput,szTemp);

                // $pack(#,space)
                } else if (!strncmp(szTemp,"space)",6)) {
                    CHAR szTemp[MAX_STRING] = {0};
                    signed char i;
                    DWORD Free=pItem->Item->Container.Slots;
                    for (i=0;i<pItem->Item->Container.Slots;i++)
                    if (pItem->Contents[i]) Free--;
                    itoa(Free,szTemp,10);
                    strcat(szOutput,szTemp);

                // $pack(#,empty)
                } else if (!strncmp(szTemp,"empty)",5)) {
                    CHAR szTemp[MAX_STRING] = {0};
                    signed char i;
                    DWORD Free=pItem->Item->Container.Slots;
                    for (i=0;i<pItem->Item->Container.Slots;i++)
                    if (pItem->Contents[i]) Free--;
                    if (Free==pItem->Item->Container.Slots) {
                        strcat(szOutput,"TRUE");
                    } else {
                        strcat(szOutput,"FALSE");
                    }

                // $pack(#,Unknown)
                } else {
                    DebugSpewNoFile("PMP - Bad $pack() '%s'",szVar);
                    return PMP_ERROR_BADPARM;
                }
            }
        }
    return i;
}

DWORD parmArg(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $arg(num,string[,<separator>])
    if ((!strstr(szVar,")")) || (!strstr(szVar,","))) {
        DebugSpewNoFile("PMP - Bad $arg() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    } else {
        CHAR szArg[MAX_STRING] = {0};
        CHAR szTemp[MAX_STRING] = {0};
        DWORD num = 0;

        GetArg(szArg,szVar,2,FALSE,FALSE,TRUE);
        if (szArg[strlen(szArg)-1]==')') {
            szArg[strlen(szArg)-1]=0;
        } else {
            GetArg(szTemp,szVar,3,FALSE,FALSE,TRUE);
            szTemp[1]=0;
        }

        BOOL InQuote = FALSE;
        for (num=0;(szVar[num]!=')' || InQuote) && szVar[num]!='\0' && num<MAX_STRING-1;num++) {
            i++;
            if (szVar[num]=='"') {
                InQuote = !InQuote;
            }
        }

        num = atoi(szVar+4);
        GetArg(szTemp,szArg,num,FALSE,FALSE,FALSE,szTemp[0]);
        strcat(szOutput,szTemp);
    }
    return i;
}

DWORD parmLeft(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $left(num,string)
    if ((!strstr(szVar,")")) || (!strstr(szVar,","))) {
        DebugSpewNoFile("PMP - Bad $left() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    } else {
        CHAR szArg[MAX_STRING] = {0};
        CHAR szTemp[MAX_STRING] = {0};
        DWORD num = 0;
        DWORD zz = 0;
        BOOL InQuote = FALSE;
        for (num=0;(szVar[num]!=')' || InQuote) && szVar[num]!='\0' && num<MAX_STRING-1;num++) {
            i++;
            if (szVar[num]!='"') {
                szTemp[zz++] = szVar[num];
            } else {
                InQuote = !InQuote;
            }
        }
        num = atoi(szTemp+5);
        if (num > MAX_STRING) num = MAX_STRING;
        strcpy(szArg,strstr(szTemp,",")+1);
        ZeroMemory(szTemp,MAX_STRING);
        strncpy(szTemp,szArg,num);
        strcat(szOutput,szTemp);
    }
    return i;
}

DWORD parmMid(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $mid(start,num,string)
    if ((!strstr(szVar,")")) || (!strstr(szVar,",")) || (!strstr(strstr(szVar,",")+1,","))) {
        DebugSpewNoFile("PMP - Bad $mid() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    } else {
        CHAR szArg[MAX_STRING] = {0};
        CHAR szTemp[MAX_STRING] = {0};
        DWORD start = 0;
        DWORD num = 0;
        DWORD zz = 0;
        BOOL InQuote = FALSE;
        for (num=0;(szVar[num]!=')' || InQuote) && szVar[num]!='\0' && num<MAX_STRING-1;num++) {
            i++;
            if (szVar[num]!='"') {
                szTemp[zz++] = szVar[num];
            } else {
                InQuote = !InQuote;
            }
        }
        start = atoi(szTemp+4);
        num = atoi(strstr(szTemp,",")+1);
        if (num > MAX_STRING) num = MAX_STRING;
        strcpy(szArg,strstr(strstr(szTemp,",")+1,",")+1);
        ZeroMemory(szTemp,MAX_STRING);
        strncpy(szTemp,szArg+start,num);
        strcat(szOutput,szTemp);
    }
    return i;
}

DWORD parmRight(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $right(num,string)
    if ((!strstr(szVar,")")) || (!strstr(szVar,","))) {
        DebugSpewNoFile("PMP - Bad $right() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    } else {
        CHAR szArg[MAX_STRING] = {0};
        CHAR szTemp[MAX_STRING] = {0};
        DWORD num = 0;
        DWORD zz = 0;
        BOOL InQuote = FALSE;
        for (num=0;(szVar[num]!=')' || InQuote) && szVar[num]!='\0' && num<MAX_STRING-1;num++) {
            i++;
            if (szVar[num]!='"') {
                szTemp[zz++] = szVar[num];
            } else {
                InQuote = !InQuote;
            }
        }
        num = atoi(szTemp+6);
        strcpy(szArg,strstr(szTemp,",")+1);
        ZeroMemory(szTemp,MAX_STRING);
        if (strlen(szArg)<=num) {
            strcpy(szTemp,szArg);
        } else {
            strcpy(szTemp,szArg + strlen(szArg) - num);
        }
        strcat(szOutput,szTemp);
    }
    return i;
}

DWORD parmInstr(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $instr(word,string)
    if ((!strstr(szVar,")")) || (!strstr(szVar,","))) {
        DebugSpewNoFile("PMP - Bad $instr() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    } else {
        CHAR szArg[MAX_STRING] = {0};
        CHAR szSearch[MAX_STRING] = {0};
        CHAR szTemp[MAX_STRING] = {0};
        DWORD num = 0;
        DWORD zz = 0;
        BOOL InQuote = FALSE;
        for (num=0;(szVar[num]!=')' || InQuote) && szVar[num]!='\0' && num<MAX_STRING-1;num++) {
            i++;
            if (szVar[num]!='"') {
                szTemp[zz++] = szVar[num];
            } else {
                InQuote = !InQuote;
            }
        }
        strncpy(szSearch,szTemp+6,strstr(szTemp,",")-szTemp-6);
        strcpy(szArg,strstr(szTemp,",")+1);
        ZeroMemory(szTemp,MAX_STRING);
        zz=-1;
        for (num=0;num<strlen(szArg)-strlen(szSearch)+1;num++) {
            if (!strnicmp(szArg+num,szSearch,strlen(szSearch))) {
                zz=num;
                num=MAX_STRING;
            }
        }
        DebugSpewNoFile("$instr(): '%s' found in '%s' at location %d",szSearch,szArg,zz);
        itoa(zz,szTemp,10);
        strcat(szOutput,szTemp);
    }
    return i;
}

DWORD parmStrLen(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $strlen(string)
    if (!strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $strlen() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    } else {
        CHAR szArg[MAX_STRING] = {0};
        CHAR szTemp[MAX_STRING] = {0};
        DWORD num = 0;
        DWORD zz = 0;
        BOOL InQuote = FALSE;
        for (num=0;(szVar[num]!=')' || InQuote) && szVar[num]!='\0' && num<MAX_STRING-1;num++) {
            i++;
            if (szVar[num]!='"') {
                szArg[zz++] = szVar[num];
            } else {
                InQuote = !InQuote;
            }
        }
        itoa(strlen(szArg+7),szTemp,10);
        strcat(szOutput,szTemp);
    }
    return i;
}

DWORD parmUcase(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $ucase(string)
    if (!strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $ucase() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    } else {
        CHAR szArg[MAX_STRING] = {0};
        CHAR szTemp[MAX_STRING] = {0};
        DWORD num = 0;
        DWORD zz = 0;
        BOOL InQuote = FALSE;
        for (num=0;(szVar[num]!=')' || InQuote) && szVar[num]!='\0' && num<MAX_STRING-1;num++) {
            i++;
            if (szVar[num]!='"') {
                if ((szVar[num]>='a') && (szVar[num]<='z')) {
                    szTemp[zz++] = szVar[num]-'a'+'A';
                } else {
                    szTemp[zz++] = szVar[num];
                }
            } else {
                InQuote = !InQuote;
            }
        }
        strcat(szOutput,szTemp+6);
    }
    return i;
}

DWORD parmLcase(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $lcase(string)
    if (!strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $lcase() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    } else {
        CHAR szArg[MAX_STRING] = {0};
        CHAR szTemp[MAX_STRING] = {0};
        DWORD num = 0;
        DWORD zz = 0;
        BOOL InQuote = FALSE;
        for (num=0;(szVar[num]!=')' || InQuote) && szVar[num]!='\0' && num<MAX_STRING-1;num++) {
            i++;
            if (szVar[num]!='"') {
                if ((szVar[num]>='A') && (szVar[num]<='Z')) {
                    szTemp[zz++] = szVar[num]-'A'+'a';
                } else {
                    szTemp[zz++] = szVar[num];
                }
            } else {
                InQuote = !InQuote;
            }
        }
        strcat(szOutput,szTemp+6);
    }
    return i;
}

DWORD parmSpawnName(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    //$spawn(name,<name>[,id|fullname])
    // returns TRUE if spawn exists with that name, FALSE otherwise.
    // id will return the ID of the first matching spawn, NULL otherwise.
    // fullname will return the full (uncleaned) name of the spawn, NULL otherwise.
    PSPAWNINFO pSpawn = NULL;
    CHAR szTemp[MAX_STRING]={0};
    CHAR szSearch[MAX_STRING]={0};
    CHAR szOption[MAX_STRING]={0};
    CHAR *pFind=NULL;
    BOOL bID=FALSE;
    BOOL bFullName=FALSE;

    if (!strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $spawn() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    } else {
        pFind=strstr(szVar,")");
        if (pFind==NULL) {
            DebugSpewNoFile("PMP - Bad $spawn() '%s'",szVar);
            return PMP_ERROR_BADPARM;
        } else {
            i+=(DWORD)(pFind-szVar);
        }

        GetArg(szSearch,szVar+11,1,FALSE,FALSE,TRUE);
        GetArg(szOption,szVar+11,2,FALSE,FALSE,TRUE);
        if (szOption[0]!='\0')
        {
            if (!_stricmp(szOption,"id)")) {
                bID=TRUE;
            } else if (!_stricmp(szOption,"fullname)")) {
                bFullName=TRUE;
            } else { return PMP_ERROR_BADPARM; }
        }
        if (szSearch[strlen(szSearch)-1]==')') szSearch[strlen(szSearch)-1]='\0';
        DebugSpewNoFile("Spawn(Name) - SearchString = '%s'",szSearch);
        for (pSpawn=(PSPAWNINFO)pSpawnList;(pSpawn) && (_stricmp(CleanupName(strcpy(szTemp,pSpawn->Name)),CleanupName(szSearch)));pSpawn=pSpawn->pNext);
    }
    if (pSpawn) {
        DebugSpewNoFile("PMP - SpawnName - Spawn '%s' FOUND!",pSpawn->Name);
        if (!bID && !bFullName) strcat(szOutput,"TRUE");
        else if (bFullName) strcat(szOutput,strcpy(szTemp,pSpawn->Name));
        else if (bID) strcat(szOutput,itoa((int)pSpawn->SpawnID,szTemp,10));
    } else {
        DebugSpewNoFile("PMP - SpawnName - Spawn '%s' NOT found!",szTemp);
        if (!bID && !bFullName) strcat(szOutput,"FALSE");
        else if (bFullName) strcat(szOutput,"NULL");
        else if (bID) strcat(szOutput,"NULL");
    }

    return i;
}

DWORD parmCount(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    PCONTENTS pContainer = 0;
    PCHARINFO pCharInfo = NULL;
    if (NULL == (pCharInfo = GetCharInfo())) return PMP_ERROR_BADPARM;
    if (!strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $count() '%s'",szVar);
        return PMP_ERROR_BADPARM;
           // $count(id,xxx)
    } else if (!strncmp("count(id,",szVar,9)) {
        CHAR szArg[MAX_STRING] = {0};
        CHAR szTemp[MAX_STRING] = {0};
        DWORD a,b,c=0;
        DWORD argSize=(strstr(szVar,")")-szVar);
        i += argSize;
        strncpy(szArg,szVar+9,argSize-9);
        GetArg(szTemp,szArg,1);
        for (a=0;a<8;a++) {
            if (!pCharInfo->Inventory[22+a]) continue;
            DebugSpewNoFile("Inventory->ItemNumber %d, looking for %s",pCharInfo->Inventory[22+a]->Item->ItemNumber,szTemp);
            if (pCharInfo->Inventory[22+a]->Item->ItemNumber==(DWORD)atoi(szTemp)) {
                if ((pCharInfo->Inventory[22+a]->Item->Type != ITEMTYPE_NORMAL) || (pCharInfo->Inventory[22+a]->Item->Common.Stackable!=1)) {
                c++;
                } else {
                c+=pCharInfo->Inventory[22+a]->StackCount;
                }
            }

            // Parse through the containers
            if (pCharInfo->Inventory[22+a]->Item->Type == ITEMTYPE_PACK) {
                pContainer = (pCharInfo->Inventory[22+a]);
                for (b=0;b<pCharInfo->Inventory[22+a]->Item->Container.Slots;b++) {
                if (!pContainer->Contents[b]) continue;
                DebugSpewNoFile("Container[%d]->Contents[%d]->Item->ItemNumber %d, looking for %s",a,b,pContainer->Contents[b]->Item->ItemNumber,szTemp);
                if (pContainer->Contents[b]->Item->ItemNumber==(DWORD)atoi(szTemp)) {
                    if ((pContainer->Contents[b]->Item->Type != ITEMTYPE_NORMAL) || (pContainer->Contents[b]->Item->Common.Stackable!=1)) {
                        c++;
                    } else {
                        c+=pContainer->Contents[b]->StackCount;
                    }
                }
                }
            }
        }
        itoa(c, szTemp, 10);
        strcat(szOutput,szTemp);

    // $count(itemname)
    } else {
        CHAR szArg[MAX_STRING] = {0};
        CHAR szTemp[MAX_STRING] = {0};
        DWORD a,b,c=0;
        DWORD argSize=(strstr(szVar,")")-szVar);
        i += argSize;
        strncpy(szArg,szVar+6,argSize-6);
        GetArg(szTemp,szArg,1,FALSE,FALSE,FALSE,')');
        for (a=0;a<8;a++) {
            if (!pCharInfo->Inventory[22+a]) continue;
            if (!stricmp(szTemp,pCharInfo->Inventory[22+a]->Item->Name)) {
                if ((pCharInfo->Inventory[22+a]->Item->Type != ITEMTYPE_NORMAL) || (pCharInfo->Inventory[22+a]->Item->Common.Stackable!=1)) {
                    c++;
                } else {
                    c+=pCharInfo->Inventory[22+a]->StackCount;
                }
            }
            if (pCharInfo->Inventory[22+a]->Item->Type == ITEMTYPE_PACK) {
                pContainer = pCharInfo->Inventory[22+a];
                for (b=0;b<pCharInfo->Inventory[22+a]->Item->Container.Slots;b++) {
                    if (!pContainer->Contents[b]) continue;
                    if (!stricmp(szTemp,pContainer->Contents[b]->Item->Name)) {
                        if ((pContainer->Contents[b]->Item->Type != ITEMTYPE_NORMAL) || (pContainer->Contents[b]->Item->Common.Stackable!=1)) {
                            c++;
                        } else {
                            c+=pContainer->Contents[b]->StackCount;
                        }
                    }
                }
            }
        }
        itoa(c, szTemp, 10);
        strcat(szOutput,szTemp);
    }
    return i;
}

DWORD parmCalc(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $calc(xxx)
    if (!strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $calc() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    } else {
        CHAR Formula[MAX_STRING] = {0};
        while (szVar[i]!=')') i++;
        strcpy(Formula,szVar+5);
        Formula[strstr(Formula,")")-Formula] = 0;
        sprintf(Formula,"%1.2f",Calculate(Formula));
        strcat(szOutput,Formula);
    }
    return i;
}

DWORD parmInt(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $int(xxx)
    if (!strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $int() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    } else {
        CHAR Formula[MAX_STRING] = {0};
        while (szVar[i]!=')') i++;
        strcpy(Formula,szVar+4);
        Formula[strstr(Formula,")")-Formula] = 0;
        LONG Val = (LONG)Calculate(Formula);
        itoa(Val,Formula,10);
        strcat(szOutput,Formula);
    }
    return i;
}

DWORD parmSpellItem(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
   DWORD i=0;
   //syntax example /echo $spell(item,"Warden symbol of Tunare",casttime)
   // will return 4.00 which is correct casttime for that item...
   // Note that you have to have the item equipped or in a primary slot, it can NOT be inside your bags...
   // $Spell(item,<name>,xxx)
   if (!strstr(szVar,",") || !strstr(szVar,")")) {
      DebugSpewNoFile("PMP - Bad $spell() '%s'",szVar);
      return 10000;
   } else {
      i += (strstr(szVar,")")-szVar);
      PCHARINFO pCharInfo = 0;
      pCharInfo = (PCHARINFO)pCharData;
      PSPELLLIST pSpell = 0;
      CHAR szItem[MAX_STRING];
      CHAR szArg[MAX_STRING];
      CHAR szTemp[MAX_STRING];
      ZeroMemory(szItem,MAX_STRING);
      ZeroMemory(szArg,MAX_STRING);
      ZeroMemory(szTemp,MAX_STRING);
      BOOL IsValid = FALSE;
      GetArg(szItem,szVar,2,FALSE,FALSE,TRUE);
      GetArg(szTemp,szVar,3,FALSE,FALSE,TRUE);
      DebugSpewNoFile("SpellItem: Temp = '%s'",szTemp);
      GetArg(szArg,szTemp,1,FALSE,FALSE,FALSE,')');
      DebugSpewNoFile("SpellItem: Arg = '%s'",szArg);
//      if (szArg[strlen(szArg)-1]==')') szArg[strlen(szArg)-1]='\0';
//        DebugSpewNoFile("%s -> %s|%d, %s",szVar,szItem,szArg);
      for (int ItemIndex=0;ItemIndex<30;ItemIndex++) {
         if (pCharInfo->Inventory[ItemIndex])
            if (!_stricmp(szItem,pCharInfo->Inventory[ItemIndex]->Item->Name)) {
               DebugSpewNoFile("$click(%s,%s) in slot %d = %s address is %x",szTemp,szArg,ItemIndex,pCharInfo->Inventory[ItemIndex]->Item->Name,pCharInfo->Inventory[ItemIndex]);
               PCHAR pcSpellName = GetSpellByID(pCharInfo->Inventory[ItemIndex]->Item->Common.SpellId);
               pSpell = GetSpellByName(pcSpellName);
               IsValid = TRUE;
               break;
            }
      }
      if (!IsValid) {
         strcpy(szTemp,"-1");
      } else if (!strncmp(szArg,"id",2)) {
         itoa(pSpell->ID,szTemp,10);
      } else if (!strncmp(szArg,"name",4)) {
         sprintf(szTemp,"%s",pSpell->Name);
      } else if (!strncmp(szArg,"level",5)) {
         itoa(pSpell->Level[GetCharInfo()->pSpawn->Class-1],szTemp,10);
      } else if (!strncmp(szArg,"mana",4)) {
         itoa(pSpell->Mana,szTemp,10);
      } else if (!strncmp(szArg,"range",5)) {
         sprintf(szTemp,"%1.2f",pSpell->Range);
      } else if (!strncmp(szArg,"casttime",8)) {
         sprintf(szTemp,"%1.2f",(FLOAT)pCharInfo->Inventory[ItemIndex]->Item->Common.CastTime/1000);
      } else if (!strncmp(szArg,"recoverytime",12)) {
         sprintf(szTemp,"%1.2f",(FLOAT)pSpell->FizzleTime/1000);
      } else if (!strncmp(szArg,"recasttime",10)) {
         sprintf(szTemp,"%1.2f",(FLOAT)pSpell->RecastTime/1000);
      } else if (!strncmp(szArg,"duration",8)) {
         DWORD Tics=GetSpellDuration(pSpell,pChar);
         if (Tics==0xFFFFFFFF) {
            strcpy(szTemp,"PERMANENT");
         } else if (Tics==0xFFFFFFFE) {
            strcpy(szTemp,"UNKNOWN");
         } else if (Tics==0) {
            strcpy(szTemp,"INSTANT");
         } else {
            itoa(Tics*6,szTemp,10);
         }
      } else {
         strcpy(szTemp,"0");
      }
      strcat(szOutput,szTemp);
   }
   return i;
}
DWORD parmAbs(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $abs(xxx)
    if (!strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $abs() '%s'",szVar);
        return 10000;
    } else {
        CHAR Formula[MAX_STRING] = {0};
        while (szVar[i]!=')') i++;
        strcpy(Formula,szVar+4);
        Formula[strstr(Formula,")")-Formula] = 0;
        DOUBLE Val = Calculate(Formula);
        if (Val<0) Val *= -1;
        sprintf(Formula,"%1.2f",Val);
        strcat(szOutput,Formula);
    }
    return i;
}

DWORD parmSin(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $sin(xxx)
    if (!strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $sin() '%s'",szVar);
        return 10000;
    } else {
        CHAR Formula[MAX_STRING] = {0};
        while (szVar[i]!=')') i++;
        strcpy(Formula,szVar+4);
        Formula[strstr(Formula,")")-Formula] = 0;
        // have to convert argument from deg to rad and result from rad to deg
        sprintf(Formula,"%1.2f",(sin(Calculate(Formula)/DegToRad)));
        strcat(szOutput,Formula);
    }
    return i;
}

DWORD parmCos(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $cos(xxx)
    if (!strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $cos() '%s'",szVar);
        return 10000;
    } else {
        CHAR Formula[MAX_STRING] = {0};
        while (szVar[i]!=')') i++;
        strcpy(Formula,szVar+4);
        Formula[strstr(Formula,")")-Formula] = 0;
        sprintf(Formula,"%1.2f",(cos(Calculate(Formula)/DegToRad)));
        strcat(szOutput,Formula);
    }
    return i;
}

DWORD parmTan(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $tan(xxx)
    if (!strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $tan() '%s'",szVar);
        return 10000;
    } else {
        CHAR Formula[MAX_STRING] = {0};
        while (szVar[i]!=')') i++;
        strcpy(Formula,szVar+4);
        Formula[strstr(Formula,")")-Formula] = 0;
        sprintf(Formula,"%1.2f",(tan(Calculate(Formula)/DegToRad)*DegToRad));
        strcat(szOutput,Formula);
    }
    return i;
}

DWORD parmAsin(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $asin(xxx)
    if (!strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $asin() '%s'",szVar);
        return 10000;
    } else {
        CHAR Formula[MAX_STRING] = {0};
        while (szVar[i]!=')') i++;
        strcpy(Formula,szVar+5);
        Formula[strstr(Formula,")")-Formula] = 0;
        sprintf(Formula,"%1.2f",(asin(Calculate(Formula))*DegToRad));
        strcat(szOutput,Formula);
    }
    return i;
}

DWORD parmAcos(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $acos(xxx)
    if (!strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $acos() '%s'",szVar);
        return 10000;
    } else {
        CHAR Formula[MAX_STRING] = {0};
        while (szVar[i]!=')') i++;
        strcpy(Formula,szVar+5);
        Formula[strstr(Formula,")")-Formula] = 0;
        sprintf(Formula,"%1.2f",(acos(Calculate(Formula))*DegToRad));
        strcat(szOutput,Formula);
    }
    return i;
}

DWORD parmAtan(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $atan(xxx)
    if (!strstr(szVar,")")) {
        DebugSpewNoFile("PMP - Bad $atan() '%s'",szVar);
        return 10000;
    } else {
        CHAR Formula[MAX_STRING] = {0};
        while (szVar[i]!=')') i++;
        strcpy(Formula,szVar+5);
        Formula[strstr(Formula,")")-Formula] = 0;
        sprintf(Formula,"%1.2f",(atan(Calculate(Formula))*DegToRad));
        strcat(szOutput,Formula);
    }
    return i;
}


DWORD parmDoor(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $door(xxx)

    // $door()
    if (!strncmp("door()",szVar,6)) {
        i+=5;
        if (!pDoorTarget) {
            strcat(szOutput,"FALSE");
        } else {
            strcat(szOutput,"TRUE");
        }

    // $door(distance)
    } else if (!strncmp("door(distance)",szVar,14)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=13;

        if (!pDoorTarget) {
            strcat(szOutput,"0");
        } else {
            itoa((INT)DistanceToSpawn(pChar,&DoorEnviroTarget),szTemp,10);
            strcat(szOutput,szTemp);
        }

    // $door(id)
    } else if (!strncmp("door(id)",szVar,8)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=7;
        if (!pDoorTarget) {
            strcat(szOutput,"0");
        } else {
            itoa(pDoorTarget->ID,szTemp,10);
            strcat(szOutput,szTemp);
        }

    // $door(x)
    } else if (!strncmp("door(x)",szVar,7)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=6;
        if (!pDoorTarget) {
            strcat(szOutput,"0");
        } else {
            sprintf(szTemp,"%1.2f",pDoorTarget->X);
            strcat(szOutput,szTemp);
        }

    // $door(y)
    } else if (!strncmp("door(y)",szVar,7)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=6;
        if (!pDoorTarget) {
            strcat(szOutput,"0");
        } else {
            sprintf(szTemp,"%1.2f",pDoorTarget->Y);
            strcat(szOutput,szTemp);
        }

    // $door(z)
    } else if (!strncmp("door(z)",szVar,7)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=6;
        if (!pDoorTarget) {
            strcat(szOutput,"0");
        } else {
            sprintf(szTemp,"%1.2f",pDoorTarget->Z);
            strcat(szOutput,szTemp);
        }

    // $door(heading)
    } else if (!strncmp("door(heading)",szVar,13)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=12;
        if (!pDoorTarget) {
            strcat(szOutput,"0");
        } else {
            sprintf(szTemp,"%1.2f",pDoorTarget->Heading*0.703125f);
            strcat(szOutput,szTemp);
        }

    // $door(defaultx)
    } else if (!strncmp("door(defaultx)",szVar,14)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=13;
        if (!pDoorTarget) {
            strcat(szOutput,"0");
        } else {
            sprintf(szTemp,"%1.2f",pDoorTarget->DefaultX);
            strcat(szOutput,szTemp);
        }

    // $door(defaulty)
    } else if (!strncmp("door(defaulty)",szVar,14)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=13;
        if (!pDoorTarget) {
            strcat(szOutput,"0");
        } else {
            sprintf(szTemp,"%1.2f",pDoorTarget->DefaultY);
            strcat(szOutput,szTemp);
        }

    // $door(defaultz)
    } else if (!strncmp("door(defaultz)",szVar,14)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=13;
        if (!pDoorTarget) {
            strcat(szOutput,"0");
        } else {
            sprintf(szTemp,"%1.2f",pDoorTarget->DefaultZ);
            strcat(szOutput,szTemp);
        }

    // $door(defaultheading)
    } else if (!strncmp("door(defaultheading)",szVar,20)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=19;
        if (!pDoorTarget) {
            strcat(szOutput,"0");
        } else {
            sprintf(szTemp,"%1.2f",pDoorTarget->DefaultHeading*0.703125f);
            strcat(szOutput,szTemp);
        }

    // $door(open)
    } else if (!strncmp("door(open)",szVar,10)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=9;
        if (!pDoorTarget) {
            strcat(szOutput,"FALSE");
        } else {
            if ((pDoorTarget->DefaultHeading != pDoorTarget->Heading) ||
                (pDoorTarget->DefaultZ != pDoorTarget->Z)) {
                strcat(szOutput,"TRUE");
            } else {
                strcat(szOutput,"FALSE");
            }
        }

    // $door(headingto)
    } else if (!strncmp("door(headingto)",szVar,15)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=14;
        if (!pDoorTarget) {
            strcat(szOutput,"0");
        } else {
            DOUBLE HeadingTo = atan2f(pChar->Y - pDoorTarget->Y, pDoorTarget->X - pChar->X) * 180.0f / PI + 90.0f;
            if (HeadingTo<0.0f) HeadingTo += 360.0f;
            if (HeadingTo>=360.0f) HeadingTo -= 360.0f;
            sprintf(szTemp,"%1.2f",HeadingTo);
            strcat(szOutput,szTemp);
        }


    // return NULL for all following $door(xxx) commands if no door
    } else if (!pDoorTarget) {
        while ((szVar[i] != ')') && (szVar[i] != 0)) i++;
        strcat(szOutput,"NULL");

    // $door(name)
    } else if (!strncmp("door(name)",szVar,10)) {
        i+=9;
        strcat(szOutput,pDoorTarget->Name);

    // $door(unknown)
    } else {
        DebugSpewNoFile("PMP - Bad $door() '%s'",szVar);
        return 10000;
    }
    return i;
}

DWORD parmGround(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $ground(xxx)

    // $ground()
    if (!strncmp("ground()",szVar,8)) {
        i+=7;
        if (!pGroundTarget) {
            strcat(szOutput,"FALSE");
        } else {
            strcat(szOutput,"TRUE");
        }

    // $ground(distance)
    } else if (!strncmp("ground(distance)",szVar,16)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=15;

        if (!pGroundTarget) {
            strcat(szOutput,"0");
        } else {
            itoa((INT)DistanceToSpawn(pChar,&EnviroTarget),szTemp,10);
            strcat(szOutput,szTemp);
        }

    // $ground(id)
    } else if (!strncmp("ground(id)",szVar,10)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=9;
        if (!pGroundTarget) {
            strcat(szOutput,"0");
        } else {
            itoa(pGroundTarget->ID,szTemp,10);
            strcat(szOutput,szTemp);
        }

    // $ground(x)
    } else if (!strncmp("ground(x)",szVar,9)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=8;
        if (!pGroundTarget) {
            strcat(szOutput,"0");
        } else {
            sprintf(szTemp,"%1.2f",pGroundTarget->X);
            strcat(szOutput,szTemp);
        }

    // $ground(y)
    } else if (!strncmp("ground(y)",szVar,9)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=8;
        if (!pGroundTarget) {
            strcat(szOutput,"0");
        } else {
            sprintf(szTemp,"%1.2f",pGroundTarget->Y);
            strcat(szOutput,szTemp);
        }

    // $ground(z)
    } else if (!strncmp("ground(z)",szVar,9)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=8;
        if (!pGroundTarget) {
            strcat(szOutput,"0");
        } else {
            sprintf(szTemp,"%1.2f",pGroundTarget->Z);
            strcat(szOutput,szTemp);
        }

    // $ground(heading)
    } else if (!strncmp("ground(heading)",szVar,15)) {
        CHAR szTemp[MAX_STRING] = {0};
        i+=14;
        if (!pGroundTarget) {
            strcat(szOutput,"0");
        } else {
            sprintf(szTemp,"%1.2f",pGroundTarget->Heading*0.703125f);
            strcat(szOutput,szTemp);
        }

    // $ground(name)
    } else if (!strncmp("ground(name)",szVar,12)) {
        i+=11;
        if (!pGroundTarget) {
            strcat(szOutput,"NULL");
        } else {
            strcat(szOutput,pGroundTarget->Name);
        }

    // $ground(unknown)
    } else {
        DebugSpewNoFile("PMP - Bad $ground() '%s'",szVar);
        return 10000;
    }
    return i;
}

DWORD parmHex(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $hex(#)
    PCHAR szArg = szVar+4;
    DWORD dwCount = 0;
    i += (strstr(szVar,")")-szVar);
    sscanf(szArg, "%x", &dwCount);
    CHAR szTemp[MAX_STRING] = {0};
    itoa(dwCount,szTemp,10);
    strcat(szOutput,szTemp);
    return i;
}

DWORD parmDec(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
	CHAR szBuffer[MAX_STRING] = {0};
    // $dec(xxx)
    if (!strstr(szVar,")"))
    {
        DebugSpewNoFile("PMP - Bad $dec() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    }
    else
    {
        CHAR szName[MAX_STRING] = {0};
        while (szVar[i]!=')') i++;
        strcpy(szName,szVar+4);
        szName[strstr(szName,")")-szName] = 0;
		DebugSpewNoFile("$dec szName = %s",szName);
		int szTest = atoi(szName);
		sprintf(szBuffer,"%x",szTest);
        strcat(szOutput,szBuffer);
    }
    return i;
}

DWORD parmNot(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $not(#)
    PCHAR szArg = szVar+4;
    DWORD dwCount = 0;
    i += (strstr(szVar,")")-szVar);
    sscanf(szArg, "%d", &dwCount);
    dwCount = ~dwCount;
    CHAR szTemp[MAX_STRING] = {0};
    itoa(dwCount,szTemp,10);
    strcat(szOutput,szTemp);
    return i;
}

DWORD parmIni(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $ini(<filename>[,<sectionname>[,<keyname>]])
    // Jalapeno & BlueSkies
    // Additions/Modifications by Valerian
    if ((!strstr(szVar,")")) || (szVar[4] == ')')) {
        DebugSpewNoFile("PMP - Bad $ini() '%s'",szVar);
        return 10000;
    } else {
        CHAR szArg1[MAX_STRING] = {0};
        CHAR szArg2[MAX_STRING] = {0};
        CHAR szArg3[MAX_STRING] = {0};
        CHAR szTemp[MAX_STRING] = {0};
        CHAR szBuffer[MAX_STRING] = {0};

        i += (strstr(szVar,")")-szVar);
        strcpy(szBuffer,&szVar[4]);
        szBuffer[strlen(szBuffer)-1]=0;

        GetArg(szArg1,szBuffer,1,FALSE,FALSE,TRUE);
        if (*szArg1)
            GetArg(szArg2,szBuffer,2,FALSE,FALSE,TRUE);
        if (*szArg2)
            GetArg(szArg3,szBuffer,3,FALSE,FALSE,TRUE);

        if (!strstr(szArg1,"\\")) {
            sprintf(szBuffer,"%s\\%s",gszMacroPath, szArg1);
            strcpy(szArg1,szBuffer);
        }
        if (!strstr(szArg1,".")) strcat(szArg1,".ini");

        ZeroMemory(szBuffer,MAX_STRING);

        if ((atoi(szArg2)==-1) || (!*szArg2)) {
            GetPrivateProfileString(NULL,NULL,"NOTFOUND",szBuffer,MAX_STRING,szArg1);
        } else if ((atoi(szArg3)==-1) || (!*szArg3)) {
            GetPrivateProfileString(szArg2,NULL,"NOTFOUND",szBuffer,MAX_STRING,szArg1);
        } else {
            GetPrivateProfileString(szArg2,szArg3,"NOTFOUND",szBuffer,MAX_STRING,szArg1);
        }

        if ((atoi(szArg2)==-1) || (atoi(szArg3)==-1) || (!*szArg2) || (!*szArg3)) {
            for (DWORD k = 0;((szBuffer[k] != 0) || (szBuffer[k+1] != 0));k++)
                if (szBuffer[k]==0) szBuffer[k] = '|';
            strcat(szBuffer,"||");
        }
        strcat(szOutput,szBuffer);

        //DebugSpewNoFile("PMP - $ini(%s,%s,%s) returned '%s'",szArg1,szArg2,szArg3,szBuffer);
    }
    return i;
}

DWORD parmMerchant(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $merchant
    if (!ppMerchantWnd) return 10000;
    PCSIDLWND pMerchWindow = NULL;
    pMerchWindow = (PCSIDLWND)pMerchantWnd;
    i += 7;
    if (pMerchWindow->Show == 1) {
        strcat(szOutput,"TRUE");
    } else {
        strcat(szOutput,"FALSE");
    }
return i;
}

DWORD parmFinditemBank(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    CHAR szTemp[MAX_STRING]={0};
    PCHARINFO pCharInfo = NULL;
    PCONTENTS pContainer = NULL;
    BOOL Exact=TRUE;
    CHAR szArg[MAX_STRING]={0};
    CHAR szSearch[MAX_STRING]={0};
    GetArg(szArg,szVar+14,1,FALSE,FALSE,TRUE);
    if (!stricmp(szArg,"similar"))
    {
        Exact=FALSE;
        GetArg(szSearch,szVar+14,2,FALSE,FALSE,TRUE);
    }
    else _strlwr(strcpy(szSearch,szArg));
    if ((NULL == (pCharInfo = GetCharInfo())) || szSearch[0]=='\0')
    {
        DebugSpewNoFile("PMP - Bad $finditem(bank) '%s'",szVar);
        return PMP_ERROR_BADPARM;
    }
    i += (strstr(szVar,")")-szVar);
    for (int a=0;a<18;a++)
    {
        pContainer=pCharInfo->Bank[a];
        if (pContainer)
        {
            _strlwr(strcpy(szTemp,pContainer->Item->Name));
            if ((Exact && !strcmp(szSearch,szTemp)) ||
                (!Exact && strstr(szSearch,szTemp)))
            {
                sprintf(szTemp,"%d",a);
                strcat(szOutput,szTemp);
                return i;
            }
            for (int b=0;b<10;b++)
            {
                if (pContainer->Contents[b])
                {
                    _strlwr(strcpy(szTemp,pContainer->Contents[b]->Item->Name));
                    if ((Exact && !strcmp(szSearch,szTemp)) ||
                        (!Exact && strstr(szSearch,szTemp)))
                    {
                        sprintf(szTemp,"%d %d",a,b);
                        strcat(szOutput,szTemp);
                        return i;
                    }
                }
            }
        }
    }
    strcat(szOutput,"FALSE");
    return i;
}

DWORD parmFinditem(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    CHAR szTemp[MAX_STRING]={0};
    PCHARINFO pCharInfo = NULL;
    PCONTENTS pContainer = NULL;
    BOOL Exact=TRUE;
    CHAR szArg[MAX_STRING]={0};
    CHAR szSearch[MAX_STRING]={0};
    GetArg(szArg,szVar+9,1,FALSE,FALSE,TRUE);
    if (!stricmp(szArg,"similar"))
    {
        Exact=FALSE;
        GetArg(szSearch,szVar+9,2,FALSE,FALSE,TRUE);
    }
    else _strlwr(strcpy(szSearch,szArg));
    if ((NULL == (pCharInfo = GetCharInfo())) || szSearch[0]=='\0')
    {
        DebugSpewNoFile("PMP - Bad $finditem() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    }
    i += (strstr(szVar,")")-szVar);
    for (int a=0;a<18;a++)
    {
        pContainer=pCharInfo->Inventory[a];
        if (pContainer)
        {
            _strlwr(strcpy(szTemp,pContainer->Item->Name));
            if ((Exact && !strcmp(szSearch,szTemp)) ||
                (!Exact && strstr(szSearch,szTemp)))
            {
                sprintf(szTemp,"%d",a);
                strcat(szOutput,szTemp);
                return i;
            }
            for (int b=0;b<10;b++)
            {
                if (pContainer->Contents[b])
                {
                    _strlwr(strcpy(szTemp,pContainer->Contents[b]->Item->Name));
                    if ((Exact && !strcmp(szSearch,szTemp)) ||
                        (!Exact && strstr(szSearch,szTemp)))
                    {
                        sprintf(szTemp,"%d %d",a,b);
                        strcat(szOutput,szTemp);
                        return i;
                    }
                }
            }
        }
    }
    return i;
}

DWORD parmEQPath(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    CHAR szEQPath[MAX_STRING]={0};
    PCHAR pSearch = GetEQPath(szEQPath);
    if (pSearch) {
        strcat(szOutput,szEQPath);
        i+=5;
    }
    else
        return PMP_ERROR_BADPARM;

    return i;
}

DWORD parmMacroPath(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    strcat(szOutput,gszMacroPath);
    i+=8;
    return i;
}

DWORD parmMQPath(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    strcat(szOutput,gszINIPath);
    i+=5;
    return i;
}

DWORD parmLogPath(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    strcat(szOutput,gszLogPath);
    i+=6;
    return i;
}

DWORD parmSqrt(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $sqrt(xxx)
    if (!strstr(szVar,")"))
    {
        DebugSpewNoFile("PMP - Bad $sqrt() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    }
    else
    {
        CHAR Formula[MAX_STRING] = {0};
        while (szVar[i]!=')') i++;
        strcpy(Formula,szVar+5);
        Formula[strstr(Formula,")")-Formula] = 0;
        sprintf(Formula,"%1.2f",(sqrt(Calculate(Formula))));
        strcat(szOutput,Formula);
    }
    return i;
}

DWORD parmDefined(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $defined(xxx)
    if (!strstr(szVar,")"))
    {
        DebugSpewNoFile("PMP - Bad $defined() '%s'",szVar);
        return PMP_ERROR_BADPARM;
    }
    else
    {
        CHAR szName[MAX_STRING] = {0};
        PCHAR szCheck = NULL;
        PTIMER pCheck = NULL;
        while (szVar[i]!=')') i++;
        strcpy(szName,szVar+8);
        szName[strstr(szName,")")-szName] = 0;



        if (IsVariableDefined(szName)) {
                strcat(szOutput,"TRUE");
            } else {
                strcat(szOutput,"FALSE");
        }
    }
    return i;
}
DWORD parmEnvOpen(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    //$envopen
    //returns the name of the enviro if it is open
    //example: /echo $envopen | Output if successful: Oven
    DWORD i=6;
    PEQ_CONTAINERWND_MANAGER ContainerMgr = 0;
    PITEMINFO pEnvinfo = 0;
    if(!ppContainerMgr || !pContainerMgr) return PMP_ERROR_BADPARM;
    ContainerMgr = (PEQ_CONTAINERWND_MANAGER)pContainerMgr;
    if(!ContainerMgr->pWorldContents) {
        strcat(szOutput,"ENVIRO_NOT_OPEN");
        return i;
    }
    if(!*(DWORD *)ContainerMgr->pWorldContents)  {
        strcat(szOutput,"ENVIRO_NOT_OPEN");
        return i;
    }
    pEnvinfo = *(PITEMINFO *)ContainerMgr->pWorldContents;
    if(pEnvinfo) {
        strcat(szOutput,pEnvinfo->Name);
    } else {
        strcat(szOutput,"ENVIRO_NOT_OPEN");
    }
    return i;
}

DWORD parmGiveWnd(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0;
    // $giveopen
    //returns TRUE if the "give to npc" window is open else FALSE
    if (!ppGiveWnd) return PMP_ERROR_BADPARM;
	PCSIDLWND pGivWindow = NULL;
	pGivWindow = (PCSIDLWND)pGiveWnd;
    if (!pGivWindow) return PMP_ERROR_BADPARM;
	DWORD PanelStatus = pGivWindow->Show;
    i += 7;
    if (PanelStatus == 1) {
        strcat(szOutput,"TRUE");
    } else {
        strcat(szOutput,"FALSE");
    }
    return i;
}

DWORD parmSelectedItem(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0,argindex=13;;
    CHAR szName[MAX_STRING] = {0};
    CHAR szArg[MAX_STRING] = {0};
	PEQCURRENTSELECTION pSelectedSlot = NULL;
	if (!ppSelectedItem || !pSelectedItem) return PMP_ERROR_BADPARM;

	pSelectedSlot = (PEQCURRENTSELECTION)pSelectedItem;
    if(!pSelectedSlot || !pSelectedSlot->TextureAnim || !*(DWORD *)pSelectedSlot->TextureAnim || !**(DWORD **)pSelectedSlot->TextureAnim) {
		strcat(szOutput,"NULL\0");
		i+=strstr(szVar,")")-szVar;
		return i;
    }
	PITEMINFO pSelectedItemInfo = **(PITEMINFO **)pSelectedSlot->TextureAnim;
	PCONTENTS pSelectedItemCont = *(PCONTENTS *)pSelectedSlot->TextureAnim;
	// $selecteditem(count)
    if (strstr(szVar,"count)")) {
        i += 18;
		if (pSelectedItemCont) {
			if(pSelectedItemCont->StackCount) {
				itoa( pSelectedItemCont->StackCount, szName, 10 );
				strcat(szOutput,szName);
				DebugSpewNoFile("pSelectedItemInfo = %x",pSelectedItemInfo);
				DebugSpewNoFile("pSelectedItemCont = %x",pSelectedItemCont);
			} else {
				strcat(szOutput,"NOT_STACKABLE\0");
			}
		} else {
			strcat(szOutput,"NULL\0");
		}
        return i;
    // $selecteditem(ItemSlot2)
    } else if (strstr(szVar,"itemslot2)")) {
        i += 22;
		if (pSelectedItemCont) {
			if(pSelectedItemCont->ItemSlot2) {
				itoa( pSelectedItemCont->ItemSlot2, szName, 10 );
				strcat(szOutput,szName);
			} else {
				strcat(szOutput,"NOT_APPLICABLE\0");
			}
		} else {
			strcat(szOutput,"NULL\0");
		}
        return i;
    }
	// $selecteditem()
    if (!strstr(szVar,")")) {
        sprintf("PMP - Bad $merchant() '%s'",szVar);
        strcat(szOutput,szVar);
        return PMP_ERROR_BADPARM;
    } else {
        i+=strstr(szVar,")")-szVar;
        GetArg(szArg,szVar+argindex,1,false,true,true);
        strlwr(szArg);
        if (szArg[strlen(szArg)-1]==')')
            szArg[strlen(szArg)-1]=0;
        DebugSpewNoFile("$merchant(xxx) szArg = %s",szArg);

        if (pSelectedItemInfo) {
			strcat(szOutput,pSelectedItemInfo->Name);
		} else {
			strcat(szOutput,"NULL");
		}
    }
    return i;
}

DWORD parmServerName(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    // $servername
    strcat(szOutput,EQADDR_SERVERNAME);
    return 10;
}

DWORD parmLoginName(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{ 
    // $loginname
	PCHAR szLogin = GetLoginName();
	if (!szLogin) {
		strcat(szOutput,"NULL");
	} else {
		strcat(szOutput,szLogin);
		free(szLogin);
	}
    return 9; 
}

DWORD parmGameState(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{ 
	DWORD GameState = gGameState;
	switch (GameState) {
		case GAMESTATE_CHARSELECT:
			strcat(szOutput,"CHARSELECT");
			break;
		case GAMESTATE_INGAME:
			strcat(szOutput,"INGAME");
			break;
		default:
			strcat(szOutput,"UNKNOWN");
 	}
    return 9; 
}
DWORD parmBanker(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar)
{
    DWORD i=0,argindex=7;;
    CHAR szTemp[MAX_STRING] = {0};
    CHAR szArg[MAX_STRING] = {0};
   // $banker(open)
    if (strstr(szVar,"open)")) {
        i += 11;
        if (!pinstCBankWnd) return PMP_ERROR_BADPARM;
        if (!*(DWORD *)pinstCBankWnd) {
            strcat(szOutput,"FALSE");
			return i;
        }
        PCSIDLWND pWind = *(PCSIDLWND *)pinstCBankWnd;
        if (pWind->Show==1) {
            strcat(szOutput,"TRUE");
        } else {
            strcat(szOutput,"FALSE");
        }
	}
	return i;
}