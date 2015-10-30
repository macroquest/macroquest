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
HANDLE bzsrchhandle = 0;
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
} classes[] =
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
} races[] =
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
	"drakkin", 522,
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

		_BazaarSearchResponsePacket bzResponse = {0};
        //memset(&bzResponse, 0, sizeof(bzrItemData));
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

        strcpy_s(bzResponse.BSSName, sTmp.c_str());

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

            strcpy_s(bzResponse.BSSName, sTmp.c_str());

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

    bool MQ2BazaarType::GETMEMBER() {
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
	bzsrchhandle = CreateMutex(NULL, FALSE, NULL);
    DebugSpewAlways("Initializing MQ2Bzsrch");

    LoadMQ2Plugin("MQ2ItemDisplay");
    if(HMODULE h = GetModuleHandle("MQ2ItemDisplay.dll")) {
		pg_Item = (ITEMINFO *)GetProcAddress(h, "g_Item");
    } else {
        pg_Item = NULL;
    }
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
	if (bzsrchhandle) {
		ReleaseMutex(bzsrchhandle);
		CloseHandle(bzsrchhandle);
		bzsrchhandle = 0;
	}
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
	WriteChatColor("    [trader any value you see in that box or an index, remember to enclose values with spaces in them with quotes like: \"some value\"]", USERCOLOR_WHO);
	WriteChatColor("    [race any|barbarian|dark elf|dwarf|erudite|froglok|gnome|half elf|halfling|high elf|human|iksar|ogre|troll|vah shir|wood elf|drakkin]", USERCOLOR_WHO);
    WriteChatColor("    [class any|bard|beastlord|berserkers|cleric|druid|enchanter|magician|monk|necromancer|paladin|ranger|rogue|shadow knight|shaman|warrior|wizard]", USERCOLOR_WHO);
    WriteChatColor("    [stat any value you see in that box or an index, remember to enclose values with spaces in them with quotes like: \"some value\"]", USERCOLOR_WHO);
    WriteChatColor("    [slot  any value you see in that box or an index, remember to enclose values with spaces in them with quotes like: \"some value\"]", USERCOLOR_WHO);
    WriteChatColor("    [type  any value you see in that box or an index, remember to enclose values with spaces in them with quotes like: \"some value\"]", USERCOLOR_WHO);
	WriteChatColor("    [price <low> <high>]", USERCOLOR_WHO);
	WriteChatColor("    [prestige any value you see in that box or an index, remember to enclose values with spaces in them with quotes like: \"some value\"]", USERCOLOR_WHO);
	WriteChatColor("    [augment any value you see in that box or an index, remember to enclose values with spaces in them with quotes like: \"some value\"]", USERCOLOR_WHO);
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
void SetComboSelection(CSidlScreenWnd*pCombo, DWORD index) {
	CXRect comborect = ((CXWnd*)pCombo)->GetScreenRect();
	CXPoint combopt = comborect.CenterPoint();
	((CComboWnd*)pCombo)->SetChoice(index);
	((CXWnd*)pCombo)->HandleLButtonDown(&combopt, 0);
	if (CListWnd*pListWnd = (CListWnd*)pCombo->Items) {
		int index = pListWnd->GetCurSel();
		CXRect listrect = pListWnd->GetItemRect(index, 0);
		CXPoint listpt = listrect.CenterPoint();
		((CXWnd*)pListWnd)->HandleLButtonDown(&listpt, 0);
		((CXWnd*)pListWnd)->HandleLButtonUp(&listpt, 0);
		WeDidStuff();
	}
}
void DoClass(PCHAR szArg)
{
	if (szArg[0] == 0) {
		MacroError("Bad class name.");
		return;
	}
	int index = -1;
	CHAR szClass[255] = { 0 };
	if (isdigit(szArg[0])) {
		index = atoi(szArg);
		if (index == 0) {
			strcpy_s(szClass, "Any Class");
		}
		else {
			for (int i = 0; i < sizeof(classes) / sizeof(classes[0]); i++) {
				if (classes[i].classn==index) {
					strcpy_s(szClass, classes[i].name);
					break;
				}
			}
		}
	}
	else {
		for (int i = 0; i < sizeof(classes) / sizeof(classes[0]); i++) {
			if (!_stricmp(szArg, classes[i].name)) {
				strcpy_s(szClass, szArg);
				break;
			}
		}
	}
	if (szClass[0] == '\0') {
		MacroError("Bad class name.");
		return;
	}
	if (!_stricmp(szArg, "any")) {
		strcpy_s(szClass, "Any Class");
	}
	if (CComboWnd *pCombo = (CComboWnd *)pBazaarSearchWnd->GetChildItem("BZR_ClassSlotCombobox")) {
		if (CListWnd*pListWnd = (CListWnd*)pCombo->Items) {
			CXStr Str;
			CHAR szOut[255] = { 0 };
			DWORD itemcnt = pCombo->GetItemCount();
			for (DWORD i = 0; i < itemcnt; i++) {
				pListWnd->GetItemText(&Str, i, 0);
				GetCXStr(Str.Ptr, szOut, 254);
				if (szOut[0] != '\0') {
					if (!_stricmp(szClass, szOut)) {
						SetComboSelection((CSidlScreenWnd*)pCombo, i);
						break;
					}
				}
			}
		}
	}
}
void DoRace(PCHAR szArg)
{
	if (szArg[0] == 0) {
		MacroError("Bad race name.");
		return;
	}
	int index = -1;
	CHAR szRace[255] = { 0 };
	if (isdigit(szArg[0])) {
		index = atoi(szArg);
		if (index == 0) {
			strcpy_s(szRace, "Any Race");
		}
		else {
			for (int i = 0; i < sizeof(races) / sizeof(races[0]); i++) {
				if (races[i].race==index) {
					strcpy_s(szRace, races[i].name);
					break;
				}
			}
		}
	}
	else {
		for (int i = 0; i < sizeof(races) / sizeof(races[0]); i++) {
			if (!_stricmp(szArg, races[i].name)) {
				strcpy_s(szRace, szArg);
				break;
			}
		}
	}
	if (szRace[0] == '\0') {
		MacroError("Bad race name.");
		return;
	}
	if (!_stricmp(szArg, "any")) {
		strcpy_s(szRace, "Any Race");
	}
	if (CComboWnd *pCombo = (CComboWnd *)pBazaarSearchWnd->GetChildItem("BZR_RaceSlotCombobox")) {
		if (CListWnd*pListWnd = (CListWnd*)pCombo->Items) {
			CXStr Str;
			CHAR szOut[255] = { 0 };
			DWORD itemcnt = pCombo->GetItemCount();
			for (DWORD i = 0; i < itemcnt; i++) {
				pListWnd->GetItemText(&Str, i, 0);
				GetCXStr(Str.Ptr, szOut, 254);
				if (szOut[0] != '\0') {
					if (!_stricmp(szRace, szOut)) {
						SetComboSelection((CSidlScreenWnd*)pCombo, i);
						break;
					}
				}
			}
		}
	}
}

void DoCombo(PCHAR szArg, PCHAR key, PCHAR szCombostring)
{
	if (szArg[0] == 0) {
		MacroError("Bad %s name.", key);
		return;
	}
	DWORD index = -1;
	CHAR szValue[255] = { 0 };
	if (isdigit(szArg[0])) {
		index = atoi(szArg);
		index--;
	}
	if (!_stricmp(szArg, "any")) {
		sprintf_s(szValue, "Any %s",key);
	}
	else {
		strcpy_s(szValue, szArg);
	}
	if (CComboWnd *pCombo = (CComboWnd *)pBazaarSearchWnd->GetChildItem(szCombostring)) {
		if (CListWnd*pListWnd = (CListWnd*)pCombo->Items) {
			CXStr Str;
			CHAR szOut[255] = { 0 };
			DWORD itemcnt = pCombo->GetItemCount();
			if (index != -1 && index <= itemcnt) {
				SetComboSelection((CSidlScreenWnd*)pCombo, index);
			} else {
				for (DWORD i = 0; i < itemcnt; i++) {
					pListWnd->GetItemText(&Str, i, 0);
					GetCXStr(Str.Ptr, szOut, 254);
					if (szOut[0] != '\0') {
						if (!_stricmp(szValue, szOut)) {
							SetComboSelection((CSidlScreenWnd*)pCombo, i);
							break;
						}
					}
				}
			}
		}
	}
}

DWORD __stdcall searchthread(PVOID pData)
{
	lockit lk(bzsrchhandle);
	if (CSidlScreenWnd *ptr = (CSidlScreenWnd *)pBazaarSearchWnd->GetChildItem("BZR_QueryButton")) {
		ULONGLONG startwait = MQGetTickCount64();
		startwait += 5000;
		while (ptr->Enabled == 0) {
			Sleep(100);
			if (startwait < MQGetTickCount64()) {
				MacroError("timed out in /bzsrch waiting for BZR_QueryButton to enable.");
				break;
			}
		}
		if (ptr->Enabled) {
			if (CListWnd *ptr = (CListWnd *)pBazaarSearchWnd->GetChildItem("BZR_ItemList")) {
				ptr->DeleteAll();
			}
			BzCount = 0;
			BzDone = 0;
			SendWndClick2((CXWnd*)ptr, "leftmouseup");
		} else {
			MacroError("woah! hold your horses there bazaarmule... BZR_QueryButton is not enabled, I suggest you check that in your macro before you issue a /bzsrch command.");
		}
	}
	return 0;
}

VOID BzSrchMe(PSPAWNINFO pChar, PCHAR szLine)
{
	lockit lk(bzsrchhandle);

	CHAR szArg[MAX_STRING] = { 0 };
	CHAR szItem[MAX_STRING] = { 0 };
    PCHARINFO pCharInfo = GetCharInfo();
    BOOL bArg = TRUE;
	bool first = true;


	if (CButtonWnd *ptr = (CButtonWnd *)pBazaarSearchWnd->GetChildItem("BZR_Default")) {
		SendWndClick2((CXWnd*)ptr, "leftmouseup");
	}
	while (bArg) {
		GetArg(szArg, szLine, 1);
		szLine = GetNextArg(szLine, 1);
		if (szArg[0] == 0) {
			bArg = FALSE;
		} else if (!strcmp(szArg, "class")) {
			GetArg(szArg, szLine, 1);
			szLine = GetNextArg(szLine, 1);
			DoClass(szArg);
		} else if (!_stricmp(szArg, "race")) {
			GetArg(szArg, szLine, 1);
			szLine = GetNextArg(szLine, 1);
			DoRace(szArg);
		} else if (!_stricmp(szArg, "stat")) {
			GetArg(szArg, szLine, 1);
			szLine = GetNextArg(szLine, 1);
			DoCombo(szArg, "Stat", "BZR_StatSlotCombobox");
		} else if (!_stricmp(szArg, "slot")) {
			GetArg(szArg, szLine, 1);
			szLine = GetNextArg(szLine, 1);
			DoCombo(szArg, "Slot", "BZR_ItemSlotCombobox");
		} else if (!_stricmp(szArg, "type")) {
			GetArg(szArg, szLine, 1);
			szLine = GetNextArg(szLine, 1);
			DoCombo(szArg, "Type", "BZR_ItemTypeCombobox");
		} else if (!strcmp(szArg, "price")) {
			GetArg(szArg, szLine, 1);
			szLine = GetNextArg(szLine, 1);
			if (szArg[0] == 0) {
				MacroError("Bad price low.");
				goto error_out;
			}
			if (CXWnd *pEdit = (CXWnd *)pBazaarSearchWnd->GetChildItem("BZR_MinPriceInput")) {
				pEdit->SetWindowTextA(CXStr(szArg));
			}
			GetArg(szArg, szLine, 1);
			szLine = GetNextArg(szLine, 1);
			if (szArg[0] == 0) {
				MacroError("Bad price high.");
				goto error_out;
			}
			if (CXWnd *pEdit = (CXWnd *)pBazaarSearchWnd->GetChildItem("BZR_MaxPriceInput")) {
				pEdit->SetWindowTextA(CXStr(szArg));
			}
		} else if (!_stricmp(szArg, "trader")) {
			GetArg(szArg, szLine, 1);
			szLine = GetNextArg(szLine, 1);
			DoCombo(szArg, "Trader", "BZR_PlayersCombobox");
		} else if (!_stricmp(szArg, "prestige")) {
			GetArg(szArg, szLine, 1);
			szLine = GetNextArg(szLine, 1);
			DoCombo(szArg, "Prestige", "BZR_ItemPrestigeCombobox");
		} else if (!_stricmp(szArg, "augment")) {
			GetArg(szArg, szLine, 1);
			szLine = GetNextArg(szLine, 1);
			DoCombo(szArg, "Augment", "BZR_ItemAugmentCombobox");
		} else {
			if (first) {
				first = false;
			} else {
				strcat(szItem, " ");
			}
			strcat(szItem, szArg);
		}
	}
	if (CXWnd *pEdit = (CXWnd *)pBazaarSearchWnd->GetChildItem("BZR_ItemNameInput")) {
		pEdit->SetWindowTextA(CXStr(szItem));
		DWORD nThreadID = 0;
		CreateThread(NULL, NULL, searchthread, 0, 0, &nThreadID);
	}
error_out:
	return;
}


BOOL dataBazaar(PCHAR szName, MQ2TYPEVAR &Ret)
{
    Ret.DWord=1;
    Ret.Type=pBazaarType;
    return true;
}
