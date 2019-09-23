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

// actual size: 0x22e Feb 16 2018 test see 5F68F6 - eqmule
// actual size: 0x22d Apr 10 2018 test see 557362 - eqmule
// actual size: 0x229 May 07 2018 test see 6628CA  - eqmule
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
/*0x02c*/ DWORD   ReagentID[0x4];                // ReagentId1-ReagentId4d
/*0x03c*/ DWORD   ReagentCount[0x4];             // ReagentCount1-ReagentCount4
/*0x04c*/ DWORD   NoExpendReagent[0x4];
/*0x05c*/ LONG    CalcIndex;
/*0x060*/ int     NumEffects;
/*0x064*/ DWORD   BookIcon;
/*0x068*/ DWORD   GemIcon;
/*0x06c*/ DWORD   DescriptionIndex;
/*0x070*/ DWORD   ResistAdj;
/*0x074*/ DWORD   Diety;
/*0x078*/ DWORD   spaindex;
/*0x07c*/ DWORD   SpellAnim;
/*0x080*/ DWORD   SpellIcon;
/*0x084*/ DWORD   DurationParticleEffect;
/*0x088*/ DWORD   NPCUsefulness;
/*0x08c*/ DWORD   ID;
/*0x090*/ DWORD   Autocast;                      // SpellID of spell to instacast on caster when current spell lands on target
/*0x094*/ DWORD   Category;                      // Unknown144 from lucy
/*0x098*/ DWORD   Subcategory;                   // Subcat to Category. Unknown145 from lucy
/*0x09c*/ DWORD   Subcategory2;
/*0x0a0*/ DWORD   HateMod;                       // Additional hate
/*0x0a4*/ DWORD   ResistPerLevel;
/*0x0a8*/ DWORD   ResistCap;
/*0x0ac*/ DWORD   EnduranceCost;                 // CA Endurance Cost
/*0x0b0*/ DWORD   ReuseTimerIndex;               // ID of combat timer, i think.
/*0x0b4*/ DWORD   EndurUpkeep;
/*0x0b8*/ DWORD   HateGenerated;                 // Hate override
/*0x0bc*/ DWORD   HitCountType;
/*0x0c0*/ DWORD   HitCount;
/*0x0c4*/ DWORD   ConeStartAngle;
/*0x0c8*/ DWORD   ConeEndAngle;
/*0x0cc*/ DWORD   PvPResistBase;
/*0x0d0*/ DWORD   PvPCalc;
/*0x0d4*/ DWORD   PvPResistCap;
/*0x0d8*/ DWORD   PvPDuration;                   // DurationType for PVP
/*0x0dc*/ DWORD   PvPDurationValue1;             // DurationValue1 for PVP

//*0x0e0*/   DWORD   GlobalGroup; this is gone now, this was only used to check for group type 46 before... uh, hp and mana regen effect spells i think
//see apr 10 test 2018 for reference:
//.text:004DA714 GlobalGroup:
//.text:004DA714                 cmp     dword ptr [eax+0E0h], 46

/*0x0e0*/ DWORD   PCNPCOnlyFlag;                 // no idea
/*0x0e4*/ DWORD   NPCMemCategory;
/*0x0e8*/ DWORD   SpellGroup;
/*0x0ec*/ DWORD   SpellSubGroup;                 // unknown237 on Lucy it is checked at 0x76FE18 in jun 11 2014 and if 0 will ask if we want to replace our spell with a rk. x version
/*0x0f0*/ int     SpellRank;                     // Unknown209 on Lucy jun 11 2014 0x76FEE0 Original = 1 , Rk. II = 5 , Rk. III = 10 , I suppose if they add Rk. IV it will be 15 and so on
/*0x0f4*/ DWORD   SpellClass;                    // Unknown222 from Lucy
/*0x0f8*/ DWORD   SpellSubClass;                 // Unknown223 from Lucy
/*0x0fc*/ DWORD   SpellReqAssociationID;
/*0x100*/ DWORD   CasterRequirementID;
/*0x104*/ DWORD   MaxResist;
/*0x108*/ DWORD   MinResist;
/*0x10c*/ DWORD   MinSpreadTime;
/*0x110*/ DWORD   MaxSpreadTime;
/*0x114*/ DWORD   SpreadRadius;
/*0x118*/ DWORD   BaseEffectsFocusCap;           // song cap, maybe other things?
/*0x11c*/ DWORD   CritChanceOverride;
/*0x120*/ DWORD   MaxTargets;                    // how many targets a spell will affect
/*0x124*/ DWORD   AIValidTargets;
/*0x128*/ DWORD   BaseEffectsFocusOffset;
/*0x12c*/ float   BaseEffectsFocusSlope;
/*0x130*/ CVector2 DistanceModStart;
/*0x138*/ CVector2 DistanceModEnd;
/*0x140*/ float   MinRange;
/*0x144*/ BYTE    NoNPCLOS;                      // NPC skips LOS checks
/*0x145*/ BYTE    Feedbackable;                  // nothing uses this
/*0x146*/ BYTE    Reflectable;
/*0x147*/ BYTE    NoPartialSave;
/*0x148*/ BYTE    NoResist;
/*0x149*/ BYTE    UsesPersistentParticles;
/*0x14a*/ BYTE    SmallTargetsOnly;
/*0x14b*/ bool    DurationWindow;                // 0=Long, 1=Short
/*0x14c*/ BYTE    Uninterruptable;
/*0x14d*/ BYTE    NotStackableDot;
/*0x14e*/ BYTE    Deletable;
/*0x14f*/ BYTE    BypassRegenCheck;
/*0x150*/ BYTE    CanCastInCombat;
/*0x151*/ BYTE    CanCastOutOfCombat;
/*0x152*/ BYTE    NoHealDamageItemMod;           // disable worn focus bonuses
/*0x153*/ BYTE    OnlyDuringFastRegen;
/*0x154*/ BYTE    CastNotStanding;
/*0x155*/ BYTE    CanMGB;
/*0x156*/ bool    NoDisspell;
/*0x157*/ BYTE    AffectInanimate;               // ldon trap spells etc
/*0x158*/ bool    IsSkill;
/*0x159*/ bool    bStacksWithDiscs;              // this was first seen in may 8 2017 test client, its checked if it's false at 0x451790. Ex: The Monk ability 'Drunken Monkey Style' or 'Breather'. see patch notes for that patch...
/*0x15a*/ bool    ShowDoTMessage;
/*0x15b*/ BYTE    ClassLevel[0x24];              // per class., yes there are allocations for 0x24 see 4B5776 in eqgame dated 12 mar 2014
/*0x17f*/ BYTE    LightType;
/*0x180*/ BYTE    SpellType;                     // 0=detrimental, 1=Beneficial, 2=Beneficial, Group Only
/*0x181*/ BYTE    Resist;                        // see   4B0493 in apr 16 2018 exe        //0=un 1=mr 2=fr 3=cr 4=pr 5=dr 6=chromatic 7=prismatic 8=physical(skills,etc) 9=corruption
/*0x182*/ BYTE    TargetType;                    // 03=Group v1, 04=PB AE, 05=Single, 06=Self, 08=Targeted AE, 0e=Pet, 28=AE PC v2, 29=Group v2, 2a=Directional
/*0x183*/ BYTE    CastDifficulty;
/*0x184*/ BYTE    Skill;
/*0x185*/ BYTE    ZoneType;                      // 01=Outdoors, 02=dungeons, ff=Any
/*0x186*/ BYTE    Environment;
/*0x187*/ BYTE    TimeOfDay;                     // 0=any, 1=day only, 2=night only
/*0x188*/ BYTE    CastingAnim;
/*0x189*/ BYTE    AnimVariation;
/*0x18a*/ BYTE    TargetAnim;
/*0x18b*/ BYTE    TravelType;
/*0x18c*/ BYTE    CancelOnSit;
/*0x18d*/ bool    CountdownHeld;
/*0x18e*/ char    Name[0x40];                    // for sure see 557AAA
/*0x1ce*/ char    Target[0x20];
/*0x1ee*/ char    Extra[0x20];                   // This is 'Extra' from Lucy (portal shortnames etc) official = NPC_FILENAME
/*0x20e*/ BYTE    ShowWearOffMessage;
/*0x20f*/ BYTE    NPCChanceofKnowingSpell;       // if this is 0 there is no way an npc can cast this spell...
/*0x210*/ BYTE    SneakAttack;
/*0x211*/ BYTE    NotFocusable;                  // ignores all(?) focus effects
/*0x212*/ BYTE    NoHate;
/*0x213*/ BYTE    StacksWithSelf;
/*0x214*/ BYTE    CannotBeScribed;               // this is used by /outputfile missingspells see 7A57DF in Aug 10 2017 live
/*0x215*/ BYTE    NoBuffBlock;
/*0x216*/ BYTE    Scribable;
/*0x217*/ BYTE    NoStripOnDeath;
/*0x218*/ BYTE    NoRemove;                      // spell can't be clicked off?
/*0x21c*/ int     NoOverwrite;                   // an enum 0 = Can Be overwritten 1 = Can Only be overwritten by itself 2 = Cannot be overwritten, not even by itself
/*0x220*/ DWORD   SpellRecourseType;
/*0x224*/ BYTE    CRC32Marker[4];
/*0x228*/ float   DistanceMod;                   // set to (DistanceModEnd.Y- DistanceModEnd.X) / (DistanceModStart.Y - DistanceModStart.X).
/*0x22c*/

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
// this is EQ_Affect todo: check the new stuff in it
struct [[offsetcomments]] SPELLBUFF
{
/*0x00*/ BYTE      Type;
/*0x01*/ BYTE      Level;                        // casterlevel
/*0x02*/ BYTE      ChargesRemaining;
/*0x03*/ char      DamageShield;                 // Activatable
/*0x04*/ float     Modifier;                     // Bard song modifier, 1.0 is default BaseDmgMod
/*0x08*/ int       SpellID;                      // -1 or 0 for no spell..
/*0x0c*/ DWORD     Duration;
/*0x10*/ DWORD     MaxDuration;
/*0x14*/ DWORD     Duration3;
/*0x18*/ EqGuid    CasterGuid;
/*0x20*/ DWORD     HitCount;
/*0x24*/ float     Y;                            // Referenced by SPA 441 (distance removal)
/*0x28*/ float     X;
/*0x2c*/ float     Z;
/*0x30*/ UINT      Flags;
/*0x34*/ SlotData  SlotData[NUM_SLOTDATA];       // used for book keeping of various effects (debuff counter, rune/vie damage remaining)
/*0x64*/ DWORD     Unknown0x64;
/*0x68*/

	// Currently necessary because of MQ2DataTypes
	SPELLBUFF() { ZeroMemory(this, sizeof(SPELLBUFF)); }
};
using PSPELLBUFF [[deprecated]] = SPELLBUFF *;

} // namespace eqlib
