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

/*0x01c*/ bool                     bMaximizable;
/*0x01d*/ bool                     bLeftAnchoredToLeft;
/*0x020*/ uint32_t                 LastBlinkFadeRefreshTime;
/*0x024*/ bool                     bAction;
/*0x025*/ bool                     bBorder2;
/*0x028*/ CXStr                    WindowText;                          // CXWnd__GetWindowTextA_x has this one
/*0x02c*/ uint32_t                 TransitionDuration;
/*0x030*/ CXStr                    DataStr;
/*0x034*/ bool                     bBorder;
/*0x035*/ bool                     bBottomAnchoredToTop;
/*0x038*/ COLORREF                 CRNormal;                            // found in OnProcessFrame
/*0x03c*/ int                      RightOffset;
/*0x040*/ int                      ParentAndContextMenuArrayIndex;
/*0x044*/ CXRect                   IconRect;
/*0x054*/ mutable CXRect           ClipRectClient;
/*0x064*/ int                      DeleteCount;
/*0x068*/ int                      ZLayer;                              // found in CXWndManager__DrawWindows_x
/*0x06c*/ CTextureAnimation*       IconTextureAnim;
/*0x070*/ bool                     bIsTransitioning;
/*0x074*/ int                      HScrollMax;
/*0x078*/ uint8_t                  Alpha;
/*0x07c*/ ControllerBase*          pController;
/*0x080*/ uint32_t                 BlinkFadeDuration;
/*0x084*/ uint32_t                 XMLIndex;
/*0x088*/ mutable bool             bClientClipRectChanged;
/*0x089*/ mutable bool             bScreenClipRectChanged;
/*0x08c*/ CXStr                    XMLToolTip;                          // found in CSidlManager__CreateLabel_x
/*0x090*/ mutable bool             bClientRectChanged;
/*0x094*/ CXRect                   Location;
/*0x0a4*/ CXWnd*                   FocusProxy;
/*0x0a8*/ bool                     bBringToTopWhenClicked;
/*0x0ac*/ COLORREF                 DisabledBackground;
/*0x0b0*/ int                      BlinkDuration;
/*0x0b4*/ CXStr                    Tooltip;                             // found in CSidlManager__CreateLabel_x
/*0x0b8*/ bool                     bUseInLayoutHorizontal;
/*0x0b9*/ bool                     MouseOver;                           // found in CXWnd__SetMouseOver_x
/*0x0ba*/ uint8_t                  TargetAlpha;
/*0x0bb*/ bool                     bRightAnchoredToLeft;
/*0x0bc*/ bool                     bActive;
/*0x0c0*/ CTextObjectInterface*    pTextObject;
/*0x0c4*/ bool                     ValidCXWnd;                          // IsValid has this one
/*0x0c8*/ uint32_t                 WindowStyle;                         // bit 1 - vertical scroll, bit 2 - horizontal scroll, bit 4 - title bar?, bit 8 - border
/*0x0cc*/ int                      BlinkStartTimer;
/*0x0d0*/ bool                     dShow;
/*0x0d1*/ uint8_t                  FadeToAlpha;                         // found in CSidlScreenWnd__StoreIniInfo_x
/*0x0d4*/ int                      managerArrayIndex;
/*0x0d8*/ int                      VScrollMax;
/*0x0dc*/ mutable CXRect           ClientRect;
/*0x0ec*/ bool                     Unlockable;                          // found in CSidlScreenWnd__LoadIniInfo_x related to Locked
/*0x0ed*/ bool                     bClickThrough;                       // if true you can click through the window, well it doesnt work for our chatwindow (yet) so more work is needed to figure out why
/*0x0f0*/ uint32_t                 LastTimeMouseOver;
/*0x0f4*/ bool                     bIsParentOrContextMenuWindow;
/*0x0f8*/ uint32_t                 FadeDelay;
/*0x0fc*/ bool                     bEscapableLocked;
/*0x0fd*/ bool                     bKeepOnScreen;
/*0x100*/ int                      LeftOffset;
/*0x104*/ CXWndDrawTemplate*       DrawTemplate;
/*0x108*/ uint32_t                 BackgroundDrawType;
/*0x10c*/ uint32_t                 FadeDuration;
/*0x110*/ bool                     Fades;
/*0x111*/ bool                     bMarkedForDelete;
/*0x112*/ bool                     bFullyScreenClipped;
/*0x113*/ bool                     bUseInLayoutVertical;
/*0x114*/ bool                     bClipToParent;
/*0x118*/ ArrayClass2_RO<uint32_t> RuntimeTypes;       // Size 0x1c
/*0x130*/ void*                    TitlePiece2;
/*0x134*/ void*                    TitlePiece;
/*0x138*/ int                      BottomOffset;
/*0x13c*/ uint32_t                 BlinkFadeFreq;
/*0x140*/ CXSize                   MinClientSize;
/*0x148*/ bool                     Clickable;                           // found in CChatWindow__CChatWindow_x and the button handlers
/*0x149*/ bool                     bTopAnchoredToTop;
/*0x14a*/ bool                     bTiled;
/*0x14b*/ bool                     bNeedsSaving;                        // will be true if you move or resize the window
/*0x14c*/ uint8_t                  FadeAlpha;
/*0x150*/ uint32_t                 TransitionStartTick;
/*0x154*/ bool                     CloseOnESC;                          // found in CSidlScreenWnd__StoreIniInfo_x, close when ESC is pressed
/*0x158*/ int                      BlinkState;
/*0x15c*/ int                      VScrollPos;
/*0x160*/ bool                     Minimized;
/*0x164*/ CTextureFont*            pFont;
/*0x168*/ int                      Transition;
/*0x16c*/ bool                     Locked;                              // found in CSidlScreenWnd__LoadIniInfo_x
/*0x170*/ int                      TopOffset;
/*0x174*/ int                      HScrollPos;
/*0x178*/ int64_t                  Data;
/*0x180*/ CXRect                   OldLocation;
/*0x190*/ CTextObjectInterface*    pTipTextObject;
/*0x194*/ uint32_t                 BlinkFadeStartTime;
/*0x198*/ bool                     Faded;
/*0x199*/ bool                     bCaptureTitle;
/*0x19a*/ bool                     bShowClickThroughMenuItem;           // shows/hides the click through option on the window menu
/*0x19c*/ uint32_t                 BGType;                              // found in CSidlScreenWnd__StoreIniInfo_x
/*0x1a0*/ CXSize                   MaxClientSize;
/*0x1a8*/ bool                     bClickThroughMenuItemStatus;         // on/off
/*0x1a9*/ bool                     bMaximized;
/*0x1aa*/ bool                     bHCenterTooltip;
/*0x1ac*/ CLayoutStrategy*         pLayoutStrategy;
/*0x1b0*/ uint8_t                  StartAlpha;
/*0x1b4*/ CXWnd*                   ParentWindow;                        // CXWnd__IsDescendantOf_x has this one, If this is NULL, coordinates are absolute...
/*0x1b8*/ mutable CXRect           ClipRectScreen;
/*0x1c8*/ COLORREF                 BGColor;                             // DO NOT CHNAGE THIS TO AN ARGBCOLOR, it will break the padding since its a union that has bytes in it.
/*0x1cc*/ uint8_t                  bResizableMask;
/*0x1d0*/ CXRect                   TransitionRect;
/*0x1e0*/ bool                     Enabled;
