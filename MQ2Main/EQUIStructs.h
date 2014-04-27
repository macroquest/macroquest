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

//Actual Size: 1d0 (see 8BCC8D in eqgame dated mar 11 2014) - eqmule
//Note to self: Check WindowStyle first
#define CXW_NO_VTABLE \
/*0x0004*/ void*        pUnknown0x4; \
/*0x0008*/ struct _CSIDLWND*     pNextSiblingWnd; \
/*0x000c*/ void*        pUnknown0xc; \
/*0x0010*/ struct _CSIDLWND*     pFirstChildWnd; \
/*0x0014*/ BYTE         Unknown0x0014[0x8]; \
/*0x001c*/ ARGBCOLOR    BGColor; \
/*0x0020*/ BYTE         Unknown0x0020[0x4]; \
/*0x0024*/ DWORD        FadeDuration; \
/*0x0028*/ BYTE         Unknown0x0028[0x44]; \
/*0x006c*/ DWORD        HScrollPos; \
/*0x0070*/ BYTE         Unknown0x0070[0x5]; \
/*0x0075*/ BYTE         Unlockable;     /* found in CSidlScreenWnd__LoadIniInfo_x related to Locked */ \
/*0x0076*/ BYTE         Unknown0x0076[0x16]; \
/*0x008c*/ BYTE         Clickable;      /* found in CChatWindow__CChatWindow_x and the button handlers */ \
/*0x008d*/ BYTE         Unknown0x008d[0x7]; \
/*0x0094*/ DWORD        ZLayer; /*found in CXWndManager__DrawWindows_x*/ \
/*0x0098*/ BYTE         Unknown0x0098[0x20]; \
/*0x00b8*/ struct _CXSTR*        Tooltip; /*found in CSidlManager__CreateLabel_x*/ \
/*0x00bc*/ BYTE         Unknown0x00bc; \
/*0x00bd*/ BYTE         Enabled; \
/*0x00be*/ BYTE         FadeToAlpha; /*found in CSidlScreenWnd__StoreIniInfo_x*/\
/*0x00bf*/ BYTE         Unknown0x00bf[0x5]; \
/*0x00c4*/ DWORD        WindowStyle;    /* bit 1 - vertical scroll, bit 2 - horizontal scroll, bit 4 - title bar?, bit 8 - border */ \
/*0x00c8*/ BYTE         Unknown0x00c8[0x10]; \
/*0x00d8*/ struct _CXSTR*        WindowText; /*CXWnd__GetWindowTextA_x has this one*/ \
/*0x00dc*/ BYTE         Unknown0x00dc[0x8]; \
/*0x00e4*/ LPVOID       DrawTemplate; \
/*0x00e8*/ RECT         OldLocation; \
/*0x00f8*/ DWORD        TimeMouseOver; \
/*0x00fc*/ struct _CSIDLWND*     pParentWindow; /*CXWnd__IsDescendantOf_x has this one, If this is NULL, coordinates are absolute... */ \
/*0x0100*/ BYTE         ValidCXWnd; /*IsValid has this one*/\
/*0x0101*/ BYTE         Unknown0x0101; \
/*0x0102*/ BYTE         dShow; \
/*0x0103*/ BYTE         Unknown0x0103; \
/*0x0104*/ DWORD        HScrollMax; \
/*0x0108*/ BYTE         Unknown0x0108[0x4]; \
/*0x010c*/ DWORD        UnknownCW; /*found in OnProcessFrame*/\
/*0x0110*/ BYTE         Locked; /*found in CSidlScreenWnd__LoadIniInfo_x*/ \
/*0x0111*/ BYTE         Unknown0x0111[0x7]; \
/*0x0118*/ DWORD        XMLIndex; \
/*0x011c*/ DWORD        VScrollMax; \
/*0x0120*/ BYTE         Unknown0x0120[0x4]; \
/*0x0124*/ DWORD        VScrollPos; \
/*0x0128*/ BYTE         Unknown0x0128[0x25]; \
/*0x014d*/ BYTE         Alpha; \
/*0x014e*/ BYTE         Unknown0x014e[0x2]; \
/*0x0150*/ DWORD        BGType;         /* found in CSidlScreenWnd__StoreIniInfo_x "BGType" in ini */ \
/*0x0154*/ struct _CXSTR*        XMLToolTip; /*found in CSidlManager__CreateLabel_x*/ \
/*0x0158*/ BYTE         Unknown0x0158[0x10]; \
/*0x0168*/ BYTE         MouseOver; /*found in CXWnd__SetMouseOver_x*/ \
/*0x0169*/ BYTE         Unknown0x0169[0x13]; \
/*0x017c*/ RECT         Location; \
/*0x018c*/ BYTE         Unknown0x018c[0x8]; \
/*0x0194*/ DWORD        TickCount2; \
/*0x0198*/ BYTE         Unknown0x0198[0x18]; \
/*0x01b0*/ BYTE         Fades; \
/*0x01b1*/ BYTE         Unknown0x01b1; \
/*0x01b2*/ BYTE         Minimized; \
/*0x01b3*/ BYTE         Unknown0x01b3[0xd]; \
/*0x01c0*/ BYTE         Faded; \
/*0x01c1*/ BYTE         Unknown0x01c1[0x2]; \
/*0x01c3*/ BYTE         CloseOnESC;     /* found in CSidlScreenWnd__StoreIniInfo_x, close when ESC is pressed */ \
/*0x01c4*/ BYTE         Unknown0x01c4[0xc]; \
/*0x01d0*/

// in CChatWindow__CChatWindow
#define EQ_CHAT_HISTORY_OFFSET 0x280
// in CChatWindow__SetChatFont
#define EQ_CHAT_FONT_OFFSET    0x114

#define CXW \
/*0x000*/   struct  _CXWNDVFTABLE   *pvfTable; \
CXW_NO_VTABLE \
/*0x1d0*/

typedef struct _CXWND {
CXW;
} CXWND, *PCXWND;
#define GateBind          0
//CSidlScreenWnd__CSidlScreenWnd1_x
//size is 218h in eqgame dated feb 14 2014 (see 5BCB2D (cswsize)) -eqmule
#define CSW \
/*0x000*/ struct _CSIDLWNDVFTABLE* pvfTable; \
CXW_NO_VTABLE; \
/*0x1d0*/ union { \
                        struct _CXSTR* SidlText; /*found in CChatWindow__WndNotification_x*/\
                        DWORD Items; \
                }; \
/*0x1d4*/ union { \
                        struct _CXSTR* SidlScreen; \
                        DWORD SlotID; \
                }; \
/*0x1d8*/ LPVOID SidlPiece; /* CScreenPieceTemplate (important) */ \
/*0x1dc*/ union { /*find in CSidlScreenWnd__dCSidlScreenWnd_x*/ \
                struct { \
                        BYTE Checked; \
                        BYTE Highlighted; \
                        BYTE Unused0x1de[0x2]; \
                }; \
                DWORD MaxChars; \
        }; \
/*0x1e0*/ DWORD TextureAnim; \
/*0x1e4*/ struct  _CXSTR* InputText; /*found in CChatWindow__CChatWindow_x*/\
/*0x1e8*/ DWORD Selector; /*found in CSidlScreenWnd__CSidlScreenWnd1_x*/\
/*0x1ec*/ DWORD PushToSelector; /*found in CSidlScreenWnd__LoadIniInfo_x*/\
/*0x1f0*/ DWORD EnableINIStorage; /*found in CSidlScreenWnd__LoadSidlScreen_x*/\
/*0x1f4*/ union { \
                struct _CXSTR* INIStorageName; /*found in CSidlScreenWnd__LoadSidlScreen_x*/\
                struct _EQINVSLOT* pEQInvSlot; \
        }; \
/*0x1f8*/ BYTE  Unknown0x1f8[0x10];  \
/*0x208*/ LPVOID ContextMenu; /* CTextureAnimation */ \
/*0x20c*/ DWORD Unknown0x20c; /* CTextureAnimation */ \
/*0x210*/ DWORD Unknown0x210; /* CTextureAnimation */ \
/*0x214*/ DWORD Unknown0x214; \
/*0x218*/

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
//confirmed 20130819 - eqmule
struct merch_other {
    merchdata *pMerchData;
    void *other;
    void *other2;
};
//CMerchantWnd__CMerchantWnd (aMerchantwnd)
// size 2a8 (see 49999F in 20140214 (merchwndsize)) - eqmule
typedef struct _EQMERCHWINDOW {
/*0x000*/   struct  _CSIDLWND Wnd;
/*0x218*/   BYTE    Unknown0x218[0xc];
/*0x224*/   merch_other   *pMerchOther;//found in CMerchantWnd__CMerchantWnd
/*0x228*/   BYTE    Unknown0x228[0x8];
/*0x230*/   FLOAT   Markup;//found in CMerchantWnd__DisplayBuyOrSellPrice_x
/*0x234*/   BYTE    Unknown0x234[0xc];
/*0x240*/   DWORD   SelectedSlotID;//found in CMerchantWnd__RequestBuyItem_x
/*0x244*/   BYTE    Unknown0x244[0x64];
/*0x2a8*/
} EQMERCHWINDOW, *PEQMERCHWINDOW;

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

// Original find by Lax 10-24-2003
// Eqmule sep 13 2013
// Actual size 0x70C sep 13 2013 (see 0x498986)
// locate aBuffwindow which will take u to CBuffWindow__CBuffWindow
//todo: correct this one
//we are not currently using it in any code
//so im leaving it here for posterity...
typedef struct _EQBUFFWINDOW
{
/*0x000*/ struct _CSIDLWND Wnd;
/*0x224*/ BYTE  Unknown0x224[0xBC];
/*0x2e0*/ DWORD pBuff[0x24];        // CButton*
/*0xxxx*/ DWORD FirstEffectSlot;    //0-15
/*0xxxx*/ DWORD LastEffectSlot;     //0-15
/*0xxxx*/ DWORD MaxBuffs;           // either 0x0F or 0x06  (normal or shortbuffs)
/*0x70C*/
} EQBUFFWINDOW, *PEQBUFFWINDOW;

// actual size 0x294 20120316 - ieatacid
// actual size 0x2a4 (see 759769 (invslotwndsize)) in feb 14 2014 eqgame.exe - eqmule
typedef struct _EQINVSLOTWND {
/*0x000*/   struct _CXWND Wnd;      //----/ actually CButtonWnd
/*0x1d0*/   BYTE Unknown0x1d0[0x88];  //___/
/*0x258*/   DWORD Unknown0x258;
/*0x25c*/   LONG WindowType;        // ieatacid has this as InventoryType
                                    // 0 for inventory
                                    // 01 for bank
                                    // 02 for shared bank
                                    // 03 for trader window
                                    // 04 for World/Tradeskill/Combine
                                    // 11 for loot window
/*0x260*/   WORD InvSlot;
/*0x262*/   WORD BagSlot;
/*0x264*/   WORD GlobalSlot;
/*0x266*/   WORD RandomNum;		//no idea what this is, it changes upon login but we need it for moveitem... -eqmule
/*0x268*/   BYTE Unknown0x268[0x20];
/*0x288*/   struct _EQINVSLOT *pInvSlot;
/*0x28c*/   BYTE Unknown0x28c[0x8];
/*0x294*/   BOOL ProcessClick;
/*0x298*/   BYTE Unknown0x298[0xc];
/*0x2a4*/
} EQINVSLOTWND, *PEQINVSLOTWND;

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

// size is 0x3a0 in eqgame.exe dated feb 14 2014 (see 499885) - eqmule
//CLootWnd__CLootWnd (aLootwnd)
typedef struct _EQLOOTWINDOW {
/*0x000*/ struct _CSIDLWND Wnd;
/*0x218*/ void   *vftable; // for CLootWnd::DialogResponse handler 
/*0x21c*/ BYTE   Unknown0x21c[0x9c];
/*0x2b8*/ DWORD  NumOfSlots;
/*0x2bc*/ DWORD  Unknown0x2bc;
/*0x2c0*/ struct _INVENTORYARRAY *pInventoryArray;
/*0x2c4*/ DWORD  NumOfSlots2;
/*0x2c8*/ DWORD  NumOfSlots3;
/*0x2cc*/ BYTE   Unknown0x2cc[0x25];
/*0x2f1*/ BYTE	 LootAll;
/*0x2f2*/ BYTE   Unknown0x2f2[0x2];
/*0x2f4*/ struct _CSIDLWND *LootInvWnd;
/*0x2f8*/ struct _CSILDWND *LootSlotWnd[0x22];
/*0x380*/ struct _CSIDLWND *LW_CorpseName;
/*0x384*/ struct _CSIDLWND *DoneButton;
/*0x388*/ struct _CSIDLWND *BroadcastButton;
/*0x38c*/ struct _CSIDLWND *LootAllButton;
/*0x390*/ BYTE   Unknown0x390[0x10];
/*0x3a0*/
} EQLOOTWINDOW, *PEQLOOTWINDOW;

//Actual Size: 918h (see 4989B2 in feb 14 2014 eqgame.exe) -eqmule
//CPetInfoWindow__CPetInfoWindow aPetinfowindow
typedef struct _EQPETINFOWINDOW {
/*0x000*/ struct _CSIDLWND Wnd;
/*0x218*/ BYTE  Unknown0x218[0x8];
/*0x220*/ DWORD	PetSpawnID;//The pets SpawnID
/*0x224*/ BYTE  Unknown0x224[0x8];
/*0x22c*/ struct _CBUTTONWND *pButton[0xe];//there are 14 buttons on the petinfowin with text that can be set to attack,none,back and so on, these are those...
/*0x264*/ BYTE  Unknown0x264[0x8];
/*0x26c*/ struct _CBUTTONWND *pAttackButton;//if 0 its not assigned.
/*0x270*/ struct _CBUTTONWND *pQAttackButton;//if 0 its not assigned.
/*0x274*/ struct _CBUTTONWND *pFollowButton;//if 0 its not assigned.
/*0x278*/ struct _CBUTTONWND *pGuardButton;//if 0 its not assigned.
/*0x27c*/ struct _CBUTTONWND *pSitButton;//if 0 its not assigned.
/*0x280*/ struct _CBUTTONWND *pStopButton;//if 0 its not assigned.
/*0x284*/ BYTE  Unknown0x284[0x1bc];//just more buttons i havent looked up...
/*0x440*/ struct _CSIDLWND *pWnd[NUM_BUFF_SLOTS]; // buff icons?
/*0x5c4*/ int   Buff[NUM_BUFF_SLOTS];        // Spell ID# of each buff -- 97 total
/*0x748*/ BYTE  Unknown0x748[0x20];
/*0x768*/ DWORD BuffFadeETA[NUM_BUFF_SLOTS]; // duration until buff fades, in thousands of a second
/*0x8ec*/ BYTE  Unknown0x8ec[0x1f];
/*0x90b*/ BYTE	Sit;//0/1 is off/on
/*0x90c*/ BYTE	Stop;//0/1 is off/on
/*0x90d*/ BYTE	ReGroup;//0/1 is off/on
/*0x90e*/ BYTE	Follow;//0/1 is off/on
/*0x90f*/ BYTE	Guard;//0/1 is off/on
/*0x910*/ BYTE	Taunt;//0/1 is off/on
/*0x911*/ BYTE	Hold;//0/1 is off/on
/*0x912*/ BYTE	GHold;//0/1 is off/on
/*0x913*/ BYTE	Focus;//0/1 is off/on
/*0x914*/ BYTE	Unknown0x92c[0x4];//just more buttonstates i havent looked at yet...
/*0x918*/
} EQPETINFOWINDOW, *PEQPETINFOWINDOW; 

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

//CTradeWnd__CTradeWnd (aTradewnd)
//Actual Size 0x2f8 (see 4999FB in eqgame.exe dated feb 14 2014) - eqmule
typedef struct _EQTRADEWINDOW {
/*0x000*/ struct _CSIDLWND Wnd;
/*0x218*/ BYTE   Unknown0x218[0xd8];
/*0x2f0*/ BYTE   HisTradeReady;
/*0x2f1*/ BYTE   MyTradeReady;
/*0x2f2*/ BYTE   TradeWndOpen;
/*0x2f3*/ BYTE   Unknown0x2f3[0x5];
/*0x2f8*/
} EQTRADEWINDOW, *PTRADEWINDOW; 

//Actual Size: 0x388 20121016 - ieatacid
typedef struct _EQRAIDWINDOW {
/*0x000*/ struct _CSIDLWND Wnd;
/*0x214*/ BYTE  Unknown0x214[0xb8];
/*0x2cc*/ DWORD ClassColors[0x10];
/*0x30c*/ BYTE  Unknown0x30c[0x7c];
/*0x388*/
} EQRAIDWINDOW, *PEQRAIDWINDOW;

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

// Lax 10-29-2003
// ieatacid 20121212
// Eqmule feb 14 2014 eqgame.exe
// Actual size 0x5f4 (6A668F)
//CItemDisplayWindow__CItemDisplayWindow (aItemdisplaywin)
typedef struct _EQITEMWINDOW
{ 
/*0x000*/ struct _CSIDLWND Wnd;
/*0x218*/ struct _CSIDLWND *DisplayWnd;
/*0x21c*/ BYTE Unknown0x234[0x70];
/*0x28c*/ PCXSTR ItemInfo;
/*0x290*/ PCXSTR WindowTitle;
/*0x294*/ BYTE Unknown0x294[0x8];
/*0x29c*/ PCXSTR UnknownCXStr; // if this is NULL don't populate item data in MQ2ItemDisplay
/*0x2a0*/ BYTE Unknown0x2a0[0x8];
/*0x2a8*/ PCONTENTS pItem;
/*0x2ac*/ BYTE Unknown0x2ac[0x348];// pointers to stat labels, etc, in this area
/*0x5f4*/ 
} EQITEMWINDOW, *PEQITEMWINDOW;

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

// eqgame.exe dated feb 14 2014 - eqmule
// Actual Size 614 - (see 498F77) 
// CMapViewWnd__CMapViewWnd_x
typedef struct _EQMAPWINDOW {
/*0x0000*/ struct _CSIDLWND          Wnd;
/*0x0218*/ BYTE         Unknown0x0218[0x40];
/*0x0258*/ CHAR         shortzonename[0x20];
/*0x0278*/ BYTE         Unknown0x0278[0x9c];
/*0x0314*/ struct _CXWND  *wnd;           //it the aMvw_maprendera
/*0x0318*/ BYTE         Unknown0x0318[0x38];
/*0x0350*/ struct _CSIDLWNDVFTABLE    *pMapViewMapVfTable; // found at aMapviewmap, start of MapViewMap
/*0x0354*/ BYTE         Unknown0x0354[0x244];
/*0x0598*/ PMAPLINE     pLines;     //0x248(pLines is 248) + 0x350 = 0x598 (address of pMapViewMapVfTable)
/*0x059c*/ PMAPLABEL    pLabels;    //0x24c
/*0x05a0*/ BYTE         Unknown0x05a0[0x3c];
/*0x0614*/
} EQMAPWINDOW, *PEQMAPWINDOW;

// ieatacid 20120316
// eqmule feb 14 2014
//Actual Size: 2a8 (see 499502)
//pinstCCastSpellWnd_x
// CCastSpellWnd__CCastSpellWnd  aCastspellwnd
typedef struct _EQCASTSPELLWINDOW {
/*0x000*/ struct _CSIDLWND Wnd;
/*0x218*/ BYTE Unknown0x218[0x14];
/*0x22c*/  struct _EQCASTSPELLGEM   *SpellSlots[NUM_SPELL_GEMS];//CSPW_Spell%d
/*0x274*/  BYTE    Unknown0x274[0x34]; 
/*0x2a8*/
} EQCASTSPELLWINDOW, *PEQCASTSPELLWINDOW;

// CSpellGemWnd__CSpellGemWnd
// Actual Size: 2f0 see 759658 in feb 14 2014 eqgame.exe - eqmule
// Individual Gems
typedef struct _EQCASTSPELLGEM { 
/*0x000*/ struct    _CXWND Wnd;
/*0x1d0*/ BYTE      Unknown0x1d0[0x44]; 
/*0x214*/ DWORD     TimeStamp;
/*0x218*/ DWORD     RecastTime;
/*0x21c*/ BYTE      Unknown0x218[0xa8]; 
/*0x2c4*/ DWORD     spellicon;       //if this is equal to FFFFFFFF there is no spell memmed in this slot... 
/*0x2c8*/ DWORD     spellstate;      // 1 = cast in progress or refreshtime not met 2 means we ducked or aborted cast, 0 means its ok to cast 
/*0x2cc*/ BYTE      Unknown0x2cc[0x24];
/*0x2f0*/ 
} EQCASTSPELLGEM, *PEQCASTSPELLGEM;
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

// size 0x2c8 20121128 - ieatacid
// size 0x2d0 feb 14 2014 (4993EE) - eqmule
//CPlayerWindow__CPlayerWindow (aPlayerwindow)
//Note to self: cant actually find CombatState in it, so no point in looking through IDA for it, but it IS the last dword... so... until that changes, im just gonna accept it...
typedef struct _CPLAYERWND {
/*0x000*/ struct _CSIDLWND Wnd;
/*0x218*/ BYTE   Unknown[0xb4];
/*0x2cc*/ DWORD  CombatState;   // 1=debuffed, 2=combat cooldown, 3=stand, 4=sit
/*0x2d0*/ 
} CPLAYERWND, *PCPLAYERWND;

// 20120316 - ieatacid
// feb 14 2013 - Eqmule
// Actual Size: 8ac (499282) 
// CTargetWindow__CTargetWindow (aTargetwindow)
typedef struct _CTARGETWND {
/*0x000*/ struct  _CSIDLWND Wnd;
/*0x218*/ BYTE    Unknown0x218[0x198];
/*0x3b0*/ struct _CBUTTONWND *pBuff[NUM_BUFF_SLOTS]; // buff icons
/*0x534*/ int     BuffSpellID[NUM_BUFF_SLOTS]; // 0xffffffff if no buff
/*0x6b8*/ DWORD   BuffTimer[NUM_BUFF_SLOTS];
/*0x83c*/ BYTE    Unknown0x83c[0x24];
/*0x860*/ DWORD   Type;              // 1 = self, 4 = group member, 5 = PC, 7 = NPC
/*0x864*/ BYTE    Unknown0x864[0x48];
/*0x8ac*/
} CTARGETWND, *PCTARGETWND;

typedef struct _CLABELWND {
/*0x000*/ struct    _CXWND Wnd;
/*0x1c4*/ BYTE      Unknown[0x8];
/*0x1cc*/ DWORD     SidlPiece;
/*0x1d0*/
} CLABELWND, *PCLABELWND;

// size 0x92c8 20130417 - ieatacid
// Actual Size: 92b4 (see 499AB3)
// dec 10 2013 - eqmule
//CBazaarSearchWnd__CBazaarSearchWnd aBazaarsearchwn
typedef struct _BAZAARSEARCHWND {
/*0x0000*/ struct _CSIDLWND     Wnd;
/*0x0218*/ BYTE                 Unknown0x218[0x8ff8];
/*0x9210*/ void                 **ppTraderData;
/*0x9214*/ DWORD                hashVal;//find in CBazaarSearchWnd__HandleBazaarMsg_x
/*0x9218*/ BYTE                 Unknown0x9218[0x9c];
/*0x92b4*/
} BAZAARSEARCHWND, *PBAZAARSEARCHWND;

};

using namespace EQUIStructs;
