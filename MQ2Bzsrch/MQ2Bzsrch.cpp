/*****************************************************************************
mq2bzsrch.dll: MacroQuest2's extension DLL for EverQuest
Copyright (C) 2003-2004 DKAA

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
//
// Original MQ2Data update by CyberCide... but it didn't work like the rest of
//  MQ2Data so Lax redid it.
//
#include "../MQ2Plugin.h"
#include "netstream.h"


PLUGIN_VERSION(1.1);

struct _BazaarSearchRequestPacket
{
    /* 0x0 */   int     BSRCommand;     // should be 7               -7c
    /* 0x4 */   int     BSRTraderID;    // default 0                 -78
    /* 0x8 */   int     BSRClass;       // default -1                -74
    /* 0xc */   int     BSRRace;        // default -1                -70
    /* 0x10 */  int     BSRStat;        // default -1                -6c
    /* 0x14 */  int     BSRSlot;        // default -1                -68
    /* 0x18 */  int     BSRType;        // default -1                -64
    /* 0x1c */  char    BSRName[64];    // name                      -60
    /* 0x5c */  int     BSRPriceL;      // price floor, default 0    -20
    /* 0x60 */  int     BSRPriceH;      // price ceiling, default 0  -1c
    /* 0x64 */  int     BSRLevelL;      // level low,  default 1     -18
    /* 0x68 */  int     BSRLevelH;      // level high, default 70    -14
    /* 0x6c */
};

// size is 0xa0 4/17/08

struct _BazaarSearchResponsePacket
{
    /* 0x00 */   int     BSSmsg;         // should be 7
    /* 0x04 */   int     BSSTraderID;    // correct 9/16
    /* 0x08 */   char    BSSTraderName[0x40];
    /* 0x48 */   int     BSSQuantity;    // correct 9/16
    /* 0x4c */   int     BSSItemID;      // correct 9/16
    /* 0x50 */   int     BSSUnknown10;
    /* 0x54 */   int     BSSUnknown14;
    /* 0x58 */   char    BSSName[0x40];  // correct 9/16
    /* 0x98 */   int     BSSPrice;       // correct 9/16
    /* 0x9c */   int     BSSValue;       // correct 9/16
    /* 0xa0 */
};

struct _classes
{
    char *name;
    int classn;
}


classes[] =
{
    "any", -1,
    "bard", 8,
    "beastlord", 15,
    "berserkers", 16,
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

struct _races
{
    char *name;
    int race;
}


races[] =
{
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

struct _stats
{
    char *name;
    int stat;
}


stats[] =
{
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

struct _slots
{
    char *name;
    int slot;
}


slots[] =
{
    "any", -1,
    "ammo", 21,
    "arms", 7,
    "back", 8,
    "charm", 0,
    "chest", 17,                         // not 11
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

struct _types
{
    char *name;
    int type;
}


types[] =
{
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

DWORD BzCount = 0;
DWORD BzDone = 0;
struct _BazaarSearchResponsePacket BzArray[200];
ITEMINFO *pg_Item;                                // dependent on MQ2ItemDisplay

PreSetup("MQ2Bzsrch");

void BzSrchMe(PSPAWNINFO pChar, PCHAR szLine);
void MQ2BzSrch(PSPAWNINFO pChar, PCHAR szLine);
VOID bzpc(PSPAWNINFO pChar, PCHAR szLine);
DWORD parmBazaar(PCHAR szVar, PCHAR szOutput, PSPAWNINFO pChar);
BOOL dataBazaar(PCHAR szName, MQ2TYPEVAR &Ret);

// length is variable based on item name
struct bzrItemData {
/*0x00*/ DWORD  nTrader;
/*0x04*/ WORD   b;
/*0x06*/ DWORD  c;  // float
/*0x0a*/ DWORD  nItems;
/*0x0e*/ DWORD  nTrader1;
/*0x12*/ CHAR   f[0x11];
/*0x23*/ DWORD  price;
/*0x27*/ DWORD  quantity;
/*0x2b*/ DWORD  ItemID;
/*0x2f*/ DWORD  icon;
/*0x33*/ char   ItemName[0x40];
/*0x73*/ DWORD  m;
};

struct bzrData {
    void *pData; // ptr to bzrItemData
    DWORD nSize; // size of bzrItemData
    DWORD nPos;  // store position
};

struct traderData {
    DWORD a;
    DWORD b;
    DWORD c;
    char  name[0x40];
};

class BzSrchHook
{
public:
    void BzTrampoline(bzrData *bz);
    void BzDetour(bzrData *bz)
    {

#define SetTraderName(trader)\
        {\
        nTmp = trader % pBzWnd->hashVal;\
        if(pBzWnd->ppTraderData[nTmp])\
        {\
        strcpy(bzResponse.BSSTraderName, ((traderData*)pBzWnd->ppTraderData[nTmp])->name);\
        }\
        }

        _BazaarSearchResponsePacket bzResponse;
        memset(&bzResponse, 0, sizeof(bzrItemData));
        NetStream ns((BYTE*)bz->pData, bz->nSize);
        _BAZAARSEARCHWND *pBzWnd = *((_BAZAARSEARCHWND**)pinstCBazaarSearchWnd);
        DWORD nIndex = 0;

        DWORD nTrader           = ns.readUInt32();
        DWORD wTmp              = ns.readUInt16();
        DWORD nTmp              = ns.readUInt32();
        BzCount                 = ns.readUInt32();
        DWORD nTrader1          = ns.readUInt32();
        string sTmp             = ns.readText();
        bzResponse.BSSPrice     = ns.readUInt32();
        bzResponse.BSSQuantity  = ns.readUInt32();
        bzResponse.BSSItemID    = ns.readUInt32();
        DWORD nIcon             = ns.readUInt32();
        sTmp                    = ns.readText();
        nTmp                    = ns.readUInt32();

        strcpy(bzResponse.BSSName, sTmp.c_str());

        SetTraderName(nTrader1);

        memcpy(&BzArray[nIndex++], &bzResponse, sizeof(_BazaarSearchResponsePacket));

        while(nIndex < BzCount)
        {
            memset(&bzResponse, 0, sizeof(bzrItemData));

            nTrader                 = ns.readUInt32();
            wTmp                    = ns.readUInt16();
            nTmp                    = ns.readUInt32();
            nTmp                    = ns.readUInt32();
            nTrader1                = ns.readUInt32();
            sTmp                    = ns.readText();
            bzResponse.BSSPrice     = ns.readUInt32();
            bzResponse.BSSQuantity  = ns.readUInt32();
            bzResponse.BSSItemID    = ns.readUInt32();
            nIcon                   = ns.readUInt32();
            sTmp                    = ns.readText();
            nTmp                    = ns.readUInt32();

            strcpy(bzResponse.BSSName, sTmp.c_str());

            SetTraderName(nTrader);

            memcpy(&BzArray[nIndex++], &bzResponse, sizeof(_BazaarSearchResponsePacket));
        }

        BzDone = TRUE;

        BzTrampoline(bz);
    };
};

DETOUR_TRAMPOLINE_EMPTY(VOID BzSrchHook::BzTrampoline(bzrData *));

class MQ2BazaarType *pBazaarType=0;
class MQ2BazaarItemType *pBazaarItemType=0;

class MQ2BazaarItemType : public MQ2Type
{
public:
    enum BazaarItemMembers
    {
        Price=1,
        Quantity=2,
        ItemID=3,
        Trader=4,
        Name=6,
    };

    MQ2BazaarItemType():MQ2Type("bazaaritem") {
        TypeMember(Price);
        TypeMember(Quantity);
        TypeMember(ItemID);
        TypeMember(Trader);
        TypeMember(Name);
    }
    ~MQ2BazaarItemType() {
    }

    bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest) {
        if (!VarPtr.Ptr)
            return false;
#define pBzrItem ((_BazaarSearchResponsePacket*)VarPtr.Ptr)
        PMQ2TYPEMEMBER pMember=MQ2BazaarItemType::FindMember(Member);
        if (!pMember)
            return false;
        switch((BazaarItemMembers)pMember->ID)
        {
        case Price:
            Dest.DWord=pBzrItem->BSSPrice;
            Dest.Type=pIntType;
            return true;
        case Quantity:
            Dest.DWord=pBzrItem->BSSQuantity;
            Dest.Type=pIntType;
            return true;
        case ItemID:
            Dest.DWord=pBzrItem->BSSItemID;
            Dest.Type=pIntType;
            return true;
        case Trader:
            if (Dest.Ptr=GetSpawnByName(pBzrItem->BSSTraderName)) {
                Dest.Type=pSpawnType;
                return true;
            }
            return false;
        case Name:
            strcpy(DataTypeTemp, &pBzrItem->BSSName[0]);
            if (PCHAR ptr = strrchr(DataTypeTemp,'('))
                *ptr = '\0';
            Dest.Ptr=&DataTypeTemp[0];
            Dest.Type=pStringType;
            return true;
        }

        return false;
#undef pBzrItem
    }

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination) {
        if (!VarPtr.Ptr)
            return false;
        strcpy(Destination,((_BazaarSearchResponsePacket*)VarPtr.Ptr)->BSSName);
        if (PCHAR ptr = strrchr(Destination,'('))
            *ptr = '\0';
        return true;
    }
    void InitVariable(MQ2VARPTR &VarPtr) {
        VarPtr.Ptr=malloc(sizeof(_BazaarSearchResponsePacket));
        ZeroMemory(VarPtr.Ptr,sizeof(_BazaarSearchResponsePacket));
    }
    void FreeVariable(MQ2VARPTR &VarPtr) {
        free(VarPtr.Ptr);
    }

    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source) {
        if (Source.Type!=pBazaarItemType)
            return false;
        memcpy(VarPtr.Ptr,Source.Ptr,sizeof(_BazaarSearchResponsePacket));
        return true;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source) {
        return false;
    }
};

class MQ2BazaarType : public MQ2Type
{
public:
    enum BazaarMembers
    {
        Count=1,
        Done=2,
        Item=3,
        Pricecheckdone=4,
        Pricecheck=5
    };

    MQ2BazaarType():MQ2Type("bazaar") {
        TypeMember(Count);
        TypeMember(Done);
        TypeMember(Item);
        TypeMember(Pricecheckdone);
        TypeMember(Pricecheck);
    }
    ~MQ2BazaarType() {
    }

    bool GetMember(MQ2VARPTR VarPtr, PCHAR Member, PCHAR Index, MQ2TYPEVAR &Dest) {
        unsigned int isnumber = 1;
        PMQ2TYPEMEMBER pMember=MQ2BazaarType::FindMember(Member);
        if (!pMember)
            return false;
        switch((BazaarMembers)pMember->ID)
        {
        case Count:
            Dest.DWord=BzCount;
            Dest.Type=pIntType;
            return true;
        case Done:
            Dest.DWord=BzDone;
            Dest.Type=pBoolType;
            return true;
        case Item:
            unsigned int i;
            if (Index[0]) {
                // check if the index is an array index
                // or an item name
                for (i=0;i<strlen(Index);i++) {
                    if (!isdigit(Index[i])) {
                        isnumber = 0;
                        break;
                    }
                }

                if (isnumber) {
                    unsigned long N=atoi(Index);
                    if (!N) 
                        return false;
                    N--;
                    if (N>BzCount)
                        return false;
                    Dest.Ptr=&BzArray[N];
                    Dest.Type=pBazaarItemType;
                    return true;
                }
                else {
                    for(i=0;i<BzCount;i++) {
                        int len = strrchr(&BzArray[i].BSSName[0],'(') - &BzArray[i].BSSName[0];
                        if (!strncmp(Index, &BzArray[i].BSSName[0], len)) {
                            Dest.Ptr=&BzArray[i];
                            Dest.Type=pBazaarItemType;
                            return true;
                        }
                    }
                }
            }
            return false;
        case Pricecheckdone:
            if (pg_Item && pg_Item->ItemNumber)
                Dest.DWord=1;
            else
                Dest.DWord=0;
            Dest.Type=pBoolType;
            return true;
        case Pricecheck:
            Dest.DWord=pg_Item->Cost;
            Dest.Type=pIntType;
            return true;
        }
        return false;
    }

    bool ToString(MQ2VARPTR VarPtr, PCHAR Destination) {
        if (BzDone)
            strcpy(Destination,"TRUE");
        else
            strcpy(Destination,"FALSE");
        return true;
    }

    bool FromData(MQ2VARPTR &VarPtr, MQ2TYPEVAR &Source) {
        return false;
    }
    bool FromString(MQ2VARPTR &VarPtr, PCHAR Source) {
        return false;
    }
};

// Called once, when the plugin is to initialize
PLUGIN_API VOID InitializePlugin(VOID)
{
    DebugSpewAlways("Initializing MQ2Bzsrch");

    LoadMQ2Plugin("MQ2ItemDisplay");
    HMODULE h = LoadLibrary("MQ2ItemDisplay.dll");
    if (!h) {
        pg_Item = NULL;
    }
    else {
        pg_Item = (ITEMINFO *)GetProcAddress(h, "g_Item");
    }
    FreeLibrary(h);

    // Add commands, macro parameters, hooks, etc.
    AddCommand("/bzsrch",BzSrchMe);
    AddCommand("/breset",BzSrchMe);
    AddCommand("/mq2bzsrch",MQ2BzSrch);
    //AddCommand("/pricecheck",bzpc);
    AddMQ2Data("Bazaar",dataBazaar);              // cc - added, but not using TLO yet

    EzDetour(CBazaarSearchWnd__HandleBazaarMsg,&BzSrchHook::BzDetour,&BzSrchHook::BzTrampoline);
    pBazaarType = new MQ2BazaarType;
    pBazaarItemType = new MQ2BazaarItemType;
}


// Called once, when the plugin is to shutdown
PLUGIN_API VOID ShutdownPlugin(VOID)
{
    DebugSpewAlways("Shutting down MQ2Bzsrch");

    // Remove commands, macro parameters, hooks, etc.
    RemoveDetour(CBazaarSearchWnd__HandleBazaarMsg);
    RemoveMQ2Data("Bazaar");
    //RemoveCommand("/pricecheck");
    RemoveCommand("/mq2bzsrch");
    RemoveCommand("/breset");
    RemoveCommand("/bzsrch");
    delete pBazaarType;
    delete pBazaarItemType;
}


VOID MQ2BzSrch(PSPAWNINFO pChar, PCHAR szLine)
{
    WriteChatColor("Bazaar Search Plugin by DKAA",USERCOLOR_WHO);
    WriteChatColor("",USERCOLOR_WHO);
    WriteChatColor("usage: /bzsrch [params] [name]",USERCOLOR_WHO);
    WriteChatColor("    params:",USERCOLOR_WHO);
    WriteChatColor("    [race any|barbarian|dark elf|dwarf|erudite|froglok|gnome|half elf|halfling|high elf|human|iksar|ogre|troll|vah shir|wood elf]",USERCOLOR_WHO);
    WriteChatColor("    [class any|bard|beastlord|berserkers|cleric|druid|enchanter|magician|monk|necromancer|paladin|ranger|rogue|shadow knight|shaman|warrior|wizard]", USERCOLOR_WHO);
    WriteChatColor("    [stat any|armor class|agility|charisma|dexterity|intelligence|stamina|strength|wisdom|vs cold|vs disease|vs fire|vs magic|vs poison|hit points|mana]", USERCOLOR_WHO);
    WriteChatColor("    [slot  any|ammo|arms|back|charm|chest|ear|face|feet|fingers|hands|head|legs|neck|primary|range|secondary|shoulders|waist|wrist]", USERCOLOR_WHO);
    WriteChatColor("    [type  any|1h slashing|1h blunt|2h blunt|2h slashing|2h piercing|alcohol|all effects|armor|arrow|bandages|book|bow|brass instrument|combinable|drink|flowing thought|focus effect|food|haste|jewelry|key|light|martial|misc|note|percussion instrument|piercing|potion|scroll|shield|stringed instrument|throwing|wind instrument]", USERCOLOR_WHO);
    WriteChatColor("    [price <low> <high>]", USERCOLOR_WHO);
    WriteChatColor("", USERCOLOR_WHO);
    WriteChatColor("values are returned in $bazaar variable", USERCOLOR_WHO);
    WriteChatColor("$bazaar -- TRUE if there are search results", USERCOLOR_WHO);
    WriteChatColor("$bazaar[count] -- number of search results", USERCOLOR_WHO);
    WriteChatColor("$bazaar[n,name] -- name of the nth item", USERCOLOR_WHO);
    WriteChatColor("$bazaar[n,price] -- price of the nth item", USERCOLOR_WHO);
    WriteChatColor("$bazaar[n,id] -- id of the nth item", USERCOLOR_WHO);
    WriteChatColor("$bazaar[n,trader] -- trader id of the nth item", USERCOLOR_WHO);
}


VOID bzpc(PSPAWNINFO pChar, PCHAR szLine)
{
    CHAR szArg[MAX_STRING] = {0};
    int index;
    struct _pc
    {
        /* 0x00 */ int id;
        /* 0x04 */ int flags;
        /* 0x08 */ char name[0x40];
        /* 0x48 */
    } pc;

    return;

    GetArg(szArg,szLine,1);
    index = atoi(szArg)-1;
    char *ptr;
    pc.id = BzArray[index].BSSItemID;
    pc.flags = 0;                                 // column where click occured; must be 0 or 1
    strncpy(pc.name, BzArray[index].BSSName, 64);
    if (ptr = strrchr(pc.name, '('))
        *ptr = '\0';
    if (pg_Item) memset(pg_Item, 0, sizeof(ITEMINFO));
    DebugSpewAlways("id = %d, name = %s\n", pc.id, pc.name);
    // this opcode is in CProgSelWnd__WndNotification
    //SendEQMessage(EQ_BAZAARSEARCHCREATE, &pc, sizeof(pc));
}


VOID BzSrchMe(PSPAWNINFO pChar, PCHAR szLine)
{
    struct _BazaarSearchRequestPacket bsrp;
    CHAR szArg[MAX_STRING] = {0};
    PCHARINFO pCharInfo = GetCharInfo();
    BOOL bArg = TRUE;
    int i, first = 1;

    // don't do anything but reset the count and the done flag

    BzCount = 0;
    BzDone = 0;

    return;

    // clear out the old list or the new entries will be
    // added to them
    // this offset is in doQuery and SortItemList
    class CListWnd *ptr = *(class CListWnd **) ((char *)pBazaarSearchWnd+0x3d08);
    ptr->DeleteAll();

    // default to current race and class
    bsrp.BSRCommand = 7;
    bsrp.BSRTraderID = 0;
    bsrp.BSRClass = GetCharInfo2()->Class;
    bsrp.BSRRace = GetCharInfo2()->Race;
    bsrp.BSRStat = -1;
    bsrp.BSRSlot = -1;
    bsrp.BSRType = -1;
    memset(bsrp.BSRName, 0, 60);
    bsrp.BSRPriceH = 0;
    bsrp.BSRPriceL = 0;
    bsrp.BSRLevelH = 75;
    bsrp.BSRLevelL = 1;

    while(bArg) {
        GetArg(szArg,szLine,1);
        szLine = GetNextArg(szLine, 1);
        if (szArg[0]==0) {
            bArg = FALSE;
        }
        else if (!strcmp(szArg, "class")) {
            GetArg(szArg,szLine,1);
            szLine = GetNextArg(szLine, 1);
            if (szArg[0]==0) {
                MacroError("Bad class name.");
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
                MacroError("Bad class name.");
                goto error_out;
            }
        }
        else if (!strcmp(szArg, "race")) {
            GetArg(szArg,szLine,1);
            szLine = GetNextArg(szLine, 1);
            if (szArg[0]==0) {
                MacroError("Bad race name.");
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
                MacroError("Bad race name.");
                goto error_out;
            }
        }
        else if (!strcmp(szArg, "stat")) {
            GetArg(szArg,szLine,1);
            szLine = GetNextArg(szLine, 1);
            if (szArg[0]==0) {
                MacroError("Bad stat name.");
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
                MacroError("Bad stat name.");
                goto error_out;
            }
        }
        else if (!strcmp(szArg, "slot")) {
            GetArg(szArg,szLine,1);
            szLine = GetNextArg(szLine, 1);
            if (szArg[0]==0) {
                MacroError("Bad slot name.");
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
                MacroError("Bad slot name.");
                goto error_out;
            }
        }
        else if (!strcmp(szArg, "type")) {
            GetArg(szArg,szLine,1);
            szLine = GetNextArg(szLine, 1);
            if (szArg[0]==0) {
                MacroError("Bad type name.");
                goto error_out;
            }
            if (isdigit(szArg[0]) && szArg[1]!='h') {
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
                MacroError("Bad type name.");
                goto error_out;
            }
        }
        else if (!strcmp(szArg, "price")) {
            GetArg(szArg,szLine,1);
            szLine = GetNextArg(szLine, 1);
            if (szArg[0]==0) {
                MacroError("Bad price low.");
                goto error_out;
            }
            bsrp.BSRPriceL = atoi(szArg);

            GetArg(szArg,szLine,1);
            szLine = GetNextArg(szLine, 1);
            if (szArg[0]==0) {
                MacroError("Bad price high.");
                goto error_out;
            }
            bsrp.BSRPriceH = atoi(szArg);
        }
        else if (!strcmp(szArg, "trader")) {
            GetArg(szArg,szLine,1);
            szLine = GetNextArg(szLine, 1);
            if (szArg[0]==0) {
                WriteChatColor("Bad trader id.",USERCOLOR_WHO);
                goto error_out;
            }
            bsrp.BSRTraderID = atoi(szArg);
        }                                         // it's a name
        else {
            if (first) {
                first = 0;
            }
            else {
                strcat(bsrp.BSRName, " ");
            }
            strcat(bsrp.BSRName, szArg);
        }
    }

    BzCount = 0;
    BzDone = 0;
    //SendEQMessage(EQ_BAZAARSEARCHME, &bsrp, sizeof(bsrp));
    return;

error_out:
    return;
}


BOOL dataBazaar(PCHAR szName, MQ2TYPEVAR &Ret)
{
    Ret.DWord=1;
    Ret.Type=pBazaarType;
    return true;
}
