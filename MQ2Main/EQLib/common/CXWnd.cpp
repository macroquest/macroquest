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

#include "CXWnd.h"
#include "EQClasses.h"
#include "Globals.h"

// shouldn't be have code dependencies outside eqlib...
//#include "../../MQ2Main.h"

namespace eqlib {

// NOTE that using FUNCTION_AT_VIRTUAL_ADDRESS has a high risk of creating infinite
// recursive calls if trying to call base class. If we want to do it this way, we instead
// need to read from static vftable, not the instance in the current class.

//----------------------------------------------------------------------------

// need to define constructor in ASM file
#ifdef CXWnd__CXWnd_x
FUNCTION_AT_ADDRESS(CXWnd::CXWnd(CXWnd*, uint32_t, CXRect), CXWnd__CXWnd);
#endif

//----------------------------------------------------------------------------
// virtuals

// 0x00
bool CXWnd::IsValid() const
{
	return ValidCXWnd;
}

// probably need actual address for this.
FUNCTION_AT_VIRTUAL_ADDRESS(CXWnd::~CXWnd(), 0x04);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::DrawNC() const, 0x08);

// 0x0c
int CXWnd::Draw()
{
	return 0;
}

// 0x10
int CXWnd::PostDraw()
{
	return 0;
}

FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::DrawCursor(const CXPoint&, const CXRect&, bool&), 0x14);

// 0x18
int CXWnd::DrawChildItem(const CXWnd* child, void* item) const
{
	return 0;
}

// 0x1c
int CXWnd::DrawCaret() const
{
	return 0;
}

FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::DrawBackground() const, 0x20);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::DrawTooltip(const CXWnd* wnd) const, 0x24);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::DrawTooltipAtPoint(const CXPoint& pos, const CXStr& tooltip) const, 0x28);

// 0x2c
CXRect CXWnd::GetMinimizedRect() const
{
	return CXRect(GetScreenRect().TopLeft(), GetMinSize());
}

FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::DrawTitleBar(const CXRect&) const, 0x30);
FUNCTION_AT_VIRTUAL_ADDRESS(HCURSOR CXWnd::GetCursorToDisplay() const, 0x34);

// 0x38
int CXWnd::HandleLButtonDown(const CXPoint& pos, uint32_t flags)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->HandleLButtonDown(pos, flags);
	}

	return 0;
}

// 0x3c
int CXWnd::HandleLButtonUp(const CXPoint& pos, uint32_t flags)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->HandleLButtonUp(pos, flags);
	}

	return 0;
}

// 0x40
int CXWnd::HandleLButtonHeld(const CXPoint& pos, uint32_t flags)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->HandleLButtonHeld(pos, flags);
	}

	return 0;
}

// 0x44
int CXWnd::HandleLButtonUpAfterHeld(const CXPoint& pos, uint32_t flags)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->HandleLButtonUpAfterHeld(pos, flags);
	}

	return 0;
}

// 0x48
int CXWnd::HandleRButtonDown(const CXPoint& pos, uint32_t flags)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->HandleRButtonDown(pos, flags);
	}

	return 0;
}

// 0x4c
int CXWnd::HandleRButtonUp(const CXPoint& pos, uint32_t flags)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->HandleRButtonUp(pos, flags);
	}

	return 0;
}

// 0x50
int CXWnd::HandleRButtonHeld(const CXPoint& pos, uint32_t flags)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->HandleRButtonHeld(pos, flags);
	}

	return 0;
}

// 0x54
int CXWnd::HandleRButtonUpAfterHeld(const CXPoint& pos, uint32_t flags)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->HandleRButtonUpAfterHeld(pos, flags);
	}

	return 0;
}

// 0x58
int CXWnd::HandleWheelButtonDown(const CXPoint& pos, uint32_t flags)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->HandleWheelButtonDown(pos, flags);
	}

	return 0;
}

// 0x5c
int CXWnd::HandleWheelButtonUp(const CXPoint& pos, uint32_t flags)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->HandleWheelButtonUp(pos, flags);
	}

	return 0;
}

// 0x60
int CXWnd::HandleMouseMove(const CXPoint& pos, uint32_t flags)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->HandleMouseMove(pos, flags);
	}

	return 0;
}

FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleWheelMove(const CXPoint&, int, uint32_t), 0x64);

// 0x68
int CXWnd::HandleKeyboardMsg(uint32_t message, uint32_t flags, bool down)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->HandleKeyboardMsg(message, flags, down);
	}

	return -1;
}

// 0x6c
int CXWnd::HandleMouseLeave()
{
	return 0;
}

// 0x70
int CXWnd::OnDragDrop(SDragDropInfo* dragDropInfo)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->OnDragDrop(dragDropInfo);
	}

	return 0;
}

// 0x74
HCURSOR CXWnd::GetDragDropCursor(SDragDropInfo* info) const
{
	return GetCursorToDisplay();
}

// 0x78
bool CXWnd::QueryDropOK(SDragDropInfo* dragDropInfo) const
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->QueryDropOK(dragDropInfo);
	}

	return false;
}

// 0x7c
int CXWnd::OnClickStick(CClickStickInfo* info, uint32_t flags, bool unk)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->OnClickStick(info, flags, unk);
	}

	return 0;
}

// 0x80
HCURSOR CXWnd::GetClickStickCursor(CClickStickInfo* info) const
{
	return GetCursorToDisplay();
}

// 0x84
bool CXWnd::QueryClickStickDropOK(CClickStickInfo* info) const
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->QueryClickStickDropOK(info);
	}

	return false;
}

// 0x88
int CXWnd::WndNotification(CXWnd* sender, uint32_t message, void* data)
{
	OnWndNotification();

	return SendNotificationToParent(sender, message, data);
}

// 0x8c
void CXWnd::OnWndNotification()
{
}

int CXWnd::SendNotificationToParent(CXWnd* sender, uint32_t message, void* data)
{
	if (pController)
	{
		pController->WndNotification(sender, message, data);
	}

	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->WndNotification(sender, message, data);
	}

	return 0;
}

// 0x90
void CXWnd::Activate()
{
	Show(true);
}

// 0x94
void CXWnd::Deactivate()
{
	Show(false);
}

// 0x98
int CXWnd::OnShow()
{
	if (IsActive())
	{
		OnBeginMoveOrResize();
		OnCompleteMoveOrResize();
	}

	return 0;
}

// 0x9c
int CXWnd::OnMove(const CXRect& rect)
{
	SetClientRectDirty(true);
	return 0;
}

// 0xa0
int CXWnd::OnResize(int w, int h)
{
	SetClientRectDirty(true);
	return 0;
}

// 0xa4
int CXWnd::OnBeginMoveOrResize()
{
	for (CXWnd* pWnd = GetFirstNode(); pWnd != nullptr; pWnd = pWnd->GetNext())
	{
		pWnd->OnBeginMoveOrResize();
	}

	return 0;
}

// 0xa8
int CXWnd::OnCompleteMoveOrResize()
{
	for (CXWnd* pWnd = GetFirstNode(); pWnd != nullptr; pWnd = pWnd->GetNext())
	{
		pWnd->OnCompleteMoveOrResize();
	}

	UpdateLayout(true);
	return 0;
}

// 0xac
int CXWnd::OnMinimizeBox()
{
	bool minimized = IsMinimized();

	if (!minimized)
	{
		for (CXWnd* pWnd = GetFirstNode(); pWnd != nullptr; pWnd = pWnd->GetNext())
		{
			pWnd->SetMouseOver(false);
		}
	}

	return Minimize(!minimized);
}

// 0xb0
int CXWnd::OnMaximizeBox()
{
	return Maximize(!IsMaximized());
}

// 0xb4
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::OnTileBox(), 0xb4);

// 0xb8
int CXWnd::OnTile()
{
	return 0;
}

// 0xbc
int CXWnd::OnSetFocus(CXWnd* old)
{
	return SendNotificationToParent(this, XWM_FOCUS, nullptr);
}

// 0xc0
int CXWnd::OnKillFocus(CXWnd* old)
{
	return SendNotificationToParent(this, XWM_LOSTFOCUS, nullptr);
}

// 0xc4
// This function does a lot of the fade handling. It could be implemented here,
// probably, but it does a lot of work. Might return to it later.
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::OnProcessFrame(), 0xc4);

// 0xc8
int CXWnd::OnVScroll(EScrollCode code, int pos)
{
	int height = GetClientRect().GetHeight();

	switch (code)
	{
	case 0:
	case 1:
		// up
		VScrollPos = std::max(0, VScrollPos - 2);
		break;

	case 2:
	case 3:
		// down
		VScrollPos = std::min(VScrollMax, VScrollPos + 2);
		break;

	case 4:
		// abs position
		VScrollPos = std::min(VScrollMax, std::max(0, pos));
		break;

	case 5:
		// page up
		VScrollPos = std::max(0, VScrollPos - height);
		break;

	case 6:
		// page down
		VScrollPos = std::min(VScrollMax, VScrollPos + height);
		break;

	default: break;
	}

	SetClientRectDirty(true);
	return 0;
}

// 0xcc
int CXWnd::OnHScroll(EScrollCode code, int pos)
{
	int width = GetClientRect().GetWidth();

	switch (code)
	{
	case 0:
	case 1:
		// left
		HScrollPos = std::max(0, HScrollPos - 2);
		break;

	case 2:
	case 3:
		// right
		HScrollPos = std::min(HScrollMax, HScrollPos + 2);
		break;

	case 4:
		// absolute
		HScrollPos = std::min(HScrollMax, std::max(0, pos));
		break;

	case 5:
		// page left
		HScrollPos = std::max(0, HScrollPos - width);
		break;

	case 6:
		// page right
		HScrollPos = std::min(HScrollMax, HScrollPos + width);
		break;

	default: break;
	}

	SetClientRectDirty(true);
	return 0;
}

// 0xd0
// int CXWnd::OnBroughtToTop

// 0xd4
// int CXWnd::OnActivate

FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::Show(bool, bool, bool), 0xd8);

// 0xdc
bool CXWnd::AboutToShow()
{
	if (pController)
	{
		return pController->AboutToShow();
	}

	return true;
}

// 0xe0
bool CXWnd::AboutToHide()
{
	if (pController)
	{
		return pController->AboutToHide();
	}

	return true;
}

// 0xe4
int CXWnd::RequestDockInfo(EDockAction action, CXWnd* wnd, CXRect* rect)
{
	return 0;
}

// 0xe8
// CXStr CXWnd::GetTooltip

FUNCTION_AT_VIRTUAL_ADDRESS(void CXWnd::Unknown0x0EC(), 0xec);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HitTest(const CXPoint&, int*) const, 0xf0);
FUNCTION_AT_VIRTUAL_ADDRESS(CXRect CXWnd::GetHitTestRect(int) const, 0xf4);
FUNCTION_AT_VIRTUAL_ADDRESS(CXRect CXWnd::GetInnerRect() const, 0xf8);

// 0xfc
CXRect CXWnd::GetClientRect() const
{
	if (IsClientRectDirty())
	{
		ClientRect = GetHitTestRect(2); // 2 == client rect?
		bClientRectChanged = false;
	}

	return ClientRect;
}

// could probably do this one too if I had the time
FUNCTION_AT_VIRTUAL_ADDRESS(CXRect CXWnd::GetClientClipRect() const, 0x100);

// These are almost doable but they call into a function to calculate the size of
// some kind of border if the bool is true
FUNCTION_AT_VIRTUAL_ADDRESS(CXSize CXWnd::GetMinSize(bool) const, 0x104);
FUNCTION_AT_VIRTUAL_ADDRESS(CXSize CXWnd::GetMaxSize(bool) const, 0x108);

// 0x10c
// CXSize CXWnd::GetUntileSize() const

// 0x110
// bool CXWnd::IsPointTransparent(const CXPoint& point) const

// 0x114
// bool CXWnd::Unknown0x114() const

// 0x118
// bool CXWnd::ControllerShouldProcessFrame() const

// 0x11c
// void CXWnd::SetDrawTemplate(CXWndDrawTemplate*)

// 0x120
FUNCTION_AT_ADDRESS(int CXWnd::Move(const CXRect&, bool, bool, bool, bool), CXWnd__Move1);

// 0x124
FUNCTION_AT_ADDRESS(int CXWnd::Move(const CXPoint&), CXWnd__Move);

// 0x128
// void CXWnd::SetWindowText(const CXStr&)

// 0x12c
FUNCTION_AT_ADDRESS(CXWnd* CXWnd::GetChildWndAt(const CXPoint&, bool, bool) const, CXWnd__GetChildWndAt);

// 0x130
CScreenPieceTemplate* CXWnd::GetSidlPiece(const CXStr& screenId, bool top) const
{
	for (const CXWnd* wnd = GetFirstNode(); wnd != nullptr; wnd = wnd->GetNext())
	{
		CScreenPieceTemplate* piece = wnd->GetSidlPiece(screenId, false);
		if (piece)
		{
			return piece;
		}
	}

	return nullptr;
}

// 0x134
// const CXStr* CXWnd::GetWindowName() const

// 0x138
int CXWnd::SetVScrollPos(int pos)
{
	int oldPos = VScrollPos;

	VScrollPos = std::min(VScrollMax, std::max(0, pos));
	SetClientRectDirty(true);

	return oldPos;
}

// 0x13c
int CXWnd::SetHScrollPos(int pos)
{
	int oldPos = HScrollPos;

	HScrollPos = std::min(HScrollMax, std::max(0, pos));
	SetClientRectDirty(true);

	return oldPos;
}

// 0x140
int CXWnd::AutoSetVScrollPos(CXRect rect)
{
	int oldPos = VScrollPos;
	int clientHeight = GetClientRect().GetHeight();

	if (VScrollPos > rect.top)
	{
		return SetVScrollPos(rect.top);
	}

	if (VScrollPos + clientHeight < rect.bottom)
	{
		return SetVScrollPos(rect.bottom - clientHeight);
	}

	return oldPos;
}

// 0x144
int CXWnd::AutoSetHScrollPos(CXRect rect)
{
	int oldPos = HScrollPos;
	int clientWidth = GetClientRect().GetWidth();

	if (HScrollPos > rect.left)
	{
		return SetHScrollPos(rect.left);
	}

	if (HScrollPos + clientWidth < rect.right)
	{
		return SetHScrollPos(rect.right - clientWidth);
	}

	return oldPos;
}

// 0x148
FUNCTION_AT_VIRTUAL_ADDRESS(void CXWnd::SetAttributesFromSidl(CParamScreenPiece*), 0x148);

// 0x150
// bool CXWnd::Unknown0x150()

// 0x154
// void CXWnd::Unknown0x154(bool)

// 0x158
// const CXSize& CXWnd::GetMinClientSize() const

// 0x15c
// const CXSize& CXWnd::GetMaxClientSize() const

// 0x160
// void* CXWnd::Unknown0x160

void CXWnd::UpdateLayout(bool finish)
{
	SetClientRectDirty(true);

	if (pLayoutStrategy && finish)
	{
		pLayoutStrategy->LayoutChildren(this);
	}
	else
	{
		for (CXWnd* wnd = GetFirstNode(); wnd != nullptr; wnd = wnd->GetNext())
		{
			wnd->UpdateLayout(finish);
		}
	}
}

void CXWnd::SetClientRectDirty(bool dirty)
{
	bClientRectChanged = dirty;
	if (bClientRectChanged)
	{
		bClientClipRectChanged = true;
		bScreenClipRectChanged = true;

		for (CXWnd* wnd = GetFirstNode(); wnd != nullptr; wnd = wnd->GetNext())
		{
			wnd->SetClientRectDirty(true);
		}
	}
}

//----------------------------------------------------------------------------

// TEMP
EQLIB_VAR CSidlManager** ppSidlMgr;
#define pSidlMgr (*ppSidlMgr)

UIType CXWnd::GetType() const
{
	if (CXMLData* pXmlData = GetXMLData())
		return pXmlData->Type;

	return UI_Unknown;
}

CXMLData* CXWnd::GetXMLData() const
{
	if (int xmlIndex = GetXMLIndex())
	{
		CXMLDataManager* mgr = (CXMLDataManager*) & ((PCSIDLMGR)pSidlMgr)->pXMLDataMgr;
		return mgr->GetXMLData(xmlIndex >> 16, xmlIndex & 0xffff);
	}

	return nullptr;
}

static CXWnd* RecurseAndFindName(CXWnd* pWnd, CXStr Name)
{
	if (!pWnd)
	{
		return nullptr;
	}

	if (CXMLData* pXMLData = pWnd->GetXMLData())
	{
		if (pXMLData->Name == Name)
		{
			return pWnd;
		}

		if (pXMLData->ScreenID == Name)
		{
			return pWnd;
		}
	}

	if (CXWnd* pChildWnd = pWnd->GetFirstNode())
	{
		if (CXWnd* tmp = RecurseAndFindName(pChildWnd, Name))
		{
			return tmp;
		}
	}

	if (CXWnd* pSiblingWnd = pWnd->GetNext())
	{
		return RecurseAndFindName(pSiblingWnd, Name);
	}

	return nullptr;
}

CXWnd* CXWnd::GetChildItem(CXStr Name)
{
	return RecurseAndFindName(this, Name);
}

#ifdef CXWnd__IsType_x
FUNCTION_AT_ADDRESS(bool CXWnd::IsType(enum EWndRuntimeType) const, CXWnd__IsType);
#endif
#ifdef CXWnd__SetFocus_x
FUNCTION_AT_ADDRESS(CXWnd* CXWnd::SetFocus(), CXWnd__SetFocus);
#endif
#ifdef CXWnd__ClrFocus_x
FUNCTION_AT_ADDRESS(void CXWnd::ClrFocus(), CXWnd__ClrFocus);
#endif
#ifdef CXWnd__Destroy_x
FUNCTION_AT_ADDRESS(int CXWnd::Destroy(), CXWnd__Destroy);
#endif
#ifdef CXWnd__Refade_x
FUNCTION_AT_ADDRESS(void CXWnd::Refade(), CXWnd__Refade);
#endif
#ifdef CXWnd__ProcessTransition_x
FUNCTION_AT_ADDRESS(int CXWnd::ProcessTransition(), CXWnd__ProcessTransition);
#endif
#ifdef CXWnd__BringToTop_x
FUNCTION_AT_ADDRESS(void CXWnd::BringToTop(bool), CXWnd__BringToTop);
#endif
#ifdef CXWnd__StartFade_x
FUNCTION_AT_ADDRESS(void CXWnd::StartFade(unsigned char, uint32_t), CXWnd__StartFade);
#endif
#ifdef CXWnd__Minimize_x
FUNCTION_AT_ADDRESS(int CXWnd::Minimize(bool), CXWnd__Minimize);
#endif
#ifdef CXWnd__IsReallyVisible_x
FUNCTION_AT_ADDRESS(bool CXWnd::IsReallyVisible() const, CXWnd__IsReallyVisible);
#endif
#ifdef CXWnd__DoAllDrawing_x
FUNCTION_AT_ADDRESS(int CXWnd::DoAllDrawing() const, CXWnd__DoAllDrawing);
#endif
#ifdef CXWnd__DrawChildren_x
FUNCTION_AT_ADDRESS(int CXWnd::DrawChildren() const, CXWnd__DrawChildren);
#endif
#ifdef CXWnd__Center_x
FUNCTION_AT_ADDRESS(void CXWnd::Center(), CXWnd__Center);
#endif
#ifdef CXWnd__Right_x
FUNCTION_AT_ADDRESS(void CXWnd::Right(), CXWnd__Right);
#endif
#ifdef CXWnd__GetScreenClipRect_x
FUNCTION_AT_ADDRESS(CXRect CXWnd::GetScreenClipRect() const, CXWnd__GetScreenClipRect);
#endif
#ifdef CXWnd__IsDescendantOf_x
FUNCTION_AT_ADDRESS(bool CXWnd::IsDescendantOf(CXWnd const*) const, CXWnd__IsDescendantOf);
#endif
#ifdef CXWnd__GetBorderFrame_x
FUNCTION_AT_ADDRESS(CTAFrameDraw const* CXWnd::GetBorderFrame() const, CXWnd__GetBorderFrame);
#endif
#ifdef CXWnd__GetScreenRect_x
FUNCTION_AT_ADDRESS(CXRect CXWnd::GetScreenRect() const, CXWnd__GetScreenRect);
#endif
#ifdef CXWnd__Resize_x
FUNCTION_AT_ADDRESS(int CXWnd::Resize(int, int, bool, bool, bool), CXWnd__Resize);
#endif
#ifdef CXWnd__GetChildItem_x
FUNCTION_AT_ADDRESS(CXWnd* CXWnd::GetChildItem(const CXStr&), CXWnd__GetChildItem);
#endif
#ifdef CXWnd__SetParent_x
FUNCTION_AT_ADDRESS(CXWnd* CXWnd::SetParent(CXWnd*), CXWnd__SetParent);
#endif
#ifdef CXWnd__SetMouseOver_x
FUNCTION_AT_ADDRESS(void CXWnd::SetMouseOver(bool), CXWnd__SetMouseOver);
#endif
#ifdef CXWnd__SetKeyTooltip_x
FUNCTION_AT_ADDRESS(void CXWnd::SetKeyTooltip(int, int), CXWnd__SetKeyTooltip);
#endif
#ifdef CXWnd__SetFont_x
FUNCTION_AT_ADDRESS(int CXWnd::SetFont(void*), CXWnd__SetFont);
#endif

} // namespace eqlib
