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

/******************************************** CHECKED ********************************************/
// everything above this line is work in progress/stuff that can be improved/checked/fixed.
// everything below it is 100% checked -eqmule


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

struct EQLOOTWINDOW
{
/*0x0000*/ CSIDLWND    Wnd;                      // inherits from CSidlScreenWnd
/*0x0240*/ void*       vftable;                  // for CLootWnd::DialogResponse handler

};
using PEQLOOTWINDOW = EQLOOTWINDOW*;

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


} // namespace eqlib

using namespace eqlib;
