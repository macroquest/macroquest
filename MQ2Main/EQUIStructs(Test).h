/*****************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2005 Lax

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
******************************************************************************/
#include "ArrayClass.h"
#pragma pack(push)
#pragma pack(8)
namespace EQUIStructs
{


enum UIType
{
   UI_Unknown=-1,
   UI_Class=0,
   UI_RGB=1,
   UI_RGBText=2,//new since the patch on Jan 08 2018 Test see 0x90EC67 -eqmule
   UI_Point=3,
   UI_Size=4,
   UI_TextureInfo=5,
   UI_Frame=6,
   UI_Ui2DAnimation=7,
   UI_ButtonDrawTemplate=8,
   UI_GaugeDrawTemplate=9,
   UI_SpellGemDrawTemplate=10,
   UI_FrameTemplate=11,
   UI_ScrollbarDrawTemplate=12,
   UI_WindowDrawTemplate=13,
   UI_SliderDrawTemplate=14,
   UI_ScreenPiece=15,
   UI_StaticScreenPiece=16,
   UI_StaticAnimation=17,
   UI_StaticTintedBlendAnimation=18,
   UI_StaticText=19,
   UI_StaticFrame=20,
   UI_StaticHeader=21,
   UI_LayoutStrategy=22,
   UI_LayoutVertical=23,
   UI_LayoutHorizontal=24,
   UI_Control=25,
   UI_TemplateAssoc=26,
   UI_TemplateScreen=27,
   UI_ListboxColumn=28,
   UI_Listbox=29,
   UI_Button=30,
   UI_Gauge=31,
   UI_SpellGem=32,
   UI_HtmlComponent=33,
   UI_InvSlot=34,
   UI_EditBox=35,
   UI_Slider=36,
   UI_Label=37,
   UI_STMLBox=38,
   UI_TreeView=39,
   UI_Combobox=40,
   UI_Page=41,
   UI_TabBox=42,
   UI_LayoutBox=43,
   UI_HorizontalLayoutBox=44,
   UI_VerticalLayoutBox=45,
   UI_FinderBox=46,
   UI_TileLayoutBox=47,
   UI_NamedTemplatePiece=48,
   UI_TemplateContainer=49,
   UI_Screen=50,
   UI_SuiteDefaults=51,
   UI_Screens=52,
   UI_TopLevelWindowList=53,
   UI_HotButton=54,
};
#define MAX_INV_SLOTS 0x900
// ***************************************************************************
// Structures
// ***************************************************************************

// 10-24-2003 Lax - Massive overhaul.
// See http://macroquest.sourceforge.net/phpBB2/viewtopic.php?t=3569 for
// standards on structures to make things easier on everyone!
// -- ONLY applies to EQ structs, not MQ structs like alerts, etc.

typedef struct _EQCURRENTSELECTION {
/*0x00*/   DWORD   Unknown;
/*0x04*/   DWORD   SelectedWnd;     //address to selection in tree
/*0x08*/   DWORD   Unknownlodncrap;
/*0x0c*/   DWORD   NumberOfSlots;   //merchantslots == 79
/*0x10*/   DWORD   TextureAnim;
/*0x14*/
} EQCURRENTSELECTION, *PEQCURRENTSELECTION;

//CXWnd see B1058C in Nov  7 2016 eqgame.exe (Test) -eqmule
#define VFTABLE \
/*0x000*/ LPVOID  IsValid; \
/*0x004*/ LPVOID  vector_deleting_destructor; \
/*0x008*/ LPVOID  DrawNC; \
/*0x00c*/ LPVOID  PostDraw; \
/*0x010*/ LPVOID  PostDraw2; \
/*0x014*/ LPVOID  DrawCursor; \
/*0x018*/ LPVOID  CXWnd__OnResize; \
/*0x01c*/ LPVOID  PostDraw3; \
/*0x020*/ LPVOID  DrawBackground; \
/*0x024*/ LPVOID  DrawTooltip; \
/*0x028*/ LPVOID  DrawTooltipAtPoint; \
/*0x02c*/ LPVOID  GetMinimizedRect; \
/*0x030*/ LPVOID  DrawTitleBar; \
/*0x034*/ LPVOID  GetCursorToDisplay; \
/*0x038*/ LPVOID  HandleLButtonDown; \
/*0x03c*/ LPVOID  HandleLButtonUp; \
/*0x040*/ LPVOID  HandleLButtonHeld; \
/*0x044*/ LPVOID  HandleLButtonUpAfterHeld; \
/*0x048*/ LPVOID  HandleRButtonDown; \
/*0x04c*/ LPVOID  HandleRButtonUp; \
/*0x050*/ LPVOID  HandleRButtonHeld; \
/*0x054*/ LPVOID  HandleRButtonUpAfterHeld; \
/*0x058*/ LPVOID  HandleWheelButtonDown; \
/*0x05c*/ LPVOID  HandleWheelButtonUp; \
/*0x060*/ LPVOID  HandleMouseMove; \
/*0x064*/ LPVOID  HandleWheelMove; \
/*0x068*/ LPVOID  GetDragDropCursor; \
/*0x06c*/ LPVOID  PostDraw4; \
/*0x070*/ LPVOID  OnDragDrop; \
/*0x074*/ LPVOID  GetClickStickCursor; \
/*0x078*/ LPVOID  QueryDropOK; \
/*0x07c*/ LPVOID  OnClickStick; \
/*0x080*/ LPVOID  GetClickStickCursor2; \
/*0x084*/ LPVOID  QueryClickStickDropOK; \
/*0x088*/ LPVOID  WndNotification; \
/*0x08c*/ LPVOID  OnWndNotification; \
/*0x090*/ LPVOID  ShowWindow; /* Activate */ \
/*0x094*/ LPVOID  Deactivate; \
/*0x098*/ LPVOID  PostDraw5; \
/*0x09c*/ LPVOID  OnResize; \
/*0x0a0*/ LPVOID  OnResize2; \
/*0x0a4*/ LPVOID  Unknown0xa4; \
/*0x0a8*/ LPVOID  Unknown0xa8; \
/*0x0ac*/ LPVOID  OnMinimizeBox; \
/*0x0b0*/ LPVOID  Unknown0xb0; \
/*0x0b4*/ LPVOID  OnTileBox; \
/*0x0b8*/ LPVOID  PostDraw6; \
/*0x0bc*/ LPVOID  OnMove2; \
/*0x0c0*/ LPVOID  OnMove3; \
/*0x0c4*/ LPVOID  OnProcessFrame; /*Dofade*/ \
/*0x0c8*/ LPVOID  OnVScroll; \
/*0x0cc*/ LPVOID  OnHScroll; \
/*0x0d0*/ LPVOID  PostDraw7; \
/*0x0d4*/ LPVOID  OnMove4; \
/*0x0d8*/ LPVOID  Show; \
/*0x0dc*/ LPVOID  AboutToShow; \
/*0x0e0*/ LPVOID  AboutToHide; \
/*0x0e4*/ LPVOID  RequestDockInfo; \
/*0x0e8*/ LPVOID  GetTooltip; \
/*0x0ec*/ LPVOID  Unknown0x0ec; /*this is new and added on oct 11 2016 its just empty*/ \
/*0x0f0*/ LPVOID  HitTest; \
/*0x0f4*/ LPVOID  GetHitTestRect; \
/*0x0f8*/ LPVOID  GetInnerRect; \
/*0x0fc*/ LPVOID  GetClientRect; \
/*0x100*/ LPVOID  GetClientClipRect; \
/*0x104*/ LPVOID  GetMinSize; \
/*0x108*/ LPVOID  GetMaxSize; \
/*0x10c*/ LPVOID  GetUntileSize; \
/*0x110*/ LPVOID  IsPointTransparent; \
/*0x114*/ LPVOID  Unknown114; \
/*0x118*/ LPVOID  Unknown118; \
/*0x11c*/ LPVOID  SetDrawTemplate; \
/*0x120*/ LPVOID  Move_Rect; /*CXWnd__Move1_x*/ \
/*0x124*/ LPVOID  Move_Point; /*CXWnd__Move_x*/ \
/*0x128*/ LPVOID  SetWindowTextA; \
/*0x12c*/ LPVOID  GetChildWndAt; /*CXWnd__GetChildWndAt_x*/ \
/*0x130*/ LPVOID  GetSidlPiece; /*CSidlScreenWnd__GetSidlPiece_x*/ \
/*0x134*/ LPVOID  CSidlScreenWnd__OnPreZone1a; \
/*0x138*/ LPVOID  SetVScrollPos; \
/*0x13c*/ LPVOID  SetHScrollPos; \
/*0x140*/ LPVOID  AutoSetVScrollPos; \
/*0x144*/ LPVOID  AutoSetHScrollPos; \
/*0x148*/ LPVOID  SetAttributesFromSidl; \
/*0x14c*/ LPVOID  nullsub_1a; \
/*0x150*/ LPVOID  Unknown0x14c; \
/*0x154*/ LPVOID  nullsub_1b; \
/*0x158*/ LPVOID  GetMinClientSize; \
/*0x15c*/ LPVOID  GetMaxClientSize; \
/*0x160*/ LPVOID  CSidlScreenWnd__OnPreZone1b; \
/*0x164*/ LPVOID  UpdateLayout;
/*0x168*/

//CSidlScreenWnd see B1116C in Nov  7 2016 eqgame.exe (Test) -eqmule
typedef struct _CSIDLWNDVFTABLE {
	VFTABLE
	/*0x16c*/ LPVOID  CSidlScreenWnd__OnPreZone1c;
	/*0x170*/ LPVOID  CSidlScreenWnd__OnPreZone1d;
	/*0x170*/ LPVOID  LoadIniInfo;
	/*0x174*/ LPVOID  StoreIniInfo;
	/*0x178*/ LPVOID  EQObject__AsObject;
	/*0x17c*/ LPVOID  CTreeViewPropertySet__IsPropertySet;
	/*0x180*/
} CSIDLWNDVFTABLE, *PCSIDLWNDVFTABLE;

typedef struct _CXWNDVFTABLE {
VFTABLE
} CXWNDVFTABLE, *PCXWNDVFTABLE;

// in CChatWindow__SetChatFont see 692847 in eqgame.exe Test dated Jun 28 2016
#define EQ_CHAT_FONT_OFFSET    0x11c


#define CXW_NO_VTABLE_BEGIN \
/*0x0004*/ struct _CSIDLWND**	WindowPtrs; \
/*0x0008*/ struct _CSIDLWND*	pPrevSiblingWnd; \
/*0x000c*/ struct _CSIDLWND*	pNextSiblingWnd; \
/*0x0010*/ void*	pUnknown0x10; \
/*0x0014*/ struct _CSIDLWND*	pFirstChildWnd; \
/*0x0018*/ BYTE		Unknown0x0018[0x4];

//CXWSize
// actual size 0x1E4 in Sep 16 2015 Test (see 0x693122) - eqmule
// actual size 0x1CC in Jan 13 2016 Test (see 0x6984E8) - eqmule
// actual size 0x1C8 in Feb 10 2016 Test (see 0x699238) - eqmule
// actual size 0x1D4 in May 23 2016 Test (see 0x691812) - eqmule
// actual size 0x1DC in Jun 21 2016 Test (see 0x691E82) - eqmule
// actual size 0x1D8 in Aug  6 2018 Test (see 0x91FD2D) - eqmule
// actual size 0x1F8 in Oct  8 2018 Test (see 0x91FE4D) - eqmule
// actual size 0x1D0 in Oct 26 2018 Test (see 0x91E99D) - eqmule
// actual size 0x1E0 in Dec  4 2018 Test (see 0x92E7AD) - eqmule
// actual size 0x1E8 in Feb 12 2019 Test (see 0x92F68D) - eqmule
// actual size 0x1F0 in Feb 14 2019 Test (see 0x92E36D) - eqmule
#define CXW_NO_VTABLE \
CXW_NO_VTABLE_BEGIN \
/*0x001C*/ bool		bUseInLayoutHorizontal; \
/*0x0020*/ RECT		TransitionRect; \
/*0x0030*/ tagSIZE	MinClientSize; \
/*0x0038*/ UINT		BlinkFadeFreq; \
/*0x003C*/ void *pController; \
/*0x0040*/ UINT		BlinkFadeDuration; \
/*0x0044*/ bool		Fades; \
/*0x0048*/ struct _CXSTR*	XMLToolTip; /* found in CSidlManager__CreateLabel_x */ \
/*0x004C*/ int		VScrollPos; \
/*0x0050*/ bool		bAction; \
/*0x0054*/ void	*IconTextureAnim; \
/*0x0058*/ int		BottomOffset; \
/*0x005C*/ int		ZLayer; /* found in CXWndManager__DrawWindows_x */ \
/*0x0060*/ bool		bBorder; \
/*0x0061*/ bool		CloseOnESC;     /* found in CSidlScreenWnd__StoreIniInfo_x, close when ESC is pressed */ \
/*0x0062*/ bool		bScreenClipRectChanged; \
/*0x0064*/ struct _CSIDLWND*		pParentWindow; /* CXWnd__IsDescendantOf_x has this one, If this is NULL, coordinates are absolute... */ \
/*0x0068*/ bool		Minimized; \
/*0x0069*/ bool		bEscapableLocked; \
/*0x006C*/ DWORD	BGType;         /* found in CSidlScreenWnd__StoreIniInfo_x */ \
/*0x0070*/ bool		bClientClipRectChanged; \
/*0x0078*/ __int64		Data; \
/*0x0080*/ int		VScrollMax; \
/*0x0084*/ RECT		Location; \
/*0x0094*/ void   *TitlePiece2; \
/*0x0098*/ BYTE		TargetAlpha; \
/*0x0099*/ bool		bMarkedForDelete; \
/*0x009C*/ COLORREF DisabledBackground; \
/*0x00A0*/ DWORD	WindowStyle;    /* bit 1 - vertical scroll, bit 2 - horizontal scroll, bit 4 - title bar?, bit 8 - border */ \
/*0x00A4*/ bool		Unlockable;     /* found in CSidlScreenWnd__LoadIniInfo_x related to Locked */ \
/*0x00A8*/ struct _CXSTR*	WindowText; /* CXWnd__GetWindowTextA_x has this one */ \
/*0x00AC*/ DWORD	FadeDelay; \
/*0x00B0*/ ArrayClass2_RO<UINT> RuntimeTypes; /* Size 0x1c */ \
/*0x00C8*/ BYTE     bResizableMask; \
/*0x00CC*/ int		DeleteCount; \
/*0x00D0*/ struct _CXSTR*	Tooltip; /* found in CSidlManager__CreateLabel_x */ \
/*0x00D4*/ bool		bCaptureTitle; \
/*0x00D5*/ BYTE		FadeAlpha; \
/*0x00D8*/ DWORD  BackgroundDrawType; \
/*0x00DC*/ BYTE		StartAlpha; \
/*0x00E0*/ UINT		BlinkFadeStartTime; \
/*0x00E4*/ RECT		ClientRect; \
/*0x00F4*/ int		RightOffset; \
/*0x00F8*/ UINT		FadeDuration; \
/*0x00FC*/ int		LeftOffset; \
/*0x0100*/ bool		dShow; \
/*0x0101*/ bool		Faded; \
/*0x0104*/ RECT		OldLocation; \
/*0x0114*/ int		HScrollPos; \
/*0x0118*/ int		HScrollMax; \
/*0x011C*/ int		BlinkState; \
/*0x0120*/ RECT		ClipRectClient; \
/*0x0130*/ bool		bLeftAnchoredToLeft; \
/*0x0131*/ bool		bBottomAnchoredToTop; \
/*0x0132*/ bool bShowClickThroughMenuItem;	/*shows/hides the click through option on the window menu*/ \
/*0x0133*/ bool		bIsTransitioning; \
/*0x0134*/ bool		Locked; /* found in CSidlScreenWnd__LoadIniInfo_x */ \
/*0x0135*/ bool		bClipToParent; \
/*0x0136*/ bool		bClientRectChanged; \
/*0x0138*/ UINT		LastBlinkFadeRefreshTime; \
/*0x013C*/ bool bClickThrough; /* if true you can click through the window, well it doesnt work for our chatwindow (yet) so more work is needed to figure out why */ \
/*0x013D*/ bool		bNeedsSaving; /* will be true if you move or resize the window */ \
/*0x0140*/ RECT		IconRect; \
/*0x0150*/ void		*pLayoutStrategy; \
/*0x0154*/ DWORD	XMLIndex; \
/*0x0158*/ UINT		TransitionDuration; \
/*0x015C*/ bool		bActive; \
/*0x0160*/ RECT		ClipRectScreen; \
/*0x0170*/ void   *TitlePiece; \
/*0x0174*/ bool		bIsParentOrContextMenuWindow; \
/*0x0178*/ int		BlinkDuration; \
/*0x017C*/ bool		bHCenterTooltip; \
/*0x017D*/ bool		bTiled; \
/*0x0180*/ int		TopOffset; \
/*0x0184*/ bool		Clickable;      /* found in CChatWindow__CChatWindow_x and the button handlers */ \
/*0x0188*/ LONG		BlinkStartTimer; \
/*0x018C*/ int		managerArrayIndex; \
/*0x0190*/ bool		bMaximized; \
/*0x0191*/ bool		bBringToTopWhenClicked; \
/*0x0192*/ bool		bBorder2; \
/*0x0194*/ void	    *pFont; \
/*0x0198*/ bool		bKeepOnScreen; \
/*0x0199*/ bool bClickThroughMenuItemStatus; /* on/off */ \
/*0x019C*/ int		ParentAndContextMenuArrayIndex; \
/*0x01A0*/ COLORREF	BGColor; /* DO NOT CHNAGE THIS TO AN ARGBCOLOR, it will break the padding since its a union that has bytes in it. */ \
/*0x01A4*/ DWORD	LastTimeMouseOver; \
/*0x01A8*/ BYTE		Alpha; \
/*0x01AC*/ COLORREF	CRNormal; /* found in OnProcessFrame */ \
/*0x01B0*/ bool		bRightAnchoredToLeft; \
/*0x01B4*/ void* pTipTextObject; \
/*0x01B8*/ bool		MouseOver; /* found in CXWnd__SetMouseOver_x */ \
/*0x01BC*/ tagSIZE	MaxClientSize; \
/*0x01C4*/ bool		Enabled; \
/*0x01C8*/ struct _CSIDLWND* pWndFocusOther; \
/*0x01CC*/ UINT		TransitionStartTick; \
/*0x01D0*/ bool		bMaximizable; \
/*0x01D4*/ struct _CXSTR*	DataStr; \
/*0x01D8*/ bool		bUseInLayoutVertical; \
/*0x01D9*/ bool		bFullyScreenClipped; \
/*0x01DA*/ BYTE		FadeToAlpha; /* found in CSidlScreenWnd__StoreIniInfo_x */ \
/*0x01DC*/ void*	pTextObject; \
/*0x01E0*/ int	Transition; \
/*0x01E4*/ bool		ValidCXWnd; /* IsValid has this one */ \
/*0x01E5*/ bool		bTopAnchoredToTop; \
/*0x01E8*/ void	*DrawTemplate; \
/*0x01EC*/ BYTE Filler0x01EC[0x4];
/*0x01F0*/


#define CXW \
/*0x000*/   struct  _CXWNDVFTABLE   *pvfTable; \
CXW_NO_VTABLE \
/*0x1f0*/

typedef struct _CXWND {
CXW
} CXWND, *PCXWND;
#define GateBind          0
//CSidlScreenWnd__CSidlScreenWnd1_x
//to check do : CSidlScreenWnd*csidlwnd = (CSidlScreenWnd*)FindMQ2Window("MMTW_MerchantWnd");
//Size 0x238 in Aug 10 2017 Live exe see 5FC76D - eqmule
#define SIDL \
/*0x1F0*/ bool bControlsCreated; /*yes this REALLY is here, see 8D255E in aug 10 2017 live - eqmule*/ \
/*0x1f4*/ PCXSTR SidlText; /*found in CChatWindow__WndNotification_x*/\
/*0x1f8*/ LPVOID SidlPiece; /* CScreenPieceTemplate (important) */ \
/*0x1fc*/ ArrayClass_RO<void*>RadioGroup; /*CRadioGroup*/ \
/*0x20c*/ bool bInitVisibility; \
/*0x20d*/ bool bVisibleBeforeResize; \
/*0x210*/ int IniFlags; \
/*0x214*/ PCXSTR INIStorageName; /*found in CSidlScreenWnd__LoadSidlScreen_x*/\
/*0x218*/ int	IniVersion; \
/*0x21c*/ int	LastResX; \
/*0x220*/ int	LastResY; \
/*0x224*/ bool bLastResFullscreen; \
/*0x228*/ int  ContextMenuID; \
/*0x22c*/ PCXWND pFirstVScrollChild; \
/*0x230*/ int ContextMenuTipID; \
/*0x234*/ bool bHasActivatedFirstTimeAlert; \
/*0x238*/

#define CSW \
/*0x000*/ struct _CSIDLWNDVFTABLE* pvfTable; \
CXW_NO_VTABLE \
SIDL \

typedef struct _CSIDLWND {
CSW
} CSIDLWND, *PCSIDLWND;

typedef struct _CCONTEXTMENUVFTABLE {
VFTABLE
/*0x168*/ LPVOID CListWnd__OnHeaderClick;
/*0x16c*/ LPVOID CListWnd__DrawColumnSeparators;
/*0x170*/ LPVOID CListWnd__DrawSeparator;
/*0x174*/ LPVOID CListWnd__DrawLine;
/*0x178*/ LPVOID CListWnd__DrawHeader;
/*0x17c*/ LPVOID CListWnd__DrawItem;
/*0x180*/ LPVOID CListWnd__DeleteAll;
/*0x184*/ LPVOID CListWnd__Compare;
/*0x188*/ LPVOID CListWnd__Sort;
/*0x18c*/ LPVOID CContextMenu__ShowAt;
/*0x190*/
} CCONTEXTMENUVFTABLE, *PCCONTEXTMENUVFTABLE; 

//class CSidlManager : public CSidlManagerBase
// size 0x1D4 2019-02-12 test see 53E3D3 - eqmule
typedef struct _CSIDLMGR {
/*0x000*/    BYTE    Unknown0x000[0x130];
/*0x130*/    PVOID   pXMLDataMgr;
/*0x134*/    BYTE    Unknown0x134[0xA0];
/*0x1D4*/
} CSIDLMGR, *PCSIDLMGR;

struct DragDropInfo {
/*0xb8*/	bool bRightButton;
/*0xbc*/	PCXWND FromWnd;
/*0xc0*/	PCXWND ToWnd;
/*0xc4*/	POINT FromPoint;
/*0xcc*/	POINT ToPoint; 
/*0xd4*/	int   Code;
/*0xd8*/	void *Data;
/*0xdc*/
};
struct ClickStickInfo
{
/*0x00*/	DWORD vfTable;
/*0x04*/	PCXWND FromWnd;
/*0x08*/	PCXWND ToWnd;
/*0x0c*/	POINT FromPoint;
/*0x14*/	POINT ToPoint; 
/*0x1c*/	int   Code;
/*0x20*/	void  *Data;
/*0x24*/
};
class ControllerStuff
{
/*0x00*/	void *vfTable;
/*0x04*/	HashTable<void*, int, ResizePolicyNoShrink> Stuff;//this really isnt a HashTable I think its a variation that just stores pointers to stuff
/*0x14*/	//but for our purposes it won't matter, i don't want to spend any more time on these kind of array classes. -eqmule
};

class ControllerManager
{
public:
/*0x00*/	void* pvfTable;
/*0x04*/	ControllerStuff *pControllerStuff;
/*0x08*/	HashTable<ControllerStuff*> CStuff;
/*0x18*/
};

//Actual size 0x1b0 in Oct 19 2017 Beta (see 4C2E25) - eqmule
//this should really be renamed to EQCXWNDMGR
//becuase its a class that looks like this:
//class EQCXWndManager : CXWndManager
typedef struct _CXWNDMGR {
/******************* Begin of CXWNDMGR ***************/
/*0x000*/ LPVOID CXWNDMGR__vtable;
/*0x004*/ LPVOID CXWNDMGR__vtable2;
/*0x008*/ ArrayClass_RO<PCXWND> pWindows;
/*0x018*/ ArrayClass_RO<PCXWND> ParentAndContextMenuWindows;
/*0x028*/ ArrayClass_RO<PCXWND> TransitionWindows;
/*0x038*/ ArrayClass_RO<PCXWND> PendingDeletionWindows;
/*0x048*/ UINT TypematicKey;
/*0x04c*/ UINT LastKeyDownTime;
/*0x050*/ UINT LastMouseClickTime;//when mouse was last clicked
/*0x054*/ DWORD MouseMoveTimeStamp;//when mouse was last moved
/*0x058*/ int StrokesSent;
/*0x05c*/ int ToolTipHitTest;//this is really an enum //0 outside 1 transparent 2 client 3 minimizebox 4 tilebox 5 qmark 6 maxbox 7 closebox 8 titlebar 9 vscrollup 10 vscrolldown 11 vscroll thumb 12 vscroll pgup 13 vscroll pgdn 14 hscroll left 15 hscroll right 16 hscroll thumb 17 hscroll pgup 18 hscroll pgdn 19 border left 20 border top 21 border right 22 border bottom 23 border topleft 24 border topright 25 border bott left 26 bott right 27 left top 28 left bott 29 right top 30 right bott 31 no hit
/*0x060*/ PCSIDLWND LastClickedWindow;
/*0x064*/ PCSIDLWND MainWindow;
/*0x068*/ PCSIDLWND FocusWindow;//when you select a window its pointer shows up here
/*0x06c*/ PCSIDLWND CurrDraggedWindow;//when you drag a window its pointer shows up here
/*0x070*/ PCSIDLWND ActiveWindow;
/*0x074*/ PCSIDLWND LastMouseOver;//Current window pointer is over if this is 0 we are above MAIN Window
/*0x078*/ PCSIDLWND Tooltip;//Last Tooltip to show?
/*0x07c*/ ArrayClass_RO<PCXWND> GlobalFocusWindows;
/*0x08c*/ bool bReadingLog;
/*0x08d*/ bool bSidlManagerOwner;
/*0x090*/ int CaptureCount;
/*0x094*/ bool bMouseMoveRelative;
/*0x098*/ POINT MousePoint;//for sure 8BE7CA
/*0x0a0*/ bool bCapsLock;
/*0x0a1*/ bool KeyboardFlags[4];    // 7d-80
/*0x0a5*/ bool bChatMessage;
/*0x0a6*/ bool bDrawWindows;
/*0x0a7*/ BYTE MouseMoveFlags;
/*0x0a8*/ UINT ManagerMode;//enum but i dont have time to do it now. its like moving, sizing etc.
/*0x0ac*/ int  DecorButtonHitTest;
/*0x0b0*/ POINT MoveResize; //for sure 8BE7D6 
/*0x0b8*/ DragDropInfo DDI;//size 0x24
/*0x0dc*/ ClickStickInfo CSI;//size 0x24
/*0x100*/ int Really;
/*0x104*/ bool bModal;//for sure
/*0x108*/ UINT TTCheckTimer;//for sure
/*0x10c*/ UINT Flags;//for sure
/*0x110*/ PCXSTR ClipText;
/*0x114*/ DWORD ScreenExtentX;
/*0x118*/ DWORD ScreenExtentY;
/*0x11c*/ ArrayClass_RO<void *>  FontsArray;
/*0x12c*/ void *pfontSystem;
/*0x130*/ bool bSomething;
/*0x134*/ HWND* pGlobalHwnd;
/*0x138*/ POINT StoredMousePos;//last position Mouse was at before we moved it
/*0x140*/ bool bManagerDeletionPending;
/*0x144*/ CursorClass CC;//size 0x3c
/******************* End of CXWNDMGR ***************/
/******************* Begin of EQCXWNDMGR ***************/
/*0x180*/ ControllerStuff Stuff;//size 0x14
/*0x194*/ ControllerManager ControllerMgr;//size 0x18
/*0x1AC*/ bool Unknown0x1AC;
/******************* End of EQCXWNDMGR ***************/
/*0x1b0*/ 
} CXWNDMGR, *PCXWNDMGR;

struct _CONTENTDATA
{
	PCONTENTS pCont;
	int Unknown;
};
typedef struct _CONTENTSARRAY {
    struct _CONTENTDATA Array[1];
} CONTENTSARRAY, *PCONTENTSARRAY;

//Size is 81 see 6F48C9 in Nov 20 2018 Beta -eqmule
enum ChatFilterEnum {
	CHAT_FILTER_SAY,
	CHAT_FILTER_TELL,
	CHAT_FILTER_GROUP,
	CHAT_FILTER_RAID,
	CHAT_FILTER_GUILD,
	CHAT_FILTER_OOC,
	CHAT_FILTER_AUCTION,
	CHAT_FILTER_SHOUT,
	CHAT_FILTER_EMOTE,
	CHAT_FILTER_MELEE_YOUR_HITS,
	CHAT_FILTER_SPELLS_MINE,
	CHAT_FILTER_SKILLS,
	CHAT_FILTER_CHAT1,
	CHAT_FILTER_CHAT2,
	CHAT_FILTER_CHAT3,
	CHAT_FILTER_CHAT4,
	CHAT_FILTER_CHAT5,
	CHAT_FILTER_CHAT6,
	CHAT_FILTER_CHAT7,
	CHAT_FILTER_CHAT8,
	CHAT_FILTER_CHAT9,
	CHAT_FILTER_CHAT10,
	CHAT_FILTER_OTHER,
	CHAT_FILTER_MELEE_YOUR_MISSES,
	CHAT_FILTER_MELEE_YOU_BEING_HIT,
	CHAT_FILTER_MELEE_YOU_BEING_MISSED,
	CHAT_FILTER_MELEE_OTHERS_HITS,
	CHAT_FILTER_MELEE_OTHERS_MISSES,
	CHAT_FILTER_MELEE_MY_DEATH,
	CHAT_FILTER_MELEE_OTHER_PC_DEATH,
	CHAT_FILTER_MELEE_CRITICAL_HITS,
	CHAT_FILTER_MELEE_DISCIPLINES,
	CHAT_FILTER_MELEE_WARNINGS,
	CHAT_FILTER_MELEE_NPC_RAMPAGE,
	CHAT_FILTER_MELEE_NPC_FLURRY,
	CHAT_FILTER_MELEE_NPC_ENRAGE,
	CHAT_FILTER_SPELLS_OTHERS,
	CHAT_FILTER_SPELLS_FAILURES	,
	CHAT_FILTER_SPELLS_CRITICALS,
	CHAT_FILTER_SPELLS_WORN_OFF	,
	CHAT_FILTER_SPELLS_DD_YOURS,
	CHAT_FILTER_FOCUS_EFFECTS,
	CHAT_FILTER_RANDOM_YOUR_ROLLS,
	CHAT_FILTER_PET_MESSAGES,
	CHAT_FILTER_PET_RAMPAGE_FLURRY,
	CHAT_FILTER_PET_CRITICALS,
	CHAT_FILTER_DAMAGE_SHIELDS_YOU_ATTACKING,
	CHAT_FILTER_EXPERIENCE_MESSAGES,
	CHAT_FILTER_NPC_EMOTES,
	CHAT_FILTER_SYSTEM_MESSAGES,
	CHAT_FILTER_WHO,
	CHAT_FILTER_PET_SPELLS,
	CHAT_FILTER_PET_RESPONSES,
	CHAT_FILTER_ITEM_SPEECH,
	CHAT_FILTER_FELLOWSHIP_MESSAGES,
	CHAT_FILTER_MERCENARY_MESSAGES,
    CHAT_FILTER_PVP_MESSAGES,
    CHAT_FILTER_MELEE_YOUR_FLURRY,
	CHAT_FILTER_DEBUG,//todo: check this not 100% sure its it...
	CHAT_FILTER_MELEE_NPC_DEATH	,
    CHAT_FILTER_RANDOM_OTHERS_ROLLS,
    CHAT_FILTER_RANDOM_GROUP_RAID_ROLLS,
	CHAT_FILTER_ENVIRONMENTAL_DAMAGE_YOURS,
	CHAT_FILTER_ENVIRONMENTAL_DAMAGE_OTHERS,
	CHAT_FILTER_DAMAGE_SHIELDS_YOU_DEFENDING,
	CHAT_FILTER_DAMAGE_SHIELDS_OTHERS,
	CHAT_FILTER_EVENT_MESSAGES,
	CHAT_FILTER_OVERWRITTEN_DETRIMENTAL_SPELL_MESSAGES,
	CHAT_FILTER_OVERWRITTEN_BENEFICIAL_SPELL_MESSAGES,
	CHAT_FILTER_YOU_CANT_USE_THAT_COMMAND, //- Added chat color and filtering options for 'You can't use that command' messages.
	CHAT_FILTER_COMBAT_ABILITY_REUSE,  //- Added chat color and filtering options for combat ability and AA ability reuse time messages.
	CHAT_FILTER_SPELLS_AA_ABILITY_REUSE,
	CHAT_FILTER_ITEM_DESTROYED,
	CHAT_FILTER_SPELLS_AURAS_YOU,
	CHAT_FILTER_SPELLS_AURAS_OTHERS,
	CHAT_FILTER_SPELLS_HEALS_YOURS,
	CHAT_FILTER_SPELLS_HEALS_OTHERS,
	CHAT_FILTER_SPELLS_DOTS_YOURS,
	CHAT_FILTER_SPELLS_DOTS_OTHERS,
	CHAT_FILTER_SPELLS_SONGS,
	CHAT_FILTER_SPELLS_DD_OTHERS,
	CHAT_FILTER_ZERO_HEALS,

};
#define MAX_CHAT_FILTERS CHAT_FILTER_ZERO_HEALS
enum eContextMenuFilterIDs
{
	CONTEXT_FILTER_SAY = 100,
	CONTEXT_FILTER_TELL,
	CONTEXT_FILTER_GROUP,
	CONTEXT_FILTER_RAID,
	CONTEXT_FILTER_GUILD,
	CONTEXT_FILTER_OOC,
	CONTEXT_FILTER_AUCTION,
	CONTEXT_FILTER_SHOUT,
	CONTEXT_FILTER_EMOTE,
	CONTEXT_FILTER_MELEE_YOUR_HITS,
	CONTEXT_FILTER_SPELLS_MINE,
	CONTEXT_FILTER_SKILLS,
	CONTEXT_FILTER_CHAT1,
	CONTEXT_FILTER_CHAT2,
	CONTEXT_FILTER_CHAT3,
	CONTEXT_FILTER_CHAT4,
	CONTEXT_FILTER_CHAT5,
	CONTEXT_FILTER_CHAT6,
	CONTEXT_FILTER_CHAT7,
	CONTEXT_FILTER_CHAT8,
	CONTEXT_FILTER_CHAT9,
	CONTEXT_FILTER_CHAT10,
	CONTEXT_FILTER_OTHER,
	CONTEXT_FILTER_MELEE_YOUR_MISSES,
	CONTEXT_FILTER_MELEE_YOU_BEING_HIT,
	CONTEXT_FILTER_MELEE_YOU_BEING_MISSED,
	CONTEXT_FILTER_MELEE_OTHERS_HITS,
	CONTEXT_FILTER_MELEE_OTHERS_MISSES,
	CONTEXT_FILTER_MELEE_MY_DEATH,
	CONTEXT_FILTER_MELEE_OTHER_PC_DEATH,
	CONTEXT_FILTER_MELEE_CRITICAL_HITS,
	CONTEXT_FILTER_MELEE_DISCIPLINES,
	CONTEXT_FILTER_MELEE_WARNINGS,
	CONTEXT_FILTER_MELEE_NPC_RAMPAGE,
	CONTEXT_FILTER_MELEE_NPC_FLURRY,
	CONTEXT_FILTER_MELEE_NPC_ENRAGE,
	CONTEXT_FILTER_SPELLS_OTHERS,
	CONTEXT_FILTER_SPELLS_FAILURES	,
	CONTEXT_FILTER_SPELLS_CRITICALS,
	CONTEXT_FILTER_SPELLS_WORN_OFF	,
	CONTEXT_FILTER_SPELLS_DD_YOURS,
	CONTEXT_FILTER_FOCUS_EFFECTS,
	CONTEXT_FILTER_RANDOM_YOUR_ROLLS,
	CONTEXT_FILTER_PET_MESSAGES,
	CONTEXT_FILTER_PET_RAMPAGE_FLURRY,
	CONTEXT_FILTER_PET_CRITICALS,
	CONTEXT_FILTER_DAMAGE_SHIELDS_YOU_ATTACKING,
	CONTEXT_FILTER_EXPERIENCE_MESSAGES,
	CONTEXT_FILTER_NPC_EMOTES,
	CONTEXT_FILTER_SYSTEM_MESSAGES,
	CONTEXT_FILTER_WHO,
	CONTEXT_FILTER_PET_SPELLS,
	CONTEXT_FILTER_PET_RESPONSES,
	CONTEXT_FILTER_ITEM_SPEECH,
	CONTEXT_FILTER_FELLOWSHIP_MESSAGES,
	CONTEXT_FILTER_MERCENARY_MESSAGES,
    CONTEXT_FILTER_PVP_MESSAGES,
    CONTEXT_FILTER_MELEE_YOUR_FLURRY,
	CONTEXT_FILTER_DEBUG,//todo: check this not 100% sure its it...
	CONTEXT_FILTER_MELEE_NPC_DEATH	,
    CONTEXT_FILTER_RANDOM_OTHERS_ROLLS,
    CONTEXT_FILTER_RANDOM_GROUP_RAID_ROLLS,
	CONTEXT_FILTER_ENVIRONMENTAL_DAMAGE_YOURS,
	CONTEXT_FILTER_ENVIRONMENTAL_DAMAGE_OTHERS,
	CONTEXT_FILTER_DAMAGE_SHIELDS_YOU_DEFENDING,
	CONTEXT_FILTER_DAMAGE_SHIELDS_OTHERS,
	CONTEXT_FILTER_EVENT_MESSAGES,
	CONTEXT_FILTER_OVERWRITTEN_DETRIMENTAL_SPELL_MESSAGES,
	CONTEXT_FILTER_OVERWRITTEN_BENEFICIAL_SPELL_MESSAGES,
	CONTEXT_FILTER_YOU_CANT_USE_THAT_COMMAND, //- Added chat color and filtering options for 'You can't use that command' messages.
	CONTEXT_FILTER_COMBAT_ABILITY_REUSE,  //- Added chat color and filtering options for combat ability and AA ability reuse time messages.
	CONTEXT_FILTER_SPELLS_AA_ABILITY_REUSE,
	CONTEXT_FILTER_ITEM_DESTROYED,
	CONTEXT_FILTER_SPELLS_AURAS_YOU,
	CONTEXT_FILTER_SPELLS_AURAS_OTHERS,
	CONTEXT_FILTER_SPELLS_HEALS_YOURS,
	CONTEXT_FILTER_SPELLS_HEALS_OTHERS,
	CONTEXT_FILTER_SPELLS_DOTS_YOURS,
	CONTEXT_FILTER_SPELLS_DOTS_OTHERS,
	CONTEXT_FILTER_SPELLS_SONGS,
	CONTEXT_FILTER_SPELLS_DD_OTHERS,

	CONTEXT_FILTER_ALL_NORMAL,
	CONTEXT_FILTER_ALL_MELEE,
	CONTEXT_FILTER_ALL_SPELL,
	CONTEXT_FILTER_ALL_CHANNEL,
    CONTEXT_FILTER_ALL_RANDOM,
	CONTEXT_FILTER_ALL_DAMAGE_SHIELDS,
	CONTEXT_FILTER_ALL_ENVIRONMENTAL_DMG,
	//new timestamp menu ids goes here
	//todo check the ids.

};
// 10-27-2003 Lax
// Actual size 0x208 11-5-2003
//Size 0x29c in eqgame dated 10 Jan 2017 (see 4BADFA) -eqmule
//todo fix this struct...
typedef struct _EQCHATMGR {
/*0x000*/ struct _EQCHATWINDOW* ChatWnd[0x20];
/*0x080*/ DWORD		NumWindows;
/*0x084*/ DWORD		ActiveWindow; // CurrentActive... CChat::GetActiveChatWindow
/*0x088*/ DWORD		LockedWindow; // LockedActive... CChatManager::GetActiveChatWindow
/*0x08c*/ struct _EQCHATWINDOW* ChannelMap[MAX_CHAT_FILTERS];   // channel map
/*0x1a0*/ LPVOID	pCM_MainMenu;//these are all CContextMenu* but we LPVOID them here since its easy...
/*0x1a4*/ int		ScrollbarIndex;
/*0x1a8*/ LPVOID	pCM_LanguageMenu;
/*0x1ac*/ int		LanguageMenuIndex;
/*0x1b0*/ LPVOID	pCM_FilterMenu;
/*0x1b4*/ int		FilterMenuIndex;
/*0x1b8*/ int		ChatChannelFilterMenuIndex;
/*0x1bc*/ int		MeleeFilterSubMenuIndex;
/*0x1c0*/ int		SpellsFilterSubMenuIndex;
/*0x1c4*/ LPVOID	pCM_MeleeMenu;
/*0x1c8*/ int		MeleeFilterMenuIndex;
/*0x1cc*/ LPVOID	pCM_SpellMenu;
/*0x1d0*/ int		SpellsMenuIndex;
/*0x1d4*/ LPVOID	pCM_ChannelMenu;
/*0x1d8*/ int		ChannelMenuIndex;
/*0x1dc*/ LPVOID	pCM_DefaultChannelMenu;
/*0x1e0*/ int		DefaultChannelMenu;
/*0x1e4*/ int		DefaultChannelMenu2;
/*0x1e8*/ LPVOID	pCM_ChatChannelDefChan;
/*0x1ec*/ int		ChatChannelDefChanIndex;
/*0x1f0*/ LPVOID	pCM_YourHitsMenu;
/*0x1f4*/ int		YourHitsMenuIndex;
/*0x1f8*/ LPVOID	pCM_YourMissesMenu;
/*0x1fc*/ int		YourMissesMenuindex;
/*0x200*/ LPVOID	pCM_YouBeingHitMenu;
/*0x204*/ int		YouBeingHitMenuindex;
/*0x208*/ LPVOID	pCM_OthersHitsMenu;
/*0x20c*/ int		OthersHitsMenuindex;
/*0x210*/ LPVOID	pCM_OthersMissesMenu;
/*0x214*/ int		OthersMissesMenuindex;
/*0x218*/ LPVOID	pCM_AllContextMenu;
/*0x21c*/ int		AllContextMenuindex;
/*0x220*/ LPVOID	pCM_HitModesMenu;
/*0x224*/ int		HitModesMenuindex;
/*0x228*/ LPVOID	pCM_ReplyToMenu;
/*0x22c*/ int		ReplyToMenuindex;
/*0x230*/ LPVOID	pCM_TellFriendMenu;
/*0x234*/ int		TellFriendMenuindex;
/*0x238*/ LPVOID	pCM_TellRaidmemberMenu;
/*0x23c*/ int		TellRaidmemberMenuindex;
/*0x240*/ int		ReplyToSubIndex;
/*0x244*/ int		TellFriendSubIndex;
/*0x248*/ int		TellRaidmemberSubIndex;
/*0x24c*/ int		HitModes[0x8];
/*0x26c*/ int		DefaultChannel;
/*0x270*/ LPVOID	pCM_RandomFilterMenu;
/*0x274*/ int		RandomFilterIndex;
/*0x278*/ int		RandomFilterSubIndex;
/*0x27c*/ LPVOID	pCM_EnvironmentalDamageMenu;
/*0x280*/ int		EnvironmentalDamageIndex;
/*0x284*/ int		EnvironmentalDamageSubIndex;
/*0x288*/ LPVOID	pCM_DamageShieldsFilterMenu;
/*0x28c*/ int		DamageShieldsFilterIndex;
/*0x290*/ int		DamageShieldsFilterSubIndex;
/*0x294*/ LPVOID	pCM_BeneficialSpellsFilterMenu;
/*0x298*/ int		BeneficialSpellsFilteIndex;
/*0x29c*/
} EQCHATMGR, *PEQCHATMGR;

//CChatWindow__CChatWindow_x
//Size 0x380 see 691C2D in Aug 10 2017 Live exe -eqmule
typedef struct _EQCHATWINDOW {
/*0x000*/ struct _CSIDLWND Wnd;
/*0x238*/ struct _EQCHATMGR *ChatManager; 
/*0x23c*/ struct _CSIDLWND* InputWnd;
/*0x240*/ struct _CSIDLWND* OutputWnd;
/*0x244*/ int ChatChannel;
/*0x248*/ int ChatChannelIndex;
/*0x24c*/ CHAR TellTarget[0x40];//for sure
/*0x28c*/ int Language;
/*0x290*/ bool bIsMainChat;
/*0x291*/ bool bIsTellWnd;
/*0x294*/ int TimestampFormat;
/*0x298*/ COLORREF TimestampColor;
/*0x29c*/ bool bTimestampMatchChatColor;
/*0x2a0*/ struct _CXSTR *CommandHistory[0x28]; // see 690DAA in apr 11 2017 test
/*0x340*/ int HistoryIndex;
/*0x344*/ int HistoryLastShown;
/*0x348*/ int FontSize;//style but yeah...
/*0x34c*/ int AlwaysChathereIndex;//menu
/*0x350*/ int NamesContextMenu;//guess
/*0x354*/ int ContextMenuID;//also a guess
/*0x358*/ int ContextMenuSubID[0xa];//this is not correct but ill fix it later.
/*0x380*/
} EQCHATWINDOW, *PEQCHATWINDOW;

// actual size 0x14 10-12-2010
//I think this is correct:
//see (69FF1E) in eqgame.exe dated 2013 11 13 -eqmule
//Invslot MUST be an int
typedef struct _EQINVSLOT {
/*0x00*/    LPVOID pvfTable;        // not based on cxwnd
/*0x04*/    struct _EQINVSLOTWND *pInvSlotWnd;
/*0x08*/    DWORD Unknown0x08;
/*0x0C*/    int InvSlot;
/*0x10*/    BYTE Valid;
/*0x11*/    BYTE Unknown0x11[3];
/*0x14*/    
} EQINVSLOT, *PEQINVSLOT;

// Size 0x2418 see 534532 in Nov 06 2018 Test - eqmule
typedef struct _EQINVSLOTMGR {
/*0x0000*/    PVOID vfTable;
/*0x0004*/    struct _EQINVSLOT *SlotArray[MAX_INV_SLOTS];//size 0x2400 //see 72E00F in Nov 06 2018 Test - eqmule
/*0x2404*/    DWORD TotalSlots;
/*0x2408*/    UINT LastUpdate;
/*0x240c*/    struct _EQINVSLOT *pSelectedItem;//LastSelectedSlot
/*0x2410*/    int  Unknown0x2410;
/*0x2414*/    bool bToggleBagsOpen;
/*0x2415*/    bool bToggleBankBagsOpen;
/*0x2418*/
} EQINVSLOTMGR, *PEQINVSLOTMGR;

// onetimehero 09-17-03
// ContainerWindow
// Actual Size 0x17C old
typedef struct _EQCONTAINERWINDOW {
/*0x000*/ struct _CSIDLWND Wnd;
/*0x148*/ struct _CONTENTS*   pContents;         // Pointer to the contents of the container;
                                                 // Matches the pointer in CHARINFO.Inventory/Bank/World
/*0x14c*/ struct _CSIDLWND*   pSlots[0x0a];
/*0x000*/ struct _CSIDLWND*   pCombine;
/*0x168*/ struct _CSIDLWND*   pDone;
/*0x16c*/ struct _CSIDLWND*   pIcon;
/*0x170*/ struct _CSIDLWND*   pUnknown;
/*0x174*/ struct _CSIDLWND*   pLabel;
/*0x178*/ BYTE Unknown0x178[4];
/*0x17c*/
} EQCONTAINERWINDOW, *PEQCONTAINERWINDOW;

// Actual Size 0x98  03/15/06
typedef struct _EQ_CONTAINERWND_MANAGER {
/*0x000*/   DWORD pvfTable;                           // NOT based on CXWnd.  Contains only destructor
/*0x004*/   PEQCONTAINERWINDOW pPCContainers[0x22];   // All open containers, including World, in order of opening...
/*0x08c*/   PCONTENTS   pWorldContents;               // Pointer to the contents of the world   If NULL, world container isn't open;
/*0x090*/   DWORD dwWorldContainerID;                 // ID of container in zone, starts at one (zero?) and goes up.
/*0x094*/   DWORD dwTimeSpentWithWorldContainerOpen;  // Cumulative counter?
/*0x078*/
} EQ_CONTAINERWND_MANAGER, *PEQ_CONTAINERWND_MANAGER;

typedef struct _POINT3 {
    FLOAT X;
    FLOAT Y;
    FLOAT Z;
} POINT3, *PPOINT3;

// plazmic 08-17-03
// Map Window
typedef struct _MAPLABEL { // sizeof() = 0x38
/*0x00*/    DWORD Unknown0x0;
/*0x04*/    struct _MAPLABEL *pNext;
/*0x08*/    struct _MAPLABEL *pPrev;
/*0x0c*/    POINT3 Location;
/*0x18*/    ARGBCOLOR Color;
/*0x1c*/    DWORD Size;     //1-3;
/*0x20*/    PCHAR Label;
/*0x24*/    DWORD Layer;    //0-3;
/*0x28*/    DWORD Width;
/*0x2c*/    DWORD Height;
/*0x30*/    DWORD unk_0x2c;
/*0x34*/    DWORD unk_0x30;
} MAPLABEL, *PMAPLABEL;

typedef struct _MAPLINE { // sizeof() = 0x28 (think this might be 0x34 now)
    struct _MAPLINE *pNext;
    struct _MAPLINE *pPrev;
    POINT3 Start;
    POINT3 End;
    ARGBCOLOR Color;
    DWORD Layer;          //0-3;
} MAPLINE, *PMAPLINE;

typedef struct _EQTRADESKILLRECIPE {
/*0x00*/ DWORD Unknown0x00;
/*0x04*/ DWORD Trivial;
/*0x08*/ DWORD Unknown0x08;
/*0x0c*/ DWORD Unknown0x0c;
/*0x10*/ DWORD Unknown0x10;
/*0x14*/ CHAR  Name[0x40];
/*0x54*/ DWORD Unknown0x54;
/*0x58*/ DWORD Ingredient[0xa];     // ID# of ingredient(s)
/*0x80*/ DWORD IngredientIcon[0xa]; //Icon# of ingredient(s) (Note: 499 is blank)
} EQTRADESKILLRECIPE, *PEQTRADESKILLRECIPE;

//Size 0x3d8 (02/10/2004)
typedef struct _EQTRADESKILLWINDOW {
/*0x000*/   struct _CSIDLWND Wnd;
/*0x148*/ DWORD Unknown0x148[0x1b];  
/*0x1b4*/ PEQTRADESKILLRECIPE SearchResults[0x64]; 
/*0x344*/ DWORD    Unknown0x344;
/*0x348*/ DWORD Unknown0x348;
/*0x34c*/ DWORD Unknown0x34c;
/*0x350*/ PCONTENTS Container;
/*0x354*/ DWORD Unknown0x354;
/*0x358*/ PEQTRADESKILLRECIPE SelectedRecipe;
/*0x35c*/ DWORD Unknown0x35c;
/*0x360*/ DWORD SkillLevel;
/*0x364*/ DWORD Unknown0x364;
/*0x368*/ DWORD Unknown0x368;
/*0x36c*/ BYTE  Unknown0x36c[0x58];
/*0x3c4*/ DWORD Unknown0x3c4;
/*0x3c8*/ DWORD Unknown0x3c8;
/*0x3cc*/ BYTE  Unknonw0x3cc[0x8];
/*0x3d4*/ DWORD Unknown0x3d4;
/*0x3d8*/ DWORD Unknown0x3d8;
} EQTRADESKILLWINDOW, *PTRADESKILLWINDOW;

typedef struct _GUILDMEMBERINFO {
/*0x000*/ DWORD Unknown0x000; //pointer?
/*0x004*/ BYTE OnlineStatus;  // 00=offline, 01=online
/*0x005*/ BYTE UnknownData0x005;
/*0x006*/ BYTE UnknownData0x006;
/*0x007*/ BYTE Unknown0x007;
/*0x008*/ BYTE Unknown0x008[0x8];
/*0x010*/ CHAR Name[0x40];
/*0x050*/ DWORD Level;
/*0x054*/ DWORD Class; 
/*0x058*/ DWORD Rank;         //0=member, 1=officer, 2=leader
/*0x05c*/ FLOAT UnknownData0x05c;
/*0x060*/ CHAR PublicNote[0x80];
/*0x0e0*/ BYTE Unknown0x0e0[0x180];
/*0x260*/ WORD UnknownData0x260;
/*0x262*/ WORD UnknownData0x262;
/*0x264*/ WORD UnknownData0x264;
/*0x266*/ WORD UnknownData0x266;
} GUILDMEMBERINFO, *PGUILDMEMBERINFO;

//Size: 0x3d0 (02/18/2004)
typedef struct _EQGUILDWINDOW {
/*0x000*/ struct _CSIDLWND Wnd;
/*0x148*/ BYTE  Unknown0x148[0x4c];
/*0x194*/ BYTE Unknown0x194;
/*0x195*/ BYTE ShowOffline;                  // 01 = show offline box is checked
/*0x196*/ BYTE Unknown0x196[0x2];
/*0x198*/ struct _GUILDMEMBERINFO **pMember; // This is a pointer to the beginning of a list of pointers, 
                                             // each representing one player in the guild.  The number of 
                                             // pointers depends upon TotalMemberCount.
/*0x19c*/ DWORD TotalMemberCount;
/*0x1a0*/ DWORD Unknown0x1a0;                // 150?
/*0x1a4*/ DWORD Unknown0x1a4;                // 1?
/*0x1a8*/ DWORD TotalMemberCountAgain;
/*0x1ac*/ BYTE Unknown0x1ac[0x1c];
/*0x1c8*/ CHAR PersonalNotesFilePath[0x40];  // path to personal notes file
/*0x208*/ BYTE Unknown0x208[0x1c0];          // empty
/*0x3c8*/ DWORD Unknown0x3c8;                // 1?
/*0x3cc*/ DWORD Unknown0x3cc;                // some sort of bizaare pointer...
/*0x3d0*/
} EQGUILDWINDOW, *PEQGUILDWINDOW;

typedef struct _EQNOTESWINDOW {
/*0x000*/ struct _CSIDLWND Wnd;
/*0x148*/ BYTE  Unknown0x148[0x04];
/*0x14c*/ struct _CSIDLWND *pEditWnd;
} EQNOTESWINDOW, *PEQNOTESWINDOW;

//aSpelldisplaywi
// Actual size 0x288 Oct 27 2017 Beta see 7B56BF -eqmule
typedef struct _EQSPELLINFOWINDOW 
{ 
/*0x000*/ struct _CSIDLWND Wnd;
/*0x238*/ PVOID WindowID;
/*0x23c*/ PVOID pDuration;
/*0x240*/ struct _CSIDLWND *DisplayWnd;//pDescription
/*0x244*/ PVOID pName; 
/*0x248*/ PVOID pIcon; 
/*0x24c*/ IString2 ItemInfo;
/*0x25c*/ IString2 MoreText;
/*0x26c*/ DWORD Unknown0x264;
/*0x270*/ DWORD pTABuffIcons;
/*0x274*/ DWORD pTADragIcons;
/*0x278*/ bool bFailed;
/*0x27c*/ PVOID TextureAnim;
/*0x280*/ DWORD SpellID;
/*0x284*/ DWORD TimeStamp;
/*0x288*/ 
} EQSPELLINFOWINDOW, *PEQSPELLINFOWINDOW;

// Size: 0x1a4 (4/14/2005)
typedef struct _EQMAILWINDOW {
/*0x000*/ struct _CSIDLWND Wnd;
/*0x158  Finish... */
} EQMAILWINDOW, *PEQMAILWINDOW;

#define Fly                     0

// Actual size 0x1c4 10-9-2003
typedef struct _EQHOTBUTTONWINDOW {
/*0x000*/ struct _CSIDLWND Wnd;
/*0x148*/ BYTE Unknown0x138[0xc];
/*0x000*/ DWORD   HotButtonWndView;     //0 to 9 for the different views
/*0x14c*/ struct _CSIDLWND   *HotButtons[0x0a];//these will change when you switch page...
/*0x174*/
} EQHOTBUTTONWINDOW, *PEQHOTBUTTONWINDOW;

typedef struct _LOOTCORPSE {
/*0x000*/   BYTE    Unknown0x000;   // 03 seems very common (for NPC anyway)
/*0x001*/   CHAR    Name[0x4b];
/*0x04c*/   FLOAT   Timer;          //Uncertain the equation used here, but fairly certain it's the timer
/*0x050*/   FLOAT   X;
/*0x054*/   BYTE    Unknown0x054[0x4];
/*0x058*/   FLOAT   Y;
/*0x05c*/   FLOAT   Z;
/*0x060*/   BYTE    Unknown0x060[0x24];
/*0x084*/   DWORD   Flags;
/*0x088*/   BYTE    Unknown0x088[0x4];
/*0x08c*/   DWORD   Unknown0x08c;   //256 seems very common
/*0x090*/
// I think there might be pointers at 0x0e0..but no clue what to
} LOOTCORPSE, *PLOOTCORPSE;

// size 0x180 3-10-2004
typedef struct _EQCOMPASSWINDOW {
/*0x000*/    struct _CSIDLWND Wnd;
/*0x148*/    struct _CSIDLWND *pStrip1;
/*0x14C*/    struct _CSIDLWND *pStrip2;
// in progress.
/*0x16C*/   BOOL DrawLine;
/*0x170*/   DWORD Unknown0x170;
/*0x174*/    DWORD LineRed;
/*0x178*/    DWORD LineGreen;
/*0x17C*/    DWORD LineBlue;
/*0x180*/
} EQCOMPASSWINDOW, *PEQCOMPASSWINDOW;

// used by options window
typedef struct _EQKBASSIGN
{
/*0x00*/    struct _CXSTR *pDescription;
/*0x04*/    DWORD nAssignmentNumber;
/*0x08*/
} EQKBASSIGN, *PEQKBASSIGN;

// size 0x904 3-10-2004
typedef struct _EQOPTIONSWINDOW {
/*0x000*/    struct _CSIDLWND Wnd;
/*0x148*/
/*0x264*/ struct _EQKBASSIGN Binds[0xA1];
/*0x508*/
/*0x904*/
} EQOPTIONSWINDOW, *PEQOPTIONSWINDOW;

// size 0x28 4-24-2004 Lax
typedef struct _EQGRAPHICSENGINE {
/*0x00*/ // Graphics file handler
/*0x04*/
} EQGRAPHICSENGINE, *PEQGRAPHICSENGINE;
#define SafeXLoc 0

//CLabel__CLabel_x
//CSidlManager__CreateLabel_x has this
//size is 0x218 see 7AB209 in Oct 27 2017 Beta -eqmule
typedef struct _CLABEL {
//Begin CLABELWND
/*0x000*/ struct    _CXWND Wnd;
/*0x1f0*/ bool bNoWrap;
/*0x1f1*/ bool bAlignRight;
/*0x1f2*/ bool bAlignCenter;
/*0x1f4*/ int  xOffset;
/*0x1f8*/ bool bResizeHeightToText;
/*0x1fc*/ int Unknown0x1fc;
/*0x200*/ PCXSTR Text;
/*0x204*/ int Unknown0x204;
/*0x208*/ bool Unknown0x208;
/*0x20c*/ int Unknown0x20c;
/*0x210*/ //begin CLABEL
/*0x210*/ int EQType;//renamed from SidlPiece
/*0x214*/ int Unknown0x214;
/*0x218*/
} CLABEL, *PCLABEL;

//CButtonWnd__CButtonWnd_x
//size is 0x288 see 91F0BA in eqgame.exe Nov 07 2018 Beta - eqmule
typedef struct _CBUTTONWND {
/*0x000*/ struct    _CXWND Wnd;
/*0x01f0*/ int		MouseButtonState;
/*0x01f4*/ bool	bPicture;
/*0x01f8*/ void *pGroup;//CRadioGroup*
/*0x01fc*/ bool	bChecked;
/*0x01fd*/ bool	bMouseOverLastFrame;
/*0x0200*/ tagPOINT	DecalOffset;
/*0x0208*/ tagSIZE	DecalSize;
/*0x0210*/ COLORREF	DecalTint;//Color
/*0x0214*/ RECT		TextOffsets;
/*0x0224*/ int		TextModeBits;
/*0x0228*/ COLORREF	Mouseover;
/*0x022c*/ COLORREF	Pressed;
/*0x0230*/ COLORREF	Disabled;
/*0x0234*/ UINT		CoolDownBeginTime;
/*0x0238*/ UINT		CoolDownDuration;
/*0x023c*/ PCXSTR	Indicator;
/*0x0240*/ UINT		IndicatorVal;
/*0x0244*/ void		*pIndicatorTextObject;
/* CButtonDrawTemplate Start */
/*0x0248*/ PCXSTR Name;
/*0x024c*/ void   *Normal;//CTextureAnimation
/*0x0250*/ void   *taPressed;
/*0x0254*/ void   *Flyby;
/*0x0258*/ void   *taDisabled;
/*0x025c*/ void   *PressedFlyby;
/*0x0260*/ void   *PressedDisabled;
/*0x0264*/ void   *NormalDecal;
/*0x0268*/ void   *PressedDecal;
/*0x026c*/ void   *FlybyDecal;
/*0x0270*/ void   *DisabledDecal;
/*0x0274*/ void   *PressedFlybyDecal;
/*0x0278*/ void   *PressedDisabledDecal;
/*0x027c*/ bool		bAllowButtonClickThrough;
/*0x027d*/ bool		bCoolDownDoDelayedStart;
/*0x027e*/ bool		bIsCheckbox;
/*0x027f*/ bool		bIsDrawLasso;
/*0x0280*/ UINT		ButtonStyle;
/*0x0284*/ PCLABEL	pButtonLabel;
/*0x0288*/
} CBUTTONWND, *PCBUTTONWND;
 
typedef struct _CTEXTENTRYWND {
/*0x000*/ struct    _CXWND Wnd;
/*0x1c4*/ DWORD     CursorPos1;
/*0x13c*/ DWORD     CursorPos2; //same as above but only this needs to be set to update cursor position
/*0x140*/
} CTEXTENTRYWND, *PCTEXTENTRYWND;

typedef struct _LOOTDETAILS
{
/*0x00*/ DWORD	CorpseID;//spawnId of the corpse that has this lootitem
/*0x04*/ WORD	StackCount;
/*0x06*/ WORD	UnknownWord;
/*0x08*/ DWORD	Expiration;
/*0x0c*/ BYTE	Locked;
/*0x0d*/ CHAR	Name[0x40];
/*0x4d*/ //more data here? -eqmule
}LOOTDETAILS,*PLOOTDETAILS;
//.text:0041ECBD                 imul    eax, 84h in Apr 15 2015 test
enum eAdvLootState
{
	eAdvLootWaiting,
	eAdvLootAsk,
	eAdvLootAskAutoRoll,
	eAdvLootStop,
	eAdvLootAskCompleted,
	eAdvLootFreeGrab,
	eAdvLootFixedAskAutoRoll,
	eAdvLootFixedAskCompleted,
	eAdvLootRemoved
};
//size is 0x88 see 0x48AB44 in Dec 10 2018 live -eqmule
typedef struct _LOOTITEM
{
/*0x00*/ UINT	ItemID;
/*0x04*/ CHAR	Name[0x40];
/*0x44*/ int	IconID;
/*0x48*/ bool   bStackable;
/*0x4c*/ DWORD  MaxStack;
/*0x50*/ BYTE   NoDrop;
/*0x51*/ BYTE   Unknown0x51[0x3];
/*0x54*/ DWORD  ComboID;
/*0x58*/ DWORD  LootID;
/*0x5c*/ eAdvLootState State;
/*0x60*/ BYTE	bAutoRoll;
/*0x61*/ BYTE	ActivelyManaged; // User has the manage Window up
/*0x62*/ BYTE	ContextMenu;     // item has a context menu
/*0x63*/ BYTE	AskRandomMode; //item is in AskRandom mode
/*0x64*/ BYTE   CLootInProgress;
/*0x65*/ BYTE   PLootInProgress;
/*0x68*/ EQArray2<LOOTDETAILS>LootDetails;
/*0x7c*/ DWORD	AskTimer;
/*0x80*/ BYTE	AutoRoll;
/*0x81*/ BYTE	FG;
/*0x82*/ BYTE	Need;
/*0x83*/ BYTE	Greed;
/*0x84*/ BYTE	No;
/*0x85*/ BYTE	AlwaysNeed;
/*0x86*/ BYTE	AlwaysGreed;
/*0x87*/ BYTE	Never;
/*0x88*/
} LOOTITEM,*PLOOTITEM;

typedef struct _LOOTLIST {
/*0x000*/ BYTE	Unknown0x004[0x4];
/*0x004*/ struct _LOOTITEM *pLootItem;
/*0x008*/ LONG	 ListSize;
/*0x00c*/ LONG	 Unknown0x00c;
/*0x010*/ LONG	 Unknown0x010;
/*0x014*/ struct _CXWND	 *SharedLootList;
/*0x018*/ struct _CXWND	 *PersonalLootList;
/*0x01c*/ LONG	 Unknown0x01c;
/*0x020*/ LONG	 Unknown0x020;
/*0x024*/
} LOOTLIST,*PLOOTLIST;

//CAdvancedLootWnd__CAdvancedLootWnd_x
//size 0x308 see 4CEA5D in Nov  7 2017 Test -eqmule
typedef struct _EQADVLOOTWND {
/*0x000*/ struct _CSIDLWND     Wnd;
/*0x238*/ BYTE	Unknown0x0238[0x94];
/*0x2cc*/ struct _LOOTLIST *pCLootList;//below ref to aAdlw_applyfilt
/*0x2d0*/ struct _LOOTLIST *pPLootList;//below ref to aAdlw_cllwnd
/*0x2d4*/ DWORD		Unknown0x2d4;
/*0x2d8*/ DWORD		Unknown0x2d8;
/*0x2dc*/ DWORD		Unknown0x2dc;
/*0x2e0*/ DWORD		TotalLootCount;
/*0x2e4*/ DWORD		Unknown0x2e4;
/*0x2e8*/ DWORD		ContextMenuId;
/*0x2ec*/ DWORD		CLastStackSize;
/*0x2f0*/ BYTE		Unknown0x2f0[0x18];
/*0x308*/
} EQADVLOOTWND, *PEQADVLOOTWND;

enum ETargetType {
	eTrivialCon,
	eVeryEasyCon,
	eEasyCon,
	eFairlyEasyCon,
	eFairMatchCon,
	eDifficultCon,
	eDeadlyCon,
	eFreeTarget,
	eFreeTargetInvalid,
};
//
//.text:005FC640 ; public: __thiscall CTargetIndicator::CTargetIndicator(void)
//size 0x48 see 4BA434 in Oct 26 2015 -eqmule
typedef struct _TARGETINDICATOR
{
/*0x00*/	bool bVisible;
/*0x01*/	bool bSettingsLoaded;
/*0x04*/	PSPAWNINFO lasttarget;
/*0x04*/	PSPAWNINFO MarkedTarget[4];//Assist,FirstMarked,LastMarked
/*0x18*/	BYTE IndicatorHidden;//if this is 1 our mouse is over another window and not on the main one - shouldnt cast when this is 1
/*0x19*/	BYTE CanActivate;//if 0 the indicator is red if 1 its green, i.e. it can be activated.
/*0x1a*/	BYTE Unknown0x1a[0x2];
/*0x1c*/	DWORD TargetIndicatorSettings;//CTargetIndicatorSettings class todo: figure it out
/*0x20*/	DWORD MarkerIndicatorSettings;
/*0x24*/	ETargetType IndicatorType;//this is reliable IF you actually have a target
/*0x28*/	FLOAT SegmentLength; 
/*0x2c*/	FLOAT ControlSegmentLength; 
/*0x30*/	void *pTargetThickLine; //CThickLineInterface
/*0x34*/	void *pFreeTargetThickLine; //CThickLineInterface
/*0x38*/	void *pMarkerThickLine[4]; //CThickLineInterface
/*0x48*/
} TARGETINDICATOR,*PTARGETINDICATOR;

typedef struct _TARGETDATA
{
/*0x00*/ PSPAWNINFO	pPlayer;
/*0x04*/ FLOAT	Dist;
/*0x08*/ bool bUpdated;//not sure what this is for tbh
/*0x0c*/ 
}TARGETDATA,*PTARGETDATA;
//.text:005FE3E0 ; private: __thiscall CTargetManager::CTargetManager(void)
//size 0x1a4 see 5FE489 in Oct 26 2015 -eqmule
typedef struct _TARGETMANAGER
{
	//has no vftable
/*0x000*/ TARGETDATA CycleNPCList[0xa];//size 0xc*0xa
/*0x078*/ TARGETDATA CyclePCList[0xa];
/*0x0F0*/ TARGETDATA CycleCorpseList[0xa];
/*0x168*/ DWORD LastTargetID;
/*0x16c*/ DWORD TabTargetID;
/*0x170*/ DWORD AttackTargetID;
/*0x174*/ DWORD LastHoverUpdate;
/*0x178*/ DWORD HoverUpdateInterval;
/*0x17c*/ DWORD LastFreeTargetUpdate;
/*0x180*/ DWORD FreeTargetUpdateInterval;
/*0x184*/ DWORD PreviousTargetID;
/*0x188*/ DWORD HoverTargetID;//id of the entity our cursor is over...
/*0x18c*/ bool bFreeTargetingEnabled;
/*0x190*/ float target_ring_range; // squared for easier math
/*0x194*/ float target_ring_x; // CVector3 class, this is whats passed to castspell
/*0x198*/ float target_ring_y;
/*0x19c*/ float target_ring_z;
/*0x1a0*/ bool target_ring_good; //0=red 1=green 
/*0x1a4*/
} TARGETMANAGER, *PTARGETMANAGER;

//Jul 18 2015 -eqmule
typedef struct _ScreenVector3
{
	union {
		float x; // left to right screen coordinate
		DWORD dx;
	};
	union {
		float y; // top to bottom screen coordinate
		DWORD dy;
	};
	union {
		float z;
		DWORD dz;
	};
} ScreenVector3, *PScreenVector3;

//see ref to pinstCInventoryWnd_x in __GetGaugeValueFromEQ_x
//Nov  7 2017 Beta see 7B3022 - eqmule
typedef struct _INVENTORYWND {
/*0x0000*/ struct _CSIDLWND     Wnd;
/*0x0238*/ BYTE         Unknown0x0238[0x90];
/*0x02c8*/ __int64		VitalityCap;
/*0x02d0*/ int			AAVitalityCap;
//more
} INVENTORYWND, *PINVENTORYWND;

/******************************************** CHECKED *****************************************************************/
//everything above this line is work in progress/stuff that can be improved/checked/fixed.
//everything below it is 100% checked -eqmule

//CBazaarSearchWnd__CBazaarSearchWnd_x aBazaarsearchwn
// CBazaarSearchWnd_size: 0x92d8 (see 5408BD) in Feb 14 2019 Test - eqmule
typedef struct _BAZAARSEARCHWND {
/*0x0000*/ struct _CSIDLWND     Wnd;
/*0x0238*/ BYTE         Unknown0x0238[0x8ff8];
/*0x9230*/ void **      ppTraderData;
/*0x9234*/ DWORD        hashVal;//find in CBazaarSearchWnd__HandleBazaarMsg_x
/*0x9238*/ BYTE         Unknown0x9238[0xa0];
/*0x92d8*/
} BAZAARSEARCHWND, *PBAZAARSEARCHWND;

//CPlayerWindow__CPlayerWindow aPlayerwindow
//Note to self: cant actually find CombatState in it, so no point in looking through IDA for it, but it IS the last dword... so... until that changes, im just gonna accept it...
// CPlayerWindow_size: 0x2f0 (see 5401B0) in Feb 14 2019 Test - eqmule
typedef struct _CPLAYERWND {
/*0x0000*/ struct _CSIDLWND     Wnd;
/*0x0238*/ BYTE         Unknown0x0238[0xb4];
/*0x02ec*/ DWORD        CombatState;   // 1=debuffed, 2=combat cooldown, 3=stand, 4=sit
/*0x02f0*/
} CPLAYERWND, *PCPLAYERWND;

// CTargetWindow__CTargetWindow aTargetwindow
// CTargetWindow_size: 0x8d0 (see 54004B) in Feb 14 2019 Test - eqmule
typedef struct _CTARGETWND {
/*0x0000*/ struct  _CSIDLWND    Wnd;
/*0x0238*/ BYTE         Unknown0x0238[0x198];
/*0x03d0*/ struct _CBUTTONWND * pTargetBuff[NUM_BUFF_SLOTS]; // buff icons
/*0x0554*/ int          BuffSpellID[NUM_BUFF_SLOTS]; // 0xffffffff if no buff
/*0x06d8*/ DWORD        BuffTimer[NUM_BUFF_SLOTS];
/*0x085c*/ BYTE         Unknown0x085c[0x24];
/*0x0880*/ DWORD        Type;              // 1 = self, 4 = group member, 5 = PC, 7 = NPC
/*0x0884*/ BYTE         Unknown0x0884[0x4c];
/*0x08d0*/
} CTARGETWND, *PCTARGETWND;

// CBuffWindow__CBuffWindow aBuffwindow
// this is used for both long and shortbuffs...
// CBuffWindow_size: 0x720 (see 53FEEF) in Feb 14 2019 Test - eqmule
typedef struct _EQBUFFWINDOW {
/*0x0000*/ struct _CSIDLWND     Wnd;
/*0x0238*/ BYTE         Unknown0x0238[0xbc];
/*0x02f4*/ struct _CBUTTONWND * pBuff[0x24];    // CButton*
/*0x0384*/ BYTE         Unknown0x0384[0x210];
/*0x0594*/ DWORD        BuffId[NUM_LONG_BUFFS];
/*0x063c*/ DWORD        BuffTimer[NUM_LONG_BUFFS];
/*0x06e4*/ BYTE         Unknown0x06e4[0x28];
/*0x070c*/ DWORD        MaxLongBuffs;           //0x2a (NUM_LONG_BUFFS)
/*0x0710*/ DWORD        MaxShortBuffs;          //0x37 (NUM_SHORT_BUFFS)
/*0x0714*/ BYTE         Unknown0x0714[0xc];
/*0x0720*/
} EQBUFFWINDOW, *PEQBUFFWINDOW;

// CSpellGemWnd__CSpellGemWnd
// Individual Gems 
// CSpellGemWnd_size: 0x328 (see 7F0C2B) in Feb 14 2019 Test - eqmule
typedef struct _EQCASTSPELLGEM {
/*0x0000*/ struct _CBUTTONWND        Wnd;
/*0x0288*/ int			MouseButtonState;//correct
/*0x028c*/ bool			bChecked;
/*0x0290*/ UINT			LastRefresh;
/*0x0294*/ DWORD		SpellGemTintArray[0xb];//I dont understand why there are only 11 of these when we have 13 gems noaways, probably a bug or unused?
/*0x02b0*/ int			SpellGemAlphaArray[0xb];
/*0x02cc*/ int			Unknown0x02cc;
/*0x02f0*/ int			Unknown0x02f0;
/*0x02f4*/ int			SpellIconOffsetX;
/*0x02f8*/ int			SpellIconOffsetY;
/*0x02fc*/ DWORD        spellicon;		//if this is equal to FFFFFFFF there is no spell memmed in this slot...
/*0x0300*/ DWORD        spellstate;		//1 = cast in progress or refreshtime not met 2 means we ducked or aborted cast, 0 means its ok to cast, should really rename this to tintstage
/*0x0304*/ int			TintIndex;
/*0x0308*/ void			*SpellIconTexture;//CTextureAnimation
/*0x030c*/ void			*CustomIconTexture;//CTextureAnimation
/*0x0310*/ int			SpellSlot;
/*0x0314*/ int			Percent;
/*0x0318*/ PCXWND		TemplateName;
/*0x031c*/ void			*TemplateBG;//CTextureAnimation
/*0x0320*/ void			*TemplateHolder;//CTextureAnimation
/*0x0324*/ void			*TemplateHighlight;//CTextureAnimation
/*0x0328*/
} EQCASTSPELLGEM, *PEQCASTSPELLGEM;

//pinstCCastSpellWnd_x
// CCastSpellWnd__CCastSpellWnd aCastspellwnd
// CCastSpellWnd_size: 0x2d8 (see 5402A9) in Feb 14 2019 Test - eqmule
typedef struct _EQCASTSPELLWINDOW {
/*0x0000*/ struct _CSIDLWND     Wnd;
/*0x0238*/ BYTE         Unknown0x0238[0x14];
/*0x024c*/ struct _EQCASTSPELLGEM *     SpellSlots[NUM_SPELL_GEMS];//CSPW_Spell%d
/*0x0284*/ BYTE         Unknown0x0284[0x54];
/*0x02d8*/
} EQCASTSPELLWINDOW, *PEQCASTSPELLWINDOW;

//make sure InvSlot is a short
// CInvSlotWnd_size: 0x2d8 (see 7F0D3C) in Feb 14 2019 Test - eqmule
typedef struct _EQINVSLOTWND {
/*0x0000*/ struct _CXWND        Wnd;      //----/ actually CButtonWnd
/*0x01f0*/ BYTE         Unknown0x01f0[0x8c];
/*0x027c*/ BYTE         Unknown0x0278[0x10];
/*0x028c*/ LONG         WindowType;
											// 00 for inventory
											// 01 for bank
											// 02 for shared bank
											// 03 for trader window
											// 04 for World/Tradeskill/Combine
											// 11 for loot window
/*0x0290*/ short         InvSlot;
/*0x0292*/ short         BagSlot;
/*0x0294*/ short         GlobalSlot;
/*0x0296*/ short         RandomNum;              //no idea what this is, it changes upon login but we need it for moveitem... -eqmule
/*0x0298*/ BYTE         Unknown0x0298[0x20];
/*0x02b8*/ struct _EQINVSLOT *  pInvSlot;
/*0x02bc*/ BYTE         Unknown0x02bc[0x8];
/*0x02c4*/ BOOL         ProcessClick;
/*0x02c8*/ BYTE         Unknown0x02c8[0x10];
/*0x02d8*/
} EQINVSLOTWND, *PEQINVSLOTWND;

// CItemDisplayWindow__CItemDisplayWindow aItemdisplaywin
// CItemDisplayWindow_size: 0x630 (see 750DC2) in Feb 14 2019 Test - eqmule
typedef struct _EQITEMWINDOW {
/*0x0000*/ struct _CSIDLWND     Wnd;
/*0x0238*/ struct _CSIDLWND *Description;
/*0x023c*/ struct _CSIDLWND *Name;
/*0x0240*/ struct _CSIDLWND *IconButton;
/*0x0244*/ struct _CSIDLWND *ItemLore;
/*0x0248*/ struct _CSIDLWND *ItemDescriptionTabBox;
/*0x024c*/ struct _CSIDLWND *ItemDescriptionTab;
/*0x0250*/ struct _CSIDLWND *ItemLoreTab;
/*0x0254*/ struct _CSIDLWND *pAppearanceSocketScreen;
/*0x0258*/ CBUTTONWND *pAppearanceSocketItem;
/*0x025c*/ CBUTTONWND *pAppearanceSocketBuyButton;
/*0x0260*/ struct _CSIDLWND *pAppearanceSocketDescription;
/*0x0264*/ struct _CSIDLWND *pItemSocketScreen[6];
/*0x027c*/ CBUTTONWND *pItemSocketItemButton[6];
/*0x0294*/ struct _CSIDLWND *pItemSocketDescription[6];
/*0x02ac*/ PCXSTR       ItemInfo;//this item is placable in yards, guild yards blah blah , This item can be used in tradeskills
/*0x02b0*/ PCXSTR       WindowTitle;
/*0x02b4*/ PCXSTR       ItemAdvancedLoreText;
/*0x02b8*/ PCXSTR       ItemMadeByText;
/*0x02bc*/ PCXSTR       UnknownCXStr; // if this is NULL don't populate item data in MQ2ItemDisplay
/*0x02c0*/ BYTE         Unknown0x02c0[0x4];
/*0x02c4*/ PCXSTR       ItemInformationText;//Item Information: Placing this augment into blah blah, this armor can only be used in blah blah
/*0x02c8*/ PCONTENTS    pItem;
/*0x02cc*/ bool			bActiveItem;
/*0x02cd*/ bool			bItemTextSet;
/*0x02d0*/ void			*BuffIcons;//CTextureAnimation
/*0x02d4*/ void			*DragIcons;//CTextureAnimation
/*0x02d8*/ bool			bTaggable;
/*0x02d9*/ bool			bFailed;
/*0x02dc*/ UINT			TabCount;
/*0x02e0*/ CLABEL		*ModButtonLabel;
/*0x02e4*/ CLABEL		*RewardButtonLabel;
/*0x02e8*/ CSIDLWND		*ConvertStml;
/*0x02ec*/ CLABEL		*MadeByLabel;
/*0x02f0*/ CLABEL		*CollectedLabel;
/*0x02f4*/ CLABEL		*ScribedLabel;
/*0x02f8*/ int			Row;
/*0x02fc*/ bool			bAntiTwink;
/*0x0300*/ CBUTTONWND	*ModButton;
/*0x0304*/ CBUTTONWND	*RewardButton;
/*0x0308*/ CBUTTONWND	*PrintRealEstateItems;
/*0x030c*/ CBUTTONWND	*ConvertButton;
/*0x0310*/ bool			bCollected;
/*0x0311*/ bool			bCollectedReceived;
/*0x0314*/ int			Unknown0x030c;
/*0x0318*/ int			Unknown0x0310;
/*0x031c*/ bool			bScribed;
/*0x031d*/ bool			bScribedReceived;
/*0x031e*/ BYTE         Unknown0x031e[0x2f2];
/*0x0610*/ DWORD        Unknown0x0610;
/*0x0614*/ DWORD        Unknown0x0614;
/*0x0618*/ DWORD        Unknown0x0618;
/*0x061c*/ DWORD        Unknown0x061c;
/*0x0620*/ DWORD        Unknown0x0620;
/*0x0624*/ DWORD        Unknown0x0624;
/*0x0628*/ DWORD        Unknown0x0628;
/*0x062c*/ DWORD        ItemWndIndex;//0-5? you can have max 6 windows up I think before it starts overwriting the sixth.
/*0x0630*/
} EQITEMWINDOW, *PEQITEMWINDOW;

//CLootWnd__CLootWnd aLootwnd
// CLootWnd_size: 0x3a0 (see 540615) in Feb 14 2019 Test - eqmule
typedef struct _EQLOOTWINDOW {
/*0x0000*/ struct _CSIDLWND     Wnd;
/*0x0238*/ void *       vftable; // for CLootWnd::DialogResponse handler
/*0x023c*/ BYTE         Unknown0x023c[0x98];
/*0x02d4*/ DWORD        NumOfSlots;
/*0x02d8*/ BYTE         Unknown0x02d8[0x4];
/*0x02dc*/ struct _INVENTORYARRAY *     pInventoryArray;
/*0x02e0*/ DWORD        Size;
/*0x02e4*/ DWORD        NumOfSlots3;
/*0x02e8*/ BYTE         Unknown0x02e8[0x8];
/*0x02f0*/ BYTE         Unknown0x02f0;
/*0x02f1*/ BYTE         Unknown0x02f1;
/*0x02f2*/ BYTE         Unknown0x02f2;
/*0x02f3*/ BYTE         Unknown0x02f3;
/*0x02f4*/ struct _CSIDLWND *   LootInvWnd;
/*0x02f8*/ struct _CSILDWND *   LootSlotWnd[0x22];
/*0x0380*/ struct _CSIDLWND *   LW_CorpseName;
/*0x0384*/ struct _CSIDLWND *   DoneButton;
/*0x0388*/ struct _CSIDLWND *   BroadcastButton;
/*0x038c*/ struct _CSIDLWND *   LootAllButton;
/*0x0390*/ BYTE         Unknown0x0390[0x10];
/*0x03a0*/
} EQLOOTWINDOW, *PEQLOOTWINDOW;

// pLines address = 0x254 + 0x035c = 0x05b0 (address of pMapViewMapVfTable)
// CMapViewWnd__CMapViewWnd_x
// CMapViewWnd_size: 0x658 (see 53FD50) in Feb 14 2019 Test - eqmule
typedef struct _EQMAPWINDOW {
/*0x0000*/ struct _CSIDLWND     Wnd;
/*0x0238*/ BYTE         Unknown0x0238[0x40];
/*0x0278*/ CHAR         shortzonename[0x80];
/*0x02f8*/ BYTE         Unknown0x02f8[0x3c];
/*0x0334*/ struct _CXWND *      wnd;           // its the MVW_MapRenderArea window... found at aMvw_maprendera
/*0x0338*/ BYTE         Unknown0x0338[0x38];
/*0x0370*/ struct _CSIDLWNDVFTABLE *    pMapViewMapVfTable; // found at aMapviewmap
/*0x0374*/ BYTE         Unknown0x0364[0x264];
/*0x05d8*/ PMAPLINE     pLines;     //0x268
/*0x05dc*/ PMAPLABEL    pLabels;    //0x26c
/*0x05e0*/ BYTE         Unknown0x05e0[0x78];
/*0x0658*/
} EQMAPWINDOW, *PEQMAPWINDOW;

// 20120316 - ieatacid
// 20130819 confirmed  - eqmule
// 20160317 confirmed Size unknown - eqmule
struct merchdata {
/*0x00*/ void   *vftable;
/*0x04*/ BYTE   Unknown0x4[0x8];
/*0x0c*/ DWORD  MerchSlots;
/*0x10*/ DWORD  SelectedListItem;
/*0x14*/ DWORD Unknown0x14[4];
/*0x24*/ struct _CONTENTSARRAY *pMerchArray;
/*0x28*/ DWORD  MerchMaxSlots;
/*0x2c*/
};
//confirmed 20130819 - eqmule
struct merch_other {
merchdata *pMerchData;
void *other;
void *other2;
};
//CMerchantWnd__CMerchantWnd_x (aMerchantwnd)
// CMerchantWnd_size: 0x450 (see 540771) in Feb 14 2019 Test - eqmule
typedef struct _EQMERCHWINDOW {
/*0x0000*/ struct _CSIDLWND Wnd;
/*0x0238*/ BYTE Unknown0x0238[0x10];
/*0x0248*/ merch_other * pMerchOther;//found in CMerchantWnd__CMerchantWnd
/*0x024c*/ BYTE Unknown0x024c[0x8];
/*0x0254*/ FLOAT Markup;//found in CMerchantWnd__DisplayBuyOrSellPrice_x
/*0x0258*/ BYTE Unknown0x0258[0xc];
/*0x0264*/ DWORD SelectedSlotID;//found in CMerchantWnd__RequestBuyItem_x
/*0x0268*/ BYTE Unknown0x0268[0x1e8];
/*0x0450*/
} EQMERCHWINDOW, *PEQMERCHWINDOW;

//CPetInfoWindow__CPetInfoWindow aPetinfowindow
// CPetInfoWindow_size: 0x8d0 (see 53F78A) in Feb 14 2019 Test - eqmule
typedef struct _EQPETINFOWINDOW {
/*0x0000*/ struct _CSIDLWND     Wnd;
/*0x0238*/ DWORD PetSpawnID;//The pets SpawnID
/*0x023c*/ BYTE Unknown0x023c[0x4];
/*0x0240*/ struct _CBUTTONWND * pButton[0xe];//there are 14 buttons on the petinfowin with text that can be set to attack,none,back and so on, these are those...
/*0x0278*/ BYTE Unknown0x0278[0x8];
/*0x0280*/ struct _CBUTTONWND * pAttackButton;//if 0 its not assigned.
/*0x0284*/ struct _CBUTTONWND * pQAttackButton;//if 0 its not assigned.
/*0x0288*/ struct _CBUTTONWND * pFollowButton;//if 0 its not assigned.
/*0x028c*/ struct _CBUTTONWND * pGuardButton;//if 0 its not assigned.
/*0x0290*/ struct _CBUTTONWND * pSitButton;//if 0 its not assigned.
/*0x0294*/ struct _CBUTTONWND * pStopButton;//if 0 its not assigned.
/*0x0298*/ BYTE Unknown0x0298[0x174];
/*0x040c*/ struct _CSIDLWND *   pWnd[NUM_BUFF_SLOTS]; // buff icons?
/*0x0590*/ int Buff[NUM_BUFF_SLOTS];        // Spell ID# of each buff -- 97 total
/*0x0714*/ BYTE Unknown0x0714[0x20];
/*0x0734*/ DWORD PetBuffTimer[NUM_BUFF_SLOTS]; // duration until buff fades, in thousands of a second
/*0x08b8*/ BYTE Unknown0x08b8[0xd];
/*0x08c5*/ BYTE Sit;//0/1 is off/on
/*0x08c6*/ BYTE Stop;//0/1 is off/on
/*0x08c7*/ BYTE ReGroup;//0/1 is off/on
/*0x08c8*/ BYTE Follow;//0/1 is off/on
/*0x08c9*/ BYTE Guard;//0/1 is off/on
/*0x08ca*/ BYTE Taunt;//0/1 is off/on
/*0x08cb*/ BYTE Hold;//0/1 is off/on
/*0x08cc*/ BYTE GHold;//0/1 is off/on
/*0x08cd*/ BYTE Focus;//0/1 is off/on
/*0x08ce*/ BYTE Unknown0x08ce[0x2];
/*0x08d0*/
} EQPETINFOWINDOW, *PEQPETINFOWINDOW;

//CRaidWindow__CRaidWindow
//aClasscolorD
// CRaidWindow_size: 0x3b0 (see 53FA7B) in Feb 14 2019 Test - eqmule
typedef struct _EQRAIDWINDOW {
/*0x0000*/ struct _CSIDLWND     Wnd;
/*0x0238*/ BYTE         Unknown0x0238[0xb8];
/*0x02f0*/ DWORD        ClassColors[0x10];
/*0x0330*/ BYTE         Unknown0x0330[0x80];
/*0x03b0*/
} EQRAIDWINDOW, *PEQRAIDWINDOW;

//CTradeWnd__CTradeWnd aTradewnd
// CTradeWnd__size: 0x2f8 (see 540817) in Feb 14 2019 Test - eqmule
typedef struct _EQTRADEWINDOW {
/*0x0000*/ struct _CSIDLWND     Wnd;
/*0x0238*/ BYTE         Unknown0x0238[0xb8];
/*0x02f0*/ BYTE         HisTradeReady;
/*0x02f1*/ BYTE         MyTradeReady;
/*0x02f2*/ BYTE         TradeWndOpen;
/*0x02f3*/ BYTE         Unknown0x02f3[0x5];
/*0x02f8*/
} EQTRADEWINDOW, *PEQTRADEWINDOW;

//CFactionWnd__CFactionWnd_x aFactionwnd
// CFactionWnd__size: 0x280 (see 540963) in Feb 14 2019 Test - eqmule
typedef struct _EQFACTIONWINDOW {
/*0x0000*/ struct _CSIDLWND Wnd;
/*0x0238*/ int			Unknown0x0238;
/*0x023c*/ bool			bUnknown0x023c;
/*0x0240*/ int			Unknown0x0240;
/*0x0244*/ int			Unknown0x0244;
/*0x0248*/ int			Unknown0x0248;
/*0x024c*/ IString<char> Unknown0x024c;
/*0x025c*/ IString<char> Unknown0x025c;
/*0x026c*/ void*		StandingGaugeTemplate;//CGaugeWnd*
/*0x0270*/ void*		Categories;//CTreeView*
/*0x0274*/ void*		SearchNameInput;//CEditWnd*
/*0x0278*/ PCBUTTONWND	SearchButton;//CButtonWnd*
/*0x027c*/ void*		FactionList;//CListWnd*
/*0x0280*/
} EQFACTIONWINDOW, *PEQFACTIONWINDOW;

};
using namespace EQUIStructs;
#pragma pack(pop)