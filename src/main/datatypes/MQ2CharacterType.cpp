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

#include "pch.h"
#include "MQ2DataTypes.h"

#include "MQ2Mercenaries.h"

using namespace mq;
using namespace mq::datatypes;

enum class CharacterMembers
{
	CountSongs,
	MaxBuffSlots,
	Exp,
	Spawn,
	Dar,
	AAExp,
	AAPoints,
	CurrentHPs,
	MaxHPs,
	HPRegen,
	PctHPs,
	CurrentMana,
	MaxMana,
	ManaRegen,
	PctMana,
	Buff,
	Song,
	Book,
	Skill,
	Ability,
	Cash,
	CashBank,
	PlatinumShared,
	Grouped,
	HPBonus,
	ManaBonus,
	GukEarned,
	MMEarned,
	RujEarned,
	TakEarned,
	MirEarned,
	LDoNPoints,
	CurrentFavor,
	CareerFavor,
	Endurance,
	Inventory,
	Bank,
	Combat,
	FreeInventory,
	Gem,
	SpellReady,
	Drunk,
	STR,
	STA,
	CHA,
	DEX,
	INT,
	AGI,
	WIS,
	svMagic,
	svFire,
	svCold,
	svPoison,
	svDisease,
	Hunger,
	Thirst,
	BaseSTR,
	BaseSTA,
	BaseCHA,
	BaseDEX,
	BaseINT,
	BaseAGI,
	BaseWIS,
	PracticePoints,
	PctExp,
	PctAAExp,
	Moving,
	AbilityReady,
	PetBuff,
	Platinum,
	Gold,
	Silver,
	Copper,
	PlatinumBank,
	GoldBank,
	SilverBank,
	CopperBank,
	Stunned,
	RangedReady,
	AltTimerReady,
	MaxEndurance,
	PctEndurance,
	AltAbility,
	AltAbilityReady,
	AltAbilityTimer,
	CombatAbility,
	CombatAbilityTimer,
	LargestFreeInventory,
	TargetOfTarget,
	RaidAssistTarget,
	GroupAssistTarget,
	RaidMarkNPC,
	GroupMarkNPC,
	CountBuffs,
	LanguageSkill,
	EnduranceBonus,
	CombatEffectsBonus,
	ShieldingBonus,
	SpellShieldBonus,
	AvoidanceBonus,
	AccuracyBonus,
	StunResistBonus,
	StrikeThroughBonus,
	AttackBonus,
	HPRegenBonus,
	ManaRegenBonus,
	DamageShieldBonus,
	DoTShieldBonus,
	AttackSpeed,
	GroupList,
	AmIGroupLeader,
	CurrentEndurance,
	EnduranceRegen,
	FreeBuffSlots,
	CurrentWeight,
	AAPointsSpent,
	AAPointsTotal,
	TributeActive,
	CombatAbilityReady,
	Running,
	GroupSize,
	TributeTimer,
	RadiantCrystals,
	EbonCrystals,
	Shrouded,
	AutoFire,
	Language,
	Aura,
	LAMarkNPC,
	LANPCHealth,
	LADelegateMA,
	LADelegateMarkNPC,
	LAInspectBuffs,
	LASpellAwareness,
	LAOffenseEnhancement,
	LAManaEnhancement,
	LAHealthEnhancement,
	LAHealthRegen,
	LAFindPathPC,
	LAHoTT,
	ActiveFavorCost,
	CombatState,
	svCorruption,
	svPrismatic,
	svChromatic,
	Doubloons,
	Orux,
	Phosphenes,
	Phosphites,
	Fellowship,
	Downtime,
	DamageShieldMitigationBonus,
	HeroicSTRBonus,
	HeroicINTBonus,
	HeroicWISBonus,
	HeroicAGIBonus,
	HeroicDEXBonus,
	HeroicSTABonus,
	HeroicCHABonus,
	HealAmountBonus,
	SpellDamageBonus,
	ClairvoyanceBonus,
	EnduranceRegenBonus,
	TotalCounters,
	Faycites,
	Chronobines,
	Mercenary,
	XTarget,
	Haste,
	MercenaryStance,
	SkillCap,
	GemTimer,
	HaveExpansion,
	PctAggro,
	SecondaryPctAggro,
	SecondaryAggroPlayer,
	AggroLock,
	ZoneBound,
	ZoneBoundX,
	ZoneBoundY,
	ZoneBoundZ,
	PctMercAAExp,
	MercAAExp,
	Subscription,
	AAPointsAssigned,
	AltCurrency,
	ActiveDisc,
	Commemoratives,
	Nobles,
	Zoning,
	InInstance,
	Instance,
	MercListInfo,
	UseAdvancedLooting,
	Fists,
	EnergyCrystals,
	PiecesofEight,
	SilverTokens,
	GoldTokens,
	McKenzie,
	Bayle,
	Reclamation,
	Brellium,
	Motes,
	RebellionChits,
	DiamondCoins,
	BronzeFiats,
	Voucher,
	VeliumShards,
	CrystallizedFear,
	ShadowStones,
	DreadStones,
	MarksOfValor,
	MedalsOfHeroism,
	RemnantOfTranquility,
	BifurcatedCoin,
	AdoptiveCoin,
	SathirsTradeGems,
	AncientSebilisianCoins,
	BathezidTradeGems,
	AncientDraconicCoin,
	FetterredIfritCoins,
	EntwinedDjinnCoins,
	CrystallizedLuck,
	FroststoneDucat,
	WarlordsSymbol,
	OverseerTetradrachm,
	SpellInCooldown,
	Slowed,
	Rooted,
	Mezzed,
	Crippled,
	Maloed,
	Tashed,
	Snared,
	Hasted,
	Aego,
	Skin,
	Focus,
	Regen,
	Symbol,
	Clarity,
	Pred,
	Strength,
	Brells,
	SV,
	SE,
	HybridHP,
	Growth,
	Shining,
	Beneficial,
	DSed,
	RevDSed,
	Charmed,
	CursorPlatinum,
	CursorGold,
	CursorSilver,
	CursorCopper,
	Diseased,
	Poisoned,
	Cursed,
	Corrupted,
	Krono,
	XTargetSlots,
	AssistComplete,
	ItemReady,
	NumGems,
	Vitality,
	PctVitality,
	AAVitality,
	PctAAVitality,
	GuildID,
	ExpansionFlags,
	SPA,
	BoundLocation,
	SkillBase,
	Name,
	AutoSkill,
	CursorKrono,
	BardSongPlaying,
	XTAggroCount,
	MercAAPoints,
	MercAAPointsSpent,
	PctExpToAA,
	XTHaterCount,
	CountersDisease,
	CountersPoison,
	CountersCurse,
	CountersCorruption,
	Bandolier,
	LCK,
	Feared,
	Silenced,
	Invulnerable,
	Dotted,
	BlockedBuff,
	BlockedPetBuff,
	LastZoned,
	Origin,
	SubscriptionDays,
	Spell,
	ParcelStatus,
	CanMount,
	SpellRankCap,
	AbilityTimer,
	CastTimeLeft,
};

enum class CharacterMethods
{
	Stand,
	Sit,
	Dismount,
	StopCast,
};

MQ2CharacterType::MQ2CharacterType() : MQ2Type("character")
{
	ScopedTypeMember(CharacterMembers, Exp);
	ScopedTypeMember(CharacterMembers, Spawn);
	ScopedTypeMember(CharacterMembers, Dar);
	ScopedTypeMember(CharacterMembers, AAExp);
	ScopedTypeMember(CharacterMembers, AAPoints);
	ScopedTypeMember(CharacterMembers, CurrentHPs);
	ScopedTypeMember(CharacterMembers, MaxHPs);
	ScopedTypeMember(CharacterMembers, HPRegen);
	ScopedTypeMember(CharacterMembers, PctHPs);
	ScopedTypeMember(CharacterMembers, CurrentMana);
	ScopedTypeMember(CharacterMembers, MaxMana);
	ScopedTypeMember(CharacterMembers, ManaRegen);
	ScopedTypeMember(CharacterMembers, PctMana);
	ScopedTypeMember(CharacterMembers, Buff);
	ScopedTypeMember(CharacterMembers, Song);
	ScopedTypeMember(CharacterMembers, Book);
	ScopedTypeMember(CharacterMembers, Skill);
	ScopedTypeMember(CharacterMembers, Ability);
	ScopedTypeMember(CharacterMembers, Cash);
	ScopedTypeMember(CharacterMembers, CashBank);
	ScopedTypeMember(CharacterMembers, PlatinumShared);
	ScopedTypeMember(CharacterMembers, Grouped);
	ScopedTypeMember(CharacterMembers, HPBonus);
	ScopedTypeMember(CharacterMembers, ManaBonus);
	ScopedTypeMember(CharacterMembers, GukEarned);
	ScopedTypeMember(CharacterMembers, MMEarned);
	ScopedTypeMember(CharacterMembers, RujEarned);
	ScopedTypeMember(CharacterMembers, TakEarned);
	ScopedTypeMember(CharacterMembers, MirEarned);
	ScopedTypeMember(CharacterMembers, LDoNPoints);
	ScopedTypeMember(CharacterMembers, CurrentFavor);
	ScopedTypeMember(CharacterMembers, CareerFavor);
	ScopedTypeMember(CharacterMembers, Endurance);
	ScopedTypeMember(CharacterMembers, Inventory);
	ScopedTypeMember(CharacterMembers, Bank);
	ScopedTypeMember(CharacterMembers, Combat);
	ScopedTypeMember(CharacterMembers, FreeInventory);
	ScopedTypeMember(CharacterMembers, Gem);
	ScopedTypeMember(CharacterMembers, SpellReady);
	ScopedTypeMember(CharacterMembers, Drunk);
	ScopedTypeMember(CharacterMembers, STR);
	ScopedTypeMember(CharacterMembers, STA);
	ScopedTypeMember(CharacterMembers, CHA);
	ScopedTypeMember(CharacterMembers, DEX);
	ScopedTypeMember(CharacterMembers, INT);
	ScopedTypeMember(CharacterMembers, AGI);
	ScopedTypeMember(CharacterMembers, WIS);
	ScopedTypeMember(CharacterMembers, svMagic);
	ScopedTypeMember(CharacterMembers, svFire);
	ScopedTypeMember(CharacterMembers, svCold);
	ScopedTypeMember(CharacterMembers, svPoison);
	ScopedTypeMember(CharacterMembers, svDisease);
	ScopedTypeMember(CharacterMembers, Hunger);
	ScopedTypeMember(CharacterMembers, Thirst);
	ScopedTypeMember(CharacterMembers, BaseSTR);
	ScopedTypeMember(CharacterMembers, BaseSTA);
	ScopedTypeMember(CharacterMembers, BaseCHA);
	ScopedTypeMember(CharacterMembers, BaseDEX);
	ScopedTypeMember(CharacterMembers, BaseINT);
	ScopedTypeMember(CharacterMembers, BaseAGI);
	ScopedTypeMember(CharacterMembers, BaseWIS);
	ScopedTypeMember(CharacterMembers, PracticePoints);
	ScopedTypeMember(CharacterMembers, PctExp);
	ScopedTypeMember(CharacterMembers, PctAAExp);
	ScopedTypeMember(CharacterMembers, Moving);
	ScopedTypeMember(CharacterMembers, AbilityReady);
	ScopedTypeMember(CharacterMembers, PetBuff);
	ScopedTypeMember(CharacterMembers, Platinum);
	ScopedTypeMember(CharacterMembers, Gold);
	ScopedTypeMember(CharacterMembers, Silver);
	ScopedTypeMember(CharacterMembers, Copper);
	ScopedTypeMember(CharacterMembers, PlatinumBank);
	ScopedTypeMember(CharacterMembers, GoldBank);
	ScopedTypeMember(CharacterMembers, SilverBank);
	ScopedTypeMember(CharacterMembers, CopperBank);
	ScopedTypeMember(CharacterMembers, Stunned);
	ScopedTypeMember(CharacterMembers, RangedReady);
	ScopedTypeMember(CharacterMembers, AltTimerReady);
	ScopedTypeMember(CharacterMembers, MaxEndurance);
	ScopedTypeMember(CharacterMembers, PctEndurance);
	ScopedTypeMember(CharacterMembers, AltAbility);
	ScopedTypeMember(CharacterMembers, AltAbilityReady);
	ScopedTypeMember(CharacterMembers, AltAbilityTimer);
	ScopedTypeMember(CharacterMembers, CombatAbility);
	ScopedTypeMember(CharacterMembers, CombatAbilityTimer);
	ScopedTypeMember(CharacterMembers, LargestFreeInventory);
	ScopedTypeMember(CharacterMembers, TargetOfTarget);
	ScopedTypeMember(CharacterMembers, RaidAssistTarget);
	ScopedTypeMember(CharacterMembers, GroupAssistTarget);
	ScopedTypeMember(CharacterMembers, RaidMarkNPC);
	ScopedTypeMember(CharacterMembers, GroupMarkNPC);
	ScopedTypeMember(CharacterMembers, CountBuffs);
	ScopedTypeMember(CharacterMembers, LanguageSkill);
	ScopedTypeMember(CharacterMembers, EnduranceBonus);
	ScopedTypeMember(CharacterMembers, CombatEffectsBonus);
	ScopedTypeMember(CharacterMembers, ShieldingBonus);
	ScopedTypeMember(CharacterMembers, SpellShieldBonus);
	ScopedTypeMember(CharacterMembers, AvoidanceBonus);
	ScopedTypeMember(CharacterMembers, AccuracyBonus);
	ScopedTypeMember(CharacterMembers, StunResistBonus);
	ScopedTypeMember(CharacterMembers, StrikeThroughBonus);
	ScopedTypeMember(CharacterMembers, AttackBonus);
	ScopedTypeMember(CharacterMembers, HPRegenBonus);
	ScopedTypeMember(CharacterMembers, ManaRegenBonus);
	ScopedTypeMember(CharacterMembers, DamageShieldBonus);
	ScopedTypeMember(CharacterMembers, DoTShieldBonus);
	ScopedTypeMember(CharacterMembers, AttackSpeed);
	ScopedTypeMember(CharacterMembers, GroupList);
	ScopedTypeMember(CharacterMembers, AmIGroupLeader);
	ScopedTypeMember(CharacterMembers, CurrentEndurance);
	ScopedTypeMember(CharacterMembers, EnduranceRegen);
	ScopedTypeMember(CharacterMembers, FreeBuffSlots);
	ScopedTypeMember(CharacterMembers, CurrentWeight);
	ScopedTypeMember(CharacterMembers, AAPointsSpent);
	ScopedTypeMember(CharacterMembers, AAPointsTotal);
	ScopedTypeMember(CharacterMembers, TributeActive);
	ScopedTypeMember(CharacterMembers, CombatAbilityReady);
	ScopedTypeMember(CharacterMembers, Running);
	ScopedTypeMember(CharacterMembers, GroupSize);
	ScopedTypeMember(CharacterMembers, TributeTimer);
	ScopedTypeMember(CharacterMembers, RadiantCrystals);
	ScopedTypeMember(CharacterMembers, EbonCrystals);
	ScopedTypeMember(CharacterMembers, Shrouded);
	ScopedTypeMember(CharacterMembers, AutoFire);
	ScopedTypeMember(CharacterMembers, Language);
	ScopedTypeMember(CharacterMembers, Aura);
	ScopedTypeMember(CharacterMembers, LAMarkNPC);
	ScopedTypeMember(CharacterMembers, LANPCHealth);
	ScopedTypeMember(CharacterMembers, LADelegateMA);
	ScopedTypeMember(CharacterMembers, LADelegateMarkNPC);
	ScopedTypeMember(CharacterMembers, LAInspectBuffs);
	ScopedTypeMember(CharacterMembers, LASpellAwareness);
	ScopedTypeMember(CharacterMembers, LAOffenseEnhancement);
	ScopedTypeMember(CharacterMembers, LAManaEnhancement);
	ScopedTypeMember(CharacterMembers, LAHealthEnhancement);
	ScopedTypeMember(CharacterMembers, LAHealthRegen);
	ScopedTypeMember(CharacterMembers, LAFindPathPC);
	ScopedTypeMember(CharacterMembers, LAHoTT);
	ScopedTypeMember(CharacterMembers, ActiveFavorCost);
	ScopedTypeMember(CharacterMembers, CombatState);
	ScopedTypeMember(CharacterMembers, svCorruption);
	ScopedTypeMember(CharacterMembers, svPrismatic);
	ScopedTypeMember(CharacterMembers, svChromatic);
	ScopedTypeMember(CharacterMembers, Doubloons);
	ScopedTypeMember(CharacterMembers, Orux);
	ScopedTypeMember(CharacterMembers, Phosphenes);
	ScopedTypeMember(CharacterMembers, Phosphites);
	ScopedTypeMember(CharacterMembers, Fellowship);
	ScopedTypeMember(CharacterMembers, Downtime);
	ScopedTypeMember(CharacterMembers, DamageShieldMitigationBonus);
	ScopedTypeMember(CharacterMembers, HeroicSTRBonus);
	ScopedTypeMember(CharacterMembers, HeroicINTBonus);
	ScopedTypeMember(CharacterMembers, HeroicWISBonus);
	ScopedTypeMember(CharacterMembers, HeroicAGIBonus);
	ScopedTypeMember(CharacterMembers, HeroicDEXBonus);
	ScopedTypeMember(CharacterMembers, HeroicSTABonus);
	ScopedTypeMember(CharacterMembers, HeroicCHABonus);
	ScopedTypeMember(CharacterMembers, HealAmountBonus);
	ScopedTypeMember(CharacterMembers, SpellDamageBonus);
	ScopedTypeMember(CharacterMembers, ClairvoyanceBonus);
	ScopedTypeMember(CharacterMembers, EnduranceRegenBonus);
	ScopedTypeMember(CharacterMembers, TotalCounters);
	ScopedTypeMember(CharacterMembers, Faycites);
	ScopedTypeMember(CharacterMembers, Chronobines);
	ScopedTypeMember(CharacterMembers, Mercenary);
	ScopedTypeMember(CharacterMembers, XTarget);
	ScopedTypeMember(CharacterMembers, Haste);
	ScopedTypeMember(CharacterMembers, MercenaryStance);
	ScopedTypeMember(CharacterMembers, SkillCap);
	ScopedTypeMember(CharacterMembers, GemTimer);
	ScopedTypeMember(CharacterMembers, HaveExpansion);
	ScopedTypeMember(CharacterMembers, PctAggro);
	ScopedTypeMember(CharacterMembers, SecondaryPctAggro);
	ScopedTypeMember(CharacterMembers, SecondaryAggroPlayer);
	ScopedTypeMember(CharacterMembers, AggroLock);
	ScopedTypeMember(CharacterMembers, ZoneBound);
	ScopedTypeMember(CharacterMembers, ZoneBoundX);
	ScopedTypeMember(CharacterMembers, ZoneBoundY);
	ScopedTypeMember(CharacterMembers, ZoneBoundZ);
	ScopedTypeMember(CharacterMembers, PctMercAAExp);
	ScopedTypeMember(CharacterMembers, MercAAExp);
	ScopedTypeMember(CharacterMembers, Subscription);
	ScopedTypeMember(CharacterMembers, AAPointsAssigned);
	ScopedTypeMember(CharacterMembers, AltCurrency);
	ScopedTypeMember(CharacterMembers, ActiveDisc);
	ScopedTypeMember(CharacterMembers, CountSongs);
	ScopedTypeMember(CharacterMembers, MaxBuffSlots);
	ScopedTypeMember(CharacterMembers, Commemoratives);
	ScopedTypeMember(CharacterMembers, Nobles);
	ScopedTypeMember(CharacterMembers, Zoning);
	ScopedTypeMember(CharacterMembers, InInstance);
	ScopedTypeMember(CharacterMembers, Instance);
	ScopedTypeMember(CharacterMembers, MercListInfo);
	ScopedTypeMember(CharacterMembers, UseAdvancedLooting);
	ScopedTypeMember(CharacterMembers, Fists);
	ScopedTypeMember(CharacterMembers, EnergyCrystals);
	ScopedTypeMember(CharacterMembers, PiecesofEight);
	ScopedTypeMember(CharacterMembers, SilverTokens);
	ScopedTypeMember(CharacterMembers, GoldTokens);
	ScopedTypeMember(CharacterMembers, McKenzie);
	ScopedTypeMember(CharacterMembers, Bayle);
	ScopedTypeMember(CharacterMembers, Reclamation);
	ScopedTypeMember(CharacterMembers, Brellium);
	ScopedTypeMember(CharacterMembers, Motes);
	ScopedTypeMember(CharacterMembers, RebellionChits);
	ScopedTypeMember(CharacterMembers, DiamondCoins);
	ScopedTypeMember(CharacterMembers, BronzeFiats);
	ScopedTypeMember(CharacterMembers, Voucher);
	ScopedTypeMember(CharacterMembers, VeliumShards);
	ScopedTypeMember(CharacterMembers, CrystallizedFear);
	ScopedTypeMember(CharacterMembers, ShadowStones);
	ScopedTypeMember(CharacterMembers, DreadStones);
	ScopedTypeMember(CharacterMembers, MarksOfValor);
	ScopedTypeMember(CharacterMembers, MedalsOfHeroism);
	ScopedTypeMember(CharacterMembers, RemnantOfTranquility);
	ScopedTypeMember(CharacterMembers, BifurcatedCoin);
	ScopedTypeMember(CharacterMembers, AdoptiveCoin);
	ScopedTypeMember(CharacterMembers, SathirsTradeGems);
	ScopedTypeMember(CharacterMembers, AncientSebilisianCoins);
	ScopedTypeMember(CharacterMembers, BathezidTradeGems);
	ScopedTypeMember(CharacterMembers, AncientDraconicCoin);
	ScopedTypeMember(CharacterMembers, FetterredIfritCoins);
	ScopedTypeMember(CharacterMembers, EntwinedDjinnCoins);
	ScopedTypeMember(CharacterMembers, CrystallizedLuck);
	ScopedTypeMember(CharacterMembers, FroststoneDucat);
	ScopedTypeMember(CharacterMembers, WarlordsSymbol);
	ScopedTypeMember(CharacterMembers, OverseerTetradrachm);
	ScopedTypeMember(CharacterMembers, SpellInCooldown);
	ScopedTypeMember(CharacterMembers, Slowed);
	ScopedTypeMember(CharacterMembers, Rooted);
	ScopedTypeMember(CharacterMembers, Mezzed);
	ScopedTypeMember(CharacterMembers, Crippled);
	ScopedTypeMember(CharacterMembers, Maloed);
	ScopedTypeMember(CharacterMembers, Tashed);
	ScopedTypeMember(CharacterMembers, Snared);
	ScopedTypeMember(CharacterMembers, Hasted);
	ScopedTypeMember(CharacterMembers, Aego);
	ScopedTypeMember(CharacterMembers, Skin);
	ScopedTypeMember(CharacterMembers, Focus);
	ScopedTypeMember(CharacterMembers, Regen);
	ScopedTypeMember(CharacterMembers, Symbol);
	ScopedTypeMember(CharacterMembers, Clarity);
	ScopedTypeMember(CharacterMembers, Pred);
	ScopedTypeMember(CharacterMembers, Strength);
	ScopedTypeMember(CharacterMembers, Brells);
	ScopedTypeMember(CharacterMembers, SV);
	ScopedTypeMember(CharacterMembers, SE);
	ScopedTypeMember(CharacterMembers, HybridHP);
	ScopedTypeMember(CharacterMembers, Growth);
	ScopedTypeMember(CharacterMembers, Shining);
	ScopedTypeMember(CharacterMembers, Beneficial);
	ScopedTypeMember(CharacterMembers, DSed);
	ScopedTypeMember(CharacterMembers, RevDSed);
	ScopedTypeMember(CharacterMembers, Charmed);
	ScopedTypeMember(CharacterMembers, CursorPlatinum);
	ScopedTypeMember(CharacterMembers, CursorGold);
	ScopedTypeMember(CharacterMembers, CursorSilver);
	ScopedTypeMember(CharacterMembers, CursorCopper);
	ScopedTypeMember(CharacterMembers, Diseased);
	ScopedTypeMember(CharacterMembers, Poisoned);
	ScopedTypeMember(CharacterMembers, Cursed);
	ScopedTypeMember(CharacterMembers, Corrupted);
	ScopedTypeMember(CharacterMembers, Krono);
	ScopedTypeMember(CharacterMembers, XTargetSlots);
	ScopedTypeMember(CharacterMembers, AssistComplete);
	ScopedTypeMember(CharacterMembers, ItemReady);
	ScopedTypeMember(CharacterMembers, NumGems);
	ScopedTypeMember(CharacterMembers, Vitality);
	ScopedTypeMember(CharacterMembers, PctVitality);
	ScopedTypeMember(CharacterMembers, AAVitality);
	ScopedTypeMember(CharacterMembers, PctAAVitality);
	ScopedTypeMember(CharacterMembers, GuildID);
	ScopedTypeMember(CharacterMembers, ExpansionFlags);
	ScopedTypeMember(CharacterMembers, SPA);
	ScopedTypeMember(CharacterMembers, BoundLocation);
	ScopedTypeMember(CharacterMembers, SkillBase);
	ScopedTypeMember(CharacterMembers, Name);
	ScopedTypeMember(CharacterMembers, AutoSkill);
	ScopedTypeMember(CharacterMembers, CursorKrono);
	ScopedTypeMember(CharacterMembers, BardSongPlaying);
	ScopedTypeMember(CharacterMembers, XTAggroCount);
	ScopedTypeMember(CharacterMembers, MercAAPoints);
	ScopedTypeMember(CharacterMembers, MercAAPointsSpent);
	ScopedTypeMember(CharacterMembers, PctExpToAA);
	ScopedTypeMember(CharacterMembers, XTHaterCount);
	ScopedTypeMember(CharacterMembers, CountersDisease);
	ScopedTypeMember(CharacterMembers, CountersPoison);
	ScopedTypeMember(CharacterMembers, CountersCurse);
	ScopedTypeMember(CharacterMembers, CountersCorruption);
	ScopedTypeMember(CharacterMembers, Bandolier);
	ScopedTypeMember(CharacterMembers, LCK);
	ScopedTypeMember(CharacterMembers, Feared);
	ScopedTypeMember(CharacterMembers, Silenced);
	ScopedTypeMember(CharacterMembers, Invulnerable);
	ScopedTypeMember(CharacterMembers, Dotted);
	ScopedTypeMember(CharacterMembers, BlockedBuff);
	ScopedTypeMember(CharacterMembers, BlockedPetBuff);
	ScopedTypeMember(CharacterMembers, LastZoned);
	ScopedTypeMember(CharacterMembers, Origin);
	ScopedTypeMember(CharacterMembers, SubscriptionDays);
	ScopedTypeMember(CharacterMembers, Spell);
	ScopedTypeMember(CharacterMembers, ParcelStatus);
	ScopedTypeMember(CharacterMembers, CanMount);
	ScopedTypeMember(CharacterMembers, SpellRankCap);
	ScopedTypeMember(CharacterMembers, AbilityTimer);
	ScopedTypeMember(CharacterMembers, CastTimeLeft);

	ScopedTypeMethod(CharacterMethods, Stand);
	ScopedTypeMethod(CharacterMethods, Sit);
	ScopedTypeMethod(CharacterMethods, Dismount);
	ScopedTypeMethod(CharacterMethods, StopCast);
}

bool MQ2CharacterType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	CHARINFO* pChar = static_cast<CHARINFO*>(pCharData);
	if (!pChar)
		return false;

	PcProfile* pProfile = GetPcProfile();
	if (!pProfile)
		return false;

	PlayerClient* pPlayerClient = reinterpret_cast<PlayerClient*>(pChar->pSpawn);

	//------------------------------------------------------------------------
	// methods

	if (MQTypeMember* pMethod = MQ2CharacterType::FindMethod(Member))
	{
		switch (static_cast<CharacterMethods>(pMethod->ID))
		{
		case CharacterMethods::Stand:
			pEverQuest->InterpretCmd(pPlayerClient, "/stand on");
			return true;

		case CharacterMethods::Sit:
			pEverQuest->InterpretCmd(pPlayerClient, "/sit on");
			return true;

		case CharacterMethods::Dismount:
			pEverQuest->InterpretCmd(pPlayerClient, "/dismount");
			return true;

		case CharacterMethods::StopCast:
			pEverQuest->InterpretCmd(pPlayerClient, "/stopcast");
			return true;

		default: break;
		}

		return false;
	}

	MQTypeMember* pMember = MQ2CharacterType::FindMember(Member);
	if (!pMember)
	{
		// call into spawn type using our own spawn
		MQVarPtr data;
		data.Ptr = pLocalPlayer;

		return pSpawnType->GetMember(data, Member, Index, Dest);
	}

	switch (static_cast<CharacterMembers>(pMember->ID))
	{
	case CharacterMembers::Name:
		strcpy_s(DataTypeTemp, ((SPAWNINFO*)pLocalPlayer)->Name);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case CharacterMembers::Origin:
		if (pChar->StartingCity > 0 && pChar->StartingCity < MAX_ZONES)
		{
			Dest.Type = pZoneType;
			Dest.Ptr = pWorldData->ZoneArray[pChar->StartingCity];
			return true;
		}
		return false;

	case CharacterMembers::SubscriptionDays:
		Dest.Int = pChar->SubscriptionDays;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Exp:
		Dest.Int64 = pChar->Exp;
		Dest.Type = pInt64Type;
		return true;

	case CharacterMembers::PctExp:
		Dest.Float = (float)pChar->Exp / 1000.0f;
		Dest.Type = pFloatType;
		return true;

	case CharacterMembers::PctExpToAA:
		Dest.Int = (int)pChar->PercentEXPtoAA;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::PctAAExp:
		Dest.Float = (float)pChar->AAExp / 1000.0f;
		Dest.Type = pFloatType;
		return true;

	case CharacterMembers::Vitality:
		Dest.Int64 = pChar->Vitality;
		Dest.Type = pInt64Type;
		return true;

	case CharacterMembers::PctVitality: {
		Dest.Float = 0;
		Dest.Type = pFloatType;
		int64_t vitality = pChar->Vitality;
		int64_t cap = pInventoryWnd->VitalityCap;
		if (vitality > cap)
			vitality = cap;
		if (cap > 0)
			Dest.Float = (float)vitality * 100 / cap;
		return true;
	}

	case CharacterMembers::AAVitality:
		Dest.Int = pChar->AAVitality;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::PctAAVitality: {
		Dest.Float = 0;
		Dest.Type = pFloatType;
		int aavitality = pChar->AAVitality;
		int aacap = pInventoryWnd->AAVitalityCap;
		if (aavitality > aacap)
			aavitality = aacap;
		if (aacap > 0)
			Dest.Float = (float)aavitality * 100 / aacap;
		return true;
	}

	case CharacterMembers::Spawn:
		Dest.Ptr = pLocalPlayer;
		Dest.Type = pSpawnType;
		return true;

	case CharacterMembers::CurrentHPs:
		Dest.DWord = GetCurHPS();
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::MaxHPs:
		Dest.Type = pIntType;
		Dest.Int = GetMaxHPS();
		return true;

	case CharacterMembers::PctHPs:
		Dest.Type = pIntType;
		Dest.Int = GetMaxHPS() == 0 ? 0 : GetCurHPS() * 100 / GetMaxHPS();
		return true;

	case CharacterMembers::CurrentMana:
		Dest.DWord = pProfile->Mana;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::MaxMana:
		Dest.DWord = GetMaxMana();
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::PctMana:
		if (int maxMana = GetMaxMana())
			Dest.DWord = pProfile->Mana * 100 / maxMana;
		else
			Dest.DWord = 0;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CountBuffs:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		for (const auto& buff : pProfile->Buff)
		{
			if (buff.SpellID > 0)
			{
				Dest.DWord++;
			}
		}
		return true;

	case CharacterMembers::CountSongs:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		for (const auto& buff : pProfile->ShortBuff)
		{
			if (buff.SpellID > 0)
			{
				Dest.DWord++;
			}
		}
		return true;

	case CharacterMembers::BlockedPetBuff:
	case CharacterMembers::BlockedBuff:
		Dest.Type = pSpellType;
		if (!Index[0])
			return false;

		// TODO:  Move this into a function for both BlockedPetBuff and BlockedBuff
		if (CHARINFONEW* pCharnew = reinterpret_cast<CHARINFONEW*>(GetCharInfo()))
		{
			int iMaxBlockedSpells = (static_cast<CharacterMembers>(pMember->ID) == CharacterMembers::BlockedBuff ? MAX_BLOCKED_SPELLS : MAX_BLOCKED_SPELLS_PET);
			if (IsNumber(Index))
			{
				int nBuff = GetIntFromString(Index, iMaxBlockedSpells + 2) - 1;
				if (nBuff < 0)
					nBuff = 0;
				if (nBuff > iMaxBlockedSpells)
					return false;

				if (int spellId = (static_cast<CharacterMembers>(pMember->ID) == CharacterMembers::BlockedBuff) ? pCharnew->BlockedSpell[nBuff] : pCharnew->BlockedPetSpell[nBuff])
				{
					if (SPELL* pSpell = GetSpellByID(spellId))
					{
						Dest.Ptr = pSpell;
						return true;
					}
				}
			}
			else
			{
				for (auto i = 0; i < iMaxBlockedSpells; ++i)
				{
					if (int spellId = (static_cast<CharacterMembers>(pMember->ID) == CharacterMembers::BlockedBuff) ? pCharnew->BlockedSpell[i] : pCharnew->BlockedPetSpell[i])
					{
						if (SPELL* pSpell = GetSpellByID(spellId))
						{
							if (!_strnicmp(Index, pSpell->Name, strlen(Index)))
							{
								Dest.Ptr = pSpell;
								return true;
							}
						}
					}
				}
			}
		}
		return false;

	// TODO:  Move this to a function for both Buff and Song since code is identical except for Short vs Long Buff.
	case CharacterMembers::Buff:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_BuffWnd;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nBuff = GetIntFromString(Index, 0) - 1;
			if (nBuff < 0 || nBuff > NUM_LONG_BUFFS || pProfile->Buff[nBuff].SpellID <= 0)
				return false;

			Dest.Int = nBuff;
			return true;
		}

		{
			int buffID = FindBuffID(Index);
			if (buffID >= 0 && buffID < NUM_LONG_BUFFS)
			{
				Dest.Int = buffID;
				return true;
			}
		}

		return false;

	case CharacterMembers::Song:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nBuff = GetIntFromString(Index, 0) - 1;
			if (nBuff < 0 || nBuff >= NUM_SHORT_BUFFS || pProfile->ShortBuff[nBuff].SpellID <= 0)
				return false;

			Dest.Int = nBuff + NUM_LONG_BUFFS;
			return true;
		}

		{
			int buffID = FindBuffID(Index);
			if (buffID >= NUM_LONG_BUFFS && buffID < NUM_LONG_BUFFS + NUM_SHORT_BUFFS)
			{
				Dest.Int = buffID;
				return true;
			}
		}

		return false;

	case CharacterMembers::HPBonus:
		Dest.DWord = pChar->HPBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::ManaBonus:
		Dest.DWord = pChar->ManaBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::EnduranceBonus:
		Dest.DWord = pChar->EnduranceBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CombatEffectsBonus: {
		int CombatEffectsCap = GetModCap(HEROIC_MOD_COMBAT_EFFECTS);
		Dest.DWord = (pChar->CombatEffectsBonus > CombatEffectsCap ? CombatEffectsCap : pChar->CombatEffectsBonus);
		Dest.Type = pIntType;
		return true;
	}

	case CharacterMembers::ShieldingBonus: {
		int ShieldingCap = GetModCap(HEROIC_MOD_MELEE_SHIELDING);
		Dest.DWord = (pChar->ShieldingBonus > ShieldingCap ? ShieldingCap : pChar->ShieldingBonus);
		Dest.Type = pIntType;
		return true;
	}

	case CharacterMembers::SpellShieldBonus: {
		int SpellShieldCap = GetModCap(HEROIC_MOD_SPELL_SHIELDING);
		Dest.DWord = (pChar->SpellShieldBonus > SpellShieldCap ? SpellShieldCap : pChar->SpellShieldBonus);
		Dest.Type = pIntType;
		return true;
	}

	case CharacterMembers::AvoidanceBonus: {
		int AvoidanceCap = GetModCap(HEROIC_MOD_AVOIDANCE);
		Dest.DWord = (pChar->AvoidanceBonus > AvoidanceCap ? AvoidanceCap : pChar->AvoidanceBonus);
		Dest.Type = pIntType;
		return true;
	}

	case CharacterMembers::AccuracyBonus: {
		int AccuracyCap = GetModCap(HEROIC_MOD_ACCURACY);
		Dest.DWord = (pChar->AccuracyBonus > AccuracyCap ? AccuracyCap : pChar->AccuracyBonus);
		Dest.Type = pIntType;
		return true;
	}

	case CharacterMembers::StunResistBonus: {
		int StunResistCap = GetModCap(HEROIC_MOD_STUN_RESIST);
		Dest.DWord = (pChar->StunResistBonus > StunResistCap ? StunResistCap : pChar->StunResistBonus);
		Dest.Type = pIntType;
		return true;
	}

	case CharacterMembers::StrikeThroughBonus: {
		int StrikeThroughCap = GetModCap(HEROIC_MOD_STRIKETHROUGH);
		Dest.DWord = (pChar->StrikeThroughBonus > StrikeThroughCap ? StrikeThroughCap : pChar->StrikeThroughBonus);
		Dest.Type = pIntType;
		return true;
	}

	case CharacterMembers::DoTShieldBonus: {
		int DoTShieldCap = GetModCap(HEROIC_MOD_DOT_SHIELDING);
		Dest.DWord = (pChar->DoTShieldBonus > DoTShieldCap ? DoTShieldCap : pChar->DoTShieldBonus);
		Dest.Type = pIntType;
		return true;
	}

	case CharacterMembers::AttackBonus:
		Dest.DWord = pChar->AttackBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::HPRegenBonus:
		Dest.DWord = pChar->HPRegenBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::ManaRegenBonus:
		Dest.DWord = pChar->ManaRegenBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::DamageShieldBonus: {
		int DamageShieldCap = GetModCap(HEROIC_MOD_DAMAGE_SHIELDING);
		Dest.DWord = (pChar->DamageShieldBonus > DamageShieldCap ? DamageShieldCap : pChar->DamageShieldBonus);
		Dest.Type = pIntType;
		return true;
	}

	case CharacterMembers::DamageShieldMitigationBonus: {
		int DamageShieldMitigationCap = GetModCap(HEROIC_MOD_DAMAGE_SHIELD_MITIG);
		Dest.DWord = (pChar->DamageShieldMitigationBonus > DamageShieldMitigationCap ? DamageShieldMitigationCap : pChar->DamageShieldMitigationBonus);
		Dest.Type = pIntType;
		return true;
	}

	case CharacterMembers::HeroicSTRBonus:
		Dest.DWord = pChar->HeroicSTRBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::HeroicINTBonus:
		Dest.DWord = pChar->HeroicINTBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::HeroicWISBonus:
		Dest.DWord = pChar->HeroicWISBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::HeroicAGIBonus:
		Dest.DWord = pChar->HeroicAGIBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::HeroicDEXBonus:
		Dest.DWord = pChar->HeroicDEXBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::HeroicSTABonus:
		Dest.DWord = pChar->HeroicSTABonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::HeroicCHABonus:
		Dest.DWord = pChar->HeroicCHABonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::HealAmountBonus:
		Dest.DWord = pChar->HealAmountBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::SpellDamageBonus:
		Dest.DWord = pChar->SpellDamageBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::ClairvoyanceBonus:
		Dest.DWord = pChar->ClairvoyanceBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::EnduranceRegenBonus:
		Dest.DWord = pChar->EnduranceRegenBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::AttackSpeed:
		Dest.DWord = pChar->AttackSpeed;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Endurance: // Backwards compat, CurrentEndurance should be used instead.
	case CharacterMembers::CurrentEndurance:
		Dest.DWord = pProfile->Endurance;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::MaxEndurance:
		Dest.DWord = GetMaxEndurance();
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::PctEndurance:
		if (int maxEndurance = GetMaxEndurance())
			Dest.DWord = pProfile->Endurance * 100 / maxEndurance;
		else
			Dest.DWord = 0;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::GukEarned:
		Dest.DWord = 0;
		if (CHARINFONEW* pCharnew = (CHARINFONEW*)GetCharInfo())
		{
			Dest.DWord = pCharnew->AdventureData.ThemeStats[eAT_DeepGuk].AdventureTotalPointsEarned;
		}
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::MMEarned:
		Dest.DWord = 0;
		if (CHARINFONEW* pCharnew = (CHARINFONEW*)GetCharInfo())
		{
			Dest.DWord = pCharnew->AdventureData.ThemeStats[eAT_Mistmoore].AdventureTotalPointsEarned;
		}
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::RujEarned:
		Dest.DWord = 0;
		if (CHARINFONEW* pCharnew = (CHARINFONEW*)GetCharInfo())
		{
			Dest.DWord = pCharnew->AdventureData.ThemeStats[eAT_Rujarkian].AdventureTotalPointsEarned;
		}
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::TakEarned:
		Dest.DWord = 0;
		if (CHARINFONEW* pCharnew = (CHARINFONEW*)GetCharInfo())
		{
			Dest.DWord = pCharnew->AdventureData.ThemeStats[eAT_Takish].AdventureTotalPointsEarned;
		}
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::MirEarned:
		Dest.DWord = 0;
		if (CHARINFONEW* pCharnew = (CHARINFONEW*)GetCharInfo())
		{
			Dest.DWord = pCharnew->AdventureData.ThemeStats[eAT_Miraguls].AdventureTotalPointsEarned;
		}
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LDoNPoints:
		Dest.DWord = 0;
		if (CHARINFONEW* pCharnew = (CHARINFONEW*)GetCharInfo())
		{
			Dest.DWord = pCharnew->AdventureData.AdventurePointsAvailable;
		}
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CurrentFavor:
		Dest.Int64 = pChar->CurrFavor;
		Dest.Type = pInt64Type;
		return true;

	case CharacterMembers::CareerFavor:
		Dest.Int64 = pChar->CareerFavor;
		Dest.Type = pInt64Type;
		return true;

	case CharacterMembers::Inventory:
		Dest.Type = pItemType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int nSlot = GetIntFromString(Index, NUM_INV_SLOTS);
				if (nSlot < NUM_INV_SLOTS)
				{
					if (pProfile->pInventoryArray && ((Dest.Ptr = pProfile->pInventoryArray->InventoryArray[nSlot])))
					{
						return true;
					}
				}
			}
			else
			{
				for (int nSlot = 0; szItemSlot[nSlot]; nSlot++)
				{
					if (!_stricmp(Index, szItemSlot[nSlot]))
					{
						if (pProfile->pInventoryArray && ((Dest.Ptr = pProfile->pInventoryArray->InventoryArray[nSlot])))
						{
							return true;
						}
					}
				}
			}
		}
		return false;

	case CharacterMembers::Bank:
		Dest.Type = pItemType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int nSlot = GetIntFromString(Index, 0) - 1;
				if (nSlot < 0)
					return false;

				if (nSlot < NUM_BANK_SLOTS)
				{
					if (pChar && pChar->pBankArray)
					{
						if (Dest.Ptr = pChar->pBankArray->Bank[nSlot])
						{
							return true;
						}
					}
				}
				else
				{
					nSlot -= NUM_BANK_SLOTS;
					if (nSlot < NUM_SHAREDBANK_SLOTS)
					{
						if (pChar && pChar->pSharedBankArray)
						{
							if (Dest.Ptr = pChar->pSharedBankArray->SharedBank[nSlot])
							{
								return true;
							}
						}
					}
				}
			}
		}
		return false;

	case CharacterMembers::PlatinumShared:
		Dest.DWord = pChar->BankSharedPlat;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Cash:
		Dest.Int64 = static_cast<uint64_t>(pProfile->Plat) * 1000 + static_cast<uint64_t>(pProfile->Gold) * 100 + static_cast<uint64_t>(pProfile->Silver) * 10 + pProfile->Copper;
		Dest.Type = pInt64Type;
		return true;

	case CharacterMembers::Platinum:
		Dest.DWord = pProfile->Plat;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CursorPlatinum:
		Dest.DWord = pProfile->CursorPlat;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Gold:
		Dest.DWord = pProfile->Gold;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CursorGold:
		Dest.DWord = pProfile->CursorGold;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Silver:
		Dest.DWord = pProfile->Silver;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CursorSilver:
		Dest.DWord = pProfile->CursorSilver;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Copper:
		Dest.DWord = pProfile->Copper;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CursorCopper:
		Dest.DWord = pProfile->CursorCopper;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CashBank:
		Dest.Int64 = static_cast<uint64_t>(pProfile->Plat) * 1000 + static_cast<uint64_t>(pProfile->Gold) * 100 + static_cast<uint64_t>(pProfile->Silver) * 10 + pProfile->Copper;
		Dest.Type = pInt64Type;
		return true;

	case CharacterMembers::PlatinumBank:
		Dest.DWord = pChar->BankPlat;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::GoldBank:
		Dest.DWord = pChar->BankGold;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::SilverBank:
		Dest.DWord = pChar->BankSilver;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CopperBank:
		Dest.DWord = pChar->BankCopper;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::AAExp:
		Dest.DWord = pChar->AAExp;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::AAPoints:
		Dest.DWord = pProfile->AAPoints;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Combat:
		Dest.DWord = *EQADDR_ATTACK;
		Dest.Type = pBoolType;
		return true;

	case CharacterMembers::HPRegen:
		Dest.DWord = GetHPRegen();
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::ManaRegen:
		Dest.DWord = GetManaRegen();
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::EnduranceRegen:
		Dest.DWord = GetEnduranceRegen();
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Grouped:
		Dest.Type = pBoolType;
		if (!pChar->pGroupInfo)
			return false;

		Dest.DWord = pChar->pGroupInfo->pMember[1]
			|| pChar->pGroupInfo->pMember[2]
			|| pChar->pGroupInfo->pMember[3]
			|| pChar->pGroupInfo->pMember[4]
			|| pChar->pGroupInfo->pMember[5];
		return true;

	case CharacterMembers::GroupList: { // This isn't really working as intended just yet
		Dest.Type = pStringType;
		if (!pChar->pGroupInfo)
			return false;
		for (int i = 1; i < 6; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
			{
				strcpy_s(DataTypeTemp, pChar->pGroupInfo->pMember[i]->Name.c_str());
				if (i < 5 && pChar->pGroupInfo->pMember[i + 1])
					strcat_s(DataTypeTemp, " ");
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	}

	case CharacterMembers::AmIGroupLeader:
		Dest.Type = pStringType;
		if (!pChar->pGroupInfo) return false;
		if (!pChar->pGroupInfo->pLeader) return false;

		if (!_stricmp(pChar->pGroupInfo->pLeader->Name.c_str(), pChar->Name))
			strcpy_s(DataTypeTemp, "TRUE");
		else
			strcpy_s(DataTypeTemp, "FALSE");
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case CharacterMembers::MaxBuffSlots:
		Dest.DWord = GetCharMaxBuffSlots();
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::FreeBuffSlots:
		Dest.DWord = GetCharMaxBuffSlots();
		Dest.Type = pIntType;

		for (const auto& buff : pProfile->Buff)
		{
			if (buff.SpellID > 0)
				Dest.DWord--;
		}
		return true;

	case CharacterMembers::Gem:
		Dest.Type = pSpellType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			// number
			int nGem = GetIntFromString(Index, 0) - 1;
			if (nGem < 0)
				return false;

			if (nGem < NUM_SPELL_GEMS)
			{
				if (Dest.Ptr = GetSpellByID(GetMemorizedSpell(nGem)))
				{
					Dest.Type = pSpellType;
					return true;
				}
			}
		}
		else
		{
			// name
			for (unsigned long nGem = 0; nGem < NUM_SPELL_GEMS; nGem++)
			{
				if (SPELL* pSpell = GetSpellByID(GetMemorizedSpell(nGem)))
				{
					if (!_stricmp(Index, pSpell->Name))
					{
						Dest.DWord = nGem + 1;
						Dest.Type = pIntType;
						return true;
					}
				}
			}
		}
		return false;

	case CharacterMembers::LanguageSkill: {
		Dest.DWord = 0;
		Dest.Type = pIntType;
		int nLang = 0;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			nLang = GetIntFromString(Index, nLang) - 1;
			if (nLang < 0)
				return false;
		}
		else
		{
			nLang = GetLanguageIDByName(Index) - 1;
		}
		if (nLang < 0 || nLang >= 25)
			return false;

		Dest.DWord = pChar->languages[nLang];
		return true;
	}

	case CharacterMembers::CombatAbility:
		Dest.Type = pSpellType;
		if (!Index[0])
			return false;
		if (IsNumber(Index))
		{
			// number
			int abnum = GetIntFromString(Index, 0);
			if (abnum <= 0)
				abnum = 1;
			int nCombatAbility = abnum - 1;
			if (nCombatAbility < NUM_COMBAT_ABILITIES)
			{
				if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility))
				{
					if (SPELL* pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)))
					{
						Dest.Ptr = pSpell;
						Dest.Type = pSpellType;
						return true;
					}
				}
			}
		}
		else
		{
			// name
			for (unsigned long nCombatAbility = 0; nCombatAbility < NUM_COMBAT_ABILITIES; nCombatAbility++)
			{
				if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility))
				{
					if (SPELL* pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)))
					{
						if (!_stricmp(Index, pSpell->Name))
						{
							Dest.DWord = nCombatAbility + 1;
							Dest.Type = pIntType;
							return true;
						}
					}
				}
			}
		}
		return false;

	case CharacterMembers::CombatAbilityTimer:
		Dest.Int = 0;
		Dest.Type = pTicksType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// number
				int nCombatAbility = GetIntFromString(Index, 0) - 1;
				if (nCombatAbility < 0)
					return false;
				if (nCombatAbility < NUM_COMBAT_ABILITIES)
				{
					if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility))
					{
						if (SPELL* pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)))
						{
							uint32_t timeNow = static_cast<uint32_t>(time(nullptr));

							if (pPCData->GetCombatAbilityTimer(pSpell->ReuseTimerIndex, pSpell->SpellGroup) > timeNow)
							{
								Dest.Int = pPCData->GetCombatAbilityTimer(pSpell->ReuseTimerIndex, pSpell->SpellGroup) - timeNow + 6;
								Dest.Int /= 6;
							}

							return true;
						}
					}
				}
			}
			else
			{
				// by name
				for (int nCombatAbility = 0; nCombatAbility < NUM_COMBAT_ABILITIES; nCombatAbility++)
				{
					if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility)) {
						if (SPELL* pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)))
						{
							if (!_stricmp(Index, pSpell->Name))
							{
								uint32_t timeNow = static_cast<uint32_t>(time(nullptr));
								uint32_t timer = pPCData->GetCombatAbilityTimer(pSpell->ReuseTimerIndex, pSpell->SpellGroup);

								if (timer > timeNow)
								{
									Dest.Int = timer - timeNow + 6;
									Dest.Int /= 6;
								}
								return true;
							}
						}
					}
				}
			}
		}
		return false;

	case CharacterMembers::CombatAbilityReady:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// number
				int nCombatAbility = GetIntFromString(Index, 0) - 1;
				if (nCombatAbility < 0)
					return false;

				if (nCombatAbility < NUM_COMBAT_ABILITIES)
				{
					if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility))
					{
						if (SPELL* pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)))
						{
							uint32_t timeNow = static_cast<uint32_t>(time(nullptr));
							uint32_t timer = pPCData->GetCombatAbilityTimer(pSpell->ReuseTimerIndex, pSpell->SpellGroup);

							if (timer < timeNow)
							{
								Dest.DWord = 1;
								return true;
							}
						}
					}
				}
			}
			else
			{
				// by name
				for (unsigned long nCombatAbility = 0; nCombatAbility < NUM_COMBAT_ABILITIES; nCombatAbility++)
				{
					if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility))
					{
						if (SPELL* pSpell = GetSpellByID(pPCData->GetCombatAbility(nCombatAbility)))
						{
							if (!_stricmp(Index, pSpell->Name))
							{
								uint32_t timeNow = static_cast<uint32_t>(time(nullptr));
								uint32_t timer = pPCData->GetCombatAbilityTimer(pSpell->ReuseTimerIndex, pSpell->SpellGroup);

								if (timer < timeNow)
								{
									Dest.DWord = 1;
									return true;
								}
							}
						}
					}
				}
			}
		}
		return true;

	case CharacterMembers::ActiveDisc:
		Dest.Type = pSpellType;

		if (pCombatAbilityWnd)
		{
			if (CXWnd* Child = pCombatAbilityWnd->GetChildItem("CAW_CombatEffectLabel"))
			{
				CXStr name = Child->GetWindowText();
				if (!name.empty())
				{
					if (Dest.Ptr = GetSpellByName(name.c_str()))
					{
						return true;
					}
				}
			}
		}
		return false;

	case CharacterMembers::Moving:
		Dest.DWord = false;
		if (pCharSpawn && pChar && pChar->pSpawn)
		{
			Dest.DWord =
				((gbMoving
					&& (pChar->pSpawn->SpeedRun == 0.0f)
					&& (pChar->pSpawn->Mount == nullptr))
				|| (fabs(FindSpeed(pChar->pSpawn) > 0.0f)));
		}
		Dest.Type = pBoolType;
		return true;

	case CharacterMembers::Hunger:
		Dest.DWord = pProfile->hungerlevel;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Thirst:
		Dest.DWord = pProfile->thirstlevel;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::AltAbilityTimer:
		Dest.UInt64 = 0;
		Dest.Type = pTimeStampType;

		if (Index[0]) {
			if (IsNumber(Index))
			{
				// numeric
				for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
				{
					if (ALTABILITY* pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility)))
					{
						if (pAbility->ID == GetIntFromString(Index, 0))
						{
							int reusetimer = 0;
							pAltAdvManager->IsAbilityReady(pPCData, pAbility, &reusetimer);
							if (reusetimer < 0)
							{
								reusetimer = 0;
							}

							Dest.UInt64 = reusetimer * 1000;
							return true;
						}
					}
				}
			}
			else
			{
				// by name so we ned to take level into account
				int level = -1;
				if (pChar->pSpawn)
				{
					level = pChar->pSpawn->Level;
				}

				for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
				{
					if (ALTABILITY* pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility), level))
					{
						if (const char* pName = pCDBStr->GetString(pAbility->nName, eAltAbilityName))
						{
							if (!_stricmp(Index, pName))
							{
								int reusetimer = 0;
								pAltAdvManager->IsAbilityReady(pPCData, pAbility, &reusetimer);
								if (reusetimer < 0)
								{
									reusetimer = 0;
								}

								Dest.UInt64 = static_cast<uint64_t>(reusetimer) * 1000;
								return true;
							}
						}
					}
				}
			}
		}
		return false;

	case CharacterMembers::AltAbilityReady:
		Dest.DWord = 0;
		Dest.Type = pBoolType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// numeric
				for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
				{
					if (ALTABILITY* pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility)))
					{
						if (pAbility->ID == GetIntFromString(Index, 0))
						{
							if (pAbility->SpellID != -1)
								Dest.DWord = pAltAdvManager->IsAbilityReady(pPCData, pAbility, nullptr);

							return true;
						}
					}
				}
			}
			else
			{
				// by name so we need to take their level into account
				int level = -1;
				if (pChar->pSpawn)
				{
					level = pChar->pSpawn->Level;
				}

				for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
				{
					if (ALTABILITY* pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility), level))
					{
						if (const char* pName = pCDBStr->GetString(pAbility->nName, eAltAbilityName))
						{
							if (!_stricmp(Index, pName))
							{
								if (pAbility->SpellID != -1)
									Dest.DWord = pAltAdvManager->IsAbilityReady(pPCData, pAbility, nullptr);

								return true;
							}
						}
					}
				}
			}
		}
		return true;

	case CharacterMembers::AltAbility:
		Dest.Type = pAltAbilityType;
		if (Index[0])

		{
			if (IsNumber(Index))
			{
				// numeric
				for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
				{
					if (ALTABILITY* pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility)))
					{
						if (pAbility->ID == GetIntFromString(Index, 0))
						{
							Dest.Ptr = pAbility;
							return true;
						}
					}
				}
			}
			else
			{
				// by name so we need to take their level into account
				int level = -1;
				if (pChar->pSpawn)
				{
					level = pChar->pSpawn->Level;
				}

				for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
				{
					if (ALTABILITY* pAbility = GetAAByIdWrapper(pPCData->GetAlternateAbilityId(nAbility), level))
					{
						if (const char* pName = pCDBStr->GetString(pAbility->nName, eAltAbilityName))
						{
							if (!_stricmp(Index, pName))
							{
								Dest.Ptr = pAbility;
								return true;
							}
						}
					}
				}
			}
		}
		return false;

	case CharacterMembers::Skill:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (Index[0])
		{
			int nSkill = 0;

			if (IsNumber(Index))
			{
				// numeric
				nSkill = GetIntFromString(Index, nSkill) - 1;
				if (nSkill < 0)
					return false;
			}
			else
			{
				// name
				for (nSkill = 0; nSkill < NUM_SKILLS; nSkill++)
				{
					if (!_stricmp(Index, szSkills[nSkill]))
						break;
				}
			}

			if (nSkill < NUM_SKILLS)
			{
				if (pProfile->Skill[nSkill])
				{
					Dest.DWord = GetAdjustedSkill(nSkill);
				}
				return true;
			}
		}
		return false;

	case CharacterMembers::SkillBase:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (Index[0])
		{
			int nSkill = 0;

			if (IsNumber(Index))
			{
				// numeric
				nSkill = GetIntFromString(Index, nSkill) - 1;
				if (nSkill < 0)
					return false;
			}
			else
			{
				// name
				for (nSkill = 0; nSkill < NUM_SKILLS; nSkill++)
				{
					if (!_stricmp(Index, szSkills[nSkill]))
						break;
				}
			}

			if (nSkill < NUM_SKILLS)
			{
				if (pProfile->Skill[nSkill])
				{
					Dest.DWord = GetBaseSkill(nSkill);
				}
				return true;
			}
		}
		return false;

	case CharacterMembers::SkillCap:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (Index[0])
		{
			int nSkill = 0;

			if (IsNumber(Index))
			{
				// numeric
				nSkill = GetIntFromString(Index, nSkill) - 1;
				if (nSkill < 0)
					return false;
			}
			else
			{
				// name
				for (nSkill = 0; nSkill < NUM_SKILLS; nSkill++)
				{
					if (!_stricmp(Index, szSkills[nSkill]))
						break;
				}
			}

			if (nSkill < NUM_SKILLS)
			{
				if (pCharData)
				{
					Dest.DWord = pSkillMgr->GetSkillCap(pCharData, pProfile->Level, pProfile->Class, nSkill, true, true, true);
					return true;
				}
			}
		}
		return false;

	case CharacterMembers::Ability:
		Dest.Type = pStringType;
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// numeric
				if (int nSkill = GetIntFromString(Index, 0))
				{
					if (bool bActivated = pSkillMgr->IsActivatedSkill(nSkill))
					{
						int nToken = pSkillMgr->GetNameToken(nSkill);

						if (const char* thename = pStringTable->getString(nToken))
						{
							strcpy_s(DataTypeTemp, thename);
							Dest.Ptr = &DataTypeTemp[0];
							Dest.Type = pStringType;
							return true;
						}
					}
				}
				return false;
			}

			// name
			for (int i = 0; i < NUM_SKILLS; i++)
			{
				int nToken = pSkillMgr->GetNameToken(i);

				if (const char* thename = pStringTable->getString(nToken))
				{
					if (!_stricmp(Index, thename))
					{
						if (bool bActivated = pSkillMgr->IsActivatedSkill(i))
						{
							Dest.DWord = i;
							Dest.Type = pIntType;
							return true;
						}

						break;
					}
				}
			}
		}
		return false;

	case CharacterMembers::AbilityReady:
		Dest.DWord = false;
		Dest.Type = pBoolType;

		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			// numeric
			if (int nSkill = GetIntFromString(Index, 0))
			{
				if (bool bActivated = pSkillMgr->IsActivatedSkill(nSkill))
				{
					Dest.DWord = pSkillMgr->IsAvailable(nSkill);
				}
			}
			return true;
		}

		// name
		for (int i = 0; i < NUM_SKILLS; i++)
		{
			int nToken = pSkillMgr->GetNameToken(i);

			if (const char* thename = pStringTable->getString(nToken))
			{
				if (!_stricmp(Index, thename))
				{
					if (bool bActivated = pSkillMgr->IsActivatedSkill(i))
					{
						Dest.DWord = pSkillMgr->IsAvailable(i);
					}
					break;
				}
			}
		}

		return true;

	case CharacterMembers::RangedReady:
		Dest.DWord = gbRangedAttackReady;
		Dest.Type = pBoolType;
		return true;

	case CharacterMembers::AltTimerReady:
		Dest.DWord = 1; // this is broken and should be fixed or removed.
		Dest.Type = pBoolType;
		return true;

	case CharacterMembers::Book:
		Dest.Type = pSpellType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// numeric
				int nSpell = GetIntFromString(Index, 0) - 1;
				if (nSpell < 0)
					return false;

				if (nSpell < NUM_BOOK_SLOTS)
				{
					if (Dest.Ptr = GetSpellByID(pProfile->SpellBook[nSpell]))
					{
						Dest.Type = pSpellType;
						return true;
					}
				}
			}
			else
			{
				// name
				for (int nSpell = 0; nSpell < NUM_BOOK_SLOTS; nSpell++)
				{
					if (pProfile->SpellBook[nSpell] != -1)
					{
						if (!_stricmp(GetSpellNameByID(pProfile->SpellBook[nSpell]), Index))
						{
							Dest.DWord = nSpell + 1;
							Dest.Type = pIntType;
							return true;
						}
					}
				}
			}
		}
		return false;

	case CharacterMembers::Spell:
	{
		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// Look for spell in our book by ID
				int spellId = GetIntFromString(Index, 0);

				for (int nSpell : pProfile->SpellBook)
				{
					if (nSpell == spellId)
					{
						Dest.Type = pSpellType;
						Dest.Ptr = GetSpellByID(spellId);
						return true;
					}
				}
			}
			else
			{
				// Look for spell in our book by Name like ${Spell}
				if (PSPELL pSpell = GetSpellByName(Index))
				{
					// If we found a spell check if its in the spellbook
					int spellID = pSpell->ID;

					for (int nSpell : pProfile->SpellBook)
					{
						if (nSpell == spellID)
						{
							Dest.Type = pSpellType;
							Dest.Ptr = pSpell;
							return true;
						}
					}

					// Scan the spell book for spells in the same group that match
					// at the substring level
					for (int nSpell : pProfile->SpellBook)
					{
						if (nSpell != -1)
						{
							if (PSPELL pFoundSpell = GetSpellByID(nSpell))
							{
								if (pFoundSpell->SpellGroup == pSpell->SpellGroup
									&& ci_find_substr(pFoundSpell->Name, pSpell->Name) == 0)
								{
									Dest.Ptr = pFoundSpell;
									Dest.Type = pSpellType;
									return true;
								}
							}
						}
					}
				}
			}
		}
		return false;
	}

	case CharacterMembers::ItemReady: {
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		CONTENTS* pCont = nullptr;

		if (pDisplay && pLocalPlayer && Index[0])
		{
			if (IsNumber(Index))
			{
				pCont = FindItemByID(GetIntFromString(Index, 0));
			}
			else
			{
				if (char* pName = Index)
				{
					bool bExact = false;
					if (*pName == '=')
					{
						bExact = true;
						pName++;
					}

					pCont = FindItemByName(pName, bExact);
				}
			}

			if (pCont)
			{
				if (PITEMINFO pIteminf = GetItemFromContents(pCont))
				{
					if (pIteminf->Clicky.TimerID != -1)
					{
						uint32_t timer = GetItemTimer(pCont);
						if (timer == 0)
							Dest.DWord = 1;
					}
					else if (pIteminf->Clicky.SpellID != -1)
					{
						Dest.DWord = 1; // insta-click or instant recast
					}
				}
			}
		}
		return true;
	}

	case CharacterMembers::BardSongPlaying:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pCastSpellWnd && pCastSpellWnd->IsBardSongPlaying())
		{
			Dest.DWord = 1;
		}
		return true;

	case CharacterMembers::SpellReady:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (pCastingWnd && pCastingWnd->IsVisible())
		{
			return true;
		}

		if (pCastSpellWnd && pCastSpellWnd->IsBardSongPlaying())
		{
			Dest.DWord = 1;
			return true;
		}

		if (pDisplay && pLocalPlayer && Index[0])
		{
			if (IsNumber(Index))
			{
				// numeric
				int nGem = GetIntFromString(Index, 0) - 1;
				if (nGem < 0 || nGem > NUM_SPELL_GEMS)
					return false;

				if (GetSpellByID(GetMemorizedSpell(nGem)))
				{
					if (pDisplay->TimeStamp > pChar->pSpawn->SpellGemETA[nGem]
						&& pDisplay->TimeStamp > pChar->pSpawn->GetSpellCooldownETA())
					{
						Dest.DWord = 1;
					}
					return true;
				}
			}
			else
			{
				for (int nGem = 0; nGem < NUM_SPELL_GEMS; nGem++)
				{
					if (SPELL* pSpell = GetSpellByID(GetMemorizedSpell(nGem)))
					{
						if (!_stricmp(Index, pSpell->Name))
						{
							if (pDisplay->TimeStamp > pChar->pSpawn->SpellGemETA[nGem]
								&& pDisplay->TimeStamp > pChar->pSpawn->GetSpellCooldownETA())
							{
								Dest.DWord = 1;
							}
							return true;
						}
					}
				}
			}
		}
		return true;

	case CharacterMembers::PetBuff:
		Dest.Type = pSpellType;
		if (!Index[0] || !pPetInfoWnd)
			return false;

		if (IsNumber(Index))
		{
			int nBuff = GetIntFromString(Index, 0) - 1;
			if (nBuff < 0)
				return false;
			if (nBuff > NUM_BUFF_SLOTS)
				return false;

			if (pPetInfoWnd->Buff[nBuff] == -1 || pPetInfoWnd->Buff[nBuff] == 0)
				return false;

			if (Dest.Ptr = GetSpellByID(pPetInfoWnd->Buff[nBuff]))
			{
				Dest.Type = pSpellType;
				return true;
			}
		}
		else
		{
			for (int nBuff = 0; nBuff < NUM_BUFF_SLOTS; nBuff++)
			{
				if (SPELL* pSpell = GetSpellByID(pPetInfoWnd->Buff[nBuff]))
				{
					if (!_stricmp(Index, pSpell->Name))
					{
						Dest.DWord = nBuff + 1;
						Dest.Type = pIntType;
						return true;
					}
				}
			}
		}
		return false;

	case CharacterMembers::Stunned:
		Dest.DWord = (pChar->Stunned == 1);
		Dest.Type = pBoolType;
		return true;

	case CharacterMembers::LargestFreeInventory:
	{
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pProfile->pInventoryArray && pProfile->pInventoryArray->InventoryArray)
		{
			for (int slot = BAG_SLOT_START; slot < NUM_INV_SLOTS; slot++)
			{
				if (CONTENTS* pItem = pProfile->pInventoryArray->InventoryArray[slot])
				{
					if (GetItemFromContents(pItem)->Type == ITEMTYPE_PACK
						&& GetItemFromContents(pItem)->SizeCapacity > Dest.DWord)
					{
						for (int pslot = 0; pslot < (GetItemFromContents(pItem)->Slots); pslot++)
						{
							if (!pItem->Contents.ContainedItems.pItems || !pItem->GetContent(pslot))
							{
								Dest.DWord = GetItemFromContents(pItem)->SizeCapacity;
								break; // break the loop for this pack
							}
						}
					}
				}
				else
				{
					Dest.DWord = 4;
					return true;
				}
			}
		}
		return true;
	}

	case CharacterMembers::FreeInventory:
	{
		int nSize = 0;
		if (Index[0])
		{
			nSize = GetIntFromString(Index, 0);
			if (nSize > 4)
				nSize = 4;
		}

		Dest.DWord = GetFreeInventory(nSize);
		Dest.Type = pIntType;
		return true;
	}

	case CharacterMembers::Drunk:
		Dest.DWord = pProfile->Drunkenness;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::TargetOfTarget:
		Dest.Type = pSpawnType;
		if (gGameState == GAMESTATE_INGAME && pLocalPlayer && pChar->pSpawn)
		{
			if (Dest.Ptr = GetSpawnByID(pChar->pSpawn->TargetOfTarget))
			{
				return true;
			}
		}
		return false;

	case CharacterMembers::RaidAssistTarget:
		Dest.Type = pSpawnType;
		if (gGameState == GAMESTATE_INGAME && pLocalPlayer)
		{
			if (Index[0] && IsNumber(Index))
			{
				int index = GetIntFromString(Index, 0) - 1;
				if (index < 0)
					return false;
				if (index >= 3)
					return false;

				if (Dest.Ptr = (SPAWNINFO*)GetSpawnByID(GetRaidMainAssistTargetID(index)))
				{
					return true;
				}
			}
		}
		return false;

	case CharacterMembers::GroupAssistTarget:
		Dest.Type = pSpawnType;
		if (gGameState == GAMESTATE_INGAME && GetCharInfo()->pSpawn)
		{
			if (Dest.Ptr = (SPAWNINFO*)GetSpawnByID(GetGroupMainAssistTargetID()))
			{
				return true;
			}
		}
		return false;

	case CharacterMembers::RaidMarkNPC:
		Dest.Type = pSpawnType;
		if (gGameState == GAMESTATE_INGAME && pChar->pSpawn)
		{
			if (Index[0] && IsNumber(Index))
			{
				int index = GetIntFromString(Index, 0) - 1;
				if (index < 0)
					return false;
				if (index >= 3)
					return false;
				if (Dest.Ptr = GetSpawnByID(pChar->pSpawn->RaidMarkNPC[index]))
				{
					return true;
				}
			}
		}
		return false;

	case CharacterMembers::GroupMarkNPC:
		Dest.Type = pSpawnType;
		if (gGameState == GAMESTATE_INGAME && pChar->pSpawn)
		{
			if (Index[0] && IsNumber(Index))
			{
				int index = GetIntFromString(Index, 0) - 1;
				if (index < 0)
					return false;
				if (index >= 3)
					return false;

				if (Dest.Ptr = GetSpawnByID(pChar->pSpawn->GroupMarkNPC[index]))
				{
					return true;
				}
			}
		}
		return false;

	case CharacterMembers::STR:
		Dest.DWord = pChar->STR;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::STA:
		Dest.DWord = pChar->STA;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::AGI:
		Dest.DWord = pChar->AGI;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::DEX:
		Dest.DWord = pChar->DEX;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::WIS:
		Dest.DWord = pChar->WIS;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::INT:
		Dest.DWord = pChar->INT;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CHA:
		Dest.DWord = pChar->CHA;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LCK:
		Dest.DWord = pChar->LCK;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::svMagic:
		Dest.DWord = pChar->SaveMagic;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::svFire:
		Dest.DWord = pChar->SaveFire;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::svCold:
		Dest.DWord = pChar->SaveCold;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::svPoison:
		Dest.DWord = pChar->SavePoison;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::svDisease:
		Dest.DWord = pChar->SaveDisease;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CurrentWeight:
		Dest.DWord = pChar->CurrWeight;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::AAPointsSpent:
		Dest.DWord = pProfile->AAPointsSpent;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::AAPointsTotal:
		Dest.DWord = pProfile->AAPointsSpent + pProfile->AAPoints;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::AAPointsAssigned:
		Dest.DWord = pProfile->AAPointsAssigned[0];
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::TributeActive:
		Dest.DWord = *pTributeActive;
		Dest.Type = pBoolType;
		return true;

	case CharacterMembers::Running:
		Dest.DWord = (*EQADDR_RUNWALKSTATE);
		Dest.Type = pBoolType;
		return true;

	case CharacterMembers::GroupSize:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!pChar->pGroupInfo)
			return false;

		for (int i = 1; i < 6; i++)
		{
			if (pChar->pGroupInfo->pMember[i])
				Dest.DWord++;
		}

		// if we have at least one other group member, count self.
		if (Dest.DWord)
			Dest.DWord++;
		return true;

	case CharacterMembers::TributeTimer:
		Dest.DWord = pChar->TributeTimer / 60 / 100;
		Dest.Type = pTicksType;
		return true;

	case CharacterMembers::RadiantCrystals:
		Dest.DWord = pChar->RadiantCrystals;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::EbonCrystals:
		Dest.DWord = pChar->EbonCrystals;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Shrouded:
		Dest.DWord = pProfile->Shrouded;
		Dest.Type = pBoolType;
		return true;

	case CharacterMembers::AutoFire:
		Dest.DWord = gAutoFire;
		Dest.Type = pBoolType;
		return true;

	case CharacterMembers::Language: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

		int nLang = 0;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			nLang = GetIntFromString(Index, 0) - 1;
			if (nLang < 0)
				return false;
			strcpy_s(DataTypeTemp, pEverQuest->GetLangDesc(nLang));
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		}
		else
		{
			nLang = GetLanguageIDByName(Index) - 1;
		}

		if (nLang < 0 || nLang >= 25)
			return false;
		Dest.DWord = nLang;
		return true;
	}

	case CharacterMembers::Aura:
		Dest.Type = pAuraType;

		if (!pAuraMgr)
			return false;

		if (pAuraMgr->Auras.IsEmpty())
			return false;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int n = GetIntFromString(Index, pAuraMgr->Auras.GetLength() + 1);
				if (n > pAuraMgr->Auras.GetLength())
					return false;
				n--;
				Dest.Ptr = &pAuraMgr->Auras[n];
				Dest.HighPart = n;
				return true;
			}

			for (int n = 0; n < pAuraMgr->Auras.GetLength(); n++)
			{
				if (!_strnicmp(Index, pAuraMgr->Auras[n].Name, strlen(Index)))
				{
					Dest.Ptr = &pAuraMgr->Auras[n];
					Dest.HighPart = n;
					return true;
				}
			}
		}
		else
		{
			Dest.Ptr = &pAuraMgr->Auras[0];
			Dest.HighPart = 0;
			return true;
		}
		return false;

	case CharacterMembers::LAMarkNPC:
		Dest.DWord = 3;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LANPCHealth:
		Dest.DWord = 1;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LADelegateMA:
		Dest.DWord = 1;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LADelegateMarkNPC:
		Dest.DWord = 1;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LAInspectBuffs:
		Dest.DWord = 2;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LASpellAwareness:
		Dest.DWord = 1;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LAOffenseEnhancement:
		Dest.DWord = 5;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LAManaEnhancement:
		Dest.DWord = 3;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LAHealthEnhancement:
		Dest.DWord = 3;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LAHealthRegen:
		Dest.DWord = 3;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LAFindPathPC:
		Dest.DWord = 1;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LAHoTT:
		Dest.DWord = 1;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::ActiveFavorCost:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (*pTributeActive)
		{
			Dest.Int = pEQMisc->GetActiveFavorCost();
			return true;
		}
		return false;

	case CharacterMembers::CombatState:
		Dest.Type = pStringType;
		if (!pPlayerWnd)
			return false;

		switch (pPlayerWnd->CombatState)
		{
		case eCombatState_Combat:
			if (pPlayerWnd->GetChildItem("PW_CombatStateAnim"))
			{
				strcpy_s(DataTypeTemp, "COMBAT");
				break;
			}
			strcpy_s(DataTypeTemp, "NULL");
			break;

		case eCombatState_Debuff:
			strcpy_s(DataTypeTemp, "DEBUFFED");
			break;

		case eCombatState_Timer:
			strcpy_s(DataTypeTemp, "COOLDOWN");
			break;

		case eCombatState_Standing:
			strcpy_s(DataTypeTemp, "ACTIVE");
			break;

		case eCombatState_Regen:
			strcpy_s(DataTypeTemp, "RESTING");
			break;

		default:
			sprintf_s(DataTypeTemp, "UNKNOWN(%d)", pPlayerWnd->CombatState);
			break;
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case CharacterMembers::svCorruption:
		Dest.DWord = pChar->SaveCorruption;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::svPrismatic:
		Dest.DWord = (pChar->SaveMagic + pChar->SaveFire + pChar->SaveCold + pChar->SavePoison + pChar->SaveDisease) / 5;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::svChromatic: {
		int lowSave;
		lowSave = pChar->SaveMagic;
		if (lowSave > pChar->SaveFire)
			lowSave = pChar->SaveFire;
		if (lowSave > pChar->SaveCold)
			lowSave = pChar->SaveCold;
		if (lowSave > pChar->SavePoison)
			lowSave = pChar->SavePoison;
		if (lowSave > pChar->SaveDisease)
			lowSave = pChar->SaveDisease;

		Dest.Int = lowSave;
		Dest.Type = pIntType;
		return true;
	}

	case CharacterMembers::Doubloons:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_DOUBLOONS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Orux:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ORUX);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Phosphenes:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_PHOSPHENES);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Phosphites:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_PHOSPHITES);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Faycites:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_FAYCITES);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Chronobines:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_CHRONOBINES);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Commemoratives:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_COMMEMORATIVE_COINS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Nobles:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_NOBLES);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Fists:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_FISTSOFBAYLE);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::EnergyCrystals:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ENERGYCRYSTALS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::PiecesofEight:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_PIECESOFEIGHT);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::SilverTokens:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_SILVERTOKENS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::GoldTokens:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_GOLDTOKENS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::McKenzie:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_MCKENZIE);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Bayle:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_BAYLE);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Reclamation:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_RECLAMATION);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Brellium:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_BRELLIUM);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Motes:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_MOTES);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::RebellionChits:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_REBELLIONCHITS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::DiamondCoins:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_DIAMONDCOINS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::BronzeFiats:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_BRONZEFIATS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Voucher:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_VOUCHER);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::VeliumShards:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_VELIUMSHARDS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CrystallizedFear:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_CRYSTALLIZEDFEAR);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::ShadowStones:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_SHADOWSTONES);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::DreadStones:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_DREADSTONES);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::MarksOfValor:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_MARKSOFVALOR);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::MedalsOfHeroism:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_MEDALSOFHEROISM);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::RemnantOfTranquility:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_REMNANTSOFTRANQUILITY);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::BifurcatedCoin:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_BIFURCATEDCOIN);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::AdoptiveCoin:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ADOPTIVE);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::SathirsTradeGems:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_SATHIRSTRADEGEMS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::AncientSebilisianCoins:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ANCIENTSEBILISIANCOINS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::BathezidTradeGems:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_BATHEZIDTRADEGEMS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::AncientDraconicCoin:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ANCIENTDRACONICCOIN);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::FetterredIfritCoins:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_FETTERREDIFRITCOINS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::EntwinedDjinnCoins:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ENTWINEDDJINNCOINS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CrystallizedLuck:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_CRYSTALLIZEDLUCK);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::FroststoneDucat:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_FROSTSTONEDUCAT);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::WarlordsSymbol:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_WARLORDSSYMBOL);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::OverseerTetradrachm:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_OVERSEERTETRADRACHM);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Fellowship:
		Dest.Type = pFellowshipType;
		if (pChar->pSpawn)
		{
			Dest.Ptr = &pChar->pSpawn->Fellowship;
			return true;
		}
		return false;

	case CharacterMembers::Downtime:
		Dest.DWord = 0;
		Dest.Type = pTicksType;
		if (pChar->DowntimeStamp)
			Dest.DWord = ((pChar->Downtime - (GetFastTime() - pChar->DowntimeStamp)) / 6) + 1;
		return true;

		// returns combined number of spell and damage "absorbment"
		// should probably split these into spell vs melee
	case CharacterMembers::Dar:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		for (const auto& buff : pProfile->Buff)
		{
			if (SPELL* pSpell = GetSpellByID(buff.SpellID))
			{
				if (pSpell->SpellType != 0)
				{
					int slots = GetSpellNumEffects(pSpell);

					for (int i = 0; i < slots; i++)
					{
						int attrib = GetSpellAttrib(pSpell, i);

						if (IsDamageAbsorbSPA(attrib))
						{
							for (auto buffData : buff.SlotData)
							{
								if (buffData.Slot == i)
								{
									Dest.DWord += buffData.Value;
								}
							}
						}
					}
				}
			}
		}
		return true;

		// this case adds all resist Counters and returns that, why is this useful?
		// should we split these into 4? one for each debuff?
	case CharacterMembers::TotalCounters:
		Dest.DWord = GetMyTotalSpellCounters();
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CountersDisease:
		Dest.DWord += GetMySpellCounters(SPA_DISEASE);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CountersPoison:
		Dest.DWord = GetMySpellCounters(SPA_POISON);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CountersCurse:
		Dest.DWord = GetMySpellCounters(SPA_CURSE);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CountersCorruption:
		Dest.DWord = GetMySpellCounters(SPA_CORRUPTION);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Mercenary:
		Dest.Type = pMercenaryType;
		if (pMercInfo && pMercInfo->MercSpawnId)
		{
			Dest.Ptr = GetSpawnByID(pMercInfo->MercSpawnId);
			return true;
		}
		else if (pMercInfo)
		{
			// FIXME: Do not ZeroMemory a SPAWNINFO
			ZeroMemory(&MercenarySpawn, sizeof(MercenarySpawn));

			if (pMercInfo->HaveMerc == 1)
			{
				switch (pMercInfo->MercState)
				{
				case 0:
					strcpy_s(MercenarySpawn.Name, "DEAD");
					break;

				case 1:
					strcpy_s(MercenarySpawn.Name, "SUSPENDED");
					break;

				default:
					strcpy_s(MercenarySpawn.Name, "NULL");
					break;
				}

				Dest.Ptr = &MercenarySpawn;
				return true;
			}
			else
			{
				if (pMercInfo->MercenaryCount >= 1)
				{
					strcpy_s(MercenarySpawn.Name, "SUSPENDED");
					Dest.Ptr = &MercenarySpawn;
					return true;
				}
				else
				{
					strcpy_s(MercenarySpawn.Name, "NULL");
					Dest.Ptr = &MercenarySpawn;
					return true;
				}
			}
		}

		return false;

	case CharacterMembers::XTargetSlots:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (ExtendedTargetList* xtm = pChar->pXTargetMgr)
		{
			Dest.DWord = xtm->XTargetSlots.Count;
		}
		return true;

	case CharacterMembers::XTAggroCount:
		Dest.DWord = 0;
		if (ExtendedTargetList* xtm = pChar->pXTargetMgr)
		{
			int AggroPct = 100;
			if (IsNumber(Index))
			{
				AggroPct = GetIntFromString(Index, AggroPct);
				if (AggroPct < 1 || AggroPct > 100)
				{
					AggroPct = 100;
				}
			}

			if (pAggroInfo)
			{
				for (int i = 0; i < xtm->XTargetSlots.Count; i++)
				{
					XTARGETSLOT xts = xtm->XTargetSlots[i];
					uint32_t spID = xts.SpawnID;

					if (spID && xts.xTargetType == XTARGET_AUTO_HATER)
					{
						if (SPAWNINFO* pSpawn = (SPAWNINFO*)GetSpawnByID(spID))
						{
							if (pTarget && ((SPAWNINFO*)pTarget)->SpawnID == pSpawn->SpawnID)
								continue;

							if (pSpawn->Type == SPAWN_NPC)
							{
								uint16_t aggropct = pAggroInfo->aggroData[AD_xTarget1 + i].AggroPct;

								if (aggropct < AggroPct)
								{
									Dest.DWord++;
								}
							}
						}
					}
				}
			}
		}

		Dest.Type = pIntType;
		return true;

	case CharacterMembers::XTHaterCount:
		Dest.DWord = 0;
		if (ExtendedTargetList* xtm = pChar->pXTargetMgr)
		{
			if (pAggroInfo)
			{
				for (int i = 0; i < xtm->XTargetSlots.Count; i++)
				{
					XTARGETSLOT xts = xtm->XTargetSlots[i];
					uint32_t spID = xts.SpawnID;

					if (spID && xts.xTargetType == XTARGET_AUTO_HATER)
					{
						if (SPAWNINFO* pSpawn = (SPAWNINFO*)GetSpawnByID(spID))
						{
							if (pTarget && ((SPAWNINFO*)pTarget)->SpawnID == pSpawn->SpawnID)
								continue;

							if (pSpawn->Type == SPAWN_NPC)
							{
								Dest.DWord++;
							}
						}
					}
				}
			}
		}

		Dest.Type = pIntType;
		return true;

	case CharacterMembers::XTarget:
		Dest.DWord = 0;
		Dest.Type = pXTargetType;

		if (ExtendedTargetList* xtm = pChar->pXTargetMgr)
		{
			if (xtm->XTargetSlots.Count)
			{
				if (Index[0])
				{
					if (IsNumber(Index))
					{
						int index = GetIntFromString(Index, 0) - 1;
						if (index >= 0 && index < (int)xtm->XTargetSlots.Count)
						{
							Dest.DWord = index;
							Dest.Type = pXTargetType;
							return true;
						}
					}
					else
					{
						for (int n = 0; n < xtm->XTargetSlots.Count; n++)
						{
							XTARGETSLOT& xts = xtm->XTargetSlots[n];

							if (xts.xTargetType && xts.XTargetSlotStatus && !_stricmp(Index, xts.Name))
							{
								Dest.DWord = n;
								Dest.Type = pXTargetType;
								return true;
							}
						}
					}
				}
				else
				{
					int count = 0;
					for (int n = 0; n < xtm->XTargetSlots.Count; n++)
					{
						XTARGETSLOT& xts = xtm->XTargetSlots[n];
						if (xts.xTargetType && xts.XTargetSlotStatus)
						{
							count++;
						}
					}

					Dest.DWord = count;
					Dest.Type = pIntType;
					return true;
				}
			}
		}
		return false;

	case CharacterMembers::Haste: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

		// TODO: Is this GetCharInfo Redundant? Remove if so.
		if (CHARINFO* pCharInfo = GetCharInfo())
		{
			// TODO: Replace magic constant with enum
			Dest.DWord = pCharData->TotalEffect(0xb, true, 0, true, true);
			return true;
		}
		return false;
	}

	case CharacterMembers::SPA: {
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			// TODO: Is this GetCharInfo Redundant? Remove if so.
			if (CHARINFO* pCharInfo = GetCharInfo())
			{
				if (pCharInfo->vtable2) {
					Dest.DWord = pCharData->TotalEffect(GetIntFromString(Index, 0), true, 0, true, true);
					return true;
				}
			}
		}
		return false;
	}

	case CharacterMembers::MercenaryStance:
		strcpy_s(DataTypeTemp, "NULL");
		if (pMercInfo->HaveMerc)
		{
			for (int n = 0; n < pMercInfo->NumStances; n++)
			{
				if (pMercInfo->pMercStanceData[n]->nStance == pMercInfo->ActiveStance)
				{
					strcpy_s(DataTypeTemp, pCDBStr->GetString(pMercInfo->pMercStanceData[n]->nDbStance, eMercenaryStanceName));
					break;
				}
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case CharacterMembers::GemTimer:
		Dest.UInt64 = 0;
		Dest.Type = pTimeStampType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			// number
			int nGem = GetIntFromString(Index, 0) - 1;
			if (nGem < 0)
				return false;

			if (nGem < NUM_SPELL_GEMS)
			{
				if (GetMemorizedSpell(nGem) != 0xFFFFFFFF)
				{
					Dest.UInt64 = GetSpellGemTimer(nGem);
					return true;
				}
			}
		}
		else
		{
			// name
			for (int nGem = 0; nGem < NUM_SPELL_GEMS; nGem++)
			{
				if (SPELL* pSpell = GetSpellByID(GetMemorizedSpell(nGem)))
				{
					if (!_stricmp(Index, pSpell->Name))
					{
						Dest.UInt64 = GetSpellGemTimer(nGem);
						return true;
					}
				}
			}
		}
		return false;

	case CharacterMembers::HaveExpansion:
		Dest.DWord = 0;
		Dest.Type = pBoolType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nExpansion = GetIntFromString(Index, 0);
			if (nExpansion > NUM_EXPANSIONS)
				return true;
			Dest.DWord = GetCharInfo()->ExpansionFlags & EQ_EXPANSION(nExpansion);
		}
		else
		{
			for (int n = 0; n < NUM_EXPANSIONS; n++)
			{
				if (!_stricmp(Index, szExpansions[n]))
				{
					Dest.DWord = GetCharInfo()->ExpansionFlags & EQ_EXPANSION(n + 1);
					return true;
				}
			}
		}
		return true;

	case CharacterMembers::PctAggro:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pAggroInfo)
		{
			Dest.DWord = pAggroInfo->aggroData[AD_Player].AggroPct;
			return true;
		}
		return false;

	case CharacterMembers::SecondaryPctAggro:
		Dest.DWord = 0;
		Dest.Type = pIntType;
		if (pAggroInfo)
		{
			Dest.DWord = pAggroInfo->aggroData[AD_Secondary].AggroPct;
			return true;
		}
		return false;

	case CharacterMembers::SecondaryAggroPlayer:
		if (pAggroInfo && pAggroInfo->AggroSecondaryID)
		{
			Dest.Type = pSpawnType;
			Dest.Ptr = GetSpawnByID(pAggroInfo->AggroSecondaryID);
			return true;
		}
		return false;

	case CharacterMembers::AggroLock:
		if (pAggroInfo && pAggroInfo->AggroLockID)
		{
			Dest.Type = pSpawnType;
			Dest.Ptr = GetSpawnByID(pAggroInfo->AggroLockID);
			return true;
		}
		return false;

	case CharacterMembers::ZoneBound:
		if (pProfile->BoundLocations[0].ZoneBoundID)
		{
			Dest.Type = pZoneType;
			Dest.Ptr = pWorldData->ZoneArray[pProfile->BoundLocations[0].ZoneBoundID];
			return true;
		}
		return false;

	case CharacterMembers::ZoneBoundX:
		Dest.Type = pFloatType;
		Dest.Float = pProfile->BoundLocations[0].ZoneBoundX;
		return true;

	case CharacterMembers::ZoneBoundY:
		Dest.Type = pFloatType;
		Dest.Float = pProfile->BoundLocations[0].ZoneBoundY;
		return true;

	case CharacterMembers::ZoneBoundZ:
		Dest.Type = pFloatType;
		Dest.Float = pProfile->BoundLocations[0].ZoneBoundZ;
		return true;

	case CharacterMembers::PctMercAAExp:
		// this is how it looks like the client is doing it in the disasm...
		Dest.Float = (float)((pChar->MercAAExp + 5) / 10);
		Dest.Type = pFloatType;
		return true;

	case CharacterMembers::MercAAExp:
		Dest.Int64 = pChar->MercAAExp;
		Dest.Type = pInt64Type;
		return true;

	case CharacterMembers::Krono:
		Dest.DWord = pChar->Krono;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Subscription:
		strcpy_s(DataTypeTemp, "UNKNOWN");

		// TODO: Fix this. Its a struct not an int*
		if (EQADDR_SUBSCRIPTIONTYPE && *EQADDR_SUBSCRIPTIONTYPE)
		{
			int dwsubtype = *(int*)EQADDR_SUBSCRIPTIONTYPE;
			if (dwsubtype)
			{
				uint8_t subtype = *(uint8_t*)dwsubtype;
				switch (subtype)
				{
				case MembershipFreeToPlay:
					strcpy_s(DataTypeTemp, "FREE");
					break;
				case MembershipSilver:
					strcpy_s(DataTypeTemp, "SILVER");
					break;
				case MembershipGold:
					strcpy_s(DataTypeTemp, "GOLD");
					break;
				}
			}
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case CharacterMembers::AltCurrency:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			Dest.DWord = pPlayerPointManager->GetAltCurrency(GetIntFromString(Index, 0));
			return true;
		}
		else
		{
			int nCurrency = GetCurrencyIDByName(Index);
			if (nCurrency < 0)
				return false;
			Dest.DWord = pPlayerPointManager->GetAltCurrency(nCurrency);
			return true;
		}
		return false;

	case CharacterMembers::Slowed:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(SpellAffect(SPA_HASTE, false)));
		return Dest.Int >= 0;

	case CharacterMembers::Rooted:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(SpellAffect(SPA_ROOT, false)));
		return Dest.Int >= 0;

	case CharacterMembers::Mezzed:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(SpellAffect(SPA_ENTHRALL, false)));
		return Dest.Int >= 0;

	case CharacterMembers::Crippled:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(SpellSubCat(SPELLCAT_DISEMPOWERING)));
		return Dest.Int >= 0;

	case CharacterMembers::Maloed:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(SpellSubCat(SPELLCAT_RESIST_DEBUFFS), SpellClassMask(Shaman, Mage)));
		return Dest.Int >= 0;

	case CharacterMembers::Tashed:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(SpellSubCat(SPELLCAT_RESIST_DEBUFFS), SpellClassMask(Enchanter)));
		return Dest.Int >= 0;

	case CharacterMembers::Snared:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(SpellAffect(SPA_MOVEMENT_RATE, false)));
		return Dest.Int >= 0;

	case CharacterMembers::Hasted:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(SpellAffect(SPA_HASTE, true)));
		return Dest.Int >= 0;

	case CharacterMembers::LastZoned:
		Dest.UInt64 = LastEnteredZone;
		Dest.Type = pTimeStampType;
		return true;

	case CharacterMembers::Zoning: {
		if (LastEnteredZone == 0) // when people reload mq
		{
			LastEnteredZone = MQGetTickCount64();
			OldLastEnteredZone = LastEnteredZone;
		}

		// FIXME: SIDE EFFECTS
		bool bZoning = false;
		if (OldLastEnteredZone != LastEnteredZone)
		{
			OldLastEnteredZone = LastEnteredZone;
			bZoning = true;
		}

		Dest.DWord = bZoning;
		Dest.Type = pBoolType;
		return true;
	}

	case CharacterMembers::DSed:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(SpellAffect(SPA_DAMAGE_SHIELD, true)));
		return Dest.Int >= 0;

	case CharacterMembers::RevDSed:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(SpellAffect(SPA_IRONMAIDEN, true)));
		return Dest.Int >= 0;

	case CharacterMembers::Charmed:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(SpellAffect(SPA_CHARM, false)));
		return Dest.Int >= 0;

	case CharacterMembers::Aego:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(
			SpellAffect(SPA_AC, true),
			SpellCategory(SPELLCAT_HP_BUFFS),
			AnyBuffs(SpellSubCat(SPELLCAT_AEGOLISM), SpellSubCat(SPELLCAT_SYMBOL)),
			SpellClassMask(Cleric)));
		return Dest.Int >= 0;

	case CharacterMembers::Skin:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(
			SpellCategory(SPELLCAT_HP_BUFFS),
			SpellSubCat(SPELLCAT_HP_TYPE_ONE),
			SpellClassMask(Druid)));
		return Dest.Int >= 0;

	case CharacterMembers::Focus:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(
			SpellCategory(SPELLCAT_HP_BUFFS),
			SpellSubCat(SPELLCAT_SHIELDING),
			SpellClassMask(Shaman)));
		return Dest.Int >= 0;

	case CharacterMembers::Regen:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(SpellAffect(SPA_HP, true), !SpellClassMask(Beastlord)));
		return Dest.Int >= 0;

	case CharacterMembers::Diseased:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(SpellAffect(SPA_DISEASE, false)));
		return Dest.Int >= 0;

	case CharacterMembers::Poisoned:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(SpellAffect(SPA_POISON, false)));
		return Dest.Int >= 0;

	case CharacterMembers::Cursed:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(SpellAffect(SPA_CURSE, false)));
		return Dest.Int >= 0;

	case CharacterMembers::Corrupted:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(SpellAffect(SPA_CORRUPTION, false)));
		return Dest.Int >= 0;

	case CharacterMembers::Symbol:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(
			SpellCategory(SPELLCAT_HP_BUFFS),
			SpellSubCat(SPELLCAT_SYMBOL),
			SpellClassMask(Cleric)));
		return Dest.Int >= 0;

	case CharacterMembers::Clarity:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(
			SpellAffect(SPA_MANA, true),
			SpellClassMask(Enchanter)));
		return Dest.Int >= 0;

	case CharacterMembers::Pred:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(
			SpellCategory(SPELLCAT_STATISTIC_BUFFS),
			SpellSubCat(SPELLCAT_ATTACK),
			SpellClassMask(Ranger)));
		return Dest.Int >= 0;

	case CharacterMembers::Strength:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(
			SpellCategory(SPELLCAT_HP_BUFFS),
			SpellSubCat(SPELLCAT_HP_TYPE_TWO),
			SpellClassMask(Ranger)));
		return Dest.Int >= 0;

	case CharacterMembers::Brells:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(
			SpellCategory(SPELLCAT_HP_BUFFS),
			SpellSubCat(SPELLCAT_HP_TYPE_TWO),
			SpellClassMask(Paladin)));
		return Dest.Int >= 0;

	case CharacterMembers::SV:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(
			SpellCategory(SPELLCAT_REGEN),
			SpellSubCat(SPELLCAT_MANA),
			SpellClassMask(Beastlord)));
		return Dest.Int >= 0;

	case CharacterMembers::SE:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(
			SpellCategory(SPELLCAT_REGEN),
			SpellSubCat(SPELLCAT_HEALTH_MANA),
			SpellClassMask(Beastlord)));
		return Dest.Int >= 0;

	case CharacterMembers::HybridHP:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(
			SpellCategory(SPELLCAT_HP_BUFFS),
			SpellSubCat(SPELLCAT_HP_TYPE_ONE),
			SpellClassMask(Ranger)));
		return Dest.Int >= 0;

	case CharacterMembers::Growth:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(
			SpellCategory(SPELLCAT_HP_BUFFS),
			SpellSubCat(SPELLCAT_TEMPORARY),
			SpellClassMask(Druid)));
		return Dest.Int >= 0;

	case CharacterMembers::Shining:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(
			SpellCategory(SPELLCAT_UTILITY_BENEFICIAL),
			SpellSubCat(SPELLCAT_MELEE_GUARD),
			SpellAffect(SPA_MELEE_GUARD, true),
			SpellClassMask(Cleric)));
		return Dest.Int >= 0;

	case CharacterMembers::InInstance:
		Dest.DWord = 0;
		if (pChar->pSpawn)
		{
			if (int zoneid = pChar->pSpawn->GetZoneID())
			{
				if (uint16_t instance = HIWORD(zoneid))
					Dest.DWord = 1;
			}
		}
		Dest.Type = pBoolType;
		return true;

	case CharacterMembers::Instance:
		Dest.DWord = 0;
		if (pChar->pSpawn)
			Dest.DWord = HIWORD(pChar->pSpawn->GetZoneID());
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::MercListInfo: {
		Dest.Type = pStringType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, 0) - 1;
			if (nIndex >= pMercInfo->MercenaryCount || nIndex < 0)
				return false;

			std::vector<MercDesc> descs = GetAllMercDesc();
			if (nIndex < static_cast<int>(descs.size()))
			{
				strcpy_s(DataTypeTemp, descs[nIndex].Type.c_str());
				Dest.Ptr = &DataTypeTemp[0];
				Dest.Type = pStringType;
				return true;
			}
		}
		else
		{
			std::vector<MercDesc> descs = GetAllMercDesc();

			for (size_t index = 0; index < descs.size(); ++index)
			{
				auto& desc = descs[index];

				if (ci_equals(Index, desc.Type))
				{
					Dest.DWord = index + 1;
					Dest.Type = pIntType;
					return true;
				}
			}
		}
		return false;
	}

	case CharacterMembers::UseAdvancedLooting:
		Dest.DWord = pChar->UseAdvancedLooting;
		Dest.Type = pBoolType;
		return true;

	case CharacterMembers::SpellInCooldown:
		Dest.DWord = pDisplay->TimeStamp <= ((SPAWNINFO*)pLocalPlayer)->GetSpellCooldownETA();
		Dest.Type = pBoolType;
		return true;

	case CharacterMembers::AssistComplete:
		Dest.DWord = gbAssistComplete == AS_AssistReceived;
		Dest.Type = pBoolType;
		return true;

	case CharacterMembers::NumGems:
		Dest.DWord = 8;
		if (pCastSpellWnd)
		{
			char szWnd[32] = { 0 };
			for (int i = 8; i < NUM_SPELL_GEMS; i++)
			{
				sprintf_s(szWnd, "CSPW_Spell%d", i);
				if (CXWnd* wnd = pCastSpellWnd->GetChildItem(szWnd))
				{
					if (wnd->IsVisible() == 1)
					{
						Dest.DWord++;
					}
				}
			}
		}

		Dest.Type = pIntType;
		return true;

	case CharacterMembers::GuildID:
		Dest.UInt64 = pChar->GuildID;
		Dest.Type = pInt64Type;
		return true;

	case CharacterMembers::ExpansionFlags:
		Dest.DWord = pChar->ExpansionFlags;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::BoundLocation:
		Dest.DWord = 0;
		Dest.Type = pWorldLocationType;

		if (IsNumber(Index))
		{
			int index = GetIntFromString(Index, 0);
			if (index < 0)
				index = 0;
			if (index > 4)
				index = 4;
			Dest.DWord = index;
			return true;
		}
		return false;

	case CharacterMembers::AutoSkill:
		Dest.Type = pSkillType;
		if (IsNumber(Index))
		{
			int index = GetIntFromString(Index, 0) - 1;
			if (index < 0)
				index = 0;
			if (index > 1)
				index = 1;

			int skillid = gAutoSkill.Skill[index];
			if (skillid > 0 && skillid < NUM_SKILLS)
			{
				Dest.Ptr = &pSkillMgr->pSkill[skillid];
				return true;
			}
		}
		return false;

	case CharacterMembers::BaseSTR:
		Dest.Type = pIntType;
		Dest.DWord = pProfile->BaseSTR;
		return true;

	case CharacterMembers::BaseSTA:
		Dest.Type = pIntType;
		Dest.DWord = pProfile->BaseSTA;
		return true;

	case CharacterMembers::BaseAGI:
		Dest.Type = pIntType;
		Dest.DWord = pProfile->BaseAGI;
		return true;

	case CharacterMembers::BaseDEX:
		Dest.Type = pIntType;
		Dest.DWord = pProfile->BaseDEX;
		return true;

	case CharacterMembers::BaseWIS:
		Dest.Type = pIntType;
		Dest.DWord = pProfile->BaseWIS;
		return true;

	case CharacterMembers::BaseINT:
		Dest.Type = pIntType;
		Dest.DWord = pProfile->BaseINT;
		return true;

	case CharacterMembers::BaseCHA:
		Dest.Type = pIntType;
		Dest.DWord = pProfile->BaseCHA;
		return true;

	case CharacterMembers::Beneficial:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs([](EQ_Spell* spell) { return spell->SpellType != 0; }));
		return Dest.Int >= 0;

	case CharacterMembers::CursorKrono:
		Dest.DWord = pChar->CursorKrono;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::MercAAPoints:
		Dest.DWord = pChar->MercAAPoints;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::MercAAPointsSpent:
		Dest.DWord = pChar->MercAAPointsSpent;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Bandolier:
		Dest.DWord = 0;
		Dest.Type = pBandolierType;

		if (IsNumber(Index))
		{
			int index = GetIntFromString(Index, 0) - 1;
			if (index < 0)
				index = 0;
			if (index > 19)
				index = 19;

			Dest.DWord = index;
			return true;
		}
		else
		{
			for (int index = 0; index < MAX_BANDOLIER_ITEMS; index++)
			{
				if (!_stricmp(Index, pProfile->Bandolier[index].Name))
				{
					Dest.DWord = index;
					return true;
				}
			}
		}
		return false;

	case CharacterMembers::Feared:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(SpellAffect(SPA_FEAR, true)));
		return Dest.Int >= 0;

	case CharacterMembers::Silenced:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(SpellAffect(SPA_SILENCE, true)));
		return Dest.Int >= 0;

	case CharacterMembers::Invulnerable:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(SpellAffect(SPA_INVULNERABILITY, true)));
		return Dest.Int >= 0;

	case CharacterMembers::Dotted:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(AllBuffs(SpellAffect(SPA_HP, false),
			[](EQ_Spell* spell) { return spell->IsDetrimentalSpell() && spell->IsDoTSpell(); }));
		return Dest.Int >= 0;

	case CharacterMembers::ParcelStatus:
		Dest.DWord = pChar->ParcelStatus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CanMount:
		if (PlayerClient* pPlayer = pLocalPlayer)
		{
			Dest.DWord = 0;
			Dest.Type = pBoolType;

			if (pPlayer->HeadWet != 0 || pPlayer->Vehicle != nullptr)
				return true;

			int race = pPlayer->mActorClient.Race;

			// These non-player races can mount.
			if (race != EQR_SKELETON
				|| race != EQR_SKELETON_NEW
				|| race != EQR_OEQ_SKELETON
				|| race != EQR_SOL_SKELETON)
			{
				// FIXME: we can calculate this, don't need to look it up.
				// The -1 means "use the current race of the player"
				if (!pPlayer->LegalPlayerRace(-1))
					return true;
			}

			// TODO: Check that these need to be set. Then update or remove this comment.
			int zoneId = pWorldData->GetZoneBaseId(pPlayer->GetZoneID());
			if (zoneId == 151 /* bazaar */
				|| zoneId == 152 /* nexus */)
			{
				Dest.DWord = 1;
				return true;
			}

			// TODO: Check that these are correct. Then update or remove this comment.
			switch (pZoneInfo->OutDoor)
			{
			case IndoorDungeon:
			case IndoorCity:
			case DungeonCity:
				return true;
			default: break;
			}

			if (pWorldData->IsFlagSet(pPlayer->GetZoneID(), EQZoneFlag_NoMount))
				return true;

			// If we made it this far, we can mount.
			Dest.DWord = 1;
			return true;
		}
		return false;

	case CharacterMembers::SpellRankCap:
		Dest.DWord = 1;
		Dest.Type = pIntType;
		if (pCharData)
		{
			int value = pCharData->GetGameFeature(eSpellRankFeature);
			if (value == -1 || value >= 10)
				Dest.DWord = 3;
			else if (value >= 5)
				Dest.DWord = 2;
		}
		return true;

	case CharacterMembers::AbilityTimer:
		Dest.Type = pTimeStampType;
		Dest.Int64 = 0;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// numeric
				if (int nSkill = GetIntFromString(Index, 0))
				{
					if (bool bActivated = pCSkillMgr->IsActivatedSkill(nSkill))
					{
						int calcedduration = pSkillMgr->SkillTimerDuration[nSkill] - (EQGetTime() - pSkillMgr->SkillLastUsed[nSkill]);
						if (calcedduration < 0)
							calcedduration = 0;

						Dest.Int64 = calcedduration;
						return true;
					}
				}
				return false;
			}

			// name
			for (int nSkill = 0; nSkill < NUM_SKILLS; nSkill++)
			{
				int nToken = pCSkillMgr->GetNameToken(nSkill);
				const char* thename = pStringTable->getString(nToken);

				if (!thename || _stricmp(Index, thename) != 0)
					continue;

				// TODO: DRY - refactor duplicated code from above.
				if (bool bActivated = pCSkillMgr->IsActivatedSkill(nSkill))
				{
					int calcedduration = pSkillMgr->SkillTimerDuration[nSkill] - (EQGetTime() - pSkillMgr->SkillLastUsed[nSkill]);
					if (calcedduration < 0)
						calcedduration = 0;

					Dest.Int64 = calcedduration;
					return true;
				}

				return false;
			}
		}
		return false;

	case CharacterMembers::CastTimeLeft:
		Dest.Int64 = 0;
		Dest.Type = pTimeStampType;
		if (pLocalPlayer->CastingData.SpellETA)
		{
			int64_t delta = pLocalPlayer->CastingData.SpellETA - pLocalPlayer->TimeStamp;
			if (delta > 0)
			{
				Dest.Int64 = delta;
			}
		}
		return true;

	default:
		return false;
	}
}

bool MQ2CharacterType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (!pCharData)
		return false;

	CHARINFO* pCharInfo = static_cast<CHARINFO*>(pCharData);
	strcpy_s(Destination, MAX_STRING, pCharInfo->Name);
	return true;
}

bool MQ2CharacterType::FromData(MQVarPtr& VarPtr, MQTypeVar& Source)
{
	if (Source.Type != pCharacterType)
		return false;

	// there is only ever one Character pointer, and we don't own it, so
	// there is no point to storing it.
	VarPtr.Ptr = nullptr;
	return true;
}

bool MQ2CharacterType::dataCharacter(const char* szIndex, MQTypeVar& Ret)
{
	if (pCharData)
	{
		Ret.Ptr = nullptr;
		Ret.Type = pCharacterType;
		return true;
	}
	return false;
}

