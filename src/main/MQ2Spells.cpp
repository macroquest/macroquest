/*
 * MacroQuest: The extension platform for EverQuest
 * Copyright (C) 2002-present MacroQuest Authors
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

#include "pch.h"
#include "MQ2Main.h"
#include "MQ2SpellSearch.h"
#include "mq/base/SimpleLexer.h"

namespace mq {

ci_unordered::multimap<std::string_view, EQ_Spell*> s_spellNameMap;
std::map<int, int> s_triggeredSpells;
std::recursive_mutex s_initializeSpellsMutex;

static const ci_unordered::map<std::string_view, eEQSPELLCAT> s_spellCatLookup = {
{ "Aegolism"            , SPELLCAT_AEGOLISM },
{ "Agility"             , SPELLCAT_AGILITY },
{ "Alliance"            , SPELLCAT_ALLIANCE },
{ "Animal"              , SPELLCAT_ANIMAL },
{ "Antonica"            , SPELLCAT_ANTONICA },
{ "Armor Class"         , SPELLCAT_ARMOR_CLASS },
{ "Attack"              , SPELLCAT_ATTACK },
{ "Bane"                , SPELLCAT_BANE },
{ "Blind"               , SPELLCAT_BLIND },
{ "Block"               , SPELLCAT_BLOCK },
{ "Calm"                , SPELLCAT_CALM },
{ "Charisma"            , SPELLCAT_CHARISMA },
{ "Charm"               , SPELLCAT_CHARM },
{ "Cold"                , SPELLCAT_COLD },
{ "Combat Abilities"    , SPELLCAT_COMBAT_ABILITIES },
{ "Combat Innates"      , SPELLCAT_COMBAT_INNATES },
{ "Conversions"         , SPELLCAT_CONVERSIONS },
{ "Create Item"         , SPELLCAT_CREATE_ITEM },
{ "Cure"                , SPELLCAT_CURE },
{ "Damage Over Time"    , SPELLCAT_DAMAGE_OVER_TIME },
{ "Damage Shield"       , SPELLCAT_DAMAGE_SHIELD },
{ "Defensive"           , SPELLCAT_DEFENSIVE },
{ "Destroy"             , SPELLCAT_DESTROY },
{ "Dexterity"           , SPELLCAT_DEXTERITY },
{ "Direct Damage"       , SPELLCAT_DIRECT_DAMAGE },
{ "Disarm Traps"        , SPELLCAT_DISARM_TRAPS },
{ "Disciplines"         , SPELLCAT_DISCIPLINES },
{ "Discord"             , SPELLCAT_DISCORD },
{ "Disease"             , SPELLCAT_DISEASE },
{ "Disempowering"       , SPELLCAT_DISEMPOWERING },
{ "Dispel"              , SPELLCAT_DISPEL },
{ "Duration Heals"      , SPELLCAT_DURATION_HEALS },
{ "Duration Tap"        , SPELLCAT_DURATION_TAP },
{ "Enchant Metal"       , SPELLCAT_ENCHANT_METAL },
{ "Enthrall"            , SPELLCAT_ENTHRALL },
{ "Faydwer"             , SPELLCAT_FAYDWER },
{ "Fear"                , SPELLCAT_FEAR },
{ "Fire"                , SPELLCAT_FIRE },
{ "Fizzle Rate"         , SPELLCAT_FIZZLE_RATE },
{ "Fumble"              , SPELLCAT_FUMBLE },
{ "Haste"               , SPELLCAT_HASTE },
{ "Heals"               , SPELLCAT_HEALS },
{ "Health"              , SPELLCAT_HEALTH },
{ "Health/Mana"         , SPELLCAT_HEALTH_MANA },
{ "HP Buffs"            , SPELLCAT_HP_BUFFS },
{ "HP type one"         , SPELLCAT_HP_TYPE_ONE },
{ "HP type two"         , SPELLCAT_HP_TYPE_TWO },
{ "Illusion: Other"     , SPELLCAT_ILLUSION_OTHER },
{ "Illusion: Adventurer", SPELLCAT_ILLUSION_ADVENTURER },
{ "Imbue Gem"           , SPELLCAT_IMBUE_GEM },
{ "Invisibility"        , SPELLCAT_INVISIBILITY },
{ "Invulnerability"     , SPELLCAT_INVULNERABILITY },
{ "Jolt"                , SPELLCAT_JOLT },
{ "Kunark"              , SPELLCAT_KUNARK },
{ "Levitate"            , SPELLCAT_LEVITATE },
{ "Life Flow"           , SPELLCAT_LIFE_FLOW },
{ "Luclin"              , SPELLCAT_LUCLIN },
{ "Magic"               , SPELLCAT_MAGIC },
{ "Mana"                , SPELLCAT_MANA },
{ "Mana Drain"          , SPELLCAT_MANA_DRAIN },
{ "Mana Flow"           , SPELLCAT_MANA_FLOW },
{ "Melee Guard"         , SPELLCAT_MELEE_GUARD },
{ "Memory Blur"         , SPELLCAT_MEMORY_BLUR },
{ "Misc"                , SPELLCAT_MISC },
{ "Movement"            , SPELLCAT_MOVEMENT },
{ "Objects"             , SPELLCAT_OBJECTS },
{ "Odus"                , SPELLCAT_ODUS },
{ "Offensive"           , SPELLCAT_OFFENSIVE },
{ "Pet"                 , SPELLCAT_PET },
{ "Pet Haste"           , SPELLCAT_PET_HASTE },
{ "Pet Misc Buffs"      , SPELLCAT_PET_MISC_BUFFS },
{ "Physical"            , SPELLCAT_PHYSICAL },
{ "Picklock"            , SPELLCAT_PICKLOCK },
{ "Plant"               , SPELLCAT_PLANT },
{ "Poison"              , SPELLCAT_POISON },
{ "Power Tap"           , SPELLCAT_POWER_TAP },
{ "Quick Heal"          , SPELLCAT_QUICK_HEAL },
{ "Reflection"          , SPELLCAT_REFLECTION },
{ "Regen"               , SPELLCAT_REGEN },
{ "Resist Buff"         , SPELLCAT_RESIST_BUFF },
{ "Resist Debuffs"      , SPELLCAT_RESIST_DEBUFFS },
{ "Resurrection"        , SPELLCAT_RESURRECTION },
{ "Root"                , SPELLCAT_ROOT },
{ "Rune"                , SPELLCAT_RUNE },
{ "Sense Trap"          , SPELLCAT_SENSE_TRAP },
{ "Shadowstep"          , SPELLCAT_SHADOWSTEP },
{ "Shielding"           , SPELLCAT_SHIELDING },
{ "Slow"                , SPELLCAT_SLOW },
{ "Snare"               , SPELLCAT_SNARE },
{ "Special"             , SPELLCAT_SPECIAL },
{ "Spell Focus"         , SPELLCAT_SPELL_FOCUS },
{ "Spell Guard"         , SPELLCAT_SPELL_GUARD },
{ "Spellshield"         , SPELLCAT_SPELLSHIELD },
{ "Stamina"             , SPELLCAT_STAMINA },
{ "Statistic Buffs"     , SPELLCAT_STATISTIC_BUFFS },
{ "Strength"            , SPELLCAT_STRENGTH },
{ "Stun"                , SPELLCAT_STUN },
{ "Sum: Air"            , SPELLCAT_SUM_AIR },
{ "Sum: Animation"      , SPELLCAT_SUM_ANIMATION },
{ "Sum: Earth"          , SPELLCAT_SUM_EARTH },
{ "Sum: Familiar"       , SPELLCAT_SUM_FAMILIAR },
{ "Sum: Fire"           , SPELLCAT_SUM_FIRE },
{ "Sum: Undead"         , SPELLCAT_SUM_UNDEAD },
{ "Sum: Warder"         , SPELLCAT_SUM_WARDER },
{ "Sum: Water"          , SPELLCAT_SUM_WATER },
{ "Summon Armor"        , SPELLCAT_SUMMON_ARMOR },
{ "Summon Focus"        , SPELLCAT_SUMMON_FOCUS },
{ "Summon Food/Water"   , SPELLCAT_SUMMON_FOOD_WATER },
{ "Summon Utility"      , SPELLCAT_SUMMON_UTILITY },
{ "Summon Weapon"       , SPELLCAT_SUMMON_WEAPON },
{ "Summoned"            , SPELLCAT_SUMMONED },
{ "Symbol"              , SPELLCAT_SYMBOL },
{ "Taelosia"            , SPELLCAT_TAELOSIA },
{ "Taps"                , SPELLCAT_TAPS },
{ "Techniques"          , SPELLCAT_TECHNIQUES },
{ "The Planes"          , SPELLCAT_THE_PLANES },
{ "Timer 1"             , SPELLCAT_TIMER_1 },
{ "Timer 2"             , SPELLCAT_TIMER_2 },
{ "Timer 3"             , SPELLCAT_TIMER_3 },
{ "Timer 4"             , SPELLCAT_TIMER_4 },
{ "Timer 5"             , SPELLCAT_TIMER_5 },
{ "Timer 6"             , SPELLCAT_TIMER_6 },
{ "Transport"           , SPELLCAT_TRANSPORT },
{ "Undead"              , SPELLCAT_UNDEAD },
{ "Utility Beneficial"  , SPELLCAT_UTILITY_BENEFICIAL },
{ "Utility Detrimental" , SPELLCAT_UTILITY_DETRIMENTAL },
{ "Velious"             , SPELLCAT_VELIOUS },
{ "Visages"             , SPELLCAT_VISAGES },
{ "Vision"              , SPELLCAT_VISION },
{ "Wisdom/Intelligence" , SPELLCAT_WISDOM_INTELLIGENCE },
{ "Traps"               , SPELLCAT_TRAPS },
{ "Auras"               , SPELLCAT_AURAS },
{ "Endurance"           , SPELLCAT_ENDURANCE },
{ "Serpent's Spine"     , SPELLCAT_SERPENTS_SPINE },
{ "Corruption"          , SPELLCAT_CORRUPTION },
{ "Learning"            , SPELLCAT_LEARNING },
{ "Chromatic"           , SPELLCAT_CHROMATIC },
{ "Prismatic"           , SPELLCAT_PRISMATIC },
{ "Sum: Swarm"          , SPELLCAT_SUM_SWARM },
{ "Delayed"             , SPELLCAT_DELAYED },
{ "Temporary"           , SPELLCAT_TEMPORARY },
{ "Twincast"            , SPELLCAT_TWINCAST },
{ "Sum: Bodyguard"      , SPELLCAT_SUM_BODYGUARD },
{ "Humanoid"            , SPELLCAT_HUMANOID },
{ "Haste/Spell Focus"   , SPELLCAT_HASTE_SPELL_FOCUS },
{ "Timer 7"             , SPELLCAT_TIMER_7 },
{ "Timer 8"             , SPELLCAT_TIMER_8 },
{ "Timer 9"             , SPELLCAT_TIMER_9 },
{ "Timer 10"            , SPELLCAT_TIMER_10 },
{ "Timer 11"            , SPELLCAT_TIMER_11 },
{ "Timer 12"            , SPELLCAT_TIMER_12 },
{ "Hatred"              , SPELLCAT_HATRED },
{ "Fast"                , SPELLCAT_FAST },
{ "Illusion: Special"   , SPELLCAT_ILLUSION_SPECIAL },
{ "Timer 13"            , SPELLCAT_TIMER_13 },
{ "Timer 14"            , SPELLCAT_TIMER_14 },
{ "Timer 15"            , SPELLCAT_TIMER_15 },
{ "Timer 16"            , SPELLCAT_TIMER_16 },
{ "Timer 17"            , SPELLCAT_TIMER_17 },
{ "Timer 18"            , SPELLCAT_TIMER_18 },
{ "Timer 19"            , SPELLCAT_TIMER_19 },
{ "Timer 20"            , SPELLCAT_TIMER_20 },
{ "Alaris"              , SPELLCAT_ALARIS },
{ "Combination"         , SPELLCAT_COMBINATION },
{ "Independent"         , SPELLCAT_INDEPENDENT },
{ "Skill Attacks"       , SPELLCAT_SKILL_ATTACKS },
{ "Incoming"            , SPELLCAT_INCOMING },
{ "Curse"               , SPELLCAT_CURSE },
{ "Timer 21"            , SPELLCAT_TIMER_21 },
{ "Timer 22"            , SPELLCAT_TIMER_22 },
{ "Timer 23"            , SPELLCAT_TIMER_23 },
{ "Timer 24"            , SPELLCAT_TIMER_24 },
{ "Timer 25"            , SPELLCAT_TIMER_25 },
{ "Drunkenness"         , SPELLCAT_DRUNKENNESS },
{ "Throwing"            , SPELLCAT_THROWING },
{ "Melee Damage"        , SPELLCAT_MELEE_DAMAGE },
};

static const ci_unordered::map<std::string_view, eEQSPA> s_spaLookup = {
{ "HP"                                , SPA_HP },
{ "AC"                                , SPA_AC },
{ "ATTACK_POWER"                      , SPA_ATTACK_POWER },
{ "MOVEMENT_RATE"                     , SPA_MOVEMENT_RATE },
{ "STR"                               , SPA_STR },
{ "DEX"                               , SPA_DEX },
{ "AGI"                               , SPA_AGI },
{ "STA"                               , SPA_STA },
{ "INT"                               , SPA_INT },
{ "WIS"                               , SPA_WIS },
{ "CHA"                               , SPA_CHA },
{ "HASTE"                             , SPA_HASTE },
{ "INVISIBILITY"                      , SPA_INVISIBILITY },
{ "SEE_INVIS"                         , SPA_SEE_INVIS },
{ "ENDURING_BREATH"                   , SPA_ENDURING_BREATH },
{ "MANA"                              , SPA_MANA },
{ "NPC_FRENZY"                        , SPA_NPC_FRENZY },
{ "NPC_AWARENESS"                     , SPA_NPC_AWARENESS },
{ "NPC_AGGRO"                         , SPA_NPC_AGGRO },
{ "NPC_FACTION"                       , SPA_NPC_FACTION },
{ "BLINDNESS"                         , SPA_BLINDNESS },
{ "STUN"                              , SPA_STUN },
{ "CHARM"                             , SPA_CHARM },
{ "FEAR"                              , SPA_FEAR },
{ "FATIGUE"                           , SPA_FATIGUE },
{ "BIND_AFFINITY"                     , SPA_BIND_AFFINITY },
{ "GATE"                              , SPA_GATE },
{ "DISPEL_MAGIC"                      , SPA_DISPEL_MAGIC },
{ "INVIS_VS_UNDEAD"                   , SPA_INVIS_VS_UNDEAD },
{ "INVIS_VS_ANIMALS"                  , SPA_INVIS_VS_ANIMALS },
{ "NPC_AGGRO_RADIUS"                  , SPA_NPC_AGGRO_RADIUS },
{ "ENTHRALL"                          , SPA_ENTHRALL },
{ "CREATE_ITEM"                       , SPA_CREATE_ITEM },
{ "SUMMON_PET"                        , SPA_SUMMON_PET },
{ "CONFUSE"                           , SPA_CONFUSE },
{ "DISEASE"                           , SPA_DISEASE },
{ "POISON"                            , SPA_POISON },
{ "DETECT_HOSTILE"                    , SPA_DETECT_HOSTILE },
{ "DETECT_MAGIC"                      , SPA_DETECT_MAGIC },
{ "NO_TWINCAST"                       , SPA_NO_TWINCAST },
{ "INVULNERABILITY"                   , SPA_INVULNERABILITY },
{ "BANISH"                            , SPA_BANISH },
{ "SHADOW_STEP"                       , SPA_SHADOW_STEP },
{ "BERSERK"                           , SPA_BERSERK },
{ "LYCANTHROPY"                       , SPA_LYCANTHROPY },
{ "VAMPIRISM"                         , SPA_VAMPIRISM },
{ "RESIST_FIRE"                       , SPA_RESIST_FIRE },
{ "RESIST_COLD"                       , SPA_RESIST_COLD },
{ "RESIST_POISON"                     , SPA_RESIST_POISON },
{ "RESIST_DISEASE"                    , SPA_RESIST_DISEASE },
{ "RESIST_MAGIC"                      , SPA_RESIST_MAGIC },
{ "DETECT_TRAPS"                      , SPA_DETECT_TRAPS },
{ "DETECT_UNDEAD"                     , SPA_DETECT_UNDEAD },
{ "DETECT_SUMMONED"                   , SPA_DETECT_SUMMONED },
{ "DETECT_ANIMALS"                    , SPA_DETECT_ANIMALS },
{ "STONESKIN"                         , SPA_STONESKIN },
{ "TRUE_NORTH"                        , SPA_TRUE_NORTH },
{ "LEVITATION"                        , SPA_LEVITATION },
{ "CHANGE_FORM"                       , SPA_CHANGE_FORM },
{ "DAMAGE_SHIELD"                     , SPA_DAMAGE_SHIELD },
{ "TRANSFER_ITEM"                     , SPA_TRANSFER_ITEM },
{ "ITEM_LORE"                         , SPA_ITEM_LORE },
{ "ITEM_IDENTIFY"                     , SPA_ITEM_IDENTIFY },
{ "NPC_WIPE_HATE_LIST"                , SPA_NPC_WIPE_HATE_LIST },
{ "SPIN_STUN"                         , SPA_SPIN_STUN },
{ "INFRAVISION"                       , SPA_INFRAVISION },
{ "ULTRAVISION"                       , SPA_ULTRAVISION },
{ "EYE_OF_ZOMM"                       , SPA_EYE_OF_ZOMM },
{ "RECLAIM_ENERGY"                    , SPA_RECLAIM_ENERGY },
{ "MAX_HP"                            , SPA_MAX_HP },
{ "CORPSE_BOMB"                       , SPA_CORPSE_BOMB },
{ "CREATE_UNDEAD"                     , SPA_CREATE_UNDEAD },
{ "PRESERVE_CORPSE"                   , SPA_PRESERVE_CORPSE },
{ "BIND_SIGHT"                        , SPA_BIND_SIGHT },
{ "FEIGN_DEATH"                       , SPA_FEIGN_DEATH },
{ "VENTRILOQUISM"                     , SPA_VENTRILOQUISM },
{ "SENTINEL"                          , SPA_SENTINEL },
{ "LOCATE_CORPSE"                     , SPA_LOCATE_CORPSE },
{ "SPELL_SHIELD"                      , SPA_SPELL_SHIELD },
{ "INSTANT_HP"                        , SPA_INSTANT_HP },
{ "ENCHANT_LIGHT"                     , SPA_ENCHANT_LIGHT },
{ "RESURRECT"                         , SPA_RESURRECT },
{ "SUMMON_TARGET"                     , SPA_SUMMON_TARGET },
{ "PORTAL"                            , SPA_PORTAL },
{ "HP_NPC_ONLY"                       , SPA_HP_NPC_ONLY },
{ "MELEE_PROC"                        , SPA_MELEE_PROC },
{ "NPC_HELP_RADIUS"                   , SPA_NPC_HELP_RADIUS },
{ "MAGNIFICATION"                     , SPA_MAGNIFICATION },
{ "EVACUATE"                          , SPA_EVACUATE },
{ "HEIGHT"                            , SPA_HEIGHT },
{ "IGNORE_PET"                        , SPA_IGNORE_PET },
{ "SUMMON_CORPSE"                     , SPA_SUMMON_CORPSE },
{ "HATE"                              , SPA_HATE },
{ "WEATHER_CONTROL"                   , SPA_WEATHER_CONTROL },
{ "FRAGILE"                           , SPA_FRAGILE },
{ "SACRIFICE"                         , SPA_SACRIFICE },
{ "SILENCE"                           , SPA_SILENCE },
{ "MAX_MANA"                          , SPA_MAX_MANA },
{ "BARD_HASTE"                        , SPA_BARD_HASTE },
{ "ROOT"                              , SPA_ROOT },
{ "HEALDOT"                           , SPA_HEALDOT },
{ "COMPLETEHEAL"                      , SPA_COMPLETEHEAL },
{ "PET_FEARLESS"                      , SPA_PET_FEARLESS },
{ "CALL_PET"                          , SPA_CALL_PET },
{ "TRANSLOCATE"                       , SPA_TRANSLOCATE },
{ "NPC_ANTI_GATE"                     , SPA_NPC_ANTI_GATE },
{ "BEASTLORD_PET"                     , SPA_BEASTLORD_PET },
{ "ALTER_PET_LEVEL"                   , SPA_ALTER_PET_LEVEL },
{ "FAMILIAR"                          , SPA_FAMILIAR },
{ "CREATE_ITEM_IN_BAG"                , SPA_CREATE_ITEM_IN_BAG },
{ "ARCHERY"                           , SPA_ARCHERY },
{ "RESIST_ALL"                        , SPA_RESIST_ALL },
{ "FIZZLE_SKILL"                      , SPA_FIZZLE_SKILL },
{ "SUMMON_MOUNT"                      , SPA_SUMMON_MOUNT },
{ "MODIFY_HATE"                       , SPA_MODIFY_HATE },
{ "CORNUCOPIA"                        , SPA_CORNUCOPIA },
{ "CURSE"                             , SPA_CURSE },
{ "HIT_MAGIC"                         , SPA_HIT_MAGIC },
{ "AMPLIFICATION"                     , SPA_AMPLIFICATION },
{ "ATTACK_SPEED_MAX"                  , SPA_ATTACK_SPEED_MAX },
{ "HEALMOD"                           , SPA_HEALMOD },
{ "IRONMAIDEN"                        , SPA_IRONMAIDEN },
{ "REDUCESKILL"                       , SPA_REDUCESKILL },
{ "IMMUNITY"                          , SPA_IMMUNITY },
{ "FOCUS_DAMAGE_MOD"                  , SPA_FOCUS_DAMAGE_MOD },
{ "FOCUS_HEAL_MOD"                    , SPA_FOCUS_HEAL_MOD },
{ "FOCUS_RESIST_MOD"                  , SPA_FOCUS_RESIST_MOD },
{ "FOCUS_CAST_TIME_MOD"               , SPA_FOCUS_CAST_TIME_MOD },
{ "FOCUS_DURATION_MOD"                , SPA_FOCUS_DURATION_MOD },
{ "FOCUS_RANGE_MOD"                   , SPA_FOCUS_RANGE_MOD },
{ "FOCUS_HATE_MOD"                    , SPA_FOCUS_HATE_MOD },
{ "FOCUS_REAGENT_MOD"                 , SPA_FOCUS_REAGENT_MOD },
{ "FOCUS_MANACOST_MOD"                , SPA_FOCUS_MANACOST_MOD },
{ "FOCUS_STUNTIME_MOD"                , SPA_FOCUS_STUNTIME_MOD },
{ "FOCUS_LEVEL_MAX"                   , SPA_FOCUS_LEVEL_MAX },
{ "FOCUS_RESIST_TYPE"                 , SPA_FOCUS_RESIST_TYPE },
{ "FOCUS_TARGET_TYPE"                 , SPA_FOCUS_TARGET_TYPE },
{ "FOCUS_WHICH_SPA"                   , SPA_FOCUS_WHICH_SPA },
{ "FOCUS_BENEFICIAL"                  , SPA_FOCUS_BENEFICIAL },
{ "FOCUS_WHICH_SPELL"                 , SPA_FOCUS_WHICH_SPELL },
{ "FOCUS_DURATION_MIN"                , SPA_FOCUS_DURATION_MIN },
{ "FOCUS_INSTANT_ONLY"                , SPA_FOCUS_INSTANT_ONLY },
{ "FOCUS_LEVEL_MIN"                   , SPA_FOCUS_LEVEL_MIN },
{ "FOCUS_CASTTIME_MIN"                , SPA_FOCUS_CASTTIME_MIN },
{ "FOCUS_CASTTIME_MAX"                , SPA_FOCUS_CASTTIME_MAX },
{ "NPC_PORTAL_WARDER_BANISH"          , SPA_NPC_PORTAL_WARDER_BANISH },
{ "PORTAL_LOCATIONS"                  , SPA_PORTAL_LOCATIONS },
{ "PERCENT_HEAL"                      , SPA_PERCENT_HEAL },
{ "STACKING_BLOCK"                    , SPA_STACKING_BLOCK },
{ "STRIP_VIRTUAL_SLOT"                , SPA_STRIP_VIRTUAL_SLOT },
{ "DIVINE_INTERVENTION"               , SPA_DIVINE_INTERVENTION },
{ "POCKET_PET"                        , SPA_POCKET_PET },
{ "PET_SWARM"                         , SPA_PET_SWARM },
{ "HEALTH_BALANCE"                    , SPA_HEALTH_BALANCE },
{ "CANCEL_NEGATIVE_MAGIC"             , SPA_CANCEL_NEGATIVE_MAGIC },
{ "POP_RESURRECT"                     , SPA_POP_RESURRECT },
{ "MIRROR"                            , SPA_MIRROR },
{ "FEEDBACK"                          , SPA_FEEDBACK },
{ "REFLECT"                           , SPA_REFLECT },
{ "MODIFY_ALL_STATS"                  , SPA_MODIFY_ALL_STATS },
{ "CHANGE_SOBRIETY"                   , SPA_CHANGE_SOBRIETY },
{ "SPELL_GUARD"                       , SPA_SPELL_GUARD },
{ "MELEE_GUARD"                       , SPA_MELEE_GUARD },
{ "ABSORB_HIT"                        , SPA_ABSORB_HIT },
{ "OBJECT_SENSE_TRAP"                 , SPA_OBJECT_SENSE_TRAP },
{ "OBJECT_DISARM_TRAP"                , SPA_OBJECT_DISARM_TRAP },
{ "OBJECT_PICKLOCK"                   , SPA_OBJECT_PICKLOCK },
{ "FOCUS_PET"                         , SPA_FOCUS_PET },
{ "DEFENSIVE"                         , SPA_DEFENSIVE },
{ "CRITICAL_MELEE"                    , SPA_CRITICAL_MELEE },
{ "CRITICAL_SPELL"                    , SPA_CRITICAL_SPELL },
{ "CRIPPLING_BLOW"                    , SPA_CRIPPLING_BLOW },
{ "EVASION"                           , SPA_EVASION },
{ "RIPOSTE"                           , SPA_RIPOSTE },
{ "DODGE"                             , SPA_DODGE },
{ "PARRY"                             , SPA_PARRY },
{ "DUAL_WIELD"                        , SPA_DUAL_WIELD },
{ "DOUBLE_ATTACK"                     , SPA_DOUBLE_ATTACK },
{ "MELEE_LIFETAP"                     , SPA_MELEE_LIFETAP },
{ "PURETONE"                          , SPA_PURETONE },
{ "SANCTIFICATION"                    , SPA_SANCTIFICATION },
{ "FEARLESS"                          , SPA_FEARLESS },
{ "HUNDRED_HANDS"                     , SPA_HUNDRED_HANDS },
{ "SKILL_INCREASE_CHANCE"             , SPA_SKILL_INCREASE_CHANCE },
{ "ACCURACY"                          , SPA_ACCURACY },
{ "SKILL_DAMAGE_MOD"                  , SPA_SKILL_DAMAGE_MOD },
{ "MIN_DAMAGE_DONE_MOD"               , SPA_MIN_DAMAGE_DONE_MOD },
{ "MANA_BALANCE"                      , SPA_MANA_BALANCE },
{ "BLOCK"                             , SPA_BLOCK },
{ "ENDURANCE"                         , SPA_ENDURANCE },
{ "INCREASE_MAX_ENDURANCE"            , SPA_INCREASE_MAX_ENDURANCE },
{ "AMNESIA"                           , SPA_AMNESIA },
{ "HATE_OVER_TIME"                    , SPA_HATE_OVER_TIME },
{ "SKILL_ATTACK"                      , SPA_SKILL_ATTACK },
{ "FADE"                              , SPA_FADE },
{ "STUN_RESIST"                       , SPA_STUN_RESIST },
{ "STRIKETHROUGH1"                    , SPA_STRIKETHROUGH1 },
{ "SKILL_DAMAGE_TAKEN"                , SPA_SKILL_DAMAGE_TAKEN },
{ "INSTANT_ENDURANCE"                 , SPA_INSTANT_ENDURANCE },
{ "TAUNT"                             , SPA_TAUNT },
{ "PROC_CHANCE"                       , SPA_PROC_CHANCE },
{ "RANGE_ABILITY"                     , SPA_RANGE_ABILITY },
{ "ILLUSION_OTHERS"                   , SPA_ILLUSION_OTHERS },
{ "MASS_GROUP_BUFF"                   , SPA_MASS_GROUP_BUFF },
{ "GROUP_FEAR_IMMUNITY"               , SPA_GROUP_FEAR_IMMUNITY },
{ "RAMPAGE"                           , SPA_RAMPAGE },
{ "AE_TAUNT"                          , SPA_AE_TAUNT },
{ "FLESH_TO_BONE"                     , SPA_FLESH_TO_BONE },
{ "PURGE_POISON"                      , SPA_PURGE_POISON },
{ "CANCEL_BENEFICIAL"                 , SPA_CANCEL_BENEFICIAL },
{ "SHIELD_CASTER"                     , SPA_SHIELD_CASTER },
{ "DESTRUCTIVE_FORCE"                 , SPA_DESTRUCTIVE_FORCE },
{ "FOCUS_FRENZIED_DEVASTATION"        , SPA_FOCUS_FRENZIED_DEVASTATION },
{ "PET_PCT_MAX_HP"                    , SPA_PET_PCT_MAX_HP },
{ "HP_MAX_HP"                         , SPA_HP_MAX_HP },
{ "PET_PCT_AVOIDANCE"                 , SPA_PET_PCT_AVOIDANCE },
{ "MELEE_ACCURACY"                    , SPA_MELEE_ACCURACY },
{ "HEADSHOT"                          , SPA_HEADSHOT },
{ "PET_CRIT_MELEE"                    , SPA_PET_CRIT_MELEE },
{ "SLAY_UNDEAD"                       , SPA_SLAY_UNDEAD },
{ "INCREASE_SKILL_DAMAGE"             , SPA_INCREASE_SKILL_DAMAGE },
{ "REDUCE_WEIGHT"                     , SPA_REDUCE_WEIGHT },
{ "BLOCK_BEHIND"                      , SPA_BLOCK_BEHIND },
{ "DOUBLE_RIPOSTE"                    , SPA_DOUBLE_RIPOSTE },
{ "ADD_RIPOSTE"                       , SPA_ADD_RIPOSTE },
{ "GIVE_DOUBLE_ATTACK"                , SPA_GIVE_DOUBLE_ATTACK },
{ "2H_BASH"                           , SPA_2H_BASH },
{ "REDUCE_SKILL_TIMER"                , SPA_REDUCE_SKILL_TIMER },
{ "ACROBATICS"                        , SPA_ACROBATICS },
{ "CAST_THROUGH_STUN"                 , SPA_CAST_THROUGH_STUN },
{ "EXTENDED_SHIELDING"                , SPA_EXTENDED_SHIELDING },
{ "BASH_CHANCE"                       , SPA_BASH_CHANCE },
{ "DIVINE_SAVE"                       , SPA_DIVINE_SAVE },
{ "METABOLISM"                        , SPA_METABOLISM },
{ "POISON_MASTERY"                    , SPA_POISON_MASTERY },
{ "FOCUS_CHANNELING"                  , SPA_FOCUS_CHANNELING },
{ "FREE_PET"                          , SPA_FREE_PET },
{ "PET_AFFINITY"                      , SPA_PET_AFFINITY },
{ "PERM_ILLUSION"                     , SPA_PERM_ILLUSION },
{ "STONEWALL"                         , SPA_STONEWALL },
{ "STRING_UNBREAKABLE"                , SPA_STRING_UNBREAKABLE },
{ "IMPROVE_RECLAIM_ENERGY"            , SPA_IMPROVE_RECLAIM_ENERGY },
{ "INCREASE_CHANGE_MEMWIPE"           , SPA_INCREASE_CHANGE_MEMWIPE },
{ "ENHANCED_CHARM"                    , SPA_ENHANCED_CHARM },
{ "ENHANCED_ROOT"                     , SPA_ENHANCED_ROOT },
{ "TRAP_CIRCUMVENTION"                , SPA_TRAP_CIRCUMVENTION },
{ "INCREASE_AIR_SUPPLY"               , SPA_INCREASE_AIR_SUPPLY },
{ "INCREASE_MAX_SKILL"                , SPA_INCREASE_MAX_SKILL },
{ "EXTRA_SPECIALIZATION"              , SPA_EXTRA_SPECIALIZATION },
{ "OFFHAND_MIN_WEAPON_DAMAGE"         , SPA_OFFHAND_MIN_WEAPON_DAMAGE },
{ "INCREASE_PROC_CHANCE"              , SPA_INCREASE_PROC_CHANCE },
{ "ENDLESS_QUIVER"                    , SPA_ENDLESS_QUIVER },
{ "BACKSTAB_FRONT"                    , SPA_BACKSTAB_FRONT },
{ "CHAOTIC_STAB"                      , SPA_CHAOTIC_STAB },
{ "NOSPELL"                           , SPA_NOSPELL },
{ "SHIELDING_DURATION_MOD"            , SPA_SHIELDING_DURATION_MOD },
{ "SHROUD_OF_STEALTH"                 , SPA_SHROUD_OF_STEALTH },
{ "GIVE_PET_HOLD"                     , SPA_GIVE_PET_HOLD },
{ "TRIPLE_BACKSTAB"                   , SPA_TRIPLE_BACKSTAB },
{ "AC_LIMIT_MOD"                      , SPA_AC_LIMIT_MOD },
{ "ADD_INSTRUMENT_MOD"                , SPA_ADD_INSTRUMENT_MOD },
{ "SONG_MOD_CAP"                      , SPA_SONG_MOD_CAP },
{ "INCREASE_STAT_CAP"                 , SPA_INCREASE_STAT_CAP },
{ "TRADESKILL_MASTERY"                , SPA_TRADESKILL_MASTERY },
{ "REDUCE_AA_TIMER"                   , SPA_REDUCE_AA_TIMER },
{ "NO_FIZZLE"                         , SPA_NO_FIZZLE },
{ "ADD_2H_ATTACK_CHANCE"              , SPA_ADD_2H_ATTACK_CHANCE },
{ "ADD_PET_COMMANDS"                  , SPA_ADD_PET_COMMANDS },
{ "ALCHEMY_FAIL_RATE"                 , SPA_ALCHEMY_FAIL_RATE },
{ "FIRST_AID"                         , SPA_FIRST_AID },
{ "EXTEND_SONG_RANGE"                 , SPA_EXTEND_SONG_RANGE },
{ "BASE_RUN_MOD"                      , SPA_BASE_RUN_MOD },
{ "INCREASE_CASTING_LEVEL"            , SPA_INCREASE_CASTING_LEVEL },
{ "DOTCRIT"                           , SPA_DOTCRIT },
{ "HEALCRIT"                          , SPA_HEALCRIT },
{ "MENDCRIT"                          , SPA_MENDCRIT },
{ "DUAL_WIELD_AMT"                    , SPA_DUAL_WIELD_AMT },
{ "EXTRA_DI_CHANCE"                   , SPA_EXTRA_DI_CHANCE },
{ "FINISHING_BLOW"                    , SPA_FINISHING_BLOW },
{ "FLURRY"                            , SPA_FLURRY },
{ "PET_FLURRY"                        , SPA_PET_FLURRY },
{ "PET_FEIGN"                         , SPA_PET_FEIGN },
{ "INCREASE_BANDAGE_AMT"              , SPA_INCREASE_BANDAGE_AMT },
{ "WU_ATTACK"                         , SPA_WU_ATTACK },
{ "IMPROVE_LOH"                       , SPA_IMPROVE_LOH },
{ "NIMBLE_EVASION"                    , SPA_NIMBLE_EVASION },
{ "FOCUS_DAMAGE_AMT"                  , SPA_FOCUS_DAMAGE_AMT },
{ "FOCUS_DURATION_AMT"                , SPA_FOCUS_DURATION_AMT },
{ "ADD_PROC_HIT"                      , SPA_ADD_PROC_HIT },
{ "DOOM_EFFECT"                       , SPA_DOOM_EFFECT },
{ "INCREASE_RUN_SPEED_CAP"            , SPA_INCREASE_RUN_SPEED_CAP },
{ "PURIFY"                            , SPA_PURIFY },
{ "STRIKETHROUGH"                     , SPA_STRIKETHROUGH },
{ "STUN_RESIST2"                      , SPA_STUN_RESIST2 },
{ "SPELL_CRIT_CHANCE"                 , SPA_SPELL_CRIT_CHANCE },
{ "REDUCE_SPECIAL_TIMER"              , SPA_REDUCE_SPECIAL_TIMER },
{ "FOCUS_DAMAGE_MOD_DETRIMENTAL"      , SPA_FOCUS_DAMAGE_MOD_DETRIMENTAL },
{ "FOCUS_DAMAGE_AMT_DETRIMENTAL"      , SPA_FOCUS_DAMAGE_AMT_DETRIMENTAL },
{ "TINY_COMPANION"                    , SPA_TINY_COMPANION },
{ "WAKE_DEAD"                         , SPA_WAKE_DEAD },
{ "DOPPELGANGER"                      , SPA_DOPPELGANGER },
{ "INCREASE_RANGE_DMG"                , SPA_INCREASE_RANGE_DMG },
{ "FOCUS_DAMAGE_MOD_CRIT"             , SPA_FOCUS_DAMAGE_MOD_CRIT },
{ "FOCUS_DAMAGE_AMT_CRIT"             , SPA_FOCUS_DAMAGE_AMT_CRIT },
{ "SECONDARY_RIPOSTE_MOD"             , SPA_SECONDARY_RIPOSTE_MOD },
{ "DAMAGE_SHIELD_MOD"                 , SPA_DAMAGE_SHIELD_MOD },
{ "WEAK_DEAD_2"                       , SPA_WEAK_DEAD_2 },
{ "APPRAISAL"                         , SPA_APPRAISAL },
{ "ZONE_SUSPEND_MINION"               , SPA_ZONE_SUSPEND_MINION },
{ "TELEPORT_CASTERS_BINDPOINT"        , SPA_TELEPORT_CASTERS_BINDPOINT },
{ "FOCUS_REUSE_TIMER"                 , SPA_FOCUS_REUSE_TIMER },
{ "FOCUS_COMBAT_SKILL"                , SPA_FOCUS_COMBAT_SKILL },
{ "OBSERVER"                          , SPA_OBSERVER },
{ "FORAGE_MASTER"                     , SPA_FORAGE_MASTER },
{ "IMPROVED_INVIS"                    , SPA_IMPROVED_INVIS },
{ "IMPROVED_INVIS_UNDEAD"             , SPA_IMPROVED_INVIS_UNDEAD },
{ "IMPROVED_INVIS_ANIMALS"            , SPA_IMPROVED_INVIS_ANIMALS },
{ "INCREASE_WORN_HP_REGEN_CAP"        , SPA_INCREASE_WORN_HP_REGEN_CAP },
{ "INCREASE_WORN_MANA_REGEN_CAP"      , SPA_INCREASE_WORN_MANA_REGEN_CAP },
{ "CRITICAL_HP_REGEN"                 , SPA_CRITICAL_HP_REGEN },
{ "SHIELD_BLOCK_CHANCE"               , SPA_SHIELD_BLOCK_CHANCE },
{ "REDUCE_TARGET_HATE"                , SPA_REDUCE_TARGET_HATE },
{ "GATE_STARTING_CITY"                , SPA_GATE_STARTING_CITY },
{ "DEFENSIVE_PROC"                    , SPA_DEFENSIVE_PROC },
{ "HP_FOR_MANA"                       , SPA_HP_FOR_MANA },
{ "NO_BREAK_AE_SNEAK"                 , SPA_NO_BREAK_AE_SNEAK },
{ "ADD_SPELL_SLOTS"                   , SPA_ADD_SPELL_SLOTS },
{ "ADD_BUFF_SLOTS"                    , SPA_ADD_BUFF_SLOTS },
{ "INCREASE_NEGATIVE_HP_LIMIT"        , SPA_INCREASE_NEGATIVE_HP_LIMIT },
{ "MANA_ABSORB_PCT_DMG"               , SPA_MANA_ABSORB_PCT_DMG },
{ "CRIT_ATTACK_MODIFIER"              , SPA_CRIT_ATTACK_MODIFIER },
{ "FAIL_ALCHEMY_ITEM_RECOVERY"        , SPA_FAIL_ALCHEMY_ITEM_RECOVERY },
{ "SUMMON_TO_CORPSE"                  , SPA_SUMMON_TO_CORPSE },
{ "DOOM_RUNE_EFFECT"                  , SPA_DOOM_RUNE_EFFECT },
{ "NO_MOVE_HP"                        , SPA_NO_MOVE_HP },
{ "FOCUSED_IMMUNITY"                  , SPA_FOCUSED_IMMUNITY },
{ "ILLUSIONARY_TARGET"                , SPA_ILLUSIONARY_TARGET },
{ "INCREASE_EXP_MOD"                  , SPA_INCREASE_EXP_MOD },
{ "EXPEDIENT_RECOVERY"                , SPA_EXPEDIENT_RECOVERY },
{ "FOCUS_CASTING_PROC"                , SPA_FOCUS_CASTING_PROC },
{ "CHANCE_SPELL"                      , SPA_CHANCE_SPELL },
{ "WORN_ATTACK_CAP"                   , SPA_WORN_ATTACK_CAP },
{ "NO_PANIC"                          , SPA_NO_PANIC },
{ "SPELL_INTERRUPT"                   , SPA_SPELL_INTERRUPT },
{ "ITEM_CHANNELING"                   , SPA_ITEM_CHANNELING },
{ "ASSASSINATE_MAX_LEVEL"             , SPA_ASSASSINATE_MAX_LEVEL },
{ "HEADSHOT_MAX_LEVEL"                , SPA_HEADSHOT_MAX_LEVEL },
{ "DOUBLE_RANGED_ATTACK"              , SPA_DOUBLE_RANGED_ATTACK },
{ "FOCUS_MANA_MIN"                    , SPA_FOCUS_MANA_MIN },
{ "INCREASE_SHIELD_DMG"               , SPA_INCREASE_SHIELD_DMG },
{ "MANABURN"                          , SPA_MANABURN },
{ "SPAWN_INTERACTIVE_OBJECT"          , SPA_SPAWN_INTERACTIVE_OBJECT },
{ "INCREASE_TRAP_COUNT"               , SPA_INCREASE_TRAP_COUNT },
{ "INCREASE_SOI_COUNT"                , SPA_INCREASE_SOI_COUNT },
{ "DEACTIVATE_ALL_TRAPS"              , SPA_DEACTIVATE_ALL_TRAPS },
{ "LEARN_TRAP"                        , SPA_LEARN_TRAP },
{ "CHANGE_TRIGGER_TYPE"               , SPA_CHANGE_TRIGGER_TYPE },
{ "FOCUS_MUTE"                        , SPA_FOCUS_MUTE },
{ "INSTANT_MANA"                      , SPA_INSTANT_MANA },
{ "PASSIVE_SENSE_TRAP"                , SPA_PASSIVE_SENSE_TRAP },
{ "PROC_ON_KILL_SHOT"                 , SPA_PROC_ON_KILL_SHOT },
{ "PROC_ON_DEATH"                     , SPA_PROC_ON_DEATH },
{ "POTION_BELT"                       , SPA_POTION_BELT },
{ "BANDOLIER"                         , SPA_BANDOLIER },
{ "ADD_TRIPLE_ATTACK_CHANCE"          , SPA_ADD_TRIPLE_ATTACK_CHANCE },
{ "PROC_ON_SPELL_KILL_SHOT"           , SPA_PROC_ON_SPELL_KILL_SHOT },
{ "GROUP_SHIELDING"                   , SPA_GROUP_SHIELDING },
{ "MODIFY_BODY_TYPE"                  , SPA_MODIFY_BODY_TYPE },
{ "MODIFY_FACTION"                    , SPA_MODIFY_FACTION },
{ "CORRUPTION"                        , SPA_CORRUPTION },
{ "RESIST_CORRUPTION"                 , SPA_RESIST_CORRUPTION },
{ "SLOW"                              , SPA_SLOW },
{ "GRANT_FORAGING"                    , SPA_GRANT_FORAGING },
{ "DOOM_ALWAYS"                       , SPA_DOOM_ALWAYS },
{ "TRIGGER_SPELL"                     , SPA_TRIGGER_SPELL },
{ "CRIT_DOT_DMG_MOD"                  , SPA_CRIT_DOT_DMG_MOD },
{ "FLING"                             , SPA_FLING },
{ "DOOM_ENTITY"                       , SPA_DOOM_ENTITY },
{ "RESIST_OTHER_SPA"                  , SPA_RESIST_OTHER_SPA },
{ "DIRECTIONAL_TELEPORT"              , SPA_DIRECTIONAL_TELEPORT },
{ "EXPLOSIVE_KNOCKBACK"               , SPA_EXPLOSIVE_KNOCKBACK },
{ "FLING_TOWARD"                      , SPA_FLING_TOWARD },
{ "SUPPRESSION"                       , SPA_SUPPRESSION },
{ "FOCUS_CASTING_PROC_NORMALIZED"     , SPA_FOCUS_CASTING_PROC_NORMALIZED },
{ "FLING_AT"                          , SPA_FLING_AT },
{ "FOCUS_WHICH_GROUP"                 , SPA_FOCUS_WHICH_GROUP },
{ "DOOM_DISPELLER"                    , SPA_DOOM_DISPELLER },
{ "DOOM_DISPELLEE"                    , SPA_DOOM_DISPELLEE },
{ "SUMMON_ALL_CORPSES"                , SPA_SUMMON_ALL_CORPSES },
{ "REFRESH_SPELL_TIMER"               , SPA_REFRESH_SPELL_TIMER },
{ "LOCKOUT_SPELL_TIMER"               , SPA_LOCKOUT_SPELL_TIMER },
{ "FOCUS_MANA_MAX"                    , SPA_FOCUS_MANA_MAX },
{ "FOCUS_HEAL_AMT"                    , SPA_FOCUS_HEAL_AMT },
{ "FOCUS_HEAL_MOD_BENEFICIAL"         , SPA_FOCUS_HEAL_MOD_BENEFICIAL },
{ "FOCUS_HEAL_AMT_BENEFICIAL"         , SPA_FOCUS_HEAL_AMT_BENEFICIAL },
{ "FOCUS_HEAL_MOD_CRIT"               , SPA_FOCUS_HEAL_MOD_CRIT },
{ "FOCUS_HEAL_AMT_CRIT"               , SPA_FOCUS_HEAL_AMT_CRIT },
{ "ADD_PET_AC"                        , SPA_ADD_PET_AC },
{ "FOCUS_SWARM_PET_DURATION"          , SPA_FOCUS_SWARM_PET_DURATION },
{ "FOCUS_TWINCAST_CHANCE"             , SPA_FOCUS_TWINCAST_CHANCE },
{ "HEALBURN"                          , SPA_HEALBURN },
{ "MANA_IGNITE"                       , SPA_MANA_IGNITE },
{ "ENDURANCE_IGNITE"                  , SPA_ENDURANCE_IGNITE },
{ "FOCUS_SPELL_CLASS"                 , SPA_FOCUS_SPELL_CLASS },
{ "FOCUS_SPELL_SUBCLASS"              , SPA_FOCUS_SPELL_SUBCLASS },
{ "STAFF_BLOCK_CHANCE"                , SPA_STAFF_BLOCK_CHANCE },
{ "DOOM_LIMIT_USE"                    , SPA_DOOM_LIMIT_USE },
{ "DOOM_FOCUS_USED"                   , SPA_DOOM_FOCUS_USED },
{ "LIMIT_HP"                          , SPA_LIMIT_HP },
{ "LIMIT_MANA"                        , SPA_LIMIT_MANA },
{ "LIMIT_ENDURANCE"                   , SPA_LIMIT_ENDURANCE },
{ "FOCUS_LIMIT_CLASS"                 , SPA_FOCUS_LIMIT_CLASS },
{ "FOCUS_LIMIT_RACE"                  , SPA_FOCUS_LIMIT_RACE },
{ "FOCUS_BASE_EFFECTS"                , SPA_FOCUS_BASE_EFFECTS },
{ "FOCUS_LIMIT_SKILL"                 , SPA_FOCUS_LIMIT_SKILL },
{ "FOCUS_LIMIT_ITEM_CLASS"            , SPA_FOCUS_LIMIT_ITEM_CLASS },
{ "AC2"                               , SPA_AC2 },
{ "MANA2"                             , SPA_MANA2 },
{ "FOCUS_INCREASE_SKILL_DMG_2"        , SPA_FOCUS_INCREASE_SKILL_DMG_2 },
{ "PROC_EFFECT_2"                     , SPA_PROC_EFFECT_2 },
{ "FOCUS_LIMIT_USE"                   , SPA_FOCUS_LIMIT_USE },
{ "FOCUS_LIMIT_USE_AMT"               , SPA_FOCUS_LIMIT_USE_AMT },
{ "FOCUS_LIMIT_USE_MIN"               , SPA_FOCUS_LIMIT_USE_MIN },
{ "FOCUS_LIMIT_USE_TYPE"              , SPA_FOCUS_LIMIT_USE_TYPE },
{ "GRAVITATE"                         , SPA_GRAVITATE },
{ "FLY"                               , SPA_FLY },
{ "ADD_EXTENDED_TARGET_SLOTS"         , SPA_ADD_EXTENDED_TARGET_SLOTS },
{ "SKILL_PROC"                        , SPA_SKILL_PROC },
{ "PROC_SKILL_MODIFIER"               , SPA_PROC_SKILL_MODIFIER },
{ "SKILL_PROC_SUCCESS"                , SPA_SKILL_PROC_SUCCESS },
{ "POST_EFFECT"                       , SPA_POST_EFFECT },
{ "POST_EFFECT_DATA"                  , SPA_POST_EFFECT_DATA },
{ "EXPAND_MAX_ACTIVE_TROPHY_BENEFITS" , SPA_EXPAND_MAX_ACTIVE_TROPHY_BENEFITS },
{ "ADD_NORMALIZED_SKILL_MIN_DMG_AMT"  , SPA_ADD_NORMALIZED_SKILL_MIN_DMG_AMT },
{ "ADD_NORMALIZED_SKILL_MIN_DMG_AMT_2", SPA_ADD_NORMALIZED_SKILL_MIN_DMG_AMT_2 },
{ "FRAGILE_DEFENSE"                   , SPA_FRAGILE_DEFENSE },
{ "FREEZE_BUFF_TIMER"                 , SPA_FREEZE_BUFF_TIMER },
{ "TELEPORT_TO_ANCHOR"                , SPA_TELEPORT_TO_ANCHOR },
{ "TRANSLOCATE_TO_ANCHOR"             , SPA_TRANSLOCATE_TO_ANCHOR },
{ "ASSASSINATE"                       , SPA_ASSASSINATE },
{ "FINISHING_BLOW_MAX"                , SPA_FINISHING_BLOW_MAX },
{ "DISTANCE_REMOVAL"                  , SPA_DISTANCE_REMOVAL },
{ "REQUIRE_TARGET_DOOM"               , SPA_REQUIRE_TARGET_DOOM },
{ "REQUIRE_CASTER_DOOM"               , SPA_REQUIRE_CASTER_DOOM },
{ "IMPROVED_TAUNT"                    , SPA_IMPROVED_TAUNT },
{ "ADD_MERC_SLOT"                     , SPA_ADD_MERC_SLOT },
{ "STACKER_A"                         , SPA_STACKER_A },
{ "STACKER_B"                         , SPA_STACKER_B },
{ "STACKER_C"                         , SPA_STACKER_C },
{ "STACKER_D"                         , SPA_STACKER_D },
{ "DOT_GUARD"                         , SPA_DOT_GUARD },
{ "MELEE_THRESHOLD_GUARD"             , SPA_MELEE_THRESHOLD_GUARD },
{ "SPELL_THRESHOLD_GUARD"             , SPA_SPELL_THRESHOLD_GUARD },
{ "MELEE_THRESHOLD_DOOM"              , SPA_MELEE_THRESHOLD_DOOM },
{ "SPELL_THRESHOLD_DOOM"              , SPA_SPELL_THRESHOLD_DOOM },
{ "ADD_HATE_PCT"                      , SPA_ADD_HATE_PCT },
{ "ADD_HATE_OVER_TIME_PCT"            , SPA_ADD_HATE_OVER_TIME_PCT },
{ "RESOURCE_TAP"                      , SPA_RESOURCE_TAP },
{ "FACTION_MOD"                       , SPA_FACTION_MOD },
{ "SKILL_DAMAGE_MOD_2"                , SPA_SKILL_DAMAGE_MOD_2 },
{ "OVERRIDE_NOT_FOCUSABLE"            , SPA_OVERRIDE_NOT_FOCUSABLE },
{ "FOCUS_DAMAGE_MOD_2"                , SPA_FOCUS_DAMAGE_MOD_2 },
{ "FOCUS_DAMAGE_AMT_2"                , SPA_FOCUS_DAMAGE_AMT_2 },
{ "SHIELD"                            , SPA_SHIELD },
{ "PC_PET_RAMPAGE"                    , SPA_PC_PET_RAMPAGE },
{ "PC_PET_AE_RAMPAGE"                 , SPA_PC_PET_AE_RAMPAGE },
{ "PC_PET_FLURRY"                     , SPA_PC_PET_FLURRY },
{ "DAMAGE_SHIELD_MITIGATION_AMT"      , SPA_DAMAGE_SHIELD_MITIGATION_AMT },
{ "DAMAGE_SHIELD_MITIGATION_PCT"      , SPA_DAMAGE_SHIELD_MITIGATION_PCT },
{ "CHANCE_BEST_IN_SPELL_GROUP"        , SPA_CHANCE_BEST_IN_SPELL_GROUP },
{ "TRIGGER_BEST_IN_SPELL_GROUP"       , SPA_TRIGGER_BEST_IN_SPELL_GROUP },
{ "DOUBLE_MELEE_ATTACKS"              , SPA_DOUBLE_MELEE_ATTACKS },
{ "AA_BUY_NEXT_RANK"                  , SPA_AA_BUY_NEXT_RANK },
{ "DOUBLE_BACKSTAB_FRONT"             , SPA_DOUBLE_BACKSTAB_FRONT },
{ "PET_MELEE_CRIT_DMG_MOD"            , SPA_PET_MELEE_CRIT_DMG_MOD },
{ "TRIGGER_SPELL_NON_ITEM"            , SPA_TRIGGER_SPELL_NON_ITEM },
{ "WEAPON_STANCE"                     , SPA_WEAPON_STANCE },
{ "HATELIST_TO_TOP"                   , SPA_HATELIST_TO_TOP },
{ "HATELIST_TO_TAIL"                  , SPA_HATELIST_TO_TAIL },
{ "FOCUS_LIMIT_MIN_VALUE"             , SPA_FOCUS_LIMIT_MIN_VALUE },
{ "FOCUS_LIMIT_MAX_VALUE"             , SPA_FOCUS_LIMIT_MAX_VALUE },
{ "FOCUS_CAST_SPELL_ON_LAND"          , SPA_FOCUS_CAST_SPELL_ON_LAND },
{ "SKILL_BASE_DAMAGE_MOD"             , SPA_SKILL_BASE_DAMAGE_MOD },
{ "FOCUS_INCOMING_DMG_MOD"            , SPA_FOCUS_INCOMING_DMG_MOD },
{ "FOCUS_INCOMING_DMG_AMT"            , SPA_FOCUS_INCOMING_DMG_AMT },
{ "FOCUS_LIMIT_CASTER_CLASS"          , SPA_FOCUS_LIMIT_CASTER_CLASS },
{ "FOCUS_LIMIT_SAME_CASTER"           , SPA_FOCUS_LIMIT_SAME_CASTER },
{ "EXTEND_TRADESKILL_CAP"             , SPA_EXTEND_TRADESKILL_CAP },
{ "DEFENDER_MELEE_FORCE_PCT"          , SPA_DEFENDER_MELEE_FORCE_PCT },
{ "WORN_ENDURANCE_REGEN_CAP"          , SPA_WORN_ENDURANCE_REGEN_CAP },
{ "FOCUS_MIN_REUSE_TIME"              , SPA_FOCUS_MIN_REUSE_TIME },
{ "FOCUS_MAX_REUSE_TIME"              , SPA_FOCUS_MAX_REUSE_TIME },
{ "FOCUS_ENDURANCE_MIN"               , SPA_FOCUS_ENDURANCE_MIN },
{ "FOCUS_ENDURANCE_MAX"               , SPA_FOCUS_ENDURANCE_MAX },
{ "PET_ADD_ATK"                       , SPA_PET_ADD_ATK },
{ "FOCUS_DURATION_MAX"                , SPA_FOCUS_DURATION_MAX },
{ "CRIT_MELEE_DMG_MOD_MAX"            , SPA_CRIT_MELEE_DMG_MOD_MAX },
{ "FOCUS_CAST_PROC_NO_BYPASS"         , SPA_FOCUS_CAST_PROC_NO_BYPASS },
{ "ADD_EXTRA_PRIMARY_ATTACK_PCT"      , SPA_ADD_EXTRA_PRIMARY_ATTACK_PCT },
{ "ADD_EXTRA_SECONDARY_ATTACK_PCT"    , SPA_ADD_EXTRA_SECONDARY_ATTACK_PCT },
{ "FOCUS_CAST_TIME_MOD2"              , SPA_FOCUS_CAST_TIME_MOD2 },
{ "FOCUS_CAST_TIME_AMT"               , SPA_FOCUS_CAST_TIME_AMT },
{ "FEARSTUN"                          , SPA_FEARSTUN },
{ "MELEE_DMG_POSITION_MOD"            , SPA_MELEE_DMG_POSITION_MOD },
{ "MELEE_DMG_POSITION_AMT"            , SPA_MELEE_DMG_POSITION_AMT },
{ "DMG_TAKEN_POSITION_MOD"            , SPA_DMG_TAKEN_POSITION_MOD },
{ "DMG_TAKEN_POSITION_AMT"            , SPA_DMG_TAKEN_POSITION_AMT },
{ "AMPLIFY_MOD"                       , SPA_AMPLIFY_MOD },
{ "AMPLIFY_AMT"                       , SPA_AMPLIFY_AMT },
{ "HEALTH_TRANSFER"                   , SPA_HEALTH_TRANSFER },
{ "FOCUS_RESIST_INCOMING"             , SPA_FOCUS_RESIST_INCOMING },
{ "FOCUS_TIMER_MIN"                   , SPA_FOCUS_TIMER_MIN },
{ "PROC_TIMER_MOD"                    , SPA_PROC_TIMER_MOD },
{ "MANA_MAX"                          , SPA_MANA_MAX },
{ "ENDURANCE_MAX"                     , SPA_ENDURANCE_MAX },
{ "AC_AVOIDANCE_MAX"                  , SPA_AC_AVOIDANCE_MAX },
{ "AC_MITIGATION_MAX"                 , SPA_AC_MITIGATION_MAX },
{ "ATTACK_OFFENSE_MAX"                , SPA_ATTACK_OFFENSE_MAX },
{ "ATTACK_ACCURACY_MAX"               , SPA_ATTACK_ACCURACY_MAX },
{ "LUCK_AMT"                          , SPA_LUCK_AMT },
{ "LUCK_PCT"                          , SPA_LUCK_PCT },
{ "ENDURANCE_ABSORB_PCT_DMG"          , SPA_ENDURANCE_ABSORB_PCT_DMG },
{ "INSTANT_MANA_PCT"                  , SPA_INSTANT_MANA_PCT },
{ "INSTANT_ENDURANCE_PCT"             , SPA_INSTANT_ENDURANCE_PCT },
{ "DURATION_HP_PCT"                   , SPA_DURATION_HP_PCT },
{ "DURATION_MANA_PCT"                 , SPA_DURATION_MANA_PCT },
{ "DURATION_ENDURANCE_PCT"            , SPA_DURATION_ENDURANCE_PCT },
};

static void InitializeSpells();
static void ShutdownSpells();
static void PulseSpells();

static MQModule gSpellsModule = {
	"Spells",                      // Name
	false,                         // CanUnload
	InitializeSpells,
	ShutdownSpells,
	PulseSpells
};
MQModule* GetSpellsModule() { return &gSpellsModule; }


EQ_Spell* GetHighestLearnedSpellByGroupID(int dwSpellGroupID)
{
	PcProfile* pProfile = GetPcProfile();
	if (!pProfile) return nullptr;

	EQ_Spell* result = nullptr;

	for (int nSpell : pProfile->SpellBook)
	{
		auto pFoundSpell = GetSpellByID(nSpell);
		if (!pFoundSpell || pFoundSpell->SpellGroup != dwSpellGroupID)
			continue;

		// Find the highest rank of the spell that matches this spell group
		if (!result || result->SpellRank < pFoundSpell->SpellRank)
			result = pFoundSpell;
	}

	return result;
}

static const char* GetSpellNameBySpellGroupID(int dwSpellGroupID)
{
	// Look up spell group
	if (pSpellMgr)
	{
		EQ_Spell* fallbackSpell = nullptr;

		int* pSpellID = pSpellMgr->SpellGroups.FindFirst(dwSpellGroupID);
		while (pSpellID)
		{
			EQ_Spell* pSpell = pSpellMgr->GetSpellByID(*pSpellID);
			if (pSpell)
			{
				if (pSpell->SpellSubGroup == 0)
					return pSpell->Name;

				if (!fallbackSpell)
					fallbackSpell = pSpell;
			}

			pSpellID = pSpellMgr->SpellGroups.FindNext(pSpellID);
		}

		if (fallbackSpell)
			return fallbackSpell->Name;
	}

	return "Unknown Spell";
}

const char* GetSpellNameByID(int dwSpellID)
{
	auto pSpell = GetSpellByID(dwSpellID);

	if (pSpell && pSpell->Name && pSpell->Name[0] != 0)
		return pSpell->Name;

	return "Unknown Spell";
}

static bool IsRecursiveEffect(int spa)
{
	switch (spa)
	{
	case SPA_CHANCE_SPELL:
	case SPA_CHANCE_BEST_IN_SPELL_GROUP:
	case SPA_TRIGGER_SPELL:
	case SPA_TRIGGER_SPELL_NON_ITEM:
	case SPA_TRIGGER_BEST_IN_SPELL_GROUP:
		return true;
	}

	return false;
}

static void PopulateTriggeredMap(const EQ_Spell* pSpell)
{
	if (!pSpell || pSpell->CannotBeScribed)
		return;

	for (int i = 0; i < pSpell->NumEffects; i++)
	{
		if (!IsRecursiveEffect(GetSpellAttrib(pSpell, i)))
			continue;

		int triggeredSpellID = (int)GetSpellBase2(pSpell, i);
		if (i > 0)
			s_triggeredSpells[triggeredSpellID] = pSpell->ID;
	}
}

EQ_Spell* GetSpellParent(int id)
{
	auto iter = s_triggeredSpells.find(id);
	if (iter != s_triggeredSpells.end())
		return GetSpellByID(iter->second);

	return nullptr;
}

void PopulateSpellMap()
{
	std::scoped_lock lock(s_initializeSpellsMutex);

	gbSpelldbLoaded = false;

	s_triggeredSpells.clear();
	s_spellNameMap.clear();

	for (EQ_Spell* pSpell : pSpellMgr->Spells)
	{
		if (!pSpell || !pSpell->Name[0])
			continue;

		PopulateTriggeredMap(pSpell);

		s_spellNameMap.emplace(pSpell->Name, pSpell);
	}

	gbSpelldbLoaded = true;
}

DWORD CALLBACK InitializeMQ2SpellDb(void* pData)
{
	bmSpellLoad = AddMQ2Benchmark("SpellLoad");
	bmSpellAccess = AddMQ2Benchmark("SpellAccess");

	while (GetGameState() != GAMESTATE_CHARSELECT && GetGameState() != GAMESTATE_INGAME)
	{
		Sleep(10);
	}

	while (pSpellMgr && !pSpellMgr->AllSpellsLoaded())
	{
		Sleep(10);
	}

	// ok everything checks out lets fill our own map with spells
	Benchmark(bmSpellLoad, PopulateSpellMap());

	ghInitializeSpellDbThread = nullptr;
	return 0;
}

bool IsSpellClassUsable(EQ_Spell* pSpell)
{
	for (int index = Warrior; index <= Berserker; index++)
	{
		if (pSpell->ClassLevel[index] == 255 || pSpell->ClassLevel[index] == 254 || pSpell->ClassLevel[index] == 127)
		{
			continue;
		}

		return true;
	}

	return false;
}

static EQ_Spell* GetSpellFromMap(std::string_view name)
{
	auto profile = GetPcProfile();
	if (!profile)
		return nullptr;

	auto range = s_spellNameMap.equal_range(name);

	// no hits
	if (range.first == range.second)
		return nullptr;

	// If there is only a single hit by name, just return that spell.
	if (std::distance(range.first, range.second) == 1)
		return range.first->second;

	// Find the preferred spell for this class.
	if (IsPlayerClass(profile->Class))
	{
		EQ_Spell* classUsableSpell = nullptr;

		for (auto iter = range.first; iter != range.second; ++iter)
		{
			EQ_Spell* testSpell = iter->second;
			if (profile->Level >= testSpell->ClassLevel[profile->Class])
			{
				if (!classUsableSpell)
					classUsableSpell = testSpell;
				else
				{
					// we found a 2nd spell with the same name that is usable by this class.
					// Check if one of these spells has a category and the other doesn't.
					// The assumption is, learnable spells will have a category. Unusable ones wont.
					if (classUsableSpell->Category == 0 && testSpell->Category != 0)
						classUsableSpell = testSpell;
				}
			}
		}

		// If we found a preferred spell, return it.
		if (classUsableSpell)
			return classUsableSpell;

		// otherwise, I can't have this spell
	}

	// if we got here, the spell the user is after isn't one his character can cast, so
	// we will have to roll through it again and see if its usable by any other class

	EQ_Spell* usableSpell = nullptr;
	for (auto iter = range.first; iter != range.second; ++iter)
	{
		EQ_Spell* testSpell = iter->second;
		if (IsSpellClassUsable(testSpell))
		{
			if (!usableSpell)
				usableSpell = testSpell;
			else
			{
				if (usableSpell->Category == 0 && testSpell->Category != 0)
					usableSpell = testSpell;
			}
		}
	}

	if (usableSpell)
		return usableSpell;

	// couldn't find a good match, return the first spell that came back.
	return range.first->second;
}

EQ_Spell* GetSpellByName(std::string_view name)
{
	// EQ_Spell* GetSpellByName(char* NameOrID)
	// This function now accepts SpellID as an argument as well as SpellName
	// /echo ${Spell[Concussive Burst].Level}
	// /echo ${Spell[Nature's Serenity].Level}

	if (name.empty()) // no spell name?
		return nullptr;

	int spellID = GetIntFromString(name, -1);
	if (spellID >= 0)
		return GetSpellByID(spellID);

	if (gbSpelldbLoaded == false)
	{
		InitializeMQ2SpellDb(nullptr);

		if (gbSpelldbLoaded == false)
		{
			return nullptr;
		}
	}

	std::scoped_lock lock(s_initializeSpellsMutex);
	if (s_spellNameMap.empty())
		return nullptr;

	EnterMQ2Benchmark(bmSpellAccess);
	auto pSpell = GetSpellFromMap(name);
	ExitMQ2Benchmark(bmSpellAccess);

	return pSpell;
}


// ***************************************************************************
// Function:    IsBardSong
// Description: Return true if the spell is a bard song
// ***************************************************************************
bool IsBardSong(EQ_Spell* pSpell)
{
	return pSpell->GetSpellLevelNeeded(Bard) <= MAX_PC_LEVEL &&
		!pSpell->DurationWindow;
}

// ***************************************************************************
// Function:    IsSPAEffect
// Description: Return true if the spell contains the SPAEffect
// ***************************************************************************
bool IsSPAEffect(EQ_Spell* pSpell, int EffectID)
{
	for (int slot = 0; slot < GetSpellNumEffects(pSpell); ++slot)
	{
		if (GetSpellAttrib(pSpell, slot) == EffectID)
			return true;
	}

	return false;
}

// ***************************************************************************
// Function:    GetClassesFromMask
// Description: Return a comma delimited list of player short class names
//              If ALL classes are in the mask it will return "ALL",
//              if 4 or less are missing it will return "ALL EXCEPT: " and the
//              comma delimited list of play short class names that are excluded
// ***************************************************************************
const std::string GetClassesFromMask(int mask)
{
	int matching = 0;
	int excluding = 0;
	int numofclasses = Berserker;

	for (int playerclass = Warrior; playerclass <= Berserker; playerclass++)
	{
		if (mask & (1 << playerclass))
			++matching;
		else
			++excluding;
	}

	std::stringstream buffer;

	if (matching == numofclasses)
	{
		buffer << "ALL";
	}
	else if (excluding <= 4)
	{
		buffer <<  "ALL EXCEPT: ";
		std::vector<std::string> classes;
		for (int playerclass = Warrior; playerclass <= Berserker; ++playerclass)
		{
			if (!(mask & (1 << playerclass)))
				classes.emplace_back(ClassInfo[playerclass].UCShortName);
		}

		buffer << join(classes, ",");
	}
	else
	{
		std::vector<std::string> classes;
		for (int playerclass = Warrior; playerclass <= Berserker; playerclass++)
		{
			if (mask & (1 << playerclass))
				classes.emplace_back(ClassInfo[playerclass].UCShortName);
		}

		buffer << join(classes, ",");
	}

	return buffer.str();
}

// ***************************************************************************
// Function:    GetSpellRestrictions
// Description: Return the restrictions for the spell slot
// ***************************************************************************
char* GetSpellRestrictions(EQ_Spell* pSpell, unsigned int nIndex, char* szBuffer, size_t BufferSize)
{
	if (!szBuffer)
		return nullptr;

	if (!pSpell)
	{
		szBuffer[0] = '\0';
		return szBuffer;
	}

	// TODO: turn these types into an enum class
	switch (GetSpellBase2(pSpell, nIndex))
	{
	case 0:	strcat_s(szBuffer, BufferSize, "None"); break;
	case 100: strcat_s(szBuffer, BufferSize, "Only works on Animal or Humanoid"); break;
	case 101: strcat_s(szBuffer, BufferSize, "Only works on Dragon"); break;
	case 102: strcat_s(szBuffer, BufferSize, "Only works on Animal or Insect"); break;
	case 104: strcat_s(szBuffer, BufferSize, "Only works on Animal"); break;
	case 105: strcat_s(szBuffer, BufferSize, "Only works on Plant"); break;
	case 106: strcat_s(szBuffer, BufferSize, "Only works on Giant"); break;
	case 108: strcat_s(szBuffer, BufferSize, "Doesn't work on Animals or Humanoids"); break;
	case 109: strcat_s(szBuffer, BufferSize, "Only works on Bixie"); break;
	case 110: strcat_s(szBuffer, BufferSize, "Only works on Harpy"); break;
	case 111: strcat_s(szBuffer, BufferSize, "Only works on Gnoll"); break;
	case 112: strcat_s(szBuffer, BufferSize, "Only works on Sporali"); break;
	case 113: strcat_s(szBuffer, BufferSize, "Only works on Kobold"); break;
	case 114: strcat_s(szBuffer, BufferSize, "Only works on Shade"); break;
	case 115: strcat_s(szBuffer, BufferSize, "Only works on Drakkin"); break;
	case 117: strcat_s(szBuffer, BufferSize, "Only works on Animals or Plants"); break;
	case 118: strcat_s(szBuffer, BufferSize, "Only works on Summoned"); break;
	case 119: strcat_s(szBuffer, BufferSize, "Only works on Fire_Pet"); break;
	case 120: strcat_s(szBuffer, BufferSize, "Only works on Undead"); break;
	case 121: strcat_s(szBuffer, BufferSize, "Only works on Living"); break;
	case 122: strcat_s(szBuffer, BufferSize, "Only works on Fairy"); break;
	case 123: strcat_s(szBuffer, BufferSize, "Only works on Humanoid"); break;
	case 124: strcat_s(szBuffer, BufferSize, "Undead HP Less Than 10%"); break;
	case 125: strcat_s(szBuffer, BufferSize, "Clockwork HP Less Than 45%"); break;
	case 126: strcat_s(szBuffer, BufferSize, "Wisp HP Less Than 10%"); break;
	case 190: strcat_s(szBuffer, BufferSize, "Doesn't work on Raid Bosses"); break;
	case 191: strcat_s(szBuffer, BufferSize, "Only works on Raid Bosses"); break;
	case 201: strcat_s(szBuffer, BufferSize, "HP Above 75%"); break;
	case 203: strcat_s(szBuffer, BufferSize, "HP Less Than 20%"); break;
	case 204: strcat_s(szBuffer, BufferSize, "HP Less Than 50%"); break;
	case 216: strcat_s(szBuffer, BufferSize, "Not In Combat"); break;
	case 221: strcat_s(szBuffer, BufferSize, "At Least 1 Pet On Hatelist"); break;
	case 222: strcat_s(szBuffer, BufferSize, "At Least 2 Pets On Hatelist"); break;
	case 223: strcat_s(szBuffer, BufferSize, "At Least 3 Pets On Hatelist"); break;
	case 224: strcat_s(szBuffer, BufferSize, "At Least 4 Pets On Hatelist"); break;
	case 225: strcat_s(szBuffer, BufferSize, "At Least 5 Pets On Hatelist"); break;
	case 226: strcat_s(szBuffer, BufferSize, "At Least 6 Pets On Hatelist"); break;
	case 227: strcat_s(szBuffer, BufferSize, "At Least 7 Pets On Hatelist"); break;
	case 228: strcat_s(szBuffer, BufferSize, "At Least 8 Pets On Hatelist"); break;
	case 229: strcat_s(szBuffer, BufferSize, "At Least 9 Pets On Hatelist"); break;
	case 230: strcat_s(szBuffer, BufferSize, "At Least 10 Pets On Hatelist"); break;
	case 231: strcat_s(szBuffer, BufferSize, "At Least 11 Pets On Hatelist"); break;
	case 232: strcat_s(szBuffer, BufferSize, "At Least 12 Pets On Hatelist"); break;
	case 233: strcat_s(szBuffer, BufferSize, "At Least 13 Pets On Hatelist"); break;
	case 234: strcat_s(szBuffer, BufferSize, "At Least 14 Pets On Hatelist"); break;
	case 235: strcat_s(szBuffer, BufferSize, "At Least 15 Pets On Hatelist"); break;
	case 236: strcat_s(szBuffer, BufferSize, "At Least 16 Pets On Hatelist"); break;
	case 237: strcat_s(szBuffer, BufferSize, "At Least 17 Pets On Hatelist"); break;
	case 238: strcat_s(szBuffer, BufferSize, "At Least 18 Pets On Hatelist"); break;
	case 239: strcat_s(szBuffer, BufferSize, "At Least 19 Pets On Hatelist"); break;
	case 240: strcat_s(szBuffer, BufferSize, "At Least 20 Pets On Hatelist"); break;
	case 250: strcat_s(szBuffer, BufferSize, "HP Less Than 35%"); break;
	case 304: strcat_s(szBuffer, BufferSize, "Chain Plate Classes"); break;
	case 399: strcat_s(szBuffer, BufferSize, "HP Between 15 and 25%"); break;
	case 400: strcat_s(szBuffer, BufferSize, "HP Between 1 and 25%"); break;
	case 401: strcat_s(szBuffer, BufferSize, "HP Between 25 and 35%"); break;
	case 402: strcat_s(szBuffer, BufferSize, "HP Between 35 and 45%"); break;
	case 403: strcat_s(szBuffer, BufferSize, "HP Between 45 and 55%"); break;
	case 404: strcat_s(szBuffer, BufferSize, "HP Between 55 and 65%"); break;
	case 412: strcat_s(szBuffer, BufferSize, "HP Above 99%"); break;
	case 501: strcat_s(szBuffer, BufferSize, "HP Below 5%"); break;
	case 502: strcat_s(szBuffer, BufferSize, "HP Below 10%"); break;
	case 503: strcat_s(szBuffer, BufferSize, "HP Below 15%"); break;
	case 504: strcat_s(szBuffer, BufferSize, "HP Below 20%"); break;
	case 505: strcat_s(szBuffer, BufferSize, "HP Below 25%"); break;
	case 506: strcat_s(szBuffer, BufferSize, "HP Below 30%"); break;
	case 507: strcat_s(szBuffer, BufferSize, "HP Below 35%"); break;
	case 508: strcat_s(szBuffer, BufferSize, "HP Below 40%"); break;
	case 509: strcat_s(szBuffer, BufferSize, "HP Below 45%"); break;
	case 510: strcat_s(szBuffer, BufferSize, "HP Below 50%"); break;
	case 511: strcat_s(szBuffer, BufferSize, "HP Below 55%"); break;
	case 512: strcat_s(szBuffer, BufferSize, "HP Below 60%"); break;
	case 513: strcat_s(szBuffer, BufferSize, "HP Below 65%"); break;
	case 514: strcat_s(szBuffer, BufferSize, "HP Below 70%"); break;
	case 515: strcat_s(szBuffer, BufferSize, "HP Below 75%"); break;
	case 516: strcat_s(szBuffer, BufferSize, "HP Below 80%"); break;
	case 517: strcat_s(szBuffer, BufferSize, "HP Below 85%"); break;
	case 518: strcat_s(szBuffer, BufferSize, "HP Below 90%"); break;
	case 519: strcat_s(szBuffer, BufferSize, "HP Below 95%"); break;
	case 521: strcat_s(szBuffer, BufferSize, "Mana Below X%"); break;
	case 522: strcat_s(szBuffer, BufferSize, "End Below 40%"); break;
	case 523: strcat_s(szBuffer, BufferSize, "Mana Below 40%"); break;
	case 603: strcat_s(szBuffer, BufferSize, "Only works on Undead2"); break;
	case 608: strcat_s(szBuffer, BufferSize, "Only works on Undead3"); break;
	case 624: strcat_s(szBuffer, BufferSize, "Only works on Summoned2"); break;
	case 701: strcat_s(szBuffer, BufferSize, "Doesn't work on Pets"); break;
	case 818: strcat_s(szBuffer, BufferSize, "Only works on Undead4"); break;
	case 819: strcat_s(szBuffer, BufferSize, "Doesn't work on Undead4"); break;
	case 825: strcat_s(szBuffer, BufferSize, "End Below 21%"); break;
	case 826: strcat_s(szBuffer, BufferSize, "End Below 25%"); break;
	case 827: strcat_s(szBuffer, BufferSize, "End Below 29%"); break;
	case 836: strcat_s(szBuffer, BufferSize, "Only works on Regular Servers"); break;
	case 837: strcat_s(szBuffer, BufferSize, "Doesn't work on Progression Servers"); break;
	case 842: strcat_s(szBuffer, BufferSize, "Only works on Humanoid Level 84 Max"); break;
	case 843: strcat_s(szBuffer, BufferSize, "Only works on Humanoid Level 86 Max"); break;
	case 844: strcat_s(szBuffer, BufferSize, "Only works on Humanoid Level 88 Max"); break;
	case 1000: strcat_s(szBuffer, BufferSize, "Between Level 1 and 75"); break;
	case 1001: strcat_s(szBuffer, BufferSize, "Between Level 76 and 85"); break;
	case 1002: strcat_s(szBuffer, BufferSize, "Between Level 86 and 95"); break;
	case 1003: strcat_s(szBuffer, BufferSize, "Between Level 96 and 100"); break;
	case 1004: strcat_s(szBuffer, BufferSize, "HP Less Than 80%"); break;
	case 38311: strcat_s(szBuffer, BufferSize, "Mana Below 20%"); break;
	case 38312: strcat_s(szBuffer, BufferSize, "Mana Below 10%"); break;
	default: {
		char szTemp[MAX_STRING] = { 0 };
		sprintf_s(szTemp, "Unknown[%lld]", GetSpellBase2(pSpell, nIndex));
		strcat_s(szBuffer, BufferSize, szTemp); break;
	}
	}
	return szBuffer;
}

// ***************************************************************************
// Function:    GetSpellEffectName, GetSpellEffectNameByID
// Description: Return spell effect string
// ***************************************************************************
char* GetSpellEffectNameByID(int EffectID, char* szBuffer, size_t BufferSize)
{
	return GetSpellEffectName(EffectID, szBuffer, BufferSize);
}

char* GetSpellEffectName(int EffectID, char* szBuffer, size_t BufferSize)
{
	// we want to take the abs here because when this is stored as a negative value, it translates
	// into an exclusion ("Exclude: "), but the spell effect name is the same
	int absEffectID = abs(EffectID);

	if ((size_t)absEffectID < MAX_SPELLEFFECTS)
	{
		strcat_s(szBuffer, BufferSize, szSPATypes[absEffectID]);
	}
	else
	{
		char szTemp[MAX_STRING] = { 0 };
		sprintf_s(szTemp, "Unknown SPA[%03d]", absEffectID);
		strcat_s(szBuffer, BufferSize, szTemp);
	}

	return szBuffer;
}

template <unsigned int Size>
static char* GetResistTypeName(int ResistType, char(&szBuffer)[Size])
{
	char szTemp[32] = { 0 };
	switch (ResistType)
	{
	case ResistType_Magic: strcat_s(szBuffer, "Magic"); break;
	case ResistType_Fire: strcat_s(szBuffer, "Fire"); break;
	case ResistType_Cold: strcat_s(szBuffer, "Cold/Ice"); break;
	case ResistType_Poison: strcat_s(szBuffer, "Poison"); break;
	case ResistType_Disease: strcat_s(szBuffer, "Disease"); break;
	case ResistType_Chromatic: strcat_s(szBuffer, "Chromatic"); break;
	case ResistType_Prismatic: strcat_s(szBuffer, "Prismatic"); break;
	case ResistType_Physical: strcat_s(szBuffer, "Physical"); break;
	case ResistType_Corruption: strcat_s(szBuffer, "Corruption"); break;
	default:
		sprintf_s(szTemp, "Unknown[%d]", ResistType);
		strcat_s(szBuffer, szTemp); break;
	}
	return szBuffer;
}

template <unsigned int Size>
static char* GetSpellTypeName(int SpellType, char(&szBuffer)[Size])
{
	char szTemp[32] = { 0 };
	switch (SpellType)
	{
	case SpellType_Detrimental: strcat_s(szBuffer, "Detrimental only"); break;
	case SpellType_Beneficial: strcat_s(szBuffer, "Beneficial only"); break;
	case SpellType_BeneficialGroupOnly: strcat_s(szBuffer, "Beneficial - Group Only"); break;
	default:
		sprintf_s(szTemp, "Unknown[%d]", SpellType);
		strcat_s(szBuffer, szTemp); break;
	}
	return szBuffer;
}


template <unsigned int Size>
static char* GetTargetTypeLimitsName(int TargetLimitsType, char(&szBuffer)[Size])
{
	char szTemp[64] = { 0 };
	switch (abs(TargetLimitsType))
	{
	case 50: strcat_s(szBuffer, "Target AE No Players Pets"); break; // blanket of forgetfullness. beneficial, AE mem blur, with max targets
	case 52: strcpy_s(szBuffer, "Single Friendly (or Target's Target"); break; // Introduced in Torment of Velious. Spell affects target if friendly, or target's target if the target is an unfriendly.
	case 47: strcat_s(szBuffer, "Pet Owner"); break;
	case 46: strcat_s(szBuffer, "Target of Target"); break;
	case 45: strcat_s(szBuffer, "Free Target"); break;
	case 44: strcat_s(szBuffer, "Beam"); break;
	case 43: strcat_s(szBuffer, "Single in Group"); break;
	case 42: strcat_s(szBuffer, "Directional AE"); break;
	case 39: strcat_s(szBuffer, "No Pets"); break;
	case 38: strcat_s(szBuffer, "Pet2"); break;
	case 37: strcat_s(szBuffer, "Caster PB NPC"); break;
	case 36: strcat_s(szBuffer, "Caster PB PC"); break;
	case 35: strcat_s(szBuffer, "Special Muramites"); break;
	case 34: strcat_s(szBuffer, "Chest"); break;
	case 33: strcat_s(szBuffer, "Hatelist2"); break;
	case 32: strcat_s(szBuffer, "Hatelist"); break;
	case 41: strcat_s(szBuffer, "Group v2"); break;
	case 40: strcat_s(szBuffer, "AE PC v2"); break;
	case 25: strcat_s(szBuffer, "AE Summoned"); break;
	case 24: strcat_s(szBuffer, "AE Undead"); break;
	case 20: strcat_s(szBuffer, "Targeted AE Tap"); break;
	case 18: strcat_s(szBuffer, "Uber Dragons"); break;
	case 17: strcat_s(szBuffer, "Uber Giants"); break;
	case 16: strcat_s(szBuffer, "Plant"); break;
	case 15: strcat_s(szBuffer, "Corpse"); break;
	case 14: strcat_s(szBuffer, "Pet"); break;
	case 13: strcat_s(szBuffer, "LifeTap"); break;
	case 11: strcat_s(szBuffer, "Summoned"); break;
	case 10: strcat_s(szBuffer, "Undead"); break;
	case 9: strcat_s(szBuffer, "Animal"); break;
	case 8: strcat_s(szBuffer, "Targeted AE"); break;
	case 6: strcat_s(szBuffer, "Self"); break;
	case 5: strcat_s(szBuffer, "Single"); break;
	case 4: strcat_s(szBuffer, "PB AE"); break;
	case 3: strcat_s(szBuffer, "Group v1"); break;
	case 2: strcat_s(szBuffer, "AE PC v1"); break;
	case 1: strcat_s(szBuffer, "Line of Sight"); break;
	default:
		sprintf_s(szTemp, "Unknown[%d]", abs(TargetLimitsType));
		strcat_s(szBuffer, szTemp); break;
	}
	return szBuffer;
}

template <unsigned int Size>
static char* GetStatShortName(int StatType, char(&szBuffer)[Size])
{
	char szTemp[32] = { 0 };
	switch (StatType)
	{
	case 0: strcat_s(szBuffer, "STR"); break;
	case 1: strcat_s(szBuffer, "STA"); break;
	case 2: strcat_s(szBuffer, "AGI"); break;
	case 3: strcat_s(szBuffer, "DEX"); break;
	case 4: strcat_s(szBuffer, "WIS"); break;
	case 5: strcat_s(szBuffer, "INT"); break;
	case 6: strcat_s(szBuffer, "CHA"); break;
	case 7: strcat_s(szBuffer, "MR"); break;
	case 8: strcat_s(szBuffer, "CR"); break;
	case 9: strcat_s(szBuffer, "FR"); break;
	case 10: strcat_s(szBuffer, "PR"); break;  // either PR or DR
	case 11: strcat_s(szBuffer, "DR"); break;  // either DR or PR
	default:
		sprintf_s(szTemp, "Unknown[%d]", StatType);
		strcat_s(szBuffer, szTemp); break;
	}
	return szBuffer;
}

template <size_t Size>
static char* GetFactionName(int FactionID, char(&szBuffer)[Size])
{
	char szTemp[MAX_STRING] = { 0 };
	eqlib::GetFactionName(FactionID, szTemp, MAX_STRING);

	strcat_s(szBuffer, "(");
	strcat_s(szBuffer, szTemp);
	strcat_s(szBuffer, ")");

	return szBuffer;
}

int64_t CalcValue(int calc, int64_t base, int64_t max, int tick, int minlevel, int level)
{
	if (calc == 0)
		return base;

	if (calc == 100)
	{
		if (max > 0 && ((base > max) || (level > minlevel)))
			return max;
		return base;
	}

	int64_t change = 0;
	int64_t adjustment = 0;

	switch (calc)
	{
	case 100:
		break;
	case 101:
		change = level / 2;
		break;
	case 102:
		change = level;
		break;
	case 103:
		change = level * 2;
		break;
	case 104:
		change = level * 3;
		break;
	case 105:
		change = level * 4;
		break;
	case 106:
		change = level * 5;
		break;
	case 107:
		change = -1 * tick;
		break;
	case 108:
		change = -2 * tick;
		break;
	case 109:
		change = level / 4;
		break;
	case 110:
		change = level / 6;
		break;
	case 111:
		//if (level < 16) adjustment = (level - 16) * 6;
		if (level > 16) change = (level - 16) * 6;
		break;
	case 112:
		//if (level < 24) adjustment = (level - 24) * 8;
		if (level > 24) change = (level - 24) * 8;
		break;
	case 113:
		//if (level < 34) adjustment = (level - 34) * 10;
		if (level > 34) change = (level - 34) * 10;
		break;
	case 114:
		//if (level < 44) adjustment = (level - 44) * 15;
		if (level > 44) change = (level - 44) * 15;
		break;
	case 115:
		//if (level < 15) adjustment = (level - 15) * 7;
		if (level > 15) change = (level - 15) * 7;
		break;
	case 116:
		//if (level < 24) adjustment = (level - 24) * 10;
		if (level > 24) change = (level - 24) * 10;
		break;
	case 117:
		//if (level < 34) adjustment = (level - 34) * 13;
		if (level > 34) change = (level - 34) * 13;
		break;
	case 118:
		//if (level < 44) adjustment = (level - 44) * 20;
		if (level > 44) change = (level - 44) * 20;
		break;
	case 119:
		change = level / 8;
		break;
	case 120:
		change = -5 * tick;
		break;
	case 121:
		change = level / 3;
		break;
	case 122:
		change = -12 * tick;
		break;
	case 123: // random in range
		if (tick > 1) change = abs(max) - abs(base);
		//change = (abs(max) - abs(base)) / 2;
		break;
	case 124:
		//if (level < 50) adjustment = (level - 50);
		if (level > 50) change = (level - 50);
		break;
	case 125:
		//if (level < 50) adjustment = (level - 50) * 2;
		if (level > 50) change = (level - 50) * 2;
		break;
	case 126:
		//if (level < 50) adjustment = (level - 50) * 3;
		if (level > 50) change = (level - 50) * 3;
		break;
	case 127:
		//if (level < 50) adjustment = (level - 50) * 4;
		if (level > 50) change = (level - 50) * 4;
		break;
	case 128:
		//if (level < 50) adjustment = (level - 50) * 5;
		if (level > 50) change = (level - 50) * 5;
		break;
	case 129:
		//if (level < 50) adjustment = (level - 50) * 10;
		if (level > 50) change = (level - 50) * 10;
		break;
	case 130:
		//if (level < 50) adjustment = (level - 50) * 15;
		if (level > 50) change = (level - 50) * 15;
		break;
	case 131:
		//if (level < 50) adjustment = (level - 50) * 20;
		if (level > 50) change = (level - 50) * 20;
		break;
	case 132:
		//if (level < 50) adjustment = (level - 50) * 25;
		if (level > 50) change = (level - 50) * 25;
		break;
	case 139:
		//if (level < 30) adjustment = (level - 30) / 2;
		if (level > 30) change = (level - 30) / 2;
		break;
	case 140:
		//if (level < 30) adjustment = (level - 30);
		if (level > 30) change = (level - 30);
		break;
	case 141:
		//if (level < 30) adjustment = 3 * (level - 30) / 2;
		if (level > 30) change = 3 * (level - 30) / 2;
		break;
	case 142:
		//if (level < 30) adjustment = 2 * (level - 30);
		if (level > 30) change = 2 * (level - 30);
		break;
	case 143:
		change = 3 * level / 4;
		break;
	case 3000:
		return base;
	default:
		if (calc > 0 && calc < 1000)
			change = level * calc;
		if (calc >= 1000 && calc < 2000)
			change = tick * (calc - 1000) * -1;
		if (calc >= 2000)
			change = level * (calc - 2000);
	}

	int64_t value = abs(base) + adjustment + change;

	if (max != 0 && value > abs(max))
		value = abs(max);

	if (base < 0)
		value = -value;

	return value;
}

static int CalcMaxSpellLevel(int calc, int64_t base, int64_t max, int tick, int minlevel, int level)
{
	if (abs(max) > 0)
	{
		for (int maxlevel = 1; maxlevel <= level; maxlevel++)
		{
			int value = (int)CalcValue(calc, base, max, tick, minlevel, maxlevel);

			if (abs(value) >= abs(max))
				return maxlevel;
		}

		return level;
	}

	return MAX_PC_LEVEL;
}

// Exported by mq/api/Spells.h
int CalcMinSpellLevel(EQ_Spell* pSpell)
{
	int minspelllvl = 255;

	for (int j = Warrior; j <= Berserker; j++)
	{
		if (pSpell->GetSpellLevelNeeded(j) < minspelllvl)
			minspelllvl = pSpell->GetSpellLevelNeeded(j);
	}

	if (minspelllvl > MAX_PC_LEVEL)
		minspelllvl = 1;

	return minspelllvl;
}

static char* CalcValueRange(int calc, int64_t base, int64_t max, int duration, int minlevel, int level, char* szBuffer, size_t BufferSize, const char* szPercent)
{
	int64_t start = CalcValue(calc, base, max, 1, minlevel, minlevel);
	int64_t finish = CalcValue(calc, base, max, duration, minlevel, level);
	char type[MAX_STRING] = { 0 };

	sprintf_s(type, "%s", abs(start) < abs(finish) ? "Growing" : "Decaying");

	switch (calc)
	{
	case SpellValueRangeCalc_DecayTick1:
		sprintf_s(szBuffer, BufferSize, " (%s to %lld @ 1/tick)", type, finish);
		break;
	case SpellValueRangeCalc_DecayTick2:
		sprintf_s(szBuffer, BufferSize, " (%s to %lld @ 2/tick)", type, finish);
		break;
	case SpellValueRangeCalc_DecayTick5:
		sprintf_s(szBuffer, BufferSize, " (%s to %lld @ 5/tick)", type, finish);
		break;
	case SpellValueRangeCalc_DecayTick12:
		sprintf_s(szBuffer, BufferSize, " (%s to %lld @ 12/tick)", type, finish);
		break;
	case SpellValueRangeCalc_Random:
		sprintf_s(szBuffer, BufferSize, " (Random: %lld to %lld)", start, finish * ((start >= 0) ? 1 : -1));
		break;
	default:
		if (calc > 0 && calc < 1000)
			sprintf_s(szBuffer, BufferSize, " to %lld%s", start, szPercent);
		if (calc >= 1000 && calc < 2000)
			sprintf_s(szBuffer, BufferSize, " (%s to %lld @ %d/tick)", type, finish, calc - 1000);
	}
	return szBuffer;
}

static char* CalcExtendedRange(int calc, int64_t start, int64_t finish, int minlevel, int maxlevel,
	char* szBuffer, size_t BufferSize, const char* szPercent, bool ACMod = false)
{
	switch (calc)
	{
	case SpellValueRangeCalc_Random:
		sprintf_s(szBuffer, BufferSize, " (Random: %lld to %lld)", start, finish * ((start >= 0) ? 1 : -1));
		break;

	default:
		if (abs(start) < abs(finish))
			sprintf_s(szBuffer, BufferSize, " by %lld%s (L%d) to %lld%s (L%d)", ACMod ? (int)(abs(start) / (10.0f / 3.0f)) : abs(start), szPercent, minlevel, ACMod ? (int)(abs(finish) / (10.0f / 3.0f)) : abs(finish), szPercent, maxlevel);
		else
			sprintf_s(szBuffer, BufferSize, " by %lld%s", ACMod ? (int)(abs(finish) / (10.0f / 3.0f)) : abs(finish), szPercent);
	}

	return szBuffer;
}

template <unsigned int Size>
static char* FormatAT(const char* szEffectName, int64_t value, char(&szBuffer)[Size], const char* preposition = "by", const char* szPercent = "")
{
	sprintf_s(szBuffer, "%s %s %lld%s", szEffectName, preposition, abs(value), szPercent);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatBase(const char* szEffectName, int64_t base, char(&szBuffer)[Size])
{
	sprintf_s(szBuffer, "%s (%lld)", szEffectName, base);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatBase(const char* szEffectName, int64_t base, int64_t max, char(&szBuffer)[Size])
{
	sprintf_s(szBuffer, "%s (%lld,%lld)", szEffectName, base, max);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatBase(const char* szEffectName, int64_t base, const char* szOptional, char(&szBuffer)[Size])
{
	sprintf_s(szBuffer, "%s %s (%lld)", szEffectName, szOptional, base);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatBasePercent(const char* szEffectName, int64_t base, char(&szBuffer)[Size])
{
	sprintf_s(szBuffer, "%s (%lld%%)", szEffectName, base);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatMinMaxBase(const char* szEffectName, int64_t base, int spa, char(&szBuffer)[Size])
{
	sprintf_s(szBuffer, "%s (%lld %s)", szEffectName, abs(base), szSPATypes[spa]);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatCount(const char* szEffectName, int64_t value, char(&szBuffer)[Size], const char* preposition = "by", const char* szPercent = "")
{
	sprintf_s(szBuffer, "%s %s %s %lld%s", value < 0 ? "Decrease" : "Increase", szEffectName, preposition, abs(value), szPercent);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatExtra(std::string_view szEffectName, std::string_view extra, char(&szBuffer)[Size], std::string_view trigger = "", std::string_view colon = ":")
{
	auto [out, _] = fmt::format_to_n(szBuffer, Size, "{}{} {}{}", szEffectName, colon, extra, trigger);
	*out = '\0';
	return szBuffer;
}

template <unsigned int Size>
static char* FormatLimits(const char* szEffectName, int64_t value, const char* extra, char(&szBuffer)[Size])
{
	sprintf_s(szBuffer, "%s (%s %s)", szEffectName, extra, value < 0 ? "excluded" : "allowed");
	return szBuffer;
}

template <unsigned int Size>
static char* FormatMax(const char* szEffectName, int64_t value, int64_t max, char(&szBuffer)[Size])
{
	sprintf_s(szBuffer, "%s %s by %lld (%lld%% max)", max < 0 ? "Decrease" : "Increase", szEffectName, abs(max), value);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatPenaltyChance(const char* szEffectName, int64_t value, char(&szBuffer)[Size], const char* penaltychance)
{
	if (value < 100)
		sprintf_s(szBuffer, "%s (%lld%% %s)", szEffectName, value, penaltychance);
	else
		sprintf_s(szBuffer, "%s", szEffectName);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatPercent(const char* szEffectName, int64_t value, int64_t max, char(&szBuffer)[Size], bool scaling = true, bool hundreds = false, bool usepercent = true)
{
	const char* szPercent = usepercent ? "%" : "";

	if (hundreds)
	{
		if (value == max)
		{
			if (scaling)
				sprintf_s(szBuffer, "%s %s by %.2f%s", max < 0 ? "Decrease" : "Increase", szEffectName, abs(max / 100.0f), szPercent);
			else
				sprintf_s(szBuffer, "%s by %.2f%s", szEffectName, abs(max / 100.0f), szPercent);
		}
		else
		{
			if (scaling)
				sprintf_s(szBuffer, "%s %s by %.2f%s to %.2f%s", max < 0 ? "Decrease" : "Increase", szEffectName, abs(value / 100.0f), szPercent, abs(max / 100.0f), szPercent);
			else
				sprintf_s(szBuffer, "%s by %.2f%s to %.2f%s", szEffectName, abs(value / 100.0f), szPercent, abs(max / 100.0f), szPercent);
		}
	}
	else
	{
		if (value == max)
		{
			if (scaling)
				sprintf_s(szBuffer, "%s %s by %lld%s", max < 0 ? "Decrease" : "Increase", szEffectName, abs(max), szPercent);
			else
				sprintf_s(szBuffer, "%s by %lld%s", szEffectName, abs(max), szPercent);
		}
		else
		{
			if (scaling)
				sprintf_s(szBuffer, "%s %s by %lld%s to %lld%s", max < 0 ? "Decrease" : "Increase", szEffectName, abs(value), szPercent, abs(max), szPercent);
			else
				sprintf_s(szBuffer, "%s by %lld%s to %lld%s", szEffectName, abs(value), szPercent, abs(max), szPercent);
		}
	}

	return szBuffer;
}

template <unsigned int Size>
static char* FormatPercent(const char* szEffectName, int64_t value, char(&szBuffer)[Size], bool scaling = true, bool hundreds = false, bool usepercent = true)
{
	return FormatPercent(szEffectName, value, value, szBuffer, scaling, hundreds, usepercent);
}

template <unsigned int Size>
static char* FormatRange(const char* szEffectName, int64_t value, const char* range, char(&szBuffer)[Size], const char* extra = "")
{
	sprintf_s(szBuffer, "%s %s%s%s", value < 0 ? "Decrease" : "Increase", szEffectName, range, extra);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatRateMod(const char* szEffectName, int64_t value, int64_t base, char(&szBuffer)[Size])
{
	if (base > 0)
		sprintf_s(szBuffer, "%s (rate mod %lld)", GetSpellNameByID((int)value), base);
	else
		strcat_s(szBuffer, GetSpellNameByID((int)value));
	return szBuffer;
}

template <unsigned int Size>
static char* FormatRefreshTimer(const char* szEffectName, int64_t value, int64_t max, int64_t skill, char(&szBuffer)[Size], const char* preposition = "with")
{
	if (value == max)
		sprintf_s(szBuffer, "%s %s by %lld sec %s %s", max < 0 ? "Decrease" : "Increase", szEffectName, abs(max), preposition, skill >= 0 ? szSkills[skill] : "All Skills");
	else
		sprintf_s(szBuffer, "%s %s by %lld sec to %lld sec %s %s", max < 0 ? "Decrease" : "Increase", szEffectName, abs(value), abs(max), preposition, skill >= 0 ? szSkills[skill] : "All Skills");
	return szBuffer;
}

template <unsigned int Size>
static char* FormatRefreshTimer(const char* szEffectName, int64_t value, int skill, char(&szBuffer)[Size], const char* preposition = "with")
{
	return FormatRefreshTimer(szEffectName, value, value, skill, szBuffer, preposition);
}

template <unsigned int Size>
static char* FormatResists(const char* szEffectName, int64_t value, int64_t base, char(&szBuffer)[Size])
{
	if (value < 100)
	{
		char szTemp[MAX_STRING] = { 0 };
		sprintf_s(szBuffer, "%s (%lld%% Chance)", GetSpellEffectNameByID((int)base, szTemp, MAX_STRING), value);
	}
	else
	{
		sprintf_s(szBuffer, "%s", szEffectName);
	}
	return szBuffer;
}

template <unsigned int Size>
static char* FormatSeconds(const char* szEffectName, int64_t value, char(&szBuffer)[Size], bool tens = false)
{
	if (tens)
		sprintf_s(szBuffer, "%s (%lld0.00 sec)", szEffectName, value);
	else
		sprintf_s(szBuffer, "%s (%lld sec)", szEffectName, value);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatSeconds(const char* szEffectName, float value, char(&szBuffer)[Size])
{
	sprintf_s(szBuffer, "%s (%.2f sec)", szEffectName, value);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatSecondsCount(const char* szEffectName, float value, char(&szBuffer)[Size], const char* preposition = "by")
{
	sprintf_s(szBuffer, "%s %s %s %.2f sec", value < 0 ? "Decrease" : "Increase", szEffectName, preposition, abs(value));
	return szBuffer;
}

template <unsigned int Size>
static char* FormatSkillAttack(const char* szEffectName, int64_t value, int64_t max, int64_t base2, int skill, char(&szBuffer)[Size], const char* preposition = "with")
{
	sprintf_s(szBuffer, "%s %s %s for %lld damage", FormatPercent(szEffectName, value, max, szBuffer), preposition, skill >= 0 ? szSkills[skill] : "All Skills", base2);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatSkillAttack(const char* szEffectName, int64_t value, int64_t base2, int skill, char(&szBuffer)[Size], const char* preposition = "with")
{
	return FormatSkillAttack(szEffectName, base2, base2, value, skill, szBuffer, preposition);
}

template <unsigned int Size>
static char* FormatSkills(const char* szEffectName, int64_t value, int64_t max, int64_t skill, char(&szBuffer)[Size], bool usepercent = true, const char* preposition = "with")
{
	sprintf_s(szBuffer, "%s %s %s", FormatPercent(szEffectName, value, max, szBuffer, true, false, usepercent), preposition, skill >= 0 ? szSkills[skill] : "All Skills");
	return szBuffer;
}

template <unsigned int Size>
static char* FormatSkills(const char* szEffectName, int64_t value, int skill, char(&szBuffer)[Size], bool percent = true, const char* preposition = "with")
{
	return FormatSkills(szEffectName, value, value, skill, szBuffer, usepercent, preposition);
}

template <unsigned int Size>
static char* FormatSpellChance(const char* szEffectName, int64_t value, int64_t base, char(&szBuffer)[Size])
{
	if (value < 100)
		sprintf_s(szBuffer, " (%lld%% Chance, Spell: %s)", value, GetSpellNameByID((int)base));
	else
		sprintf_s(szBuffer, " (Spell: %s)", GetSpellNameByID((int)base));
	return szBuffer;
}

template <unsigned int Size>
static char* FormatSpellGroupChance(std::string_view szEffectName, int64_t value, int groupId /* base */, char(&szBuffer)[Size])
{
	if (value < 100)
	{
		auto [out, _] = fmt::format_to_n(szBuffer, Size, " ({:d}% Chance, Spell: {:s})", value, GetSpellNameBySpellGroupID(groupId));
		*out = '\0';
	}
	else
	{
		auto [out, _] = fmt::format_to_n(szBuffer, Size, " (Spell: {:s})", GetSpellNameBySpellGroupID(groupId));
		*out = '\0';
	}

	return szBuffer;
}

template <unsigned int Size>
static char* FormatStacking(const char* szEffectName, int slot, int64_t value, int64_t max, int spa, const char* extra, char(&szBuffer)[Size])
{
	if (max > 0)
		sprintf_s(szBuffer, "%s %s spell if slot %d is effect '%s' and < %lld", szEffectName, spa == SPA_STACKING_BLOCK ? "new" : "existing", slot, extra, value);
	else
		sprintf_s(szBuffer, "%s %s spell if slot %d is effect '%s'", szEffectName, spa == SPA_STACKING_BLOCK ? "new" : "existing", slot, extra);

	return szBuffer;
}

template <unsigned int Size>
static char* FormatStatsCapRange(const char* szEffectName, int64_t value, const char* stat, const char* range, char(&szBuffer)[Size])
{
	sprintf_s(szBuffer, "%s %s %s%s", value < 0 ? "Decrease" : "Increase", stat, szEffectName, range);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatString(const char* szEffectName, const char* extra, char(&szBuffer)[Size], const char* trigger = "")
{
	sprintf_s(szBuffer, "%s %s%s", szEffectName, extra, trigger);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatTimer(const char* szEffectName, int64_t value, char(&szBuffer)[Size])
{
	sprintf_s(szBuffer, "%s by %lld.00 sec", szEffectName, value);
	return szBuffer;
}

template <unsigned int Size>
static char* FormatTimer(const char* szEffectName, float value, char(&szBuffer)[Size])
{
	sprintf_s(szBuffer, "%s by %.2f sec", szEffectName, value);
	return szBuffer;
}

int GetSpellAttrib(const EQ_Spell* pSpell, int index)
{
	if (index < 0) index = 0;

	return pSpell ? pSpell->GetEffectAttrib(index) : 0;
}

int64_t GetSpellBase(const EQ_Spell* pSpell, int index)
{
	if (index < 0) index = 0;

	return pSpell ? pSpell->GetEffectBase(index) : 0;
}

int64_t GetSpellBase2(const EQ_Spell* pSpell, int index)
{
	if (index < 0) index = 0;

	return pSpell ? pSpell->GetEffectBase2(index) : 0;
}

int64_t GetSpellMax(const EQ_Spell* pSpell, int index)
{
	if (index < 0) index = 0;

	return pSpell ? pSpell->GetEffectMax(index) : 0;
}

int GetSpellCalc(const EQ_Spell* pSpell, int index)
{
	if (index < 0) index = 0;

	return pSpell ? pSpell->GetEffectCalc(index) : 0;
}

template <typename T>
inline int EQSpellHeading(T heading)
{
	return static_cast<int>(((512 - heading) % 512) / 32);
}

char* ParseSpellEffect(EQ_Spell* pSpell, int i, char* szBuffer, size_t BufferSize, int level)
{
	char szBuff[MAX_STRING] = { 0 };
	char szTemp[MAX_STRING] = { 0 };
	char szTemp2[MAX_STRING] = { 0 };

	int id = pSpell->ID;
	int spa = GetSpellAttrib(pSpell, i);
	int64_t base = GetSpellBase(pSpell, i);
	int64_t base2 = GetSpellBase2(pSpell, i);
	int64_t max = GetSpellMax(pSpell, i);
	int calc = GetSpellCalc(pSpell, i);
	int spellgroup = pSpell->SpellGroup;
	int ticks = pSpell->DurationCap;
	int targets = pSpell->MaxTargets;
	int targettype = pSpell->TargetType;
	int skill = pSpell->Skill;

	// Handle spell effects that have no display.
	switch (spa)
	{
	case SPA_CHA:
		if (base <= 1 || base > 255)
			return szBuffer;
		break;
	case SPA_NOSPELL:           // Not a spell effect
	case SPA_PORTAL_LOCATIONS:  // Portal locations are parameters to the teleport spell. We don't need to show them a second time.
		return szBuffer;
	}

	switch (spa)
	{
	case SPA_HASTE:
	case SPA_HEIGHT:
	case SPA_BARD_HASTE:                   // Adjust for Base=100
		base -= 100;
		max -= 100;
		break;
	case SPA_SUMMON_CORPSE:                // Adjust for base/max swapped
		max = base;
		base = 0;
		break;
	case SPA_FOCUS_DAMAGE_MOD:
	case SPA_FOCUS_HEAL_MOD:
	case SPA_FOCUS_MANACOST_MOD:           // Adjust for base2 used as max
		max = base2;
		break;
	case SPA_FOCUS_REAGENT_MOD:
	case SPA_FOCUS_DAMAGE_AMT_DETRIMENTAL: // Adjust for base2 used as base
		base = base2;
		break;
	}

	ITEMDB* ItemDB = gItemDB;

	std::string spelleffectname(GetSpellEffectName(spa, szTemp, sizeof(szTemp)));
	memset(szTemp, 0, sizeof(szTemp));
	std::string extra(pSpell->Extra);

	int minspelllvl = CalcMinSpellLevel(pSpell);
	int maxspelllvl = CalcMaxSpellLevel(calc, base, max, ticks, minspelllvl, level);
	int64_t value = CalcValue(calc, (spa == SPA_STACKING_BLOCK) ? max : base, max, 1, minspelllvl, minspelllvl);
	int64_t finish = CalcValue(calc, (spa == SPA_FOCUS_INCOMING_DMG_MOD) ? base2 : base, max, ticks, minspelllvl, level);

	bool usePercent =
		(spa == SPA_MOVEMENT_RATE
			|| spa == SPA_HASTE
			|| spa == SPA_BARD_HASTE
			|| spa == SPA_FOCUS_DAMAGE_MOD
			|| spa == SPA_FOCUS_HEAL_MOD
			|| spa == SPA_DOUBLE_ATTACK
			|| spa == SPA_STUN_RESIST
			|| spa == SPA_PROC_CHANCE
			|| spa == SPA_DIVINE_SAVE
			|| spa == SPA_METABOLISM
			|| spa == SPA_TRIPLE_BACKSTAB
			|| spa == SPA_DOTCRIT
			|| spa == SPA_HEALCRIT
			|| spa == SPA_MENDCRIT
			|| spa == SPA_FLURRY
			|| spa == SPA_PET_FLURRY
			|| spa == SPA_SPELL_CRIT_CHANCE
			|| spa == SPA_SHIELD_BLOCK_CHANCE
			|| spa == SPA_FOCUS_DAMAGE_MOD_CRIT
			|| spa == SPA_FOCUS_INCOMING_DMG_MOD
			|| spa == SPA_CANCEL_NEGATIVE_MAGIC);

	bool AEEffect =
		(targettype == TT_PBAE
			|| targettype == TT_TARGETED_AE
			|| targettype == TT_AE_PC_V2
			|| targettype == TT_DIRECTIONAL);

	std::string range(CalcValueRange(calc, base, max, ticks, minspelllvl, level, szTemp2, sizeof(szTemp2), usePercent ? "%" : ""));
	std::string extendedrange(CalcExtendedRange(calc, value, finish, minspelllvl, maxspelllvl, szTemp2, sizeof(szTemp2), usePercent ? "%" : "", (spa == SPA_AC || spa == SPA_AC2)));
	std::string repeating = [&ticks]() { if (ticks) return std::string(" per tick "); else return std::string(); }();
	std::string maxlevel = [&max]() { if (max) return fmt::format(" up to level {}", max); else return std::string(); }();
	std::string maxtargets = [&targets, &AEEffect]() {
		if (targets && AEEffect) return fmt::format(" on up to {} enemies", targets);
		else return std::string();
	}();

#ifdef DEBUGSPELLS
	WriteChatf("SLOT:%d, SPA:%d, BASE:%d, BASE2:%d, MAX:%d, CALC:%d, TICKS:%d, VALUE:%d, FINISH:%d, MINSPELLLVL:%d, MAXSPELLLVL:%d, RANGE:%s, EXTENDEDRANGE:%s, USEPERCENT:%s, REPEATING:%s, MAXLEVEL:%s",
		i + 1, spa, base, base2, max, calc, ticks, value, finish, minspelllvl, maxspelllvl, range.c_str(), extendedrange.c_str(), usePercent ? "TRUE" : "FALSE", repeating, maxlevel);
#endif

	sprintf_s(szBuff, "Slot %d: ", i + 1);

	switch (spa)
	{
	case SPA_HP:                  // hp +/-: heals/regen/dd
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		if (!repeating.empty()) strcat_s(szBuff, repeating.c_str());

		if (!maxtargets.empty()) strcat_s(szBuff, maxtargets.c_str());
		if (base2) {
			GetSpellRestrictions(pSpell, i, szTemp, sizeof(szTemp));
			strcat_s(szBuff, " -- Restrictions: ");
			strcat_s(szBuff, szTemp);
		}
		break;
	case SPA_AC:                  // ac mod
	case SPA_ATTACK_POWER:        // attack mod
	case SPA_MOVEMENT_RATE:       // movement speed mod
	case SPA_STR:                 // str mod
	case SPA_DEX:                 // dex mod
	case SPA_AGI:                 // agi mod
	case SPA_STA:                 // sta mod
	case SPA_INT:                 // int mod
	case SPA_WIS:                 // wis mod
	case SPA_CHA:                 // cha mod
	case SPA_HASTE:               // haste mod
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		break;
	case SPA_INVISIBILITY:        // Invisibility
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_SEE_INVIS:           // See Invisible(c)
	case SPA_ENDURING_BREATH:     // Water Breathing(c)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), value, szTemp2));
		break;
	case SPA_MANA:                // mana +/-
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		if (!repeating.empty()) strcat_s(szBuff, repeating.c_str());
		if (!maxtargets.empty()) strcat_s(szBuff, maxtargets.c_str());
		if (base2) {
			GetSpellRestrictions(pSpell, i, szTemp, sizeof(szTemp));
			strcat_s(szBuff, " -- Restrictions: ");
			strcat_s(szBuff, szTemp);
		}
		break;
	case SPA_NPC_FRENZY:          // NPC Frenzy (no spells currently)
	case SPA_NPC_AWARENESS:       // NPC Awareness (no spells currently)
	case SPA_NPC_AGGRO:           // NPC Aggro
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_NPC_FACTION:         // NPC Faction
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		break;
	case SPA_BLINDNESS:           // Blindness
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_STUN:                // stun  time = base in ms
		if (base2 != 0 && base != base2)
			sprintf_s(szTemp, " NPC for %1.fs (PC for %1.fs)%s", base / 1000.0f, base2 / 1000.0f, maxlevel.c_str());
		else
			sprintf_s(szTemp, " for %1.fs%s", base / 1000.0f, maxlevel.c_str());
		strcat_s(szBuff, FormatString(spelleffectname.c_str(), szTemp, szTemp2));
		if (!maxtargets.empty()) strcat_s(szBuff, maxtargets.c_str());
		break;
	case SPA_CHARM:               // Charm(c/level)
	case SPA_FEAR:                // Fear(c/level)
		strcat_s(szBuff, FormatString(spelleffectname.c_str(), maxlevel.c_str(), szTemp2));
		if (!maxtargets.empty()) strcat_s(szBuff, maxtargets.c_str());
		break;
	case SPA_FATIGUE:             // Fatigue
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2));
		break;
	case SPA_BIND_AFFINITY:       // Bind Affinity
		if (base == 2)
			strcat_s(szTemp, " (Secondary Bind Point)");
		if (base == 3)
			strcat_s(szTemp, " (Tertiary Bind Point)");
		strcat_s(szBuff, FormatString(spelleffectname.c_str(), szTemp, szTemp2));
		break;
	case SPA_GATE:                // Gate
		if (base == 2)
			strcat_s(szTemp, " to Secondary Bind Point");
		if (base == 3)
			strcat_s(szTemp, " (Tertiary Bind Point)");
		strcat_s(szBuff, FormatString(spelleffectname.c_str(), szTemp, szTemp2));
		break;
	case SPA_DISPEL_MAGIC:        // Cancel Magic(c)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_INVIS_VS_UNDEAD:     // Invisibility versus Undead
	case SPA_INVIS_VS_ANIMALS:    // Invisibility versus Animal
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_NPC_AGGRO_RADIUS:    // NPC Aggro Radius(c/level)
		                          // NPC Aggro Radius' use the reverse sign from normal base values
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), -value, szTemp2));
		strcat_s(szBuff, maxlevel.c_str());
		break;
	case SPA_ENTHRALL:            // Mesmerize(c/level)
		strcat_s(szBuff, FormatString(spelleffectname.c_str(), maxlevel.c_str(), szTemp2));
		if (!maxtargets.empty()) strcat_s(szBuff, maxtargets.c_str());
		break;
	case SPA_CREATE_ITEM:         // Create Item
		while ((ItemDB) && (base != ItemDB->ID)) {
			ItemDB = ItemDB->pNext;
		}
		if (ItemDB) {
			sprintf_s(szTemp, "%s (Qty:%d)", ItemDB->szName, (int)ItemDB->StackSize < calc ? ItemDB->StackSize : calc);
		}
		else {
			sprintf_s(szTemp, "[%5lld] (Qty:%d)", base, calc);
		}
		strcat_s(szBuff, FormatExtra(spelleffectname, szTemp, szTemp2));
		break;
	case SPA_SUMMON_PET:          // Summon Pet
		strcat_s(szBuff, FormatExtra(spelleffectname, extra.c_str(), szTemp2));
		break;
	case SPA_CONFUSE:             // Confuse
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_DISEASE:             // disease counters
	case SPA_POISON:              // poison counters
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		break;
	case SPA_DETECT_HOSTILE: //DetectHostile (no spells currently)
	case SPA_DETECT_MAGIC: //DetectMagic (no spells currently)
	case SPA_NO_TWINCAST: //No Twincast
	case SPA_INVULNERABILITY: //Invulnerability
	case SPA_BANISH: //Banish
	case SPA_SHADOW_STEP: //Shadow Step
	case SPA_BERSERK: //Berserk
	case SPA_LYCANTHROPY: //Lycanthropy
	case SPA_VAMPIRISM: //Vampirism
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_RESIST_FIRE: //fire resist
	case SPA_RESIST_COLD: //cold resist
	case SPA_RESIST_POISON: //poison resist
	case SPA_RESIST_DISEASE: //disease resist
	case SPA_RESIST_MAGIC: //magic resist
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		if (!maxtargets.empty()) strcat_s(szBuff, maxtargets.c_str());
		break;
	case SPA_DETECT_TRAPS: //Detect Traps (no spells currently)
	case SPA_DETECT_UNDEAD: //Sense Undead
	case SPA_DETECT_SUMMONED: //Sense Summoned
	case SPA_DETECT_ANIMALS: //Sense Animals
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_STONESKIN: //most runes
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		break;
	case SPA_TRUE_NORTH: //True North
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_LEVITATION:
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_CHANGE_FORM: //Illusion: Base=Race
		strcat_s(szBuff, FormatExtra(spelleffectname, pEverQuest->GetRaceDesc((int)base), szTemp2));
		break;
	case SPA_DAMAGE_SHIELD: //Damage Shield
		// Damage Shield's use the reverse sign from normal base values
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), -value, extendedrange.c_str(), szTemp2));
		break;
	case SPA_TRANSFER_ITEM: //Transfer Item (no spells currently)
	case SPA_ITEM_LORE: //Identify
	case SPA_ITEM_IDENTIFY: //Item ID (no spells currently)
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_NPC_WIPE_HATE_LIST: //Memblur e%
		strcat_s(szBuff, FormatPenaltyChance(spelleffectname.c_str(), value + 40, szTemp2, "Chance"));
		if (!maxtargets.empty()) strcat_s(szBuff, maxtargets.c_str());
		break;
	case SPA_SPIN_STUN: //SpinStun
	case SPA_INFRAVISION: //Infravision
	case SPA_ULTRAVISION: //ultravision
	case SPA_EYE_OF_ZOMM: //Eye of Zomm
	case SPA_RECLAIM_ENERGY: //Reclaim Energy
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_MAX_HP: //max hp mod
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		break;
	case SPA_CORPSE_BOMB: //CorpseBomb (no spells currently)
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_CREATE_UNDEAD: //Create Undead Pet
		strcat_s(szBuff, FormatExtra(spelleffectname, extra.c_str(), szTemp2));
		break;
	case SPA_PRESERVE_CORPSE: //Preserve Corpse (no spells currently)
	case SPA_BIND_SIGHT: //Bind Sight
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_FEIGN_DEATH: //Feign Death
		strcat_s(szBuff, FormatPenaltyChance(spelleffectname.c_str(), value, szTemp2, "Chance"));
		break;
	case SPA_VENTRILOQUISM: //Voice Graft
	case SPA_SENTINEL: //Sentinel
	case SPA_LOCATE_CORPSE: //Locate Corpse
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_SPELL_SHIELD: //Absorb Magic Damage
	case SPA_INSTANT_HP: //+hp when cast (priest buffs that have heal component, DoTs with DDs)
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		if (!maxtargets.empty()) strcat_s(szBuff, maxtargets.c_str());
		break;
	case SPA_ENCHANT_LIGHT: //Enchant:Light (no spells currently)
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_RESURRECT: //Resurrect
		sprintf_s(szTemp, " and restore %lld%% experience", value);
		strcat_s(szBuff, FormatString(spelleffectname.c_str(), szTemp, szTemp2));
		if (!maxtargets.empty()) strcat_s(szBuff, maxtargets.c_str());
		break;
	case SPA_SUMMON_TARGET: //Summon Player
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_PORTAL: //zone portal spells
		if (targettype == 6) {
			sprintf_s(szTemp, " Self to %lld, %lld, %lld in %s facing %s", GetSpellBase(pSpell, 0), GetSpellBase(pSpell, 1),
				GetSpellBase(pSpell, 2), GetFullZone(GetZoneID(extra.c_str())), szHeadingNormal[EQSpellHeading(GetSpellBase(pSpell, 3))]);
		}
		else {
			sprintf_s(szTemp, " Group to %lld, %lld, %lld in %s facing %s", GetSpellBase(pSpell, 0), GetSpellBase(pSpell, 1),
				GetSpellBase(pSpell, 2), GetFullZone(GetZoneID(extra.c_str())), szHeadingNormal[EQSpellHeading(GetSpellBase(pSpell, 3))]);
		}
		strcat_s(szBuff, FormatString(spelleffectname.c_str(), szTemp, szTemp2));
		break;
	case SPA_HP_NPC_ONLY: //Toss on Z axis (is this right??)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), abs(base), base >= 0 ? " Down" : " Up", szTemp2));
		break;
	case SPA_MELEE_PROC: //Add Proc
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname.c_str(), base, base2, szTemp), szTemp2));
		break;
	case SPA_NPC_HELP_RADIUS: //Reaction Radius(c/level)
		// Reaction Radius' use the reverse sign from normal base values
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), -value, szTemp2));
		strcat_s(szBuff, maxlevel.c_str());
		if (!maxtargets.empty()) strcat_s(szBuff, maxtargets.c_str());
		break;
	case SPA_MAGNIFICATION: //Perspective Magnification
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_EVACUATE: //evac portal spells
		sprintf_s(szTemp, " to %lld, %lld, %lld in %s facing %s", GetSpellBase(pSpell, 0), GetSpellBase(pSpell, 1),
			GetSpellBase(pSpell, 2), extra.c_str(), szHeadingNormal[EQSpellHeading(GetSpellBase(pSpell, 3))]);
		strcat_s(szBuff, FormatString(spelleffectname.c_str(), szTemp, szTemp2));
		break;
	case SPA_HEIGHT: //Player Size
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_IGNORE_PET: //Cloak
	case SPA_SUMMON_CORPSE: //Summon Corpse
		strcat_s(szBuff, FormatString(spelleffectname.c_str(), maxlevel.c_str(), szTemp2));
		break;
	case SPA_HATE: //hate mod
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		if (!maxtargets.empty()) strcat_s(szBuff, maxtargets.c_str());
		break;
	case SPA_WEATHER_CONTROL: //Stop Rain
	case SPA_FRAGILE: //Make Fragile
	case SPA_SACRIFICE: //Sacrifice
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_SILENCE: //Silence (no PC spells currently)
		strcat_s(szBuff, spelleffectname.c_str());
		if (!maxtargets.empty()) strcat_s(szBuff, maxtargets.c_str());
		break;
	case SPA_MAX_MANA: //Mana Pool
	case SPA_BARD_HASTE: //Haste v2
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		break;
	case SPA_ROOT: //Root
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_HEALDOT: //hp mod: pet heals/regen
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		strcat_s(szBuff, repeating.c_str());
		break;
	case SPA_COMPLETEHEAL: //Complete Heal (with duration)
	case SPA_PET_FEARLESS: //Fearless
	case SPA_CALL_PET: //Call Pet
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_TRANSLOCATE: //zone translocate spells
		if (!extra.empty() && !extra.rfind('0', 0))
			sprintf_s(szTemp, " to %lld, %lld, %lld in %s facing %s", GetSpellBase(pSpell, 0), GetSpellBase(pSpell, 1),
				GetSpellBase(pSpell, 2), GetFullZone(GetZoneID(extra.c_str())), szHeadingNormal[EQSpellHeading(GetSpellBase(pSpell, 3))]);
		else
			strcat_s(szTemp, " to Bind Point");
		strcat_s(szBuff, FormatString(spelleffectname.c_str(), szTemp, szTemp2));
		break;
	case SPA_NPC_ANTI_GATE: //Anti-Gate
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_BEASTLORD_PET: //Summon Warder
		strcat_s(szBuff, FormatExtra(spelleffectname, extra.c_str(), szTemp2));
		break;
	case SPA_ALTER_PET_LEVEL: //Alter NPC Level (no spells currently)
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_FAMILIAR: //Summon Familiar
		strcat_s(szBuff, FormatExtra(spelleffectname, extra.c_str(), szTemp2));
		break;
	case SPA_CREATE_ITEM_IN_BAG: //Summon Into Bag
		while ((ItemDB) && (base != ItemDB->ID)) {
			ItemDB = ItemDB->pNext;
		}
		if (ItemDB) {
			sprintf_s(szTemp, "%s", ItemDB->szName);
		}
		else {
			sprintf_s(szTemp, "[%5lld]", base);
		}
		strcat_s(szBuff, FormatExtra(spelleffectname, szTemp, szTemp2));
		break;
	case SPA_ARCHERY: //Increase Archery (no spells currently)
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2));
		break;
	case SPA_RESIST_ALL: //Resistances
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		if (!maxtargets.empty()) strcat_s(szBuff, maxtargets.c_str());
		break;
	case SPA_FIZZLE_SKILL: //Casting Level
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2));
		break;
	case SPA_SUMMON_MOUNT: //Summon Mount
		strcat_s(szBuff, FormatExtra(spelleffectname, extra.c_str(), szTemp2));
		break;
	case SPA_MODIFY_HATE: //aggro multiplier
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_CORNUCOPIA: //Food/Water
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_CURSE: //curse counters
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2));
		if (!maxtargets.empty()) strcat_s(szBuff, maxtargets.c_str());
		break;
	case SPA_HIT_MAGIC: //Make Weapons Magical
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_AMPLIFICATION: //Singing Skill
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		break;
	case SPA_ATTACK_SPEED_MAX: //Bard Overhaste
	case SPA_HEALMOD: //Reduce Healing Effectiveness (%)
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_IRONMAIDEN: //Reverse Damage Shield
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), -base, szTemp2));
		break;
	case SPA_REDUCESKILL: //Reduce Skill
		strcat_s(szBuff, FormatSkills(spelleffectname.c_str(), value, finish, base2, szTemp2));
		break;
	case SPA_IMMUNITY: //Immunity
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_FOCUS_DAMAGE_MOD: //spell damage
	case SPA_FOCUS_HEAL_MOD: //healing
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_FOCUS_RESIST_MOD: //spell resist rate
	case SPA_FOCUS_CAST_TIME_MOD: //spell haste
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), -value, -finish, szTemp2));
		break;
	case SPA_FOCUS_DURATION_MOD: //spell duration
	case SPA_FOCUS_RANGE_MOD: //spell range
	case SPA_FOCUS_HATE_MOD: //spell/bash hate
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_FOCUS_REAGENT_MOD: //Decrease Chance of Using Reagent
	case SPA_FOCUS_MANACOST_MOD: //Spell Mana Cost
	case SPA_FOCUS_STUNTIME_MOD: //Spell Stun Duration (no spells currently)
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), -value, -finish, szTemp2));
		break;
	case SPA_FOCUS_LEVEL_MAX: //limit max level
		if (base2 > 0)
			sprintf_s(szTemp, "%s (%lld) (lose %lld%% per level over cap)", spelleffectname.c_str(), base, base2);
		else
			strcpy_s(szTemp, FormatBase(spelleffectname.c_str(), base, szTemp2));
		strcat_s(szBuff, szTemp);
		break;
	case SPA_FOCUS_RESIST_TYPE: //Limit: Resist
		strcat_s(szBuff, FormatLimits(spelleffectname.c_str(), value, GetResistTypeName((int)base, szTemp), szTemp2));
		break;
	case SPA_FOCUS_TARGET_TYPE: //limit target types this affects
		strcat_s(szBuff, FormatLimits(spelleffectname.c_str(), value, GetTargetTypeLimitsName((int)base, szTemp), szTemp2));
		break;
	case SPA_FOCUS_WHICH_SPA: //limit effect types this affects
		strcat_s(szBuff, FormatLimits(spelleffectname.c_str(), value, GetSpellEffectName((int)base, szTemp, sizeof(szTemp)), szTemp2));
		break;
	case SPA_FOCUS_BENEFICIAL: //limit spelltype this affects
		strcat_s(szBuff, FormatLimits(spelleffectname.c_str(), value, GetSpellTypeName((int)base, szTemp), szTemp2));
		break;
	case SPA_FOCUS_WHICH_SPELL: //limit spell this affects
		strcat_s(szBuff, FormatLimits(spelleffectname.c_str(), value, GetSpellNameByID((int)base), szTemp2));
		break;
	case SPA_FOCUS_DURATION_MIN: //limit min duration of spells this affects (base= #ticks)
		strcat_s(szBuff, FormatSeconds(spelleffectname.c_str(), value * 6, szTemp2));
		break;
	case SPA_FOCUS_INSTANT_ONLY: //limit to instant spells only
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_FOCUS_LEVEL_MIN: //Limit: Min Level
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_FOCUS_CASTTIME_MIN: //limit min casting time of spells this affects (base= seconds in ms)
	case SPA_FOCUS_CASTTIME_MAX: //limit max casting time of spells this affects (base= seconds in ms)
		strcat_s(szBuff, FormatSeconds(spelleffectname.c_str(), value / 1000.0f, szTemp2));
		break;
	case SPA_NPC_PORTAL_WARDER_BANISH: //Teleportv2
		sprintf_s(szTemp, " to %lld, %lld, %lld in %s facing %s", GetSpellBase(pSpell, 0), GetSpellBase(pSpell, 1),
			GetSpellBase(pSpell, 2), GetFullZone(GetZoneID(extra.c_str())), szHeadingNormal[EQSpellHeading(GetSpellBase(pSpell, 3))]);
		strcat_s(szBuff, FormatString(spelleffectname.c_str(), szTemp, szTemp2));
		break;
	case SPA_PORTAL_LOCATIONS: //Resist Electricity
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_PERCENT_HEAL: //Hit Points (% Max)
		strcat_s(szBuff, FormatMax(spelleffectname.c_str(), value, max, szTemp2));
		break;
	case SPA_STACKING_BLOCK: //Stacking: Block
		strcat_s(szBuff, FormatStacking(spelleffectname.c_str(), (int)base2, value, max, spa, GetSpellEffectName((int)base, szTemp, sizeof(szTemp)), szTemp2));
		break;
	case SPA_STRIP_VIRTUAL_SLOT: //Stacking: Overwrite
		strcat_s(szBuff, FormatStacking(spelleffectname.c_str(), calc - 200, value, (max > 1000 ? max - 1000 : max), spa, GetSpellEffectName((int)base, szTemp, sizeof(szTemp)), szTemp2));
		break;
	case SPA_DIVINE_INTERVENTION: //Death Save - Restore Full Health
		sprintf_s(szTemp, "Restore %s Health", base == 1 ? "Partial" : base == 2 ? "Full" : "Unknown");
		strcat_s(szBuff, FormatExtra(spelleffectname, szTemp, szTemp2));
		break;
	case SPA_POCKET_PET: //Suspended Minion (no current spells)
		sprintf_s(szTemp, "(%s)", base == 0 ? "Current HP Only" : base == 1 ? "Current HP, Buffs, Weapons" : "Unknown");
		strcat_s(szBuff, FormatExtra(spelleffectname, szTemp, szTemp2));
		break;
	case SPA_PET_SWARM: //Summon Pets (swarm)
		sprintf_s(szTemp, "%s x%lld for %lldsec", extra.c_str(), value, finish);
		strcat_s(szBuff, FormatExtra(spelleffectname, szTemp, szTemp2));
		break;
	case SPA_HEALTH_BALANCE: //Balance Party Health
		strcat_s(szBuff, FormatPenaltyChance(spelleffectname.c_str(), value, szTemp2, "Penalty"));
		break;
	case SPA_CANCEL_NEGATIVE_MAGIC: //Remove Detrimental(c)
		strcat_s(szBuff, FormatPenaltyChance(spelleffectname.c_str(), base / 10, szTemp2, "Chance"));
		break;
	case SPA_POP_RESURRECT: //PoP Resurrect
	case SPA_MIRROR: //Illusion: Target
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_FEEDBACK: //Spell Damage Shield
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), -value, extendedrange.c_str(), szTemp2));
		break;
	case SPA_REFLECT: //Chance to Reflect Spell
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_MODIFY_ALL_STATS: //Stats
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		break;
	case SPA_CHANGE_SOBRIETY: //Drunk effect
		strcat_s(szBuff, FormatAT(spelleffectname.c_str(), value, szTemp2, "if Alcholol Tolerance is below"));
		break;
	case SPA_SPELL_GUARD: //Mitigate Spell Damage
	case SPA_MELEE_GUARD: //Mitigate Melee Damage
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, szTemp2, false));
		if (max > 0)
			sprintf_s(szTemp, " until %lld absorbed", max);
		strcat_s(szBuff, szTemp);
		break;
	case SPA_ABSORB_HIT: //Absorb Damage
		sprintf_s(szTemp, " up to %lld from the next %lld melee strikes or direct damage spells", max, value);
		strcat_s(szBuff, FormatString(spelleffectname.c_str(), szTemp, szTemp2));
		break;
	case SPA_OBJECT_SENSE_TRAP: //Attempt Sense (Cursed) Trap
	case SPA_OBJECT_DISARM_TRAP: //Attempt Disarm (Cursed) Trap
	case SPA_OBJECT_PICKLOCK: //Attempt Destroy (Cursed) Lock
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_FOCUS_PET: //Increase Pet Power
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_DEFENSIVE: //Mitigation
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), -value, -finish, szTemp2));
		break;
	case SPA_CRITICAL_MELEE: //Chance to Critical Hit
		strcat_s(szBuff, FormatSkills(spelleffectname.c_str(), value, finish, base2, szTemp2, true, "for"));
		break;
	case SPA_CRITICAL_SPELL: //Critical Direct Damage
	case SPA_CRIPPLING_BLOW: //Crippling Blow
	case SPA_EVASION: //Melee Avoidance
	case SPA_RIPOSTE: //Riposte
	case SPA_DODGE: //Dodge
	case SPA_PARRY: //Parry
	case SPA_DUAL_WIELD: //Dual Wield
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_DOUBLE_ATTACK: //Stat Cap Mod (how do they know which?)
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		break;
	case SPA_MELEE_LIFETAP: //Lifetap Proc
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		strcat_s(szBuff, " heal");
		break;
	case SPA_PURETONE: //Puretone
	case SPA_SANCTIFICATION: //Spell Resist
	case SPA_FEARLESS: //Fearless
	case SPA_HUNDRED_HANDS: //Hundred Hands
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_SKILL_INCREASE_CHANCE: //Skill Chance Mod
	case SPA_ACCURACY: //Chance to hit with Backstab (or throwing/archery [http://lucy.allakhazam.com/spellraw.html?id=9616&source=Live])
	case SPA_SKILL_DAMAGE_MOD: //Damage Mod (how to tell which, rogues get a backstab only, others get an all skills)
	case SPA_MIN_DAMAGE_DONE_MOD: //Damage Mod (see above)
		strcat_s(szBuff, FormatSkills(spelleffectname.c_str(), value, finish, base2, szTemp2));
		break;
	case SPA_MANA_BALANCE: //Mana Balance
		strcat_s(szBuff, FormatPenaltyChance(spelleffectname.c_str(), value, szTemp2, "Penalty"));
		break;
	case SPA_BLOCK: //Block
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_ENDURANCE: //Endurance DoT/Regen
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		strcat_s(szBuff, repeating.c_str());
		break;
	case SPA_INCREASE_MAX_ENDURANCE: //Max Endurance
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		break;
	case SPA_AMNESIA: //Amnesia
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_HATE_OVER_TIME: //Discord Hate
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		if (!maxtargets.empty()) strcat_s(szBuff, maxtargets.c_str());
		break;
	case SPA_SKILL_ATTACK: //Skill Attack
		strcat_s(szBuff, FormatSkillAttack(spelleffectname.c_str(), value, base2, skill, szTemp2));
		if (!maxtargets.empty()) strcat_s(szBuff, maxtargets.c_str());
		break;
	case SPA_FADE: //Fade
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_STUN_RESIST: //Stun Resist
	case SPA_STRIKETHROUGH1: //Strikethrough
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		break;
	case SPA_SKILL_DAMAGE_TAKEN: //Skill Damage
		strcat_s(szBuff, FormatSkills(spelleffectname.c_str(), value, finish, base2, szTemp2));
		if (!maxtargets.empty()) strcat_s(szBuff, maxtargets.c_str());
		break;
	case SPA_INSTANT_ENDURANCE: //Endurance Heals
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2));
		break;
	case SPA_TAUNT: //Taunt
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_PROC_CHANCE: //Proc Mod
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		break;
	case SPA_RANGE_ABILITY: //Ranged Proc
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname.c_str(), base, base2, szTemp), szTemp2));
		break;
	case SPA_ILLUSION_OTHERS: //Illusion Other
	case SPA_MASS_GROUP_BUFF: //Mass Group Buff
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_GROUP_FEAR_IMMUNITY: //War Cry
		strcat_s(szBuff, FormatSeconds(spelleffectname.c_str(), value, szTemp2, true));
		break;
	case SPA_RAMPAGE: //AE Rampage
	case SPA_AE_TAUNT: //AE Taunt
	case SPA_FLESH_TO_BONE: //Flesh to Bone
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_PURGE_POISON: //Purge Poison (no spells currently)
	case SPA_CANCEL_BENEFICIAL: //Disspell Beneficial Buffs
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_SHIELD_CASTER: //Pet Shield
		strcat_s(szBuff, FormatSeconds(spelleffectname.c_str(), value * 1.0f, szTemp2));
		break;
	case SPA_DESTRUCTIVE_FORCE: //AE Melee
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_FOCUS_FRENZIED_DEVASTATION: //Frenzied Devastation (### come back and change ###)
		strcat_s(szBuff, FormatSeconds(spelleffectname.c_str(), value, szTemp2, true));
		break;
	case SPA_PET_PCT_MAX_HP://Pet HP
	case SPA_HP_MAX_HP: //Change Max HP
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2, false, true));
		break;
	case SPA_PET_PCT_AVOIDANCE: //Pet Avoidance (no spells currently)
	case SPA_MELEE_ACCURACY: //Accuracy
	case SPA_HEADSHOT: //Headshot (no spells currently)
	case SPA_PET_CRIT_MELEE: //Pet Crit Melee (no spells currently)
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		if (!maxtargets.empty()) strcat_s(szBuff, maxtargets.c_str());
		break;
	case SPA_SLAY_UNDEAD: //Slay undead (Holyforge)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_INCREASE_SKILL_DAMAGE: //Skill Damage Amt
		strcat_s(szBuff, FormatSkills(spelleffectname.c_str(), value, finish, base2, szTemp2, false));
		break;
	case SPA_REDUCE_WEIGHT: //Reduce Weight
	case SPA_BLOCK_BEHIND: //Block Behind
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_DOUBLE_RIPOSTE: //Double Riposte (no spells currently)
	case SPA_ADD_RIPOSTE: //Additional Riposte
	case SPA_GIVE_DOUBLE_ATTACK: //Double Attack
	case SPA_2H_BASH: //2H Bash (no spells currently)
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_REDUCE_SKILL_TIMER: //Base Refresh Timer
		strcat_s(szBuff, FormatRefreshTimer(spelleffectname.c_str(), -value, -finish, base2, szTemp2));
		break;
	case SPA_ACROBATICS: //Reduce Fall Dmg (no spells currently)
	case SPA_CAST_THROUGH_STUN: //Cast Through Stun (no spells currently)
	case SPA_EXTENDED_SHIELDING: //Increase Shield Dist (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_BASH_CHANCE: //Stun Bash Chance (no spells currently)
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_DIVINE_SAVE: //Divine Save
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		break;
	case SPA_METABOLISM: //Metabolism
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), -value, extendedrange.c_str(), szTemp2));
		break;
	case SPA_POISON_MASTERY: //Poison Mastery (no spells currently)
	case SPA_FOCUS_CHANNELING: //Focus Channelling (no spells currently)
	case SPA_FREE_PET: //Free Pet (no spells currently)
	case SPA_PET_AFFINITY: //Pet Affinity (no spells currently)
	case SPA_PERM_ILLUSION: //Permanent Illusion (no spells currently)
	case SPA_STONEWALL: //Stonewall (no spells currently)
	case SPA_STRING_UNBREAKABLE: //String Unbreakable (no spells currently)
	case SPA_IMPROVE_RECLAIM_ENERGY: //Improve Reclaim Energy (no spells currently)
	case SPA_INCREASE_CHANGE_MEMWIPE: //Increase Chance Memwipe (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_ENHANCED_CHARM: //NoBreak Charm Chance
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_ENHANCED_ROOT: //Root Break Chance
	case SPA_TRAP_CIRCUMVENTION: //Trap Circumvention (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_INCREASE_AIR_SUPPLY: //Lung Capacity
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, range.c_str(), szTemp2));
		break;
	case SPA_INCREASE_MAX_SKILL: //Increase SkillCap (no spells currently)
	case SPA_EXTRA_SPECIALIZATION: //Extra Specialization (no spells currently)
	case SPA_OFFHAND_MIN_WEAPON_DAMAGE: //Offhand Min (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_INCREASE_PROC_CHANCE: //Spell Proc Chance
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_ENDLESS_QUIVER: //Endless Quiver (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_BACKSTAB_FRONT: //Backstab from Front
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_CHAOTIC_STAB: //Chaotic Stab (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_NOSPELL: //placeholder of some kind
		break;
	case SPA_SHIELDING_DURATION_MOD: //Shielding Duration (no spells currently)
		strcat_s(szBuff, FormatBasePercent(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_SHROUD_OF_STEALTH: //Shroud Of Stealth (no spells currently)
	case SPA_GIVE_PET_HOLD: //Give Pet Hold (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_TRIPLE_BACKSTAB: //Triple Backstab
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_AC_LIMIT_MOD: //AC Limit
	case SPA_ADD_INSTRUMENT_MOD: //Add Instrument
	case SPA_SONG_MOD_CAP: //Song Cap (no spells currently)
		strcat_s(szBuff, FormatBasePercent(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_INCREASE_STAT_CAP: //Stats Cap
		strcat_s(szBuff, FormatStatsCapRange(spelleffectname.c_str(), value, GetStatShortName((int)base2, szTemp), extendedrange.c_str(), szTemp2));
		break;
	case SPA_TRADESKILL_MASTERY: //Tradeskill Masteries (no spells currently)
	case SPA_REDUCE_AA_TIMER: //Reduce AATimer
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_NO_FIZZLE: //No Fizzle
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_ADD_2H_ATTACK_CHANCE: //Attack Chance
	case SPA_ADD_PET_COMMANDS: //Add Pet Commands (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_ALCHEMY_FAIL_RATE: //TS Fail Rate
		strcat_s(szBuff, FormatSkills(spelleffectname.c_str(), -value, -finish, base2, szTemp2, true, "for"));
		break;
	case SPA_FIRST_AID: //Bandage Perc Limit (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_EXTEND_SONG_RANGE: //Bard Song Range
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2, "to"));
		break;
	case SPA_BASE_RUN_MOD: //Base Run Speed
		strcat_s(szBuff, FormatBasePercent(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_INCREASE_CASTING_LEVEL: //Casting Level
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2));
		break;
	case SPA_DOTCRIT: //DoT Crit
	case SPA_HEALCRIT: //Heal Crit
	case SPA_MENDCRIT: //Mend Crit (no spells currently)
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		break;
	case SPA_DUAL_WIELD_AMT: //Dual Wield Amt (no spells currently)
	case SPA_EXTRA_DI_CHANCE: //Extra DI Chance (no spells currently)
	case SPA_FINISHING_BLOW: //Finishing Blow (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_FLURRY: //Flurry
	case SPA_PET_FLURRY: //Pet Flurry Chance
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		break;
	case SPA_PET_FEIGN: //Give Pet Feign (no spells currently)
	case SPA_INCREASE_BANDAGE_AMT: //Increase Bandage Amt (no spells currently)
	case SPA_WU_ATTACK: //Special Attack Chain (no spells currently)
	case SPA_IMPROVE_LOH: //LoH Set Heal (no spells currently)
	case SPA_NIMBLE_EVASION: //NoMove Check Sneak (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_FOCUS_DAMAGE_AMT: //DD Bonus
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		break;
	case SPA_FOCUS_DURATION_AMT: //Focus Combat Duration
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2));
		strcat_s(szBuff, " tick(s)");
		break;
	case SPA_ADD_PROC_HIT: //Add Proc Hit (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_DOOM_EFFECT: //Trigger on Fade
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID((int)base), szTemp2, " on Fade"));
		break;
	case SPA_INCREASE_RUN_SPEED_CAP: //Increase Movement Cap (no spells currently)
	case SPA_PURIFY: //Purify
	case SPA_STRIKETHROUGH: //Strikethrough2
	case SPA_STUN_RESIST2: //StunResist2 (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_SPELL_CRIT_CHANCE: //Spell Crit Chance
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		break;
	case SPA_REDUCE_SPECIAL_TIMER: //Reduce Timer Special (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_FOCUS_DAMAGE_MOD_DETRIMENTAL: //Incoming Spell Damage
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_FOCUS_DAMAGE_AMT_DETRIMENTAL: //Incoming Spell Damage Amt
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2));
		break;
	case SPA_TINY_COMPANION: //Tiny Companion
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), -value, -finish, szTemp2));
		break;
	case SPA_WAKE_DEAD: //Wake the Dead
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_DOPPELGANGER: //Doppleganger
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_INCREASE_RANGE_DMG: //Increase Range Damage (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_FOCUS_DAMAGE_MOD_CRIT: //Damage Crit
	case SPA_FOCUS_DAMAGE_AMT_CRIT: //Damage
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		break;
	case SPA_SECONDARY_RIPOSTE_MOD: //Secondary Riposte Mod (no spells currently)
		strcat_s(szBuff, FormatBasePercent(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_DAMAGE_SHIELD_MOD: //Damage Shield Mitigation
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), -value, -finish, szTemp2));
		break;
	case SPA_WEAK_DEAD_2: //Army of Dead
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_APPRAISAL: //Appraisal
	case SPA_ZONE_SUSPEND_MINION: //Suspend Minion
	case SPA_TELEPORT_CASTERS_BINDPOINT: //Teleport Bind
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_FOCUS_REUSE_TIMER: //Reuse Timer
		strcat_s(szBuff, FormatTimer(spelleffectname.c_str(), -base / 1000.0f, szTemp2));
		break;
	case SPA_FOCUS_COMBAT_SKILL: //No Combat Skills
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_OBSERVER: //Sanc
	case SPA_FORAGE_MASTER: //Forage Master (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_IMPROVED_INVIS: //Improved Invisibility
	case SPA_IMPROVED_INVIS_UNDEAD: //Improved Invisibility Vs Undead
	case SPA_IMPROVED_INVIS_ANIMALS: //Improved Invisibility Vs Animals (no spells currently)
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_INCREASE_WORN_HP_REGEN_CAP: //Worn Regen Cap
	case SPA_INCREASE_WORN_MANA_REGEN_CAP: //Worn Mana Cap
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_CRITICAL_HP_REGEN: //Critical HP Regen
	case SPA_SHIELD_BLOCK_CHANCE: //Shield Block Chance
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		break;
	case SPA_REDUCE_TARGET_HATE: //Soothing
		strcat_s(szBuff, FormatBasePercent(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_GATE_STARTING_CITY: //Origin
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_DEFENSIVE_PROC: //Add Defensive Proc
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname.c_str(), base, base2, szTemp), szTemp2));
		break;
	case SPA_HP_FOR_MANA: //Spirit Channel
		strcat_s(szBuff, FormatBasePercent(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_NO_BREAK_AE_SNEAK: //No Break AE Sneak (no spells currently)
	case SPA_ADD_SPELL_SLOTS: //Spell Slots (no spells currently)
	case SPA_ADD_BUFF_SLOTS: //Buff Slots (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_INCREASE_NEGATIVE_HP_LIMIT: //Negative HP Limit
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2));
		break;
	case SPA_MANA_ABSORB_PCT_DMG: //Mana Shield
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2, "up to", "%"));
		break;
	case SPA_CRIT_ATTACK_MODIFIER: //Crit Damage
		strcat_s(szBuff, FormatSkills(spelleffectname.c_str(), value, finish, base2, szTemp2));
		break;
	case SPA_FAIL_ALCHEMY_ITEM_RECOVERY: //Item Recovery
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_SUMMON_TO_CORPSE: //Summon to Corpse
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_DOOM_RUNE_EFFECT: //Trigger on fade
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID((int)base), szTemp2, " on Fade"));
		break;
	case SPA_NO_MOVE_HP: //Song DoT
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		strcat_s(szBuff, repeating.c_str());
		strcat_s(szBuff, " if target is not moving");
		break;
	case SPA_FOCUSED_IMMUNITY: //Fc_Immunity Focus
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_ILLUSIONARY_TARGET: //Illusionary Target (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_INCREASE_EXP_MOD: //Experience buff
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_EXPEDIENT_RECOVERY: //Expedient Recovery
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_FOCUS_CASTING_PROC: //Trigger DoT on cast
	case SPA_CHANCE_SPELL: //Trigger DD on cast
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatSpellChance(spelleffectname.c_str(), base, base2, szTemp), szTemp2, " on Cast"));
		break;
	case SPA_WORN_ATTACK_CAP: //Worn Attack Cap
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2));
		break;
	case SPA_NO_PANIC: //Prevent Flee on Low Health
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_SPELL_INTERRUPT: //Spell Interrupt
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		if (!maxtargets.empty()) strcat_s(szBuff, maxtargets.c_str());
		break;
	case SPA_ITEM_CHANNELING: //Item Channeling (no spells currently)
	case SPA_ASSASSINATE_MAX_LEVEL: //Assassinate Max (no spells currently)
	case SPA_HEADSHOT_MAX_LEVEL: //Headshot Max (no spells currently)
	case SPA_DOUBLE_RANGED_ATTACK: //Double Ranged Attack (no spells currently)
	case SPA_FOCUS_MANA_MIN: //Limit: Mana Min
	case SPA_INCREASE_SHIELD_DMG: //Increase Damage With Shield (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_MANABURN: //Manaburn
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value * 4, szTemp2, "for"));
		break;
	case SPA_SPAWN_INTERACTIVE_OBJECT: //Persistent Effect
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID(id + (spellgroup ? 3 : 1)), szTemp2));
		break;
	case SPA_INCREASE_TRAP_COUNT: //Increase Trap Count
	case SPA_INCREASE_SOI_COUNT: //Increase SOI Count
	case SPA_DEACTIVATE_ALL_TRAPS: //Deactivate All Traps
	case SPA_LEARN_TRAP: //Learn Trap
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_CHANGE_TRIGGER_TYPE: //Change Trigger Type (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_FOCUS_MUTE: //Mute
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_INSTANT_MANA: //Mana/Max Mana
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2));
		break;
	case SPA_PASSIVE_SENSE_TRAP: //Passive Sense Trap
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_PROC_ON_KILL_SHOT: //Killshot Triggers
	case SPA_PROC_ON_DEATH: //Proc On Death
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatSpellChance(spelleffectname.c_str(), base, base2, szTemp), szTemp2));
		break;
	case SPA_POTION_BELT: //Potion Belt (no spells currently)
	case SPA_BANDOLIER: //Bandolier (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_ADD_TRIPLE_ATTACK_CHANCE: //Triple Attack Chance
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_PROC_ON_SPELL_KILL_SHOT: //Trigger on Kill Shot
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatSpellChance(spelleffectname.c_str(), base, base2, szTemp), szTemp2));
		break;
	case SPA_GROUP_SHIELDING: //Group Shielding
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_MODIFY_BODY_TYPE: //Change Body Type
		sprintf_s(szTemp, " to %s", base == 25 ? "Plant" : base == 21 ? "Animal" : base == 3 ? "Undead" : "Unknown");
		strcat_s(szBuff, FormatString(spelleffectname.c_str(), szTemp, szTemp2));
		break;
	case SPA_MODIFY_FACTION: //Modify Faction
		strcat_s(szBuff, FormatExtra(spelleffectname, GetFactionName((int)base, szTemp), szTemp2));
		break;
	case SPA_CORRUPTION: //Corruption Counters
	case SPA_RESIST_CORRUPTION: //Corruption Resists
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2));
		break;
	case SPA_SLOW: //Slow
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_GRANT_FORAGING: //Grant Foraging (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_DOOM_ALWAYS: //Trigger Effect
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID((int)base), szTemp2, " on Fade"));
		break;
	case SPA_TRIGGER_SPELL: //Trigger Spell
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatSpellChance(spelleffectname.c_str(), base, base2, szTemp), szTemp2));
		break;
	case SPA_CRIT_DOT_DMG_MOD: //Critical DoT Damage Mod
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_FLING: //Fling
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_DOOM_ENTITY: //Trigger Effect
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID((int)base), szTemp2, " on Fade"));
		break;
	case SPA_RESIST_OTHER_SPA: //Resist
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatResists(spelleffectname.c_str(), base, base2, szTemp), szTemp2));
		break;
	case SPA_DIRECTIONAL_TELEPORT: //Directional Shadowstep
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2));
		break;
	case SPA_EXPLOSIVE_KNOCKBACK: //Knockback Explosive
		sprintf_s(szTemp, " (%lld) and Toss Up (%lld)", base, base2);
		strcat_s(szBuff, FormatString(spelleffectname.c_str(), szTemp, szTemp2));
		break;
	case SPA_FLING_TOWARD: //Fling to Self
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_SUPPRESSION: //Negate: Effect
	{
		char szString[MAX_STRING] = { 0 };
		sprintf_s(szTemp, " %s Effect", GetSpellEffectNameByID((int)base2, szString, MAX_STRING));
		strcat_s(szBuff, FormatExtra(spelleffectname, szTemp, szTemp2));
		break;
	}
	case SPA_FOCUS_CASTING_PROC_NORMALIZED: //Trigger Spell
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatSpellChance(spelleffectname.c_str(), base, base2, szTemp), szTemp2, " on Cast"));
		break;
	case SPA_FLING_AT: //Fling to Target
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_FOCUS_WHICH_GROUP: //Limit: SpellGroup
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameBySpellGroupID((int)base), szTemp2));
		break;
	case SPA_DOOM_DISPELLER: //Trigger Effect
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID((int)base), szTemp2, " on Curer"));
		break;
	case SPA_DOOM_DISPELLEE: //Trigger Effect
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID((int)base), szTemp2, " on Fade"));
		break;
	case SPA_SUMMON_ALL_CORPSES: //Summon All Corpses
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_REFRESH_SPELL_TIMER: //Spell Gem Refresh
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), -value, szTemp2, "to"));
		break;
	case SPA_LOCKOUT_SPELL_TIMER: //Fc_Timer Lockout
	case SPA_FOCUS_MANA_MAX: //Limit: Mana Max
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_FOCUS_HEAL_AMT: //Heal Amt
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2));
		break;
	case SPA_FOCUS_HEAL_MOD_BENEFICIAL: //Incoming Healing Effectiveness
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_FOCUS_HEAL_AMT_BENEFICIAL: //Incoming Healing Amt
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2));
		break;
	case SPA_FOCUS_HEAL_MOD_CRIT: //Fc_Heal % Crit (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_FOCUS_HEAL_AMT_CRIT: //Heal Amt
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2));
		break;
	case SPA_ADD_PET_AC: //Pet Amt Mitigation (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_FOCUS_SWARM_PET_DURATION: //Swarm Pet Duration
		strcat_s(szBuff, FormatSecondsCount(spelleffectname.c_str(), value / 1000.0f, szTemp2));
		break;
	case SPA_FOCUS_TWINCAST_CHANCE: //Twincast Chance
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_HEALBURN: //Healburn
		sprintf_s(szTemp, " use up to %lld mana to heal your group", value);
		strcat_s(szBuff, FormatString(spelleffectname.c_str(), szTemp, szTemp2));
		break;
	case SPA_MANA_IGNITE: //Mana/HP
	case SPA_ENDURANCE_IGNITE: //Endurance/HP
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), -value, szTemp2, "by up to"));
		break;
	case SPA_FOCUS_SPELL_CLASS: //Limit: SpellClass
	case SPA_FOCUS_SPELL_SUBCLASS: //Limit: SpellSubclass
	case SPA_STAFF_BLOCK_CHANCE: //Staff Block Chance (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_DOOM_LIMIT_USE: //Trigger Effect
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID((int)base), szTemp2, " on Max Hits"));
		break;
	case SPA_DOOM_FOCUS_USED: //Trigger Effect
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID((int)base), szTemp2, " on Focus Used"));
		break;
	case SPA_LIMIT_HP: //Limit HP
	case SPA_LIMIT_MANA: //Limit Mana
	case SPA_LIMIT_ENDURANCE: //Limit Endurance
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2, "to"));
		break;
	case SPA_FOCUS_LIMIT_CLASS: //Limit: PlayerClass
		strcat_s(szBuff, FormatExtra(spelleffectname, GetClassesFromMask((int)base).c_str(), szTemp2));
		break;
	case SPA_FOCUS_LIMIT_RACE: //Limit: Race (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2)); // needs work (base2 bitmask of races)
		break;
	case SPA_FOCUS_BASE_EFFECTS: //Base Dmg
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2, "by", "%"));
		break;
	case SPA_FOCUS_LIMIT_SKILL: //Limit: CastingSkill
	case SPA_FOCUS_LIMIT_ITEM_CLASS: //Limit: ItemClass (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_AC2: //AC2
	case SPA_MANA2: //Mana2
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2));
		break;
	case SPA_FOCUS_INCREASE_SKILL_DMG_2: //Increased Skill Damage2
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2));
		break;
	case SPA_PROC_EFFECT_2: //Add Proc
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname.c_str(), base, base2, szTemp), szTemp2));
		break;
	case SPA_FOCUS_LIMIT_USE: //Fc_Limit Use (no spells currently)
	case SPA_FOCUS_LIMIT_USE_AMT: //Fc_Limit Use Amt (no spells currently)
	case SPA_FOCUS_LIMIT_USE_MIN: //Limit: Use Min (no spells currently)
	case SPA_FOCUS_LIMIT_USE_TYPE: //Limit: Use Type (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_GRAVITATE: //Gravitate
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		if (!maxtargets.empty()) strcat_s(szBuff, maxtargets.c_str());
		break;
	case SPA_FLY: //Fly
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_ADD_EXTENDED_TARGET_SLOTS: //AddExtTargetSlots (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_SKILL_PROC: //Skill Proc
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname.c_str(), base, base2, szTemp), szTemp2));
		break;
	case SPA_PROC_SKILL_MODIFIER: //Limit Skill
		strcat_s(szBuff, FormatExtra(spelleffectname, base >= 0 ? szSkills[base] : "All Skills", szTemp2));
		break;
	case SPA_SKILL_PROC_SUCCESS: //Skill Proc Success
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname.c_str(), base, base2, szTemp), szTemp2));
		break;
	case SPA_POST_EFFECT: //PostEffect
	case SPA_POST_EFFECT_DATA: //PostEffectData
	case SPA_EXPAND_MAX_ACTIVE_TROPHY_BENEFITS: //ExpandMaxActiveTrophyBenefits (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_ADD_NORMALIZED_SKILL_MIN_DMG_AMT: //Skill Min Damage
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatRateMod(spelleffectname.c_str(), base, base2, szTemp), szTemp2));
		break;
	case SPA_ADD_NORMALIZED_SKILL_MIN_DMG_AMT_2: //Skill Min Damage
	case SPA_FRAGILE_DEFENSE: //Fragile Defense
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_FREEZE_BUFF_TIMER: //Beneficial Countdown Hold
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_TELEPORT_TO_ANCHOR: //Teleport to Anchor
	case SPA_TRANSLOCATE_TO_ANCHOR: //Translocate to Anchor
		sprintf_s(szTemp, " to %s Anchor", base == 50874 ? "Guild Hall" : base == 52584 ? "Primary" : base == 52585 ? "Secondary" : "Unknown");
		strcat_s(szBuff, FormatString(spelleffectname.c_str(), szTemp, szTemp2));
		break;
	case SPA_ASSASSINATE: //Assassinate (no spells currently)
	case SPA_FINISHING_BLOW_MAX: //FinishingBlowMax (no spells currently)
	case SPA_DISTANCE_REMOVAL: //Distance Removal
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_REQUIRE_TARGET_DOOM: //Doom Req Target
	case SPA_REQUIRE_CASTER_DOOM: //Doom Req Caster
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID((int)base), szTemp2));
		if (base2) {
			GetSpellRestrictions(pSpell, i, szTemp, sizeof(szTemp));
			strcat_s(szBuff, " -- Restrictions: ");
			strcat_s(szBuff, szTemp);
		}
		break;
	case SPA_IMPROVED_TAUNT: //Improved Taunt
		sprintf_s(szTemp, " up to L%lld and Reduce Ally Hate Generation by %lld%%", base, base2);
		strcat_s(szBuff, FormatString(spelleffectname.c_str(), szTemp, szTemp2));
		break;
	case SPA_ADD_MERC_SLOT: //Add Merc Slot
	case SPA_STACKER_A: //A_Stacker
	case SPA_STACKER_B: //B_Stacker
	case SPA_STACKER_C: //C_Stacker
	case SPA_STACKER_D: //D_Stacker
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_DOT_GUARD: //DoT Guard
		sprintf_s(szTemp, " absorbing %lld%% damage to a total of %lld", value, max);
		strcat_s(szBuff, FormatString(spelleffectname.c_str(), szTemp, szTemp2));
		break;
	case SPA_MELEE_THRESHOLD_GUARD: //Melee Threshold Guard
	case SPA_SPELL_THRESHOLD_GUARD: //Spell Threshold Guard
		sprintf_s(szTemp, " absorbing %lld%% of incoming %s damage in excess of %lld to a total of %lld", value,
			spa == SPA_MELEE_THRESHOLD_GUARD ? "melee" : "spell", base2, max);
		strcat_s(szBuff, FormatString(spelleffectname.c_str(), szTemp, szTemp2));
		break;
	case SPA_MELEE_THRESHOLD_DOOM: //Doom Melee Threshold
		sprintf_s(szTemp, " on %lld Melee Damage Taken", base2);
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID((int)base), szTemp2, szTemp));
		break;
	case SPA_SPELL_THRESHOLD_DOOM: //Doom Spell Threshold
		sprintf_s(szTemp, " on %lld Spell Damage Taken", base2);
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID((int)base), szTemp2, szTemp));
		break;
	case SPA_ADD_HATE_PCT: //Add Hate %
	case SPA_ADD_HATE_OVER_TIME_PCT: //Add Hate Over Time %
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_RESOURCE_TAP: //Resource Tap
		sprintf_s(szTemp, "Return %.2f%% of direct damage as %s", value / 10.0f, base2 == 0 ? "hit points" : base2 == 1 ? "mana" : base2 == 2 ? "endurance" : "unknown");
		strcat_s(szBuff, szTemp);
		break;
	case SPA_FACTION_MOD: //Faction Mod %
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_SKILL_DAMAGE_MOD_2: //Damage Mod 2 (how to tell which, rogues get a backstab only, others get an all skills)
		strcat_s(szBuff, FormatSkills(spelleffectname.c_str(), value, finish, base2, szTemp2));
		break;
	case SPA_OVERRIDE_NOT_FOCUSABLE: //Limit: Include Non-Focusable
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_FOCUS_DAMAGE_MOD_2: //Fc Damage % 2 (no spells currently)
	case SPA_FOCUS_DAMAGE_AMT_2: //Fc Damage Amt 2 (no spells currently)
	case SPA_SHIELD: //Shield Target (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_PC_PET_RAMPAGE: //PC Pet Rampage
	case SPA_PC_PET_AE_RAMPAGE: //PC Pet AE Rampage
	case SPA_PC_PET_FLURRY: //PC Pet Flurry Chance
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_DAMAGE_SHIELD_MITIGATION_AMT: //DS Mitigation Amt
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_DAMAGE_SHIELD_MITIGATION_PCT: //DS Mitigation Percentage
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_CHANCE_BEST_IN_SPELL_GROUP: //Chance Best in Spell Group
	case SPA_TRIGGER_BEST_IN_SPELL_GROUP: //Trigger Best in Spell Group
		strcat_s(szBuff, FormatExtra(spelleffectname, FormatSpellGroupChance(spelleffectname, base, (int)base2, szTemp), szTemp2, " on Cast"));
		break;
	case SPA_DOUBLE_MELEE_ATTACKS: //Double Melee Round (PC Only)
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_AA_BUY_NEXT_RANK: //Toggle Passive AA Rank
		strcat_s(szBuff, spelleffectname.c_str());
		break;
	case SPA_DOUBLE_BACKSTAB_FRONT: //Double Backstab From Front  (no spells currently)
	case SPA_PET_MELEE_CRIT_DMG_MOD: //Pet Crit Melee Damage% (Owner)  (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_TRIGGER_SPELL_NON_ITEM: //Trigger Spell Non-Item
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID((int)base2), szTemp2, " on Cast"));
		break;
	case SPA_WEAPON_STANCE: //Weapon Stance (no spells currently)
	case SPA_HATELIST_TO_TOP: //Move to Top of Hatelist (no spells currently)
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_HATELIST_TO_TAIL: //Move to Bottom of Hatelist
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID((int)base), szTemp2, " on Cast"));
		break;
	case SPA_FOCUS_LIMIT_MIN_VALUE: //Value Min
		sprintf_s(szTemp, "%s %s", spelleffectname.c_str(), base < 0 ? "Max" : "Min");
		strcat_s(szBuff, FormatMinMaxBase(szTemp, base, (int)base2, szTemp2));
		break;
	case SPA_FOCUS_LIMIT_MAX_VALUE: //Value Max
		sprintf_s(szTemp, "%s %s", spelleffectname.c_str(), base < 0 ? "Min" : "Max");
		strcat_s(szBuff, FormatMinMaxBase(szTemp, base, (int)base2, szTemp2));
		break;
	case SPA_FOCUS_CAST_SPELL_ON_LAND: //Cast Spell on Land
		strcat_s(szBuff, FormatExtra(spelleffectname, GetSpellNameByID((int)base2), szTemp2, " on Land and conditions are met"));
		break;
	case SPA_SKILL_BASE_DAMAGE_MOD: //Skill Base Damage Mod
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_FOCUS_INCOMING_DMG_MOD: //Spell Damage Taken
	case SPA_FOCUS_INCOMING_DMG_AMT: //Spell Damage Taken
		strcat_s(szBuff, FormatRange(spelleffectname.c_str(), value, extendedrange.c_str(), szTemp2, " (after crit)"));
		break;
	case SPA_FOCUS_LIMIT_CASTER_CLASS: //CasterClass
		strcat_s(szBuff, FormatExtra(spelleffectname, GetClassesFromMask((int)base).c_str(), szTemp2));
		break;
	case SPA_FOCUS_LIMIT_SAME_CASTER: //Same Caster
		strcat_s(szBuff, FormatExtra(spelleffectname, base ? "(Same)" : "(Different)", szTemp2, "", ""));
		break;
	case SPA_EXTEND_TRADESKILL_CAP: //Extend Tradeskill Cap
		sprintf_s(szTemp, "%s (%lld, %lld, %lld)", spelleffectname.c_str(), base, base2, max);
		strcat_s(szBuff, szTemp);
		break;
	case SPA_DEFENDER_MELEE_FORCE_PCT: //Push Taken
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), -base, szTemp2));
		break;
	case SPA_WORN_ENDURANCE_REGEN_CAP: //Worn Endurance Regen Cap
		strcat_s(szBuff, FormatBase(spelleffectname.c_str(), base, szTemp2));
		break;
	case SPA_FOCUS_MIN_REUSE_TIME: //Limit: ReuseTime Min
	case SPA_FOCUS_MAX_REUSE_TIME: //Limit: ReuseTime Max
		strcat_s(szBuff, FormatSeconds(spelleffectname.c_str(), value / 1000.0f, szTemp2));
		break;
	case SPA_FOCUS_ENDURANCE_MIN: //Limit: Endurance Min
	case SPA_FOCUS_ENDURANCE_MAX: //Limit: Endurance Max
	case SPA_PET_ADD_ATK: //Pet Add Attack
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2));
		break;
	case SPA_FOCUS_DURATION_MAX: //Limit: Duration Max
		strcat_s(szBuff, FormatSeconds(spelleffectname.c_str(), value * 6, szTemp2));
		break;
	case SPA_CRIT_MELEE_DMG_MOD_MAX: //Critical Hit Damage (Non-stacking)
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		strcat_s(szBuff, " of Base Damage (Non Stacking)");
		break;
	case SPA_FOCUS_CAST_PROC_NO_BYPASS: //NoProc
		sprintf_s(szTemp, "%s (%lld, %lld, %lld)", spelleffectname.c_str(), base, base2, max);
		strcat_s(szBuff, szTemp);
		break;
	case SPA_ADD_EXTRA_PRIMARY_ATTACK_PCT: //Extra Attack % (1H Primary)
	case SPA_ADD_EXTRA_SECONDARY_ATTACK_PCT: //Extra Attack % (1H Secondary)
	case SPA_FOCUS_CAST_TIME_MOD2: //Spell Haste v2
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_FOCUS_CAST_TIME_AMT: //Spell Cast Time
	case SPA_FEARSTUN: //Stun and Fear
		strcat_s(szBuff, FormatSeconds(spelleffectname.c_str(), value / 1000.0f, szTemp2));
		break;
	case SPA_MELEE_DMG_POSITION_MOD: //Rear Arc Melee Damage Mod
		strcat_s(szBuff, FormatSeconds(spelleffectname.c_str(), value / 10.0f, szTemp2));
		break;
	case SPA_MELEE_DMG_POSITION_AMT: //Rear Arc Melee Damage
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2));
		break;
	case SPA_DMG_TAKEN_POSITION_MOD: //Rear Arc Damage Taken Mod
		strcat_s(szBuff, FormatSeconds(spelleffectname.c_str(), value / 10.0f, szTemp2));
		break;
	case SPA_DMG_TAKEN_POSITION_AMT: //Rear Arc Damage Taken
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2));
		break;
	case SPA_AMPLIFY_MOD: //Spell Damage v4 Mod
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		strcat_s(szBuff, " (Before DoT Crit, After Nuke Crit)");
		break;
	case SPA_AMPLIFY_AMT: //Spell Damage v4
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2));
		break;
	case SPA_HEALTH_TRANSFER: //Health Transfer
		sprintf_s(szTemp, "%s (%lld, %lld, %lld)", spelleffectname.c_str(), base, base2, max);
		strcat_s(szBuff, szTemp);
		break;
	case SPA_FOCUS_RESIST_INCOMING: //Resist Incoming
		strcat_s(szBuff, FormatCount(spelleffectname.c_str(), value, szTemp2));
		break;
	case SPA_ATTACK_ACCURACY_MAX: //Attack Accuracy Max Percent
		strcat_s(szBuff, FormatPercent(spelleffectname.c_str(), value, finish, szTemp2));
		break;
	case SPA_FOCUS_TIMER_MIN: //Focus Timer Min
	case SPA_PROC_TIMER_MOD: //Proc Timer Modifier
	case SPA_MANA_MAX: //Mana Max Percent
	case SPA_ENDURANCE_MAX: //Endurance Max Percent
	case SPA_AC_AVOIDANCE_MAX: //AC Avoidance Max Percent
	case SPA_AC_MITIGATION_MAX: //AC Mitigation Max Percent
	case SPA_ATTACK_OFFENSE_MAX: //Attack Offense Max Percent
	case SPA_LUCK_AMT: //Luck Amt
	case SPA_LUCK_PCT: //Luck Percent
	case SPA_ENDURANCE_ABSORB_PCT_DMG: // Endurance Absorb % Damage
	case SPA_INSTANT_MANA_PCT: // Instant Mana %
	case SPA_INSTANT_ENDURANCE_PCT: // Instant Endurance %
	case SPA_DURATION_HP_PCT: // Duration HP %
	case SPA_DURATION_MANA_PCT: // Duration Mana %
	case SPA_DURATION_ENDURANCE_PCT: // Duration Endurance %
	default: //undefined effect
		sprintf_s(szTemp, "%s (base=%lld, base2=%lld, max=%lld, calc=%d, value=%lld)", spelleffectname.c_str(), base, base2, max, calc, value);
		strcat_s(szBuff, szTemp);
		break;
	}

#ifdef DEBUGSPELLS
	if (strlen(szBuff) > 0) WriteChatf("%s", szBuff);
#endif
	strcat_s(szBuffer, BufferSize, szBuff);
	return szBuffer;
}

char* ShowSpellSlotInfo(EQ_Spell* pSpell, char* szBuffer, size_t BufferSize, const char* lineBreak)
{
	char szTemp[MAX_STRING] = { 0 };
	char szBuff[MAX_STRING] = { 0 };
	size_t count = 0;
	for (int i = 0; i < GetSpellNumEffects(pSpell); i++)
	{
		szBuff[0] = szTemp[0] = '\0';
		strcat_s(szBuff, ParseSpellEffect(pSpell, i, szTemp, sizeof(szTemp)));
		size_t len = strlen(szBuff);
		if (len > 0 && count + len < BufferSize) {
			strcat_s(szBuffer, BufferSize, szBuff);
			strcat_s(szBuffer, BufferSize, lineBreak);
		}
		count += len + 4;
	}
	return szBuffer;
}

void SlotValueCalculate(char* szBuff, EQ_Spell* pSpell, int i, double mp)
{
	sprintf_s(szBuff, 12, "%lld",
		CalcValue(GetSpellCalc(pSpell, i), GetSpellBase(pSpell, i), GetSpellMax(pSpell, i), pSpell->DurationCap));
}

int64_t GetSpellCounters(eEQSPA spellAffect, const EQ_Affect& buff)
{
	int64_t count = 0;

	EQ_Spell* pSpell = GetSpellByID(buff.SpellID);
	if (!pSpell || pSpell->SpellType != SpellType_Detrimental)
		return 0;

	int slots = GetSpellNumEffects(pSpell);

	for (int i = 0; i < slots; i++)
	{
		int attrib = GetSpellAttrib(pSpell, i);

		if (attrib == spellAffect)
		{
			for (auto& slotData : buff.SlotData)
			{
				if (slotData.Slot == i)
				{
					count += slotData.Value;
				}
			}
		}
	}

	return count;
}

int64_t GetMySpellCounters(eEQSPA spellAffect)
{
	const PcProfile* pProfile = GetPcProfile();
	if (!pProfile)
		return 0;

	int64_t count = 0;

	for (const auto& buff : pProfile->Buffs)
	{
		count += GetSpellCounters(spellAffect, buff);
	}

	return count;
}

int64_t GetTotalSpellCounters(const EQ_Affect& buff)
{
	int64_t count = 0;

	EQ_Spell* pSpell = GetSpellByID(buff.SpellID);
	if (!pSpell || pSpell->SpellType != SpellType_Detrimental)
		return 0;

	int slots = GetSpellNumEffects(pSpell);

	for (int i = 0; i < slots; i++)
	{
		int attrib = GetSpellAttrib(pSpell, i);

		if (IsSpellCountersSPA(attrib))
		{
			for (auto& slotData : buff.SlotData)
			{
				if (slotData.Slot == i)
				{
					count += slotData.Value;
				}
			}
		}
	}

	return count;
}

int64_t GetMyTotalSpellCounters()
{
	const PcProfile* pProfile = GetPcProfile();
	if (!pProfile)
		return 0;

	int64_t total = 0;

	for (const auto& buff : pProfile->Buffs)
	{
		total += GetTotalSpellCounters(buff);
	}

	return total;
}

int GetTriggerSPA(EQ_Spell* pSpell)
{
	eEQSPA SPAtoCheck[] = {
		SPA_TRIGGER_BEST_IN_SPELL_GROUP,
		SPA_CHANCE_BEST_IN_SPELL_GROUP,
		SPA_TRIGGER_SPELL,
		SPA_CHANCE_SPELL
	};

	for (eEQSPA spa : SPAtoCheck)
	{
		if (IsSPAEffect(pSpell, spa))
			return spa;
	}

	return 0;
}

int GetMeleeSpeedFromTriggers(EQ_Spell* pSpell, bool bIncrease)
{
	int triggerSPA = GetTriggerSPA(pSpell);
	if (triggerSPA == 0)
		return 0;

	int result = 0;

	int numEffects = GetSpellNumEffects(pSpell);
	for (int index = 0; index < numEffects; index++)
	{
		if (int groupId = (int)GetSpellBase2(pSpell, index))
		{
			EQ_Spell* pTrigger = nullptr;

			switch (triggerSPA)
			{
			case SPA_TRIGGER_BEST_IN_SPELL_GROUP:
				pTrigger = GetHighestLearnedSpellByGroupID(groupId);
				if (!pTrigger)
				{
					pTrigger = GetHighestLearnedSpellByGroupID(groupId);
				}
				break;

			case SPA_TRIGGER_SPELL:
				pTrigger = pSpellMgr->GetSpellByID(groupId);
				break;

			default:
				break; // should not be reachable if we handled everything GetTriggerSPA returns
			}

			if (pTrigger
				&& !ci_equals(pTrigger->Name, "Unknown Spell")
				&& !ci_equals(pTrigger->Name, pSpell->Name))
			{
				result = std::max(GetMeleeSpeedPctFromSpell(pTrigger, bIncrease), result);
			}
		}
	}

	return result;
}

int GetMeleeSpeedPctFromSpell(EQ_Spell* pSpell, bool bIncrease)
{
	if (GetTriggerSPA(pSpell) != 0)
	{
		return GetMeleeSpeedFromTriggers(pSpell, bIncrease);
	}

	if (!pLocalPlayer)
		return 0;

	int numEffects = GetSpellNumEffects(pSpell);
	for (int index = 0; index < numEffects; index++)
	{
		int spa = GetSpellAttrib(pSpell, index);
		if (spa == SPA_HASTE)
		{
			int64_t base = GetSpellBase(pSpell, index) - 100;
			if ((!bIncrease && base < 0) || (bIncrease && base > 0))
			{
				int64_t max = GetSpellMax(pSpell, index) - 100;
				int calc = GetSpellCalc(pSpell, index);
				int minSpellLevel = CalcMinSpellLevel(pSpell);

				int finish = (int)CalcValue(calc, base, max, 0, minSpellLevel, pLocalPlayer->Level);
				return abs(finish);
			}
		}
	}

	return 0;
}

//Usage: The spa is the spellaffect id, for example 11 for Melee Speed
//       the bIncrease tells the function if we want spells that increase or decrease the SPA
bool HasSPA(EQ_Spell* pSpell, eEQSPA eSPA, bool bIncrease)
{
	if (!pSpell)
		return false;

	const SpellAffectData* spellAffect = nullptr;
	for (int index = 0; index < pSpell->GetNumEffects(); ++index)
	{
		if (const SpellAffectData* sad = pSpell->GetSpellAffectByIndex(index))
		{
			if (sad->Attrib == eSPA)
			{
				spellAffect = sad;
				break;
			}
		}
	}

	if (spellAffect == nullptr)
		return false;

	auto base = spellAffect->Base;

	switch (eSPA)
	{
	case SPA_HP: // HP regen or DoT, below 0 means its a DoT or lich-like spell
	case SPA_MANA: // Mana regen or drain, below 0 means its draining mana
	case SPA_MOVEMENT_RATE: // Movement Rate, below 0 means its a snare above its runspeed increase
		return (!bIncrease && base < 0) || (bIncrease && base > 0);

	case SPA_HASTE: // Melee Speed
		// below 100 means its a slow above its haste...
		return (!bIncrease && base < 100) || (bIncrease && base > 100);

	case SPA_DAMAGE_SHIELD: // Damage Shield
		// decreased DS
		return (!bIncrease && base > 0) || (bIncrease && base < 0);

	case SPA_IRONMAIDEN: // Reverse Damage Shield
		// decreased DS
		return (!bIncrease && base > 0) || (bIncrease && base < 0);

	default:
		// has the SPA
		return true;
	}
}
bool HasSPA(const EQ_Affect& buff, eEQSPA eSPA, bool bIncrease) { return HasSPA(GetSpellByID(buff.SpellID), eSPA, bIncrease); }
bool HasSPA(const CachedBuff& buff, eEQSPA eSPA, bool bIncrease) { return HasSPA(GetSpellByID(buff.spellId), eSPA, bIncrease); }

int GetPlayerClass(std::string_view name)
{
	auto player_class = std::find_if(std::cbegin(ClassInfo), std::cend(ClassInfo),
		[name](const SClassInfo& info)
		{
			return ci_equals(info.ShortName, name) || ci_equals(info.Name, name);
		});

	if (player_class != std::cend(ClassInfo))
		return static_cast<int>(std::distance(std::cbegin(ClassInfo), player_class));

	return 0;
}

int GetPlayerClass(const char* name)
{
	return GetPlayerClass(std::string_view(name)); // explicit cast to disambiguate
}

bool IsSpellUsableForClass(EQ_Spell* pSpell, unsigned int classmask)
{
	if (!pSpell)
		return false;

	if (classmask != Unknown)
	{
		for (int N = 0; N < 16; N++)
		{
			if (classmask & (1 << N))
			{
				if (pSpell->ClassLevel[N] != 255)
					return true;
			}
		}
		return false;
	}
	return true;
}
bool IsSpellUsableForClass(const EQ_Affect& buff, unsigned int classmask) { return IsSpellUsableForClass(GetSpellByID(buff.SpellID), classmask); }
bool IsSpellUsableForClass(CachedBuff buff, unsigned int classmask) { return IsSpellUsableForClass(GetSpellByID(buff.spellId), classmask); }

int GetSpellCategory(EQ_Spell* pSpell)
{
	if (pSpell)
	{
		if (pSpell->CannotBeScribed)
		{
			if (SPELL* pTrigger = GetSpellParent(pSpell->ID))
			{
				return pTrigger->Category;
			}
		}
		else
		{
			return pSpell->Category;
		}
	}

	return 0;
}
int GetSpellCategory(const EQ_Affect& buff) { return GetSpellCategory(GetSpellByID(buff.SpellID)); }
int GetSpellCategory(CachedBuff buff) { return GetSpellCategory(GetSpellByID(buff.spellId)); }

int GetSpellSubcategory(EQ_Spell* pSpell)
{
	if (pSpell)
	{
		if (pSpell->CannotBeScribed)
		{
			if (SPELL* pTrigger = GetSpellParent(pSpell->ID))
			{
				return pTrigger->Subcategory;
			}
		}
		else
		{
			return pSpell->Subcategory;
		}
	}

	return 0;
}
int GetSpellSubcategory(const EQ_Affect& buff) { return GetSpellSubcategory(GetSpellByID(buff.SpellID)); }
int GetSpellSubcategory(CachedBuff buff) { return GetSpellSubcategory(GetSpellByID(buff.spellId)); }

DWORD GetSpellID(EQ_Spell* spell)
{
	if (spell == nullptr)
		return false;

	return spell->ID;
}
DWORD GetSpellID(const EQ_Affect& buff) { return buff.SpellID; }
DWORD GetSpellID(const CachedBuff& buff) { return buff.spellId; }

const char* GetSpellName(EQ_Spell* spell)
{
	if (spell == nullptr || spell->Name == nullptr || spell->Name[0] == '\0')
		return false;

	return spell->Name;
}
const char* GetSpellName(const EQ_Affect& buff) { return GetSpellNameByID(buff.SpellID); }
const char* GetSpellName(const CachedBuff& buff) { return GetSpellNameByID(buff.spellId); }

const char* GetSpellCaster(const EQ_Affect& buff)
{
	if (pBuffWnd != nullptr)
	{
		if (auto buffInfo = pBuffWnd->GetBuffInfoBySpellID(buff.SpellID))
			return buffInfo.GetCaster();
	}

	if (pSongWnd != nullptr)
	{
		if (auto buffInfo = pSongWnd->GetBuffInfoBySpellID(buff.SpellID))
			return buffInfo.GetCaster();
	}

	return "";
}

const char* GetSpellCaster(const CachedBuff& buff)
{
	return buff.casterName;
}

const char* GetPetSpellCaster(const EQ_Affect& buff)
{
	if (pPetInfoWnd != nullptr)
	{
		if (auto pBuffInfo = pPetInfoWnd->GetBuffInfoBySpellID(buff.SpellID))
		{
			return pBuffInfo.GetCaster();
		}
	}

	return "";
}

eEQSPELLCAT GetSpellCategoryFromName(std::string_view category)
{
	if (auto it = s_spellCatLookup.find(category); it != s_spellCatLookup.end())
		return it->second;

	return static_cast<eEQSPELLCAT>(0);
}

eEQSPELLCAT GetSpellCategoryFromName(const char* category)
{
	return GetSpellCategoryFromName(std::string_view(category)); // explicit cast to disambiguate
}

eEQSPA GetSPAFromName(std::string_view spa)
{
	if (auto it = s_spaLookup.find(spa); it != s_spaLookup.end())
		return it->second;

	return static_cast<eEQSPA>(-1);
}

eEQSPA GetSPAFromName(const char* spa)
{
	return GetSPAFromName(std::string_view(spa)); // explicit cast to disambiguate
}

int GetTargetBuffByCategory(DWORD category, DWORD classmask, int startslot)
{
	return GetCachedBuff(pTarget, SpellCategory(static_cast<eEQSPELLCAT>(category)) && SpellClassMask(classmask));
}

int GetTargetBuffBySubCat(const char* subcat, DWORD classmask, int startslot)
{
	return GetCachedBuff(pTarget, [subcat, classmask](const CachedBuff& buff)
		{
			auto spell = GetSpellByID(buff.spellId);
			if (!spell) return false;

			if (const char* ptr = pCDBStr->GetString(GetSpellSubcategory(spell), eSpellCategory, NULL))
			{
				return !_stricmp(ptr, subcat) && IsSpellUsableForClass(spell, classmask);
			}

			return false;
		});
}

int GetTargetBuffBySPA(int spa, bool bIncrease, int startslot)
{
	return GetCachedBuff(pTarget, SpellAffect(static_cast<eEQSPA>(spa), bIncrease));
}

bool HasCachedTargetBuffSubCat(const char* subcat, SPAWNINFO* pSpawn, void*, DWORD classmask)
{
	return GetCachedBuffCount(pSpawn, [subcat, classmask](const CachedBuff& buff)
		{
			auto spell = GetSpellByID(buff.spellId);
			if (!spell) return false;

			if (const char* ptr = pCDBStr->GetString(GetSpellSubcategory(spell), eSpellCategory, NULL))
			{
				return !_stricmp(ptr, subcat) && IsSpellUsableForClass(spell, classmask);
			}

			return false;
		}) > 0;
}

bool HasCachedTargetBuffSPA(int spa, bool bIncrease, SPAWNINFO* pSpawn, void*)
{
	return GetCachedBuffCount(pSpawn, [spa, bIncrease](const CachedBuff& buff)
		{
			return HasSPA(buff, static_cast<eEQSPA>(spa), bIncrease);
		}) > 0;
}

int GetSelfBuff(const std::function<bool(const EQ_Affect&)>& fPredicate, int minSlot /* = 0 */, int maxSlot /* = -1 */)
{
	PcProfile* pProfile = GetPcProfile();
	if (!pProfile)
		return -1;

	if (minSlot < 0)
		minSlot = 0;
	if (maxSlot < 0 || maxSlot > MAX_TOTAL_BUFFS)
		maxSlot = MAX_TOTAL_BUFFS;

	for (int i = minSlot; i < maxSlot; ++i)
	{
		EQ_Affect& buff = pProfile->GetEffect(i);

		if (fPredicate(buff))
			return i;
	}

	return -1;
}

int GetSelfBuff(const std::function<bool(EQ_Spell*)>& fPredicate, int minSlot, int maxSlot)
{
	auto predicate = [&fPredicate](const EQ_Affect& buff)
	{
		auto spell = GetSpellByID(buff.SpellID);
		return spell && fPredicate(spell);
	};

	return GetSelfBuff(predicate, minSlot, maxSlot);
}

int GetSelfBuffByCategory(DWORD category, DWORD classmask, int startslot)
{
	return GetSelfBuff(SpellCategory(static_cast<eEQSPELLCAT>(category)) && SpellClassMask(classmask), startslot);
}

int GetSelfBuffBySubCat(PCHAR subcat, DWORD classmask, int startslot)
{
	return GetSelfBuff([subcat, classmask](const EQ_Affect& buff)
		{
			auto spell = GetSpellByID(buff.SpellID);
			if (!spell) return false;

			if (const char* ptr = pCDBStr->GetString(GetSpellSubcategory(spell), eSpellCategory, NULL))
			{
				return !_stricmp(ptr, subcat) && IsSpellUsableForClass(spell, classmask);
			}

			return false;
		}, startslot);
}

int GetSelfBuffBySPA(int spa, bool bIncrease, int startslot)
{
	return GetSelfBuff(SpellAffect(static_cast<eEQSPA>(spa), bIncrease), startslot);
}

int GetSelfShortBuffBySPA(int spa, bool bIncrease, int startslot)
{
	return GetSelfBuff(SpellAffect(static_cast<eEQSPA>(spa), bIncrease), startslot);
}

int GetSpellRankByName(const char* SpellName)
{
	// uppercase the string
	char szTemp[256];
	strcpy_s(szTemp, SpellName);
	_strupr_s(szTemp);

	if (endsWith(szTemp, " II"))
		return 2;
	if (endsWith(szTemp, " III"))
		return 3;
	if (endsWith(szTemp, " IV"))
		return 4;
	if (endsWith(szTemp, " V"))
		return 5;
	if (endsWith(szTemp, " VI"))
		return 6;
	if (endsWith(szTemp, " VII"))
		return 7;
	if (endsWith(szTemp, " VIII"))
		return 8;
	if (endsWith(szTemp, " IX"))
		return 9;
	if (endsWith(szTemp, " X"))
		return 10;
	if (endsWith(szTemp, " XI"))
		return 11;
	if (endsWith(szTemp, " XII"))
		return 12;
	if (endsWith(szTemp, " XIII"))
		return 13;
	if (endsWith(szTemp, " XIV"))
		return 14;
	if (endsWith(szTemp, " XV"))
		return 15;
	if (endsWith(szTemp, " XVI"))
		return 16;
	if (endsWith(szTemp, " XVII"))
		return 17;
	if (endsWith(szTemp, " XVIII"))
		return 18;
	if (endsWith(szTemp, " XIX"))
		return 19;
	if (endsWith(szTemp, " XX"))
		return 20;
	if (endsWith(szTemp, " XXI"))
		return 21;
	if (endsWith(szTemp, " XXII"))
		return 22;
	if (endsWith(szTemp, " XXIII"))
		return 23;
	if (endsWith(szTemp, " XXIV"))
		return 24;
	if (endsWith(szTemp, " XXV"))
		return 25;
	if (endsWith(szTemp, " XXVI"))
		return 26;
	if (endsWith(szTemp, " XXVII"))
		return 27;
	if (endsWith(szTemp, " XXVIII"))
		return 28;
	if (endsWith(szTemp, " XXIX"))
		return 29;
	if (endsWith(szTemp, " XXX"))
		return 30;

	if (endsWith(szTemp, ".II"))
		return 2;
	if (endsWith(szTemp, ".III"))
		return 3;

	return 0;
}

void TruncateSpellRankName(char* SpellName)
{
	if (char* pch = strrchr(SpellName, '.'))
	{
		pch -= 3;
		*pch = 0;
	}
}

int FindBuffIndex(std::string_view Name, int minSlot, int maxSlot)
{
	if (Name.empty())
		return -1;

	return GetSelfBuff([&Name](EQ_Spell* spell) { return MaybeExactCompare(spell->Name, Name); }, minSlot, maxSlot);
}

bool RemoveBuffByName(std::string_view buffName)
{
	if (!pLocalPC) return false;

	auto checkBuffWnd = [&buffName](CBuffWindow* pBuffWnd) -> bool
	{
		if (!pBuffWnd) return false;

		for (const auto& buffInfo : pBuffWnd->GetBuffRange())
		{
			if (EQ_Spell* pSpell = buffInfo.GetSpell())
			{
				if (ci_equals(buffName, pSpell->Name))
				{
					pLocalPC->RemoveBuffEffect(pBuffWnd->firstEffectSlot + buffInfo.GetIndex(), pLocalPlayer->SpawnID);
					return true;
				}
			}
		}

		return false;
	};

	if (checkBuffWnd(pBuffWnd)) return true;
	if (checkBuffWnd(pSongWnd)) return true;

	return false;
}

bool RemoveBuffBySpellID(int spellId)
{
	if (!pLocalPC) return false;
	if (spellId <= 0) return false;

	auto checkBuffWnd = [spellId](CBuffWindow* pBuffWnd) -> bool
	{
		if (!pBuffWnd) return false;

		for (const auto& buffInfo : pBuffWnd->GetBuffRange())
		{
			if (spellId == buffInfo.GetSpellID())
			{
				pLocalPC->RemoveBuffEffect(pBuffWnd->firstEffectSlot + buffInfo.GetIndex(), pLocalPlayer->SpawnID);
				return true;
			}

			return false;
		}

		return false;
	};

	if (checkBuffWnd(pBuffWnd)) return true;
	if (checkBuffWnd(pSongWnd)) return true;

	return false;
}

bool RemoveBuffByIndex(int buffIndex)
{
	if (buffIndex < 0 && buffIndex >= MAX_TOTAL_BUFFS)
		return false;

	// the Buff index for this function is defined to be based on the local PC data.
	const EQ_Affect& affect = pLocalPC->GetEffect(buffIndex);

	auto checkBuffWnd = [buffIndex, &affect](CBuffWindow* pBuffWnd) -> bool
	{
		if (!pBuffWnd) return false;

		// Do a simple range check to ensure we're in the proper window
		if (buffIndex < pBuffWnd->firstEffectSlot || buffIndex > pBuffWnd->lastEffectSlot)
			return false;

		// Indices might not be in the correct order, so always use the order of the buff window
		for (const auto& buffInfo : pBuffWnd->GetBuffRange())
		{
			// If the spell id matches then remove it.
			if (buffInfo.GetSpellID() == affect.SpellID)
			{
				pLocalPC->RemoveBuffEffect(pBuffWnd->firstEffectSlot + buffInfo.GetIndex(), pLocalPlayer->SpawnID);
				return true;
			}
		}

		return false;
	};

	if (checkBuffWnd(pBuffWnd)) return true;
	if (checkBuffWnd(pSongWnd)) return true;

	return false;
}

bool RemovePetBuffByName(std::string_view buffName)
{
	if (!pPetInfoWnd) return false;

	for (const auto& buffInfo : pPetInfoWnd->GetBuffRange())
	{
		if (EQ_Spell* pSpell = buffInfo.GetSpell())
		{
			if (ci_equals(buffName, pSpell->Name))
			{
				pLocalPC->RemovePetEffect(buffInfo.GetIndex());
				return true;
			}
		}
	}

	return false;
}

void RemoveBuff(PlayerClient* pChar, const char* szLine)
{
	char szCmd[MAX_STRING] = { 0 };
	GetMaybeQuotedArg(szCmd, MAX_STRING, szLine, 1);

	if (_strnicmp(szLine, "-pet", 4) == 0)
	{
		GetMaybeQuotedArg(szCmd, MAX_STRING, szLine, 2);
		RemovePetBuff(pChar, szCmd);
		return;
	}

	if (_strnicmp(szLine, "-both", 5) == 0)
	{
		GetMaybeQuotedArg(szCmd, MAX_STRING, szLine, 2);
		RemovePetBuff(pChar, szCmd);
	}

	if (szCmd[0] != '\0')
	{
		int buffIndex = FindBuffIndex(szCmd);
		if (buffIndex != -1)
		{
			RemoveBuffByIndex(buffIndex);
		}
	}
}

void RemovePetBuff(PlayerClient* pChar, const char* szLine)
{
	if (!pPetInfoWnd || !szLine || szLine[0] == '\0')
		return;

	char szArg[MAX_STRING] = { 0 };
	GetMaybeQuotedArg(szArg, MAX_STRING, szLine, 1);

	for (int nBuff = 0; nBuff < pPetInfoWnd->GetMaxBuffs(); ++nBuff)
	{
		EQ_Spell* pBuffSpell = GetSpellByID(pPetInfoWnd->GetBuff(nBuff));
		if (pBuffSpell && MaybeExactCompare(pBuffSpell->Name, szArg))
		{
			pLocalPC->RemovePetEffect(nBuff);
			return;
		}
	}
}

// --------------------------- Buff Find DSL --------------------------------

template <typename Buff, typename Caster = SpellCasterAttribute>
static SpellAttributePredicate<Buff> InternalBuffEvaluate(std::string_view dsl)
{
	using DSL = SimpleLexer<SpellAttributePredicate<Buff>>;

	static auto spaDSL = DSL(
		[]() -> SpellAttributePredicate<Buff>
		{ return [](const Buff&) { return false; }; },
		"spa", DSL::Term([](std::string_view arg) -> SpellAttributePredicate<Buff>
			{
				auto spa = GetIntFromString(arg, -1);
				if (spa < 0)
					spa = GetSPAFromName(arg);
				return SpellAffect(static_cast<eEQSPA>(spa));
			}),
		"detspa", DSL::Term([](std::string_view arg) -> SpellAttributePredicate<Buff>
			{
				auto spa = GetIntFromString(arg, -1);
				if (spa < 0)
					spa = GetSPAFromName(arg);
				return SpellAffect(static_cast<eEQSPA>(spa), false);
			}),
		"cat", DSL::Term([](std::string_view arg) -> SpellAttributePredicate<Buff>
			{
				auto cat = GetIntFromString(arg, 0);
				if (cat == 0)
					cat = GetSpellCategoryFromName(arg);
				return SpellCategory(static_cast<eEQSPELLCAT>(cat));
			}),
		"subcat", DSL::Term([](std::string_view arg) -> SpellAttributePredicate<Buff>
			{
				auto cat = GetIntFromString(arg, 0);
				if (cat == 0)
					cat = GetSpellCategoryFromName(arg);
				return SpellSubCat(static_cast<eEQSPELLCAT>(cat));
			}),
		"class", DSL::Term([](std::string_view arg) -> SpellAttributePredicate<Buff>
			{
				auto player_class = GetIntFromString(arg, 0);
				if (player_class == 0)
					player_class = GetPlayerClass(arg);
				return SpellClass(static_cast<PlayerClass>(player_class));
			}),
		"id", DSL::Term([](std::string_view arg) -> SpellAttributePredicate<Buff>
			{ return SpellIDAttribute(GetIntFromString(arg, 0)); }),
		"name", DSL::Term([](std::string_view arg) -> SpellAttributePredicate<Buff>
			{ return SpellNameAttribute(arg); }),
		"caster", DSL::Term([](std::string_view arg) -> SpellAttributePredicate<Buff>
			{
				auto id = GetIntFromString(arg, -1);
				if (id >= 0)
				{
					auto name = GetSpawnByID(id);
					if (name != nullptr)
						return Caster(name->Name);

					return [](const Buff&) { return false; };
				}

				return Caster(arg);
			}),
		"and", DSL::Reducer([](SpellAttributePredicate<Buff>&& a, SpellAttributePredicate<Buff>&& b) -> SpellAttributePredicate<Buff>
			{ return BothSpellAttribute<Buff>(std::move(a), std::move(b)); }),
		"or", DSL::Reducer([](SpellAttributePredicate<Buff>&& a, SpellAttributePredicate<Buff>&& b) -> SpellAttributePredicate<Buff>
			{ return EitherSpellAttribute<Buff>(std::move(a), std::move(b)); }),
		"not", DSL::Modifier([](SpellAttributePredicate<Buff>&& a) -> SpellAttributePredicate<Buff>
			{ return NotSpellAttribute<Buff>(std::move(a)); })
	);

	static ci_unordered::map<std::string_view, SpellAttributePredicate<Buff>> s_dslMap;
	static ci_unordered::set<std::string> s_dsls; // storing like this prevents allocating a string every time

	try
	{
		auto maybe_predicate = s_dslMap.find(dsl);
		if (maybe_predicate == s_dslMap.end())
		{
			auto [dsl_iter, _] = s_dsls.emplace(dsl);

			// this guarantees ownership of the DSL string is in the set, so we are free to use string_view's for everything in the DSL
			auto predicate = spaDSL(*dsl_iter);
			s_dslMap[*dsl_iter] = predicate;

			return predicate;
		}

		return maybe_predicate->second;
	}
	catch (SimpleLexerParseError& e)
	{
		WriteChatf("%s", e.msg().c_str());
		return [](const Buff&) { return false; };
	}
}

SpellAttributePredicate<EQ_Affect> mq::EvaluateBuffPredicate(std::string_view dsl)
{
    return InternalBuffEvaluate<EQ_Affect>(dsl);
}

SpellAttributePredicate<EQ_Affect> mq::EvaluatePetBuffPredicate(std::string_view dsl)
{
    return InternalBuffEvaluate<EQ_Affect, PetSpellCasterAttribute>(dsl);
}

SpellAttributePredicate<CachedBuff> mq::EvaluateCachedBuffPredicate(std::string_view dsl)
{
    return InternalBuffEvaluate<CachedBuff>(dsl);
}

//============================================================================

static void InitializeSpells()
{
}

static void ShutdownSpells()
{
}

static void PulseSpells()
{
}

} // namespace mq
