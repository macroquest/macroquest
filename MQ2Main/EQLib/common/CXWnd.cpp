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

CXWnd::VirtualFunctionTable* CXWnd::sm_vftable = nullptr;
CSidlScreenWnd::VirtualFunctionTable* CSidlScreenWnd::sm_vftable = nullptr;

#define FUNCTION_AT_VFTABLE_MEMBER(Function, Class, Member)           \
	__declspec(naked) Function                                        \
	{                                                                 \
		using VFT = Class::VirtualFunctionTable;                      \
		__asm mov eax, [Class::sm_vftable]                            \
		__asm mov eax, [eax]                                          \
		__asm jmp dword ptr [eax]VFT.Member                           \
	}

#define FUNCTION_AT_VFTABLE_MEMBER2(Function, Class, Base, Member)    \
	__declspec(naked) Function                                        \
	{                                                                 \
		using VFT = Base::VirtualFunctionTable;                       \
		__asm mov eax, [Class::sm_vftable]                            \
		__asm mov eax, [eax]                                          \
		__asm jmp dword ptr [eax]VFT.Member                           \
	}


//----------------------------------------------------------------------------

// need to define constructor in ASM file
#ifdef CXWnd__CXWnd_x
FUNCTION_AT_ADDRESS(CXWnd::CXWnd(CXWnd*, uint32_t, CXRect), CXWnd__CXWnd);
#endif
#ifdef CXWnd__dCXWndx
FUNCTION_AT_ADDRESS(CXWnd::~CXWnd(), CXWnd__dCXWnd);
#endif

//----------------------------------------------------------------------------
// virtuals

FUNCTION_AT_VFTABLE_MEMBER(int CXWnd::DrawNC() const, CXWnd, DrawNC);
FUNCTION_AT_VFTABLE_MEMBER(int CXWnd::DrawCursor(const CXPoint&, const CXRect&, bool&), CXWnd, DrawCursor);
FUNCTION_AT_VFTABLE_MEMBER(int CXWnd::DrawBackground() const, CXWnd, DrawBackground);
FUNCTION_AT_VFTABLE_MEMBER(int CXWnd::DrawTooltip(const CXWnd* wnd) const, CXWnd, DrawTooltip);
FUNCTION_AT_VFTABLE_MEMBER(int CXWnd::DrawTooltipAtPoint(const CXPoint& pos, const CXStr& tooltip) const, CXWnd, DrawTooltipAtPoint);

CXRect CXWnd::GetMinimizedRect() const
{
	return CXRect(GetScreenRect().TopLeft(), GetMinSize());
}

FUNCTION_AT_VFTABLE_MEMBER(int CXWnd::DrawTitleBar(const CXRect&) const, CXWnd, DrawTitleBar);
FUNCTION_AT_VFTABLE_MEMBER(HCURSOR CXWnd::GetCursorToDisplay() const, CXWnd, GetCursorToDisplay);

int CXWnd::HandleLButtonDown(const CXPoint& pos, uint32_t flags)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->HandleLButtonDown(pos, flags);
	}

	return 0;
}

int CXWnd::HandleLButtonUp(const CXPoint& pos, uint32_t flags)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->HandleLButtonUp(pos, flags);
	}

	return 0;
}

int CXWnd::HandleLButtonHeld(const CXPoint& pos, uint32_t flags)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->HandleLButtonHeld(pos, flags);
	}

	return 0;
}

int CXWnd::HandleLButtonUpAfterHeld(const CXPoint& pos, uint32_t flags)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->HandleLButtonUpAfterHeld(pos, flags);
	}

	return 0;
}

int CXWnd::HandleRButtonDown(const CXPoint& pos, uint32_t flags)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->HandleRButtonDown(pos, flags);
	}

	return 0;
}

int CXWnd::HandleRButtonUp(const CXPoint& pos, uint32_t flags)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->HandleRButtonUp(pos, flags);
	}

	return 0;
}

int CXWnd::HandleRButtonHeld(const CXPoint& pos, uint32_t flags)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->HandleRButtonHeld(pos, flags);
	}

	return 0;
}

int CXWnd::HandleRButtonUpAfterHeld(const CXPoint& pos, uint32_t flags)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->HandleRButtonUpAfterHeld(pos, flags);
	}

	return 0;
}

int CXWnd::HandleWheelButtonDown(const CXPoint& pos, uint32_t flags)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->HandleWheelButtonDown(pos, flags);
	}

	return 0;
}

int CXWnd::HandleWheelButtonUp(const CXPoint& pos, uint32_t flags)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->HandleWheelButtonUp(pos, flags);
	}

	return 0;
}

int CXWnd::HandleMouseMove(const CXPoint& pos, uint32_t flags)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->HandleMouseMove(pos, flags);
	}

	return 0;
}

FUNCTION_AT_VFTABLE_MEMBER(int CXWnd::HandleWheelMove(const CXPoint&, int, uint32_t), CXWnd, HandleWheelMove);

int CXWnd::HandleKeyboardMsg(uint32_t message, uint32_t flags, bool down)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->HandleKeyboardMsg(message, flags, down);
	}

	return -1;
}

int CXWnd::HandleMouseLeave()
{
	return 0;
}

int CXWnd::OnDragDrop(SDragDropInfo* dragDropInfo)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->OnDragDrop(dragDropInfo);
	}

	return 0;
}

HCURSOR CXWnd::GetDragDropCursor(SDragDropInfo* info) const
{
	return GetCursorToDisplay();
}

bool CXWnd::QueryDropOK(SDragDropInfo* dragDropInfo) const
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->QueryDropOK(dragDropInfo);
	}

	return false;
}

int CXWnd::OnClickStick(CClickStickInfo* info, uint32_t flags, bool unk)
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->OnClickStick(info, flags, unk);
	}

	return 0;
}

HCURSOR CXWnd::GetClickStickCursor(CClickStickInfo* info) const
{
	return GetCursorToDisplay();
}

bool CXWnd::QueryClickStickDropOK(CClickStickInfo* info) const
{
	CXWnd* parent = GetParent();

	if (parent)
	{
		return parent->QueryClickStickDropOK(info);
	}

	return false;
}

int CXWnd::WndNotification(CXWnd* sender, uint32_t message, void* data)
{
	OnWndNotification();

	return SendNotificationToParent(sender, message, data);
}

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

int CXWnd::OnShow()
{
	if (IsActive())
	{
		OnBeginMoveOrResize();
		OnCompleteMoveOrResize();
	}

	return 0;
}

int CXWnd::OnMove(const CXRect& rect)
{
	SetClientRectDirty(true);
	return 0;
}

int CXWnd::OnResize(int w, int h)
{
	SetClientRectDirty(true);
	return 0;
}

int CXWnd::OnBeginMoveOrResize()
{
	for (CXWnd* pWnd = GetFirstNode(); pWnd != nullptr; pWnd = pWnd->GetNext())
	{
		pWnd->OnBeginMoveOrResize();
	}

	return 0;
}

int CXWnd::OnCompleteMoveOrResize()
{
	for (CXWnd* pWnd = GetFirstNode(); pWnd != nullptr; pWnd = pWnd->GetNext())
	{
		pWnd->OnCompleteMoveOrResize();
	}

	UpdateLayout(true);
	return 0;
}

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

int CXWnd::OnMaximizeBox()
{
	return Maximize(!IsMaximized());
}

FUNCTION_AT_VFTABLE_MEMBER(int CXWnd::OnTileBox(), CXWnd, OnTileBox);

int CXWnd::OnSetFocus(CXWnd* old)
{
	return SendNotificationToParent(this, XWM_FOCUS, nullptr);
}

int CXWnd::OnKillFocus(CXWnd* old)
{
	return SendNotificationToParent(this, XWM_LOSTFOCUS, nullptr);
}

FUNCTION_AT_VFTABLE_MEMBER(int CXWnd::OnProcessFrame(), CXWnd, OnProcessFrame);

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

FUNCTION_AT_VFTABLE_MEMBER(int CXWnd::Show(bool, bool, bool), CXWnd, Show);

bool CXWnd::AboutToShow()
{
	if (pController)
	{
		return pController->AboutToShow();
	}

	return true;
}

bool CXWnd::AboutToHide()
{
	if (pController)
	{
		return pController->AboutToHide();
	}

	return true;
}

FUNCTION_AT_VFTABLE_MEMBER(void CXWnd::Unknown0x0EC(), CXWnd, Unknown0x0ec);
FUNCTION_AT_VFTABLE_MEMBER(int CXWnd::HitTest(const CXPoint&, int*) const, CXWnd, HitTest);
FUNCTION_AT_VFTABLE_MEMBER(CXRect CXWnd::GetHitTestRect(int) const, CXWnd, GetHitTestRect);
FUNCTION_AT_VFTABLE_MEMBER(CXRect CXWnd::GetInnerRect() const, CXWnd, GetInnerRect);

CXRect CXWnd::GetClientRect() const
{
	if (IsClientRectDirty())
	{
		ClientRect = GetHitTestRect(2); // 2 == client rect?
		bClientRectChanged = false;
	}

	return ClientRect;
}

FUNCTION_AT_VFTABLE_MEMBER(CXRect CXWnd::GetClientClipRect() const, CXWnd, GetClientClipRect);
FUNCTION_AT_VFTABLE_MEMBER(CXSize CXWnd::GetMinSize(bool) const, CXWnd, GetMinSize);
FUNCTION_AT_VFTABLE_MEMBER(CXSize CXWnd::GetMaxSize(bool) const, CXWnd, GetMaxSize);
FUNCTION_AT_VFTABLE_MEMBER(int CXWnd::Move(const CXRect&, bool, bool, bool, bool), CXWnd, Move_Rect);
FUNCTION_AT_VFTABLE_MEMBER(int CXWnd::Move(const CXPoint&), CXWnd, Move_Point);
FUNCTION_AT_VFTABLE_MEMBER(CXWnd* CXWnd::GetChildWndAt(const CXPoint&, bool, bool) const, CXWnd, GetChildWndAt);

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

int CXWnd::SetVScrollPos(int pos)
{
	int oldPos = VScrollPos;

	VScrollPos = std::min(VScrollMax, std::max(0, pos));
	SetClientRectDirty(true);

	return oldPos;
}

int CXWnd::SetHScrollPos(int pos)
{
	int oldPos = HScrollPos;

	HScrollPos = std::min(HScrollMax, std::max(0, pos));
	SetClientRectDirty(true);

	return oldPos;
}

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

FUNCTION_AT_VFTABLE_MEMBER(void CXWnd::SetAttributesFromSidl(CParamScreenPiece*), CXWnd, SetAttributesFromSidl);

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

//============================================================================
//============================================================================

// CSidlScreenWnd

FUNCTION_AT_VFTABLE_MEMBER2(int CSidlScreenWnd::OnResize(int, int), CSidlScreenWnd, CXWnd, OnResize);
FUNCTION_AT_VFTABLE_MEMBER2(int CSidlScreenWnd::DrawBackground() const, CSidlScreenWnd, CXWnd, DrawBackground);
FUNCTION_AT_VFTABLE_MEMBER2(int CSidlScreenWnd::WndNotification(CXWnd*, uint32_t, void*), CSidlScreenWnd, CXWnd, WndNotification);
FUNCTION_AT_VFTABLE_MEMBER2(int CSidlScreenWnd::HandleRButtonDown(const CXPoint&, uint32_t), CSidlScreenWnd, CXWnd, HandleRButtonDown);
FUNCTION_AT_VFTABLE_MEMBER2(int CSidlScreenWnd::OnShow(), CSidlScreenWnd, CXWnd, OnShow);
FUNCTION_AT_VFTABLE_MEMBER2(CScreenPieceTemplate* CSidlScreenWnd::GetSidlPiece(const CXStr&, bool) const, CSidlScreenWnd, CXWnd, GetSidlPiece);
FUNCTION_AT_VFTABLE_MEMBER2(const CXStr* CSidlScreenWnd::GetWindowName() const, CSidlScreenWnd, CXWnd, GetWindowName);
FUNCTION_AT_VFTABLE_MEMBER2(bool CSidlScreenWnd::HasActivatedFirstTimeAlert() const, CSidlScreenWnd, CXWnd, HasActivatedFirstTimeAlert);
FUNCTION_AT_VFTABLE_MEMBER2(void CSidlScreenWnd::SetHasActivatedFirstTimeAlert(bool), CSidlScreenWnd, CXWnd, SetHasActivatedFirstTimeAlert);

FUNCTION_AT_VFTABLE_MEMBER(void CSidlScreenWnd::LoadIniInfo(), CSidlScreenWnd, LoadIniInfo);
FUNCTION_AT_VFTABLE_MEMBER(void CSidlScreenWnd::StoreIniInfo(), CSidlScreenWnd, StoreIniInfo);



#ifdef CSidlScreenWnd__dCSidlScreenWnd_x
FUNCTION_AT_ADDRESS(CSidlScreenWnd::~CSidlScreenWnd(), CSidlScreenWnd__dCSidlScreenWnd);
#endif
#ifdef CSidlScreenWnd__CSidlScreenWnd_x
CONSTRUCTOR_AT_ADDRESS(CSidlScreenWnd::CSidlScreenWnd(CXWnd*, uint32_t, const CXRect&, const CXStr&), CSidlScreenWnd__CSidlScreenWnd);
#endif
#ifdef CSidlScreenWnd__CSidlScreenWnd1_x
CONSTRUCTOR_AT_ADDRESS(CSidlScreenWnd::CSidlScreenWnd(CXWnd* pParent, const CXStr& Screen, int, int, char*), CSidlScreenWnd__CSidlScreenWnd1);
#endif
#ifdef CSidlScreenWnd__CSidlScreenWnd2_x
CONSTRUCTOR_AT_ADDRESS(CSidlScreenWnd::CSidlScreenWnd(CXWnd* pParent, const CXStr& Screen), CSidlScreenWnd__CSidlScreenWnd2);
#endif
#ifdef CSidlScreenWnd__Init_x
FUNCTION_AT_ADDRESS(void CSidlScreenWnd::Init(CXWnd*, uint32_t, const CXRect&, const CXStr&, int, char*), CSidlScreenWnd__Init);
#endif
#ifdef CSidlScreenWnd__Init1_x
FUNCTION_AT_ADDRESS(void CSidlScreenWnd::Init(int, const CXStr&, int, int, int), CSidlScreenWnd__Init1);
#endif
#ifdef CSidlScreenWnd__SetScreen_x
FUNCTION_AT_ADDRESS(void CSidlScreenWnd::SetScreen(CXStr*), CSidlScreenWnd__SetScreen);
#endif
#ifdef CSidlScreenWnd__LoadSidlScreen_x
FUNCTION_AT_ADDRESS(void CSidlScreenWnd::LoadSidlScreen(), CSidlScreenWnd__LoadSidlScreen);
#endif
#ifdef CSidlScreenWnd__CalculateVSBRange_x
FUNCTION_AT_ADDRESS(void CSidlScreenWnd::CalculateVSBRange(), CSidlScreenWnd__CalculateVSBRange);
#endif
#ifdef CSidlScreenWnd__CalculateHSBRange_x
FUNCTION_AT_ADDRESS(void CSidlScreenWnd::CalculateHSBRange(), CSidlScreenWnd__CalculateHSBRange);
#endif
#ifdef CSidlScreenWnd__DrawSidlPiece_x
FUNCTION_AT_ADDRESS(int CSidlScreenWnd::DrawSidlPiece(CScreenPieceTemplate*, const CXRect&, const CXRect&) const, CSidlScreenWnd__DrawSidlPiece);
#endif
#ifdef CSidlScreenWnd__GetSidlPieceRect_x
FUNCTION_AT_ADDRESS(CXRect CSidlScreenWnd::GetSidlPieceRect(CScreenPieceTemplate*, const CXRect&) const, CSidlScreenWnd__GetSidlPieceRect);
#endif
#ifdef CSidlScreenWnd__AddButtonToRadioGroup_x
FUNCTION_AT_ADDRESS(void CSidlScreenWnd::AddButtonToRadioGroup(CXStr, CButtonWnd*), CSidlScreenWnd__AddButtonToRadioGroup);
#endif
#ifdef CSidlScreenWnd__CreateChildrenFromSidl_x
FUNCTION_AT_ADDRESS(void CSidlScreenWnd::CreateChildrenFromSidl(DWORD), CSidlScreenWnd__CreateChildrenFromSidl);
#endif
#ifdef CSidlScreenWnd__StoreIniVis_x
FUNCTION_AT_ADDRESS(void CSidlScreenWnd::StoreIniVis(), CSidlScreenWnd__StoreIniVis);
#endif
#ifdef CSidlScreenWnd__EnableIniStorage_x
FUNCTION_AT_ADDRESS(void CSidlScreenWnd::EnableIniStorage(int, char*), CSidlScreenWnd__EnableIniStorage);
#endif
#ifdef CSidlScreenWnd__ConvertToRes_x
FUNCTION_AT_ADDRESS(int CSidlScreenWnd::ConvertToRes(int, int, int, int), CSidlScreenWnd__ConvertToRes);
#endif
#ifdef CSidlScreenWnd__GetChildItem_x
FUNCTION_AT_ADDRESS(CXWnd* CSidlScreenWnd::GetChildItem(const CXStr&, bool bDebug), CSidlScreenWnd__GetChildItem);
#endif
#ifdef CSidlScreenWnd__LoadIniListWnd_x
FUNCTION_AT_ADDRESS(void CSidlScreenWnd::LoadIniListWnd(CListWnd*, char*), CSidlScreenWnd__LoadIniListWnd);
#endif
#ifdef CSidlScreenWnd__StoreIniListWnd_x
FUNCTION_AT_ADDRESS(void CSidlScreenWnd::StoreIniListWnd(CListWnd const*, char*), CSidlScreenWnd__StoreIniListWnd);
#endif



} // namespace eqlib
