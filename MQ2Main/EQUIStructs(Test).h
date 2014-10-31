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

namespace EQUIStructs
{


enum UIType
{
   UI_Unknown=-1,
   UI_Class=0,
   UI_RGB=1,
   UI_Point=2,
   UI_Size=3,
   UI_TextureInfo=4,
   UI_Frame=5,
   UI_Ui2DAnimation=6,
   UI_ButtonDrawTemplate=7,
   UI_GaugeDrawTemplate=8,
   UI_SpellGemDrawTemplate=9,
   UI_FrameTemplate=10,
   UI_ScrollbarDrawTemplate=11,
   UI_WindowDrawTemplate=12,
   UI_SliderDrawTemplate=13,
   UI_ScreenPiece=14,
   UI_StaticScreenPiece=15,
   UI_StaticAnimation=16,
   UI_StaticTintedBlendAnimation=17,
   UI_StaticText=18,
   UI_StaticFrame=19,
   UI_StaticHeader=20,
   UI_LayoutStrategy=21,
   UI_LayoutVertical=22,
   UI_LayoutHorizontal=23,
   UI_Control=24,
   UI_TemplateAssoc=25,
   UI_TemplateScreen=26,
   UI_ListboxColumn=27,
   UI_Listbox=28,
   UI_Button=29,
   UI_Gauge=30,
   UI_SpellGem=31,
   UI_HtmlComponent=32,
   UI_InvSlot=33,
   UI_EditBox=34,
   UI_Slider=35,
   UI_Label=36,
   UI_STMLBox=37,
   UI_TreeView=38,
   UI_Combobox=39,
   UI_Page=40,
   UI_TabBox=41,
   UI_LayoutBox=42,
   UI_HorizontalLayoutBox=43,
   UI_VerticalLayoutBox=44,
   UI_FinderBox=45,
   UI_TileLayoutBox=46,
   UI_NamedTemplatePiece=47,
   UI_TemplateContainer=48,
   UI_Screen=49,
   UI_SuiteDefaults=50,
   UI_Screens=51,
   UI_TopLevelWindowList=52,
   UI_HotButton=53,
};

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

#define VFTABLE \
/*0x000*/ LPVOID  IsValid; \
/*0x004*/ LPVOID  vector_deleting_destructor; \
/*0x008*/ LPVOID  DrawNC; \
/*0x00c*/ LPVOID  PostDraw; \
/*0x010*/ LPVOID  PostDraw2; \
/*0x014*/ LPVOID  DrawCursor; \
/*0x018*/ LPVOID  nullsub0x18; \
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
/*0x08c*/ LPVOID  Unknown8c; \
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
/*0x0c4*/ LPVOID  OnProcessFrame; \
/*0x0c8*/ LPVOID  OnVScroll; \
/*0x0cc*/ LPVOID  OnHScroll; \
/*0x0d0*/ LPVOID  PostDraw7; \
/*0x0d4*/ LPVOID  OnMove4; \
/*0x0d8*/ LPVOID  Show; \
/*0x0dc*/ LPVOID  Unknown0xdc; \
/*0x0e0*/ LPVOID  Unknown0xe0; \
/*0x0e4*/ LPVOID  OnMove5; \
/*0x0e8*/ LPVOID  GetTooltip; \
/*0x0ec*/ LPVOID  HitTest; \
/*0x0f0*/ LPVOID  GetHitTestRect; \
/*0x0f4*/ LPVOID  GetInnerRect; \
/*0x0f8*/ LPVOID  GetClientRect; \
/*0x0fc*/ LPVOID  GetMinSize; \
/*0x100*/ LPVOID  GetMaxSize; \
/*0x104*/ LPVOID  GetUntileSize; \
/*0x108*/ LPVOID  IsPointTransparent; \
/*0x10c*/ LPVOID  Unknown10c; \
/*0x110*/ LPVOID  Unknown110; \
/*0x114*/ LPVOID  Unknown114; \
/*0x118*/ LPVOID  SetDrawTemplate; \
/*0x11c*/ LPVOID  Move_Rect; \
/*0x120*/ LPVOID  Move_Point; \
/*0x124*/ LPVOID  SetWindowTextA; \
/*0x128*/ LPVOID  Unknown0x128; \
/*0x12c*/ LPVOID  Unknown0x12c; \
/*0x130*/ LPVOID  Unknown0x130; \
/*0x134*/ LPVOID  SetVScrollPos; \
/*0x138*/ LPVOID  SetHScrollPos; \
/*0x13c*/ LPVOID  Unknown0x13c; \
/*0x140*/ LPVOID  Unknown0x140; \
/*0x144*/ LPVOID  SetAttributesFromSidl; \
/*0x148*/ LPVOID  nullsub_1; \
/*0x14c*/ LPVOID  Unknown0x14c; \
/*0x150*/ LPVOID  Unknown0x150; \
/*0x154*/ LPVOID  Unknown0x154; \
/*0x158*/ LPVOID  Unknown0x158; \
/*0x15c*/ LPVOID  PostDraw8; \
/*0x160*/ LPVOID  Unknown0x160; \
/*0x164*/

typedef struct _CSIDLWNDVFTABLE {
VFTABLE;
/*0x168*/ LPVOID  LoadIniInfo;
/*0x16c*/ LPVOID  StoreIniInfo;
/*0x170*/ LPVOID  Unknown0x170;
/*0x174*/ LPVOID  Unknown0x174;
/*0x178*/ LPVOID  Unknown0x178;
/*0x17c*/
} CSIDLWNDVFTABLE, *PCSIDLWNDVFTABLE; 

typedef struct _CXWNDVFTABLE {
VFTABLE;
} CXWNDVFTABLE, *PCXWNDVFTABLE; 

// in CChatWindow__CChatWindow_x checked on 20140909 test - eqmule
#define EQ_CHAT_HISTORY_OFFSET 0x274
// in CChatWindow__SetChatFont checked on 20131029 test - eqmule
#define EQ_CHAT_FONT_OFFSET    0x114

//aAmw_aggrogauge
//Jun 11 2014 test size is 1d8 see (8C071D) - eqmule
//Jul 09 2014 test size is 1c8 see (8C251D) - eqmule
//2014-08-11 test size is 1dc see (8C4C8D) - eqmule
//2014-08-21 test size is 1d0 see (8C372D) - eqmule
//2014-09-09 test size is 1e8 see (8C4F0D) - eqmule
//2014-09-18 test size is 1dc see (8C456D) - eqmule
//2014-10-24 test size is 1c4 see (8C975D) - eqmule
#define CXW_NO_VTABLE \
/*0x0004*/ void*        pUnknown0x4; \
/*0x0008*/ struct _CSIDLWND*    pNextSiblingWnd; \
/*0x000c*/ void*        pUnknown0xc; \
/*0x0010*/ struct _CSIDLWND*    pFirstChildWnd; \
/*0x0014*/ BYTE         Unknown0x0014[0x14]; \
/*0x0028*/ BYTE         Enabled; \
/*0x0029*/ BYTE         Unknown0x0029[0x7]; \
/*0x0030*/ BYTE         ValidCXWnd; /*IsValid has this one*/\
/*0x0031*/ BYTE         Unknown0x0031[0x13]; \
/*0x0044*/ BYTE         Fades; \
/*0x0045*/ BYTE         Unknown0x0045; \
/*0x0046*/ BYTE         MouseOver; /*found in CXWnd__SetMouseOver_x*/ \
/*0x0047*/ BYTE         Clickable;      /* found in CChatWindow__CChatWindow_x and the button handlers */ \
/*0x0048*/ BYTE         Unknown0x0048[0x18]; \
/*0x0060*/ DWORD        TimeMouseOver; \
/*0x0064*/ BYTE         Unknown0x0064[0x10]; \
/*0x0074*/ DWORD        WindowStyle;    /* bit 1 - vertical scroll, bit 2 - horizontal scroll, bit 4 - title bar?, bit 8 - border */ \
/*0x0078*/ DWORD        FadeDuration; \
/*0x007c*/ BYTE         Alpha; \
/*0x007d*/ BYTE         Unknown0x007d[0x3]; \
/*0x0080*/ RECT         Location; \
/*0x0090*/ BYTE         Unknown0x0090[0x8]; \
/*0x0098*/ DWORD        VScrollMax; \
/*0x009c*/ BYTE         Unknown0x009c[0x5]; \
/*0x00a1*/ BYTE         dShow; \
/*0x00a2*/ BYTE         Unknown0x00a2[0x6]; \
/*0x00a8*/ ARGBCOLOR    BGColor; \
/*0x00ac*/ BYTE         Unknown0x00ac[0x8]; \
/*0x00b4*/ DWORD        VScrollPos; \
/*0x00b8*/ BYTE         Unknown0x00b8[0x1c]; \
/*0x00d4*/ struct _CSIDLWND*    pParentWindow; /*CXWnd__IsDescendantOf_x has this one, If this is NULL, coordinates are absolute... */ \
/*0x00d8*/ struct _CXSTR*       WindowText; /*CXWnd__GetWindowTextA_x has this one*/ \
/*0x00dc*/ BYTE         Unknown0x00dc[0x8]; \
/*0x00e4*/ struct _CXSTR*       XMLToolTip; /*found in CSidlManager__CreateLabel_x*/ \
/*0x00e8*/ BYTE         Unknown0x00e8[0x4]; \
/*0x00ec*/ DWORD        UnknownCW; /*found in OnProcessFrame*/\
/*0x00f0*/ BYTE         Unknown0x00f0[0x8]; \
/*0x00f8*/ DWORD        HScrollPos; \
/*0x00fc*/ BYTE         Unknown0x00fc[0x22]; \
/*0x011e*/ BYTE         Locked; /*found in CSidlScreenWnd__LoadIniInfo_x*/ \
/*0x011f*/ BYTE         Unknown0x011f; \
/*0x0120*/ struct _CXSTR*       Tooltip; /*found in CSidlManager__CreateLabel_x*/ \
/*0x0124*/ BYTE         Unknown0x0124[0xc]; \
/*0x0130*/ DWORD        HScrollMax; \
/*0x0134*/ BYTE         Unknown0x0134[0x4]; \
/*0x0138*/ DWORD        XMLIndex; \
/*0x013c*/ BYTE         Unknown0x013c[0x3]; \
/*0x013f*/ BYTE         Unlockable;     /* found in CSidlScreenWnd__LoadIniInfo_x related to Locked */ \
/*0x0140*/ BYTE         FadeToAlpha; /*found in CSidlScreenWnd__StoreIniInfo_x*/\
/*0x0141*/ BYTE         Unknown0x0141; \
/*0x0142*/ BYTE         CloseOnESC;     /* found in CSidlScreenWnd__StoreIniInfo_x, close when ESC is pressed */ \
/*0x0143*/ BYTE         Unknown0x0143; \
/*0x0144*/ DWORD        TickCount2; \
/*0x0148*/ BYTE         Unknown0x0148; \
/*0x0149*/ BYTE         Minimized; \
/*0x014a*/ BYTE         Unknown0x014a[0x2]; \
/*0x014c*/ BYTE         Faded; \
/*0x014d*/ BYTE         Unknown0x014d[0x3]; \
/*0x0150*/ LPVOID       DrawTemplate; \
/*0x0154*/ DWORD        BGType;         /* found in CSidlScreenWnd__StoreIniInfo_x "BGType" in ini */ \
/*0x0158*/ BYTE         Unknown0x0158[0x8]; \
/*0x0160*/ RECT         OldLocation; \
/*0x0170*/ BYTE         Unknown0x0170[0x50]; \
/*0x01c0*/ DWORD        ZLayer; /*found in CXWndManager__DrawWindows_x*/ \
/*0x01c4*/ 
#define CXW \
/*0x000*/   struct  _CXWNDVFTABLE   *pvfTable; \
CXW_NO_VTABLE \
/*0x1c4*/

typedef struct _CXWND {
CXW;
} CXWND, *PCXWND;
#define GateBind          0
//updated from Oct 24 2014 test exe - eqmule
#define CSW \
/*0x000*/ struct _CSIDLWNDVFTABLE* pvfTable; \
CXW_NO_VTABLE; \
/*0x1c4*/ union { \
                        struct _CXSTR* SidlText; /*found in CChatWindow__WndNotification_x*/\
                        DWORD Items; \
                }; \
/*0x1c8*/ union { \
                        struct _CXSTR* SidlScreen; \
                        DWORD SlotID; \
                }; \
/*0x1cc*/ LPVOID SidlPiece; /* CScreenPieceTemplate (important) */ \
/*0x1d0*/ union { /*find in CSidlScreenWnd__dCSidlScreenWnd_x*/ \
                struct { \
                        BYTE Checked; \
                        BYTE Highlighted; \
                        BYTE Unused0x1d2[0x2]; \
                }; \
                DWORD MaxChars; \
        }; \
/*0x1d4*/ DWORD TextureAnim; \
/*0x1d8*/ struct  _CXSTR* InputText; /*found in CChatWindow__CChatWindow_x*/\
/*0x1dc*/ DWORD Selector; /*found in CSidlScreenWnd__CSidlScreenWnd1_x*/\
/*0x1e0*/ DWORD PushToSelector; /*found in CSidlScreenWnd__LoadIniInfo_x*/\
/*0x1e4*/ DWORD EnableINIStorage; /*found in CSidlScreenWnd__LoadSidlScreen_x*/\
/*0x1e8*/ union { \
                struct _CXSTR* INIStorageName; /*found in CSidlScreenWnd__LoadSidlScreen_x*/\
                struct _EQINVSLOT* pEQInvSlot; \
        }; \
/*0x1ec*/ BYTE  Unknown0x1ec[0x10];  \
/*0x1fc*/ LPVOID ContextMenu; /* CTextureAnimation */ \
/*0x200*/ DWORD Unknown0x200; /* CTextureAnimation */ \
/*0x204*/ DWORD Unknown0x204; /* CTextureAnimation */ \
/*0x208*/ DWORD Unknown0x208; \
/*0x20c*/

typedef struct _CSIDLWND {
CSW;
} CSIDLWND, *PCSIDLWND;

// size 0x298  09-03-2008
typedef struct _CSIDLMGR {
/*0x000*/    BYTE    Unknown0x000[0x144];
/*0x144*/    PVOID   pXMLDataMgr;
/*0x148*/    BYTE    Unknown0x11c[0x150];
/*0x298*/
} CSIDLMGR, *PCSIDLMGR;

//11-6-2003 lax
//Actual size 0x140 11-11-09 - ieatacid
typedef struct _CXWNDMGR {
/*0x000*/ LPVOID CXWNDMGR__vtable;
/*0x004*/ DWORD Count;
/*0x008*/ struct _CSIDLWND **pWindows;
/*0x00c*/ BYTE Unknown0x00C[0x91];
/*0x09d*/ bool KeyboardFlags[4];    // 7d-80
/*0x0a1*/ CHAR Unknown0x0a1[0x6b];
/*0x10c*/ DWORD ScreenExtentX;
/*0x110*/ DWORD ScreenExtentY;
/*0x114*/ DWORD Unknown;
/*0x118*/ DWORD font_list_ptr;
/*0x11c*/ BYTE Unknown0x11c[0x24];
/*0x140*/ 
} CXWNDMGR, *PCXWNDMGR;


typedef struct _CONTENTSARRAY {
    struct _CONTENTS* Array[1];
} CONTENTSARRAY, *PCONTENTSARRAY;

// 10-27-2003 Lax
// Actual size 0x208 11-5-2003
typedef struct _EQCHATMGR
{
/*0x000*/ struct _EQCHATWINDOW* ChatWnd[0x20];
/*0x080*/ DWORD NumWindows;
/*0x084*/ DWORD ActiveWindow; // CChat::GetActiveChatWindow
/*0x088*/ DWORD LockedWindow; // CChatManager::GetActiveChatWindow
/*0x08c*/ DWORD Unknown0x08c;
/*0x090*/ struct _EQCHATWINDOW* ChannelMap[0x20];   // channel map
/*0x110*/ BYTE  Unknown0x110[0x28];
/*0x138*/ DWORD Unknown0x138;
/*0x13c*/ DWORD Unknown0x13c;
/*0x140*/ DWORD Unknown0x140;
/*0x144*/ LPVOID ChatMenu;
/*0x148*/ DWORD Unknown0x148;
/*0x14c*/ DWORD Unknown0x14c;
/*0x150*/ DWORD Unknown0x150;
/*0x154*/ DWORD Unknown0x154;
/*0x158*/ LPVOID MeleeMenu;
/*0x15c*/ DWORD Unknown0x15c;
/*0x160*/ LPVOID SpellMenu;
/*0x164*/ DWORD Unknown0x164;
/*0x168*/ DWORD Unknown0x168;
/*0x16c*/ LPVOID ChannelMenu;
/*0x170*/ LPVOID ChatMenu2;
/*0x174*/ LPVOID FilterMenu;
/*0x178*/ DWORD Unknown0x178;
/*0x17c*/ DWORD Unknown0x17c;
/*0x180*/ DWORD Unknown0x180;
/*0x184*/ LPVOID HitsModeMenu;
/*0x188*/ LPVOID MeleeMenu2;
/*0x18c*/ LPVOID HitsModeMenu2;
/*0x190*/ DWORD Unknown0x190;
/*0x194*/ LPVOID HitsModeMenu3;
/*0x198*/ DWORD Unknown0x198;
/*0x19c*/ LPVOID HitsModeMenu4;
/*0x1a0*/ DWORD Unknown0x1a0;
/*0x1a4*/ LPVOID HitsModeMenu5;
/*0x1a8*/ DWORD Unknown0x1a8;
/*0x1ac*/ LPVOID HitsModeMenu6;
/*0x1b0*/ DWORD Unknown0x1b0;
/*0x1b4*/ DWORD Unknown0x1b4; // CChatManager__UpdateTellMenus
/*0x1b8*/ DWORD Unknown0x1b8;
/*0x1bc*/ DWORD Unknown0x1bc; // CChatManager__UpdateTellMenus
/*0x1c0*/ DWORD Unknown0x1c0;
/*0x1c4*/ DWORD Unknown0x1c4; // CChatManager__UpdateTellMenus // raid
/*0x1c8*/ DWORD Unknown0x1c8;
/*0x1cc*/ DWORD Unknown0x1cc; // CChatManager__UpdateTellMenus
/*0x1d0*/ DWORD Unknown0x1d0; // CChatManager__UpdateTellMenus
/*0x1d4*/ DWORD Unknown0x1d4; // CChatManager__UpdateTellMenus
/*0x1d8*/ DWORD Unknown0x1d8;
/*0x1dc*/ DWORD Unknown0x1dc;
/*0x1e0*/ DWORD Unknown0x1e0;
/*0x1e4*/ BYTE  Unknown0x1e4[0x1c];
/*0x200*/ DWORD Unknown0x200;
/*0x204*/ DWORD Unknown0x204;
/*0x208*/
} EQCHATMGR, *PEQCHATMGR;

// Actual size 0x26c 02-14-2007
// 10-27-2003 Lax
typedef struct _EQCHATWINDOW
{
/*0x000*/ struct _CSIDLWND Wnd;
/*0x214*/ struct _EQCHATMGR *ChatManager; 
/*0x218*/ struct _CSIDLWND* InputWnd;
/*0x21c*/ struct _CSIDLWND* OutputWnd;
/*0x220*/ DWORD Unknown0x154;
/*0x224*/ DWORD Unknown0x158;       // need to update locations..
/*0x228*/ BYTE Unknown0x148;
/*0x229*/ BYTE Unknown0x149[0x3f];
/*0x268*/ DWORD Unknown0x188;
/*0x26c*/ DWORD Unknown0x18c;
/*0x270*/ struct _CXSTR *CommandHistory[0x28]; // ->0x198
/*0x310*/ DWORD Unknown0x230;       // CChatWindow::HistoryBack/forward .. maybe total or current history lines
/*0x314*/ DWORD Unknown0x234;       // CChatWindow::HistoryBack/forward .. maybe total or current history lines
/*0x318*/ DWORD FontSize;
/*0x268*/ DWORD Unknown0x23C;
/*0x26c*/
} EQCHATWINDOW, *PEQCHATWINDOW;

// actual size 0x14 10-12-2010
//I think this is correct:
//see (69FF1E) in eqgame.exe dated 2013 11 13 -eqmule
typedef struct _EQINVSLOT {
/*0x00*/    LPVOID pvfTable;        // not based on cxwnd
/*0x04*/    struct _EQINVSLOTWND *pInvSlotWnd;
/*0x08*/    DWORD Unknown0x08;
/*0x0C*/    DWORD InvSlot;
/*0x10*/    BYTE Valid;
/*0x11*/    BYTE Unknown0x11[3];
/*0x14*/    
} EQINVSLOT, *PEQINVSLOT;

// actual size 0x2014 10-12-2010
// confirmed (size) 2013 dec 10 eqgame.exe at 497E7A -eqmule
// confirmed 2014-03-31 - eqmule
typedef struct _EQINVSLOTMGR {
/*0x0000*/    DWORD Unknown0x0000;
/*0x0004*/    struct _EQINVSLOT *SlotArray[0x800];
/*0x2004*/    DWORD TotalSlots;
/*0x2008*/    DWORD Unknown0x2008;
/*0x200c*/    struct _EQINVSLOT *pSelectedItem;
/*0x2010*/    DWORD Unknown0x2010;
/*0x2014*/
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

// Actual size 0x1c8 07-09-2008
typedef struct _EQSPELLINFOWINDOW 
{ 
/*0x000*/ struct _CSIDLWND Wnd;
/*0x208*/ PVOID Unknown0x190;
/*0x20c*/ PVOID Unknown0x194;
/*0x210*/ struct _CSIDLWND *DisplayWnd;
/*0x214*/ PVOID Unknown0x19c; 
/*0x218*/ PVOID Unknown0x1a0; 
/*0x21c*/ PCXSTR ItemInfo;
/*0x220*/ PVOID Unknown0x1a8;
/*0x224*/ DWORD Unknown0x1ac;
/*0x228*/ DWORD Unknown0x1b0;
/*0x22c*/ DWORD Unknown0x1b4;
/*0x230*/ DWORD Unknown0x1b8;
/*0x234*/ PVOID TextureAnim;
/*0x238*/ DWORD SpellID;
/*0x23c*/ DWORD TimeStamp;
/*0x240*/ 
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

typedef struct _CBUTTONWND {
/*0x000*/ struct    _CXWND Wnd;
/*0x1c4*/ BYTE      Unknown[0x4];
/*0x1c8*/ BYTE      State;        //1=down 0=up
/*0x1c9*/ BYTE      Unknown0x1c9; //something to do with State
/*0x1ca*/ BYTE      Unknown0x1ca[0x12];
/*0x1dc*/ ARGBCOLOR Color;
/*0x1e0*/
} CBUTTONWND, *PCBUTTONWND;
 
typedef struct _CTEXTENTRYWND {
/*0x000*/ struct    _CXWND Wnd;
/*0x1c4*/ DWORD     CursorPos1;
/*0x13c*/ DWORD     CursorPos2; //same as above but only this needs to be set to update cursor position
/*0x140*/
} CTEXTENTRYWND, *PCTEXTENTRYWND;

typedef struct _CLABELWND {
/*0x000*/ struct    _CXWND Wnd;
/*0x1c4*/ BYTE      Unknown[0x8];
/*0x1cc*/ DWORD     SidlPiece;
/*0x1d0*/
} CLABELWND, *PCLABELWND;

/******************************************** CHECKED *****************************************************************/
//everything above this line is work in progress/stuff that can be improved/checked/fixed.
//everything below it is 100% checked -eqmule

//CBazaarSearchWnd__CBazaarSearchWnd aBazaarsearchwn
// Actual Size: 0x92a8 (see 49B573) in Oct 24 2014 test - eqmule
typedef struct _BAZAARSEARCHWND {
/*0x0000*/ struct _CSIDLWND     Wnd;
/*0x020c*/ BYTE         Unknown0x020c[0x8ff8];
/*0x9204*/ void **      ppTraderData;
/*0x9208*/ DWORD        hashVal;//find in CBazaarSearchWnd__HandleBazaarMsg_x
/*0x920c*/ BYTE         Unknown0x920c[0x9c];
/*0x92a8*/
} BAZAARSEARCHWND, *PBAZAARSEARCHWND;

//CPlayerWindow__CPlayerWindow aPlayerwindow
//Note to self: cant actually find CombatState in it, so no point in looking through IDA for it, but it IS the last dword... so... until that changes, im just gonna accept it...
// Actual Size: 0x2c4 (see 49AEAE) in Oct 24 2014 test - eqmule
typedef struct _CPLAYERWND {
/*0x0000*/ struct _CSIDLWND     Wnd;
/*0x020c*/ BYTE         Unknown0x020c[0xb4];
/*0x02c0*/ DWORD        CombatState;   // 1=debuffed, 2=combat cooldown, 3=stand, 4=sit
/*0x02c4*/
} CPLAYERWND, *PCPLAYERWND;

// CTargetWindow__CTargetWindow aTargetwindow
// Actual Size: 0x8a0 (see 49AD42) in Oct 24 2014 test - eqmule
typedef struct _CTARGETWND {
/*0x0000*/ struct  _CSIDLWND    Wnd;
/*0x020c*/ BYTE         Unknown0x020c[0x198];
/*0x03a4*/ struct _CBUTTONWND * pTargetBuff[NUM_BUFF_SLOTS]; // buff icons
/*0x0528*/ int          BuffSpellID[NUM_BUFF_SLOTS]; // 0xffffffff if no buff
/*0x06ac*/ DWORD        BuffTimer[NUM_BUFF_SLOTS];
/*0x0830*/ BYTE         Unknown0x0830[0x24];
/*0x0854*/ DWORD        Type;              // 1 = self, 4 = group member, 5 = PC, 7 = NPC
/*0x0858*/ BYTE         Unknown0x0858[0x48];
/*0x08a0*/
} CTARGETWND, *PCTARGETWND;

// CBuffWindow__CBuffWindow aBuffwindow
// this is used for both long and shortbuffs...
// Actual Size: 0x6f4 (see 49ABD6) in Oct 24 2014 test - eqmule
typedef struct _EQBUFFWINDOW {
/*0x0000*/ struct _CSIDLWND     Wnd;
/*0x020c*/ BYTE         Unknown0x020c[0xbc];
/*0x02c8*/ struct _CBUTTONWND * pBuff[0x24];    // CButton*
/*0x0358*/ BYTE         Unknown0x0358[0x210];
/*0x0568*/ DWORD        BuffId[NUM_LONG_BUFFS];
/*0x0610*/ DWORD        BuffTimer[NUM_LONG_BUFFS];
/*0x06b8*/ BYTE         Unknown0x06b8[0x28];
/*0x06e0*/ DWORD        MaxLongBuffs;           //0x2a (NUM_LONG_BUFFS)
/*0x06e4*/ DWORD        MaxShortBuffs;          //0x37 (NUM_SHORT_BUFFS)
/*0x06e8*/ BYTE         Unknown0x06e8[0xc];
/*0x06f4*/
} EQBUFFWINDOW, *PEQBUFFWINDOW;

// CSpellGemWnd__CSpellGemWnd
// Individual Gems 
// Actual Size: 0x2e4 (see 76E038) in Oct 24 2014 test - eqmule
typedef struct _EQCASTSPELLGEM {
/*0x0000*/ struct    _CXWND     Wnd;
/*0x01c4*/ BYTE         Unknown0x01c4[0x44];
/*0x0208*/ DWORD        TimeStamp;
/*0x020c*/ DWORD        RecastTime;
/*0x0210*/ BYTE         Unknown0x0210[0xa8];
/*0x02b8*/ DWORD        spellicon;       //if this is equal to FFFFFFFF there is no spell memmed in this slot...
/*0x02bc*/ DWORD        spellstate;      // 1 = cast in progress or refreshtime not met 2 means we ducked or aborted cast, 0 means its ok to cast
/*0x02c0*/ BYTE         Unknown0x02c0[0x24];
/*0x02e4*/
} EQCASTSPELLGEM, *PEQCASTSPELLGEM;

//pinstCCastSpellWnd_x
// CCastSpellWnd__CCastSpellWnd aCastspellwnd
// Actual Size: 0x29c (see 49AFC2) in Oct 24 2014 test - eqmule
typedef struct _EQCASTSPELLWINDOW {
/*0x0000*/ struct _CSIDLWND     Wnd;
/*0x020c*/ BYTE         Unknown0x020c[0x14];
/*0x0220*/ struct _EQCASTSPELLGEM   *   SpellSlots[NUM_SPELL_GEMS];//CSPW_Spell%d
/*0x0250*/ BYTE         Unknown0x0250[0x4c];
/*0x029c*/
} EQCASTSPELLWINDOW, *PEQCASTSPELLWINDOW;

// Actual Size: 0x298 (see 76E149) in Oct 24 2014 test - eqmule
typedef struct _EQINVSLOTWND {
/*0x0000*/ struct _CXWND        Wnd;      //----/ actually CButtonWnd
/*0x01c4*/ BYTE         Unknown0x01c4[0x88];
/*0x024c*/ BYTE         Unknown0x024c[0x4];
/*0x0250*/ LONG         WindowType;        // ieatacid has this as InventoryType
									// 00 for inventory
                                    // 01 for bank
                                    // 02 for shared bank
                                    // 03 for trader window
                                    // 04 for World/Tradeskill/Combine
                                    // 11 for loot window
/*0x0254*/ WORD         InvSlot;
/*0x0256*/ WORD         BagSlot;
/*0x0258*/ WORD         GlobalSlot;
/*0x025a*/ WORD         RandomNum;              //no idea what this is, it changes upon login but we need it for moveitem... -eqmule
/*0x025c*/ BYTE         Unknown0x025c[0x20];
/*0x027c*/ struct _EQINVSLOT *  pInvSlot;
/*0x0280*/ BYTE         Unknown0x0280[0x8];
/*0x0288*/ BOOL         ProcessClick;
/*0x028c*/ BYTE         Unknown0x028c[0xc];
/*0x0298*/
} EQINVSLOTWND, *PEQINVSLOTWND;

// CItemDisplayWindow__CItemDisplayWindow aItemdisplaywin
// Actual Size: 0x5ec (see 6B85BF) in Oct 24 2014 test - eqmule
typedef struct _EQITEMWINDOW {
/*0x0000*/ struct _CSIDLWND     Wnd;
/*0x020c*/ struct _CSIDLWND *   DisplayWnd;
/*0x0210*/ BYTE         Unknown0x0210[0x70];
/*0x0280*/ PCXSTR       ItemInfo;
/*0x0284*/ PCXSTR       WindowTitle;
/*0x0288*/ BYTE         Unknown0x0288[0x8];
/*0x0290*/ PCXSTR       UnknownCXStr; // if this is NULL don't populate item data in MQ2ItemDisplay
/*0x0294*/ BYTE         Unknown0x0294[0x8];
/*0x029c*/ PCONTENTS    pItem;
/*0x02a0*/ BYTE         Unknown0x02a0[0x34c];
/*0x05ec*/
} EQITEMWINDOW, *PEQITEMWINDOW;

//CLootWnd__CLootWnd aLootwnd
// Actual Size: 0x390 (see 49B345) in Oct 24 2014 test - eqmule
typedef struct _EQLOOTWINDOW {
/*0x0000*/ struct _CSIDLWND     Wnd;
/*0x020c*/ void *       vftable; // for CLootWnd::DialogResponse handler
/*0x0210*/ BYTE         Unknown0x0210[0x98];
/*0x02a8*/ DWORD        NumOfSlots;
/*0x02ac*/ BYTE         Unknown0x02ac[0x4];
/*0x02b0*/ struct _INVENTORYARRAY *     pInventoryArray;
/*0x02b4*/ DWORD        NumOfSlots2;
/*0x02b8*/ DWORD        NumOfSlots3;
/*0x02bc*/ BYTE         Unknown0x02bc[0x24];
/*0x02e0*/ BYTE         Unknown0x02e0;
/*0x02e1*/ BYTE         LootAll;
/*0x02e2*/ BYTE         Unknown0x02e2;
/*0x02e3*/ BYTE         Unknown0x02e3;
/*0x02e4*/ struct _CSIDLWND *   LootInvWnd;
/*0x02e8*/ struct _CSILDWND *   LootSlotWnd[0x22];
/*0x0370*/ struct _CSIDLWND *   LW_CorpseName;
/*0x0374*/ struct _CSIDLWND *   DoneButton;
/*0x0378*/ struct _CSIDLWND *   BroadcastButton;
/*0x037c*/ struct _CSIDLWND *   LootAllButton;
/*0x0380*/ BYTE         Unknown0x0380[0x10];
/*0x0390*/
} EQLOOTWINDOW, *PEQLOOTWINDOW;

// pLines address = 0x254 + 0x035c = 0x05b0 (address of pMapViewMapVfTable)
// CMapViewWnd__CMapViewWnd_x
// Actual Size: 0x5fc (see 49AA37) in Oct 24 2014 test - eqmule
typedef struct _EQMAPWINDOW {
/*0x0000*/ struct _CSIDLWND     Wnd;
/*0x020c*/ BYTE         Unknown0x020c[0x40];
/*0x024c*/ CHAR         shortzonename[0x20];
/*0x026c*/ BYTE         Unknown0x026c[0x9c];
/*0x0308*/ struct _CXWND  *     wnd;           // its the MVW_MapRenderArea window... found at aMvw_maprendera
/*0x030c*/ BYTE         Unknown0x030c[0x38];
/*0x0344*/ struct _CSIDLWNDVFTABLE    * pMapViewMapVfTable; // found at aMapviewmap
/*0x0348*/ BYTE         Unknown0x0348[0x238];
/*0x0580*/ PMAPLINE     pLines;     //0x23c
/*0x0584*/ PMAPLABEL    pLabels;    //0x240
/*0x0588*/ BYTE         Unknown0x0588[0x74];
/*0x05fc*/
} EQMAPWINDOW, *PEQMAPWINDOW;

// 20120316 - ieatacid
// 20130819 confirmed  - eqmule
struct merchdata {
/*0x00*/ void   *vftable;
/*0x04*/ BYTE   Unknown0x4[0xc];
/*0x10*/ DWORD  MerchSlots;
/*0x14*/ DWORD  Unknown0x14;
/*0x18*/ struct _CONTENTSARRAY *pMerchArray;
/*0x1c*/ DWORD  MerchMaxSlots;
/*0x20*/
};

struct merch_other {
    merchdata *pMerchData;
    void *other;
    void *other2;
};

//CMerchantWnd__CMerchantWnd (aMerchantwnd)
// Actual Size: 0x2a8 (see 49B45F) in Oct 24 2014 test - eqmule
typedef struct _EQMERCHWINDOW {
/*0x0000*/ struct _CSIDLWND     Wnd;
/*0x020c*/ BYTE         Unknown0x020c[0x10];
/*0x021c*/ merch_other * pMerchOther;//found in CMerchantWnd__CMerchantWnd
/*0x0220*/ BYTE         Unknown0x0220[0x8];
/*0x0228*/ FLOAT        Markup;//found in CMerchantWnd__DisplayBuyOrSellPrice_x
/*0x022c*/ BYTE         Unknown0x022c[0xc];
/*0x0238*/ DWORD        SelectedSlotID;//found in CMerchantWnd__RequestBuyItem_x
/*0x023c*/ BYTE         Unknown0x023c[0x6c];
/*0x02a8*/
} EQMERCHWINDOW, *PEQMERCHWINDOW;

//CPetInfoWindow__CPetInfoWindow aPetinfowindow
// Actual Size: 0x90c (see 49A472) in Oct 24 2014 test - eqmule
typedef struct _EQPETINFOWINDOW {
/*0x0000*/ struct _CSIDLWND     Wnd;
/*0x020c*/ BYTE Unknown0x020c[0x8];
/*0x0214*/ DWORD PetSpawnID;//The pets SpawnID
/*0x0218*/ BYTE Unknown0x0218[0x8];
/*0x0220*/ struct _CBUTTONWND * pButton[0xe];//there are 14 buttons on the petinfowin with text that can be set to attack,none,back and so on, these are those...
/*0x0258*/ BYTE         Unknown0x0258[0x8];
/*0x0260*/ struct _CBUTTONWND * pAttackButton;//if 0 its not assigned.
/*0x0264*/ struct _CBUTTONWND * pQAttackButton;//if 0 its not assigned.
/*0x0268*/ struct _CBUTTONWND * pFollowButton;//if 0 its not assigned.
/*0x026c*/ struct _CBUTTONWND * pGuardButton;//if 0 its not assigned.
/*0x0270*/ struct _CBUTTONWND * pSitButton;//if 0 its not assigned.
/*0x0274*/ struct _CBUTTONWND * pStopButton;//if 0 its not assigned.
/*0x0278*/ BYTE         Unknown0x0278[0x1bc];
/*0x0434*/ struct _CSIDLWND *   pWnd[NUM_BUFF_SLOTS]; // buff icons?
/*0x05b8*/ int          Buff[NUM_BUFF_SLOTS];        // Spell ID# of each buff -- 97 total
/*0x073c*/ BYTE         Unknown0x073c[0x20];
/*0x075c*/ DWORD        PetBuffTimer[NUM_BUFF_SLOTS]; // duration until buff fades, in thousands of a second
/*0x08e0*/ BYTE         Unknown0x08e0[0x1f];
/*0x08ff*/ BYTE         Sit;//0/1 is off/on
/*0x0900*/ BYTE         Stop;//0/1 is off/on
/*0x0901*/ BYTE         ReGroup;//0/1 is off/on
/*0x0902*/ BYTE         Follow;//0/1 is off/on
/*0x0903*/ BYTE         Guard;//0/1 is off/on
/*0x0904*/ BYTE         Taunt;//0/1 is off/on
/*0x0905*/ BYTE         Hold;//0/1 is off/on
/*0x0906*/ BYTE         GHold;//0/1 is off/on
/*0x0907*/ BYTE         Focus;//0/1 is off/on
/*0x0908*/ BYTE         Unknown0x0908[0x4];
/*0x090c*/
} EQPETINFOWINDOW, *PEQPETINFOWINDOW;

//CRaidWindow__CRaidWindow
//aClasscolorD
// Actual Size: 0x37c (see 49A765) in Oct 24 2014 test - eqmule
typedef struct _EQRAIDWINDOW {
/*0x0000*/ struct _CSIDLWND     Wnd;
/*0x020c*/ BYTE         Unknown0x020c[0xb4];
/*0x02c0*/ DWORD        ClassColors[0x10];
/*0x0300*/ BYTE         Unknown0x0300[0x7c];
/*0x037c*/
} EQRAIDWINDOW, *PEQRAIDWINDOW;

//CTradeWnd__CTradeWnd aTradewnd
// Actual Size: 0x2e8 (see 49B4BB) in Oct 24 2014 test - eqmule
typedef struct _EQTRADEWINDOW {
/*0x0000*/ struct _CSIDLWND     Wnd;
/*0x020c*/ BYTE         Unknown0x020c[0xd8];
/*0x02e0*/ BYTE         HisTradeReady;
/*0x02e1*/ BYTE         MyTradeReady;
/*0x02e2*/ BYTE         TradeWndOpen;
/*0x02e3*/ BYTE         Unknown0x02e3[0x5];
/*0x02e8*/
} EQTRADEWINDOW, *PEQTRADEWINDOW; 

};
using namespace EQUIStructs;
