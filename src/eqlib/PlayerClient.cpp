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

#include "Globals.h"
#include "PlayerClient.h"

namespace eqlib {

//============================================================================
// ActorBase
//============================================================================

FUNCTION_AT_VIRTUAL_ADDRESS(float ActorBase::GetBoundingRadius(), 0x60);

//============================================================================
// ActorClient
//============================================================================

#ifdef ActorClient__GetPosition_x
FUNCTION_AT_ADDRESS(const CVector3& ActorClient::GetPosition() const, ActorClient__GetPosition);
#endif
#ifdef ActorClient__GetPosition1_x
FUNCTION_AT_ADDRESS(void ActorClient::GetPosition(CVector3*) const, ActorClient__GetPosition1);
#endif


//============================================================================
// EQPlayer
//============================================================================

#ifdef EQPlayer__GetGuild_x
FUNCTION_AT_ADDRESS(int EQPlayer::GetGuild() const, EQPlayer__GetGuild);
#endif
#ifdef EQPlayer__DoCamAi_x
FUNCTION_AT_ADDRESS(void EQPlayer::DoCamAi(), EQPlayer__DoCamAi);
#endif
#ifdef EQPlayer__CanIFitHere_x
FUNCTION_AT_ADDRESS(bool PlayerZoneClient::CanIFitHere(const CVector3&, bool), EQPlayer__CanIFitHere);
#endif
#ifdef EQPlayer__MovePlayer_x
FUNCTION_AT_ADDRESS(int PlayerZoneClient::MovePlayer(), EQPlayer__MovePlayer);
#endif
#ifdef EQPlayer__EQPlayer_x
FUNCTION_AT_ADDRESS(void PlayerClient::Initialize(PlayerClient*, unsigned char, unsigned int, unsigned char, char*), EQPlayer__EQPlayer);
#endif
#ifdef EQPlayer__dEQPlayer_x
FUNCTION_AT_ADDRESS(PlayerClient::~PlayerClient(), EQPlayer__dEQPlayer);
#endif
#ifdef EQPlayer__ResetVariables_x
FUNCTION_AT_ADDRESS(void EQPlayer::ResetVariables(), EQPlayer__ResetVariables);
#endif
#ifdef EQPlayer__do_change_form_x
FUNCTION_AT_ADDRESS(void EQPlayer::do_change_form(struct chngForm*), EQPlayer__do_change_form);
#endif
#ifdef EQPlayer__DisplayWeaponsAndArmor_x
FUNCTION_AT_ADDRESS(void EQPlayer::DisplayWeaponsAndArmor(), EQPlayer__DisplayWeaponsAndArmor);
#endif
#ifdef EQPlayer__CleanUpTarget_x
FUNCTION_AT_ADDRESS(void EQPlayer::CleanUpTarget(), EQPlayer__CleanUpTarget);
#endif
#ifdef EQPlayer__FollowPlayerAI_x
FUNCTION_AT_ADDRESS(void EQPlayer::FollowPlayerAI(), EQPlayer__FollowPlayerAI);
#endif
#ifdef EQPlayer__TurnOffAutoFollow_x
FUNCTION_AT_ADDRESS(void EQPlayer::TurnOffAutoFollow(), EQPlayer__TurnOffAutoFollow);
#endif
#ifdef EQPlayer__AimAtTarget_x
FUNCTION_AT_ADDRESS(int EQPlayer::AimAtTarget(EQPlayer*, EQMissile*), EQPlayer__AimAtTarget);
#endif
#ifdef EQPlayer__FacePlayer_x
FUNCTION_AT_ADDRESS(void EQPlayer::FacePlayer(EQPlayer*), EQPlayer__FacePlayer);
#endif
#ifdef EQPlayer__CleanUpVehicle_x
FUNCTION_AT_ADDRESS(void EQPlayer::CleanUpVehicle(), EQPlayer__CleanUpVehicle);
#endif
#ifdef EQPlayer__CleanUpMyEffects_x
FUNCTION_AT_ADDRESS(void EQPlayer::CleanUpMyEffects(), EQPlayer__CleanUpMyEffects);
#endif
#ifdef EQPlayer__GetPlayerFromName_x
FUNCTION_AT_ADDRESS(EQPlayer* __cdecl EQPlayer::GetPlayerFromName(const char*), EQPlayer__GetPlayerFromName);
#endif
#ifdef EQPlayer__GetPlayerFromPartialName_x
FUNCTION_AT_ADDRESS(EQPlayer* __cdecl EQPlayer::GetPlayerFromPartialName(char*), EQPlayer__GetPlayerFromPartialName);
#endif
#ifdef EQPlayer__GetClosestPlayerFromPartialName_x
FUNCTION_AT_ADDRESS(EQPlayer* __cdecl EQPlayer::GetClosestPlayerFromPartialName(char*, EQPlayer*), EQPlayer__GetClosestPlayerFromPartialName);
#endif
#ifdef EQPlayer__IsPlayerActor_x
FUNCTION_AT_ADDRESS(EQPlayer* __cdecl EQPlayer::IsPlayerActor(struct T3D_tagACTORINSTANCE*), EQPlayer__IsPlayerActor);
#endif
#ifdef EQPlayer__TackOnNeuterChar_x
FUNCTION_AT_ADDRESS(void __cdecl EQPlayer::TackOnNeuterChar(char*, unsigned int), EQPlayer__TackOnNeuterChar);
#endif
#ifdef EQPlayer__GetActorTag_x
FUNCTION_AT_ADDRESS(void EQPlayer::GetActorTag(char*), EQPlayer__GetActorTag);
#endif
#ifdef EQPlayer__GetPCActorTag_x
FUNCTION_AT_ADDRESS(void __cdecl EQPlayer::GetPCActorTag(char*, unsigned int, unsigned char), EQPlayer__GetPCActorTag);
#endif
#ifdef EQPlayer__NotOnSameDeity_x
FUNCTION_AT_ADDRESS(int EQPlayer::NotOnSameDeity(EQPlayer*, EQ_Spell*), EQPlayer__NotOnSameDeity);
#endif
#ifdef EQPlayer__SetAnimVariation_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetAnimVariation(), EQPlayer__SetAnimVariation);
#endif
#ifdef EQPlayer__SetAfk_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetAfk(int), EQPlayer__SetAfk);
#endif
#ifdef EQPlayer__AllowedToAttack_x
FUNCTION_AT_ADDRESS(bool EQPlayer::AllowedToAttack(EQPlayer*, int), EQPlayer__AllowedToAttack);
#endif
#ifdef EQPlayer__CanIHit_x
FUNCTION_AT_ADDRESS(bool EQPlayer::CanIHit(EQPlayer*, float), EQPlayer__CanIHit);
#endif
#ifdef EQPlayer__CanSee_x
FUNCTION_AT_ADDRESS(bool PlayerBase::CanSee(const PlayerBase&), EQPlayer__CanSee);
#endif
#ifdef EQPlayer__CanSee1_x
FUNCTION_AT_ADDRESS(bool PlayerBase::CanSee(const CVector3& pos), EQPlayer__CanSee1);
#endif
#ifdef EQPlayer__ModifyAttackSpeed_x
FUNCTION_AT_ADDRESS(unsigned int EQPlayer::ModifyAttackSpeed(unsigned int, int), EQPlayer__ModifyAttackSpeed);
#endif
#ifdef EQPlayer__DoAttack_x
FUNCTION_AT_ADDRESS(bool PlayerZoneClient::DoAttack(BYTE, BYTE, PlayerZoneClient*, bool, bool, bool), EQPlayer__DoAttack);
#endif
#ifdef EQPlayer__HandleAmmo_x
FUNCTION_AT_ADDRESS(unsigned char EQPlayer::HandleAmmo(), EQPlayer__HandleAmmo);
#endif
#ifdef EQPlayer__TriggerSpellEffect_x
FUNCTION_AT_ADDRESS(void EQPlayer::TriggerSpellEffect(struct _EQMissileHitinfo*), EQPlayer__TriggerSpellEffect);
#endif
#ifdef EQPlayer__IWasHit_x
FUNCTION_AT_ADDRESS(bool EQPlayer::IWasHit(struct _EQMissileHitinfo*), EQPlayer__IWasHit);
#endif
#ifdef EQPlayer__GetConscious_x
FUNCTION_AT_ADDRESS(void EQPlayer::GetConscious(), EQPlayer__GetConscious);
#endif
#ifdef EQPlayer__KnockedOut_x
FUNCTION_AT_ADDRESS(void EQPlayer::KnockedOut(), EQPlayer__KnockedOut);
#endif
#ifdef EQPlayer__IDied_x
FUNCTION_AT_ADDRESS(void EQPlayer::IDied(struct _EQPlayerDeath*), EQPlayer__IDied);
#endif
#ifdef EQPlayer__HandoverControlToZoneserver_x
FUNCTION_AT_ADDRESS(void EQPlayer::HandoverControlToZoneserver(), EQPlayer__HandoverControlToZoneserver);
#endif
#ifdef EQPlayer__TouchingSwitch_x
FUNCTION_AT_ADDRESS(void EQPlayer::TouchingSwitch(), EQPlayer__TouchingSwitch);
#endif
#ifdef EQPlayer__MyFeetAreOnGround_x
FUNCTION_AT_ADDRESS(bool EQPlayer::MyFeetAreOnGround(), EQPlayer__MyFeetAreOnGround);
#endif
#ifdef EQPlayer__IHaveFallen_x
FUNCTION_AT_ADDRESS(void EQPlayer::IHaveFallen(float), EQPlayer__IHaveFallen);
#endif
#ifdef EQPlayer__SkillUsed_x
FUNCTION_AT_ADDRESS(unsigned char EQPlayer::SkillUsed(unsigned char), EQPlayer__SkillUsed);
#endif
#ifdef EQPlayer__BodyEnvironmentChange_x
FUNCTION_AT_ADDRESS(void EQPlayer::BodyEnvironmentChange(unsigned char), EQPlayer__BodyEnvironmentChange);
#endif
#ifdef EQPlayer__FeetEnvironmentChange_x
FUNCTION_AT_ADDRESS(void EQPlayer::FeetEnvironmentChange(unsigned char), EQPlayer__FeetEnvironmentChange);
#endif
#ifdef EQPlayer__HeadEnvironmentChange_x
FUNCTION_AT_ADDRESS(void EQPlayer::HeadEnvironmentChange(unsigned char), EQPlayer__HeadEnvironmentChange);
#endif
#ifdef EQPlayer__DeleteMyMissiles_x
FUNCTION_AT_ADDRESS(void EQPlayer::DeleteMyMissiles(), EQPlayer__DeleteMyMissiles);
#endif
#ifdef EQPlayer__ChangePosition_x
FUNCTION_AT_ADDRESS(void EQPlayer::ChangePosition(unsigned char), EQPlayer__ChangePosition);
#endif
#ifdef EQPlayer__ChangeHeight_x
FUNCTION_AT_ADDRESS(void EQPlayer::ChangeHeight(float), EQPlayer__ChangeHeight);
#endif
#ifdef EQPlayer__PositionOnFloor_x
FUNCTION_AT_ADDRESS(void EQPlayer::PositionOnFloor(), EQPlayer__PositionOnFloor);
#endif
#ifdef EQPlayer__IsRoleplaying_x
FUNCTION_AT_ADDRESS(bool EQPlayer::IsRoleplaying(), EQPlayer__IsRoleplaying);
#endif
#ifdef EQPlayer__IsInvited_x
FUNCTION_AT_ADDRESS(bool EQPlayer::IsInvited(), EQPlayer__IsInvited);
#endif
#ifdef EQPlayer__SetInvited_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetInvited(bool), EQPlayer__SetInvited);
#endif
#ifdef EQPlayer__PlaySoundA_x
FUNCTION_AT_ADDRESS(void EQPlayer::PlaySoundA(int), EQPlayer__PlaySoundA);
#endif
#ifdef EQPlayer__SetSounds_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetSounds(), EQPlayer__SetSounds);
#endif
#ifdef EQPlayer__SetCurrentLoopSound_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetCurrentLoopSound(int), EQPlayer__SetCurrentLoopSound);
#endif
#ifdef EQPlayer__IsFlyer_x
FUNCTION_AT_ADDRESS(bool EQPlayer::IsFlyer(), EQPlayer__IsFlyer);
#endif
#ifdef EQPlayer__InitSneakMod_x
FUNCTION_AT_ADDRESS(void EQPlayer::InitSneakMod(), EQPlayer__InitSneakMod);
#endif
#ifdef EQPlayer__SetHeights_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetHeights(), EQPlayer__SetHeights);
#endif
#ifdef EQPlayer__GetDefaultHeight_x
FUNCTION_AT_ADDRESS(float EQPlayer::GetDefaultHeight(int, unsigned char), EQPlayer__GetDefaultHeight);
#endif
#ifdef EQPlayer__ComputeSpecialHeights_x
FUNCTION_AT_ADDRESS(void __cdecl EQPlayer::ComputeSpecialHeights(int, float*, float*, float*, float*, bool), EQPlayer__ComputeSpecialHeights);
#endif
#ifdef EQPlayer__IsUntexturedHorse_x
FUNCTION_AT_ADDRESS(bool EQPlayer::IsUntexturedHorse(), EQPlayer__IsUntexturedHorse);
#endif
#ifdef EQPlayer__HasInvalidRiderTexture_x
FUNCTION_AT_ADDRESS(bool const EQPlayer::HasInvalidRiderTexture() const, EQPlayer__HasInvalidRiderTexture);
#endif
#ifdef EQPlayer__ForceInvisible_x
FUNCTION_AT_ADDRESS(void EQPlayer::ForceInvisible(bool), EQPlayer__ForceInvisible);
#endif
#ifdef EQPlayer__MountableRace_x
FUNCTION_AT_ADDRESS(int EQPlayer::MountableRace(), EQPlayer__MountableRace);
#endif
#ifdef EQPlayer__MakeRiderMountUp_x
FUNCTION_AT_ADDRESS(void EQPlayer::MakeRiderMountUp(), EQPlayer__MakeRiderMountUp);
#endif
#ifdef EQPlayer__MountEQPlayer_x
FUNCTION_AT_ADDRESS(void EQPlayer::MountEQPlayer(EQPlayer*), EQPlayer__MountEQPlayer);
#endif
#ifdef EQPlayer__Dismount_x
FUNCTION_AT_ADDRESS(void EQPlayer::Dismount(), EQPlayer__Dismount);
#endif
#ifdef EQPlayer__GetArmorType_x
FUNCTION_AT_ADDRESS(int EQPlayer::GetArmorType(int), EQPlayer__GetArmorType);
#endif
#ifdef EQPlayer__SetArmorType_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetArmorType(int, int), EQPlayer__SetArmorType);
#endif
#ifdef EQPlayer__GetArmorTint_x
FUNCTION_AT_ADDRESS(unsigned long EQPlayer::GetArmorTint(int), EQPlayer__GetArmorTint);
#endif
#ifdef EQPlayer__SetArmorTint_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetArmorTint(int, unsigned long), EQPlayer__SetArmorTint);
#endif
#ifdef EQPlayer__SetAccel_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetAccel(float, int), EQPlayer__SetAccel);
#endif
#ifdef EQPlayer__SetToRandomRace_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetToRandomRace(), EQPlayer__SetToRandomRace);
#endif
#ifdef EQPlayer__GetBaseFaceNbr_x
FUNCTION_AT_ADDRESS(unsigned char EQPlayer::GetBaseFaceNbr(int, unsigned char*), EQPlayer__GetBaseFaceNbr);
#endif
#ifdef EQPlayer__HasAttachedBeard_x
FUNCTION_AT_ADDRESS(unsigned char EQPlayer::HasAttachedBeard(), EQPlayer__HasAttachedBeard);
#endif
#ifdef EQPlayer__HasAttachedHair_x
FUNCTION_AT_ADDRESS(unsigned char EQPlayer::HasAttachedHair(), EQPlayer__HasAttachedHair);
#endif
#ifdef EQPlayer__SetDefaultFacialFeaturesByFace_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetDefaultFacialFeaturesByFace(int, unsigned char, unsigned char), EQPlayer__SetDefaultFacialFeaturesByFace);
#endif
#ifdef EQPlayer__GetAllowedHairColorIndexRange_x
FUNCTION_AT_ADDRESS(void EQPlayer::GetAllowedHairColorIndexRange(int, int*, int*), EQPlayer__GetAllowedHairColorIndexRange);
#endif
#ifdef EQPlayer__CanBeBald_x
FUNCTION_AT_ADDRESS(int EQPlayer::CanBeBald(), EQPlayer__CanBeBald);
#endif
#ifdef EQPlayer__ChangeNoGravity_x
FUNCTION_AT_ADDRESS(void EQPlayer::ChangeNoGravity(int), EQPlayer__ChangeNoGravity);
#endif
#ifdef EQPlayer__IdUsed_x
FUNCTION_AT_ADDRESS(int EQPlayer::IdUsed(unsigned int), EQPlayer__IdUsed);
#endif
#ifdef EQPlayer__GetUnusedID_x
FUNCTION_AT_ADDRESS(unsigned int EQPlayer::GetUnusedID(), EQPlayer__GetUnusedID);
#endif
#ifdef EQPlayer__SetAndReserveID_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetAndReserveID(unsigned int), EQPlayer__SetAndReserveID);
#endif
#ifdef EQPlayer__InitializeIDArray_x
FUNCTION_AT_ADDRESS(void EQPlayer::InitializeIDArray(), EQPlayer__InitializeIDArray);
#endif
#ifdef EQPlayer__Levitating_x
FUNCTION_AT_ADDRESS(int PlayerZoneClient::Levitating(), EQPlayer__Levitating);
#endif
#ifdef EQPlayer__SetRace_x
FUNCTION_AT_ADDRESS(void PlayerZoneClient::SetRace(int), EQPlayer__SetRace);
#endif
#ifdef EQPlayer__CanChangeForm_x
FUNCTION_AT_ADDRESS(bool PlayerZoneClient::CanChangeForm(int Race, BYTE Sex, float Height), EQPlayer__CanChangeForm);
#endif
#ifdef EQPlayer__SetNameSpriteState_x
FUNCTION_AT_ADDRESS(int PlayerClient::SetNameSpriteState(bool), EQPlayer__SetNameSpriteState);
#endif
#ifdef EQPlayer__ChangeBoneStringSprite_x
FUNCTION_AT_ADDRESS(void PlayerClient::ChangeBoneStringSprite(int, const char*), EQPlayer__ChangeBoneStringSprite);
#endif
#ifdef EQPlayer__SetNameSpriteTint_x
FUNCTION_AT_ADDRESS(bool PlayerClient::SetNameSpriteTint(), EQPlayer__SetNameSpriteTint);
#endif
#ifdef EQPlayer__UpdateNameSprite_x
FUNCTION_AT_ADDRESS(void EQPlayer::UpdateNameSprite(), EQPlayer__UpdateNameSprite);
#endif
#ifdef EQPlayer__UpdateBonePointers_x
FUNCTION_AT_ADDRESS(void EQPlayer::UpdateBonePointers(), EQPlayer__UpdateBonePointers);
#endif
#ifdef EQPlayer__FindDefaultEyeMaterialIndexes_x
FUNCTION_AT_ADDRESS(void EQPlayer::FindDefaultEyeMaterialIndexes(), EQPlayer__FindDefaultEyeMaterialIndexes);
#endif
#ifdef EQPlayer__CalcAnimLength_x
FUNCTION_AT_ADDRESS(unsigned int EQPlayer::CalcAnimLength(int), EQPlayer__CalcAnimLength);
#endif
#ifdef EQPlayer__GetAlternateTrackNumber_x
FUNCTION_AT_ADDRESS(int EQPlayer::GetAlternateTrackNumber(int, unsigned char*), EQPlayer__GetAlternateTrackNumber);
#endif
#ifdef EQPlayer__GetAlternateAnimVariation_x
FUNCTION_AT_ADDRESS(unsigned char EQPlayer::GetAlternateAnimVariation(int, unsigned char), EQPlayer__GetAlternateAnimVariation);
#endif
#ifdef EQPlayer__GetRaceSexITOffset_x
FUNCTION_AT_ADDRESS(int EQPlayer::GetRaceSexITOffset(), EQPlayer__GetRaceSexITOffset);
#endif
#ifdef EQPlayer__UpdatePlayerVisibility_x
FUNCTION_AT_ADDRESS(void EQPlayer::UpdatePlayerVisibility(), EQPlayer__UpdatePlayerVisibility);
#endif
#ifdef EQPlayer__UpdateAllPlayersVisibility_x
FUNCTION_AT_ADDRESS(void __cdecl EQPlayer::UpdateAllPlayersVisibility(), EQPlayer__UpdateAllPlayersVisibility);
#endif
#ifdef EQPlayer__SetEyeMaterial_x
FUNCTION_AT_ADDRESS(int EQPlayer::SetEyeMaterial(unsigned char, int), EQPlayer__SetEyeMaterial);
#endif
#ifdef EQPlayer__HideOrShowAttachedHair_x
FUNCTION_AT_ADDRESS(void EQPlayer::HideOrShowAttachedHair(), EQPlayer__HideOrShowAttachedHair);
#endif
#ifdef EQPlayer__SetFHEB_x
FUNCTION_AT_ADDRESS(int EQPlayer::SetFHEB(unsigned char, unsigned char), EQPlayer__SetFHEB);
#endif
#ifdef EQPlayer__SetFHEB_Color_x
FUNCTION_AT_ADDRESS(int EQPlayer::SetFHEB_Color(unsigned char, unsigned char), EQPlayer__SetFHEB_Color);
#endif
#ifdef EQPlayer__SetHairOrBeard_x
FUNCTION_AT_ADDRESS(int EQPlayer::SetHairOrBeard(int), EQPlayer__SetHairOrBeard);
#endif
#ifdef EQPlayer__GetBonePointerByITS_x
FUNCTION_AT_ADDRESS(struct T3D_DAG* EQPlayer::GetBonePointerByITS(int, int), EQPlayer__GetBonePointerByITS);
#endif
#ifdef EQPlayer__UpdateAppearance_x
FUNCTION_AT_ADDRESS(void EQPlayer::UpdateAppearance(), EQPlayer__UpdateAppearance);
#endif
#ifdef EQPlayer__SetDefaultITAttachments_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetDefaultITAttachments(int), EQPlayer__SetDefaultITAttachments);
#endif
#ifdef EQPlayer__SwapMaterial_x
FUNCTION_AT_ADDRESS(int EQPlayer::SwapMaterial(int, int, int, int, unsigned char), EQPlayer__SwapMaterial);
#endif
#ifdef EQPlayer__SwapFace_x
FUNCTION_AT_ADDRESS(int EQPlayer::SwapFace(int, int), EQPlayer__SwapFace);
#endif
#ifdef EQPlayer__GetAttachedHelmITNum_x
FUNCTION_AT_ADDRESS(int EQPlayer::GetAttachedHelmITNum(int, int*), EQPlayer__GetAttachedHelmITNum);
#endif
#ifdef EQPlayer__SetPlayerConstantAmbient_x
FUNCTION_AT_ADDRESS(void EQPlayer::SetPlayerConstantAmbient(struct T3D_RGB*), EQPlayer__SetPlayerConstantAmbient);
#endif
#ifdef EQPlayer__SwapHead_x
FUNCTION_AT_ADDRESS(int EQPlayer::SwapHead(int, int, unsigned long, int), EQPlayer__SwapHead);
#endif
#ifdef EQPlayer__SetPlayerPitchType_x
FUNCTION_AT_ADDRESS(int EQPlayer::SetPlayerPitchType(), EQPlayer__SetPlayerPitchType);
#endif
#ifdef EQPlayer__ReplaceSpecialCloakMaterials_x
FUNCTION_AT_ADDRESS(int EQPlayer::ReplaceSpecialCloakMaterials(), EQPlayer__ReplaceSpecialCloakMaterials);
#endif
#ifdef EQPlayer__SwapBody_x
FUNCTION_AT_ADDRESS(int EQPlayer::SwapBody(int, int), EQPlayer__SwapBody);
#endif
#ifdef EQPlayer__HandleMaterialEx_x
FUNCTION_AT_ADDRESS(void EQPlayer::HandleMaterialEx(int, unsigned int, unsigned int, unsigned long, int), EQPlayer__HandleMaterialEx);
#endif
#ifdef EQPlayer__UpdateItemSlot_x
FUNCTION_AT_ADDRESS(unsigned char EQPlayer::UpdateItemSlot(unsigned char, char*, int), EQPlayer__UpdateItemSlot);
#endif
#ifdef EQPlayer__SwapNPCMaterials_x
FUNCTION_AT_ADDRESS(int EQPlayer::SwapNPCMaterials(), EQPlayer__SwapNPCMaterials);
#endif
#ifdef EQPlayer__PutPlayerOnFloor_x
FUNCTION_AT_ADDRESS(void EQPlayer::PutPlayerOnFloor(), EQPlayer__PutPlayerOnFloor);
#endif
#ifdef EQPlayer__CheckForUnderFloor_x
FUNCTION_AT_ADDRESS(void EQPlayer::CheckForUnderFloor(), EQPlayer__CheckForUnderFloor);
#endif
#ifdef EQPlayer__DoFloorCheck_x
FUNCTION_AT_ADDRESS(void EQPlayer::DoFloorCheck(), EQPlayer__DoFloorCheck);
#endif
#ifdef EQPlayer__DoSwimJump_x
FUNCTION_AT_ADDRESS(void EQPlayer::DoSwimJump(unsigned char), EQPlayer__DoSwimJump);
#endif
#ifdef EQPlayer__PushAlongHeading_x
FUNCTION_AT_ADDRESS(void EQPlayer::PushAlongHeading(float), EQPlayer__PushAlongHeading);
#endif
#ifdef EQPlayer__DoTeleport_x
FUNCTION_AT_ADDRESS(unsigned char EQPlayer::DoTeleport(char*, int), EQPlayer__DoTeleport);
#endif
#ifdef EQPlayer__ChangeLight_x
FUNCTION_AT_ADDRESS(void EQPlayer::ChangeLight(), EQPlayer__ChangeLight);
#endif
#ifdef EQPlayer__GetBoneCoords_x
FUNCTION_AT_ADDRESS(bool EQPlayer::GetBoneCoords(struct T3D_DAG*, struct _EQLOC*), EQPlayer__GetBoneCoords);
#endif
#ifdef EQPlayer__CheckForJump_x
FUNCTION_AT_ADDRESS(int EQPlayer::CheckForJump(), EQPlayer__CheckForJump);
#endif
#ifdef EQPlayer__GetPlayerFloorHeight_x
FUNCTION_AT_ADDRESS(float EQPlayer::GetPlayerFloorHeight(float, float, float, unsigned char), EQPlayer__GetPlayerFloorHeight);
#endif
#ifdef EQPlayer__UpdatePlayerActor_x
FUNCTION_AT_ADDRESS(bool EQPlayer::UpdatePlayerActor(), EQPlayer__UpdatePlayerActor);
#endif
#ifdef EQPlayer__GetNearestActorTag_x
FUNCTION_AT_ADDRESS(unsigned char EQPlayer::GetNearestActorTag(char*, void*), EQPlayer__GetNearestActorTag);
#endif
#ifdef EQPlayer__DoItemSlot_x
FUNCTION_AT_ADDRESS(void EQPlayer::DoItemSlot(int), EQPlayer__DoItemSlot);
#endif
#ifdef EQPlayer__DoClassRandomAnimation_x
FUNCTION_AT_ADDRESS(void EQPlayer::DoClassRandomAnimation(), EQPlayer__DoClassRandomAnimation);
#endif
#ifdef EQPlayer__CreateUserLight_x
FUNCTION_AT_ADDRESS(struct T3D_POINTLIGHT* EQPlayer::CreateUserLight(struct T3D_LIGHTDEFINITION*, int), EQPlayer__CreateUserLight);
#endif
#ifdef EQPlayer__AttachPlayerToPlayerBone_x
FUNCTION_AT_ADDRESS(int EQPlayer::AttachPlayerToPlayerBone(EQPlayer*, struct T3D_DAG*), EQPlayer__AttachPlayerToPlayerBone);
#endif
#ifdef EQPlayer__IsInvisible_x
FUNCTION_AT_ADDRESS(bool EQPlayer::IsInvisible(EQPlayer*), EQPlayer__IsInvisible);
#endif
#ifdef EQPlayer__IsAMount_x
FUNCTION_AT_ADDRESS(bool EQPlayer::IsAMount(), EQPlayer__IsAMount);
#endif
#ifdef EQPlayer__IsTargetable_x
FUNCTION_AT_ADDRESS(bool PlayerBase::IsTargetable(), EQPlayer__IsTargetable);
#endif

//============================================================================
// EQPlayerManager
//============================================================================

#ifdef EQPlayerManager__GetSpawnByID_x
FUNCTION_AT_ADDRESS(PlayerClient* PlayerManagerClient::GetSpawnByID(int), EQPlayerManager__GetSpawnByID);
#endif
#ifdef EQPlayerManager__GetSpawnByName_x
FUNCTION_AT_ADDRESS(PlayerClient* PlayerManagerClient::GetSpawnByName(const char*), EQPlayerManager__GetSpawnByName);
#endif
#ifdef EQPlayerManager__GetPlayerFromPartialName_x
FUNCTION_AT_ADDRESS(PlayerClient* PlayerManagerClient::GetPlayerFromPartialName(const char*, PlayerBase*), EQPlayerManager__GetPlayerFromPartialName);
#endif

//============================================================================
// PlayerBase
//============================================================================

#ifdef PlayerBase__HasProperty_j_x
FUNCTION_AT_ADDRESS(bool PlayerBase::HasProperty(unsigned int, int, int), PlayerBase__HasProperty_j);
#endif
#ifdef PlayerBase__GetVisibilityLineSegment_x
FUNCTION_AT_ADDRESS(CLineSegment PlayerBase::GetVisibilityLineSegment(const PlayerBase&, unsigned int), PlayerBase__GetVisibilityLineSegment);
#endif

//============================================================================
// PlayerClient
//============================================================================

#ifdef PlayerClient__GetPcClient_x
FUNCTION_AT_ADDRESS(PcClient* PlayerClient::GetPcClient() const, PlayerClient__GetPcClient);
#endif

//============================================================================
// PlayerZoneClient
//============================================================================

#ifdef PlayerZoneClient__LegalPlayerRace_x
FUNCTION_AT_ADDRESS(int PlayerZoneClient::LegalPlayerRace(int), PlayerZoneClient__LegalPlayerRace);
#endif
#ifdef PlayerZoneClient__GetLevel_x
FUNCTION_AT_ADDRESS(unsigned char PlayerZoneClient::GetLevel() const, PlayerZoneClient__GetLevel);
#endif
#ifdef PlayerZoneClient__IsValidTeleport_x
FUNCTION_AT_ADDRESS(bool PlayerZoneClient::IsValidTeleport(float X, float Y, float Z, float Heading, float Distance), PlayerZoneClient__IsValidTeleport);
#endif

} // namespace eqlib
