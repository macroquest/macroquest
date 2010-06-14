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
namespace EQData
{

// ***************************************************************************
// Defines
// ***************************************************************************

enum PlayerClass
{
    Unknown=                            0,
    Warrior=                            1,
    Cleric=                             2,
    Paladin=                            3,
    Ranger=                             4,
    Shadowknight=                       5,
    Druid=                              6,
    Monk=                               7,
    Bard=                               8,
    Rogue=                              9,
    Shaman=                            10,
    Necromancer=                       11,
    Wizard=                            12,
    Mage=                              13,
    Enchanter=                         14,
    Beastlord=                         15,
    Berserker=                         16,
    TotalClasses=                      16,
};
// class 20 through 35 are the NPC GMs (same class order as above)
// class 41   Merchant
// class 60   LDoN Recruiter
// class 61   LDoN Merchant
// class 63   Tribute Master
// class 67   DoN Merchant (Norrath's Keepers)
// class 68   DoN Merchant (Dark Reign)

typedef struct _ClassInfo
{
    bool CanCast;
    bool PureCaster;
    bool PetClass;
    bool DruidType;
    bool NecroType;
    bool ClericType;
    bool ShamanType;
    char RaidColorOrder;
    PCHAR Name;
    PCHAR ShortName;
} CLASSINFO, *PCLASSINFO;

static _ClassInfo ClassInfo[]=
{
    {0,0,0,0,0,0,0,0,"",""},                        //unk
    {0,0,0,0,0,0,0,13,"Warrior","war"},             //war
    {1,1,0,0,0,1,0,2,"Cleric","clr"},               //clr
    {1,0,0,0,0,1,0,8,"Paladin","pal"},              //pal
    {1,0,0,1,0,0,0,9,"Ranger","rng"},               //rng
    {1,0,0,0,1,0,0,11,"Shadowknight","shd"},        //shd
    {1,1,0,1,0,0,0,3,"Druid","dru"},                //dru
    {0,0,0,0,0,0,0,6,"Monk","mnk"},                 //mnk
    {1,0,0,0,0,0,0,0,"Bard","brd"},                 //brd
    {0,0,0,0,0,0,0,10,"Rogue","rog"},               //rog
    {1,1,1,0,0,0,1,12,"Shaman","shm"},              //shm
    {1,1,1,0,1,0,0,7,"Necromancer","nec"},          //nec
    {1,1,0,0,0,0,0,14,"Wizard","wiz"},              //wiz
    {1,1,1,0,0,0,0,5,"Mage","mag"},                 //mag
    {1,1,0,0,0,0,0,4,"Enchanter","enc"},            //enc
    {1,0,1,0,0,0,1,1,"Beastlord","bst"},            //bst
    {0,0,0,0,0,0,0,15,"Berserker","ber"},           //ber
};

enum GroupAbilityLevels { 
   G_MarkNPC=                           0,          //0-3 
   G_NPCHealth=                         1,          //0-1 
   G_DelegateMA=                        3,          //0-1 
   G_DelegateMarkNPC=                   4,          //0-1 
   G_InspectBuffs=                      6,          //0-2 
   G_SpellAwareness=                    8,          //0-1 
   G_OffenseEnhancement=                9,          //0-5 
   G_ManaEnhancement=                  10,          //0-3 
   G_HealthEnhancement=                11,          //0-3 
   G_HealthRegen=                      12,          //0-3 
   G_FindPathtoPC=                     13,          //0-1 
   G_HealthofTargetsTarget=            14,          //0-1 
}; 

enum RaidAbilityLevels { 
   R_MarkNPC=                           0,          //0-3 
   R_NPCHealth=                         1,          //0-1 
   R_DelegateMA=                        3,          //0-3 
   R_DelegateMarkNPC=                   4,          //0-4 
   R_SpellAwareness=                    7,          //0-1 
   R_OffenseEnhancement=                8,          //0-5 
   R_ManaEnhancement=                   9,          //0-3 
   R_HealthEnhancement=                10,          //0-3 
   R_HealthRegen=                      11,          //0-3 
   R_FindPathtoPC=                     12,          //0-1 
   R_HealthofTargetsTarget=            13,          //0-1 
}; 

#define BI_TARGETABLE                   1
#define BI_TRIGGER                      2 
#define BI_TRAP                         4
#define BI_TIMER                        8

typedef struct _BodyInfo
{
    PCHAR Name;
    DWORD Flags;
} BODYINFO, *PBODYINFO;

#define SPAWN_PLAYER                    0
#define SPAWN_NPC                       1
#define SPAWN_CORPSE                    2
//#define SPAWN_ANY                       3
//#define SPAWN_PET                       4

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

#define ITEMITEMTYPE_FOOD               0x0e 
#define ITEMITEMTYPE_WATER              0x0f 
#define ITEMITEMTYPE_ALCOHOL            0x26 
#define ITEMITEMTYPE_POISON             0x2a 
#define ITEMITEMTYPE_AUGUMENT           0x36 

#define ITEMEFFECTTYPE_COMBAT           0x00 
#define ITEMEFFECTTYPE_INVENTORY1       0x01 // Bards need to stop sing to cast 
#define ITEMEFFECTTYPE_WORN             0x02 
#define ITEMEFFECTTYPE_INVENTORY2       0x03 
#define ITEMEFFECTTYPE_MUSTEQUIP        0x04 // Bards need to stop sing to cast 
#define ITEMEFFECTTYPE_INVENTORY3       0x05 

#define SKILLMINDAMAGEMOD_BASH          0x00 
#define SKILLMINDAMAGEMOD_BACKSTAB      0x01 
#define SKILLMINDAMAGEMOD_DRAGONPUNCH   0x02 
#define SKILLMINDAMAGEMOD_EAGLESTRIKE   0x03 
#define SKILLMINDAMAGEMOD_FLYINGKICK    0x04 
#define SKILLMINDAMAGEMOD_KICK          0x05 
#define SKILLMINDAMAGEMOD_ROUNDKICK     0x06 
#define SKILLMINDAMAGEMOD_TIGERCLAW     0x07 
#define SKILLMINDAMAGEMOD_FRENZY        0x08 

#define COLOR_DEFAULT                   0x00
#define COLOR_DARKGREY                  0x01
#define COLOR_DARKGREEN                 0x02
#define COLOR_DARKBLUE                  0x03
#define COLOR_PURPLE                    0x05
#define COLOR_LIGHTGREY                 0x06

#define CONCOLOR_GREY                   0x06
#define CONCOLOR_GREEN                  0x02
#define CONCOLOR_LIGHTBLUE              0x12
#define CONCOLOR_BLUE                   0x04
#define CONCOLOR_BLACK                  0x14
#define CONCOLOR_WHITE                  0x0a
#define CONCOLOR_YELLOW                 0x0f
#define CONCOLOR_RED                    0x0d

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
#define USERCOLOR_NPC_RAMPAGE           0xFF +  49 //  49 - NPC Rampage
#define USERCOLOR_NPC_FLURRY            0xFF +  50 //  50 - NPC Furry
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
#define USERCOLOR_RESERVED              0xFF +  70 //  70 - "unused at this time" 
#define USERCOLOR_LINK                  0xFF +  71 //  71 - item links 
#define USERCOLOR_RAID                  0xFF +  72 //  72 - raid 
#define USERCOLOR_PET                   0xFF +  73 //  73 - my pet 
#define USERCOLOR_DAMAGESHIELD          0xFF +  74 //  74 - damage shields 
#define USERCOLOR_LEADER                0xFF +  75 //  75 - LAA-related messages 
#define USERCOLOR_PETRAMPFLURRY         0xFF +  76 //  76 - pet rampage/flurry 
#define USERCOLOR_PETCRITS              0xFF +  77 //  77 - pet's critical hits 
#define USERCOLOR_FOCUS                 0xFF +  78 //  78 - focus item activation 
#define USERCOLOR_XP                    0xFF +  79 //  79 - xp gain/loss 
#define USERCOLOR_SYSTEM                0xFF +  80 //  80 - system broadcasts etc 
#define USERCOLOR_PET_SPELLS            0xFF +  81 //  81 - pet spells
#define USERCOLOR_PET_RESPONSES         0xFF +  82 //  82 - pet responses
#define USERCOLOR_ITEM_SPEECH           0xFF +  83 //  83 - item speech
#define USERCOLOR_STRIKETHROUGH         0xFF +  84 //  84 - strikethrough messages
#define USERCOLOR_STUN                  0XFF +  85 //  85 - stun messages
#define USERCOLOR_RESERVED2             0xFF +  86 //  86 - "unused at this time" (or unknown!?)
#define USERCOLOR_FELLOWSHIP            0xFF +  87 //  87 - fellowship messages
#define USERCOLOR_NPC_SPEECH            0xFF +  88 //  88 - npc dialogue
#define USERCOLOR_NPC_SPEECH_TO_YOU     0xFF +  89 //  89 - npc dialogue to you
#define USERCOLOR_GUILD_MSG             0xFF +  90 //  90 - guild messages

#define DEITY_Bertoxxulous              201
#define DEITY_BrellSerilis              202
#define DEITY_CazicThule                203
#define DEITY_ErollisiMarr              204
#define DEITY_Bristlebane               205
#define DEITY_Innoruuk                  206
#define DEITY_Karana                    207
#define DEITY_MithanielMarr             208
#define DEITY_Prexus                    209
#define DEITY_Quellious                 210
#define DEITY_RallosZek                 211
#define DEITY_RodcetNife                212
#define DEITY_SolusekRo                 213
#define DEITY_TheTribunal               214
#define DEITY_Tunare                    215
#define DEITY_Veeshan                   216

#define ITEMTYPE_NORMAL                 0
#define ITEMTYPE_PACK                   1
#define ITEMTYPE_BOOK                   2

#define COMP_NONE                       0
#define COMP_EQ                         1
#define COMP_NE                         2
#define COMP_GT                         3
#define COMP_LT                         4
#define COMP_GE                         5
#define COMP_LE                         6
#define COMP_CONT                       7
#define COMP_NOTCONT                    8
#define COMP_BITAND                     9
#define COMP_BITOR                      10

#define COMP_TYPE_STRING                0
#define COMP_TYPE_NUMERIC               1
#define COMP_TYPE_BIT                   2

#define CMD_MQ                          1
#define CMD_EQ                          2        

#define LASTFIND_NOTFOUND               96
#define LASTFIND_PRIMARY                97

#define EVENT_CHAT                      0
#define EVENT_TIMER                     1
#define EVENT_CUSTOM                    2
#define EVENT_EVAL                      3
#define EVENT_EXEC                      4
#define EVENT_PULSE                     5
#define EVENT_SHUTDOWN                  6
#define EVENT_BREAK                     7
#define NUM_EVENTS                      8

#define CHAT_SAY                        1
#define CHAT_TELL                       2
#define CHAT_OOC                        4
#define CHAT_SHOUT                      8
#define CHAT_AUC                        16
#define CHAT_GUILD                      32
#define CHAT_GROUP                      64
#define CHAT_CHAT                       128
#define CHATEVENT(x)                    (gEventChat & x)

#define FILTERSKILL_ALL                 0
#define FILTERSKILL_INCREASE            1
#define FILTERSKILL_NONE                2

#define FILTERMACRO_ALL                 0
#define FILTERMACRO_ENHANCED            1
#define FILTERMACRO_NONE                2
#define FILTERMACRO_MACROENDED			3


#define MAX_STRING                      2048
#define MAX_VARNAME                     64

// Defines for CXWnd WindowStyle
#define CWS_VSCROLL                     0x1
#define CWS_HSCROLL                     0x2
#define CWS_TITLE                       0x4
#define CWS_CLOSE                       0x8
#define CWS_TILEBOX                     0x10
#define CWS_MINIMIZE                    0x20
#define CWS_BORDER                      0x40
//#define CWS_UNKNOWN                     0x80
//#define CWS_UNKNOWN                     0x100
#define CWS_RESIZEALL                   0x200
#define CWS_TRANSPARENT                 0x400
//#define CWS_UNKNOWN                     0x800
#define CWS_NOMOVE                      0x8000
#define CWS_QMARK                       0x10000
#define CWS_MAXIMIZE                    0x40000
#define ToggleBit(field,bit)            field^=bit;
#define BitOn(field,bit)                field|=bit;
#define BitOff(field,bit)               field&=~bit;
// End CXWnd WindowStyle Defines

#define ALTCURRENCY_DOUBLOONS           0xa
#define ALTCURRENCY_ORUX                0xb
#define ALTCURRENCY_PHOSPHENES          0xc
#define ALTCURRENCY_PHOSPHITES          0xd
#define ALTCURRENCY_FAYCITES            0xe
#define ALTCURRENCY_CHRONOBINES         0xf

enum MOUSE_DATA_TYPES {
   MD_Unknown = -1,
   MD_Button0Click=0,
   MD_Button1Click,
   MD_Button0,
   MD_Button1
};

#define nEQMappableCommands             0x13f

#define MAX_PC_LEVEL                    85
#define NUM_SPELL_GEMS                  12
#define NUM_SPELL_SETS                  10
#define NUM_BUFF_SLOTS					0x55
#define NUM_LONG_BUFFS                  30
#define NUM_SHORT_BUFFS                 20

// ***************************************************************************
// Structures
// ***************************************************************************

typedef struct _MOUSESPOOF {
   MOUSE_DATA_TYPES     mdType;
   DWORD                dwData;
   struct _MOUSESPOOF   *pNext;
} MOUSESPOOF, *PMOUSESPOOF;

typedef struct _MOUSECLICK {
   BYTE Confirm[8];         // DO NOT WRITE TO THIS BYTE
   BYTE Click[8];         // Left = 0, Right = 1, etc
} MOUSECLICK, *PMOUSECLICK;

typedef struct _UILOCATION {
   DWORD x;
   DWORD y;
   DWORD w;
   DWORD h;
   CHAR error[MAX_STRING];
} UILOCATION, *PUILOCATION;

//5-15-2003   eqmule
typedef struct _CXSTR {
/*0x00*/   DWORD   Font;            // maybe, dont know.  04 = Window 01 = button
/*0x04*/   DWORD   MaxLength;
/*0x08*/   DWORD   Length;
/*0x0c*/   BOOL    Encoding;        // 0: ASCII, 1:Unicode
/*0x10*/   PCRITICAL_SECTION pLock;
/*0x14*/   CHAR    Text[1];         // Stub, can be anywhere from Length to MaxLength (which is how much is malloc'd to this CXStr)
} CXSTR, *PCXSTR;

#define ITEM_NAME_LEN                   0x40
#define LORE_NAME_LEN                   0x70

// size is 0x64 02-16-2007
typedef struct _ITEMSPELLS { 
/*0x00*/ DWORD SpellID; 
/*0x04*/ BYTE  RequiredLevel; 
/*0x05*/ BYTE  EffectType; 
/*0x06*/ BYTE  Unknown[0x2]; 
/*0x08*/ DWORD Unknown0x08;
/*0x0c*/ DWORD MaxCharges;
/*0x10*/ DWORD CastTime;
/*0x14*/ DWORD TimerID;
/*0x18*/ DWORD RecastType;
/*0x1c*/ DWORD ProcRate;
/*0x20*/ BYTE  Unknown0x20[0x44];
/*0x64*/
} ITEMSPELLS, *PITEMSPELLS; 

// actual size: 0x574 5-12-2010 - ieatacid
typedef struct _ITEMINFO {
/*0x000*/ CHAR   Name[ITEM_NAME_LEN];
/*0x040*/ CHAR   LoreName[LORE_NAME_LEN];
/*0x0b0*/ CHAR   IDFile[0x20];
/*0x0d0*/ DWORD  ItemNumber;
/*0x0d4*/ DWORD  EquipSlots;
/*0x0d8*/ DWORD  Cost;
/*0x0dc*/ DWORD  IconNumber;
/*0x0e0*/ BYTE   Unknown0xe0[0x9];
/*0x0e9*/ BYTE   Weight;
/*0x0ea*/ BYTE   NoRent; // 0=temp, 1=default
/*0x0eb*/ BYTE   NoDrop; // 0=no drop, 1=can drop
/*0x0ec*/ BYTE   Attuneable;
/*0x0ed*/ BYTE   Unknown0xf0;
/*0x0ee*/ BYTE   Size;
/*0x0ef*/ BYTE   Type;
/*0x0f0*/ BYTE   TradeSkills;
/*0x0f1*/ BYTE   Padding0xf1[0x3];
/*0x0f4*/ BYTE   Lore;
/*0x0f5*/ BYTE   Unknown0xf5[0x3];
/*0x0f8*/ BYTE   Artifact;
/*0x0f9*/ BYTE   Summoned;
/*0x0fa*/ BYTE   SvCold;
/*0x0fb*/ BYTE   SvFire;
/*0x0fc*/ BYTE   SvMagic;
/*0x0fd*/ BYTE   SvDisease;
/*0x0fe*/ BYTE   SvPoison;
/*0x0ff*/ BYTE   SvCorruption;
/*0x100*/ BYTE   STR;
/*0x101*/ BYTE   STA;
/*0x102*/ BYTE   AGI;
/*0x103*/ BYTE   DEX;
/*0x104*/ BYTE   CHA;
/*0x105*/ BYTE   INT;
/*0x106*/ BYTE   WIS;
/*0x107*/ BYTE   Unknown0x107;
/*0x108*/ DWORD  HP;
/*0x10c*/ DWORD  Mana;
/*0x110*/ DWORD  AC;
/*0x114*/ DWORD  RequiredLevel;
/*0x118*/ DWORD  RecommendedLevel;
/*0x11c*/ BYTE   RecommendedSkill;
/*0x11d*/ BYTE   Unknown0x11d[0x3];
/*0x120*/ BYTE   SkillModType;
/*0x121*/ BYTE   Unknown0x121[0x3];
/*0x124*/ DWORD  Unknown0x124;
/*0x128*/ DWORD  SkillModValue;
/*0x12c*/ DWORD  BaneDMGRace;
/*0x130*/ DWORD  BaneDMGBodyType;
/*0x134*/ BYTE   BaneDMGBodyTypeValue;
/*0x135*/ BYTE   BaneDMGRaceValue;
/*0x136*/ BYTE   Unknown0x136[0x6];
/*0x13c*/ DWORD  InstrumentType;
/*0x140*/ DWORD  InstrumentMod;
/*0x144*/ DWORD  Classes;
/*0x148*/ DWORD  Races;
/*0x14c*/ DWORD  Diety;
/*0x150*/ BYTE   Unknown0x150[0x4];
/*0x154*/ BYTE   Magic;
/*0x155*/ BYTE   Light;
/*0x156*/ BYTE   Delay;
/*0x157*/ BYTE   DmgBonusType;
/*0x158*/ BYTE   DmgBonusVal;
/*0x159*/ BYTE   Range;
/*0x15a*/ BYTE   Unknown0x15a[0x2];
/*0x15c*/ DWORD  Damage;
/*0x160*/ DWORD  BackstabDamage;
/*0x164*/ DWORD  DamageShieldMitigation;
/*0x168*/ DWORD  HeroicSTR;
/*0x16c*/ DWORD  HeroicINT;
/*0x170*/ DWORD  HeroicWIS;
/*0x174*/ DWORD  HeroicAGI;
/*0x178*/ DWORD  HeroicDEX;
/*0x17c*/ DWORD  HeroicSTA;
/*0x180*/ DWORD  HeroicCHA;
/*0x184*/ DWORD  HeroicSvMagic;
/*0x188*/ DWORD  HeroicSvFire;
/*0x18c*/ DWORD  HeroicSvCold;
/*0x190*/ DWORD  HeroicSvDisease;
/*0x194*/ DWORD  HeroicSvPoison;
/*0x198*/ DWORD  HeroicSvCorruption;
/*0x19c*/ DWORD  HealAmount;
/*0x1a0*/ DWORD  SpellDamage;
/*0x1a4*/ BYTE   ItemType;
/*0x1a5*/ BYTE   Unknown0x1a5[0x3];
/*0x1a8*/ BYTE   Material;
/*0x1a9*/ BYTE   Unknown0x1a9[0xb];
/*0x1b4*/ DWORD  AugSlot1;
/*0x1b8*/ DWORD  AugSlot1_Unknown;
/*0x1bc*/ DWORD  AugSlot2;
/*0x1c0*/ DWORD  AugSlot2_Unknown;
/*0x1c4*/ DWORD  AugSlot3;
/*0x1c8*/ DWORD  AugSlot3_Unknown;
/*0x1cc*/ DWORD  AugSlot4;
/*0x1d0*/ DWORD  AugSlot4_Unknown;
/*0x1d4*/ DWORD  AugSlot5;
/*0x1d8*/ DWORD  AugSlot5_Unknown;
/*0x1dc*/ DWORD  AugType;
/*0x1e0*/ DWORD  AugRestrictions;
/*0x1e4*/ DWORD  SolventNeeded; //ID# of Solvent (Augs only)
/*0x1e8*/ DWORD  LDTheme;
/*0x1ec*/ DWORD  LDCost;
/*0x1f0*/ DWORD  LDType;
/*0x1f4*/ DWORD  Unknown0x1f4;
/*0x1f8*/ BYTE   Unknown0x1f8[0x4];
/*0x1fc*/ DWORD  FactionModType[0x4];
/*0x20c*/ DWORD  FactionModValue[0x4];
/*0x21c*/ BYTE   CharmFile[0x20];
/*0x23c*/ BYTE   Unknown0x23c[0x4];
/*0x240*/ struct _ITEMSPELLS Clicky;
/*0x2a4*/ struct _ITEMSPELLS Proc;
/*0x308*/ struct _ITEMSPELLS Worn;
/*0x36c*/ struct _ITEMSPELLS Focus;
/*0x3d0*/ struct _ITEMSPELLS Scroll;
/*0x434*/ BYTE   Unknown0x434[0x78];
/*0x4ac*/ DWORD  CombatEffects;
/*0x4b0*/ DWORD  Shielding;
/*0x4b4*/ DWORD  StunResist;
/*0x4b8*/ DWORD  DoTShielding;
/*0x4bc*/ DWORD  StrikeThrough;
/*0x4c0*/ DWORD  DmgBonusSkill; // SkillMinDamageMod;
/*0x4c4*/ DWORD  DmgBonusValue; // MinDamageMod;
/*0x4c8*/ DWORD  SpellShield;
/*0x4cc*/ DWORD  Avoidance;
/*0x4d0*/ DWORD  Accuracy;
/*0x4d4*/ DWORD  CharmFileID;
/*0x4d8*/ DWORD  CastTime;
/*0x4dc*/ BYTE   Combine;
/*0x4dd*/ BYTE   Slots;
/*0x4de*/ BYTE   SizeCapacity;
/*0x4df*/ BYTE   WeightReduction;
/*0x4e0*/ BYTE   BookType;      // 0=note, !0=book
/*0x4e1*/ BYTE   BookLang;
/*0x4e2*/ CHAR   BookFile[0x1e];
/*0x500*/ DWORD  Favor;         // Tribute Value
/*0x504*/ DWORD  GuildFavor;
/*0x508*/ DWORD  Unknown0x508;
/*0x50c*/ DWORD  Endurance;
/*0x510*/ DWORD  Attack;
/*0x514*/ DWORD  HPRegen;
/*0x518*/ DWORD  ManaRegen;
/*0x51c*/ DWORD  EnduranceRegen;
/*0x520*/ DWORD  Haste;
/*0x524*/ DWORD  DamShield;
/*0x528*/ BYTE   Unknown0x528[0x8];
/*0x530*/ BYTE   NoPet;
/*0x531*/ BYTE   Unknown0x531[0xb];
/*0x53c*/ DWORD  StackSize;
/*0x540*/ BYTE   Unknown0x540[0x4];
/*0x544*/ DWORD  MaxPower;
/*0x548*/ DWORD  Purity;
/*0x54c*/ BYTE   Unknown0x54c[0x4];
/*0x550*/ DWORD  Unknown0x550;
/*0x554*/ BYTE   QuestItem;
/*0x555*/ BYTE   Unknown0x555[0x3];
/*0x558*/ DWORD  Clairvoyance;
/*0x55c*/ BYTE   Unknown0x55c[0x18];
/*0x574*/ 
} ITEMINFO, *PITEMINFO;

// actual size 0xd8 01-16-2008
typedef struct _CONTENTS {
/*0x00*/  void    *vtable;
/*0x04*/  void    *punknown;
/*0x08*/  DWORD   EvolvingMaxLevel;
/*0x0c*/  struct  _CONTENTS *Contents[0x0a]; //addresses to whats inside the bag if its a bag; augs if an item
/*0x34*/  BYTE    Unknown0x34[0x8];
/*0x3c*/  DWORD   ItemSlot;
/*0x40*/  BYTE    Unknown0x40[0x4];
/*0x44*/  DWORD   EvolvingCurrentLevel;
/*0x48*/  BYTE    Unknown0x48[0x4];
/*0x4c*/  BYTE    EvolvingExpOn;
/*0x4d*/  BYTE    Unknown0x4d[0x3];
/*0x50*/  DWORD   Price;             // merchant price
/*0x54*/  DWORD   MerchantQuantity;  // amount that a merchant has for sale, -1 for unlimited
/*0x58*/  BYTE    Unknown0x58[0x28];
/*0x80*/  DWORD   MerchantSlot;      // slot id on a merchant 
/*0x84*/  BYTE    Unknown0x84[0x4];
/*0x88*/  DWORD   Open;
/*0x8c*/  BYTE    Unknown0x8c[0x4];
/*0x90*/  DWORD   Charges;           // charges if positive; some things are neg
/*0x94*/  BYTE    Unknown0x94[0x4];
/*0x98*/  DOUBLE  EvolvingExpPct;
/*0xa0*/  BYTE    Unknown0xa0[0x4];
/*0xa4*/  DWORD   Power;
/*0xa8*/  BYTE    Unknown0xa8[0x8];
/*0xb0*/  DWORD   EvolvingLoreGroup; // lore group if it's an evolving item
/*0xb4*/  BYTE    Unknown0xb4[0x4];
/*0xb8*/  struct  _ITEMINFO *Item;
/*0xbc*/  BYTE    Unknown0xbc[0x12];
/*0xce*/  BYTE    IsEvolvingItem;
/*0xcf*/  BYTE    Unknown0xcf;
/*0xd0*/  DWORD   StackCount;
/*0xd4*/  BYTE    Unknown0xd4[0x4];
/*0xd8*/
} CONTENTS, *PCONTENTS;

// Size 0x4c 5-12-2010 - ieatacid
typedef struct _SPELLBUFF {
/*0x00*/    BYTE      Unknown0x00;
/*0x01*/    BYTE      Level;
/*0x02*/    CHAR      Modifier;      // bard song modifier, divide by 10 to get 2.8 etc
/*0x03*/    CHAR      DamageShield;  // maybe.. I've noticed this is -1 on a lot of ds's.
/*0x04*/    FLOAT     Unknown0x4;
/*0x08*/    LONG      SpellID;       // -1 or 0 for no spell..
/*0x0c*/    DWORD     Duration;
/*0x10*/    BYTE      Unknown0x10[0x8];
/*0x18*/    DWORD     DamageAbsorbRemaining;
/*0x1c*/    BYTE      Unknown0x1c[0x4];
/*0x20*/    DWORD     DamageAbsorbRemaining2;
/*0x24*/    DWORD     Counters;
/*0x28*/    DWORD     DamageAbsorbRemaining3;
/*0x2c*/    BYTE      Unknown0x2c[0x20];
/*0x4c*/
} SPELLBUFF, *PSPELLBUFF;

// 12-23-2003   TheColonel
typedef struct _INVENTORY { 
/*0x00*/  struct    _CONTENTS* Charm; 
/*0x04*/  struct    _CONTENTS* LeftEar; 
/*0x08*/  struct    _CONTENTS* Head; 
/*0x0c*/  struct    _CONTENTS* Face; 
/*0x10*/  struct    _CONTENTS* RightEar; 
/*0x14*/  struct    _CONTENTS* Neck; 
/*0x18*/  struct    _CONTENTS* Shoulders; 
/*0x1c*/  struct    _CONTENTS* Arms; 
/*0x20*/  struct    _CONTENTS* Back; 
/*0x24*/  struct    _CONTENTS* LeftWrist; 
/*0x28*/  struct    _CONTENTS* RightWrist; 
/*0x2c*/  struct    _CONTENTS* Range; 
/*0x30*/  struct    _CONTENTS* Hands; 
/*0x34*/  struct    _CONTENTS* Primary; 
/*0x38*/  struct    _CONTENTS* Secondary; 
/*0x3c*/  struct    _CONTENTS* LeftFinger; 
/*0x40*/  struct    _CONTENTS* RightFinger; 
/*0x44*/  struct    _CONTENTS* Chest; 
/*0x48*/  struct    _CONTENTS* Legs; 
/*0x4c*/  struct    _CONTENTS* Feet; 
/*0x50*/  struct    _CONTENTS* Waist; 
/*0x54*/  struct    _CONTENTS* PowerSource; 
/*0x58*/  struct    _CONTENTS* Ammo; 
/*0x5c*/  struct    _CONTENTS* Pack[0x8]; 
} INVENTORY, *PINVENTORY; 

#define NUM_ALT_ABILITIES_ARRAY         0x1F7                        
#define NUM_ALT_ABILITIES               0xC34F

//these two will merge when i get a chance
#define AA_CHAR_MAX                     0xF5
#define AA_CHAR_MAX_REAL                0x12C

typedef struct _AALIST { 
/*0x0*/   DWORD        AAIndex;
/*0x4*/   DWORD        PointsSpent;
/*0x8*/   DWORD        ChargeSpent;        // charges spent in the last 10 min?
} AALIST, *PAALIST;

#define      NUM_INV_SLOTS              0x1f
#define      NUM_BANK_SLOTS             0x1a
#define      NUM_BOOK_SLOTS             0x2d0
#define      NUM_COMBAT_ABILITIES       0xc8
#define      BAG_SLOT_START             23
#define ExactLocation                   0

typedef struct _LEADERABILITIES {
/*0x00*/ DWORD MarkNPC;
/*0x04*/ DWORD NPCHealth;
/*0x08*/ DWORD Unknown0x8;
/*0x0c*/ DWORD DelegateMA;
/*0x10*/ DWORD DelegateMarkNPC;
/*0x14*/ DWORD Unknown0x14;
/*0x18*/ DWORD InspectBuffs;
/*0x1c*/ DWORD Unknown0x1c;
/*0x20*/ DWORD SpellAwareness;
/*0x24*/ DWORD OffenseEnhancement;
/*0x28*/ DWORD ManaEnhancement;
/*0x2c*/ DWORD HealthEnhancement;
/*0x30*/ DWORD HealthRegen;
/*0x34*/ DWORD FindPathPC;
/*0x38*/ DWORD HoTT;
/*0x3c*/ DWORD Unknown0x3c;
/*0x40*/
} LEADERABILITIES, *PLEADERABILITIES;

typedef struct _EQC_INFO {
/* 0x0000 */    DWORD   minus4;
/* 0x0004 */    DWORD   stuff_offset;
} EQC_INFO, *PEQC_INFO;

typedef struct _CI_INFO {
/* 0x0000 */    DWORD   minus8;
/* 0x0004 */    DWORD   stuff_offset;
/* 0x0008 */    DWORD   Unknown0x8;    // 2000
/* 0x000c */    DWORD   Unknown0xc;    // 2500
/* 0x0010 */    DWORD   Unknown0x10;   // 3000
/* 0x0014 */    DWORD   Unknown0x14;   // 4000
/* 0x0018 */    DWORD   Unknown0x18;   // 10000
} CI_INFO, *PCI_INFO;

typedef struct _CI2_INFO {
/* 0x0000 */    DWORD   Unknown0x0;
/* 0x0004 */    struct  _CHARINFO2* pCharInfo2;
/* 0x0008 */    struct  _CHARINFO2* pCharInfo3;
/* 0x000c */    BYTE    Unknown0xc[0x14];
/* 0x0010 */    void    *Unknown0x10[0x10];
/* 0x0060 */
} CI2_INFO, *PCI2_INFO;

typedef struct _GROUPMEMBER {
/*0x00*/ void   *vftable;
/*0x04*/ struct _CXSTR *pName;
/*0x08*/ BYTE   Mercenary;
/*0x09*/ BYTE   Unknown0x8[0x3];
/*0x0c*/ struct _CXSTR *pOwner; // name of mercenary's owner
/*0x10*/ DWORD  Level;
/*0x14*/ BYTE   Unknown0x14[0x2];
/*0x16*/ BYTE   MainTank;
/*0x17*/ BYTE   MainAssist;
/*0x18*/ BYTE   Puller;
/*0x19*/ BYTE   Unknown0x19[0x3];
/*0x1c*/ DWORD  Roles;          // (Roles & 1) = MainTank, 2 = MainAssist, 4 = Puller
/*0x20*/ BYTE   Unknown0x20[0x8];
/*0x28*/ struct _SPAWNINFO *pSpawn;
/*0x2c*/
} GROUPMEMBER, *PGROUPMEMBER;

typedef struct _GROUPINFO {
/*0x00*/ void   *vftable;
/*0x04*/ struct _GROUPMEMBER *pMember[0x6];
/*0x1c*/ struct _GROUPMEMBER *pLeader;
/*0x20*/
} GROUPINFO, *PGROUPINFO;

// actual size: 0x4994 6-9-10 - ieatacid
typedef struct _CHARINFO {
/*0x0000*/   void       *vtable1;
/*0x0004*/   void       *punknown;
/*0x0008*/   struct     _CI_INFO* charinfo_info;
/*0x000c*/   BYTE       Unknown0xc[0x101c];
/*0x1028*/   struct     _LEADERABILITIES MyAbilities; //points spent in each ability (size 0x40)
/*0x1068*/   BYTE       Unknown0x1068[0xc0];
/*0x1128*/   struct     _CONTENTS*   Bank[NUM_BANK_SLOTS];
/*0x1190*/   BYTE       unknown0x1190[0xdc];
/*0x126c*/   DWORD      GuildID;
/*0x1270*/   BYTE       Unknown0x1270[0x8];
/*0x1278*/   DWORD      GuildRank; // 0=Member, 1=Officer, 2=Leader
/*0x127c*/   BYTE       Unknown0x127c[0x18];
/*0x1294*/   DWORD      AAExp;
/*0x1298*/   BYTE       Unknown0x1298; 
/*0x1299*/   BYTE       PercentEXPtoAA;
/*0x129a*/   BYTE       Unknown0x129a[0x42];
/*0x12dc*/   DWORD      TributeTimer;
/*0x12e0*/   DWORD      CareerFavor;
/*0x12e4*/   DWORD      Unknown0x12e4;
/*0x12e8*/   DWORD      CurrFavor;
/*0x12ec*/   BYTE       Unknown0x12ec[0xc];
/*0x12f8*/   DOUBLE     GroupLeadershipExp;
/*0x1300*/   DOUBLE     RaidLeadershipExp;
/*0x1308*/   DWORD      GroupLeadershipPoints;
/*0x130c*/   DWORD      RaidLeadershipPoints;
/*0x1310*/   BYTE       Unknown0x1310[0x194];
/*0x14a4*/   DWORD      RadiantCrystals;
/*0x14a8*/   DWORD      Unknown0x14a8;
/*0x14ac*/   DWORD      EbonCrystals; 
/*0x14b0*/   BYTE       Unknown0x14b0[0x630];
/*0x1ae0*/   DWORD      Exp;
/*0x1ae4*/   BYTE       Unknown0x1ae4[0x64];
/*0x1b48*/   void       *OtherCharData;
/*0x1b4c*/   BYTE       Unknown0x1b4c[0x62c];
/*0x2178*/   void       *vtable2;
/*0x217c*/   struct     _EQC_INFO* eqc_info;
/*0x2180*/   struct     _SPAWNINFO* pSpawn;
/*0x2184*/   DWORD      Unknown0x2184;
/*0x2188*/   DWORD      Unknown0x2188;
/*0x218c*/   DWORD      CurrWeight;
/*0x2190*/   BYTE       Unknown0x2190[0xc];
/*0x219c*/   DWORD      HPBonus;
/*0x21a0*/   DWORD      ManaBonus;
/*0x21a4*/   DWORD      EnduranceBonus;
/*0x21a8*/   DWORD      CombatEffectsCap;
/*0x21ac*/   DWORD      ShieldingCap;
/*0x21b0*/   DWORD      SpellShieldCap;
/*0x21b4*/   DWORD      AvoidanceCap;
/*0x21b8*/   DWORD      AccuracyCap;
/*0x21bc*/   DWORD      StunResistCap;
/*0x21c0*/   DWORD      StrikeThroughCap;
/*0x21c4*/   DWORD      Unknown0x21c4[0x9];
/*0x21e8*/   DWORD      SkillMinDamageModBonus[0x9];
/*0x220c*/   BYTE       Unknown0x220c[0x4];
/*0x2210*/   DWORD      DoTShieldCap;
/*0x2214*/   DWORD      DamageShieldMitigationCap;
/*0x2218*/   DWORD      CombatEffectsBonus;
/*0x221c*/   DWORD      SpellShieldBonus;
/*0x2220*/   DWORD      ShieldingBonus;
/*0x2224*/   DWORD      DamageShieldBonus;
/*0x2228*/   DWORD      DoTShieldBonus;
/*0x222c*/   DWORD      DamageShieldMitigationBonus;
/*0x2230*/   DWORD      AvoidanceBonus;
/*0x2234*/   DWORD      AccuracyBonus;
/*0x2238*/   DWORD      StunResistBonus;
/*0x223c*/   DWORD      StrikeThroughBonus;
/*0x2240*/   DWORD      HeroicSTRBonus;
/*0x2244*/   DWORD      HeroicINTBonus;
/*0x2248*/   DWORD      HeroicWISBonus;
/*0x224c*/   DWORD      HeroicAGIBonus;
/*0x2250*/   DWORD      HeroicDEXBonus;
/*0x2254*/   DWORD      HeroicSTABonus;
/*0x2258*/   DWORD      HeroicCHABonus;
/*0x225c*/   DWORD      HeroicSvMagicBonus;
/*0x2260*/   DWORD      HeroicSvFireBonus;
/*0x2264*/   DWORD      HeroicSvColdBonus;
/*0x2268*/   DWORD      HeroicSvDiseaseBonus;
/*0x226c*/   DWORD      HeroicSvPoisonBonus;
/*0x2270*/   DWORD      HeroicSvCorruptionBonus;
/*0x2274*/   DWORD      HealAmountBonus;
/*0x2278*/   DWORD      SpellDamageBonus;
/*0x227c*/   DWORD      Unknown0x227c[0x2];
/*0x2284*/   DWORD      ClairvoyanceBonus;
/*0x2288*/   DWORD      AttackBonus;
/*0x228c*/   DWORD      HPRegenBonus;
/*0x2290*/   DWORD      ManaRegenBonus;
/*0x2294*/   DWORD      EnduranceRegenBonus;
/*0x2298*/   DWORD      DamageShieldCap;
/*0x229c*/   DWORD      AttackSpeed;
/*0x22a0*/   BYTE       Unknown0x22a0[0xa8];
/*0x2348*/   struct     _XTARGETMGR *pXTargetMgr;
/*0x234c*/   DWORD      InCombat;
/*0x2350*/   DWORD      Downtime;
/*0x2354*/   DWORD      DowntimeStamp;
/*0x2358*/   BYTE       Unknown0x2358[0x4];
/*0x235c*/   struct     _GROUPINFO *pGroupInfo;
/*0x2360*/   BYTE       Unknown0x2360[0x1c];
/*0x237c*/   void       *pUnknown2;
/*0x2380*/   struct     _CI2_INFO* pCI2;
/*0x2384*/   DWORD      Unknown0x2384;
/*0x2388*/   BYTE       languages[0x20];
/*0x23a8*/   BYTE       Unknown0x23a8[0x10];
/*0x23b8*/   CHAR       Name[0x40];
/*0x23f8*/   CHAR       Lastname[0x20];
/*0x2418*/   BYTE       Unknown0x2418[0x60];
/*0x2478*/   BYTE       Stunned;
/*0x2479*/   BYTE       Unknown0x2479[0x3];
/*0x247c*/   WORD       zoneId;
/*0x247e*/   WORD       instance;
/*0x2480*/   DWORD      standstate;
/*0x2484*/   BYTE       Unknown0x2484[0x4];
/*0x2488*/   struct     _LEADERABILITIES ActiveAbilities; //ability levels of the leader of your group (size 0x40)
/*0x24c8*/   BYTE       Unknown0x24c8[0x334];
/*0x27fc*/   DWORD      BankSharedPlat;
/*0x2800*/   DWORD      BankSharedGold;
/*0x2804*/   DWORD      BankSharedSilver;
/*0x2808*/   DWORD      BankSharedCopper;
/*0x280c*/   DWORD      BankPlat;
/*0x2810*/   DWORD      BankGold;
/*0x2814*/   DWORD      BankSilver;
/*0x2818*/   DWORD      BankCopper;
/*0x281c*/   DWORD      STR;
/*0x2820*/   DWORD      STA;
/*0x2824*/   DWORD      CHA;
/*0x2828*/   DWORD      DEX;
/*0x282c*/   DWORD      INT;
/*0x2830*/   DWORD      AGI;
/*0x2834*/   DWORD      WIS;
/*0x2838*/   DWORD      SavePoison;
/*0x283c*/   DWORD      SaveMagic;
/*0x2840*/   DWORD      SaveDisease;
/*0x2844*/   DWORD      SaveCorruption;
/*0x2848*/   DWORD      SaveFire;
/*0x284c*/   DWORD      SaveCold;
/*0x2850*/   BYTE       Unknown0x2850[0x2144];
/*0x4994*/
} CHARINFO, *PCHARINFO;

// actual size: 0x9c1c 5-13-2010 - ieatacid
typedef struct _CHARINFO2 {
/*0x0000*/   BYTE       Unknown0x0[0x10];
union {
/*0x0010*/   struct     _INVENTORY   Inventory;
/*0x0010*/   struct     _CONTENTS*   InventoryArray[NUM_INV_SLOTS];
};
/*0x008c*/   struct     _CONTENTS*   Cursor;
/*0x0090*/   BYTE       Unknown0x90[0x14];
/*0x00a4*/   struct     _SPELLBUFF   Buff[NUM_LONG_BUFFS];
/*0x098c*/   struct     _SPELLBUFF   ShortBuff[0x37];
/*0x19e0*/   DWORD      Unknown0x19e0[NUM_BUFF_SLOTS]; // effect IDs
/*0x1b34*/   DWORD      Unknown0x1b34[NUM_BUFF_SLOTS];
/*0x1c88*/   DWORD      SpellBook[NUM_BOOK_SLOTS];
/*0x27c8*/   DWORD      MemorizedSpells[0x10];
/*0x2808*/   DWORD      Skill[0x64];
/*0x2998*/   DWORD      InnateSkill[0x19];
/*0x29fc*/   DWORD      Unknown0x29fc[0x24];
/*0x2a8c*/   DWORD      Gender;
/*0x2a90*/   DWORD      Race;
/*0x2a94*/   DWORD      Class;
/*0x2a98*/   BYTE       Unknown0x2a98[0x10];
/*0x2aa8*/   DWORD      Level;
/*0x2aac*/   DWORD      Mana;
/*0x2ab0*/   DWORD      Endurance;
/*0x2ab4*/   DWORD      BaseHP;
/*0x2ab8*/   DWORD      BaseSTR;
/*0x2abc*/   DWORD      BaseSTA;
/*0x2ac0*/   DWORD      BaseCHA;
/*0x2ac4*/   DWORD      BaseDEX;
/*0x2ac8*/   DWORD      BaseINT;
/*0x2acc*/   DWORD      BaseAGI;
/*0x2ad0*/   DWORD      BaseWIS;
/*0x2ad4*/   DWORD      Unknown0x1ae4;
/*0x2ad8*/   DWORD      Plat;
/*0x2adc*/   DWORD      Gold;
/*0x2ae0*/   DWORD      Silver;
/*0x2ae4*/   DWORD      Copper;
/*0x2ae8*/   DWORD      CursorPlat;
/*0x2aec*/   DWORD      CursorGold;
/*0x2af0*/   DWORD      CursorSilver;
/*0x2af4*/   DWORD      CursorCopper;
/*0x2af8*/   BYTE       Unknown0x2af8[0x28];
/*0x2b20*/   DWORD      thirstlevel;
/*0x2b24*/   DWORD      hungerlevel;
/*0x2b28*/   DWORD      Unknown0x2b28; 
/*0x2b2c*/   DWORD      Shrouded;
/*0x2b30*/   BYTE       Unknown0x2b30[0x74];
/*0x2ba4*/   DWORD      ZoneBoundID;
/*0x2ba8*/   FLOAT      ZoneBoundY;
/*0x2bac*/   FLOAT      ZoneBoundX;
/*0x2bb0*/   FLOAT      ZoneBoundZ;
/*0x2bb4*/   FLOAT      ZoneBoundHeading;
/*0x2bb8*/   BYTE       Unknown0x2bb8[0x50];
/*0x2c08*/   DWORD      ArmorType[0x16];
/*0x2c60*/   BYTE       Unknown0x2c60[0xb0];
/*0x2d10*/   AALIST     AAList[AA_CHAR_MAX_REAL];
/*0x3b20*/   DWORD      BodyColor[0x9];
/*0x3b44*/   BYTE       Unknown0x3b44[0x2000];
/*0x5b44*/   DWORD      CombatAbilities[NUM_COMBAT_ABILITIES];
/*0x5e64*/   BYTE       Unknown0x5e64[0x34];
/*0x5e98*/   DWORD      CombatAbilityTimes[0x14];
/*0x5ee8*/   BYTE       Unknown0x5ee8[0x1ccc];
/*0x7bb4*/   DWORD      Deity;
/*0x7bb8*/   BYTE       Unknown0x7bb8[0x4];
/*0x7bbc*/   DWORD      Drunkenness;
/*0x7bc0*/   BYTE       Unknown0x7bc0[0x10];
/*0x7bd0*/   DWORD      AAPoints;
/*0x7bd4*/   BYTE       Unknown0x7bd4[0x200c];
/*0x9be0*/   DWORD      AAPointsSpent;
/*0x9be4*/   BYTE       Unknown0x9be4[0x38];
/*0x9c1c*/
} CHARINFO2, *PCHARINFO2;

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


#define MODEL_LABEL                     0 
#define MODEL_LABELINFO                 1
#define MODEL_NULL2                     2
#define MODEL_HELD_R                    3
#define MODEL_HELD_L                    4
#define MODEL_SHIELD                    5
#define MODEL_NULL6                     6

/*
//Work in progress...
#define MODEL_HEAD                      0x00
#define MODEL_HEAD_POINT                0x01
#define MODEL_NULL_1                    0x02
#define MODEL_HELD_R                    0x03
#define MODEL_HELD_L                    0x04
#define MODEL_SHIELD                    0x05
#define MODEL_NULL_2                    0x06
#define MODEL_TUNIC                     0x07
#define MODEL_HAIR                      0x08
#define MODEL_BEARD                     0x09
#define MODEL_CHEST                     0x0a
#define MODEL_GLOVES                    0x0b
#define MODEL_GLOVES2                   0b0c
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

typedef struct _ARMOR {
/*0x00*/ DWORD  ID; //idfile on Lucy
/*0x04*/ DWORD  Unknown0x04;
/*0x08*/ DWORD  Unknown0x08;
/*0x0c*/
} ARMOR, *PARMOR;

// 10-22-2003 Lax
typedef struct _EQUIPMENT {
   union {
      struct// EQUIPARRAY
      {
         struct _ARMOR Item[9];
      };// Array;
      struct //EQUIPUNIQUE
      {
         struct _ARMOR Head;
         struct _ARMOR Chest;
         struct _ARMOR Arms;
         struct _ARMOR Wrists;
         struct _ARMOR Hands;
         struct _ARMOR Legs;
         struct _ARMOR Feet;
         struct _ARMOR Primary;
         struct _ARMOR Offhand;
      };// Unique;
   };
} EQUIPMENT, *PEQUIPMENT;

// 10-14-07 - ieatacid
typedef struct _FELLOWSHIPMEMBER {
/*0x00*/  DWORD   Unknown0x0;
/*0x04*/  CHAR    Name[0x40];
/*0x44*/  WORD    ZoneID;
/*0x46*/  WORD    InstanceID;
/*0x48*/  DWORD   Level;
/*0x4c*/  DWORD   Class;
/*0x50*/  DWORD   LastOn;    // FastTime() timestamp
/*0x54*/
} FELLOWSHIPMEMBER, *PFELLOWSHIPMEMBER;

// 3-2-2008 - ieatacid
typedef struct _FELLOWSHIPINFO {
/*0x000*/  DWORD  Unknown0x0;        // always 1?
/*0x004*/  DWORD  FellowshipID;
/*0x008*/  CHAR   Leader[0x40];
/*0x048*/  CHAR   MotD[0x400];
/*0x448*/  DWORD  Members;
/*0x44c*/  struct _FELLOWSHIPMEMBER  FellowshipMember[0x9];
/*0x740*/  DWORD  Unknown0x740;      // timestamp for something
/*0x744*/  BYTE   Unknown0x744[0x120];
/*0x864*/  FLOAT  CampfireY;
/*0x868*/  FLOAT  CampfireX;
/*0x86c*/  FLOAT  CampfireZ;
/*0x870*/  WORD   CampfireZoneID;    // zone ID where campfire is
/*0x872*/  WORD   InstanceID;
/*0x874*/  DWORD  CampfireTimestamp; // CampfireTimestamp-FastTime()=time left on campfire
/*0x878*/  DWORD  Unknown0x878;      // same as FellowshipID
/*0x87c*/  DWORD  Unknown0x87c;      // campfire type?
/*0x880*/  DWORD  Campfire;          // do we have a campfire up?
/*0x884*/
} FELLOWSHIPINFO, *PFELLOWSHIPINFO;

typedef struct _ITEMLOCATION {
/*0x00*/ DWORD    a;
/*0x04*/ DWORD    InvSlot;
/*0x08*/ DWORD    BagSlot;
/*0x0c*/ DWORD    d;
/*0x10*/ DWORD    e;
/*0x14*/
} ITEMLOCATION, *PITEMLOCATION;

typedef struct _LAUNCHSPELLDATA {
/*0x00*/ DWORD    SpellETA;           //Calculated TimeStamp when current spell being cast will land. 0 while not casting.
/*0x04*/ DWORD    SpellID;            // -1 = not casting a spell
/*0x08*/ BYTE     SpellSlot;          // 0xFF if not casting, otherwise it's the spell gem number (0 - 8)
/*0x09*/ BYTE     Padding0x9[0x3];
/*0x0c*/ struct   _ITEMLOCATION ItemLocation;
/*0x20*/ DWORD    Unknown0x20;        // spell type?
/*0x24*/ DWORD    ItemID;
/*0x28*/ FLOAT    CastingY;
/*0x2c*/ FLOAT    CastingX;
/*0x30*/ BYTE     Unknown0x30[0x1c];
/*0x4c*/
} LAUNCHSPELLDATA, *PLAUNCHSPELLDATA;

// actual size: 0x1c3c 11-11-09 - ieatacid
typedef struct _SPAWNINFO {
/*0x0000*/ void     *vtable;
/*0x0004*/ struct   _SPAWNINFO *pPrev;
/*0x0008*/ struct   _SPAWNINFO *pNext;
/*0x000c*/ BYTE     Unknown0xc[0xc];
/*0x0018*/ FLOAT    SpeedMultiplier;
/*0x001c*/ BYTE     Unknown0x1c[0x14];
/*0x0030*/ DWORD    TimeStamp;
/*0x0034*/ BYTE     Unknown0x034[0x4];
/*0x0038*/ CHAR     Lastname[0x20];
/*0x0058*/ BYTE     Unknown0x058[0xc];
/*0x0064*/ FLOAT    Y;
/*0x0068*/ FLOAT    X;
/*0x006c*/ FLOAT    Z;
/*0x0070*/ FLOAT    SpeedY;
/*0x0074*/ FLOAT    SpeedX;
/*0x0078*/ FLOAT    SpeedZ;
/*0x007c*/ FLOAT    SpeedRun;
/*0x0080*/ FLOAT    Heading;
/*0x0084*/ BYTE     Unknown0x84[0x8];
/*0x008c*/ FLOAT    SpeedHeading;
/*0x0090*/ FLOAT    CameraAngle;
/*0x0094*/ BYTE     UnderWater;
/*0x0095*/ BYTE     Unknown0x95[0xc];
/*0x00a1*/ BYTE     FeetWet;
/*0x00a2*/ BYTE     Unknown0xa2[0x2];
/*0x00a4*/ CHAR     Name[0x40];             // ie priest_of_discord00
/*0x00e4*/ CHAR     DisplayedName[0x40];    // ie Priest of Discord
/*0x0124*/ BYTE     Unknown0x124;
/*0x0125*/ BYTE     Type;
/*0x0126*/ BYTE     Unknown0x126[0x2];
/*0x0128*/ DWORD    **BodyType;
/*0x012c*/ BYTE     Unknown0x12c[0xc];
/*0x0138*/ FLOAT    AvatarHeight;           // height of avatar from ground when standing
/*0x013c*/ BYTE     Unknown0x13c[0x8];
/*0x0144*/ FLOAT    AvatarHeight2;          // height of avatar from ground when crouched/sitting
/*0x0148*/ DWORD    SpawnID;
/*0x014c*/ BYTE     Unknown0x14c[0x4];
/*0x0150*/ DWORD    IsABoat;                // 1 = a type of boat
/*0x0154*/ struct   _SPAWNINFO *Mount;      // NULL if no mount present
/*0x0158*/ struct   _SPAWNINFO *Rider;      // _SPAWNINFO of mount's rider
/*0x015c*/ BYTE     Unknown0x15c[0x24];
/*0x0180*/ CHAR     Suffix[0x20];
/*0x01a0*/ DWORD    AARank;
/*0x01a4*/ DWORD    PetID;
/*0x01a8*/ BYTE     Unknown0x1a8[0x28];
/*0x01d0*/ BYTE     Linkdead;
/*0x01d1*/ BYTE     Unknown0x1d1[0x3];
/*0x01d4*/ DWORD    EnduranceMax;
/*0x01d8*/ LONG     HPCurrent;
/*0x01dc*/ BYTE     Sneak;
/*0x01dd*/ BYTE     Light;
/*0x01de*/ BYTE     Unknown0x1de[0x20];
/*0x01fe*/ BYTE     LFG;
/*0x01ff*/ BYTE     Unknown0x1ff;
/*0x0200*/ BYTE     Unknown0x200[0x1c];
/*0x021c*/ DWORD    Buyer;
/*0x0220*/ DWORD    ManaMax;
/*0x0224*/ BYTE     Unknown0x228[0x14];
/*0x0238*/ DWORD    MasterID;
/*0x023c*/ BYTE     Unknown0x23c[0x4];
/*0x0240*/ DWORD    FishingETA;
/*0x0244*/ BYTE     Mercenary;
/*0x0245*/ BYTE     Unknown0x245[0x47];
/*0x028c*/ BYTE     Unknown0x28c;
/*0x028d*/ BYTE     StandState;
/*0x028e*/ BYTE     Unknown0x28e[0x2];
/*0x0290*/ BYTE     Unknown0x290[0x8];
/*0x0298*/ DWORD    AFK;
/*0x029c*/ BYTE     Unknown0x29c[0x4];
/*0x02a0*/ CHAR     Title[0x20];
/*0x02c0*/ DWORD    Anon;
/*0x02c4*/ BYTE     Unknown0x2c4[0x8];
/*0x02cc*/ DWORD    Trader;
/*0x02d0*/ BYTE     PvPFlag;
/*0x02d1*/ BYTE     Unknown0x2d1[0x3];
/*0x02d4*/ BYTE     Unknown0x2d4[0x8];
/*0x02dc*/ FLOAT    GetMeleeRangeVar1;      // used by GetMeleeRange
/*0x02e0*/ BYTE     Unknown0x2e0[0x8];
/*0x02e8*/ DWORD    LastTick;
/*0x02ec*/ BYTE     Unknown0x2ec[0x4];
/*0x02f0*/ WORD     Zone;
/*0x02f2*/ WORD     Instance;
/*0x02f4*/ BYTE     Unknown0x2f4[0x1c];
/*0x0310*/ FLOAT    RunSpeed;
/*0x0314*/ DWORD    ManaCurrent;
/*0x0318*/ BYTE     Unknown0x318[0x4];
/*0x031c*/ DWORD    GuildID;
/*0x0320*/ BYTE     Unknown0x320[0x4];
/*0x0324*/ BYTE     FishingEvent;
/*0x0325*/ BYTE     Level;
/*0x0326*/ BYTE     Unknown0x326[0x2];
/*0x0328*/ BYTE     Unknown0x328[0x8];
/*0x0330*/ DWORD    HPMax;
/*0x0334*/ BYTE     Unknown0x334[0x3c];
/*0x0370*/ DWORD    InnateETA;              //Calculated TimeStamp when innate skill will be ready (LoH, HT, Bash)
/*0x0374*/ BYTE     Unknown0x374[0x4];
/*0x0378*/ DWORD    RespawnTimer;           // TimeStamp of when RespawnWnd will close - 0 when you're alive
/*0x037c*/ BYTE     Unknown0x37c[0x28];
/*0x03a4*/ DWORD    GuildStatus;
/*0x03a8*/ BYTE     Unknown0x3a8[0xc];
/*0x03b4*/ BYTE     HideMode;
/*0x03b5*/ BYTE     Unknown0x3b5[0x3];
/*0x03b8*/ BYTE     Unknown0x3b8[0x30];
/*0x03e8*/ BYTE     Holding;
/*0x03e9*/ BYTE     Unknown0x3e9[0x3];
/*0x03ec*/ BYTE     Unknown0x3ec[0xc];
/*0x03f8*/ struct   _LAUNCHSPELLDATA CastingData; // size: 0x4c
/*0x0444*/ BYTE     Unknown0x444[0xa0];
/*0x04e4*/ DWORD    EnduranceCurrent;
/*0x04e8*/ DWORD    Deity;
/*0x04ec*/ BYTE     Unknown0x4ec[0x2];
/*0x04ee*/ BYTE     GM;
/*0x04ef*/ BYTE     Unknown0x4ef;
/*0x04f0*/ BYTE     Unknown0x4f0[0x918];
/*0x0e08*/ struct   _SPAWNINFO *WhoFollowing; // NULL if autofollow off
/*0x0e0c*/ int      GroupAssistNPC[1];
/*0x0e10*/ int      RaidAssistNPC[3];
/*0x0e1c*/ int      GroupMarkNPC[3];
/*0x0e28*/ int      RaidMarkNPC[3];
/*0x0e34*/ int      TargetOfTarget;
/*0x0e38*/ BYTE     Unknown0xe38[0x30];
/*0x0e68*/ void     *pActorClient;          // start of ActorClient struct
/*0x0e6c*/ BYTE     InNonPCRaceIllusion;
/*0x0e6d*/ BYTE     Unknown0xe6d[0x3];
/*0x0e70*/ BYTE     FaceStyle;
/*0x0e71*/ BYTE     HairColor;
/*0x0e72*/ BYTE     FacialHairColor;
/*0x0e73*/ BYTE     EyeColor1;
/*0x0e74*/ BYTE     EyeColor2;
/*0x0e75*/ BYTE     HairStyle;
/*0x0e76*/ BYTE     FacialHair;
/*0x0e77*/ BYTE     Unknown0xe77;
/*0x0e78*/ DWORD    Race;
/*0x0e7c*/ BYTE     Class;
/*0x0e7d*/ BYTE     Gender;
/*0x0e7e*/ CHAR     ActorDef[0x40];
/*0x0ebe*/ BYTE     Unknown0xebe[0x2];
/*0x0ec0*/ ARGBCOLOR ArmorColor[0x9];
/*0x0ee4*/ BYTE     Unknown0xee4[0x4];
/*0x0ee8*/ DWORD    Heritage;               //drakkin only face setting
/*0x0eec*/ DWORD    Tattoo;                 //drakkin only face setting
/*0x0ef0*/ DWORD    Details;                //drakkin only face setting
/*0x0ef4*/ struct   _EQUIPMENT Equipment;   // size 0x6c
/*0x0f60*/ BYTE     Unknown0xf60[0x38];
/*0x0f98*/ VOID     *pcactorex;             // ActorInterface*
/*0x0f9c*/ DWORD    Unknown0xf9c;
/*0x0fa0*/ VOID     *FaceRelatedActorStruct;
/*0x0fa4*/ BYTE     Unknown0xfa4[0x30];
/*0x0fd4*/ FLOAT    GetMeleeRangeVar2;      // used by GetMeleeRange
/*0x0fd8*/ BYTE     Unknown0xfd8[0x60];
/*0x1038*/ DWORD    Animation;
/*0x103c*/ BYTE     Unknown0x103c[0x104];
/*0x1140*/ FLOAT    WalkSpeed;
/*0x1144*/ DWORD    HideCorpse;
/*0x1148*/ BYTE     Unknown0x1148[0x40];
/*0x1188*/ BYTE     InvitedToGroup;
/*0x1189*/ BYTE     Unknown0x1189[0x3];
/*0x118c*/ DWORD    GroupMemberTargeted;    // 0xFFFFFFFF if no target, else 1 through 5
/*0x1190*/ BYTE     Unknown0x1190[0x180];
/*0x1310*/ struct   _FELLOWSHIPINFO Fellowship; // size 0x884
/*0x1b94*/ BYTE     Unknown0x1b94[0x54];
/*0x1be8*/ void     *vtable2;
/*0x1bec*/ DWORD    Unknown0x1bec;
/*0x1bf0*/ struct   _SPAWNINFO *pSpawn;
/*0x1bf4*/ BYTE     Levitate;
/*0x1bf5*/ BYTE     Unknown0x1bf5[0x47];
/*0x1c3c*/
} SPAWNINFO, *PSPAWNINFO;

#define STANDSTATE_STAND                0x64
#define STANDSTATE_CASTING              0x66
#define STANDSTATE_BIND                 0x69
#define STANDSTATE_SIT                  0x6E
#define STANDSTATE_DUCK                 0x6F
#define STANDSTATE_FEIGN                0x73
#define STANDSTATE_DEAD                 0x78

#define MONITOR_SPAWN_X                 1
#define MONITOR_SPAWN_Y                 2
#define MONITOR_SPAWN_Z                 4
#define MONITOR_SPAWN_HEADING           8
#define MONITOR_SPAWN_SPEEDRUN          16
#define MONITOR_SPAWN_HPCURRENT         32

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

typedef struct _HASHENTRY {
    SPAWNINFO   *spawn;
    DWORD       key;            // same as SpawnID for spawns
    struct      _HASHENTRY *next;
} HASHENTRY, *PHASHENTRY;

typedef struct _HASHTABLE {
    struct _HASHENTRY **table;
    int size;
} HASHTABLE, *PHASHTABLE;

typedef struct _SPAWNMANAGER {
/*0x000*/ void          *vftable;
/*0x004*/ DWORD         random; // rand()%20000
/*0x008*/ struct  _SPAWNINFO        *FirstSpawn;
/*0x00c*/ struct  _SPAWNINFO        *LastSpawn;
/*0x010*/ DWORD         unknown10;
/*0x014*/ struct        _HASHTABLE  *SPHash;
} SPAWNMANAGER, *PSPAWNMANAGER;


#if 0

void *gethashedentry(struct _HASHTABLE  *table, DWORD key)
{
    PHASHENTRY p = NULL;
    p = table->array[key%table->size];

    while(p) {
        if (p->key == key) return p;
        p = p->next;
    }
    return NULL;
}

#endif

// this is actually ActorInterface
// actual size: 0x120 3-3-2009
typedef struct _EQSWITCH {
/*0x00*/    DWORD        Unknown0x0[0x2];
/*0x08*/    float        UnknownData0x08;
/*0x0c*/    float        UnknownData0x0c;
/*0x10*/    float        Unknown0x10[0x2];
/*0x18*/    float        UnknownData0x18;
/*0x1c*/    float        Unknown0x1c;
/*0x20*/    float        UnknownData0x20;
/*0x24*/    float        Unknown0x24;
/*0x28*/    FLOAT        Y;
/*0x2c*/    FLOAT        X;
/*0x30*/    FLOAT        Z;
/*0x34*/    BYTE         Unknown0x34[0x50]; //A lot of data here.
/*0x84*/    float        yAdjustment1;
/*0x88*/    float        xAdjustment1;
/*0x8c*/    float        zAdjustment1;
/*0x90*/    float        headingAdjustment1;
/*0x94*/    float        yAdjustment2;
/*0x98*/    float        xAdjustment2;
/*0x9c*/    float        zAdjustment2;
/*0xa0*/    float        headingAdjustment2;
/*0xa4*/    float        yAdjustment3;
/*0xa8*/    float        xAdjustment3;
/*0xac*/    float        zAdjustment3;
/*0xb0*/    float        headingAdjustment3;
/*0xb4*/    FLOAT        Y2;
/*0xb8*/    FLOAT        X2;
/*0xbc*/    FLOAT        Z2;
/*0xc0*/    DWORD        Unknown0xa4;
/*0xc4*/    FLOAT        Heading;
/*0xc8*/    BYTE         Unknown0xc8[0x18];
/*0xe0*/    float        HeightAdjustment;
/*0xe4*/    // more data
} EQSWITCH, *PEQSWITCH;

// actual size 0xdc 2-9-2009
typedef struct _DOOR {
/*0x00*/ void  *vtable;
/*0x04*/ BYTE  Unknown0x4;          // always 5
/*0x05*/ BYTE  ID;
/*0x06*/ CHAR  Name[0x20];
/*0x26*/ BYTE  Type;
/*0x27*/ BYTE  State;               // 0 = closed, 1 = open, 2 = opening, 3 = closing
/*0x28*/ FLOAT DefaultY;
/*0x2c*/ FLOAT DefaultX;
/*0x30*/ FLOAT DefaultZ;
/*0x34*/ FLOAT DefaultHeading;
/*0x38*/ FLOAT DefaultDoorAngle;
/*0x3c*/ FLOAT TopSpeed1;
/*0x40*/ FLOAT TopSpeed2;
/*0x44*/ FLOAT Y;
/*0x48*/ FLOAT X;
/*0x4c*/ FLOAT Z;
/*0x50*/ FLOAT Heading;
/*0x54*/ FLOAT DoorAngle;
/*0x58*/ BYTE  Unknown0x58[0x18];
/*0x70*/ int   Unknown0x70;         // always 0xFFFFFFFF
/*0x74*/ WORD  Unknown0x74;         // actor scale factor?
/*0x76*/ BYTE  Unknown0x76[0x2];
/*0x78*/ DWORD ZonePoint;
/*0x7c*/ BYTE  Unknown0x7c[0x5];
/*0x81*/ BYTE  Unknown0x81;
/*0x82*/ BYTE  Unknown0x82[0x22];
/*0xa4*/ PEQSWITCH pSwitch;         // (CActorInterface*)
/*0xa8*/ void  *pUnknown0xa8;       // (CParticleCloudInterface*)
/*0xac*/ DWORD TimeStamp;
/*0xb0*/ BYTE  Unknown0xb0[0x2c];
/*0xdc*/
} DOOR, *PDOOR; 

// 7-21-2003    Stargazer
typedef struct _DOORTABLE {
/*0x000*/   DWORD NumEntries;
/*0x004*/   PDOOR pDoor[0x0FF];
/*0x400*/
} DOORTABLE, *PDOORTABLE;

// actual size 0x68 2-10-2010 - ieatacid
typedef struct _GROUNDITEM {
/*0x00*/ struct _GROUNDITEM *pPrev;
/*0x04*/ struct _GROUNDITEM *pNext;
/*0x08*/ DWORD  ID;
/*0x0c*/ DWORD  DropID;
/*0x10*/ DWORD  Unknown0x10;
/*0x14*/ DWORD  Unknown0x14;
/*0x18*/ PEQSWITCH pSwitch; // (class EQSwitch *)
/*0x1c*/ CHAR   Name[0x18];
/*0x34*/ BYTE   Unknown0x34[0xc];
/*0x40*/ FLOAT  Heading;
/*0x44*/ BYTE   Unknown0x44[0xc];
/*0x50*/ FLOAT  Y;
/*0x54*/ FLOAT  X;
/*0x58*/ FLOAT  Z;
/*0x5c*/ BYTE   Unknown0x5c[0xc];
/*0x68*/
} GROUNDITEM, *PGROUNDITEM;

#define   MAX_ZONES                     0x3e8
extern    PCHAR szZoneExpansionName[];     //defined in LibEQ_Utilities.cpp

typedef struct _ZONELIST { 
/*0x000*/   DWORD   Header; 
/*0x004*/   DWORD   Unknown0x4;         //pointer to something? 
/*0x008*/   DWORD   Expansion;          // szZoneExpansionName[] 
/*0x00c*/   WORD    Id; 
/*0x00e*/   WORD    Instance; 
/*0x010*/   CHAR    ShortName[0x81]; 
/*0x091*/   CHAR    LongName[0x103]; 
/*0x194*/   DWORD   Unknown0x194; 
/*0x198*/   DWORD   Flags;              // (Flags & 0x100000) = HasMinLevel, 0x4000 no air, 0x2 newbie zone, 0x20 no bind, 0x400000 something, 0x80000000 guild hall
/*0x19c*/   DWORD   Unknown0x19c; 
/*0x1a0*/   DWORD   Id2;                // This is Id+2242 
/*0x1a4*/   DWORD   PoPValue;           // This has something to do with PoP zones. 
/*0x1a8*/   DWORD   MinLevel;           // Minimum level to access 
/*0x1ac*/   WORD    Unknown0x1ac;          
/*0x1ae*/   BYTE    Unknown0x1ae[0x6];    
/*0x1b4*/   DWORD   Unknown0x1b4; 
/*0x1b8*/   DWORD   Unknown0x1b8; 
/*0x1bc*/   DWORD   Unknown0x1bc; 
/*0x1c0      next zone in list*/ 
} ZONELIST, *PZONELIST;

typedef struct _WORLDDATA {
/*0x000*/ PVOID lpvTable;
/*0x004*/ BYTE Hour;
/*0x005*/ BYTE Minute;
/*0x006*/ BYTE Day;
/*0x007*/ BYTE Month;
/*0x008*/ DWORD Year;
/*0x00C*/ BYTE Unknown0x00c[0x14];
/*0x020*/ PZONELIST ZoneArray[MAX_ZONES];
} WORLDDATA, *PWORLDDATA;

typedef struct _ZONEINFO {
/*0x000*/   CHAR    CharacterName[0x40];
/*0x040*/   CHAR    ShortName[0x20];
/*0x060*/   CHAR    Unknown0x060[0x60];
/*0x0c0*/   CHAR    LongName[0x80];
/*0x140*/   CHAR    Unknown0x140[0x96];  // <-- this isnt part of zone name, see CEverQuest__CEverQuest
/*0x1d6*/   BYTE    ZoneType; // (usually FF)
/*0x1d7*/   ARGBCOLOR FogRed;
/*0x1db*/   ARGBCOLOR FogGreen;
/*0x1df*/   ARGBCOLOR FogBlue;
/*0x1e3*/   BYTE    Unknown0x1e3;
/*0x1e4*/   BYTE    Unknown0x1e4[0x10];
/*0x1f4*/   BYTE    Unknown0x1f4[0x10];
/*0x204*/   FLOAT   ZoneGravity;
/*0x208*/   BYTE    Unknown0x208;
/*0x209*/   BYTE    Unknown0x209[0x3];
/*0x20c*/   BYTE    Unknown0x20c[0x2e];
/*0x23a*/   BYTE    SkyType;   
/*0x23b*/   BYTE    Unknown0x23b[0xd];
/*0x248*/   FLOAT   ZoneExpModifier;    //This has been nerfed ..now reads 1.0 for all zones
/*0x24c*/   FLOAT   Unknown0x24c[0x3];
/*0x258*/   BYTE    Unknown0x258[0x4];
/*0x25c*/   FLOAT   Ceiling;
/*0x260*/   FLOAT   Floor;
/*0x264*/   FLOAT   MinClip;
/*0x268*/   FLOAT   MaxClip;
/*0x26c*/   BYTE    Unknown0x26c[0x18];
/*0x284*/   BYTE    Unknown0x284[0x20];
/*0x2a4*/
} ZONEINFO, *PZONEINFO;

#define   TOTAL_SPELL_COUNT             0x6d60      // # of spells allocated in memory (4/7/2009)
#define   TOTAL_ACTUAL_SPELLS           0x1964      // # of ACTUAL spells in game      (9/14/2004) - wrong and unused

// size: 0x17770 08-07-06          
typedef struct _SPELLMGR {
BYTE            unknown[0x68];
struct _SPELL*  Spells[TOTAL_SPELL_COUNT];
} SPELLMGR, *PSPELLMGR;

// actual size: 0x524 12-8-09 - ieatacid
typedef struct _SPELL {
/*0x000*/   BYTE    Location;           //01=Outdoors, 02=dungeons, ff=Any
/*0x001*/   BYTE    Unknown0x1[0x3];
/*0x004*/   FLOAT   PushBack;
/*0x008*/   BYTE    Unknown0x8[0xc];
/*0x014*/   DWORD   BookIcon;
/*0x018*/   FLOAT   AERange;
/*0x01c*/   DWORD   EnduranceCost;      //CA Endurance Cost
/*0x020*/   BYTE    SpellType;          //0=detrimental, 1=Beneficial, 2=Beneficial, Group Only
/*0x021*/   BYTE    Unknown0x21[0xb];
/*0x02c*/   DWORD   ReagentId[0x4];     //ReagentId1-ReagentId4
/*0x03c*/   BYTE    Unknown0x3c[0x4];
/*0x040*/   DWORD   CARecastTimerID;    //ID of combat timer, i think.
/*0x044*/   LONG    Base2[0x0c];        //Mostly unused, setting name to Base2 from Lucy for now
/*0x074*/   BYTE    Unknown0x74[0x29];
/*0x09d*/   BYTE    Environment;
/*0x09e*/   BYTE    Unknown0x9e[0xe];
/*0x0ac*/   DWORD   ID;
/*0x0b0*/   BYTE    Unknown0xb0[0x4];
/*0x0b4*/   DWORD   DurationValue1;
/*0x0b8*/   BYTE    Unknown0xb8[0x8];
/*0x0c0*/   DWORD   Calc[0x0c];         //Calc1-Calc12
/*0x0f0*/   BYTE    Unknown0xf0[0x4];
/*0x0f4*/   DWORD   Mana;
/*0x0f8*/   BYTE    Deletable;
/*0x0f9*/   BYTE    Unknown0xf9[0x3];
/*0x0fc*/   DWORD   DescriptionNumber;
/*0x100*/   BYTE    CanMGB;
/*0x101*/   BYTE    Unknown0x101[0x3];
/*0x104*/   LONG    Max[0xc];           //Max1-Max12
/*0x134*/   DWORD   PvPResistCap;
/*0x138*/   BYTE    Unknown0x138;
/*0x139*/   BYTE    TargetAnim;
/*0x13a*/   BYTE    Unknown0x13a[0x2];
/*0x13c*/   FLOAT   Range;
/*0x140*/   BYTE    Unknown0x140;
/*0x141*/   BYTE    Level[0x10];        //per class.
/*0x151*/   BYTE    Unknown0x151[0x14];
/*0x165*/   BYTE    DurationWindow;     //0=Long, 1=Short
/*0x166*/   BYTE    Unknown0x166;
/*0x167*/   BYTE    CastingAnim;
/*0x168*/   BYTE    Unknown0x168[0x5];
/*0x16d*/   BYTE    FizzleAdj;
/*0x16e*/   BYTE    Unknown0x16e[0x2];
/*0x170*/   DWORD   Autocast;           //SpellID of spell to instacast on caster when current spell lands on target
/*0x174*/   DWORD   Unknown183;         //Unknown183 from Lucy
/*0x178*/   DWORD   Attrib[0x0c];       //Attrib1-Attrib12
/*0x1a8*/   BYTE    Unknown0x1a8[0x8];
/*0x1b0*/   DWORD   RecastTime;
/*0x1b4*/   BYTE    TimeOfDay;          // 0=any, 1=day only, 2=night only
/*0x1b5*/   BYTE    Unknown0x1b5[0x2];
/*0x1b7*/   BYTE    Resist;             //0=un 1=mr 2=fr 3=cr 4=pr 5=dr 6=chromatic 7=prismatic 8=physical(skills,etc) 9=corruption
/*0x1b8*/   DWORD   Unknown144;         //Unknown144 from lucy
/*0x1bc*/   DWORD   CastTime;
/*0x1c0*/   BYTE    LightType;
/*0x1c1*/   BYTE    Unknown0x1c1[0xb];
/*0x1cc*/   DWORD   ReagentCount[0x4];  //ReagentCount1-ReagentCount4
/*0x1dc*/   DWORD   FizzleTime;
/*0x1e0*/   BYTE    Unknown0x1e0[0x4];
/*0x1e4*/   DWORD   PvPResistBase;
/*0x1e8*/   BYTE    Unknown0x1e8[0x8];
/*0x1f0*/   DWORD   Unknown145;         //Unknown145 from lucy
/*0x1f4*/   LONG    Base[0x0c];         //Base1-Base12
/*0x224*/   BYTE    Unknown0x224[0x4];
/*0x228*/   BYTE    TargetType;         //03=Group v1, 04=PB AE, 05=Single, 06=Self, 08=Targeted AE, 0e=Pet, 28=AE PC v2, 29=Group v2
/*0x229*/   BYTE    Unknown0x229[0xf];
/*0x238*/   DWORD   DurationType;       //DurationFormula on Lucy
/*0x23c*/   BYTE    Unknown0x23c[0x9];
/*0x245*/   BYTE    Skill;
/*0x246*/   BYTE    Unknown0x246;
/*0x247*/   CHAR    Name[0x40];
/*0x287*/   CHAR    Target[0x20];
/*0x2a7*/   CHAR    Extra[0x20];        //This is 'Extra' from Lucy (portal shortnames etc)
/*0x2c7*/   CHAR    Unknown0x2c7[0x60];
/*0x327*/   CHAR    Unknown0x327[0x60];
/*0x387*/   CHAR    CastOnYou[0x60];
/*0x3e7*/   CHAR    CastOnAnother[0x60];
/*0x447*/   CHAR    WearOff[0x60];
/*0x4a7*/   BYTE    Unknonw0x4a7[0x5];
/*0x4ac*/   DWORD   spaindex;
/*0x4b0*/   CHAR    *SpellEffectName;
/*0x4b4*/   DWORD   SpellAnim;
/*0x4b8*/   BYTE    Unknown0x4b8[0xc];
/*0x4c4*/   DWORD   SpellIcon;
/*0x4c8*/   DWORD   ResistAdj;
/*0x4cc*/   BYTE    Unknown0x4cc[0x1a];
/*0x4e6*/   BYTE    Uninterruptable;    //00=Interruptable, 01=Uninterruptable 
/*0x4e7*/   BYTE    Unknown0x4e7[0x3d]; 
/*0x524*/
} SPELL, *PSPELL;

// actual size: 0x148 10-25-2006  ieatacid
typedef struct _SKILL {
/*0x000*/  PVOID  pUnknown0x0;       //_SKILL *pNext?
/*0x004*/  PVOID  pUnknown0x4;
/*0x008*/  DWORD  nName;
/*0x00c*/  DWORD  ReuseTimer;
/*0x010*/  DWORD  Unknown0x10;
/*0x014*/  CHAR   AltTimer;          //compare to 2 all over.. alternate timer?
/*0x015*/  BYTE   Unknown0x15[0x3];
/*0x018*/  DWORD  Unknown0x18;
/*0x01c*/  DWORD  Unknown0x1c;
/*0x020*/  CHAR   Activated;
/*0x021*/  CHAR   Unknown0x21;
/*0x022*/  BYTE   Unknown0x22[0x2];
/*0x024*/  DWORD  MinLevel[0x24];
/*0x0b4*/  DWORD  Available[0x24];   //FF=not available for that class
/*0x144*/  DWORD  Unknown0x144;
/*0x148*/  
} SKILL, *PSKILL;

#define NUM_SKILLS 99
typedef struct _SKILLMGR {
/*0x000*/ struct _SKILL *pSkill[NUM_SKILLS];
/*0x004*/ //more data
} SKILLMGR, *PSKILLMGR;

//actual size 0x274  10-2-2006  ieatacid
typedef struct _GUILDMEMBER {
/*0x000*/ struct  _GUILDMEMBER *pNext;
/*0x004*/ BYTE    Online;
/*0x005*/ BYTE    Unknown0x5[0x3];
/*0x008*/ WORD    ZoneID;
/*0x00a*/ WORD    Instance;
/*0x00c*/ BYTE    Unknown0xc[0x4];
/*0x010*/ CHAR    Name[0x40];
/*0x050*/ DWORD   Level;
/*0x054*/ DWORD   Flags; //1=banker, 2=alt
/*0x058*/ DWORD   Class;
/*0x05c*/ DWORD   Rank; //0=member 1=officer 2=leader
/*0x060*/ DWORD   LastSeen; //last seen timestamp
/*0x064*/ CHAR    PublicNote[0x100];
/*0x164*/ CHAR    PersonalNote[0x100];
/*0x264*/ DWORD   TributeStatus;
/*0x268*/ DWORD   TributeDonations;
/*0x26c*/ DWORD   LastDonation;//timestamp
/*0x270*/ DWORD   Unknown0x270;
/*0x274*/
} GUILDMEMBER, *PGUILDMEMBER;

typedef struct _GUILDDATA
{
/*0x00*/ char   Name[0x40];
/*0x04*/ DWORD  ID;
/*0x08*/
} GUILDDATA, *PGUILDDATA;

typedef struct _GUILD
{
/*0x00*/ struct _GUILDDATA *pGuildData;
/*0x04*/ DWORD  ID;
/*0x08*/ _GUILD *pNext;
/*0x0c*/ BYTE   Unknown0xc[0xc];
/*0x18*/
} GUILD, *PGUILD;

typedef struct _GUILDS {
/*0x0000*/ PVOID    pOneEntryVTable;
/*0x0004*/ BYTE     Unknown0x4[0x40];
/*0x0044*/ DWORD    GuildMemberCount;
/*0x0048*/ struct   _GUILDMEMBER *pMember;
/*0x004c*/ CHAR     GuildMotD[0x200];
/*0x024c*/ CHAR     GuildLeader[0x40];
/*0x028c*/ BYTE     Unknown0x288[0x4];
/*0x0290*/ struct _GUILD **GuildList;
/*0x0294*/ DWORD    HashValue;
/*0x0298*/ DWORD    NumberOfGuilds;
/*0x029c*/ BYTE     Unknown0x29c[0x10];
/*0x02ac*/ DWORD    GuildTribute;
/*0x02b0*/ BYTE     Unknown0x2b0[0x17];
/*0x02c7*/ CHAR     GuildUrl[0x200];
/*0x04c7*/ CHAR     GuildChannelName[0x80];
/*0x0547*/ BYTE     Unknown0x547[0x1];
/*0x0548*/
} GUILDS, *PGUILDS;

typedef struct _INTERACTGROUNDITEM {
    DWORD DropID;
    DWORD SpawnID;
} INTERACTGROUNDITEM, *PINTERACTGROUNDITEM;

typedef struct _SPELLFAVORITE {
/*0x000*/   DWORD   SpellId[NUM_SPELL_GEMS];
/*0x030*/   CHAR    Name[0x19];
/*0x049*/   BYTE    inuse;
/*0x04a*/   BYTE    Byte_0x4a;
/*0x04b*/   BYTE    Byte_0x4b;
/*0x04c*/
} SPELLFAVORITE, *PSPELLFAVORITE;

typedef struct _CMDLIST {
    DWORD LocalizedStringID;
    PCHAR szName;
    PCHAR szLocalized;
    VOID  (__cdecl *fAddress)(PSPAWNINFO, PCHAR);
    DWORD Restriction;
    DWORD Category;
    DWORD Unknown;
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

// Size 0x70 (8.11.2004)
typedef struct _ALTABILITY {
/*0x00*/ DWORD Index;
/*0x04*/ DWORD Flags;                    //?
/*0x08*/ DWORD nShortName;
/*0x0c*/ DWORD nShorterName;
/*0x10*/ DWORD nName;                    // now a database number
/*0x14*/ DWORD nDesc;                    // now a database number
/*0x18*/ DWORD MinLevel;
/*0x1c*/ DWORD Cost;                     //Initial Cost or cost the last time you bought a level of it
/*0x20*/ DWORD ID;                       // /alt activate id
/*0x24*/ DWORD AARankRequired;
union {  
/*0x28*/ LONG  RequiresAbility;          // If the value is positive then its the index number of the AA required.
/*0x28*/ DWORD RequiresPointsInCategory; // If the value is negative then abs(value) is the
};                                       // category, while (abs(value))*6 is the points required.
/*0x2c*/ DWORD RequiresAbilityPoints;
/*0x30*/ DWORD Type; 
/*0x34*/ LONG  SpellID;                  // -1 for no Spell
/*0x38*/ BYTE  Unknown0x38[0x8]; 
/*0x40*/ DWORD ReuseTimer;               // in seconds
/*0x44*/ DWORD Classes;                  // Classes/2 is the actual value we want.
/*0x48*/ DWORD MaxRank;                         //If you have not spent points in this 
union {                                         //If you have not spent points in this 
/*0x4c*/ DWORD PointsSpent;                //ability, then its PointsToBeSpent (or 
/*0x4c*/ DWORD PointsToBeSpent;            //'Cost', in other words).
}; 
/*0x50*/ DWORD AAIndex;                  // -1 if not available
/*0x54*/ DWORD UseAAIndex;
/*0x55*/ BYTE  Unknown0x55;
/*0x56*/ BYTE  Unknown0x56;
/*0x57*/ BYTE  Unknown0x57;
/*0x58*/ BYTE  Unknown0x58;
/*0x59*/ BYTE  Unknown0x59[0x18];
} ALTABILITY, *PALTABILITY;
#define zWarp                 0

typedef struct _ALTABILITIESLISTMGR {
/*0x00*/ struct _ALTABILITY* Ability;
/*0x04*/ DWORD Index;
} ALTABILITIESLISTMGR, *PALTABILITIESLISTMGR;

//NUM_ALT_ABILITIES is now defined before CHARINFO definition in this same header file.
typedef struct _ALTABILITIESLIST {
/*0x00*/ struct _ALTABILITIESLISTMGR* Abilities[NUM_ALT_ABILITIES_ARRAY];
} ALTABILITIESLIST, *PALTABILITIESLIST;

typedef struct _NEWALTADVMGR {
/*0x00*/ struct _ALTABILITIESLIST* AltAbilityList;
/*0x04*/ DWORD NumAltAbilities;  // NUM_ALT_ABILITIES
/*0x08*/ DWORD Unknown0x08; // data here
/*0x0c*/ DWORD Unknown0x0c; // data here
/*0x10*/ BYTE  Unknown0x10[0x8];
} NEWALTADVMGR, *PNEWALTADVMGR;

typedef struct _ALTADVMGR {
/*0x00*/ struct _NEWALTADVMGR* AltAbilities;
} ALTADVMGR, *PALTADVMGR;

// size 0x94 (3-19-2009)
typedef struct _EQRAIDMEMBER { 
/*0x000*/ CHAR      Name[0x40]; 
/*0x040*/ CHAR      RaidNote[0x40]; 
/*0x080*/ BYTE      nLevel;
/*0x081*/ BYTE      nClass; 
/*0x082*/ BYTE      RaidLeader; 
/*0x083*/ BYTE      GroupLeader; 
/*0x084*/ BYTE      RaidMainAssist;
/*0x085*/ BYTE      RaidMarker;
/*0x086*/ BYTE      RaidWaypointer;
/*0x087*/ BYTE      Unknown0x87;
/*0x088*/ DWORD     GroupNumber;
/*0x08c*/ BYTE      Unknown0x8c[0x8];
/*0x094*/ 
} EQRAIDMEMBER, *PEQRAIDMEMBER;

// sizeof(_EQRAID) is 0x3668 (12-09-2009)
typedef struct _EQRAID {
/*0x0000*/ BYTE     Unknown0x0[0x218];
/*0x0218*/ CHAR     RaidMemberUsed[0x48];
/*0x0260*/ struct   _EQRAIDMEMBER RaidMember[0x48];
/*0x2c00*/ BYTE     Unknown0x2c00[0x4];
/*0x2c04*/ DWORD    RaidMemberCount;
/*0x2c08*/ CHAR     RaidLeaderName[0x40];
/*0x2c48*/ BYTE     Unknown0x2b88[0x100];
/*0x2d48*/ CHAR     RaidMOTD[0x400];
/*0x3148*/ BYTE     Unknown0x3148[0x40];
/*0x3188*/ BYTE     Invited; // 1 = default?, 2 = invited, 4 = in raid
/*0x3189*/ BYTE     Unknown0x3189[0x8];
/*0x3191*/ BYTE     IsRaidLeader;
/*0x3192*/ BYTE     Unknown0x0x30d2[0x2];
/*0x3194*/ DWORD    RaidTarget;
/*0x3198*/ DWORD    LootType;
/*0x319c*/ CHAR     RaidLooters[0x13][0x40];
/*0x365c*/ DWORD    TotalRaidMemberLevels; // TotalRaidMemberLevels/RaidMemberCount=RaidAvgLevel
/*0x3660*/ BYTE     Locked;
/*0x3661*/ BYTE     Padding0x35a1[0x7];
/*0x3668*/
} EQRAID, *PEQRAID;

// size 0x19C 3-23-2005
typedef struct _EQGROUP {
/*0x000*/ BYTE MemberExists[5];
/*0x005*/ CHAR MemberName[5][0x40];
/*0x145*/ BYTE Unused[3];
/*0x148*/ struct _SPAWNINFO* pMember[5];
/*0x15C*/ CHAR LeaderName[0x40];
/*0x19C*/
} EQGROUP, *PEQGROUP;

// size 0x08
typedef struct _EQSTRING {
/*0x00*/    DWORD ID;
/*0x04*/    PCHAR String;
} EQSTRING, *PEQSTRING;

// size 0x10 4-28-2004 lax
typedef struct _EQSTRINGTABLE {
/*0x00*/ struct _EQSTRING **StringItems;
/*0x04*/ DWORD Size;
/*0x08*/ DWORD Count;
/*0x0c*/ DWORD Unknown0x0c;
/*0x10*/
} EQSTRINGTABLE, *PEQSTRINGTABLE;

typedef struct connection_t {
/*0x000*/ void  *vtable;
/*0x004*/ BYTE  Unknown0x4[0x100];
/*0x104*/ DWORD Master;
/*0x108*/ DWORD Average;
/*0x10c*/ DWORD Low;
/*0x110*/ DWORD High;
/*0x114*/ DWORD Last;
/*0x118*/
} CONNECTION_T, *PCONNECTION_T;

//actual size 0x2dfc 3-19-09 - ieatacid 
typedef struct _CDISPLAY {
/*0x0000*/ BYTE   Unknown0x000[0x12c];
/*0x012c*/ void   *pActorTagManager;
/*0x0130*/ BYTE   Unknown0x130[0x24];
/*0x0154*/ DWORD  TimeStamp;
/*0x0158*/ BYTE   Unknown0x158[0x2c12];
/*0x2d6a*/ BYTE   NpcNames; // show npc names
} CDISPLAY, *PCDISPLAY;

//5-16-06 - ieatacid
typedef struct _DZTIMERINFO {
/*0x000*/ CHAR   ExpeditionName[0x80];
/*0x080*/ CHAR   EventName[0x100];
/*0x180*/ DWORD  TimeStamp;  // TimeStamp - Util__FastTime = time left
/*0x184*/ DWORD  TimerID;
/*0x188*/ struct _DZTIMERINFO *pNext;
/*0x18c*/
} DZTIMERINFO, *PDZTIMERINFO;

typedef struct _DZMEMBER {
/*0x000*/ CHAR   Name[0x40];
/*0x040*/ DWORD  Status;  // 0="unknown", 1="Online", 2="Offline", 3="In Dynamic Zone", 4="Link Dead"
/*0x044*/ struct _DZMEMBER *pNext;
/*0x048*/
} DZMEMBER, *PDZMEMBER;

typedef struct _TASKMEMBER {
/*0x000*/ CHAR   Name[0x40];
/*0x040*/ DWORD  Unknown0x40;
/*0x044*/ DWORD  IsLeader;
/*0x048*/ struct _TASKMEMBER *pNext;
/*0x04c*/
} TASKMEMBER, *PTASKMEMBER;

typedef struct _DYNAMICZONE {
/*0x000*/ void   *vftable;
/*0x004*/ BYTE   Unknown0x04[0x46];
/*0x04a*/ CHAR   Name[0x40]; // your name
/*0x08a*/ CHAR   ExpeditionName[0x80];
/*0x10a*/ BYTE   Unknown0x10a[0x2];
/*0x10c*/ WORD   MaxPlayers;
/*0x10e*/ BYTE   Unknown0x10e[0x2];
/*0x110*/ struct _DZMEMBER *pMemberList;
/*0x114*/ PCHAR  expeditionName;
/*0x118*/ // more?
} DYNAMICZONE, *PDYNAMICZONE;

typedef struct _CHATCHANNELS {
/*0x000*/ PCHAR  ChannelName[0xa];
/*0x004*/
} CHATCHANNELS, *PCHATCHANNELS;

typedef struct _CHATSERVICE {
/*0x000*/ BYTE   Unknown0x0[0xc];
/*0x00c*/ struct _CHATCHANNELS *ChannelList;
/*0x010*/ DWORD  ActiveChannels;   // number of channels joined
/*0x014*/ BYTE   Unknown0x14[0xc];
/*0x020*/ CHAR   ChatID[0x30];     // "ServerName.CharName" (0x60?)
/*0x050*/ BYTE   Unknown0x50[0x30];
/*0x080*/ CHAR   ServerName[0x30]; // "ServerName."
/*0x0b0*/ // more data
} CHATSERVICE, *PCHATSERVICE;

typedef struct _EVERQUEST {
/*0x000*/ BYTE   Unknown[0x2a4];
/*0x2a4*/ struct _CHATSERVICE *ChatService;
/*0x2a8*/ BYTE   Unknown0x2a8[0x320];
/*0x5c8*/ DWORD  GameState;
/*0x5cc*/ // more data
} EVERQUEST, *PEVERQUEST;

typedef struct _AURAINFO {
/*0x000*/ CHAR    Name[0x40];
/*0x040*/ BYTE    Unknown0x14[0xc];
/*0x04c*/
} AURAINFO, *PAURAINFO;

typedef struct _AURAS {
/*0x000*/ _AURAINFO Aura[0x2];
} AURAS, *PAURAS;

typedef struct _AURAMGR {
/*0x000*/ DWORD   NumAuras;
/*0x004*/ BYTE    Unknown0x4[0xc];
/*0x010*/ _AURAS  **pAuraInfo;
/*0x014*/ BYTE    Unknown0x14[0x8];
/*0x01c*/
} AURAMGR, *PAURAMGR;

typedef struct _INTERACTSWITCH {
/*0x000*/ DWORD   switchID;
/*0x004*/ DWORD   dwzero;
/*0x008*/ DWORD   dwneg1;
/*0x00c*/ DWORD   spawnID;
} INTERACTSWITCH, *PINTERACTSWITCH;

typedef struct _MERCENARYINFO {
/*0x000*/ BYTE Unknown0x0[0x3c];
/*0x03c*/ DWORD HaveMerc;
/*0x040*/ DWORD MercState; // 1 = suspended, 5 = active
} MERCENARYINFO, *PMERCENARYINFO;

#define MAX_XTARGETS 5

enum xTargetTypes
{
    XTARGET_EMPTY_TARGET,
    XTARGET_AUTO_HATER,
    XTARGET_SPECIFIC_PC,
    XTARGET_SPECIFIC_NPC,
    XTARGET_TARGETS_TARGET,
    XTARGET_GROUP_TANK,
    XTARGET_GROUP_TANKS_TARGET,
    XTARGET_GROUP_ASSIST,
    XTARGET_GROUP_ASSIST_TARGET,
    XTARGET_GROUP_PULLER,
    XTARGET_GROUP_PULLER_TARGET,
    XTARGET_GROUP_MARK1,
    XTARGET_GROUP_MARK2,
    XTARGET_GROUP_MARK3,
    XTARGET_RAID_ASSIST1,
    XTARGET_RAID_ASSIST2,
    XTARGET_RAID_ASSIST3,
    XTARGET_RAID_ASSIST1_TARGET,
    XTARGET_RAID_ASSIST2_TARGET,
    XTARGET_RAID_ASSIST3_TARGET,
    XTARGET_RAID_MARK1,
    XTARGET_RAID_MARK2,
    XTARGET_RAID_MARK3,
    XTARGET_MY_PET,
    XTARGET_MY_PET_TARGET,
    XTARGET_MY_MERCENARY,
    XTARGET_MY_MERCENTARY_TARGET
};

// size 0x4c 12-25-09 - ieatacid
typedef struct _XTARGETDATA
{
/*0x00*/ DWORD  xTargetType;
/*0x04*/ DWORD  Unknown0x4;
/*0x08*/ DWORD  SpawnID;
/*0x0c*/ char   Name[0x40];
/*0x4c*/
} XTARGETDATA, *PXTARGETDATA;

typedef struct _XTARGETARRAY
{
    XTARGETDATA pXTargetData[MAX_XTARGETS];
} XTARGETARRAY, *PXTARGETARRAY;

// size 0x20 12-25-09 - ieatacid
typedef struct _XTARGETMGR
{
/*0x00*/ void  *vftable;
/*0x04*/ DWORD TargetSlots; // MAX_XTARGETS
/*0x08*/ PXTARGETARRAY pXTargetArray;
/*0x0c*/ DWORD Unknown0xc;  // same as TargetSlots?
/*0x10*/ BYTE  Unknown0x10[0x4];
/*0x14*/ BYTE  AutoAddHaters; // 1 = auto add haters, 0 = do not auto add haters
/*0x15*/ BYTE  Unknown0x15[0x3];
/*0x18*/ BYTE  Unknown0x18[0x4];
/*0x1c*/ BYTE  Unknown0x1c[0x4];
/*0x20*/
} XTARGETMGR, *PXTARGETMGR;

#define EQ_BEGIN_ZONE                   0x2913  // CEverQuest__SavePCForce+45F     12-15-2009
#define EQ_END_ZONE                     0x6CDC  // CEverQuest__DoMainLoop+B2F      12-15-2009
#define EQ_LoadingS__ArraySize          0x45    // EQ_LoadingS__SetProgressBar+7C  12-15-2009
};
using namespace EQData;
