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

enum class WindowMembers
{
	Open,
	Child,
	VScrollMax,
	VScrollPos,
	VScrollPct,
	HScrollMax,
	HScrollPos,
	HScrollPct,
	Children,
	Siblings,
	Parent,
	FirstChild,
	Next,
	Minimized,
	X,
	Y,
	Height,
	Width,
	MouseOver,
	BGColor,
	Text,
	Tooltip,
	List,
	Checked,
	Style,
	Enabled,
	Highlighted,
	Name,
	ScreenID,
	Type,
	Items,
	HisTradeReady,
	MyTradeReady,
	GetCurSel,
	Address,
	Size
};

enum class WindowMethods
{
	LeftMouseDown,
	LeftMouseUp,
	LeftMouseHeld,
	LeftMouseHeldUp,
	RightMouseDown,
	RightMouseUp,
	RightMouseHeld,
	RightMouseHeldUp,
	DoOpen,
	DoClose,
	Select
};

MQ2WindowType::MQ2WindowType() : MQ2Type("window")
{
	ScopedTypeMember(WindowMembers, Open);
	ScopedTypeMember(WindowMembers, Child);
	ScopedTypeMember(WindowMembers, VScrollMax);
	ScopedTypeMember(WindowMembers, VScrollPos);
	ScopedTypeMember(WindowMembers, VScrollPct);
	ScopedTypeMember(WindowMembers, HScrollMax);
	ScopedTypeMember(WindowMembers, HScrollPos);
	ScopedTypeMember(WindowMembers, HScrollPct);
	ScopedTypeMember(WindowMembers, Children);
	ScopedTypeMember(WindowMembers, Parent);
	ScopedTypeMember(WindowMembers, Siblings);
	ScopedTypeMember(WindowMembers, FirstChild);
	ScopedTypeMember(WindowMembers, Next);
	ScopedTypeMember(WindowMembers, Minimized);
	ScopedTypeMember(WindowMembers, X);
	ScopedTypeMember(WindowMembers, Y);
	ScopedTypeMember(WindowMembers, Height);
	ScopedTypeMember(WindowMembers, Width);
	ScopedTypeMember(WindowMembers, MouseOver);
	ScopedTypeMember(WindowMembers, BGColor);
	ScopedTypeMember(WindowMembers, Text);
	ScopedTypeMember(WindowMembers, Tooltip);
	ScopedTypeMember(WindowMembers, List);
	ScopedTypeMember(WindowMembers, Checked);
	ScopedTypeMember(WindowMembers, Style);
	ScopedTypeMember(WindowMembers, Enabled);
	ScopedTypeMember(WindowMembers, Highlighted);
	ScopedTypeMember(WindowMembers, Name);
	ScopedTypeMember(WindowMembers, ScreenID);
	ScopedTypeMember(WindowMembers, Type);
	ScopedTypeMember(WindowMembers, Items);
	ScopedTypeMember(WindowMembers, HisTradeReady);
	ScopedTypeMember(WindowMembers, MyTradeReady);
	ScopedTypeMember(WindowMembers, GetCurSel);
	ScopedTypeMember(WindowMembers, Address);
	ScopedTypeMember(WindowMembers, Size);

	ScopedTypeMethod(WindowMethods, LeftMouseDown);
	ScopedTypeMethod(WindowMethods, LeftMouseUp);
	ScopedTypeMethod(WindowMethods, LeftMouseHeld);
	ScopedTypeMethod(WindowMethods, LeftMouseHeldUp);
	ScopedTypeMethod(WindowMethods, RightMouseDown);
	ScopedTypeMethod(WindowMethods, RightMouseUp);
	ScopedTypeMethod(WindowMethods, RightMouseHeld);
	ScopedTypeMethod(WindowMethods, RightMouseHeldUp);
	ScopedTypeMethod(WindowMethods, DoOpen);
	ScopedTypeMethod(WindowMethods, DoClose);
	ScopedTypeMethod(WindowMethods, Select);
}

bool MQ2WindowType::GetMember(MQVarPtr VarPtr, char* Member, char* Index, MQTypeVar& Dest)
{
	CXWnd* pWnd = static_cast<CXWnd*>(VarPtr.Ptr);
	if (!VarPtr.Ptr)
		return false;

	//----------------------------------------------------------------------------
	// methods

	MQTypeMember* pMethod = MQ2WindowType::FindMethod(Member);
	if (pMethod)
	{
		switch (static_cast<WindowMethods>(pMethod->ID))
		{
		case WindowMethods::LeftMouseDown:
			SendWndClick2(pWnd, "leftmousedown");
			return true;

		case WindowMethods::LeftMouseUp:
			SendWndClick2(pWnd, "leftmouseup");
			return true;

		case WindowMethods::LeftMouseHeld:
			SendWndClick2(pWnd, "leftmouseheld");
			return true;

		case WindowMethods::LeftMouseHeldUp:
			SendWndClick2(pWnd, "leftmouseheldup");
			return true;

		case WindowMethods::RightMouseDown:
			SendWndClick2(pWnd, "rightmousedown");
			return true;

		case WindowMethods::RightMouseUp:
			SendWndClick2(pWnd, "rightmouseup");
			return true;

		case WindowMethods::RightMouseHeld:
			SendWndClick2(pWnd, "rightmouseheld");
			return true;

		case WindowMethods::RightMouseHeldUp:
			SendWndClick2(pWnd, "rightmouseheldup");
			return true;

		case WindowMethods::DoOpen:
			pWnd->Show(true, true);
			return true;

		case WindowMethods::DoClose:
			pWnd->Show(false, true);
			return true;

		case WindowMethods::Select: {
			int ListIndex = GetIntFromString(Index, 0) - 1;
			if (ListIndex < 0)
				ListIndex = 0;

			if (pWnd->GetType() == UI_Listbox)
			{
				CListWnd* listWnd = static_cast<CListWnd*>(pWnd);
				if (listWnd->ItemsArray.Count < ListIndex)
					return false;

				listWnd->SetCurSel(ListIndex);
				int index = listWnd->GetCurSel();

				listWnd->EnsureVisible(index);
				CXPoint pt = listWnd->GetItemRect(index, 0).CenterPoint();

				pWnd->HandleLButtonDown(pt, 0);
				pWnd->HandleLButtonUp(pt, 0);
				WeDidStuff();
				return true;
			}

			if (pWnd->GetType() == UI_Combobox)
			{
				CComboWnd* comboWnd = static_cast<CComboWnd*>(pWnd);

				if (CListWnd* pListWnd = comboWnd->pListWnd)
				{
					if (pListWnd->ItemsArray.Count < ListIndex)
						return false;

					CXPoint combopt = pWnd->GetScreenRect().CenterPoint();
					comboWnd->SetChoice(ListIndex);
					comboWnd->HandleLButtonDown(combopt, 0);

					int index = pListWnd->GetCurSel();
					CXPoint listpt = pListWnd->GetItemRect(index, 0).CenterPoint();
					pListWnd->HandleLButtonDown(listpt, 0);
					pListWnd->HandleLButtonUp(listpt, 0);

					WeDidStuff();
					return true;
				}
			}
			return false;
		}

		default: break;
		}

		return false;
	}

	//----------------------------------------------------------------------------
	// members

	MQTypeMember* pMember = MQ2WindowType::FindMember(Member);
	if (!pMember)
		return false;

	switch (static_cast<WindowMembers>(pMember->ID))
	{
	case WindowMembers::Address:
		Dest.DWord = reinterpret_cast<uint32_t>(pWnd);
		Dest.Type = pIntType;
		return true;

	case WindowMembers::Open:
		Dest.DWord = pWnd->IsVisible();
		Dest.Type = pBoolType;
		return true;

	case WindowMembers::Child:
		if (Dest.Ptr = pWnd->GetChildItem(Index))
		{
			Dest.Type = pWindowType;
			return true;
		}
		Dest.DWord = 0;
		Dest.Type = pIntType;
		return true;

	case WindowMembers::Parent:
		if (Dest.Ptr = pWnd->GetParentWindow())
		{
			Dest.Type = pWindowType;
			return true;
		}
		Dest.DWord = 0;
		Dest.Type = pIntType;
		return true;

	case WindowMembers::FirstChild:
		if (Dest.Ptr = pWnd->GetFirstChildWnd())
		{
			Dest.Type = pWindowType;
			return true;
		}
		Dest.DWord = 0;
		Dest.Type = pIntType;
		return true;

	case WindowMembers::Next:
		if (Dest.Ptr = pWnd->GetNextSiblingWnd())
		{
			Dest.Type = pWindowType;
			return true;
		}
		Dest.DWord = 0;
		Dest.Type = pIntType;
		return true;

	case WindowMembers::VScrollMax:
		Dest.DWord = pWnd->GetVScrollMax();
		Dest.Type = pIntType;
		return true;

	case WindowMembers::VScrollPos:
		Dest.DWord = pWnd->GetVScrollPos();
		Dest.Type = pIntType;
		return true;

	case WindowMembers::VScrollPct:
		Dest.DWord = (pWnd->GetVScrollPos() * 100) / pWnd->GetVScrollMax();
		Dest.Type = pIntType;
		return true;

	case WindowMembers::HScrollMax:
		Dest.DWord = pWnd->GetHScrollMax();
		Dest.Type = pIntType;
		return true;

	case WindowMembers::HScrollPos:
		Dest.DWord = pWnd->GetHScrollPos();
		Dest.Type = pIntType;
		return true;

	case WindowMembers::HScrollPct:
		Dest.DWord = (pWnd->GetHScrollPos() * 100) / pWnd->GetHScrollMax();
		Dest.Type = pIntType;
		return true;

	case WindowMembers::Children:
		Dest.DWord = pWnd->GetFirstChildWnd() != nullptr;
		Dest.Type = pBoolType;
		return true;

	case WindowMembers::Siblings:
		Dest.DWord = pWnd->GetNextSiblingWnd() != nullptr;
		Dest.Type = pBoolType;
		return true;

	case WindowMembers::Minimized:
		Dest.DWord = pWnd->IsMinimized();
		Dest.Type = pBoolType;
		return true;

	case WindowMembers::MouseOver:
		Dest.DWord = pWnd->IsMouseOver();
		Dest.Type = pBoolType;
		return true;

	case WindowMembers::X:
		Dest.DWord = pWnd->GetLocation().left;
		Dest.Type = pIntType;
		return true;

	case WindowMembers::Y:
		Dest.DWord = pWnd->GetLocation().top;
		Dest.Type = pIntType;
		return true;

	case WindowMembers::Size:
		sprintf_s(DataTypeTemp, "%d,%d", pWnd->GetLocation().bottom - pWnd->GetLocation().top,
			pWnd->GetLocation().right - pWnd->GetLocation().left);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case WindowMembers::Width:
		Dest.DWord = pWnd->GetLocation().right - pWnd->GetLocation().left;
		Dest.Type = pIntType;
		return true;

	case WindowMembers::Height:
		Dest.DWord = pWnd->GetLocation().bottom - pWnd->GetLocation().top;
		Dest.Type = pIntType;
		return true;

	case WindowMembers::BGColor:
		Dest.DWord = pWnd->GetBGColor();
		Dest.Type = pArgbType;
		return true;

	case WindowMembers::Text:
		if (pWnd->GetType() == UI_STMLBox)
		{
			CStmlWnd* cstmlwnd = static_cast<CStmlWnd*>(pWnd);
			strcpy_s(DataTypeTemp, cstmlwnd->STMLText.c_str());
		}
		else
		{
			strcpy_s(DataTypeTemp, pWnd->GetWindowText().c_str());
		}
		DataTypeTemp[MAX_STRING - 1] = '\0';
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case WindowMembers::Tooltip:
		strcpy_s(DataTypeTemp, pWnd->GetTooltip().c_str());
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case WindowMembers::Checked:
		Dest.Int = ((CButtonWnd*)pWnd)->bChecked;
		Dest.Type = pBoolType;
		return true;

	case WindowMembers::Highlighted: // if the window in question has focus...
		Dest.Int = false;
		Dest.Type = pBoolType;
		if (pWndMgr)
		{
			if (pWnd == pWndMgr->FocusWindow)
				Dest.Int = true;
		}
		return true;

	case WindowMembers::Enabled:
		Dest.Int = pWnd->IsEnabled();
		Dest.Type = pBoolType;
		return true;

	case WindowMembers::Style:
		Dest.DWord = pWnd->GetWindowStyle();
		Dest.Type = pIntType;
		return true;

	case WindowMembers::List: {
		Dest.Type = pStringType;
		CListWnd* pListWnd = nullptr;

		if (pWnd->GetType() == UI_Combobox)
		{
			CComboWnd* combownd = static_cast<CComboWnd*>(pWnd);
			pListWnd = combownd->pListWnd;
		}
		else if (pWnd->GetType() == UI_Listbox)
		{
			pListWnd = static_cast<CListWnd*>(pWnd);
		}
		else
		{
			return false;
		}

		int n = 0;
		if (char* pComma = strchr(Index, ','))
		{
			n = GetIntFromString(&pComma[1], n) - 1;
			if (n < 0) n = 0;
			*pComma = '\0';
		}

		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, 0);
			if (!nIndex)
				return false;

			CXStr Str = pListWnd->GetItemText(nIndex - 1, n);
			strcpy_s(DataTypeTemp, Str.c_str());
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		}
		else
		{
			// name
			bool bEqual = false;
			std::string_view sv;

			if (Index[0] == '=')
			{
				bEqual = true;
				sv = &Index[1];
			}
			else
			{
				sv = Index;
			}

			int nIndex = 0;
			while (true)
			{
				CXStr Str = pListWnd->GetItemText(nIndex, n);
				if (Str.empty())
					return false;

				if (bEqual)
				{
					if (ci_equals(Str, sv))
					{
						Dest.DWord = nIndex + 1;
						Dest.Type = pIntType;
						return true;
					}
				}
				else
				{
					if (ci_find_substr(Str, sv) != -1)
					{
						Dest.DWord = nIndex + 1;
						Dest.Type = pIntType;
						return true;
					}
				}
				nIndex++;
			}
		}
		return false;
	}

	case WindowMembers::Name:
		Dest.Type = pStringType;
		if (CXMLData* pXMLData = pWnd->GetXMLData())
		{
			if (!pXMLData->Name.empty())
			{
				strcpy_s(DataTypeTemp, pXMLData->Name.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}
		}
		return false;

	case WindowMembers::ScreenID:
		Dest.Type = pStringType;
		if (CXMLData* pXMLData = pWnd->GetXMLData())
		{
			if (!pXMLData->ScreenID.empty())
			{
				strcpy_s(DataTypeTemp, pXMLData->ScreenID.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}
		}
		return false;

	case WindowMembers::Type:
		Dest.Type = pStringType;
		if (CXMLData* pXMLData = pWnd->GetXMLData())
		{
			if (!pXMLData->TypeName.empty())
			{
				strcpy_s(DataTypeTemp, pXMLData->TypeName.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				return true;
			}
		}
		return false;

	case WindowMembers::Items:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pWnd->GetType() == UI_Listbox)
		{
			CListWnd* clist = static_cast<CListWnd*>(pWnd);
			Dest.DWord = clist->ItemsArray.Count;
		}
		else if (pWnd->GetType() == UI_Combobox)
		{
			CComboWnd* ccombo = static_cast<CComboWnd*>(pWnd);
			if (ccombo->pListWnd)
			{
				Dest.DWord = ccombo->pListWnd->ItemsArray.Count;
			}
		}
		return true;

	case WindowMembers::HisTradeReady:
		Dest.Int = 0;
		Dest.Type = pBoolType;
		if (pTradeWnd)
		{
			Dest.Int = pTradeWnd->bHisReadyTrade;
		}
		return true;

	case WindowMembers::MyTradeReady:
		Dest.Int = 0;
		Dest.Type = pBoolType;
		if (pTradeWnd)
		{
			Dest.Int = pTradeWnd->bMyReadyTrade;
		}
		return true;

	case WindowMembers::GetCurSel: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

		CListWnd* pListWnd = nullptr;

		if (pWnd->GetType() == UI_Combobox)
		{
			CComboWnd* combo = static_cast<CComboWnd*>(pWnd);
			Dest.DWord = combo->pListWnd ? combo->pListWnd->GetCurSel() + 1 : 0;
			return true;
		}

		if (pWnd->GetType() == UI_Listbox)
		{
			CListWnd* list = static_cast<CListWnd*>(pWnd);
			Dest.DWord = list->GetCurSel() + 1;
			return true;
		}

		return false;
	}

	default: break;
	}

	return false;
}

bool MQ2WindowType::ToString(MQVarPtr VarPtr, char* Destination)
{
	CXWnd* pWnd = static_cast<CXWnd*>(VarPtr.Ptr);

	if (pWnd)
	{
		if (pWnd->IsVisible())
			strcpy_s(Destination, MAX_STRING, "TRUE");
		else
			strcpy_s(Destination, MAX_STRING, "FALSE");
	}
	return true;
}

bool MQ2WindowType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	if (Source.Type != pWindowType)
		return false;
	VarPtr.Ptr = Source.Ptr;
	return true;
}

bool MQ2WindowType::FromString(MQVarPtr& VarPtr, char* Source)
{
	if (VarPtr.Ptr = FindMQ2WindowPath(Source))
		return true;

	return false;
}

