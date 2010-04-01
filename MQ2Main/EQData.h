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
	Unknown=							0,
	Warrior=							1,
	Cleric=								2,
	Paladin=							3,
	Ranger=								4,
	Shadowknight=						5,
	Druid=								6,
	Monk=								7,
	Bard=								8,
	Rogue=								9,
	Shaman=								10,
	Necromancer=						11,
	Wizard=								12,
	Mage=								13,
	Enchanter=							14,
	Beastlord=							15,
	Berserker=							16,
	TotalClasses=						16,
};
// class 20 through 35 are the NPC GMs (same class order as above)
// class 41   Merchant
// class 60   LDoN Recruiter
// class 61   LDoN Merchant
// class 63   Tribute Master

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
	{0,0,0,0,0,0,0,0,"",""},//unk
	{0,0,0,0,0,0,0,13,"Warrior","war"},//war
	{1,1,0,0,0,1,0,2,"Cleric","clr"},//clr
	{1,0,0,0,0,1,0,8,"Paladin","pal"},//pal
	{1,0,0,1,0,0,0,9,"Ranger","rng"},//rng
	{1,0,0,0,1,0,0,11,"Shadowknight","shd"},//shd
	{1,1,0,1,0,0,0,3,"Druid","dru"},//dru
	{0,0,0,0,0,0,0,6,"Monk","mnk"},//mnk
	{1,0,0,0,0,0,0,0,"Bard","brd"},//brd
	{0,0,0,0,0,0,0,10,"Rogue","rog"},//rog
	{1,1,1,0,0,0,1,12,"Shaman","shm"},//shm
	{1,1,1,0,1,0,0,7,"Necromancer","nec"},//nec
	{1,1,0,0,0,0,0,14,"Wizard","wiz"},//wiz
	{1,1,1,0,0,0,0,5,"Mage","mag"},//mag
	{1,1,0,0,0,0,0,4,"Enchanter","enc"},//enc
	{1,0,1,0,0,0,1,1,"Beastlord","bst"},//bst
	{0,0,0,0,0,0,0,15,"Berserker","ber"},//ber
};

enum GroupAbilityLevels { 
   G_MarkNPC=							0,			//0-3 
   G_NPCHealth=							1,			//0-1 
   G_DelegateMA=						3,			//0-1 
   G_DelegateMarkNPC=					4,			//0-1 
   G_InspectBuffs=						6,			//0-2 
   G_SpellAwareness=					8,			//0-1 
   G_OffenseEnhancement=				9,			//0-5 
   G_ManaEnhancement=					10,			//0-3 
   G_HealthEnhancement=					11,			//0-3 
   G_HealthRegen=						12,         //0-3 
   G_FindPathtoPC=						13,			//0-1 
   G_HealthofTargetsTarget=				14,			//0-1 
}; 

enum RaidAbilityLevels { 
   R_MarkNPC=							0,			//0-3 
   R_NPCHealth=							1,			//0-1 
   R_DelegateMA=						3,			//0-3 
   R_DelegateMarkNPC=					4,			//0-4 
   R_SpellAwareness=					7,			//0-1 
   R_OffenseEnhancement=				8,			//0-5 
   R_ManaEnhancement=					9,			//0-3 
   R_HealthEnhancement=					10,			//0-3 
   R_HealthRegen=						11,         //0-3 
   R_FindPathtoPC=						12,			//0-1 
   R_HealthofTargetsTarget=				13,			//0-1 
}; 

#define BI_TARGETABLE					1
#define BI_TRIGGER						2 
#define BI_TRAP							4
#define BI_TIMER						8

typedef struct _BodyInfo
{
	PCHAR Name;
	DWORD Flags;
} BODYINFO, *PBODYINFO;

#define SPAWN_PLAYER                    0
#define SPAWN_NPC                       1
#define SPAWN_CORPSE                    2
//#define SPAWN_ANY                     3
//#define SPAWN_PET                     4

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

#define ITEMITEMTYPE_FOOD				0x0e 
#define ITEMITEMTYPE_WATER				0x0f 
#define ITEMITEMTYPE_ALCOHOL			0x26 
#define ITEMITEMTYPE_POISON				0x2a 
#define ITEMITEMTYPE_AUGUMENT			0x36 

#define ITEMEFFECTTYPE_COMBAT			0x00 
#define ITEMEFFECTTYPE_INVENTORY1		0x01 // Bards need to stop sing to cast 
#define ITEMEFFECTTYPE_WORN				0x02 
#define ITEMEFFECTTYPE_INVENTORY2		0x03 
#define ITEMEFFECTTYPE_MUSTEQUIP		0x04 // Bards need to stop sing to cast 
#define ITEMEFFECTTYPE_INVENTORY3		0x05 

#define SKILLMINDAMAGEMOD_BASH			0x00 
#define SKILLMINDAMAGEMOD_BACKSTAB		0x01 
#define SKILLMINDAMAGEMOD_DRAGONPUNCH	0x02 
#define SKILLMINDAMAGEMOD_EAGLESTRIKE	0x03 
#define SKILLMINDAMAGEMOD_FLYINGKICK	0x04 
#define SKILLMINDAMAGEMOD_KICK			0x05 
#define SKILLMINDAMAGEMOD_ROUNDKICK		0x06 
#define SKILLMINDAMAGEMOD_TIGERCLAW		0x07 
#define SKILLMINDAMAGEMOD_FRENZY		0x08 

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

#define DEITY_Bertoxxulous				201
#define DEITY_BrellSerilis				202
#define DEITY_CazicThule				203
#define DEITY_ErollisiMarr				204
#define DEITY_Bristlebane				205
#define DEITY_Innoruuk					206
#define DEITY_Karana					207
#define DEITY_MithanielMarr				208
#define DEITY_Prexus					209
#define DEITY_Quellious					210
#define DEITY_RallosZek					211
#define DEITY_RodcetNife				212
#define DEITY_SolusekRo					213
#define DEITY_TheTribunal				214
#define DEITY_Tunare					215
#define DEITY_Veeshan					216

#define ITEMTYPE_NORMAL					0
#define ITEMTYPE_PACK					1
#define ITEMTYPE_BOOK					2

#define COMP_NONE						0
#define COMP_EQ							1
#define COMP_NE							2
#define COMP_GT							3
#define COMP_LT							4
#define COMP_GE							5
#define COMP_LE							6
#define COMP_CONT						7
#define COMP_NOTCONT					8
#define COMP_BITAND						9
#define COMP_BITOR						10

#define COMP_TYPE_STRING				0
#define COMP_TYPE_NUMERIC				1
#define COMP_TYPE_BIT					2

#define CMD_MQ							1
#define CMD_EQ							2		

#define LASTFIND_NOTFOUND				96
#define LASTFIND_PRIMARY				97

#define EVENT_CHAT						0
#define EVENT_TIMER						1
#define EVENT_CUSTOM					2
#define EVENT_EVAL						3
#define EVENT_EXEC						4
#define EVENT_PULSE						5
#define EVENT_SHUTDOWN					6
#define EVENT_BREAK						7
#define NUM_EVENTS						8

#define CHAT_SAY						1
#define CHAT_TELL						2
#define CHAT_OOC						4
#define CHAT_SHOUT						8
#define CHAT_AUC						16
#define CHAT_GUILD						32
#define CHAT_GROUP						64
#define CHAT_CHAT						128
#define CHATEVENT(x)					(gEventChat & x)

#define FILTERSKILL_ALL					0
#define FILTERSKILL_INCREASE			1
#define FILTERSKILL_NONE				2

#define FILTERMACRO_ALL					0
#define FILTERMACRO_ENHANCED			1
#define FILTERMACRO_NONE				2


#define MAX_STRING						2048
#define MAX_VARNAME						64

// Defines for CXWnd WindowStyle
#define CWS_VSCROLL						0x1
#define CWS_HSCROLL						0x2
#define CWS_TITLE						0x4
#define CWS_CLOSE						0x8
//#define CWS_UNKNOWN					0x10
#define CWS_MINIMIZE					0x20
#define CWS_BORDER						0x40
//#define CWS_UNKNOWN					0x80
//#define CWS_UNKNOWN					0x100
#define CWS_RESIZEALL					0x200
#define CWS_TRANSPARENT					0x400
//#define CWS_UNKNOWN					0x800
#define CWS_NOMOVE						0x8000
#define CWS_UNKNOWN						0x40000
#define ToggleBit(field,bit)			field^=bit;
#define BitOn(field,bit)				field|=bit;
#define BitOff(field,bit)				field&=~bit;
// End CXWnd WindowStyle Defines

enum MOUSE_DATA_TYPES {
   MD_Unknown = -1,
   MD_Button0Click=0,
   MD_Button1Click,
   MD_Button0,
   MD_Button1
};

#define nEQMappableCommands				0x10b


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

// size is 0xc 01-27-2005
typedef struct _ITEMSPELLS { 
/*0x00*/ DWORD SpellID; 
/*0x04*/ BYTE RequiredLevel; 
/*0x05*/ BYTE EffectType; 
/*0x06*/ BYTE Unknown[2]; 
/*0x08*/ DWORD Unknown0x08;
/*0x0c*/ DWORD Unknown0x0c;
} ITEMSPELLS, *PITEMSPELLS; 

typedef struct _ITEMINFO {
/*0x000*/ CHAR Name[ITEM_NAME_LEN];
/*0x040*/ CHAR LoreName[LORE_NAME_LEN];
/*0x090*/ CHAR IDFile[0x20];
/*0x0b0*/ DWORD ItemNumber;
/*0x0b4*/ DWORD EquipSlots;
/*0x0b8*/ DWORD Cost;
/*0x0bc*/ DWORD IconNumber;
/*0x0c0*/ BYTE Unknown0x0c0[0x11];
/*0x0d1*/ BYTE Weight;
/*0x0d2*/ BYTE NoRent;
/*0x0d3*/ BYTE NoDrop; // 0=can drop (and place in bank), 1=no drop, (2=no bank)
/*0x0d4*/ BYTE Size;
/*0x0d5*/ BYTE Type;
/*0x0d6*/ BYTE TradeSkills;
/*0x0d7*/ BYTE Unknown0x0d7;
/*0x0d8*/ BYTE Lore;
/*0x0d9*/ BYTE PendingLore;
/*0x0da*/ BYTE Artifact;
/*0x0db*/ BYTE Summoned;
/*0x0dc*/ BYTE Unknown0x0dc[0x3];
/*0x0df*/ BYTE SvCold;
/*0x0e0*/ BYTE SvFire;
/*0x0e1*/ BYTE SvMagic;
/*0x0e2*/ BYTE SvDisease;
/*0x0e3*/ BYTE SvPoison;
/*0x0e4*/ BYTE STR;
/*0x0e5*/ BYTE STA;
/*0x0e6*/ BYTE AGI;
/*0x0e7*/ BYTE DEX;
/*0x0e8*/ BYTE CHA;
/*0x0e9*/ BYTE INT;
/*0x0ea*/ BYTE WIS;
/*0x0eb*/ BYTE Skill;  //is this right?
/*0x0ec*/ DWORD HP;
/*0x0f0*/ DWORD Mana;
/*0x0f4*/ DWORD AC;
/*0x0f8*/ DWORD Unknown0x0f8;   // New value added with DoN expansion
/*0x0fc*/ DWORD SkillModValue;
/*0x100*/ DWORD BaneDMGRace;
/*0x104*/ DWORD BaneDMGBodyType;
/*0x108*/ DWORD RequiredLevel;
/*0x10c*/ DWORD InstrumentType;
/*0x110*/ DWORD InstrumentMod;
/*0x114*/ DWORD Classes;
/*0x118*/ DWORD Races;
/*0x11c*/ DWORD Diety;
/*0x120*/ BYTE Unknown0x11c[0x4];
/*0x124*/ DWORD Unknown0x120;
/*0x128*/ BYTE SkillModType;
/*0x129*/ BYTE BaneDMGBodyTypeValue;
/*0x12a*/ BYTE BaneDMGRaceValue;
/*0x12b*/ BYTE Magic;
/*0x12c*/ BYTE Light;
/*0x12d*/ BYTE Delay;
/*0x12e*/ BYTE RecommendedLevel;
/*0x12f*/ BYTE RecommendedSkill;
/*0x130*/ BYTE DmgBonusType;
/*0x131*/ BYTE DmgBonusVal;
/*0x132*/ BYTE Range;
/*0x133*/ BYTE Damage;
/*0x134*/ BYTE ItemType;
/*0x135*/ BYTE Material;
/*0x136*/ BYTE Unknown0x132;
/*0x137*/ BYTE Unknown0x133;
/*0x138*/ DWORD AugSlot1;
/*0x13c*/ DWORD AugSlot1_Unkown;
/*0x140*/ DWORD AugSlot2;
/*0x144*/ DWORD AugSlot2_Unkown;
/*0x148*/ DWORD AugSlot3;
/*0x14c*/ DWORD AugSlot3_Unkown;
/*0x150*/ DWORD AugSlot4;
/*0x154*/ DWORD AugSlot4_Unkown;
/*0x158*/ DWORD AugSlot5;
/*0x15c*/ DWORD AugSlot5_Unkown;
/*0x160*/ DWORD AugType;
/*0x164*/ DWORD AugRestrictions;
/*0x168*/ DWORD LDTheme;
/*0x16c*/ DWORD LDCost;
/*0x170*/ DWORD LDType;
/*0x174*/ BYTE Unknown0x15c[4];
/*0x178*/ DWORD FactionModType[0x4];
/*0x188*/ DWORD FactionModValue[0x4];
/*0x198*/ BYTE CharmFile[0x20];
/*0x1b8*/ FLOAT QuestValue;
/*0x1bc*/ struct _ITEMSPELLS Clicky;
/*0x1cc*/ struct _ITEMSPELLS Proc;
/*0x1dc*/ struct _ITEMSPELLS Worn;
/*0x1ec*/ struct _ITEMSPELLS Focus;
/*0x1fc*/ struct _ITEMSPELLS Scroll;
/*0x20c*/ DWORD Unknown0x1e0;
/*0x210*/ DWORD Unknown0x1e4;
/*0x214*/ DWORD ProcRate;
/*0x218*/ DWORD CombatEffects;
/*0x21c*/ DWORD Shielding;
/*0x220*/ DWORD StunResist;
/*0x224*/ DWORD DoTShielding;
/*0x228*/ DWORD StrikeThrough;
/*0x22c*/ DWORD DmgBonusSkill; // SkillMinDamageMod;
/*0x230*/ DWORD DmgBonusValue; // MinDamageMod;
/*0x234*/ DWORD SpellShield;
/*0x238*/ DWORD Avoidance;
/*0x23c*/ DWORD Accuracy;
/*0x240*/ DWORD CharmFileID;
/*0x244*/ DWORD CastTime;
union{
/*0x248*/ DWORD MaxCharges; // Also has something to do with item stacking
/*0x248*/ DWORD Stackable;
};
/*0x24c*/ BYTE BookType; // 0=note, !0=book
/*0x24d*/ BYTE BookLang;
/*0x24e*/ CHAR BookFile[0x1e];
/*0x26c*/ BYTE Combine;
/*0x26d*/ BYTE Slots;
/*0x26e*/ BYTE SizeCapacity;
/*0x26f*/ BYTE WeightReduction;
/*0x270*/ DWORD Favor; // Tribute Value
/*0x274*/ DWORD GuildFavor;
/*0x278*/ DWORD Unknown0x24c;
/*0x27c*/ DWORD Endurance;
/*0x280*/ DWORD Attack;     
/*0x284*/ DWORD HPRegen;
/*0x28c*/ DWORD ManaRegen;
/*0x290*/ DWORD Haste;
/*0x294*/ DWORD DamShield;
/*0x298*/ DWORD Recast;
/*0x29c*/ DWORD TimerID;
/*0x2a0*/ DWORD SolventNeeded; //ID# of Solvent (Augs only)
/*0x2a4*/ DWORD Unknown0x274;
/*0x2a8*/ DWORD Unknown0x278;
/*0x2ac*/ DWORD Attuneable;
/*0x2b0*/ BYTE Unknown0x280[0x14];
/*0x2c4*/
} ITEMINFO, *PITEMINFO;

// 9-17-05 Size 0xa8
typedef struct _CONTENTS {
/*0x00*/  BYTE    Unknown0x0[0x1c];
/*0x1c*/  struct _ITEMINFO *Item;
   union {
/*0x20*/  struct _CONTENTS *Contents[0x0a]; //addresses to whats inside the bag if its a bag
/*0x20*/  struct _ITEMINFO *Augments[0x0a]; //Only 1-5 are actually used (for now)
   };
/*0x48*/  DWORD   StackCount;
/*0x5c*/  DWORD   ItemSlot;// slotid for Player Items
/*0x4c*/  BYTE    Unknown0x4c[0x8];
/*0x58*/  DWORD   Charges;
/*0x5C*/  BYTE    Unknown0x5c[0x24];
/*0x80*/  DWORD   ItemSlot2;// slotid for Merchant Items
/*0x84*/  DWORD   Unknown0x88;
/*0x88*/  DWORD   Price; //price a player vendor set the item at
/*0x8c*/  DWORD   Open;
/*0x90*/  BYTE    Unknown0x94[0x14];
/*0xa4*/   
} CONTENTS, *PCONTENTS;

// 5-11-2005 Amadeus
// Size 0x14
typedef struct _SPELLBUFF {
/*0x00*/    BYTE      Unknown0x00;
/*0x01*/    BYTE      Level;
/*0x02*/    CHAR      Modifier; // bard song modifier, divide by 10 to get 2.8 etc
/*0x03*/    CHAR      DamageShield;  // maybe.. I've noticed this is -1 on a lot of ds's.
/*0x04*/    LONG      SpellID;// -1 or 0 for no spell..
/*0x08*/    DWORD     Duration;
/*0x0c*/    DWORD     DamageAbsorbRemaining;  // Melee or Spellshield type
/*0x10*/    DWORD     Unknown0x10;
/*0x14*/
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

#define NUM_ALT_ABILITIES_ARRAY   0x1F7 
#define NUM_ALT_ABILITIES   1500            // GetAltAbility require an index
                                            // which is really a hash table 
                                            // index.  the index is divided
                                            // with 0x1f7 and the remainder
                                            // is used the hash table slot.
                                            // the slot is walked to find the
                                            // entry corresponding to the 
                                            // original index (before the
                                            // divide

//these two will merge when i get a chance
#define AA_CHAR_MAX         0xF5
#define AA_CHAR_MAX_REAL    0xF0

typedef struct _AALIST { 
/*0x0*/   DWORD		AAIndex;
/*0x4*/   DWORD		PointsSpent;
} AALIST, *PAALIST;

#define      NUM_BANK_SLOTS         0x12
#define      NUM_BOOK_SLOTS         0x200
#define      NUM_COMBAT_ABILITIES   0x64
#define ExactLocation		 0

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
/* 0x0010 */    void   *Unknown0x10[0x10];
/* 0x0060 */
} CI2_INFO, *PCI2_INFO;

typedef struct _CHARINFO {
/* 0x0000 */   void      *vtable1;
/* 0x0004 */   void      *punknown;
/* 0x0008 */   struct     _CI_INFO* charinfo_info;
/* 0x000c */   BYTE       Unknown0xc[0xce4];
/* 0x0cf0 */   struct     _CONTENTS*   Bank[NUM_BANK_SLOTS];
/* 0x0d38 */   BYTE       unknown0xd38[0xd4];
/* 0x0e0c */   DWORD      GuildID;
/* 0x0e10 */   BYTE       Unknown0xe10[0x18];
/* 0x0e28 */   DWORD      AAExp;
/* 0x0e2c */   BYTE       Unknown0xe2c;
/* 0x0e2d */   BYTE       PercentEXPtoAA;
/* 0x0e2e */   BYTE       Unknown0xe2e[0x4a];
/* 0x0e78 */   DWORD      CareerFavor;
/* 0x0e7c */   DWORD      Unknown0xe7c;
/* 0x0e80 */   DWORD      CurrFavor;
/* 0x0e84 */   BYTE       Unknown0xe84[0xc];
/* 0x0e90 */   DOUBLE     GroupLeadershipExp;
/* 0x0e98 */   DOUBLE     RaidLeadershipExp;
/* 0x0ea0 */   DWORD      GroupLeadershipPoints;
/* 0x0ea4 */   DWORD      RaidLeadershipPoints;
/* 0x0ea8 */   BYTE       Unknown0xea8[0x708];
/* 0x15b0 */   CHAR       GroupMember[0x6][0x40];
/* 0x1730 */   CHAR       GroupLeader[0x40];
/* 0x1770 */   BYTE       Unknown0x1770[0x2a0];
/* 0x1a10 */   DWORD      Exp;
/* 0x1a14 */   BYTE       Unknown0x1a14[0xa864];
/* 0xc278 */   BYTE       Unknown0xc278[0x8];
/* 0xc280 */   void      *vtable2;
/* 0xc284 */   struct     _EQC_INFO* eqc_info;
/* 0xc288 */   struct     _SPAWNINFO*  pSpawn;
/* 0xc28c */   DWORD      Unknown0xc284;
/* 0xc290 */   DWORD      STR;
/* 0xc294 */   DWORD      STA;
/* 0xc298 */   DWORD      CHA;
/* 0xc29c */   DWORD      DEX;
/* 0xc2a0 */   DWORD      INT;
/* 0xc2a4 */   DWORD      AGI;
/* 0xc2a8 */   DWORD      WIS;
/* 0xc2ac */   DWORD      AC;
/* 0xc2b0 */   DWORD      SaveMagic;
/* 0xc2b4 */   DWORD      SaveCold;
/* 0xc2b8 */   DWORD      SaveFire;
/* 0xc2bc */   DWORD      SavePoison;
/* 0xc2c0 */   DWORD      SaveDisease;
/* 0xc2c4 */   DWORD      Unknown0xc2bc;
/* 0xc2c8 */   DWORD      CurrWeight;
/* 0xc2cc */   DWORD      Unknown0xc2c4;
/* 0xc2d0 */   DWORD      HPBonus;
/* 0xc2d4 */   DWORD      ManaBonus;
/* 0xc2d8 */   DWORD      EnduranceBonus;
/* 0xc2dc */   DWORD      CombatEffectsBonus;
/* 0xc2e0 */   DWORD      ShieldingBonus;
/* 0xc2e4 */   DWORD      SpellShieldBonus;
/* 0xc2e8 */   DWORD      AvoidanceBonus;
/* 0xc2ec */   DWORD      AccuracyBonus;
/* 0xc2f0 */   DWORD      StunResistBonus;
/* 0xc2f4 */   DWORD      StrikeThroughBonus;
/* 0xc2f8 */   DWORD      SkillMinDamageModBonus[0x9];
/* 0xc31c */   DWORD      Unknown0xc314;
/* 0xc320 */   DWORD      DoTShieldBonus;
/* 0xc324 */   DWORD      AttackBonus;
/* 0xc328 */   DWORD      HPRegenBonus;
/* 0xc32c */   DWORD      ManaRegenBonus;
/* 0xc330 */   DWORD      Unknown0xc328;
/* 0xc334 */   DWORD      DamageShieldBonus;
/* 0xc338 */   DWORD      AttackSpeed;
/* 0xc33c */   BYTE       Unknown0xc330[0x1c];
/* 0xc358 */   _CONTENTS  *ActiveGuildTribute[0xc];
/* 0xc388 */   struct     _CI2_INFO* pCI2;
/* 0xc38c */   DWORD      Unknown0xc38c;
/* 0xc390 */   BYTE       languages[0x20];
/* 0xc3b0 */   BYTE       Unknown0xc3b0[0x10];
/* 0xc3c0 */   CHAR       Name[0x40];
/* 0xc400 */   CHAR       Lastname[0x20];
/* 0xc420 */   BYTE       Unknown0xc420[0x60];
/* 0xc480 */   DWORD      Stunned;
/* 0xc484 */   WORD       zoneId;
/* 0xc486 */   WORD       instance;
/* 0xc488 */   DWORD      standstate;
/* 0xc48c */   BYTE       Unknown0xc489[0x24];
/* 0xc4b0 */   DWORD      BankSharedPlat;
/* 0xc4b4 */   DWORD      BankSharedGold;
/* 0xc4b8 */   DWORD      BankSharedSilver;
/* 0xc4bc */   DWORD      BankSharedCopper;
/* 0xc4c0 */   DWORD      BankPlat;
/* 0xc4c4 */   DWORD      BankGold;
/* 0xc4c8 */   DWORD      BankSilver;
/* 0xc4cc */   DWORD      BankCopper;
/* 0xc4d0 */
} CHARINFO, *PCHARINFO;


typedef struct  _CHARINFO2 {
/* 0x0000 */   BYTE       Unknown0x0[0x10];
union {
/* 0x0010 */   struct     _INVENTORY   Inventory;
/* 0x0010 */   struct     _CONTENTS*   InventoryArray[0x1e];
};
/* 0x0088 */   struct     _CONTENTS*   Cursor;
/* 0x008c */   BYTE       Unknown0x8c[0x14];
/* 0x00a0 */   struct     _SPELLBUFF   Buff[0x19];
/* 0x0294 */   struct     _SPELLBUFF   ShortBuff[0x23];
/* 0x0550 */   BYTE       Unknown0x550[0x1e0];
/* 0x0730 */   DWORD      SpellBook[NUM_BOOK_SLOTS];
/* 0x0f30 */   DWORD      MemorizedSpells[0x10];
/* 0x0f70 */   DWORD      Skill[0x64];
/* 0x1100 */   BYTE       Unknown0x1100[0x94];
/* 0x1194 */   DWORD      Gender;
/* 0x1198 */   DWORD      Race;
/* 0x119c */   DWORD      Class;
/* 0x11a0 */   DWORD      Unknown0x11a0;
/* 0x11a4 */   DWORD      Level;
/* 0x11a8 */   DWORD      Mana;
/* 0x11ac */   DWORD      Endurance;
/* 0x11b0 */   DWORD      BaseHP;
/* 0x11b4 */   DWORD      BaseSTR;
/* 0x11b8 */   DWORD      BaseSTA;
/* 0x11bc */   DWORD      BaseCHA;
/* 0x11c0 */   DWORD      BaseDEX;
/* 0x11c4 */   DWORD      BaseINT;
/* 0x11c8 */   DWORD      BaseAGI;
/* 0x11cc */   DWORD      BaseWIS;
/* 0x11d0 */   DWORD      Unknown0x11d0;
/* 0x11d4 */   DWORD      Plat;
/* 0x11d8 */   DWORD      Gold;
/* 0x11dc */   DWORD      Silver;
/* 0x11e0 */   DWORD      Copper;
/* 0x11e4 */   DWORD      CursorPlat;
/* 0x11e8 */   DWORD      CursorGold;
/* 0x11ec */   DWORD      CursorSilver;
/* 0x11f0 */   DWORD      CursorCopper;
/* 0x11f4 */   BYTE       Unknown0x11f4[0x24];
/* 0x1218 */   DWORD      thirstlevel;
/* 0x121c */   DWORD      hungerlevel;
/* 0x1220 */   BYTE       Unknown0x1220[0x6c];
/* 0x128c */   DWORD      ZoneBoundID;
/* 0x1290 */   FLOAT      ZoneBoundX;
/* 0x1294 */   FLOAT      ZoneBoundY;
/* 0x1298 */   FLOAT      ZoneBoundZ;
/* 0x129c */   FLOAT      ZoneBoundHeading;
/* 0x12a0 */   BYTE       Unknown0x12a0[0xa8];
/* 0x1348 */   AALIST     AAList[AA_CHAR_MAX_REAL];
/* 0x1ac8 */   BYTE       Unknown0x1ac8[0x3aec-0x1ac8];
/* 0x3aec */   DWORD      CombatAbilities[NUM_COMBAT_ABILITIES];
/* 0x3c7c */   DWORD      Unknown0x3c7c[0xa];
/* 0x3ca4 */   DWORD      CombatAbilityTimes[NUM_COMBAT_ABILITIES];
/* 0x3e34 */   BYTE       Unknown0x3e34[0x1A28];
/* 0x585c */   DWORD      Deity;
/* 0x5860 */   DWORD      Unknown0x5830;
/* 0x5864 */   DWORD      Drunkenness;
/* 0x5868 */   BYTE       Unknown0x5838[8];
/* 0x5870 */   DWORD      AAPoints;
/* 0x5874 */   BYTE       Unknown0x5844[0x5dc8];
/* 0xb63c */   DWORD      AAPointsSpent;
/* 0xb640 */   BYTE       Unknown0xb610[0x1c];
/* 0xb65c */
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

// unknown size
typedef struct _ACTOREX {
/*0x00*/   BYTE Unknown0x00;
} ACTOREX, *PACTOREX;

// actual size 0x10c0  5-11-2005 
typedef struct _ACTORINFO { 
/*0x000*/ struct       _ACTOREX *pActorEx; 
/*0x004*/ DWORD        T3D_POINTLIGHT; 
/*0x008*/ CHAR         ActorDef[0x40]; 
/*0x048*/ FLOAT        Z;            // Z coordinates for the floor where standing 
/*0x04c*/ BYTE         Unknown0x04c[0x4]; 
/*0x050*/ DWORD        TimeStamp;      
/*0x054*/ DWORD        Unknown0x054;  
/*0x058*/ DWORD        LastTick;    
/*0x05c*/ BYTE         Unknown0x05c[0x80-0x5c]; 
/*0x080*/ FLOAT        BobbingAmount; 
/*0x084*/ BYTE         Unknown0x084[0xa0-0x84]; 
/*0x0a0*/ BYTE		   UnderWater;
/*0x0a1*/ BYTE		   Unknown0x0a1[0x0ae-0x0a1];
/*0x0ae*/ BYTE		   FeetWet;
/*0x0af*/ BYTE		   Unknown0x0af[0x0d8-0x0af];
/*0x0d8*/ DWORD        SpellETA;      //Calculated TimeStamp when current spell being cast will land. 0 while not casting. 
/*0x0dc*/ BYTE         Unknown0x0dc[0x44]; 
/*0x120*/ DWORD        FishingETA;      // EQMisc__SteveGetTime 
/*0x124*/ BYTE         Unknown0x124[0x8]; 
/*0x12c*/ VOID         *FaceRelatedActorStruct; 
/*0x130*/ DWORD        Unknown0x0130; 
/*0x134*/ DWORD        Animation; 
/*0x138*/ DWORD        Unknown0x138; 
/*0x13c*/ BYTE         Unknown0x13c[0x16]; 
/*0x152*/ BYTE         FishingEvent;   // 0=not fishing, 1=some event, 2-6=some other event 
/*0x153*/ BYTE         Unknown0x153[0x9]; 
/*0x15c*/ struct       _SPAWNINFO *Mount; //NULL if no mount present 
/*0x160*/ BYTE         Unknown0x0160[0xc]; 
/*0x16c*/ DWORD        PetID;  
/*0x170*/ struct       _SPAWNINFO *pGroupAssistNPC[1]; 
/*0x174*/ struct       _SPAWNINFO *pRaidAssistNPC[3]; 
/*0x180*/ struct       _SPAWNINFO *pGroupMarkNPC[3]; 
/*0x18c*/ struct       _SPAWNINFO *pRaidMarkNPC[3]; 
/*0x198*/ struct       _SPAWNINFO *pTargetOfTarget; 
/*0x19c*/ BYTE         Unknown0x19c[0xd90]; 
/*0xf2c*/ struct       _MODELINFO *Model[0x11];  // 0x11 is the correct number, or are there more? 
/*0xf70*/ BYTE         Unknown0xf70[0x1c]; 
/*0xf8c*/ DWORD        InvitedToGroup; // 1=currently invited to group 
/*0xf90*/ BYTE         Unknown0xf90[0x8]; 
/*0xf98*/ DWORD        CastingSpellID;      // -1 = not casting a spell 
/*0xf9c*/ DWORD        CastingAnimation;  //unsure, FF for not casting, low numbers while casting 
/*0xfa0*/ BYTE         Unknown0xfa0[0x48]; 
/*0xfe8*/struct        _SPAWNINFO *WhoFollowing; // NULL if autofollow off 
/*0xfec*/ BYTE         Unknown0xfec[0xc]; 
/*0xff8*/ FLOAT        CastingY; 
/*0xffc*/ FLOAT        CastingX; 
/*0x1000*/ BYTE        Unknown0x1000[0x6c];
/*0x106c*/ DWORD       Trader;            //0=normal 1=trader 
/*0x1070*/ BYTE        Unknown0x1070[0x50]; 
/*0x10c0*/ 
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

// sizeof(_SPAWNINFO) is 0x348 (5/11/2005) 
typedef struct _SPAWNINFO { 
/* 0x0000 */   BYTE    Unknown0x0; 
/* 0x0001 */   CHAR    Lastname[0x27];  // // Surname on PCs, Newbie Tag on NPCs 
/* 0x0028 */   DWORD     Unknown0x028[0x2];
/* 0x0030 */   FLOAT     Y; 
/* 0x0034 */   FLOAT     X; 
/* 0x0038 */   FLOAT     Z; 
/* 0x003c */   FLOAT     SpeedY; 
/* 0x0040 */   FLOAT     SpeedX; 
/* 0x0044 */   FLOAT     SpeedZ; 
/* 0x0048 */   FLOAT     SpeedRun; 
/* 0x004c */   FLOAT     Heading; 
/* 0x0050 */   FLOAT     field_50; 
/* 0x0054 */   DWORD     field_54; 
/* 0x0058 */   DWORD     field_58; 
/* 0x005c */   FLOAT     CameraAngle; 
/* 0x0060 */   BYTE      Unknown0x60[0x50]; 
/* 0x00b0 */   FLOAT     Y2;
/* 0x00b4 */   FLOAT     X2;
/* 0x00b8 */   FLOAT     Z2;
/* 0x00bc */   FLOAT     SpeedY2;
/* 0x00c0 */   FLOAT     SpeedX2;
/* 0x00c4 */   FLOAT     SpeedZ2;
/* 0x00c8 */   FLOAT     SpeedRun2;
/* 0x00cc */   FLOAT     Heading2;
/* 0x00d0 */   BYTE      Unknown0x0d0[0x50];
/* 0x0120 */   CHAR      Name[0x40]; // ie priest_of_discord00 
/* 0x0160 */   CHAR      DisplayedName[0x40]; // ie Priest of Discord 
/* 0x01a0 */   FLOAT     SpeedHeading; 
/* 0x01a4 */   DWORD     field_1a4;  
/* 0x01a8 */   struct    _ACTORINFO   *pActorInfo; 
/* 0x01ac */   DWORD     field_1ac; 
/* 0x01b0 */   BYTE      CanFindLocation; 
/* 0x01b1 */   BYTE      Sneak;  // returns 01 on both Sneak and Shroud of Stealth 
/* 0x01b2 */   BYTE      Linkdead;  // Uncharmable flag when used on mobs? 
/* 0x01b3 */   BYTE      field_1b3; 
/* 0x01b4 */   BYTE      LFG; 
/* 0x01b5 */   BYTE      field_1b5; 
/* 0x01b6 */   BYTE      IsABoat; // 1 = a type of boat 
/* 0x01b7 */   BYTE      Unknown0x1b7; 
/* 0x01b8 */   ARGBCOLOR ArmorColor[0x9];  // Armor Dye if custom, otherwise Item Tint 
/* 0x01dc */   struct    _EQUIPMENT Equipment; 
/* 0x0200 */   DWORD     field_200; 
/* 0x0204 */   WORD      Zone; 
/* 0x0206 */   WORD      Instance; 
/* 0x0208 */   DWORD     field_208; 
/* 0x020c */   DWORD     field_20c; 
/* 0x0210 */   DWORD     field_210; 
/* 0x0214 */   struct    _SPAWNINFO *pNext; 
/* 0x0218 */   struct    _CHARINFO  *pCharInfo; 
/* 0x021c */   DWORD     field_218; 
/* 0x0220 */   struct    _SPAWNINFO *pPrev; 
/* 0x0224 */   BYTE      Unknown0x220[0x4]; 
/* 0x0228 */   FLOAT     field_228; 
/* 0x022c */   DWORD     field_22c; 
/* 0x0230 */   FLOAT     RunSpeed; 
/* 0x0234 */   FLOAT     field_234; 
/* 0x0238 */   FLOAT     field_238; 
/* 0x023c */   FLOAT     AvatarHeight;  // height of avatar from ground when standing 
/* 0x0240 */   FLOAT     WalkSpeed; 
/* 0x0244 */   BYTE      Type; 
/* 0x0245 */   BYTE      HairColor;      
/* 0x0246 */   BYTE      BeardColor; 
/* 0x0247 */   BYTE      Field_247; 
/* 0x0248 */   BYTE      Eyes; 
/* 0x0249 */   BYTE      Eyes2;      
/* 0x024a */   BYTE      BeardType; 
/* 0x024b */   BYTE      Holding;   // 0=holding/wielding nothing 
/* 0x024c */   BYTE      Level; 
/* 0x024d */   BYTE      FaceHair;  // Face/Hair combination with headgear 
/* 0x024e */   BYTE      Gender; 
/* 0x024f */   BYTE      PvPFlag; 
/* 0x0250 */   BYTE      HideMode; 
/* 0x0251 */   BYTE      StandState; 
/* 0x0252 */   BYTE      Class; 
/* 0x0253 */   BYTE      Light; 
/* 0x0254 */   BYTE      InNonPCRaceIllusion;  // This is buggy ...not sure exact usage 
/* 0x0255 */   BYTE      Field_251;  // form related, unsure how 
/* 0x0256 */   BYTE      GM;       
/* 0x0257 */   BYTE      Field_253; 
/* 0x0258 */   DWORD     SpawnID; 
/* 0x025c */   DWORD     MasterID; 
/* 0x0260 */   DWORD     Race; 
/* 0x0264 */   DWORD     Anon; 
/* 0x0268 */   DWORD     field_264; 
/* 0x026c */   DWORD     AFK; 
/* 0x0270 */   DWORD     BodyType; 
/* 0x0274 */   LONG      HPCurrent; 
/* 0x0278 */   BYTE      AARank; 
/* 0x0279 */   BYTE      Unknown0x278[0x3]; 
/* 0x027c */   DWORD     GuildStatus; 
/* 0x0280 */   DWORD     Deity; 
/* 0x0284 */   DWORD     HPMax; 
/* 0x0288 */   DWORD     GuildID; 
/* 0x028c */   BYTE      Levitate;   //0-normal state  2=levitating 3=mob (not levitating) 
/* 0x028d */   BYTE      Unknown0x28c[0x17]; 
/* 0x02a4 */   CHAR      Title[0x20];
/* 0x02c4 */   CHAR      Suffix[0x20];
/* 0x02e4 */   CHAR      Unknown0x2e4[0x348-0x2e4];
/*	        More Data */ 
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
/*0x00*/	DWORD		Unknown0x0[0x2];
/*0x08*/	DWORD		UnknownData0x08;
/*0x0c*/	DWORD		UnknownData0x0c;
/*0x10*/	DWORD		Unknown0x10[0x2];
/*0x18*/	DWORD		UnknownData0x18;
/*0x1c*/	DWORD		Unknown0x1c;
/*0x20*/	DWORD		UnknownData0x20;
/*0x24*/	FLOAT		Y;
/*0x28*/	FLOAT		X;
/*0x2c*/	FLOAT		Z;
/*0x30*/	BYTE		Unknown0x30[0x58]; //A lot of data here.
/*0x88*/	FLOAT		Y2;
/*0x8c*/	FLOAT		X2;
/*0x90*/	FLOAT		Z2;
/*0x94*/	DWORD		Unknown0x94;
/*0x98*/	FLOAT		Heading;
/*0x9c		Data Continues... */
} EQSWITCH, *PEQSWITCH;

typedef struct _DOOR { 
/*0x00*/   BYTE Unknown0x00; 
/*0x01*/   BYTE ID; 
/*0x02*/   CHAR Name[0x0b]; 
/*0x0d*/   BYTE Unknown0x0d[0x17]; 
/*0x24*/   FLOAT DefaultY; 
/*0x28*/   FLOAT DefaultX; 
/*0x2c*/   FLOAT DefaultZ; 
/*0x30*/   FLOAT DefaultHeading; 
/*0x34*/   FLOAT DoorAngle; 
/*0x38*/   FLOAT Y; 
/*0x3c*/   FLOAT X; 
/*0x40*/   FLOAT Z; 
/*0x44*/   FLOAT Heading; 
/*0x48*/   BYTE Unknown0x48[0x3c]; 
/*0x84*/   PEQSWITCH pSwitch; // (class EQSwitch *) 
/*0x88*/ 
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

#define   MAX_ZONES                                    0x15B   
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
/*0x198*/   DWORD   Flags;              // (Flags & 0x100000) = HasMinLevel, 0x4000 no air, 0x2 newbie zone, 0x20 no bind, 0x400000 something 
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
/*0x1a8*/   BYTE    Unknown0x1a8;
/*0x1a9*/   BYTE    Unknown0x1a9[0x3];
/*0x1ac*/   BYTE    Unknown0x1ac[0x2e];
/*0x1da*/	BYTE	SkyType;	
/*0x1db*/	BYTE	Unknown0x1db[0xd];
/*0x1e8*/   FLOAT   ZoneExpModifier;    //This has been nerfed ..now reads 1.0 for all zones
/*0x1ec*/   FLOAT   Unknown0x1ec[3];
/*0x1f8*/   FLOAT   Ceiling;
/*0x1fc*/   FLOAT   Floor; 
/*0x200*/   FLOAT   MinClip; 
/*0x204*/   FLOAT   MaxClip; 
/*0x208*/   BYTE    Unknown0x208[0x18];
/*0x220*/   BYTE    Unknown0x220[0x20];
/*0x240*/
} ZONEINFO, *PZONEINFO;

#define   TOTAL_SPELL_COUNT				0x2701      // # of spells allocated in memory (5/11/2005 :: 0x7d00/4)
#define   TOTAL_ACTUAL_SPELLS			0x1964      // # of ACTUAL spells in game      (9/14/2004)

// size: 0x7d24 (5/11/2005 :: 0x7d00+0x24)
typedef struct _SPELLMGR {
            BYTE                unknown[0x24];
            struct _SPELL*      Spells[TOTAL_SPELL_COUNT];
} SPELLMGR, *PSPELLMGR;

// Size is 0x268 as of 9/14
// Size is 0x26C as of 2/8
// Size is 0x26C as of 03/03/2005
// Size is 0x26c as of 5/11/2005
// Size is 0x26c as of 9/17/2005
typedef struct _SPELL {
/*0x000*/   DWORD   ID;
/*0x004*/   FLOAT   Range;
/*0x008*/   FLOAT   AERange;
/*0x00c*/   FLOAT   PushBack;
/*0x010*/   BYTE    Unknown0x010[0x04];
/*0x014*/   DWORD   CastTime;
/*0x018*/   DWORD   FizzleTime;
/*0x01c*/   DWORD   RecastTime;
/*0x020*/   DWORD   DurationType;       //DurationFormula on Lucy
/*0x024*/   DWORD   DurationValue1;
/*0x028*/   DWORD   Unknown0x028;
/*0x02c*/   DWORD   Mana;
/*0x030*/   LONG    Base[0x0c];         //Base1-Base12
/*0x060*/   LONG    Base2[0x0c];        //Mostly unused, setting name to Base2 from Lucy for now
/*0x090*/   LONG    Max[0x0c];          //Max1-Max12
/*0x0c0*/   DWORD   ReagentId[0x4];     //ReagentId1-ReagentId4
/*0x0d0*/   DWORD   ReagentCount[0x4];  //ReagentCount1-ReagentCount4
/*0x0e0*/   BYTE    Unknown0x0e0[0x10];
/*0x0f0*/   DWORD   Calc[0x0c];         //Calc1-Calc12
/*0x120*/   DWORD   Attrib[0x0c];       //Attrib1-Attrib12
/*0x150*/   BYTE    Unknown0x150;
/*0x151*/   BYTE    Level[0x10];        // per class.
/*0x161*/   BYTE    Unknown0x161[0x13];
/*0x174*/   DWORD   BookIcon;
/*0x178*/   DWORD   GemIcon;
/*0x17c*/   BYTE    LightType;
/*0x17d*/   BYTE    SpellType;          //0=detrimental, 1=Beneficial, 2=Beneficial, Group Only
/*0x17e*/   BYTE    Unknown0x12a;
/*0x17f*/   BYTE    Resist;             //0=un 1=mr 2=fr 3=cr 4=pr 5=dr 6=chromatic
/*0x180*/   BYTE    TargetType;         // 03=Group v1, 04=PB AE, 05=Single, 06=Self, 08=Targeted AE, 0e=Pet, 28=AE PC v2, 29=Group v2
/*0x181*/   BYTE    FizzleAdj;
/*0x182*/   BYTE    Skill;
/*0x183*/   BYTE    Location;           // 01=Outdoors, 02=dungeons, ff=Any
/*0x184*/   BYTE    Environment;
/*0x185*/   BYTE    TimeOfDay;          // 0=any, 1=day only, 2=night only
/*0x186*/   BYTE    CastingAnim;
/*0x187*/   BYTE    TargetAnim;
/*0x188*/   BYTE    Unknown0x188[0x4];
/*0x18c*/   DWORD   DescriptionNumber;
/*0x190*/   BYTE    Uninterruptable;    // 00=Interruptable, 01=Uninterruptable
/*0x191*/   BYTE    Unknown0x191;
/*0x192*/   BYTE    Deletable;
/*0x193*/   BYTE    Unknown0x193;
/*0x194*/   DWORD   Autocast;           // SpellID of spell to instacast on caster when current spell lands on target
/*0x198*/   BYTE    Unknown0x198;
/*0x199*/   BYTE    Unknown0x199;
/*0x19a*/   BYTE    Unknown0x19a;
/*0x19b*/   BYTE    DurationWindow;     // 0=Long, 1=Short
/*0x19c*/   DWORD   Unknown144;         // Unknown144 from lucy
/*0x1a0*/   DWORD   Unknown145;         // Unknown145 from lucy
/*0x1a4*/   BYTE    Unknown0x1a4[0x1c];
/*0x1c0*/   DWORD   CARecastTimerID;    // ID of combat timer, i think.
/*0x1c4*/   DWORD   Unknown0x1c4;
/*0x1c8*/   BYTE    Unknown0x1c8[0x18];
/*0x1e0*/   DWORD   PvPResistBase;
/*0x1e4*/   DWORD   PvPResistCalc;
/*0x1e8*/   DWORD   PvPResistCap;
/*0x1ec*/   DWORD   Unknown182;         // Unknown182 from Lucy
/*0x1f0*/   DWORD   Unknown183;         // Unknown183 from Lucy
/*0x1f4*/   DWORD   Unknown0x1f4;
/*0x1f8*/   DWORD   Unknown0x1f8;
/*0x1fc*/   BYTE    Unknown0x1fc;
/*0x1fd*/   BYTE    CanMGB;
/*0x1fe*/   BYTE    Unknown0x1fe[0xa];
/*0x208*/   CHAR    *Name;
/*0x20c*/   CHAR    *Target;
/*0x210*/   CHAR    *Extra;             // This is 'Extra' from Lucy (portal shortnames etc)
/*0x214*/   CHAR    *Unknown0x214;
/*0x218*/   CHAR    *Unknown0x218;
/*0x21c*/   CHAR    *CastOnYou;
/*0x220*/   CHAR    *CastOnAnother;
/*0x224*/   CHAR    *WearOff;
/*0x228*/   BYTE    Unknown0x228[0x8];
/*0x230*/   DWORD   Unknown0x230; 
/*0x234*/   DWORD   spaindex;
/*0x238*/   DWORD   Unknown0x238;
/*0x23c*/   DWORD   SpellAnim;
/*0x240*/   DWORD   Unknown0x240;
/*0x244*/   DWORD   Unknown130;
/*0x248*/   DWORD   Unknown0x248;
/*0x24c*/   DWORD   SpellIcon;
/*0x250*/   DWORD   ResistAdj;
/*0x254*/   BYTE    Unknown0x254[0x18];
/*0x26c*/
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

#define MAX_GUILDS			0x5DC
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

typedef struct _INTERACTGROUNDITEM {
	DWORD DropID;
	DWORD SpawnID;
} INTERACTGROUNDITEM, *PINTERACTGROUNDITEM;

typedef struct _SPELLFAVORITE {
/*0x000*/   DWORD   SpellId[9];
/*0x024*/   CHAR    Name[25];
/*0x03d*/   BYTE    Byte_3d;
/*0x03e*/   BYTE    Byte_3e;
/*0x03f*/   BYTE    Byte_3f;
/*0x040*/
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
/*0x04*/ DWORD Flags;           //?
/*0x08*/ DWORD nShortName;
/*0x0c*/ DWORD nShorterName;
/*0x10*/ DWORD nName;           // now a database number
/*0x14*/ DWORD nDesc;           // now a database number
/*0x18*/ DWORD MinLevel;
/*0x1c*/ DWORD Cost; //Initial Cost or cost the last time you bought a level of it
/*0x20*/ DWORD ID;              // /alt activate id
/*0x24*/ DWORD AARankRequired; 
        union {  
/*0x28*/ LONG  RequiresAbility;          // If the value is positive then its the index number of the AA required.
/*0x28*/ DWORD RequiresPointsInCategory; // If the value is negative then abs(value) is the
	};                                   // category, while (abs(value))*6 is the points required.
/*0x2c*/ DWORD RequiresAbilityPoints;
/*0x30*/ DWORD Type; 
/*0x34*/ LONG  SpellID; // -1 for no Spell
/*0x38*/ BYTE  Unknown0x34[0x8]; 
/*0x40*/ DWORD ReuseTimer; // in seconds
/*0x44*/ DWORD Classes;    // Classes/2 is the actual value we want.
/*0x48*/ DWORD MaxRank;
	union {						 //If you have not spent points in this 
/*0x4c*/ DWORD PointsSpent;		 //ability, then its PointsToBeSpent (or 
/*0x4c*/ DWORD PointsToBeSpent;	 //'Cost', in other words).
	}; 
/*0x50*/ DWORD AAIndex;     // -1 if not available
/*0xxx*/ DWORD UseAAIndex;
/*0xxx*/ BYTE  Unknown0x54;
/*0xxx*/ BYTE  Unknown0x55;
/*0xxx*/ BYTE  Unknown0x56;
/*0xxx*/ BYTE  Unknown0x57;
/*0xxx*/ BYTE  Unknown0x58[0x18];
} ALTABILITY, *PALTABILITY;
#define zWarp				 0

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

// size 0x118 (8.11.2004)
typedef struct _EQRAIDMEMBER { 
/*0x00*/ CHAR Name[0x40]; 
/*0x40*/ CHAR RaidNote[0x40]; 
/*0x80*/ CHAR Level[0x08]; 
/*0x88*/ CHAR Class[0x20]; 
/*0xC8*/ BYTE Unknown0xC8[0x60]; 
/*0x108*/ DWORD nClass; 
/*0x10C*/ BYTE  RaidLeader; 
/*0x10D*/ BYTE  GroupLeader; 
/*0x10E*/ BYTE  Field_10E; 
/*0x10F*/ BYTE  Field_10F; 
/*0x110*/ BYTE  Field_110; 
/*0x111*/ BYTE  Padding0x111[0x3]; 
/*0x114*/ DWORD GroupNumber; 
/*0x118*/ 
} EQRAIDMEMBER, *PEQRAIDMEMBER;

// sizeof(_EQRAID) is 0x5ab8 (8-11-2004)
typedef struct _EQRAID { 
/*0x0000*/  BYTE  		Unknown0x0[0x154];
/*0x0154*/  CHAR  		RaidMemberUsed[0x48];
/*0x019c*/  struct		_EQRAIDMEMBER RaidMember[0x48];
/*0x505c*/  DWORD 		field_505c;
/*0x5060*/  DWORD 		RaidMemberCount;
/*0x5064*/  CHAR        RaidLeaderName[0x140]; 
/*0x51a4*/  CHAR        RaidMOTD[0x400];
/*0x55a4*/  BYTE        Unknown0x55a4[0x40]; 
/*0x55e4*/  DWORD       field_55E4; 
/*0x55e8*/  BYTE        Unknown0x55e8; 
/*0x55e9*/  BYTE        IsRaidLeader; 
/*0x55ea*/  BYTE        Unknown0x55ea[0x2]; 
/*0x55ec*/  DWORD       RaidTarget; 
/*0x55f0*/  DWORD       LootType; 
/*0x55f4*/  CHAR        RaidLooters[0x13][0x40]; 
/*0x5ab4*/  DWORD       TotalRaidMemberLevels; // TotalRaidMemberLevels/RaidMemberCount=RaidAvgLevel
/*0x5ab8*/ 
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

#define EQ_INTERACTGROUNDITEM   0x3BC2
#define EQ_EMOTE	        0x547A
#define EQ_BEGIN_ZONE           0x1540
#define EQ_END_ZONE             0x5e20
};
using namespace EQData;
