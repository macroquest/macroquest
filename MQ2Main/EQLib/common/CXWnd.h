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

// Message types for WndNotifications
#define XWM_LCLICK              1
#define XWM_LMOUSEUP            2
#define XWM_RCLICK              3
#define XWM_LDBLCLICK           4
#define XWM_HITENTER            6
#define XWM_CLOSE               10
#define XWN_TOOLTIP             12
#define XWM_NEWVALUE            14
#define XWM_COLUMNCLICK         15
#define XWM_SORTREQUEST         16
#define XWM_IS_LINK_ACTIVE      19
#define XWM_MENUSELECT          20
#define XWM_MOUSEOVER           21
#define XWM_HISTORY             22
#define XWM_LCLICKHOLD          23
#define XWM_LINK                27
#define XWM_MAXIMIZEBOX         29
#define XWM_ACHIEVEMENTLINK     31
	//not sure what 32 is now, they inserted a new message smack in the middle instead of adding it to the end
	//i think its achievement related. -eqmule
#if !defined(ROF2EMU) && !defined(UFEMU)
#define XWN_DIALOGRESPONSELINK  33
#define XWM_FOCUS               35
#define XWM_LOSTFOCUS           36
#define XWM_TEXTENTRY_COMPLETE  41
#define XWM_RSELITEM_DOWN       47
#define XWN_OUTPUT_TEXT         49
#define XWN_COMMANDLINK         50
//ok so here we have 2 new messages 51 and 52 see https://forums.daybreakgames.com/eq/index.php?threads/game-update-notes-july-19-2017.242705/
//I think they where added in that patch
//they are dynamiczone/raid related or something
//need to investigate further to know for sure -eqmule
#else
#define XWN_DIALOGRESPONSELINK  32
#define XWM_FOCUS               33
#define XWM_LOSTFOCUS           34
#define XWM_TEXTENTRY_COMPLETE  40
#define XWM_RSELITEM_DOWN       46
#define XWN_OUTPUT_TEXT         48
#define XWN_COMMANDLINK         49
#endif


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

using EScrollCode = uint32_t;
using EDockAction = uint32_t;

struct SDragDropInfo
{
	bool       m_rightMouse;
	CXWnd*     sourceWnd;
	CXWnd*     targetWnd;
	CXPoint    sourcePos;
	CXPoint    targetPos;
	int        message;
	uintptr_t  data;
};

class CClickStickInfo;

// "Controller" helper class
class ControllerBase
{
public:
	virtual ~ControllerBase() {}
	virtual void* Unknown0x04(CXStr& unknown1, int unknown2) { return nullptr; }
	virtual void Unknown0x08() {}
	virtual bool AboutToShow() { return true; }
	virtual bool AboutToHide() { return true; }
	virtual void WndNotification(CXWnd* sender, uint32_t message, void* data) {}
	virtual void Unknown0x14(uint32_t) = 0;
	virtual void Unknown0x18(const CXStr&) {}
};

class CLayoutStrategy
{
public:
	~CLayoutStrategy() {}
	virtual bool LayoutChildren(CXWnd* wnd) {}
};

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

	EQLIB_OBJECT CXWnd(CXWnd* parent, uint32_t, CXRect);

	//----------------------------------------------------------------------------
	EQLIB_OBJECT virtual bool IsValid() const;
	EQLIB_OBJECT virtual ~CXWnd();
	EQLIB_OBJECT virtual int DrawNC() const;
	EQLIB_OBJECT virtual int Draw();
	EQLIB_OBJECT virtual int PostDraw();
	EQLIB_OBJECT virtual int DrawCursor(const CXPoint& mousePos, const CXRect& clip, bool& drawn);
	EQLIB_OBJECT virtual int DrawChildItem(const CXWnd* child, void* item) const;
	EQLIB_OBJECT virtual int DrawCaret() const;
	EQLIB_OBJECT virtual int DrawBackground() const;
	EQLIB_OBJECT virtual int DrawTooltip(const CXWnd* wnd) const;
	EQLIB_OBJECT virtual int DrawTooltipAtPoint(const CXPoint& pos, const CXStr& tooltip = {}) const;
	EQLIB_OBJECT virtual CXRect GetMinimizedRect() const;
	EQLIB_OBJECT virtual int DrawTitleBar(const CXRect& rect) const;
	EQLIB_OBJECT virtual HCURSOR GetCursorToDisplay() const;
	EQLIB_OBJECT virtual int HandleLButtonDown(const CXPoint& pos, uint32_t flags);
	EQLIB_OBJECT virtual int HandleLButtonUp(const CXPoint& pos, uint32_t flags);
	EQLIB_OBJECT virtual int HandleLButtonHeld(const CXPoint& pos, uint32_t flags);
	EQLIB_OBJECT virtual int HandleLButtonUpAfterHeld(const CXPoint& pos, uint32_t flags);
	EQLIB_OBJECT virtual int HandleRButtonDown(const CXPoint& pos, uint32_t flags);
	EQLIB_OBJECT virtual int HandleRButtonUp(const CXPoint& pos, uint32_t flags);
	EQLIB_OBJECT virtual int HandleRButtonHeld(const CXPoint& pos, uint32_t flags);
	EQLIB_OBJECT virtual int HandleRButtonUpAfterHeld(const CXPoint& pos, uint32_t flags);
	EQLIB_OBJECT virtual int HandleWheelButtonDown(const CXPoint& pos, uint32_t flags);
	EQLIB_OBJECT virtual int HandleWheelButtonUp(const CXPoint& pos, uint32_t flags);
	EQLIB_OBJECT virtual int HandleMouseMove(const CXPoint& pos, uint32_t flags);
	EQLIB_OBJECT virtual int HandleWheelMove(const CXPoint& pos, int scroll, uint32_t flags);
	EQLIB_OBJECT virtual int HandleKeyboardMsg(uint32_t message, uint32_t flags, bool down);
	EQLIB_OBJECT virtual int HandleMouseLeave();
	EQLIB_OBJECT virtual int OnDragDrop(SDragDropInfo* info);
	EQLIB_OBJECT virtual HCURSOR GetDragDropCursor(SDragDropInfo* info) const;
	EQLIB_OBJECT virtual bool QueryDropOK(SDragDropInfo* info) const;
	EQLIB_OBJECT virtual int OnClickStick(CClickStickInfo* info, uint32_t flags, bool unk);
	EQLIB_OBJECT virtual HCURSOR GetClickStickCursor(CClickStickInfo* info) const;
	EQLIB_OBJECT virtual bool QueryClickStickDropOK(CClickStickInfo* info) const;
	EQLIB_OBJECT virtual int WndNotification(CXWnd* sender, uint32_t message, void* data);
	EQLIB_OBJECT virtual void OnWndNotification();
	EQLIB_OBJECT virtual void Activate();
	EQLIB_OBJECT virtual void Deactivate();
	EQLIB_OBJECT bool IsActive() const { return bActive; }
	EQLIB_OBJECT virtual int OnShow();
	EQLIB_OBJECT virtual int OnMove(const CXRect& rect);
	EQLIB_OBJECT virtual int OnResize(int w, int h);
	EQLIB_OBJECT virtual int OnBeginMoveOrResize();
	EQLIB_OBJECT virtual int OnCompleteMoveOrResize();
	EQLIB_OBJECT virtual int OnMinimizeBox();
	EQLIB_OBJECT bool IsMinimized() const { return Minimized; }
	EQLIB_OBJECT void SetMinimized(bool bValue) { Minimized = bValue; }
	EQLIB_OBJECT virtual int OnMaximizeBox();
	EQLIB_OBJECT bool IsMaximized() const { return bMaximized; }
	EQLIB_OBJECT virtual int OnTileBox(); // needs impl
	EQLIB_OBJECT bool IsTiled() const { return bTiled; }
	EQLIB_OBJECT virtual int OnTile();
	EQLIB_OBJECT virtual int OnSetFocus(CXWnd* old);
	EQLIB_OBJECT virtual int OnKillFocus(CXWnd* old);
	EQLIB_OBJECT virtual int OnProcessFrame();
	EQLIB_OBJECT virtual int OnVScroll(EScrollCode code, int pos);
	EQLIB_OBJECT virtual int OnHScroll(EScrollCode code, int pos);
	EQLIB_OBJECT virtual int OnBroughtToTop();
	EQLIB_OBJECT virtual int OnActivate(CXWnd* old) { return 0; }
	EQLIB_OBJECT virtual int Show(bool show = true, bool bringToTop = true, bool updateLayout = true);
	EQLIB_OBJECT virtual bool AboutToShow();
	EQLIB_OBJECT virtual bool AboutToHide();
	EQLIB_OBJECT virtual int RequestDockInfo(EDockAction action, CXWnd* wnd, CXRect* rect);
	EQLIB_OBJECT virtual CXStr GetTooltip() const { return Tooltip; }
	EQLIB_OBJECT void SetTooltip(const CXStr& Value) { Tooltip = Value; }
	EQLIB_OBJECT virtual void Unknown0x0EC();
	EQLIB_OBJECT virtual int HitTest(const CXPoint& pos, int* result) const;
	EQLIB_OBJECT virtual CXRect GetHitTestRect(int code) const;
	EQLIB_OBJECT virtual CXRect GetInnerRect() const;
	EQLIB_OBJECT virtual CXRect GetClientRect() const;
	EQLIB_OBJECT virtual CXRect GetClientClipRect() const;
	EQLIB_OBJECT virtual CXSize GetMinSize(bool withBorder = true) const;
	EQLIB_OBJECT virtual CXSize GetMaxSize(bool withBorder = true) const;
	EQLIB_OBJECT virtual CXSize GetUntileSize() const { return Location.GetSize(); }
	EQLIB_OBJECT virtual bool IsPointTransparent(const CXPoint& point) const { return false; }
	EQLIB_OBJECT virtual bool Unknown0x114() const { return IsVisible() && !IsMinimized(); }
	EQLIB_OBJECT virtual bool ControllerShouldProcessFrame() const { return IsVisible() && !IsMinimized(); }
	EQLIB_OBJECT virtual void SetDrawTemplate(CXWndDrawTemplate* drawTemplate) { DrawTemplate = drawTemplate; }
	EQLIB_OBJECT virtual int Move(const CXRect& rect, bool updateLayout = true, bool forceUpdateLayout = false,
		bool completeMoveOrResize = false, bool moveAutoStretch = false);
	EQLIB_OBJECT virtual int Move(const CXPoint& point);
	EQLIB_OBJECT virtual void SetWindowText(const CXStr& text) { WindowText = text; }
	EQLIB_OBJECT CXStr GetWindowText() const { return WindowText; }
	EQLIB_OBJECT virtual CXWnd* GetChildWndAt(const CXPoint& pos, bool, bool) const;
	EQLIB_OBJECT virtual CScreenPieceTemplate* GetSidlPiece(const CXStr& screenId, bool top = true) const;
	EQLIB_OBJECT virtual const CXStr* GetWindowName() const { return nullptr; }
	EQLIB_OBJECT virtual int SetVScrollPos(int pos);
	EQLIB_OBJECT virtual int SetHScrollPos(int pos);
	EQLIB_OBJECT virtual int AutoSetVScrollPos(CXRect rect);
	EQLIB_OBJECT virtual int AutoSetHScrollPos(CXRect rect);
	EQLIB_OBJECT virtual void SetAttributesFromSidl(CParamScreenPiece* screenPiece);
	EQLIB_OBJECT virtual void OnReloadSidl() {}
	EQLIB_OBJECT virtual bool Unknown0x150() { return false;  }
	EQLIB_OBJECT virtual void Unknown0x154(bool) {}
	EQLIB_OBJECT virtual const CXSize& GetMinClientSize() const { return MinClientSize; }
	EQLIB_OBJECT void SetMinClientSize(const CXSize& pt) { MinClientSize = pt; }
	EQLIB_OBJECT virtual const CXSize& GetMaxClientSize() const { return MaxClientSize; }
	EQLIB_OBJECT virtual void* Unknown0x160() const { return nullptr; }
	EQLIB_OBJECT virtual void UpdateLayout(bool finish = false);


	void SetClientRectDirty(bool dirty);
	bool IsClientRectDirty() const { return bClientRectChanged; }
	bool IsClientClipRectDirty() const { return bClientClipRectChanged; }
	bool IsScreenClipRectDirty() const { return bScreenClipRectChanged; }

public:
	EQLIB_OBJECT CXWnd* SetParent(CXWnd*);
	EQLIB_OBJECT CXWnd* GetChildItem(CXStr Name);

	EQLIB_OBJECT bool HasFocus() const;
	EQLIB_OBJECT bool IsDescendantOf(CXWnd const*) const;
	EQLIB_OBJECT bool IsReallyVisible() const;
	EQLIB_OBJECT bool IsType(EWndRuntimeType eType) const;
	EQLIB_OBJECT const CButtonDrawTemplate* GetCloseBoxTemplate() const;
	EQLIB_OBJECT const CButtonDrawTemplate* GetMinimizeBoxTemplate() const;
	EQLIB_OBJECT const CButtonDrawTemplate* GetTileBoxTemplate() const;
	EQLIB_OBJECT const CTAFrameDraw* GetBorderFrame() const;
	EQLIB_OBJECT const CTAFrameDraw* GetTitlebarHeader() const;
	EQLIB_OBJECT CXRect GetRelativeRect() const;
	EQLIB_OBJECT CXRect GetScreenClipRect() const;
	EQLIB_OBJECT CXRect GetScreenRect() const;
	EQLIB_OBJECT CXWnd* GetChildItem(CXStr const &);
	EQLIB_OBJECT CXWnd* GetChildWndAt(CXPoint*, int, int) const;
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

	EQLIB_OBJECT int ProcessTransition();
	EQLIB_OBJECT int Resize(int Width, int Height, bool bUpdateLayout = true, bool bCompleteMoveOrResize = false, bool bMoveAutoStretch = false);
	EQLIB_OBJECT void Bottom();
	EQLIB_OBJECT void BringChildWndToTop(CXWnd*);
	EQLIB_OBJECT void BringToTop(bool bRecurse = true);
	EQLIB_OBJECT void Center();
	EQLIB_OBJECT void ClrFocus();
	EQLIB_OBJECT int Destroy();
	EQLIB_OBJECT void Left();
	EQLIB_OBJECT void Refade();
	EQLIB_OBJECT void Right();
	EQLIB_OBJECT void SetFirstChildPointer(CXWnd*);
	EQLIB_OBJECT void SetKeyTooltip(int, int);
	EQLIB_OBJECT void SetLookLikeParent();
	EQLIB_OBJECT void SetMouseOver(bool);
	EQLIB_OBJECT void SetNextSibPointer(CXWnd*);
	EQLIB_OBJECT void StartFade(unsigned char, uint32_t);

	// private
	EQLIB_OBJECT int SetFont(void*);

	// -----------------------------------------------------------------------

	EQLIB_OBJECT UIType GetType() const;
	EQLIB_OBJECT CXMLData* GetXMLData() const;

	EQLIB_OBJECT bool IsVisible() const { return dShow; }
	EQLIB_OBJECT void SetVisible(bool bValue) { dShow = bValue; }

	EQLIB_OBJECT void SetClickThrough(bool bValue) { bClickThrough = bValue; }

	EQLIB_OBJECT void SetMaximizable(bool bValue) { bMaximizable = bValue; }

	EQLIB_OBJECT void* GetFont() const { return pFont; }

	EQLIB_OBJECT void SetEscapable(bool bValue) { CloseOnESC = bValue; }
	EQLIB_OBJECT void SetEscapableLocked(bool bValue) { bEscapableLocked = bValue; }

	EQLIB_OBJECT CXWnd* GetParentWindow() const { return ParentWindow; }
	EQLIB_OBJECT CXWnd* GetParent() const { return ParentWindow; }
	EQLIB_OBJECT void SetParentWindow(CXWnd* pWnd) { ParentWindow = pWnd; };

	EQLIB_OBJECT const CXWnd* GetFirstChildWnd() const { return GetFirstNode(); }
	EQLIB_OBJECT CXWnd* GetFirstChildWnd() { return GetFirstNode(); }
	EQLIB_OBJECT const CXWnd* GetNextSiblingWnd() const { return GetNext(); }
	EQLIB_OBJECT CXWnd* GetNextSiblingWnd() { return GetNext(); }

	EQLIB_OBJECT int GetVScrollMax() const { return VScrollMax; }
	EQLIB_OBJECT int GetVScrollPos() const { return VScrollPos; }
	EQLIB_OBJECT int GetHScrollMax() const { return HScrollMax; }
	EQLIB_OBJECT int GetHScrollPos() const { return HScrollPos; }

	EQLIB_OBJECT bool IsMouseOver() const { return MouseOver; }

	EQLIB_OBJECT CXRect GetLocation() const { return Location; }
	EQLIB_OBJECT void SetLocation(const CXRect& r) { Location = r; }

	EQLIB_OBJECT CXRect GetOldLocation() { return OldLocation; }

	EQLIB_OBJECT void SetNeedsSaving(bool bValue) { bNeedsSaving = bValue; }

	EQLIB_OBJECT void SetClientRectChanged(bool bValue) { bClientRectChanged = bValue; }

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

	EQLIB_OBJECT void SetXMLTooltip(const CXStr& Value) { XMLToolTip = Value; }
	EQLIB_OBJECT CXStr GetXMLTooltip() const { return XMLToolTip; }

	EQLIB_OBJECT void SetCRNormal(COLORREF Value) { CRNormal = Value; }

private:
	int Maximize(bool) { return 0; }
	void Tile(bool) {}
	int SendNotificationToParent(CXWnd* sender, uint32_t message, void* data);
};

using CXWND = CXWnd;
using PCXWND = CXWnd*;

} // namespace eqlib

using namespace eqlib;
