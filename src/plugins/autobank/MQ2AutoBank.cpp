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

PreSetup("MQ2AutoBank");
PLUGIN_VERSION(0.1);

static std::list<ItemGlobalIndex> gAutoBankList;
static std::list<ItemGlobalIndex> gAutoInventoryList;
static bool gbStartAutoBanking = false;
static bool gbAutoBankInProgress = false;
static bool gbAutoInventoryInProgress = false;
static bool gbAutoBankTradeSkillItems = false;
static bool gbAutoBankTrophiesWithTradeskill = true;
static bool gbAutoBankCollectibleItems = false;
static bool gbAutoBankQuestItems = false;
static bool gbAutoInventoryItems = false;

static CContextMenu* AutoBankMenu = nullptr;
static CButtonWnd* gAutoBankButton = nullptr;
static int s_bankCustomMenu = 0;

// BankWnd context menu items
constexpr int ContextMenu_TradeskillItemsId = 50;
constexpr int ContextMenu_CollectibleItemsId = 51;
constexpr int ContextMenu_QuestItemsId = 52;
constexpr int ContextMenu_CheckedItemsId = 53;
constexpr int ContextMenu_TrophysId = 54;

namespace AutoBank
{
	class BankWnd_Hook;
}

// CBankWnd hooks
class AutoBank::BankWnd_Hook
{
public:
	DETOUR_TRAMPOLINE_DEF(int, WndNotification_Trampoline, (CXWnd*, uint32_t, void*));
	int WndNotification_Detour(CXWnd* pWnd, uint32_t uiMessage, void* pData)
	{
		CBankWnd* pThis = reinterpret_cast<CBankWnd*>(this);
		PcProfile* pProfile = GetPcProfile();

		// we use this to intercept the menu messages for our autobank button extension
		if (pThis->AutoButton == pWnd)
		{
			if (gAutoBankButton != pWnd)
				gAutoBankButton = static_cast<CButtonWnd*>(pWnd);

			if (gAutoBankButton)
			{
				switch (uiMessage)
				{
				case XWM_LCLICK:
					if (!pProfile->GetInventorySlot(InvSlot_Cursor))
					{
						if (!gbAutoBankTradeSkillItems && !gbAutoBankCollectibleItems && !gbAutoBankQuestItems)
						{
							gAutoBankButton->bChecked = false;
						}
						else
						{
							gAutoBankButton->bChecked = true;
						}
					}
					break;

				case XWM_LMOUSEUP:
					if (!pProfile->GetInventorySlot(InvSlot_Cursor))
					{
						if (!gbAutoBankTradeSkillItems && !gbAutoBankCollectibleItems && !gbAutoBankQuestItems)
						{
							WriteChatf("\ay[AUTOBANK FILTER NOT CONFIGURED]\ax AutoBank Filters where empty there is nothing selected for moving, rightclick the autobank button to select filters.\n");
							gAutoBankButton->bChecked = false;
							break;
						}

						if (!gbStartAutoBanking)
						{
							// user leftclicked the autobank button and nothing on cursor
							// we will autobank from inventory instead and pick items he wants
							// by using his menu settings.
							gbStartAutoBanking = true;

							WriteChatf("\ay[Auto%s started. Please wait...]\ax",
								gbAutoInventoryItems ? "Inventory" : "Bank");
						}
						else
						{
							WriteChatf("\ar[Auto%s ALREADY in Progress, please wait for it to finish...]\ax",
								gbAutoInventoryItems ? "Inventory" : "Bank");
							return 0;
						}
					}
					break;

				case XWM_RCLICK:
					if (pContextMenuManager)
					{
						CXPoint Loc = pWndMgr->MousePoint;

						// work in progress
						pContextMenuManager->PopupMenu(s_bankCustomMenu, Loc, pThis);
					}
					break;

				default: break;
				}
			}
		}
		else if (uiMessage == XWM_MENUSELECT)
		{
			CContextMenu* pContextMenu = static_cast<CContextMenu*>(pWnd);
			int ItemID = static_cast<int>(reinterpret_cast<intptr_t>(pData));

			int iItemID = pContextMenu->GetItemAtPoint(pWndMgr->MousePoint);

			switch (ItemID)
			{
			case ContextMenu_TradeskillItemsId:
				gbAutoBankTradeSkillItems = !gbAutoBankTradeSkillItems;
				WritePrivateProfileBool("AutoBank", "AutoBankTradeSkillItems", gbAutoBankTradeSkillItems, gPathConfig);

				AutoBankMenu->CheckMenuItem(iItemID, gbAutoBankTradeSkillItems);
				break;

			case ContextMenu_CollectibleItemsId:
				gbAutoBankCollectibleItems = !gbAutoBankCollectibleItems;
				WritePrivateProfileBool("AutoBank", "AutoBankCollectibleItems", gbAutoBankCollectibleItems, gPathConfig);

				AutoBankMenu->CheckMenuItem(iItemID, gbAutoBankCollectibleItems);
				break;

			case ContextMenu_QuestItemsId:
				gbAutoBankQuestItems = !gbAutoBankQuestItems;
				WritePrivateProfileBool("AutoBank", "AutoBankQuestItems", gbAutoBankQuestItems, gPathConfig);

				AutoBankMenu->CheckMenuItem(iItemID, gbAutoBankQuestItems);
				break;

			case ContextMenu_CheckedItemsId:
				gbAutoInventoryItems = !gbAutoInventoryItems;
				WritePrivateProfileBool("AutoBank", "AutoInventoryItems", gbAutoInventoryItems, gPathConfig);

				AutoBankMenu->CheckMenuItem(iItemID, gbAutoInventoryItems);
				break;
			case ContextMenu_TrophysId:
				gbAutoBankTrophiesWithTradeskill = !gbAutoBankTrophiesWithTradeskill;
				WritePrivateProfileBool("AutoBank", "AutoBankTrophiesWithTradeskill", gbAutoBankTrophiesWithTradeskill, gPathConfig);

				AutoBankMenu->CheckMenuItem(iItemID, gbAutoBankTrophiesWithTradeskill);
				break;

			default: break;
			}
		}

		return WndNotification_Trampoline(pWnd, uiMessage, pData);
	}
};

static void AddAutoBankMenu()
{
	if (s_bankCustomMenu == 0)
	{
		if (pContextMenuManager)
		{
			// save orig values
			int DefaultMenuIndex = pContextMenuManager->DefaultMenuIndex;
			int DefaultBGItem = pContextMenuManager->DefaultBGItem;
			int DefaultHelpItem = pContextMenuManager->DefaultHelpItem;
			int DefaultLockItem = pContextMenuManager->DefaultLockItem;
			int DefaultEscapeItem = pContextMenuManager->DefaultEscapeItem;
			int DefaultMinItem = pContextMenuManager->DefaultMinItem;
			int DefaultCloseItem = pContextMenuManager->DefaultCloseItem;

			// create our menu
			pContextMenuManager->CreateDefaultMenu();  // FIXME: Don't rely on CreateDefaultMenu

			// set our values
			s_bankCustomMenu = pContextMenuManager->DefaultMenuIndex;

			// set orig values back, we now have a menu that's ours...
			pContextMenuManager->DefaultMenuIndex = DefaultMenuIndex;
			pContextMenuManager->DefaultBGItem = DefaultBGItem;
			pContextMenuManager->DefaultHelpItem = DefaultHelpItem;
			pContextMenuManager->DefaultLockItem = DefaultLockItem;
			pContextMenuManager->DefaultEscapeItem = DefaultEscapeItem;
			pContextMenuManager->DefaultMinItem = DefaultMinItem;
			pContextMenuManager->DefaultCloseItem = DefaultCloseItem;

			AutoBankMenu = pContextMenuManager->GetMenu(s_bankCustomMenu);
			AutoBankMenu->RemoveAllMenuItems();

			gbAutoBankTradeSkillItems = GetPrivateProfileBool("AutoBank", "AutoBankTradeSkillItems", false, gPathConfig);
			gbAutoBankTrophiesWithTradeskill = GetPrivateProfileBool("AutoBank", "AutoBankTrophiesWithTradeskill", true, gPathConfig);
			gbAutoBankCollectibleItems = GetPrivateProfileBool("AutoBank", "AutoBankCollectibleItems", false, gPathConfig);
			gbAutoBankQuestItems = GetPrivateProfileInt("AutoBank", "AutoBankQuestItems", false, gPathConfig);
			gbAutoInventoryItems = GetPrivateProfileInt("AutoBank", "AutoInventoryItems", false, gPathConfig);

			if (gbWriteAllConfig)
			{
				WritePrivateProfileBool("AutoBank", "AutoBankTradeSkillItems", gbAutoBankTradeSkillItems, gPathConfig);
				WritePrivateProfileBool("AutoBank", "AutoBankTrophiesWithTradeskill", gbAutoBankTrophiesWithTradeskill, gPathConfig);
				WritePrivateProfileBool("AutoBank", "AutoBankCollectibleItems", gbAutoBankCollectibleItems, gPathConfig);
				WritePrivateProfileBool("AutoBank", "AutoBankQuestItems", gbAutoBankQuestItems, gPathConfig);
				WritePrivateProfileBool("AutoBank", "AutoInventoryItems", gbAutoInventoryItems, gPathConfig);
			}

			AutoBankMenu->AddMenuItem("Tradeskill Items", ContextMenu_TradeskillItemsId, gbAutoBankTradeSkillItems);
			AutoBankMenu->AddMenuItem("Move mod items (trophies) with tradeskill items", ContextMenu_TrophysId, gbAutoBankTrophiesWithTradeskill);
			AutoBankMenu->AddMenuItem("Collectible Items", ContextMenu_CollectibleItemsId, gbAutoBankCollectibleItems);
			AutoBankMenu->AddMenuItem("Quest Items", ContextMenu_QuestItemsId, gbAutoBankQuestItems);
			AutoBankMenu->AddSeparator();
			AutoBankMenu->AddMenuItem("AutoInventory Checked Items", ContextMenu_CheckedItemsId, gbAutoInventoryItems);
		}
	}
}

void RemoveAutoBankMenu()//This was empty for autobank??
{
	if (s_bankCustomMenu != 0)
	{
		pContextMenuManager->RemoveMenu(s_bankCustomMenu, true);
		s_bankCustomMenu = 0;
	}
}

static void AutoBankPulse()
{
	if (!pLocalPC)
		return;

	PcProfile* pProfile = GetPcProfile();

	if (!gbStartAutoBanking)
	{
		return;
	}

	if (!pBankWnd || (pBankWnd && pBankWnd->IsVisible() == 0))
	{
		gbStartAutoBanking = false;
		gbAutoBankInProgress = false;
		gbAutoInventoryInProgress = false;

		if (gAutoBankButton && gAutoBankButton->bChecked)
			gAutoBankButton->bChecked = false;

		gAutoBankList.clear();
		gAutoInventoryList.clear();
		return;
	}

	if (gbAutoInventoryItems && !gbAutoInventoryInProgress)
	{
		// user wants us to move items FROM bank back to their inventory

		if (gAutoInventoryList.empty() && (gbAutoBankTradeSkillItems || gbAutoBankCollectibleItems || gbAutoBankQuestItems))
		{
			pLocalPC->BankItems.VisitContainers(
				[&](const ItemPtr& pItem, const ItemIndex& index)
				{
					UNUSED(index);

					// don't add bags that have items inside of them.
					if (pItem->IsContainer() && !pItem->IsEmpty())
						return;

					ItemDefinition* itemDef = pItem->GetItemDefinition();
					if ((gbAutoBankTradeSkillItems && itemDef->TradeSkills && (!itemDef->SkillModValue || gbAutoBankTrophiesWithTradeskill))
						|| (gbAutoBankCollectibleItems && itemDef->Collectible)
						|| (gbAutoBankQuestItems && itemDef->QuestItem))
					{
						gAutoInventoryList.push_back(pItem->GetItemLocation());
					}
				});
		}

		if (!gAutoInventoryList.empty())
		{
			gbAutoInventoryInProgress = true;
		}
		else
		{
			gbStartAutoBanking = false;
			gbAutoInventoryInProgress = false;

			if (gAutoBankButton && gAutoBankButton->bChecked)
				gAutoBankButton->bChecked = false;

			WriteChatf("\ay[No Items Found for Auto Inventory.]\ax\n");
			return;
		}
	} // user wants us to autobank stuff
	else if (!gbAutoInventoryItems && !gbAutoBankInProgress)
	{
		if (gAutoBankList.empty() && (gbAutoBankTradeSkillItems || gbAutoBankCollectibleItems || gbAutoBankQuestItems))
		{
			// check toplevel slots
			pProfile->GetInventory().VisitContainers(
				[&](const ItemPtr& pItem, const ItemIndex& index)
				{
					if (pItem->IsContainer() && !pItem->IsEmpty())
						return;

					ItemDefinition* itemDef = pItem->GetItemDefinition();
					if ((gbAutoBankTradeSkillItems && itemDef->TradeSkills && (!itemDef->SkillModValue || gbAutoBankTrophiesWithTradeskill))
						|| (gbAutoBankCollectibleItems && itemDef->Collectible)
						|| (gbAutoBankQuestItems && itemDef->QuestItem))
					{
						gAutoBankList.push_back(pItem->GetItemLocation());
					}
				});
		}

		if (!gAutoBankList.empty())
		{
			gbAutoBankInProgress = true;
		}
		else
		{
			gbStartAutoBanking = false;
			gbAutoBankInProgress = false;

			if (gAutoBankButton && gAutoBankButton->bChecked)
				gAutoBankButton->bChecked = false;

			WriteChatf("\ay[No Items Found for Auto Banking.]\ax\n");
			return;
		}
	}

	if (pProfile->GetInventorySlot(InvSlot_Cursor) != nullptr)
	{
		if (gbAutoInventoryInProgress)
			DoCommandf("/autoinventory");
		else
			DoCommandf("/autobank");
		return;
	}

	if (!gAutoInventoryList.empty())
	{
		const ItemGlobalIndex& ind = gAutoInventoryList.front();

		if (ItemClient* pItem = FindItemByGlobalIndex(ind))
		{
			ItemGlobalIndex indy = pItem->GetItemLocation();

			if (WillFitInInventory(pItem))
			{
				WriteChatf("[%d] Moving %s from slot %d %d to inventory",
					gAutoInventoryList.size(), pItem->GetName(), indy.GetIndex().GetSlot(0), indy.GetIndex().GetSlot(1));

				PickupItem(pItem->GetItemLocation());
			}
			else
			{
				WriteChatf("[%d] \arAutoinventory for %s from slot %d %d to inventory \ayFAILED\ar, you are out of space.\ax",
					gAutoInventoryList.size(), pItem->GetName(), indy.GetIndex().GetSlot(0), indy.GetIndex().GetSlot(1));
			}
		}
		else
		{
			WriteChatf("[%d] \arAutoinventory for slot %d %d to inventory \ayFAILED\ar, no item was found.\ax",
				gAutoInventoryList.size(), ind.GetIndex().GetSlot(0), ind.GetIndex().GetSlot(1));
		}

		gAutoInventoryList.pop_front();
		return;
	}

	if (!gAutoBankList.empty())
	{
		const ItemGlobalIndex& ind = gAutoBankList.front();

		if (ItemClient* pCont = FindItemByGlobalIndex(ind))
		{
			ItemDefinition* pItem = GetItemFromContents(pCont);
			ItemGlobalIndex indy = pCont->GetItemLocation();

			if (WillFitInBank(pCont))
			{
				WriteChatf("[%d] Moving %s from slot %d %d to bank",
					gAutoBankList.size(), pItem->Name, indy.GetIndex().GetSlot(0), indy.GetIndex().GetSlot(1));

				PickupItem(indy.Location, pCont);
			}
			else
			{
				WriteChatf("[%d] \arAutoBank for %s from slot %d %d to bank \ayFAILED\ar, you are out of space.\ax",
					gAutoBankList.size(), pItem->Name, indy.GetIndex().GetSlot(0), indy.GetIndex().GetSlot(1));
			}
		}
		else
		{
			WriteChatf("[%d] \arAutoBank for slot %d %d to bank \ayFAILED\ar, no item was found.\ax",
				gAutoBankList.size(), ind.GetIndex().GetSlot(0), ind.GetIndex().GetSlot(1));
		}

		gAutoBankList.pop_front();
		return;
	}

	if (gbAutoInventoryInProgress)
	{
		if (gAutoBankButton && gAutoBankButton->bChecked)
			gAutoBankButton->bChecked = false;

		gbAutoInventoryInProgress = false;
		gbStartAutoBanking = false;
		WriteChatf("\ay[Autoinventory Finished.]\ax");
	}
	else if (gbAutoBankInProgress)
	{
		if (gAutoBankButton && gAutoBankButton->bChecked)
			gAutoBankButton->bChecked = false;

		gbAutoBankInProgress = false;
		gbStartAutoBanking = false;
		WriteChatf("\ay[AutoBank Finished.]\ax");
	}
}

PLUGIN_API void InitializePlugin()
{
	DebugSpewAlways("MQ2AutoBank::Initializing version %f", MQ2Version);
	EzDetour(CBankWnd__WndNotification,
		&AutoBank::BankWnd_Hook::WndNotification_Detour,
		&AutoBank::BankWnd_Hook::WndNotification_Trampoline);
}

PLUGIN_API void ShutdownPlugin()
{
	DebugSpewAlways("MQ2AutoBank::Shutting down");
	RemoveDetour(CBankWnd__WndNotification);
	RemoveAutoBankMenu();
}

PLUGIN_API void OnCleanUI()
{
	RemoveAutoBankMenu();
}

PLUGIN_API void OnPulse()
{
	if (gGameState != GAMESTATE_INGAME)
		return;

	AddAutoBankMenu();
	AutoBankPulse();
}

/* Leaving for future expansion of plugin.
PLUGIN_API void OnUpdateImGui()
{
	if (GetGameState() == GAMESTATE_INGAME)
	{
		if (ShowMQ2AutoBankWindow)
		{
			if (ImGui::Begin("MQ2AutoBank", &ShowMQ2AutoBankWindow, ImGuiWindowFlags_MenuBar))
			{
				if (ImGui::BeginMenuBar())
				{
					ImGui::Text("MQ2AutoBank is loaded!");
					ImGui::EndMenuBar();
				}
			}
			ImGui::End();
		}
	}
}*/