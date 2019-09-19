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

/*0x01c*/ int                      LeftOffset;
/*0x020*/ int                      ZLayer;                              // found in CXWndManager__DrawWindows_x
/*0x024*/ uint32_t                 BGType;                              // found in CSidlScreenWnd__StoreIniInfo_x
/*0x028*/ CTextureFont*            pFont;
/*0x02c*/ uint8_t                  TargetAlpha;
/*0x02d*/ bool                     Minimized;
/*0x02e*/ bool                     dShow;
/*0x02f*/ bool                     bClipToParent;
/*0x030*/ CXStr                    XMLToolTip;                          // found in CSidlManager__CreateLabel_x
/*0x034*/ mutable CXRect           ClientRect;
/*0x044*/ ArrayClass2_RO<uint32_t> RuntimeTypes;       // Size 0x1c
/*0x05c*/ void*                    TitlePiece2;
/*0x060*/ uint8_t                  bResizableMask;
/*0x061*/ bool                     bUseInLayoutVertical;
/*0x062*/ uint8_t                  FadeAlpha;
/*0x063*/ uint8_t                  StartAlpha;
/*0x064*/ bool                     ValidCXWnd;                          // IsValid has this one
/*0x068*/ int                      BottomOffset;
/*0x06c*/ int                      managerArrayIndex;
/*0x070*/ bool                     MouseOver;                           // found in CXWnd__SetMouseOver_x
/*0x074*/ mutable CXRect           ClipRectScreen;
/*0x084*/ mutable bool             bClientRectChanged;
/*0x085*/ bool                     bActive;
/*0x088*/ COLORREF                 BGColor;                             // DO NOT CHNAGE THIS TO AN ARGBCOLOR, it will break the padding since its a union that has bytes in it.
/*0x08c*/ bool                     bShowClickThroughMenuItem;           // shows/hides the click through option on the window menu
/*0x08d*/ bool                     Fades;
/*0x090*/ uint32_t                 XMLIndex;
/*0x094*/ int                      BlinkDuration;
/*0x098*/ bool                     bNeedsSaving;                        // will be true if you move or resize the window
/*0x09c*/ uint32_t                 LastBlinkFadeRefreshTime;
/*0x0a0*/ bool                     bIsParentOrContextMenuWindow;
/*0x0a1*/ bool                     bUseInLayoutHorizontal;
/*0x0a8*/ int64_t                  Data;
/*0x0b0*/ uint32_t                 BlinkFadeDuration;
/*0x0b4*/ CTextObjectInterface*    pTextObject;
/*0x0b8*/ int                      Transition;
/*0x0bc*/ int                      HScrollPos;
/*0x0c0*/ bool                     Faded;
/*0x0c4*/ COLORREF                 CRNormal;                            // found in OnProcessFrame
/*0x0c8*/ uint32_t                 FadeDuration;
/*0x0cc*/ void*                    TitlePiece;
/*0x0d0*/ bool                     bMaximized;
/*0x0d1*/ uint8_t                  Alpha;
/*0x0d2*/ bool                     bEscapableLocked;
/*0x0d4*/ CXStr                    DataStr;
/*0x0d8*/ CXStr                    WindowText;                          // CXWnd__GetWindowTextA_x has this one
/*0x0dc*/ bool                     bRightAnchoredToLeft;
/*0x0dd*/ bool                     Unlockable;                          // found in CSidlScreenWnd__LoadIniInfo_x related to Locked
/*0x0de*/ bool                     bMarkedForDelete;
/*0x0e0*/ mutable CXRect           ClipRectClient;
/*0x0f0*/ CXRect                   OldLocation;
/*0x100*/ CXSize                   MaxClientSize;
/*0x108*/ bool                     bAction;
/*0x109*/ bool                     bCaptureTitle;
/*0x10c*/ int                      DeleteCount;
/*0x110*/ uint32_t                 BlinkFadeStartTime;
/*0x114*/ uint32_t                 TransitionDuration;
/*0x118*/ bool                     bLeftAnchoredToLeft;
/*0x119*/ bool                     bClickThroughMenuItemStatus;         // on/off
/*0x11a*/ uint8_t                  FadeToAlpha;                         // found in CSidlScreenWnd__StoreIniInfo_x
/*0x11b*/ bool                     bBorder;
/*0x11c*/ bool                     bTopAnchoredToTop;
/*0x120*/ CXStr                    Tooltip;                             // found in CSidlManager__CreateLabel_x
/*0x124*/ bool                     bTiled;
/*0x128*/ int                      BlinkStartTimer;
/*0x12c*/ COLORREF                 DisabledBackground;
/*0x130*/ int                      VScrollPos;
/*0x134*/ bool                     CloseOnESC;                          // found in CSidlScreenWnd__StoreIniInfo_x, close when ESC is pressed
/*0x135*/ mutable bool             bClientClipRectChanged;
/*0x138*/ uint32_t                 LastTimeMouseOver;
/*0x13c*/ bool                     Enabled;
/*0x13d*/ bool                     bBorder2;
/*0x140*/ CXRect                   TransitionRect;
/*0x150*/ int                      VScrollMax;
/*0x154*/ bool                     bFullyScreenClipped;
/*0x155*/ bool                     bClickThrough;                       // if true you can click through the window, well it doesnt work for our chatwindow (yet) so more work is needed to figure out why
/*0x158*/ uint32_t                 BackgroundDrawType;
/*0x15c*/ CXWnd*                   ParentWindow;                        // CXWnd__IsDescendantOf_x has this one, If this is NULL, coordinates are absolute...
/*0x160*/ bool                     bBringToTopWhenClicked;
/*0x161*/ bool                     bBottomAnchoredToTop;
/*0x164*/ uint32_t                 BlinkFadeFreq;
/*0x168*/ ControllerBase*          pController;
/*0x16c*/ int                      ParentAndContextMenuArrayIndex;
/*0x170*/ CXRect                   Location;
/*0x180*/ CXWnd*                   FocusProxy;
/*0x184*/ int                      HScrollMax;
/*0x188*/ CTextObjectInterface*    pTipTextObject;
/*0x18c*/ uint32_t                 WindowStyle;                         // bit 1 - vertical scroll, bit 2 - horizontal scroll, bit 4 - title bar?, bit 8 - border
/*0x190*/ uint32_t                 FadeDelay;
/*0x194*/ int                      RightOffset;
/*0x198*/ CXWndDrawTemplate*       DrawTemplate;
/*0x19c*/ bool                     bKeepOnScreen;
/*0x1a0*/ CXRect                   IconRect;
/*0x1b0*/ int                      TopOffset;
/*0x1b4*/ uint32_t                 TransitionStartTick;
/*0x1b8*/ mutable bool             bScreenClipRectChanged;
/*0x1b9*/ bool                     Clickable;                           // found in CChatWindow__CChatWindow_x and the button handlers
/*0x1ba*/ bool                     bMaximizable;
/*0x1bb*/ bool                     bHCenterTooltip;
/*0x1bc*/ CLayoutStrategy*         pLayoutStrategy;
/*0x1c0*/ bool                     Locked;                              // found in CSidlScreenWnd__LoadIniInfo_x
/*0x1c4*/ CTextureAnimation*       IconTextureAnim;
/*0x1c8*/ int                      BlinkState;
/*0x1cc*/ CXSize                   MinClientSize;
/*0x1d4*/ bool                     bIsTransitioning;
