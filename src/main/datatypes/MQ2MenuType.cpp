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

#include "pch.h"
#include "MQ2DataTypes.h"

using namespace mq;
using namespace mq::datatypes;

bool MQ2MenuType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	CContextMenuManager* pMgr = static_cast<CContextMenuManager*>(VarPtr.Ptr);
	if (!pMgr)
		return false;

	//------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2MenuType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<MenuMethods>(pMethod->ID))
		{
		case Select: {
			if (Index[0])
			{
				if (pMgr->NumVisibleMenus == 1)
				{
					if (pMgr->CurrMenu < MAX_CONTEXT_MENU_DEPTH)
					{
						int currItem = pMgr->CurrMenu;
						if (CContextMenu* menu = pMgr->pCurrMenus[currItem])
						{
							for (int i = 0; i < menu->NumItems; i++)
							{
								CXStr Str = menu->GetItemText(i, 1);
								if (!Str.empty())
								{
									if (ci_find_substr(Str, Index))
									{
										WriteChatf("\ay[${Menu.Select}] SUCCESS\ax: Clicking \"%s\" at position %d in the menu.", Str.c_str(), i);

										pMgr->WndNotification(menu, XWM_LMOUSEUP, (void*)i);
										Dest.DWord = 1;
										Dest.Type = pBoolType;
										return true;
									}
								}
							}

							WriteChatf("\ar[${Menu.Select}] FAILED\ax: No Menu item was found with the word %s in it", Index);
						}
					}
				}
			}
			break;
		}

		default: break;
		}

		Dest.DWord = 0;
		Dest.Type = pBoolType;
		return true;
	}

	//------------------------------------------------------------------------
	// members

	MQTypeMember* pMember = MQ2MenuType::FindMember(Member);
	if (!pMember)
	{
		if (pMgr->NumVisibleMenus == 1)
		{
			if (CContextMenu* pMenu = pMgr->pCurrMenus[pMgr->CurrMenu])
			{
				MQVarPtr data;
				data.Ptr = pMenu;

				return pWindowType->GetMember(data, Member, Index, Dest);
			}
		}
		return false;
	}

	switch (static_cast<MenuMembers>(pMember->ID))
	{
	case Address:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pMgr->NumVisibleMenus == 1)
		{
			if (CContextMenu* pMenu = pMgr->pCurrMenus[pMgr->CurrMenu])
			{
				Dest.DWord = (uint32_t)pMenu;
				return true;
			}
		}
		return false;

	case NumVisibleMenus:
		Dest.DWord = pMgr->NumVisibleMenus;
		Dest.Type = pIntType;
		return true;

	case CurrMenu:
		Dest.DWord = pMgr->CurrMenu;
		Dest.Type = pIntType;
		return true;

	case Name:
		Dest.Type = pStringType;
		if (pMgr->NumVisibleMenus == 1)
		{
			if (pMgr->CurrMenu < MAX_CONTEXT_MENU_DEPTH)
			{
				int currMenu = pMgr->CurrMenu;
				if (CContextMenu* menu = pMgr->pCurrMenus[currMenu])
				{
					CXStr Str = menu->GetItemText(0, 1);
					if (!Str.empty())
					{
						strcpy_s(DataTypeTemp, Str.c_str());
						Dest.Ptr = &DataTypeTemp[0];
						return true;
					}
				}
			}
		}
		return false;

	case NumItems:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pMgr->NumVisibleMenus == 1)
		{
			if (pMgr->CurrMenu < MAX_CONTEXT_MENU_DEPTH)
			{
				int currmen = pMgr->CurrMenu;
				if (CContextMenu* menu = pMgr->pCurrMenus[currmen])
				{
					Dest.DWord = menu->NumItems;
					return true;
				}
			}
		}
		return false;

	case Items:
		Dest.Type = pStringType;
		if (IsNumber(Index))
		{
			if (pMgr->NumVisibleMenus == 1)
			{
				if (pMgr->CurrMenu < MAX_CONTEXT_MENU_DEPTH)
				{
					int index = GetIntFromString(Index, 0);
					int currmen = pMgr->CurrMenu;

					if (CContextMenu* menu = pMgr->pCurrMenus[currmen])
					{
						if (index < menu->NumItems)
						{
							CXStr Str = menu->GetItemText(index, 1);
							strcpy_s(DataTypeTemp, Str.c_str());
							Dest.Ptr = &DataTypeTemp[0];
							return true;
						}
					}
				}
			}
			return false;
		}

	default: break;
	}

	return false;
}

