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

	uint32_t    BGType;                              // found in CSidlScreenWnd__StoreIniInfo_x
	CXRect      Location;
	CXStr       WindowText;                          // CXWnd__GetWindowTextA_x has this one
	uint32_t    BlinkFadeDuration;
	bool        Clickable;                           // found in CChatWindow__CChatWindow_x and the button handlers
	uint8_t     FadeToAlpha;                         // found in CSidlScreenWnd__StoreIniInfo_x
	bool        bHCenterTooltip;
	bool        Locked;                              // found in CSidlScreenWnd__LoadIniInfo_x
	bool        bBringToTopWhenClicked;
	bool        bCaptureTitle;
	void*       IconTextureAnim;
	void*       TitlePiece2;
	bool        bNeedsSaving;                        // will be true if you move or resize the window
	uint32_t    FadeDuration;
	int         DeleteCount;
	mutable bool bClientRectChanged;
	bool        bMaximized;
	uint8_t     TargetAlpha;
	int         LeftOffset;
	uint8_t     Alpha;
	CXStr       Tooltip;                             // found in CSidlManager__CreateLabel_x
	mutable bool bScreenClipRectChanged;
	int         BottomOffset;
	uint8_t     FadeAlpha;
	void*       pTipTextObject;
	int         VScrollMax;
	uint32_t    LastTimeMouseOver;
	bool        Faded;
	int         VScrollPos;
	bool        bBorder2;
	bool        bActive;
	int         BlinkDuration;
	bool        bIsTransitioning;
	int         ParentAndContextMenuArrayIndex;
	bool        Enabled;
	CXRect      TransitionRect;
	bool        bMarkedForDelete;
	uint32_t    BlinkFadeStartTime;
	bool        bAction;
	bool        bClickThroughMenuItemStatus;         // on/off
	void*       pFont;
	bool        bIsParentOrContextMenuWindow;
	CXSize      MaxClientSize;
	int         ZLayer;                              // found in CXWndManager__DrawWindows_x
	COLORREF    CRNormal;                            // found in OnProcessFrame
	bool        bUseInLayoutHorizontal;
	bool        bRightAnchoredToLeft;
	uint32_t    FadeDelay;
	bool        bEscapableLocked;
	CXRect      OldLocation;
	uint8_t     bResizableMask;
	bool        bMaximizable;
	int         BlinkState;
	bool        dShow;
	int         HScrollMax;
	bool        Unlockable;                          // found in CSidlScreenWnd__LoadIniInfo_x related to Locked
	bool        Minimized;
	CXWnd*      FocusProxy;
	bool        bShowClickThroughMenuItem;           // shows/hides the click through option on the window menu
	bool        bTopAnchoredToTop;
	uint32_t    XMLIndex;
	ControllerBase* pController;
	void*       TitlePiece;
	bool        MouseOver;                           // found in CXWnd__SetMouseOver_x
	bool        Fades;
	COLORREF    DisabledBackground;
	bool        bBottomAnchoredToTop;
	uint32_t    LastBlinkFadeRefreshTime;
	mutable CXRect ClipRectClient;
	bool        bClipToParent;
	void*       pTextObject;
	bool        bUseInLayoutVertical;
	int         managerArrayIndex;
	uint32_t    TransitionDuration;
	uint8_t     StartAlpha;
	bool        ValidCXWnd;                          // IsValid has this one
	bool        bBorder;
	CXStr       DataStr;
	int64_t     Data;
	CXSize      MinClientSize;
	bool        bLeftAnchoredToLeft;
	CXRect      IconRect;
	mutable CXRect ClipRectScreen;
	int         BlinkStartTimer;
	bool        bFullyScreenClipped;
	int         Transition;
	mutable CXRect ClientRect;
	int         TopOffset;
	bool        bTiled;
	mutable bool bClientClipRectChanged;
	bool        bClickThrough;                       // if true you can click through the window, well it doesnt work for our chatwindow (yet) so more work is needed to figure out why
	uint32_t    BlinkFadeFreq;
	int         HScrollPos;
	uint32_t    WindowStyle;                         // bit 1 - vertical scroll, bit 2 - horizontal scroll, bit 4 - title bar?, bit 8 - border
	uint32_t    TransitionStartTick;
	bool        CloseOnESC;                          // found in CSidlScreenWnd__StoreIniInfo_x, close when ESC is pressed
	COLORREF    BGColor;                             // DO NOT CHNAGE THIS TO AN ARGBCOLOR, it will break the padding since its a union that has bytes in it.
	CXStr       XMLToolTip;                          // found in CSidlManager__CreateLabel_x
	CLayoutStrategy* pLayoutStrategy;
	CXWndDrawTemplate* DrawTemplate;
	CXWnd*      ParentWindow;                        // CXWnd__IsDescendantOf_x has this one, If this is NULL, coordinates are absolute...
	bool        bKeepOnScreen;
	ArrayClass2_RO<UINT> RuntimeTypes;               // Size 0x1c
	int         RightOffset;
	uint32_t    BackgroundDrawType;
