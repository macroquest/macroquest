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
#include "MQ2DataTypes.h"

#include "MQ2Mercenaries.h"
#include "MQ2SpellSearch.h"

namespace mq::datatypes {

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
	FindBuff,
	Book,
	Skill,
	Ability,
	AbilityReady,
	AbilityTimer,
	AbilityTimerTotal,
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
	SharedBank,
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
	WarforgedEmblem,
	RestlessMark,
	ScarletMarks,
	MedalsOfConflict,
	ShadedSpecie,
	SpiritualMedallions,
	LaurionInnVoucher,
	ShalowainsPrivateReserve,
	LoyaltyTokens,
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
	VitalityCap,
	PctVitality,
	AAVitality,
	AAVitalityCap,
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
	CastTimeLeft,
	MaxLevel,
	AirSupply,
	MaxAirSupply,
	PctAirSupply,
	NumBagSlots,
	Inviter,
	Invited,
	IsBerserk,
	GroupLeaderExp,
	GroupLeaderPoints,
	PctGroupLeaderExp,
	RaidLeaderExp,
	RaidLeaderPoints,
	PctRaidLeaderExp,
	PersonaLevel,
	MembershipLevel,
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
	ScopedTypeMember(CharacterMembers, FindBuff);
	ScopedTypeMember(CharacterMembers, Book);
	ScopedTypeMember(CharacterMembers, Skill);
	ScopedTypeMember(CharacterMembers, Ability);
	ScopedTypeMember(CharacterMembers, AbilityReady);
	ScopedTypeMember(CharacterMembers, AbilityTimer);
	ScopedTypeMember(CharacterMembers, AbilityTimerTotal);
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
	ScopedTypeMember(CharacterMembers, SharedBank);
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
	ScopedTypeMember(CharacterMembers, WarforgedEmblem);
	ScopedTypeMember(CharacterMembers, RestlessMark);
	ScopedTypeMember(CharacterMembers, ScarletMarks);
	ScopedTypeMember(CharacterMembers, MedalsOfConflict);
	ScopedTypeMember(CharacterMembers, ShadedSpecie);
	ScopedTypeMember(CharacterMembers, SpiritualMedallions);
	ScopedTypeMember(CharacterMembers, LaurionInnVoucher);
	ScopedTypeMember(CharacterMembers, ShalowainsPrivateReserve);
	ScopedTypeMember(CharacterMembers, LoyaltyTokens);
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
	ScopedTypeMember(CharacterMembers, VitalityCap);
	ScopedTypeMember(CharacterMembers, PctVitality);
	ScopedTypeMember(CharacterMembers, AAVitality);
	ScopedTypeMember(CharacterMembers, AAVitalityCap);
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
	ScopedTypeMember(CharacterMembers, CastTimeLeft);
	ScopedTypeMember(CharacterMembers, MaxLevel);
	ScopedTypeMember(CharacterMembers, AirSupply);
	ScopedTypeMember(CharacterMembers, MaxAirSupply);
	ScopedTypeMember(CharacterMembers, PctAirSupply);
	ScopedTypeMember(CharacterMembers, NumBagSlots);
	ScopedTypeMember(CharacterMembers, Inviter);
	ScopedTypeMember(CharacterMembers, Invited);
	ScopedTypeMember(CharacterMembers, IsBerserk);
	ScopedTypeMember(CharacterMembers, GroupLeaderExp);
	ScopedTypeMember(CharacterMembers, GroupLeaderPoints);
	ScopedTypeMember(CharacterMembers, PctGroupLeaderExp);
	ScopedTypeMember(CharacterMembers, RaidLeaderExp);
	ScopedTypeMember(CharacterMembers, RaidLeaderPoints);
	ScopedTypeMember(CharacterMembers, PctRaidLeaderExp);
	ScopedTypeMember(CharacterMembers, PersonaLevel);
	ScopedTypeMember(CharacterMembers, MembershipLevel);

	ScopedTypeMethod(CharacterMethods, Stand);
	ScopedTypeMethod(CharacterMethods, Sit);
	ScopedTypeMethod(CharacterMethods, Dismount);
	ScopedTypeMethod(CharacterMethods, StopCast);
}

bool MQ2CharacterType::GetMember(MQVarPtr VarPtr, const char* Member, char* Index, MQTypeVar& Dest)
{
	if (!pLocalPC || !pLocalPlayer)
		return false;

	PcProfile* pProfile = GetPcProfile();
	if (!pProfile)
		return false;

	//------------------------------------------------------------------------
	// methods

	if (MQTypeMember* pMethod = MQ2CharacterType::FindMethod(Member))
	{
		switch (static_cast<CharacterMethods>(pMethod->ID))
		{
		case CharacterMethods::Stand:
			pEverQuest->InterpretCmd(pLocalPlayer, "/stand on");
			return true;

		case CharacterMethods::Sit:
			pEverQuest->InterpretCmd(pLocalPlayer, "/sit on");
			return true;

		case CharacterMethods::Dismount:
			pEverQuest->InterpretCmd(pLocalPlayer, "/dismount");
			return true;

		case CharacterMethods::StopCast:
			pEverQuest->InterpretCmd(pLocalPlayer, "/stopcast");
			return true;

		default: break;
		}

		return false;
	}

	MQTypeMember* pMember = MQ2CharacterType::FindMember(Member);
	if (!pMember)
	{
		// call into spawn type using our own spawn
		return pSpawnType->GetMember(pLocalPlayer, Member, Index, Dest);
	}

	switch (static_cast<CharacterMembers>(pMember->ID))
	{
	case CharacterMembers::Name:
		strcpy_s(DataTypeTemp, pLocalPlayer->Name);
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];
		return true;

	case CharacterMembers::Origin: {
		int startingCity = pLocalPC->GetStartingCity();
		if (startingCity > 0 && startingCity < MAX_ZONES)
		{
			Dest.Type = pZoneType;
			Dest.Ptr = pWorldData->ZoneArray[startingCity];
			return true;
		}
		return false;
	}

	case CharacterMembers::SubscriptionDays:
		Dest.Int = pLocalPC->SubscriptionDays;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Exp:
		Dest.Int64 = pLocalPC->Exp;
		Dest.Type = pInt64Type;
		return true;

	case CharacterMembers::PctExp:
		Dest.Float = (float)pLocalPC->Exp / EXP_TO_PCT_RATIO;
		Dest.Type = pFloatType;
		return true;

	case CharacterMembers::PctExpToAA:
		Dest.Int = (int)pLocalPC->PercentEXPtoAA;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::PctAAExp:
		Dest.Float = (float)pLocalPC->AAExp / EXP_TO_PCT_RATIO;
		Dest.Type = pFloatType;
		return true;

	case CharacterMembers::Vitality:
		Dest.Int64 = pLocalPC->Vitality;
		Dest.Type = pInt64Type;
		return true;

	case CharacterMembers::VitalityCap:
		Dest.Int64 = pInventoryWnd->VitalityCap;
		Dest.Type = pInt64Type;
		return true;

	case CharacterMembers::PctVitality: {
		Dest.Float = 0;
		Dest.Type = pFloatType;
		int64_t vitality = pLocalPC->Vitality;
		int64_t cap = pInventoryWnd->VitalityCap;
		if (vitality > cap)
			vitality = cap;
		if (cap > 0)
			Dest.Float = (float)vitality * 100 / cap;
		return true;
	}

	case CharacterMembers::AAVitality:
		Dest.Int64 = pLocalPC->AAVitality;
		Dest.Type = pInt64Type;
		return true;

	case CharacterMembers::AAVitalityCap:
		Dest.Int64 = pInventoryWnd->AAVitalityCap;
		Dest.Type = pInt64Type;
		return true;

	case CharacterMembers::PctAAVitality: {
		Dest.Float = 0;
		Dest.Type = pFloatType;
		int64_t aavitality = pLocalPC->AAVitality;
		int aacap = pInventoryWnd->AAVitalityCap;
		if (aavitality > aacap)
			aavitality = aacap;
		if (aacap > 0)
			Dest.Float = (float)aavitality * 100 / aacap;
		return true;
	}

	case CharacterMembers::Spawn:
		Dest = pSpawnType->MakeTypeVar(pLocalPlayer);
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

		for (int i = 0; i < NUM_LONG_BUFFS; ++i)
		{
			if (pProfile->GetEffect(i).SpellID > 0)
				Dest.DWord++;
		}
		return true;

	case CharacterMembers::CountSongs:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		for (int i = 0; i < NUM_SHORT_BUFFS; ++i)
		{
			if (pProfile->GetTempEffect(i).SpellID > 0)
				Dest.DWord++;
		}
		return true;

	case CharacterMembers::BlockedPetBuff:
	case CharacterMembers::BlockedBuff: {
		Dest.Type = pSpellType;
		if (!Index[0])
			return false;

		// TODO:  Move this into a function for both BlockedPetBuff and BlockedBuff
		int iMaxBlockedSpells = (static_cast<CharacterMembers>(pMember->ID) == CharacterMembers::BlockedBuff ? MAX_BLOCKED_SPELLS : MAX_BLOCKED_SPELLS_PET);
		if (IsNumber(Index))
		{
			int nBuff = GetIntFromString(Index, iMaxBlockedSpells + 2) - 1;
			if (nBuff < 0)
				nBuff = 0;
			if (nBuff > iMaxBlockedSpells)
				return false;

			if (int spellId = (static_cast<CharacterMembers>(pMember->ID) == CharacterMembers::BlockedBuff) ? pLocalPC->BlockedSpell[nBuff] : pLocalPC->BlockedPetSpell[nBuff])
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
				if (int spellId = (static_cast<CharacterMembers>(pMember->ID) == CharacterMembers::BlockedBuff) ? pLocalPC->BlockedSpell[i] : pLocalPC->BlockedPetSpell[i])
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
		return false;
	}

	// TODO:  Move this to a function for both Buff and Song since code is identical except for Short vs Long Buff.
	case CharacterMembers::Buff:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_BuffWnd;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nBuff = GetIntFromString(Index, 0) - 1;
			if (nBuff < 0 || nBuff > NUM_LONG_BUFFS)
				return false;

			Dest.Int = nBuff;
			return true;
		}

		{
			int buffID = FindBuffIndex(Index, 0, NUM_LONG_BUFFS);
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
			if (nBuff < 0 || nBuff >= NUM_SHORT_BUFFS)
				return false;

			Dest.Int = nBuff + NUM_LONG_BUFFS;
			return true;
		}

		{
			int buffID = FindBuffIndex(Index, NUM_LONG_BUFFS, MAX_TOTAL_BUFFS);
			if (buffID >= NUM_LONG_BUFFS && buffID < MAX_TOTAL_BUFFS)
			{
				Dest.Int = buffID;
				return true;
			}
		}

		return false;

	case CharacterMembers::FindBuff:
	{
		if (!Index[0])
			return false;

		Dest.Type = pBuffType;

		auto attrib = EvaluateBuffPredicate(Index);
		int buff = GetSelfBuff([&attrib](const EQ_Affect& buff)
			{
				return attrib(buff);
			});

		if (buff < 0)
			return false;

		Dest.Int = buff;
		if (buff >= NUM_LONG_BUFFS)
			Dest.HighPart = SpellDisplayType_None;
		else
			Dest.HighPart = SpellDisplayType_BuffWnd;

		return true;
	}

	case CharacterMembers::HPBonus:
		Dest.DWord = pLocalPC->HPBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::ManaBonus:
		Dest.DWord = pLocalPC->ManaBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::EnduranceBonus:
		Dest.DWord = pLocalPC->EnduranceBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CombatEffectsBonus: {
		int CombatEffectsCap = GetModCap(HEROIC_MOD_COMBAT_EFFECTS);
		Dest.DWord = (pLocalPC->CombatEffectsBonus > CombatEffectsCap ? CombatEffectsCap : pLocalPC->CombatEffectsBonus);
		Dest.Type = pIntType;
		return true;
	}

	case CharacterMembers::ShieldingBonus: {
		int ShieldingCap = GetModCap(HEROIC_MOD_MELEE_SHIELDING);
		Dest.DWord = (pLocalPC->ShieldingBonus > ShieldingCap ? ShieldingCap : pLocalPC->ShieldingBonus);
		Dest.Type = pIntType;
		return true;
	}

	case CharacterMembers::SpellShieldBonus: {
		int SpellShieldCap = GetModCap(HEROIC_MOD_SPELL_SHIELDING);
		Dest.DWord = (pLocalPC->SpellShieldBonus > SpellShieldCap ? SpellShieldCap : pLocalPC->SpellShieldBonus);
		Dest.Type = pIntType;
		return true;
	}

	case CharacterMembers::AvoidanceBonus: {
		int AvoidanceCap = GetModCap(HEROIC_MOD_AVOIDANCE);
		Dest.DWord = (pLocalPC->AvoidanceBonus > AvoidanceCap ? AvoidanceCap : pLocalPC->AvoidanceBonus);
		Dest.Type = pIntType;
		return true;
	}

	case CharacterMembers::AccuracyBonus: {
		int AccuracyCap = GetModCap(HEROIC_MOD_ACCURACY);
		Dest.DWord = (pLocalPC->AccuracyBonus > AccuracyCap ? AccuracyCap : pLocalPC->AccuracyBonus);
		Dest.Type = pIntType;
		return true;
	}

	case CharacterMembers::StunResistBonus: {
		int StunResistCap = GetModCap(HEROIC_MOD_STUN_RESIST);
		Dest.DWord = (pLocalPC->StunResistBonus > StunResistCap ? StunResistCap : pLocalPC->StunResistBonus);
		Dest.Type = pIntType;
		return true;
	}

	case CharacterMembers::StrikeThroughBonus: {
		int StrikeThroughCap = GetModCap(HEROIC_MOD_STRIKETHROUGH);
		Dest.DWord = (pLocalPC->StrikeThroughBonus > StrikeThroughCap ? StrikeThroughCap : pLocalPC->StrikeThroughBonus);
		Dest.Type = pIntType;
		return true;
	}

	case CharacterMembers::DoTShieldBonus: {
		int DoTShieldCap = GetModCap(HEROIC_MOD_DOT_SHIELDING);
		Dest.DWord = (pLocalPC->DoTShieldBonus > DoTShieldCap ? DoTShieldCap : pLocalPC->DoTShieldBonus);
		Dest.Type = pIntType;
		return true;
	}

	case CharacterMembers::AttackBonus:
		Dest.DWord = pLocalPC->AttackBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::HPRegenBonus:
		Dest.DWord = pLocalPC->HPRegenBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::ManaRegenBonus:
		Dest.DWord = pLocalPC->ManaRegenBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::DamageShieldBonus: {
		Dest.DWord = std::min(pLocalPC->GetDamageShieldBonus(), GetModCap(HEROIC_MOD_DAMAGE_SHIELDING));
		Dest.Type = pIntType;
		return true;
	}

	case CharacterMembers::DamageShieldMitigationBonus: {
		int DamageShieldMitigationCap = GetModCap(HEROIC_MOD_DAMAGE_SHIELD_MITIG);
		Dest.DWord = (pLocalPC->DamageShieldMitigationBonus > DamageShieldMitigationCap ? DamageShieldMitigationCap : pLocalPC->DamageShieldMitigationBonus);
		Dest.Type = pIntType;
		return true;
	}

	case CharacterMembers::HeroicSTRBonus:
		Dest.DWord = pLocalPC->HeroicSTRBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::HeroicINTBonus:
		Dest.DWord = pLocalPC->HeroicINTBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::HeroicWISBonus:
		Dest.DWord = pLocalPC->HeroicWISBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::HeroicAGIBonus:
		Dest.DWord = pLocalPC->HeroicAGIBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::HeroicDEXBonus:
		Dest.DWord = pLocalPC->HeroicDEXBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::HeroicSTABonus:
		Dest.DWord = pLocalPC->HeroicSTABonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::HeroicCHABonus:
		Dest.DWord = pLocalPC->HeroicCHABonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::HealAmountBonus:
		Dest.DWord = pLocalPC->HealAmountBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::SpellDamageBonus:
		Dest.DWord = pLocalPC->SpellDamageBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::ClairvoyanceBonus:
		Dest.DWord = pLocalPC->ClairvoyanceBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::EnduranceRegenBonus:
		Dest.DWord = pLocalPC->EnduranceRegenBonus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::AttackSpeed:
		Dest.DWord = pLocalPC->AttackSpeed;
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
		Dest.DWord = pLocalPC->AdventureData.ThemeStats[eAT_DeepGuk].AdventureTotalPointsEarned;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::MMEarned:
		Dest.DWord = pLocalPC->AdventureData.ThemeStats[eAT_Mistmoore].AdventureTotalPointsEarned;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::RujEarned:
		Dest.DWord = pLocalPC->AdventureData.ThemeStats[eAT_Rujarkian].AdventureTotalPointsEarned;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::TakEarned:
		Dest.DWord = pLocalPC->AdventureData.ThemeStats[eAT_Takish].AdventureTotalPointsEarned;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::MirEarned:
		Dest.DWord = pLocalPC->AdventureData.ThemeStats[eAT_Miraguls].AdventureTotalPointsEarned;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LDoNPoints:
		Dest.DWord = pLocalPC->AdventureData.AdventurePointsAvailable;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CurrentFavor:
		Dest.Int64 = pLocalPC->CurrFavor;
		Dest.Type = pInt64Type;
		return true;

	case CharacterMembers::CareerFavor:
		Dest.Int64 = pLocalPC->CareerFavor;
		Dest.Type = pInt64Type;
		return true;

	case CharacterMembers::Inventory:
		Dest.Type = pItemType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int nSlot = GetIntFromString(Index, NUM_INV_SLOTS);
				if (nSlot >= 0 && nSlot < NUM_INV_SLOTS)
				{
					Dest = pItemType->MakeTypeVar(pProfile->GetInventorySlot(nSlot));
					return true;
				}
			}
			else
			{
				for (int nSlot = 0; szItemSlot[nSlot]; nSlot++)
				{
					if (!_stricmp(Index, szItemSlot[nSlot]))
					{
						Dest = pItemType->MakeTypeVar(pProfile->GetInventorySlot(nSlot));
						return true;
					}
				}
			}
		}

		// return null item type
		return true;

	case CharacterMembers::Bank:
		Dest.Type = pItemType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int nSlot = GetIntFromString(Index, 0) - 1;
				if (nSlot < 0)
					return true;

				if (nSlot < GetAvailableBankSlots())
				{
					Dest = pItemType->MakeTypeVar(pLocalPC->BankItems.GetItem(nSlot));
					return true;
				}

				if (nSlot >= NUM_BANK_SLOTS)
				{
					nSlot -= NUM_BANK_SLOTS;

					Dest = pItemType->MakeTypeVar(pLocalPC->SharedBankItems.GetItem(nSlot));
					return true;
				}
			}
		}

		// return null item type
		return true;

	case CharacterMembers::SharedBank:
		Dest.Type = pItemType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int nSlot = GetIntFromString(Index, 0) - 1;
				if (nSlot >= 0 && nSlot < GetAvailableSharedBankSlots())
				{
					Dest = pItemType->MakeTypeVar(pLocalPC->SharedBankItems.GetItem(nSlot));
					return true;
				}
			}
		}

		// return null item type
		return true;

	case CharacterMembers::PlatinumShared:
		Dest.DWord = pLocalPC->BankSharedPlat;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Cash:
		Dest.Int64 = pLocalPC->GetTotalCash();
		Dest.Type = pInt64Type;
		return true;

	case CharacterMembers::Platinum:
		Dest.DWord = pLocalPC->GetPlatinum();
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CursorPlatinum:
		Dest.DWord = pProfile->CursorPlat;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Gold:
		Dest.DWord = pLocalPC->GetGold();
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CursorGold:
		Dest.DWord = pProfile->CursorGold;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Silver:
		Dest.DWord = pLocalPC->GetSilver();
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CursorSilver:
		Dest.DWord = pProfile->CursorSilver;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Copper:
		Dest.DWord = pLocalPC->GetCopper();
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CursorCopper:
		Dest.DWord = pProfile->CursorCopper;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CashBank:
		Dest.Int64 = static_cast<uint64_t>(pLocalPC->BankPlat) * 1000
			+ static_cast<uint64_t>(pLocalPC->BankGold) * 100
			+ static_cast<uint64_t>(pLocalPC->BankSilver) * 10
			+ pLocalPC->BankCopper;
		Dest.Type = pInt64Type;
		return true;

	case CharacterMembers::PlatinumBank:
		Dest.DWord = pLocalPC->BankPlat;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::GoldBank:
		Dest.DWord = pLocalPC->BankGold;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::SilverBank:
		Dest.DWord = pLocalPC->BankSilver;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CopperBank:
		Dest.DWord = pLocalPC->BankCopper;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::AAExp:
		Dest.DWord = pLocalPC->AAExp;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::AAPoints:
		Dest.DWord = pProfile->AAPoints;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Combat:
		Dest.Set(pEverQuestInfo->bAutoAttack);
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
		if (pLocalPC->Group)
			Dest.Set(pLocalPC->Group->GetNumberOfMembers() > 1);
		else
			Dest.Set(false);
		return true;

	case CharacterMembers::GroupList: { // This isn't really working as intended just yet
		Dest.Type = pStringType;
		if (!pLocalPC->Group)
			return false;

		for (int i = 1; i < MAX_GROUP_SIZE; i++)
		{
			if (CGroupMember* pMember = pLocalPC->Group->GetGroupMember(i))
			{
				strcpy_s(DataTypeTemp, pMember->GetName());
				if ((i < MAX_GROUP_SIZE - 1) && pLocalPC->Group->GetGroupMember(i + 1))
					strcat_s(DataTypeTemp, " ");
			}
		}
		Dest.Ptr = &DataTypeTemp[0];
		return true;
	}

	case CharacterMembers::AmIGroupLeader:
		Dest.Type = pBoolType;
		Dest.DWord = pLocalPC->Group != nullptr && pLocalPC->Group->IsGroupLeader(pLocalPC->me);
		return true;

	case CharacterMembers::MaxBuffSlots:
		Dest.DWord = GetCharMaxBuffSlots();
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::FreeBuffSlots:
		Dest.DWord = GetCharMaxBuffSlots();
		Dest.Type = pIntType;

		for (int i = 0; i < NUM_LONG_BUFFS; ++i)
		{
			if (pProfile->GetEffect(i).SpellID > 0)
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
			// Decremeting the given ID by 1 to get zero based index for pulling skill from languages array
			nLang = GetIntFromString(Index, nLang) - 1;
		}
		else
		{
			// Grabbing ID by Name and decremeting ID by 1 to get zero based index for pulling skill from languages array
			nLang = GetLanguageIDByName(Index) - 1;
		}

		if (nLang < 0 || nLang >= 27)
			return false;

		Dest.DWord = pLocalPC->languages[nLang];
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
					if (SPELL* pSpell = GetSpellByID(pLocalPC->GetCombatAbility(nCombatAbility)))
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
			for (int nCombatAbility = 0; nCombatAbility < NUM_COMBAT_ABILITIES; nCombatAbility++)
			{
				if (pCombatSkillsSelectWnd->ShouldDisplayThisSkill(nCombatAbility))
				{
					if (SPELL* pSpell = GetSpellByID(pLocalPC->GetCombatAbility(nCombatAbility)))
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
						if (SPELL* pSpell = GetSpellByID(pLocalPC->GetCombatAbility(nCombatAbility)))
						{
							uint32_t timeNow = static_cast<uint32_t>(time(nullptr));

							if (pLocalPC->GetCombatAbilityTimer(pSpell->ReuseTimerIndex, pSpell->SpellGroup) > timeNow)
							{
								Dest.Int = pLocalPC->GetCombatAbilityTimer(pSpell->ReuseTimerIndex, pSpell->SpellGroup) - timeNow + 6;
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
						if (SPELL* pSpell = GetSpellByID(pLocalPC->GetCombatAbility(nCombatAbility)))
						{
							if (!_stricmp(Index, pSpell->Name))
							{
								uint32_t timeNow = static_cast<uint32_t>(time(nullptr));
								uint32_t timer = pLocalPC->GetCombatAbilityTimer(pSpell->ReuseTimerIndex, pSpell->SpellGroup);

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
		Dest.Set(false);
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
						if (SPELL* pSpell = GetSpellByID(pLocalPC->GetCombatAbility(nCombatAbility)))
						{
							uint32_t timeNow = static_cast<uint32_t>(time(nullptr));
							uint32_t timer = pLocalPC->GetCombatAbilityTimer(pSpell->ReuseTimerIndex, pSpell->SpellGroup);

							if (timer < timeNow)
							{
								Dest.Set(true);
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
						if (SPELL* pSpell = GetSpellByID(pLocalPC->GetCombatAbility(nCombatAbility)))
						{
							if (!_stricmp(Index, pSpell->Name))
							{
								uint32_t timeNow = static_cast<uint32_t>(time(nullptr));
								uint32_t timer = pLocalPC->GetCombatAbilityTimer(pSpell->ReuseTimerIndex, pSpell->SpellGroup);

								if (timer < timeNow)
								{
									Dest.Set(true);
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
		// FIXME: Use pControlledPlayer - there are edge cases with Eye of Zomm and pControlledPlayer that would change
		//        also look at an edge case where you are levitating in water but not moving
		Dest.Set(
			((gbMoving
				&& (pLocalPlayer->SpeedRun == 0.0f)
				&& (pLocalPlayer->Mount == nullptr))
			|| (FindSpeed(pLocalPlayer) != 0.0f)));
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
				int aaId = GetIntFromString(Index, 0);

				if (CAltAbilityData* pAbility = pAltAdvManager->GetOwnedAbilityFromGroupID(pLocalPC, aaId))
				{
					int reusetimer = 0;
					pAltAdvManager->IsAbilityReady(pLocalPC, pAbility, &reusetimer);
					if (reusetimer < 0)
					{
						reusetimer = 0;
					}

					Dest.UInt64 = reusetimer * 1000;
					return true;
				}
			}
			else
			{
				// by name so we ned to take level into account
				int level = pLocalPlayer->Level;

				for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
				{
					if (CAltAbilityData* pAbility = GetAAById(pLocalPC->GetAlternateAbilityId(nAbility), level))
					{
						if (const char* pName = pDBStr->GetString(pAbility->nName, eAltAbilityName))
						{
							if (!_stricmp(Index, pName))
							{
								int reusetimer = 0;
								pAltAdvManager->IsAbilityReady(pLocalPC, pAbility, &reusetimer);
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
		Dest.Set(false);
		Dest.Type = pBoolType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				// numeric
				for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
				{
					if (CAltAbilityData* pAbility = GetAAById(pLocalPC->GetAlternateAbilityId(nAbility)))
					{
						if (pAbility->ID == GetIntFromString(Index, 0))
						{
							if (pAbility->SpellID != -1)
								Dest.Set(pAltAdvManager->IsAbilityReady(pLocalPC, pAbility, nullptr));

							return true;
						}
					}
				}
			}
			else
			{
				// by name so we need to take their level into account
				int level = pLocalPlayer->Level;

				for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
				{
					if (CAltAbilityData* pAbility = GetAAById(pLocalPC->GetAlternateAbilityId(nAbility), level))
					{
						if (const char* pName = pDBStr->GetString(pAbility->nName, eAltAbilityName))
						{
							if (!_stricmp(Index, pName))
							{
								if (pAbility->SpellID != -1)
									Dest.Set(pAltAdvManager->IsAbilityReady(pLocalPC, pAbility, nullptr));

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
				int aaId = GetIntFromString(Index, 0);

				if (CAltAbilityData* pAbility = pAltAdvManager->GetOwnedAbilityFromGroupID(pLocalPC, aaId))
				{
					Dest.Ptr = pAbility;
					return true;
				}
			}
			else
			{
				// by name so we need to take their level into account
				int level = pLocalPlayer->Level;

				for (int nAbility = 0; nAbility < AA_CHAR_MAX_REAL; nAbility++)
				{
					if (CAltAbilityData* pAbility = GetAAById(pLocalPC->GetAlternateAbilityId(nAbility), level))
					{
						if (const char* pName = pDBStr->GetString(pAbility->nName, eAltAbilityName))
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
				if (pLocalPC)
				{
					Dest.DWord = pLocalPC->GetPcSkillLimit(nSkill);
					return true;
				}
			}
		}
		return false;

	case CharacterMembers::Ability:
	{
		Dest.Type = pBoolType;
		Dest.Set(false);
		int nSkill = GetAbilityIDFromString(Index, -1);
		if (nSkill != -1)
		{
			Dest.Set(HasSkillOrInnate(nSkill));
		}
		return true;
	}

	case CharacterMembers::AbilityReady:
	{
		Dest.Type = pBoolType;
		Dest.Set(false);
		int nSkill = GetAbilityIDFromString(Index, -1);
		if (nSkill != -1 && HasSkillOrInnate(nSkill))
		{
			Dest.Set(pSkillMgr->IsAvailable(nSkill));
		}
		return true;
	}

	case CharacterMembers::AbilityTimer:
	{
		Dest.Type = pTimeStampType;
		Dest.Int64 = 0;
		int nSkill = GetAbilityIDFromString(Index, -1);
		if (nSkill != -1)
		{
			if (HasSkillOrInnate(nSkill))
			{
				int timer = pSkillMgr->GetSkillTimerDuration(nSkill) - (EQGetTime() - pSkillMgr->GetSkillLastUsed(nSkill));
				if (timer < 0)
					timer = 0;
				Dest.Int64 = timer;
			}
			return true;
		}
		return false;
	}

	case CharacterMembers::AbilityTimerTotal:
	{
		Dest.Type = pTimeStampType;
		Dest.Int64 = 0;

		int nSkill = GetAbilityIDFromString(Index, -1);
		if (nSkill != -1)
		{
			Dest.Int64 = pSkillMgr->GetSkillTimerDuration(nSkill);
		}
		return true;
	}

	case CharacterMembers::RangedReady:
		Dest.Set(pEverQuestInfo->PrimaryAttackReady != 0);
		Dest.Type = pBoolType;
		return true;

	case CharacterMembers::AltTimerReady:
		Dest.Set(true); // this is broken and should be fixed or removed.
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
		Dest.Set(false);
		Dest.Type = pBoolType;
		ItemClient* pCont = nullptr;

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
				if (ItemDefinition* pIteminf = GetItemFromContents(pCont))
				{
					if (pIteminf->Clicky.TimerID != -1)
					{
						uint32_t timer = GetItemTimer(pCont);
						if (timer == 0)
							Dest.Set(true);
					}
					else if (pIteminf->Clicky.SpellID != -1)
					{
						Dest.Set(true); // insta-click or instant recast
					}
				}
			}
		}
		return true;
	}

	case CharacterMembers::BardSongPlaying:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (pCastSpellWnd && pCastSpellWnd->IsBardSongPlaying())
		{
			Dest.Set(true);
		}
		return true;

	case CharacterMembers::SpellReady:
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (pCastingWnd && pCastingWnd->IsVisible())
		{
			return true;
		}

		if (pCastSpellWnd && pCastSpellWnd->IsBardSongPlaying())
		{
			Dest.Set(true);
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
					if (pDisplay->TimeStamp > pLocalPlayer->SpellGemETA[nGem]
						&& pDisplay->TimeStamp > pLocalPlayer->GetSpellCooldownETA())
					{
						Dest.Set(true);
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
							if (pDisplay->TimeStamp > pLocalPlayer->SpellGemETA[nGem]
								&& pDisplay->TimeStamp > pLocalPlayer->GetSpellCooldownETA())
							{
								Dest.Set(true);
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
			if (nBuff < 0 || nBuff >= pPetInfoWnd->GetMaxBuffs())
				return false;

			if (pPetInfoWnd->GetBuff(nBuff) == -1 || pPetInfoWnd->GetBuff(nBuff) == 0)
				return false;

			if (Dest.Ptr = GetSpellByID(pPetInfoWnd->GetBuff(nBuff)))
			{
				Dest.Type = pSpellType;
				return true;
			}
		}
		else
		{
			for (int nBuff = 0; nBuff < pPetInfoWnd->GetMaxBuffs(); nBuff++)
			{
				if (SPELL* pSpell = GetSpellByID(pPetInfoWnd->GetBuff(nBuff)))
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
		Dest.Set(pLocalPC->Stunned == 1);
		Dest.Type = pBoolType;
		return true;

	case CharacterMembers::LargestFreeInventory:
	{
		Dest.DWord = ItemSize_Tiny;
		Dest.Type = pIntType;

		for (int slot = InvSlot_Bag1; slot < GetHighestAvailableBagSlot(); slot++)
		{
			if (ItemPtr pItem = pProfile->InventoryContainer.GetItem(slot))
			{
				ItemDefinition* itemDef = pItem->GetItemDefinition();
				if (itemDef->Type == ITEMTYPE_PACK
					&& itemDef->SizeCapacity > Dest.DWord)
				{
					// Check if the container has a free slot.
					if (!pItem->GetChildItemContainer()->IsFull())
					{
						Dest.DWord = itemDef->SizeCapacity;
						return true;
					}
				}
			}
			else
			{
				// Its an empty slot, we can hold the largest size things here...
				Dest.DWord = ItemSize_Giant;
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
			if (nSize > ItemSize_Giant)
				nSize = ItemSize_Giant;
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
		Dest = pSpawnType->MakeTypeVar(GetSpawnByID(pLocalPlayer->TargetOfTarget));
		return true;

	case CharacterMembers::RaidAssistTarget:
		if (Index[0] && IsNumber(Index))
		{
			int index = GetIntFromString(Index, 0) - 1;
			Dest = pSpawnType->MakeTypeVar(GetSpawnByID(GetRaidMainAssistTargetID(index)));
			return true;
		}

		Dest = pSpawnType->MakeTypeVar();
		return true;

	case CharacterMembers::GroupAssistTarget:
		Dest = pSpawnType->MakeTypeVar(GetSpawnByID(GetGroupMainAssistTargetID()));
		return true;

	case CharacterMembers::RaidMarkNPC:
		if (Index[0] && IsNumber(Index))
		{
			int index = GetIntFromString(Index, 0) - 1;
			Dest = pSpawnType->MakeTypeVar(GetSpawnByID(GetRaidMarkedTargetID(index)));
			return true;
		}

		Dest = pSpawnType->MakeTypeVar();
		return true;

	case CharacterMembers::GroupMarkNPC:
		if (Index[0] && IsNumber(Index))
		{
			int index = GetIntFromString(Index, 0) - 1;
			Dest = pSpawnType->MakeTypeVar(GetSpawnByID(GetGroupMarkedTargetID(index)));
			return true;
		}

		Dest = pSpawnType->MakeTypeVar();
		return true;

	case CharacterMembers::STR:
		Dest.DWord = pLocalPC->GetStrength();
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::STA:
		Dest.DWord = pLocalPC->GetStamina();
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::AGI:
		Dest.DWord = pLocalPC->GetAgility();
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::DEX:
		Dest.DWord = pLocalPC->GetDexterity();
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::WIS:
		Dest.DWord = pLocalPC->GetWisdom();
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::INT:
		Dest.DWord = pLocalPC->GetIntelligence();
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CHA:
		Dest.DWord = pLocalPC->GetCharisma();
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LCK:
		Dest.DWord = pLocalPC->GetLuck();
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::svMagic:
		Dest.DWord = pLocalPC->SaveMagic;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::svFire:
		Dest.DWord = pLocalPC->SaveFire;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::svCold:
		Dest.DWord = pLocalPC->SaveCold;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::svPoison:
		Dest.DWord = pLocalPC->SavePoison;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::svDisease:
		Dest.DWord = pLocalPC->SaveDisease;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CurrentWeight:
		Dest.DWord = pLocalPC->CurrWeight;
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
		Dest.Set(*pTributeActive != 0);
		Dest.Type = pBoolType;
		return true;

	case CharacterMembers::Running:
		Dest.Set(pEverQuestInfo->RunMode != 0);
		Dest.Type = pBoolType;
		return true;

	case CharacterMembers::GroupSize:
		Dest.Type = pIntType;
		Dest.DWord = (pLocalPC->Group ? pLocalPC->Group->GetNumberOfMembersExcludingSelf() : 0);

		// if we have at least one other group member, count self.
		if (Dest.DWord)
			Dest.DWord++;
		return true;

	case CharacterMembers::TributeTimer:
		Dest.DWord = pLocalPC->TributeTimer / 60 / 100;
		Dest.Type = pTicksType;
		return true;

	case CharacterMembers::RadiantCrystals:
		Dest.DWord = pLocalPC->RadiantCrystals;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::EbonCrystals:
		Dest.DWord = pLocalPC->EbonCrystals;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Shrouded:
		Dest.Set(pProfile->Shrouded != 0);
		Dest.Type = pBoolType;
		return true;

	case CharacterMembers::AutoFire:
		Dest.Set(pEverQuestInfo->bAutoRangeAttack != 0);
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
			// Decremeting the given ID by 1 to get zero based index for GetLangDesc
			nLang = GetIntFromString(Index, 0) - 1;
			if (nLang < 0 || nLang >= 27)
				return false;
			strcpy_s(DataTypeTemp, pEverQuest->GetLangDesc(nLang));
			Dest.Ptr = &DataTypeTemp[0];
			Dest.Type = pStringType;
			return true;
		}
		else
		{
			// Not decrementing as we are returning the ID by Name
			nLang = GetLanguageIDByName(Index);
		}

		if (nLang < 0 || nLang >= 27)
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
				int n = GetIntFromString(Index, 0) - 1;
				if (n < 0 || n >= pAuraMgr->Auras.GetLength())
					return false;
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
#if HAS_LEADERSHIP_EXPERIENCE
		Dest.DWord = pLocalPC->ActiveAbilities.MarkNPC;
#else
		Dest.DWord = 3;
#endif
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LANPCHealth:
#if HAS_LEADERSHIP_EXPERIENCE
		Dest.DWord = pLocalPC->ActiveAbilities.NPCHealth;
#else
		Dest.DWord = 1;
#endif
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LADelegateMA:
#if HAS_LEADERSHIP_EXPERIENCE
		Dest.DWord = pLocalPC->ActiveAbilities.DelegateMA;
#else
		Dest.DWord = 1;
#endif
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LADelegateMarkNPC:
#if HAS_LEADERSHIP_EXPERIENCE
		Dest.DWord = pLocalPC->ActiveAbilities.DelegateMarkNPC;
#else
		Dest.DWord = 1;
#endif
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LAInspectBuffs:
#if HAS_LEADERSHIP_EXPERIENCE
		Dest.DWord = pLocalPC->ActiveAbilities.InspectBuffs;
#else
		Dest.DWord = 2;
#endif
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LASpellAwareness:
#if HAS_LEADERSHIP_EXPERIENCE
		Dest.DWord = pLocalPC->ActiveAbilities.SpellAwareness;
#else
		Dest.DWord = 1;
#endif
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LAOffenseEnhancement:
#if HAS_LEADERSHIP_EXPERIENCE
		Dest.DWord = pLocalPC->ActiveAbilities.OffenseEnhancement;
#else
		Dest.DWord = 5;
#endif
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LAManaEnhancement:
#if HAS_LEADERSHIP_EXPERIENCE
		Dest.DWord = pLocalPC->ActiveAbilities.ManaEnhancement;
#else
		Dest.DWord = 3;
#endif
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LAHealthEnhancement:
#if HAS_LEADERSHIP_EXPERIENCE
		Dest.DWord = pLocalPC->ActiveAbilities.HealthEnhancement;
#else
		Dest.DWord = 3;
#endif
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LAHealthRegen:
#if HAS_LEADERSHIP_EXPERIENCE
		Dest.DWord = pLocalPC->ActiveAbilities.HealthRegen;
#else
		Dest.DWord = 3;
#endif
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LAFindPathPC:
#if HAS_LEADERSHIP_EXPERIENCE
		Dest.DWord = pLocalPC->ActiveAbilities.FindPathPC;
#else
		Dest.DWord = 1;
#endif
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LAHoTT:
#if HAS_LEADERSHIP_EXPERIENCE
		Dest.DWord = pLocalPC->ActiveAbilities.HoTT;
#else
		Dest.DWord = 1;
#endif
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::ActiveFavorCost:
		Dest.Int = 0;
		Dest.Type = pIntType;
		if (*pTributeActive)
		{
			Dest.Int = pTribute->GetActiveFavorCost();
			return true;
		}
		return false;

	case CharacterMembers::CombatState:
		Dest.Type = pStringType;
		Dest.Ptr = &DataTypeTemp[0];

		switch (GetCombatState())
		{
		case eCombatState_Combat:
			strcpy_s(DataTypeTemp, "COMBAT");
			break;

		case eCombatState_Debuff:
			strcpy_s(DataTypeTemp, "DEBUFFED");
			break;

		case eCombatState_Timer:
			strcpy_s(DataTypeTemp, "COOLDOWN");
			break;

		case eCombatState_Regen:
			strcpy_s(DataTypeTemp, "RESTING");
			break;

		case eCombatState_Standing:
		default:
			strcpy_s(DataTypeTemp, "ACTIVE");
			break;
		}

		return true;

	case CharacterMembers::svCorruption:
		Dest.DWord = pLocalPC->SaveCorruption;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::svPrismatic:
		Dest.DWord = (pLocalPC->SaveMagic + pLocalPC->SaveFire + pLocalPC->SaveCold + pLocalPC->SavePoison + pLocalPC->SaveDisease) / 5;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::svChromatic:
		Dest.Int = std::min({ pLocalPC->SaveMagic,
			pLocalPC->SaveFire,
			pLocalPC->SaveCold,
			pLocalPC->SavePoison,
			pLocalPC->SaveDisease });
		Dest.Type = pIntType;
		return true;

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
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_FAYCITUM);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Chronobines:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_CHRONOBINES);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Commemoratives:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_COMMEMORATIVECOINS);
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
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ARXENERGYCRYSTALS);
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
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_MCKENZIESSPECIALBREW);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Bayle:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_BAYLEMARKS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Reclamation:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_TOKENSOFRECLAMATION);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Brellium:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_BRELLIUMTOKENS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Motes:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_DREAMMOTES);
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
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_EXPEDIENTDELIVERYVOUCHERS);
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
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_BIFURCATEDCOINS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::AdoptiveCoin:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_ADOPTIONCOINS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::SathirsTradeGems:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_SATHIRTRADEGEMS);
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
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_FETTEREDIFRITCOINS);
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
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_FROSTSTONEDUCATS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::WarlordsSymbol:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_WARLORDSSYMBOLS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::OverseerTetradrachm:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_OVERSEERTETRADRACHMS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::WarforgedEmblem:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_WARFORGEDEMBLEMS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::RestlessMark:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_RESTLESSMARKS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::ScarletMarks:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_SCARLETMARKS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::MedalsOfConflict:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_MEDALSOFCONFLICT);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::ShadedSpecie:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_SHADEDSPECIE);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::SpiritualMedallions:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_SPIRITUALMEDALLIONS);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LaurionInnVoucher:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_LAURIONINNVOUCHER);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::ShalowainsPrivateReserve:
		Dest.DWord = pPlayerPointManager->GetAltCurrency(ALTCURRENCY_SHALOWAINSPRIVATERESERVE);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::LoyaltyTokens:
		Dest.DWord = pLocalPC->LoyaltyRewardBalance;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Fellowship:
		Dest.Type = pFellowshipType;
		Dest.Ptr = &pLocalPlayer->Fellowship;
		return true;

	case CharacterMembers::Downtime:
		Dest.DWord = pLocalPC->DowntimeStamp ? ((pLocalPC->Downtime - (GetFastTime() - pLocalPC->DowntimeStamp)) / 6) + 1 : 0;
		Dest.Type = pTicksType;
		return true;

		// returns combined number of spell and damage "absorbment"
		// should probably split these into spell vs melee
	case CharacterMembers::Dar:
		Dest.DWord = 0;
		Dest.Type = pInt64Type;

		for (const auto& buff : pProfile->Buffs)
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
									Dest.Int64 += buffData.Value;
								}
							}
						}
					}
				}
			}
		}
		return true;

	case CharacterMembers::TotalCounters:
		Dest.Int64 = GetMyTotalSpellCounters();
		Dest.Type = pInt64Type;
		return true;

	case CharacterMembers::CountersDisease:
		Dest.Int64 = GetMySpellCounters(SPA_DISEASE);
		Dest.Type = pInt64Type;
		return true;

	case CharacterMembers::CountersPoison:
		Dest.Int64 = GetMySpellCounters(SPA_POISON);
		Dest.Type = pInt64Type;
		return true;

	case CharacterMembers::CountersCurse:
		Dest.Int64 = GetMySpellCounters(SPA_CURSE);
		Dest.Type = pInt64Type;
		return true;

	case CharacterMembers::CountersCorruption:
		Dest.Int64 = GetMySpellCounters(SPA_CORRUPTION);
		Dest.Type = pInt64Type;
		return true;

	case CharacterMembers::Mercenary:
		Dest.Type = pMercenaryType;
		return true;

	case CharacterMembers::XTargetSlots:
		Dest.DWord = pLocalPC->pExtendedTargetList->GetNumSlots();
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::XTAggroCount: {
		Dest.DWord = 0;
		Dest.Type = pIntType;

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
			int count = pLocalPC->pExtendedTargetList->GetNumSlots();
			for (int i = 0; i < count; i++)
			{
				ExtendedTargetSlot* slot = pLocalPC->pExtendedTargetList->GetSlot(i);
				if (!slot) continue;

				if (slot->SpawnID && slot->xTargetType == XTARGET_AUTO_HATER)
				{
					SPAWNINFO* pSpawn = GetSpawnByID(slot->SpawnID);
					if (!pSpawn
						|| (pTarget && pTarget->SpawnID == pSpawn->SpawnID)
						|| (pSpawn->Type != SPAWN_NPC))
					{
						continue;
					}

					uint16_t aggropct = pAggroInfo->aggroData[AD_xTarget1 + i].AggroPct;
					if (aggropct < AggroPct)
					{
						Dest.DWord++;
					}
				}
			}
		}
		return true;
	}

	case CharacterMembers::XTHaterCount:
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (pAggroInfo)
		{
			for (ExtendedTargetSlot& slot : *pLocalPC->pExtendedTargetList)
			{
				if (slot.SpawnID != 0
					&& slot.xTargetType == XTARGET_AUTO_HATER)
				{
					SPAWNINFO* pSpawn = GetSpawnByID(slot.SpawnID);
					if (!pSpawn
						|| (pTarget && pTarget->SpawnID == pSpawn->SpawnID)
						|| (pSpawn->Type != SPAWN_NPC))
					{
						continue;
					}

					Dest.DWord++;
				}
			}
		}

		return true;

	case CharacterMembers::XTarget: {
		Dest.DWord = 0;
		Dest.Type = pXTargetType;

		if (Index[0])
		{
			if (IsNumber(Index))
			{
				int index = GetIntFromString(Index, 0) - 1;

				if (pLocalPC->pExtendedTargetList->GetSlot(index) != nullptr)
				{
					Dest.DWord = index;
					Dest.Type = pXTargetType;
					return true;
				}
			}
			else
			{
				int pos = 0;
				for (const ExtendedTargetSlot& slot : *pLocalPC->pExtendedTargetList)
				{
					if (slot.xTargetType != 0
						&& slot.XTargetSlotStatus != eXTSlotEmpty
						&& _stricmp(Index, slot.Name) == 0)
					{
						Dest.DWord = pos;
						Dest.Type = pXTargetType;
						return true;
					}

					pos++;
				}
			}

			return false;
		}

		// No index was given, so we return the count.
		int count = 0;
		for (const ExtendedTargetSlot& slot : *pLocalPC->pExtendedTargetList)
		{
			if (slot.xTargetType != 0 && slot.XTargetSlotStatus != eXTSlotEmpty)
			{
				count++;
			}
		}

		Dest.DWord = count;
		Dest.Type = pIntType;
		return true;
	}

	case CharacterMembers::Haste:
		Dest.DWord = pLocalPC->TotalEffect(SPA_HASTE, true, 0, true, true);
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::SPA:
		if (IsNumber(Index))
		{
			Dest.DWord = pLocalPC->TotalEffect(GetIntFromString(Index, 0), true, 0, true, true);
			Dest.Type = pIntType;
			return true;
		}
		return false;

	case CharacterMembers::MercenaryStance:
		if (const MercenaryStanceInfo* pInfo = pMercManager->GetActiveMercenaryStance())
		{
			strcpy_s(DataTypeTemp, pCDBStr->GetString(pInfo->stanceStringId, eMercenaryStanceName));
		}
		else
		{
			strcpy_s(DataTypeTemp, "NULL");
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
		Dest.Set(false);
		Dest.Type = pBoolType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			// Check if expansion is owned by number: ${Me.HaveExpansion[18]}
			int nExpansion = GetIntFromString(Index, 0);
			if (nExpansion > NUM_EXPANSIONS)
				return true;
			Dest.Set((pLocalPC->ExpansionFlags & EQ_EXPANSION(nExpansion)) != 0);
		}
		else
		{
			// Check if expansion is owned by name: ${Me.HaveExpansion[Veil of Alaris]}
			for (int n = 0; n < NUM_EXPANSIONS; n++)
			{
				if (!_stricmp(Index, szExpansions[n]))
				{
					Dest.Set((pLocalPC->ExpansionFlags & EQ_EXPANSION(n + 1)) != 0);
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
		Dest = pSpawnType->MakeTypeVar(pAggroInfo ? GetSpawnByID(pAggroInfo->AggroSecondaryID) : nullptr);
		return true;

	case CharacterMembers::AggroLock:
		Dest = pSpawnType->MakeTypeVar(pAggroInfo ? GetSpawnByID(pAggroInfo->AggroLockID) : nullptr);
		return true;

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
		Dest.Float = pLocalPC->GetMercAAExpPct();
		Dest.Type = pFloatType;
		return true;

	case CharacterMembers::MercAAExp:
		Dest.Int64 = pLocalPC->GetMercAAExp();
		Dest.Type = pInt64Type;
		return true;

	case CharacterMembers::Krono:
		Dest.DWord = pLocalPC->Krono;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::MembershipLevel:
	case CharacterMembers::Subscription:
		strcpy_s(DataTypeTemp, "UNKNOWN");

		switch (GetMembershipLevel())
		{
		case MembershipLevel::Free:
			strcpy_s(DataTypeTemp, "FREE");
			break;
		case MembershipLevel::Silver:
			strcpy_s(DataTypeTemp, "SILVER");
			break;
#if IS_EXPANSION_LEVEL(EXPANSION_LEVEL_ROF + 1)
		case MembershipLevel::AllAccess:
		case MembershipLevel::LifetimeAllAccess:
#else
		case MembershipLevel::Gold:
#endif
			strcpy_s(DataTypeTemp, "GOLD");
			break;

		default: break;
		}

		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case CharacterMembers::AltCurrency:
	{
		Dest.DWord = 0;
		Dest.Type = pIntType;

		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			Dest.DWord = pPlayerPointManager->GetAltCurrency(GetIntFromString(Index, 0));
			return true;
		}

		int nCurrency = GetCurrencyIDByName(Index);
		if (nCurrency < 0)
			return false;
		Dest.DWord = pPlayerPointManager->GetAltCurrency(nCurrency);
		return true;
	}

	case CharacterMembers::Slowed:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellAffect(SPA_HASTE, false));
		return Dest.Int >= 0;

	case CharacterMembers::Rooted:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellAffect(SPA_ROOT, false));
		return Dest.Int >= 0;

	case CharacterMembers::Mezzed:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellAffect(SPA_ENTHRALL, false));
		return Dest.Int >= 0;

	case CharacterMembers::Crippled:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellSubCat(SPELLCAT_DISEMPOWERING));
		return Dest.Int >= 0;

	case CharacterMembers::Maloed:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellSubCat(SPELLCAT_RESIST_DEBUFFS) && SpellClassMask(Shaman, Mage));
		return Dest.Int >= 0;

	case CharacterMembers::Tashed:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellSubCat(SPELLCAT_RESIST_DEBUFFS) && SpellClassMask(Enchanter));
		return Dest.Int >= 0;

	case CharacterMembers::Snared:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellAffect(SPA_MOVEMENT_RATE, false));
		return Dest.Int >= 0;

	case CharacterMembers::Hasted:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellAffect(SPA_HASTE));
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

		Dest.Set(bZoning);
		Dest.Type = pBoolType;
		return true;
	}

	case CharacterMembers::DSed:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellAffect(SPA_DAMAGE_SHIELD));
		return Dest.Int >= 0;

	case CharacterMembers::RevDSed:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellAffect(SPA_IRONMAIDEN));
		return Dest.Int >= 0;

	case CharacterMembers::Charmed:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellAffect(SPA_CHARM, false));
		return Dest.Int >= 0;

	case CharacterMembers::Aego:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellAffect(SPA_AC, true) &&
			SpellCategory(SPELLCAT_HP_BUFFS) &&
			(SpellSubCat(SPELLCAT_AEGOLISM) || SpellSubCat(SPELLCAT_SYMBOL)) &&
			SpellClassMask(Cleric));
		return Dest.Int >= 0;

	case CharacterMembers::Skin:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellCategory(SPELLCAT_HP_BUFFS) &&
			SpellSubCat(SPELLCAT_HP_TYPE_ONE) &&
			SpellClassMask(Druid));
		return Dest.Int >= 0;

	case CharacterMembers::Focus:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellCategory(SPELLCAT_HP_BUFFS) &&
			SpellSubCat(SPELLCAT_SHIELDING) &&
			SpellClassMask(Shaman));
		return Dest.Int >= 0;

	case CharacterMembers::Regen:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellAffect(SPA_HP) && !SpellClassMask(Beastlord));
		return Dest.Int >= 0;

	case CharacterMembers::Diseased:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellAffect(SPA_DISEASE, false));
		return Dest.Int >= 0;

	case CharacterMembers::Poisoned:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellAffect(SPA_POISON, false));
		return Dest.Int >= 0;

	case CharacterMembers::Cursed:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellAffect(SPA_CURSE, false));
		return Dest.Int >= 0;

	case CharacterMembers::Corrupted:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellAffect(SPA_CORRUPTION, false));
		return Dest.Int >= 0;

	case CharacterMembers::Symbol:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellCategory(SPELLCAT_HP_BUFFS) &&
			SpellSubCat(SPELLCAT_SYMBOL) &&
			SpellClassMask(Cleric));
		return Dest.Int >= 0;

	case CharacterMembers::Clarity:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellAffect(SPA_MANA) && SpellClassMask(Enchanter));
		return Dest.Int >= 0;

	case CharacterMembers::Pred:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellCategory(SPELLCAT_STATISTIC_BUFFS) &&
			SpellSubCat(SPELLCAT_ATTACK) &&
			SpellClassMask(Ranger));
		return Dest.Int >= 0;

	case CharacterMembers::Strength:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellCategory(SPELLCAT_HP_BUFFS) &&
			SpellSubCat(SPELLCAT_HP_TYPE_TWO) &&
			SpellClassMask(Ranger));
		return Dest.Int >= 0;

	case CharacterMembers::Brells:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellCategory(SPELLCAT_HP_BUFFS) &&
			SpellSubCat(SPELLCAT_HP_TYPE_TWO) &&
			SpellClassMask(Paladin));
		return Dest.Int >= 0;

	case CharacterMembers::SV:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellCategory(SPELLCAT_REGEN) &&
			SpellSubCat(SPELLCAT_MANA) &&
			SpellClassMask(Beastlord));
		return Dest.Int >= 0;

	case CharacterMembers::SE:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellCategory(SPELLCAT_REGEN) &&
			SpellSubCat(SPELLCAT_HEALTH_MANA) &&
			SpellClassMask(Beastlord));
		return Dest.Int >= 0;

	case CharacterMembers::HybridHP:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellCategory(SPELLCAT_HP_BUFFS) &&
			SpellSubCat(SPELLCAT_HP_TYPE_ONE) &&
			SpellClassMask(Ranger));
		return Dest.Int >= 0;

	case CharacterMembers::Growth:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellCategory(SPELLCAT_HP_BUFFS) &&
			SpellSubCat(SPELLCAT_TEMPORARY) &&
			SpellClassMask(Druid));
		return Dest.Int >= 0;

	case CharacterMembers::Shining:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellCategory(SPELLCAT_UTILITY_BENEFICIAL) &&
			SpellSubCat(SPELLCAT_MELEE_GUARD) &&
			SpellAffect(SPA_MELEE_GUARD) &&
			SpellClassMask(Cleric));
		return Dest.Int >= 0;

	case CharacterMembers::InInstance:
		Dest.Set(HIWORD(pLocalPlayer->GetZoneID()) != 0);
		Dest.Type = pBoolType;
		return true;

	case CharacterMembers::Instance:
		Dest.DWord = HIWORD(pLocalPlayer->GetZoneID());
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::MercListInfo: {
		Dest.Type = pStringType;
		if (!Index[0])
			return false;

		if (IsNumber(Index))
		{
			int nIndex = GetIntFromString(Index, 0) - 1;
			if (nIndex >= pMercManager->mercenaries.GetLength() || nIndex < 0)
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

			for (uint32_t index = 0; index < descs.size(); ++index)
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
		Dest.Set(pLocalPC->UseAdvancedLooting != 0);
		Dest.Type = pBoolType;
		return true;

	case CharacterMembers::SpellInCooldown:
		Dest.Set(pDisplay->TimeStamp <= pLocalPlayer->GetSpellCooldownETA());
		Dest.Type = pBoolType;
		return true;

	case CharacterMembers::AssistComplete:
		Dest.Set(gbAssistComplete == AS_AssistReceived);
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
		Dest.UInt64 = pLocalPC->GuildID;
		Dest.Type = pInt64Type;
		return true;

	case CharacterMembers::ExpansionFlags:
		Dest.DWord = pLocalPC->ExpansionFlags;
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
#if HAS_AUTOSKILLS
		Dest.Type = pSkillType;
		if (IsNumber(Index))
		{
			int index = GetIntFromString(Index, 0) - 1;
			if (index < 0)
				index = 0;
			if (index >= CONCURRENT_SKILLS)
				index = CONCURRENT_SKILLS - 1;

			int skillid = pEverQuestInfo->AutoSkills[index];
			if (skillid > 0 && skillid < NUM_SKILLS)
			{
				Dest.Ptr = &pSkillMgr->pSkill[skillid];
				return true;
			}
		}
#endif
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
		Dest.Int = GetSelfBuff([](EQ_Spell* spell) { return spell->SpellType != 0; });
		return Dest.Int >= 0;

	case CharacterMembers::CursorKrono:
		Dest.DWord = pLocalPC->CursorKrono;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::MercAAPoints:
		Dest.DWord = pLocalPC->GetMercAAPoints();
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::MercAAPointsSpent:
		Dest.DWord = pLocalPC->GetMercAAPointsSpent();
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::Bandolier:
		Dest.DWord = 0;
		Dest.Type = pBandolierType;

		if (IsNumber(Index))
		{
			Dest.DWord = std::clamp(GetIntFromString(Index, 1), 1, MAX_BANDOLIER_ITEMS) - 1;
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
		Dest.Int = GetSelfBuff(SpellAffect(SPA_FEAR));
		return Dest.Int >= 0;

	case CharacterMembers::Silenced:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellAffect(SPA_SILENCE));
		return Dest.Int >= 0;

	case CharacterMembers::Invulnerable:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(SpellAffect(SPA_INVULNERABILITY));
		return Dest.Int >= 0;

	case CharacterMembers::Dotted:
		Dest.Type = pBuffType;
		Dest.HighPart = SpellDisplayType_None;
		Dest.Int = GetSelfBuff(
			[](EQ_Spell* spell) { return SpellAffect(SPA_HP, false)(spell) && spell->IsDetrimentalSpell() && spell->IsDoTSpell(); });
		return Dest.Int >= 0;

	case CharacterMembers::ParcelStatus:
		Dest.DWord = pLocalPC->ParcelStatus;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::CanMount: {
		Dest.Set(false);
		Dest.Type = pBoolType;

		if (pLocalPlayer->HeadWet != 0 || pLocalPlayer->Vehicle != nullptr)
			return true;

		int race = pLocalPlayer->GetRace();

		// These non-player races can mount.
		if (race != EQR_SKELETON
			&& race != EQR_SKELETON_NEW
			&& race != EQR_OEQ_SKELETON
			&& race != EQR_SOL_SKELETON)
		{
			// FIXME: we can calculate this, don't need to look it up.
			// The -1 means "use the current race of the player"
			if (!pLocalPlayer->LegalPlayerRace(-1))
				return true;
		}

		if (pZoneInfo->IsIndoor())
			return true;

		if (pWorldData->IsFlagSet(pLocalPlayer->GetZoneID(), EQZoneFlag_NoMount))
			return true;

		// If we made it this far, we can mount.
		Dest.Set(true);
		return true;
	}

	case CharacterMembers::SpellRankCap:
		Dest.DWord = 1;
		Dest.Type = pIntType;
		if (pLocalPC)
		{
			int value = pLocalPC->GetGameFeature(GameFeature::SpellTier);
			if (value == -1 || value >= 10)
				Dest.DWord = 3;
			else if (value >= 5)
				Dest.DWord = 2;
		}
		return true;

	case CharacterMembers::CastTimeLeft:
		Dest.Int64 = 0;
		Dest.Type = pTimeStampType;
		if (pLocalPlayer->CastingData.SpellETA)
		{
			int64_t delta = pLocalPlayer->CastingData.SpellETA - pDisplay->TimeStamp;
			if (delta > 0)
			{
				Dest.Int64 = delta;
			}
		}
		return true;

	case CharacterMembers::MaxLevel:
		Dest.Type = pIntType;
		Dest.Set(GetCharMaxLevel());
		return true;

	case CharacterMembers::AirSupply:
		Dest.Type = pIntType;
		Dest.Set(pLocalPC->GetAirSupply());
		return true;

	case CharacterMembers::MaxAirSupply:
		Dest.Type = pIntType;
		Dest.Set(pLocalPC->GetMaxAirSupply());
		return true;

	case CharacterMembers::PctAirSupply:
		Dest.Type = pIntType;
		Dest.Set(((pLocalPC->GetAirSupply()) * 100) / (pLocalPC->GetMaxAirSupply()));
		return true;

	case CharacterMembers::NumBagSlots:
		Dest.Type = pIntType;
		Dest.Set<int>(GetHighestAvailableBagSlot() - InvSlot_FirstBagSlot + 1);
		return true;

	case CharacterMembers::Inviter:
		strcpy_s(DataTypeTemp, pEverQuestInfo->Inviter);
		Dest.Ptr = &DataTypeTemp[0];
		Dest.Type = pStringType;
		return true;

	case CharacterMembers::Invited:
		Dest.Set(pLocalPlayer->InvitedToGroup);
		Dest.Type = pBoolType;
		return true;

	case CharacterMembers::IsBerserk:
		Dest.DWord = pLocalPlayer->berserker;
		Dest.Type = pIntType;
		return true;

	case CharacterMembers::GroupLeaderExp:
#if HAS_LEADERSHIP_EXPERIENCE
		Dest.Float = static_cast<float>(pLocalPC->GroupLeadershipExp);
#else
		Dest.Float = 0.0f;
#endif
		Dest.Type = pFloatType;
		return true;
	case CharacterMembers::GroupLeaderPoints:
#if HAS_LEADERSHIP_EXPERIENCE
		Dest.DWord = pLocalPC->GroupLeadershipPoints;
#else
		Dest.DWord = 0;
#endif
		Dest.Type = pIntType;
		return true;
	case CharacterMembers::PctGroupLeaderExp:
#if HAS_LEADERSHIP_EXPERIENCE
		Dest.Float = static_cast<float>(pLocalPC->GroupLeadershipExp) / 10.0f;
#else
		Dest.Float = 0.0f;
#endif
		Dest.Type = pFloatType;
		return true;
	case CharacterMembers::RaidLeaderExp:
#if HAS_LEADERSHIP_EXPERIENCE
		Dest.Float = static_cast<float>(pLocalPC->RaidLeadershipExp);
#else
		Dest.Float = 0.0f;
#endif
		Dest.Type = pFloatType;
		return true;
	case CharacterMembers::RaidLeaderPoints:
#if HAS_LEADERSHIP_EXPERIENCE
		Dest.DWord = pLocalPC->RaidLeadershipPoints;
#else
		Dest.DWord = 0;
#endif
		Dest.Type = pIntType;
		return true;
	case CharacterMembers::PctRaidLeaderExp:
#if HAS_LEADERSHIP_EXPERIENCE
		Dest.Float = static_cast<float>(pLocalPC->RaidLeadershipExp) / 10.0f;
#else
		Dest.Float = 0.0f;
#endif
		Dest.Type = pFloatType;
		return true;

	case CharacterMembers::PersonaLevel: {
		Dest.Type = pIntType;
		Dest.Int = 0;
#if HAS_ALTERNATE_PERSONAS
		if (Index[0])
		{
			int classId = GetIntFromString(Index, -1);

			if (classId != -1)
			{
				if (classId >= eqlib::Warrior && classId <= eqlib::Berserker)
				{
					Dest.Int = pLocalPC->GetPersonaLevel(classId);
					return true;
				}
			}
			else
			{
				for (int i = eqlib::Warrior; i < eqlib::Berserker; ++i)
				{
					if (ci_equals(Index, ClassInfo[i].ShortName))
					{
						Dest.Int = pLocalPC->GetPersonaLevel(i);
						return true;
					}
				}
			}
		}
#endif
		return true;
	}

	default:
		return false;
	}
}

bool MQ2CharacterType::ToString(MQVarPtr VarPtr, char* Destination)
{
	if (!pLocalPC)
		return false;

	strcpy_s(Destination, MAX_STRING, pLocalPC->Name);
	return true;
}

bool MQ2CharacterType::Downcast(const MQVarPtr& fromVar, MQVarPtr& toVar, MQ2Type* toType)
{
	if (toType == pSpawnType)
	{
		// We don't store anything on the soutce VarPtr so we ignore it.
		toVar = MQ2SpawnType::MakeVarPtr(pLocalPlayer);
		return true;
	}

	return false;
}

bool MQ2CharacterType::dataCharacter(const char* szIndex, MQTypeVar& Ret)
{
	Ret.Ptr = nullptr;
	Ret.Type = pCharacterType;
	return true;
}

} // namespace mq::datatypes
