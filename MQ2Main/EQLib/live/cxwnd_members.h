	int         TopOffset;
	bool        CloseOnESC;                          // found in CSidlScreenWnd__StoreIniInfo_x, close when ESC is pressed
	bool        bActive;
	int         BlinkState;
	ArrayClass2_RO RuntimeTypes;                     // Size 0x1c
	void*       pTextObject;
	bool        bUseInLayoutHorizontal;
	DWORD       FadeDelay;
	bool        bShowClickThroughMenuItem;           // shows/hides the click through option on the window menu
	DWORD       BGType;                              // found in CSidlScreenWnd__StoreIniInfo_x
	bool        bNeedsSaving;                        // will be true if you move or resize the window
	BYTE        TargetAlpha;
	DWORD       WindowStyle;                         // bit 1 - vertical scroll, bit 2 - horizontal scroll, bit 4 - title bar?, bit 8 - border
	int         VScrollPos;
	CXStr       DataStr;
	int64_t     Data;
	CXStr       Tooltip;                             // found in CSidlManager__CreateLabel_x
	UINT        BlinkFadeFreq;
	bool        bClientClipRectChanged;
	bool        bBorder2;
	int         Transition;
	bool        Locked;                              // found in CSidlScreenWnd__LoadIniInfo_x
	RECT        TransitionRect;
	UINT        BlinkFadeDuration;
	bool        bBringToTopWhenClicked;
	bool        Minimized;
	int         LeftOffset;
	int         VScrollMax;
	RECT        ClipRectClient;
	bool        bIsTransitioning;
	bool        Enabled;
	int         HScrollMax;
	bool        bScreenClipRectChanged;
	BYTE        Alpha;
	bool        bFullyScreenClipped;
	bool        bBorder;
	bool        bHCenterTooltip;
	int         DeleteCount;
	bool        bClickThroughMenuItemStatus;         // on/off
	COLORREF    CRNormal;                            // found in OnProcessFrame
	BYTE        FadeToAlpha;                         // found in CSidlScreenWnd__StoreIniInfo_x
	bool        bLeftAnchoredToLeft;
	void*       TitlePiece;
	RECT        ClipRectScreen;
	int         ZLayer;                              // found in CXWndManager__DrawWindows_x
	DWORD       LastTimeMouseOver;
	RECT        IconRect;
	DWORD       XMLIndex;
	bool        bClientRectChanged;
	int         HScrollPos;
	bool        bBottomAnchoredToTop;
	bool        Clickable;                           // found in CChatWindow__CChatWindow_x and the button handlers
	bool        bClipToParent;
	bool        bKeepOnScreen;
	LONG        BlinkStartTimer;
	RECT        ClientRect;
	BYTE        bResizableMask;
	bool        bRightAnchoredToLeft;
	void*       IconTextureAnim;
	void*       DrawTemplate;
	COLORREF    BGColor;                             // DO NOT CHNAGE THIS TO AN ARGBCOLOR, it will break the padding since its a union that has bytes in it.
	void*       pLayoutStrategy;
	BYTE        FadeAlpha;
	UINT        LastBlinkFadeRefreshTime;
	int         ParentAndContextMenuArrayIndex;
	COLORREF    DisabledBackground;
	UINT        FadeDuration;
	bool        bIsParentOrContextMenuWindow;
	BYTE        StartAlpha;
	RECT        OldLocation;
	int         RightOffset;
	bool        bClickThrough;                       // if true you can click through the window, well it doesnt work for our chatwindow (yet) so more work is needed to figure out why
	void*       pFont;
	CXStr       WindowText;                          // CXWnd__GetWindowTextA_x has this one
	void*       pTipTextObject;
	bool        bTopAnchoredToTop;
	bool        dShow;
	bool        bMarkedForDelete;
	UINT        TransitionDuration;
	CXStr       XMLToolTip;                          // found in CSidlManager__CreateLabel_x
	UINT        BlinkFadeStartTime;
	bool        bMaximized;
	DWORD       BackgroundDrawType;
	RECT        Location;
	bool        Unlockable;                          // found in CSidlScreenWnd__LoadIniInfo_x related to Locked
	bool        bEscapableLocked;
	void*       pController;
	void*       TitlePiece2;
	CSIDLWND*   pWndFocusOther;
	int         managerArrayIndex;
	bool        bTiled;
	tagSIZE     MaxClientSize;
	bool        bMaximizable;
	UINT        TransitionStartTick;
	tagSIZE     MinClientSize;
	int         BlinkDuration;
	bool        bAction;
	bool        ValidCXWnd;                          // IsValid has this one
	int         BottomOffset;
	bool        MouseOver;                           // found in CXWnd__SetMouseOver_x
	CSIDLWND*   pParentWindow;                       // CXWnd__IsDescendantOf_x has this one, If this is NULL, coordinates are absolute...
	bool        Fades;
	bool        Faded;
	bool        bCaptureTitle;
	bool        bUseInLayoutVertical;
	