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

#include "pch.h"
#include "MQ2Main.h"

#include <algorithm>
#include <list>
#include <map>
#include <string>

namespace mq {

#if HAS_FIND_ITEM_WINDOW
CContextMenu* CheckBoxMenu = nullptr;
static int s_findItemCheckBoxMenu = 0;

CTextureAnimation* pChecked = nullptr;
CTextureAnimation* pUnChecked = nullptr;
CLabelWnd* pCountLabel = nullptr;
CButtonWnd* pNLMarkedButton = nullptr;
bool bChangedNL = false;

static std::list<ItemGlobalIndex> gDeleteList;
static bool gbStartDeleting = false;

static std::list<ItemGlobalIndex> gSellList;
static bool gbStartSelling = false;
uint64_t SellTimer = 0;

static bool gbCheckBoxFeatureEnabled = true;
bool gbColorsFeatureEnabled = true;

static int s_lastSelectedItem = -1;

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

namespace AutoInventory {
	class FindItemWnd_Hook;
}

#endif // HAS_FIND_ITEM_WINDOW

namespace AutoInventory {
	class CBarterWnd_Hook;
	class CBarterSearchWnd_Hook;
}

static int CompareMoneyStrings(SListWndSortInfo* sInfo, GetMoneyFromStringFormat format)
{
	int64_t value1 = static_cast<int64_t>(!sInfo->StrLabel1.empty() ? GetMoneyFromString(sInfo->StrLabel1.c_str(), format) : -1);
	int64_t value2 = static_cast<int64_t>(!sInfo->StrLabel2.empty() ? GetMoneyFromString(sInfo->StrLabel2.c_str(), format) : -1);
	return static_cast<int>(value1 - value2);
}

#if HAS_FIND_ITEM_WINDOW

// CFindItemWnd hooks
class AutoInventory::FindItemWnd_Hook
{
public:
	DETOUR_TRAMPOLINE_DEF(void, Update_Trampoline, ())
	void Update_Detour()
	{
		CFindItemWnd* pFIWnd = reinterpret_cast<CFindItemWnd*>(this);
		Update_Trampoline();

		CListWnd* list = static_cast<CListWnd*>(pFIWnd->GetChildItem("FIW_ItemList"));
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

				if (TotalWidth > rect.right - rect.left)
				{
					int newwidth = TotalWidth - (rect.right - rect.left);
					rect.right += newwidth;
					rectmain.right += newwidth + 10;
					list->Move(rect, false, false, false, false);
					pFIWnd->Move(rectmain, false, false, false, false);
				}

				// let's borrow a checkbox
				if (CControlTemplate* pDisableConnectionTemplate = static_cast<CControlTemplate*>(pSidlMgr->FindScreenPieceTemplate("ATW_Checkbox")))
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

						if (CCheckBoxWnd* pCheck = static_cast<CCheckBoxWnd*>(pSidlMgr->CreateXWndFromTemplate(pFIWnd, pDisableConnectionTemplate)))
						{
							pCheck->SetEnabled(true);
							pCheck->SetCheck(false);
							pCheck->SetData(list->GetItemData(i));
							pCheck->SetVisible(true);
							pCheck->SetActive(true);
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

							ItemGlobalIndex itemIndex = pFIWnd->GetItemGlobalIndex(static_cast<int>(pCheck->GetData()));
							if (itemIndex.IsValidIndex())
							{
								if (ItemPtr ptr = pLocalPC->GetItemByGlobalIndex(itemIndex))
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
										FormatMoneyString(szTemp3, lengthof(szTemp3), static_cast<uint64_t>(sellprice), GetMoneyFromStringFormat::Long);
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

	DETOUR_TRAMPOLINE_DEF(int, WndNotification_Trampoline, (CXWnd*, uint32_t, void*))
	int WndNotification_Detour(CXWnd* pWnd, uint32_t uiMessage, void* pData)
	{
		CFindItemWnd* pThis = reinterpret_cast<CFindItemWnd*>(this);

		if (uiMessage == XWM_SORTREQUEST)
		{
			if (pWnd == pThis->FIW_ItemList)
			{
				SListWndSortInfo* pSI = static_cast<SListWndSortInfo*>(pData);

				if (pSI->SortCol == Column_Value)
				{
					pSI->SortResult = CompareMoneyStrings(pSI, GetMoneyFromStringFormat::Long);
					return 0;
				}

				// Let other columns sort by default
				return WndNotification_Trampoline(pWnd, uiMessage, pData);
			}
		}
		else if (uiMessage == XWM_MENUSELECT)
		{
			int ItemID = static_cast<int>(reinterpret_cast<intptr_t>(pData));
			int iItemID = 0;

			if (CContextMenu* pContextMenu = static_cast<CContextMenu*>(pWnd))
			{
				CXPoint pt = pWndMgr->MousePoint;
				iItemID = pContextMenu->GetItemAtPoint(pt);
			}

			if (ItemID == ContextMenu_CheckboxFeatureEnabled)
			{
				if (gbCheckBoxFeatureEnabled)
				{
					gbCheckBoxFeatureEnabled = false;

					if (pNLMarkedButton)
						pNLMarkedButton->SetVisible(false);
					if (pCountLabel)
						pCountLabel->SetVisible(false);

					if (CListWnd* list = static_cast<CListWnd*>(pThis->GetChildItem("FIW_ItemList")))
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

					if (CListWnd* list = static_cast<CListWnd*>(pThis->GetChildItem("FIW_ItemList")))
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
			}
			else if (ItemID == ContextMenu_ColorsFeatureEnabled)
			{
				gbColorsFeatureEnabled = !gbColorsFeatureEnabled;
				WritePrivateProfileBool("CoolBoxes", "ColorsFeatureEnabled", gbColorsFeatureEnabled, mq::internal_paths::MQini);

				CheckBoxMenu->CheckMenuItem(iItemID, gbColorsFeatureEnabled);
				pFindItemWnd->Update();
			}
		}
		else if (uiMessage == XWM_RCLICK)
		{
			if (CButtonWnd* FIW_DestroyItem = static_cast<CButtonWnd*>(pThis->GetChildItem("FIW_DestroyItem")))
			{
				if (pWnd == FIW_DestroyItem || pWnd == pNLMarkedButton || pWnd == pCountLabel)
				{
					if (pContextMenuManager)
					{
						CXPoint Loc = pWndMgr->MousePoint;

						// work in progress
						pContextMenuManager->PopupMenu(s_findItemCheckBoxMenu, Loc, pThis);
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
				int itemclicked = static_cast<int>(reinterpret_cast<intptr_t>(pData));
				if (CListWnd* list = static_cast<CListWnd*>(pThis->GetChildItem("FIW_ItemList")))
				{
					if (list->Columns.Count > Column_CheckBox)
					{
						SListWndColumn* col = &list->Columns[Column_CheckBox];

						if (pWnd->IsType(WRT_CHECKBOXWND))
						{
							bool bChecked = static_cast<CCheckBoxWnd*>(pWnd)->bChecked;
							int Selected = 0;
							int Checked = 0;

							for (int i = 0; i < list->ItemsArray.Count; i++)
							{
								if (CButtonWnd* button = static_cast<CButtonWnd*>(list->GetItemWnd(i, Column_CheckBox)))
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
						else if (pWnd->IsType(WRT_LISTWND))
						{
							// they clicked an item maybe...
							if (itemclicked < list->ItemsArray.Count)
							{
								if (itemclicked == list->CurSel)
								{
									if (s_lastSelectedItem == itemclicked)
									{
										list->ItemsArray[itemclicked].bSelected = false;
										list->CurSel = -1;
									}
								}
								s_lastSelectedItem = list->CurSel;
							}

							if (pMerchantWnd && pMerchantWnd->IsVisible() && list->CurSel >= 0)
							{
								ItemGlobalIndex itemIndex = pThis->GetItemGlobalIndex(static_cast<int>(list->GetItemData(list->CurSel)));
								if (itemIndex.IsValidIndex())
								{
									pMerchantWnd->SelectBuySellSlot(itemIndex, itemIndex.GetTopSlot());
								}
							}

							int Checked = 0;
							for (int i = 0; i < list->ItemsArray.Count; i++)
							{
								if (CButtonWnd* button = static_cast<CButtonWnd*>(list->GetItemWnd(i, Column_CheckBox)))
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
				int colindex = static_cast<int>(reinterpret_cast<intptr_t>(pData));

				if (colindex == Column_CheckBox)
				{
					CListWnd* list = static_cast<CListWnd*>(pThis->GetChildItem("FIW_ItemList"));
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
								if (CButtonWnd* button = static_cast<CButtonWnd*>(list->GetItemWnd(i, Column_CheckBox)))
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
				if (CListWnd* list = static_cast<CListWnd*>(pThis->GetChildItem("FIW_ItemList")))
				{
					if (list->Columns.Count > Column_CheckBox)
					{
						// Clicked destroy button?
						CButtonWnd* FIW_DestroyItem = static_cast<CButtonWnd*>(pThis->GetChildItem("FIW_DestroyItem"));
						if (FIW_DestroyItem && pWnd == FIW_DestroyItem)
						{
							if (!gDeleteList.empty())
								return 0;

							// if we have something on cursor we let eq handle the destroy action
							PcProfile* pProfile = GetPcProfile();
							if (!pProfile->GetInventorySlot(InvSlot_Cursor))
							{
								// If we have something checked AND they clicked the destroy item button... we go... their fault if they do this.
								for (int i = 0; i < list->ItemsArray.Count; i++)
								{
									if (CButtonWnd* button = static_cast<CButtonWnd*>(list->GetItemWnd(i, Column_CheckBox)))
									{
										if (button->bChecked)
										{
											ItemGlobalIndex itemIndex = pThis->GetItemGlobalIndex(static_cast<int>(list->GetItemData(i)));
											if (itemIndex.IsValidIndex() && itemIndex.GetLocation() == eItemContainerPossessions)
											{
												gDeleteList.push_back(itemIndex);
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
								bool isMerchantMode = pMerchantWnd && pMerchantWnd->IsVisible();

								for (int i = 0; i < list->ItemsArray.Count; i++)
								{
									if (CButtonWnd* button = static_cast<CButtonWnd*>(list->GetItemWnd(i, Column_CheckBox)))
									{
										if (button->bChecked)
										{
											ItemGlobalIndex itemIndex = pThis->GetItemGlobalIndex(static_cast<int>(list->GetItemData(i)));

											// Can only sell items from our inventory.
											if (isMerchantMode && itemIndex.GetLocation() != eItemContainerPossessions)
												continue;

											if (ItemPtr ptr = pLocalPC->GetItemByGlobalIndex(itemIndex))
											{
												if (isMerchantMode)
												{
													WriteChatf("[%d] Adding %s to Sell List", i, ptr->GetName());
													gSellList.push_back(itemIndex);
												}
												else
												{
													// FIXME: emu
													WriteChatf("[%d] Marking %s as Never Loot", i, ptr->GetName());
													if (pLootFiltersManager)
													{
														ItemDefinition* pItem = ptr->GetItemDefinition();

														pLootFiltersManager->SetItemLootFilter(pItem->ItemNumber, pItem->IconNumber, pItem->Name, 8, false, false);
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
			if (CListWnd* list = static_cast<CListWnd*>(pThis->GetChildItem("FIW_ItemList")))
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
};

#endif // HAS_FIND_ITEM_WINDOW

// CBarterWnd hooks
class AutoInventory::CBarterWnd_Hook
{
public:
	DETOUR_TRAMPOLINE_DEF(int, WndNotification_Trampoline, (CXWnd* pWnd, uint32_t uiMessage, void* pData))
	int WndNotification_Detour(CXWnd* pWnd, uint32_t uiMessage, void* pData)
	{
		CBarterWnd* pThis = reinterpret_cast<CBarterWnd*>(this);

		if (pWnd == pThis->plistBuyLines)
		{
			if (uiMessage == XWM_COLUMNCLICK)
			{
				int columnIndex = static_cast<int>(reinterpret_cast<intptr_t>(pData));

				pThis->plistBuyLines->SetSortColumn(columnIndex);
				return 0;
			}
			else if (uiMessage == XWM_SORTREQUEST)
			{
				SListWndSortInfo* sortInfo = static_cast<SListWndSortInfo*>(pData);

				switch (sortInfo->SortCol)
				{
				case CBarterWnd::Column_Active:
				case CBarterWnd::Column_Icon:
				case CBarterWnd::Column_Name:
				default:
					sortInfo->SortResult = sortInfo->StrLabel1.Compare(sortInfo->StrLabel2, CaseInsensitive);
					break;

				case CBarterWnd::Column_Count:
					sortInfo->SortResult = GetIntFromString(sortInfo->StrLabel1, 0) - GetIntFromString(sortInfo->StrLabel2, 0);
					break;

				case CBarterWnd::Column_Offering:
					sortInfo->SortResult = CompareMoneyStrings(sortInfo, GetMoneyFromStringFormat::Short);
					break;
				}

				return 0;
			}
		}

		return WndNotification_Trampoline(pWnd, uiMessage, pData);
	}
};

class AutoInventory::CBarterSearchWnd_Hook
{
	static inline int BarterValueCol = 0;
	static inline int BarterLastSortIndex = 1;
	static inline bool BarterLastSortDirection = true;

public:
	DETOUR_TRAMPOLINE_DEF(int, WndNotification_Trampoline, (CXWnd* pWnd, uint32_t uiMessage, void* pData))
	int WndNotification_Detour(CXWnd* pWnd, uint32_t uiMessage, void* pData)
	{
		CBarterSearchWnd* pThis = reinterpret_cast<CBarterSearchWnd*>(this);

		if (pWnd == pThis->plistInventory)
		{
			if (uiMessage == XWM_RCLICK)
			{
				int selectedIndex = pThis->plistInventory->GetCurSel();
				if (selectedIndex != -1)
				{
					int searchIndex = static_cast<int>(pThis->plistInventory->GetItemData(selectedIndex));
					if (searchIndex >= 0 && searchIndex < pThis->InventoryItems.GetLength())
					{
						BarterInventoryItem& item = pThis->InventoryItems[searchIndex];

						if (ItemPtr pItem = FindItemByID(item.ItemID))
						{
							pItemDisplayManager->ShowItem(pItem);
						}
					}
				}

				return 0;
			}
			
			if (uiMessage == XWM_COLUMNCLICK)
			{
				int columnIndex = static_cast<int>(reinterpret_cast<intptr_t>(pData));
				pThis->plistInventory->SetSortColumn(columnIndex);

				return 0;
			}

			if (uiMessage == XWM_SORTREQUEST)
			{
				SListWndSortInfo* sortInfo = static_cast<SListWndSortInfo*>(pData);

				switch (sortInfo->SortCol)
				{
				case CBarterSearchWnd::Column_Icon:
				case CBarterSearchWnd::Column_Name:
				default:
					sortInfo->SortResult = sortInfo->StrLabel1.Compare(sortInfo->StrLabel2, CaseInsensitive);
					break;

				case CBarterSearchWnd::Column_Count:
					sortInfo->SortResult = GetIntFromString(sortInfo->StrLabel1, 0) - GetIntFromString(sortInfo->StrLabel2, 0);
					break;
				}

				return 0;
			}
		}

		return WndNotification_Trampoline(pWnd, uiMessage, pData);
	}

	DETOUR_TRAMPOLINE_DEF(void, UpdateInventoryList_Trampoline, ())
	void UpdateInventoryList_Detour()
	{
		UpdateInventoryList_Trampoline();

		CBarterSearchWnd* pThis = reinterpret_cast<CBarterSearchWnd*>(this);

		if (BarterValueCol != 0 && BarterValueCol < pThis->plistInventory->Columns.GetCount())
		{
			for (int i = 0; i < pThis->plistInventory->ItemsArray.GetCount(); ++i)
			{
				int realIndex = static_cast<int>(pThis->plistInventory->GetItemData(i));
				ItemPtr pItem = FindItemByID(pThis->InventoryItems[realIndex].ItemID);

				char szLabel[32] = "";

				if (pItem && pItem->GetItemDefinition()->Cost > 0)
				{
					int sellPrice = pItem->ValueSellMerchant(1.05f, 1);
					FormatMoneyString(szLabel, lengthof(szLabel), sellPrice, GetMoneyFromStringFormat::Short);
				}

				pThis->plistInventory->SetItemText(i, BarterValueCol, szLabel);
			}

			pThis->plistInventory->bSortAsc = BarterLastSortDirection;
			pThis->plistInventory->SortCol = BarterLastSortIndex;
			pThis->plistInventory->Sort();
		}
	}

	static void AddInventoryValueColumn()
	{
		// Add a value sort column
		if (BarterValueCol == 0 && pBarterSearchWnd)
		{
			BarterLastSortIndex = pBarterSearchWnd->plistInventory->SortCol;
			BarterLastSortDirection = pBarterSearchWnd->plistInventory->bSortAsc;

			if (pBarterSearchWnd->plistInventory->Columns.GetCount() <= CBarterSearchWnd::Column_Max)
			{
				CXStr tooltip = "Shows merchant value of item";
				BarterValueCol = pBarterSearchWnd->plistInventory->AddColumn("Value", nullptr, 160 /* width */, 0, tooltip,
					CellTypeBasicText, nullptr, nullptr, true, CXSize(), CXPoint());
				pBarterSearchWnd->plistInventory->SetColumnJustification(BarterValueCol, 0);
			}
			else
			{
				BarterValueCol = CBarterSearchWnd::Column_Max; // we added it already at the end.
			}
		}
	}

	static void RemoveInventoryValueColumn()
	{
		// Remove the sort column
		if (BarterValueCol != 0 && pBarterSearchWnd && BarterValueCol < pBarterSearchWnd->plistInventory->Columns.GetCount())
		{
			pBarterSearchWnd->plistInventory->Columns.DeleteElement(BarterValueCol);
			BarterValueCol = 0;

			BarterLastSortIndex = 1;
			BarterLastSortDirection = true;

			pBarterSearchWnd->plistInventory->SortCol = BarterLastSortIndex;
			pBarterSearchWnd->plistInventory->bSortAsc = BarterLastSortDirection;
			pBarterSearchWnd->plistInventory->Sort();
		}
	}
};

static void AddFindItemMenu()
{
	AutoInventory::CBarterSearchWnd_Hook::AddInventoryValueColumn();

#if HAS_FIND_ITEM_WINDOW
	if (s_findItemCheckBoxMenu == 0)
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

			s_findItemCheckBoxMenu = pContextMenuManager->DefaultMenuIndex;

			// set orig values back, we now have a menu that's ours...
			pContextMenuManager->DefaultMenuIndex = DefaultMenuIndex;
			pContextMenuManager->DefaultBGItem = DefaultBGItem;
			pContextMenuManager->DefaultHelpItem = DefaultHelpItem;
			pContextMenuManager->DefaultLockItem = DefaultLockItem;
			pContextMenuManager->DefaultEscapeItem = DefaultEscapeItem;
			pContextMenuManager->DefaultMinItem = DefaultMinItem;
			pContextMenuManager->DefaultCloseItem = DefaultCloseItem;

			CheckBoxMenu = pContextMenuManager->GetMenu(s_findItemCheckBoxMenu);
			CheckBoxMenu->RemoveAllMenuItems();

			gbCheckBoxFeatureEnabled = GetPrivateProfileBool("CoolBoxes", "CheckBoxFeatureEnabled", true, mq::internal_paths::MQini);
			gbColorsFeatureEnabled = GetPrivateProfileInt("CoolBoxes", "ColorsFeatureEnabled", true, mq::internal_paths::MQini);

			if (gbWriteAllConfig)
			{
				WritePrivateProfileBool("CoolBoxes", "CheckBoxFeatureEnabled", gbCheckBoxFeatureEnabled, mq::internal_paths::MQini);
				WritePrivateProfileBool("CoolBoxes", "ColorsFeatureEnabled", gbColorsFeatureEnabled, mq::internal_paths::MQini);
			}

			CheckBoxMenu->AddMenuItem("Cool Checkbox Feature", ContextMenu_CheckboxFeatureEnabled, gbCheckBoxFeatureEnabled);
			CheckBoxMenu->AddMenuItem("Cool Colors Feature", ContextMenu_ColorsFeatureEnabled, gbColorsFeatureEnabled);
		}

		if (CFindItemWnd* pFIWnd = pFindItemWnd)
		{
			if (CListWnd* list = static_cast<CListWnd*>(pFIWnd->GetChildItem("FIW_ItemList")))
			{
				list->bHasItemTooltips = true;

				// if we don't do this the column tooltip is not drawn, I don't know why, possibly a listwindow bug
				list->SetTooltip("Find item Window has a sixth column now.");
				list->ListWndStyle |= 0x00020000; // ok to multiselect, if we add a 1 here we can edit lines as well
				pUnChecked = pSidlMgr->FindAnimation("A_CheckBoxNormal");
				pChecked = pSidlMgr->FindAnimation("A_CheckBoxPressed");

				// add checkbox column
				if (list->Columns.Count == Column_CheckBox)
				{
					// can't get this stupid tooltip to show for columns, I don't know why...
					CXStr Str = "Toggle Checkboxes On/Off";
					MarkCol = list->AddColumn("", pUnChecked, 20, 0, Str, 3, nullptr, nullptr, true, { 0,0 }, { 0,0 });
					list->SetColumnJustification(MarkCol, 0);
				}
				else
				{
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
					ValueCol = Column_CheckBox + 1;
				}

				// we need to add a couple controls, Checked count label and Never Loot Button
				if (CControlTemplate* pCountLabelTemplate = static_cast<CControlTemplate*>(pSidlMgr->FindScreenPieceTemplate("FIW_ItemNameLabel")))
				{
					if ((pCountLabel = static_cast<CLabelWnd*>(pSidlMgr->CreateXWndFromTemplate(pFIWnd, pCountLabelTemplate))))
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
						// BackgroundTextureTint
						pCountLabel->SetBGColor(0xFF2032FF);
					}
				}

				if (CControlTemplate* pRequestPreviewButtonTemplate = static_cast<CControlTemplate*>(pSidlMgr->FindScreenPieceTemplate("FIW_DestroyItem")))
				{
					if ((pNLMarkedButton = static_cast<CButtonWnd*>(pSidlMgr->CreateXWndFromTemplate(pFIWnd, pRequestPreviewButtonTemplate))))
					{
						pNLMarkedButton->SetLeftOffset(157);
						pNLMarkedButton->SetRightOffset(87);
						pNLMarkedButton->SetTooltip("Click to tag all marked items as NEVER LOOT in advloot filters.");
						pNLMarkedButton->SetWindowText("Never Loot");
						// BackgroundTextureTint
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
#endif // HAS_FIND_ITEM_WINDOW
}

void RemoveFindItemMenu()
{
	AutoInventory::CBarterSearchWnd_Hook::RemoveInventoryValueColumn();

#if HAS_FIND_ITEM_WINDOW
	if (pContextMenuManager)
	{
		if (s_findItemCheckBoxMenu != 0)
		{
			pContextMenuManager->RemoveMenu(s_findItemCheckBoxMenu, true);
			s_findItemCheckBoxMenu = 0;
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
				if (CListWnd* list = static_cast<CListWnd*>(pFindItemWnd->GetChildItem("FIW_ItemList")))
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
#endif // HAS_FIND_ITEM_WINDOW
}

static void FindItemPulse()
{
	if (!pLocalPC)
		return;

#if HAS_FIND_ITEM_WINDOW
	if (pMerchantWnd)
	{
		if (pMerchantWnd->IsVisible())
		{
			if (!bChangedNL)
			{
				if (pNLMarkedButton)
				{
					pNLMarkedButton->SetWindowText("Sell Marked");
					pNLMarkedButton->SetTooltip("Click to sell marked items.");
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
					pNLMarkedButton->SetTooltip("Click to tag all marked items as NEVER LOOT in advloot filters.");
					bChangedNL = false;
				}
			}
		}
	}

	if (gbStartSelling)
	{
		if (pMerchantWnd && pMerchantWnd->IsVisible())
		{
			if (pEverQuestInfo->ItemPending > 0) {
				return;
			}

			uint64_t now = GetTickCount64();
			if (now < SellTimer + 1200)
				return;

			// user wants us to sell stuff
			if (!gSellList.empty())
			{
				ItemGlobalIndex itemIndex = gSellList.front();
				gSellList.pop_front();

				if (ItemPtr pItem = pLocalPC->GetItemByGlobalIndex(itemIndex))
				{
					bool didSell = false;
					if (pMerchantWnd->pSelectedItem)
					{
						if (pMerchantWnd->pSelectedItem->GetID() == pItem->GetID())
						{
							WriteChatf("Sold %d %s", pItem->GetItemCount(), pItem->GetName());
							DoCommandf("/sellitem %d", pItem->GetItemCount());
							SellTimer = GetTickCount64();
							didSell = true;
						}
					}

					if (!didSell)
					{
						pMerchantWnd->SelectBuySellSlot(itemIndex, itemIndex.GetTopSlot());
					}
				}
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
				ItemGlobalIndex itemIndex = gDeleteList.front();
				gDeleteList.pop_front();

				if (ItemPtr pItem = pLocalPC->GetItemByGlobalIndex(itemIndex))
				{
					if (PickupItem(pItem->GetItemLocation()))
					{
						ItemDefinition* pItemDef = pItem->GetItemDefinition();

						if (pItemDef->NoDestroy)
						{
							WriteChatf("Skipping \"No Destroy\" item %s", pItem->GetName());
							DoCommandf("/autoinventory");
						}
						else
						{

							WriteChatf("Destroyed %s", pItem->GetName());
							DoCommandf("/destroyitem");
						}
					}
				}
			}

			if (gDeleteList.empty())
				gbStartDeleting = false;
		}
	}

#endif // HAS_FIND_ITEM_WINDOW
}

void InitializeMQ2AutoInventory()
{
#if HAS_FIND_ITEM_WINDOW
	EzDetour(CFindItemWnd__WndNotification,
		&AutoInventory::FindItemWnd_Hook::WndNotification_Detour,
		&AutoInventory::FindItemWnd_Hook::WndNotification_Trampoline);
	EzDetour(CFindItemWnd__Update,
		&AutoInventory::FindItemWnd_Hook::Update_Detour,
		&AutoInventory::FindItemWnd_Hook::Update_Trampoline);
#endif // HAS_FIND_ITEM_WINDOW
	EzDetour(CBarterSearchWnd__WndNotification,
		&AutoInventory::CBarterSearchWnd_Hook::WndNotification_Detour,
		&AutoInventory::CBarterSearchWnd_Hook::WndNotification_Trampoline);
	EzDetour(CBarterSearchWnd__UpdateInventoryList,
		&AutoInventory::CBarterSearchWnd_Hook::UpdateInventoryList_Detour,
		&AutoInventory::CBarterSearchWnd_Hook::UpdateInventoryList_Trampoline);
	EzDetour(CBarterWnd__WndNotification,
		&AutoInventory::CBarterWnd_Hook::WndNotification_Detour,
		&AutoInventory::CBarterWnd_Hook::WndNotification_Trampoline);
}

void ShutdownMQ2AutoInventory()
{
	RemoveDetour(CBarterWnd__WndNotification);
	RemoveDetour(CBarterSearchWnd__UpdateInventoryList);
	RemoveDetour(CBarterSearchWnd__WndNotification);
#if HAS_FIND_ITEM_WINDOW
	RemoveDetour(CFindItemWnd__WndNotification);
	RemoveDetour(CFindItemWnd__Update);
#endif
	RemoveFindItemMenu();
}

void PulseMQ2AutoInventory()
{
	if (gGameState != GAMESTATE_INGAME)
		return;

	AddFindItemMenu();
	FindItemPulse();
}

} // namespace mq
