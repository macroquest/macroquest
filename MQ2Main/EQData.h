/*****************************************************************************
    MQ2Main.dll: MacroQuest2's extension DLL for EverQuest
    Copyright (C) 2002-2003 Plazmic, 2003-2004 Lax

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as published by
    the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
******************************************************************************/
namespace EQData
{

// ***************************************************************************
// Defines
// ***************************************************************************

enum PlayerClass
{
	Unknown=0,
	Warrior=1,
	Cleric=2,
	Paladin=3,
	Ranger=4,
	Shadowknight=5,
	Druid=6,
	Monk=7,
	Bard=8,
	Rogue=9,
	Shaman=10,
	Necromancer=11,
	Wizard=12,
	Mage=13,
	Enchanter=14,
	Beastlord=15,
	Berserker=16,
	TotalClasses=16,
};

typedef struct _ClassInfo
{
	bool CanCast;
	bool PureCaster;
	bool PetClass;
	bool DruidType;
	bool NecroType;
	bool ClericType;
	bool ShamanType;
	bool WizardType;
} CLASSINFO, *PCLASSINFO;

static _ClassInfo ClassInfo[]=
{
	{0,0,0,0,0,0,0},//unk
	{0,0,0,0,0,0,0},//war
	{1,1,0,0,0,1,0},//clr
	{1,0,0,0,0,1,0},//pal
	{1,0,0,1,0,0,0},//rng
	{1,0,0,0,1,0,0},//shd
	{1,1,0,1,0,0,0},//dru
	{0,0,0,0,0,0,0},//mnk
	{1,0,0,0,0,0,0},//brd
	{0,0,0,0,0,0,0},//rog
	{1,1,1,0,0,0,1},//shm
	{1,1,1,0,1,0,0},//nec
	{1,1,0,0,0,0,0},//wiz
	{1,1,1,0,0,0,0},//mag
	{1,1,0,0,0,0,0},//enc
	{1,0,1,0,0,0,1},//bst
	{0,0,0,0,0,0,0},//ber
};


#define SPAWN_PLAYER                    0
#define SPAWN_NPC                       1
#define SPAWN_CORPSE                    2
#define SPAWN_ANY                       3
#define SPAWN_PET                       4

#define ITEM_NORMAL1                    0x0031
#define ITEM_NORMAL2                    0x0036
#define ITEM_NORMAL3                    0x315f
#define ITEM_NORMAL4                    0x3336
#define ITEM_NORMAL5                    0x0032
#define ITEM_NORMAL6                    0x0033
#define ITEM_NORMAL7                    0x0034
#define ITEM_NORMAL8                    0x0039
#define ITEM_CONTAINER                  0x7900
#define ITEM_CONTAINER_PLAIN            0x7953
#define ITEM_BOOK                       0x7379

#define COLOR_DEFAULT                   0x00 +   0
#define COLOR_DARKGREY                  0x00 +   1
#define COLOR_DARKGREEN                 0x00 +   2
#define COLOR_DARKBLUE                  0x00 +   3
#define COLOR_PURPLE                    0x00 +   5
#define COLOR_LIGHTGREY                 0x00 +   6

#define CONCOLOR_GREEN                  0x00 +  14
#define CONCOLOR_LIGHTBLUE              0x00 +  18
#define CONCOLOR_BLUE                   0x00 +  16
#define CONCOLOR_BLACK                  0x00 +  20
#define CONCOLOR_YELLOW                 0x00 +  15
#define CONCOLOR_RED                    0x00 +  13

#define USERCOLOR_SAY                   0xFF +   1 //  1  - Say
#define USERCOLOR_TELL                  0xFF +   2 //  2  - Tell
#define USERCOLOR_GROUP                 0xFF +   3 //  3  - Group
#define USERCOLOR_GUILD                 0xFF +   4 //  4  - Guild
#define USERCOLOR_OOC                   0xFF +   5 //  5  - OOC
#define USERCOLOR_AUCTION               0xFF +   6 //  6  - Auction
#define USERCOLOR_SHOUT                 0xFF +   7 //  7  - Shout
#define USERCOLOR_EMOTE                 0xFF +   8 //  8  - Emote
#define USERCOLOR_SPELLS                0xFF +   9 //  9  - Spells (meming, scribing, casting, etc.)
#define USERCOLOR_YOU_HIT_OTHER         0xFF +  10 //  10 - You hit other
#define USERCOLOR_OTHER_HIT_YOU         0xFF +  11 //  11 - Other hits you
#define USERCOLOR_YOU_MISS_OTHER        0xFF +  12 //  12 - You miss other
#define USERCOLOR_OTHER_MISS_YOU        0xFF +  13 //  13 - Other misses you
#define USERCOLOR_DUELS                 0xFF +  14 //  14 - Some broadcasts (duels)
#define USERCOLOR_SKILLS                0xFF +  15 //  15 - Skills (ups, non-combat use, etc.)
#define USERCOLOR_DISCIPLINES           0xFF +  16 //  16 - Disciplines or special abilities
#define USERCOLOR_UNUSED001             0xFF +  17 //  17 - Unused at this time
#define USERCOLOR_DEFAULT               0xFF +  18 //  18 - Default text and stuff you type
#define USERCOLOR_UNUSED002             0xFF +  19 //  19 - Unused at this time
#define USERCOLOR_MERCHANT_OFFER        0xFF +  20 //  20 - Merchant Offer Price
#define USERCOLOR_MERCHANT_EXCHANGE     0xFF +  21 //  21 - Merchant Buy/Sell
#define USERCOLOR_YOUR_DEATH            0xFF +  22 //  22 - Your death message
#define USERCOLOR_OTHER_DEATH           0xFF +  23 //  23 - Others death message
#define USERCOLOR_OTHER_HIT_OTHER       0xFF +  24 //  24 - Other damage other
#define USERCOLOR_OTHER_MISS_OTHER      0xFF +  25 //  25 - Other miss other
#define USERCOLOR_WHO                   0xFF +  26 //  26 - /who command
#define USERCOLOR_YELL                  0xFF +  27 //  27 - yell for help
#define USERCOLOR_NON_MELEE             0xFF +  28 //  28 - Hit for non-melee
#define USERCOLOR_SPELL_WORN_OFF        0xFF +  29 //  29 - Spell worn off
#define USERCOLOR_MONEY_SPLIT           0xFF +  30 //  30 - Money splits
#define USERCOLOR_LOOT                  0xFF +  31 //  31 - Loot message
#define USERCOLOR_RANDOM                0xFF +  32 //  32 - Dice Roll (/random)
#define USERCOLOR_OTHERS_SPELLS         0xFF +  33 //  33 - Others spells
#define USERCOLOR_SPELL_FAILURE         0xFF +  34 //  34 - Spell Failures (resists, fizzles, missing component, bad target, etc.)
#define USERCOLOR_CHAT_CHANNEL          0xFF +  35 //  35 - Chat Channel Messages
#define USERCOLOR_CHAT_1                0xFF +  36 //  36 - Chat Channel 1
#define USERCOLOR_CHAT_2                0xFF +  37 //  37 - Chat Channel 2
#define USERCOLOR_CHAT_3                0xFF +  38 //  38 - Chat Channel 3
#define USERCOLOR_CHAT_4                0xFF +  39 //  39 - Chat Channel 4
#define USERCOLOR_CHAT_5                0xFF +  40 //  40 - Chat Channel 5
#define USERCOLOR_CHAT_6                0xFF +  41 //  41 - Chat Channel 6
#define USERCOLOR_CHAT_7                0xFF +  42 //  42 - Chat Channel 7
#define USERCOLOR_CHAT_8                0xFF +  43 //  43 - Chat Channel 8
#define USERCOLOR_CHAT_9                0xFF +  44 //  44 - Chat Channel 9
#define USERCOLOR_CHAT_10               0xFF +  45 //  45 - Chat Channel 10
#define USERCOLOR_MELEE_CRIT            0xFF +  46 //  46 - Melee Crits
#define USERCOLOR_SPELL_CRIT            0xFF +  47 //  47 - Spell Crits
#define USERCOLOR_TOO_FAR_AWAY          0xFF +  48 //  48 - Too far away (melee)
#define USERCOLOR_NPC_RAMAGE            0xFF +  49 //  49 - NPC Rampage
#define USERCOLOR_NPC_FURRY             0xFF +  50 //  50 - NPC Furry
#define USERCOLOR_NPC_ENRAGE            0xFF +  51 //  51 - NPC Enrage
#define USERCOLOR_ECHO_SAY              0xFF +  52 //  52 - say echo
#define USERCOLOR_ECHO_TELL             0xFF +  53 //  53 - tell echo
#define USERCOLOR_ECHO_GROUP            0xFF +  54 //  54 - group echo
#define USERCOLOR_ECHO_GUILD            0xFF +  55 //  55 - guild echo
#define USERCOLOR_ECHO_OOC              0xFF +  56 //  56 - group echo
#define USERCOLOR_ECHO_AUCTION          0xFF +  57 //  57 - auction echo
#define USERCOLOR_ECHO_SHOUT            0xFF +  58 //  58 - shout echo
#define USERCOLOR_ECHO_EMOTE            0xFF +  59 //  59 - emote echo
#define USERCOLOR_ECHO_CHAT_1           0xFF +  60 //  60 - chat 1 echo
#define USERCOLOR_ECHO_CHAT_2           0xFF +  61 //  61 - chat 2 echo
#define USERCOLOR_ECHO_CHAT_3           0xFF +  62 //  62 - chat 3 echo
#define USERCOLOR_ECHO_CHAT_4           0xFF +  63 //  63 - chat 4 echo
#define USERCOLOR_ECHO_CHAT_5           0xFF +  64 //  64 - chat 5 echo
#define USERCOLOR_ECHO_CHAT_6           0xFF +  65 //  65 - chat 6 echo
#define USERCOLOR_ECHO_CHAT_7           0xFF +  66 //  66 - chat 7 echo
#define USERCOLOR_ECHO_CHAT_8           0xFF +  67 //  67 - chat 8 echo
#define USERCOLOR_ECHO_CHAT_9           0xFF +  68 //  68 - chat 9 echo
#define USERCOLOR_ECHO_CHAT_10          0xFF +  69 //  69 - chat 10 echo

#define DEITY_Bertoxxulous          201
#define DEITY_BrellSerilis          202
#define DEITY_CazicThule            203
#define DEITY_ErollisiMarr          204
#define DEITY_Bristlebane           205
#define DEITY_Innoruuk              206
#define DEITY_Karana                207
#define DEITY_MithanielMarr         208
#define DEITY_Prexus                209
#define DEITY_Quellious             210
#define DEITY_RallosZek             211
#define DEITY_RodcetNife            212
#define DEITY_SolusekRo             213
#define DEITY_TheTribunal           214
#define DEITY_Tunare                215
#define DEITY_Veeshan               216

#define ITEMTYPE_NORMAL     0
#define ITEMTYPE_PACK       1
#define ITEMTYPE_BOOK       2

#define COMP_NONE       0
#define COMP_EQ         1
#define COMP_NE         2
#define COMP_GT         3
#define COMP_LT         4
#define COMP_GE         5
#define COMP_LE         6
#define COMP_CONT       7
#define COMP_NOTCONT    8
#define COMP_BITAND     9
#define COMP_BITOR      10

#define COMP_TYPE_STRING    0
#define COMP_TYPE_NUMERIC   1
#define COMP_TYPE_BIT       2

#define CMD_MQ 1
#define CMD_EQ 2

#define LASTFIND_NOTFOUND   96
#define LASTFIND_PRIMARY    97

#define EVENT_CHAT          0
#define EVENT_TIMER         1
#define EVENT_CUSTOM        2
#define EVENT_EVAL          3
#define EVENT_EXEC          4
#define EVENT_PULSE         5
#define EVENT_SHUTDOWN      6
#define EVENT_BREAK         7
#define NUM_EVENTS          8

#define CHAT_SAY            1
#define CHAT_TELL           2
#define CHAT_OOC            4
#define CHAT_SHOUT          8
#define CHAT_AUC            16
#define CHAT_GUILD          32
#define CHAT_GROUP          64
#define CHAT_CHAT           128
#define CHATEVENT(x)    (gEventChat & x)

#define FILTERSKILL_ALL      0
#define FILTERSKILL_INCREASE 1
#define FILTERSKILL_NONE     2

#define FILTERMACRO_ALL      0
#define FILTERMACRO_ENHANCED 1
#define FILTERMACRO_NONE     2


#define MAX_STRING            2048
#define MAX_VARNAME           64

// Defines for CXWnd WindowStyle
#define CWS_VSCROLL     0x1
#define CWS_HSCROLL     0x2
#define CWS_TITLE       0x4
#define CWS_CLOSE       0x8
//#define CWS_UNKNOWN     0x10
#define CWS_MINIMIZE    0x20
#define CWS_BORDER      0x40
//#define CWS_UNKNOWN     0x80
//#define CWS_UNKNOWN     0x100
#define CWS_RESIZEALL   0x200
#define CWS_TRANSPARENT 0x400
//#define CWS_UNKNOWN 0x800
#define CWS_NOMOVE      0x8000
#define CWS_UNKNOWN     0x40000
#define ToggleBit(field,bit) field^=bit;
#define BitOn(field,bit) field|=bit;
#define BitOff(field,bit) field&=~bit;
// End CXWnd WindowStyle Defines

enum MOUSE_DATA_TYPES {
   MD_Unknown = -1,
   MD_Button0Click=0,
   MD_Button1Click,
   MD_Button0,
   MD_Button1
};

#define nEQMappableCommands 0xB9


// ***************************************************************************
// Structures
// ***************************************************************************

typedef struct _MOUSESPOOF {
   MOUSE_DATA_TYPES   mdType;
   DWORD            dwData;
   struct _MOUSESPOOF   *pNext;
} MOUSESPOOF, *PMOUSESPOOF;

typedef struct _MOUSECLICK {
   BYTE ConfirmLeftClick;// DO NOT WRITE TO THIS BYTE
   BYTE ConfirmRightClick;// DO NOT WRITE TO THIS BYTE
   BYTE RightClick;
   BYTE LeftClick;
} MOUSECLICK, *PMOUSECLICK;

typedef struct _UILOCATION {
   DWORD x;
   DWORD y;
   DWORD w;
   DWORD h;
   CHAR error[MAX_STRING];
} UILOCATION, *PUILOCATION;

#define ITEM_NAME_LEN         64
#define LORE_NAME_LEN         80
// 0x204 10-9-2003
typedef struct _ITEMINFO {
/*0x00*/   CHAR         Name[ITEM_NAME_LEN];
/*0x40*/   CHAR         LoreName[LORE_NAME_LEN];
/*0x90*/   CHAR         IDFile[0x20];
/*0xb0*/   DWORD      ItemNumber;
/*0xb4*/   DWORD      EquipSlots;
/*0xb8*/   DWORD      Cost;
/*0xbc*/   DWORD      IconNumber;
/*0xc0*/   BYTE         Unknown0xc0[0x10];
/*0xd0*/   BYTE         UnknownData0xd0;
/*0xd1*/   BYTE         Weight;
/*0xd2*/   BYTE         NoRent;
/*0xd3*/   BYTE         NoDrop;
/*0xd4*/   BYTE         Size;
/*0xd5*/   BYTE         Type;
/*0xd6*/   BYTE         TradeSkills;
/*0x0d7*/  BYTE         Lore;
/*0x0d8*/  BYTE         PendingLore;
/*0x0d9*/  BYTE         Artifact;
/*0x0da*/  BYTE         Summoned;
/*0x0db*/  BYTE        SvCold;
/*0x0dc*/  BYTE        SvFire;
/*0x0dd*/  BYTE        SvMagic;
/*0x0de*/  BYTE        SvDisease;
/*0x0df*/  BYTE        SvPoison;
/*0x0e0*/  BYTE        STR;
/*0x0e1*/  BYTE        STA;
/*0x0e2*/  BYTE        AGI;
/*0x0e3*/  BYTE        DEX;
/*0x0e4*/  BYTE        CHA;
/*0x0e5*/  BYTE        INT;
/*0x0e6*/  BYTE        WIS;
/*0x0e7*/  BYTE        Unknown0xe7;
/*0x0e8*/  DWORD       HP;
/*0x0ec*/  DWORD       Mana;
/*0x0f0*/  DWORD       AC;
/*0x0f4*/  DWORD      SkillModValue;
/*0x0f8*/  DWORD      BaneDMGRace;
/*0x0fc*/  DWORD       BaneDMGBodyType;
/*0x100*/  DWORD       RequiredLevel;
/*0x104*/  DWORD       InstrumentType;
/*0x108*/  DWORD       InstrumentMod;
/*0x10c*/  DWORD       Classes;
/*0x110*/  DWORD       Races;
/*0x114*/  DWORD       Diety;
/*0x118*/  BYTE        Unknown0x118[0x4];
/*0x11c*/  DWORD       SpellId;
/*0x120*/  DWORD       Color;
/*0x124*/  BYTE        SkillModType;
/*0x125*/  BYTE        BaneDMGBodyTypeValue;
/*0x126*/  BYTE        BaneDMGRaceValue;
/*0x127*/  BYTE        Magic;
/*0x128*/  BYTE        Level;
/*0x129*/  BYTE        Light;
/*0x12a*/  BYTE        Delay;
/*0x12b*/  BYTE        RecommendedLevel;
/*0x12c*/  BYTE         RecommendedSkill;
/*0x12d*/  BYTE        DmgBonusType;
/*0x12e*/  BYTE        DmgBonusVal;
/*0x12f*/  BYTE        Range;
/*0x130*/  BYTE        Damage;
/*0x131*/  BYTE        ItemType;
/*0x132*/  WORD       Material;
/*0x134*/  DWORD       AugSlot1;
/*0x138*/  DWORD       AugSlot2;
/*0x13c*/  DWORD       AugSlot3;
/*0x140*/  DWORD       AugSlot4;
/*0x144*/  DWORD       AugSlot5;
/*0x148*/  DWORD       AugType;
/*0x14c*/  DWORD        AugRestrictions;
/*0x150*/  DWORD       LDTheme;
/*0x154*/  DWORD       LDCost;
/*0x158*/  BYTE         Unknown0x158[4];
/*0x15C*/  DWORD      FactionModType[0x4];
/*0x16C*/  DWORD      FactionModValue[0x4];
/*0x17c*/  BYTE        CharmFile[0x20];
/*0x19c*/  FLOAT       QuestValue; //everything over 1.00000 is a good thing... ring of the ancients is 777.500
/*0x1a0*/  BYTE        Unknown0x1a0[0x8];
/*0x1a8*/  DWORD      ProcRate;
/*0x1ac*/  DWORD       FocusId;
/*0x1b0*/  DWORD      CombatEffects;
/*0x1b4*/  DWORD      Shielding;
/*0x1b8*/  DWORD      StunResist;
/*0x1bc*/  DWORD      StrikeThrough;
/*0x1c0*/  DWORD      Unknown0x1c0[0x2];
/*0x1c8*/  DWORD      SpellShield;
/*0x1cc*/  DWORD      Avoidance;
/*0x1d0*/  BYTE         Unknown0x1d0[0xc];
/*0x1dc*/  DWORD      CastTime;
   union {
/*0x1e0*/  BYTE         MaxCharges;
/*0x1e0*/  BYTE         Stackable;
   };
/*0x1e1*/  WORD       EffectType;
/*0x1e3*/  CHAR        BookFile[0x1e];
/*0x201*/  BYTE        Skill;
/*0x202*/  BYTE        Combine;
/*0x203*/  BYTE        Slots;
/*0x204*/  BYTE        SizeCapacity;
/*0x205*/  BYTE        WeightReduction;
/*0x206*/  BYTE        Unknown0x206[0x2];
/*0x208*/  DWORD      Favor;  // Tribute Value
/*0x20c*/  DWORD      Unknown0x20c;
/*0x210*/  DWORD      Endurance;
/*0x214*/  DWORD      Attack;
/*0x218*/  DWORD      HPRegen;
/*0x21c*/  DWORD      ManaRegen;
/*0x220*/  DWORD      Haste;
/*0x224*/  DWORD      DamShield;
/*0x22c*/  DWORD      Unknown0x22c;
/*0x228*/  DWORD      Unknown0x228;
/*0x230*/
} ITEMINFO, *PITEMINFO; 

typedef struct _CONTENTS {
/*0x00*/ struct _ITEMINFO *Item;
	union {
/*0x04*/ struct _CONTENTS *Contents[0x0a]; //addresses to whats inside the bag if its a bag
/*0x04*/ struct _ITEMINFO *Augments[0x0a]; //Only 1-5 are actually used (for now)
	};
	union {
/*0x2c*/  DWORD   StackCount;
/*0x2c*/  DWORD   Charges;
    };
/*0x30*/  DWORD   ItemSlot;// slotid for Player Items
/*0x34*/  BYTE    Unknown2[0xc];
/*0x40*/  DWORD	  ItemSlot2;// slotid for Merchant Items
/*0x44*/  DWORD   Unknown3;
/*0x48*/  DWORD   Price; //price a player vendor set the item at 
/*0x4c*/  DWORD   Open;
/*0x50*/
} CONTENTS, *PCONTENTS;

// 6-11-2003 Amadeus
// Size 0x10
typedef struct _SPELLBUFF {
/*0x00*/    BYTE      Unknown0x00;
/*0x01*/    BYTE      Level;
/*0x02*/    CHAR      Modifier; // bard song modifier, divide by 10 to get 2.8 etc
/*0x03*/    CHAR      DamageShield;  // maybe.. I've noticed this is -1 on a lot of ds's.
/*0x04*/    DWORD     SpellID;
/*0x08*/    DWORD     Duration;
/*0x0c*/    DWORD     DamageAbsorbRemaining;  // Melee or Spellshield type
/*0x10*/
} SPELLBUFF, *PSPELLBUFF;

// 12-23-2003   TheColonel
typedef struct _INVENTORY { 
/*0x00*/  struct	_CONTENTS* Charm; 
/*0x04*/  struct	_CONTENTS* LeftEar; 
/*0x08*/  struct	_CONTENTS* Head; 
/*0x0c*/  struct	_CONTENTS* Face; 
/*0x10*/  struct	_CONTENTS* RightEar; 
/*0x14*/  struct	_CONTENTS* Neck; 
/*0x18*/  struct	_CONTENTS* Shoulders; 
/*0x1c*/  struct	_CONTENTS* Arms; 
/*0x20*/  struct	_CONTENTS* Back; 
/*0x24*/  struct	_CONTENTS* LeftWrist; 
/*0x28*/  struct	_CONTENTS* RightWrist; 
/*0x2c*/  struct	_CONTENTS* Range; 
/*0x30*/  struct	_CONTENTS* Hands; 
/*0x34*/  struct	_CONTENTS* Primary; 
/*0x38*/  struct	_CONTENTS* Secondary; 
/*0x3c*/  struct	_CONTENTS* LeftFinger; 
/*0x40*/  struct	_CONTENTS* RightFinger; 
/*0x44*/  struct	_CONTENTS* Chest; 
/*0x48*/  struct	_CONTENTS* Legs; 
/*0x4c*/  struct	_CONTENTS* Feet; 
/*0x50*/  struct	_CONTENTS* Waist; 
/*0x54*/  struct	_CONTENTS* Ammo; 
/*0x58*/  struct	_CONTENTS* Pack[0x8]; 
} INVENTORY, *PINVENTORY; 

#define      NUM_BANK_SLOTS         0x12
#define      NUM_BOOK_SLOTS         0x200
// actual size 0xa020 3-10-2004
typedef struct _OLDCHARINFO { 
/*0x0000*/	BYTE		Unknown00000; 
/*0x0001*/	BYTE		Unknown00001; 
/*0x0002*/	CHAR		Name[0x40]; 
/*0x0042*/	CHAR		Lastname[0x20]; 
/*0x0062*/	CHAR		Unknown0x0062[0x20]; 
/*0x0082*/	BYTE		Unused0x0082[0x2]; 
/*0x0084*/	DWORD		Unknown0x0084; 
/*0x0088*/	BYTE		Gender; 
/*0x0089*/	BYTE		Unknown0x0089[3]; 
/*0x008c*/	BYTE		Race; 
/*0x008d*/	BYTE		Unknown0x008d[3]; 
/*0x0090*/	BYTE		Class; 
/*0x0091*/	BYTE		Unknown0x0091[3]; 
/*0x0094*/	DWORD		Unknown0x0094; 
/*0x0098*/	DWORD		Level; 
/*0x009c*/	DWORD		Exp; 
/*0x00a0*/	DWORD		PracticePoints; 
/*0x00a4*/	DWORD		Mana; 
/*0x00a8*/	DWORD		Endurance;
/*0x00ac*/	DWORD		BaseHP; 
/*0x00b0*/	BYTE		Stunned; 
/*0x00b1*/	BYTE		Unknown0x00b1[3]; 
/*0x00b4*/	DWORD		BaseSTR; 
/*0x00b8*/	DWORD		BaseSTA; 
/*0x00bc*/	DWORD		BaseCHA; 
/*0x00c0*/	DWORD		BaseDEX; 
/*0x00c4*/	DWORD		BaseINT; 
/*0x00c8*/	DWORD		BaseAGI; 
/*0x00cc*/	DWORD		BaseWIS; 
/*0x00d0*/  BYTE		Face;
/*0x00d1*/  BYTE		field_D1[0x9];
/*0x00da*/  BYTE		Unknown0xda[0x2];
/*0x00dc*/  DWORD		field_DC;
/*0x00e0*/  BYTE		Unknown0xe0[0x20];
/*0x0100*/	BYTE		languages[0x20];
/*0x0120*/	struct  	_SPELLBUFF Buff[0x0f]; 
/*0x0210*/	DWORD		SpellBook[NUM_BOOK_SLOTS]; 
/*0x0a10*/  DWORD		MemorizedSpells[0x10];
/*0x0a50*/  BYTE		field_A50;
/*0x0a51*/  BYTE		Unknown0xa51[0x3];
/*0x0a54*/	FLOAT		y; 
/*0x0a58*/	FLOAT		x; 
/*0x0a5c*/	FLOAT		z; 
/*0x0a60*/	FLOAT		heading; 
/*0x0a64*/  BYTE		standstate;
/*0x0a65*/  BYTE		Unknown0xa65[0x3];
/*0x0a68*/	DWORD		Plat; 
/*0x0a6c*/	DWORD		Gold; 
/*0x0a70*/	DWORD		Silver; 
/*0x0a74*/	DWORD		Copper; 
/*0x0a78*/	DWORD		BankPlat; 
/*0x0a7c*/	DWORD		BankGold; 
/*0x0a80*/	DWORD		BankSilver; 
/*0x0a84*/	DWORD		BankCopper; 
/*0x0a88*/  DWORD		field_A88;
/*0x0a8c*/  DWORD		field_A8C;
/*0x0a90*/  DWORD		field_A90;
/*0x0a94*/  DWORD		field_A94;
/*0x0a98*/	DWORD		BankSharedPlat; 
/*0x0a9c*/  DWORD		field_A9C;
/*0x0aa0*/  DWORD		field_AA0;
/*0x0aa4*/  DWORD		field_AA4;
/*0x0aa8*/  DWORD		field_AA8;
/*0x0aac*/  DWORD		field_AAC;
/*0x0ab0*/  DWORD		field_AB0;
/*0x0ab4*/  DWORD		field_AB4;
/*0x0ab8*/  DWORD		Skill[0x64];
/*0x0c48*/  DWORD		InnateSkill[0x19];
/*0x0cac*/  BYTE		field_CAC;
/*0x0cad*/  BYTE		field_CAD;
/*0x0cae*/  BYTE		Unknown0xcae[0x2];
/*0x0cb0*/  DWORD		field_CB0;
/*0x0cb4*/  DWORD		field_CB4;
/*0x0cb8*/  DWORD		field_CB8;
/*0x0cbc*/  DWORD		field_CBC;
/*0x0cc0*/  BYTE		field_CC0[0x40];  
/*0x0d00*/  DWORD		field_D00;
/*0x0d04*/  DWORD		field_D04;
/*0x0d08*/  BYTE		Unknown0xd08[0x58];
/*0x0d60*/  DWORD		hungerlevel;
/*0x0d64*/  DWORD		thirstlevel;
/*0x0d68*/  BYTE		Unknown0xd68[0x14];
/*0x0d7c*/	WORD		zoneId; 
/*0x0d7e*/	WORD		Instance; 
/*0x0d80*/	struct		_SPAWNINFO* pSpawn;  //-->d80
	union { 
     /*0x0d84*/ struct	_INVENTORY	Inventory; 
     /*0x0d84*/ struct	_CONTENTS*	InventoryArray[0x1e]; 
	}; 
/*0x0dfc*/	struct		_CONTENTS* Cursor; 
/*0x0e00*/  BYTE		Unknown0xe00[0x14];
/*0x0e14*/  BYTE		field_E14;
/*0x0e15*/  BYTE		field_E15;
/*0x0e16*/  BYTE		Unknown0xe16[0x2];
/*0x0e18*/	DWORD		STR; 
/*0x0e1c*/	DWORD		STA; 
/*0x0e20*/	DWORD		CHA; 
/*0x0e24*/	DWORD		DEX; 
/*0x0e28*/	DWORD		INT; 
/*0x0e2c*/	DWORD		AGI; 
/*0x0e30*/	DWORD		WIS; 
/*0x0e34*/	DWORD		field_E34; 
/*0x0e38*/	DWORD		SaveMagic; 
/*0x0e3c*/	DWORD		SaveFire; 
/*0x0e40*/	DWORD		SaveCold; 
/*0x0e44*/	DWORD		SavePoison; 
/*0x0e48*/	DWORD		SaveDisease; 
/*0x0e4c*/	DWORD		Unknown0x0e4c; 
/*0x0e50*/  DWORD       CurrWeight;
/*0x0e54*/  DWORD       Unknown0x0e54;
/*0x0e58*/  DWORD       HPBonus;       //From +HP Gear & Probably Spells
/*0x0e5c*/  DWORD       ManaBonus;       //From +MANA Gear & Probably Spells
/*0x0e60*/  BYTE        Unknown0xe60[0x4c];
/*0x0eac*/  DWORD       AttackBonus;  // From gear only
/*0x0eb0*/  DWORD       HPRegenBonus; // From gear only
/*0x0eb4*/  DWORD       ManaRegenBonus;  // From gear only
/*0x0eb8*/  DWORD       DamageShieldBonus;  // From gear only
/*0x0ebc*/  DWORD       AttackSpeed;  // From gear only
/*0x0ec0*/  DWORD       field_EC0;     // This is some sort of pointer
/*0x0ec4*/  BYTE        UnknownData0xec4;  // data here'
/*0x0ec5*/  BYTE        Unknown0xec5[0x3];
/*0x0ec8*/  SPELLBUFF   ShortBuff[0x6];
/*0x0f48*/  BYTE        Unknown0x0f34[0x108];
/*0x1030*/  DWORD       ZoneBoundId; //-->1034
/*0x1034*/	BYTE		Unknown0x1034[0x10]; 
/*0x1044*/	FLOAT		ZoneBoundY; 
/*0x1048*/	BYTE		Unknown0x1048[0x10]; 
/*0x1058*/	FLOAT		ZoneBoundX; 
/*0x105c*/	BYTE		Unknown0x105c[0x10]; 
/*0x106c*/	FLOAT		ZoneBoundZ; 
/*0x1070*/	FLOAT		Unknown0x1070; 
/*0x1074*/	FLOAT		Unknown0x1074; 
/*0x1078*/	FLOAT		Unknown0x1078; 
/*0x107c*/	FLOAT		Unknown0x107c; 
/*0x1080*/  BYTE		field_1080[0x14];
/*0x1094*/  DWORD		field_1094;
/*0x1098*/	DWORD		Diety; 
/*0x109c*/	DWORD		GuildID; 
/*0x10a0*/  BYTE		Unknown0x10a0[0x10];
/*0x10b0*/	BYTE		GuildStatus; 
/*0x10b1*/  BYTE		Unknown0x10b1[0x3];
/*0x10b4*/  DWORD		Drunkedness;
/*0x10b8*/  DWORD		field_10b8;
/*0x10bc*/  BYTE		Unknown0x10bc[0x24];
/*0x10e0*/	DWORD		AAExp;   // AAExp/330 = %
/*0x10e4*/	BYTE		field_10e4; 
/*0x10e5*/	BYTE		PercentEXPtoAA; 
/*0x10e6*/  BYTE		Unknown0x10e6[0x1aa];
/*0x1290*/	DWORD		AAPoints;   
/*0x1294*/  BYTE		Unknown0x1294[0x9b8];// <-- major shrink here
/*0x1c4c*/	CHAR		Server[0x20]; 
/*0x1c6c*/	BYTE		Unknown0x1c6c[0x11c];
/*0x1d88*/	DWORD		GukEarned; 
/*0x1d8c*/	DWORD		MirEarned; 
/*0x1d90*/	DWORD		MMEarned; 
/*0x1d94*/	DWORD		RujEarned;  
/*0x1d9c*/	DWORD		TakEarned; 
/*0x1da0*/  BYTE  		Unknown0x1da0[0x18];
/*0x1db4*/	DWORD		LDoNPoints;   
/*0x1db8*/  BYTE        Unknown0x1db8[0x7aD0]; 
/*0x9888*/  DWORD       CareerFavor; // NOTE: 64-bit #   --> 9318
/*0x988c*/  DWORD       Unknown0x984c; 
/*0x9890*/  DWORD       CurrFavor; // NOTE: 64-bit #
/*0x9894*/  BYTE        Unknown0x9854[0x4];  
/*0x9898*/  DWORD       CombatAbilities[0x32];//-->9328
/*0x9960*/  DWORD       CombatAbilityTimes[0x14]; // ??
/*0x99B0*/  DWORD       CombatAbilityTimes2[0x14]; // ??
/*0x9a00*/  DWORD       GroupLeadershipExp;      // 0-999
/*0x9a04*/  DWORD       RaidLeadershipExp;       // 0-999
/*0x9a08*/  DWORD       GroupLeadershipPoints;   // 0-8  // 
/*0x9a0c*/  DWORD       RaidLeadershipPoints;    // 0-10
/*0x9a10*/	BYTE		field_9a10[0x100];
/*0x9b10*/  BYTE        Unknown0x9b10[0x118];
/*0x9C28*/	struct		_CONTENTS* Bank[NUM_BANK_SLOTS]; // -> 96BC
/*0x9C70*/	BYTE		Unknown0x9b08[0xa8];//-->97AC
/*0x9D18*/	BYTE		Grouped;
/*...   */
/*0xA020*/
} OLDCHARINFO, *POLDCHARINFO; 

// sizeof(_CHARINFO) is 0x9c2c 5-5-2004
typedef struct _CHARINFO {
/*0x0000*/  BYTE  		field_0;
/*0x0001*/  BYTE  		Padding0x1;
/*0x0002*/  CHAR		Name[0x40];
/*0x0042*/  CHAR		Lastname[0x20];
/*0x0062*/  BYTE  		field_62[0x20];
/*0x0082*/  BYTE  		Padding0x82[0x2];
/*0x0084*/  DWORD 		field_84;
/*0x0088*/	BYTE		Gender; 
/*0x0089*/	BYTE		Padding0x89[3]; 
/*0x008c*/	BYTE		Race; 
/*0x008d*/  BYTE        Pading0x8d[0x3];
/*0x0090*/	BYTE		Class; 
/*0x0091*/  BYTE  		Padding0x91[0x3];
/*0x0094*/  DWORD 		field_94;
/*0x0098*/	DWORD		Level; 
/*0x009c*/	DWORD		Exp; 
/*0x00a0*/	DWORD		PracticePoints; 
/*0x00a4*/	DWORD		Mana; 
/*0x00a8*/	DWORD		Endurance;
/*0x00ac*/	DWORD		BaseHP; 
/*0x00b0*/	BYTE		Stunned; 
/*0x00b1*/  BYTE  		Padding0xb1[0x3];
/*0x00b4*/	DWORD		BaseSTR; 
/*0x00b8*/	DWORD		BaseSTA; 
/*0x00bc*/	DWORD		BaseCHA; 
/*0x00c0*/	DWORD		BaseDEX; 
/*0x00c4*/	DWORD		BaseINT; 
/*0x00c8*/	DWORD		BaseAGI; 
/*0x00cc*/	DWORD		BaseWIS; 
/*0x00d0*/  BYTE		Face;
/*0x00d1*/  BYTE  		field_D1[0x9];
/*0x00da*/  BYTE  		Padding0xda[0x2];
/*0x00dc*/  BYTE  		field_DC[0x24];
/*0x0100*/	BYTE		languages[0x20];
/*0x0120*/	struct  	_SPELLBUFF Buff[0x0f]; 
/*0x0210*/	DWORD		SpellBook[NUM_BOOK_SLOTS]; 
/*0x0a10*/  DWORD		MemorizedSpells[0x10];
/*0x0a50*/  BYTE  		field_A50;
/*0x0a51*/  BYTE  		Padding0xa51[0x3];
/*0x0a54*/	FLOAT		y; 
/*0x0a58*/	FLOAT		x; 
/*0x0a5c*/	FLOAT		z; 
/*0x0a60*/	FLOAT		heading; 
/*0x0a64*/  BYTE		standstate;
/*0x0a65*/  BYTE  		Padding0xa65[0x3];
/*0x0a68*/	DWORD		Plat; 
/*0x0a6c*/	DWORD		Gold; 
/*0x0a70*/	DWORD		Silver; 
/*0x0a74*/	DWORD		Copper; 
/*0x0a78*/	DWORD		BankPlat; 
/*0x0a7c*/	DWORD		BankGold; 
/*0x0a80*/	DWORD		BankSilver; 
/*0x0a84*/	DWORD		BankCopper; 
/*0x0a88*/  DWORD 		field_A88;
/*0x0a8c*/  DWORD 		field_A8C;
/*0x0a90*/  DWORD 		field_A90;
/*0x0a94*/  DWORD 		field_A94;
/*0x0a98*/	DWORD		BankSharedPlat; 
/*0x0a9c*/  DWORD 		field_A9C;
/*0x0aa0*/  DWORD 		field_AA0;
/*0x0aa4*/  DWORD 		field_AA4;
/*0x0aa8*/  DWORD 		field_AA8;
/*0x0aac*/  DWORD 		field_AAC;
/*0x0ab0*/  DWORD 		field_AB0;
/*0x0ab4*/  DWORD 		field_AB4;
/*0x0ab8*/  DWORD		Skill[0x64];
/*0x0c48*/  DWORD		InnateSkill[0x19];
/*0x0cac*/  BYTE  		field_CAC;
/*0x0cad*/  BYTE  		field_CAD;
/*0x0cae*/  BYTE  		Padding0xcae[0x2];
/*0x0cb0*/  FLOAT 		field_CB0;
/*0x0cb4*/  FLOAT 		field_CB4;
/*0x0cb8*/  FLOAT 		field_CB8;
/*0x0cbc*/  FLOAT 		field_CBC;
/*0x0cc0*/  BYTE  		field_CC0[0x40];
/*0x0d00*/  DWORD 		field_D00;
/*0x0d04*/  DWORD 		field_D04;
/*0x0d08*/  BYTE  		field_D08[0x74];
/*0x0d7c*/	WORD		zoneId; 
/*0x0d7e*/	WORD		Instance; 
/*0x0d80*/	struct		_SPAWNINFO* pSpawn;  //-->d80
	union { 
     /*0x0d84*/ struct	_INVENTORY	Inventory; 
     /*0x0d84*/ struct	_CONTENTS*	InventoryArray[0x1e]; 
	}; 
/*0x0dfc*/	struct		_CONTENTS* Cursor; 
/*0x0e00*/  DWORD 		field_E00;
/*0x0e04*/  DWORD 		field_E04;
/*0x0e08*/  DWORD 		field_E08;
/*0x0e0c*/  DWORD 		field_E0C;
/*0x0e10*/  DWORD 		field_E10;
/*0x0e14*/  BYTE  		field_E14;
/*0x0e15*/  BYTE  		field_E15;
/*0x0e16*/  BYTE  		Padding0xe16[0x2];
/*0x0e18*/	DWORD		STR; 
/*0x0e1c*/	DWORD		STA; 
/*0x0e20*/	DWORD		CHA; 
/*0x0e24*/	DWORD		DEX; 
/*0x0e28*/	DWORD		INT; 
/*0x0e2c*/	DWORD		AGI; 
/*0x0e30*/	DWORD		WIS; 
/*0x0e34*/  DWORD 		field_E34;
/*0x0e38*/	DWORD		SaveMagic; 
/*0x0e3c*/	DWORD		SaveFire; 
/*0x0e40*/	DWORD		SaveCold; 
/*0x0e44*/	DWORD		SavePoison; 
/*0x0e48*/	DWORD		SaveDisease; 
/*0x0e4c*/  DWORD  		field_E4C;
/*0x0e50*/  DWORD       CurrWeight;
/*0x0e54*/  DWORD 		field_E54;
/*0x0e58*/  DWORD       HPBonus;       //From +HP Gear & Probably Spells
/*0x0e5c*/  DWORD       ManaBonus;       //From +MANA Gear & Probably Spells
/*0x0e60*/  BYTE  		Padding0xe60[0x4];
/*0x0e64*/  DWORD 		field_E64;
/*0x0e68*/  DWORD 		field_E68;
/*0x0e6c*/  DWORD 		field_E6C;
/*0x0e70*/  DWORD 		field_E70;
/*0x0e74*/  DWORD 		field_E74;
/*0x0e78*/  DWORD 		field_E78;
/*0x0e7c*/  BYTE  		Padding0xe7c[0x4];
/*0x0e80*/  DWORD 		field_E80;
/*0x0e84*/  BYTE  		Padding0xe84[0x20];
/*0x0ea4*/  DWORD 		field_EA4;
/*0x0ea8*/  DWORD 		field_EA8;
/*0x0eac*/  DWORD       AttackBonus;  // From gear only
/*0x0eb0*/  DWORD       HPRegenBonus; // From gear only
/*0x0eb4*/  DWORD       ManaRegenBonus;  // From gear only
/*0x0eb8*/  DWORD       DamageShieldBonus;  // From gear only
/*0x0ebc*/  DWORD       AttackSpeed;  // From gear only
/*0x0ec0*/  BYTE  		field_EC0;
/*0x0ec1*/  BYTE  		Padding0xec1[0x3];
/*0x0ec4*/  DWORD 		field_EC4;
/*0x0ec8*/  BYTE  		field_EC8;
/*0x0ec9*/  BYTE  		Padding0xec9[0x3];
/*0x0ecc*/  SPELLBUFF   ShortBuff[0x6];
/*0x0f2c*/  BYTE  		Unknown0xf2c[0x90];
/*0x0fbc*/  BYTE  		field_FBC[0x78];
/*0x1034*/  DWORD       ZoneBoundId;
/*0x1038*/	BYTE		field_1038[0x10]; 
/*0x1048*/  FLOAT		ZoneBoundY; 
/*0x104c*/  BYTE  		field_104C[0x10];
/*0x105c*/  FLOAT		ZoneBoundX; 
/*0x1060*/  BYTE  		field_1060[0x10];
/*0x1070*/  FLOAT		ZoneBoundZ; 
/*0x1074*/  BYTE  		field_1074[0x10];
/*0x1084*/  BYTE  		field_1084[0x14];
/*0x1098*/  DWORD 		field_1098;
/*0x109c*/  DWORD 		Deity;
/*0x10a0*/  DWORD 		GuildID;
/*0x10a4*/  DWORD 		field_10A4;
/*0x10a8*/  DWORD 		field_10A8;
/*0x10ac*/  DWORD 		field_10AC;
/*0x10b0*/  BYTE  		field_10B0;
/*0x10b1*/  BYTE  		field_10B1;
/*0x10b2*/  BYTE  		field_10B2;
/*0x10b3*/  BYTE  		field_10B3;
/*0x10b4*/  BYTE  		GuildStatus;
/*0x10b5*/  BYTE  		Padding0x10b5[0x3];
/*0x10b8*/  DWORD 		Drunkenness;
/*0x10bc*/  BYTE  		field_10BC[0x28];
/*0x10e4*/  DWORD 		AAExp;
/*0x10e8*/  BYTE  		field_10E8;
/*0x10e9*/  BYTE  		PercentEXPtoAA;
/*0x10ea*/  BYTE  		field_10EA;
/*0x10eb*/  BYTE  		field_10EB;
/*0x10ec*/  BYTE  		field_10EC;
/*0x10ed*/  BYTE  		field_10ED;
/*0x10ee*/  BYTE  		field_10EE;
/*0x10ef*/  BYTE  		field_10EF;
/*0x10f0*/  BYTE  		field_10F0;
/*0x10f1*/  BYTE  		Padding0x10f1[0x3];
/*0x10f4*/  BYTE  		field_10F4[0x58];
/*0x114c*/  BYTE  		field_114C[0x24];
/*0x1170*/  BYTE  		field_1170[0xf0];
/*0x1260*/  DWORD 		field_1260;
/*0x1264*/  DWORD 		field_1264;
/*0x1268*/  DWORD 		field_1268;
/*0x126c*/  DWORD 		field_126C;
/*0x1270*/  DWORD 		field_1270;
/*0x1274*/  DWORD 		field_1274;
/*0x1278*/  DWORD 		field_1278;
/*0x127c*/  DWORD 		field_127C;
/*0x1280*/  DWORD 		field_1280;
/*0x1284*/  DWORD 		field_1284;
/*0x1288*/  DWORD 		field_1288;
/*0x128c*/  DWORD 		field_128C;
/*0x1290*/  DWORD 		field_1290;
/*0x1294*/  DWORD		AAPoints;
/*0x1298*/  DWORD 		field_1298;
/*0x129c*/  DWORD 		field_129C;
/*0x12a0*/  BYTE  		field_12A0[0x320];
/*0x15c0*/  DWORD 		field_15C0;
/*0x15c4*/  DWORD 		field_15C4;
/*0x15c8*/  DWORD 		field_15C8;
/*0x15cc*/  DWORD 		field_15CC;
/*0x15d0*/  BYTE  		field_15D0[0x140];
/*0x1710*/  DWORD 		field_1710;
/*0x1714*/  DWORD 		field_1714;
/*0x1718*/  DWORD 		field_1718;
/*0x171c*/  BYTE        UnknownInsertionPoint[0x8];
/*0x1724*/  CHAR		Server[0x20];//-->1724
/*0x17  */  DWORD 		field_173C;
/*0x174 */  BYTE  		field_1740[0x14];
/*0x175 */  BYTE  		field_1754[0x14];
/*0x176 */  DWORD 		field_1768;
/*0x176 */  DWORD 		field_176C;
/*0x177 */  DWORD 		field_1770;
/*0x177 */  DWORD 		field_1774;
/*0x177 */  DWORD 		field_1778;
/*0x177 */  DWORD 		field_177C;
/*0x178 */  DWORD 		field_1780;
/*0x178 */  DWORD 		field_1784;
/*0x178 */  DWORD 		field_1788;
/*0x178 */  BYTE  		field_178C[0x30];
/*0x17b */  BYTE  		field_17BC[0x30];
/*0x17e */  BYTE  		field_17EC[0x30];
/*0x181 */  BYTE  		field_181C[0x30];
/*0x184 */  DWORD 		field_184C;
/*0x185 */  DWORD 		field_1850;
/*0x185 */  BYTE  		field_1854[0x30];
/*0x188 */  DWORD 		field_1884;
/*0x188 */  DWORD 		field_1888;
/*0x188 */  DWORD 		field_188C;
/*0x189 */  DWORD 		field_1890;
/*0x189 */  DWORD 		field_1894;
/*0x189 */  DWORD 		field_1898;
/*0x189 */  DWORD 		field_189C;
/*0x18a */  DWORD 		field_18A0;
/*0x18a */  DWORD 		field_18A4;
/*0x18a */  BYTE  		Padding0x18a8[0xc];
/*0x18b */  DWORD 		field_18B4;
/*0x18b */  DWORD 		field_18B8;
/*0x18b */  DWORD 		field_18BC;
/*0x18c */  DWORD 		field_18C0;
/*0x18c */  DWORD 		field_18C4;
/*0x18c */  DWORD 		field_18C8;
/*0x18c */  DWORD 		field_18CC;
/*0x18d */  DWORD 		field_18D0;
/*0x18d */  DWORD 		field_18D4;
/*0x18d */  DWORD 		field_18D8;
/*0x18d */  DWORD 		field_18DC;
/*0x18e */  DWORD 		field_18E0;
/*0x18e */  DWORD 		field_18E4;
/*0x18e */  DWORD 		field_18E8;
/*0x18e */  DWORD 		field_18EC;
/*0x18f */  DWORD 		field_18F0;
/*0x18f */  DWORD 		field_18F4;
/*0x18f */  DWORD 		field_18F8;
/*0x18f */  DWORD 		field_18FC;
/*0x190 */  DWORD 		field_1900;
/*0x190 */  DWORD 		field_1904;
/*0x190 */  DWORD 		field_1908;
/*0x190 */  DWORD 		field_190C;
/*0x191 */  DWORD 		field_1910;
/*0x191 */  BYTE  		field_1914[0x2000];
/*0x391 */  BYTE  		field_3914[0x4e20];//in-pack slots in this structure
/*0x873 */  BYTE  		field_8734[0xbb8];
/*0x92e */  BYTE  		field_92EC[0x28];
/*0x931 */  DWORD 		field_9314;
/*0x931 */  DWORD       CareerFavor; // NOTE: 64-bit #   -->9320
/*0x931 */  DWORD 		field_931C;
/*0x932 */  DWORD       CurrFavor; // NOTE: 64-bit #   -->9328
/*0x932 */  DWORD 		field_9324;
/*0x932 */  DWORD       CombatAbilities[0x32];//
/*0x93f */  DWORD       CombatAbilityTimes[0x14]; // ??
/*0x944 */  DWORD       CombatAbilityTimes2[0x14]; // ??
/*0x949 */  DWORD       GroupLeadershipExp;      // 0-999
/*0x949 */  DWORD       RaidLeadershipExp;       // 0-999
/*0x949 */  DWORD       GroupLeadershipPoints;   // 0-8  // 
/*0x949 */  DWORD       RaidLeadershipPoints;    // 0-10
/*0x94a */  BYTE  		field_94A0[0x100];
/*0x95a */  BYTE  		field_95A0;
/*0x95a */  BYTE  		Padding0x95a1[0x3];
/*0x95a */  DWORD 		field_95A4;
/*0x95a */  BYTE  		Padding0x95a8[0x18];
/*0x95c */  DWORD 		field_95C0;
/*0x95c */  DWORD 		field_95C4;
/*0x95c */  DWORD 		field_95C8;
/*0x95c */  DWORD 		field_95CC;
/*0x95d */  DWORD 		field_95D0;
/*0x95d */  DWORD 		field_95D4;
/*0x95d */  DWORD 		field_95D8;
/*0x95d */  DWORD 		field_95DC;
/*0x95e */  BYTE  		field_95E0[0x58];
/*0x963 */  BYTE  		field_9638[0x58];
/*0x969 */  DWORD 		field_9690;
/*0x969 */  BYTE  		Padding0x9694[0xc];
/*0x96a */  DWORD 		field_96A0;
/*0x96a */  BYTE  		field_96A4;
/*0x96a */  BYTE  		Padding0x96a5[0x3];
/*0x96a */  DWORD 		field_96A8;
/*0x96a */  DWORD 		field_96AC;
/*0x96b */  DWORD 		field_96B0;
/*0x96b */  BYTE  		Padding0x96b4[0x8];
/*0x96c4*/  BYTE        UnknownInsertionPt2[0x8];
/*0x96cc*/  struct		_CONTENTS* Bank[NUM_BANK_SLOTS];  //-->96cc
/*0x970 */  BYTE  		field_9704[0x90];
/*0x979 */  DWORD 		field_9794;
/*0x979 */  BYTE  		Padding0x9798[0x10];
/*0x97a */  DWORD 		field_97A8;
/*0x97a */  BYTE  		Grouped;
/*0x97a */  BYTE        field_97AD[0x17F];// NOTE group info 97ac-992c
/*0x992 */  BYTE  		field_992C[0x18];
/*0x994 */  BYTE  		field_9944[0x40];
/*0x998 */  BYTE  		field_9984[0x13c];
/*0x9ac */  BYTE  		field_9AC0[0x154];// group leadership
/*0x9c1 */  DWORD 		field_9C14;
/*0x9c1 */  DWORD 		field_9C18;
/*0x9c1c*/
} CHARINFO, *PCHARINFO;


typedef struct _MODELINFONAME {
/*0x00*/    DWORD Unknown0000;
/*0x04*/    DWORD Unknown0004;
/*0x08*/    PCHAR Name;
/*0x0c*/
} MODELINFONAME, *PMODELINFONAME;

typedef struct _MODELINFO_GENERIC {
/*0x00*/    DWORD Type;
/*0x04*/    DWORD Unknown0x04;
/*0x08*/    DWORD Unknown0x08;
/*0x0c*/    DWORD Unknown0x0c;
/*0x10*/    DWORD Unknown0x10;
/*0x14*/
} MODELINFO_GENERIC, *PMODELINFO_GENERIC;

typedef struct _MODELINFO_48 {
/*0x00*/    struct _MODELINFO_GENERIC Header;
/*0x14*/    FLOAT Float1;
/*0x18*/    FLOAT Float2;
/*0x1c*/    FLOAT Float3;
/*0x20*/    struct _MODELINFONAME *pModelName;
/*0x24*/
} MODELINFO_48, *PMODELINFO_48;

typedef struct _MODELINFO_51 {
/*0x00*/    struct _MODELINFO_GENERIC Header;
/*0x14*/    struct _MODELINFONAME *pFontName;
/*0x18*/    PCHAR LabelText;
/*0x1c*/
} MODELINFO_51, *PMODELINFO_51;

// 10/09/2003 build      plazmic
// 12/24/2003 verified   Amadeus
typedef struct _MODELINFO {
/*0x00*/    DWORD   Unknown;
/*0x04*/    PCHAR NameDAG;
/*0x08*/    struct _MODELINFO_GENERIC *pModelInfo;
/*0x0c*/    struct _MODELINFO *pNextInChain;
/*0x10*/    PVOID pUnknown;
/*0x14*/    struct _MODELINFONAME *pTrack1;
/*0x18*/    struct _MODELINFONAME *pTrack2;
   //moredata
} MODELINFO, *PMODELINFO;

// 4/30/2003 build      eqmule
typedef struct _CAMERAINFO {
/*0x00*/   DWORD Unknown0x00;
/*0x04*/   DWORD Unknown0x04;
/*0x08*/   BYTE Unknown0x08[0x8];
/*0x10*/   FLOAT Y;
/*0x14*/   FLOAT X;
/*0x18*/   FLOAT Z;
/*0x1c*/   FLOAT LightRadius;
/*0x20*/
} CAMERAINFO, *PCAMERAINFO;

// actual size 0x54F4h  4-28-2004
typedef struct _ACTORINFO {
/*0x0000*/   struct     _CAMERAINFO *pCamera;
/*0x0004*/   DWORD      T3D_POINTLIGHT;
/*0x0008*/   CHAR      ActorDef[0x40];
/*0x0048*/   FLOAT      Z;  // Z coordinates for the floor where standing
/*0x004c*/   BYTE       Unknown0x04c[0x4];
/*0x0050*/   DWORD      TimeStamp;     // Some kind of timestamp in microseconds. Updates as fast as my display can refresh.
/*0x0054*/   DWORD      Unknown0x054;  // Being set to TimeStamp about once per second
/*0x0058*/   DWORD      LastTick;      // Being set to TimeStamp on every tick?
/*0x005c*/   DWORD      Unknown0x05c;  // Being set to TimeStamp at unknown intervals
/*0x0060*/   BYTE       Unknown0x060[0x14];
/*0x0074*/   DWORD      Unknown0x074;  // Being set to TimeStamp at unknown intervals
/*0x0078*/   DWORD      Unknown0x078;  // Being set to TimeStamp at unknown intervals
/*0x007c*/   BYTE       Unknown0x07c[0x20];
/*0x0090*/ // FLOAT Unknown
/*0x0094*/ // FLOAT Unknown
/*0x009c*/   DWORD      UnderWaterMirror; //copy of UnderWater
/*0x00a0*/   DWORD      SwimmingMirror; //copy of Swimming
/*0x00a4*/   DWORD      FeetWetMirror; //copy of FeetWet
/*0x00a8*/   BYTE       UnderWater;    // 5 = Underwater; otherwise zero
/*0x00a9*/   BYTE       Swimming;      // 5 = Swimming (under or on top of water); otherwise zero
/*0x00aa*/   BYTE       FeetWet;        // 5 = Feet are in the water; otherwise zero
/*0x00ab*/   BYTE       LeftWater;     // 5 = Just got out of water, but still very close to shore
/*0x00ac*/   BYTE       Unknown0x0ac[0x28];
/*0x00d4*/   DWORD      SpellETA;      // Calculated TimeStamp when current spell being cast will land. 0 while not casting.
/*0x00d8*/   BYTE       Unknown0x0d4[0xb0];
/*0x0108*/  // LAYHANDS/HARMTOUCH TIMER
/*0x0170*/  // BACKSTAB/BASH/SLAM TIMER
/*0x0188*/   VOID      *FaceRelatedActorStruct;
/*0x018c*/   DWORD      Unknown0x0188;
/*0x0190*/   DWORD      Animation;
/*0x0194*/   DWORD      Unknown0x190;
/*0x0198*/   BYTE      Unknown0x198[0x1c];   
/*0x01b4*/   struct     _SPAWNINFO   *Mount;   // NULL if no mount present
/*0x01b8*/   BYTE      Unknown0x01b8[0xc];
/*0x01c4*/   DWORD      PetID;
/*0x01c8*/   BYTE      Unknown0x01c4[0x28];
/*0x01f0*/   struct     _SPAWNINFO *pTargetOfTarget;
/*0x01f4*/   BYTE       Unknown0x01f4[0x502d];
/*0x5221*/   CHAR      NameOfLastSuccessfulTargetHit[0x40];
/*0x5261*/   BYTE      Unknown0x5234[0xf];
/*0x5270*/    struct   _MODELINFO *Model[0x15];
/*0x52c4*/    BYTE   Unknown0x52c4[0x0c];
/*0x52d0*/   DWORD      InvitedToGroup; // 1 = currently invited to group
/*0x52d4*/   DWORD   Unknown0x52d4[0x2];
/*0x52dc*/   DWORD      CastingSpellID; // -1 = not casting a spell
/*0x52e0*/   DWORD      Unknown0x52e0[0x8];
/*0x5300*/    struct     _SPAWNINFO   *WhoFollowing;  // NULL if autofollow off
/*0x5304*/    DWORD   Unknown0x5304[0x13];
/*0x5338*/   BYTE      Unknown0x5338[0x20];
/*0x5358*/   FLOAT      Unknown0x5358;
/*0x535c*/   DWORD      Unknown0x535c;
/*0x5360*/   FLOAT      Unknown0x5360;
/*0x5364*/   BYTE       Unknown0x5364[0x128];
/*0x54a4*/   DWORD      Trader;           //0=normal 1=trader -->54A4
/*0x54a8*/   BYTE      Unknown0x54a8[0x4c];
} ACTORINFO, *PACTORINFO; 

#define MODEL_LABEL         0 
#define MODEL_LABELINFO     1
#define MODEL_NULL2         2
#define MODEL_HELD_R        3
#define MODEL_HELD_L        4
#define MODEL_SHIELD        5
#define MODEL_NULL6         6

/*
//Work in progress...
#define MODEL_HEAD			0x00
#define MODEL_HEAD_POINT	0x01
#define MODEL_NULL_1		0x02
#define MODEL_HELD_R		0x03
#define MODEL_HELD_L		0x04
#define MODEL_SHIELD		0x05
#define MODEL_NULL_2		0x06
#define MODEL_TUNIC			0x07
#define MODEL_HAIR			0x08
#define MODEL_BEARD			0x09
#define MODEL_CHEST			0x0a
#define MODEL_GLOVES		0x0b
#define MODEL_GLOVES2		0b0c
*/

typedef struct _ARGBCOLOR {
    union {
        struct {
            BYTE B;
            BYTE G;
            BYTE R;
            BYTE A;
        };
        DWORD ARGB;
    };
} ARGBCOLOR, *PARGBCOLOR;

// 10-22-2003 Lax
typedef struct _EQUIPMENT {
   union {
      struct// EQUIPARRAY
      {
         DWORD Item[9];
      };// Array;
      struct //EQUIPUNIQUE
      {
         DWORD Head;
         DWORD Chest;
         DWORD Arms;
         DWORD Wrists;
         DWORD Hands;
         DWORD Legs;
         DWORD Feet;
         DWORD Primary;
         DWORD Offhand;
      };// Unique;
   };
} EQUIPMENT, *PEQUIPMENT;

// actual size 0x280
typedef struct _OLDSPAWNINFO {
/*0x000*/   BYTE    Unknown0x000;
/*0x001*/   CHAR	Lastname[0x27];  // // Surname on PCs, Newbie Tag on NPCs 
/*0x028*/   FLOAT   Y;
/*0x02c*/   FLOAT   X;
/*0x030*/   FLOAT   Z;
/*0x034*/   FLOAT   SpeedY;
/*0x038*/   FLOAT   SpeedX;
/*0x03C*/   FLOAT   SpeedZ;
/*0x040*/   FLOAT   SpeedRun;
/*0x044*/   FLOAT   Heading;
/*0x048*/   BYTE    Unknown0x048[0xC]; 
/*0x054*/   FLOAT   CameraAngle; 
/*0x058*/   BYTE    Unknown0x058[0x38]; 
/*0x090*/	BYTE	UnknownData0x090[0x8]; // 8 values here (were all 128 for me)
/*0x098*/	BYTE    Unknown0x098[0x38];
/*0x0d0*/	CHAR    Name[0x40]; // ie priest_of_discord00 
/*0x110*/	CHAR    DisplayedName[0x40]; // ie Priest of Discord 
/*0x150*/	FLOAT   SpeedHeading;  
/*0x154*/   struct  _ACTORINFO   *pActorInfo;
/*0x158*/   BYTE    Unknown0x158[0x4];
/*0x15c*/   BYTE	AllowFind;
/*0x15d*/   BYTE    Sneak;  // returns 01 on both Sneak and Shroud of Stealth
/*0x15e*/   BYTE    Linkdead;  // Uncharmable flag when used on mobs?
/*0x15f*/   BYTE	Unknown0x15f;
/*0x160*/   BYTE    LFG;
/*0x161*/   BYTE    Unknown0x161;
/*0x162*/	BYTE	IsABoat; // 1 = a type of boat
/*0x163*/	BYTE	Unknown0x163;
/*0x164*/   ARGBCOLOR ArmorColor[0x7];  // Armor Dye if custom, otherwise Item Tint
/*0x180*/   BYTE	Unknown0x180[0x8];
/*0x188*/   struct  _EQUIPMENT Equipment;
/*0x1b0*/   WORD    Zone;
/*0x1b2*/   WORD    Instance;
/*0x1b4*/   DWORD   Unknown0x1b0; // some pointer
/*0x1b8*/   struct  _SPAWNINFO *pNext;
/*0x1bc*/   struct  _CHARINFO  *pCharInfo;
/*0x1c0*/   BYTE    Unknown0x1bc[0x4];
/*0x1c4*/   struct  _SPAWNINFO *pPrev;
/*0x1c8*/   DWORD   Unknown0x1c4;
/*0x1cc*/   BYTE    Unknown0x1c8[0x8];
/*0x1d4*/   FLOAT   Unknownf0x1d0;
/*0x1d8*/   FLOAT   Unknownf0x1d4;
/*0x1dc*/   FLOAT   Unknownf0x1d8; // commonly used by actor positioning
/*0x1e0*/   FLOAT   AvatarHeight;  // height of avatar from ground when standing
/*0x1e4*/   FLOAT   Unknownf0x1e0;
/*0x1e8*/   BYTE    Type;
/*0x1e9*/   BYTE    Face;      // Needs Testing
/*0x1ea*/   BYTE	BeardColor;
/*0x1eb*/   BYTE	Unknown0x1e7;
/*0x1ec*/   BYTE    Eyes;
/*0x1ed*/   BYTE	Hair;      // Hair with no headgear (?)
/*0x1ee*/   BYTE	BeardType;
/*0x1ef*/   BYTE	Holding;   // 0=holding/wielding nothing
/*0x1f0*/   BYTE    Level;
/*0x1f1*/   BYTE    FaceHair;  // Face/Hair combination with headgear
/*0x1f2*/   BYTE    Gender;
/*0x1f3*/   BYTE    PvPFlag;
/*0x1f4*/   BYTE    HideMode;
/*0x1f5*/   BYTE    StandState;
/*0x1f6*/   BYTE    Class;
/*0x1f7*/   BYTE    Light;
/*0x1f8*/   BYTE    InNonPCRaceIllusion;  // This is buggy ...not sure exact usage
/*0x1f9*/   BYTE    Unknown0x1f6;  // form related, unsure how
/*0x1fa*/   BYTE    GM;
/*0x1fb*/   BYTE    Unknown0x1f8;
/*0x1fc*/   DWORD   SpawnID;
/*0x200*/   DWORD   MasterID;
/*0x204*/   DWORD   Race;
/*0x208*/   DWORD   Anon;
/*0x20c*/   DWORD   Unkonwn0x1d0;
/*0x210*/   DWORD   AFK;
/*0x214*/   DWORD   BodyType;
/*0x218*/   DWORD   HPCurrent;
/*0x21c*/   BYTE    AARank; //0=none 1=first 2=second 3=third 
/*0x21d*/   BYTE    Unknown0x21c[0x3]; 
/*0x220*/   DWORD   GuildStatus;
/*0x224*/   DWORD   Deity;
/*0x228*/   DWORD   HPMax;
/*0x22c*/   DWORD   GuildID;
/*0x230*/   BYTE    Levitate;   //0-normal state  2=levitating 3=mob (not levitating)
/*0x23d*/   BYTE    Unknown0x22d[0xb]; 
} OLDSPAWNINFO, *POLDSPAWNINFO;

// sizeof(_SPAWNINFO) is 0x280
typedef struct _SPAWNINFO {
/*0x000*/  BYTE  		Unknown0x0;
/*0x001*/  CHAR			Lastname[0x27];  // // Surname on PCs, Newbie Tag on NPCs 
/*0x028*/   FLOAT   Y;
/*0x02c*/   FLOAT   X;
/*0x030*/   FLOAT   Z;
/*0x034*/   FLOAT   SpeedY;
/*0x038*/   FLOAT   SpeedX;
/*0x03C*/   FLOAT   SpeedZ;
/*0x040*/   FLOAT   SpeedRun;
/*0x044*/   FLOAT   Heading;
/*0x048*/  FLOAT 		field_48;
/*0x04c*/  DWORD 		field_4C;
/*0x050*/  DWORD 		field_50;
/*0x054*/   FLOAT   CameraAngle; 
/*0x058*/  BYTE  		Unknown0x58[0x78];
/*0x0d0*/	CHAR    Name[0x40]; // ie priest_of_discord00 
/*0x110*/	CHAR    DisplayedName[0x40]; // ie Priest of Discord 
/*0x150*/	FLOAT   SpeedHeading;  
/*0x154*/   struct  _ACTORINFO   *pActorInfo;
/*0x158*/  DWORD 		field_158;
/*0x15c*/  BYTE  		CanFindLocation;
/*0x15d*/   BYTE    Sneak;  // returns 01 on both Sneak and Shroud of Stealth
/*0x15e*/   BYTE    Linkdead;  // Uncharmable flag when used on mobs?
/*0x15f*/  BYTE  		field_15F;
/*0x160*/   BYTE    LFG;
/*0x161*/  BYTE  		field_161;
/*0x162*/	BYTE	IsABoat; // 1 = a type of boat
/*0x163*/  BYTE  		Unknown0x163;
/*0x164*/   ARGBCOLOR ArmorColor[0x9];  // Armor Dye if custom, otherwise Item Tint
/*0x188*/   struct  _EQUIPMENT Equipment;
/*0x1ac*/   WORD    Zone;
/*0x1ae*/   WORD    Instance;
/*0x1b0*/  DWORD 		field_1B0;
/*0x1b4*/   struct  _SPAWNINFO *pNext;
/*0x1b8*/   struct  _CHARINFO  *pCharInfo;
/*0x1bc*/  DWORD 		field_1BC;
/*0x1c0*/   struct  _SPAWNINFO *pPrev;
/*0x1c4*/  BYTE  		Unknown0x1c4[0x4];
/*0x1c8*/  FLOAT 		field_1C8;
/*0x1cc*/  DWORD 		field_1CC;
/*0x1d0*/  FLOAT 		field_1D0;
/*0x1d4*/  FLOAT 		field_1D4;
/*0x1d8*/  FLOAT 		field_1D8;
/*0x1dc*/   FLOAT   AvatarHeight;  // height of avatar from ground when standing
/*0x1e0*/  FLOAT 		field_1E0;
/*0x1e4*/   BYTE    Type;
/*0x1e5*/   BYTE    Face;      // Needs Testing
/*0x1e6*/   BYTE	BeardColor;
/*0x1e7*/   BYTE	Field_1E7;
/*0x1e8*/   BYTE    Eyes;
/*0x1e9*/   BYTE	Hair;      // Hair with no headgear (?)
/*0x1ea*/   BYTE	BeardType;
/*0x1eb*/   BYTE	Holding;   // 0=holding/wielding nothing
/*0x1ec*/   BYTE    Level;
/*0x1ed*/   BYTE    FaceHair;  // Face/Hair combination with headgear
/*0x1ee*/   BYTE    Gender;
/*0x1ef*/   BYTE    PvPFlag;
/*0x1f0*/   BYTE    HideMode;
/*0x1f1*/   BYTE    StandState;
/*0x1f2*/   BYTE    Class;
/*0x1f3*/   BYTE    Light;
/*0x1f4*/   BYTE    InNonPCRaceIllusion;  // This is buggy ...not sure exact usage
/*0x1f5*/   BYTE    Field_1F5;  // form related, unsure how
/*0x1f6*/   BYTE    GM;
/*0x1f7*/   BYTE    Field_1F7;
/*0x1f8*/   DWORD   SpawnID;
/*0x1fc*/   DWORD   MasterID;
/*0x200*/   DWORD   Race;
/*0x204*/   DWORD   Anon;
/*0x208*/  DWORD 		field_208;
/*0x20c*/  DWORD 		AFK;
/*0x210*/   DWORD   BodyType;
/*0x214*/   DWORD   HPCurrent;
/*0x218*/  BYTE		AARank;
/*0x219*/   BYTE    Unknown0x21c[0x3]; 
/*0x21c*/   DWORD   GuildStatus;
/*0x220*/   DWORD   Deity;
/*0x224*/   DWORD   HPMax;
/*0x228*/   DWORD   GuildID;
/*0x22c*/   BYTE    Levitate;   //0-normal state  2=levitating 3=mob (not levitating)
/*0x22d*/   BYTE    Unknown0x22d[0xb]; 
/*0x230*/  BYTE  		Unknown0x230[0x4];
/*0x234*/  DWORD 		field_234;
/*0x238*/  BYTE  		Unknown0x238[0x47];
/*0x27f*/  BYTE  		field_27F;
/*0x280*/
} SPAWNINFO, *PSPAWNINFO;


#define STANDSTATE_STAND            0x64
#define STANDSTATE_BIND             0x69
#define STANDSTATE_SIT              0x6E
#define STANDSTATE_DUCK             0x6F
#define STANDSTATE_FEIGN            0x73
#define STANDSTATE_DEAD             0x78

#define MONITOR_SPAWN_X             1
#define MONITOR_SPAWN_Y             2
#define MONITOR_SPAWN_Z             4
#define MONITOR_SPAWN_HEADING       8
#define MONITOR_SPAWN_SPEEDRUN      16
#define MONITOR_SPAWN_HPCURRENT     32

typedef struct _SPAWNMONITORINFO {
    WORD SpawnID;
    FLOAT Y;
    FLOAT X;
    FLOAT Z;
    FLOAT Heading;
    FLOAT SpeedRun;
    DWORD HPCurrent;
    DWORD MonitorMask;
} SPAWNMONITORINFO, *PSPAWNMONITORINFO;

typedef struct _EQSWITCH {
/*0x00*/	DWORD		Value0x00;
/*0x04*/	DWORD		Value0x04;
/*0x08*/	PVOID		pUnknown0x08;
/*0x0C*/	DWORD		Value0x0C;
/*0x10*/	FLOAT		Y;
/*0x14*/	FLOAT		X;
/*0x18*/	FLOAT		Z;
/*0x1C*/	FLOAT		Heading;
/*0x20*/	DWORD		Unknown0x20;
/*0x24*/	DWORD		Unknown0x24;
/*0x28*/	DWORD		Value0x28;
/*0x2C*/	PVOID		pUnknown0x2C;
/*0x30*/	DWORD		Unknown0x30;
/*0x34*/	FLOAT		Value0x34;
/*0x38*/	FLOAT		Value0x38;
/*0x3C*/	DWORD		Unknown0x3C;
/*0x40*/	PVOID		pUnknown0x40;
/*0x44*/	PVOID		pUnknown0x44;
/*0x48*/	DWORD		Value0x48;
/*0x4C*/	DWORD		Value0x4C;
/*0x50*/	PVOID		pUnknown0x50;
/*0x54*/	DWORD		Unknown0x54;
/*0x58*/	DWORD		Unknown0x58;
/*0x5C*/	DWORD		Unknown0x5C;
/*0x60*/	DWORD		Value0x60;
/*0x64*/	PVOID		pUnknown0x64;
} EQSWITCH, *PEQSWITCH;

typedef struct _DOOR {
/*0x00*/   BYTE Unknown0x00;
/*0x01*/   BYTE ID;
/*0x02*/   CHAR Name[0x0b];
/*0x0d*/   BYTE Unknown0x0d[0x7];
/*0x14*/   FLOAT DefaultY;
/*0x18*/   FLOAT DefaultX;
/*0x1c*/   FLOAT DefaultZ;
/*0x20*/   FLOAT DefaultHeading;
/*0x24*/   FLOAT DoorAngle;
/*0x28*/   FLOAT Y;
/*0x2c*/   FLOAT X;
/*0x30*/   FLOAT Z;
/*0x34*/   FLOAT Heading;
/*0x38*/   BYTE Unknown0x38[0x3c];
/*0x74*/   PEQSWITCH pSwitch; // (class EQSwitch *)
/*0x78*/
} DOOR, *PDOOR;

// 7-21-2003    Stargazer
typedef struct _DOORTABLE {
/*0x000*/   DWORD NumEntries;
/*0x004*/   PDOOR pDoor[0x0FF];
/*0x400*/
} DOORTABLE, *PDOORTABLE;

// actual size 0x5c  2-18-2004 lax
// 8-26-2003 mule
typedef struct _GROUNDITEM {
/*0x00*/ struct _GROUNDITEM *pPrev;
/*0x04*/ struct _GROUNDITEM *pNext;
/*0x08*/ DWORD ID;
/*0x0C*/ DWORD DropID;
/*0x10*/ DWORD Unknown0x10;
/*0x14*/ PEQSWITCH pSwitch; // (class EQSwitch *)
/*0x18*/ DWORD Unknown0x18;
/*0x1C*/ FLOAT Heading;
/*0x20*/ FLOAT Z;
/*0x24*/ FLOAT X;
/*0x28*/ FLOAT Y;
/*0x2C*/ CHAR Name[0x18];
/*0x44*/
} GROUNDITEM, *PGROUNDITEM;

// 5-15-2003    Amadeus
#define   MAX_ZONES                                    0x129   
extern    PCHAR szZoneExpansionName[];     //defined in LibEQ_Utilities.cpp
typedef struct _ZONELIST {
/*0x000*/   DWORD   Header;
/*0x004*/   DWORD   Expansion;          // szZoneExpansionName[]
/*0x008*/   WORD    Id;
/*0x00a*/   WORD    Instance;
/*0x00c*/   CHAR    ShortName[0x81];
/*0x08d*/   CHAR    LongName[0x103];
/*0x190*/   DWORD   Flags;              // (Flags & 0x100000) = HasMinLevel, 0x4000 no air, 0x2 newbie zone, 0x20 no bind, 0x400000 something
/*0x194*/   DWORD   Id2;                // This is Id+2242
/*0x198*/   DWORD   PoPValue;           // This has something to do with PoP zones.
/*0x19c*/   DWORD   MinLevel;           // Minimum level to access
/*0x1a0*/   WORD    Unknown0x1a0;         
/*0x1a2*/   BYTE    Unknown0x1a2[0x6];   
/*0x1a8     Next Zone in list */
} ZONELIST, *PZONELIST;

typedef struct _WORLDDATA {
/*0x000*/ PVOID lpvTable;
/*0x004*/ BYTE Hour;
/*0x005*/ BYTE Minute;
/*0x006*/ BYTE Day;
/*0x007*/ BYTE Month;
/*0x008*/ DWORD Year;
/*0x00C*/ BYTE Unknown0x00c[0x10];
/*0x01C*/ PZONELIST ZoneArray[MAX_ZONES];
} WORLDDATA, *PWORLDDATA;

// 5-15-2003    Amadeus (discovered by Lax)
// Actual Size 0x240, old
typedef struct _ZONEINFO {
/*0x000*/   CHAR    CharacterName[0x40];
/*0x040*/   CHAR    ShortName[0x20];
/*0x060*/   CHAR    LongName[0x80];
/*0x0E0*/   CHAR    Unknown0x0e0[0x96];  // <-- this isnt part of zone name, see CEverQuest__CEverQuest
/*0x176*/   BYTE    ZoneType; // (usually FF)
/*0x177*/	ARGBCOLOR FogRed;
/*0x17b*/	ARGBCOLOR FogGreen;
/*0x17f*/	ARGBCOLOR FogBlue;
/*0x183*/   BYTE    Unknown0x183;
/*0x184*/   BYTE	Unknown0x184[0x10];
/*0x194*/   BYTE    Unknown0x194[0x10];
/*0x1a4*/   FLOAT   ZoneGravity;
/*0x1a8*/   BYTE    Unknown0x1a8[0x4];
/*0x1ac*/   BYTE    Unknown0x1ac[0x2e];
/*0x1da*/	BYTE	SkyType;	
/*0x1db*/	BYTE	Unknown0x1db[0xd];
/*0x1e8*/   FLOAT   ZoneExpModifier;    //This has been nerfed ..now reads 1.0 for all zones
/*0x1ec*/   FLOAT   SafeYLoc;
/*0x1f0*/   FLOAT   SafeXLoc;
/*0x1f4*/   FLOAT   SafeZLoc;
/*0x1f8*/   FLOAT   Ceiling;
/*0x1fc*/   FLOAT   Floor; 
/*0x200*/   FLOAT   MinClip; 
/*0x204*/   FLOAT   MaxClip; 
/*0x208*/   BYTE    Unknown0x208[0x18];
/*0x220*/   BYTE    Unknown0x220[0x20];
/*0x240*/
} ZONEINFO, *PZONEINFO;

#define   TOTAL_SPELL_COUNT         0x157C       // # of spells in game
// note: fuck using TOTAL_SPELL_COUNT in the struct, but keep it for users to use
// because they cant figure out how to use pSpellMgr->InvalidSpell
typedef struct _SPELLMGR {
            BYTE                unknown[0x24];
            struct  _SPELL*     Spells[TOTAL_SPELL_COUNT];
            struct  _SPELL*     Spells2[TOTAL_SPELL_COUNT];
			struct _SPELL*		InvalidSpell;
} SPELLMGR, *PSPELLMGR;


// size 0x1f4 2004-05-05 lax
typedef struct _SPELL { 
/*0x000*/   DWORD   ID; 
/*0x004*/   FLOAT   Range; 
/*0x008*/   FLOAT   AERange; 
/*0x00c*/	FLOAT	PushBack;
/*0x010*/   BYTE    Unknown0x00c[0x04];  
/*0x014*/   DWORD   CastTime; 
/*0x018*/   DWORD   FizzleTime; 
/*0x01c*/   DWORD   RecastTime; 
/*0x020*/   DWORD   DurationType;       //DurationFormula on Lucy 
/*0x024*/   DWORD   DurationValue1; 
/*0x028*/   DWORD   Unknown0x028; 
/*0x02c*/   DWORD   Mana; 
/*0x030*/   LONG    Base[0x0c];         //Base1-Base12 
/*0x060*/   LONG    Base2[0x0c];     //Mostly unused, setting name to Base2 from Lucy for now 
/*0x090*/   LONG    Max[0x0c];          //Max1-Max12 
/*0x0c0*/   DWORD   BookIcon; 
/*0x0c4*/   DWORD   GemIcon; 
/*0x0c8*/   DWORD   ReagentId[0x4];     //ReagentId1-ReagentId4 
/*0x0d8*/   DWORD   ReagentCount[0x4];  //ReagentCount1-ReagentCount4 
/*0x0e8*/   BYTE	Unknown0x0e8[0x10]; 
/*0x0f8*/   BYTE	Calc[0x0c];         //Calc1-Calc12 
/*0x104*/   BYTE	LightType; 
/*0x105*/   BYTE	SpellType;          //0=detrimental, 1=Beneficial, 2=Beneficial, Group Only
/*0x106*/   BYTE	Unknown0x106; 
/*0x107*/   BYTE    Resist;             //0=un 1=mr 2=fr 3=cr 4=pr 5=dr 6=chromatic
/*0x108*/   BYTE	Attrib[0x0c];       //Attrib1-Attrib12 
/*0x114*/   BYTE    TargetType;         // 03=Group v1, 04=PB AE, 05=Single, 06=Self, 08=Targeted AE, 0e=Pet, 28=AE PC v2, 29=Group v2
/*0x115*/   BYTE	FizzleAdj; 
/*0x116*/   BYTE	Skill; 
/*0x117*/   BYTE    Location;            // 01=Outdoors, 02=dungeons, ff=Any 
/*0x118*/   BYTE	Environment;
/*0x119*/   BYTE	TimeOfDay;		     // 0=any, 1=day only, 2=night only
/*0x11a*/	BYTE	Unknown0x11a;
/*0x11b*/   BYTE    Level[0x10];         // per class. 
/*0x12b*/   BYTE    Unknown0x12b[0x12]; 
/*0x13d*/   BYTE    CastingAnim;	//-->13d	
/*0x13e*/	BYTE	Unknown0x13e[0x6];
/*0x144*/   DWORD   descnum; 
/*0x148*/   BYTE    Uninterruptable;  // 00=Interruptable, 01=Uninterruptable 
/*0x149*/	BYTE	Unknown0x149;
/*0x14a*/	BYTE	Deletable;
/*0x14b*/   BYTE    Unknown0x14b;	
/*0x14c*/   DWORD   Autocast;  // SpellID of spell to instacast on caster when current spell lands on target 
/*0x150*/	BYTE	Unknown0x150[0x06];
/*0x156*/   BYTE    DurationWindow; // 0=Long, 1=Short
/*0x157*/   BYTE    Unknown0x157;
/*0x158*/   DWORD   Unknown144;  // Unknown144 from lucy 
/*0x15c*/   DWORD   Unknown145;  // Unknown145 from lucy 
/*0x160*/   DWORD   Unknown0x160; 
/*0x164*/   BYTE    Unknown0x164;
/*0x165*/	BYTE	Unknown0x165;  //data here on detrimental spells
/*0x166*/	BYTE	Unknown0x166;  //data here on detrimental spells 
/*0x167*/	BYTE	Unknown0x167[0x45];////184->184  1a0->1a4
/*0x1ac*/   CHAR	*Name;// -->1ac
/*0x1  */   CHAR	*Target; 
/*0x1a */   CHAR	*Extra;			// This is 'Extra' from Lucy (portal shortnames etc)
/*0x1a */   CHAR	*Unknown0x1a8; //
/*0x1a */   CHAR	*Unknown0x1ac;      
/*0x1b */   CHAR	*CastOnYou; 
/*0x1b */   CHAR	*CastOnAnother; 
/*0x1b */   CHAR	*WearOff; 
/*0x1b */   CHAR	*Unknown0x1bc; //  
/*0x1c */   DWORD   spaindex; //
/*0x1c */   CHAR	*Unknown0x1c4;      
/*0x1c */   DWORD   SpellAnim; 
/*0x1c */   DWORD   Unknown0x1cc; 
/*0x1d */   DWORD   Unknown130;    // This is Unknown130 from Lucy 
/*0x1d */   DWORD   Unknown0x1d4; 
/*0x1d */   DWORD   SpellIcon; 
/*0x1d */	DWORD	ResistAdj;
/*0x1e */
} SPELL, *PSPELL;

// Size 0x180 4-23-2004 Lax
typedef struct _SKILL {
/*0x000*/   DWORD nName;
/*0x004*/   DWORD ReuseTimer;
/*0x008*/   CHAR  Unknown0x008;
/*0x009*/   CHAR  Unknown0x009;
/*0x00A*/   CHAR  AltTimer;//compare to 2 all over.. alternate timer?
/*0x00B*/   CHAR  Unknown0x00B;
/*0x00C*/   CHAR  Unknown0x00C;
/*0x00D*/   CHAR  MinLevel[0x22];
/*0x02F*/   CHAR  Unused0x02F;
/*0x030*/   CHAR  StartingSkill[0x22];
/*0x052*/   CHAR  Unknown0x052[0x6];
/*0x058*/   DWORD SkillCapsPre50[0x22];
/*0x0E0*/   DWORD Unknown0x0E0;// 1 for backstab..
/*0x0E4*/   DWORD Unknown0x0E4;// 
/*0x0E8*/   DWORD Unknown0x0E8;
/*0x0EC*/   FLOAT Accuracy;
/*0x0F0*/   DWORD Unknown0x0F0;
/*0x0F4*/   DWORD SkillCapsPost50[0x22];
/*0x17C*/   DWORD Unknown0x17C;
/*0x180*/
} SKILL, *PSKILL;

#define MAX_GUILDS			0x200
typedef struct _GUILDS {
/*0x0000*/ PVOID	pOneEntryVTable;
/*0x0004*/ BYTE		UnknownByte0x0005;
/*0x0005*/ BYTE		Unknown0x0005[0x3f];
/*0x0044*/ DWORD	UnknownValue0x0044;
/*0x0048*/ DWORD	UnknownValue0x0048;
/*0x004c*/ CHAR		GuildName[MAX_GUILDS][0x40];
/*0x804c*/ BYTE		UnknownByteArray0x804c[0x200];
/*0x824c*/ BYTE		UnknownByteArray0x824c[0x40];
/*0x828c*/
} GUILDS, *PGUILDS;

//works for 23 dec 2003 patch
#define EQ_INTERACTGROUNDITEM 0x00FB
typedef struct _INTERACTGROUNDITEM {
	DWORD DropID;
	DWORD SpawnID;
} INTERACTGROUNDITEM, *PINTERACTGROUNDITEM;

typedef struct _SPELLFAVORITE {
/*0x000*/   DWORD   SpellId[8];
/*0x020*/   CHAR    Name[25];
/*0x039*/   BYTE    Byte_39;
/*0x03A*/   BYTE    Byte_3A;
/*0x03B*/   BYTE    Byte_3B;
/*0x03C*/
} SPELLFAVORITE, *PSPELLFAVORITE;

typedef struct _CMDLIST {
    DWORD LocalizedStringID;
    PCHAR szName;
    PCHAR szLocalized;
    VOID  (__cdecl *fAddress)(PSPAWNINFO, PCHAR);
    DWORD Restriction;
    DWORD Category;
} CMDLIST, *PCMDLIST;

typedef struct _EQSOCIAL {
/*0x0000*/   CHAR   Name[0x10];
/*0x0010*/   CHAR   Line[0x5][0x100];
/*0x0510*/   BYTE   Color; 
} EQSOCIAL, *PEQSOCIAL;

typedef struct _EQFRIENDSLIST {
/*0x0000*/ CHAR Name[0x64][0x40];
/*0x1900*/
} EQFRIENDSLIST, *PEQFRIENDSLIST;

// size 0x50
typedef struct _ALTABILITY {
/*0x00*/ DWORD nShortName;
/*0x04*/ DWORD nShorterName;
/*0x08*/ DWORD nName;
/*0x0C*/ DWORD nDesc;
/*0x10*/ DWORD MinLevel;
/*0x14*/ DWORD Cost;//cost?
/*0x18*/ LONG RequiresAbility;//requires ability? (-1 for no)
/*0x1C*/ DWORD RequiresAbilityPoints;//requires points in this ability?
/*0x20*/ DWORD MaxRank;//BYTE
/*0x24*/ DWORD AARankRequired;
/*0x28*/ DWORD Unknown0x28;//BYTE
/*0x2C*/ LONG  SpellID;// -1 for no
/*0x30*/ BYTE  Unused0x30;
/*0x31*/ BYTE  Type;
/*0x32*/ BYTE  Unknown0x32[0x2];
/*0x34*/ DWORD Unused0x34;
/*0x38*/ DWORD Unknown0x38;//
/*0x3C*/ DWORD Unknown0x3C;
/*0x40*/ DWORD Unknown0x40;// aa level needed?
/*0x44*/ BYTE Unknown0x44;//BYTE
/*0x45*/ BYTE Unknown0x45;//BYTE
/*0x46*/ BYTE Unknown0x46;//BYTE
/*0x47*/ BYTE Unknown0x47;//BYTE
/*0x48*/ LONG ReuseTimer;// in seconds
/*0x4C*/ DWORD Unknown0x4C;//
/*0x50*/
} ALTABILITY, *PALTABILITY;

// total size 0x4D4 04-21-2004 lax
#define NUM_ALT_ABILITIES 0x135
typedef struct _ALTADVMGR {
/*0x000*/ PALTABILITY Abilities[NUM_ALT_ABILITIES];
/*0x4D4*/
} ALTADVMGR, *PALTADVMGR;

// size 0xD8
typedef struct _EQRAIDMEMBER {
/*0x00*/ CHAR Name[0x40]; // 
/*0x40*/ CHAR Level[0x08];
/*0x48*/ CHAR Class[0x20];
/*0x68*/ BYTE Unknown0x68[0x60];
/*0xC8*/ DWORD Field_C8;
/*0xCC*/ BYTE  RaidLeader;
/*0xCD*/ BYTE  GroupLeader;
/*0xCE*/ BYTE  Field_CE;
/*0xCF*/ BYTE  Field_CF;
/*0xD0*/ BYTE  Field_D0;
/*0xD1*/ BYTE  Padding0xD1[0x3];
/*0xD4*/ DWORD GroupNumber;
/*0xD8*/
} EQRAIDMEMBER, *PEQRAIDMEMBER;

// sizeof(_EQRAID) is 0x44b8
typedef struct _EQRAID {
/*0x0000*/  BYTE  		Unknown0x0[0x154];
/*0x0154*/  CHAR  		RaidMemberUsed[0x48];
/*0x019c*/  struct		_EQRAIDMEMBER RaidMember[0x48];
/*0x3e5c*/  DWORD 		field_3E5C;
/*0x3e60*/  DWORD 		RaidMemberCount;
/*0x3e64*/  CHAR  		RaidLeaderName[0x40];
/*0x3ea4*/  BYTE  		Unknown0x3ea4[0x140];
/*0x3fe4*/  DWORD 		field_3FE4;
/*0x3fe8*/  BYTE  		Unknown0x3fe8;
/*0x3fe9*/  BYTE  		IsRaidLeader;
/*0x3fea*/  BYTE  		Unknown0x3fea[0x2];
/*0x3fec*/  DWORD 		RaidTarget;
/*0x3ff0*/  DWORD 		LootType;
/*0x3ff4*/  CHAR  		RaidLooters[0x13][0x40];
/*0x44b4*/  DWORD 		TotalRaidMemberLevels;
/*0x44b8*/
} EQRAID, *PEQRAID;

// size 0x08
typedef struct _EQSTRING {
/*0x00*/	DWORD ID;
/*0x04*/	PCHAR String;
} EQSTRING, *PEQSTRING;

// size 0x10 4-28-2004 lax
typedef struct _EQSTRINGTABLE {
/*0x00*/ struct _EQSTRING **StringItems;
/*0x04*/ DWORD Size;
/*0x08*/ DWORD Count;
/*0x0c*/ DWORD Unknown0x0c;
/*0x10*/
} EQSTRINGTABLE, *PEQSTRINGTABLE;

};
using namespace EQData;
