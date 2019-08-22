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

#pragma once

#include "Common.h"
#include "Containers.h"
#include "CXStr.h"

// For the most part, these follow the structure of the CParams, only some objects
// are resolved.

using D3DCOLOR = DWORD;

namespace eqlib {

//============================================================================
// Forward Declarations
//============================================================================

class CTextureAnimation;


//============================================================================
// CUITexturePiece
//============================================================================

enum enDir
{
	cUIDirectory,
	cUIDirectoryAtlas,
	cUIDirectoryTexture,
	cUIDirectoryMaps,

	cUIDirectoryCount,
};

struct [[offsetcomments]] CUITextureInfo
{
public:
	EQLIB_OBJECT CUITextureInfo();
	EQLIB_OBJECT CUITextureInfo(const CXStr& name, int size);
	EQLIB_OBJECT CUITextureInfo(const CXStr& name, const CXSize& size);
	EQLIB_OBJECT CUITextureInfo(uint32_t id, int size);
	EQLIB_OBJECT CUITextureInfo(uint32_t id, const CXSize& size);

	//EQLIB_OBJECT int Draw(const CXRect&, const CXRect&, const CXRect&, D3DCOLOR*, D3DCOLOR*) const;
	//EQLIB_OBJECT int Draw(const CXRect&, const CXRect&, const CXRect&, D3DCOLOR, D3DCOLOR) const;
	//EQLIB_OBJECT int Preload();
	//EQLIB_OBJECT int Tile(const CXRect&, D3DCOLOR*, D3DCOLOR*) const;
	//EQLIB_OBJECT int Tile(const CXRect&, D3DCOLOR, D3DCOLOR) const;

	//----------------------------------------------------------------------------
	// data members
/*0x00*/ bool          bValid = false;
/*0x04*/ enDir         Directory = cUIDirectory;
/*0x08*/ CXStr         Name;
/*0x0c*/ CXSize        TextureSize;
/*0x14*/ uint32_t      TextureId = -1;
/*0x18*/
};

class [[offsetcomments]] CUITexturePiece
{
public:
	EQLIB_OBJECT CUITexturePiece();
	EQLIB_OBJECT CUITexturePiece(const CUITextureInfo&, const CXRect&);
	EQLIB_OBJECT CUITexturePiece(const CUITextureInfo&);

	//EQLIB_OBJECT int Draw(const CXRect&, const CXRect&, const CXRect&, D3DCOLOR, D3DCOLOR) const;
	//EQLIB_OBJECT int Draw(const CXRect&, const CXRect&, D3DCOLOR, D3DCOLOR) const;

	const CUITextureInfo& GetTextureInfo() const { return m_info; }
	CXSize GetSize() const { return m_rect.GetSize(); }
	const CXRect& GetRect() const { return m_rect; }

private:
/*0x00*/ CUITextureInfo      m_info;
/*0x18*/ CXRect              m_rect;
/*0x28*/
};


//============================================================================
// CTextureAnimation
//============================================================================

struct [[offsetcomments]] STextureAnimationFrame
{
/*0x00*/ CUITexturePiece    Piece;
/*0x28*/ uint32_t           Ticks = 0;
/*0x2c*/ CXPoint            Hotspot;
/*0x34*/
};

class [[offsetcomments]] CTextureAnimation
{
public:
	EQLIB_OBJECT CTextureAnimation();
	EQLIB_OBJECT CTextureAnimation(const CXStr& name);
	EQLIB_OBJECT CTextureAnimation(CUITexturePiece tp);
	EQLIB_OBJECT virtual ~CTextureAnimation();

	EQLIB_OBJECT int AddFrame(const CUITextureInfo* ti, const CXRect& rect, uint32_t ticks, CXPoint hotspot = {});
	EQLIB_OBJECT int AddFrame(CUITexturePiece tp, uint32_t ticks, CXPoint hotspot = {});
	EQLIB_OBJECT int AddBlankFrame(uint32_t ticks, CXPoint hotspot = {});
	EQLIB_OBJECT void SetCurFrame(int);
	EQLIB_OBJECT int GetCurFrame() const;
	EQLIB_OBJECT void Pause(bool pause);
	EQLIB_OBJECT CXPoint GetHotspot() const;
	EQLIB_OBJECT const CXStr& GetName() const { return Name; }
	EQLIB_OBJECT void SetCurCell(int);
	EQLIB_OBJECT CXSize GetSize() const { return Size; }
	inline int GetWidth() const { return Size.cx; }
	inline int GetHeight() const { return Size.cy; }

	// todo
	EQLIB_OBJECT int Draw(const CXRect& rect, const CXRect& clip, uint32_t color = 0xffffffff, uint32_t color2 = 0xff000000) { return 0; }
	//EQLIB_OBJECT int Draw(const CXPoint&, const CXRect&, unsigned long, unsigned long) const;
	//EQLIB_OBJECT int Draw(const CXRect&, const CXRect&, unsigned long, unsigned long) const;
	//EQLIB_OBJECT int Preload();
	//EQLIB_OBJECT void Reset();

	//----------------------------------------------------------------------------
	// data members
/*0x04*/ CXStr         Name;
/*0x08*/ ArrayClass<STextureAnimationFrame> Frames;
/*0x18*/ uint32_t           TotalTicks = 0;
/*0x1c*/ int                ZeroFrame = 0;
/*0x20*/ uint32_t           StartTicks = GetTickCount();
/*0x24*/ CXSize             Size;
/*0x2c*/ bool               bPaused = false;
/*0x2d*/ bool               bCycle = true;
/*0x2e*/ bool               bGrid = false;
/*0x2f*/ bool               bVertical = false;
/*0x30*/ int                CellWidth = 0;
/*0x34*/ int                CellHeight = 0;
/*0x38*/ int                CurCell = -1;
/*0x3c*/ CXRect             CellRect;
/*0x4c*/
};

//============================================================================
// CTAFrameDraw
//============================================================================

class [[offsetcomments]] CTAFrameDraw
{
public:
	EQLIB_OBJECT CTAFrameDraw(CXStr = {});

	enum EFrameDrawPiece
	{
		FrameDraw_TopLeft = 0,
		FrameDraw_Top,
		FrameDraw_TopRight,
		FrameDraw_RightTop,
		FrameDraw_Right,
		FrameDraw_RightBottom,
		FrameDraw_BottomRight,
		FrameDraw_Bottom,
		FrameDraw_BottomLeft,
		FrameDraw_LeftTop,
		FrameDraw_Left,
		FrameDraw_LeftBottom,
		FrameDraw_Middle,

		FrameDraw_Max,
	};

	EQLIB_OBJECT CTextureAnimation* GetAnimation(EFrameDrawPiece) const;
	EQLIB_OBJECT void SetAnimation(EFrameDrawPiece which, CTextureAnimation* tex);

	EQLIB_OBJECT CXRect GetHitTestRect(const CXRect&, int) const;
	EQLIB_OBJECT CXRect GetInnerRect(const CXRect&) const;
	EQLIB_OBJECT CXRect GetPieceRect(const CXRect&, int) const;
	EQLIB_OBJECT CXSize GetFrameSize() const;

	EQLIB_OBJECT CXStr GetName() const { return m_name; }
	EQLIB_OBJECT void SetName(const CXStr& name) { m_name = name; }

	EQLIB_OBJECT bool IsHorizontal() const;
	EQLIB_OBJECT bool IsVertical() const;

	EQLIB_OBJECT int Draw(const CXRect&, const CXRect&) const;
	EQLIB_OBJECT int Draw(const CXRect&, const CXRect&, EFrameDrawPiece) const;

	EQLIB_OBJECT int GetExtent() const;
	EQLIB_OBJECT int GetMinLength() const;

	EQLIB_OBJECT void Set(CTextureAnimation* pta[FrameDraw_Max]);

	//----------------------------------------------------------------------------
	// data members
private:
/*0x00*/ CXStr              m_name;
/*0x04*/ CTextureAnimation* m_pta[FrameDraw_Max];
/*0x38*/ int                Unknown0x38 = -1;
/*0x3c*/ int                m_nOverlapTop = 0;
/*0x40*/ int                m_nOverlapLeft = 0;
/*0x44*/ int                m_nOverlapBottom = 0;
/*0x48*/ int                m_nOverlapRight = 0;
/*0x4c*/
};

//============================================================================
// CButtonDrawTemplate
//============================================================================

class [[offsetcomments]] CButtonDrawTemplate
{
public:
	// Returns the appropriate texture to use for the button given the specified properties
	EQLIB_OBJECT CTextureAnimation* GetAnimation(bool pressed, bool hover, bool disabled, bool decal = false) const;
	EQLIB_OBJECT CXSize GetSize() const;

/*0x00*/ CXStr                    strName;
/*0x04*/ CTextureAnimation*       ptaNormal = nullptr;
/*0x08*/ CTextureAnimation*       ptaPressed = nullptr;
/*0x0c*/ CTextureAnimation*       ptaFlyby = nullptr;
/*0x10*/ CTextureAnimation*       ptaDisabled = nullptr;
/*0x14*/ CTextureAnimation*       ptaPressedFlyby = nullptr;
/*0x18*/ CTextureAnimation*       ptaPressedDisabled = nullptr;
/*0x1c*/ CTextureAnimation*       ptaNormalDecal = nullptr;
/*0x20*/ CTextureAnimation*       ptaPressedDecal = nullptr;
/*0x24*/ CTextureAnimation*       ptaFlybyDecal = nullptr;
/*0x28*/ CTextureAnimation*       ptaDisabledDecal = nullptr;
/*0x2c*/ CTextureAnimation*       ptaPressedFlybyDecal = nullptr;
/*0x30*/ CTextureAnimation*       ptaPressedDisabledDecal = nullptr;
/*0x34*/
};

//============================================================================
// CGaugeDrawTemplate
//============================================================================

class CGaugeDrawTemplate
{
public:
	CXStr                    strName;

	CTextureAnimation*       ptaBackground = nullptr;
	CTextureAnimation*       ptaFill = nullptr;
	CTextureAnimation*       ptaLines = nullptr;
	CTextureAnimation*       ptaLinesFill = nullptr;
	CTextureAnimation*       ptaEndCapLeft = nullptr;
	CTextureAnimation*       ptaEndCapRight = nullptr;
};

//============================================================================
// CGaugeDrawTemplate
//============================================================================

class CSpellGemDrawTemplate
{
public:
	CXStr                    strName;

	CTextureAnimation*       ptaBackground = nullptr;
	CTextureAnimation*       ptaHolder = nullptr;
	CTextureAnimation*       ptaHighlight = nullptr;
};


//============================================================================
// CSliderDrawTemplate
//============================================================================

class CSliderDrawTemplate
{
public:
	CXStr                    strName;

	CButtonDrawTemplate      bdtThumb;
	CTextureAnimation*       ptaBackground = nullptr;
	CTextureAnimation*       ptaEndCapRight = nullptr;
	CTextureAnimation*       ptaEndCapLeft = nullptr;
};

//============================================================================
// CScrollbarTemplate
//============================================================================

// not ScrollbarDrawTemplate ??
class CScrollbarTemplate
{
public:
	CXStr                       strName;

	CButtonDrawTemplate         bdtUp;
	CButtonDrawTemplate         bdtDown;
	CTAFrameDraw                frameThumb;
	CUITextureInfo              tiMiddle;
	D3DCOLOR                    colorMiddleTint = 0;
};

//============================================================================
// CXWndDrawTemplate
//============================================================================

class CXWndDrawTemplate
{
public:
	CXStr                       strName;

	CUITextureInfo              tiBackground;
	int                         nBackgroundDrawType = 0;
	CScrollbarTemplate          sbtVScroll;
	CScrollbarTemplate          sbtHScroll;
	CButtonDrawTemplate         bdtCloseBox;
	CButtonDrawTemplate         bdtQMarkBox;
	CButtonDrawTemplate         bdtMinimizeBox;
	CButtonDrawTemplate         bdtMaximizeBox;
	CButtonDrawTemplate         bdtTileBox;
	CTAFrameDraw                frameBorder;
	CTAFrameDraw                frameTitlebar;
};

//============================================================================
// CScreenPieceTemplate
//============================================================================

class [[offsetcomments]] CScreenPieceTemplate
{
public:
	EQLIB_OBJECT CScreenPieceTemplate(CScreenPieceTemplate*);
	EQLIB_OBJECT CScreenPieceTemplate(CParamScreenPiece*);
	EQLIB_OBJECT virtual ~CScreenPieceTemplate() {}

	EQLIB_OBJECT void DeclareType(uint32_t type);
	EQLIB_OBJECT bool IsType(uint32_t type) const;

/*0x04*/ ArrayClass2<uint32_t> arRuntimeTypes;
/*0x1c*/ CXStr               strName;
/*0x20*/ uint32_t            uParamObjectId = 0;
/*0x24*/ CXStr               strScreenId;
/*0x28*/ uint32_t            nFont = 0;
/*0x2c*/ bool                bRelativePosition = true;
/*0x2d*/ bool                bAutoStretchVertical = false;
/*0x2e*/ bool                bAutoStretchHorizontal = false;
/*0x2f*/ bool                bTopAnchorToTop = true;
/*0x30*/ bool                bBottomAnchorToTop = true;
/*0x31*/ bool                bLeftAnchorToLeft = true;
/*0x32*/ bool                bRightAnchorToLeft = true;
/*0x34*/ int                 nTopOffset = 0;
/*0x38*/ int                 nBottomOffset = 0;
/*0x3c*/ int                 nLeftOffset = 0;
/*0x40*/ int                 nRightOffset = 0;
/*0x44*/ int                 nMinVSize = 0;
/*0x48*/ int                 nMinHSize = 0;
/*0x4c*/ int                 nMaxVSize = 0;
/*0x50*/ int                 nMaxHSize = 0;
/*0x54*/ CXRect              rect;
/*0x64*/ CXStr               strText;
/*0x68*/ D3DCOLOR            colorText = 0;
/*0x6c*/ D3DCOLOR            colorDisabled = 0;
/*0x70*/ D3DCOLOR            colorEnabled = 0;
/*0x74*/ bool                bUseInLayoutHorizontal = true;
/*0x75*/ bool                bUseInLayoutVertical = true;
/*0x78*/ D3DCOLOR            colorBackgroundTextureTint = 0;
/*0x7c*/ D3DCOLOR            colorDisabledBackgroundTextureTint = 0;
/*0x80*/
};

//============================================================================
// CStaticScreenPieceTemplate
//============================================================================

class [[offsetcomments]] CStaticScreenPieceTemplate : public CScreenPieceTemplate
{
public:
	EQLIB_OBJECT CStaticScreenPieceTemplate(CStaticScreenPieceTemplate*);
	EQLIB_OBJECT CStaticScreenPieceTemplate(CParamStaticScreenPiece*);

	bool                     bAutoDraw = true;
};

//============================================================================
// CLayoutStrategyTemplate
//============================================================================

class CParamLayoutStrategy;

class [[offsetcomments]] CLayoutStrategyTemplate
{
public:
	EQLIB_OBJECT CLayoutStrategyTemplate(CParamLayoutStrategy*, uint32_t type);
	virtual ~CLayoutStrategyTemplate() {}

/*0x04*/ int                      nPadding = 0;
/*0x08*/ uint32_t                 nType = 0;
/*0x0c*/ CXStr                    strName;
/*0x10*/ bool                     bResizeHorizontal = false;
/*0x11*/ bool                     bResizeVertical = false;
/*0x14*/
};

//============================================================================
// CControlTemplate
//============================================================================

class [[offsetcomments]] CControlTemplate : public CScreenPieceTemplate
{
public:
	EQLIB_OBJECT CControlTemplate(CParamControl*);

/*0x80*/ uint32_t                 uStyleBits = 0;
/*0x84*/ uint8_t                  bSizableMask = 0;
/*0x85*/ bool                     bEscapable = true;
/*0x88*/ CXStr                    strTooltip;
/*0x8c*/ CXWndDrawTemplate*       pDrawTemplate = nullptr;
/*0x90*/ CXStr                    strController;
/*0x94*/ CLayoutStrategyTemplate* pLayoutStrategyTemplate = nullptr;
/*0x98*/
};

//============================================================================
// CButtonTemplate
//============================================================================

class [[offsetcomments]] CButtonTemplate : public CControlTemplate
{
public:
	EQLIB_OBJECT CButtonTemplate(CParamButton*);

	bool                     bCheckbox = false;
	CXStr                    strRadioGroup;
	CXStr                    strText;
	bool                     bTextAlignCenter = true;
	bool                     bTextAlignRight = false;
	bool                     bTextAlignVCenter = true;
	CButtonDrawTemplate      bdt;
	CXStr                    strSoundPressed;
	CXStr                    strSoundUp;
	CXStr                    strSoundFlyby;
	CXPoint                  ptDecalOffset;
	CXSize                   sizeDecalSize;
};

//============================================================================
// CComboboxTemplate
//============================================================================

class CComboboxTemplate
{
public:
	EQLIB_OBJECT CComboboxTemplate(CParamCombobox*);
};

class CEditboxTemplate
{
public:
	EQLIB_OBJECT CEditboxTemplate(class CParamEditbox*);
};

class CGaugeTemplate
{
public:
	EQLIB_OBJECT CGaugeTemplate(CParamGauge*);
};

class CInvSlotTemplate
{
public:
	EQLIB_OBJECT CInvSlotTemplate(CParamInvSlot*);
};

class CLabelTemplate : public CControlTemplate
{
public:
	EQLIB_OBJECT CLabelTemplate(CParamLabel*);
};

class CListboxColumnTemplate
{
public:
	EQLIB_OBJECT CListboxColumnTemplate(CParamListboxColumn*);
};

class CListboxTemplate
{
public:
	EQLIB_OBJECT CListboxTemplate(CParamListbox*);
};

class CPageTemplate
{
public:
	EQLIB_OBJECT CPageTemplate(CParamPage*);
};

class CScreenTemplate
{
public:
	EQLIB_OBJECT CScreenTemplate(CParamScreen*);
};

class CSliderTemplate
{
public:
	EQLIB_OBJECT CSliderTemplate(CParamSlider*);
};

class CSpellGemTemplate
{
public:
	EQLIB_OBJECT CSpellGemTemplate(CParamSpellGem*);
};

class CStaticAnimationTemplate
{
public:
	EQLIB_OBJECT CStaticAnimationTemplate(CParamStaticAnimation*);
};

class CStaticFrameTemplate
{
public:
	EQLIB_OBJECT CStaticFrameTemplate(CParamStaticFrame*);
};

class CStaticHeaderTemplate
{
public:
	EQLIB_OBJECT CStaticHeaderTemplate(CParamStaticHeader*);
};

class CStaticTextTemplate
{
public:
	EQLIB_OBJECT CStaticTextTemplate(CParamStaticText*);

	EQLIB_OBJECT const CXStr& SetText(const CXStr&);
};

class CSTMLboxTemplate
{
public:
	EQLIB_OBJECT CSTMLboxTemplate(CParamSTMLbox*);
};

class CTabBoxTemplate
{
public:
	EQLIB_OBJECT CTabBoxTemplate(CParamTabBox*);
};

} // namespace eqlib

using namespace eqlib;
