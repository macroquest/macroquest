	bool        bEscapableLocked;
	void*       pTipTextObject;
	bool        bUseInLayoutHorizontal;
	int         BlinkDuration;
	tagSIZE     MaxClientSize;
	void*       pController;
	bool        bBottomAnchoredToTop;
	int         HScrollMax;
	bool        Minimized;
	RECT        ClipRectScreen;
	RECT        OldLocation;
	UINT        FadeDuration;
	int         ZLayer;                              // found in CXWndManager__DrawWindows_x
	UINT        TransitionStartTick;
	bool        bClientClipRectChanged;
	BYTE        bResizableMask;
	int         VScrollMax;
	bool        bCaptureTitle;
	bool        bBorder2;
	int         LeftOffset;
	bool        Enabled;
	LONG        BlinkStartTimer;
	ArrayClass2_RO RuntimeTypes;                     // Size 0x1c
	bool        Clickable;                           // found in CChatWindow__CChatWindow_x and the button handlers
	int         BottomOffset;
	bool        bClipToParent;
	bool        Unlockable;                          // found in CSidlScreenWnd__LoadIniInfo_x related to Locked
	RECT        ClientRect;
	CSIDLWND*   pParentWindow;                       // CXWnd__IsDescendantOf_x has this one, If this is NULL, coordinates are absolute...
	bool        bClickThrough;                       // if true you can click through the window, well it doesnt work for our chatwindow (yet) so more work is needed to figure out why
	bool        bUseInLayoutVertical;
	int         TopOffset;
	bool        bBringToTopWhenClicked;
	void*       pFont;
	int         VScrollPos;
	BYTE        FadeToAlpha;                         // found in CSidlScreenWnd__StoreIniInfo_x
	int64_t     Data;
	void*       TitlePiece;
	RECT        ClipRectClient;
	bool        bMaximized;
	bool        bFullyScreenClipped;
	int         ParentAndContextMenuArrayIndex;
	void*       pLayoutStrategy;
	CXStr       DataStr;
	bool        Fades;
	COLORREF    DisabledBackground;
	DWORD       FadeDelay;
	bool        bMaximizable;
	void*       TitlePiece2;
	bool        bTiled;
	DWORD       XMLIndex;
	int         HScrollPos;
	DWORD       BGType;                              // found in CSidlScreenWnd__StoreIniInfo_x
	BYTE        TargetAlpha;
	UINT        BlinkFadeStartTime;
	CXStr       WindowText;                          // CXWnd__GetWindowTextA_x has this one
	CXStr       XMLToolTip;                          // found in CSidlManager__CreateLabel_x
	int         DeleteCount;
	UINT        LastBlinkFadeRefreshTime;
	bool        bActive;
	bool        bHCenterTooltip;
	COLORREF    CRNormal;                            // found in OnProcessFrame
	RECT        Location;
	DWORD       LastTimeMouseOver;
	bool        bClickThroughMenuItemStatus;         // on/off
	int         Transition;
	bool        bKeepOnScreen;
	bool        bLeftAnchoredToLeft;
	void*       DrawTemplate;
	UINT        TransitionDuration;
	bool        bIsParentOrContextMenuWindow;
	int         RightOffset;
	bool        Faded;
	int         BlinkState;
	bool        bTopAnchoredToTop;
	bool        bScreenClipRectChanged;
	bool        dShow;
	bool        bIsTransitioning;
	int         managerArrayIndex;
	bool        bShowClickThroughMenuItem;           // shows/hides the click through option on the window menu
	DWORD       WindowStyle;                         // bit 1 - vertical scroll, bit 2 - horizontal scroll, bit 4 - title bar?, bit 8 - border
	bool        bNeedsSaving;                        // will be true if you move or resize the window
	COLORREF    BGColor;                             // DO NOT CHNAGE THIS TO AN ARGBCOLOR, it will break the padding since its a union that has bytes in it.
	bool        ValidCXWnd;                          // IsValid has this one
	RECT        TransitionRect;
	RECT        IconRect;
	BYTE        Alpha;
	bool        CloseOnESC;                          // found in CSidlScreenWnd__StoreIniInfo_x, close when ESC is pressed
	BYTE        StartAlpha;
	tagSIZE     MinClientSize;
	bool        bRightAnchoredToLeft;
	BYTE        FadeAlpha;
	UINT        BlinkFadeFreq;
	bool        bMarkedForDelete;
	CSIDLWND*   pWndFocusOther;
	void*       IconTextureAnim;
	bool        bBorder;
	bool        Locked;                              // found in CSidlScreenWnd__LoadIniInfo_x
	DWORD       BackgroundDrawType;
	void*       pTextObject;
	bool        bAction;
	bool        bClientRectChanged;
	UINT        BlinkFadeDuration;
	bool        MouseOver;                           // found in CXWnd__SetMouseOver_x
	CXStr       Tooltip;                             // found in CSidlManager__CreateLabel_x
