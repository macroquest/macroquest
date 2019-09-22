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
#include "Items.h"
#include "SidlParams.h"
#include "SidlTemplates.h"
#include "EQData.h"

#include <list>
#include <functional>

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
	EQLIB_OBJECT virtual void Notify(CObservable* Src, const CNotification* const Notification) {}
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

class [[offsetcomments]] CTextureFont
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

/*0x04*/ int FontStyle;
/*0x08*/
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
class [[offsetcomments]] CEQGBitmap
{
public:
/*0x00*/ void* vftable;
/*0x04*/ BYTE               Header[0x1c];
/*0x20*/ eBitmapType        eType;
/*0x24*/ int                eMemoryPoolManagerType;   // eMemoryPoolManagerType need to figure out this enum
/*0x28*/ char* FileName;
/*0x2c*/ UINT               SourceWidth;
/*0x30*/ UINT               SourceHeight;
/*0x34*/ float              DetailScale;
/*0x38*/ UINT               GrassDensity;
/*0x3c*/ UINT               Width;
/*0x40*/ UINT               Height;
/*0x44*/ bool               bHasTexture;
	union
	{
	/*0x48*/ void* pD3DTexture;              // IDirect3DBaseTexture9
	/*0x48*/ void* pRawBitmap;
	};
/*0x4c*/ UINT               ObjectIndex;
/*0x50*/ UINT               Size;
/*0x54*/ bool               bForceMipMap;
/*0x58*/ int	               TrackingType;
/*0x5c*/ float              SQDistanceToCamera;
/*0x60*/ UINT               LastDistanceTime;
/*0x64*/ UINT               LastRenderTime;
/*0x68*/ UINT               LoadedTime;
/*0x6c*/
};

struct [[offsetcomments]] BMI
{
/*0x00*/ char*              Name;
/*0x04*/ unsigned int       Flags;
/*0x08*/ CEQGBitmap*        pBmp;
/*0x0c*/
};

struct [[offsetcomments]] _SuiteTexture
{
/*0x00*/ bool               bUsed;
/*0x04*/ CXStr              Name;
/*0x08*/ enDir              Directory;
/*0x0c*/ BMI*               pBMInfo;
/*0x10*/
};

struct SWadFile;

class [[offsetcomments]] CEQSuiteTextureLoader
{
public:
/*0x00*/ SWadFile*         pWadFile;
/*0x04*/ ArrayClass<_SuiteTexture> Textures;
/*0x14*/ CXStr              UIPath[cUIDirectoryCount];
/*0x24*/ CXStr              DefaultUIPath[cUIDirectoryCount];
/*0x34*/

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

class [[offsetcomments]] CRadioGroup
{
public:
	EQLIB_OBJECT CRadioGroup(CXStr name = {});
	EQLIB_OBJECT virtual ~CRadioGroup();

/*0x04*/ CXStr                    Name;
/*0x08*/ ArrayClass<CButtonWnd*>  Buttons;
/*0x18*/ int                      CurSel = -1;
/*0x1c*/ bool                     bAllowMultiSelect = false;
/*0x20*/ int                      nSelectionLimit = -1;
/*0x24*/ bool                     bAllowNullable = false;
/*0x28*/
};

//============================================================================
// CButtonWnd
//============================================================================

// CButtonWnd__CButtonWnd_x
// size is 0x290 see 8E0709 in eqgame.exe dated Oct 13 2017 Test
class [[offsetcomments]] CButtonWnd : public CXWnd
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
	EQLIB_OBJECT virtual void SetCheck(bool check, bool bNoSound = true);
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
/*0x1d8*/ int          MouseButtonState;
/*0x1dc*/ bool         bPicture;
/*0x1e0*/ CRadioGroup* pGroup;
/*0x1e4*/ bool         bChecked;                 // Checked
/*0x1e5*/ bool         bMouseOverLastFrame;
/*0x1e8*/ CXPoint      DecalOffset;
/*0x1f0*/ CXSize       DecalSize;
/*0x1f8*/ COLORREF     DecalTint;                // Color
/*0x1fc*/ CXRect       TextOffsets;
/*0x20c*/ int          TextModeBits;
/*0x210*/ COLORREF     Mouseover;
/*0x214*/ COLORREF     Pressed;
/*0x218*/ COLORREF     Disabled;
/*0x21c*/ unsigned int CoolDownBeginTime;
/*0x220*/ unsigned int CoolDownDuration;
/*0x224*/ CXStr        Indicator;
/*0x228*/ unsigned int IndicatorVal;
/*0x22c*/ CTextObjectInterface* pIndicatorTextObject;
/*0x230*/ CButtonDrawTemplate DrawTemplate;
/*0x264*/ bool         bAllowButtonClickThrough;
/*0x265*/ bool         bCoolDownDoDelayedStart;
/*0x266*/ bool         bIsCheckbox;
/*0x267*/ bool         bIsDrawLasso;
/*0x268*/ uint32_t     ButtonStyle;              // tbd
/*0x26c*/ CLabel*      pButtonLabel;
/*0x270*/

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

using CBUTTONWND [[deprecated]] = CButtonWnd;
using PCBUTTONWND [[deprecated]] = CButtonWnd*;

//============================================================================
// CCheckBoxWnd
//============================================================================

class [[offsetcomments]] CCheckBoxWnd : public CButtonWnd
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
/*0x270*/ bool bOrgState;
/*0x274*/
};

//============================================================================
// CComboWnd
//============================================================================

class [[offsetcomments]] CComboWnd : public CXWnd
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
/*0x1d8*/ CListWnd*                    pListWnd;
/*0x1dc*/ int                          ListHeightMax;
/*0x1e0*/ int                          ListHeight;
/*0x1e4*/ CButtonDrawTemplate          ButtonDrawTemplate;
/*0x218*/
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

class [[offsetcomments]] CEditBaseWnd : public CXWnd
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
/*0x1d8*/ eTextAlign   eAlign = eta_Left;
/*0x1dc*/ int          StartPos = 0;
/*0x1e0*/ int          EndPos = 0;
/*0x1e4*/ int          MaxChars = -1;
/*0x1e8*/ int          MaxBytesUTF8 = -1;
/*0x1ec*/ CXStr        InputText;
/*0x1f0*/ int          TagPrintableStarts[EDITWND_MAX_TAGS];
/*0x218*/ int          TagPrintableEnds[EDITWND_MAX_TAGS];
/*0x240*/ int          TagOriginalStarts[EDITWND_MAX_TAGS];
/*0x268*/ int          TagOriginalEnds[EDITWND_MAX_TAGS];
/*0x290*/ int          TagDynamicSize[EDITWND_MAX_TAGS];
/*0x2b8*/ int          TagCodes[EDITWND_MAX_TAGS];
/*0x2e0*/ CXStr        TagStrings[EDITWND_MAX_TAGS];
/*0x308*/ int          TagCount;
/*0x30c*/ uint32_t     EditStyle;
/*0x310*/
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

class [[offsetcomments]] CEditWnd : public CEditBaseWnd
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

/*0x310*/ bool         bAnchorAtStart;
/*0x311*/ bool         bCaretAtEnd;
/*0x312*/ bool         bAutoVScrollCalc;
/*0x313*/ bool         bEditable;
/*0x314*/ CXStr        FilterChars;
/*0x318*/ int          EditMode;
/*0x31c*/ wchar_t      PasswordChar;
/*0x320*/ ArrayClass2<uint32_t> LineIndices;
/*0x338*/
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
class [[offsetcomments]] CGaugeWnd : public CXWnd
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

/*0x1d8*/ int          EQType;
/*0x1dc*/ D3DCOLOR     FillTint;
/*0x1e0*/ D3DCOLOR     LinesFillTint;
/*0x1e4*/ bool         bDrawLinesFill;
/*0x1e8*/ int          TextOffsetX;
/*0x1ec*/ int          TextOffsetY;
/*0x1f0*/ int          GaugeOffsetX;
/*0x1f4*/ int          GaugeOffsetY;
/*0x1f8*/ float        LastFrameVal;
/*0x1fc*/ CXStr        LastFrameName;
/*0x200*/ int          LastFrameTime;
/*0x204*/ int          LastFrameTarget;
/*0x208*/ CXStr        GaugeTooltip;
/*0x20c*/ int          TooltipVal;
/*0x210*/ CGaugeDrawTemplate DrawTemplate;
/*0x22c*/ CTextObjectInterface* pTextObject;
/*0x230*/ CXStr        NextDrawStr;
/*0x234*/ bool         bSmooth;
/*0x238*/ int          TargetVal;
/*0x23c*/ bool         bUseTargetVal;
/*0x240*/
};

//============================================================================
// CHotButton
//============================================================================

class [[offsetcomments]] CHotButton : public CXWnd
{
public:
	CHotButton(CXWnd* parent, uint32_t id, const CXRect& rect, CButtonWnd* button,
		CInvSlotWnd* invSlot, CSpellGemWnd* gemSlot);
	virtual ~CHotButton();

	EQLIB_OBJECT void SetButtonSize(int percent, bool bUpdateParent = true);

	//----------------------------------------------------------------------------
	// data members

/*0x1d8*/ int          BarIndex;
/*0x1dc*/ int          ButtonIndex;
/*0x1e0*/ unsigned int Timer;
/*0x1e4*/ CTextureAnimation* DecalIcon;
/*0x1e8*/ int          LastButtonType;
/*0x1ec*/ int          LastButtonSlot;
/*0x1f0*/ char         LastButtonPage;
/*0x1f1*/ EqItemGuid   LastItemGuid;
/*0x204*/ int          LastItemId;
/*0x208*/ int          LastIconType;
/*0x20c*/ int          LastIconSlot;
/*0x210*/ CXStr        LastLabel;
/*0x214*/ CXStr        DefaultLabel;
/*0x218*/ bool         bForceUpdate;
/*0x21c*/ CTextObjectInterface* pKeyMapText;
/*0x220*/ int          Unknown0x228;
/*0x224*/ CButtonWnd*  pButtonWnd;
/*0x228*/ CInvSlotWnd* pInvSlotWnd;
/*0x22c*/ CSpellGemWnd* pSpellGemWnd;
/*0x230*/ CXSize       BaseSize;
/*0x238*/ int          ButtonPercentSize;
/*0x23c*/ CXSize       BaseButtonSize;
/*0x244*/ CXSize       BaseDecalSize;
/*0x24c*/ CXSize       BaseInvButtonSize;
/*0x254*/ CXSize       BaseSpellButtonSize;
/*0x25c*/ int          Unknown0x264;
/*0x260*/
};
//============================================================================
// CLabelWnd
//============================================================================

// CLabelWnd__CLabelWnd_x
// size 0x200 see 8D5699 in Aug 10 2017 Live
// size 0x210 see 8DCE59 in Sep 11 2017 Test
// size 0x200 see 668D5B in Oct 17 2017 Live
// size 0x1e4 see 86BFC9 in rof2
class [[offsetcomments]] CLabelWnd : public CXWnd
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
/*0x1d8*/ bool         bNoWrap;
/*0x1d9*/ bool         bAlignRight;
/*0x1da*/ bool         bAlignCenter;
/*0x1dc*/ int          xOffset;
/*0x1e0*/ bool         bResizeHeightToText;
/*0x1e4*/ int          Unknown0x204;
/*0x1e8*/ CXStr        Text;
/*0x1ec*/ int          Unknown0x20c;
/*0x1f0*/ bool         Unknown0x210;
/*0x1f4*/ int          Unknown0x214;
/*0x1f8*/
};

//============================================================================
// CLabel
//============================================================================

// CLabel__CLabel_x
// CSidlManager__CreateLabel_x has this
// size 0x1e8 see 755709 in Rof2
// size is 0x220 see 7A5849 in Oct 13 2017 Test
class [[offsetcomments]] CLabel : public CLabelWnd
{
public:
	// constructor / destructor
	CLabel(CXWnd* parent, uint32_t id, CXRect rect, int EQType);
	virtual ~CLabel();

	// virtual functions
	virtual void UpdateText() override;

	// data members
/*0x1f8*/ int          EQType;
/*0x1fc*/
};
using CLABEL [[deprecated]] = CLabel;
using PCLABEL [[deprecated]] = CLabel*;

//============================================================================
// CListWnd
//============================================================================

struct [[offsetcomments]] STreeData
{
/*0x00*/ int                      Depth = 0;
/*0x04*/ bool                     bIsExpandable = false;
/*0x08*/
};

struct [[offsetcomments]] SListWndCell
{
/*0x00*/ const CTextureAnimation* pTA = nullptr;
/*0x04*/ CXStr                    Text;
/*0x08*/ COLORREF                 Color = RGB(255, 255, 255);
/*0x0c*/ bool                     bOnlyDrawTexture = false;
/*0x10*/ CXWnd*                   pWnd = nullptr;
/*0x14*/
};

struct [[offsetcomments]] SListWndLine
{
/*0x000*/ ArrayClass<SListWndCell> Cells;
/*0x010*/ uint64_t                Data = 0;
/*0x018*/ int                     Height = -1;
/*0x01c*/ bool                    bSelected = false;
/*0x01d*/ bool                    bEnabled = true;
/*0x020*/ STreeData               Treedata;
/*0x028*/ char                    TooltipText[256];
/*0x128*/ bool                    bVisible = true;
/*0x12c*/
};

class [[offsetcomments]] SListWndSortInfo
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

struct [[offsetcomments]] SListWndColumn
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
/*0x44*/ ///*0x44*/ int           Filler0x44;
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
class [[offsetcomments]] CListWnd : public CXWnd
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
	EQLIB_OBJECT CXStr GetItemText(int index, int subIndex = 0) const;
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

	// Index of the first row in the list where the text in column matches predicate, or -1 if no row matches
	EQLIB_OBJECT int IndexOf(int column, const std::function<bool(const CXStr)>& predicate);

	// Index of the first row in the list where the text in the first column matches predicate, or -1 if no row matches
	EQLIB_OBJECT int IndexOf(const std::function<bool(const CXStr)>& predicate);

	// True if the list contains a row where the text in columns matches predicate
	EQLIB_OBJECT bool Contains(int column, const std::function<bool(const CXStr)>& predicate);

	// True if the list contains a row the text in the first column matches predicate
	EQLIB_OBJECT bool Contains(const std::function<bool(const CXStr)>& predicate);

	//----------------------------------------------------------------------------
	// data members

/*0x1d8*/ int                 Unknown0x1f0;
/*0x1dc*/ ArrayClass<SListWndLine> ItemsArray;       // see CListWnd__GetItemData_x 0x8BD768                 add     ecx, 1F4h
/*0x1ec*/ ArrayClass<SListWndColumn> Columns;
/*0x1fc*/ int                 CurSel;
/*0x200*/ int                 CurCol;
/*0x204*/ int                 DownItem;
/*0x208*/ int                 ScrollOffsetY;
/*0x20c*/ int                 HeaderHeight;
/*0x210*/ int                 FirstVisibleLine;
/*0x214*/ int                 SortCol;
/*0x218*/ bool                bSortAsc;
/*0x219*/ bool                bFixedHeight;
/*0x21a*/ bool                bOwnerDraw;
/*0x21b*/ bool                bCalcHeights;
/*0x21c*/ bool                bColumnSizable;
/*0x220*/ int                 LineHeight;
/*0x224*/ int                 ColumnSepDragged;
/*0x228*/ int                 ColumnSepMouseOver;
/*0x22c*/ COLORREF            HeaderText;
/*0x230*/ COLORREF            Highlight;
/*0x234*/ COLORREF            Selected;
/*0x238*/ CUITextureInfo      BGHeader;
/*0x250*/ COLORREF            BGHeaderTint;
/*0x254*/ CTextureAnimation*  pRowSep;
/*0x258*/ CTextureAnimation*  pColumnSep;
/*0x25c*/ CEditBaseWnd*       pEditCell;
/*0x260*/ IListItemDataHandler* pItemDataHandler;
/*0x264*/ bool                bHasItemTooltips;
/*0x268*/ CXRect              PrevInsideRect;
/*0x278*/ uint32_t            ListWndStyle;
/*0x27c*/ time_t              LastVisibleTime;
/*0x284*/

	struct [[offsetcomments]] VirtualFunctionTable : public CXWnd::VirtualFunctionTable
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
	/*0x18c*/
	};

	// points to the eq instance of the virtual function table for this class
	static VirtualFunctionTable* sm_vftable;
};

//============================================================================
// CPageWnd
//============================================================================

class [[offsetcomments]] CPageWnd : public CSidlScreenWnd
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
class [[offsetcomments]] CSliderWnd : public CXWnd
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

/*0x1d8*/ CButtonDrawTemplate      bdtThumb;
/*0x20c*/ CTextureAnimation*       ptaBackground;
/*0x210*/ CTextureAnimation*       ptaEndCapLeft;
/*0x214*/ CTextureAnimation*       ptaEndCapRight;
/*0x218*/
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

struct [[offsetcomments]] SFontTag
{
/*0x00*/ CTextureFont*      face;
/*0x04*/ COLORREF           color;
/*0x08*/
};

using SStyleTag = uint32_t;

const uint32_t STML_TAG_BOLD = 0;
const uint32_t STML_TAG_UNDERLINE = 2;

struct [[offsetcomments]] SFormattedText
{
/*0x00*/ SFontTag           Font;
/*0x08*/ SStyleTag          Style;
/*0x0c*/ int                Left;
/*0x10*/ int                Right;
/*0x14*/ CXStr              Text;
/*0x18*/ int32_t            LinkID;
/*0x1c*/ CTextureAnimation* Texture;
/*0x20*/ int32_t            TableID;
/*0x24*/ int32_t            IndexStart;
/*0x28*/
};

struct [[offsetcomments]] STextLine
{
/*0x00*/ ArrayClass<SFormattedText> TextPieces;
/*0x10*/ int                yBottom;
/*0x14*/ int                yTop;
/*0x18*/ int32_t            IndexStart;
/*0x1c*/
};

struct [[offsetcomments]] SLinkInfo
{
/*0x00*/ ELinkType          Type = STML_LINK_EMPTY;
/*0x04*/ uint32_t           MsgID = -1;
/*0x08*/ CXStr              Name;
/*0x0c*/ EStmlTargetValue   TargetType = STML_TARGET_SELF;
/*0x10*/
};

struct SParseVariables
{
	// todo ...
};

struct [[offsetcomments]] SHistoryElement
{
/*0x00*/ SLinkInfo          sLink;
/*0x10*/ CXStr              STMLText;
/*0x14*/
};

enum ESTMLParseState
{
	STML_PARSE_STATE_BODY,
	STML_PARSE_STATE_HEAD,
};


// size is 0x2b8 in sep 11 2017 test see 8DCF69
class [[offsetcomments]] CStmlWnd : public CXWnd
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
	EQLIB_OBJECT void SetSTMLText(CXStr, bool addToHistory = true, SLinkInfo* = nullptr);
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
/*0x1d8*/ CXStr                        STMLText;
/*0x1dc*/ CircularArrayClass2<STextLine> TextLines;
/*0x204*/ int32_t                      TextTotalHeight;
/*0x208*/ int32_t                      TextTotalWidth;
/*0x20c*/ int32_t                      Unknown0x224;
/*0x210*/ ArrayClass2<SLinkInfo>       Links;                        // size 0x1c at 0x228 for sure see 8F4487 in Sep 11 2017 test
/*0x228*/ ArrayClass<STable>           Tables;
/*0x238*/ bool                         bReparseNow;
/*0x239*/ bool                         bResized;
/*0x23a*/ bool                         bAlignCenter;
/*0x23c*/ int                          LineSpacingAdjust;
/*0x240*/ int32_t                      CapturedLinkID;
/*0x244*/ int32_t                      MousedOverLinkID;
/*0x248*/ COLORREF                     BackGroundColor;
/*0x24c*/ COLORREF                     TextColor;
/*0x250*/ COLORREF                     LinkColor;
/*0x254*/ COLORREF                     VLinkColor;
/*0x258*/ COLORREF                     ALinkColor;
/*0x25c*/ COLORREF                     MLinkColor;
/*0x260*/ ESTMLParseState              CurrentParseState;
/*0x264*/ ArrayClass2<SHistoryElement> HistoryArray;
/*0x27c*/ int32_t                      HistoryIndex;
/*0x280*/ CStmlReport* pStmlReport;
/*0x284*/ int                          MaxLines;
/*0x288*/ int                          PlayerContextMenuIndex;
/*0x28c*/ int                          Unknown0x2ac;
/*0x290*/ int                          Unknown0x2b0;
/*0x294*/ int                          Unknown0x2b4;
/*0x298*/
};

//============================================================================
// CTabWnd
//============================================================================

class [[offsetcomments]] CTabWnd : public CXWnd
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

class [[offsetcomments]] CTreeView : public CListWnd
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

struct [[offsetcomments]] AdvancedLootItemNPC
{
/*0x00*/ unsigned int  CorpseID;                 // spawnId of the corpse that has this lootitem
/*0x04*/ short         StackCount;
/*0x08*/ unsigned int  Expiration;
/*0x0c*/ bool          Locked;
/*0x0d*/ char          Name[0x40];
/*0x50*/ //more data here?
};
using LOOTDETAILS [[deprecated]] = AdvancedLootItemNPC;
using PLOOTDETAILS [[deprecated]] = AdvancedLootItemNPC*;

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
struct [[offsetcomments]] AdvancedLootItem
{
/*0x00*/ int64_t       ItemID;                   // EqGuid?
/*0x08*/ char          Name[0x40];
/*0x48*/ int           IconID;
/*0x4c*/ bool          bStackable;
/*0x50*/ int           MaxStack;
/*0x54*/ bool          NoDrop;
/*0x58*/ int           ComboID;
/*0x5c*/ unsigned int  LootID;
/*0x60*/ eAdvLootState State;
/*0x64*/ bool          bAutoRoll;
/*0x65*/ bool          ActivelyManaged;          // User has the manage Window up
/*0x66*/ bool          ContextMenu;              // item has a context menu
/*0x67*/ bool          AskRandomMode;            // item is in AskRandom mode
/*0x68*/ bool          CLootInProgress;
/*0x69*/ bool          PLootInProgress;
/*0x6c*/ SoeUtil::Array<AdvancedLootItemNPC> LootDetails;
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
using LOOTITEM [[deprecated]] = AdvancedLootItem;
using PLOOTITEM [[deprecated]] = AdvancedLootItem*;

struct [[offsetcomments]] AdvancedLootItemList
{
/*0x00*/ SoeUtil::Array<AdvancedLootItem> Items;
/*0x10*/ bool         bIsPersonalLoot;
/*0x14*/ CListWnd*    SharedLootList;
/*0x18*/ CComboWnd*   PersonalLootList;
/*0x1c*/
};
using LOOTLIST [[deprecated]] = AdvancedLootItemList;
using PLOOTLIST [[deprecated]] = AdvancedLootItemList*;

class CorpseData;
class RefreshCorpseItemChoices;
class CGroupMemberBase;
struct RaidMember;

// CAdvancedLootWnd__CAdvancedLootWnd_x
// size 0x310 see 4CEA0D in Nov 29 2017 Beta
class [[offsetcomments]] CAdvancedLootWnd : public CSidlScreenWnd, public PopDialogHandler, public WndEventHandler
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
	EQLIB_OBJECT void DoSharedAdvLootAction(AdvancedLootItem* pLootItem, const CXStr& Assignee, bool Action, int Quantity);

	//----------------------------------------------------------------------------
	// data members

/*0x228*/ uint8_t      Unknown0x0240[0x8c];      // ui controls
/*0x2b4*/ AdvancedLootItemList* pCLootList;      // below ref to aAdlw_applyfilt
/*0x2b8*/ AdvancedLootItemList* pPLootList;      // below ref to aAdlw_cllwnd
/*0x2bc*/ DWORD        Unknown0x2dc;
/*0x2c0*/ DWORD        Unknown0x2e0;
/*0x2c4*/ DWORD        Unknown0x2e4;
/*0x2c8*/ DWORD        TotalLootCount;
/*0x2cc*/ DWORD        Unknown0x2ec;
/*0x2d0*/ DWORD        ContextMenuId;
/*0x2d4*/ DWORD        CLastStackSize;
/*0x2d8*/ BYTE         Unknown0x2f8[0x18];
/*0x2f0*/
};
using EQADVLOOTWND [[deprecated]] = CAdvancedLootWnd;
using PEQADVLOOTWND [[deprecated]] = CAdvancedLootWnd*;


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

class [[offsetcomments]] CBandolierWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CBandolierWnd();
	virtual ~CBandolierWnd();

/*0x224*/ CButtonWnd*        pAddButton;
/*0x228*/ CButtonWnd*        pDeleteButton;
/*0x22c*/ CButtonWnd*        pUseButton;
/*0x230*/ CButtonWnd*        pMkHotButton;
/*0x234*/ CButtonWnd*        pAutoSwapButton;
/*0x238*/ CButtonWnd*        pDisplayButtons[MAX_BANDOLIER_SLOTS];
/*0x248*/ CListWnd*          pWeaponSetList;
/*0x24c*/
};

//============================================================================
// CBankWnd
//============================================================================

class [[offsetcomments]] CBankWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
/*0x224*/ int          MoneyButtonIndex;
/*0x228*/ unsigned int NextRefreshTime;
/*0x22c*/ bool         bInventoryWasActive;
/*0x22d*/ bool         bRealEstateManagementWasActive;
/*0x230*/ CButtonWnd*  MoneyButtons[5];          // including shared plat
/*0x244*/ CLabel*      BankerNameLabel;
/*0x248*/ CInvSlotWnd* InvSlotWindows[NUM_BANK_SLOTS];
/*0x2a8*/ CLabel*      SharedBankLabel;
/*0x2ac*/ CInvSlotWnd* SharedSlotWindows[NUM_SHAREDBANK_SLOTS];
/*0x2c4*/ CButtonWnd*  DoneButton;
/*0x2c8*/ CButtonWnd*  ChangeButton;
/*0x2cc*/ CButtonWnd*  AutoButton;
/*0x2d0*/ CButtonWnd*  AltStorageButton;
/*0x2d4*/ CButtonWnd*  FindItemButton;
/*0x2d8*/ int          BankSize;
/*0x2dc*/ int          Unknown0x2F4;
/*0x2e0*/

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
// CBazaarSearchWnd_size: 0x92c0 (see 54464D) in Aug 15 2019 Live
class [[offsetcomments]] CBazaarSearchWnd : public CSidlScreenWnd, public WndEventHandler
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
/*0x0224*/ BYTE        Unknown0x0240[0x8fec];
/*0x9210*/ void**      ppTraderData;
/*0x9214*/ DWORD       hashVal;                  // find in CBazaarSearchWnd__HandleBazaarMsg_x
/*0x9218*/ CListWnd*   pItemList;
/*0x921c*/ CButtonWnd* pQueryButton;
/*0x9220*/ CButtonWnd* pWelcomeButton;
/*0x9224*/ CButtonWnd* pUpdatePlayerButton;
/*0x9228*/ CButtonWnd* pRequestItemButton;
/*0x922c*/ CButtonWnd* pRequestPreviewButton;
/*0x9230*/ CButtonWnd* pFindTraderButton;
/*0x9234*/ CButtonWnd* pHideTradersButton;
/*0x9238*/ CButtonWnd* pDefaultButton;
/*0x923c*/ CButtonWnd* pBuyButton;
/*0x9240*/ CLabelWnd*  pItemNameLabel;
/*0x9244*/ CLabelWnd*  pPlayersLabel;
/*0x9248*/ CLabelWnd*  pItemSlotLabel;
/*0x924c*/ CLabelWnd*  pStatSlotLabel;
/*0x9250*/ CLabelWnd*  pRaceSlotLabel;
/*0x9254*/ CLabelWnd*  pClassSlotLabel;
/*0x9258*/ CLabelWnd*  pItemTypeLabel;
/*0x925c*/ CLabelWnd*  pSearchResultLabel;
/*0x9260*/ CLabelWnd*  pMaxPriceLabel;
/*0x9264*/ CLabelWnd*  pMinPriceLabel;
/*0x9268*/ CLabelWnd*  pItemPrestigeLabel;
/*0x926c*/ CLabelWnd*  pItemAugmentLabel;
/*0x9270*/ CComboWnd*  pItemSlotCombobox;
/*0x9274*/ CComboWnd*  pStatSlotCombobox;
/*0x9278*/ CComboWnd*  pRaceSlotCombobox;
/*0x927c*/ CComboWnd*  pClassSlotCombobox;
/*0x9280*/ CComboWnd*  pItemTypeCombobox;
/*0x9284*/ CComboWnd*  pPlayersCombobox;
/*0x9288*/ CComboWnd*  pItemPrestigeCombobox;
/*0x928c*/ CComboWnd*  pItemAugmentCombobox;
/*0x9290*/ CEditWnd*   pItemNameInput;
/*0x9294*/ CEditWnd*   pMaxPriceInput;
/*0x9298*/ CEditWnd*   pMinPriceInput;
/*0x929c*/ CEditWnd*   pMaxLevelInput;
/*0x92a0*/ CEditWnd*   pMinLevelInput;
/*0x92a4*/ CEditWnd*   pMaxResultsPerTraderInput;
/*0x92a8*/ BYTE        Unknown0x92C8[0x8];
/*0x92b0*/
};
using BAZAARSEARCHWND [[deprecated]] = CBazaarSearchWnd;
using PBAZAARSEARCHWND [[deprecated]] = CBazaarSearchWnd*;

//============================================================================
// CBazaarWnd
//============================================================================

class [[offsetcomments]] CBazaarWnd : public CSidlScreenWnd, public WndEventHandler
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

class [[offsetcomments]] CBodyTintWnd : public CSidlScreenWnd, public WndEventHandler
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
// CBuffWindow_size: 0x708 (see 543C79) in Aug 15 2019 Live
class [[offsetcomments]] CBuffWindow : public CSidlScreenWnd, public WndEventHandler
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
/*0x224*/ uint8_t     Unknown0x0240[0xb8];
/*0x2dc*/ CButtonWnd* pBuff[0x24];
/*0x36c*/ uint8_t     Unknown0x038c[0x210];
/*0x57c*/ int         BuffId[NUM_LONG_BUFFS];
/*0x624*/ int         BuffTimer[NUM_LONG_BUFFS];
/*0x6cc*/ uint8_t     Unknown0x06ec[0x28];
/*0x6f4*/ int         MaxLongBuffs;             // 0x2a (NUM_LONG_BUFFS)
/*0x6f8*/ int         MaxShortBuffs;            // 0x37 (NUM_SHORT_BUFFS)
/*0x6fc*/ uint8_t     Unknown0x071c[0xc];
/*0x708*/
};
using EQBUFFWINDOW [[deprecated]] = CBuffWindow;
using PEQBUFFWINDOW [[deprecated]] = CBuffWindow*;

//============================================================================
// CCastingWnd
//============================================================================

class CCastingWnd : public CSidlScreenWnd
{
public:
	CCastingWnd(class CXWnd*);
	virtual ~CCastingWnd();
};

//============================================================================
// CCastSpellWnd
//============================================================================

class CSpellGemWnd;

// pinstCCastSpellWnd_x
// CCastSpellWnd__CCastSpellWnd aCastspellwnd
// CCastSpellWnd_size: 0x2c0 (see 544037) in Aug 15 2019 Live 
class [[offsetcomments]] CCastSpellWnd : public CSidlScreenWnd, public PopDialogHandler, public WndEventHandler
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

/*0x228*/ CPopDialogWnd* pCurrentPop;
/*0x22c*/ unsigned int   lastRefresh;
/*0x230*/ bool           bHorizontal;
/*0x234*/ CSpellGemWnd*  SpellSlots[NUM_SPELL_GEMS]; // CSPW_Spell%d
/*0x26c*/ BYTE        Unknown0x028c[0x54];
/*0x2c0*/
};
using EQCASTSPELLWINDOW [[deprecated]] = CCastSpellWnd;
using PEQCASTSPELLWINDOW [[deprecated]] = CCastSpellWnd*;

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

// Size is 82 see 4E4072 in Mar 05 2019 Test
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
class [[offsetcomments]] CChatWindowManager
{
public:
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
/*0x128*/ CChatWindow*       ChannelMap[MAX_CHAT_FILTERS];       // channel map
/*0x270*/ CContextMenu*      pCM_MainMenu;
/*0x274*/ int                ScrollbarIndex;
/*0x278*/ CContextMenu*      pCM_LanguageMenu;
/*0x27c*/ int                LanguageMenuIndex;
/*0x280*/ CContextMenu*      pCM_FilterMenu;
/*0x284*/ int                FilterMenuIndex;
/*0x288*/ int                ChatChannelFilterMenuIndex;
/*0x28c*/ int                MeleeFilterSubMenuIndex;
/*0x290*/ int                SpellsFilterSubMenuIndex;
/*0x294*/ CContextMenu*      pCM_MeleeMenu;
/*0x298*/ int                MeleeFilterMenuIndex;
/*0x29c*/ CContextMenu*      pCM_SpellMenu;
/*0x2a0*/ int                SpellsMenuIndex;
/*0x2a4*/ CContextMenu*      pCM_ChannelMenu;
/*0x2a8*/ int                ChannelMenuIndex;
/*0x2ac*/ CContextMenu*      pCM_DefaultChannelMenu;
/*0x2b0*/ int                DefaultChannelMenu;
/*0x2b4*/ int                DefaultChannelMenu2;
/*0x2b8*/ CContextMenu*      pCM_ChatChannelDefChan;
/*0x2bc*/ int                ChatChannelDefChanIndex;
/*0x2c0*/ CContextMenu*      pCM_YourHitsMenu;
/*0x2c4*/ int                YourHitsMenuIndex;
/*0x2c8*/ CContextMenu*      pCM_YourMissesMenu;
/*0x2cc*/ int                YourMissesMenuindex;
/*0x2d0*/ CContextMenu*      pCM_YouBeingHitMenu;
/*0x2d4*/ int                YouBeingHitMenuindex;
/*0x2d8*/ CContextMenu*      pCM_OthersHitsMenu;
/*0x2dc*/ int                OthersHitsMenuindex;
/*0x2e0*/ CContextMenu*      pCM_OthersMissesMenu;
/*0x2e4*/ int                OthersMissesMenuindex;
/*0x2e8*/ CContextMenu*      pCM_AllContextMenu;
/*0x2ec*/ int                AllContextMenuindex;
/*0x2f0*/ CContextMenu*      pCM_HitModesMenu;
/*0x2f4*/ int                HitModesMenuindex;
/*0x2f8*/ CContextMenu*      pCM_ReplyToMenu;
/*0x2fc*/ int                ReplyToMenuindex;
/*0x300*/ CContextMenu*      pCM_TellFriendMenu;
/*0x304*/ int                TellFriendMenuindex;
/*0x308*/ CContextMenu*      pCM_TellRaidmemberMenu;
/*0x30c*/ int                TellRaidmemberMenuindex;
/*0x310*/ int                ReplyToSubIndex;
/*0x314*/ int                TellFriendSubIndex;
/*0x318*/ int                TellRaidmemberSubIndex;
/*0x31c*/ int                HitModes[MAX_HITMODES];
/*0x33c*/ int                DefaultChannel;
/*0x340*/ CContextMenu*      pCM_RandomFilterMenu;
/*0x344*/ int                RandomFilterIndex;
/*0x348*/ int                RandomFilterSubIndex;
/*0x34c*/ CContextMenu*      pCM_EnvironmentalDamageMenu;
/*0x350*/ int                EnvironmentalDamageIndex;
/*0x354*/ int                EnvironmentalDamageSubIndex;
/*0x358*/ CContextMenu*      pCM_DamageShieldsFilterMenu;
/*0x35c*/ int                DamageShieldsFilterIndex;
/*0x360*/ int                DamageShieldsFilterSubIndex;
/*0x364*/ CContextMenu*      pCM_BeneficialSpellsFilterMenu;
/*0x368*/ int                BeneficialSpellsFilteIndex;
	/*0x36c*/
};
using EQCHATMGR [[deprecated]] = CChatWindowManager;
using PEQCHATMGR [[deprecated]] = CChatWindowManager *;

//============================================================================
// CChatWindow
//============================================================================

// in CChatWindow__SetChatFont see 692847 in eqgame.exe Test dated Jun 28 2016
const int EQ_CHAT_FONT_OFFSET = 0x11c;

// CChatWindow__CChatWindow_x
// Size 0x378 see 69265D in 20 Jun 2017 Test exe
class [[offsetcomments]] CChatWindow : public CSidlScreenWnd
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

/*0x220*/ CChatWindowManager* ChatManager;
/*0x224*/ CEditWnd*    InputWnd;
/*0x228*/ CStmlWnd*    OutputWnd;
/*0x22c*/ int          ChatChannel;
/*0x230*/ int          ChatChannelIndex;
/*0x234*/ char         TellTarget[0x40];
/*0x274*/ int          Language;
/*0x278*/ bool         bIsMainChat;
/*0x279*/ bool         bIsTellWnd;
/*0x27c*/ int          TimestampFormat;
/*0x280*/ COLORREF     TimestampColor;
/*0x284*/ bool         bTimestampMatchChatColor;
/*0x288*/ CXStr        CommandHistory[0x28];     // see 690DAA in apr 11 2017 test
/*0x328*/ int          HistoryIndex;
/*0x32c*/ int          HistoryLastShown;
/*0x330*/ int          FontSize;                 // style
/*0x334*/ int          AlwaysChathereIndex;      // menu
/*0x338*/ int          NamesContextMenu;         // guess
/*0x33c*/ int          ContextMenuID;            // also a guess
/*0x340*/ int          ContextMenuSubID[0xa];    // this is not correct but ill fix it later.
/*0x368*/
};

using EQCHATWINDOW [[deprecated]] = CChatWindow;
using PEQCHATWINDOW [[deprecated]] = CChatWindow *;

//============================================================================
// CColorPickerWnd
//============================================================================

class [[offsetcomments]] CColorPickerWnd : public CSidlScreenWnd, public WndEventHandler
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

/*0x224*/ int                ContextMenuIndex;
/*0x228*/ int                MaxSliderValue;
/*0x22c*/ CXWnd*             pwndCaller;
/*0x230*/ CButtonWnd*        ColorButton[16];
/*0x270*/ int                RedSliderValue;
/*0x274*/ CSliderWnd*        RedSlider;
/*0x278*/ CEditWnd*          RedSliderInputEdit;
/*0x27c*/ int                GreenSliderValue;
/*0x280*/ CSliderWnd*        GreenSlider;
/*0x284*/ CEditWnd*          GreenSliderInputEdit;
/*0x288*/ int                BlueSliderValue;
/*0x28c*/ CSliderWnd*        BlueSlider;
/*0x290*/ CEditWnd*          BlueSliderInputEdit;
/*0x294*/ CButtonWnd*        AcceptButton;
/*0x298*/
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
class [[offsetcomments]] CCompassWnd : public CSidlScreenWnd, public WndEventHandler
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

/*0x224*/ CStaticAnimationTemplate* pStrip1;
/*0x228*/ CStaticAnimationTemplate* pStrip2;
	// WIP
/*0x22c*/ BOOL         DrawLine;
/*0x230*/ DWORD        Unknown0x170;
/*0x234*/ DWORD        LineRed;
/*0x238*/ DWORD        LineGreen;
/*0x23c*/ DWORD        LineBlue;
/*0x240*/
};
using EQCOMPASSWINDOW [[deprecated]] = CCompassWnd;
using PEQCOMPASSWINDOW [[deprecated]] = CCompassWnd*;

//============================================================================
// CConfirmationDialog
//============================================================================

// This is actually CPopDialogWnd.
// TODO: Rename this
class [[offsetcomments]] CConfirmationDialog : public CSidlScreenWnd
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
/*0x220*/ CStmlWnd*    OutputText;
/*0x224*/ CButtonWnd*  pYesButton;
/*0x228*/ CButtonWnd*  pNoButton;
/*0x22c*/ CButtonWnd*  pCancelButton;
/*0x230*/ CButtonWnd*  pOKButton;
/*0x234*/ BYTE         Unknown0x170[0x18];
/*0x24c*/
};

//============================================================================
// CContainerWnd
//============================================================================

class [[offsetcomments]] CContainerWnd : public CSidlScreenWnd
{
public:
	CContainerWnd(CXWnd*);
	virtual ~CContainerWnd();

	virtual int OnProcessFrame() override;
	virtual int PostDraw() override;
	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT void CheckCloseable();
	EQLIB_OBJECT void SetContainer(CONTENTS*& pContainer, const ItemGlobalIndex& location); // should be ItemBasePtr
	EQLIB_OBJECT bool ContainsNoDrop();
	EQLIB_OBJECT void HandleCombine();

	// TODO: Fix for inaccuracies
/*0x220*/ CONTENTS*     pContents;
/*0x224*/ ItemGlobalIndex Location;
/*0x230*/ VeArray<CInvSlotWnd*> InvSlotWnds;
/*0x23c*/ CButtonWnd*   pCombineButton;
/*0x240*/ CButtonWnd*   pDoneButton;
/*0x244*/ CButtonWnd*   pStandardDoneButton;
/*0x248*/ CButtonWnd*   pCombineDoneButton;
/*0x24c*/ CButtonWnd*   pContainerIcon;
/*0x250*/ CButtonWnd*   pContainerStandardIcon;
/*0x254*/ CButtonWnd*   pContainerCombineIcon;
/*0x258*/ CTextureAnimation* pIconAnimation;
/*0x25c*/ CLabel*       ContainerLabel;
/*0x260*/ CInvSlotWnd*  pContainerSlotTemplate;
/*0x264*/ CXWnd*        pStandardItems;
/*0x268*/ CXWnd*        pStandardItemsWithDone;
/*0x26c*/ CXWnd*        pCombineItems;
/*0x270*/ CStmlWnd*     pStandardSize;
/*0x274*/ CStmlWnd*     pCombineSize;
/*0x278*/ bool          bCombineValid;
/*0x279*/ bool          bUserCloseable;
/*0x27c*/ int           ContainerType;            // classic = 0, standard = 1, combine = 2
/*0x280*/ int           IndexDoneButton;
/*0x284*/ CContextMenu* ContextMenu;
/*0x288*/

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
using EQCONTAINERWINDOW [[deprecated]] = CContainerWnd;
using PEQCONTAINERWINDOW [[deprecated]] = CContainerWnd *;

#define MAX_CONTAINERS           40

class [[offsetcomments]] CContainerMgr
{
public:
	CContainerMgr();
	virtual ~CContainerMgr();

	EQLIB_OBJECT bool CloseAllContainers();
	EQLIB_OBJECT EQ_Item* GetWorldContainerItem(int);
	EQLIB_OBJECT void ClearWorldContainerItems();
	EQLIB_OBJECT void CloseContainer(CONTENTS**, bool deleteWindow);
	EQLIB_OBJECT void CloseEQContainer(EQ_Container*);
	EQLIB_OBJECT void OpenContainer(CONTENTS**, const ItemGlobalIndex& location, bool allowTradeskill = true);
	EQLIB_OBJECT void OpenWorldContainer(EQ_Container*, unsigned long);
	EQLIB_OBJECT void Process();
	EQLIB_OBJECT void SetWorldContainerItem(EQ_Item*, int);
	EQLIB_OBJECT CContainerWnd* GetFreeContainerWnd();
	EQLIB_OBJECT void OpenExperimentContainer(const VePointer<CONTENTS>& pCont, const ItemGlobalIndex& Location);

	//----------------------------------------------------------------------------
	// data members

/*0x04*/ CContainerWnd*     pContainerWnds[40];
/*0xa4*/ ArrayClass<CContainerWnd*> ContainerWndsToDelete;
/*0xb4*/ VePointer<CONTENTS> pWorldContainer;
/*0xb8*/ DWORD              WorldContainerSerialNumber;
/*0xbc*/ int                WorldContainerRealEstateID;
/*0xc0*/ int                WorldContainerRealEstateItemID;
/*0xc4*/ DWORD              Timer;
/*0xc8*/ bool               bShowDone;
/*0xcc*/
};

//============================================================================
// CContextMenuManager
//============================================================================

#define MAX_CONTEXT_MENU_DEPTH 8
#define MAX_CONTEXT_MENUS 1024

// combination of CContexTMenuManager and CContextMenuManagerBase
class [[offsetcomments]] CContextMenuManager : public CXWnd
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

/*0x01d8*/ CXWnd*             pParentMenuWnd;
/*0x01dc*/ CContextMenu*      pCurrMenus[MAX_CONTEXT_MENU_DEPTH];
/*0x01fc*/ int                NumVisibleMenus;
/*0x0200*/ int                CurrMenu;
/*0x0204*/ CContextMenu*      pMenus[MAX_CONTEXT_MENUS];
/*0x1204*/ int                NumMenus;
/*0x1208*/ CXWnd*             pHandlerWnd;
/*0x120c*/ int                HandlerCmd;
/*0x1210*/ int                DefaultMenuIndex;
/*0x1214*/ int                DefaultHelpItem;
/*0x1218*/ int                DefaultBGItem;
/*0x121c*/ int                DefaultMinItem;
/*0x1220*/ int                DefaultCloseItem;
/*0x1224*/ int                DefaultLockItem;
/*0x1228*/ int                DefaultEscapeItem;
/*0x122c*/
};

//============================================================================
// CContextMenu
//============================================================================

// Size is 0x290 in eagame 2016 Nov 14
class [[offsetcomments]] CContextMenu : public CListWnd
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

/*0x280*/ int          NumItems;
/*0x284*/ int          Unknown0x28C;
/*0x288*/
};

//============================================================================
// CCursorAttachment
//============================================================================

enum ECursorAttachmentType
{
	eCursorAttachment_None              = -1,
	eCursorAttachment_MemorizeSpel      = 1,
	eCursorAttachment_Item,
	eCursorAttachment_Money,
	eCursorAttachment_Social,
	eCursorAttachment_MenuButton,
	eCursorAttachment_Ability,
	eCursorAttachment_Combat,
	eCursorAttachment_InvSlot,
	eCursorAttachment_SpellGem,
	eCursorAttachment_PetCommand,
	eCursorAttachment_SkillID,
	eCursorAttachment_MeleeAbility,
	eCursorAttachment_LeadershipAbility,
	eCursorAttachment_ItemLink,
	eCursorAttachment_KronoSlot,
	eCursorAttachment_Command,
	eCursorAttachment_CombatAbility,
	eCursorAttachment_MountKeyRingLink,
	eCursorAttachment_IllusionKeyRingLink,
	eCursorAttachment_FamiliarKeyRingLink,
};

class [[offsetcomments]] CCursorAttachment : public CSidlScreenWnd, public WndEventHandler
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
	/*0x24c*/ // and more...
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
// CFactionWnd__size: 0x268 (see 5446F3) in Aug 15 2019 Live
class [[offsetcomments]] CFactionWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CFactionWnd(CXWnd*);
	virtual ~CFactionWnd();

	//----------------------------------------------------------------------------
	// data members

/*0x224*/ bool         bUnknown0x0244;
/*0x228*/ int          Unknown0x0248;
/*0x22c*/ int          Unknown0x024c;
/*0x230*/ int          Unknown0x0250;
/*0x234*/ SoeUtil::IString Unknown0x0254;
/*0x244*/ SoeUtil::IString Unknown0x0264;
/*0x254*/ CGaugeWnd*   StandingGaugeTemplate;
/*0x258*/ CTreeView*   Categories;
/*0x25c*/ CEditWnd*    SearchNameInput;
/*0x260*/ CButtonWnd*  SearchButton;
/*0x264*/ CListWnd*    FactionList;
/*0x268*/
};
using EQFACTIONWINDOW [[deprecated]] = CFactionWnd;
using PEQFACTIONWINDOW [[deprecated]] = CFactionWnd *;

//============================================================================
// CFacePick
//============================================================================

// todo: actually CPlayerCustomizationWnd
class [[offsetcomments]] CFacePick : public CSidlScreenWnd
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

class [[offsetcomments]] CFindItemWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CFindItemWnd(CXWnd*);
	virtual ~CFindItemWnd();

	virtual int WndNotification(CXWnd*, uint32_t, void*) override;

	EQLIB_OBJECT void Update();
	EQLIB_OBJECT void PickupSelectedItem();

/*0x224*/ CComboWnd*   SearchCombo0;
/*0x228*/ CComboWnd*   SearchCombo1;
/*0x22c*/ int          SelIndex;
/*0x230*/ VeArray<ItemGlobalIndex*> gi;
/*0x23c*/ int          Unknown0x24c;
/*0x240*/ int          Unknown0x250;
/*0x244*/ int          Unknown0x254;
/*0x248*/ int          Unknown0x258;
/*0x24c*/ int          Unknown0x25c;
/*0x250*/ int          FIW_ClassAnim;
/*0x254*/ CSidlScreenWnd* FIW_CharacterView;
/*0x258*/ CListWnd*    FIW_ItemList;
/*0x25c*/ CButtonWnd*  FIW_QueryButton;
/*0x260*/ CButtonWnd*  FIW_RequestItemButton;
/*0x264*/ CButtonWnd*  FIW_RequestPreviewButton;
/*0x268*/ CButtonWnd*  FIW_Default;
/*0x26c*/ CButtonWnd*  FIW_GrabButton;
/*0x270*/ CButtonWnd*  FIW_HighlightButton;
/*0x274*/ CButtonWnd*  FIW_DestroyItem;
/*0x278*/ CComboWnd*   FIW_ItemLocationCombobox;
/*0x27c*/ CComboWnd*   FIW_ItemSlotCombobox;
/*0x280*/ CComboWnd*   FIW_StatSlotCombobox;
/*0x284*/ CComboWnd*   FIW_RaceSlotCombobox;
/*0x288*/ CComboWnd*   FIW_ClassSlotCombobox;
/*0x28c*/ CComboWnd*   FIW_ItemTypeCombobox;
/*0x290*/ CComboWnd*   FIW_ItemPrestigeCombobox;
/*0x294*/ CComboWnd*   FIW_ItemAugmentCombobox;
/*0x298*/ CEditWnd*    FIW_ItemNameInput;
/*0x29c*/ CEditWnd*    FIW_MaxLevelInput;
/*0x2a0*/ CEditWnd*    FIW_MinLevelInput;
/*0x2a4*/ CEditWnd*    Unknown0x2b4;
/*0x2a8*/
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

constexpr int MAX_GIVE_SLOTS = 4;

class [[offsetcomments]] CGiveWnd : public CSidlScreenWnd, public PopDialogHandler, public WndEventHandler
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

/*0x228*/ CButtonWnd*    pMoneyButton[4];
/*0x238*/ CButtonWnd*    TradeButton;
/*0x23c*/ CButtonWnd*    CancelButton;
/*0x240*/ CLabel*        NPCNameLabel;
/*0x244*/ CInvSlotWnd*   pInvSlotWnd[MAX_GIVE_SLOTS];
/*0x254*/
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
	EQLIB_OBJECT void GetDefaultLfgLevelRange(const PcClient*, int*, int*) const;
	EQLIB_OBJECT void GetDefaultLfpLevelRange(const PcClient*, int*, int*) const;
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
class [[offsetcomments]] CGroupWnd : public CSidlScreenWnd
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
/*0x220*/ CButtonWnd*        InviteButton;
/*0x224*/ CButtonWnd*        DisbandButton;
/*0x228*/ CButtonWnd*        FollowButton;
/*0x22c*/ CButtonWnd*        DeclineButton;
/*0x230*/ CButtonWnd*        LFGButton;
/*0x234*/ CGaugeWnd*         HPGauge[6];
/*0x24c*/ CGaugeWnd*         PetGauge[6];
/*0x264*/ CGaugeWnd*         ManaGauge[6];
/*0x27c*/ CGaugeWnd*         EnduranceGauge[6];
/*0x294*/ CLabel*            HPLabel[6];
/*0x2ac*/ CLabel*            HPPercLabel[6];
/*0x2c4*/ CLabel*            ManaLabel[6];
/*0x2dc*/ CLabel*            ManaPercLabel[6];
/*0x2f4*/ CLabel*            EnduranceLabel[6];
/*0x30c*/ CLabel*            EndurancePercLabel[6];
/*0x324*/ COLORREF           HPTextColor[6];
/*0x33c*/ CButtonWnd*        GroupTankButton[6];
/*0x354*/ CButtonWnd*        GroupAssistButton[6];
/*0x36c*/ CButtonWnd*        GroupPullerButton[6];
/*0x384*/ CButtonWnd*        GroupMarkNPCButton[6];
/*0x39c*/ CLabel*            AggroPercLabel[6];
/*0x3b4*/ long               Timer;
/*0x3b8*/ CContextMenu*      GroupContextMenu;
/*0x3bc*/ bool               bPetbars;
/*0x3bd*/ bool               bManabars;
/*0x3be*/ bool               bEndurancebars;
/*0x3bf*/ bool               bAggroPct;
/*0x3c0*/ int                PetBarIndex;
/*0x3c4*/ int                ManaBarIndex;
/*0x3c8*/ int                EnduranceBarIndex;
/*0x3cc*/ int                AggroPctIndex;
/*0x3d0*/ int                RoleSeparatorID;
/*0x3d4*/ int                RoleSelectMenu;
/*0x3d8*/ int                RoleSelectMenuID;
/*0x3dc*/ bool               bPlayerInvited;
/*0x3e0*/
};

//============================================================================
// CGuildMgmtWnd
//============================================================================

// todo: update, some of this is obsolete
struct [[offsetcomments]] GuildMember
{
	// Start of GuildMember
/*0x000*/ GuildMember*       pNext;
/*0x004*/ bool               bOnline;
/*0x005*/ BYTE               Filler0x005[0x3];
/*0x008*/ WORD               ZoneID;
/*0x00a*/ WORD               Instance;
/*0x00c*/ DWORD              PlayerSerial;
/*0x010*/ bool               bMainProfile;
/*0x011*/ bool               bOfflineMode;
/*0x012*/ char               Name[0x40];
/*0x052*/ BYTE               Filler0x52[0x2];
/*0x054*/ int                Level;
/*0x058*/ int                Flags; //1=banker, 2=alt
/*0x05c*/ DWORD              Class;
/*0x060*/ DWORD              Rank; //0=member 1=officer 2=leader
/*0x064*/ char               PlayerHandle[0x20];
/*0x084*/ char               PlayerComments[0x100];
/*0x184*/ DWORD              LastLoginTime;
/*0x188*/ EqGuid             PlayerGuild;//size is 8
/*0x190*/ bool               bGuildShowSprite;
/*0x191*/ bool               bTributeStatus;//active on/off
/*0x192*/ bool               bTrophyStatus;//active on/off
/*0x194*/ int                TributeDonations;
/*0x198*/ DWORD              LastDonation;//timestamp
/*0x19c*/ // end of GuildMember
	// start of GuildMemberClient
/*0x19c*/ char               PublicNote[0x100];
/*0x29c*/ char               PersonalNote[0x100];
/*0x39c*/ bool               bTributeOptIn;
/*0x39d*/ bool               bTrophyTributeOptIn;
/*0x3a0*/
};
using GUILDMEMBERCLIENT [[deprecated]] = GuildMember;
using PGUILDMEMBERCLIENT [[deprecated]] = GuildMember*;
using GUILDMEMBERINFO [[deprecated]] = GuildMember;
using PGUILDMEMBERINFO [[deprecated]] = GuildMember*;
using GuildMember = GuildMember;


// Size: 0x3d0 (02/18/2004)
class [[offsetcomments]] CGuildMgmtWnd
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

/*0x230*/ BYTE         Unknown0x148[0x3c];
/*0x26c*/ BYTE         Unknown0x194;
/*0x26d*/ BYTE         ShowOffline;              // 01 = show offline box is checked
/*0x26e*/ BYTE         Unknown0x196[0x2];

	// This is a pointer to the beginning of a list of pointers, each representing one player in
	// the guild. The number of  pointers depends upon TotalMemberCount.
/*0x270*/ GuildMember** pMember;
/*0x274*/ DWORD        TotalMemberCount;
/*0x278*/ DWORD        Unknown0x1a0;             // 150?
/*0x27c*/ DWORD        Unknown0x1a4;             // 1?
/*0x280*/ DWORD        TotalMemberCountAgain;
/*0x284*/ BYTE         Unknown0x1ac[0x1c];
/*0x2a0*/ char         PersonalNotesFilePath[0x40]; // path to personal notes file
/*0x2e0*/ BYTE         Unknown0x208[0x1c0];      // empty
/*0x4a0*/ DWORD        Unknown0x3c8;             // 1?
/*0x4a4*/ DWORD        Unknown0x3cc;             // some sort of bizaare pointer...
/*0x4a8*/
};
using EQGUILDWINDOW [[deprecated]] = CGuildMgmtWnd;
using PEQGUILDWINDOW [[deprecated]] = CGuildMgmtWnd*;

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
	EQLIB_OBJECT virtual bool doValidateURI(Window*, const char*) = 0;
};

} // namepsace libMozilla

class [[offsetcomments]] CHtmlComponentWnd
	: public CXWnd
	, public libMozilla::ICallback
	, public CObservable
{
public:
	CHtmlComponentWnd(CXWnd* parent, uint32_t id, CXRect rect, CXStr startURI = "");
	virtual ~CHtmlComponentWnd();

/*0x1e4*/ libMozilla::Window* m_mozillaWnd;
/*0x1e8*/
	// more ...
};

class [[offsetcomments]] CHtmlWnd : public CSidlScreenWnd, public TListNode<CHtmlWnd>
{
public:
	CHtmlWnd(const char* uri, const char* postData, const char* windowId, bool byPassfilter = false, const char* title = nullptr);
	virtual ~CHtmlWnd();

	EQLIB_OBJECT void SetClientCallbacks(libMozilla::ICallback* cb);
	EQLIB_OBJECT void AddObserver(IObserver* observer);
	EQLIB_OBJECT void RemoveObserver(IObserver* observer);

	const CHtmlWnd* GetNextHtmlWnd() const { return TListNode<CHtmlWnd>::GetNext(); }
	CHtmlWnd* GetNextHtmlWnd() { return TListNode<CHtmlWnd>::GetNext(); }

/*0x22c*/ CHtmlComponentWnd*       pHtmlComponentMain;
/*0x230*/ CButtonWnd*              pBackBtn;
/*0x234*/ CButtonWnd*              pForwardBtn;
/*0x238*/ CGaugeWnd*               pProgressGauge;
/*0x23c*/ CLabelWnd*               pStatusLabel;
/*0x240*/ CXStr                    WindowID;
/*0x244*/
};

class [[offsetcomments]] CWebManager
{
public:
	EQLIB_OBJECT CHtmlWnd* CreateHtmlWnd(const char* uri, const char* windowId, const char* postBuffer = nullptr,
		bool bypassFilter = false, const char* titleOverride = nullptr);

	EQLIB_OBJECT CHtmlWnd* GetHtmlWnd(const char* windowId);

/*0x00*/ TList<CHtmlWnd>             m_htmlWndList;
/*0x08*/
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
class [[offsetcomments]] CInventoryWnd : public CSidlScreenWnd, public PopDialogHandler, public WndEventHandler, public IObserver
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

/*0x22c*/ BYTE        Unknown0x0240[0x84];
/*0x2b0*/ int64_t     VitalityCap;
/*0x2b8*/ int         AAVitalityCap;
/*0x2bc*/
};
using INVENTORYWND [[deprecated]] = CInventoryWnd;
using PINVENTORYWND [[deprecated]] = CInventoryWnd*;

//============================================================================
// CInvSlotWnd
//============================================================================

class CInvSlotWnd;

const int MAX_INV_SLOTS = 0x900;

// actual size 0x14 10-12-2010
// I think this is correct:
// see (69FF1E) in eqgame.exe dated 2013 11 13
class [[offsetcomments]] CInvSlot
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
/*0x0c*/ int                Index;                    // InvSlot
/*0x10*/ bool               bEnabled;                 // Valid
/*0x14*/
};
using EQINVSLOT [[deprecated]] = CInvSlot;
using PEQINVSLOT [[deprecated]] = CInvSlot*;

//----------------------------------------------------------------------------
// Size 0x2418 see 534532 in Nov 06 2018 Test
class [[offsetcomments]] CInvSlotMgr
{
public:
	CInvSlotMgr();
	virtual ~CInvSlotMgr();

	EQLIB_OBJECT CInvSlot* CreateInvSlot(CInvSlotWnd*);
	EQLIB_OBJECT CInvSlot* FindInvSlot(int TopSlot, int SubSlot = -1,
		ItemContainerInstance location = eItemContainerPossessions, bool includeLinks = true);
	EQLIB_OBJECT CInvSlot* FindInvSlot(const ItemGlobalIndex& index, bool includeLinks = true)
	{
		return FindInvSlot(index.GetTopSlot(), index.GetIndex().GetSlot(1), index.GetLocation(), includeLinks);
	}

	EQLIB_OBJECT bool MoveItem(const ItemGlobalIndex& from, const ItemGlobalIndex& to, bool bDebugOut, bool CombineIsOk, bool MoveFromIntoToBag = false, bool MoveToIntoFromBag = false);
	EQLIB_OBJECT void Process();
	EQLIB_OBJECT void SelectSlot(CInvSlot*);
	EQLIB_OBJECT void UpdateSlots();

	//----------------------------------------------------------------------------
	// data members

/*0x0004*/ CInvSlot*    SlotArray[MAX_INV_SLOTS]; // size 0x2400 //see 72E00F in Nov 06 2018 Test
/*0x2404*/ int          TotalSlots;
/*0x2408*/ unsigned int LastUpdate;
/*0x240c*/ CInvSlot*    pSelectedItem;
/*0x2410*/ int          Unknown0x2410;
/*0x2414*/ bool         bToggleBagsOpen;
/*0x2415*/ bool         bToggleBankBagsOpen;
/*0x2418*/
};
using EQINVSLOTMGR [[deprecated]] = CInvSlotMgr;
using PEQINVSLOTMGR [[deprecated]] = CInvSlotMgr*;

//----------------------------------------------------------------------------

// note that Invslot needs to be a short or pickupitem wont work
// CInvSlotWnd_size: 0x2c0 (see 7F8ACC) in Aug 15 2019 Live
class [[offsetcomments]] CInvSlotWnd : public CButtonWnd
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

/*0x270*/ CTextureAnimation* pBackground;
/*0x274*/ ItemGlobalIndex    ItemLocation;            // WindowType = ItemLocation.Location, InvSlot = ItemLocation.GetTopSlot()
/*0x280*/ void*              LinkedItem;              // ItemBasePtr
/*0x284*/ int                ItemOffsetX;
/*0x288*/ int                ItemOffsetY;
/*0x28c*/ CTextureAnimation* ptItem;
/*0x290*/ int                Quantity;
/*0x294*/ bool               bSelected;
/*0x298*/ int                RecastLeft;
/*0x29c*/ bool               bHotButton;
/*0x29d*/ bool               bInventorySlotLinked;
/*0x2a0*/ CInvSlot*          pInvSlot;
/*0x2a4*/ CTextObjectInterface* pTextObject;
/*0x2a8*/ int                TextFontStyle;
/*0x2ac*/ int                Mode;
/*0x2b0*/ D3DCOLOR           BGTintRollover;
/*0x2b4*/ D3DCOLOR           BGTintNormal;
/*0x2b8*/ long               LastTime;
/*0x2bc*/ int                Unknown0x2dc;
/*0x2c0*/
};
using EQINVSLOTWND [[deprecated]] = CInvSlotWnd;
using PEQINVSLOTWND [[deprecated]] = CInvSlotWnd*;

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
// CItemDisplayWindow_size: 0x618 (see 758832) in Aug 15 2019 Live
class [[offsetcomments]] CItemDisplayWnd : public CSidlScreenWnd
{
public:
	EQLIB_OBJECT CItemDisplayWnd(CXWnd*);
	EQLIB_OBJECT virtual ~CItemDisplayWnd();

	EQLIB_OBJECT virtual int HandleKeyboardMsg(uint32_t, uint32_t, bool) override;
	EQLIB_OBJECT virtual int OnProcessFrame() override;
	EQLIB_OBJECT virtual int WndNotification(CXWnd* pWnd, uint32_t Message, void* pData) override;
	EQLIB_OBJECT virtual bool AboutToShow() override;

	EQLIB_OBJECT CXStr CreateEquipmentStatusString(EQ_Item*);
	EQLIB_OBJECT void SetItem(CONTENTS** pCont, int flags);
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
/*0x220*/ CStmlWnd*         Description;
/*0x224*/ CStmlWnd*         Name;
/*0x228*/ CButtonWnd*       IconButton;
/*0x22c*/ CStmlWnd*         ItemLore;
/*0x230*/ CTabWnd*          ItemDescriptionTabBox;
/*0x234*/ CPageWnd*         ItemDescriptionTab;
/*0x238*/ CPageWnd*         ItemLoreTab;
/*0x23c*/ CSidlScreenWnd*   pAppearanceSocketScreen;
/*0x240*/ CButtonWnd*       pAppearanceSocketItem;
/*0x244*/ CButtonWnd*       pAppearanceSocketBuyButton;
/*0x248*/ CStmlWnd*         pAppearanceSocketDescription;
/*0x24c*/ CSidlScreenWnd*   pItemSocketScreen[6];
/*0x264*/ CButtonWnd*       pItemSocketItemButton[6];
/*0x27c*/ CStmlWnd*         pItemSocketDescription[6];
/*0x294*/ CXStr             ItemInfo;                 // this item is placable in yards, guild yards blah blah , This item can be used in tradeskills
/*0x298*/ CXStr             WindowTitle;
/*0x29c*/ CXStr             ItemAdvancedLoreText;
/*0x2a0*/ CXStr             ItemMadeByText;
/*0x2a4*/ CXStr             BackupTabTitle;
/*0x2a8*/ CXStr             SolventText;
/*0x2ac*/ CXStr             ItemInformationText;      // Item Information: Placing this augment into blah blah, this armor can only be used in blah blah
/*0x2b0*/ CONTENTS*         pItem; // ItemBasePtr
/*0x2b4*/ bool              bActiveItem;
/*0x2b5*/ bool              bItemTextSet;
/*0x2b8*/ CTextureAnimation* BuffIcons;
/*0x2bc*/ CTextureAnimation* DragIcons;
/*0x2c0*/ bool              bTaggable;
/*0x2c1*/ bool              bFailed;
/*0x2c4*/ unsigned int      TabCount;
/*0x2c8*/ CLabel*           ModButtonLabel;
/*0x2cc*/ CLabel*           RewardButtonLabel;
/*0x2d0*/ CStmlWnd*         ConvertStml;
/*0x2d4*/ CLabel*           MadeByLabel;
/*0x2d8*/ CLabel*           CollectedLabel;
/*0x2dc*/ CLabel*           ScribedLabel;
/*0x2e0*/ int               Row;
/*0x2e4*/ bool              bAntiTwink;
/*0x2e8*/ CButtonWnd*       ModButton;
/*0x2ec*/ CButtonWnd*       RewardButton;
/*0x2f0*/ CButtonWnd*       PrintRealEstateItems;
/*0x2f4*/ CButtonWnd*       ConvertButton;
/*0x2f8*/ bool              bCollected;
/*0x2f9*/ bool              bCollectedReceived;
/*0x2fc*/ int               Unknown0x031c;
/*0x300*/ int               Unknown0x0320;
/*0x304*/ bool              bScribed;
/*0x305*/ bool              bScribedReceived;
/*0x306*/ BYTE              Unknown0x0326[0x2f2];
/*0x5f8*/ DWORD             Unknown0x0618;
/*0x5fc*/ DWORD             Unknown0x061C;
/*0x600*/ DWORD             Unknown0x0620;
/*0x604*/ DWORD             Unknown0x0624;
/*0x608*/ DWORD             Unknown0x0628;
/*0x60c*/ DWORD             Unknown0x062c;
/*0x610*/ DWORD             Unknown0x0630;
/*0x614*/ DWORD             ItemWndIndex;             // 0-5? you can have max 6 windows up I think before it starts overwriting the sixth.
/*0x618*/
};
using EQITEMWINDOW [[deprecated]] = CItemDisplayWnd;
using PEQITEMWINDOW [[deprecated]] = CItemDisplayWnd*;

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
// CLootWnd_size: 0x388 (see 5443A5) in Aug 15 2019 Live
class [[offsetcomments]] CLootWnd : public CSidlScreenWnd, public PopDialogHandler, public WndEventHandler
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
	EQLIB_OBJECT void LootAll(bool close);
	EQLIB_OBJECT void RequestLootSlot(int Slot, bool bAutoInventory);
	EQLIB_OBJECT void SlotLooted(int);
	EQLIB_OBJECT void FinalizeLoot();

	//----------------------------------------------------------------------------
	// data members

	// todo: most of this is wrong
/*0x228*/ BYTE              Unknown0x0244[0x94];
/*0x2bc*/ DWORD             NumOfSlots;
/*0x2c0*/ BYTE              Unknown0x02e0[0x4];
/*0x2c4*/ INVENTORYARRAY*   pInventoryArray;
/*0x2c8*/ DWORD             Size;
/*0x2cc*/ DWORD             NumOfSlots3;
/*0x2d0*/ BYTE              Unknown0x02f0[0x8];
/*0x2d8*/ BYTE              Unknown0x02f8;
/*0x2d9*/ BYTE              Unknown0x02f9;
/*0x2da*/ BYTE              Unknown0x02fa;
/*0x2db*/ BYTE              Unknown0x02fb;
/*0x2dc*/ CXWnd*            LootInvWnd;
/*0x2e0*/ CInvSlotWnd*      LootSlotWnd[0x22];
/*0x368*/ CLabel*           LW_CorpseName;
/*0x36c*/ CButtonWnd*       DoneButton;
/*0x370*/ CButtonWnd*       BroadcastButton;
/*0x374*/ CButtonWnd*       LootAllButton;
/*0x378*/ BYTE              Unknown0x0398[0x10];
/*0x388*/
};
using EQLOOTWINDOW [[deprecated]] = CLootWnd;
using PEQLOOTWINDOW [[deprecated]] = CLootWnd*;

//============================================================================
// CMapViewWnd
//============================================================================

// Map Window sizeof() = 0x38
struct [[offsetcomments]] MAPLABEL
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
struct [[offsetcomments]] MAPLINE
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
// CMapViewWnd_size: 0x628 (see 543ADA) in Aug 15 2019 Live
class [[offsetcomments]] MapViewMap : public CSidlScreenWnd
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

/*0x220*/ float              mapViewMinX;
/*0x224*/ float              mapViewMinY;
/*0x228*/ float              mapViewMaxX;
/*0x22c*/ float              mapViewMaxY;
/*0x230*/ int                panOffsetX;
/*0x234*/ int                panOffsetY;
/*0x238*/ float              lineOffsetX;
/*0x23c*/ float              lineOffsetY;
/*0x240*/ float              scaleDiffX;
/*0x244*/ float              scaleDiffY;
/*0x248*/ float              mapViewScaleX;
/*0x24c*/ float              mapViewScaleY;
/*0x250*/ PMAPLINE           pLines;
/*0x254*/ PMAPLABEL          pLabels;
/*0x258*/ uint32_t           nextLabelId;
/*0x25c*/ bool               lineActive;
/*0x260*/
	// more members, need to map it out. Fortunately, this is the last member of
	// CMapViewWnd so its not necessary at this time to do so ...
};

class [[offsetcomments]] CMapViewWnd : public CSidlScreenWnd, public WndEventHandler
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
	EQLIB_OBJECT void GetWorldCoordinates(CVector3&); // actually MapViewMap

	// these are almost all the controls belonging to the CMapViewWnd
/*0x224*/ int         ZoneId;
/*0x228*/ bool        bAutoMapping;
/*0x22c*/ CButtonWnd* btnPanLeft;
/*0x230*/ CButtonWnd* btnPanRight;
/*0x234*/ CButtonWnd* btnPanUp;
/*0x238*/ CButtonWnd* btnPanDown;
/*0x23c*/ CButtonWnd* btnPanReset;
/*0x240*/ CButtonWnd* btnZoomIn;
/*0x244*/ CButtonWnd* btnZoomOut;
/*0x248*/ CButtonWnd* btnShowGroup;
/*0x24c*/ CButtonWnd* btnFind;
/*0x250*/ CButtonWnd* btnEndFind;
/*0x254*/ CButtonWnd* btnFindAutoZoom;
/*0x258*/ CButtonWnd* btnMapZoneGuide;
/*0x25c*/ CButtonWnd* btnToolbar;
/*0x260*/ char        szZoneName[0x80];
/*0x2e0*/ CButtonWnd* btntoggleLabels;
/*0x2e4*/ CEditWnd*   editMinZ;
/*0x2e8*/ CEditWnd*   editMaxZ;
/*0x2ec*/ CButtonWnd* btnZFilter;
/*0x2f0*/ CButtonWnd* btnLayer0;
/*0x2f4*/ CButtonWnd* btnLayer1;
/*0x2f8*/ CButtonWnd* btnLayer2;
/*0x2fc*/ CButtonWnd* btnLayer3;
/*0x300*/ CButtonWnd* btnLayer1Active;
/*0x304*/ CButtonWnd* btnLayer2Active;
/*0x308*/ CButtonWnd* btnLayer3Active;
/*0x30c*/ CButtonWnd* btnLoadCurrent;
/*0x310*/ CPageWnd*   pageAtlas;
/*0x314*/ CPageWnd*   pageMap;
/*0x318*/ CTabWnd*    tabWnd;
/*0x31c*/ CXWnd*      MapRenderArea;
/*0x320*/ CComboWnd*  MapsDirSelect;
/*0x324*/ CXWnd*      AtlasRenderArea;
/*0x328*/ CAtlas*     AtlasWnd;
/*0x32c*/ CComboWnd*  AtlasDirSelect;
/*0x330*/ CButtonWnd* btnAtlasZoneGuide;
/*0x334*/ CButtonWnd* btnMapIcon;
/*0x338*/ CEditWnd*   editSearchBox;
/*0x33c*/ CButtonWnd* btnSearch;
/*0x340*/ CButtonWnd* btnSearchClear;
/*0x344*/ CListWnd*   listSearch;
/*0x348*/ CXWnd*      wndSearchLayout;
/*0x34c*/ CButtonWnd* btnSearchHide;
/*0x350*/ CXWnd*      wndSpacer;
/*0x354*/ bool        bEditing;
/*0x358*/ MapViewMap  MapView;                            // a window component owned by CMapViewWnd.
/*0x5b8*/
	// alias the stupid
	__declspec(property(get = getLines)) PMAPLINE pLines;
	__declspec(property(get = getLabels)) PMAPLABEL pLabels;

private:
	PMAPLINE getLines() { return MapView.pLines; }
	PMAPLABEL getLabels() { return MapView.pLabels; }
};

using EQMAPWINDOW [[deprecated]] = CMapViewWnd;
using PEQMAPWINDOW [[deprecated]] = CMapViewWnd *;

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

struct [[offsetcomments]] CONTENTDATA
{
/*0x00*/ CONTENTS*     pCont;
/*0x04*/ int           Unknown;
/*0x08*/
};

struct [[offsetcomments]] CONTENTSARRAY
{
	FORCE_SYMBOLS;

/*0x00*/ struct CONTENTDATA Array[1];
/*0x08*/
};
using PCONTENTSARRAY [[deprecated]] = CONTENTSARRAY *;

// todo: finish mapping this and verify

#if 1
class [[offsetcomments]] MerchantPageHandler : public VeBaseReferenceCount
{
public:
/*0x08*/ CMerchantWnd*   pParent;
/*0x0c*/ int             MaxItems;
/*0x10*/ int             LastIndex;
/*0x14*/ CListWnd*       ItemsList;
/*0x18*/ CPageWnd*       PurchasePage;
/*0x1c*/ bool            bListNeedsRefresh;
/*0x20*/ SoeUtil::Array<CONTENTDATA> ItemContainer;
/*0x30*/ int             Unknown0x40;
/*0x34*/ int             Unknown0x44;
/*0x38*/ int             Unknown0x48;
/*0x3c*/ int             Unknown0x4c;
/*0x40*/ int             Unknown0x50;
/*0x44*/ int             Unknown0x54;
/*0x48*/ int             Unknown0x58;
/*0x4c*/ int             Unknown0x5c;
/*0x50*/ int             Unknown0x60;
/*0x54*/ int             Unknown0x64;
/*0x58*/ int             Unknown0x68;
/*0x5c*/ int             Unknown0x6c;
/*0x60*/ int             Unknown0x70;
/*0x64*/ int             Unknown0x74;
/*0x68*/ int             Unknown0x78;
/*0x6c*/ int             Unknown0x7c;
/*0x70*/ int             Unknown0x80;
/*0x74*/

	// offset comments indicate vtable offset
	/*0x0c*/ EQLIB_OBJECT virtual void Unknownv0x08();
	/*0x0c*/ EQLIB_OBJECT virtual void Unknownv0x0c();
	/*0x10*/ EQLIB_OBJECT virtual void Unknownv0x10();
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

class [[offsetcomments]] PurchasePageHandler : public MerchantPageHandler
{
	FORCE_SYMBOLS;

public:
/*0x74*/ bool bShowAllItems;
/*0x78*/ int Unknown0x88;
/*0x7c*/ int Unknown0x8c;
/*0x80*/ int Unknown0x90;
/*0x84*/ int Unknown0x94;
/*0x88*/ int Unknown0x98;
/*0x8c*/ int Unknown0x9c;
/*0x90*/ int Unknown0xa0;
/*0x94*/ int Unknown0xa4;
/*0x98*/

	EQLIB_OBJECT bool RequestGetItem(int);
	EQLIB_OBJECT void RequestPutItem(int);
};
#endif

struct CONTENTSARRAY;
struct sell_msg;

// this is actually PurchasePageHandler?
struct [[offsetcomments]] merchdata
{
	FORCE_SYMBOLS;

/*0x00*/ void* vftable;                  // VeBaseReferenceCount
/*0x04*/ BYTE          Unknown0x4[0x8];
/*0x0c*/ DWORD         MerchSlots;
/*0x10*/ DWORD         SelectedListItem;
/*0x14*/ DWORD         Unknown0x14[4];
/*0x24*/ CONTENTSARRAY* pMerchArray;
/*0x28*/ DWORD         MerchMaxSlots;
/*0x2c*/
};

struct [[offsetcomments]] merch_other
{
	FORCE_SYMBOLS;

/*0x00*/ merchdata* pMerchData;          // purchase page
/*0x04*/ void* other;                    // buyback page
/*0x08*/ void* other2;                   // mail page
/*0x0c*/
};

enum MerchantPages
{
	RegularMerchantPage,
	BuybackMerchantPage,
	MailMerchantPage,

	MaxMerchantPages
};

// CMerchantWnd__CMerchantWnd_x (aMerchantwnd)
// CMerchantWnd_size: 0x438 (see 544501) in Aug 15 2019 Live
class [[offsetcomments]] CMerchantWnd : public CSidlScreenWnd, public WndEventHandler, PopDialogHandler
{
public:

	// TODO: This structure needs to be verified
#if 0
/*0x0248*/ BYTE        Unknown0x0240[0x8];
/*0x0250*/ merch_other* pMerchOther;             // found in CMerchantWnd__CMerchantWnd
/*0x0254*/ BYTE        Unknown0x0254[0x8];
/*0x025c*/ float       Markup;                   // found in CMerchantWnd__DisplayBuyOrSellPrice_x
/*0x0260*/ BYTE        Unknown0x0260[0xc];
/*0x026c*/ DWORD       SelectedSlotID;
/*0x0270*/ BYTE        Unknown0x0270[0x1e8];
/*0x0458*/

#else
/*0x228*/ bool         bInventoryWasActive;
/*0x22c*/ VeArray<VePointer<MerchantPageHandler>> PageHandlers;
/*0x238*/ float        MerchantGreed;
/*0x23c*/ ItemGlobalIndex ItemLocation;
/*0x248*/ BYTE         Unknown0x254[0x8];
/*0x250*/ VePointer<CONTENTS> pSelectedItem;
/*0x254*/ time_t       MailExpireTime;
/*0x258*/ bool         bAutoRetrieveingMail;
/*0x259*/ BYTE         Unknown0x268[0x10];
/*0x26c*/ char*        Labels[0xc];
/*0x29c*/ CEditWnd*    SearchEdit;
/*0x2a0*/ CButtonWnd*  SearchButton;
/*0x2a4*/ CLabel*      MerchantNameLabel;
/*0x2a8*/ CLabel*      SelectedItemLabel;
/*0x2ac*/ CLabel*      SelectedPriceLabel;
/*0x2b0*/ CButtonWnd*  InspectButton;
/*0x2b4*/ CButtonWnd*  PreviewButton;
/*0x2b8*/ CButtonWnd*  SelectedItemButton;
/*0x2bc*/ CButtonWnd*  BuyButton;
/*0x2c0*/ CButtonWnd*  BuyMarketPlaceButton;
/*0x2c4*/ CButtonWnd*  SellButton;
/*0x2c8*/ CButtonWnd*  RecoverButton;
/*0x2cc*/ CButtonWnd*  RetrieveButton;
/*0x2d0*/ CButtonWnd*  RetrieveAllButton;
/*0x2d4*/ CButtonWnd*  SendButton;
/*0x2d8*/ CButtonWnd*  AdventureButton;
/*0x2dc*/ CLabel*      SendToLabel;
/*0x2e0*/ CEditWnd*    SendToEdit;
/*0x2e4*/ CLabel*      NoteLabel;
/*0x2e8*/ CEditWnd*    NoteEdit;
/*0x2ec*/ CButtonWnd*  ClearNoteButton;
/*0x2f0*/ CListWnd*    ItemsList;
/*0x2f4*/ CListWnd*    ItemsRecoveryList;
/*0x2f8*/ CListWnd*    ItemsMailList;
/*0x2fc*/ CButtonWnd*  DoneButton;
/*0x300*/ CPageWnd*    PurchasePage;
/*0x304*/ CPageWnd*    RecoveryPage;
/*0x308*/ CPageWnd*    MailPage;
/*0x30c*/ CTabWnd*     TabWindow;
/*0x310*/ CButtonWnd*  UsableButton;
/*0x314*/ CLabel*      CurrentCurrencyLabel;
/*0x318*/ int          Unknown0x32c;
/*0x31c*/ int          Unknown0x330;
/*0x320*/ int          Unknown0x334;
/*0x324*/ int          Unknown0x338;
/*0x328*/ int          Unknown0x33C;
/*0x32c*/ int          Guk_Currency;
/*0x330*/ uint8_t      Unknown0x340[0x100];
/*0x430*/
#endif

	CMerchantWnd(CXWnd*);
	virtual ~CMerchantWnd();

	EQLIB_OBJECT void AddContainerToMercArray(EQ_Container*);
	EQLIB_OBJECT void AddEquipmentToMercArray(EQ_Equipment*);
	EQLIB_OBJECT void AddNoteToMercArray(EQ_Note*);
	EQLIB_OBJECT void ClearMerchantSlot(int);
	EQLIB_OBJECT void FinishBuyingItem(sell_msg*);
	EQLIB_OBJECT void FinishSellingItem(sell_msg*);
	EQLIB_OBJECT int SelectBuySellSlot(const ItemGlobalIndex&, int ListIndex = -1);
	EQLIB_OBJECT void DisplayBuyOrSellPrice(bool, EQ_Item*);
	EQLIB_OBJECT void HandleBuy(int);
	EQLIB_OBJECT void HandleSell(int);
	EQLIB_OBJECT void UpdateBuySellButtons();
};
using EQMERCHWINDOW [[deprecated]] = CMerchantWnd;
using PEQMERCHWINDOW [[deprecated]] = CMerchantWnd *;

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

struct [[offsetcomments]] KeyboardAssignmentData
{
/*0x00*/ CXStr Description;
/*0x04*/ int nAssignmentNumber;
/*0x08*/
};
using EQKBASSIGN [[deprecated]] = KeyboardAssignmentData;
using PEQKBASSIGN [[deprecated]] = KeyboardAssignmentData*;

// size 0x904 3-10-2004
class [[offsetcomments]] COptionsWnd : public CSidlScreenWnd, public PopDialogHandler, public WndEventHandler
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
/*0x228*/ KeyboardAssignmentData   Binds[0xA1];
/*0x730*/
/*0x904*/
};

using EQOPTIONSWINDOW [[deprecated]] = COptionsWnd;
using PEQOPTIONSWINDOW [[deprecated]] = COptionsWnd*;

//============================================================================
// CPetInfoWnd
//============================================================================

// CPetInfoWindow__CPetInfoWindow aPetinfowindow
// CPetInfoWindow_size: 0x8b8 (see 543531) in Aug 15 2019 Live
class [[offsetcomments]] CPetInfoWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CPetInfoWnd(CXWnd*);
	virtual ~CPetInfoWnd();

	EQLIB_OBJECT CButtonWnd* GetButton(int);
	EQLIB_OBJECT void SetShowOnSummon(bool);
	EQLIB_OBJECT void Update();

	//----------------------------------------------------------------------------
	// data members

/*0x224*/ uint8_t            Unknown0x0244[0x4];
/*0x228*/ CButtonWnd*        pButton[0xe];             // there are 14 buttons on the petinfowin with text that can be set to attack,none,back and so on, these are those...
/*0x260*/ uint8_t            Unknown0x0280[0x8];
/*0x268*/ CButtonWnd*        pAttackButton;
/*0x26c*/ CButtonWnd*        pQAttackButton;
/*0x270*/ CButtonWnd*        pFollowButton;
/*0x274*/ CButtonWnd*        pGuardButton;
/*0x278*/ CButtonWnd*        pSitButton;
/*0x27c*/ CButtonWnd*        pStopButton;
/*0x280*/ uint8_t            Unknown0x02a0[0x174];
/*0x3f4*/ CButtonWnd*        pWnd[NUM_BUFF_SLOTS];     // buff buttons
/*0x578*/ int                Buff[NUM_BUFF_SLOTS];     // Spell ID# of each buff -- 97 total
/*0x6fc*/ uint8_t            Unknown0x0714[0x20];
/*0x71c*/ unsigned int       PetBuffTimer[NUM_BUFF_SLOTS]; // duration until buff fades, in thousands of a second
/*0x8a0*/ uint8_t            Unknown0x08c0[0xc];
/*0x8ac*/ bool               bPetButtonsDirty;
/*0x8ad*/ bool               Sit;
/*0x8ae*/ bool               Stop;
/*0x8af*/ bool               ReGroup;
/*0x8b0*/ bool               Follow;
/*0x8b1*/ bool               Guard;
/*0x8b2*/ bool               Taunt;
/*0x8b3*/ bool               Hold;
/*0x8b4*/ bool               GHold;
/*0x8b5*/ bool               Focus;
/*0x8b8*/
};
using EQPETINFOWINDOW [[deprecated]] = CPetInfoWnd;
using PEQPETINFOWINDOW [[deprecated]] = CPetInfoWnd *;

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
// CPlayerWindow_size: 0x2d8 (see 543F3E) in Aug 15 2019 Live
class [[offsetcomments]] CPlayerWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CPlayerWnd(CXWnd*);
	virtual ~CPlayerWnd();

	EQLIB_OBJECT void CreateLocalMenu();
	EQLIB_OBJECT void UpdateContextMenu();

	//----------------------------------------------------------------------------
	// data members

/*0x224*/ uint8_t            Unknown0x0240[0xb0];
/*0x2d4*/ ECombatState       CombatState;                       // right above "A_PWCSInCombat"
/*0x2d8*/
};
using CPLAYERWND [[deprecated]] = CPlayerWnd;
using PCPLAYERWND [[deprecated]] = CPlayerWnd*;

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

struct [[offsetcomments]] PointMerchantItem
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

class [[offsetcomments]] PointMerchantWnd : public CSidlScreenWnd, public PopDialogHandler, public WndEventHandler
{
public:
	PointMerchantWnd(CXWnd*);
	virtual ~PointMerchantWnd();

	//----------------------------------------------------------------------------
	// data members

	// todo: verify
/*0x228*/ int                Unknown0x008;
/*0x22c*/ int                NumItems;
/*0x230*/ bool               HdrItemName;
/*0x231*/ bool               HdrTheme;
/*0x232*/ bool               HdrPrice;
/*0x233*/ char               OriginalPointsLabel[0x40];
/*0x274*/ CLabel* MerchantNameLabel;
/*0x278*/ CListWnd* ItemList;
/*0x27c*/ CListWnd* PointList;
/*0x280*/ CButtonWnd* EquipButton;
/*0x284*/ CButtonWnd* PurchaseButton;
/*0x288*/ CButtonWnd* SellButton;
/*0x28c*/ CButtonWnd* DoneButton;
/*0x290*/ CLabel* PointsAvailableValue;
/*0x294*/ CLabel* PointsEverEarnedLabel;
/*0x298*/ CLabel* PointsAvailableLabel;
/*0x29c*/ unsigned int       NextRefreshTime;
/*0x2a0*/ PSPAWNINFO         ActiveMerchant; // PlayerClient*
/*0x2a4*/ PointMerchantItem** Items;
/*0x2a8*/ int                MerchantThemeId;
/*0x2ac*/ int                CurrentSelection;
/*0x2b0*/ int                CurrentSort;
/*0x2b4*/ bool               bCurrentAscending;
/*0x2b8*/ ItemGlobalIndex    ItemLocation;
/*0x2c4*/ CONTENTS* pSelectedItem; // ItemBasePtr
/*0x2c8*/ bool               bInventoryWasActive;
/*0x2cc*/ int                CurrentItem;
/*0x2d0*/ int                CurrentQuantity;
/*0x2d4*/ int                SliderType;
/*0x2d8*/ PointMerchantInterface* pHandler;
/*0x2dc*/
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
// CRaidWindow_size: 0x398 (see 543822) in Aug 15 2019 Live
class [[offsetcomments]] CRaidWnd : public CSidlScreenWnd, public WndEventHandler, public CVivoxObserver
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

/*0x22c*/ uint8_t            Unknown0x0240[0xac];
/*0x2d8*/ COLORREF           ClassColors[0x10];
/*0x318*/ uint8_t            Unknown0x0338[0x80];
/*0x398*/
};
using EQRAIDWINDOW [[deprecated]] = CRaidWnd;
using PEQRAIDWINDOW [[deprecated]] = CRaidWnd *;

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
// Actual size 0x280 23 oct 2017 Beta see 7B413F
class [[offsetcomments]] CSpellDisplayWnd : public CSidlScreenWnd
{
	FORCE_SYMBOLS

public:
	CSpellDisplayWnd(CXWnd* parent, ESpellDisplayType displayType);
	virtual ~CSpellDisplayWnd();

/*0x220*/ int                WindowID;
/*0x224*/ CLabelWnd*         pDuration;
/*0x228*/ CStmlWnd*          pDescription;
/*0x22c*/ CStmlWnd*          pName;
/*0x230*/ CButtonWnd*        pIcon;
/*0x234*/ SoeUtil::IString   DescriptionText;
/*0x244*/ SoeUtil::IString   TitleText;
/*0x254*/ bool               bActiveItem;
/*0x258*/ CTextureAnimation* ptaBuffIcons;
/*0x25c*/ CTextureAnimation* ptaDragIcons;
/*0x260*/ bool               bFailed;
/*0x264*/ ESpellDisplayType  SpellDisplayType;
/*0x268*/ int                SpellID;
/*0x26c*/ int                LastUpdateTime;
/*0x270*/
};
using EQSPELLINFOWINDOW [[deprecated]] = CSpellDisplayWnd;
using PEQSPELLINFOWINDOW [[deprecated]] = CSpellDisplayWnd*;

//============================================================================
// CSpellGemWnd
//============================================================================

// CSpellGemWnd__CSpellGemWnd
// CSpellGemWnd_size: 0x310 (see 7F89CB) in Aug 15 2019 Live
class [[offsetcomments]] CSpellGemWnd : public CButtonWnd
{
public:
	CSpellGemWnd(CXWnd*, uint32_t, const CXRect&, CTextureAnimation*, CTextureAnimation*, CTextureAnimation*, int, int, unsigned long);
	virtual ~CSpellGemWnd();

	EQLIB_OBJECT void SetGemTintStage(int);
	EQLIB_OBJECT void SetSpellGemTint(unsigned long);
	EQLIB_OBJECT void SetSpellIconIndex(int);

	//----------------------------------------------------------------------------
	// data members

/*0x270*/ int                MouseButtonState;
/*0x274*/ bool               bChecked;
/*0x278*/ unsigned int       LastRefresh;
/*0x27c*/ D3DCOLOR           SpellGemTintArray[0xb];   // I dont understand why there are only 11 of these when we have 13 gems noaways, probably a bug or unused?
/*0x2a8*/ int                SpellGemAlphaArray[0xb];
/*0x2d4*/ int                Unknown0x02f4;
/*0x2d8*/ int                Unknown0x02f8;
/*0x2dc*/ int                SpellIconOffsetX;
/*0x2e0*/ int                SpellIconOffsetY;
/*0x2e4*/ int                spellicon;                // if this is equal to FFFFFFFF there is no spell memmed in this slot...
/*0x2e8*/ int                spellstate;               // 1 = cast in progress or refreshtime not met 2 means we ducked or aborted cast, 0 means its ok to cast, should really rename this to tintstage
/*0x2ec*/ int                TintIndex;
/*0x2f0*/ CTextureAnimation* SpellIconTexture;         // CTextureAnimation
/*0x2f4*/ CTextureAnimation* CustomIconTexture;        // CTextureAnimation
/*0x2f8*/ int                SpellSlot;
/*0x2fc*/ int                Percent;
/*0x300*/ CSpellGemDrawTemplate DrawTemplate;
/*0x310*/
};
using EQCASTSPELLGEM [[deprecated]] = CSpellGemWnd;
using PEQCASTSPELLGEM [[deprecated]] = CSpellGemWnd *;

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
class [[offsetcomments]] CTargetWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CTargetWnd(CXWnd*);
	virtual ~CTargetWnd();

	EQLIB_OBJECT CXStr* GetBuffCaster(int SpellID);
	EQLIB_OBJECT void RefreshTargetBuffs(BYTE* buffer);
	EQLIB_OBJECT void HandleBuffRemoveRequest(CXWnd* pWnd);

	//----------------------------------------------------------------------------
	// data members

/*0x224*/ CXWnd*             pWndBuffs;
/*0x228*/ CTextureAnimation* pBuffGoodBackground;
/*0x22c*/ CTextureAnimation* pBuffBadBackground;
/*0x230*/ CTextureAnimation* pBuffBypassBackground;
/*0x234*/ CTextureAnimation* ptaBuffIcons[NUM_BUFF_SLOTS];
/*0x3b8*/ CButtonWnd*        pTargetBuff[NUM_BUFF_SLOTS];
/*0x53c*/ int                BuffSpellID[NUM_BUFF_SLOTS]; // 0xffffffff if no buff
/*0x6c0*/ int                BuffTimer[NUM_BUFF_SLOTS];
/*0x844*/ int                Unknown0x0864[0x24];
/*0x8d4*/ int                Type;                     // 1 = self, 4 = group member, 5 = PC, 7 = NPC
/*0x8d8*/ uint8_t            Unknown0x088c[0x4c];
/*0x924*/
};
using CTARGETWND [[deprecated]] = CTargetWnd;
using PCTARGETWND [[deprecated]] = CTargetWnd*;

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

class [[offsetcomments]] CTextEntryWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
	CTextEntryWnd(CXWnd*);
	virtual ~CTextEntryWnd();

	EQLIB_OBJECT void Open(CXWnd* pwnd, int EditMode, char* Prompt, int MinLength, int MaxLength, const char* InitialText);
	EQLIB_OBJECT CXStr GetEntryText();
	EQLIB_OBJECT void Activate(CXWnd*, int, char*, int, int, char*);
	EQLIB_OBJECT void Callback(bool);
	EQLIB_OBJECT void UpdateButtons();

/*0x224*/ int          m_minLength;
/*0x228*/ int          m_maxLength;
/*0x22c*/ CXStr        m_text;
/*0x230*/ CXWnd*       m_parent;
/*0x234*/ CEditWnd*    m_entry;
/*0x238*/ CLabel*      m_prompt;
/*0x23c*/ CButtonWnd*  m_ok;
/*0x240*/ CButtonWnd*  m_cancel;
/*0x244*/
};
using CTEXTENTRYWND [[deprecated]] = CTextEntryWnd;
using PCTEXTENTRYWND [[deprecated]] = CTextEntryWnd*;

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

struct [[offsetcomments]] TradeskillRecipe
{
	FORCE_SYMBOLS;

/*0x00*/ int ID;
/*0x04*/ int Trivial;
/*0x08*/ int ContainerType;
/*0x0c*/ int ContainerID;
/*0x10*/ int RequiredSize;
/*0x14*/ char Name[0x40];
/*0x54*/ bool bUnknown;
/*0x58*/ int Ingredient[MAX_RECIPE_ITEMS];                 // ID# of ingredient(s)
/*0x80*/ int IngredientIcon[MAX_RECIPE_ITEMS];             // Icon# of ingredient(s) (Note: 499 is blank)
/*0xa8*/
};
using EQTRADESKILLRECIPE [[deprecated]] = TradeskillRecipe;
using PEQTRADESKILLRECIPE [[deprecated]] = TradeskillRecipe *;

// size: 0xd28 Jun 10, 2019 (test)
class [[offsetcomments]] CTradeSkillWnd : public CSidlScreenWnd
{
	FORCE_SYMBOLS;

public:
	CTradeSkillWnd(CXWnd* parent);
	virtual ~CTradeSkillWnd();

	//----------------------------------------------------------------------------
	// data members

	// todo: check and update
/*0x220*/ DWORD        Unknown0x148[0x1b];
/*0x28c*/ TradeskillRecipe* SearchResults[0x64];
/*0x41c*/ DWORD        Unknown0x344;
/*0x420*/ DWORD        Unknown0x348;
/*0x424*/ DWORD        Unknown0x34c;
/*0x428*/ CONTENTS*    Container;
/*0x42c*/ DWORD        Unknown0x354;
/*0x430*/ TradeskillRecipe* SelectedRecipe;
/*0x434*/ DWORD        Unknown0x35c;
/*0x438*/ DWORD        SkillLevel;
/*0x43c*/ DWORD        Unknown0x364;
/*0x440*/ DWORD        Unknown0x368;
/*0x444*/ BYTE         Unknown0x36c[0x58];
/*0x49c*/ DWORD        Unknown0x3c4;
/*0x4a0*/ DWORD        Unknown0x3c8;
/*0x4a4*/ BYTE         Unknonw0x3cc[0x8];
/*0x4ac*/ DWORD        Unknown0x3d4;
/*0x4b0*/ DWORD        Unknown0x3d8;
/*0x4b4*/
};
using EQTRADESKILLWINDOW [[deprecated]] = CTradeSkillWnd;
using PEQTRADESKILLWINDOW [[deprecated]] = CTradeSkillWnd*;

//============================================================================
// CTradeWnd
//============================================================================

constexpr int MAX_TRADE_SLOTS = 16;

// CTradeWnd__CTradeWnd aTradewnd
// CTradeWnd__size: 0x2e0 (see 5445A7) in Aug 15 2019 Live
class [[offsetcomments]] CTradeWnd : public CSidlScreenWnd, public WndEventHandler
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

/*0x224*/ unsigned int       NextRefreshTime;
/*0x228*/ bool               bInventoryWasOpen;
/*0x22c*/ CButtonWnd*        HisMoneyButton[4];
/*0x23c*/ CButtonWnd*        MyMoneyButton[4];
/*0x24c*/ CButtonWnd*        TradeButton;
/*0x250*/ CButtonWnd*        CancelButton;
/*0x254*/ CLabel*            HisNameLabel;
/*0x258*/ CLabel*            MyNameLabel;
/*0x25c*/ CInvSlotWnd*       pInvSlotWnd[MAX_TRADE_SLOTS];
/*0x29c*/ long               HisMoney[4];
/*0x2ac*/ long               MyMoney[4];
/*0x2bc*/ ItemBaseContainer  TradeItems;
/*0x2d8*/ bool               bHisReadyTrade;           // was HisTradeReady
/*0x2d9*/ bool               bMyReadyTrade;            // was MyTradeReady
/*0x2da*/ bool               bIsTrading;               // was TradeWndOpen
/*0x2dc*/
};
using EQTRADEWINDOW [[deprecated]] = CTradeWnd;
using PEQTRADEWINDOW [[deprecated]] = CTradeWnd *;

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

class [[offsetcomments]] ZoneGuideConnection
{
	FORCE_SYMBOLS;

public:
/*0x00*/ EQZoneIndex        DestZone;
/*0x04*/ int                TransferTypeIndex;
/*0x08*/ int                RequiredExpansions;       // EQExpansionOwned
/*0x0c*/ bool               bDisabled;
/*0x10*/
};

class [[offsetcomments]] ZoneGuideContinent
{
	FORCE_SYMBOLS;

public:
/*0x00*/ int                ID;
/*0x04*/ int                DisplaySequence;
/*0x08*/ CXStr              Name;
/*0x0c*/
};

class [[offsetcomments]] ZoneGuideZoneType
{
	FORCE_SYMBOLS;

public:
/*0x00*/ int                ID;
/*0x04*/ int                DisplaySequence;
/*0x08*/ CXStr              Name;
/*0x0c*/
};

class [[offsetcomments]] ZoneGuideTransferType
{
	FORCE_SYMBOLS;

public:
/*0x00*/ int                ID;
/*0x04*/ CXStr              Description;
/*0x08*/
};

// see 8E87D6 in Apr 15 2019 exe
class [[offsetcomments]] ZoneGuideZone
{
	FORCE_SYMBOLS;

public:
/*0x00*/ EQZoneIndex   ID;
/*0x04*/ CXStr         Name;
/*0x08*/ int           ContinentIndex;
/*0x0c*/ int           MinLevel;
/*0x10*/ int           MaxLevel;
/*0x14*/ DynamicBitField<unsigned short, short> Types;
/*0x1c*/ ArrayClass<ZoneGuideConnection> ZoneConnections;
/*0x2c*/
};

struct [[offsetcomments]] ZonePathData
{
	FORCE_SYMBOLS;

/*0x00*/ EQZoneIndex        ZoneID;
/*0x04*/ int                TransferTypeIndex;
/*0x08*/
};

// see 8D35C1 in may 10 2018 exe
#define ZONE_COUNT 836

class [[offsetcomments]] ZoneGuideManagerBase
{
	FORCE_SYMBOLS;

public:
	ZoneGuideManagerBase();
	virtual ~ZoneGuideManagerBase();

	virtual void ResetAllData();
	//virtual void Serialize(CSerializeBuffer&);
	//virtual void Unserialize(CUnserializeBuffer&);

/*0x0004*/ ZoneGuideZone Zones[ZONE_COUNT];
/*0x8fb4*/ ArrayClass<ZoneGuideContinent> Continents;
/*0x8fc4*/ ArrayClass<ZoneGuideZoneType> ZoneTypes;
/*0x8fd4*/ ArrayClass<ZoneGuideTransferType> TransferTypes;
/*0x8fe4*/
};

// size: 0x9010 see 6AB098 in Apr 15 2019 exe
class [[offsetcomments]] ZoneGuideManagerClient : public ZoneGuideManagerBase
{
	FORCE_SYMBOLS;

public:
/*0x8fe4*/ ArrayClass<ZonePathData> ActivePath;
/*0x8ff4*/ ArrayClass<ZonePathData> PreviewPath;
/*0x9004*/ EQZoneIndex CurrZone;
/*0x9008*/ int         HerosJourneyIndex;
/*0x900c*/ bool        bZoneGuideDataSet;
/*0x900d*/ bool        bIncludeBindZoneInPath;
/*0x900e*/ bool        bAutoFindActivePath;
/*0x900f*/ bool        bFindActivePath;
/*0x9010*/

	static ZoneGuideManagerClient& Instance();
};

class [[offsetcomments]] CZoneGuideWnd : public CSidlScreenWnd, public WndEventHandler
{
public:
/*0x224*/ CVerticalLayoutWnd* VerticalLayout;
/*0x228*/ CButtonWnd*        FilterMyLevelButton;
/*0x22c*/ CButtonWnd*        FilterAllLevelsButton;
/*0x230*/ CButtonWnd*        FilterZonesActiveButton;
/*0x234*/ CButtonWnd*        FilterZonesInactiveButton;
/*0x238*/ CButtonWnd*        ZoneRunSearchButton;
/*0x23c*/ CButtonWnd*        ZoneClearSearchButton;
/*0x240*/ CButtonWnd*        SelectCurrentZoneButton;
/*0x244*/ CEditWnd*          LevelFilterEdit;
/*0x248*/ CEditWnd*          ZoneSearchEdit;
/*0x24c*/ CComboWnd*         TypeFilterCombo;
/*0x250*/ CComboWnd*         ContinentFilterCombo;
/*0x254*/ CListWnd*          ZonesList;
/*0x258*/ CLabelWnd*         ViewZoneConnectionsSelectedZoneLabel;
/*0x25c*/ CLabelWnd*         ViewZoneConnectionsPreviewPathLabel;
/*0x260*/ CLabelWnd*         ViewZoneConnectionsActivePathLabel;
/*0x264*/ CLabelWnd*         ViewZoneConnectionsDisabledLabel;
/*0x268*/ CButtonWnd*        ViewZoneConnectionsSelectedZoneButton;
/*0x26c*/ CButtonWnd*        ViewZoneConnectionsPreviewPathButton;
/*0x270*/ CButtonWnd*        ViewZoneConnectionsActivePathButton;
/*0x274*/ CButtonWnd*        ViewZoneConnectionsDisabledButton;
/*0x278*/ CButtonWnd*        DisableConnectionTemplateButton;
/*0x27c*/ CListWnd*          ZoneConnectionsList;
/*0x280*/ CButtonWnd*        ResetPathStartZoneButton;
/*0x284*/ CButtonWnd*        SetPathStartZoneButton;
/*0x288*/ CButtonWnd*        SetPathEndZoneButton;
/*0x28c*/ CButtonWnd*        ShowPathWndButton;
/*0x290*/ CButtonWnd*        HidePathWndButton;
/*0x294*/ CButtonWnd*        FindPathButton;
/*0x298*/ CButtonWnd*        EndFindButton;
/*0x29c*/ CButtonWnd*        ClearPathWndButton;
/*0x2a0*/ CButtonWnd*        ActivatePathButton;
/*0x2a4*/ CButtonWnd*        IncludeBindZoneInPathGenerationButton;
/*0x2a8*/ CButtonWnd*        ShowPathWndOnPathActivationButton;
/*0x2ac*/ CButtonWnd*        AutoFindActivePathButton;
/*0x2b0*/ CEditWnd*          PathStartZoneEdit;
/*0x2b4*/ CEditWnd*          PathEndZoneEdit;
/*0x2b8*/ UINT               NextButtonRefreshTime;
/*0x2bc*/ EQZoneIndex        eCurrentZone;
/*0x2c0*/ bool               bFilterActive;
/*0x2c4*/ int                FilterLevel;
/*0x2c8*/ int                FilterContinentIndex;
/*0x2cc*/ int                FilterZoneTypeIndex;
/*0x2d0*/ bool               bSelectCurrentZone;
/*0x2d4*/ CXStr              ZoneSearchString;
/*0x2d8*/ eZoneGuideConnectionsView eCurrConnectionsView;
/*0x2dc*/ EQZoneIndex        CurrConnectionsViewSelectedZone;
/*0x2e0*/ bool               bCurrentConnectionsViewPreviewPathChanged;
/*0x2e1*/ bool               bCurrentConnectionsViewActivePathChanged;
/*0x2e2*/ bool               bSetPathStartZoneToCurrentZone;
/*0x2e4*/ EQZoneIndex        StartZone;
/*0x2e8*/ EQZoneIndex        EndZone;
/*0x2ec*/ bool               bZoneGuideDataChanged;
/*0x2ed*/ bool               bZoneListChanged;
/*0x2ee*/ bool               bZoneConnectionsListChanged;
/*0x2ef*/ bool               bPathStartZoneChanged;
/*0x2f0*/ int                RightClickMenuID;
/*0x2f4*/
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

	ArrayClass2<ArrayClass2<CKeyCXStrElementType>> HashData;
};

class [[offsetcomments]] CXMLSymbolItem
{
public:
/*0x00*/ CXStr                              ItemString;
/*0x04*/ bool                               bDeclared;
/*0x05*/ bool                               bValid;
/*0x08*/
};

class [[offsetcomments]] CXMLSymbolClass
{
public:
/*0x00*/ CXStr                              Class;
/*0x04*/ ArrayClass2<CXMLSymbolItem>     ItemsArray;
/*0x1c*/ CHashCXStrInt32                    ItemsHashes;
/*0x34*/ bool                               bValid;
/*0x38*/
};

class [[offsetcomments]] CXMLSymbolTable
{
public:
/*0x00*/ void* vfTable;
/*0x04*/ ArrayClass2<CXMLSymbolClass> ClassesArray;
/*0x1c*/ CHashCXStrInt32               ClassesHashes;
/*0x34*/
};

class [[offsetcomments]] CXMLDataManager
{
public:
/*0x00*/ void* vfTable;
/*0x04*/ CHashCXStrInt32               EnumTypeHashes;
/*0x1c*/ ArrayClass2<CXMLEnumInfo>  XMLEnumArray;
/*0x34*/ HashCXStrElement<CXMLDataPtr, 16 * 1024> ClassItemHashes;
/*0x4c*/ ArrayClass2<CXMLDataClass> XMLDataArray;
/*0x64*/ CXMLSymbolTable               SymbolTable;
/*0x98*/ CXStr                         ErrorString;
/*0x9c*/

	EQLIB_OBJECT CXMLDataManager();
	EQLIB_OBJECT bool IsDerivedFrom(int, int);
	EQLIB_OBJECT bool ReadFromXMLSOM(CXMLSOMDocument&);
	EQLIB_OBJECT CXMLData* GetXMLData(CXStr className, CXStr itemName);
	EQLIB_OBJECT CXMLData* GetXMLData(int classIndex, int itemIndex) const;
	EQLIB_OBJECT CXMLData* GetXMLData(int xmlIndex) const
	{
		return GetXMLData(xmlIndex >> 16, xmlIndex & 0xffff);
	}

	EQLIB_OBJECT UIType GetWindowType(const CXWnd* wnd) const;

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
class [[offsetcomments]] CSidlManagerBase
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
/*0x090*/ ArrayClass<CTextureAnimation*>         AnimationArray;
/*0x0a0*/ CHashCXStrInt32                        AnimationsHash;
/*0x0b8*/ ArrayClass<CTAFrameDraw*>              TAFrameArray;
/*0x0c8*/ CHashCXStrInt32                        TAFrameHash;
/*0x0e0*/ ArrayClass<CScreenPieceTemplate*>      ScreenPieceArray;
/*0x0f0*/ CHashCXStrInt32                        ScreenPiecesHash;
/*0x108*/ ArrayClass<CLayoutStrategyTemplate*>   LayoutStrategyTemplateArray;
/*0x118*/ CHashCXStrInt32                        LayoutStrategyTemplatesHash;
/*0x130*/ CXMLParamManager                       XMLDataMgr;
/*0x1cc*/ bool                                   bLoadError;
/*0x1d0*/ CXStr                                  ErrorString;
/*0x1d4*/
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

using CSIDLMGR [[deprecated]] = CSidlManager;
using PCSIDLMGR [[deprecated]] = CSidlManager*;

//----------------------------------------------------------------------------

void InitializeUI();

} // namespace eqlib
