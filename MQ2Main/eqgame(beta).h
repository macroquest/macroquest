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
#define __ExpectedVersionDate                                     "Oct 26 2019"
#define __ExpectedVersionTime                                     "04:25:12"
#define __ActualVersionDate_x                                      0xB00DC0
#define __ActualVersionTime_x                                      0xB00DB4
#define __ActualVersionBuild_x                                     0xAECA5C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x6288A0
#define __MemChecker1_x                                            0x8FA3A0
#define __MemChecker2_x                                            0x6B6D80
#define __MemChecker3_x                                            0x6B6CD0
#define __MemChecker4_x                                            0x8521C0
#define __EncryptPad0_x                                            0xC363F0
#define __EncryptPad1_x                                            0xC945B0
#define __EncryptPad2_x                                            0xC46C88
#define __EncryptPad3_x                                            0xC46888
#define __EncryptPad4_x                                            0xC84C08
#define __EncryptPad5_x                                            0xF5DCCC
#define __AC1_x                                                    0x80F056
#define __AC2_x                                                    0x5E28BF
#define __AC3_x                                                    0x5E9FBF
#define __AC4_x                                                    0x5EDF80
#define __AC5_x                                                    0x5F428F
#define __AC6_x                                                    0x5F88A6
#define __AC7_x                                                    0x5E2330
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
#define __do_loot_x                                                0x5AEBA0
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
#define __gfMaxZoomCameraDistance_x                                0xAF66D0
#define __gfMaxCameraDistance_x                                    0xB22C34
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
#define __CastRay_x                                                0x5AA000
#define __CastRay2_x                                               0x5AA050
#define __ConvertItemTags_x                                        0x5C5BA0
#define __CleanItemTags_x                                          0x47CF80
#define __DoesFileExist_x                                          0x8FD4E0
#define __EQGetTime_x                                              0x8F9E70
#define __ExecuteCmd_x                                             0x5A28E0
#define __FixHeading_x                                             0x994E90
#define __GameLoop_x                                               0x6B5F70
#define __get_bearing_x                                            0x5A9B70
#define __get_melee_range_x                                        0x5AA240
#define __GetAnimationCache_x                                      0x71B1C0
#define __GetGaugeValueFromEQ_x                                    0x80D500
#define __GetLabelFromEQ_x                                         0x80EFE0
#define __GetXTargetType_x                                         0x9968E0
#define __HandleMouseWheel_x                                       0x6B6E30
#define __HeadingDiff_x                                            0x994F00
#define __HelpPath_x                                               0xF587A4
#define __LoadFrontEnd_x                                           0x6B3290
#define __NewUIINI_x                                               0x80D1D0
#define __ProcessGameEvents_x                                      0x60A120
#define __ProcessMouseEvent_x                                      0x6098E0
#define __SaveColors_x                                             0x54F160
#define __STMLToText_x                                             0x938690
#define __ToggleKeyRingItem_x                                      0x5123A0
#define CMemoryMappedFile__SetFile_x                               0xA84100
#define CrashDetected_x                                            0x6B4D30
#define DrawNetStatus_x                                            0x635E10
#define Expansion_HoT_x                                            0xEBA6F4
#define Teleport_Table_Size_x                                      0xEABADC
#define Teleport_Table_x                                           0xEA9638
#define Util__FastTime_x                                           0x8F9A40

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4902D0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4991E0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498FB0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493860
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492CB0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x556D20
#define AltAdvManager__IsAbilityReady_x                            0x555C50
#define AltAdvManager__GetAAById_x                                 0x555E50
#define AltAdvManager__CanTrainAbility_x                           0x555EC0
#define AltAdvManager__CanSeeAbility_x                             0x556220

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9FB0
#define CharacterZoneClient__HasSkill_x                            0x4D4EA0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D65C0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE230
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA830
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8F40
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9020
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9100
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3020
#define CharacterZoneClient__BardCastBard_x                        0x4C5B80
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA900
#define CharacterZoneClient__GetEffect_x                           0x4BA770
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4070
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4140
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4190
#define CharacterZoneClient__CalcAffectChange_x                    0x4C42E0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C44B0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B26E0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7520
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6FA0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DC970
#define CBankWnd__WndNotification_x                                0x6DC750

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6EA1C0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x6186A0
#define CButtonWnd__CButtonWnd_x                                   0x934A70

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x70A2B0
#define CChatManager__InitContextMenu_x                            0x703400
#define CChatManager__FreeChatWindow_x                             0x708DF0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8620
#define CChatManager__SetLockedActiveChatWindow_x                  0x709F30
#define CChatManager__CreateChatWindow_x                           0x709430

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8730

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x949000
#define CContextMenu__dCContextMenu_x                              0x949230
#define CContextMenu__AddMenuItem_x                                0x949240
#define CContextMenu__RemoveMenuItem_x                             0x949550
#define CContextMenu__RemoveAllMenuItems_x                         0x949570
#define CContextMenu__CheckMenuItem_x                              0x9495F0
#define CContextMenu__SetMenuItem_x                                0x949470
#define CContextMenu__AddSeparator_x                               0x9493D0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x949B80
#define CContextMenuManager__RemoveMenu_x                          0x949BF0
#define CContextMenuManager__PopupMenu_x                           0x949CB0
#define CContextMenuManager__Flush_x                               0x949B20
#define CContextMenuManager__GetMenu_x                             0x49B370
#define CContextMenuManager__CreateDefaultMenu_x                   0x7159D0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D6880
#define CChatService__GetFriendName_x                              0x8D6890

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x70AB20
#define CChatWindow__Clear_x                                       0x70BDE0
#define CChatWindow__WndNotification_x                             0x70C570
#define CChatWindow__AddHistory_x                                  0x70B6A0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x946460
#define CComboWnd__Draw_x                                          0x945970
#define CComboWnd__GetCurChoice_x                                  0x9462A0
#define CComboWnd__GetListRect_x                                   0x945E10
#define CComboWnd__GetTextRect_x                                   0x9464D0
#define CComboWnd__InsertChoice_x                                  0x945FA0
#define CComboWnd__SetColors_x                                     0x945F70
#define CComboWnd__SetChoice_x                                     0x946270
#define CComboWnd__GetItemCount_x                                  0x9462B0
#define CComboWnd__GetCurChoiceText_x                              0x9462F0
#define CComboWnd__GetChoiceText_x                                 0x9462C0
#define CComboWnd__InsertChoiceAtIndex_x                           0x946030

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7133B0
#define CContainerWnd__vftable_x                                   0xB09FAC
#define CContainerWnd__SetContainer_x                              0x714910

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x549BA0
#define CDisplay__PreZoneMainUI_x                                  0x549BB0
#define CDisplay__CleanGameUI_x                                    0x54EF20
#define CDisplay__GetClickedActor_x                                0x541EC0
#define CDisplay__GetUserDefinedColor_x                            0x53A580
#define CDisplay__GetWorldFilePath_x                               0x543930
#define CDisplay__is3dON_x                                         0x53EB20
#define CDisplay__ReloadUI_x                                       0x549030
#define CDisplay__WriteTextHD2_x                                   0x53E910
#define CDisplay__TrueDistance_x                                   0x5455F0
#define CDisplay__SetViewActor_x                                   0x5417E0
#define CDisplay__GetFloorHeight_x                                 0x53EBE0
#define CDisplay__SetRenderWindow_x                                0x53D540
#define CDisplay__ToggleScreenshotMode_x                           0x5412B0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x968B70

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x94C550
#define CEditWnd__GetCharIndexPt_x                                 0x94D480
#define CEditWnd__GetDisplayString_x                               0x94D320
#define CEditWnd__GetHorzOffset_x                                  0x94BB90
#define CEditWnd__GetLineForPrintableChar_x                        0x94E620
#define CEditWnd__GetSelStartPt_x                                  0x94D730
#define CEditWnd__GetSTMLSafeText_x                                0x94D140
#define CEditWnd__PointFromPrintableChar_x                         0x94E250
#define CEditWnd__SelectableCharFromPoint_x                        0x94E3C0
#define CEditWnd__SetEditable_x                                    0x94D800
#define CEditWnd__SetWindowTextA_x                                 0x94CEC0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5F7D80
#define CEverQuest__ClickedPlayer_x                                0x5E9DA0
#define CEverQuest__CreateTargetIndicator_x                        0x6073B0
#define CEverQuest__DeleteTargetIndicator_x                        0x607440
#define CEverQuest__DoTellWindow_x                                 0x4E8810
#define CEverQuest__OutputTextToLog_x                              0x4E8A90
#define CEverQuest__DropHeldItemOnGround_x                         0x5DEDE0
#define CEverQuest__dsp_chat_x                                     0x4E8E20
#define CEverQuest__trimName_x                                     0x603690
#define CEverQuest__Emote_x                                        0x5F85E0
#define CEverQuest__EnterZone_x                                    0x5F2560
#define CEverQuest__GetBodyTypeDesc_x                              0x5FCF50
#define CEverQuest__GetClassDesc_x                                 0x5FD590
#define CEverQuest__GetClassThreeLetterCode_x                      0x5FDB90
#define CEverQuest__GetDeityDesc_x                                 0x605CF0
#define CEverQuest__GetLangDesc_x                                  0x5FDD50
#define CEverQuest__GetRaceDesc_x                                  0x5FD570
#define CEverQuest__InterpretCmd_x                                 0x6062C0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E2FE0
#define CEverQuest__LMouseUp_x                                     0x5E1370
#define CEverQuest__RightClickedOnPlayer_x                         0x5E38C0
#define CEverQuest__RMouseUp_x                                     0x5E22F0
#define CEverQuest__SetGameState_x                                 0x5DEB70
#define CEverQuest__UPCNotificationFlush_x                         0x603590
#define CEverQuest__IssuePetCommand_x                              0x5FF150
#define CEverQuest__ReportSuccessfulHit_x                          0x5F99D0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x725330
#define CGaugeWnd__CalcLinesFillRect_x                             0x725390
#define CGaugeWnd__Draw_x                                          0x7249B0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF100
#define CGuild__GetGuildName_x                                     0x4AE1E0
#define CGuild__GetGuildIndex_x                                    0x4AE570

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x740760

//CHotButton
#define CHotButton__SetButtonSize_x                                0x618A60

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x74D750
#define CInvSlotMgr__MoveItem_x                                    0x74C470
#define CInvSlotMgr__SelectSlot_x                                  0x74D820

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x74ACF0
#define CInvSlot__SliderComplete_x                                 0x748A50
#define CInvSlot__GetItemBase_x                                    0x7483D0
#define CInvSlot__UpdateItem_x                                     0x748540

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74F270
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74E420
#define CInvSlotWnd__HandleLButtonUp_x                             0x74EDF0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8087F0
#define CItemDisplayWnd__UpdateStrings_x                           0x75D870
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7575E0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x757AF0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x75DE70
#define CItemDisplayWnd__AboutToShow_x                             0x75D4C0
#define CItemDisplayWnd__WndNotification_x                         0x75EF60
#define CItemDisplayWnd__RequestConvertItem_x                      0x75EA20
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x75C520
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x75D2E0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x841280

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x763450

// CLabel 
#define CLabel__Draw_x                                             0x768E20

// CListWnd
#define CListWnd__CListWnd_x                                       0x91EBF0
#define CListWnd__dCListWnd_x                                      0x91EF10
#define CListWnd__AddColumn_x                                      0x923380
#define CListWnd__AddColumn1_x                                     0x9233D0
#define CListWnd__AddLine_x                                        0x923760
#define CListWnd__AddString_x                                      0x923560
#define CListWnd__CalculateFirstVisibleLine_x                      0x923140
#define CListWnd__CalculateVSBRange_x                              0x922F20
#define CListWnd__ClearSel_x                                       0x923F40
#define CListWnd__ClearAllSel_x                                    0x923FA0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x9249C0
#define CListWnd__Compare_x                                        0x922860
#define CListWnd__Draw_x                                           0x91F040
#define CListWnd__DrawColumnSeparators_x                           0x921830
#define CListWnd__DrawHeader_x                                     0x921CA0
#define CListWnd__DrawItem_x                                       0x9221A0
#define CListWnd__DrawLine_x                                       0x9219A0
#define CListWnd__DrawSeparator_x                                  0x9218D0
#define CListWnd__EnableLine_x                                     0x921100
#define CListWnd__EnsureVisible_x                                  0x9248E0
#define CListWnd__ExtendSel_x                                      0x923E70
#define CListWnd__GetColumnTooltip_x                               0x920C40
#define CListWnd__GetColumnMinWidth_x                              0x920CB0
#define CListWnd__GetColumnWidth_x                                 0x920BB0
#define CListWnd__GetCurSel_x                                      0x920540
#define CListWnd__GetItemAtPoint_x                                 0x921380
#define CListWnd__GetItemAtPoint1_x                                0x9213F0
#define CListWnd__GetItemData_x                                    0x9205C0
#define CListWnd__GetItemHeight_x                                  0x920980
#define CListWnd__GetItemIcon_x                                    0x920750
#define CListWnd__GetItemRect_x                                    0x9211F0
#define CListWnd__GetItemText_x                                    0x920600
#define CListWnd__GetSelList_x                                     0x923FF0
#define CListWnd__GetSeparatorRect_x                               0x921630
#define CListWnd__InsertLine_x                                     0x923B50
#define CListWnd__RemoveLine_x                                     0x923CA0
#define CListWnd__SetColors_x                                      0x922F00
#define CListWnd__SetColumnJustification_x                         0x922C30
#define CListWnd__SetColumnWidth_x                                 0x922B50
#define CListWnd__SetCurSel_x                                      0x923DB0
#define CListWnd__SetItemColor_x                                   0x924590
#define CListWnd__SetItemData_x                                    0x924550
#define CListWnd__SetItemText_x                                    0x924160
#define CListWnd__ShiftColumnSeparator_x                           0x922CF0
#define CListWnd__Sort_x                                           0x9229E0
#define CListWnd__ToggleSel_x                                      0x923DE0
#define CListWnd__SetColumnsSizable_x                              0x922DA0
#define CListWnd__SetItemWnd_x                                     0x924410
#define CListWnd__GetItemWnd_x                                     0x9207A0
#define CListWnd__SetItemIcon_x                                    0x9241E0
#define CListWnd__CalculateCustomWindowPositions_x                 0x923240
#define CListWnd__SetVScrollPos_x                                  0x922B30

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77E4A0
#define CMapViewWnd__GetWorldCoordinates_x                         0x77CBB0
#define CMapViewWnd__HandleLButtonDown_x                           0x779BF0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79E3E0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79ECC0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79F1F0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A2160
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x79CF50
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A7D10
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79DFF0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A42D0
#define CPacketScrambler__hton_x                                   0x8A42C0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x93DCE0
#define CSidlManager__FindScreenPieceTemplate_x                    0x93E0F0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x93DEE0
#define CSidlManager__CreateLabel_x                                0x7FFBF0
#define CSidlManager__CreateXWndFromTemplate_x                     0x941050
#define CSidlManager__CreateXWndFromTemplate1_x                    0x941230
#define CSidlManager__CreateXWnd_x                                 0x7FFB20
#define CSidlManager__CreateHotButtonWnd_x                         0x8000F0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x93A7C0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x93A6C0
#define CSidlScreenWnd__ConvertToRes_x                             0x95FB80
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x93A150
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x939E40
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x939F10
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x939FE0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x93AC60
#define CSidlScreenWnd__EnableIniStorage_x                         0x93B130
#define CSidlScreenWnd__GetSidlPiece_x                             0x93AE50
#define CSidlScreenWnd__Init1_x                                    0x939A40
#define CSidlScreenWnd__LoadIniInfo_x                              0x93B180
#define CSidlScreenWnd__LoadIniListWnd_x                           0x93BCC0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x938E40
#define CSidlScreenWnd__StoreIniInfo_x                             0x93B840
#define CSidlScreenWnd__StoreIniVis_x                              0x93BBA0
#define CSidlScreenWnd__WndNotification_x                          0x93AB70
#define CSidlScreenWnd__GetChildItem_x                             0x93B0B0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x92A850
#define CSidlScreenWnd__m_layoutCopy_x                             0x15EEF18

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x67D0C0
#define CSkillMgr__GetSkillCap_x                                   0x67D2A0
#define CSkillMgr__GetNameToken_x                                  0x67C840
#define CSkillMgr__IsActivatedSkill_x                              0x67C980
#define CSkillMgr__IsCombatSkill_x                                 0x67C8C0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x94A960
#define CSliderWnd__SetValue_x                                     0x94A7D0
#define CSliderWnd__SetNumTicks_x                                  0x94A830

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x805C40

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x953180
#define CStmlWnd__CalculateHSBRange_x                              0x954260
#define CStmlWnd__CalculateVSBRange_x                              0x9541D0
#define CStmlWnd__CanBreakAtCharacter_x                            0x9585A0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x959230
#define CStmlWnd__ForceParseNow_x                                  0x953720
#define CStmlWnd__GetNextTagPiece_x                                0x958500
#define CStmlWnd__GetSTMLText_x                                    0x5017A0
#define CStmlWnd__GetVisibleText_x                                 0x953740
#define CStmlWnd__InitializeWindowVariables_x                      0x959080
#define CStmlWnd__MakeStmlColorTag_x                               0x9527F0
#define CStmlWnd__MakeWndNotificationTag_x                         0x952860
#define CStmlWnd__SetSTMLText_x                                    0x9518A0
#define CStmlWnd__StripFirstSTMLLines_x                            0x95A330
#define CStmlWnd__UpdateHistoryString_x                            0x959440

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9509F0
#define CTabWnd__DrawCurrentPage_x                                 0x951120
#define CTabWnd__DrawTab_x                                         0x950E40
#define CTabWnd__GetCurrentPage_x                                  0x9501F0
#define CTabWnd__GetPageInnerRect_x                                0x950430
#define CTabWnd__GetTabInnerRect_x                                 0x950370
#define CTabWnd__GetTabRect_x                                      0x950220
#define CTabWnd__InsertPage_x                                      0x950640
#define CTabWnd__SetPage_x                                         0x9504B0
#define CTabWnd__SetPageRect_x                                     0x950930
#define CTabWnd__UpdatePage_x                                      0x950D00
#define CTabWnd__GetPageFromTabIndex_x                             0x950D80
#define CTabWnd__GetCurrentTabIndex_x                              0x9501E0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x763820
#define CPageWnd__SetTabText_x                                     0x94FD30

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8D80

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x927700
#define CTextureFont__GetTextExtent_x                              0x9278C0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B0130
#define CHtmlComponentWnd__ValidateUri_x                           0x742150
#define CHtmlWnd__SetClientCallbacks_x                             0x61DAD0
#define CHtmlWnd__AddObserver_x                                    0x61DAF0
#define CHtmlWnd__RemoveObserver_x                                 0x61DB50
#define Window__getProgress_x                                      0x859790
#define Window__getStatus_x                                        0x8597B0
#define Window__getURI_x                                           0x8597C0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9655C0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x914840

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8360
#define CXStr__CXStr1_x                                            0x481480
#define CXStr__CXStr3_x                                            0x8F5F70
#define CXStr__dCXStr_x                                            0x478670
#define CXStr__operator_equal_x                                    0x8F61A0
#define CXStr__operator_equal1_x                                   0x8F61E0
#define CXStr__operator_plus_equal1_x                              0x8F6C70
#define CXStr__SetString_x                                         0x8F8B60
#define CXStr__operator_char_p_x                                   0x8F66B0
#define CXStr__GetChar_x                                           0x8F84B0
#define CXStr__Delete_x                                            0x8F7D60
#define CXStr__GetUnicode_x                                        0x8F8520
#define CXStr__GetLength_x                                         0x4A8B30
#define CXStr__Mid_x                                               0x47D330
#define CXStr__Insert_x                                            0x8F8580
#define CXStr__FindNext_x                                          0x8F81D0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x948C20
#define CXWnd__BringToTop_x                                        0x92DF70
#define CXWnd__Center_x                                            0x92DAF0
#define CXWnd__ClrFocus_x                                          0x92D910
#define CXWnd__Destroy_x                                           0x92D9B0
#define CXWnd__DoAllDrawing_x                                      0x92A010
#define CXWnd__DrawChildren_x                                      0x929FE0
#define CXWnd__DrawColoredRect_x                                   0x92A460
#define CXWnd__DrawTooltip_x                                       0x928B40
#define CXWnd__DrawTooltipAtPoint_x                                0x928C00
#define CXWnd__GetBorderFrame_x                                    0x92A2C0
#define CXWnd__GetChildWndAt_x                                     0x92E010
#define CXWnd__GetClientClipRect_x                                 0x92C250
#define CXWnd__GetScreenClipRect_x                                 0x92C320
#define CXWnd__GetScreenRect_x                                     0x92C4A0
#define CXWnd__GetTooltipRect_x                                    0x92A4B0
#define CXWnd__GetWindowTextA_x                                    0x49CAE0
#define CXWnd__IsActive_x                                          0x92ABD0
#define CXWnd__IsDescendantOf_x                                    0x92CE70
#define CXWnd__IsReallyVisible_x                                   0x92CEA0
#define CXWnd__IsType_x                                            0x92E670
#define CXWnd__Move_x                                              0x92CF20
#define CXWnd__Move1_x                                             0x92CFD0
#define CXWnd__ProcessTransition_x                                 0x92DAA0
#define CXWnd__Refade_x                                            0x92D2A0
#define CXWnd__Resize_x                                            0x92D530
#define CXWnd__Right_x                                             0x92DD30
#define CXWnd__SetFocus_x                                          0x92D8D0
#define CXWnd__SetFont_x                                           0x92D940
#define CXWnd__SetKeyTooltip_x                                     0x92E480
#define CXWnd__SetMouseOver_x                                      0x92B3D0
#define CXWnd__StartFade_x                                         0x92CD60
#define CXWnd__GetChildItem_x                                      0x92E180
#define CXWnd__SetParent_x                                         0x92CC50
#define CXWnd__Minimize_x                                          0x92D5A0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x960C00

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x930F10
#define CXWndManager__DrawWindows_x                                0x930F30
#define CXWndManager__GetKeyboardFlags_x                           0x933610
#define CXWndManager__HandleKeyboardMsg_x                          0x9331C0
#define CXWndManager__RemoveWnd_x                                  0x933850
#define CXWndManager__RemovePendingDeletionWnd_x                   0x933D90

// CDBStr
#define CDBStr__GetString_x                                        0x539510

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB810
#define EQ_Character__Cur_HP_x                                     0x4D1EE0
#define EQ_Character__Cur_Mana_x                                   0x4D9600
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE880
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2320
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2470
#define EQ_Character__GetHPRegen_x                                 0x4DF3A0
#define EQ_Character__GetEnduranceRegen_x                          0x4DF9A0
#define EQ_Character__GetManaRegen_x                               0x4DFDE0
#define EQ_Character__Max_Endurance_x                              0x643C40
#define EQ_Character__Max_HP_x                                     0x4D1D10
#define EQ_Character__Max_Mana_x                                   0x643A40
#define EQ_Character__doCombatAbility_x                            0x646090
#define EQ_Character__UseSkill_x                                   0x4E1BB0
#define EQ_Character__GetConLevel_x                                0x63CE00
#define EQ_Character__IsExpansionFlag_x                            0x5A10C0
#define EQ_Character__TotalEffect_x                                0x4C52C0
#define EQ_Character__GetPCSpellAffect_x                           0x4BF5D0
#define EQ_Character__SpellDuration_x                              0x4BF100
#define EQ_Character__GetAdjustedSkill_x                           0x4D4C60
#define EQ_Character__GetBaseSkill_x                               0x4D5C00
#define EQ_Character__CanUseItem_x                                 0x4D9910

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C3650

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x65A1D0

//PcClient
#define PcClient__PcClient_x                                       0x63A530

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9460
#define CCharacterListWnd__EnterWorld_x                            0x4B8EA0
#define CCharacterListWnd__Quit_x                                  0x4B8BF0
#define CCharacterListWnd__UpdateList_x                            0x4B9030

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x61ED00
#define EQ_Item__CreateItemTagString_x                             0x89DB10
#define EQ_Item__IsStackable_x                                     0x8A26B0
#define EQ_Item__GetImageNum_x                                     0x89F570
#define EQ_Item__CreateItemClient_x                                0x61DED0
#define EQ_Item__GetItemValue_x                                    0x8A08B0
#define EQ_Item__ValueSellMerchant_x                               0x8A3EB0
#define EQ_Item__IsKeyRingItem_x                                   0x8A1FE0
#define EQ_Item__CanGoInBag_x                                      0x61EE20
#define EQ_Item__IsEmpty_x                                         0x8A1B20
#define EQ_Item__GetMaxItemCount_x                                 0x8A0CC0
#define EQ_Item__GetHeldItem_x                                     0x89F440
#define EQ_Item__GetAugmentFitBySlot_x                             0x89D490

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x557A30
#define EQ_LoadingS__Array_x                                       0xC1DB60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6445A0
#define EQ_PC__GetAlternateAbilityId_x                             0x8AD0D0
#define EQ_PC__GetCombatAbility_x                                  0x8AD740
#define EQ_PC__GetCombatAbilityTimer_x                             0x8AD7B0
#define EQ_PC__GetItemRecastTimer_x                                0x646610
#define EQ_PC__HasLoreItem_x                                       0x63D5C0
#define EQ_PC__AlertInventoryChanged_x                             0x63C730
#define EQ_PC__GetPcZoneClient_x                                   0x668C30
#define EQ_PC__RemoveMyAffect_x                                    0x649840
#define EQ_PC__GetKeyRingItems_x                                   0x8AE040
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8ADDD0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8AE340

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5A75F0
#define EQItemList__add_object_x                                   0x5D4620
#define EQItemList__add_item_x                                     0x5A7B50
#define EQItemList__delete_item_x                                  0x5A7BA0
#define EQItemList__FreeItemList_x                                 0x5A7AA0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x535FE0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x65BA50
#define EQPlayer__dEQPlayer_x                                      0x64ED70
#define EQPlayer__DoAttack_x                                       0x663900
#define EQPlayer__EQPlayer_x                                       0x64F430
#define EQPlayer__SetNameSpriteState_x                             0x653740
#define EQPlayer__SetNameSpriteTint_x                              0x654600
#define PlayerBase__HasProperty_j_x                                0x993270
#define EQPlayer__IsTargetable_x                                   0x993710
#define EQPlayer__CanSee_x                                         0x993570
#define EQPlayer__CanSee1_x                                        0x993640
#define PlayerBase__GetVisibilityLineSegment_x                     0x993330

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6666D0
#define PlayerZoneClient__GetLevel_x                               0x668C70
#define PlayerZoneClient__IsValidTeleport_x                        0x5D5790
#define PlayerZoneClient__LegalPlayerRace_x                        0x550DE0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x65E810
#define EQPlayerManager__GetSpawnByName_x                          0x65E8C0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x65E950

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6223C0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x622440
#define KeypressHandler__AttachKeyToEqCommand_x                    0x622480
#define KeypressHandler__ClearCommandStateArray_x                  0x623890
#define KeypressHandler__HandleKeyDown_x                           0x6238B0
#define KeypressHandler__HandleKeyUp_x                             0x623950
#define KeypressHandler__SaveKeymapping_x                          0x623DA0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x77A310
#define MapViewMap__SaveEx_x                                       0x77D6D0
#define MapViewMap__SetZoom_x                                      0x781D90

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C1570

// StringTable 
#define StringTable__getString_x                                   0x8BC220

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6494B0
#define PcZoneClient__RemovePetEffect_x                            0x649AE0
#define PcZoneClient__HasAlternateAbility_x                        0x643870
#define PcZoneClient__GetCurrentMod_x                              0x4E4C60
#define PcZoneClient__GetModCap_x                                  0x4E4B60
#define PcZoneClient__CanEquipItem_x                               0x643F40
#define PcZoneClient__GetItemByID_x                                0x646A80
#define PcZoneClient__GetItemByItemClass_x                         0x646BD0
#define PcZoneClient__RemoveBuffEffect_x                           0x649B00
#define PcZoneClient__BandolierSwap_x                              0x644B50
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x6465B0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5DA240

//IconCache
#define IconCache__GetIcon_x                                       0x71AA60

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7124A0
#define CContainerMgr__CloseContainer_x                            0x712770
#define CContainerMgr__OpenExperimentContainer_x                   0x7131F0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D2290

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x616E90

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7708F0
#define CLootWnd__RequestLootSlot_x                                0x76FB20

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5749F0
#define EQ_Spell__SpellAffects_x                                   0x574E60
#define EQ_Spell__SpellAffectBase_x                                0x574C20
#define EQ_Spell__IsStackable_x                                    0x4C98E0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9760
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B67F0
#define EQ_Spell__IsSPAStacking_x                                  0x575CB0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5751C0
#define EQ_Spell__IsNoRemove_x                                     0x4C98C0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x575CC0
#define __IsResEffectSpell_x                                       0x4C8D00

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACDB0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8CBCA0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x818FB0
#define CTargetWnd__WndNotification_x                              0x818840
#define CTargetWnd__RefreshTargetBuffs_x                           0x818B10
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8179A0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81D5A0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x533A00
#define CTaskManager__HandleMessage_x                              0x531EB0
#define CTaskManager__GetTaskStatus_x                              0x533AB0
#define CTaskManager__GetElementDescription_x                      0x533B30

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x56FF40
#define EqSoundManager__PlayScriptMp3_x                            0x5700A0
#define EqSoundManager__SoundAssistPlay_x                          0x681030
#define EqSoundManager__WaveInstancePlay_x                         0x6805A0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x527720

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x94F240

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x55F4B0
#define CAltAbilityData__GetMercMaxRank_x                          0x55F440
#define CAltAbilityData__GetMaxRank_x                              0x554AD0

//CTargetRing
#define CTargetRing__Cast_x                                        0x614FB0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9740
#define CharacterBase__CreateItemGlobalIndex_x                     0x50EA00
#define CharacterBase__CreateItemIndex_x                           0x61D080
#define CharacterBase__GetItemPossession_x                         0x4FA040
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D4280
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D42E0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F9690
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F9EC0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F9F70

//messages
#define msg_spell_worn_off_x                                       0x599290
#define msg_new_text_x                                             0x58E040
#define __msgTokenTextParam_x                                      0x59B7C0
#define msgTokenText_x                                             0x59BA10

//SpellManager
#define SpellManager__vftable_x                                    0xAE4164
#define SpellManager__SpellManager_x                               0x684360
#define Spellmanager__LoadTextSpells_x                             0x684C50
#define SpellManager__GetSpellByGroupAndRank_x                     0x684530

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9971D0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x50F080
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x59F5A0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x635C70
#define ItemGlobalIndex__IsValidIndex_x                            0x50F0E0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8CC640
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8CC8C0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x769160

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x716C70
#define CCursorAttachment__AttachToCursor1_x                       0x716CB0
#define CCursorAttachment__Deactivate_x                            0x717CA0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x942090
#define CSidlManagerBase__CreatePageWnd_x                          0x941880
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x93DB00
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x93DA90

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x95F160
#define CEQSuiteTextureLoader__GetTexture_x                        0x95EE20

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50BF40
#define CFindItemWnd__WndNotification_x                            0x50CA20
#define CFindItemWnd__Update_x                                     0x50D590
#define CFindItemWnd__PickupSelectedItem_x                         0x50B790

//IString
#define IString__Append_x                                          0x4FB910

//Camera
#define CDisplay__cameraType_x                                     0xDF7020
#define EverQuest__Cameras_x                                       0xEBAA44

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x514740
#define LootFiltersManager__GetItemFilterData_x                    0x514040
#define LootFiltersManager__RemoveItemLootFilter_x                 0x514070
#define LootFiltersManager__SetItemLootFilter_x                    0x514290

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C02B0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x99CDC0
#define CResolutionHandler__GetWindowedStyle_x                     0x67BAC0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70F290

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E0330
#define CDistillerInfo__Instance_x                                 0x8E02D0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72F510
#define CGroupWnd__UpdateDisplay_x                                 0x72E870

//ItemBase
#define ItemBase__IsLore_x                                         0x8A2080
#define ItemBase__IsLoreEquipped_x                                 0x8A20F0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D4580
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D46C0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D4720

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x671320
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x674CB0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x5022A0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F0A00
#define FactionManagerClient__HandleFactionMessage_x               0x4F1070
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F1630
#define FactionManagerClient__GetMaxFaction_x                      0x4F164F
#define FactionManagerClient__GetMinFaction_x                      0x4F1600

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FA010

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x9266B0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BDF0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FA320

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x55E970

//CTargetManager
#define CTargetManager__Get_x                                      0x687BF0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x671320

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8B40

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5A7A40

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF580D8

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
