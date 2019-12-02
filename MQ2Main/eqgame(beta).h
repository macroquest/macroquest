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
#define __ExpectedVersionDate                                     "Dec  2 2019"
#define __ExpectedVersionTime                                     "04:22:16"
#define __ActualVersionDate_x                                      0xB0A2FC
#define __ActualVersionTime_x                                      0xB0A2F0
#define __ActualVersionBuild_x                                     0xAF5F7C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62F450
#define __MemChecker1_x                                            0x902E40
#define __MemChecker2_x                                            0x6BE070
#define __MemChecker3_x                                            0x6BDFC0
#define __MemChecker4_x                                            0x859890
#define __EncryptPad0_x                                            0xC403E8
#define __EncryptPad1_x                                            0xC9E5E8
#define __EncryptPad2_x                                            0xC50C80
#define __EncryptPad3_x                                            0xC50880
#define __EncryptPad4_x                                            0xC8EC00
#define __EncryptPad5_x                                            0xF6A1C0
#define __AC1_x                                                    0x816956
#define __AC2_x                                                    0x5E92DF
#define __AC3_x                                                    0x5F09DF
#define __AC4_x                                                    0x5F49B0
#define __AC5_x                                                    0x5FACBF
#define __AC6_x                                                    0x5FF2D6
#define __AC7_x                                                    0x5E8D50
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
#define __do_loot_x                                                0x5B4B00
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
#define __gfMaxZoomCameraDistance_x                                0xAFFC18
#define __gfMaxCameraDistance_x                                    0xB2C154
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
#define __CastRay_x                                                0x5AFF60
#define __CastRay2_x                                               0x5AFFB0
#define __ConvertItemTags_x                                        0x5CBB00
#define __CleanItemTags_x                                          0x47D100
#define __DoesFileExist_x                                          0x905ED0
#define __EQGetTime_x                                              0x902910
#define __ExecuteCmd_x                                             0x5A87D0
#define __FixHeading_x                                             0x99D410
#define __GameLoop_x                                               0x6BD260
#define __get_bearing_x                                            0x5AFAD0
#define __get_melee_range_x                                        0x5B01A0
#define __GetAnimationCache_x                                      0x7225B0
#define __GetGaugeValueFromEQ_x                                    0x814E00
#define __GetLabelFromEQ_x                                         0x8168E0
#define __GetXTargetType_x                                         0x99EED0
#define __HandleMouseWheel_x                                       0x6BE120
#define __HeadingDiff_x                                            0x99D480
#define __HelpPath_x                                               0xF627DC
#define __LoadFrontEnd_x                                           0x6BA580
#define __NewUIINI_x                                               0x814AD0
#define __ProcessGameEvents_x                                      0x610B30
#define __ProcessMouseEvent_x                                      0x6102F0
#define __SaveColors_x                                             0x551CA0
#define __STMLToText_x                                             0x940AE0
#define __ToggleKeyRingItem_x                                      0x515590
#define CMemoryMappedFile__SetFile_x                               0xA8C830
#define CrashDetected_x                                            0x6BC020
#define DrawNetStatus_x                                            0x63C730
#define Expansion_HoT_x                                            0xEC472C
#define Teleport_Table_Size_x                                      0xEB3760
#define Teleport_Table_x                                           0xEB3BC8
#define Util__FastTime_x                                           0x9024E0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490330
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499220
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498FF0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4938C0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492D10

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5597F0
#define AltAdvManager__IsAbilityReady_x                            0x558720
#define AltAdvManager__GetAAById_x                                 0x558920
#define AltAdvManager__CanTrainAbility_x                           0x558990
#define AltAdvManager__CanSeeAbility_x                             0x558CF0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA200
#define CharacterZoneClient__HasSkill_x                            0x4D50F0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6810
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE450
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAA50
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D91C0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D92A0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9380
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3250
#define CharacterZoneClient__BardCastBard_x                        0x4C5DB0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAB20
#define CharacterZoneClient__GetEffect_x                           0x4BA990
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C42A0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4370
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C43C0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4510
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C46E0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B28F0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7770
#define CharacterZoneClient__FindItemByRecord_x                    0x4D71F0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E3E00
#define CBankWnd__WndNotification_x                                0x6E3BE0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F1380

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61F240
#define CButtonWnd__CButtonWnd_x                                   0x93CEA0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x711730
#define CChatManager__InitContextMenu_x                            0x70A880
#define CChatManager__FreeChatWindow_x                             0x710270
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E87F0
#define CChatManager__SetLockedActiveChatWindow_x                  0x7113B0
#define CChatManager__CreateChatWindow_x                           0x7108B0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8900

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9514A0
#define CContextMenu__dCContextMenu_x                              0x9516D0
#define CContextMenu__AddMenuItem_x                                0x9516E0
#define CContextMenu__RemoveMenuItem_x                             0x9519F0
#define CContextMenu__RemoveAllMenuItems_x                         0x951A10
#define CContextMenu__CheckMenuItem_x                              0x951A90
#define CContextMenu__SetMenuItem_x                                0x951910
#define CContextMenu__AddSeparator_x                               0x951870

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x952030
#define CContextMenuManager__RemoveMenu_x                          0x9520A0
#define CContextMenuManager__PopupMenu_x                           0x952160
#define CContextMenuManager__Flush_x                               0x951FD0
#define CContextMenuManager__GetMenu_x                             0x49B540
#define CContextMenuManager__CreateDefaultMenu_x                   0x71CDC0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DE120
#define CChatService__GetFriendName_x                              0x8DE130

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x711FE0
#define CChatWindow__Clear_x                                       0x7132A0
#define CChatWindow__WndNotification_x                             0x713A30
#define CChatWindow__AddHistory_x                                  0x712B60

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94E900
#define CComboWnd__Draw_x                                          0x94DE00
#define CComboWnd__GetCurChoice_x                                  0x94E740
#define CComboWnd__GetListRect_x                                   0x94E2B0
#define CComboWnd__GetTextRect_x                                   0x94E970
#define CComboWnd__InsertChoice_x                                  0x94E440
#define CComboWnd__SetColors_x                                     0x94E410
#define CComboWnd__SetChoice_x                                     0x94E710
#define CComboWnd__GetItemCount_x                                  0x94E750
#define CComboWnd__GetCurChoiceText_x                              0x94E790
#define CComboWnd__GetChoiceText_x                                 0x94E760
#define CComboWnd__InsertChoiceAtIndex_x                           0x94E4D0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x71A7B0
#define CContainerWnd__vftable_x                                   0xB134E4
#define CContainerWnd__SetContainer_x                              0x71BD20

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54C6D0
#define CDisplay__PreZoneMainUI_x                                  0x54C6E0
#define CDisplay__CleanGameUI_x                                    0x551A60
#define CDisplay__GetClickedActor_x                                0x5449F0
#define CDisplay__GetUserDefinedColor_x                            0x53D0B0
#define CDisplay__GetWorldFilePath_x                               0x546460
#define CDisplay__is3dON_x                                         0x541650
#define CDisplay__ReloadUI_x                                       0x54BB60
#define CDisplay__WriteTextHD2_x                                   0x541440
#define CDisplay__TrueDistance_x                                   0x548120
#define CDisplay__SetViewActor_x                                   0x544310
#define CDisplay__GetFloorHeight_x                                 0x541710
#define CDisplay__SetRenderWindow_x                                0x540070
#define CDisplay__ToggleScreenshotMode_x                           0x543DE0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x971020

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9549EF
#define CEditWnd__GetCharIndexPt_x                                 0x955920
#define CEditWnd__GetDisplayString_x                               0x9557C0
#define CEditWnd__GetHorzOffset_x                                  0x954030
#define CEditWnd__GetLineForPrintableChar_x                        0x956AC0
#define CEditWnd__GetSelStartPt_x                                  0x955BD0
#define CEditWnd__GetSTMLSafeText_x                                0x9555E0
#define CEditWnd__PointFromPrintableChar_x                         0x9566F0
#define CEditWnd__SelectableCharFromPoint_x                        0x956860
#define CEditWnd__SetEditable_x                                    0x955CA0
#define CEditWnd__SetWindowTextA_x                                 0x955360

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FE7B0
#define CEverQuest__ClickedPlayer_x                                0x5F07C0
#define CEverQuest__CreateTargetIndicator_x                        0x60DDD0
#define CEverQuest__DeleteTargetIndicator_x                        0x60DE60
#define CEverQuest__DoTellWindow_x                                 0x4E89E0
#define CEverQuest__OutputTextToLog_x                              0x4E8C60
#define CEverQuest__DropHeldItemOnGround_x                         0x5E5800
#define CEverQuest__dsp_chat_x                                     0x4E8FF0
#define CEverQuest__trimName_x                                     0x60A0C0
#define CEverQuest__Emote_x                                        0x5FF010
#define CEverQuest__EnterZone_x                                    0x5F8F90
#define CEverQuest__GetBodyTypeDesc_x                              0x603980
#define CEverQuest__GetClassDesc_x                                 0x603FC0
#define CEverQuest__GetClassThreeLetterCode_x                      0x6045C0
#define CEverQuest__GetDeityDesc_x                                 0x60C710
#define CEverQuest__GetLangDesc_x                                  0x604780
#define CEverQuest__GetRaceDesc_x                                  0x603FA0
#define CEverQuest__InterpretCmd_x                                 0x60CCE0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E9A00
#define CEverQuest__LMouseUp_x                                     0x5E7D90
#define CEverQuest__RightClickedOnPlayer_x                         0x5EA2E0
#define CEverQuest__RMouseUp_x                                     0x5E8D10
#define CEverQuest__SetGameState_x                                 0x5E5590
#define CEverQuest__UPCNotificationFlush_x                         0x609FC0
#define CEverQuest__IssuePetCommand_x                              0x605B80
#define CEverQuest__ReportSuccessfulHit_x                          0x600400

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72C7A0
#define CGaugeWnd__CalcLinesFillRect_x                             0x72C800
#define CGaugeWnd__Draw_x                                          0x72BE20

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF320
#define CGuild__GetGuildName_x                                     0x4AE400
#define CGuild__GetGuildIndex_x                                    0x4AE790

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x747BE0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61F600

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x754B80
#define CInvSlotMgr__MoveItem_x                                    0x7538E0
#define CInvSlotMgr__SelectSlot_x                                  0x754C50

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x752160
#define CInvSlot__SliderComplete_x                                 0x74FEB0
#define CInvSlot__GetItemBase_x                                    0x74F840
#define CInvSlot__UpdateItem_x                                     0x74F9B0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7566B0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x755850
#define CInvSlotWnd__HandleLButtonUp_x                             0x756230

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x810110
#define CItemDisplayWnd__UpdateStrings_x                           0x764CA0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75EA00
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75EF20
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7652A0
#define CItemDisplayWnd__AboutToShow_x                             0x764900
#define CItemDisplayWnd__WndNotification_x                         0x766370
#define CItemDisplayWnd__RequestConvertItem_x                      0x765E40
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x763970
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x764720

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8489F0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x76A8C0

// CLabel 
#define CLabel__Draw_x                                             0x770350

// CListWnd
#define CListWnd__CListWnd_x                                       0x927110
#define CListWnd__dCListWnd_x                                      0x927430
#define CListWnd__AddColumn_x                                      0x92B8A0
#define CListWnd__AddColumn1_x                                     0x92B8F0
#define CListWnd__AddLine_x                                        0x92BC80
#define CListWnd__AddString_x                                      0x92BA80
#define CListWnd__CalculateFirstVisibleLine_x                      0x92B660
#define CListWnd__CalculateVSBRange_x                              0x92B440
#define CListWnd__ClearSel_x                                       0x92C460
#define CListWnd__ClearAllSel_x                                    0x92C4C0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92CEE0
#define CListWnd__Compare_x                                        0x92AD80
#define CListWnd__Draw_x                                           0x927560
#define CListWnd__DrawColumnSeparators_x                           0x929D50
#define CListWnd__DrawHeader_x                                     0x92A1C0
#define CListWnd__DrawItem_x                                       0x92A6C0
#define CListWnd__DrawLine_x                                       0x929EC0
#define CListWnd__DrawSeparator_x                                  0x929DF0
#define CListWnd__EnableLine_x                                     0x929620
#define CListWnd__EnsureVisible_x                                  0x92CE00
#define CListWnd__ExtendSel_x                                      0x92C390
#define CListWnd__GetColumnTooltip_x                               0x929160
#define CListWnd__GetColumnMinWidth_x                              0x9291D0
#define CListWnd__GetColumnWidth_x                                 0x9290D0
#define CListWnd__GetCurSel_x                                      0x928A60
#define CListWnd__GetItemAtPoint_x                                 0x9298A0
#define CListWnd__GetItemAtPoint1_x                                0x929910
#define CListWnd__GetItemData_x                                    0x928AE0
#define CListWnd__GetItemHeight_x                                  0x928EA0
#define CListWnd__GetItemIcon_x                                    0x928C70
#define CListWnd__GetItemRect_x                                    0x929710
#define CListWnd__GetItemText_x                                    0x928B20
#define CListWnd__GetSelList_x                                     0x92C510
#define CListWnd__GetSeparatorRect_x                               0x929B50
#define CListWnd__InsertLine_x                                     0x92C070
#define CListWnd__RemoveLine_x                                     0x92C1C0
#define CListWnd__SetColors_x                                      0x92B420
#define CListWnd__SetColumnJustification_x                         0x92B150
#define CListWnd__SetColumnWidth_x                                 0x92B070
#define CListWnd__SetCurSel_x                                      0x92C2D0
#define CListWnd__SetItemColor_x                                   0x92CAB0
#define CListWnd__SetItemData_x                                    0x92CA70
#define CListWnd__SetItemText_x                                    0x92C680
#define CListWnd__ShiftColumnSeparator_x                           0x92B210
#define CListWnd__Sort_x                                           0x92AF00
#define CListWnd__ToggleSel_x                                      0x92C300
#define CListWnd__SetColumnsSizable_x                              0x92B2C0
#define CListWnd__SetItemWnd_x                                     0x92C930
#define CListWnd__GetItemWnd_x                                     0x928CC0
#define CListWnd__SetItemIcon_x                                    0x92C700
#define CListWnd__CalculateCustomWindowPositions_x                 0x92B760
#define CListWnd__SetVScrollPos_x                                  0x92B050

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x785AB0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7841C0
#define CMapViewWnd__HandleLButtonDown_x                           0x781200

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A5AC0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A63A0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A68D0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A9850
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A4630
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AF410
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A56E0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8ABC30
#define CPacketScrambler__hton_x                                   0x8ABC20

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x946100
#define CSidlManager__FindScreenPieceTemplate_x                    0x946510
#define CSidlManager__FindScreenPieceTemplate1_x                   0x946300
#define CSidlManager__CreateLabel_x                                0x807550
#define CSidlManager__CreateXWndFromTemplate_x                     0x949470
#define CSidlManager__CreateXWndFromTemplate1_x                    0x949650
#define CSidlManager__CreateXWnd_x                                 0x807480
#define CSidlManager__CreateHotButtonWnd_x                         0x807A50

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x942BE0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x942AE0
#define CSidlScreenWnd__ConvertToRes_x                             0x968070
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x942570
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x942260
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x942330
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x942400
#define CSidlScreenWnd__DrawSidlPiece_x                            0x943080
#define CSidlScreenWnd__EnableIniStorage_x                         0x943550
#define CSidlScreenWnd__GetSidlPiece_x                             0x943270
#define CSidlScreenWnd__Init1_x                                    0x941E80
#define CSidlScreenWnd__LoadIniInfo_x                              0x9435A0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9440E0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x941290
#define CSidlScreenWnd__StoreIniInfo_x                             0x943C60
#define CSidlScreenWnd__StoreIniVis_x                              0x943FC0
#define CSidlScreenWnd__WndNotification_x                          0x942F90
#define CSidlScreenWnd__GetChildItem_x                             0x9434D0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x932CC0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F8F50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x684170
#define CSkillMgr__GetSkillCap_x                                   0x684350
#define CSkillMgr__GetNameToken_x                                  0x6838F0
#define CSkillMgr__IsActivatedSkill_x                              0x683A30
#define CSkillMgr__IsCombatSkill_x                                 0x683970

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x952E00
#define CSliderWnd__SetValue_x                                     0x952C70
#define CSliderWnd__SetNumTicks_x                                  0x952CD0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80D5A0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95B630
#define CStmlWnd__CalculateHSBRange_x                              0x95C750
#define CStmlWnd__CalculateVSBRange_x                              0x95C6D0
#define CStmlWnd__CanBreakAtCharacter_x                            0x960A90
#define CStmlWnd__FastForwardToEndOfTag_x                          0x961720
#define CStmlWnd__ForceParseNow_x                                  0x95BC20
#define CStmlWnd__GetNextTagPiece_x                                0x9609F0
#define CStmlWnd__GetSTMLText_x                                    0x504BE0
#define CStmlWnd__GetVisibleText_x                                 0x95BC40
#define CStmlWnd__InitializeWindowVariables_x                      0x961570
#define CStmlWnd__MakeStmlColorTag_x                               0x95ACA0
#define CStmlWnd__MakeWndNotificationTag_x                         0x95AD10
#define CStmlWnd__SetSTMLText_x                                    0x959D50
#define CStmlWnd__StripFirstSTMLLines_x                            0x962820
#define CStmlWnd__UpdateHistoryString_x                            0x961930

// CTabWnd 
#define CTabWnd__Draw_x                                            0x958E80
#define CTabWnd__DrawCurrentPage_x                                 0x9595B0
#define CTabWnd__DrawTab_x                                         0x9592D0
#define CTabWnd__GetCurrentPage_x                                  0x958680
#define CTabWnd__GetPageInnerRect_x                                0x9588C0
#define CTabWnd__GetTabInnerRect_x                                 0x958800
#define CTabWnd__GetTabRect_x                                      0x9586B0
#define CTabWnd__InsertPage_x                                      0x958AD0
#define CTabWnd__SetPage_x                                         0x958940
#define CTabWnd__SetPageRect_x                                     0x958DC0
#define CTabWnd__UpdatePage_x                                      0x959190
#define CTabWnd__GetPageFromTabIndex_x                             0x959210
#define CTabWnd__GetCurrentTabIndex_x                              0x958670

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x76ACD0
#define CPageWnd__SetTabText_x                                     0x9581D0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9020

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92FB30
#define CTextureFont__GetTextExtent_x                              0x92FCF0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B7400
#define CHtmlComponentWnd__ValidateUri_x                           0x7495D0
#define CHtmlWnd__SetClientCallbacks_x                             0x624680
#define CHtmlWnd__AddObserver_x                                    0x6246A0
#define CHtmlWnd__RemoveObserver_x                                 0x624700
#define Window__getProgress_x                                      0x860ED0
#define Window__getStatus_x                                        0x860EF0
#define Window__getURI_x                                           0x860F00

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96DAB0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91CC10

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8630
#define CXStr__CXStr1_x                                            0x4B6370
#define CXStr__CXStr3_x                                            0x8FEA10
#define CXStr__dCXStr_x                                            0x4786B0
#define CXStr__operator_equal_x                                    0x8FEC40
#define CXStr__operator_equal1_x                                   0x8FEC80
#define CXStr__operator_plus_equal1_x                              0x8FF710
#define CXStr__SetString_x                                         0x901600
#define CXStr__operator_char_p_x                                   0x8FF180
#define CXStr__GetChar_x                                           0x900F50
#define CXStr__Delete_x                                            0x900800
#define CXStr__GetUnicode_x                                        0x900FC0
#define CXStr__GetLength_x                                         0x4A8DD0
#define CXStr__Mid_x                                               0x47D4B0
#define CXStr__Insert_x                                            0x901020
#define CXStr__FindNext_x                                          0x900C70

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9510C0
#define CXWnd__BringToTop_x                                        0x936470
#define CXWnd__Center_x                                            0x935FF0
#define CXWnd__ClrFocus_x                                          0x935E00
#define CXWnd__Destroy_x                                           0x935EB0
#define CXWnd__DoAllDrawing_x                                      0x932460
#define CXWnd__DrawChildren_x                                      0x932430
#define CXWnd__DrawColoredRect_x                                   0x9328C0
#define CXWnd__DrawTooltip_x                                       0x930F60
#define CXWnd__DrawTooltipAtPoint_x                                0x931020
#define CXWnd__GetBorderFrame_x                                    0x932720
#define CXWnd__GetChildWndAt_x                                     0x936510
#define CXWnd__GetClientClipRect_x                                 0x9346D0
#define CXWnd__GetScreenClipRect_x                                 0x9347A0
#define CXWnd__GetScreenRect_x                                     0x934960
#define CXWnd__GetTooltipRect_x                                    0x932910
#define CXWnd__GetWindowTextA_x                                    0x49CC10
#define CXWnd__IsActive_x                                          0x933030
#define CXWnd__IsDescendantOf_x                                    0x935350
#define CXWnd__IsReallyVisible_x                                   0x935380
#define CXWnd__IsType_x                                            0x936B90
#define CXWnd__Move_x                                              0x9353F0
#define CXWnd__Move1_x                                             0x9354A0
#define CXWnd__ProcessTransition_x                                 0x935FA0
#define CXWnd__Refade_x                                            0x935780
#define CXWnd__Resize_x                                            0x935A10
#define CXWnd__Right_x                                             0x936230
#define CXWnd__SetFocus_x                                          0x935DC0
#define CXWnd__SetFont_x                                           0x935E30
#define CXWnd__SetKeyTooltip_x                                     0x9369A0
#define CXWnd__SetMouseOver_x                                      0x933860
#define CXWnd__StartFade_x                                         0x935230
#define CXWnd__GetChildItem_x                                      0x936680
#define CXWnd__SetParent_x                                         0x935100
#define CXWnd__Minimize_x                                          0x935A80

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9690F0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9393B0
#define CXWndManager__DrawWindows_x                                0x9393D0
#define CXWndManager__GetKeyboardFlags_x                           0x93BA90
#define CXWndManager__HandleKeyboardMsg_x                          0x93B640
#define CXWndManager__RemoveWnd_x                                  0x93BCC0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93C230

// CDBStr
#define CDBStr__GetString_x                                        0x53C080

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBA30
#define EQ_Character__Cur_HP_x                                     0x4D2130
#define EQ_Character__Cur_Mana_x                                   0x4D9880
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEAA0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2530
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2680
#define EQ_Character__GetHPRegen_x                                 0x4DF650
#define EQ_Character__GetEnduranceRegen_x                          0x4DFC50
#define EQ_Character__GetManaRegen_x                               0x4E0090
#define EQ_Character__Max_Endurance_x                              0x64A850
#define EQ_Character__Max_HP_x                                     0x4D1F60
#define EQ_Character__Max_Mana_x                                   0x64A650
#define EQ_Character__doCombatAbility_x                            0x64CCB0
#define EQ_Character__UseSkill_x                                   0x4E1E70
#define EQ_Character__GetConLevel_x                                0x643610
#define EQ_Character__IsExpansionFlag_x                            0x5A6F90
#define EQ_Character__TotalEffect_x                                0x4C54F0
#define EQ_Character__GetPCSpellAffect_x                           0x4BF7F0
#define EQ_Character__SpellDuration_x                              0x4BF320
#define EQ_Character__GetAdjustedSkill_x                           0x4D4EB0
#define EQ_Character__GetBaseSkill_x                               0x4D5E50
#define EQ_Character__CanUseItem_x                                 0x4D9B90

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CAFA0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x661190

//PcClient
#define PcClient__PcClient_x                                       0x640D50

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B96A0
#define CCharacterListWnd__EnterWorld_x                            0x4B90E0
#define CCharacterListWnd__Quit_x                                  0x4B8E30
#define CCharacterListWnd__UpdateList_x                            0x4B9270

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6258C0
#define EQ_Item__CreateItemTagString_x                             0x8A5440
#define EQ_Item__IsStackable_x                                     0x8A9FC0
#define EQ_Item__GetImageNum_x                                     0x8A6EB0
#define EQ_Item__CreateItemClient_x                                0x624A80
#define EQ_Item__GetItemValue_x                                    0x8A81C0
#define EQ_Item__ValueSellMerchant_x                               0x8AB800
#define EQ_Item__IsKeyRingItem_x                                   0x8A98C0
#define EQ_Item__CanGoInBag_x                                      0x6259E0
#define EQ_Item__IsEmpty_x                                         0x8A9410
#define EQ_Item__GetMaxItemCount_x                                 0x8A85E0
#define EQ_Item__GetHeldItem_x                                     0x8A6D80
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A4DB0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55A540
#define EQ_LoadingS__Array_x                                       0xC27B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64B1B0
#define EQ_PC__GetAlternateAbilityId_x                             0x8B4A50
#define EQ_PC__GetCombatAbility_x                                  0x8B50C0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B5130
#define EQ_PC__GetItemRecastTimer_x                                0x64D230
#define EQ_PC__HasLoreItem_x                                       0x643DD0
#define EQ_PC__AlertInventoryChanged_x                             0x642F50
#define EQ_PC__GetPcZoneClient_x                                   0x66FCB0
#define EQ_PC__RemoveMyAffect_x                                    0x650470
#define EQ_PC__GetKeyRingItems_x                                   0x8B59C0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B5750
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B5CC0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AD4E0
#define EQItemList__add_object_x                                   0x5DAF90
#define EQItemList__add_item_x                                     0x5ADA40
#define EQItemList__delete_item_x                                  0x5ADA90
#define EQItemList__FreeItemList_x                                 0x5AD990

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x538B70

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x662A10
#define EQPlayer__dEQPlayer_x                                      0x655940
#define EQPlayer__DoAttack_x                                       0x66A940
#define EQPlayer__EQPlayer_x                                       0x656000
#define EQPlayer__SetNameSpriteState_x                             0x65A700
#define EQPlayer__SetNameSpriteTint_x                              0x65B5C0
#define PlayerBase__HasProperty_j_x                                0x99B820
#define EQPlayer__IsTargetable_x                                   0x99BCC0
#define EQPlayer__CanSee_x                                         0x99BB20
#define EQPlayer__CanSee1_x                                        0x99BBF0
#define PlayerBase__GetVisibilityLineSegment_x                     0x99B8E0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66D740
#define PlayerZoneClient__GetLevel_x                               0x66FCF0
#define PlayerZoneClient__IsValidTeleport_x                        0x5DC100
#define PlayerZoneClient__LegalPlayerRace_x                        0x5538F0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x665860
#define EQPlayerManager__GetSpawnByName_x                          0x665910
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6659A0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x628FC0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x629040
#define KeypressHandler__AttachKeyToEqCommand_x                    0x629080
#define KeypressHandler__ClearCommandStateArray_x                  0x62A490
#define KeypressHandler__HandleKeyDown_x                           0x62A4B0
#define KeypressHandler__HandleKeyUp_x                             0x62A550
#define KeypressHandler__SaveKeymapping_x                          0x62A9A0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x781920
#define MapViewMap__SaveEx_x                                       0x784CE0
#define MapViewMap__SetZoom_x                                      0x7893A0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C8E10

// StringTable 
#define StringTable__getString_x                                   0x8C3C60

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6500E0
#define PcZoneClient__RemovePetEffect_x                            0x650710
#define PcZoneClient__HasAlternateAbility_x                        0x64A480
#define PcZoneClient__GetCurrentMod_x                              0x4E4F20
#define PcZoneClient__GetModCap_x                                  0x4E4E20
#define PcZoneClient__CanEquipItem_x                               0x64AB50
#define PcZoneClient__GetItemByID_x                                0x64D6B0
#define PcZoneClient__GetItemByItemClass_x                         0x64D800
#define PcZoneClient__RemoveBuffEffect_x                           0x650730
#define PcZoneClient__BandolierSwap_x                              0x64B770
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64D1D0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E0C80

//IconCache
#define IconCache__GetIcon_x                                       0x721E50

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x719950
#define CContainerMgr__CloseContainer_x                            0x719C20
#define CContainerMgr__OpenExperimentContainer_x                   0x71A6A0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D9AE0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61DA00

//CLootWnd
#define CLootWnd__LootAll_x                                        0x777E20
#define CLootWnd__RequestLootSlot_x                                0x777050

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57A1F0
#define EQ_Spell__SpellAffects_x                                   0x57A660
#define EQ_Spell__SpellAffectBase_x                                0x57A420
#define EQ_Spell__IsStackable_x                                    0x4C9B60
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C99E0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6A30
#define EQ_Spell__IsSPAStacking_x                                  0x57B4B0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57A9C0
#define EQ_Spell__IsNoRemove_x                                     0x4C9B40
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57B4C0
#define __IsResEffectSpell_x                                       0x4C8F10

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD060

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D35E0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8208E0
#define CTargetWnd__WndNotification_x                              0x820170
#define CTargetWnd__RefreshTargetBuffs_x                           0x820440
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81F2E0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x824ED0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x536570
#define CTaskManager__HandleMessage_x                              0x534A00
#define CTaskManager__GetTaskStatus_x                              0x536620
#define CTaskManager__GetElementDescription_x                      0x5366A0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x575760
#define EqSoundManager__PlayScriptMp3_x                            0x5758C0
#define EqSoundManager__SoundAssistPlay_x                          0x6880D0
#define EqSoundManager__WaveInstancePlay_x                         0x687640

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52A300

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9576E0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x561F20
#define CAltAbilityData__GetMercMaxRank_x                          0x561EB0
#define CAltAbilityData__GetMaxRank_x                              0x5575A0

//CTargetRing
#define CTargetRing__Cast_x                                        0x61BB20

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C99C0
#define CharacterBase__CreateItemGlobalIndex_x                     0x511C40
#define CharacterBase__CreateItemIndex_x                           0x623C30
#define CharacterBase__GetItemPossession_x                         0x4FD6E0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DBBF0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DBC50
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x700B10
#define CCastSpellWnd__IsBardSongPlaying_x                         0x701340
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x7013F0

//messages
#define msg_spell_worn_off_x                                       0x59F0E0
#define msg_new_text_x                                             0x593E70
#define __msgTokenTextParam_x                                      0x5A1610
#define msgTokenText_x                                             0x5A1860

//SpellManager
#define SpellManager__vftable_x                                    0xAED4D4
#define SpellManager__SpellManager_x                               0x68B400
#define Spellmanager__LoadTextSpells_x                             0x68BCF0
#define SpellManager__GetSpellByGroupAndRank_x                     0x68B5D0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99F7C0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x512290
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A53B0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63C590
#define ItemGlobalIndex__IsValidIndex_x                            0x5122F0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D3F80
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D4200

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x770690

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71E050
#define CCursorAttachment__AttachToCursor1_x                       0x71E090
#define CCursorAttachment__Deactivate_x                            0x71F080

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x94A4B0
#define CSidlManagerBase__CreatePageWnd_x                          0x949CA0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x945F20
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x945EB0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x967430
#define CEQSuiteTextureLoader__GetTexture_x                        0x9670F0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50F1E0
#define CFindItemWnd__WndNotification_x                            0x50FCC0
#define CFindItemWnd__Update_x                                     0x510830
#define CFindItemWnd__PickupSelectedItem_x                         0x50EA20

//IString
#define IString__Append_x                                          0x4F0520

//Camera
#define CDisplay__cameraType_x                                     0xE010BC
#define EverQuest__Cameras_x                                       0xEC4A7C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x517930
#define LootFiltersManager__GetItemFilterData_x                    0x517240
#define LootFiltersManager__RemoveItemLootFilter_x                 0x517270
#define LootFiltersManager__SetItemLootFilter_x                    0x517490

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C7A60

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A5390
#define CResolutionHandler__GetWindowedStyle_x                     0x682BC0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x716740

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E8F40
#define CDistillerInfo__Instance_x                                 0x8E8EE0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7369C0
#define CGroupWnd__UpdateDisplay_x                                 0x735D20

//ItemBase
#define ItemBase__IsLore_x                                         0x8A9970
#define ItemBase__IsLoreEquipped_x                                 0x8A99F0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DAEF0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DB030
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DB090

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6783B0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67BD40

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x505580

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F2050
#define FactionManagerClient__HandleFactionMessage_x               0x4F26C0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2CC0
#define FactionManagerClient__GetMaxFaction_x                      0x4F2CDF
#define FactionManagerClient__GetMinFaction_x                      0x4F2C90

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FD6B0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92EB80

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BF20

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FD930

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x5613F0

//CTargetManager
#define CTargetManager__Get_x                                      0x68EC20

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6783B0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8DE0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AD930

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF62110

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
