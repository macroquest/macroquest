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

namespace eqlib {

enum UIType
{
	UI_Unknown                                   = -1,
	UI_Class                                     = 0,
	UI_RGB                                       = 1,
	UI_RGBText                                   = 2,   // new since the patch on Jan 08 2018 Test see 0x90EC67
	UI_Point                                     = 3,
	UI_Size                                      = 4,
	UI_TextureInfo                               = 5,
	UI_Frame                                     = 6,
	UI_Ui2DAnimation                             = 7,
	UI_ButtonDrawTemplate                        = 8,
	UI_GaugeDrawTemplate                         = 9,
	UI_SpellGemDrawTemplate                      = 10,
	UI_FrameTemplate                             = 11,
	UI_ScrollbarDrawTemplate                     = 12,
	UI_WindowDrawTemplate                        = 13,
	UI_SliderDrawTemplate                        = 14,
	UI_ScreenPiece                               = 15,
	UI_StaticScreenPiece                         = 16,
	UI_StaticAnimation                           = 17,
	UI_StaticTintedBlendAnimation                = 18,
	UI_StaticText                                = 19,
	UI_StaticFrame                               = 20,
	UI_StaticHeader                              = 21,
	UI_LayoutStrategy                            = 22,
	UI_LayoutVertical                            = 23,
	UI_LayoutHorizontal                          = 24,
	UI_Control                                   = 25,
	UI_TemplateAssoc                             = 26,
	UI_TemplateScreen                            = 27,
	UI_ListboxColumn                             = 28,
	UI_Listbox                                   = 29,
	UI_Button                                    = 30,
	UI_Gauge                                     = 31,
	UI_SpellGem                                  = 32,
	UI_HtmlComponent                             = 33,
	UI_InvSlot                                   = 34,
	UI_EditBox                                   = 35,
	UI_Slider                                    = 36,
	UI_Label                                     = 37,
	UI_STMLBox                                   = 38,
	UI_TreeView                                  = 39,
	UI_Combobox                                  = 40,
	UI_Page                                      = 41,
	UI_TabBox                                    = 42,
	UI_LayoutBox                                 = 43,
	UI_HorizontalLayoutBox                       = 44,
	UI_VerticalLayoutBox                         = 45,
	UI_FinderBox                                 = 46,
	UI_TileLayoutBox                             = 47,
	UI_NamedTemplatePiece                        = 48,
	UI_TemplateContainer                         = 49,
	UI_Screen                                    = 50,
	UI_SuiteDefaults                             = 51,
	UI_Screens                                   = 52,
	UI_TopLevelWindowList                        = 53,
	UI_HotButton                                 = 54,
};

struct CXWnd_VirtualFunctions
{
/*0x000*/ void* IsValid;
/*0x004*/ void* vector_deleting_destructor;
/*0x008*/ void* DrawNC;
/*0x00c*/ void* PostDraw;
/*0x010*/ void* PostDraw2;
/*0x014*/ void* DrawCursor;
/*0x018*/ void* CXWnd__OnResize;
/*0x01c*/ void* PostDraw3;
/*0x020*/ void* DrawBackground;
/*0x024*/ void* DrawTooltip;
/*0x028*/ void* DrawTooltipAtPoint;
/*0x02c*/ void* GetMinimizedRect;
/*0x030*/ void* DrawTitleBar;
/*0x034*/ void* GetCursorToDisplay;
/*0x038*/ void* HandleLButtonDown;
/*0x03c*/ void* HandleLButtonUp;
/*0x040*/ void* HandleLButtonHeld;
/*0x044*/ void* HandleLButtonUpAfterHeld;
/*0x048*/ void* HandleRButtonDown;
/*0x04c*/ void* HandleRButtonUp;
/*0x050*/ void* HandleRButtonHeld;
/*0x054*/ void* HandleRButtonUpAfterHeld;
/*0x058*/ void* HandleWheelButtonDown;
/*0x05c*/ void* HandleWheelButtonUp;
/*0x060*/ void* HandleMouseMove;
/*0x064*/ void* HandleWheelMove;
/*0x068*/ void* GetDragDropCursor;
/*0x06c*/ void* PostDraw4;
/*0x070*/ void* OnDragDrop;
/*0x074*/ void* GetClickStickCursor;
/*0x078*/ void* QueryDropOK;
/*0x07c*/ void* OnClickStick;
/*0x080*/ void* GetClickStickCursor2;
/*0x084*/ void* QueryClickStickDropOK;
/*0x088*/ void* WndNotification;
/*0x08c*/ void* OnWndNotification;
/*0x090*/ void* ShowWindow;                      // Activate 
/*0x094*/ void* Deactivate;
/*0x098*/ void* PostDraw5;
/*0x09c*/ void* OnResize;
/*0x0a0*/ void* OnResize2;
/*0x0a4*/ void* Unknown0xa4;
/*0x0a8*/ void* Unknown0xa8;
/*0x0ac*/ void* OnMinimizeBox;
/*0x0b0*/ void* Unknown0xb0;
/*0x0b4*/ void* OnTileBox;
/*0x0b8*/ void* PostDraw6;
/*0x0bc*/ void* OnMove2;
/*0x0c0*/ void* OnMove3;
/*0x0c4*/ void* OnProcessFrame;                  // Dofade
/*0x0c8*/ void* OnVScroll;
/*0x0cc*/ void* OnHScroll;
/*0x0d0*/ void* PostDraw7;
/*0x0d4*/ void* OnMove4;
/*0x0d8*/ void* Show;
/*0x0dc*/ void* AboutToShow;
/*0x0e0*/ void* AboutToHide;
/*0x0e4*/ void* RequestDockInfo;
/*0x0e8*/ void* GetTooltip;
/*0x0ec*/ void* Unknown0x0ec;                    // this is new and added on oct 11 2016 its just empty
/*0x0f0*/ void* HitTest;
/*0x0f4*/ void* GetHitTestRect;
/*0x0f8*/ void* GetInnerRect;
/*0x0fc*/ void* GetClientRect;
/*0x100*/ void* GetClientClipRect;
/*0x104*/ void* GetMinSize;
/*0x108*/ void* GetMaxSize;
/*0x10c*/ void* GetUntileSize;
/*0x110*/ void* IsPointTransparent;
/*0x114*/ void* Unknown114;
/*0x118*/ void* Unknown118;
/*0x11c*/ void* SetDrawTemplate;
/*0x120*/ void* Move_Rect;                       // CXWnd__Move1_x
/*0x124*/ void* Move_Point;                      // CXWnd__Move_x
/*0x128*/ void* SetWindowText;
/*0x12c*/ void* GetChildWndAt;                   // CXWnd__GetChildWndAt_x
/*0x130*/ void* GetSidlPiece;                    // CSidlScreenWnd__GetSidlPiece_x
/*0x134*/ void* CSidlScreenWnd__OnPreZone1a;
/*0x138*/ void* SetVScrollPos;
/*0x13c*/ void* SetHScrollPos;
/*0x140*/ void* AutoSetVScrollPos;
/*0x144*/ void* AutoSetHScrollPos;
/*0x148*/ void* SetAttributesFromSidl;
/*0x14c*/ void* nullsub_1a;
/*0x150*/ void* Unknown0x14c;
/*0x154*/ void* nullsub_1b;
/*0x158*/ void* GetMinClientSize;
/*0x15c*/ void* GetMaxClientSize;
/*0x160*/ void* CSidlScreenWnd__OnPreZone1b;
/*0x164*/ void* UpdateLayout;
/*0x168*/
};

using CXWNDVFTABLE = CXWnd_VirtualFunctions;
using PCXWNDVFTABLE = CXWnd_VirtualFunctions*;

// CXWSize
// actual size 0x1E4 in Sep 16 2015 Test (see 0x693122)
// actual size 0x1CC in Jan 13 2016 Test (see 0x6984E8)
// actual size 0x1C8 in Feb 10 2016 Test (see 0x699238)
// actual size 0x1D4 in May 23 2016 Test (see 0x691812)
// actual size 0x1DC in Jun 21 2016 Test (see 0x691E82)
// actual size 0x1D0 in Oct 26 2018 Test (see 0x91E99D)
// actual size 0x1D8 in Mar 14 2019 Test (see 0x93174D)
// actual size 0x1F0 in Apr  9 2019 Test (see 0x9341FD)
// actual size 0x1E8 in Apr 18 2019 Test (see 0x933F5D)
// actual size 0x1E0 in May  7 2019 Test (see 0x932FAD)
// actual size 0x1F8 in Jun 10 2019 Test (see 0x9351BD)
class CXWnd
	: public TListNode<CXWnd>   // node in list of siblings
	, public TList<CXWnd>       // list of children
{
public:
#if defined(LIVE)
#include "../live/CXWnd-Members.h"
#elif defined(TEST)
#include "../test/CXWnd-Members.h"
#else
#error "Need CXWnd-Members""
#endif

	// -----------------------------------------------------------------------

	EQLIB_OBJECT CXWnd* SetParent(CXWnd*);
	EQLIB_OBJECT CXWnd* GetChildItem(CXStr Name);
	EQLIB_OBJECT CXWnd(CXWnd*, uint32_t, const CXRect&);
	EQLIB_OBJECT virtual ~CXWnd();

	EQLIB_OBJECT bool HasFocus() const;
	EQLIB_OBJECT bool IsActive() const;
	EQLIB_OBJECT bool IsDescendantOf(CXWnd const*) const;
	EQLIB_OBJECT bool IsReallyVisible() const;
	EQLIB_OBJECT bool IsType(EWndRuntimeType eType) const;
	EQLIB_OBJECT const CButtonDrawTemplate* GetCloseBoxTemplate() const;
	EQLIB_OBJECT const CButtonDrawTemplate* GetMinimizeBoxTemplate() const;
	EQLIB_OBJECT const CButtonDrawTemplate* GetTileBoxTemplate() const;
	EQLIB_OBJECT const CTAFrameDraw* GetBorderFrame() const;
	EQLIB_OBJECT const CTAFrameDraw* GetTitlebarHeader() const;
	EQLIB_OBJECT CXRect GetClientClipRect() const;
	EQLIB_OBJECT CXRect GetRelativeRect() const;
	EQLIB_OBJECT CXRect GetScreenClipRect() const;
	EQLIB_OBJECT CXRect GetScreenRect() const;
	EQLIB_OBJECT CXStr GetWindowTextA() const;
	EQLIB_OBJECT CXWnd* GetChildItem(CXStr const &);
	EQLIB_OBJECT CXWnd* GetChildWndAt(CXPoint*, int, int) const;
	EQLIB_OBJECT CXWnd* GetNextChildWnd(CXWnd*) const;
	EQLIB_OBJECT CXWnd* GetNextSib() const;
	EQLIB_OBJECT CXWnd* SetFocus();
	EQLIB_OBJECT int DoAllDrawing() const;
	EQLIB_OBJECT int DrawChildren() const;
	EQLIB_OBJECT int DrawCloseBox() const;
	EQLIB_OBJECT int DrawHScrollbar(int, int, int) const;
	EQLIB_OBJECT int DrawMinimizeBox() const;
	EQLIB_OBJECT int DrawTileBox() const;
	EQLIB_OBJECT int DrawVScrollbar(int, int, int) const;
	EQLIB_OBJECT int GetWidth() const;
	EQLIB_OBJECT int Minimize(bool);
#if !defined(ROF2EMU) && !defined(UFEMU)
	EQLIB_OBJECT int Move(CXPoint const &);
#else
	EQLIB_OBJECT int Move(CXPoint);
#endif
	// Move (this is CXWnd__Move1_x) was checked on apr 29 2016 - eqmule
	EQLIB_OBJECT int Move(const CXRect& rc, bool bUpdateLayout = true, bool bForceUpdateLayout = false, bool bCompleteMoveOrResize = false, bool bMoveAutoStretch = false);
	EQLIB_OBJECT int ProcessTransition();
	EQLIB_OBJECT int Resize(int Width, int Height, bool bUpdateLayout = true, bool bCompleteMoveOrResize = false, bool bMoveAutoStretch = false);
	EQLIB_OBJECT int Show(bool bShow = true, bool bBringToTop = true, bool bUpdateLayout = true);
	EQLIB_OBJECT int Tile(bool);
	EQLIB_OBJECT static CXRect GetTooltipRect(const CXPoint&, const CXSize&);
	EQLIB_OBJECT static CXRect GetTooltipRect(const CXRect&);
	EQLIB_OBJECT static CXWndDrawTemplate sm_wdtDefaults;
	EQLIB_OBJECT static int DrawColoredRect(const CXRect&, unsigned long, const CXRect&);
	EQLIB_OBJECT static int DrawLasso(const CXRect&, unsigned long, const CXRect&);
	EQLIB_OBJECT static int DrawRaisedRect(const CXRect&, const CXRect&);
	EQLIB_OBJECT static int DrawSunkenRect(const CXRect&, const CXRect&);
	EQLIB_OBJECT void Bottom();
	EQLIB_OBJECT void BringChildWndToTop(CXWnd*);
	EQLIB_OBJECT void BringToTop(bool bRecurse = true);
	EQLIB_OBJECT void Center();
	EQLIB_OBJECT void ClrFocus();
	EQLIB_OBJECT int Destroy();
	EQLIB_OBJECT void DrawTooltipAtPoint(CXPoint) const;
	EQLIB_OBJECT void Left();
	EQLIB_OBJECT void Refade();
	EQLIB_OBJECT void Right();
	EQLIB_OBJECT void SetFirstChildPointer(CXWnd*);
	EQLIB_OBJECT void SetKeyTooltip(int, int);
	EQLIB_OBJECT void SetLookLikeParent();
	EQLIB_OBJECT void SetMouseOver(bool);
	EQLIB_OBJECT void SetNextSibPointer(CXWnd*);
	EQLIB_OBJECT void SetTooltip(CXStr);
	EQLIB_OBJECT void SetXMLTooltip(CXStr);
	//EQLIB_OBJECT void SetZLayer(int);
	EQLIB_OBJECT void StartFade(unsigned char, uint32_t);

	// virtual
	EQLIB_OBJECT bool IsPointTransparent(const CXPoint&) const;
	EQLIB_OBJECT bool IsValid() const;
	EQLIB_OBJECT bool QueryClickStickDropOK(CClickStickInfo*) const;
	EQLIB_OBJECT bool QueryDropOK(SDragDropInfo*) const;
	EQLIB_OBJECT CTextureAnimation* GetClickStickCursor(CClickStickInfo*) const;
	EQLIB_OBJECT CTextureAnimation* GetCursorToDisplay() const;
	EQLIB_OBJECT CTextureAnimation* GetDragDropCursor(SDragDropInfo*) const;
	EQLIB_OBJECT CXRect GetClientRect() const;
	EQLIB_OBJECT CXRect GetHitTestRect(int) const;
	EQLIB_OBJECT CXRect GetInnerRect() const;
	EQLIB_OBJECT CXRect GetMinimizedRect() const;
	EQLIB_OBJECT CXSize GetMinSize() const;
	EQLIB_OBJECT CXSize GetUntileSize() const;
	EQLIB_OBJECT int AboutToDeleteWnd(CXWnd*);
	EQLIB_OBJECT int Draw() const;
	EQLIB_OBJECT int DrawBackground() const;
	EQLIB_OBJECT int DrawCaret() const;
	EQLIB_OBJECT int DrawChildItem(CXWnd const*, void*) const;
	EQLIB_OBJECT int DrawCursor(const CXPoint&, const CXRect&, bool &);
	EQLIB_OBJECT int DrawNC() const;
	EQLIB_OBJECT int DrawTitleBar(const CXRect&) const;
	EQLIB_OBJECT int DrawTooltip(const CXWnd*) const;
	EQLIB_OBJECT int HandleKeyboardMsg(uint32_t, uint32_t, bool);
	EQLIB_OBJECT int HandleLButtonDown(const CXPoint&, uint32_t);
	EQLIB_OBJECT int HandleLButtonHeld(const CXPoint&, uint32_t);
	EQLIB_OBJECT int HandleLButtonUp(const CXPoint&, uint32_t);
	EQLIB_OBJECT int HandleLButtonUpAfterHeld(const CXPoint&, uint32_t);
	EQLIB_OBJECT int HandleMouseMove(const CXPoint&, uint32_t);
	EQLIB_OBJECT int HandleRButtonDown(const CXPoint&, uint32_t);
	EQLIB_OBJECT int HandleRButtonHeld(const CXPoint&, uint32_t);
	EQLIB_OBJECT int HandleRButtonUp(const CXPoint&, uint32_t);
	EQLIB_OBJECT int HandleRButtonUpAfterHeld(const CXPoint&, uint32_t);
	EQLIB_OBJECT int HandleWheelButtonDown(const CXPoint&, uint32_t);
	EQLIB_OBJECT int HandleWheelButtonUp(const CXPoint&, uint32_t);
	EQLIB_OBJECT int HandleWheelMove(const CXPoint&, int, uint32_t);
	EQLIB_OBJECT int HitTest(const CXPoint&, int*) const;
	EQLIB_OBJECT int OnActivate(CXWnd*);
	EQLIB_OBJECT int OnBroughtToTop();
	EQLIB_OBJECT int OnClickStick(CClickStickInfo*, uint32_t, bool);
	EQLIB_OBJECT int OnDragDrop(SDragDropInfo*);
	EQLIB_OBJECT int OnHScroll(EScrollCode, int);
	EQLIB_OBJECT int OnKillFocus(CXWnd*);
	EQLIB_OBJECT int OnMinimizeBox();
	EQLIB_OBJECT int OnMove(const CXRect&);
	EQLIB_OBJECT int OnProcessFrame();
	EQLIB_OBJECT int OnResize(int, int);
	EQLIB_OBJECT int OnSetFocus(CXWnd*);
	EQLIB_OBJECT int OnShow();
	EQLIB_OBJECT int OnTile();
	EQLIB_OBJECT int OnTileBox();
	EQLIB_OBJECT int OnVScroll(EScrollCode, int);
	EQLIB_OBJECT int PostDraw() const;
	//int EQLIB_OBJECT RequestDockInfo(enum EDockAction, CXWnd*, class CXRect*);
	EQLIB_OBJECT int SetVScrollPos(int);
	EQLIB_OBJECT int WndNotification(CXWnd*, uint32_t, void*);
	EQLIB_OBJECT void Deactivate();
	EQLIB_OBJECT void OnReloadSidl();
	EQLIB_OBJECT void SetAttributesFromSidl(CParamScreenPiece*);
	EQLIB_OBJECT void SetDrawTemplate(CXWndDrawTemplate*);
	EQLIB_OBJECT void SetWindowText(const CXStr& Str);

	// protected
	static CXWndManager*& sm_pMgr;
	// private
	static unsigned char sm_byCurrentAlpha;
	EQLIB_OBJECT int SetFont(void*);

	// -----------------------------------------------------------------------

	EQLIB_OBJECT UIType GetType() const;
	EQLIB_OBJECT CXMLData* GetXMLData() const;

	EQLIB_OBJECT bool IsVisible() const { return dShow; }
	EQLIB_OBJECT void SetVisible(bool bValue) { dShow = bValue; }

	EQLIB_OBJECT void SetClickThrough(bool bValue) { bClickThrough = bValue; }

	EQLIB_OBJECT void SetMinClientSize(const CXSize& pt) { MinClientSize = pt; }
	EQLIB_OBJECT CXSize GetMinClientSize() const { return MinClientSize; }

	EQLIB_OBJECT void SetMaximizable(bool bValue) { bMaximizable = bValue; }

	EQLIB_OBJECT void* GetFont() const { return pFont; }

	EQLIB_OBJECT void SetEscapable(bool bValue) { CloseOnESC = bValue; }
	EQLIB_OBJECT void SetEscapableLocked(bool bValue) { bEscapableLocked = bValue; }

	EQLIB_OBJECT CXWnd* GetParentWindow() const { return ParentWindow; }
	EQLIB_OBJECT void SetParentWindow(CXWnd* pWnd) { ParentWindow = pWnd; };

	EQLIB_OBJECT const CXWnd* GetFirstChildWnd() const { return GetFirstNode(); }
	EQLIB_OBJECT CXWnd* GetFirstChildWnd() { return GetFirstNode(); }
	EQLIB_OBJECT const CXWnd* GetNextSilingWnd() const { return GetNext(); }
	EQLIB_OBJECT CXWnd* GetNextSilingWnd() { return GetNext(); }

	EQLIB_OBJECT int GetVScrollMax() const { return VScrollMax; }
	EQLIB_OBJECT int GetVScrollPos() const { return VScrollPos; }
	EQLIB_OBJECT int GetHScrollMax() const { return HScrollMax; }
	EQLIB_OBJECT int GetHScrollPos() const { return HScrollPos; }

	EQLIB_OBJECT bool IsMinimized() const { return Minimized; }
	EQLIB_OBJECT void SetMinimized(bool bValue) { Minimized = bValue; }

	EQLIB_OBJECT bool IsMouseOver() const { return MouseOver; }

	EQLIB_OBJECT CXRect GetLocation() const { return Location; }
	EQLIB_OBJECT void SetLocation(const CXRect& r) { Location = r; }

	EQLIB_OBJECT CXRect GetOldLocation() { return OldLocation; }

	EQLIB_OBJECT void SetNeedsSaving(bool bValue) { bNeedsSaving = bValue; }

	EQLIB_OBJECT void SetClientRectChanged(bool bValue) { bClientRectChanged = bValue; }

	//EQLIB_OBJECT void SetWindowText(const CXStr& Value) { WindowText = Value; }
	EQLIB_OBJECT CXStr GetWindowText() const { return WindowText; }

	EQLIB_OBJECT void SetTooltip(const CXStr& Value) { Tooltip = Value; }
	EQLIB_OBJECT CXStr GetTooltip() const { return Tooltip; }

	EQLIB_OBJECT COLORREF GetBGColor() const { return BGColor; }
	EQLIB_OBJECT void SetBGColor(COLORREF Value) { BGColor = Value; }

	EQLIB_OBJECT void SetDisabledBackground(COLORREF Value) { DisabledBackground = Value; }
	EQLIB_OBJECT COLORREF GetDisabledBackground() const { return DisabledBackground; }

	EQLIB_OBJECT bool IsEnabled() const { return Enabled; }
	EQLIB_OBJECT void SetEnabled(bool bValue) { Enabled = bValue; }

	EQLIB_OBJECT uint32_t GetWindowStyle() const { return WindowStyle; }
	EQLIB_OBJECT void SetWindowStyle(uint32_t Value) { WindowStyle = Value; }
	EQLIB_OBJECT void AddStyle(uint32_t Value) { WindowStyle |= Value; }
	EQLIB_OBJECT void RemoveStyle(uint32_t Value) { WindowStyle &= ~Value; }

	EQLIB_OBJECT void SetClipToParent(bool bValue) { bClipToParent = bValue; }
	EQLIB_OBJECT void SetUseInLayoutHorizontal(bool bValue) { bUseInLayoutHorizontal = bValue; }
	EQLIB_OBJECT void SetUseInLayoutVertical(bool bValue) { bUseInLayoutVertical = bValue; }

	EQLIB_OBJECT void SetZLayer(int Value) { ZLayer = Value; }
	EQLIB_OBJECT int GetZLayer() const { return ZLayer; }

	EQLIB_OBJECT CXWndDrawTemplate* GetDrawTemplate() const { return DrawTemplate; }

	EQLIB_OBJECT void SetActive(bool bValue) { bActive = bValue; }

	EQLIB_OBJECT void SetLocked(bool bValue) { Locked = bValue; }
	EQLIB_OBJECT bool IsLocked() const { return Locked; }

	EQLIB_OBJECT void SetFades(bool bValue) { Fades = bValue; }
	EQLIB_OBJECT bool GetFades() const { return Fades; }

	EQLIB_OBJECT void SetFaded(bool bValue) { Faded = bValue; }
	EQLIB_OBJECT bool GetFaded() const { return Faded; }

	EQLIB_OBJECT void SetFadeDelay(int Value) { FadeDelay = Value; }
	EQLIB_OBJECT int GetFadeDelay() const { return FadeDelay; }

	EQLIB_OBJECT void SetBGType(uint32_t Value) { BGType = Value; }
	EQLIB_OBJECT uint32_t GetBGType() const { return BGType; }

	EQLIB_OBJECT void SetFadeDuration(uint32_t Value) { FadeDuration = Value; }
	EQLIB_OBJECT uint32_t GetFadeDuration() const { return FadeDuration; }

	EQLIB_OBJECT void SetAlpha(uint8_t Value) { Alpha = Value; }
	EQLIB_OBJECT uint8_t GetAlpha() const { return Alpha; }

	EQLIB_OBJECT void SetFadeToAlpha(uint8_t Value) { FadeToAlpha = Value; }
	EQLIB_OBJECT uint8_t GetFadeToAlpha() const { return FadeToAlpha; }

	EQLIB_OBJECT bool GetClickable() const { return Clickable; }
	EQLIB_OBJECT void SetClickable(bool bValue) { Clickable = bValue; }

	EQLIB_OBJECT void SetData(int64_t Value) { Data = Value; }
	EQLIB_OBJECT int64_t GetData() const { return Data; }

	EQLIB_OBJECT void SetClickThroughMenuItemStatus(bool bValue) { bClickThroughMenuItemStatus = bValue; }
	EQLIB_OBJECT void SetController(void* value) { pController = value; }
	EQLIB_OBJECT void SetShowClickThroughMenuItem(bool bValue) { bShowClickThroughMenuItem = bValue; }

	EQLIB_OBJECT void SetBottomAnchoredToTop(bool bValue) { bBottomAnchoredToTop = bValue; }
	EQLIB_OBJECT void SetLeftAnchoredToLeft(bool bValue) { bLeftAnchoredToLeft = bValue; }
	EQLIB_OBJECT void SetRightAnchoredToLeft(bool bValue) { bRightAnchoredToLeft = bValue; }
	EQLIB_OBJECT void SetTopAnchoredToTop(bool bValue) { bTopAnchoredToTop = bValue; }

	EQLIB_OBJECT void SetTopOffset(int Value) { TopOffset = Value; }
	EQLIB_OBJECT int GetTopOffset() const { return TopOffset; }

	EQLIB_OBJECT void SetBottomOffset(int Value) { BottomOffset = Value; }
	EQLIB_OBJECT int GetBottomOffset() const { return BottomOffset; }

	EQLIB_OBJECT void SetLeftOffset(int Value) { LeftOffset = Value; }
	EQLIB_OBJECT int GetLeftOffset() const { return LeftOffset; }

	EQLIB_OBJECT void SetRightOffset(int Value) { RightOffset = Value; }
	EQLIB_OBJECT int GetRightOffset() const { return RightOffset; }

	EQLIB_OBJECT int GetXMLIndex() const { return XMLIndex; }

	template <typename T>
	void SetXMLTooltip(T&& Value) { XMLToolTip = std::forward<T>(Value); }
	EQLIB_OBJECT CXStr GetXMLTooltip() const { return XMLToolTip; }

	EQLIB_OBJECT void SetCRNormal(COLORREF Value) { CRNormal = Value; }
};

using CXWND = CXWnd;
using PCXWND = CXWnd*;



} // namespace eqlib

using namespace eqlib;