/*****************************************************************************
MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License, version 2, as published by
the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
******************************************************************************/

#if !defined(CINTERFACE)
#error /DCINTERFACE
#endif
#ifdef _DEBUG
#define DBG_SPEW
#endif
//#define DEBUG_TRY

#include "MQ2Main.h"
#include "DebugHandler.h"

#include <map>
#include <string>
#include <algorithm>
using namespace std;
std::list<ItemGlobalIndex2> selllist;
std::list<ItemGlobalIndex2> deletelist;
std::list<ItemGlobalIndex2> autobanklist;
std::list<ItemGlobalIndex2> autoinventorylist;

CButtonWnd* gAutoBankButton = nullptr;
bool gStartAutoBanking = false;
bool gStartDeleting = false;
bool gStartSelling = false;
bool bAutoBankInProgress = false;
bool bAutoInventoryInProgress = false;
int gAutoBankTradeSkillItems = 0;
int gCheckBoxFeatureEnabled = 1;
int gColorsFeatureEnabled = 1;
int gAutoBankCollectibleItems = 0;
int gAutoBankQuestItems = 0;
int gAutoInventoryItems = 0;
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
CButtonWnd* pNLMarkedButton = nullptr;
CLabelWnd* pCountLabel = nullptr;
std::map<std::string, CXWnd*> WindowMap;
std::vector<std::string> XmlFiles;

int WinCount = 0;
const int FINDWINDOW_CHECKBOXCOLUMN = 6;

PCHAR szClickNotification[] = { 
	"leftmouse",        // 0
	"leftmouseup",      // 1
	"leftmouseheld",    // 2
	"leftmouseheldup",  // 3
	"rightmouse",       // 4
	"rightmouseup",     // 5
	"rightmouseheld",   // 6
	"rightmouseheldup", // 7
};

struct WindowInfo
{
    std::string Name;
	CXWnd* pWnd = nullptr;
	CXWnd** ppWnd = nullptr;
};

std::map<CXWnd*, WindowInfo> WindowList;

int MarkCol = 0;
int ValueCol = 0;
int BarterValueCol = 0;
int BarterLastSortIndex = 1;
bool BarterLastSortDirection = true;

bool GenerateMQUI();
void DestroyMQUI();

bool PickupItemNew(PCONTENTS pCont)
{
	if (PCHARINFO pCharInfo = GetCharInfo()) {
#ifndef NEWCHARINFO
		if (pCharInfo->vtable2) {
#else
		if (pCharInfo->PcClient_CharacterZoneClient_vfTable) {
#endif
			if (CharacterZoneClient* czc = (CharacterZoneClient*)pCharData1)
			{
				if ((czc && pInvSlotMgr) && (pCursorAttachment && pCursorAttachment->Type == -1/*none*/))
				{
					int slot1 = -1;
					int slot2 = -1;
					bool bFound = czc->FindItemByGuid(pCont->ItemGUID, &slot1, &slot2);
					if (bFound && slot1 > -1)
					{
						if (pCharInfo->CharacterBase_vftable)
						{
							if (CharacterBase* cbase = (CharacterBase*)&pCharInfo->CharacterBase_vftable)
							{
								ItemGlobalIndex IGIndex = cbase->CreateItemGlobalIndex(slot1, slot2);
								ItemIndex IIndex;
								IIndex.Slot1 = IGIndex.Index.Slot1;
								IIndex.Slot2 = IGIndex.Index.Slot2;
								IIndex.Slot3 = IGIndex.Index.Slot3;
								VePointer<CONTENTS> Cont = ((CharacterBase*)cbase)->GetItemPossession(IIndex);
								if (Cont.pObject != nullptr)
								{
								if (pInvSlotMgr->MoveItem(&cbase->CreateItemGlobalIndex(slot1, slot2), &cbase->CreateItemGlobalIndex(33/*HELD*/), false, false))
									{
										pCursorAttachment->Deactivate();
										pCursorAttachment->AttachToCursor(NULL, NULL, 2/*ITEM*/, -1, NULL, NULL);
										if (CDisplay* pDisp = (CDisplay*)pDisplay)
										{
											pDisp->DragItem = TRUE;
										}
										return true;
									}
								}
							}
						}
					}
				}
			}
		}
    }
	return false;
}

int lastsel = -1;
CCheckBoxWnd* pCheck = nullptr;

class CSidlInitHook
{
public:
	void Init_Trampoline(class CXStr* pName, int A);
	void Init_Detour(class CXStr* pName, int A)
	{
		CHAR Name[MAX_STRING] = { 0 };
		if (pName)
			GetCXStr(pName->Ptr, Name, MAX_STRING);

		std::string WindowName = Name;
		MakeLower((WindowName));

		unsigned long N = 0;
		if (WindowMap.find(WindowName) != WindowMap.end())
		{
			WindowInfo wi;
			wi.Name = WindowName;
			wi.pWnd = (CXWnd*)this;
			wi.ppWnd = 0;
			WindowList[(CXWnd*)this] = wi;

			DebugSpew("Updating WndNotification target '%s'", Name);
		}
		else
		{
			WindowInfo wi;
			wi.Name = WindowName;
			wi.pWnd = (CXWnd*)this;
			wi.ppWnd = 0;
			WindowList[(CXWnd*)this] = wi;
			WindowMap[WindowName] = (CXWnd*)this;

			if (Name[0] != '\0')
				DebugSpew("Adding WndNotification target '%s'", Name);
			else
				DebugSpew("Adding WndNotification target FAILED");
		}

		Init_Trampoline(pName, A);
	}

	int CTargetWnd__WndNotification_Tramp(CXWnd*, uint32_t, void*);
	int CTargetWnd__WndNotification_Detour(CXWnd* pWnd, uint32_t uiMessage, void* pData)
	{
		if (gUseTradeOnTarget)
		{
			if (uiMessage == XWM_LCLICK)
			{
				if (PCHARINFO2 pChar2 = GetCharInfo2())
				{
					if (pTarget && pLocalPlayer
						&& ((PSPAWNINFO)pTarget)->SpawnID != ((PSPAWNINFO)pLocalPlayer)->SpawnID
						&& pEverQuest && pChar2->pInventoryArray
						&& (pChar2->pInventoryArray->Inventory.Cursor
							|| pChar2->CursorPlat || pChar2->CursorGold || pChar2->CursorSilver || pChar2->CursorCopper))
					{
						// player has a item or coin on his cursor and clicked targetwindow, he wants to trade with target...
						pEverQuest->LeftClickedOnPlayer(pTarget);
						WeDidStuff();
					}
				}
			}
		}
		return CTargetWnd__WndNotification_Tramp(pWnd, uiMessage, pData);
	}

#if !defined(ROF2EMU) && !defined(UFEMU)
	void CFindItemWnd__Update_Tramp();
	void CFindItemWnd__Update_Detour()
	{
		CFindItemWnd* pFIWnd = (CFindItemWnd*)this;
		CFindItemWnd__Update_Tramp();

		CListWnd* list = (CListWnd*)pFIWnd->GetChildItem("FIW_ItemList");
		if (gCheckBoxFeatureEnabled && list)
		{
			if (MarkCol && list->Columns.Count > MarkCol)
			{
				char szTemp[20];
				sprintf_s(szTemp, "0/%d", list->ItemsArray.Count);
				pCountLabel->CSetWindowText(szTemp);

				// we really need the list to fit to the window so people can actually see this new feature.
				CXRect rectmain = ((CXWnd*)pFIWnd)->GetClientRect();
				CXRect rect = ((CXWnd*)list)->GetClientRect();
				DWORD TotalWidth = 0;

				for (int i = 0; i < list->Columns.Count; i++)
				{
					TotalWidth += list->Columns[i].Width;
				}
				TotalWidth += 20;

				DWORD mainwidth = rectmain.right - rectmain.left;
				int newwidth = 0;

				if (TotalWidth > rect.right - rect.left)
				{
					newwidth = TotalWidth - (rect.right - rect.left);
					rect.right += newwidth;
					rectmain.right += newwidth + 10;
					((CXWnd*)list)->Move(rect, false, false, false, false);
					((CXWnd*)pFIWnd)->Move(rectmain, false, false, false, false);
				}

				// lets borrow a checkbox...
				CControlTemplate* pDisableConnectionTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("ATW_Checkbox");
				if (pDisableConnectionTemplate)
				{
					RECT OldRect = pDisableConnectionTemplate->Rect;
					/*pDisableConnectionTemplate->Rect.left = 21;
					pDisableConnectionTemplate->Rect.top = 2;
					pDisableConnectionTemplate->Rect.right = 32;
					pDisableConnectionTemplate->Rect.bottom = 13;*/
					char* OldName1 = new char[MAX_STRING];
					char* OldScreenName1 = new char[MAX_STRING];
					char* OldController1 = new char[MAX_STRING];
					GetCXStr(pDisableConnectionTemplate->Name, OldName1);
					GetCXStr(pDisableConnectionTemplate->ScreenID, OldScreenName1);
					GetCXStr(pDisableConnectionTemplate->Controller, OldController1);

					SetCXStr(&pDisableConnectionTemplate->Controller, "0");

					char* szTemp2 = new char[MAX_STRING];
					char* szTemp3 = new char[MAX_STRING];
					CXStr Str;

					for (int i = 0; i < list->ItemsArray.Count && i < 900; i++)
					{
						sprintf_s(szTemp2, MAX_STRING, "FIW_CheckBox_%d", i);
						SetCXStr(&pDisableConnectionTemplate->Name, szTemp2);
						SetCXStr(&pDisableConnectionTemplate->ScreenID, szTemp2);

						if (pCheck = (CCheckBoxWnd*)pSidlMgr->CreateXWndFromTemplate((CXWnd*)pFIWnd, pDisableConnectionTemplate))
						{
							pCheck->SetEnabled(true);
							pCheck->SetCheck(false);
							pCheck->SetData(list->GetItemData(i));
							pCheck->SetVisible(true);
							pCheck->SetActive(true);
							pCheck->SetClickThroughMenuItemStatus(true);
							pCheck->SetController(0x00000000);
							pCheck->SetShowClickThroughMenuItem(true);
							pCheck->SetLocation({ 4, 0, 16, 12 });
							pCheck->IndicatorValue = 0;
							list->GetItemText(&Str, i, 1);
							GetCXStr(Str.Ptr, szTemp2);
							sprintf_s(szTemp3, MAX_STRING, "Check to mark %s for Action.(%d)", szTemp2, i);

							// todo check this
							pCheck->SetTooltip(szTemp3);
							// this works before private fix((CXStr*)&pCheck->Tooltip)->SetString(szTemp3, strlen(szTemp3));
							list->SetItemWnd(i, MarkCol, pCheck);

							if (ItemGlobalIndex* gi = (ItemGlobalIndex*)pFIWnd->gi[(int)pCheck->GetData()])
							{
								if (PCHARINFO pCharInfo = GetCharInfo())
								{
									if (CharacterBase* cb = (CharacterBase*)& pCharInfo->CharacterBase_vftable)
									{
										VePointer<CONTENTS> ptr = cb->GetItemByGlobalIndex(*gi);
										if (ptr.pObject)
										{
											if (PITEMINFO pItem = GetItemFromContents(ptr.pObject))
											{
												if (gColorsFeatureEnabled)
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

												if (pItem->Cost > 0)
												{
													int sellprice = ((EQ_Item*)ptr.pObject)->ValueSellMerchant((float)1.05, 1);
													DWORD cp = sellprice;
													DWORD sp = cp / 10; cp = cp % 10;
													DWORD gp = sp / 10; sp = sp % 10;
													DWORD pp = gp / 10; gp = gp % 10;
													szTemp3[0] = '\0';

													if (pp > 0)
													{
														sprintf_s(szTemp2, MAX_STRING, " %dpp", pp);
														strcat_s(szTemp3, MAX_STRING, szTemp2);
													}
													if (gp > 0)
													{
														sprintf_s(szTemp2, MAX_STRING, " %dgp", gp);
														strcat_s(szTemp3, MAX_STRING, szTemp2);
													}
													if (sp > 0)
													{
														sprintf_s(szTemp2, MAX_STRING, " %dsp", sp);
														strcat_s(szTemp3, MAX_STRING, szTemp2);
													}
													if (cp > 0)
													{
														sprintf_s(szTemp2, MAX_STRING, " %dcp", cp);
														strcat_s(szTemp3, MAX_STRING, szTemp2);
													}
												}
												else
												{
													strcpy_s(szTemp3, MAX_STRING, "");
												}

												list->SetItemText(i, ValueCol, &CXStr(szTemp3));
											}
										}
									}
								}
							}
						}
					}

					delete szTemp2;
					delete szTemp3;

					pDisableConnectionTemplate->Rect = OldRect;
					SetCXStr(&pDisableConnectionTemplate->Name, OldName1);
					SetCXStr(&pDisableConnectionTemplate->ScreenID, OldScreenName1);
					SetCXStr(&pDisableConnectionTemplate->Controller, OldController1);

					delete OldName1;
					delete OldScreenName1;
					delete OldController1;

					if (list->SortCol == 7)
					{
						list->Sort();
					}
				}
			}
		}
	}

	int GetMoneyFromString(char* str)
	{
		char* szLabel1 = new char[MAX_STRING];
		strcpy_s(szLabel1, MAX_STRING, str);

		int pp = 0;
		int gp = 0;
		int sp = 0;
		int cp = 0;

		if (char* pDest = strstr(szLabel1, "pp"))
		{
			pDest[0] = '\0';
			pp = atoi(szLabel1);
			strcpy_s(szLabel1, MAX_STRING, &pDest[2]);
		}
		else if (char* pDest = strstr(szLabel1, "p"))
		{
			pDest[0] = '\0';
			pp = atoi(szLabel1);
			strcpy_s(szLabel1, MAX_STRING, &pDest[1]);
		}
		if (char* pDest = strstr(szLabel1, "gp"))
		{
			pDest[0] = '\0';
			gp = atoi(szLabel1);
			strcpy_s(szLabel1, MAX_STRING, &pDest[2]);
		}
		else if (char* pDest = strstr(szLabel1, "g"))
		{
			pDest[0] = '\0';
			gp = atoi(szLabel1);
			strcpy_s(szLabel1, MAX_STRING, &pDest[1]);
		}
		if (char* pDest = strstr(szLabel1, "sp"))
		{
			pDest[0] = '\0';
			sp = atoi(szLabel1);
			strcpy_s(szLabel1, MAX_STRING, &pDest[2]);
		}
		else if (char* pDest = strstr(szLabel1, "s"))
		{
			pDest[0] = '\0';
			sp = atoi(szLabel1);
			strcpy_s(szLabel1, MAX_STRING, &pDest[1]);
		}
		if (char* pDest = strstr(szLabel1, "cp"))
		{
			pDest[0] = '\0';
			cp = atoi(szLabel1);
			strcpy_s(szLabel1, MAX_STRING, &pDest[2]);
		}
		else if (char* pDest = strstr(szLabel1, "c"))
		{
			pDest[0] = '\0';
			cp = atoi(szLabel1);
			strcpy_s(szLabel1, MAX_STRING, &pDest[1]);
		}

		delete szLabel1;
		int total = (pp * 1000) + (gp * 100) + (sp * 10) + cp;
		return total;
	}
	int CBarterWnd__WndNotification_Tramp(CXWnd*, uint32_t, void*);
	int CBarterWnd__WndNotification_Detour(CXWnd* pWnd, uint32_t uiMessage, void* pData)
	{
		if (uiMessage == XWM_COLUMNCLICK)
		{
			if (pWnd == ((CXWnd*)this)->GetChildItem("BTR_BuyLineList"))
			{
				CListWnd *pListWnd = (CListWnd *)pWnd;
				int colindex = (int)pData;
				if (colindex == 1)//icons
					colindex = 2;//so just sort by name...
				if (colindex != 0)
				{
					if (pListWnd->SortCol == colindex)
					{
						pListWnd->bSortAsc = !pListWnd->bSortAsc;
					}
					else
					{
						pListWnd->SortCol = colindex;
						pListWnd->bSortAsc = true;
					}
					BarterLastSortDirection = pListWnd->bSortAsc;
					BarterLastSortIndex = pListWnd->SortCol;
					pListWnd->Sort();
					return 1;
				}
			}
		}
		else if (uiMessage == XWM_SORTREQUEST)
		{
			if (pWnd == ((CXWnd*)this)->GetChildItem("BTR_BuyLineList"))
			{
				SListWndSortInfo *pSI = (SListWndSortInfo *)pData;

				CHAR *szLabel1 = new CHAR[MAX_STRING];
				CHAR *szLabel2 = new CHAR[MAX_STRING];
				switch (pSI->SortCol)
				{
				case 2://column 2 item name
				{
					GetCXStr(pSI->StrLabel1, szLabel1);
					GetCXStr(pSI->StrLabel2, szLabel2);
					pSI->SortResult = _stricmp(szLabel1, szLabel2);
					break;
				}
				case 3://Count
				{
					GetCXStr(pSI->StrLabel1, szLabel1);
					int int1 = atoi(szLabel1);
					GetCXStr(pSI->StrLabel2, szLabel2);
					int int2 = atoi(szLabel2);

					if (int1 > int2)
						pSI->SortResult = -1;
					else if (int1 < int2)
						pSI->SortResult = 1;
					else
						pSI->SortResult = 0;
					break;
				}
				case 4://Offering
				{
					GetCXStr(pSI->StrLabel1, szLabel1);
					int int1 = GetMoneyFromString(szLabel1);
					GetCXStr(pSI->StrLabel2, szLabel2);
					int int2 = GetMoneyFromString(szLabel2);

					if (int1 > int2)
						pSI->SortResult = -1;
					else if (int1 < int2)
						pSI->SortResult = 1;
					else
						pSI->SortResult = 0;
					break;
				}
				}
				delete szLabel1;
				delete szLabel2;
				return 1;
			}
		}
		return CBarterWnd__WndNotification_Tramp(pWnd, uiMessage, pData);
	}
	int CBarterSearchWnd__WndNotification_Tramp(CXWnd*, uint32_t, void*);
	int CBarterSearchWnd__WndNotification_Detour(CXWnd* pWnd, uint32_t uiMessage, void* pData)
	{
		if (uiMessage == XWM_RCLICK)
		{
			if (pWnd == ((CXWnd*)this)->GetChildItem("BTRSRCH_InventoryList"))
			{
				CBarterSearchWnd* pBSWnd = (CBarterSearchWnd*)this;
				CListWnd *pListWnd = (CListWnd *)pWnd;
				int selIndex = pListWnd->GetCurSel();
				if (selIndex != -1)
				{
					int searchIndex = (int)pListWnd->GetItemData(selIndex);
					if (searchIndex < pBSWnd->InventoryItemsArray.Count)
					{
						if (PCONTENTS pCont = FindItemByID(pBSWnd->InventoryItemsArray[searchIndex].ItemID))
						{
							bool IsShiftPressed = (pWndMgr->GetKeyboardFlags() & 1U) != 0;
							VePointer<CONTENTS>cont;
							cont.pObject = pCont;
							pItemDisplayManager->ShowItem(cont, !IsShiftPressed);
						}
					}
				}
				return 1;
			}
		}
		else if (uiMessage == XWM_COLUMNCLICK)
		{
			if (pWnd == ((CXWnd*)this)->GetChildItem("BTRSRCH_InventoryList"))
			{
				CListWnd *pListWnd = (CListWnd *)pWnd;
				int colindex = (int)pData;
				if (colindex == 0)
					colindex = 1;
				if (pListWnd->SortCol == colindex)
				{
					pListWnd->bSortAsc = !pListWnd->bSortAsc;
				}
				else
				{
					pListWnd->SortCol = colindex;
					pListWnd->bSortAsc = true;
				}
				BarterLastSortDirection = pListWnd->bSortAsc;
				BarterLastSortIndex = pListWnd->SortCol;
				pListWnd->Sort();
				return 1;
			}
		}
		else if (uiMessage == XWM_SORTREQUEST)
		{
			if (pWnd == ((CXWnd*)this)->GetChildItem("BTRSRCH_InventoryList"))
			{
				SListWndSortInfo *pSI = (SListWndSortInfo *)pData;

				CHAR *szLabel1 = new CHAR[MAX_STRING];
				CHAR *szLabel2 = new CHAR[MAX_STRING];
				switch (pSI->SortCol)
				{
				case 1://column 2 item name
				{
					GetCXStr(pSI->StrLabel1, szLabel1);
					GetCXStr(pSI->StrLabel2, szLabel2);
					pSI->SortResult = _stricmp(szLabel1, szLabel2);
					break;
				}
				case 2://Qty
				{
					GetCXStr(pSI->StrLabel1, szLabel1);
					int int1 = atoi(szLabel1);
					GetCXStr(pSI->StrLabel2, szLabel2);
					int int2 = atoi(szLabel2);

					if (int1 > int2)
						pSI->SortResult = -1;
					else if (int1 < int2)
						pSI->SortResult = 1;
					else
						pSI->SortResult = 0;
					break;
				}
				case 3://Value
				{
					GetCXStr(pSI->StrLabel1, szLabel1);
					int int1 = GetMoneyFromString(szLabel1);
					GetCXStr(pSI->StrLabel2, szLabel2);
					int int2 = GetMoneyFromString(szLabel2);

					if (int1 > int2)
						pSI->SortResult = -1;
					else if (int1 < int2)
						pSI->SortResult = 1;
					else
						pSI->SortResult = 0;
					break;
				}
				default:
					delete szLabel1;
					delete szLabel2;
					return 0;
				}
				delete szLabel1;
				delete szLabel2;
				return 1;
			}
		}
		return CBarterSearchWnd__WndNotification_Tramp(pWnd, uiMessage, pData);
	}
	void CBarterSearchWnd__UpdateInventoryList_Tramp();
	void CBarterSearchWnd__UpdateInventoryList_Detour()
	{
		CBarterSearchWnd* pBSWnd = (CBarterSearchWnd*)this;
		CBarterSearchWnd__UpdateInventoryList_Tramp();
		if (CListWnd* list = (CListWnd*)((CXWnd*)this)->GetChildItem("BTRSRCH_InventoryList"))
		{
			if (BarterValueCol && list->Columns.Count > BarterValueCol)
			{
				/* we really need the list to fit to the window so people can actually see this new feature.
				CXRect rectmain = ((CXWnd*)this)->GetClientRect();
				CXWnd* layout = (CXWnd*)((CXWnd*)this)->GetChildItem("BTRSRCH_Layout");
				//CXRect rectmain = ((CXWnd*)layout)->GetClientRect();
				CXRect rect = ((CXWnd*)list)->GetClientRect();
				DWORD TotalWidth = 0;
				for (int i = 0; i < list->Columns.Count; i++)
				{
					TotalWidth += list->Columns[i].Width;
				}
				TotalWidth += 20;

				DWORD mainwidth = rectmain.right - rectmain.left;
				int newwidth = 0;

				if (TotalWidth > rect.right - rect.left)
				{
					newwidth = TotalWidth - (rect.right - rect.left);
					rect.right += newwidth;
					rectmain.right += newwidth + 10;
					((CXWnd*)list)->Move(rect, true, true, true, true);
					//((CXWnd*)layout)->Move(rectmain, true, true, true, true);
					//((CXWnd*)this)->Move(rectmain, false, false, false, false);
				}*/
				char* szTemp2 = new char[MAX_STRING];
				char* szTemp3 = new char[MAX_STRING];

				for (int i = 0; i < list->ItemsArray.Count && i < 900; i++)
				{
					int realindex = (int)list->GetItemData(i);
					if (realindex < pBSWnd->InventoryItemsArray.Count)
					{
						if (PCONTENTS pCont = FindItemByID(pBSWnd->InventoryItemsArray[realindex].ItemID))
						{
							if (PITEMINFO pItem = GetItemFromContents(pCont))
							{
								/*maybe later it works but I don't have time to make a stting for it.
								if (gColorsFeatureEnabled)
								{
									if (pItem->TradeSkills)
									{
										list->SetItemColor(i, 1, 0xFFFF00FF);
									}
									if (pItem->QuestItem)
									{
										list->SetItemColor(i, 1, 0xFFFFFF00);
									}
								}*/

								if (pItem->Cost > 0)
								{
									int sellprice = ((EQ_Item*)pCont)->ValueSellMerchant((float)1.05, 1);
									DWORD cp = sellprice;
									DWORD sp = cp / 10; cp = cp % 10;
									DWORD gp = sp / 10; sp = sp % 10;
									DWORD pp = gp / 10; gp = gp % 10;
									szTemp3[0] = '\0';

									if (pp > 0)
									{
										sprintf_s(szTemp2, MAX_STRING, " %dp", pp);
										strcat_s(szTemp3, MAX_STRING, szTemp2);
									}
									if (gp > 0)
									{
										sprintf_s(szTemp2, MAX_STRING, " %dg", gp);
										strcat_s(szTemp3, MAX_STRING, szTemp2);
									}
									if (sp > 0)
									{
										sprintf_s(szTemp2, MAX_STRING, " %ds", sp);
										strcat_s(szTemp3, MAX_STRING, szTemp2);
									}
									if (cp > 0)
									{
										sprintf_s(szTemp2, MAX_STRING, " %dc", cp);
										strcat_s(szTemp3, MAX_STRING, szTemp2);
									}
								}
								else
								{
									strcpy_s(szTemp3, MAX_STRING, "");
								}

								list->SetItemText(i, BarterValueCol, &CXStr(szTemp3));
							}
						}
					}
				}
				delete szTemp2;
				delete szTemp3;
				list->bSortAsc = BarterLastSortDirection;
				list->SortCol = BarterLastSortIndex;
				list->Sort();
			}
		}
	}
	int CFindItemWnd__WndNotification_Tramp(CXWnd*, uint32_t, void*);
	int CFindItemWnd__WndNotification_Detour(CXWnd* pWnd, uint32_t uiMessage, void* pData)
	{
		if (uiMessage == XWM_SORTREQUEST)
		{
			CFindItemWnd* wnd = (CFindItemWnd*)this;
			if (pWnd == (CXWnd*)wnd->FIW_ItemList)
			{
				if (SListWndSortInfo* pSI = (SListWndSortInfo *)pData)
				{
					char* szLabel1 = new char[MAX_STRING];
					char* szLabel2 = new char[MAX_STRING];

					switch (pSI->SortCol)
					{
					case 7:
					{
						GetCXStr(pSI->StrLabel1, szLabel1);
						int int1 = GetMoneyFromString(szLabel1);
						GetCXStr(pSI->StrLabel2, szLabel2);
						int int2 = GetMoneyFromString(szLabel2);

						if (int1 > int2)
							pSI->SortResult = -1;
						else if (int1 < int2)
							pSI->SortResult = 1;
						else
							pSI->SortResult = 0;
					}
					break;
					}

					delete szLabel1;
					delete szLabel2;
					return 0;
				}
			}
		}
		else if (uiMessage == XWM_MENUSELECT)
		{
			int ItemID = (int)pData;
			int iItemID = 0;

			if (CContextMenu* pContextMenu = (CContextMenu*)pWnd)
			{
				POINT pt;
				pt.x = ((PCXWNDMGR)pWndMgr)->MousePoint.x;
				pt.y = ((PCXWNDMGR)pWndMgr)->MousePoint.y;
				iItemID = ((CListWnd*)pContextMenu)->GetItemAtPoint(&pt);
			}

			switch (ItemID)
			{
				case 50:
				if (gCheckBoxFeatureEnabled)
				{
					gCheckBoxFeatureEnabled = 0;
					WritePrivateProfileString("CoolBoxes", "CheckBoxFeatureEnabled", "0", gszINIFilename);

					if (pNLMarkedButton)
							pNLMarkedButton->SetVisible(false);
					if (pCountLabel)
							pCountLabel->SetVisible(false);
					
					if (CListWnd* list = (CListWnd*)((CXWnd*)this)->GetChildItem("FIW_ItemList"))
					{
						list->Selected = 0xFF004040;
					}
				}
				else
				{
					gCheckBoxFeatureEnabled = 1;
					WritePrivateProfileString("CoolBoxes", "CheckBoxFeatureEnabled", "1", gszINIFilename);

					if (pNLMarkedButton)
							pNLMarkedButton->SetVisible(true);
					if (pCountLabel)
							pCountLabel->SetVisible(true);
					
					if (CListWnd* list = (CListWnd*)((CXWnd*)this)->GetChildItem("FIW_ItemList"))
					{
						if (list->Columns.Count > FINDWINDOW_CHECKBOXCOLUMN)
						{
							if (SListWndColumn_RO* col = &list->Columns[FINDWINDOW_CHECKBOXCOLUMN])
							{
								col->pTextureAnim = pUnChecked;
							}
						}
					}
				}

				CheckBoxMenu->CheckMenuItem(iItemID, gCheckBoxFeatureEnabled);
				pFindItemWnd->Update();
				break;

				case 51:
					if (gColorsFeatureEnabled)
					{
						gColorsFeatureEnabled = 0;
						WritePrivateProfileString("CoolBoxes", "ColorsFeatureEnabled", "0", gszINIFilename);
					}
				else
				{
						gColorsFeatureEnabled = 1;
						WritePrivateProfileString("CoolBoxes", "ColorsFeatureEnabled", "1", gszINIFilename);
					}

					CheckBoxMenu->CheckMenuItem(iItemID, gColorsFeatureEnabled);
					pFindItemWnd->Update();
					break;
			}
		}
		else if (uiMessage == XWM_RCLICK)
		{	
			if (CButtonWnd* FIW_DestroyItem = (CButtonWnd*)((CXWnd*)this)->GetChildItem("FIW_DestroyItem"))
			{
				if ((CButtonWnd*)pWnd == FIW_DestroyItem || (CButtonWnd*)pWnd == pNLMarkedButton || (CLabelWnd*)pWnd == pCountLabel)
				{
					if (pContextMenuManager)
					{
						CXPoint Loc;
						Loc.X = ((PCXWNDMGR)pWndMgr)->MousePoint.x;
						Loc.Y = ((PCXWNDMGR)pWndMgr)->MousePoint.y;

						// work in progress -eqmule
						pContextMenuManager->PopupMenu(OurCheckBoxMenuIndex, Loc, (CXWnd*)this);
					}

					return 0;
				}
			}
		}
		else if (gCheckBoxFeatureEnabled)
		{
			if (uiMessage == XWM_LCLICK)
			{
				// for our checkboxes, they should parent notify to this func...
				int itemclicked = (int)pData;
				if (CListWnd* list = (CListWnd*)((CXWnd*)this)->GetChildItem("FIW_ItemList"))
				{
					CXMLData* data = pWnd->GetXMLData();
					if (list->Columns.Count > FINDWINDOW_CHECKBOXCOLUMN)
					{
						SListWndColumn_RO* col = &list->Columns[FINDWINDOW_CHECKBOXCOLUMN];

						if (bool bCheckBox = pWnd->IsType(WRT_CHECKBOXWND))
						{
							bool bChecked = ((CCheckBoxWnd*)pWnd)->Checked;
							int Selected = 0;
							int Checked = 0;

							for (int i = 0; i < list->ItemsArray.Count; i++)
							{
								if (CButtonWnd* button = (CButtonWnd*)list->GetItemWnd(i, FINDWINDOW_CHECKBOXCOLUMN))
								{
									if (button->Checked)
										Checked++;

									if (button == pWnd)
									{
										list->ItemsArray[i].bSelected = bChecked;

										if (bChecked == true)
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
										if (button->Checked == false)
										{
											list->ItemsArray[i].bSelected = false;
										}
										Selected++;
									}
								}
							}

							char szTemp[26];
							sprintf_s(szTemp, "%d/%d", Checked, list->ItemsArray.Count);
							pCountLabel->CSetWindowText(szTemp);

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
								if (ItemGlobalIndex* igg = (ItemGlobalIndex*)((CFindItemWnd*)this)->gi[dta])
								{
									pMerchantWnd->SelectBuySellSlot(igg, igg->Index.Slot1);
								}
							}

							int Checked = 0;
							for (int i = 0; i < list->ItemsArray.Count; i++)
							{
								if (CButtonWnd* button = (CButtonWnd*)list->GetItemWnd(i, FINDWINDOW_CHECKBOXCOLUMN))
								{
									if (button->Checked)
									{
										list->ItemsArray[i].bSelected = true;
										Checked++;
									}
								}
							}

							char szTemp[26];
							sprintf_s(szTemp, "%d/%d", Checked, list->ItemsArray.Count);
							pCountLabel->CSetWindowText(szTemp);

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

				if (colindex == FINDWINDOW_CHECKBOXCOLUMN)
				{
					CListWnd* list = (CListWnd*)((CXWnd*)this)->GetChildItem("FIW_ItemList");
					if (list)
					{
						if (list->Columns.Count > FINDWINDOW_CHECKBOXCOLUMN)
						{
							list->CurSel = -1;
							list->Selected = 0xFF004040;
							SListWndColumn_RO* col = &list->Columns[FINDWINDOW_CHECKBOXCOLUMN];
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
								if (CButtonWnd* button = (CButtonWnd*)list->GetItemWnd(i, FINDWINDOW_CHECKBOXCOLUMN))
								{
									if (selected > 1)
									{
										if (list->ItemsArray[i].bSelected)
										{
											button->Checked = checked;
										}
									}
									else
									{
										button->Checked = checked;
									}

									if (button->Checked == true)
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
								pCountLabel->CSetWindowText(szTemp);

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
				CButtonWnd* FIW_DestroyItem = (CButtonWnd*)((CXWnd*)this)->GetChildItem("FIW_DestroyItem");
				int clickedrow = (int)pData;

				if (CListWnd* list = (CListWnd*)((CXWnd*)this)->GetChildItem("FIW_ItemList"))
				{
					if (list->Columns.Count > FINDWINDOW_CHECKBOXCOLUMN)
					{
						if (FIW_DestroyItem && (CXWnd*)FIW_DestroyItem == pWnd)
						{
							if (!deletelist.empty())
								return 0;

							if (PCHARINFO2 pChar2 = GetCharInfo2())
							{
								// if we have something on cursor we let eq handle the destroy
								if (pChar2->pInventoryArray && pChar2->pInventoryArray->Inventory.Cursor == NULL)
								{
									// if we have something on cursor we let eq handle the destroy
									// IF have something checked... AND they clicked the destroy item button... we go... their fault if they do this.
									CXStr Str;
									char* szTemp = new char[MAX_STRING];

									for (int i = 0; i < list->ItemsArray.Count; i++)
									{
										if (CButtonWnd* button = (CButtonWnd*)list->GetItemWnd(i, FINDWINDOW_CHECKBOXCOLUMN))
										{
											if (button->Checked == true)
											{
												SListWndLine_RO item = list->ItemsArray[i];
												list->GetItemText(&Str, i, 1);
												int dta = (int)list->GetItemData(i);
												GetCXStr(Str.Ptr, szTemp);

												if (CFindItemWnd* pFIWnd2 = (CFindItemWnd*)this)
												{
													if (ItemGlobalIndex2* igg = (ItemGlobalIndex2*)pFIWnd2->gi[dta])
													{
														deletelist.push_back(*igg);
													}
												}
											}
										}
									}

									delete szTemp;

									if (SListWndColumn_RO* col = &list->Columns[FINDWINDOW_CHECKBOXCOLUMN])
									{
										col->pTextureAnim = pUnChecked;
									}

									if (!deletelist.empty())
										gStartDeleting = true;

									return 1;
								}
							}
						}
						else if ((CXWnd*)pNLMarkedButton == pWnd)
						{
							if (pMerchantWnd && pMerchantWnd->IsVisible())
							{
								if (!selllist.empty())
									return 0;
							}

							if (list)
							{
								for (int i = 0; i < list->ItemsArray.Count; i++)
								{
									if (CButtonWnd* button = (CButtonWnd*)list->GetItemWnd(i, FINDWINDOW_CHECKBOXCOLUMN))
									{
										if (button->Checked)
										{
											int dta = (int)list->GetItemData(i);

											if (CFindItemWnd* pFIWnd2 = (CFindItemWnd*)this)
											{
												if (ItemGlobalIndex* gi = (ItemGlobalIndex*)pFIWnd2->gi[dta])
												{
													if (PCHARINFO pCharInfo = GetCharInfo())
													{
														if (CharacterBase* cb = (CharacterBase*)& pCharInfo->CharacterBase_vftable)
														{
															VePointer<CONTENTS> ptr = cb->GetItemByGlobalIndex(*gi);
															if (ptr.pObject)
															{
																if (PITEMINFO pItem = GetItemFromContents(ptr.pObject))
																{
																	if (pMerchantWnd && pMerchantWnd->IsVisible())
																	{
																		WriteChatf("[%d] Adding %s to Sell List", i, pItem->Name);
																		ItemGlobalIndex2* igg = (ItemGlobalIndex2*)gi;
																		selllist.push_back(*igg);
																	}
																	else
																	{
																	WriteChatf("[%d] Marking %s as Never Loot", i, pItem->Name);
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
										}
									}
								}
							}

								if (!selllist.empty())
									gStartSelling = true;
							}
							return 1;
						}
					}
				}
			}
		}
		else if (!gCheckBoxFeatureEnabled)
		{
			if (CListWnd* list = (CListWnd*)((CXWnd*)this)->GetChildItem("FIW_ItemList"))
			{
				if (list->Columns.Count > FINDWINDOW_CHECKBOXCOLUMN)
				{
					if (SListWndColumn_RO* col = &list->Columns[FINDWINDOW_CHECKBOXCOLUMN])
					{
						col->pTextureAnim = 0;
					}
				}
			}
		}

		return CFindItemWnd__WndNotification_Tramp(pWnd, uiMessage, pData);
	}
#endif

	int CBankWnd__WndNotification_Tramp(CXWnd*, unsigned __int32, void*);
	int CBankWnd__WndNotification_Detour(CXWnd* pWnd, unsigned int uiMessage, void* pData)
	{
		// we use this to intercept the menu messages for our autobank button extension
		if (((CBankWnd*)this)->AutoButton == pWnd)
		{
			if (gAutoBankButton != pWnd)
				gAutoBankButton = (CButtonWnd*)pWnd;

			if (gAutoBankButton)
			{
				switch (uiMessage)
				{
					case XWM_LCLICK:
						if (PCHARINFO2 pChar2 = GetCharInfo2())
						{
							if (pChar2->pInventoryArray && pChar2->pInventoryArray->Inventory.Cursor == 0)
							{
								if (!gAutoBankTradeSkillItems && !gAutoBankCollectibleItems && !gAutoBankQuestItems)
								{
									gAutoBankButton->Checked = 0;
								}
								else
								{
									gAutoBankButton->Checked = 1;
								}
							}
						}
						break;

					case XWM_LMOUSEUP:
						if (PCHARINFO2 pChar2 = GetCharInfo2())
						{
							if (pChar2->pInventoryArray && pChar2->pInventoryArray->Inventory.Cursor == 0)
							{
								if (!gAutoBankTradeSkillItems && !gAutoBankCollectibleItems && !gAutoBankQuestItems)
								{
									WriteChatf("\ay[AUTOBANK FILTER NOT CONFIGURED]\ax AutoBank Filters where empty there is nothing selected for moving, rightclick the autobank button to select filters.\n");
									gAutoBankButton->Checked = 0;
									break;
								}

								if (!gStartAutoBanking)
								{
								// user leftclicked the autobank button and nothing on cursor
								// we will autobank from inventory instead and pick items he wants
								// by using his menu settings.
									gStartAutoBanking = true;
								WriteChatf("\ay[Auto%s started. Please wait...]\ax", gAutoInventoryItems ? "inventory" : "Bank");
								}
								else
								{
									Beep(1000, 100);
								WriteChatf("\ar[Auto%s ALREADY in Progress, please wait for it to finish...]\ax", gAutoInventoryItems ? "inventory" : "Bank");
									return 0;
								}
							}
						}
						break;

					case XWM_RCLICK:
						if (pContextMenuManager)
						{
							CXPoint Loc;
							Loc.X = ((PCXWNDMGR)pWndMgr)->MousePoint.x;
							Loc.Y = ((PCXWNDMGR)pWndMgr)->MousePoint.y;

						// work in progress -eqmule
							pContextMenuManager->PopupMenu(OurDefaultMenuIndex, Loc, (CXWnd*)this);
						}
						break;
				};
			}
		}
		else if (uiMessage == XWM_MENUSELECT)
		{
			int ItemID = (int)pData;
			int iItemID = 0;

			if (CContextMenu* pContextMenu = (CContextMenu*)pWnd)
			{
				POINT pt;
				pt.x = ((PCXWNDMGR)pWndMgr)->MousePoint.x;
				pt.y = ((PCXWNDMGR)pWndMgr)->MousePoint.y;
				iItemID = ((CListWnd*)pContextMenu)->GetItemAtPoint(&pt);
			}

			switch (ItemID)
			{
			case 50:
				if (gAutoBankTradeSkillItems)
				{
					gAutoBankTradeSkillItems = 0;
					WritePrivateProfileString("AutoBank", "AutoBankTradeSkillItems", "0", gszINIFilename);
				}
				else
				{
					gAutoBankTradeSkillItems = 1;
					WritePrivateProfileString("AutoBank", "AutoBankTradeSkillItems", "1", gszINIFilename);
				}

				AutoBankMenu->CheckMenuItem(iItemID, gAutoBankTradeSkillItems);
				break;

			case 51:
				if (gAutoBankCollectibleItems)
				{
					gAutoBankCollectibleItems = 0;
					WritePrivateProfileString("AutoBank", "AutoBankCollectibleItems", "0", gszINIFilename);
				}
				else
				{
					gAutoBankCollectibleItems = 1;
					WritePrivateProfileString("AutoBank", "AutoBankCollectibleItems", "1", gszINIFilename);
				}

				AutoBankMenu->CheckMenuItem(iItemID, gAutoBankCollectibleItems);
				break;

			case 52:
				if (gAutoBankQuestItems)
				{
					gAutoBankQuestItems = 0;
					WritePrivateProfileString("AutoBank", "AutoBankQuestItems", "0", gszINIFilename);
				}
				else
				{
					gAutoBankQuestItems = 1;
					WritePrivateProfileString("AutoBank", "AutoBankQuestItems", "1", gszINIFilename);
				}

				AutoBankMenu->CheckMenuItem(iItemID, gAutoBankQuestItems);
				break;

			case 53:
				if (gAutoInventoryItems)
				{
					gAutoInventoryItems = 0;
					WritePrivateProfileString("AutoBank", "AutoInventoryItems", "0", gszINIFilename);
				}
				else
				{
					gAutoInventoryItems = 1;
					WritePrivateProfileString("AutoBank", "AutoInventoryItems", "1", gszINIFilename);
				}

				AutoBankMenu->CheckMenuItem(iItemID, gAutoInventoryItems);
				break;
			};
		}

		return CBankWnd__WndNotification_Tramp(pWnd, uiMessage, pData);
	}

	int CSidlScreenWnd__WndNotification_Tramp(CXWnd*, uint32_t, void*);
	int CSidlScreenWnd__WndNotification_Detour(CXWnd* pWnd, uint32_t uiMessage, void* pData)
	{
		if (uiMessage == XWM_LINK)
		{
		}

		return CSidlScreenWnd__WndNotification_Tramp(pWnd, uiMessage, pData);
	}
};
DETOUR_TRAMPOLINE_EMPTY(void CSidlInitHook::Init_Trampoline(CXStr*, int));
DETOUR_TRAMPOLINE_EMPTY(int CSidlInitHook::CTargetWnd__WndNotification_Tramp(CXWnd*, unsigned __int32, void*));
DETOUR_TRAMPOLINE_EMPTY(int CSidlInitHook::CBankWnd__WndNotification_Tramp(CXWnd*, unsigned __int32, void*));
DETOUR_TRAMPOLINE_EMPTY(int CSidlInitHook::CBarterSearchWnd__WndNotification_Tramp(CXWnd*, unsigned __int32, void*));
DETOUR_TRAMPOLINE_EMPTY(void CSidlInitHook::CBarterSearchWnd__UpdateInventoryList_Tramp());
DETOUR_TRAMPOLINE_EMPTY(int CSidlInitHook::CBarterWnd__WndNotification_Tramp(CXWnd*, unsigned __int32, void*));
#if !defined(ROF2EMU) && !defined(UFEMU)
DETOUR_TRAMPOLINE_EMPTY(int CSidlInitHook::CFindItemWnd__WndNotification_Tramp(CXWnd*, unsigned __int32, void*));
DETOUR_TRAMPOLINE_EMPTY(void CSidlInitHook::CFindItemWnd__Update_Tramp());
#endif
DETOUR_TRAMPOLINE_EMPTY(int CSidlInitHook::CSidlScreenWnd__WndNotification_Tramp(CXWnd*, unsigned __int32, void*));

class CXWndManagerHook
{
public:
	int RemoveWnd_Trampoline(class CXWnd*);
	int RemoveWnd_Detour(class CXWnd* pWnd)
	{
		if (pWnd)
    	{
			auto N = WindowList.find(pWnd);
			if (N != WindowList.end())
			{
				std::string Name = N->second.Name;
				MakeLower(Name);

				if (WindowMap.find(Name) != WindowMap.end())
				{
					WindowMap.erase(Name);
				}

				WindowList.erase(N);
			}
		}
        return RemoveWnd_Trampoline(pWnd);
    }
};
DETOUR_TRAMPOLINE_EMPTY(int CXWndManagerHook::RemoveWnd_Trampoline(class CXWnd*));

class CXMLSOMDocumentBaseHook
{
public:
	int XMLRead(CXStr* A, CXStr* B, CXStr* C, CXStr* D)
    {
		char Temp[MAX_STRING] = { 0 };
		GetCXStr(C->Ptr, Temp, MAX_STRING);
		DebugSpew("XMLRead(%s)", Temp);

		// When EQ tries to read EQUI.xml, generate MQUI.xml instead
		// and redirect the read to that file.
		if (!_stricmp("EQUI.xml", Temp))
        {
            if (GenerateMQUI())
            {
				SetCXStr(&C->Ptr, "MQUI.xml");
				int Ret = XMLRead_Trampoline(A, B, C, D);
                DestroyMQUI();
                return Ret;
            }
        }
		return XMLRead_Trampoline(A, B, C, D);
	}
	int XMLRead_Trampoline(CXStr* A, CXStr* B, CXStr* C, CXStr* D);
};
DETOUR_TRAMPOLINE_EMPTY(int CXMLSOMDocumentBaseHook::XMLRead_Trampoline(CXStr* A, CXStr* B, CXStr* C, CXStr* D));

bool DoesFileExist(const char* filename)
{
	char localfile[MAX_PATH];
	sprintf_s(localfile, "%s\\%s", gszINIPath, filename);
	//if (strstr(filename, ".tga"))
	//	Sleep(0);
	if (_FileExists(localfile))
		return true;

	return _FileExists(filename);
}
DETOUR_TRAMPOLINE_EMPTY(bool DoesFileExist_Trampoline(const char*));

class CMemoryMappedFile
{
public:
	bool SetFile_Detour(const char* filename, bool unk8, unsigned int unkC)
	{
		char localfile[MAX_PATH];
		sprintf_s(localfile, "%s\\%s", gszINIPath, filename);
		//if (strstr(filename, ".tga"))
		//	Sleep(0);
		if (_FileExists(localfile))
			return SetFile_Trampoline(localfile, unk8, unkC);

		return SetFile_Trampoline(filename, unk8, unkC);
    }

	bool SetFile_Trampoline(const char*, bool, unsigned int);
};
DETOUR_TRAMPOLINE_EMPTY(bool CMemoryMappedFile::SetFile_Trampoline(const char*, bool, unsigned int));

// Hook for fopen in eqgraphics.dll
DETOUR_TRAMPOLINE_EMPTY(FILE* fopen_eqgraphics_trampoline(const char* filename, const char* mode));
FILE* fopen_eqgraphics_detour(const char* filename, const char* mode)
{
	// Only intercept reads
	if (strstr(mode, "r"))
	{
		char localfile[MAX_PATH];
		sprintf_s(localfile, "%s\\%s", gszINIPath, filename);
		if (_FileExists(localfile))
			return fopen_eqgraphics_trampoline(localfile, mode);
	}
	return fopen_eqgraphics_trampoline(filename, mode);
}

#ifndef ISXEQ
void ListWindows(PSPAWNINFO pChar, PCHAR szLine);
void WndNotify(PSPAWNINFO pChar, PCHAR szLine);
void ItemNotify(PSPAWNINFO pChar, PCHAR szLine);
void ListItemSlots(PSPAWNINFO pChar, PCHAR szLine);
void ReloadUI(PSPAWNINFO pChar, PCHAR szLine);
#else
int ListWindows(int argc, char *argv[]);
int WndNotify(int argc, char *argv[]);
int ItemNotify(int argc, char *argv[]);
int ListItemSlots(int argc, char *argv[]); 
#endif

#ifndef ISXEQ_LEGACY
#define WSF_AUTOSTRETCHH	0x00400000
#define WSF_CLIENTMOVABLE	0x00200000
#define WSF_NOHITTEST		0x00008000
#define WSF_USEMYALPHA		0x00000800
#define WSF_TRANSPARENT		0x00000400
#define WSF_SIZABLE			0x00000200
#define WSF_AUTOSTRETCHV	0x00000100
#define WSF_RELATIVERECT	0x00000080
#define WSF_BORDER			0x00000040
#define WSF_MINIMIZEBOX     0x00000020
#define WSF_CLOSEBOX        0x00000008
#define WSF_TITLEBAR		0x00000004

void AddAutoBankMenu()
{
	if (BarterValueCol == 0)
	{
		//Add a Value sort column
		if (CBarterSearchWnd *pBSW = (CBarterSearchWnd*)*(DWORD*)pinstCBarterSearchWnd)
		{
			if (CListWnd* list = (CListWnd*)((CXWnd*)pBSW)->GetChildItem("BTRSRCH_InventoryList"))
			{
				BarterLastSortIndex = list->SortCol;
				BarterLastSortDirection = list->bSortAsc;
				if (list->Columns.Count < 4)
				{
					CXStr Str = "Shows Merchant Value of item";
					BarterValueCol = list->AddColumn(CXStr("Value"), nullptr, 160, 0, Str, 1, 0, 0, true, { 0,0 }, { 0,0 });
					list->SetColumnJustification(BarterValueCol, 0);
				}
				else
				{
					SListWndColumn_RO col = list->Columns[4];
					BarterValueCol = 4;
				}
			}
		}
	}
#if !defined(ROF2EMU) && !defined(UFEMU)
	if (OurCheckBoxMenuIndex == 0)
	{
		if (CContextMenuManager *pMgr = pContextMenuManager)
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

			gCheckBoxFeatureEnabled = GetPrivateProfileInt("CoolBoxes", "CheckBoxFeatureEnabled", -1, gszINIFilename);
			if (gCheckBoxFeatureEnabled == -1)
			{
				gCheckBoxFeatureEnabled = 1;
				WritePrivateProfileString("CoolBoxes", "CheckBoxFeatureEnabled", "1", gszINIFilename);
			}

			gColorsFeatureEnabled = GetPrivateProfileInt("CoolBoxes", "ColorsFeatureEnabled", -1, gszINIFilename);
			if (gColorsFeatureEnabled == -1)
			{
				gColorsFeatureEnabled = 1;
				WritePrivateProfileString("CoolBoxes", "ColorsFeatureEnabled", "1", gszINIFilename);
			}

			CoolCheckBoxoptionID = CheckBoxMenu->AddMenuItem("Cool Checkbox Feature", 50, gCheckBoxFeatureEnabled);
			CoolColorsoptionID = CheckBoxMenu->AddMenuItem("Cool Colors Feature", 51, gColorsFeatureEnabled);
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
				if (list->Columns.Count == FINDWINDOW_CHECKBOXCOLUMN)
				{
					// can't get this stupid tooltip to show for columns, i dont know why...
					CXStr Str = "Toggle Checkboxes On/Off";
					MarkCol = list->AddColumn(CXStr(""), pUnChecked, 20, 0, Str, 3, 0, 0, true, { 0,0 }, { 0,0 });
					list->SetColumnJustification(MarkCol, 0);
				}
				else
				{
					SListWndColumn_RO col = list->Columns[FINDWINDOW_CHECKBOXCOLUMN];
					MarkCol = FINDWINDOW_CHECKBOXCOLUMN;
				}

				// add Value Column
				if (list->Columns.Count == FINDWINDOW_CHECKBOXCOLUMN+1)
				{
					CXStr Str = "Shows Merchant Value of item";
					ValueCol = list->AddColumn(CXStr("Value"), nullptr, 160, 0, Str, 1, 0, 0, true, { 0,0 }, { 0,0 });
					list->SetColumnJustification(ValueCol, 0);
				}
				else
				{
					SListWndColumn_RO col = list->Columns[FINDWINDOW_CHECKBOXCOLUMN + 1];
					ValueCol = FINDWINDOW_CHECKBOXCOLUMN+1;
				}

				// we need to add a couple controls, Checked count label and Never Loot Button
				if (CControlTemplate* pCountLabelTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("FIW_ItemNameLabel"))
				{
					if (pCountLabel = (CLabelWnd*)pSidlMgr->CreateXWndFromTemplate((CXWnd*)pFIWnd, pCountLabelTemplate))
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
						pCountLabel->CSetWindowText("0/10000");
						//BackgroundTextureTint
						pCountLabel->SetBGColor(0xFF2032FF);
					}
				}

				if (CControlTemplate* pRequestPreviewButtonTemplate = (CControlTemplate*)pSidlMgr->FindScreenPieceTemplate("FIW_DestroyItem"))
				{
					if (pNLMarkedButton = (CButtonWnd*)pSidlMgr->CreateXWndFromTemplate((CXWnd*)pFIWnd, pRequestPreviewButtonTemplate))
					{
						pNLMarkedButton->SetLeftOffset(157);
						pNLMarkedButton->SetRightOffset(87);
						pNLMarkedButton->SetTooltip("Click to tag all marked items as NEVER LOOT in advloot filters.");
						pNLMarkedButton->CSetWindowText("Never Loot");
						//BackgroundTextureTint
						pNLMarkedButton->SetBGColor(0xFF2032FF);
					}
				}
			}
		}
		if (!gCheckBoxFeatureEnabled)
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
#endif

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

			gAutoBankTradeSkillItems = GetPrivateProfileInt("AutoBank", "AutoBankTradeSkillItems", -1, gszINIFilename);
			if (gAutoBankTradeSkillItems == -1)
			{
				gAutoBankTradeSkillItems = 0;
				WritePrivateProfileString("AutoBank", "AutoBankTradeSkillItems", "0", gszINIFilename);
			}

			gAutoBankCollectibleItems = GetPrivateProfileInt("AutoBank", "AutoBankCollectibleItems", -1, gszINIFilename);
			if (gAutoBankCollectibleItems == -1)
			{
				gAutoBankCollectibleItems = 0;
				WritePrivateProfileString("AutoBank", "AutoBankCollectibleItems", "0", gszINIFilename);
			}

			gAutoBankQuestItems = GetPrivateProfileInt("AutoBank", "AutoBankQuestItems", -1, gszINIFilename);
			if (gAutoBankQuestItems == -1)
			{
				gAutoBankQuestItems = 0;
				WritePrivateProfileString("AutoBank", "AutoBankQuestItems", "0", gszINIFilename);
			}

			gAutoInventoryItems = GetPrivateProfileInt("AutoBank", "AutoInventoryItems", -1, gszINIFilename);
			if (gAutoInventoryItems == -1)
			{
				gAutoInventoryItems = 0;
				WritePrivateProfileString("AutoBank", "AutoInventoryItems", "0", gszINIFilename);
			}

			tradeskilloptionID = AutoBankMenu->AddMenuItem("Tradeskill Items", 50, gAutoBankTradeSkillItems);
			collectibleoptionID = AutoBankMenu->AddMenuItem("Collectible Items", 51, gAutoBankCollectibleItems);
			questoptionID = AutoBankMenu->AddMenuItem("Quest Items", 52, gAutoBankQuestItems);
			separatoroptionID = AutoBankMenu->AddSeparator();
			questoptionID = AutoBankMenu->AddMenuItem("Autoinventory Checked Items", 53, gAutoInventoryItems);
		}
	}
}

void RemoveAutoBankMenu()
{
	if (BarterValueCol)
	{
		if (CBarterSearchWnd *pBSW = (CBarterSearchWnd*)*(DWORD*)pinstCBarterSearchWnd)
		{
			if (CListWnd* list = (CListWnd*)pBSW->GetChildItem("BTRSRCH_InventoryList"))
			{
				if (BarterValueCol && list->Columns.Count > BarterValueCol)
				{
					list->Columns.DeleteElement(BarterValueCol);
					BarterValueCol = 0;
				}
				list->bSortAsc = true;
				list->SortCol = 1;
				BarterLastSortIndex = list->SortCol;
				BarterLastSortDirection = list->bSortAsc;
				list->Sort();
			}
		}
	}
	if (CContextMenuManager* pMgr = pContextMenuManager)
	{
		if (OurDefaultMenuIndex != 0)
		{
			pMgr->RemoveMenu(OurDefaultMenuIndex, true);
			OurDefaultMenuIndex = 0;
		}
#if !defined(ROF2EMU) && !defined(UFEMU)
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
				((CXWnd*)pCountLabel)->Destroy();
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
#endif
	}
}
#if defined(ROF2EMU) || defined(UFEMU)
void Autobank(PSPAWNINFO pChar, PCHAR szLine)
{
	//.text:006288E0 public: void __thiscall CBankWnd::AutoBank(bool) proc near
	pBankWnd->AutoBank();
}
#endif
void InitializeMQ2Windows()
{
    DebugSpew("Initializing MQ2 Windows");

	for (int i = 0; i < GetCurrentInvSlots(); i++)
		ItemSlotMap[szItemSlot[i]] = i;

	CHAR szOut[MAX_STRING] = { 0 };

#define AddSlotArray(name, count, start)     \
	for (int i = 0; i < count; i++)          \
	{                                        \
		sprintf_s(szOut, #name"%d", i + 1);  \
		ItemSlotMap[szOut] = start + i;      \
	}
	AddSlotArray(bank, 24, 2000);
	AddSlotArray(sharedbank, 4, 2500);
	AddSlotArray(trade, 16, 3000);
	AddSlotArray(world, 10, 4000);
	AddSlotArray(enviro, 10, 4000);
    ItemSlotMap["enviro"] = 4100;
	AddSlotArray(loot, 31, 5000);
	AddSlotArray(merchant, 80, 6000);
	AddSlotArray(bazaar, 80, 7000);
	AddSlotArray(inspect, 31, 8000);
#undef AddSlotArray
	
	EzDetourwName(CBankWnd__WndNotification, &CSidlInitHook::CBankWnd__WndNotification_Detour, &CSidlInitHook::CBankWnd__WndNotification_Tramp, "CBankWnd__WndNotification");
	EzDetourwName(CBarterSearchWnd__WndNotification, &CSidlInitHook::CBarterSearchWnd__WndNotification_Detour, &CSidlInitHook::CBarterSearchWnd__WndNotification_Tramp, "CBarterSearchWnd__WndNotification");
	EzDetourwName(CBarterSearchWnd__UpdateInventoryList, &CSidlInitHook::CBarterSearchWnd__UpdateInventoryList_Detour, &CSidlInitHook::CBarterSearchWnd__UpdateInventoryList_Tramp, "CBarterSearchWnd__UpdateInventoryList");
	EzDetourwName(CBarterWnd__WndNotification, &CSidlInitHook::CBarterWnd__WndNotification_Detour, &CSidlInitHook::CBarterWnd__WndNotification_Tramp, "CBarterWnd__WndNotification");
	
#if !defined(ROF2EMU) && !defined(UFEMU)
	EzDetourwName(CFindItemWnd__WndNotification, &CSidlInitHook::CFindItemWnd__WndNotification_Detour, &CSidlInitHook::CFindItemWnd__WndNotification_Tramp, "CFindItemWnd__WndNotification");
	EzDetourwName(CFindItemWnd__Update, &CSidlInitHook::CFindItemWnd__Update_Detour, &CSidlInitHook::CFindItemWnd__Update_Tramp, "CFindItemWnd__Update");
#endif
	
	EzDetourwName(CXMLSOMDocumentBase__XMLRead, &CXMLSOMDocumentBaseHook::XMLRead, &CXMLSOMDocumentBaseHook::XMLRead_Trampoline, "CXMLSOMDocumentBase__XMLRead");
	EzDetourwName(CSidlScreenWnd__Init1, &CSidlInitHook::Init_Detour, &CSidlInitHook::Init_Trampoline, "CSidlScreenWnd__Init1");
	EzDetourwName(CTargetWnd__WndNotification, &CSidlInitHook::CTargetWnd__WndNotification_Detour, &CSidlInitHook::CTargetWnd__WndNotification_Tramp, "CTargetWnd__WndNotification");
	EzDetourwName(CXWndManager__RemoveWnd, &CXWndManagerHook::RemoveWnd_Detour, &CXWndManagerHook::RemoveWnd_Trampoline, "CXWndManager__RemoveWnd");
	EzDetourwName(CMemoryMappedFile__SetFile, &CMemoryMappedFile::SetFile_Detour, &CMemoryMappedFile::SetFile_Trampoline, "CMemoryMappedFile__SetFile");
	EzDetourwName(__DoesFileExist, &DoesFileExist, &DoesFileExist_Trampoline, "__DoesFileExist");
	EzDetourwName(__eqgraphics_fopen, fopen_eqgraphics_detour, fopen_eqgraphics_trampoline,"__eqgraphics_fopen");
	// debugging
	// just remember this might be detoured in other plugins as well
	//EzDetourwName(CChatWindow__WndNotification,&CSidlInitHook::CSidlScreenWnd__WndNotification_Detour,&CSidlInitHook::CSidlScreenWnd__WndNotification_Tramp,"linktest");
#ifndef ISXEQ
	AddCommand("/windows", ListWindows);
	AddCommand("/notify", WndNotify);
	AddCommand("/itemnotify", ItemNotify);
	AddCommand("/itemslots", ListItemSlots);
	AddCommand("/reloadui", ReloadUI);
#if defined(ROF2EMU) || defined(UFEMU)
	//neither of these have an actual /autobank command but they do have the autobank function... so we add it.
	AddCommand("/autobank", Autobank);
#endif
#else
	pISInterface->AddCommand("EQWindows", ListWindows);
	pISInterface->AddCommand("EQNotify", WndNotify);
	pISInterface->AddCommand("EQItemNotify", ItemNotify);
	pISInterface->AddCommand("EQItemSlots", ListItemSlots);
#endif 

	if (pWndMgr)
	{
		CHAR Name[MAX_STRING] = { 0 };
		for (int i = 0; i < ((_CXWNDMGR*)pWndMgr)->pWindows.Count; i++)
		{
			if (PCXWND pWnd = ((_CXWNDMGR*)pWndMgr)->pWindows[i])
			{
				if (CXMLData* pXMLData = ((CXWnd*)pWnd)->GetXMLData())
				{
					if (pXMLData->Type == UI_Screen)
					{
						GetCXStr(pXMLData->Name.Ptr, Name, MAX_STRING);
						std::string WindowName = Name;
						MakeLower((WindowName));

						if (WindowMap.find(WindowName) != WindowMap.end())
						{
							WindowInfo wi;
							wi.Name = WindowName;
							wi.pWnd = (CXWnd*)pWnd;
							wi.ppWnd = nullptr;
							WindowList[(CXWnd*)pWnd] = wi;
						}
						else
						{
							WindowInfo wi;
							wi.Name = WindowName;
							wi.pWnd = (CXWnd*)pWnd;
							wi.ppWnd = nullptr;
							WindowList[(CXWnd*)pWnd] = wi;
							WindowMap[WindowName] = (CXWnd*)pWnd;
						}
					}
				}
			}
		}
	}
}

void ShutdownMQ2Windows()
{
    DebugSpew("Shutting down MQ2 Windows");
#ifndef ISXEQ
    RemoveCommand("/windows");
    RemoveCommand("/notify");
    RemoveCommand("/itemnotify");
    RemoveCommand("/itemslots");
	RemoveCommand("/reloadui");
#else
    pISInterface->RemoveCommand("EQWindows");
    pISInterface->RemoveCommand("EQNotify");
    pISInterface->RemoveCommand("EQItemNotify");
    pISInterface->RemoveCommand("EQItemSlots");
#endif 
	
#if !defined(ROF2EMU) && !defined(UFEMU)
    RemoveDetour(CFindItemWnd__WndNotification);
    RemoveDetour(CFindItemWnd__Update);
#else
	RemoveCommand("/autobank");
#endif
    RemoveDetour(CBarterWnd__WndNotification);
    RemoveDetour(CBarterSearchWnd__UpdateInventoryList);
    RemoveDetour(CBarterSearchWnd__WndNotification);
    RemoveDetour(CBankWnd__WndNotification);
	RemoveAutoBankMenu();
	RemoveDetour(CXMLSOMDocumentBase__XMLRead);
    RemoveDetour(CSidlScreenWnd__Init1);
    RemoveDetour(CTargetWnd__WndNotification);
    RemoveDetour(CXWndManager__RemoveWnd);
	RemoveDetour(__DoesFileExist);
	RemoveDetour(CMemoryMappedFile__SetFile);
	RemoveDetour(__eqgraphics_fopen);
	
	// for testing notifications, only for debugging
	// dont leave active for release
	//RemoveDetour(CChatWindow__WndNotification);
}

bool GenerateMQUI()
{
    // create EverQuest\uifiles\default\MQUI.xml
	PCHARINFO pCharInfo = GetCharInfo();
	char szFilename[MAX_PATH] = { 0 };
	char szOrgFilename[MAX_PATH] = { 0 };
	char UISkin[256] = { 0 };
    char            Buffer[2048];

	if (XmlFiles.empty())
	{
        DebugSpew("GenerateMQUI::Not Generating MQUI.xml, no files in our list");
        return false;
    }
    sprintf_s(UISkin, "default");
    sprintf_s(szOrgFilename, "%s\\uifiles\\%s\\EQUI.xml", gszEQPath, UISkin);
    sprintf_s(szFilename, "%s\\uifiles\\%s\\MQUI.xml", gszEQPath, UISkin);

    DebugSpew("GenerateMQUI::Generating %s", szFilename);

	FILE* forg = nullptr;
	errno_t err = fopen_s(&forg, szOrgFilename, "rt");
	if (err)
	{
        DebugSpew("GenerateMQUI::could not open %s", szOrgFilename);
        return false;
    }

	FILE* fnew = nullptr;
	err = fopen_s(&fnew, szFilename, "wt");
	if (err)
	{
        DebugSpew("GenerateMQUI::could not open %s", szFilename);
        fclose(forg);
        return false;
    }

	while (fgets(Buffer, 2048, forg))
	{
		if (strstr(Buffer, "</Composite>"))
		{
            DebugSpew("GenerateMQUI::Inserting our xml files");

			for (const std::string& file : XmlFiles)
			{
				DebugSpew("GenerateMQUI::Inserting %s", file.c_str());
				fprintf(fnew, "<Include>%s</Include>\n", file.c_str());
            }
        }
        fprintf(fnew, "%s", Buffer);
    }
    fclose(fnew);
    fclose(forg);

	if (pCharInfo != nullptr)
	{
        sprintf_s(szFilename, "%s\\UI_%s_%s.ini", gszEQPath, pCharInfo->Name, EQADDR_SERVERNAME);
		GetPrivateProfileString("Main", "UISkin", "default", UISkin, 256, szFilename);

		if (strcmp(UISkin, "default") != 0)
		{
            sprintf_s(szOrgFilename, "%s\\uifiles\\%s\\EQUI.xml", gszEQPath, UISkin);
            sprintf_s(szFilename, "%s\\uifiles\\%s\\MQUI.xml", gszEQPath, UISkin);

            DebugSpew("GenerateMQUI::Generating %s", szFilename);

			err = fopen_s(&forg, szOrgFilename, "rt");
			if (err)
			{
                DebugSpew("GenerateMQUI::could not open %s (non-fatal)", szOrgFilename);
				sprintf_s(szOrgFilename, "%s\\uifiles\\default\\EQUI.xml", gszEQPath);
				err = fopen_s(&forg, szOrgFilename, "rt");
				if (err)
				{
                    DebugSpew("GenerateMQUI::could not open %s", szOrgFilename);
                    DebugSpew("GenerateMQUI::giving up");
                    return false;
                }
            }

			err = fopen_s(&fnew, szFilename, "wt");
			if (err || fnew == nullptr)
			{
                DebugSpew("GenerateMQUI::could not open %s", szFilename);
                fclose(forg);
                return false;
            }

			while (fgets(Buffer, 2048, forg))
			{
				if (strstr(Buffer, "</Composite>"))
				{
					for (const std::string& file : XmlFiles)
					{
						fprintf(fnew, "<Include>%s</Include>\n", file.c_str());
                    }
                }

                fprintf(fnew, "%s", Buffer);
            }
            fclose(fnew);
            fclose(forg);
        }
    }
    return true;
}

bool IsXMLFilePresent(const char* filename)
{
	// check default location.
	char szFilename[MAX_PATH] = { 0 };

	sprintf_s(szFilename, "uifiles\\default\\%s", filename);

	// this will check both MQ and EQ dirs
	if (DoesFileExist(szFilename))
		return true;

	// check current ui
	if (PCHARINFO pCharInfo = GetCharInfo())
	{
		char UISkin[256] = { 0 };

		sprintf_s(szFilename, "%s\\UI_%s_%s.ini", gszEQPath, pCharInfo->Name, EQADDR_SERVERNAME);
		GetPrivateProfileString("Main", "UISkin", "default", UISkin, 256, szFilename);

		sprintf_s(szFilename, "uifiles\\%s\\%s", UISkin, filename);

		// this will check both MQ and EQ dirs
		return DoesFileExist(szFilename);
	}

	return false;
}

void DestroyMQUI()
{
    // delete MQUI.xml files.
	PCHARINFO pCharInfo = GetCharInfo();
	char szFilename[MAX_PATH] = { 0 };
	char UISkin[256] = { 0 };

	sprintf_s(szFilename, "%s\\uifiles\\default\\MQUI.xml", gszEQPath);
    DebugSpew("DestroyMQUI: removing file %s", szFilename);
    remove(szFilename);

	if (pCharInfo != nullptr)
	{
        sprintf_s(szFilename, "%s\\UI_%s_%s.ini", gszEQPath, pCharInfo->Name, EQADDR_SERVERNAME);
		GetPrivateProfileString("Main", "UISkin", "default", UISkin, 256, szFilename);

        sprintf_s(szFilename, "%s\\uifiles\\%s\\MQUI.xml", gszEQPath, UISkin);
        DebugSpew("DestroyMQUI: removing file %s", szFilename);
        remove(szFilename);
    }
}

void AddXMLFile(const char* filename)
{
	for (const std::string& file : XmlFiles)
	{
		if (!_stricmp(file.c_str(), filename))
			return; // we already added this file
	}

	char szBuffer[MAX_PATH] = { 0 };
	PCHARINFO pCharInfo = GetCharInfo();
	char szFilename[MAX_PATH] = { 0 };
	char UISkin[256] = { 0 };
    sprintf_s(UISkin, "default");

	// grab the name of the ui skin
	if (pCharInfo != nullptr)
	{
        sprintf_s(szFilename, "%s\\UI_%s_%s.ini", gszEQPath, pCharInfo->Name, EQADDR_SERVERNAME);
		GetPrivateProfileString("Main", "UISkin", "default", UISkin, 256, szFilename);
    }

	sprintf_s(szBuffer, "uifiles\\%s\\%s", UISkin, filename);

	if (!DoesFileExist(szBuffer))
	{
		sprintf_s(szBuffer, "uifiles\\default\\%s", filename);
		if (!DoesFileExist(szBuffer))
		{
            WriteChatf("UI file %s not found in either uifiles\\%s or uifiles\\default.  Please copy it there, reload the UI, and reload this plugin.", filename, UISkin);
            return;
        }
    }

    DebugSpew("Adding XML File %s", filename);
	if (gGameState == GAMESTATE_INGAME)
	{
        WriteChatf("UI file %s added, you must reload your UI for this to take effect.", filename);
    }

	XmlFiles.emplace_back(filename);
}

void RemoveXMLFile(const char* filename)
{
	// Remove all file(s) that match the given filename. Should only ever be one.
	XmlFiles.erase(
		std::remove_if(std::begin(XmlFiles), std::end(XmlFiles),
			[filename](const std::string & file) { return !_stricmp(filename, file.c_str()); }),
		std::end(XmlFiles));
}

CXWnd* FindMQ2Window(PCHAR WindowName, bool bVisibleOnly /*false*/)
{
	WindowInfo Info;
	std::string Name = WindowName;
    MakeLower(Name);

	// check toplevel windows first
	if (WindowMap.find(Name) != WindowMap.end())
	{
		if (bVisibleOnly)
		{
			if (WindowMap[Name]->IsVisible())
			{
				return WindowMap[Name];
			}
		}
		else
		{
			//found it no need to look further...
			return WindowMap[Name];
		}
	}

	// didnt find one, is it a container?
	PCONTENTS pPack = nullptr;
	if (!_strnicmp(WindowName, "bank", 4))
	{
			unsigned long nPack = atoi(&WindowName[4]);
		if (nPack && nPack <= NUM_BANK_SLOTS)
		{
			if (pCharData && ((PCHARINFO)pCharData)->BankItems.Items.Size > nPack - 1)
			{
					pPack = ((PCHARINFO)pCharData)->BankItems.Items[nPack - 1].pObject;
			}
		}
	}
	else if (!_strnicmp(WindowName, "pack", 4))
	{
			unsigned long nPack = atoi(&WindowName[4]);
		if (nPack && nPack <= 10)
		{
			if (PCHARINFO2 pChar2 = GetCharInfo2())
			{
				if (pChar2->pInventoryArray)
				{
						pPack = pChar2->pInventoryArray->Inventory.Pack[nPack - 1];
					}
				}
			}
		}
	else if (!_stricmp(WindowName, "enviro"))
	{
		pPack = ((CContainerMgr*)pContainerMgr)->pWorldContainer.pObject;
	}

	if (pPack)
	{
			return (CXWnd*)FindContainerForContents(pPack);
	}

	// didn't find a toplevel window, is it a child then?
	bool namefound = false;
	for (auto& N : WindowList)
	{
		if (N.second.Name == Name)
		{
			if (bVisibleOnly)
			{
				if (N.second.pWnd->IsVisible())
				{
					namefound = true;
					Info = N.second;
					break;
				}
			}
			else
			{
				namefound = true;
				Info = N.second;
				break;
			}
		}
	}

	if (!namefound)
	{
		WindowMap.erase(Name);
		return nullptr;
	}

	if (Info.pWnd)
	{
        return Info.pWnd;
	}

	if (Info.ppWnd)
	{
            return *Info.ppWnd;
	}


            WindowMap.erase(Name);
            WindowList.erase(Info.pWnd);
	return nullptr;
}

bool SendWndClick2(CXWnd* pWnd, PCHAR ClickNotification)
{
    if (!pWnd)
        return false;

	for (unsigned long i = 0; i < 8; i++)
    {
		if (!_stricmp(szClickNotification[i], ClickNotification))
        {
			DebugTry(CXRect rect = pWnd->GetScreenRect());
			DebugTry(CXPoint pt = rect.CenterPoint());

			switch (i)
            {
            case 0:
				DebugTry(pWnd->HandleLButtonDown(&pt, 0));
                break;
            case 1:
				DebugTry(pWnd->HandleLButtonDown(&pt, 0));
				DebugTry(pWnd->HandleLButtonUp(&pt, 0));
                break;
            case 2:
				DebugTry(pWnd->HandleLButtonDown(&pt, 0));
				DebugTry(pWnd->HandleLButtonHeld(&pt, 0));
                break;
            case 3:
				DebugTry(pWnd->HandleLButtonDown(&pt, 0));
				DebugTry(pWnd->HandleLButtonHeld(&pt, 0));
				DebugTry(pWnd->HandleLButtonUpAfterHeld(&pt, 0));
                break;
            case 4:
				DebugTry(pWnd->HandleRButtonDown(&pt, 0));
                break;
            case 5:
				DebugTry(pWnd->HandleRButtonDown(&pt, 0));
				DebugTry(pWnd->HandleRButtonUp(&pt, 0));
                break;
            case 6:
				DebugTry(pWnd->HandleRButtonDown(&pt, 0));
				DebugTry(pWnd->HandleRButtonHeld(&pt, 0));
                break;
            case 7:
				DebugTry(pWnd->HandleRButtonDown(&pt, 0));
				DebugTry(pWnd->HandleRButtonHeld(&pt, 0));
				DebugTry(pWnd->HandleRButtonUpAfterHeld(&pt, 0));
                break;
            default:
                return false;
            };

            WeDidStuff();
            return true;
        }
    }
    return false;
}

CXWnd* GetChildByIndex(CXWnd* pWnd, PCHAR Name, int index)
{
	CHAR Buffer[MAX_STRING] = { 0 };
	CXWnd* tmp = nullptr;

    if (!pWnd) return pWnd;
	if (CXMLData* pXMLData = pWnd->GetXMLData())
	{
		if (GetCXStr(pXMLData->Name.Ptr, Buffer, MAX_STRING) && !_stricmp(Buffer, Name))
		{
            WinCount++;
		}
		else if (GetCXStr(pXMLData->ScreenID.Ptr, Buffer, MAX_STRING) && !_stricmp(Buffer, Name))
		{
            WinCount++;
        }
    }

	if (WinCount == index)
		return pWnd;

	if (pWnd->GetFirstChildWnd())
	{
		if (tmp = GetChildByIndex((CXWnd*)pWnd->GetFirstChildWnd(), Name, index))
            return tmp;
    }

	return GetChildByIndex((CXWnd*)pWnd->GetNextSiblingWnd(), Name, index);
}

bool SendWndClick(PCHAR WindowName, PCHAR ScreenID, PCHAR ClickNotification)
{
	CXWnd* pWnd = FindMQ2Window(WindowName);
	if (!_stricmp(WindowName, "RewardSelectionWnd"))
	{
		//							 Parent      TabWindow        PageTemplate
		pWnd = (CXWnd*)FindMQ2Window(WindowName)->GetFirstChildWnd()->GetFirstChildWnd();

		while (pWnd)
		{
			if (((PCSIDLWND)pWnd)->IsVisible())
			{
				break;
			}
			pWnd = (CXWnd*)pWnd->GetNextSiblingWnd();
		}
	}

    if (!pWnd)
    {
		MacroError("Window '%s' not available.", WindowName);
        return false;
    }

	if (ScreenID && ScreenID[0] && ScreenID[0] != '0')
	{
		CXWnd* pButton = nullptr;

		if (!_stricmp(WindowName,"bartersearchwnd") && !_stricmp(ScreenID,"sellbutton"))
		{
			if (CXWnd* pList = ((CSidlScreenWnd*)(pWnd))->GetChildItem("BuyLineList"))
    {
				int selection = ((CListWnd*)pList)->GetCurSel();
				if (selection == -1)
				{
					MacroError("Please select a Listitem in '%s' before issuing a '%s' Click", WindowName, ScreenID);
					return false;
				}

				int buttonindex = (int)((CListWnd*)pList)->GetItemData(selection);
				WinCount = 0;
				pButton = GetChildByIndex(pWnd, ScreenID, buttonindex + 1);
			}
			}
		else if (!_stricmp(WindowName, "bazaarsearchwnd") && !_stricmp(ScreenID, "BZR_BuyButton"))
		{
			if (CXWnd* pList = ((CSidlScreenWnd*)(pWnd))->GetChildItem("BZR_ItemList"))
			{
				int selection = ((CListWnd*)pList)->GetCurSel();
				if (selection == -1)
				{
					MacroError("Please select a Listitem in '%s' before issuing a '%s' Click", WindowName, ScreenID);
					return false;
				}

				int buttonindex = (int)((CListWnd*)pList)->GetItemData(selection);
				WinCount = 0;
				pButton = GetChildByIndex(pWnd, ScreenID, buttonindex + 1);
			}
		}
		else
		{
			pButton = ((CSidlScreenWnd*)(pWnd))->GetChildItem(ScreenID);
		}

        if (!pButton)
        {
			MacroError("Window '%s' child '%s' not found.", WindowName, ScreenID);
            return false;
        }
		pWnd = pButton;
    }

	for (unsigned long i = 0; i < 8; i++)
    {
		if (!_stricmp(szClickNotification[i], ClickNotification))
        {
			CXRect rect = pWnd->GetScreenRect();
			CXPoint pt = rect.CenterPoint();

			switch (i)
            {
            case 0:
				pWnd->HandleLButtonDown(&pt, 0);
                break;
            case 1:
				pWnd->HandleLButtonDown(&pt, 0);
				pWnd->HandleLButtonUp(&pt, 0);
                break;
            case 2:
				pWnd->HandleLButtonHeld(&pt, 0);
                break;
            case 3:
				pWnd->HandleLButtonDown(&pt, 0);
				pWnd->HandleLButtonHeld(&pt, 0);
				pWnd->HandleLButtonUpAfterHeld(&pt, 0);
                break;
            case 4:
				pWnd->HandleRButtonDown(&pt, 0);
                break;
            case 5:
				pWnd->HandleRButtonDown(&pt, 0);
				pWnd->HandleRButtonUp(&pt, 0);
                break;
            case 6:
				pWnd->HandleRButtonDown(&pt, 0);
				pWnd->HandleRButtonHeld(&pt, 0);
                break;
            case 7:
				pWnd->HandleRButtonDown(&pt, 0);
				pWnd->HandleRButtonHeld(&pt, 0);
				pWnd->HandleRButtonUpAfterHeld(&pt, 0);
                break;
            default:
                return false;
            };

            WeDidStuff();
            return true;
        }
    }

    return false;
}

bool SendListSelect(PCHAR WindowName, PCHAR ScreenID, DWORD Value)
{
	CXWnd* pWnd = FindMQ2Window(WindowName);
	if (!_stricmp(WindowName, "RewardSelectionWnd"))
	{
		//							 Parent      TabWindow        PageTemplate
		pWnd = (CXWnd*)FindMQ2Window(WindowName)->GetFirstChildWnd()->GetFirstChildWnd();
		while (pWnd) 
		{
			if (((PCSIDLWND)pWnd)->IsVisible()) 
			{
				break;
			}
			pWnd = (CXWnd*)pWnd->GetNextSiblingWnd();
		}
	}

    if (!pWnd)
    {
		MacroError("Window '%s' not available.", WindowName);
        return false;
    }

	if (ScreenID && ScreenID[0] && ScreenID[0] != '0')
    {
		CXWnd* pList = pWnd->GetChildItem(ScreenID);
        if (!pList)
        {
			MacroError("Window '%s' child '%s' not found.", WindowName, ScreenID);
            return false;
        }

		if (pList->GetType() == UI_Listbox)
        {
			((CListWnd*)pList)->SetCurSel(Value);
			int index = ((CListWnd*)pList)->GetCurSel();		
			((CListWnd*)pList)->EnsureVisible(index);
			CXRect rect = ((CListWnd*)pList)->GetItemRect(index, 0);
            CXPoint pt = rect.CenterPoint();
			pList->HandleLButtonDown(&pt, 0);
			pList->HandleLButtonUp(&pt, 0);

            WeDidStuff();
        }
		else if (pList->GetType() == UI_Combobox)
        {
			CXRect comborect = pList->GetScreenRect();
			CXPoint combopt = comborect.CenterPoint();
			((CComboWnd*)pList)->SetChoice(Value);
			((CXWnd*)pList)->HandleLButtonDown(&combopt, 0);
			CListWnd* pListWnd = ((CComboWnd*)pList)->pListWnd;
			int index = pListWnd->GetCurSel();
			CXRect listrect = pListWnd->GetItemRect(index, 0);
			CXPoint listpt = listrect.CenterPoint();
			((CXWnd*)pListWnd)->HandleLButtonDown(&listpt, 0);
			((CXWnd*)pListWnd)->HandleLButtonUp(&listpt, 0);

            WeDidStuff();
        }
        else
        {
			MacroError("Window '%s' child '%s' cannot accept this notification.", WindowName, ScreenID);
            return false;
        }

        return true;
    }

    return false;
}

bool SendListSelect2(CXWnd *pList, LONG ListIndex)
{
	if (!pList)
	{
		MacroError("Window %x not available.", pList);
		return false;
	}

	if (pList->GetType() == UI_Listbox)
	{
		if ((LONG)((CListWnd*)pList)->ItemsArray.Count >= ListIndex)
		{
			((CListWnd*)pList)->SetCurSel(ListIndex);
			int index = ((CListWnd*)pList)->GetCurSel();
			((CListWnd*)pList)->EnsureVisible(index);
			CXRect rect = ((CListWnd*)pList)->GetItemRect(index, 0);
			CXPoint pt = rect.CenterPoint();
			pList->HandleLButtonDown(&pt, 0);
			pList->HandleLButtonUp(&pt, 0);

			WeDidStuff();
			return true;
		}

			MacroError("Index Out of Bounds in SendListSelect2");
			return false;
		}

	if (pList->GetType() == UI_Combobox)
	{
		if (CListWnd*pListWnd = ((CComboWnd*)pList)->pListWnd)
		{
			if (pListWnd->ItemsArray.Count >= ListIndex)
			{
				CXRect comborect = pList->GetScreenRect();
				CXPoint combopt = comborect.CenterPoint();
				((CComboWnd*)pList)->SetChoice(ListIndex);
				((CXWnd*)pList)->HandleLButtonDown(&combopt, 0);
				int index = pListWnd->GetCurSel();
				CXRect listrect = pListWnd->GetItemRect(index, 0);
				CXPoint listpt = listrect.CenterPoint();
				((CXWnd*)pListWnd)->HandleLButtonDown(&listpt, 0);
				((CXWnd*)pListWnd)->HandleLButtonUp(&listpt, 0);

				WeDidStuff();
				return true;
			}

				MacroError("Index Out of Bounds in SendListSelect2");
				return false;
			}

			MacroError("Invalid combobox in SendListSelect2");
			return false;
		}

		MacroError("Window was neiter a UI_Listbox nor a UI_Combobox");
		return false;
}

bool SendComboSelect(PCHAR WindowName, PCHAR ScreenID, DWORD Value)
{
	CXWnd* pWnd = FindMQ2Window(WindowName);
	if (!_stricmp(WindowName, "RewardSelectionWnd"))
	{
		//							 Parent      TabWindow        PageTemplate
		pWnd = (CXWnd*)FindMQ2Window(WindowName)->GetFirstChildWnd()->GetFirstChildWnd();
		while (pWnd)
		{
			if (((PCSIDLWND)pWnd)->IsVisible())
			{
				break;
			}

			pWnd = (CXWnd*)pWnd->GetNextSiblingWnd();
		}
	}

    if (!pWnd)
    {
		MacroError("Window '%s' not available.", WindowName);
        return false;
    }

	if (ScreenID && ScreenID[0] && ScreenID[0] != '0')
    {
		CComboWnd* pCombo = (CComboWnd*)((CSidlScreenWnd*)(pWnd))->GetChildItem(ScreenID);
        if (!pCombo)
        {
			MacroError("Window '%s' child '%s' not found.", WindowName, ScreenID);
            return false;
        }

		if (((CXWnd*)pCombo)->GetType() == UI_Combobox)
        {
			CXRect comborect = ((CXWnd*)pCombo)->GetScreenRect();
			CXPoint combopt = comborect.CenterPoint();
			pCombo->SetChoice(Value);
			((CXWnd*)pCombo)->HandleLButtonDown(&combopt, 0);
			CListWnd* pListWnd = pCombo->pListWnd;
			int index = pListWnd->GetCurSel();
			CXRect listrect = pListWnd->GetItemRect(index, 0);
			CXPoint listpt = listrect.CenterPoint();
			((CXWnd*)pListWnd)->HandleLButtonDown(&listpt, 0);
			((CXWnd*)pListWnd)->HandleLButtonUp(&listpt, 0);

            WeDidStuff();
			return true;
        }

		MacroError("Window '%s' child '%s' cannot accept this notification.", WindowName, ScreenID);
            return false;
        }

    return false;
}

bool SendTabSelect(PCHAR WindowName, PCHAR ScreenID, DWORD Value)
{
	CXWnd* pWnd = FindMQ2Window(WindowName);
	if (!_stricmp(WindowName, "RewardSelectionWnd"))
	{
		//							 Parent      TabWindow        PageTemplate
		pWnd = (CXWnd*)FindMQ2Window(WindowName)->GetFirstChildWnd()->GetFirstChildWnd();
		while (pWnd)
		{
			if (((PCSIDLWND)pWnd)->IsVisible())
			{
				break;
			}
			pWnd = (CXWnd*)pWnd->GetNextSiblingWnd();
		}
	}

    if (!pWnd)
    {
		MacroError("Window '%s' not available.", WindowName);
        return false;
    }

	if (ScreenID && ScreenID[0] && ScreenID[0] != '0')
    {
		CTabWnd* pTab = (CTabWnd*)((CSidlScreenWnd*)(pWnd))->GetChildItem(ScreenID);
        if (!pTab)
        {
			MacroError("Window '%s' child '%s' not found.", WindowName, ScreenID);
            return false;
        }

		int uitype = ((CXWnd*)pTab)->GetType();
		if (uitype == UI_TabBox)
        {
			pTab->SetPage(Value, true);

            WeDidStuff();
			return true;
        }

		MacroError("Window '%s' child '%s' cannot accept this notification.", WindowName, ScreenID);
            return false;
        }

    return false;
}

bool SendWndNotification(PCHAR WindowName, PCHAR ScreenID, DWORD Notification, VOID* Data)
{
	CHAR szOut[MAX_STRING] = { 0 };

	CXWnd* pWnd = FindMQ2Window(WindowName);
    if (!pWnd)
    {
		sprintf_s(szOut, "Window '%s' not available.", WindowName);
		WriteChatColor(szOut, USERCOLOR_DEFAULT);
        return false;
    }

	CXWnd* pButton = nullptr;
    if (ScreenID && ScreenID[0])
    {
		pButton = ((CSidlScreenWnd*)(pWnd))->GetChildItem(ScreenID);
        if (!pButton)
        {
			sprintf_s(szOut, "Window '%s' child '%s' not found.", WindowName, ScreenID);
			WriteChatColor(szOut, USERCOLOR_DEFAULT);
            return false;
        }
    }

	// its possible to null-deref this pButton if ScreenID is 0
	if (Notification == XWM_NEWVALUE) {
		((CSliderWnd*)(pButton))->SetValue((int)Data);
	}

	((CXWnd*)(pWnd))->WndNotification(pButton, Notification, Data);
    WeDidStuff();
    return true;
}

void AddWindow(char* WindowName, CXWnd** ppWindow)
{
	std::string Name = WindowName;
    MakeLower(Name);

	if (WindowMap.find(Name) != WindowMap.end())
	{
		WindowInfo pWnd;

		for (auto& N : WindowList)
		{
			if (N.second.Name == Name)
			{
				pWnd = N.second;
				break;
			}
		}

		pWnd.pWnd = nullptr;
		pWnd.ppWnd = ppWindow;
	}
	else
	{
		WindowInfo pWnd;
		pWnd.Name = Name;
		pWnd.pWnd = nullptr;
		pWnd.ppWnd = ppWindow;

		WindowList[*ppWindow] = pWnd;
		WindowMap[Name] = *ppWindow;
    }
}

void RemoveWindow(char* WindowName)
{
	std::string Name = WindowName;
    MakeLower(Name);

	if (WindowMap.find(Name) != WindowMap.end())
	{
        WindowMap.erase(Name);
		for (auto N = WindowList.begin(); N != WindowList.end(); N++)
		{
			if (N->second.Name == Name)
			{
				WindowList.erase(N);
				break;
			}
        }
    }
}
#endif

CHAR tmpName[MAX_STRING] = { 0 };
CHAR tmpAltName[MAX_STRING] = { 0 };
CHAR tmpType[MAX_STRING] = { 0 };

int RecurseAndListWindows(PCSIDLWND pWnd)
{
    int Count = 0;

	if (CXMLData* pXMLData = ((CXWnd*)pWnd)->GetXMLData())
	{
        Count++;
		GetCXStr(pXMLData->TypeName.Ptr, tmpType, MAX_STRING);
		GetCXStr(pXMLData->Name.Ptr, tmpName, MAX_STRING);
		GetCXStr(pXMLData->ScreenID.Ptr, tmpAltName, MAX_STRING);
		if (tmpAltName[0] && _stricmp(tmpName, tmpAltName))
		{
			if (pWnd->GetParentWindow() && pWnd->GetParentWindow()->GetParentWindow())
				WriteChatf("[0x%08X][P:0x%08X][PP:0x%08X] [\ay%s\ax] [\at%s\ax] [Custom UI-specific: \at%s\ax]", pWnd, pWnd->GetParentWindow(), pWnd->GetParentWindow()->GetParentWindow(), tmpType, tmpName, tmpAltName);
			else
				WriteChatf("[0x%08X][P:0x%08X] [\ay%s\ax] [\at%s\ax] [Custom UI-specific: \at%s\ax]", pWnd, pWnd->GetParentWindow(), tmpType, tmpName, tmpAltName);
		}
		else
		{
			WriteChatf("[0x%08X][P:0x%08X] [\ay%s\ax] [\at%s\ax]", pWnd, pWnd->GetParentWindow(), tmpType, tmpName);
		}
    }

    if (pWnd->GetFirstChildWnd())
        Count += RecurseAndListWindows(pWnd->GetFirstChildWnd());

    if (pWnd->GetNextSiblingWnd())
        Count += RecurseAndListWindows(pWnd->GetNextSiblingWnd());

    return Count;
}

#ifndef ISXEQ
VOID ListWindows(PSPAWNINFO pChar, PCHAR szLine)
{
	char szArg1[MAX_STRING] = { 0 };
	char szArg2[MAX_STRING] = { 0 };
	char szArg3[MAX_STRING] = { 0 };
	GetArg(szArg1, szLine, 1);
	GetArg(szArg2, szLine, 2);
	GetArg(szArg3, szLine, 3);
#else
int ListWindows(int argc, char *argv[])
{
	char szArg1[MAX_STRING] = { 0 };
	char szArg2[MAX_STRING] = { 0 };
	char szArg3[MAX_STRING] = { 0 };
    PCHAR szLine = NULL;
    if (argc > 0)
        szLine = argv[1];
    if (argc > 1)
		strcpy_s(szArg1, argv[1]);
    if (argc > 2)
		strcpy_s(szArg2, argv[2]);
    if (argc > 3)
		strcpy_s(szArg3, argv[3]);
#endif
	bool bOpen = false;
	bool bPartial = false;

	if (!_stricmp(szArg1, "open"))
	{
		bOpen = true;
		szLine[0] = '\0';
		szLine = 0;
		if (!_stricmp(szArg2, "partial"))
		{
			bPartial = true;
			strcpy_s(szArg2, szArg3);
		}
		}
	else if (!_stricmp(szArg1, "partial"))
	{
		bPartial = true;
		szLine[0] = '\0';
		szLine = 0;
	}

	unsigned long Count = 0;
    if (!szLine || !szLine[0])
    {
		if (bOpen)
			WriteChatColor("List of available OPEN windows");
		else
			WriteChatColor("List of available windows");
        WriteChatColor("-------------------------");

		for (auto& N : WindowList)
		{
			WindowInfo Info = N.second;
			if (bOpen)
			{
				if (Info.pWnd && Info.pWnd->IsVisible() == 1 && Info.pWnd->GetParentWindow() == 0)
				{
					if (bPartial)
					{
						if (Info.Name.find(szArg2) != Info.Name.npos)
						{
							WriteChatf("[PARTIAL MATCH][OPEN] %s", Info.Name.c_str());
							RecurseAndListWindows((PCSIDLWND)Info.pWnd);
								Count++;
							}
					}
					else
					{
						WriteChatf("[OPEN] %s", Info.Name.c_str());
							Count++;
						}
					}
			}
			else
			{
				if (bPartial)
				{
					if (Info.Name.find(szArg2) != Info.Name.npos)
					{
						WriteChatf("[PARTIAL MATCH] %s", Info.Name.c_str());
						RecurseAndListWindows((PCSIDLWND)Info.pWnd);
							Count++;
						}
				}
				else
				{
					WriteChatf("%s", Info.Name.c_str());
						Count++;
					}
				}
            }

		WriteChatf("%d window(s) found with %s in the name", Count, szArg2);
    }
    else
    {
        // list children of..
		std::string WindowName = szLine;
        MakeLower(WindowName);

		if (WindowMap.find(WindowName) == WindowMap.end())
		{
			if (CXWnd* pWnd = FindMQ2Window(szLine))
			{
                Count = RecurseAndListWindows((PCSIDLWND)pWnd);

				WriteChatf("%d child windows", Count);
				RETURN(0);
			}

			WriteChatf("Window '%s' not available", WindowName.c_str());
			RETURN(0);
 		}

		WriteChatf("Listing child windows of '%s'", WindowName.c_str());
        WriteChatColor("-------------------------");

		for (auto & N : WindowList)
		{
			WindowInfo Info = N.second;

			if (Info.Name == WindowName && Info.pWnd)
			{
				if (PCSIDLWND pWnd = Info.pWnd->GetFirstChildWnd())
				{
					Count = RecurseAndListWindows(pWnd);
				}
				WriteChatf("%d child windows", Count);
			}
        }
    }

    RETURN(0);
}

PCHAR szWndNotification[] = { 
	0,                        // 0
	"leftmouse",              // 1
	"leftmouseup",            // 2
	"rightmouse",             // 3
	0,                        // 4
	0,                        // 5
	"enter",                  // 6
	0,                        // 7
	0,                        // 8
	"help",                   // 9
	"close",                  // 10
	0,                        // 11
	0,                        // 12
	0,                        // 13
	"newvalue",               // 14
	0,                        // 15
	0,                        // 16
	0,                        // 17
	0,                        // 18
	0,                        // 19
	"contextmenu",            // 20
	"mouseover",              // 21
	"history",                // 22
	"leftmousehold",          // 23
	0,                        // 24
	0,                        // 25
	0,                        // 26
	"link",                   // 27
	0,                        // 28
	"resetdefaultposition",   // 29
}; 

#ifndef ISXEQ
void WndNotify(PSPAWNINFO pChar, PCHAR szLine)
{
#else
int WndNotify(int argc, char* argv[])
{
    PSPAWNINFO pChar = (PSPAWNINFO)pLocalPlayer;
#endif
	unsigned long Data = 0;
#ifndef ISXEQ 
	CHAR szArg1[MAX_STRING] = { 0 };
	CHAR szArg2[MAX_STRING] = { 0 };
	CHAR szArg3[MAX_STRING] = { 0 };
	CHAR szArg4[MAX_STRING] = { 0 };
    GetArg(szArg1, szLine, 1);
    GetArg(szArg2, szLine, 2);
    GetArg(szArg3, szLine, 3);
    GetArg(szArg4, szLine, 4);

	if (!szArg3[0] && !IsNumber(szArg1) && _stricmp(szArg2, "menuselect"))
    {
        SyntaxError("Syntax: /notify <window|\"item\"> <control|0> <notification> [notification data]");
        return;
    }

    if (szArg4[0])
	{
		Data = atoi(szArg4);
	}
#else
	if (argc < 3 && (argc > 1 && !IsNumber(argv[2])))
    {
		printf("%s syntax: %s <window|\"item\"> <control|0> <notification> [notification data]", argv[0], argv[0]);
        RETURN(0);
    }
	if (argc > 4)
		Data = atoi(argv[4]);
	char* szArg1 = argv[1];
	char* szArg2 = argv[2];
	char* szArg3 = argv[3];
	char* szArg4 = argv[4];
#endif 

	if (!_stricmp(szArg2, "menuselect"))
	{
		CContextMenuManager* ccmgr = pContextMenuManager;
		if (ccmgr->NumVisibleMenus == 1)
		{
			if (ccmgr->CurrMenu < 8)
			{
				int currmen = ccmgr->CurrMenu;
				if (CContextMenu* menu = ccmgr->pCurrMenus[currmen])
				{
					CXStr Str;
					_strlwr_s(szArg1);

					for (int i = 0; i < menu->NumItems; i++)
					{
						((CListWnd*)menu)->GetItemText(&Str, i, 1);
						GetCXStr(Str.Ptr, szArg4);

						if (szArg4[0] != '\0')
						{
							_strlwr_s(szArg4);
							if (strstr(szArg4, szArg1))
							{
								WriteChatf("\ay[/notify] SUCCESS\ax: Clicking \"%s\" at position %d in the menu.", szArg4, i);
								((CXWnd*)(ccmgr))->WndNotification((CXWnd*)menu, XWM_LMOUSEUP, (void*)i);
								RETURN(0);
							}
						}
					}

					WriteChatf("\ar[/notify] FAILED\ax: No Menu item was found with the word %s in it", szArg1);
				}
			}
		}
		else
		{
			WriteChatf("\ar[/notify] FAILED\ax: No Menu is currently open.");
		}

		RETURN(0);
	}

	if (!_stricmp(szArg3, "link"))
	{
        DebugSpewAlways("WndNotify: link found, Data = 1");
        Data = 1;
    }

	if (IsNumber(szArg1))
	{
		// we have a number. it means the user want us to click a window he has found the address for...
		DWORD addr = atoi(szArg1);
		if (!_stricmp(szArg2, "listselect"))
		{
			SendListSelect2((CXWnd*)addr, atoi(szArg3));
			RETURN(0);
		}

		SendWndClick2((CXWnd*)addr, szArg2);
		RETURN(0);
	}

	if (!_stricmp(szArg3, "listselect"))
	{
		SendListSelect(szArg1, szArg2, Data - 1);
        RETURN(0);
	}

	if (!_stricmp(szArg3, "comboselect"))
	{
		SendComboSelect(szArg1, szArg2, Data - 1);
        RETURN(0);
	}

	if (!_stricmp(szArg3, "tabselect"))
	{
		SendTabSelect(szArg1, szArg2, Data - 1);
        RETURN(0);
    } 

	if (Data == 0 && SendWndClick(szArg1, szArg2, szArg3))
	{
        RETURN(0);
	}

	for (unsigned long i = 0; i < sizeof(szWndNotification) / sizeof(szWndNotification[0]); i++)
	{
		if (szWndNotification[i] && !_stricmp(szWndNotification[i], szArg3))
    {
			if (i == XWM_LINK)
        {
				if (!SendWndNotification(szArg1, szArg2, i, (void*)szArg4))
                {
					MacroError("Could not send notification to %s %s", szArg1, szArg2);
                }
                RETURN(0);
            }

			if (szArg2[0] == '0')
            {
				if (!SendWndNotification(szArg1, 0, i, (void*)Data))
                {
					MacroError("Could not send notification to %s %s", szArg1, szArg2);
                }
            }
			else if (!SendWndNotification(szArg1, szArg2, i, (void*)Data))
            {
				MacroError("Could not send notification to %s %s", szArg1, szArg2);
            }
            RETURN(0);
        }
    }

	MacroError("Invalid notification '%s'", szArg3);
    RETURN(0);
}

bool IsCtrlKey()
{
	return (pWndMgr->GetKeyboardFlags() & 0x00000002) != 0;
}

// item slots:
// 2000-2015 bank window
// 2500-2503 shared bank
// 5000-5031 loot window
// 3000-3015 trade window (including npc) 3000-3007 are your slots, 3008-3015 are other character's slots
// 4000-4010 world container window
// 6000-6080 merchant window
// 7000-7080 bazaar window
// 8000-8031 inspect window
bool CheckLootArg(char* arg, char* search, int argcnt, int* slot)
{
	if (!_strnicmp(arg, search, argcnt))
	{
		char* numptr = arg + argcnt;
		int theslot = -1;
		if (IsNumber(numptr))
		{
			theslot = atoi(numptr) - 1;
			if (theslot < 0)
				theslot = 0;
			*slot = theslot;
			return true;
		}
	}
	return false;
}

#ifndef ISXEQ
VOID ItemNotify(PSPAWNINFO pChar, PCHAR szLine)
{
	CHAR szArg1[MAX_STRING] = { 0 };
	CHAR szArg2[MAX_STRING] = { 0 };
	CHAR szArg3[MAX_STRING] = { 0 };
	CHAR szArg4[MAX_STRING] = { 0 };
    GetArg(szArg1, szLine, 1);
    GetArg(szArg2, szLine, 2);
    GetArg(szArg3, szLine, 3);
    GetArg(szArg4, szLine, 4); 

    if (!szArg2[0])
    {
        WriteChatColor("Syntax: /itemnotify <slot|#> <notification>");
        WriteChatColor("     or /itemnotify in <bag slot> <slot # in bag> <notification>");
		WriteChatColor("     or /itemnotify <itemname> <notification>");
        RETURN(0);
    }
#else
int ItemNotify(int argc, char *argv[])
{
	if (argc != 3 && argc != 5)
    {
        //WriteChatf("ItemNotify got %d args", argc);
        WriteChatColor("Syntax: /itemnotify <slot|#> <notification>");
        WriteChatColor("     or /itemnotify in <bag slot> <slot # in bag> <notification>");
        RETURN(0);
    }
	char* szArg1tmp = argv[1];
	char* szArg2 = argv[2];
	char* szArg3 = "";
	char* szArg4 = "";
	CHAR szArg1[2048] = { 0 };
	strcpy_s(szArg1, szArg1tmp);
	if (argc == 5)
    {
		szArg3 = argv[3];
		szArg4 = argv[4];
    }
    PSPAWNINFO pChar = (PSPAWNINFO)pLocalPlayer;
#endif

	PCHAR pNotification = &szArg2[0];
	EQINVSLOT* pSlot = nullptr;
	DWORD i = 0;
	PEQINVSLOTMGR pInvMgr = (PEQINVSLOTMGR)pInvSlotMgr;
    short bagslot = -1;
    short invslot = -1;
    ItemContainerInstance type = eItemContainerInvalid;

	if (!_stricmp(szArg1, "in"))
    { 
        if (!szArg4[0])
        {
            WriteChatColor("Syntax: /itemnotify in <bag slot> <slot # in bag> <notification>");
            RETURN(0);
        }

		if (!_strnicmp(szArg2, "bank", 4))
		{
			invslot = atoi(&szArg2[4]) - 1;
			bagslot = atoi(szArg3) - 1;
			type = eItemContainerBank;
		}
		else if (!_strnicmp(szArg2, "sharedbank", 10))
		{
			invslot = atoi(&szArg2[10]) - 1;
			bagslot = atoi(szArg3) - 1;
			type = eItemContainerSharedBank;
		}
		else if (!_strnicmp(szArg2, "pack", 4))
		{
			invslot = atoi(&szArg2[4]) - 1 + BAG_SLOT_START;
			bagslot = atoi(szArg3) - 1;
			type = eItemContainerPossessions;
		}

		// I wish I could just call:
		// pSlot = (PEQINVSLOT)pInvSlotMgr->FindInvSlot(invslot,bagslot);
		// BUT it returns HB_InvSlot as well as containers AND it doesn't take "type" into account...
		// which is why I use GetInvSlot instead...
		pSlot = GetInvSlot(type, invslot, bagslot);
		pNotification = &szArg4[0];

		if (!pSlot && type != -1)
		{
			// pSlot was not found (so bag is closed) BUT we can "click" it anyway with moveitem
			// so lets just do that if pNotification is leftmoseup
			if (invslot < 0 || invslot > GetCurrentInvSlots())
			{
				WriteChatf("%d is not a valid invslot. (itemnotify)", invslot);
				RETURN(0);
			}

			if (pNotification && !_strnicmp(pNotification, "leftmouseup", 11))
			{
				// we dont care about the bagslot here
				// and we dont care if the user has something
																// on cursor either, cause we know they
																// specified "in" so a container MUST exist... -eqmule
				PCONTENTS pContainer = FindItemBySlot(invslot);
				if (!pContainer)
				{
					WriteChatf("There was no container in slot %d", invslot);
					RETURN(0);
				}

				if (bagslot < 0 && bagslot >= (int)pContainer->Contents.ContentSize)
				{
					WriteChatf("%d is not a valid slot for this container.", bagslot);
					RETURN(0);
				}

				if (GetItemFromContents(pContainer)->Type != ITEMTYPE_PACK)
				{
					WriteChatf("There was no container in slot %d", invslot);
					RETURN(0);
				}

				if (ItemOnCursor())
				{
					DropItem(type, invslot, bagslot);
				}
				else
				{
					PickupItem(type, FindItemBySlot(invslot, bagslot));
				}

				RETURN(0);
			}

			if (pNotification && !_strnicmp(pNotification, "rightmouseup", 12))
				{
				// we fake it with /useitem
				if (HasExpansion(EXPANSION_VoA))
				{
					PCONTENTS pItem = FindItemBySlot(invslot, bagslot);
					if (pItem)
					{
						if (GetItemFromContents(pItem)->Clicky.SpellID > 0 && GetItemFromContents(pItem)->Clicky.SpellID != -1)
						{
							CHAR cmd[MAX_STRING] = { 0 };
							sprintf_s(cmd, "/useitem \"%s\"", GetItemFromContents(pItem)->Name);
							EzCommand(cmd);
							RETURN(0);
						}
					}
					else
					{
						// it doesnt matter if its a bag, since the user specified "in"
						// we cant open bags inside bags so lets just return...
						WriteChatf("Item '%s' not found.", szArg2);
						RETURN(0);
					}
				}
			}
		}
	}
	else
	{
		// user didnt specify "in" so it should be outside a container
		// OR it's an item, either way we can "click" it -eqmule
		int Slot = atoi(szArg1);
		if (Slot == 0)
		{
			_strlwr_s(szArg1);
			Slot = ItemSlotMap[szArg1];
			if (Slot < GetCurrentInvSlots() && pInvSlotMgr)
			{
				DebugTry(pSlot = (EQINVSLOT*)pInvSlotMgr->FindInvSlot(Slot));
			}
			else
			{
				if (!_strnicmp(szArg1, "loot", 4))
				{
					invslot = atoi(szArg1 + 4) - 1;
					type = eItemContainerCorpse;
				}
				else if (!_strnicmp(szArg1, "enviro", 6))
				{
					invslot = atoi(szArg1 + 6) - 1;
                    type = eItemContainerWorld;
				}
				else if (!_strnicmp(szArg1, "pack", 4))
				{
					invslot = atoi(szArg1 + 4) - 1 + BAG_SLOT_START;
                    type = eItemContainerPossessions;
				}
				else if (!_strnicmp(szArg1, "bank", 4))
				{
					invslot = atoi(szArg1 + 4) - 1;
                    type = eItemContainerBank;
				}
				else if (!_strnicmp(szArg1, "sharedbank", 10))
				{
					invslot = atoi(szArg1 + 10) - 1;
                    type = eItemContainerSharedBank;
				}
				else if (!_strnicmp(szArg1, "trade", 5))
				{
					invslot = atoi(szArg1 + 5) - 1;
                    type = eItemContainerTrade;
                }

				CHAR szType[MAX_STRING] = { 0 };

				for (i = 0; i < pInvMgr->TotalSlots; i++)
				{
                    pSlot = pInvMgr->SlotArray[i];
					if (pSlot && pSlot->Valid && pSlot->pInvSlotWnd
						&& pSlot->pInvSlotWnd->Location == type
						&& (short)pSlot->pInvSlotWnd->Slot1 == invslot)
					{
						CXMLData* pXMLData = ((CXWnd*)pSlot->pInvSlotWnd)->GetXMLData();
						if (pXMLData)
						{
							GetCXStr(pXMLData->ScreenID.Ptr, szType, MAX_STRING);
							if (!_stricmp(szType, "HB_InvSlot"))
							{
								continue;
							}
						}

						Slot = 1;
                        break;
                    }
                }

                if (i == pInvMgr->TotalSlots)
					Slot = 0;
            }
        }

		if (Slot == 0 && szArg1[0] != '0' && _stricmp(szArg1, "charm"))
		{
			// could it be an itemname?
			// lets check:
			PCONTENTS ptheitem = nullptr;

			if (szArg1[0] == '#')
        {
				int id = atoi(&szArg1[1]);
				ptheitem = FindItemByID(id);
			}
			else
			{
				ptheitem = FindItemByName(szArg1, 1);
			}

			if (ptheitem)
			{
				if (pNotification && !_strnicmp(pNotification, "leftmouseup", 11))
				{
					if (ItemOnCursor())
					{
						DropItem(eItemContainerPossessions, bagslot, invslot);
					}
					else
					{
						PickupItem(eItemContainerPossessions, ptheitem);
					}
				}
				else if (pNotification && !_strnicmp(pNotification, "rightmouseup", 12))
				{
					// we fake it with /useitem
					// better check if its a spell cause then it means we should mem it
					PITEMINFO pClicky = GetItemFromContents(ptheitem);

					if (pClicky && pClicky->ItemType == ITEMITEMTYPE_SCROLL)
					{
						if (IsItemInsideContainer(ptheitem))
						{
							OpenContainer(ptheitem, true);
						}

						if (pInvSlotMgr)
						{
							pSlot = (PEQINVSLOT)pInvSlotMgr->FindInvSlot(ptheitem->GetGlobalIndex().Index.Slot1, ptheitem->GetGlobalIndex().Index.Slot2);
						}

						if (!pSlot || !pSlot->pInvSlotWnd || !SendWndClick2((CXWnd*)pSlot->pInvSlotWnd, pNotification))
						{
							WriteChatf("Could not mem spell, most likely cause bag wasnt open and i didnt find it");
						}

						RETURN(0);
					}

					if (pClicky && pClicky->Clicky.SpellID != -1)
					{
						CHAR cmd[512] = { 0 };
						sprintf_s(cmd, "/useitem \"%s\"", GetItemFromContents(ptheitem)->Name);
						EzCommand(cmd);

						RETURN(0);
					}

					if (pClicky->Type == ITEMTYPE_PACK)
					{
						// its a pack, so just open it
						if (ptheitem->Open)
						{
							CloseContainer(ptheitem);
						}
						else {
							OpenContainer(ptheitem, false);
						}
					}
				}

				RETURN(0);
			}

			WriteChatf("[/itemnotify] Invalid item slot '%s'", szArg1);
            RETURN(0);
		}

		if (Slot > 0 && Slot < MAX_INV_SLOTS && !pSlot)
		{
            pSlot = pInvMgr->SlotArray[Slot];
        }
    }

    if (!pSlot)
    {
		WriteChatf("SLOT IS NULL: Could not send notification to %s %s", szArg1, szArg2);
        RETURN(0);
    }

    DebugSpew("ItemNotify: Calling SendWndClick");

	if (!pSlot->pInvSlotWnd || !SendWndClick2((CXWnd*)pSlot->pInvSlotWnd, pNotification))
    {
		WriteChatf("Could not send notification to %s %s", szArg1, szArg2);
    }

    RETURN(0);
}

#ifndef ISXEQ
void ListItemSlots(PSPAWNINFO pChar, PCHAR szLine)
#else
int ListItemSlots(int argc, char* argv[])
#endif
{
	PEQINVSLOTMGR pMgr = (PEQINVSLOTMGR)pInvSlotMgr;
    if (!pMgr)
        RETURN(0);
	unsigned long Count = 0;

    WriteChatColor("List of available item slots");
    WriteChatColor("-------------------------");

	for (unsigned long N = 0; N < MAX_INV_SLOTS; N++)
	{
		if (PEQINVSLOT pSlot = pMgr->SlotArray[N])
        {
            if (pSlot->pInvSlotWnd)
            {
                WriteChatf("%d %d %d", N, pSlot->pInvSlotWnd->Location, pSlot->InvSlot);
                Count++;
			}
			else if (pSlot->InvSlot)
			{
                WriteChatf("%d %d", N, pSlot->InvSlot);
            }
        }
	}

	WriteChatf("%d available item slots", Count);
        RETURN(0)
}

void ReloadUI(PSPAWNINFO pChar, PCHAR szLine)
{
	PCHARINFO pCharInfo = GetCharInfo();
	if (!pCharInfo) return;

	CHAR szFilename[MAX_PATH];
	CHAR UISkin[256];

	sprintf_s(szFilename, "%s\\UI_%s_%s.ini", gszEQPath, pCharInfo->Name, EQADDR_SERVERNAME);
	GetPrivateProfileString("Main", "UISkin", "default", UISkin, 256, szFilename);

	CHAR szBuffer[50];
	sprintf_s(szBuffer, "/loadskin %s 1", UISkin);

	DoCommand(pChar, szBuffer);
}

bool bChangedNL = false;
ULONGLONG SellTimer = 0;

void AutoBankPulse()
{
	if (pMerchantWnd)
	{
		if (pMerchantWnd->IsVisible())
		{
			if (!bChangedNL)
			{
				if (pNLMarkedButton)
				{
					pNLMarkedButton->CSetWindowText("Sell Marked");
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
					pNLMarkedButton->CSetWindowText("Never Loot");
					bChangedNL = false;
				}
			}
		}
	}

	if (gStartSelling)
	{
		if (pMerchantWnd && pMerchantWnd->IsVisible())
		{
			if (EverQuestinfo__IsItemPending) {
				DWORD wecantsell = *(DWORD*)EverQuestinfo__IsItemPending;
				if (wecantsell)
					return;
			}

			ULONGLONG now = GetTickCount64();
			if (now < SellTimer + 1200)
				return;

			// user wants us to sell stuff
			for (auto g = selllist.begin(); g != selllist.end(); g++)
			{
				ItemGlobalIndex* gi = (ItemGlobalIndex*)&*g;
				if (PCHARINFO pCharInfo = GetCharInfo())
				{
					if (CharacterBase* cb = (CharacterBase*)&pCharInfo->CharacterBase_vftable)
					{
						VePointer<CONTENTS> ptr = cb->GetItemByGlobalIndex(*gi);
						if (ptr.pObject)
						{
							if (PITEMINFO pItem = GetItemFromContents(ptr.pObject))
							{
								CMerchantWnd* pmercho = (CMerchantWnd*)pMerchantWnd;
								bool bwesold = false;
								if (pmercho->pSelectedItem.pObject)
								{
									if (pmercho->pSelectedItem.pObject->ID == ptr.pObject->ID)
									{
										selllist.pop_front();
										WriteChatf("Sold %d %s", pItem->StackSize, pItem->Name);

										if (((EQ_Item*)ptr.pObject)->IsStackable())
										{
											DoCommandf("/sellitem %d", pItem->StackSize);
										}
										else
										{
											DoCommandf("/sellitem 1");
										}
										SellTimer = GetTickCount64();
										bwesold = true;
										break;
									}
								}
								if (!bwesold) {
#if !defined(ROF2EMU) && !defined(UFEMU)
									pmercho->SelectBuySellSlot(gi, gi->Index.Slot1);
#else
									pmercho->SelectBuySellSlot(gi);
#endif
									break;
								}
							}
						}
					}
				}

				selllist.pop_front();
				break;
			}

			if (selllist.empty())
				gStartSelling = false;
		}
		else
		{
			selllist.clear();
			gStartSelling = false;
		}
		return;
	}

	if (gStartDeleting)
	{
		if (pCursorAttachment && pCursorAttachment->Type == -1/*none*/)
		{
			// user wants us to delete stuff
			for (auto g = deletelist.begin(); g != deletelist.end(); g++)
			{
				ItemGlobalIndex* gi = (ItemGlobalIndex*)&(*g);
				if (PCHARINFO pCharInfo = GetCharInfo())
				{
					if (CharacterBase* cb = (CharacterBase*)&pCharInfo->CharacterBase_vftable)
					{
						VePointer<CONTENTS> ptr = cb->GetItemByGlobalIndex(*gi);
						if (ptr.pObject)
						{
							if (PITEMINFO pItem = GetItemFromContents(ptr.pObject))
							{
								if (PickupItemNew(ptr.pObject))
								{
									deletelist.pop_front();
									WriteChatf("Destroyed %s", pItem->Name);
									DoCommandf("/destroyitem");
									break;
								}
							}
						}
					}
				}

				deletelist.pop_front();
				break;
			}

			if (deletelist.empty())
				gStartDeleting = false;
		}

		return;
	}

	if (!gStartAutoBanking)
	{
		return;
	}

	if (!pBankWnd || (pBankWnd && pBankWnd->IsVisible() == 0))
	{
		gStartAutoBanking = false;
		bAutoBankInProgress = false;
		bAutoInventoryInProgress = false;

		if (gAutoBankButton && gAutoBankButton->Checked)
			gAutoBankButton->Checked = false;

		autobanklist.clear();
		autoinventorylist.clear();
		return;
	}

	if (gAutoInventoryItems && !bAutoInventoryInProgress)
	{
		// user wants us to move items FROM bank back to their inventory

		if (autoinventorylist.empty() && (gAutoBankTradeSkillItems || gAutoBankCollectibleItems || gAutoBankQuestItems))
		{
#ifdef NEWCHARINFO
			if (PCHARINFO pChar = GetCharInfo()) {
#else
			if (PCHARINFONEW pChar = (PCHARINFONEW)GetCharInfo()) {
#endif
				// check toplevel slots
				for (DWORD slot = 0; slot < pChar->BankItems.Items.Size; slot++)
				{
					if (PCONTENTS pCont = pChar->BankItems.Items[slot].pObject)
					{
						if (PITEMINFO pItem = GetItemFromContents(pCont))
						{
							if (pItem->Type == ITEMTYPE_PACK && !((EQ_Item*)pCont)->IsEmpty())
								continue; // dont add bags that has items inside of them...

							if (gAutoBankTradeSkillItems && pItem->TradeSkills)
							{
								autoinventorylist.push_back(pCont->GetGlobalIndex());
							}
							else if (gAutoBankCollectibleItems && pItem->Collectible)
							{
								autoinventorylist.push_back(pCont->GetGlobalIndex());
							}
							else if (gAutoBankQuestItems && pItem->QuestItem)
							{
								autoinventorylist.push_back(pCont->GetGlobalIndex());
							}
						}
					}
				}

				// check the bags
				for (DWORD slot = 0; slot < pChar->BankItems.Items.Size; slot++)
				{
					if (PCONTENTS pPack = pChar->BankItems.Items[slot].pObject)
					{
						if (GetItemFromContents(pPack)->Type == ITEMTYPE_PACK && pPack->Contents.ContainedItems.pItems)
						{
							for (unsigned long nItem = 0; nItem < GetItemFromContents(pPack)->Slots; nItem++)
							{
								if (PCONTENTS pCont = pPack->GetContent(nItem))
								{
									if (PITEMINFO pItem = GetItemFromContents(pCont))
									{
										if (gAutoBankTradeSkillItems && pItem->TradeSkills)
										{
											autoinventorylist.push_back(pCont->GetGlobalIndex());
										}
										else if (gAutoBankCollectibleItems && pItem->Collectible)
										{
											autoinventorylist.push_back(pCont->GetGlobalIndex());
										}
										else if (gAutoBankQuestItems && pItem->QuestItem)
										{
											autoinventorylist.push_back(pCont->GetGlobalIndex());
										}
									}
								}
							}
						}
					}
				}
			}
		}

		if (!autoinventorylist.empty())
		{
			bAutoInventoryInProgress = true;
		}
		else
		{
			gStartAutoBanking = false;
			bAutoInventoryInProgress = false;

			if (gAutoBankButton && gAutoBankButton->Checked)
				gAutoBankButton->Checked = false;

			WriteChatf("\ay[No Items Found for Auto Inventory.]\ax\n");
			return;
		}
	}

	// user wants us to autobank stuff
	else if (!gAutoInventoryItems && !bAutoBankInProgress)
	{
		if (autobanklist.empty() && (gAutoBankTradeSkillItems || gAutoBankCollectibleItems || gAutoBankQuestItems))
		{
			// check toplevel slots
			PCHARINFO2 pChar2 = GetCharInfo2();
			if (pChar2 && pChar2->pInventoryArray && pChar2->pInventoryArray->InventoryArray)
			{
				for (PCONTENTS pCont : pChar2->pInventoryArray->InventoryArray)
				{
					if (pCont)
					{
						if (PITEMINFO pItem = GetItemFromContents(pCont))
						{
							if (pItem->Type == ITEMTYPE_PACK && !((EQ_Item*)pCont)->IsEmpty())
								continue; //dont add bags that has items inside of them...

							if (gAutoBankTradeSkillItems && pItem->TradeSkills)
							{
								autobanklist.push_back(pCont->GetGlobalIndex());
							}
							else if (gAutoBankCollectibleItems && pItem->Collectible)
							{
								autobanklist.push_back(pCont->GetGlobalIndex());
							}
							else if (gAutoBankQuestItems && pItem->QuestItem)
							{
								autobanklist.push_back(pCont->GetGlobalIndex());
							}
						}
					}
				}
			}

			// check the bags
			if (pChar2 && pChar2->pInventoryArray)
			{
				for (PCONTENTS pPack : pChar2->pInventoryArray->Inventory.Pack)
				{
					if (pPack)
					{
						if (GetItemFromContents(pPack)->Type == ITEMTYPE_PACK && pPack->Contents.ContainedItems.pItems)
						{
							for (unsigned long nItem = 0; nItem < GetItemFromContents(pPack)->Slots; nItem++)
							{
								if (PCONTENTS pCont = pPack->GetContent(nItem))
								{
									if (PITEMINFO pItem = GetItemFromContents(pCont))
									{
										if (gAutoBankTradeSkillItems && pItem->TradeSkills)
										{
											autobanklist.push_back(pCont->GetGlobalIndex());
										}
										else if (gAutoBankCollectibleItems && pItem->Collectible)
										{
											autobanklist.push_back(pCont->GetGlobalIndex());
										}
										else if (gAutoBankQuestItems && pItem->QuestItem)
										{
											autobanklist.push_back(pCont->GetGlobalIndex());
										}
									}
								}
							}
						}
					}
				}
			}
		}

		if (!autobanklist.empty())
		{
			bAutoBankInProgress = true;
		}
		else
		{
			gStartAutoBanking = false;
			bAutoBankInProgress = false;

			if (gAutoBankButton && gAutoBankButton->Checked)
				gAutoBankButton->Checked = false;

			WriteChatf("\ay[No Items Found for Auto Banking.]\ax\n");
			return;
		}
	}

	if (PCHARINFO2 pChar2 = GetCharInfo2())
	{
		if (pChar2->pInventoryArray && pChar2->pInventoryArray->Inventory.Cursor != 0)
		{
			if (bAutoInventoryInProgress)
				DoCommandf("/autoinventory");
			else
				DoCommandf("/autobank");
			return;
		}
	}

	if (!autoinventorylist.empty())
		{
		const ItemGlobalIndex2& ind = autoinventorylist.front();

		if (PCONTENTS pCont = FindItemBySlot(ind.Index.Slot1, ind.Index.Slot2, ind.Location))
			{
				if (PITEMINFO pItem = GetItemFromContents(pCont))
				{
					ItemGlobalIndex2 indy = pCont->GetGlobalIndex();
					if (WillFitInInventory(pCont))
					{
						WriteChatf("[%d] Moving %s from slot %d %d to inventory", autoinventorylist.size(), pItem->Name, indy.Index.Slot1, indy.Index.Slot2);
						PickupItem(indy.Location, pCont);
					}
				else
				{
						WriteChatf("[%d] \arAutoinventory for %s from slot %d %d to inventory \ayFAILED\ar, you are out of space.\ax", autoinventorylist.size(), pItem->Name, indy.Index.Slot1, indy.Index.Slot2);
					}
				}
			}
		else
		{
				WriteChatf("[%d] \arAutoinventory for slot %d %d to inventory \ayFAILED\ar, no item was found.\ax", autoinventorylist.size(), ind.Index.Slot1, ind.Index.Slot2);
			}
		autoinventorylist.pop_front();
		return;
	}

	if (!autobanklist.empty())
		{
		const ItemGlobalIndex2& ind = autobanklist.front();

		if (PCONTENTS pCont = FindItemBySlot(ind.Index.Slot1, ind.Index.Slot2, ind.Location))
			{
				if (PITEMINFO pItem = GetItemFromContents(pCont))
				{
					ItemGlobalIndex2 indy = pCont->GetGlobalIndex();
					if (WillFitInBank(pCont))
					{
						WriteChatf("[%d] Moving %s from slot %d %d to bank", autobanklist.size(), pItem->Name, indy.Index.Slot1, indy.Index.Slot2);
						PickupItem(indy.Location, pCont);
					}
					else {
						WriteChatf("[%d] \arAutoBank for %s from slot %d %d to bank \ayFAILED\ar, you are out of space.\ax", autobanklist.size(), pItem->Name, indy.Index.Slot1, indy.Index.Slot2);
					}
				}
			}
		else
		{
			WriteChatf("[%d] \arAutoBank for slot %d %d to bank \ayFAILED\ar, no item was found.\ax", autobanklist.size(), ind.Index.Slot1, ind.Index.Slot2);
		}
		autobanklist.pop_front();
		return;
	}

	if (bAutoInventoryInProgress)
	{
		if (gAutoBankButton && gAutoBankButton->Checked)
			gAutoBankButton->Checked = false;

		bAutoInventoryInProgress = false;
		gStartAutoBanking = false;
		WriteChatf("\ay[Autoinventory Finished.]\ax");
	}	
	else if (bAutoBankInProgress)
	{
		if (gAutoBankButton && gAutoBankButton->Checked)
			gAutoBankButton->Checked = false;

		bAutoBankInProgress = false;
		gStartAutoBanking = false;
		WriteChatf("\ay[AutoBank Finished.]\ax");
	}	
}
