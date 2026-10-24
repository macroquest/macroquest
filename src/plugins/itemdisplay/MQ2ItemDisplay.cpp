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
#include <array>
#include <fstream>

#include <regex>
#include <misc/cpp/imgui_stdlib.h>

using namespace mq::datatypes;

PreSetup("MQ2ItemDisplay");

// Keep data about the recent items that have been displayed.
static int s_lastWindowIndex = -1;

class MQ2DisplayItemType;
MQ2DisplayItemType* pDisplayItemType = nullptr;

const int BUTTON_SPACING = 22;
const int BUTTON_GROUP_HEIGHT = 34;

const int MAX_CUSTOM_BUTTONS = 20;

static bool s_refreshItemDisplay = false;
static bool s_refreshSpellDisplay = false;

static bool s_inOnCleanUI = false;
static bool s_settingsChangedForImGui = false;

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
	static constexpr inline int default_windowX = 0;
	static constexpr inline int default_windowY = 0;
	static constexpr inline int default_windowWidth = 400;
	static constexpr inline int default_windowHeight = 600;

	static constexpr inline bool default_persistWindowBounds = false;

	static constexpr inline bool default_lootButtonsEnabled = true;
	static const inline int default_customURLCount = 1;
	static const inline int default_custombuttonCount = 0;
	static constexpr inline bool default_showSpellInfoOnItems = true;
	static constexpr inline bool default_showSpellInfoOnSpells = true;
	static constexpr inline MQColor default_spellColor = "#00ffff";
	static constexpr inline MQColor default_itemColor = "#00ffff";

	inline bool IsLootButtonsEnabled() const { return m_lootButtonsEnabled; }
	void SetLootButtonsEnabled(bool enabled);

	inline int GetCustomURLCount() const { return m_customURLCount; }
	void SetCustomURLCount(int count);
	inline int GetCustomButtonCount() const { return m_custombuttonCount; }
	void SetCustomButtonCount(int count);

	inline std::string ButtonURL(int idx) const;
	inline std::string ButtonName(int idx) const;
	void SetButtonURL(int idx, std::string url);
	void SetButtonName(int idx, std::string name);

	struct CustomButton
	{
		std::string action;
		std::string name;
		bool pickupEnabled;
	};

	static inline const std::vector<CustomButton> default_customURL = []() {
		std::vector<CustomButton> configs;
		configs.reserve(MAX_CUSTOM_BUTTONS);
		configs.push_back({ "https://lucy.allakhazam.com/item.html?id=%id%", "Lucy", false });
		for (int i = 2; i <= MAX_CUSTOM_BUTTONS; ++i) {
			configs.push_back({ "", "Custom" + std::to_string(i), false });
		}
		return configs;
		}();

	static inline const std::vector<CustomButton> default_customButton = []() {
		std::vector<CustomButton> configs;
		configs.reserve(MAX_CUSTOM_BUTTONS);
		for (int i = 1; i <= MAX_CUSTOM_BUTTONS; ++i) {
			configs.push_back({ "", "Custom" + std::to_string(i), false });
		}
		return configs;
		}();

	inline std::string CustButtonAction(int idx) const;
	inline std::string CustButtonName(int idx) const;
	inline bool IsCustPickupItemEnabled(int idx) const;
	void SetCustButtonAction(int idx, std::string action);
	void SetCustButtonName(int idx, std::string name);
	void SetCustPickupItemEnabled(int idx, bool enabled);

	inline bool IsShowSpellInfoOnItemsEnabled() const { return m_showSpellInfoOnItems; }
	void SetShowSpellInfoOnItemsEnabled(bool enabled);

	inline bool IsShowSpellInfoOnSpellsEnabled() const { return m_showSpellInfoOnSpells; }
	void SetShowSpellInfoOnSpellsEnabled(bool enabled);
	inline int GetWindowX() const { return m_windowX; }
	inline int GetWindowY() const { return m_windowY; }
	inline int GetWindowWidth() const { return m_windowWidth; }
	inline int GetWindowHeight() const { return m_windowHeight; }
	inline bool PersistWindowBounds() const { return m_persistWindowBounds; }
	void SetWindowX(int x);
	void SetWindowY(int y);
	void SetWindowWidth(int width);
	void SetWindowHeight(int height);
	void SetPersistWindowBounds(bool persist);

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
	int m_windowX = default_windowX;
	int m_windowY = default_windowY;
	int m_windowWidth = default_windowWidth;
	int m_windowHeight = default_windowHeight;

	bool m_persistWindowBounds = default_persistWindowBounds;

	bool m_lootButtonsEnabled = default_lootButtonsEnabled;
	int m_customURLCount = default_customURLCount;
	int m_custombuttonCount = default_custombuttonCount;
	std::vector<CustomButton> m_customURL = default_customURL;
	std::vector<CustomButton> m_customButtons = default_customButton;
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


	m_windowX = GetPrivateProfileInt("Settings", "WindowX", default_windowX, INIFileName);
	m_windowY = GetPrivateProfileInt("Settings", "WindowY", default_windowY, INIFileName);
	m_windowWidth = GetPrivateProfileInt("Settings", "WindowWidth", default_windowWidth, INIFileName);
	m_windowHeight = GetPrivateProfileInt("Settings", "WindowHeight", default_windowHeight, INIFileName);

	m_persistWindowBounds = GetPrivateProfileBool("Settings", "PersistWindowBounds", default_persistWindowBounds, INIFileName);

	m_lootButtonsEnabled = GetPrivateProfileBool("Settings", "LootButton", default_lootButtonsEnabled, INIFileName);
	m_showSpellInfoOnItems = GetPrivateProfileBool("Settings", "ShowSpellsInfoOnItems", default_showSpellInfoOnItems, INIFileName);
	m_showSpellInfoOnSpells = GetPrivateProfileBool("Settings", "ShowSpellInfoOnSpells", default_showSpellInfoOnSpells, INIFileName);

	m_customURLCount = std::clamp(GetPrivateProfileInt("Settings", "CustomURLCount", default_customURLCount, INIFileName), 0, MAX_CUSTOM_BUTTONS);
	m_custombuttonCount = std::clamp(GetPrivateProfileInt("Settings", "CustomButtonCount", default_custombuttonCount, INIFileName), 0, MAX_CUSTOM_BUTTONS);

	for (int i = 1; i <= m_customURLCount; ++i)
	{
		std::string actionKey = fmt::format("Button{:02d}URL", i);
		std::string nameKey = fmt::format("Button{:02d}Name", i);

		m_customURL[i - 1].action = GetPrivateProfileString("Settings", actionKey.c_str(), default_customURL[i - 1].action, INIFileName);
		m_customURL[i - 1].name = GetPrivateProfileString("Settings", nameKey.c_str(), default_customURL[i - 1].name, INIFileName);
	}

	for (int i = 1; i <= m_custombuttonCount; ++i)
	{
		std::string actionKey = fmt::format("Cust{:02d}Action", i);
		std::string nameKey = fmt::format("Cust{:02d}Name", i);
		std::string pickupKey = fmt::format("Cust{:02d}PickupItemEnabled", i);

		m_customButtons[i - 1].action = GetPrivateProfileString("Settings", actionKey.c_str(), default_customButton[i - 1].action, INIFileName);
		m_customButtons[i - 1].name = GetPrivateProfileString("Settings", nameKey.c_str(), default_customButton[i - 1].name, INIFileName);
		m_customButtons[i - 1].pickupEnabled = GetPrivateProfileBool("Settings", pickupKey.c_str(), default_customButton[i - 1].pickupEnabled, INIFileName);
	}

	const auto validHexColor = [](const std::string& value) -> bool
		{
			if (value.size() != 7 || value[0] != '#')
				return false;
			for (size_t i = 1; i < 7; ++i)
			{
				unsigned char ch = static_cast<unsigned char>(value[i]);
				if (!std::isxdigit(ch))
					return false;
			}
			return true;
		};

	for (const auto& conf : s_itemEffectConfigs)
	{
		std::string setting = GetPrivateProfileString("Settings", fmt::format("CustomColor_{}", conf.label), std::string(), INIFileName);
		if (validHexColor(setting))
		{
			m_customColors[conf.effectType] = MQColor(setting.c_str());
		}
	}

	std::string itemColor = GetPrivateProfileString("Settings", "CustomColor_Item", std::string(), INIFileName);
	if (validHexColor(itemColor))
	{
		m_itemColor = MQColor(itemColor.c_str());
	}

	std::string spellColor = GetPrivateProfileString("Settings", "CustomColor_Spell", std::string(), INIFileName);
	if (validHexColor(spellColor))
	{
		m_spellColor = MQColor(spellColor.c_str());
	}

	// Notify UI to refresh
	s_refreshItemDisplay = true;
	s_refreshSpellDisplay = true;
	s_settingsChangedForImGui = true;
}

void Settings::Reset()
{
	m_customColors.clear();
	m_windowX = default_windowX;
	m_windowY = default_windowY;
	m_windowWidth = default_windowWidth;
	m_windowHeight = default_windowHeight;
	m_persistWindowBounds = default_persistWindowBounds;
	m_lootButtonsEnabled = default_lootButtonsEnabled;
	m_customURLCount = default_customURLCount;
	m_custombuttonCount = default_custombuttonCount;
	m_itemColor = default_itemColor;
	m_spellColor = default_spellColor;
	m_customURL = default_customURL;
	m_customButtons = default_customButton;
	m_showSpellInfoOnItems = default_showSpellInfoOnItems;
	m_showSpellInfoOnSpells = default_showSpellInfoOnSpells;

	DeletePrivateProfileKey("Settings", "LootButton", INIFileName);
	DeletePrivateProfileKey("Settings", "CustomURLCount", INIFileName);
	DeletePrivateProfileKey("Settings", "CustomButtonCount", INIFileName);
	DeletePrivateProfileKey("Settings", "PersistWindowBounds", INIFileName);
	DeletePrivateProfileKey("Settings", "WindowX", INIFileName);
	DeletePrivateProfileKey("Settings", "WindowY", INIFileName);
	DeletePrivateProfileKey("Settings", "WindowWidth", INIFileName);
	DeletePrivateProfileKey("Settings", "WindowHeight", INIFileName);
	DeletePrivateProfileKey("Settings", "ShowSpellsInfoOnItems", INIFileName);
	DeletePrivateProfileKey("Settings", "ShowSpellInfoOnSpells", INIFileName);
	for (int i = 1; i <= MAX_CUSTOM_BUTTONS; ++i)
	{
		DeletePrivateProfileKey("Settings", fmt::format("Button{:02d}URL", i), INIFileName);
		DeletePrivateProfileKey("Settings", fmt::format("Button{:02d}Name", i), INIFileName);
		DeletePrivateProfileKey("Settings", fmt::format("Cust{:02d}Action", i), INIFileName);
		DeletePrivateProfileKey("Settings", fmt::format("Cust{:02d}Name", i), INIFileName);
		DeletePrivateProfileKey("Settings", fmt::format("Cust{:02d}PickupItemEnabled", i), INIFileName);
	}

	for (const auto& conf : s_itemEffectConfigs)
	{
		DeletePrivateProfileKey("Settings", fmt::format("CustomColor_{}", conf.label), INIFileName);
	}

	ResetItemColor();
	ResetSpellColor();

	// Notify UI to refresh
	s_refreshItemDisplay = true;
	s_refreshSpellDisplay = true;
	s_settingsChangedForImGui = true;
}

void Settings::SetWindowX(int x)
{
	if (x == m_windowX)
		return;

	m_windowX = x;
	WritePrivateProfileInt("Settings", "WindowX", m_windowX, INIFileName);
}
void Settings::SetWindowY(int y)
{
	if (y == m_windowY)
		return;

	m_windowY = y;
	WritePrivateProfileInt("Settings", "WindowY", m_windowY, INIFileName);
}
void Settings::SetWindowWidth(int width)
{
	if (width == m_windowWidth)
		return;

	m_windowWidth = width;
	WritePrivateProfileInt("Settings", "WindowWidth", m_windowWidth, INIFileName);
}
void Settings::SetWindowHeight(int height)
{
	if (height == m_windowHeight)
		return;

	m_windowHeight = height;
	WritePrivateProfileInt("Settings", "WindowHeight", m_windowHeight, INIFileName);
}
void Settings::SetPersistWindowBounds(bool persist)
{
	if (persist == m_persistWindowBounds)
		return;

	m_persistWindowBounds = persist;
	WritePrivateProfileBool("Settings", "PersistWindowBounds", m_persistWindowBounds, INIFileName);
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
		fmt::format("#{:06X}", color.ToRGB()), INIFileName);

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

void Settings::SetCustomURLCount(int count)
{
	count = std::clamp(count, 0, MAX_CUSTOM_BUTTONS);
	if (count == m_customURLCount)
		return;
	m_customURLCount = count;
	WritePrivateProfileInt("Settings", "CustomURLCount", m_customURLCount, INIFileName);
	s_refreshItemDisplay = true;
	s_settingsChangedForImGui = true;
}

void Settings::SetCustomButtonCount(int count)
{
	count = std::clamp(count, 0, MAX_CUSTOM_BUTTONS);
	if (count == m_custombuttonCount)
		return;

	m_custombuttonCount = count;
	WritePrivateProfileInt("Settings", "CustomButtonCount", m_custombuttonCount, INIFileName);
	s_refreshItemDisplay = true;
	s_settingsChangedForImGui = true;
}

inline std::string Settings::ButtonURL(int idx) const
{
	if (idx < 0 || idx >= static_cast<int>(m_customURL.size()))
		return {};
	return m_customURL[idx].action;
}

inline std::string Settings::ButtonName(int idx) const
{
	if (idx < 0 || idx >= static_cast<int>(m_customURL.size()))
		return {};
	return m_customURL[idx].name;
}

void Settings::SetButtonURL(int idx, const std::string action)
{
	if (idx < 0 || idx >= static_cast<int>(m_customURL.size()))
		return;
	if (action == m_customURL[idx].action)
		return;

	m_customURL[idx].action = action;
	WritePrivateProfileString("Settings", fmt::format("Button{:02d}URL", idx + 1), m_customURL[idx].action, INIFileName);
	s_refreshItemDisplay = true;
	s_settingsChangedForImGui = true;
}

void Settings::SetButtonName(int idx, std::string name)
{
	if (idx < 0 || idx >= static_cast<int>(m_customURL.size()))
		return;
	if (name == m_customURL[idx].name)
		return;
	if (name.empty())
		name = default_customURL[idx].name;

	m_customURL[idx].name = name;
	WritePrivateProfileString("Settings", fmt::format("Button{:02d}Name", idx + 1), m_customURL[idx].name, INIFileName);
	s_refreshItemDisplay = true;
	s_settingsChangedForImGui = true;
}

std::string Settings::CustButtonAction(int idx) const
{
	if (idx < 0 || idx >= static_cast<int>(m_customButtons.size()))
		return {};
	return m_customButtons[idx].action;
}

std::string Settings::CustButtonName(int idx) const
{
	if (idx < 0 || idx >= static_cast<int>(m_customButtons.size()))
		return {};
	return m_customButtons[idx].name;
}

bool Settings::IsCustPickupItemEnabled(int idx) const
{
	if (idx < 0 || idx >= static_cast<int>(m_customButtons.size()))
		return false;
	return m_customButtons[idx].pickupEnabled;
}

void Settings::SetCustButtonAction(int idx, std::string action)
{
	if (idx < 0 || idx >= static_cast<int>(m_customButtons.size()))
		return;
	if (action == m_customButtons[idx].action)
		return;

	m_customButtons[idx].action = action;
	WritePrivateProfileString("Settings", fmt::format("Cust{:02d}Action", idx + 1), m_customButtons[idx].action, INIFileName);

	s_refreshItemDisplay = true;
	s_settingsChangedForImGui = true;
}

void Settings::SetCustButtonName(int idx, std::string name)
{
	if (idx < 0 || idx >= static_cast<int>(m_customButtons.size()))
		return;
	if (name == m_customButtons[idx].name)
		return;
	if (name.empty())
		name = default_customButton[idx].name;

	m_customButtons[idx].name = name;
	WritePrivateProfileString("Settings", fmt::format("Cust{:02d}Name", idx + 1), m_customButtons[idx].name, INIFileName);
	s_refreshItemDisplay = true;
	s_settingsChangedForImGui = true;
}

void Settings::SetCustPickupItemEnabled(int idx, bool enabled)
{
	if (idx < 0 || idx >= static_cast<int>(m_customButtons.size()))
		return;
	if (enabled == m_customButtons[idx].pickupEnabled)
		return;

	m_customButtons[idx].pickupEnabled = enabled;
	WritePrivateProfileBool("Settings", fmt::format("Cust{:02d}PickupItemEnabled", idx + 1), m_customButtons[idx].pickupEnabled, INIFileName);
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
	std::array<std::unique_ptr<CButtonWnd>, MAX_CUSTOM_BUTTONS> pURLButtons{};
	std::array<std::unique_ptr<CButtonWnd>, MAX_CUSTOM_BUTTONS> pCustButtons{};
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
	void SetCustomButtonsPosition(const CXPoint& labelPos);
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

	for (auto& b : pURLButtons) b.reset();
	for (auto& b : pCustButtons) b.reset();
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

	// URL Button Grid layout configuration
	const int itemsPerColumn = 2;    // Number of rows before wrapping right
	const int horizontalPitch = 36;  // Adjust based on your UI needs (button width 36 + padding)
	const int verticalPitch = 20;    // Adjust based on BUTTON_SPACING or preferred row gap
	const CXSize urlButtonSize(36, 20);

	// Starting base offsets relative to headerRect
	const int baseLeftOffset = pHeader ? (headerRect.GetWidth() + 6) : 0;
	const int baseTopOffset = -10;

	// Loop handles any number of URL buttons automatically
	for (size_t i = 0; i < pURLButtons.size(); ++i)
	{
		if (!pURLButtons[i])
			continue;

		// Calculate 2D grid coordinates (Fills columns vertically first)
		int row = static_cast<int>(i) % itemsPerColumn;
		int col = static_cast<int>(i) / itemsPerColumn;

		// Calculate dynamic position offsets
		int leftOffset = baseLeftOffset + (col * horizontalPitch);
		int topOffset = baseTopOffset + (row * verticalPitch);

		// Apply positions safely
		CXRect buttonRect = headerRect;
		buttonRect.SetLeft(buttonRect.left + leftOffset);
		buttonRect.SetTop(buttonRect.top + topOffset);
		buttonRect.SetSize(urlButtonSize);

		pURLButtons[i]->SetLocation(buttonRect);
	}
}
void ItemDisplayExtraInfo::SetCustomButtonsPosition(const CXPoint& labelPos)
{
	CXRect headerRect{ labelPos, CXSize(80, 12) };

	const int itemsPerColumn = 2;   // Number of rows before wrapping right
	const int horizontalPitch = 44; // Distance between starting points of adjacent buttons
	const int verticalPitch = 15;   // Distance between rows
	const CXSize custButtonSize(44, 15);

	// Starting offsets relative to headerRect
	const int baseLeftOffset = 60;  // 80 - 20 from original code
	const int baseTopOffset = -8;

	// Loop scales automatically across X-axis first
	for (size_t i = 0; i < pCustButtons.size(); ++i)
	{
		if (!pCustButtons[i])
			continue;

		// Calculate 2D grid coordinates (Filling columns vertically first)
		int row = static_cast<int>(i) % itemsPerColumn;
		int col = static_cast<int>(i) / itemsPerColumn;

		// Calculate dynamic position offsets
		int leftOffset = baseLeftOffset + (col * horizontalPitch);
		int topOffset = baseTopOffset + (row * verticalPitch);

		// Apply positions safely
		CXRect buttonRect = headerRect;
		buttonRect.SetLeft(buttonRect.left + leftOffset);
		buttonRect.SetTop(buttonRect.top + topOffset);
		buttonRect.SetSize(custButtonSize);

		pCustButtons[i]->SetLocation(buttonRect);
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
			case ResistType_Physical:   fmt::format_to(buffer, "Resist: Physical"); break;
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

static std::string ReplaceCustomButtonVariables(const ItemPtr& pItem, std::string text)
{
	std::regex name("%name%");
	std::regex id("%id%");
	std::regex count("%count%");
	text = std::regex_replace(text, name, pItem->GetName());
	text = std::regex_replace(text, id, std::to_string(pItem->GetID()));
	text = std::regex_replace(text, count, std::to_string(FindInventoryItemCountByName(pItem->GetName())));
	return text;
}

static void HandleURLButton(int index, const ItemPtr& pItem)
{
	if (!pItem) return;
	if (s_settings.ButtonURL(index).empty()) return;

	std::string replaced = ReplaceCustomButtonVariables(pItem, s_settings.ButtonURL(index));
	ShellExecuteA(nullptr, "open", replaced.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}

static void HandleCustButton(int index, const ItemPtr& pItem)
{
	if (!pItem) return;
	if (s_settings.CustButtonAction(index).empty()) return;

	if (s_settings.IsCustPickupItemEnabled(index))
	{
		PcProfile* pProfile = GetPcProfile();
		ItemPtr pCursorItem = pProfile ? pProfile->GetInventorySlot(InvSlot_Cursor) : nullptr;
		if (!pCursorItem || pCursorItem->ItemGUID != pItem->ItemGUID)
		{
			std::string pickupItem = fmt::format("/nomodkey /shiftkey /itemnotify \"{}\" leftmouseup", pItem->GetName());
			EzCommand(pickupItem.c_str());
		}
	}

	EzCommand(ReplaceCustomButtonVariables(pItem, s_settings.CustButtonAction(index)).c_str());
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

			for (int i = 0; i < s_settings.GetCustomURLCount(); ++i)
			{
				if (extraInfo.pURLButtons[i].get() == sender)
				{
					HandleURLButton(i, pItem);
					return 0;
				}
			}

			for (int i = 0; i < s_settings.GetCustomButtonCount(); ++i)
			{
				if (extraInfo.pCustButtons[i].get() == sender)
				{
					HandleCustButton(i, pItem);
					return 0;
				}
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
#if !IS_EXPANSION_LEVEL(EXPANSION_LEVEL_COTF) // RoF2 or earlier
		else if (message == XWM_SPELL_LINK)
		{
			std::string_view spellLinkText = std::string_view(static_cast<const char*>(data));

			// Format like a spell link so we can parse it using the link parser
			fmt::memory_buffer buf;
			fmt::format_to(fmt::appender(buf), "{}{}{}{}", ITEM_TAG_CHAR, static_cast<int>(ETAG_SPELL), spellLinkText, ITEM_TAG_CHAR);

			SpellLinkInfo linkInfo;
			ParseSpellLink(std::string_view(buf.data(), buf.size()), linkInfo);

			if (linkInfo.spellID != 0 && pSpellDisplayManager)
			{
				pSpellDisplayManager->ShowSpell(linkInfo.spellID, !pWndMgr->IsShiftKey(), true, SpellDisplayType_SpellBookWnd);
			}

			return 0;
		}
#endif

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

		auto createOrReset = [&](bool create, const std::string& text, std::unique_ptr<CButtonWnd>& slot)
			{
				if (create)
				{
					if (CControlTemplate* btnTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("IDW_ModButton"))
					{
						uint32_t oldfont = std::exchange(btnTemplate->nFont, 1);

						CXWnd* pAnchor = this;
						if (CXWnd* pDescriptionTab = GetChildItem("ItemDescriptionTab"))
							pAnchor = pDescriptionTab;

						CButtonWnd* pBtn = (CButtonWnd*)pSidlMgr->CreateXWndFromTemplate(pAnchor, btnTemplate);
						pBtn->SetCRNormal(MQColor(255, 255, 0));
						pBtn->SetWindowText(text.c_str());
						pBtn->SetDecalTint(MQColor(0, 255, 255));
						slot.reset(pBtn);

						btnTemplate->nFont = oldfont;
					}
				}
				else
				{
					slot.reset();
				}
			};
		// Custom buttons
		struct Def { const std::string action; const std::string name; bool pickup; std::unique_ptr<CButtonWnd>* slot; };

		std::vector<Def> URLdefs;
		URLdefs.reserve(s_settings.GetCustomURLCount());
		for (int i = 0; i < s_settings.GetCustomURLCount(); ++i) {
			URLdefs.emplace_back(Def{
				s_settings.ButtonURL(i),
				s_settings.ButtonName(i),
				false,
				&extraInfo.pURLButtons[i]
				});
		}
		std::vector<Def> Buttondefs;
		Buttondefs.reserve(s_settings.GetCustomButtonCount());
		for (int i = 0; i < s_settings.GetCustomButtonCount(); ++i) {
			Buttondefs.emplace_back(Def{
				s_settings.CustButtonAction(i),
				s_settings.CustButtonName(i),
				s_settings.IsCustPickupItemEnabled(i),
				&extraInfo.pCustButtons[i]
				});
		}

		for (auto& d : URLdefs)
		{
			bool shouldCreate = !d.action.empty();
			createOrReset(shouldCreate, d.name, *d.slot);
		}
		for (int i = s_settings.GetCustomURLCount(); i < MAX_CUSTOM_BUTTONS; ++i)
		{
			createOrReset(false, {}, extraInfo.pURLButtons[i]);
		}

		bool haveInventory = (pItem && FindInventoryItemCountByName(pItem->GetName()) > 0);
		for (auto& d : Buttondefs)
		{
			bool shouldCreate = !d.action.empty() && (!d.pickup || (d.pickup && haveInventory));
			createOrReset(shouldCreate, d.name, *d.slot);
		}
		for (int i = s_settings.GetCustomButtonCount(); i < MAX_CUSTOM_BUTTONS; ++i)
		{
			createOrReset(false, {}, extraInfo.pCustButtons[i]);
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
		bool hasURLButton = false;
		for (auto& b : extraInfo.pURLButtons) if (b) { hasURLButton = true; break; }
		if (extraInfo.pHeader || hasURLButton)
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
		bool hasCustButton = false;
		for (auto& b : extraInfo.pCustButtons) if (b) { hasCustButton = true; break; }
		if (hasCustButton)
		{
			//------------------------------------------------------------------------
			// Update position of labels

			// Define the position of everything in terms of the upper left corner of
			// the header label.

			// Try to show it in the 2nd column, if it isn't taken.
			CXWnd* tempWnd = GetChildItem("IDW_ModButtonLabel");
			if (tempWnd)
			{
				extraInfo.SetCustomButtonsPosition(tempWnd->GetLocation().TopLeft());
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

		if (GetGameState() == GAMESTATE_INGAME && s_settings.PersistWindowBounds())
		{
			CXRect rc = GetLocation();
			rc.left = s_settings.GetWindowX();
			rc.top = s_settings.GetWindowY();
			rc.right = s_settings.GetWindowX() + s_settings.GetWindowWidth();
			rc.bottom = s_settings.GetWindowY() + s_settings.GetWindowHeight();

			((CItemDisplayWnd*)this)->UpdateGeometry(rc, true, true, true, true);
		}
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
		// Skip cleaning up after ourselves if we're already destroying the UI
		if (s_inOnCleanUI)
			return;

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

	DETOUR_TRAMPOLINE_DEF(void, SetSpell_Trampoline, (int SpellID, int))
	void SetSpell_Detour(int SpellID, int flags)
	{
		SetSpell_Trampoline(SpellID, flags);

		if (GetGameState() == GAMESTATE_INGAME && s_settings.PersistWindowBounds())
		{
			CXRect rc = GetLocation();
			rc.left = s_settings.GetWindowX();
			rc.top = s_settings.GetWindowY();
			rc.right = s_settings.GetWindowX() + s_settings.GetWindowWidth();
			rc.bottom = s_settings.GetWindowY() + s_settings.GetWindowHeight();

			UpdateGeometry(rc, true, true, true, true);
		}
	}
};

void ItemDisplayCmd(SPAWNINFO* pChar, char* szLine)
{
	if (szLine && szLine[0] == '\0')
	{
		WriteChatf("Usage:");
		WriteChatf("    /itemdisplay LootButton [on|off]");
		WriteChatf("    /itemdisplay CustomURLCount [0-%d]", MAX_CUSTOM_BUTTONS);
		WriteChatf("    /itemdisplay URL[01-%d] \"URL\" \"ButtonName\"", MAX_CUSTOM_BUTTONS);
		WriteChatf("    /itemdisplay CustomButtonCount [0-%d]", MAX_CUSTOM_BUTTONS);
		WriteChatf("    /itemdisplay Custom[01-%d] \"Action\" \"ButtonName\" [PickupItem on|off]", MAX_CUSTOM_BUTTONS);
		WriteChatf("        Action variables: %%name%% %%id%% %%count%%");
		WriteChatf("    /itemdisplay reload");
		return;
	}

	char szArg1[MAX_STRING] = { 0 };
	char szArg2[MAX_STRING] = { 0 };
	char szArg3[MAX_STRING] = { 0 };
	char szArg4[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);

	if (ci_equals(szArg1, "lootbutton"))
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
	}
	else if (ci_equals(szArg1, "customurlcount"))
	{
		GetArg(szArg2, szLine, 2);
		int count = std::clamp(GetIntFromString(szArg2, s_settings.GetCustomURLCount()), 0, MAX_CUSTOM_BUTTONS);
		s_settings.SetCustomURLCount(count);
		WriteChatf("Custom URL button count is now: %d", s_settings.GetCustomURLCount());
	}
	else if (ci_equals(szArg1, "custombuttoncount"))
	{
		GetArg(szArg2, szLine, 2);
		int count = std::clamp(GetIntFromString(szArg2, s_settings.GetCustomButtonCount()), 0, MAX_CUSTOM_BUTTONS);
		s_settings.SetCustomButtonCount(count);
		WriteChatf("Custom button count is now: %d", s_settings.GetCustomButtonCount());
	}
	else if (std::string_view arg1Str{ szArg1 }; _strnicmp(szArg1, "custom", 6) == 0 || (_strnicmp(szArg1, "url", 3) == 0 && arg1Str.size() >= 6 && _stricmp(szArg1 + arg1Str.size() - 6, "button") == 0))
	{
		GetArg(szArg2, szLine, 2);
		GetArg(szArg3, szLine, 3);
		GetArg(szArg4, szLine, 4);
		bool bOn = false;
		bool bToggle = false;

		if (szArg4 && szArg4[0] != '\0')
		{
			if (ci_equals(szArg4, "off"))
			{
				bToggle = true;
				bOn = false;
			}
			else if (ci_equals(szArg4, "on"))
			{
				bToggle = true;
				bOn = true;
			}
		}

		if (_strnicmp(szArg1, "url", 3) == 0)
		{
			// Extract index from "urlXXbutton" (starts at index 3, length 2)
			int displayNum = std::atoi(szArg1 + 3);
			int index = displayNum - 1;

			if (index >= 0 && index < MAX_CUSTOM_BUTTONS) // Safety bounds check for URL buttons
			{
				s_settings.SetButtonURL(index, szArg2);
				s_settings.SetButtonName(index, szArg3);
				WriteChatf("URL button \"\ay%s\ax\" is now: \ay%s\ax", s_settings.ButtonName(index).c_str(), s_settings.ButtonURL(index).c_str());
			}
		}
		else if (_strnicmp(szArg1, "custom", 6) == 0)
		{
			// Extract index from "customXX" (starts at index 6, length 2)
			int displayNum = std::atoi(szArg1 + 6);
			int index = displayNum - 1;

			if (index >= 0 && index < MAX_CUSTOM_BUTTONS) // Safety bounds check for Custom buttons
			{
				s_settings.SetCustButtonAction(index, szArg2);
				s_settings.SetCustButtonName(index, szArg3);
				if (bToggle)
					s_settings.SetCustPickupItemEnabled(index, bOn);

				WriteChatf("Custom button %02d \"\ay%s\ax\" action is now: \ay%s\ax", displayNum, s_settings.CustButtonName(index).c_str(), s_settings.CustButtonAction(index).c_str());

				if (bToggle)
				{
					WriteChatf("Custom button %02d Pickup Item is now: \ay%s\ax", displayNum, (s_settings.IsCustPickupItemEnabled(index) ? "\agEnabled\ax" : "\arDisabled\ax"));
				}
			}
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

	ImGui::NewLine();
	ImGui::Text("URL Buttons");
	ImGui::SameLine();

	int urlButtonCount = s_settings.GetCustomURLCount();
	if (ImGui::SliderInt("##UrlButtonCount", &urlButtonCount, 0, MAX_CUSTOM_BUTTONS))
	{
		s_settings.SetCustomURLCount(urlButtonCount);
	}
	ImGui::Separator();

	struct ButtonCache {
		std::string name;
		std::string action;
	};
	static std::vector<ButtonCache> urlButtons;

	urlButtons.resize(urlButtonCount);
	for (int i = 0; i < urlButtonCount; ++i)
	{
		// 1. Isolate IDs for each URL row to prevent ImGui conflicts
		ImGui::PushID(i + 1000);

		// 2. Render row label
		ImGui::Text("%d. Name", i + 1);
		ImGui::SameLine();

		// 3. URL Name Input Field
		ImGui::SetNextItemWidth(80.f);
		urlButtons[i].name = s_settings.ButtonName(i);
		std::string urlNameLabel = "URL##URLName" + std::to_string(i);

		if (ImGui::InputTextWithHint(urlNameLabel.c_str(), s_settings.default_customURL[i].name.c_str(), & urlButtons[i].name))
		{
			s_settings.SetButtonName(i, urlButtons[i].name);
		}
		ImGui::SameLine();

		// 4. URL Path Input Field
		ImGui::SetNextItemWidth(-120.f);
		urlButtons[i].action = s_settings.ButtonURL(i);
		std::string urlPathLabel = "##URL" + std::to_string(i);

		if (ImGui::InputTextWithHint(urlPathLabel.c_str(), s_settings.default_customURL[i].action.c_str(), &urlButtons[i].action))
		{
			s_settings.SetButtonURL(i, urlButtons[i].action);
		}

		ImGui::PopID();
	}


	ImGui::NewLine();
	ImGui::Text("Custom Buttons");
	ImGui::SameLine();
	int customButtonCount = s_settings.GetCustomButtonCount();
	if (ImGui::SliderInt("##CustomButtonCount", &customButtonCount, 0, MAX_CUSTOM_BUTTONS))
	{
		s_settings.SetCustomButtonCount(customButtonCount);
	}
	ImGui::Separator();
	static std::vector<ButtonCache> customButtons;

	customButtonCount = s_settings.GetCustomButtonCount();
	customButtons.resize(customButtonCount);
	for (int i = 0; i < customButtonCount; ++i)
	{
		// 1. Isolate IDs for each row to prevent ImGui widget conflicts
		ImGui::PushID(i + 2000);

		// 2. Render row label (1-indexed for the user)
		ImGui::Text("%d. Name", i + 1);
		ImGui::SameLine();

		// 3. Name Input Field
		ImGui::SetNextItemWidth(80.f);
		customButtons[i].name = s_settings.CustButtonName(i);
		// Unique runtime label via ## suffix
		std::string nameLabel = "Action##Name" + std::to_string(i);

		if (ImGui::InputTextWithHint(nameLabel.c_str(), s_settings.default_customButton[i].name.c_str(), &customButtons[i].name))
		{
			s_settings.SetCustButtonName(i, customButtons[i].name);
		}
		ImGui::SameLine();

		// 4. Action Input Field
		ImGui::SetNextItemWidth(-120.f);
		customButtons[i].action = s_settings.CustButtonAction(i);

		if (ImGui::InputText("##Action", &customButtons[i].action))
		{
			s_settings.SetCustButtonAction(i, customButtons[i].action);
		}
		ImGui::SameLine();

		// 5. Pickup Checkbox
		bool showPickupItem = s_settings.IsCustPickupItemEnabled(i);
		// Unique runtime label via ## suffix
		std::string checkboxLabel = "Pickup##" + std::to_string(i);

		if (ImGui::Checkbox(checkboxLabel.c_str(), &showPickupItem))
		{
			s_settings.SetCustPickupItemEnabled(i, showPickupItem);
		}

		ImGui::PopID();
	}


	// If settings reloaded/reset elsewhere, refresh ImGui static buffers
	if (s_settingsChangedForImGui)
	{
		for (int i = 0; i < urlButtonCount; ++i)
		{
			urlButtons[i].name = s_settings.ButtonName(i);
			urlButtons[i].action = s_settings.ButtonURL(i);
		}

		for (int i = 0; i < customButtonCount; ++i)
		{
			customButtons[i].name = s_settings.CustButtonName(i);
			customButtons[i].action = s_settings.CustButtonAction(i);
		}

		s_settingsChangedForImGui = false;
	}

	ImGui::Text("Custom variables: %%name%% %%id%% %%count%%");

	ImGui::NewLine();
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
			if (ImGui::Button("Reset##ItemText"))
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

			if (ImGui::Button("Reset##SpellText"))
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

		if (customColor.has_value() && customColor.value() != color)
		{
			ImGui::SameLine();
			ImGui::SetNextItemWidth(20.f);
			if (ImGui::Button("Reset##SpellColor"))
			{
				s_settings.ResetItemSpellColor(config.effectType);
			}
		}

		ImGui::PopID();
	}

	ImGui::NewLine();
	ImGui::Text("Information Window Size and Locations");
	ImGui::Separator();

	bool persistWindowBounds = s_settings.PersistWindowBounds();
	if (ImGui::Checkbox("Persist Window Bounds", &persistWindowBounds))
	{
		s_settings.SetPersistWindowBounds(persistWindowBounds);
	}
	if (persistWindowBounds)
	{
		ImGui::Columns(2, "##WindowSizeColumns", false);

		ImGui::SetNextItemWidth(120.f);
		int windowX = s_settings.GetWindowX();
		if (ImGui::InputInt("Left", &windowX))
		{
			s_settings.SetWindowX(windowX);
		}

		ImGui::SetNextItemWidth(120.f);
		int windowY = s_settings.GetWindowY();
		if (ImGui::InputInt("Top", &windowY))
		{
			s_settings.SetWindowY(windowY);
		}

		ImGui::NextColumn();

		ImGui::SetNextItemWidth(120.f);
		int windowWidth = s_settings.GetWindowWidth();
		if (ImGui::InputInt("Width", &windowWidth))
		{
			s_settings.SetWindowWidth(windowWidth);
		}
		ImGui::SetNextItemWidth(120.f);
		int windowHeight = s_settings.GetWindowHeight();
		if (ImGui::InputInt("Height", &windowHeight))
		{
			s_settings.SetWindowHeight(windowHeight);
		}

		ImGui::Columns(1);
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
	EzDetour(CSpellDisplayWnd__SetSpell, &SpellDisplayHook::SetSpell_Detour, &SpellDisplayHook::SetSpell_Trampoline);
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
	RemoveDetour(CSpellDisplayWnd__SetSpell);

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
	s_inOnCleanUI = true;

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

	s_inOnCleanUI = false;
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
