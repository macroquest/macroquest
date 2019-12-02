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
enum eEQSPA
{
	SPA_HP                             = 0,
	SPA_AC                             = 1,
	SPA_MOVEMENTRATE                   = 3,
	SPA_CHA                            = 10,
	SPA_HASTE                          = 11,
	SPA_MANA                           = 15,
	SPA_VAMPIRISM                      = 45,
	SPA_LEVITATION                     = 57,
	SPA_CHANGE_FORM                    = 58,
	SPA_EYE_OF_ZOMM                    = 67,
	SPA_MAGNIFICATION                  = 87,
	SPA_PLAYERSIZE                     = 89,
	SPA_SUMMONCORPSE                   = 91,
	SPA_BARDOVERHASTE                  = 98,
	SPA_HEALDOT                        = 100,
	SPA_COMPLETEHEAL                   = 101,
	SPA_SUMMON_MOUNT                   = 113,
	SPA_SPELLDAMAGE                    = 124,
	SPA_HEALING                        = 125,
	SPA_REAGENTCHANCE                  = 131,
	SPA_SPELLMANACOST                  = 132,
	SPA_STACKING_BLOCK                 = 148,
	SPA_MIRROR                         = 156,
	SPA_SPELL_GUARD                    = 161,
	SPA_MELEE_GUARD                    = 162,
	SPA_DOUBLEATTACK                   = 177,
	SPA_STUNRESIST                     = 195,
	SPA_PROCMOD                        = 200,
	SPA_DIVINEREZ                      = 232,
	SPA_METABOLISM                     = 233,
	SPA_NOSPELL                        = 254,
	SPA_TRIPLEBACKSTAB                 = 258,
	SPA_INCREASE_CASTING_LEVEL         = 272,
	SPA_DOTCRIT                        = 273,
	SPA_HEALCRIT                       = 274,
	SPA_MENDCRIT                       = 275,
	SPA_FLURRY                         = 279,
	SPA_PETFLURRY                      = 280,
	SPA_SPELLCRITCHANCE                = 294,
	SPA_INCSPELLDMG                    = 296,
	SPA_DAMAGECRITMOD                  = 302,
	SPA_SHIELDBLOCKCHANCE              = 320,
	SPA_NO_MOVE_HP                     = 334,
	SPA_MANA_IGNITE                    = 401,
	SPA_ENDURANCE_IGNITE               = 402,
	SPA_LIMIT_HP                       = 408,
	SPA_LIMIT_MANA                     = 409,
	SPA_LIMIT_ENDURANCE                = 410,
	SPA_AC2                            = 416,
	SPA_MANA2                          = 417,
	SPA_IMPROVED_TAUNT                 = 444,
	SPA_DOT_GUARD                      = 450,
	SPA_MELEE_THRESHOLD_GUARD          = 451,
	SPA_SPELL_THRESHOLD_GUARD          = 452,
	SPA_TRIGGER_BEST_SPELL_GROUP       = 470,
	SPA_SPELLDAMAGETAKEN               = 483,
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
