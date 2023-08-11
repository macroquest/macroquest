/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-2023 MacroQuest Authors
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

enum class WindowMembers
{
	Open = 1,
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
	Size,
	Value,
	TabCount,
	Tab,
	CurrentTab,
	CurrentTabIndex,
};

enum class WindowMethods
{
	LeftMouseDown = 1,
	LeftMouseUp,
	LeftMouseHeld,
	LeftMouseHeldUp,
	RightMouseDown,
	RightMouseUp,
	RightMouseHeld,
	RightMouseHeldUp,
	DoOpen,
	DoClose,
	Select,
	Move,
	SetBGColor,
	SetAlpha,
	SetFadeAlpha,
	SetCurrentTab,
	SetText,
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
	ScopedTypeMember(WindowMembers, Size);
	ScopedTypeMember(WindowMembers, Value);
	ScopedTypeMember(WindowMembers, TabCount);
	ScopedTypeMember(WindowMembers, Tab);
	ScopedTypeMember(WindowMembers, CurrentTab);
	ScopedTypeMember(WindowMembers, CurrentTabIndex);

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
	ScopedTypeMethod(WindowMethods, Move);
	ScopedTypeMethod(WindowMethods, SetBGColor);
	ScopedTypeMethod(WindowMethods, SetAlpha);
	ScopedTypeMethod(WindowMethods, SetFadeAlpha);
	ScopedTypeMethod(WindowMethods, SetCurrentTab);
	ScopedTypeMethod(WindowMethods, SetText);
}

bool MQ2WindowType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
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

			if (pWnd->GetType() == UI_Listbox || pWnd->GetType() == UI_TreeView)
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

		case WindowMethods::Move: {
			if (Index[0])
			{
				char szLeft[MAX_STRING] = { 0 };
				char szTop[MAX_STRING] = { 0 };
				char szWidth[MAX_STRING] = { 0 };
				char szHeight[MAX_STRING] = { 0 };
				GetArg(szLeft, Index, 1, false, false, false, ',');
				GetArg(szTop, Index, 2, false, false, false, ',');
				GetArg(szWidth, Index, 3, false, false, false, ',');
				GetArg(szHeight, Index, 4, false, false, false, ',');

				CXRect rc = pWnd->GetLocation();

				if (szLeft[0])
					rc.left = GetIntFromString(szLeft, rc.left);
				if (szTop[0])
					rc.top = GetIntFromString(szTop, rc.top);
				if (szWidth[0])
					rc.right = rc.left + GetIntFromString(szWidth, rc.right - rc.left);
				if (szHeight[0])
					rc.bottom = rc.top + GetIntFromString(szHeight, rc.bottom - rc.top);

				pWnd->Move(rc, true, true, true, true);
			}
			return true;
		}

		case WindowMethods::SetBGColor:
			if (Index[0])
			{
				try
				{
					uint32_t color = std::stoi(Index, nullptr, 16);
					pWnd->SetBGColor(color);
					pWnd->Refade();
				}
				catch (const std::exception&) {}
			}
			return true;

		case WindowMethods::SetAlpha:
			if (Index[0])
			{
				try
				{
					uint8_t alpha = static_cast<uint8_t>(std::stoi(Index, nullptr, 0));
					pWnd->SetAlpha(alpha);
					pWnd->Refade();
				}
				catch (const std::exception&) {}
			}
			return true;

		case WindowMethods::SetFadeAlpha:
			if (Index[0])
			{
				try
				{
					uint8_t alpha = static_cast<uint8_t>(std::stoi(Index, nullptr, 0));
					pWnd->SetFadeToAlpha(alpha);
					pWnd->Refade();
				}
				catch (const std::exception&) {}
			}
			return true;

		case WindowMethods::SetCurrentTab:
			if (pWnd->GetType() == UI_TabBox && Index[0])
			{
				CTabWnd* pTabWnd = static_cast<CTabWnd*>(pWnd);

				if (IsNumber(Index))
				{
					int tabIndex = GetIntFromString(Index, 0) - 1;
					if (tabIndex >= 0 && tabIndex < pTabWnd->PageArray.GetCount())
					{
						pTabWnd->SetPage(tabIndex);
					}
				}
				else
				{
					for (int tabIndex = 0; tabIndex < pTabWnd->PageArray.GetCount(); ++tabIndex)
					{
						if (ci_equals(pTabWnd->PageArray[tabIndex]->TabText, Index))
						{
							pTabWnd->SetPage(tabIndex);
							break;
						}
					}
				}
			}
			return true;

		case WindowMethods::SetText:
			if (pWnd->GetType() == UI_EditBox)
			{
				CEditWnd* pEditWnd = static_cast<CEditWnd*>(pWnd);

				pEditWnd->SetWindowText(Index);
			}
			return true;

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
	case WindowMembers::Open:
		Dest.Set(pWnd->IsVisible());
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
		Dest.Set(pWnd->GetFirstChildWnd() != nullptr);
		Dest.Type = pBoolType;
		return true;

	case WindowMembers::Siblings:
		Dest.Set(pWnd->GetNextSiblingWnd() != nullptr);
		Dest.Type = pBoolType;
		return true;

	case WindowMembers::Minimized:
		Dest.Set(pWnd->IsMinimized());
		Dest.Type = pBoolType;
		return true;

	case WindowMembers::MouseOver:
		Dest.Set(pWnd->IsMouseOver());
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
			strcpy_s(DataTypeTemp, cstmlwnd->GetSTMLText().c_str());
		}
		else if (pWnd->GetType() == UI_Page)
		{
			CPageWnd* pPageWnd = static_cast<CPageWnd*>(pWnd);
			strcpy_s(DataTypeTemp, pPageWnd->TabText.c_str());
		}
		else
		{
			strcpy_s(DataTypeTemp, pWnd->GetWindowText().c_str());
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case WindowMembers::Tooltip:
		strcpy_s(DataTypeTemp, pWnd->GetTooltip().c_str());
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case WindowMembers::Checked:
		Dest.Set(((CButtonWnd*)pWnd)->bChecked);
		Dest.Type = pBoolType;
		return true;

	case WindowMembers::Highlighted: // if the window in question has focus...
		Dest.Type = pBoolType;
		Dest.Set(pWndMgr && pWnd == pWndMgr->FocusWindow);
		return true;

	case WindowMembers::Enabled:
		Dest.Set(pWnd->IsEnabled());
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
		else if (pWnd->GetType() == UI_Listbox || pWnd->GetType() == UI_TreeView)
		{
			pListWnd = static_cast<CListWnd*>(pWnd);
		}
		else
		{
			return false;
		}

		int nColumn = 0;
		if (char* pComma = strchr(Index, ','))
		{
			nColumn = GetIntFromString(&pComma[1], nColumn) - 1;
			if (nColumn < 0) nColumn = 0;
			if (nColumn >= pListWnd->Columns.GetCount())
				return false;
			*pComma = '\0';
		}

		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, 0);
			if (!nIndex)
				return false;
			nIndex = nIndex - 1;
			if (nIndex < 0 || nIndex >= pListWnd->ItemsArray.GetCount())
				return false;

			const SListWndLine& line = pListWnd->ItemsArray[nIndex];
			if (nColumn < 0 || nColumn >= line.Cells.GetLength())
				return false;

			const SListWndCell& cell = line.Cells[nColumn];

			// If this holds a window then return a window
			if (cell.pWnd != nullptr)
			{
				Dest.Ptr = cell.pWnd->GetFirstChildWnd();
				Dest.Type = pWindowType;
				return true;
			}

			CXStr Str = pListWnd->GetItemText(nIndex, nColumn);
			strcpy_s(DataTypeTemp, Str.c_str());
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		}
		else
		{
			// by name/label
			for (int nIndex = 0; nIndex < pListWnd->ItemsArray.GetCount(); ++nIndex)
			{
				const SListWndLine& line = pListWnd->ItemsArray[nIndex];
				if (nColumn < 0 || nColumn >= line.Cells.GetLength())
					return false;

				const SListWndCell& cell = line.Cells[nColumn];

				// If this holds a window then compare against the window text
				if (cell.pWnd != nullptr)
				{
					if (MaybeExactCompare(cell.pWnd->GetFirstChildWnd()->GetWindowText(), Index))
					{
						Dest.DWord = nIndex + 1;
						Dest.Type = pIntType;
						return true;
					}
				}

				CXStr Str = pListWnd->GetItemText(nIndex, nColumn);
				if (MaybeExactCompare(Str, Index))
				{
					Dest.DWord = nIndex + 1;
					Dest.Type = pIntType;
					return true;
				}
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

		if (pWnd->GetType() == UI_Listbox || pWnd->GetType() == UI_TreeView)
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
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (pTradeWnd)
		{
			Dest.Set(pTradeWnd->bHisReadyTrade);
		}
		return true;

	case WindowMembers::MyTradeReady:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (pTradeWnd)
		{
			Dest.Set(pTradeWnd->bMyReadyTrade);
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

		if (pWnd->GetType() == UI_Listbox || pWnd->GetType() == UI_TreeView)
		{
			CListWnd* list = static_cast<CListWnd*>(pWnd);
			Dest.DWord = list->GetCurSel() + 1;
			return true;
		}

		return false;
	}

	case WindowMembers::Value:
		Dest.Type = pFloatType;

		if (pWnd->GetType() == UI_Gauge)
		{
			auto pGauge = static_cast<CGaugeWnd*>(pWnd);
			Dest.Float = pGauge->LastFrameVal;
			return true;
		}

		return false;

	case WindowMembers::TabCount:
		Dest.Type = pIntType;
		Dest.DWord = 0;

		if (pWnd->GetType() == UI_TabBox)
		{
			CTabWnd* pTabWnd = static_cast<CTabWnd*>(pWnd);
			Dest.DWord = pTabWnd->PageArray.GetCount();
		}
		return true;

	case WindowMembers::Tab:
		Dest.Type = pWindowType;
		Dest.Ptr = nullptr;

		if (pWnd->GetType() == UI_TabBox && Index[0])
		{
			CTabWnd* pTabWnd = static_cast<CTabWnd*>(pWnd);
			
			if (IsNumber(Index))
			{
				int tabIndex = GetIntFromString(Index, 0) - 1;
				if (tabIndex >= 0 && tabIndex < pTabWnd->PageArray.GetCount())
				{
					Dest.Ptr = pTabWnd->PageArray[tabIndex];
				}
			}
			else
			{
				for (int i = 0; i < pTabWnd->PageArray.GetCount(); ++i)
				{
					if (ci_equals(pTabWnd->PageArray[i]->TabText, Index))
					{
						Dest.Ptr = pTabWnd->PageArray[i];
						break;
					}
				}
			}
		}
		return true;

	case WindowMembers::CurrentTab:
		Dest.Type = pWindowType;
		Dest.Ptr = nullptr;

		if (pWnd->GetType() == UI_TabBox)
		{
			CTabWnd* pTabWnd = static_cast<CTabWnd*>(pWnd);

			int tabIndex = pTabWnd->CurTabIndex;
			if (tabIndex >= 0 && tabIndex < pTabWnd->PageArray.GetCount())
			{
				Dest.Ptr = pTabWnd->PageArray[tabIndex];
			}
		}
		return true;

	case WindowMembers::CurrentTabIndex:
		Dest.Type = pIntType;
		Dest.Int = 0;

		if (pWnd->GetType() == UI_TabBox)
		{
			CTabWnd* pTabWnd = static_cast<CTabWnd*>(pWnd);
			Dest.Int = pTabWnd->CurTabIndex + 1;
		}
		return true;

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

bool MQ2WindowType::FromData(MQVarPtr& VarPtr, const MQTypeVar& Source)
{
	if (Source.Type != pWindowType)
		return false;
	VarPtr.Ptr = Source.Ptr;
	return true;
}

bool MQ2WindowType::FromString(MQVarPtr& VarPtr, const char* Source)
{
	if (VarPtr.Ptr = FindMQ2WindowPath(Source))
		return true;

	return false;
}

bool MQ2WindowType::dataWindow(const char* szIndex, MQTypeVar& Ret)
{
	if (szIndex[0])
	{
		if (Ret.Ptr = FindMQ2Window(szIndex))
		{
			Ret.Type = pWindowType;
			return true;
		}
	}

	return false;
}

} // namespace mq::datatypes
