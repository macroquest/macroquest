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
#include "MQ2DataTypes.h"

namespace mq::datatypes {

enum class MenuMembers
{
	NumVisibleMenus = 1,
	CurrMenu,
	Name,
	NumItems,
	Items,
};

enum class MenuMethods
{
	Select = 1,
};

MQ2MenuType::MQ2MenuType() : MQ2Type("menu")
{
	ScopedTypeMember(MenuMembers, NumVisibleMenus);
	ScopedTypeMember(MenuMembers, CurrMenu);
	ScopedTypeMember(MenuMembers, Name);
	ScopedTypeMember(MenuMembers, NumItems);
	ScopedTypeMember(MenuMembers, Items);

	ScopedTypeMethod(MenuMethods, Select);
}

bool MQ2MenuType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
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
		case MenuMethods::Select: {
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

#pragma warning(suppress : 4312)
										pMgr->WndNotification(menu, XWM_LMOUSEUP, (void*)i);
										Dest.Set(true);
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

		Dest.Set(false);
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
	case MenuMembers::NumVisibleMenus:
		Dest.DWord = pMgr->NumVisibleMenus;
		Dest.Type = pIntType;
		return true;

	case MenuMembers::CurrMenu:
		Dest.DWord = pMgr->CurrMenu;
		Dest.Type = pIntType;
		return true;

	case MenuMembers::Name:
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

	case MenuMembers::NumItems:
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

	case MenuMembers::Items:
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

bool MQ2MenuType::ToString(MQVarPtr VarPtr, char* Destination)
{
	strcpy_s(Destination, MAX_STRING, "No Menu Open");
	if (VarPtr.Ptr && ((CContextMenuManager*)VarPtr.Ptr)->NumVisibleMenus == 1)
	{
		CContextMenuManager* pMgr = (CContextMenuManager*)VarPtr.Ptr;
		if (pMgr->CurrMenu < 8)
		{
			int currmen = pMgr->CurrMenu;
			if (CContextMenu* menu = pMgr->pCurrMenus[currmen])
			{
				strcpy_s(Destination, MAX_STRING, menu->GetItemText(0, 1).c_str());
			}
		}
	}
	return true;
}

bool MQ2MenuType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type == this)
	{
		VarPtr = Source;
		return true;
	}

	return false;
}

bool MQ2MenuType::dataMenu(const char* szIndex, MQTypeVar& Ret)
{
	if (CContextMenuManager* pMrg = pContextMenuManager)
	{
		if (Ret.Ptr = pMrg)
		{
			Ret.Type = pMenuType;
			return true;
		}
	}

	return false;
}

} // namespace mq::datatypes
