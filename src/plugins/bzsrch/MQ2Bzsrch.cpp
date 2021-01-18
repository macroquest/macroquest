/*
 * MacroQuest: The extension platform for EverQuest
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
// MQ2Bzsrch.cpp: Bazaar Search Plugin by DKAA
//

#include <mq/Plugin.h>

using namespace mq::datatypes;

PLUGIN_VERSION(2.0);
PreSetup("MQ2Bzsrch");

class MQ2BazaarType;
class MQ2BazaarItemType;

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

ItemDefinition* pg_Item = nullptr;                          // dependent on MQ2ItemDisplay

// Contains an item response from the bazaar search. Struct layout does not
// matter because we are constructing it ourself via CUnSerializeBuffer.
struct BazaarSearchItem
{
	int32_t     TraderID = 0;
	EqItemGuid  ItemGuid;
	uint32_t    Price = 0;
	int         Quantity = 0;
	int         ItemID = 0;
	uint32_t    IconID = 0;
	char        ItemName[0x40];
	int         StatValue = 0;

	// This isn't part of the network response -- we read this from the UI
	char        TraderName[0x40];

	BazaarSearchItem()
	{
		ItemName[0] = 0;
		TraderName[0] = 0;
	}

	void UnSerialize(CUnSerializeBuffer& buffer)
	{
		buffer.Read(TraderID);
		buffer.Read(ItemGuid);
		buffer.Read(Price);
		buffer.Read(Quantity);
		buffer.Read(ItemID);
		buffer.Read(IconID);
		buffer.ReadString(ItemName, lengthof(ItemName));
		buffer.Read(StatValue);
	}
};
std::vector<BazaarSearchItem> BazaarItemsArray;
bool BazaarSearchDone = false;
bool WaitingForSearch = false;
uint64_t NextSearchCheck = 0;

// attn: dannuic, I need a state machine
enum class SearchCheckState
{
	None, // also used as the "Done" state.
	WaitForQueryButton,
	WaitForQueryComplete,
};
SearchCheckState SearchState = SearchCheckState::None;

class CBazaarSearchWnd_Hook
{
public:
	void HandleSearchResults_Trampoline(CUnSerializeBuffer& buffer);
	void HandleSearchResults_Detour(CUnSerializeBuffer& bufferIn)
	{
		// Make a copy of the CUnSerializeBuffer so we don't spoil eq's internal tracking.
		CUnSerializeBuffer buffer(bufferIn);

		int32_t spawnId = 0;
		int16_t unk1;
		float unk2;
		int count = 0;

		buffer.Read(spawnId);
		buffer.Read(unk1);
		buffer.Read(unk2);
		buffer.Read(count);

		BazaarItemsArray.clear();
		BazaarItemsArray.resize(count);

		for (int i = 0; i < count; ++i)
		{
			BazaarSearchItem& item = BazaarItemsArray[i];
			buffer.Read(item);

			if (BazaarTraderData* trader = pBazaarSearchWnd->Traders.FindFirst(item.TraderID))
			{
				strcpy_s(item.TraderName, trader->Name);
			}
		}

		HandleSearchResults_Trampoline(bufferIn);
		BazaarSearchDone = true;
	};
};
DETOUR_TRAMPOLINE_EMPTY(void CBazaarSearchWnd_Hook::HandleSearchResults_Trampoline(CUnSerializeBuffer&));

MQ2BazaarType* pBazaarType = nullptr;
MQ2BazaarItemType* pBazaarItemType = nullptr;

class MQ2BazaarItemType : public MQ2Type
{
public:
	enum class BazaarItemMembers
	{
		Price,
		Quantity,
		ItemID,
		Trader,
		Name,
	};

	MQ2BazaarItemType() : MQ2Type("bazaaritem")
	{
		ScopedTypeMember(BazaarItemMembers, Price);
		ScopedTypeMember(BazaarItemMembers, Quantity);
		ScopedTypeMember(BazaarItemMembers, ItemID);
		ScopedTypeMember(BazaarItemMembers, Trader);
		ScopedTypeMember(BazaarItemMembers, Name);
	}

	virtual bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override
	{
		size_t index = VarPtr.DWord;
		if (index >= BazaarItemsArray.size())
			return false;
		BazaarSearchItem& item = BazaarItemsArray[index];

		MQTypeMember* pMember = MQ2BazaarItemType::FindMember(Member);
		if (!pMember)
			return false;

		switch ((BazaarItemMembers)pMember->ID)
		{
		case BazaarItemMembers::Price:
			Dest.DWord = item.Price;
			Dest.Type = pIntType;
			return true;

		case BazaarItemMembers::Quantity:
			Dest.DWord = item.Quantity;
			Dest.Type = pIntType;
			return true;

		case BazaarItemMembers::ItemID:
			Dest.DWord = item.ItemID;
			Dest.Type = pIntType;
			return true;

		case BazaarItemMembers::Trader:
			strcpy_s(DataTypeTemp, item.TraderName);
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;

		case BazaarItemMembers::Name:
			strcpy_s(DataTypeTemp, item.ItemName);
			if (char* pDest = strrchr(DataTypeTemp, '('))
				*pDest = '\0';
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		}

		return false;
	}

	virtual bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		size_t index = VarPtr.DWord;
		if (index >= BazaarItemsArray.size())
			return false;
		BazaarSearchItem& item = BazaarItemsArray[index];

		strcpy_s(Destination, MAX_STRING, item.ItemName);
		if (char* pDest = strrchr(Destination, '('))
			*pDest = '\0';

		return true;
	}

	virtual void InitVariable(MQVarPtr& VarPtr) override
	{
		VarPtr.DWord = 0;
	}

	virtual void FreeVariable(MQVarPtr& VarPtr) override
	{
	}

	virtual bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		if (Source.Type != pBazaarItemType)
			return false;

		VarPtr.DWord = Source.DWord;
		return true;
	}

	virtual bool FromString(MQVarPtr& VarPtr, const char* Source) override
	{
		return false;
	}
};

//============================================================================

class MQ2BazaarType : public MQ2Type
{
public:
	enum class BazaarMembers
	{
		Count,
		Done,
		Item,
		Pricecheckdone,
		Pricecheck
	};

	MQ2BazaarType() : MQ2Type("bazaar")
	{
		ScopedTypeMember(BazaarMembers, Count);
		ScopedTypeMember(BazaarMembers, Done);
		ScopedTypeMember(BazaarMembers, Item);
		ScopedTypeMember(BazaarMembers, Pricecheckdone);
		ScopedTypeMember(BazaarMembers, Pricecheck);
	}

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override
	{
		MQTypeMember* pMember = MQ2BazaarType::FindMember(Member);
		if (!pMember)
			return false;

		switch ((BazaarMembers)pMember->ID)
		{
		case BazaarMembers::Count:
			Dest.DWord = BazaarItemsArray.size();
			Dest.Type = pIntType;
			return true;

		case BazaarMembers::Done:
			Dest.Set(BazaarSearchDone);
			Dest.Type = pBoolType;
			return true;

		case BazaarMembers::Item:
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
					int N = GetIntFromString(Index, 0) - 1;
					if (N < 0 || N >= (int)BazaarItemsArray.size())
						return false;

					Dest.DWord = N;
					Dest.Type = pBazaarItemType;
					return true;
				}
				else
				{
					for (size_t i = 0; i < BazaarItemsArray.size(); i++)
					{
						BazaarSearchItem& item = BazaarItemsArray[i];

						int len = strrchr(&item.ItemName[0], '(') - &item.ItemName[0];
						if (!strncmp(Index, &item.ItemName[0], len))
						{
							Dest.DWord = i;
							Dest.Type = pBazaarItemType;
							return true;
						}
					}
				}
			}
			return false;

		case BazaarMembers::Pricecheckdone:
			Dest.Set(pg_Item && pg_Item->ItemNumber);
			Dest.Type = pBoolType;
			return true;

		case BazaarMembers::Pricecheck:
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
		if (BazaarSearchDone)
			strcpy_s(Destination, MAX_STRING, "TRUE");
		else
			strcpy_s(Destination, MAX_STRING, "FALSE");

		return true;
	}

	bool FromData(MQVarPtr& VarPtr, MQTypeVar& Source) override
	{
		return false;
	}

	bool FromString(MQVarPtr& VarPtr, const char* Source) override
	{
		return false;
	}

	static bool dataBazaar(const char* szName, MQTypeVar& Ret)
	{
		Ret.DWord = 1;
		Ret.Type = pBazaarType;
		return true;
	}
};

void BZQuery(SPAWNINFO* pChar, char* szLine)
{
	if (pBazaarSearchWnd && pBazaarSearchWnd->pQueryButton)
	{
		SendWndClick2(pBazaarSearchWnd->pQueryButton, "leftmouseup");
	}
}

void MQ2BzSrch(SPAWNINFO* pChar, char* szLine)
{
	WriteChatColor("Bazaar Search Plugin by DKAA", USERCOLOR_WHO);
	WriteChatColor("", USERCOLOR_WHO);
	WriteChatColor("usage: /bzsrch [params] [name]", USERCOLOR_WHO);
	WriteChatColor("params:", USERCOLOR_WHO);
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
	WriteChatColor("Results are available through the Bazaar TLO:", USERCOLOR_WHO);
	WriteChatColor("    ${Bazaar} -- TRUE if there are search results", USERCOLOR_WHO);
	WriteChatColor("    ${Bazaar.Count} -- number of search results", USERCOLOR_WHO);
	WriteChatColor("    ${Bazaar.Done} -- TRUE if search is completed", USERCOLOR_WHO);
	WriteChatColor("    ${Bazaar.Item[n].Name} -- name of the nth item", USERCOLOR_WHO);
	WriteChatColor("    ${Bazaar.Item[n].Price} -- price of the nth item", USERCOLOR_WHO);
	WriteChatColor("    ${Bazaar.Item[n].Quantity} -- quantity of the nth item", USERCOLOR_WHO);
	WriteChatColor("    ${Bazaar.Item[n].ItemID} -- id of the nth item", USERCOLOR_WHO);
	WriteChatColor("    ${Bazaar.Item[n].Trader} -- trader name of the nth item", USERCOLOR_WHO);
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
		index = GetIntFromString(szArg, index);
		if (index == 0)
		{
			strcpy_s(szClass, "Any Class");
		}
		else
		{
			for (auto& c : classes)
			{
				if (c.classn == index)
				{
					strcpy_s(szClass, c.name);
					break;
				}
			}
		}
	}
	else
	{
		for (auto& c : classes)
		{
			if (!_stricmp(szArg, c.name))
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
		index = GetIntFromString(szArg, index);
		if (index == 0)
		{
			strcpy_s(szRace, "Any Race");
		}
		else
		{
			for (auto& r : races)
			{
				if (r.race == index)
				{
					strcpy_s(szRace, r.name);
					break;
				}
			}
		}
	}
	else
	{
		for (auto& r : races)
		{
			if (!_stricmp(szArg, r.name))
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
		index = GetIntFromString(szArg, index) - 1;
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

void BzReset(SPAWNINFO* pChar, char* szLine)
{
	BazaarSearchDone = false;
	WaitingForSearch = false;
	BazaarItemsArray.clear();
}

void BzSrchMe(SPAWNINFO* pChar, char* szLine)
{
	CHARINFO* pCharInfo = GetCharInfo();
	if (!pBazaarSearchWnd || !pCharInfo)
		return;

	BazaarSearchDone = false;
	WaitingForSearch = false;
	BazaarItemsArray.clear();

	// Reset to defaults
	if (CButtonWnd* pDefaultButton = pBazaarSearchWnd->pDefaultButton)
	{
		if (pDefaultButton->IsEnabled())
		{
			SendWndClick2(pDefaultButton, "leftmouseup");
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

	// NOTE: A lot of these member variables rely on the ui structure being correct. They're
	// children defined in the XML. If there is ever trouble with keeping them updated, they
	// should be switched to look up by name via GetChildItem.
	bool first = true;
	bool bArg = true;
	char szItem[MAX_STRING] = { 0 };

	while (bArg)
	{
		char szArg[MAX_STRING] = { 0 };
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

		SearchState = SearchCheckState::None;
		WaitingForSearch = true;
		NextSearchCheck = 0;
	}
	else
	{
		MacroError("Whats wrong? couldnt find the BZR_ItemNameInput window.");
	}
}

void DoWaitingForSearchChecks()
{
	if (!pBazaarSearchWnd)
	{
		WaitingForSearch = false;
		return;
	}

	CButtonWnd* pQueryButton = pBazaarSearchWnd->pQueryButton;
	if (!pQueryButton)
	{
		MacroError("Unable to perform search, we couldnt find the BZR_QueryButton window.");

		WaitingForSearch = false;
		return;
	}

	if (NextSearchCheck != 0 && MQGetTickCount64() > NextSearchCheck)
	{
		if (SearchState == SearchCheckState::WaitForQueryButton)
			MacroError("Timed out waiting for BZR_QueryButton to be enabled to start the search. The query may not be valid.");
		else
			MacroError("Timed out waiting for /bzsrch to complete");

		WaitingForSearch = false;
		return;
	}

	switch (SearchState)
	{
	case SearchCheckState::None:
		BazaarSearchDone = false;

		if (!pQueryButton->IsEnabled())
		{
			SearchState = SearchCheckState::WaitForQueryButton;
			NextSearchCheck = MQGetTickCount64() + 7000; // 7 seconds arbitrarily
			break;
		}
		// fallthrough
	case SearchCheckState::WaitForQueryButton:
		if (pQueryButton->IsEnabled())
		{
			HideDoCommand((SPAWNINFO*)pLocalPlayer, "/bzquery", true);

			SearchState = SearchCheckState::WaitForQueryComplete;
			NextSearchCheck = MQGetTickCount64() + 2000; // 2 seconds arbitrarily
		}
		break;

	case SearchCheckState::WaitForQueryComplete:
		if (BazaarSearchDone)
		{
			WaitingForSearch = false;
			SearchState = SearchCheckState::None;
			NextSearchCheck = 0;
		}
		break;
	}
}

// Called once, when the plugin is to initialize
PLUGIN_API void InitializePlugin()
{
	// FIXME: MQ2ItemDisplay doesn't provide this functionality anymore.
#if 0
	LoadMQ2Plugin("MQ2ItemDisplay");
	if (HMODULE h = GetModuleHandle("MQ2ItemDisplay.dll"))
	{
		pg_Item = (ITEMINFO*)GetProcAddress(h, "g_Item");
	}
	else
	{
		pg_Item = nullptr;
	}
#endif

	AddCommand("/bzquery", BZQuery);
	AddCommand("/bzsrch", BzSrchMe);
	AddCommand("/breset", BzReset);
	AddCommand("/mq2bzsrch", MQ2BzSrch);
	AddMQ2Data("Bazaar", MQ2BazaarType::dataBazaar);

	EzDetourwName(CBazaarSearchWnd__HandleBazaarMsg, &CBazaarSearchWnd_Hook::HandleSearchResults_Detour, &CBazaarSearchWnd_Hook::HandleSearchResults_Trampoline, "CBazaarSearchWnd__HandleBazaarMsg");
	pBazaarType = new MQ2BazaarType;
	pBazaarItemType = new MQ2BazaarItemType;
}

// Called once, when the plugin is to shutdown
PLUGIN_API void ShutdownPlugin()
{
	RemoveDetour(CBazaarSearchWnd__HandleBazaarMsg);
	RemoveMQ2Data("Bazaar");
	RemoveCommand("/mq2bzsrch");
	RemoveCommand("/breset");
	RemoveCommand("/bzsrch");
	RemoveCommand("/bzquery");

	delete pBazaarType;
	delete pBazaarItemType;
}

PLUGIN_API void SetGameState(DWORD gamestate)
{
	// When game state changes, just clear things.
	WaitingForSearch = false;
	BazaarSearchDone = false;
	BazaarItemsArray.clear();
	NextSearchCheck = 0;
}

PLUGIN_API void OnPulse()
{
	if (WaitingForSearch)
	{
		DoWaitingForSearchChecks();
	}
}

