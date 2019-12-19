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

/*0x01c*/ bool        bMaximizable;
/*0x01d*/ bool        bUseInLayoutHorizontal;
/*0x01e*/ bool        bBringToTopWhenClicked;
/*0x01f*/ bool        bTiled;
/*0x020*/ uint32_t    TransitionDuration;
/*0x024*/ uint8_t     StartAlpha;
/*0x028*/ int         VScrollPos;
/*0x02c*/ bool        bBorder2;
/*0x02d*/ bool        bEscapableLocked;
/*0x030*/ CXRect      IconRect;
/*0x040*/ ArrayClass2_RO<unsigned int> RuntimeTypes;       // Size 0x1c
/*0x058*/ bool        bMarkedForDelete;
/*0x05c*/ int         BlinkDuration;
/*0x060*/ void*       TitlePiece2;
/*0x064*/ uint32_t    LastBlinkFadeRefreshTime;
/*0x068*/ bool        bMaximized;
/*0x069*/ uint8_t     bResizableMask;
/*0x06a*/ bool        Enabled;
/*0x06b*/ bool        bAction;
/*0x06c*/ int         managerArrayIndex;
/*0x070*/ uint32_t    TransitionStartTick;
/*0x074*/ void*       pTipTextObject;
/*0x078*/ int         BlinkState;
/*0x07c*/ mutable CXRect ClientRect;
/*0x08c*/ bool        bShowClickThroughMenuItem;           // shows/hides the click through option on the window menu
/*0x090*/ uint32_t    BackgroundDrawType;
/*0x094*/ CXStr       XMLToolTip;                          // found in CSidlManager__CreateLabel_x
/*0x098*/ bool        bCaptureTitle;
/*0x09c*/ int         Transition;
/*0x0a0*/ bool        CloseOnESC;                          // found in CSidlScreenWnd__StoreIniInfo_x, close when ESC is pressed
/*0x0a1*/ bool        ValidCXWnd;                          // IsValid has this one
/*0x0a4*/ int         TopOffset;
/*0x0a8*/ bool        Locked;                              // found in CSidlScreenWnd__LoadIniInfo_x
/*0x0ac*/ int         HScrollPos;
/*0x0b0*/ CXRect      OldLocation;
/*0x0c0*/ uint32_t    BlinkFadeDuration;
/*0x0c4*/ uint32_t    FadeDelay;
/*0x0c8*/ CXRect      TransitionRect;
/*0x0d8*/ CLayoutStrategy* pLayoutStrategy;
/*0x0dc*/ bool        bRightAnchoredToLeft;
/*0x0e0*/ int         LeftOffset;
/*0x0e4*/ bool        bNeedsSaving;                        // will be true if you move or resize the window
/*0x0e5*/ bool        bBottomAnchoredToTop;
/*0x0e8*/ COLORREF    BGColor;                             // DO NOT CHNAGE THIS TO AN ARGBCOLOR, it will break the padding since its a union that has bytes in it.
/*0x0ec*/ uint32_t    BlinkFadeFreq;
/*0x0f0*/ CXSize      MaxClientSize;
/*0x0f8*/ mutable bool bClientRectChanged;
/*0x0fc*/ CXWnd*      FocusProxy;
/*0x100*/ uint32_t    BGType;                              // found in CSidlScreenWnd__StoreIniInfo_x
/*0x104*/ COLORREF    CRNormal;                            // found in OnProcessFrame
/*0x108*/ uint8_t     Alpha;
/*0x109*/ bool        bFullyScreenClipped;
/*0x10a*/ bool        bBorder;
/*0x10c*/ CXWndDrawTemplate* DrawTemplate;
/*0x110*/ bool        bClipToParent;
/*0x114*/ CXSize      MinClientSize;
/*0x11c*/ void*       pTextObject;
/*0x120*/ bool        bHCenterTooltip;
/*0x121*/ bool        bIsParentOrContextMenuWindow;
/*0x124*/ int         ParentAndContextMenuArrayIndex;
/*0x128*/ ControllerBase* pController;
/*0x12c*/ bool        Clickable;                           // found in CChatWindow__CChatWindow_x and the button handlers
/*0x12d*/ bool        bClickThroughMenuItemStatus;         // on/off
/*0x130*/ CXWnd*      ParentWindow;                        // CXWnd__IsDescendantOf_x has this one, If this is NULL, coordinates are absolute...
/*0x134*/ int         BlinkStartTimer;
/*0x138*/ int         DeleteCount;
/*0x13c*/ bool        bActive;
/*0x140*/ uint32_t    XMLIndex;
/*0x144*/ void*       pFont;
/*0x148*/ int         BottomOffset;
/*0x14c*/ bool        Faded;
/*0x150*/ uint32_t    BlinkFadeStartTime;
/*0x154*/ uint32_t    WindowStyle;                         // bit 1 - vertical scroll, bit 2 - horizontal scroll, bit 4 - title bar?, bit 8 - border
/*0x158*/ bool        MouseOver;                           // found in CXWnd__SetMouseOver_x
/*0x159*/ bool        Unlockable;                          // found in CSidlScreenWnd__LoadIniInfo_x related to Locked
/*0x15c*/ CXStr       WindowText;                          // CXWnd__GetWindowTextA_x has this one
/*0x160*/ bool        bClickThrough;                       // if true you can click through the window, well it doesnt work for our chatwindow (yet) so more work is needed to figure out why
/*0x161*/ bool        bLeftAnchoredToLeft;
/*0x164*/ int         HScrollMax;
/*0x168*/ void*       IconTextureAnim;
/*0x16c*/ mutable bool bScreenClipRectChanged;
/*0x16d*/ uint8_t     FadeAlpha;
/*0x170*/ mutable CXRect ClipRectClient;
/*0x180*/ void*       TitlePiece;
/*0x184*/ uint8_t     TargetAlpha;
/*0x188*/ int64_t     Data;
/*0x190*/ uint8_t     FadeToAlpha;                         // found in CSidlScreenWnd__StoreIniInfo_x
/*0x194*/ CXStr       Tooltip;                             // found in CSidlManager__CreateLabel_x
/*0x198*/ mutable bool bClientClipRectChanged;
/*0x19c*/ COLORREF    DisabledBackground;
/*0x1a0*/ CXRect      Location;
/*0x1b0*/ CXStr       DataStr;
/*0x1b4*/ mutable CXRect ClipRectScreen;
/*0x1c4*/ bool        dShow;
/*0x1c5*/ bool        bIsTransitioning;
/*0x1c8*/ int         ZLayer;                              // found in CXWndManager__DrawWindows_x
/*0x1cc*/ bool        Fades;
/*0x1cd*/ bool        bUseInLayoutVertical;
/*0x1d0*/ uint32_t    FadeDuration;
/*0x1d4*/ int         VScrollMax;
/*0x1d8*/ bool        Minimized;
/*0x1dc*/ uint32_t    LastTimeMouseOver;
/*0x1e0*/ bool        bTopAnchoredToTop;
/*0x1e4*/ int         RightOffset;
/*0x1e8*/ bool        bKeepOnScreen;
