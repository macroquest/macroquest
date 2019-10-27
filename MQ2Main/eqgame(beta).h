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
#define __ExpectedVersionDate                                     "Oct 27 2019"
#define __ExpectedVersionTime                                     "04:47:43"
#define __ActualVersionDate_x                                      0xB00D60
#define __ActualVersionTime_x                                      0xB00D54
#define __ActualVersionBuild_x                                     0xAECA4C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x628640
#define __MemChecker1_x                                            0x8FA7A0
#define __MemChecker2_x                                            0x6B6B00
#define __MemChecker3_x                                            0x6B6A50
#define __MemChecker4_x                                            0x852550
#define __EncryptPad0_x                                            0xC363F0
#define __EncryptPad1_x                                            0xC945B0
#define __EncryptPad2_x                                            0xC46C88
#define __EncryptPad3_x                                            0xC46888
#define __EncryptPad4_x                                            0xC84C08
#define __EncryptPad5_x                                            0xF5DCCC
#define __AC1_x                                                    0x80F436
#define __AC2_x                                                    0x5E25FF
#define __AC3_x                                                    0x5E9CFF
#define __AC4_x                                                    0x5EDCC0
#define __AC5_x                                                    0x5F3FCF
#define __AC6_x                                                    0x5F85E6
#define __AC7_x                                                    0x5E2070
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1B2778

// Direct Input
#define DI8__Main_x                                                0xF601A8
#define DI8__Keyboard_x                                            0xF601AC
#define DI8__Mouse_x                                               0xF601C4
#define DI8__Mouse_Copy_x                                          0xEB9394
#define DI8__Mouse_Check_x                                         0xF5DCF4
#define __AutoSkillArray_x                                         0xEBA2AC
#define __Attack_x                                                 0xF580D3
#define __Autofire_x                                               0xF580D4
#define __BindList_x                                               0xC24E20
#define g_eqCommandStates_x                                        0xC25BA0
#define __Clicks_x                                                 0xEB944C
#define __CommandList_x                                            0xC26760
#define __CurrentMapLabel_x                                        0xF70B54
#define __CurrentSocial_x                                          0xC0E7CC
#define __DoAbilityList_x                                          0xEEFBF4
#define __do_loot_x                                                0x5AE940
#define __DrawHandler_x                                            0x15EFEC8
#define __GroupCount_x                                             0xEAB78A
#define __Guilds_x                                                 0xEAFBA0
#define __gWorld_x                                                 0xEAB63C
#define __HWnd_x                                                   0xF601C8
#define __heqmain_x                                                0xF6019C
#define __InChatMode_x                                             0xEB937C
#define __LastTell_x                                               0xEBB2F0
#define __LMouseHeldTime_x                                         0xEB94B8
#define __Mouse_x                                                  0xF60188
#define __MouseLook_x                                              0xEB9412
#define __MouseEventTime_x                                         0xF58BB4
#define __gpbCommandEvent_x                                        0xEAB9EC
#define __NetStatusToggle_x                                        0xEB9415
#define __PCNames_x                                                0xEBA89C
#define __RangeAttackReady_x                                       0xEBA590
#define __RMouseHeldTime_x                                         0xEB94B4
#define __RunWalkState_x                                           0xEB9380
#define __ScreenMode_x                                             0xDF6F6C
#define __ScreenX_x                                                0xEB9334
#define __ScreenY_x                                                0xEB9330
#define __ScreenXMax_x                                             0xEB9338
#define __ScreenYMax_x                                             0xEB933C
#define __ServerHost_x                                             0xEABC23
#define __ServerName_x                                             0xEEFBB4
#define __ShiftKeyDown_x                                           0xEB9A0C
#define __ShowNames_x                                              0xEBA74C
#define __Socials_x                                                0xEEFCB4
#define __SubscriptionType_x                                       0xFB5058
#define __TargetAggroHolder_x                                      0xF73508
#define __ZoneType_x                                               0xEB9810
#define __GroupAggro_x                                             0xF73548
#define __LoginName_x                                              0xF60904
#define __Inviter_x                                                0xF58050
#define __AttackOnAssist_x                                         0xEBA708
#define __UseTellWindows_x                                         0xEBAA38
#define __gfMaxZoomCameraDistance_x                                0xAF66C0
#define __gfMaxCameraDistance_x                                    0xB22C3C
#define __pulAutoRun_x                                             0xEB9430
#define __pulForward_x                                             0xEBAA70
#define __pulBackward_x                                            0xEBAA74
#define __pulTurnRight_x                                           0xEBAA78
#define __pulTurnLeft_x                                            0xEBAA7C
#define __pulStrafeLeft_x                                          0xEBAA80
#define __pulStrafeRight_x                                         0xEBAA84

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEABF38
#define instEQZoneInfo_x                                           0xEB9608
#define pinstActiveBanker_x                                        0xEABA04
#define pinstActiveCorpse_x                                        0xEAB9FC
#define pinstActiveGMaster_x                                       0xEABA00
#define pinstActiveMerchant_x                                      0xEAB9F8
#define pinstAltAdvManager_x                                       0xDF8168
#define pinstBandageTarget_x                                       0xEABA14
#define pinstCamActor_x                                            0xDF6F5C
#define pinstCDBStr_x                                              0xDF6E84
#define pinstCDisplay_x                                            0xEAB640
#define pinstCEverQuest_x                                          0xF601C0
#define pinstEverQuestInfo_x                                       0xEB9328
#define pinstCharData_x                                            0xEAB76C
#define pinstCharSpawn_x                                           0xEABACC
#define pinstControlledMissile_x                                   0xEABD2C
#define pinstControlledPlayer_x                                    0xEABACC
#define pinstCResolutionHandler_x                                  0x15F00F8
#define pinstCSidlManager_x                                        0x15EF090
#define pinstCXWndManager_x                                        0x15EF08C
#define instDynamicZone_x                                          0xEAFA78
#define pinstDZMember_x                                            0xEAFB88
#define pinstDZTimerInfo_x                                         0xEAFB8C
#define pinstEqLogin_x                                             0xF60250
#define instEQMisc_x                                               0xDF6DC8
#define pinstEQSoundManager_x                                      0xDF9138
#define pinstEQSpellStrings_x                                      0xCB9868
#define instExpeditionLeader_x                                     0xEAFAC2
#define instExpeditionName_x                                       0xEAFB02
#define pinstGroup_x                                               0xEAB786
#define pinstImeManager_x                                          0x15EF088
#define pinstLocalPlayer_x                                         0xEAB9F4
#define pinstMercenaryData_x                                       0xF5A6AC
#define pinstMercenaryStats_x                                      0xF73654
#define pinstModelPlayer_x                                         0xEABA0C
#define pinstPCData_x                                              0xEAB76C
#define pinstSkillMgr_x                                            0xF5C810
#define pinstSpawnManager_x                                        0xF5B2B8
#define pinstSpellManager_x                                        0xF5CA30
#define pinstSpellSets_x                                           0xF50CFC
#define pinstStringTable_x                                         0xEAB770
#define pinstSwitchManager_x                                       0xEA94D8
#define pinstTarget_x                                              0xEABAC8
#define pinstTargetObject_x                                        0xEABAD4
#define pinstTargetSwitch_x                                        0xEA9634
#define pinstTaskMember_x                                          0xDF6C58
#define pinstTrackTarget_x                                         0xEABAD0
#define pinstTradeTarget_x                                         0xEABA08
#define instTributeActive_x                                        0xDF6DE9
#define pinstViewActor_x                                           0xDF6F58
#define pinstWorldData_x                                           0xEA9628
#define pinstZoneAddr_x                                            0xEB98A8
#define pinstPlayerPath_x                                          0xF5B350
#define pinstTargetIndicator_x                                     0xF5CC98
#define EQObject_Top_x                                             0xEAB9F0
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDF722C
#define pinstCAchievementsWnd_x                                    0xDF6FB8
#define pinstCActionsWnd_x                                         0xDF6FE8
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDF7794
#define pinstCAdvancedLootWnd_x                                    0xDF7764
#define pinstCAdventureLeaderboardWnd_x                            0xF6A328
#define pinstCAdventureRequestWnd_x                                0xF6A3D8
#define pinstCAdventureStatsWnd_x                                  0xF6A488
#define pinstCAggroMeterWnd_x                                      0xDF6F50
#define pinstCAlarmWnd_x                                           0xDF7728
#define pinstCAlertHistoryWnd_x                                    0xDF775C
#define pinstCAlertStackWnd_x                                      0xDF7240
#define pinstCAlertWnd_x                                           0xDF7274
#define pinstCAltStorageWnd_x                                      0xF6A7E8
#define pinstCAudioTriggersWindow_x                                0xCABB98
#define pinstCAuraWnd_x                                            0xDF6F24
#define pinstCAvaZoneWnd_x                                         0xDF6FC0
#define pinstCBandolierWnd_x                                       0xDF6F4C
#define pinstCBankWnd_x                                            0xDF6F20
#define pinstCBarterMerchantWnd_x                                  0xF6BA28
#define pinstCBarterSearchWnd_x                                    0xF6BAD8
#define pinstCBarterWnd_x                                          0xF6BB88
#define pinstCBazaarConfirmationWnd_x                              0xDF6FF8
#define pinstCBazaarSearchWnd_x                                    0xDF6FAC
#define pinstCBazaarWnd_x                                          0xDF7714
#define pinstCBlockedBuffWnd_x                                     0xDF6F28
#define pinstCBlockedPetBuffWnd_x                                  0xDF6F48
#define pinstCBodyTintWnd_x                                        0xDF6FFC
#define pinstCBookWnd_x                                            0xDF6F8C
#define pinstCBreathWnd_x                                          0xDF726C
#define pinstCBuffWindowNORMAL_x                                   0xDF77AC
#define pinstCBuffWindowSHORT_x                                    0xDF77B0
#define pinstCBugReportWnd_x                                       0xDF77B8
#define pinstCButtonWnd_x                                          0x15EF2F8
#define pinstCCastingWnd_x                                         0xDF6F7C
#define pinstCCastSpellWnd_x                                       0xDF7244
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDF7718
#define pinstCChatWindowManager_x                                  0xF6C648
#define pinstCClaimWnd_x                                           0xF6C7A0
#define pinstCColorPickerWnd_x                                     0xDF6FF0
#define pinstCCombatAbilityWnd_x                                   0xDF7724
#define pinstCCombatSkillsSelectWnd_x                              0xDF7744
#define pinstCCompassWnd_x                                         0xDF6FEC
#define pinstCConfirmationDialog_x                                 0xF716A0
#define pinstCContainerMgr_x                                       0xDF770C
#define pinstCContextMenuManager_x                                 0x15EF048
#define pinstCCursorAttachment_x                                   0xDF6F60
#define pinstCDynamicZoneWnd_x                                     0xF6CD68
#define pinstCEditLabelWnd_x                                       0xDF77A0
#define pinstCEQMainWnd_x                                          0xF6CFB0
#define pinstCEventCalendarWnd_x                                   0xDF77A8
#define pinstCExtendedTargetWnd_x                                  0xDF6F3C
#define pinstCFacePick_x                                           0xDF7754
#define pinstCFactionWnd_x                                         0xDF7300
#define pinstCFellowshipWnd_x                                      0xF6D1B0
#define pinstCFileSelectionWnd_x                                   0xDF6F78
#define pinstCFindItemWnd_x                                        0xDF7280
#define pinstCFindLocationWnd_x                                    0xF6D308
#define pinstCFriendsWnd_x                                         0xDF7760
#define pinstCGemsGameWnd_x                                        0xDF72FC
#define pinstCGiveWnd_x                                            0xDF772C
#define pinstCGroupSearchFiltersWnd_x                              0xDF6F84
#define pinstCGroupSearchWnd_x                                     0xF6D700
#define pinstCGroupWnd_x                                           0xF6D7B0
#define pinstCGuildBankWnd_x                                       0xEBA6EC
#define pinstCGuildCreationWnd_x                                   0xF6D910
#define pinstCGuildMgmtWnd_x                                       0xF6D9C0
#define pinstCharacterCreation_x                                   0xDF774C
#define pinstCHelpWnd_x                                            0xDF778C
#define pinstCHeritageSelectionWnd_x                               0xDF7768
#define pinstCHotButtonWnd_x                                       0xF6FB18
#define pinstCHotButtonWnd1_x                                      0xF6FB18
#define pinstCHotButtonWnd2_x                                      0xF6FB1C
#define pinstCHotButtonWnd3_x                                      0xF6FB20
#define pinstCHotButtonWnd4_x                                      0xF6FB24
#define pinstCIconSelectionWnd_x                                   0xDF6F54
#define pinstCInspectWnd_x                                         0xDF7788
#define pinstCInventoryWnd_x                                       0xDF776C
#define pinstCInvSlotMgr_x                                         0xDF7228
#define pinstCItemDisplayManager_x                                 0xF700A8
#define pinstCItemExpTransferWnd_x                                 0xF701DC
#define pinstCItemOverflowWnd_x                                    0xDF6FB4
#define pinstCJournalCatWnd_x                                      0xDF6F94
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDF6F40
#define pinstCKeyRingWnd_x                                         0xDF779C
#define pinstCLargeDialogWnd_x                                     0xF72320
#define pinstCLayoutCopyWnd_x                                      0xF70528
#define pinstCLFGuildWnd_x                                         0xF705D8
#define pinstCLoadskinWnd_x                                        0xDF7710
#define pinstCLootFiltersCopyWnd_x                                 0xCC8160
#define pinstCLootFiltersWnd_x                                     0xDF7254
#define pinstCLootSettingsWnd_x                                    0xDF727C
#define pinstCLootWnd_x                                            0xDF6F98
#define pinstCMailAddressBookWnd_x                                 0xDF7234
#define pinstCMailCompositionWnd_x                                 0xDF7014
#define pinstCMailIgnoreListWnd_x                                  0xDF7238
#define pinstCMailWnd_x                                            0xDF6FE4
#define pinstCManageLootWnd_x                                      0xDF8618
#define pinstCMapToolbarWnd_x                                      0xDF7790
#define pinstCMapViewWnd_x                                         0xDF7778
#define pinstCMarketplaceWnd_x                                     0xDF7270
#define pinstCMerchantWnd_x                                        0xDF6F9C
#define pinstCMIZoneSelectWnd_x                                    0xF70E10
#define pinstCMusicPlayerWnd_x                                     0xDF6FA4
#define pinstCNameChangeMercWnd_x                                  0xDF6FE0
#define pinstCNameChangePetWnd_x                                   0xDF6FBC
#define pinstCNameChangeWnd_x                                      0xDF7008
#define pinstCNoteWnd_x                                            0xDF777C
#define pinstCObjectPreviewWnd_x                                   0xDF7278
#define pinstCOptionsWnd_x                                         0xDF7780
#define pinstCPetInfoWnd_x                                         0xDF6FC4
#define pinstCPetitionQWnd_x                                       0xDF6FA8
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDF7000
#define pinstCPlayerWnd_x                                          0xDF6FC8
#define pinstCPopupWndManager_x                                    0xF716A0
#define pinstCProgressionSelectionWnd_x                            0xF71750
#define pinstCPurchaseGroupWnd_x                                   0xDF7734
#define pinstCPurchaseWnd_x                                        0xDF7708
#define pinstCPvPLeaderboardWnd_x                                  0xF71800
#define pinstCPvPStatsWnd_x                                        0xF718B0
#define pinstCQuantityWnd_x                                        0xDF6F44
#define pinstCRaceChangeWnd_x                                      0xDF7230
#define pinstCRaidOptionsWnd_x                                     0xDF6F88
#define pinstCRaidWnd_x                                            0xDF701C
#define pinstCRealEstateItemsWnd_x                                 0xDF6FB0
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDF6F30
#define pinstCRealEstateManageWnd_x                                0xDF773C
#define pinstCRealEstateNeighborhoodWnd_x                          0xDF7758
#define pinstCRealEstatePlotSearchWnd_x                            0xDF7770
#define pinstCRealEstatePurchaseWnd_x                              0xDF7784
#define pinstCRespawnWnd_x                                         0xDF6F34
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDF723C
#define pinstCSendMoneyWnd_x                                       0xDF7740
#define pinstCServerListWnd_x                                      0xDF77A4
#define pinstCSkillsSelectWnd_x                                    0xDF771C
#define pinstCSkillsWnd_x                                          0xDF728C
#define pinstCSocialEditWnd_x                                      0xDF7798
#define pinstCSocialWnd_x                                          0xDF6FDC
#define pinstCSpellBookWnd_x                                       0xDF7720
#define pinstCStoryWnd_x                                           0xDF6FCC
#define pinstCTargetOfTargetWnd_x                                  0xF736D8
#define pinstCTargetWnd_x                                          0xDF6F2C
#define pinstCTaskOverlayWnd_x                                     0xDF7730
#define pinstCTaskSelectWnd_x                                      0xF73830
#define pinstCTaskManager_x                                        0xCC8AA0
#define pinstCTaskTemplateSelectWnd_x                              0xF738E0
#define pinstCTaskWnd_x                                            0xF73990
#define pinstCTextEntryWnd_x                                       0xDF77B4
#define pinstCTimeLeftWnd_x                                        0xDF6F80
#define pinstCTipWndCONTEXT_x                                      0xF73B94
#define pinstCTipWndOFDAY_x                                        0xF73B90
#define pinstCTitleWnd_x                                           0xF73C40
#define pinstCTrackingWnd_x                                        0xDF7774
#define pinstCTradeskillWnd_x                                      0xF73DA8
#define pinstCTradeWnd_x                                           0xDF700C
#define pinstCTrainWnd_x                                           0xDF7004
#define pinstCTributeBenefitWnd_x                                  0xF73FA8
#define pinstCTributeMasterWnd_x                                   0xF74058
#define pinstCTributeTrophyWnd_x                                   0xF74108
#define pinstCVideoModesWnd_x                                      0xDF7018
#define pinstCVoiceMacroWnd_x                                      0xF5D400
#define pinstCVoteResultsWnd_x                                     0xDF6FA0
#define pinstCVoteWnd_x                                            0xDF6F90
#define pinstCWebManager_x                                         0xF5DA7C
#define pinstCZoneGuideWnd_x                                       0xDF7738
#define pinstCZonePathWnd_x                                        0xDF7748

#define pinstEQSuiteTextureLoader_x                                0xC96088
#define pinstItemIconCache_x                                       0xF6CF68
#define pinstLootFiltersManager_x                                  0xCC8210
#define pinstRewardSelectionWnd_x                                  0xF71FF8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5A9DA0
#define __CastRay2_x                                               0x5A9DF0
#define __ConvertItemTags_x                                        0x5C5940
#define __CleanItemTags_x                                          0x47D180
#define __DoesFileExist_x                                          0x8FD880
#define __EQGetTime_x                                              0x8FA270
#define __ExecuteCmd_x                                             0x5A2680
#define __FixHeading_x                                             0x994530
#define __GameLoop_x                                               0x6B5CF0
#define __get_bearing_x                                            0x5A9910
#define __get_melee_range_x                                        0x5A9FE0
#define __GetAnimationCache_x                                      0x71AF60
#define __GetGaugeValueFromEQ_x                                    0x80D8E0
#define __GetLabelFromEQ_x                                         0x80F3C0
#define __GetXTargetType_x                                         0x995F80
#define __HandleMouseWheel_x                                       0x6B6BB0
#define __HeadingDiff_x                                            0x9945A0
#define __HelpPath_x                                               0xF587A4
#define __LoadFrontEnd_x                                           0x6B3010
#define __NewUIINI_x                                               0x80D5B0
#define __ProcessGameEvents_x                                      0x609E50
#define __ProcessMouseEvent_x                                      0x609610
#define __SaveColors_x                                             0x54EE10
#define __STMLToText_x                                             0x937C00
#define __ToggleKeyRingItem_x                                      0x512060
#define CMemoryMappedFile__SetFile_x                               0xA836E0
#define CrashDetected_x                                            0x6B4AB0
#define DrawNetStatus_x                                            0x635A50
#define Expansion_HoT_x                                            0xEBA6F4
#define Teleport_Table_Size_x                                      0xEABADC
#define Teleport_Table_x                                           0xEA9638
#define Util__FastTime_x                                           0x8F9E40

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490480
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499380
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499150
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A10
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492E60

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x556940
#define AltAdvManager__IsAbilityReady_x                            0x555870
#define AltAdvManager__GetAAById_x                                 0x555A70
#define AltAdvManager__CanTrainAbility_x                           0x555AE0
#define AltAdvManager__CanSeeAbility_x                             0x555E40

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA170
#define CharacterZoneClient__HasSkill_x                            0x4D5060
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6780
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE3B0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA9B0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9120
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9200
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D92E0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C31A0
#define CharacterZoneClient__BardCastBard_x                        0x4C5D00
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAA80
#define CharacterZoneClient__GetEffect_x                           0x4BA8F0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C41F0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C42C0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4310
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4460
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4630
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2880
#define CharacterZoneClient__FindItemByGuid_x                      0x4D76E0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7160

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DC690
#define CBankWnd__WndNotification_x                                0x6DC470

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E9E30

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x6184E0
#define CButtonWnd__CButtonWnd_x                                   0x933FD0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x709FA0
#define CChatManager__InitContextMenu_x                            0x7030F0
#define CChatManager__FreeChatWindow_x                             0x708AE0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8810
#define CChatManager__SetLockedActiveChatWindow_x                  0x709C20
#define CChatManager__CreateChatWindow_x                           0x709120

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8920

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x948730
#define CContextMenu__dCContextMenu_x                              0x948960
#define CContextMenu__AddMenuItem_x                                0x948970
#define CContextMenu__RemoveMenuItem_x                             0x948C80
#define CContextMenu__RemoveAllMenuItems_x                         0x948CA0
#define CContextMenu__CheckMenuItem_x                              0x948D20
#define CContextMenu__SetMenuItem_x                                0x948BA0
#define CContextMenu__AddSeparator_x                               0x948B00

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9492B0
#define CContextMenuManager__RemoveMenu_x                          0x949320
#define CContextMenuManager__PopupMenu_x                           0x9493E0
#define CContextMenuManager__Flush_x                               0x949250
#define CContextMenuManager__GetMenu_x                             0x49B480
#define CContextMenuManager__CreateDefaultMenu_x                   0x715750

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D6E10
#define CChatService__GetFriendName_x                              0x8D6E20

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x70A8D0
#define CChatWindow__Clear_x                                       0x70BB90
#define CChatWindow__WndNotification_x                             0x70C320
#define CChatWindow__AddHistory_x                                  0x70B450

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x945B90
#define CComboWnd__Draw_x                                          0x945090
#define CComboWnd__GetCurChoice_x                                  0x9459D0
#define CComboWnd__GetListRect_x                                   0x945530
#define CComboWnd__GetTextRect_x                                   0x945C00
#define CComboWnd__InsertChoice_x                                  0x9456C0
#define CComboWnd__SetColors_x                                     0x945690
#define CComboWnd__SetChoice_x                                     0x9459A0
#define CComboWnd__GetItemCount_x                                  0x9459E0
#define CComboWnd__GetCurChoiceText_x                              0x945A20
#define CComboWnd__GetChoiceText_x                                 0x9459F0
#define CComboWnd__InsertChoiceAtIndex_x                           0x945760

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x713120
#define CContainerWnd__vftable_x                                   0xB09F54
#define CContainerWnd__SetContainer_x                              0x714690

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x549850
#define CDisplay__PreZoneMainUI_x                                  0x549860
#define CDisplay__CleanGameUI_x                                    0x54EBD0
#define CDisplay__GetClickedActor_x                                0x541B70
#define CDisplay__GetUserDefinedColor_x                            0x53A230
#define CDisplay__GetWorldFilePath_x                               0x5435E0
#define CDisplay__is3dON_x                                         0x53E7D0
#define CDisplay__ReloadUI_x                                       0x548CE0
#define CDisplay__WriteTextHD2_x                                   0x53E5C0
#define CDisplay__TrueDistance_x                                   0x5452A0
#define CDisplay__SetViewActor_x                                   0x541490
#define CDisplay__GetFloorHeight_x                                 0x53E890
#define CDisplay__SetRenderWindow_x                                0x53D1F0
#define CDisplay__ToggleScreenshotMode_x                           0x540F60

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x968280

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x94BC70
#define CEditWnd__GetCharIndexPt_x                                 0x94CB90
#define CEditWnd__GetDisplayString_x                               0x94CA40
#define CEditWnd__GetHorzOffset_x                                  0x94B2B0
#define CEditWnd__GetLineForPrintableChar_x                        0x94DD00
#define CEditWnd__GetSelStartPt_x                                  0x94CE40
#define CEditWnd__GetSTMLSafeText_x                                0x94C860
#define CEditWnd__PointFromPrintableChar_x                         0x94D940
#define CEditWnd__SelectableCharFromPoint_x                        0x94DAB0
#define CEditWnd__SetEditable_x                                    0x94CF00
#define CEditWnd__SetWindowTextA_x                                 0x94C5E0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5F7AC0
#define CEverQuest__ClickedPlayer_x                                0x5E9AE0
#define CEverQuest__CreateTargetIndicator_x                        0x6070F0
#define CEverQuest__DeleteTargetIndicator_x                        0x607180
#define CEverQuest__DoTellWindow_x                                 0x4E8A00
#define CEverQuest__OutputTextToLog_x                              0x4E8C80
#define CEverQuest__DropHeldItemOnGround_x                         0x5DEB20
#define CEverQuest__dsp_chat_x                                     0x4E9010
#define CEverQuest__trimName_x                                     0x6033D0
#define CEverQuest__Emote_x                                        0x5F8320
#define CEverQuest__EnterZone_x                                    0x5F22A0
#define CEverQuest__GetBodyTypeDesc_x                              0x5FCC90
#define CEverQuest__GetClassDesc_x                                 0x5FD2D0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5FD8D0
#define CEverQuest__GetDeityDesc_x                                 0x605A30
#define CEverQuest__GetLangDesc_x                                  0x5FDA90
#define CEverQuest__GetRaceDesc_x                                  0x5FD2B0
#define CEverQuest__InterpretCmd_x                                 0x606000
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E2D20
#define CEverQuest__LMouseUp_x                                     0x5E10B0
#define CEverQuest__RightClickedOnPlayer_x                         0x5E3600
#define CEverQuest__RMouseUp_x                                     0x5E2030
#define CEverQuest__SetGameState_x                                 0x5DE8B0
#define CEverQuest__UPCNotificationFlush_x                         0x6032D0
#define CEverQuest__IssuePetCommand_x                              0x5FEE90
#define CEverQuest__ReportSuccessfulHit_x                          0x5F9710

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x725120
#define CGaugeWnd__CalcLinesFillRect_x                             0x725180
#define CGaugeWnd__Draw_x                                          0x7247A0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF370
#define CGuild__GetGuildName_x                                     0x4AE450
#define CGuild__GetGuildIndex_x                                    0x4AE7E0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x740570

//CHotButton
#define CHotButton__SetButtonSize_x                                0x6188A0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x74D530
#define CInvSlotMgr__MoveItem_x                                    0x74C290
#define CInvSlotMgr__SelectSlot_x                                  0x74D600

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x74AB00
#define CInvSlot__SliderComplete_x                                 0x748850
#define CInvSlot__GetItemBase_x                                    0x7481F0
#define CInvSlot__UpdateItem_x                                     0x748360

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74F050
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74E200
#define CInvSlotWnd__HandleLButtonUp_x                             0x74EBD0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x808BF0
#define CItemDisplayWnd__UpdateStrings_x                           0x75D750
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7574A0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7579C0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x75DD60
#define CItemDisplayWnd__AboutToShow_x                             0x75D3A0
#define CItemDisplayWnd__WndNotification_x                         0x75EE40
#define CItemDisplayWnd__RequestConvertItem_x                      0x75E900
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x75C400
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x75D1C0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x841660

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x763390

// CLabel 
#define CLabel__Draw_x                                             0x768E20

// CListWnd
#define CListWnd__CListWnd_x                                       0x91E370
#define CListWnd__dCListWnd_x                                      0x91E690
#define CListWnd__AddColumn_x                                      0x922B00
#define CListWnd__AddColumn1_x                                     0x922B50
#define CListWnd__AddLine_x                                        0x922EE0
#define CListWnd__AddString_x                                      0x922CE0
#define CListWnd__CalculateFirstVisibleLine_x                      0x9228C0
#define CListWnd__CalculateVSBRange_x                              0x9226A0
#define CListWnd__ClearSel_x                                       0x9236C0
#define CListWnd__ClearAllSel_x                                    0x923720
#define CListWnd__CloseAndUpdateEditWindow_x                       0x924130
#define CListWnd__Compare_x                                        0x921FD0
#define CListWnd__Draw_x                                           0x91E7C0
#define CListWnd__DrawColumnSeparators_x                           0x920FA0
#define CListWnd__DrawHeader_x                                     0x921410
#define CListWnd__DrawItem_x                                       0x921910
#define CListWnd__DrawLine_x                                       0x921110
#define CListWnd__DrawSeparator_x                                  0x921040
#define CListWnd__EnableLine_x                                     0x920880
#define CListWnd__EnsureVisible_x                                  0x924050
#define CListWnd__ExtendSel_x                                      0x9235F0
#define CListWnd__GetColumnTooltip_x                               0x9203C0
#define CListWnd__GetColumnMinWidth_x                              0x920430
#define CListWnd__GetColumnWidth_x                                 0x920330
#define CListWnd__GetCurSel_x                                      0x91FCC0
#define CListWnd__GetItemAtPoint_x                                 0x920B00
#define CListWnd__GetItemAtPoint1_x                                0x920B70
#define CListWnd__GetItemData_x                                    0x91FD40
#define CListWnd__GetItemHeight_x                                  0x920100
#define CListWnd__GetItemIcon_x                                    0x91FED0
#define CListWnd__GetItemRect_x                                    0x920970
#define CListWnd__GetItemText_x                                    0x91FD80
#define CListWnd__GetSelList_x                                     0x923770
#define CListWnd__GetSeparatorRect_x                               0x920DB0
#define CListWnd__InsertLine_x                                     0x9232D0
#define CListWnd__RemoveLine_x                                     0x923420
#define CListWnd__SetColors_x                                      0x922670
#define CListWnd__SetColumnJustification_x                         0x9223A0
#define CListWnd__SetColumnWidth_x                                 0x9222C0
#define CListWnd__SetCurSel_x                                      0x923530
#define CListWnd__SetItemColor_x                                   0x923D00
#define CListWnd__SetItemData_x                                    0x923CC0
#define CListWnd__SetItemText_x                                    0x9238E0
#define CListWnd__ShiftColumnSeparator_x                           0x922460
#define CListWnd__Sort_x                                           0x922150
#define CListWnd__ToggleSel_x                                      0x923560
#define CListWnd__SetColumnsSizable_x                              0x922510
#define CListWnd__SetItemWnd_x                                     0x923B90
#define CListWnd__GetItemWnd_x                                     0x91FF20
#define CListWnd__SetItemIcon_x                                    0x923960
#define CListWnd__CalculateCustomWindowPositions_x                 0x9229C0
#define CListWnd__SetVScrollPos_x                                  0x9222A0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77E500
#define CMapViewWnd__GetWorldCoordinates_x                         0x77CC10
#define CMapViewWnd__HandleLButtonDown_x                           0x779C50

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79E540
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79EE20
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79F350
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A22D0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x79D0A0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A7E80
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79E150

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A4780
#define CPacketScrambler__hton_x                                   0x8A4770

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x93D230
#define CSidlManager__FindScreenPieceTemplate_x                    0x93D640
#define CSidlManager__FindScreenPieceTemplate1_x                   0x93D430
#define CSidlManager__CreateLabel_x                                0x800040
#define CSidlManager__CreateXWndFromTemplate_x                     0x9405A0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x940770
#define CSidlManager__CreateXWnd_x                                 0x7FFF70
#define CSidlManager__CreateHotButtonWnd_x                         0x800530

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x939D10
#define CSidlScreenWnd__CalculateVSBRange_x                        0x939C10
#define CSidlScreenWnd__ConvertToRes_x                             0x95F2D0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9396A0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x939390
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x939460
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x939530
#define CSidlScreenWnd__DrawSidlPiece_x                            0x93A1B0
#define CSidlScreenWnd__EnableIniStorage_x                         0x93A680
#define CSidlScreenWnd__GetSidlPiece_x                             0x93A3A0
#define CSidlScreenWnd__Init1_x                                    0x938F90
#define CSidlScreenWnd__LoadIniInfo_x                              0x93A6D0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x93B210
#define CSidlScreenWnd__LoadSidlScreen_x                           0x9383B0
#define CSidlScreenWnd__StoreIniInfo_x                             0x93AD90
#define CSidlScreenWnd__StoreIniVis_x                              0x93B0F0
#define CSidlScreenWnd__WndNotification_x                          0x93A0C0
#define CSidlScreenWnd__GetChildItem_x                             0x93A600
#define CSidlScreenWnd__HandleLButtonUp_x                          0x929E90
#define CSidlScreenWnd__m_layoutCopy_x                             0x15EEF18

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x67CF10
#define CSkillMgr__GetSkillCap_x                                   0x67D0F0
#define CSkillMgr__GetNameToken_x                                  0x67C690
#define CSkillMgr__IsActivatedSkill_x                              0x67C7D0
#define CSkillMgr__IsCombatSkill_x                                 0x67C710

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x94A090
#define CSliderWnd__SetValue_x                                     0x949F00
#define CSliderWnd__SetNumTicks_x                                  0x949F60

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x806060

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x952860
#define CStmlWnd__CalculateHSBRange_x                              0x953940
#define CStmlWnd__CalculateVSBRange_x                              0x9538B0
#define CStmlWnd__CanBreakAtCharacter_x                            0x957C80
#define CStmlWnd__FastForwardToEndOfTag_x                          0x958910
#define CStmlWnd__ForceParseNow_x                                  0x952E00
#define CStmlWnd__GetNextTagPiece_x                                0x957BE0
#define CStmlWnd__GetSTMLText_x                                    0x5019C0
#define CStmlWnd__GetVisibleText_x                                 0x952E20
#define CStmlWnd__InitializeWindowVariables_x                      0x958760
#define CStmlWnd__MakeStmlColorTag_x                               0x951ED0
#define CStmlWnd__MakeWndNotificationTag_x                         0x951F40
#define CStmlWnd__SetSTMLText_x                                    0x950F80
#define CStmlWnd__StripFirstSTMLLines_x                            0x959A10
#define CStmlWnd__UpdateHistoryString_x                            0x958B20

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9500D0
#define CTabWnd__DrawCurrentPage_x                                 0x950800
#define CTabWnd__DrawTab_x                                         0x950520
#define CTabWnd__GetCurrentPage_x                                  0x94F8D0
#define CTabWnd__GetPageInnerRect_x                                0x94FB10
#define CTabWnd__GetTabInnerRect_x                                 0x94FA50
#define CTabWnd__GetTabRect_x                                      0x94F900
#define CTabWnd__InsertPage_x                                      0x94FD20
#define CTabWnd__SetPage_x                                         0x94FB90
#define CTabWnd__SetPageRect_x                                     0x950010
#define CTabWnd__UpdatePage_x                                      0x9503E0
#define CTabWnd__GetPageFromTabIndex_x                             0x950460
#define CTabWnd__GetCurrentTabIndex_x                              0x94F8C0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x763780
#define CPageWnd__SetTabText_x                                     0x94F410

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9000

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x926D50
#define CTextureFont__GetTextExtent_x                              0x926F10

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AFEE0
#define CHtmlComponentWnd__ValidateUri_x                           0x741F60
#define CHtmlWnd__SetClientCallbacks_x                             0x61D930
#define CHtmlWnd__AddObserver_x                                    0x61D950
#define CHtmlWnd__RemoveObserver_x                                 0x61D9B0
#define Window__getProgress_x                                      0x859B80
#define Window__getStatus_x                                        0x859BA0
#define Window__getURI_x                                           0x859BB0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x964D10

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x913F30

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8550
#define CXStr__CXStr1_x                                            0x4B62E0
#define CXStr__CXStr3_x                                            0x8F6370
#define CXStr__dCXStr_x                                            0x478810
#define CXStr__operator_equal_x                                    0x8F65A0
#define CXStr__operator_equal1_x                                   0x8F65E0
#define CXStr__operator_plus_equal1_x                              0x8F7070
#define CXStr__SetString_x                                         0x8F8F60
#define CXStr__operator_char_p_x                                   0x8F6AE0
#define CXStr__GetChar_x                                           0x8F8890
#define CXStr__Delete_x                                            0x8F8160
#define CXStr__GetUnicode_x                                        0x8F8900
#define CXStr__GetLength_x                                         0x47D530
#define CXStr__Mid_x                                               0x47D540
#define CXStr__Insert_x                                            0x8F8960
#define CXStr__FindNext_x                                          0x8F85D0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x948350
#define CXWnd__BringToTop_x                                        0x92D5A0
#define CXWnd__Center_x                                            0x92D120
#define CXWnd__ClrFocus_x                                          0x92CF30
#define CXWnd__Destroy_x                                           0x92CFE0
#define CXWnd__DoAllDrawing_x                                      0x929640
#define CXWnd__DrawChildren_x                                      0x929610
#define CXWnd__DrawColoredRect_x                                   0x929AA0
#define CXWnd__DrawTooltip_x                                       0x928170
#define CXWnd__DrawTooltipAtPoint_x                                0x928230
#define CXWnd__GetBorderFrame_x                                    0x929900
#define CXWnd__GetChildWndAt_x                                     0x92D640
#define CXWnd__GetClientClipRect_x                                 0x92B870
#define CXWnd__GetScreenClipRect_x                                 0x92B940
#define CXWnd__GetScreenRect_x                                     0x92BB00
#define CXWnd__GetTooltipRect_x                                    0x929AF0
#define CXWnd__GetWindowTextA_x                                    0x49CB60
#define CXWnd__IsActive_x                                          0x92A210
#define CXWnd__IsDescendantOf_x                                    0x92C4B0
#define CXWnd__IsReallyVisible_x                                   0x92C4E0
#define CXWnd__IsType_x                                            0x92DCA0
#define CXWnd__Move_x                                              0x92C540
#define CXWnd__Move1_x                                             0x92C5F0
#define CXWnd__ProcessTransition_x                                 0x92D0D0
#define CXWnd__Refade_x                                            0x92C8C0
#define CXWnd__Resize_x                                            0x92CB60
#define CXWnd__Right_x                                             0x92D360
#define CXWnd__SetFocus_x                                          0x92CEF0
#define CXWnd__SetFont_x                                           0x92CF60
#define CXWnd__SetKeyTooltip_x                                     0x92DAD0
#define CXWnd__SetMouseOver_x                                      0x92AA40
#define CXWnd__StartFade_x                                         0x92C3A0
#define CXWnd__GetChildItem_x                                      0x92D7B0
#define CXWnd__SetParent_x                                         0x92C2A0
#define CXWnd__Minimize_x                                          0x92CBD0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x960350

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x930510
#define CXWndManager__DrawWindows_x                                0x930530
#define CXWndManager__GetKeyboardFlags_x                           0x932C40
#define CXWndManager__HandleKeyboardMsg_x                          0x9327F0
#define CXWndManager__RemoveWnd_x                                  0x932E90
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9333F0

// CDBStr
#define CDBStr__GetString_x                                        0x539200

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB990
#define EQ_Character__Cur_HP_x                                     0x4D20A0
#define EQ_Character__Cur_Mana_x                                   0x4D97E0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEA00
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B24C0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2610
#define EQ_Character__GetHPRegen_x                                 0x4DF5B0
#define EQ_Character__GetEnduranceRegen_x                          0x4DFBB0
#define EQ_Character__GetManaRegen_x                               0x4DFFF0
#define EQ_Character__Max_Endurance_x                              0x643890
#define EQ_Character__Max_HP_x                                     0x4D1ED0
#define EQ_Character__Max_Mana_x                                   0x643690
#define EQ_Character__doCombatAbility_x                            0x645CF0
#define EQ_Character__UseSkill_x                                   0x4E1DD0
#define EQ_Character__GetConLevel_x                                0x63C9C0
#define EQ_Character__IsExpansionFlag_x                            0x5A0E60
#define EQ_Character__TotalEffect_x                                0x4C5440
#define EQ_Character__GetPCSpellAffect_x                           0x4BF750
#define EQ_Character__SpellDuration_x                              0x4BF280
#define EQ_Character__GetAdjustedSkill_x                           0x4D4E20
#define EQ_Character__GetBaseSkill_x                               0x4D5DC0
#define EQ_Character__CanUseItem_x                                 0x4D9AF0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C3D30

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x659D90

//PcClient
#define PcClient__PcClient_x                                       0x63A100

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B95E0
#define CCharacterListWnd__EnterWorld_x                            0x4B9020
#define CCharacterListWnd__Quit_x                                  0x4B8D70
#define CCharacterListWnd__UpdateList_x                            0x4B91B0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x61EB80
#define EQ_Item__CreateItemTagString_x                             0x89DFB0
#define EQ_Item__IsStackable_x                                     0x8A2B20
#define EQ_Item__GetImageNum_x                                     0x89FA30
#define EQ_Item__CreateItemClient_x                                0x61DD50
#define EQ_Item__GetItemValue_x                                    0x8A0D30
#define EQ_Item__ValueSellMerchant_x                               0x8A4350
#define EQ_Item__IsKeyRingItem_x                                   0x8A2430
#define EQ_Item__CanGoInBag_x                                      0x61ECA0
#define EQ_Item__IsEmpty_x                                         0x8A1F80
#define EQ_Item__GetMaxItemCount_x                                 0x8A1150
#define EQ_Item__GetHeldItem_x                                     0x89F900
#define EQ_Item__GetAugmentFitBySlot_x                             0x89D910

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x557610
#define EQ_LoadingS__Array_x                                       0xC1DB60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6441F0
#define EQ_PC__GetAlternateAbilityId_x                             0x8AD540
#define EQ_PC__GetCombatAbility_x                                  0x8ADBB0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8ADC20
#define EQ_PC__GetItemRecastTimer_x                                0x646270
#define EQ_PC__HasLoreItem_x                                       0x63D180
#define EQ_PC__AlertInventoryChanged_x                             0x63C300
#define EQ_PC__GetPcZoneClient_x                                   0x6688A0
#define EQ_PC__RemoveMyAffect_x                                    0x6494A0
#define EQ_PC__GetKeyRingItems_x                                   0x8AE4B0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8AE240
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8AE7B0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5A7390
#define EQItemList__add_object_x                                   0x5D4350
#define EQItemList__add_item_x                                     0x5A78F0
#define EQItemList__delete_item_x                                  0x5A7940
#define EQItemList__FreeItemList_x                                 0x5A7840

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x535CE0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x65B610
#define EQPlayer__dEQPlayer_x                                      0x64E970
#define EQPlayer__DoAttack_x                                       0x663560
#define EQPlayer__EQPlayer_x                                       0x64F030
#define EQPlayer__SetNameSpriteState_x                             0x653300
#define EQPlayer__SetNameSpriteTint_x                              0x6541C0
#define PlayerBase__HasProperty_j_x                                0x9928F0
#define EQPlayer__IsTargetable_x                                   0x992D90
#define EQPlayer__CanSee_x                                         0x992BF0
#define EQPlayer__CanSee1_x                                        0x992CC0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9929B0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x666330
#define PlayerZoneClient__GetLevel_x                               0x6688E0
#define PlayerZoneClient__IsValidTeleport_x                        0x5D54C0
#define PlayerZoneClient__LegalPlayerRace_x                        0x550A60

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x65E470
#define EQPlayerManager__GetSpawnByName_x                          0x65E520
#define EQPlayerManager__GetPlayerFromPartialName_x                0x65E5B0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6221B0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x622230
#define KeypressHandler__AttachKeyToEqCommand_x                    0x622270
#define KeypressHandler__ClearCommandStateArray_x                  0x623680
#define KeypressHandler__HandleKeyDown_x                           0x6236A0
#define KeypressHandler__HandleKeyUp_x                             0x623740
#define KeypressHandler__SaveKeymapping_x                          0x623B90

// MapViewMap 
#define MapViewMap__Clear_x                                        0x77A370
#define MapViewMap__SaveEx_x                                       0x77D730
#define MapViewMap__SetZoom_x                                      0x781DF0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C1C30

// StringTable 
#define StringTable__getString_x                                   0x8BC750

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x649110
#define PcZoneClient__RemovePetEffect_x                            0x649740
#define PcZoneClient__HasAlternateAbility_x                        0x6434C0
#define PcZoneClient__GetCurrentMod_x                              0x4E4E80
#define PcZoneClient__GetModCap_x                                  0x4E4D80
#define PcZoneClient__CanEquipItem_x                               0x643B90
#define PcZoneClient__GetItemByID_x                                0x6466E0
#define PcZoneClient__GetItemByItemClass_x                         0x646830
#define PcZoneClient__RemoveBuffEffect_x                           0x649760
#define PcZoneClient__BandolierSwap_x                              0x6447B0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x646210

//Doors
#define EQSwitch__UseSwitch_x                                      0x5DA030

//IconCache
#define IconCache__GetIcon_x                                       0x71A800

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7122C0
#define CContainerMgr__CloseContainer_x                            0x712590
#define CContainerMgr__OpenExperimentContainer_x                   0x713010

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D2590

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x616CB0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7708F0
#define CLootWnd__RequestLootSlot_x                                0x76FB20

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x574880
#define EQ_Spell__SpellAffects_x                                   0x574CF0
#define EQ_Spell__SpellAffectBase_x                                0x574AB0
#define EQ_Spell__IsStackable_x                                    0x4C9AF0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9940
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B69A0
#define EQ_Spell__IsSPAStacking_x                                  0x575B40
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x575050
#define EQ_Spell__IsNoRemove_x                                     0x4C9AD0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x575B50
#define __IsResEffectSpell_x                                       0x4C8E60

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD0B0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8CC2D0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x819340
#define CTargetWnd__WndNotification_x                              0x818BD0
#define CTargetWnd__RefreshTargetBuffs_x                           0x818EA0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x817D30

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81D950

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x533730
#define CTaskManager__HandleMessage_x                              0x531BB0
#define CTaskManager__GetTaskStatus_x                              0x5337E0
#define CTaskManager__GetElementDescription_x                      0x533860

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x56FD50
#define EqSoundManager__PlayScriptMp3_x                            0x56FEB0
#define EqSoundManager__SoundAssistPlay_x                          0x680EE0
#define EqSoundManager__WaveInstancePlay_x                         0x680450

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x527440

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x94E920

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x55EFD0
#define CAltAbilityData__GetMercMaxRank_x                          0x55EF60
#define CAltAbilityData__GetMaxRank_x                              0x5546F0

//CTargetRing
#define CTargetRing__Cast_x                                        0x614DD0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9920
#define CharacterBase__CreateItemGlobalIndex_x                     0x50E6B0
#define CharacterBase__CreateItemIndex_x                           0x61CEE0
#define CharacterBase__GetItemPossession_x                         0x4FA390
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D48E0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D4940
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F9380
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F9BB0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F9C60

//messages
#define msg_spell_worn_off_x                                       0x599180
#define msg_new_text_x                                             0x58DF20
#define __msgTokenTextParam_x                                      0x59B6B0
#define msgTokenText_x                                             0x59B900

//SpellManager
#define SpellManager__vftable_x                                    0xAE4164
#define SpellManager__SpellManager_x                               0x684210
#define Spellmanager__LoadTextSpells_x                             0x684B00
#define SpellManager__GetSpellByGroupAndRank_x                     0x6843E0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x996870

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x50ED30
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x59F470
#define ItemGlobalIndex__IsEquippedLocation_x                      0x6358B0
#define ItemGlobalIndex__IsValidIndex_x                            0x50ED90

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8CCC70
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8CCEF0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x769160

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7169E0
#define CCursorAttachment__AttachToCursor1_x                       0x716A20
#define CCursorAttachment__Deactivate_x                            0x717A00

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x9415C0
#define CSidlManagerBase__CreatePageWnd_x                          0x940DC0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x93D050
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x93CFE0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x95E650
#define CEQSuiteTextureLoader__GetTexture_x                        0x95E310

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50BC80
#define CFindItemWnd__WndNotification_x                            0x50C760
#define CFindItemWnd__Update_x                                     0x50D2A0
#define CFindItemWnd__PickupSelectedItem_x                         0x50B4C0

//IString
#define IString__Append_x                                          0x4FBB80

//Camera
#define CDisplay__cameraType_x                                     0xDF7020
#define EverQuest__Cameras_x                                       0xEBAA44

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x514400
#define LootFiltersManager__GetItemFilterData_x                    0x513D00
#define LootFiltersManager__RemoveItemLootFilter_x                 0x513D30
#define LootFiltersManager__SetItemLootFilter_x                    0x513F50

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C0510

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x99C390
#define CResolutionHandler__GetWindowedStyle_x                     0x67B9F0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70F020

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E0900
#define CDistillerInfo__Instance_x                                 0x8E08A0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72F350
#define CGroupWnd__UpdateDisplay_x                                 0x72E6A0

//ItemBase
#define ItemBase__IsLore_x                                         0x8A24D0
#define ItemBase__IsLoreEquipped_x                                 0x8A2550

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D42B0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D43F0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D4450

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x670FB0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x674960

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x501FC0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F0AF0
#define FactionManagerClient__HandleFactionMessage_x               0x4F1160
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F1760
#define FactionManagerClient__GetMaxFaction_x                      0x4F177F
#define FactionManagerClient__GetMinFaction_x                      0x4F1730

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FA360

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x925DA0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE70

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FA590

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x55E480

//CTargetManager
#define CTargetManager__Get_x                                      0x687A70

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x670FB0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8DC0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5A77E0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF580D8

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
