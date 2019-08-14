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
#if defined(TEST)
#include "eqgame-private(test).h"
#endif
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Aug 12 2019"
#define __ExpectedVersionTime                                     "19:04:55"
#define __ActualVersionDate_x                                      0xAE650C
#define __ActualVersionTime_x                                      0xAE6500
#define __ActualVersionBuild_x                                     0xAE6FA4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x61D290
#define __MemChecker1_x                                            0x8F4910
#define __MemChecker2_x                                            0x6AC760
#define __MemChecker3_x                                            0x6AC6B0
#define __MemChecker4_x                                            0x84B4E0
#define __EncryptPad0_x                                            0xC1C990
#define __EncryptPad1_x                                            0xC7A9B8
#define __EncryptPad2_x                                            0xC2D208
#define __EncryptPad3_x                                            0xC2CE08
#define __EncryptPad4_x                                            0xC6B180
#define __EncryptPad5_x                                            0x104E718
#define __AC1_x                                                    0x808086
#define __AC2_x                                                    0x5D6EFF
#define __AC3_x                                                    0x5DE60F
#define __AC4_x                                                    0x5E24F0
#define __AC5_x                                                    0x5E8840
#define __AC6_x                                                    0x5ECE06
#define __AC7_x                                                    0x5D6970
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E9B25C

// Direct Input
#define DI8__Main_x                                                0x104E738
#define DI8__Keyboard_x                                            0x104E73C
#define DI8__Mouse_x                                               0xF43658
#define DI8__Mouse_Copy_x                                          0xE9ED34
#define DI8__Mouse_Check_x                                         0xF43990
#define __AutoSkillArray_x                                         0xE9FC4C
#define __Attack_x                                                 0xF3DA63
#define __Autofire_x                                               0xF3DA64
#define __BindList_x                                               0xC0B3E8
#define g_eqCommandStates_x                                        0xC0C160
#define __Clicks_x                                                 0xE9EDEC
#define __CommandList_x                                            0xC0CD20
#define __CurrentMapLabel_x                                        0x105EB0C
#define __CurrentSocial_x                                          0xBF5730
#define __DoAbilityList_x                                          0xED5584
#define __do_loot_x                                                0x5A2FF0
#define __DrawHandler_x                                            0x16DB4E0
#define __GroupCount_x                                             0xE8EFE2
#define __Guilds_x                                                 0xE95540
#define __gWorld_x                                                 0xE918C8
#define __HWnd_x                                                   0xF4365C
#define __heqmain_x                                                0x104DC78
#define __InChatMode_x                                             0xE9ED1C
#define __LastTell_x                                               0xEA0C80
#define __LMouseHeldTime_x                                         0xE9EE58
#define __Mouse_x                                                  0x104E724
#define __MouseLook_x                                              0xE9EDB2
#define __MouseEventTime_x                                         0xF3E544
#define __gpbCommandEvent_x                                        0xE913B4
#define __NetStatusToggle_x                                        0xE9EDB5
#define __PCNames_x                                                0xEA0230
#define __RangeAttackReady_x                                       0xE9FF30
#define __RMouseHeldTime_x                                         0xE9EE54
#define __RunWalkState_x                                           0xE9ED20
#define __ScreenMode_x                                             0xDDD174
#define __ScreenX_x                                                0xE9ECD4
#define __ScreenY_x                                                0xE9ECD0
#define __ScreenXMax_x                                             0xE9ECD8
#define __ScreenYMax_x                                             0xE9ECDC
#define __ServerHost_x                                             0xE9159B
#define __ServerName_x                                             0xED5544
#define __ShiftKeyDown_x                                           0xE9F3AC
#define __ShowNames_x                                              0xEA00EC
#define __Socials_x                                                0xED5644
#define __SubscriptionType_x                                       0x10A06A0
#define __TargetAggroHolder_x                                      0x10614C0
#define __ZoneType_x                                               0xE9F1B0
#define __GroupAggro_x                                             0x1061500
#define __LoginName_x                                              0x104E3BC
#define __Inviter_x                                                0xF3D9E0
#define __AttackOnAssist_x                                         0xEA00A8
#define __UseTellWindows_x                                         0xEA03CC
#define __gfMaxZoomCameraDistance_x                                0xADB988
#define __gfMaxCameraDistance_x                                    0xB08F94
#define __pulAutoRun_x                                             0xE9EDD0
#define __pulForward_x                                             0xEA0404
#define __pulBackward_x                                            0xEA0408
#define __pulTurnRight_x                                           0xEA040C
#define __pulTurnLeft_x                                            0xEA0410
#define __pulStrafeLeft_x                                          0xEA0414
#define __pulStrafeRight_x                                         0xEA0418

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE918D8
#define instEQZoneInfo_x                                           0xE9EFA8
#define pinstActiveBanker_x                                        0xE8F358
#define pinstActiveCorpse_x                                        0xE8F350
#define pinstActiveGMaster_x                                       0xE8F354
#define pinstActiveMerchant_x                                      0xE8F34C
#define pinstAltAdvManager_x                                       0xDDDBA0
#define pinstBandageTarget_x                                       0xE8F368
#define pinstCamActor_x                                            0xDDD164
#define pinstCDBStr_x                                              0xDDC8CC
#define pinstCDisplay_x                                            0xE918D0
#define pinstCEverQuest_x                                          0x104CC68
#define pinstEverQuestInfo_x                                       0xE9ECC8
#define pinstCharData_x                                            0xE9148C
#define pinstCharSpawn_x                                           0xE8F3A0
#define pinstControlledMissile_x                                   0xE913B8
#define pinstControlledPlayer_x                                    0xE8F3A0
#define pinstCResolutionHandler_x                                  0x16DB710
#define pinstCSidlManager_x                                        0x16DA6AC
#define pinstCXWndManager_x                                        0x16DA6A0
#define instDynamicZone_x                                          0xE95418
#define pinstDZMember_x                                            0xE95528
#define pinstDZTimerInfo_x                                         0xE9552C
#define pinstEqLogin_x                                             0x104DD08
#define instEQMisc_x                                               0xDDC810
#define pinstEQSoundManager_x                                      0xDDEAC8
#define pinstEQSpellStrings_x                                      0xC9F5A0
#define instExpeditionLeader_x                                     0xE95462
#define instExpeditionName_x                                       0xE954A2
#define pinstGroup_x                                               0xE8EFDE
#define pinstImeManager_x                                          0x16DA6A4
#define pinstLocalPlayer_x                                         0xE8F348
#define pinstMercenaryData_x                                       0xF40030
#define pinstMercenaryStats_x                                      0x106160C
#define pinstModelPlayer_x                                         0xE8F360
#define pinstPCData_x                                              0xE9148C
#define pinstSkillMgr_x                                            0xF421A8
#define pinstSpawnManager_x                                        0xF40C50
#define pinstSpellManager_x                                        0xF423C8
#define pinstSpellSets_x                                           0xF3668C
#define pinstStringTable_x                                         0xE8EFCC
#define pinstSwitchManager_x                                       0xE8EE78
#define pinstTarget_x                                              0xE8F39C
#define pinstTargetObject_x                                        0xE8F3A8
#define pinstTargetSwitch_x                                        0xE91488
#define pinstTaskMember_x                                          0xDDC6A0
#define pinstTrackTarget_x                                         0xE8F3A4
#define pinstTradeTarget_x                                         0xE8F35C
#define instTributeActive_x                                        0xDDC831
#define pinstViewActor_x                                           0xDDD160
#define pinstWorldData_x                                           0xE918CC
#define pinstZoneAddr_x                                            0xE9F248
#define pinstPlayerPath_x                                          0xF40CE8
#define pinstTargetIndicator_x                                     0xF42630
#define EQObject_Top_x                                             0xE8F344
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDDD138
#define pinstCAchievementsWnd_x                                    0xDDD1A4
#define pinstCActionsWnd_x                                         0xDDD1BC
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDDC974
#define pinstCAdvancedLootWnd_x                                    0xDDD1B4
#define pinstCAdventureLeaderboardWnd_x                            0x10582E0
#define pinstCAdventureRequestWnd_x                                0x1058390
#define pinstCAdventureStatsWnd_x                                  0x1058440
#define pinstCAggroMeterWnd_x                                      0xDDD034
#define pinstCAlarmWnd_x                                           0xDDD0A8
#define pinstCAlertHistoryWnd_x                                    0xDDD154
#define pinstCAlertStackWnd_x                                      0xDDD0CC
#define pinstCAlertWnd_x                                           0xDDD0E4
#define pinstCAltStorageWnd_x                                      0x10587A0
#define pinstCAudioTriggersWindow_x                                0xC918D0
#define pinstCAuraWnd_x                                            0xDDD02C
#define pinstCAvaZoneWnd_x                                         0xDDD158
#define pinstCBandolierWnd_x                                       0xDDD074
#define pinstCBankWnd_x                                            0xDDD0E8
#define pinstCBarterMerchantWnd_x                                  0x10599E0
#define pinstCBarterSearchWnd_x                                    0x1059A90
#define pinstCBarterWnd_x                                          0x1059B40
#define pinstCBazaarConfirmationWnd_x                              0xDDD0C8
#define pinstCBazaarSearchWnd_x                                    0xDDD1F0
#define pinstCBazaarWnd_x                                          0xDDD08C
#define pinstCBlockedBuffWnd_x                                     0xDDD0D4
#define pinstCBlockedPetBuffWnd_x                                  0xDDD0F8
#define pinstCBodyTintWnd_x                                        0xDDCB98
#define pinstCBookWnd_x                                            0xDDD094
#define pinstCBreathWnd_x                                          0xDDD14C
#define pinstCBuffWindowNORMAL_x                                   0xDDD0B4
#define pinstCBuffWindowSHORT_x                                    0xDDD0B8
#define pinstCBugReportWnd_x                                       0xDDD144
#define pinstCButtonWnd_x                                          0x16DA910
#define pinstCCastingWnd_x                                         0xDDD134
#define pinstCCastSpellWnd_x                                       0xDDD1F8
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDDD148
#define pinstCChatWindowManager_x                                  0x105A600
#define pinstCClaimWnd_x                                           0x105A758
#define pinstCColorPickerWnd_x                                     0xDDD19C
#define pinstCCombatAbilityWnd_x                                   0xDDD038
#define pinstCCombatSkillsSelectWnd_x                              0xDDD1B8
#define pinstCCompassWnd_x                                         0xDDCB84
#define pinstCConfirmationDialog_x                                 0x105F658
#define pinstCContainerMgr_x                                       0xDDD128
#define pinstCContextMenuManager_x                                 0x16DA660
#define pinstCCursorAttachment_x                                   0xDDD120
#define pinstCDynamicZoneWnd_x                                     0x105AD20
#define pinstCEditLabelWnd_x                                       0xDDD09C
#define pinstCEQMainWnd_x                                          0x105AF68
#define pinstCEventCalendarWnd_x                                   0xDDD1EC
#define pinstCExtendedTargetWnd_x                                  0xDDCBA4
#define pinstCFacePick_x                                           0xDDD188
#define pinstCFactionWnd_x                                         0xDDD130
#define pinstCFellowshipWnd_x                                      0x105B168
#define pinstCFileSelectionWnd_x                                   0xDDD1A8
#define pinstCFindItemWnd_x                                        0xDDD0A0
#define pinstCFindLocationWnd_x                                    0x105B2C0
#define pinstCFriendsWnd_x                                         0xDDD1DC
#define pinstCGemsGameWnd_x                                        0xDDD088
#define pinstCGiveWnd_x                                            0xDDD0A4
#define pinstCGroupSearchFiltersWnd_x                              0xDDD044
#define pinstCGroupSearchWnd_x                                     0x105B6B8
#define pinstCGroupWnd_x                                           0x105B768
#define pinstCGuildBankWnd_x                                       0xEA008C
#define pinstCGuildCreationWnd_x                                   0x105B8C8
#define pinstCGuildMgmtWnd_x                                       0x105B978
#define pinstCharacterCreation_x                                   0xDDD03C
#define pinstCHelpWnd_x                                            0xDDC97C
#define pinstCHeritageSelectionWnd_x                               0xDDD1A0
#define pinstCHotButtonWnd_x                                       0x105DAD0
#define pinstCHotButtonWnd1_x                                      0x105DAD0
#define pinstCHotButtonWnd2_x                                      0x105DAD4
#define pinstCHotButtonWnd3_x                                      0x105DAD8
#define pinstCHotButtonWnd4_x                                      0x105DADC
#define pinstCIconSelectionWnd_x                                   0xDDD100
#define pinstCInspectWnd_x                                         0xDDD110
#define pinstCInventoryWnd_x                                       0xDDD078
#define pinstCInvSlotMgr_x                                         0xDDD0D8
#define pinstCItemDisplayManager_x                                 0x105E060
#define pinstCItemExpTransferWnd_x                                 0x105E194
#define pinstCItemOverflowWnd_x                                    0xDDD1F4
#define pinstCJournalCatWnd_x                                      0xDDD1C8
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDDD18C
#define pinstCKeyRingWnd_x                                         0xDDD0C4
#define pinstCLargeDialogWnd_x                                     0x10602D8
#define pinstCLayoutCopyWnd_x                                      0x105E4E0
#define pinstCLFGuildWnd_x                                         0x105E590
#define pinstCLoadskinWnd_x                                        0xDDD098
#define pinstCLootFiltersCopyWnd_x                                 0xCADB98
#define pinstCLootFiltersWnd_x                                     0xDDD0FC
#define pinstCLootSettingsWnd_x                                    0xDDD118
#define pinstCLootWnd_x                                            0xDDD184
#define pinstCMailAddressBookWnd_x                                 0xDDD0F0
#define pinstCMailCompositionWnd_x                                 0xDDD0D0
#define pinstCMailIgnoreListWnd_x                                  0xDDD0F4
#define pinstCMailWnd_x                                            0xDDD0B0
#define pinstCManageLootWnd_x                                      0xDDE050
#define pinstCMapToolbarWnd_x                                      0xDDD080
#define pinstCMapViewWnd_x                                         0xDDD070
#define pinstCMarketplaceWnd_x                                     0xDDC968
#define pinstCMerchantWnd_x                                        0xDDD1C4
#define pinstCMIZoneSelectWnd_x                                    0x105EDC8
#define pinstCMusicPlayerWnd_x                                     0xDDD0C0
#define pinstCNameChangeMercWnd_x                                  0xDDD07C
#define pinstCNameChangePetWnd_x                                   0xDDD064
#define pinstCNameChangeWnd_x                                      0xDDD1E0
#define pinstCNoteWnd_x                                            0xDDC96C
#define pinstCObjectPreviewWnd_x                                   0xDDCB8C
#define pinstCOptionsWnd_x                                         0xDDD084
#define pinstCPetInfoWnd_x                                         0xDDD0E0
#define pinstCPetitionQWnd_x                                       0xDDD1E4
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDDCB94
#define pinstCPlayerWnd_x                                          0xDDD090
#define pinstCPopupWndManager_x                                    0x105F658
#define pinstCProgressionSelectionWnd_x                            0x105F708
#define pinstCPurchaseGroupWnd_x                                   0xDDCC24
#define pinstCPurchaseWnd_x                                        0xDDCB9C
#define pinstCPvPLeaderboardWnd_x                                  0x105F7B8
#define pinstCPvPStatsWnd_x                                        0x105F868
#define pinstCQuantityWnd_x                                        0xDDD108
#define pinstCRaceChangeWnd_x                                      0xDDC970
#define pinstCRaidOptionsWnd_x                                     0xDDD068
#define pinstCRaidWnd_x                                            0xDDD114
#define pinstCRealEstateItemsWnd_x                                 0xDDD1AC
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDDD1E8
#define pinstCRealEstateManageWnd_x                                0xDDD11C
#define pinstCRealEstateNeighborhoodWnd_x                          0xDDD13C
#define pinstCRealEstatePlotSearchWnd_x                            0xDDD15C
#define pinstCRealEstatePurchaseWnd_x                              0xDDD190
#define pinstCRespawnWnd_x                                         0xDDD040
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDDD028
#define pinstCSendMoneyWnd_x                                       0xDDD0BC
#define pinstCServerListWnd_x                                      0xDDD150
#define pinstCSkillsSelectWnd_x                                    0xDDD198
#define pinstCSkillsWnd_x                                          0xDDD180
#define pinstCSocialEditWnd_x                                      0xDDD124
#define pinstCSocialWnd_x                                          0xDDD0AC
#define pinstCSpellBookWnd_x                                       0xDDCBA0
#define pinstCStoryWnd_x                                           0xDDCB80
#define pinstCTargetOfTargetWnd_x                                  0x1061690
#define pinstCTargetWnd_x                                          0xDDD0DC
#define pinstCTaskOverlayWnd_x                                     0xDDD16C
#define pinstCTaskSelectWnd_x                                      0x10617E8
#define pinstCTaskManager_x                                        0xCAE4E8
#define pinstCTaskTemplateSelectWnd_x                              0x1061898
#define pinstCTaskWnd_x                                            0x1061948
#define pinstCTextEntryWnd_x                                       0xDDCB88
#define pinstCTimeLeftWnd_x                                        0xDDD1B0
#define pinstCTipWndCONTEXT_x                                      0x1061B4C
#define pinstCTipWndOFDAY_x                                        0x1061B48
#define pinstCTitleWnd_x                                           0x1061BF8
#define pinstCTrackingWnd_x                                        0xDDD0EC
#define pinstCTradeskillWnd_x                                      0x1061D60
#define pinstCTradeWnd_x                                           0xDDCB90
#define pinstCTrainWnd_x                                           0xDDD104
#define pinstCTributeBenefitWnd_x                                  0x1061F60
#define pinstCTributeMasterWnd_x                                   0x1062010
#define pinstCTributeTrophyWnd_x                                   0x10620C0
#define pinstCVideoModesWnd_x                                      0xDDD1C0
#define pinstCVoiceMacroWnd_x                                      0xF42D98
#define pinstCVoteResultsWnd_x                                     0xDDD030
#define pinstCVoteWnd_x                                            0xDDCBA8
#define pinstCWebManager_x                                         0xF43414
#define pinstCZoneGuideWnd_x                                       0xDDD12C
#define pinstCZonePathWnd_x                                        0xDDD140

#define pinstEQSuiteTextureLoader_x                                0xC7C4A8
#define pinstItemIconCache_x                                       0x105AF20
#define pinstLootFiltersManager_x                                  0xCADC48
#define pinstRewardSelectionWnd_x                                  0x105FFB0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC2CDF8
#define __CastRay_x                                                0x59E450
#define __CastRay2_x                                               0x59E4A0
#define __ConvertItemTags_x                                        0x5B9FF0
#define __CrashHandler_x                                           0x854E20
#define __CleanItemTags_x                                          0x477B10
#define __DoesFileExist_x                                          0x8F7A00
#define __EQGetTime_x                                              0x8F43F0
#define __ExecuteCmd_x                                             0x596D70
#define __FixHeading_x                                             0x98EBF0
#define __GameLoop_x                                               0x6ABC20
#define __get_bearing_x                                            0x59DFA0
#define __get_melee_range_x                                        0x59E690
#define __GetAnimationCache_x                                      0x710BD0
#define __GetGaugeValueFromEQ_x                                    0x806520
#define __GetLabelFromEQ_x                                         0x808010
#define __GetXTargetType_x                                         0x990650
#define __HandleMouseWheel_x                                       0x6AC810
#define __HeadingDiff_x                                            0x98EC60
#define __HelpPath_x                                               0xF3E134
#define __LoadFrontEnd_x                                           0x6A86F0
#define __NewUIINI_x                                               0x8061F0
#define __pCrashHandler_x                                          0x107F4C8
#define __ProcessGameEvents_x                                      0x5FE660
#define __ProcessMouseEvent_x                                      0x5FDE20
#define __SaveColors_x                                             0x546E90
#define __STMLToText_x                                             0x932080
#define __ToggleKeyRingItem_x                                      0x508F30
#define CMemoryMappedFile__SetFile_x                               0xA691B0
#define CrashDetected_x                                            0x6AA150
#define DrawNetStatus_x                                            0x62A550
#define Expansion_HoT_x                                            0xEA0094
#define Teleport_Table_Size_x                                      0xE91444
#define Teleport_Table_x                                           0xE8F3B0
#define Util__FastTime_x                                           0x8F3FB0
#define wwsCrashReportCheckForUploader_x                           0x855BD0
#define wwsCrashReportPlatformLaunchUploader_x                     0x858290

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B980
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x494890
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x494660
#define CAdvancedLootWnd__AddPlayerToList_x                        0x48EF00
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x48E350

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54EA20
#define AltAdvManager__IsAbilityReady_x                            0x54D970
#define AltAdvManager__GetAAById_x                                 0x54DB70
#define AltAdvManager__CanTrainAbility_x                           0x54DBE0
#define AltAdvManager__CanSeeAbility_x                             0x54DF40

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C7960
#define CharacterZoneClient__HasSkill_x                            0x4D2830
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3F50
#define CharacterZoneClient__IsStackBlocked_x                      0x4BBFF0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B8740
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D6910
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D69F0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D6AD0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C0AD0
#define CharacterZoneClient__BardCastBard_x                        0x4C35A0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B8810
#define CharacterZoneClient__GetEffect_x                           0x4B8680
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C1B00
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C1BD0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1C20
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1D70
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1F50
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B0490
#define CharacterZoneClient__FindItemByGuid_x                      0x4D4EC0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D4930

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D2460
#define CBankWnd__WndNotification_x                                0x6D2240

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6DFBE0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x60CFE0
#define CButtonWnd__CButtonWnd_x                                   0x92E420

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6FFCD0
#define CChatManager__InitContextMenu_x                            0x6F8F50
#define CChatManager__FreeChatWindow_x                             0x6FE7F0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E5FB0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6FF950
#define CChatManager__CreateChatWindow_x                           0x6FEE30

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E60C0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x942BE0
#define CContextMenu__dCContextMenu_x                              0x942E10
#define CContextMenu__AddMenuItem_x                                0x942E20
#define CContextMenu__RemoveMenuItem_x                             0x943130
#define CContextMenu__RemoveAllMenuItems_x                         0x943150
#define CContextMenu__CheckMenuItem_x                              0x9431D0
#define CContextMenu__SetMenuItem_x                                0x943050
#define CContextMenu__AddSeparator_x                               0x942FB0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x943760
#define CContextMenuManager__RemoveMenu_x                          0x9437D0
#define CContextMenuManager__PopupMenu_x                           0x943890
#define CContextMenuManager__Flush_x                               0x943700
#define CContextMenuManager__GetMenu_x                             0x496AF0
#define CContextMenuManager__CreateDefaultMenu_x                   0x70B3D0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D4A10
#define CChatService__GetFriendName_x                              0x8D4A20

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x700540
#define CChatWindow__Clear_x                                       0x7017F0
#define CChatWindow__WndNotification_x                             0x701F80
#define CChatWindow__AddHistory_x                                  0x7010C0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x940060
#define CComboWnd__Draw_x                                          0x93F560
#define CComboWnd__GetCurChoice_x                                  0x93FEA0
#define CComboWnd__GetListRect_x                                   0x93FA00
#define CComboWnd__GetTextRect_x                                   0x9400D0
#define CComboWnd__InsertChoice_x                                  0x93FB90
#define CComboWnd__SetColors_x                                     0x93FB60
#define CComboWnd__SetChoice_x                                     0x93FE70
#define CComboWnd__GetItemCount_x                                  0x93FEB0
#define CComboWnd__GetCurChoiceText_x                              0x93FEF0
#define CComboWnd__GetChoiceText_x                                 0x93FEC0
#define CComboWnd__InsertChoiceAtIndex_x                           0x93FC30

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x708DD0
#define CContainerWnd__vftable_x                                   0xAEF7A8
#define CContainerWnd__SetContainer_x                              0x70A330

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x5418F0
#define CDisplay__PreZoneMainUI_x                                  0x541900
#define CDisplay__CleanGameUI_x                                    0x546C50
#define CDisplay__GetClickedActor_x                                0x539C10
#define CDisplay__GetUserDefinedColor_x                            0x5322D0
#define CDisplay__GetWorldFilePath_x                               0x53B660
#define CDisplay__is3dON_x                                         0x5368C0
#define CDisplay__ReloadUI_x                                       0x540D80
#define CDisplay__WriteTextHD2_x                                   0x5366A0
#define CDisplay__TrueDistance_x                                   0x53D2C0
#define CDisplay__SetViewActor_x                                   0x539560
#define CDisplay__GetFloorHeight_x                                 0x536980
#define CDisplay__SetRenderWindow_x                                0x5352B0
#define CDisplay__ToggleScreenshotMode_x                           0x539030

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x962600

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x946160
#define CEditWnd__GetCharIndexPt_x                                 0x947060
#define CEditWnd__GetDisplayString_x                               0x946F00
#define CEditWnd__GetHorzOffset_x                                  0x945790
#define CEditWnd__GetLineForPrintableChar_x                        0x948210
#define CEditWnd__GetSelStartPt_x                                  0x947310
#define CEditWnd__GetSTMLSafeText_x                                0x946D20
#define CEditWnd__PointFromPrintableChar_x                         0x947E40
#define CEditWnd__SelectableCharFromPoint_x                        0x947FB0
#define CEditWnd__SetEditable_x                                    0x9473E0
#define CEditWnd__SetWindowTextA_x                                 0x946AA0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5EC330
#define CEverQuest__ClickedPlayer_x                                0x5DE3F0
#define CEverQuest__CreateTargetIndicator_x                        0x5FB910
#define CEverQuest__DeleteTargetIndicator_x                        0x5FB9A0
#define CEverQuest__DoTellWindow_x                                 0x4E61A0
#define CEverQuest__OutputTextToLog_x                              0x4E63D0
#define CEverQuest__DropHeldItemOnGround_x                         0x5D3420
#define CEverQuest__dsp_chat_x                                     0x4E6760
#define CEverQuest__trimName_x                                     0x5F7BF0
#define CEverQuest__Emote_x                                        0x5ECB40
#define CEverQuest__EnterZone_x                                    0x5E6B20
#define CEverQuest__GetBodyTypeDesc_x                              0x5F1480
#define CEverQuest__GetClassDesc_x                                 0x5F1AC0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5F20C0
#define CEverQuest__GetDeityDesc_x                                 0x5FA260
#define CEverQuest__GetLangDesc_x                                  0x5F2280
#define CEverQuest__GetRaceDesc_x                                  0x5F1AA0
#define CEverQuest__InterpretCmd_x                                 0x5FA830
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D7620
#define CEverQuest__LMouseUp_x                                     0x5D5990
#define CEverQuest__RightClickedOnPlayer_x                         0x5D7F00
#define CEverQuest__RMouseUp_x                                     0x5D6930
#define CEverQuest__SetGameState_x                                 0x5D31B0
#define CEverQuest__UPCNotificationFlush_x                         0x5F7AF0
#define CEverQuest__IssuePetCommand_x                              0x5F3690
#define CEverQuest__ReportSuccessfulHit_x                          0x5EDF40

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x71AE50
#define CGaugeWnd__CalcLinesFillRect_x                             0x71AEB0
#define CGaugeWnd__Draw_x                                          0x71A490

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACFD0
#define CGuild__GetGuildName_x                                     0x4AC0B0
#define CGuild__GetGuildIndex_x                                    0x4AC440

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x736220

//CHotButton
#define CHotButton__SetButtonSize_x                                0x60D3A0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x743220
#define CInvSlotMgr__MoveItem_x                                    0x741F40
#define CInvSlotMgr__SelectSlot_x                                  0x7432F0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7407F0
#define CInvSlot__SliderComplete_x                                 0x73E550
#define CInvSlot__GetItemBase_x                                    0x73DED0
#define CInvSlot__UpdateItem_x                                     0x73E040

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x744D30
#define CInvSlotWnd__CInvSlotWnd_x                                 0x743EE0
#define CInvSlotWnd__HandleLButtonUp_x                             0x7448B0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x801940
#define CItemDisplayWnd__UpdateStrings_x                           0x7534D0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x74D1B0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x74D6E0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x753AE0
#define CItemDisplayWnd__AboutToShow_x                             0x753140
#define CItemDisplayWnd__WndNotification_x                         0x754BD0
#define CItemDisplayWnd__RequestConvertItem_x                      0x754690
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7521A0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x752F60

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x83A3C0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x759120

// CLabel 
#define CLabel__Draw_x                                             0x75EBD0

// CListWnd
#define CListWnd__CListWnd_x                                       0x9188B0
#define CListWnd__dCListWnd_x                                      0x918BD0
#define CListWnd__AddColumn_x                                      0x91CEE0
#define CListWnd__AddColumn1_x                                     0x91CF30
#define CListWnd__AddLine_x                                        0x91D2C0
#define CListWnd__AddString_x                                      0x91D0C0
#define CListWnd__CalculateFirstVisibleLine_x                      0x91CCB0
#define CListWnd__CalculateVSBRange_x                              0x91CA90
#define CListWnd__ClearSel_x                                       0x91DAA0
#define CListWnd__ClearAllSel_x                                    0x91DB00
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91E500
#define CListWnd__Compare_x                                        0x91C3D0
#define CListWnd__Draw_x                                           0x918CD0
#define CListWnd__DrawColumnSeparators_x                           0x91B4A0
#define CListWnd__DrawHeader_x                                     0x91B910
#define CListWnd__DrawItem_x                                       0x91BD10
#define CListWnd__DrawLine_x                                       0x91B610
#define CListWnd__DrawSeparator_x                                  0x91B540
#define CListWnd__EnableLine_x                                     0x91AD90
#define CListWnd__EnsureVisible_x                                  0x91E430
#define CListWnd__ExtendSel_x                                      0x91D9D0
#define CListWnd__GetColumnTooltip_x                               0x91A8D0
#define CListWnd__GetColumnMinWidth_x                              0x91A940
#define CListWnd__GetColumnWidth_x                                 0x91A840
#define CListWnd__GetCurSel_x                                      0x91A1D0
#define CListWnd__GetItemAtPoint_x                                 0x91B000
#define CListWnd__GetItemAtPoint1_x                                0x91B070
#define CListWnd__GetItemData_x                                    0x91A250
#define CListWnd__GetItemHeight_x                                  0x91A610
#define CListWnd__GetItemIcon_x                                    0x91A3E0
#define CListWnd__GetItemRect_x                                    0x91AE80
#define CListWnd__GetItemText_x                                    0x91A290
#define CListWnd__GetSelList_x                                     0x91DB50
#define CListWnd__GetSeparatorRect_x                               0x91B2B0
#define CListWnd__InsertLine_x                                     0x91D6B0
#define CListWnd__RemoveLine_x                                     0x91D800
#define CListWnd__SetColors_x                                      0x91CA60
#define CListWnd__SetColumnJustification_x                         0x91C790
#define CListWnd__SetColumnWidth_x                                 0x91C6B0
#define CListWnd__SetCurSel_x                                      0x91D910
#define CListWnd__SetItemColor_x                                   0x91E0F0
#define CListWnd__SetItemData_x                                    0x91E0B0
#define CListWnd__SetItemText_x                                    0x91DCC0
#define CListWnd__ShiftColumnSeparator_x                           0x91C850
#define CListWnd__Sort_x                                           0x91C550
#define CListWnd__ToggleSel_x                                      0x91D940
#define CListWnd__SetColumnsSizable_x                              0x91C8F0
#define CListWnd__SetItemWnd_x                                     0x91DF70
#define CListWnd__GetItemWnd_x                                     0x91A430
#define CListWnd__SetItemIcon_x                                    0x91DD40
#define CListWnd__CalculateCustomWindowPositions_x                 0x91CDA0
#define CListWnd__SetVScrollPos_x                                  0x91C690

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x774420
#define CMapViewWnd__GetWorldCoordinates_x                         0x772B30
#define CMapViewWnd__HandleLButtonDown_x                           0x76FB90

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x797380
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x797C60
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7981A0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79B120
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x795ED0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A0CE0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x796F90

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A24E0
#define CPacketScrambler__hton_x                                   0x8A24D0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x937630
#define CSidlManager__FindScreenPieceTemplate_x                    0x937A40
#define CSidlManager__FindScreenPieceTemplate1_x                   0x937830
#define CSidlManager__CreateLabel_x                                0x7F8D40
#define CSidlManager__CreateXWndFromTemplate_x                     0x93A9E0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x93ABB0
#define CSidlManager__CreateXWnd_x                                 0x7F8C70
#define CSidlManager__CreateHotButtonWnd_x                         0x7F9230

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9341B0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9340B0
#define CSidlScreenWnd__ConvertToRes_x                             0x9595C0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x933B40
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x933830
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x933900
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9339D0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x934640
#define CSidlScreenWnd__EnableIniStorage_x                         0x934B10
#define CSidlScreenWnd__GetSidlPiece_x                             0x934830
#define CSidlScreenWnd__Init1_x                                    0x933430
#define CSidlScreenWnd__LoadIniInfo_x                              0x934B60
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9356A0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x932860
#define CSidlScreenWnd__StoreIniInfo_x                             0x935220
#define CSidlScreenWnd__StoreIniVis_x                              0x935580
#define CSidlScreenWnd__WndNotification_x                          0x934550
#define CSidlScreenWnd__GetChildItem_x                             0x934A90
#define CSidlScreenWnd__HandleLButtonUp_x                          0x924350
#define CSidlScreenWnd__m_layoutCopy_x                             0x16DA530

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x671C00
#define CSkillMgr__GetSkillCap_x                                   0x671DE0
#define CSkillMgr__GetNameToken_x                                  0x671390
#define CSkillMgr__IsActivatedSkill_x                              0x6714D0
#define CSkillMgr__IsCombatSkill_x                                 0x671410

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x944560
#define CSliderWnd__SetValue_x                                     0x9443D0
#define CSliderWnd__SetNumTicks_x                                  0x944430

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FEDD0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x94CD20
#define CStmlWnd__CalculateHSBRange_x                              0x94DDF0
#define CStmlWnd__CalculateVSBRange_x                              0x94DD60
#define CStmlWnd__CanBreakAtCharacter_x                            0x952130
#define CStmlWnd__FastForwardToEndOfTag_x                          0x952DC0
#define CStmlWnd__ForceParseNow_x                                  0x94D2C0
#define CStmlWnd__GetNextTagPiece_x                                0x952090
#define CStmlWnd__GetSTMLText_x                                    0x4F8570
#define CStmlWnd__GetVisibleText_x                                 0x94D2E0
#define CStmlWnd__InitializeWindowVariables_x                      0x952C10
#define CStmlWnd__MakeStmlColorTag_x                               0x94C390
#define CStmlWnd__MakeWndNotificationTag_x                         0x94C400
#define CStmlWnd__SetSTMLText_x                                    0x94B440
#define CStmlWnd__StripFirstSTMLLines_x                            0x953EB0
#define CStmlWnd__UpdateHistoryString_x                            0x952FD0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x94A5E0
#define CTabWnd__DrawCurrentPage_x                                 0x94ACC0
#define CTabWnd__DrawTab_x                                         0x94A9E0
#define CTabWnd__GetCurrentPage_x                                  0x949DE0
#define CTabWnd__GetPageInnerRect_x                                0x94A020
#define CTabWnd__GetTabInnerRect_x                                 0x949F60
#define CTabWnd__GetTabRect_x                                      0x949E10
#define CTabWnd__InsertPage_x                                      0x94A230
#define CTabWnd__SetPage_x                                         0x94A0A0
#define CTabWnd__SetPageRect_x                                     0x94A520
#define CTabWnd__UpdatePage_x                                      0x94A8A0
#define CTabWnd__GetPageFromTabIndex_x                             0x94A920
#define CTabWnd__GetCurrentTabIndex_x                              0x949DD0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x759510
#define CPageWnd__SetTabText_x                                     0x949920

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A6C60

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x9211E0
#define CTextureFont__GetTextExtent_x                              0x9213A0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A5710
#define CHtmlComponentWnd__ValidateUri_x                           0x737C10
#define CHtmlWnd__SetClientCallbacks_x                             0x612430
#define CHtmlWnd__AddObserver_x                                    0x612450
#define CHtmlWnd__RemoveObserver_x                                 0x6124B0
#define Window__getProgress_x                                      0x852B30
#define Window__getStatus_x                                        0x852B50
#define Window__getURI_x                                           0x852B60

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x95F030

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90E3A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E5EA0
#define CXStr__CXStr1_x                                            0x9D08B0
#define CXStr__CXStr3_x                                            0x8F04E0
#define CXStr__dCXStr_x                                            0x473150
#define CXStr__operator_equal_x                                    0x8F0710
#define CXStr__operator_equal1_x                                   0x8F0750
#define CXStr__operator_plus_equal1_x                              0x8F11E0
#define CXStr__SetString_x                                         0x8F30D0
#define CXStr__operator_char_p_x                                   0x8F0C20
#define CXStr__GetChar_x                                           0x8F2A00
#define CXStr__Delete_x                                            0x8F22D0
#define CXStr__GetUnicode_x                                        0x8F2A70
#define CXStr__GetLength_x                                         0x4A6A10
#define CXStr__Mid_x                                               0x477EC0
#define CXStr__Insert_x                                            0x8F2AD0
#define CXStr__FindNext_x                                          0x8F2740

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9427F0
#define CXWnd__BringToTop_x                                        0x9279F0
#define CXWnd__Center_x                                            0x927570
#define CXWnd__ClrFocus_x                                          0x9273B0
#define CXWnd__Destroy_x                                           0x927450
#define CXWnd__DoAllDrawing_x                                      0x923AE0
#define CXWnd__DrawChildren_x                                      0x923AB0
#define CXWnd__DrawColoredRect_x                                   0x923F40
#define CXWnd__DrawTooltip_x                                       0x922610
#define CXWnd__DrawTooltipAtPoint_x                                0x9226D0
#define CXWnd__GetBorderFrame_x                                    0x923DA0
#define CXWnd__GetChildWndAt_x                                     0x927A90
#define CXWnd__GetClientClipRect_x                                 0x925CE0
#define CXWnd__GetScreenClipRect_x                                 0x925DB0
#define CXWnd__GetScreenRect_x                                     0x925F70
#define CXWnd__GetTooltipRect_x                                    0x923F90
#define CXWnd__GetWindowTextA_x                                    0x498260
#define CXWnd__IsActive_x                                          0x9246D0
#define CXWnd__IsDescendantOf_x                                    0x926970
#define CXWnd__IsReallyVisible_x                                   0x9269A0
#define CXWnd__IsType_x                                            0x9280D0
#define CXWnd__Move_x                                              0x926A10
#define CXWnd__Move1_x                                             0x926AC0
#define CXWnd__ProcessTransition_x                                 0x927520
#define CXWnd__Refade_x                                            0x926D90
#define CXWnd__Resize_x                                            0x927020
#define CXWnd__Right_x                                             0x9277B0
#define CXWnd__SetFocus_x                                          0x927370
#define CXWnd__SetFont_x                                           0x9273E0
#define CXWnd__SetKeyTooltip_x                                     0x927F00
#define CXWnd__SetMouseOver_x                                      0x924EF0
#define CXWnd__StartFade_x                                         0x926850
#define CXWnd__GetChildItem_x                                      0x927C00
#define CXWnd__SetParent_x                                         0x926710
#define CXWnd__Minimize_x                                          0x927080

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95A650

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x92A950
#define CXWndManager__DrawWindows_x                                0x92A970
#define CXWndManager__GetKeyboardFlags_x                           0x92D0D0
#define CXWndManager__HandleKeyboardMsg_x                          0x92CCD0
#define CXWndManager__RemoveWnd_x                                  0x92D320
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92D870

// CDBStr
#define CDBStr__GetString_x                                        0x531260

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B9720
#define EQ_Character__Cur_HP_x                                     0x4CF810
#define EQ_Character__Cur_Mana_x                                   0x4D6FD0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BC640
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B00D0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B0220
#define EQ_Character__GetHPRegen_x                                 0x4DCE00
#define EQ_Character__GetEnduranceRegen_x                          0x4DD410
#define EQ_Character__GetManaRegen_x                               0x4DD850
#define EQ_Character__Max_Endurance_x                              0x638130
#define EQ_Character__Max_HP_x                                     0x4CF640
#define EQ_Character__Max_Mana_x                                   0x637F30
#define EQ_Character__doCombatAbility_x                            0x63A5F0
#define EQ_Character__UseSkill_x                                   0x4DF640
#define EQ_Character__GetConLevel_x                                0x6314D0
#define EQ_Character__IsExpansionFlag_x                            0x595510
#define EQ_Character__TotalEffect_x                                0x4C2CE0
#define EQ_Character__GetPCSpellAffect_x                           0x4BD240
#define EQ_Character__SpellDuration_x                              0x4BCD70
#define EQ_Character__GetAdjustedSkill_x                           0x4D25F0
#define EQ_Character__GetBaseSkill_x                               0x4D3590
#define EQ_Character__CanUseItem_x                                 0x4D72E0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C18B0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x64E790

//PcClient
#define PcClient__PcClient_x                                       0x62EC10

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B7390
#define CCharacterListWnd__EnterWorld_x                            0x4B6DD0
#define CCharacterListWnd__Quit_x                                  0x4B6AE0
#define CCharacterListWnd__UpdateList_x                            0x4B6F60

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x613670
#define EQ_Item__CreateItemTagString_x                             0x89BCB0
#define EQ_Item__IsStackable_x                                     0x8A0830
#define EQ_Item__GetImageNum_x                                     0x89D700
#define EQ_Item__CreateItemClient_x                                0x612830
#define EQ_Item__GetItemValue_x                                    0x89EA00
#define EQ_Item__ValueSellMerchant_x                               0x8A2080
#define EQ_Item__IsKeyRingItem_x                                   0x8A0190
#define EQ_Item__CanGoInBag_x                                      0x613790
#define EQ_Item__IsEmpty_x                                         0x89FC90
#define EQ_Item__GetMaxItemCount_x                                 0x89EE30
#define EQ_Item__GetHeldItem_x                                     0x89D5D0
#define EQ_Item__GetAugmentFitBySlot_x                             0x89B600

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54F770
#define EQ_LoadingS__Array_x                                       0xC045F8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x638A90
#define EQ_PC__GetAlternateAbilityId_x                             0x8AB120
#define EQ_PC__GetCombatAbility_x                                  0x8AB790
#define EQ_PC__GetCombatAbilityTimer_x                             0x8AB800
#define EQ_PC__GetItemRecastTimer_x                                0x63AB70
#define EQ_PC__HasLoreItem_x                                       0x631C90
#define EQ_PC__AlertInventoryChanged_x                             0x630E10
#define EQ_PC__GetPcZoneClient_x                                   0x65D160
#define EQ_PC__RemoveMyAffect_x                                    0x63DD90
#define EQ_PC__GetKeyRingItems_x                                   0x8AC0A0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8ABE20
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8AC390

// EQItemList 
#define EQItemList__EQItemList_x                                   0x59BA60
#define EQItemList__add_object_x                                   0x5C8B90
#define EQItemList__add_item_x                                     0x59BFB0
#define EQItemList__delete_item_x                                  0x59C000
#define EQItemList__FreeItemList_x                                 0x59BF00

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52DFA0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x650010
#define EQPlayer__dEQPlayer_x                                      0x643300
#define EQPlayer__DoAttack_x                                       0x657E10
#define EQPlayer__EQPlayer_x                                       0x6439C0
#define EQPlayer__SetNameSpriteState_x                             0x647C80
#define EQPlayer__SetNameSpriteTint_x                              0x648B40
#define PlayerBase__HasProperty_j_x                                0x98CF80
#define EQPlayer__IsTargetable_x                                   0x98D420
#define EQPlayer__CanSee_x                                         0x98D280
#define EQPlayer__CanSee1_x                                        0x98D350
#define PlayerBase__GetVisibilityLineSegment_x                     0x98D040

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x65AC10
#define PlayerZoneClient__GetLevel_x                               0x65D1A0
#define PlayerZoneClient__IsValidTeleport_x                        0x5C9D00
#define PlayerZoneClient__LegalPlayerRace_x                        0x548AD0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x652D50
#define EQPlayerManager__GetSpawnByName_x                          0x652E00
#define EQPlayerManager__GetPlayerFromPartialName_x                0x652E90

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x616DB0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x616E30
#define KeypressHandler__AttachKeyToEqCommand_x                    0x616E70
#define KeypressHandler__ClearCommandStateArray_x                  0x618280
#define KeypressHandler__HandleKeyDown_x                           0x6182A0
#define KeypressHandler__HandleKeyUp_x                             0x618340
#define KeypressHandler__SaveKeymapping_x                          0x618770

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7702B0
#define MapViewMap__SaveEx_x                                       0x773650
#define MapViewMap__SetZoom_x                                      0x777D20

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BF6F0

// StringTable 
#define StringTable__getString_x                                   0x8BA4A0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x63DA00
#define PcZoneClient__RemovePetEffect_x                            0x63E030
#define PcZoneClient__HasAlternateAbility_x                        0x637D70
#define PcZoneClient__GetCurrentMod_x                              0x4E2720
#define PcZoneClient__GetModCap_x                                  0x4E2620
#define PcZoneClient__CanEquipItem_x                               0x638420
#define PcZoneClient__GetItemByID_x                                0x63AFE0
#define PcZoneClient__GetItemByItemClass_x                         0x63B130
#define PcZoneClient__RemoveBuffEffect_x                           0x63E050
#define PcZoneClient__BandolierSwap_x                              0x639050
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x63AB10

//Doors
#define EQSwitch__UseSwitch_x                                      0x5CE910

//IconCache
#define IconCache__GetIcon_x                                       0x710460

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x707F70
#define CContainerMgr__CloseContainer_x                            0x708240
#define CContainerMgr__OpenExperimentContainer_x                   0x708CC0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CB4E0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x60B7C0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x766710
#define CLootWnd__RequestLootSlot_x                                0x765930

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x567E30
#define EQ_Spell__SpellAffects_x                                   0x5682A0
#define EQ_Spell__SpellAffectBase_x                                0x568060
#define EQ_Spell__IsStackable_x                                    0x4C72C0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C7170
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B46D0
#define EQ_Spell__IsSPAStacking_x                                  0x5690D0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5685F0
#define EQ_Spell__IsNoRemove_x                                     0x4C72A0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5690E0
#define __IsResEffectSpell_x                                       0x4C6690

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AAD60

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C9E60

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x812000
#define CTargetWnd__WndNotification_x                              0x811890
#define CTargetWnd__RefreshTargetBuffs_x                           0x811B60
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8109E0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8165C0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x52B9B0
#define CTaskManager__HandleMessage_x                              0x529E50

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5633C0
#define EqSoundManager__PlayScriptMp3_x                            0x563520
#define EqSoundManager__SoundAssistPlay_x                          0x675BE0
#define EqSoundManager__WaveInstancePlay_x                         0x675150

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51F810

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x948E20

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x557200
#define CAltAbilityData__GetMercMaxRank_x                          0x5571A0
#define CAltAbilityData__GetMaxRank_x                              0x54C820

//CTargetRing
#define CTargetRing__Cast_x                                        0x6098C0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C7150
#define CharacterBase__CreateItemGlobalIndex_x                     0x505330
#define CharacterBase__CreateItemIndex_x                           0x6119F0
#define CharacterBase__GetItemPossession_x                         0x4F0FD0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D24E0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D2540
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6EF290
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6EFAC0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6EFB70

//messages
#define msg_spell_worn_off_x                                       0x58D710
#define msg_new_text_x                                             0x582540
#define __msgTokenTextParam_x                                      0x58FC40
#define msgTokenText_x                                             0x58FE90

//SpellManager
#define SpellManager__vftable_x                                    0xAC9CB8
#define SpellManager__SpellManager_x                               0x678F10
#define Spellmanager__LoadTextSpells_x                             0x679810
#define SpellManager__GetSpellByGroupAndRank_x                     0x6790E0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x990F40

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5059E0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5939F0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x62A3B0
#define ItemGlobalIndex__IsValidIndex_x                            0x505A40

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8CA800
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8CAA80

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x75EF20

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x70C670
#define CCursorAttachment__AttachToCursor1_x                       0x70C6B0
#define CCursorAttachment__Deactivate_x                            0x70D690

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x93B9F0
#define CSidlManagerBase__CreatePageWnd_x                          0x93B200
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x937450
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9373E0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9589B0
#define CEQSuiteTextureLoader__GetTexture_x                        0x958670

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x5028D0
#define CFindItemWnd__WndNotification_x                            0x5033B0
#define CFindItemWnd__Update_x                                     0x503F20
#define CFindItemWnd__PickupSelectedItem_x                         0x502130

//IString
#define IString__Append_x                                          0x4F26F0

//Camera
#define CDisplay__cameraType_x                                     0xDDC978
#define EverQuest__Cameras_x                                       0xEA03D8

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x50B220
#define LootFiltersManager__GetItemFilterData_x                    0x50AB10
#define LootFiltersManager__RemoveItemLootFilter_x                 0x50AB40
#define LootFiltersManager__SetItemLootFilter_x                    0x50AD60

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B94A0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x996B20
#define CResolutionHandler__GetWindowedStyle_x                     0x6706E0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x704CB0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DD030
#define CDistillerInfo__Instance_x                                 0x8DCFD0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x724FE0
#define CGroupWnd__UpdateDisplay_x                                 0x724340

//ItemBase
#define ItemBase__IsLore_x                                         0x8A01F0
#define ItemBase__IsLoreEquipped_x                                 0x8A0260

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C8AF0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C8C30
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C8C90

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x665C70
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x669640

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F8BA0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E7BA0
#define FactionManagerClient__HandleFactionMessage_x               0x4E8210
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E8800
#define FactionManagerClient__GetMaxFaction_x                      0x4E8850
#define FactionManagerClient__GetMinFaction_x                      0x4E87D0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F0FA0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x9201B0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x497580

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F1340

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x5566F0

//CTargetManager
#define CTargetManager__Get_x                                      0x67C7E0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x665C70

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A6A20

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x59BEA0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF3DA68

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
