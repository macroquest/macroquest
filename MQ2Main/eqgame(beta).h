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
#define __ExpectedVersionDate                                     "Nov 23 2018"
#define __ExpectedVersionTime                                     "04:19:50"
#define __ActualVersionDate_x                                      0xACE01C
#define __ActualVersionTime_x                                      0xACE010

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x6140E0
#define __MemChecker1_x                                            0x8E8760
#define __MemChecker2_x                                            0x6A33C0
#define __MemChecker3_x                                            0x6A3310
#define __MemChecker4_x                                            0x83FD40
#define __EncryptPad0_x                                            0xC02340
#define __EncryptPad1_x                                            0xC605D0
#define __EncryptPad2_x                                            0xC12EC8
#define __EncryptPad3_x                                            0xC12AC8
#define __EncryptPad4_x                                            0xC50E40
#define __EncryptPad5_x                                            0x1031770
#define __AC1_x                                                    0x7FC746
#define __AC2_x                                                    0x5CF1DF
#define __AC3_x                                                    0x5D606F
#define __AC4_x                                                    0x5D9E90
#define __AC5_x                                                    0x5E004F
#define __AC6_x                                                    0x5E4586
#define __AC7_x                                                    0x5CEC50
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E8AEE4

// Direct Input
#define DI8__Main_x                                                0x1031794
#define DI8__Keyboard_x                                            0x1031798
#define DI8__Mouse_x                                               0xF27498
#define DI8__Mouse_Copy_x                                          0xE85194
#define DI8__Mouse_Check_x                                         0x1032658
#define __AutoSkillArray_x                                         0xE860AC
#define __Attack_x                                                 0xF23EB3
#define __Autofire_x                                               0xF23EB4
#define __BindList_x                                               0xBF0F20
#define g_eqCommandStates_x                                        0xBF1C90
#define __Clicks_x                                                 0xE8524C
#define __CommandList_x                                            0xBF2848
#define __CurrentMapLabel_x                                        0x1039A5C
#define __CurrentSocial_x                                          0xBDB730
#define __DoAbilityList_x                                          0xEBB9D4
#define __do_loot_x                                                0x59C890
#define __DrawHandler_x                                            0x16B6430
#define __GroupCount_x                                             0xE75442
#define __Guilds_x                                                 0xE7B9A0
#define __gWorld_x                                                 0xE77D1C
#define __HWnd_x                                                   0xF2749C
#define __heqmain_x                                                0x1031758
#define __InChatMode_x                                             0xE8517C
#define __LastTell_x                                               0xE870D0
#define __LMouseHeldTime_x                                         0xE852B8
#define __Mouse_x                                                  0x103177C
#define __MouseLook_x                                              0xE85212
#define __MouseEventTime_x                                         0xF24968
#define __gpbCommandEvent_x                                        0xE77760
#define __NetStatusToggle_x                                        0xE85215
#define __PCNames_x                                                0xE8668C
#define __RangeAttackReady_x                                       0xE86390
#define __RMouseHeldTime_x                                         0xE852B4
#define __RunWalkState_x                                           0xE85180
#define __ScreenMode_x                                             0xDC3A68
#define __ScreenX_x                                                0xE85134
#define __ScreenY_x                                                0xE85130
#define __ScreenXMax_x                                             0xE85138
#define __ScreenYMax_x                                             0xE8513C
#define __ServerHost_x                                             0xE779B3
#define __ServerName_x                                             0xEBB994
#define __ShiftKeyDown_x                                           0xE8580C
#define __ShowNames_x                                              0xE8654C
#define __Socials_x                                                0xEBBA94
#define __SubscriptionType_x                                       0x107B5AC
#define __TargetAggroHolder_x                                      0x103C418
#define __ZoneType_x                                               0xE85610
#define __GroupAggro_x                                             0x103C458
#define __LoginName_x                                              0x1031FEC
#define __Inviter_x                                                0xF23E30
#define __AttackOnAssist_x                                         0xE86508
#define __UseTellWindows_x                                         0xE86824
#define __gfMaxZoomCameraDistance_x                                0xAC3530
#define __gfMaxCameraDistance_x                                    0xAF0980
#define __pulAutoRun_x                                             0xE85230
#define __pulForward_x                                             0xE8685C
#define __pulBackward_x                                            0xE86860
#define __pulTurnRight_x                                           0xE86864
#define __pulTurnLeft_x                                            0xE86868
#define __pulStrafeLeft_x                                          0xE8686C
#define __pulStrafeRight_x                                         0xE86870
//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE77D38
#define instEQZoneInfo_x                                           0xE85408
#define instKeypressHandler_x                                      0xF24918
#define pinstActiveBanker_x                                        0xE77858
#define pinstActiveCorpse_x                                        0xE77850
#define pinstActiveGMaster_x                                       0xE77854
#define pinstActiveMerchant_x                                      0xE7784C
#define pinstAggroInfo_x                                           0xC76E08
#define pinstAltAdvManager_x                                       0xDC46D8
#define pinstAuraMgr_x                                             0xC92970
#define pinstBandageTarget_x                                       0xE77868
#define pinstCamActor_x                                            0xDC3A5C
#define pinstCDBStr_x                                              0xDC340C
#define pinstCDisplay_x                                            0xE77D14
#define pinstCEverQuest_x                                          0x10318B0
#define pinstEverQuestInfo_x                                       0xE85128
#define pinstCharData_x                                            0xE77D24
#define pinstCharSpawn_x                                           0xE778A0
#define pinstControlledMissile_x                                   0xE77D20
#define pinstControlledPlayer_x                                    0xE778A0
#define pinstCResolutionHandler_x                                  0x16B6660
#define pinstCSidlManager_x                                        0x16B54F4
#define pinstCXWndManager_x                                        0x16B54E8
#define instDynamicZone_x                                          0xE7B878
#define pinstDZMember_x                                            0xE7B988
#define pinstDZTimerInfo_x                                         0xE7B98C
#define pinstEQItemList_x                                          0xE73F28
#define pinstEQObjectList_x                                        0xE75118
#define instEQMisc_x                                               0xDC3348
#define pinstEQSoundManager_x                                      0xDC4F38
#define pinstEQSpellStrings_x                                      0xC84F40
#define instExpeditionLeader_x                                     0xE7B8C2
#define instExpeditionName_x                                       0xE7B902
#define pinstGroup_x                                               0xE7543E
#define pinstImeManager_x                                          0x16B54EC
#define pinstLocalPlayer_x                                         0xE77848
#define pinstMercenaryData_x                                       0xF25114
#define pinstMercenaryStats_x                                      0x103C564
#define pinstMercAltAbilities_x                                    0xDC4CA8
#define pinstModelPlayer_x                                         0xE77860
#define pinstPCData_x                                              0xE77D24
#define pinstRealEstateItems_x                                     0xF265F8
#define pinstSkillMgr_x                                            0xF266C8
#define pinstSpawnManager_x                                        0xF25CB8
#define pinstSpellManager_x                                        0xF268A0
#define pinstSpellSets_x                                           0xF1CADC
#define pinstStringTable_x                                         0xE77638
#define pinstSwitchManager_x                                       0xE752D8
#define pinstTarget_x                                              0xE7789C
#define pinstTargetObject_x                                        0xE77CC8
#define pinstTargetSwitch_x                                        0xE77D2C
#define pinstTaskMember_x                                          0xDC31DC
#define pinstTrackTarget_x                                         0xE778B0
#define pinstTradeTarget_x                                         0xE7785C
#define instTributeActive_x                                        0xDC336D
#define pinstViewActor_x                                           0xDC3A58
#define pinstWorldData_x                                           0xE77768
#define pinstZoneAddr_x                                            0xE856A8
#define pinstPlayerPath_x                                          0xF25D50
#define pinstTargetIndicator_x                                     0xF26B08
#define pinstCTargetManager_x                                      0xF26BA0
#define EQObject_Top_x                                             0xE77844

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDC3518
#define pinstCAchievementsWnd_x                                    0xDC34CC
#define pinstCActionsWnd_x                                         0xDC39F4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDC39E4
#define pinstCAdvancedLootWnd_x                                    0xDC3534
#define pinstCAdventureLeaderboardWnd_x                            0x1033230
#define pinstCAdventureRequestWnd_x                                0x10332E0
#define pinstCAdventureStatsWnd_x                                  0x1033390
#define pinstCAggroMeterWnd_x                                      0xDC3A98
#define pinstCAlarmWnd_x                                           0xDC3AB8
#define pinstCAlertHistoryWnd_x                                    0xDC3B1C
#define pinstCAlertStackWnd_x                                      0xDC3A7C
#define pinstCAlertWnd_x                                           0xDC3A8C
#define pinstCAltStorageWnd_x                                      0x10336F0
#define pinstCAudioTriggersWindow_x                                0xC77298
#define pinstCAuraWnd_x                                            0xDC3A94
#define pinstCAvaZoneWnd_x                                         0xDC3D20
#define pinstCBandolierWnd_x                                       0xDC3ADC
#define pinstCBankWnd_x                                            0xDC34C4
#define pinstCBarterMerchantWnd_x                                  0x1034930
#define pinstCBarterSearchWnd_x                                    0x10349E0
#define pinstCBarterWnd_x                                          0x1034A90
#define pinstCBazaarConfirmationWnd_x                              0xDC3A78
#define pinstCBazaarSearchWnd_x                                    0xDC3A30
#define pinstCBazaarWnd_x                                          0xDC3AD4
#define pinstCBlockedBuffWnd_x                                     0xDC34A8
#define pinstCBlockedPetBuffWnd_x                                  0xDC34D0
#define pinstCBodyTintWnd_x                                        0xDC3A3C
#define pinstCBookWnd_x                                            0xDC3B00
#define pinstCBreathWnd_x                                          0xDC3520
#define pinstCBuffWindowNORMAL_x                                   0xDC3D24
#define pinstCBuffWindowSHORT_x                                    0xDC3D28
#define pinstCBugReportWnd_x                                       0xDC3508
#define pinstCButtonWnd_x                                          0x16B5718
#define pinstCCastingWnd_x                                         0xDC3504
#define pinstCCastSpellWnd_x                                       0xDC3A44
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDC3524
#define pinstCChatWindowManager_x                                  0x1035550
#define pinstCClaimWnd_x                                           0x10356A8
#define pinstCColorPickerWnd_x                                     0xDC3554
#define pinstCCombatAbilityWnd_x                                   0xDC3AA4
#define pinstCCombatSkillsSelectWnd_x                              0xDC39EC
#define pinstCCompassWnd_x                                         0xDC3A24
#define pinstCConfirmationDialog_x                                 0x103A5A8
#define pinstCContainerMgr_x                                       0xDC3AC0
#define pinstCContextMenuManager_x                                 0x16B54A8
#define pinstCCursorAttachment_x                                   0xDC34F8
#define pinstCDistillerInfo_x                                      0x1038FB4
#define pinstCDynamicZoneWnd_x                                     0x1035C70
#define pinstCEditLabelWnd_x                                       0xDC3B0C
#define pinstCEQMainWnd_x                                          0x1035EB8
#define pinstCEventCalendarWnd_x                                   0xDC3514
#define pinstCExtendedTargetWnd_x                                  0xDC3A84
#define pinstCFacePick_x                                           0xDC354C
#define pinstCFellowshipWnd_x                                      0x10360B8
#define pinstCFileSelectionWnd_x                                   0xDC352C
#define pinstCFindItemWnd_x                                        0xDC3AF4
#define pinstCFindLocationWnd_x                                    0x1036210
#define pinstCFriendsWnd_x                                         0xDC3A2C
#define pinstCGemsGameWnd_x                                        0xDC3A90
#define pinstCGiveWnd_x                                            0xDC3AF8
#define pinstCGroupSearchFiltersWnd_x                              0xDC3AB0
#define pinstCGroupSearchWnd_x                                     0x1036608
#define pinstCGroupWnd_x                                           0x10366B8
#define pinstCGuildBankWnd_x                                       0xE864EC
#define pinstCGuildCreationWnd_x                                   0x1036818
#define pinstCGuildMgmtWnd_x                                       0x10368C8
#define pinstCharacterCreation_x                                   0xDC3AA0
#define pinstCHelpWnd_x                                            0xDC3A4C
#define pinstCHeritageSelectionWnd_x                               0xDC35D4
#define pinstCHotButtonWnd_x                                       0x1038A20
#define pinstCHotButtonWnd1_x                                      0x1038A20
#define pinstCHotButtonWnd2_x                                      0x1038A24
#define pinstCHotButtonWnd3_x                                      0x1038A28
#define pinstCHotButtonWnd4_x                                      0x1038A2C
#define pinstCIconSelectionWnd_x                                   0xDC34E0
#define pinstCInspectWnd_x                                         0xDC34D4
#define pinstCInventoryWnd_x                                       0xDC3AE4
#define pinstCInvSlotMgr_x                                         0xDC3A74
#define pinstCItemDisplayManager_x                                 0x1038FB0
#define pinstCItemExpTransferWnd_x                                 0x10390E0
#define pinstCItemOverflowWnd_x                                    0xDC3A34
#define pinstCJournalCatWnd_x                                      0xDC3544
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDC350C
#define pinstCKeyRingWnd_x                                         0xDC3D3C
#define pinstCLargeDialogWnd_x                                     0x103B228
#define pinstCLayoutCopyWnd_x                                      0x1039430
#define pinstCLFGuildWnd_x                                         0x10394E0
#define pinstCLoadskinWnd_x                                        0xDC3A9C
#define pinstCLootFiltersCopyWnd_x                                 0xC932A0
#define pinstCLootFiltersWnd_x                                     0xDC3AA8
#define pinstCLootSettingsWnd_x                                    0xDC3AC8
#define pinstCLootWnd_x                                            0xDC353C
#define pinstCMailAddressBookWnd_x                                 0xDC34D8
#define pinstCMailCompositionWnd_x                                 0xDC34B4
#define pinstCMailIgnoreListWnd_x                                  0xDC34DC
#define pinstCMailWnd_x                                            0xDC3D2C
#define pinstCManageLootWnd_x                                      0xDC4B50
#define pinstCMapToolbarWnd_x                                      0xDC3AE8
#define pinstCMapViewWnd_x                                         0xDC3AC4
#define pinstCMarketplaceWnd_x                                     0xDC351C
#define pinstCMerchantWnd_x                                        0xDC39E8
#define pinstCMIZoneSelectWnd_x                                    0x1039D18
#define pinstCMusicPlayerWnd_x                                     0xDC3D38
#define pinstCNameChangeMercWnd_x                                  0xDC3A40
#define pinstCNameChangePetWnd_x                                   0xDC3A14
#define pinstCNameChangeWnd_x                                      0xDC34FC
#define pinstCNoteWnd_x                                            0xDC3A48
#define pinstCObjectPreviewWnd_x                                   0xDC3540
#define pinstCOptionsWnd_x                                         0xDC3AEC
#define pinstCPetInfoWnd_x                                         0xDC34B8
#define pinstCPetitionQWnd_x                                       0xDC3550
//#define pinstCPlayerCustomizationWnd_x                             0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDC3A38
#define pinstCPlayerWnd_x                                          0xDC3A1C
#define pinstCPopupWndManager_x                                    0x103A5A8
#define pinstCProgressionSelectionWnd_x                            0x103A658
#define pinstCPurchaseGroupWnd_x                                   0xDC39DC
#define pinstCPurchaseWnd_x                                        0xDC3548
#define pinstCPvPLeaderboardWnd_x                                  0x103A708
#define pinstCPvPStatsWnd_x                                        0x103A7B8
#define pinstCQuantityWnd_x                                        0xDC34EC
#define pinstCRaceChangeWnd_x                                      0xDC3528
#define pinstCRaidOptionsWnd_x                                     0xDC3ABC
#define pinstCRaidWnd_x                                            0xDC34F0
#define pinstCRealEstateItemsWnd_x                                 0xDC34E4
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDC3510
#define pinstCRealEstateManageWnd_x                                0xDC3AE0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDC3B04
#define pinstCRealEstatePlotSearchWnd_x                            0xDC3D30
#define pinstCRealEstatePurchaseWnd_x                              0xDC34BC
#define pinstCRespawnWnd_x                                         0xDC3AAC
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDC3A88
#define pinstCSendMoneyWnd_x                                       0xDC3B10
#define pinstCServerListWnd_x                                      0xDC3B14
#define pinstCSkillsSelectWnd_x                                    0xDC355C
#define pinstCSkillsWnd_x                                          0xDC3538
#define pinstCSocialEditWnd_x                                      0xDC34F4
#define pinstCSocialWnd_x                                          0xDC3A50
#define pinstCSpellBookWnd_x                                       0xDC3A80
#define pinstCStoryWnd_x                                           0xDC39F0
#define pinstCTargetOfTargetWnd_x                                  0x103C5E8
#define pinstCTargetWnd_x                                          0xDC34B0
#define pinstCTaskOverlayWnd_x                                     0xDC3D34
#define pinstCTaskSelectWnd_x                                      0x103C740
#define pinstCTaskManager_x                                        0xC93AA0
#define pinstCTaskTemplateSelectWnd_x                              0x103C7F0
#define pinstCTaskWnd_x                                            0x103C8A0
#define pinstCTextEntryWnd_x                                       0xDC3A28
#define pinstCTextOverlay_x                                        0xC775A8
#define pinstCTimeLeftWnd_x                                        0xDC3530
#define pinstCTipWndCONTEXT_x                                      0x103CAA4
#define pinstCTipWndOFDAY_x                                        0x103CAA0
#define pinstCTitleWnd_x                                           0x103CB50
#define pinstCTrackingWnd_x                                        0xDC34AC
#define pinstCTradeskillWnd_x                                      0x103CCB8
#define pinstCTradeWnd_x                                           0xDC3A54
#define pinstCTrainWnd_x                                           0xDC34E8
#define pinstCTributeBenefitWnd_x                                  0x103CEB8
#define pinstCTributeMasterWnd_x                                   0x103CF68
#define pinstCTributeTrophyWnd_x                                   0x103D018
#define pinstCVideoModesWnd_x                                      0xDC3AB4
#define pinstCVoiceMacroWnd_x                                      0xF270D0
#define pinstCVoteResultsWnd_x                                     0xDC39E0
#define pinstCVoteWnd_x                                            0xDC3558
#define pinstCWebManager_x                                         0xF27234
#define pinstCZoneGuideWnd_x                                       0xDC3AF0
#define pinstCZonePathWnd_x                                        0xDC3B08

#define pinstEQSuiteTextureLoader_x                                0xC620A0
#define pinstItemIconCache_x                                       0x1035E70
#define pinstLootFiltersManager_x                                  0xC93350
#define pinstRewardSelectionWnd_x                                  0x103AF00

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC12ABC
#define __CastRay_x                                                0x597DB0
#define __CastRay2_x                                               0x597E00
#define __ConvertItemTags_x                                        0x5B29B0
#define __CrashHandler_x                                           0x849690
#define __EQGetTime_x                                              0x8E8250
#define __ExecuteCmd_x                                             0x590700
#define __FixHeading_x                                             0x9788F0
#define __get_bearing_x                                            0x597900
#define __get_melee_range_x                                        0x597FF0
#define __GetAnimationCache_x                                      0x706B00
#define __GetGaugeValueFromEQ_x                                    0x7FAF60
#define __GetLabelFromEQ_x                                         0x7FC6D0
#define __GetXTargetType_x                                         0x97A3C0
#define __HeadingDiff_x                                            0x978960
#define __HelpPath_x                                               0xF24584
#define __LoadFrontEnd_x                                           0x69F220
#define __NewUIINI_x                                               0x7FAC30
#define __pCrashHandler_x                                          0x105A408
#define __ProcessGameEvents_x                                      0x5F57B0
#define __ProcessMouseEvent_x                                      0x5F4F70
#define __SaveColors_x                                             0x540320
#define __STMLToText_x                                             0x91BE70
#define __ToggleKeyRingItem_x                                      0x5035A0
#define CrashDetected_x                                            0x6A0D10
#define DrawNetStatus_x                                            0x621520
#define Expansion_HoT_x                                            0xE864F4
#define Teleport_Table_Size_x                                      0xE77804
#define Teleport_Table_x                                           0xE75638
#define Util__FastTime_x                                           0x8E7E10
#define wwsCrashReportCheckForUploader_x                           0x84A3E0
#define wwsCrashReportPlatformLaunchUploader_x                     0x84CAC0
#define __HandleMouseWheel_x                                       0x6A3470

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B5D0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x494440
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x494200

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x547E70
#define AltAdvManager__IsAbilityReady_x                            0x546DC0
#define AltAdvManager__GetAAById_x                                 0x546FC0
#define AltAdvManager__CanTrainAbility_x                           0x547030
#define AltAdvManager__CanSeeAbility_x                             0x547390

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C7680
#define CharacterZoneClient__HasSkill_x                            0x4D2340
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3A60
#define CharacterZoneClient__IsStackBlocked_x                      0x4BBA30
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B81B0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D6400
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D64E0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D65C0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C0510
#define CharacterZoneClient__BardCastBard_x                        0x4C3180
#define CharacterZoneClient__GetMaxEffects_x                       0x4B8280
#define CharacterZoneClient__GetEffect_x                           0x4B80F0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C1510
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C15E0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1630
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1780
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1950

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6C9110

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D69A0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x603E00
#define CButtonWnd__CButtonWnd_x                                   0x918260

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F5560
#define CChatManager__InitContextMenu_x                            0x6EF600
#define CChatManager__FreeChatWindow_x                             0x6F4470
#define CChatManager__GetLockedActiveChatWindow_x                  0x6F8E10
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F5300

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x92CA60
#define CContextMenu__dCContextMenu_x                              0x92CC90
#define CContextMenu__AddMenuItem_x                                0x92CCA0
#define CContextMenu__RemoveMenuItem_x                             0x92CFA0
#define CContextMenu__RemoveAllMenuItems_x                         0x92CFC0
#define CContextMenu__CheckMenuItem_x                              0x92D040
#define CContextMenu__SetMenuItem_x                                0x92CED0
#define CContextMenu__AddSeparator_x                               0x92CE30

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x92D5E0
#define CContextMenuManager__RemoveMenu_x                          0x92D650
#define CContextMenuManager__PopupMenu_x                           0x92D710
#define CContextMenuManager__Flush_x                               0x92D580
#define CContextMenuManager__GetMenu_x                             0x496590

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8C8C60
#define CChatService__GetFriendName_x                              0x8C8C70

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F5AD0
#define CChatWindow__Clear_x                                       0x6F6B20
#define CChatWindow__WndNotification_x                             0x6F7090

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x929EE0
#define CComboWnd__Draw_x                                          0x9293E0
#define CComboWnd__GetCurChoice_x                                  0x929D20
#define CComboWnd__GetListRect_x                                   0x929890
#define CComboWnd__GetTextRect_x                                   0x929F40
#define CComboWnd__InsertChoice_x                                  0x929A20
#define CComboWnd__SetColors_x                                     0x9299F0
#define CComboWnd__SetChoice_x                                     0x929CF0
#define CComboWnd__GetItemCount_x                                  0x929D30
#define CComboWnd__GetCurChoiceText_x                              0x929D70

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6FED00
#define CContainerWnd__vftable_x                                   0xAD72C0
#define CContainerWnd__SetContainer_x                              0x700270

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x5400E0
#define CDisplay__GetClickedActor_x                                0x533090
#define CDisplay__GetUserDefinedColor_x                            0x52B770
#define CDisplay__GetWorldFilePath_x                               0x534AE0
#define CDisplay__is3dON_x                                         0x52FD60
#define CDisplay__ReloadUI_x                                       0x53A200
#define CDisplay__WriteTextHD2_x                                   0x52FB40
#define CDisplay__TrueDistance_x                                   0x536740
#define CDisplay__SetViewActor_x                                   0x5329E0
#define CDisplay__GetFloorHeight_x                                 0x52FE20
#define CDisplay__SetRenderWindow_x                                0x52E750
#define CDisplay__ToggleScreenshotMode_x                           0x5324B0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x94BFB0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x931130
#define CEditWnd__GetCharIndexPt_x                                 0x932020
#define CEditWnd__GetDisplayString_x                               0x931EC0
#define CEditWnd__GetHorzOffset_x                                  0x930770
#define CEditWnd__GetLineForPrintableChar_x                        0x933150
#define CEditWnd__GetSelStartPt_x                                  0x9322C0
#define CEditWnd__GetSTMLSafeText_x                                0x931CE0
#define CEditWnd__PointFromPrintableChar_x                         0x932D80
#define CEditWnd__SelectableCharFromPoint_x                        0x932EF0
#define CEditWnd__SetEditable_x                                    0x932390

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E3AB0
#define CEverQuest__ClickedPlayer_x                                0x5D5E50
#define CEverQuest__CreateTargetIndicator_x                        0x5F2A60
#define CEverQuest__DeleteTargetIndicator_x                        0x5F2AF0
#define CEverQuest__DoTellWindow_x                                 0x4E34F0
#define CEverQuest__OutputTextToLog_x                              0x4E3720
#define CEverQuest__DropHeldItemOnGround_x                         0x5CB710
#define CEverQuest__dsp_chat_x                                     0x4E3AB0
#define CEverQuest__trimName_x                                     0x5EEFD0
#define CEverQuest__Emote_x                                        0x5E42C0
#define CEverQuest__EnterZone_x                                    0x5DE4A0
#define CEverQuest__GetBodyTypeDesc_x                              0x5E8870
#define CEverQuest__GetClassDesc_x                                 0x5E8EB0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5E94B0
#define CEverQuest__GetDeityDesc_x                                 0x5F13B0
#define CEverQuest__GetLangDesc_x                                  0x5E9670
#define CEverQuest__GetRaceDesc_x                                  0x5E8E90
#define CEverQuest__InterpretCmd_x                                 0x5F1980
#define CEverQuest__LeftClickedOnPlayer_x                          0x5CF900
#define CEverQuest__LMouseUp_x                                     0x5CDC80
#define CEverQuest__RightClickedOnPlayer_x                         0x5D01E0
#define CEverQuest__RMouseUp_x                                     0x5CEC10
#define CEverQuest__SetGameState_x                                 0x5CB4A0
#define CEverQuest__UPCNotificationFlush_x                         0x5EEED0
#define CEverQuest__IssuePetCommand_x                              0x5EAA70
#define CEverQuest__ReportSuccessfulHit_x                          0x5E56C0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x710BA0
#define CGaugeWnd__CalcLinesFillRect_x                             0x710C00
#define CGaugeWnd__Draw_x                                          0x710290

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACCE0
#define CGuild__GetGuildName_x                                     0x4ABDC0
#define CGuild__GetGuildIndex_x                                    0x4AC150

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x72BF50

//CHotButton
#define CHotButton__SetButtonSize_x                                0x6041C0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x738F40
#define CInvSlotMgr__MoveItem_x                                    0x737C60
#define CInvSlotMgr__SelectSlot_x                                  0x739010

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x736510
#define CInvSlot__SliderComplete_x                                 0x734270
#define CInvSlot__GetItemBase_x                                    0x733BE0
#define CInvSlot__UpdateItem_x                                     0x733D50

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x73A960
#define CInvSlotWnd__CInvSlotWnd_x                                 0x739C30
#define CInvSlotWnd__HandleLButtonUp_x                             0x73A4E0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F7160
#define CItemDisplayWnd__UpdateStrings_x                           0x748B80
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x742B10
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x743020
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x749190
#define CItemDisplayWnd__AboutToShow_x                             0x7487D0
#define CItemDisplayWnd__WndNotification_x                         0x74A6E0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x82EA20

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x74E830

// CLabel 
#define CLabel__Draw_x                                             0x754380

// CListWnd
#define CListWnd__CListWnd_x                                       0x9026C0
#define CListWnd__dCListWnd_x                                      0x9029D0
#define CListWnd__AddColumn_x                                      0x906CA0
#define CListWnd__AddColumn1_x                                     0x906CF0
#define CListWnd__AddLine_x                                        0x907080
#define CListWnd__AddString_x                                      0x906E80
#define CListWnd__CalculateFirstVisibleLine_x                      0x906A70
#define CListWnd__CalculateVSBRange_x                              0x906860
#define CListWnd__ClearSel_x                                       0x907860
#define CListWnd__ClearAllSel_x                                    0x9078C0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x9082A0
#define CListWnd__Compare_x                                        0x9061B0
#define CListWnd__Draw_x                                           0x902AD0
#define CListWnd__DrawColumnSeparators_x                           0x905290
#define CListWnd__DrawHeader_x                                     0x905700
#define CListWnd__DrawItem_x                                       0x905AF0
#define CListWnd__DrawLine_x                                       0x905400
#define CListWnd__DrawSeparator_x                                  0x905330
#define CListWnd__EnableLine_x                                     0x904B70
#define CListWnd__EnsureVisible_x                                  0x9081E0
#define CListWnd__ExtendSel_x                                      0x907790
#define CListWnd__GetColumnMinWidth_x                              0x9046B0
#define CListWnd__GetColumnWidth_x                                 0x904620
#define CListWnd__GetCurSel_x                                      0x903FB0
#define CListWnd__GetItemAtPoint_x                                 0x904DE0
#define CListWnd__GetItemAtPoint1_x                                0x904E50
#define CListWnd__GetItemData_x                                    0x904030
#define CListWnd__GetItemHeight_x                                  0x9043F0
#define CListWnd__GetItemIcon_x                                    0x9041C0
#define CListWnd__GetItemRect_x                                    0x904C60
#define CListWnd__GetItemText_x                                    0x904070
#define CListWnd__GetSelList_x                                     0x907910
#define CListWnd__GetSeparatorRect_x                               0x905090
#define CListWnd__InsertLine_x                                     0x907470
#define CListWnd__RemoveLine_x                                     0x9075C0
#define CListWnd__SetColors_x                                      0x906840
#define CListWnd__SetColumnJustification_x                         0x906570
#define CListWnd__SetColumnWidth_x                                 0x906490
#define CListWnd__SetCurSel_x                                      0x9076D0
#define CListWnd__SetItemColor_x                                   0x907EA0
#define CListWnd__SetItemData_x                                    0x907E60
#define CListWnd__SetItemText_x                                    0x907A90
#define CListWnd__ShiftColumnSeparator_x                           0x906630
#define CListWnd__Sort_x                                           0x906330
#define CListWnd__ToggleSel_x                                      0x907700

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x769840
#define CMapViewWnd__GetWorldCoordinates_x                         0x767F50
#define CMapViewWnd__HandleLButtonDown_x                           0x764FB0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x78CB20
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x78D400
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x78D930
#define CMerchantWnd__SelectRecoverySlot_x                         0x790760
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x78B510
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x796350
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x78C760

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x896B40
#define CPacketScrambler__hton_x                                   0x896B30

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x921450
#define CSidlManager__FindScreenPieceTemplate_x                    0x921860
#define CSidlManager__FindScreenPieceTemplate1_x                   0x921650
#define CSidlManager__CreateLabel_x                                0x7EE590
#define CSidlManager__CreateXWndFromTemplate_x                     0x924930
#define CSidlManager__CreateXWndFromTemplate1_x                    0x924B10
#define CSidlManager__CreateXWnd_x                                 0x7EE4C0
#define CSidlManager__CreateHotButtonWnd_x                         0x7EEA90

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x91DFC0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x91DEC0
#define CSidlScreenWnd__ConvertToRes_x                             0x942E20
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x91D950
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x91D640
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x91D710
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x91D7E0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x91E460
#define CSidlScreenWnd__EnableIniStorage_x                         0x91E930
#define CSidlScreenWnd__GetSidlPiece_x                             0x91E650
#define CSidlScreenWnd__Init1_x                                    0x91D250
#define CSidlScreenWnd__LoadIniInfo_x                              0x91E980
#define CSidlScreenWnd__LoadIniListWnd_x                           0x91F4C0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x91C650
#define CSidlScreenWnd__StoreIniInfo_x                             0x91F040
#define CSidlScreenWnd__StoreIniVis_x                              0x91F3A0
#define CSidlScreenWnd__WndNotification_x                          0x91E370
#define CSidlScreenWnd__GetChildItem_x                             0x91E8B0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x90E160
#define CSidlScreenWnd__m_layoutCopy_x                             0x16B5378

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x668400
#define CSkillMgr__GetSkillCap_x                                   0x6685E0
#define CSkillMgr__GetNameToken_x                                  0x667B90

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x92E3D0
#define CSliderWnd__SetValue_x                                     0x92E240
#define CSliderWnd__SetNumTicks_x                                  0x92E2A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7F43A0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x934FE0
#define CStmlWnd__CalculateHSBRange_x                              0x936050
#define CStmlWnd__CalculateVSBRange_x                              0x935FC0
#define CStmlWnd__CanBreakAtCharacter_x                            0x93A390
#define CStmlWnd__FastForwardToEndOfTag_x                          0x93AF80
#define CStmlWnd__ForceParseNow_x                                  0x935580
#define CStmlWnd__GetNextTagPiece_x                                0x93A2F0
#define CStmlWnd__GetSTMLText_x                                    0x4F4E60
#define CStmlWnd__GetVisibleText_x                                 0x9355A0
#define CStmlWnd__InitializeWindowVariables_x                      0x93ADD0
#define CStmlWnd__MakeStmlColorTag_x                               0x934770
#define CStmlWnd__MakeWndNotificationTag_x                         0x9347E0
#define CStmlWnd__SetSTMLText_x                                    0x933840
#define CStmlWnd__StripFirstSTMLLines_x                            0x93C0D0
#define CStmlWnd__UpdateHistoryString_x                            0x93B190

// CTabWnd 
#define CTabWnd__Draw_x                                            0x93FD40
#define CTabWnd__DrawCurrentPage_x                                 0x940360
#define CTabWnd__DrawTab_x                                         0x940130
#define CTabWnd__GetCurrentPage_x                                  0x93F5A0
#define CTabWnd__GetPageInnerRect_x                                0x93F7E0
#define CTabWnd__GetTabInnerRect_x                                 0x93F720
#define CTabWnd__GetTabRect_x                                      0x93F5D0
#define CTabWnd__InsertPage_x                                      0x93F9D0
#define CTabWnd__SetPage_x                                         0x93F860
#define CTabWnd__SetPageRect_x                                     0x93FC80
#define CTabWnd__UpdatePage_x                                      0x93FFF0
#define CTabWnd__GetPageFromTabIndex_x                             0x940070
#define CTabWnd__GetCurrentTabIndex_x                              0x93F590

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x74ECC0
#define CPageWnd__SetTabText_x                                     0x94C3C0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A67E0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x90AFB0
#define CTextureFont__GetTextExtent_x                              0x90B170

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x69C050
#define CHtmlComponentWnd__ValidateUri_x                           0x72D940
#define CHtmlWnd__SetClientCallbacks_x                             0x609170
#define CHtmlWnd__AddObserver_x                                    0x609190
#define CHtmlWnd__RemoveObserver_x                                 0x6091F0
#define Window__getProgress_x                                      0x847300
#define Window__getStatus_x                                        0x847320
#define Window__getURI_x                                           0x847330

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x948940

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F80C0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AE040
#define CXStr__CXStr1_x                                            0x837B50
#define CXStr__CXStr3_x                                            0x8E4380
#define CXStr__dCXStr_x                                            0x472F20
#define CXStr__operator_equal_x                                    0x8E45B0
#define CXStr__operator_equal1_x                                   0x8E45F0
#define CXStr__operator_plus_equal1_x                              0x8E5080

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x92C660
#define CXWnd__BringToTop_x                                        0x911880
#define CXWnd__Center_x                                            0x911400
#define CXWnd__ClrFocus_x                                          0x911240
#define CXWnd__Destroy_x                                           0x9112E0
#define CXWnd__DoAllDrawing_x                                      0x90D8F0
#define CXWnd__DrawChildren_x                                      0x90D8C0
#define CXWnd__DrawColoredRect_x                                   0x90DD50
#define CXWnd__DrawTooltip_x                                       0x90C410
#define CXWnd__DrawTooltipAtPoint_x                                0x90C4D0
#define CXWnd__GetBorderFrame_x                                    0x90DBB0
#define CXWnd__GetChildWndAt_x                                     0x911920
#define CXWnd__GetClientClipRect_x                                 0x90FB80
#define CXWnd__GetScreenClipRect_x                                 0x90FC50
#define CXWnd__GetScreenRect_x                                     0x90FE20
#define CXWnd__GetTooltipRect_x                                    0x90DDA0
#define CXWnd__GetWindowTextA_x                                    0x497D10
#define CXWnd__IsActive_x                                          0x9147C0
#define CXWnd__IsDescendantOf_x                                    0x910800
#define CXWnd__IsReallyVisible_x                                   0x910830
#define CXWnd__IsType_x                                            0x911F90
#define CXWnd__Move_x                                              0x9108A0
#define CXWnd__Move1_x                                             0x910950
#define CXWnd__ProcessTransition_x                                 0x9113B0
#define CXWnd__Refade_x                                            0x910C10
#define CXWnd__Resize_x                                            0x910E60
#define CXWnd__Right_x                                             0x911640
#define CXWnd__SetFocus_x                                          0x911200
#define CXWnd__SetFont_x                                           0x911270
#define CXWnd__SetKeyTooltip_x                                     0x911DA0
#define CXWnd__SetMouseOver_x                                      0x90ED00
#define CXWnd__StartFade_x                                         0x9106F0
#define CXWnd__GetChildItem_x                                      0x911A90
#define CXWnd__SetParent_x                                         0x9105C0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x943EF0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x914800
#define CXWndManager__DrawWindows_x                                0x914820
#define CXWndManager__GetKeyboardFlags_x                           0x916EE0
#define CXWndManager__HandleKeyboardMsg_x                          0x916AE0
#define CXWndManager__RemoveWnd_x                                  0x917130
#define CXWndManager__RemovePendingDeletionWnd_x                   0x917680

// CDBStr
#define CDBStr__GetString_x                                        0x52A720

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B9160
#define EQ_Character__Cur_HP_x                                     0x4CF3C0
#define EQ_Character__Cur_Mana_x                                   0x4D6AC0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BC070
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFC90
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFDE0
#define EQ_Character__GetHPRegen_x                                 0x4DCA20
#define EQ_Character__GetEnduranceRegen_x                          0x4DD030
#define EQ_Character__GetManaRegen_x                               0x4DD470
#define EQ_Character__Max_Endurance_x                              0x62F060
#define EQ_Character__Max_HP_x                                     0x4CF1F0
#define EQ_Character__Max_Mana_x                                   0x62EE60
#define EQ_Character__doCombatAbility_x                            0x631520
#define EQ_Character__UseSkill_x                                   0x4DF260
#define EQ_Character__GetConLevel_x                                0x628260
#define EQ_Character__IsExpansionFlag_x                            0x58EEB0
#define EQ_Character__TotalEffect_x                                0x4C2700
#define EQ_Character__GetPCSpellAffect_x                           0x4BCC60
#define EQ_Character__SpellDuration_x                              0x4BC790
#define EQ_Character__FindItemByRecord_x                           0x4D49D0
#define EQ_Character__GetAdjustedSkill_x                           0x4D2100
#define EQ_Character__GetBaseSkill_x                               0x4D30A0
#define EQ_Character__CanUseItem_x                                 0x4D6DD0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B5BB0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6457A0

//PcClient
#define PcClient__PcClient_x                                       0x625B40

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6DE0
#define CCharacterListWnd__EnterWorld_x                            0x4B6820
#define CCharacterListWnd__Quit_x                                  0x4B6530
#define CCharacterListWnd__UpdateList_x                            0x4B69B0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x60A390
#define EQ_Item__CreateItemTagString_x                             0x890490
#define EQ_Item__IsStackable_x                                     0x894ED0
#define EQ_Item__GetImageNum_x                                     0x891ED0
#define EQ_Item__CreateItemClient_x                                0x609550
#define EQ_Item__GetItemValue_x                                    0x893120
#define EQ_Item__ValueSellMerchant_x                               0x8966D0
#define EQ_Item__IsKeyRingItem_x                                   0x894820
#define EQ_Item__CanGoInBag_x                                      0x60A4B0
#define EQ_Item__GetMaxItemCount_x                                 0x8934F0
#define EQ_Item__GetHeldItem_x                                     0x891DA0
#define EQ_Item__GetAugmentFitBySlot_x                             0x88FDC0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x548BD0
#define EQ_LoadingS__Array_x                                       0xBEA130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x62F9C0
#define EQ_PC__GetAlternateAbilityId_x                             0x89F8C0
#define EQ_PC__GetCombatAbility_x                                  0x89FF30
#define EQ_PC__GetCombatAbilityTimer_x                             0x89FFA0
#define EQ_PC__GetItemRecastTimer_x                                0x631AA0
#define EQ_PC__HasLoreItem_x                                       0x628A30
#define EQ_PC__AlertInventoryChanged_x                             0x627D40
#define EQ_PC__GetPcZoneClient_x                                   0x653F40
#define EQ_PC__RemoveMyAffect_x                                    0x634CA0
#define EQ_PC__GetKeyRingItems_x                                   0x8A0840
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A05C0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A0B30

// EQItemList 
#define EQItemList__EQItemList_x                                   0x595340
#define EQItemList__add_object_x                                   0x5C0DA0
#define EQItemList__add_item_x                                     0x595950
#define EQItemList__delete_item_x                                  0x5959A0
#define EQItemList__FreeItemList_x                                 0x5958A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x527D20

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x647020
#define EQPlayer__dEQPlayer_x                                      0x63A310
#define EQPlayer__DoAttack_x                                       0x64EC40
#define EQPlayer__EQPlayer_x                                       0x63A9C0
#define EQPlayer__SetNameSpriteState_x                             0x63F050
#define EQPlayer__SetNameSpriteTint_x                              0x63FF20
#define PlayerBase__HasProperty_j_x                                0x976C80
#define EQPlayer__IsTargetable_x                                   0x977120
#define EQPlayer__CanSee_x                                         0x976F80
#define EQPlayer__CanSee1_x                                        0x977050
#define PlayerBase__GetVisibilityLineSegment_x                     0x976D40

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x651A10
#define PlayerZoneClient__GetLevel_x                               0x653F80
#define PlayerZoneClient__IsValidTeleport_x                        0x5C1EF0
#define PlayerZoneClient__LegalPlayerRace_x                        0x541EF0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x649D80
#define EQPlayerManager__GetSpawnByName_x                          0x649DA0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x649E30

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x60DCF0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x60DD30
#define KeypressHandler__ClearCommandStateArray_x                  0x60F120
#define KeypressHandler__HandleKeyDown_x                           0x60F140
#define KeypressHandler__HandleKeyUp_x                             0x60F1E0
#define KeypressHandler__SaveKeymapping_x                          0x60F5C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7656D0
#define MapViewMap__SaveEx_x                                       0x768A70
#define MapViewMap__SetZoom_x                                      0x76D140

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B3AA0

// StringTable 
#define StringTable__getString_x                                   0x8AEAE0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x634910
#define PcZoneClient__RemovePetEffect_x                            0x634F40
#define PcZoneClient__HasAlternateAbility_x                        0x62ECA0
#define PcZoneClient__GetCurrentMod_x                              0x4E2360
#define PcZoneClient__GetModCap_x                                  0x4E2260
#define PcZoneClient__CanEquipItem_x                               0x62F350
#define PcZoneClient__GetItemByID_x                                0x631F20
#define PcZoneClient__GetItemByItemClass_x                         0x632070
#define PcZoneClient__RemoveBuffEffect_x                           0x634F60
#define PcZoneClient__BandolierSwap_x                              0x62FF80

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C6B70

//IconCache
#define IconCache__GetIcon_x                                       0x706390

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6FDEA0
#define CContainerMgr__CloseContainer_x                            0x6FE170
#define CContainerMgr__OpenExperimentContainer_x                   0x6FEBF0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C0BD0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x6025E0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x75BB70
#define CLootWnd__RequestLootSlot_x                                0x75AF30

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x561230
#define EQ_Spell__SpellAffects_x                                   0x5616A0
#define EQ_Spell__SpellAffectBase_x                                0x561460
#define EQ_Spell__IsStackable_x                                    0x4C6FA0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6DF0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B41A0
#define EQ_Spell__IsSPAStacking_x                                  0x5624D0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5619F0
#define EQ_Spell__IsNoRemove_x                                     0x4C6F80
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5624E0
#define __IsResEffectSpell_x                                       0x4C6260

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA9E0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8BE0E0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8064C0
#define CTargetWnd__WndNotification_x                              0x805D50
#define CTargetWnd__RefreshTargetBuffs_x                           0x806020
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x804EB0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x80AB90

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x525780

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x55C7D0
#define EqSoundManager__PlayScriptMp3_x                            0x55C930
#define EqSoundManager__SoundAssistPlay_x                          0x66C240
#define EqSoundManager__WaveInstancePlay_x                         0x66B7B0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x519720

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x92FDB0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x550840
#define CAltAbilityData__GetMercMaxRank_x                          0x5507E0
#define CAltAbilityData__GetMaxRank_x                              0x545C70

//CTargetRing
#define CTargetRing__Cast_x                                        0x6006E0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6DD0
#define CharacterBase__CreateItemGlobalIndex_x                     0x4FFAA0
#define CharacterBase__CreateItemIndex_x                           0x6087B0
#define CharacterBase__GetItemPossession_x                         0x4B4050
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C6750
#define CharacterBase__GetEffectId_x                               0x4C6D80

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E60D0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E68F0

//messages
#define msg_spell_worn_off_x                                       0x5870A0
#define msg_new_text_x                                             0x57BFC0
#define __msgTokenTextParam_x                                      0x5896E0
#define msgTokenText_x                                             0x589930

//SpellManager
#define SpellManager__vftable_x                                    0xAB1A18
#define SpellManager__SpellManager_x                               0x66F570
#define Spellmanager__LoadTextSpells_x                             0x66FE40
#define SpellManager__GetSpellByGroupAndRank_x                     0x66F740

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x97ACB0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x500150
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x58D510
#define ItemGlobalIndex__IsEquippedLocation_x                      0x621380
#define ItemGlobalIndex__IsValidIndex_x                            0x5001B0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8BEA20
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8BECA0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7546C0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7025E0
#define CCursorAttachment__Deactivate_x                            0x7035C0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x942360
#define CEQSuiteTextureLoader__GetTexture_x                        0x942020

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4FD230

//IString
#define IString__Append_x                                          0x4EEFD0

//Camera
#define CDisplay__cameraType_x                                     0xDC3B18
#define EverQuest__Cameras_x                                       0xE86830

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x505810
#define LootFiltersManager__GetItemFilterData_x                    0x505110
#define LootFiltersManager__RemoveItemLootFilter_x                 0x505140
#define LootFiltersManager__SetItemLootFilter_x                    0x505360

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7AEAA0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9809F0
#define CResolutionHandler__GetWindowedStyle_x                     0x667000

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6FAC70

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D1160

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x71AD40
#define CGroupWnd__UpdateDisplay_x                                 0x71A0A0

//ItemBase
#define ItemBase__IsLore_x                                         0x894880
#define ItemBase__IsLoreEquipped_x                                 0x8948F0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
