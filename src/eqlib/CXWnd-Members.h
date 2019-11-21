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
/*0x020*/ int         HScrollPos;
/*0x024*/ CXRect      TransitionRect;
/*0x034*/ uint8_t     StartAlpha;
/*0x038*/ mutable CXRect ClipRectClient;
/*0x048*/ COLORREF    DisabledBackground;
/*0x04c*/ CXSize      MinClientSize;
/*0x054*/ bool        bBorder2;
/*0x055*/ uint8_t     bResizableMask;
/*0x056*/ bool        bEscapableLocked;
/*0x057*/ uint8_t     FadeAlpha;
/*0x058*/ bool        bIsParentOrContextMenuWindow;
/*0x059*/ bool        bTopAnchoredToTop;
/*0x05c*/ CXWnd*      ParentWindow;                        // CXWnd__IsDescendantOf_x has this one, If this is NULL, coordinates are absolute...
/*0x060*/ bool        bBringToTopWhenClicked;
/*0x064*/ mutable CXRect ClipRectScreen;
/*0x074*/ int         BottomOffset;
/*0x078*/ bool        bRightAnchoredToLeft;
/*0x07c*/ void*       pTipTextObject;
/*0x080*/ bool        Locked;                              // found in CSidlScreenWnd__LoadIniInfo_x
/*0x081*/ uint8_t     Alpha;
/*0x084*/ void*       TitlePiece;
/*0x088*/ bool        dShow;
/*0x089*/ bool        Minimized;
/*0x08c*/ uint32_t    TransitionDuration;
/*0x090*/ bool        bActive;
/*0x091*/ bool        Clickable;                           // found in CChatWindow__CChatWindow_x and the button handlers
/*0x094*/ COLORREF    BGColor;                             // DO NOT CHNAGE THIS TO AN ARGBCOLOR, it will break the padding since its a union that has bytes in it.
/*0x098*/ bool        bMaximizable;
/*0x09c*/ CXStr       Tooltip;                             // found in CSidlManager__CreateLabel_x
/*0x0a0*/ bool        bUseInLayoutVertical;
/*0x0a4*/ COLORREF    CRNormal;                            // found in OnProcessFrame
/*0x0a8*/ CLayoutStrategy* pLayoutStrategy;
/*0x0ac*/ bool        bIsTransitioning;
/*0x0ad*/ bool        ValidCXWnd;                          // IsValid has this one
/*0x0b0*/ CXRect      IconRect;
/*0x0c0*/ int         BlinkState;
/*0x0c4*/ uint8_t     FadeToAlpha;                         // found in CSidlScreenWnd__StoreIniInfo_x
/*0x0c8*/ uint32_t    WindowStyle;                         // bit 1 - vertical scroll, bit 2 - horizontal scroll, bit 4 - title bar?, bit 8 - border
/*0x0cc*/ CXRect      OldLocation;
/*0x0dc*/ ArrayClass2_RO<unsigned int> RuntimeTypes;       // Size 0x1c
/*0x0f4*/ CXStr       XMLToolTip;                          // found in CSidlManager__CreateLabel_x
/*0x0f8*/ uint32_t    FadeDuration;
/*0x0fc*/ bool        bMaximized;
/*0x100*/ CXStr       WindowText;                          // CXWnd__GetWindowTextA_x has this one
/*0x104*/ int         BlinkStartTimer;
/*0x108*/ uint32_t    LastTimeMouseOver;
/*0x10c*/ int         BlinkDuration;
/*0x110*/ bool        bUseInLayoutHorizontal;
/*0x111*/ bool        bBottomAnchoredToTop;
/*0x114*/ int         RightOffset;
/*0x118*/ mutable CXRect ClientRect;
/*0x128*/ void*       pFont;
/*0x12c*/ int         LeftOffset;
/*0x130*/ bool        bTiled;
/*0x134*/ uint32_t    FadeDelay;
/*0x138*/ bool        bKeepOnScreen;
/*0x13c*/ void*       TitlePiece2;
/*0x140*/ bool        Faded;
/*0x141*/ uint8_t     TargetAlpha;
/*0x142*/ bool        CloseOnESC;                          // found in CSidlScreenWnd__StoreIniInfo_x, close when ESC is pressed
/*0x144*/ int         ParentAndContextMenuArrayIndex;
/*0x148*/ CXWnd*      FocusProxy;
/*0x14c*/ CXSize      MaxClientSize;
/*0x154*/ bool        MouseOver;                           // found in CXWnd__SetMouseOver_x
/*0x155*/ bool        bCaptureTitle;
/*0x158*/ uint32_t    BlinkFadeDuration;
/*0x15c*/ int         managerArrayIndex;
/*0x160*/ bool        bClickThrough;                       // if true you can click through the window, well it doesnt work for our chatwindow (yet) so more work is needed to figure out why
/*0x161*/ bool        bFullyScreenClipped;
/*0x162*/ bool        bShowClickThroughMenuItem;           // shows/hides the click through option on the window menu
/*0x163*/ mutable bool bClientClipRectChanged;
/*0x164*/ int         TopOffset;
/*0x168*/ uint32_t    TransitionStartTick;
/*0x16c*/ uint32_t    LastBlinkFadeRefreshTime;
/*0x170*/ int         VScrollMax;
/*0x174*/ CXRect      Location;
/*0x184*/ int         ZLayer;                              // found in CXWndManager__DrawWindows_x
/*0x188*/ bool        bClickThroughMenuItemStatus;         // on/off
/*0x189*/ bool        bBorder;
/*0x18c*/ CXWndDrawTemplate* DrawTemplate;
/*0x190*/ ControllerBase* pController;
/*0x198*/ int64_t     Data;
/*0x1a0*/ bool        bHCenterTooltip;
/*0x1a4*/ int         HScrollMax;
/*0x1a8*/ mutable bool bClientRectChanged;
/*0x1a9*/ bool        Fades;
/*0x1ac*/ uint32_t    BackgroundDrawType;
/*0x1b0*/ uint32_t    BGType;                              // found in CSidlScreenWnd__StoreIniInfo_x
/*0x1b4*/ uint32_t    BlinkFadeFreq;
/*0x1b8*/ bool        Enabled;
/*0x1b9*/ bool        bNeedsSaving;                        // will be true if you move or resize the window
/*0x1bc*/ uint32_t    BlinkFadeStartTime;
/*0x1c0*/ bool        bMarkedForDelete;
/*0x1c1*/ bool        bLeftAnchoredToLeft;
/*0x1c4*/ uint32_t    XMLIndex;
/*0x1c8*/ mutable bool bScreenClipRectChanged;
/*0x1c9*/ bool        bAction;
/*0x1cc*/ int         Transition;
/*0x1d0*/ int         VScrollPos;
/*0x1d4*/ int         DeleteCount;
/*0x1d8*/ void*       pTextObject;
/*0x1dc*/ bool        bClipToParent;
/*0x1e0*/ CXStr       DataStr;
/*0x1e4*/ bool        Unlockable;                          // found in CSidlScreenWnd__LoadIniInfo_x related to Locked
