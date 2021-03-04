/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2021 MacroQuest Authors
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

#include <mq/Plugin.h>
#include "resource.h"

#include <shellapi.h>
#include <fmt/format.h>

#include <mutex>
#include <string_view>
#include <fstream>

using namespace mq::datatypes;

PreSetup("MQ2ItemDisplay");

// starting position of link text found in MQ2Web__ParseItemLink_x
constexpr int LINK_LEN = 90;
constexpr int MAX_ITEMDISPLAY_WINDOWS = 6;

char ConvertFrom[MAX_STRING] = { 0 };
char ConvertTo[MAX_STRING] = { 0 };
bool bDisabledComparetip = false;
bool gCompareTip = false;
bool gLootButton = true;
bool gLucyButton = true;
std::recursive_mutex s_mutex;
const char* TipWndXML = "MQUI_CompareTipWnd.xml";

struct ButtonInfo
{
	CItemDisplayWnd* ItemDisplayWnd;
	int              ID;
};

std::map<CButtonWnd*, ButtonInfo> ButtonMap;

void Comment(SPAWNINFO* pChar, char* szLine);

struct DisplayItemStrings
{
	// this item is placeable in yards, guild yard, etc, This item can be used in tradeskills
	std::string ItemInfo;
	std::string WindowTitle;
	std::string ItemAdvancedLoreText;
	std::string ItemMadeByText;

	// Item Information: Placing this augment into <*>, this armor can only be used in <*>
	std::string ItemInformationText;
	bool bCollected = false;
	bool bCollectedRecieved = false;
	bool bScribed = false;
	bool bScribedRecieved = false;
};

// Keep data about the last 6 items displayed
ItemPtr gContents[MAX_ITEMDISPLAY_WINDOWS];
DisplayItemStrings gContentsItemStrings[MAX_ITEMDISPLAY_WINDOWS];
int gLastIndex = 5;

class MQ2DisplayItemType;
MQ2DisplayItemType* pDisplayItemType = nullptr;

class MQ2DisplayItemType : public MQ2Type
{
public:
	enum DisplayItemMembers
	{
		Info = 1,
		WindowTitle = 2,
		AdvancedLore = 3,
		MadeBy = 4,
		CollectedRecieved = 5,
		Collected = 6,
		ScribedRecieved = 7,
		Scribed = 8,
		Information = 9,
		DisplayIndex = 10,
	};

	enum DisplayItemMethods
	{
		AddLootFilter = 1,
	};

	MQ2DisplayItemType() : MQ2Type("DisplayItem")
	{
		TypeMember(Info);
		TypeMember(WindowTitle);
		TypeMember(AdvancedLore);
		TypeMember(MadeBy);
		TypeMember(CollectedRecieved);
		TypeMember(Collected);
		TypeMember(ScribedRecieved);
		TypeMember(Scribed);
		TypeMember(Information);
		TypeMember(DisplayIndex);

		TypeMethod(AddLootFilter);
	}

	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override
	{
		const int index = std::clamp<int>(VarPtr.DWord, 0, MAX_ITEMDISPLAY_WINDOWS - 1);
		ItemPtr pContents = gContents[index];

		if (!pContents)
			return false;

		MQTypeMember* pMethod = MQ2DisplayItemType::FindMethod(Member);

		if (pMethod)
		{
			Dest.Set(false);
			Dest.Type = pBoolType;

			switch (static_cast<DisplayItemMethods>(pMethod->ID))
			{
			case AddLootFilter:
				if (ItemDefinition* pItem = pContents->GetItemDefinition())
				{
					pLootFiltersManager->AddItemLootFilter(pItem->ItemNumber, pItem->IconNumber, pItem->Name, 5);

					WriteChatf("Added %s to AG and Roll LootFilters.", pItem->Name);
					Dest.Set(true);
				}
				break;

			default: break;
			}
			return true;
		}

		MQTypeMember* pMember = MQ2DisplayItemType::FindMember(Member);
		if (!pMember)
		{
			MQVarPtr varPtr;
			varPtr.Ptr = pContents.get();

			return pItemType->GetMember(varPtr, Member, Index, Dest);
		}

		if (pMember)
		{
			switch ((DisplayItemMembers)pMember->ID)
			{
			case Info:
				strcpy_s(DataTypeTemp, gContentsItemStrings[index].ItemInfo.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;
			case WindowTitle:
				strcpy_s(DataTypeTemp, gContentsItemStrings[index].WindowTitle.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;
			case AdvancedLore:
				strcpy_s(DataTypeTemp, gContentsItemStrings[index].ItemAdvancedLoreText.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;
			case MadeBy:
				strcpy_s(DataTypeTemp, gContentsItemStrings[index].ItemMadeByText.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;
			case Collected:
				Dest.Set(gContentsItemStrings[index].bCollected);
				Dest.Type = pBoolType;
				return true;
			case CollectedRecieved:
				Dest.Set(gContentsItemStrings[index].bCollectedRecieved);
				Dest.Type = pBoolType;
				return true;
			case Scribed:
				Dest.Set(gContentsItemStrings[index].bScribed);
				Dest.Type = pBoolType;
				return true;
			case ScribedRecieved:
				Dest.Set(gContentsItemStrings[index].bScribedRecieved);
				Dest.Type = pBoolType;
				return true;
			case Information:
				strcpy_s(DataTypeTemp, gContentsItemStrings[index].ItemInformationText.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;
			case DisplayIndex:
				Dest.DWord = gLastIndex;
				Dest.Type = pIntType;
				return true;
			}
		}
		return false;
	}

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		const int index = std::clamp<int>(VarPtr.DWord, 0, MAX_ITEMDISPLAY_WINDOWS - 1);
		ItemPtr pContents = gContents[index];

		if (pContents)
		{
			if (ItemDefinition* pItem = pContents->GetItemDefinition())
			{
				strcpy_s(Destination, 128, pItem->Name);
				return true;
			}
		}

		strcpy_s(Destination, 128, gContentsItemStrings[index].WindowTitle.c_str());
		return true;
	}
};

bool dataLastItem(const char* szName, MQTypeVar& Ret)
{
	std::scoped_lock lock(s_mutex);

	int index = gLastIndex;

	if (szName[0])
	{
		if (IsNumber(szName))
		{
			index = atoi(szName);
			if (index < 0 || index >= MAX_ITEMDISPLAY_WINDOWS)
				return false;
		}
	}

	Ret.DWord = index;
	Ret.Type = pDisplayItemType;
	return true;
}

// ***************************************************************************
// Function:    ItemDisplayHook
// Description: Our Item display hook
// ***************************************************************************

// Don't ever directly reference this. We don't know when it might get deleted. We only use
// this to check if the current tooltip item has changed.
ItemClient* gpOldTooltipItem = nullptr;

class CCompareTipWnd : public CSidlScreenWnd
{
public:
	CCompareTipWnd() : CSidlScreenWnd(nullptr, "CompareTipWnd", -1, 1, nullptr)
	{
		CreateChildrenFromSidl();
		SetEscapable(false);
		SetFaded(true);
		SetZLayer(100);
		SetAlpha(0xfa);
		SetBGColor(0xFF000000);
		SetBGType(1);
		SetClickThrough(true);

		Display = (CStmlWnd*)GetChildItem("CT_Display");
	}

	~CCompareTipWnd()
	{
	}

	int WndNotification(CXWnd* pWnd, unsigned int Message, void* data) override
	{
		return CSidlScreenWnd::WndNotification(pWnd, Message, data);
	}

/*0x218*/ CStmlWnd* Display;
};
CCompareTipWnd* pCompareTipWnd = nullptr;

int CanIUseThisItem(ItemDefinition* pItem)
{
	if (PcProfile* pProfile = GetPcProfile())
	{
		if (!pProfile->Class)
			return -1;
		DWORD ClassMask = (1 << (pProfile->Class - 1));
		if ((ClassMask & pItem->Classes) == 0)
			return -2;
		return 1;
	}
	return -1;
}

template <unsigned int _Size>
char* GetSlots(ItemDefinition* pItem, char(&_Buffer)[_Size])
{
	DWORD cmp = pItem->EquipSlots;
	for (int N = 0; N < 32; N++)
	{
		if (cmp & (1 << N))
		{
			strcat_s(_Buffer, _Size, szItemSlot[N]);
			strcat_s(_Buffer, _Size, " ");
		}
	}
	return _Buffer;
}

// Returns an item that is equipped in the same slot as this item. Does not
// account for cases where the item could be placed into multiple slots.
ItemPtr GetItemEquippedInSlot(const ItemPtr& pItem)
{
	PcProfile* pProfile = GetPcProfile();
	ItemDefinition* pItemDef = pItem->GetItemDefinition();

	for (int slot = InvSlot_FirstWornItem; slot <= InvSlot_LastWornItem; slot++)
	{
		if (pItemDef->EquipSlots & (1 << slot))
		{
			if (ItemPtr pSlotItem = pProfile->GetInventorySlot(slot))
				return pSlotItem;
		}
	}

	return nullptr;
}

static void UpdateCompareWindow(ItemClient* pCont, ItemClient* pEquipped);

class ItemDisplayHook
{
	enum SEffectType { None = 0, Clicky, Proc, Worn, Focus, Scroll, Focus2, Mount, Illusion, Familiar };

	static bool bNoSpellTramp;
	static SEffectType eEffectType;

public:
	int GetDmgBonus(const CXStr& Str) const
	{
		size_t dmgbonuspos = std::string_view::npos;
		int dmgbonus = 0;
		size_t badcharpos = std::string_view::npos;

		char ActualDmgBonus[3];
		std::string_view ItemDisplay = Str;

		dmgbonuspos = ItemDisplay.find("Dmg Bonus:");

		if (dmgbonuspos != std::string_view::npos)
		{
			dmgbonuspos = dmgbonuspos + 11;
			ItemDisplay = ItemDisplay.substr(dmgbonuspos, 3);

			badcharpos = ItemDisplay.find(" ");

			if (badcharpos != std::string_view::npos)
			{
				// found blank
				ItemDisplay = ItemDisplay.substr(0, 2);
			}
			else
			{
				// badcharpos = tmpActualDmgBonus.find("<");
				badcharpos = ItemDisplay.find("<");
				if (badcharpos != std::string_view::npos)
				{
					// found <
					ItemDisplay = ItemDisplay.substr(0, 2);
				}
			}

			std::string displayCopy{ ItemDisplay };
			strcpy_s(ActualDmgBonus, displayCopy.c_str());

			dmgbonus = GetIntFromString(ActualDmgBonus, 0);
		}

		return dmgbonus;
	}

	static void GetEffectInfo(const SEffectType effect, std::string& Color, std::string& Name)
	{
			if(Color.empty())
			{
				Color = "FF0000";
			}
			if(Name.empty())
			{
				// Is "Blub" significant or just known nonsense?
				Name = "Blub";
			}

			switch (eEffectType)
			{
			case Clicky:
				Color = "00FF00";
				Name = "Clicky";
				break;
			case Proc:
				Color = "FF00FF";
				Name = "Proc";
				break;
			case Worn:
				Color = "FFFF00";
				Name = "Worn";
				break;
			case Focus:
			case Focus2:
				Color = "9F9F00";
				Name = "Focus";
				break;
			case Scroll:
				Color = "9F9F9F";
				Name = "Scroll";
				break;
			case Mount:
				Color = "00FF00";
				Name = "Mount";
				break;
			case Illusion:
				Color = "00FF00";
				Name = "Illusion";
				break;
			case Familiar:
				Color = "00FF00";
				Name = "Familiar";
				break;
			case None:
				Name = "None";
				break;
			default:
				break;
			}
	}

	void SetSpell_Trampoline(int SpellID, bool bFullInfo);
	void SetSpell_Detour(int SpellID, bool bFullInfo)
	{
		CSpellDisplayWnd* pThis = reinterpret_cast<CSpellDisplayWnd*>(this);
		CHARINFO* pCharInfo = GetCharInfo();

		if (pCharInfo == nullptr) return;

		EQ_Spell* pSpell = GetSpellByID(SpellID);
		if (pSpell == nullptr)
		{
			return;
		}

		char out[MAX_STRING * 2] = { 0 };
		char temp[MAX_STRING] = { 0 };

		if (!bNoSpellTramp)
		{
			SetSpell_Trampoline(SpellID, bFullInfo);
			strcat_s(out, "<BR><c \"#00FFFF\">");
		}
		else
		{
			std::string cColour = "FF0000";
			std::string cName = "Blub";
			GetEffectInfo(eEffectType, cColour, cName);
			sprintf_s(temp, "<BR><c \"#%s\">Spell Info for %s effect: %s<br>", cColour.data(), cName.data(), pSpell->Name);
			strcat_s(out, temp);
		}

		sprintf_s(temp, "ID: %04d&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;", pSpell->ID);
		strcat_s(out, temp);

		DWORD Tics = GetSpellDuration(pSpell, pLocalPlayer);
		if (Tics == 0xFFFFFFFF)
			strcat_s(out, "Duration: Permanent<br>");
		else if (Tics == 0xFFFFFFFE)
			strcat_s(out, "Duration: Unknown<br>");
		else if (Tics == 0)
		{
			// It's "instant", who cares?
			strcat_s(out, "<br>");
		}
		else
		{
			sprintf_s(temp, "Duration: %1.1f minutes<br>", (float)((Tics * 6.0f) / 60.0f));
			strcat_s(out, temp);
		}

		sprintf_s(temp, "RecoveryTime: %1.2f&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RecastTime: %1.2f <br>", (float)(pSpell->RecoveryTime / 1000.0f), (float)(pSpell->RecastTime / 1000.0f));
		strcat_s(out, temp);

		if (pSpell->Range > 0.0f)
		{
			sprintf_s(temp, "Range: %1.0f", pSpell->Range);
			strcat_s(out, temp);
			if (pSpell->PushBack == 0.0f && pSpell->AERange == 0.0f)
				strcat_s(out, "<br>");
		}

		if (pSpell->PushBack != 0.0f)
		{
			if (pSpell->Range > 0.0f)
				strcat_s(out, "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
			sprintf_s(temp, "PushBack: %1.1f", pSpell->PushBack);
			strcat_s(out, temp);
			if (pSpell->AERange == 0.0f || pSpell->Range > 0.0f)
				strcat_s(out, "<br>");
		}

		if (pSpell->AERange > 0.0f)
		{
			if (pSpell->Range > 0.0f)
				strcat_s(out, "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
			else if (pSpell->PushBack > 0.0f)
				strcat_s(out, "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
			sprintf_s(temp, "AERange: %1.0f<br>", pSpell->AERange);
			strcat_s(out, temp);
		}

		if (pSpell->TargetType != 0x06 && pSpell->TargetType != 0x0e && pSpell->TargetType != 0x03 && pSpell->TargetType != 0x28 && pSpell->TargetType != 0x29)
		{
			if (pSpell->SpellType == 0)
			{
				// Ziggy: Only show resist type for detrimental spells
				switch (pSpell->Resist)
				{
				case 9: strcat_s(out, "Resist: Corruption"); break;
				case 7: strcat_s(out, "Resist: Prismatic[Avg]"); break; // Ziggy - Added Reminder which..
				case 6: strcat_s(out, "Resist: Chromatic[Low]"); break; // ..is what type of resist
				case 5: strcat_s(out, "Resist: Disease"); break;
				case 4: strcat_s(out, "Resist: Poison"); break;
				case 3: strcat_s(out, "Resist: Cold/Ice"); break;
				case 2: strcat_s(out, "Resist: Fire"); break;
				case 1: strcat_s(out, "Resist: Magic"); break;
				case 0: strcat_s(out, "Resist: Unresistable"); break;
				default: break;
				}

				if (pSpell->ResistAdj != 0)
				{
					sprintf_s(temp, "&nbsp;&nbsp;&nbsp;(Resist Adj.: %d)<br>", pSpell->ResistAdj);
					strcat_s(out, temp);
				}
				else
				{
					strcat_s(out, "<br>");
				}
			}
		}

		if (pSpell->HateGenerated)
		{
			sprintf_s(temp, "Hate Generated: %d<br>", pSpell->HateGenerated);
			strcat_s(out, temp);
		}

		strcat_s(out, "<br>");
		int outlen = strlen(out);
		ShowSpellSlotInfo(pSpell, &out[outlen], sizeof(out) - outlen);

		// show usable classes routine by Koad//
		bool bUseableClasses = false;
		strcat_s(out, "<br>");
		for (int j = Warrior; j <= Berserker; j++)
		{
			// Ziggy - output will word wrap properly now
			if (pSpell->GetSpellLevelNeeded(j) > 0 && pSpell->GetSpellLevelNeeded(j) <= MAX_PC_LEVEL)
			{
				if (bUseableClasses) strcat_s(out, ", ");

				sprintf_s(temp, "%s(%d)", GetClassDesc(j), pSpell->GetSpellLevelNeeded(j));
				strcat_s(out, temp);
				bUseableClasses = true;
			}
		}

		if (bUseableClasses) strcat_s(out, "<br><br>");

		if (const char* str = GetSpellString(pSpell->ID, 2))
		{
			sprintf_s(temp, "Cast on you: %s<br>", str);
			strcat_s(out, temp);
		}

		if (const char* str = GetSpellString(pSpell->ID, 3))
		{
			sprintf_s(temp, "Cast on another: %s<br>", str);
			strcat_s(out, temp);
		}

		if (const char* str = GetSpellString(pSpell->ID, 4))
		{
			sprintf_s(temp, "Wears off: %s<br>", str);
			strcat_s(out, temp);
		}

		if (int cat = GetSpellCategory(pSpell))
		{
			if (const char* ptr = pCDBStr->GetString(cat, eSpellCategory))
			{
				sprintf_s(temp, "Category: %s<br>", ptr);
				strcat_s(out, temp);
			}
		}

		if (int cat = GetSpellSubcategory(pSpell))
		{
			if (const char* ptr = pCDBStr->GetString(cat, eSpellCategory))
			{
				sprintf_s(temp, "Subcategory: %s<br>", ptr);
				strcat_s(out, temp);
			}
		}

		sprintf_s(temp, "Book Icon: %d<br>", pSpell->BookIcon);
		strcat_s(out, temp);
		sprintf_s(temp, "Gem Icon: %d<br>", pSpell->GemIcon);
		strcat_s(out, temp);
		sprintf_s(temp, "Spell Icon: %d<br>", pSpell->SpellIcon);
		strcat_s(out, temp);

		if (out[0] != 17)
		{
			strcat_s(out, "</c>");
			pThis->DescriptionText.Append(out);
		}
	}

	void ItemSetSpell_Detour(ITEMSPELLS Effect)
	{
		CItemDisplayWnd* pThis = reinterpret_cast<CItemDisplayWnd*>(this);
		CHARINFO* pCharInfo = GetCharInfo();

		if (!pCharInfo) return;

		SPELL* pSpell = GetSpellByID(Effect.SpellID);
		if (pSpell == nullptr)
		{
			return;
		}

		char out[MAX_STRING * 2] = { 0 };
		char temp[MAX_STRING] = { 0 };

		if (!bNoSpellTramp)
		{
			SetSpell_Trampoline(Effect.SpellID, false);
			strcat_s(out, "<BR><c \"#00FFFF\">");
		}
		else
		{
			std::string cColour = "FF0000";
			std::string cName = "Blub";

            GetEffectInfo(eEffectType, cColour, cName);
			char aliased[MAX_STRING] = { 0 };
			sprintf_s(aliased, "%s%s", Effect.OtherName, " (aliased)");
			sprintf_s(temp, "<BR><c \"#%s\">Spell Info for %s effect: %s<br>", cColour.data(), cName.data(), Effect.OtherName[0] ? aliased : pSpell->Name);
			strcat_s(out, temp);

			if (strstr(pThis->ItemInfo.c_str(), out))
			{
				return;
			}
		}

		sprintf_s(temp, "ID: %04d&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;", pSpell->ID);
		strcat_s(out, temp);

		DWORD Tics = GetSpellDuration(pSpell, pLocalPlayer);
		if (Tics == 0xFFFFFFFF)
			strcat_s(out, "Duration: Permanent<br>");
		else if (Tics == 0xFFFFFFFE)
			strcat_s(out, "Duration: Unknown<br>");
		else if (Tics == 0)
		{
			// It's "instant", who cares?
			strcat_s(out, "<br>");
		}
		else
		{
			sprintf_s(temp, "Duration: %1.1f minutes<br>", (float)((Tics * 6.0f) / 60.0f));
			strcat_s(out, temp);
		}

		sprintf_s(temp, "RecoveryTime: %1.2f&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;RecastTime: %1.2f <br>", (float)(pSpell->RecoveryTime / 1000.0f), (float)(pSpell->RecastTime / 1000.0f));
		strcat_s(out, temp);

		if (pSpell->Range > 0.0f)
		{
			sprintf_s(temp, "Range: %1.0f", pSpell->Range);
			strcat_s(out, temp);
			if (pSpell->PushBack == 0.0f && pSpell->AERange == 0.0f)
				strcat_s(out, "<br>");
		}

		if (pSpell->PushBack != 0.0f)
		{
			if (pSpell->Range > 0.0f)
				strcat_s(out, "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
			sprintf_s(temp, "PushBack: %1.1f", pSpell->PushBack);
			strcat_s(out, temp);
			if (pSpell->AERange == 0.0f || pSpell->Range > 0.0f)
				strcat_s(out, "<br>");
		}

		if (pSpell->AERange > 0.0f)
		{
			if (pSpell->Range > 0.0f)
				strcat_s(out, "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
			else if (pSpell->PushBack > 0.0f)
				strcat_s(out, "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
			sprintf_s(temp, "AERange: %1.0f<br>", pSpell->AERange);
			strcat_s(out, temp);
		}

		if (pSpell->TargetType != 0x06 && pSpell->TargetType != 0x0e && pSpell->TargetType != 0x03 && pSpell->TargetType != 0x28 && pSpell->TargetType != 0x29)
		{
			if (pSpell->SpellType == 0)
			{
				// Ziggy: Only show resist type for detrimental spells
				switch (pSpell->Resist)
				{
				case 9: strcat_s(out, "Resist: Corruption"); break;
				case 7: strcat_s(out, "Resist: Prismatic[Avg]"); break; // Ziggy - Added Reminder which..
				case 6: strcat_s(out, "Resist: Chromatic[Low]"); break; // ..is what type of resist
				case 5: strcat_s(out, "Resist: Disease"); break;
				case 4: strcat_s(out, "Resist: Poison"); break;
				case 3: strcat_s(out, "Resist: Cold/Ice"); break;
				case 2: strcat_s(out, "Resist: Fire"); break;
				case 1: strcat_s(out, "Resist: Magic"); break;
				case 0: strcat_s(out, "Resist: Unresistable"); break;
				}

				if (pSpell->ResistAdj != 0)
				{
					sprintf_s(temp, "&nbsp;&nbsp;&nbsp;(Resist Adj.: %d)<br>", pSpell->ResistAdj);
					strcat_s(out, temp);
				}
				else
				{
					strcat_s(out, "<br>");
				}
			}
		}

		if (pSpell->HateGenerated)
		{
			sprintf_s(temp, "Hate Generated: %d<br>", pSpell->HateGenerated);
			strcat_s(out, temp);
		}

		strcat_s(out, "<br>");
		int outlen = strlen(out);
		ShowSpellSlotInfo(pSpell, &out[outlen], sizeof(out) - outlen);

		// show usable classes routine by Koad//
		bool bUseableClasses = false;
		strcat_s(out, "<br>");
		for (int j = Warrior; j <= Berserker; j++)
		{
			// Ziggy - output will word wrap properly now
			if (pSpell->GetSpellLevelNeeded(j) > 0 && pSpell->GetSpellLevelNeeded(j) <= MAX_PC_LEVEL)
			{
				if (bUseableClasses) strcat_s(out, ", ");

				sprintf_s(temp, "%s(%d)", GetClassDesc(j), pSpell->GetSpellLevelNeeded(j));
				strcat_s(out, temp);
				bUseableClasses = true;
			}
		}

		if (bUseableClasses) strcat_s(out, "<br><br>");

		if (const char* str = GetSpellString(pSpell->ID, 2))
		{
			sprintf_s(temp, "Cast on you: %s<br>", str);
			strcat_s(out, temp);
		}

		if (const char* str = GetSpellString(pSpell->ID, 3))
		{
			sprintf_s(temp, "Cast on another: %s<br>", str);
			strcat_s(out, temp);
		}

		if (const char* str = GetSpellString(pSpell->ID, 4))
		{
			sprintf_s(temp, "Wears off: %s<br>", str);
			strcat_s(out, temp);
		}

		if (out[0] != 17)
		{
			strcat_s(out, "</c>");
			pThis->ItemInfo += out;
		}
	}

	void UpdateStrings_Trampoline();
	void UpdateStrings_Detour()
	{
		CItemDisplayWnd* pThis = reinterpret_cast<CItemDisplayWnd*>(this);
		int index = pThis->ItemWndIndex;
		if (index >= MAX_ITEMDISPLAY_WINDOWS || index < 0)
		{
			index = 0;
			WriteChatf("Tell eqmule his PEQITEMWINDOW struct is wrong");
		}

		ItemPtr& item = pThis->pItem;
		ItemDefinition* Item = item->GetItemDefinition();

		UpdateStrings_Trampoline();
		std::scoped_lock lock(s_mutex);

		// add the strings to our map
		gContentsItemStrings[index].ItemInformationText  = STMLToText(pThis->ItemInformationText);
		gContentsItemStrings[index].ItemInfo             = STMLToText(pThis->ItemInfo);
		gContentsItemStrings[index].ItemMadeByText       = STMLToText(pThis->ItemMadeByText);
		gContentsItemStrings[index].ItemAdvancedLoreText = STMLToText(pThis->ItemAdvancedLoreText);
		gContentsItemStrings[index].WindowTitle          = STMLToText(pThis->WindowTitle);

		if (pThis->bCollectedReceived)
		{
			gContentsItemStrings[index].bCollectedRecieved = true;
			gContentsItemStrings[index].bCollected = pThis->bCollected;
		}
		else
		{
			gContentsItemStrings[index].bCollectedRecieved = false;
			gContentsItemStrings[index].bCollected = false;
		}

		if (pThis->bScribedReceived)
		{
			gContentsItemStrings[index].bScribedRecieved = true;
			gContentsItemStrings[index].bScribed = pThis->bScribed;
		}
		else
		{
			gContentsItemStrings[index].bScribedRecieved = false;
			gContentsItemStrings[index].bScribed = false;
		}

		gContents[index] = item;
		gLastIndex = index;

		char out[MAX_STRING * 2] = { 0 };
		strcpy_s(out, "<BR><c \"#00FFFF\">");

		char temp[MAX_STRING] = { 0 };

		if (Item->ItemNumber > 0)
		{
			sprintf_s(temp, "Item ID: %d<br>", Item->ItemNumber);
			strcat_s(out, temp);
		}

		if (Item->ItemNumber > 0)
		{
			sprintf_s(temp, "Icon ID: %d<br>", Item->IconNumber);
			strcat_s(out, temp);
		}

		// TODO: Add injection point for additional stats

		if (item->IsStackable())
		{
			if (Item->StackSize > 0)
			{
				sprintf_s(temp, "Stackable Count: %d<br>", Item->StackSize);
				strcat_s(out, temp);
			}
		}

		if (Item->Cost > 0)
		{
			int cp = Item->Cost;
			int sp = cp / 10; cp = cp % 10;
			int gp = sp / 10; sp = sp % 10;
			int pp = gp / 10; gp = gp % 10;

			strcat_s(out, "Value:");
			if (pp > 0)
			{
				sprintf_s(temp, " %dpp", pp);
				strcat_s(out, temp);
			}

			if (gp > 0)
			{
				sprintf_s(temp, " %dgp", gp);
				strcat_s(out, temp);
			}

			if (sp > 0)
			{
				sprintf_s(temp, " %dsp", sp);
				strcat_s(out, temp);
			}

			if (cp > 0)
			{
				sprintf_s(temp, " %dcp", cp);
				strcat_s(out, temp);
			}

			strcat_s(out, "<BR>");
		}

		if (Item->Favor > 0)
		{
			sprintf_s(temp, "Tribute Value: %d<br>", Item->Favor);
			strcat_s(out, temp);
		}

		if (Item->GuildFavor > 0)
		{
			sprintf_s(temp, "Guild Tribute Value: %d<br>", Item->GuildFavor);
			strcat_s(out, temp);
		}

		if (Item->Clicky.TimerID != 0)
		{
			int Secs = GetItemTimer(item.get());

			if (!Secs)
			{
				sprintf_s(temp, "Item Timer: <c \"#20FF20\">Ready</c><br>");
			}
			else
			{
				int Mins = (Secs / 60) % 60;
				int Hrs = (Secs / 3600);
				Secs = Secs % 60;

				if (Hrs)
					sprintf_s(temp, "Item Timer: %d:%02d:%02d<br>", Hrs, Mins, Secs);
				else
					sprintf_s(temp, "Item Timer: %d:%02d<br>", Mins, Secs);
			}

			strcat_s(out, temp);
		}

		// Outlaw (AKA CheckinThingsOut) (02/24/2005)
		if (Item->ItemType != 27)
		{
			// Arrows..they have dmg/dly but we don't want them
			if (Item->Delay > 0)
			{
				if (Item->Damage > 0)
				{
					sprintf_s(temp, "Ratio: %5.3f<br>", (float)Item->Delay / (float)Item->Damage);
					strcat_s(out, temp);

					// Calculate Efficiency
					int dmgbonus = 0;

					if (PcProfile* pProfile = GetPcProfile())
					{
						if (pProfile->Level > 27 && !pThis->ItemInfo.empty())
						{
							// bonus is 0 for anything below 28
							dmgbonus = GetDmgBonus(pThis->ItemInfo);
						}
					}

					sprintf_s(temp, "Efficiency: %3.0f<br>", ((((float)Item->Damage * 2) + dmgbonus) / (float)Item->Delay) * 50);
					strcat_s(out, temp);

					if (Item->EquipSlots & 16384)
					{
						// Equipable In Secondary Slot
						sprintf_s(temp, "Offhand Efficiency: %3.0f<br>", ((((float)Item->Damage * 2) / (float)Item->Delay) * 50) * 0.62);
						strcat_s(out, temp);
					}

					sprintf_s(temp, "<br>");
					strcat_s(out, temp);
				}
			}
		}

		char* lore = Item->LoreName;
		if (lore[0] == '*') lore++;

		if (strcmp(lore, Item->Name))
		{
			sprintf_s(temp, "Item Lore: %s<BR>", Item->LoreName);
			strcat_s(out, temp);
		}

		// Ziggy - for item level highlights
		// Will be 0 for no effect or -1 if other effects present
		if (Item->Proc.SpellID && Item->Proc.SpellID != -1)
		{
			if (Item->Proc.RequiredLevel == 0)
			{
				sprintf_s(temp, "Procs at level 1 (Proc rate modifier: %d)<BR>", Item->Proc.ProcRate);
			}
			else
			{
				if (PcProfile* pProfile = GetPcProfile())
				{
					sprintf_s(temp, "%sProcs at level %d%s (Proc rate modifier: %d)<BR>", (Item->Proc.RequiredLevel > pProfile->Level ? "<c \"#FF4040\">" : ""), Item->Proc.RequiredLevel, (Item->Proc.RequiredLevel > pProfile->Level ? "</C>" : ""), Item->Proc.ProcRate);
				}
			}
			strcat_s(out, temp);
		}

		// Just in case...
		if (!strstr(pThis->ItemInfo.c_str(), "(Combat)") && Item->Proc.ProcRate > 0)
		{
			sprintf_s(temp, "Proc rate Modifier: %d<BR>", Item->Proc.ProcRate);
			strcat_s(out, temp);
		}

		// Teh_Ish (02/08/2004)
		if (Item->Clicky.EffectType == 4 || Item->Clicky.EffectType == 1 || Item->Clicky.EffectType == 5)
		{
			if (Item->Clicky.RequiredLevel == 0)
			{
				sprintf_s(temp, "Clickable at level 1<br>");
			}
			else
			{
				if (PcProfile* pProfile = GetPcProfile())
				{
					sprintf_s(temp, "%sClickable at level %d%s<BR>", (Item->Clicky.RequiredLevel > pProfile->Level ? "<c \"#FF4040\">" : ""), Item->Clicky.RequiredLevel, (Item->Clicky.RequiredLevel > pProfile->Level ? "</C>" : ""));
				}
			}

			strcat_s(out, temp);
		}

		// TheColonel (12/24/2003)
		if (Item->LDType == 1)
		{
			if (Item->LDCost == 0)
				sprintf_s(temp, "This drops in %s dungeons<BR>", GetLDoNTheme(Item->LDTheme));
			else
				sprintf_s(temp, "LDoN Cost: %d from %s<BR>", Item->LDCost, GetLDoNTheme(Item->LDTheme));
			strcat_s(out, temp);
		}

		if (Item->LDType == 2 && Item->LDCost > 0)
		{
			sprintf_s(temp, "Discord Cost: %d points<BR>", Item->LDCost);
			strcat_s(out, temp);
		}

		if (Item->LDType == 4 && Item->LDCost > 0)
		{
			sprintf_s(temp, "DoN Cost: %d Radiant Crystals<BR>", Item->LDCost);
			strcat_s(out, temp);
		}

		if (Item->LDType == 5 && Item->LDCost > 0)
		{
			sprintf_s(temp, "DoN Cost: %d Ebon Crystals<BR>", Item->LDCost);
			strcat_s(out, temp);
		}

		// TheColonel (1/18/2004)
		if (Item->Type == ITEMTYPE_PACK)
		{
			sprintf_s(temp, "Container Type: %s<BR>", szCombineTypes[Item->Combine]);
			strcat_s(out, temp);
		}

		sprintf_s(temp, "%07d", Item->ItemNumber);

		char temp2[MAX_STRING] = { 0 };
		GetPrivateProfileString("Notes", temp, "", temp2, MAX_STRING, INIFileName);
		if (strlen(temp2) > 0)
		{
			sprintf_s(temp, "Note: %s<br>", temp2);
			strcat_s(out, temp);
		}

		if (out[0] != 17)
		{
			strcat_s(out, "</c>");
			pThis->Description->AppendSTML(out);
		}
	}

	void HandleLucyButton(const ItemPtr& pItem)
	{
		if (pItem)
		{
			std::string url = fmt::format("https://lucy.allakhazam.com/item.html?id={}", pItem->GetID());
			ShellExecute(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
		}
	}

	int WndNotification_Trampoline(CXWnd*, uint32_t, void*);
	int WndNotification_Detour(CXWnd* pWnd, uint32_t Message, void* pData)
	{
		if (Message == XWM_RCLICK)
		{
			auto iter = ButtonMap.find(static_cast<CButtonWnd*>(pWnd));
			if (iter != ButtonMap.end())
			{
				ButtonInfo& buttonInfo = iter->second;

				// open in lucy
				if (buttonInfo.ID == 6)
				{
					HandleLucyButton(buttonInfo.ItemDisplayWnd->pItem);
					return 0;
				}
			}
		}
		else if (Message == XWM_LCLICK)
		{
			auto iter = ButtonMap.find(static_cast<CButtonWnd*>(pWnd));

			if (iter != ButtonMap.end())
			{
				auto& [pButton, buttonInfo] = *iter;

				// FIXME: What do these numbers mean??
				switch (buttonInfo.ID)
				{
				case 2: // Toggle the Need Loot Filter
				{
					if (pButton->bChecked)
					{
						// check need
						// uncheck 3 and 4
						for (auto& [pButton2, buttonInfo2] : ButtonMap)
						{
							if (buttonInfo2.ItemDisplayWnd == buttonInfo.ItemDisplayWnd)
							{
								if (buttonInfo2.ID == 3 || buttonInfo2.ID == 4)
								{
									pButton2->bChecked = false;
								}
							}
						}

						if (ItemDefinition* pItem = buttonInfo.ItemDisplayWnd->pItem->GetItemDefinition())
						{
							if (pLootFiltersManager)
							{
								pLootFiltersManager->SetItemLootFilter(pItem->ItemNumber, pItem->IconNumber, pItem->Name, 2, true, true);
							}
						}
					}
					else
					{
						// uncheck need
						bool bAutoRollIsChecked = false;
						for (auto& [pButton2, buttonInfo2] : ButtonMap)
						{
							if (buttonInfo2.ItemDisplayWnd == buttonInfo.ItemDisplayWnd)
							{
								if (buttonInfo2.ID == 5)
								{
									bAutoRollIsChecked = pButton2->bChecked;
									break;
								}
							}
						}

						if (ItemDefinition* pItem = buttonInfo.ItemDisplayWnd->pItem->GetItemDefinition())
						{
							if (pLootFiltersManager)
							{
								if (const ItemFilterData* pData = pLootFiltersManager->GetItemFilterData(pItem->ItemNumber))
								{
									bool bAutoRoll = (pData->Types & (1 << 0)) != 0;
									if (bAutoRoll)
									{
										pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 2);
									}
									else
									{
										pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 0);
									}
								}
								else
								{
									// its not currently in lootfilters
									if (bAutoRollIsChecked)
									{
										pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 2);
									}
									else
									{
										pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 0);
									}
								}
							}
						}
					}

					return 0;
				}

				case 3: // Toggle the Greed Loot Filter
				{
					if (pButton->bChecked)
					{
						// check greed
						// uncheck 2 and 4
						bool bAutoRollIsChecked = false;
						for (auto& [pButton2, buttonInfo2] : ButtonMap)
						{
							if (buttonInfo2.ItemDisplayWnd == buttonInfo.ItemDisplayWnd)
							{
								if (buttonInfo2.ID == 2 || buttonInfo2.ID == 4)
								{
									pButton2->bChecked = false;
								}
								else if (buttonInfo2.ID == 5)
								{
									bAutoRollIsChecked = pButton2->bChecked;
								}
							}
						}

						if (ItemDefinition* pItem = iter->second.ItemDisplayWnd->pItem->GetItemDefinition())
						{
							if (pLootFiltersManager)
							{
								pLootFiltersManager->SetItemLootFilter(pItem->ItemNumber, pItem->IconNumber, pItem->Name, 4, true, true);
							}
						}
					}
					else
					{
						// uncheck greed
						bool bAutoRollIsChecked = false;

						for (auto& [pButton2, buttonInfo2] : ButtonMap)
						{
							if (buttonInfo2.ItemDisplayWnd == buttonInfo.ItemDisplayWnd)
							{
								if (buttonInfo2.ID == 5)
								{
									bAutoRollIsChecked = pButton2->bChecked;
									break;
								}
							}
						}

						if (ItemDefinition* pItem = buttonInfo.ItemDisplayWnd->pItem->GetItemDefinition())
						{
							if (pLootFiltersManager)
							{
								if (const ItemFilterData* pData = pLootFiltersManager->GetItemFilterData(pItem->ItemNumber))
								{
									bool bAutoRoll = (pData->Types & (1 << 0)) != 0;

									if (bAutoRoll)
									{
										pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 4);
									}
									else
									{
										pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 0);
									}
								}
								else
								{
									// its not currently in lootfilters
									if (bAutoRollIsChecked)
									{
										pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 4);
									}
									else
									{
										pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 0);
									}
								}
							}
						}
					}
					return 0;
				}

				case 4: // Toggle the Never Loot Filter
				{
					if (pButton->bChecked)
					{
						// check never
						// uncheck 2 and 3
						bool bAutoRollIsChecked = false;

						for (auto& [pButton2, buttonInfo2] : ButtonMap)
						{
							if (buttonInfo2.ItemDisplayWnd == buttonInfo.ItemDisplayWnd)
							{
								if (buttonInfo2.ID == 2 || buttonInfo2.ID == 3)
								{
									pButton2->bChecked = false;
								}
								else if (buttonInfo2.ID == 5)
								{
									bAutoRollIsChecked = pButton2->bChecked;
								}
							}
						}

						if (ItemDefinition* pItem = buttonInfo.ItemDisplayWnd->pItem->GetItemDefinition())
						{
							if (pLootFiltersManager)
							{
								pLootFiltersManager->SetItemLootFilter(pItem->ItemNumber, pItem->IconNumber, pItem->Name, 8, true, true);
							}
						}
					}
					else
					{
						// uncheck never
						bool bAutoRollIsChecked = false;

						for (auto& [pButton2, buttonInfo2] : ButtonMap)
						{
							if (buttonInfo2.ItemDisplayWnd == buttonInfo.ItemDisplayWnd)
							{
								if (buttonInfo2.ID == 5)
								{
									bAutoRollIsChecked = pButton2->bChecked;
									break;
								}
							}
						}

						if (ItemDefinition* pItem = buttonInfo.ItemDisplayWnd->pItem->GetItemDefinition())
						{
							if (pLootFiltersManager)
							{
								if (const ItemFilterData* pData = pLootFiltersManager->GetItemFilterData(pItem->ItemNumber))
								{
									bool bAutoRoll = (pData->Types & (1 << 0)) != 0;

									if (bAutoRoll)
									{
										pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 8);
									}
									else
									{
										pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 0);
									}
								}
								else
								{
									// its not currently in lootfilters
									if (bAutoRollIsChecked)
									{
										pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 8);
									}
									else
									{
										pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 0);
									}
								}
							}
						}
					}
					return 0;
				}

				case 5: // Toggle the Auto Roll Loot Filter
				{
					if (pButton->bChecked)
					{
						// check autoroll
						if (ItemDefinition* pItem = buttonInfo.ItemDisplayWnd->pItem->GetItemDefinition())
						{
							if (pLootFiltersManager)
							{
								if (const ItemFilterData* pData = pLootFiltersManager->GetItemFilterData(pItem->ItemNumber))
								{
									bool bNeed = (pData->Types & (1 << 1)) != 0;
									bool bGreed = (pData->Types & (1 << 2)) != 0;
									bool bNever = (pData->Types & (1 << 3)) != 0;

									if (bNeed)
									{
										pLootFiltersManager->SetItemLootFilter(pItem->ItemNumber, pItem->IconNumber, pItem->Name, 3, false, true);
									}
									else if (bGreed)
									{
										pLootFiltersManager->SetItemLootFilter(pItem->ItemNumber, pItem->IconNumber, pItem->Name, 5, false, true);
									}
									else if (bNever)
									{
										pLootFiltersManager->SetItemLootFilter(pItem->ItemNumber, pItem->IconNumber, pItem->Name, 9, false, true);
									}
									else
									{
										pLootFiltersManager->AddItemLootFilter(pItem->ItemNumber, pItem->IconNumber, pItem->Name, 1);
									}
								}
								else
								{
									pLootFiltersManager->AddItemLootFilter(pItem->ItemNumber, pItem->IconNumber, pItem->Name, 1);
								}
							}
						}
					}
					else
					{
						// uncheck autoroll
						if (ItemDefinition* pItem = buttonInfo.ItemDisplayWnd->pItem->GetItemDefinition())
						{
							pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 1);
						}
					}
					return 0;
				}

				case 6: // open in lucy
				{
					HandleLucyButton(buttonInfo.ItemDisplayWnd->pItem);
					return 0;
				}

				default: break;
				}
			}
		}

		return WndNotification_Trampoline(pWnd, Message, pData);
	};

	bool AboutToShow_Trampoline();
	bool AboutToShow_Detour()
	{
		CItemDisplayWnd* pThis = (CItemDisplayWnd*)this;
		int index = pThis->ItemWndIndex;
		if (index > 5 || index < 0)
		{
			index = 0;
			WriteChatf("Tell eqmule his PEQITEMWINDOW struct is wrong");
		}

		ItemClient* item = pThis->pItem.get();
		ItemDefinition* Item = item->GetItemDefinition();

		// Ziggy - Items showing their spell details:
		bNoSpellTramp = true;
		if (Item->Clicky.SpellID > 0 && Item->Clicky.SpellID != -1)
		{
			eEffectType = Clicky;
			ItemSetSpell_Detour(Item->Clicky);
		}

		if (Item->Proc.SpellID > 0 && Item->Proc.SpellID != -1)
		{
			eEffectType = Proc;
			ItemSetSpell_Detour(Item->Proc);
		}

		if (Item->Worn.SpellID > 0 && Item->Worn.SpellID != -1)
		{
			eEffectType = Worn;
			ItemSetSpell_Detour(Item->Worn);
		}

		if (Item->Focus.SpellID > 0 && Item->Focus.SpellID != -1)
		{
			eEffectType = Focus;
			ItemSetSpell_Detour(Item->Focus);
		}

		if (Item->Scroll.SpellID > 0 && Item->Scroll.SpellID != -1)
		{
			eEffectType = Scroll;
			ItemSetSpell_Detour(Item->Scroll);
		}

		if (Item->Focus2.SpellID > 0 && Item->Focus2.SpellID != -1)
		{
			eEffectType = Focus2;
			ItemSetSpell_Detour(Item->Focus2);
		}

		if (Item->Mount.SpellID > 0 && Item->Mount.SpellID != -1)
		{
			eEffectType = Mount;
			ItemSetSpell_Detour(Item->Mount);
		}

		if (Item->Illusion.SpellID > 0 && Item->Illusion.SpellID != -1)
		{
			eEffectType = Illusion;
			ItemSetSpell_Detour(Item->Illusion);
		}

		if (Item->Familiar.SpellID > 0 && Item->Familiar.SpellID != -1)
		{
			eEffectType = Familiar;
			ItemSetSpell_Detour(Item->Familiar);
		}

		bNoSpellTramp = false;
		eEffectType = None;

		bool doit = false;

		// get rid of old buttons. we really should destroy them in abouttohide but i dont want another detour.
		for (auto i = ButtonMap.begin(); i != ButtonMap.end();)
		{
			if (i->second.ItemDisplayWnd == pThis)
			{
				i->first->Destroy();
				ButtonMap.erase(i++);
			}
			else
			{
				i++;
			}
		}

		// create add to loot filters button
		if (gLootButton)
		{
			CControlTemplate* btntemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("ADLW_CheckBoxTemplate");
			CControlTemplate* labeltemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("IDW_ModButtonLabel");

			if (btntemplate && labeltemplate)
			{
				uint32_t oldfont = std::exchange(labeltemplate->nFont, 1u);

				//labeltemplate->TextColor = 0xFF0094FF;
				CLabelWnd* pHeader = (CLabelWnd*)pSidlMgr->CreateXWndFromTemplate(pThis, labeltemplate);
				pHeader->SetCRNormal(0xFF0094FF);
				CButtonWnd* pAlwaysNeedBtn = (CButtonWnd*)pSidlMgr->CreateXWndFromTemplate(pThis, btntemplate);
				CButtonWnd* pAlwaysGreedBtn = (CButtonWnd*)pSidlMgr->CreateXWndFromTemplate(pThis, btntemplate);
				CButtonWnd* pNeverBtn = (CButtonWnd*)pSidlMgr->CreateXWndFromTemplate(pThis, btntemplate);
				CButtonWnd* pAutoRollBtn = (CButtonWnd*)pSidlMgr->CreateXWndFromTemplate(pThis, btntemplate);

				if (pAlwaysNeedBtn && pAlwaysGreedBtn && pNeverBtn && pAutoRollBtn && pHeader)
				{
					pHeader->SetWindowText("AN | AG | NV | AR");
					pAlwaysNeedBtn->SetTooltip("Always roll need on this item");
					pAlwaysGreedBtn->SetTooltip("Always roll greed on this item");
					pNeverBtn->SetTooltip("Never loot this item");
					pAutoRollBtn->SetTooltip("Always roll on this item");

					if (CXWnd* orgbutton = pThis->GetChildItem("IDW_ModButtonLabel"))
					{
						int spacing = 22;
						// header
						int pheader_top = orgbutton->GetLocation().top + 12;
						int pheader_bottom = pheader_top + 12;
						int pheader_left = orgbutton->GetLocation().left;

						if (CXWnd* fusebutton = pThis->GetChildItem("IDW_FuseButtonLabel"))
						{
							if (fusebutton->IsVisible())
							{
								pheader_left += 240;
							}
							else
							{
								pheader_left += 80;
							}
						}
						int pheader_right = pheader_left + 80;

						pHeader->SetLocation({ pheader_left, pheader_top, pheader_right, pheader_bottom });
						int pAlwaysNeedBtn_Location_top = orgbutton->GetLocation().top + 28;
						int pAlwaysNeedBtn_Location_bottom = pAlwaysNeedBtn_Location_top + 14;
						int pAlwaysNeedBtn_Location_left = pHeader->GetLocation().left;
						int pAlwaysNeedBtn_Location_right = pAlwaysNeedBtn_Location_left + 14;

						// always need
						pAlwaysNeedBtn->SetLocation({ pAlwaysNeedBtn_Location_left, pAlwaysNeedBtn_Location_top, pAlwaysNeedBtn_Location_right, pAlwaysNeedBtn_Location_bottom });

						// always greed
						pAlwaysGreedBtn->SetLocation({ pAlwaysNeedBtn->GetLocation().left + spacing, pAlwaysNeedBtn->GetLocation().top, pAlwaysNeedBtn->GetLocation().right + spacing, pAlwaysNeedBtn->GetLocation().bottom });

						// never
						//left top right bottom
						pNeverBtn->SetLocation({ pAlwaysGreedBtn->GetLocation().left + spacing, pAlwaysGreedBtn->GetLocation().top, pAlwaysGreedBtn->GetLocation().right + spacing, pAlwaysGreedBtn->GetLocation().bottom });

						// autoroll
						pAutoRollBtn->SetLocation({ pNeverBtn->GetLocation().left + spacing, pNeverBtn->GetLocation().top, pNeverBtn->GetLocation().right + spacing, pNeverBtn->GetLocation().bottom });
					}

					pHeader->SetData(1);
					ButtonMap[(CButtonWnd*)pHeader] = { pThis, 1 }; // wtf?

					pAlwaysNeedBtn->SetData(2);
					ButtonMap[pAlwaysNeedBtn] = { pThis, 2 };

					pAlwaysGreedBtn->SetData(3);
					ButtonMap[pAlwaysGreedBtn] = { pThis, 3 };

					pNeverBtn->SetData(4);
					ButtonMap[pNeverBtn] = { pThis, 4 };

					pAutoRollBtn->SetData(5);
					ButtonMap[pAutoRollBtn] = { pThis, 5 };

					if (ItemDefinition* pItem = pThis->pItem->GetItemDefinition())
					{
						if (pLootFiltersManager)
						{
							if (const ItemFilterData* pData = pLootFiltersManager->GetItemFilterData(pItem->ItemNumber))
							{
								bool bAutoRoll = (pData->Types & (1 << 0)) != 0;
								bool bNeed = (pData->Types & (1 << 1)) != 0;
								bool bGreed = (pData->Types & (1 << 2)) != 0;
								bool bNever = (pData->Types & (1 << 3)) != 0;

								if (bNeed)
								{
									pAlwaysNeedBtn->bChecked = true;
								}

								if (bGreed)
								{
									pAlwaysGreedBtn->bChecked = true;
								}

								if (bNever)
								{
									pNeverBtn->bChecked = true;
								}

								if (bAutoRoll)
								{
									pAutoRollBtn->bChecked = true;
								}
							}
							else
							{
								pAlwaysNeedBtn->bChecked = false;
								pAlwaysGreedBtn->bChecked = false;
								pNeverBtn->bChecked = false;
								pAutoRollBtn->bChecked = false;
							}
						}
					}
				}

				labeltemplate->nFont = oldfont;
			}
		}

		// ok now create the lucy button
		if (gLucyButton)
		{
			if (CControlTemplate* btnTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("IDW_ModButton"))
			{
				uint32_t oldfont = std::exchange(btnTemplate->nFont, 1);

				if (CButtonWnd* pBtn = (CButtonWnd*)pSidlMgr->CreateXWndFromTemplate(pThis, btnTemplate))
				{
					pBtn->SetCRNormal(0xFFFFFF00);
					pBtn->SetLocation({ 20, 10, 60, 30 });
					pBtn->SetWindowText("Lucy");
					pBtn->SetData(6);
					pBtn->SetBGColor(0xFF0000FF);
					pBtn->DecalTint = 0xFF00FFFF;
					ButtonMap[pBtn] = { pThis, 6 };
				}

				btnTemplate->nFont = oldfont;
			}
		}

		return AboutToShow_Trampoline();
	}

	int CInvSlotWnd_DrawTooltipTramp(const CXWnd* pwnd) const;
	int CInvSlotWnd_DrawTooltipDetour(const CXWnd* pwnd) const
	{
		if (!gCompareTip)
		{
			return CInvSlotWnd_DrawTooltipTramp(pwnd);
		}

		CInvSlotWnd* wnd = (CInvSlotWnd*)this;
		ItemPtr pItem = wnd->pInvSlot ? wnd->pInvSlot->GetItem() : nullptr;

		if (pItem && pItem.get() != gpOldTooltipItem)
		{
			gpOldTooltipItem = pItem.get();

			if (pCompareTipWnd && pCompareTipWnd->Display)
			{
				if (ItemPtr pEquipped = GetItemEquippedInSlot(pItem))
				{
					if (pItem != pEquipped)
					{
						UpdateCompareWindow(pItem.get(), pEquipped.get());
					}
				}
			}
		}

		return CInvSlotWnd_DrawTooltipTramp(pwnd);
	}
};

ItemDisplayHook::SEffectType ItemDisplayHook::eEffectType = None;
bool ItemDisplayHook::bNoSpellTramp = false;

DETOUR_TRAMPOLINE_EMPTY(int ItemDisplayHook::CInvSlotWnd_DrawTooltipTramp(const CXWnd* pwnd) const);
DETOUR_TRAMPOLINE_EMPTY(int ItemDisplayHook::WndNotification_Trampoline(CXWnd*, uint32_t, void*));
DETOUR_TRAMPOLINE_EMPTY(bool ItemDisplayHook::AboutToShow_Trampoline());
DETOUR_TRAMPOLINE_EMPTY(void ItemDisplayHook::SetSpell_Trampoline(int SpellID, bool bFullInfo));
DETOUR_TRAMPOLINE_EMPTY(void ItemDisplayHook::UpdateStrings_Trampoline());

enum eAugTypes
{
	AT_1 = 0x00000001,
	AT_2 = 0x00000002,
	AT_3 = 0x00000004,
	AT_4 = 0x00000008,
	AT_5 = 0x00000010,
	AT_6 = 0x00000020,
	AT_7 = 0x00000040,
	AT_8 = 0x00000080,
	AT_9 = 0x00000100,
	AT_10 = 0x00000200,
	AT_11 = 0x00000400,
	AT_12 = 0x00000800,
	AT_13 = 0x00001000,
	AT_14 = 0x00002000,
	AT_15 = 0x00004000,
	AT_16 = 0x00008000,
	AT_17 = 0x00010000,
	AT_18 = 0x00020000,
	AT_19 = 0x00040000,
	AT_20 = 0x00080000,
	AT_21 = 0x00100000,
	AT_22 = 0x00200000,
	AT_23 = 0x00400000,
	AT_24 = 0x00800000,
	AT_25 = 0x01000000,
	AT_26 = 0x02000000,
	AT_27 = 0x04000000,
	AT_28 = 0x08000000,
	AT_29 = 0x10000000,
	AT_30 = 0x20000000,
	AT_31 = 0x40000000,
	AT_32 = 0x80000000
};

void ItemDisplayCmd(SPAWNINFO* pChar, char* szLine)
{
	if (szLine && szLine[0] == '\0')
	{
		WriteChatf("Usage: /itemdisplay LootButton optional:off/on");
		WriteChatf("Usage: /itemdisplay LucyButton optional:off/on");
		return;
	}

	char szArg1[MAX_STRING] = { 0 };
	char szArg2[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);
	GetArg(szArg2, szLine, 2);
	bool bon = true;
	bool bToggle = true;

	if (szArg2 && szArg2[0] != '\0')
	{
		if (!_stricmp(szArg2, "off"))
		{
			bToggle = false;
			bon = false;
		}
		else if (!_stricmp(szArg2, "on"))
		{
			bToggle = false;
		}
	}

	if (!_stricmp(szArg1, "LootButton"))
	{
		if (bToggle)
		{
			gLootButton = !gLootButton;
		}
		else
		{
			gLootButton = bon;
		}

		WriteChatf("Display of the %s is now \ay%s\ax.", szArg1, (gLootButton ? "Enabled" : "Disabled"));
		_itoa_s(gLootButton, szArg1, 10);
		WritePrivateProfileString("Settings", "LootButton", szArg1, INIFileName);

		for (auto i = ButtonMap.begin(); i != ButtonMap.end();)
		{
			if (i->second.ID == 1)
			{
				i->first->Destroy();
				ButtonMap.erase(i++);
			}
			else
			{
				i++;
			}
		}
	}
	else if (!_stricmp(szArg1, "LucyButton"))
	{
		if (bToggle)
		{
			gLucyButton = !gLucyButton;
		}
		else
		{
			gLucyButton = bon;
		}

		WriteChatf("Display of the %s is now \ay%s\ax.", szArg1, (gLucyButton ? "Enabled" : "Disabled"));
		_itoa_s(gLucyButton, szArg1, 10);
		WritePrivateProfileString("Settings", "LucyButton", szArg1, INIFileName);

		for (auto i = ButtonMap.begin(); i != ButtonMap.end();)
		{
			if (i->second.ID == 2)
			{
				i->first->Destroy();
				ButtonMap.erase(i++);
			}
			else
			{
				i++;
			}
		}
	}
	else if (!_stricmp(szArg1, "Compare"))
	{
		if (bToggle)
		{
			gCompareTip = !gCompareTip;
		}
		else
		{
			gCompareTip = bon;
		}

		WriteChatf("Display of Compare Tip is now \ay%s\ax.", (gCompareTip ? "Enabled" : "Disabled"));
		_itoa_s(gCompareTip, szArg1, 10);
		WritePrivateProfileString("Settings", "CompareTip", szArg1, INIFileName);
	}
}

static void AddCompareTableData(char* buffer, size_t length, const char* statname, unsigned long statcolor, float statvalue)
{
	char szBuffer[256] = { 0 };
	if (statvalue != 0.00f)
	{
		sprintf_s(szBuffer, "<TD><c \"#FFFFFF\">%s</c></TD><TD><c \"#%06X\">%+2.3f</c></TD>", statname, statcolor, statvalue);
		strcat_s(buffer, length, szBuffer);
	}
	else
	{
		strcat_s(buffer, length, "<TD></TD><TD></TD>");
	}
}

static void AddCompareTableData(char* buffer, size_t length, const char* statname, unsigned long statcolor, int statvalue)
{
	char szBuffer[256] = { 0 };
	if (statvalue != 0)
	{
		sprintf_s(szBuffer, "<TD><c \"#FFFFFF\">%s</c></TD><TD><c \"#%06X\">%+d</c></TD>", statname, statcolor, statvalue);
		strcat_s(buffer, length, szBuffer);
	}
	else
	{
		strcat_s(buffer, length, "<TD></TD><TD></TD>");
	}
}

static void UpdateCompareWindow(ItemClient* pCont, ItemClient* pEquipped)
{
	ItemDefinition* pItem = GetItemFromContents(pCont);
	ItemDefinition* pItem2 = GetItemFromContents(pEquipped);
	if (!pItem || !pItem2 || !CanIUseThisItem(pItem))
		return;

	PSPAWNINFO pSpawn = (PSPAWNINFO)pLocalPlayer;
	if (!pSpawn)
		return;

	// Set the location for the window to the mouse cursor
	CXPoint pt;
	pt.x = EQADDR_MOUSE->X + 5;
	pt.y = EQADDR_MOUSE->Y + 5;
	pCompareTipWnd->Move(pt);

	// Set the layer of the window to display
	pCompareTipWnd->SetZLayer(105);        // Bags are z-index 100
	pCompareTipWnd->SetBringToTopWhenClicked(true);
	pCompareTipWnd->SetEscapable(true);

	pCompareTipWnd->Display->SetSTMLText("", false);
	pCompareTipWnd->Display->ForceParseNow();

	char szTemp[MAX_STRING] = { 0 };
	char szTable[MAX_STRING] = { 0 };
	char szTemp2[256] = { 0 };
	unsigned int color_red = 0xFF0000;
	unsigned int color_green = 0x00FF00;
	unsigned int color_yellow = 0xFFFF00;

	// Display Name/Lore/NoDrop tags.
	sprintf_s(szTemp, "<c \"#ffff00\">%s</c><c \"#FFFFFF\">&NBSP;&NBSP;Vs</c>&NBSP;&NBSP;<c \"#00FF00\">%s(equipped)</c><br>", pItem->Name, pItem2->Name);
	pCompareTipWnd->Display->SetSTMLText(szTemp, false);

	if (pItem->Lore)
		strcpy_s(szTemp2, "[Lore]");
	if (pItem->NoDrop)
	{
		if (pItem->Lore)
			strcat_s(szTemp2, " ");
		strcat_s(szTemp2, "[No Drop]");
	}
	if (pItem->NoDrop || pItem->Lore)
		strcat_s(szTemp2, "<br>");
	pCompareTipWnd->Display->AppendSTML(szTemp2);

	// Display all the slots - No table, need it to word wrap
	szTemp2[0] = 0;
	sprintf_s(szTemp, "<c \"#ffff00\">%s<br></c>", GetSlots(pItem, szTemp2));
	pCompareTipWnd->Display->AppendSTML(szTemp);

	// Begin table
	strcat_s(szTable, "<TABLE>");

	// Row -- Size          AC
	{
		int ACStat = pItem->AC - pItem2->AC;
		unsigned int ACcolor = (ACStat >= 0) ? color_green : color_red;

		int dmgStat = pItem->Damage - pItem2->Damage;
		unsigned int dmgColor = (dmgStat >= 0) ? color_green : color_red;

		sprintf_s(szTemp, "<TR><TD><c \"#FFFFFF\">Size: </c></TD><TD><c \"#00FF00\">%s</c></TD>", szSize[pItem->Size]);
		AddCompareTableData(szTemp, MAX_STRING, "AC:", ACcolor, ACStat);
		AddCompareTableData(szTemp, MAX_STRING, "Damage:", dmgColor, dmgStat);
		strcat_s(szTemp, "</TR>");
		strcat_s(szTable, szTemp);
	}

	// Row -- Weight         HP:          Elemental:
	{
		float weightstat = (float)((int)pItem->Weight - (int)pItem2->Weight) / 10.f;

		// If item weighs more, make it red.
		unsigned int weightcolor = (weightstat > 0) ? color_red : color_green;

		// compute HP and color
		int HPStat = pItem->HP - pItem2->HP;
		unsigned int hpcolor = (HPStat >= 0) ? color_green : color_red;

		// FIXME: this is not working for all weapons (Fabled Rune Etched Bamboo Bo for example has
		// 4 fire damage, but it is no showing up here)
		// compute ele dmg and color
		int eleDmgStat = pItem->ElementalDamage - pItem2->ElementalDamage;
		unsigned int eleDmgColor = (eleDmgStat >= 0) ? color_green : color_red;

		// FIXME: Also missing, is damage bonus

		strcpy_s(szTemp, "<TR>");
		AddCompareTableData(szTemp, MAX_STRING, "Weight:", weightcolor, weightstat);
		AddCompareTableData(szTemp, MAX_STRING, "HP:", hpcolor, HPStat);
		AddCompareTableData(szTemp, MAX_STRING, "Elemental:", eleDmgColor, eleDmgStat);
		strcat_s(szTemp, "</TR>");
		strcat_s(szTable, szTemp);
	}

	// Row -- RecLevel       Mana:
	{
		// We're just going to display the rec level, but let's choose a color.
		// Yellow if we can use it, but not greater than or equal to the rec level.
		unsigned int recLevelColor = color_red;
		if (pItem->RecommendedLevel < pSpawn->Level)
			recLevelColor = color_green;     // My level is higher than recommended level, so it's green.
		else if (pItem->RecommendedLevel > pSpawn->Level)
			recLevelColor = color_yellow;    // recommended level is higher than mine, so it's yellow.

		int manastat = pItem->Mana - pItem2->Mana;
		unsigned int manaColor = (manastat >= 0) ? color_green : color_red;

		int bsstat = pItem->BackstabDamage - pItem2->BackstabDamage;
		unsigned int bscolor = (bsstat >= 0) ? color_green : color_red;

		strcpy_s(szTemp, "<TR>");
		AddCompareTableData(szTemp, MAX_STRING, "Recommended:", recLevelColor, pItem->RecommendedLevel);
		AddCompareTableData(szTemp, MAX_STRING, "Mana:", manaColor, manastat);
		AddCompareTableData(szTemp, MAX_STRING, "Backstab:", bscolor, bsstat);
		strcat_s(szTemp, "</TR>");
		strcat_s(szTable, szTemp);
	}

	// Row -- ReqLevel       Endurance:
	{
		unsigned int reqLevelColor = color_red;
		if (pItem->RequiredLevel < pSpawn->Level)
			reqLevelColor = color_green;      // My level is higher than recommended level, so it's green.

		int endstat = pItem->Endurance - pItem2->Endurance;
		unsigned int endColor = (endstat >= 0) ? color_green : color_red;

		int delaystat = (int)pItem->Delay - pItem2->Delay;
		unsigned int delaycolor = (delaystat >= 0) ? color_red : color_green;

		strcpy_s(szTemp, "<TR>");
		AddCompareTableData(szTemp, MAX_STRING, "Required:", reqLevelColor, pItem->RequiredLevel);
		AddCompareTableData(szTemp, MAX_STRING, "Endurance:", endColor, endstat);
		AddCompareTableData(szTemp, MAX_STRING, "Delay:", delaycolor, delaystat);
		strcat_s(szTemp, "</TR>");
		strcat_s(szTable, szTemp);
	}

	// Row -- Skill          (Blank)        Haste:
	{
		int hastestat = pItem->Haste - pItem2->Haste;
		unsigned int hasteColor = (hastestat >= 0) ? color_green : color_red;

		// FIXME: Skill does no make much sense for all items. Probably only needs to be displayed for weapons.

		sprintf_s(szTemp, "<TR><TD>Skill:</TD><TD><c \"#%06X\">%s</c></TD>", color_green, szItemClasses[pItem->ItemType]);
		AddCompareTableData(szTemp, MAX_STRING, "Haste:", hasteColor, hastestat);
		strcat_s(szTemp, "</TR>");
		strcat_s(szTable, szTemp);
	}

	// Row -- Efficiency       OffhandEff          Ratio
	{
		// Avoid division by zero
		float item1ratio = (pItem->Damage != 0) ? ((float)pItem->Delay / (float)pItem->Damage) : 0.0f;
		float item2ratio = (pItem2->Damage != 0) ? ((float)pItem2->Delay / (float)pItem2->Damage) : 0.0f;
		float ratiostat = item1ratio - item2ratio;
		unsigned int ratiocolor = (ratiostat >= 0) ? color_red : color_green;

		float effstat = (pItem->Delay != 0) ? (((((float)pItem->Damage * 2) + pItem->DmgBonusValue) / (float)pItem->Delay) * 50) : 0.0f;
		float eff2stat = (pItem2->Delay != 0) ? (((((float)pItem2->Damage * 2) + pItem2->DmgBonusValue) / (float)pItem2->Delay) * 50) : 0.0f;
		effstat -= eff2stat;
		unsigned int effcolor = (effstat >= 0) ? color_green : color_red;

		float offeffstat = (pItem->Delay != 0) ? (((((float)pItem->Damage * 2) / (float)pItem->Delay) * 50.0f) * 0.62f) : 0.0f;
		float offeff2stat = (pItem2->Delay != 0) ? (((((float)pItem2->Damage * 2) / (float)pItem2->Delay) * 50.0f) * 0.62f) : 0.0f;
		offeffstat -= offeff2stat;
		unsigned int offeffcolor = (offeffstat >= 0) ? color_green : color_red;

		strcpy_s(szTemp, "<TR>");
		AddCompareTableData(szTemp, MAX_STRING, "Efficiency:", effcolor, (int)effstat);
		if (pItem->EquipSlots & 16384 || pItem2->EquipSlots & 16384)
			AddCompareTableData(szTemp, MAX_STRING, "Offhand Eff:", offeffcolor, (int)offeffstat);
		else
			strcat_s(szTemp, "<TD></TD><TD></TD>");
		AddCompareTableData(szTemp, MAX_STRING, "Ratio:", ratiocolor, ratiostat);
		strcat_s(szTemp, "</TR>");
		strcat_s(szTable, szTemp);
	}

	// Row -- Luck
	{
		int luckstat = pCont->Luck - pEquipped->Luck;
		unsigned int luckcolor = (luckstat >= 0) ? color_green : color_red;

		strcpy_s(szTemp, "<TR><TD></TD><TD></TD><TD></TD><TD></TD>");
		AddCompareTableData(szTemp, MAX_STRING, "Luck:", luckcolor, luckstat);
		strcat_s(szTemp, "</TR>");
		strcat_s(szTable, szTemp);
	}

	// Finish this table and start a new one
	strcat_s(szTable, "</TABLE><br>");
	pCompareTipWnd->Display->AppendSTML(szTable);

	strcpy_s(szTable, "<TABLE>");

	// Row -- Strength:        Magic:        Attack:
	{
		int strstat = pItem->STR - pItem2->STR;
		unsigned int strcolor = (strstat >= 0) ? color_green : color_red;

		int hstrstat = pItem->HeroicSTR - pItem2->HeroicSTR;
		unsigned int hstrcolor = (hstrstat >= 0) ? color_green : color_red;

		int MRstat = pItem->SvMagic - pItem2->SvMagic;
		unsigned int mrcolor = (MRstat >= 0) ? color_green : color_red;

		int atkstat = pItem->Attack - pItem2->Attack;
		unsigned int atkcolor = (atkstat >= 0) ? color_green : color_red;

		strcpy_s(szTemp, "<TR>");
		AddCompareTableData(szTemp, MAX_STRING, "Strength:", strcolor, strstat);
		AddCompareTableData(szTemp, MAX_STRING, "<c \"#d6b228\">HStr:</c>", hstrcolor, hstrstat);
		AddCompareTableData(szTemp, MAX_STRING, "Magic:", mrcolor, MRstat);
		AddCompareTableData(szTemp, MAX_STRING, "Attack:", atkcolor, atkstat);
		strcat_s(szTemp, "</TR>");
		strcat_s(szTable, szTemp);
	}

	// Row -- Stamina:              Fire:            HP Regen:
	{
		int stastat = pItem->STA - pItem2->STA;
		unsigned int stacolor = (stastat >= 0) ? color_green : color_red;

		int hstastat = pItem->HeroicSTA - pItem2->HeroicSTA;
		unsigned int hstacolor = (hstastat >= 0) ? color_green : color_red;

		int frstat = pItem->SvFire - pItem2->SvFire;
		unsigned int frcolor = (frstat >= 0) ? color_green : color_red;

		int hpregenstat = pItem->HPRegen - pItem2->HPRegen;
		unsigned int hpregencolor = (hpregenstat >= 0) ? color_green : color_red;

		strcpy_s(szTemp, "<TR>");
		AddCompareTableData(szTemp, MAX_STRING, "Stamina:", stacolor, stastat);
		AddCompareTableData(szTemp, MAX_STRING, "<c \"#d6b228\">HSta:</c>", hstacolor, hstastat);
		AddCompareTableData(szTemp, MAX_STRING, "Fire:", frcolor, frstat);
		AddCompareTableData(szTemp, MAX_STRING, "HP Regen:", hpregencolor, hpregenstat);
		strcat_s(szTemp, "</TR>");
		strcat_s(szTable, szTemp);
	}

	// Row -- Intelligence:          Cold:            Mana Regen:
	{
		int intstat = pItem->INT - pItem2->INT;
		unsigned int intcolor = (intstat >= 0) ? color_green : color_red;

		int hintstat = pItem->HeroicINT - pItem2->HeroicINT;
		unsigned int hintcolor = (hintstat >= 0) ? color_green : color_red;

		int crstat = pItem->SvCold - pItem2->SvCold;
		unsigned int crcolor = (crstat >= 0) ? color_green : color_red;

		int manaregenstat = pItem->ManaRegen - pItem2->ManaRegen;
		unsigned int manaregencolor = (manaregenstat >= 0) ? color_green : color_red;

		strcpy_s(szTemp, "<TR>");
		AddCompareTableData(szTemp, MAX_STRING, "Intelligence:", intcolor, intstat);
		AddCompareTableData(szTemp, MAX_STRING, "<c \"#d6b228\">HInt:</c>", hintcolor, hintstat);
		AddCompareTableData(szTemp, MAX_STRING, "Cold:", crcolor, crstat);
		AddCompareTableData(szTemp, MAX_STRING, "Mana Regen:", manaregencolor, manaregenstat);
		strcat_s(szTemp, "</TR>");
		strcat_s(szTable, szTemp);
	}

	// Row -- Wisdom:               Disease:           Heal Amount:
	{
		int wisstat = pItem->WIS - pItem2->WIS;
		unsigned int wiscolor = (wisstat >= 0) ? color_green : color_red;

		int hwisstat = pItem->HeroicWIS - pItem2->HeroicWIS;
		unsigned int hwiscolor = (hwisstat >= 0) ? color_green : color_red;

		int drstat = pItem->SvDisease - pItem2->SvDisease;
		unsigned int drcolor = (drstat >= 0) ? color_green : color_red;

		int healstat = pItem->HealAmount - pItem2->HealAmount;
		unsigned int healcolor = (healstat >= 0) ? color_green : color_red;

		strcpy_s(szTemp, "<TR>");
		AddCompareTableData(szTemp, MAX_STRING, "Wisdom:", wiscolor, wisstat);
		AddCompareTableData(szTemp, MAX_STRING, "<c \"#d6b228\">HWis:</c>", hwiscolor, hwisstat);
		AddCompareTableData(szTemp, MAX_STRING, "Disease:", drcolor, drstat);
		AddCompareTableData(szTemp, MAX_STRING, "Heal Amt:", healcolor, healstat);
		strcat_s(szTemp, "</TR>");
		strcat_s(szTable, szTemp);
	}

	// Row -- Agility:              Poison:             Spell Dmg:
	{
		int agistat = pItem->AGI - pItem2->AGI;
		unsigned int agicolor = (agistat >= 0) ? color_green : color_red;

		int hagistat = pItem->HeroicAGI - pItem2->HeroicAGI;
		unsigned int hagicolor = (hagistat >= 0) ? color_green : color_red;

		int prstat = pItem->SvPoison - pItem2->SvPoison;
		unsigned int prcolor = (prstat >= 0) ? color_green : color_red;

		int spelldmgstat = pItem->SpellDamage - pItem2->SpellDamage;
		unsigned int spelldmgcolor = (spelldmgstat >= 0) ? color_green : color_red;

		strcpy_s(szTemp, "<TR>");
		AddCompareTableData(szTemp, MAX_STRING, "Agility:", agicolor, agistat);
		AddCompareTableData(szTemp, MAX_STRING, "<c \"#d6b228\">HAgi:</c>", hagicolor, hagistat);
		AddCompareTableData(szTemp, MAX_STRING, "Poison:", prcolor, prstat);
		AddCompareTableData(szTemp, MAX_STRING, "Spell Dmg:", spelldmgcolor, spelldmgstat);
		strcat_s(szTemp, "</TR>");
		strcat_s(szTable, szTemp);
	}

	// Row -- Dexterity:               Corrupt:           Clairvoyance:
	{
		int dexstat = pItem->DEX - pItem2->DEX;
		unsigned int dexcolor = (dexstat >= 0) ? color_green : color_red;

		int hdexstat = pItem->HeroicDEX - pItem2->HeroicDEX;
		unsigned int hdexcolor = (hdexstat >= 0) ? color_green : color_red;

		int corstat = pItem->SvCorruption - pItem2->SvCorruption;
		unsigned int corcolor = (corstat >= 0) ? color_green : color_red;

		int clairstat = pItem->Clairvoyance - pItem2->Clairvoyance;
		unsigned int claircolor = (clairstat >= 0) ? color_green : color_red;

		strcpy_s(szTemp, "<TR>");
		AddCompareTableData(szTemp, MAX_STRING, "Dexterity:", dexcolor, dexstat);
		AddCompareTableData(szTemp, MAX_STRING, "<c \"#d6b228\">HDex:</c>", hdexcolor, hdexstat);
		AddCompareTableData(szTemp, MAX_STRING, "Corruption:", corcolor, corstat);
		AddCompareTableData(szTemp, MAX_STRING, "Clairvoyance:", claircolor, clairstat);
		strcat_s(szTemp, "</TR>");
		strcat_s(szTable, szTemp);
	}

	// Row -- Charisma:               (blank)                 FlyingKick (or any other dmgbonus skill)
	{
		int chastat = pItem->CHA - pItem2->CHA;
		unsigned int chacolor = (chastat >= 0) ? color_green : color_red;

		int hchastat = pItem->HeroicCHA - pItem2->HeroicCHA;
		unsigned int hchacolor = (hchastat >= 0) ? color_green : color_red;

		strcpy_s(szTemp, "<TR>");
		AddCompareTableData(szTemp, MAX_STRING, "Charisma:", chacolor, chastat);
		AddCompareTableData(szTemp, MAX_STRING, "<c \"#d6b228\">HCha:</c>", hchacolor, hchastat);
		strcat_s(szTemp, "<TD></TD><TD></TD>");

		if ((pItem->DmgBonusValue || pItem2->DmgBonusValue) && pItem->DmgBonusSkill == pItem2->DmgBonusSkill)
		{
			// If both have skills and the skills match.
			int dmgstat = pItem->DmgBonusValue - pItem2->DmgBonusValue;
			unsigned int dmgstatcolor = (dmgstat >= 0) ? color_green : color_red;

			AddCompareTableData(szTemp, MAX_STRING, szSkills[pItem->DmgBonusSkill], dmgstatcolor, dmgstat);
		}
		else if (pItem->DmgBonusSkill != pItem2->DmgBonusSkill)
		{
			// If both have skills, but they don't match.
			if (pItem->DmgBonusValue)
			{
				sprintf_s(szTemp2, "<TD>%s:</c></TD><TD><c \"#%06X\">%+d</c></TD>", szSkills[pItem->DmgBonusSkill], color_green, pItem->DmgBonusValue);
				strcat_s(szTemp, szTemp2);
			}

			if (pItem2->DmgBonusValue)
			{
				if (pItem->DmgBonusValue)
				{
					// If there's a second skill, end the row, move over 6 columns.
					strcat_s(szTemp, "</TR><TR> <TD></TD> <TD></TD> <TD></TD> <TD></TD> <TD></TD> <TD></TD>");
				}

				sprintf_s(szTemp2, "<TD>%s:</c></TD><TD><c \"#%06X\">%+d</c></TD>", szSkills[pItem2->DmgBonusSkill], color_red, -(int)pItem2->DmgBonusValue);
				strcat_s(szTemp, szTemp2);
			}
		}

		strcat_s(szTemp, "</TR></TABLE>");
		strcat_s(szTable, szTemp);
	}

	// We're done generating the STML so we can force an update now.
	pCompareTipWnd->Display->AppendSTML(szTable);
	pCompareTipWnd->Display->ForceParseNow();
	pCompareTipWnd->SetVisible(true);
}

void RequestConvertItem(SPAWNINFO* pSpawn, char* szLine)
{
	if (!pItemDisplayManager) return;

	if (szLine && szLine[0] != '\0')
	{
		GetArg(ConvertFrom, szLine, 1);

		if (ItemPtr pItem = FindItemByName(ConvertFrom))
		{
			int index = pItemDisplayManager->FindWindow(true);
			if (index == -1)
			{
				index = pItemDisplayManager->CreateWindowInstance();
			}

			if (auto itemDis = pItemDisplayManager->GetWindow(index))
			{
				itemDis->SetItem(pItem, 0);
				itemDis->RequestConvertItem();
			}
			return;
		}
	}

	WriteChatf("\agUSAGE:\ax /convertitem \ay\"<item name>\"\ax");
	WriteChatf("\agExample:\ax /convertitem \ay\"Wishing Lamp:\"\ax");
}

void AddLootFilter(SPAWNINFO* pChar, char* szLine)
{
	if (!pLootFiltersManager)
		return;

	if (szLine[0] == '\0')
	{
		WriteChatf("AddLootFilter Usage: /AddLootFilter <itemID> <ItemIconID> \"Item Name\"");
		return;
	}

	char szArg1[MAX_STRING] = { 0 };
	char szArg2[MAX_STRING] = { 0 };
	char szArg3[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);
	GetArg(szArg2, szLine, 2);
	GetArg(szArg3, szLine, 3);

	if (szArg1[0] == '\0' || szArg2[0] == '\0' || szArg3[0] == '\0')
	{
		WriteChatf("AddLootFilter Usage: /AddLootFilter <itemID> <ItemIconID> \"Item Name\"");
		return;
	}

	int itemid = GetIntFromString(szArg1, 0);
	int itemicon = GetIntFromString(szArg2, 0);

	pLootFiltersManager->AddItemLootFilter(itemid, itemicon, szArg3, 5);
	WriteChatf("Added %s to AG and Roll LootFilters.", szArg3);
}

void InsertAug(SPAWNINFO* pChar, char* szLine)
{
	PcProfile* pProfile = GetPcProfile();
	if (!pProfile) return;
	if (!pItemDisplayManager) return;

	char szArg1[MAX_STRING] = { 0 };
	char szArg2[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);
	GetArg(szArg2, szLine, 2);

	ItemPtr pTargetItem;

	if (szArg1[0] != '\0' && IsNumber(szArg1))
	{
		if (szArg2[0] == '\0')
		{
			// its an itemid...
			int iID = GetIntFromString(szArg1, -1);
			pTargetItem = FindItemByID(iID);
		}
		else
		{
			// it must be a slot then...
			int slot1 = GetIntFromString(szArg1, -1);
			int slot2 = -1;

			if (szArg2[0] != '\0')
			{
				slot2 = GetIntFromString(szArg2, -1);
			}
			pTargetItem = FindItemBySlot(slot1, slot2);
		}
	}
	else if (szArg1[0] != '\0')
	{
		// its a itemname....
		pTargetItem = FindItemByName(szArg1);
	}

	if (!pTargetItem)
	{
		WriteChatColor("/insertaug USAGE: /insertaug \ay#######\ax where ####### is the itemid OR \ay\"Item Name in Quotes\"\ax OR \ay## ##\ax where ## ## are slotnumbers the item is in.", CONCOLOR_WHITE);
		WriteChatColor("Example1: /insertaug \ay41302\ax", CONCOLOR_WHITE);
		WriteChatColor("Example2: /insertaug \ay\"Darkened Thick Banded Belt\"\ax", CONCOLOR_WHITE);
		WriteChatColor("Example3: /insertaug \ay20 -1\ax", CONCOLOR_WHITE);
		return;
	}

	if (ItemPtr pAugItem = pProfile->GetInventorySlot(InvSlot_Cursor))
	{
		int Slot = 0;
		bool bFits = false;

		for (; Slot < MAX_AUG_SOCKETS; Slot++)
		{
			int fit = pTargetItem->CanGemFitInSlot(pAugItem, Slot);
			if (fit == 0)
			{
				bFits = true;
				break;
			}
		}

		if (!bFits)
		{
			WriteChatf("\ayCould NOT insert the\ax \at%s\ax into the \ag%s\ax",
				pAugItem->GetName(), pTargetItem->GetName());
			return;
		}

		int index = pItemDisplayManager->FindWindow(true);
		if (index == -1)
		{
			index = pItemDisplayManager->CreateWindowInstance();
		}

		if (index >= 0 && index < pItemDisplayManager->GetCount())
		{
			auto itemDis = pItemDisplayManager->GetWindow(index);
			itemDis->SetItem(pTargetItem, 0);

			ItemDefinition* pAugDef = pAugItem->GetItemDefinition();

			// hack to bypass popupdialog...
			int oldsolv = std::exchange(pAugDef->SolventItemID, 0);
			bool oldattn = std::exchange(pAugDef->Attuneable, false);

			// now the actual function call...
			itemDis->InsertAugmentRequest(Slot);

			// ok so lets restore the org values...
			pAugDef->SolventItemID = oldsolv;
			pAugDef->Attuneable = oldattn;
		}
	}
}

void RemoveAug(SPAWNINFO* pChar, char* szLine)
{
	PcProfile* pProfile = GetPcProfile();
	if (!pProfile) return;
	if (!pItemDisplayManager) return;

	if (pProfile->GetInventorySlot(InvSlot_Cursor))
	{
		// You cannot remove the augment while you are holding something.
		WriteChatf("\ay%s", pStringTable->getString(5478));
		return;
	}

	char szArg1[MAX_STRING] = { 0 };
	char szArg2[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);
	GetArg(szArg2, szLine, 2);

	ItemPtr pTargetItem;
	if (szArg2[0] != '\0' && IsNumber(szArg2))
	{
		// its an id
		int itemId = GetIntFromString(szArg2, -1);
		if (itemId > 0)
			pTargetItem = FindItemByID(itemId);
	}
	else if (szArg2[0] != '\0')
	{
		// its a name...
		pTargetItem = FindItemByName(szArg2, true);
	}

	if (!pTargetItem || szArg1[0] == '\0')
	{
		WriteChatColor("/removeaug USAGE: /removeaug \ay<augid>\ax <#####> OR \ay<augname>\ax \"Name in quotes\" \ay<itemid>\ax <#####> OR \ay<itemname>\ax \"Name in quotes\"", CONCOLOR_WHITE);
		WriteChatColor("NOTE! /removeaug \ayIS A CASE SENSITIVE FUNCTION\ax", CONCOLOR_WHITE);
		WriteChatColor("Example1: /removeaug \ay50502\ax \ay41302\ax", CONCOLOR_WHITE);
		WriteChatColor("Example2: /removeaug \ay\"Crude Defiant Ruby Shard\"\ax \"Darkened Thick Banded Belt\"", CONCOLOR_WHITE);
		WriteChatColor("Example2: /removeaug \ay\"Crude Defiant Ruby Shard\"\ax \ay41302\ax", CONCOLOR_WHITE);
		WriteChatColor("Example2: /removeaug \ay50502\ax \"Darkened Thick Banded Belt\"", CONCOLOR_WHITE);
		return;
	}

	ItemIndex foundAugment;
	if (IsNumber(szArg1))
	{
		int itemId = GetIntFromString(szArg1, 0);
		if (itemId > 0)
		{
			foundAugment = pTargetItem->GetHeldItems().FindItem(0, FindItemByIdPred(itemId));
		}
	}
	else
	{
		foundAugment = pTargetItem->GetHeldItems().FindItem(0, FindItemByNamePred(szArg1));
	}

	ItemPtr pAugItem;
	if (foundAugment.IsValid())
	{
		pAugItem = pTargetItem->GetHeldItem(foundAugment.GetDeepestSlot());
	}

	if (pAugItem)
	{
		int index = pItemDisplayManager->FindWindow(true);
		if (index == -1)
		{
			index = pItemDisplayManager->CreateWindowInstance();
		}

		if (index >= 0 && index < pItemDisplayManager->GetCount())
		{
			auto itemDis = pItemDisplayManager->GetWindow(index);

			itemDis->SetItem(pTargetItem, 0);

			if (pAugItem)
			{
				ItemPtr pItemSolvent;
				int realID = 0;

				// we need to check for all distillers
				int minreqid = pAugItem->GetItemDefinition()->SolventItemID;

				CDistillerInfo& pDistillerInfo = CDistillerInfo::Instance();

				for (int i = minreqid; i <= 21; i++)
				{
					realID = pDistillerInfo.GetIDFromRecordNum(i, false);

					pItemSolvent = pPCData->GetItemByID(realID);
					if (pItemSolvent)
					{
						// found a distiller that will work...
						break;
					}
				}

				if (!pItemSolvent)
				{
					// Universal Augment Solvent... aka perfect distiller...
					pItemSolvent = pPCData->GetItemByItemClass(ItemClass_PerfectedDistiller);
				}

				if (pItemSolvent)
				{
					// we shouldnt do the solvent thing for removals, people who macro this can click the ok button on the confirmation window...
					itemDis->RemoveAugmentRequest(foundAugment.GetDeepestSlot());
				}
				else
				{
					// The augment cannot be removed because your inventory does not contain the required solvent.
					WriteChatf("\ay%s", pStringTable->getString(5474));
				}
			}
		}
	}
	else
	{
		WriteChatf("\ayCould NOT remove the\ax \at%s\ax from the \ag%s\ax", szArg1, pTargetItem->GetName());
	}
}

void Comment(SPAWNINFO* pChar, char* szLine)
{
	char Arg[MAX_STRING] = { 0 };
	char ItemNo[MAX_STRING] = { 0 };
	char Comment[MAX_STRING] = { 0 };
	char szTemp[MAX_STRING] = { 0 };

	GetArg(Arg, szLine, 1);
	GetArg(ItemNo, szLine, 2);
	GetArg(szTemp, szLine, 3);

	for (int i = 4; strlen(szTemp); i++)
	{
		strcat_s(Comment, szTemp);
		strcat_s(Comment, " ");
		GetArg(szTemp, szLine, i);
	}
	const int itemno = GetIntFromString(ItemNo, 0);

	if (_stricmp(Arg, "add") != 0 && _stricmp(Arg, "del") != 0)
	{
		WriteChatColor("Use: /inote <add|del> <itemno> \"Comment\"", CONCOLOR_YELLOW);
		return;
	}

	if (itemno <= 0)
	{
		WriteChatColor("Invalid item number");
		WriteChatColor("Use: /inote <add|del> <itemno> \"Comment\"", CONCOLOR_YELLOW);
		return;
	}

	if (strlen(Comment) == 0 || _stricmp(Arg, "del") == 0)
	{
		sprintf_s(szTemp, "%07d", itemno);
		WritePrivateProfileString("Notes", szTemp, "", INIFileName);
		return;
	}

	if (_stricmp(Arg, "add") == 0)
	{
		sprintf_s(szTemp, "%07d", itemno);
		WritePrivateProfileString("Notes", szTemp, Comment, INIFileName);
		return;
	}
}

void DestroyCompareTipWnd()
{
	if (pCompareTipWnd)
	{
		delete pCompareTipWnd;
		pCompareTipWnd = nullptr;
	}
}

void CreateCompareTipWnd()
{
	if (pCompareTipWnd || bDisabledComparetip)
	{
		return;
	}

	if (IsScreenPieceLoaded("CompareTipWnd"))
	{
		pCompareTipWnd = new CCompareTipWnd();
		if (!pCompareTipWnd)
		{
			WriteChatf("[MQ2ItemDisplay] Unable to Create Tip Window.");
		}
	}
	else
	{
		bDisabledComparetip = true;
		WriteChatf("[MQ2ItemDisplay] Unable to create CompareTipWnd. Please do /reloadui");
	}
}

// Called once, when the plugin is to initialize
PLUGIN_API void InitializePlugin()
{
	gLootButton = 1 == GetPrivateProfileInt("Settings", "LootButton", 1, INIFileName);
	gLucyButton = 1 == GetPrivateProfileInt("Settings", "LucyButton", 1, INIFileName);
	gCompareTip = 1 == GetPrivateProfileInt("Settings", "CompareTip", 0, INIFileName);

	EzDetourwName(CItemDisplayWnd__WndNotification, &ItemDisplayHook::WndNotification_Detour, &ItemDisplayHook::WndNotification_Trampoline, "CItemDisplayWnd__WndNotification");
	EzDetourwName(CItemDisplayWnd__AboutToShow, &ItemDisplayHook::AboutToShow_Detour, &ItemDisplayHook::AboutToShow_Trampoline, "CItemDisplayWnd__AboutToShow");
	EzDetourwName(CItemDisplayWnd__SetSpell, &ItemDisplayHook::SetSpell_Detour, &ItemDisplayHook::SetSpell_Trampoline, "CItemDisplayWnd__SetSpell");
	EzDetourwName(CItemDisplayWnd__UpdateStrings, &ItemDisplayHook::UpdateStrings_Detour, &ItemDisplayHook::UpdateStrings_Trampoline, "CItemDisplayWnd__UpdateStrings");

	AddCommand("/itemdisplay", ItemDisplayCmd);
	AddCommand("/convertitem", RequestConvertItem);
	AddCommand("/addlootfilter", AddLootFilter);
	AddCommand("/insertaug", InsertAug);
	AddCommand("/removeaug", RemoveAug);
	AddCommand("/inote", Comment);

	pDisplayItemType = new MQ2DisplayItemType;
	AddMQ2Data("DisplayItem", dataLastItem);

	// The XML only needs to exist in the default UI for AddXML to load it
	std::filesystem::path pathXML = gPathResources;
	pathXML = pathXML / "uifiles" / "default" / TipWndXML;

	std::error_code ec_fs;

	if (!std::filesystem::exists(pathXML, ec_fs))
	{
		HMODULE hMe = nullptr;

		GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
			(LPCTSTR)InitializePlugin, &hMe);

		// need to unpack our resource.
		if (const HRSRC hRes = FindResource(hMe, MAKEINTRESOURCE(IDR_XML1), "XML"))
		{
			if (const HGLOBAL bin = LoadResource(hMe, hRes))
			{
				if (const void* pMyBinaryData = LockResource(bin))
				{
					if (std::filesystem::exists(pathXML.parent_path(), ec_fs) || std::filesystem::create_directories(pathXML.parent_path(), ec_fs))
					{
						const std::size_t ressize = SizeofResource(hMe, hRes);
						std::ofstream outFile(pathXML, std::ios::binary);
						if (outFile)
						{
							outFile.write(static_cast<const char*>(pMyBinaryData), ressize);
						}
					}
				}
			}
		}
	}

	AddXMLFile(TipWndXML);
	EzDetourwName(CInvSlotWnd__DrawTooltip, &ItemDisplayHook::CInvSlotWnd_DrawTooltipDetour, &ItemDisplayHook::CInvSlotWnd_DrawTooltipTramp,"CInvSlotWnd__DrawTooltip");

	if (gGameState == GAMESTATE_INGAME)
	{
		CreateCompareTipWnd();
	}
}

// Called once, when the plugin is to shutdown
PLUGIN_API void ShutdownPlugin()
{
	RemoveXMLFile(TipWndXML);

	// Remove commands, macro parameters, hooks, etc.
	RemoveDetour(CInvSlotWnd__DrawTooltip);
	RemoveDetour(CItemDisplayWnd__SetSpell);
	RemoveDetour(CItemDisplayWnd__UpdateStrings);
	RemoveDetour(CItemDisplayWnd__AboutToShow);
	RemoveDetour(CItemDisplayWnd__WndNotification);

	for (auto i = ButtonMap.begin(); i != ButtonMap.end(); i++)
	{
		i->first->Destroy();
	}
	ButtonMap.clear();

	RemoveMQ2Data("DisplayItem");
	RemoveCommand("/inote");
	RemoveCommand("/addlootfilter");
	RemoveCommand("/convertitem");
	RemoveCommand("/itemdisplay");
	RemoveCommand("/insertaug");
	RemoveCommand("/removeaug");

	delete pDisplayItemType;
	DestroyCompareTipWnd();
}

PLUGIN_API void OnCleanUI()
{
	for (auto i = ButtonMap.begin(); i != ButtonMap.end(); i++)
	{
		i->first->Destroy();
	}
	ButtonMap.clear();

	DestroyCompareTipWnd();
}

PLUGIN_API void OnReloadUI()
{
	for (auto i = ButtonMap.begin(); i != ButtonMap.end(); i++)
	{
		i->first->Destroy();
	}
	ButtonMap.clear();

	if (GetGameState() == GAMESTATE_INGAME && pCharSpawn)
	{
		bDisabledComparetip = false;
		CreateCompareTipWnd();
	}
}

PLUGIN_API void OnPulse()
{
	if (GetGameState() == GAMESTATE_INGAME)
	{
		CreateCompareTipWnd();
	}
}

PLUGIN_API void OnBeginZone()
{
	for (ItemPtr& ptr : gContents)
		ptr.reset();
}