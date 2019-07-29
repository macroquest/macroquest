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
// defined in AssemblyFunctions.asm
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

void CComboWnd::InsertChoice(char* str)
{
	InsertChoice(str, 0);
}

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
}

} // namespace eqlib

using namespace eqlib;
