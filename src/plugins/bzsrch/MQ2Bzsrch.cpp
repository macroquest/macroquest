/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

//
// MQ2Bzsrch.cpp : Bazaar Search Plugin by DKAA
//
//
// Original MQ2Data update by CyberCide... but it didn't work like the rest of
//  MQ2Data so Lax redid it.
// v2.0 - Eqmule 07-22-2016 - Added string safety.
//
#include "../MQ2Plugin.h"
#include "netstream.h"

#include <mutex>

PLUGIN_VERSION(2.0);
PreSetup("MQ2Bzsrch");

class MQ2BazaarType;
class MQ2BazaarItemType;

struct BazaarSearchRequestPacket
{
/*0x00*/ int     BSRCommand;     // should be 7               -7c
/*0x04*/ int     BSRTraderID;    // default 0                 -78
/*0x08*/ int     BSRClass;       // default -1                -74
/*0x0c*/ int     BSRRace;        // default -1                -70
/*0x10*/ int     BSRStat;        // default -1                -6c
/*0x14*/ int     BSRSlot;        // default -1                -68
/*0x18*/ int     BSRType;        // default -1                -64
/*0x1c*/ char    BSRName[64];    // name                      -60
/*0x5c*/ int     BSRPriceL;      // price floor, default 0    -20
/*0x60*/ int     BSRPriceH;      // price ceiling, default 0  -1c
/*0x64*/ int     BSRLevelL;      // level low,  default 1     -18
/*0x68*/ int     BSRLevelH;      // level high, default 70    -14
/*0x6c*/
};

// size is 0xa0 4/17/08

struct BazaarSearchResponsePacket
{
/*0x00*/ int     BSSmsg;         // should be 7
/*0x04*/ int     BSSTraderID;
/*0x08*/ char    BSSTraderName[0x40];
/*0x48*/ int     BSSQuantity;
/*0x4c*/ int     BSSItemID;
/*0x50*/ int     BSSUnknown10;
/*0x54*/ int     BSSUnknown14;
/*0x58*/ char    BSSName[0x40];
/*0x98*/ int     BSSPrice;
/*0x9c*/ int     BSSValue;
/*0xa0*/
};

struct
{
	char* name;
	int classn;
} classes[] = {
	"any",              -1,
	"bard",             8,
	"beastlord",        15,
	"berserkers",       16,
	"cleric",           2,
	"druid",            6,
	"enchanter",        14,
	"magician",         13,
	"monk",             7,
	"necromancer",      11,
	"paladin",          3,
	"ranger",           4,
	"rogue",            9,
	"shadow knight",    5,
	"shaman",           10,
	"warrior",          1,
	"wizard",           12,
};

struct
{
	char* name;
	int race;
} races[] =
{
	"any",              -1,
	"barbarian",        2,
	"dark elf",         6,
	"dwarf",            8,
	"erudite",          3,
	"froglok",          15,
	"gnome",            12,
	"half elf",         7,
	"halfling",         11,
	"high elf",         5,
	"human",            1,
	"iksar",            13,
	"ogre",             10,
	"troll",            9,
	"vah shir",         14,
	"wood elf",         4,
	"drakkin",          522,
};

int BzCount = 0;
bool BzDone = false;
BazaarSearchResponsePacket BzArray[200];
ITEMINFO* pg_Item;                                // dependent on MQ2ItemDisplay
std::mutex s_bzrMutex;

void BzSrchMe(SPAWNINFO* pChar, char* szLine);
void MQ2BzSrch(SPAWNINFO* pChar, char* szLine);
void bzpc(SPAWNINFO* pChar, char* szLine);
bool dataBazaar(const char* szName, MQTypeVar& Ret);

// length is variable based on item name
struct bzrItemData
{
/*0x00*/ DWORD  nTrader;
/*0x04*/ WORD   b;
/*0x06*/ DWORD  c;  // float
/*0x0a*/ DWORD  nItems;
/*0x0e*/ DWORD  nTrader1;
/*0x12*/ char   f[0x11];
/*0x23*/ DWORD  price;
/*0x27*/ DWORD  quantity;
/*0x2b*/ DWORD  ItemID;
/*0x2f*/ DWORD  icon;
/*0x33*/ char   ItemName[0x40];
/*0x73*/ DWORD  m;
};

struct bzrData
{
	void* pData; // ptr to bzrItemData
	DWORD nSize; // size of bzrItemData
	DWORD nPos;  // store position
};

struct traderData
{
	DWORD a;
	DWORD b;
	DWORD c;
	char  name[0x40];
};

class BzSrchHook
{
public:
	void BzTrampoline(bzrData* bz);
	void BzDetour(bzrData* bz)
	{
#define SetTraderName(trader) {                                                                   \
	nTmp = trader % pBazaarSearchWnd->hashVal;                                                              \
	if (pBazaarSearchWnd->ppTraderData[nTmp]) {                                                             \
		strcpy_s(bzResponse.BSSTraderName, ((traderData*)pBazaarSearchWnd->ppTraderData[nTmp])->name);      \
	}                                                                                             \
}

		BazaarSearchResponsePacket bzResponse = { 0 };
		NetStream ns((BYTE*)bz->pData, bz->nSize);

		int nIndex = 0;
		DWORD nTrader = ns.readUInt32();
		DWORD wTmp = ns.readUInt16();
		DWORD nTmp = ns.readUInt32();
		BzCount = ns.readInt32();
		DWORD nTrader1 = ns.readUInt32();
		std::string sTmp = ns.readText();
		bzResponse.BSSPrice = ns.readUInt32();
		bzResponse.BSSQuantity = ns.readUInt32();
		bzResponse.BSSItemID = ns.readUInt32();
		DWORD nIcon = ns.readUInt32();
		sTmp = ns.readText();
		nTmp = ns.readUInt32();

		strcpy_s(bzResponse.BSSName, sTmp.c_str());

		SetTraderName(nTrader1);

		memcpy(&BzArray[nIndex++], &bzResponse, sizeof(BazaarSearchResponsePacket));

		while (nIndex < BzCount)
		{
			memset(&bzResponse, 0, sizeof(bzrItemData));

			nTrader = ns.readUInt32();
			wTmp = ns.readUInt16();
			nTmp = ns.readUInt32();
			nTmp = ns.readUInt32();
			nTrader1 = ns.readUInt32();
			sTmp = ns.readText();
			bzResponse.BSSPrice = ns.readUInt32();
			bzResponse.BSSQuantity = ns.readUInt32();
			bzResponse.BSSItemID = ns.readUInt32();
			nIcon = ns.readUInt32();
			sTmp = ns.readText();
			nTmp = ns.readUInt32();

			strcpy_s(bzResponse.BSSName, sTmp.c_str());

			SetTraderName(nTrader);

			memcpy(&BzArray[nIndex++], &bzResponse, sizeof(BazaarSearchResponsePacket));
		}
		BzTrampoline(bz);
		BzDone = true;
	};
};
DETOUR_TRAMPOLINE_EMPTY(void BzSrchHook::BzTrampoline(bzrData *));

MQ2BazaarType* pBazaarType = nullptr;
MQ2BazaarItemType* pBazaarItemType = nullptr;

class MQ2BazaarItemType : public MQ2Type
{
public:
	enum BazaarItemMembers
	{
		Price = 1,
		Quantity = 2,
		ItemID = 3,
		Trader = 4,
		Name = 6,
	};

	MQ2BazaarItemType() : MQ2Type("bazaaritem")
	{
		TypeMember(Price);
		TypeMember(Quantity);
		TypeMember(ItemID);
		TypeMember(Trader);
		TypeMember(Name);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override
	{
		if (!VarPtr.Ptr)
			return false;

		auto pBzrItem = (BazaarSearchResponsePacket*)VarPtr.Ptr;

		MQTypeMember* pMember = MQ2BazaarItemType::FindMember(Member);
		if (!pMember)
			return false;

		switch ((BazaarItemMembers)pMember->ID)
		{
		case Price:
			Dest.DWord = pBzrItem->BSSPrice;
			Dest.Type = pIntType;
			return true;

		case Quantity:
			Dest.DWord = pBzrItem->BSSQuantity;
			Dest.Type = pIntType;
			return true;

		case ItemID:
			Dest.DWord = pBzrItem->BSSItemID;
			Dest.Type = pIntType;
			return true;

		case Trader:
			strcpy_s(DataTypeTemp, &pBzrItem->BSSTraderName[0]);
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;

		case Name:
			strcpy_s(DataTypeTemp, &pBzrItem->BSSName[0]);
			if (char* pDest = strrchr(DataTypeTemp, '('))
				*pDest = '\0';
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		}

		return false;
	}

	bool ToString(MQVarPtr VarPtr, char* Destination)
	{
		if (!VarPtr.Ptr)
			return false;

		strcpy_s(Destination, MAX_STRING, ((BazaarSearchResponsePacket*)VarPtr.Ptr)->BSSName);
		if (char* pDest = strrchr(Destination, '('))
			*pDest = '\0';

		return true;
	}

	void InitVariable(MQVarPtr& VarPtr)
	{
		VarPtr.Ptr = malloc(sizeof(BazaarSearchResponsePacket));
		VarPtr.HighPart = 0;
		ZeroMemory(VarPtr.Ptr, sizeof(BazaarSearchResponsePacket));
	}

	void FreeVariable(MQVarPtr& VarPtr)
	{
		free(VarPtr.Ptr);
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
	{
		if (Source.Type != pBazaarItemType)
			return false;
		memcpy(VarPtr.Ptr, Source.Ptr, sizeof(BazaarSearchResponsePacket));
		return true;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source)
	{
		return false;
	}
};

class MQ2BazaarType : public MQ2Type
{
public:
	enum BazaarMembers
	{
		Count = 1,
		Done = 2,
		Item = 3,
		Pricecheckdone = 4,
		Pricecheck = 5
	};

	MQ2BazaarType() : MQ2Type("bazaar")
	{
		TypeMember(Count);
		TypeMember(Done);
		TypeMember(Item);
		TypeMember(Pricecheckdone);
		TypeMember(Pricecheck);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override
	{
		MQTypeMember* pMember = MQ2BazaarType::FindMember(Member);
		if (!pMember)
			return false;

		switch ((BazaarMembers)pMember->ID)
		{
		case Count:
			Dest.DWord = BzCount;
			Dest.Type = pIntType;
			return true;

		case Done:
			Dest.DWord = BzDone ? 1 : 0;
			Dest.Type = pBoolType;
			return true;

		case Item:
			if (Index[0])
			{
				bool isNumber = true;

				// check if the index is an array index
				// or an item name
				for (uint32_t i = 0; i < strlen(Index); i++)
				{
					if (!isdigit(Index[i]))
					{
						isNumber = false;
						break;
					}
				}

				if (isNumber)
				{
					int N = atoi(Index) - 1;
					if (N < 0 || N >= BzCount)
						return false;
					Dest.Ptr = &BzArray[N];
					Dest.Type = pBazaarItemType;
					return true;
				}
				else
				{
					for (int i = 0; i < BzCount; i++)
					{
						int len = strrchr(&BzArray[i].BSSName[0], '(') - &BzArray[i].BSSName[0];
						if (!strncmp(Index, &BzArray[i].BSSName[0], len))
						{
							Dest.Ptr = &BzArray[i];
							Dest.Type = pBazaarItemType;
							return true;
						}
					}
				}
			}
			return false;

		case Pricecheckdone:
			if (pg_Item && pg_Item->ItemNumber)
				Dest.DWord = 1;
			else
				Dest.DWord = 0;
			Dest.Type = pBoolType;
			return true;

		case Pricecheck:
			if (!pg_Item)
				return false;
			Dest.DWord = pg_Item->Cost;
			Dest.Type = pIntType;
			return true;
		}
		return false;
	}

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		if (BzDone)
			strcpy_s(Destination, MAX_STRING, "TRUE");
		else
			strcpy_s(Destination, MAX_STRING, "FALSE");

		return true;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		return false;
	}

	bool FromString(MQVarPtr& VarPtr, char* Source) override
	{
		return false;
	}
};

void BZQuery(SPAWNINFO* pChar, char* szLine)
{
	if (pBazaarSearchWnd && pBazaarSearchWnd->pQueryButton)
	{
		SendWndClick2(pBazaarSearchWnd->pQueryButton, "leftmouseup");
	}
}

// Called once, when the plugin is to initialize
PLUGIN_API void InitializePlugin()
{
	LoadMQ2Plugin("MQ2ItemDisplay");

	if (HMODULE h = GetModuleHandle("MQ2ItemDisplay.dll"))
	{
		pg_Item = (ITEMINFO*)GetProcAddress(h, "g_Item");
	}
	else
	{
		pg_Item = nullptr;
	}

	// Add commands, macro parameters, hooks, etc.
	AddCommand("/bzquery", BZQuery);
	AddCommand("/bzsrch", BzSrchMe);
	AddCommand("/breset", BzSrchMe);
	AddCommand("/mq2bzsrch", MQ2BzSrch);
	AddMQ2Data("Bazaar", dataBazaar);              // cc - added, but not using TLO yet

	EzDetourwName(CBazaarSearchWnd__HandleBazaarMsg, &BzSrchHook::BzDetour, &BzSrchHook::BzTrampoline, "CBazaarSearchWnd__HandleBazaarMsg");
	pBazaarType = new MQ2BazaarType;
	pBazaarItemType = new MQ2BazaarItemType;
}

// Called once, when the plugin is to shutdown
PLUGIN_API void ShutdownPlugin()
{
	// Remove commands, macro parameters, hooks, etc.
	RemoveDetour(CBazaarSearchWnd__HandleBazaarMsg);
	RemoveMQ2Data("Bazaar");
	RemoveCommand("/mq2bzsrch");
	RemoveCommand("/breset");
	RemoveCommand("/bzsrch");
	RemoveCommand("/bzquery");

	delete pBazaarType;
	delete pBazaarItemType;
}

void MQ2BzSrch(SPAWNINFO* pChar, char* szLine)
{
	WriteChatColor("Bazaar Search Plugin by DKAA", USERCOLOR_WHO);
	WriteChatColor("", USERCOLOR_WHO);
	WriteChatColor("usage: /bzsrch [params] [name]", USERCOLOR_WHO);
	WriteChatColor("    params:", USERCOLOR_WHO);
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

void SetComboSelection(CComboWnd* pCombo, DWORD index)
{
	pCombo->SetChoice(index);
	pCombo->HandleLButtonDown(pCombo->GetScreenRect().CenterPoint(), 0);

	if (CListWnd* pListWnd = pCombo->pListWnd)
	{
		CXPoint listpt = pListWnd->GetItemRect(pListWnd->GetCurSel(), 0).CenterPoint();
		pListWnd->HandleLButtonDown(listpt, 0);
		pListWnd->HandleLButtonUp(listpt, 0);
		WeDidStuff();
	}
}

void SetComboSelection(CComboWnd* pCombo, const char* str)
{
	if (auto pListWnd = pCombo->pListWnd)
	{
		int itemCount = pCombo->GetItemCount();
		for (int i = 0; i < itemCount; ++i)
		{
			if (!_stricmp(str, pListWnd->GetItemText(i, 0).c_str()))
			{
				SetComboSelection(pCombo, i);
				break;
			}
		}
	}
}

void DoClass(char* szArg)
{
	if (szArg[0] == 0)
	{
		MacroError("Bad class name.");
		return;
	}

	int index = -1;
	char szClass[255] = { 0 };

	if (isdigit(szArg[0]))
	{
		index = atoi(szArg);
		if (index == 0)
		{
			strcpy_s(szClass, "Any Class");
		}
		else
		{
			for (size_t i = 0; i < lengthof(classes); i++)
			{
				if (classes[i].classn == index)
				{
					strcpy_s(szClass, classes[i].name);
					break;
				}
			}
		}
	}
	else
	{
		for (size_t i = 0; i < lengthof(classes); i++)
		{
			if (!_stricmp(szArg, classes[i].name))
			{
				strcpy_s(szClass, szArg);
				break;
			}
		}
	}

	if (szClass[0] == '\0')
	{
		MacroError("Bad class name.");
		return;
	}

	if (!_stricmp(szArg, "any"))
	{
		strcpy_s(szClass, "Any Class");
	}
	
	if (auto pCombo = pBazaarSearchWnd->pClassSlotCombobox)
	{
		SetComboSelection(pCombo, szClass);
	}
}

void DoRace(char* szArg)
{
	if (szArg[0] == 0)
	{
		MacroError("Bad race name.");
		return;
	}

	int index = -1;
	char szRace[255] = { 0 };
	if (isdigit(szArg[0]))
	{
		index = atoi(szArg);
		if (index == 0)
		{
			strcpy_s(szRace, "Any Race");
		}
		else
		{
			for (size_t i = 0; i < lengthof(races); i++)
			{
				if (races[i].race == index)
				{
					strcpy_s(szRace, races[i].name);
					break;
				}
			}
		}
	}
	else
	{
		for (size_t i = 0; i < lengthof(races); i++)
		{
			if (!_stricmp(szArg, races[i].name))
			{
				strcpy_s(szRace, szArg);
				break;
			}
		}
	}

	if (szRace[0] == '\0')
	{
		MacroError("Bad race name.");
		return;
	}

	if (!_stricmp(szArg, "any"))
	{
		strcpy_s(szRace, "Any Race");
	}

	if (auto pCombo = pBazaarSearchWnd->pRaceSlotCombobox)
	{
		SetComboSelection(pCombo, szRace);
	}
}

void DoCombo(CComboWnd* pCombo, const char* szArg, const char* key)
{
	if (szArg[0] == 0)
	{
		MacroError("Bad %s name.", key);
		return;
	}

	int index = -1;
	char szValue[255] = { 0 };

	if (isdigit(szArg[0]))
	{
		index = atoi(szArg) - 1;
	}
	if (!_stricmp(szArg, "any"))
	{
		sprintf_s(szValue, "Any %s", key);
	}
	else
	{
		strcpy_s(szValue, szArg);
	}

	if (pCombo)
	{
		if (index != -1 && index <= pCombo->GetItemCount())
		{
			SetComboSelection(pCombo, index);
		}
		else
		{
			SetComboSelection(pCombo, szValue);
		}
	}
}

DWORD __stdcall searchthread(void* pData)
{
	std::unique_lock<std::mutex> lock(s_bzrMutex);

	if (auto pQueryButton = pBazaarSearchWnd->pQueryButton)
	{
		uint64_t startwait = MQGetTickCount64() + 7000;

		while (pQueryButton->IsEnabled() == 0)
		{
			Sleep(0);

			if (startwait < MQGetTickCount64())
			{
				WriteChatf("1. timed out in /bzsrch waiting for BZR_QueryButton to enable.");
				break;
			}
		}

		if (pQueryButton->IsEnabled())
		{
			HideDoCommand((SPAWNINFO*)pLocalPlayer, "/bzquery", true);

			startwait = MQGetTickCount64() + 2000;

			while (pQueryButton && pQueryButton->IsEnabled() == 0 && !BzDone)
			{
				Sleep(0);

				if (startwait < MQGetTickCount64())
				{
					break;
				}
			}

			if (!BzDone)
			{
				BzDone = true;
			}
		}
		else
		{
			WriteChatf("woah! hold your horses there bazaarmule... BZR_QueryButton is not enabled, I suggest you check that in your macro before you issue a /bzsrch command.");
		}
	}
	else
	{
		WriteChatf("Whats wrong? couldnt find the BZR_QueryButton window.");
	}

	return 0;
}

void BzSrchMe(SPAWNINFO* pChar, char* szLine)
{
	std::unique_lock<std::mutex> lock(s_bzrMutex);

	BzDone = false;
	char szArg[MAX_STRING] = { 0 };
	char szItem[MAX_STRING] = { 0 };
	CHARINFO* pCharInfo = GetCharInfo();
	bool bArg = true;
	bool first = true;

	if (CButtonWnd* pDefaultButton = pBazaarSearchWnd->pDefaultButton)
	{
		if (pDefaultButton->IsEnabled())
		{
			SendWndClick2((CXWnd*)pDefaultButton, "leftmouseup");
		}
		else
		{
			MacroError("Whats wrong? BZR_Default wasnt enabled.");
		}
	}
	else
	{
		MacroError("Whats wrong? Counldnt find the BZR_Default window.");
	}

	if (CListWnd* pList = (CListWnd*)pBazaarSearchWnd->GetChildItem("BZR_ItemList"))
	{
		pList->DeleteAll();
	}

	BzCount = 0;

	while (bArg)
	{
		GetArg(szArg, szLine, 1);
		szLine = GetNextArg(szLine, 1);

		if (szArg[0] == 0)
		{
			bArg = false;
		}
		else if (!strcmp(szArg, "class"))
		{
			GetArg(szArg, szLine, 1);
			szLine = GetNextArg(szLine, 1);
			DoClass(szArg);
		}
		else if (!_stricmp(szArg, "race"))
		{
			GetArg(szArg, szLine, 1);
			szLine = GetNextArg(szLine, 1);
			DoRace(szArg);
		}
		else if (!_stricmp(szArg, "stat"))
		{
			GetArg(szArg, szLine, 1);
			szLine = GetNextArg(szLine, 1);
			DoCombo(pBazaarSearchWnd->pStatSlotCombobox, szArg, "Stat");
		}
		else if (!_stricmp(szArg, "slot"))
		{
			GetArg(szArg, szLine, 1);
			szLine = GetNextArg(szLine, 1);
			DoCombo(pBazaarSearchWnd->pItemSlotCombobox, szArg, "Slot");
		}
		else if (!_stricmp(szArg, "type"))
		{
			GetArg(szArg, szLine, 1);
			szLine = GetNextArg(szLine, 1);
			DoCombo(pBazaarSearchWnd->pItemTypeCombobox, szArg, "Type");
		}
		else if (!strcmp(szArg, "price"))
		{
			GetArg(szArg, szLine, 1);
			szLine = GetNextArg(szLine, 1);
			if (szArg[0] == 0)
			{
				MacroError("Bad price low.");
				return;
			}

			if (CEditWnd* pEdit = pBazaarSearchWnd->pMinPriceInput)
			{
				pEdit->SetWindowText(szArg);
			}

			GetArg(szArg, szLine, 1);
			szLine = GetNextArg(szLine, 1);

			if (szArg[0] == 0)
			{
				MacroError("Bad price high.");
				return;
			}

			if (CEditWnd* pEdit = pBazaarSearchWnd->pMaxPriceInput)
			{
				pEdit->SetWindowText(szArg);
			}
		}
		else if (!_stricmp(szArg, "trader"))
		{
			GetArg(szArg, szLine, 1);
			szLine = GetNextArg(szLine, 1);
			DoCombo(pBazaarSearchWnd->pPlayersCombobox, szArg, "Trader");
		}
		else if (!_stricmp(szArg, "prestige"))
		{
			GetArg(szArg, szLine, 1);
			szLine = GetNextArg(szLine, 1);
			DoCombo(pBazaarSearchWnd->pItemPrestigeCombobox, szArg, "Prestige");
		}
		else if (!_stricmp(szArg, "augment"))
		{
			GetArg(szArg, szLine, 1);
			szLine = GetNextArg(szLine, 1);
			DoCombo(pBazaarSearchWnd->pItemAugmentCombobox, szArg, "Augment");
		}
		else
		{
			if (first)
			{
				first = false;
			}
			else
			{
				strcat_s(szItem, " ");
			}

			strcat_s(szItem, szArg);
		}
	}

	if (CEditWnd* pMaxEdit = pBazaarSearchWnd->pMaxResultsPerTraderInput)
	{
		pMaxEdit->SetWindowText("200");
	}
	else
	{
		MacroError("Whats wrong? couldnt find the BZR_MaxResultsPerTraderInput window.");
	}

	if (CEditWnd* pEdit = pBazaarSearchWnd->pItemNameInput)
	{
		pEdit->SetWindowText(szItem);
		DWORD nThreadID = 0;
		CreateThread(NULL, NULL, searchthread, 0, 0, &nThreadID);
	}
	else
	{
		MacroError("Whats wrong? couldnt find the BZR_ItemNameInput window.");
	}
}

bool dataBazaar(const char* szName, MQTypeVar& Ret)
{
	Ret.DWord = 1;
	Ret.Type = pBazaarType;
	return true;
}
