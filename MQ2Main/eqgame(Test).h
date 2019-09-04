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
#define __ExpectedVersionDate                                     "Aug 27 2019"
#define __ExpectedVersionTime                                     "12:44:42"
#define __ActualVersionDate_x                                      0xAE6554
#define __ActualVersionTime_x                                      0xAE6548
#define __ActualVersionBuild_x                                     0xAE6FEC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x61C220
#define __MemChecker1_x                                            0x8F3D60
#define __MemChecker2_x                                            0x6AB880
#define __MemChecker3_x                                            0x6AB7D0
#define __MemChecker4_x                                            0x84AE10
#define __EncryptPad0_x                                            0xC1C990
#define __EncryptPad1_x                                            0xC7A9B8
#define __EncryptPad2_x                                            0xC2D208
#define __EncryptPad3_x                                            0xC2CE08
#define __EncryptPad4_x                                            0xC6B180
#define __EncryptPad5_x                                            0x104E718
#define __AC1_x                                                    0x8076A6
#define __AC2_x                                                    0x5D5D4F
#define __AC3_x                                                    0x5DD45F
#define __AC4_x                                                    0x5E1340
#define __AC5_x                                                    0x5E7690
#define __AC6_x                                                    0x5EBC56
#define __AC7_x                                                    0x5D57C0
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
#define __do_loot_x                                                0x5A1E30
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
#define __gfMaxZoomCameraDistance_x                                0xADB9D0
#define __gfMaxCameraDistance_x                                    0xB08FD4
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
#define __CastRay_x                                                0x59D290
#define __CastRay2_x                                               0x59D2E0
#define __ConvertItemTags_x                                        0x5B8E30
#define __CrashHandler_x                                           0x8546B0
#define __CleanItemTags_x                                          0x477A00
#define __DoesFileExist_x                                          0x8F6EE0
#define __EQGetTime_x                                              0x8F3840
#define __ExecuteCmd_x                                             0x595B90
#define __FixHeading_x                                             0x98E850
#define __GameLoop_x                                               0x6AAD40
#define __get_bearing_x                                            0x59CDE0
#define __get_melee_range_x                                        0x59D4D0
#define __GetAnimationCache_x                                      0x70FFA0
#define __GetGaugeValueFromEQ_x                                    0x805B40
#define __GetLabelFromEQ_x                                         0x807630
#define __GetXTargetType_x                                         0x990320
#define __HandleMouseWheel_x                                       0x6AB930
#define __HeadingDiff_x                                            0x98E8C0
#define __HelpPath_x                                               0xF3E134
#define __LoadFrontEnd_x                                           0x6A7810
#define __NewUIINI_x                                               0x805810
#define __pCrashHandler_x                                          0x107F4C8
#define __ProcessGameEvents_x                                      0x5FD4B0
#define __ProcessMouseEvent_x                                      0x5FCC70
#define __SaveColors_x                                             0x546E90
#define __STMLToText_x                                             0x931B90
#define __ToggleKeyRingItem_x                                      0x508DE0
#define CMemoryMappedFile__SetFile_x                               0xA68E00
#define CrashDetected_x                                            0x6A9270
#define DrawNetStatus_x                                            0x629580
#define Expansion_HoT_x                                            0xEA0094
#define Teleport_Table_Size_x                                      0xE91444
#define Teleport_Table_x                                           0xE8F3B0
#define Util__FastTime_x                                           0x8F3400
#define wwsCrashReportCheckForUploader_x                           0x8551C0
#define wwsCrashReportPlatformLaunchUploader_x                     0x8578A0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B7C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4946D0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4944A0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x48ED60
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x48E1B0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54E9C0
#define AltAdvManager__IsAbilityReady_x                            0x54D910
#define AltAdvManager__GetAAById_x                                 0x54DB10
#define AltAdvManager__CanTrainAbility_x                           0x54DB80
#define AltAdvManager__CanSeeAbility_x                             0x54DEE0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C7960
#define CharacterZoneClient__HasSkill_x                            0x4D2830
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3F50
#define CharacterZoneClient__IsStackBlocked_x                      0x4BBFD0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B8720
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D6910
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D69F0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D6AD0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C0AB0
#define CharacterZoneClient__BardCastBard_x                        0x4C3580
#define CharacterZoneClient__GetMaxEffects_x                       0x4B87F0
#define CharacterZoneClient__GetEffect_x                           0x4B8660
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C1AE0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C1BB0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1C00
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1D50
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1F30
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B0490
#define CharacterZoneClient__FindItemByGuid_x                      0x4D4EC0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D4930

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D16B0
#define CBankWnd__WndNotification_x                                0x6D1490

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6DEF30

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x60BED0
#define CButtonWnd__CButtonWnd_x                                   0x92DF70

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6FF070
#define CChatManager__InitContextMenu_x                            0x6F82F0
#define CChatManager__FreeChatWindow_x                             0x6FDB90
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E5F20
#define CChatManager__SetLockedActiveChatWindow_x                  0x6FECF0
#define CChatManager__CreateChatWindow_x                           0x6FE1D0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E6030

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x942630
#define CContextMenu__dCContextMenu_x                              0x942860
#define CContextMenu__AddMenuItem_x                                0x942870
#define CContextMenu__RemoveMenuItem_x                             0x942B80
#define CContextMenu__RemoveAllMenuItems_x                         0x942BA0
#define CContextMenu__CheckMenuItem_x                              0x942C20
#define CContextMenu__SetMenuItem_x                                0x942AA0
#define CContextMenu__AddSeparator_x                               0x942A00

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9431C0
#define CContextMenuManager__RemoveMenu_x                          0x943230
#define CContextMenuManager__PopupMenu_x                           0x9432F0
#define CContextMenuManager__Flush_x                               0x943160
#define CContextMenuManager__GetMenu_x                             0x496A00
#define CContextMenuManager__CreateDefaultMenu_x                   0x70A760

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D3EE0
#define CChatService__GetFriendName_x                              0x8D3EF0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6FF950
#define CChatWindow__Clear_x                                       0x700BF0
#define CChatWindow__WndNotification_x                             0x701380
#define CChatWindow__AddHistory_x                                  0x7004C0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93FAC0
#define CComboWnd__Draw_x                                          0x93EFB0
#define CComboWnd__GetCurChoice_x                                  0x93F900
#define CComboWnd__GetListRect_x                                   0x93F460
#define CComboWnd__GetTextRect_x                                   0x93FB30
#define CComboWnd__InsertChoice_x                                  0x93F5F0
#define CComboWnd__SetColors_x                                     0x93F5C0
#define CComboWnd__SetChoice_x                                     0x93F8D0
#define CComboWnd__GetItemCount_x                                  0x93F910
#define CComboWnd__GetCurChoiceText_x                              0x93F950
#define CComboWnd__GetChoiceText_x                                 0x93F920
#define CComboWnd__InsertChoiceAtIndex_x                           0x93F690

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x708160
#define CContainerWnd__vftable_x                                   0xAEF7E8
#define CContainerWnd__SetContainer_x                              0x7096D0

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
#define CEditBaseWnd__SetSel_x                                     0x962040

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x945BC0
#define CEditWnd__GetCharIndexPt_x                                 0x946AC0
#define CEditWnd__GetDisplayString_x                               0x946960
#define CEditWnd__GetHorzOffset_x                                  0x9451F0
#define CEditWnd__GetLineForPrintableChar_x                        0x947C70
#define CEditWnd__GetSelStartPt_x                                  0x946D70
#define CEditWnd__GetSTMLSafeText_x                                0x946780
#define CEditWnd__PointFromPrintableChar_x                         0x9478A0
#define CEditWnd__SelectableCharFromPoint_x                        0x947A10
#define CEditWnd__SetEditable_x                                    0x946E40
#define CEditWnd__SetWindowTextA_x                                 0x946500

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5EB180
#define CEverQuest__ClickedPlayer_x                                0x5DD240
#define CEverQuest__CreateTargetIndicator_x                        0x5FA760
#define CEverQuest__DeleteTargetIndicator_x                        0x5FA7F0
#define CEverQuest__DoTellWindow_x                                 0x4E6110
#define CEverQuest__OutputTextToLog_x                              0x4E6340
#define CEverQuest__DropHeldItemOnGround_x                         0x5D2270
#define CEverQuest__dsp_chat_x                                     0x4E66D0
#define CEverQuest__trimName_x                                     0x5F6A40
#define CEverQuest__Emote_x                                        0x5EB990
#define CEverQuest__EnterZone_x                                    0x5E5970
#define CEverQuest__GetBodyTypeDesc_x                              0x5F02D0
#define CEverQuest__GetClassDesc_x                                 0x5F0910
#define CEverQuest__GetClassThreeLetterCode_x                      0x5F0F10
#define CEverQuest__GetDeityDesc_x                                 0x5F90B0
#define CEverQuest__GetLangDesc_x                                  0x5F10D0
#define CEverQuest__GetRaceDesc_x                                  0x5F08F0
#define CEverQuest__InterpretCmd_x                                 0x5F9680
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D6470
#define CEverQuest__LMouseUp_x                                     0x5D47E0
#define CEverQuest__RightClickedOnPlayer_x                         0x5D6D50
#define CEverQuest__RMouseUp_x                                     0x5D5780
#define CEverQuest__SetGameState_x                                 0x5D2000
#define CEverQuest__UPCNotificationFlush_x                         0x5F6940
#define CEverQuest__IssuePetCommand_x                              0x5F24E0
#define CEverQuest__ReportSuccessfulHit_x                          0x5ECD90

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x71A1C0
#define CGaugeWnd__CalcLinesFillRect_x                             0x71A220
#define CGaugeWnd__Draw_x                                          0x719800

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACEF0
#define CGuild__GetGuildName_x                                     0x4ABFD0
#define CGuild__GetGuildIndex_x                                    0x4AC360

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x735590

//CHotButton
#define CHotButton__SetButtonSize_x                                0x60C290

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7425C0
#define CInvSlotMgr__MoveItem_x                                    0x7412E0
#define CInvSlotMgr__SelectSlot_x                                  0x742690

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x73FB90
#define CInvSlot__SliderComplete_x                                 0x73D8F0
#define CInvSlot__GetItemBase_x                                    0x73D260
#define CInvSlot__UpdateItem_x                                     0x73D3D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7440F0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7432A0
#define CInvSlotWnd__HandleLButtonUp_x                             0x743C70

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x800F80
#define CItemDisplayWnd__UpdateStrings_x                           0x7527F0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x74C4D0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x74CA00
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x752E00
#define CItemDisplayWnd__AboutToShow_x                             0x752450
#define CItemDisplayWnd__WndNotification_x                         0x753EF0
#define CItemDisplayWnd__RequestConvertItem_x                      0x7539B0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7514C0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x752270

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x839C80

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x758440

// CLabel 
#define CLabel__Draw_x                                             0x75DEC0

// CListWnd
#define CListWnd__CListWnd_x                                       0x9184F0
#define CListWnd__dCListWnd_x                                      0x918810
#define CListWnd__AddColumn_x                                      0x91CB10
#define CListWnd__AddColumn1_x                                     0x91CB60
#define CListWnd__AddLine_x                                        0x91CEF0
#define CListWnd__AddString_x                                      0x91CCF0
#define CListWnd__CalculateFirstVisibleLine_x                      0x91C8D0
#define CListWnd__CalculateVSBRange_x                              0x91C6B0
#define CListWnd__ClearSel_x                                       0x91D6D0
#define CListWnd__ClearAllSel_x                                    0x91D730
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91E150
#define CListWnd__Compare_x                                        0x91BFF0
#define CListWnd__Draw_x                                           0x918910
#define CListWnd__DrawColumnSeparators_x                           0x91B0D0
#define CListWnd__DrawHeader_x                                     0x91B530
#define CListWnd__DrawItem_x                                       0x91B930
#define CListWnd__DrawLine_x                                       0x91B230
#define CListWnd__DrawSeparator_x                                  0x91B170
#define CListWnd__EnableLine_x                                     0x91A9C0
#define CListWnd__EnsureVisible_x                                  0x91E070
#define CListWnd__ExtendSel_x                                      0x91D600
#define CListWnd__GetColumnTooltip_x                               0x91A500
#define CListWnd__GetColumnMinWidth_x                              0x91A570
#define CListWnd__GetColumnWidth_x                                 0x91A470
#define CListWnd__GetCurSel_x                                      0x919E00
#define CListWnd__GetItemAtPoint_x                                 0x91AC30
#define CListWnd__GetItemAtPoint1_x                                0x91ACA0
#define CListWnd__GetItemData_x                                    0x919E80
#define CListWnd__GetItemHeight_x                                  0x91A240
#define CListWnd__GetItemIcon_x                                    0x91A010
#define CListWnd__GetItemRect_x                                    0x91AAB0
#define CListWnd__GetItemText_x                                    0x919EC0
#define CListWnd__GetSelList_x                                     0x91D780
#define CListWnd__GetSeparatorRect_x                               0x91AEE0
#define CListWnd__InsertLine_x                                     0x91D2E0
#define CListWnd__RemoveLine_x                                     0x91D430
#define CListWnd__SetColors_x                                      0x91C680
#define CListWnd__SetColumnJustification_x                         0x91C3B0
#define CListWnd__SetColumnWidth_x                                 0x91C2D0
#define CListWnd__SetCurSel_x                                      0x91D540
#define CListWnd__SetItemColor_x                                   0x91DD20
#define CListWnd__SetItemData_x                                    0x91DCE0
#define CListWnd__SetItemText_x                                    0x91D8F0
#define CListWnd__ShiftColumnSeparator_x                           0x91C470
#define CListWnd__Sort_x                                           0x91C170
#define CListWnd__ToggleSel_x                                      0x91D570
#define CListWnd__SetColumnsSizable_x                              0x91C510
#define CListWnd__SetItemWnd_x                                     0x91DBA0
#define CListWnd__GetItemWnd_x                                     0x91A060
#define CListWnd__SetItemIcon_x                                    0x91D970
#define CListWnd__CalculateCustomWindowPositions_x                 0x91C9D0
#define CListWnd__SetVScrollPos_x                                  0x91C2B0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x773840
#define CMapViewWnd__GetWorldCoordinates_x                         0x771F50
#define CMapViewWnd__HandleLButtonDown_x                           0x76EFB0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7968C0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7971A0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7976E0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79A660
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x795410
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A0240
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7964D0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A1A20
#define CPacketScrambler__hton_x                                   0x8A1A10

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x937130
#define CSidlManager__FindScreenPieceTemplate_x                    0x937540
#define CSidlManager__FindScreenPieceTemplate1_x                   0x937330
#define CSidlManager__CreateLabel_x                                0x7F8400
#define CSidlManager__CreateXWndFromTemplate_x                     0x93A4E0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x93A6C0
#define CSidlManager__CreateXWnd_x                                 0x7F8330
#define CSidlManager__CreateHotButtonWnd_x                         0x7F88F0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x933CB0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x933BB0
#define CSidlScreenWnd__ConvertToRes_x                             0x959060
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x933640
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x933330
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x933400
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9334D0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x934140
#define CSidlScreenWnd__EnableIniStorage_x                         0x934610
#define CSidlScreenWnd__GetSidlPiece_x                             0x934330
#define CSidlScreenWnd__Init1_x                                    0x932F50
#define CSidlScreenWnd__LoadIniInfo_x                              0x934660
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9351A0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x932370
#define CSidlScreenWnd__StoreIniInfo_x                             0x934D20
#define CSidlScreenWnd__StoreIniVis_x                              0x935080
#define CSidlScreenWnd__WndNotification_x                          0x934050
#define CSidlScreenWnd__GetChildItem_x                             0x934590
#define CSidlScreenWnd__HandleLButtonUp_x                          0x923F30
#define CSidlScreenWnd__m_layoutCopy_x                             0x16DA530

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x670CF0
#define CSkillMgr__GetSkillCap_x                                   0x670ED0
#define CSkillMgr__GetNameToken_x                                  0x670480
#define CSkillMgr__IsActivatedSkill_x                              0x6705C0
#define CSkillMgr__IsCombatSkill_x                                 0x670500

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x943FC0
#define CSliderWnd__SetValue_x                                     0x943E30
#define CSliderWnd__SetNumTicks_x                                  0x943E90

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FE420

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x94C7B0
#define CStmlWnd__CalculateHSBRange_x                              0x94D890
#define CStmlWnd__CalculateVSBRange_x                              0x94D800
#define CStmlWnd__CanBreakAtCharacter_x                            0x951BD0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x952860
#define CStmlWnd__ForceParseNow_x                                  0x94CD50
#define CStmlWnd__GetNextTagPiece_x                                0x951B30
#define CStmlWnd__GetSTMLText_x                                    0x4F8400
#define CStmlWnd__GetVisibleText_x                                 0x94CD70
#define CStmlWnd__InitializeWindowVariables_x                      0x9526B0
#define CStmlWnd__MakeStmlColorTag_x                               0x94BE20
#define CStmlWnd__MakeWndNotificationTag_x                         0x94BE90
#define CStmlWnd__SetSTMLText_x                                    0x94AED0
#define CStmlWnd__StripFirstSTMLLines_x                            0x953930
#define CStmlWnd__UpdateHistoryString_x                            0x952A70

// CTabWnd 
#define CTabWnd__Draw_x                                            0x94A050
#define CTabWnd__DrawCurrentPage_x                                 0x94A730
#define CTabWnd__DrawTab_x                                         0x94A450
#define CTabWnd__GetCurrentPage_x                                  0x949850
#define CTabWnd__GetPageInnerRect_x                                0x949A90
#define CTabWnd__GetTabInnerRect_x                                 0x9499D0
#define CTabWnd__GetTabRect_x                                      0x949880
#define CTabWnd__InsertPage_x                                      0x949CA0
#define CTabWnd__SetPage_x                                         0x949B10
#define CTabWnd__SetPageRect_x                                     0x949F90
#define CTabWnd__UpdatePage_x                                      0x94A310
#define CTabWnd__GetPageFromTabIndex_x                             0x94A390
#define CTabWnd__GetCurrentTabIndex_x                              0x949840

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x758810
#define CPageWnd__SetTabText_x                                     0x949390

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A6AD0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x920DA0
#define CTextureFont__GetTextExtent_x                              0x920F60

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6A4850
#define CHtmlComponentWnd__ValidateUri_x                           0x736F80
#define CHtmlWnd__SetClientCallbacks_x                             0x611310
#define CHtmlWnd__AddObserver_x                                    0x611330
#define CHtmlWnd__RemoveObserver_x                                 0x611390
#define Window__getProgress_x                                      0x8523B0
#define Window__getStatus_x                                        0x8523D0
#define Window__getURI_x                                           0x8523E0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x95EA70

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90E250

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E5E10
#define CXStr__CXStr1_x                                            0x916C70
#define CXStr__CXStr3_x                                            0x8EF970
#define CXStr__dCXStr_x                                            0x473070
#define CXStr__operator_equal_x                                    0x8EFBA0
#define CXStr__operator_equal1_x                                   0x8EFBE0
#define CXStr__operator_plus_equal1_x                              0x8F0670
#define CXStr__SetString_x                                         0x8F2560
#define CXStr__operator_char_p_x                                   0x8F00B0
#define CXStr__GetChar_x                                           0x8F1E90
#define CXStr__Delete_x                                            0x8F1760
#define CXStr__GetUnicode_x                                        0x8F1F00
#define CXStr__GetLength_x                                         0x477DB0
#define CXStr__Mid_x                                               0x477DC0
#define CXStr__Insert_x                                            0x8F1F60
#define CXStr__FindNext_x                                          0x8F1BD0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x942250
#define CXWnd__BringToTop_x                                        0x927610
#define CXWnd__Center_x                                            0x927190
#define CXWnd__ClrFocus_x                                          0x926FC0
#define CXWnd__Destroy_x                                           0x927070
#define CXWnd__DoAllDrawing_x                                      0x9236E0
#define CXWnd__DrawChildren_x                                      0x9236B0
#define CXWnd__DrawColoredRect_x                                   0x923B40
#define CXWnd__DrawTooltip_x                                       0x9221F0
#define CXWnd__DrawTooltipAtPoint_x                                0x9222B0
#define CXWnd__GetBorderFrame_x                                    0x9239A0
#define CXWnd__GetChildWndAt_x                                     0x9276B0
#define CXWnd__GetClientClipRect_x                                 0x9258E0
#define CXWnd__GetScreenClipRect_x                                 0x9259B0
#define CXWnd__GetScreenRect_x                                     0x925B70
#define CXWnd__GetTooltipRect_x                                    0x923B90
#define CXWnd__GetWindowTextA_x                                    0x498190
#define CXWnd__IsActive_x                                          0x9242B0
#define CXWnd__IsDescendantOf_x                                    0x926560
#define CXWnd__IsReallyVisible_x                                   0x926590
#define CXWnd__IsType_x                                            0x927D10
#define CXWnd__Move_x                                              0x9265F0
#define CXWnd__Move1_x                                             0x9266A0
#define CXWnd__ProcessTransition_x                                 0x927140
#define CXWnd__Refade_x                                            0x926970
#define CXWnd__Resize_x                                            0x926BF0
#define CXWnd__Right_x                                             0x9273D0
#define CXWnd__SetFocus_x                                          0x926F80
#define CXWnd__SetFont_x                                           0x926FF0
#define CXWnd__SetKeyTooltip_x                                     0x927B30
#define CXWnd__SetMouseOver_x                                      0x924AA0
#define CXWnd__StartFade_x                                         0x926440
#define CXWnd__GetChildItem_x                                      0x927820
#define CXWnd__SetParent_x                                         0x926310
#define CXWnd__Minimize_x                                          0x926C60

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95A0F0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x92A570
#define CXWndManager__DrawWindows_x                                0x92A590
#define CXWndManager__GetKeyboardFlags_x                           0x92CC50
#define CXWndManager__HandleKeyboardMsg_x                          0x92C850
#define CXWndManager__RemoveWnd_x                                  0x92CE90
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92D3C0

// CDBStr
#define CDBStr__GetString_x                                        0x5312A0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B9700
#define EQ_Character__Cur_HP_x                                     0x4CF810
#define EQ_Character__Cur_Mana_x                                   0x4D6FD0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BC620
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B00D0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B0220
#define EQ_Character__GetHPRegen_x                                 0x4DCE00
#define EQ_Character__GetEnduranceRegen_x                          0x4DD410
#define EQ_Character__GetManaRegen_x                               0x4DD850
#define EQ_Character__Max_Endurance_x                              0x6371E0
#define EQ_Character__Max_HP_x                                     0x4CF640
#define EQ_Character__Max_Mana_x                                   0x636FE0
#define EQ_Character__doCombatAbility_x                            0x6396A0
#define EQ_Character__UseSkill_x                                   0x4DF640
#define EQ_Character__GetConLevel_x                                0x630520
#define EQ_Character__IsExpansionFlag_x                            0x594360
#define EQ_Character__TotalEffect_x                                0x4C2CC0
#define EQ_Character__GetPCSpellAffect_x                           0x4BD220
#define EQ_Character__SpellDuration_x                              0x4BCD50
#define EQ_Character__GetAdjustedSkill_x                           0x4D25F0
#define EQ_Character__GetBaseSkill_x                               0x4D3590
#define EQ_Character__CanUseItem_x                                 0x4D72E0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C0C70

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x64D850

//PcClient
#define PcClient__PcClient_x                                       0x62DC60

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B7340
#define CCharacterListWnd__EnterWorld_x                            0x4B6D80
#define CCharacterListWnd__Quit_x                                  0x4B6A90
#define CCharacterListWnd__UpdateList_x                            0x4B6F10

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x612520
#define EQ_Item__CreateItemTagString_x                             0x89B210
#define EQ_Item__IsStackable_x                                     0x89FD80
#define EQ_Item__GetImageNum_x                                     0x89CC50
#define EQ_Item__CreateItemClient_x                                0x6116F0
#define EQ_Item__GetItemValue_x                                    0x89DF60
#define EQ_Item__ValueSellMerchant_x                               0x8A15C0
#define EQ_Item__IsKeyRingItem_x                                   0x89F6E0
#define EQ_Item__CanGoInBag_x                                      0x612640
#define EQ_Item__IsEmpty_x                                         0x89F1E0
#define EQ_Item__GetMaxItemCount_x                                 0x89E390
#define EQ_Item__GetHeldItem_x                                     0x89CB20
#define EQ_Item__GetAugmentFitBySlot_x                             0x89AB60

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54F6C0
#define EQ_LoadingS__Array_x                                       0xC045F8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x637B40
#define EQ_PC__GetAlternateAbilityId_x                             0x8AA6A0
#define EQ_PC__GetCombatAbility_x                                  0x8AAD10
#define EQ_PC__GetCombatAbilityTimer_x                             0x8AAD80
#define EQ_PC__GetItemRecastTimer_x                                0x639C20
#define EQ_PC__HasLoreItem_x                                       0x630CE0
#define EQ_PC__AlertInventoryChanged_x                             0x62FE60
#define EQ_PC__GetPcZoneClient_x                                   0x65C310
#define EQ_PC__RemoveMyAffect_x                                    0x63CE40
#define EQ_PC__GetKeyRingItems_x                                   0x8AB620
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8AB3A0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8AB910

// EQItemList 
#define EQItemList__EQItemList_x                                   0x59A8B0
#define EQItemList__add_object_x                                   0x5C7AA0
#define EQItemList__add_item_x                                     0x59AE00
#define EQItemList__delete_item_x                                  0x59AE50
#define EQItemList__FreeItemList_x                                 0x59AD50

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52DD20

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x64F0D0
#define EQPlayer__dEQPlayer_x                                      0x6423B0
#define EQPlayer__DoAttack_x                                       0x656FC0
#define EQPlayer__EQPlayer_x                                       0x642A70
#define EQPlayer__SetNameSpriteState_x                             0x646D30
#define EQPlayer__SetNameSpriteTint_x                              0x647C00
#define PlayerBase__HasProperty_j_x                                0x98CC30
#define EQPlayer__IsTargetable_x                                   0x98D0D0
#define EQPlayer__CanSee_x                                         0x98CF30
#define EQPlayer__CanSee1_x                                        0x98D000
#define PlayerBase__GetVisibilityLineSegment_x                     0x98CCF0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x659DC0
#define PlayerZoneClient__GetLevel_x                               0x65C350
#define PlayerZoneClient__IsValidTeleport_x                        0x5C8C10
#define PlayerZoneClient__LegalPlayerRace_x                        0x548B00

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x651EC0
#define EQPlayerManager__GetSpawnByName_x                          0x651F70
#define EQPlayerManager__GetPlayerFromPartialName_x                0x652000

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x615CB0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x615D30
#define KeypressHandler__AttachKeyToEqCommand_x                    0x615D70
#define KeypressHandler__ClearCommandStateArray_x                  0x617180
#define KeypressHandler__HandleKeyDown_x                           0x6171A0
#define KeypressHandler__HandleKeyUp_x                             0x617240
#define KeypressHandler__SaveKeymapping_x                          0x617670

// MapViewMap 
#define MapViewMap__Clear_x                                        0x76F6D0
#define MapViewMap__SaveEx_x                                       0x772A70
#define MapViewMap__SetZoom_x                                      0x777140

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BEB60

// StringTable 
#define StringTable__getString_x                                   0x8B98E0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x63CAB0
#define PcZoneClient__RemovePetEffect_x                            0x63D0E0
#define PcZoneClient__HasAlternateAbility_x                        0x636E20
#define PcZoneClient__GetCurrentMod_x                              0x4E2730
#define PcZoneClient__GetModCap_x                                  0x4E2630
#define PcZoneClient__CanEquipItem_x                               0x6374D0
#define PcZoneClient__GetItemByID_x                                0x63A090
#define PcZoneClient__GetItemByItemClass_x                         0x63A1E0
#define PcZoneClient__RemoveBuffEffect_x                           0x63D100
#define PcZoneClient__BandolierSwap_x                              0x638100
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x639BC0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5CD750

//IconCache
#define IconCache__GetIcon_x                                       0x70F830

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x707300
#define CContainerMgr__CloseContainer_x                            0x7075D0
#define CContainerMgr__OpenExperimentContainer_x                   0x708050

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CA9F0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x60A6B0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x765A00
#define CLootWnd__RequestLootSlot_x                                0x764C20

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x567B70
#define EQ_Spell__SpellAffects_x                                   0x567FE0
#define EQ_Spell__SpellAffectBase_x                                0x567DA0
#define EQ_Spell__IsStackable_x                                    0x4C72D0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C7150
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B46B0
#define EQ_Spell__IsSPAStacking_x                                  0x568E10
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x568330
#define EQ_Spell__IsNoRemove_x                                     0x4C72B0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x568E20
#define __IsResEffectSpell_x                                       0x4C6670

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AABD0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C92F0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x811650
#define CTargetWnd__WndNotification_x                              0x810EE0
#define CTargetWnd__RefreshTargetBuffs_x                           0x8111B0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x810040

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x815C20

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x52B730
#define CTaskManager__HandleMessage_x                              0x529BB0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x563100
#define EqSoundManager__PlayScriptMp3_x                            0x563260
#define EqSoundManager__SoundAssistPlay_x                          0x674C90
#define EqSoundManager__WaveInstancePlay_x                         0x674200

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51F5E0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x948890

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5571A0
#define CAltAbilityData__GetMercMaxRank_x                          0x557140
#define CAltAbilityData__GetMaxRank_x                              0x54C7C0

//CTargetRing
#define CTargetRing__Cast_x                                        0x6087B0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C7130
#define CharacterBase__CreateItemGlobalIndex_x                     0x505180
#define CharacterBase__CreateItemIndex_x                           0x6108D0
#define CharacterBase__GetItemPossession_x                         0x4F0FD0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D1970
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D19D0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6EE570
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6EEDA0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6EEE50

//messages
#define msg_spell_worn_off_x                                       0x58C460
#define msg_new_text_x                                             0x5812A0
#define __msgTokenTextParam_x                                      0x58E990
#define msgTokenText_x                                             0x58EBE0

//SpellManager
#define SpellManager__vftable_x                                    0xAC9CB8
#define SpellManager__SpellManager_x                               0x677FC0
#define Spellmanager__LoadTextSpells_x                             0x6788C0
#define SpellManager__GetSpellByGroupAndRank_x                     0x678190

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x990C10

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x505860
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x592760
#define ItemGlobalIndex__IsEquippedLocation_x                      0x6293E0
#define ItemGlobalIndex__IsValidIndex_x                            0x5058C0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C9C90
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C9F10

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x75E210

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x70BA10
#define CCursorAttachment__AttachToCursor1_x                       0x70BA50
#define CCursorAttachment__Deactivate_x                            0x70CA30

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x93B500
#define CSidlManagerBase__CreatePageWnd_x                          0x93AD10
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x936F50
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x936EE0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x958630
#define CEQSuiteTextureLoader__GetTexture_x                        0x9582F0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x502720
#define CFindItemWnd__WndNotification_x                            0x503200
#define CFindItemWnd__Update_x                                     0x503D70
#define CFindItemWnd__PickupSelectedItem_x                         0x501F80

//IString
#define IString__Append_x                                          0x4F25F0

//Camera
#define CDisplay__cameraType_x                                     0xDDC978
#define EverQuest__Cameras_x                                       0xEA03D8

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x50B0E0
#define LootFiltersManager__GetItemFilterData_x                    0x50A9D0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x50AA00
#define LootFiltersManager__SetItemLootFilter_x                    0x50AC20

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B8950

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x996890
#define CResolutionHandler__GetWindowedStyle_x                     0x66F780

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7040B0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DC4C0
#define CDistillerInfo__Instance_x                                 0x8DC460

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x724330
#define CGroupWnd__UpdateDisplay_x                                 0x723690

//ItemBase
#define ItemBase__IsLore_x                                         0x89F740
#define ItemBase__IsLoreEquipped_x                                 0x89F7B0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C7A00
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C7B40
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C7BA0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x664E40
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x668850

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F8B20

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E7B20
#define FactionManagerClient__HandleFactionMessage_x               0x4E8190
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E8780
#define FactionManagerClient__GetMaxFaction_x                      0x4E87D0
#define FactionManagerClient__GetMinFaction_x                      0x4E8750

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F0FA0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91FE00

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x4974B0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F1240

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x556670

//CTargetManager
#define CTargetManager__Get_x                                      0x67B820

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x664E40

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A6890

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x59ACF0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF3DA68

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
