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
#include "SidlTemplates.h"

#if defined(TEST)
#include "../test/EQData(Test).h"
#elif defined(LIVE)
#include "../live/EQData.h"
#endif

#include <list>

#undef FindWindow
#undef InsertMenuItem

struct IShellFolder;

// from shtypes.h
struct _ITEMIDLIST;
using LPITEMIDLIST = _ITEMIDLIST *;

namespace eqlib {

//----------------------------------------------------------------------------
// Forward Declarations

class CAtlas;
class CButtonWnd;
class CChatContainerWindow;
class CChatWindow;
class CContextMenu;
class CConfirmationDialog;
class CEditWnd;
class CParamLayoutStrategy;
class CLabel;
class CLayoutStrategyTemplate;
class CStmlWnd;
class CUnSerializeBuffer;
class CVerticalLayoutWnd;
class CVivoxObserver;

using D3DCOLOR = DWORD;
using CPopDialogWnd = CConfirmationDialog;

//----------------------------------------------------------------------------

class WndEventHandler
{
public:
	unsigned int lastUpdate;
};

//----------------------------------------------------------------------------

class PopDialogHandler
{
public:
	virtual void DialogResponse(int, int, void*);
};

//----------------------------------------------------------------------------

class CVivoxManager;
class CVivoxObserver
{
public:
	virtual void Unknown00(bool) {}

	CVivoxManager* VivoxManager;
};

//----------------------------------------------------------------------------

class CObservable;

class CNotification
{
public:
	int Type;
};

class IObserver
{
public:
	virtual void Notify(CObservable* Src, const CNotification* const Notification);
};

class CObservable
{
public:
	EQLIB_OBJECT void NotifyObservers(CNotification* notification = 0);

private:
	// this will never work because of differences in stl between
	// mq2 and eq. Don't use it.
	std::list<IObserver*> ObserverList;
};

//============================================================================
// CTextureFont
//============================================================================

class CTextureFont
{
public:
	virtual ~CTextureFont();

	EQLIB_OBJECT CXStr GetName() const;
	EQLIB_OBJECT int DrawWrappedText(const CXStr&, const CXRect&, const CXRect&, unsigned long, unsigned short, int) const;
	EQLIB_OBJECT int DrawWrappedText(const CXStr& Str, int x, int y, int Width, const CXRect& BoundRect, COLORREF Color, uint16_t Flags = 0, int StartX = 0) const;
	EQLIB_OBJECT int GetHeight() const;
	EQLIB_OBJECT int GetKerning(unsigned short, unsigned short) const;
	EQLIB_OBJECT int GetTextExtent(const CXStr&);
	EQLIB_OBJECT int GetWidth(unsigned short) const;

/*0x00*/ int FontStyle;
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
// CCheckBoxWnd
//============================================================================

class CCheckBoxWnd : public CButtonWnd
{
public:
	CCheckBoxWnd(CXWnd*, uint32_t, const CXRect&, const CXPoint&, const CXSize&,
		CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*,
		CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*,
		CTextureAnimation*, CTextureAnimation*);
	virtual ~CCheckBoxWnd();

	// virtual
	int HandleLButtonDown(const CXPoint&, uint32_t) override;
	int HandleLButtonUp(const CXPoint&, uint32_t) override;
	int HandleMouseMove(const CXPoint&, uint32_t) override;
	void SetRadioGroup(CRadioGroup*) override;

	EQLIB_OBJECT void SetRadioLook();

	// protected
	bool bOrgState;
};

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
// CEditWnd
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
// CEditLabelWnd
//============================================================================

class CEditLabelWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CEditLabelWnd(CXWnd*);
	virtual ~CEditLabelWnd();

	virtual int OnProcessFrame() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT CXStr GetLabelText();
};

//============================================================================
// CGaugeWnd
//============================================================================

// size 0x248 see 7E24DB in Sep 21 2018
class CGaugeWnd : public CXWnd
{
public:
	EQLIB_OBJECT CGaugeWnd(CXWnd*, uint32_t, const CXRect&, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, int, unsigned long, unsigned long, bool, int, int, int, int);
	EQLIB_OBJECT CXRect CalcFillRect(CXRect*, int) const;
	EQLIB_OBJECT CXRect CalcLinesFillRect(CXRect*, int) const;
	EQLIB_OBJECT void SpecialToolTip();

	// virtual
	EQLIB_OBJECT ~CGaugeWnd();
	EQLIB_OBJECT int Draw() const;
	EQLIB_OBJECT int HandleLButtonUp(const CXPoint&, uint32_t);
	EQLIB_OBJECT int OnProcessFrame();
	EQLIB_OBJECT void SetAttributesFromSidl(CParamScreenPiece*);

	//----------------------------------------------------------------------------
	// data members

/*0x1e0*/ int          EQType;
/*0x1e4*/ D3DCOLOR     FillTint;
/*0x1e8*/ D3DCOLOR     LinesFillTint;
/*0x1ec*/ bool         bDrawLinesFill;
/*0x1f0*/ int          TextOffsetX;
/*0x1f4*/ int          TextOffsetY;
/*0x1f8*/ int          GaugeOffsetX;
/*0x1fc*/ int          GaugeOffsetY;
/*0x200*/ float        LastFrameVal;
/*0x204*/ CXStr        LastFrameName;
/*0x208*/ int          LastFrameTime;
/*0x20c*/ int          LastFrameTarget;
/*0x210*/ CXStr        GaugeTooltip;
/*0x214*/ int          TooltipVal;
/*0x218*/ CGaugeDrawTemplate DrawTemplate;
/*0x234*/ CTextObjectInterface* pTextObject;
/*0x238*/ CXStr        NextDrawStr;
/*0x23c*/ bool         bSmooth;
/*0x240*/ int          TargetVal;
/*0x244*/ bool         bUseTargetVal;
/*0x248*/
};

//============================================================================
// CHotButton
//============================================================================

class CHotButton : public CXWnd
{
public:
	CHotButton(CXWnd* parent, uint32_t id, const CXRect& rect, CButtonWnd* button,
		CInvSlotWnd* invSlot, CSpellGemWnd* gemSlot);
	virtual ~CHotButton();

	EQLIB_OBJECT void SetButtonSize(int percent, bool bUpdateParent = true);

	//----------------------------------------------------------------------------
	// data members

/*0x1e0*/ int          BarIndex;
/*0x1e4*/ int          ButtonIndex;
/*0x1e8*/ unsigned int Timer;
/*0x1ec*/ CTextureAnimation* DecalIcon;
/*0x1f0*/ int          LastButtonType;
/*0x1f4*/ int          LastButtonSlot;
/*0x1f8*/ char         LastButtonPage;
/*0x1f9*/ EqItemGuid   LastItemGuid;
/*0x20c*/ int          LastItemId;
/*0x210*/ int          LastIconType;
/*0x214*/ int          LastIconSlot;
/*0x218*/ CXStr        LastLabel;
/*0x21c*/ CXStr        DefaultLabel;
/*0x220*/ bool         bForceUpdate;
/*0x224*/ CTextObjectInterface* pKeyMapText;
/*0x228*/ int          Unknown0x228;
/*0x22c*/ CButtonWnd*  pButtonWnd;
/*0x230*/ CInvSlotWnd* pInvSlotWnd;
/*0x234*/ CSpellGemWnd* pSpellGemWnd;
/*0x238*/ CXSize       BaseSize;
/*0x240*/ int          ButtonPercentSize;
/*0x244*/ CXSize       BaseButtonSize;
/*0x24c*/ CXSize       BaseDecalSize;
/*0x254*/ CXSize       BaseInvButtonSize;
/*0x25c*/ CXSize       BaseSpellButtonSize;
/*0x264*/ int          Unknown0x264;
/*0x268*/
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

class SListWndSortInfo
{
public:
/*0x00*/ int           SortCol;
/*0x04*/ const SListWndLine& ListWndLine1;
/*0x08*/ CXStr         StrLabel1;
/*0x10*/ uint64_t      Data1;
/*0x18*/ const SListWndLine& ListWndLine2;
/*0x1c*/ CXStr         StrLabel2;
/*0x20*/ uint64_t      Data2;
/*0x28*/ int           SortResult;
/*0x2c*/
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
// CPageWnd
//============================================================================

class CPageWnd : public CSidlScreenWnd
{
public:
	CPageWnd(CXWnd*, uint32_t, const CXRect&, const CXStr&, CPageTemplate*);
	virtual ~CPageWnd();

	EQLIB_OBJECT CXStr GetTabText(bool bSomething = false) const;
	EQLIB_OBJECT void SetTabText(CXStr&) const;
};

//============================================================================
// CSliderWnd
//============================================================================

// size: 0x258 6/10/2019 (test)
class CSliderWnd : public CXWnd
{
public:
	CSliderWnd(CXWnd*, uint32_t, const CXRect&, CSliderTemplate*);
	virtual ~CSliderWnd();

	virtual int Draw() override;
	virtual int HandleKeyboardMsg(uint32_t, uint32_t, bool) override;
	virtual int HandleLButtonDown(const CXPoint&, uint32_t) override;
	virtual int HandleLButtonUp(const CXPoint&, uint32_t) override;
	virtual int HandleLButtonUpAfterHeld(const CXPoint&, uint32_t) override;
	virtual int HandleMouseMove(const CXPoint&, uint32_t) override;
	virtual int OnProcessFrame() override;

	EQLIB_OBJECT CXRect GetEndCapLeftRect() const;
	EQLIB_OBJECT CXRect GetEndCapRightRect() const;
	EQLIB_OBJECT CXRect GetMiddleRangeRect() const;
	EQLIB_OBJECT CXRect GetThumbRect() const;
	EQLIB_OBJECT int GetValue() const;
	EQLIB_OBJECT void SetNumTicks(int);
	EQLIB_OBJECT void SetValue(int);

	EQLIB_OBJECT int DrawEndCapLeft() const;
	EQLIB_OBJECT int DrawEndCapRight() const;
	EQLIB_OBJECT int DrawMiddleRange() const;
	EQLIB_OBJECT int DrawThumb() const;
	EQLIB_OBJECT void SetThumbToOffset(int);
	EQLIB_OBJECT void UpdateMiddleRange();
	EQLIB_OBJECT void UpdateThumb();

	//----------------------------------------------------------------------------
	// data members

/*0x1f8*/ CButtonDrawTemplate      bdtThumb;
/*0x230*/ CTextureAnimation*       ptaBackground;
/*0x234*/ CTextureAnimation*       ptaEndCapLeft;
/*0x238*/ CTextureAnimation*       ptaEndCapRight;

	// more ...
};

//============================================================================
// CStmlWnd
//============================================================================

enum ELinkType
{
	STML_LINK_FILE,
	STML_LINK_UNIT,
	STML_LINK_BUILDING,
	STML_LINK_MESSAGE,
	STML_LINK_CAMERA,
	STML_LINK_REPORT,
	STML_LINK_WNDNOTIFY,
	STML_LINK_EMPTY,
	STML_LINK_URL,
	STML_LINK_PLAYER,
	STML_LINK_SPAM,
	STML_LINK_ACHIEVEMENT,
	STML_LINK_HELP,
	STML_LINK_DIALOG_RESPONSE,
	STML_LINK_COMMAND,
	STML_NUM_LINK_TYPES,
};

enum EStmlTargetValue
{
	STML_TARGET_SELF,
	STML_TARGET_BLANK,
};

struct SFontTag
{
	CTextureFont*      face;
	COLORREF           color;
};

using SStyleTag = uint32_t;

const uint32_t STML_TAG_BOLD = 0;
const uint32_t STML_TAG_UNDERLINE = 2;

struct SFormattedText
{
	SFontTag           Font;
	SStyleTag          Style;
	int                Left;
	int                Right;
	CXStr              Text;
	int32_t            LinkID;
	CTextureAnimation* Texture;
	int32_t            TableID;
	int32_t            IndexStart;
};

struct STextLine
{
	ArrayClass<SFormattedText> TextPieces;
	int                yBottom;
	int                yTop;
	int32_t            IndexStart;
};

struct SLinkInfo
{
	ELinkType          Type = STML_LINK_EMPTY;
	uint32_t           MsgID = -1;
	CXStr              Name;
	EStmlTargetValue   TargetType = STML_TARGET_SELF;
};

struct SParseVariables
{
	// todo ...
};

struct SHistoryElement
{
	SLinkInfo          sLink;
	CXStr              STMLText;
};

enum ESTMLParseState
{
	STML_PARSE_STATE_BODY,
	STML_PARSE_STATE_HEAD,
};


// size is 0x2b8 in sep 11 2017 test see 8DCF69
class CStmlWnd : public CXWnd
{
public:
	CStmlWnd(CXWnd*, uint32_t, const CXRect&);
	virtual ~CStmlWnd();

	virtual bool IsPointTransparent(const CXPoint&) const override;
	virtual HCURSOR GetCursorToDisplay() const override;
	virtual int Draw() override;
	virtual int HandleKeyboardMsg(uint32_t, uint32_t, bool) override;
	virtual int HandleLButtonDown(const CXPoint&, uint32_t) override;
	virtual int HandleLButtonUp(const CXPoint&, uint32_t) override;
	virtual int HandleMouseMove(const CXPoint&, uint32_t) override;
	virtual int OnMove(const CXRect&) override;
	virtual int OnProcessFrame() override;
	virtual int OnResize(int, int) override;
	virtual int OnHScroll(EScrollCode, int) override;
	virtual int OnVScroll(EScrollCode, int) override;
	virtual void SetWindowText(const CXStr&) override;

	EQLIB_OBJECT bool CanGoBackward();
	EQLIB_OBJECT CXSize AppendSTML(CXStr);
	EQLIB_OBJECT CXStr GetSTMLText() const;
	EQLIB_OBJECT CXStr GetVisibleText(CXStr, const CXRect&) const;
	EQLIB_OBJECT static CXStr MakeStmlColorTag(unsigned long);
	EQLIB_OBJECT static CXStr MakeWndNotificationTag(uint32_t, const CXStr&, const CXStr&);
	EQLIB_OBJECT void ActivateLink(SLinkInfo);
	EQLIB_OBJECT void ForceParseNow();
	EQLIB_OBJECT void GoToBackHistoryLink();
	// EQLIB_OBJECT void LoadPage(CXStr, enum ESTMLTargetValue, bool);
	EQLIB_OBJECT void SetSTMLText(CXStr, bool, SLinkInfo*);
	EQLIB_OBJECT void SetSTMLTextWithoutHistory(CXStr);

	// protected
	EQLIB_OBJECT bool IsLinkActive(SLinkInfo) const;
	EQLIB_OBJECT bool ParseAmpersand(CXStr, char*) const;
	EQLIB_OBJECT static bool CanBreakAtCharacter(unsigned short);
	EQLIB_OBJECT static bool IsCharacterNotASpaceAndNotNULL(unsigned short);
	EQLIB_OBJECT static bool IsCharacterNotEquals(unsigned short);
	EQLIB_OBJECT static bool IsCharacterNotQuotes(unsigned short);
	EQLIB_OBJECT unsigned short FastForwardPastQuotesAndGetNextTagPiece(const CXStr&, CXStr*, int*, bool);
	EQLIB_OBJECT unsigned short FastForwardPastSpaces(const CXStr&, int*);
	EQLIB_OBJECT unsigned short FastForwardPastSpacesAndQuotes(const CXStr&, int*);
	EQLIB_OBJECT unsigned short FastForwardToEndOfTag(const CXStr&, CXStr*, int*, char);
	EQLIB_OBJECT unsigned short GetNextChar(int*, const CXStr&);
	EQLIB_OBJECT unsigned short GetNextTagPiece(const CXStr&, CXStr*, int*, bool (*)(unsigned short), bool);
	EQLIB_OBJECT unsigned short GetThisChar(int, const CXStr&);
	EQLIB_OBJECT void ActivateLinkFile(SLinkInfo);
	EQLIB_OBJECT void ActivateLinkMessageId(SLinkInfo);
	EQLIB_OBJECT void ActivateLinkReport(SLinkInfo, bool);
	EQLIB_OBJECT void ActivateLinkWndNotify(SLinkInfo);
	EQLIB_OBJECT void AddLinkToHistory(SLinkInfo, const CXStr&);
	EQLIB_OBJECT void AddTextPieceToLine(SParseVariables*);
	EQLIB_OBJECT void CalculateHSBRange(int);
	EQLIB_OBJECT void CalculateVSBRange(int);
	EQLIB_OBJECT void CompleteParse();
	EQLIB_OBJECT void InitializeTempVariables(SParseVariables*, const CXRect&);
	EQLIB_OBJECT void InitializeTextLine(SParseVariables*, int);
	EQLIB_OBJECT void InitializeWindowVariables();
	// EQLIB_OBJECT void ParseLinkTarget(const CXStr&, enum ESTMLTargetValue*) const;
	EQLIB_OBJECT void ParseSTMLHead(const CXStr&);
	EQLIB_OBJECT void ParseSTMLTable(const CXStr&, int*, const CXStr&, SParseVariables*);
	EQLIB_OBJECT void ParseSTMLTableAttributes(const CXStr&, STable*);
	// EQLIB_OBJECT void ParseTagAlign(const CXStr&, enum ESTMLAlign*) const;
	EQLIB_OBJECT void ParseTagColor(const CXStr&, unsigned long*) const;
	EQLIB_OBJECT void ParseTagFace(const CXStr&, const CTextureFont**) const;
	EQLIB_OBJECT void ResetTempVariablesForNewLine(SParseVariables*);
	EQLIB_OBJECT void StripFirstSTMLLines(int);
	EQLIB_OBJECT void UpdateHistoryString(int32_t, const CXStr&);

	//----------------------------------------------------------------------------
	// data members

	// todo: verify
/*0x1F0*/ CXStr                        STMLText;
/*0x1F4*/ CircularArrayClass2<STextLine> TextLines;
/*0x21c*/ int32_t                      TextTotalHeight;
/*0x220*/ int32_t                      TextTotalWidth;
/*0x224*/ int32_t                      Unknown0x224;
/*0x228*/ ArrayClass2<SLinkInfo>       Links;                        // size 0x1c at 0x228 for sure see 8F4487 in Sep 11 2017 test - eqmule
/*0x244*/ ArrayClass<STable>           Tables;
/*0x254*/ bool                         bReparseNow;
/*0x255*/ bool                         bResized;
/*0x256*/ bool                         bAlignCenter;
/*0x258*/ int                          LineSpacingAdjust;
/*0x25c*/ int32_t                      CapturedLinkID;
/*0x260*/ int32_t                      MousedOverLinkID;
/*0x264*/ COLORREF                     BackGroundColor;
/*0x268*/ COLORREF                     TextColor;
/*0x26c*/ COLORREF                     LinkColor;
/*0x270*/ COLORREF                     VLinkColor;
/*0x274*/ COLORREF                     ALinkColor;
/*0x278*/ COLORREF                     MLinkColor;
/*0x27c*/ ESTMLParseState              CurrentParseState;
/*0x280*/ ArrayClass2<SHistoryElement> HistoryArray;
/*0x29c*/ int32_t                      HistoryIndex;
/*0x2a0*/ CStmlReport* pStmlReport;
/*0x2a4*/ int                          MaxLines;
/*0x2a8*/ int                          PlayerContextMenuIndex;
/*0x2ac*/ int                          Unknown0x2ac;
/*0x2b0*/ int                          Unknown0x2b0;
/*0x2b4*/ int                          Unknown0x2b4;
/*0x2b8*/
};

//============================================================================
// CTabWnd
//============================================================================

class CTabWnd : public CXWnd
{
public:
	CTabWnd(CXWnd* pParent, uint32_t uId, const CXRect& rect, CTabBoxTemplate* pTabContents);
	virtual ~CTabWnd();

	EQLIB_OBJECT CPageWnd* GetCurrentPage() const;
	EQLIB_OBJECT CXRect GetPageClientRect() const;
	EQLIB_OBJECT CXRect GetPageInnerRect() const;
	EQLIB_OBJECT CXRect GetTabInnerRect(int) const;
	EQLIB_OBJECT CXRect GetTabRect(int) const;
	EQLIB_OBJECT int GetCurrentTabIndex() const;
	EQLIB_OBJECT int GetNumTabs() const;
	EQLIB_OBJECT void InsertPage(CPageWnd*, int);
	EQLIB_OBJECT void SetPage(CPageWnd*, bool);
	EQLIB_OBJECT void SetPage(int index, bool bNotifyParent, bool bBringToTop = true, bool bSomething = true);
	EQLIB_OBJECT void SetPageRect(const CXRect&);
	EQLIB_OBJECT void UpdatePage();
	EQLIB_OBJECT bool IndexInBounds(int) const;
	EQLIB_OBJECT CPageWnd* GetPageFromTabIndex(int) const;
	EQLIB_OBJECT CPageWnd* GetPageFromTabPoint(CXPoint) const;
	EQLIB_OBJECT int DrawCurrentPage() const;
	EQLIB_OBJECT int DrawTab(int) const;

	//----------------------------------------------------------------------------
	// data members

	// todo: map this out
};

//============================================================================
// CTreeView
//============================================================================

class CTreeView : public CListWnd
{
public:
	CTreeView(CXWnd*, uint32_t, CXRect, int);
	virtual ~CTreeView();
};

//============================================================================
//============================================================================
//============================================================================
//============================================================================

//============================================================================
// CAAWnd
//============================================================================

class CAAWnd : public CSidlScreenWnd, public PopDialogHandler, public WndEventHandler
{
public:
	CAAWnd(CXWnd*);
	virtual ~CAAWnd();

	virtual int OnProcessFrame() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT void CancelAASpend();
	EQLIB_OBJECT void ConfirmAASpend();
	EQLIB_OBJECT void SendNewPercent();
	EQLIB_OBJECT void ShowAbility(int);
	EQLIB_OBJECT void Update();
	EQLIB_OBJECT void UpdateTimer();

	// private
	EQLIB_OBJECT void Init();
	EQLIB_OBJECT void UpdateSelected();
};

//============================================================================
// CAchievementsWnd
//============================================================================

class CAchievementsWnd : public CSidlScreenWnd
{
public:
	CAchievementsWnd(CXWnd*);
	virtual ~CAchievementsWnd();
};

//============================================================================
// CActionsWnd
//============================================================================

class CActionsWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CActionsWnd(CXWnd*);
	virtual ~CActionsWnd();

	virtual int OnProcessFrame() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT CButtonWnd* GetAbilityBtn(int);
	EQLIB_OBJECT CButtonWnd* GetCombatBtn(int);
	EQLIB_OBJECT CButtonWnd* GetMenuBtn(int);
	EQLIB_OBJECT int GetCurrentPageEnum() const;
	EQLIB_OBJECT void Activate(int);
	EQLIB_OBJECT void KeyMapUpdated();
	EQLIB_OBJECT void SelectSkillForAbilityBtn(int);
	EQLIB_OBJECT void SelectSkillForCombatBtn(int);
	EQLIB_OBJECT void UpdateButtonText();

	// private
	EQLIB_OBJECT int AbilitiesPageActivate();
	EQLIB_OBJECT int AbilitiesPageDeactivate();
	EQLIB_OBJECT int AbilitiesPageOnProcessFrame();
	EQLIB_OBJECT int AbilitiesPageWndNotification(CXWnd*, uint32_t, void*);
	EQLIB_OBJECT int CombatPageActivate();
	EQLIB_OBJECT int CombatPageDeactivate();
	EQLIB_OBJECT int CombatPageOnProcessFrame();
	EQLIB_OBJECT int CombatPageWndNotification(CXWnd*, uint32_t, void*);
	EQLIB_OBJECT int MainPageActivate();
	EQLIB_OBJECT int MainPageDeactivate();
	EQLIB_OBJECT int MainPageOnProcessFrame();
	EQLIB_OBJECT int MainPageWndNotification(CXWnd*, uint32_t, void*);
	EQLIB_OBJECT int RedirectActivateTo(CPageWnd*);
	EQLIB_OBJECT int RedirectDeactivateTo(CPageWnd*);
	EQLIB_OBJECT int RedirectOnProcessFrameTo(CPageWnd*);
	EQLIB_OBJECT int RedirectWndNotificationTo(CPageWnd*, CXWnd*, uint32_t, void*);
	EQLIB_OBJECT int SocialsPageActivate();
	EQLIB_OBJECT int SocialsPageDeactivate();
	EQLIB_OBJECT int SocialsPageOnProcessFrame();
	EQLIB_OBJECT int SocialsPageWndNotification(CXWnd*, uint32_t, void*);
};

//============================================================================
// CAdvancedLootWnd
//============================================================================

struct AdvancedLootItemNPC
{
/*0x00*/ unsigned int  CorpseID;                 // spawnId of the corpse that has this lootitem
/*0x04*/ short         StackCount;
/*0x08*/ unsigned int  Expiration;
/*0x0c*/ bool          Locked;
/*0x0d*/ CHAR          Name[0x40];
/*0x4d*/ //more data here?
};
using LOOTDETAILS = AdvancedLootItemNPC;
using PLOOTDETAILS = AdvancedLootItemNPC*;

//.text:0041ECBD                 imul    eax, 84h in Apr 15 2015 test
enum eAdvLootState
{
	eAdvLootWaiting,
	eAdvLootAsk,
	eAdvLootAskAutoRoll,
	eAdvLootStop,
	eAdvLootAskCompleted,
	eAdvLootFreeGrab,
	eAdvLootFixedAskAutoRoll,
	eAdvLootFixedAskCompleted,
	eAdvLootRemoved
};

// size is 0x88 see 0x48AB44 in Dec 10 2018 live
struct AdvancedLootItem
{
/*0x00*/ unsigned int  ItemID;
/*0x04*/ char          Name[0x40];
/*0x44*/ int           IconID;
/*0x48*/ bool          bStackable;
/*0x4c*/ int           MaxStack;
/*0x50*/ bool          NoDrop;
/*0x54*/ int           ComboID;
/*0x58*/ unsigned int  LootID;
/*0x5c*/ eAdvLootState State;
/*0x60*/ bool          bAutoRoll;
/*0x61*/ bool          ActivelyManaged;          // User has the manage Window up
/*0x62*/ bool          ContextMenu;              // item has a context menu
/*0x63*/ bool          AskRandomMode;            // item is in AskRandom mode
/*0x64*/ bool          CLootInProgress;
/*0x65*/ bool          PLootInProgress;
/*0x68*/ SoeUtil::Array<AdvancedLootItemNPC> LootDetails;
/*0x7c*/ unsigned int  AskTimer;
/*0x80*/ bool          AutoRoll;
/*0x81*/ bool          FG;
/*0x82*/ bool          Need;
/*0x83*/ bool          Greed;
/*0x84*/ bool          No;
/*0x85*/ bool          AlwaysNeed;
/*0x86*/ bool          AlwaysGreed;
/*0x87*/ bool          Never;
/*0x88*/
};
using LOOTITEM = AdvancedLootItem;
using PLOOTITEM = AdvancedLootItem*;

struct AdvancedLootItemList
{
/*0x000*/ SoeUtil::Array<AdvancedLootItem> Items;
/*0x010*/ bool         bIsPersonalLoot;
/*0x014*/ CListWnd*    SharedLootList;
/*0x018*/ CComboWnd*   PersonalLootList;
/*0x01C*/
};
using LOOTLIST = AdvancedLootItemList;
using PLOOTLIST = AdvancedLootItemList*;

class CorpseData;
class RefreshCorpseItemChoices;
class CGroupMemberBase;
struct RaidMember;

// CAdvancedLootWnd__CAdvancedLootWnd_x
// size 0x310 see 4CEA0D in Nov 29 2017 Beta
class CAdvancedLootWnd : public CSidlScreenWnd, public PopDialogHandler, public WndEventHandler
{
public:
	CAdvancedLootWnd(CXWnd*);
	virtual ~CAdvancedLootWnd();

	// virtuals
	virtual void UpdateMasterLooter(const CXStr&, bool);
	virtual void ToggleGroupedByNpc();
	virtual void ToggleApplyFilters();
	virtual void AddCorpse(CorpseData*, RefreshCorpseItemChoices*);
	virtual void RemoveCorpse(uint32_t id);
	virtual void ReduceItemCount(bool, int, int, int);
	virtual void ClearCorpses();
	virtual void AddPlayerToList(CGroupMemberBase*);
	virtual void AddPlayerToList(const RaidMember*);
	virtual void ResetComboBox();
	virtual bool ConstructChange();
	virtual void AddPlayerAccess(uint32_t id);

	// GiveTo
	EQLIB_OBJECT void DoAdvLootAction(int listindex, const CXStr& Name, bool Action, int Quantity);
	// GiveTo
	EQLIB_OBJECT void DoSharedAdvLootAction(PLOOTITEM pLootItem, const CXStr& Assignee, bool Action, int Quantity);

	//----------------------------------------------------------------------------
	// data members

/*0x248*/ uint8_t      Unknown0x0240[0x8c];      // ui controls
/*0x2d4*/ AdvancedLootItemList* pCLootList;      // below ref to aAdlw_applyfilt
/*0x2d8*/ AdvancedLootItemList* pPLootList;      // below ref to aAdlw_cllwnd
/*0x2dc*/ DWORD        Unknown0x2dc;
/*0x2e0*/ DWORD        Unknown0x2e0;
/*0x2e4*/ DWORD        Unknown0x2e4;
/*0x2e8*/ DWORD        TotalLootCount;
/*0x2ec*/ DWORD        Unknown0x2ec;
/*0x2f0*/ DWORD        ContextMenuId;
/*0x2f4*/ DWORD        CLastStackSize;
/*0x2f8*/ BYTE         Unknown0x2f8[0x18];
/*0x310*/
};
using EQADVLOOTWND = CAdvancedLootWnd;
using PEQADVLOOTWND = CAdvancedLootWnd*;


//============================================================================
// CAlarmWnd
//============================================================================

class CAlarmWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CAlarmWnd(CXWnd*);
	virtual ~CAlarmWnd();

	// virtual
	int OnProcessFrame() override;
	int WndNotification(CXWnd*, uint32_t, void*) override;

	// private
	EQLIB_OBJECT void DoNeverButton();
};

//============================================================================
// CAuraWnd
//============================================================================

class CAuraWnd : public CSidlScreenWnd
{
public:
	CAuraWnd(CXWnd*);
	virtual ~CAuraWnd();
};

//============================================================================
// CBandolierWnd
//============================================================================

#define MAX_BANDOLIER_SLOTS 4

class CBandolierWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CBandolierWnd();
	virtual ~CBandolierWnd();

	CButtonWnd*        pAddButton;
	CButtonWnd*        pDeleteButton;
	CButtonWnd*        pUseButton;
	CButtonWnd*        pMkHotButton;
	CButtonWnd*        pAutoSwapButton;
	CButtonWnd*        pDisplayButtons[MAX_BANDOLIER_SLOTS];
	CListWnd*          pWeaponSetList;
};

//============================================================================
// CBankWnd
//============================================================================

class CBankWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
/*0x23c*/ int          MoneyButtonIndex;
/*0x240*/ unsigned int NextRefreshTime;
/*0x244*/ bool         bInventoryWasActive;
/*0x245*/ bool         bRealEstateManagementWasActive;
/*0x248*/ CButtonWnd*  MoneyButtons[5];          // including shared plat
/*0x25C*/ CLabel*      BankerNameLabel;
/*0x260*/ CInvSlotWnd* InvSlotWindows[NUM_BANK_SLOTS];
/*0x2C0*/ CLabel*      SharedBankLabel;
/*0x2C4*/ CInvSlotWnd* SharedSlotWindows[NUM_SHAREDBANK_SLOTS];
/*0x2DC*/ CButtonWnd*  DoneButton;
/*0x2E0*/ CButtonWnd*  ChangeButton;
/*0x2E4*/ CButtonWnd*  AutoButton;
/*0x2E8*/ CButtonWnd*  AltStorageButton;
/*0x2EC*/ CButtonWnd*  FindItemButton;
/*0x2F0*/ int          BankSize;
/*0x2F4*/ int          Unknown0x2F4;
/*0x2F8*/

	CBankWnd(CXWnd*, CXStr);
	virtual ~CBankWnd();

	virtual int OnProcessFrame() override;
	virtual int PostDraw() override;
	virtual int WndNotification(CXWnd* pWnd, unsigned int uiMessage, void* pData) override;

	EQLIB_OBJECT int GetNumBankSlots() const;

	// private
	EQLIB_OBJECT long GetBankQtyFromCoinType(int);
	EQLIB_OBJECT void ClickedMoneyButton(int, int);
	EQLIB_OBJECT void UpdateMoneyDisplay();
};

//============================================================================
// CBazaarSearchWnd
//============================================================================

// CBazaarSearchWnd__CBazaarSearchWnd_x aBazaarsearchwn
// CBazaarSearchWnd_size: 0x92e0 (see 5431FE) in May 17 2019 Test
class CBazaarSearchWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CBazaarSearchWnd(CXWnd*);
	virtual ~CBazaarSearchWnd();

	virtual void Activate() override;
	virtual int Draw() override;
	virtual int OnProcessFrame() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;
	virtual void Deactivate() override;

	EQLIB_OBJECT void HandleBazaarMsg(char*, int);

	EQLIB_OBJECT char* GetPriceString(unsigned long);
	EQLIB_OBJECT void UpdatePlayerCombo();
	EQLIB_OBJECT void UpdatePlayerUpdateButton(bool);
	EQLIB_OBJECT void AddItemtoList(char*, unsigned long, char*, int, int);
	EQLIB_OBJECT void doQuery();
	EQLIB_OBJECT void SortItemList(int);
	EQLIB_OBJECT void UpdateComboButtons();

	//----------------------------------------------------------------------------
	// data members

	// todo: check
/*0x0240*/ BYTE        Unknown0x0240[0x8ff4];
/*0x9238*/ void**      ppTraderData;
/*0x923c*/ DWORD       hashVal;                  // find in CBazaarSearchWnd__HandleBazaarMsg_x
/*0x9240*/ BYTE        Unknown0x9240[0xa0];
/*0x92e0*/
};
using BAZAARSEARCHWND = CBazaarSearchWnd;
using PBAZAARSEARCHWND = CBazaarSearchWnd*;

//============================================================================
// CBazaarWnd
//============================================================================

class CBazaarWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CBazaarWnd(CXWnd*);
	virtual ~CBazaarWnd();

	// virtual
	virtual int OnProcessFrame() override;
	virtual int PostDraw() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT bool StoreSelectedPrice();
	EQLIB_OBJECT char* GetPriceString(unsigned long);
	EQLIB_OBJECT EQ_Item* ReturnItemByIndex(int);
	EQLIB_OBJECT int UpdateBazaarListtoServer();
	EQLIB_OBJECT long GetQtyFromCoinType(int);
	EQLIB_OBJECT unsigned long GetPrice();
	EQLIB_OBJECT void AddBazaarText(char*, int);
	EQLIB_OBJECT void AddEquipmentToBazaarArray(EQ_Item*, int, unsigned long);
	EQLIB_OBJECT void BuildBazaarItemArray();
	EQLIB_OBJECT void ClickedMoneyButton(int, int);
	EQLIB_OBJECT void HandleTraderMsg(char*);
	EQLIB_OBJECT void RebuildItemArray();
	EQLIB_OBJECT void SelectBazaarSlotItem(int, CTextureAnimation*);
	EQLIB_OBJECT void SetMoneyButton(int, int);
	EQLIB_OBJECT void UpdatePriceButtons();

	// protected
	EQLIB_OBJECT void UpdateButtons();

	// private
	EQLIB_OBJECT void CreateBZRIniFilename();
	EQLIB_OBJECT void ToggleBzrItemActive(int, bool);
};

//============================================================================
// CBodyTintWnd
//============================================================================

class CBodyTintWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CBodyTintWnd(CXWnd*);
	virtual ~CBodyTintWnd();

	virtual int OnProcessFrame() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT char* BuildRBGTooltip(unsigned long, char* const);
	EQLIB_OBJECT unsigned long GetButtonTint(int);
	EQLIB_OBJECT unsigned long GetItemTint(int);
	EQLIB_OBJECT void GetReagentCount();
	EQLIB_OBJECT void GetTintChangeCount();
	EQLIB_OBJECT void ResetToOrigBodyTints();
	EQLIB_OBJECT void SetSlotLabels(bool);
	EQLIB_OBJECT void StoreModifiedBodyTints();
	EQLIB_OBJECT void UpdateLabelsAndButtons();
	EQLIB_OBJECT void UpdateLocalTintColor(unsigned long);
	EQLIB_OBJECT void UpdateMaterialTintLocal(unsigned long);
};

//============================================================================
// CBookWnd
//============================================================================

class CBookWnd : public CSidlScreenWnd
{
public:
	CBookWnd(CXWnd*);
	virtual ~CBookWnd();

	virtual int HandleKeyboardMsg(uint32_t, uint32_t, bool) override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT bool CheckBook(EQ_Note*);
	EQLIB_OBJECT void SetBook(char*);
	EQLIB_OBJECT void CleanPages();
	EQLIB_OBJECT void DisplayText();
	EQLIB_OBJECT void ProcessText();
	EQLIB_OBJECT void ShowButtons();
};

//============================================================================
// CBuffWindow
//============================================================================

enum BuffWindowType
{
	BuffWindowStandard,
	BuffWindowShortDuration,
	BuffWindowMelee
};

// CBuffWindow__CBuffWindow aBuffwindow
// this is used for both long and shortbuffs...
// CBuffWindow_size: 0x728 (see 542833) in May 17 2019 Test
class CBuffWindow : public CSidlScreenWnd, public WndEventHandler
{
public:
	CBuffWindow(CXWnd*, BuffWindowType);
	virtual ~CBuffWindow();

	virtual CXSize GetMinSize(bool) const override;
	virtual int OnProcessFrame() override;
	virtual int PostDraw() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT void SetBuffIcon(CButtonWnd*, int, int);
	EQLIB_OBJECT void HandleSpellInfoDisplay(CXWnd*);
	EQLIB_OBJECT void RefreshBuffDisplay();
	EQLIB_OBJECT void RefreshIconArrangement();

	//----------------------------------------------------------------------------
	// data members

	// todo: check me
/*0x0240*/ uint8_t     Unknown0x0240[0xb8];
/*0x02fc*/ CButtonWnd* pBuff[0x24];
/*0x038c*/ uint8_t     Unknown0x038c[0x210];
/*0x059c*/ int         BuffId[NUM_LONG_BUFFS];
/*0x0644*/ int         BuffTimer[NUM_LONG_BUFFS];
/*0x06ec*/ uint8_t     Unknown0x06ec[0x28];
/*0x0714*/ int         MaxLongBuffs;             // 0x2a (NUM_LONG_BUFFS)
/*0x0718*/ int         MaxShortBuffs;            // 0x37 (NUM_SHORT_BUFFS)
/*0x071c*/ uint8_t     Unknown0x071c[0xc];
/*0x0728*/
};
using EQBUFFWINDOW = CBuffWindow;
using PEQBUFFWINDOW = CBuffWindow*;

//============================================================================
// CCastingWnd
//============================================================================

class CCastingWnd;

//============================================================================
// CCastSpellWnd
//============================================================================

class CSpellGemWnd;

// pinstCCastSpellWnd_x
// CCastSpellWnd__CCastSpellWnd aCastspellwnd
// CCastSpellWnd_size: 0x2e0 (see 542BED) in May 17 2019 Test
class CCastSpellWnd : public CSidlScreenWnd, public PopDialogHandler, public WndEventHandler
{
public:
	CCastSpellWnd(CXWnd*);
	~CCastSpellWnd();

	virtual int OnProcessFrame() override;
	virtual int PostDraw() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	static EQLIB_OBJECT void Unmemorize(int);
	static EQLIB_OBJECT void UnmemorizeList(int*, int);
	EQLIB_OBJECT void ForgetMemorizedSpell(int);
	EQLIB_OBJECT void HandleSpellInfoDisplay(CXWnd*);
	EQLIB_OBJECT void HandleSpellLeftClick(int);
	EQLIB_OBJECT void HandleSpellRightClick(int);
	EQLIB_OBJECT void KeyMapUpdated();
	EQLIB_OBJECT void RecacheCategorizedSpells();
	EQLIB_OBJECT void RecacheLoadoutContextMenu();
	EQLIB_OBJECT void SpellBookDeactivating();
	EQLIB_OBJECT bool IsBardSongPlaying();
	EQLIB_OBJECT unsigned long GetSpellGemColor(EQ_Spell*);
	EQLIB_OBJECT void CategorizeSpell(int, int, int, int);
	EQLIB_OBJECT void ClearSpellCategories();
	EQLIB_OBJECT void Init();
	EQLIB_OBJECT void MakeSpellSelectMenu();
	EQLIB_OBJECT void RefreshSpellGemButtons();
	EQLIB_OBJECT void UpdateSpellGems(int);
	EQLIB_OBJECT void UpdateSpellGemTooltips(int);

	//----------------------------------------------------------------------------
	// data members

/*0x248*/ CPopDialogWnd* pCurrentPop;
/*0x24c*/ unsigned int   lastRefresh;
/*0x250*/ bool           bHorizontal;
/*0x254*/ CSpellGemWnd*  SpellSlots[NUM_SPELL_GEMS]; // CSPW_Spell%d
/*0x28c*/ BYTE        Unknown0x028c[0x54];
/*0x2e0*/
};
using EQCASTSPELLWINDOW = CCastSpellWnd;
using PEQCASTSPELLWINDOW = CCastSpellWnd*;

//============================================================================
// CCharacterCreation
//============================================================================

class CCharacterCreation : public CSidlScreenWnd
{
public:
	CCharacterCreation(CXWnd*);
	virtual ~CCharacterCreation();

	virtual int Draw() override;
	virtual int OnProcessFrame() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT void ActivateScreen(int);
	EQLIB_OBJECT void DoBackButton();
	EQLIB_OBJECT void DoNextButton();
	EQLIB_OBJECT void HandleNameApprovalResponse(int);
	EQLIB_OBJECT void NameGenerated(char*);
	EQLIB_OBJECT bool IsLackingExpansion(bool, bool);
	EQLIB_OBJECT char* GetCharCreateText(char*, int, int, int, int);
	EQLIB_OBJECT int GetClassButtonIndex(int);
	EQLIB_OBJECT int GetRaceButtonIndex(int);
	EQLIB_OBJECT void DoStatButton(int);
	EQLIB_OBJECT void FinalizeNewPCAndSendToWorld();
	EQLIB_OBJECT void Init();
	EQLIB_OBJECT void InitNewPC();
	EQLIB_OBJECT void InitStartingCities();
	EQLIB_OBJECT void InitStats(bool);
	EQLIB_OBJECT void RandomizeCharacter(bool, bool);
	EQLIB_OBJECT void RandomizeFacialFeatures();
	EQLIB_OBJECT void SelectedClassButton(int);
	EQLIB_OBJECT void SelectedRaceButton(int);
	EQLIB_OBJECT void SelectStartingCity(int);
	EQLIB_OBJECT void SetNewPCDeityFromBtnIndex(int);
	EQLIB_OBJECT void SetPlayerAppearanceFromNewPC();
	EQLIB_OBJECT void SubmitNameToWorld();
	EQLIB_OBJECT void UpdatePlayerFromNewPC();
	EQLIB_OBJECT void UpdateScreenZeroButtons(bool);
};

//============================================================================
// CCharacterListWnd
//============================================================================

class CCharacterListWnd : public CSidlScreenWnd, public PopDialogHandler, public WndEventHandler
{
public:
	CCharacterListWnd(CXWnd*);
	virtual ~CCharacterListWnd();

	virtual int Draw() override;
	virtual int OnProcessFrame() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT int IsEmptyCharacterSlot(int);
	EQLIB_OBJECT int IsValidCharacterSelected();
	EQLIB_OBJECT int NumberOfCharacters();
	EQLIB_OBJECT unsigned char IsEvil(int, int, int);
	EQLIB_OBJECT void DeleteCharacter();
	EQLIB_OBJECT void EnterExplorationMode();
	EQLIB_OBJECT void EnterWorld();
	EQLIB_OBJECT void LeaveExplorationMode();
	EQLIB_OBJECT void Quit();
	EQLIB_OBJECT void UpdateList(bool bForceUpdate = false);
	EQLIB_OBJECT void SelectCharacter(int charindex, bool bSwitchVisually = true, bool bForceUpdate = false /*dont mess with this*/);
	EQLIB_OBJECT void SetLoadZonePlayerLocation();
	EQLIB_OBJECT void SwitchModel(PlayerClient*, unsigned char, int, unsigned char, unsigned char);
	EQLIB_OBJECT void UpdateButtonNames();
	EQLIB_OBJECT void CreateExplorationModePlayers();
	EQLIB_OBJECT void EnableButtons(bool);
	EQLIB_OBJECT void EnableEqMovementCommands(bool);
	EQLIB_OBJECT void Init();
	EQLIB_OBJECT void RemoveExplorationModePlayers();
	EQLIB_OBJECT void SetLocationByClass(PlayerClient*, bool, int);
};

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

	/*0x000*/ CChatWindow* ChatWnd[MAX_CHAT_WINDOWS];

	// this is likely a class as a member variable
	/*0x080*/ void* ChatContainerWindow_vfTable;
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
	/*0x128*/ CChatWindow* ChannelMap[MAX_CHAT_FILTERS];       // channel map
	/*0x1a0*/ CContextMenu* pCM_MainMenu;
	/*0x1a4*/ int                ScrollbarIndex;
	/*0x1a8*/ CContextMenu* pCM_LanguageMenu;
	/*0x1ac*/ int                LanguageMenuIndex;
	/*0x1b0*/ CContextMenu* pCM_FilterMenu;
	/*0x1b4*/ int                FilterMenuIndex;
	/*0x1b8*/ int                ChatChannelFilterMenuIndex;
	/*0x1bc*/ int                MeleeFilterSubMenuIndex;
	/*0x1c0*/ int                SpellsFilterSubMenuIndex;
	/*0x1c4*/ CContextMenu* pCM_MeleeMenu;
	/*0x1c8*/ int                MeleeFilterMenuIndex;
	/*0x1cc*/ CContextMenu* pCM_SpellMenu;
	/*0x1d0*/ int                SpellsMenuIndex;
	/*0x1d4*/ CContextMenu* pCM_ChannelMenu;
	/*0x1d8*/ int                ChannelMenuIndex;
	/*0x1dc*/ CContextMenu* pCM_DefaultChannelMenu;
	/*0x1e0*/ int                DefaultChannelMenu;
	/*0x1e4*/ int                DefaultChannelMenu2;
	/*0x1e8*/ CContextMenu* pCM_ChatChannelDefChan;
	/*0x1ec*/ int                ChatChannelDefChanIndex;
	/*0x1f0*/ CContextMenu* pCM_YourHitsMenu;
	/*0x1f4*/ int                YourHitsMenuIndex;
	/*0x1f8*/ CContextMenu* pCM_YourMissesMenu;
	/*0x1fc*/ int                YourMissesMenuindex;
	/*0x200*/ CContextMenu* pCM_YouBeingHitMenu;
	/*0x204*/ int                YouBeingHitMenuindex;
	/*0x208*/ CContextMenu* pCM_OthersHitsMenu;
	/*0x20c*/ int                OthersHitsMenuindex;
	/*0x210*/ CContextMenu* pCM_OthersMissesMenu;
	/*0x214*/ int                OthersMissesMenuindex;
	/*0x218*/ CContextMenu* pCM_AllContextMenu;
	/*0x21c*/ int                AllContextMenuindex;
	/*0x220*/ CContextMenu* pCM_HitModesMenu;
	/*0x224*/ int                HitModesMenuindex;
	/*0x228*/ CContextMenu* pCM_ReplyToMenu;
	/*0x22c*/ int                ReplyToMenuindex;
	/*0x230*/ CContextMenu* pCM_TellFriendMenu;
	/*0x234*/ int                TellFriendMenuindex;
	/*0x238*/ CContextMenu* pCM_TellRaidmemberMenu;
	/*0x23c*/ int                TellRaidmemberMenuindex;
	/*0x240*/ int                ReplyToSubIndex;
	/*0x244*/ int                TellFriendSubIndex;
	/*0x248*/ int                TellRaidmemberSubIndex;
	/*0x24c*/ int                HitModes[MAX_HITMODES];
	/*0x26c*/ int                DefaultChannel;
	/*0x270*/ CContextMenu* pCM_RandomFilterMenu;
	/*0x274*/ int                RandomFilterIndex;
	/*0x278*/ int                RandomFilterSubIndex;
	/*0x27c*/ CContextMenu* pCM_EnvironmentalDamageMenu;
	/*0x280*/ int                EnvironmentalDamageIndex;
	/*0x284*/ int                EnvironmentalDamageSubIndex;
	/*0x288*/ CContextMenu* pCM_DamageShieldsFilterMenu;
	/*0x28c*/ int                DamageShieldsFilterIndex;
	/*0x290*/ int                DamageShieldsFilterSubIndex;
	/*0x294*/ CContextMenu* pCM_BeneficialSpellsFilterMenu;
	/*0x298*/ int                BeneficialSpellsFilteIndex;
	/*0x29c*/
};

using EQCHATMGR = CChatWindowManager;
using PEQCHATMGR = CChatWindowManager *;

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
	/*0x244*/ CEditWnd* InputWnd;
	/*0x248*/ CStmlWnd* OutputWnd;
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
using PEQCHATWINDOW = CChatWindow *;

//============================================================================
// CColorPickerWnd
//============================================================================

class CColorPickerWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CColorPickerWnd(CXWnd* pwndParent);

	virtual bool AboutToHide() override;
	virtual int WndNotification(CXWnd* pwndSender, uint32_t Msg, void* pData) override;
	virtual void OnWndNotification() override;

	EQLIB_OBJECT void CheckMaxEditWnd();
	EQLIB_OBJECT void SetCurrentColor(unsigned long);
	EQLIB_OBJECT void SetTemplateColor(int, unsigned long);
	EQLIB_OBJECT void UpdateCurrentColor();
	EQLIB_OBJECT void UpdateEditWndFromSlider(CSliderWnd* pSlider, CEditWnd* pEdit, int* value);
	EQLIB_OBJECT void UpdateSliderFromEditWnd(CSliderWnd* pSlider, CEditWnd* pEdit, int* value);
	EQLIB_OBJECT int Open(CXWnd* pwndCaller, D3DCOLOR CurrentColor = 0x00FFFFFF);

	//----------------------------------------------------------------------------
	// data members

	int                ContextMenuIndex;
	int                MaxSliderValue;
	CXWnd*             pwndCaller;
	CButtonWnd*        ColorButton[16];
	int                RedSliderValue;
	CSliderWnd*        RedSlider;
	CEditWnd*          RedSliderInputEdit;
	int                GreenSliderValue;
	CSliderWnd*        GreenSlider;
	CEditWnd*          GreenSliderInputEdit;
	int                BlueSliderValue;
	CSliderWnd*        BlueSlider;
	CEditWnd*          BlueSliderInputEdit;
	CButtonWnd*        AcceptButton;
};

//============================================================================
// CCombatAbilityWnd
//============================================================================

class CCombatAbilityWnd : public CSidlScreenWnd
{
public:
	CCombatAbilityWnd(CXWnd*);
	virtual ~CCombatAbilityWnd();
};

//============================================================================
// CCombatSkillsSelectWnd
//============================================================================

class CCombatSkillsSelectWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CCombatSkillsSelectWnd(CXWnd*);
	virtual ~CCombatSkillsSelectWnd();

	EQLIB_OBJECT bool ShouldDisplayThisSkill(int);
};

//============================================================================
// CCompassWnd
//============================================================================

// size 0x180 3-10-2004
class CCompassWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	EQLIB_OBJECT CCompassWnd(CXWnd*);
	virtual ~CCompassWnd();

	virtual int Draw() override;
	virtual int OnProcessFrame() override;

	EQLIB_OBJECT void SenseHeading();
	EQLIB_OBJECT void PickNewTarget();
	EQLIB_OBJECT void SetSpeed();

	//----------------------------------------------------------------------------
	// data members

	/*0x148*/ CStaticAnimationTemplate* pStrip1;
	/*0x14C*/ CStaticAnimationTemplate* pStrip2;
	// WIP
	/*0x16C*/ BOOL         DrawLine;
	/*0x170*/ DWORD        Unknown0x170;
	/*0x174*/ DWORD        LineRed;
	/*0x178*/ DWORD        LineGreen;
	/*0x17C*/ DWORD        LineBlue;
	/*0x180*/
};
using EQCOMPASSWINDOW = CCompassWnd;
using PEQCOMPASSWINDOW = CCompassWnd*;

//============================================================================
// CConfirmationDialog
//============================================================================

// This is actually CPopDialogWnd.
// TODO: Rename this
class CConfirmationDialog : public CSidlScreenWnd
{
public:
	CConfirmationDialog(CXWnd*);
	virtual ~CConfirmationDialog();

	virtual int Draw() override;
	virtual int OnProcessFrame() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	// probably wrong
	virtual void Activate(PopDialogHandler* handler, int msg, const char* text,
		int, int, int, int);

	// this is all invalid
	//EQLIB_OBJECT void HandleButtonNoPressed();
	//EQLIB_OBJECT void HandleButtonOkPressed();
	//EQLIB_OBJECT void HandleButtonYesPressed();
	//EQLIB_OBJECT void ProcessNo(int);
	//EQLIB_OBJECT void ProcessYes();
	//EQLIB_OBJECT void SetNameApprovalData(char*, char*, int, int, char*);
	//EQLIB_OBJECT void ExpireCurrentDialog();
	//EQLIB_OBJECT void ResetFocusOnClose();

	// Data members
/*0x15c*/ CStmlWnd*    OutputText;
/*0x160*/ CButtonWnd*  pYesButton;
/*0x164*/ CButtonWnd*  pNoButton;
/*0x168*/ CButtonWnd*  pCancelButton;
/*0x16c*/ CButtonWnd*  pOKButton;
/*0x170*/ BYTE         Unknown0x170[0x18];
/*0x188*/
};

//============================================================================
// CContainerWnd
//============================================================================

class CContainerWnd : public CSidlScreenWnd
{
public:
	CContainerWnd(CXWnd*);
	virtual ~CContainerWnd();

	virtual int OnProcessFrame() override;
	virtual int PostDraw() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT void CheckCloseable();
	EQLIB_OBJECT void SetContainer(PCONTENTS &pContainer, const ItemGlobalIndex& location);
	EQLIB_OBJECT bool ContainsNoDrop();
	EQLIB_OBJECT void HandleCombine();

	// TODO: Fix for inaccuracies
/*0x240*/ CONTENTS*     pContents;
/*0x244*/ ItemGlobalIndex Location;
/*0x24x*/ VeArray<CInvSlotWnd*> InvSlotWnds;
/*0x18*/ CButtonWnd*   pCombineButton;
/*0x1c*/ CButtonWnd*   pDoneButton;
/*0x20*/ CButtonWnd*   pStandardDoneButton;
/*0x24*/ CButtonWnd*   pCombineDoneButton;
/*0x28*/ CButtonWnd*   pContainerIcon;
/*0x2c*/ CButtonWnd*   pContainerStandardIcon;
/*0x30*/ CButtonWnd*   pContainerCombineIcon;
/*0x34*/ CTextureAnimation* pIconAnimation;
/*0x38*/ CLabel*       ContainerLabel;
/*0x3c*/ CInvSlotWnd*  pContainerSlotTemplate;
/*0x40*/ CXWnd*        pStandardItems;
/*0x44*/ CXWnd*        pStandardItemsWithDone;
/*0x48*/ CXWnd*        pCombineItems;
/*0x4c*/ CStmlWnd*     pStandardSize;
/*0x50*/ CStmlWnd*     pCombineSize;
/*0x54*/ bool          bCombineValid;
/*0x55*/ bool          bUserCloseable;
/*0x58*/ int           ContainerType;            // classic = 0, standard = 1, combine = 2
/*0x5c*/ int           IndexDoneButton;
/*0x60*/ CContextMenu* ContextMenu;
/*0x64*/

#if 0 // old stuff
/*0x000*/ CSIDLWND     Wnd;
/*0x148*/ CONTENTS* pContents;                // Pointer to the contents of the container;
												 // Matches the pointer in CHARINFO.Inventory/Bank/World
/*0x14c*/ CSIDLWND* pSlots[0x0a];
/*0x000*/ CSIDLWND* pCombine;
/*0x168*/ CSIDLWND* pDone;
/*0x16c*/ CSIDLWND* pIcon;
/*0x170*/ CSIDLWND* pUnknown;
/*0x174*/ CSIDLWND* pLabel;
/*0x178*/ BYTE         Unknown0x178[4];
/*0x17c*/
#endif
};
using EQCONTAINERWINDOW = CContainerWnd;
using PEQCONTAINERWINDOW = CContainerWnd *;

class CContainerMgr
{
public:
	CContainerMgr();
	virtual ~CContainerMgr();

	EQLIB_OBJECT bool CloseAllContainers();
	EQLIB_OBJECT EQ_Item* GetWorldContainerItem(int);
	EQLIB_OBJECT void ClearWorldContainerItems();
	EQLIB_OBJECT void CloseContainer(EQ_Container*, bool);
	EQLIB_OBJECT void CloseEQContainer(EQ_Container*);
	EQLIB_OBJECT void OpenContainer(EQ_Container*, int, bool);
	EQLIB_OBJECT void OpenWorldContainer(EQ_Container*, unsigned long);
	EQLIB_OBJECT void Process();
	EQLIB_OBJECT void SetWorldContainerItem(EQ_Item*, int);
	EQLIB_OBJECT CContainerWnd* GetFreeContainerWnd();
	EQLIB_OBJECT void OpenExperimentContainer(const VePointer<CONTENTS>& pCont, const ItemGlobalIndex& Location);

	//----------------------------------------------------------------------------
	// data members

	CContainerWnd* pContainerWnds[38];
	ArrayClass<CContainerWnd*> ContainerWndsToDelete;
	VePointer<CONTENTS> pWorldContainer;
	DWORD              WorldContainerSerialNumber;
	int                WorldContainerRealEstateID;
	int                WorldContainerRealEstateItemID;
	DWORD              Timer;
	bool               bShowDone;
};


//============================================================================
// CContextMenuManager
//============================================================================

#define MAX_CONTEXT_MENU_DEPTH 8
#define MAX_CONTEXT_MENUS 1024

// combination of CContexTMenuManager and CContextMenuManagerBase
class CContextMenuManager : public CXWnd
{
public:
	CContextMenuManager(CXWnd*, uint32_t, const CXRect&);
	virtual ~CContextMenuManager();

	virtual int HandleLButtonDown(const CXPoint&, uint32_t) override;
	virtual int HandleRButtonDown(const CXPoint&, uint32_t) override;
	virtual int HandleWheelButtonDown(const CXPoint&, uint32_t) override;
	virtual int OnProcessFrame() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	virtual void CreateDefaultMenu();
	virtual int HandleWindowMenuCommands(CXWnd*, int);

	EQLIB_OBJECT int AddMenu(CContextMenu*);
	EQLIB_OBJECT int GetDefaultMenuIndex() { return DefaultMenuIndex; }
	EQLIB_OBJECT CContextMenu*GetMenu(int);
	EQLIB_OBJECT int PopupMenu(int, const CXPoint&, CXWnd*);
	EQLIB_OBJECT int RemoveMenu(int, bool);
	EQLIB_OBJECT void Flush();
	EQLIB_OBJECT void WarnDefaultMenu(CXWnd*);

	//----------------------------------------------------------------------------
	// data members

	CXWnd*             pParentMenuWnd;
	CContextMenu*      pCurrMenus[MAX_CONTEXT_MENU_DEPTH];
	int                NumVisibleMenus;
	int                CurrMenu;
	CContextMenu*      pMenus[MAX_CONTEXT_MENUS];
	int                NumMenus;
	CXWnd*             pHandlerWnd;
	int                HandlerCmd;
	int                DefaultMenuIndex;
	int                DefaultHelpItem;
	int                DefaultBGItem;
	int                DefaultMinItem;
	int                DefaultCloseItem;
	int                DefaultLockItem;
	int                DefaultEscapeItem;
};

//============================================================================
// CContextMenu
//============================================================================

// Size is 0x290 in eagame 2016 Nov 14
class CContextMenu : public CListWnd
{
public:
	EQLIB_OBJECT CContextMenu(CXWnd* pParent, uint32_t MenuID, const CXRect& rect);
	EQLIB_OBJECT virtual ~CContextMenu();

	virtual int OnKillFocus(CXWnd*) override;

	// MenuID: Set HighPart as the ID for submenus and LowPart is then the subindex
	EQLIB_OBJECT int AddMenuItem(const CXStr& str, unsigned int MenuID, bool bChecked = false, COLORREF Color = 0xFFFFFFFF, bool bEnable = true);
	EQLIB_OBJECT int AddSeparator();
	EQLIB_OBJECT void Activate(CXPoint, int, int);
	EQLIB_OBJECT void CheckMenuItem(int ID, bool bVal = true, bool bUncheckAll = false);
	EQLIB_OBJECT void EnableMenuItem(int ID, bool bVal = true);
	EQLIB_OBJECT void RemoveAllMenuItems();
	EQLIB_OBJECT void RemoveMenuItem(int id);
	EQLIB_OBJECT void SetMenuItem(int ID, const CXStr& Str, bool bChecked = false, COLORREF Color = 0xFFFFFFFF, bool bEnable = true);

	EQLIB_OBJECT int InsertMenuItem(const CXStr& str, unsigned int position, unsigned int ItemID,
		bool bChecked, COLORREF Color, bool bEnable);

	//----------------------------------------------------------------------------
	// data members

/*0x288*/ int          NumItems;
/*0x28C*/ int          Unknown0x28C;
/*0x290*/
};

//============================================================================
// CCursorAttachment
//============================================================================

class CCursorAttachment : public CSidlScreenWnd, public WndEventHandler
{
public:
	CCursorAttachment(CXWnd*);
	virtual ~CCursorAttachment();

	virtual int Draw() override;
	virtual int OnProcessFrame() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;
	virtual void Deactivate() override;

	EQLIB_OBJECT bool IsOkToActivate(int);
	EQLIB_OBJECT bool RemoveAttachment();
	EQLIB_OBJECT void DrawButtonText() const;
	EQLIB_OBJECT void DrawQuantity() const;

	EQLIB_OBJECT void AttachToCursor(CTextureAnimation* Overlay, CTextureAnimation* pTABG, int Type, int Index,
		const char* Assigned_Name, const char* Name, int Qty = -1, int IconID = -1);
	EQLIB_OBJECT void AttachToCursor(CTextureAnimation* Overlay, CTextureAnimation* pTABG, int Type, int Index,
		const EqItemGuid& ItemGuid, int ItemID, const char* Assigned_Name, const char* Name, int Qty = -1, int IconID = -1);

	//----------------------------------------------------------------------------
	// data members

/*0x224*/ int          Type;
/*0x228*/ int          Index;
/*0x22c*/ EqItemGuid   ItemGuid;
/*0x240*/ int          ItemID;
/*0x244*/ int          Qty;
/*0x248*/ CXStr        ButtonText;
	// and more...
};

//============================================================================
// CExtendedTargetWnd
//============================================================================

class CExtendedTargetWnd : public CSidlScreenWnd
{
public:
};

//============================================================================
// CFactionWnd
//============================================================================

// CFactionWnd__CFactionWnd_x aFactionwnd
// CFactionWnd__size: 0x288 (see 5432A4) in May 17 2019 Test
class CFactionWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CFactionWnd(CXWnd*);
	virtual ~CFactionWnd();

	//----------------------------------------------------------------------------
	// data members

/*0x244*/ bool         bUnknown0x0244;
/*0x248*/ int          Unknown0x0248;
/*0x24c*/ int          Unknown0x024c;
/*0x250*/ int          Unknown0x0250;
/*0x254*/ SoeUtil::IString Unknown0x0254;
/*0x264*/ SoeUtil::IString Unknown0x0264;
/*0x274*/ CGaugeWnd*   StandingGaugeTemplate;
/*0x278*/ CTreeView*   Categories;
/*0x27c*/ CEditWnd*    SearchNameInput;
/*0x280*/ CButtonWnd*  SearchButton;
/*0x284*/ CListWnd*    FactionList;
/*0x288*/
};
using EQFACTIONWINDOW = CFactionWnd;
using PEQFACTIONWINDOW = CFactionWnd *;

//============================================================================
// CFacePick
//============================================================================

// todo: actually CPlayerCustomizationWnd
class CFacePick : public CSidlScreenWnd
{
public:
	EQLIB_OBJECT CFacePick(CXWnd*);
	EQLIB_OBJECT void SetFaceSelectionsFromPlayer();

	// virtual
	EQLIB_OBJECT ~CFacePick();
	EQLIB_OBJECT int Draw() const;
	EQLIB_OBJECT int OnProcessFrame();
	EQLIB_OBJECT int WndNotification(CXWnd*, uint32_t, void*);

	// private
	EQLIB_OBJECT void CycleThroughFHEB(int, int);
	EQLIB_OBJECT void ShowButtonGroup(int, bool);
};

//============================================================================
// CFindItemWnd
//============================================================================

class CFindItemWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CFindItemWnd(CXWnd*);
	virtual ~CFindItemWnd();

	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT void Update();
	EQLIB_OBJECT void PickupSelectedItem();

/*0x234*/ CComboWnd*   SearchCombo0;
/*0x238*/ CComboWnd*   SearchCombo1;
/*0x23c*/ int          SelIndex;
/*0x240*/ VeArray<ItemGlobalIndex*> gi;
/*0x24c*/ int          Unknown0x24c;
/*0x250*/ int          Unknown0x250;
/*0x254*/ int          Unknown0x254;
/*0x258*/ int          Unknown0x258;
/*0x25c*/ int          Unknown0x25c;
/*0x260*/ int          FIW_ClassAnim;
/*0x264*/ CSidlScreenWnd* FIW_CharacterView;
/*0x268*/ CListWnd*    FIW_ItemList;
/*0x26c*/ CButtonWnd*  FIW_QueryButton;
/*0x270*/ CButtonWnd*  FIW_RequestItemButton;
/*0x274*/ CButtonWnd*  FIW_RequestPreviewButton;
/*0x278*/ CButtonWnd*  FIW_Default;
/*0x27c*/ CButtonWnd*  FIW_GrabButton;
/*0x280*/ CButtonWnd*  FIW_HighlightButton;
/*0x284*/ CButtonWnd*  FIW_DestroyItem;
/*0x288*/ CComboWnd*   FIW_ItemLocationCombobox;
/*0x28c*/ CComboWnd*   FIW_ItemSlotCombobox;
/*0x290*/ CComboWnd*   FIW_StatSlotCombobox;
/*0x294*/ CComboWnd*   FIW_RaceSlotCombobox;
/*0x298*/ CComboWnd*   FIW_ClassSlotCombobox;
/*0x29c*/ CComboWnd*   FIW_ItemTypeCombobox;
/*0x2a0*/ CComboWnd*   FIW_ItemPrestigeCombobox;
/*0x2a4*/ CComboWnd*   FIW_ItemAugmentCombobox;
/*0x2a8*/ CEditWnd*    FIW_ItemNameInput;
/*0x2ac*/ CEditWnd*    FIW_MaxLevelInput;
/*0x2b0*/ CEditWnd*    FIW_MinLevelInput;
/*0x2b4*/ CEditWnd*    Unknown0x2b4;
/*0x2B8*/
};

//============================================================================
// CFindLocationWnd
//============================================================================

class CFindLocationWnd : public CSidlScreenWnd
{
public:
	// has virtuals, but we get those from CSidlScreenWnd
	EQLIB_OBJECT bool HandleFindBegin();
	EQLIB_OBJECT void HandleFindEnd();
	EQLIB_OBJECT void HandleRowClicked(int Index);
	EQLIB_OBJECT void HandleFindableZoneConnectionsMessage(CUnSerializeBuffer& buf);
};

//============================================================================
// CFileSelectionWnd
//============================================================================

class CFileSelectionWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CFileSelectionWnd(CXWnd*);
	virtual ~CFileSelectionWnd();

	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT CXStr GetSelectedFile(int);
	EQLIB_OBJECT int GetSelectedFileCount();
	EQLIB_OBJECT void Callback(bool);
	EQLIB_OBJECT bool DirectoryEmpty(IShellFolder*, LPITEMIDLIST);
	EQLIB_OBJECT unsigned long GetPath(IShellFolder*, LPITEMIDLIST, bool, CXStr&);
	EQLIB_OBJECT void ClearFileList();
	EQLIB_OBJECT void GoSubdirectory(LPITEMIDLIST);
	EQLIB_OBJECT void MakeFilePath();
	EQLIB_OBJECT void UpdateButtons();
	EQLIB_OBJECT void UpdateFileList();
};

//============================================================================
// CFriendsWnd
//============================================================================

class CFriendsWnd : public CSidlScreenWnd
{
public:
	CFriendsWnd(CXWnd*);
	virtual ~CFriendsWnd();

	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT void UpdateFriendsList();
	EQLIB_OBJECT void UpdateIgnoreList();
	EQLIB_OBJECT void AddFriend();
	EQLIB_OBJECT void AddIgnore();
	EQLIB_OBJECT void UpdateButtons();
};

//============================================================================
// CGemsGameWnd
//============================================================================

struct GemsBlock;

class CGemsGameWnd : public CSidlScreenWnd
{
public:
	EQLIB_OBJECT CGemsGameWnd(CXWnd*);
	virtual ~CGemsGameWnd();

	virtual int HandleLButtonUp(const CXPoint&, uint32_t) override;
	virtual int OnProcessFrame() override;
	virtual int PostDraw() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT void MoveCurBlock(int);
	EQLIB_OBJECT bool BadSpecial(int) const;
	EQLIB_OBJECT bool LegalBlockMove(int, int, int, int, bool);
	EQLIB_OBJECT int GetRndBlockImage();
	EQLIB_OBJECT void ActivateSpecialMode(int);
	EQLIB_OBJECT void AdvanceToNextWave();
	EQLIB_OBJECT void CheckForMatches(int, int);
	EQLIB_OBJECT void CheckForNewHighScore();
	EQLIB_OBJECT void ClearBlock(GemsBlock*);
	EQLIB_OBJECT void ClearHighScores();
	EQLIB_OBJECT void DoMatchScore(int);
	EQLIB_OBJECT void DrawSpellGem(int, const CXRect&, int, bool) const;
	EQLIB_OBJECT void GetNextBlock();
	EQLIB_OBJECT void MakeBlockDrop(int, int, int);
	EQLIB_OBJECT void MarkHigherBlocksFalling(int, int);
	EQLIB_OBJECT void ProcessMatches(int);
	EQLIB_OBJECT void ProcessMoveCurBlock(int);
	EQLIB_OBJECT void ReadHighScores();
	EQLIB_OBJECT void Restart();
	EQLIB_OBJECT void SetNextUpdate();
	EQLIB_OBJECT void SetPause(bool);
	EQLIB_OBJECT void TogglePause();
	EQLIB_OBJECT void Update();
	EQLIB_OBJECT void UpdateDisplay();
	EQLIB_OBJECT void WriteHighScores();
};

//============================================================================
// CGiveWnd
//============================================================================

class CGiveWnd : public CSidlScreenWnd, public PopDialogHandler, public WndEventHandler
{
public:
	CGiveWnd(CXWnd*);
	virtual ~CGiveWnd();

	virtual int OnProcessFrame() override;
	virtual int PostDraw() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT void UpdateGiveDisplay();

	//----------------------------------------------------------------------------
	// data members

	CButtonWnd*    pMoneyButton[4];
	CButtonWnd*    TradeButton;
	CButtonWnd*    CancelButton;
	CLabel*        NPCNameLabel;
	CInvSlotWnd*   pInvSlotWnd[4];
};

//============================================================================
// CGroupSearchFiltersWnd
//============================================================================

// todo: not mapped or cleaned up
class CGroupSearchFiltersWnd : public CSidlScreenWnd
{
public:
	EQLIB_OBJECT CGroupSearchFiltersWnd(CXWnd*);
	EQLIB_OBJECT bool ShouldFilterPlayer(const char*, const char*) const;
	EQLIB_OBJECT bool UseExclusiveSearchMode() const;
	EQLIB_OBJECT void HandleAddDesiredGuild();
	EQLIB_OBJECT void HandleAddExcludedGuild();
	EQLIB_OBJECT void HandleDesiredGuildsSelected();
	EQLIB_OBJECT void HandleExcludeGuildsSelected();
	EQLIB_OBJECT void HandleRemoveAllDesiredGuilds();
	EQLIB_OBJECT void HandleRemoveAllExcludedGuilds();
	EQLIB_OBJECT void HandleRemoveDesiredGuild();
	EQLIB_OBJECT void HandleRemoveExcludedGuild();
	EQLIB_OBJECT void HandleUseFriendsListSelected();
	EQLIB_OBJECT void HandleUseIgnoreListSelected();

	// virtual
	EQLIB_OBJECT ~CGroupSearchFiltersWnd();
	EQLIB_OBJECT int OnProcessFrame();
	EQLIB_OBJECT int WndNotification(CXWnd*, uint32_t, void*);

	// private
	EQLIB_OBJECT bool GuildIsInDesiredGuildsList(const char*) const;
	EQLIB_OBJECT bool GuildIsInExcludedGuildsList(const char*) const;
	EQLIB_OBJECT bool Load();
	EQLIB_OBJECT bool NameIsInFriendsList(const char*) const;
	EQLIB_OBJECT bool NameIsInIgnoreList(const char*) const;
	EQLIB_OBJECT bool UseDesiredGuilds() const;
	EQLIB_OBJECT bool UseExcludedGuilds() const;
	EQLIB_OBJECT bool UseFriendsList() const;
	EQLIB_OBJECT bool UseIgnoreList() const;
	EQLIB_OBJECT void ClearUiPointers();
	EQLIB_OBJECT void FetchUiPointers();
	EQLIB_OBJECT void InitPieces();
	EQLIB_OBJECT void Save() const;
};

//============================================================================
// CGroupSearchWnd
//============================================================================

struct LfgGroupResult;
class SListWndSortInfo;
struct LfgPlayerData;
struct LfgPlayerResult;

// todo: not mapped or cleaned up
class CGroupSearchWnd : public CSidlScreenWnd
{
public:
	EQLIB_OBJECT CGroupSearchWnd(CXWnd*);
	EQLIB_OBJECT void AddGroupResult(const LfgGroupResult*);
	EQLIB_OBJECT void AddPlayerResult(const LfgPlayerResult*);
	EQLIB_OBJECT void HandleDeselectAllClasses();
	EQLIB_OBJECT void HandleDoubleClickedOnPlayer(const char*);
	EQLIB_OBJECT void HandleGroupInfoPost();
	EQLIB_OBJECT void HandleGroupInfoRemove();
	EQLIB_OBJECT void HandleGroupInfoUpdate();
	EQLIB_OBJECT void HandleGroupMakeupChanged();
	EQLIB_OBJECT void HandleGroupResultColSelected(int);
	EQLIB_OBJECT void HandleGroupResultRowSelected(int);
	EQLIB_OBJECT void HandleNumericSort(SListWndSortInfo*);
	EQLIB_OBJECT void HandleOpenFiltersWindow();
	EQLIB_OBJECT void HandlePlayerInfoPost();
	EQLIB_OBJECT void HandlePlayerInfoRemove();
	EQLIB_OBJECT void HandlePlayerInfoUpdate();
	EQLIB_OBJECT void HandlePlayerResultColSelected(int);
	EQLIB_OBJECT void HandleQueryingForGroups();
	EQLIB_OBJECT void HandleQueryingForPlayers();
	EQLIB_OBJECT void HandleSelectAllClasses();
	EQLIB_OBJECT void ResetGroupList();
	EQLIB_OBJECT void ResetPlayerList();
	EQLIB_OBJECT void SendServerLfgOff();
	EQLIB_OBJECT void SendServerLfgOn();
	EQLIB_OBJECT void SendServerLfpOff();
	EQLIB_OBJECT void SendServerLfpOn();

	// virtual
	EQLIB_OBJECT ~CGroupSearchWnd();
	EQLIB_OBJECT int OnProcessFrame();
	EQLIB_OBJECT int WndNotification(CXWnd*, uint32_t, void*);

	// private
	EQLIB_OBJECT bool IsLevelRangeValid(int, int) const;
	EQLIB_OBJECT bool PlayerShouldBeFiltered(const LfgPlayerData*) const;
	EQLIB_OBJECT int CheckIfCurrentLfgInfoIsValid() const;
	EQLIB_OBJECT int CheckIfCurrentLfpInfoIsValid() const;
	EQLIB_OBJECT int GetDesiredClassesFlag() const;
	EQLIB_OBJECT int GetDesiredGroupMaxLevel() const;
	EQLIB_OBJECT int GetDesiredGroupMinLevel() const;
	EQLIB_OBJECT int GetDesiredPlayerMaxLevel() const;
	EQLIB_OBJECT int GetDesiredPlayerMinLevel() const;
	EQLIB_OBJECT int GetEqClassType(int) const;
	EQLIB_OBJECT int GroupInfoPageOnProcessFrame();
	EQLIB_OBJECT int GroupInfoPageWndNotification(CXWnd*, uint32_t, void*);
	EQLIB_OBJECT int GroupListPageOnProcessFrame();
	EQLIB_OBJECT int GroupListPageWndNotification(CXWnd*, uint32_t, void*);
	EQLIB_OBJECT int PlayerInfoPageOnProcessFrame();
	EQLIB_OBJECT int PlayerInfoPageWndNotification(CXWnd*, uint32_t, void*);
	EQLIB_OBJECT int PlayerListPageOnProcessFrame();
	EQLIB_OBJECT int PlayerListPageWndNotification(CXWnd*, uint32_t, void*);
	EQLIB_OBJECT int RedirectOnProcessFrameTo(CPageWnd*);
	EQLIB_OBJECT int RedirectWndNotificationTo(CPageWnd*, CXWnd*, uint32_t, void*);
	EQLIB_OBJECT void ClearUiPointers();
	EQLIB_OBJECT void FetchUiPointers();
	EQLIB_OBJECT void FilterOutBadWords(const char*, char*) const;
	EQLIB_OBJECT void GetDefaultLfgLevelRange(EQ_PC const*, int*, int*) const;
	EQLIB_OBJECT void GetDefaultLfpLevelRange(EQ_PC const*, int*, int*) const;
	EQLIB_OBJECT void InitLfg();
	EQLIB_OBJECT void InitLfp();
	EQLIB_OBJECT void LockQueryButtonAtTime(long);
	EQLIB_OBJECT void PopUpErrorMessage(int) const;
	EQLIB_OBJECT void ShowGroupDetails(LfgGroupResult const*);
	EQLIB_OBJECT void UpdateGroupLabel();
	EQLIB_OBJECT void UpdateLfgPostingStatus();
	EQLIB_OBJECT void UpdateLfpPostingStatus();
	EQLIB_OBJECT void UpdatePlayerLabel();
	EQLIB_OBJECT void UpdateRemainingQueryLockedTime(long);
};

//============================================================================
// CGroupWnd
//============================================================================

// Sep 21 2018
class CGroupWnd : public CSidlScreenWnd
{
public:
	CGroupWnd(CXWnd*);
	virtual ~CGroupWnd();

	virtual int Draw() override;
	virtual int OnProcessFrame() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;
	virtual void LoadIniInfo() override;
	virtual void StoreIniInfo() override;

	EQLIB_OBJECT void CreateLocalMenu();
	EQLIB_OBJECT void KeyMapUpdated();
	EQLIB_OBJECT void SetInvited(bool);
	EQLIB_OBJECT void UpdateContextMenu();

	EQLIB_OBJECT void UpdateButtons();
	EQLIB_OBJECT void UpdateDisplay(int Index, PSPAWNINFO groupmember, COLORREF NameColor, UINT RoleBits);

	//----------------------------------------------------------------------------
	// data members
	CButtonWnd*        InviteButton;
	CButtonWnd*        DisbandButton;
	CButtonWnd*        FollowButton;
	CButtonWnd*        DeclineButton;
	CButtonWnd*        LFGButton;
	CGaugeWnd*         HPGauge[6];
	CGaugeWnd*         PetGauge[6];
	CGaugeWnd*         ManaGauge[6];
	CGaugeWnd*         EnduranceGauge[6];
	CLabel*            HPLabel[6];
	CLabel*            HPPercLabel[6];
	CLabel*            ManaLabel[6];
	CLabel*            ManaPercLabel[6];
	CLabel*            EnduranceLabel[6];
	CLabel*            EndurancePercLabel[6];
	COLORREF           HPTextColor[6];
	CButtonWnd*        GroupTankButton[6];
	CButtonWnd*        GroupAssistButton[6];
	CButtonWnd*        GroupPullerButton[6];
	CButtonWnd*        GroupMarkNPCButton[6];
	CLabel*            AggroPercLabel[6];
	long               Timer;
	CContextMenu*      GroupContextMenu;
	bool               bPetbars;
	bool               bManabars;
	bool               bEndurancebars;
	bool               bAggroPct;
	int                PetBarIndex;
	int                ManaBarIndex;
	int                EnduranceBarIndex;
	int                AggroPctIndex;
	int                RoleSeparatorID;
	int                RoleSelectMenu;
	int                RoleSelectMenuID;
	bool               bPlayerInvited;
};

//============================================================================
// CGuildMgmtWnd
//============================================================================

// todo: update, some of this is obsolete
struct GuildMember
{
/*0x000*/ GuildMember* next;
/*0x004*/ bool         OnlineStatus;
/*0x008*/ uint8_t      Unknown0x008[0x8];
/*0x010*/ char         Name[0x40];
/*0x050*/ int          Level;
/*0x054*/ int          Class;
/*0x058*/ int          Rank;                     // 0=member, 1=officer, 2=leader
/*0x05c*/ float        UnknownData0x05c;
/*0x060*/ char         PublicNote[0x80];
/*0x0e0*/ BYTE         Unknown0x0e0[0x180];
/*0x260*/ WORD         UnknownData0x260;
/*0x262*/ WORD         UnknownData0x262;
/*0x264*/ WORD         UnknownData0x264;
/*0x266*/ WORD         UnknownData0x266;
};
using GUILDMEMBERINFO = GuildMember;
using PGUILDMEMBERINFO = GuildMember *;


// Size: 0x3d0 (02/18/2004)
class CGuildMgmtWnd
	: public CSidlScreenWnd
	, public PopDialogHandler
	, public WndEventHandler
	, public CVivoxObserver
{
public:
	CGuildMgmtWnd(CXWnd*);
	virtual ~CGuildMgmtWnd();

	virtual int OnProcessFrame() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT void AddMember(GuildMember*);
	EQLIB_OBJECT void Clean();
	EQLIB_OBJECT void DumpToFile(char*);
	EQLIB_OBJECT void RemoveMember(GuildMember*);
	EQLIB_OBJECT void RenameMember(char*, char*);
	EQLIB_OBJECT void SetMOTD(char*, char*);
	EQLIB_OBJECT void SetPlayerCount(int);
	EQLIB_OBJECT void SortList(int, bool);
	EQLIB_OBJECT void UpdateButtons();
	EQLIB_OBJECT void UpdateListMember(GuildMember*, int);
	EQLIB_OBJECT char* GetPersonalNote(char*);
	EQLIB_OBJECT int FindListMember(GuildMember*);
	EQLIB_OBJECT void CleanAndRefillListWnd(bool);
	EQLIB_OBJECT void CreatePersonalNotesFilename();
	EQLIB_OBJECT void LoadINI();
	EQLIB_OBJECT void LoadPersonalNotes();
	EQLIB_OBJECT void SavePersonalNotes();
	EQLIB_OBJECT void SetPersonalNote(char*, char*);

	//----------------------------------------------------------------------------
	// data members

	// this is all out of date and needs updating
/*0x250*/ // start

/*0x148*/ BYTE         Unknown0x148[0x3c];
/*0x194*/ BYTE         Unknown0x194;
/*0x195*/ BYTE         ShowOffline;              // 01 = show offline box is checked
/*0x196*/ BYTE         Unknown0x196[0x2];

	// This is a pointer to the beginning of a list of pointers, each representing one player in
	// the guild. The number of  pointers depends upon TotalMemberCount.
/*0x198*/ GUILDMEMBERINFO** pMember;
/*0x19c*/ DWORD        TotalMemberCount;
/*0x1a0*/ DWORD        Unknown0x1a0;             // 150?
/*0x1a4*/ DWORD        Unknown0x1a4;             // 1?
/*0x1a8*/ DWORD        TotalMemberCountAgain;
/*0x1ac*/ BYTE         Unknown0x1ac[0x1c];
/*0x1c8*/ CHAR         PersonalNotesFilePath[0x40]; // path to personal notes file
/*0x208*/ BYTE         Unknown0x208[0x1c0];      // empty
/*0x3c8*/ DWORD        Unknown0x3c8;             // 1?
/*0x3cc*/ DWORD        Unknown0x3cc;             // some sort of bizaare pointer...
/*0x3d0*/
};
using EQGUILDWINDOW = CGuildMgmtWnd;
using PEQGUILDWINDOW = CGuildMgmtWnd*;

//============================================================================
// CHelpWnd
//============================================================================

class CHelpWnd : public CSidlScreenWnd
{
public:
	CHelpWnd(CXWnd*);
	virtual ~CHelpWnd();

	virtual int HandleKeyboardMsg(uint32_t, uint32_t, bool) override;
	virtual int OnProcessFrame() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT void SetFile(CXStr);
};

//============================================================================
// CHtmlWnd
//============================================================================

namespace libMozilla {

class Window
{
public:
	EQLIB_OBJECT float getProgress(bool& bIsLoading);
	EQLIB_OBJECT const wchar_t* getStatus() const;
	EQLIB_OBJECT const char* getURI() const;
};

class ICallback
{
public:
	EQLIB_OBJECT virtual void onURIChanged(Window*) = 0;
	EQLIB_OBJECT virtual void onProgressChanged(Window*) = 0;
	EQLIB_OBJECT virtual void onStatusChanged(Window*) = 0;
	EQLIB_OBJECT virtual void doValidateURI(Window*, const char*) = 0;
};

} // namepsace libMozilla

class CHtmlComponentWnd
	: public CXWnd
	, public libMozilla::ICallback
	, public CObservable
{
public:
	CHtmlComponentWnd(CXWnd* parent, uint32_t id, CXRect rect, CXStr startURI = "");
	virtual ~CHtmlComponentWnd();

	libMozilla::Window* m_mozillaWnd;

	// more ...
};

class CHtmlWnd : public CSidlScreenWnd, public TListNode<CHtmlWnd>
{
public:
	CHtmlWnd(const char* uri, const char* postData, const char* windowId, bool byPassfilter = false, const char* title = nullptr);
	virtual ~CHtmlWnd();

	EQLIB_OBJECT void SetClientCallbacks(libMozilla::ICallback* cb);
	EQLIB_OBJECT void AddObserver(IObserver* observer);
	EQLIB_OBJECT void RemoveObserver(IObserver* observer);

	const CHtmlWnd* GetNextHtmlWnd() const { return TListNode<CHtmlWnd>::GetNext(); }
	CHtmlWnd* GetNextHtmlWnd() { return TListNode<CHtmlWnd>::GetNext(); }

	CHtmlComponentWnd*       pHtmlComponentMain;
	CButtonWnd*              pBackBtn;
	CButtonWnd*              pForwardBtn;
	CGaugeWnd*               pProgressGauge;
	CLabelWnd*               pStatusLabel;
	CXStr                    WindowID;
};

class CWebManager
{
public:
	EQLIB_OBJECT CHtmlWnd* CreateHtmlWnd(const char* uri, const char* windowId, const char* postBuffer = nullptr,
		bool bypassFilter = false, const char* titleOverride = nullptr);

	EQLIB_OBJECT CHtmlWnd* GetHtmlWnd(const char* windowId);

	TList<CHtmlWnd>             m_htmlWndList;
};

//============================================================================
// CHotButtonWnd
//============================================================================

// Actual size 0x1c4 10-9-2003
class CHotButtonWnd : public CSidlScreenWnd, public PopDialogHandler
{
public:
	CHotButtonWnd(CXWnd*);
	virtual ~CHotButtonWnd();

	virtual int Draw() override;
	virtual int OnProcessFrame() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT void DoHotButton(int Button, int AllowAutoRightClick, int something);
	EQLIB_OBJECT void DoHotButtonRightClick(int);
	EQLIB_OBJECT void UpdatePage();

	//----------------------------------------------------------------------------
	// data members

	// todo
};

//============================================================================
// CInspectWnd
//============================================================================

class CInspectWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	EQLIB_OBJECT CInspectWnd(CXWnd*);
	EQLIB_OBJECT void PlayerBeingDeleted(PlayerClient*);

	// virtual
	EQLIB_OBJECT ~CInspectWnd();
	EQLIB_OBJECT int Draw() const;
	EQLIB_OBJECT int OnProcessFrame();
	EQLIB_OBJECT int WndNotification(CXWnd*, uint32_t, void*);
	EQLIB_OBJECT void Deactivate();

	// private
	EQLIB_OBJECT void AcceptInspectText();
	EQLIB_OBJECT void Init();
};

//============================================================================
// CInventoryWnd
//============================================================================

// see ref to pinstCInventoryWnd_x in __GetGaugeValueFromEQ_x
// oct 26 2017 Beta see 7BBCE2
class CInventoryWnd : public CSidlScreenWnd, public PopDialogHandler, public WndEventHandler, public IObserver
{
public:
	CInventoryWnd(CXWnd*);
	virtual ~CInventoryWnd();

	virtual int Draw() override;
	virtual int HandleLButtonUp(const CXPoint&, uint32_t) override;
	virtual int OnProcessFrame() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT long GetInventoryQtyFromCoinType(int);
	EQLIB_OBJECT void ClickedMoneyButton(int, int);
	EQLIB_OBJECT void DestroyHeld();
	EQLIB_OBJECT void Init();
	EQLIB_OBJECT void UpdateMoneyDisplay();

	// todo: check me

/*0x024C*/ BYTE        Unknown0x0240[0x84];
/*0x02d0*/ int64_t     VitalityCap;
/*0x02d8*/ int         AAVitalityCap;
};
using INVENTORYWND = CInventoryWnd;
using PINVENTORYWND = CInventoryWnd*;

//============================================================================
// CInvSlotWnd
//============================================================================

class CInvSlotWnd;

const int MAX_INV_SLOTS = 0x900;

// actual size 0x14 10-12-2010
// I think this is correct:
// see (69FF1E) in eqgame.exe dated 2013 11 13
class CInvSlot
{
public:
	CInvSlot();
	virtual ~CInvSlot();

	EQLIB_OBJECT bool IllegalBigBank(int);
	EQLIB_OBJECT void DoDrinkEatPoison(EQ_Item*, int);
	EQLIB_OBJECT void HandleLButtonDown(const CXPoint&);
	EQLIB_OBJECT void HandleLButtonHeld(const CXPoint&);
	EQLIB_OBJECT void HandleLButtonUp(const CXPoint&, bool);
	EQLIB_OBJECT void HandleLButtonUpAfterHeld(const CXPoint&);
	EQLIB_OBJECT void HandleRButtonDown(const CXPoint&);
	EQLIB_OBJECT void HandleRButtonHeld(const CXPoint&);
	EQLIB_OBJECT void HandleRButtonUp(const CXPoint&);
	EQLIB_OBJECT void HandleRButtonUpAfterHeld(const CXPoint&);
	EQLIB_OBJECT void SetInvSlotWnd(CInvSlotWnd*);
	EQLIB_OBJECT void SetItem(EQ_Item*);
	EQLIB_OBJECT void SliderComplete(int);
	EQLIB_OBJECT void GetItemBase(CONTENTS**);
	EQLIB_OBJECT void UpdateItem();

	//----------------------------------------------------------------------------
	// data members

/*0x04*/ CInvSlotWnd*       pInvSlotWnd;
/*0x08*/ CTextureAnimation* pInvSlotAnimation;
/*0x0c*/ int                Index;
/*0x10*/ bool               bEnabled;
};
using EQINVSLOT = CInvSlot;
using PEQINVSLOT = CInvSlot*;

//----------------------------------------------------------------------------
// Size 0x2418 see 534532 in Nov 06 2018 Test
class CInvSlotMgr
{
public:
	CInvSlotMgr();
	virtual ~CInvSlotMgr();

	EQLIB_OBJECT CInvSlot* CreateInvSlot(CInvSlotWnd*);
	EQLIB_OBJECT CInvSlot* FindInvSlot(int TopSlot, int SubSlot = -1, int FindWindowRelated = 0, bool bSomething = 1);
	EQLIB_OBJECT bool MoveItem(ItemGlobalIndex* from, ItemGlobalIndex* to, bool bDebugOut, bool CombineIsOk, bool MoveFromIntoToBag = false, bool MoveToIntoFromBag = false);
	EQLIB_OBJECT void Process();
	EQLIB_OBJECT void SelectSlot(CInvSlot*);
	EQLIB_OBJECT void UpdateSlots();

	//----------------------------------------------------------------------------
	// data members

/*0x0004*/ CInvSlot*    SlotArray[MAX_INV_SLOTS]; // size 0x2400 //see 72E00F in Nov 06 2018 Test
/*0x2404*/ int          TotalSlots;
/*0x2408*/ unsigned int LastUpdate;
/*0x240c*/ CInvSlot*    pLastSelectedSlot;
/*0x2410*/ int          Unknown0x2410;
/*0x2414*/ bool         bToggleBagsOpen;
/*0x2415*/ bool         bToggleBankBagsOpen;
/*0x2418*/
};
using EQINVSLOTMGR = CInvSlotMgr;
using PEQINVSLOTMGR = CInvSlotMgr*;

//----------------------------------------------------------------------------

// note that Invslot needs to be a short or pickupitem wont work
// CInvSlotWnd_size: 0x2e0 (see 7F64AC) in May 17 2019 Test
class CInvSlotWnd : public CButtonWnd
{
public:
	CInvSlotWnd(CXWnd* pParent, uint32_t ID, CXRect rect, CTextureAnimation* ptaBackground,
		const ItemGlobalIndex& itemLocation, int ItemOffsetX, int ItemOffsetY);
	virtual ~CInvSlotWnd();

	virtual int Draw() override;
	virtual int DrawTooltip(const CXWnd*) const override;
	virtual int HandleLButtonDown(const CXPoint&, uint32_t) override;
	virtual int HandleLButtonHeld(const CXPoint&, uint32_t) override;
	virtual int HandleLButtonUp(const CXPoint&, uint32_t) override;
	virtual int HandleLButtonUpAfterHeld(const CXPoint&, uint32_t) override;
	virtual int HandleRButtonDown(const CXPoint&, uint32_t) override;
	virtual int HandleRButtonHeld(const CXPoint&, uint32_t) override;
	virtual int HandleRButtonUp(const CXPoint&, uint32_t) override;
	virtual int HandleRButtonUpAfterHeld(const CXPoint&, uint32_t) override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;
	virtual void SetAttributesFromSidl(CParamScreenPiece*) override;

	EQLIB_OBJECT void SetInvSlot(CInvSlot*);

	//----------------------------------------------------------------------------
	// data members

/*0x290*/ CTextureAnimation* pBackground;
/*0x294*/ ItemGlobalIndex    ItemLocation;
/*0x2a0*/ void*              LinkedItem; // ItemBasePtr
/*0x2a4*/ int                ItemOffsetX;
/*0x2a8*/ int                ItemOffsetY;
/*0x2ac*/ CTextureAnimation* ptItem;
/*0x2b0*/ int                Quantity;
/*0x2b4*/ bool               bSelected;
/*0x2b8*/ int                RecastLeft;
/*0x2bc*/ bool               bHotButton;
/*0x2bd*/ bool               bInventorySlotLinked;
/*0x2c0*/ CInvSlot*          pInvSlot;
/*0x2c4*/ CTextObjectInterface* pTextObject;
/*0x2c8*/ int                TextFontStyle;
/*0x2cc*/ int                Mode;
/*0x2d0*/ D3DCOLOR           BGTintRollover;
/*0x2d4*/ D3DCOLOR           BGTintNormal;
/*0x2d8*/ long               LastTime;
/*0x2dc*/ int                Unknown0x2dc;
/*0x2e0*/
};
using EQINVSLOTWND = CInvSlotWnd;
using PEQINVSLOTWND = CInvSlotWnd*;

//============================================================================
// CItemDisplayWnd
//============================================================================

enum ItemDisplayFlags
{
	PREVENT_LINK       = 0x00000001,
	RECYCLE_WINDOW     = 0x00000002,
	FROM_LINK          = 0x00000004,
	FROM_BAZAAR_SEARCH = 0x00000008,
	FROM_BARTER_SEARCH = 0x00000010
};

// CItemDisplayWindow__CItemDisplayWindow_x aItemdisplaywin
// CItemDisplayWindow_size: 0x638 (see 756212) in May 17 2019 Test
class CItemDisplayWnd : public CSidlScreenWnd
{
public:
	EQLIB_OBJECT CItemDisplayWnd(CXWnd*);
	EQLIB_OBJECT virtual ~CItemDisplayWnd();

	EQLIB_OBJECT virtual int HandleKeyboardMsg(uint32_t, uint32_t, bool) override;
	EQLIB_OBJECT virtual int OnProcessFrame() override;
	EQLIB_OBJECT virtual int WndNotification(CXWnd* pWnd, uint32_t Message, void* pData) override;
	EQLIB_OBJECT virtual bool AboutToShow() override;

	EQLIB_OBJECT CXStr CreateEquipmentStatusString(EQ_Item*);
	EQLIB_OBJECT void SetItem(PCONTENTS* pCont, int flags);
	EQLIB_OBJECT void SetItemText(char*);
	EQLIB_OBJECT void SetSpell(int SpellID, bool HasSpellDescr, int);
	EQLIB_OBJECT void UpdateStrings();

	EQLIB_OBJECT CXStr CreateClassString(EQ_Equipment*);
	EQLIB_OBJECT CXStr CreateMealSizeString(EQ_Equipment*);
	EQLIB_OBJECT CXStr CreateModString(EQ_Equipment*, int, int, int*);
	EQLIB_OBJECT CXStr CreateRaceString(EQ_Equipment*);
	EQLIB_OBJECT void GetSizeString(int, char*);
	EQLIB_OBJECT void InsertAugmentRequest(int AugSlot);
	EQLIB_OBJECT void RemoveAugmentRequest(int AugSlot);
	EQLIB_OBJECT void RequestConvertItem();

	//----------------------------------------------------------------------------
	// data members

	// todo: verify
/*0x0240*/ CStmlWnd*         Description;
/*0x0244*/ CStmlWnd*         Name;
/*0x0248*/ CButtonWnd*       IconButton;
/*0x024c*/ CStmlWnd*         ItemLore;
/*0x0250*/ CTabWnd*          ItemDescriptionTabBox;
/*0x0254*/ CPageWnd*         ItemDescriptionTab;
/*0x0258*/ CPageWnd*         ItemLoreTab;
/*0x025c*/ CSidlScreenWnd*   pAppearanceSocketScreen;
/*0x0260*/ CButtonWnd*       pAppearanceSocketItem;
/*0x0264*/ CButtonWnd*       pAppearanceSocketBuyButton;
/*0x0268*/ CStmlWnd*         pAppearanceSocketDescription;
/*0x026c*/ CSidlScreenWnd*   pItemSocketScreen[6];
/*0x0284*/ CButtonWnd*       pItemSocketItemButton[6];
/*0x029c*/ CStmlWnd*         pItemSocketDescription[6];
/*0x02b4*/ CXStr             ItemInfo;                 // this item is placable in yards, guild yards blah blah , This item can be used in tradeskills
/*0x02b8*/ CXStr             WindowTitle;
/*0x02bc*/ CXStr             ItemAdvancedLoreText;
/*0x02c0*/ CXStr             ItemMadeByText;
/*0x02c4*/ CXStr             BackupTabTitle;
/*0x02c8*/ CXStr             SolventText;
/*0x02cc*/ CXStr             ItemInformationText;      // Item Information: Placing this augment into blah blah, this armor can only be used in blah blah
/*0x02d0*/ PCONTENTS         pItem; // ItemBasePtr
/*0x02d4*/ bool              bActiveItem;
/*0x02d5*/ bool              bItemTextSet;
/*0x02d8*/ CTextureAnimation* BuffIcons;
/*0x02dC*/ CTextureAnimation* DragIcons;
/*0x02E0*/ bool              bTaggable;
/*0x02E1*/ bool              bFailed;
/*0x02E4*/ unsigned int      TabCount;
/*0x02E8*/ CLabel*           ModButtonLabel;
/*0x02EC*/ CLabel*           RewardButtonLabel;
/*0x02f0*/ CStmlWnd*         ConvertStml;
/*0x02F4*/ CLabel*           MadeByLabel;
/*0x02F8*/ CLabel*           CollectedLabel;
/*0x02FC*/ CLabel*           ScribedLabel;
/*0x0300*/ int               Row;
/*0x0304*/ bool              bAntiTwink;
/*0x0308*/ CButtonWnd*       ModButton;
/*0x030c*/ CButtonWnd*       RewardButton;
/*0x0310*/ CButtonWnd*       PrintRealEstateItems;
/*0x0314*/ CButtonWnd*       ConvertButton;
/*0x0318*/ bool              bCollected;
/*0x0319*/ bool              bCollectedReceived;
/*0x031c*/ int               Unknown0x031c;
/*0x0320*/ int               Unknown0x0320;
/*0x0324*/ bool              bScribed;
/*0x0325*/ bool              bScribedReceived;
/*0x0326*/ BYTE              Unknown0x0326[0x2f2];
/*0x0618*/ DWORD             Unknown0x0618;
/*0x061c*/ DWORD             Unknown0x061C;
/*0x0620*/ DWORD             Unknown0x0620;
/*0x0624*/ DWORD             Unknown0x0624;
/*0x0628*/ DWORD             Unknown0x0628;
/*0x062c*/ DWORD             Unknown0x062c;
/*0x0630*/ DWORD             Unknown0x0630;
/*0x0634*/ DWORD             ItemWndIndex;             // 0-5? you can have max 6 windows up I think before it starts overwriting the sixth.
/*0x0638*/
};
using EQITEMWINDOW = CItemDisplayWnd;
using PEQITEMWINDOW = CItemDisplayWnd*;

//============================================================================
// CJournalWnd
//============================================================================

class JournalNPC;

class CJournalCatWnd : public CSidlScreenWnd
{
public:
	CJournalCatWnd(CXWnd*);
	virtual ~CJournalCatWnd();

	virtual int OnProcessFrame() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT void Clean();
	EQLIB_OBJECT void UpdateAll(bool);
	EQLIB_OBJECT void UpdateButtons();
	EQLIB_OBJECT void BuildList();
	EQLIB_OBJECT void LoadINI();
	EQLIB_OBJECT void SelectCategory(int);
	EQLIB_OBJECT void SortList(int, bool);
	EQLIB_OBJECT void StoreINI();
	EQLIB_OBJECT void UpdateListWnd(bool);
};

class CJournalNPCWnd : public CSidlScreenWnd
{
public:
	CJournalNPCWnd(CXWnd*);
	virtual ~CJournalNPCWnd();

	virtual int OnProcessFrame() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT void EnterIntoJournal(char*, float, float, float, char*);
	EQLIB_OBJECT void LoadJournal(int);
	EQLIB_OBJECT void SaveJournal();
	EQLIB_OBJECT void UpdateAll(bool);
	EQLIB_OBJECT void UpdateCategories();
	EQLIB_OBJECT void BuildList();
	EQLIB_OBJECT void DoBackups(CXStr);
	EQLIB_OBJECT void GetLogState();
	EQLIB_OBJECT void SelectNPCIndex(int);
	EQLIB_OBJECT void SortList(int, bool);
	EQLIB_OBJECT void StoreLogState();
	EQLIB_OBJECT void UpdateButtons();
	EQLIB_OBJECT void UpdateListWnd(bool);
};

class CJournalTextWnd : public CSidlScreenWnd
{
public:
	CJournalTextWnd(CXWnd*);
	virtual ~CJournalTextWnd();

	virtual int OnProcessFrame() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT void Clear();
	EQLIB_OBJECT void DisplayNPC(JournalNPC*);
	EQLIB_OBJECT void SetSearch(CXStr);
	EQLIB_OBJECT void UpdateAll(bool);
	EQLIB_OBJECT void UpdateCategories();
	EQLIB_OBJECT void BuildList();
	EQLIB_OBJECT void SelectEntryIndex(int);
	EQLIB_OBJECT void SortList(int, bool);
	EQLIB_OBJECT void UpdateButtons();
	EQLIB_OBJECT void UpdateListWnd(bool);
};

//============================================================================
// CLargeDialogWnd
//============================================================================

class CLargeDialogWnd : public CSidlScreenWnd
{
public:
	EQLIB_OBJECT void Open(bool bYesNoEnabled, CXStr DialogText, unsigned long closeTimer /* 0 means never */,
		CXStr DialogTitle, bool bShowVolumeControls, CXStr YesText, CXStr NoText);
};

//============================================================================
// CLootWnd
//============================================================================

// CLootWnd__CLootWnd aLootwnd
// CLootWnd_size: 0x3a8 (see 542F56) in May 17 2019 Test
class CLootWnd : public CSidlScreenWnd, public PopDialogHandler, public WndEventHandler
{
public:
	CLootWnd(CXWnd*);
	virtual ~CLootWnd();

	virtual int OnProcessFrame() override;
	virtual int PostDraw() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT void AddContainerToLootArray(EQ_Item*);
	EQLIB_OBJECT void AddEquipmentToLootArray(EQ_Item*);
	EQLIB_OBJECT void AddNoteToLootArray(EQ_Item*);
	EQLIB_OBJECT void Deactivate(bool);
	EQLIB_OBJECT void LootAll(bool);
	EQLIB_OBJECT void RequestLootSlot(int Slot, bool bAutoInventory);
	EQLIB_OBJECT void SlotLooted(int);
	EQLIB_OBJECT void FinalizeLoot();

	//----------------------------------------------------------------------------
	// data members

	// todo: most of this is wrong
/*0x0248*/ BYTE              Unknown0x0244[0x94];
/*0x02dc*/ DWORD             NumOfSlots;
/*0x02e0*/ BYTE              Unknown0x02e0[0x4];
/*0x02e4*/ INVENTORYARRAY*   pInventoryArray;
/*0x02e8*/ DWORD             Size;
/*0x02ec*/ DWORD             NumOfSlots3;
/*0x02f0*/ BYTE              Unknown0x02f0[0x8];
/*0x02f8*/ BYTE              Unknown0x02f8;
/*0x02f9*/ BYTE              Unknown0x02f9;
/*0x02fa*/ BYTE              Unknown0x02fa;
/*0x02fb*/ BYTE              Unknown0x02fb;
/*0x02fc*/ CXWnd*            LootInvWnd;
/*0x0300*/ CInvSlotWnd*      LootSlotWnd[0x22];
/*0x0388*/ CLabel*           LW_CorpseName;
/*0x038c*/ CButtonWnd*       DoneButton;
/*0x0390*/ CButtonWnd*       BroadcastButton;
/*0x0394*/ CButtonWnd*       LootAllButton;
/*0x0398*/ BYTE              Unknown0x0398[0x10];
/*0x03a8*/
};
using EQLOOTWINDOW = CLootWnd;
using PEQLOOTWINDOW = CLootWnd*;

//============================================================================
// CMapViewWnd
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
// CMerchantWnd
//============================================================================

enum eMerchantServices
{
	Regular,
	Recovery,
	Mail,
	ServiceCount
};

// todo: finish mapping this and verify

#if 0
class MerchantPageHandler : public VeBaseReferenceCount
{
public:
	/*0x08*/ CMerchantWnd*   pParent;
	/*0x0c*/ int             MaxItems;
	/*0x10*/ int             LastIndex;
	/*0x14*/ CListWnd* ItemsList;
	/*0x18*/ CPageWnd* PurchasePage;
	/*0x1c*/ bool            bListNeedsRefresh;
	/*0x20*/ SoeUtil::Array<CONTENTDATA> ItemContainer;
	/*0x40*/ int             Unknown0x40;
	/*0x44*/ int             Unknown0x44;
	/*0x48*/ int             Unknown0x48;
	/*0x4c*/ int             Unknown0x4c;
	/*0x50*/ int             Unknown0x50;
	/*0x54*/ int             Unknown0x54;
	/*0x58*/ int             Unknown0x58;
	/*0x5c*/ int             Unknown0x5c;
	/*0x60*/ int             Unknown0x60;
	/*0x64*/ int             Unknown0x64;
	/*0x68*/ int             Unknown0x68;
	/*0x6c*/ int             Unknown0x6c;
	/*0x70*/ int             Unknown0x70;
	/*0x74*/ int             Unknown0x74;
	/*0x78*/ int             Unknown0x78;
	/*0x7c*/ int             Unknown0x7c;
	/*0x80*/ int             Unknown0x80;
	/*0x84*/

	// offset comments indicate vtable offset
	/*0x0c*/ EQLIB_OBJECT virtual void Unknownv0x08();
	/*0x0c*/ EQLIB_OBJECT virtual void Unknownv0x0c();-
	/*0x10*/ EQLIB_OBJECT virtual void Unknownv0x10()-;
	/*0x14*/ EQLIB_OBJECT virtual void Unknownv0x14();
	/*0x18*/ EQLIB_OBJECT virtual void DestroyItemByUniqueId(int64_t UniqueID);
	/*0x1c*/ EQLIB_OBJECT virtual void DestroyItemByItemGuid(const EqItemGuid& ItemGuid);
	/*0x20*/ EQLIB_OBJECT virtual bool AddItemToArray(const VePointer<CONTENTS>& pSentItem);
	/*0x24*/ EQLIB_OBJECT virtual int Sort(SListWndSortInfo* SortInfo);
	/*0x28*/ EQLIB_OBJECT virtual void UpdateList();
	/*0x2c*/ EQLIB_OBJECT virtual int DisplayBuyOrSellPrice(const VePointer<CONTENTS>& pItem, bool bBuy) const;
	/*0x30*/ EQLIB_OBJECT virtual CXStr GetPriceString(int Price) const;
	/*0x34*/ EQLIB_OBJECT virtual void UpdateControls();
	/*0x38*/ EQLIB_OBJECT virtual bool RequestGetItem(int Qty);
	/*0x3c*/ EQLIB_OBJECT virtual void RequestPutItem(int Qty);
	/*0x40*/ EQLIB_OBJECT virtual bool CanSelectSlot(const ItemGlobalIndex& Location) const;
	/*0x44*/ EQLIB_OBJECT virtual void DisablePageSpecificButtons();
	/*0x48*/ EQLIB_OBJECT virtual eMerchantServices GetHandlerType() const;
	/*0x4c*/ EQLIB_OBJECT virtual void CXWnd__OnShowANDPostDraw() const;
	/*0x50*/ EQLIB_OBJECT virtual void Unknownv0x50() const;
	/*0x54*/ EQLIB_OBJECT virtual void Unknownv0x54() const;
	/*0x58*/ EQLIB_OBJECT virtual void Unknownv0x58() const;
};

class PurchasePageHandler : public MerchantPageHandler
{
public:
	/*0x84*/ bool bShowAllItems;
	/*0x88*/ int Unknown0x88;
	/*0x8c*/ int Unknown0x8c;
	/*0x90*/ int Unknown0x90;
	/*0x94*/ int Unknown0x94;
	/*0x98*/ int Unknown0x98;
	/*0x9c*/ int Unknown0x9c;
	/*0xa0*/ int Unknown0xa0;
	/*0xa4*/ int Unknown0xa4;
	/*0xa8*/
	EQLIB_OBJECT bool RequestGetItem(int);
	EQLIB_OBJECT void RequestPutItem(int);
};
#endif

struct CONTENTSARRAY;
struct sell_msg;

// this is actually PurchasePageHandler?
struct merchdata
{
	/*0x00*/ void* vftable;                  // VeBaseReferenceCount
	/*0x04*/ BYTE          Unknown0x4[0x8];
	/*0x0c*/ DWORD         MerchSlots;
	/*0x10*/ DWORD         SelectedListItem;
	/*0x14*/ DWORD         Unknown0x14[4];
	/*0x24*/ CONTENTSARRAY* pMerchArray;
	/*0x28*/ DWORD         MerchMaxSlots;
	/*0x2c*/
};

struct merch_other
{
	merchdata* pMerchData;          // purchase page
	void* other;                    // buyback page
	void* other2;                   // mail page
};

// CMerchantWnd__CMerchantWnd_x (aMerchantwnd)
// CMerchantWnd_size: 0x458 (see 5430B2) in May 17 2019 Test
class CMerchantWnd : public CSidlScreenWnd, public WndEventHandler, PopDialogHandler
{
public:
/*0x0248*/ BYTE        Unknown0x0240[0x8];
/*0x0250*/ merch_other* pMerchOther;             // found in CMerchantWnd__CMerchantWnd
/*0x0254*/ BYTE        Unknown0x0254[0x8];
/*0x025c*/ FLOAT       Markup;                   // found in CMerchantWnd__DisplayBuyOrSellPrice_x
/*0x0260*/ BYTE        Unknown0x0260[0xc];
/*0x026c*/ DWORD       SelectedSlotID;
/*0x0270*/ BYTE        Unknown0x0270[0x1e8];
/*0x0458*/

#if 0
/*0x234*/ bool         bInventoryWasActive;
/*0x240*/ VeArray<VePointer<MerchantPageHandler>> PageHandlers;
/*0x24c*/ float        MerchantGreed;
/*0x250*/ ItemGlobalIndex ItemLocation;
/*0x25c*/ BYTE         Unknown0x254[0x8];
/*0x264*/ VePointer<CONTENTS> pSelectedItem;
/*0x268*/ time_t       MailExpireTime;
/*0x26c*/ bool         bAutoRetrieveingMail;
/*0x270*/ BYTE         Unknown0x268[0x10];
/*0x280*/ char*        Labels[0xc];
/*0x2b0*/ CEditWnd*    SearchEdit;
/*0x2b4*/ CButtonWnd*  SearchButton;
/*0x2b8*/ CLabel*      MerchantNameLabel;
/*0x2bc*/ CLabel*      SelectedItemLabel;
/*0x2c0*/ CLabel*      SelectedPriceLabel;
/*0x2c4*/ CButtonWnd*  InspectButton;
/*0x2c8*/ CButtonWnd*  PreviewButton;
/*0x2cc*/ CButtonWnd*  SelectedItemButton;
/*0x2d0*/ CButtonWnd*  BuyButton;
/*0x2d4*/ CButtonWnd*  BuyMarketPlaceButton;
/*0x2d8*/ CButtonWnd*  SellButton;
/*0x2dc*/ CButtonWnd*  RecoverButton;
/*0x2e0*/ CButtonWnd*  RetrieveButton;
/*0x2e4*/ CButtonWnd*  RetrieveAllButton;
/*0x2e8*/ CButtonWnd*  SendButton;
/*0x2ec*/ CButtonWnd*  AdventureButton;
/*0x2f0*/ CLabel*      SendToLabel;
/*0x2f4*/ CEditWnd*    SendToEdit;
/*0x2f8*/ CLabel*      NoteLabel;
/*0x2fc*/ CEditWnd*    NoteEdit;
/*0x300*/ CButtonWnd*  ClearNoteButton;
/*0x304*/ CListWnd*    ItemsList;
/*0x308*/ CListWnd*    ItemsRecoveryList;
/*0x30c*/ CListWnd*    ItemsMailList;
/*0x310*/ CButtonWnd*  DoneButton;
/*0x314*/ CPageWnd*    PurchasePage;
/*0x318*/ CPageWnd*    RecoveryPage;
/*0x31c*/ CPageWnd*    MailPage;
/*0x320*/ CTabWnd*     TabWindow;
/*0x324*/ CButtonWnd*  UsableButton;
/*0x328*/ CLabel*      CurrentCurrencyLabel;
/*0x32c*/ int          Unknown0x32c;
/*0x330*/ int          Unknown0x330;
/*0x334*/ int          Unknown0x334;
/*0x338*/ int          Unknown0x338;
/*0x33C*/ int          Unknown0x33C;
/*0x340*/ int          Guk_Currency;
/*0x344*/ uint8_t      Unknown0x340[0x100];
/*0x444*/
#endif

	CMerchantWnd(CXWnd*);
	virtual ~CMerchantWnd();

	EQLIB_OBJECT void AddContainerToMercArray(EQ_Container*);
	EQLIB_OBJECT void AddEquipmentToMercArray(EQ_Equipment*);
	EQLIB_OBJECT void AddNoteToMercArray(EQ_Note*);
	EQLIB_OBJECT void ClearMerchantSlot(int);
	EQLIB_OBJECT void FinishBuyingItem(sell_msg*);
	EQLIB_OBJECT void FinishSellingItem(sell_msg*);
	EQLIB_OBJECT int SelectBuySellSlot(ItemGlobalIndex*, int ListIndex = -1);
	EQLIB_OBJECT void DisplayBuyOrSellPrice(bool, EQ_Item*);
	EQLIB_OBJECT void HandleBuy(int);
	EQLIB_OBJECT void HandleSell(int);
	EQLIB_OBJECT void UpdateBuySellButtons();
};
using EQMERCHWINDOW = CMerchantWnd;
using PEQMERCHWINDOW = CMerchantWnd *;

//============================================================================
// CMusicPlayerWnd
//============================================================================

class CMusicPlayerWnd : public CSidlScreenWnd
{
public:
	CMusicPlayerWnd(CXWnd*);
	virtual ~CMusicPlayerWnd();

	EQLIB_OBJECT void Update();
	EQLIB_OBJECT void AutoStart();
	EQLIB_OBJECT void UpdateButtons();
};

//============================================================================
// CNoteWnd
//============================================================================

class CNoteWnd : public CSidlScreenWnd
{
public:
	EQLIB_OBJECT CNoteWnd(CXWnd*);
	EQLIB_OBJECT ~CNoteWnd();

	EQLIB_OBJECT bool CheckNote(EQ_Note*);
	EQLIB_OBJECT void SetNote(char*);
};

//============================================================================
// COptionsWnd
//============================================================================

struct KeyboardAssignmentData
{
	CXStr Description;
	int nAssignmentNumber;
};
using EQKBASSIGN = KeyboardAssignmentData;
using PEQKBASSIGN = KeyboardAssignmentData*;

// size 0x904 3-10-2004
class COptionsWnd : public CSidlScreenWnd, public PopDialogHandler, public WndEventHandler
{
public:
	COptionsWnd(CXWnd*);
	virtual ~COptionsWnd();

	EQLIB_OBJECT void RefreshCurrentKeyboardAssignmentList();
	EQLIB_OBJECT void ResetKeysToDefault();
	EQLIB_OBJECT void RestoreDefaultColors();
	EQLIB_OBJECT int ChatPageOnProcessFrame();
	EQLIB_OBJECT int ChatPageWndNotification(CXWnd*, uint32_t, void*);
	EQLIB_OBJECT int ColorPageOnProcessFrame();
	EQLIB_OBJECT int ColorPageWndNotification(CXWnd*, uint32_t, void*);
	EQLIB_OBJECT int DisplayPageOnProcessFrame();
	EQLIB_OBJECT int DisplayPageWndNotification(CXWnd*, uint32_t, void*);
	EQLIB_OBJECT int GeneralPageOnProcessFrame();
	EQLIB_OBJECT int GeneralPageWndNotification(CXWnd*, uint32_t, void*);
	EQLIB_OBJECT int KeyboardPageDeactivate();
	EQLIB_OBJECT int KeyboardPageHandleKeyboardMsg(uint32_t, uint32_t, bool);
	EQLIB_OBJECT int KeyboardPageOnProcessFrame();
	EQLIB_OBJECT int KeyboardPageWndNotification(CXWnd*, uint32_t, void*);
	EQLIB_OBJECT int MousePageOnProcessFrame();
	EQLIB_OBJECT int MousePageWndNotification(CXWnd*, uint32_t, void*);
	EQLIB_OBJECT int RedirectDeactivateTo(CPageWnd*);
	EQLIB_OBJECT int RedirectHandleKeyboardMsgTo(CPageWnd*, uint32_t, uint32_t, bool);
	EQLIB_OBJECT int RedirectOnProcessFrameTo(CPageWnd*);
	EQLIB_OBJECT int RedirectWndNotificationTo(CPageWnd*, CXWnd*, uint32_t, void*);
	EQLIB_OBJECT void AddKeyboardAssignment(int, int, int);
	EQLIB_OBJECT void InitKeyboardAssignments();
	EQLIB_OBJECT void InitKeyboardPage();
	EQLIB_OBJECT void KeyboardPageCancelKeypressAssignment();
	EQLIB_OBJECT void SetBagOptions(int, int);
	EQLIB_OBJECT void SyncChatPage();
	EQLIB_OBJECT void SyncColorPage();
	EQLIB_OBJECT void SyncDisplayPage();
	EQLIB_OBJECT void SyncGeneralPage();
	EQLIB_OBJECT void SyncMousePage();
	EQLIB_OBJECT void FillChatFilterList();

	//----------------------------------------------------------------------------
	// data members

	// this is incorrect and needs to be updated
	/*0x264*/ KeyboardAssignmentData   Binds[0xA1];
	/*0x508*/
	/*0x904*/
};

using EQOPTIONSWINDOW = COptionsWnd;
using PEQOPTIONSWINDOW = COptionsWnd*;

//============================================================================
// CPetInfoWnd
//============================================================================

// CPetInfoWindow__CPetInfoWindow aPetinfowindow
// CPetInfoWindow_size: 0x8d8 (see 5420D1) in May 17 2019 Test
class CPetInfoWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CPetInfoWnd(CXWnd*);
	virtual ~CPetInfoWnd();

	EQLIB_OBJECT CButtonWnd* GetButton(int);
	EQLIB_OBJECT void SetShowOnSummon(bool);
	EQLIB_OBJECT void Update();

	//----------------------------------------------------------------------------
	// data members

/*0x244*/ uint8_t            Unknown0x0244[0x4];
/*0x248*/ CButtonWnd*        pButton[0xe];             // there are 14 buttons on the petinfowin with text that can be set to attack,none,back and so on, these are those...
/*0x280*/ uint8_t            Unknown0x0280[0x8];
/*0x288*/ CButtonWnd*        pAttackButton;
/*0x28c*/ CButtonWnd*        pQAttackButton;
/*0x290*/ CButtonWnd*        pFollowButton;
/*0x294*/ CButtonWnd*        pGuardButton;
/*0x298*/ CButtonWnd*        pSitButton;
/*0x29c*/ CButtonWnd*        pStopButton;
/*0x2a0*/ uint8_t            Unknown0x02a0[0x174];
/*0x414*/ CButtonWnd*        pWnd[NUM_BUFF_SLOTS];     // buff buttons
/*0x598*/ int                Buff[NUM_BUFF_SLOTS];     // Spell ID# of each buff -- 97 total
/*0x71c*/ uint8_t            Unknown0x0714[0x20];
/*0x73c*/ unsigned int       PetBuffTimer[NUM_BUFF_SLOTS]; // duration until buff fades, in thousands of a second
/*0x8c0*/ uint8_t            Unknown0x08c0[0xc];
/*0x8cc*/ bool               bPetButtonsDirty;
/*0x8cd*/ bool               Sit;
/*0x8ce*/ bool               Stop;
/*0x8cf*/ bool               ReGroup;
/*0x8d0*/ bool               Follow;
/*0x8d1*/ bool               Guard;
/*0x8d2*/ bool               Taunt;
/*0x8d3*/ bool               Hold;
/*0x8d4*/ bool               GHold;
/*0x8d5*/ bool               Focus;
/*0x8d8*/
};
using EQPETINFOWINDOW = CPetInfoWnd;
using PEQPETINFOWINDOW = CPetInfoWnd *;

//============================================================================
// CPlayerNotesWnd
//============================================================================

class CPlayerNotesWnd : public CSidlScreenWnd
{
public:
	CPlayerNotesWnd(CXWnd*);
	virtual ~CPlayerNotesWnd();

	EQLIB_OBJECT void AppendText(char*);
	EQLIB_OBJECT void SaveNotes();
};

//============================================================================
// CPlayerWnd
//============================================================================

enum ECombatState
{
	eCombatState_Combat,
	eCombatState_Debuff,
	eCombatState_Timer,
	eCombatState_Standing,
	eCombatState_Regen,
};

// CPlayerWindow__CPlayerWindow aPlayerwindow
// CPlayerWindow_size: 0x2f8 (see 542AF4) in May 17 2019 Test
class CPlayerWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CPlayerWnd(CXWnd*);
	virtual ~CPlayerWnd();

	EQLIB_OBJECT void CreateLocalMenu();
	EQLIB_OBJECT void UpdateContextMenu();

	//----------------------------------------------------------------------------
	// data members

/*0x244*/ uint8_t            Unknown0x0240[0xb0];
/*0x2f4*/ ECombatState       CombatState;                       // right above "A_PWCSInCombat"
/*0x2f8*/
};
using CPLAYERWND = CPlayerWnd;
using PCPLAYERWND = CPlayerWnd*;

//============================================================================
// CPotionBeltWnd
//============================================================================

class CPotionBeltWnd : public CSidlScreenWnd
{
public:
	CPotionBeltWnd(CXWnd*);
	virtual ~CPotionBeltWnd();
};


//============================================================================
// CPointMerchantWnd
//============================================================================

struct PointMerchantItem
{
	/*0x00*/ char          ItemName[0x40];
	/*0x40*/ int           ItemID;
	/*0x44*/ unsigned int  Price;
	/*0x48*/ int           ThemeID;
	/*0x4c*/ int           IsStackable;
	/*0x50*/ int           IsLore;
	/*0x54*/ int           RaceMask;
	/*0x58*/ int           ClassMask;
	/*0x5c*/ bool          bCanUse;
	/*0x60*/
};

class PointMerchantInterface;

class PointMerchantWnd : public CSidlScreenWnd, public PopDialogHandler, public WndEventHandler
{
public:
	PointMerchantWnd(CXWnd*);
	virtual ~PointMerchantWnd();

	//----------------------------------------------------------------------------
	// data members

	// todo: verify
	int                Unknown0x008;
	int                NumItems;
	bool               HdrItemName;
	bool               HdrTheme;
	bool               HdrPrice;
	char               OriginalPointsLabel[0x40];
	CLabel* MerchantNameLabel;
	CListWnd* ItemList;
	CListWnd* PointList;
	CButtonWnd* EquipButton;
	CButtonWnd* PurchaseButton;
	CButtonWnd* SellButton;
	CButtonWnd* DoneButton;
	CLabel* PointsAvailableValue;
	CLabel* PointsEverEarnedLabel;
	CLabel* PointsAvailableLabel;
	unsigned int       NextRefreshTime;
	PSPAWNINFO         ActiveMerchant; // PlayerClient*
	PointMerchantItem** Items;
	int                MerchantThemeId;
	int                CurrentSelection;
	int                CurrentSort;
	bool               bCurrentAscending;
	ItemGlobalIndex    ItemLocation;
	CONTENTS* pSelectedItem; // ItemBasePtr
	bool               bInventoryWasActive;
	int                CurrentItem;
	int                CurrentQuantity;
	int                SliderType;
	PointMerchantInterface* pHandler;
};

//============================================================================
// CQuantityWnd
//============================================================================

class CQuantityWnd : public CSidlScreenWnd
{
public:
	CQuantityWnd(CXWnd*);
	virtual ~CQuantityWnd();

	EQLIB_OBJECT void Open(CXWnd*, int, int, int, int, int, int, bool);
	EQLIB_OBJECT void CheckMaxEditWnd();
	EQLIB_OBJECT void UpdateEditWndFromSlider();
	EQLIB_OBJECT void UpdateSliderFromEditWnd();
};

//============================================================================
// CRaidOptionsWnd
//============================================================================

class CRaidOptionsWnd : public CSidlScreenWnd
{
public:
	CRaidOptionsWnd(CXWnd*);
	virtual ~CRaidOptionsWnd();

	EQLIB_OBJECT void AddLooterToList(char*);
	EQLIB_OBJECT void ClearLooterList();
	EQLIB_OBJECT void UpdateComponents();
	EQLIB_OBJECT void InitializeClassColors();
};

//============================================================================
// CRaidWnd
//============================================================================

// CRaidWindow__CRaidWindow
// aClasscolorD
// CRaidWindow_size: 0x3b8 (see 5423C2) in May 17 2019 Test
class CRaidWnd : public CSidlScreenWnd, public WndEventHandler, public CVivoxObserver
{
public:
	CRaidWnd(CXWnd*);
	virtual ~CRaidWnd();

	EQLIB_OBJECT void AddPlayertoList(char*, char*, char*, char*, int, int, bool);
	EQLIB_OBJECT void ChangePosition(char*, int, int, int, bool);
	EQLIB_OBJECT void ChangeRaidGroupLeader(char*, int, char*);
	EQLIB_OBJECT void ClearPlayerList();
	EQLIB_OBJECT void RemovePlayerFromList(char*, int);
	EQLIB_OBJECT void SetClassColor(int, unsigned long);
	EQLIB_OBJECT void SetPlayerClassColor(char*, int, int);
	EQLIB_OBJECT void SetPlayerClassColor(int, int, int);
	EQLIB_OBJECT void SetRaidCount(int);
	EQLIB_OBJECT void SetRaidMemberRank(char*, char*, int);
	EQLIB_OBJECT void SetRaidTarget(char*, int, char*, int);
	EQLIB_OBJECT void UpdateButtons();
	EQLIB_OBJECT void UpdateLevelAverage(int);
	EQLIB_OBJECT void UpdateMemberName(char*, char*, int);
	EQLIB_OBJECT int FindIndexNotInGroupList(char*);
	EQLIB_OBJECT int FindOpenIndexInGroup(int);
	EQLIB_OBJECT int FindPlayerIndexInGroup(char*, int);
	EQLIB_OBJECT void AddSeparator();
	EQLIB_OBJECT void InitializeClassColors();
	EQLIB_OBJECT void ResortRaidGroupList(int, int);

	//----------------------------------------------------------------------------
	// data members

/*0x24c*/ uint8_t            Unknown0x0240[0xac];
/*0x2f8*/ COLORREF           ClassColors[0x10];
/*0x338*/ uint8_t            Unknown0x0338[0x80];
/*0x3b8*/
};
using EQRAIDWINDOW = CRaidWnd;
using PEQRAIDWINDOW = CRaidWnd *;

//============================================================================
// CRealEstateItemsWnd
//============================================================================

class CRealEstateItemsWnd : public CSidlScreenWnd, public PopDialogHandler, public WndEventHandler
{
public:
	CRealEstateItemsWnd(CXWnd*);
	virtual ~CRealEstateItemsWnd();
};

//============================================================================
// CRespawnWnd
//============================================================================

class CRespawnWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CRespawnWnd(CXWnd* pParent);
	virtual ~CRespawnWnd();
};

//============================================================================
// CRewardSelectionWnd
//============================================================================

class CRewardSelectionWnd : public CSidlScreenWnd
{
public:
	EQLIB_OBJECT CRewardSelectionWnd(CXWnd*);

	// virtual
	EQLIB_OBJECT ~CRewardSelectionWnd();
};

//============================================================================
// CSelectorWnd
//============================================================================

class CSelectorWnd : public CSidlScreenWnd
{
public:
	CSelectorWnd(CXWnd*);
	virtual ~CSelectorWnd();

	EQLIB_OBJECT void KeyMapUpdated();
};

//============================================================================
// CSkillsSelectWnd
//============================================================================

class CSkillsSelectWnd : public CSidlScreenWnd
{
public:
	CSkillsSelectWnd(CXWnd*);
	virtual ~CSkillsSelectWnd();

	EQLIB_OBJECT void Refresh();
	EQLIB_OBJECT void SetTypesToDisplay(int);
	EQLIB_OBJECT void UpdateAll();
	EQLIB_OBJECT void UpdateSkill(int);
};

//============================================================================
// CSkillsWnd
//============================================================================

class CSkillsWnd : public CSidlScreenWnd
{
public:
	CSkillsWnd(CXWnd*);
	virtual ~CSkillsWnd();

	EQLIB_OBJECT void SkillImproveOccurred(int);
	EQLIB_OBJECT void UpdateAll();
	EQLIB_OBJECT void UpdateSkill(int);
};

//============================================================================
// CSocialEditWnd
//============================================================================

class CSocialEditWnd : public CSidlScreenWnd
{
public:
	CSocialEditWnd(CXWnd*);
	virtual ~CSocialEditWnd();

	EQLIB_OBJECT unsigned long GetSocialTextColor(int);
	EQLIB_OBJECT void ClickedAccept();
	EQLIB_OBJECT void ClickedClear();
	EQLIB_OBJECT void ClickedTextColorButton(int);
	EQLIB_OBJECT void UpdateControlsFromSocial();
};

//============================================================================
// CSpellBookWnd
//============================================================================

class CSpellBookWnd : public CSidlScreenWnd
{
public:
	CSpellBookWnd(CXWnd*);
	virtual ~CSpellBookWnd();

	EQLIB_OBJECT bool StartSpellMemorization(int, int, bool);
	EQLIB_OBJECT int GetSpellMemTicksLeft();
	EQLIB_OBJECT int GetSpellScribeTicksLeft();
	EQLIB_OBJECT void AutoMemSpell(int, int);
	EQLIB_OBJECT void DeleteSpellFromBook(int, int);
	EQLIB_OBJECT void FinishMemorizing(int, int);
	EQLIB_OBJECT void FinishScribing(int, int);
	EQLIB_OBJECT void MemorizeSet(int*, int);
	EQLIB_OBJECT void RequestSpellDeletion(int);
	EQLIB_OBJECT void SwapSpellBookSlots(int, int);
	EQLIB_OBJECT void TurnToPage(int);
	EQLIB_OBJECT bool CanStartMemming(int);
	EQLIB_OBJECT void ContinueSetMem();
	EQLIB_OBJECT void DelayedSpellMem(int, int, int);
	EQLIB_OBJECT void DisplaySpellInfo(int);
	EQLIB_OBJECT void EndSetMem();
	EQLIB_OBJECT void GetSpellDeletionConfirmation(int);
	EQLIB_OBJECT void HandleLeftClickOnSpell(int);
	EQLIB_OBJECT void HandleRightClickOnSpell(int);
	EQLIB_OBJECT void HandleSpellInfoDisplay(CXWnd*);
	EQLIB_OBJECT void StartSpellMemorizationDrag(int, CButtonWnd*);
	EQLIB_OBJECT void StartSpellScribe(int);
	EQLIB_OBJECT void StopSpellBookAction();
	EQLIB_OBJECT void UpdateSpellBookDisplay();

	EQLIB_OBJECT static int GetBookSlot(int);
};

//============================================================================
// CSpellDisplayWnd
//============================================================================

enum ESpellDisplayType
{
	SpellDisplayType_None,
	SpellDisplayType_BuffWnd,
	SpellDisplayType_PetBuffWnd,
	SpellDisplayType_BlockedBuffWnd,
	SpellDisplayType_BlockedPetBuffWnd,
	SpellDisplayType_SpellBookWnd,
	SpellDisplayType_HotButtonWnd,
	SpellDisplayType_CastSpellWnd,
	SpellDisplayType_Unknown8,
	SpellDisplayType_Unknown9,
	SpellDisplayType_TargetBuff,
};

// aSpelldisplaywi
// size: 0x290 Jun 10, 2019 (test)
class CSpellDisplayWnd : public CSidlScreenWnd
{
public:
	CSpellDisplayWnd(CXWnd* parent, ESpellDisplayType displayType);
	virtual ~CSpellDisplayWnd();

/*0x240*/ int                WindowID;
/*0x244*/ CLabelWnd*         pDuration;
/*0x248*/ CStmlWnd*          pDescription;
/*0x24c*/ CStmlWnd*          pName;
/*0x250*/ CButtonWnd*        pIcon;
/*0x254*/ SoeUtil::IString   DescriptionText;
/*0x264*/ SoeUtil::IString   TitleText;
/*0x274*/ bool               bActiveItem;
/*0x278*/ CTextureAnimation* ptaBuffIcons;
/*0x27c*/ CTextureAnimation* ptaDragIcons;
/*0x280*/ bool               bFailed;
/*0x284*/ ESpellDisplayType  SpellDisplayType;
/*0x288*/ int                SpellID;
/*0x28c*/ int                LastUpdateTime;
/*0x290*/
};
using EQSPELLINFOWINDOW = CSpellDisplayWnd;
using PEQSPELLINFOWINDOW = CSpellDisplayWnd*;

//============================================================================
// CSpellGemWnd
//============================================================================

// CSpellGemWnd__CSpellGemWnd
// CSpellGemWnd_size: 0x330 (see 7F639B) in May 17 2019 Test
class CSpellGemWnd : public CButtonWnd
{
public:
	CSpellGemWnd(CXWnd*, uint32_t, const CXRect&, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, int, int, unsigned long);
	virtual ~CSpellGemWnd();

	EQLIB_OBJECT void SetGemTintStage(int);
	EQLIB_OBJECT void SetSpellGemTint(unsigned long);
	EQLIB_OBJECT void SetSpellIconIndex(int);

	//----------------------------------------------------------------------------
	// data members

/*0x290*/ int                MouseButtonState;
/*0x294*/ bool               bChecked;
/*0x298*/ unsigned int       LastRefresh;
/*0x29C*/ D3DCOLOR           SpellGemTintArray[0xb];   // I dont understand why there are only 11 of these when we have 13 gems noaways, probably a bug or unused?
/*0x2C8*/ int                SpellGemAlphaArray[0xb];
/*0x2f4*/ int                Unknown0x02f4;
/*0x2f8*/ int                Unknown0x02f8;
/*0x2fC*/ int                SpellIconOffsetX;
/*0x300*/ int                SpellIconOffsetY;
/*0x304*/ int                spellicon;                // if this is equal to FFFFFFFF there is no spell memmed in this slot...
/*0x308*/ int                spellstate;               // 1 = cast in progress or refreshtime not met 2 means we ducked or aborted cast, 0 means its ok to cast, should really rename this to tintstage
/*0x30c*/ int                TintIndex;
/*0x310*/ CTextureAnimation* SpellIconTexture;         // CTextureAnimation
/*0x314*/ CTextureAnimation* CustomIconTexture;        // CTextureAnimation
/*0x318*/ int                SpellSlot;
/*0x31c*/ int                Percent;
/*0x320*/ CSpellGemDrawTemplate DrawTemplate;
/*0x330*/
};
using EQCASTSPELLGEM = CSpellGemWnd;
using PEQCASTSPELLGEM = CSpellGemWnd *;

//============================================================================
// CStoryWnd
//============================================================================

class CStoryWnd : public CSidlScreenWnd
{
public:
	CStoryWnd(CXWnd*);
	virtual ~CStoryWnd();

	EQLIB_OBJECT bool HasNew();
	EQLIB_OBJECT bool ShowAuto();
	EQLIB_OBJECT void SaveIni();
	EQLIB_OBJECT void SelectIndex(int);
	EQLIB_OBJECT void SelectOldestNew();
};

//============================================================================
// CTargetWnd
//============================================================================

// CTargetWindow__CTargetWindow aTargetwindow
// CTargetWindow_size: 0x8d8 (see 54298F) in May 17 2019 Test
class CTargetWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CTargetWnd(CXWnd*);
	virtual ~CTargetWnd();

	EQLIB_OBJECT CXStr* GetBuffCaster(int SpellID);
	EQLIB_OBJECT void RefreshTargetBuffs(PBYTE buffer);
	EQLIB_OBJECT void HandleBuffRemoveRequest(CXWnd* pWnd);

	//----------------------------------------------------------------------------
	// data members

/*0x244*/ CXWnd*             pWndBuffs;
/*0x248*/ CTextureAnimation* pBuffGoodBackground;
/*0x24c*/ CTextureAnimation* pBuffBadBackground;
/*0x250*/ CTextureAnimation* pBuffBypassBackground;
/*0x254*/ CTextureAnimation* ptaBuffIcons[NUM_BUFF_SLOTS];
/*0x3d8*/ CButtonWnd*        pTargetBuff[NUM_BUFF_SLOTS];
/*0x55c*/ int                BuffSpellID[NUM_BUFF_SLOTS]; // 0xffffffff if no buff
/*0x6e0*/ int                BuffTimer[NUM_BUFF_SLOTS];
/*0x864*/ int                Unknown0x0864[0x24];
/*0x888*/ int                Type;                     // 1 = self, 4 = group member, 5 = PC, 7 = NPC
/*0x88c*/ uint8_t            Unknown0x088c[0x4c];
/*0x8d8*/
};
using CTARGETWND = CTargetWnd;
using PCTARGETWND = CTargetWnd*;

//============================================================================
// CTaskWnd
//============================================================================

class CTaskWnd : public CSidlScreenWnd
{
public:
	CTaskWnd(CXWnd*);
	virtual ~CTaskWnd();

	EQLIB_OBJECT int UpdateTaskTimers(unsigned long fasttime);
};

//============================================================================
// CTextEntryWnd
//============================================================================

class CTextEntryWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CTextEntryWnd(CXWnd*);
	virtual ~CTextEntryWnd();

	EQLIB_OBJECT void Open(CXWnd* pwnd, int EditMode, char* Prompt, int MinLength, int MaxLength, const char* InitialText);
	EQLIB_OBJECT CXStr GetEntryText();
	EQLIB_OBJECT void Activate(CXWnd*, int, char*, int, int, char*);
	EQLIB_OBJECT void Callback(bool);
	EQLIB_OBJECT void UpdateButtons();

/*0x148*/ int          m_minLength;
/*0x14C*/ int          m_maxLength;
/*0x150*/ CXStr        m_text;
/*0x154*/ CXWnd*       m_parent;
/*0x158*/ CEditWnd*    m_entry;
/*0x15c*/ CLabel*      m_prompt;
/*0x160*/ CButtonWnd*  m_ok;
/*0x164*/ CButtonWnd*  m_cancel;
};
using CTEXTENTRYWND = CTextEntryWnd;
using PCTEXTENTRYWND = CTextEntryWnd*;

//============================================================================
// CTimeLeftWnd
//============================================================================

class CTimeLeftWnd : public CLabel, public WndEventHandler
{
public:
	CTimeLeftWnd(int timeLeft);
	virtual ~CTimeLeftWnd();
};

//============================================================================
// CTipWnd
//============================================================================

class CTipWnd : public CSidlScreenWnd
{
public:
	CTipWnd(CXWnd*, int);
	virtual ~CTipWnd();

	EQLIB_OBJECT void InitializeTipSettings();
	EQLIB_OBJECT void UpdateButtons();
	EQLIB_OBJECT bool IsRecentTOTD(int);
	EQLIB_OBJECT int SelectRandomTip();
	EQLIB_OBJECT void AddContextTip(int);
	EQLIB_OBJECT void LoadINISettings();
	EQLIB_OBJECT void SetTOTD(int);
	EQLIB_OBJECT void ShowHistoryTip(int);
	EQLIB_OBJECT void CleanDayTips();
	EQLIB_OBJECT void LoadDayTips();
};


//============================================================================
// CTrackingWnd
//============================================================================

class CTrackingWnd : public CSidlScreenWnd
{
public:
	CTrackingWnd(CXWnd*);
	virtual ~CTrackingWnd();

	EQLIB_OBJECT void DoTrackFilter(bool);
	EQLIB_OBJECT void DoTrackSort(bool);
	EQLIB_OBJECT void RemovePlayerFromTracking(PlayerClient*);
	EQLIB_OBJECT void SetTrackingList(const char*, int);
	EQLIB_OBJECT int GetListIdByData(unsigned int);
	EQLIB_OBJECT unsigned long GetTrackColor(int);
	EQLIB_OBJECT void GenerateTrackingList();
	EQLIB_OBJECT void NotifyServerOfTrackingTarget(int);
	EQLIB_OBJECT void RemoveFromListWndByData(unsigned int);
	EQLIB_OBJECT void RemovePlayerFromTracking(int);
	EQLIB_OBJECT void UpdateTrackingControls();
	EQLIB_OBJECT void UpdateTrackingList(bool);
};

//============================================================================
// CTradeSkillWnd
//============================================================================

#define MAX_RECIPE_ITEMS 10

struct TradeskillRecipe
{
/*0x00*/ int ID;
/*0x04*/ int Trivial;
/*0x08*/ int ContainerType;
/*0x0c*/ int ContainerID;
/*0x10*/ int RequiredSize;
/*0x14*/ char Name[0x40];
/*0x54*/ bool bUnknown;
/*0x58*/ int Ingredient[MAX_RECIPE_ITEMS];                 // ID# of ingredient(s)
/*0x80*/ int IngredientIcon[MAX_RECIPE_ITEMS];             // Icon# of ingredient(s) (Note: 499 is blank)
};
using EQTRADESKILLRECIPE = TradeskillRecipe;
using PEQTRADESKILLRECIPE = TradeskillRecipe *;

// size: 0xd28 Jun 10, 2019 (test)
class CTradeSkillWnd : public CSidlScreenWnd
{
public:
	CTradeSkillWnd(CXWnd* parent);
	virtual ~CTradeSkillWnd();

	//----------------------------------------------------------------------------
	// data members

	// todo: check and update
/*0x148*/ DWORD        Unknown0x148[0x1b];
/*0x1b4*/ EQTRADESKILLRECIPE* SearchResults[0x64];
/*0x344*/ DWORD        Unknown0x344;
/*0x348*/ DWORD        Unknown0x348;
/*0x34c*/ DWORD        Unknown0x34c;
/*0x350*/ CONTENTS*    Container;
/*0x354*/ DWORD        Unknown0x354;
/*0x358*/ EQTRADESKILLRECIPE* SelectedRecipe;
/*0x35c*/ DWORD        Unknown0x35c;
/*0x360*/ DWORD        SkillLevel;
/*0x364*/ DWORD        Unknown0x364;
/*0x368*/ DWORD        Unknown0x368;
/*0x36c*/ BYTE         Unknown0x36c[0x58];
/*0x3c4*/ DWORD        Unknown0x3c4;
/*0x3c8*/ DWORD        Unknown0x3c8;
/*0x3cc*/ BYTE         Unknonw0x3cc[0x8];
/*0x3d4*/ DWORD        Unknown0x3d4;
/*0x3d8*/ DWORD        Unknown0x3d8;
};
using EQTRADESKILLWINDOW = CTradeSkillWnd;
using PEQTRADESKILLWINDOW = CTradeSkillWnd*;

//============================================================================
// CTradeWnd
//============================================================================

// CTradeWnd__CTradeWnd aTradewnd
// CTradeWnd__size: 0x300 (see 543158) in May 17 2019 Test
class CTradeWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CTradeWnd(CXWnd*);
	virtual ~CTradeWnd();

	EQLIB_OBJECT bool IsMyTradeSlot(int, bool*);
	EQLIB_OBJECT void Activate(PlayerClient*, bool);
	EQLIB_OBJECT void AddContainerToHisTradeArray(EQ_Container*);
	EQLIB_OBJECT void AddEquipmentToHisTradeArray(EQ_Equipment*);
	EQLIB_OBJECT void AddNoteToHisTradeArray(EQ_Note*);
	EQLIB_OBJECT void ClickedCancelButton();
	EQLIB_OBJECT void ClickedMoneyButton(int);
	EQLIB_OBJECT void ClickedTradeButton();
	EQLIB_OBJECT void CompleteTrade();
	EQLIB_OBJECT void DeleteItemFromHisTradeArray(int);
	EQLIB_OBJECT void DropItemIntoTrade();
	EQLIB_OBJECT void SetHisMoney(int, long);
	EQLIB_OBJECT void SetHisReadyTrade(bool);
	EQLIB_OBJECT void SetMyReadyTrade(bool);
	EQLIB_OBJECT void TradeItemChanged(int, int);
	EQLIB_OBJECT void UpdateTradeDisplay();

/*0x244*/ unsigned int       NextRefreshTime;
/*0x248*/ bool               bInventoryWasOpen;
/*0x24c*/ CButtonWnd*        HisMoneyButton[4];
/*0x25c*/ CButtonWnd*        MyMoneyButton[4];
/*0x26c*/ CButtonWnd*        TradeButton;
/*0x270*/ CButtonWnd*        CancelButton;
/*0x274*/ CLabel*            HisNameLabel;
/*0x278*/ CLabel*            MyNameLabel;
/*0x27c*/ CInvSlotWnd*       pInvSlotWnd[16];
/*0x2bc*/ long               HisMoney[4];
/*0x2cc*/ long               MyMoney[4];
/*0x2dc*/ ItemBaseContainer  TradeItems;
/*0x2f8*/ bool               bHisReadyTrade;           // was HisTradeReady
/*0x2f9*/ bool               bMyReadyTrade;            // was MyTradeReady
/*0x2fa*/ bool               bIsTrading;               // was TradeWndOpen
};
using EQTRADEWINDOW = CTradeWnd;
using PEQTRADEWINDOW = CTradeWnd *;

//============================================================================
// CTrainWnd
//============================================================================

class CTrainWnd : public CSidlScreenWnd
{
public:
	CTrainWnd(CXWnd*);
	virtual ~CTrainWnd();

	EQLIB_OBJECT void SetGMData(int*, unsigned char*, float);
	EQLIB_OBJECT void SkillChanged(int);
	EQLIB_OBJECT char* SkillName(int);
	EQLIB_OBJECT int SkillValue(int);
	EQLIB_OBJECT void SortNames(int);
	EQLIB_OBJECT void SortSkill(int);
	EQLIB_OBJECT void SwapSkill(int, int);
	EQLIB_OBJECT void Train();
	EQLIB_OBJECT void UpdateAll(bool);
	EQLIB_OBJECT void UpdateRight();
	EQLIB_OBJECT void UpdateSkill(int);
};

//============================================================================
// CVideoModesWnd
//============================================================================

class CVideoModesWnd : public CSidlScreenWnd
{
public:
	CVideoModesWnd(CXWnd*);
	virtual ~CVideoModesWnd();

	EQLIB_OBJECT void RestoreOldMode();
	EQLIB_OBJECT void Update();
	EQLIB_OBJECT void UpdateSelection(unsigned int);
};

//============================================================================
// CZoneGuideWnd
//============================================================================

enum eZoneGuideConnectionsView
{
	eZGCV_None,
	eZGCV_Selected,
	eZGCV_PreviewPath,
	eZGCV_ActivePath,
	eZGCV_Disabled,
};

class ZoneGuideConnection
{
public:
	EQZoneIndex        DestZone;
	int                TransferTypeIndex;
	int                RequiredExpansions;       // EQExpansionOwned
	bool               bDisabled;
};

class ZoneGuideContinent
{
public:
	int                ID;
	int                DisplaySequence;
	CXStr              Name;
};

class ZoneGuideZoneType
{
public:
	int                ID;
	int                DisplaySequence;
	CXStr              Name;
};

class ZoneGuideTransferType
{
public:
	int                ID;
	CXStr              Description;
};

// see 8E87D6 in Apr 15 2019 exe
class ZoneGuideZone
{
public:
/*0x00*/ EQZoneIndex   ID;
/*0x04*/ CXStr         Name;
/*0x08*/ int           ContinentIndex;
/*0x0C*/ int           MinLevel;
/*0x10*/ int           MaxLevel;
/*0x14*/ DynamicBitField<unsigned short, short> Types;
/*0x1C*/ ArrayClass_RO<ZoneGuideConnection> ZoneConnections;
/*0x2C*/
};

struct ZonePathData
{
	EQZoneIndex        ZoneID;
	int                TransferTypeIndex;
};

// see 8D35C1 in may 10 2018 exe
#define ZONE_COUNT 836

class ZoneGuideManagerBase
{
public:
	ZoneGuideManagerBase();
	virtual ~ZoneGuideManagerBase();

	virtual void ResetAllData();
	//virtual void Serialize(CSerializeBuffer&);
	//virtual void Unserialize(CUnserializeBuffer&);

/*0x0004*/ ZoneGuideZone Zones[ZONE_COUNT];
/*0x8FB4*/ ArrayClass<ZoneGuideContinent> Continents;
/*0x8FC4*/ ArrayClass<ZoneGuideZoneType> ZoneTypes;
/*0x8FD4*/ ArrayClass<ZoneGuideTransferType> TransferTypes;
/*0x8FE4*/
};

// size: 0x9010 see 6AB098 in Apr 15 2019 exe
class ZoneGuideManagerClient : public ZoneGuideManagerBase
{
public:
/*0x8FE4*/ ArrayClass<ZonePathData> ActivePath;
/*0x8FF4*/ ArrayClass<ZonePathData> PreviewPath;
/*0x9004*/ EQZoneIndex CurrZone;
/*0x9008*/ int         HerosJourneyIndex;
/*0x900C*/ bool        bZoneGuideDataSet;
/*0x900D*/ bool        bIncludeBindZoneInPath;
/*0x900E*/ bool        bAutoFindActivePath;
/*0x900F*/ bool        bFindActivePath;
/*0x9010*/

	static ZoneGuideManagerClient& Instance();
};

class CZoneGuideWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CVerticalLayoutWnd* VerticalLayout;
	CButtonWnd*        FilterMyLevelButton;
	CButtonWnd*        FilterAllLevelsButton;
	CButtonWnd*        FilterZonesActiveButton;
	CButtonWnd*        FilterZonesInactiveButton;
	CButtonWnd*        ZoneRunSearchButton;
	CButtonWnd*        ZoneClearSearchButton;
	CButtonWnd*        SelectCurrentZoneButton;
	CEditWnd*          LevelFilterEdit;
	CEditWnd*          ZoneSearchEdit;
	CComboWnd*         TypeFilterCombo;
	CComboWnd*         ContinentFilterCombo;
	CListWnd*          ZonesList;
	CLabelWnd*         ViewZoneConnectionsSelectedZoneLabel;
	CLabelWnd*         ViewZoneConnectionsPreviewPathLabel;
	CLabelWnd*         ViewZoneConnectionsActivePathLabel;
	CLabelWnd*         ViewZoneConnectionsDisabledLabel;
	CButtonWnd*        ViewZoneConnectionsSelectedZoneButton;
	CButtonWnd*        ViewZoneConnectionsPreviewPathButton;
	CButtonWnd*        ViewZoneConnectionsActivePathButton;
	CButtonWnd*        ViewZoneConnectionsDisabledButton;
	CButtonWnd*        DisableConnectionTemplateButton;
	CListWnd*          ZoneConnectionsList;
	CButtonWnd*        ResetPathStartZoneButton;
	CButtonWnd*        SetPathStartZoneButton;
	CButtonWnd*        SetPathEndZoneButton;
	CButtonWnd*        ShowPathWndButton;
	CButtonWnd*        HidePathWndButton;
	CButtonWnd*        FindPathButton;
	CButtonWnd*        EndFindButton;
	CButtonWnd*        ClearPathWndButton;
	CButtonWnd*        ActivatePathButton;
	CButtonWnd*        IncludeBindZoneInPathGenerationButton;
	CButtonWnd*        ShowPathWndOnPathActivationButton;
	CButtonWnd*        AutoFindActivePathButton;
	CEditWnd*          PathStartZoneEdit;
	CEditWnd*          PathEndZoneEdit;
	UINT               NextButtonRefreshTime;
	EQZoneIndex        eCurrentZone;
	bool               bFilterActive;
	int                FilterLevel;
	int                FilterContinentIndex;
	int                FilterZoneTypeIndex;
	bool               bSelectCurrentZone;
	CXStr              ZoneSearchString;
	eZoneGuideConnectionsView eCurrConnectionsView;
	EQZoneIndex        CurrConnectionsViewSelectedZone;
	bool               bCurrentConnectionsViewPreviewPathChanged;
	bool               bCurrentConnectionsViewActivePathChanged;
	bool               bSetPathStartZoneToCurrentZone;
	EQZoneIndex        StartZone;
	EQZoneIndex        EndZone;
	bool               bZoneGuideDataChanged;
	bool               bZoneListChanged;
	bool               bZoneConnectionsListChanged;
	bool               bPathStartZoneChanged;
	int                RightClickMenuID;
};

//============================================================================
//============================================================================
//============================================================================
//============================================================================

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
