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

	/*0x01c*/ bool        dShow;
	/*0x01d*/ bool        bIsParentOrContextMenuWindow;
	/*0x020*/ int         VScrollPos;
	/*0x024*/ int         HScrollMax;
	/*0x028*/ bool        bKeepOnScreen;
	/*0x02c*/ uint32_t    FadeDelay;
	/*0x030*/ bool        bIsTransitioning;
	/*0x031*/ mutable bool bScreenClipRectChanged;
	/*0x032*/ bool        CloseOnESC;                          // found in CSidlScreenWnd__StoreIniInfo_x, close when ESC is pressed
	/*0x034*/ CXSize      MaxClientSize;
	/*0x03c*/ CXRect      TransitionRect;
	/*0x04c*/ bool        bMaximized;
	/*0x050*/ void*       TitlePiece2;
	/*0x054*/ uint8_t     FadeToAlpha;                         // found in CSidlScreenWnd__StoreIniInfo_x
	/*0x055*/ uint8_t     StartAlpha;
	/*0x056*/ bool        bCaptureTitle;
	/*0x057*/ bool        ValidCXWnd;                          // IsValid has this one
	/*0x058*/ int         BlinkDuration;
	/*0x05c*/ uint32_t    WindowStyle;                         // bit 1 - vertical scroll, bit 2 - horizontal scroll, bit 4 - title bar?, bit 8 - border
	/*0x060*/ bool        Minimized;
	/*0x061*/ bool        Fades;
	/*0x062*/ bool        bShowClickThroughMenuItem;           // shows/hides the click through option on the window menu
	/*0x064*/ CXWnd*      ParentWindow;                        // CXWnd__IsDescendantOf_x has this one, If this is NULL, coordinates are absolute...
	/*0x068*/ uint8_t     TargetAlpha;
	/*0x06c*/ uint32_t    BlinkFadeFreq;
	/*0x070*/ uint32_t    TransitionStartTick;
	/*0x074*/ void*       TitlePiece;
	/*0x078*/ uint32_t    TransitionDuration;
	/*0x07c*/ CLayoutStrategy* pLayoutStrategy;
	/*0x080*/ bool        bClickThrough;                       // if true you can click through the window, well it doesnt work for our chatwindow (yet) so more work is needed to figure out why
	/*0x081*/ bool        bUseInLayoutHorizontal;
	/*0x084*/ mutable CXRect ClipRectClient;
	/*0x094*/ bool        bFullyScreenClipped;
	/*0x095*/ bool        Faded;
	/*0x096*/ uint8_t     bResizableMask;
	/*0x098*/ void*       pTipTextObject;
	/*0x09c*/ void*       pTextObject;
	/*0x0a0*/ int64_t     Data;
	/*0x0a8*/ void*       pFont;
	/*0x0ac*/ CXRect      IconRect;
	/*0x0bc*/ bool        bBorder;
	/*0x0c0*/ uint32_t    FadeDuration;
	/*0x0c4*/ uint32_t    BlinkFadeDuration;
	/*0x0c8*/ int         ParentAndContextMenuArrayIndex;
	/*0x0cc*/ bool        Clickable;                           // found in CChatWindow__CChatWindow_x and the button handlers
	/*0x0d0*/ uint32_t    LastTimeMouseOver;
	/*0x0d4*/ CXStr       DataStr;
	/*0x0d8*/ int         DeleteCount;
	/*0x0dc*/ ArrayClass2_RO<unsigned int> RuntimeTypes;       // Size 0x1c
	/*0x0f4*/ CXStr       Tooltip;                             // found in CSidlManager__CreateLabel_x
	/*0x0f8*/ bool        bEscapableLocked;
	/*0x0f9*/ bool        bLeftAnchoredToLeft;
	/*0x0fa*/ bool        Locked;                              // found in CSidlScreenWnd__LoadIniInfo_x
	/*0x0fb*/ bool        bRightAnchoredToLeft;
	/*0x0fc*/ CXStr       XMLToolTip;                          // found in CSidlManager__CreateLabel_x
	/*0x100*/ bool        bBottomAnchoredToTop;
	/*0x104*/ uint32_t    BackgroundDrawType;
	/*0x108*/ int         ZLayer;                              // found in CXWndManager__DrawWindows_x
	/*0x10c*/ COLORREF    CRNormal;                            // found in OnProcessFrame
	/*0x110*/ bool        bNeedsSaving;                        // will be true if you move or resize the window
	/*0x114*/ CXWnd*      FocusProxy;
	/*0x118*/ uint8_t     Alpha;
	/*0x11c*/ COLORREF    BGColor;                             // DO NOT CHNAGE THIS TO AN ARGBCOLOR, it will break the padding since its a union that has bytes in it.
	/*0x120*/ uint32_t    BlinkFadeStartTime;
	/*0x124*/ bool        bTiled;
	/*0x128*/ int         Transition;
	/*0x12c*/ void*       IconTextureAnim;
	/*0x130*/ mutable CXRect ClientRect;
	/*0x140*/ bool        bClickThroughMenuItemStatus;         // on/off
	/*0x144*/ int         LeftOffset;
	/*0x148*/ int         BottomOffset;
	/*0x14c*/ bool        bMarkedForDelete;
	/*0x150*/ ControllerBase* pController;
	/*0x154*/ bool        bMaximizable;
	/*0x155*/ uint8_t     FadeAlpha;
	/*0x156*/ bool        bActive;
	/*0x158*/ int         BlinkState;
	/*0x15c*/ bool        bBorder2;
	/*0x160*/ mutable CXRect ClipRectScreen;
	/*0x170*/ bool        bTopAnchoredToTop;
	/*0x171*/ mutable bool bClientRectChanged;
	/*0x174*/ CXRect      OldLocation;
	/*0x184*/ bool        bAction;
	/*0x188*/ int         RightOffset;
	/*0x18c*/ int         TopOffset;
	/*0x190*/ bool        Unlockable;                          // found in CSidlScreenWnd__LoadIniInfo_x related to Locked
	/*0x194*/ CXWndDrawTemplate* DrawTemplate;
	/*0x198*/ bool        bBringToTopWhenClicked;
	/*0x19c*/ CXRect      Location;
	/*0x1ac*/ uint32_t    XMLIndex;
	/*0x1b0*/ bool        MouseOver;                           // found in CXWnd__SetMouseOver_x
	/*0x1b4*/ int         managerArrayIndex;
	/*0x1b8*/ bool        bClipToParent;
	/*0x1b9*/ bool        bHCenterTooltip;
	/*0x1bc*/ int         BlinkStartTimer;
	/*0x1c0*/ int         HScrollPos;
	/*0x1c4*/ int         VScrollMax;
	/*0x1c8*/ uint32_t    BGType;                              // found in CSidlScreenWnd__StoreIniInfo_x
	/*0x1cc*/ mutable bool bClientClipRectChanged;
	/*0x1d0*/ COLORREF    DisabledBackground;
	/*0x1d4*/ bool        bUseInLayoutVertical;
	/*0x1d8*/ CXSize      MinClientSize;
	/*0x1e0*/ CXStr       WindowText;                          // CXWnd__GetWindowTextA_x has this one
	/*0x1e4*/ bool        Enabled;
	/*0x1e8*/ uint32_t    LastBlinkFadeRefreshTime;
