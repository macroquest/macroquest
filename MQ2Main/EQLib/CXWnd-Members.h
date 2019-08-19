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

/*0x01c*/ bool        bClickThroughMenuItemStatus;         // on/off
/*0x020*/ uint32_t    BlinkFadeDuration;
/*0x024*/ int         ZLayer;                              // found in CXWndManager__DrawWindows_x
/*0x028*/ COLORREF    BGColor;                             // DO NOT CHNAGE THIS TO AN ARGBCOLOR, it will break the padding since its a union that has bytes in it.
/*0x02c*/ bool        bLeftAnchoredToLeft;
/*0x02d*/ uint8_t     FadeToAlpha;                         // found in CSidlScreenWnd__StoreIniInfo_x
/*0x030*/ int         VScrollPos;
/*0x034*/ bool        bIsTransitioning;
/*0x038*/ CXWnd*      ParentWindow;                        // CXWnd__IsDescendantOf_x has this one, If this is NULL, coordinates are absolute...
/*0x03c*/ uint32_t    FadeDelay;
/*0x040*/ bool        bBottomAnchoredToTop;
/*0x041*/ uint8_t     bResizableMask;
/*0x042*/ bool        bBorder2;
/*0x044*/ CXStr       WindowText;                          // CXWnd__GetWindowTextA_x has this one
/*0x048*/ bool        Enabled;
/*0x049*/ bool        bMaximizable;
/*0x04c*/ uint32_t    LastTimeMouseOver;
/*0x050*/ bool        Minimized;
/*0x051*/ uint8_t     StartAlpha;
/*0x054*/ mutable CXRect ClientRect;
/*0x064*/ bool        bHCenterTooltip;
/*0x065*/ bool        bEscapableLocked;
/*0x068*/ int         BlinkState;
/*0x06c*/ int         BlinkStartTimer;
/*0x070*/ uint32_t    BGType;                              // found in CSidlScreenWnd__StoreIniInfo_x
/*0x074*/ bool        bCaptureTitle;
/*0x075*/ mutable bool bClientRectChanged;
/*0x078*/ int         Transition;
/*0x07c*/ int         TopOffset;
/*0x080*/ bool        bActive;
/*0x081*/ bool        bTiled;
/*0x082*/ bool        bNeedsSaving;                        // will be true if you move or resize the window
/*0x083*/ uint8_t     TargetAlpha;
/*0x084*/ uint32_t    BlinkFadeFreq;
/*0x088*/ bool        bBringToTopWhenClicked;
/*0x08c*/ int         DeleteCount;
/*0x090*/ void*       pFont;
/*0x094*/ bool        Locked;                              // found in CSidlScreenWnd__LoadIniInfo_x
/*0x095*/ bool        Faded;
/*0x098*/ mutable CXRect ClipRectClient;
/*0x0a8*/ ArrayClass2_RO<unsigned int> RuntimeTypes;       // Size 0x1c
/*0x0c8*/ int64_t     Data;
/*0x0d0*/ CXRect      OldLocation;
/*0x0e0*/ uint32_t    BackgroundDrawType;
/*0x0e4*/ CXSize      MaxClientSize;
/*0x0ec*/ int         ParentAndContextMenuArrayIndex;
/*0x0f0*/ CXRect      Location;
/*0x100*/ mutable CXRect ClipRectScreen;
/*0x110*/ CLayoutStrategy* pLayoutStrategy;
/*0x114*/ int         managerArrayIndex;
/*0x118*/ bool        bClickThrough;                       // if true you can click through the window, well it doesnt work for our chatwindow (yet) so more work is needed to figure out why
/*0x119*/ bool        MouseOver;                           // found in CXWnd__SetMouseOver_x
/*0x11c*/ uint32_t    BlinkFadeStartTime;
/*0x120*/ bool        bUseInLayoutVertical;
/*0x124*/ void*       pTextObject;
/*0x128*/ bool        ValidCXWnd;                          // IsValid has this one
/*0x12c*/ uint32_t    XMLIndex;
/*0x130*/ bool        Fades;
/*0x131*/ bool        bClipToParent;
/*0x134*/ CXRect      IconRect;
/*0x144*/ mutable bool bClientClipRectChanged;
/*0x148*/ int         HScrollMax;
/*0x14c*/ bool        bIsParentOrContextMenuWindow;
/*0x150*/ CXWndDrawTemplate* DrawTemplate;
/*0x154*/ COLORREF    DisabledBackground;
/*0x158*/ uint32_t    LastBlinkFadeRefreshTime;
/*0x15c*/ COLORREF    CRNormal;                            // found in OnProcessFrame
/*0x160*/ void*       TitlePiece;
/*0x164*/ bool        bFullyScreenClipped;
/*0x168*/ int         VScrollMax;
/*0x16c*/ bool        CloseOnESC;                          // found in CSidlScreenWnd__StoreIniInfo_x, close when ESC is pressed
/*0x170*/ uint32_t    TransitionStartTick;
/*0x174*/ int         BottomOffset;
/*0x178*/ bool        bKeepOnScreen;
/*0x179*/ bool        bAction;
/*0x17c*/ uint32_t    WindowStyle;                         // bit 1 - vertical scroll, bit 2 - horizontal scroll, bit 4 - title bar?, bit 8 - border
/*0x180*/ bool        bMarkedForDelete;
/*0x181*/ bool        bTopAnchoredToTop;
/*0x182*/ bool        dShow;
/*0x183*/ bool        bRightAnchoredToLeft;
/*0x184*/ ControllerBase* pController;
/*0x188*/ bool        bShowClickThroughMenuItem;           // shows/hides the click through option on the window menu
/*0x18c*/ int         HScrollPos;
/*0x190*/ void*       pTipTextObject;
/*0x194*/ CXSize      MinClientSize;
/*0x19c*/ int         BlinkDuration;
/*0x1a0*/ bool        bMaximized;
/*0x1a4*/ int         RightOffset;
/*0x1a8*/ mutable bool bScreenClipRectChanged;
/*0x1a9*/ uint8_t     Alpha;
/*0x1aa*/ bool        Clickable;                           // found in CChatWindow__CChatWindow_x and the button handlers
/*0x1ac*/ CXStr       DataStr;
/*0x1b0*/ bool        bBorder;
/*0x1b4*/ CXStr       Tooltip;                             // found in CSidlManager__CreateLabel_x
/*0x1b8*/ bool        Unlockable;                          // found in CSidlScreenWnd__LoadIniInfo_x related to Locked
/*0x1bc*/ void*       TitlePiece2;
/*0x1c0*/ uint32_t    TransitionDuration;
/*0x1c4*/ CXWnd*      FocusProxy;
/*0x1c8*/ uint8_t     FadeAlpha;
/*0x1c9*/ bool        bUseInLayoutHorizontal;
/*0x1cc*/ CXRect      TransitionRect;
/*0x1dc*/ uint32_t    FadeDuration;
/*0x1e0*/ CXStr       XMLToolTip;                          // found in CSidlManager__CreateLabel_x
/*0x1e4*/ void*       IconTextureAnim;
/*0x1e8*/ int         LeftOffset;
