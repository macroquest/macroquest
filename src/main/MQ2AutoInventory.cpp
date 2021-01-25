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

#include "pch.h"
#include "MQ2Main.h"

#include <algorithm>
#include <list>
#include <map>
#include <string>

namespace mq {

static std::list<ItemGlobalIndex> gSellList;
static std::list<ItemGlobalIndex> gDeleteList;
static std::list<ItemGlobalIndex> gAutoBankList;
static std::list<ItemGlobalIndex> gAutoInventoryList;
bool gbStartAutoBanking = false;
bool gbStartDeleting = false;
bool gbStartSelling = false;
bool gbAutoBankInProgress = false;
bool gbAutoInventoryInProgress = false;
bool gbAutoBankTradeSkillItems = false;
bool gbCheckBoxFeatureEnabled = true;
bool gbColorsFeatureEnabled = true;
bool gbAutoBankCollectibleItems = false;
bool gbAutoBankQuestItems = false;
bool gbAutoInventoryItems = false;
CContextMenu* AutoBankMenu = nullptr;
CContextMenu* CheckBoxMenu = nullptr;
int CoolCheckBoxoptionID = 0;
int CoolColorsoptionID = 0;
int tradeskilloptionID = 0;
int collectibleoptionID = 0;
int questoptionID = 0;
int separatoroptionID = 0;
int autoinventoryoptionID = 0;
int OurCheckBoxMenuIndex = 0;
int OurDefaultMenuIndex = 0;
int OurDefaultBGItem = 0;
int OurDefaultHelpItem = 0;
int OurDefaultLockItem = 0;
int OurDefaultEscapeItem = 0;
int OurDefaultMinItem = 0;
int OurDefaultCloseItem = 0;

CTextureAnimation* pChecked = nullptr;
CTextureAnimation* pUnChecked = nullptr;
CButtonWnd* gAutoBankButton = nullptr;
CButtonWnd* pNLMarkedButton = nullptr;
CLabelWnd* pCountLabel = nullptr;

// BankWnd context menu items
constexpr int ContextMenu_TradeskillItemsId = 50;
constexpr int ContextMenu_CollectibleItemsId = 51;
constexpr int ContextMenu_QuestItemsId = 52;
constexpr int ContextMenu_CheckedItemsId = 53;

// CFindItemWnd context menu items
constexpr int ContextMenu_CheckboxFeatureEnabled = 50;
constexpr int ContextMenu_ColorsFeatureEnabled = 51;

// CFindItemWnd columns
constexpr int Column_CheckBox = 6;
constexpr int Column_Value = 7;

// TODO: We should really be using these instead of the constants above. These have the
// dynamically assigned column ids when the columns are added.
int MarkCol = 0;
int ValueCol = 0;

int lastsel = -1;
CCheckBoxWnd* pCheck = nullptr;
bool bChangedNL = false;
ULONGLONG SellTimer = 0;

static int GetMoneyFromString(const char* str)
{
	char szLabel1[50];
	strcpy_s(szLabel1, str);

	int pp = 0;
	int gp = 0;
	int sp = 0;
	int cp = 0;

	if (char* pDest = strstr(szLabel1, "pp"))
	{
		pDest[0] = '\0';
		pp = GetIntFromString(szLabel1, pp);
		strcpy_s(szLabel1, &pDest[2]);
	}

	if (char* pDest = strstr(szLabel1, "gp"))
	{
		pDest[0] = '\0';
		gp = GetIntFromString(szLabel1, gp);
		strcpy_s(szLabel1, &pDest[2]);
	}

	if (char* pDest = strstr(szLabel1, "sp"))
	{
		pDest[0] = '\0';
		sp = GetIntFromString(szLabel1, sp);
		strcpy_s(szLabel1, &pDest[2]);
	}

	if (char* pDest = strstr(szLabel1, "cp"))
	{
		pDest[0] = '\0';
		cp = GetIntFromString(szLabel1, cp);
		strcpy_s(szLabel1, &pDest[2]);
	}

	int total = (pp * 1000) + (gp * 100) + (sp * 10) + cp;
	return total;
}

// CFindItemWnd hooks
class AutoInventory_FindItemWnd_Hook
{
public:
	void Update_Detour()
	{
		CFindItemWnd* pFIWnd = (CFindItemWnd*)this;
		Update_Trampoline();

		CListWnd* list = (CListWnd*)pFIWnd->GetChildItem("FIW_ItemList");
		if (gbCheckBoxFeatureEnabled && list)
		{
			if (MarkCol && list->Columns.Count > MarkCol)
			{
				char szTemp[20];
				sprintf_s(szTemp, "0/%d", list->ItemsArray.Count);
				pCountLabel->SetWindowText(szTemp);

				// we really need the list to fit to the window so people can actually see this new feature.
				CXRect rectmain = pFIWnd->GetClientRect();
				CXRect rect = list->GetClientRect();
				int TotalWidth = 0;

				for (int i = 0; i < list->Columns.Count; i++)
				{
					TotalWidth += list->Columns[i].Width;
				}
				TotalWidth += 20;

				int mainwidth = rectmain.right - rectmain.left;
				int newwidth = 0;

				if (TotalWidth > rect.right - rect.left)
				{
					newwidth = TotalWidth - (rect.right - rect.left);
					rect.right += newwidth;
					rectmain.right += newwidth + 10;
					list->Move(rect, false, false, false, false);
					pFIWnd->Move(rectmain, false, false, false, false);
				}

				// lets borrow a checkbox...
				CControlTemplate* pDisableConnectionTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("ATW_Checkbox");
				if (pDisableConnectionTemplate)
				{
					CXRect OldRect = pDisableConnectionTemplate->rect;
					CXStr OldName1 = pDisableConnectionTemplate->strName;
					CXStr OldScreenName1 = pDisableConnectionTemplate->strScreenId;
					CXStr OldController1 = pDisableConnectionTemplate->strController;

					pDisableConnectionTemplate->strController = "0";

					char szTemp2[256];
					char szTemp3[256];

					for (int i = 0; i < list->ItemsArray.Count && i < 900; i++)
					{
						sprintf_s(szTemp2, "FIW_CheckBox_%d", i);
						pDisableConnectionTemplate->strName = szTemp2;
						pDisableConnectionTemplate->strScreenId = szTemp2;

						if (pCheck = (CCheckBoxWnd*)pSidlMgr->CreateXWndFromTemplate(pFIWnd, pDisableConnectionTemplate))
						{
							pCheck->SetEnabled(true);
							pCheck->SetCheck(false);
							pCheck->SetData(list->GetItemData(i));
							pCheck->SetVisible(true);
							pCheck->SetActive(true);
							pCheck->SetClickThroughMenuItemStatus(true);
							pCheck->pController = nullptr;
							pCheck->SetShowClickThroughMenuItem(true);
							pCheck->SetLocation({ 4, 0, 16, 12 });
							pCheck->IndicatorVal = 0;

							// todo: check this
							CXStr Str = list->GetItemText(i, 1);
							strcpy_s(szTemp2, Str.c_str());
							sprintf_s(szTemp3, "Check to mark %s for Action. (%d)", szTemp2, i);
							pCheck->SetTooltip(szTemp3);

							list->SetItemWnd(i, MarkCol, pCheck);

							if (ItemGlobalIndex* gi = (ItemGlobalIndex*)pFIWnd->gi[(int)pCheck->GetData()])
							{
								if (ItemPtr ptr = pCharData->GetItemByGlobalIndex(*gi))
								{
									ItemDefinition* pItem = ptr->GetItemDefinition();
									if (gbColorsFeatureEnabled)
									{
										if (pItem->TradeSkills)
										{
											list->SetItemColor(i, 1, 0xFFFF00FF);
										}
										if (pItem->QuestItem)
										{
											list->SetItemColor(i, 1, 0xFFFFFF00);
										}
									}

									szTemp3[0] = 0;

									if (pItem->Cost > 0)
									{
										int sellprice = ptr->ValueSellMerchant(1.05f, 1);
										int cp = sellprice;
										int sp = cp / 10; cp = cp % 10;
										int gp = sp / 10; sp = sp % 10;
										int pp = gp / 10; gp = gp % 10;

										if (pp > 0)
										{
											sprintf_s(szTemp2, " %dpp", pp);
											strcat_s(szTemp3, szTemp2);
										}
										if (gp > 0)
										{
											sprintf_s(szTemp2, " %dgp", gp);
											strcat_s(szTemp3, szTemp2);
										}
										if (sp > 0)
										{
											sprintf_s(szTemp2, " %dsp", sp);
											strcat_s(szTemp3, szTemp2);
										}
										if (cp > 0)
										{
											sprintf_s(szTemp2, " %dcp", cp);
											strcat_s(szTemp3, szTemp2);
										}
									}

									list->SetItemText(i, ValueCol, szTemp3);
								}
							}
						}
					}

					pDisableConnectionTemplate->rect = OldRect;
					pDisableConnectionTemplate->strName = OldName1;
					pDisableConnectionTemplate->strScreenId = OldScreenName1;
					pDisableConnectionTemplate->strController = OldController1;

					if (list->SortCol == Column_Value)
					{
						list->Sort();
					}
				}
			}
		}
	}
	void Update_Trampoline();

	int WndNotification_Detour(CXWnd* pWnd, uint32_t uiMessage, void* pData)
	{
		CFindItemWnd* pThis = (CFindItemWnd*)this;
		PcProfile* pProfile = GetPcProfile();
		if (!pProfile)
			return WndNotification_Trampoline(pWnd, uiMessage, pData);;

		if (uiMessage == XWM_SORTREQUEST)
		{
			if (pWnd == pThis->FIW_ItemList)
			{
				if (SListWndSortInfo* pSI = (SListWndSortInfo*)pData)
				{
					if (pSI->SortCol == Column_Value)
					{
						int int1 = GetMoneyFromString(pSI->StrLabel1.c_str());
						int int2 = GetMoneyFromString(pSI->StrLabel2.c_str());

						if (int1 > int2)
							pSI->SortResult = -1;
						else if (int1 < int2)
							pSI->SortResult = 1;
						else
							pSI->SortResult = 0;

						return 0;
					}
				}
			}
		}
		else if (uiMessage == XWM_MENUSELECT)
		{
			int ItemID = (int)pData;
			int iItemID = 0;

			if (CContextMenu* pContextMenu = (CContextMenu*)pWnd)
			{
				CXPoint pt = pWndMgr->MousePoint;
				iItemID = pContextMenu->GetItemAtPoint(pt);
			}

			switch (ItemID)
			{
			case ContextMenu_CheckboxFeatureEnabled:
				if (gbCheckBoxFeatureEnabled)
				{
					gbCheckBoxFeatureEnabled = false;

					if (pNLMarkedButton)
						pNLMarkedButton->SetVisible(false);
					if (pCountLabel)
						pCountLabel->SetVisible(false);

					if (CListWnd* list = (CListWnd*)pThis->GetChildItem("FIW_ItemList"))
					{
						list->Selected = 0xFF004040;
					}
				}
				else
				{
					gbCheckBoxFeatureEnabled = true;

					if (pNLMarkedButton)
						pNLMarkedButton->SetVisible(true);
					if (pCountLabel)
						pCountLabel->SetVisible(true);

					if (CListWnd* list = (CListWnd*)pThis->GetChildItem("FIW_ItemList"))
					{
						if (list->Columns.Count > Column_CheckBox)
						{
							if (SListWndColumn* col = &list->Columns[Column_CheckBox])
							{
								col->pTextureAnim = pUnChecked;
							}
						}
					}
				}

				WritePrivateProfileBool("CoolBoxes", "CheckBoxFeatureEnabled", gbCheckBoxFeatureEnabled, mq::internal_paths::MQini);

				CheckBoxMenu->CheckMenuItem(iItemID, gbCheckBoxFeatureEnabled);
				pFindItemWnd->Update();
				break;

			case ContextMenu_ColorsFeatureEnabled:
				gbColorsFeatureEnabled = !gbColorsFeatureEnabled;
				WritePrivateProfileBool("CoolBoxes", "ColorsFeatureEnabled", gbColorsFeatureEnabled, mq::internal_paths::MQini);

				CheckBoxMenu->CheckMenuItem(iItemID, gbColorsFeatureEnabled);
				pFindItemWnd->Update();
				break;
			}
		}
		else if (uiMessage == XWM_RCLICK)
		{
			if (CButtonWnd* FIW_DestroyItem = (CButtonWnd*)pThis->GetChildItem("FIW_DestroyItem"))
			{
				if (pWnd == FIW_DestroyItem || pWnd == pNLMarkedButton || pWnd == pCountLabel)
				{
					if (pContextMenuManager)
					{
						CXPoint Loc = pWndMgr->MousePoint;

						// work in progress -eqmule
						pContextMenuManager->PopupMenu(OurCheckBoxMenuIndex, Loc, pThis);
					}

					return 0;
				}
			}
		}
		else if (gbCheckBoxFeatureEnabled)
		{
			if (uiMessage == XWM_LCLICK)
			{
				// for our checkboxes, they should parent notify to this func...
				int itemclicked = (int)pData;
				if (CListWnd* list = (CListWnd*)pThis->GetChildItem("FIW_ItemList"))
				{
					CXMLData* data = pWnd->GetXMLData();
					if (list->Columns.Count > Column_CheckBox)
					{
						SListWndColumn* col = &list->Columns[Column_CheckBox];

						if (bool bCheckBox = pWnd->IsType(WRT_CHECKBOXWND))
						{
							bool bChecked = ((CCheckBoxWnd*)pWnd)->bChecked;
							int Selected = 0;
							int Checked = 0;

							for (int i = 0; i < list->ItemsArray.Count; i++)
							{
								if (CButtonWnd* button = (CButtonWnd*)list->GetItemWnd(i, Column_CheckBox))
								{
									if (button->bChecked)
										Checked++;

									if (button == pWnd)
									{
										list->ItemsArray[i].bSelected = bChecked;

										if (bChecked)
										{
											col->pTextureAnim = pChecked;
											list->CurSel = i;
											list->Selected = 0xFFFF0000;
										}
										else
										{
											list->CurSel = -1;
										}
									}

									if (list->ItemsArray[i].bSelected == true)
									{
										if (!button->bChecked)
										{
											list->ItemsArray[i].bSelected = false;
										}
										Selected++;
									}
								}
							}

							char szTemp[26];
							sprintf_s(szTemp, "%d/%d", Checked, list->ItemsArray.Count);
							pCountLabel->SetWindowText(szTemp);

							if (Selected == 0)
							{
								col->pTextureAnim = pUnChecked;
							}
							else
							{
								col->pTextureAnim = pChecked;
							}
						}
						else if (bool bList = pWnd->IsType(WRT_LISTWND))
						{
							// they clicked a item maybe...
							if (itemclicked < list->ItemsArray.Count)
							{
								if (itemclicked == list->CurSel)
								{
									if (lastsel == itemclicked)
									{
										list->ItemsArray[itemclicked].bSelected = false;
										list->CurSel = -1;
									}
								}
								lastsel = list->CurSel;
							}

							if (pMerchantWnd && pMerchantWnd->IsVisible() && list->CurSel >= 0)
							{
								int dta = (int)list->GetItemData(list->CurSel);
								if (ItemGlobalIndex* igg = pThis->gi[dta])
								{
									pMerchantWnd->SelectBuySellSlot(*igg, igg->GetTopSlot());
								}
							}

							int Checked = 0;
							for (int i = 0; i < list->ItemsArray.Count; i++)
							{
								if (CButtonWnd* button = (CButtonWnd*)list->GetItemWnd(i, Column_CheckBox))
								{
									if (button->bChecked)
									{
										list->ItemsArray[i].bSelected = true;
										Checked++;
									}
								}
							}

							char szTemp[26];
							sprintf_s(szTemp, "%d/%d", Checked, list->ItemsArray.Count);
							pCountLabel->SetWindowText(szTemp);

							if (Checked == 0)
							{
								col->pTextureAnim = pUnChecked;
								list->Selected = 0xFF004040;
							}
							else
							{
								col->pTextureAnim = pChecked;
							}
						}
					}
				}
			}
			else if (uiMessage == XWM_COLUMNCLICK)
			{
				int colindex = (int)pData;

				if (colindex == Column_CheckBox)
				{
					CListWnd* list = (CListWnd*)pThis->GetChildItem("FIW_ItemList");
					if (list)
					{
						if (list->Columns.Count > Column_CheckBox)
						{
							list->CurSel = -1;
							list->Selected = 0xFF004040;
							SListWndColumn* col = &list->Columns[Column_CheckBox];
							bool checked = true;

							if (col->pTextureAnim == pUnChecked)
							{
								col->pTextureAnim = pChecked;
							}
							else
							{
								col->pTextureAnim = pUnChecked;
								checked = false;
							}

							int selected = 0;
							for (int i = 0; i < list->ItemsArray.Count; i++)
							{
								if (list->ItemsArray[i].bSelected)
								{
									selected++;
								}
							}

							bool bFound = false;
							int Checked = 0;
							for (int i = 0; i < list->ItemsArray.Count; i++)
							{
								if (CButtonWnd* button = (CButtonWnd*)list->GetItemWnd(i, Column_CheckBox))
								{
									if (selected > 1)
									{
										if (list->ItemsArray[i].bSelected)
										{
											button->bChecked = checked;
										}
									}
									else
									{
										button->bChecked = checked;
									}

									if (button->bChecked)
									{
										Checked++;
										list->ItemsArray[i].bSelected = true;
										bFound = true;
									}
									else
									{
										list->ItemsArray[i].bSelected = false;
									}
								}

								char szTemp[26];
								sprintf_s(szTemp, "%d/%d", Checked, list->ItemsArray.Count);
								pCountLabel->SetWindowText(szTemp);

								if (bFound)
								{
									list->CurSel = -1;
									list->Selected = 0xFFFF0000;
								}
								else
								{
									list->Selected = 0xFF004040;
								}
							}
						}
					}
					return 1;
				}
			}
			else if (uiMessage == XWM_LMOUSEUP)
			{
				CButtonWnd* FIW_DestroyItem = (CButtonWnd*)pThis->GetChildItem("FIW_DestroyItem");
				int clickedrow = (int)pData;

				if (CListWnd* list = (CListWnd*)pThis->GetChildItem("FIW_ItemList"))
				{
					if (list->Columns.Count > Column_CheckBox)
					{
						if (FIW_DestroyItem && FIW_DestroyItem == pWnd)
						{
							if (!gDeleteList.empty())
								return 0;

							// if we have something on cursor we let eq handle the destroy
							if (!pProfile->GetInventorySlot(InvSlot_Cursor))
							{
								// if we have something on cursor we let eq handle the destroy
								// IF have something checked... AND they clicked the destroy item button... we go... their fault if they do this.
								for (int i = 0; i < list->ItemsArray.Count; i++)
								{
									if (CButtonWnd* button = (CButtonWnd*)list->GetItemWnd(i, Column_CheckBox))
									{
										if (button->bChecked)
										{
											CXStr str = list->GetItemText(i, 1);
											int dta = (int)list->GetItemData(i);

											if (ItemGlobalIndex* igg = (ItemGlobalIndex*)pThis->gi[dta])
											{
												gDeleteList.push_back(*igg);
											}
										}
									}
								}

								if (SListWndColumn* col = &list->Columns[Column_CheckBox])
								{
									col->pTextureAnim = pUnChecked;
								}

								if (!gDeleteList.empty())
									gbStartDeleting = true;

								return 1;
							}
						}
						else if (pNLMarkedButton == pWnd)
						{
							if (pMerchantWnd && pMerchantWnd->IsVisible())
							{
								if (!gSellList.empty())
									return 0;
							}

							if (list)
							{
								for (int i = 0; i < list->ItemsArray.Count; i++)
								{
									if (CButtonWnd* button = (CButtonWnd*)list->GetItemWnd(i, Column_CheckBox))
									{
										if (button->bChecked)
										{
											int dta = (int)list->GetItemData(i);

											if (ItemGlobalIndex* gi = pThis->gi[dta])
											{
												if (ItemPtr ptr = pCharData->GetItemByGlobalIndex(*gi))
												{
													ItemDefinition* pItem = ptr->GetItemDefinition();

													if (pMerchantWnd && pMerchantWnd->IsVisible())
													{
														WriteChatf("[%d] Adding %s to Sell List", i, ptr->GetName());
														gSellList.push_back(*gi);
													}
													else
													{
														WriteChatf("[%d] Marking %s as Never Loot", i, ptr->GetName());
														if (pLootFiltersManager)
														{
															pLootFiltersManager->SetItemLootFilter(pItem->ItemNumber, pItem->IconNumber, pItem->Name, 8, false, false);
														}
													}
												}
											}
										}
									}
								}

								if (!gSellList.empty())
									gbStartSelling = true;
							}
							return 1;
						}
					}
				}
			}
		}
		else if (!gbCheckBoxFeatureEnabled)
		{
			if (CListWnd* list = (CListWnd*)pThis->GetChildItem("FIW_ItemList"))
			{
				if (list->Columns.Count > Column_CheckBox)
				{
					if (SListWndColumn* col = &list->Columns[Column_CheckBox])
					{
						col->pTextureAnim = nullptr;
					}
				}
			}
		}

		return WndNotification_Trampoline(pWnd, uiMessage, pData);
	}
	int WndNotification_Trampoline(CXWnd*, uint32_t, void*);
};
DETOUR_TRAMPOLINE_EMPTY(void AutoInventory_FindItemWnd_Hook::Update_Trampoline());
DETOUR_TRAMPOLINE_EMPTY(int AutoInventory_FindItemWnd_Hook::WndNotification_Trampoline(CXWnd*, uint32_t, void*));

// CBankWnd hooks
class AutoInventory_BankWnd_Hook
{
public:
	int WndNotification_Detour(CXWnd* pWnd, uint32_t uiMessage, void* pData)
	{
		CBankWnd* pThis = (CBankWnd*)this;
		PcProfile* pProfile = GetPcProfile();

		// we use this to intercept the menu messages for our autobank button extension
		if (pThis->AutoButton == pWnd)
		{
			if (gAutoBankButton != pWnd)
				gAutoBankButton = (CButtonWnd*)pWnd;

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

						// work in progress -eqmule
						pContextMenuManager->PopupMenu(OurDefaultMenuIndex, Loc, pThis);
					}
					break;
				};
			}
		}
		else if (uiMessage == XWM_MENUSELECT)
		{
			CContextMenu* pContextMenu = (CContextMenu*)pWnd;
			int ItemID = (int)pData;
			int iItemID = pContextMenu->GetItemAtPoint(pWndMgr->MousePoint);

			switch (ItemID)
			{
			case ContextMenu_TradeskillItemsId:
				gbAutoBankTradeSkillItems = !gbAutoBankTradeSkillItems;
				WritePrivateProfileBool("AutoBank", "AutoBankTradeSkillItems", gbAutoBankTradeSkillItems, mq::internal_paths::MQini);

				AutoBankMenu->CheckMenuItem(iItemID, gbAutoBankTradeSkillItems);
				break;

			case ContextMenu_CollectibleItemsId:
				gbAutoBankCollectibleItems = !gbAutoBankCollectibleItems;
				WritePrivateProfileBool("AutoBank", "AutoBankCollectibleItems", gbAutoBankCollectibleItems, mq::internal_paths::MQini);

				AutoBankMenu->CheckMenuItem(iItemID, gbAutoBankCollectibleItems);
				break;

			case ContextMenu_QuestItemsId:
				gbAutoBankQuestItems = !gbAutoBankQuestItems;
				WritePrivateProfileBool("AutoBank", "AutoBankQuestItems", gbAutoBankQuestItems, mq::internal_paths::MQini);

				AutoBankMenu->CheckMenuItem(iItemID, gbAutoBankQuestItems);
				break;

			case ContextMenu_CheckedItemsId:
				gbAutoInventoryItems = !gbAutoInventoryItems;
				WritePrivateProfileBool("AutoBank", "AutoInventoryItems", gbAutoInventoryItems, mq::internal_paths::MQini);

				AutoBankMenu->CheckMenuItem(iItemID, gbAutoInventoryItems);
				break;
			};
		}

		return WndNotification_Trampoline(pWnd, uiMessage, pData);
	}
	int WndNotification_Trampoline(CXWnd*, uint32_t, void*);
};
DETOUR_TRAMPOLINE_EMPTY(int AutoInventory_BankWnd_Hook::WndNotification_Trampoline(CXWnd*, uint32_t, void*));

static void AddAutoBankMenu()
{
	if (OurCheckBoxMenuIndex == 0)
	{
		if (CContextMenuManager* pMgr = pContextMenuManager)
		{
			// save orig values
			int DefaultMenuIndex = pMgr->DefaultMenuIndex;
			int DefaultBGItem = pMgr->DefaultBGItem;
			int DefaultHelpItem = pMgr->DefaultHelpItem;
			int DefaultLockItem = pMgr->DefaultLockItem;
			int DefaultEscapeItem = pMgr->DefaultEscapeItem;
			int DefaultMinItem = pMgr->DefaultMinItem;
			int DefaultCloseItem = pMgr->DefaultCloseItem;

			// create our menu
			pMgr->CreateDefaultMenu();
			OurCheckBoxMenuIndex = pMgr->DefaultMenuIndex;

			// set orig values back, we now have a menu that's ours...
			pMgr->DefaultMenuIndex = DefaultMenuIndex;
			pMgr->DefaultBGItem = DefaultBGItem;
			pMgr->DefaultHelpItem = DefaultHelpItem;
			pMgr->DefaultLockItem = DefaultLockItem;
			pMgr->DefaultEscapeItem = DefaultEscapeItem;
			pMgr->DefaultMinItem = DefaultMinItem;
			pMgr->DefaultCloseItem = DefaultCloseItem;

			CheckBoxMenu = pContextMenuManager->GetMenu(OurCheckBoxMenuIndex);
			CheckBoxMenu->RemoveAllMenuItems();

			gbCheckBoxFeatureEnabled = GetPrivateProfileBool("CoolBoxes", "CheckBoxFeatureEnabled", true, mq::internal_paths::MQini);
			gbColorsFeatureEnabled = GetPrivateProfileInt("CoolBoxes", "ColorsFeatureEnabled", true, mq::internal_paths::MQini);

			if (gbWriteAllConfig)
			{
				WritePrivateProfileBool("CoolBoxes", "CheckBoxFeatureEnabled", gbCheckBoxFeatureEnabled, mq::internal_paths::MQini);
				WritePrivateProfileBool("CoolBoxes", "ColorsFeatureEnabled", gbColorsFeatureEnabled, mq::internal_paths::MQini);
			}

			CoolCheckBoxoptionID = CheckBoxMenu->AddMenuItem("Cool Checkbox Feature", ContextMenu_CheckboxFeatureEnabled, gbCheckBoxFeatureEnabled);
			CoolColorsoptionID = CheckBoxMenu->AddMenuItem("Cool Colors Feature", ContextMenu_ColorsFeatureEnabled, gbColorsFeatureEnabled);
		}

		if (CFindItemWnd* pFIWnd = pFindItemWnd)
		{
			if (CListWnd* list = (CListWnd*)pFIWnd->GetChildItem("FIW_ItemList"))
			{
				list->bHasItemTooltips = true;

				// if we dont do this the column tooltip is not drawn, i dont know why, possibly a listwindow bug
				list->SetTooltip("Find item Window has a sixth column now.");
				//list->SetItemIcon()
				list->ListWndStyle |= 0x00020000; // ok to multiselect, if we add a 1 here we can edit lines as well
				pUnChecked = pSidlMgr->FindAnimation("A_CheckBoxNormal");
				pChecked = pSidlMgr->FindAnimation("A_CheckBoxPressed");

				// add checkbox column
				if (list->Columns.Count == Column_CheckBox)
				{
					// can't get this stupid tooltip to show for columns, i dont know why...
					CXStr Str = "Toggle Checkboxes On/Off";
					MarkCol = list->AddColumn("", pUnChecked, 20, 0, Str, 3, nullptr, nullptr, true, { 0,0 }, { 0,0 });
					list->SetColumnJustification(MarkCol, 0);
				}
				else
				{
					SListWndColumn& col = list->Columns[Column_CheckBox];
					MarkCol = Column_CheckBox;
				}

				// add Value Column
				if (list->Columns.Count == Column_CheckBox + 1)
				{
					CXStr Str = "Shows Merchant Value of item";
					ValueCol = list->AddColumn("Value", nullptr, 160, 0, Str, 1, nullptr, nullptr, true, { 0,0 }, { 0,0 });
					list->SetColumnJustification(ValueCol, 0);
				}
				else
				{
					SListWndColumn& col = list->Columns[Column_CheckBox + 1];
					ValueCol = Column_CheckBox + 1;
				}

				// we need to add a couple controls, Checked count label and Never Loot Button
				if (CControlTemplate* pCountLabelTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("FIW_ItemNameLabel"))
				{
					if (pCountLabel = (CLabelWnd*)pSidlMgr->CreateXWndFromTemplate(pFIWnd, pCountLabelTemplate))
					{
						pCountLabel->SetBottomAnchoredToTop(false);
						pCountLabel->SetLeftAnchoredToLeft(false);
						pCountLabel->SetRightAnchoredToLeft(false);
						pCountLabel->SetTopAnchoredToTop(false);

						pCountLabel->SetTopOffset(20);
						pCountLabel->SetBottomOffset(0);
						pCountLabel->SetLeftOffset(220);
						pCountLabel->SetRightOffset(160);
						pCountLabel->SetTooltip("Shows you how many items you have selected.");
						pCountLabel->SetWindowText("0/10000");
						//BackgroundTextureTint
						pCountLabel->SetBGColor(0xFF2032FF);
					}
				}

				if (CControlTemplate* pRequestPreviewButtonTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("FIW_DestroyItem"))
				{
					if (pNLMarkedButton = (CButtonWnd*)pSidlMgr->CreateXWndFromTemplate(pFIWnd, pRequestPreviewButtonTemplate))
					{
						pNLMarkedButton->SetLeftOffset(157);
						pNLMarkedButton->SetRightOffset(87);
						pNLMarkedButton->SetTooltip("Click to tag all marked items as NEVER LOOT in advloot filters.");
						pNLMarkedButton->SetWindowText("Never Loot");
						//BackgroundTextureTint
						pNLMarkedButton->SetBGColor(0xFF2032FF);
					}
				}
			}
		}
		if (!gbCheckBoxFeatureEnabled)
		{
			if (pNLMarkedButton)
				pNLMarkedButton->SetVisible(false);
			if (pCountLabel)
				pCountLabel->SetVisible(false);
		}

		if (pFindItemWnd && pFindItemWnd->IsVisible() == true)
		{
			pFindItemWnd->Update();
		}
	}

	if (OurDefaultMenuIndex == 0)
	{
		if (CContextMenuManager* pMgr = pContextMenuManager)
		{
			// save orig values
			int DefaultMenuIndex = pMgr->DefaultMenuIndex;
			int DefaultBGItem = pMgr->DefaultBGItem;
			int DefaultHelpItem = pMgr->DefaultHelpItem;
			int DefaultLockItem = pMgr->DefaultLockItem;
			int DefaultEscapeItem = pMgr->DefaultEscapeItem;
			int DefaultMinItem = pMgr->DefaultMinItem;
			int DefaultCloseItem = pMgr->DefaultCloseItem;

			// create our menu
			pMgr->CreateDefaultMenu();

			// set our values
			OurDefaultMenuIndex = pMgr->DefaultMenuIndex;
			OurDefaultBGItem = pMgr->DefaultBGItem;
			OurDefaultHelpItem = pMgr->DefaultHelpItem;
			OurDefaultLockItem = pMgr->DefaultLockItem;
			OurDefaultEscapeItem = pMgr->DefaultEscapeItem;
			OurDefaultMinItem = pMgr->DefaultMinItem;
			OurDefaultCloseItem = pMgr->DefaultCloseItem;

			// set orig values back, we now have a menu that's ours...
			pMgr->DefaultMenuIndex = DefaultMenuIndex;
			pMgr->DefaultBGItem = DefaultBGItem;
			pMgr->DefaultHelpItem = DefaultHelpItem;
			pMgr->DefaultLockItem = DefaultLockItem;
			pMgr->DefaultEscapeItem = DefaultEscapeItem;
			pMgr->DefaultMinItem = DefaultMinItem;
			pMgr->DefaultCloseItem = DefaultCloseItem;

			AutoBankMenu = pContextMenuManager->GetMenu(OurDefaultMenuIndex);
			AutoBankMenu->RemoveAllMenuItems();

			gbAutoBankTradeSkillItems = GetPrivateProfileBool("AutoBank", "AutoBankTradeSkillItems", false, mq::internal_paths::MQini);
			gbAutoBankCollectibleItems = GetPrivateProfileBool("AutoBank", "AutoBankCollectibleItems", false, mq::internal_paths::MQini);
			gbAutoBankQuestItems = GetPrivateProfileInt("AutoBank", "AutoBankQuestItems", false, mq::internal_paths::MQini);
			gbAutoInventoryItems = GetPrivateProfileInt("AutoBank", "AutoInventoryItems", false, mq::internal_paths::MQini);

			if (gbWriteAllConfig)
			{
				WritePrivateProfileBool("AutoBank", "AutoBankTradeSkillItems", gbAutoBankTradeSkillItems, mq::internal_paths::MQini);
				WritePrivateProfileBool("AutoBank", "AutoBankCollectibleItems", gbAutoBankCollectibleItems, mq::internal_paths::MQini);
				WritePrivateProfileBool("AutoBank", "AutoBankQuestItems", gbAutoBankQuestItems, mq::internal_paths::MQini);
				WritePrivateProfileBool("AutoBank", "AutoInventoryItems", gbWriteAllConfig, mq::internal_paths::MQini);
			}

			tradeskilloptionID = AutoBankMenu->AddMenuItem("Tradeskill Items", ContextMenu_TradeskillItemsId, gbAutoBankTradeSkillItems);
			collectibleoptionID = AutoBankMenu->AddMenuItem("Collectible Items", ContextMenu_CollectibleItemsId, gbAutoBankCollectibleItems);
			questoptionID = AutoBankMenu->AddMenuItem("Quest Items", ContextMenu_QuestItemsId, gbAutoBankQuestItems);
			separatoroptionID = AutoBankMenu->AddSeparator();
			questoptionID = AutoBankMenu->AddMenuItem("AutoInventory Checked Items", ContextMenu_CheckedItemsId, gbAutoInventoryItems);
		}
	}
}

void RemoveAutoBankMenu()
{
	if (CContextMenuManager* pMgr = pContextMenuManager)
	{
		if (OurDefaultMenuIndex != 0)
		{
			pMgr->RemoveMenu(OurDefaultMenuIndex, true);
			OurDefaultMenuIndex = 0;
		}

		if (OurCheckBoxMenuIndex != 0)
		{
			pMgr->RemoveMenu(OurCheckBoxMenuIndex, true);
			OurCheckBoxMenuIndex = 0;
			if (pNLMarkedButton)
			{
				pNLMarkedButton->Destroy();
				pNLMarkedButton = nullptr;
			}

			if (pCountLabel)
			{
				pCountLabel->Destroy();
				pCountLabel = nullptr;
			}


			if (pFindItemWnd)
			{
				if (CListWnd* list = (CListWnd*)pFindItemWnd->GetChildItem("FIW_ItemList"))
				{
					if (list->Columns.Count > ValueCol)
					{
						list->Columns.DeleteElement(ValueCol);
						ValueCol = 0;
					}

					if (list->Columns.Count > MarkCol)
					{
						list->Columns.DeleteElement(MarkCol);
						MarkCol = 0;
					}
				}
			}
		}
	}
}

static void AutoBankPulse()
{
	CHARINFO* pCharInfo = GetCharInfo();
	if (!pCharInfo)
		return;
	PcProfile* pProfile = GetPcProfile();

	if (pMerchantWnd)
	{
		if (pMerchantWnd->IsVisible())
		{
			if (!bChangedNL)
			{
				if (pNLMarkedButton)
				{
					pNLMarkedButton->SetWindowText("Sell Marked");
					bChangedNL = true;
				}
			}
		}
		else
		{
			if (bChangedNL)
			{
				if (pNLMarkedButton)
				{
					pNLMarkedButton->SetWindowText("Never Loot");
					bChangedNL = false;
				}
			}
		}
	}

	if (gbStartSelling)
	{
		if (pMerchantWnd && pMerchantWnd->IsVisible())
		{
			if (EverQuestinfo__IsItemPending) {
				DWORD wecantsell = *(DWORD*)EverQuestinfo__IsItemPending;
				if (wecantsell)
					return;
			}

			uint64_t now = GetTickCount64();
			if (now < SellTimer + 1200)
				return;

			// user wants us to sell stuff
			for (auto g = gSellList.begin(); g != gSellList.end(); g++)
			{
				ItemGlobalIndex& gi = *g;
				if (ItemPtr pItem = pCharData->GetItemByGlobalIndex(gi))
				{
					bool didSell = false;
					if (pMerchantWnd->pSelectedItem)
					{
						if (pMerchantWnd->pSelectedItem->GetID() == pItem->GetID())
						{
							gSellList.pop_front();
							WriteChatf("Sold %d %s", pItem->GetItemCount(), pItem->GetName());
							DoCommandf("/sellitem %d", pItem->GetItemCount());
							SellTimer = GetTickCount64();
							didSell = true;
							break;
						}
					}

					if (!didSell)
					{
						pMerchantWnd->SelectBuySellSlot(gi, gi.GetTopSlot());
						break;
					}
				}

				gSellList.pop_front();
				break;
			}

			if (gSellList.empty())
				gbStartSelling = false;
		}
		else
		{
			gSellList.clear();
			gbStartSelling = false;
		}
		return;
	}

	if (gbStartDeleting)
	{
		if (pCursorAttachment && pCursorAttachment->Type == eCursorAttachment_None)
		{
			// user wants us to delete stuff. Delete one item per frame.
			if (!gDeleteList.empty())
			{
				ItemGlobalIndex index = gDeleteList.front();
				gDeleteList.pop_front();

				if (ItemPtr pItem = pCharData->GetItemByGlobalIndex(index))
				{
					if (PickupItem(pItem->GetGlobalIndex()))
					{
						WriteChatf("Destroyed %s", pItem->GetName());
						DoCommandf("/destroyitem");
					}
				}
			}

			if (gDeleteList.empty())
				gbStartDeleting = false;
		}

		return;
	}

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
			pCharInfo->BankItems.VisitContainers(
				[&](const ItemPtr& pItem, const ItemIndex& index)
			{
				// dont add bags that have items inside of them.
				if (pItem->IsContainer() && !pItem->IsEmpty())
					return;

				ItemDefinition* itemDef = pItem->GetItemDefinition();
				if ((gbAutoBankTradeSkillItems && itemDef->TradeSkills)
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
	}

	// user wants us to autobank stuff
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
				if ((gbAutoBankTradeSkillItems && itemDef->TradeSkills)
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
				PickupItem(pItem->GetGlobalIndex());
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

void InitializeMQ2AutoInventory()
{
	EzDetour(CBankWnd__WndNotification,
		&AutoInventory_BankWnd_Hook::WndNotification_Detour,
		&AutoInventory_BankWnd_Hook::WndNotification_Trampoline);
	EzDetour(CFindItemWnd__WndNotification,
		&AutoInventory_FindItemWnd_Hook::WndNotification_Detour,
		&AutoInventory_FindItemWnd_Hook::WndNotification_Trampoline);
	EzDetour(CFindItemWnd__Update,
		&AutoInventory_FindItemWnd_Hook::Update_Detour,
		&AutoInventory_FindItemWnd_Hook::Update_Trampoline);
}

void ShutdownMQ2AutoInventory()
{
	RemoveDetour(CFindItemWnd__WndNotification);
	RemoveDetour(CFindItemWnd__Update);
	RemoveDetour(CBankWnd__WndNotification);
	RemoveAutoBankMenu();
}

void PulseMQ2AutoInventory()
{
	if (gGameState != GAMESTATE_INGAME)
		return;

	AddAutoBankMenu();
	AutoBankPulse();
}

} // namespace mq
