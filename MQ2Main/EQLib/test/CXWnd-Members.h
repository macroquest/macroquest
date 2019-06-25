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

	DWORD       BGType;                              // found in CSidlScreenWnd__StoreIniInfo_x
	RECT        Location;
	CXStr       WindowText;                          // CXWnd__GetWindowTextA_x has this one
	UINT        BlinkFadeDuration;
	bool        Clickable;                           // found in CChatWindow__CChatWindow_x and the button handlers
	BYTE        FadeToAlpha;                         // found in CSidlScreenWnd__StoreIniInfo_x
	bool        bHCenterTooltip;
	bool        Locked;                              // found in CSidlScreenWnd__LoadIniInfo_x
	bool        bBringToTopWhenClicked;
	bool        bCaptureTitle;
	void*       IconTextureAnim;
	void*       TitlePiece2;
	bool        bNeedsSaving;                        // will be true if you move or resize the window
	UINT        FadeDuration;
	int         DeleteCount;
	bool        bClientRectChanged;
	bool        bMaximized;
	BYTE        TargetAlpha;
	int         LeftOffset;
	BYTE        Alpha;
	CXStr       Tooltip;                             // found in CSidlManager__CreateLabel_x
	bool        bScreenClipRectChanged;
	int         BottomOffset;
	BYTE        FadeAlpha;
	void*       pTipTextObject;
	int         VScrollMax;
	DWORD       LastTimeMouseOver;
	bool        Faded;
	int         VScrollPos;
	bool        bBorder2;
	bool        bActive;
	int         BlinkDuration;
	bool        bIsTransitioning;
	int         ParentAndContextMenuArrayIndex;
	bool        Enabled;
	RECT        TransitionRect;
	bool        bMarkedForDelete;
	UINT        BlinkFadeStartTime;
	bool        bAction;
	bool        bClickThroughMenuItemStatus;         // on/off
	void*       pFont;
	bool        bIsParentOrContextMenuWindow;
	tagSIZE     MaxClientSize;
	int         ZLayer;                              // found in CXWndManager__DrawWindows_x
	COLORREF    CRNormal;                            // found in OnProcessFrame
	bool        bUseInLayoutHorizontal;
	bool        bRightAnchoredToLeft;
	DWORD       FadeDelay;
	bool        bEscapableLocked;
	RECT        OldLocation;
	BYTE        bResizableMask;
	bool        bMaximizable;
	int         BlinkState;
	bool        dShow;
	int         HScrollMax;
	bool        Unlockable;                          // found in CSidlScreenWnd__LoadIniInfo_x related to Locked
	bool        Minimized;
	CSIDLWND*   pWndFocusOther;
	bool        bShowClickThroughMenuItem;           // shows/hides the click through option on the window menu
	bool        bTopAnchoredToTop;
	DWORD       XMLIndex;
	void*       pController;
	void*       TitlePiece;
	bool        MouseOver;                           // found in CXWnd__SetMouseOver_x
	bool        Fades;
	COLORREF    DisabledBackground;
	bool        bBottomAnchoredToTop;
	UINT        LastBlinkFadeRefreshTime;
	RECT        ClipRectClient;
	bool        bClipToParent;
	void*       pTextObject;
	bool        bUseInLayoutVertical;
	int         managerArrayIndex;
	UINT        TransitionDuration;
	BYTE        StartAlpha;
	bool        ValidCXWnd;                          // IsValid has this one
	bool        bBorder;
	CXStr       DataStr;
	int64_t     Data;
	tagSIZE     MinClientSize;
	bool        bLeftAnchoredToLeft;
	RECT        IconRect;
	RECT        ClipRectScreen;
	LONG        BlinkStartTimer;
	bool        bFullyScreenClipped;
	int         Transition;
	RECT        ClientRect;
	int         TopOffset;
	bool        bTiled;
	bool        bClientClipRectChanged;
	bool        bClickThrough;                       // if true you can click through the window, well it doesnt work for our chatwindow (yet) so more work is needed to figure out why
	UINT        BlinkFadeFreq;
	int         HScrollPos;
	DWORD       WindowStyle;                         // bit 1 - vertical scroll, bit 2 - horizontal scroll, bit 4 - title bar?, bit 8 - border
	UINT        TransitionStartTick;
	bool        CloseOnESC;                          // found in CSidlScreenWnd__StoreIniInfo_x, close when ESC is pressed
	COLORREF    BGColor;                             // DO NOT CHNAGE THIS TO AN ARGBCOLOR, it will break the padding since its a union that has bytes in it.
	CXStr       XMLToolTip;                          // found in CSidlManager__CreateLabel_x
	void*       pLayoutStrategy;
	void*       DrawTemplate;
	CSIDLWND*   pParentWindow;                       // CXWnd__IsDescendantOf_x has this one, If this is NULL, coordinates are absolute...
	bool        bKeepOnScreen;
	ArrayClass2_RO<UINT> RuntimeTypes;                     // Size 0x1c
	int         RightOffset;
	DWORD       BackgroundDrawType;
