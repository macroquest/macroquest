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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include "UI.h"
#include "EQClasses.h"
#include "Globals.h"

namespace eqlib {

//============================================================================
// Statics
//============================================================================

CButtonWnd::VirtualFunctionTable* CButtonWnd::sm_vftable = nullptr;
CListWnd::VirtualFunctionTable* CListWnd::sm_vftable = nullptr;

//============================================================================
// CUITextureInfo
//============================================================================

CUITextureInfo::CUITextureInfo()
{
}

CUITextureInfo::CUITextureInfo(const CXStr& name, int size)
	: Name(name)
	, TextureSize(size, size)
	, bValid(true)
{
}

CUITextureInfo::CUITextureInfo(const CXStr& name, const CXSize& size)
	: Name(name)
	, TextureSize(size)
	, bValid(true)
{
}

CUITextureInfo::CUITextureInfo(uint32_t id, int size)
	: TextureId(id)
	, TextureSize(size, size)
	, bValid(true)
{
}

CUITextureInfo::CUITextureInfo(uint32_t id, const CXSize& size)
	: TextureId(id)
	, TextureSize(size)
	, bValid(true)
{
}

//============================================================================
// CUITexturePiece
//============================================================================

CUITexturePiece::CUITexturePiece()
	: m_info("", 0)
{
}

CUITexturePiece::CUITexturePiece(const CUITextureInfo& ti, const CXRect& rect)
	: m_info(ti)
	, m_rect(rect)
{
	m_info.TextureId = -1;
}

CUITexturePiece::CUITexturePiece(const CUITextureInfo& ti)
	: m_info(ti)
	, m_rect(CXPoint(0, 0), ti.TextureSize)
{
	m_info.TextureId = -1;
}

//============================================================================
// CTextureAnimation
//============================================================================

CTextureAnimation::CTextureAnimation()
{
}

CTextureAnimation::CTextureAnimation(const CXStr& name)
	: Name(name)
{
}

CTextureAnimation::CTextureAnimation(CUITexturePiece tp)
{
	AddFrame(tp, 1);
}

CTextureAnimation::~CTextureAnimation()
{
}

// 0x93b400 Jun 10 2019
int CTextureAnimation::AddFrame(const CUITextureInfo* ti, const CXRect& rect, uint32_t ticks, CXPoint hotspot)
{
	CUITexturePiece tp{ *ti, rect };

	return AddFrame(tp, ticks, hotspot);
}

// 0x93ba40 Jun 10 2019
int CTextureAnimation::AddFrame(CUITexturePiece tp, uint32_t ticks, CXPoint hotspot)
{
	ticks = std::max<uint32_t>(1, std::min<uint32_t>(10000, ticks));

	STextureAnimationFrame frame{ tp, ticks, hotspot };

	Size.cx = std::max(Size.cx, tp.GetSize().cx);
	Size.cy = std::max(Size.cy, tp.GetSize().cy);

	Frames.Add(frame);

	TotalTicks += TotalTicks;

	return Frames.GetLength() - 1;
}

// 0x93b5f0 Jun 10 2019
int CTextureAnimation::AddBlankFrame(uint32_t ticks, CXPoint hotspot)
{
	CUITexturePiece tp{ CUITextureInfo{0, 0}, CXRect{} };

	return AddFrame(tp, ticks, hotspot);
}

// 0x93b710 Jun 10 2019
void CTextureAnimation::SetCurFrame(int frame)
{
	if (!bGrid)
	{
		ZeroFrame = frame;
		StartTicks = GetTickCount();
	}
}

// 0x93bb60 Jun 10 2019
int CTextureAnimation::GetCurFrame() const
{
	int count = Frames.GetLength();

	if (count == 0)
		return -1;

	if (count == 1)
		return 0;

	if (bGrid || TotalTicks == 0 || bPaused)
		return ZeroFrame;

	// run through the frames until we accumulate enough ticks to reach the delta.
	uint32_t delta = GetTickCount() - StartTicks;

	// if we aren't a cycling texture, then we only need to check frames until we
	// reach the end. if we get to the end then we just return the last texture.
	if (!bCycle)
	{
		uint32_t ticks = 0;

		// check if we reach the last texture. return it if we do.
		for (int i = ZeroFrame; i < count; ++i)
		{
			ticks += Frames[i].Ticks;
		}

		// enough time has passed to reach the end. return the last frame.
		if (delta > ticks)
			return count - 1;
	}

	// reduce the ticks by the full size of the animation. This eliminates the need
	// to loop through the frames more than once.
	delta %= TotalTicks;
	int frame = ZeroFrame;

	do
	{
		const STextureAnimationFrame& texAnim = Frames[frame];

		if (texAnim.Ticks > delta)
			break;

		// increment
		delta -= texAnim.Ticks;
		frame++;

		// wrap around
		if (frame >= count)
			frame = 0;

	} while (true);

	return frame;
}

// 0x93b7a0 Jun 10 2019
void CTextureAnimation::Pause(bool pause)
{
	if (pause != bPaused)
	{
		bPaused = pause;
		if (bPaused)
		{
			ZeroFrame = GetCurFrame();
		}

		StartTicks = GetTickCount();
	}
}

// just return hotspot of current frame.
CXPoint CTextureAnimation::GetHotspot() const
{
	int frame = GetCurFrame();
	if (frame >= 0)
	{
		return Frames[frame].Hotspot;
	}

	return {};
}

#if defined CTextureAnimation__SetCurCell_x
FUNCTION_AT_ADDRESS(void CTextureAnimation::SetCurCell(int), CTextureAnimation__SetCurCell)
#endif

//============================================================================
// CButtonDrawTemplate
//============================================================================

CButtonDrawTemplate::CButtonDrawTemplate()
{
}

CButtonDrawTemplate::~CButtonDrawTemplate()
{
}

CTextureAnimation* CButtonDrawTemplate::GetAnimation(bool pressed, bool hover, bool disabled, bool decal /*= false*/) const
{
	if (decal)
	{
		if (disabled)
		{
			if (pressed && PressedDisabledDecal != nullptr)
			{
				return PressedDisabledDecal;
			}

			if (DisabledDecal != nullptr)
			{
				return DisabledDecal;
			}

			return NormalDecal;
		}

		if (pressed)
		{
			if (hover && PressedFlybyDecal != nullptr)
			{
				return PressedFlybyDecal;
			}

			if (PressedDecal != nullptr)
			{
				return PressedDecal;
			}

			return NormalDecal;
		}

		if (hover)
		{
			if (FlybyDecal != nullptr)
			{
				return FlybyDecal;
			}

			return NormalDecal;
		}
	}
	else // not a decal
	{
		if (disabled)
		{
			if (pressed && PressedDisabled != nullptr)
			{
				return PressedDisabled;
			}

			if (Disabled != nullptr)
			{
				return Disabled;
			}

			return Normal;
		}

		if (pressed)
		{
			if (hover && PressedFlyby != nullptr)
			{
				return PressedFlyby;
			}

			if (Pressed != nullptr)
			{
				return Pressed;
			}

			return Normal;
		}

		if (hover)
		{
			if (Flyby != nullptr)
			{
				return Flyby;
			}

			return Normal;
		}
	}

	return Normal;
}

CXSize CButtonDrawTemplate::GetSize() const
{
	if (Normal != nullptr)
	{
		return Normal->GetSize();
	}

	return { 0, 0 };
}

//============================================================================
// CRadioGroup
//============================================================================

CRadioGroup::CRadioGroup(CXStr name)
	: Name(name)
{
}

CRadioGroup::~CRadioGroup()
{
	for (int i = 0; i < Buttons.GetLength(); ++i)
	{
		if (Buttons[i])
		{
			Buttons[i]->SetRadioGroup(nullptr);
		}
	}
}

//============================================================================
// CButtonWnd
//============================================================================

// Class virtuals
FORWARD_FUNCTION_TO_VTABLE(void CButtonWnd::SetRadioGroup(CRadioGroup*), CButtonWnd, SetRadioGroup);
FORWARD_FUNCTION_TO_VTABLE(int CButtonWnd::DrawWndText(const CXRect&, const CXRect&), CButtonWnd, DrawWndText);
FORWARD_FUNCTION_TO_VTABLE(int CButtonWnd::DrawCooldown(), CButtonWnd, DrawCooldown);
FORWARD_FUNCTION_TO_VTABLE(void CButtonWnd::SetCheck(bool), CButtonWnd, SetCheck);
FORWARD_FUNCTION_TO_VTABLE(void CButtonWnd::SetCoolDownCompletionTimeDelta(uint32_t, uint32_t), CButtonWnd, SetCoolDownCompletionTimeDelta);
FORWARD_FUNCTION_TO_VTABLE(void CButtonWnd::SetCoolDownCompletionTime(uint32_t, uint32_t), CButtonWnd, SetCoolDownCompletionTime);
FORWARD_FUNCTION_TO_VTABLE(void CButtonWnd::SetCoolDownCompletionTime(time_t, uint32_t), CButtonWnd, SetCoolDownCompletionTime2);
FORWARD_FUNCTION_TO_VTABLE(void CButtonWnd::SetCoolDownBeginTime(uint32_t, uint32_t), CButtonWnd, SetCoolDownBeginTime);
FORWARD_FUNCTION_TO_VTABLE(void CButtonWnd::SetCoolDownUpdatedBeginTime(uint32_t, uint32_t), CButtonWnd, SetCoolDownUpdatedBeginTime);
FORWARD_FUNCTION_TO_VTABLE(uint32_t CButtonWnd::GetCoolDownBeginTime() const, CButtonWnd, SetCoolDownUpdatedBeginTime);
FORWARD_FUNCTION_TO_VTABLE(uint32_t CButtonWnd::GetCoolDownTotalDuration() const, CButtonWnd, GetCoolDownTotalDuration);
FORWARD_FUNCTION_TO_VTABLE(uint32_t CButtonWnd::GetCoolDownTimeRemaining() const, CButtonWnd, GetCoolDownTimeRemaining);
FORWARD_FUNCTION_TO_VTABLE(void CButtonWnd::ClearCoolDownCompletionTime(), CButtonWnd, ClearCoolDownCompletionTime);

// Overridden virtuals
FORWARD_FUNCTION_TO_VTABLE2(int CButtonWnd::Draw(), CButtonWnd, CXWnd, Draw);
FORWARD_FUNCTION_TO_VTABLE2(int CButtonWnd::DrawTooltipAtPoint(const CXPoint& pos, const CXStr& tooltip) const, CButtonWnd, CXWnd, DrawTooltipAtPoint);
FORWARD_FUNCTION_TO_VTABLE2(int CButtonWnd::HandleLButtonDown(const CXPoint&, uint32_t), CButtonWnd, CXWnd, HandleLButtonDown);
FORWARD_FUNCTION_TO_VTABLE2(int CButtonWnd::HandleLButtonUp(const CXPoint&, uint32_t), CButtonWnd, CXWnd, HandleLButtonUp);
FORWARD_FUNCTION_TO_VTABLE2(int CButtonWnd::HandleLButtonHeld(const CXPoint&, uint32_t), CButtonWnd, CXWnd, HandleLButtonHeld);
FORWARD_FUNCTION_TO_VTABLE2(int CButtonWnd::HandleLButtonUpAfterHeld(const CXPoint&, uint32_t), CButtonWnd, CXWnd, HandleLButtonUpAfterHeld);
FORWARD_FUNCTION_TO_VTABLE2(int CButtonWnd::HandleRButtonDown(const CXPoint&, uint32_t), CButtonWnd, CXWnd, HandleRButtonDown);
FORWARD_FUNCTION_TO_VTABLE2(int CButtonWnd::HandleRButtonUp(const CXPoint&, uint32_t), CButtonWnd, CXWnd, HandleRButtonUp);
FORWARD_FUNCTION_TO_VTABLE2(int CButtonWnd::HandleRButtonHeld(const CXPoint&, uint32_t), CButtonWnd, CXWnd, HandleRButtonHeld);
FORWARD_FUNCTION_TO_VTABLE2(int CButtonWnd::HandleRButtonUpAfterHeld(const CXPoint&, uint32_t), CButtonWnd, CXWnd, HandleRButtonUpAfterHeld);
FORWARD_FUNCTION_TO_VTABLE2(int CButtonWnd::HandleMouseMove(const CXPoint&, uint32_t), CButtonWnd, CXWnd, HandleMouseMove);
FORWARD_FUNCTION_TO_VTABLE2(int CButtonWnd::OnProcessFrame(), CButtonWnd, CXWnd, OnProcessFrame);
FORWARD_FUNCTION_TO_VTABLE2(bool CButtonWnd::IsPointTransparent(const CXPoint& point) const, CButtonWnd, CXWnd, IsPointTransparent);
FORWARD_FUNCTION_TO_VTABLE2(void CButtonWnd::SetAttributesFromSidl(CParamScreenPiece*), CButtonWnd, CXWnd, SetAttributesFromSidl);

//============================================================================
// CComboWnd
//============================================================================

#ifdef CComboWnd__GetListRect_x
FUNCTION_AT_ADDRESS(CXRect CComboWnd::GetListRect(bool) const, CComboWnd__GetListRect);
#endif
#ifdef CComboWnd__SetColors_x
FUNCTION_AT_ADDRESS(void CComboWnd::SetColors(COLORREF, COLORREF, COLORREF), CComboWnd__SetColors);
#endif
#ifdef CComboWnd__InsertChoice_x
FUNCTION_AT_ADDRESS(void CComboWnd::InsertChoice(const CXStr&, uint32_t), CComboWnd__InsertChoice);
#endif
#ifdef CComboWnd__SetChoice_x
FUNCTION_AT_ADDRESS(void CComboWnd::SetChoice(int), CComboWnd__SetChoice);
#endif
#ifdef CComboWnd__GetItemCount_x
FUNCTION_AT_ADDRESS(int CComboWnd::GetItemCount(), CComboWnd__GetItemCount);
#endif
#ifdef CComboWnd__GetCurChoice_x
FUNCTION_AT_ADDRESS(int CComboWnd::GetCurChoice() const, CComboWnd__GetCurChoice);
#endif
#ifdef CComboWnd__GetCurChoiceText_x
FUNCTION_AT_ADDRESS(CXStr CComboWnd::GetCurChoiceText() const, CComboWnd__GetCurChoiceText);
#endif
#ifdef CComboWnd__DeleteAll_x
FUNCTION_AT_ADDRESS(void CComboWnd::DeleteAll(), CComboWnd__DeleteAll);
#endif
#ifdef CComboWnd__GetTextRect_x
FUNCTION_AT_ADDRESS(CXRect CComboWnd::GetTextRect() const, CComboWnd__GetTextRect);
#endif

//============================================================================
// CEditWnd
//============================================================================

// CEditBaseWnd
#ifdef CEditBaseWnd__SetMaxChars_x
FUNCTION_AT_ADDRESS(void CEditBaseWnd::SetMaxChars(int), CEditBaseWnd__SetMaxChars);
#endif
#ifdef CEditBaseWnd__SetSel_x
FUNCTION_AT_ADDRESS(void CEditBaseWnd::SetSel(int, int), CEditBaseWnd__SetSel);
#endif


// CEditWnd
#ifdef CEditWnd__CEditWnd_x
//FUNCTION_AT_ADDRESS(CEditWnd::CEditWnd(CXWnd*, uint32_t, CXRect, uint32_t), CEditWnd__CEditWnd);
#endif
#ifdef CEditWnd__GetLineForPrintableChar_x
FUNCTION_AT_ADDRESS(int CEditWnd::GetLineForPrintableChar(int) const, CEditWnd__GetLineForPrintableChar);
#endif
#ifdef CEditWnd__GetLineLength_x
FUNCTION_AT_ADDRESS(int CEditWnd::GetLineLength(int) const, CEditWnd__GetLineLength);
#endif
#ifdef CEditWnd__FillIndexArray_x
FUNCTION_AT_ADDRESS(void CEditWnd::FillIndexArray(CXStr) const, CEditWnd__FillIndexArray);
#endif
#ifdef CEditWnd__SelectableCharFromPoint_x
FUNCTION_AT_ADDRESS(int CEditWnd::SelectableCharFromPoint(CXPoint) const, CEditWnd__SelectableCharFromPoint);
#endif
#ifdef CEditWnd__AddItemTag_x
FUNCTION_AT_ADDRESS(void CEditWnd::AddItemTag(int, char*, int), CEditWnd__AddItemTag);
#endif
#ifdef CEditWnd__ProcessText_x
FUNCTION_AT_ADDRESS(void CEditWnd::ProcessText(), CEditWnd__ProcessText);
#endif
#ifdef CEditWnd__GetCharIndexPt_x
FUNCTION_AT_ADDRESS(CXPoint CEditWnd::GetCharIndexPt(int) const, CEditWnd__GetCharIndexPt);
#endif
#ifdef CEditWnd__GetSelStartPt_x
FUNCTION_AT_ADDRESS(CXPoint CEditWnd::GetSelStartPt() const, CEditWnd__GetSelStartPt);
#endif
#ifdef CEditWnd__GetSelEndPt_x
FUNCTION_AT_ADDRESS(CXPoint CEditWnd::GetSelEndPt() const, CEditWnd__GetSelEndPt);
#endif
#ifdef CEditWnd__FilterInputStr_x
FUNCTION_AT_ADDRESS(void CEditWnd::FilterInputStr(CXStr&), CEditWnd__FilterInputStr);
#endif
#ifdef CEditWnd__ReplaceSelection_x
FUNCTION_AT_ADDRESS(void CEditWnd::ReplaceSelection(CXStr, bool), CEditWnd__ReplaceSelection);
#endif
#ifdef CEditWnd__ReplaceSelection1_x
FUNCTION_AT_ADDRESS(void CEditWnd::ReplaceSelection(char, bool), CEditWnd__ReplaceSelection1);
#endif
#ifdef CEditWnd__CalculateScrollRange_x
FUNCTION_AT_ADDRESS(void CEditWnd::CalculateScrollRange(), CEditWnd__CalculateScrollRange);
#endif
#ifdef CEditWnd__EnsureCaretVisible_x
FUNCTION_AT_ADDRESS(void CEditWnd::EnsureCaretVisible(), CEditWnd__EnsureCaretVisible);
#endif
#ifdef CEditWnd__SetEditable_x
FUNCTION_AT_ADDRESS(void CEditWnd::SetEditable(bool), CEditWnd__SetEditable);
#endif
#ifdef CEditWnd__GetSTMLSafeText_x
FUNCTION_AT_ADDRESS(CXStr CEditWnd::GetSTMLSafeText(), CEditWnd__GetSTMLSafeText);
#endif
#ifdef CEditWnd__SetWindowTextA_x
FUNCTION_AT_ADDRESS(void CEditWnd::SetWindowTextA(const CXStr& Str), CEditWnd__SetWindowTextA);
#endif
#ifdef CEditWnd__ConvertIndexPrintableToTagged_x
FUNCTION_AT_ADDRESS(int CEditWnd::ConvertIndexPrintableToTagged(int), CEditWnd__ConvertIndexPrintableToTagged);
#endif
#ifdef CEditWnd__ConvertIndexTaggedToPrintable_x
FUNCTION_AT_ADDRESS(int CEditWnd::ConvertIndexTaggedToPrintable(int), CEditWnd__ConvertIndexTaggedToPrintable);
#endif

//============================================================================
// CListWnd
//============================================================================

// class virtuals
FORWARD_FUNCTION_TO_VTABLE(int CListWnd::OnHeaderClick(CXPoint), CListWnd, OnHeaderClick);
FORWARD_FUNCTION_TO_VTABLE(int CListWnd::DrawColumnSeparators() const, CListWnd, DrawColumnSeparators);
FORWARD_FUNCTION_TO_VTABLE(int CListWnd::DrawSeparator(int index) const, CListWnd, DrawSeparator);
FORWARD_FUNCTION_TO_VTABLE(int CListWnd::DrawLine(int index) const, CListWnd, DrawLine);
FORWARD_FUNCTION_TO_VTABLE(int CListWnd::DrawHeader() const, CListWnd, DrawHeader);
FORWARD_FUNCTION_TO_VTABLE(int CListWnd::DrawItem(int index, int, int) const, CListWnd, DrawItem);
FORWARD_FUNCTION_TO_VTABLE(void CListWnd::DeleteAll(), CListWnd, DeleteAll);
FORWARD_FUNCTION_TO_VTABLE(int CListWnd::Compare(const SListWndLine&, const SListWndLine&) const, CListWnd, Compare);
FORWARD_FUNCTION_TO_VTABLE(void CListWnd::Sort(), CListWnd, Sort);

// overrides
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::Draw(), CListWnd, CXWnd, Draw);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::DrawBackground() const, CListWnd, CXWnd, DrawBackground);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::DrawTooltip(const CXWnd* wnd) const, CListWnd, CXWnd, DrawTooltip);
FORWARD_FUNCTION_TO_VTABLE2(HCURSOR CListWnd::GetCursorToDisplay() const, CListWnd, CXWnd, GetCursorToDisplay);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::HandleLButtonDown(const CXPoint& pos, uint32_t flags), CListWnd, CXWnd, HandleLButtonDown);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::HandleLButtonUp(const CXPoint& pos, uint32_t flags), CListWnd, CXWnd, HandleLButtonUp);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::HandleLButtonHeld(const CXPoint& pos, uint32_t flags), CListWnd, CXWnd, HandleLButtonHeld);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::HandleLButtonUpAfterHeld(const CXPoint& pos, uint32_t flags), CListWnd, CXWnd, HandleLButtonUpAfterHeld);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::HandleRButtonDown(const CXPoint& pos, uint32_t flags), CListWnd, CXWnd, HandleRButtonDown);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::HandleRButtonUp(const CXPoint& pos, uint32_t flags), CListWnd, CXWnd, HandleRButtonUp);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::HandleRButtonHeld(const CXPoint& pos, uint32_t flags), CListWnd, CXWnd, HandleRButtonHeld);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::HandleRButtonUpAfterHeld(const CXPoint& pos, uint32_t flags), CListWnd, CXWnd, HandleRButtonUpAfterHeld);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::HandleMouseMove(const CXPoint& pos, uint32_t flags), CListWnd, CXWnd, HandleMouseMove);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::WndNotification(CXWnd* sender, uint32_t message, void* data), CListWnd, CXWnd, WndNotification);
FORWARD_FUNCTION_TO_VTABLE2(void CListWnd::OnWndNotification(), CListWnd, CXWnd, OnWndNotification);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::OnMove(const CXRect& rect), CListWnd, CXWnd, OnMove);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::OnResize(int w, int h), CListWnd, CXWnd, OnResize);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::OnVScroll(EScrollCode code, int pos), CListWnd, CXWnd, OnVScroll);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::OnHScroll(EScrollCode code, int pos), CListWnd, CXWnd, OnHScroll);
FORWARD_FUNCTION_TO_VTABLE2(CXRect CListWnd::GetHitTestRect(int code) const, CListWnd, CXWnd, GetHitTestRect);
FORWARD_FUNCTION_TO_VTABLE2(CXRect CListWnd::GetClientClipRect() const, CListWnd, CXWnd, GetClientClipRect);
FORWARD_FUNCTION_TO_VTABLE2(CXWnd* CListWnd::GetChildWndAt(const CXPoint& pos, bool, bool) const, CListWnd, CXWnd, GetChildWndAt);
FORWARD_FUNCTION_TO_VTABLE2(int CListWnd::SetVScrollPos(int pos), CListWnd, CXWnd, SetVScrollPos);

#ifdef CListWnd__CListWnd_x
CONSTRUCTOR_AT_ADDRESS(CListWnd::CListWnd(CXWnd*, uint32_t, CXRect const&), CListWnd__CListWnd);
#endif
#ifdef CListWnd__dCListWnd_x
FUNCTION_AT_ADDRESS(CListWnd::~CListWnd(), CListWnd__dCListWnd);
#endif
#ifdef CListWnd__GetCurSel_x
FUNCTION_AT_ADDRESS(int CListWnd::GetCurSel() const, CListWnd__GetCurSel);
#endif
#ifdef CListWnd__GetCurCol_x
FUNCTION_AT_ADDRESS(int CListWnd::GetCurCol() const, CListWnd__GetCurCol);
#endif
#ifdef CListWnd__GetItemData_x
FUNCTION_AT_ADDRESS(uint64_t CListWnd::GetItemData(int) const, CListWnd__GetItemData);
#endif
#ifdef CListWnd__GetItemText_x
FUNCTION_AT_ADDRESS(CXStr CListWnd::GetItemText(const CXStr&, int, int) const, CListWnd__GetItemText);
#endif
#ifdef CListWnd__GetItemIcon_x
FUNCTION_AT_ADDRESS(CTextureAnimation const* CListWnd::GetItemIcon(int, int) const, CListWnd__GetItemIcon);
#endif
#ifdef CListWnd__GetItemColor_x
FUNCTION_AT_ADDRESS(unsigned long CListWnd::GetItemColor(int, int) const, CListWnd__GetItemColor);
#endif
#ifdef CListWnd__GetColumnFlags_x
FUNCTION_AT_ADDRESS(uint32_t CListWnd::GetColumnFlags(int) const, CListWnd__GetColumnFlags);
#endif
#ifdef CListWnd__GetColumnWidth_x
FUNCTION_AT_ADDRESS(int CListWnd::GetColumnWidth(int) const, CListWnd__GetColumnWidth);
#endif
#ifdef CListWnd__SetColumnWidth_x
FUNCTION_AT_ADDRESS(void CListWnd::SetColumnWidth(int, int), CListWnd__SetColumnWidth);
#endif
#ifdef CListWnd__ShiftColumnSeparator_x
FUNCTION_AT_ADDRESS(void CListWnd::ShiftColumnSeparator(int, int), CListWnd__ShiftColumnSeparator);
#endif
#ifdef CListWnd__GetColumnMinWidth_x
FUNCTION_AT_ADDRESS(int CListWnd::GetColumnMinWidth(int) const, CListWnd__GetColumnMinWidth);
#endif
#ifdef CListWnd__GetColumnTooltip_x
FUNCTION_AT_ADDRESS(CXStr CListWnd::GetColumnTooltip(int) const, CListWnd__GetColumnTooltip);
#endif
#ifdef CListWnd__GetColumnJustification_x
FUNCTION_AT_ADDRESS(int CListWnd::GetColumnJustification(int) const, CListWnd__GetColumnJustification);
#endif
#ifdef CListWnd__SetColumnJustification_x
FUNCTION_AT_ADDRESS(void CListWnd::SetColumnJustification(int, int), CListWnd__SetColumnJustification);
#endif
#ifdef CListWnd__GetColumnLabel_x
FUNCTION_AT_ADDRESS(CXStr CListWnd::GetColumnLabel(int) const, CListWnd__GetColumnLabel);
#endif
#ifdef CListWnd__GetColumnAnimation_x
FUNCTION_AT_ADDRESS(CTextureAnimation const* CListWnd::GetColumnAnimation(int) const, CListWnd__GetColumnAnimation);
#endif
#ifdef CListWnd__GetColumnAnimationSelected_x
FUNCTION_AT_ADDRESS(CTextureAnimation const* CListWnd::GetColumnAnimationSelected(int) const, CListWnd__GetColumnAnimationSelected);
#endif
#ifdef CListWnd__GetColumnAnimationMouseOver_x
FUNCTION_AT_ADDRESS(CTextureAnimation const* CListWnd::GetColumnAnimationMouseOver(int) const, CListWnd__GetColumnAnimationMouseOver);
#endif
#ifdef CListWnd__AddLine_x
FUNCTION_AT_ADDRESS(int CListWnd::AddLine(SListWndLine*), CListWnd__AddLine);
#endif
#ifdef CListWnd__AddString_x
FUNCTION_AT_ADDRESS(int CListWnd::AddString(const CXStr& Str, COLORREF Color, uint64_t Data, const CTextureAnimation* pTa, const char* TooltipStr), CListWnd__AddString);
#endif
#ifdef CListWnd__RemoveString_x
FUNCTION_AT_ADDRESS(void CListWnd::RemoveString(int), CListWnd__RemoveString);
#endif
#ifdef CListWnd__InsertLine_x
FUNCTION_AT_ADDRESS(void CListWnd::InsertLine(int ID, SListWndLine* rEntry), CListWnd__InsertLine);
#endif
#ifdef CListWnd__RemoveLine_x
FUNCTION_AT_ADDRESS(void CListWnd::RemoveLine(int), CListWnd__RemoveLine);
#endif
#ifdef CListWnd__SetCurSel_x
FUNCTION_AT_ADDRESS(void CListWnd::SetCurSel(int), CListWnd__SetCurSel);
#endif
#ifdef CListWnd__ToggleSel_x
FUNCTION_AT_ADDRESS(void CListWnd::ToggleSel(int), CListWnd__ToggleSel);
#endif
#ifdef CListWnd__ExtendSel_x
FUNCTION_AT_ADDRESS(void CListWnd::ExtendSel(int), CListWnd__ExtendSel);
#endif
#ifdef CListWnd__ClearAllSel_x
FUNCTION_AT_ADDRESS(void CListWnd::ClearAllSel(), CListWnd__ClearAllSel);
#endif
#ifdef CListWnd__ClearSel_x
FUNCTION_AT_ADDRESS(void CListWnd::ClearSel(int), CListWnd__ClearSel);
#endif
#ifdef CListWnd__SetColumnsSizable_x
FUNCTION_AT_ADDRESS(void CListWnd::SetColumnsSizable(bool), CListWnd__SetColumnsSizable);
#endif
#ifdef CListWnd__GetItemWnd_x
FUNCTION_AT_ADDRESS(CXWnd* CListWnd::GetItemWnd(int Index, int SubItem) const, CListWnd__GetItemWnd);
#endif
#ifdef CListWnd__SetItemIcon_x
FUNCTION_AT_ADDRESS(void CListWnd::SetItemIcon(int Index, int SubItem, const CTextureAnimation* pTA), CListWnd__SetItemIcon);
#endif
#ifdef CListWnd__CalculateCustomWindowPositions_x
FUNCTION_AT_ADDRESS(void CListWnd::CalculateCustomWindowPositions(), CListWnd__CalculateCustomWindowPositions);
#endif
#ifdef CListWnd__SetItemWnd_x
FUNCTION_AT_ADDRESS(void CListWnd::SetItemWnd(int Index, int SubItem, CXWnd* pWnd), CListWnd__SetItemWnd);
#endif
#ifdef CListWnd__SetItemData_x
FUNCTION_AT_ADDRESS(void CListWnd::SetItemData(int, uint64_t), CListWnd__SetItemData);
#endif
#ifdef CListWnd__SetItemText_x
FUNCTION_AT_ADDRESS(void CListWnd::SetItemText(int, int, const CXStr&), CListWnd__SetItemText);
#endif
#ifdef CListWnd__SetItemColor_x
FUNCTION_AT_ADDRESS(void CListWnd::SetItemColor(int, int, unsigned long), CListWnd__SetItemColor);
#endif
#ifdef CListWnd__IsLineEnabled_x
FUNCTION_AT_ADDRESS(bool CListWnd::IsLineEnabled(int) const, CListWnd__IsLineEnabled);
#endif
#ifdef CListWnd__EnableLine_x
FUNCTION_AT_ADDRESS(void CListWnd::EnableLine(int, bool), CListWnd__EnableLine);
#endif
#ifdef CListWnd__AddColumn_x
FUNCTION_AT_ADDRESS(int CListWnd::AddColumn(const CXStr&, int, uint32_t, uint32_t), CListWnd__AddColumn);
#endif
#ifdef CListWnd__AddColumn1_x
// CListWnd::AddColumn implemented in ExceptionsDisabled.cpp
#endif
#ifdef CListWnd__SetColumnLabel_x
FUNCTION_AT_ADDRESS(void CListWnd::SetColumnLabel(int, CXStr), CListWnd__SetColumnLabel);
#endif
#ifdef CListWnd__GetItemHeight_x
FUNCTION_AT_ADDRESS(int CListWnd::GetItemHeight(int) const, CListWnd__GetItemHeight);
#endif
#ifdef CListWnd__CalculateLineHeights_x
FUNCTION_AT_ADDRESS(void CListWnd::CalculateLineHeights(), CListWnd__CalculateLineHeights);
#endif
#ifdef CListWnd__CalculateVSBRange_x
FUNCTION_AT_ADDRESS(void CListWnd::CalculateVSBRange(), CListWnd__CalculateVSBRange);
#endif
#ifdef CListWnd__CalculateFirstVisibleLine_x
FUNCTION_AT_ADDRESS(void CListWnd::CalculateFirstVisibleLine(), CListWnd__CalculateFirstVisibleLine);
#endif
#ifdef CListWnd__EnsureVisible_x
FUNCTION_AT_ADDRESS(void CListWnd::EnsureVisible(int), CListWnd__EnsureVisible);
#endif
#ifdef CListWnd__GetItemRect_x
FUNCTION_AT_ADDRESS(CXRect CListWnd::GetItemRect(int, int) const, CListWnd__GetItemRect);
#endif
#ifdef CListWnd__GetItemAtPoint_x
FUNCTION_AT_ADDRESS(int CListWnd::GetItemAtPoint(const CXPoint&) const, CListWnd__GetItemAtPoint);
#endif
#ifdef CListWnd__GetItemAtPoint1_x
FUNCTION_AT_ADDRESS(void CListWnd::GetItemAtPoint(const CXPoint&, int*, int*) const, CListWnd__GetItemAtPoint1);
#endif
#ifdef CListWnd__CloseAndUpdateEditWindow_x
FUNCTION_AT_ADDRESS(void CListWnd::CloseAndUpdateEditWindow(), CListWnd__CloseAndUpdateEditWindow);
#endif
#ifdef CListWnd__SetColors_x
FUNCTION_AT_ADDRESS(void CListWnd::SetColors(unsigned long, unsigned long, unsigned long), CListWnd__SetColors);
#endif
#ifdef CListWnd__GetSeparatorRect_x
FUNCTION_AT_ADDRESS(CXRect CListWnd::GetSeparatorRect(int) const, CListWnd__GetSeparatorRect);
#endif
#ifdef CListWnd__GetHeaderRect_x
FUNCTION_AT_ADDRESS(CXRect CListWnd::GetHeaderRect(int) const, CListWnd__GetHeaderRect);
#endif

//============================================================================
// CMapViewWnd
//============================================================================

// CMapViewWnd
#ifdef CMapViewWnd__IsMappingEnabled_x
FUNCTION_AT_ADDRESS(bool CMapViewWnd::IsMappingEnabled(), CMapViewWnd__IsMappingEnabled);
#endif
#ifdef CMapViewWnd__CMapViewWnd_x
CONSTRUCTOR_AT_ADDRESS(CMapViewWnd::CMapViewWnd(CXWnd*), CMapViewWnd__CMapViewWnd);
#endif
#ifdef CMapViewWnd__Init_x
FUNCTION_AT_ADDRESS(void CMapViewWnd::Init(), CMapViewWnd__Init);
#endif
#ifdef CMapViewWnd__Activate_x
FUNCTION_AT_ADDRESS(void CMapViewWnd::Activate(), CMapViewWnd__Activate);
#endif
#ifdef CMapViewWnd__ActivateAutoMapping_x
FUNCTION_AT_ADDRESS(void CMapViewWnd::ActivateAutoMapping(), CMapViewWnd__ActivateAutoMapping);
#endif
#ifdef CMapViewWnd__DeactivateAutoMapping_x
FUNCTION_AT_ADDRESS(void CMapViewWnd::DeactivateAutoMapping(), CMapViewWnd__DeactivateAutoMapping);
#endif
#ifdef CMapViewWnd__GetWorldCoordinates_x
FUNCTION_AT_ADDRESS(void CMapViewWnd::GetWorldCoordinates(float*), CMapViewWnd__GetWorldCoordinates);
#endif

// MapViewMap
#ifdef MapViewMap__MapViewMap_x
FUNCTION_AT_ADDRESS(MapViewMap::MapViewMap(), MapViewMap__MapViewMap);
#endif
#ifdef MapViewMap__dMapViewMap_x
FUNCTION_AT_ADDRESS(MapViewMap::~MapViewMap(), MapViewMap__dMapViewMap);
#endif
#ifdef CMapViewWnd__HandleLButtonDown_x
FUNCTION_AT_ADDRESS(int MapViewMap::HandleLButtonDown(const CXPoint&, uint32_t), CMapViewWnd__HandleLButtonDown);
#endif
#ifdef MapViewMap__Clear_x
FUNCTION_AT_ADDRESS(void MapViewMap::Clear(), MapViewMap__Clear);
#endif
#ifdef MapViewMap__StartLine_x
FUNCTION_AT_ADDRESS(void MapViewMap::StartLine(float, float, float), MapViewMap__StartLine);
#endif
#ifdef MapViewMap__EndLine_x
FUNCTION_AT_ADDRESS(void MapViewMap::EndLine(float, float, float), MapViewMap__EndLine);
#endif
#ifdef MapViewMap__RemoveLine_x
FUNCTION_AT_ADDRESS(void MapViewMap::RemoveLine(), MapViewMap__RemoveLine);
#endif
#ifdef MapViewMap__AddPoint_x
FUNCTION_AT_ADDRESS(void MapViewMap::AddPoint(float, float, float), MapViewMap__AddPoint);
#endif
#ifdef MapViewMap__AddLabel_x
FUNCTION_AT_ADDRESS(void MapViewMap::AddLabel(float, float, float, unsigned long, int, char*), MapViewMap__AddLabel);
#endif
#ifdef MapViewMap__RecalcLabelExtents_x
FUNCTION_AT_ADDRESS(void MapViewMap::RecalcLabelExtents(struct _mapviewlabel*), MapViewMap__RecalcLabelExtents);
#endif
#ifdef MapViewMap__RemoveLabel_x
FUNCTION_AT_ADDRESS(void MapViewMap::RemoveLabel(), MapViewMap__RemoveLabel);
#endif
#ifdef MapViewMap__MoveLabel_x
FUNCTION_AT_ADDRESS(void MapViewMap::MoveLabel(struct _mapviewlabel*, float, float, float), MapViewMap__MoveLabel);
#endif
#ifdef MapViewMap__CalcLabelRenderOffsets_x
FUNCTION_AT_ADDRESS(void MapViewMap::CalcLabelRenderOffsets(CXRect), MapViewMap__CalcLabelRenderOffsets);
#endif
#ifdef MapViewMap__IsLayerVisible_x
FUNCTION_AT_ADDRESS(bool MapViewMap::IsLayerVisible(int), MapViewMap__IsLayerVisible);
#endif
#ifdef MapViewMap__PointInMapViewArea_x
FUNCTION_AT_ADDRESS(bool MapViewMap::PointInMapViewArea(CXPoint, CXRect), MapViewMap__PointInMapViewArea);
#endif
#ifdef MapViewMap__PreCalcRenderValues_x
FUNCTION_AT_ADDRESS(void MapViewMap::PreCalcRenderValues(), MapViewMap__PreCalcRenderValues);
#endif
#ifdef MapViewMap__TransformPoint_x
FUNCTION_AT_ADDRESS(void MapViewMap::TransformPoint(struct T3D_XYZ*), MapViewMap__TransformPoint);
#endif
#ifdef MapViewMap__Draw_x
FUNCTION_AT_ADDRESS(void MapViewMap::Draw(CXRect), MapViewMap__Draw);
#endif
#ifdef MapViewMap__DrawClippedLine_x
FUNCTION_AT_ADDRESS(bool MapViewMap::DrawClippedLine(struct T3D_XYZ*, struct T3D_RGB, CXRect), MapViewMap__DrawClippedLine);
#endif
#ifdef MapViewMap__Save_x
FUNCTION_AT_ADDRESS(void MapViewMap::Save(char*), MapViewMap__Save);
#endif
#ifdef MapViewMap__SaveEx_x
FUNCTION_AT_ADDRESS(void MapViewMap::SaveEx(char*, int), MapViewMap__SaveEx);
#endif
#ifdef MapViewMap__Load_x
FUNCTION_AT_ADDRESS(void MapViewMap::Load(char*), MapViewMap__Load);
#endif
#ifdef MapViewMap__LoadEx_x
FUNCTION_AT_ADDRESS(bool MapViewMap::LoadEx(char*, int), MapViewMap__LoadEx);
#endif
#ifdef MapViewMap__GetCurrentColor_x
FUNCTION_AT_ADDRESS(unsigned long MapViewMap::GetCurrentColor(), MapViewMap__GetCurrentColor);
#endif
#ifdef MapViewMap__SetCurrentColor_x
FUNCTION_AT_ADDRESS(void MapViewMap::SetCurrentColor(unsigned long), MapViewMap__SetCurrentColor);
#endif
#ifdef MapViewMap__SetMarkedLine_x
FUNCTION_AT_ADDRESS(void MapViewMap::SetMarkedLine(struct _mapviewline*), MapViewMap__SetMarkedLine);
#endif
#ifdef MapViewMap__SetMarkedLineColor_x
FUNCTION_AT_ADDRESS(void MapViewMap::SetMarkedLineColor(unsigned long), MapViewMap__SetMarkedLineColor);
#endif
#ifdef MapViewMap__GetMarkedLineColor_x
FUNCTION_AT_ADDRESS(unsigned long MapViewMap::GetMarkedLineColor(), MapViewMap__GetMarkedLineColor);
#endif
#ifdef MapViewMap__ClearActiveLayer_x
FUNCTION_AT_ADDRESS(void MapViewMap::ClearActiveLayer(), MapViewMap__ClearActiveLayer);
#endif
#ifdef MapViewMap__RemoveLine1_x
FUNCTION_AT_ADDRESS(void MapViewMap::RemoveLine(struct _mapviewline*), MapViewMap__RemoveLine1);
#endif
#ifdef MapViewMap__RemoveLabel1_x
FUNCTION_AT_ADDRESS(void MapViewMap::RemoveLabel(struct _mapviewlabel*), MapViewMap__RemoveLabel1);
#endif
#ifdef MapViewMap__JoinLinesAtIntersect_x
FUNCTION_AT_ADDRESS(void MapViewMap::JoinLinesAtIntersect(bool), MapViewMap__JoinLinesAtIntersect);
#endif
#ifdef MapViewMap__SetZoneExtents_x
FUNCTION_AT_ADDRESS(void MapViewMap::SetZoneExtents(int, int, int, int), MapViewMap__SetZoneExtents);
#endif
#ifdef MapViewMap__SetZoom_x
FUNCTION_AT_ADDRESS(void MapViewMap::SetZoom(float), MapViewMap__SetZoom);
#endif
#ifdef MapViewMap__GetMinZ_x
FUNCTION_AT_ADDRESS(int MapViewMap::GetMinZ(), MapViewMap__GetMinZ);
#endif
#ifdef MapViewMap__GetMaxZ_x
FUNCTION_AT_ADDRESS(int MapViewMap::GetMaxZ(), MapViewMap__GetMaxZ);
#endif

//============================================================================
// CChatWindowManager
//============================================================================

#ifdef CChatWindowManager__FreeChatWindow_x
FUNCTION_AT_ADDRESS(void CChatWindowManager::FreeChatWindow(CChatWindow*), CChatWindowManager__FreeChatWindow);
#endif
#ifdef CChatWindowManager__GetRGBAFromIndex_x
FUNCTION_AT_ADDRESS(COLORREF CChatWindowManager::GetRGBAFromIndex(int), CChatWindowManager__GetRGBAFromIndex);
#endif
#ifdef CChatWindowManager__InitContextMenu_x
FUNCTION_AT_ADDRESS(int CChatWindowManager::InitContextMenu(CChatWindow*), CChatWindowManager__InitContextMenu);
#endif
#ifdef CChatWindowManager__GetLockedActiveChatWindow_x
FUNCTION_AT_ADDRESS(CChatWindow* CChatWindowManager::GetLockedActiveChatWindow(), CChatWindowManager__GetLockedActiveChatWindow);
#endif
#ifdef CChatWindowManager__SetLockedActiveChatWindow_x
FUNCTION_AT_ADDRESS(void CChatWindowManager::SetLockedActiveChatWindow(CChatWindow*), CChatWindowManager__SetLockedActiveChatWindow);
#endif
#ifdef CChatWindowManager__CreateChatWindow_x
FUNCTION_AT_ADDRESS(void CChatWindowManager::CreateChatWindow(CXWnd* pParentWnd, int ID, char* Name, int Language, int DefaultChannel,
	int ChatChannel, char* szTellTarget, int FontStyle, bool bScrollbar, bool bHighLight, COLORREF HighlightColor), CChatWindowManager__CreateChatWindow);
#endif

//============================================================================
// CChatWindow
//============================================================================

#ifdef CChatWindow__CChatWindow_x
CONSTRUCTOR_AT_ADDRESS(CChatWindow::CChatWindow(CXWnd*), CChatWindow__CChatWindow);
#endif
#ifdef CChatWindow__AddOutputText_x
FUNCTION_AT_ADDRESS(void CChatWindow::AddOutputText(PCXSTR, int), CChatWindow__AddOutputText);
#endif
#ifdef CChatWindow__HistoryBack_x
FUNCTION_AT_ADDRESS(void CChatWindow::HistoryBack(), CChatWindow__HistoryBack);
#endif
#ifdef CChatWindow__HistoryForward_x
FUNCTION_AT_ADDRESS(void CChatWindow::HistoryForward(), CChatWindow__HistoryForward);
#endif
#ifdef CChatWindow__AddHistory_x
// defined in ExceptionsDisabled.cpp
#endif
#ifdef CChatWindow__GetInputText_x
FUNCTION_AT_ADDRESS(CXStr CChatWindow::GetInputText(), CChatWindow__GetInputText);
#endif
#ifdef CChatWindow__PageUp_x
FUNCTION_AT_ADDRESS(void CChatWindow::PageUp(), CChatWindow__PageUp);
#endif
#ifdef CChatWindow__PageDown_x
FUNCTION_AT_ADDRESS(void CChatWindow::PageDown(), CChatWindow__PageDown);
#endif
#ifdef CChatWindow__SetChatFont_x
FUNCTION_AT_ADDRESS(void CChatWindow::SetChatFont(int), CChatWindow__SetChatFont);
#endif
#ifdef CChatWindow__Clear_x
FUNCTION_AT_ADDRESS(void CChatWindow::Clear(), CChatWindow__Clear);
#endif
#ifdef CChatWindow__GetInputWnd_x
FUNCTION_AT_ADDRESS(CEditWnd* CChatWindow::GetInputWnd(), CChatWindow__GetInputWnd);
#endif
#ifdef CChatWindow__WndNotification_x
FUNCTION_AT_ADDRESS(int CChatWindow::WndNotification(CXWnd*, uint32_t, void*), CChatWindow__WndNotification);
#endif


//============================================================================
// CSidlManagerBase
//============================================================================

#ifdef CSidlManagerBase__FindButtonDrawTemplate_x
FUNCTION_AT_ADDRESS(CButtonDrawTemplate* CSidlManagerBase::FindButtonDrawTemplate(uint32_t) const, CSidlManagerBase__FindButtonDrawTemplate);
#endif
#ifdef CSidlManagerBase__FindButtonDrawTemplate1_x
FUNCTION_AT_ADDRESS(CButtonDrawTemplate* CSidlManagerBase::FindButtonDrawTemplate(const CXStr& Name) const, CSidlManagerBase__FindButtonDrawTemplate1);
#endif
#ifdef CSidlManagerBase__FindAnimation1_x
FUNCTION_AT_ADDRESS(CTextureAnimation* CSidlManagerBase::FindAnimation(const CXStr&) const, CSidlManager__FindAnimation1);
#endif
#ifdef CSidlManagerBase__FindScreenPieceTemplate_x
FUNCTION_AT_ADDRESS(CScreenPieceTemplate* CSidlManagerBase::FindScreenPieceTemplate(uint32_t) const, CSidlManager__FindScreenPieceTemplate);
#endif
#ifdef CSidlManagerBase__FindScreenPieceTemplate1_x
FUNCTION_AT_ADDRESS(CScreenPieceTemplate* CSidlManagerBase::FindScreenPieceTemplate(const CXStr&) const, CSidlManager__FindScreenPieceTemplate1);
#endif
#ifdef CSidlManagerBase__CreateXWndFromTemplate_x
FUNCTION_AT_ADDRESS(CXWnd* CSidlManagerBase::CreateXWndFromTemplate(CXWnd*, CControlTemplate*, bool), CSidlManager__CreateXWndFromTemplate);
#endif
#ifdef CSidlManagerBase__CreateXWndFromTemplate1_x
FUNCTION_AT_ADDRESS(CXWnd* CSidlManagerBase::CreateXWndFromTemplate(CXWnd*, const CXStr&), CSidlManager__CreateXWndFromTemplate1);
#endif
#ifdef CSidlManagerBase__CreateXWnd_x
FUNCTION_AT_ADDRESS(CXWnd* CSidlManagerBase::CreateXWnd(CXWnd* pwndParent, CControlTemplate* pControl), CSidlManager__CreateXWnd);
#endif

CXMLParamManager* CSidlManagerBase::GetParamManager()
{
	return &XMLDataMgr;
}

//============================================================================
// CSidlManager
//============================================================================

#ifdef CSidlManager__CreateHotButtonWnd_x
FUNCTION_AT_ADDRESS(CXWnd* CSidlManager::CreateHotButtonWnd(CXWnd* pwndParent, CControlTemplate* pControl), CSidlManager__CreateHotButtonWnd);
#endif

//============================================================================

int CListWnd::AddString(const char* Str, COLORREF Color, uint64_t Data, const CTextureAnimation* pTa, const char* TooltipStr)
{
	return AddString(CXStr(Str), Color, Data, pTa, TooltipStr);
}

void CEditBaseWnd::SetMaxChars(int maxChars)
{
	MaxChars = maxChars;

	if (maxChars < (int)InputText.length())
	{
		SetWindowText(InputText);
	}
}

//----------------------------------------------------------------------------

void InitializeUI()
{
	CButtonWnd::sm_vftable = reinterpret_cast<CButtonWnd::VirtualFunctionTable*>(CButtonWnd__vftable);
	CListWnd::sm_vftable = reinterpret_cast<CListWnd::VirtualFunctionTable*>(CListWnd__vftable);
}

} // namespace eqlib

using namespace eqlib;
