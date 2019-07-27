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

#include "../common/CXStr.h"
#include "../common/CXWnd.h"
#include "../common/Containers.h"
#include "../common/SharedClasses.h"
#include "../common/UI.h"
#include "EQData(Test).h"

namespace eqlib {

const int MAX_INV_SLOTS = 0x900;

// ***************************************************************************
// Structures
// ***************************************************************************

struct EQCURRENTSELECTION
{
/*0x00*/ DWORD Unknown;
/*0x04*/ DWORD SelectedWnd;                      // address to selection in tree
/*0x08*/ DWORD Unknownlodncrap;
/*0x0c*/ DWORD NumberOfSlots;                    // merchantslots == 79
/*0x10*/ DWORD TextureAnim;
/*0x14*/
};
using PEQCURRENTSELECTION = EQCURRENTSELECTION*;

struct CSidlScreenWnd_VirtualFunctions// : public CXWnd_VirtualFunctions
{
/*0x16c*/ void* CSidlScreenWnd__OnPreZone1c;
/*0x170*/ void* CSidlScreenWnd__OnPreZone1d;
/*0x170*/ void* LoadIniInfo;
/*0x174*/ void* StoreIniInfo;
/*0x178*/ void* EQObject__AsObject;
/*0x17c*/ void* CTreeViewPropertySet__IsPropertySet;
/*0x180*/
};


struct CListWnd_VirtualFunctions// : public CXWnd_VirtualFunctions
{
/*0x168*/ void* CListWnd__OnHeaderClick;
/*0x16c*/ void* CListWnd__DrawColumnSeparators;
/*0x170*/ void* CListWnd__DrawSeparator;
/*0x174*/ void* CListWnd__DrawLine;
/*0x178*/ void* CListWnd__DrawHeader;
/*0x17c*/ void* CListWnd__DrawItem;
/*0x180*/ void* CListWnd__DeleteAll;
/*0x184*/ void* CListWnd__Compare;
/*0x188*/ void* CListWnd__Sort;
};

struct CContextMenu_VirtualFunctions : public CListWnd_VirtualFunctions
{
/*0x18c*/ void* CContextMenu__ShowAt;
};
using CCONTEXTMENUVFTABLE = CContextMenu_VirtualFunctions;
using PCCONTEXTMENUVFTABLE = CContextMenu_VirtualFunctions*;

// class CSidlManager : public CSidlManagerBase
// size 0x1D4 2019-02-12 test see 53E3D3
struct CSIDLMGR
{
/*0x000*/ BYTE     Unknown0x000[0x130];
/*0x130*/ void*    pXMLDataMgr;
/*0x134*/ BYTE     Unknown0x134[0xA0];
/*0x1D4*/
};
using PCSIDLMGR = CSIDLMGR*;

struct DragDropInfo
{
/*0xb8*/ bool      bRightButton;
/*0xbc*/ PCXWND    FromWnd;
/*0xc0*/ PCXWND    ToWnd;
/*0xc4*/ POINT     FromPoint;
/*0xcc*/ POINT     ToPoint; 
/*0xd4*/ int       Code;
/*0xd8*/ void*     Data;
/*0xdc*/
};

struct ClickStickInfo
{
/*0x00*/ void*     vfTable;
/*0x04*/ PCXWND    FromWnd;
/*0x08*/ PCXWND    ToWnd;
/*0x0c*/ POINT     FromPoint;
/*0x14*/ POINT     ToPoint; 
/*0x1c*/ int       Code;
/*0x20*/ void*     Data;
/*0x24*/
};

class ControllerStuff
{
/*0x00*/ void*                 vfTable;

	// this really isnt a HashTable I think its a variation that just stores pointers to stuff
	// but for our purposes it won't matter, i don't want to spend any more time on these kind of array classes.
/*0x04*/ HashTable<void*, int, ResizePolicyNoShrink> Stuff; 
/*0x14*/ 
};

class ControllerManager
{
public:
/*0x00*/ void*               pvfTable;
/*0x04*/ ControllerStuff*   pControllerStuff;
/*0x08*/ HashTable<ControllerStuff*> CStuff;
/*0x18*/
};

// Actual size 0x1b0 in Oct 19 2017 Beta (see 4C2E25)
// this should really be renamed to EQCXWNDMGR
// because its a class that looks like this:
// class EQCXWndManager : CXWndManager
struct CXWNDMGR {
/******************* Begin of CXWNDMGR ***************/
/*0x000*/ LPVOID                       CXWNDMGR__vtable;
/*0x004*/ LPVOID                       CXWNDMGR__vtable2;
/*0x008*/ ArrayClass_RO<PCXWND>        pWindows;
/*0x018*/ ArrayClass_RO<PCXWND>        ParentAndContextMenuWindows;
/*0x028*/ ArrayClass_RO<PCXWND>        TransitionWindows;
/*0x038*/ ArrayClass_RO<PCXWND>        PendingDeletionWindows;
/*0x048*/ UINT                         TypematicKey;
/*0x04c*/ UINT                         LastKeyDownTime;
/*0x050*/ UINT                         LastMouseClickTime;           // when mouse was last clicked
/*0x054*/ DWORD                        MouseMoveTimeStamp;           // when mouse was last moved
/*0x058*/ int                          StrokesSent;
/*0x05c*/ int                          ToolTipHitTest;               // this is really an enum //0 outside 1 transparent 2 client 3 minimizebox 4 tilebox 5 qmark 6 maxbox 7 closebox 8 titlebar 9 vscrollup 10 vscrolldown 11 vscroll thumb 12 vscroll pgup 13 vscroll pgdn 14 hscroll left 15 hscroll right 16 hscroll thumb 17 hscroll pgup 18 hscroll pgdn 19 border left 20 border top 21 border right 22 border bottom 23 border topleft 24 border topright 25 border bott left 26 bott right 27 left top 28 left bott 29 right top 30 right bott 31 no hit
/*0x060*/ PCSIDLWND                    LastClickedWindow;
/*0x064*/ PCSIDLWND                    MainWindow;
/*0x068*/ PCSIDLWND                    FocusWindow;                  // when you select a window its pointer shows up here
/*0x06c*/ PCSIDLWND                    CurrDraggedWindow;            // when you drag a window its pointer shows up here
/*0x070*/ PCSIDLWND                    ActiveWindow;
/*0x074*/ PCSIDLWND                    LastMouseOver;                // Current window pointer is over if this is 0 we are above MAIN Window
/*0x078*/ PCSIDLWND                    Tooltip;                      // Last Tooltip to show?
/*0x07c*/ ArrayClass_RO<PCXWND>        GlobalFocusWindows;
/*0x08c*/ bool                         bReadingLog;
/*0x08d*/ bool                         bSidlManagerOwner;
/*0x090*/ int                          CaptureCount;
/*0x094*/ bool                         bMouseMoveRelative;
/*0x098*/ POINT                        MousePoint;                   // for sure 8BE7CA
/*0x0a0*/ bool                         bCapsLock;
/*0x0a1*/ bool                         KeyboardFlags[4];             // 7d-80
/*0x0a5*/ bool                         bChatMessage;
/*0x0a6*/ bool                         bDrawWindows;
/*0x0a7*/ BYTE                         MouseMoveFlags;
/*0x0a8*/ UINT                         ManagerMode;                  // enum but i dont have time to do it now. its like moving, sizing etc.
/*0x0ac*/ int                          DecorButtonHitTest;
/*0x0b0*/ POINT                        MoveResize;                   // for sure 8BE7D6 
/*0x0b8*/ DragDropInfo                 DDI;                          // size 0x24
/*0x0dc*/ ClickStickInfo               CSI;                          // size 0x24
/*0x100*/ int                          Really;
/*0x104*/ bool                         bModal;                       // for sure
/*0x108*/ UINT                         TTCheckTimer;                 // for sure
/*0x10c*/ UINT                         Flags;                        // for sure
/*0x110*/ CXStr                        ClipText;
/*0x114*/ DWORD                        ScreenExtentX;
/*0x118*/ DWORD                        ScreenExtentY;
/*0x11c*/ ArrayClass_RO<void*>         FontsArray;
/*0x12c*/ void*                        pfontSystem;
/*0x130*/ bool                         bSomething;
/*0x134*/ HWND*                        pGlobalHwnd;
/*0x138*/ POINT                        StoredMousePos;               // last position Mouse was at before we moved it
/*0x140*/ bool                         bManagerDeletionPending;
/*0x144*/ CursorClass                  CC;                           // size 0x3c
/******************* End of CXWNDMGR *****************/
/******************* Begin of EQCXWNDMGR *************/
/*0x180*/ ControllerStuff              Stuff;                        // size 0x14
/*0x194*/ ControllerManager            ControllerMgr;                // size 0x18
/*0x1AC*/ bool                         Unknown0x1AC;
/******************* End of EQCXWNDMGR ***************/
/*0x1b0*/
};
using PCXWNDMGR = CXWNDMGR*;

struct CONTENTDATA
{
	CONTENTS*      pCont;
	int            Unknown;
};

struct CONTENTSARRAY
{
    struct CONTENTDATA Array[1];
};
using PCONTENTSARRAY = CONTENTSARRAY*;


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
	CONTEXT_FILTER_DEBUG,                        // todo: check this not 100% sure its it...
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
	CONTEXT_FILTER_YOU_CANT_USE_THAT_COMMAND,     // Added chat color and filtering options for 'You can't use that command' messages.
	CONTEXT_FILTER_COMBAT_ABILITY_REUSE,          // Added chat color and filtering options for combat ability and AA ability reuse time messages.
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

	// new timestamp menu ids goes here
	// todo check the ids.
};



struct EQINVSLOTWND;

// actual size 0x14 10-12-2010
// I think this is correct:
// see (69FF1E) in eqgame.exe dated 2013 11 13
struct EQINVSLOT
{
/*0x00*/ void*         pvfTable;                 // not based on cxwnd
/*0x04*/ EQINVSLOTWND* pInvSlotWnd;
/*0x08*/ DWORD         Unknown0x08;
/*0x0C*/ int           InvSlot;
/*0x10*/ BYTE          Valid;
/*0x11*/ BYTE          Unknown0x11[3];
/*0x14*/
};
using PEQINVSLOT = EQINVSLOT*;

// Size 0x2418 see 534532 in Nov 06 2018 Test
struct EQINVSLOTMGR
{
/*0x0000*/ void*       vfTable;
/*0x0004*/ EQINVSLOT*  SlotArray[MAX_INV_SLOTS]; // size 0x2400 //see 72E00F in Nov 06 2018 Test
/*0x2404*/ DWORD       TotalSlots;
/*0x2408*/ UINT        LastUpdate;
/*0x240c*/ EQINVSLOT*  pSelectedItem;            // LastSelectedSlot
/*0x2410*/ int         Unknown0x2410;
/*0x2414*/ bool        bToggleBagsOpen;
/*0x2415*/ bool        bToggleBankBagsOpen;
/*0x2418*/
};
using PEQINVSLOTMGR = EQINVSLOTMGR*;

// ContainerWindow
// Actual Size 0x17C old
struct EQCONTAINERWINDOW
{
/*0x000*/ CSIDLWND     Wnd;
/*0x148*/ CONTENTS*    pContents;                // Pointer to the contents of the container;
                                                 // Matches the pointer in CHARINFO.Inventory/Bank/World
/*0x14c*/ CSIDLWND*    pSlots[0x0a];
/*0x000*/ CSIDLWND*    pCombine;
/*0x168*/ CSIDLWND*    pDone;
/*0x16c*/ CSIDLWND*    pIcon;
/*0x170*/ CSIDLWND*    pUnknown;
/*0x174*/ CSIDLWND*    pLabel;
/*0x178*/ BYTE         Unknown0x178[4];
/*0x17c*/
};
using PEQCONTAINERWINDOW = EQCONTAINERWINDOW*;

// Actual Size 0x98  03/15/06
struct EQ_CONTAINERWND_MANAGER
{
/*0x000*/ DWORD       pvfTable;                            // NOT based on CXWnd. Contains only destructor
/*0x004*/ EQCONTAINERWINDOW* pPCContainers[0x22];          // All open containers, including World, in order of opening...
/*0x08c*/ CONTENTS*   pWorldContents;                      // Pointer to the contents of the world If NULL, world container isn't open;
/*0x090*/ DWORD       dwWorldContainerID;                  // ID of container in zone, starts at one (zero?) and goes up.
/*0x094*/ DWORD       dwTimeSpentWithWorldContainerOpen;   // Cumulative counter?
/*0x078*/
};
using PEQ_CONTAINERWND_MANAGER = EQ_CONTAINERWND_MANAGER*;

struct POINT3
{
    float X;
    float Y;
    float Z;
};
using PPOINT3 = POINT3*;


struct EQTRADESKILLRECIPE
{
/*0x00*/ DWORD         Unknown0x00;
/*0x04*/ DWORD         Trivial;
/*0x08*/ DWORD         Unknown0x08;
/*0x0c*/ DWORD         Unknown0x0c;
/*0x10*/ DWORD         Unknown0x10;
/*0x14*/ char          Name[0x40];
/*0x54*/ DWORD         Unknown0x54;
/*0x58*/ DWORD         Ingredient[0xa];          // ID# of ingredient(s)
/*0x80*/ DWORD         IngredientIcon[0xa];      // Icon# of ingredient(s) (Note: 499 is blank)
};
using PEQTRADESKILLRECIPE = EQTRADESKILLRECIPE*;

// Size 0x3d8 (02/10/2004)
struct EQTRADESKILLWINDOW
{
/*0x000*/ CSIDLWND     Wnd;                      // inherits from CSidlScreenWnd
/*0x148*/ DWORD        Unknown0x148[0x1b];
/*0x1b4*/ EQTRADESKILLRECIPE* SearchResults[0x64]; 
/*0x344*/ DWORD        Unknown0x344;
/*0x348*/ DWORD        Unknown0x348;
/*0x34c*/ DWORD        Unknown0x34c;
/*0x350*/ CONTENTS*    Container;
/*0x354*/ DWORD        Unknown0x354;
/*0x358*/ EQTRADESKILLRECIPE* SelectedRecipe;
/*0x35c*/ DWORD        Unknown0x35c;
/*0x360*/ DWORD        SkillLevel;
/*0x364*/ DWORD        Unknown0x364;
/*0x368*/ DWORD        Unknown0x368;
/*0x36c*/ BYTE         Unknown0x36c[0x58];
/*0x3c4*/ DWORD        Unknown0x3c4;
/*0x3c8*/ DWORD        Unknown0x3c8;
/*0x3cc*/ BYTE         Unknonw0x3cc[0x8];
/*0x3d4*/ DWORD        Unknown0x3d4;
/*0x3d8*/ DWORD        Unknown0x3d8;
};
using PEQTRADESKILLWINDOW = EQTRADESKILLWINDOW*;

struct GUILDMEMBERINFO
{
/*0x000*/ DWORD        Unknown0x000;             // pointer?
/*0x004*/ BYTE         OnlineStatus;             // 00=offline, 01=online
/*0x005*/ BYTE         UnknownData0x005;
/*0x006*/ BYTE         UnknownData0x006;
/*0x007*/ BYTE         Unknown0x007;
/*0x008*/ BYTE         Unknown0x008[0x8];
/*0x010*/ CHAR         Name[0x40];
/*0x050*/ DWORD        Level;
/*0x054*/ DWORD        Class; 
/*0x058*/ DWORD        Rank;                     // 0=member, 1=officer, 2=leader
/*0x05c*/ FLOAT        UnknownData0x05c;
/*0x060*/ CHAR         PublicNote[0x80];
/*0x0e0*/ BYTE         Unknown0x0e0[0x180];
/*0x260*/ WORD         UnknownData0x260;
/*0x262*/ WORD         UnknownData0x262;
/*0x264*/ WORD         UnknownData0x264;
/*0x266*/ WORD         UnknownData0x266;
};
using PGUILDMEMBERINFO = GUILDMEMBERINFO*;

// Size: 0x3d0 (02/18/2004)
struct EQGUILDWINDOW
{
/*0x000*/ CSIDLWND     Wnd;                      // inherits from CSidlScreenWnd
/*0x148*/ BYTE         Unknown0x148[0x4c];
/*0x194*/ BYTE         Unknown0x194;
/*0x195*/ BYTE         ShowOffline;              // 01 = show offline box is checked
/*0x196*/ BYTE         Unknown0x196[0x2];

	// This is a pointer to the beginning of a list of pointers, each representing one player in
	// the guild. The number of  pointers depends upon TotalMemberCount.
/*0x198*/ GUILDMEMBERINFO** pMember;             
/*0x19c*/ DWORD        TotalMemberCount;
/*0x1a0*/ DWORD        Unknown0x1a0;             // 150?
/*0x1a4*/ DWORD        Unknown0x1a4;             // 1?
/*0x1a8*/ DWORD        TotalMemberCountAgain;
/*0x1ac*/ BYTE         Unknown0x1ac[0x1c];
/*0x1c8*/ CHAR         PersonalNotesFilePath[0x40]; // path to personal notes file
/*0x208*/ BYTE         Unknown0x208[0x1c0];      // empty
/*0x3c8*/ DWORD        Unknown0x3c8;             // 1?
/*0x3cc*/ DWORD        Unknown0x3cc;             // some sort of bizaare pointer...
/*0x3d0*/
};
using PEQGUILDWINDOW = EQGUILDWINDOW*;

struct EQNOTESWINDOW
{
/*0x000*/ CSIDLWND     Wnd;                      // inherits from CSidlScreenWnd
/*0x148*/ BYTE         Unknown0x148[0x04];
/*0x14c*/ CSIDLWND*    pEditWnd;
};
using PEQNOTESWINDOW = EQNOTESWINDOW*;

// aSpelldisplaywi
// Actual size 0x290 Oct 26 2017 Beta see 7B605F -eqmule
struct EQSPELLINFOWINDOW 
{ 
/*0x000*/ CSIDLWND     Wnd;                      // inherits from CSidlScreenWnd
/*0x240*/ void*        WindowID;
/*0x244*/ void*        pDuration;
/*0x248*/ CSIDLWND*    DisplayWnd;               // pDescription
/*0x24c*/ void*        pName; 
/*0x250*/ void*        pIcon; 
/*0x254*/ IString2     ItemInfo;
/*0x264*/ IString2     MoreText;
/*0x274*/ DWORD        Unknown0x274;
/*0x278*/ DWORD        pTABuffIcons;
/*0x27c*/ DWORD        pTADragIcons;
/*0x280*/ bool         bFailed;
/*0x284*/ void*        TextureAnim;
/*0x288*/ DWORD        SpellID;
/*0x28c*/ DWORD        TimeStamp;
/*0x290*/ 
};
using PEQSPELLINFOWINDOW = EQSPELLINFOWINDOW*;

// Size: 0x1a4 (4/14/2005)
struct EQMAILWINDOW
{
/*0x000*/ CSIDLWND     Wnd;                      // inherits from CSidlScreenWnd
/*0x158  Finish... */
};
using PEQMAILWINDOW = EQMAILWINDOW*;

// Actual size 0x1c4 10-9-2003
struct EQHOTBUTTONWINDOW
{
/*0x000*/ CSIDLWND     Wnd;                      // inherits from CSidlScreenWnd
/*0x148*/ BYTE         Unknown0x138[0xc];
/*0x000*/ DWORD        HotButtonWndView;         // 0 to 9 for the different views
/*0x14c*/ CSIDLWND*    HotButtons[0x0a];         // these will change when you switch page...
/*0x174*/
};
using PEQHOTBUTTONWINDOW = EQHOTBUTTONWINDOW*;

struct LOOTCORPSE
{
/*0x000*/ BYTE         Unknown0x000;             // 03 seems very common (for NPC anyway)
/*0x001*/ CHAR         Name[0x4b];
/*0x04c*/ FLOAT        Timer;                    // Uncertain the equation used here, but fairly certain it's the timer
/*0x050*/ FLOAT        X;
/*0x054*/ BYTE         Unknown0x054[0x4];
/*0x058*/ FLOAT        Y;
/*0x05c*/ FLOAT        Z;
/*0x060*/ BYTE         Unknown0x060[0x24];
/*0x084*/ DWORD        Flags;
/*0x088*/ BYTE         Unknown0x088[0x4];
/*0x08c*/ DWORD        Unknown0x08c;             // 256 seems very common
/*0x090*/
};
using PLOOTCORPSE = LOOTCORPSE*;

// size 0x180 3-10-2004
struct EQCOMPASSWINDOW
{
/*0x000*/ CSIDLWND     Wnd;                      // inherits from CSidlScreenWnd
/*0x148*/ CSIDLWND*    pStrip1;
/*0x14C*/ CSIDLWND*    pStrip2;
	// WIP
/*0x16C*/ BOOL         DrawLine;
/*0x170*/ DWORD        Unknown0x170;
/*0x174*/ DWORD        LineRed;
/*0x178*/ DWORD        LineGreen;
/*0x17C*/ DWORD        LineBlue;
/*0x180*/
};
using PEQCOMPASSWINDOW = EQCOMPASSWINDOW*;

// used by options window
struct EQKBASSIGN
{
/*0x00*/ CXStr pDescription;
/*0x04*/ DWORD nAssignmentNumber;
/*0x08*/
};
using PEQKBASSIGN = EQKBASSIGN*;

// size 0x904 3-10-2004
struct EQOPTIONSWINDOW
{
/*0x000*/ CSIDLWND     Wnd;                      // inherits from CSidlScreenWnd
/*0x148*/
/*0x264*/ EQKBASSIGN   Binds[0xA1];
/*0x508*/
/*0x904*/
};
using PEQOPTIONSWINDOW = EQOPTIONSWINDOW*;

// size 0x28 4-24-2004 Lax
struct EQGRAPHICSENGINE
{
/*0x00*/ // Graphics file handler
/*0x04*/
};
using PEQGRAPHICSENGINE = EQGRAPHICSENGINE*;


struct CTEXTENTRYWND
{
/*0x000*/ CXWND        Wnd;                      // inherits from CXWnd
/*0x1c4*/ DWORD        CursorPos1;
/*0x13c*/ DWORD        CursorPos2;               // same as above but only this needs to be set to update cursor position
/*0x140*/
};
using PCTEXTENTRYWND = CTEXTENTRYWND*;

struct LOOTDETAILS
{
/*0x00*/ DWORD         CorpseID;                 // spawnId of the corpse that has this lootitem
/*0x04*/ WORD          StackCount;
/*0x06*/ WORD          UnknownWord;
/*0x08*/ DWORD         Expiration;
/*0x0c*/ BYTE          Locked;
/*0x0d*/ CHAR          Name[0x40];
/*0x4d*/ //more data here?
};
using PLOOTDETAILS = LOOTDETAILS*;

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

// size is 0x88 see 0x48AB44 in Dec 10 2018 live
struct LOOTITEM
{
/*0x00*/ UINT          ItemID;
/*0x04*/ CHAR          Name[0x40];
/*0x44*/ int           IconID;
/*0x48*/ bool          bStackable;
/*0x4c*/ DWORD         MaxStack;
/*0x50*/ BYTE          NoDrop;
/*0x51*/ BYTE          Unknown0x51[0x3];
/*0x54*/ DWORD         ComboID;
/*0x58*/ DWORD         LootID;
/*0x5c*/ eAdvLootState State;
/*0x60*/ BYTE          bAutoRoll;
/*0x61*/ BYTE          ActivelyManaged;          // User has the manage Window up
/*0x62*/ BYTE          ContextMenu;              // item has a context menu
/*0x63*/ BYTE          AskRandomMode;            // item is in AskRandom mode
/*0x64*/ BYTE          CLootInProgress;
/*0x65*/ BYTE          PLootInProgress;
/*0x68*/ EQArray2<LOOTDETAILS> LootDetails;
/*0x7c*/ DWORD         AskTimer;
/*0x80*/ BYTE          AutoRoll;
/*0x81*/ BYTE          FG;
/*0x82*/ BYTE          Need;
/*0x83*/ BYTE          Greed;
/*0x84*/ BYTE          No;
/*0x85*/ BYTE          AlwaysNeed;
/*0x86*/ BYTE          AlwaysGreed;
/*0x87*/ BYTE          Never;
/*0x88*/
};
using PLOOTITEM = LOOTITEM*;

struct LOOTLIST
{
/*0x000*/ BYTE         Unknown0x004[0x4];
/*0x004*/ LOOTITEM*    pLootItem;
/*0x008*/ LONG         ListSize;
/*0x00c*/ LONG         Unknown0x00c;
/*0x010*/ LONG         Unknown0x010;
/*0x014*/ CXWND*       SharedLootList;
/*0x018*/ CXWND*       PersonalLootList;
/*0x01c*/ LONG         Unknown0x01c;
/*0x020*/ LONG         Unknown0x020;
/*0x024*/
};
using PLOOTLIST = LOOTLIST*;

// CAdvancedLootWnd__CAdvancedLootWnd_x
// size 0x310 see 4CEA0D in Nov 29 2017 Beta
struct EQADVLOOTWND
{
/*0x000*/ CSIDLWND     Wnd;                      // inherits from CSidlScreenWnd
/*0x240*/ BYTE         Unknown0x0240[0x94];
/*0x2d4*/ LOOTLIST*    pCLootList;               // below ref to aAdlw_applyfilt
/*0x2d8*/ LOOTLIST*    pPLootList;               // below ref to aAdlw_cllwnd
/*0x2dc*/ DWORD        Unknown0x2dc;
/*0x2e0*/ DWORD        Unknown0x2e0;
/*0x2e4*/ DWORD        Unknown0x2e4;
/*0x2e8*/ DWORD        TotalLootCount;
/*0x2ec*/ DWORD        Unknown0x2ec;
/*0x2f0*/ DWORD        ContextMenuId;
/*0x2f4*/ DWORD        CLastStackSize;
/*0x2f8*/ BYTE         Unknown0x2f8[0x18];
/*0x310*/
};
using PEQADVLOOTWND = EQADVLOOTWND*;

enum ETargetType
{
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

//.text:005FC640 ; public: __thiscall CTargetIndicator::CTargetIndicator(void)
// size 0x48 see 4BA434 in Oct 26 2015 -eqmule
struct TARGETINDICATOR
{
/*0x00*/ bool          bVisible;
/*0x01*/ bool          bSettingsLoaded;
/*0x04*/ SPAWNINFO*    lasttarget;
/*0x04*/ SPAWNINFO*    MarkedTarget[4];          // Assist,FirstMarked,LastMarked
/*0x18*/ BYTE          IndicatorHidden;          // if this is 1 our mouse is over another window and not on the main one - shouldnt cast when this is 1
/*0x19*/ BYTE          CanActivate;              // if 0 the indicator is red if 1 its green, i.e. it can be activated.
/*0x1a*/ BYTE          Unknown0x1a[0x2];
/*0x1c*/ DWORD         TargetIndicatorSettings;  // CTargetIndicatorSettings class todo: figure it out
/*0x20*/ DWORD         MarkerIndicatorSettings;
/*0x24*/ ETargetType   IndicatorType;            // this is reliable IF you actually have a target
/*0x28*/ float         SegmentLength;
/*0x2c*/ float         ControlSegmentLength;
/*0x30*/ void*         pTargetThickLine;         // CThickLineInterface
/*0x34*/ void*         pFreeTargetThickLine;     // CThickLineInterface
/*0x38*/ void*         pMarkerThickLine[4];      // CThickLineInterface
/*0x48*/
};
using PTARGETINDICATOR = TARGETINDICATOR*;

struct TARGETDATA
{
/*0x00*/ SPAWNINFO*    pPlayer;
/*0x04*/ float         Dist;
/*0x08*/ bool          bUpdated;                 // not sure what this is for tbh
/*0x0c*/ 
};
using PTARGETDATA = TARGETDATA*;

// CTargetManager
// size 0x1a4 see 5FE489 in Oct 26 2015 -eqmule
struct TARGETMANAGER
{
/*0x000*/ TARGETDATA   CycleNPCList[0xa];        // size 0xc*0xa
/*0x078*/ TARGETDATA   CyclePCList[0xa];
/*0x0F0*/ TARGETDATA   CycleCorpseList[0xa];
/*0x168*/ DWORD        LastTargetID;
/*0x16c*/ DWORD        TabTargetID;
/*0x170*/ DWORD        AttackTargetID;
/*0x174*/ DWORD        LastHoverUpdate;
/*0x178*/ DWORD        HoverUpdateInterval;
/*0x17c*/ DWORD        LastFreeTargetUpdate;
/*0x180*/ DWORD        FreeTargetUpdateInterval;
/*0x184*/ DWORD        PreviousTargetID;
/*0x188*/ DWORD        HoverTargetID;            // id of the entity our cursor is over...
/*0x18c*/ bool         bFreeTargetingEnabled;
/*0x190*/ float        target_ring_range;        // squared for easier math
/*0x194*/ float        target_ring_x;            // CVector3 class, this is whats passed to castspell
/*0x198*/ float        target_ring_y;
/*0x19c*/ float        target_ring_z;
/*0x1a0*/ bool         target_ring_good;         // 0=red 1=green 
/*0x1a4*/
};
using PTARGETMANAGER = TARGETMANAGER*;

struct ScreenVector3
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
};
using PScreenVector3 = ScreenVector3*;

// see ref to pinstCInventoryWnd_x in __GetGaugeValueFromEQ_x
// oct 26 2017 Beta see 7BBCE2
struct INVENTORYWND
{
/*0x0000*/ CSIDLWND    Wnd;                      // inherits from CSidlScreenWnd
/*0x0240*/ BYTE        Unknown0x0240[0x90];
/*0x02d0*/ int64_t     VitalityCap;
/*0x02d8*/ int         AAVitalityCap;
};
using PINVENTORYWND = INVENTORYWND*;

/******************************************** CHECKED ********************************************/
// everything above this line is work in progress/stuff that can be improved/checked/fixed.
// everything below it is 100% checked -eqmule

// CBazaarSearchWnd__CBazaarSearchWnd_x aBazaarsearchwn
// CBazaarSearchWnd_size: 0x92e0 (see 5431FE) in May 17 2019 Test
struct BAZAARSEARCHWND
{
/*0x0000*/ CSIDLWND    Wnd;                      // inherits from CSidlScreenWnd
/*0x0240*/ BYTE        Unknown0x0240[0x8ff8];
/*0x9238*/ void**      ppTraderData;
/*0x923c*/ DWORD       hashVal;                  // find in CBazaarSearchWnd__HandleBazaarMsg_x
/*0x9240*/ BYTE        Unknown0x9240[0xa0];
/*0x92e0*/
};
using PBAZAARSEARCHWND = BAZAARSEARCHWND*;

// CPlayerWindow__CPlayerWindow aPlayerwindow
// Note to self: cant actually find CombatState in it, so no point in looking through IDA for it, but it IS the last dword... so... until that changes, im just gonna accept it...
// CPlayerWindow_size: 0x2f8 (see 542AF4) in May 17 2019 Test
struct CPLAYERWND
{
/*0x0000*/ CSIDLWND    Wnd;                      // inherits from CSidlScreenWnd
/*0x0240*/ BYTE        Unknown0x0240[0xb4];
/*0x02f4*/ DWORD       CombatState;              // 1=debuffed, 2=combat cooldown, 3=stand, 4=sit
/*0x02f8*/
};
using PCPLAYERWND = CPLAYERWND*;

// CTargetWindow__CTargetWindow aTargetwindow
// CTargetWindow_size: 0x8d8 (see 54298F) in May 17 2019 Test
struct CTARGETWND
{
/*0x0000*/ CSIDLWND    Wnd;                      // inherits from CSidlScreenWnd
/*0x0240*/ BYTE        Unknown0x0240[0x198];
/*0x03d8*/ CBUTTONWND* pTargetBuff[NUM_BUFF_SLOTS]; // buff icons
/*0x055c*/ int         BuffSpellID[NUM_BUFF_SLOTS]; // 0xffffffff if no buff
/*0x06e0*/ DWORD       BuffTimer[NUM_BUFF_SLOTS];
/*0x0864*/ BYTE        Unknown0x0864[0x24];
/*0x0888*/ DWORD       Type;                     // 1 = self, 4 = group member, 5 = PC, 7 = NPC
/*0x088c*/ BYTE        Unknown0x088c[0x4c];
/*0x08d8*/
};
using PCTARGETWND = CTARGETWND*;

// CBuffWindow__CBuffWindow aBuffwindow
// this is used for both long and shortbuffs...
// CBuffWindow_size: 0x728 (see 542833) in May 17 2019 Test
struct EQBUFFWINDOW
{
/*0x0000*/ CSIDLWND    Wnd;                      // inherits from CSidlScreenWnd
/*0x0240*/ BYTE        Unknown0x0240[0xbc];
/*0x02fc*/ CBUTTONWND* pBuff[0x24];              // CButton*
/*0x038c*/ BYTE        Unknown0x038c[0x210];
/*0x059c*/ DWORD       BuffId[NUM_LONG_BUFFS];
/*0x0644*/ DWORD       BuffTimer[NUM_LONG_BUFFS];
/*0x06ec*/ BYTE        Unknown0x06ec[0x28];
/*0x0714*/ DWORD       MaxLongBuffs;             // 0x2a (NUM_LONG_BUFFS)
/*0x0718*/ DWORD       MaxShortBuffs;            // 0x37 (NUM_SHORT_BUFFS)
/*0x071c*/ BYTE        Unknown0x071c[0xc];
/*0x0728*/
};
using PEQBUFFWINDOW = EQBUFFWINDOW*;

// CSpellGemWnd__CSpellGemWnd
// Individual Gems 
// CSpellGemWnd_size: 0x330 (see 7F639B) in May 17 2019 Test
struct EQCASTSPELLGEM
{
/*0x0000*/ CBUTTONWND  Wnd;                      // inherits from CButtonWnd
/*0x0290*/ int         MouseButtonState;
/*0x0294*/ bool        bChecked;
/*0x0298*/ UINT        LastRefresh;
/*0x029C*/ DWORD       SpellGemTintArray[0xb];   // I dont understand why there are only 11 of these when we have 13 gems noaways, probably a bug or unused?
/*0x02C8*/ int         SpellGemAlphaArray[0xb];
/*0x02f4*/ int         Unknown0x02f4;
/*0x02f8*/ int         Unknown0x02f8;
/*0x02fC*/ int         SpellIconOffsetX;
/*0x0300*/ int         SpellIconOffsetY;
/*0x0304*/ DWORD       spellicon;                // if this is equal to FFFFFFFF there is no spell memmed in this slot...
/*0x0308*/ DWORD       spellstate;               // 1 = cast in progress or refreshtime not met 2 means we ducked or aborted cast, 0 means its ok to cast, should really rename this to tintstage
/*0x030c*/ int         TintIndex;
/*0x0310*/ void*       SpellIconTexture;         // CTextureAnimation
/*0x0314*/ void*       CustomIconTexture;        // CTextureAnimation
/*0x0318*/ int         SpellSlot;
/*0x031c*/ int         Percent;
/*0x0320*/ PCXWND      TemplateName;
/*0x0324*/ void*       TemplateBG;               // CTextureAnimation
/*0x0328*/ void*       TemplateHolder;           // CTextureAnimation
/*0x032C*/ void*       TemplateHighlight;        // CTextureAnimation
/*0x0330*/
};
using PEQCASTSPELLGEM = EQCASTSPELLGEM*;

// pinstCCastSpellWnd_x
// CCastSpellWnd__CCastSpellWnd aCastspellwnd
// CCastSpellWnd_size: 0x2e0 (see 542BED) in May 17 2019 Test
struct EQCASTSPELLWINDOW
{
/*0x0000*/ CSIDLWND    Wnd;                      // inherits from CSidlScreenWnd
/*0x0240*/ BYTE        Unknown0x0240[0x14];
/*0x0254*/ EQCASTSPELLGEM* SpellSlots[NUM_SPELL_GEMS]; // CSPW_Spell%d
/*0x028c*/ BYTE        Unknown0x028c[0x54];
/*0x02e0*/
};
using PEQCASTSPELLWINDOW = EQCASTSPELLWINDOW*;

// note that Invslot needs to be a short or pickupitem wont work
// CInvSlotWnd_size: 0x2e0 (see 7F64AC) in May 17 2019 Test
struct EQINVSLOTWND
{
/*0x0000*/ CXWND       Wnd;                      // inherits from CXWnd(actually CButtonWnd)
/*0x01f8*/ BYTE        Unknown0x01f8[0x8c];
/*0x0284*/ BYTE        Unknown0x0284[0x10];
	// this is ItemGlobalIndex - brainiac
/*0x0294*/ ItemContainerInstance WindowType;
/*0x0298*/ short       InvSlot;
/*0x029a*/ short       BagSlot;
/*0x029c*/ short       GlobalSlot;
	// end of ItemGlobalIndex
/*0x029e*/ short       RandomNum;                // no idea what this is, it changes upon login but we need it for moveitem... -eqmule
/*0x02a0*/ BYTE        Unknown0x02a0[0x20];
/*0x02c0*/ EQINVSLOT*  pInvSlot;
/*0x02c4*/ BYTE        Unknown0x02c4[0x8];
/*0x02cc*/ BOOL        ProcessClick;
/*0x02d0*/ BYTE        Unknown0x02d0[0x10];
/*0x02e0*/
};
using PEQINVSLOTWND = EQINVSLOTWND*;

// CItemDisplayWindow__CItemDisplayWindow_x aItemdisplaywin
// CItemDisplayWindow_size: 0x638 (see 756212) in May 17 2019 Test
struct EQITEMWINDOW
{
/*0x0000*/ CSIDLWND    Wnd;                      // inherits from CSidlScreenWnd
/*0x0240*/ CSIDLWND*   Description;
/*0x0244*/ CSIDLWND*   Name;
/*0x0248*/ CSIDLWND*   IconButton;
/*0x024c*/ CSIDLWND*   ItemLore;
/*0x0250*/ CSIDLWND*   ItemDescriptionTabBox;
/*0x0254*/ CSIDLWND*   ItemDescriptionTab;
/*0x0258*/ CSIDLWND*   ItemLoreTab;
/*0x025c*/ CSIDLWND*   pAppearanceSocketScreen;
/*0x0260*/ CBUTTONWND* pAppearanceSocketItem;
/*0x0264*/ CBUTTONWND* pAppearanceSocketBuyButton;
/*0x0268*/ CSIDLWND*   pAppearanceSocketDescription;
/*0x026c*/ CSIDLWND*   pItemSocketScreen[6];
/*0x0284*/ CBUTTONWND* pItemSocketItemButton[6];
/*0x029c*/ CSIDLWND*   pItemSocketDescription[6];
/*0x02b4*/ CXStr       ItemInfo;                 // this item is placable in yards, guild yards blah blah , This item can be used in tradeskills
/*0x02b8*/ CXStr       WindowTitle;
/*0x02bc*/ CXStr       ItemAdvancedLoreText;
/*0x02c0*/ CXStr       ItemMadeByText;
/*0x02c4*/ CXStr       UnknownCXStr;             // if this is NULL don't populate item data in MQ2ItemDisplay
/*0x02c8*/ BYTE        Unknown0x02c8[0x4];
/*0x02cc*/ CXStr       ItemInformationText;      // Item Information: Placing this augment into blah blah, this armor can only be used in blah blah
/*0x02d0*/ PCONTENTS   pItem;
/*0x02d4*/ bool        bActiveItem;
/*0x02d5*/ bool        bItemTextSet;
/*0x02d8*/ void*       BuffIcons;                // CTextureAnimation
/*0x02dC*/ void*       DragIcons;                // CTextureAnimation
/*0x02E0*/ bool        bTaggable;
/*0x02E1*/ bool        bFailed;
/*0x02E4*/ UINT        TabCount;
/*0x02E8*/ CLABEL*     ModButtonLabel;
/*0x02EC*/ CLABEL*     RewardButtonLabel;
/*0x02f0*/ CSIDLWND*   ConvertStml;
/*0x02F4*/ CLABEL*     MadeByLabel;
/*0x02F8*/ CLABEL*     CollectedLabel;
/*0x02FC*/ CLABEL*     ScribedLabel;
/*0x0300*/ int         Row;
/*0x0304*/ bool        bAntiTwink;
/*0x0308*/ CBUTTONWND* ModButton;
/*0x030c*/ CBUTTONWND* RewardButton;
/*0x0310*/ CBUTTONWND* PrintRealEstateItems;
/*0x0314*/ CBUTTONWND* ConvertButton;
/*0x0318*/ bool        bCollected;
/*0x0319*/ bool        bCollectedReceived;
/*0x031c*/ int         Unknown0x031c;
/*0x0320*/ int         Unknown0x0320;
/*0x0324*/ bool        bScribed;
/*0x0325*/ bool        bScribedReceived;
/*0x0326*/ BYTE        Unknown0x0326[0x2f2];
/*0x0618*/ DWORD       Unknown0x0618;
/*0x061c*/ DWORD       Unknown0x061C;
/*0x0620*/ DWORD       Unknown0x0620;
/*0x0624*/ DWORD       Unknown0x0624;
/*0x0628*/ DWORD       Unknown0x0628;
/*0x062c*/ DWORD       Unknown0x062c;
/*0x0630*/ DWORD       Unknown0x0630;
/*0x0634*/ DWORD       ItemWndIndex;             // 0-5? you can have max 6 windows up I think before it starts overwriting the sixth.
/*0x0638*/
};
using PEQITEMWINDOW = EQITEMWINDOW*;

// CLootWnd__CLootWnd aLootwnd
// CLootWnd_size: 0x3a8 (see 542F56) in May 17 2019 Test
struct EQLOOTWINDOW
{
/*0x0000*/ CSIDLWND    Wnd;                      // inherits from CSidlScreenWnd
/*0x0240*/ void*       vftable;                  // for CLootWnd::DialogResponse handler
/*0x0244*/ BYTE        Unknown0x0244[0x98];
/*0x02dc*/ DWORD       NumOfSlots;
/*0x02e0*/ BYTE        Unknown0x02e0[0x4];
/*0x02e4*/ INVENTORYARRAY* pInventoryArray;
/*0x02e8*/ DWORD       Size;
/*0x02ec*/ DWORD       NumOfSlots3;
/*0x02f0*/ BYTE        Unknown0x02f0[0x8];
/*0x02f8*/ BYTE        Unknown0x02f8;
/*0x02f9*/ BYTE        Unknown0x02f9;
/*0x02fa*/ BYTE        Unknown0x02fa;
/*0x02fb*/ BYTE        Unknown0x02fb;
/*0x02fc*/ CSIDLWND*   LootInvWnd;
/*0x0300*/ CSIDLWND*   LootSlotWnd[0x22];
/*0x0388*/ CSIDLWND*   LW_CorpseName;
/*0x038c*/ CSIDLWND*   DoneButton;
/*0x0390*/ CSIDLWND*   BroadcastButton;
/*0x0394*/ CSIDLWND*   LootAllButton;
/*0x0398*/ BYTE        Unknown0x0398[0x10];
/*0x03a8*/
};
using PEQLOOTWINDOW = EQLOOTWINDOW*;


struct merchdata
{
/*0x00*/ void*         vftable;                  // VeBaseReferenceCount
/*0x04*/ BYTE          Unknown0x4[0x8];
/*0x0c*/ DWORD         MerchSlots;
/*0x10*/ DWORD         SelectedListItem;
/*0x14*/ DWORD         Unknown0x14[4];
/*0x24*/ CONTENTSARRAY* pMerchArray;
/*0x28*/ DWORD         MerchMaxSlots;
/*0x2c*/
};

struct merch_other
{
	merchdata*         pMerchData;               // purchase page
	void*              other;                    // buyback page
	void*              other2;                   // mail page
};

// CMerchantWnd__CMerchantWnd_x (aMerchantwnd)
// CMerchantWnd_size: 0x458 (see 5430B2) in May 17 2019 Test
struct EQMERCHWINDOW
{
/*0x0000*/ CSIDLWND    Wnd;                      // inherits from CSidlScreenWnd
/*0x0240*/ BYTE        Unknown0x0240[0x10];
/*0x0250*/ merch_other* pMerchOther;             // found in CMerchantWnd__CMerchantWnd
/*0x0254*/ BYTE        Unknown0x0254[0x8];
/*0x025c*/ FLOAT       Markup;                   // found in CMerchantWnd__DisplayBuyOrSellPrice_x
/*0x0260*/ BYTE        Unknown0x0260[0xc];
/*0x026c*/ DWORD       SelectedSlotID;
/*0x0270*/ BYTE        Unknown0x0270[0x1e8];
/*0x0458*/
};
using PEQMERCHWINDOW = EQMERCHWINDOW*;

// CPetInfoWindow__CPetInfoWindow aPetinfowindow
// CPetInfoWindow_size: 0x8d8 (see 5420D1) in May 17 2019 Test
struct EQPETINFOWINDOW
{
/*0x0000*/ CSIDLWND    Wnd;                      // inherits from CSidlScreenWnd
/*0x0240*/ DWORD       PetSpawnID;               // The pets SpawnID
/*0x0244*/ BYTE        Unknown0x0244[0x4];
/*0x0248*/ CBUTTONWND* pButton[0xe];             // there are 14 buttons on the petinfowin with text that can be set to attack,none,back and so on, these are those...
/*0x0280*/ BYTE        Unknown0x0280[0x8];
/*0x0288*/ CBUTTONWND* pAttackButton;            // if 0 its not assigned.
/*0x028c*/ CBUTTONWND* pQAttackButton;           // if 0 its not assigned.
/*0x0290*/ CBUTTONWND* pFollowButton;            // if 0 its not assigned.
/*0x0294*/ CBUTTONWND* pGuardButton;             // if 0 its not assigned.
/*0x0298*/ CBUTTONWND* pSitButton;               // if 0 its not assigned.
/*0x029c*/ CBUTTONWND* pStopButton;              // if 0 its not assigned.
/*0x02a0*/ BYTE        Unknown0x02a0[0x174];
/*0x0414*/ CSIDLWND*   pWnd[NUM_BUFF_SLOTS];     // buff icons?
/*0x0598*/ int         Buff[NUM_BUFF_SLOTS];     // Spell ID# of each buff -- 97 total
/*0x071c*/ BYTE        Unknown0x0714[0x20];
/*0x073c*/ DWORD       PetBuffTimer[NUM_BUFF_SLOTS]; // duration until buff fades, in thousands of a second
/*0x08c0*/ BYTE        Unknown0x08c0[0xd];
/*0x08cd*/ BYTE        Sit;                      // 0/1 is off/on
/*0x08ce*/ BYTE        Stop;                     // 0/1 is off/on
/*0x08cf*/ BYTE        ReGroup;                  // 0/1 is off/on
/*0x08d0*/ BYTE        Follow;                   // 0/1 is off/on
/*0x08d1*/ BYTE        Guard;                    // 0/1 is off/on
/*0x08d2*/ BYTE        Taunt;                    // 0/1 is off/on
/*0x08d3*/ BYTE        Hold;                     // 0/1 is off/on
/*0x08d4*/ BYTE        GHold;                    // 0/1 is off/on
/*0x08d5*/ BYTE        Focus;                    // 0/1 is off/on
/*0x08d6*/ BYTE        Unknown0x08d6[0x2];
/*0x08d8*/
};
using PEQPETINFOWINDOW = EQPETINFOWINDOW*;

// CRaidWindow__CRaidWindow
// aClasscolorD
// CRaidWindow_size: 0x3b8 (see 5423C2) in May 17 2019 Test
struct EQRAIDWINDOW
{
/*0x0000*/ CSIDLWND    Wnd;                      // inherits from CSidlScreenWnd
/*0x0240*/ BYTE        Unknown0x0240[0xb8];
/*0x02f8*/ DWORD       ClassColors[0x10];
/*0x0338*/ BYTE        Unknown0x0338[0x80];
/*0x03b8*/
};
using PEQRAIDWINDOW = EQRAIDWINDOW*;

// CTradeWnd__CTradeWnd aTradewnd
// CTradeWnd__size: 0x300 (see 543158) in May 17 2019 Test
struct EQTRADEWINDOW
{
/*0x0000*/ CSIDLWND    Wnd;                      // inherits from CSidlScreenWnd
/*0x0240*/ BYTE        Unknown0x0240[0xb8];
/*0x02f8*/ BYTE        HisTradeReady;
/*0x02f9*/ BYTE        MyTradeReady;
/*0x02fa*/ BYTE        TradeWndOpen;
/*0x02fb*/ BYTE        Unknown0x02fb[0x5];
/*0x0300*/
};
using PEQTRADEWINDOW = EQTRADEWINDOW*;

// CFactionWnd__CFactionWnd_x aFactionwnd
// CFactionWnd__size: 0x288 (see 5432A4) in May 17 2019 Test
struct EQFACTIONWINDOW
{
/*0x0000*/ CSIDLWND    Wnd;                      // inherits from CSidlScreenWnd
/*0x0240*/ int         Unknown0x0240;
/*0x0244*/ bool        bUnknown0x0244;
/*0x0248*/ int         Unknown0x0248;
/*0x024c*/ int         Unknown0x024c;
/*0x0250*/ int         Unknown0x0250;
/*0x0254*/ IString<char> Unknown0x0254;
/*0x0264*/ IString<char> Unknown0x0264;
/*0x0274*/ void*       StandingGaugeTemplate;    // CGaugeWnd*
/*0x0278*/ void*       Categories;               // CTreeView*
/*0x027c*/ void*       SearchNameInput;          // CEditWnd*
/*0x0280*/ CBUTTONWND* SearchButton;             // CButtonWnd*
/*0x0284*/ void*       FactionList;              // CListWnd*
/*0x0288*/
};
using PEQFACTIONWINDOW = EQFACTIONWINDOW*;

} // namespace eqlib

using namespace eqlib;
