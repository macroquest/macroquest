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

#define nEQMappableCommands             0x1ef

#define MAX_PC_LEVEL                    95
#define NUM_SPELL_GEMS                  12
#define NUM_SPELL_SETS                  10
#define NUM_BUFF_SLOTS					0x61
#define NUM_LONG_BUFFS                  42
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

// actual size: 0x62c 20120815 - ieatacid
typedef struct _ITEMINFO {
/*0x000*/ CHAR   Name[ITEM_NAME_LEN];
/*0x040*/ CHAR   LoreName[LORE_NAME_LEN];
/*0x0b0*/ CHAR   IDFile[0x20];
/*0x0d0*/ BYTE   Unknown0xd0[0x1c];
/*0x0ec*/ DWORD  ItemNumber;
/*0x0f0*/ DWORD  EquipSlots;
/*0x0f4*/ DWORD  Cost;
/*0x0f8*/ DWORD  IconNumber;
/*0x0fc*/ BYTE   Unknown0xfc[0xc];
/*0x108*/ DWORD  Weight;
/*0x10c*/ BYTE   NoRent; // 0=temp, 1=default
/*0x10d*/ BYTE   NoDrop; // 0=no drop, 1=can drop
/*0x10e*/ BYTE   Attuneable;
/*0x10f*/ BYTE   Unknown0x10f;
/*0x110*/ BYTE   Size;
/*0x111*/ BYTE   Type;
/*0x112*/ BYTE   TradeSkills;
/*0x113*/ BYTE   Padding0x113;
/*0x114*/ DWORD  Lore;
/*0x118*/ BYTE   Artifact;
/*0x119*/ BYTE   Summoned;
/*0x11a*/ CHAR   SvCold;
/*0x11b*/ CHAR   SvFire;
/*0x11c*/ CHAR   SvMagic;
/*0x11d*/ CHAR   SvDisease;
/*0x11e*/ CHAR   SvPoison;
/*0x11f*/ CHAR   SvCorruption;
/*0x120*/ CHAR   STR;
/*0x121*/ CHAR   STA;
/*0x122*/ CHAR   AGI;
/*0x123*/ CHAR   DEX;
/*0x124*/ CHAR   CHA;
/*0x125*/ CHAR   INT;
/*0x126*/ CHAR   WIS;
/*0x127*/ BYTE   Unknown0x127;
/*0x128*/ DWORD  HP;
/*0x12c*/ DWORD  Mana;
/*0x130*/ DWORD  AC;
/*0x134*/ DWORD  RequiredLevel;
/*0x138*/ DWORD  RecommendedLevel;
/*0x13c*/ BYTE   RecommendedSkill;
/*0x13d*/ BYTE   Unknown0x13d[0x3];
/*0x140*/ DWORD  SkillModType;
/*0x144*/ DWORD  SkillModValue;
/*0x148*/ DWORD  Unknown0x148;
/*0x14c*/ DWORD  Unknown0x14c;
/*0x150*/ DWORD  BaneDMGRace;
/*0x154*/ DWORD  BaneDMGBodyType;
/*0x158*/ BYTE   BaneDMGBodyTypeValue;
/*0x159*/ BYTE   BaneDMGRaceValue;
/*0x15a*/ BYTE   Unknown0x15a[0x6];
/*0x160*/ DWORD  InstrumentType;
/*0x164*/ DWORD  InstrumentMod;
/*0x168*/ DWORD  Classes;
/*0x16c*/ DWORD  Races;
/*0x170*/ DWORD  Diety;
/*0x174*/ BYTE   Unknown0x174[0x4];
/*0x178*/ BYTE   Magic;
/*0x179*/ BYTE   Light;
/*0x17a*/ BYTE   Delay;
/*0x17b*/ BYTE   DmgBonusType;
/*0x17c*/ BYTE   DmgBonusVal;
/*0x17d*/ BYTE   Range;
/*0x17e*/ BYTE   Unknown0x17e[0x2];
/*0x180*/ DWORD  Damage;
/*0x184*/ DWORD  BackstabDamage;
/*0x188*/ DWORD  DamageShieldMitigation;
/*0x18c*/ DWORD  HeroicSTR;
/*0x190*/ DWORD  HeroicINT;
/*0x194*/ DWORD  HeroicWIS;
/*0x198*/ DWORD  HeroicAGI;
/*0x19c*/ DWORD  HeroicDEX;
/*0x1a0*/ DWORD  HeroicSTA;
/*0x1a4*/ DWORD  HeroicCHA;
/*0x1a8*/ DWORD  HeroicSvMagic;
/*0x1ac*/ DWORD  HeroicSvFire;
/*0x1b0*/ DWORD  HeroicSvCold;
/*0x1b4*/ DWORD  HeroicSvDisease;
/*0x1b8*/ DWORD  HeroicSvPoison;
/*0x1bc*/ DWORD  HeroicSvCorruption;
/*0x1c0*/ DWORD  HealAmount;
/*0x1c4*/ DWORD  SpellDamage;
/*0x1c8*/ DWORD  Unknown0x1c8;
/*0x1cc*/ BYTE   ItemType;
/*0x1cd*/ BYTE   Unknown0x1cd[0x3];
/*0x1d0*/ BYTE   Material;
/*0x1d1*/ BYTE   Unknown0x1d1[0x13];
/*0x1e4*/ DWORD  AugSlot1;
/*0x1e8*/ DWORD  AugSlot1_Unknown;
/*0x1ec*/ DWORD  AugSlot2;
/*0x1f0*/ DWORD  AugSlot2_Unknown;
/*0x1f4*/ DWORD  AugSlot3;
/*0x1f8*/ DWORD  AugSlot3_Unknown;
/*0x1fc*/ DWORD  AugSlot4;
/*0x200*/ DWORD  AugSlot4_Unknown;
/*0x204*/ DWORD  AugSlot5;
/*0x208*/ DWORD  AugSlot5_Unknown;
/*0x20c*/ DWORD  AugSlot6;
/*0x210*/ DWORD  AugSlot6_Unknown;
/*0x214*/ DWORD  AugType;
/*0x218*/ DWORD  AugRestrictions;
/*0x21c*/ DWORD  Unknown0x21c;
/*0x220*/ DWORD  SolventNeeded; //ID# of Solvent (Augs only)
/*0x224*/ DWORD  LDTheme;
/*0x228*/ DWORD  LDCost;
/*0x22c*/ DWORD  LDType;
/*0x230*/ DWORD  Unknown0x230;
/*0x234*/ BYTE   Unknown0x234[0x4];
/*0x238*/ DWORD  FactionModType[0x4];
/*0x248*/ DWORD  FactionModValue[0x4];
/*0x258*/ BYTE   CharmFile[0x20];
/*0x278*/ BYTE   Unknown0x278[0x4];
/*0x27c*/ struct _ITEMSPELLS Clicky;
/*0x2e0*/ struct _ITEMSPELLS Proc;
/*0x344*/ struct _ITEMSPELLS Worn;
/*0x3a8*/ struct _ITEMSPELLS Focus;
/*0x40c*/ struct _ITEMSPELLS Scroll;
/*0x470*/ BYTE   Unknown0x470[0x78];
/*0x4e8*/ DWORD  CombatEffects;
/*0x4ec*/ DWORD  Shielding;
/*0x4f0*/ DWORD  StunResist;
/*0x4f4*/ DWORD  DoTShielding;
/*0x4f8*/ DWORD  StrikeThrough;
/*0x4fc*/ DWORD  DmgBonusSkill; // SkillMinDamageMod;
/*0x500*/ DWORD  DmgBonusValue; // MinDamageMod;
/*0x504*/ DWORD  SpellShield;
/*0x508*/ DWORD  Avoidance;
/*0x50c*/ DWORD  Accuracy;
/*0x510*/ DWORD  CharmFileID;
/*0x514*/ DWORD  CastTime;
/*0x518*/ BYTE   Combine;
/*0x519*/ BYTE   Slots;
/*0x51a*/ BYTE   SizeCapacity;
/*0x51b*/ BYTE   WeightReduction;
/*0x51c*/ BYTE   BookType;      // 0=note, !0=book
/*0x51d*/ BYTE   BookLang;
/*0x51e*/ CHAR   BookFile[0x1e];
/*0x53c*/ DWORD  Favor;         // Tribute Value
/*0x540*/ DWORD  GuildFavor;
/*0x544*/ DWORD  Unknown0x544;
/*0x548*/ DWORD  Endurance;
/*0x54c*/ DWORD  Attack;
/*0x550*/ DWORD  HPRegen;
/*0x554*/ DWORD  ManaRegen;
/*0x558*/ DWORD  EnduranceRegen;
/*0x55c*/ DWORD  Haste;
/*0x560*/ DWORD  DamShield;
/*0x564*/ BYTE   Unknown0x564[0x8];
/*0x56c*/ BYTE   NoPet;
/*0x56d*/ BYTE   Unknown0x56d[0xb];
/*0x578*/ DWORD  StackSize;
/*0x57c*/ BYTE   Unknown0x57c[0x4];
/*0x580*/ DWORD  MaxPower;
/*0x584*/ DWORD  Purity;
/*0x588*/ BYTE   Unknown0x588[0x4];
/*0x58c*/ DWORD  Unknown0x58c;
/*0x590*/ BYTE   QuestItem;
/*0x591*/ BYTE   Unknown0x591[0x3];
/*0x594*/ DWORD  Clairvoyance;
/*0x598*/ BYTE   Unknown0x598[0x94];
/*0x62c*/
} ITEMINFO, *PITEMINFO;

typedef struct _CONTENTSARRAY {
    struct  _CONTENTS *Contents[0x14]; // 20 bag-slot max - addresses to whats inside the bag if its a bag; augs if an item
} CONTENTSARRAY, *PCONTENTSARRAY;

// actual size 0x158 20120815 - ieatacid
typedef struct _CONTENTS {
/*0x000*/  void    *vtable;
/*0x004*/  DWORD   ItemType;          // ? 1 = normal, 2 = pack ?
/*0x008*/  void    *punknown;
/*0x00c*/  DWORD   ItemSlot;
/*0x010*/  BYTE    Unknown0x10[0xc];
/*0x01c*/  DWORD   EvolvingCurrentLevel;
/*0x020*/  DWORD   Price;             // merchant price  
/*0x024*/  BYTE    Unknown0x24[0x24];
/*0x048*/  DWORD   EvolvingLoreGroup; // lore group if it's an evolving item
/*0x04c*/  BYTE    Unknown0x4c[0x4];
/*0x050*/  DWORD   NumOfSlots1;
/*0x054*/  DWORD   Unknown0x6c;
/*0x058*/  struct  _CONTENTSARRAY *pContentsArray;
/*0x05c*/  DWORD   NumOfSlots2;
/*0x060*/  DWORD   NumOfSlots3;
/*0x064*/  BYTE    Unknown0x64[0x2c];
/*0x090*/  struct  _ITEMINFO *Item1;
/*0x094*/  DWORD   EvolvingMaxLevel;
/*0x098*/  BYTE    Unknown0x98[0x1c];
/*0x0b4*/  DWORD   StackCount;
/*0x0b8*/  BYTE    Unknown0xb8[0x38];
/*0x0f0*/  DWORD   MerchantSlot;      // slot id on a merchant
/*0x0f4*/  BYTE    Unknown0xf4[0xc];
/*0x100*/  DWORD   Charges;           // charges if positive; some things are neg
/*0x104*/  BYTE    Unknown0x104[0x4];
/*0x108*/  DWORD   Power;
/*0x10c*/  BYTE    IsEvolvingItem;
/*0x10d*/  BYTE    Unknown0x10d[0x3];
/*0x110*/  DOUBLE  EvolvingExpPct;
/*0x118*/  BYTE    EvolvingExpOn;
/*0x119*/  BYTE    Unknown0x119[0x3];
/*0x11c*/  DWORD   MerchantQuantity;  // amount that a merchant has for sale, -1 for unlimited
/*0x120*/  BYTE    Unknown0x120[0x24];
/*0x144*/  DWORD   Open;
/*0x148*/  BYTE    Unknown0x148[0x4];
/*0x14c*/  struct   _ITEMINFO *Item2;
/*0x150*/  BYTE    Unknown0x150[0x8];
/*0x158*/
} CONTENTS, *PCONTENTS;

// Size 0x58 20110810 - dkaa
typedef struct _SPELLBUFF {
/*0x00*/    BYTE      Unknown0x0;
/*0x01*/    BYTE      Level;
/*0x02*/    CHAR      Modifier;      // bard song modifier, divide by 10 to get 2.8 etc
/*0x03*/    CHAR      DamageShield;  // maybe.. I've noticed this is -1 on a lot of ds's.
/*0x04*/    FLOAT     Unknown0x4;
/*0x08*/    LONG      SpellID;       // -1 or 0 for no spell..
/*0x0c*/    DWORD     Duration;
/*0x10*/    BYTE      Unknown0x10[0x48];
/*0x58*/
} SPELLBUFF, *PSPELLBUFF;

// 20101012 - ieatacid
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
/*0x5c*/  struct    _CONTENTS* Pack[0xa];
/*0x84*/  struct    _CONTENTS* Cursor;
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

#define      NUM_INV_SLOTS              0x21
#define      NUM_BANK_SLOTS             0x18
#define      NUM_SHAREDBANK_SLOTS       0x02
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

typedef struct _BANKARRAY {
/*0x00*/ struct _CONTENTS* Bank[NUM_BANK_SLOTS];
/*0x68*/
} BANKARRAY, *PBANKARRAY;

typedef struct _SHAREDBANKARRAY {
/*0x00*/ struct _CONTENTS* SharedBank[NUM_SHAREDBANK_SLOTS];
/*0x68*/
} SHAREDBANKARRAY, *PSHAREDBANKARRAY;

// actual size: 0x606c 20120815 - ieatacid
typedef struct _CHARINFO {
/*0x0000*/   void       *vtable1;
/*0x0004*/   void       *punknown;
/*0x0008*/   struct     _CI_INFO* charinfo_info;
/*0x000c*/   BYTE       Unknown0xc[0x106c];
/*0x1078*/   struct     _LEADERABILITIES MyAbilities; //points spent in each ability (size 0x40)
/*0x10b8*/   BYTE       Unknown0x10b8[0xc0];
/*0x1178*/   DWORD      Unknown0x1178; // # of bank slots?
/*0x117c*/   DWORD      Unknown0x117c;
/*0x1180*/   struct     _BANKARRAY *pBankArray;
/*0x1184*/   DWORD      Unknown0x1184; // # of bank slots?
/*0x1188*/   BYTE       Unknown0x1188[0x28];
/*0x11b0*/   DWORD      Unknown0x11b0; // # of bank slots?
/*0x11b4*/   DWORD      Unknown0x11b4;
/*0x11b8*/   struct     _SHAREDBANKARRAY *pSharedBankArray;
/*0x11bc*/   DWORD      Unknown0x11bc; // # of bank slots?
/*0x11c0*/   BYTE       Unknown0x11c0[0x164];
/*0x1324*/   DWORD      GuildID;
/*0x1328*/   BYTE       Unknown0x1328[0x2c];
/*0x1354*/   DWORD      AAExp;
/*0x1358*/   BYTE       Unknown0x1358;
/*0x1359*/   BYTE       PercentEXPtoAA;
/*0x135a*/   BYTE       Unknown0x135a[0x42];
/*0x139c*/   DWORD      TributeTimer;
/*0x13a0*/   DWORD      BenefitTimer;
/*0x13a4*/   DWORD      Unknown0x13a4;
/*0x13a8*/   DWORD      CareerFavor;
/*0x13ac*/   DWORD      Unknown0x13ac;
/*0x13b0*/   DWORD      CurrFavor;
/*0x13b4*/   BYTE       Unknown0x13b4[0xc];
/*0x13c0*/   DOUBLE     GroupLeadershipExp;
/*0x13c8*/   DOUBLE     RaidLeadershipExp;
/*0x13d0*/   DWORD      GroupLeadershipPoints;
/*0x13d4*/   DWORD      RaidLeadershipPoints;
/*0x13d8*/   BYTE       Unknown0x13d8[0x194];
/*0x156c*/   DWORD      RadiantCrystals;
/*0x1570*/   DWORD      Unknown0x1570;
/*0x1574*/   DWORD      EbonCrystals; 
/*0x1578*/   BYTE       Unknown0x1578[0x670];
/*0x1be8*/   DWORD      Exp;
/*0x1bec*/   BYTE       Unknown0x1bec[0x64];
/*0x1c50*/   void       *PlayerPointManager;
/*0x1c54*/   BYTE       Unknown0x1c54[0x1bf4];
/*0x3848*/   void       *vtable2;
/*0x384c*/   struct     _EQC_INFO* eqc_info;
/*0x3850*/   struct     _SPAWNINFO* pSpawn;
/*0x3854*/   DWORD      Unknown0x3854;
/*0x3858*/   DWORD      Unknown0x3858;
/*0x385c*/   DWORD      CurrWeight;
/*0x3860*/   BYTE       Unknown0x3860[0xc];
/*0x386c*/   DWORD      HPBonus;
/*0x3870*/   DWORD      ManaBonus;
/*0x3874*/   DWORD      EnduranceBonus;
/*0x3878*/   DWORD      CombatEffectsCap;//CombatEffectsBonus
/*0x387c*/   DWORD      ShieldingCap;//ShieldingBonus
/*0x3880*/   DWORD      SpellShieldCap;//SpellShieldBonus
/*0x3884*/   DWORD      AvoidanceCap;//AvoidanceBonus
/*0x3888*/   DWORD      AccuracyCap;//AccuracyBonus
/*0x388c*/   DWORD      StunResistCap;//StunResistBonus
/*0x3890*/   DWORD      StrikeThroughCap;//StrikeThroughBonus
/*0x3894*/   DWORD      Unknown0x3894[0x9];
/*0x38b8*/   DWORD      SkillMinDamageModBonus[0x9];
/*0x38dc*/   BYTE       Unknown0x38dc[0x4];
/*0x38e0*/   DWORD      DoTShieldCap;//DoTShieldBonus
/*0x38e4*/   DWORD      DamageShieldMitigationCap;//DamageShieldMitigationBonus
/*0x38e8*/   DWORD      CombatEffectsBonus;
/*0x38ec*/   DWORD      SpellShieldBonus;
/*0x38f0*/   DWORD      ShieldingBonus;
/*0x38f4*/   DWORD      DamageShieldBonus;
/*0x38f8*/   DWORD      DoTShieldBonus;
/*0x38fc*/   DWORD      DamageShieldMitigationBonus;
/*0x3900*/   DWORD      AvoidanceBonus;
/*0x3904*/   DWORD      AccuracyBonus;
/*0x3908*/   DWORD      StunResistBonus;
/*0x390c*/   DWORD      StrikeThroughBonus;
/*0x3910*/   DWORD      HeroicSTRBonus;
/*0x3914*/   DWORD      HeroicINTBonus;
/*0x3918*/   DWORD      HeroicWISBonus;
/*0x391c*/   DWORD      HeroicAGIBonus;
/*0x3920*/   DWORD      HeroicDEXBonus;
/*0x3924*/   DWORD      HeroicSTABonus;
/*0x3928*/   DWORD      HeroicCHABonus;
/*0x392c*/   DWORD      HeroicSvMagicBonus;
/*0x3930*/   DWORD      HeroicSvFireBonus;
/*0x3934*/   DWORD      HeroicSvColdBonus;
/*0x3938*/   DWORD      HeroicSvDiseaseBonus;
/*0x393c*/   DWORD      HeroicSvPoisonBonus;
/*0x3940*/   DWORD      HeroicSvCorruptionBonus;
/*0x3944*/   DWORD      HealAmountBonus;
/*0x3948*/   DWORD      SpellDamageBonus;
/*0x394c*/   DWORD      Unknown0x394c[0x2];
/*0x3954*/   DWORD      ClairvoyanceBonus;
/*0x3958*/   DWORD      AttackBonus;
/*0x395c*/   DWORD      HPRegenBonus;
/*0x3960*/   DWORD      ManaRegenBonus;
/*0x3964*/   DWORD      EnduranceRegenBonus;
/*0x3968*/   DWORD      DamageShieldCap;
/*0x396c*/   DWORD      AttackSpeed;
/*0x3970*/   BYTE       Unknown0x3970[0xb0];
/*0x3a20*/   struct     _XTARGETMGR *pXTargetMgr;
/*0x3a24*/   DWORD      InCombat;
/*0x3a28*/   DWORD      Downtime;
/*0x3a2c*/   DWORD      DowntimeStamp;
/*0x3a30*/   BYTE       Unknown0x3a30[0x4];
/*0x3a34*/   struct     _GROUPINFO *pGroupInfo;
/*0x3a38*/   BYTE       Unknown0x3a38[0x1c];
/*0x3a54*/   void       *pUnknown2;
/*0x3a58*/   struct     _CI2_INFO* pCI2;
/*0x3a5c*/   DWORD      Unknown0x3a5c;
/*0x3a60*/   BYTE       languages[0x20];
/*0x3a80*/   BYTE       Unknown0x3a78[0x10];
/*0x3a90*/   CHAR       Name[0x40];
/*0x3ad0*/   CHAR       Lastname[0x20];
/*0x3af0*/   BYTE       Unknown0x3af0[0x60];
/*0x3b50*/   BYTE       Stunned;
/*0x3b51*/   BYTE       Unknown0x3b51[0x3];
/*0x3b54*/   WORD       zoneId;
/*0x3b56*/   WORD       instance;
/*0x3b58*/   DWORD      standstate;
/*0x3b5c*/   BYTE       Unknown0x3b5c[0x4];
/*0x3b60*/   struct     _LEADERABILITIES ActiveAbilities; //ability levels of the leader of your group (size 0x40)
/*0x3ba0*/   BYTE       Unknown0x3ba0[0x334];
/*0x3ed4*/   DWORD      BankSharedPlat;
/*0x3ed8*/   DWORD      BankSharedGold;
/*0x3edc*/   DWORD      BankSharedSilver;
/*0x3ee0*/   DWORD      BankSharedCopper;
/*0x3ee4*/   DWORD      BankPlat;
/*0x3ee8*/   DWORD      BankGold;
/*0x3eec*/   DWORD      BankSilver;
/*0x3ef0*/   DWORD      BankCopper;
/*0x3ef4*/   DWORD      STR;
/*0x3ef8*/   DWORD      STA;
/*0x3efc*/   DWORD      CHA;
/*0x3f00*/   DWORD      DEX;
/*0x3f04*/   DWORD      INT;
/*0x3f08*/   DWORD      AGI;
/*0x3f0c*/   DWORD      WIS;
/*0x3f10*/   DWORD      SavePoison;
/*0x3f14*/   DWORD      SaveMagic;
/*0x3f18*/   DWORD      SaveDisease;
/*0x3f1c*/   DWORD      SaveCorruption;
/*0x3f20*/   DWORD      SaveFire;
/*0x3f24*/   DWORD      SaveCold;
/*0x3f28*/   BYTE       Unknown0x3f28[0x2144];
/*0x606c*/
} CHARINFO, *PCHARINFO;

typedef struct _INVENTORYARRAY {
union {
/*0x00*/ struct _INVENTORY Inventory;
/*0x00*/ struct _CONTENTS* InventoryArray[NUM_INV_SLOTS];
};
} INVENTORYARRAY, *PINVENTORYARRAY;

// *note* Cursor is no longer a member of _CHARINFO2.  access with pInventoryArray->Inventory.Cursor
// actual size: 0x97c0 20120815 - ieatacid
typedef struct _CHARINFO2 {
/*0x0000*/   BYTE       Unknown0x0[0x18];
/*0x0018*/   DWORD      Unknown0x18; // # of inventory slots?
/*0x001c*/   DWORD      Unknown0x1c;
/*0x0020*/   struct     _INVENTORYARRAY *pInventoryArray;
/*0x0024*/   DWORD      Unknown0x24; // # of inventory slots?
/*0x0024*/   DWORD      Unknown0x28; // # of inventory slots?
/*0x0028*/   BYTE       Unknown0x2c[0x94];
/*0x00c0*/   struct     _SPELLBUFF   Buff[NUM_LONG_BUFFS];
/*0x0f30*/   struct     _SPELLBUFF   ShortBuff[0x37];
/*0x2218*/   DWORD      Unknown0x2218[NUM_BUFF_SLOTS]; // effect IDs
/*0x239c*/   DWORD      Unknown0x239c[NUM_BUFF_SLOTS];
/*0x2520*/   DWORD      SpellBook[NUM_BOOK_SLOTS];
/*0x3060*/   DWORD      MemorizedSpells[0x10];
/*0x30a0*/   DWORD      Skill[0x64];
/*0x3230*/   DWORD      InnateSkill[0x19];
/*0x3294*/   DWORD      Unknown0x3294[0x36];
/*0x336c*/   DWORD      Gender;
/*0x3370*/   DWORD      Race;
/*0x3374*/   DWORD      Class;
/*0x3378*/   BYTE       Unknown0x3378[0x10];
/*0x3388*/   DWORD      Level;
/*0x338c*/   DWORD      Mana;
/*0x3390*/   DWORD      Endurance;
/*0x3394*/   DWORD      BaseHP;
/*0x3398*/   DWORD      BaseSTR;
/*0x339c*/   DWORD      BaseSTA;
/*0x33a0*/   DWORD      BaseCHA;
/*0x33a4*/   DWORD      BaseDEX;
/*0x33a8*/   DWORD      BaseINT;
/*0x33ac*/   DWORD      BaseAGI;
/*0x33b0*/   DWORD      BaseWIS;
/*0x33b4*/   DWORD      Unknown0x33b4;
/*0x33b8*/   DWORD      Plat;
/*0x33bc*/   DWORD      Gold;
/*0x33c0*/   DWORD      Silver;
/*0x33c4*/   DWORD      Copper;
/*0x33c8*/   DWORD      CursorPlat;
/*0x33cc*/   DWORD      CursorGold;
/*0x33d0*/   DWORD      CursorSilver;
/*0x33d4*/   DWORD      CursorCopper;
/*0x33d8*/   BYTE       Unknown0x33d8[0x28];
/*0x3400*/   DWORD      thirstlevel;
/*0x3404*/   DWORD      hungerlevel;
/*0x3408*/   DWORD      Unknown0x3408; 
/*0x340c*/   DWORD      Shrouded;
/*0x3410*/   BYTE       Unknown0x3410[0x78];
/*0x3488*/   DWORD      ZoneBoundID;
/*0x348c*/   FLOAT      ZoneBoundY;
/*0x3490*/   FLOAT      ZoneBoundX;
/*0x3494*/   FLOAT      ZoneBoundZ;
/*0x3498*/   FLOAT      ZoneBoundHeading;
/*0x349c*/   BYTE       Unknown0x349c[0x50];
/*0x34ec*/   DWORD      ArmorType[0x16];
/*0x3544*/   BYTE       Unknown0x3544[0x160];
/*0x36a4*/   AALIST     AAList[AA_CHAR_MAX_REAL];
/*0x44b4*/   DWORD      BodyColor[0x9];
/*0x44d8*/   BYTE       Unknown0x44d8[0x2000];
/*0x64d8*/   DWORD      CombatAbilities[NUM_COMBAT_ABILITIES];
/*0x67f8*/   BYTE       Unknown0x67f8[0x34];
/*0x682c*/   DWORD      CombatAbilityTimes[0x14];
/*0x687c*/   BYTE       Unknown0x687c[0x1ed8];
/*0x8754*/   DWORD      Deity;
/*0x8758*/   BYTE       Unknown0x8758[0x4];
/*0x875c*/   DWORD      Drunkenness;
/*0x8760*/   BYTE       Unknown0x8760[0x10];
/*0x8770*/   DWORD      AAPoints;
/*0x8774*/   BYTE       Unknown0x8774[0x100c];
/*0x9780*/   DWORD      AAPointsSpent;
/*0x9784*/   BYTE       Unknown0x9784[0x3c];
/*0x97c0*/
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

// 20110915 - ieatacid  0x9d8
typedef struct _FELLOWSHIPINFO {
/*0x000*/  DWORD  Unknown0x0;        // always 1?
/*0x004*/  DWORD  FellowshipID;
/*0x008*/  CHAR   Leader[0x40];
/*0x048*/  CHAR   MotD[0x400];
/*0x448*/  DWORD  Members;
/*0x44c*/  struct _FELLOWSHIPMEMBER  FellowshipMember[0xc];
/*0x83c*/  DWORD  Unknown0x83c;      // timestamp for something
/*0x840*/  BYTE   Unknown0x840[0x198];
/*0x9d8*/
} FELLOWSHIPINFO, *PFELLOWSHIPINFO;

// offsets are relative to their position in _LAUNCHSPELLDATA
typedef struct _ITEMLOCATION {
/*0x0c*/ DWORD    a;
/*0x10*/ DWORD    InvSlot;
/*0x14*/ DWORD    BagSlot;
/*0x18*/ DWORD    d;
/*0x1c*/
} ITEMLOCATION, *PITEMLOCATION;

typedef struct _LAUNCHSPELLDATA {
/*0x00*/ DWORD    SpellETA;           //Calculated TimeStamp when current spell being cast will land. 0 while not casting.
/*0x04*/ DWORD    SpellID;            // -1 = not casting a spell
/*0x08*/ BYTE     SpellSlot;          // 0xFF if not casting, otherwise it's the spell gem number (0 - 8)
/*0x09*/ BYTE     Padding0x9[0x3];
/*0x0c*/ struct   _ITEMLOCATION ItemLocation;
/*0x1c*/ DWORD    ItemID;
/*0x20*/ FLOAT    CastingY;
/*0x24*/ FLOAT    CastingX;
/*0x28*/ BYTE     Unknown0x28[0x4];
/*0x2c*/ DWORD    TargetID;
/*0x30*/ BYTE     Unknown0x30[0x14];
/*0x44*/ DWORD    Unknown0x44;
/*0x48*/ DWORD    Unknown0x48;
/*0x4c*/ DWORD    Unknown0x4c;
/*0x50*/
} LAUNCHSPELLDATA, *PLAUNCHSPELLDATA;

// actual size: 0x1ee4 20120815 - ieatacid
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
/*0x015c*/ BYTE     Unknown0x15c[0x30];
/*0x018c*/ LONG     HPCurrent;
/*0x0190*/ BYTE     Unknown0x190[0xc];
/*0x019c*/ DWORD    Deity;
/*0x01a0*/ DWORD    HPMax;
/*0x01a4*/ BYTE     Unknown0x1a4[0x4];
/*0x01a8*/ DWORD    ManaMax;
/*0x01ac*/ BYTE     Unknown0x1ac[0x8];
/*0x01b4*/ DWORD    AFK;
/*0x01b8*/ BYTE     Unknown0x1b8[0x4];
/*0x01bc*/ DWORD    EnduranceMax;
/*0x01c0*/ BYTE     Unknown0x1c0[0x10];
/*0x01d0*/ BYTE     HideMode;
/*0x01d1*/ BYTE     Unknown0x1d1[0x3];
/*0x01d4*/ BYTE     Light;
/*0x01d5*/ BYTE     Unknown0x1d5[0x7];
/*0x01dc*/ DWORD    RespawnTimer;           // TimeStamp of when RespawnWnd will close - 0 when you're alive
/*0x01e0*/ BYTE     Unknown0x1e0[0xc];
/*0x01ec*/ DWORD    PetID;
/*0x01f0*/ BYTE     Unknown0x1f0[0x10];
/*0x0200*/ BYTE     Holding;
/*0x0204*/ BYTE     Unknown0x204[0x7];
/*0x0208*/ FLOAT    GetMeleeRangeVar1;      // used by GetMeleeRange
/*0x020c*/ BYTE     Unknown0x20c[0x4];
/*0x0210*/ BYTE     Sneak;
/*0x0211*/ BYTE     Unknown0x211[0x3];
/*0x0214*/ FLOAT    RunSpeed;
/*0x0218*/ BYTE     Unknown0x218[0x8];
/*0x0220*/ DWORD    Anon;
/*0x0224*/ BYTE     Unknown0x224[0x5];
/*0x0229*/ BYTE     StandState;
/*0x022a*/ BYTE     Unknown0x22a;
/*0x022b*/ BYTE     Linkdead;
/*0x022c*/ BYTE     Unknown0x22c[0x14];
/*0x0240*/ DWORD    Buyer;
/*0x0244*/ BYTE     Unknown0x244[0x12];
/*0x0256*/ BYTE     PvPFlag;
/*0x0257*/ BYTE     Mercenary;
/*0x0258*/ BYTE     Unknown0x258[0x8];
/*0x0260*/ DWORD    AARank;
/*0x0264*/ WORD     Zone;
/*0x0266*/ WORD     Instance;
/*0x0268*/ BYTE     Unknown0x268[0x8];
/*0x0270*/ CHAR     Suffix[0x20];
/*0x0290*/ BYTE     Unknown0x290[0x30];
/*0x02c0*/ DWORD    GuildStatus;
/*0x02c4*/ BYTE     Unknown0x2c4[0x10];
/*0x02d4*/ DWORD    GuildID;
/*0x02d8*/ DWORD    Trader;
/*0x02dc*/ BYTE     Unknown0x2dc[0x14];
/*0x02f0*/ BYTE     FishingEvent;
/*0x02f1*/ BYTE     Unknown0x2f1[0x20];
/*0x0311*/ BYTE     LFG;
/*0x0312*/ CHAR     Title[0x20];
/*0x0332*/ BYTE     Unknown0x332[0x12];
/*0x0344*/ DWORD    EnduranceCurrent;
/*0x0348*/ BYTE     Unknown0x348[0x60];
/*0x03a8*/ struct   _LAUNCHSPELLDATA CastingData; // size: 0x50
/*0x03f8*/ BYTE     Unknown0x3f8[0x6];
/*0x03fe*/ BYTE     GM;
/*0x03ff*/ BYTE     Unknown0x3ff[0x85];
/*0x0484*/ DWORD    ManaCurrent;
/*0x0488*/ BYTE     Unknown0x488[0x18];
/*0x04a0*/ DWORD    MasterID;
/*0x04a4*/ BYTE     Unknown0x4a4[0x4];
/*0x04a8*/ DWORD    LastTick;
/*0x04ac*/ BYTE     Unknown0x4ac[0x18];
/*0x04c4*/ DWORD    FishingETA;
/*0x04c8*/ BYTE     Unknown0x4c8[0x34];
/*0x04fc*/ DWORD    InnateETA;              //Calculated TimeStamp when innate skill will be ready (LoH, HT, Bash)
/*0x0500*/ BYTE     Unknown0x500[0x8];
/*0x0508*/ BYTE     Level;
/*0x0509*/ BYTE     Unknown0x509[0x923];
/*0x0e2c*/ struct   _SPAWNINFO *WhoFollowing; // NULL if autofollow off
/*0x0e30*/ int      GroupAssistNPC[1];
/*0x0e34*/ int      RaidAssistNPC[3];
/*0x0e40*/ int      GroupMarkNPC[3];
/*0x0e4c*/ int      RaidMarkNPC[3];
/*0x0e58*/ int      TargetOfTarget;
/*0x0e5c*/ BYTE     Unknown0xe60[0x30];
/*0x0e8c*/ void     *pActorClient;          // start of ActorClient struct
/*0x0e90*/ BYTE     InNonPCRaceIllusion;
/*0x0e91*/ BYTE     Unknown0xe95[0x3];
/*0x0e94*/ BYTE     FaceStyle;
/*0x0e95*/ BYTE     HairColor;
/*0x0e96*/ BYTE     FacialHairColor;
/*0x0e97*/ BYTE     EyeColor1;
/*0x0e98*/ BYTE     EyeColor2;
/*0x0e99*/ BYTE     HairStyle;
/*0x0e9a*/ BYTE     FacialHair;
/*0x0e9b*/ BYTE     Unknown0xe9b;
/*0x0e9c*/ DWORD    Race;
/*0x0ea0*/ BYTE     Class;
/*0x0ea1*/ BYTE     Gender;
/*0x0ea2*/ CHAR     ActorDef[0x40];
/*0x0ee2*/ BYTE     Unknown0xee2[0x2];
/*0x0ee4*/ ARGBCOLOR ArmorColor[0x9];
/*0x0f08*/ BYTE     Unknown0xf08[0x4];
/*0x0f0c*/ DWORD    Heritage;               //drakkin only face setting
/*0x0f10*/ DWORD    Tattoo;                 //drakkin only face setting
/*0x0f14*/ DWORD    Details;                //drakkin only face setting
/*0x0f18*/ struct   _EQUIPMENT Equipment;   // size 0x6c
/*0x0f84*/ BYTE     Unknown0xf84[0x80];     // this is actually a part of _EQUIPMENT  add 0x24?
/*0x1004*/ VOID     *pcactorex;             // ActorInterface*
/*0x1008*/ DWORD    Unknown0x1008;
/*0x100c*/ VOID     *FaceRelatedActorStruct;
/*0x1010*/ BYTE     Unknown0x1010[0x34];         // add 4
/*0x1044*/ FLOAT    GetMeleeRangeVar2;      // used by GetMeleeRange
/*0x1048*/ BYTE     Unknown0x1048[0x60];
/*0x10a8*/ DWORD    Animation;
/*0x10ac*/ BYTE     Unknown0x10ac[0x104];
/*0x11b0*/ FLOAT    WalkSpeed;
/*0x11b4*/ DWORD    HideCorpse;
/*0x11b8*/ BYTE     Unknown0x11b8[0x40];
/*0x11f8*/ BYTE     InvitedToGroup;
/*0x11f9*/ BYTE     Unknown0x11f9[0x3];
/*0x11fc*/ DWORD    GroupMemberTargeted;    // 0xFFFFFFFF if no target, else 1 through 5
/*0x1200*/ BYTE     Unknown0x1200[0x184];
/*0x1384*/ struct   _FELLOWSHIPINFO Fellowship; // size 0x9d8
/*0x1d5c*/ FLOAT    CampfireY;
/*0x1d60*/ FLOAT    CampfireX;
/*0x1d64*/ FLOAT    CampfireZ;
/*0x1d68*/ WORD     CampfireZoneID;         // zone ID where campfire is
/*0x1d6a*/ WORD     InstanceID;
/*0x1d6c*/ DWORD    CampfireTimestamp;      // CampfireTimestamp-FastTime()=time left on campfire
/*0x1d70*/ DWORD    Unknown0x1d70;
/*0x1d74*/ DWORD    Unknown0x1d74;          // campfire type?
/*0x1d78*/ DWORD    Campfire;               // do we have a campfire up?
/*0x1d7c*/ BYTE     Unknown0x1d7c[0x110];
/*0x1e8c*/ void     *vtable2;
/*0x1e90*/ DWORD    Unknown0x1e90;
/*0x1e94*/ struct   _SPAWNINFO *pSpawn;
/*0x1e98*/ DWORD    Levitate;
/*0x1e9c*/ BYTE     Unknown0x1e9c[0x48];
/*0x1ee4*/
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

// actual size 0x80 20101012 - ieatacid
typedef struct _GROUNDITEM {
/*0x00*/ struct _GROUNDITEM *pPrev;
/*0x04*/ struct _GROUNDITEM *pNext;
/*0x08*/ DWORD  ID;
/*0x0c*/ DWORD  DropID;
/*0x10*/ DWORD  Unknown0x10;
/*0x14*/ DWORD  Unknown0x14;
/*0x18*/ PEQSWITCH pSwitch; // (class EQSwitch *)
/*0x1c*/ CHAR   Name[0x20];
/*0x3c*/ BYTE   Unknown0x3c[0x24];
/*0x60*/ FLOAT  Heading;
/*0x64*/ BYTE   Unknown0x64[0xc];
/*0x70*/ FLOAT  Y;
/*0x74*/ FLOAT  X;
/*0x78*/ FLOAT  Z;
/*0x7c*/ BYTE   Unknown0x7c[0x4];
/*0x80*/
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

#define   TOTAL_SPELL_COUNT             0xAFC9      // # of spells allocated in memory (06/27/2012)
#define   TOTAL_ACTUAL_SPELLS           0x1964      // # of ACTUAL spells in game      (9/14/2004) - wrong and unused

// size: 0x9496C 20120316
typedef struct _SPELLMGR {
BYTE            unknown[0x2C180];
struct _SPELL*  Spells[TOTAL_SPELL_COUNT];
} SPELLMGR, *PSPELLMGR;

// actual size: 0x4ed 20120316 - ieatacid
typedef struct _SPELL {
/*0x000*/   FLOAT   Range;
/*0x004*/   FLOAT   AERange;
/*0x008*/   FLOAT   PushBack;
/*0x00c*/   BYTE    Unknown0xc[0x4];
/*0x010*/   DWORD   CastTime;
/*0x014*/   DWORD   FizzleTime;
/*0x018*/   DWORD   RecastTime;
/*0x01c*/   DWORD   DurationType;       //DurationFormula on Lucy
/*0x020*/   DWORD   DurationValue1;
/*0x024*/   BYTE    Unknown0x24[0x4];
/*0x028*/   DWORD   Mana;
/*0x02c*/   LONG    Base[0x0c];         //Base1-Base12
/*0x05c*/   LONG    Base2[0x0c];        //Mostly unused, setting name to Base2 from Lucy for now
/*0x08c*/   LONG    Max[0xc];           //Max1-Max12
/*0x0bc*/   DWORD   ReagentId[0x4];     //ReagentId1-ReagentId4d
/*0x0cc*/   DWORD   ReagentCount[0x4];  //ReagentCount1-ReagentCount4
/*0x0dc*/   BYTE    Unknown0xdc[0x10];
/*0x0ec*/   DWORD   Calc[0x0c];         //Calc1-Calc12
/*0x11c*/   DWORD   Attrib[0xc];       //Attrib1-Attrib12
/*0x14c*/   DWORD   BookIcon;
/*0x150*/   BYTE    Unknown0x150[0x4];
/*0x154*/   DWORD   DescriptionNumber;
/*0x158*/   DWORD   ResistAdj;
/*0x15c*/   BYTE    Unknown0x15c[0x4];
/*0x160*/   DWORD   spaindex;
/*0x164*/   DWORD   SpellAnim;
/*0x168*/   DWORD   SpellIcon;
/*0x16c*/   BYTE    Unknown0x16c[0x8];
/*0x174*/   DWORD   ID;
/*0x178*/   DWORD   Autocast;           //SpellID of spell to instacast on caster when current spell lands on target
/*0x17c*/   DWORD   Unknown144;         //Unknown144 from lucy
/*0x180*/   DWORD   Unknown145;         //Unknown145 from lucy
/*0x184*/   BYTE    Unknown0x184[0x10];
/*0x194*/   DWORD   EnduranceCost;      //CA Endurance Cost
/*0x198*/   DWORD   CARecastTimerID;    //ID of combat timer, i think.
/*0x19c*/   BYTE    Unknown0x19c[0x18];
/*0x1b4*/   DWORD   PvPResistBase;
/*0x1b8*/   BYTE    Unknown0x1b8[0x4];
/*0x1bc*/   DWORD   PvPResistCap;
/*0x1c0*/   BYTE    Unknown0x1c0[0x4];
/*0x1c4*/   DWORD   Unknown183;         //Unknown183 from Lucy
/*0x1c8*/   BYTE    Unknown0x1c8[0x6f];
/*0x237*/   BYTE    DurationWindow;     //0=Long, 1=Short
/*0x238*/   BYTE    Unknown0x238[0x2];
/*0x23a*/   BYTE    Deletable;
/*0x23b*/   BYTE    Unknown0x23b[0x6];
/*0x241*/   BYTE    CanMGB;
/*0x242*/   BYTE    Unknown0x242[0x5];
/*0x247*/   BYTE    Level[0x10];        //per class.
/*0x257*/   BYTE    Unknown0x257[0x13];
/*0x26a*/   BYTE    LightType;
/*0x26b*/   BYTE    SpellType;          //0=detrimental, 1=Beneficial, 2=Beneficial, Group Only
/*0x26c*/   BYTE    Unknown0x26c;
/*0x26d*/   BYTE    Resist;             //0=un 1=mr 2=fr 3=cr 4=pr 5=dr 6=chromatic 7=prismatic 8=physical(skills,etc) 9=corruption
/*0x26e*/   BYTE    TargetType;         //03=Group v1, 04=PB AE, 05=Single, 06=Self, 08=Targeted AE, 0e=Pet, 28=AE PC v2, 29=Group v2
/*0x26f*/   BYTE    FizzleAdj;
/*0x270*/   BYTE    Skill;
/*0x271*/   BYTE    Location;           //01=Outdoors, 02=dungeons, ff=Any
/*0x272*/   BYTE    Environment;
/*0x273*/   BYTE    TimeOfDay;          // 0=any, 1=day only, 2=night only
/*0x274*/   BYTE    CastingAnim;
/*0x275*/   BYTE    Unknown0x275;
/*0x276*/   BYTE    TargetAnim;
/*0x277*/   BYTE    Unknown0x277[0x3];
/*0x27a*/   CHAR    Name[0x40];
/*0x2ba*/   CHAR    Target[0x20];
/*0x2da*/   CHAR    Extra[0x20];        //This is 'Extra' from Lucy (portal shortnames etc)
/*0x2fa*/   CHAR    Unknown0x2fa[0x60];
/*0x35a*/   CHAR    Unknown0x35a[0x60];
/*0x3ba*/   CHAR    CastOnYou[0x60];
/*0x41a*/   CHAR    CastOnAnother[0x60];
/*0x47a*/   CHAR    WearOff[0x60];
/*0x4da*/   BYTE    Unknown0x4da[0x4];
/*0x4de*/   BYTE    Uninterruptable;    //00=Interruptable, 01=Uninterruptable 
/*0x4df*/   BYTE    Unknown0x4df[0xe];
/*0x4ed*/
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
/*0x020*/  bool   Activated;
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

//actual size 0x3a8 11-15-11  ieatacid
typedef struct _GUILDMEMBER {
/*0x000*/ struct  _GUILDMEMBER *pNext;
/*0x004*/ BYTE    Online;
/*0x005*/ BYTE    Unknown0x5[0x3];
/*0x008*/ WORD    ZoneID;
/*0x00a*/ WORD    Instance;
/*0x00c*/ BYTE    Unknown0xc[0x5];
/*0x011*/ CHAR    Name[0x40];
/*0x054*/ DWORD   Level;
/*0x058*/ DWORD   Flags; //1=banker, 2=alt
/*0x05c*/ DWORD   Class;
/*0x060*/ DWORD   Rank; //0=member 1=officer 2=leader

// not updated
#if 0
/*0x060*/ DWORD   LastSeen; //last seen timestamp
/*0x064*/ CHAR    PublicNote[0x100];//0x1a0
/*0x164*/ CHAR    PersonalNote[0x100];
/*0x264*/ DWORD   TributeStatus;
/*0x268*/ DWORD   TributeDonations;
/*0x26c*/ DWORD   LastDonation;//timestamp
/*0x270*/ DWORD   Unknown0x270;
/*0x274*/
#endif
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

// 11-15-11 - ieatacid
typedef struct _GUILDS {
/*0x0000*/ PVOID    pOneEntryVTable;
/*0x0004*/ BYTE     Unknown0x4[0x4];
/*0x0008*/ DWORD    GuildMemberCount;
/*0x000c*/ struct   _GUILDMEMBER *pMember;
/*0x0010*/ BYTE     Unknown0x10[0x69];
/*0x0079*/ CHAR     GuildMotD[0x200];
/*0x0279*/ CHAR     GuildLeader[0x40];
/*0x02b9*/ BYTE     Unknown0x2b9[0x3];
/*0x02bc*/ DWORD    GuildTribute;
/*0x02c0*/ BYTE     Unknown0x2c0[0x8dc6];
/*0x9086*/ CHAR     GuildUrl[0x200];
/*0x9286*/ CHAR     GuildChannelName[0x80];
/*0x9306*/ BYTE     Unknown0x9306[0x1e];
/*0x9324*/ struct _GUILD **GuildList;
/*0x9328*/ DWORD    HashValue;
/* more data */
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

// Size 0xa4    11/15/2011 ieatacid in msg_send_alt_data
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
/*0x28*/ DWORD Unknown0x28;
/*0x2c*/ DWORD *RequiresAbility;
/*0x30*/ DWORD Unknown0x30[3];
/*0x3c*/ DWORD *RequiresAbilityPoints;
/*0x40*/ DWORD Unknown0x40[2];
/*0x48*/ DWORD Type; 
/*0x4c*/ LONG  SpellID;                  // -1 for no Spell
/*0x50*/ DWORD Unknown0x50;
/*0x54*/ BYTE  Unknown0x54[0x10]; 
/*0x64*/ DWORD ReuseTimer;               // in seconds
/*0x68*/ DWORD Classes;                  // Classes/2 is the actual value we want.
/*0x6c*/ DWORD MaxRank;                         //If you have not spent points in this 
union {                                         //If you have not spent points in this 
/*0x70*/ DWORD PointsSpent;                //ability, then its PointsToBeSpent (or 
/*0x70*/ DWORD PointsToBeSpent;            //'Cost', in other words).
}; 
/*0x74*/ BYTE  Unknown0x74[0x30];
/*0xa4*/
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

typedef struct _MERCSTANCEDATA {
DWORD nStance;
DWORD nDbStance;
} MERCSTANCEDATA, *PMERCSTANCEDATA;

typedef struct _MERCENARYINFO {
/*0x000*/ BYTE Unknown0x0[0x10c];
/*0x10c*/ DWORD HaveMerc;
/*0x110*/ DWORD MercState; // 1 = suspended, 5 = active
/*0x114*/ BYTE  Unknown0x114[0x30];
/*0x144*/ DWORD ActiveStance;
/*0x148*/ BYTE  Unknown0x148[0xf0];
/*0x238*/ DWORD NumStances;
/*0x23c*/ _MERCSTANCEDATA **pMercStanceData;
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

#define XPAC_FLAG_HoT       0x10000

#define EQ_BEGIN_ZONE                   0x1055  // CEverQuest__SavePCForce          8-15-2012
#define EQ_END_ZONE                     0x7FB   // CEverQuest__DoMainLoop+B2F       8-15-2012
#define EQ_LoadingS__ArraySize          0x5b    // EQ_LoadingS__SetProgressBar+8C  12-08-2010
};
using namespace EQData;
