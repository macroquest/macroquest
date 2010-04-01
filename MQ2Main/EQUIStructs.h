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
	UI_Unknown=0,
	UI_Listbox=22,
	UI_Button=23,
	UI_Gauge=24,
	UI_SpellGem=25,
	UI_InvSlot=26,
	UI_EditBox=27,
	UI_Slider=28,
	UI_Label=29,
	UI_STMLBox=30,
	UI_Combobox=31,
	UI_Page=32,
	UI_TabBox=33,
	UI_HorizontalLayoutBox=35,
	UI_VericalLayoutBox=36,
	UI_Screen=38,
};

// ***************************************************************************
// Structures
// ***************************************************************************

// 10-24-2003 Lax - Massive overhaul.
// See http://macroquest.sourceforge.net/phpBB2/viewtopic.php?t=3569 for
// standards on structures to make things easier on everyone!
// -- ONLY applies to EQ structs, not MQ structs like alerts, etc.


//5-15-2003   eqmule
typedef struct _CXSTR {
/*0x00*/   DWORD   Font;            // maybe, dont know.  04 = Window 01 = button
/*0x04*/   DWORD   MaxLength;
/*0x08*/   DWORD   Length;
/*0x0c*/   BOOL    Encoding; // 0: ASCII, 1:Unicode
/*0x10*/   PCRITICAL_SECTION pLock;
/*0x14*/   CHAR    Text[1]; // Stub, can be anywhere from Length to MaxLength (which is how much is malloc'd to this CXStr)
} CXSTR, *PCXSTR;


typedef struct _EQCURRENTSELECTION {
/*0x00*/   DWORD   Unknown;
/*0x04*/   DWORD   SelectedWnd;//address to selection in tree
/*0x08*/   DWORD   Unknownlodncrap;
/*0x0c*/   DWORD   NumberOfSlots;//merchantslots == 79
/*0x10*/   DWORD   TextureAnim;
/*0x14*/
} EQCURRENTSELECTION, *PEQCURRENTSELECTION;

// TO BE REMOVED.
/*
typedef struct _EQSLOTLIST {
            DWORD   Parent;
            DWORD   InvSlots[372];//0-21 inv 22-30 bags
} EQSLOTLIST, *PEQSLOTLIST;
/**/

// Lax
// Actual Size 0x11c 5-5-2004
typedef struct _CSIDLWNDVFTABLE {
/*0000*/ LPVOID IsValid;
/*0004*/ LPVOID  vector_deleting_destructor;
/*0008*/ LPVOID  DrawNC;
/*000C*/ LPVOID  PostDraw;
/*0010*/ LPVOID  PostDraw2;
/*0014*/ LPVOID  DrawCursor;
/*0018*/ LPVOID  OnResize;
/*001C*/ LPVOID  PostDraw3;
/*0020*/ LPVOID  DrawBackground;
/*0024*/ LPVOID  DrawTooltip;
/*0028*/ LPVOID  GetMinimizedRect;
/*002C*/ LPVOID  DrawTitleBar;
/*0030*/ LPVOID  GetCursorToDisplay;
/*0034*/ LPVOID  HandleLButtonDown;
/*0038*/ LPVOID  HandleLButtonUp;
/*003C*/ LPVOID  HandleLButtonHeld;
/*0040*/ LPVOID  HandleLButtonUpAfterHeld;
/*0044*/ LPVOID  HandleRButtonDown;
/*0048*/ LPVOID  HandleRButtonUp;
/*004C*/ LPVOID  HandleRButtonHeld;
/*0050*/ LPVOID  HandleRButtonUpAfterHeld;
/*0054*/ LPVOID  HandleWheelButtonDown;
/*0058*/ LPVOID  HandleWheelButtonUp;
/*005C*/ LPVOID  HandleMouseMove;
/*0060*/ LPVOID  HandleWheelMove;
/*0064*/ LPVOID  HandleKeyboardMsg;
// ./*0068*/ LPVOID  OnDragDrop;
/*0068*/ LPVOID  GetDragDropCursor;
/*006c*/ LPVOID  QueryDropOK;
/*0070*/ LPVOID  OnClickStick;
/*0074*/ LPVOID  GetDragDropCursor2;
/*0078*/ LPVOID  QueryClickStickDropOK;
/*007C*/ LPVOID  WndNotification;
/*0080*/ LPVOID  ShowWindow;     // Activate   
/*0084*/ LPVOID  Deactivate;
/*0088*/ LPVOID  PostDraw4;
/*008C*/ LPVOID  OnMove;
/*0090*/ LPVOID  OnResize2;
/*0094*/ LPVOID  OnMinimizeBox;
/*0098*/ LPVOID  OnTileBox;
/*009C*/ LPVOID  PostDraw5;
/*00A0*/ LPVOID  OnMove2;
/*00A4*/ LPVOID  OnMove3;
/*00A8*/ LPVOID  OnProcessFrame;
/*00AC*/ LPVOID  OnVScroll;
/*00B0*/ LPVOID  OnHScroll;
/*00B4*/ LPVOID  OnBroughtToTop;
/*00B8*/ LPVOID  OnMove4;
/*00BC*/ LPVOID  Show;
/*00C0*/ LPVOID  Unknown0x0c4;
/*00C4*/ LPVOID  Unknown0x0c8;
/*00C8*/ LPVOID  OnMove5;
/*00CC*/ LPVOID  RequestDockInfo;
/*00D0*/ LPVOID  GetTooltip;
/*00D4*/ LPVOID  HitTest;
/*00D8*/ LPVOID  GetHitTestRect;
/*00DC*/ LPVOID  GetInnerRect;
/*00E0*/ LPVOID  GetClientRect;
/*00E4*/ LPVOID  GetMinSize;
/*00E8*/ LPVOID  GetUntileSize;
/*00EC*/ LPVOID  IsPointTransparent;
/*00F0*/ LPVOID  SetDrawTemplate;
/*00F4*/ LPVOID  Unknown0x0f8;
/*00F8*/ LPVOID  SetWindowTextA;
/*00FC*/ LPVOID  SetVScrollPos;
/*0100*/ LPVOID  SetAttributesFromSidl;
/*0104*/ LPVOID  DefineImages;
/*0108*/ LPVOID  Unknown0x10c;
/*010C*/ LPVOID  Unknown0x110;
/*0110*/ LPVOID  LoadIniInfo;
/*0114*/ LPVOID  StoreIniInfo;
/*0118*/ LPVOID  Unknown118;
/*011c*/ LPVOID  Unknown11c;
/*0120*/ LPVOID  Unknown120;
/*0124*/
} CSIDLWNDVFTABLE, *PCSIDLWNDVFTABLE;

// Lax
// Actual Size 0x114  8-11-2004
typedef struct _CXWNDVFTABLE {
/*0000*/ LPVOID  IsValid;
/*0004*/ LPVOID  vector_deleting_destructor;
/*0008*/ LPVOID  DrawNC;
/*000C*/ LPVOID  PostDraw;
/*0010*/ LPVOID  PostDraw2;
/*0014*/ LPVOID  DrawCursor;
/*0018*/ LPVOID  OnResize;
/*001C*/ LPVOID  PostDraw3;
/*0020*/ LPVOID  DrawBackground;
/*0024*/ LPVOID  DrawTooltip;
/*0028*/ LPVOID  GetMinimizedRect;
/*002C*/ LPVOID  DrawTitleBar;
/*0030*/ LPVOID  GetCursorToDisplay;
/*0034*/ LPVOID  HandleLButtonDown;
/*0038*/ LPVOID  HandleLButtonUp;
/*003C*/ LPVOID  HandleLButtonHeld;
/*0040*/ LPVOID  HandleLButtonUpAfterHeld;
/*0044*/ LPVOID  HandleRButtonDown;
/*0048*/ LPVOID  HandleRButtonUp;
/*004C*/ LPVOID  HandleRButtonHeld;
/*0050*/ LPVOID  HandleRButtonUpAfterHeld;
/*0054*/ LPVOID  HandleWheelButtonDown;
/*0058*/ LPVOID  HandleWheelButtonUp;
/*005C*/ LPVOID  HandleMouseMove;
/*0060*/ LPVOID  HandleWheelMove;
/*0064*/ LPVOID  HandleKeyboardMsg;
/*0068*/ LPVOID  OnDragDrop;
/*006C*/ LPVOID  GetDragDropCursor;
/*0070*/ LPVOID  QueryDropOK;
/*0074*/ LPVOID  OnClickStick;
/*0078*/ LPVOID  GetDragDropCursor2;
/*007C*/ LPVOID  QueryClickStickDropOK;
/*0080*/ LPVOID  WndNotification;
/*0084*/ LPVOID  ShowWindow;        
/*0088*/ LPVOID  Deactivate;
/*008C*/ LPVOID  PostDraw4;
/*0090*/ LPVOID  OnMove;
/*0094*/ LPVOID  OnResize2;
/*0098*/ LPVOID  OnMinimizeBox;
/*009C*/ LPVOID  OnTileBox;
/*00A0*/ LPVOID  PostDraw5;
/*00A4*/ LPVOID  OnMove2;
/*00A8*/ LPVOID  OnMove3;
/*00AC*/ LPVOID  OnProcessFrame;
/*00B0*/ LPVOID  OnVScroll;
/*00B4*/ LPVOID  OnHScroll;
/*00B8*/ LPVOID  OnBroughtToTop;
/*00BC*/ LPVOID  OnMove4;
/*00C0*/ LPVOID  Show;
/*00C4*/ LPVOID  Unknown0x0c4;  // Activate?
/*00C8*/ LPVOID  Unknown0x0c8;
/*00CC*/ LPVOID  OnMove5;
/*00D0*/ LPVOID  RequestDockInfo;
/*00D4*/ LPVOID  GetTooltip;
/*00D8*/ LPVOID  HitTest;
/*00DC*/ LPVOID  GetHitTestRect;
/*00E0*/ LPVOID  GetInnerRect;
/*00E4*/ LPVOID  GetClientRect;
/*00E8*/ LPVOID  GetMinSize;
/*00EC*/ LPVOID  GetUntileSize;
/*00F0*/ LPVOID  IsPointTransparent;
/*00F4*/ LPVOID  SetDrawTemplate;
/*00F8*/ LPVOID  Unknown0x0f8;
/*00FC*/ LPVOID  SetWindowTextA;
/*0100*/ LPVOID  SetVScrollPos;//->0
/*0104*/ LPVOID  SetAttributesFromSidl;
/*0108*/ LPVOID  DefineImages;
/*010C*/ LPVOID  Unknown0x10c;
/*0110*/ LPVOID  Unknown0x110;
/*0114*/
} CXWNDVFTABLE, *PCXWNDVFTABLE;

// Lax 10-24-2003
// Actual size                 
typedef struct _CXWND {
/*0x000*/   struct _CXWNDVFTABLE   *pvfTable;
/*0x004*/   DWORD   Unknown0x004;   // set to 0 in CXWnd::Refade
/*0x008*/   DWORD   Unknown0x008;
/*0x00c*/   DWORD   TimeMouseOver;     // "Delay" in ini
/*0x010*/   DWORD   FadeDuration;      //  "Duration" in ini
/*0x014*/   BYTE    FadeToAlpha;      // set to 1 in CXWnd::Refade
/*0x015*/   BYTE    Unknown0x015;     // Faded?
/*0x016*/   BYTE    Locked; // 
/*0x017*/   BYTE    Unknown0x017;
/*0x018*/   BYTE    Unknown0x018;
/*0x019*/   BYTE    Unknown0x019;
/*0x01a*/   BYTE    Unknown0x01a;
/*0x01b*/   BYTE    Unknown0x01b;
/*0x01c*/   BYTE    Unknown0x01c[0xc];
/*0x028*/   struct  _CSIDLWND *pParentWindow;  // If this is NULL, coordinates are absolute...
/*0x02c*/   struct  _CSIDLWND *pChildren;
/*0x030*/   struct  _CSIDLWND *pSiblings;  // its a tree. 
/*0x034*/   BYTE    HasChildren;
/*0x035*/   BYTE    HasSiblings; // 
/*0x036*/   BYTE    Unknown0x02e[0x2];
/*0x038*/   DWORD   XMLIndex;
/*0x03 */   RECT    Location;
/*0x04 */   RECT    OldLocation;
/*0x05 */   BYTE    Show;       // 
/*0x05 */   BYTE    Enabled;
/*0x05 */   BYTE    Minimized;  // 
/*0x05 */   BYTE    Unknown0x057; // ontilebox
/*0x05 */   BYTE    Unknown0x058;
/*0x05 */   BYTE    Unknown0x059;
/*0x05 */   BYTE    MouseOver;
/*0x05 */   BYTE    Unknown0x05b;
/*0x05 */   DWORD   WindowStyle; // bit 1 - vertical scroll, bit 2 - horizontal scroll, bit 4 - title bar?, bit 8 - border 
/*0x06 */   DWORD   Unknown0x060;// -> 0x60
			DWORD   Unknown0x064;
			DWORD   Unknown0x068;
/*0x   */   struct _CXSTR  *WindowText; // -> 0x6C
/*0x0  */   struct _CXSTR  *Tooltip; // -> 0x70
/*0x06 */   DWORD   Unknown0x06c; // CXWnd::SetLookLikeParent
/*0x07 */   ARGBCOLOR BGColor; // "BGTint.Red", green, blue
/*0x07 */   BYTE    Unknown0x074[0x10];
/*0x08 */   DWORD   BGType; // "BGType" in ini
/*0x08 */   struct _CXSTR  *XMLToolTip;// -> 0x90
/*0x08 */   BYTE    Unknown0x08c[0x14];
/*0x0a */   BYTE    Alpha; // "Alpha" in ini
/*0x0a */   BYTE    Fades; // "Fades" in ini
/*0x0a */   BYTE    Unknown0x0a2;
/*0x0a */   BYTE    Unknown0x0a3;
/*0x0a */   BYTE    Unknown0x0a4[0x0c];
/*0x0b */   DWORD   ZLayer; // 
/*0x0b */   DWORD   Unknown0x0b4;
/*0x0b */   LPVOID  DrawTemplate; //
/*0x0b */   BYTE    Unknown0x0b0[0xc];
/*0x0c */   union {
					_ITEMINFO* Item;
					_CSIDLWND* InvDescription;
			};
/*0x0c */   BYTE    Unknown0x0c0[0xc];
/*0x0d */   DWORD   Unknown0x0cc; // CXWnd::StartFade, CXWnd::Minimize
/*0x0d */   BYTE    Unknown0x0d0[0x10];
/*0x0e */   DWORD   FadeTickCount; // 
/*0x0f */   BYTE    Unknown0x0e4; // CXWnd::StartFade  
/*0x0f */   BYTE    Unknown0x0e5; // CXWnd::StartFade 
/*0x0f */   BYTE    Unknown0x0e6; 
/*0x0f */   BYTE    Unknown0x0e7;
/*0x0f */   DWORD   Unknown0x0e8;// CXWnd::StartFade, CXWnd::Minimize 
/*0x0f */   DWORD   VScrollMax; //
/*0x0f */   DWORD   VScrollPos; //
/*0x10 */   DWORD   HScrollMax; // 
/*0x10 */   DWORD   HScrollPos; // 
/*0x10 */   BYTE    ValidCXWnd; //
/*0x10 */   BYTE    Unused0x0f9[0x7];
/*0x   */
} CXWND, *PCXWND;
#define GateBind			 0


// Lax 10-24-2003
// Actual size 0x15c (5/11/2005)      
typedef struct _CSIDLWND {
/*0x000*/   struct _CSIDLWNDVFTABLE   *pvfTable;
/*0x004*/   DWORD   Unknown0x004;   // set to 0 in CXWnd::Refade
/*0x008*/   DWORD   Unknown0x008;
/*0x00c*/   DWORD   TimeMouseOver;     // "Delay" in ini
/*0x010*/   DWORD   FadeDuration;      //  "Duration" in ini
/*0x014*/   BYTE    FadeToAlpha;      // set to 1 in CXWnd::Refade   // -->0x14
/*0x015*/   BYTE    Unknown0x015;     // Faded?
/*0x016*/   BYTE    Locked; // 
/*0x017*/   BYTE    Unknown0x017;
/*0x018*/   BYTE    Unknown0x018;
/*0x019*/   BYTE    Unknown0x019;
/*0x01a*/   BYTE    Unknown0x01a;
/*0x01b*/   BYTE    Unknown0x01b;
/*0x01c*/   BYTE    Unknown0x01c[0x0c];//-->1c
/*0x028*/   struct  _CSIDLWND *pParentWindow;  // If this is NULL, coordinates are absolute...  //-->28
/*0x02c*/   struct  _CSIDLWND *pChildren;
/*0x030*/   struct  _CSIDLWND *pSiblings;  // its a tree.  
/*0x034*/   BYTE    HasChildren;
/*0x035*/   BYTE    HasSiblings;
/*0x036*/   BYTE    Unknown0x036[0x2];
/*0x038*/   DWORD   XMLIndex;
/*0x03c*/   RECT    Location;
/*0x04c*/   RECT    OldLocation;
/*0x05c*/   BYTE    Show;      
/*0x05d*/   BYTE    Enabled;
/*0x05e*/   BYTE    Minimized;  
/*0x05f*/   BYTE    Unknown0x05f; // ontilebox
/*0x060*/   BYTE    Unknown0x060;
/*0x061*/   BYTE    Unknown0x061;
/*0x062*/   BYTE    MouseOver;
/*0x063*/   BYTE    Unknown0x063;
/*0x064*/   DWORD   WindowStyle; // bit 1 - vertical scroll, bit 2 - horizontal scroll, bit 4 - title bar?, bit 8 - border
/*0x068*/   DWORD   Unknown0x068;
/*0x06c*/	DWORD   Unknown0x06c;
/*0x070*/	DWORD   Unknown0x070;
/*0x074*/   struct _CXSTR  *WindowText;
/*0x078*/   struct _CXSTR  *Tooltip;
/*0x07c*/   DWORD   UnknownCW; // CXWnd::SetLookLikeParent
/*0x080*/   ARGBCOLOR BGColor; // "BGTint.Red", green, blue
/*0x084*/   BYTE    Unknown0x084[0x10];
/*0x094*/   DWORD   BGType; // "BGType" in ini 
/*0x098*/   struct _CXSTR  *XMLToolTip;
/*0x09c*/   BYTE    Unknown0x09c[0x14];
/*0x0b0*/   BYTE    Alpha; // "Alpha" in ini 
/*0x0b1*/   BYTE    Fades; // "Fades" in ini
/*0x0b2*/   BYTE    Unknown0x0b2;
/*0x0b3*/   BYTE    Unknown0x0b3;
/*0x0b4*/   BYTE    Unknown0x0b4[0x0c];
/*0x0c0*/   DWORD   ZLayer; // 
/*0x0c4*/   DWORD   Unknown0x0c4;
/*0x0c8*/   LPVOID  DrawTemplate; //
/*0x0cc*/   BYTE    Unknown0x0cc[0xc];
/*0x0d8*/   union {
					_ITEMINFO* Item;
					_CSIDLWND* InvDescription;
			};
/*0x0dc*/   BYTE    Unknown0x0dc[0xc];
/*0x0e8*/   DWORD   Unknown0x0e8; // CXWnd::StartFade, CXWnd::Minimize
/*0x0ec*/   BYTE    Unknown0x0ec[0x10];
/*0x0fc*/   DWORD   FadeTickCount; 
/*0x100*/   BYTE    Unknown0x100; // CXWnd::StartFade  
/*0x101*/   BYTE    Unknown0x101; // CXWnd::StartFade  
/*0x102*/   BYTE    Unknown0x102; 
/*0x103*/   BYTE    Unknown0x103;
/*0x104*/   DWORD   Unknown0x104;// CXWnd::StartFade, CXWnd::Minimize
/*0x108*/   DWORD   VScrollMax;
/*0x10c*/   DWORD   VScrollPos; 
/*0x110*/   DWORD   HScrollMax; 
/*0x114*/   DWORD   HScrollPos; 
/*0x118*/   BYTE    ValidCXWnd; 
/*0x119*/   BYTE    Unused0x119[0x3];
/*0x11c*/   struct _CXSTR  *SidlText; 
/*0x120*/   union { 
			   struct _CXSTR  *SidlScreen; 
               DWORD   SlotID; 
         }; 
/*0x124*/   LPVOID SidlPiece;   // CScreenPieceTemplate (important)  
/*0x128*/   BYTE    Checked;
/*0x129*/   BYTE    Highlighted;
/*0x12a*/   BYTE    Unused0x12a[0x2];
/*0x12c*/   DWORD   TextureAnim; // used in CSidlScreenWnd::AddButtonToRadioGroup
/*0x130*/   struct _CXSTR *   InputText;
/*0x134*/   DWORD   Selector;
/*0x138*/   DWORD   PushToSelector;
/*0x13c*/   DWORD   EnableINIStorage;
/*0x140*/   struct _CXSTR *INIStorageName;
/*0x144*/   DWORD   Unknown0x144;
/*0x148*/   DWORD   Unknown0x148;// CTextureAnimation
/*0x14c*/   DWORD   Unknown0x14c;// CTextureAnimation
/*0x150*/   LPVOID  ContextMenu; // CTextureAnimation
/*0x154*/	DWORD   Unknown0x154;// CTextureAnimation
/*0x158*/	DWORD   Unknown0x158;// CTextureAnimation
/*0x15c*/
} CSIDLWND, *PCSIDLWND;

// size 0x268  5-12-2004 lax
typedef struct _CSIDLMGR {
/*0x000*/	BYTE	Unknown0x000[0x114];
/*0x114*/	PVOID pXMLDataMgr;
/*0x118*/	BYTE	Unknown0x118[0x150];
/*0x268*/
} CSIDLMGR, *PCSIDLMGR;

//11-6-2003 lax
//Actual size 0x108 4-28-2004
//Actual size 0x108 4-12-2005
typedef struct _CXWNDMGR {
/*0x000*/ LPVOID CXWNDMGR__vtable;
/*0x004*/ DWORD Unknown0x004;
/*0x008*/ struct _CSIDLWND *pWindows; 
/*0x00c*/ BYTE Unknown0x00C[0x71];
/*0x07d*/ bool KeyboardFlags[4];  // 7d-80
/*0x081*/ CHAR Unknown0x081[0x6b];
/*0x0EC*/ DWORD ScreenExtentX;
/*0x0F0*/ DWORD ScreenExtentY;
/*0x0F4*/ DWORD Unknown;
/*0x0F8*/ DWORD font_list_ptr;
/*0x0Fc*/ BYTE Unknown0xfc[0xc];
/*0x108*/ 
} CXWNDMGR, *PCXWNDMGR;


// 06-16-2004 dkaa - size is 0x404
// 05-13-2004 dkaa - size is 0x2d4
typedef struct _EQMERCHWINDOW {
/*0x000*/   struct _CSIDLWND Wnd;
/*0x15c*/   BYTE    Unknown0x150[0x8];
/*0x164*/   PCONTENTS   ItemDesc[0x50];     // the mainwindow has pointers
                                            // directly to the items in the
                                            // slots...
/*0x2a4*/   FLOAT   Markup;
/*0x2a8*/   DWORD   SelectedSlotID;
/*0x2ac*/   DWORD   AddressToPointerForSelectedItem;
/*0x2b0*/   DWORD   Unknown0x2b0;
/*0x2b4*/   DWORD   MW_MerchantName;
/*0x2b8*/   DWORD   MW_SelectedItemLabel;
/*0x2bc*/   DWORD   MW_SelectedPriceLabel;
/*0x2c0*/   DWORD   MW_SelectedItem;
/*0x2c4*/   DWORD   MW_Buy_Button;
/*0x2c8*/   DWORD   MW_Sell_Button;
/*0x2cc*/   DWORD   ItemList;
/*0x2d0*/   DWORD   Unknown0x2d0;
/*0x2d4*/
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

// Actual size 0x254 11-5-2003
// 10-27-2003 Lax
typedef struct _EQCHATWINDOW
{
/*0x000*/ struct _CSIDLWND Wnd;
/*0x148*/ struct _EQCHATMGR *ChatManager; 
/*0x14c*/ struct _CSIDLWND* InputWnd;
/*0x150*/ struct _CSIDLWND* OutputWnd;
/*0x154*/ DWORD Unknown0x154;
/*0x158*/ DWORD Unknown0x158;// need to update locations..
/*0x150*/ BYTE Unknown0x148;
/*0x151*/ BYTE Unknown0x149[0x3f];
/*0x18c*/ DWORD Unknown0x188;
/*0x190*/ DWORD Unknown0x18c;
/*0x194*/ struct _CXSTR *CommandHistory[0x28]; // ->0x198
/*0x238*/ DWORD Unknown0x230; // CChatWindow::HistoryBack/forward .. maybe total or current history lines
/*0x23c*/ DWORD Unknown0x234; // CChatWindow::HistoryBack/forward .. maybe total or current history lines
/*0x240*/ DWORD FontSize; //
/*0x244*/ DWORD Unknown0x23C;
/*0x248*/
} EQCHATWINDOW, *PEQCHATWINDOW;

// Actual size 0x1dc old
// Lax 10-24-2003
typedef struct _EQBUFFWINDOW
{
/*0x000*/ struct _CSIDLWND Wnd;
/*0x148*/ BYTE  Unknown0x148[0x48];
/*0x184*/ DWORD pBuff[0x0f];    // CButton*
/*0x1C0*/ DWORD Unknown0x1C0;
/*0x1C4*/ DWORD Unknown0x1C4;
/*0x1C8*/ DWORD Unknown0x1C8;
/*0x1CC*/ DWORD Unknown0x1CC;
/*0x1D0*/ DWORD FirstEffectSlot; //0-15
/*0x1D4*/ DWORD LastEffectSlot;  //0-15
/*0x1D8*/ DWORD MaxBuffs;  // either 0x0F or 0x06  (normal or shortbuffs)
/*0x1DC*/
} EQBUFFWINDOW, *PEQBUFFWINDOW;

// actual size 0x148
typedef struct _EQINVSLOTWND {
/*0x000*/   struct _CXWND Wnd;
/*0x110*/	LONG InvSlot;
/*0x114*/   BYTE Unknown0x114[0x28];
/*0x13C*/   BOOL ProcessClick;
} EQINVSLOTWND, *PEQINVSLOTWND;

// actual size 0x14 2-18-2004 Lax
typedef struct _EQINVSLOT {
/*0x00*/	LPVOID pvfTable; // not based on cxwnd
/*0x04*/	struct _EQINVSLOTWND *pInvSlotWnd;
/*0x08*/	DWORD Unknown0x08;
/*0x0C*/	DWORD Unknown0x0C;
/*0x10*/	PCONTENTS *ppContents;
/*0x14*/
} EQINVSLOT, *PEQINVSLOT;

// actual size 0x100C 2-18-2004 Lax
typedef struct _EQINVSLOTMGR {
/*0x0000*/	DWORD Unknown0x0000;
/*0x0004*/	struct _EQINVSLOT *SlotArray[0x400];
/*0x1004*/	DWORD TotalSlots;
/*0x1008*/	DWORD Unknown0x1008;
/*0x100C*/
} EQINVSLOTMGR, *PEQINVSLOTMGR;


// onetimehero 09-17-03
// ContainerWindow
// Actual Size 0x17C old
typedef struct _EQCONTAINERWINDOW {
/*0x000*/ struct _CSIDLWND Wnd;
/*0x148*/ struct _CONTENTS*   pContents;     // Pointer to the contents of the container;
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

// Actual Size 0x78  old
typedef struct _EQ_CONTAINERWND_MANAGER {
/*0x000*/   DWORD pvfTable; // NOT based on CXWnd.  Contains only destructor
/*0x004*/   PEQCONTAINERWINDOW pPCContainers[0x1a];  // All open containers, including World, in order of opening...
/*0x06c*/   PCONTENTS   pWorldContents;            // Pointer to the contents of the world   If NULL, world container isn't open;
/*0x070*/   DWORD dwWorldContainerID;            // ID of container in zone, starts at one (zero?) and goes up.
/*0x074*/   DWORD dwTimeSpentWithWorldContainerOpen;  // Cumulative counter?
/*0x078*/
} EQ_CONTAINERWND_MANAGER, *PEQ_CONTAINERWND_MANAGER;

typedef struct _POINT3 {
    FLOAT X;
    FLOAT Y;
    FLOAT Z;
} POINT3, *PPOINT3;

// plazmic 08-17-03
// Map Window
typedef struct _MAPLABEL { // sizeof() = 0x28
/*0x00*/    struct _MAPLABEL *pNext;
/*0x04*/    struct _MAPLABEL *pPrev;
/*0x08*/    POINT3 Location;
/*0x14*/    ARGBCOLOR Color;
/*0x18*/    DWORD Size; //1-3;
/*0x1C*/    PCHAR Label;
/*0x20*/    DWORD Layer;    //0-3;
/*0x24*/    DWORD Width;
/*0x28*/    DWORD Height;
/*0x2C*/    DWORD unk_0x2c;
/*0x30*/    DWORD unk_0x30;
} MAPLABEL, *PMAPLABEL;

typedef struct _MAPLINE { // sizeof() = 0x28 (think this might be 0x34 now)
    struct _MAPLINE *pNext;
    struct _MAPLINE *pPrev;
    POINT3 Start;
    POINT3 End;
    ARGBCOLOR Color;
    DWORD Layer;    //0-3;
} MAPLINE, *PMAPLINE;

typedef struct _EQLOOTWINDOW {
/*0x000*/ struct _CSIDLWND Wnd;
/*0x148*/ BYTE  Unknown0x148[0x08];
/*0x150*/ BYTE  Unknown0x150[0x84]; // This is an array of something
/*0x1d4*/ PCONTENTS   ItemDesc[0x1e]; //there can only be 30 items on a corpse since that equals 22 inv slots plus 8 bags...
/*0x24c*/
} EQLOOTWINDOW, *PEQLOOTWINDOW;

//Size: 0x2f8 (03/25/2004)
typedef struct _EQPETINFOWINDOW {
/*0x000*/ struct _CSIDLWND Wnd;
/*0x150*/ DWORD Unknown0x150;
/*0x154*/ DWORD Unknown0x154; // pet's spawnid# ??
/*0x158*/ DWORD Unknown0x158; // 1
/*0x15c*/ BYTE  Unknown0x15c[0x120];
/*0x18C*/ // unknown (one per buff)
/*0x204*/ // window (one per buff)
/*0x27c*/ int   Buff[0x1e]; // Spell ID# of each buff -- 30 total
/*0x2f4*/ DWORD Unknown0x2f4;  
} EQPETINFOWINDOW, *PEQPETINFOWINDOW;

typedef struct _EQTRADESKILLRECIPE {
/*0x00*/ DWORD Unknown0x00;
/*0x04*/ DWORD Trivial;
/*0x08*/ DWORD Unknown0x08;
/*0x0c*/ DWORD Unknown0x0c;
/*0x10*/ DWORD Unknown0x10;
/*0x14*/ CHAR  Name[0x40];
/*0x54*/ DWORD Unknown0x54;
/*0x58*/ DWORD Ingredient[0xa];  // ID# of ingredient(s)
/*0x80*/ DWORD IngredientIcon[0xa]; //Icon# of ingredient(s) (Note: 499 is blank)
} EQTRADESKILLRECIPE, *PEQTRADESKILLRECIPE;

//Size 0x3d8 (02/10/2004)
typedef struct _EQTRADESKILLWINDOW {
/*0x000*/   struct _CSIDLWND Wnd;
/*0x148*/ DWORD Unknown0x148[0x1b];  
/*0x1b4*/ PEQTRADESKILLRECIPE SearchResults[0x64]; 
/*0x344*/ DWORD	Unknown0x344;
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

//Size: 0x28c (08/11/2004) 
typedef struct _EQRAIDWINDOW {
/*0x000*/ struct _CSIDLWND Wnd;
/*0x158*/ BYTE  Unknown0x158[0xa4];
/*0x1fc*/ DWORD ClassColors[0x10];
/*0x23c*/
} EQRAIDWINDOW, *PEQRAIDWINDOW;

typedef struct _GUILDMEMBERINFO {
/*0x000*/ DWORD Unknown0x000; //pointer?
/*0x004*/ BYTE OnlineStatus; // 00=offline, 01=online
/*0x005*/ BYTE UnknownData0x005;
/*0x006*/ BYTE UnknownData0x006;
/*0x007*/ BYTE Unknown0x007;
/*0x008*/ BYTE Unknown0x008[0x8];
/*0x010*/ CHAR Name[0x40];
/*0x050*/ DWORD Level;
/*0x054*/ DWORD Class; 
/*0x058*/ DWORD Rank; //0=member, 1=officer, 2=leader
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
/*0x195*/ BYTE ShowOffline; // 01 = show offline box is checked
/*0x196*/ BYTE Unknown0x196[0x2];
/*0x198*/ struct _GUILDMEMBERINFO **pMember; // This is a pointer to the beginning of a list of pointers, 
	                                         // each representing one player in the guild.  The number of 
	                                         // pointers depends upon TotalMemberCount.
/*0x19c*/ DWORD TotalMemberCount;
/*0x1a0*/ DWORD Unknown0x1a0;  // 150?
/*0x1a4*/ DWORD Unknown0x1a4;  // 1?
/*0x1a8*/ DWORD TotalMemberCountAgain;
/*0x1ac*/ BYTE Unknown0x1ac[0x1c];
/*0x1c8*/ CHAR PersonalNotesFilePath[0x40];  // path to personal notes file
/*0x208*/ BYTE Unknown0x208[0x1c0]; // empty
/*0x3c8*/ DWORD Unknown0x3c8; // 1?
/*0x3cc*/ DWORD Unknown0x3cc; // some sort of bizaare pointer...
/*0x3d0*/
} EQGUILDWINDOW, *PEQGUILDWINDOW;

typedef struct _EQNOTESWINDOW {
/*0x000*/ struct _CSIDLWND Wnd;
/*0x148*/ BYTE  Unknown0x148[0x04];
/*0x14c*/ struct _CSIDLWND *pEditWnd;
} EQNOTESWINDOW, *PEQNOTESWINDOW;

// Lax 10-29-2003 
// Actual size 0x174 11-9-2003
typedef struct _EQITEMWINDOW 
{ 
/*0x000*/ struct _CSIDLWND Wnd; 
/*0x148*/ struct _CSIDLWND *DisplayWnd;  // 13c -> 148
/*0x14c*/ BYTE Unknown0x140[0x4]; 
/*0x150*/ BYTE Unknown0x148; 
/*0x151*/ BYTE Unknown0x149[0x3]; 
/*0x154*/ PCXSTR ItemInfo; // 14c -> 154
/*0x158*/ PVOID Unknown0x150; // PCXSTR "item display" ??    _CSIDLWND ?? 
/*0x15c*/ DWORD Unknown0x154; // possibly PCXSTR of information as on charms 
/*0x160*/ BYTE  Unknown0x158; 
/*0x164*/ PVOID TextureAnim; //0x164
/*0x168*/ PVOID TextureAnim2; 
/*0x16C*/ DWORD Unknown0x164[2]; 
/*0x174*/ 
} EQITEMWINDOW, *PEQITEMWINDOW; 

// Size: 0x1a4 (4/14/2005)
typedef struct _EQMAILWINDOW {
/*0x000*/ struct _CSIDLWND Wnd;
/*0x158  Finish... */
} EQMAILWINDOW, *PEQMAILWINDOW;


// Actual Size 0x270 05-11-2005
typedef struct _EQMAPWINDOW {
/*0x000*/ struct _CSIDLWND Wnd;
/*0x15c*/ BYTE Unknown0x15c[0x24];
/*0x180*/ CHAR shortzonename[0x20]; 
/*0x1a0*/ BYTE Unknown0x1a0[0x8c];
/*0x22c*/ PMAPLINE pLines;       
/*0x230*/ PMAPLABEL pLabels;			
/*0x234*/ BYTE Unknown0x234[0x34];
/*0x268*/ DWORD ContentsCount;  //number of lines/labels on the map (I think)
/*0x270*/
} EQMAPWINDOW, *PEQMAPWINDOW;

// onetimehero 09-17-03
// Spell Window
typedef struct _EQCASTSPELLWINDOW {
/*0x000*/ struct _CSIDLWND Wnd;
/*0x148*/ BYTE Unknown0x148[0x04];
/*0x14c*/  struct _EQCASTSPELLGEM   *SpellSlots[0x9];
/*0x170*/  BYTE    Unknown0x160[0x8];
/*0x178*/  DWORD   spellicon;//if this is equal to FFFFFFFF there is no spell memmed in this slot...
/*0x17c*/  DWORD   spellstate;// 1 = cast in progress or refreshtime not met 2 means we ducked or aborted cast, 0 means its ok to cast
/*0x180*/
} EQCASTSPELLWINDOW, *PEQCASTSPELLWINDOW;

// Individual Gems 2005-05-18 koad 
typedef struct _EQCASTSPELLGEM { 
/*0x000*/ struct	_CSIDLWND Wnd; 
/*0x148*/ BYTE		Unknown0x148[0x08]; 
/*0x054*/ BYTE		Unknown0x154[0x20]; 
/*0x174*/ BYTE		Unknown0x174[0x4]; 
/*0x178*/ DWORD		spellicon;//if this is equal to FFFFFFFF there is no spell memmed in this slot... 
/*0x17C*/ DWORD		spellstate;// 1 = cast in progress or refreshtime not met 2 means we ducked or aborted cast, 0 means its ok to cast 
/*0x180*/ 
} EQCASTSPELLGEM, *PEQCASTSPELLGEM;
#define Fly					 0

// Actual size 0x1c4 10-9-2003
typedef struct _EQHOTBUTTONWINDOW {
/*0x000*/ struct _CSIDLWND Wnd;
/*0x148*/ BYTE Unknown0x138[0xc];
/*0x000*/ DWORD   HotButtonWndView;//0 to 9 for the different views
/*0x14c*/ struct _CSIDLWND   *HotButtons[0x0a];//these will change when you switch page...
/*0x174*/
} EQHOTBUTTONWINDOW, *PEQHOTBUTTONWINDOW;

typedef struct _LOOTCORPSE {
/*0x000*/   BYTE    Unknown0x000;   // 03 seems very common (for NPC anyway)
/*0x001*/   CHAR    Name[0x4b];
/*0x04c*/   FLOAT   Timer;  //Uncertain the equation used here, but fairly certain it's the timer
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
/*0x000*/	struct _CSIDLWND Wnd;
/*0x148*/	struct _CSIDLWND *pStrip1;
/*0x14C*/	struct _CSIDLWND *pStrip2;
// in progress.
/*0x16C*/   BOOL DrawLine;
/*0x170*/   DWORD Unknown0x170;
/*0x174*/	DWORD LineRed;
/*0x178*/	DWORD LineGreen;
/*0x17C*/	DWORD LineBlue;
/*0x180*/
} EQCOMPASSWINDOW, *PEQCOMPASSWINDOW;

// used by options window
typedef struct _EQKBASSIGN
{
/*0x00*/	struct _CXSTR *pDescription;
/*0x04*/	DWORD nAssignmentNumber;
/*0x08*/
} EQKBASSIGN, *PEQKBASSIGN;

// size 0x904 3-10-2004
typedef struct _EQOPTIONSWINDOW {
/*0x000*/	struct _CSIDLWND Wnd;
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

};


using namespace EQUIStructs;
