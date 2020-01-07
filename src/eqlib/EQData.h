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

#pragma once

#include "../common/Common.h"
#include "Containers.h"
#include "Items.h"
#include "PlayerClient.h"

namespace eqlib {

// Forward declarations


// ***************************************************************************
// Defines
// ***************************************************************************

#define AllClassesMASK                           0xffff
#define WarriorMASK                              0x0001
#define ClericMASK                               0x0002
#define RogueMASK                                0x0100
#define WizardMASK                               0x0400

enum PlayerClass
{
	Unknown                                    = 0,
	Warrior                                    = 1,
	Cleric                                     = 2,
	Paladin                                    = 3,
	Ranger                                     = 4,
	Shadowknight                               = 5,
	Druid                                      = 6,
	Monk                                       = 7,
	Bard                                       = 8,
	Rogue                                      = 9,
	Shaman                                     = 10,
	Necromancer                                = 11,
	Wizard                                     = 12,
	Mage                                       = 13,
	Enchanter                                  = 14,
	Beastlord                                  = 15,
	Berserker                                  = 16,
	TotalPlayerClasses                         = Berserker,

	Mercenary                                  = 17,
	TotalClasses                               = Mercenary,
};

// class 20 through 35 are the NPC GMs (same class order as above)
// class 41   Merchant
// class 60   LDoN Recruiter
// class 61   LDoN Merchant
// class 63   Tribute Master
// class 67   DoN Merchant (Norrath's Keepers)
// class 68   DoN Merchant (Dark Reign)

struct SClassInfo
{
	bool CanCast;
	bool PureCaster;
	bool PetClass;
	bool DruidType;
	bool NecroType;
	bool ClericType;
	bool ShamanType;
	bool MercType;
	char RaidColorOrder;
	char* Name;
	char* ShortName;
	char* UCShortName;
};
using CLASSINFO [[deprecated]] = SClassInfo;
using PCLASSINFO [[deprecated]] = SClassInfo *;

static SClassInfo ClassInfo[] =
{
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0,  "",             "",    ""    }, // unk
	{ 0, 0, 0, 0, 0, 0, 0, 0, 13, "Warrior",      "war", "WAR" }, // war
	{ 1, 1, 0, 0, 0, 1, 0, 0, 2,  "Cleric",       "clr", "CLR" }, // clr
	{ 1, 0, 0, 0, 0, 1, 0, 0, 8,  "Paladin",      "pal", "PAL" }, // pal
	{ 1, 0, 0, 1, 0, 0, 0, 0, 9,  "Ranger",       "rng", "RNG" }, // rng
	{ 1, 0, 0, 0, 1, 0, 0, 0, 11, "Shadowknight", "shd", "SHD" }, // shd
	{ 1, 1, 0, 1, 0, 0, 0, 0, 3,  "Druid",        "dru", "DRU" }, // dru
	{ 0, 0, 0, 0, 0, 0, 0, 0, 6,  "Monk",         "mnk", "MNK" }, // mnk
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0,  "Bard",         "brd", "BRD" }, // brd
	{ 0, 0, 0, 0, 0, 0, 0, 0, 10, "Rogue",        "rog", "ROG" }, // rog
	{ 1, 1, 1, 0, 0, 0, 1, 0, 12, "Shaman",       "shm", "SHM" }, // shm
	{ 1, 1, 1, 0, 1, 0, 0, 0, 7,  "Necromancer",  "nec", "NEC" }, // nec
	{ 1, 1, 0, 0, 0, 0, 0, 0, 14, "Wizard",       "wiz", "WIZ" }, // wiz
	{ 1, 1, 1, 0, 0, 0, 0, 0, 5,  "Mage",         "mag", "MAG" }, // mag
	{ 1, 1, 0, 0, 0, 0, 0, 0, 4,  "Enchanter",    "enc", "ENC" }, // enc
	{ 1, 0, 1, 0, 0, 0, 1, 0, 1,  "Beastlord",    "bst", "BST" }, // bst
	{ 0, 0, 0, 0, 0, 0, 0, 0, 15, "Berserker",    "ber", "BER" }, // ber
	{ 1, 1, 0, 0, 0, 0, 0, 1, 16, "Mercenary",    "mer", "MER" }, // mer
};

#define BI_TARGETABLE                            1
#define BI_TRIGGER                               2
#define BI_TRAP                                  4
#define BI_TIMER                                 8

// player types
constexpr int EQP_PC = 0;
constexpr int EQP_NPC = 1;
constexpr int EQP_CORPSE = 2;

// door types
#define EQSWITCH_STANDARD                        0
#define EQSWITCH_STANDARD_METAL                  1
#define EQSWITCH_STANDARD_STONE	                 2
#define EQSWITCH_STANDARD_CLOCKWISE	             5
#define EQSWITCH_STANDARD_CLOCKWISE_METAL        6
#define EQSWITCH_STANDARD_CLOCKWISE_STONE        7
#define EQSWITCH_STANDARD_STONE_COLLIDING        8

#define EQSWITCH_SMALL_SLIDING                   10
#define EQSWITCH_SMALL_SLIDING_METAL             11
#define EQSWITCH_SMALL_SLIDING_STONE             12
#define EQSWITCH_MEDIUM_SLIDING	                 15
#define EQSWITCH_MEDIUM_SLIDING_METAL            16
#define EQSWITCH_MEDIUM_SLIDING_STONE            17
#define EQSWITCH_LARGE_SLIDING                   20
#define EQSWITCH_LARGE_SLIDING_METAL             21
#define EQSWITCH_LARGE_SLIDING_STONE             22
#define EQSWITCH_GIANT_SLIDING                   25
#define EQSWITCH_GIANT_SLIDING_METAL             26
#define EQSWITCH_GIANT_SLIDING_STONE             27
#define EQSWITCH_DRAWBRIDGE                      30
#define	EQSWITCH_TRAP                            35
#define	EQSWITCH_PULLTRAP                        36
#define EQSWITCH_LEVER                           40
#define	EQSWITCH_TOGGLE_BUTTON                   45
#define EQSWITCH_PRESSURE_PLATE                  50 // if u step or touch this it keep the door open, move away and it closes.
#define EQSWITCH_DAMAGE_PLATE                    51 // if you stand on this it damages you.

#define EQSWITCH_GUILD_CHEST                     56
#define EQSWITCH_TELEPORTER                      57
#define EQSWITCH_KEY_TELEPORTER                  58
#define EQSWITCH_ELEVATOR                        59
#define EQSWITCH_SMALL_SLIDE_UPWARDS             60
#define EQSWITCH_SMALL_SLIDE_UPWARDS_METAL       61
#define EQSWITCH_SMALL_SLIDE_UPWARDS_STONE       62
#define EQSWITCH_MEDIUM_SLIDE_UPWARDS            65
#define EQSWITCH_MEDIUM_SLIDE_UPWARDS_METAL      66
#define EQSWITCH_MEDIUM_SLIDE_UPWARDS_STONE      67

#define EQSWITCH_LARGE_SLIDE_UPWARDS             70
#define EQSWITCH_LARGE_SLIDE_UPWARDS_METAL       71
#define EQSWITCH_LARGE_SLIDE_UPWARDS_STONE       72
#define EQSWITCH_GIANT_SLIDE_UPWARDS             75
#define EQSWITCH_GIANT_SLIDE_UPWARDS_METAL       76
#define EQSWITCH_GIANT_SLIDE_UPWARDS_STONE       77
#define EQSWITCH_DIAGONAL_UP_RIGHT               78
#define EQSWITCH_DIAGONAL_UP_LEFT                79
#define EQSWITCH_DIAGONAL_DOWN_RIGHT             80
#define EQSWITCH_DIAGONAL_DOWN_LEFT              81
#define EQSWITCH_GIANT_UP_OR_DOWN                82
#define EQSWITCH_GIANT_UP_OR_DOWN_METAL          83
#define EQSWITCH_GIANT_UP_OR_DOWN_STONE          84

#define EQSWITCH_BUTTON                          109

#define EQSWITCH_TRADER_PLATFORM                 153
#define EQSWITCH_BARTER_PLATFORM                 154
#define EQSWITCH_BARTER_TRADER_PLATFORM          155

#define EQSWITCH_BOOK                            158 // opens bookwindow
#define EQSWITCH_REALESTATE_NEIGHBORHOOD         159
#define EQSWITCH_REALESTATE_PLOT                 160
#define EQSWITCH_REALESTATE_EXIT                 161

#define SPAWN_PLAYER                             0
#define SPAWN_NPC                                1
#define SPAWN_CORPSE                             2
//#define SPAWN_ANY                                3
//#define SPAWN_PET                                4

#define SKILL_PICKLOCK                           35

#define ITEM_NORMAL1                             0x0031
#define ITEM_NORMAL2                             0x0036
#define ITEM_NORMAL3                             0x315f
#define ITEM_NORMAL4                             0x3336
#define ITEM_NORMAL5                             0x0032
#define ITEM_NORMAL6                             0x0033
#define ITEM_NORMAL7                             0x0034
#define ITEM_NORMAL8                             0x0039
#define ITEM_CONTAINER                           0x7900
#define ITEM_CONTAINER_PLAIN                     0x7953
#define ITEM_BOOK                                0x7379

#define ITEMITEMTYPE_FOOD                        0x0e
#define ITEMITEMTYPE_WATER                       0x0f
#define ITEMITEMTYPE_SCROLL                      0x14
#define ITEMITEMTYPE_ALCOHOL                     0x26
#define ITEMITEMTYPE_POISON                      0x2a
#define ITEMITEMTYPE_AUGUMENT                    0x36

#define ITEMEFFECTTYPE_COMBAT                    0x00
#define ITEMEFFECTTYPE_INVENTORY1                0x01 // Bards need to stop sing to cast
#define ITEMEFFECTTYPE_WORN                      0x02
#define ITEMEFFECTTYPE_INVENTORY2                0x03
#define ITEMEFFECTTYPE_MUSTEQUIP                 0x04 // Bards need to stop sing to cast
#define ITEMEFFECTTYPE_INVENTORY3                0x05

#define SKILLMINDAMAGEMOD_BASH                   0x00
#define SKILLMINDAMAGEMOD_BACKSTAB               0x01
#define SKILLMINDAMAGEMOD_DRAGONPUNCH            0x02
#define SKILLMINDAMAGEMOD_EAGLESTRIKE            0x03
#define SKILLMINDAMAGEMOD_FLYINGKICK             0x04
#define SKILLMINDAMAGEMOD_KICK                   0x05
#define SKILLMINDAMAGEMOD_ROUNDKICK              0x06
#define SKILLMINDAMAGEMOD_TIGERCLAW              0x07
#define SKILLMINDAMAGEMOD_FRENZY                 0x08

// Heroic Mods
#define HEROIC_MOD_SPELL_SHIELDING               0x4
#define HEROIC_MOD_COMBAT_EFFECTS                0x5
#define HEROIC_MOD_MELEE_SHIELDING               0x6
#define HEROIC_MOD_DAMAGE_SHIELDING              0x7
#define HEROIC_MOD_DOT_SHIELDING                 0x8
#define HEROIC_MOD_DAMAGE_SHIELD_MITIG           0x9
#define HEROIC_MOD_AVOIDANCE                     0xa
#define HEROIC_MOD_ACCURACY                      0xb
#define HEROIC_MOD_STUN_RESIST                   0xc
#define HEROIC_MOD_STRIKETHROUGH                 0xd

#define COLOR_DEFAULT                            0x00
#define COLOR_DARKGREY                           0x01
#define COLOR_DARKGREEN                          0x02
#define COLOR_DARKBLUE                           0x03
#define COLOR_PURPLE                             0x05
#define COLOR_LIGHTGREY                          0x06

#define CONCOLOR_GREY                            0x06
#define CONCOLOR_GREEN                           0x02
#define CONCOLOR_LIGHTBLUE                       0x12
#define CONCOLOR_BLUE                            0x04
#define CONCOLOR_BLACK                           0x14
#define CONCOLOR_WHITE                           0x0a
#define CONCOLOR_YELLOW                          0x0f
#define CONCOLOR_RED                             0x0d

#define USERCOLOR_SAY                            0xFF +   1 //  1  - Say
#define USERCOLOR_TELL                           0xFF +   2 //  2  - Tell
#define USERCOLOR_GROUP                          0xFF +   3 //  3  - Group
#define USERCOLOR_GUILD                          0xFF +   4 //  4  - Guild
#define USERCOLOR_OOC                            0xFF +   5 //  5  - OOC
#define USERCOLOR_AUCTION                        0xFF +   6 //  6  - Auction
#define USERCOLOR_SHOUT                          0xFF +   7 //  7  - Shout
#define USERCOLOR_EMOTE                          0xFF +   8 //  8  - Emote
#define USERCOLOR_SPELLS                         0xFF +   9 //  9  - Spells (meming, scribing, casting, etc.)
#define USERCOLOR_YOU_HIT_OTHER                  0xFF +  10 //  10 - You hit other
#define USERCOLOR_OTHER_HIT_YOU                  0xFF +  11 //  11 - Other hits you
#define USERCOLOR_YOU_MISS_OTHER                 0xFF +  12 //  12 - You miss other
#define USERCOLOR_OTHER_MISS_YOU                 0xFF +  13 //  13 - Other misses you
#define USERCOLOR_DUELS                          0xFF +  14 //  14 - Some broadcasts (duels)
#define USERCOLOR_SKILLS                         0xFF +  15 //  15 - Skills (ups, non-combat use, etc.)
#define USERCOLOR_DISCIPLINES                    0xFF +  16 //  16 - Disciplines or special abilities
#define USERCOLOR_UNUSED001                      0xFF +  17 //  17 - Unused at this time
#define USERCOLOR_DEFAULT                        0xFF +  18 //  18 - Default text and stuff you type
#define USERCOLOR_UNUSED002                      0xFF +  19 //  19 - Unused at this time
#define USERCOLOR_MERCHANT_OFFER                 0xFF +  20 //  20 - Merchant Offer Price
#define USERCOLOR_MERCHANT_EXCHANGE              0xFF +  21 //  21 - Merchant Buy/Sell
#define USERCOLOR_YOUR_DEATH                     0xFF +  22 //  22 - Your death message
#define USERCOLOR_OTHER_DEATH                    0xFF +  23 //  23 - Others death message
#define USERCOLOR_OTHER_HIT_OTHER                0xFF +  24 //  24 - Other damage other
#define USERCOLOR_OTHER_MISS_OTHER               0xFF +  25 //  25 - Other miss other
#define USERCOLOR_WHO                            0xFF +  26 //  26 - /who command
#define USERCOLOR_YELL                           0xFF +  27 //  27 - yell for help
#define USERCOLOR_NON_MELEE                      0xFF +  28 //  28 - Hit for non-melee
#define USERCOLOR_SPELL_WORN_OFF                 0xFF +  29 //  29 - Spell worn off
#define USERCOLOR_MONEY_SPLIT                    0xFF +  30 //  30 - Money splits
#define USERCOLOR_LOOT                           0xFF +  31 //  31 - Loot message
#define USERCOLOR_RANDOM                         0xFF +  32 //  32 - Dice Roll (/random)
#define USERCOLOR_OTHERS_SPELLS                  0xFF +  33 //  33 - Others spells
#define USERCOLOR_SPELL_FAILURE                  0xFF +  34 //  34 - Spell Failures (resists, fizzles, missing component, bad target, etc.)
#define USERCOLOR_CHAT_CHANNEL                   0xFF +  35 //  35 - Chat Channel Messages
#define USERCOLOR_CHAT_1                         0xFF +  36 //  36 - Chat Channel 1
#define USERCOLOR_CHAT_2                         0xFF +  37 //  37 - Chat Channel 2
#define USERCOLOR_CHAT_3                         0xFF +  38 //  38 - Chat Channel 3
#define USERCOLOR_CHAT_4                         0xFF +  39 //  39 - Chat Channel 4
#define USERCOLOR_CHAT_5                         0xFF +  40 //  40 - Chat Channel 5
#define USERCOLOR_CHAT_6                         0xFF +  41 //  41 - Chat Channel 6
#define USERCOLOR_CHAT_7                         0xFF +  42 //  42 - Chat Channel 7
#define USERCOLOR_CHAT_8                         0xFF +  43 //  43 - Chat Channel 8
#define USERCOLOR_CHAT_9                         0xFF +  44 //  44 - Chat Channel 9
#define USERCOLOR_CHAT_10                        0xFF +  45 //  45 - Chat Channel 10
#define USERCOLOR_MELEE_CRIT                     0xFF +  46 //  46 - Melee Crits
#define USERCOLOR_SPELL_CRIT                     0xFF +  47 //  47 - Spell Crits
#define USERCOLOR_TOO_FAR_AWAY                   0xFF +  48 //  48 - Too far away (melee)
#define USERCOLOR_NPC_RAMPAGE                    0xFF +  49 //  49 - NPC Rampage
#define USERCOLOR_NPC_FLURRY                     0xFF +  50 //  50 - NPC Furry
#define USERCOLOR_NPC_ENRAGE                     0xFF +  51 //  51 - NPC Enrage
#define USERCOLOR_ECHO_SAY                       0xFF +  52 //  52 - say echo
#define USERCOLOR_ECHO_TELL                      0xFF +  53 //  53 - tell echo
#define USERCOLOR_ECHO_GROUP                     0xFF +  54 //  54 - group echo
#define USERCOLOR_ECHO_GUILD                     0xFF +  55 //  55 - guild echo
#define USERCOLOR_ECHO_OOC                       0xFF +  56 //  56 - group echo
#define USERCOLOR_ECHO_AUCTION                   0xFF +  57 //  57 - auction echo
#define USERCOLOR_ECHO_SHOUT                     0xFF +  58 //  58 - shout echo
#define USERCOLOR_ECHO_EMOTE                     0xFF +  59 //  59 - emote echo
#define USERCOLOR_ECHO_CHAT_1                    0xFF +  60 //  60 - chat 1 echo
#define USERCOLOR_ECHO_CHAT_2                    0xFF +  61 //  61 - chat 2 echo
#define USERCOLOR_ECHO_CHAT_3                    0xFF +  62 //  62 - chat 3 echo
#define USERCOLOR_ECHO_CHAT_4                    0xFF +  63 //  63 - chat 4 echo
#define USERCOLOR_ECHO_CHAT_5                    0xFF +  64 //  64 - chat 5 echo
#define USERCOLOR_ECHO_CHAT_6                    0xFF +  65 //  65 - chat 6 echo
#define USERCOLOR_ECHO_CHAT_7                    0xFF +  66 //  66 - chat 7 echo
#define USERCOLOR_ECHO_CHAT_8                    0xFF +  67 //  67 - chat 8 echo
#define USERCOLOR_ECHO_CHAT_9                    0xFF +  68 //  68 - chat 9 echo
#define USERCOLOR_ECHO_CHAT_10                   0xFF +  69 //  69 - chat 10 echo
#define USERCOLOR_RESERVED                       0xFF +  70 //  70 - "unused at this time"
#define USERCOLOR_LINK                           0xFF +  71 //  71 - item links
#define USERCOLOR_RAID                           0xFF +  72 //  72 - raid
#define USERCOLOR_PET                            0xFF +  73 //  73 - my pet
#define USERCOLOR_DAMAGESHIELD                   0xFF +  74 //  74 - damage shields
#define USERCOLOR_LEADER                         0xFF +  75 //  75 - LAA-related messages
#define USERCOLOR_PETRAMPFLURRY                  0xFF +  76 //  76 - pet rampage/flurry
#define USERCOLOR_PETCRITS                       0xFF +  77 //  77 - pet's critical hits
#define USERCOLOR_FOCUS                          0xFF +  78 //  78 - focus item activation
#define USERCOLOR_XP                             0xFF +  79 //  79 - xp gain/loss
#define USERCOLOR_SYSTEM                         0xFF +  80 //  80 - system broadcasts etc
#define USERCOLOR_PET_SPELLS                     0xFF +  81 //  81 - pet spells
#define USERCOLOR_PET_RESPONSES                  0xFF +  82 //  82 - pet responses
#define USERCOLOR_ITEM_SPEECH                    0xFF +  83 //  83 - item speech
#define USERCOLOR_STRIKETHROUGH                  0xFF +  84 //  84 - strikethrough messages
#define USERCOLOR_STUN                           0XFF +  85 //  85 - stun messages
#define USERCOLOR_RESERVED2                      0xFF +  86 //  86 - "unused at this time" (or unknown!?)
#define USERCOLOR_FELLOWSHIP                     0xFF +  87 //  87 - fellowship messages
#define USERCOLOR_NPC_SPEECH                     0xFF +  88 //  88 - npc dialogue
#define USERCOLOR_NPC_SPEECH_TO_YOU              0xFF +  89 //  89 - npc dialogue to you
#define USERCOLOR_GUILD_MSG                      0xFF +  90 //  90 - guild messages

#define DEITY_Bertoxxulous                       201
#define DEITY_BrellSerilis                       202
#define DEITY_CazicThule                         203
#define DEITY_ErollisiMarr                       204
#define DEITY_Bristlebane                        205
#define DEITY_Innoruuk                           206
#define DEITY_Karana                             207
#define DEITY_MithanielMarr                      208
#define DEITY_Prexus                             209
#define DEITY_Quellious                          210
#define DEITY_RallosZek                          211
#define DEITY_RodcetNife                         212
#define DEITY_SolusekRo                          213
#define DEITY_TheTribunal                        214
#define DEITY_Tunare                             215
#define DEITY_Veeshan                            216
#define NUM_DEITIES                              16

constexpr int ITEMTYPE_NORMAL = 0;
constexpr int ITEMTYPE_PACK = 1;
constexpr int ITEMTYPE_BOOK = 2;

#define COMP_NONE                                0
#define COMP_EQ                                  1
#define COMP_NE                                  2
#define COMP_GT                                  3
#define COMP_LT                                  4
#define COMP_GE                                  5
#define COMP_LE                                  6
#define COMP_CONT                                7
#define COMP_NOTCONT                             8
#define COMP_BITAND                              9
#define COMP_BITOR                               10

#define COMP_TYPE_STRING                         0
#define COMP_TYPE_NUMERIC                        1
#define COMP_TYPE_BIT                            2

#define CMD_MQ                                   1
#define CMD_EQ                                   2

#define LASTFIND_NOTFOUND                        96
#define LASTFIND_PRIMARY                         97

#define EVENT_CHAT                               0
#define EVENT_TIMER                              1
#define EVENT_CUSTOM                             2
#define EVENT_EVAL                               3
#define EVENT_EXEC                               4
#define EVENT_PULSE                              5
#define EVENT_SHUTDOWN                           6
#define EVENT_BREAK                              7
#define NUM_EVENTS                               8

#define CHAT_SAY                                 1
#define CHAT_TELL                                2
#define CHAT_OOC                                 4
#define CHAT_SHOUT                               8
#define CHAT_AUC                                 16
#define CHAT_GUILD                               32
#define CHAT_GROUP                               64
#define CHAT_CHAT                                128
#define CHATEVENT(x)                             (gEventChat & x)

enum eFilterSkill
{
	FILTERSKILL_ALL = 0,
	FILTERSKILL_INCREASE = 1,
	FILTERSKILL_NONE = 2,
};

enum eFilterMacro
{
	FILTERMACRO_ALL = 0,
	FILTERMACRO_ENHANCED = 1,
	FILTERMACRO_NONE = 2,
	FILTERMACRO_MACROENDED = 3,

	FILTERMACRO_MAX,
};

#define MAX_VARNAME                              64


constexpr int EQR_HUMAN                        = 1;
constexpr int EQR_BARBARIAN                    = 2;
constexpr int EQR_ERUDITE                      = 3;
constexpr int EQR_ELF                          = 4;
constexpr int EQR_HIGH_ELF                     = 5;
constexpr int EQR_DARK_ELF                     = 6;
constexpr int EQR_HALF_ELF                     = 7;
constexpr int EQR_DWARF                        = 8;
constexpr int EQR_TROLL                        = 9;
constexpr int EQR_OGRE                         = 10;
constexpr int EQR_HALFLING                     = 11;
constexpr int EQR_GNOME                        = 12;
constexpr int EQR_SKELETON                     = 60;
constexpr int EQR_IKSAR                        = 128;
constexpr int EQR_VAHSHIR                      = 130;
constexpr int EQR_FROGLOCK                     = 330;
constexpr int EQR_SKELETON_NEW                 = 367;
constexpr int EQR_DRAKKIN                      = 522;
constexpr int EQR_OEQ_SKELETON                 = 802;
constexpr int EQR_SOL_SKELETON                 = 803;

// Inventory Slots
enum eInventorySlot
{
	InvSlot_Charm = 0,
	InvSlot_LeftEar,
	InvSlot_Head,
	InvSlot_Face,
	InvSlot_RightEar,
	InvSlot_Neck,
	InvSlot_Shoulders,
	InvSlot_Arms,
	InvSlot_Back,
	InvSlot_LeftWrist,
	InvSlot_RightWrist,
	InvSlot_Range,
	InvSlot_Hands,
	InvSlot_Primary,
	InvSlot_Secondary,
	InvSlot_LeftFingers,
	InvSlot_RightFingers,
	InvSlot_Chest,
	InvSlot_Legs,
	InvSlot_Feet,
	InvSlot_Waist,
	InvSlot_PowerSource,
	InvSlot_Ammo,
	InvSlot_Bag1,
	InvSlot_Bag2,
	InvSlot_Bag3,
	InvSlot_Bag4,
	InvSlot_Bag5,
	InvSlot_Bag6,
	InvSlot_Bag7,
	InvSlot_Bag8,
	InvSlot_Bag9,
	InvSlot_Bag10,
	InvSlot_Held,

	InvSlot_Max,
	InvSlot_FirstBagSlot = InvSlot_Bag1,
	InvSlot_LastBagsLot = InvSlot_Bag10,
};

// AltCurrency values
enum ALTCURRENCY
{
	ALTCURRENCY_DOUBLOONS              = 10, // TBS
	ALTCURRENCY_ORUX                   = 11, // TBS
	ALTCURRENCY_PHOSPHENES             = 12, // TBS
	ALTCURRENCY_PHOSPHITES             = 13, // TBS
	ALTCURRENCY_FAYCITES               = 14, // SoF
	ALTCURRENCY_CHRONOBINES            = 15, // SoD
	ALTCURRENCY_SILVERTOKENS           = 16, // UF
	ALTCURRENCY_GOLDTOKENS             = 17, // UF
	ALTCURRENCY_MCKENZIE               = 18, // SoD
	ALTCURRENCY_BAYLE                  = 19, // SoD
	ALTCURRENCY_RECLAMATION            = 20, // EQ
	ALTCURRENCY_BRELLIUM               = 21, // UF
	ALTCURRENCY_MOTES                  = 22, // HoT
	ALTCURRENCY_REBELLIONCHITS         = 23, // VoA
	ALTCURRENCY_DIAMONDCOINS           = 24, // VoA
	ALTCURRENCY_BRONZEFIATS            = 25, // VoA
	ALTCURRENCY_VOUCHER                = 26, // TDS
	ALTCURRENCY_VELIUMSHARDS           = 27, // RoF
	ALTCURRENCY_CRYSTALLIZEDFEAR       = 28, // RoF
	ALTCURRENCY_SHADOWSTONES           = 29, // RoF
	ALTCURRENCY_DREADSTONES            = 30, // RoF
	ALTCURRENCY_MARKSOFVALOR           = 31, // CoTF
	ALTCURRENCY_MEDALSOFHEROISM        = 32, // CoTF
	ALTCURRENCY_COMMEMORATIVE_COINS    = 33, // VoA
	ALTCURRENCY_FISTSOFBAYLE           = 34, // CoTF
	ALTCURRENCY_NOBLES                 = 35, // EQ
	ALTCURRENCY_ENERGYCRYSTALS         = 36, // TDS
	ALTCURRENCY_PIECESOFEIGHT          = 37, // TDS
	ALTCURRENCY_REMNANTSOFTRANQUILITY  = 38, // TBM
	ALTCURRENCY_BIFURCATEDCOIN         = 39, // TBM
	ALTCURRENCY_ADOPTIVE               = 40, // EQ
	ALTCURRENCY_SATHIRSTRADEGEMS       = 41, // EoK
	ALTCURRENCY_ANCIENTSEBILISIANCOINS = 42, // EoK
	ALTCURRENCY_BATHEZIDTRADEGEMS      = 43, // RoS
	ALTCURRENCY_ANCIENTDRACONICCOIN    = 44, // RoS
	ALTCURRENCY_FETTERREDIFRITCOINS    = 45, // TBL
	ALTCURRENCY_ENTWINEDDJINNCOINS     = 46, // TBL
	ALTCURRENCY_CRYSTALLIZEDLUCK       = 47, // TBL
};

enum MOUSE_DATA_TYPES
{
	MD_Unknown        = -1,
	MD_Button0Click   = 0,
	MD_Button1Click   = 1,
	MD_Button0        = 2,
	MD_Button1        = 3,
};

// KeypressHandler__HandleKeyUp_x has this one
constexpr int nEQMappableCommands = 546;

// found using __BindList_x
constexpr int nNormalEQMappableCommands = nEQMappableCommands - 22;

constexpr int MAX_PC_LEVEL = 110;
constexpr int MAX_NPC_LEVEL = 200;
constexpr int MAX_SPELL_LEVEL = 255;
constexpr int NUM_SPELL_GEMS = 14;
constexpr int NUM_SPELL_SETS = 30;
constexpr int NUM_BUFF_SLOTS = 97;
constexpr int NUM_LONG_BUFFS = 42;
constexpr int NUM_SHORT_BUFFS = 55;
constexpr int NUM_RACES = 17;
constexpr int NUM_BLOCKED_BUFFS = 40;

constexpr int MAX_MEMORIZED_SPELLS = 18;

// need to find this one
constexpr int NUM_ALT_ABILITIES_ARRAY = 503;

// see 4FBD46 in eqgame.exe dated oct 29 2013 test
constexpr int NUM_ALT_ABILITIES = 49999;

// these two will merge when i get a chance - ieatacid wrote this?
constexpr int AA_CHAR_MAX = 245;

// EQ_PC__GetAlternateAbilityId_x
// size is at 7EE7F8 in eqgame dated jun 13 2014
constexpr int AA_CHAR_MAX_REAL = 300;

// found in CSpellBookWnd__GetBookSlot_x (see 7A7DD7 in Nov 29 2017 Beta)
// Find by searching for A1 ? ? ? ? 53 83 CB FF 85 C0 in IDA
constexpr int NUM_BOOK_SLOTS = 960;
constexpr int NUM_COMBAT_ABILITIES = 300;
constexpr int BAG_SLOT_START = 23;
constexpr int NUM_SKILLS = 100;
constexpr int NUM_INNATE = 25;
constexpr int CONCURRENT_SKILLS = 2;

#define EQ_EXPANSION(x)                          (1 << (x - 1))
#define EXPANSION_RoK                            EQ_EXPANSION(1)
#define EXPANSION_SoV                            EQ_EXPANSION(2)
#define EXPANSION_SoL                            EQ_EXPANSION(3)
#define EXPANSION_PoP                            EQ_EXPANSION(4)
#define EXPANSION_LoY                            EQ_EXPANSION(5)
#define EXPANSION_LDoN                           EQ_EXPANSION(6)
#define EXPANSION_GoD                            EQ_EXPANSION(7)
#define EXPANSION_OoW                            EQ_EXPANSION(8)
#define EXPANSION_DoN                            EQ_EXPANSION(9)
#define EXPANSION_DoD                            EQ_EXPANSION(10)
#define EXPANSION_PoR                            EQ_EXPANSION(11)
#define EXPANSION_TSS                            EQ_EXPANSION(12)
#define EXPANSION_TBS                            EQ_EXPANSION(13)
#define EXPANSION_SoF                            EQ_EXPANSION(14)
#define EXPANSION_SoD                            EQ_EXPANSION(15)
#define EXPANSION_UFT                            EQ_EXPANSION(16)
#define EXPANSION_HoT                            EQ_EXPANSION(17)
#define EXPANSION_VoA                            EQ_EXPANSION(18)
#define EXPANSION_RoF                            EQ_EXPANSION(19)
#define EXPANSION_CotF                           EQ_EXPANSION(20)
#define EXPANSION_TDS                            EQ_EXPANSION(21)
#define EXPANSION_TBM                            EQ_EXPANSION(22)
#define EXPANSION_EoK                            EQ_EXPANSION(23)
#define EXPANSION_RoS                            EQ_EXPANSION(24)
#define EXPANSION_TBL                            EQ_EXPANSION(25)
#define EXPANSION_TOV                            EQ_EXPANSION(26)
constexpr int NUM_EXPANSIONS = 26;

// LDON Dungeon themes. This is a bitmask.
constexpr int LDON_None = 0;
constexpr int LDON_DG   = 1;      // deepest guk
constexpr int LDON_MIR  = 2;      // miragul's menagerie
constexpr int LDON_MIS  = 4;      // Mistmoore catacombs
constexpr int LDON_RUJ  = 8;      // rujarkian hills
constexpr int LDON_TAK  = 16;     // takish-hiz

// Camera modes
constexpr int EQ_FIRST_PERSON_CAM = 0;
constexpr int EQ_OVERHEAD_CAM = 1;
constexpr int EQ_CHASE_CAM = 2;
constexpr int EQ_USER_CAM_1 = 3;
constexpr int EQ_USER_CAM_2 = 4;

// Spell targeting types
constexpr int TT_PBAE = 4;
constexpr int TT_TARGETED_AE = 8;
constexpr int TT_AE_PC_V2 = 40;
constexpr int TT_DIRECTIONAL = 42;
constexpr int TT_SPLASH = 45;

constexpr char* KeyRingWindowParent = "KeyRingWnd";
constexpr char* MountWindowList = "KRW_Mounts_List";
constexpr char* IllusionWindowList = "KRW_Illusions_List";
constexpr char* FamiliarWindowList = "KRW_Familiars_list";
constexpr char* HeroForgeWindowList = "KRW_HeroForge_List";
constexpr char* KeyRingTab = "KRW_Subwindows";

enum ETargetRelationship
{
	eTargetNone        = 0,
	eTargetSelf,
	eTargetPet,
	eTargetMyPet,
	eTargetMyMercenary,
	eTargetGroup,
	eTargetOtherPC,
	eTargetOtherMercenary,
	eTargetOtherNPC
};

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

enum ePetCommandType
{
	PCT_ReportHealth,
	PCT_WhoLeader,
	PCT_Attack,
	PCT_QueueAttack,
	PCT_ToggleFollow,
	PCT_ToggleGuard,
	PCT_ToggleSit,
	PCT_SitOn,
	PCT_SitOff,
	PCT_ToggleStop,
	PCT_StopOn,
	PCT_StopOff,
	PCT_ToggleTaunt,
	PCT_TauntOn,
	PCT_TauntOff,
	PCT_ToggleHold,
	PCT_HoldOn,
	PCT_HoldOff,
	PCT_ToggleGHold,
	PCT_GHoldOn,
	PCT_GHoldOff,
	PCT_ToggleSpellHold,
	PCT_SpellHoldOn,
	PCT_SpellHoldOff,
	PCT_ToggleFocus,
	PCT_FocusOn,
	PCT_FocusOff,
	PCT_FeignDeath,
	PCT_BackOff,
	PCT_GetLost,
	PCT_TargetPet,
	PCT_ToggleRegroup,
	PCT_RegroupOn,
	PCT_RegroupOff,
	PCT_Something,
	PCT_Something2,
	PCT_DoNothing
};

enum eMembershipLevel
{
	MembershipFreeToPlay = 0,
	MembershipSilver,
	MembershipGold
};

template <typename T>
inline int EQHeading(T heading)
{
	return static_cast<int>((((heading + 16) % 256) / 32) * 2);
}

// ***************************************************************************
// Structures
// ***************************************************************************

class PopDialogHandler
{
public:
	virtual void DialogResponse(int, int, void*);
};

struct MOUSESPOOF
{
	MOUSE_DATA_TYPES   mdType;
	DWORD              dwData;
	MOUSESPOOF*        pNext;
};

struct MOUSECLICK {
	BYTE Confirm[8];         // DO NOT WRITE TO THIS BYTE
	BYTE Click[8];          // Left = 0, Right = 1, etc
};
using PMOUSECLICK = MOUSECLICK*;

struct [[offsetcomments]] LEADERABILITIES
{
	FORCE_SYMBOLS;

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
/*0x3c*/
};
using PLEADERABILITIES = LEADERABILITIES*;

struct [[offsetcomments]] USINGSKILL
{
/*0x00*/ int       Skill;
/*0x04*/ void*     Target;
/*0x08*/
};
using PUSINGSKILL = USINGSKILL*;

struct [[offsetcomments]] EQCAMERABASE
{
/*0x00*/ void* vftable;
/*0x04*/ float Y;
/*0x08*/ float X;
/*0x0c*/ float Z;
/*0x10*/ float Orientation_Y;                   // old name Heading
/*0x14*/ float Orientation_X;                   // old name LookAngle
/*0x18*/ float Orientation_Z;
/*0x1c*/ float OldPosition_Y;
/*0x20*/ float OldPosition_X;
/*0x24*/ float OldPosition_Z;
/*0x28*/ float Heading;
/*0x2c*/ float Height;
/*0x30*/ float Pitch;
/*0x34*/ float Distance;
/*0x38*/ float DirectionalHeading;
/*0x3c*/ float SideMovement;
/*0x40*/ float Zoom;                            // old name: ViewAngle
/*0x44*/ bool  bAutoPitch;
/*0x45*/ bool  bAutoHeading;
/*0x46*/ bool  bSkipFrame;
/*0x48*/
};
using PEQCAMERABASE = EQCAMERABASE*;

#define MODEL_LABEL                              0
#define MODEL_LABELINFO                          1
#define MODEL_NULL2                              2
#define MODEL_HELD_R                             3
#define MODEL_HELD_L                             4
#define MODEL_SHIELD                             5
#define MODEL_NULL6                              6

#if 0
// Work in progress...
#define MODEL_HEAD                               0x00
#define MODEL_HEAD_POINT                         0x01
#define MODEL_NULL_1                             0x02
#define MODEL_HELD_R                             0x03
#define MODEL_HELD_L                             0x04
#define MODEL_SHIELD                             0x05
#define MODEL_NULL_2                             0x06
#define MODEL_TUNIC                              0x07
#define MODEL_HAIR                               0x08
#define MODEL_BEARD                              0x09
#define MODEL_CHEST                              0x0a
#define MODEL_GLOVES                             0x0b
#define MODEL_GLOVES2                            0x0c
#endif

// This is the # of spell gems + 1 (zero-based)
constexpr int InnateETA = 12;

enum InvisibleTypes
{
	eAll,
	eUndead,
	eAnimal
};

#define STANDSTATE_STAND                         0x64
#define STANDSTATE_CASTING                       0x66
#define STANDSTATE_BIND                          0x69
#define STANDSTATE_SIT                           0x6E
#define STANDSTATE_DUCK                          0x6F
#define STANDSTATE_FEIGN                         0x73
#define STANDSTATE_DEAD                          0x78

#define MONITOR_SPAWN_X                          1
#define MONITOR_SPAWN_Y                          2
#define MONITOR_SPAWN_Z                          4
#define MONITOR_SPAWN_HEADING                    8
#define MONITOR_SPAWN_SPEEDRUN                   16
#define MONITOR_SPAWN_HPCURRENT                  32

struct SPAWNMONITORINFO
{
	WORD SpawnID;
	float Y;
	float X;
	float Z;
	float Heading;
	float SpeedRun;
	DWORD HPCurrent;
	DWORD MonitorMask;
};
using PSPAWNMONITORINFO = SPAWNMONITORINFO*;

// copy of D3DMATRIX by brainiac dec 16 2015
struct Matrix4x4
{
	union {
		struct {
			float        _11, _12, _13, _14;
			float        _21, _22, _23, _24;
			float        _31, _32, _33, _34;
			float        _41, _42, _43, _44;
		};
		float m[4][4];
	};
};

struct SWITCHCLICK
{
	float Y;
	float X;
	float Z;
	float Y1;
	float X1;
	float Z1;
};
using PSWITCHCLICK = SWITCHCLICK*;

enum eMemPoolType
{
	eGlobal,
	eOnDemand,
	eClearOnZone,
};

// this is actually a CActor Class
// actual size: 0x120 3-3-2009
// Size is 0x190 dec 13 2016 live - eqmule
// see Cactor::CActor in EQGraphicsDX9.dll
struct [[offsetcomments]] EQSWITCH
{
/*0x000*/ void*         vfTable;
/*0x004*/ eMemPoolType  MemType;
/*0x008*/ bool          bIsS3DCreated;
/*0x009*/ bool          bHasParentBone;
/*0x00a*/ bool          bUpdateScaledAmbient;
/*0x00c*/ float         ScaledAmbient;
/*0x010*/ float         ScaledAmbientTarget;
/*0x014*/ float         ParticleScaleFactor;
/*0x018*/ float         CollisionSphereScaleFactor;
/*0x01c*/ UINT          UpdateAmbientTick;
/*0x020*/ UINT          InterpolateAmbientTick;
/*0x024*/ void*         pParentActor;             // its a  CActor*
/*0x028*/ void*         pDPVSObject;
/*0x02c*/ float         Y;
/*0x030*/ float         X;
/*0x034*/ float         Z;
/*0x038*/ float         SurfaceNormalY;
/*0x03c*/ float         SurfaceNormalX;
/*0x040*/ float         SurfaceNormalZ;
/*0x044*/ UINT          VisibleIndex;
/*0x048*/ float         Alpha;
/*0x04c*/ bool          bCastShadow;
/*0x04d*/ bool          bNeverClip;
/*0x04e*/ bool          bClientCreated;
/*0x050*/ float         ZOffset;
/*0x054*/ float         EmitterScalingRadius;
/*0x058*/ void*         pDuplicateActor;          // its a  CActor*
/*0x05c*/ bool          bShowParticlesWhenInvisible;
/*0x060*/ void*         pAreaPortalVolumeList;    // CAreaPortalVolumeList*
/*0x064*/ void*         CleanupList;              // a TListNode<CActor*>? not sure
/*0x068*/ BYTE          CleanupListFiller[0xc];
/*0x074*/ void*         pActorApplicationData;    // CActorApplicationData* 74 for sure see 1003AE70
/*0x078*/ EActorType    ActorType;
/*0x07c*/ void*         pTerrainObject;           // CTerrainObject*
/*0x080*/ void*         HighlightData;            // HighlightData*
/*0x084*/ float         yAdjustment1;             // from this point on im not sure - 2013 dec 16
/*0x088*/ float         xAdjustment1;
/*0x08c*/ float         zAdjustment1;
/*0x090*/ float         headingAdjustment1;
/*0x094*/ float         yAdjustment2;
/*0x098*/ float         xAdjustment2;
/*0x09c*/ float         zAdjustment2;
/*0x0a0*/ float         headingAdjustment2;
/*0x0a4*/ float         yAdjustment3;
/*0x0a8*/ float         xAdjustment3;
/*0x0ac*/ float         zAdjustment3;
/*0x0b0*/ float         headingAdjustment3;
/*0x0b4*/ float         adjustments4[3];
/*0x0c0*/ float         adjustments5[4];
/*0x0d0*/ bool          bbHasAttachSRT;
/*0x0d1*/ bool          bDisableDesignOverride;
/*0x0d4*/ int           Unknown0xd4[4];
/*0x0e4*/ Matrix4x4     transformMatrix;          // used for new armor
/*0x124*/ float         Heading;
/*0x128*/ BYTE          Unknown0x12c[0x14];
/*0x13c*/ float         HeightAdjustment;         // this is most likely wrong dec 16 2013 eqmule
/*0x140*/ BYTE          Unknown0x144[0x4c];
/*0x18c*/
};
using PEQSWITCH = EQSWITCH*;

// Size is 0xe0 see 54933E in dec 13 2016 live - eqmule
// This is actually EQSwitch
struct [[offsetcomments]] DOOR
{
/*0x00*/ void*         vtable;
/*0x04*/ BYTE          ObjType;                  // always 5
/*0x05*/ BYTE          ID;
/*0x06*/ char          Name[0x20];
/*0x26*/ BYTE          Type;
/*0x27*/ BYTE          State;                    // 0 = closed, 1 = open, 2 = opening, 3 = closing
/*0x28*/ float         DefaultY;
/*0x2c*/ float         DefaultX;
/*0x30*/ float         DefaultZ;
/*0x34*/ float         DefaultHeading;
/*0x38*/ float         DefaultDoorAngle;
/*0x3c*/ float         TopSpeed1;
/*0x40*/ float         TopSpeed2;
/*0x44*/ float         Y;
/*0x48*/ float         X;
/*0x4c*/ float         Z;
/*0x50*/ float         Heading;
/*0x54*/ float         DoorAngle;
/*0x58*/ BYTE          DefaultState;
/*0x59*/ BYTE          SelfActivated;
/*0x5a*/ BYTE          Dependent;
/*0x5b*/ bool          bTemplate;
/*0x5c*/ BYTE          Difficulty;               // pick/disarm...
/*0x5d*/ BYTE          AffectSlots[5];
/*0x62*/ BYTE          CurrentCombination[5];
/*0x67*/ BYTE          ReqCombination[5];
/*0x6c*/ BYTE          RandomCombo;
/*0x70*/ int           Key;
/*0x74*/ SHORT         ScaleFactor;              // divide by 100 to get scale multiplier
/*0x78*/ int           SpellID;
/*0x7c*/ BYTE          TargetID[0x5];
/*0x81*/ char          Script[0x20];
/*0xa4*/ PEQSWITCH     pSwitch;                  // (CActorInterface*)
/*0xa8*/ void*         particle;                 // (CParticleCloudInterface*)
/*0xac*/ DWORD         TimeStamp;                // last time UseSwitch
/*0xb0*/ float         Accel;
/*0xb4*/ BYTE          AlwaysActive;
/*0xb8*/ int           AdventureDoorID;
/*0xbc*/ float         ReturnY;
/*0xc0*/ float         ReturnX;
/*0xc4*/ float         ReturnZ;
/*0xc8*/ int           DynDoorID;
/*0xcc*/ bool          bHasScript;
/*0xd0*/ int           SomeID;
/*0xd4*/ bool          bUsable;
/*0xd5*/ bool          bRemainOpen;
/*0xd6*/ bool          bVisible;
/*0xd7*/ bool          bHeadingChanged;
/*0xd8*/ bool          bAllowCorpseDrag;
/*0xdc*/ int           RealEstateDoorID;
/*0xe0*/

	// Currently necessary because of MQ2DataTypes
	DOOR() { ZeroMemory(this, sizeof(DOOR)); }
};
using PDOOR = DOOR*;

// This is EqSwitchManager
struct [[offsetcomments]] DOORTABLE
{
/*0x000*/ int   NumEntries;
/*0x004*/ PDOOR pDoor[0x0FF];
/*0x400*/
};
using PDOORTABLE = DOORTABLE*;

// actual size 0x80 20101012 - ieatacid
struct [[offsetcomments]] GROUNDITEM
{
/*0x00*/ GROUNDITEM*         pPrev;
/*0x04*/ GROUNDITEM*         pNext;
/*0x08*/ VePointer<CONTENTS> ID;                 // well its not an int but plugins use this as one so ill keep the name
/*0x0c*/ DWORD               DropID;             // unique id
/*0x10*/ DWORD               ZoneID;
/*0x14*/ DWORD               DropSubID;          // well zonefile id, but yeah...
/*0x18*/ PEQSWITCH           pSwitch;            // (class EQSwitch *)
/*0x1c*/ char                Name[0x40];
/*0x5c*/ long                Expires;
/*0x60*/ float               Heading;
/*0x64*/ float               Pitch;
/*0x68*/ float               Roll;
/*0x6c*/ float               Scale;
/*0x70*/ float               Y;
/*0x74*/ float               X;
/*0x78*/ float               Z;
/*0x7c*/ int                 Weight;             // -1 means it can't be picked up
/*0x80*/
};
using PGROUNDITEM = GROUNDITEM*;

enum eGroundObject
{
	GO_None,
	GO_GroundType,
	GO_ObjectType
};

struct [[offsetcomments]] GROUNDOBJECT
{
/*0x00*/ eGroundObject            Type;
/*0x04*/ GROUNDITEM               GroundItem;         // for conversion between switch and gorunditems
/*0x84*/ void*                    ObjPtr;             // EQPlacedItem *
/*0x88*/ PGROUNDITEM              pGroundItem;
/*0x8c*/

	// Currently necessary because of MQ2DataTypes
	GROUNDOBJECT() { ZeroMemory(this, sizeof(GROUNDOBJECT)); }
};
using PGROUNDOBJECT = GROUNDOBJECT*;

constexpr int MAX_ZONES = 1000; // 0x3e8

extern char* szZoneExpansionName[];              // defined in LibEQ_Utilities.cpp

// Size 0x1D8 see 867D39 in eqgame.exe live 21 apr 2016 - eqmule
struct [[offsetcomments]] ZONELIST
{
/*0x000*/ DWORD              Header;
/*0x004*/ DWORD              Unknown0x4;         // pointer to something?
/*0x008*/ DWORD              EQExpansion;        // szZoneExpansionName[]
/*0x00c*/ DWORD              Id;                 // EQZoneIndex
/*0x010*/ char               ShortName[0x80];
/*0x090*/ BYTE               Unknown0x090;
/*0x091*/ char               LongName[0x100];
/*0x194*/ DWORD              Unknown0x191;
/*0x198*/ DWORD              Unknown0x192[0x6];
/*0x1b0*/ DWORD              ZoneFlags;          // 0x800000 = gmzone? 0x8000 water/mountainzone? 0x4 = ? 0x1 = MultiInstanceZone 0x10000000 bazaarzone 0x2000000 = barterzone 0x100000 = HasMinLevel, 0x1000000 = tutorialzone 0x4000 = no air, 0x2 newbie zone, 0x20 no bind, 0x400000 lostestingdisabled, 0x80000000 guildhallzone
/*0x1b4*/ DWORD              Unknown0x19c;
/*0x1b8*/ DWORD              eqstrID;            // can call pStringTable->getString to get this string
/*0x1bc*/ DWORD              PoPValue;           // This has something to do with PoP zones.
/*0x1c0*/ DWORD              MinLevel;           // Minimum level to access is this used?
/*0x1c4*/ BYTE               Unknown0x1ac[0x8];
/*0x1cc*/ BYTE               Unknown0x1b4;
/*0x1cd*/ BYTE               Unknown0x1b5[0x3];
/*0x1d0*/ BYTE               Unknown0x1b8[0x20];
/*0x1f0*/
};
using PZONELIST = ZONELIST*;

// EQWorldData__EQWorldData_x
// Size 0xFC0 see 5721F1 in eqgame.exe live 21 apr 2016 - eqmule
struct [[offsetcomments]] WORLDDATA
{
/*0x000*/ void*        lpvTable;
/*0x004*/ BYTE         Hour;
/*0x005*/ BYTE         Minute;
/*0x006*/ BYTE         Day;
/*0x007*/ BYTE         Month;
/*0x008*/ int          Year;
/*0x00c*/ BYTE         LastHour;
/*0x00d*/ BYTE         LastMinute;
/*0x00e*/ BYTE         LastDay;
/*0x00f*/ BYTE         LastMonth;
/*0x010*/ int          LastYear;
/*0x014*/ UINT         LastAdvance;
/*0x018*/ UINT         LastTime;
/*0x01c*/ UINT         Unknown0x01C;
/*0x020*/ PZONELIST    ZoneArray[MAX_ZONES];     // see 867D1B in eqgame.exe live 21 apr 2016
/*0xfc0*/
};
using PWORLDDATA = WORLDDATA*;

enum EOutDoor : BYTE
{
	IndoorDungeon,                               // Zones without sky SolB for example.
	Outdoor,                                     // Zones with sky like Commonlands for example.
	OutdoorCity,                                 // A Player City with sky Plane of Knowledge for example.
	DungeonCity,                                 // A Player City without sky Ak'anon for example.
	IndoorCity,                                  // A Player City without sky Erudin for example.
	OutdoorDungeon,                              // Dungeons with sky like Blackburrow for example.
};

enum EPlace
{
	CannotPlace,
	CanOnlyPlace,
	CanPlaceAndGoto,
};

// Size 0x3a8 see F17224-F16E7C in eqgame.exe live 17 Jan 2017 - eqmule
struct [[offsetcomments]] ZONEINFO
{
/*0x000*/ char         CharacterName[0x40];
/*0x040*/ char         ShortName[0x80];
/*0x0c0*/ char         LongName[0x80];
/*0x140*/ char         ZoneDesc[0x5][0x1e];  //zone description strings
/*0x1d6*/ BYTE         FogOnOff; // (usually FF)
/*0x1d8*/ ARGBCOLOR    FogRed;
/*0x1dc*/ ARGBCOLOR    FogGreen;
/*0x1e0*/ ARGBCOLOR    FogBlue;
/*0x1e4*/ float        FogStart[0x4]; //fog distance
/*0x1f4*/ float        FogEnd[0x4];
/*0x204*/ float        ZoneGravity;
/*0x208*/ EOutDoor     OutDoor;//this is what we want instead of ZoneType, see the enum
/*0x209*/ BYTE         RainChance[0x4];//no u cant change these to dwords cause then u screw up 4 byte padding
/*0x20d*/ BYTE         RainDuration[0x4];
/*0x211*/ BYTE         SnowChance[0x4];
/*0x215*/ BYTE         SnowDuration[0x4];
/*0x219*/ char         ZoneTimeZone;   //in hours from worldserver, can be negative
/*0x21a*/ BYTE         SkyType;   //1 means active
/*0x21c*/ int          WaterMidi;   //which midi to play while underwater
/*0x220*/ int          DayMidi;
/*0x224*/ int          NightMidi;
/*0x228*/ float        ZoneExpModifier;    //This has been nerfed ..now reads 1.0 for all zones
/*0x22c*/ float        SafeXLoc;
/*0x230*/ float        SafeYLoc;
/*0x234*/ float        SafeZLoc;
/*0x238*/ float        SafeHeading;
/*0x23c*/ float        Ceiling;
/*0x240*/ float        Floor;
/*0x244*/ float        MinClip;
/*0x248*/ float        MaxClip;
/*0x24c*/ int          ForageLow; //Forage skill level needed to get stuff
/*0x250*/ int          ForageMedium;
/*0x254*/ int          ForageHigh;
/*0x258*/ int          FishingLow; //Fishing skill level needed to get stuff
/*0x25c*/ int          FishingMedium;
/*0x260*/ int          FishingHigh;
/*0x264*/ int          SkyRelated; //0-24 i think
/*0x268*/ UINT         GraveyardTimer; //minutes until corpse(s) pops to graveyard
/*0x26c*/ int          ScriptIDHour;
/*0x270*/ int          ScriptIDMinute;
/*0x274*/ int          ScriptIDTick;
/*0x278*/ int          ScriptIDOnPlayerDeath;
/*0x27c*/ int          ScriptIDOnNPCDeath;
/*0x280*/ int          ScriptIDPlayerEnteringZone;
/*0x284*/ int          ScriptIDOnZonePop;
/*0x288*/ int          ScriptIDNPCLoot;
/*0x28c*/ int          ScriptIDAdventureFailed;
/*0x290*/ int          CanExploreTasks;
/*0x294*/ int          UnknownFlag;
/*0x298*/ int          ScriptIDOnFishing;
/*0x29c*/ int          ScriptIDOnForage;
/*0x2a0*/ char         SkyString[0x20]; //if empty no sky, ive only seen this as the zone name
/*0x2c0*/ char         WeatherString[0x20]; //if empty no weather
/*0x2e0*/ char         SkyString2[0x20]; //if SkyString is empty this is checked
/*0x300*/ int          SkyRelated2; //0-24
/*0x304*/ char         WeatherString2[0x20]; //if empty no weather
/*0x324*/ float        WeatherChangeTime;
/*0x328*/ int          Climate;
/*0x32c*/ int          NPCAgroMaxDist; //the distance needed for an npc to lose agro after an attack
/*0x330*/ int          FilterID; //found in the teleport table
/*0x334*/ int          ZoneID;
/*0x338*/ int          ScriptNPCReceivedanItem;
/*0x33c*/ bool         bCheck;
/*0x340*/ int          ScriptIDSomething;
/*0x344*/ int          ScriptIDSomething2;
/*0x348*/ int          ScriptIDSomething3;
/*0x34c*/ bool         bNoBuffExpiration;//this is checked serverside so no, u cant and shouldn't set this if u value your account
/*0x350*/ int          LavaDamage; //before resists
/*0x354*/ int          MinLavaDamage; //after resists
/*0x358*/ bool         bDisallowManaStone; //can a manastone be used here?
/*0x359*/ bool         bNoBind;
/*0x35a*/ bool         bNoAttack;
/*0x35b*/ bool         bNoCallOfHero;
/*0x35c*/ bool         bNoFlux;
/*0x35d*/ bool         bNoFear;
/*0x35e*/ bool         bNoEncumber;
/*0x360*/ int          FastRegenHP;//not exactly sure how these work but ome zones have these set
/*0x364*/ int          FastRegenMana;
/*0x368*/ int          FastRegenEndurance;
/*0x36c*/ EPlace       CanPlaceCampsite;
/*0x370*/ EPlace       CanPlaceGuildBanner;
/*0x374*/ float        FogDensity;
/*0x378*/ bool         bAdjustGamma;
/*0x37c*/ int          TimeStringID;
/*0x380*/ bool         bNoMercenaries;
/*0x384*/ int          FishingRelated;
/*0x388*/ int          ForageRelated;
/*0x38c*/ bool         bNoLevitate;
/*0x390*/ float        Blooming;
/*0x394*/ bool         bNoPlayerLight;
/*0x398*/ int          GroupLvlExpRelated;
/*0x39c*/ BYTE         PrecipitationType;
/*0x39d*/ bool         bAllowPVP;
/*0x3a0*/
};
using PZONEINFO = ZONEINFO*;

// actual size: 0x148 04-11-2017 test confirmed see 5F7150
enum eSkillCombatType
{
	SCT_NonCombat,
	SCT_Combat,
	SCT_Special
};

struct [[offsetcomments]] SKILL
{
/*0x000*/ int               ImageNumber;
/*0x004*/ int               ImageDep;
/*0x008*/ DWORD             nName;
/*0x00c*/ DWORD             ReuseTimer;
/*0x010*/ DWORD             BaseDamage;
/*0x014*/ eSkillCombatType  SkillCombatType;
/*0x018*/ int               EnduranceCost;
/*0x01c*/ float             Force;
/*0x020*/ bool              Activated;
/*0x021*/ bool              LevelCappedSkill;
/*0x024*/ DWORD             MinLevel[0x24];      // the level each class gains this skill
/*0x0b4*/ DWORD             Available[0x24];     // FF=not available for that class (its actually how difficult it is to learn... low num easy, high hard...)
/*0x144*/ bool              bSkillupable;
/*0x148*/
};
using PSKILL = SKILL*;

constexpr int MAX_SKILL_CLASSES = 36;

// see SkillManager__IsValidSkillIndex_x (5C87C0) in eqgame dated 20140611
// SkillManager__SkillManager
// Actual Size: 0x2E9B2C see 571E37 in eqgame dated 20170411 test
struct [[offsetcomments]] SKILLMGR
{
	FORCE_SYMBOLS;
/*0x000000*/ SKILL*    pSkill[NUM_SKILLS];
/*0x000190*/ int       SkillCaps[MAX_SKILL_CLASSES][NUM_SKILLS][MAX_PC_LEVEL+1];
/*0x186550*/ float     SkillMods[MAX_SKILL_CLASSES][NUM_SKILLS][MAX_PC_LEVEL+1];
/*0x30c910*/ char      SkillCapsFilename[MAX_PATH];
/*0x30ca14*/ UINT      SkillLastUsed[NUM_SKILLS];
/*0x30cba4*/ UINT      SkillTimerDuration[NUM_SKILLS];
/*0x30cd34*/ UINT      CombatSkillLastUsed[CONCURRENT_SKILLS];
/*0x30cd3c*/ UINT      CombatSkillDuration[CONCURRENT_SKILLS];
/*0x30cd44*/ bool      bSkillCanUse[NUM_SKILLS];
/*0x30cda8*/ bool      bCombatSkillCanUse[CONCURRENT_SKILLS];
/*0x30cdac*/
};
using PSKILLMGR = SKILLMGR*;

struct AUTOSKILL
{
	int Skill[CONCURRENT_SKILLS];
};
using PAUTOSKILL = AUTOSKILL*;

// Same as SKILLMGR
class [[offsetcomments]] SkillManager
{
	FORCE_SYMBOLS;

public:
/*0x000000*/ TSafeArrayStatic<PSKILL, NUM_SKILLS> pSkill;
/*0x000190*/ int       SkillCaps[0x24][NUM_SKILLS][MAX_PC_LEVEL+1];
/*0x186550*/ float     SkillMods[0x24][NUM_SKILLS][MAX_PC_LEVEL+1];
/*0x30c910*/ char      SkillCapsFilename[MAX_PATH];
/*0x30ca14*/ UINT      SkillLastUsed[NUM_SKILLS];
/*0x30cba4*/ UINT      SkillTimerDuration[NUM_SKILLS];
/*0x30cd34*/ UINT      CombatSkillLastUsed[CONCURRENT_SKILLS];
/*0x30cd3c*/ UINT      CombatSkillDuration[CONCURRENT_SKILLS];
/*0x30cd44*/ bool      bSkillCanUse[NUM_SKILLS];
/*0x30cda8*/ bool      bCombatSkillCanUse[CONCURRENT_SKILLS];
/*0x30cdac*/
};

struct [[offsetcomments]] GUILDDATA
{
	FORCE_SYMBOLS;

/*0x00*/ char   Name[0x40];
/*0x40*/ DWORD  ID;
/*0x44*/
};
using PGUILDDATA = GUILDDATA*;

struct [[offsetcomments]] GUILD
{
/*0x00*/ char                Name[0x40];
/*0x40*/ DWORD               ID;                 // maybe this is just a int64 now, not sure needs more investigation.
/*0x44*/ DWORD               ID2;
/*0x48*/ GUILD*              pNext;
/*0x4c*/ GUILD*              pPrev;
/*0x50*/
};
using PGUILD = GUILD*;

// 11-15-11 - ieatacid
// aUnknownGuild the offset below is the guild vftable
// 2016 Oct 11 beta - eqmule (see AB50E4) not sure on size needs more investigation
struct [[offsetcomments]] GUILDS
{
/*0x0000*/ void*             pOneEntryVTable;
/*0x0004*/ BYTE              Unknown0x4[0x4];
/*0x0008*/ DWORD             GuildMemberCount;
/*0x000c*/ GuildMember*      pMember;
/*0x0010*/ BYTE              Unknown0x10[0x51];
/*0x0061*/ char              GuildMotD[0x200];
/*0x0261*/ char              GuildLeader[0x40];
/*0x02a1*/ BYTE              Unknown0x2a1[0x3];
/*0x02a4*/ DWORD             GuildTribute;
/*0x02a8*/ BYTE              Unknown0x2a8[0x8dc1];
/*0x9069*/ char              GuildUrl[0x200];
/*0x9269*/ char              GuildChannelName[0x80];
/*0x92e9*/ BYTE              Unknown0x9e9[0x2f];
/*0x9318*/ GUILD*            pFirst;
/*0x931c*/ GUILD*            pLast;
/*0x9320*/ UINT              GuildListCount;
/*0x9324*/ DWORD             Empty;
/*0x9328*/ GUILD*            GuildList;
/*0x932c*/ DWORD             HashValue;
/*0x9330*/
};
using PGUILDS = GUILDS*;

struct [[offsetcomments]] INTERACTGROUNDITEM
{
	FORCE_SYMBOLS;

/*0x00*/ DWORD DropID;
/*0x04*/ DWORD SpawnID;
/*0x08*/
};
using PINTERACTGROUNDITEM = INTERACTGROUNDITEM;

constexpr int MAX_SPELL_LOADOUT_NAME = 24;

struct [[offsetcomments]] SpellLoadout
{
/*0x00*/ int  SpellId[NUM_SPELL_GEMS];
/*0x38*/ char Name[MAX_SPELL_LOADOUT_NAME + 1];
/*0x51*/ bool inuse;
/*0x52*/ bool changed;
/*0x54*/
};
using SPELLFAVORITE [[deprecated("Use SpellLoadout instead")]] = SpellLoadout;
using PSPELLFAVORITE [[deprecated("Use SpellLoadout* instead")]] = SpellLoadout*;

struct [[offsetcomments]] CMDLIST
{
/*0x00*/ DWORD LocalizedStringID;
/*0x04*/ char* szName;
/*0x08*/ char* szLocalized;
/*0x0c*/ void  (*fAddress)(PSPAWNINFO, char*);
/*0x10*/ DWORD Restriction;
/*0x14*/ DWORD Category;
/*0x18*/ DWORD Flags;
/*0x1c*/
};
using PCMDLIST = CMDLIST*;

struct [[offsetcomments]] EQSOCIAL
{
/*0x000*/ char Name[0x10];
/*0x010*/ char Line[0x5][0x100];
/*0x510*/ BYTE Color;
/*0x514*/ UINT TimerBegin;
/*0x518*/ UINT TimerDuration;
/*0x51c*/
};
using PEQSOCIAL = EQSOCIAL*;

struct [[offsetcomments]] EQFRIENDSLIST
{
	FORCE_SYMBOLS;

/*0x0000*/ char Name[0x64][0x40];
/*0x1900*/
};
using PEQFRIENDSLIST = EQFRIENDSLIST*;

struct [[offsetcomments]] AAEFFECTDATA
{
	FORCE_SYMBOLS;

/*0x00*/ int EffectType;
/*0x04*/ int BaseEffect1;
/*0x08*/ int BaseEffect2;
/*0x0c*/ int Slot;
/*0x10*/
};
using PAAEFFECTDATA = AAEFFECTDATA*;

// Size 0xa4    11/15/2011 ieatacid in msg_send_alt_data
// Size 0xa8    06/11/2014 eqmule in msg_send_alt_data
// Size 0xa8    See 4EF12F (msg_send_alt_data) in 2015-09-24
class [[offsetcomments]] CAltAbilityData
{
public:
/*0x00*/ DWORD         Index;
/*0x04*/ bool          bShowInAbilityWindow;               // [0] = enabled flag? everything 1
/*0x05*/ BYTE          bShowInAbilityWindowdPadding[0x3];
/*0x08*/ DWORD         nShortName;
/*0x0c*/ DWORD         nShorterName;
/*0x10*/ DWORD         nName;                              // now a database number
/*0x14*/ DWORD         nDesc;                              // now a database number
/*0x18*/ DWORD         MinLevel;                           // LevelNeeded
/*0x1c*/ DWORD         Cost;                               // Initial Cost or cost the last time you bought a level of it
/*0x20*/ DWORD         ID;                                 // ID of the AA group (/alt activate id)
/*0x24*/ DWORD         CurrentRank;                        // GroupLevel the current rank of this AA first rank is 1 etc
/*0x28*/ DWORD*        RequiredGroups;                     // array of required groups
/*0x2c*/ DWORD*        RequiredGroupLevels;                // array of required group ID;
/*0x30*/ DWORD         Unknown0x30[2];                     // ArrayClass stuff
/*0x38*/ DWORD         prereq_count2;                      // count of next array, which contains rank required
/*0x3c*/ DWORD*        RequiresAbilityPoints;              // this is part of their ArrayClass
/*0x40*/ DWORD         Unknown0x40;                        // ArrayClass stuff
/*0x44*/ DWORD         pointer;                            // ArrayClass stuff
/*0x48*/ DWORD         Type;                               // 1 General 2 Archetype 3 Class 4 special 5 focus
/*0x4c*/ int           SpellID;                            // -1 for no Spell
/*0x50*/ DWORD         Unknown0x50;
/*0x54*/ DWORD         Unknown0x54;                        // this uses the same class as prereqs, so count?
/*0x58*/ DWORD*        reuse_id;
/*0x5c*/ bool          bRefund;
/*0x5d*/ BYTE          bRefundPadding[0x3];
/*0x60*/ DWORD*        TimerIds;                           // ArrayClass of timer ids starts here
/*0x64*/ DWORD         ReuseTimer;                         // in seconds
/*0x68*/ DWORD         Classes;                            // Classes/2 is the actual value we want.
/*0x6c*/ DWORD         MaxRank;                            // so like x/25, this is the 25
/*0x70*/ DWORD         TotalPoints;
/*0x74*/ DWORD         PreviousGroupAbilityId;             // -1 if none, although sometimes it can be -1 when there is ...
/*0x78*/ DWORD         NextGroupAbilityId;                 // ID of the next rank
/*0x7c*/ bool          QuestOnly;                          // vet AA, quest AA
/*0x7d*/ BYTE          QuestOnlypadding[0x3];
/*0x80*/ DWORD         max_charges;                        // charges on expendable AAs (limited use aa's)
/*0x84*/ BOOL          bIgnoreDeLevel;
/*0x88*/ DWORD         Expansion;
/*0x8c*/ DWORD         special_category;                   // 7 is expendable, -1 none
/*0x90*/ bool          bShroud;                            // shrouds are also called "templates"
/*0x91*/ bool          bBetaOnlyAbility;
/*0x92*/ bool          bResetOnDeath;                      // true for lay on hands for example.
/*0x93*/ bool          bAutogrant;                         // true if its an autogrant ability? or if auto grant is enabled? need to check cause this could be useful
/*0x94*/ DWORD         AutoGrantAssociationId;             // Usually the same as normal expansion if enabled
	// this is where a list of Ability Effect Data starts in the packet
/*0x98*/ DWORD         effects_count;                      // Count of spell effects for AA
/*0x9c*/ DWORD**       effects;                            // this is repeated a few times some times depending on list size
/*0xa0*/ BYTE          Unknown0xA0[0x8];                   // part of their internal list class, I need to re that at some point
/*0xa8*/

	EQLIB_OBJECT int GetMercCurrentRank(int);
	EQLIB_OBJECT int GetMercMaxRank(int);
	EQLIB_OBJECT int GetMaxRank();
};
using ALTABILITY = CAltAbilityData;
using PALTABILITY = CAltAbilityData*;

struct [[offsetcomments]] ALTABILITIESLISTMGR
{
	FORCE_SYMBOLS;

/*0x00*/ ALTABILITY* Ability;
/*0x04*/ DWORD Index;
/*0x08*/
};
using PALTABILITIESLISTMGR = ALTABILITIESLISTMGR*;

// NUM_ALT_ABILITIES is now defined before CHARINFO definition in this same header file.
struct [[offsetcomments]] ALTABILITIESLIST
{
	FORCE_SYMBOLS;

/*0x000*/ ALTABILITIESLISTMGR* Abilities[NUM_ALT_ABILITIES_ARRAY];
/*0x7dc*/
};
using PALTABILITIESLIST = ALTABILITIESLIST*;

struct [[offsetcomments]] NEWALTADVMGR
{
	FORCE_SYMBOLS;

/*0x00*/ ALTABILITIESLIST*   AltAbilityList;
/*0x04*/ DWORD               NumAltAbilities;    // NUM_ALT_ABILITIES
/*0x08*/ DWORD               Unknown0x08;        // data here
/*0x0c*/ DWORD               Unknown0x0c;        // data here
/*0x10*/ BYTE                Unknown0x10[0x8];
/*0x18*/
};
using PNEWALTADVMGR = NEWALTADVMGR*;

struct [[offsetcomments]] ALTADVMGR
{
	FORCE_SYMBOLS;

/*0x00*/ NEWALTADVMGR* AltAbilities;
/*0x04*/
};
using PALTADVMGR = ALTADVMGR*;

struct [[offsetcomments]] MERCAADATA
{
/*0x00*/ DWORD nName;                            // I would guess we can find aapoints spent on the ability in this struct as well
/*0x04*/
};
using PMERCAADATA = MERCAADATA*;

struct [[offsetcomments]] MERCAA
{
/*0x00*/ DWORD         Unknown0x00;
/*0x04*/ DWORD         Unknown0x04;
/*0x08*/ MERCAADATA*   Ptr;
/*0x0c*/ DWORD         Unknown0x00c;
/*0x10*/ DWORD         Max;                      // how many AA can be spent on this ability
/*0x14*/
};
using PMERCAA = MERCAA*;

constexpr int MERC_ALT_ABILITY_COUNT = 12;

// pinstMercAltAbilities_x
// MercAltAbilities__MercAltAbilities
// Actual Size: 0x478 in eqgame dated oct 04 2013 (see 4A96D4) - eqmule
struct [[offsetcomments]] EQMERCALTABILITIES
{
/*0x000*/ BYTE    Unknown0x000[0x408];
/*0x408*/ PMERCAA MercAAInfo[MERC_ALT_ABILITY_COUNT];  // 12 pointers since there are currently only 12 mercenary aa's
/*0x438*/ BYTE    Unknown0x438[0x40];
/*0x478*/
};
using PEQMERCALTABILITIES = EQMERCALTABILITIES*;

// size 0x98 (3-12-2014)
// size 0x9c 3-18-2015 test see (49A077)
struct [[offsetcomments]] EQRAIDMEMBER
{
/*0x00*/ char      Name[0x40];
/*0x40*/ char      RaidNote[0x40];
/*0x80*/ DWORD     nLevel;
/*0x84*/ DWORD     nClass;
/*0x88*/ BYTE      RaidLeader;
/*0x89*/ BYTE      GroupLeader;
/*0x8a*/ BYTE      RaidMainAssist;
/*0x8b*/ BYTE      RaidMarker;
/*0x8c*/ DWORD     MasterLooter;
/*0x90*/ DWORD     GroupNumber;
/*0x94*/ BYTE      Unknown0x94[0x8];            // i guess new master looter is in here...
/*0x9c*/
};
using PEQRAIDMEMBER = EQRAIDMEMBER*;

constexpr int MAX_RAID_LOOTERS = 19;
constexpr int MAX_RAID_SIZE = 72;
constexpr int MAX_RAID_MOTD = 1024;

constexpr int MAX_GROUP_SIZE = 6;

enum eRaidLootType : int32_t
{
	RaidLootUnknown = 0,
	RaidLootLeaderOnly = 1,
	RaidLootLeaderAndGroupLeader = 2,
	RaidLootAssignments = 3,
};

enum eRaidState : int32_t
{
	RaidStateNotInRaid = 1,
	RaidStateInvited = 2,
	RaidStateInRaid = 4
};

// sizeof(_EQRAID) is 0x3668 (12-09-2009)
// is size calculated by doing instCGuild_x - 4 - instCRaid_x ? 366C
// 0x3668 is locked so if its 4 byte aligned size should be /*0x366c*/ - eqmule Aug 10 2016
// instCRaid_x
// push    13C6h
// mar 18 2015 Test CRaid__ResetRaid eqgame.exe - eqmule
// as for the size... I have no idea...
// maybe 3544h? see 48055F                 mov     [esi+3544h], bl (jun 11 2014)
// 392C in mar 18 205 test? not sure...

// CRaid
struct [[offsetcomments]] EQRAID
{
/*0x0000*/ BYTE              Unknown0x0000[0xe0];
/*0x00e0*/ char              RaidMemberUsed[MAX_RAID_SIZE];
/*0x0128*/ EQRAIDMEMBER      RaidMember[MAX_RAID_SIZE];
/*0x2d08*/ BYTE              Unknown0x2d08[0x4];
/*0x2d0c*/ int               RaidMemberCount;
/*0x2d10*/ char              RaidLeaderName[0x40];
/*0x2d50*/ char              RaidMOTD[MAX_RAID_MOTD];
/*0x3150*/ char              Inviter[0x40];
/*0x3190*/ eRaidState        Invited;
/*0x3194*/ UINT              RaidID;                       // not sure
/*0x3198*/ bool              bCreateRaidInvite;
/*0x3199*/ bool              IsRaidLeader;
/*0x319a*/ BYTE              Filler0x319a[0x2];
/*0x319c*/ DWORD             RaidTarget;
/*0x31a0*/ eRaidLootType     LootType;
/*0x31a4*/ char              RaidLooters[MAX_RAID_LOOTERS][0x40];
/*0x3664*/ DWORD             TotalRaidMemberLevels;        // TotalRaidMemberLevels/RaidMemberCount=RaidAvgLevel
/*0x3668*/ BYTE              Locked;
/*0x3669*/ BYTE              Unknown0x3669[0x7];
/*0x3670*/ // <- im sure this is not right but whatever... we got what we came for...
};
using PEQRAID = EQRAID*;

// size 0x19C 3-23-2005
struct [[offsetcomments]] EQGROUP
{
	FORCE_SYMBOLS;

/*0x000*/ BYTE         MemberExists[5];
/*0x005*/ char         MemberName[5][0x40];
/*0x145*/ BYTE         Unused[3];
/*0x148*/ SPAWNINFO*   pMember[5];
/*0x15c*/ char         LeaderName[0x40];
/*0x19c*/
};
using PEQGROUP = EQGROUP*;

// size 0x08
struct [[offsetcomments]] EQSTRING {
/*0x00*/ DWORD ID;
/*0x04*/ char* String;
/*0x08*/
};
using PEQSTRING = EQSTRING*;

// size 0x10 4-28-2004 lax
struct [[offsetcomments]] EQSTRINGTABLE
{
/*0x00*/ EQSTRING** StringItems;
/*0x04*/ DWORD      Size;
/*0x08*/ int        Count;
/*0x0c*/ DWORD      Unknown0x0c;
/*0x10*/
};
using PEQSTRINGTABLE [[deprecated]] = EQSTRINGTABLE*;

// updated by eqmule
// see 7B000C in eqgame.exe dated jul 16 2014
// not sure about size... oh and this is __gWorld_x
struct [[offsetcomments]] connection_t
{
/*0x000*/ void* vtable;
/*0x004*/ BYTE  Unknown0x4[0x110];
/*0x114*/ DWORD Master;
/*0x118*/ DWORD Average;
/*0x11c*/ DWORD Low;
/*0x120*/ DWORD High;
/*0x124*/ DWORD Last;
/*0x128*/
};
using CONNECTION_T [[deprecated]] = connection_t;
using PCONNECTION_T [[deprecated]] = connection_t*;

// actual size 0x2dfc 3-19-09 - ieatacid
struct [[offsetcomments]] CDISPLAY
{
/*0x0000*/ BYTE    Unknown0x000[0x12c];
/*0x012c*/ void*   pActorTagManager;
/*0x0130*/ BYTE    Unknown0x130[0x24];
/*0x0154*/ DWORD   TimeStamp;
/*0x0158*/ BYTE    Unknown0x158[0x2c12];
/*0x2d6a*/ BYTE    NpcNames;                     // show npc names
/*0x2d6c*/
};
using PCDISPLAY [[deprecated]] = CDISPLAY*;

enum eDynamicZoneType
{
	eDZT_Unknown,
	eDZT_Expedition,
	eDZT_Tutorial,
	eDZT_Task,
	eDZT_Mission,
	eDZT_Quest
};

struct [[offsetcomments]] DynamicZoneData
{
/*0x00*/ int                DynamicZoneID;
/*0x04*/ int                SetID;
/*0x08*/ eDynamicZoneType   Type;
/*0x0c*/
};

struct [[offsetcomments]] DynamicZoneTimerData
{
/*0x00*/ int                   DataSetID;
/*0x04*/ time_t                TimerExpiration;
/*0x08*/ int                   EventID;
/*0x0c*/ int                   DynamicZoneID;
/*0x10*/ DynamicZoneTimerData* pNext;
/*0x14*/
};

struct [[offsetcomments]] DynamicZoneClientTimerData
{
/*0x000*/ char         ExpeditionName[0x80];
/*0x080*/ char         EventName[0x100];
/*0x180*/ time_t       TimeStamp;                      // TimeStamp - Util__FastTime = time left
/*0x184*/ int          TimerID;
/*0x188*/ DynamicZoneClientTimerData* pNext;
/*0x18c*/
};
using DZTIMERINFO = DynamicZoneClientTimerData;
using PDZTIMERINFO [[deprecated]] = DZTIMERINFO*;


enum eDyanicZonePlayerStatus
{
	eStatusUnknown = 0,
	eStatusOnline,
	eStatusOffline,
	eStatusInZone,
	eStatusLinkDead,
};

struct [[offsetcomments]] DynamicZonePlayerInfo
{
	/*0x00*/ char                     Name[0x40];                // The usual name length
	/*0x40*/ eDyanicZonePlayerStatus  Status;
	/*0x44*/ DynamicZonePlayerInfo*   pNext;
	/*0x48*/ bool                     bFlagged;                  // Do we meet the requirements?
	/*0x49*/ bool                     bCheckedZoneReqs;          // Zone reqs serverside checked?
/*0x4c*/ };
using DZMEMBER = DynamicZonePlayerInfo;
using PDZMEMBER [[deprecated]] = DynamicZonePlayerInfo*;

enum eSharedTaskPlayerRole
{
	eSharedTaskRoleNone = 0,
	eSharedTaskRoleLeader
};

// Shared Task Member Info
struct [[offsetcomments]] SharedTaskPlayerInfo
{
/*0x00*/ char                     Name[0x40];
/*0x40*/ int                      ShroudID;
/*0x44*/ eSharedTaskPlayerRole    Role;
/*0x48*/ SharedTaskPlayerInfo*    pNext;
/*0x4c*/

	ALT_MEMBER_GETTER(DWORD, Role, IsLeader);
};
using TASKMEMBER = SharedTaskPlayerInfo;
using PTASKMEMBER [[deprecated]] = SharedTaskPlayerInfo*;

struct [[offsetcomments]] DynamicZoneSwitchInfo
{
	/*0x00*/ int          DZID;
	/*0x04*/ int          Type;
	/*0x08*/ int          DZSwitchID;
	/*0x0c*/ float        SwitchX;
	/*0x10*/ float        SwitchY;
	/*0x14*/ float        SwitchZ;
/*0x18*/ };
using DZSWITCHINFO = DynamicZoneSwitchInfo;
using PDZSWITCHINFO [[deprecated]] = DynamicZoneSwitchInfo*;
using _DZSWITCHINFO [[deprecated]] = DynamicZoneSwitchInfo;

struct [[offsetcomments]] DynamicZoneCompass
{
	/*0x00*/ int          R;
	/*0x04*/ int          G;
	/*0x08*/ int          B;
	/*0x0c*/ float        X;
	/*0x10*/ float        Y;
	/*0x14*/ float        Z;
	/*0x18*/ bool         bVisible;
	/*0x1c*/ int          PixelOffset;
	/*0x20*/ bool         bInWindow;
/*0x24*/ };
using DZCOMPASS = DynamicZoneCompass;
using PDZCOMPASS [[deprecated]] = DynamicZoneCompass*;

struct [[offsetcomments]] DynamicZoneClientSwitchInfo : public DynamicZoneSwitchInfo
{
	/*0x18*/ DynamicZoneCompass* pCompass;
/*0x1c*/ };
using DZSWITCH = DynamicZoneClientSwitchInfo;
using PDZSWITCH [[deprecated]] = DynamicZoneClientSwitchInfo*;

// CDynamicZone size: 0x128
struct [[offsetcomments]] CDynamicZone : public PopDialogHandler
{
	/*0x004*/ uint32_t     NewMemberDZID;
	/*0x008*/ char         NewMemberName[0x40];
	/*0x048*/ bool         bNewSwap;
	/*0x049*/ bool         bNewAssignedToDZ;
	/*0x04a*/ char         LeaderName[0x40];
	/*0x08a*/ char         DZName[0x80];
	/*0x10c*/ int          MaxPlayers;
	/*0x110*/ DynamicZonePlayerInfo* pFirstMember;
	/*0x114*/ DynamicZoneClientTimerData* pFirstTimer;
	/*0x118*/ HashTable<DynamicZoneClientSwitchInfo> Switches;
/*0x128*/
	ALT_MEMBER_GETTER_ARRAY(char, 0x40, LeaderName, Name);
	ALT_MEMBER_GETTER_ARRAY(char, 0x80, DZName, ExpeditionName);
	ALT_MEMBER_GETTER(DynamicZonePlayerInfo*, pFirstMember, pMemberList);
};
using DYNAMICZONE = CDynamicZone;
using PDYNAMICZONE [[deprecated]] = CDynamicZone*;

struct [[offsetcomments]] CHATCHANNELS
{
/*0x00*/ char* ChannelName[0xa];
/*0x28*/
};
using PCHATCHANNELS [[deprecated]] = CHATCHANNELS*;

enum eFriendStatus
{
	eFriendRemoved,
	eFriendOffline,
	eFriendOnline,
	eFriendOnlineAway,
	eFriendOnlineInvisible,
	eFriendInGame,
	eFriendInGameAway,
	eFriendInGameInvisible
};

struct [[offsetcomments]] FriendEntry
{
/*0x00*/ char               Name[0x30];
/*0x30*/ eFriendStatus      Status;
/*0x34*/ bool               bName;                    // not sure.
/*0x38*/
};

struct [[offsetcomments]] _CHATSERVICE
{
/*0x00*/ void*        vfTable;
/*0x04*/ void*        pChatProxyHandler;
/*0x08*/ void*        pUdpManager;
/*0x0c*/ CHATCHANNELS* ChannelList;             // really just a char**
/*0x10*/ int          ActiveChannels;           // number of channels joined, aka channelcount
/*0x14*/ bool         mAuthenticated;
/*0x15*/ bool         bLoginSent;
/*0x16*/ bool         bInvisible;
/*0x17*/ bool         bFullNotifyMode;
/*0x18*/ void*        UdpConnection;
/*0x1c*/ char         ChatID[0x30];             // "ServerName.CharName"
/*0x4c*/ char         ChatPass[0x30];
/*0x7c*/ char         ServerName[0x30];         // "ServerName."
/*0xac*/ int          ServerNameLen;
/*0xb0*/ char         Locale[0x10];
/*0xc0*/ const char*  ChatPrefix;
/*0xc4*/ int          LastDisconnectCheckTime;
/*0xc8*/ FriendEntry** BuddyList;
/*0xcc*/ int          BuddyListCount;
/*0xd0*/ ArrayClass<CXStr> IgnoreList;
/*0xe0*/
};
using PCHATSERVICE [[deprecated]] = _CHATSERVICE*;
using CHATSERVICE/* [[deprecated]]*/ = _CHATSERVICE;

class [[offsetcomments]] PickZoneTimerHandler
{
public:
	struct PickZoneRecord
	{
		CXStr  ZoneName;
		int    Time;
	};

/*0x00*/ SoeUtil::Array<PickZoneRecord> Records;
/*0x10*/
};

struct [[offsetcomments]] PETITIONSTATUS
{
/*0x00*/ int           ID;
/*0x04*/ int           Priority;                 // todo: check
/*0x08*/ int           State;                    // todo: figure out.
/*0x0c*/ DWORD         ArrivalTime;
/*0x10*/ char          User[0x20];
/*0x30*/ char          Player[0x40];
/*0x70*/ int           NumActive;
/*0x74*/ char          Player2[0x40];
/*0xb4*/ DWORD         TimeStamp;                // not sure what its for
/*0xb8*/
};
using PPETITIONSTATUS [[deprecated]] = PETITIONSTATUS*;

// size is 0x170 see 4467A5 in Sep 18 2017 Live
struct [[offsetcomments]] CSINFO
{
/*0x000*/ char         Name[0x40];
/*0x040*/ int          Class;
/*0x044*/ int          Race;
/*0x048*/ BYTE         Level;
/*0x04c*/ int          Class2;
/*0x050*/ int          Race2;
/*0x054*/ int          CurZoneID;
/*0x058*/ BYTE         Sex;
/*0x059*/ BYTE         Face;
/*0x05c*/ ArmorProperties ArmProp[9];            // size /*0x14*/ * 9 = 0xB4
/*0x110*/ DWORD        Tint[9];                  // size 0x24
/*0x134*/ char         TextureType;
/*0x135*/ char         ArmorMaterial;
/*0x136*/ char         ArmorVariation;
/*0x137*/ char         HeadType;
/*0x138*/ int          TattooIndex;
/*0x13c*/ int          FacialAttachmentIndex;
/*0x140*/ int          Deity;
/*0x144*/ int          PrimActor;
/*0x148*/ int          SecdActor;
/*0x14c*/ BYTE         HairColor;
/*0x14d*/ BYTE         BeardColor;
/*0x14e*/ BYTE         LeftEye;
/*0x14f*/ BYTE         RightEye;
/*0x150*/ BYTE         Hair;
/*0x151*/ BYTE         Beard;
/*0x152*/ bool         bCanGoHome;
/*0x153*/ bool         bCanTutorial;
/*0x154*/ int          ParentId;
/*0x158*/ bool         bTooHighLevel;
/*0x159*/ bool         bPreFTP;
/*0x15c*/ long         SomethingLogin;
/*0x160*/ bool         bUseable;
/*0x161*/ bool         bHeroicCharacter;
/*0x162*/ bool         bShrouded;
/*0x164*/ int          Unknown0x164;
/*0x168*/ int          Unknown0x168;
/*0x16c*/ int          Unknown0x16c;
/*0x170*/
};
using PCSINFO [[deprecated]] = CSINFO*;

struct [[offsetcomments]] CharSelectPlayerArray
{
	FORCE_SYMBOLS;

	// note that CharSelectPlayerCount determines how many are actully here
/*0x0000*/ CSINFO CharacterInfo[13];                    // is 13 chars the max u can have?
/*0x12b0*/
};
using PCharSelectPlayerArray [[deprecated]] = CharSelectPlayerArray*;

// this struct is actually part of EverQuestInfo struct
struct MQMouseInfo
{
	int X = 0;
	int Y = 0;
	int SpeedX = 0;
	int SpeedY = 0;
	int Scroll = 0;
};
using MOUSEINFO [[deprecated("Use MQMouseInfo instead")]] = MQMouseInfo;
using PMOUSEINFO [[deprecated("Use MQMouseInfo* instead")]] = MQMouseInfo *;

struct [[offsetcomments]] _EVERQUEST
{
/*0x00000*/ BYTE             Unknown[0x2a4];
/*0x002a4*/ CHATSERVICE*     ChatService;
/*0x002a8*/ BYTE             Unknown0x2a8[0x8];
/*0x002b0*/ bool             bJoinedChannel;
/*0x002b1*/ char             ChannelPlayerName[0x100];
/*0x003b1*/ char             ChannelName[0xa][0x30];
/*0x00591*/ BYTE             Unknown0x591[0x3];
/*0x00594*/ DWORD            ChannelNumber[0xa];
/*0x005bc*/ int              ChannelQty;
/*0x005c0*/ void*            pFreeTargetRing;              // PTARGETRING
/*0x005c4*/ DWORD            WorldState;                   // 0 everything is fine, 1 we are getting disconnected 2 player not released from zone
/*0x005c8*/ int              GameState;
/*0x005cc*/ bool             bStopAreaProcessing;
/*0x005cd*/ bool             bRAFEnabled;
/*0x005d0*/ int64_t          ServerTimeSync;
/*0x005d8*/ int64_t          ServerTimeBase;
/*0x005e0*/ int64_t          ServerTimeLastReported;
/*0x005e8*/ bool             bServerTimeHasWrapped;
/*0x005ec*/ float            TargetCameraDistance;
/*0x005f0*/ bool             bUnknown0x5f0;
/*0x005f4*/ int              TotalCharacterSlots;
/*0x005f8*/ int              MarketplaceCharacterSlots;
/*0x005fc*/ int              Unknown0x5fc;
/*0x00600*/ void*            CampDialog;                   // CPopDialogWnd
/*0x00604*/ PickZoneTimerHandler pickZoneTimerHandler;     // size 0x10?
/*0x00614*/ USINGSKILL       UsingSkill;                   // size 0x8
/*0x0061c*/ PETITIONSTATUS   PetitionStatus[0x200];        // size 0xb8 * 0x200 = 0x17000
/*0x1761c*/ int              TotalQ;                       // see 760EE8 in Sep 18 2017
/*0x17620*/ int              TotalClientPetitions;
/*0x17624*/ char             ChatText[0x840];
/*0x17e64*/ int              TrimIdx;                      // correct
/*0x17e68*/ char             ChatChanged;                  // 1 or 0?
/*0x17e69*/ char             Trim[0x40][0x840];            // correct. size 0x40*0x840= 0x21000
/*0x38e6c*/ BOOL             bChat;
/*0x38e70*/ int              Unknown0x38E70;
/*0x38e74*/ int              Red;                          // for sure see 564105 in spe 18 2017 exe
/*0x38e78*/ int              Green;
/*0x38e7c*/ int              Blue;
/*0x38e80*/ ArrayClass<CSINFO> pCharSelectPlayerArray;
/*0x38e90*/ // more data
};
using EVERQUEST /*[[deprecated]]*/ = _EVERQUEST;
using PEVERQUEST [[deprecated]] = _EVERQUEST*;

struct [[offsetcomments]] AURAINFO
{
/*0x00*/ char         Name[0x40];
/*0x40*/ uint32_t     SpawnID;
/*0x44*/ int          Cost;
/*0x48*/ int          IconnID;
/*0x4c*/
};
using PAURAINFO [[deprecated]] = AURAINFO*;

struct [[offsetcomments]] AURAS
{
	FORCE_SYMBOLS;

/*0x00*/ AURAINFO     Aura[0x2];
/*0x98*/
};
using PAURAS = AURAS*;

struct [[offsetcomments]] AURAMGR
{
	FORCE_SYMBOLS;

/*0x00*/ DWORD        NumAuras;
/*0x04*/ BYTE         Unknown0x4[0xc];
/*0x10*/ AURAS**      pAuraInfo;
/*0x14*/ BYTE         Unknown0x14[0x8];
/*0x1c*/
};
using PAURAMGR [[deprecated]] = AURAMGR*;

struct [[offsetcomments]] INTERACTSWITCH
{
	FORCE_SYMBOLS;

/*0x00*/ DWORD        switchID;
/*0x04*/ DWORD        dwzero;
/*0x08*/ DWORD        dwneg1;
/*0x0c*/ DWORD        spawnID;
/*0x10*/
};
using PINTERACTSWITCH [[deprecated]] = INTERACTSWITCH*;

struct [[offsetcomments]] MERCSTANCEDATA
{
/*0x00*/ DWORD nStance;
/*0x04*/ DWORD nDbStance;
/*0x08*/
};
using PMERCSTANCEDATA [[deprecated]] = MERCSTANCEDATA*;

struct [[offsetcomments]] MERCSINFO
{
/*0x00*/ DWORD         Unknown0x00;
/*0x04*/ DWORD         nMercCategory;
/*0x08*/ DWORD         nMercDesc;
/*0x0c*/ DWORD         Purchase;                 // in copper
/*0x10*/ DWORD         Upkeep;                   // in copper
/*0x14*/ BYTE          Unknown0x14[0x2c];
/*0x40*/ char          Name[0xC];
/*0x4c*/ BYTE          Unknown0x4c[0x88];
/*0xd4*/
};
using PMERCSINFO [[deprecated]] = MERCSINFO*;

// Size 0xD4 in eqgame.exe dated 01 22 2015
struct [[offsetcomments]] MERCSLIST
{
/*0x000*/ MERCSINFO     mercinfo[7];              // is 7 max, even with slots u can buy for sc?
/*0x5cc*/
};
using PMERCSLIST [[deprecated]] = MERCSLIST*;

// Actual Size: 0x2fc (See 57117F in eqgame dated dec 10 2013) - eqmule
// CMercenaryInfo__CMercenaryInfo
// this is CMercenaryClientManager
struct [[offsetcomments]] MERCENARYINFO
{
/*0x000*/ BYTE               Unknown0x0[0x110];
/*0x110*/ DWORD              HaveMerc;
/*0x114*/ DWORD              MercState;          // 1 = suspended, 5 = active
/*0x118*/ BYTE               Unknown0x118[0x30];
/*0x148*/ DWORD              ActiveStance;
/*0x14c*/ BYTE               Unknown0x14c[0x10];
/*0x15c*/ char               MercName[0x18];
/*0x174*/ BYTE               Unknown0x174[0x7c];
/*0x1f0*/ int                MercenaryCount;     // how many mercenaries we have
/*0x1f4*/ MERCSLIST*         pMercsList;
/*0x1f8*/ BYTE               Unknown0x1f8[0xc];
/*0x204*/ DWORD              MaxMercsCount;      // max you can have
/*0x208*/ BYTE               Unknown0x208[0x10];
/*0x218*/ DWORD              CurrentMercIndex;
/*0x21c*/ BYTE               Unknown0x21c[0x8];
/*0x224*/ DWORD              MercSpawnId;        // yes its the spawnID of the mercenary
/*0x228*/ BYTE               Unknown0x228[0x30];
/*0x258*/ int                NumStances;
/*0x25c*/ MERCSTANCEDATA**   pMercStanceData;
/*0x260*/ BYTE               Unknown0x260[0x9c];
/*0x2fc*/
};
using PMERCENARYINFO [[deprecated]] = MERCENARYINFO*;

struct [[offsetcomments]] MERCENARYSTATS
{
	FORCE_SYMBOLS;

/*0x00*/ DWORD        MaxHP;
/*0x04*/ DWORD        CurrHP;
/*0x08*/ DWORD        MaxMana;
/*0x0c*/ DWORD        CurrMana;
/*0x10*/ DWORD        MaxEndurance;
/*0x14*/ DWORD        CurrEndurance;
/*0x18*/ DWORD        AC;
/*0x1c*/ DWORD        Attack;
/*0x20*/ DWORD        Haste;
/*0x24*/ DWORD        STR;
/*0x28*/ DWORD        STA;
/*0x2c*/ DWORD        INT;
/*0x30*/ DWORD        WIS;
/*0x34*/ DWORD        AGI;
/*0x38*/ DWORD        DEX;
/*0x3c*/ DWORD        CHA;
/*0x40*/ DWORD        CombatHPRegen;
/*0x44*/ DWORD        CombatManaRegen;
/*0x48*/ DWORD        CombatEnduranceRegen;
/*0x4c*/ DWORD        HealAmount;
/*0x50*/ DWORD        SpellDamage;
/*0x54*/
};
using PMERCENARYSTATS [[deprecated]] = MERCENARYSTATS*;

#define MAX_XTARGETS                             20

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

struct [[offsetcomments]] AGGRODATA
{
	FORCE_SYMBOLS;

/*0x00*/ DWORD         Unknown0x0;
/*0x04*/ BYTE          AggroPct;
/*0x05*/ BYTE          padding[3];
/*0x08*/
};
using PAGGRODATA [[deprecated]] = AGGRODATA*;

// size 0xe4 11-28-12 - ieatacid (in GetAggroInfo)
// size 0xfc see 422F94 in 20 Aug 2015
struct [[offsetcomments]] AGGROINFO
{
	FORCE_SYMBOLS;

/*0x00*/ AGGRODATA     aggroData[0x1e];
/*0xf0*/ DWORD         AggroLockID;              // this can be 0, I dont know what it is...
/*0xf4*/ DWORD         AggroTargetID;            // this is id of whoever we are fighting
/*0xf8*/ DWORD         AggroSecondaryID;         // this is id of whoever the npc is fighting
/*0xfc*/
};
using PAGGROINFO [[deprecated]] = AGGROINFO*;

enum AggroDataTypes
{
	AD_Player,
	AD_Secondary,
	AD_Group1,
	AD_Group2,
	AD_Group3,
	AD_Group4,
	AD_Group5,
	AD_xTarget1,
	AD_xTarget2,
	AD_xTarget3,
	AD_xTarget4,
	AD_xTarget5,
	AD_xTarget6,
	AD_xTarget7,
	AD_xTarget8,
	AD_xTarget9,
	AD_xTarget10,
	AD_xTarget11,
	AD_xTarget12,
	AD_xTarget13,
	AD_xTarget14,
	AD_xTarget15,
	AD_xTarget16,
	AD_xTarget17,
	AD_xTarget18,
	AD_xTarget19,
	AD_xTarget20,
};

struct [[offsetcomments]] GROUPAGGRO
{
/*0x00*/ DWORD         Unknown0x00;
/*0x04*/ DWORD         Unknown0x04;
/*0x08*/ DWORD         GroupMemberAggro[6];      // player is ALWAYS the 6th member...
/*0x20*/
};
using PGROUPAGGRO [[deprecated]] = GROUPAGGRO*;

#define EQ_ASSIST_CALC                           0x020c0f19
#define EQ_ASSIST_COMPLETE                       0x2228    // aMsgTimeStampRe
#define EQ_ASSIST                                0x758e    // do_assist(PlayerClient *,char const *)+399 20160212 live (see 52C319)
#define EQ_LoadingS__ArraySize                   0x5a      // EQ_LoadingS__SetProgressBar_x+76  (4C7396 yes it says 5b there, but we dont want to overwrite the NULL term... 2016 Apr 21

} // namespace eqlib
