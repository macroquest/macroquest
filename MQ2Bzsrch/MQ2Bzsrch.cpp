/*****************************************************************************
    mq2bzsrch.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 DKAA

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as 
    published by the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
******************************************************************************/

//
// MQ2Bzsrch.cpp : Bazaar Seach Plugin by DKAA
//
// read this first: v1.0: search only -- you need the bazaar window up 
// to see the results
//

#include "../MQ2Plugin.h"

struct _BazaarSearchRequestPacket {
/* 0x0 */   int     BSRCommand;     // should be 7
/* 0x4 */   int     BSRTraderID;    // default 0
/* 0x8 */   int     BSRClass;       // default -1
/* 0xc */   int     BSRRace;        // default -1
/* 0x10 */  int     BSRStat;        // default -1
/* 0x14 */  int     BSRSlot;        // default -1
/* 0x18 */  int     BSRType;        // default -1
/* 0x1c */  char    BSRName[64];    // name
/* 0x5c */  int     BSRPriceL;      // price floor, default 0
/* 0x60 */  int     BSRPriceH;      // price ceiling, default 0
};

struct _BazaarSearchResponsePacket {
/* 0x0 */   int     BSSmsg;         // should be 7 
/* 0x4 */   int     BSSQuantity;    
/* 0x8 */   int     BSSItemID;        
/* 0xc */   int     BSSTraderID;
/* 0x10 */  int     BSSPrice;
/* 0x14 */  int     BSSValue;       // double check
/* 0x18 */  char    BSSName[0x40];  // size is 0x58
};


struct _classes {
    char *name;
    int classn;
} classes[] = {
    "any", -1,
    "bard", 8,
    "beastlord", 15,
    "cleric", 2,
    "druid", 6,
    "enchanter", 14,
    "magician", 13,
    "monk", 7,
    "necromancer", 11,
    "paladin", 3,
    "ranger", 4,
    "rogue", 9,
    "shadow knight", 5,
    "shaman", 10,
    "warrior", 1,
    "wizard", 12,
};

struct _races {
    char *name;
    int race;
} races[] = {
    "any", -1,
    "barbarian", 2,
    "dark elf",6,
    "dwarf", 8,
    "erudite", 3,
    "froglok", 15,
    "gnome", 12,
    "half elf", 7,
    "halfling", 11,
    "high elf", 5,
    "human", 1,
    "iksar", 13,
    "ogre", 10,
    "troll", 9,
    "vah shir", 14,
    "wood elf", 4,
};

struct _stats {
    char *name;
    int stat;
} stats[] = {
    "any", -1,
    "armor class", 14,
    "agility", 2,
    "charisma", 6,
    "dexterity", 3,
    "intelligence", 4,
    "stamina", 1,
    "strength", 0,
    "wisdom", 5,
    "vs cold", 8,
    "vs disease", 11,
    "vs fire", 9,
    "vs magic", 7,
    "vs poison", 10,
    "hit points", 13,
    "mana", 12,
};

struct _slots {
    char *name;
    int slot;
} slots[] = { 
    "any", -1,
    "ammo", 21,
    "arms", 7,
    "back", 8,
    "charm", 0,
    "chest", 11,
    "ear", 1,
    "face", 3,
    "feet", 19,
    "fingers", 15,
    "hands", 12,
    "head", 2,
    "legs", 18,
    "neck", 5,
    "primary", 13,
    "range", 11,
    "secondary", 14,
    "shoulders", 6,
    "waist", 20,
    "wrist", 9,
};

struct _types {
    char *name;
    int type;
} types[] = { 
    "any", -1,
    "1h slashing", 0,
    "1h blunt", 3,
    "2h blunt", 4,
    "2h slashing", 1,
    "2h piercing", 35,
    "alcohol", 38,
    "all effects", 46,
    "armor", 10,
    "arrow", 27,
    "bandages", 18,
    "book", 31,
    "bow", 5,
    "brass instrument", 25,
    "combinable", 17,
    "drink", 15,
    "flowing thought", 48,
    "focus effect", 49,
    "food", 14,
    "haste", 47,
    "jewelry", 29,
    "key", 33,
    "light", 16,
    "martial", 45,
    "misc", 11,
    "note", 32,
    "percussion instrument", 26,
    "piercing", 2,
    "potion", 21,
    "scroll", 20,
    "shield", 8,
    "stringed instrument", 24,
    "throwing", 19,
    "wind instrument", 23,
};


PreSetup("MQ2Bzsrch");

void BzSrchMe(PSPAWNINFO pChar, PCHAR szLine);
void MQ2BzSrch(PSPAWNINFO pChar, PCHAR szLine);

// we need to specify a class because we are hooking a class member 
// function.  This should preserve ecx (*this).   We don't ever 
// instanstiate this class, so we don't need constructors.
class BzSrchHook
{
public:
    void BzTrampoline(char *itemarray,int count); 

    // count is byte count
    // msg must be 7 on the first item or it is not
    // an item list but a request to resort the list
    void BzDetour(char *itemarray,int count) 
    {
        int i;
        struct _BazaarSearchResponsePacket *ptr = (struct _BazaarSearchResponsePacket *) itemarray;

        DebugSpewAlways("count = %d\n", count);
    
        // future: copy these to a list that we keep here for so that
        // they may be retrieved with a $bazaar parm
        if (ptr->BSSmsg == 7) {
            for(i=0;(i<5) && (i<(int)(count/sizeof(struct _BazaarSearchResponsePacket)));i++, ptr++)
                DebugSpewAlways("item %d: %s msg %d n %d, itemid %d, value %d", i, 
                    ptr->BSSName,
                    ptr->BSSmsg,
                    ptr->BSSQuantity,
                    ptr->BSSItemID,
                    ptr->BSSValue);
        }

        BzTrampoline(itemarray, count);
    };
};

DETOUR_TRAMPOLINE_EMPTY(VOID BzSrchHook::BzTrampoline(char *,int)); 

// Called once, when the plugin is to initialize
PLUGIN_API VOID InitializePlugin(VOID)
{
    DebugSpewAlways("Initializing MQ2Bzsrch");

    // Add commands, macro parameters, hooks, etc.
    AddCommand("/bzsrch",BzSrchMe);
    AddCommand("/mq2bzsrch",MQ2BzSrch);
    // AddParm("$bazaar(x)",MyParm);
    void (BzSrchHook::*pfDetour)(char *,int) = BzSrchHook::BzDetour; 
    void (BzSrchHook::*pfTrampoline)(char *,int) = BzSrchHook::BzTrampoline; 
    AddDetour(CBazaarSearchWnd__HandleBazaarMsg,
            *(PBYTE*)&pfDetour,
            *(PBYTE*)&pfTrampoline);
}

// Called once, when the plugin is to shutdown
PLUGIN_API VOID ShutdownPlugin(VOID)
{
    DebugSpewAlways("Shutting down MQ2Bzsrch");

    // Remove commands, macro parameters, hooks, etc.
    RemoveDetour(CBazaarSearchWnd__HandleBazaarMsg);
    // RemoveParm("$bazaar(x)");
    RemoveCommand("/bzsrchme");
}

VOID MQ2BzSrch(PSPAWNINFO pChar, PCHAR szLine)
{
    WriteChatColor("Bazaar Search Plugin by DKAA",USERCOLOR_WHO);
    WriteChatColor("",USERCOLOR_WHO);
    WriteChatColor("usage: /bzsrch [params] [name]",USERCOLOR_WHO);
    WriteChatColor("    params:",USERCOLOR_WHO);
    WriteChatColor("    [race any|barbarian|dark elf|dwarf|erudite|froglok|gnome|half elf|halfling|high elf|human|iksar|ogre|troll|vah shir|wood elf]",USERCOLOR_WHO);
    WriteChatColor("    [class any|bard|beastlord|cleric|druid|enchanter|magician|monk|necromancer|paladin|ranger|rogue|shadow knight|shaman|warrior|wizard]", USERCOLOR_WHO);
    WriteChatColor("    [stat any|armor class|agility|charisma|dexterity|intelligence|stamina|strength|wisdom|vs cold|vs disease|vs fire|vs magic|vs poison|hit points|mana]", USERCOLOR_WHO);
    WriteChatColor("    [slot  any|ammo|arms|back|charm|chest|ear|face|feet|fingers|hands|head|legs|neck|primary|range|secondary|shoulders|waist|wrist]", USERCOLOR_WHO);
    WriteChatColor("    [type  any|1h slashing|1h blunt|2h blunt|2h slashing|2h piercing|alcohol|all effects|armor|arrow|bandages|book|bow|brass instrument|combinable|drink|flowing thought|focus effect|food|haste|jewelry|key|light|martial|misc|note|percussion instrument|piercing|potion|scroll|shield|stringed instrument|throwing|wind instrument]", USERCOLOR_WHO);
    WriteChatColor("    [price <low> <high>]", USERCOLOR_WHO);
}

VOID BzSrchMe(PSPAWNINFO pChar, PCHAR szLine)
{
    struct _BazaarSearchRequestPacket bsrp;
    CHAR szArg[MAX_STRING] = {0};
    PCHARINFO pCharInfo = GetCharInfo();
    BOOL bArg = TRUE;
    int i;

    // clear out the old list or the new entries will be
    // added to them
    class CListWnd *ptr = *(class CListWnd **) ((char *)pBazaarSearchWnd+0x39a8);
    ptr->DeleteAll();


    // default to current race and class
    bsrp.BSRCommand = 7;
    bsrp.BSRTraderID = 0;
    bsrp.BSRClass = pCharInfo->Class;
    bsrp.BSRRace = pCharInfo->Race;
    bsrp.BSRStat = -1;
    bsrp.BSRSlot = -1;
    bsrp.BSRType = -1;
    memset(bsrp.BSRName, 0, 60);
    bsrp.BSRPriceH = 0;
    bsrp.BSRPriceL = 0;

    while(bArg) {
        GetArg(szArg,szLine,1);
        szLine = GetNextArg(szLine, 1);
        if (szArg[0]==0) {
            bArg = FALSE;
        } else if (!strcmp(szArg, "class")) {
            GetArg(szArg,szLine,1);
            szLine = GetNextArg(szLine, 1);
            if (szArg[0]==0) {
                WriteChatColor("Bad class name.",USERCOLOR_WHO);
                goto error_out;
            }
            if (isdigit(szArg[0])) {
                bsrp.BSRClass = atoi(szArg);
                continue;
            }
            for(i=0;i<sizeof(classes)/sizeof(classes[0]);i++) {
                if (!strcmp(szArg, classes[i].name)) {
                    bsrp.BSRClass = classes[i].classn;
                    break;
                }
            }
            if (i==sizeof(classes)/sizeof(classes[0])) {
                WriteChatColor("Bad class name.",USERCOLOR_WHO); 
                goto error_out;
            }
        } else if (!strcmp(szArg, "race")) {
            GetArg(szArg,szLine,1);
            szLine = GetNextArg(szLine, 1);
            if (szArg[0]==0) {
                WriteChatColor("Bad race name.",USERCOLOR_WHO);
                goto error_out;
            }
            if (isdigit(szArg[0])) {
                bsrp.BSRRace = atoi(szArg);
                continue;
            }
            for(i=0;i<sizeof(races)/sizeof(races[0]);i++) {
                if (!strcmp(szArg, races[i].name)) {
                    bsrp.BSRRace = races[i].race;
                    break;
                }
            }
            if (i==sizeof(races)/sizeof(races[0])) {
                WriteChatColor("Bad race name.",USERCOLOR_WHO); 
                goto error_out;
            }
        } else if (!strcmp(szArg, "stat")) {
            GetArg(szArg,szLine,1);
            szLine = GetNextArg(szLine, 1);
            if (szArg[0]==0) {
                WriteChatColor("Bad stat name.",USERCOLOR_WHO);
                goto error_out;
            }
            if (isdigit(szArg[0])) {
                bsrp.BSRStat = atoi(szArg);
                continue;
            }
            for(i=0;i<sizeof(stats)/sizeof(stats[0]);i++) {
                if (!strcmp(szArg, stats[i].name)) {
                    bsrp.BSRStat = stats[i].stat;
                    break;
                }
            }
            if (i==sizeof(stats)/sizeof(stats[0])) {
                WriteChatColor("Bad stat name.",USERCOLOR_WHO); 
                goto error_out;
            }
        } else if (!strcmp(szArg, "slot")) {
            GetArg(szArg,szLine,1);
            szLine = GetNextArg(szLine, 1);
            if (szArg[0]==0) {
                WriteChatColor("Bad slot name.",USERCOLOR_WHO);
                goto error_out;
            }
            if (isdigit(szArg[0])) {
                bsrp.BSRSlot = atoi(szArg);
                continue;
            }
            for(i=0;i<sizeof(slots)/sizeof(slots[0]);i++) {
                if (!strcmp(szArg, slots[i].name)) {
                    bsrp.BSRSlot = slots[i].slot;
                    break;
                }
            }
            if (i==sizeof(slots)/sizeof(slots[0])) {
                WriteChatColor("Bad slot name.",USERCOLOR_WHO); 
                goto error_out;
            }
        } else if (!strcmp(szArg, "type")) {
            GetArg(szArg,szLine,1);
            szLine = GetNextArg(szLine, 1);
            if (szArg[0]==0) {
                WriteChatColor("Bad type name.",USERCOLOR_WHO);
                goto error_out;
            }
            if (isdigit(szArg[0])) {
                bsrp.BSRType = atoi(szArg);
                continue;
            }
            for(i=0;i<sizeof(types)/sizeof(types[0]);i++) {
                if (!strcmp(szArg, types[i].name)) {
                    bsrp.BSRType = types[i].type;
                    break;
                }
            }
            if (i==sizeof(types)/sizeof(types[0])) {
                WriteChatColor("Bad type name.",USERCOLOR_WHO); 
                goto error_out;
            }
        } else if (!strcmp(szArg, "price")) {
            GetArg(szArg,szLine,1);
            szLine = GetNextArg(szLine, 1);
            if (szArg[0]==0) {
                WriteChatColor("Bad price low.",USERCOLOR_WHO);
                goto error_out;
            }
            bsrp.BSRPriceL = atoi(szArg);
            
            GetArg(szArg,szLine,1);
            szLine = GetNextArg(szLine, 1);
            if (szArg[0]==0) {
                WriteChatColor("Bad price high.",USERCOLOR_WHO);
                goto error_out;
            }
            bsrp.BSRPriceH = atoi(szArg);
        } else { // it's a name
            strcat(bsrp.BSRName, " ");
            strcat(bsrp.BSRName, szArg);
        }
    }
    
    send_message(EQADDR_GWORLD,0x1ec, &bsrp, sizeof(bsrp), TRUE);
    return;

error_out:
    return;
}
