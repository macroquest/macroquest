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

/*0x01c*/ void*       IconTextureAnim;
/*0x020*/ int         TopOffset;
/*0x024*/ bool        Fades;
/*0x028*/ int64_t     Data;
/*0x030*/ void*       pTextObject;
/*0x034*/ uint8_t     FadeToAlpha;                         // found in CSidlScreenWnd__StoreIniInfo_x
/*0x035*/ bool        bHCenterTooltip;
/*0x036*/ uint8_t     Alpha;
/*0x038*/ int         VScrollPos;
/*0x03c*/ uint8_t     bResizableMask;
/*0x040*/ uint32_t    WindowStyle;                         // bit 1 - vertical scroll, bit 2 - horizontal scroll, bit 4 - title bar?, bit 8 - border
/*0x044*/ CXRect      Location;
/*0x054*/ ArrayClass2_RO<unsigned int> RuntimeTypes;       // Size 0x1c
/*0x06c*/ bool        bMaximized;
/*0x06d*/ bool        bIsTransitioning;
/*0x070*/ CXWnd*      ParentWindow;                        // CXWnd__IsDescendantOf_x has this one, If this is NULL, coordinates are absolute...
/*0x074*/ CXStr       XMLToolTip;                          // found in CSidlManager__CreateLabel_x
/*0x078*/ bool        bTopAnchoredToTop;
/*0x079*/ uint8_t     StartAlpha;
/*0x07a*/ bool        bClickThrough;                       // if true you can click through the window, well it doesnt work for our chatwindow (yet) so more work is needed to figure out why
/*0x07c*/ CXRect      OldLocation;
/*0x08c*/ int         BlinkDuration;
/*0x090*/ bool        bClickThroughMenuItemStatus;         // on/off
/*0x094*/ uint32_t    TransitionStartTick;
/*0x098*/ bool        bBottomAnchoredToTop;
/*0x099*/ bool        bBorder;
/*0x09a*/ bool        bShowClickThroughMenuItem;           // shows/hides the click through option on the window menu
/*0x09b*/ mutable bool bClientClipRectChanged;
/*0x09c*/ bool        bMaximizable;
/*0x0a0*/ int         Transition;
/*0x0a4*/ void*       pFont;
/*0x0a8*/ mutable bool bScreenClipRectChanged;
/*0x0a9*/ bool        bFullyScreenClipped;
/*0x0aa*/ bool        Locked;                              // found in CSidlScreenWnd__LoadIniInfo_x
/*0x0ab*/ bool        bUseInLayoutVertical;
/*0x0ac*/ uint32_t    BlinkFadeStartTime;
/*0x0b0*/ bool        dShow;
/*0x0b4*/ mutable CXRect ClientRect;
/*0x0c4*/ uint32_t    FadeDuration;
/*0x0c8*/ bool        bTiled;
/*0x0cc*/ CXWnd*      FocusProxy;
/*0x0d0*/ bool        bBringToTopWhenClicked;
/*0x0d1*/ bool        bRightAnchoredToLeft;
/*0x0d4*/ CXWndDrawTemplate* DrawTemplate;
/*0x0d8*/ uint8_t     TargetAlpha;
/*0x0d9*/ bool        CloseOnESC;                          // found in CSidlScreenWnd__StoreIniInfo_x, close when ESC is pressed
/*0x0da*/ bool        ValidCXWnd;                          // IsValid has this one
/*0x0dc*/ CXSize      MinClientSize;
/*0x0e4*/ int         BlinkStartTimer;
/*0x0e8*/ int         BottomOffset;
/*0x0ec*/ int         managerArrayIndex;
/*0x0f0*/ bool        Enabled;
/*0x0f4*/ int         HScrollMax;
/*0x0f8*/ mutable bool bClientRectChanged;
/*0x0f9*/ uint8_t     FadeAlpha;
/*0x0fa*/ bool        bLeftAnchoredToLeft;
/*0x0fc*/ uint32_t    TransitionDuration;
/*0x100*/ COLORREF    BGColor;                             // DO NOT CHNAGE THIS TO AN ARGBCOLOR, it will break the padding since its a union that has bytes in it.
/*0x104*/ uint32_t    LastTimeMouseOver;
/*0x108*/ int         BlinkState;
/*0x10c*/ bool        bIsParentOrContextMenuWindow;
/*0x110*/ CXStr       DataStr;
/*0x114*/ COLORREF    DisabledBackground;
/*0x118*/ int         VScrollMax;
/*0x11c*/ int         ParentAndContextMenuArrayIndex;
/*0x120*/ bool        bMarkedForDelete;
/*0x124*/ uint32_t    BlinkFadeDuration;
/*0x128*/ uint32_t    FadeDelay;
/*0x12c*/ bool        bCaptureTitle;
/*0x130*/ uint32_t    BackgroundDrawType;
/*0x134*/ mutable CXRect ClipRectScreen;
/*0x144*/ void*       pTipTextObject;
/*0x148*/ bool        bActive;
/*0x14c*/ void*       TitlePiece2;
/*0x150*/ uint32_t    LastBlinkFadeRefreshTime;
/*0x154*/ CXStr       Tooltip;                             // found in CSidlManager__CreateLabel_x
/*0x158*/ bool        bEscapableLocked;
/*0x159*/ bool        bClipToParent;
/*0x15a*/ bool        Unlockable;                          // found in CSidlScreenWnd__LoadIniInfo_x related to Locked
/*0x15b*/ bool        bNeedsSaving;                        // will be true if you move or resize the window
/*0x15c*/ CXRect      IconRect;
/*0x16c*/ CXStr       WindowText;                          // CXWnd__GetWindowTextA_x has this one
/*0x170*/ CXRect      TransitionRect;
/*0x180*/ COLORREF    CRNormal;                            // found in OnProcessFrame
/*0x184*/ int         HScrollPos;
/*0x188*/ bool        Minimized;
/*0x189*/ bool        Clickable;                           // found in CChatWindow__CChatWindow_x and the button handlers
/*0x18c*/ CLayoutStrategy* pLayoutStrategy;
/*0x190*/ void*       TitlePiece;
/*0x194*/ bool        bKeepOnScreen;
/*0x195*/ bool        bAction;
/*0x198*/ CXSize      MaxClientSize;
/*0x1a0*/ int         RightOffset;
/*0x1a4*/ int         DeleteCount;
/*0x1a8*/ uint32_t    BGType;                              // found in CSidlScreenWnd__StoreIniInfo_x
/*0x1ac*/ int         LeftOffset;
/*0x1b0*/ ControllerBase* pController;
/*0x1b4*/ bool        MouseOver;                           // found in CXWnd__SetMouseOver_x
/*0x1b8*/ int         ZLayer;                              // found in CXWndManager__DrawWindows_x
/*0x1bc*/ mutable CXRect ClipRectClient;
/*0x1cc*/ uint32_t    BlinkFadeFreq;
/*0x1d0*/ uint32_t    XMLIndex;
/*0x1d4*/ bool        bBorder2;
/*0x1d5*/ bool        bUseInLayoutHorizontal;
/*0x1d6*/ bool        Faded;
