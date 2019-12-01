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
#define __ExpectedVersionDate                                     "Dec  1 2019"
#define __ExpectedVersionTime                                     "04:45:00"
#define __ActualVersionDate_x                                      0xB0A2B4
#define __ActualVersionTime_x                                      0xB0A2A8
#define __ActualVersionBuild_x                                     0xAF5F84

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62F710
#define __MemChecker1_x                                            0x903770
#define __MemChecker2_x                                            0x6BE560
#define __MemChecker3_x                                            0x6BE4B0
#define __MemChecker4_x                                            0x85A210
#define __EncryptPad0_x                                            0xC403E8
#define __EncryptPad1_x                                            0xC9E5E8
#define __EncryptPad2_x                                            0xC50C80
#define __EncryptPad3_x                                            0xC50880
#define __EncryptPad4_x                                            0xC8EC00
#define __EncryptPad5_x                                            0xF6A1C0
#define __AC1_x                                                    0x816E46
#define __AC2_x                                                    0x5E95AF
#define __AC3_x                                                    0x5F0CAF
#define __AC4_x                                                    0x5F4C80
#define __AC5_x                                                    0x5FAF8F
#define __AC6_x                                                    0x5FF5A6
#define __AC7_x                                                    0x5E9020
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
#define __do_loot_x                                                0x5B5010
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
#define __gfMaxZoomCameraDistance_x                                0xAFFC20
#define __gfMaxCameraDistance_x                                    0xB2C164
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
#define pinstCAvaZoneWnd_x                                         0xE01054
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
#define pinstCEventCalendarWnd_x                                   0xE01050
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
#define pinstCItemOverflowWnd_x                                    0xE01094
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
#define pinstCMailCompositionWnd_x                                 0xE01304
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
#define pinstCStoryWnd_x                                           0xE010A8
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
#define pinstCTradeWnd_x                                           0xE012F8
#define pinstCTrainWnd_x                                           0xE012F4
#define pinstCTributeBenefitWnd_x                                  0xF7DFE0
#define pinstCTributeMasterWnd_x                                   0xF7E090
#define pinstCTributeTrophyWnd_x                                   0xF7E140
#define pinstCVideoModesWnd_x                                      0xE010AC
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
#define __CastRay_x                                                0x5B0470
#define __CastRay2_x                                               0x5B04C0
#define __ConvertItemTags_x                                        0x5CC020
#define __CleanItemTags_x                                          0x47D170
#define __DoesFileExist_x                                          0x906800
#define __EQGetTime_x                                              0x903240
#define __ExecuteCmd_x                                             0x5A8C80
#define __FixHeading_x                                             0x99D7B0
#define __GameLoop_x                                               0x6BD750
#define __get_bearing_x                                            0x5AFFE0
#define __get_melee_range_x                                        0x5B06B0
#define __GetAnimationCache_x                                      0x722B20
#define __GetGaugeValueFromEQ_x                                    0x8152F0
#define __GetLabelFromEQ_x                                         0x816DD0
#define __GetXTargetType_x                                         0x99F200
#define __HandleMouseWheel_x                                       0x6BE610
#define __HeadingDiff_x                                            0x99D820
#define __HelpPath_x                                               0xF627DC
#define __LoadFrontEnd_x                                           0x6BAA70
#define __NewUIINI_x                                               0x814FC0
#define __ProcessGameEvents_x                                      0x610E10
#define __ProcessMouseEvent_x                                      0x6105D0
#define __SaveColors_x                                             0x551F70
#define __STMLToText_x                                             0x940D40
#define __ToggleKeyRingItem_x                                      0x5156E0
#define CMemoryMappedFile__SetFile_x                               0xA8C930
#define CrashDetected_x                                            0x6BC510
#define DrawNetStatus_x                                            0x63CAA0
#define Expansion_HoT_x                                            0xEC472C
#define Teleport_Table_Size_x                                      0xEB3760
#define Teleport_Table_x                                           0xEB3BC8
#define Util__FastTime_x                                           0x902E10

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490290
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4991B0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498F80
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493830
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492C80

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x559AB0
#define AltAdvManager__IsAbilityReady_x                            0x5589E0
#define AltAdvManager__GetAAById_x                                 0x558BE0
#define AltAdvManager__CanTrainAbility_x                           0x558C50
#define AltAdvManager__CanSeeAbility_x                             0x558FB0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA010
#define CharacterZoneClient__HasSkill_x                            0x4D4F00
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6620
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE2B0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA8B0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8FD0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D90B0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9190
#define CharacterZoneClient__FindAffectSlot_x                      0x4C30B0
#define CharacterZoneClient__BardCastBard_x                        0x4C5C10
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA980
#define CharacterZoneClient__GetEffect_x                           0x4BA7F0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4100
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C41D0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4220
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4370
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4540
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2770
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7580
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7000

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E4220
#define CBankWnd__WndNotification_x                                0x6E4000

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F1A80

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61F4B0
#define CButtonWnd__CButtonWnd_x                                   0x93D0E0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x711C80
#define CChatManager__InitContextMenu_x                            0x70ADD0
#define CChatManager__FreeChatWindow_x                             0x7107C0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8660
#define CChatManager__SetLockedActiveChatWindow_x                  0x711900
#define CChatManager__CreateChatWindow_x                           0x710E00

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8770

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x951800
#define CContextMenu__dCContextMenu_x                              0x951A40
#define CContextMenu__AddMenuItem_x                                0x951A50
#define CContextMenu__RemoveMenuItem_x                             0x951D60
#define CContextMenu__RemoveAllMenuItems_x                         0x951D80
#define CContextMenu__CheckMenuItem_x                              0x951E00
#define CContextMenu__SetMenuItem_x                                0x951C80
#define CContextMenu__AddSeparator_x                               0x951BE0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9523A0
#define CContextMenuManager__RemoveMenu_x                          0x952410
#define CContextMenuManager__PopupMenu_x                           0x9524D0
#define CContextMenuManager__Flush_x                               0x952340
#define CContextMenuManager__GetMenu_x                             0x49B340
#define CContextMenuManager__CreateDefaultMenu_x                   0x71D310

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DEAD0
#define CChatService__GetFriendName_x                              0x8DEAE0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7124F0
#define CChatWindow__Clear_x                                       0x7137C0
#define CChatWindow__WndNotification_x                             0x713F50
#define CChatWindow__AddHistory_x                                  0x713080

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94EC60
#define CComboWnd__Draw_x                                          0x94E140
#define CComboWnd__GetCurChoice_x                                  0x94EAA0
#define CComboWnd__GetListRect_x                                   0x94E600
#define CComboWnd__GetTextRect_x                                   0x94ECD0
#define CComboWnd__InsertChoice_x                                  0x94E790
#define CComboWnd__SetColors_x                                     0x94E760
#define CComboWnd__SetChoice_x                                     0x94EA70
#define CComboWnd__GetItemCount_x                                  0x94EAB0
#define CComboWnd__GetCurChoiceText_x                              0x94EAF0
#define CComboWnd__GetChoiceText_x                                 0x94EAC0
#define CComboWnd__InsertChoiceAtIndex_x                           0x94E830

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x71AD00
#define CContainerWnd__vftable_x                                   0xB134A4
#define CContainerWnd__SetContainer_x                              0x71C260

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54C9A0
#define CDisplay__PreZoneMainUI_x                                  0x54C9B0
#define CDisplay__CleanGameUI_x                                    0x551D30
#define CDisplay__GetClickedActor_x                                0x544CC0
#define CDisplay__GetUserDefinedColor_x                            0x53D380
#define CDisplay__GetWorldFilePath_x                               0x546730
#define CDisplay__is3dON_x                                         0x541920
#define CDisplay__ReloadUI_x                                       0x54BE30
#define CDisplay__WriteTextHD2_x                                   0x541710
#define CDisplay__TrueDistance_x                                   0x5483F0
#define CDisplay__SetViewActor_x                                   0x5445E0
#define CDisplay__GetFloorHeight_x                                 0x5419E0
#define CDisplay__SetRenderWindow_x                                0x540340
#define CDisplay__ToggleScreenshotMode_x                           0x5440B0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9713E0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x954D5F
#define CEditWnd__GetCharIndexPt_x                                 0x955CA0
#define CEditWnd__GetDisplayString_x                               0x955B40
#define CEditWnd__GetHorzOffset_x                                  0x9543A0
#define CEditWnd__GetLineForPrintableChar_x                        0x956E40
#define CEditWnd__GetSelStartPt_x                                  0x955F50
#define CEditWnd__GetSTMLSafeText_x                                0x955960
#define CEditWnd__PointFromPrintableChar_x                         0x956A70
#define CEditWnd__SelectableCharFromPoint_x                        0x956BE0
#define CEditWnd__SetEditable_x                                    0x956020
#define CEditWnd__SetWindowTextA_x                                 0x9556E0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FEA80
#define CEverQuest__ClickedPlayer_x                                0x5F0A90
#define CEverQuest__CreateTargetIndicator_x                        0x60E0B0
#define CEverQuest__DeleteTargetIndicator_x                        0x60E140
#define CEverQuest__DoTellWindow_x                                 0x4E8850
#define CEverQuest__OutputTextToLog_x                              0x4E8AD0
#define CEverQuest__DropHeldItemOnGround_x                         0x5E5AD0
#define CEverQuest__dsp_chat_x                                     0x4E8E60
#define CEverQuest__trimName_x                                     0x60A390
#define CEverQuest__Emote_x                                        0x5FF2E0
#define CEverQuest__EnterZone_x                                    0x5F9260
#define CEverQuest__GetBodyTypeDesc_x                              0x603C50
#define CEverQuest__GetClassDesc_x                                 0x604290
#define CEverQuest__GetClassThreeLetterCode_x                      0x604890
#define CEverQuest__GetDeityDesc_x                                 0x60C9F0
#define CEverQuest__GetLangDesc_x                                  0x604A50
#define CEverQuest__GetRaceDesc_x                                  0x604270
#define CEverQuest__InterpretCmd_x                                 0x60CFC0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E9CD0
#define CEverQuest__LMouseUp_x                                     0x5E8060
#define CEverQuest__RightClickedOnPlayer_x                         0x5EA5B0
#define CEverQuest__RMouseUp_x                                     0x5E8FE0
#define CEverQuest__SetGameState_x                                 0x5E5860
#define CEverQuest__UPCNotificationFlush_x                         0x60A290
#define CEverQuest__IssuePetCommand_x                              0x605E50
#define CEverQuest__ReportSuccessfulHit_x                          0x6006D0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72CCF0
#define CGaugeWnd__CalcLinesFillRect_x                             0x72CD50
#define CGaugeWnd__Draw_x                                          0x72C380

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF1A0
#define CGuild__GetGuildName_x                                     0x4AE280
#define CGuild__GetGuildIndex_x                                    0x4AE610

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x748190

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61F870

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x755150
#define CInvSlotMgr__MoveItem_x                                    0x753EC0
#define CInvSlotMgr__SelectSlot_x                                  0x755220

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x752740
#define CInvSlot__SliderComplete_x                                 0x750490
#define CInvSlot__GetItemBase_x                                    0x74FE20
#define CInvSlot__UpdateItem_x                                     0x74FF90

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x756CB0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x755E50
#define CInvSlotWnd__HandleLButtonUp_x                             0x756830

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x810660
#define CItemDisplayWnd__UpdateStrings_x                           0x7653D0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75F120
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75F640
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7659E0
#define CItemDisplayWnd__AboutToShow_x                             0x765020
#define CItemDisplayWnd__WndNotification_x                         0x766AC0
#define CItemDisplayWnd__RequestConvertItem_x                      0x766580
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x764080
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x764E40

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x849210

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x76B010

// CLabel 
#define CLabel__Draw_x                                             0x770A70

// CListWnd
#define CListWnd__CListWnd_x                                       0x927420
#define CListWnd__dCListWnd_x                                      0x927740
#define CListWnd__AddColumn_x                                      0x92BBC0
#define CListWnd__AddColumn1_x                                     0x92BC10
#define CListWnd__AddLine_x                                        0x92BFA0
#define CListWnd__AddString_x                                      0x92BDA0
#define CListWnd__CalculateFirstVisibleLine_x                      0x92B980
#define CListWnd__CalculateVSBRange_x                              0x92B770
#define CListWnd__ClearSel_x                                       0x92C780
#define CListWnd__ClearAllSel_x                                    0x92C7E0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92D200
#define CListWnd__Compare_x                                        0x92B0A0
#define CListWnd__Draw_x                                           0x927870
#define CListWnd__DrawColumnSeparators_x                           0x92A070
#define CListWnd__DrawHeader_x                                     0x92A4E0
#define CListWnd__DrawItem_x                                       0x92A9E0
#define CListWnd__DrawLine_x                                       0x92A1E0
#define CListWnd__DrawSeparator_x                                  0x92A110
#define CListWnd__EnableLine_x                                     0x929940
#define CListWnd__EnsureVisible_x                                  0x92D120
#define CListWnd__ExtendSel_x                                      0x92C6B0
#define CListWnd__GetColumnTooltip_x                               0x929480
#define CListWnd__GetColumnMinWidth_x                              0x9294F0
#define CListWnd__GetColumnWidth_x                                 0x9293F0
#define CListWnd__GetCurSel_x                                      0x928D80
#define CListWnd__GetItemAtPoint_x                                 0x929BC0
#define CListWnd__GetItemAtPoint1_x                                0x929C30
#define CListWnd__GetItemData_x                                    0x928E00
#define CListWnd__GetItemHeight_x                                  0x9291C0
#define CListWnd__GetItemIcon_x                                    0x928F90
#define CListWnd__GetItemRect_x                                    0x929A30
#define CListWnd__GetItemText_x                                    0x928E40
#define CListWnd__GetSelList_x                                     0x92C830
#define CListWnd__GetSeparatorRect_x                               0x929E70
#define CListWnd__InsertLine_x                                     0x92C390
#define CListWnd__RemoveLine_x                                     0x92C4E0
#define CListWnd__SetColors_x                                      0x92B740
#define CListWnd__SetColumnJustification_x                         0x92B470
#define CListWnd__SetColumnWidth_x                                 0x92B390
#define CListWnd__SetCurSel_x                                      0x92C5F0
#define CListWnd__SetItemColor_x                                   0x92CDD0
#define CListWnd__SetItemData_x                                    0x92CD90
#define CListWnd__SetItemText_x                                    0x92C9A0
#define CListWnd__ShiftColumnSeparator_x                           0x92B530
#define CListWnd__Sort_x                                           0x92B220
#define CListWnd__ToggleSel_x                                      0x92C620
#define CListWnd__SetColumnsSizable_x                              0x92B5E0
#define CListWnd__SetItemWnd_x                                     0x92CC50
#define CListWnd__GetItemWnd_x                                     0x928FE0
#define CListWnd__SetItemIcon_x                                    0x92CA20
#define CListWnd__CalculateCustomWindowPositions_x                 0x92BA80
#define CListWnd__SetVScrollPos_x                                  0x92B370

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7861E0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7848F0
#define CMapViewWnd__HandleLButtonDown_x                           0x781930

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A61F0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A6AD0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A7000
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A9F80
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A4D60
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AFB40
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A5E00

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AC5C0
#define CPacketScrambler__hton_x                                   0x8AC5B0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x946360
#define CSidlManager__FindScreenPieceTemplate_x                    0x946770
#define CSidlManager__FindScreenPieceTemplate1_x                   0x946560
#define CSidlManager__CreateLabel_x                                0x807A90
#define CSidlManager__CreateXWndFromTemplate_x                     0x9496D0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9498B0
#define CSidlManager__CreateXWnd_x                                 0x8079C0
#define CSidlManager__CreateHotButtonWnd_x                         0x807F90

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x942E60
#define CSidlScreenWnd__CalculateVSBRange_x                        0x942D60
#define CSidlScreenWnd__ConvertToRes_x                             0x968430
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9427F0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9424E0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9425B0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x942680
#define CSidlScreenWnd__DrawSidlPiece_x                            0x943300
#define CSidlScreenWnd__EnableIniStorage_x                         0x9437D0
#define CSidlScreenWnd__GetSidlPiece_x                             0x9434F0
#define CSidlScreenWnd__Init1_x                                    0x9420E0
#define CSidlScreenWnd__LoadIniInfo_x                              0x943820
#define CSidlScreenWnd__LoadIniListWnd_x                           0x944340
#define CSidlScreenWnd__LoadSidlScreen_x                           0x9414F0
#define CSidlScreenWnd__StoreIniInfo_x                             0x943EC0
#define CSidlScreenWnd__StoreIniVis_x                              0x944220
#define CSidlScreenWnd__WndNotification_x                          0x943210
#define CSidlScreenWnd__GetChildItem_x                             0x943750
#define CSidlScreenWnd__HandleLButtonUp_x                          0x933030
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F8F50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x684310
#define CSkillMgr__GetSkillCap_x                                   0x6844F0
#define CSkillMgr__GetNameToken_x                                  0x683A90
#define CSkillMgr__IsActivatedSkill_x                              0x683BD0
#define CSkillMgr__IsCombatSkill_x                                 0x683B10

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x953180
#define CSliderWnd__SetValue_x                                     0x952FF0
#define CSliderWnd__SetNumTicks_x                                  0x953050

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80DAF0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95B9A0
#define CStmlWnd__CalculateHSBRange_x                              0x95CAD0
#define CStmlWnd__CalculateVSBRange_x                              0x95CA40
#define CStmlWnd__CanBreakAtCharacter_x                            0x960E00
#define CStmlWnd__FastForwardToEndOfTag_x                          0x961A90
#define CStmlWnd__ForceParseNow_x                                  0x95BF90
#define CStmlWnd__GetNextTagPiece_x                                0x960D60
#define CStmlWnd__GetSTMLText_x                                    0x504AE0
#define CStmlWnd__GetVisibleText_x                                 0x95BFB0
#define CStmlWnd__InitializeWindowVariables_x                      0x9618E0
#define CStmlWnd__MakeStmlColorTag_x                               0x95B010
#define CStmlWnd__MakeWndNotificationTag_x                         0x95B080
#define CStmlWnd__SetSTMLText_x                                    0x95A0C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x962B90
#define CStmlWnd__UpdateHistoryString_x                            0x961CA0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x959210
#define CTabWnd__DrawCurrentPage_x                                 0x959940
#define CTabWnd__DrawTab_x                                         0x959660
#define CTabWnd__GetCurrentPage_x                                  0x958A10
#define CTabWnd__GetPageInnerRect_x                                0x958C50
#define CTabWnd__GetTabInnerRect_x                                 0x958B90
#define CTabWnd__GetTabRect_x                                      0x958A40
#define CTabWnd__InsertPage_x                                      0x958E60
#define CTabWnd__SetPage_x                                         0x958CD0
#define CTabWnd__SetPageRect_x                                     0x959150
#define CTabWnd__UpdatePage_x                                      0x959520
#define CTabWnd__GetPageFromTabIndex_x                             0x9595A0
#define CTabWnd__GetCurrentTabIndex_x                              0x958A00

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x76B3E0
#define CPageWnd__SetTabText_x                                     0x958550

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8DF0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92FEF0
#define CTextureFont__GetTextExtent_x                              0x9300B0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B7630
#define CHtmlComponentWnd__ValidateUri_x                           0x749B80
#define CHtmlWnd__SetClientCallbacks_x                             0x624900
#define CHtmlWnd__AddObserver_x                                    0x624920
#define CHtmlWnd__RemoveObserver_x                                 0x624980
#define Window__getProgress_x                                      0x8617C0
#define Window__getStatus_x                                        0x8617E0
#define Window__getURI_x                                           0x8617F0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96DE70

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91CF30

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E83A0
#define CXStr__CXStr1_x                                            0x4FFC40
#define CXStr__CXStr3_x                                            0x8FF380
#define CXStr__dCXStr_x                                            0x4787B0
#define CXStr__operator_equal_x                                    0x8FF5B0
#define CXStr__operator_equal1_x                                   0x8FF5F0
#define CXStr__operator_plus_equal1_x                              0x900080
#define CXStr__SetString_x                                         0x901F70
#define CXStr__operator_char_p_x                                   0x8FFAC0
#define CXStr__GetChar_x                                           0x9018C0
#define CXStr__Delete_x                                            0x901170
#define CXStr__GetUnicode_x                                        0x901930
#define CXStr__GetLength_x                                         0x4A8BA0
#define CXStr__Mid_x                                               0x47D520
#define CXStr__Insert_x                                            0x901990
#define CXStr__FindNext_x                                          0x9015E0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x951420
#define CXWnd__BringToTop_x                                        0x936780
#define CXWnd__Center_x                                            0x936300
#define CXWnd__ClrFocus_x                                          0x936120
#define CXWnd__Destroy_x                                           0x9361C0
#define CXWnd__DoAllDrawing_x                                      0x9327E0
#define CXWnd__DrawChildren_x                                      0x9327B0
#define CXWnd__DrawColoredRect_x                                   0x932C40
#define CXWnd__DrawTooltip_x                                       0x9312F0
#define CXWnd__DrawTooltipAtPoint_x                                0x9313B0
#define CXWnd__GetBorderFrame_x                                    0x932AA0
#define CXWnd__GetChildWndAt_x                                     0x936820
#define CXWnd__GetClientClipRect_x                                 0x934A80
#define CXWnd__GetScreenClipRect_x                                 0x934B50
#define CXWnd__GetScreenRect_x                                     0x934D20
#define CXWnd__GetTooltipRect_x                                    0x932C90
#define CXWnd__GetWindowTextA_x                                    0x49CA10
#define CXWnd__IsActive_x                                          0x9333B0
#define CXWnd__IsDescendantOf_x                                    0x9356E0
#define CXWnd__IsReallyVisible_x                                   0x935710
#define CXWnd__IsType_x                                            0x936E90
#define CXWnd__Move_x                                              0x935780
#define CXWnd__Move1_x                                             0x935830
#define CXWnd__ProcessTransition_x                                 0x9362B0
#define CXWnd__Refade_x                                            0x935AE0
#define CXWnd__Resize_x                                            0x935D70
#define CXWnd__Right_x                                             0x936540
#define CXWnd__SetFocus_x                                          0x9360E0
#define CXWnd__SetFont_x                                           0x936150
#define CXWnd__SetKeyTooltip_x                                     0x936CB0
#define CXWnd__SetMouseOver_x                                      0x933BD0
#define CXWnd__StartFade_x                                         0x9355C0
#define CXWnd__GetChildItem_x                                      0x936990
#define CXWnd__SetParent_x                                         0x935480
#define CXWnd__Minimize_x                                          0x935DE0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9694B0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x939650
#define CXWndManager__DrawWindows_x                                0x939670
#define CXWndManager__GetKeyboardFlags_x                           0x93BD90
#define CXWndManager__HandleKeyboardMsg_x                          0x93B940
#define CXWndManager__RemoveWnd_x                                  0x93BFB0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93C500

// CDBStr
#define CDBStr__GetString_x                                        0x53C340

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB890
#define EQ_Character__Cur_HP_x                                     0x4D1F40
#define EQ_Character__Cur_Mana_x                                   0x4D9690
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE900
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B23B0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2500
#define EQ_Character__GetHPRegen_x                                 0x4DF460
#define EQ_Character__GetEnduranceRegen_x                          0x4DFA60
#define EQ_Character__GetManaRegen_x                               0x4DFEA0
#define EQ_Character__Max_Endurance_x                              0x64ACC0
#define EQ_Character__Max_HP_x                                     0x4D1D70
#define EQ_Character__Max_Mana_x                                   0x64AAC0
#define EQ_Character__doCombatAbility_x                            0x64D110
#define EQ_Character__UseSkill_x                                   0x4E1C70
#define EQ_Character__GetConLevel_x                                0x643A00
#define EQ_Character__IsExpansionFlag_x                            0x5A7450
#define EQ_Character__TotalEffect_x                                0x4C5350
#define EQ_Character__GetPCSpellAffect_x                           0x4BF650
#define EQ_Character__SpellDuration_x                              0x4BF180
#define EQ_Character__GetAdjustedSkill_x                           0x4D4CC0
#define EQ_Character__GetBaseSkill_x                               0x4D5C60
#define EQ_Character__CanUseItem_x                                 0x4D99A0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CB900

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x661260

//PcClient
#define PcClient__PcClient_x                                       0x641140

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9500
#define CCharacterListWnd__EnterWorld_x                            0x4B8F40
#define CCharacterListWnd__Quit_x                                  0x4B8C90
#define CCharacterListWnd__UpdateList_x                            0x4B90D0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x625B60
#define EQ_Item__CreateItemTagString_x                             0x8A5D80
#define EQ_Item__IsStackable_x                                     0x8AA940
#define EQ_Item__GetImageNum_x                                     0x8A77F0
#define EQ_Item__CreateItemClient_x                                0x624D20
#define EQ_Item__GetItemValue_x                                    0x8A8AE0
#define EQ_Item__ValueSellMerchant_x                               0x8AC190
#define EQ_Item__IsKeyRingItem_x                                   0x8AA240
#define EQ_Item__CanGoInBag_x                                      0x625C80
#define EQ_Item__IsEmpty_x                                         0x8A9D90
#define EQ_Item__GetMaxItemCount_x                                 0x8A8F00
#define EQ_Item__GetHeldItem_x                                     0x8A76C0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A56E0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55A7D0
#define EQ_LoadingS__Array_x                                       0xC27B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64B620
#define EQ_PC__GetAlternateAbilityId_x                             0x8B53F0
#define EQ_PC__GetCombatAbility_x                                  0x8B5A60
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B5AD0
#define EQ_PC__GetItemRecastTimer_x                                0x64D690
#define EQ_PC__HasLoreItem_x                                       0x6441C0
#define EQ_PC__AlertInventoryChanged_x                             0x643340
#define EQ_PC__GetPcZoneClient_x                                   0x66FD80
#define EQ_PC__RemoveMyAffect_x                                    0x6508D0
#define EQ_PC__GetKeyRingItems_x                                   0x8B6360
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B60F0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B6660

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AD9B0
#define EQItemList__add_object_x                                   0x5DB350
#define EQItemList__add_item_x                                     0x5ADF10
#define EQItemList__delete_item_x                                  0x5ADF60
#define EQItemList__FreeItemList_x                                 0x5ADE60

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x538E90

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x662AE0
#define EQPlayer__dEQPlayer_x                                      0x655E20
#define EQPlayer__DoAttack_x                                       0x66AA20
#define EQPlayer__EQPlayer_x                                       0x6564E0
#define EQPlayer__SetNameSpriteState_x                             0x65A7C0
#define EQPlayer__SetNameSpriteTint_x                              0x65B690
#define PlayerBase__HasProperty_j_x                                0x99BBC0
#define EQPlayer__IsTargetable_x                                   0x99C060
#define EQPlayer__CanSee_x                                         0x99BEC0
#define EQPlayer__CanSee1_x                                        0x99BF90
#define PlayerBase__GetVisibilityLineSegment_x                     0x99BC80

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66D820
#define PlayerZoneClient__GetLevel_x                               0x66FDC0
#define PlayerZoneClient__IsValidTeleport_x                        0x5DC4C0
#define PlayerZoneClient__LegalPlayerRace_x                        0x553BC0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6658D0
#define EQPlayerManager__GetSpawnByName_x                          0x665980
#define EQPlayerManager__GetPlayerFromPartialName_x                0x665A10

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6292C0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x629340
#define KeypressHandler__AttachKeyToEqCommand_x                    0x629380
#define KeypressHandler__ClearCommandStateArray_x                  0x62A790
#define KeypressHandler__HandleKeyDown_x                           0x62A7B0
#define KeypressHandler__HandleKeyUp_x                             0x62A850
#define KeypressHandler__SaveKeymapping_x                          0x62ACA0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x782050
#define MapViewMap__SaveEx_x                                       0x785410
#define MapViewMap__SetZoom_x                                      0x789AD0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C9820

// StringTable 
#define StringTable__getString_x                                   0x8C4650

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x650540
#define PcZoneClient__RemovePetEffect_x                            0x650B70
#define PcZoneClient__HasAlternateAbility_x                        0x64A8F0
#define PcZoneClient__GetCurrentMod_x                              0x4E4D30
#define PcZoneClient__GetModCap_x                                  0x4E4C30
#define PcZoneClient__CanEquipItem_x                               0x64AFC0
#define PcZoneClient__GetItemByID_x                                0x64DB10
#define PcZoneClient__GetItemByItemClass_x                         0x64DC60
#define PcZoneClient__RemoveBuffEffect_x                           0x650B90
#define PcZoneClient__BandolierSwap_x                              0x64BBD0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64D630

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E0FE0

//IconCache
#define IconCache__GetIcon_x                                       0x7223C0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x719E90
#define CContainerMgr__CloseContainer_x                            0x71A160
#define CContainerMgr__OpenExperimentContainer_x                   0x71ABE0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7DA1E0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61DC60

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7785D0
#define CLootWnd__RequestLootSlot_x                                0x777800

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57A2C0
#define EQ_Spell__SpellAffects_x                                   0x57A730
#define EQ_Spell__SpellAffectBase_x                                0x57A4F0
#define EQ_Spell__IsStackable_x                                    0x4C9950
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C97A0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B68A0
#define EQ_Spell__IsSPAStacking_x                                  0x57B580
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57AA90
#define EQ_Spell__IsNoRemove_x                                     0x4C9930
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57B590
#define __IsResEffectSpell_x                                       0x4C8D70

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACEE0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D3F70

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x820E20
#define CTargetWnd__WndNotification_x                              0x8206B0
#define CTargetWnd__RefreshTargetBuffs_x                           0x820980
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81F810

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x825440

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x536880
#define CTaskManager__HandleMessage_x                              0x534D10
#define CTaskManager__GetTaskStatus_x                              0x536930
#define CTaskManager__GetElementDescription_x                      0x5369B0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x575810
#define EqSoundManager__PlayScriptMp3_x                            0x575970
#define EqSoundManager__SoundAssistPlay_x                          0x688240
#define EqSoundManager__WaveInstancePlay_x                         0x6877B0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52A5E0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x957A60

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x562220
#define CAltAbilityData__GetMercMaxRank_x                          0x5621B0
#define CAltAbilityData__GetMaxRank_x                              0x557860

//CTargetRing
#define CTargetRing__Cast_x                                        0x61BD80

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9780
#define CharacterBase__CreateItemGlobalIndex_x                     0x511D20
#define CharacterBase__CreateItemIndex_x                           0x623EB0
#define CharacterBase__GetItemPossession_x                         0x4FD560
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DC560
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DC5C0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x701020
#define CCastSpellWnd__IsBardSongPlaying_x                         0x701850
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x701900

//messages
#define msg_spell_worn_off_x                                       0x59F750
#define msg_new_text_x                                             0x594500
#define __msgTokenTextParam_x                                      0x5A1C80
#define msgTokenText_x                                             0x5A1ED0

//SpellManager
#define SpellManager__vftable_x                                    0xAED4D4
#define SpellManager__SpellManager_x                               0x68B570
#define Spellmanager__LoadTextSpells_x                             0x68BE60
#define SpellManager__GetSpellByGroupAndRank_x                     0x68B740

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99FAF0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5123A0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A5A10
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63C900
#define ItemGlobalIndex__IsValidIndex_x                            0x512400

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D4910
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D4B90

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x770DB0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71E5B0
#define CCursorAttachment__AttachToCursor1_x                       0x71E5F0
#define CCursorAttachment__Deactivate_x                            0x71F5E0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x94A710
#define CSidlManagerBase__CreatePageWnd_x                          0x949F00
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x946180
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x946110

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x967990
#define CEQSuiteTextureLoader__GetTexture_x                        0x967650

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50F2C0
#define CFindItemWnd__WndNotification_x                            0x50FDA0
#define CFindItemWnd__Update_x                                     0x510910
#define CFindItemWnd__PickupSelectedItem_x                         0x50EB00

//IString
#define IString__Append_x                                          0x4F0360

//Camera
#define CDisplay__cameraType_x                                     0xE010BC
#define EverQuest__Cameras_x                                       0xEC4A7C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x517A80
#define LootFiltersManager__GetItemFilterData_x                    0x517380
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5173B0
#define LootFiltersManager__SetItemLootFilter_x                    0x5175D0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C8100

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A5690
#define CResolutionHandler__GetWindowedStyle_x                     0x682B60

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x716C60

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E99F0
#define CDistillerInfo__Instance_x                                 0x8E9990

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x736F30
#define CGroupWnd__UpdateDisplay_x                                 0x736280

//ItemBase
#define ItemBase__IsLore_x                                         0x8AA2F0
#define ItemBase__IsLoreEquipped_x                                 0x8AA370

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DB2B0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DB3F0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DB450

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x678500
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67BE70

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x505640

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F1F00
#define FactionManagerClient__HandleFactionMessage_x               0x4F2570
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2B70
#define FactionManagerClient__GetMaxFaction_x                      0x4F2B8F
#define FactionManagerClient__GetMinFaction_x                      0x4F2B40

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FD530

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92EEA0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BD20

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FD7B0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x5616D0

//CTargetManager
#define CTargetManager__Get_x                                      0x68EDD0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x678500

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8BB0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5ADE00

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF62110

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
