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
#define __ExpectedVersionDate                                     "Nov 23 2019"
#define __ExpectedVersionTime                                     "04:25:15"
#define __ActualVersionDate_x                                      0xB0A2A8
#define __ActualVersionTime_x                                      0xB0A29C
#define __ActualVersionBuild_x                                     0xAF5F7C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62EA30
#define __MemChecker1_x                                            0x9023A0
#define __MemChecker2_x                                            0x6BD3E0
#define __MemChecker3_x                                            0x6BD330
#define __MemChecker4_x                                            0x859360
#define __EncryptPad0_x                                            0xC403E8
#define __EncryptPad1_x                                            0xC9E5E8
#define __EncryptPad2_x                                            0xC50C80
#define __EncryptPad3_x                                            0xC50880
#define __EncryptPad4_x                                            0xC8EC00
#define __EncryptPad5_x                                            0xF6A1C0
#define __AC1_x                                                    0x815EE6
#define __AC2_x                                                    0x5E894F
#define __AC3_x                                                    0x5F004F
#define __AC4_x                                                    0x5F4020
#define __AC5_x                                                    0x5FA32F
#define __AC6_x                                                    0x5FE946
#define __AC7_x                                                    0x5E83C0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x193A2C

// Direct Input
#define DI8__Main_x                                                0xF6A1E8
#define DI8__Keyboard_x                                            0xF6A1EC
#define DI8__Mouse_x                                               0xF6A1CC
#define DI8__Mouse_Copy_x                                          0xEC33CC
#define DI8__Mouse_Check_x                                         0xF67D14
#define __AutoSkillArray_x                                         0xEC42E4
#define __Attack_x                                                 0xF6210B
#define __Autofire_x                                               0xF6210C
#define __BindList_x                                               0xC2EE20
#define g_eqCommandStates_x                                        0xC2FBA0
#define __Clicks_x                                                 0xEC3484
#define __CommandList_x                                            0xC30760
#define __CurrentMapLabel_x                                        0xF7AB8C
#define __CurrentSocial_x                                          0xC187CC
#define __DoAbilityList_x                                          0xEF9C2C
#define __do_loot_x                                                0x5B4310
#define __DrawHandler_x                                            0x15F9F00
#define __GroupCount_x                                             0xEB5D82
#define __Guilds_x                                                 0xEB9BD8
#define __gWorld_x                                                 0xEB5BD0
#define __HWnd_x                                                   0xF6A1D0
#define __heqmain_x                                                0xF6A1A8
#define __InChatMode_x                                             0xEC33B4
#define __LastTell_x                                               0xEC5328
#define __LMouseHeldTime_x                                         0xEC34F0
#define __Mouse_x                                                  0xF6A1D4
#define __MouseLook_x                                              0xEC344A
#define __MouseEventTime_x                                         0xF62BEC
#define __gpbCommandEvent_x                                        0xEB3670
#define __NetStatusToggle_x                                        0xEC344D
#define __PCNames_x                                                0xEC48D4
#define __RangeAttackReady_x                                       0xEC45C8
#define __RMouseHeldTime_x                                         0xEC34EC
#define __RunWalkState_x                                           0xEC33B8
#define __ScreenMode_x                                             0xE01014
#define __ScreenX_x                                                0xEC336C
#define __ScreenY_x                                                0xEC3368
#define __ScreenXMax_x                                             0xEC3370
#define __ScreenYMax_x                                             0xEC3374
#define __ServerHost_x                                             0xEB38A3
#define __ServerName_x                                             0xEF9BEC
#define __ShiftKeyDown_x                                           0xEC3A44
#define __ShowNames_x                                              0xEC4784
#define __Socials_x                                                0xEF9CEC
#define __SubscriptionType_x                                       0xFBF090
#define __TargetAggroHolder_x                                      0xF7D540
#define __ZoneType_x                                               0xEC3848
#define __GroupAggro_x                                             0xF7D580
#define __LoginName_x                                              0xF6A93C
#define __Inviter_x                                                0xF62088
#define __AttackOnAssist_x                                         0xEC4740
#define __UseTellWindows_x                                         0xEC4A70
#define __gfMaxZoomCameraDistance_x                                0xAFFC10
#define __gfMaxCameraDistance_x                                    0xB2C14C
#define __pulAutoRun_x                                             0xEC3468
#define __pulForward_x                                             0xEC4AA8
#define __pulBackward_x                                            0xEC4AAC
#define __pulTurnRight_x                                           0xEC4AB0
#define __pulTurnLeft_x                                            0xEC4AB4
#define __pulStrafeLeft_x                                          0xEC4AB8
#define __pulStrafeRight_x                                         0xEC4ABC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB5F78
#define instEQZoneInfo_x                                           0xEC3640
#define pinstActiveBanker_x                                        0xEB3688
#define pinstActiveCorpse_x                                        0xEB3680
#define pinstActiveGMaster_x                                       0xEB3684
#define pinstActiveMerchant_x                                      0xEB367C
#define pinstAltAdvManager_x                                       0xE021A8
#define pinstBandageTarget_x                                       0xEB3698
#define pinstCamActor_x                                            0xE01008
#define pinstCDBStr_x                                              0xE00EC4
#define pinstCDisplay_x                                            0xEB5BCC
#define pinstCEverQuest_x                                          0xF6A200
#define pinstEverQuestInfo_x                                       0xEC3360
#define pinstCharData_x                                            0xEB5D64
#define pinstCharSpawn_x                                           0xEB36D0
#define pinstControlledMissile_x                                   0xEB3BBC
#define pinstControlledPlayer_x                                    0xEB36D0
#define pinstCResolutionHandler_x                                  0x15FA130
#define pinstCSidlManager_x                                        0x15F90C8
#define pinstCXWndManager_x                                        0x15F90C4
#define instDynamicZone_x                                          0xEB9AB0
#define pinstDZMember_x                                            0xEB9BC0
#define pinstDZTimerInfo_x                                         0xEB9BC4
#define pinstEqLogin_x                                             0xF6A288
#define instEQMisc_x                                               0xE00E08
#define pinstEQSoundManager_x                                      0xE03178
#define pinstEQSpellStrings_x                                      0xCC3878
#define instExpeditionLeader_x                                     0xEB9AFA
#define instExpeditionName_x                                       0xEB9B3A
#define pinstGroup_x                                               0xEB5D7E
#define pinstImeManager_x                                          0x15F90C0
#define pinstLocalPlayer_x                                         0xEB3678
#define pinstMercenaryData_x                                       0xF646DC
#define pinstMercenaryStats_x                                      0xF7D68C
#define pinstModelPlayer_x                                         0xEB3690
#define pinstPCData_x                                              0xEB5D64
#define pinstSkillMgr_x                                            0xF66848
#define pinstSpawnManager_x                                        0xF652F0
#define pinstSpellManager_x                                        0xF66A68
#define pinstSpellSets_x                                           0xF5AD34
#define pinstStringTable_x                                         0xEB5D68
#define pinstSwitchManager_x                                       0xEB3518
#define pinstTarget_x                                              0xEB36CC
#define pinstTargetObject_x                                        0xEB3758
#define pinstTargetSwitch_x                                        0xEB3BC4
#define pinstTaskMember_x                                          0xE00C98
#define pinstTrackTarget_x                                         0xEB36D4
#define pinstTradeTarget_x                                         0xEB368C
#define instTributeActive_x                                        0xE00E29
#define pinstViewActor_x                                           0xE01004
#define pinstWorldData_x                                           0xEB3BB8
#define pinstZoneAddr_x                                            0xEC38E0
#define pinstPlayerPath_x                                          0xF65388
#define pinstTargetIndicator_x                                     0xF66CD0
#define EQObject_Top_x                                             0xEB3674
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE01790
#define pinstCAchievementsWnd_x                                    0xE0178C
#define pinstCActionsWnd_x                                         0xE012DC
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE00FC0
#define pinstCAdvancedLootWnd_x                                    0xE00F84
#define pinstCAdventureLeaderboardWnd_x                            0xF74360
#define pinstCAdventureRequestWnd_x                                0xF74410
#define pinstCAdventureStatsWnd_x                                  0xF744C0
#define pinstCAggroMeterWnd_x                                      0xE01044
#define pinstCAlarmWnd_x                                           0xE017EC
#define pinstCAlertHistoryWnd_x                                    0xE00FDC
#define pinstCAlertStackWnd_x                                      0xE017F4
#define pinstCAlertWnd_x                                           0xE00F64
#define pinstCAltStorageWnd_x                                      0xF74820
#define pinstCAudioTriggersWindow_x                                0xCB5BA8
#define pinstCAuraWnd_x                                            0xE00FFC
#define pinstCAvaZoneWnd_x                                         0xE01050
#define pinstCBandolierWnd_x                                       0xE0103C
#define pinstCBankWnd_x                                            0xE00FF8
#define pinstCBarterMerchantWnd_x                                  0xF75A60
#define pinstCBarterSearchWnd_x                                    0xF75B10
#define pinstCBarterWnd_x                                          0xF75BC0
#define pinstCBazaarConfirmationWnd_x                              0xE017B8
#define pinstCBazaarSearchWnd_x                                    0xE01090
#define pinstCBazaarWnd_x                                          0xE017D4
#define pinstCBlockedBuffWnd_x                                     0xE01000
#define pinstCBlockedPetBuffWnd_x                                  0xE01038
#define pinstCBodyTintWnd_x                                        0xE012EC
#define pinstCBookWnd_x                                            0xE01068
#define pinstCBreathWnd_x                                          0xE017A8
#define pinstCBuffWindowNORMAL_x                                   0xE00FE0
#define pinstCBuffWindowSHORT_x                                    0xE00FE4
#define pinstCBugReportWnd_x                                       0xE00FF0
#define pinstCButtonWnd_x                                          0x15F9330
#define pinstCCastingWnd_x                                         0xE0105C
#define pinstCCastSpellWnd_x                                       0xE017A4
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE017D8
#define pinstCChatWindowManager_x                                  0xF76680
#define pinstCClaimWnd_x                                           0xF767D8
#define pinstCColorPickerWnd_x                                     0xE012E4
#define pinstCCombatAbilityWnd_x                                   0xE017E4
#define pinstCCombatSkillsSelectWnd_x                              0xE00F6C
#define pinstCCompassWnd_x                                         0xE012E0
#define pinstCConfirmationDialog_x                                 0xF7B6D8
#define pinstCContainerMgr_x                                       0xE017CC
#define pinstCContextMenuManager_x                                 0x15F9080
#define pinstCCursorAttachment_x                                   0xE0104C
#define pinstCDynamicZoneWnd_x                                     0xF76DA0
#define pinstCEditLabelWnd_x                                       0xE00FD8
#define pinstCEQMainWnd_x                                          0xF76FE8
#define pinstCEventCalendarWnd_x                                   0xE01054
#define pinstCExtendedTargetWnd_x                                  0xE0102C
#define pinstCFacePick_x                                           0xE00F7C
#define pinstCFactionWnd_x                                         0xE017C8
#define pinstCFellowshipWnd_x                                      0xF771E8
#define pinstCFileSelectionWnd_x                                   0xE01058
#define pinstCFindItemWnd_x                                        0xE017B4
#define pinstCFindLocationWnd_x                                    0xF77340
#define pinstCFriendsWnd_x                                         0xE00F80
#define pinstCGemsGameWnd_x                                        0xE017C4
#define pinstCGiveWnd_x                                            0xE017F0
#define pinstCGroupSearchFiltersWnd_x                              0xE01060
#define pinstCGroupSearchWnd_x                                     0xF77738
#define pinstCGroupWnd_x                                           0xF777E8
#define pinstCGuildBankWnd_x                                       0xEC4724
#define pinstCGuildCreationWnd_x                                   0xF77948
#define pinstCGuildMgmtWnd_x                                       0xF779F8
#define pinstCharacterCreation_x                                   0xE00F74
#define pinstCHelpWnd_x                                            0xE00FB8
#define pinstCHeritageSelectionWnd_x                               0xE00F88
#define pinstCHotButtonWnd_x                                       0xF79B50
#define pinstCHotButtonWnd1_x                                      0xF79B50
#define pinstCHotButtonWnd2_x                                      0xF79B54
#define pinstCHotButtonWnd3_x                                      0xF79B58
#define pinstCHotButtonWnd4_x                                      0xF79B5C
#define pinstCIconSelectionWnd_x                                   0xE01048
#define pinstCInspectWnd_x                                         0xE00FB4
#define pinstCInventoryWnd_x                                       0xE00F8C
#define pinstCInvSlotMgr_x                                         0xE01788
#define pinstCItemDisplayManager_x                                 0xF7A0E0
#define pinstCItemExpTransferWnd_x                                 0xF7A210
#define pinstCItemOverflowWnd_x                                    0xE01098
#define pinstCJournalCatWnd_x                                      0xE0106C
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE01030
#define pinstCKeyRingWnd_x                                         0xE00FD4
#define pinstCLargeDialogWnd_x                                     0xF7C358
#define pinstCLayoutCopyWnd_x                                      0xF7A560
#define pinstCLFGuildWnd_x                                         0xF7A610
#define pinstCLoadskinWnd_x                                        0xE017D0
#define pinstCLootFiltersCopyWnd_x                                 0xCD21A0
#define pinstCLootFiltersWnd_x                                     0xE017F8
#define pinstCLootSettingsWnd_x                                    0xE00F78
#define pinstCLootWnd_x                                            0xE01070
#define pinstCMailAddressBookWnd_x                                 0xE01798
#define pinstCMailCompositionWnd_x                                 0xE0130C
#define pinstCMailIgnoreListWnd_x                                  0xE0179C
#define pinstCMailWnd_x                                            0xE012D8
#define pinstCManageLootWnd_x                                      0xE02658
#define pinstCMapToolbarWnd_x                                      0xE00FBC
#define pinstCMapViewWnd_x                                         0xE00F98
#define pinstCMarketplaceWnd_x                                     0xE00F60
#define pinstCMerchantWnd_x                                        0xE01074
#define pinstCMIZoneSelectWnd_x                                    0xF7AE48
#define pinstCMusicPlayerWnd_x                                     0xE0107C
#define pinstCNameChangeMercWnd_x                                  0xE017B0
#define pinstCNameChangePetWnd_x                                   0xE01794
#define pinstCNameChangeWnd_x                                      0xE017C0
#define pinstCNoteWnd_x                                            0xE00F9C
#define pinstCObjectPreviewWnd_x                                   0xE00F70
#define pinstCOptionsWnd_x                                         0xE00FA4
#define pinstCPetInfoWnd_x                                         0xE010A0
#define pinstCPetitionQWnd_x                                       0xE0137C
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE012F0
#define pinstCPlayerWnd_x                                          0xE010A4
#define pinstCPopupWndManager_x                                    0xF7B6D8
#define pinstCProgressionSelectionWnd_x                            0xF7B788
#define pinstCPurchaseGroupWnd_x                                   0xE00FA8
#define pinstCPurchaseWnd_x                                        0xE00F90
#define pinstCPvPLeaderboardWnd_x                                  0xF7B838
#define pinstCPvPStatsWnd_x                                        0xF7B8E8
#define pinstCQuantityWnd_x                                        0xE01034
#define pinstCRaceChangeWnd_x                                      0xE017E8
#define pinstCRaidOptionsWnd_x                                     0xE01064
#define pinstCRaidWnd_x                                            0xE01378
#define pinstCRealEstateItemsWnd_x                                 0xE01784
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE01078
#define pinstCRealEstateManageWnd_x                                0xE00FB0
#define pinstCRealEstateNeighborhoodWnd_x                          0xE00FD0
#define pinstCRealEstatePlotSearchWnd_x                            0xE00FF4
#define pinstCRealEstatePurchaseWnd_x                              0xE01028
#define pinstCRespawnWnd_x                                         0xE01024
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE017A0
#define pinstCSendMoneyWnd_x                                       0xE00F68
#define pinstCServerListWnd_x                                      0xE01040
#define pinstCSkillsSelectWnd_x                                    0xE017DC
#define pinstCSkillsWnd_x                                          0xE017BC
#define pinstCSocialEditWnd_x                                      0xE00FCC
#define pinstCSocialWnd_x                                          0xE017AC
#define pinstCSpellBookWnd_x                                       0xE017E0
#define pinstCStoryWnd_x                                           0xE010B0
#define pinstCTargetOfTargetWnd_x                                  0xF7D710
#define pinstCTargetWnd_x                                          0xE01020
#define pinstCTaskOverlayWnd_x                                     0xE00FA0
#define pinstCTaskSelectWnd_x                                      0xF7D868
#define pinstCTaskManager_x                                        0xCD2AE0
#define pinstCTaskTemplateSelectWnd_x                              0xF7D918
#define pinstCTaskWnd_x                                            0xF7D9C8
#define pinstCTextEntryWnd_x                                       0xE00FE8
#define pinstCTimeLeftWnd_x                                        0xE010D4
#define pinstCTipWndCONTEXT_x                                      0xF7DBCC
#define pinstCTipWndOFDAY_x                                        0xF7DBC8
#define pinstCTitleWnd_x                                           0xF7DC78
#define pinstCTrackingWnd_x                                        0xE00F94
#define pinstCTradeskillWnd_x                                      0xF7DDE0
#define pinstCTradeWnd_x                                           0xE012FC
#define pinstCTrainWnd_x                                           0xE012F4
#define pinstCTributeBenefitWnd_x                                  0xF7DFE0
#define pinstCTributeMasterWnd_x                                   0xF7E090
#define pinstCTributeTrophyWnd_x                                   0xF7E140
#define pinstCVideoModesWnd_x                                      0xE010BC
#define pinstCVoiceMacroWnd_x                                      0xF67438
#define pinstCVoteResultsWnd_x                                     0xE01374
#define pinstCVoteWnd_x                                            0xE012E8
#define pinstCWebManager_x                                         0xF67AB4
#define pinstCZoneGuideWnd_x                                       0xE00FAC
#define pinstCZonePathWnd_x                                        0xE00FC4

#define pinstEQSuiteTextureLoader_x                                0xCA00C0
#define pinstItemIconCache_x                                       0xF76FA0
#define pinstLootFiltersManager_x                                  0xCD2250
#define pinstRewardSelectionWnd_x                                  0xF7C030

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5AF770
#define __CastRay2_x                                               0x5AF7C0
#define __ConvertItemTags_x                                        0x5CB320
#define __CleanItemTags_x                                          0x47D0C0
#define __DoesFileExist_x                                          0x905530
#define __EQGetTime_x                                              0x901E70
#define __ExecuteCmd_x                                             0x5A7FC0
#define __FixHeading_x                                             0x99CCF0
#define __GameLoop_x                                               0x6BC5D0
#define __get_bearing_x                                            0x5AF2E0
#define __get_melee_range_x                                        0x5AF9B0
#define __GetAnimationCache_x                                      0x7217D0
#define __GetGaugeValueFromEQ_x                                    0x814390
#define __GetLabelFromEQ_x                                         0x815E70
#define __GetXTargetType_x                                         0x99E6F0
#define __HandleMouseWheel_x                                       0x6BD490
#define __HeadingDiff_x                                            0x99CD60
#define __HelpPath_x                                               0xF627DC
#define __LoadFrontEnd_x                                           0x6B98F0
#define __NewUIINI_x                                               0x814060
#define __ProcessGameEvents_x                                      0x6101C0
#define __ProcessMouseEvent_x                                      0x60F980
#define __SaveColors_x                                             0x551D40
#define __STMLToText_x                                             0x9402A0
#define __ToggleKeyRingItem_x                                      0x515510
#define CMemoryMappedFile__SetFile_x                               0xA8BF50
#define CrashDetected_x                                            0x6BB390
#define DrawNetStatus_x                                            0x63BF20
#define Expansion_HoT_x                                            0xEC472C
#define Teleport_Table_Size_x                                      0xEB3760
#define Teleport_Table_x                                           0xEB3BC8
#define Util__FastTime_x                                           0x901A40

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4904F0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499400
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4991D0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A90
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492EE0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5598D0
#define AltAdvManager__IsAbilityReady_x                            0x558800
#define AltAdvManager__GetAAById_x                                 0x558A00
#define AltAdvManager__CanTrainAbility_x                           0x558A70
#define AltAdvManager__CanSeeAbility_x                             0x558DD0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA1C0
#define CharacterZoneClient__HasSkill_x                            0x4D50B0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D67D0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE3A0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA9A0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9150
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9230
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9310
#define CharacterZoneClient__FindAffectSlot_x                      0x4C31A0
#define CharacterZoneClient__BardCastBard_x                        0x4C5D00
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAA70
#define CharacterZoneClient__GetEffect_x                           0x4BA8E0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C41F0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C42C0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4310
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4460
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4630
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2840
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7730
#define CharacterZoneClient__FindItemByRecord_x                    0x4D71B0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E2FD0
#define CBankWnd__WndNotification_x                                0x6E2DB0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F05B0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61E920
#define CButtonWnd__CButtonWnd_x                                   0x93C670

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x7108C0
#define CChatManager__InitContextMenu_x                            0x709A20
#define CChatManager__FreeChatWindow_x                             0x70F400
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E86D0
#define CChatManager__SetLockedActiveChatWindow_x                  0x710540
#define CChatManager__CreateChatWindow_x                           0x70FA40

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E87E0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x950C70
#define CContextMenu__dCContextMenu_x                              0x950EA0
#define CContextMenu__AddMenuItem_x                                0x950EB0
#define CContextMenu__RemoveMenuItem_x                             0x9511C0
#define CContextMenu__RemoveAllMenuItems_x                         0x9511E0
#define CContextMenu__CheckMenuItem_x                              0x951260
#define CContextMenu__SetMenuItem_x                                0x9510E0
#define CContextMenu__AddSeparator_x                               0x951040

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x951800
#define CContextMenuManager__RemoveMenu_x                          0x951870
#define CContextMenuManager__PopupMenu_x                           0x951930
#define CContextMenuManager__Flush_x                               0x9517A0
#define CContextMenuManager__GetMenu_x                             0x49B640
#define CContextMenuManager__CreateDefaultMenu_x                   0x71BFE0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DD7B0
#define CChatService__GetFriendName_x                              0x8DD7C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x711130
#define CChatWindow__Clear_x                                       0x7123F0
#define CChatWindow__WndNotification_x                             0x712B80
#define CChatWindow__AddHistory_x                                  0x711CB0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94E0C0
#define CComboWnd__Draw_x                                          0x94D5B0
#define CComboWnd__GetCurChoice_x                                  0x94DF00
#define CComboWnd__GetListRect_x                                   0x94DA70
#define CComboWnd__GetTextRect_x                                   0x94E130
#define CComboWnd__InsertChoice_x                                  0x94DC00
#define CComboWnd__SetColors_x                                     0x94DBD0
#define CComboWnd__SetChoice_x                                     0x94DED0
#define CComboWnd__GetItemCount_x                                  0x94DF10
#define CComboWnd__GetCurChoiceText_x                              0x94DF50
#define CComboWnd__GetChoiceText_x                                 0x94DF20
#define CComboWnd__InsertChoiceAtIndex_x                           0x94DC90

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7199D0
#define CContainerWnd__vftable_x                                   0xB1348C
#define CContainerWnd__SetContainer_x                              0x71AF30

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54C780
#define CDisplay__PreZoneMainUI_x                                  0x54C790
#define CDisplay__CleanGameUI_x                                    0x551B00
#define CDisplay__GetClickedActor_x                                0x544AA0
#define CDisplay__GetUserDefinedColor_x                            0x53D160
#define CDisplay__GetWorldFilePath_x                               0x546510
#define CDisplay__is3dON_x                                         0x541700
#define CDisplay__ReloadUI_x                                       0x54BC10
#define CDisplay__WriteTextHD2_x                                   0x5414F0
#define CDisplay__TrueDistance_x                                   0x5481D0
#define CDisplay__SetViewActor_x                                   0x5443C0
#define CDisplay__GetFloorHeight_x                                 0x5417C0
#define CDisplay__SetRenderWindow_x                                0x540120
#define CDisplay__ToggleScreenshotMode_x                           0x543E90

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x970A20

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x95419F
#define CEditWnd__GetCharIndexPt_x                                 0x9550D0
#define CEditWnd__GetDisplayString_x                               0x954F80
#define CEditWnd__GetHorzOffset_x                                  0x9537F0
#define CEditWnd__GetLineForPrintableChar_x                        0x956240
#define CEditWnd__GetSelStartPt_x                                  0x955380
#define CEditWnd__GetSTMLSafeText_x                                0x954DA0
#define CEditWnd__PointFromPrintableChar_x                         0x955E80
#define CEditWnd__SelectableCharFromPoint_x                        0x955FF0
#define CEditWnd__SetEditable_x                                    0x955440
#define CEditWnd__SetWindowTextA_x                                 0x954B20

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FDE20
#define CEverQuest__ClickedPlayer_x                                0x5EFE30
#define CEverQuest__CreateTargetIndicator_x                        0x60D450
#define CEverQuest__DeleteTargetIndicator_x                        0x60D4E0
#define CEverQuest__DoTellWindow_x                                 0x4E88C0
#define CEverQuest__OutputTextToLog_x                              0x4E8B40
#define CEverQuest__DropHeldItemOnGround_x                         0x5E4E70
#define CEverQuest__dsp_chat_x                                     0x4E8ED0
#define CEverQuest__trimName_x                                     0x609730
#define CEverQuest__Emote_x                                        0x5FE680
#define CEverQuest__EnterZone_x                                    0x5F8600
#define CEverQuest__GetBodyTypeDesc_x                              0x602FF0
#define CEverQuest__GetClassDesc_x                                 0x603630
#define CEverQuest__GetClassThreeLetterCode_x                      0x603C30
#define CEverQuest__GetDeityDesc_x                                 0x60BD90
#define CEverQuest__GetLangDesc_x                                  0x603DF0
#define CEverQuest__GetRaceDesc_x                                  0x603610
#define CEverQuest__InterpretCmd_x                                 0x60C360
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E9070
#define CEverQuest__LMouseUp_x                                     0x5E7400
#define CEverQuest__RightClickedOnPlayer_x                         0x5E9950
#define CEverQuest__RMouseUp_x                                     0x5E8380
#define CEverQuest__SetGameState_x                                 0x5E4C00
#define CEverQuest__UPCNotificationFlush_x                         0x609630
#define CEverQuest__IssuePetCommand_x                              0x6051F0
#define CEverQuest__ReportSuccessfulHit_x                          0x5FFA70

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72B9F0
#define CGaugeWnd__CalcLinesFillRect_x                             0x72BA50
#define CGaugeWnd__Draw_x                                          0x72B070

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF350
#define CGuild__GetGuildName_x                                     0x4AE430
#define CGuild__GetGuildIndex_x                                    0x4AE7C0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x746E70

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61ECE0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x753E80
#define CInvSlotMgr__MoveItem_x                                    0x752BA0
#define CInvSlotMgr__SelectSlot_x                                  0x753F50

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x751420
#define CInvSlot__SliderComplete_x                                 0x74F180
#define CInvSlot__GetItemBase_x                                    0x74EAF0
#define CInvSlot__UpdateItem_x                                     0x74EC60

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7559D0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x754B70
#define CInvSlotWnd__HandleLButtonUp_x                             0x755550

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80F6E0
#define CItemDisplayWnd__UpdateStrings_x                           0x764160
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75DE20
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75E350
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x764760
#define CItemDisplayWnd__AboutToShow_x                             0x763DA0
#define CItemDisplayWnd__WndNotification_x                         0x765850
#define CItemDisplayWnd__RequestConvertItem_x                      0x765310
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x762E00
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x763BC0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x848140

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x769D50

// CLabel 
#define CLabel__Draw_x                                             0x76F7A0

// CListWnd
#define CListWnd__CListWnd_x                                       0x926940
#define CListWnd__dCListWnd_x                                      0x926C60
#define CListWnd__AddColumn_x                                      0x92B0C0
#define CListWnd__AddColumn1_x                                     0x92B110
#define CListWnd__AddLine_x                                        0x92B4A0
#define CListWnd__AddString_x                                      0x92B2A0
#define CListWnd__CalculateFirstVisibleLine_x                      0x92AE80
#define CListWnd__CalculateVSBRange_x                              0x92AC70
#define CListWnd__ClearSel_x                                       0x92BC80
#define CListWnd__ClearAllSel_x                                    0x92BCE0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92C700
#define CListWnd__Compare_x                                        0x92A5A0
#define CListWnd__Draw_x                                           0x926D90
#define CListWnd__DrawColumnSeparators_x                           0x929580
#define CListWnd__DrawHeader_x                                     0x9299E0
#define CListWnd__DrawItem_x                                       0x929EE0
#define CListWnd__DrawLine_x                                       0x9296E0
#define CListWnd__DrawSeparator_x                                  0x929620
#define CListWnd__EnableLine_x                                     0x928E60
#define CListWnd__EnsureVisible_x                                  0x92C620
#define CListWnd__ExtendSel_x                                      0x92BBB0
#define CListWnd__GetColumnTooltip_x                               0x9289A0
#define CListWnd__GetColumnMinWidth_x                              0x928A10
#define CListWnd__GetColumnWidth_x                                 0x928910
#define CListWnd__GetCurSel_x                                      0x9282A0
#define CListWnd__GetItemAtPoint_x                                 0x9290D0
#define CListWnd__GetItemAtPoint1_x                                0x929140
#define CListWnd__GetItemData_x                                    0x928320
#define CListWnd__GetItemHeight_x                                  0x9286E0
#define CListWnd__GetItemIcon_x                                    0x9284B0
#define CListWnd__GetItemRect_x                                    0x928F50
#define CListWnd__GetItemText_x                                    0x928360
#define CListWnd__GetSelList_x                                     0x92BD30
#define CListWnd__GetSeparatorRect_x                               0x929380
#define CListWnd__InsertLine_x                                     0x92B890
#define CListWnd__RemoveLine_x                                     0x92B9E0
#define CListWnd__SetColors_x                                      0x92AC40
#define CListWnd__SetColumnJustification_x                         0x92A970
#define CListWnd__SetColumnWidth_x                                 0x92A890
#define CListWnd__SetCurSel_x                                      0x92BAF0
#define CListWnd__SetItemColor_x                                   0x92C2D0
#define CListWnd__SetItemData_x                                    0x92C290
#define CListWnd__SetItemText_x                                    0x92BEA0
#define CListWnd__ShiftColumnSeparator_x                           0x92AA30
#define CListWnd__Sort_x                                           0x92A720
#define CListWnd__ToggleSel_x                                      0x92BB20
#define CListWnd__SetColumnsSizable_x                              0x92AAE0
#define CListWnd__SetItemWnd_x                                     0x92C150
#define CListWnd__GetItemWnd_x                                     0x928500
#define CListWnd__SetItemIcon_x                                    0x92BF20
#define CListWnd__CalculateCustomWindowPositions_x                 0x92AF80
#define CListWnd__SetVScrollPos_x                                  0x92A870

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x785070
#define CMapViewWnd__GetWorldCoordinates_x                         0x783780
#define CMapViewWnd__HandleLButtonDown_x                           0x7807C0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A51A0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A5A80
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A5FB0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A8F30
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A3D10
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AEAE0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A4DB0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AB300
#define CPacketScrambler__hton_x                                   0x8AB2F0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9458C0
#define CSidlManager__FindScreenPieceTemplate_x                    0x945CD0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x945AC0
#define CSidlManager__CreateLabel_x                                0x806B70
#define CSidlManager__CreateXWndFromTemplate_x                     0x948C30
#define CSidlManager__CreateXWndFromTemplate1_x                    0x948E10
#define CSidlManager__CreateXWnd_x                                 0x806AA0
#define CSidlManager__CreateHotButtonWnd_x                         0x807060

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9423B0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9422B0
#define CSidlScreenWnd__ConvertToRes_x                             0x9679C0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x941D50
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x941A40
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x941B10
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x941BE0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x942840
#define CSidlScreenWnd__EnableIniStorage_x                         0x942D10
#define CSidlScreenWnd__GetSidlPiece_x                             0x942A30
#define CSidlScreenWnd__Init1_x                                    0x941640
#define CSidlScreenWnd__LoadIniInfo_x                              0x942D60
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9438A0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x940A50
#define CSidlScreenWnd__StoreIniInfo_x                             0x943420
#define CSidlScreenWnd__StoreIniVis_x                              0x943780
#define CSidlScreenWnd__WndNotification_x                          0x942750
#define CSidlScreenWnd__GetChildItem_x                             0x942C90
#define CSidlScreenWnd__HandleLButtonUp_x                          0x932560
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F8F50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6833E0
#define CSkillMgr__GetSkillCap_x                                   0x6835C0
#define CSkillMgr__GetNameToken_x                                  0x682B60
#define CSkillMgr__IsActivatedSkill_x                              0x682CA0
#define CSkillMgr__IsCombatSkill_x                                 0x682BE0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9525D0
#define CSliderWnd__SetValue_x                                     0x952440
#define CSliderWnd__SetNumTicks_x                                  0x9524A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80CB70

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95AD80
#define CStmlWnd__CalculateHSBRange_x                              0x95BEE0
#define CStmlWnd__CalculateVSBRange_x                              0x95BE60
#define CStmlWnd__CanBreakAtCharacter_x                            0x960200
#define CStmlWnd__FastForwardToEndOfTag_x                          0x960E90
#define CStmlWnd__ForceParseNow_x                                  0x95B3C0
#define CStmlWnd__GetNextTagPiece_x                                0x960160
#define CStmlWnd__GetSTMLText_x                                    0x504BD0
#define CStmlWnd__GetVisibleText_x                                 0x95B3E0
#define CStmlWnd__InitializeWindowVariables_x                      0x960CE0
#define CStmlWnd__MakeStmlColorTag_x                               0x95A3F0
#define CStmlWnd__MakeWndNotificationTag_x                         0x95A460
#define CStmlWnd__SetSTMLText_x                                    0x9594A0
#define CStmlWnd__StripFirstSTMLLines_x                            0x961F60
#define CStmlWnd__UpdateHistoryString_x                            0x9610A0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9585F0
#define CTabWnd__DrawCurrentPage_x                                 0x958D20
#define CTabWnd__DrawTab_x                                         0x958A40
#define CTabWnd__GetCurrentPage_x                                  0x957E00
#define CTabWnd__GetPageInnerRect_x                                0x958040
#define CTabWnd__GetTabInnerRect_x                                 0x957F80
#define CTabWnd__GetTabRect_x                                      0x957E30
#define CTabWnd__InsertPage_x                                      0x958250
#define CTabWnd__SetPage_x                                         0x9580C0
#define CTabWnd__SetPageRect_x                                     0x958530
#define CTabWnd__UpdatePage_x                                      0x958900
#define CTabWnd__GetPageFromTabIndex_x                             0x958980
#define CTabWnd__GetCurrentTabIndex_x                              0x957DF0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x76A190
#define CPageWnd__SetTabText_x                                     0x957950

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A90A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92F420
#define CTextureFont__GetTextExtent_x                              0x92F5E0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B6760
#define CHtmlComponentWnd__ValidateUri_x                           0x748860
#define CHtmlWnd__SetClientCallbacks_x                             0x623D50
#define CHtmlWnd__AddObserver_x                                    0x623D70
#define CHtmlWnd__RemoveObserver_x                                 0x623DD0
#define Window__getProgress_x                                      0x860990
#define Window__getStatus_x                                        0x8609B0
#define Window__getURI_x                                           0x8609C0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96D4B0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91C590

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8510
#define CXStr__CXStr1_x                                            0x4FFCD0
#define CXStr__CXStr3_x                                            0x8FDFB0
#define CXStr__dCXStr_x                                            0x478800
#define CXStr__operator_equal_x                                    0x8FE1E0
#define CXStr__operator_equal1_x                                   0x8FE220
#define CXStr__operator_plus_equal1_x                              0x8FECB0
#define CXStr__SetString_x                                         0x900BA0
#define CXStr__operator_char_p_x                                   0x8FE720
#define CXStr__GetChar_x                                           0x9004D0
#define CXStr__Delete_x                                            0x8FFDA0
#define CXStr__GetUnicode_x                                        0x900540
#define CXStr__GetLength_x                                         0x47D470
#define CXStr__Mid_x                                               0x47D480
#define CXStr__Insert_x                                            0x9005A0
#define CXStr__FindNext_x                                          0x900210

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x950870
#define CXWnd__BringToTop_x                                        0x935CB0
#define CXWnd__Center_x                                            0x935830
#define CXWnd__ClrFocus_x                                          0x935640
#define CXWnd__Destroy_x                                           0x9356F0
#define CXWnd__DoAllDrawing_x                                      0x931D10
#define CXWnd__DrawChildren_x                                      0x931CE0
#define CXWnd__DrawColoredRect_x                                   0x932150
#define CXWnd__DrawTooltip_x                                       0x930830
#define CXWnd__DrawTooltipAtPoint_x                                0x9308F0
#define CXWnd__GetBorderFrame_x                                    0x931FB0
#define CXWnd__GetChildWndAt_x                                     0x935D50
#define CXWnd__GetClientClipRect_x                                 0x933F70
#define CXWnd__GetScreenClipRect_x                                 0x934020
#define CXWnd__GetScreenRect_x                                     0x9341D0
#define CXWnd__GetTooltipRect_x                                    0x9321A0
#define CXWnd__GetWindowTextA_x                                    0x49CD20
#define CXWnd__IsActive_x                                          0x9328D0
#define CXWnd__IsDescendantOf_x                                    0x934BB0
#define CXWnd__IsReallyVisible_x                                   0x934BE0
#define CXWnd__IsType_x                                            0x9363D0
#define CXWnd__Move_x                                              0x934C50
#define CXWnd__Move1_x                                             0x934D00
#define CXWnd__ProcessTransition_x                                 0x9357E0
#define CXWnd__Refade_x                                            0x934FD0
#define CXWnd__Resize_x                                            0x935260
#define CXWnd__Right_x                                             0x935A70
#define CXWnd__SetFocus_x                                          0x935600
#define CXWnd__SetFont_x                                           0x935670
#define CXWnd__SetKeyTooltip_x                                     0x9361E0
#define CXWnd__SetMouseOver_x                                      0x933110
#define CXWnd__StartFade_x                                         0x934A90
#define CXWnd__GetChildItem_x                                      0x935EC0
#define CXWnd__SetParent_x                                         0x934960
#define CXWnd__Minimize_x                                          0x9352D0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x968A40

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x938C10
#define CXWndManager__DrawWindows_x                                0x938C30
#define CXWndManager__GetKeyboardFlags_x                           0x93B330
#define CXWndManager__HandleKeyboardMsg_x                          0x93AEF0
#define CXWndManager__RemoveWnd_x                                  0x93B550
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93BAA0

// CDBStr
#define CDBStr__GetString_x                                        0x53C130

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB980
#define EQ_Character__Cur_HP_x                                     0x4D20F0
#define EQ_Character__Cur_Mana_x                                   0x4D9810
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE9F0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2480
#define EQ_Character__GetFocusRangeModifier_x                      0x4B25D0
#define EQ_Character__GetHPRegen_x                                 0x4DF5B0
#define EQ_Character__GetEnduranceRegen_x                          0x4DFBB0
#define EQ_Character__GetManaRegen_x                               0x4DFFF0
#define EQ_Character__Max_Endurance_x                              0x649CE0
#define EQ_Character__Max_HP_x                                     0x4D1F20
#define EQ_Character__Max_Mana_x                                   0x649AE0
#define EQ_Character__doCombatAbility_x                            0x64C130
#define EQ_Character__UseSkill_x                                   0x4E1DC0
#define EQ_Character__GetConLevel_x                                0x642EC0
#define EQ_Character__IsExpansionFlag_x                            0x5A6780
#define EQ_Character__TotalEffect_x                                0x4C5440
#define EQ_Character__GetPCSpellAffect_x                           0x4BF740
#define EQ_Character__SpellDuration_x                              0x4BF270
#define EQ_Character__GetAdjustedSkill_x                           0x4D4E70
#define EQ_Character__GetBaseSkill_x                               0x4D5E10
#define EQ_Character__CanUseItem_x                                 0x4D9B20

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CA630

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x660260

//PcClient
#define PcClient__PcClient_x                                       0x640600

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B95E0
#define CCharacterListWnd__EnterWorld_x                            0x4B9020
#define CCharacterListWnd__Quit_x                                  0x4B8D70
#define CCharacterListWnd__UpdateList_x                            0x4B91B0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x624F90
#define EQ_Item__CreateItemTagString_x                             0x8A4B50
#define EQ_Item__IsStackable_x                                     0x8A96C0
#define EQ_Item__GetImageNum_x                                     0x8A65B0
#define EQ_Item__CreateItemClient_x                                0x624150
#define EQ_Item__GetItemValue_x                                    0x8A78D0
#define EQ_Item__ValueSellMerchant_x                               0x8AAEE0
#define EQ_Item__IsKeyRingItem_x                                   0x8A8FE0
#define EQ_Item__CanGoInBag_x                                      0x6250B0
#define EQ_Item__IsEmpty_x                                         0x8A8B20
#define EQ_Item__GetMaxItemCount_x                                 0x8A7CE0
#define EQ_Item__GetHeldItem_x                                     0x8A6480
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A44D0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55A5A0
#define EQ_LoadingS__Array_x                                       0xC27B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64A640
#define EQ_PC__GetAlternateAbilityId_x                             0x8B4140
#define EQ_PC__GetCombatAbility_x                                  0x8B47B0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B4820
#define EQ_PC__GetItemRecastTimer_x                                0x64C6B0
#define EQ_PC__HasLoreItem_x                                       0x643680
#define EQ_PC__AlertInventoryChanged_x                             0x642800
#define EQ_PC__GetPcZoneClient_x                                   0x66ECD0
#define EQ_PC__RemoveMyAffect_x                                    0x64F8E0
#define EQ_PC__GetKeyRingItems_x                                   0x8B50B0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B4E40
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B53B0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5ACCF0
#define EQItemList__add_object_x                                   0x5DA6D0
#define EQItemList__add_item_x                                     0x5AD250
#define EQItemList__delete_item_x                                  0x5AD2A0
#define EQItemList__FreeItemList_x                                 0x5AD1A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x538C60

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x661AE0
#define EQPlayer__dEQPlayer_x                                      0x654E20
#define EQPlayer__DoAttack_x                                       0x669970
#define EQPlayer__EQPlayer_x                                       0x6554E0
#define EQPlayer__SetNameSpriteState_x                             0x6597C0
#define EQPlayer__SetNameSpriteTint_x                              0x65A690
#define PlayerBase__HasProperty_j_x                                0x99B0E0
#define EQPlayer__IsTargetable_x                                   0x99B580
#define EQPlayer__CanSee_x                                         0x99B3E0
#define EQPlayer__CanSee1_x                                        0x99B4B0
#define PlayerBase__GetVisibilityLineSegment_x                     0x99B1A0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66C770
#define PlayerZoneClient__GetLevel_x                               0x66ED10
#define PlayerZoneClient__IsValidTeleport_x                        0x5DB840
#define PlayerZoneClient__LegalPlayerRace_x                        0x553990

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x664830
#define EQPlayerManager__GetSpawnByName_x                          0x6648E0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x664970

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6285D0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x628650
#define KeypressHandler__AttachKeyToEqCommand_x                    0x628690
#define KeypressHandler__ClearCommandStateArray_x                  0x629AA0
#define KeypressHandler__HandleKeyDown_x                           0x629AC0
#define KeypressHandler__HandleKeyUp_x                             0x629B60
#define KeypressHandler__SaveKeymapping_x                          0x629FB0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x780EE0
#define MapViewMap__SaveEx_x                                       0x7842A0
#define MapViewMap__SetZoom_x                                      0x788960

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C8550

// StringTable 
#define StringTable__getString_x                                   0x8C3390

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64F550
#define PcZoneClient__RemovePetEffect_x                            0x64FB80
#define PcZoneClient__HasAlternateAbility_x                        0x649910
#define PcZoneClient__GetCurrentMod_x                              0x4E4E80
#define PcZoneClient__GetModCap_x                                  0x4E4D80
#define PcZoneClient__CanEquipItem_x                               0x649FE0
#define PcZoneClient__GetItemByID_x                                0x64CB20
#define PcZoneClient__GetItemByItemClass_x                         0x64CC70
#define PcZoneClient__RemoveBuffEffect_x                           0x64FBA0
#define PcZoneClient__BandolierSwap_x                              0x64ABF0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64C650

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E02E0

//IconCache
#define IconCache__GetIcon_x                                       0x721070

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x718AC0
#define CContainerMgr__CloseContainer_x                            0x718D90
#define CContainerMgr__OpenExperimentContainer_x                   0x719810

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D9160

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61D110

//CLootWnd
#define CLootWnd__LootAll_x                                        0x777270
#define CLootWnd__RequestLootSlot_x                                0x7764A0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57A1F0
#define EQ_Spell__SpellAffects_x                                   0x57A660
#define EQ_Spell__SpellAffectBase_x                                0x57A420
#define EQ_Spell__IsStackable_x                                    0x4C9B40
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9990
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6990
#define EQ_Spell__IsSPAStacking_x                                  0x57B4B0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57A9C0
#define EQ_Spell__IsNoRemove_x                                     0x4C9B20
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57B4C0
#define __IsResEffectSpell_x                                       0x4C8E80

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD0C0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D2C50

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81FDF0
#define CTargetWnd__WndNotification_x                              0x81F680
#define CTargetWnd__RefreshTargetBuffs_x                           0x81F950
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81E7F0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x824400

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5366E0
#define CTaskManager__HandleMessage_x                              0x534B70
#define CTaskManager__GetTaskStatus_x                              0x536790
#define CTaskManager__GetElementDescription_x                      0x536810

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5756E0
#define EqSoundManager__PlayScriptMp3_x                            0x575840
#define EqSoundManager__SoundAssistPlay_x                          0x687340
#define EqSoundManager__WaveInstancePlay_x                         0x6868B0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52A420

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x956E60

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x562050
#define CAltAbilityData__GetMercMaxRank_x                          0x561FE0
#define CAltAbilityData__GetMaxRank_x                              0x557680

//CTargetRing
#define CTargetRing__Cast_x                                        0x61B230

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9970
#define CharacterBase__CreateItemGlobalIndex_x                     0x511BB0
#define CharacterBase__CreateItemIndex_x                           0x623300
#define CharacterBase__GetItemPossession_x                         0x4FD560
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DB240
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DB2A0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FFCC0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x7004F0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x7005A0

//messages
#define msg_spell_worn_off_x                                       0x59E910
#define msg_new_text_x                                             0x5936A0
#define __msgTokenTextParam_x                                      0x5A0E40
#define msgTokenText_x                                             0x5A1090

//SpellManager
#define SpellManager__vftable_x                                    0xAED4CC
#define SpellManager__SpellManager_x                               0x68A670
#define Spellmanager__LoadTextSpells_x                             0x68AF60
#define SpellManager__GetSpellByGroupAndRank_x                     0x68A840

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99EFE0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x512200
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A4C10
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63BD80
#define ItemGlobalIndex__IsValidIndex_x                            0x512260

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D35F0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D3870

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76FAE0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71D280
#define CCursorAttachment__AttachToCursor1_x                       0x71D2C0
#define CCursorAttachment__Deactivate_x                            0x71E2A0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x949C60
#define CSidlManagerBase__CreatePageWnd_x                          0x949460
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9456E0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x945670

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x966C70
#define CEQSuiteTextureLoader__GetTexture_x                        0x966930

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50F120
#define CFindItemWnd__WndNotification_x                            0x50FC00
#define CFindItemWnd__Update_x                                     0x510770
#define CFindItemWnd__PickupSelectedItem_x                         0x50E960

//IString
#define IString__Append_x                                          0x4F0480

//Camera
#define CDisplay__cameraType_x                                     0xE010D0
#define EverQuest__Cameras_x                                       0xEC4A7C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5178B0
#define LootFiltersManager__GetItemFilterData_x                    0x5171B0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5171E0
#define LootFiltersManager__SetItemLootFilter_x                    0x517400

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C7100

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A4BD0
#define CResolutionHandler__GetWindowedStyle_x                     0x681D90

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x715890

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E8600
#define CDistillerInfo__Instance_x                                 0x8E85A0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x735C00
#define CGroupWnd__UpdateDisplay_x                                 0x734F60

//ItemBase
#define ItemBase__IsLore_x                                         0x8A9090
#define ItemBase__IsLoreEquipped_x                                 0x8A9100

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DA630
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DA770
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DA7D0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6773E0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67AD60

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x505460

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F2020
#define FactionManagerClient__HandleFactionMessage_x               0x4F2690
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2C90
#define FactionManagerClient__GetMaxFaction_x                      0x4F2CAF
#define FactionManagerClient__GetMinFaction_x                      0x4F2C60

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FD530

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92E3A0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C030

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FD890

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x561510

//CTargetManager
#define CTargetManager__Get_x                                      0x68DEE0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6773E0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8E60

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AD140

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF62110

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
