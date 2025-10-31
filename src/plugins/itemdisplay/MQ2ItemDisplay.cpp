/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
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

#include "eqlib/WindowOverride.h"
#include "resource.h"

#include <shellapi.h>
#include <fmt/format.h>

#include <mutex>
#include <string_view>
#include <fstream>

using namespace mq::datatypes;

PreSetup("MQ2ItemDisplay");

// Keep data about the recent items that have been displayed.
static int s_lastWindowIndex = -1;

class MQ2DisplayItemType;
MQ2DisplayItemType* pDisplayItemType = nullptr;

const int BUTTON_SPACING = 22;
const int BUTTON_GROUP_HEIGHT = 34;

static bool s_refreshItemDisplay = false;
static bool s_refreshSpellDisplay = false;

struct ItemEffectConfig {
	ItemSpellTypes effectType;
	MQColor color;
	std::string_view label;
};

ItemEffectConfig s_itemEffectConfigs[ItemSpellType_Max] = {
	{ ItemSpellType_Clicky,   MQColor(0,   255, 0),   "Clicky"   },
	{ ItemSpellType_Proc,     MQColor(255, 0,   255), "Proc"     },
	{ ItemSpellType_Worn,     MQColor(255, 255, 0),   "Worn"     },
	{ ItemSpellType_Focus,    MQColor(160, 160, 0),   "Focus"    },
	{ ItemSpellType_Scroll,   MQColor(160, 160, 160), "Scroll"   },
	{ ItemSpellType_Focus2,   MQColor(160, 160, 0),   "Focus2"   },
#if HAS_ITEM_BLESSING_EFFECT
	{ ItemSpellType_Blessing, MQColor(88,  214, 141), "Blessing" }
#endif
};

static std::pair<MQColor, std::string_view> GetEffectInfo(ItemSpellTypes effectType, bool useCustom = true);

//----------------------------------------------------------------------------
// this class holds persisted settings for this plugin.
class Settings
{
public:
	static constexpr inline bool default_lootButtonsEnabled = true;
	static constexpr inline bool default_lucyButtonEnabled = true;
	static constexpr inline bool default_showSpellInfoOnItems = true;
	static constexpr inline bool default_showSpellInfoOnSpells = true;
	static constexpr inline MQColor default_spellColor = "#00ffff";
	static constexpr inline MQColor default_itemColor = "#00ffff";

	inline bool IsLootButtonsEnabled() const { return m_lootButtonsEnabled; }
	void SetLootButtonsEnabled(bool enabled);

	inline bool IsLucyButtonEnabled() const { return m_lucyButtonEnabled; }
	void SetLucyButtonEnabled(bool enabled);

	inline bool IsShowSpellInfoOnItemsEnabled() const { return m_showSpellInfoOnItems; }
	void SetShowSpellInfoOnItemsEnabled(bool enabled);

	inline bool IsShowSpellInfoOnSpellsEnabled() const { return m_showSpellInfoOnSpells; }
	void SetShowSpellInfoOnSpellsEnabled(bool enabled);

	std::optional<MQColor> GetItemSpellColor(ItemSpellTypes effectType) const;
	void SetItemSpellColor(ItemSpellTypes effectType, MQColor color);
	void ResetItemSpellColor(ItemSpellTypes effectType);

	inline MQColor GetSpellColor() const { return m_spellColor; }
	void SetSpellColor(MQColor color);
	void ResetSpellColor();

	inline MQColor GetItemColor() const { return m_itemColor; }
	void SetItemColor(MQColor color);
	void ResetItemColor();

	void Load();
	void Reset();

private:
	bool m_lootButtonsEnabled = default_lootButtonsEnabled;
	bool m_lucyButtonEnabled = default_lucyButtonEnabled;
	bool m_showSpellInfoOnItems = default_showSpellInfoOnItems;
	bool m_showSpellInfoOnSpells = default_showSpellInfoOnSpells;
	std::map<ItemSpellTypes, MQColor> m_customColors;

	MQColor m_spellColor = default_spellColor;
	MQColor m_itemColor = default_itemColor;
};
Settings s_settings;

void Settings::Load()
{
	DeletePrivateProfileKey("Settings", "CompareTip", INIFileName); // Unused

	m_lootButtonsEnabled = GetPrivateProfileBool("Settings", "LootButton", default_lootButtonsEnabled, INIFileName);
	m_lucyButtonEnabled = GetPrivateProfileBool("Settings", "LucyButton", default_lucyButtonEnabled, INIFileName);
	m_showSpellInfoOnItems = GetPrivateProfileBool("Settings", "ShowSpellsInfoOnItems", default_showSpellInfoOnItems, INIFileName);
	m_showSpellInfoOnSpells = GetPrivateProfileBool("Settings", "ShowSpellInfoOnSpells", default_showSpellInfoOnSpells, INIFileName);

	for (const auto& conf : s_itemEffectConfigs)
	{
		std::string setting = GetPrivateProfileString("Settings", fmt::format("CustomColor_{}", conf.label), std::string(), INIFileName);
		if (setting.size() == 7 && setting[0] == '#') // #rrggbb
		{
			m_customColors[conf.effectType] = MQColor(setting.c_str());
		}
	}

	std::string itemColor = GetPrivateProfileString("Settings", "CustomColor_Item", std::string(), INIFileName);
	if (itemColor.size() == 7 && itemColor[0] == '#')
	{
		m_itemColor = MQColor(itemColor.c_str());
	}

	std::string spellColor = GetPrivateProfileString("Settings", "CustomColor_Spell", std::string(), INIFileName);
	if (spellColor.size() == 7 && spellColor[0] == '#')
	{
		m_spellColor = MQColor(spellColor.c_str());
	}
}

void Settings::Reset()
{
	m_customColors.clear();
	m_lootButtonsEnabled = default_lootButtonsEnabled;
	m_lucyButtonEnabled = default_lucyButtonEnabled;
	m_showSpellInfoOnItems = default_showSpellInfoOnItems;
	m_showSpellInfoOnSpells = default_showSpellInfoOnSpells;

	DeletePrivateProfileKey("Settings", "LootButton", INIFileName);
	DeletePrivateProfileKey("Settings", "LucyButton", INIFileName);
	DeletePrivateProfileKey("Settings", "ShowSpellsInfoOnItems", INIFileName);
	DeletePrivateProfileKey("Settings", "ShowSpellInfoOnSpells", INIFileName);

	for (const auto& conf : s_itemEffectConfigs)
	{
		DeletePrivateProfileKey("Settings", fmt::format("CustomColor_{}", conf.label), INIFileName);
	}

	ResetItemColor();
	ResetSpellColor();
}

std::optional<MQColor> Settings::GetItemSpellColor(ItemSpellTypes effectType) const
{
	auto iter = m_customColors.find(effectType);
	if (iter == m_customColors.end())
		return {};

	return iter->second;
}

void Settings::SetItemSpellColor(ItemSpellTypes effectType, MQColor color)
{
	m_customColors[effectType] = color;

	auto [_, name] = GetEffectInfo(effectType);

	WritePrivateProfileString("Settings", fmt::format("CustomColor_{}", name),
		fmt::format("#{:6X}", color.ToRGB()), INIFileName);

	s_refreshItemDisplay = true;
}

void Settings::ResetItemSpellColor(ItemSpellTypes effectType)
{
	m_customColors.erase(effectType);
	for (const auto& conf : s_itemEffectConfigs)
	{
		if (conf.effectType == effectType)
		{
			DeletePrivateProfileKey("Settings", fmt::format("CustomColor_{}", conf.label), INIFileName);
			break;
		}
	}

	s_refreshItemDisplay = true;
}

void Settings::SetSpellColor(MQColor color)
{
	m_spellColor = color;

	WritePrivateProfileString("Settings", "CustomColor_Spell",
		fmt::format("#{:06X}", color.ToRGB()), INIFileName);

	s_refreshSpellDisplay = true;
}

void Settings::ResetSpellColor()
{
	m_spellColor = default_spellColor;

	DeletePrivateProfileKey("Settings", "CustomColor_Spell", INIFileName);

	s_refreshSpellDisplay = true;
}

void Settings::SetItemColor(MQColor color)
{
	m_itemColor = color;

	WritePrivateProfileString("Settings", "CustomColor_Item",
		fmt::format("#{:06X}", color.ToRGB()), INIFileName);

	s_refreshItemDisplay = true;
}

void Settings::ResetItemColor()
{
	m_itemColor = default_itemColor;

	DeletePrivateProfileKey("Settings", "CustomColor_Item", INIFileName);

	s_refreshItemDisplay = true;
}

void Settings::SetLootButtonsEnabled(bool enabled)
{
	if (enabled == m_lootButtonsEnabled)
		return;

	m_lootButtonsEnabled = enabled;
	WritePrivateProfileBool("Settings", "LootButton", m_lootButtonsEnabled, INIFileName);

	s_refreshItemDisplay = true;
}

void Settings::SetLucyButtonEnabled(bool enabled)
{
	if (enabled == m_lucyButtonEnabled)
		return;

	m_lucyButtonEnabled = enabled;
	WritePrivateProfileBool("Settings", "LucyButton", m_lucyButtonEnabled, INIFileName);

	s_refreshItemDisplay = true;
}

void Settings::SetShowSpellInfoOnItemsEnabled(bool enabled)
{
	if (enabled == m_showSpellInfoOnItems)
		return;

	m_showSpellInfoOnItems = enabled;
	WritePrivateProfileBool("Settings", "ShowSpellsInfoOnItems", m_showSpellInfoOnItems, INIFileName);

	s_refreshItemDisplay = true;
}

void Settings::SetShowSpellInfoOnSpellsEnabled(bool enabled)
{
	if (enabled == m_showSpellInfoOnSpells)
		return;

	m_showSpellInfoOnSpells = enabled;
	WritePrivateProfileBool("Settings", "ShowSpellInfoOnSpells", m_showSpellInfoOnSpells, INIFileName);

	s_refreshSpellDisplay = true;
}

static std::pair<MQColor, std::string_view> GetEffectInfo(ItemSpellTypes effectType, bool useCustom)
{
	for (ItemEffectConfig& config : s_itemEffectConfigs)
	{
		if (config.effectType == effectType)
		{
			std::optional<MQColor> customColor;
			if (useCustom)
				customColor = s_settings.GetItemSpellColor(effectType);

			return { customColor.value_or(config.color), config.label };
		}
	}

	return { MQColor(255, 0, 0), "Unknown" };
}

//----------------------------------------------------------------------------
// This structure holds all the extra information that we associate with an
// instance of CItemDisplayWnd

struct ItemDisplayExtraInfo
{
	// this item is placeable in yards, guild yard, etc, This item can be used in tradeskills
	std::string itemInfo;
	std::string windowTitle;
	std::string itemAdvancedLoreText;
	std::string itemMadeByText;

	// Item Information: Placing this augment into <*>, this armor can only be used in <*>
	std::string itemInformationText;

	// Our Extra item information
	std::string extraItemInfo;
	std::string extraSpellInfo;

	bool collected = false;
	bool collectedReceived = false;
	bool scribed = false;
	bool scribedReceived = false;

	// Our extra buttons
	std::unique_ptr<CButtonWnd> pLucyButton = nullptr;
	std::unique_ptr<CLabelWnd> pHeader = nullptr;         // Loot buttons header
	std::unique_ptr<CButtonWnd> pAlwaysNeedBtn = nullptr;
	std::unique_ptr<CButtonWnd> pAlwaysGreedBtn = nullptr;
	std::unique_ptr<CButtonWnd> pNeverBtn = nullptr;
	std::unique_ptr<CButtonWnd> pAutoRollBtn = nullptr;


	ItemDisplayExtraInfo() = default;
	~ItemDisplayExtraInfo() { Reset(); }

	ItemDisplayExtraInfo(ItemDisplayExtraInfo&&) = default;
	ItemDisplayExtraInfo(const ItemDisplayExtraInfo&) = delete;

	ItemDisplayExtraInfo& operator=(const ItemDisplayExtraInfo&) = delete;
	ItemDisplayExtraInfo& operator=(ItemDisplayExtraInfo&&) = default;

	void Reset();
	void ResetLootButtons();
	void ResetItem();

	void SetLootButtonsPosition(const CXPoint& labelPos);
};

void ItemDisplayExtraInfo::ResetItem()
{
	itemInfo.clear();
	windowTitle.clear();
	itemAdvancedLoreText.clear();
	itemMadeByText.clear();
	itemInformationText.clear();

	extraItemInfo.clear();
	extraSpellInfo.clear();

	collected = false;
	collectedReceived = false;
	scribed = false;
	scribedReceived = false;
}

void ItemDisplayExtraInfo::Reset()
{
	ResetItem();

	pLucyButton.reset();
	ResetLootButtons();
}

void ItemDisplayExtraInfo::ResetLootButtons()
{
	// or destroy?
	pHeader.reset();
	pAlwaysNeedBtn.reset();
	pAlwaysGreedBtn.reset();
	pNeverBtn.reset();
	pAutoRollBtn.reset();
}

void ItemDisplayExtraInfo::SetLootButtonsPosition(const CXPoint& labelPos)
{
	CXRect headerRect{ labelPos, CXSize(80, 12) };

	if (pHeader)
	{
		pHeader->SetLocation(headerRect);

		// always need
		CXRect buttonRect = headerRect;
		buttonRect.SetTop(buttonRect.bottom + 4);
		buttonRect.SetWidth(14);
		buttonRect.SetHeight(14);
		pAlwaysNeedBtn->SetLocation(buttonRect);

		// always greed
		buttonRect.SetLeft(buttonRect.left + BUTTON_SPACING);
		pAlwaysGreedBtn->SetLocation(buttonRect);

		// never
		buttonRect.SetLeft(buttonRect.left + BUTTON_SPACING);
		pNeverBtn->SetLocation(buttonRect);

		// autoroll
		buttonRect.SetLeft(buttonRect.left + BUTTON_SPACING);
		pAutoRollBtn->SetLocation(buttonRect);
	}

	if (pLucyButton)
	{
		const CXSize lucyButtonSize(36, 20);

		CXRect buttonRect = headerRect;
		buttonRect.SetTop(buttonRect.top + 10);

		if (!pHeader)
		{
			buttonRect.SetSize(lucyButtonSize);

			pLucyButton->SetLocation(buttonRect);
		}
		else
		{
			// offset to the right
			buttonRect.SetLeft(buttonRect.left + buttonRect.GetWidth() + 6);
			buttonRect.SetSize(lucyButtonSize);

			pLucyButton->SetLocation(buttonRect);
		}
	}
}

static std::map<CItemDisplayWnd*, ItemDisplayExtraInfo> s_itemDisplayExtraInfo;

//----------------------------------------------------------------------------

static CItemDisplayWnd* GetItemWndPtr(const MQVarPtr& VarPtr)
{
	if (!pItemDisplayManager)
		return nullptr;

	const int index = (int)VarPtr.DWord;
	return pItemDisplayManager->GetWindow(index);
}

static CItemDisplayWnd* GetNextItemWnd(CItemDisplayWnd* pCurWindow)
{
	if (!pItemDisplayManager || !pCurWindow)
		return nullptr;

	// Do a full rotation around the container looking for
	// the next non-null item window.
	int count = pItemDisplayManager->GetCount();
	int index = pCurWindow->ItemWndIndex;

	for (int offset = 0; offset < count; ++offset)
	{
		index = (index + 1) % count;

		if (CItemDisplayWnd* pWnd = pItemDisplayManager->GetWindow(index))
			return pWnd;
	}

	return nullptr;
}

static CItemDisplayWnd* FindItemWndByString(std::string_view search)
{
	if (!pItemDisplayManager)
		return nullptr;

	if (search.empty())
		return nullptr;

	int searchId = -1;
	if (ci_starts_with(search, "id "))
	{
		search = search.substr(3);
		searchId = GetIntFromString(search, -1);

		if (searchId <= 0)
			return nullptr;
	}

	for (int i = 0; i < pItemDisplayManager->GetCount(); ++i)
	{
		// Closed windows will clear the item ptr.
		CItemDisplayWnd* pWnd = pItemDisplayManager->GetWindow(i);
		if (pWnd && pWnd->pItem)
		{
			if (searchId != -1)
			{
				if (pWnd->pItem->GetID() == searchId)
					return pWnd;
			}
			else if (ci_equals(search, pWnd->pItem->GetName()))
			{
				return pWnd;
			}
		}
	}

	return nullptr;
}

//----------------------------------------------------------------------------

class MQ2DisplayItemType : public MQ2Type
{
public:
	enum class DisplayItemMembers
	{
		Info = 1,
		WindowTitle,
		AdvancedLore,
		MadeBy,
		CollectedReceived,
		Collected,
		ScribedReceived,
		Scribed,
		Information,
		DisplayIndex,
		Window,
		Item,
		Next,

		// Typos... really??
		CollectedRecieved,
		ScribedRecieved,
	};

	MQ2DisplayItemType() : MQ2Type("DisplayItem")
	{
		ScopedTypeMember(DisplayItemMembers, Info);
		ScopedTypeMember(DisplayItemMembers, WindowTitle);
		ScopedTypeMember(DisplayItemMembers, AdvancedLore);
		ScopedTypeMember(DisplayItemMembers, MadeBy);
		ScopedTypeMember(DisplayItemMembers, CollectedReceived);
		ScopedTypeMember(DisplayItemMembers, Collected);
		ScopedTypeMember(DisplayItemMembers, ScribedReceived);
		ScopedTypeMember(DisplayItemMembers, Scribed);
		ScopedTypeMember(DisplayItemMembers, Information);
		ScopedTypeMember(DisplayItemMembers, DisplayIndex);
		ScopedTypeMember(DisplayItemMembers, Window);
		ScopedTypeMember(DisplayItemMembers, Item);
		ScopedTypeMember(DisplayItemMembers, Next);

		ScopedTypeMember(DisplayItemMembers, CollectedRecieved);
		ScopedTypeMember(DisplayItemMembers, ScribedRecieved);
	}

public:
	bool GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest) override
	{
		CItemDisplayWnd* pWindow = GetItemWndPtr(VarPtr);
		if (!pWindow)
			return false;

		ItemPtr pItem = pWindow->pItem;
		if (!pItem)
			return false;

		uint32_t windowIndex = pWindow->ItemWndIndex;
		const ItemDisplayExtraInfo& extraInfo = s_itemDisplayExtraInfo[pWindow];

		// Fall back to members of Item if we couldn't find anything.
		MQTypeMember* pMember = MQ2DisplayItemType::FindMember(Member);
		if (!pMember)
		{
			MQVarPtr varPtr = pItemType->MakeVarPtr(pItem);
			return pItemType->GetMember(varPtr, Member, Index, Dest);
		}

		switch (static_cast<DisplayItemMembers>(pMember->ID))
		{
		case DisplayItemMembers::Info:
			strcpy_s(DataTypeTemp, extraInfo.itemInfo.c_str());
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		case DisplayItemMembers::WindowTitle:
			strcpy_s(DataTypeTemp, extraInfo.windowTitle.c_str());
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		case DisplayItemMembers::AdvancedLore:
			strcpy_s(DataTypeTemp, extraInfo.itemAdvancedLoreText.c_str());
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		case DisplayItemMembers::MadeBy:
			strcpy_s(DataTypeTemp, extraInfo.itemMadeByText.c_str());
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		case DisplayItemMembers::Collected:
			Dest.Set(extraInfo.collected);
			Dest.Type = pBoolType;
			return true;
		case DisplayItemMembers::CollectedRecieved:
		case DisplayItemMembers::CollectedReceived:
			Dest.Set(extraInfo.collectedReceived);
			Dest.Type = pBoolType;
			return true;
		case DisplayItemMembers::Scribed:
			Dest.Set(extraInfo.scribed);
			Dest.Type = pBoolType;
			return true;
		case DisplayItemMembers::ScribedRecieved:
		case DisplayItemMembers::ScribedReceived:
			Dest.Set(extraInfo.scribedReceived);
			Dest.Type = pBoolType;
			return true;
		case DisplayItemMembers::Information:
			strcpy_s(DataTypeTemp, extraInfo.itemInformationText.c_str());
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		case DisplayItemMembers::DisplayIndex:
			Dest.DWord = pWindow->ItemWndIndex + 1;
			Dest.Type = pIntType;
			return true;
		case DisplayItemMembers::Window:
			Dest.Ptr = pWindow;
			Dest.Type = pWindowType;
			return true;
		case DisplayItemMembers::Item:
			Dest = pItemType->MakeTypeVar(pWindow->pItem);
			return true;
		case DisplayItemMembers::Next: {
			Dest.Type = pDisplayItemType;
			CItemDisplayWnd* pNextWnd = GetNextItemWnd(pWindow);
			Dest.DWord = pNextWnd ? pNextWnd->ItemWndIndex : -1;
			return true;
		}
		default: break;
		}

		return false;
	}

	bool ToString(MQVarPtr VarPtr, char* Destination) override
	{
		CItemDisplayWnd* pWindow = GetItemWndPtr(VarPtr);
		if (!pWindow)
			return false;

		if (ItemPtr pItem = pWindow->pItem)
		{
			strcpy_s(Destination, MAX_STRING, pItem->GetName());
			return true;
		}

		const ItemDisplayExtraInfo& extraInfo = s_itemDisplayExtraInfo[pWindow];
		strcpy_s(Destination, MAX_STRING, extraInfo.windowTitle.c_str());
		return true;
	}

	bool Downcast(const MQVarPtr& fromVar, MQVarPtr& toVar, MQ2Type* toType) override
	{
		CItemDisplayWnd* pWindow = GetItemWndPtr(fromVar);

		if (toType == pItemType)
		{
			toVar = pItemType->MakeVarPtr(pWindow ? pWindow->pItem : nullptr);
			return true;
		}

		if (toType == pWindowType)
		{
			toVar.Ptr = pWindow;
			return true;
		}

		return false;
	}

	static bool dataDisplayItem(const char* szIndex, MQTypeVar& Ret)
	{
		if (!pItemDisplayManager)
			return false;

		if (szIndex[0])
		{
			int index = GetIntFromString(szIndex, 0) - 1;
			if (index >= 0 && index < pItemDisplayManager->GetCount())
			{
				if (CItemDisplayWnd* pWnd = pItemDisplayManager->GetWindow(index))
				{
					if (pWnd->IsVisible() && pWnd->pItem)
					{
						Ret.DWord = index;
						Ret.Type = pDisplayItemType;
						return true;
					}
				}

				return false;
			}
			
			// Search by string.
			CItemDisplayWnd* pWnd = FindItemWndByString(szIndex);
			Ret.DWord = pWnd ? pWnd->ItemWndIndex : -1;
			Ret.Type = pDisplayItemType;
			return true;
		}

		// Use the last known window index. Which could also be invalid.
		if (s_lastWindowIndex >= 0)
		{
			Ret.DWord = s_lastWindowIndex;
			Ret.Type = pDisplayItemType;
			return true;
		}

		return false;
	}
};

static int GetDmgBonus(const CXStr& Str)
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

static void CreateSpellTextDetails(fmt::memory_buffer& out, EQ_Spell* pSpell);

static CXStr CreateItemSpellTag(ItemSpellData::SpellData* Effect, EQ_Spell* pSpell)
{
	fmt::memory_buffer buf;
	fmt::format_to(fmt::appender(buf), "{:d}^{:d}^{:d}", 3, pSpell->ID, static_cast<int>(Effect->EffectType));

	return CStmlWnd::MakeWndNotificationTag(XWM_SPELL_LINK, Effect->OverrideName[0] ? Effect->OverrideName : pSpell->Name,
		CXStr{ buf.data(), buf.size() });
}

static std::string CreateItemSpellText(eItemSpellType spellType, ItemSpellData::SpellData* Effect)
{
	EQ_Spell* pSpell = GetSpellByID(Effect->SpellID);
	if (pSpell == nullptr)
		return {};

	auto [color, name] = GetEffectInfo(spellType);

	auto buf = fmt::memory_buffer();
	fmt::format_to(fmt::appender(buf), "<BR><c \"#{:06X}\">Spell Info for {} effect: ", color.ToRGB(), name);

	CXStr spellLink = CreateItemSpellTag(Effect, pSpell);
	fmt::format_to(fmt::appender(buf), "{}<BR>", std::string_view{ spellLink });

	CreateSpellTextDetails(buf, pSpell);

	fmt::format_to(std::back_inserter(buf), "</c>");

	return to_string(buf);
}

static std::string CreateSpellText(EQ_Spell* pSpell)
{
	if (!pSpell)
		return {};

	auto buf = fmt::memory_buffer();
	fmt::format_to(fmt::appender(buf), "<BR><c \"#{:06X}\">", s_settings.GetSpellColor().ToRGB());

	CreateSpellTextDetails(buf, pSpell);

	if (int cat = GetSpellCategory(pSpell))
	{
		if (const char* str = pDBStr->GetString(cat, eSpellCategory))
		{
			fmt::format_to(std::back_inserter(buf), "Category: {}<br>", str);
		}
	}

	if (int cat = GetSpellSubcategory(pSpell))
	{
		if (const char* str = pDBStr->GetString(cat, eSpellCategory))
		{
			fmt::format_to(std::back_inserter(buf), "Subcategory: {}<br>", str);
		}
	}

	fmt::format_to(std::back_inserter(buf), "Spell Icon: {}<br>", pSpell->SpellIcon);
	fmt::format_to(std::back_inserter(buf), "</c>");

	return to_string(buf);
}

struct repeated_text
{
	int n;
	std::string_view sv;
};
repeated_text rep(int n, std::string_view sv) { return { n, sv }; }

template <>
struct fmt::formatter<repeated_text> : fmt::formatter<std::string_view>
{
	auto format(const repeated_text& r, format_context& ctx) const
		-> format_context::iterator
	{
		auto it = ctx.out();
		for (int i = 0; i < r.n; ++i)
			it = fmt::formatter<std::string_view>::format(r.sv, ctx);
		return it;
	}
};

struct class_name_level
{
	int class_id;
	int level;
};

template <>
struct fmt::formatter<class_name_level> : fmt::formatter<string_view>
{
	auto format(const class_name_level& r, format_context& ctx) const
		-> format_context::iterator
	{
		return fmt::format_to(ctx.out(), "{}({})", GetClassDesc(r.class_id), r.level);
	}
};

static void CreateSpellTextDetails(fmt::memory_buffer& out, EQ_Spell* pSpell)
{
	auto buffer = std::back_inserter(out);

	//----------------------------------------------------------------------------
	// Basic Info

	fmt::format_to(buffer, "ID: {:04d}{}", pSpell->ID, rep(28, "&nbsp;"));

	int Ticks = GetSpellDuration(pSpell, pLocalPlayer ? pLocalPlayer->Level : 0, true);
	if (Ticks == -1)
		fmt::format_to(buffer, "Duration: Permanent<br>");
	else if (Ticks == -2)
		fmt::format_to(buffer, "Duration: Unknown<br>");
	else if (Ticks == 0)
		fmt::format_to(buffer, "<br>");
	else
		fmt::format_to(buffer, "Duration: {:1.1f} minutes<br>", (float)((Ticks * 6.0f) / 60.0f));

	fmt::format_to(buffer, "RecoveryTime: {0:1.2f}{2}RecastTime: {1:1.2f}<br>",
		(float)(pSpell->RecoveryTime / 1000.0f), (float)(pSpell->RecastTime / 1000.0f), rep(7, "&nbsp;"));

	if (pSpell->Range > 0.0f)
	{
		fmt::format_to(buffer, "Range: {:1.0f}", pSpell->Range);

		if (pSpell->PushBack == 0.0f && pSpell->AERange == 0.0f)
			fmt::format_to(buffer, "<br>");
	}

	if (pSpell->PushBack != 0.0f)
	{
		if (pSpell->Range > 0.0f)
			fmt::format_to(buffer, "{}", rep(22, "&nbsp;"));
		fmt::format_to(buffer, "PushBack: {:1.1f}", pSpell->PushBack);

		if (pSpell->AERange == 0.0f || pSpell->Range > 0.0f)
			fmt::format_to(buffer, "<br>");
	}

	if (pSpell->AERange > 0.0f)
	{
		if (pSpell->Range > 0.0f)
			fmt::format_to(buffer, "{}", rep(22, "&nbsp;"));
		else if (pSpell->PushBack > 0.0f)
			fmt::format_to(buffer, "{}", rep(17, "&nbsp;"));

		fmt::format_to(buffer, "AERange: {:1.0f}<br>", pSpell->AERange);
	}

	if (pSpell->TargetType != TargetType_Self
		&& pSpell->TargetType != TargetType_Pet
		&& pSpell->TargetType != TargetType_Group_v1
		&& pSpell->TargetType != TargetType_AEPC_v2
		&& pSpell->TargetType != TargetType_Group_v2)
	{
		if (pSpell->SpellType == SpellType_Detrimental)
		{
			switch (pSpell->Resist)
			{
			case ResistType_Corruption: fmt::format_to(buffer, "Resist: Corruption"); break;
			case ResistType_Prismatic:  fmt::format_to(buffer, "Resist: Prismatic[Avg]"); break;
			case ResistType_Chromatic:  fmt::format_to(buffer, "Resist: Chromatic[Low]"); break;
			case ResistType_Disease:    fmt::format_to(buffer, "Resist: Disease"); break;
			case ResistType_Poison:     fmt::format_to(buffer, "Resist: Poison"); break;
			case ResistType_Cold:       fmt::format_to(buffer, "Resist: Cold"); break;
			case ResistType_Fire:       fmt::format_to(buffer, "Resist: Fire"); break;
			case ResistType_Magic:      fmt::format_to(buffer, "Resist: Magic"); break;
			case ResistType_None:       fmt::format_to(buffer, "Resist: Unresistable"); break;
			}

			if (pSpell->ResistAdj != 0)
				fmt::format_to(buffer, "{1}(Resist Adj.: {0}", pSpell->ResistAdj, rep(3, "&nbsp;"));

			fmt::format_to(buffer, "<br>");
		}
	}

	if (pSpell->HateGenerated)
		fmt::format_to(buffer, "Hate Generated: {}<br>", pSpell->HateGenerated);

	fmt::format_to(buffer, "<br>");

	//----------------------------------------------------------------------------
	// Spell Slots

	char szSpellSlotInfo[MAX_STRING] = { 0 };
	ShowSpellSlotInfo(pSpell, szSpellSlotInfo, MAX_STRING);

	fmt::format_to(buffer, "{}<br>", szSpellSlotInfo);

	//----------------------------------------------------------------------------
	// Usable classes

	class_name_level class_levels[TotalPlayerClasses];
	int numClassLevels = 0;

	for (int j = Warrior; j <= Berserker; j++)
	{
		int levelNeeded = pSpell->GetSpellLevelNeeded(j);

		if (levelNeeded > 0 && levelNeeded <= MAX_PC_LEVEL)
			class_levels[numClassLevels++] = class_name_level{ j, levelNeeded };
	}
	if (numClassLevels)
		fmt::format_to(buffer, "{}<br><br>", fmt::join(class_levels, class_levels + numClassLevels, ", "));

	//----------------------------------------------------------------------------
	// Messages

	if (const char* str = GetSpellString(pSpell->ID, 2))
	{
		fmt::format_to(buffer, "Cast on you: {}<br>", str);
	}

	if (const char* str = GetSpellString(pSpell->ID, 3))
	{
		fmt::format_to(buffer, "Cast on another: {}<br>", str);
	}

	if (const char* str = GetSpellString(pSpell->ID, 4))
	{
		fmt::format_to(buffer, "Wears off: {}<br>", str);
	}
}

// TODO: Find a way to remove origMsg by calculating the bonus dmg.
static void CreateItemText(fmt::memory_buffer& buffer_, const ItemPtr& item, const CXStr& origMsg)
{
	auto buffer = std::back_inserter(buffer_);

	if (item->GetID() > 0)
	{
		fmt::format_to(buffer, "Item ID: {}<br>", item->GetID());
	}

	if (item->GetIconID() > 0)
	{
		fmt::format_to(buffer, "Icon ID: {}<br>", item->GetIconID());
	}

	if (item->IsStackable())
	{
		fmt::format_to(buffer, "Stackable Count: {}<br>", item->GetMaxItemCount());
	}

	if (item->GetMoneyValue() > 0)
	{
		int cp = item->GetMoneyValue();
		int sp = cp / 10; cp = cp % 10;
		int gp = sp / 10; sp = sp % 10;
		int pp = gp / 10; gp = gp % 10;

		fmt::format_to(buffer, "Value:");
		if (pp > 0)
		{
			fmt::format_to(buffer, " {}pp", pp);
		}

		if (gp > 0)
		{
			fmt::format_to(buffer, " {}gp", gp);
		}

		if (sp > 0)
		{
			fmt::format_to(buffer, " {}sp", sp);
		}

		if (cp > 0)
		{
			fmt::format_to(buffer, " {}cp", cp);
		}

		fmt::format_to(buffer, "<br>");
	}

	if (item->GetTributeValue() > 0)
	{
		fmt::format_to(buffer, "Tribute Value: {}<br>", item->GetTributeValue());
	}

	if (item->GetGuildTributeValue() > 0)
	{
		fmt::format_to(buffer, "Guild Tribute Value: {}<br>", item->GetGuildTributeValue());
	}

	if (item->GetSpellRecastTime(ItemSpellType_Clicky))
	{
		int Secs = GetItemTimer(item.get());

		if (!Secs)
		{
			fmt::format_to(buffer, "Item Timer: <c \"#20FF20\">Ready</c><br>");
		}
		else
		{
			int Mins = (Secs / 60) % 60;
			int Hrs = (Secs / 3600);
			Secs = Secs % 60;

			if (Hrs)
				fmt::format_to(buffer, "Item Timer: {}:{:02d}:{:02d}<br>", Hrs, Mins, Secs);
			else
				fmt::format_to(buffer, "Item Timer: {}:{:02d}<br>", Mins, Secs);
		}
	}

	// Arrows..they have dmg/dly but we don't want them
	if (item->GetItemClass() != ItemClass_Arrow
		&& item->GetDelay() > 0
		&& item->GetDamage() > 0)
	{
		float delay = static_cast<float>(item->GetDelay());
		float damage = static_cast<float>(item->GetDamage());

		fmt::format_to(buffer, "Ratio: {:5.3f}<br>", delay / damage);

		// Calculate Efficiency
		int dmgbonus = 0;

		// Read this from the already generated text, we don't have CalculateDisplayedMinItemDamage yet.
		if (PcProfile* pProfile = GetPcProfile())
		{
			if (pProfile->Level > 27 && !origMsg.empty())
			{
				// bonus is 0 for anything below 28
				dmgbonus = GetDmgBonus(origMsg);
			}
		}

		float efficiency = (((damage * 2) + dmgbonus) / delay) * 50;
		fmt::format_to(buffer, "Efficiency: {:3.0f}<br>", efficiency);

		if (item->CanWear(InvSlot_Secondary))
		{
			// Equipable In Secondary Slot
			float offhandEfficiency = (((damage * 2) / delay) * 50) * .62f;
			fmt::format_to(buffer, "Offhand Efficiency: {:3.0f}<br>", offhandEfficiency);
		}

		fmt::format_to(buffer, "<br>");
	}

	char* lore = item->GetItemDefinition()->LoreName;
	if (lore[0])
	{
		if (lore[0] == '*') lore++;

		if (strcmp(lore, item->GetName()) != 0)
		{
			fmt::format_to(buffer, "Item Lore: {}<br>", lore);
		}
	}

	// TODO: Refactor this into the CreateItemSpellText function instead.

	// Will be 0 for no effect or -1 if other effects present
	auto procEffect = item->GetSpellData(ItemSpellType_Proc);
	if (procEffect->SpellID > 0)
	{
		if (procEffect->RequiredLevel == 0)
		{
			fmt::format_to(buffer, "Procs at level 1", procEffect->ProcRate);
		}
		else
		{
			if (procEffect->RequiredLevel > pLocalPC->GetLevel())
			{
				fmt::format_to(buffer, "<c \"#FF4040\">Procs at level {}</c>", procEffect->RequiredLevel);
			}
			else
			{
				fmt::format_to(buffer, "Procs at level {}", procEffect->RequiredLevel);
			}
		}

		if (procEffect->ProcRate != 0)
		{
			fmt::format_to(buffer, " (Proc rate modifier: {})", procEffect->ProcRate);
		}
		else
		{
			fmt::format_to(buffer, "<BR>");
		}
	}

	auto clickEffect = item->GetSpellData(ItemSpellType_Clicky);
	switch (clickEffect->EffectType)
	{
	case ItemEffectClicky:
	case ItemEffectClickyWorn:
	case ItemEffectClickyRestricted:
	case ItemEffectConsumable:
		if (clickEffect->RequiredLevel == 0)
		{
			fmt::format_to(buffer, "Clickable at level 1<br>", procEffect->ProcRate);
		}
		else
		{
			if (clickEffect->RequiredLevel > pLocalPC->GetLevel())
			{
				fmt::format_to(buffer, "<c \"#FF4040\">Clickable at level {}</c><br>", clickEffect->RequiredLevel);
			}
			else
			{
				fmt::format_to(buffer, "Clickable at level {}<br>", clickEffect->RequiredLevel);
			}
		}
		break;
	default: break;
	}

	// Old "Points" system
	if (int pointCost = item->GetPointCost())
	{
		switch (item->GetPointType())
		{
		case 1: // LDoN Adventures
			fmt::format_to(buffer, "LDoN Cost: {} from {}<BR>", pointCost, GetLDoNTheme(item->GetPointTheme()));
			break;
		case 2: // Discord/PvP
			fmt::format_to(buffer, "Discord Cost: {} points<BR>", pointCost);
			break;
		case 4: // Radiant Crystals
			fmt::format_to(buffer, "DoN Cost: {} Radiant Crystals<BR>", pointCost);
			break;
		case 5: // Ebon Crystals
			fmt::format_to(buffer, "DoN Cost: {} Ebon Crystals<BR>", pointCost);
			break;
		}
	}

	if (item->IsContainer())
	{
		uint8_t containerType = item->GetItemDefinition()->ContainerType;

		if (item->GetItemDefinition()->ContainerType > MAX_COMBINES)
		{
			fmt::format_to(buffer, "Container Type: Unknown ({})<BR>", containerType);
		}
		else
		{
			if (const char* containerTypeName = szCombineTypes[containerType])
			{
				fmt::format_to(buffer, "Container Type: {}<BR>", containerTypeName);
			}
			else
			{
				fmt::format_to(buffer, "Container Type: Unknown ({})<BR>", containerType);
			}
		}
	}

	std::string notes = GetPrivateProfileString("Notes", fmt::format("{:07d}", item->GetID()), {}, INIFileName);
	if (!notes.empty())
	{
		fmt::format_to(buffer, "Note: {}<br>", notes);
	}
}

//============================================================================

void HandleLucyButton(const ItemPtr& pItem)
{
	if (pItem)
	{
		std::string url = fmt::format("https://lucy.allakhazam.com/item.html?id={}", pItem->GetID());
		ShellExecute(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
	}
}

class CItemDisplayWndOverride : public WindowOverride<CItemDisplayWndOverride, CItemDisplayWnd>
{
	static inline bool s_inSetItem = false;

public:
	static void OnHooked(CItemDisplayWndOverride* pWnd) { pWnd->OnHooked(); }
	static void OnAboutToUnhook(CItemDisplayWndOverride* pWnd) { pWnd->OnAboutToUnhook(); }

	static inline bool s_needUpdateLastWindowIndex = false;

	//----------------------------------------------------------------------------
	// overrides

	virtual int WndNotification(CXWnd* sender, uint32_t message, void* data) override
	{
		// If no item then bail immediately.
		if (!pItem) return Super::WndNotification(sender, message, data);

		if (message == XWM_LCLICK)
		{
			ItemDisplayExtraInfo& extraInfo = s_itemDisplayExtraInfo[this];

			if (extraInfo.pLucyButton.get() == sender)
			{
				HandleLucyButton(pItem);
				return 0;
			}

#if HAS_ADVANCED_LOOT
			bool updateFilters = false;
			if (extraInfo.pAlwaysNeedBtn.get() == sender
				|| extraInfo.pAlwaysGreedBtn.get() == sender
				|| extraInfo.pNeverBtn.get() == sender)
			{
				CButtonWnd* pSender = (CButtonWnd*)sender;
				if (pSender->Checked)
				{
					extraInfo.pAlwaysNeedBtn->Checked = extraInfo.pAlwaysNeedBtn.get() == sender;
					extraInfo.pAlwaysGreedBtn->Checked = extraInfo.pAlwaysGreedBtn.get() == sender;
					extraInfo.pNeverBtn->Checked = extraInfo.pNeverBtn.get() == sender;
				}
				updateFilters = true;
			}
			else if (extraInfo.pAutoRollBtn.get() == sender)
			{
				updateFilters = true;
			}

			if (updateFilters)
			{
				int filterTypes = 0;
				if (extraInfo.pAutoRollBtn->Checked)
					filterTypes |= LootFilterBit(LootFilterType_AutoRoll);
				if (extraInfo.pAlwaysNeedBtn->Checked)
					filterTypes |= LootFilterBit(LootFilterType_AlwaysNeed);
				if (extraInfo.pAlwaysGreedBtn->Checked)
					filterTypes |= LootFilterBit(LootFilterType_AlwaysGreed);
				if (extraInfo.pNeverBtn->Checked)
					filterTypes |= LootFilterBit(LootFilterType_NeverLoot);

				pLootFiltersManager->SetItemLootFilter(pItem->GetID(), pItem->GetIconID(), pItem->GetName(), filterTypes);
			}
#endif
		}

		return Super::WndNotification(sender, message, data);
	}

	// ItemDisplay sequence:
	//
	// CItemDisplayManager::ShowItem
	//     CItemDisplayWnd::SetItem
	//         --> Requests additional information
	//         CItemDisplayWnd::UpdateStrings
	//     CItemDisplayWnd::Activate
	//         CXWnd::Show
	//             CItemDisplayWnd::AboutToShow
	//                 CItemDisplayWnd::UpdateStrings
	// Various events:
	//     CItemDisplayWnd::UpdateStrings
	//
	// Basically, everything wants to call UpdateStrings,
	// so try to do less work in UpdateStrings and do most of what we can in SetItem

	void UpdateButtons()
	{
		ItemDisplayExtraInfo& extraInfo = s_itemDisplayExtraInfo[this];

		if (!extraInfo.pLucyButton && s_settings.IsLucyButtonEnabled())
		{
			// create lucy button
			if (CControlTemplate* btnTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("IDW_ModButton"))
			{
				uint32_t oldfont = std::exchange(btnTemplate->nFont, 1);

				CXWnd* pAnchor = this;
				if (CXWnd* pDescriptionTab = GetChildItem("ItemDescriptionTab"))
					pAnchor = pDescriptionTab;

				CButtonWnd* pBtn = (CButtonWnd*)pSidlMgr->CreateXWndFromTemplate(pAnchor, btnTemplate);
				pBtn->SetCRNormal(MQColor(255, 255, 0));
				pBtn->SetWindowText("Lucy");
				pBtn->SetDecalTint(MQColor(0, 255, 255));
				extraInfo.pLucyButton.reset(pBtn);

				btnTemplate->nFont = oldfont;
			}
		}
		else if (extraInfo.pLucyButton && !s_settings.IsLucyButtonEnabled())
		{
			extraInfo.pLucyButton.reset();
		}

#if HAS_ADVANCED_LOOT
		// create loot filter buttons
		if (!extraInfo.pHeader && s_settings.IsLootButtonsEnabled())
		{
			CControlTemplate* btntemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("ADLW_CheckBoxTemplate");
			CControlTemplate* labeltemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("IDW_ModButtonLabel");

			if (btntemplate && labeltemplate)
			{
				CXWnd* pAnchor = this;
				if (CXWnd* pDescriptionTab = GetChildItem("ItemDescriptionTab"))
					pAnchor = pDescriptionTab;

				// header
				uint32_t oldfont = std::exchange(labeltemplate->nFont, 1);

				std::unique_ptr<CLabelWnd> pHeader{ (CLabelWnd*)pSidlMgr->CreateXWndFromTemplate(pAnchor, labeltemplate) };
				pHeader->SetCRNormal(MQColor(0, 148, 255));
				pHeader->SetWindowText("AN | AG | NV | AR");

				labeltemplate->nFont = oldfont;

				std::unique_ptr<CButtonWnd> pAlwaysNeedBtn{ (CButtonWnd*)pSidlMgr->CreateXWndFromTemplate(pAnchor, btntemplate) };
				pAlwaysNeedBtn->SetTooltip("Always roll need on this item");

				std::unique_ptr<CButtonWnd> pAlwaysGreedBtn{ (CButtonWnd*)pSidlMgr->CreateXWndFromTemplate(pAnchor, btntemplate) };
				pAlwaysGreedBtn->SetTooltip("Always roll greed on this item");

				std::unique_ptr<CButtonWnd> pNeverBtn{ (CButtonWnd*)pSidlMgr->CreateXWndFromTemplate(pAnchor, btntemplate) };
				pNeverBtn->SetTooltip("Never loot this item");

				std::unique_ptr<CButtonWnd> pAutoRollBtn{ (CButtonWnd*)pSidlMgr->CreateXWndFromTemplate(pAnchor, btntemplate) };
				pAutoRollBtn->SetTooltip("Always roll on this item");

				extraInfo.pHeader = std::move(pHeader);
				extraInfo.pAlwaysNeedBtn = std::move(pAlwaysNeedBtn);
				extraInfo.pAlwaysGreedBtn = std::move(pAlwaysGreedBtn);
				extraInfo.pNeverBtn = std::move(pNeverBtn);
				extraInfo.pAutoRollBtn = std::move(pAutoRollBtn);
			}
		}
		else if (extraInfo.pHeader && !s_settings.IsLootButtonsEnabled())
		{
			extraInfo.pHeader.reset();
			extraInfo.pAlwaysNeedBtn.reset();
			extraInfo.pAlwaysGreedBtn.reset();
			extraInfo.pNeverBtn.reset();
			extraInfo.pAutoRollBtn.reset();
		}
#endif // HAS_ADVANCED_LOOT

		if (extraInfo.pHeader || extraInfo.pLucyButton)
		{
			//------------------------------------------------------------------------
			// Update position of labels

			// Define the position of everything in terms of the upper left corner of
			// the header label.

			// Try to show it in the 2nd column, if it isn't taken.
			CXWnd* tempWnd = GetChildItem("IDW_Row1Col2Value");
			if (tempWnd && !tempWnd->IsVisible())
			{
				extraInfo.SetLootButtonsPosition(tempWnd->GetLocation().TopLeft());
			}
			else
			{
				// Try third column.
				tempWnd = GetChildItem("IDW_Row1Col3Value");
				if (tempWnd)
				{
					if (!tempWnd->IsVisible())
					{
						// position in third column if its not being used.
						extraInfo.SetLootButtonsPosition(tempWnd->GetLocation().TopLeft());
					}
					else
					{
						// position above third column if it is.
						CXPoint pos = tempWnd->GetLocation().TopLeft();
						pos.y -= BUTTON_GROUP_HEIGHT;
						extraInfo.SetLootButtonsPosition(pos);
					}
				}
			}
		}

#if HAS_ADVANCED_LOOT
		if (extraInfo.pHeader)
		{
			//----------------------------------------------------------------------------
			// update button states

			const ItemFilterData* filterData = pLootFiltersManager->GetItemFilterData(pItem->GetID());
			if (filterData)
			{
				extraInfo.pAutoRollBtn->Checked = (filterData->Types & LootFilterBit(LootFilterType_AutoRoll)) != 0;
				extraInfo.pAlwaysNeedBtn->Checked = (filterData->Types & LootFilterBit(LootFilterType_AlwaysNeed)) != 0;
				extraInfo.pAlwaysGreedBtn->Checked = (filterData->Types & LootFilterBit(LootFilterType_AlwaysGreed)) != 0;
				extraInfo.pNeverBtn->Checked = (filterData->Types & LootFilterBit(LootFilterType_NeverLoot)) != 0;
			}
			else
			{
				extraInfo.pAutoRollBtn->Checked = false;
				extraInfo.pAlwaysNeedBtn->Checked = false;
				extraInfo.pAlwaysGreedBtn->Checked = false;
				extraInfo.pNeverBtn->Checked = false;
			}
		}
#endif
	}

	bool AboutToHide() override
	{
		auto iter = s_itemDisplayExtraInfo.find(this);
		if (iter != s_itemDisplayExtraInfo.end())
		{
			ItemDisplayExtraInfo& extraInfo = iter->second;

			extraInfo.Reset();
		}

		s_needUpdateLastWindowIndex = true;

		return Super::AboutToHide();
	}

	bool AboutToShow() override
	{
		Update();

		return Super::AboutToShow();
	}

	// Updates the s_lastWindowIndex after a change in visibility. Needs to be done
	// from OnPulse because the times get updated *after* our detours return.
	static void UpdateLastWindowIndex()
	{
		int lastWindowIndex = -1;
		int latestTime = 0;

		if (pItemDisplayManager)
		{
			for (int i = 0; i < pItemDisplayManager->GetCount(); ++i)
			{
				CItemDisplayWnd* pWnd = pItemDisplayManager->GetWindow(i);
				int updateTime = pItemDisplayManager->GetLastUpdateTime(i);

				if (pWnd && pWnd->IsVisible() && pWnd->pItem && updateTime > latestTime)
				{
					lastWindowIndex = i;
					latestTime = updateTime;
				}
			}
		}

		s_lastWindowIndex = lastWindowIndex;
	}

	void SetExtraItemText()
	{
		ItemDisplayExtraInfo& extraInfo = s_itemDisplayExtraInfo[this];

		// Update item info
		auto buf = fmt::memory_buffer();
		fmt::format_to(fmt::appender(buf), "<BR><c \"#{:6X}\">", s_settings.GetItemColor().ToRGB());
		CreateItemText(buf, pItem, ItemInfo);
		fmt::format_to(std::back_inserter(buf), "</c>");
		extraInfo.extraItemInfo = to_string(buf);

		// Update spell info
		std::string spellInfo;
		if (s_settings.IsShowSpellInfoOnItemsEnabled())
		{
			static eItemSpellType spellTypes[] = {
				ItemSpellType_Clicky,
				ItemSpellType_Proc,
				ItemSpellType_Worn,
				ItemSpellType_Focus,
				ItemSpellType_Scroll,
				ItemSpellType_Focus2,
				ItemSpellType_Blessing,
			};

			bool spellTypeUsed[ItemSpellType_Max] = {};

			for (eItemSpellType spellType : spellTypes)
			{
				// Some of these enums might be duplicates depending on the client
				if (spellTypeUsed[spellType])
					continue;
				spellTypeUsed[spellType] = true;

				ItemSpellData::SpellData* spellData = pItem->GetSpellData(spellType);
				if (spellData->SpellID > 0)
				{
					spellInfo.append(CreateItemSpellText(spellType, spellData));
				}
			}
		}

		extraInfo.extraSpellInfo = std::move(spellInfo);
	}

	void Update()
	{
		if (!pItem)
		{
			s_itemDisplayExtraInfo.erase(this);
			return;
		}

		// Refresh/Update buttons
		UpdateButtons();
	}

	void ForceUpdate()
	{
		s_inSetItem = true;

		// This will update our controls and strings like an initial load of the window
		UpdateStrings_Detour();

		s_inSetItem = false;
	}

	//============================================================================

	DETOUR_TRAMPOLINE_DEF(void, UpdateStrings_Trampoline, ())
	void UpdateStrings_Detour()
	{
		if (s_inSetItem)
		{
			s_needUpdateLastWindowIndex = true;

			SetExtraItemText();
		}

		UpdateStrings_Trampoline();

		// update our strings
		ItemDisplayExtraInfo& extraInfo = s_itemDisplayExtraInfo[this];
		extraInfo.itemInformationText = STMLToText(this->ItemInformationText);
		extraInfo.itemInfo = STMLToText(this->ItemInfo);
		extraInfo.itemMadeByText = STMLToText(this->ItemMadeByText);
		extraInfo.itemAdvancedLoreText = STMLToText(this->ItemAdvancedLoreText);
		extraInfo.windowTitle = STMLToText(this->WindowTitle);

#if HAS_ITEM_WINDOW_COLLECTED
		extraInfo.collectedReceived = this->bCollectedReceived;
		extraInfo.collected = this->bCollected && this->bCollectedReceived;
#endif
#if HAS_ITEM_WINDOW_SCRIBED
		extraInfo.scribedReceived = this->bScribedReceived;
		extraInfo.scribed = this->bScribed && this->bScribedReceived;
#endif

		Description->AppendSTML(CXStr(extraInfo.extraItemInfo));
		Description->AppendSTML(CXStr(extraInfo.extraSpellInfo));

		if (s_inSetItem)
		{
			Update();
		}
	}

	DETOUR_TRAMPOLINE_DEF(void, SetItem_Trampoline, (const ItemPtr& pItem, int flags))
	void SetItem_Detour(const ItemPtr& pItem, int flags)
	{
		ItemDisplayExtraInfo& extraInfo = s_itemDisplayExtraInfo[this];
		extraInfo.ResetItem();

		s_inSetItem = true;

		// This will call into UpdateStrings too.
		SetItem_Trampoline(pItem, flags);

		s_inSetItem = false;
	}

	//----------------------------------------------------------------------------
private:

	void OnHooked()
	{
		if (IsVisible() && pItem)
		{
			ForceUpdate();
		}
	}

	void OnAboutToUnhook()
	{
		// Reset strings back to the way they were before.
		UpdateStrings_Trampoline();
	}
};


class SpellDisplayHook : public CSpellDisplayWnd
{
public:
	DETOUR_TRAMPOLINE_DEF(void, UpdateStrings_Trampoline, ())
	void UpdateStrings_Detour()
	{
		UpdateStrings_Trampoline();

		if (s_settings.IsShowSpellInfoOnSpellsEnabled())
		{
			EQ_Spell* pSpell = GetSpellByID(SpellID);
			if (pSpell == nullptr)
			{
				return;
			}

			std::string spellText = CreateSpellText(pSpell);
			if (!spellText.empty())
			{
				if (CStmlWnd* description = (CStmlWnd*)GetChildItem("SDW_SpellDescription"))
				{
					description->AppendSTML(CXStr(spellText));
				}
			}
		}
	}
};

void ItemDisplayCmd(SPAWNINFO* pChar, char* szLine)
{
	if (szLine && szLine[0] == '\0')
	{
		WriteChatf("Usage:");
		WriteChatf("    /itemdisplay LootButton [on|off]");
		WriteChatf("    /itemdisplay LucyButton [on|off]");
		WriteChatf("    /itemdisplay reload");
		return;
	}

	char szArg1[MAX_STRING] = { 0 };
	char szArg2[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);

	if (ci_equals(szArg1, "lootbutton") || ci_equals(szArg1, "lucybutton"))
	{
		GetArg(szArg2, szLine, 2);
		bool bOn = true;
		bool bToggle = true;

		if (szArg2 && szArg2[0] != '\0')
		{
			if (ci_equals(szArg2, "off"))
			{
				bToggle = false;
				bOn = false;
			}
			else if (ci_equals(szArg2, "on"))
			{
				bToggle = false;
			}
		}

		if (ci_equals(szArg1, "lootbutton"))
		{
			s_settings.SetLootButtonsEnabled(bToggle ? !s_settings.IsLootButtonsEnabled() : bOn);
			WriteChatf("Display of the loot filter buttons is now %s.", (s_settings.IsLootButtonsEnabled() ? "\agEnabled\ax" : "\arDisabled\ax"));
		}
		else if (ci_equals(szArg1, "lucybutton"))
		{
			s_settings.SetLucyButtonEnabled(bToggle ? !s_settings.IsLucyButtonEnabled() : bOn);
			WriteChatf("Display of the lucy button is now \ay%s\ax.", (s_settings.IsLucyButtonEnabled() ? "\agEnabled\ax" : "\agDisabled\ax"));
		}
	}
	else if (ci_equals(szArg1, "reload"))
	{
		s_settings.Load();
	}
}

void ItemNoteCmd(SPAWNINFO* pChar, char* szLine)
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

void DrawItemDisplaySettingsPanel()
{
	bool showLootButtons = s_settings.IsLootButtonsEnabled();
	if (ImGui::Checkbox("Show Loot Filter Buttons", &showLootButtons))
	{
		s_settings.SetLootButtonsEnabled(showLootButtons);
	}

	bool showLucyButton = s_settings.IsLucyButtonEnabled();
	if (ImGui::Checkbox("Show Lucy Button", &showLucyButton))
	{
		s_settings.SetLucyButtonEnabled(showLucyButton);
	}

	bool showItemSpells = s_settings.IsShowSpellInfoOnItemsEnabled();
	if (ImGui::Checkbox("Show Spell Info on Items", &showItemSpells))
	{
		s_settings.SetShowSpellInfoOnItemsEnabled(showItemSpells);
	}

	bool showSpells = s_settings.IsShowSpellInfoOnSpellsEnabled();
	if (ImGui::Checkbox("Show Spell Info on Spells", &showSpells))
	{
		s_settings.SetShowSpellInfoOnSpellsEnabled(showSpells);
	}

	{
		ImColor imColor = s_settings.GetItemColor().ToImColor();

		ImGui::SetNextItemWidth(-120.f);
		if (ImGui::ColorEdit3("Item Text", &imColor.Value.x))
		{
			MQColor newColor;
			newColor.Blue = static_cast<uint8_t>(imColor.Value.z * 255);
			newColor.Green = static_cast<uint8_t>(imColor.Value.y * 255);
			newColor.Red = static_cast<uint8_t>(imColor.Value.x * 255);
			newColor.Alpha = 255;

			s_settings.SetItemColor(newColor);
		}

		if (s_settings.GetItemColor() != s_settings.default_itemColor)
		{
			ImGui::SameLine();
			ImGui::SetNextItemWidth(20.f);
			if (ImGui::Button("Reset"))
			{
				s_settings.ResetItemColor();
			}
		}
	}

	{
		ImColor imColor = s_settings.GetSpellColor().ToImColor();

		ImGui::SetNextItemWidth(-120.f);

		if (ImGui::ColorEdit3("Spell Text", &imColor.Value.x))
		{
			MQColor newColor;
			newColor.Blue = static_cast<uint8_t>(imColor.Value.z * 255);
			newColor.Green = static_cast<uint8_t>(imColor.Value.y * 255);
			newColor.Red = static_cast<uint8_t>(imColor.Value.x * 255);
			newColor.Alpha = 255;

			s_settings.SetSpellColor(newColor);
		}

		if (s_settings.GetSpellColor() != s_settings.default_spellColor)
		{
			ImGui::SameLine();
			ImGui::SetNextItemWidth(20.f);

			if (ImGui::Button("Reset"))
			{
				s_settings.ResetSpellColor();
			}
		}
	}

	ImGui::NewLine();
	ImGui::Text("Item Spell Text Colors");
	ImGui::Separator();

	for (const auto& config : s_itemEffectConfigs)
	{
		ImGui::PushID((int)config.effectType);

		auto [color, text] = GetEffectInfo(config.effectType, false);
		std::optional<MQColor> customColor = s_settings.GetItemSpellColor(config.effectType);
		ImColor imColor = customColor.value_or(color).ToImColor();

		ImGui::SetNextItemWidth(-120.f);
		if (ImGui::ColorEdit3(text.data(), &imColor.Value.x))
		{
			MQColor newColor;
			newColor.Blue = static_cast<uint8_t>(imColor.Value.z * 255);
			newColor.Green = static_cast<uint8_t>(imColor.Value.y * 255);
			newColor.Red = static_cast<uint8_t>(imColor.Value.x * 255);
			newColor.Alpha = 255;

			s_settings.SetItemSpellColor(config.effectType, newColor);
		}

		if (customColor.has_value())
		{
			ImGui::SameLine();
			ImGui::SetNextItemWidth(20.f);
			if (ImGui::Button("Reset"))
			{
				s_settings.ResetItemSpellColor(config.effectType);
			}
		}

		ImGui::PopID();
	}

	ImGui::Separator();

	if (ImGui::Button("Reload Settings"))
	{
		s_settings.Load();
	}

	ImGui::SameLine();
	if (ImGui::Button("Reset Settings"))
	{
		s_settings.Reset();
	}
}

// Called once, when the plugin is to initialize
PLUGIN_API void InitializePlugin()
{
	EzDetour(CSpellDisplayWnd__UpdateStrings, &SpellDisplayHook::UpdateStrings_Detour, &SpellDisplayHook::UpdateStrings_Trampoline);
	EzDetour(CItemDisplayWnd__UpdateStrings, &CItemDisplayWndOverride::UpdateStrings_Detour, &CItemDisplayWndOverride::UpdateStrings_Trampoline);
	EzDetour(CItemDisplayWnd__SetItem, &CItemDisplayWndOverride::SetItem_Detour, &CItemDisplayWndOverride::SetItem_Trampoline);

	AddCommand("/itemdisplay", ItemDisplayCmd);
	AddCommand("/inote", ItemNoteCmd);

	pDisplayItemType = new MQ2DisplayItemType;
	pDisplayItemType->SetInheritance(pItemType);
	AddMQ2Data("DisplayItem", MQ2DisplayItemType::dataDisplayItem);

	AddSettingsPanel("plugins/ItemDisplay", DrawItemDisplaySettingsPanel);

	s_settings.Load();
	s_refreshSpellDisplay = true;
}

// Called once, when the plugin is to shutdown
PLUGIN_API void ShutdownPlugin()
{
	// Remove commands, macro parameters, hooks, etc.
	RemoveDetour(CItemDisplayWnd__UpdateStrings);
	RemoveDetour(CItemDisplayWnd__SetItem);
	RemoveDetour(CSpellDisplayWnd__UpdateStrings);

	s_itemDisplayExtraInfo.clear();

	RemoveMQ2Data("DisplayItem");
	RemoveCommand("/inote");
	RemoveCommand("/itemdisplay");

	RemoveSettingsPanel("plugins/ItemDisplay");

	delete pDisplayItemType;
}

PLUGIN_API void OnCleanUI()
{
	s_itemDisplayExtraInfo.clear();

	if (pItemDisplayManager && pItemDisplayManager->GetCount() > 0)
	{
		for (int i = 1; i < pItemDisplayManager->GetCount(); ++i)
		{
			CItemDisplayWndOverride::RestoreVFTable(pItemDisplayManager->GetWindow(i));
		}

		CItemDisplayWndOverride::RemoveHooks(pItemDisplayManager->GetWindow(0));
	}

	if (pSpellDisplayManager)
	{
		for (int i = 0; i < pSpellDisplayManager->GetCount(); ++i)
		{
			SpellDisplayHook* pWindow = (SpellDisplayHook*)pSpellDisplayManager->GetWindow(i);
			if (pWindow && pWindow->IsVisible())
			{
				pWindow->UpdateStrings_Trampoline();
			}
		}
	}
}

PLUGIN_API void OnPulse()
{
	if (gGameState == GAMESTATE_INGAME)
	{
		// Check if we're able to hook the ItemDisplayWnd yet. We only need one instance.
		// These are created dynamically so we need to wait for it to exist before we can hook it.
		if (!CItemDisplayWndOverride::IsHooked()
			&& pItemDisplayManager
			&& pItemDisplayManager->GetCount() > 0)
		{
			CItemDisplayWndOverride::InstallHooks(pItemDisplayManager->GetWindow(0));
		}

		if (CItemDisplayWndOverride::IsHooked()
			&& pItemDisplayManager
			&& pItemDisplayManager->GetCount() > 1)
		{
			// Replacate hooks to other windows
			for (int i = 1; i < pItemDisplayManager->GetCount(); ++i)
			{
				CItemDisplayWndOverride::InstallAdditionalHook(pItemDisplayManager->GetWindow(i));
			}
		}

		if (CItemDisplayWndOverride::s_needUpdateLastWindowIndex)
		{
			CItemDisplayWndOverride::s_needUpdateLastWindowIndex = false;
			CItemDisplayWndOverride::UpdateLastWindowIndex();
		}

		if (s_refreshItemDisplay)
		{
			s_refreshItemDisplay = false;

			if (pItemDisplayManager)
			{
				for (int i = 0; i < pItemDisplayManager->GetCount(); ++i)
				{
					CItemDisplayWndOverride* pOverride = (CItemDisplayWndOverride*)pItemDisplayManager->GetWindow(i);
					if (pOverride && pOverride->IsVisible())
					{
						pOverride->ForceUpdate();
					}
				}
			}
		}

		if (s_refreshSpellDisplay)
		{
			s_refreshSpellDisplay = false;

			if (pSpellDisplayManager)
			{
				for (int i = 0; i < pSpellDisplayManager->GetCount(); ++i)
				{
					SpellDisplayHook* pWindow = (SpellDisplayHook*)pSpellDisplayManager->GetWindow(i);
					if (pWindow && pWindow->IsVisible())
					{
						pWindow->UpdateStrings_Detour();
					}
				}
			}
		}
	}
}
