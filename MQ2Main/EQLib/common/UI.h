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
#include "CXStr.h"
#include "CXWnd.h"
#include "Containers.h"

namespace eqlib {

//----------------------------------------------------------------------------
// Forward Declarations

class CAtlas;
class CButtonWnd;
class CChatContainerWindow;
class CChatWindow;
class CContextMenu;
class CEditWnd;
class CParamLayoutStrategy;
class CLabel;
class CLayoutStrategyTemplate;
class CStmlWnd;

using D3DCOLOR = DWORD;

//----------------------------------------------------------------------------

class WndEventHandler
{
public:
	unsigned int lastUpdate;

};

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

struct CUITextureInfo
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

class CUITexturePiece
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

struct STextureAnimationFrame
{
/*0x00*/ CUITexturePiece    Piece;
/*0x28*/ uint32_t           Ticks = 0;
/*0x2c*/ CXPoint            Hotspot;
/*0x34*/
};

class CTextureAnimation
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
// CEQSuiteTextureLoader
//============================================================================

enum eBitmapType
{
	eBitmapTypeNormal,
	eBitmapTypeLayer,
	eBitmapType_SingleDetail,
	eBitmapTypePaletteDetailMain,
	eBitmapTypePaletteDetailPalette,
	eBitmapTypePaletteDetailDetail
};

// have to fake these i dont wanna map them now... we dont need them anyway : public CThreadLoader, public TListNode<CEQGBitmap>
class CEQGBitmap
{
public:
	void* vftable;
	BYTE               Header[0x1c];
	eBitmapType        eType;
	int                eMemoryPoolManagerType;   // eMemoryPoolManagerType need to figure out this enum
	char* FileName;
	UINT               SourceWidth;
	UINT               SourceHeight;
	float              DetailScale;
	UINT               GrassDensity;
	UINT               Width;
	UINT               Height;
	bool               bHasTexture;
	union
	{
		void* pD3DTexture;              // IDirect3DBaseTexture9
		void* pRawBitmap;
	};
	UINT               ObjectIndex;
	UINT               Size;
	bool               bForceMipMap;
	int	               TrackingType;
	float              SQDistanceToCamera;
	UINT               LastDistanceTime;
	UINT               LastRenderTime;
	UINT               LoadedTime;
};

struct BMI
{
	char*              Name;
	unsigned int       Flags;
	CEQGBitmap*        pBmp;
};

struct _SuiteTexture
{
	bool               bUsed;
	CXStr              Name;
	enDir              Directory;
	BMI*               pBMInfo;
};

struct SWadFile;

class CEQSuiteTextureLoader
{
public:
	SWadFile*         pWadFile;
	ArrayClass<_SuiteTexture> Textures;
	CXStr              UIPath[cUIDirectoryCount];
	CXStr              DefaultUIPath[cUIDirectoryCount];

	EQLIB_OBJECT CEQSuiteTextureLoader();
	EQLIB_OBJECT ~CEQSuiteTextureLoader();
	EQLIB_OBJECT BMI* GetTexture(const CUITextureInfo& ti);
	EQLIB_OBJECT unsigned int CreateTexture(const CUITextureInfo&);
	EQLIB_OBJECT void UnloadAllTextures();
	EQLIB_OBJECT const CXStr& GetDefaultUIPath(int DirType) const;
};


//============================================================================
// CButtonDrawTemplate
//============================================================================

class CButtonDrawTemplate
{
public:
	EQLIB_OBJECT CButtonDrawTemplate();
	EQLIB_OBJECT ~CButtonDrawTemplate();

	// Returns the appropriate texture to use for the button given the specified properties
	EQLIB_OBJECT CTextureAnimation* GetAnimation(bool pressed, bool hover, bool disabled, bool decal = false) const;
	EQLIB_OBJECT CXSize GetSize() const;

	//----------------------------------------------------------------------------
	// data members
	CXStr              Name;
	CTextureAnimation* Normal = nullptr;
	CTextureAnimation* Pressed = nullptr;
	CTextureAnimation* Flyby = nullptr;
	CTextureAnimation* Disabled = nullptr;
	CTextureAnimation* PressedFlyby = nullptr;
	CTextureAnimation* PressedDisabled = nullptr;
	CTextureAnimation* NormalDecal = nullptr;
	CTextureAnimation* PressedDecal = nullptr;
	CTextureAnimation* FlybyDecal = nullptr;
	CTextureAnimation* DisabledDecal = nullptr;
	CTextureAnimation* PressedFlybyDecal = nullptr;
	CTextureAnimation* PressedDisabledDecal = nullptr;
};

//============================================================================
// CRadioGroup
//============================================================================

class CRadioGroup
{
public:
	EQLIB_OBJECT CRadioGroup(CXStr name = {});
	EQLIB_OBJECT virtual ~CRadioGroup();

	CXStr                    Name;
	ArrayClass<CButtonWnd*>  Buttons;
	int                      CurSel = -1;
	bool                     bAllowMultiSelect = false;
	int                      nSelectionLimit = -1;
	bool                     bAllowNullable = false;
};

//============================================================================
// CButtonWnd
//============================================================================

// CButtonWnd__CButtonWnd_x
// size is 0x290 see 8E0709 in eqgame.exe dated Oct 13 2017 Test
class CButtonWnd : public CXWnd
{
public:
	//----------------------------------------------------------------------------
	// constructor / destructor
	EQLIB_OBJECT CButtonWnd(CXWnd* parent, uint32_t id, const CXRect& rect,
		const CXPoint& decalOffset, const CXSize& decalSize,
		CTextureAnimation* normal, CTextureAnimation* pressed,
		CTextureAnimation* hover, CTextureAnimation* disabled,
		CTextureAnimation* pressedHover, CTextureAnimation* pressedDisabled,
		CTextureAnimation* normalDecal, CTextureAnimation* pressedDecal,
		CTextureAnimation* hoverDecal, CTextureAnimation* pressedDisabledDecal);
	//EQLIB_OBJECT CButtonWnd(CXWnd* parent, uint32_t id, const CXRect& rect);
	//EQLIB_OBJECT CBUttonWnd(CXWnd* parent, uint32_t id, const CXRect& rect, const CXStr& label);
	EQLIB_OBJECT virtual ~CButtonWnd();

	//----------------------------------------------------------------------------
	// virtual functions
	EQLIB_OBJECT virtual void SetRadioGroup(CRadioGroup* group);
	EQLIB_OBJECT virtual int DrawWndText(const CXRect& rect, const CXRect& clip);
	EQLIB_OBJECT virtual int DrawCooldown();
	EQLIB_OBJECT virtual void SetCheck(bool check);
	EQLIB_OBJECT virtual void SetCoolDownCompletionTimeDelta(uint32_t delta, uint32_t total);
	EQLIB_OBJECT virtual void SetCoolDownCompletionTime(uint32_t time, uint32_t total);
	EQLIB_OBJECT virtual void SetCoolDownCompletionTime(time_t time, uint32_t total);
	EQLIB_OBJECT virtual void SetCoolDownBeginTime(uint32_t time, uint32_t total);
	EQLIB_OBJECT virtual void SetCoolDownUpdatedBeginTime(uint32_t time, uint32_t total);
	EQLIB_OBJECT virtual uint32_t GetCoolDownBeginTime() const;
	EQLIB_OBJECT virtual uint32_t GetCoolDownTotalDuration() const;
	EQLIB_OBJECT virtual uint32_t GetCoolDownTimeRemaining() const;
	EQLIB_OBJECT virtual void ClearCoolDownCompletionTime();

	//----------------------------------------------------------------------------
	// inherited virtuals
	EQLIB_OBJECT virtual int Draw() override;
	EQLIB_OBJECT virtual int DrawTooltipAtPoint(const CXPoint& pos, const CXStr& tooltip) const override;
	EQLIB_OBJECT virtual int HandleLButtonDown(const CXPoint&, uint32_t) override;
	EQLIB_OBJECT virtual int HandleLButtonUp(const CXPoint&, uint32_t) override;
	EQLIB_OBJECT virtual int HandleLButtonHeld(const CXPoint&, uint32_t) override;
	EQLIB_OBJECT virtual int HandleLButtonUpAfterHeld(const CXPoint&, uint32_t) override;
	EQLIB_OBJECT virtual int HandleRButtonDown(const CXPoint&, uint32_t) override;
	EQLIB_OBJECT virtual int HandleRButtonUp(const CXPoint&, uint32_t) override;
	EQLIB_OBJECT virtual int HandleRButtonHeld(const CXPoint&, uint32_t) override;
	EQLIB_OBJECT virtual int HandleRButtonUpAfterHeld(const CXPoint&, uint32_t) override;
	EQLIB_OBJECT virtual int HandleMouseMove(const CXPoint&, uint32_t) override;
	EQLIB_OBJECT virtual int OnProcessFrame() override;
	EQLIB_OBJECT virtual bool IsPointTransparent(const CXPoint& point) const override;
	EQLIB_OBJECT virtual void SetAttributesFromSidl(CParamScreenPiece*) override;

	//----------------------------------------------------------------------------
	// data members
/*0x1f8*/ int          MouseButtonState;
/*0x1fc*/ bool         bPicture;
/*0x200*/ CRadioGroup* pGroup;
/*0x204*/ bool         bChecked;
/*0x205*/ bool         bMouseOverLastFrame;
/*0x208*/ CXPoint      DecalOffset;
/*0x210*/ CXSize       DecalSize;
/*0x218*/ COLORREF     DecalTint;                // Color
/*0x21c*/ CXRect       TextOffsets;
/*0x22c*/ int          TextModeBits;
/*0x230*/ COLORREF     Mouseover;
/*0x234*/ COLORREF     Pressed;
/*0x238*/ COLORREF     Disabled;
/*0x23c*/ unsigned int CoolDownBeginTime;
/*0x240*/ unsigned int CoolDownDuration;
/*0x244*/ CXStr        Indicator;
/*0x248*/ unsigned int IndicatorVal;
/*0x24c*/ CTextObjectInterface* pIndicatorTextObject;
/*0x250*/ CButtonDrawTemplate DrawTemplate;
/*0x284*/ bool         bAllowButtonClickThrough;
/*0x285*/ bool         bCoolDownDoDelayedStart;
/*0x286*/ bool         bIsCheckbox;
/*0x287*/ bool         bIsDrawLasso;
/*0x288*/ uint32_t     ButtonStyle;              // tbd
/*0x28c*/ CLabel*      pButtonLabel;
/*0x290*/

	struct VirtualFunctionTable : public CXWnd::VirtualFunctionTable
	{
	/*0x168*/ void* SetRadioGroup;
	/*0x16c*/ void* DrawWndText;
	/*0x170*/ void* DrawCooldown;
	/*0x174*/ void* SetCheck;
	/*0x178*/ void* SetCoolDownCompletionTimeDelta;
	/*0x17c*/ void* SetCoolDownCompletionTime;
	/*0x180*/ void* SetCoolDownCompletionTime2;
	/*0x184*/ void* SetCoolDownBeginTime;
	/*0x188*/ void* SetCoolDownUpdatedBeginTime;
	/*0x18c*/ void* GetCoolDownBeginTime;
	/*0x190*/ void* GetCoolDownTotalDuration;
	/*0x194*/ void* GetCoolDownTimeRemaining;
	/*0x198*/ void* ClearCoolDownCompletionTime;
	};

	// points to the eq instance of the virtual function table for this class
	static VirtualFunctionTable* sm_vftable;
};

using CBUTTONWND = CButtonWnd;
using PCBUTTONWND = CButtonWnd*;

//============================================================================
// CComboWnd
//============================================================================

class CComboWnd : public CXWnd
{
public:
	CComboWnd(CXWnd*, uint32_t, const CXRect&, int height, const CButtonDrawTemplate&);
	virtual ~CComboWnd();

	//----------------------------------------------------------------------------
	// virtuals

	virtual CXSize GetMinSize() const;

	// overrides

	virtual int Draw() override;
	virtual int HandleLButtonDown(const CXPoint&, uint32_t) override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;
	virtual int OnMove(const CXRect&) override;
	virtual int OnResize(int, int) override;
	virtual int HitTest(const CXPoint&, int*) const override;
	virtual void SetDrawTemplate(CXWndDrawTemplate*) override;

	//----------------------------------------------------------------------------
	// methods

	EQLIB_OBJECT CXRect GetListRect(bool) const;
	EQLIB_OBJECT void SetColors(COLORREF norm, COLORREF highlight, COLORREF selected);
	EQLIB_OBJECT void InsertChoice(const CXStr& text, uint32_t data = 0);
	EQLIB_OBJECT void SetChoice(int index);
	EQLIB_OBJECT int GetItemCount();
	EQLIB_OBJECT int GetCurChoice() const;
	EQLIB_OBJECT CXStr GetCurChoiceText() const;
	EQLIB_OBJECT void DeleteAll();
	EQLIB_OBJECT CXRect GetTextRect() const;

	//EQLIB_OBJECT CXRect GetButtonRect() const;

	//----------------------------------------------------------------------------
	// data members
/*0x1e0*/ CListWnd*                    pListWnd;
/*0x1e4*/ int                          ListHeightMax;
/*0x1e8*/ int                          ListHeight;
/*0x1ec*/ CButtonDrawTemplate          ButtonDrawTemplate;
};

//============================================================================
// CEditLabelWnd
//============================================================================

enum eTextAlign
{
	eta_Left,
	eta_Center,
	eta_Right,
};

#define EDITWND_MAX_TAGS 10

enum EditWndStyle
{
	ewsMultiline    = 0x00010000,
	ewsPassword     = 0x00020000,
	ewsWantReturn   = 0x00040000,
	ewsWantArrows   = 0x00080000,
	ewsWantTabs     = 0x00100000,
	ewsReadOnly     = 0x00200000,
};

class CEditBaseWnd : public CXWnd
{
public:
	CEditBaseWnd(CXWnd* parent, uint32_t id, const CXRect& rect);
	virtual ~CEditBaseWnd();

	//----------------------------------------------------------------------------
	// virtuals

	virtual int GetHorzOffset() = 0;
	virtual CXStr GetDisplayString() const = 0;
	virtual CXPoint GetCaretPt() const = 0;
	virtual CXPoint PointFromPrintableChar(int charIndex) const = 0;
	virtual int ResetWnd() = 0;

	// overrides
	virtual int Draw() override = 0;
	virtual int DrawCaret() const override = 0;
	virtual int HandleKeyboardMsg(uint32_t message, uint32_t flags, bool down) override = 0;
	virtual int HandleLButtonDown(const CXPoint& pos, uint32_t flags) override = 0;
	virtual int OnKillFocus(CXWnd*) override;

	EQLIB_OBJECT void SetMaxChars(int);
	EQLIB_OBJECT void SetSel(int, int);

	//----------------------------------------------------------------------------
	// data members
/*0x1F0*/ eTextAlign   eAlign = eta_Left;
/*0x1F4*/ int          StartPos = 0;
/*0x1F8*/ int          EndPos = 0;
/*0x1Fc*/ int          MaxChars = -1;
/*0x200*/ int          MaxBytesUTF8 = -1;
/*0x204*/ CXStr        InputText;
/*0x208*/ int          TagPrintableStarts[EDITWND_MAX_TAGS];
/*0x230*/ int          TagPrintableEnds[EDITWND_MAX_TAGS];
/*0x258*/ int          TagOriginalStarts[EDITWND_MAX_TAGS];
/*0x280*/ int          TagOriginalEnds[EDITWND_MAX_TAGS];
/*0x2a8*/ int          TagDynamicSize[EDITWND_MAX_TAGS];
/*0x2d0*/ int          TagCodes[EDITWND_MAX_TAGS];
/*0x2f8*/ CXStr        TagStrings[EDITWND_MAX_TAGS];
/*0x320*/ int          TagCount;
/*0x324*/ uint32_t     EditStyle;
/*0x328*/
};

enum EditWndMode
{
	ewmNormal,
	ewmName,
	ewmAlphaOnly,
	ewmNumericOnly,
	ewmAlphaNumOnly,
	ewmCount
};

class CEditWnd : public CEditBaseWnd
{
public:
	CEditWnd(CXWnd* parent, uint32_t id, const CXRect& rect, uint32_t style = 0);
	virtual ~CEditWnd();

	//----------------------------------------------------------------------------
	// virtuals

	virtual int DrawMultiline();
	virtual CXStr GetWindowText() const;
	virtual CXStr GetWindowPrefixText();
	virtual CXStr GetWindowSuffixText();

	// CEditBaseWnd
	virtual int GetHorzOffset() override;
	virtual CXStr GetDisplayString() const override;
	virtual CXPoint GetCaretPt() const override;
	virtual CXPoint PointFromPrintableChar(int charIndex) const override;
	virtual int ResetWnd() override;

	// CXWnd
	virtual int Draw() override;
	virtual int DrawCaret() const override;
	virtual int HandleLButtonDown(const CXPoint&, uint32_t) override;
	virtual int HandleLButtonUp(const CXPoint&, uint32_t) override;
	virtual int HandleMouseMove(const CXPoint&, uint32_t) override;
	virtual void SetWindowText(const CXStr& text) override;
	virtual int OnMove(const CXRect& rect) override;
	virtual int OnResize(int, int) override;
	virtual int OnSetFocus(CXWnd*) override;
	virtual int OnKillFocus(CXWnd*) override;

	//----------------------------------------------------------------------------
	// methods

	EQLIB_OBJECT CXPoint GetCharIndexPt(int) const;
	EQLIB_OBJECT CXPoint GetSelEndPt() const;
	EQLIB_OBJECT CXPoint GetSelStartPt() const;
	EQLIB_OBJECT CXStr GetSTMLSafeText();
	EQLIB_OBJECT int ConvertIndexPrintableToTagged(int);
	EQLIB_OBJECT int ConvertIndexTaggedToPrintable(int);
	EQLIB_OBJECT int GetLineForPrintableChar(int) const;
	EQLIB_OBJECT int GetLineLength(int) const;
	EQLIB_OBJECT int SelectableCharFromPoint(CXPoint) const;
	EQLIB_OBJECT void AddItemTag(int, char*, int);
	EQLIB_OBJECT void CalculateScrollRange();
	EQLIB_OBJECT void EnsureCaretVisible();
	EQLIB_OBJECT void ReplaceSelection(char, bool);
	EQLIB_OBJECT void ReplaceSelection(CXStr, bool);
	EQLIB_OBJECT void SetEditable(bool);

	EQLIB_OBJECT void FillIndexArray(CXStr) const;
	EQLIB_OBJECT void FilterInputStr(CXStr&);
	EQLIB_OBJECT void ProcessText();

	//----------------------------------------------------------------------------
	// data members

/*0x328*/ bool         bAnchorAtStart;
/*0x329*/ bool         bCaretAtEnd;
/*0x32a*/ bool         bAutoVScrollCalc;
/*0x32b*/ bool         bEditable;
/*0x32c*/ CXStr        FilterChars;
/*0x330*/ int          EditMode;
/*0x334*/ wchar_t      PasswordChar;
/*0x338*/ ArrayClass2<uint32_t> LineIndices;
/*0x354*/
};

//============================================================================
// CLabelWnd
//============================================================================

// CLabelWnd__CLabelWnd_x
// size 0x200 see 8D5699 in Aug 10 2017 Live
// size 0x210 see 8DCE59 in Sep 11 2017 Test
// size 0x200 see 668D5B in Oct 17 2017 Live
// size 0x1e4 see 86BFC9 in rof2
class CLabelWnd : public CXWnd
{
public:
	// constructor / destructor
	CLabelWnd(CXWnd* parent, uint32_t id, const CXRect& rect);
	virtual ~CLabelWnd();

	// virtual functions
	virtual int Draw() override;
	virtual void SetWindowText(const CXStr& Text) override;

	virtual void UpdateText();
	virtual void ResizeHeightToText();

	// data members
/*0x1f8*/ bool         bNoWrap;
/*0x1f9*/ bool         bAlignRight;
/*0x1fa*/ bool         bAlignCenter;
/*0x1fc*/ int          xOffset;
/*0x200*/ bool         bResizeHeightToText;
/*0x204*/ int          Unknown0x204;
/*0x208*/ CXStr        Text;
/*0x20c*/ int          Unknown0x20c;
/*0x210*/ bool         Unknown0x210;
/*0x214*/ int          Unknown0x214;
};

//============================================================================
// CLabel
//============================================================================

// CLabel__CLabel_x
// CSidlManager__CreateLabel_x has this
// size 0x1e8 see 755709 in Rof2
// size is 0x220 see 7A5849 in Oct 13 2017 Test -eqmule
class CLabel : public CLabelWnd
{
public:
	// constructor / destructor
	CLabel(CXWnd* parent, uint32_t id, CXRect rect, int EQType);
	virtual ~CLabel();

	// virtual functions
	virtual void UpdateText() override;

	// data members
/*0x218*/ int          EQType;
};
using CLABEL = CLabel;
using PCLABEL = CLabel*;

//============================================================================
// CListWnd
//============================================================================

struct STreeData
{
/*0x00*/ int                      Depth = 0;
/*0x04*/ bool                     bIsExpandable = false;
/*0x08*/
};

struct SListWndCell
{
/*0x00*/ const CTextureAnimation* pTA = nullptr;
/*0x04*/ CXStr                    Text;
/*0x08*/ COLORREF                 Color = RGB(255, 255, 255);
/*0x09*/ bool                     bOnlyDrawTexture = false;
	CXWnd*                        pWnd = nullptr;
};

struct SListWndLine
{
/*0x000*/ ArrayClass<SListWndCell> Cells;
/*0x010*/ uint64_t                Data = 0;
/*0x018*/ int                     Height = -1;
/*0x01c*/ bool                    bSelected = false;
/*0x01d*/ bool                    bEnabled = true;
/*0x020*/ STreeData               Treedata;
/*0x028*/ char                    TooltipText[256];
/*0x128*/ bool                    bVisible = true;
};

enum ECellType
{
	CellTypeBasicText            = 1,
	CellTypeBasicIcon            = 2,
	CellTypeTextIcon             = 3
};

struct SListWndColumn
{
/*0x00*/ int                      Width = 0;
/*0x04*/ int                      MinWidth = 10;
/*0x08*/ CXSize                   TextureSize;
/*0x10*/ CXPoint                  TextureOffset;
/*0x18*/ CXStr                    StrLabel;
/*0x20*/ uint64_t                 Data = 0;
/*0x28*/ uint32_t                 Flags = 0;
/*0x2c*/ uint32_t                 Type = CellTypeTextIcon; // ECellType
/*0x30*/ CTextureAnimation*       pTextureAnim = nullptr;
/*0x34*/ CTextureAnimation*       pSelected = nullptr;
/*0x38*/ CTextureAnimation*       pMouseOver = nullptr;
/*0x3c*/ CXStr                    Tooltip;
/*0x40*/ bool                     bResizable = false;
///*0x44*/ int           Filler0x44;
/*0x48*/

	SListWndColumn(CXStr strLabel = "",
		int width = 0,
		CTextureAnimation* pta = nullptr,
		uint32_t flags = 0,
		uint32_t type = CellTypeTextIcon,
		CTextureAnimation* pSelected = nullptr,
		CTextureAnimation* pMouseOver = nullptr,
		CXStr tooltip = "",
		bool bResizable = false,
		CXSize textureSize = {},
		CXPoint textureOffset = {})
		: StrLabel(strLabel)
		, Width(width)
		, pTextureAnim(pta)
		, Flags(flags)
		, Type(type)
		, pSelected(pSelected)
		, pMouseOver(pMouseOver)
		, Tooltip(tooltip)
		, bResizable(bResizable)
		, TextureSize(textureSize)
		, TextureOffset(textureOffset)
	{}
};

class IListItemDataHandler
{
public:
	virtual bool GetText(int index, int subItem, CXStr& text) const = 0;
};

// Size is 0x298 in eqgame Sep 11 2017 Test (see 8D1D4C)
class CListWnd : public CXWnd
{
public:
	EQLIB_OBJECT CListWnd(CXWnd*, uint32_t, const CXRect&);
	virtual ~CListWnd();

	//----------------------------------------------------------------------------
	// virtuals

	EQLIB_OBJECT virtual int OnHeaderClick(CXPoint);
	EQLIB_OBJECT virtual int DrawColumnSeparators() const;
	EQLIB_OBJECT virtual int DrawSeparator(int index) const;
	EQLIB_OBJECT virtual int DrawLine(int index) const;
	EQLIB_OBJECT virtual int DrawHeader() const;
	EQLIB_OBJECT virtual int DrawItem(int index, int, int) const;
	EQLIB_OBJECT virtual void DeleteAll();
	EQLIB_OBJECT virtual int Compare(const SListWndLine&, const SListWndLine&) const;
	EQLIB_OBJECT virtual void Sort();

	// overrides
	EQLIB_OBJECT virtual int Draw() override;
	EQLIB_OBJECT virtual int DrawBackground() const override;
	EQLIB_OBJECT virtual int DrawTooltip(const CXWnd* wnd) const override;
	EQLIB_OBJECT virtual HCURSOR GetCursorToDisplay() const override;
	EQLIB_OBJECT virtual int HandleLButtonDown(const CXPoint& pos, uint32_t flags) override;
	EQLIB_OBJECT virtual int HandleLButtonUp(const CXPoint& pos, uint32_t flags) override;
	EQLIB_OBJECT virtual int HandleLButtonHeld(const CXPoint& pos, uint32_t flags) override;
	EQLIB_OBJECT virtual int HandleLButtonUpAfterHeld(const CXPoint& pos, uint32_t flags) override;
	EQLIB_OBJECT virtual int HandleRButtonDown(const CXPoint& pos, uint32_t flags) override;
	EQLIB_OBJECT virtual int HandleRButtonUp(const CXPoint& pos, uint32_t flags) override;
	EQLIB_OBJECT virtual int HandleRButtonHeld(const CXPoint& pos, uint32_t flags) override;
	EQLIB_OBJECT virtual int HandleRButtonUpAfterHeld(const CXPoint& pos, uint32_t flags) override;
	EQLIB_OBJECT virtual int HandleMouseMove(const CXPoint& pos, uint32_t flags) override;
	EQLIB_OBJECT virtual int WndNotification(CXWnd* sender, uint32_t message, void* data) override;
	EQLIB_OBJECT virtual void OnWndNotification() override;
	EQLIB_OBJECT virtual int OnMove(const CXRect& rect) override;
	EQLIB_OBJECT virtual int OnResize(int w, int h) override;
	EQLIB_OBJECT virtual int OnVScroll(EScrollCode code, int pos) override;
	EQLIB_OBJECT virtual int OnHScroll(EScrollCode code, int pos) override;
	EQLIB_OBJECT virtual CXRect GetHitTestRect(int code) const override;
	EQLIB_OBJECT virtual CXRect GetClientClipRect() const override;
	EQLIB_OBJECT virtual CXWnd* GetChildWndAt(const CXPoint& pos, bool, bool) const override;
	EQLIB_OBJECT virtual int SetVScrollPos(int pos) override;

	//----------------------------------------------------------------------------
	// methods

	EQLIB_OBJECT bool IsLineEnabled(int) const;
	EQLIB_OBJECT const CTextureAnimation* GetColumnAnimation(int) const;
	EQLIB_OBJECT const CTextureAnimation* GetColumnAnimationMouseOver(int) const;
	EQLIB_OBJECT const CTextureAnimation* GetColumnAnimationSelected(int) const;
	EQLIB_OBJECT const CTextureAnimation* GetItemIcon(int, int) const;
	EQLIB_OBJECT CXRect GetHeaderRect(int) const;
	EQLIB_OBJECT CXRect GetItemRect(int, int) const;
	EQLIB_OBJECT CXRect GetSeparatorRect(int) const;
	EQLIB_OBJECT CXStr GetColumnLabel(int) const;
	EQLIB_OBJECT CXStr GetItemText(const CXStr&, int, int) const;
	EQLIB_OBJECT int AddColumn(const CXStr& Label, CTextureAnimation* pTA, int Width, uint32_t Flags, CXStr Tooltip = "",
		uint32_t Type = CellTypeTextIcon, CTextureAnimation* pTASelected = nullptr, CTextureAnimation* pTAMouseOver = nullptr,
		bool bResizeable = false, CXSize TextureSize = {}, CXPoint TextureOffset = {});
	EQLIB_OBJECT int AddColumn(const CXStr& Label, int Width, uint32_t Flags, uint32_t Type = CellTypeTextIcon);
	EQLIB_OBJECT int AddLine(SListWndLine*);
	EQLIB_OBJECT int AddString(const CXStr& Str, COLORREF Color, uint64_t Data = 0, const CTextureAnimation* pTa = nullptr, const char* TooltipStr = nullptr);
	EQLIB_OBJECT int AddString(const char* Str, COLORREF Color, uint64_t Data, const CTextureAnimation* pTa, const char* TooltipStr = nullptr);
	EQLIB_OBJECT int GetColumnJustification(int) const;
	EQLIB_OBJECT int GetColumnMinWidth(int) const;
	EQLIB_OBJECT CXStr GetColumnTooltip(int) const;
	EQLIB_OBJECT int GetColumnWidth(int) const;
	EQLIB_OBJECT int GetCurCol() const;
	EQLIB_OBJECT int GetCurSel() const;
	EQLIB_OBJECT int GetItemAtPoint(const CXPoint& pt) const;
	EQLIB_OBJECT int GetItemHeight(int) const;
	EQLIB_OBJECT uint32_t GetColumnFlags(int) const;
	EQLIB_OBJECT uint64_t GetItemData(int) const;
	EQLIB_OBJECT COLORREF GetItemColor(int, int) const;
	EQLIB_OBJECT void CalculateFirstVisibleLine();
	EQLIB_OBJECT void CalculateLineHeights();
	EQLIB_OBJECT void CalculateVSBRange();
	EQLIB_OBJECT void ClearAllSel();
	EQLIB_OBJECT void ClearSel(int);
	EQLIB_OBJECT void CloseAndUpdateEditWindow();
	EQLIB_OBJECT void EnableLine(int Index, bool bVal);
	EQLIB_OBJECT void EnsureVisible(int);
	EQLIB_OBJECT void ExtendSel(int);
	EQLIB_OBJECT void GetItemAtPoint(const CXPoint& pt, int* ID, int* SubItem) const;
	EQLIB_OBJECT void InsertLine(int ID, SListWndLine* rEntry);
	EQLIB_OBJECT void RemoveLine(int);
	EQLIB_OBJECT void RemoveString(int);
	EQLIB_OBJECT void SetColors(unsigned long, unsigned long, unsigned long);
	EQLIB_OBJECT void SetColumnJustification(int, int);
	EQLIB_OBJECT void SetColumnLabel(int, const CXStr&);
	EQLIB_OBJECT void SetColumnWidth(int, int);
	EQLIB_OBJECT void SetCurSel(int);
	EQLIB_OBJECT void SetItemColor(int, int, unsigned long);
	EQLIB_OBJECT void SetItemData(int ID, uint64_t Data);
	EQLIB_OBJECT void SetItemText(int ID, int SubID, const CXStr& Text);
	EQLIB_OBJECT void ShiftColumnSeparator(int, int);
	EQLIB_OBJECT void ToggleSel(int);
	EQLIB_OBJECT void SetColumnsSizable(bool bColumnsSizable);
	EQLIB_OBJECT void GetWndPosition(CXWnd* pWnd, int& ItemID, int& SubItemID) const;
	EQLIB_OBJECT void SetItemWnd(int Index, int SubItem, CXWnd* pWnd);
	EQLIB_OBJECT CXWnd* GetItemWnd(int Index, int SubItem) const;
	EQLIB_OBJECT void SetItemIcon(int Index, int SubItem, const CTextureAnimation* pTA);
	EQLIB_OBJECT void CalculateCustomWindowPositions();

	//----------------------------------------------------------------------------
	// data members

/*0x1f0*/ int                 Unknown0x1f0;
/*0x1f4*/ ArrayClass<SListWndLine> ItemsArray;       // see CListWnd__GetItemData_x 0x8BD768                 add     ecx, 1F4h
/*0x204*/ ArrayClass<SListWndColumn> Columns;
/*0x214*/ int                 CurSel;
/*0x218*/ int                 CurCol;
/*0x21c*/ int                 DownItem;
/*0x220*/ int                 ScrollOffsetY;
/*0x224*/ int                 HeaderHeight;
/*0x228*/ int                 FirstVisibleLine;
/*0x22c*/ int                 SortCol;
/*0x230*/ bool                bSortAsc;
/*0x231*/ bool                bFixedHeight;
/*0x232*/ bool                bOwnerDraw;
/*0x233*/ bool                bCalcHeights;
/*0x234*/ bool                bColumnSizable;
/*0x238*/ int                 LineHeight;
/*0x23c*/ int                 ColumnSepDragged;
/*0x240*/ int                 ColumnSepMouseOver;
/*0x244*/ COLORREF            HeaderText;
/*0x248*/ COLORREF            Highlight;
/*0x24c*/ COLORREF            Selected;
/*0x250*/ CUITextureInfo      BGHeader;
/*0x268*/ COLORREF            BGHeaderTint;
/*0x26c*/ CTextureAnimation*  pRowSep;
/*0x270*/ CTextureAnimation*  pColumnSep;
/*0x274*/ CEditBaseWnd*       pEditCell;

/*0x278*/ IListItemDataHandler* pItemDataHandler;
/*0x27c*/ bool                bHasItemTooltips;
/*0x280*/ CXRect              PrevInsideRect;
/*0x290*/ uint32_t            ListWndStyle;
/*0x294*/ time_t              LastVisibleTime;
/*0x298*/

	struct VirtualFunctionTable : public CXWnd::VirtualFunctionTable
	{
	/*0x168*/ void* OnHeaderClick;
	/*0x16c*/ void* DrawColumnSeparators;
	/*0x170*/ void* DrawSeparator;
	/*0x174*/ void* DrawLine;
	/*0x178*/ void* DrawHeader;
	/*0x17c*/ void* DrawItem;
	/*0x180*/ void* DeleteAll;
	/*0x184*/ void* Compare;
	/*0x188*/ void* Sort;
	};

	// points to the eq instance of the virtual function table for this class
	static VirtualFunctionTable* sm_vftable;
};


//============================================================================
// Map Window
//============================================================================

// Map Window sizeof() = 0x38
struct MAPLABEL
{
/*0x00*/ uint32_t      LabelId;
/*0x04*/ MAPLABEL*     pNext;
/*0x08*/ MAPLABEL*     pPrev;
/*0x0c*/ CVector3      Location;
/*0x18*/ ARGBCOLOR     Color;
/*0x1c*/ int           Size;                     // 1-3;
/*0x20*/ char*         Label;
/*0x24*/ int           Layer;                    // 0-3;
/*0x28*/ int           Width;
/*0x2c*/ int           Height;
/*0x30*/ int           OffsetX;
/*0x34*/ int           OffsetY;
/*0x38*/
};
using PMAPLABEL = MAPLABEL *;

// sizeof() = 0x28
struct MAPLINE
{
/*0x00*/ MAPLINE*      pNext;
/*0x04*/ MAPLINE*      pPrev;
/*0x08*/ CVector3      Start;
/*0x14*/ CVector3      End;
/*0x20*/ ARGBCOLOR     Color;
/*0x24*/ int           Layer;                    // 0-3;
/*0x28*/
};
using PMAPLINE = MAPLINE *;

// pLines address = 0x254 + 0x035c = 0x05b0 (address of pMapViewMapVfTable)
// CMapViewWnd__CMapViewWnd_x
// CMapViewWnd_size: 0x668 (see 542694) in May 17 2019 Test
class MapViewMap : public CSidlScreenWnd
{
public:
	// constructor / destructor
	MapViewMap();
	virtual ~MapViewMap();

	// virtual functions
	virtual int PostDraw() override;
	virtual int HandleLButtonDown(const CXPoint& pos, uint32_t flags) override;
	virtual int HandleLButtonUp(const CXPoint& pos, uint32_t flags) override;
	virtual int HandleLButtonUpAfterHeld(const CXPoint& pos, uint32_t flags) override;
	virtual int HandleRButtonDown(const CXPoint& pos, uint32_t flags) override;
	virtual int HandleWheelMove(const CXPoint& pos, int scroll, uint32_t flags) override;

	// methods
	EQLIB_OBJECT void Clear();
	EQLIB_OBJECT void SaveEx(char*, int);
	EQLIB_OBJECT void SetZoom(float);

	//EQLIB_OBJECT bool DrawClippedLine(CVector3*, RGB, CXRect);
	//EQLIB_OBJECT bool IsLayerVisible(int);
	//EQLIB_OBJECT bool LoadEx(char*, int);
	//EQLIB_OBJECT bool PointInMapViewArea(CXPoint, CXRect);
	//EQLIB_OBJECT int GetMaxZ();
	//EQLIB_OBJECT int GetMinZ();
	//EQLIB_OBJECT unsigned long GetCurrentColor();
	//EQLIB_OBJECT unsigned long GetMarkedLineColor();
	//EQLIB_OBJECT void AddLabel(float, float, float, unsigned long, int, char*);
	//EQLIB_OBJECT void AddPoint(float, float, float);
	//EQLIB_OBJECT void CalcLabelRenderOffsets(CXRect);
	//EQLIB_OBJECT void ClearActiveLayer();
	//EQLIB_OBJECT void Draw(CXRect);
	//EQLIB_OBJECT void EndLine(float, float, float);
	//EQLIB_OBJECT void JoinLinesAtIntersect(bool);
	//EQLIB_OBJECT void Load(char*);
	//EQLIB_OBJECT void MoveLabel(MapViewLabel*, float, float, float);
	//EQLIB_OBJECT void PreCalcRenderValues();
	//EQLIB_OBJECT void RecalcLabelExtents(MapViewLabel*);
	//EQLIB_OBJECT void RemoveLabel(MapViewLabel*);
	//EQLIB_OBJECT void RemoveLabel();
	//EQLIB_OBJECT void RemoveLine(MapViewLabel*);
	//EQLIB_OBJECT void RemoveLine();
	//EQLIB_OBJECT void Save(char*);
	//EQLIB_OBJECT void SetCurrentColor(unsigned long);
	//EQLIB_OBJECT void SetMarkedLine(MapViewLabel*);
	//EQLIB_OBJECT void SetMarkedLineColor(unsigned long);
	//EQLIB_OBJECT void SetZoneExtents(int, int, int, int);
	//EQLIB_OBJECT void StartLine(float, float, float);
	//EQLIB_OBJECT void TransformPoint(CVector3*);

	float              mapViewMinX;
	float              mapViewMinY;
	float              mapViewMaxX;
	float              mapViewMaxY;
	int                panOffsetX;
	int                panOffsetY;
	float              lineOffsetX;
	float              lineOffsetY;
	float              scaleDiffX;
	float              scaleDiffY;
	float              mapViewScaleX;
	float              mapViewScaleY;
	PMAPLINE           pLines;
	PMAPLABEL          pLabels;
	uint32_t           nextLabelId;
	bool               lineActive;

	// more members, need to map it out. Fortunately, this is the last member of
	// CMapViewWnd so its not necessary at this time to do so ...
};

class CMapViewWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	// constructor / destructor
	EQLIB_OBJECT CMapViewWnd(CXWnd*);
	EQLIB_OBJECT virtual ~CMapViewWnd();

	// virtual functions
	virtual bool AboutToShow() override;
	virtual bool AboutToHide() override;
	virtual int OnShow() override;
	virtual int OnMove(const CXRect&) override;
	virtual int OnProcessFrame() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;
	virtual void OnWndNotification() override;
	virtual void LoadIniInfo() override;
	virtual void StoreIniInfo() override;

	// functions
	EQLIB_OBJECT void ActivateAutoMapping();
	EQLIB_OBJECT void DeactivateAutoMapping();
	EQLIB_OBJECT bool IsMappingEnabled();

	EQLIB_OBJECT void SetCurrentZone(EQZoneIndex, CVector3* v3Min, CVector3* v3Max, bool);
	EQLIB_OBJECT void GetWorldCoordinates(float*); // actually MapViewMap

	// these are almost all the controls belonging to the CMapViewWnd
/*0x0244*/ int         ZoneId;
/*0x0248*/ bool        bAutoMapping;
/*0x024c*/ CButtonWnd* btnPanLeft;
/*0x0250*/ CButtonWnd* btnPanRight;
/*0x0254*/ CButtonWnd* btnPanUp;
/*0x0258*/ CButtonWnd* btnPanDown;
/*0x025c*/ CButtonWnd* btnPanReset;
/*0x0260*/ CButtonWnd* btnZoomIn;
/*0x0264*/ CButtonWnd* btnZoomOut;
/*0x0268*/ CButtonWnd* btnShowGroup;
/*0x026c*/ CButtonWnd* btnFind;
/*0x0270*/ CButtonWnd* btnEndFind;
/*0x0274*/ CButtonWnd* btnFindAutoZoom;
/*0x0278*/ CButtonWnd* btnMapZoneGuide;
/*0x027c*/ CButtonWnd* btnToolbar;
/*0x0280*/ char        szZoneName[0x80];
/*0x0300*/ CButtonWnd* btntoggleLabels;
/*0x0304*/ CEditWnd*   editMinZ;
/*0x0308*/ CEditWnd*   editMaxZ;
/*0x030c*/ CButtonWnd* btnZFilter;
/*0x0310*/ CButtonWnd* btnLayer0;
/*0x0314*/ CButtonWnd* btnLayer1;
/*0x0318*/ CButtonWnd* btnLayer2;
/*0x031c*/ CButtonWnd* btnLayer3;
/*0x0320*/ CButtonWnd* btnLayer1Active;
/*0x0324*/ CButtonWnd* btnLayer2Active;
/*0x0328*/ CButtonWnd* btnLayer3Active;
/*0x032c*/ CButtonWnd* btnLoadCurrent;
/*0x0330*/ CPageWnd*   pageAtlas;
/*0x0334*/ CPageWnd*   pageMap;
/*0x0338*/ CTabWnd*    tabWnd;
/*0x033c*/ CXWnd*      MapRenderArea;
/*0x0340*/ CComboWnd*  MapsDirSelect;
/*0x0344*/ CXWnd*      AtlasRenderArea;
/*0x0348*/ CAtlas*     AtlasWnd;
/*0x034c*/ CComboWnd*  AtlasDirSelect;
/*0x0350*/ CButtonWnd* btnAtlasZoneGuide;
/*0x0354*/ CButtonWnd* btnMapIcon;
/*0x0358*/ CEditWnd*   editSearchBox;
/*0x035c*/ CButtonWnd* btnSearch;
/*0x0360*/ CButtonWnd* btnSearchClear;
/*0x0364*/ CListWnd*   listSearch;
/*0x0368*/ CXWnd*      wndSearchLayout;
/*0x036c*/ CButtonWnd* btnSearchHide;
/*0x0370*/ CXWnd*      wndSpacer;
/*0x0374*/ bool        bEditing;
/*0x0378*/ MapViewMap  MapView;                            // a window component owned by CMapViewWnd.

	// alias the stupid
	__declspec(property(get = getLines)) PMAPLINE pLines;
	__declspec(property(get = getLabels)) PMAPLABEL pLabels;

private:
	PMAPLINE getLines() { return MapView.pLines; }
	PMAPLABEL getLabels() { return MapView.pLabels; }
};

using EQMAPWINDOW = CMapViewWnd;
using PEQMAPWINDOW = CMapViewWnd *;

//============================================================================
// CChatWindowManager
//============================================================================

#define MAX_CHAT_WINDOWS     32
#define MAX_HITMODES         8

// Size is 82 see 4E4072 in Mar 05 2019 Test -eqmule
enum ChatFilterEnum
{
	CHAT_FILTER_SAY,
	CHAT_FILTER_TELL,
	CHAT_FILTER_GROUP,
	CHAT_FILTER_RAID,
	CHAT_FILTER_GUILD,
	CHAT_FILTER_OOC,
	CHAT_FILTER_AUCTION,
	CHAT_FILTER_SHOUT,
	CHAT_FILTER_EMOTE,
	CHAT_FILTER_MELEE_YOUR_HITS,
	CHAT_FILTER_SPELLS_MINE,
	CHAT_FILTER_SKILLS,
	CHAT_FILTER_CHAT1,
	CHAT_FILTER_CHAT2,
	CHAT_FILTER_CHAT3,
	CHAT_FILTER_CHAT4,
	CHAT_FILTER_CHAT5,
	CHAT_FILTER_CHAT6,
	CHAT_FILTER_CHAT7,
	CHAT_FILTER_CHAT8,
	CHAT_FILTER_CHAT9,
	CHAT_FILTER_CHAT10,
	CHAT_FILTER_OTHER,
	CHAT_FILTER_MELEE_YOUR_MISSES,
	CHAT_FILTER_MELEE_YOU_BEING_HIT,
	CHAT_FILTER_MELEE_YOU_BEING_MISSED,
	CHAT_FILTER_MELEE_OTHERS_HITS,
	CHAT_FILTER_MELEE_OTHERS_MISSES,
	CHAT_FILTER_MELEE_MY_DEATH,
	CHAT_FILTER_MELEE_OTHER_PC_DEATH,
	CHAT_FILTER_MELEE_CRITICAL_HITS,
	CHAT_FILTER_MELEE_DISCIPLINES,
	CHAT_FILTER_MELEE_WARNINGS,
	CHAT_FILTER_MELEE_NPC_RAMPAGE,
	CHAT_FILTER_MELEE_NPC_FLURRY,
	CHAT_FILTER_MELEE_NPC_ENRAGE,
	CHAT_FILTER_SPELLS_OTHERS,
	CHAT_FILTER_SPELLS_FAILURES,
	CHAT_FILTER_SPELLS_CRITICALS,
	CHAT_FILTER_SPELLS_WORN_OFF,
	CHAT_FILTER_SPELLS_DD_YOURS,
	CHAT_FILTER_FOCUS_EFFECTS,
	CHAT_FILTER_RANDOM_YOUR_ROLLS,
	CHAT_FILTER_PET_MESSAGES,
	CHAT_FILTER_PET_RAMPAGE_FLURRY,
	CHAT_FILTER_PET_CRITICALS,
	CHAT_FILTER_DAMAGE_SHIELDS_YOU_ATTACKING,
	CHAT_FILTER_EXPERIENCE_MESSAGES,
	CHAT_FILTER_NPC_EMOTES,
	CHAT_FILTER_SYSTEM_MESSAGES,
	CHAT_FILTER_WHO,
	CHAT_FILTER_PET_SPELLS,
	CHAT_FILTER_PET_RESPONSES,
	CHAT_FILTER_ITEM_SPEECH,
	CHAT_FILTER_FELLOWSHIP_MESSAGES,
	CHAT_FILTER_MERCENARY_MESSAGES,
	CHAT_FILTER_PVP_MESSAGES,
	CHAT_FILTER_MELEE_YOUR_FLURRY,
	CHAT_FILTER_DEBUG,                           // todo: check this not 100% sure its it...
	CHAT_FILTER_MELEE_NPC_DEATH,
	CHAT_FILTER_RANDOM_OTHERS_ROLLS,
	CHAT_FILTER_RANDOM_GROUP_RAID_ROLLS,
	CHAT_FILTER_ENVIRONMENTAL_DAMAGE_YOURS,
	CHAT_FILTER_ENVIRONMENTAL_DAMAGE_OTHERS,
	CHAT_FILTER_DAMAGE_SHIELDS_YOU_DEFENDING,
	CHAT_FILTER_DAMAGE_SHIELDS_OTHERS,
	CHAT_FILTER_EVENT_MESSAGES,
	CHAT_FILTER_OVERWRITTEN_DETRIMENTAL_SPELL_MESSAGES,
	CHAT_FILTER_OVERWRITTEN_BENEFICIAL_SPELL_MESSAGES,
	CHAT_FILTER_YOU_CANT_USE_THAT_COMMAND,       // Added chat color and filtering options for 'You can't use that command' messages.
	CHAT_FILTER_COMBAT_ABILITY_REUSE,            // Added chat color and filtering options for combat ability and AA ability reuse time messages.
	CHAT_FILTER_SPELLS_AA_ABILITY_REUSE,
	CHAT_FILTER_ITEM_DESTROYED,
	CHAT_FILTER_SPELLS_AURAS_YOU,
	CHAT_FILTER_SPELLS_AURAS_OTHERS,
	CHAT_FILTER_SPELLS_HEALS_YOURS,
	CHAT_FILTER_SPELLS_HEALS_OTHERS,
	CHAT_FILTER_SPELLS_DOTS_YOURS,
	CHAT_FILTER_SPELLS_DOTS_OTHERS,
	CHAT_FILTER_SPELLS_SONGS,
	CHAT_FILTER_SPELLS_DD_OTHERS,
	CHAT_FILTER_ZERO_HEALS,
	CHAT_FILTER_SOMETHING,

	MAX_CHAT_FILTERS = CHAT_FILTER_SOMETHING
};


// Size 0x384 in eqgame dated 05 Mar 2019 Test (see 0x5418AB)
class CChatWindowManager
{
	//EQLIB_OBJECT CChatWindowManager();
	//EQLIB_OBJECT ~CChatWindowManager();

	EQLIB_OBJECT COLORREF GetRGBAFromIndex(int);
	EQLIB_OBJECT int InitContextMenu(CChatWindow*);
	EQLIB_OBJECT void FreeChatWindow(CChatWindow*);
	EQLIB_OBJECT CChatWindow* GetLockedActiveChatWindow();   // might be returning CChatContainerWindow now
	EQLIB_OBJECT void SetLockedActiveChatWindow(CChatWindow*);
	EQLIB_OBJECT void CreateChatWindow(CXWnd* pParentWnd, int ID, char* Name, int Language, int DefaultChannel,
		int ChatChannel, char* szTellTarget, int FontStyle, bool bScrollbar, bool bHighLight, COLORREF HighlightColor);

	//EQLIB_OBJECT CChatWindow* GetActiveChatWindow();
	//EQLIB_OBJECT CChatWindow* GetChannelMap(int);
	//EQLIB_OBJECT CXStr GetAllVisibleText(CXStr);
	//EQLIB_OBJECT int GetChannelFromColor(int);
	//EQLIB_OBJECT void Activate();
	//EQLIB_OBJECT void AddText(CXStr, int);
	//EQLIB_OBJECT void ClearChannelMap(int);
	//EQLIB_OBJECT void ClearChannelMaps(CChatWindow*);
	//EQLIB_OBJECT void CreateChatWindow();
	//EQLIB_OBJECT void Deactivate();
	//EQLIB_OBJECT void LoadChatInis();
	//EQLIB_OBJECT void Process();
	//EQLIB_OBJECT void SetActiveChatWindow(CChatWindow*);
	//EQLIB_OBJECT void SetChannelMap(int, CChatWindow*);
	//EQLIB_OBJECT void UpdateContextMenus(CChatWindow*);
	//EQLIB_OBJECT void UpdateTellMenus(CChatWindow*);

/*0x000*/ CChatWindow*       ChatWnd[MAX_CHAT_WINDOWS];

	// this is likely a class as a member variable
/*0x080*/ void*              ChatContainerWindow_vfTable;
/*0x084*/ DWORD              Unknown0x084;
/*0x088*/ DWORD              Unknown0x088;
/*0x08c*/ DWORD              Unknown0x08c;
/*0x090*/ CChatContainerWindow* ChatContainerWindow[MAX_CHAT_WINDOWS];
/*0x110*/ DWORD              Unknown0x110;

/*0x114*/ DWORD              NumWindows;
/*0x118*/ DWORD              LockedWindow;
/*0x11c*/ DWORD              ActiveWindow;
/*0x120*/ DWORD              Unknown0x120;                       // CurrentActive... CChat::GetActiveChatWindow
/*0x124*/ DWORD              Unknown0x124;                       // LockedActive... CChatManager__GetLockedActiveChatWindow_x
/*0x128*/ CChatWindow*       ChannelMap[MAX_CHAT_FILTERS];       // channel map
/*0x1a0*/ CContextMenu*      pCM_MainMenu;
/*0x1a4*/ int                ScrollbarIndex;
/*0x1a8*/ CContextMenu*      pCM_LanguageMenu;
/*0x1ac*/ int                LanguageMenuIndex;
/*0x1b0*/ CContextMenu*      pCM_FilterMenu;
/*0x1b4*/ int                FilterMenuIndex;
/*0x1b8*/ int                ChatChannelFilterMenuIndex;
/*0x1bc*/ int                MeleeFilterSubMenuIndex;
/*0x1c0*/ int                SpellsFilterSubMenuIndex;
/*0x1c4*/ CContextMenu*      pCM_MeleeMenu;
/*0x1c8*/ int                MeleeFilterMenuIndex;
/*0x1cc*/ CContextMenu*      pCM_SpellMenu;
/*0x1d0*/ int                SpellsMenuIndex;
/*0x1d4*/ CContextMenu*      pCM_ChannelMenu;
/*0x1d8*/ int                ChannelMenuIndex;
/*0x1dc*/ CContextMenu*      pCM_DefaultChannelMenu;
/*0x1e0*/ int                DefaultChannelMenu;
/*0x1e4*/ int                DefaultChannelMenu2;
/*0x1e8*/ CContextMenu*      pCM_ChatChannelDefChan;
/*0x1ec*/ int                ChatChannelDefChanIndex;
/*0x1f0*/ CContextMenu*      pCM_YourHitsMenu;
/*0x1f4*/ int                YourHitsMenuIndex;
/*0x1f8*/ CContextMenu*      pCM_YourMissesMenu;
/*0x1fc*/ int                YourMissesMenuindex;
/*0x200*/ CContextMenu*      pCM_YouBeingHitMenu;
/*0x204*/ int                YouBeingHitMenuindex;
/*0x208*/ CContextMenu*      pCM_OthersHitsMenu;
/*0x20c*/ int                OthersHitsMenuindex;
/*0x210*/ CContextMenu*      pCM_OthersMissesMenu;
/*0x214*/ int                OthersMissesMenuindex;
/*0x218*/ CContextMenu*      pCM_AllContextMenu;
/*0x21c*/ int                AllContextMenuindex;
/*0x220*/ CContextMenu*      pCM_HitModesMenu;
/*0x224*/ int                HitModesMenuindex;
/*0x228*/ CContextMenu*      pCM_ReplyToMenu;
/*0x22c*/ int                ReplyToMenuindex;
/*0x230*/ CContextMenu*      pCM_TellFriendMenu;
/*0x234*/ int                TellFriendMenuindex;
/*0x238*/ CContextMenu*      pCM_TellRaidmemberMenu;
/*0x23c*/ int                TellRaidmemberMenuindex;
/*0x240*/ int                ReplyToSubIndex;
/*0x244*/ int                TellFriendSubIndex;
/*0x248*/ int                TellRaidmemberSubIndex;
/*0x24c*/ int                HitModes[MAX_HITMODES];
/*0x26c*/ int                DefaultChannel;
/*0x270*/ CContextMenu*      pCM_RandomFilterMenu;
/*0x274*/ int                RandomFilterIndex;
/*0x278*/ int                RandomFilterSubIndex;
/*0x27c*/ CContextMenu*      pCM_EnvironmentalDamageMenu;
/*0x280*/ int                EnvironmentalDamageIndex;
/*0x284*/ int                EnvironmentalDamageSubIndex;
/*0x288*/ CContextMenu*      pCM_DamageShieldsFilterMenu;
/*0x28c*/ int                DamageShieldsFilterIndex;
/*0x290*/ int                DamageShieldsFilterSubIndex;
/*0x294*/ CContextMenu*      pCM_BeneficialSpellsFilterMenu;
/*0x298*/ int                BeneficialSpellsFilteIndex;
/*0x29c*/
};

using EQCHATMGR = CChatWindowManager;
using PEQCHATMGR = CChatWindowManager*;

//============================================================================
// CChatWindow
//============================================================================

// in CChatWindow__SetChatFont see 692847 in eqgame.exe Test dated Jun 28 2016
const int EQ_CHAT_FONT_OFFSET = 0x11c;

// CChatWindow__CChatWindow_x
// Size 0x388 see 69AE4D in Oct 26 2017 Beta exe -eqmule
class CChatWindow : public CSidlScreenWnd
{
public:
	EQLIB_OBJECT CChatWindow(CXWnd* parent);
	EQLIB_OBJECT virtual ~CChatWindow();

	//----------------------------------------------------------------------------
	// virtuals

	virtual int Draw() override;
	virtual int HandleRButtonDown(const CXPoint&, uint32_t) override;
	virtual int OnProcessFrame() override;
	virtual int WndNotification(CXWnd* sender, uint32_t message, void* data) override;
	virtual int OnSetFocus(CXWnd* wnd) override;
	virtual int OnKillFocus(CXWnd* wnd) override;
	virtual void Deactivate() override;

	EQLIB_OBJECT void Clear();
	EQLIB_OBJECT void AddHistory(CXStr Text);
	EQLIB_OBJECT CEditWnd* GetInputWnd() { return InputWnd; }
	EQLIB_OBJECT CStmlWnd* GetOutputWnd() { return OutputWnd; }

	//EQLIB_OBJECT CXStr GetInputText();
	//EQLIB_OBJECT void AddOutputText(CXStr, int);
	//EQLIB_OBJECT void HistoryBack();
	//EQLIB_OBJECT void HistoryForward();
	//EQLIB_OBJECT void PageDown();
	//EQLIB_OBJECT void PageUp();
	//EQLIB_OBJECT void SetChatFont(int);

/*0x240*/ CChatWindowManager* ChatManager;
/*0x244*/ CEditWnd*    InputWnd;
/*0x248*/ CStmlWnd*    OutputWnd;
/*0x24c*/ int          ChatChannel;
/*0x250*/ int          ChatChannelIndex;
/*0x254*/ char         TellTarget[0x40];
/*0x294*/ int          Language;
/*0x298*/ bool         bIsMainChat;
/*0x299*/ bool         bIsTellWnd;
/*0x29c*/ int          TimestampFormat;
/*0x2a0*/ COLORREF     TimestampColor;
/*0x2a4*/ bool         bTimestampMatchChatColor;
/*0x2a8*/ CXStr        CommandHistory[0x28];     // see 690DAA in apr 11 2017 test
/*0x348*/ int          HistoryIndex;
/*0x34c*/ int          HistoryLastShown;
/*0x350*/ int          FontSize;                 // style
/*0x354*/ int          AlwaysChathereIndex;      // menu
/*0x358*/ int          NamesContextMenu;         // guess
/*0x35c*/ int          ContextMenuID;            // also a guess
/*0x360*/ int          ContextMenuSubID[0xa];    // this is not correct but ill fix it later.
/*0x388*/
};

using EQCHATWINDOW = CChatWindow;
using PEQCHATWINDOW = CChatWindow*;

//============================================================================
// CXMLParamManager
//============================================================================


template <class ElementType, int Cnt>
class HashCXStrElement
{
public:
	struct CKeyCXStrElementType
	{
		CXStr          key;
		ElementType    value;
	};

	ArrayClass2_RO<ArrayClass2_RO<CKeyCXStrElementType>> HashData;
};

class CXMLSymbolItem
{
public:
	CXStr                              ItemString;
	bool                               bDeclared;
	bool                               bValid;
};

class CXMLSymbolClass
{
public:
	CXStr                              Class;
	ArrayClass2_RO<CXMLSymbolItem>     ItemsArray;
	CHashCXStrInt32                    ItemsHashes;
	bool                               bValid;
};

class CXMLSymbolTable
{
public:
	/*0x00*/ void* vfTable;
	/*0x04*/ ArrayClass2_RO<CXMLSymbolClass> ClassesArray;
	/*0x20*/ CHashCXStrInt32               ClassesHashes;
	/*0x3C*/
};

class CXMLDataManager
{
public:
	/*0x00*/ void* vfTable;
	/*0x00*/ CHashCXStrInt32               EnumTypeHashes;
	/*0x00*/ ArrayClass2_RO<CXMLEnumInfo>  XMLEnumArray;
	/*0x1c*/ HashCXStrElement<CXMLDataPtr, 16 * 1024> ClassItemHashes;
	/*0x38*/ ArrayClass2_RO<CXMLDataClass> XMLDataArray;
	/*0x54*/ CXMLSymbolTable               SymbolTable;
	/*0x90*/ CXStr                         ErrorString;
	/*0x94*/

	EQLIB_OBJECT CXMLDataManager();
	EQLIB_OBJECT bool IsDerivedFrom(int, int);
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT CXMLData* GetXMLData(CXStr, CXStr);
	EQLIB_OBJECT CXMLData* GetXMLData(int, int);
	EQLIB_OBJECT int GetClassIdx(CXStr);
	EQLIB_OBJECT int GetItemIdx(int, CXStr);
	EQLIB_OBJECT int GetNumClass();
	EQLIB_OBJECT int GetNumItem(int);

	// virtual
	EQLIB_OBJECT ~CXMLDataManager();
	EQLIB_OBJECT bool DataValidate();
	EQLIB_OBJECT bool ReadValidate(CMemoryStream&);
	EQLIB_OBJECT bool WriteValidate(CMemoryStream&);
	EQLIB_OBJECT int GetStreamSize();
	EQLIB_OBJECT void IndexAll();
	EQLIB_OBJECT void ReadFromStream(CMemoryStream&);
	EQLIB_OBJECT void Set(CXMLDataManager&);
	EQLIB_OBJECT void WriteToStream(CMemoryStream&);

	// protected
	EQLIB_OBJECT void AddToSuperType(CXStr, CXMLDataPtr);
	EQLIB_OBJECT void SetEnumHash();
};

class CXMLParamManager : public CXMLDataManager
{
public:
	// virtual
	EQLIB_OBJECT ~CXMLParamManager();
	EQLIB_OBJECT bool XMLDataCopy(CXMLData*, CXMLData*);
	EQLIB_OBJECT CXMLData* AllocPtr(CXMLDataPtr&, int, const CXMLData*);
};

//============================================================================
// CSidlManagerBase
//============================================================================

enum EStaticScreenPieceClasses
{
	StaticScreenPieceUnknown = -1,

	StaticScreenPieceHeader,
	StaticScreenPieceFrame,
	StaticScreenPieceText,
	StaticScreenPieceAnimation,
	StaticScreenPieceTintedBlendAnimation,

	StaticScreenPieceMax,
};

// this class helps translate xml into ui elements

// size 0x1D4 2019-02-12 test see 53E3D3
// size 0x200 see 53ED93 in 2019 01 11 eqgame.exe
class CSidlManagerBase
{
public:
	CSidlManagerBase();
	virtual ~CSidlManagerBase();

	//----------------------------------------------------------------------------
	// virtuals

	virtual CXWnd* CreateXWnd(CXWnd* parent, CControlTemplate* pTemplate);

	//----------------------------------------------------------------------------
	// defined methods

	EQLIB_OBJECT CButtonDrawTemplate* FindButtonDrawTemplate(uint32_t id) const;
	EQLIB_OBJECT CButtonDrawTemplate* FindButtonDrawTemplate(const CXStr& name) const;

	EQLIB_OBJECT CXMLParamManager* GetParamManager();

	// this "bSomething" is a parameter passed through to CreateButtonWnd and CreateScreenWnd, which is then passed back through
	// CreateXWndFromTemplate recursively... not sure where it is used yet. A couple non-xml source set it to 1.
	EQLIB_OBJECT CXWnd* CreateXWndFromTemplate(CXWnd* pParent, CControlTemplate* pTemplate, bool bUnknown = false);

	// same as above but looks up a template by name.
	EQLIB_OBJECT CXWnd* CreateXWndFromTemplate(CXWnd* pParent, const CXStr& name);

	//----------------------------------------------------------------------------
	// methods

	EQLIB_OBJECT void DeleteContents();
	EQLIB_OBJECT void LoadSidl(const CXStr& Path, const CXStr& DefaultPath, const CXStr& Filename, const CXStr& DefaultClientPath = "UIFiles\\default\\");
	EQLIB_OBJECT CXStr& GetParsingErrorMsg();

	EQLIB_OBJECT EStaticScreenPieceClasses GetScreenPieceEnum(CScreenPieceTemplate*) const;
	EQLIB_OBJECT EStaticScreenPieceClasses GetScreenPieceEnum(CParamScreenPiece*) const;

	EQLIB_OBJECT CScrollbarTemplate* FindScrollbarTemplate(const CXStr& name) const;
	EQLIB_OBJECT CScrollbarTemplate* FindScrollbarTemplate(uint32_t) const;
	EQLIB_OBJECT CSliderDrawTemplate* FindSliderDrawTemplate(const CXStr& Name) const;
	EQLIB_OBJECT CSliderDrawTemplate* FindSliderDrawTemplate(uint32_t) const;
	EQLIB_OBJECT CUITextureInfo* FindTexture(const CXStr&) const;
	EQLIB_OBJECT CUITextureInfo* FindTexture(uint32_t) const;
	EQLIB_OBJECT CTextureAnimation* FindAnimation(const CXStr&) const;
	EQLIB_OBJECT CTextureAnimation* FindAnimation(uint32_t) const;
	EQLIB_OBJECT CTAFrameDraw* FindFrameDraw(const CXStr&) const;
	EQLIB_OBJECT CTAFrameDraw* FindFrameDraw(uint32_t) const;
	EQLIB_OBJECT CXWndDrawTemplate* FindDrawTemplate(const CXStr&) const;
	EQLIB_OBJECT CXWndDrawTemplate* FindDrawTemplate(uint32_t) const;
	EQLIB_OBJECT CScreenPieceTemplate* FindScreenPieceTemplate(const CXStr& Name) const;
	EQLIB_OBJECT CScreenPieceTemplate* FindScreenPieceTemplate(uint32_t) const;
	EQLIB_OBJECT CLayoutStrategyTemplate* FindLayoutStrategyTEmplate(uint32_t id);

	EQLIB_OBJECT CParamScreenPiece* GetScreenPiece(CParamScreen* screen, const CXStr& screenId) const;
	EQLIB_OBJECT CTextureAnimation CreateTextureAnimationFromSidlAnimation(const CParamUi2DAnimation*) const;
	EQLIB_OBJECT CTAFrameDraw CreateTAFrameDrawFromSidlFrame(const CParamFrameTemplate*) const;
	EQLIB_OBJECT CXWndDrawTemplate CreateDrawTemplateFromParamWindowDrawTemplate(const CParamWindowDrawTemplate*) const;

	EQLIB_OBJECT void AddScreenPieceTemplateInOrder(CScreenPieceTemplate*);
	EQLIB_OBJECT void AddAnimationInOrder(CTextureAnimation*);
	EQLIB_OBJECT void AddTAFrameDrawInOrder(CTAFrameDraw*);
	EQLIB_OBJECT void AddDrawTemplateInOrder(CXWndDrawTemplate*);
	EQLIB_OBJECT void AddLayoutStrategyInOrder(CLayoutStrategyTemplate*);

	EQLIB_OBJECT CButtonDrawTemplate GetButtonDrawTemplateFromParamButtonDrawTemplate(const CParamButtonDrawTemplate&) const;
	EQLIB_OBJECT CGaugeDrawTemplate GetGaugeDrawTemplateFromParamGaugeDrawTemplate(const CParamGaugeDrawTemplate&) const;
	EQLIB_OBJECT CSpellGemDrawTemplate GetSpellGemDrawTemplateFromParamSpellGemDrawTemplate(const CParamSpellGemDrawTemplate&) const;
	EQLIB_OBJECT CScrollbarTemplate GetScrollbarTemplateFromParamScrollbarTemplate(const CParamScrollbarDrawTemplate&) const;
	EQLIB_OBJECT CSliderDrawTemplate GetSliderDrawTemplateFromParamSliderDrawTemplate(const CParamSliderDrawTemplate&) const;

	EQLIB_OBJECT static CXPoint GetPointFromParamPoint(const CParamPoint&);
	EQLIB_OBJECT static CXRect GetRectFromParamPointSize(const CParamPoint&, const CParamSize&);
	EQLIB_OBJECT static CXSize GetSizeFromParamSize(const CParamSize&);
	EQLIB_OBJECT static CXStr TranslateString(const CXStr&);
	EQLIB_OBJECT static D3DCOLOR GetD3DCOLOR(const CParamRGB&);

	EQLIB_OBJECT CLayoutStrategyTemplate* CreateLayoutStrategyTemplate(CParamLayoutStrategy*);
	EQLIB_OBJECT CScreenPieceTemplate* CreateScreenPieceTemplateFromParamScreenPiece(const CParamScreenPiece*) const;
	EQLIB_OBJECT CLayoutStrategy* CreateLayoutStrategy(CLayoutStrategyTemplate*);
	EQLIB_OBJECT CXWnd* CreateButtonWnd(CXWnd* parent, CControlTemplate* pTemplate);
	EQLIB_OBJECT CXWnd* CreateScreenWnd(CXWnd* parent, CControlTemplate* pTemplate);
	EQLIB_OBJECT CXWnd* CreatePageWnd(CXWnd* parent, CControlTemplate* pTemplate);
	EQLIB_OBJECT CXWnd* CreateListWnd(CXWnd* parent, CControlTemplate* pTemplate);
	EQLIB_OBJECT CXWnd* CreateSliderWnd(CXWnd* parent, CControlTemplate* pTemplate);
	EQLIB_OBJECT CXWnd* CreateLabelWnd(CXWnd* parent, CControlTemplate* pTemplate);
	EQLIB_OBJECT CXWnd* CreateSTMLWnd(CXWnd* parent, CControlTemplate* pTemplate);
	EQLIB_OBJECT CXWnd* CreateTreeViewWnd(CXWnd* parent, CControlTemplate* pTemplate);
	EQLIB_OBJECT CXWnd* CreateComboWnd(CXWnd* parent, CControlTemplate* pTemplate);
	EQLIB_OBJECT CXWnd* CreateTabWnd(CXWnd* parent, CControlTemplate* pTemplate);
	EQLIB_OBJECT CXWnd* CreateLayoutWnd(CXWnd* parent, CControlTemplate* pTemplate);
	EQLIB_OBJECT CXWnd* CreateHorizontalLayoutWnd(CXWnd* parent, CControlTemplate* pTemplate);
	EQLIB_OBJECT CXWnd* CreateVerticalLayoutWnd(CXWnd* parent, CControlTemplate* pTemplate);
	EQLIB_OBJECT CXWnd* CreateFinderWnd(CXWnd* parent, CControlTemplate* pTemplate);
	EQLIB_OBJECT CXWnd* CreateTileLayoutWnd(CXWnd* parent, CControlTemplate* pTemplate);
	EQLIB_OBJECT CXWnd* CreateTemplateContainerWnd(CXWnd* parent, CControlTemplate* pTemplate);

	//----------------------------------------------------------------------------
	// data members

	/*0x004*/ EStaticScreenPieceClasses              ScreenPieceClassIndex[StaticScreenPieceMax];
	/*0x018*/ ArrayClass<CUITextureInfo*>            Textures;
	/*0x028*/ ArrayClass<CButtonDrawTemplate*>       ButtonDrawTemplateArray;
	/*0x038*/ ArrayClass<CScrollbarTemplate*>        ScrollbarTemplateArray;
	/*0x048*/ ArrayClass<CSliderDrawTemplate*>       SliderDrawTemplateArray;
	/*0x058*/ ArrayClass<CXStr>                      ScreenNameArray;
	/*0x068*/ ArrayClass<CXWndDrawTemplate*>         DrawTemplateArray;
	/*0x078*/ CHashCXStrInt32                        DrawTemplateHash;
	/*0x094*/ ArrayClass<CTextureAnimation*>         AnimationArray;
	/*0x0A4*/ CHashCXStrInt32                        AnimationsHash;
	/*0x0C0*/ ArrayClass<CTAFrameDraw*>              TAFrameArray;
	/*0x0D0*/ CHashCXStrInt32                        TAFrameHash;
	/*0x0EC*/ ArrayClass<CScreenPieceTemplate*>      ScreenPieceArray;
	/*0x0FC*/ CHashCXStrInt32                        ScreenPiecesHash;
	/*0x118*/ ArrayClass<CLayoutStrategyTemplate*>   LayoutStrategyTemplateArray;
	/*0x128*/ CHashCXStrInt32                        LayoutStrategyTemplatesHash;
	/*0x144*/ CXMLParamManager                       XMLDataMgr;
	/*0x1F8*/ bool                                   bLoadError;
	/*0x1FC*/ CXStr                                  ErrorString;
	/*0x200*/
};

class CSidlManager : public CSidlManagerBase
{
public:
	virtual ~CSidlManager();

	//----------------------------------------------------------------------------
	// virtuals
	virtual CXWnd* CreateXWnd(CXWnd* parent, CControlTemplate* pTemplate) override;

	//----------------------------------------------------------------------------
	// defined methods

	// don't need to use this -- can just use CreateXWnd.
	EQLIB_OBJECT CXWnd* CreateHotButtonWnd(CXWnd* pwndParent, CControlTemplate* pControl);

	//----------------------------------------------------------------------------
	// methods

	EQLIB_OBJECT CXWnd* CreateLabel(CXWnd* parent, CControlTemplate* pTemplate);
	EQLIB_OBJECT CXWnd* CreateGuageWnd(CXWnd* parent, CControlTemplate* pTemplate);
	EQLIB_OBJECT CXWnd* CreateSpellGemWnd(CXWnd* parent, CControlTemplate* pTemplate);
	EQLIB_OBJECT CXWnd* CreateInvSlotWnd(CXWnd* parent, CControlTemplate* pTemplate);
	EQLIB_OBJECT CXWnd* CreateHtmlComponentWnd(CXWnd* parent, CControlTemplate* pTemplate);
};

using CSIDLMGR = CSidlManager;
using PCSIDLMGR = CSidlManager*;

//----------------------------------------------------------------------------

void InitializeUI();

} // namespace eqlib
