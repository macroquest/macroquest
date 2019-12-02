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

#include "Common.h"
#include "Containers.h"
#include "CXStr.h"
#include "Items.h"

namespace eqlib {

//============================================================================
// Spell Cache
//============================================================================

enum ItemSpellTypes
{
	eActivatableSpell,
	eProcSpell,
	eWornSpell,
	eFocusSpell,
	eScrollSpell,
	eFocus2Spell,
	eMountSpell,
	eIllusionSpell,
	eFamiliarSpell
};

// EQ Spell "Affect"
// http://everquest.fanra.info/wiki/SPA_list
enum eEQSPA
{
	SPA_HP                                  = 0,
	SPA_AC                                  = 1,
	SPA_ATTACK_POWER                        = 2,
	SPA_MOVEMENT_RATE                       = 3,
	SPA_STR                                 = 4,
	SPA_DEX                                 = 5,
	SPA_AGI                                 = 6,
	SPA_STA                                 = 7,
	SPA_INT                                 = 8,
	SPA_WIS                                 = 9,
	SPA_CHA                                 = 10,
	SPA_HASTE                               = 11, // "Melee Speed"
	SPA_INVISIBILITY                        = 12,
	SPA_SEE_INVIS                           = 13,
	SPA_ENDURING_BREATH                     = 14,
	SPA_MANA                                = 15,
	SPA_NPC_FRENZY                          = 16,
	SPA_NPC_AWARENESS                       = 17,
	SPA_NPC_AGGRO                           = 18,
	SPA_NPC_FACTION                         = 19,
	SPA_BLINDNESS                           = 20,
	SPA_STUN                                = 21,
	SPA_CHARM                               = 22,
	SPA_FEAR                                = 23,
	SPA_FATIGUE                             = 24,
	SPA_BIND_AFFINITY                       = 25,
	SPA_GATE                                = 26,
	SPA_DISPEL_MAGIC                        = 27,
	SPA_INVIS_VS_UNDEAD                     = 28,
	SPA_INVIS_VS_ANIMALS                    = 29,
	SPA_NPC_AGGRO_RADIUS                    = 30,
	SPA_ENTHRALL                            = 31,
	SPA_CREATE_ITEM                         = 32,
	SPA_SUMMON_PET                          = 33,
	SPA_CONFUSE                             = 34,
	SPA_DISEASE                             = 35,
	SPA_POISON                              = 36,
	SPA_DETECT_HOSTILE                      = 37,
	SPA_DETECT_MAGIC                        = 38,
	SPA_NO_TWINCAST                         = 39,
	SPA_INVULNERABILITY                     = 40,
	SPA_BANISH                              = 41,
	SPA_SHADOW_STEP                         = 42,
	SPA_BERSERK                             = 43,
	SPA_LYCANTHROPY                         = 44,
	SPA_VAMPIRISM                           = 45,
	SPA_RESIST_FIRE                         = 46,
	SPA_RESIST_COLD                         = 47,
	SPA_RESIST_POISON                       = 48,
	SPA_RESIST_DISEASE                      = 49,
	SPA_RESIST_MAGIC                        = 50,
	SPA_DETECT_TRAPS                        = 51,
	SPA_DETECT_UNDEAD                       = 52,
	SPA_DETECT_SUMMONED                     = 53,
	SPA_DETECT_ANIMALS                      = 54,
	SPA_STONESKIN                           = 55,
	SPA_TRUE_NORTH                          = 56,
	SPA_LEVITATION                          = 57,
	SPA_CHANGE_FORM                         = 58,
	SPA_DAMAGE_SHIELD                       = 59,
	SPA_TRANSFER_ITEM                       = 60,
	SPA_ITEM_LORE                           = 61,
	SPA_ITEM_IDENTIFY                       = 62,
	SPA_NPC_WIPE_HATE_LIST                  = 63,
	SPA_SPIN_STUN                           = 64,
	SPA_INFRAVISION                         = 65,
	SPA_ULTRAVISION                         = 66,
	SPA_EYE_OF_ZOMM                         = 67,
	SPA_RECLAIM_ENERGY                      = 68,
	SPA_MAX_HP                              = 69,
	SPA_CORPSE_BOMB                         = 70,
	SPA_CREATE_UNDEAD                       = 71,
	SPA_PRESERVE_CORPSE                     = 72,
	SPA_TARGETS_VIEW                        = 73,
	SPA_FEIGN_DEATH                         = 74,
	SPA_VENTRILOQUISM                       = 75,
	SPA_SENTINEL                            = 76,
	SPA_LOCATE_CORPSE                       = 77,
	SPA_SPELL_SHIELD                        = 78,
	SPA_INSTANT_HP                          = 79,
	SPA_ENCHANT_LIGHT                       = 80,
	SPA_RESURRECT                           = 81,
	SPA_SUMMON_TARGET                       = 82,
	SPA_PORTAL                              = 83,
	SPA_HP_NPC_ONLY                         = 84,
	SPA_MELEE_PROC                          = 85,
	SPA_NPC_HELP_RADIUS                     = 86,
	SPA_MAGNIFICATION                       = 87,
	SPA_EVACUATE                            = 88,
	SPA_HEIGHT                              = 89,
	SPA_IGNORE_PET                          = 90,
	SPA_SUMMON_CORPSE                       = 91,
	SPA_HATE                                = 92,
	SPA_WEATHER_CONTROL                     = 93,
	SPA_FRAGILE                             = 94,
	SPA_SACRIFICE                           = 95,
	SPA_SILENCE                             = 96,
	SPA_MAX_MANA                            = 97,
	SPA_BARD_HASTE                          = 98,
	SPA_ROOT                                = 99,
	SPA_HEALDOT                             = 100,
	SPA_COMPLETEHEAL                        = 101,
	SPA_PET_FEARLESS                        = 102,
	SPA_CALL_PET                            = 103,
	SPA_TRANSLOCATE                         = 104,
	SPA_NPC_ANTI_GATE                       = 105,
	SPA_BEASTLORD_PET                       = 106,
	SPA_ALTER_PET_LEVEL                     = 107,
	SPA_FAMILIAR                            = 108,
	SPA_CREATE_ITEM_IN_BAG                  = 109,
	SPA_ARCHERY                             = 110,
	SPA_RESIST_ALL                          = 111,
	SPA_FIZZLE_SKILL                        = 112,
	SPA_SUMMON_MOUNT                        = 113,
	SPA_MODIFY_HATE                         = 114,
	SPA_CORNUCOPIA                          = 115,
	SPA_CURSE                               = 116,
	SPA_HIT_MAGIC                           = 117,
	SPA_AMPLIFICATION                       = 118,
	SPA_ATTACK_SPEED_MAX                    = 119,
	SPA_HEALMOD                             = 120,
	SPA_IRONMAIDEN                          = 121,
	SPA_REDUCESKILL                         = 122,
	SPA_IMMUNITY                            = 123,
	SPA_FOCUS_DAMAGE_MOD                    = 124,
	SPA_FOCUS_HEAL_MOD                      = 125,
	SPA_FOCUS_RESIST_MOD                    = 126,
	SPA_FOCUS_CAST_TIME_MOD                 = 127,
	SPA_FOCUS_DURATION_MOD                  = 128,
	SPA_FOCUS_RANGE_MOD                     = 129,
	SPA_FOCUS_HATE_MOD                      = 130,
	SPA_FOCUS_REAGENT_MOD                   = 131,
	SPA_FOCUS_MANACOST_MOD                  = 132,
	SPA_FOCUS_STUNTIME_MOD                  = 133,
	SPA_FOCUS_LEVEL_MAX                     = 134,
	SPA_FOCUS_RESIST_TYPE                   = 135,
	SPA_FOCUS_TARGET_TYPE                   = 136,
	SPA_FOCUS_WHICH_SPA                     = 137,
	SPA_FOCUS_BENEFICIAL                    = 138,
	SPA_FOCUS_WHICH_SPELL                   = 139,
	SPA_FOCUS_DURATION_MIN                  = 140,
	SPA_FOCUS_INSTANT_ONLY                  = 141,
	SPA_FOCUS_LEVEL_MIN                     = 142,
	SPA_FOCUS_CASTTIME_MIN                  = 143,
	SPA_FOCUS_CASTTIME_MAX                  = 144,
	SPA_NPC_PORTAL_WARDER_BANISH            = 145,
	SPA_PORTAL_LOCATIONS                    = 146,
	SPA_PERCENT_HEAL                        = 147,
	SPA_STACKING_BLOCK                      = 148,
	SPA_STRIP_VIRTUAL_SLOT                  = 149,
	SPA_DIVINE_INTERVENTION                 = 150,
	SPA_POCKET_PET                          = 151,
	SPA_PET_SWARM                           = 152,
	SPA_HEALTH_BALANCE                      = 153,
	SPA_CANCEL_NEGATIVE_MAGIC               = 154,
	SPA_POP_RESURRECT                       = 155,
	SPA_MIRROR                              = 156,
	SPA_FEEDBACK                            = 157,
	SPA_REFLECT                             = 158,
	SPA_MODIFY_ALL_STATS                    = 159,
	SPA_CHANGE_SOBRIETY                     = 160,
	SPA_SPELL_GUARD                         = 161,
	SPA_MELEE_GUARD                         = 162,
	SPA_ABSORB_HIT                          = 163,
	SPA_OBJECT_SENSE_TRAP                   = 164,
	SPA_OBJECT_DISARM_TRAP                  = 165,
	SPA_OBJECT_PICKLOCK                     = 166,
	SPA_FOCUS_PET                           = 167,
	SPA_DEFENSIVE                           = 168,
	SPA_CRITICAL_MELEE                      = 169,
	SPA_CRITICAL_SPELL                      = 170,
	SPA_CRIPPLING_BLOW                      = 171,
	SPA_EVASION                             = 172,
	SPA_RIPOSTE                             = 173,
	SPA_DODGE                               = 174,
	SPA_PARRY                               = 175,
	SPA_DUAL_WIELD                          = 176,
	SPA_DOUBLE_ATTACK                       = 177,
	SPA_MELEE_LIFETAP                       = 178,
	SPA_PURETONE                            = 179,
	SPA_SANCTIFICATION                      = 180,
	SPA_FEARLESS                            = 181,
	SPA_HUNDRED_HANDS                       = 182,
	SPA_SKILL_INCREASE_CHANCE               = 183, // Unused
	SPA_ACCURACY                            = 184,
	SPA_SKILL_DAMAGE_MOD                    = 185,
	SPA_MIN_DAMAGE_DONE_MOD                 = 186,
	SPA_MANA_BALANCE                        = 187,
	SPA_BLOCK                               = 188,
	SPA_ENDURANCE                           = 189,
	SPA_INCREASE_MAX_ENDURANCE              = 190,
	SPA_AMNESIA                             = 191,
	SPA_HATE_OVER_TIME                      = 192,
	SPA_SKILL_ATTACK                        = 193,
	SPA_FADE                                = 194,
	SPA_STUN_RESIST                         = 195,
	SPA_STRIKETHROUGH1                      = 196, // Deprecated
	SPA_SKILL_DAMAGE_TAKEN                  = 197,
	SPA_INSTANT_ENDURANCE                   = 198,
	SPA_TAUNT                               = 199,
	SPA_PROC_CHANCE                         = 200,
	SPA_RANGE_ABILITY                       = 201,
	SPA_ILLUSION_OTHERS                     = 202,
	SPA_MASS_GROUP_BUFF                     = 203,
	SPA_GROUP_FEAR_IMMUNITY                 = 204,
	SPA_RAMPAGE                             = 205,
	SPA_AE_TAUNT                            = 206,
	SPA_FLESH_TO_BONE                       = 207,
	SPA_PURGE_POISON                        = 208,
	SPA_CANCEL_BENEFICIAL                   = 209,
	SPA_SHIELD_CASTER                       = 210,
	SPA_DESTRUCTIVE_FORCE                   = 211,
	SPA_FOCUS_FRENZIED_DEVASTATION          = 212,
	SPA_PET_PCT_MAX_HP                      = 213,
	SPA_HP_MAX_HP                           = 214,
	SPA_PET_PCT_AVOIDANCE                   = 215,
	SPA_MELEE_ACCURACY                      = 216,
	SPA_HEADSHOT                            = 217,
	SPA_PET_CRIT_MELEE                      = 218,
	SPA_SLAY_UNDEAD                         = 219,
	SPA_INCREASE_SKILL_DAMAGE               = 220,
	SPA_REDUCE_WEIGHT                       = 221,
	SPA_BLOCK_BEHIND                        = 222,
	SPA_DOUBLE_RIPOSTE                      = 223,
	SPA_ADD_RIPOSTE                         = 224,
	SPA_GIVE_DOUBLE_ATTACK                  = 225,
	SPA_2H_BASH                             = 226,
	SPA_REDUCE_SKILL_TIMER                  = 227,
	SPA_ACROBATICS                          = 228,
	SPA_CAST_THROUGH_STUN                   = 229,
	SPA_EXTENDED_SHIELDING                  = 230,
	SPA_BASH_CHANCE                         = 231,
	SPA_DIVINE_SAVE                         = 232,
	SPA_METABOLISM                          = 233,
	SPA_POISON_MASTERY                      = 234,
	SPA_FOCUS_CHANNELING                    = 235,
	SPA_FREE_PET                            = 236,
	SPA_PET_AFFINITY                        = 237,
	SPA_PERM_ILLUSION                       = 238,
	SPA_STONEWALL                           = 239,
	SPA_STRING_UNBREAKABLE                  = 240,
	SPA_IMPROVE_RECLAIM_ENERGY              = 241,
	SPA_INCREASE_CHANGE_MEMWIPE             = 242,
	SPA_ENHANCED_CHARM                      = 243,
	SPA_ENHANCED_ROOT                       = 244,
	SPA_TRAP_CIRCUMVENTION                  = 245,
	SPA_INCREASE_AIR_SUPPLY                 = 246,
	SPA_INCREASE_MAX_SKILL                  = 247,
	SPA_EXTRA_SPECIALIZATION                = 248,
	SPA_OFFHAND_MIN_WEAPON_DAMAGE           = 249,
	SPA_INCREASE_PROC_CHANCE                = 250,
	SPA_ENDLESS_QUIVER                      = 251,
	SPA_BACKSTAB_FRONT                      = 252,
	SPA_CHAOTIC_STAB                        = 253,
	SPA_NOSPELL                             = 254,
	SPA_SHIELDING_DURATION_MOD              = 255,
	SPA_SHROUD_OF_STEALTH                   = 256,
	SPA_GIVE_PET_HOLD                       = 257, // Deprecated
	SPA_TRIPLE_BACKSTAB                     = 258,
	SPA_AC_LIMIT_MOD                        = 259,
	SPA_ADD_INSTRUMENT_MOD                  = 260,
	SPA_SONG_MOD_CAP                        = 261,
	SPA_INCREASE_STAT_CAP                   = 262,
	SPA_TRADESKILL_MASTERY                  = 263,
	SPA_REDUCE_AA_TIMER                     = 264,
	SPA_NO_FIZZLE                           = 265,
	SPA_ADD_2H_ATTACK_CHANCE                = 266,
	SPA_ADD_PET_COMMANDS                    = 267,
	SPA_ALCHEMY_FAIL_RATE                   = 268,
	SPA_FIRST_AID                           = 269,
	SPA_EXTEND_SONG_RANGE                   = 270,
	SPA_BASE_RUN_MOD                        = 271,
	SPA_INCREASE_CASTING_LEVEL              = 272,
	SPA_DOTCRIT                             = 273,
	SPA_HEALCRIT                            = 274,
	SPA_MENDCRIT                            = 275,
	SPA_FLURRY                              = 279,
	SPA_PET_FLURRY                          = 280,
	SPA_PET_FEIGN                           = 281,
	SPA_INCREASE_BANDAGE_AMT                = 282,
	SPA_WU_ATTACK                           = 283,
	SPA_IMPROVE_LOH                         = 284,
	SPA_NIMBLE_EVASION                      = 285,
	SPA_FOCUS_DAMAGE_AMT                    = 286,
	SPA_FOCUS_DURATION_AMT                  = 287,
	SPA_ADD_PROC_HIT                        = 288,
	SPA_DOOM_EFFECT                         = 289,
	SPA_INCREASE_RUN_SPEED_CAP              = 290,
	SPA_PURIFY                              = 291,
	SPA_STRIKETHROUGH                       = 292,
	SPA_STUN_RESIST2                        = 293,
	SPA_SPELL_CRIT_CHANCE                   = 294,
	SPA_REDUCE_SPECIAL_TIMER                = 295,
	SPA_FOCUS_DAMAGE_MOD_DETRIMENTAL        = 296,
	SPA_FOCUS_DAMAGE_AMT_DETRIMENTAL        = 297,
	SPA_HEIGHT_SMALL                        = 298,
	SPA_WAKE_DEAD                           = 299,
	SPA_DOPPELGANGER                        = 300,
	SPA_INCREASE_RANGE_DMG                  = 301,
	SPA_FOCUS_DAMAGE_MOD_CRIT               = 302,
	SPA_FOCUS_DAMAGE_AMT_CRIT               = 303,
	SPA_SECONDARY_RIPOSTE_MOD               = 304,
	SPA_DAMAGE_SHIELD_MOD                   = 305,
	SPA_WEAK_DEAD_2                         = 306,
	SPA_APPRAISAL                           = 307,
	SPA_ZONE_SUSPEND_MINION                 = 308,
	SPA_TELEPORT_CASTERS_BINDPOINT          = 309,
	SPA_FOCUS_REUSE_TIMER                   = 310,
	SPA_FOCUS_COMBAT_SKILL                  = 311,
	SPA_OBSERVER                            = 312,
	SPA_FORAGE_MASTER                       = 313,
	SPA_IMPROVED_INVIS                      = 314,
	SPA_IMPROVED_INVIS_UNDEAD               = 315,
	SPA_IMPROVED_INVIS_ANIMALS              = 316,
	SPA_INCREASE_WORN_HP_REGEN_CAP          = 317,
	SPA_INCREASE_WORN_MANA_REGEN_CAP        = 318,
	SPA_CRITICAL_HP_REGEN                   = 319,
	SPA_SHIELD_BLOCK_CHANCE                 = 320,
	SPA_REDUCE_TARGET_HATE                  = 321,
	SPA_GATE_STARTING_CITY                  = 322,
	SPA_DEFENSIVE_PROC                      = 323,
	SPA_HP_FOR_MANA                         = 324,
	SPA_NO_BREAK_AE_SNEAK                   = 325,
	SPA_ADD_SPELL_SLOTS                     = 326,
	SPA_ADD_BUFF_SLOTS                      = 327,
	SPA_INCREASE_NEGATIVE_HP_LIMIT          = 328,
	SPA_MANA_ABSORB_PCT_DMG                 = 329,
	SPA_CRIT_ATTACK_MODIFIER                = 330,
	SPA_FAIL_ALCHEMY_ITEM_RECOVERY          = 331,
	SPA_SUMMON_TO_CORPSE                    = 332,
	SPA_DOOM_RUNE_EFFECT                    = 333,
	SPA_NO_MOVE_HP                          = 334,
	SPA_FOCUSED_IMMUNITY                    = 335,
	SPA_ILLUSIONARY_TARGET                  = 336,
	SPA_INCREASE_EXP_MOD                    = 337,
	SPA_EXPEDIENT_RECOVERY                  = 338,
	SPA_FOCUS_CASTING_PROC                  = 339,
	SPA_CHANCE_SPELL                        = 340,
	SPA_WORN_ATTACK_CAP                     = 341,
	SPA_NO_PANIC                            = 342,
	SPA_SPELL_INTERRUPT                     = 343,
	SPA_ITEM_CHANNELIGN                     = 344,
	SPA_ASSASSINATE_MAX_LEVEL               = 345,
	SPA_HEADSHOT_MAX_LEVEL                  = 346,
	SPA_DOUBLE_RANGED_ATTACK                = 347,
	SPA_FOCUS_MANA_MIN                      = 348,
	SPA_INCREASE_SHIELD_DMG                 = 349,
	SPA_MANABURN                            = 350,
	SPA_SPAWN_INTERACTIVE_OBJECT            = 351,
	SPA_INCREASE_TRAP_COUNT                 = 352,
	SPA_INCREASE_SOI_COUNT                  = 353,
	SPA_DEACTIVATE_ALL_TRAPS                = 354,
	SPA_LEARN_TRAP                          = 355,
	SPA_CHANGE_TRIGGER_TYPE                 = 356,
	SPA_FOCUS_MUTE                          = 357,
	SPA_INSTANT_MANA                        = 358,
	SPA_PASSIVE_SENSE_TRAP                  = 359,
	SPA_PROC_ON_KILL_SHOT                   = 360,
	SPA_PROC_ON_DEATH                       = 361,
	SPA_POTION_BELT                         = 362,
	SPA_BANDOLIER                           = 363,
	SPA_ADD_TRIPLE_ATTACK_CHANCE            = 364,
	SPA_PROC_ON_SPELL_KILL_SHOT             = 365,
	SPA_GROUP_SHIELDING                     = 366,
	SPA_MODIFY_BODY_TYPE                    = 367,
	SPA_MODIFY_FACTION                      = 368,
	SPA_CORRUPTION                          = 369,
	SPA_RESIST_CORRUPTION                   = 370,
	SPA_SLOW                                = 371,
	SPA_GRANT_FORAGING                      = 372,
	SPA_DOOM_ALWAYS                         = 373,
	SPA_TRIGGER_SPELL                       = 374,
	SPA_CRIT_DOT_DMG_MOD                    = 375,
	SPA_FLING                               = 376,
	SPA_DOOM_ENTITY                         = 377,
	SPA_RESIST_OTHER_SPA                    = 378,
	SPA_DIRECTIONAL_TELEPORT                = 379,
	SPA_EXPLOSIVE_KNOCKBACK                 = 380,
	SPA_FLING_TOWARD                        = 381,
	SPA_SUPPRESSION                         = 382,
	SPA_FOCUS_CASTING_PROC_NORMALIZED       = 383,
	SPA_FLING_AT                            = 384,
	SPA_FOCUS_WHICH_GROUP                   = 385,
	SPA_DOOM_DISPELLER                      = 386,
	SPA_DOOM_DISPELLEE                      = 387,
	SPA_SUMMON_ALL_CORPSES                  = 388,
	SPA_REFRESH_SPELL_TIMER                 = 389,
	SPA_LOCKOUT_SPELL_TIMER                 = 390,
	SPA_FOCUS_MANA_MAX                      = 391,
	SPA_FOCUS_HEAL_AMT                      = 392,
	SPA_FOCUS_HEAL_MOD_BENEFICIAL           = 393,
	SPA_FOCUS_HEAL_AMT_BENEFICIAL           = 394,
	SPA_FOCUS_HEAL_MOD_CRIT                 = 395,
	SPA_FOCUS_HEAL_AMT_CRIT                 = 396,
	SPA_ADD_PET_AC                          = 397,
	SPA_FOCUS_SWARM_PET_DURATION            = 398,
	SPA_FOCUS_TWINCAST_CHANCE               = 399,
	SPA_HEALBURN                            = 400,
	SPA_MANA_IGNITE                         = 401,
	SPA_ENDURANCE_IGNITE                    = 402,
	SPA_FOCUS_SPELL_CLASS                   = 403,
	SPA_FOCUS_SPELL_SUBCLASS                = 404,
	SPA_STAFF_BLOCK_CHANCE                  = 405,
	SPA_DOOM_LIMIT_USE                      = 406,
	SPA_DOOM_FOCUS_USED                     = 407,
	SPA_LIMIT_HP                            = 408,
	SPA_LIMIT_MANA                          = 409,
	SPA_LIMIT_ENDURANCE                     = 410,
	SPA_FOCUS_LIMIT_CLASS                   = 411,
	SPA_FOCUS_LIMIT_RACE                    = 412,
	SPA_FOCUS_BASE_EFFECTS                  = 413,
	SPA_FOCUS_LIMIT_SKILL                   = 414,
	SPA_FOCUS_LIMIT_ITEM_CLASS              = 415,
	SPA_AC2                                 = 416,
	SPA_MANA2                               = 417,
	SPA_FOCUS_INCREASE_SKILL_DMG_2          = 418,
	SPA_PROC_EFFECT_2                       = 419,
	SPA_FOCUS_LIMIT_USE                     = 420,
	SPA_FOCUS_LIMIT_USE_AMT                 = 421,
	SPA_FOCUS_LIMIT_USE_MIN                 = 422,
	SPA_FOCUS_LIMIT_USE_TYPE                = 423,
	SPA_GRAVITATE                           = 424,
	SPA_FLY                                 = 425,
	SPA_ADD_EXTENDED_TARGET_SLOTS           = 426,
	SPA_SKILL_PROC                          = 427,
	SPA_PROC_SKILL_MODIFIER                 = 428,
	SPA_SKILL_PROC_SUCCESS                  = 429,
	SPA_POST_EFFECT                         = 430,
	SPA_POST_EFFECT_DATA                    = 431,
	SPA_EXPAND_MAX_ACTIVE_TROPHY_BENEFITS   = 432,
	SPA_ADD_NORMALIZED_SKILL_MIN_DMG_AMT    = 433,
	SPA_ADD_NORMALIZED_SKILL_MIN_DMG_AMT_2  = 434,
	SPA_FRAGILE_DEFENSE                     = 435,
	SPA_FREEZE_BUFF_TIMER                   = 436,
	SPA_TELEPORT_TO_ANCHOR                  = 437,
	SPA_TRANSLOCATE_TO_ANCHOR               = 438,
	SPA_ASSASSINATE                         = 439,
	SPA_FINISHING_BLOW_MAX                  = 440,
	SPA_DISTANCE_REMOVAL                    = 441,
	SPA_REQUIRE_TARGET_DOOM                 = 442,
	SPA_REQUIRE_CASTER_DOOM                 = 443,
	SPA_IMPROVED_TAUNT                      = 444,
	SPA_ADD_MERC_SLOT                       = 445,
	SPA_STACKER_A                           = 446,
	SPA_STACKER_B                           = 447,
	SPA_STACKER_C                           = 448,
	SPA_STACKER_D                           = 449,
	SPA_DOT_GUARD                           = 450,
	SPA_MELEE_THRESHOLD_GUARD               = 451,
	SPA_SPELL_THRESHOLD_GUARD               = 452,
	SPA_MELEE_THRESHOLD_DOOM                = 453,
	SPA_SPELL_THRESHOLD_DOOM                = 454,
	SPA_ADD_HATE_PCT                        = 455,
	SPA_ADD_HATE_OVER_TIME_PCT              = 456,
	SPA_RESOURCE_TAP                        = 457,
	SPA_FACTION_MOD                         = 458,
	SPA_SKILL_DAMAGE_MOD_2                  = 459,
	SPA_OVERRIDE_NOT_FOCUSABLE              = 460,
	SPA_FOCUS_DAMAGE_MOD_2                  = 461,
	SPA_FOCUS_DAMAGE_AMT_2                  = 462,
	SPA_SHIELD                              = 463,
	SPA_PC_PET_RAMPAGE                      = 464,
	SPA_PC_PET_AE_RAMPAGE                   = 465,
	SPA_PC_PET_FLURRY                       = 466,
	SPA_DAMAGE_SHIELD_MITIGATION_AMT        = 467,
	SPA_DAMAGE_SHIELD_MITIGATION_PCT        = 468,
	SPA_CHANCE_BEST_IN_SPELL_GROUP          = 469,
	SPA_TRIGGER_BEST_IN_SPELL_GROUP         = 470,
	SPA_TRIGGER_BEST_SPELL_GROUP            = 470,
	SPA_DOUBLE_MELEE_ATTACKS                = 471,
	SPA_AA_BUY_NEXT_RANK                    = 472,
	SPA_DOUBLE_BACKSTAB_FRONT               = 473,
	SPA_PET_MELEE_CRIT_DMG_MOD              = 474,
	SPA_TRIGGER_SPELL_NON_ITEM              = 475,
	SPA_WEAPON_STANCE                       = 476,
	SPA_HATELIST_TO_TOP                     = 477,
	SPA_HATELIST_TO_TAIL                    = 478,
	SPA_FOCUS_LIMIT_MIN_VALUE               = 479,
	SPA_FOCUS_LIMIT_MAX_VALUE               = 480,
	SPA_FOCUS_CAST_SPELL_ON_LAND            = 481,
	SPA_SKILL_BASE_DAMAGE_MOD               = 482,
	SPA_FOCUS_INCOMING_DMG_MOD              = 483,
	SPA_FOCUS_INCOMING_DMG_AMT              = 484,
	SPA_FOCUS_LIMIT_CASTER_CLASS            = 485,
	SPA_FOCUS_LIMIT_SAME_CASTER             = 486,
	SPA_EXTEND_TRADESKILL_CAP               = 487,
	SPA_DEFENDER_MELEE_FORCE_PCT            = 488,
	SPA_WORN_ENDURANCE_REGEN_CAP            = 489,
	SPA_FOCUS_MIN_REUSE_TIME                = 490,
	SPA_FOCUS_MAX_REUSE_TIME                = 491,
	SPA_FOCUS_ENDURANCE_MIN                 = 492,
	SPA_FOCUS_ENDURANCE_MAX                 = 493,
	SPA_PET_ADD_ATK                         = 494,
	SPA_FOCUS_DURATION_MAX                  = 495,
	SPA_CRIT_MELEE_DMG_MOD_MAX              = 496,
	SPA_FOCUS_CAST_PROC_NO_BYPASS           = 497,
	SPA_ADD_EXTRA_PRIMARY_ATTACK_PCT        = 498,
	SPA_ADD_EXTRA_SECONDARY_ATTACK_PCT      = 499,
	SPA_FOCUS_CAST_TIME_MOD2                = 500,
	SPA_FOCUS_CAST_TIME_AMT                 = 501,
	SPA_FEARSTUN                            = 502,
	SPA_MELEE_DMG_POSITION_MOD              = 503,
	SPA_MELEE_DMG_POSITION_AMT              = 504,
	SPA_DMG_TAKEN_POSITION_MOD              = 505,
	SPA_DMG_TAKEN_POSITION_AMT              = 506,
	SPA_AMPLIFY_MOD                         = 507,
	SPA_AMPLIFY_AMT                         = 508,
	SPA_HEALTH_TRANSFER                     = 509,
	SPA_FOCUS_RESIST_INCOMING               = 510,

	// I renamed these, so these are here for backwards compatibility
	SPA_MOVEMENTRATE DEPRECATE("Use SPA_MOVEMENT_RATE instead") = SPA_MOVEMENT_RATE,
	SPA_PLAYERSIZE DEPRECATE("Use SPA_HEIGHT instead") = SPA_HEIGHT,
	SPA_SUMMONCORPSE DEPRECATE("Use SPA_SUMMON_CORPSE instead") = SPA_SUMMON_CORPSE,
	SPA_BARDOVERHASTE DEPRECATE("Use SPA_BARD_HASTE instead") = SPA_BARD_HASTE,
	SPA_SPELLDAMAGE DEPRECATE("Use SPA_FOCUS_DAMAGE_MOD instead") = SPA_FOCUS_DAMAGE_MOD,
	SPA_HEALING DEPRECATE("Use SPA_FOCUS_HEAL_MOD instead") = SPA_FOCUS_HEAL_MOD,
	SPA_REAGENTCHANCE DEPRECATE("Use SPA_FOCUS_REAGENT_MOD instead") = SPA_FOCUS_REAGENT_MOD,
	SPA_SPELLMANACOST DEPRECATE("Use SPA_FOCUS_MANACOST_MOD instead") = SPA_FOCUS_MANACOST_MOD,
	SPA_DOUBLEATTACK DEPRECATE("Use SPA_DOUBLE_ATTACK instead") = SPA_DOUBLE_ATTACK,
	SPA_STUNRESIST DEPRECATE("Use SPA_STUN_RESIST instead") = SPA_STUN_RESIST,
	SPA_PROCMOD DEPRECATE("Use SPA_PROC_CHANCE instead") = SPA_PROC_CHANCE,
	SPA_DIVINEREZ DEPRECATE("Use SPA_DIVINE_SAVE instead") = SPA_DIVINE_SAVE,
	SPA_TRIPLEBACKSTAB DEPRECATE("Use SPA_TRIPLE_BACKSTAB instead") = SPA_TRIPLE_BACKSTAB,
	SPA_PETFLURRY DEPRECATE("Use SPA_PET_FLURRY instead") = SPA_PET_FLURRY,
	SPA_SPELLCRITCHANCE DEPRECATE("Use SPA_SPELL_CRIT_CHANCE instead") = SPA_SPELL_CRIT_CHANCE,
	SPA_INCSPELLDMG DEPRECATE("Use SPA_FOCUS_DAMAGE_AMT_DETRIMENTAL instead") = SPA_FOCUS_DAMAGE_AMT_DETRIMENTAL,
	SPA_DAMAGECRITMOD DEPRECATE("Use SPA_FOCUS_DAMAGE_MOD_CRIT instead") = SPA_FOCUS_DAMAGE_MOD_CRIT,
	SPA_SHIELDBLOCKCHANCE DEPRECATE("Use SPA_SHIELD_BLOCK_CHANCE instead") = SPA_SHIELD_BLOCK_CHANCE,
	SPA_SPELLDAMAGETAKEN DEPRECATE("Use SPA_FOCUS_INCOMING_DMG_MOD instead") = SPA_FOCUS_INCOMING_DMG_MOD,
};

// actual size: 0x22e Feb 16 2018 test see 5F68F6 - eqmule
// actual size: 0x22d Apr 10 2018 test see 557362 - eqmule
// actual size: 0x229 May 07 2018 test see 6628CA  - eqmule
// actual size: 0x231 Oct 07 2019 test see 565BE2  - eqmule
// This is EQ_Spell
struct [[offsetcomments]] SPELL
{
/*0x000*/ float   Range;
/*0x004*/ float   AERange;
/*0x008*/ float   PushBack;
/*0x00c*/ float   PushUp;
/*0x010*/ DWORD   CastTime;
/*0x014*/ DWORD   RecoveryTime;
/*0x018*/ DWORD   RecastTime;
/*0x01c*/ DWORD   DurationType;                  // DurationFormula on Lucy
/*0x020*/ DWORD   DurationCap;
/*0x024*/ DWORD   AEDuration;
/*0x028*/ DWORD   ManaCost;
/*0x02c*/ float   Unknown0x02C;                  // See 565CB5 in eqgame oct 07 2019
/*0x030*/ DWORD   ReagentID[0x4];                // ReagentId1-ReagentId4d
/*0x040*/ DWORD   ReagentCount[0x4];             // ReagentCount1-ReagentCount4
/*0x050*/ DWORD   NoExpendReagent[0x4];
/*0x060*/ LONG    CalcIndex;
/*0x064*/ int     NumEffects;
/*0x068*/ DWORD   BookIcon;
/*0x06c*/ DWORD   GemIcon;
/*0x070*/ DWORD   DescriptionIndex;
/*0x074*/ DWORD   ResistAdj;
/*0x078*/ DWORD   Diety;
/*0x07c*/ DWORD   spaindex;
/*0x080*/ DWORD   SpellAnim;
/*0x084*/ DWORD   SpellIcon;
/*0x088*/ DWORD   DurationParticleEffect;
/*0x08c*/ DWORD   NPCUsefulness;
/*0x090*/ DWORD   ID;
/*0x094*/ DWORD   Autocast;                      // SpellID of spell to instacast on caster when current spell lands on target
/*0x098*/ DWORD   Category;                      // Unknown144 from lucy
/*0x09c*/ DWORD   Subcategory;                   // Subcat to Category. Unknown145 from lucy
/*0x0a0*/ DWORD   Subcategory2;
/*0x0a4*/ DWORD   HateMod;                       // Additional hate
/*0x0a8*/ DWORD   ResistPerLevel;
/*0x0ac*/ DWORD   ResistCap;
/*0x0b0*/ DWORD   EnduranceCost;                 // CA Endurance Cost
/*0x0b4*/ DWORD   EnduranceValue;                // Unsure
/*0x0b8*/ DWORD   ReuseTimerIndex;               // ID of combat timer, i think.
/*0x0bc*/ DWORD   EndurUpkeep;
/*0x0c0*/ DWORD   HateGenerated;                 // Hate override
/*0x0c4*/ DWORD   HitCountType;
/*0x0c8*/ DWORD   HitCount;
/*0x0cc*/ DWORD   ConeStartAngle;
/*0x0d0*/ DWORD   ConeEndAngle;
/*0x0d4*/ DWORD   PvPResistBase;
/*0x0d8*/ DWORD   PvPCalc;
/*0x0dc*/ DWORD   PvPResistCap;
/*0x0e0*/ DWORD   PvPDuration;                   // DurationType for PVP
/*0x0e4*/ DWORD   PvPDurationValue1;             // DurationValue1 for PVP

//*0x0e0*/   DWORD   GlobalGroup; this is gone now, this was only used to check for group type 46 before... uh, hp and mana regen effect spells i think
//see apr 10 test 2018 for reference:
//.text:004DA714 GlobalGroup:
//.text:004DA714                 cmp     dword ptr [eax+0E0h], 46

/*0x0e8*/ DWORD   PCNPCOnlyFlag;                 // no idea
/*0x0ec*/ DWORD   NPCMemCategory;
/*0x0f0*/ DWORD   SpellGroup;
/*0x0f4*/ DWORD   SpellSubGroup;                 // unknown237 on Lucy it is checked at 0x76FE18 in jun 11 2014 and if 0 will ask if we want to replace our spell with a rk. x version
/*0x0f8*/ int     SpellRank;                     // Unknown209 on Lucy jun 11 2014 0x76FEE0 Original = 1 , Rk. II = 5 , Rk. III = 10 , I suppose if they add Rk. IV it will be 15 and so on
/*0x0fc*/ DWORD   SpellClass;                    // Unknown222 from Lucy
/*0x100*/ DWORD   SpellSubClass;                 // Unknown223 from Lucy
/*0x104*/ DWORD   SpellReqAssociationID;
/*0x108*/ DWORD   CasterRequirementID;
/*0x10c*/ DWORD   MaxResist;
/*0x110*/ DWORD   MinResist;
/*0x114*/ DWORD   MinSpreadTime;
/*0x118*/ DWORD   MaxSpreadTime;
/*0x11c*/ DWORD   SpreadRadius;
/*0x120*/ DWORD   BaseEffectsFocusCap;           // song cap, maybe other things?
/*0x124*/ DWORD   CritChanceOverride;
/*0x128*/ DWORD   MaxTargets;                    // how many targets a spell will affect
/*0x12c*/ DWORD   AIValidTargets;
/*0x130*/ DWORD   BaseEffectsFocusOffset;
/*0x134*/ float   BaseEffectsFocusSlope;
/*0x138*/ CVector2 DistanceModStart;
/*0x140*/ CVector2 DistanceModEnd;
/*0x148*/ float   MinRange;
/*0x14c*/ BYTE    NoNPCLOS;                      // NPC skips LOS checks
/*0x14d*/ BYTE    Feedbackable;                  // nothing uses this
/*0x14e*/ BYTE    Reflectable;
/*0x14f*/ BYTE    NoPartialSave;
/*0x150*/ BYTE    NoResist;
/*0x151*/ BYTE    UsesPersistentParticles;
/*0x152*/ BYTE    SmallTargetsOnly;
/*0x153*/ bool    DurationWindow;                // 0=Long, 1=Short
/*0x154*/ BYTE    Uninterruptable;
/*0x155*/ BYTE    NotStackableDot;
/*0x156*/ BYTE    Deletable;
/*0x157*/ BYTE    BypassRegenCheck;
/*0x158*/ BYTE    CanCastInCombat;
/*0x159*/ BYTE    CanCastOutOfCombat;
/*0x15a*/ BYTE    NoHealDamageItemMod;           // disable worn focus bonuses
/*0x15b*/ BYTE    OnlyDuringFastRegen;
/*0x15c*/ BYTE    CastNotStanding;
/*0x15d*/ BYTE    CanMGB;
/*0x15e*/ bool    NoDisspell;
/*0x15f*/ BYTE    AffectInanimate;               // ldon trap spells etc
/*0x160*/ bool    IsSkill;
/*0x161*/ bool    bStacksWithDiscs;              // this was first seen in may 8 2017 test client, its checked if it's false at 0x451790. Ex: The Monk ability 'Drunken Monkey Style' or 'Breather'. see patch notes for that patch...
/*0x162*/ bool    ShowDoTMessage;
/*0x163*/ BYTE    ClassLevel[0x24];              // per class., yes there are allocations for 0x24 see 4B5776 in eqgame dated 12 mar 2014
/*0x187*/ BYTE    LightType;
/*0x188*/ BYTE    SpellType;                     // 0=detrimental, 1=Beneficial, 2=Beneficial, Group Only
/*0x189*/ BYTE    Resist;                        // see   4B0493 in apr 16 2018 exe        //0=un 1=mr 2=fr 3=cr 4=pr 5=dr 6=chromatic 7=prismatic 8=physical(skills,etc) 9=corruption
/*0x18a*/ BYTE    TargetType;                    // 03=Group v1, 04=PB AE, 05=Single, 06=Self, 08=Targeted AE, 0e=Pet, 28=AE PC v2, 29=Group v2, 2a=Directional
/*0x18b*/ BYTE    CastDifficulty;
/*0x18c*/ BYTE    Skill;
/*0x18d*/ BYTE    ZoneType;                      // 01=Outdoors, 02=dungeons, ff=Any
/*0x18e*/ BYTE    Environment;
/*0x18f*/ BYTE    TimeOfDay;                     // 0=any, 1=day only, 2=night only
/*0x190*/ BYTE    CastingAnim;
/*0x191*/ BYTE    AnimVariation;
/*0x192*/ BYTE    TargetAnim;
/*0x193*/ BYTE    TravelType;
/*0x194*/ BYTE    CancelOnSit;
/*0x195*/ bool    CountdownHeld;
/*0x196*/ char    Name[0x40];                    // for sure see 557AAA
/*0x1d6*/ char    Target[0x20];
/*0x1f6*/ char    Extra[0x20];                   // This is 'Extra' from Lucy (portal shortnames etc) official = NPC_FILENAME
/*0x216*/ BYTE    ShowWearOffMessage;
/*0x217*/ BYTE    NPCChanceofKnowingSpell;       // if this is 0 there is no way an npc can cast this spell...
/*0x218*/ BYTE    SneakAttack;
/*0x219*/ BYTE    NotFocusable;                  // ignores all(?) focus effects
/*0x21a*/ BYTE    NoHate;
/*0x21b*/ BYTE    StacksWithSelf;
/*0x21c*/ BYTE    CannotBeScribed;               // this is used by /outputfile missingspells see 7A57DF in Aug 10 2017 live
/*0x21d*/ BYTE    NoBuffBlock;
/*0x21e*/ bool    Scribable;                     // int?
/*0x21f*/ BYTE    NoStripOnDeath;
/*0x220*/ BYTE    NoRemove;                      // spell can't be clicked off?
/*0x224*/ int     NoOverwrite;                   // an enum 0 = Can Be overwritten 1 = Can Only be overwritten by itself 2 = Cannot be overwritten, not even by itself
/*0x228*/ DWORD   SpellRecourseType;
/*0x22c*/ BYTE    CRC32Marker[4];
/*0x230*/ float   DistanceMod;                   // set to (DistanceModEnd.Y- DistanceModEnd.X) / (DistanceModStart.Y - DistanceModStart.X).
/*0x234*/

	// Currently necessary because of MQ2DataTypes
	SPELL() { ZeroMemory(this, sizeof(SPELL)); }
};
using PSPELL = SPELL*;

struct [[offsetcomments]] SpellAffectData
{
/*0x00*/ int Slot = 0;
/*0x04*/ int Base = 0;
/*0x08*/ int Base2 = 0;
/*0x0c*/ int Max = 0;
/*0x10*/ int Calc = 0;
/*0x14*/ int Attrib = SPA_NOSPELL;
/*0x18*/
};
using SPELLCALCINFO = SpellAffectData;
using PSPELLCALCINFO = SPELLCALCINFO*;

constexpr int TOTAL_SPELL_COUNT = 62000; // # of spells allocated in memory (07/10/2019 test 4F1197)
constexpr int CalcInfoSize = 206000;     // 4E8814 in eqgame 2018 10 Apr test

// CalcInfoSize is 3 * TOTAL_SPELL_COUNT

// this is actually the size of the struct thats populated from aSpells_S_txt
// SpellManager__SpellManager_x
// size: 0x1966A8 2017-04-11 test (see 55DC54) - eqmule
// size: 0x1AED40 2018-04-10 test (see 5D32E2) - eqmule
// size: 0x1BC800 2019-07-10 test (see 5E36C2) - eqmule
struct [[offsetcomments]] SPELLMGR
{
	/*0x000000*/ void* vfTable;                       // need this for some calls later
/*0x000004*/ BYTE           Unknown0x00004[0x3DAE0];
/*0x03dae4*/ SPELL* Spells[TOTAL_SPELL_COUNT];    // 60000
/*0x07a3a4*/ SPELL* PtrToUnknownSpell;            // default bailout pointer...
/*0x07a3a8*/ SPELLCALCINFO* CalcInfo[CalcInfoSize];       // 200000
/*0x143668*/ DWORD          What1[0x6];
/*0x143680*/ DWORD          What2[0x1E460];               // 120000
/*0x1bc800*/ //(1820672) 1.8 mill! large struct in memory for sure...
};
using PSPELLMGR = SPELLMGR*;

class [[offsetcomments]] MercenaryAbilityEffectsDefinition
{
public:
/*0x00*/ void* vfTable;
/*0x04*/ int   ID;
/*0x08*/ int   AbilityID;
/*0x0c*/ int   FromID;
/*0x10*/ int   Base;
/*0x14*/ int   Base2;
/*0x18*/ int   LevelMod;
/*0x1c*/ int   Cap;
/*0x20*/ int   Slot;
/*0x24*/
};

struct [[offsetcomments]] FocusEffectData
{
/*0x00*/ int Type;
/*0x04*/ int Base;
/*0x08*/ int Base2;
/*0x0c*/ int Slot;
/*0x10*/
};

struct [[offsetcomments]] CachedFocusAbility
{
/*0x00*/ FocusEffectData* pEffectData;
/*0x04*/ int Percent;
/*0x08*/
};

class [[offsetcomments]] SpellCache
{
public:
	struct EffectCache
	{
		int SubIndex;
		int TotalPlayerEffects;
		int TotalItemEffects;
		bool bDegenerating;
		int TotalContrib;
	};

	struct AltEffectCache
	{
		int SubIndex;
		int AltTotal;
	};

	struct CachedFocusItem
	{
		CONTENTS* pContents;
		int	           Percent;
		ItemSpellTypes SpellType;
	};

	struct CachedFocusEffect
	{
		PSPELL     pSpell;
		int	       Percent;
		short      AffectIndex;
	};

	struct CachedFocusMercAbility
	{
		MercenaryAbilityEffectsDefinition* pAbilityEffectDef;
		int Percent;
	};

/*0x00*/ HashTable<EffectCache>* pCachedEffects;
/*0x04*/ bool                                       bCachedSpellEffects;
/*0x08*/ HashTable<AltEffectCache>* pCachedAltAbilityEffects;
/*0x0c*/ bool                                       bCachedAltEffects;
/*0x10*/ HashTable<EffectCache>* pCachedLimitedEffects;
/*0x14*/ bool                                       bCachedLimitedEffects;
/*0x18*/ HashTable<CachedFocusItem, int64_t>        CachedFocusItems;
/*0x28*/ HashTable<CachedFocusEffect, int64_t>      CachedFocusEffects;
/*0x38*/ HashTable<CachedFocusAbility, int64_t>     CachedFocusAbilities;
/*0x48*/ HashTable<CachedFocusMercAbility, int64_t> CachedFocusMercAbilities;
/*0x58*/
};


struct [[offsetcomments]] SlotData
{
/*0x00*/ LONG Slot;
/*0x04*/ DWORD Value;
/*0x08*/
};

// Size 0x58 20110810 - dkaa
// Size 0x58 20150326 - demonstar55
// Size 0x68 Apr 10 2018 test see 8B2FD5 - eqmule
// Size 0x68 Oct 07 2019 test see 8C9BAD - eqmule
// this is EQ_Affect todo: check the new stuff in it
struct [[offsetcomments]] SPELLBUFF
{
/*0x00*/ EqGuid    CasterGuid;
/*0x08*/ SlotData  SlotData[NUM_SLOTDATA];       // used for book keeping of various effects (debuff counter, rune/vie damage remaining)
/*0x38*/ DWORD     Flags;
/*0x3c*/ LONG      SpellID;                      // -1 or 0 for no spell..
/*0x40*/ DWORD     Duration;
/*0x44*/ DWORD     InitialDuration;
/*0x48*/ DWORD     HitCount;
/*0x4c*/ UINT      ViralTimer;                   // not 100% sure this is correct
/*0x50*/ FLOAT     Modifier;                     // Bard song modifier, 1.0 is default BaseDmgMod
/*0x54*/ FLOAT     Y;                            // Referenced by SPA 441 (distance removal)
/*0x58*/ FLOAT     X;
/*0x5c*/ FLOAT     Z;
/*0x60*/ BYTE      Type;
/*0x61*/ BYTE      Level;                        // casterlevel
/*0x62*/ BYTE      ChargesRemaining;             // dont think this is used anymore.
/*0x63*/ BYTE      Activatable;                  // dont think this is used anymore. We used to think this was DamageShield
/*0x64*/ DWORD     Unknown0x64;                  // not 100% sure this is correct it could be ViralTimer
/*0x68*/
	// Currently necessary because of MQ2DataTypes
	SPELLBUFF() { ZeroMemory(this, sizeof(SPELLBUFF)); }
};
using PSPELLBUFF [[deprecated]] = SPELLBUFF*;

} // namespace eqlib
