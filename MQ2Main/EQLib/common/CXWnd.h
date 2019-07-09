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
/*0x128*/ void* SetWindowTextA;
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
EQLIB_OBJECT class CXWnd
	: public TListNode<CXWnd>   // node in list of siblings
	, public TList<CXWnd>       // list of children
{
public:
	#include "CXWnd-Members.h"

	// -----------------------------------------------------------------------

	//CXWnd() {};
	void dCXWnd();
	CXWnd* SetParent(CXWnd*);
	CXMLData* GetXMLData();
	CXWnd* GetChildItem(CXStr Name);
	CXWnd(CXWnd*, uint32_t, const CXRect&);
	bool HasFocus() const;
	bool IsActive() const;
	bool IsDescendantOf(CXWnd const*) const;
	bool IsEnabled() const;
	bool IsReallyVisible() const;
	bool IsType(EWndRuntimeType eType) const;
	const CButtonDrawTemplate* GetCloseBoxTemplate() const;
	const CButtonDrawTemplate* GetMinimizeBoxTemplate() const;
	const CButtonDrawTemplate* GetTileBoxTemplate() const;
	const CTAFrameDraw* GetBorderFrame() const;
	const CTAFrameDraw* GetTitlebarHeader() const;
	CXRect GetClientClipRect() const;
	CXRect GetRelativeRect() const;
	CXRect GetScreenClipRect() const;
	CXRect GetScreenRect() const;
	CXStr GetWindowTextA() const;
	CXStr GetXMLTooltip() const;
	CXWnd* GetChildItem(CXStr const &);
	CXWnd* GetChildWndAt(CXPoint*, int, int) const;
	CXWnd* GetFirstChildWnd() const;
	CXWnd* GetNextChildWnd(CXWnd*) const;
	CXWnd* GetNextSib() const;
	CXWnd* SetFocus();
	int DoAllDrawing() const;
	int DrawChildren() const;
	int DrawCloseBox() const;
	int DrawHScrollbar(int, int, int) const;
	int DrawMinimizeBox() const;
	int DrawTileBox() const;
	int DrawVScrollbar(int, int, int) const;
	int GetWidth() const;
	int Minimize(bool);
#if !defined(ROF2EMU) && !defined(UFEMU)
	int Move(CXPoint const &);
#else
	int Move(CXPoint);
#endif
	//Move (this is CXWnd__Move1_x) was checked on apr 29 2016 - eqmule
	int Move(const CXRect& rc, bool bUpdateLayout = true, bool bForceUpdateLayout = false, bool bCompleteMoveOrResize = false, bool bMoveAutoStretch = false);
	int ProcessTransition();
	int Resize(int Width, int Height, bool bUpdateLayout = true, bool bCompleteMoveOrResize = false, bool bMoveAutoStretch = false);
	int Show(bool bShow = true, bool bBringToTop = true, bool bUpdateLayout = true);
	int Tile(bool);
	static CXRect GetTooltipRect(const CXPoint&, const CXSize&);
	static CXRect GetTooltipRect(const CXRect&);
	static CXWndDrawTemplate sm_wdtDefaults;
	static int DrawColoredRect(const CXRect&, unsigned long, const CXRect&);
	static int DrawLasso(const CXRect&, unsigned long, const CXRect&);
	static int DrawRaisedRect(const CXRect&, const CXRect&);
	static int DrawSunkenRect(const CXRect&, const CXRect&);
	void Bottom();
	void BringChildWndToTop(CXWnd*);
	void BringToTop(bool bRecurse = true);
	void Center();
	void ClrFocus();
	int Destroy();
	void DrawTooltipAtPoint(CXPoint) const;
	void Left();
	void Refade();
	void Right();
	void SetFirstChildPointer(CXWnd*);
	void SetKeyTooltip(int, int);
	void SetLookLikeParent();
	void SetMouseOver(bool);
	void SetNextSibPointer(CXWnd*);
	void SetTooltip(CXStr);
	void SetXMLTooltip(CXStr);
	//void SetZLayer(int);
	void StartFade(unsigned char, uint32_t);

	// virtual
	bool IsPointTransparent(const CXPoint&) const;
	bool IsValid() const;
	bool QueryClickStickDropOK(CClickStickInfo*) const;
	bool QueryDropOK(SDragDropInfo*) const;
	CTextureAnimation* GetClickStickCursor(CClickStickInfo*) const;
	CTextureAnimation* GetCursorToDisplay() const;
	CTextureAnimation* GetDragDropCursor(SDragDropInfo*) const;
	CXRect GetClientRect() const;
	CXRect GetHitTestRect(int) const;
	CXRect GetInnerRect() const;
	CXRect GetMinimizedRect() const;
	CXSize GetMinSize() const;
	CXSize GetUntileSize() const;
	CXStr GetTooltip() const;
	int AboutToDeleteWnd(CXWnd*);
	int Draw() const;
	int DrawBackground() const;
	int DrawCaret() const;
	int DrawChildItem(CXWnd const*, void*) const;
	int DrawCursor(const CXPoint&, const CXRect&, bool &);
	int DrawNC() const;
	int DrawTitleBar(const CXRect&) const;
	int DrawTooltip(const CXWnd*) const;
	int HandleKeyboardMsg(uint32_t, uint32_t, bool);
	int HandleLButtonDown(const CXPoint&, uint32_t);
	int HandleLButtonHeld(const CXPoint&, uint32_t);
	int HandleLButtonUp(const CXPoint&, uint32_t);
	int HandleLButtonUpAfterHeld(const CXPoint&, uint32_t);
	int HandleMouseMove(const CXPoint&, uint32_t);
	int HandleRButtonDown(const CXPoint&, uint32_t);
	int HandleRButtonHeld(const CXPoint&, uint32_t);
	int HandleRButtonUp(const CXPoint&, uint32_t);
	int HandleRButtonUpAfterHeld(const CXPoint&, uint32_t);
	int HandleWheelButtonDown(const CXPoint&, uint32_t);
	int HandleWheelButtonUp(const CXPoint&, uint32_t);
	int HandleWheelMove(const CXPoint&, int, uint32_t);
	int HitTest(const CXPoint&, int*) const;
	int OnActivate(CXWnd*);
	int OnBroughtToTop();
	int OnClickStick(CClickStickInfo*, uint32_t, bool);
	int OnDragDrop(SDragDropInfo*);
	int OnHScroll(EScrollCode, int);
	int OnKillFocus(CXWnd*);
	int OnMinimizeBox();
	int OnMove(const CXRect&);
	int OnProcessFrame();
	int OnResize(int, int);
	int OnSetFocus(CXWnd*);
	int OnShow();
	int OnTile();
	int OnTileBox();
	int OnVScroll(EScrollCode, int);
	int PostDraw() const;
	//int RequestDockInfo(enum EDockAction, CXWnd*, class CXRect*);
	int SetVScrollPos(int);
	int WndNotification(CXWnd*, uint32_t, void*);
	void Deactivate();
	void OnReloadSidl();
	void SetAttributesFromSidl(CParamScreenPiece*);
	void SetDrawTemplate(CXWndDrawTemplate*);
	//void SetWindowText(const CXStr& Str);

	// protected
	static CXWndManager*& sm_pMgr;
	// private
	static unsigned char sm_byCurrentAlpha;
	int SetFont(void*);

	// -----------------------------------------------------------------------

	UIType GetType() const;
	CXMLData* GetXMLData();

	bool IsVisible() const { return dShow; }
	void SetVisible(bool bValue) { dShow = bValue; }

	void SetClickThrough(bool bValue) { bClickThrough = bValue; }

	void SetMinClientSize(const CXSize& pt) { MinClientSize = pt; }
	CXSize GetMinClientSize() const { return MinClientSize; }

	void SetMaximizable(bool bValue) { bMaximizable = bValue; }

	void* GetFont() const { return pFont; }

	void SetEscapable(bool bValue) { CloseOnESC = bValue; }
	void SetEscapableLocked(bool bValue) { bEscapableLocked = bValue; }

	CXWnd* GetParentWindow() const { return ParentWindow; }
	void SetParentWindow(CXWnd* pWnd) { ParentWindow = pWnd; };

	const CXWnd* GetFirstChildWnd() const { return GetFirstNode(); }
	CXWnd* GetFirstChildWnd() { return GetFirstNode(); }
	const CXWnd* GetNextSilingWnd() const { return GetNext(); }
	CXWnd* GetNextSilingWnd() { return GetNext(); }

	int GetVScrollMax() const { return VScrollMax; }
	int GetVScrollPos() const { return VScrollPos; }
	int GetHScrollMax() const { return HScrollMax; }
	int GetHScrollPos() const { return HScrollPos; }

	bool IsMinimized() const { return Minimized; }
	void SetMinimized(bool bValue) Minimized = bValue; }

	bool IsMouseOver() const { return MouseOver; }

	CXRect GetLocation() const { return Location; }
	void SetLocation(const CXRect& r) { Location = r; }

	CXRect GetOldLocation() { return OldLocation; }

	void SetNeedsSaving(bool bValue) { bNeedsSaving = bValue; }

	void SetClientRectChanged(bool bValue) { bClientRectChanged = bValue; }

	//void SetWindowText(const CXStr& Value) { WindowText = Value; }
	CXStr GetWindowText() const { return WindowText; }

	void SetTooltip(const CXStr& Value) { Tooltip = Value; }
	CXStr GetTooltip() const { return Tooltip; }

	COLORREF GetBGColor() const { return BGColor; }
	void SetBGColor(COLORREF Value) { BGColor = Value; }

	void SetDisabledBackground(COLORREF Value) { DisabledBackground = Value; }
	COLORREF GetDisabledBackground() const { return DisabledBackground; }

	bool IsEnabled() const { return Enabled; }
	void SetEnabled(bool bValue) { Enabled = bValue; }

	uint32_t GetWindowStyle() const { return WindowStyle; }
	void SetWindowStyle(uint32_t Value) { WindowStyle = Value; }
	void AddStyle(uint32_t Value) { WindowStyle |= Value; }
	void RemoveStyle(uint32_t Value) { WindowStyle &= ~Value; }

	void SetClipToParent(bool bValue) { bClipToParent = bValue; }
	void SetUseInLayoutHorizontal(bool bValue) { bUseInLayoutHorizontal = bValue; }
	void SetUseInLayoutVertical(bool bValue) { bUseInLayoutVertical = bValue; }

	void SetZLayer(int Value) { ZLayer = Value; }
	int GetZLayer() const { return ZLayer; }

	CXWndDrawTemplate* GetDrawTemplate() const { return DrawTemplate; }

	void SetActive(bool bValue) { bActive = bValue; }

	void SetLocked(bool bValue) { Locked = bValue; }
	bool IsLocked() const { return Locked; }

	void SetFades(bool bValue) { Fades = bValue; }
	bool GetFades() const { return Fades; }

	void SetFaded(bool bValue) { Faded = bValue; }
	bool GetFaded() const { return Faded; }

	void SetFadeDelay(int Value) { FadeDelay = Value; }
	int GetFadeDelay() const { return FadeDelay; }

	void SetBGType(uint32_t Value) { BGType = Value; }
	uint32_t GetBGType() const { return BGType; }

	void SetFadeDuration(uint32_t Value) { FadeDuration = Value; }
	uint32_t GetFadeDuration() const { return FadeDuration; }

	void SetAlpha(uint8_t Value) { Alpha = Value; }
	uint8_t GetAlpha() const { return Alpha; }

	void SetFadeToAlpha(uint8_t Value) { FadeToAlpha = Value; }
	uint8_t GetFadeToAlpha() const { return FadeToAlpha; }

	bool GetClickable() const { return Clickable; }
	void SetClickable(bool bValue) { Clickable = bValue; }

	void SetData(int64_t Value) { Data = Value; }
	int64_t GetData() const { return Data; }

	void SetClickThroughMenuItemStatus(bool bValue) { bClickThroughMenuItemStatus = bValue; }
	void SetController(void* value) { pController = value; }
	void SetShowClickThroughMenuItem(bool bValue) { bShowClickThroughMenuItem = bValue; }

	void SetBottomAnchoredToTop(bool bValue) { bBottomAnchoredToTop = bValue; }
	void SetLeftAnchoredToLeft(bool bValue) { bLeftAnchoredToLeft = bValue; }
	void SetRightAnchoredToLeft(bool bValue) { bRightAnchoredToLeft = bValue; }
	void SetTopAnchoredToTop(bool bValue) { bTopAnchoredToTop = bValue; }

	void SetTopOffset(int Value) { TopOffset = Value; }
	int GetTopOffset() const { return TopOffset; }

	void SetBottomOffset(int Value) { BottomOffset = Value; }
	int GetBottomOffset() const { return BottomOffset; }

	void SetLeftOffset(int Value) { LeftOffset = Value; }
	int GetLeftOffset() const { return LeftOffset; }

	void SetRightOffset(int Value) { RightOffset = Value; }
	int GetRightOffset() const { return RightOffset; }

	int GetXMLIndex() const { return XMLIndex; }

	template <typename T>
	void SetXMLTooltip(T&& Value) { XMLToolTip = std::forward<T>(Value); }
	CXStr GetXMLTooltip() const { return XMLToolTip; }

	void SetCRNormal(COLORREF Value) { CRNormal = Value; }

private:
	virtual void Dummy() {} // force a virtual function table
};

using CXWND = CXWnd;
using PCXWND = CXWnd*;



} // namespace eqlib

using namespace eqlib;