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

/*0x01c*/ uint32_t    BGType;                              // found in CSidlScreenWnd__StoreIniInfo_x
/*0x020*/ CXRect      Location;
/*0x030*/ CXStr       WindowText;                          // CXWnd__GetWindowTextA_x has this one
/*0x034*/ uint32_t    BlinkFadeDuration;
/*0x038*/ bool        Clickable;                           // found in CChatWindow__CChatWindow_x and the button handlers
/*0x039*/ uint8_t     FadeToAlpha;                         // found in CSidlScreenWnd__StoreIniInfo_x
/*0x03a*/ bool        bHCenterTooltip;
/*0x03b*/ bool        Locked;                              // found in CSidlScreenWnd__LoadIniInfo_x
/*0x03c*/ bool        bBringToTopWhenClicked;
/*0x03d*/ bool        bCaptureTitle;
/*0x040*/ void*       IconTextureAnim;
/*0x044*/ void*       TitlePiece2;
/*0x048*/ bool        bNeedsSaving;                        // will be true if you move or resize the window
/*0x04c*/ uint32_t    FadeDuration;
/*0x050*/ int         DeleteCount;
/*0x054*/ mutable bool bClientRectChanged;
/*0x055*/ bool        bMaximized;
/*0x056*/ uint8_t     TargetAlpha;
/*0x058*/ int         LeftOffset;
/*0x05c*/ uint8_t     Alpha;
/*0x060*/ CXStr       Tooltip;                             // found in CSidlManager__CreateLabel_x
/*0x064*/ mutable bool bScreenClipRectChanged;
/*0x068*/ int         BottomOffset;
/*0x06c*/ uint8_t     FadeAlpha;
/*0x070*/ void*       pTipTextObject;
/*0x074*/ int         VScrollMax;
/*0x078*/ uint32_t    LastTimeMouseOver;
/*0x07c*/ bool        Faded;
/*0x080*/ int         VScrollPos;
/*0x084*/ bool        bBorder2;
/*0x085*/ bool        bActive;
/*0x088*/ int         BlinkDuration;
/*0x08c*/ bool        bIsTransitioning;
/*0x090*/ int         ParentAndContextMenuArrayIndex;
/*0x094*/ bool        Enabled;
/*0x098*/ CXRect      TransitionRect;
/*0x0a8*/ bool        bMarkedForDelete;
/*0x0ac*/ uint32_t    BlinkFadeStartTime;
/*0x0b0*/ bool        bAction;
/*0x0b1*/ bool        bClickThroughMenuItemStatus;         // on/off
/*0x0b4*/ void*       pFont;
/*0x0b8*/ bool        bIsParentOrContextMenuWindow;
/*0x0bc*/ CXSize      MaxClientSize;
/*0x0c4*/ int         ZLayer;                              // found in CXWndManager__DrawWindows_x
/*0x0c8*/ COLORREF    CRNormal;                            // found in OnProcessFrame
/*0x0cc*/ bool        bUseInLayoutHorizontal;
/*0x0cd*/ bool        bRightAnchoredToLeft;
/*0x0d0*/ uint32_t    FadeDelay;
/*0x0d4*/ bool        bEscapableLocked;
/*0x0d8*/ CXRect      OldLocation;
/*0x0e8*/ uint8_t     bResizableMask;
/*0x0e9*/ bool        bMaximizable;
/*0x0ec*/ int         BlinkState;
/*0x0f0*/ bool        dShow;
/*0x0f4*/ int         HScrollMax;
/*0x0f8*/ bool        Unlockable;                          // found in CSidlScreenWnd__LoadIniInfo_x related to Locked
/*0x0f9*/ bool        Minimized;
/*0x0fc*/ CXWnd*      FocusProxy;
/*0x100*/ bool        bShowClickThroughMenuItem;           // shows/hides the click through option on the window menu
/*0x101*/ bool        bTopAnchoredToTop;
/*0x104*/ uint32_t    XMLIndex;
/*0x108*/ ControllerBase* pController;
/*0x10c*/ void*       TitlePiece;
/*0x110*/ bool        MouseOver;                           // found in CXWnd__SetMouseOver_x
/*0x111*/ bool        Fades;
/*0x114*/ COLORREF    DisabledBackground;
/*0x118*/ bool        bBottomAnchoredToTop;
/*0x11c*/ uint32_t    LastBlinkFadeRefreshTime;
/*0x120*/ mutable CXRect ClipRectClient;
/*0x130*/ bool        bClipToParent;
/*0x134*/ void*       pTextObject;
/*0x138*/ bool        bUseInLayoutVertical;
/*0x13c*/ int         managerArrayIndex;
/*0x140*/ uint32_t    TransitionDuration;
/*0x144*/ uint8_t     StartAlpha;
/*0x145*/ bool        ValidCXWnd;                          // IsValid has this one
/*0x146*/ bool        bBorder;
/*0x148*/ CXStr       DataStr;
/*0x150*/ int64_t     Data;
/*0x158*/ CXSize      MinClientSize;
/*0x160*/ bool        bLeftAnchoredToLeft;
/*0x164*/ CXRect      IconRect;
/*0x174*/ mutable CXRect ClipRectScreen;
/*0x184*/ int         BlinkStartTimer;
/*0x188*/ bool        bFullyScreenClipped;
/*0x18c*/ int         Transition;
/*0x190*/ mutable CXRect ClientRect;
/*0x1a0*/ int         TopOffset;
/*0x1a4*/ bool        bTiled;
/*0x1a5*/ mutable bool bClientClipRectChanged;
/*0x1a6*/ bool        bClickThrough;                       // if true you can click through the window, well it doesnt work for our chatwindow (yet) so more work is needed to figure out why
/*0x1a8*/ uint32_t    BlinkFadeFreq;
/*0x1ac*/ int         HScrollPos;
/*0x1b0*/ uint32_t    WindowStyle;                         // bit 1 - vertical scroll, bit 2 - horizontal scroll, bit 4 - title bar?, bit 8 - border
/*0x1b4*/ uint32_t    TransitionStartTick;
/*0x1b8*/ bool        CloseOnESC;                          // found in CSidlScreenWnd__StoreIniInfo_x, close when ESC is pressed
/*0x1bc*/ COLORREF    BGColor;                             // DO NOT CHNAGE THIS TO AN ARGBCOLOR, it will break the padding since its a union that has bytes in it.
/*0x1c0*/ CXStr       XMLToolTip;                          // found in CSidlManager__CreateLabel_x
/*0x1c4*/ CLayoutStrategy* pLayoutStrategy;
/*0x1c8*/ CXWndDrawTemplate* DrawTemplate;
/*0x1cc*/ CXWnd*      ParentWindow;                        // CXWnd__IsDescendantOf_x has this one, If this is NULL, coordinates are absolute...
/*0x1d0*/ bool        bKeepOnScreen;
/*0x1d4*/ ArrayClass2_RO<UINT> RuntimeTypes;               // Size 0x1c
/*0x1f0*/ int         RightOffset;
/*0x1f4*/ uint32_t    BackgroundDrawType;
