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

//		This plugin will provide fast item comparisons based strictly on the base
//		armor status. It does NOT add in augs. This makes it bad for cultural vs
//		traditional gear.
//
//		/iScore 			; shows basic status
//		/iScore AC 10 		; scores AC as 10:1
//		/iScore HP 1 		; scores HP as 1:1
//		/iScore HeroicSTA 15; scores HeroicSTA at 15:1
//

#include <mq/Plugin.h>
#include "resource.h"

#include <shellapi.h>
#include <fmt/format.h>

#include <mutex>
#include <string_view>

PreSetup("MQ2ItemDisplay");

// thanks, finally, SOE. we'll leave this here for a while and eventually remove it
#define DISABLE_TOOLTIP_TIMERS

#define EQLIB_EXPORT __declspec(dllexport)
// starting position of link text found in MQ2Web__ParseItemLink_x
constexpr int LINK_LEN = 90;
constexpr int MAX_ITEMDISPLAY_WINDOWS = 6;

char ConvertFrom[2048] = { 0 };
char ConvertTo[2048] = { 0 };
bool bDisabledComparetip = false;
bool gCompareTip = false;
bool gLootButton = true;
bool gLucyButton = true;
std::mutex s_mutex;
const char* TipWndXML = "MQUI_CompareTipWnd.xml";

struct ButtonInfo
{
	CItemDisplayWnd* ItemDisplayWnd;
	int              ID;
};

std::map<CButtonWnd*, ButtonInfo> ButtonMap;

void Comment(SPAWNINFO* pChar, char* szLine);
void DoGearScoreUserCommand(SPAWNINFO* pChar, char* szLine);

template <unsigned int _Size>
void AddGearScores(CONTENTS* pSlot, ITEMINFO* pItem, char(&out)[_Size], char* br);

struct DISPLAYITEMSTRINGS
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

class MQ2DisplayItemType;

extern "C" {
EQLIB_EXPORT MQ2DisplayItemType* pDisplayItemType = 0;
EQLIB_EXPORT std::map<DWORD, DISPLAYITEMSTRINGS> contentsitemstrings;
}

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
		Information = 9
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

		TypeMethod(AddLootFilter);
	}

	bool GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override
	{
		const int index = VarPtr.DWord;
		CONTENTS fullContents[MAX_ITEMDISPLAY_WINDOWS] = { 0 };
		CONTENTS* pCont = &fullContents[index];

		if (!pCont)
			return false;

		MQTypeMember* pMethod = MQ2DisplayItemType::FindMethod(Member);

		if (pMethod)
		{
			Dest.DWord = 0;
			Dest.Type = pBoolType;

			switch (static_cast<DisplayItemMethods>(pMethod->ID))
			{
			case AddLootFilter:
				if (ITEMINFO* pItem = GetItemFromContents(pCont))
				{
					pLootFiltersManager->AddItemLootFilter(pItem->ItemNumber, pItem->IconNumber, pItem->Name, 5);

					WriteChatf("Added %s to AG and Roll LootFilters.", pItem->Name);
					Dest.DWord = 1;
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
			varPtr.Ptr = pCont;

			return pItemType->GetMember(varPtr, Member, Index, Dest);
		}

		if (pMember)
		{
			switch ((DisplayItemMembers)pMember->ID)
			{
			case Info:
				strcpy_s(DataTypeTemp, contentsitemstrings[index].ItemInfo.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;
			case WindowTitle:
				strcpy_s(DataTypeTemp, contentsitemstrings[index].WindowTitle.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;
			case AdvancedLore:
				strcpy_s(DataTypeTemp, contentsitemstrings[index].ItemAdvancedLoreText.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;
			case MadeBy:
				strcpy_s(DataTypeTemp, contentsitemstrings[index].ItemMadeByText.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;
			case Collected:
				Dest.DWord = contentsitemstrings[index].bCollected;
				Dest.Type = pBoolType;
				return true;
			case CollectedRecieved:
				Dest.DWord = contentsitemstrings[index].bCollectedRecieved;
				Dest.Type = pBoolType;
				return true;
			case Scribed:
				Dest.DWord = contentsitemstrings[index].bScribed;
				Dest.Type = pBoolType;
				return true;
			case ScribedRecieved:
				Dest.DWord = contentsitemstrings[index].bScribedRecieved;
				Dest.Type = pBoolType;
				return true;
			case Information:
				strcpy_s(DataTypeTemp, contentsitemstrings[index].ItemInformationText.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;
			}
		}
		return false;
	}

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		CONTENTS fullContents[MAX_ITEMDISPLAY_WINDOWS] = { 0 };
		if (CONTENTS* pCont = &fullContents[VarPtr.DWord])
		{
			if (ITEMINFO* pItem = GetItemFromContents(pCont))
			{
				strcpy_s(Destination, 128, pItem->Name);
				return true;
			}
		}
		strcpy_s(Destination, 128, contentsitemstrings[VarPtr.DWord].WindowTitle.c_str());
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

class ItemInfoManager : public libMozilla::ICallback, public CObservable, public IObserver
{
	virtual void onStatusChanged(eqlib::libMozilla::Window* wnd) override;
	virtual void onURIChanged(eqlib::libMozilla::Window* wnd) override;
	virtual void onProgressChanged(eqlib::libMozilla::Window* wnd) override;
	virtual bool doValidateURI(eqlib::libMozilla::Window* wnd, const char* uri) override;

public:
	CHtmlWnd* htmlwnd = nullptr;

	ItemInfoManager() = default;

	~ItemInfoManager()
	{
		ItemInfoManager* im = &GetInstance();
		if (im)
		{
			if (im->htmlwnd)
			{
				im->htmlwnd->SetClientCallbacks(nullptr);
			}
		}
	};

	static ItemInfoManager& GetInstance();
	void Notify(CObservable* Src, const CNotification* const Notification) override;
};

ItemInfoManager& ItemInfoManager::GetInstance()
{
	static std::unique_ptr<ItemInfoManager> instance;
	if (instance.get() == nullptr)
	{
		instance.reset(new ItemInfoManager);
	}

	return *instance;
}

// work in progress
enum EHTMLNotification
{
	URISelected,
	WindowClosed,
};

void ItemInfoManager::Notify(CObservable* Src, const CNotification* Notification)
{
	if (!Src || !Notification)
		return;
}

void ItemInfoManager::onStatusChanged(eqlib::libMozilla::Window* wnd)
{
	if (const wchar_t* status = wnd->getStatus()) {
		//WriteChatf("Status changed: %s", status);
	}
}

void ItemInfoManager::onURIChanged(eqlib::libMozilla::Window* wnd)
{
	if (const char* uri = wnd->getURI())
	{
		//WriteChatf("URI changed: %s", uri);
	}
}

void ItemInfoManager::onProgressChanged(eqlib::libMozilla::Window* wnd)
{
	bool bIsLoading;
	float pct = wnd->getProgress(bIsLoading);
	//WriteChatf("Progress %0.2f Loading is %s", pct, bIsLoading ? "TRUE":"FALSE");
	//ghettofix for resize, i need to detect this better... another detour? gah... -eqmule
	/*if (!bIsLoading) {
		ItemInfoManager& manager = ItemInfoManager::GetInstance();
		if (manager.htmlwnd) {
			//int width = manager.htmlwnd->Location.right - manager.htmlwnd->Location.left;
			//int height = manager.htmlwnd->Location.bottom - manager.htmlwnd->Location.top;
			//((CXWnd*)manager.htmlwnd)->Resize(width+1, height+1);
			//Beep(1000, 100);
		}
	}
	Sleep(0);*/
}

bool ItemInfoManager::doValidateURI(eqlib::libMozilla::Window* wnd, const char* uri)
{
	return true;
}

// ***************************************************************************
// Function:    ItemDisplayHook
// Description: Our Item display hook
// ***************************************************************************

CONTENTS* pOldCont = 0;

class CCompareTipWnd : public CSidlScreenWnd
{
public:
	CCompareTipWnd() : CSidlScreenWnd(0, "CompareTipWnd", -1, 1, 0)
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

int CanIUseThisItem(ITEMINFO* pItem)
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
char* GetSlots(ITEMINFO* pItem, char(&_Buffer)[_Size])
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

CONTENTS* GetEquippedSlot(CONTENTS* pCont)
{
	if (ITEMINFO* pItem = GetItemFromContents(pCont))
	{
		DWORD cmp = pItem->EquipSlots;
		for (int N = 0; N < 32; N++)
		{
			if (cmp & (1 << N))
			{
				if (PcProfile* pProfile = GetPcProfile())
				{
					if (CONTENTS* pInvSlot = pProfile->pInventoryArray->InventoryArray[N])
					{
						return pInvSlot;
					}
				}
			}
		}
	}

	return nullptr;
}

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

		SPELL* pSpell = GetSpellByID(SpellID);
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

		DWORD Tics = GetSpellDuration(pSpell, (SPAWNINFO*)pLocalPlayer);
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
			if (((EQ_Spell*)pSpell)->GetSpellLevelNeeded(j) > 0 && ((EQ_Spell*)pSpell)->GetSpellLevelNeeded(j) <= MAX_PC_LEVEL)
			{
				if (bUseableClasses) strcat_s(out, ", ");

				sprintf_s(temp, "%s(%d)", GetClassDesc(j), ((EQ_Spell*)pSpell)->GetSpellLevelNeeded(j));
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

		DWORD Tics = GetSpellDuration(pSpell, (SPAWNINFO*)pLocalPlayer);
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
			if (((EQ_Spell*)pSpell)->GetSpellLevelNeeded(j) > 0 && ((EQ_Spell*)pSpell)->GetSpellLevelNeeded(j) <= MAX_PC_LEVEL)
			{
				if (bUseableClasses) strcat_s(out, ", ");

				sprintf_s(temp, "%s(%d)", GetClassDesc(j), ((EQ_Spell*)pSpell)->GetSpellLevelNeeded(j));
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

		CONTENTS* item = static_cast<CONTENTS*>(pThis->pItem);
		ITEMINFO* Item = GetItemFromContents(item);

		char out[MAX_STRING * 2] = { 0 };

		UpdateStrings_Trampoline();
		std::scoped_lock lock(s_mutex);

		// add the strings to our map

		CXStr text =  STMLToText(pThis->ItemInformationText);

		contentsitemstrings[index].ItemInformationText = text;

		text = STMLToText(pThis->ItemInfo);
		contentsitemstrings[index].ItemInfo = text;

		text = STMLToText(pThis->ItemMadeByText);
		contentsitemstrings[index].ItemMadeByText = text;

		text = STMLToText(pThis->ItemAdvancedLoreText);
		contentsitemstrings[index].ItemAdvancedLoreText = text;

		text = STMLToText(pThis->WindowTitle);
		contentsitemstrings[index].WindowTitle = text;

		if (pThis->bCollectedReceived)
		{
			contentsitemstrings[index].bCollectedRecieved = true;
			contentsitemstrings[index].bCollected = pThis->bCollected;
		}
		else
		{
			contentsitemstrings[index].bCollectedRecieved = false;
			contentsitemstrings[index].bCollected = false;
		}

		if (pThis->bScribedReceived)
		{
			contentsitemstrings[index].bScribedRecieved = true;
			contentsitemstrings[index].bScribed = pThis->bScribed;
		}
		else
		{
			contentsitemstrings[index].bScribedRecieved = false;
			contentsitemstrings[index].bScribed = false;
		}

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

		// Dewey 2461 - user defined score 12-22-2012
		AddGearScores(pThis->pItem, Item, out, "<BR>");

		if (((EQ_Item*)item)->IsStackable())
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
			int Secs = GetItemTimer(item);

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
					if (ITEMINFO* pItem = GetItemFromContents(buttonInfo.ItemDisplayWnd->pItem))
					{
						std::string url = fmt::format(
							"http://lucy.allakhazam.com/item.html?id={}", pItem->ItemNumber);
						ShellExecute(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
					}

					return 0;
				}
			}
		}
		else if (Message == XWM_LCLICK)
		{
			auto i = ButtonMap.find((CButtonWnd*)pWnd);

			if (i != ButtonMap.end())
			{
				switch (i->second.ID)
				{
				case 2: // Toggle the Need Loot Filter
				{
					if (i->first->bChecked)
					{
						// check need
						// uncheck 3 and 4
						for (auto j = ButtonMap.begin(); j != ButtonMap.end(); j++)
						{
							if (j->second.ItemDisplayWnd == i->second.ItemDisplayWnd)
							{
								if (j->second.ID == 3 || j->second.ID == 4)
								{
									j->first->bChecked = false;
								}
							}
						}

						if (ITEMINFO* pItem = GetItemFromContents(i->second.ItemDisplayWnd->pItem))
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
						bool bAutoRollisChecked = false;
						for (auto j = ButtonMap.begin(); j != ButtonMap.end(); j++)
						{
							if (j->second.ItemDisplayWnd == i->second.ItemDisplayWnd)
							{
								if (j->second.ID == 5)
								{
									bAutoRollisChecked = j->first->bChecked;
									break;
								}
							}
						}

						if (ITEMINFO* pItem = GetItemFromContents(i->second.ItemDisplayWnd->pItem))
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
									if (bAutoRollisChecked)
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
					if (i->first->bChecked)
					{
						// check greed
						// uncheck 2 and 4
						bool bAutoRollisChecked = false;
						for (auto j = ButtonMap.begin(); j != ButtonMap.end(); j++)
						{
							if (j->second.ItemDisplayWnd == i->second.ItemDisplayWnd)
							{
								if (j->second.ID == 2 || j->second.ID == 4) {
									j->first->bChecked = false;
								}
								else if (j->second.ID == 5)
								{
									bAutoRollisChecked = j->first->bChecked;
								}
							}
						}

						if (ITEMINFO* pItem = GetItemFromContents(i->second.ItemDisplayWnd->pItem))
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
						bool bAutoRollisChecked = false;

						for (auto j = ButtonMap.begin(); j != ButtonMap.end(); j++)
						{
							if (j->second.ItemDisplayWnd == i->second.ItemDisplayWnd)
							{
								if (j->second.ID == 5)
								{
									bAutoRollisChecked = j->first->bChecked;
									break;
								}
							}
						}

						if (ITEMINFO* pItem = GetItemFromContents(i->second.ItemDisplayWnd->pItem))
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
									if (bAutoRollisChecked)
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
					if (i->first->bChecked)
					{
						// check never
						// uncheck 2 and 3
						bool bAutoRollisChecked = false;
						for (auto j = ButtonMap.begin(); j != ButtonMap.end(); j++)
						{
							if (j->second.ItemDisplayWnd == i->second.ItemDisplayWnd)
							{
								if (j->second.ID == 2 || j->second.ID == 3)
								{
									j->first->bChecked = false;
								}
								else if (j->second.ID == 5)
								{
									bAutoRollisChecked = j->first->bChecked;
								}
							}
						}

						if (ITEMINFO* pItem = GetItemFromContents(i->second.ItemDisplayWnd->pItem))
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
						bool bAutoRollisChecked = false;

						for (auto j = ButtonMap.begin(); j != ButtonMap.end(); j++)
						{
							if (j->second.ItemDisplayWnd == i->second.ItemDisplayWnd)
							{
								if (j->second.ID == 5)
								{
									bAutoRollisChecked = j->first->bChecked;
									break;
								}
							}
						}

						if (ITEMINFO* pItem = GetItemFromContents(i->second.ItemDisplayWnd->pItem))
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
									if (bAutoRollisChecked)
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
					if (i->first->bChecked)
					{
						// check autoroll
						if (ITEMINFO* pItem = GetItemFromContents(i->second.ItemDisplayWnd->pItem))
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
									else  if (bGreed)
									{
										pLootFiltersManager->SetItemLootFilter(pItem->ItemNumber, pItem->IconNumber, pItem->Name, 5, false, true);
									}
									else  if (bNever)
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
						if (ITEMINFO* pItem = GetItemFromContents(i->second.ItemDisplayWnd->pItem))
						{
							pLootFiltersManager->RemoveItemLootFilter(pItem->ItemNumber, 1);
						}
					}
					return 0;
				}

				case 6: // open in lucy
				{
					if (ITEMINFO* pItem = GetItemFromContents(i->second.ItemDisplayWnd->pItem))
					{
						std::string url = "http://lucy.allakhazam.com/item.html?id=";
						char szID[64] = { 0 };
						_itoa_s(pItem->ItemNumber, szID, 10);
						url.append(szID);

						if (CHtmlWnd* ItemHtmlwnd = pCWebManager->CreateHtmlWnd(url.c_str(), pItem->Name, nullptr, true, pItem->Name))
						{
							ItemHtmlwnd->SetMinClientSize({ 10, 20 });
							ItemHtmlwnd->SetMaximizable(true);
							ItemHtmlwnd->SetWindowStyle(CWS_USEMYALPHA | CWS_RESIZEBORDER | CWS_MAXIMIZE | CWS_CLOSE | CWS_TITLE | CWS_MINIMIZE);
							int oldwidth = ItemHtmlwnd->GetLocation().right - ItemHtmlwnd->GetLocation().left;
							int oldheight = ItemHtmlwnd->GetLocation().bottom - ItemHtmlwnd->GetLocation().top;
							int ourleftloc = ItemHtmlwnd->GetLocation().left;
							int ourtoploc = ItemHtmlwnd->GetLocation().top;

							// left top right bottom
							ItemHtmlwnd->SetLocation({ ourleftloc,
								ourtoploc,
								ItemHtmlwnd->GetLocation().left + 759,
								ItemHtmlwnd->GetLocation().top + 539 });

							ItemInfoManager& manager = ItemInfoManager::GetInstance();
							manager.htmlwnd = ItemHtmlwnd;
							int width = manager.htmlwnd->GetLocation().right - manager.htmlwnd->GetLocation().left;
							int height = manager.htmlwnd->GetLocation().bottom - manager.htmlwnd->GetLocation().top;

							ItemHtmlwnd->Resize(width + 1, height + 1);
							ItemHtmlwnd->SetClientCallbacks(&manager);
							// maybe later im not 100% sure what observers are for
							// ItemHtmlwnd->AddObserver(&manager);
						}
					}
					return 0;
				}
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

		CONTENTS* item = pThis->pItem;
		ITEMINFO* Item = GetItemFromContents(item);

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

					if (ITEMINFO* pItem = GetItemFromContents(pThis->pItem))
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

	static void PrintItem(CONTENTS* pCont, CONTENTS* pEquipped)
	{
		if (ITEMINFO* pItem = GetItemFromContents(pCont))
		{
			if (CanIUseThisItem(pItem))
			{
				if (ITEMINFO* pItem2 = GetItemFromContents(pEquipped))
				{
					CXPoint pt{ (int)EQADDR_MOUSE->X + 5, (int)EQADDR_MOUSE->Y + 5 };

					pCompareTipWnd->Move(pt);
					pCompareTipWnd->SetZLayer(0);
					pCompareTipWnd->Display->SetSTMLText("");
					pCompareTipWnd->Display->ForceParseNow();

					char szTemp[MAX_STRING] = { 0 };
					char szTemp2[MAX_STRING] = { 0 };
					DWORD realcolor = 0xFF00FF00;

					sprintf_s(szTemp, "<c \"#FFFF00\">%s<br></c><c \"#FFFFFF\">%s %s </c><br>", pItem->Name, pItem->Lore ? "[Lore]" : "", pItem->NoDrop ? "" : "[No Drop]");
					pCompareTipWnd->Display->SetSTMLText(szTemp);

					sprintf_s(szTemp, "<c \"#FFFF00\">%s<br></c>", GetSlots(pItem, szTemp2));
					pCompareTipWnd->Display->AppendSTML(szTemp);

					DWORD color = 0xFF0000;
					int ACStat = pItem->AC - pItem2->AC;
					if (ACStat > 0)
						color = 0x00FF00;

					sprintf_s(szTemp, "<c \"#FFFFFF\">Rec Level: </c><c \"#00FF00\">%d</c><c \"#FFFFFF\">&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;&NBSP;AC: </c><c \"#%06X\">%d</c><br>", pItem->RequiredLevel, color, ACStat);
					pCompareTipWnd->Display->AppendSTML(szTemp);

					pCompareTipWnd->Display->ForceParseNow();
					pCompareTipWnd->SetVisible(true);
				}
			}
		}
	}

	int CInvSlotWnd_DrawTooltipTramp(const CXWnd* pwnd) const;
	int CInvSlotWnd_DrawTooltipDetour(const CXWnd* pwnd) const
	{
		if (!gCompareTip)
		{
			return CInvSlotWnd_DrawTooltipTramp(pwnd);
		}

		CInvSlotWnd* wnd = (CInvSlotWnd*)this;
		CONTENTS* pCont = nullptr;

		if (wnd->pInvSlot)
		{
			wnd->pInvSlot->GetItemBase(&pCont);
		}

		if (pCont && pCont != pOldCont)
		{
			pOldCont = pCont;

			if (ITEMINFO* pItem = GetItemFromContents(pCont))
			{
				if (pCompareTipWnd && pCompareTipWnd->Display)
				{
					if (CONTENTS* pEquipped = GetEquippedSlot(pCont))
					{
						PrintItem(pCont, pEquipped);
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

void RequestConvertItem(SPAWNINFO* pSpawn, char* szLine)
{
	if (szLine && szLine[0] != '\0')
	{
		GetArg(ConvertFrom, szLine, 1);

		if (CONTENTS* pCont = FindItemByName(ConvertFrom))
		{
			if (ITEMINFO* pItem = GetItemFromContents(pCont))
			{
				if (CItemDisplayManager* mgr = pItemDisplayManager)
				{
					int index = mgr->FindWindow(true);
					if (index == -1)
					{
						index = mgr->CreateWindowInstance();
					}

					if (index > -1 && index < mgr->pWindows.Count)
					{
						if (CItemDisplayWnd* itemDis = (CItemDisplayWnd*)mgr->pWindows[index])
						{
							itemDis->SetItem(&pCont, 0);
							itemDis->RequestConvertItem();
						}
					}
				}
			}
			return;
		}
	}

	WriteChatf("\agUSAGE:\ax /convertitem \ay\"<item name>\"\ax");
	WriteChatf("\agEaxmple:\ax /convertitem \ay\"Wishing Lamp:\"\ax");
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
	char szArg1[MAX_STRING] = { 0 };
	char szArg2[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);
	GetArg(szArg2, szLine, 2);

	CONTENTS* pCont = nullptr;
	if (szArg1[0] != '\0' && IsNumber(szArg1))
	{
		if (szArg2[0] == '\0')
		{
			// its an itemid...
			int iID = GetIntFromString(szArg1, -1);
			pCont = FindItemByID(iID);
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
			pCont = FindItemBySlot(slot1, slot2);
		}
	}
	else if (szArg1[0] != '\0')
	{
		// its a itemname....
		pCont = FindItemByName(szArg1);
	}

	if (!pCont)
	{
		WriteChatColor("/insertaug USAGE: /insertaug \ay#######\ax where ####### is the itemid OR \ay\"Item Name in Quotes\"\ax OR \ay## ##\ax where ## ## are slotnumbers the item is in.", CONCOLOR_WHITE);
		WriteChatColor("Example1: /insertaug \ay41302\ax", CONCOLOR_WHITE);
		WriteChatColor("Example2: /insertaug \ay\"Darkened Thick Banded Belt\"\ax", CONCOLOR_WHITE);
		WriteChatColor("Example3: /insertaug \ay20 -1\ax", CONCOLOR_WHITE);
		return;
	}

	if (PcProfile* pMe = GetPcProfile())
	{
		if (pMe->pInventoryArray)
		{
			if (CONTENTS* pCursor = pMe->pInventoryArray->Inventory.Cursor)
			{
				int Slot = 0;
				bool bFits = false;
				for (; Slot < 6; Slot++)
				{
					int fit = ((EQ_Item*)pCont)->GetAugmentFitBySlot(&pCursor, Slot);

					if (fit == 0)
					{
						bFits = true;
						break;
					}
				}

				if (bFits)
				{
					if (CItemDisplayManager* mgr = pItemDisplayManager)
					{
						int index = mgr->FindWindow(true);
						if (index == -1)
						{
							index = mgr->CreateWindowInstance();
						}

						if (index > -1 && index < mgr->pWindows.Count)
						{
							if (CItemDisplayWnd* itemDis = (CItemDisplayWnd*)mgr->pWindows[index])
							{
								itemDis->SetItem(&pCont, 0);

								if (ITEMINFO* pTheAug = GetItemFromContents(pCursor))
								{
									// hack to bypass popupdialog...
									int oldsolv = std::exchange(pTheAug->SolventItemID, 0);
									bool oldattn = std::exchange(pTheAug->Attuneable, false);

									// now the actual function call...
									itemDis->InsertAugmentRequest(Slot);

									// ok so lets restore the org values...
									pTheAug->SolventItemID = oldsolv;
									pTheAug->Attuneable = oldattn;
								}
							}
						}
					}
				}
				else
				{
					if (ITEMINFO* ptheAug = GetItemFromContents(pCursor))
					{
						if (ITEMINFO* ptheItem = GetItemFromContents(pCont))
						{
							WriteChatf("\ayCould NOT insert the\ax \at%s\ax into the \ag%s\ax", ptheAug->Name, ptheItem->Name);
						}
					}
				}
			}
		}
	}
}

void RemoveAug(SPAWNINFO* pChar, char* szLine)
{
	if (PcProfile* pMe = GetPcProfile())
	{
		if (pMe->pInventoryArray)
		{
			if (CONTENTS* pCursor = pMe->pInventoryArray->Inventory.Cursor)
			{
				if (const char* pError = pStringTable->getString(5478, nullptr))
				{
					WriteChatf("\ay%s", pError);
				}
				return;
			}
		}
	}

	char szArg1[MAX_STRING] = { 0 };
	char szArg2[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);
	GetArg(szArg2, szLine, 2);

	CONTENTS* pCont = nullptr;

	if (szArg2[0] != '\0' && IsNumber(szArg2))
	{
		// its an id
		int iID = GetIntFromString(szArg2, -1);
		pCont = FindItemByID(iID);
	}
	else if (szArg2[0] != '\0')
	{
		// its a name...
		pCont = FindItemByName(szArg2, true);
	}

	if (!pCont || szArg1[0] == '\0')
	{
		WriteChatColor("/removeaug USAGE: /removeaug \ay<augid>\ax <#####> OR \ay<augname>\ax \"Name in quotes\" \ay<itemid>\ax <#####> OR \ay<itemname>\ax \"Name in quotes\"", CONCOLOR_WHITE);
		WriteChatColor("NOTE! /removeaug \ayIS A CASE SENSITIVE FUNCTION\ax", CONCOLOR_WHITE);
		WriteChatColor("Example1: /removeaug \ay50502\ax \ay41302\ax", CONCOLOR_WHITE);
		WriteChatColor("Example2: /removeaug \ay\"Crude Defiant Ruby Shard\"\ax \"Darkened Thick Banded Belt\"", CONCOLOR_WHITE);
		WriteChatColor("Example2: /removeaug \ay\"Crude Defiant Ruby Shard\"\ax \ay41302\ax", CONCOLOR_WHITE);
		WriteChatColor("Example2: /removeaug \ay50502\ax \"Darkened Thick Banded Belt\"", CONCOLOR_WHITE);
		return;
	}

	int Slot = 0;
	bool bFound = false;
	int iID = 0;
	if (IsNumber(szArg1))
	{
		// its an id
		iID = GetIntFromString(szArg1, 0);
	}

	ITEMINFO* ptheAug = nullptr;
	if (iID)
	{
		for (; Slot < 6; Slot++)
		{
			if (CONTENTS* pAug = pCont->GetContent(Slot))
			{
				if (iID == pAug->ID)
				{
					if (ptheAug = GetItemFromContents(pAug))
					{
						// found it...
						bFound = true;
						break;
					}
				}
			}
		}
	}
	else
	{
		for (; Slot < 6; Slot++)
		{
			if (CONTENTS* pAug = pCont->GetContent(Slot))
			{
				if (ptheAug = GetItemFromContents(pAug))
				{
					if (!_stricmp(ptheAug->Name, szArg1))
					{
						bFound = true;
						break;
					}
				}
			}
		}
	}

	if (bFound)
	{
		if (CItemDisplayManager*mgr = pItemDisplayManager)
		{
			int index = mgr->FindWindow(true);
			if (index == -1)
			{
				index = mgr->CreateWindowInstance();
			}

			if (index > -1 && index < mgr->pWindows.Count)
			{
				if (CItemDisplayWnd* itemDis = (CItemDisplayWnd*)mgr->pWindows[index])
				{
					itemDis->SetItem(&pCont, 0);
					if (ptheAug)
					{
						CONTENTS* contout = nullptr;
						CONTENTS** pContsolv = nullptr;
						int realID = 0;

						// we need to check for all distillers
						int minreqid = ptheAug->SolventItemID;

						CDistillerInfo* pDistillerInfo = &CDistillerInfo::Instance();
						if (pDistillerInfo)
						{
							for (int i = minreqid; i <= 21; i++)
							{
								realID = pDistillerInfo->GetIDFromRecordNum(i, 0);

								pContsolv = ((PcZoneClient*)pPCData)->GetItemByID(&contout, realID);
								if (contout)
								{
									// found a distiller that will work...
									break;
								}
							}
						}

						if (!contout)
						{
							// Universal Augment Solvent... aka perfect distiller...
							pContsolv = ((PcZoneClient*)pPCData)->GetItemByItemClass(&contout, 64);
						}

						if (contout)
						{
							// we shouldnt do the solvent thing for removals, people who macro this can click the ok button on the confirmation window...
							itemDis->RemoveAugmentRequest(Slot);
						}
						else
						{
							if (const char* pError = pStringTable->getString(5474, NULL))
							{
								WriteChatf("\ay%s", pError);
							}
							return;
						}
					}
				}
			}
			}
		}
	else
	{
		if (ptheAug)
		{
			if (ITEMINFO* ptheItem = GetItemFromContents(pCont))
			{
				WriteChatf("\ayCould NOT remove the\ax \at%s\ax from the \ag%s\ax", ptheAug->Name, ptheItem->Name);
			}
		}
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

char  ReportChannel[MAX_STRING];
char  ReportBestStr[MAX_STRING];
char  ReportBestSlot[MAX_STRING];
char  ReportBestName[MAX_STRING];
int   ClickGroup = 0;
int   ClickGuild = 0;
int   ClickRaid = 0;
int   ClickAny = 0;
int   IniLoaded = 0;
int   BestSlot = 0;
float BestScore = 0;
float CurrScore = 0;
int CurrSlot = 0;

struct trATR
{
	char* Name;
	float Weight;
	float Val;
	float Best;
};

int      AttribMax = 26;
trATR    AttribList[] = {
/*00*/ { "AC",            0, 0 },
/*01*/ { "HP",            0, 0 },
/*02*/ { "HPReg",         0, 0 },
/*03*/ { "Mana",          0, 0 },
/*04*/ { "ManaReg",       0, 0 },
/*05*/ { "hSTR",          0, 0 },
/*06*/ { "hSTA",          0, 0 },
/*07*/ { "hAGI",          0, 0 },
/*08*/ { "hDEX",          0, 0 },
/*09*/ { "hINT",          0, 0 },
/*10*/ { "hWIS",          0, 0 },
/*11*/ { "hCHR",          0, 0 },
/*12*/ { "Heal",          0, 0 },
/*13*/ { "Nuke",          0, 0 },
/*14*/ { "Clrv",          0, 0 },
/*15*/ { "Attack",        0, 0 },
/*16*/ { "Accuracy",      0, 0 },
/*17*/ { "CE",            0, 0 },
/*18*/ { "StrikeThrough", 0, 0 },
/*19*/ { "Avoidance",     0, 0 },
/*20*/ { "Shielding",     0, 0 },
/*21*/ { "DoTShielding",  0, 0 },
/*22*/ { "SpellShield",   0, 0 },
/*23*/ { "Stun",          0, 0 },
/*24*/ { "DS",            0, 0 },
/*25*/ { "Haste",         0, 0 },
/*26*/ { "Ratio",         0, 0 },
};

struct tSLOTINFO
{
	uint32_t SlotMask;
	char*    SlotName;
};

tSLOTINFO SlotInfo[] = {
/*00 | 0x000001*/ { 1,         "Charm" },
/*01 | 0x000002*/ { 2,         "Left Ear" },
/*02 | 0x000004*/ { 4,         "Head" },
/*03 | 0x000008*/ { 8,         "Face" },
/*04 | 0x000010*/ { 16,        "Right Ear" },
/*05 | 0x000020*/ { 32,        "Neck" },
/*06 | 0x000040*/ { 64,        "Shoulders" },
/*07 | 0x000080*/ { 128,       "Arms" },
/*08 | 0x000100*/ { 256,       "Back" },
/*09 | 0x000200*/ { 512,       "Left Wrist" },
/*10 | 0x000401*/ { 1024,      "Right Wrist" },
/*11 | 0x000800*/ { 2048,      "Range" },
/*12 | 0x001000*/ { 4096,      "Hands" },
/*13 | 0x002000*/ { 8192,      "Primary" },
/*14 | 0x004000*/ { 16384,     "Secondary" },
/*15 | 0x008000*/ { 32768,     "Left Finger" },
/*16 | 0x010000*/ { 65536,     "Right Finger" },
/*17 | 0x020000*/ { 131072,    "Chest" },
/*18 | 0x040000*/ { 262144,    "Legs" },
/*19 | 0x080000*/ { 524288,    "Feet" },
/*20 | 0x100000*/ { 1048576,   "Waist" },
/*21 | 0x200000*/ { 2097152,   "Power Source" },
/*22 | 0x400000*/ { 4194304,   "Ammo" },
/*23 | 0x800000*/ { 0,         nullptr }
};

// ***************************************************************************
//	This section is methods to interact with the AttributeList
// ***************************************************************************

void LoadAttribListWeights(char* Section)
{
	char szVal[MAX_STRING];

	for (int i = 0; i <= AttribMax; i++)
	{
		GetPrivateProfileString(Section, AttribList[i].Name, "0", szVal, 256, INIFileName);
		AttribList[i].Weight = GetFloatFromString(szVal, 0);
	}
}

void SaveAttribListWeights(char* Section)
{
	char szVal[MAX_STRING];

	for (int i = 0; i <= AttribMax; i++)
	{
		sprintf_s(szVal, "%0.2f", AttribList[i].Weight);
		WritePrivateProfileString(Section, AttribList[i].Name, szVal, INIFileName);
	}
}

int SetAttribListWeight(char* Key, char* Val)
{
	for (int i = 0; i <= AttribMax; i++)
	{
		if (_stricmp(AttribList[i].Name, Key) == 0)
		{
			WriteChatf("MQ2GearScore::Setting %s to %s", AttribList[i].Name, Val);
			AttribList[i].Weight = GetFloatFromString(Val, 0);
			return 1;
		}
	}
	return 0;
}

void ClearAttribListWeights()
{
	for (int i = 0; i <= AttribMax; i++)
		AttribList[i].Weight = 0;
}

void ClearAttribListScores()
{
	BestSlot = 0;
	BestScore = 0;
	for (int i = 0; i <= AttribMax; i++)
	{
		AttribList[i].Val = 0;
		AttribList[i].Best = 0;
	}
}

void ClearAttribListVal()
{
	for (int i = 0; i <= AttribMax; i++)
	{
		AttribList[i].Val = 0;
	}
}

void LoadAttribListVal(ITEMINFO* pItem)
{
	AttribList[0].Val = static_cast<float>(pItem->AC);
	AttribList[1].Val = static_cast<float>(pItem->HP);
	AttribList[2].Val = static_cast<float>(pItem->HPRegen);
	AttribList[3].Val = static_cast<float>(pItem->Mana);
	AttribList[4].Val = static_cast<float>(pItem->ManaRegen);
	AttribList[5].Val = static_cast<float>(pItem->HeroicSTR);
	AttribList[6].Val = static_cast<float>(pItem->HeroicSTA);
	AttribList[7].Val = static_cast<float>(pItem->HeroicAGI);
	AttribList[8].Val = static_cast<float>(pItem->HeroicDEX);
	AttribList[9].Val = static_cast<float>(pItem->HeroicINT);
	AttribList[10].Val = static_cast<float>(pItem->HeroicWIS);
	AttribList[11].Val = static_cast<float>(pItem->HeroicCHA);
	AttribList[12].Val = static_cast<float>(pItem->HealAmount);
	AttribList[13].Val = static_cast<float>(pItem->SpellDamage);
	AttribList[14].Val = static_cast<float>(pItem->Clairvoyance);
	AttribList[15].Val = static_cast<float>(pItem->Attack);
	AttribList[16].Val = 0; // FIX THIS static_cast<float>(pItem->Accuracy);
	AttribList[17].Val = 0; // FIX THIS static_cast<float>(pItem->CombatEffects);
	AttribList[18].Val = 0; // FIX THIS static_cast<float>(pItem->StrikeThrough);
	AttribList[19].Val = 0; // FIX THIS static_cast<float>(pItem->Avoidance);
	AttribList[20].Val = 0; // FIX THIS static_cast<float>(pItem->Shielding);
	AttribList[21].Val = 0; // FIX THIS static_cast<float>(pItem->DoTShielding);
	AttribList[22].Val = 0; // FIX THIS static_cast<float>(pItem->SpellShield);
	AttribList[23].Val = 0; // FIX THIS static_cast<float>(pItem->StunResist);
	AttribList[24].Val = 0; // FIX THIS static_cast<float>(pItem->DamageShieldMitigation);
	AttribList[25].Val = static_cast<float>(pItem->Haste);
	AttribList[26].Val = static_cast<float>(pItem->Damage) / (pItem->Delay == 0 ? 1.0f : static_cast<float>(pItem->Delay));
}
#undef cvtfloat

float CalcItemGearScore(ITEMINFO* pItem)
{
	float score = 0;
	LoadAttribListVal(pItem);

	for (int i = 0; i <= AttribMax; i++)
	{
		score = score + AttribList[i].Val * AttribList[i].Weight;
	}
	return score;
}

void CheckForBest(float ItemScore, int ItemSlot)
{
	if (ItemScore < BestScore)
	{
		for (int i = 0; i <= AttribMax; i++)
		{
			AttribList[i].Best = AttribList[i].Val;
		}
		BestScore = ItemScore;
		BestSlot = ItemSlot;
	}
}

// ***************************************************************************
//	This section is to set, save, and report global profile variables.
// ***************************************************************************

void ClearProfile(int Echo)
{
	sprintf_s(ReportChannel, "None");
	ClickGroup = 0;
	ClickGuild = 0;
	ClickRaid = 0;
	ClickAny = 0;
	ClearAttribListWeights();
	if (Echo) WriteChatf("MQ2ItemDisplay::plugin variables cleared but not saved.");
}

void ReadProfile(char* pName, int Echo)
{
	if (Echo) WriteChatf("MQ2ItemDisplay::loading settings for [%s]", pName);
	GetPrivateProfileString(pName, "Report", "None", ReportChannel, 256, INIFileName);
	ClickGroup = GetPrivateProfileInt(pName, "ClickGroup", 0, INIFileName);
	ClickGuild = GetPrivateProfileInt(pName, "ClickGuild", 0, INIFileName);
	ClickRaid = GetPrivateProfileInt(pName, "ClickRaid", 0, INIFileName);
	ClickAny = GetPrivateProfileInt(pName, "ClickAny", 0, INIFileName);
	LoadAttribListWeights(pName);
	IniLoaded = 1;
}

void WriteProfile(char* pName, int Echo)
{
	char szKey[MAX_STRING];

	WritePrivateProfileString(pName, "Report", ReportChannel, INIFileName);
	sprintf_s(szKey, "%d", ClickGroup);	WritePrivateProfileString(pName, "ClickGroup", szKey, INIFileName);
	sprintf_s(szKey, "%d", ClickGuild);	WritePrivateProfileString(pName, "ClickGuild", szKey, INIFileName);
	sprintf_s(szKey, "%d", ClickRaid);	WritePrivateProfileString(pName, "ClickRaid", szKey, INIFileName);
	sprintf_s(szKey, "%d", ClickAny);	WritePrivateProfileString(pName, "ClickAny", szKey, INIFileName);
	SaveAttribListWeights(pName);

	if (Echo) WriteChatf("MQ2ItemDisplay::saving settings for [%s]", pName);
}

void EchoProfile(int reporting, int clicking, int weights)
{
	if (reporting)
	{
		WriteChatf("MQ2GearScore::Report to [ %s ]", ReportChannel);
	}

	if (clicking)
	{
		WriteChatf("MQ2GearScore::ClickGroup = %d", ClickGroup);
		WriteChatf("MQ2GearScore::ClickGuild = %d", ClickGuild);
		WriteChatf("MQ2GearScore::ClickRaid  = %d", ClickRaid);
		WriteChatf("MQ2GearScore::ClickAny   = %d", ClickAny);
	}

	if (weights)
	{
		for (int i = AttribMax; i >= 0; i--)
		{
			WriteChatf("MQ2ItemDisplay::%s = %0.0f", AttribList[i].Name, AttribList[i].Weight);
		}
	}
}

void EchoHelp(int Echo)
{
	WriteChatf("MQ2ItemDisplay::Commands :");
	WriteChatf("  /iScore clear -- resets all variables");
	WriteChatf("  /iScore click [Group|Guild|Raid|Any] -- auto click links for these sources");
	WriteChatf("  /iScore cursor -- evaluate item on cursor");
	WriteChatf("  /iScore report [Channel] -- send upgrade using this command ex: /bc ");
	WriteChatf("  /iScore load -- load settings from disk");
	WriteChatf("  /iScore save -- save current settings to disk");
	WriteChatf("  /iScore [attribute] [weight] -- sets an item weight");
}

void EchoCommands(int Echo)
{
	EchoHelp(TRUE);
	EchoProfile(FALSE, TRUE, FALSE);
	EchoProfile(TRUE, FALSE, TRUE);
}

// ***************************************************************************
//	This section is for each of the user commands.
// ***************************************************************************

void DoScoreForCursor();

void SetReportChannel(char* pName, char* Val)
{
	strcpy_s(ReportChannel, Val);
	EchoProfile(TRUE, FALSE, FALSE);
}

void SetClickMode(char* pName, char* Val)
{
	if (_stricmp(Val, "Group") == 0) ClickGroup = !ClickGroup;
	if (_stricmp(Val, "Guild") == 0) ClickGuild = !ClickGuild;
	if (_stricmp(Val, "Raid") == 0) ClickRaid = !ClickRaid;
	if (_stricmp(Val, "Any") == 0) ClickAny = !ClickAny;
	EchoProfile(FALSE, TRUE, FALSE);
}

// ***************************************************************************
//	This is the actual entry point for user commands. Parse and divy up the work.
// ***************************************************************************

void DoGearScoreUserCommand(PSPAWNINFO pChar, char* szLine)
{
	char Key[MAX_STRING] = { 0 };
	char Val[MAX_STRING] = { 0 };
	char* pName = GetCharInfo()->Name;
	if (!pName) return;
	GetArg(Key, szLine, 1);
	GetArg(Val, szLine, 2);

	if (_stricmp(Key, "save") == 0) { WriteProfile(pName, TRUE); return; }
	if (_stricmp(Key, "load") == 0) { ReadProfile(pName, TRUE);	return; }
	if (_stricmp(Key, "report") == 0) { SetReportChannel(pName, Val); return; }
	if (_stricmp(Key, "click") == 0) { SetClickMode(pName, Val); return; }
	if (_stricmp(Key, "cursor") == 0) { DoScoreForCursor(); return; }
	if (_stricmp(Key, "clear") == 0) { ClearProfile(TRUE); return; }
	if (_stricmp(Key, "help") == 0) { EchoHelp(TRUE); return; }
	if (Key[0] == 0) { EchoCommands(TRUE); return; }
	SetAttribListWeight(Key, Val);
}

void DoScoreForCursor()
{
	if (PcProfile* pProfile = GetPcProfile())
	{
		if (pProfile->pInventoryArray)
		{
			if (CONTENTS* pCursorContents = pProfile->pInventoryArray->Inventory.Cursor)
			{
				if (ITEMINFO* pCursorItem = GetItemFromContents(pCursorContents))
				{
					char Temp[MAX_STRING];
					AddGearScores(pCursorContents, pCursorItem, Temp, "\n");
					WriteChatf("MQ2ItemDisplay::Cursor item %s", pCursorItem->Name);
					WriteChatf("%s", Temp);
				}
			}
		}
	}
}

class MQ2GearScoreType : public MQ2Type
{
public:
	enum GearScoreMembers
	{
		Upgrade = 1,
		UpgradeName = 2,
		UpgradeSlot = 3,
	};

	MQ2GearScoreType() : MQ2Type("GearScore")
	{
		TypeMember(Upgrade);
		TypeMember(UpgradeName);
		TypeMember(UpgradeSlot);
	}

	bool MQ2GearScoreType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest) override
	{
		MQTypeMember* pMember = MQ2GearScoreType::FindMember(Member);

		if (!pMember)
			return false;

		char* pName = GetCharInfo()->Name;
		if (!pName)
			return false;

		switch (static_cast<GearScoreMembers>(pMember->ID))
		{
		case Upgrade:
			Dest.Type = pStringType;
			Dest.Ptr = ReportBestStr;
			return true;

		case UpgradeName:
			Dest.Type = pStringType;
			Dest.Ptr = ReportBestName;
			return true;

		case UpgradeSlot:
			Dest.Type = pStringType;
			Dest.Ptr = ReportBestSlot;
			return true;
		}

		return false;
	}

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		strcpy_s(Destination, MAX_STRING, "TRUE");
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
MQ2GearScoreType* pGearScoreType = nullptr;

bool dataGearScore(const char* szName, MQTypeVar& Dest)
{
	Dest.DWord = 1;
	Dest.Type = pGearScoreType;
	return true;
}

template <unsigned int _Size>
void AddGearScore_CheckAugSlot(ITEMINFO* pItem, float score, int SlotNum, char* SlotName, CONTENTS* pInvContent, ITEMINFO* pInvItem, DWORD AugType, DWORD AugSlot, char(&out)[_Size], char* br)
{
	if (!AugType) return; // This worn item does not have an aug slot for [n]
	DWORD mask = (1 << (AugType - 1));
	if ((mask & pItem->AugType) == 0) return; // Calculate a bitmask and compare to the aug we have, does it fit?

	char temp[MAX_STRING];
	ITEMINFO* pAug = NULL;
	if (pInvContent
		&& pInvContent->Contents.ContainedItems.pItems
		&& pInvContent->Contents.ContainedItems.pItems->Item[AugSlot])
	{
		pAug = GetItemFromContents(pInvContent->Contents.ContainedItems.pItems->Item[AugSlot]);
	}

	if (!pAug)
	{
		ClearAttribListVal();
		CheckForBest(0, SlotNum);
		sprintf_s(temp, "%s = empty : UPGRADE%s", SlotName, br);
		strcat_s(out, temp);
		return;
	}

	if (pItem->ItemNumber == pInvItem->ItemNumber)
		return;

	float s2 = CalcItemGearScore(pAug);
	CheckForBest(s2, SlotNum);

	sprintf_s(temp, "%s = %s : %6.0f %s %s", SlotName, pAug->Name, s2, (s2 >= score ? "Keep " : "UPGRADE"), br);
	strcat_s(out, temp);
}

template <unsigned int _Size>
void AddGearScores_CheckAugs(CONTENTS* pSlot, ITEMINFO* pItem, char(&out)[_Size], char* br)
{
	float score = CalcItemGearScore(pItem);
	if (!score) return;

	char temp[MAX_STRING];

	sprintf_s(temp, "Base Aug Score : %6.0f%s", score, br);
	strcat_s(out, temp);

	if (PcProfile* pProfile = GetPcProfile())
	{
		if (pProfile->pInventoryArray)
		{
			ITEMINFO* pInvItem;
			CONTENTS* pInvContent;
			float bestVal = score;

			// Loop over all the worn items
			for (int i = 0; i < BAG_SLOT_START - 1; i++)
			{
				uint32_t mask = SlotInfo[i].SlotMask;
				char* name = SlotInfo[i].SlotName;
				pInvItem = nullptr;
				pInvContent = pProfile->pInventoryArray->InventoryArray[i];
				if (pInvContent)
					pInvItem = GetItemFromContents(pInvContent);

				if (pInvItem && (pItem->EquipSlots & mask) == mask)
				{
					AddGearScore_CheckAugSlot(pItem, score, i, name, pInvContent, pInvItem, pInvItem->AugData.Sockets[0].Type, 0, out, br);
					AddGearScore_CheckAugSlot(pItem, score, i, name, pInvContent, pInvItem, pInvItem->AugData.Sockets[1].Type, 1, out, br);
					AddGearScore_CheckAugSlot(pItem, score, i, name, pInvContent, pInvItem, pInvItem->AugData.Sockets[2].Type, 2, out, br);
					AddGearScore_CheckAugSlot(pItem, score, i, name, pInvContent, pInvItem, pInvItem->AugData.Sockets[3].Type, 3, out, br);
					AddGearScore_CheckAugSlot(pItem, score, i, name, pInvContent, pInvItem, pInvItem->AugData.Sockets[4].Type, 4, out, br);
					AddGearScore_CheckAugSlot(pItem, score, i, name, pInvContent, pInvItem, pInvItem->AugData.Sockets[5].Type, 5, out, br);
				}
			}
		}
	}
}

// DoIHave() - pinkfloydx33 - determine if you already have an item
int DoIHave(ITEMINFO* Item)
{
	DWORD ID = Item->ItemNumber;
	DWORD AugType = Item->AugType;

	int nHowMany = 0;

	if (PcProfile* pProfile = GetPcProfile())
	{
		if (pProfile->pInventoryArray)
		{
			// Normal Inventory worn slots
			for (int iSlot = 0; iSlot < NUM_INV_SLOTS; iSlot++)
			{
				if (CONTENTS* pItem = pProfile->pInventoryArray->InventoryArray[iSlot])
				{
					if (GetItemFromContents(pItem)->ItemNumber == ID)
					{
						if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
							|| (((EQ_Item*)pItem)->IsStackable() != 1))
						{
							nHowMany++;
						}
						else
						{
							nHowMany += pItem->StackCount;
						}
					}
					else // for augs
					{
						if (pItem->Contents.ContainedItems.pItems && pItem->Contents.ContainedItems.Size)
						{
							for (size_t nAug = 0; nAug < pItem->Contents.ContainedItems.Size; nAug++)
							{
								if (pItem->Contents.ContainedItems.pItems->Item[nAug]
									&& GetItemFromContents(pItem->Contents.ContainedItems.pItems->Item[nAug])->Type == ITEMTYPE_NORMAL
									&& GetItemFromContents(pItem->Contents.ContainedItems.pItems->Item[nAug])->AugType
									&& GetItemFromContents(pItem->Contents.ContainedItems.pItems->Item[nAug])->ItemNumber == ID)
								{
									nHowMany++;
								}
							}
						}
					}
				}
			}

			// Bags
			for (int nPack = 0; nPack < 10; nPack++)
			{
				if (CONTENTS* pPack = pProfile->pInventoryArray->Inventory.Pack[nPack])
				{
					if (GetItemFromContents(pPack)->Type == ITEMTYPE_PACK && pPack->Contents.ContainedItems.pItems)
					{
						for (size_t nItem = 0; nItem < GetItemFromContents(pPack)->Slots; nItem++)
						{
							if (CONTENTS* pItem = pPack->Contents.ContainedItems.pItems->Item[nItem])
							{
								if (GetItemFromContents(pItem)->ItemNumber == ID)
								{
									if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
										|| (((EQ_Item*)pItem)->IsStackable() != 1))
									{
										nHowMany++;
									}
									else
									{
										nHowMany += pItem->StackCount;
									}
								}
								else // for augs
								{
									if (pItem->Contents.ContainedItems.pItems && pItem->Contents.ContainedItems.Size)
									{
										for (size_t nAug = 0; nAug < pItem->Contents.ContainedItems.Size; nAug++)
										{
											if (pItem->Contents.ContainedItems.pItems->Item[nAug]
												&& GetItemFromContents(pItem->Contents.ContainedItems.pItems->Item[nAug])->Type == ITEMTYPE_NORMAL
												&& GetItemFromContents(pItem->Contents.ContainedItems.pItems->Item[nAug])->AugType
												&& GetItemFromContents(pItem->Contents.ContainedItems.pItems->Item[nAug])->ItemNumber == ID)
											{
												nHowMany++;
											}
										}
									}
								}
							}
						}
					}
				}
			}

			// Bank slots, not including shared
			for (int nPack = 0; nPack < NUM_BANK_SLOTS; nPack++)
			{
				CHARINFO* pCharInfo = GetCharInfo();
				CONTENTS* pPack = nullptr;
#ifdef NEWCHARINFO
				if (pCharInfo && pCharInfo->BankItems.Items.Size > nPack)
					pPack = pCharInfo->BankItems.Items[nPack].pObject;
#else
				if (pCharInfo && pCharInfo->pBankArray)
					pPack = pCharInfo->pBankArray->Bank[nPack];
#endif
				if (pPack)
				{
					if (GetItemFromContents(pPack)->ItemNumber == ID)
					{
						if ((GetItemFromContents(pPack)->Type != ITEMTYPE_NORMAL)
							|| (((EQ_Item*)pPack)->IsStackable() != 1))
						{
							nHowMany++;
						}
						else
						{
						nHowMany += pPack->StackCount;
						}
					}

					if (GetItemFromContents(pPack)->Type == ITEMTYPE_PACK && pPack->Contents.ContainedItems.pItems)
					{
						for (size_t nItem = 0; nItem < GetItemFromContents(pPack)->Slots; nItem++)
						{
							if (CONTENTS* pItem = pPack->Contents.ContainedItems.pItems->Item[nItem])
							{
								if (GetItemFromContents(pItem)->ItemNumber == ID)
								{
									if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL)
										|| (((EQ_Item*)pItem)->IsStackable() != 1))
									{
										nHowMany++;
									}
									else
									{
										nHowMany += pItem->StackCount;
									}
								}
							}
						}
					}
				}
			}

			for (int nPack = 0; nPack < NUM_SHAREDBANK_SLOTS; nPack++)
			{
				CHARINFO* pCharInfo = GetCharInfo();
				CONTENTS* pPack = nullptr;
#ifdef NEWCHARINFO
				if (pCharInfo && pCharInfo->SharedBankItems.Items.Size > nPack)
					pPack = pCharInfo->SharedBankItems.Items[nPack].pObject;
#else
				if (pCharInfo && pCharInfo->pSharedBankArray)
					pPack = pCharInfo->pSharedBankArray->SharedBank[nPack];
#endif
				if (pPack)
				{
					if (GetItemFromContents(pPack)->ItemNumber == ID)
					{
						if ((GetItemFromContents(pPack)->Type != ITEMTYPE_NORMAL) || (((EQ_Item*)pPack)->IsStackable() != 1))
							nHowMany++;
						else
							nHowMany += pPack->StackCount;
					}

					if (GetItemFromContents(pPack)->Type == ITEMTYPE_PACK && pPack->Contents.ContainedItems.pItems)
					{
						for (size_t nItem = 0; nItem < GetItemFromContents(pPack)->Slots; nItem++)
						{
							if (CONTENTS* pItem = pPack->Contents.ContainedItems.pItems->Item[nItem])
							{
								if (GetItemFromContents(pItem)->ItemNumber == ID)
								{
									if ((GetItemFromContents(pItem)->Type != ITEMTYPE_NORMAL) || (((EQ_Item*)pItem)->IsStackable() != 1))
										nHowMany++;
									else
										nHowMany += pItem->StackCount;
								}
							}
						}
					}
				}
			}
		}
	}

	return nHowMany;
}

void FormatBestStr(ITEMINFO* pItem)
{
	ReportBestStr[0] = 0;
	ReportBestSlot[0] = 0;
	ReportBestName[0] = 0;
	if (BestScore < CurrScore && BestSlot >= 0 && BestSlot <= 23) // We found an item to replace
	{
		char szVerb[MAX_STRING];
		char* pSlotName = SlotInfo[BestSlot].SlotName;
		float v;
		if (BestScore > 0)
			v = 100.0f * (CurrScore / BestScore) - 100.0f;
		else
			v = 100.0f;
		if (CurrSlot < BAG_SLOT_START) return;

		if (CurrSlot < 65500)
			sprintf_s(szVerb, "WEAR [ %s ] As ", pItem->Name);
		else
			sprintf_s(szVerb, "LOOT [ %s ] For ", pItem->Name);

		if (pItem->Lore && DoIHave(pItem))
			sprintf_s(szVerb, "WEAR [ %s ] As ", pItem->Name);

		sprintf_s(ReportBestStr, "%s %s = %+6.1f%%", szVerb, pSlotName, v);

		strcpy_s(ReportBestSlot, pSlotName);
		strcpy_s(ReportBestName, pItem->Name);

		CalcItemGearScore(pItem);

		char szTmp[MAX_STRING];
		strcat_s(ReportBestStr, " =");

		for (int i = 0; i <= AttribMax; i++)
		{
			if (AttribList[i].Weight != 0 && (AttribList[i].Val != AttribList[i].Best))
			{
				sprintf_s(szTmp, " %s %+0.0f", AttribList[i].Name, AttribList[i].Val - AttribList[i].Best);
				strcat_s(ReportBestStr, szTmp);
			}
		}
	}
}

template <unsigned int _Size>
void AddGearScores_CheckItems(CONTENTS* pSlot, ITEMINFO* pItem, char(&out)[_Size], char* br)
{
	char temp[MAX_STRING];
	sprintf_s(temp, "This Item Score : %6.0f%s", CurrScore, br);
	strcat_s(out, temp);

	if (PcProfile* pProfile = GetPcProfile())
	{
		if (pProfile->pInventoryArray)
		{
			for (int i = 0; i < BAG_SLOT_START - 1; i++)
			{
				uint32_t mask = SlotInfo[i].SlotMask;
				if ((pItem->EquipSlots & mask) == mask)
				{
					float score = 0;
					ClearAttribListVal();

					CONTENTS* pInvSlot = pProfile->pInventoryArray->InventoryArray[i];
					if (pInvSlot)
					{
						ITEMINFO* pItemInfo = GetItemFromContents(pInvSlot);
						score = CalcItemGearScore(pItemInfo);
						if (pItemInfo && pItemInfo->ItemNumber != pItem->ItemNumber)
						{
							sprintf_s(temp, "Worn Item Score : %6.0f (%s%s) %s", score, (score - CurrScore > 0 ? "Keep " : "UPGRADE for "), SlotInfo[i].SlotName, br);
							strcat_s(out, temp);
						}
					}
					CheckForBest(score, i);
				}
			}
		}
	}
}

template <unsigned int _Size>
void AddGearScores(CONTENTS* pSlot, ITEMINFO* pItem, char(&out)[_Size], char* br)
{
	static ULONGLONG lastTick = 0;
	ReportBestStr[0] = 0;
	ReportBestSlot[0] = 0;
	ReportBestName[0] = 0;
	if (CanIUseThisItem(pItem) < 1)
		return;

	ClearAttribListScores();
	CurrScore = CalcItemGearScore(pItem);
	if (CurrScore == 0) return;

	CurrSlot = pSlot->GetGlobalIndex().GetTopSlot();
	BestScore = CurrScore;
	BestSlot = 0;
	if (pItem->ItemType == ITEMITEMTYPE_AUGUMENT)
		AddGearScores_CheckAugs(pSlot, pItem, out, br);
	else
		AddGearScores_CheckItems(pSlot, pItem, out, br);

	FormatBestStr(pItem);
	if (BestScore < CurrScore && ReportBestStr[0] != 0)
	{
		strcat_s(out, ReportBestStr);
		strcat_s(out, br);
	}

	// Trap the 3x call back stuff.
	if (MQGetTickCount64() - lastTick > 1000 && ReportBestStr[0] != 0 && ReportChannel[0] == '/')
	{
		char szCmd[MAX_STRING];
		lastTick = MQGetTickCount64();
		sprintf_s(szCmd, "%s %s", ReportChannel, ReportBestStr);
		EzCommand(szCmd);
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

	if (IsXMLFilePresent(TipWndXML))
	{
		if (pSidlMgr && pSidlMgr->FindScreenPieceTemplate("CompareTipWnd"))
		{
			if (pCompareTipWnd = new CCompareTipWnd())
			{
				//LoadWindowSettings((PCSIDLWND)pCompareTipWnd);
			}
		}
		else
		{
			bDisabledComparetip = true;
			WriteChatf("Unable to create CompareTipWnd. Please do /reloadui");
		}
	}
	else
	{
		bDisabledComparetip = true;

		MessageBox(NULL, "MQUI_CompareTipWnd.xml not Found in UIFiles\\default\n"
			"This feature will be disabled for now.\n"
			"You can retry again by /plugin mq2itemdisplay unload and then /plugin mq2itemdisplay", "MQ2ItemDisplay", MB_OK | MB_SYSTEMMODAL);
	}
}

// Called once, when the plugin is to initialize
PLUGIN_API void InitializePlugin()
{
	pGearScoreType = new MQ2GearScoreType;
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
	AddCommand("/iScore", DoGearScoreUserCommand);
	AddCommand("/GearScore", DoGearScoreUserCommand);
	pDisplayItemType = new MQ2DisplayItemType;
	AddMQ2Data("GearScore", dataGearScore);

	if (!IsXMLFilePresent(TipWndXML))
	{
		HMODULE hMe = nullptr;

		GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
			(LPCTSTR)InitializePlugin, &hMe);

		// need to unpack our resource.
		if (HRSRC hRes = FindResource(hMe, MAKEINTRESOURCE(IDR_XML1), "XML"))
		{
			if (HGLOBAL bin = LoadResource(hMe, hRes))
			{
				BOOL bResult = 0;
				if (void* pMyBinaryData = LockResource(bin))
				{
					std::filesystem::path pathUI = gPathResources;
					pathUI = pathUI / "uifiles" / "default";

					if (!std::filesystem::exists(pathUI))
					{
						std::filesystem::create_directories(pathUI);
					}

					pathUI /= TipWndXML;

					// save it to the default mq uifiles dir
					DWORD ressize = SizeofResource(hMe, hRes);
					FILE* File = nullptr;

					errno_t err = fopen_s(&File, pathUI.string().data(), "wb");
					if (!err && File)
					{
						fwrite(pMyBinaryData, ressize, 1, File);
						fclose(File);
					}
					bResult = UnlockResource(hRes);
				}
				bResult = FreeResource(hRes);
			}
		}
	}

	AddXMLFile(TipWndXML);
	EzDetourwName(CInvSlotWnd__DrawTooltip, &ItemDisplayHook::CInvSlotWnd_DrawTooltipDetour, &ItemDisplayHook::CInvSlotWnd_DrawTooltipTramp,"CInvSlotWnd__DrawTooltip");

	if (gGameState == GAMESTATE_INGAME)
	{
		ReadProfile(GetCharInfo()->Name, FALSE);
		CreateCompareTipWnd();
	}
}

PLUGIN_API void SetGameState(DWORD GameState)
{
	if (GameState == GAMESTATE_INGAME && IniLoaded == 0)
		ReadProfile(GetCharInfo()->Name, FALSE);
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

	delete pGearScoreType;
	pGearScoreType = nullptr;

	RemoveMQ2Data("InsertAug");
	RemoveMQ2Data("RemoveAug");
	RemoveMQ2Data("DisplayItem");
	RemoveMQ2Data("GearScore");
	RemoveCommand("/inote");
	RemoveCommand("/iScore");
	RemoveCommand("/GearScore");
	RemoveCommand("/addlootfilter");
	RemoveCommand("/convertitem");
	RemoveCommand("/itemdisplay");

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

PLUGIN_API DWORD OnIncomingChat(char* Line, DWORD Color)
{
	// TODO: Get rid of all these dynamic 2k buffers
	if (ClickGroup || ClickGuild || ClickRaid || ClickAny)
	{
		char* szStart = new char[MAX_STRING];
		sprintf_s(szStart, MAX_STRING, "%c%c", 0x12, 0x30);
		char* p = strstr(Line, szStart);
		delete szStart;
		if (!p)
		{
			return 0;
		}
		int doLink = 0;

		if (ClickAny) doLink = 1;
		if (!doLink && ClickGroup && (strstr(Line, "tells the group") || strstr(Line, "tell your party"))) doLink = 1;
		if (!doLink && ClickGuild && (strstr(Line, "tells the guild") || strstr(Line, "to your guild"))) doLink = 1;
		if (!doLink && ClickRaid && (strstr(Line, "tells the raid") || strstr(Line, "tell your raid"))) doLink = 1;

		if (doLink && p && strlen(p) > LINK_LEN + 2)
		{
			char* szText = new char[MAX_STRING];
			memset(szText, 0, 100);
			strncpy_s(szText, MAX_STRING, p + 2, LINK_LEN);
			char* szCommand = new char[MAX_STRING];
			sprintf_s(szCommand, MAX_STRING, "/notify ChatWindow CW_ChatOutput link %s", szText);
			delete szText;
			DoCommand(((SPAWNINFO*)pLocalPlayer), szCommand);
			delete szCommand;
		}
	}
	return 0;
}

PLUGIN_API void OnPulse()
{
	if (GetGameState() == GAMESTATE_INGAME)
	{
		CreateCompareTipWnd();
	}
}