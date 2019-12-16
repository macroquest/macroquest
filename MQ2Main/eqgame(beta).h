/******************************************************************************
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
#ifdef PRIVATE
#if defined(EQBETA)
#include "eqgame-private(beta).h"
#endif
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Dec 16 2019"
#define __ExpectedVersionTime                                     "04:23:22"
#define __ActualVersionDate_x                                      0xB0B664
#define __ActualVersionTime_x                                      0xB0B658
#define __ActualVersionBuild_x                                     0xAF733C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x631500
#define __MemChecker1_x                                            0x9039A0
#define __MemChecker2_x                                            0x6BFE10
#define __MemChecker3_x                                            0x6BFD60
#define __MemChecker4_x                                            0x85A810
#define __EncryptPad0_x                                            0xC423E8
#define __EncryptPad1_x                                            0xCA05E8
#define __EncryptPad2_x                                            0xC52C80
#define __EncryptPad3_x                                            0xC52880
#define __EncryptPad4_x                                            0xC90C00
#define __EncryptPad5_x                                            0xF6CCC8
#define __AC1_x                                                    0x8173F6
#define __AC2_x                                                    0x5EB25F
#define __AC3_x                                                    0x5F295F
#define __AC4_x                                                    0x5F6930
#define __AC5_x                                                    0x5FCC3F
#define __AC6_x                                                    0x601256
#define __AC7_x                                                    0x5EACD0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x19708C

// Direct Input
#define DI8__Main_x                                                0xF6CCF0
#define DI8__Keyboard_x                                            0xF6CCF4
#define DI8__Mouse_x                                               0xF6CCD4
#define DI8__Mouse_Copy_x                                          0xEC5424
#define DI8__Mouse_Check_x                                         0xF6A81C
#define __AutoSkillArray_x                                         0xEC633C
#define __Attack_x                                                 0xF64163
#define __Autofire_x                                               0xF64164
#define __BindList_x                                               0xC30E20
#define g_eqCommandStates_x                                        0xC31BA0
#define __Clicks_x                                                 0xEC54DC
#define __CommandList_x                                            0xC32760
#define __CurrentMapLabel_x                                        0xF7CC04
#define __CurrentSocial_x                                          0xC1A7C0
#define __DoAbilityList_x                                          0xEFBC84
#define __do_loot_x                                                0x5B6B80
#define __DrawHandler_x                                            0x15FBF78
#define __GroupCount_x                                             0xEB56D2
#define __Guilds_x                                                 0xEBBC30
#define __gWorld_x                                                 0xEB5E18
#define __HWnd_x                                                   0xF6CCD8
#define __heqmain_x                                                0xF6CCB0
#define __InChatMode_x                                             0xEC540C
#define __LastTell_x                                               0xEC7380
#define __LMouseHeldTime_x                                         0xEC5548
#define __Mouse_x                                                  0xF6CCDC
#define __MouseLook_x                                              0xEC54A2
#define __MouseEventTime_x                                         0xF64C44
#define __gpbCommandEvent_x                                        0xEB58D0
#define __NetStatusToggle_x                                        0xEC54A5
#define __PCNames_x                                                0xEC692C
#define __RangeAttackReady_x                                       0xEC6620
#define __RMouseHeldTime_x                                         0xEC5544
#define __RunWalkState_x                                           0xEC5410
#define __ScreenMode_x                                             0xE03108
#define __ScreenX_x                                                0xEC53C4
#define __ScreenY_x                                                0xEC53C0
#define __ScreenXMax_x                                             0xEC53C8
#define __ScreenYMax_x                                             0xEC53CC
#define __ServerHost_x                                             0xEB5B03
#define __ServerName_x                                             0xEFBC44
#define __ShiftKeyDown_x                                           0xEC5A9C
#define __ShowNames_x                                              0xEC67DC
#define __Socials_x                                                0xEFBD44
#define __SubscriptionType_x                                       0xFC1108
#define __TargetAggroHolder_x                                      0xF7F5B8
#define __ZoneType_x                                               0xEC58A0
#define __GroupAggro_x                                             0xF7F5F8
#define __LoginName_x                                              0xF6A4AC
#define __Inviter_x                                                0xF640E0
#define __AttackOnAssist_x                                         0xEC6798
#define __UseTellWindows_x                                         0xEC6AC8
#define __gfMaxZoomCameraDistance_x                                0xB00FC8
#define __gfMaxCameraDistance_x                                    0xB2D36C
#define __pulAutoRun_x                                             0xEC54C0
#define __pulForward_x                                             0xEC6B00
#define __pulBackward_x                                            0xEC6B04
#define __pulTurnRight_x                                           0xEC6B08
#define __pulTurnLeft_x                                            0xEC6B0C
#define __pulStrafeLeft_x                                          0xEC6B10
#define __pulStrafeRight_x                                         0xEC6B14

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB7FC8
#define instEQZoneInfo_x                                           0xEC5698
#define pinstActiveBanker_x                                        0xEB58E8
#define pinstActiveCorpse_x                                        0xEB58E0
#define pinstActiveGMaster_x                                       0xEB58E4
#define pinstActiveMerchant_x                                      0xEB58DC
#define pinstAltAdvManager_x                                       0xE04200
#define pinstBandageTarget_x                                       0xEB58F8
#define pinstCamActor_x                                            0xE030FC
#define pinstCDBStr_x                                              0xE02F1C
#define pinstCDisplay_x                                            0xEB7E94
#define pinstCEverQuest_x                                          0xF69D70
#define pinstEverQuestInfo_x                                       0xEC53B8
#define pinstCharData_x                                            0xEB7FC0
#define pinstCharSpawn_x                                           0xEB5930
#define pinstControlledMissile_x                                   0xEB5E14
#define pinstControlledPlayer_x                                    0xEB5930
#define pinstCResolutionHandler_x                                  0x15FC1A8
#define pinstCSidlManager_x                                        0x15FB140
#define pinstCXWndManager_x                                        0x15FB13C
#define instDynamicZone_x                                          0xEBBB08
#define pinstDZMember_x                                            0xEBBC18
#define pinstDZTimerInfo_x                                         0xEBBC1C
#define pinstEqLogin_x                                             0xF69DF8
#define instEQMisc_x                                               0xE02E60
#define pinstEQSoundManager_x                                      0xE051D0
#define pinstEQSpellStrings_x                                      0xCC5878
#define instExpeditionLeader_x                                     0xEBBB52
#define instExpeditionName_x                                       0xEBBB92
#define pinstGroup_x                                               0xEB56CE
#define pinstImeManager_x                                          0x15FB138
#define pinstLocalPlayer_x                                         0xEB58D8
#define pinstMercenaryData_x                                       0xF66734
#define pinstMercenaryStats_x                                      0xF7F704
#define pinstModelPlayer_x                                         0xEB58F0
#define pinstPCData_x                                              0xEB7FC0
#define pinstSkillMgr_x                                            0xF688A0
#define pinstSpawnManager_x                                        0xF67348
#define pinstSpellManager_x                                        0xF68AE0
#define pinstSpellSets_x                                           0xF5CD8C
#define pinstStringTable_x                                         0xEB56B8
#define pinstSwitchManager_x                                       0xEB5568
#define pinstTarget_x                                              0xEB592C
#define pinstTargetObject_x                                        0xEB59B8
#define pinstTargetSwitch_x                                        0xEB5E34
#define pinstTaskMember_x                                          0xE02CF0
#define pinstTrackTarget_x                                         0xEB5934
#define pinstTradeTarget_x                                         0xEB58EC
#define instTributeActive_x                                        0xE02E81
#define pinstViewActor_x                                           0xE030F8
#define pinstWorldData_x                                           0xEB58C8
#define pinstZoneAddr_x                                            0xEC5938
#define pinstPlayerPath_x                                          0xF673E0
#define pinstTargetIndicator_x                                     0xF68D48
#define EQObject_Top_x                                             0xEB58D4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE03848
#define pinstCAchievementsWnd_x                                    0xE03844
#define pinstCActionsWnd_x                                         0xE03608
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE03080
#define pinstCAdvancedLootWnd_x                                    0xE0303C
#define pinstCAdventureLeaderboardWnd_x                            0xF763D8
#define pinstCAdventureRequestWnd_x                                0xF76488
#define pinstCAdventureStatsWnd_x                                  0xF76538
#define pinstCAggroMeterWnd_x                                      0xE035A0
#define pinstCAlarmWnd_x                                           0xE0300C
#define pinstCAlertHistoryWnd_x                                    0xE030A0
#define pinstCAlertStackWnd_x                                      0xE03014
#define pinstCAlertWnd_x                                           0xE03024
#define pinstCAltStorageWnd_x                                      0xF76898
#define pinstCAudioTriggersWindow_x                                0xCB7BA8
#define pinstCAuraWnd_x                                            0xE030C4
#define pinstCAvaZoneWnd_x                                         0xE03058
#define pinstCBandolierWnd_x                                       0xE03134
#define pinstCBankWnd_x                                            0xE030C0
#define pinstCBarterMerchantWnd_x                                  0xF77AD8
#define pinstCBarterSearchWnd_x                                    0xF77B88
#define pinstCBarterWnd_x                                          0xF77C38
#define pinstCBazaarConfirmationWnd_x                              0xE02FD8
#define pinstCBazaarSearchWnd_x                                    0xE035E8
#define pinstCBazaarWnd_x                                          0xE02FF0
#define pinstCBlockedBuffWnd_x                                     0xE030C8
#define pinstCBlockedPetBuffWnd_x                                  0xE03120
#define pinstCBodyTintWnd_x                                        0xE03820
#define pinstCBookWnd_x                                            0xE035C4
#define pinstCBreathWnd_x                                          0xE02FC0
#define pinstCBuffWindowNORMAL_x                                   0xE030A4
#define pinstCBuffWindowSHORT_x                                    0xE030A8
#define pinstCBugReportWnd_x                                       0xE030B4
#define pinstCButtonWnd_x                                          0x15FB3A8
#define pinstCCastingWnd_x                                         0xE035B8
#define pinstCCastSpellWnd_x                                       0xE02FB8
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE03008
#define pinstCChatWindowManager_x                                  0xF786F8
#define pinstCClaimWnd_x                                           0xF78850
#define pinstCColorPickerWnd_x                                     0xE03614
#define pinstCCombatAbilityWnd_x                                   0xE03000
#define pinstCCombatSkillsSelectWnd_x                              0xE03028
#define pinstCCompassWnd_x                                         0xE03610
#define pinstCConfirmationDialog_x                                 0xF7D750
#define pinstCContainerMgr_x                                       0xE02FFC
#define pinstCContextMenuManager_x                                 0x15FB0F8
#define pinstCCursorAttachment_x                                   0xE035AC
#define pinstCDynamicZoneWnd_x                                     0xF78E18
#define pinstCEditLabelWnd_x                                       0xE0309C
#define pinstCEQMainWnd_x                                          0xF79060
#define pinstCEventCalendarWnd_x                                   0xE035B0
#define pinstCExtendedTargetWnd_x                                  0xE03114
#define pinstCFacePick_x                                           0xE03040
#define pinstCFactionWnd_x                                         0xE02FE8
#define pinstCFellowshipWnd_x                                      0xF79260
#define pinstCFileSelectionWnd_x                                   0xE035B4
#define pinstCFindItemWnd_x                                        0xE02FD4
#define pinstCFindLocationWnd_x                                    0xF793B8
#define pinstCFriendsWnd_x                                         0xE03038
#define pinstCGemsGameWnd_x                                        0xE02FE4
#define pinstCGiveWnd_x                                            0xE03010
#define pinstCGroupSearchFiltersWnd_x                              0xE035BC
#define pinstCGroupSearchWnd_x                                     0xF797B0
#define pinstCGroupWnd_x                                           0xF79860
#define pinstCGuildBankWnd_x                                       0xEC677C
#define pinstCGuildCreationWnd_x                                   0xF799C0
#define pinstCGuildMgmtWnd_x                                       0xF79A70
#define pinstCharacterCreation_x                                   0xE03030
#define pinstCHelpWnd_x                                            0xE03074
#define pinstCHeritageSelectionWnd_x                               0xE03050
#define pinstCHotButtonWnd_x                                       0xF7BBC8
#define pinstCHotButtonWnd1_x                                      0xF7BBC8
#define pinstCHotButtonWnd2_x                                      0xF7BBCC
#define pinstCHotButtonWnd3_x                                      0xF7BBD0
#define pinstCHotButtonWnd4_x                                      0xF7BBD4
#define pinstCIconSelectionWnd_x                                   0xE035A8
#define pinstCInspectWnd_x                                         0xE03070
#define pinstCInventoryWnd_x                                       0xE03044
#define pinstCInvSlotMgr_x                                         0xE02FBC
#define pinstCItemDisplayManager_x                                 0xF7C158
#define pinstCItemExpTransferWnd_x                                 0xF7C288
#define pinstCItemOverflowWnd_x                                    0xE035EC
#define pinstCJournalCatWnd_x                                      0xE035C8
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE03118
#define pinstCKeyRingWnd_x                                         0xE03090
#define pinstCLargeDialogWnd_x                                     0xF7E3D0
#define pinstCLayoutCopyWnd_x                                      0xF7C5D8
#define pinstCLFGuildWnd_x                                         0xF7C688
#define pinstCLoadskinWnd_x                                        0xE02FEC
#define pinstCLootFiltersCopyWnd_x                                 0xCD41F8
#define pinstCLootFiltersWnd_x                                     0xE03018
#define pinstCLootSettingsWnd_x                                    0xE03034
#define pinstCLootWnd_x                                            0xE035CC
#define pinstCMailAddressBookWnd_x                                 0xE02FC4
#define pinstCMailCompositionWnd_x                                 0xE0383C
#define pinstCMailIgnoreListWnd_x                                  0xE02FC8
#define pinstCMailWnd_x                                            0xE03818
#define pinstCManageLootWnd_x                                      0xE046B0
#define pinstCMapToolbarWnd_x                                      0xE0307C
#define pinstCMapViewWnd_x                                         0xE03054
#define pinstCMarketplaceWnd_x                                     0xE0301C
#define pinstCMerchantWnd_x                                        0xE035D0
#define pinstCMIZoneSelectWnd_x                                    0xF7CEC0
#define pinstCMusicPlayerWnd_x                                     0xE035D8
#define pinstCNameChangeMercWnd_x                                  0xE02FD0
#define pinstCNameChangePetWnd_x                                   0xE0384C
#define pinstCNameChangeWnd_x                                      0xE02FE0
#define pinstCNoteWnd_x                                            0xE0305C
#define pinstCObjectPreviewWnd_x                                   0xE0302C
#define pinstCOptionsWnd_x                                         0xE03060
#define pinstCPetInfoWnd_x                                         0xE035F0
#define pinstCPetitionQWnd_x                                       0xE03834
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE03824
#define pinstCPlayerWnd_x                                          0xE035FC
#define pinstCPopupWndManager_x                                    0xF7D750
#define pinstCProgressionSelectionWnd_x                            0xF7D800
#define pinstCPurchaseGroupWnd_x                                   0xE03068
#define pinstCPurchaseWnd_x                                        0xE03048
#define pinstCPvPLeaderboardWnd_x                                  0xF7D8B0
#define pinstCPvPStatsWnd_x                                        0xF7D960
#define pinstCQuantityWnd_x                                        0xE0311C
#define pinstCRaceChangeWnd_x                                      0xE03004
#define pinstCRaidOptionsWnd_x                                     0xE035C0
#define pinstCRaidWnd_x                                            0xE03830
#define pinstCRealEstateItemsWnd_x                                 0xE03840
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE035D4
#define pinstCRealEstateManageWnd_x                                0xE03078
#define pinstCRealEstateNeighborhoodWnd_x                          0xE03094
#define pinstCRealEstatePlotSearchWnd_x                            0xE030B8
#define pinstCRealEstatePurchaseWnd_x                              0xE030F4
#define pinstCRespawnWnd_x                                         0xE030F0
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE03850
#define pinstCSendMoneyWnd_x                                       0xE03020
#define pinstCServerListWnd_x                                      0xE0319C
#define pinstCSkillsSelectWnd_x                                    0xE02FF4
#define pinstCSkillsWnd_x                                          0xE02FDC
#define pinstCSocialEditWnd_x                                      0xE03088
#define pinstCSocialWnd_x                                          0xE02FCC
#define pinstCSpellBookWnd_x                                       0xE02FF8
#define pinstCStoryWnd_x                                           0xE035F8
#define pinstCTargetOfTargetWnd_x                                  0xF7F788
#define pinstCTargetWnd_x                                          0xE030EC
#define pinstCTaskOverlayWnd_x                                     0xE03064
#define pinstCTaskSelectWnd_x                                      0xF7F8E0
#define pinstCTaskManager_x                                        0xCD4B38
#define pinstCTaskTemplateSelectWnd_x                              0xF7F990
#define pinstCTaskWnd_x                                            0xF7FA40
#define pinstCTextEntryWnd_x                                       0xE030AC
#define pinstCTimeLeftWnd_x                                        0xE03600
#define pinstCTipWndCONTEXT_x                                      0xF7FC44
#define pinstCTipWndOFDAY_x                                        0xF7FC40
#define pinstCTitleWnd_x                                           0xF7FCF0
#define pinstCTrackingWnd_x                                        0xE0304C
#define pinstCTradeskillWnd_x                                      0xF7FE58
#define pinstCTradeWnd_x                                           0xE0382C
#define pinstCTrainWnd_x                                           0xE03828
#define pinstCTributeBenefitWnd_x                                  0xF80058
#define pinstCTributeMasterWnd_x                                   0xF80108
#define pinstCTributeTrophyWnd_x                                   0xF801B8
#define pinstCVideoModesWnd_x                                      0xE03604
#define pinstCVoiceMacroWnd_x                                      0xF694B0
#define pinstCVoteResultsWnd_x                                     0xE03838
#define pinstCVoteWnd_x                                            0xE0381C
#define pinstCWebManager_x                                         0xF69B2C
#define pinstCZoneGuideWnd_x                                       0xE0306C
#define pinstCZonePathWnd_x                                        0xE03084

#define pinstEQSuiteTextureLoader_x                                0xCA20C0
#define pinstItemIconCache_x                                       0xF79018
#define pinstLootFiltersManager_x                                  0xCD42A8
#define pinstRewardSelectionWnd_x                                  0xF7E0A8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5B1FE0
#define __CastRay2_x                                               0x5B2030
#define __ConvertItemTags_x                                        0x5CDB90
#define __CleanItemTags_x                                          0x47D190
#define __DoesFileExist_x                                          0x906B30
#define __EQGetTime_x                                              0x903470
#define __ExecuteCmd_x                                             0x5AA840
#define __FixHeading_x                                             0x99DD10
#define __GameLoop_x                                               0x6BF000
#define __get_bearing_x                                            0x5B1B50
#define __get_melee_range_x                                        0x5B2220
#define __GetAnimationCache_x                                      0x724370
#define __GetGaugeValueFromEQ_x                                    0x8158A0
#define __GetLabelFromEQ_x                                         0x817380
#define __GetXTargetType_x                                         0x99F7D0
#define __HandleMouseWheel_x                                       0x6BFEC0
#define __HeadingDiff_x                                            0x99DD80
#define __HelpPath_x                                               0xF64834
#define __LoadFrontEnd_x                                           0x6BC320
#define __NewUIINI_x                                               0x815570
#define __ProcessGameEvents_x                                      0x612A10
#define __ProcessMouseEvent_x                                      0x6121D0
#define __SaveColors_x                                             0x5539A0
#define __STMLToText_x                                             0x941430
#define __ToggleKeyRingItem_x                                      0x516CC0
#define CMemoryMappedFile__SetFile_x                               0xA8D020
#define CrashDetected_x                                            0x6BDDC0
#define DrawNetStatus_x                                            0x63E660
#define Expansion_HoT_x                                            0xEC6784
#define Teleport_Table_Size_x                                      0xEB59C0
#define Teleport_Table_x                                           0xEB5E38
#define Util__FastTime_x                                           0x903040

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4906C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4995E0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4993B0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493C60
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x4930B0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x55B5B0
#define AltAdvManager__IsAbilityReady_x                            0x55A4E0
#define AltAdvManager__GetAAById_x                                 0x55A6E0
#define AltAdvManager__CanTrainAbility_x                           0x55A750
#define AltAdvManager__CanSeeAbility_x                             0x55AAB0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA3E0
#define CharacterZoneClient__HasSkill_x                            0x4D52D0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D69F0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE6F0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAD00
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9380
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9460
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9540
#define CharacterZoneClient__FindAffectSlot_x                      0x4C34F0
#define CharacterZoneClient__BardCastBard_x                        0x4C6050
#define CharacterZoneClient__GetMaxEffects_x                       0x4BADD0
#define CharacterZoneClient__GetEffect_x                           0x4BAC40
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4540
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4610
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4660
#define CharacterZoneClient__CalcAffectChange_x                    0x4C47B0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4980
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2B40
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7950
#define CharacterZoneClient__FindItemByRecord_x                    0x4D73D0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E59B0
#define CBankWnd__WndNotification_x                                0x6E5790

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F3220

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x621230
#define CButtonWnd__CButtonWnd_x                                   0x93D810

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x713370
#define CChatManager__InitContextMenu_x                            0x70C4C0
#define CChatManager__FreeChatWindow_x                             0x711EB0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8980
#define CChatManager__SetLockedActiveChatWindow_x                  0x712FF0
#define CChatManager__CreateChatWindow_x                           0x7124F0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8A90

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x951DC0
#define CContextMenu__dCContextMenu_x                              0x951FF0
#define CContextMenu__AddMenuItem_x                                0x952000
#define CContextMenu__RemoveMenuItem_x                             0x952300
#define CContextMenu__RemoveAllMenuItems_x                         0x952320
#define CContextMenu__CheckMenuItem_x                              0x9523A0
#define CContextMenu__SetMenuItem_x                                0x952230
#define CContextMenu__AddSeparator_x                               0x952190

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x952940
#define CContextMenuManager__RemoveMenu_x                          0x9529B0
#define CContextMenuManager__PopupMenu_x                           0x952A70
#define CContextMenuManager__Flush_x                               0x9528E0
#define CContextMenuManager__GetMenu_x                             0x49B6A0
#define CContextMenuManager__CreateDefaultMenu_x                   0x71EB40

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DE9D0
#define CChatService__GetFriendName_x                              0x8DE9E0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x713BE0
#define CChatWindow__Clear_x                                       0x714EA0
#define CChatWindow__WndNotification_x                             0x715630
#define CChatWindow__AddHistory_x                                  0x714760

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94F220
#define CComboWnd__Draw_x                                          0x94E720
#define CComboWnd__GetCurChoice_x                                  0x94F060
#define CComboWnd__GetListRect_x                                   0x94EBD0
#define CComboWnd__GetTextRect_x                                   0x94F280
#define CComboWnd__InsertChoice_x                                  0x94ED60
#define CComboWnd__SetColors_x                                     0x94ED30
#define CComboWnd__SetChoice_x                                     0x94F030
#define CComboWnd__GetItemCount_x                                  0x94F070
#define CComboWnd__GetCurChoiceText_x                              0x94F0B0
#define CComboWnd__GetChoiceText_x                                 0x94F080
#define CComboWnd__InsertChoiceAtIndex_x                           0x94EDF0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x71C530
#define CContainerWnd__vftable_x                                   0xB14854
#define CContainerWnd__SetContainer_x                              0x71DA90

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54E3D0
#define CDisplay__PreZoneMainUI_x                                  0x54E3E0
#define CDisplay__CleanGameUI_x                                    0x553760
#define CDisplay__GetClickedActor_x                                0x5466F0
#define CDisplay__GetUserDefinedColor_x                            0x53EDB0
#define CDisplay__GetWorldFilePath_x                               0x548160
#define CDisplay__is3dON_x                                         0x543350
#define CDisplay__ReloadUI_x                                       0x54D860
#define CDisplay__WriteTextHD2_x                                   0x543140
#define CDisplay__TrueDistance_x                                   0x549E20
#define CDisplay__SetViewActor_x                                   0x546010
#define CDisplay__GetFloorHeight_x                                 0x543410
#define CDisplay__SetRenderWindow_x                                0x541D70
#define CDisplay__ToggleScreenshotMode_x                           0x545AE0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x971A70

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x955310
#define CEditWnd__GetCharIndexPt_x                                 0x956230
#define CEditWnd__GetDisplayString_x                               0x9560D0
#define CEditWnd__GetHorzOffset_x                                  0x954940
#define CEditWnd__GetLineForPrintableChar_x                        0x9573D0
#define CEditWnd__GetSelStartPt_x                                  0x9564E0
#define CEditWnd__GetSTMLSafeText_x                                0x955EF0
#define CEditWnd__PointFromPrintableChar_x                         0x957000
#define CEditWnd__SelectableCharFromPoint_x                        0x957170
#define CEditWnd__SetEditable_x                                    0x9565B0
#define CEditWnd__SetWindowTextA_x                                 0x955C70
#define CEditWnd__ReplaceSelection_x                               0x956C70
#define CEditWnd__ReplaceSelection1_x                              0x956BF0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x600730
#define CEverQuest__ClickedPlayer_x                                0x5F2740
#define CEverQuest__CreateTargetIndicator_x                        0x60FCA0
#define CEverQuest__DeleteTargetIndicator_x                        0x60FD30
#define CEverQuest__DoTellWindow_x                                 0x4E8B70
#define CEverQuest__OutputTextToLog_x                              0x4E8DF0
#define CEverQuest__DropHeldItemOnGround_x                         0x5E7780
#define CEverQuest__dsp_chat_x                                     0x4E9180
#define CEverQuest__trimName_x                                     0x60BF90
#define CEverQuest__Emote_x                                        0x600F90
#define CEverQuest__EnterZone_x                                    0x5FAF10
#define CEverQuest__GetBodyTypeDesc_x                              0x605850
#define CEverQuest__GetClassDesc_x                                 0x605E90
#define CEverQuest__GetClassThreeLetterCode_x                      0x606490
#define CEverQuest__GetDeityDesc_x                                 0x60E5E0
#define CEverQuest__GetLangDesc_x                                  0x606650
#define CEverQuest__GetRaceDesc_x                                  0x605E70
#define CEverQuest__InterpretCmd_x                                 0x60EBB0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5EB980
#define CEverQuest__LMouseUp_x                                     0x5E9D10
#define CEverQuest__RightClickedOnPlayer_x                         0x5EC260
#define CEverQuest__RMouseUp_x                                     0x5EAC90
#define CEverQuest__SetGameState_x                                 0x5E7510
#define CEverQuest__UPCNotificationFlush_x                         0x60BE90
#define CEverQuest__IssuePetCommand_x                              0x607A50
#define CEverQuest__ReportSuccessfulHit_x                          0x6022E0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72E430
#define CGaugeWnd__CalcLinesFillRect_x                             0x72E490
#define CGaugeWnd__Draw_x                                          0x72DAC0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF620
#define CGuild__GetGuildName_x                                     0x4AE700
#define CGuild__GetGuildIndex_x                                    0x4AEA90

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x748620

//CHotButton
#define CHotButton__SetButtonSize_x                                0x6215F0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x755620
#define CInvSlotMgr__MoveItem_x                                    0x754340
#define CInvSlotMgr__SelectSlot_x                                  0x7556F0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x752BC0
#define CInvSlot__SliderComplete_x                                 0x750920
#define CInvSlot__GetItemBase_x                                    0x750290
#define CInvSlot__UpdateItem_x                                     0x750400

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x757170
#define CInvSlotWnd__CInvSlotWnd_x                                 0x756310
#define CInvSlotWnd__HandleLButtonUp_x                             0x756CF0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x810C20
#define CItemDisplayWnd__UpdateStrings_x                           0x765860
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75F5D0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75FAE0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x765E70
#define CItemDisplayWnd__AboutToShow_x                             0x7654C0
#define CItemDisplayWnd__WndNotification_x                         0x766F60
#define CItemDisplayWnd__RequestConvertItem_x                      0x766A20
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x764520
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7652E0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8494F0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x76B4A0

// CLabel 
#define CLabel__Draw_x                                             0x770EB0

// CListWnd
#define CListWnd__CListWnd_x                                       0x927B20
#define CListWnd__dCListWnd_x                                      0x927E40
#define CListWnd__AddColumn_x                                      0x92C2A0
#define CListWnd__AddColumn1_x                                     0x92C2F0
#define CListWnd__AddLine_x                                        0x92C680
#define CListWnd__AddString_x                                      0x92C480
#define CListWnd__CalculateFirstVisibleLine_x                      0x92C060
#define CListWnd__CalculateVSBRange_x                              0x92BE40
#define CListWnd__ClearSel_x                                       0x92CE60
#define CListWnd__ClearAllSel_x                                    0x92CEC0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92D8B0
#define CListWnd__Compare_x                                        0x92B770
#define CListWnd__Draw_x                                           0x927F70
#define CListWnd__DrawColumnSeparators_x                           0x92A740
#define CListWnd__DrawHeader_x                                     0x92ABB0
#define CListWnd__DrawItem_x                                       0x92B0B0
#define CListWnd__DrawLine_x                                       0x92A8B0
#define CListWnd__DrawSeparator_x                                  0x92A7E0
#define CListWnd__EnableLine_x                                     0x92A030
#define CListWnd__EnsureVisible_x                                  0x92D7E0
#define CListWnd__ExtendSel_x                                      0x92CD90
#define CListWnd__GetColumnTooltip_x                               0x929B70
#define CListWnd__GetColumnMinWidth_x                              0x929BE0
#define CListWnd__GetColumnWidth_x                                 0x929AE0
#define CListWnd__GetCurSel_x                                      0x929470
#define CListWnd__GetItemAtPoint_x                                 0x92A2A0
#define CListWnd__GetItemAtPoint1_x                                0x92A310
#define CListWnd__GetItemData_x                                    0x9294F0
#define CListWnd__GetItemHeight_x                                  0x9298B0
#define CListWnd__GetItemIcon_x                                    0x929680
#define CListWnd__GetItemRect_x                                    0x92A120
#define CListWnd__GetItemText_x                                    0x929530
#define CListWnd__GetSelList_x                                     0x92CF10
#define CListWnd__GetSeparatorRect_x                               0x92A550
#define CListWnd__InsertLine_x                                     0x92CA70
#define CListWnd__RemoveLine_x                                     0x92CBC0
#define CListWnd__SetColors_x                                      0x92BE10
#define CListWnd__SetColumnJustification_x                         0x92BB40
#define CListWnd__SetColumnWidth_x                                 0x92BA60
#define CListWnd__SetCurSel_x                                      0x92CCD0
#define CListWnd__SetItemColor_x                                   0x92D4A0
#define CListWnd__SetItemData_x                                    0x92D460
#define CListWnd__SetItemText_x                                    0x92D080
#define CListWnd__ShiftColumnSeparator_x                           0x92BC00
#define CListWnd__Sort_x                                           0x92B8F0
#define CListWnd__ToggleSel_x                                      0x92CD00
#define CListWnd__SetColumnsSizable_x                              0x92BCB0
#define CListWnd__SetItemWnd_x                                     0x92D330
#define CListWnd__GetItemWnd_x                                     0x9296D0
#define CListWnd__SetItemIcon_x                                    0x92D100
#define CListWnd__CalculateCustomWindowPositions_x                 0x92C160
#define CListWnd__SetVScrollPos_x                                  0x92BA40

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x786550
#define CMapViewWnd__GetWorldCoordinates_x                         0x784C60
#define CMapViewWnd__HandleLButtonDown_x                           0x781CA0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A6600
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A6EE0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A7410
#define CMerchantWnd__SelectRecoverySlot_x                         0x7AA380
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A5170
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AFF30
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A6210

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AC5E0
#define CPacketScrambler__hton_x                                   0x8AC5D0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x946A40
#define CSidlManager__FindScreenPieceTemplate_x                    0x946E50
#define CSidlManager__FindScreenPieceTemplate1_x                   0x946C40
#define CSidlManager__CreateLabel_x                                0x808050
#define CSidlManager__CreateXWndFromTemplate_x                     0x949DB0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x949F80
#define CSidlManager__CreateXWnd_x                                 0x807F80
#define CSidlManager__CreateHotButtonWnd_x                         0x808540

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x943540
#define CSidlScreenWnd__CalculateVSBRange_x                        0x943440
#define CSidlScreenWnd__ConvertToRes_x                             0x968A60
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x942ED0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x942BC0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x942C90
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x942D60
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9439E0
#define CSidlScreenWnd__EnableIniStorage_x                         0x943EB0
#define CSidlScreenWnd__GetSidlPiece_x                             0x943BD0
#define CSidlScreenWnd__Init1_x                                    0x9427C0
#define CSidlScreenWnd__LoadIniInfo_x                              0x943F00
#define CSidlScreenWnd__LoadIniListWnd_x                           0x944A20
#define CSidlScreenWnd__LoadSidlScreen_x                           0x941BE0
#define CSidlScreenWnd__StoreIniInfo_x                             0x9445A0
#define CSidlScreenWnd__StoreIniVis_x                              0x944900
#define CSidlScreenWnd__WndNotification_x                          0x9438F0
#define CSidlScreenWnd__GetChildItem_x                             0x943E30
#define CSidlScreenWnd__HandleLButtonUp_x                          0x933680
#define CSidlScreenWnd__m_layoutCopy_x                             0x15FAFC8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x686000
#define CSkillMgr__GetSkillCap_x                                   0x6861E0
#define CSkillMgr__GetNameToken_x                                  0x685780
#define CSkillMgr__IsActivatedSkill_x                              0x6858C0
#define CSkillMgr__IsCombatSkill_x                                 0x685800

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x953720
#define CSliderWnd__SetValue_x                                     0x953590
#define CSliderWnd__SetNumTicks_x                                  0x9535F0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80E0B0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95BF20
#define CStmlWnd__CalculateHSBRange_x                              0x95D000
#define CStmlWnd__CalculateVSBRange_x                              0x95CF70
#define CStmlWnd__CanBreakAtCharacter_x                            0x961350
#define CStmlWnd__FastForwardToEndOfTag_x                          0x961FE0
#define CStmlWnd__ForceParseNow_x                                  0x95C4C0
#define CStmlWnd__GetNextTagPiece_x                                0x9612B0
#define CStmlWnd__GetSTMLText_x                                    0x5064C0
#define CStmlWnd__GetVisibleText_x                                 0x95C4E0
#define CStmlWnd__InitializeWindowVariables_x                      0x961E30
#define CStmlWnd__MakeStmlColorTag_x                               0x95B590
#define CStmlWnd__MakeWndNotificationTag_x                         0x95B600
#define CStmlWnd__SetSTMLText_x                                    0x95A640
#define CStmlWnd__StripFirstSTMLLines_x                            0x9630E0
#define CStmlWnd__UpdateHistoryString_x                            0x9621F0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x959790
#define CTabWnd__DrawCurrentPage_x                                 0x959EC0
#define CTabWnd__DrawTab_x                                         0x959BE0
#define CTabWnd__GetCurrentPage_x                                  0x958F90
#define CTabWnd__GetPageInnerRect_x                                0x9591D0
#define CTabWnd__GetTabInnerRect_x                                 0x959110
#define CTabWnd__GetTabRect_x                                      0x958FC0
#define CTabWnd__InsertPage_x                                      0x9593E0
#define CTabWnd__SetPage_x                                         0x959250
#define CTabWnd__SetPageRect_x                                     0x9596D0
#define CTabWnd__UpdatePage_x                                      0x959AA0
#define CTabWnd__GetPageFromTabIndex_x                             0x959B20
#define CTabWnd__GetCurrentTabIndex_x                              0x958F80

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x76B8B0
#define CPageWnd__SetTabText_x                                     0x958AE0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9320

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x930570
#define CTextureFont__GetTextExtent_x                              0x930730

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B91B0
#define CHtmlComponentWnd__ValidateUri_x                           0x74A010
#define CHtmlWnd__SetClientCallbacks_x                             0x626680
#define CHtmlWnd__AddObserver_x                                    0x6266A0
#define CHtmlWnd__RemoveObserver_x                                 0x626700
#define Window__getProgress_x                                      0x861E20
#define Window__getStatus_x                                        0x861E40
#define Window__getURI_x                                           0x861E50

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96E500

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91D6A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E87C0
#define CXStr__CXStr1_x                                            0x481680
#define CXStr__CXStr3_x                                            0x8FF570
#define CXStr__dCXStr_x                                            0x478810
#define CXStr__operator_equal_x                                    0x8FF7A0
#define CXStr__operator_equal1_x                                   0x8FF7E0
#define CXStr__operator_plus_equal1_x                              0x900270
#define CXStr__SetString_x                                         0x902160
#define CXStr__operator_char_p_x                                   0x8FFCB0
#define CXStr__GetChar_x                                           0x901A90
#define CXStr__Delete_x                                            0x901360
#define CXStr__GetUnicode_x                                        0x901B00
#define CXStr__GetLength_x                                         0x47D540
#define CXStr__Mid_x                                               0x47D550
#define CXStr__Insert_x                                            0x901B60
#define CXStr__FindNext_x                                          0x9017D0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9519D0
#define CXWnd__BringToTop_x                                        0x936D20
#define CXWnd__Center_x                                            0x9368A0
#define CXWnd__ClrFocus_x                                          0x9366C0
#define CXWnd__Destroy_x                                           0x936760
#define CXWnd__DoAllDrawing_x                                      0x932E30
#define CXWnd__DrawChildren_x                                      0x932E00
#define CXWnd__DrawColoredRect_x                                   0x933290
#define CXWnd__DrawTooltip_x                                       0x931960
#define CXWnd__DrawTooltipAtPoint_x                                0x931A20
#define CXWnd__GetBorderFrame_x                                    0x9330F0
#define CXWnd__GetChildWndAt_x                                     0x936DC0
#define CXWnd__GetClientClipRect_x                                 0x935060
#define CXWnd__GetScreenClipRect_x                                 0x935130
#define CXWnd__GetScreenRect_x                                     0x9352F0
#define CXWnd__GetTooltipRect_x                                    0x9332E0
#define CXWnd__GetWindowTextA_x                                    0x49CD90
#define CXWnd__IsActive_x                                          0x933A00
#define CXWnd__IsDescendantOf_x                                    0x935CA0
#define CXWnd__IsReallyVisible_x                                   0x935CD0
#define CXWnd__IsType_x                                            0x937430
#define CXWnd__Move_x                                              0x935D30
#define CXWnd__Move1_x                                             0x935DE0
#define CXWnd__ProcessTransition_x                                 0x936850
#define CXWnd__Refade_x                                            0x936090
#define CXWnd__Resize_x                                            0x936310
#define CXWnd__Right_x                                             0x936AE0
#define CXWnd__SetFocus_x                                          0x936680
#define CXWnd__SetFont_x                                           0x9366F0
#define CXWnd__SetKeyTooltip_x                                     0x937250
#define CXWnd__SetMouseOver_x                                      0x934200
#define CXWnd__StartFade_x                                         0x935B80
#define CXWnd__GetChildItem_x                                      0x936F30
#define CXWnd__SetParent_x                                         0x935A40
#define CXWnd__Minimize_x                                          0x936380

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x969AE0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x939C00
#define CXWndManager__DrawWindows_x                                0x939C20
#define CXWndManager__GetKeyboardFlags_x                           0x93C3D0
#define CXWndManager__HandleKeyboardMsg_x                          0x93BF80
#define CXWndManager__RemoveWnd_x                                  0x93C600
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93CB70

// CDBStr
#define CDBStr__GetString_x                                        0x53DD80

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBCE0
#define EQ_Character__Cur_HP_x                                     0x4D2310
#define EQ_Character__Cur_Mana_x                                   0x4D9A40
#define EQ_Character__GetCastingTimeModifier_x                     0x4BED40
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2780
#define EQ_Character__GetFocusRangeModifier_x                      0x4B28D0
#define EQ_Character__GetHPRegen_x                                 0x4DF810
#define EQ_Character__GetEnduranceRegen_x                          0x4DFE10
#define EQ_Character__GetManaRegen_x                               0x4E0250
#define EQ_Character__Max_Endurance_x                              0x64C480
#define EQ_Character__Max_HP_x                                     0x4D2140
#define EQ_Character__Max_Mana_x                                   0x64C280
#define EQ_Character__doCombatAbility_x                            0x64E8D0
#define EQ_Character__UseSkill_x                                   0x4E2020
#define EQ_Character__GetConLevel_x                                0x645590
#define EQ_Character__IsExpansionFlag_x                            0x5A9010
#define EQ_Character__TotalEffect_x                                0x4C5790
#define EQ_Character__GetPCSpellAffect_x                           0x4BFA90
#define EQ_Character__SpellDuration_x                              0x4BF5C0
#define EQ_Character__GetAdjustedSkill_x                           0x4D5090
#define EQ_Character__GetBaseSkill_x                               0x4D6030
#define EQ_Character__CanUseItem_x                                 0x4D9D50

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CB870

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x662E30

//PcClient
#define PcClient__PcClient_x                                       0x642CD0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9950
#define CCharacterListWnd__EnterWorld_x                            0x4B9390
#define CCharacterListWnd__Quit_x                                  0x4B90E0
#define CCharacterListWnd__UpdateList_x                            0x4B9520

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6278D0
#define EQ_Item__CreateItemTagString_x                             0x8A5D90
#define EQ_Item__IsStackable_x                                     0x8AA970
#define EQ_Item__GetImageNum_x                                     0x8A7820
#define EQ_Item__CreateItemClient_x                                0x626AA0
#define EQ_Item__GetItemValue_x                                    0x8A8B20
#define EQ_Item__ValueSellMerchant_x                               0x8AC1B0
#define EQ_Item__IsKeyRingItem_x                                   0x8AA270
#define EQ_Item__CanGoInBag_x                                      0x6279F0
#define EQ_Item__IsEmpty_x                                         0x8A9DC0
#define EQ_Item__GetMaxItemCount_x                                 0x8A8F40
#define EQ_Item__GetHeldItem_x                                     0x8A76F0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A56F0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55C290
#define EQ_LoadingS__Array_x                                       0xC29B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64CDE0
#define EQ_PC__GetAlternateAbilityId_x                             0x8B53E0
#define EQ_PC__GetCombatAbility_x                                  0x8B5A50
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B5AC0
#define EQ_PC__GetItemRecastTimer_x                                0x64EE50
#define EQ_PC__HasLoreItem_x                                       0x645D50
#define EQ_PC__AlertInventoryChanged_x                             0x644ED0
#define EQ_PC__GetPcZoneClient_x                                   0x6718A0
#define EQ_PC__RemoveMyAffect_x                                    0x652080
#define EQ_PC__GetKeyRingItems_x                                   0x8B6350
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B60E0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B6650

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AF570
#define EQItemList__add_object_x                                   0x5DCF30
#define EQItemList__add_item_x                                     0x5AFAD0
#define EQItemList__delete_item_x                                  0x5AFB20
#define EQItemList__FreeItemList_x                                 0x5AFA20

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53A8E0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6646B0
#define EQPlayer__dEQPlayer_x                                      0x6575C0
#define EQPlayer__DoAttack_x                                       0x66C540
#define EQPlayer__EQPlayer_x                                       0x657C80
#define EQPlayer__SetNameSpriteState_x                             0x65C390
#define EQPlayer__SetNameSpriteTint_x                              0x65D260
#define PlayerBase__HasProperty_j_x                                0x99C120
#define EQPlayer__IsTargetable_x                                   0x99C5C0
#define EQPlayer__CanSee_x                                         0x99C420
#define EQPlayer__CanSee1_x                                        0x99C4F0
#define PlayerBase__GetVisibilityLineSegment_x                     0x99C1E0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66F340
#define PlayerZoneClient__GetLevel_x                               0x6718E0
#define PlayerZoneClient__IsValidTeleport_x                        0x5DE0A0
#define PlayerZoneClient__LegalPlayerRace_x                        0x5555C0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x667460
#define EQPlayerManager__GetSpawnByName_x                          0x667510
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6675A0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x62AFF0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x62B070
#define KeypressHandler__AttachKeyToEqCommand_x                    0x62B0B0
#define KeypressHandler__ClearCommandStateArray_x                  0x62C4C0
#define KeypressHandler__HandleKeyDown_x                           0x62C4E0
#define KeypressHandler__HandleKeyUp_x                             0x62C580
#define KeypressHandler__SaveKeymapping_x                          0x62C9D0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7823C0
#define MapViewMap__SaveEx_x                                       0x785780
#define MapViewMap__SetZoom_x                                      0x789E40

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C9790

// StringTable 
#define StringTable__getString_x                                   0x8C45B0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x651CF0
#define PcZoneClient__RemovePetEffect_x                            0x652320
#define PcZoneClient__HasAlternateAbility_x                        0x64C0B0
#define PcZoneClient__GetCurrentMod_x                              0x4E50E0
#define PcZoneClient__GetModCap_x                                  0x4E4FE0
#define PcZoneClient__CanEquipItem_x                               0x64C780
#define PcZoneClient__GetItemByID_x                                0x64F2C0
#define PcZoneClient__GetItemByItemClass_x                         0x64F410
#define PcZoneClient__RemoveBuffEffect_x                           0x652340
#define PcZoneClient__BandolierSwap_x                              0x64D390
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64EDF0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E2BC0

//IconCache
#define IconCache__GetIcon_x                                       0x723C10

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x71B6A0
#define CContainerMgr__CloseContainer_x                            0x71B970
#define CContainerMgr__OpenExperimentContainer_x                   0x71C3F0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7DA560

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61FA00

//CLootWnd
#define CLootWnd__LootAll_x                                        0x778990
#define CLootWnd__RequestLootSlot_x                                0x777BC0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57CB60
#define EQ_Spell__SpellAffects_x                                   0x57CFD0
#define EQ_Spell__SpellAffectBase_x                                0x57CD90
#define EQ_Spell__IsStackable_x                                    0x4C9D50
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9C30
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6C70
#define EQ_Spell__IsSPAStacking_x                                  0x57DE20
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57D330
#define EQ_Spell__IsNoRemove_x                                     0x4C9D30
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57DE30
#define __IsResEffectSpell_x                                       0x4C91D0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD360

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D3EC0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x821380
#define CTargetWnd__WndNotification_x                              0x820C10
#define CTargetWnd__RefreshTargetBuffs_x                           0x820EE0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81FD70

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x825980

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x538320
#define CTaskManager__HandleMessage_x                              0x5367C0
#define CTaskManager__GetTaskStatus_x                              0x5383D0
#define CTaskManager__GetElementDescription_x                      0x538450

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x577CC0
#define EqSoundManager__PlayScriptMp3_x                            0x577F80
#define EqSoundManager__SoundAssistPlay_x                          0x689F00
#define EqSoundManager__WaveInstancePlay_x                         0x689470

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52BC20

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x957FF0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x563C80
#define CAltAbilityData__GetMercMaxRank_x                          0x563C10
#define CAltAbilityData__GetMaxRank_x                              0x559360

//CTargetRing
#define CTargetRing__Cast_x                                        0x61DB20

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9C10
#define CharacterBase__CreateItemGlobalIndex_x                     0x513190
#define CharacterBase__CreateItemIndex_x                           0x625C30
#define CharacterBase__GetItemPossession_x                         0x4FEED0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DC4A0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DC500
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x702750
#define CCastSpellWnd__IsBardSongPlaying_x                         0x702F80
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x703030

//messages
#define msg_spell_worn_off_x                                       0x5A11F0
#define msg_new_text_x                                             0x595FB0
#define __msgTokenTextParam_x                                      0x5A3720
#define msgTokenText_x                                             0x5A3970

//SpellManager
#define SpellManager__vftable_x                                    0xAEE684
#define SpellManager__SpellManager_x                               0x68D220
#define Spellmanager__LoadTextSpells_x                             0x68DB10
#define SpellManager__GetSpellByGroupAndRank_x                     0x68D3F0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9A00C0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x513850
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A7500
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63E4C0
#define ItemGlobalIndex__IsValidIndex_x                            0x5138B0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D4860
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D4AE0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7711F0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71FDE0
#define CCursorAttachment__AttachToCursor1_x                       0x71FE20
#define CCursorAttachment__Deactivate_x                            0x720E10

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x94ADD0
#define CSidlManagerBase__CreatePageWnd_x                          0x94A5D0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x946860
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9467F0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x967FF0
#define CEQSuiteTextureLoader__GetTexture_x                        0x967CB0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x510730
#define CFindItemWnd__WndNotification_x                            0x511210
#define CFindItemWnd__Update_x                                     0x511D80
#define CFindItemWnd__PickupSelectedItem_x                         0x50FF80

//IString
#define IString__Append_x                                          0x4F16D0

//Camera
#define CDisplay__cameraType_x                                     0xE0360C
#define EverQuest__Cameras_x                                       0xEC6AD4

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x519060
#define LootFiltersManager__GetItemFilterData_x                    0x518960
#define LootFiltersManager__RemoveItemLootFilter_x                 0x518990
#define LootFiltersManager__SetItemLootFilter_x                    0x518BB0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C8520

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A5C80
#define CResolutionHandler__GetWindowedStyle_x                     0x6849D0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x718340

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E9A70
#define CDistillerInfo__Instance_x                                 0x8E9A10

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x737400
#define CGroupWnd__UpdateDisplay_x                                 0x736750

//ItemBase
#define ItemBase__IsLore_x                                         0x8AA320
#define ItemBase__IsLoreEquipped_x                                 0x8AA3A0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DCE90
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DCFD0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DD030

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x679FB0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67D910

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x506AF0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F35B0
#define FactionManagerClient__HandleFactionMessage_x               0x4F3C20
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F41E0
#define FactionManagerClient__GetMaxFaction_x                      0x4F41FF
#define FactionManagerClient__GetMinFaction_x                      0x4F41B0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FEEA0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92F520

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C0A0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FF120

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x563120

//CTargetManager
#define CTargetManager__Get_x                                      0x690A70

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x679FB0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A90E0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AF9C0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF64168

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
