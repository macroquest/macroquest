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

#include "pch.h"

#include "Globals.h"
#include "SidlTemplates.h"

namespace eqlib {

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
// CTAFrameDraw
//============================================================================

CTAFrameDraw::CTAFrameDraw(CXStr name)
	: m_name(name)
{
	for (int i = 0; i < FrameDraw_Max; ++i)
		m_pta[i] = nullptr;
}

CTextureAnimation* CTAFrameDraw::GetAnimation(EFrameDrawPiece piece) const
{
	return m_pta[piece];
}

void CTAFrameDraw::SetAnimation(EFrameDrawPiece which, CTextureAnimation* tex)
{
	m_pta[which] = tex;
}

void CTAFrameDraw::Set(CTextureAnimation* pta[FrameDraw_Max])
{
	for (int i = 0; i < FrameDraw_Max; ++i)
		m_pta[i] = pta[i];
}

int CTAFrameDraw::Draw(const CXRect& rect, const CXRect& clip) const
{
	for (int i = 0; i < FrameDraw_Max; ++i)
	{
		int result = Draw(rect, clip, (EFrameDrawPiece)i);

		if (result < 0)
			return result;
	}

	return 0;
}

int CTAFrameDraw::Draw(const CXRect& rect, const CXRect& clip, EFrameDrawPiece which) const
{
	if (which >= 0 && which < FrameDraw_Max)
	{
		CXRect pieceRect = GetPieceRect(rect, which);

		auto pta = m_pta[which];
		if (pta != nullptr)
		{
			return pta->Draw(rect, clip);
		}
	}

	return 0;
}

bool CTAFrameDraw::IsHorizontal() const
{
	return m_pta[FrameDraw_TopLeft] == nullptr
		&& m_pta[FrameDraw_Top] == nullptr
		&& m_pta[FrameDraw_TopRight] == nullptr
		&& m_pta[FrameDraw_BottomLeft] == nullptr
		&& m_pta[FrameDraw_Bottom] == nullptr
		&& m_pta[FrameDraw_BottomRight] == nullptr;
}

bool CTAFrameDraw::IsVertical() const
{
	return m_pta[FrameDraw_LeftTop] == nullptr
		&& m_pta[FrameDraw_Left] == nullptr
		&& m_pta[FrameDraw_LeftBottom] == nullptr
		&& m_pta[FrameDraw_RightTop] == nullptr
		&& m_pta[FrameDraw_Right] == nullptr
		&& m_pta[FrameDraw_RightBottom] == nullptr;
}

CXRect CTAFrameDraw::GetHitTestRect(const CXRect& rect, int which) const
{
	CXRect pieceRect = GetPieceRect(rect, which);

	switch (which)
	{
	case FrameDraw_TopLeft:
	case FrameDraw_Top:
	case FrameDraw_TopRight:
		pieceRect.bottom -= m_nOverlapTop;
		break;

	case FrameDraw_RightTop:
	case FrameDraw_Right:
	case FrameDraw_RightBottom:
		pieceRect.left += m_nOverlapRight;
		break;

	case FrameDraw_BottomRight:
	case FrameDraw_Bottom:
	case FrameDraw_BottomLeft:
		pieceRect.top += m_nOverlapBottom;
		break;

	case FrameDraw_LeftTop:
	case FrameDraw_Left:
	case FrameDraw_LeftBottom:
		pieceRect.right -= m_nOverlapLeft;
		break;

	case FrameDraw_Middle:
		pieceRect.right -= m_nOverlapLeft;
		pieceRect.bottom -= m_nOverlapTop;
		pieceRect.left += m_nOverlapRight;
		pieceRect.top += m_nOverlapBottom;
		break;
	}

	return pieceRect;
}

CXRect CTAFrameDraw::GetInnerRect(const CXRect& rectIn) const
{
	int top = 0;
	CXRect rect = rectIn;

	if (m_pta[FrameDraw_TopLeft] != nullptr)
	{
		top = std::max(top, m_pta[FrameDraw_TopLeft]->GetHeight());
	}

	if (m_pta[FrameDraw_TopLeft] != nullptr)
	{
		top = std::max(top, m_pta[FrameDraw_TopRight]->GetHeight());
	}

	if (m_pta[FrameDraw_TopLeft] != nullptr)
	{
		top = std::max(top, m_pta[FrameDraw_Top]->GetHeight());
	}

	int left = 0;

	if (m_pta[FrameDraw_LeftTop] != nullptr)
	{
		left = std::max(left, m_pta[FrameDraw_LeftTop]->GetWidth());
	}

	if (m_pta[FrameDraw_Left] != nullptr)
	{
		left = std::max(left, m_pta[FrameDraw_Left]->GetWidth());
	}

	if (m_pta[FrameDraw_LeftBottom] != nullptr)
	{
		left = std::max(left, m_pta[FrameDraw_LeftBottom]->GetWidth());
	}

	int right = 0;

	if (m_pta[FrameDraw_RightTop] != nullptr)
	{
		right = std::max(right, m_pta[FrameDraw_RightTop]->GetWidth());
	}

	if (m_pta[FrameDraw_Right] != nullptr)
	{
		right = std::max(right, m_pta[FrameDraw_Right]->GetWidth());
	}

	if (m_pta[FrameDraw_RightBottom] != nullptr)
	{
		right = std::max(right, m_pta[FrameDraw_RightBottom]->GetWidth());
	}

	int bottom = 0;

	if (m_pta[FrameDraw_BottomRight] != nullptr)
	{
		bottom = std::max(bottom, m_pta[FrameDraw_BottomRight]->GetHeight());
	}

	if (m_pta[FrameDraw_Bottom] != nullptr)
	{
		bottom = std::max(bottom, m_pta[FrameDraw_Bottom]->GetHeight());
	}

	if (m_pta[FrameDraw_BottomLeft] != nullptr)
	{
		bottom = std::max(bottom, m_pta[FrameDraw_BottomLeft]->GetHeight());
	}

	rect.left = rect.left + (left - m_nOverlapLeft);
	rect.top = rect.top + (top - m_nOverlapTop);
	rect.right = rect.right - (right - m_nOverlapRight);
	rect.bottom = rect.bottom - (bottom - m_nOverlapBottom);

	return rect;
}

CXRect CTAFrameDraw::GetPieceRect(const CXRect& rect, int which) const
{
	if (which == FrameDraw_Middle)
	{
		return GetInnerRect(rect);
	}

	CTextureAnimation* pta = m_pta[which];
	CXRect pieceRect = rect;

	switch (which)
	{
	case FrameDraw_TopLeft:
		if (pta != nullptr)
		{
			pieceRect = CXRect{ rect.TopLeft(), pta->GetSize() };
		}
		else
		{
			pieceRect.right = pieceRect.left;
			pieceRect.bottom = pieceRect.top;
		}
		return pieceRect;

	case FrameDraw_TopRight:
		if (pta != nullptr)
		{
			pieceRect.left = pieceRect.right - pta->GetWidth();
			pieceRect.bottom = pieceRect.top + pta->GetHeight();
		}
		else
		{
			pieceRect.left = pieceRect.right;
			pieceRect.bottom = pieceRect.top;
		}
		return pieceRect;

	case FrameDraw_RightTop:
		if (pta != nullptr)
		{
			pieceRect.left = rect.right - pta->GetWidth();
			auto topRight = m_pta[FrameDraw_TopRight];
			if (topRight != nullptr)
				pieceRect.top = rect.top + topRight->GetHeight();
			pieceRect.bottom = pieceRect.top + pta->GetHeight();
		}
		else
		{
			pieceRect.right = pieceRect.left;
			pieceRect.bottom = pieceRect.top;
		}
		return pieceRect;

	case FrameDraw_RightBottom:
		if (pta != nullptr)
		{
			pieceRect.left = rect.right - pta->GetWidth();
			auto bottomRight = m_pta[FrameDraw_BottomRight];
			if (bottomRight != nullptr)
				pieceRect.top = pieceRect.bottom - bottomRight->GetHeight() - pta->GetHeight();
			else
				pieceRect.top = pieceRect.bottom - pta->GetHeight();
		}
		else
		{
			pieceRect.left = pieceRect.right;
			pieceRect.top = pieceRect.bottom;
		}
		return pieceRect;

	case FrameDraw_BottomRight:
		if (pta != nullptr)
		{
			pieceRect.left = rect.right - pta->GetWidth();
			pieceRect.top = pieceRect.bottom - pta->GetHeight();
		}
		else
		{
			pieceRect.left = pieceRect.right;
			pieceRect.top = pieceRect.bottom;
		}
		return pieceRect;

	case FrameDraw_BottomLeft:
		if (pta != nullptr)
		{
			pieceRect.right = pieceRect.left + pta->GetWidth();
			pieceRect.top = pieceRect.bottom - pta->GetHeight();
		}
		else
		{
			pieceRect.right = pieceRect.left;
			pieceRect.top = pieceRect.bottom;
		}
		return pieceRect;

	case FrameDraw_LeftTop:
		if (pta != nullptr)
		{
			pieceRect.right = pieceRect.left + pta->GetWidth();
			auto topLeft = m_pta[FrameDraw_TopLeft];
			if (topLeft != nullptr)
				pieceRect.top = rect.top + topLeft->GetHeight();
			pieceRect.bottom = pieceRect.top + pta->GetHeight();
		}
		else
		{
			pieceRect.right = pieceRect.left;
			pieceRect.bottom = pieceRect.top;
		}
		return pieceRect;

	case FrameDraw_LeftBottom:
		if (pta != nullptr)
		{
			pieceRect.right = pieceRect.left + pta->GetWidth();
			auto bottomLeft = m_pta[FrameDraw_BottomLeft];
			if (bottomLeft)
				pieceRect.top = pieceRect.bottom - bottomLeft->GetHeight() - pta->GetHeight();
			else
				pieceRect.top = pieceRect.bottom - pta->GetHeight();
			pieceRect.bottom = pieceRect.top + pta->GetHeight();
		}
		else
		{
			pieceRect.right = pieceRect.left;
			pieceRect.top = pieceRect.bottom;
		}
		return pieceRect;

	case FrameDraw_Top:
		pieceRect = CXRect{
			GetPieceRect(rect, FrameDraw_TopLeft).TopRight(),
			GetPieceRect(rect, FrameDraw_TopRight).TopLeft() };
		if (pta != nullptr)
			pieceRect.bottom = rect.top + pta->GetHeight();
		return pieceRect;

	case FrameDraw_Right:
		pieceRect = CXRect{
			GetPieceRect(rect, FrameDraw_RightTop).BottomLeft(),
			GetPieceRect(rect, FrameDraw_RightBottom).TopRight() };
		if (pieceRect.top > pieceRect.bottom)
			return {};
		if (pta != nullptr)
			pieceRect.left = rect.right - pta->GetWidth();
		return pieceRect;

	case FrameDraw_Bottom:
		pieceRect = CXRect{
			GetPieceRect(rect, FrameDraw_BottomLeft).BottomRight(),
			GetPieceRect(rect, FrameDraw_BottomRight).BottomLeft() };
		if (pta)
			pieceRect.top = rect.bottom - pta->GetHeight();
		return pieceRect;

	case FrameDraw_Left:
		pieceRect = CXRect{
			GetPieceRect(rect, FrameDraw_LeftTop).BottomLeft(),
			GetPieceRect(rect, FrameDraw_LeftBottom).TopRight() };
		if (pieceRect.top > pieceRect.bottom)
			return {};
		if (pta != nullptr)
			pieceRect.right = rect.left + pta->GetWidth();
		return pieceRect;
	}

	return {};
}

CXSize CTAFrameDraw::GetFrameSize() const
{
	CXRect inner = GetInnerRect({ 0, 0, 100, 100 });

	return { 100 - inner.GetWidth(), 100 - inner.GetHeight() };
}

int CTAFrameDraw::GetExtent() const
{
	int extent = 0;

	if (IsVertical())
	{
		for (int i = 0; i < FrameDraw_Max; ++i)
		{
			if (m_pta[i] != nullptr)
				extent = std::max(extent, m_pta[i]->GetWidth());
		}
	}
	else if (IsHorizontal())
	{
		for (int i = 0; i < FrameDraw_Max; ++i)
		{
			if (m_pta[i] != nullptr)
				extent = std::max(extent, m_pta[i]->GetHeight());
		}
	}

	return extent;
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

CTextureAnimation* CButtonDrawTemplate::GetAnimation(bool pressed, bool hover, bool disabled, bool decal /*= false*/) const
{
	if (decal)
	{
		if (disabled)
		{
			if (pressed && ptaPressedDisabledDecal != nullptr)
			{
				return ptaPressedDisabledDecal;
			}

			if (ptaDisabledDecal != nullptr)
			{
				return ptaDisabledDecal;
			}

			return ptaNormalDecal;
		}

		if (pressed)
		{
			if (hover && ptaPressedFlybyDecal != nullptr)
			{
				return ptaPressedFlybyDecal;
			}

			if (ptaPressedDecal != nullptr)
			{
				return ptaPressedDecal;
			}

			return ptaNormalDecal;
		}

		if (hover)
		{
			if (ptaFlybyDecal != nullptr)
			{
				return ptaFlybyDecal;
			}

			return ptaNormalDecal;
		}
	}
	else // not a decal
	{
		if (disabled)
		{
			if (pressed && ptaPressedDisabled != nullptr)
			{
				return ptaPressedDisabled;
			}

			if (ptaDisabled != nullptr)
			{
				return ptaDisabled;
			}

			return ptaNormal;
		}

		if (pressed)
		{
			if (hover && ptaPressedFlyby != nullptr)
			{
				return ptaPressedFlyby;
			}

			if (ptaPressed != nullptr)
			{
				return ptaPressed;
			}

			return ptaNormal;
		}

		if (hover)
		{
			if (ptaFlyby != nullptr)
			{
				return ptaFlyby;
			}

			return ptaNormal;
		}
	}

	return ptaNormal;
}

CXSize CButtonDrawTemplate::GetSize() const
{
	if (ptaNormal != nullptr)
	{
		return ptaNormal->GetSize();
	}

	return { 0, 0 };
}

//============================================================================
// CScreenPieceTemplate
//============================================================================

void CScreenPieceTemplate::DeclareType(uint32_t type)
{
	arRuntimeTypes.Add(type);
}

bool CScreenPieceTemplate::IsType(uint32_t type) const
{
	for (int i = 0; i < arRuntimeTypes.GetLength(); ++i)
	{
		if (arRuntimeTypes[i] == type)
			return true;
	}

	return false;
}
//============================================================================

} // namespace eqlib
