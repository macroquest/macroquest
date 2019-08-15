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

#include "PcClient.h"
#include "Globals.h"

namespace eqlib {

//============================================================================
// BaseProfile
//============================================================================

#ifdef BaseProfile__GetItemPossession_x
FUNCTION_AT_ADDRESS(VePointer<CONTENTS> BaseProfile::GetItemPossession(const ItemIndex& lIndex) const, BaseProfile__GetItemPossession);
#endif

//============================================================================
// CharacterBase
//============================================================================

#ifdef CharacterBase__GetMemorizedSpell_x
FUNCTION_AT_ADDRESS(LONG CharacterBase::GetMemorizedSpell(int), CharacterBase__GetMemorizedSpell);
#endif
#ifdef CharacterBase__CreateItemGlobalIndex_x
FUNCTION_AT_ADDRESS(ItemGlobalIndex CharacterBase::CreateItemGlobalIndex(int, int, int), CharacterBase__CreateItemGlobalIndex);
#endif
#ifdef CharacterBase__CreateItemIndex_x
FUNCTION_AT_ADDRESS(ItemIndex CharacterBase::CreateItemIndex(int, int, int), CharacterBase__CreateItemIndex);
#endif
#ifdef CharacterBase__GetItemByGlobalIndex_x
FUNCTION_AT_ADDRESS(VePointer<CONTENTS> CharacterBase::GetItemByGlobalIndex(const ItemGlobalIndex& GlobalIndex) const, CharacterBase__GetItemByGlobalIndex);
#endif
#ifdef CharacterBase__GetItemByGlobalIndex1_x
FUNCTION_AT_ADDRESS(VePointer<CONTENTS> CharacterBase::GetItemByGlobalIndex(const ItemGlobalIndex& GlobalIndex, GILocationOption Option) const, CharacterBase__GetItemByGlobalIndex1);
#endif
#ifdef CharacterBase__GetItemPossession_x
FUNCTION_AT_ADDRESS(VePointer<CONTENTS> CharacterBase::GetItemPossession(const ItemIndex& lIndex) const, CharacterBase__GetItemPossession);
#endif
#ifdef CharacterBase__GetEffectId_x
FUNCTION_AT_ADDRESS(unsigned int CharacterBase::GetEffectId(int), CharacterBase__GetEffectId);
#endif

//============================================================================
// CharacterZoneClient
//============================================================================

#ifdef CharacterZoneClient__FindAffectSlot_x
FUNCTION_AT_ADDRESS(EQ_Affect* CharacterZoneClient::FindAffectSlot(int, PSPAWNINFO, int*, bool, int, EQ_Affect*, int, bool), CharacterZoneClient__FindAffectSlot);
#endif
#ifdef CharacterZoneClient__GetMaxEffects_x
FUNCTION_AT_ADDRESS(unsigned char CharacterZoneClient::GetMaxEffects() const, CharacterZoneClient__GetMaxEffects);
#endif
#ifdef CharacterZoneClient__GetEffect_x
FUNCTION_AT_ADDRESS(EQ_Affect& CharacterZoneClient::GetEffect(int) const, CharacterZoneClient__GetEffect);
#endif
#ifdef CharacterZoneClient__GetOpenEffectSlot_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::GetOpenEffectSlot(bool, bool, int), CharacterZoneClient__GetOpenEffectSlot);
#endif
#ifdef CharacterZoneClient__GetFirstEffectSlot_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::GetFirstEffectSlot(bool, bool), CharacterZoneClient__GetFirstEffectSlot);
#endif
#ifdef CharacterZoneClient__GetLastEffectSlot_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::GetLastEffectSlot(bool, bool, bool), CharacterZoneClient__GetLastEffectSlot);
#endif
#ifdef CharacterZoneClient__FindItemByGuid_x
FUNCTION_AT_ADDRESS(bool CharacterZoneClient::FindItemByGuid(const EqItemGuid& ItemGuid, int* pos_slot, int* con_slot), CharacterZoneClient__FindItemByGuid);
#endif
#ifdef CharacterZoneClient__FindItemByRecord_x
FUNCTION_AT_ADDRESS(BYTE CharacterZoneClient::FindItemByRecord(int ItemNumber /*recordnum*/, int* pos_slot, int* con_slot, bool bReverseLookup), CharacterZoneClient__FindItemByRecord);
#endif
#ifdef CharacterZoneClient__CharacterZoneClient_x
FUNCTION_AT_ADDRESS(CharacterZoneClient::CharacterZoneClient(), CharacterZoneClient__CharacterZoneClient);
#endif
#ifdef CharacterZoneClient__HasSkill_x
FUNCTION_AT_ADDRESS(bool CharacterZoneClient::HasSkill(int), CharacterZoneClient__HasSkill);
#endif
#ifdef CharacterZoneClient__MakeMeVisible_x
FUNCTION_AT_ADDRESS(void CharacterZoneClient::MakeMeVisible(int, bool), CharacterZoneClient__MakeMeVisible);
#endif
#ifdef CharacterZoneClient__GetItemCountWorn_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::GetItemCountWorn(int), CharacterZoneClient__GetItemCountWorn);
#endif
#ifdef CharacterZoneClient__GetItemCountInInventory_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::GetItemCountInInventory(int), CharacterZoneClient__GetItemCountInInventory);
#endif
#ifdef CharacterZoneClient__GetCursorItemCount_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::GetCursorItemCount(int), CharacterZoneClient__GetCursorItemCount);
#endif
#ifdef CharacterZoneClient__ApplyDamage_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::ApplyDamage(int, int, int, int, int, int), CharacterZoneClient__ApplyDamage);
#endif
#ifdef CharacterZoneClient__BardCastBard_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::BardCastBard(const EQ_Spell*, signed int) const, CharacterZoneClient__BardCastBard);
#endif
#ifdef CharacterZoneClient__CalcAffectChange_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::CalcAffectChange(const EQ_Spell* spell, BYTE, BYTE, const EQ_Affect*, int, PlayerZoneClient*, bool, int, bool), CharacterZoneClient__CalcAffectChange);
#endif
#ifdef CharacterZoneClient__CalcAffectChangeGeneric_x
FUNCTION_AT_ADDRESS(int CharacterZoneClient::CalcAffectChangeGeneric(const EQ_Spell* spell, BYTE, BYTE, const EQ_Affect*, int, bool), CharacterZoneClient__CalcAffectChangeGeneric);
#endif
#ifdef CharacterZoneClient__GetFocusReuseMod_x
FUNCTION_AT_ADDRESS(const int CharacterZoneClient::GetFocusReuseMod(const EQ_Spell* pSpell, VePointer<CONTENTS>& pOutItem), CharacterZoneClient__GetFocusReuseMod);
#endif
#ifdef CharacterZoneClient__IsStackBlocked_x
FUNCTION_AT_ADDRESS(bool CharacterZoneClient::IsStackBlocked(const EQ_Spell*, PSPAWNINFO, EQ_Affect*, int, bool), CharacterZoneClient__IsStackBlocked);
#endif
#ifdef CharacterZoneClient__CanUseMemorizedSpellSlot_x
FUNCTION_AT_ADDRESS(bool EQ_Character::CanUseMemorizedSpellSlot(int), CharacterZoneClient__CanUseMemorizedSpellSlot);
#endif


//============================================================================
// EQ_Character
//============================================================================

#ifdef EQ_Character__Max_Endurance_x
FUNCTION_AT_ADDRESS(int EQ_Character1::Max_Endurance(bool), EQ_Character__Max_Endurance);
#endif
#ifdef EQ_Character__Max_Mana_x
FUNCTION_AT_ADDRESS(int EQ_Character1::Max_Mana(bool), EQ_Character__Max_Mana);
#endif
#ifdef EQ_Character__Max_HP_x
FUNCTION_AT_ADDRESS(int EQ_Character1::Max_HP(int, bool), EQ_Character__Max_HP);
#endif
#ifdef EQ_Character__doCombatAbility_x
FUNCTION_AT_ADDRESS(bool EQ_Character::DoCombatAbility(int spellID, int dummy), EQ_Character__doCombatAbility);
#endif
#ifdef EQ_Character__EQ_Character_x
FUNCTION_AT_ADDRESS(EQ_Character::EQ_Character(), EQ_Character__EQ_Character);
#endif
#ifdef EQ_Character__dEQ_Character_x
FUNCTION_AT_ADDRESS(EQ_Character::~EQ_Character(), EQ_Character__dEQ_Character);
#endif
#ifdef EQ_Character__EQ_CharacterResetAllMembers_x
FUNCTION_AT_ADDRESS(void EQ_Character::EQ_CharacterResetAllMembers(), EQ_Character__EQ_CharacterResetAllMembers);
#endif
#ifdef EQ_Character__ModifyCurHP_x
FUNCTION_AT_ADDRESS(void EQ_Character::ModifyCurHP(int32_t modification, PlayerZoneClient* resposibleplayer, int skilltype), EQ_Character__ModifyCurHP);
#endif
#ifdef EQ_Character__normal_to_special_x
FUNCTION_AT_ADDRESS(int __cdecl EQ_Character::normal_to_special(int), EQ_Character__normal_to_special);
#endif
#ifdef EQ_Character__IsSpellcaster_x
FUNCTION_AT_ADDRESS(int EQ_Character::IsSpellcaster(), EQ_Character__IsSpellcaster);
#endif
#ifdef EQ_Character__DoLight_x
FUNCTION_AT_ADDRESS(void EQ_Character::DoLight(unsigned char), EQ_Character__DoLight);
#endif
#ifdef EQ_Character__Skill_x
FUNCTION_AT_ADDRESS(int EQ_Character::Skill(int), EQ_Character__Skill);
#endif
#ifdef EQ_Character__HasSpell_x
FUNCTION_AT_ADDRESS(int EQ_Character::HasSpell(int), EQ_Character__HasSpell);
#endif
#ifdef EQ_Character__ResetCur_HP_x
FUNCTION_AT_ADDRESS(void EQ_Character::ResetCur_HP(int), EQ_Character__ResetCur_HP);
#endif
#ifdef EQ_Character__GetEnduranceRegen_x
FUNCTION_AT_ADDRESS(int EQ_Character1::GetEnduranceRegen(bool bIncItemsAndBuffs, bool bCombat), EQ_Character__GetEnduranceRegen);
#endif
#ifdef EQ_Character__GetHPRegen_x
FUNCTION_AT_ADDRESS(int EQ_Character1::GetHPRegen(bool bIncItemsAndBuffs, bool* bIsBleeding, bool bCombat), EQ_Character__GetHPRegen);
#endif
#ifdef EQ_Character__GetManaRegen_x
FUNCTION_AT_ADDRESS(int EQ_Character1::GetManaRegen(bool bincItemsAndBuffs, bool bCombat), EQ_Character__GetManaRegen);
#endif
#ifdef EQ_Character__Cur_HP_x
FUNCTION_AT_ADDRESS(int EQ_Character1::Cur_HP(int SpawnType, bool bCapAtMax), EQ_Character__Cur_HP);
#endif
#ifdef EQ_Character__GetHPFromStamina_x
FUNCTION_AT_ADDRESS(int EQ_Character::GetHPFromStamina(int), EQ_Character__GetHPFromStamina);
#endif
#ifdef EQ_Character__Cur_Mana_x
FUNCTION_AT_ADDRESS(int EQ_Character::Cur_Mana(bool bCapAtMax), EQ_Character__Cur_Mana);
#endif
#ifdef EQ_Character__IsMage_x
FUNCTION_AT_ADDRESS(int EQ_Character::IsMage(), EQ_Character__IsMage);
#endif
#ifdef EQ_Character__GetClassACBonus_x
FUNCTION_AT_ADDRESS(int EQ_Character::GetClassACBonus(int), EQ_Character__GetClassACBonus);
#endif
#ifdef EQ_Character__ac_x
FUNCTION_AT_ADDRESS(int EQ_Character::ac(bool), EQ_Character__ac);
#endif
#ifdef EQ_Character__compute_tohit_x
FUNCTION_AT_ADDRESS(int EQ_Character::compute_tohit(unsigned char), EQ_Character__compute_tohit);
#endif
#ifdef EQ_Character__defense_agility_bonus_x
FUNCTION_AT_ADDRESS(int EQ_Character::defense_agility_bonus(), EQ_Character__defense_agility_bonus);
#endif
#ifdef EQ_Character__compute_defense_x
FUNCTION_AT_ADDRESS(int EQ_Character::compute_defense(), EQ_Character__compute_defense);
#endif
#ifdef EQ_Character__offense_x
FUNCTION_AT_ADDRESS(int EQ_Character::offense(unsigned char), EQ_Character__offense);
#endif
#ifdef EQ_Character__HasSkill_x
FUNCTION_AT_ADDRESS(int EQ_Character::HasSkill(unsigned char), EQ_Character__HasSkill);
#endif
#ifdef EQ_Character__HasInnateSkill_x
FUNCTION_AT_ADDRESS(int EQ_Character::HasInnateSkill(unsigned char, int), EQ_Character__HasInnateSkill);
#endif
#ifdef EQ_Character__InitMyLanguages_x
FUNCTION_AT_ADDRESS(void EQ_Character::InitMyLanguages(), EQ_Character__InitMyLanguages);
#endif
#ifdef EQ_Character__BaneDamage_x
FUNCTION_AT_ADDRESS(int EQ_Character::BaneDamage(EQ_Equipment*), EQ_Character__BaneDamage);
#endif
#ifdef EQ_Character__ElementResistDmg_x
FUNCTION_AT_ADDRESS(int EQ_Character::ElementResistDmg(EQ_Equipment*, int), EQ_Character__ElementResistDmg);
#endif
#ifdef EQ_Character__save_bash_x
FUNCTION_AT_ADDRESS(int EQ_Character::save_bash(int), EQ_Character__save_bash);
#endif
#ifdef EQ_Character__CapStat_x
FUNCTION_AT_ADDRESS(int EQ_Character::CapStat(int, int), EQ_Character__CapStat);
#endif
#ifdef EQ_Character__CalcFoodDrinkBonus_x
FUNCTION_AT_ADDRESS(void EQ_Character::CalcFoodDrinkBonus(int), EQ_Character__CalcFoodDrinkBonus);
#endif
#ifdef EQ_Character__basesave_magic_x
FUNCTION_AT_ADDRESS(int EQ_Character::basesave_magic(), EQ_Character__basesave_magic);
#endif
#ifdef EQ_Character__save_magic_x
FUNCTION_AT_ADDRESS(int EQ_Character::save_magic(), EQ_Character__save_magic);
#endif
#ifdef EQ_Character__basesave_fire_x
FUNCTION_AT_ADDRESS(int EQ_Character::basesave_fire(), EQ_Character__basesave_fire);
#endif
#ifdef EQ_Character__save_fire_x
FUNCTION_AT_ADDRESS(int EQ_Character::save_fire(), EQ_Character__save_fire);
#endif
#ifdef EQ_Character__basesave_cold_x
FUNCTION_AT_ADDRESS(int EQ_Character::basesave_cold(), EQ_Character__basesave_cold);
#endif
#ifdef EQ_Character__save_cold_x
FUNCTION_AT_ADDRESS(int EQ_Character::save_cold(), EQ_Character__save_cold);
#endif
#ifdef EQ_Character__basesave_disease_x
FUNCTION_AT_ADDRESS(int EQ_Character::basesave_disease(), EQ_Character__basesave_disease);
#endif
#ifdef EQ_Character__save_disease_x
FUNCTION_AT_ADDRESS(int EQ_Character::save_disease(), EQ_Character__save_disease);
#endif
#ifdef EQ_Character__basesave_poison_x
FUNCTION_AT_ADDRESS(int EQ_Character::basesave_poison(), EQ_Character__basesave_poison);
#endif
#ifdef EQ_Character__save_poison_x
FUNCTION_AT_ADDRESS(int EQ_Character::save_poison(), EQ_Character__save_poison);
#endif
#ifdef EQ_Character__Str_x
FUNCTION_AT_ADDRESS(int EQ_Character::Str(), EQ_Character__Str);
#endif
#ifdef EQ_Character__Sta_x
FUNCTION_AT_ADDRESS(int EQ_Character::Sta(), EQ_Character__Sta);
#endif
#ifdef EQ_Character__Cha_x
FUNCTION_AT_ADDRESS(int EQ_Character::Cha(), EQ_Character__Cha);
#endif
#ifdef EQ_Character__Dex_x
FUNCTION_AT_ADDRESS(int EQ_Character::Dex(), EQ_Character__Dex);
#endif
#ifdef EQ_Character__Int_x
FUNCTION_AT_ADDRESS(int EQ_Character::Int(), EQ_Character__Int);
#endif
#ifdef EQ_Character__Agi_x
FUNCTION_AT_ADDRESS(int EQ_Character::Agi(), EQ_Character__Agi);
#endif
#ifdef EQ_Character__Wis_x
FUNCTION_AT_ADDRESS(int EQ_Character::Wis(), EQ_Character__Wis);
#endif
#ifdef EQ_Character__ApplyFatigue_x
FUNCTION_AT_ADDRESS(int EQ_Character::ApplyFatigue(int), EQ_Character__ApplyFatigue);
#endif
#ifdef EQ_Character__max_encumbrance_x
FUNCTION_AT_ADDRESS(int EQ_Character::max_encumbrance(), EQ_Character__max_encumbrance);
#endif
#ifdef EQ_Character__CanUseItem_x
FUNCTION_AT_ADDRESS(bool EQ_Character1::CanUseItem(CONTENTS**, bool, bool), EQ_Character__CanUseItem);
#endif
#ifdef EQ_Character__encum_factor_x
FUNCTION_AT_ADDRESS(float EQ_Character::encum_factor(), EQ_Character__encum_factor);
#endif
#ifdef EQ_Character__cur_encumbrance_x
FUNCTION_AT_ADDRESS(int EQ_Character::cur_encumbrance(), EQ_Character__cur_encumbrance);
#endif
#ifdef EQ_Character__Race_x
FUNCTION_AT_ADDRESS(char* EQ_Character::Race(int), EQ_Character__Race);
#endif
#ifdef EQ_Character__Class_x
FUNCTION_AT_ADDRESS(char* EQ_Character::Class(int), EQ_Character__Class);
#endif
#ifdef EQ_Character__KunarkClass_x
FUNCTION_AT_ADDRESS(char* EQ_Character::KunarkClass(int, int, int, bool), EQ_Character__KunarkClass);
#endif
#ifdef EQ_Character__ClassMin_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::ClassMin(int, int, unsigned char), EQ_Character__ClassMin);
#endif
#ifdef EQ_Character__CheckClass_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::CheckClass(int, int), EQ_Character__CheckClass);
#endif
#ifdef EQ_Character__CanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::CanWorship(int, int, unsigned char), EQ_Character__CanWorship);
#endif
#ifdef EQ_Character__HumanCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::HumanCanWorship(unsigned char, unsigned char), EQ_Character__HumanCanWorship);
#endif
#ifdef EQ_Character__BarbarianCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::BarbarianCanWorship(unsigned char, unsigned char), EQ_Character__BarbarianCanWorship);
#endif
#ifdef EQ_Character__EruditeCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::EruditeCanWorship(unsigned char, unsigned char), EQ_Character__EruditeCanWorship);
#endif
#ifdef EQ_Character__ElfCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::ElfCanWorship(unsigned char, unsigned char), EQ_Character__ElfCanWorship);
#endif
#ifdef EQ_Character__HighElfCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::HighElfCanWorship(unsigned char, unsigned char), EQ_Character__HighElfCanWorship);
#endif
#ifdef EQ_Character__DarkElfCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::DarkElfCanWorship(unsigned char, unsigned char), EQ_Character__DarkElfCanWorship);
#endif
#ifdef EQ_Character__HalfElfCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::HalfElfCanWorship(unsigned char, unsigned char), EQ_Character__HalfElfCanWorship);
#endif
#ifdef EQ_Character__DwarfCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::DwarfCanWorship(unsigned char, unsigned char), EQ_Character__DwarfCanWorship);
#endif
#ifdef EQ_Character__TrollCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::TrollCanWorship(unsigned char, unsigned char), EQ_Character__TrollCanWorship);
#endif
#ifdef EQ_Character__OgreCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::OgreCanWorship(unsigned char, unsigned char), EQ_Character__OgreCanWorship);
#endif
#ifdef EQ_Character__HalflingCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::HalflingCanWorship(unsigned char, unsigned char), EQ_Character__HalflingCanWorship);
#endif
#ifdef EQ_Character__GnomeCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::GnomeCanWorship(unsigned char, unsigned char), EQ_Character__GnomeCanWorship);
#endif
#ifdef EQ_Character__IksarCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::IksarCanWorship(unsigned char, unsigned char), EQ_Character__IksarCanWorship);
#endif
#ifdef EQ_Character__VahShirCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::VahShirCanWorship(unsigned char, unsigned char), EQ_Character__VahShirCanWorship);
#endif
#ifdef EQ_Character__FroglockCanWorship_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::FroglockCanWorship(unsigned char, unsigned char), EQ_Character__FroglockCanWorship);
#endif
#ifdef EQ_Character__CityCanStart_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::CityCanStart(int, int, int, int), EQ_Character__CityCanStart);
#endif
#ifdef EQ_Character__BaseAttr_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::BaseAttr(int, unsigned char), EQ_Character__BaseAttr);
#endif
#ifdef EQ_Character__InitSkills_x
FUNCTION_AT_ADDRESS(void EQ_Character::InitSkills(unsigned char, unsigned int), EQ_Character__InitSkills);
#endif
#ifdef EQ_Character__InitInnates_x
FUNCTION_AT_ADDRESS(void EQ_Character::InitInnates(unsigned int, unsigned int), EQ_Character__InitInnates);
#endif
#ifdef EQ_Character__IsSpecialBazaarSpot_x
FUNCTION_AT_ADDRESS(int EQ_Character::IsSpecialBazaarSpot(EQPlayer*), EQ_Character__IsSpecialBazaarSpot);
#endif
#ifdef EQ_Character__CanSecondaryAttack_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::CanSecondaryAttack(EQPlayer*), EQ_Character__CanSecondaryAttack);
#endif
#ifdef EQ_Character__CanDoubleAttack_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::CanDoubleAttack(EQPlayer*, unsigned char), EQ_Character__CanDoubleAttack);
#endif
#ifdef EQ_Character__AntiTwinkAdj_x
FUNCTION_AT_ADDRESS(int EQ_Character::AntiTwinkAdj(EQ_Equipment*, int, int), EQ_Character__AntiTwinkAdj);
#endif
#ifdef EQ_Character__GetSkillBaseDamage_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::GetSkillBaseDamage(unsigned char, EQPlayer*), EQ_Character__GetSkillBaseDamage);
#endif
#ifdef EQ_Character__UseSkill_x
FUNCTION_AT_ADDRESS(void EQ_Character1::UseSkill(unsigned char skill, PlayerZoneClient* target, bool), EQ_Character__UseSkill);
#endif
#ifdef EQ_Character__DoIntimidationEvent_x
FUNCTION_AT_ADDRESS(void EQ_Character::DoIntimidationEvent(), EQ_Character__DoIntimidationEvent);
#endif
#ifdef EQ_Character__DoFishingEvent_x
FUNCTION_AT_ADDRESS(void EQ_Character::DoFishingEvent(), EQ_Character__DoFishingEvent);
#endif
#ifdef EQ_Character__FindClosest_x
FUNCTION_AT_ADDRESS(EQPlayer* EQ_Character::FindClosest(int, int, int, int, int), EQ_Character__FindClosest);
#endif
#ifdef EQ_Character__IAmDead_x
FUNCTION_AT_ADDRESS(void EQ_Character::IAmDead(struct _EQMissileHitinfo*, int), EQ_Character__IAmDead);
#endif
#ifdef EQ_Character__TotalOnPerson_x
FUNCTION_AT_ADDRESS(long EQ_Character::TotalOnPerson(), EQ_Character__TotalOnPerson);
#endif
#ifdef EQ_Character__ItemSold_x
FUNCTION_AT_ADDRESS(void EQ_Character::ItemSold(long), EQ_Character__ItemSold);
#endif
#ifdef EQ_Character__TakeFallDamage_x
FUNCTION_AT_ADDRESS(int EQ_Character::TakeFallDamage(float), EQ_Character__TakeFallDamage);
#endif
#ifdef EQ_Character__IHaveSkill_x
FUNCTION_AT_ADDRESS(int EQ_Character::IHaveSkill(unsigned char), EQ_Character__IHaveSkill);
#endif
#ifdef EQ_Character__NoMezMe_x
FUNCTION_AT_ADDRESS(int EQ_Character::NoMezMe(int, EQPlayer*, EQ_Spell*), EQ_Character__NoMezMe);
#endif
#ifdef EQ_Character__NoBashMe_x
FUNCTION_AT_ADDRESS(int EQ_Character::NoBashMe(int), EQ_Character__NoBashMe);
#endif
#ifdef EQ_Character__StunMe_x
FUNCTION_AT_ADDRESS(void EQ_Character1::StunMe(unsigned int, bool, bool, bool), EQ_Character__StunMe);
#endif
#ifdef EQ_Character__UnStunMe_x
FUNCTION_AT_ADDRESS(void EQ_Character1::UnStunMe(), EQ_Character__UnStunMe);
#endif
#ifdef EQ_Character__ApplyDamage_x
FUNCTION_AT_ADDRESS(int EQ_Character::ApplyDamage(int, struct _EQMissileHitinfo*, bool, HateListEntry*, bool), EQ_Character__ApplyDamage);
#endif
#ifdef EQ_Character__NotifyPCAffectChange_x
FUNCTION_AT_ADDRESS(void EQ_Character::NotifyPCAffectChange(int, int), EQ_Character__NotifyPCAffectChange);
#endif
#ifdef EQ_Character__UpdateMyVisibleStatus_x
FUNCTION_AT_ADDRESS(void EQ_Character::UpdateMyVisibleStatus(), EQ_Character__UpdateMyVisibleStatus);
#endif
#ifdef EQ_Character__CanISeeInvis_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::CanISeeInvis(), EQ_Character__CanISeeInvis);
#endif
#ifdef EQ_Character__CanIBreathe_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::CanIBreathe(), EQ_Character__CanIBreathe);
#endif
#ifdef EQ_Character__ProcessEnvironment_x
FUNCTION_AT_ADDRESS(void EQ_Character::ProcessEnvironment(), EQ_Character__ProcessEnvironment);
#endif
#ifdef EQ_Character__ProcessHungerandThirst_x
FUNCTION_AT_ADDRESS(void EQ_Character::ProcessHungerandThirst(unsigned int), EQ_Character__ProcessHungerandThirst);
#endif
#ifdef EQ_Character__ItemSpellAffects_x
FUNCTION_AT_ADDRESS(int EQ_Character::ItemSpellAffects(int), EQ_Character__ItemSpellAffects);
#endif
#ifdef EQ_Character__ProcessAllStats_x
FUNCTION_AT_ADDRESS(void EQ_Character::ProcessAllStats(), EQ_Character__ProcessAllStats);
#endif
#ifdef EQ_Character__DoPassageOfTime_x
FUNCTION_AT_ADDRESS(void EQ_Character::DoPassageOfTime(), EQ_Character__DoPassageOfTime);
#endif
#ifdef EQ_Character__FindItemByClass_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::FindItemByClass(int, int*, int*), EQ_Character__FindItemByClass);
#endif
#ifdef EQ_Character__FindItemQty_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::FindItemQty(int, int), EQ_Character__FindItemQty);
#endif
#ifdef EQ_Character__CanMedOnHorse_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::CanMedOnHorse(), EQ_Character__CanMedOnHorse);
#endif
#ifdef EQ_Character__ExpendItemCharge_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::ExpendItemCharge(int, int), EQ_Character__ExpendItemCharge);
#endif
#ifdef EQ_Character__AutoEat_x
FUNCTION_AT_ADDRESS(int EQ_Character::AutoEat(unsigned char), EQ_Character__AutoEat);
#endif
#ifdef EQ_Character__CheckFoodAndWater_x
FUNCTION_AT_ADDRESS(int EQ_Character::CheckFoodAndWater(), EQ_Character__CheckFoodAndWater);
#endif
#ifdef EQ_Character__DoMeditation_x
FUNCTION_AT_ADDRESS(void EQ_Character::DoMeditation(), EQ_Character__DoMeditation);
#endif
#ifdef EQ_Character__SetLocalVar_x
FUNCTION_AT_ADDRESS(int EQ_Character::SetLocalVar(char*, int), EQ_Character__SetLocalVar);
#endif
#ifdef EQ_Character__GetIndexSkillMinDamageMod_x
FUNCTION_AT_ADDRESS(int EQ_Character::GetIndexSkillMinDamageMod(int), EQ_Character__GetIndexSkillMinDamageMod);
#endif
#ifdef EQ_Character__GetFocusConserveRegChance_x
FUNCTION_AT_ADDRESS(int const EQ_Character::GetFocusConserveRegChance(EQ_Spell const*, EQ_Equipment**), EQ_Character__GetFocusConserveRegChance);
#endif
#ifdef EQ_Character__GetFocusCastingTimeModifier_x
FUNCTION_AT_ADDRESS(const int EQ_Character1::GetFocusCastingTimeModifier(const EQ_Spell* pSpell, VePointer<CONTENTS>& pItemOut, bool bEvalOnly), EQ_Character__GetFocusCastingTimeModifier);
#endif
#ifdef EQ_Character__GetFocusRangeModifier_x
FUNCTION_AT_ADDRESS(const int EQ_Character1::GetFocusRangeModifier(const EQ_Spell* pSpell, VePointer<CONTENTS>& pItemOut), EQ_Character__GetFocusRangeModifier);
#endif
#ifdef EQ_Character__IsExpansionFlag_x
FUNCTION_AT_ADDRESS(int EQ_Character1::IsExpansionFlag(int), EQ_Character__IsExpansionFlag);
#endif
#ifdef EQ_Character__GetFocusItem_x
FUNCTION_AT_ADDRESS(EQ_Equipment* EQ_Character::GetFocusItem(EQ_Spell const*, int), EQ_Character__GetFocusItem);
#endif
#ifdef EQ_Character__GetFocusEffect_x
FUNCTION_AT_ADDRESS(EQ_Spell* EQ_Character::GetFocusEffect(EQ_Spell const*, int), EQ_Character__GetFocusEffect);
#endif
#ifdef EQ_Character__DoesSpellMatchFocusFilters_x
FUNCTION_AT_ADDRESS(bool EQ_Character::DoesSpellMatchFocusFilters(EQ_Spell const*, EQ_Spell const*), EQ_Character__DoesSpellMatchFocusFilters);
#endif
#ifdef EQ_Character__GetMyPetPlayer_x
FUNCTION_AT_ADDRESS(EQPlayer* EQ_Character::GetMyPetPlayer(), EQ_Character__GetMyPetPlayer);
#endif
#ifdef EQ_Character__SetEffectId_x
FUNCTION_AT_ADDRESS(void EQ_Character1::SetEffectId(unsigned char, unsigned int), EQ_Character__SetEffectId);
#endif
#ifdef EQ_Character__CastSpell_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character1::CastSpell(unsigned char gemid, int spellid, EQ_Item** ppItem, const ItemGlobalIndex&, enum ItemSpellTypes slot, unsigned char spell_loc, int arg7, int arg8, int arg9, bool arg10), EQ_Character__CastSpell);
#endif
#ifdef EQ_Character__GetBardInstrumentMod_x
FUNCTION_AT_ADDRESS(int EQ_Character::GetBardInstrumentMod(int), EQ_Character__GetBardInstrumentMod);
#endif
#ifdef EQ_Character__CalculateBardSongMod_x
FUNCTION_AT_ADDRESS(int EQ_Character::CalculateBardSongMod(int), EQ_Character__CalculateBardSongMod);
#endif
#ifdef EQ_Character__CastingRequirementsMet_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::CastingRequirementsMet(int), EQ_Character__CastingRequirementsMet);
#endif
#ifdef EQ_Character__GetCastingTimeModifier_x
FUNCTION_AT_ADDRESS(const int EQ_Character1::GetCastingTimeModifier(const EQ_Spell*), EQ_Character__GetCastingTimeModifier);
#endif
#ifdef EQ_Character__IsValidAffect_x
FUNCTION_AT_ADDRESS(bool EQ_Character::IsValidAffect(int), EQ_Character__IsValidAffect);
#endif
#ifdef EQ_Character__LaunchSpell_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::LaunchSpell(unsigned char, int, EQ_Item**), EQ_Character__LaunchSpell);
#endif
#ifdef EQ_Character__HandleSpecialPCAffects_x
FUNCTION_AT_ADDRESS(void EQ_Character::HandleSpecialPCAffects(int), EQ_Character__HandleSpecialPCAffects);
#endif
#ifdef EQ_Character__GetPCSpellAffect_x
FUNCTION_AT_ADDRESS(EQ_Affect* EQ_Character::GetPCSpellAffect(int theaffect, int* slotnum, int* spaslot) const, EQ_Character__GetPCSpellAffect);
#endif
#ifdef EQ_Character__TotalSpellAffects_x
FUNCTION_AT_ADDRESS(int EQ_Character::TotalSpellAffects(unsigned char, bool, int*), EQ_Character__TotalSpellAffects);
#endif
#ifdef EQ_Character__IsSpellAffectingPC_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::IsSpellAffectingPC(int, int), EQ_Character__IsSpellAffectingPC);
#endif
#ifdef EQ_Character__SpellFizzled_x
FUNCTION_AT_ADDRESS(unsigned char EQ_Character::SpellFizzled(unsigned char, EQ_Spell*), EQ_Character__SpellFizzled);
#endif
#ifdef EQ_Character__ProcessAffects_x
FUNCTION_AT_ADDRESS(int EQ_Character::ProcessAffects(), EQ_Character__ProcessAffects);
#endif
#ifdef EQ_Character__GetOpenEffectSlot_x
FUNCTION_AT_ADDRESS(int EQ_Character::GetOpenEffectSlot(bool, int), EQ_Character__GetOpenEffectSlot);
#endif
#ifdef EQ_Character__GetFirstEffectSlot_x
FUNCTION_AT_ADDRESS(int EQ_Character::GetFirstEffectSlot(bool), EQ_Character__GetFirstEffectSlot);
#endif
#ifdef EQ_Character__GetLastEffectSlot_x
FUNCTION_AT_ADDRESS(int EQ_Character::GetLastEffectSlot(bool), EQ_Character__GetLastEffectSlot);
#endif
#ifdef EQ_Character__IsSpellTooPowerfull_x
FUNCTION_AT_ADDRESS(bool EQ_Character::IsSpellTooPowerfull(EQ_Spell*, EQ_Character*), EQ_Character__IsSpellTooPowerfull);
#endif
#ifdef EQ_Character__HitBySpell_x
FUNCTION_AT_ADDRESS(void EQ_Character::HitBySpell(struct _EQMissileHitinfo*), EQ_Character__HitBySpell);
#endif
#ifdef EQ_Character__EQSPA_Feign_Death_x
FUNCTION_AT_ADDRESS(void EQ_Character::EQSPA_Feign_Death(int), EQ_Character__EQSPA_Feign_Death);
#endif
#ifdef EQ_Character__SpellDuration_x
FUNCTION_AT_ADDRESS(int EQ_Character::SpellDuration(EQ_Spell const*, unsigned char, unsigned char), EQ_Character__SpellDuration);
#endif
#ifdef EQ_Character__eqspa_change_form_x
FUNCTION_AT_ADDRESS(int EQ_Character::eqspa_change_form(EQ_Spell*, int, int, EQ_Affect*), EQ_Character__eqspa_change_form);
#endif
#ifdef EQ_Character__eqspa_movement_rate_x
FUNCTION_AT_ADDRESS(void EQ_Character::eqspa_movement_rate(int), EQ_Character__eqspa_movement_rate);
#endif
#ifdef EQ_Character__eqspa_levitation_x
FUNCTION_AT_ADDRESS(void EQ_Character::eqspa_levitation(), EQ_Character__eqspa_levitation);
#endif
#ifdef EQ_Character__eqspa_hp_x
FUNCTION_AT_ADDRESS(int EQ_Character::eqspa_hp(unsigned int, EQ_Affect*, int, EQ_Spell*), EQ_Character__eqspa_hp);
#endif
#ifdef EQ_Character__eqspa_locate_corpse_x
FUNCTION_AT_ADDRESS(void EQ_Character::eqspa_locate_corpse(), EQ_Character__eqspa_locate_corpse);
#endif
#ifdef EQ_Character__InSpecialBindSpot_x
FUNCTION_AT_ADDRESS(int EQ_Character::InSpecialBindSpot(EQPlayer*), EQ_Character__InSpecialBindSpot);
#endif
#ifdef EQ_Character__RemovePCAffect_x
FUNCTION_AT_ADDRESS(void EQ_Character::RemovePCAffect(EQ_Affect*), EQ_Character__RemovePCAffect);
#endif
#ifdef EQ_Character__RemovePCAffectex_x
FUNCTION_AT_ADDRESS(void EQ_Character::RemovePCAffectex(EQ_Affect*, int), EQ_Character__RemovePCAffectex);
#endif
#ifdef EQ_Character__StopSpellCast_x
FUNCTION_AT_ADDRESS(void EQ_Character1::StopSpellCast(unsigned char), EQ_Character__StopSpellCast);
#endif
#ifdef EQ_Character__StopSpellCast1_x
FUNCTION_AT_ADDRESS(void EQ_Character1::StopSpellCast(unsigned char, int), EQ_Character__StopSpellCast1);
#endif
#ifdef EQ_Character__ReCachSpellEffects_x
FUNCTION_AT_ADDRESS(void EQ_Character::ReCachSpellEffects(), EQ_Character__ReCachSpellEffects);
#endif
#ifdef EQ_Character__ReCachItemEffects_x
FUNCTION_AT_ADDRESS(void EQ_Character::ReCachItemEffects(), EQ_Character__ReCachItemEffects);
#endif
#ifdef EQ_Character__GetCachEQSPA_x
FUNCTION_AT_ADDRESS(int EQ_Character::GetCachEQSPA(int), EQ_Character__GetCachEQSPA);
#endif
#ifdef EQ_Character__GetConLevel_x
FUNCTION_AT_ADDRESS(unsigned long EQ_Character::GetConLevel(const PlayerClient*), EQ_Character__GetConLevel);
#endif
#ifdef EQ_Character__TotalEffect_x
FUNCTION_AT_ADDRESS(int EQ_Character1::TotalEffect(int, bool, int, bool, bool), EQ_Character__TotalEffect);
#endif
#ifdef EQ_Character__GetAdjustedSkill_x
FUNCTION_AT_ADDRESS(int EQ_Character1::GetAdjustedSkill(int), EQ_Character__GetAdjustedSkill);
#endif
#ifdef EQ_Character__GetBaseSkill_x
FUNCTION_AT_ADDRESS(int EQ_Character1::GetBaseSkill(int), EQ_Character__GetBaseSkill);
#endif

//============================================================================
// EQ_CharacterData
//============================================================================

#ifdef EQ_CharacterData__EQ_CharacterDataResetAllMembers_x
FUNCTION_AT_ADDRESS(void EQ_CharacterData::EQ_CharacterDataResetAllMembers(), EQ_CharacterData__EQ_CharacterDataResetAllMembers);
#endif

//============================================================================
// EQ_PC
//============================================================================

#ifdef EQ_PC__EQ_PC_x
FUNCTION_AT_ADDRESS(EQ_PC::EQ_PC(EQ_PC*), EQ_PC__EQ_PC);
#endif
#ifdef EQ_PC__dEQ_PC_x
FUNCTION_AT_ADDRESS(EQ_PC::~EQ_PC(), EQ_PC__dEQ_PC);
#endif
#ifdef EQ_PC__ClearSharedVault_x
FUNCTION_AT_ADDRESS(void EQ_PC::ClearSharedVault(), EQ_PC__ClearSharedVault);
#endif
#ifdef EQ_PC__IsAGroupMember_x
FUNCTION_AT_ADDRESS(int EQ_PC::IsAGroupMember(char*), EQ_PC__IsAGroupMember);
#endif
#ifdef EQ_PC__CheckForGroupChanges_x
FUNCTION_AT_ADDRESS(void EQ_PC::CheckForGroupChanges(), EQ_PC__CheckForGroupChanges);
#endif
#ifdef EQ_PC__UnpackMyNetPC_x
FUNCTION_AT_ADDRESS(void EQ_PC::UnpackMyNetPC(char*, int), EQ_PC__UnpackMyNetPC);
#endif
#ifdef EQ_PC__AlertInventoryChanged_x
FUNCTION_AT_ADDRESS(void EQ_PC::AlertInventoryChanged(), EQ_PC__AlertInventoryChanged);
#endif
#ifdef EQ_PC__InitPlayerStart_x
FUNCTION_AT_ADDRESS(void EQ_PC::InitPlayerStart(unsigned int, unsigned char, int), EQ_PC__InitPlayerStart);
#endif
#ifdef EQ_PC__EmptyPossessionSlots_x
FUNCTION_AT_ADDRESS(void EQ_PC::EmptyPossessionSlots(), EQ_PC__EmptyPossessionSlots);
#endif
#ifdef EQ_PC__RefreshMe_x
FUNCTION_AT_ADDRESS(void EQ_PC::RefreshMe(int), EQ_PC__RefreshMe);
#endif
#ifdef EQ_PC__PrepareForRepop_x
FUNCTION_AT_ADDRESS(void EQ_PC::PrepareForRepop(int), EQ_PC__PrepareForRepop);
#endif
#ifdef EQ_PC__RefitNewbieEQ_x
FUNCTION_AT_ADDRESS(void EQ_PC::RefitNewbieEQ(), EQ_PC__RefitNewbieEQ);
#endif
#ifdef EQ_PC__RemoveMyAffect_x
FUNCTION_AT_ADDRESS(unsigned char EQ_PC::RemoveMyAffect(int), EQ_PC__RemoveMyAffect);
#endif
#ifdef EQ_PC__ProcessFatigue_x
FUNCTION_AT_ADDRESS(void EQ_PC::ProcessFatigue(), EQ_PC__ProcessFatigue);
#endif
#ifdef EQ_PC__DelLoreItemDup_x
FUNCTION_AT_ADDRESS(int EQ_PC::DelLoreItemDup(int, int, int, EQ_Item*), EQ_PC__DelLoreItemDup);
#endif
#ifdef EQ_PC__CheckDupLoreItems_x
FUNCTION_AT_ADDRESS(int EQ_PC::CheckDupLoreItems(), EQ_PC__CheckDupLoreItems);
#endif
#ifdef EQ_PC__CostToTrain_x
FUNCTION_AT_ADDRESS(int EQ_PC::CostToTrain(int, float, int), EQ_PC__CostToTrain);
#endif
#ifdef EQ_PC__checkLang_x
FUNCTION_AT_ADDRESS(int EQ_PC::checkLang(int), EQ_PC__checkLang);
#endif
#ifdef EQ_PC__BitchCanTrain_x
FUNCTION_AT_ADDRESS(int EQ_PC::BitchCanTrain(int, int, int), EQ_PC__BitchCanTrain);
#endif
#ifdef EQ_PC__HandleMoney_x
FUNCTION_AT_ADDRESS(int EQ_PC::HandleMoney(long), EQ_PC__HandleMoney);
#endif
#ifdef EQ_PC__DetermineQuestExpGained_x
FUNCTION_AT_ADDRESS(void EQ_PC::DetermineQuestExpGained(int), EQ_PC__DetermineQuestExpGained);
#endif
#ifdef EQ_PC__ProcessAirSupply_x
FUNCTION_AT_ADDRESS(void EQ_PC::ProcessAirSupply(), EQ_PC__ProcessAirSupply);
#endif
#ifdef EQ_PC__MaxAirSupply_x
FUNCTION_AT_ADDRESS(int EQ_PC::MaxAirSupply(), EQ_PC__MaxAirSupply);
#endif
#ifdef EQ_PC__SetFatigue_x
FUNCTION_AT_ADDRESS(void EQ_PC::SetFatigue(int), EQ_PC__SetFatigue);
#endif
#ifdef EQ_PC__numInParty_x
FUNCTION_AT_ADDRESS(int EQ_PC::numInParty(), EQ_PC__numInParty);
#endif
#ifdef EQ_PC__AtSkillLimit_x
FUNCTION_AT_ADDRESS(unsigned char EQ_PC::AtSkillLimit(int), EQ_PC__AtSkillLimit);
#endif
#ifdef EQ_PC__GetItemRecastTimer_x
FUNCTION_AT_ADDRESS(unsigned long EQ_PC::GetItemRecastTimer(EQ_Item* item, ItemSpellTypes etype), EQ_PC__GetItemRecastTimer);
#endif
#ifdef EQ_PC__GetAlternateAbilityId_x
FUNCTION_AT_ADDRESS(int EQ_PC::GetAlternateAbilityId(int), EQ_PC__GetAlternateAbilityId);
#endif
#ifdef EQ_PC__GetCombatAbility_x
FUNCTION_AT_ADDRESS(int EQ_PC::GetCombatAbility(int), EQ_PC__GetCombatAbility);
#endif
#ifdef EQ_PC__GetPcZoneClient_x
FUNCTION_AT_ADDRESS(PcZoneClient* EQ_PC::GetPcZoneClient() const, EQ_PC__GetPcZoneClient);
#endif
#ifdef EQ_PC__GetCombatAbilityTimer_x
FUNCTION_AT_ADDRESS(unsigned long EQ_PC::GetCombatAbilityTimer(int, int), EQ_PC__GetCombatAbilityTimer);
#endif
#ifdef EQ_PC__HasLoreItem_x
FUNCTION_AT_ADDRESS(bool EQ_PC::HasLoreItem(EQ_Item*, int, int, int, int), EQ_PC__HasLoreItem);
#endif
#ifdef EQ_PC__GetItemContainedRealEstateIds_x
FUNCTION_AT_ADDRESS(void EQ_PC::GetItemContainedRealEstateIds(ArrayClass<ItemContainingRealEstate>&, bool, bool, bool), EQ_PC__GetItemContainedRealEstateIds);
#endif
#ifdef EQ_PC__GetNonArchivedOwnedRealEstates_x
FUNCTION_AT_ADDRESS(void EQ_PC::GetNonArchivedOwnedRealEstates(ArrayClass<int>&), EQ_PC__GetNonArchivedOwnedRealEstates);
#endif
#ifdef EQ_PC__CheckForLanguageImprovement_x
FUNCTION_AT_ADDRESS(void EQ_PC::CheckForLanguageImprovement(unsigned char, unsigned char), EQ_PC__CheckForLanguageImprovement);
#endif
#ifdef EQ_PC__CheckSkillImprove_x
FUNCTION_AT_ADDRESS(void EQ_PC::CheckSkillImprove(int, float), EQ_PC__CheckSkillImprove);
#endif
#ifdef EQ_PC__GetBodyTint_x
FUNCTION_AT_ADDRESS(unsigned long EQ_PC::GetBodyTint(int), EQ_PC__GetBodyTint);
#endif
#ifdef EQ_PC__SetAltAbilityIndex_x
FUNCTION_AT_ADDRESS(void EQ_PC::SetAltAbilityIndex(int, int), EQ_PC__SetAltAbilityIndex);
#endif
#ifdef EQ_PC__GetArmorTint_x
FUNCTION_AT_ADDRESS(unsigned long EQ_PC::GetArmorTint(int), EQ_PC__GetArmorTint);
#endif
#ifdef EQ_PC__SetArmorTint_x
FUNCTION_AT_ADDRESS(void EQ_PC::SetArmorTint(int, unsigned long), EQ_PC__SetArmorTint);
#endif
#ifdef EQ_PC__GetArmorType_x
FUNCTION_AT_ADDRESS(int EQ_PC::GetArmorType(int), EQ_PC__GetArmorType);
#endif
#ifdef EQ_PC__SetArmorType_x
FUNCTION_AT_ADDRESS(void EQ_PC::SetArmorType(int, int), EQ_PC__SetArmorType);
#endif
#ifdef EQ_PC__InitializeNewPCVariables_x
FUNCTION_AT_ADDRESS(void EQ_PC::InitializeNewPCVariables(int), EQ_PC__InitializeNewPCVariables);
#endif
#ifdef EQ_PC__DestroyHeldItemOrMoney_x
FUNCTION_AT_ADDRESS(void EQ_PC::DestroyHeldItemOrMoney(), EQ_PC__DestroyHeldItemOrMoney);
#endif

//============================================================================
// PcClient
//============================================================================

#ifdef PcClient__PcClient_x
//FUNCTION_AT_ADDRESS(PcClient::PcClient(), PcClient__PcClient);
#endif

//============================================================================
// PcZoneClient
//============================================================================

#ifdef PcZoneClient__GetPcSkillLimit_x
FUNCTION_AT_ADDRESS(int PcZoneClient::GetPcSkillLimit(int), PcZoneClient__GetPcSkillLimit);
#endif
#ifdef PcZoneClient__HasCombatAbility_x
FUNCTION_AT_ADDRESS(bool PcZoneClient::HasCombatAbility(int), PcZoneClient__HasCombatAbility);
#endif
#ifdef PcZoneClient__RemovePetEffect_x
FUNCTION_AT_ADDRESS(void PcZoneClient::RemovePetEffect(int), PcZoneClient__RemovePetEffect);
#endif
#ifdef PcZoneClient__HasAlternateAbility_x
FUNCTION_AT_ADDRESS(bool PcZoneClient::HasAlternateAbility(int aaindex, int*, bool, bool), PcZoneClient__HasAlternateAbility);
#endif
#ifdef PcZoneClient__GetItemByID_x
FUNCTION_AT_ADDRESS(CONTENTS** PcZoneClient::GetItemByID(CONTENTS** contOut, int itemid, ItemIndex*), PcZoneClient__GetItemByID);
#endif
#ifdef PcZoneClient__GetItemByItemClass_x
FUNCTION_AT_ADDRESS(CONTENTS** PcZoneClient::GetItemByItemClass(CONTENTS** contOut, int itemclass, ItemIndex*), PcZoneClient__GetItemByItemClass);
#endif
#ifdef PcZoneClient__CanEquipItem_x
FUNCTION_AT_ADDRESS(bool PcZoneClient::CanEquipItem(CONTENTS** pCont, int slotid, bool bOutputDebug, bool bUseRequiredLevel), PcZoneClient__CanEquipItem);
#endif
#ifdef PcZoneClient__GetCurrentMod_x
FUNCTION_AT_ADDRESS(int PcZoneClient::GetCurrentMod(int index), PcZoneClient__GetCurrentMod);
#endif
#ifdef PcZoneClient__GetModCap_x
FUNCTION_AT_ADDRESS(int PcZoneClient::GetModCap(int index, bool bToggle), PcZoneClient__GetModCap);
#endif
#ifdef PcZoneClient__RemoveBuffEffect_x
FUNCTION_AT_ADDRESS(void PcZoneClient::RemoveBuffEffect(int Index, int SpawnID), PcZoneClient__RemoveBuffEffect);
#endif
#ifdef PcZoneClient__BandolierSwap_x
FUNCTION_AT_ADDRESS(void PcZoneClient::BandolierSwap(int index), PcZoneClient__BandolierSwap);
#endif
#ifdef PcZoneClient__GetLinkedSpellReuseTimer_x
FUNCTION_AT_ADDRESS(UINT PcZoneClient::GetLinkedSpellReuseTimer(int index), PcZoneClient__GetLinkedSpellReuseTimer);
#endif

//============================================================================
// ProfileManager
//============================================================================

#ifdef ProfileManager__GetCurrentProfile_x
FUNCTION_AT_ADDRESS(BaseProfile* ProfileManager::GetCurrentProfile(), ProfileManager__GetCurrentProfile);
#endif

} // namespace eqlib
