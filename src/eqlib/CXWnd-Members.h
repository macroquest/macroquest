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

/*0x01c*/ uint32_t    WindowStyle;                         // bit 1 - vertical scroll, bit 2 - horizontal scroll, bit 4 - title bar?, bit 8 - border
/*0x020*/ CXRect      TransitionRect;
/*0x030*/ bool        bIsParentOrContextMenuWindow;
/*0x031*/ bool        dShow;
/*0x032*/ uint8_t     FadeToAlpha;                         // found in CSidlScreenWnd__StoreIniInfo_x
/*0x033*/ bool        bTopAnchoredToTop;
/*0x034*/ bool        bMaximized;
/*0x038*/ void*       TitlePiece2;
/*0x03c*/ CLayoutStrategy* pLayoutStrategy;
/*0x040*/ COLORREF    DisabledBackground;
/*0x044*/ void*       pTipTextObject;
/*0x048*/ CXStr       XMLToolTip;                          // found in CSidlManager__CreateLabel_x
/*0x04c*/ void*       pTextObject;
/*0x050*/ int         BlinkDuration;
/*0x054*/ int         LeftOffset;
/*0x058*/ bool        bClipToParent;
/*0x05c*/ int         ParentAndContextMenuArrayIndex;
/*0x060*/ uint32_t    BlinkFadeDuration;
/*0x064*/ bool        bKeepOnScreen;
/*0x068*/ uint32_t    FadeDelay;
/*0x06c*/ int         BottomOffset;
/*0x070*/ bool        bLeftAnchoredToLeft;
/*0x071*/ mutable bool bScreenClipRectChanged;
/*0x072*/ uint8_t     FadeAlpha;
/*0x074*/ int         TopOffset;
/*0x078*/ mutable CXRect ClientRect;
/*0x088*/ CXStr       DataStr;
/*0x08c*/ bool        Fades;
/*0x090*/ CXStr       Tooltip;                             // found in CSidlManager__CreateLabel_x
/*0x094*/ int         ZLayer;                              // found in CXWndManager__DrawWindows_x
/*0x098*/ CXWnd*      FocusProxy;
/*0x09c*/ CXStr       WindowText;                          // CXWnd__GetWindowTextA_x has this one
/*0x0a0*/ bool        bHCenterTooltip;
/*0x0a1*/ bool        bMarkedForDelete;
/*0x0a4*/ void*       IconTextureAnim;
/*0x0a8*/ int         VScrollPos;
/*0x0ac*/ bool        CloseOnESC;                          // found in CSidlScreenWnd__StoreIniInfo_x, close when ESC is pressed
/*0x0ad*/ bool        bTiled;
/*0x0ae*/ bool        bBringToTopWhenClicked;
/*0x0b0*/ mutable CXRect ClipRectClient;
/*0x0c0*/ uint32_t    TransitionDuration;
/*0x0c4*/ CXSize      MinClientSize;
/*0x0cc*/ uint32_t    BlinkFadeStartTime;
/*0x0d0*/ bool        bIsTransitioning;
/*0x0d1*/ uint8_t     StartAlpha;
/*0x0d4*/ uint32_t    BlinkFadeFreq;
/*0x0d8*/ uint32_t    BGType;                              // found in CSidlScreenWnd__StoreIniInfo_x
/*0x0dc*/ uint8_t     bResizableMask;
/*0x0e0*/ CXWndDrawTemplate* DrawTemplate;
/*0x0e4*/ uint32_t    TransitionStartTick;
/*0x0e8*/ uint8_t     TargetAlpha;
/*0x0ec*/ int         Transition;
/*0x0f0*/ int         HScrollMax;
/*0x0f4*/ bool        bClickThroughMenuItemStatus;         // on/off
/*0x0f8*/ CXRect      Location;
/*0x108*/ bool        Clickable;                           // found in CChatWindow__CChatWindow_x and the button handlers
/*0x109*/ bool        Minimized;
/*0x10a*/ bool        Locked;                              // found in CSidlScreenWnd__LoadIniInfo_x
/*0x10b*/ bool        Unlockable;                          // found in CSidlScreenWnd__LoadIniInfo_x related to Locked
/*0x10c*/ CXSize      MaxClientSize;
/*0x114*/ int         managerArrayIndex;
/*0x118*/ bool        bBorder;
/*0x11c*/ int         DeleteCount;
/*0x120*/ bool        bFullyScreenClipped;
/*0x121*/ bool        bUseInLayoutHorizontal;
/*0x124*/ ArrayClass2_RO<unsigned int> RuntimeTypes;       // Size 0x1c
/*0x13c*/ bool        bBottomAnchoredToTop;
/*0x140*/ mutable CXRect ClipRectScreen;
/*0x150*/ mutable bool bClientRectChanged;
/*0x154*/ COLORREF    BGColor;                             // DO NOT CHNAGE THIS TO AN ARGBCOLOR, it will break the padding since its a union that has bytes in it.
/*0x158*/ CXRect      IconRect;
/*0x168*/ bool        bNeedsSaving;                        // will be true if you move or resize the window
/*0x169*/ bool        Enabled;
/*0x16c*/ int         RightOffset;
/*0x170*/ bool        bCaptureTitle;
/*0x171*/ bool        bClickThrough;                       // if true you can click through the window, well it doesnt work for our chatwindow (yet) so more work is needed to figure out why
/*0x172*/ bool        MouseOver;                           // found in CXWnd__SetMouseOver_x
/*0x173*/ uint8_t     Alpha;
/*0x174*/ bool        bAction;
/*0x178*/ uint32_t    XMLIndex;
/*0x17c*/ uint32_t    LastTimeMouseOver;
/*0x180*/ int64_t     Data;
/*0x188*/ CXWnd*      ParentWindow;                        // CXWnd__IsDescendantOf_x has this one, If this is NULL, coordinates are absolute...
/*0x18c*/ int         BlinkStartTimer;
/*0x190*/ int         HScrollPos;
/*0x194*/ void*       pFont;
/*0x198*/ uint32_t    LastBlinkFadeRefreshTime;
/*0x19c*/ uint32_t    FadeDuration;
/*0x1a0*/ int         VScrollMax;
/*0x1a4*/ bool        ValidCXWnd;                          // IsValid has this one
/*0x1a8*/ ControllerBase* pController;
/*0x1ac*/ CXRect      OldLocation;
/*0x1bc*/ void*       TitlePiece;
/*0x1c0*/ bool        bBorder2;
/*0x1c1*/ bool        bShowClickThroughMenuItem;           // shows/hides the click through option on the window menu
/*0x1c2*/ bool        bUseInLayoutVertical;
/*0x1c4*/ int         BlinkState;
/*0x1c8*/ COLORREF    CRNormal;                            // found in OnProcessFrame
/*0x1cc*/ mutable bool bClientClipRectChanged;
/*0x1cd*/ bool        Faded;
/*0x1ce*/ bool        bEscapableLocked;
/*0x1cf*/ bool        bRightAnchoredToLeft;
/*0x1d0*/ bool        bActive;
/*0x1d4*/ uint32_t    BackgroundDrawType;
/*0x1d8*/ bool        bMaximizable;
