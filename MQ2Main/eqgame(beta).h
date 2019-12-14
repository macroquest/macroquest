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
#define __ExpectedVersionDate                                     "Dec 14 2019"
#define __ExpectedVersionTime                                     "04:26:00"
#define __ActualVersionDate_x                                      0xB0B664
#define __ActualVersionTime_x                                      0xB0B658
#define __ActualVersionBuild_x                                     0xAF7344

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x630FB0
#define __MemChecker1_x                                            0x902CC0
#define __MemChecker2_x                                            0x6BF700
#define __MemChecker3_x                                            0x6BF650
#define __MemChecker4_x                                            0x8597A0
#define __EncryptPad0_x                                            0xC423E8
#define __EncryptPad1_x                                            0xCA05E8
#define __EncryptPad2_x                                            0xC52C80
#define __EncryptPad3_x                                            0xC52880
#define __EncryptPad4_x                                            0xC90C00
#define __EncryptPad5_x                                            0xF6CCC8
#define __AC1_x                                                    0x816756
#define __AC2_x                                                    0x5EAE7F
#define __AC3_x                                                    0x5F257F
#define __AC4_x                                                    0x5F6550
#define __AC5_x                                                    0x5FC85F
#define __AC6_x                                                    0x600E76
#define __AC7_x                                                    0x5EA8F0
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
#define __do_loot_x                                                0x5B6810
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
#define __gfMaxZoomCameraDistance_x                                0xB00FD0
#define __gfMaxCameraDistance_x                                    0xB2D374
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
#define __CastRay_x                                                0x5B1C70
#define __CastRay2_x                                               0x5B1CC0
#define __ConvertItemTags_x                                        0x5CD820
#define __CleanItemTags_x                                          0x47D050
#define __DoesFileExist_x                                          0x905D80
#define __EQGetTime_x                                              0x902790
#define __ExecuteCmd_x                                             0x5AA480
#define __FixHeading_x                                             0x99D630
#define __GameLoop_x                                               0x6BE8F0
#define __get_bearing_x                                            0x5B17E0
#define __get_melee_range_x                                        0x5B1EB0
#define __GetAnimationCache_x                                      0x723BA0
#define __GetGaugeValueFromEQ_x                                    0x814C00
#define __GetLabelFromEQ_x                                         0x8166E0
#define __GetXTargetType_x                                         0x99F150
#define __HandleMouseWheel_x                                       0x6BF7B0
#define __HeadingDiff_x                                            0x99D6A0
#define __HelpPath_x                                               0xF64834
#define __LoadFrontEnd_x                                           0x6BBC10
#define __NewUIINI_x                                               0x8148D0
#define __ProcessGameEvents_x                                      0x612620
#define __ProcessMouseEvent_x                                      0x611DE0
#define __SaveColors_x                                             0x553880
#define __STMLToText_x                                             0x9409D0
#define __ToggleKeyRingItem_x                                      0x5168B0
#define CMemoryMappedFile__SetFile_x                               0xA8CAB0
#define CrashDetected_x                                            0x6BD6B0
#define DrawNetStatus_x                                            0x63E400
#define Expansion_HoT_x                                            0xEC6784
#define Teleport_Table_Size_x                                      0xEB59C0
#define Teleport_Table_x                                           0xEB5E38
#define Util__FastTime_x                                           0x902360

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490430
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499330
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499100
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4939C0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492E10

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x55B4B0
#define AltAdvManager__IsAbilityReady_x                            0x55A3E0
#define AltAdvManager__GetAAById_x                                 0x55A5E0
#define AltAdvManager__CanTrainAbility_x                           0x55A650
#define AltAdvManager__CanSeeAbility_x                             0x55A9B0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA0F0
#define CharacterZoneClient__HasSkill_x                            0x4D4FE0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6700
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE320
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA920
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D90B0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9190
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9270
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3120
#define CharacterZoneClient__BardCastBard_x                        0x4C5C80
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA9F0
#define CharacterZoneClient__GetEffect_x                           0x4BA860
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4170
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4240
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4290
#define CharacterZoneClient__CalcAffectChange_x                    0x4C43E0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C45B0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B27C0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7660
#define CharacterZoneClient__FindItemByRecord_x                    0x4D70E0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E5460
#define CBankWnd__WndNotification_x                                0x6E5240

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F2C90

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x620E20
#define CButtonWnd__CButtonWnd_x                                   0x93CDF0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x712D70
#define CChatManager__InitContextMenu_x                            0x70BED0
#define CChatManager__FreeChatWindow_x                             0x7118B0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8740
#define CChatManager__SetLockedActiveChatWindow_x                  0x7129F0
#define CChatManager__CreateChatWindow_x                           0x711EF0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8850

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9513C0
#define CContextMenu__dCContextMenu_x                              0x9515F0
#define CContextMenu__AddMenuItem_x                                0x951600
#define CContextMenu__RemoveMenuItem_x                             0x951910
#define CContextMenu__RemoveAllMenuItems_x                         0x951930
#define CContextMenu__CheckMenuItem_x                              0x9519B0
#define CContextMenu__SetMenuItem_x                                0x951830
#define CContextMenu__AddSeparator_x                               0x951790

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x951F50
#define CContextMenuManager__RemoveMenu_x                          0x951FC0
#define CContextMenuManager__PopupMenu_x                           0x952080
#define CContextMenuManager__Flush_x                               0x951EF0
#define CContextMenuManager__GetMenu_x                             0x49B520
#define CContextMenuManager__CreateDefaultMenu_x                   0x71E3C0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DDCD0
#define CChatService__GetFriendName_x                              0x8DDCE0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7135E0
#define CChatWindow__Clear_x                                       0x7148A0
#define CChatWindow__WndNotification_x                             0x715030
#define CChatWindow__AddHistory_x                                  0x714160

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94E840
#define CComboWnd__Draw_x                                          0x94DD40
#define CComboWnd__GetCurChoice_x                                  0x94E680
#define CComboWnd__GetListRect_x                                   0x94E1F0
#define CComboWnd__GetTextRect_x                                   0x94E8B0
#define CComboWnd__InsertChoice_x                                  0x94E380
#define CComboWnd__SetColors_x                                     0x94E350
#define CComboWnd__SetChoice_x                                     0x94E650
#define CComboWnd__GetItemCount_x                                  0x94E690
#define CComboWnd__GetCurChoiceText_x                              0x94E6D0
#define CComboWnd__GetChoiceText_x                                 0x94E6A0
#define CComboWnd__InsertChoiceAtIndex_x                           0x94E410

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x71BDB0
#define CContainerWnd__vftable_x                                   0xB14854
#define CContainerWnd__SetContainer_x                              0x71D310

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54E2B0
#define CDisplay__PreZoneMainUI_x                                  0x54E2C0
#define CDisplay__CleanGameUI_x                                    0x553640
#define CDisplay__GetClickedActor_x                                0x5465D0
#define CDisplay__GetUserDefinedColor_x                            0x53EC90
#define CDisplay__GetWorldFilePath_x                               0x548040
#define CDisplay__is3dON_x                                         0x543230
#define CDisplay__ReloadUI_x                                       0x54D740
#define CDisplay__WriteTextHD2_x                                   0x543020
#define CDisplay__TrueDistance_x                                   0x549D00
#define CDisplay__SetViewActor_x                                   0x545EF0
#define CDisplay__GetFloorHeight_x                                 0x5432F0
#define CDisplay__SetRenderWindow_x                                0x541C50
#define CDisplay__ToggleScreenshotMode_x                           0x5459C0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x971250

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x954900
#define CEditWnd__GetCharIndexPt_x                                 0x955820
#define CEditWnd__GetDisplayString_x                               0x9556D0
#define CEditWnd__GetHorzOffset_x                                  0x953F50
#define CEditWnd__GetLineForPrintableChar_x                        0x956990
#define CEditWnd__GetSelStartPt_x                                  0x955AD0
#define CEditWnd__GetSTMLSafeText_x                                0x9554F0
#define CEditWnd__PointFromPrintableChar_x                         0x9565D0
#define CEditWnd__SelectableCharFromPoint_x                        0x956740
#define CEditWnd__SetEditable_x                                    0x955B90
#define CEditWnd__SetWindowTextA_x                                 0x955270
#define CEditWnd__ReplaceSelection_x                               0x956250
#define CEditWnd__ReplaceSelection1_x                              0x9561D0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x600350
#define CEverQuest__ClickedPlayer_x                                0x5F2360
#define CEverQuest__CreateTargetIndicator_x                        0x60F8C0
#define CEverQuest__DeleteTargetIndicator_x                        0x60F950
#define CEverQuest__DoTellWindow_x                                 0x4E8930
#define CEverQuest__OutputTextToLog_x                              0x4E8BB0
#define CEverQuest__DropHeldItemOnGround_x                         0x5E73A0
#define CEverQuest__dsp_chat_x                                     0x4E8F40
#define CEverQuest__trimName_x                                     0x60BBA0
#define CEverQuest__Emote_x                                        0x600BB0
#define CEverQuest__EnterZone_x                                    0x5FAB30
#define CEverQuest__GetBodyTypeDesc_x                              0x605470
#define CEverQuest__GetClassDesc_x                                 0x605AB0
#define CEverQuest__GetClassThreeLetterCode_x                      0x6060B0
#define CEverQuest__GetDeityDesc_x                                 0x60E200
#define CEverQuest__GetLangDesc_x                                  0x606270
#define CEverQuest__GetRaceDesc_x                                  0x605A90
#define CEverQuest__InterpretCmd_x                                 0x60E7D0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5EB5A0
#define CEverQuest__LMouseUp_x                                     0x5E9930
#define CEverQuest__RightClickedOnPlayer_x                         0x5EBE80
#define CEverQuest__RMouseUp_x                                     0x5EA8B0
#define CEverQuest__SetGameState_x                                 0x5E7130
#define CEverQuest__UPCNotificationFlush_x                         0x60BAA0
#define CEverQuest__IssuePetCommand_x                              0x607670
#define CEverQuest__ReportSuccessfulHit_x                          0x601F00

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72DCC0
#define CGaugeWnd__CalcLinesFillRect_x                             0x72DD20
#define CGaugeWnd__Draw_x                                          0x72D340

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF220
#define CGuild__GetGuildName_x                                     0x4AE300
#define CGuild__GetGuildIndex_x                                    0x4AE690

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x747EF0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x6211E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x754E80
#define CInvSlotMgr__MoveItem_x                                    0x753BF0
#define CInvSlotMgr__SelectSlot_x                                  0x754F50

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x752470
#define CInvSlot__SliderComplete_x                                 0x7501D0
#define CInvSlot__GetItemBase_x                                    0x74FB70
#define CInvSlot__UpdateItem_x                                     0x74FCE0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7569B0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x755B50
#define CInvSlotWnd__HandleLButtonUp_x                             0x756530

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80FF90
#define CItemDisplayWnd__UpdateStrings_x                           0x764F40
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75ED30
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75F230
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x765540
#define CItemDisplayWnd__AboutToShow_x                             0x764BA0
#define CItemDisplayWnd__WndNotification_x                         0x766620
#define CItemDisplayWnd__RequestConvertItem_x                      0x7660E0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x763C00
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7649C0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x848900

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x76AB50

// CLabel 
#define CLabel__Draw_x                                             0x770520

// CListWnd
#define CListWnd__CListWnd_x                                       0x927120
#define CListWnd__dCListWnd_x                                      0x927440
#define CListWnd__AddColumn_x                                      0x92B8A0
#define CListWnd__AddColumn1_x                                     0x92B8F0
#define CListWnd__AddLine_x                                        0x92BC80
#define CListWnd__AddString_x                                      0x92BA80
#define CListWnd__CalculateFirstVisibleLine_x                      0x92B660
#define CListWnd__CalculateVSBRange_x                              0x92B450
#define CListWnd__ClearSel_x                                       0x92C460
#define CListWnd__ClearAllSel_x                                    0x92C4C0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92CEE0
#define CListWnd__Compare_x                                        0x92AD90
#define CListWnd__Draw_x                                           0x927570
#define CListWnd__DrawColumnSeparators_x                           0x929D60
#define CListWnd__DrawHeader_x                                     0x92A1D0
#define CListWnd__DrawItem_x                                       0x92A6D0
#define CListWnd__DrawLine_x                                       0x929ED0
#define CListWnd__DrawSeparator_x                                  0x929E00
#define CListWnd__EnableLine_x                                     0x929630
#define CListWnd__EnsureVisible_x                                  0x92CE00
#define CListWnd__ExtendSel_x                                      0x92C390
#define CListWnd__GetColumnTooltip_x                               0x929170
#define CListWnd__GetColumnMinWidth_x                              0x9291E0
#define CListWnd__GetColumnWidth_x                                 0x9290E0
#define CListWnd__GetCurSel_x                                      0x928A70
#define CListWnd__GetItemAtPoint_x                                 0x9298B0
#define CListWnd__GetItemAtPoint1_x                                0x929920
#define CListWnd__GetItemData_x                                    0x928AF0
#define CListWnd__GetItemHeight_x                                  0x928EB0
#define CListWnd__GetItemIcon_x                                    0x928C80
#define CListWnd__GetItemRect_x                                    0x929720
#define CListWnd__GetItemText_x                                    0x928B30
#define CListWnd__GetSelList_x                                     0x92C510
#define CListWnd__GetSeparatorRect_x                               0x929B60
#define CListWnd__InsertLine_x                                     0x92C070
#define CListWnd__RemoveLine_x                                     0x92C1C0
#define CListWnd__SetColors_x                                      0x92B430
#define CListWnd__SetColumnJustification_x                         0x92B160
#define CListWnd__SetColumnWidth_x                                 0x92B080
#define CListWnd__SetCurSel_x                                      0x92C2D0
#define CListWnd__SetItemColor_x                                   0x92CAB0
#define CListWnd__SetItemData_x                                    0x92CA70
#define CListWnd__SetItemText_x                                    0x92C680
#define CListWnd__ShiftColumnSeparator_x                           0x92B220
#define CListWnd__Sort_x                                           0x92AF10
#define CListWnd__ToggleSel_x                                      0x92C300
#define CListWnd__SetColumnsSizable_x                              0x92B2D0
#define CListWnd__SetItemWnd_x                                     0x92C930
#define CListWnd__GetItemWnd_x                                     0x928CD0
#define CListWnd__SetItemIcon_x                                    0x92C700
#define CListWnd__CalculateCustomWindowPositions_x                 0x92B760
#define CListWnd__SetVScrollPos_x                                  0x92B060

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x785B90
#define CMapViewWnd__GetWorldCoordinates_x                         0x7842A0
#define CMapViewWnd__HandleLButtonDown_x                           0x7812E0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A5C70
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A6550
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A6A80
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A99F0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A47E0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AF590
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A5880

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AB8D0
#define CPacketScrambler__hton_x                                   0x8AB8C0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x945FF0
#define CSidlManager__FindScreenPieceTemplate_x                    0x946400
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9461F0
#define CSidlManager__CreateLabel_x                                0x807390
#define CSidlManager__CreateXWndFromTemplate_x                     0x949360
#define CSidlManager__CreateXWndFromTemplate1_x                    0x949530
#define CSidlManager__CreateXWnd_x                                 0x8072C0
#define CSidlManager__CreateHotButtonWnd_x                         0x807880

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x942AF0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9429F0
#define CSidlScreenWnd__ConvertToRes_x                             0x968290
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x942490
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x942180
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x942250
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x942320
#define CSidlScreenWnd__DrawSidlPiece_x                            0x942F90
#define CSidlScreenWnd__EnableIniStorage_x                         0x943460
#define CSidlScreenWnd__GetSidlPiece_x                             0x943180
#define CSidlScreenWnd__Init1_x                                    0x941D80
#define CSidlScreenWnd__LoadIniInfo_x                              0x9434B0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x943FD0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x941180
#define CSidlScreenWnd__StoreIniInfo_x                             0x943B50
#define CSidlScreenWnd__StoreIniVis_x                              0x943EB0
#define CSidlScreenWnd__WndNotification_x                          0x942EA0
#define CSidlScreenWnd__GetChildItem_x                             0x9433E0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x932CF0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15FAFC8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x685980
#define CSkillMgr__GetSkillCap_x                                   0x685B60
#define CSkillMgr__GetNameToken_x                                  0x685100
#define CSkillMgr__IsActivatedSkill_x                              0x685240
#define CSkillMgr__IsCombatSkill_x                                 0x685180

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x952D20
#define CSliderWnd__SetValue_x                                     0x952B90
#define CSliderWnd__SetNumTicks_x                                  0x952BF0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80D420

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95B4D0
#define CStmlWnd__CalculateHSBRange_x                              0x95C640
#define CStmlWnd__CalculateVSBRange_x                              0x95C5C0
#define CStmlWnd__CanBreakAtCharacter_x                            0x960960
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9615F0
#define CStmlWnd__ForceParseNow_x                                  0x95BB10
#define CStmlWnd__GetNextTagPiece_x                                0x9608C0
#define CStmlWnd__GetSTMLText_x                                    0x506130
#define CStmlWnd__GetVisibleText_x                                 0x95BB30
#define CStmlWnd__InitializeWindowVariables_x                      0x961440
#define CStmlWnd__MakeStmlColorTag_x                               0x95AB40
#define CStmlWnd__MakeWndNotificationTag_x                         0x95ABB0
#define CStmlWnd__SetSTMLText_x                                    0x959BF0
#define CStmlWnd__StripFirstSTMLLines_x                            0x9626F0
#define CStmlWnd__UpdateHistoryString_x                            0x961800

// CTabWnd 
#define CTabWnd__Draw_x                                            0x958D40
#define CTabWnd__DrawCurrentPage_x                                 0x959470
#define CTabWnd__DrawTab_x                                         0x959190
#define CTabWnd__GetCurrentPage_x                                  0x958550
#define CTabWnd__GetPageInnerRect_x                                0x958790
#define CTabWnd__GetTabInnerRect_x                                 0x9586D0
#define CTabWnd__GetTabRect_x                                      0x958580
#define CTabWnd__InsertPage_x                                      0x9589A0
#define CTabWnd__SetPage_x                                         0x958810
#define CTabWnd__SetPageRect_x                                     0x958C80
#define CTabWnd__UpdatePage_x                                      0x959050
#define CTabWnd__GetPageFromTabIndex_x                             0x9590D0
#define CTabWnd__GetCurrentTabIndex_x                              0x958540

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x76AF20
#define CPageWnd__SetTabText_x                                     0x9580A0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8EE0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92FBD0
#define CTextureFont__GetTextExtent_x                              0x92FD90

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B8A70
#define CHtmlComponentWnd__ValidateUri_x                           0x7498F0
#define CHtmlWnd__SetClientCallbacks_x                             0x626270
#define CHtmlWnd__AddObserver_x                                    0x626290
#define CHtmlWnd__RemoveObserver_x                                 0x6262F0
#define Window__getProgress_x                                      0x860D70
#define Window__getStatus_x                                        0x860D90
#define Window__getURI_x                                           0x860DA0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96DCE0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91CEA0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8480
#define CXStr__CXStr1_x                                            0x481530
#define CXStr__CXStr3_x                                            0x8FE890
#define CXStr__dCXStr_x                                            0x478670
#define CXStr__operator_equal_x                                    0x8FEAC0
#define CXStr__operator_equal1_x                                   0x8FEB00
#define CXStr__operator_plus_equal1_x                              0x8FF590
#define CXStr__SetString_x                                         0x901480
#define CXStr__operator_char_p_x                                   0x8FF000
#define CXStr__GetChar_x                                           0x900DD0
#define CXStr__Delete_x                                            0x900680
#define CXStr__GetUnicode_x                                        0x900E40
#define CXStr__GetLength_x                                         0x4A8C90
#define CXStr__Mid_x                                               0x47D400
#define CXStr__Insert_x                                            0x900EA0
#define CXStr__FindNext_x                                          0x900AF0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x950FE0
#define CXWnd__BringToTop_x                                        0x936450
#define CXWnd__Center_x                                            0x935FD0
#define CXWnd__ClrFocus_x                                          0x935DE0
#define CXWnd__Destroy_x                                           0x935E90
#define CXWnd__DoAllDrawing_x                                      0x9324A0
#define CXWnd__DrawChildren_x                                      0x932470
#define CXWnd__DrawColoredRect_x                                   0x9328E0
#define CXWnd__DrawTooltip_x                                       0x930FC0
#define CXWnd__DrawTooltipAtPoint_x                                0x931080
#define CXWnd__GetBorderFrame_x                                    0x932740
#define CXWnd__GetChildWndAt_x                                     0x9364F0
#define CXWnd__GetClientClipRect_x                                 0x9346D0
#define CXWnd__GetScreenClipRect_x                                 0x934790
#define CXWnd__GetScreenRect_x                                     0x934930
#define CXWnd__GetTooltipRect_x                                    0x932930
#define CXWnd__GetWindowTextA_x                                    0x49CC00
#define CXWnd__IsActive_x                                          0x933060
#define CXWnd__IsDescendantOf_x                                    0x935320
#define CXWnd__IsReallyVisible_x                                   0x935350
#define CXWnd__IsType_x                                            0x936B40
#define CXWnd__Move_x                                              0x9353D0
#define CXWnd__Move1_x                                             0x935480
#define CXWnd__ProcessTransition_x                                 0x935F80
#define CXWnd__Refade_x                                            0x935750
#define CXWnd__Resize_x                                            0x9359F0
#define CXWnd__Right_x                                             0x936210
#define CXWnd__SetFocus_x                                          0x935DA0
#define CXWnd__SetFont_x                                           0x935E10
#define CXWnd__SetKeyTooltip_x                                     0x936950
#define CXWnd__SetMouseOver_x                                      0x933890
#define CXWnd__StartFade_x                                         0x935210
#define CXWnd__GetChildItem_x                                      0x936650
#define CXWnd__SetParent_x                                         0x9350D0
#define CXWnd__Minimize_x                                          0x935A60

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x969310

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x939370
#define CXWndManager__DrawWindows_x                                0x939390
#define CXWndManager__GetKeyboardFlags_x                           0x93BA80
#define CXWndManager__HandleKeyboardMsg_x                          0x93B640
#define CXWndManager__RemoveWnd_x                                  0x93BCB0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93C220

// CDBStr
#define CDBStr__GetString_x                                        0x53DC50

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB900
#define EQ_Character__Cur_HP_x                                     0x4D2020
#define EQ_Character__Cur_Mana_x                                   0x4D9770
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE970
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2400
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2550
#define EQ_Character__GetHPRegen_x                                 0x4DF540
#define EQ_Character__GetEnduranceRegen_x                          0x4DFB40
#define EQ_Character__GetManaRegen_x                               0x4DFF80
#define EQ_Character__Max_Endurance_x                              0x64BFD0
#define EQ_Character__Max_HP_x                                     0x4D1E50
#define EQ_Character__Max_Mana_x                                   0x64BDD0
#define EQ_Character__doCombatAbility_x                            0x64E420
#define EQ_Character__UseSkill_x                                   0x4E1D50
#define EQ_Character__GetConLevel_x                                0x645340
#define EQ_Character__IsExpansionFlag_x                            0x5A8C70
#define EQ_Character__TotalEffect_x                                0x4C53C0
#define EQ_Character__GetPCSpellAffect_x                           0x4BF6C0
#define EQ_Character__SpellDuration_x                              0x4BF1F0
#define EQ_Character__GetAdjustedSkill_x                           0x4D4DA0
#define EQ_Character__GetBaseSkill_x                               0x4D5D40
#define EQ_Character__CanUseItem_x                                 0x4D9A80

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CAC40

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x662540

//PcClient
#define PcClient__PcClient_x                                       0x642A70

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9560
#define CCharacterListWnd__EnterWorld_x                            0x4B8FA0
#define CCharacterListWnd__Quit_x                                  0x4B8CF0
#define CCharacterListWnd__UpdateList_x                            0x4B9130

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6274B0
#define EQ_Item__CreateItemTagString_x                             0x8A50E0
#define EQ_Item__IsStackable_x                                     0x8A9CA0
#define EQ_Item__GetImageNum_x                                     0x8A6B60
#define EQ_Item__CreateItemClient_x                                0x626690
#define EQ_Item__GetItemValue_x                                    0x8A7E80
#define EQ_Item__ValueSellMerchant_x                               0x8AB4B0
#define EQ_Item__IsKeyRingItem_x                                   0x8A95C0
#define EQ_Item__CanGoInBag_x                                      0x6275D0
#define EQ_Item__IsEmpty_x                                         0x8A90F0
#define EQ_Item__GetMaxItemCount_x                                 0x8A8290
#define EQ_Item__GetHeldItem_x                                     0x8A6A30
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A4A60

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55C180
#define EQ_LoadingS__Array_x                                       0xC29B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64C930
#define EQ_PC__GetAlternateAbilityId_x                             0x8B4700
#define EQ_PC__GetCombatAbility_x                                  0x8B4D70
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B4DE0
#define EQ_PC__GetItemRecastTimer_x                                0x64E9A0
#define EQ_PC__HasLoreItem_x                                       0x645B00
#define EQ_PC__AlertInventoryChanged_x                             0x644C70
#define EQ_PC__GetPcZoneClient_x                                   0x671040
#define EQ_PC__RemoveMyAffect_x                                    0x651BD0
#define EQ_PC__GetKeyRingItems_x                                   0x8B5670
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B5400
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B5970

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AF190
#define EQItemList__add_object_x                                   0x5DCBD0
#define EQItemList__add_item_x                                     0x5AF6F0
#define EQItemList__delete_item_x                                  0x5AF740
#define EQItemList__FreeItemList_x                                 0x5AF640

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53A750

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x663DC0
#define EQPlayer__dEQPlayer_x                                      0x657110
#define EQPlayer__DoAttack_x                                       0x66BCE0
#define EQPlayer__EQPlayer_x                                       0x6577D0
#define EQPlayer__SetNameSpriteState_x                             0x65BAB0
#define EQPlayer__SetNameSpriteTint_x                              0x65C970
#define PlayerBase__HasProperty_j_x                                0x99BA40
#define EQPlayer__IsTargetable_x                                   0x99BEE0
#define EQPlayer__CanSee_x                                         0x99BD40
#define EQPlayer__CanSee1_x                                        0x99BE10
#define PlayerBase__GetVisibilityLineSegment_x                     0x99BB00

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66EAE0
#define PlayerZoneClient__GetLevel_x                               0x671080
#define PlayerZoneClient__IsValidTeleport_x                        0x5DDD40
#define PlayerZoneClient__LegalPlayerRace_x                        0x555500

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x666B90
#define EQPlayerManager__GetSpawnByName_x                          0x666C40
#define EQPlayerManager__GetPlayerFromPartialName_x                0x666CD0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x62AAE0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x62AB60
#define KeypressHandler__AttachKeyToEqCommand_x                    0x62ABA0
#define KeypressHandler__ClearCommandStateArray_x                  0x62BFB0
#define KeypressHandler__HandleKeyDown_x                           0x62BFD0
#define KeypressHandler__HandleKeyUp_x                             0x62C070
#define KeypressHandler__SaveKeymapping_x                          0x62C4C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x781A00
#define MapViewMap__SaveEx_x                                       0x784DC0
#define MapViewMap__SetZoom_x                                      0x789480

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C8B60

// StringTable 
#define StringTable__getString_x                                   0x8C3990

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x651840
#define PcZoneClient__RemovePetEffect_x                            0x651E70
#define PcZoneClient__HasAlternateAbility_x                        0x64BC00
#define PcZoneClient__GetCurrentMod_x                              0x4E4E00
#define PcZoneClient__GetModCap_x                                  0x4E4D00
#define PcZoneClient__CanEquipItem_x                               0x64C2D0
#define PcZoneClient__GetItemByID_x                                0x64EE10
#define PcZoneClient__GetItemByItemClass_x                         0x64EF60
#define PcZoneClient__RemoveBuffEffect_x                           0x651E90
#define PcZoneClient__BandolierSwap_x                              0x64CEE0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64E940

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E27E0

//IconCache
#define IconCache__GetIcon_x                                       0x723440

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x71AF50
#define CContainerMgr__CloseContainer_x                            0x71B220
#define CContainerMgr__OpenExperimentContainer_x                   0x71BCA0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D9AE0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61F5F0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x777FE0
#define CLootWnd__RequestLootSlot_x                                0x777210

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57C8E0
#define EQ_Spell__SpellAffects_x                                   0x57CD50
#define EQ_Spell__SpellAffectBase_x                                0x57CB10
#define EQ_Spell__IsStackable_x                                    0x4C9A50
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C98A0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B68D0
#define EQ_Spell__IsSPAStacking_x                                  0x57DBA0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57D0B0
#define EQ_Spell__IsNoRemove_x                                     0x4C9A30
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57DBB0
#define __IsResEffectSpell_x                                       0x4C8DE0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACF30

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D31C0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x820700
#define CTargetWnd__WndNotification_x                              0x81FF90
#define CTargetWnd__RefreshTargetBuffs_x                           0x820260
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81F110

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x824CF0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5381E0
#define CTaskManager__HandleMessage_x                              0x536670
#define CTaskManager__GetTaskStatus_x                              0x538290
#define CTaskManager__GetElementDescription_x                      0x538310

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x577AB0
#define EqSoundManager__PlayScriptMp3_x                            0x577D70
#define EqSoundManager__SoundAssistPlay_x                          0x689930
#define EqSoundManager__WaveInstancePlay_x                         0x688EA0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52BAB0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9575B0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x563CA0
#define CAltAbilityData__GetMercMaxRank_x                          0x563C30
#define CAltAbilityData__GetMaxRank_x                              0x559260

//CTargetRing
#define CTargetRing__Cast_x                                        0x61D710

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9880
#define CharacterBase__CreateItemGlobalIndex_x                     0x512F30
#define CharacterBase__CreateItemIndex_x                           0x625820
#define CharacterBase__GetItemPossession_x                         0x4FEC20
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DB7A0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DB800
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x702150
#define CCastSpellWnd__IsBardSongPlaying_x                         0x702980
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x702A30

//messages
#define msg_spell_worn_off_x                                       0x5A0E50
#define msg_new_text_x                                             0x595C10
#define __msgTokenTextParam_x                                      0x5A3380
#define msgTokenText_x                                             0x5A35D0

//SpellManager
#define SpellManager__vftable_x                                    0xAEE69C
#define SpellManager__SpellManager_x                               0x68CC50
#define Spellmanager__LoadTextSpells_x                             0x68D540
#define SpellManager__GetSpellByGroupAndRank_x                     0x68CE20

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99FA40

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x513580
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A7140
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63E260
#define ItemGlobalIndex__IsValidIndex_x                            0x5135E0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D3B60
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D3DE0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x770860

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71F650
#define CCursorAttachment__AttachToCursor1_x                       0x71F690
#define CCursorAttachment__Deactivate_x                            0x720670

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x94A370
#define CSidlManagerBase__CreatePageWnd_x                          0x949B70
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x945E10
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x945DA0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x967700
#define CEQSuiteTextureLoader__GetTexture_x                        0x9673C0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x5104A0
#define CFindItemWnd__WndNotification_x                            0x510F80
#define CFindItemWnd__Update_x                                     0x511AF0
#define CFindItemWnd__PickupSelectedItem_x                         0x50FCF0

//IString
#define IString__Append_x                                          0x4F1530

//Camera
#define CDisplay__cameraType_x                                     0xE0360C
#define EverQuest__Cameras_x                                       0xEC6AD4

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x518C60
#define LootFiltersManager__GetItemFilterData_x                    0x518560
#define LootFiltersManager__RemoveItemLootFilter_x                 0x518590
#define LootFiltersManager__SetItemLootFilter_x                    0x5187B0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C7B10

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A55C0
#define CResolutionHandler__GetWindowedStyle_x                     0x684340

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x717D40

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E8DE0
#define CDistillerInfo__Instance_x                                 0x8E8D80

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x736C80
#define CGroupWnd__UpdateDisplay_x                                 0x735FF0

//ItemBase
#define ItemBase__IsLore_x                                         0x8A9670
#define ItemBase__IsLoreEquipped_x                                 0x8A96E0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DCB30
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DCC70
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DCCD0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6797C0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67D160

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x506890

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F34B0
#define FactionManagerClient__HandleFactionMessage_x               0x4F3B20
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F4120
#define FactionManagerClient__GetMaxFaction_x                      0x4F413F
#define FactionManagerClient__GetMinFaction_x                      0x4F40F0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FEBF0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92EB80

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BF10

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FEEB0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x563140

//CTargetManager
#define CTargetManager__Get_x                                      0x6904D0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6797C0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8CA0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AF5E0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF64168

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
