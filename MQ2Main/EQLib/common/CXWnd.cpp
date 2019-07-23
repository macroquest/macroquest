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

// shouldn't be have code dependencies outside eqlib...
#include "../../MQ2Main.h"

namespace eqlib {

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
		CXMLDataManager* mgr = (CXMLDataManager*)&((PCSIDLMGR)pSidlMgr)->pXMLDataMgr;
		return mgr->GetXMLData(xmlIndex >> 16, xmlIndex & 0xffff);
	}

	return 0;
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

	if (CXWnd* pChildWnd = pWnd->GetFirstChildWnd())
	{
		if (CXWnd* tmp = RecurseAndFindName(pChildWnd, Name))
		{
			return tmp;
		}
	}

	if (CXWnd* pSiblingWnd = pWnd->GetNextSiblingWnd())
	{
		return RecurseAndFindName(pSiblingWnd, Name);
	}

	return nullptr;
}

CXWnd* CXWnd::GetChildItem(CXStr Name)
{
	RecurseAndFindName(this, Name);
}

FUNCTION_AT_VIRTUAL_ADDRESS(bool CXWnd::IsValid() const, 0);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleLButtonDown(const CXPoint&, uint32_t), 0x38);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleLButtonUp(const CXPoint&, uint32_t), 0x3c);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleLButtonHeld(const CXPoint&, uint32_t), 0x40);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleLButtonUpAfterHeld(const CXPoint&, uint32_t), 0x44);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleRButtonDown(const CXPoint&, uint32_t), 0x48);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleRButtonUp(const CXPoint&, uint32_t), 0x4c);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleRButtonHeld(const CXPoint&, uint32_t), 0x50);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::HandleRButtonUpAfterHeld(const CXPoint&, uint32_t), 0x54);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::WndNotification(CXWnd*, uint32_t, void*), 0x88);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::OnResize(int, int), 0x0a0);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::OnMinimizeBox(), 0xac);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::Show(bool, bool, bool), 0x0d8);
FUNCTION_AT_VIRTUAL_ADDRESS(CXRect CXWnd::GetClientRect() const, 0xfc);
FUNCTION_AT_VIRTUAL_ADDRESS(void CXWnd::SetWindowText(const CXStr&), 0x128);
FUNCTION_AT_VIRTUAL_ADDRESS(int CXWnd::SetVScrollPos(int), 0x138);       // don't ever doubt this one, double check CXWnd__CXWnd vftable and count

#ifdef CXWnd__GetWindowTextA_x
FUNCTION_AT_ADDRESS(CXStr CXWnd::GetWindowText() const, CXWnd__GetWindowTextA);
#endif
#ifdef CXWnd__SetTooltip_x
FUNCTION_AT_ADDRESS(void CXWnd::SetTooltip(const CXStr&), CXWnd__SetTooltip);
#endif
#ifdef CXWnd__CXWnd_x
FUNCTION_AT_ADDRESS(CXWnd::CXWnd(CXWnd*, uint32_t, CXRect), CXWnd__CXWnd);
#endif
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
#ifdef CXWnd__HasFocus_x
FUNCTION_AT_ADDRESS(bool CXWnd::HasFocus() const, CXWnd__HasFocus);
#endif
#ifdef CXWnd__Show_x
FUNCTION_AT_ADDRESS(int CXWnd::Show(bool, bool), CXWnd__Show);
#endif
#ifdef CXWnd__DrawCloseBox_x
FUNCTION_AT_ADDRESS(int CXWnd::DrawCloseBox() const, CXWnd__DrawCloseBox);
#endif
#ifdef CXWnd__DrawMinimizeBox_x
FUNCTION_AT_ADDRESS(int CXWnd::DrawMinimizeBox() const, CXWnd__DrawMinimizeBox);
#endif
#ifdef CXWnd__DrawTileBox_x
FUNCTION_AT_ADDRESS(int CXWnd::DrawTileBox() const, CXWnd__DrawTileBox);
#endif
#ifdef CXWnd__DrawVScrollbar_x
FUNCTION_AT_ADDRESS(int CXWnd::DrawVScrollbar(int, int, int) const, CXWnd__DrawVScrollbar);
#endif
#ifdef CXWnd__DrawHScrollbar_x
FUNCTION_AT_ADDRESS(int CXWnd::DrawHScrollbar(int, int, int) const, CXWnd__DrawHScrollbar);
#endif
#ifdef CXWnd__Refade_x
FUNCTION_AT_ADDRESS(void CXWnd::Refade(), CXWnd__Refade);
#endif
#ifdef CXWnd__Move_x
FUNCTION_AT_ADDRESS(int CXWnd::Move(const CXPoint&), CXWnd__Move);
#endif
#ifdef CXWnd__Move1_x
FUNCTION_AT_ADDRESS(int CXWnd::Move(const CXRect&, bool, bool, bool, bool), CXWnd__Move1);
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
#ifdef CXWnd__GetNextChildWnd_x
FUNCTION_AT_ADDRESS(CXWnd* CXWnd::GetNextChildWnd(CXWnd*) const, CXWnd__GetNextChildWnd);
#endif
#ifdef CXWnd__GetChildWndAt_x
FUNCTION_AT_ADDRESS(CXWnd* CXWnd::GetChildWndAt(CXPoint*, int, int) const, CXWnd__GetChildWndAt);
#endif
#ifdef CXWnd__GetFirstChildWnd_x
FUNCTION_AT_ADDRESS(CXWnd* CXWnd::GetFirstChildWnd() const, CXWnd__GetFirstChildWnd);
#endif
#ifdef CXWnd__GetNextSib_x
FUNCTION_AT_ADDRESS(CXWnd* CXWnd::GetNextSib() const, CXWnd__GetNextSib);
#endif
#ifdef CXWnd__DoAllDrawing_x
FUNCTION_AT_ADDRESS(int CXWnd::DoAllDrawing() const, CXWnd__DoAllDrawing);
#endif
#ifdef CXWnd__DrawLasso_x
FUNCTION_AT_ADDRESS(int __cdecl CXWnd::DrawLasso(CXRect, unsigned long, CXRect), CXWnd__DrawLasso);
#endif
#ifdef CXWnd__DrawChildren_x
FUNCTION_AT_ADDRESS(int CXWnd::DrawChildren() const, CXWnd__DrawChildren);
#endif
#ifdef CXWnd__BringChildWndToTop_x
FUNCTION_AT_ADDRESS(void CXWnd::BringChildWndToTop(CXWnd*), CXWnd__BringChildWndToTop);
#endif
#ifdef CXWnd__DrawColoredRect_x
FUNCTION_AT_ADDRESS(int __cdecl CXWnd::DrawColoredRect(CXRect, unsigned long, CXRect), CXWnd__DrawColoredRect);
#endif
#ifdef CXWnd__GetTooltipRect_x
FUNCTION_AT_ADDRESS(CXRect* __cdecl CXWnd::GetTooltipRect(CXRect*), CXWnd__GetTooltipRect);
#endif
#ifdef CXWnd__GetTooltipRect1_x
FUNCTION_AT_ADDRESS(CXRect __cdecl CXWnd::GetTooltipRect(CXPoint, CXSize), CXWnd__GetTooltipRect1);
#endif
#ifdef CXWnd__DrawTooltipAtPoint_x
FUNCTION_AT_ADDRESS(void CXWnd::DrawTooltipAtPoint(CXPoint) const, CXWnd__DrawTooltipAtPoint);
#endif
#ifdef CXWnd__Bottom_x
FUNCTION_AT_ADDRESS(void CXWnd::Bottom(), CXWnd__Bottom);
#endif
#ifdef CXWnd__Center_x
FUNCTION_AT_ADDRESS(void CXWnd::Center(), CXWnd__Center);
#endif
#ifdef CXWnd__Right_x
FUNCTION_AT_ADDRESS(void CXWnd::Right(), CXWnd__Right);
#endif
#ifdef CXWnd__Left_x
FUNCTION_AT_ADDRESS(void CXWnd::Left(), CXWnd__Left);
#endif
#ifdef CXWnd__SetLookLikeParent_x
FUNCTION_AT_ADDRESS(void CXWnd::SetLookLikeParent(), CXWnd__SetLookLikeParent);
#endif
#ifdef CXWnd__GetClientClipRect_x
FUNCTION_AT_ADDRESS(CXRect CXWnd::GetClientClipRect() const, CXWnd__GetClientClipRect);
#endif
#ifdef CXWnd__GetScreenClipRect_x
FUNCTION_AT_ADDRESS(CXRect CXWnd::GetScreenClipRect() const, CXWnd__GetScreenClipRect);
#endif
#ifdef CXWnd__IsActive_x
FUNCTION_AT_ADDRESS(bool CXWnd::IsActive() const, CXWnd__IsActive);
#endif
#ifdef CXWnd__IsDescendantOf_x
FUNCTION_AT_ADDRESS(bool CXWnd::IsDescendantOf(CXWnd const*) const, CXWnd__IsDescendantOf);
#endif
#ifdef CXWnd__GetBorderFrame_x
FUNCTION_AT_ADDRESS(CTAFrameDraw const* CXWnd::GetBorderFrame() const, CXWnd__GetBorderFrame);
#endif
#ifdef CXWnd__GetTitlebarHeader_x
FUNCTION_AT_ADDRESS(CTAFrameDraw const* CXWnd::GetTitlebarHeader() const, CXWnd__GetTitlebarHeader);
#endif
#ifdef CXWnd__GetCloseBoxTemplate_x
FUNCTION_AT_ADDRESS(CButtonDrawTemplate const* CXWnd::GetCloseBoxTemplate() const, CXWnd__GetCloseBoxTemplate);
#endif
#ifdef CXWnd__GetMinimizeBoxTemplate_x
FUNCTION_AT_ADDRESS(CButtonDrawTemplate const* CXWnd::GetMinimizeBoxTemplate() const, CXWnd__GetMinimizeBoxTemplate);
#endif
#ifdef CXWnd__GetTileBoxTemplate_x
FUNCTION_AT_ADDRESS(CButtonDrawTemplate const* CXWnd::GetTileBoxTemplate() const, CXWnd__GetTileBoxTemplate);
#endif
#ifdef CXWnd__GetRelativeRect_x
FUNCTION_AT_ADDRESS(CXRect CXWnd::GetRelativeRect() const, CXWnd__GetRelativeRect);
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
#ifdef CXWnd__SetZLayer_x
FUNCTION_AT_ADDRESS(void CXWnd::SetZLayer(int), CXWnd__SetZLayer);
#endif
#ifdef CXWnd__SetFirstChildPointer_x
FUNCTION_AT_ADDRESS(void CXWnd::SetFirstChildPointer(CXWnd*), CXWnd__SetFirstChildPointer);
#endif
#ifdef CXWnd__SetNextSibPointer_x
FUNCTION_AT_ADDRESS(void CXWnd::SetNextSibPointer(CXWnd*), CXWnd__SetNextSibPointer);
#endif
#ifdef CXWnd__SetMouseOver_x
FUNCTION_AT_ADDRESS(void CXWnd::SetMouseOver(bool), CXWnd__SetMouseOver);
#endif
#ifdef CXWnd__SetKeyTooltip_x
FUNCTION_AT_ADDRESS(void CXWnd::SetKeyTooltip(int, int), CXWnd__SetKeyTooltip);
#endif
#ifdef CXWnd__GetXMLTooltip_x
FUNCTION_AT_ADDRESS(CXStr CXWnd::GetXMLTooltip() const, CXWnd__GetXMLTooltip);
#endif
#ifdef CXWnd__DrawTooltip_x
FUNCTION_AT_ADDRESS(int CXWnd::DrawTooltip(CXWnd const*) const, CXWnd__DrawTooltip);
#endif
#ifdef CXWnd__Tile_x
FUNCTION_AT_ADDRESS(int CXWnd::Tile(bool), CXWnd__Tile);
#endif
#ifdef CXWnd__IsEnabled_x
FUNCTION_AT_ADDRESS(bool CXWnd::IsEnabled() const, CXWnd__IsEnabled);
#endif
#ifdef CXWnd__GetWidth_x
FUNCTION_AT_ADDRESS(int CXWnd::GetWidth() const, CXWnd__GetWidth);
#endif
#ifdef CXWnd__SetXMLTooltip_x
FUNCTION_AT_ADDRESS(void CXWnd::SetXMLTooltip(CXStr), CXWnd__SetXMLTooltip);
#endif
#ifdef CXWnd__DrawRaisedRect_x
FUNCTION_AT_ADDRESS(int __cdecl CXWnd::DrawRaisedRect(CXRect, CXRect), CXWnd__DrawRaisedRect);
#endif
#ifdef CXWnd__DrawSunkenRect_x
FUNCTION_AT_ADDRESS(int __cdecl CXWnd::DrawSunkenRect(CXRect, CXRect), CXWnd__DrawSunkenRect);
#endif
#ifdef CXWnd__SetFont_x
FUNCTION_AT_ADDRESS(int CXWnd::SetFont(void*), CXWnd__SetFont);
#endif

} // namespace eqlib
