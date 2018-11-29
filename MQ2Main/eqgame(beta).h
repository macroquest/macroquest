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
#define __ExpectedVersionDate                                     "Nov 29 2018"
#define __ExpectedVersionTime                                     "04:22:39"
#define __ActualVersionDate_x                                      0xACE0D4
#define __ActualVersionTime_x                                      0xACE0C8

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x6141A0
#define __MemChecker1_x                                            0x8E8BF0
#define __MemChecker2_x                                            0x6A34E0
#define __MemChecker3_x                                            0x6A3430
#define __MemChecker4_x                                            0x83FEA0
#define __EncryptPad0_x                                            0xC02340
#define __EncryptPad1_x                                            0xC605D0
#define __EncryptPad2_x                                            0xC12EC8
#define __EncryptPad3_x                                            0xC12AC8
#define __EncryptPad4_x                                            0xC50E40
#define __EncryptPad5_x                                            0x1031AE0
#define __AC1_x                                                    0x7FCA56
#define __AC2_x                                                    0x5CF22F
#define __AC3_x                                                    0x5D60BF
#define __AC4_x                                                    0x5D9EE0
#define __AC5_x                                                    0x5E009F
#define __AC6_x                                                    0x5E4666
#define __AC7_x                                                    0x5CECA0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E8A344

// Direct Input
#define DI8__Main_x                                                0x1031B04
#define DI8__Keyboard_x                                            0x1031B08
#define DI8__Mouse_x                                               0xF27764
#define DI8__Mouse_Copy_x                                          0xE851A4
#define DI8__Mouse_Check_x                                         0xF27768
#define __AutoSkillArray_x                                         0xE860BC
#define __Attack_x                                                 0xF23EC3
#define __Autofire_x                                               0xF23EC4
#define __BindList_x                                               0xBF0F20
#define g_eqCommandStates_x                                        0xBF1C90
#define __Clicks_x                                                 0xE8525C
#define __CommandList_x                                            0xBF2848
#define __CurrentMapLabel_x                                        0x1039A6C
#define __CurrentSocial_x                                          0xBDB730
#define __DoAbilityList_x                                          0xEBB9E4
#define __do_loot_x                                                0x59C9B0
#define __DrawHandler_x                                            0x16B6440
#define __GroupCount_x                                             0xE75452
#define __Guilds_x                                                 0xE7B9B0
#define __gWorld_x                                                 0xE77D2C
#define __HWnd_x                                                   0xF2777C
#define __heqmain_x                                                0x1031AC8
#define __InChatMode_x                                             0xE8518C
#define __LastTell_x                                               0xE870E0
#define __LMouseHeldTime_x                                         0xE852C8
#define __Mouse_x                                                  0x1031AEC
#define __MouseLook_x                                              0xE85222
#define __MouseEventTime_x                                         0xF24978
#define __gpbCommandEvent_x                                        0xE7776C
#define __NetStatusToggle_x                                        0xE85225
#define __PCNames_x                                                0xE8669C
#define __RangeAttackReady_x                                       0xE863A0
#define __RMouseHeldTime_x                                         0xE852C4
#define __RunWalkState_x                                           0xE85190
#define __ScreenMode_x                                             0xDC3A90
#define __ScreenX_x                                                0xE85144
#define __ScreenY_x                                                0xE85140
#define __ScreenXMax_x                                             0xE85148
#define __ScreenYMax_x                                             0xE8514C
#define __ServerHost_x                                             0xE779C3
#define __ServerName_x                                             0xEBB9A4
#define __ShiftKeyDown_x                                           0xE8581C
#define __ShowNames_x                                              0xE8655C
#define __Socials_x                                                0xEBBAA4
#define __SubscriptionType_x                                       0x107B5BC
#define __TargetAggroHolder_x                                      0x103C428
#define __ZoneType_x                                               0xE85620
#define __GroupAggro_x                                             0x103C468
#define __LoginName_x                                              0x103235C
#define __Inviter_x                                                0xF23E40
#define __AttackOnAssist_x                                         0xE86518
#define __UseTellWindows_x                                         0xE86834
#define __gfMaxZoomCameraDistance_x                                0xAC35F0
#define __gfMaxCameraDistance_x                                    0xAF0A48
#define __pulAutoRun_x                                             0xE85240
#define __pulForward_x                                             0xE8686C
#define __pulBackward_x                                            0xE86870
#define __pulTurnRight_x                                           0xE86874
#define __pulTurnLeft_x                                            0xE86878
#define __pulStrafeLeft_x                                          0xE8687C
#define __pulStrafeRight_x                                         0xE86880
//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE77D48
#define instEQZoneInfo_x                                           0xE85418
#define instKeypressHandler_x                                      0xF24928
#define pinstActiveBanker_x                                        0xE77858
#define pinstActiveCorpse_x                                        0xE7784C
#define pinstActiveGMaster_x                                       0xE77854
#define pinstActiveMerchant_x                                      0xE77848
#define pinstAggroInfo_x                                           0xC76E08
#define pinstAltAdvManager_x                                       0xDC46F0
#define pinstAuraMgr_x                                             0xC92988
#define pinstBandageTarget_x                                       0xE77878
#define pinstCamActor_x                                            0xDC3A80
#define pinstCDBStr_x                                              0xDC3424
#define pinstCDisplay_x                                            0xE77CDC
#define pinstCEverQuest_x                                          0x1031C20
#define pinstEverQuestInfo_x                                       0xE85138
#define pinstCharData_x                                            0xE77D34
#define pinstCharSpawn_x                                           0xE778B0
#define pinstControlledMissile_x                                   0xE77D30
#define pinstControlledPlayer_x                                    0xE778B0
#define pinstCResolutionHandler_x                                  0x16B6670
#define pinstCSidlManager_x                                        0x16B5504
#define pinstCXWndManager_x                                        0x16B54F8
#define instDynamicZone_x                                          0xE7B888
#define pinstDZMember_x                                            0xE7B998
#define pinstDZTimerInfo_x                                         0xE7B99C
#define pinstEQItemList_x                                          0xE73F38
#define pinstEQObjectList_x                                        0xE75128
#define instEQMisc_x                                               0xDC3360
#define pinstEQSoundManager_x                                      0xDC4F50
#define pinstEQSpellStrings_x                                      0xC84F40
#define instExpeditionLeader_x                                     0xE7B8D2
#define instExpeditionName_x                                       0xE7B912
#define pinstGroup_x                                               0xE7544E
#define pinstImeManager_x                                          0x16B54FC
#define pinstLocalPlayer_x                                         0xE77844
#define pinstMercenaryData_x                                       0xF25124
#define pinstMercenaryStats_x                                      0x103C574
#define pinstMercAltAbilities_x                                    0xDC4CC0
#define pinstModelPlayer_x                                         0xE77870
#define pinstPCData_x                                              0xE77D34
#define pinstRealEstateItems_x                                     0xF26608
#define pinstSkillMgr_x                                            0xF266D8
#define pinstSpawnManager_x                                        0xF25CC8
#define pinstSpellManager_x                                        0xF268B0
#define pinstSpellSets_x                                           0xF1CAEC
#define pinstStringTable_x                                         0xE77648
#define pinstSwitchManager_x                                       0xE752E8
#define pinstTarget_x                                              0xE778AC
#define pinstTargetObject_x                                        0xE778B8
#define pinstTargetSwitch_x                                        0xE77D3C
#define pinstTaskMember_x                                          0xDC31F4
#define pinstTrackTarget_x                                         0xE778C0
#define pinstTradeTarget_x                                         0xE7785C
#define instTributeActive_x                                        0xDC3385
#define pinstViewActor_x                                           0xDC3A7C
#define pinstWorldData_x                                           0xE77770
#define pinstZoneAddr_x                                            0xE856B8
#define pinstPlayerPath_x                                          0xF25D60
#define pinstTargetIndicator_x                                     0xF26B18
#define pinstCTargetManager_x                                      0xF26BB0
#define EQObject_Top_x                                             0xE77810

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDC3538
#define pinstCAchievementsWnd_x                                    0xDC3508
#define pinstCActionsWnd_x                                         0xDC3A1C
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDC3A20
#define pinstCAdvancedLootWnd_x                                    0xDC3568
#define pinstCAdventureLeaderboardWnd_x                            0x1033240
#define pinstCAdventureRequestWnd_x                                0x10332F0
#define pinstCAdventureStatsWnd_x                                  0x10333A0
#define pinstCAggroMeterWnd_x                                      0xDC3AC0
#define pinstCAlarmWnd_x                                           0xDC3AFC
#define pinstCAlertHistoryWnd_x                                    0xDC3D54
#define pinstCAlertStackWnd_x                                      0xDC3AB4
#define pinstCAlertWnd_x                                           0xDC3AB8
#define pinstCAltStorageWnd_x                                      0x1033700
#define pinstCAudioTriggersWindow_x                                0xC77298
#define pinstCAuraWnd_x                                            0xDC3ABC
#define pinstCAvaZoneWnd_x                                         0xDC34C4
#define pinstCBandolierWnd_x                                       0xDC3B04
#define pinstCBankWnd_x                                            0xDC34E8
#define pinstCBarterMerchantWnd_x                                  0x1034940
#define pinstCBarterSearchWnd_x                                    0x10349F0
#define pinstCBarterWnd_x                                          0x1034AA0
#define pinstCBazaarConfirmationWnd_x                              0xDC3AAC
#define pinstCBazaarSearchWnd_x                                    0xDC3A40
#define pinstCBazaarWnd_x                                          0xDC3B00
#define pinstCBlockedBuffWnd_x                                     0xDC34D4
#define pinstCBlockedPetBuffWnd_x                                  0xDC34F4
#define pinstCBodyTintWnd_x                                        0xDC3A6C
#define pinstCBookWnd_x                                            0xDC3B28
#define pinstCBreathWnd_x                                          0xDC3548
#define pinstCBuffWindowNORMAL_x                                   0xDC3D44
#define pinstCBuffWindowSHORT_x                                    0xDC3D48
#define pinstCBugReportWnd_x                                       0xDC352C
#define pinstCButtonWnd_x                                          0x16B5728
#define pinstCCastingWnd_x                                         0xDC3528
#define pinstCCastSpellWnd_x                                       0xDC3A64
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDC354C
#define pinstCChatWindowManager_x                                  0x1035560
#define pinstCClaimWnd_x                                           0x10356B8
#define pinstCColorPickerWnd_x                                     0xDC357C
#define pinstCCombatAbilityWnd_x                                   0xDC3ACC
#define pinstCCombatSkillsSelectWnd_x                              0xDC3A14
#define pinstCCompassWnd_x                                         0xDC3A5C
#define pinstCConfirmationDialog_x                                 0x103A5B8
#define pinstCContainerMgr_x                                       0xDC3AD8
#define pinstCContextMenuManager_x                                 0x16B54B8
#define pinstCCursorAttachment_x                                   0xDC3524
#define pinstCDistillerInfo_x                                      0x1038FC4
#define pinstCDynamicZoneWnd_x                                     0x1035C80
#define pinstCEditLabelWnd_x                                       0xDC3B30
#define pinstCEQMainWnd_x                                          0x1035EC8
#define pinstCEventCalendarWnd_x                                   0xDC3544
#define pinstCExtendedTargetWnd_x                                  0xDC3AA8
#define pinstCFacePick_x                                           0xDC3570
#define pinstCFellowshipWnd_x                                      0x10360C8
#define pinstCFileSelectionWnd_x                                   0xDC3558
#define pinstCFindItemWnd_x                                        0xDC3B20
#define pinstCFindLocationWnd_x                                    0x1036220
#define pinstCFriendsWnd_x                                         0xDC3A2C
#define pinstCGemsGameWnd_x                                        0xDC3AC4
#define pinstCGiveWnd_x                                            0xDC3B24
#define pinstCGroupSearchFiltersWnd_x                              0xDC3AE0
#define pinstCGroupSearchWnd_x                                     0x1036618
#define pinstCGroupWnd_x                                           0x10366C8
#define pinstCGuildBankWnd_x                                       0xE864FC
#define pinstCGuildCreationWnd_x                                   0x1036828
#define pinstCGuildMgmtWnd_x                                       0x10368D8
#define pinstCharacterCreation_x                                   0xDC3AC8
#define pinstCHelpWnd_x                                            0xDC3A78
#define pinstCHeritageSelectionWnd_x                               0xDC3588
#define pinstCHotButtonWnd_x                                       0x1038A30
#define pinstCHotButtonWnd1_x                                      0x1038A30
#define pinstCHotButtonWnd2_x                                      0x1038A34
#define pinstCHotButtonWnd3_x                                      0x1038A38
#define pinstCHotButtonWnd4_x                                      0x1038A3C
#define pinstCIconSelectionWnd_x                                   0xDC350C
#define pinstCInspectWnd_x                                         0xDC3504
#define pinstCInventoryWnd_x                                       0xDC3B08
#define pinstCInvSlotMgr_x                                         0xDC3A9C
#define pinstCItemDisplayManager_x                                 0x1038FC0
#define pinstCItemExpTransferWnd_x                                 0x10390F0
#define pinstCItemOverflowWnd_x                                    0xDC3A4C
#define pinstCJournalCatWnd_x                                      0xDC3574
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDC353C
#define pinstCKeyRingWnd_x                                         0xDC34C8
#define pinstCLargeDialogWnd_x                                     0x103B238
#define pinstCLayoutCopyWnd_x                                      0x1039440
#define pinstCLFGuildWnd_x                                         0x10394F0
#define pinstCLoadskinWnd_x                                        0xDC3AD4
#define pinstCLootFiltersCopyWnd_x                                 0xC932B8
#define pinstCLootFiltersWnd_x                                     0xDC3AEC
#define pinstCLootSettingsWnd_x                                    0xDC3B14
#define pinstCLootWnd_x                                            0xDC3564
#define pinstCMailAddressBookWnd_x                                 0xDC34FC
#define pinstCMailCompositionWnd_x                                 0xDC34E0
#define pinstCMailIgnoreListWnd_x                                  0xDC3500
#define pinstCMailWnd_x                                            0xDC3D4C
#define pinstCManageLootWnd_x                                      0xDC4B68
#define pinstCMapToolbarWnd_x                                      0xDC3B0C
#define pinstCMapViewWnd_x                                         0xDC3AE8
#define pinstCMarketplaceWnd_x                                     0xDC3550
#define pinstCMerchantWnd_x                                        0xDC3A10
#define pinstCMIZoneSelectWnd_x                                    0x1039D28
#define pinstCMusicPlayerWnd_x                                     0xDC34C0
#define pinstCNameChangeMercWnd_x                                  0xDC3A70
#define pinstCNameChangePetWnd_x                                   0xDC3A54
#define pinstCNameChangeWnd_x                                      0xDC3530
#define pinstCNoteWnd_x                                            0xDC3A74
#define pinstCObjectPreviewWnd_x                                   0xDC356C
#define pinstCOptionsWnd_x                                         0xDC3B10
#define pinstCPetInfoWnd_x                                         0xDC34E4
#define pinstCPetitionQWnd_x                                       0xDC3584
//#define pinstCPlayerCustomizationWnd_x                           0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDC3A68
#define pinstCPlayerWnd_x                                          0xDC3A24
#define pinstCPopupWndManager_x                                    0x103A5B8
#define pinstCProgressionSelectionWnd_x                            0x103A668
#define pinstCPurchaseGroupWnd_x                                   0xDC3A08
#define pinstCPurchaseWnd_x                                        0xDC3578
#define pinstCPvPLeaderboardWnd_x                                  0x103A718
#define pinstCPvPStatsWnd_x                                        0x103A7C8
#define pinstCQuantityWnd_x                                        0xDC3514
#define pinstCRaceChangeWnd_x                                      0xDC3554
#define pinstCRaidOptionsWnd_x                                     0xDC3AE4
#define pinstCRaidWnd_x                                            0xDC3518
#define pinstCRealEstateItemsWnd_x                                 0xDC351C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDC3540
#define pinstCRealEstateManageWnd_x                                0xDC3B1C
#define pinstCRealEstateNeighborhoodWnd_x                          0xDC3D3C
#define pinstCRealEstatePlotSearchWnd_x                            0xDC34CC
#define pinstCRealEstatePurchaseWnd_x                              0xDC34EC
#define pinstCRespawnWnd_x                                         0xDC3ADC
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDC3AB0
#define pinstCSendMoneyWnd_x                                       0xDC3D38
#define pinstCServerListWnd_x                                      0xDC3D50
#define pinstCSkillsSelectWnd_x                                    0xDC3580
#define pinstCSkillsWnd_x                                          0xDC355C
#define pinstCSocialEditWnd_x                                      0xDC3520
#define pinstCSocialWnd_x                                          0xDC3AA0
#define pinstCSpellBookWnd_x                                       0xDC3AA4
#define pinstCStoryWnd_x                                           0xDC3A28
#define pinstCTargetOfTargetWnd_x                                  0x103C5F8
#define pinstCTargetWnd_x                                          0xDC34D8
#define pinstCTaskOverlayWnd_x                                     0xDC34D0
#define pinstCTaskSelectWnd_x                                      0x103C750
#define pinstCTaskManager_x                                        0xC93AB8
#define pinstCTaskTemplateSelectWnd_x                              0x103C800
#define pinstCTaskWnd_x                                            0x103C8B0
#define pinstCTextEntryWnd_x                                       0xDC3A60
#define pinstCTextOverlay_x                                        0xC775A8
#define pinstCTimeLeftWnd_x                                        0xDC3560
#define pinstCTipWndCONTEXT_x                                      0x103CAB4
#define pinstCTipWndOFDAY_x                                        0x103CAB0
#define pinstCTitleWnd_x                                           0x103CB60
#define pinstCTrackingWnd_x                                        0xDC34DC
#define pinstCTradeskillWnd_x                                      0x103CCC8
#define pinstCTradeWnd_x                                           0xDC3A8C
#define pinstCTrainWnd_x                                           0xDC3510
#define pinstCTributeBenefitWnd_x                                  0x103CEC8
#define pinstCTributeMasterWnd_x                                   0x103CF78
#define pinstCTributeTrophyWnd_x                                   0x103D028
#define pinstCVideoModesWnd_x                                      0xDC3AD0
#define pinstCVoiceMacroWnd_x                                      0xF270E0
#define pinstCVoteResultsWnd_x                                     0xDC3A0C
#define pinstCVoteWnd_x                                            0xDC358C
#define pinstCWebManager_x                                         0xF27244
#define pinstCZoneGuideWnd_x                                       0xDC3B2C
#define pinstCZonePathWnd_x                                        0xDC3D40

#define pinstEQSuiteTextureLoader_x                                0xC620A0
#define pinstItemIconCache_x                                       0x1035E80
#define pinstLootFiltersManager_x                                  0xC93368
#define pinstRewardSelectionWnd_x                                  0x103AF10

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC12ABC
#define __CastRay_x                                                0x597ED0
#define __CastRay2_x                                               0x597F20
#define __ConvertItemTags_x                                        0x5B2B00
#define __CrashHandler_x                                           0x849870
#define __EQGetTime_x                                              0x8E86E0
#define __ExecuteCmd_x                                             0x590820
#define __FixHeading_x                                             0x978D00
#define __get_bearing_x                                            0x597A20
#define __get_melee_range_x                                        0x598110
#define __GetAnimationCache_x                                      0x706DB0
#define __GetGaugeValueFromEQ_x                                    0x7FB260
#define __GetLabelFromEQ_x                                         0x7FC9E0
#define __GetXTargetType_x                                         0x97A760
#define __HeadingDiff_x                                            0x978D70
#define __HelpPath_x                                               0xF24594
#define __LoadFrontEnd_x                                           0x69F340
#define __NewUIINI_x                                               0x7FAF30
#define __pCrashHandler_x                                          0x105A418
#define __ProcessGameEvents_x                                      0x5F5880
#define __ProcessMouseEvent_x                                      0x5F5040
#define __SaveColors_x                                             0x5417F0
#define __STMLToText_x                                             0x91C300
#define __ToggleKeyRingItem_x                                      0x504720
#define CrashDetected_x                                            0x6A0E30
#define DrawNetStatus_x                                            0x6216F0
#define Expansion_HoT_x                                            0xE86504
#define Teleport_Table_Size_x                                      0xE77800
#define Teleport_Table_x                                           0xE75640
#define Util__FastTime_x                                           0x8E82A0
#define wwsCrashReportCheckForUploader_x                           0x84A470
#define wwsCrashReportPlatformLaunchUploader_x                     0x84CB50
#define __HandleMouseWheel_x                                       0x6A3590

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B530
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4943C0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x494180

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x549350
#define AltAdvManager__IsAbilityReady_x                            0x5482A0
#define AltAdvManager__GetAAById_x                                 0x5484A0
#define AltAdvManager__CanTrainAbility_x                           0x548510
#define AltAdvManager__CanSeeAbility_x                             0x548870

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C73A0
#define CharacterZoneClient__HasSkill_x                            0x4D2070
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3790
#define CharacterZoneClient__IsStackBlocked_x                      0x4BB810
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7F90
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D6140
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D6220
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D6300
#define CharacterZoneClient__FindAffectSlot_x                      0x4C02F0
#define CharacterZoneClient__BardCastBard_x                        0x4C2F50
#define CharacterZoneClient__GetMaxEffects_x                       0x4B8060
#define CharacterZoneClient__GetEffect_x                           0x4B7ED0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C12F0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C13C0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1410
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1560
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1730

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6C9220

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D6CA0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x603E40
#define CButtonWnd__CButtonWnd_x                                   0x918720

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F5810
#define CChatManager__InitContextMenu_x                            0x6EF8B0
#define CChatManager__FreeChatWindow_x                             0x6F4720
#define CChatManager__GetLockedActiveChatWindow_x                  0x6F90B0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F55B0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x92CE10
#define CContextMenu__dCContextMenu_x                              0x92D040
#define CContextMenu__AddMenuItem_x                                0x92D050
#define CContextMenu__RemoveMenuItem_x                             0x92D360
#define CContextMenu__RemoveAllMenuItems_x                         0x92D380
#define CContextMenu__CheckMenuItem_x                              0x92D400
#define CContextMenu__SetMenuItem_x                                0x92D280
#define CContextMenu__AddSeparator_x                               0x92D1E0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x92D9A0
#define CContextMenuManager__RemoveMenu_x                          0x92DA10
#define CContextMenuManager__PopupMenu_x                           0x92DAD0
#define CContextMenuManager__Flush_x                               0x92D940
#define CContextMenuManager__GetMenu_x                             0x496670

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8C9090
#define CChatService__GetFriendName_x                              0x8C90A0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F5D80
#define CChatWindow__Clear_x                                       0x6F6DD0
#define CChatWindow__WndNotification_x                             0x6F7330

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x92A2B0
#define CComboWnd__Draw_x                                          0x9297B0
#define CComboWnd__GetCurChoice_x                                  0x92A0F0
#define CComboWnd__GetListRect_x                                   0x929C60
#define CComboWnd__GetTextRect_x                                   0x92A320
#define CComboWnd__InsertChoice_x                                  0x929DF0
#define CComboWnd__SetColors_x                                     0x929DC0
#define CComboWnd__SetChoice_x                                     0x92A0C0
#define CComboWnd__GetItemCount_x                                  0x92A100
#define CComboWnd__GetCurChoiceText_x                              0x92A140

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6FEFB0
#define CContainerWnd__vftable_x                                   0xAD7378
#define CContainerWnd__SetContainer_x                              0x700520

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x5415B0
#define CDisplay__GetClickedActor_x                                0x534560
#define CDisplay__GetUserDefinedColor_x                            0x52CC40
#define CDisplay__GetWorldFilePath_x                               0x535FB0
#define CDisplay__is3dON_x                                         0x531230
#define CDisplay__ReloadUI_x                                       0x53B6D0
#define CDisplay__WriteTextHD2_x                                   0x531010
#define CDisplay__TrueDistance_x                                   0x537C10
#define CDisplay__SetViewActor_x                                   0x533EB0
#define CDisplay__GetFloorHeight_x                                 0x5312F0
#define CDisplay__SetRenderWindow_x                                0x52FC20
#define CDisplay__ToggleScreenshotMode_x                           0x533980

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x94C3B0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x931530
#define CEditWnd__GetCharIndexPt_x                                 0x932430
#define CEditWnd__GetDisplayString_x                               0x9322D0
#define CEditWnd__GetHorzOffset_x                                  0x930B60
#define CEditWnd__GetLineForPrintableChar_x                        0x933570
#define CEditWnd__GetSelStartPt_x                                  0x9326E0
#define CEditWnd__GetSTMLSafeText_x                                0x9320F0
#define CEditWnd__PointFromPrintableChar_x                         0x9331A0
#define CEditWnd__SelectableCharFromPoint_x                        0x933310
#define CEditWnd__SetEditable_x                                    0x9327B0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E3B90
#define CEverQuest__ClickedPlayer_x                                0x5D5EA0
#define CEverQuest__CreateTargetIndicator_x                        0x5F2B30
#define CEverQuest__DeleteTargetIndicator_x                        0x5F2BC0
#define CEverQuest__DoTellWindow_x                                 0x4E3220
#define CEverQuest__OutputTextToLog_x                              0x4E3450
#define CEverQuest__DropHeldItemOnGround_x                         0x5CB760
#define CEverQuest__dsp_chat_x                                     0x4E37E0
#define CEverQuest__trimName_x                                     0x5EF0A0
#define CEverQuest__Emote_x                                        0x5E43A0
#define CEverQuest__EnterZone_x                                    0x5DE4F0
#define CEverQuest__GetBodyTypeDesc_x                              0x5E8950
#define CEverQuest__GetClassDesc_x                                 0x5E8F90
#define CEverQuest__GetClassThreeLetterCode_x                      0x5E9590
#define CEverQuest__GetDeityDesc_x                                 0x5F1480
#define CEverQuest__GetLangDesc_x                                  0x5E9750
#define CEverQuest__GetRaceDesc_x                                  0x5E8F70
#define CEverQuest__InterpretCmd_x                                 0x5F1A50
#define CEverQuest__LeftClickedOnPlayer_x                          0x5CF950
#define CEverQuest__LMouseUp_x                                     0x5CDCD0
#define CEverQuest__RightClickedOnPlayer_x                         0x5D0230
#define CEverQuest__RMouseUp_x                                     0x5CEC60
#define CEverQuest__SetGameState_x                                 0x5CB4F0
#define CEverQuest__UPCNotificationFlush_x                         0x5EEFA0
#define CEverQuest__IssuePetCommand_x                              0x5EAB40
#define CEverQuest__ReportSuccessfulHit_x                          0x5E57A0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x710FA0
#define CGaugeWnd__CalcLinesFillRect_x                             0x711000
#define CGaugeWnd__Draw_x                                          0x710690

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACB80
#define CGuild__GetGuildName_x                                     0x4ABC60
#define CGuild__GetGuildIndex_x                                    0x4ABFF0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x72C350

//CHotButton
#define CHotButton__SetButtonSize_x                                0x604200

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7392F0
#define CInvSlotMgr__MoveItem_x                                    0x738050
#define CInvSlotMgr__SelectSlot_x                                  0x7393C0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x736900
#define CInvSlot__SliderComplete_x                                 0x734660
#define CInvSlot__GetItemBase_x                                    0x733FF0
#define CInvSlot__UpdateItem_x                                     0x734160

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x73AD10
#define CInvSlotWnd__CInvSlotWnd_x                                 0x739FE0
#define CInvSlotWnd__HandleLButtonUp_x                             0x73A890

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F7460
#define CItemDisplayWnd__UpdateStrings_x                           0x748EC0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x742EE0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7433E0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7494E0
#define CItemDisplayWnd__AboutToShow_x                             0x748B30
#define CItemDisplayWnd__WndNotification_x                         0x74AA10

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x82EC40

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x74EB60

// CLabel 
#define CLabel__Draw_x                                             0x7545E0

// CListWnd
#define CListWnd__CListWnd_x                                       0x902BF0
#define CListWnd__dCListWnd_x                                      0x902F10
#define CListWnd__AddColumn_x                                      0x9071F0
#define CListWnd__AddColumn1_x                                     0x907240
#define CListWnd__AddLine_x                                        0x9075D0
#define CListWnd__AddString_x                                      0x9073D0
#define CListWnd__CalculateFirstVisibleLine_x                      0x906FC0
#define CListWnd__CalculateVSBRange_x                              0x906DB0
#define CListWnd__ClearSel_x                                       0x907DB0
#define CListWnd__ClearAllSel_x                                    0x907E10
#define CListWnd__CloseAndUpdateEditWindow_x                       0x908810
#define CListWnd__Compare_x                                        0x9066F0
#define CListWnd__Draw_x                                           0x903010
#define CListWnd__DrawColumnSeparators_x                           0x9057D0
#define CListWnd__DrawHeader_x                                     0x905C30
#define CListWnd__DrawItem_x                                       0x906030
#define CListWnd__DrawLine_x                                       0x905930
#define CListWnd__DrawSeparator_x                                  0x905870
#define CListWnd__EnableLine_x                                     0x9050C0
#define CListWnd__EnsureVisible_x                                  0x908740
#define CListWnd__ExtendSel_x                                      0x907CE0
#define CListWnd__GetColumnMinWidth_x                              0x904C00
#define CListWnd__GetColumnWidth_x                                 0x904B70
#define CListWnd__GetCurSel_x                                      0x904500
#define CListWnd__GetItemAtPoint_x                                 0x905330
#define CListWnd__GetItemAtPoint1_x                                0x9053A0
#define CListWnd__GetItemData_x                                    0x904580
#define CListWnd__GetItemHeight_x                                  0x904940
#define CListWnd__GetItemIcon_x                                    0x904710
#define CListWnd__GetItemRect_x                                    0x9051B0
#define CListWnd__GetItemText_x                                    0x9045C0
#define CListWnd__GetSelList_x                                     0x907E60
#define CListWnd__GetSeparatorRect_x                               0x9055E0
#define CListWnd__InsertLine_x                                     0x9079C0
#define CListWnd__RemoveLine_x                                     0x907B10
#define CListWnd__SetColors_x                                      0x906D80
#define CListWnd__SetColumnJustification_x                         0x906AB0
#define CListWnd__SetColumnWidth_x                                 0x9069D0
#define CListWnd__SetCurSel_x                                      0x907C20
#define CListWnd__SetItemColor_x                                   0x908400
#define CListWnd__SetItemData_x                                    0x9083C0
#define CListWnd__SetItemText_x                                    0x907FE0
#define CListWnd__ShiftColumnSeparator_x                           0x906B70
#define CListWnd__Sort_x                                           0x906870
#define CListWnd__ToggleSel_x                                      0x907C50

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x769C30
#define CMapViewWnd__GetWorldCoordinates_x                         0x768340
#define CMapViewWnd__HandleLButtonDown_x                           0x7653A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x78CEF0
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x78D7D0
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x78DD00
#define CMerchantWnd__SelectRecoverySlot_x                         0x790B30
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x78B8D0
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x796720
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x78CB30

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x896CE0
#define CPacketScrambler__hton_x                                   0x896CD0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x921890
#define CSidlManager__FindScreenPieceTemplate_x                    0x921CA0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x921A90
#define CSidlManager__CreateLabel_x                                0x7EE870
#define CSidlManager__CreateXWndFromTemplate_x                     0x924D70
#define CSidlManager__CreateXWndFromTemplate1_x                    0x924F40
#define CSidlManager__CreateXWnd_x                                 0x7EE7A0
#define CSidlManager__CreateHotButtonWnd_x                         0x7EED60

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x91E430
#define CSidlScreenWnd__CalculateVSBRange_x                        0x91E340
#define CSidlScreenWnd__ConvertToRes_x                             0x943250
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x91DDE0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x91DAD0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x91DBA0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x91DC70
#define CSidlScreenWnd__DrawSidlPiece_x                            0x91E8A0
#define CSidlScreenWnd__EnableIniStorage_x                         0x91ED70
#define CSidlScreenWnd__GetSidlPiece_x                             0x91EA90
#define CSidlScreenWnd__Init1_x                                    0x91D6C0
#define CSidlScreenWnd__LoadIniInfo_x                              0x91EDC0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x91F900
#define CSidlScreenWnd__LoadSidlScreen_x                           0x91CAE0
#define CSidlScreenWnd__StoreIniInfo_x                             0x91F480
#define CSidlScreenWnd__StoreIniVis_x                              0x91F7E0
#define CSidlScreenWnd__WndNotification_x                          0x91E7B0
#define CSidlScreenWnd__GetChildItem_x                             0x91ECF0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x90E680
#define CSidlScreenWnd__m_layoutCopy_x                             0x16B5388

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6687D0
#define CSkillMgr__GetSkillCap_x                                   0x6689B0
#define CSkillMgr__GetNameToken_x                                  0x667F60

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x92E7A0
#define CSliderWnd__SetValue_x                                     0x92E610
#define CSliderWnd__SetNumTicks_x                                  0x92E670

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7F46A0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x935400
#define CStmlWnd__CalculateHSBRange_x                              0x9364A0
#define CStmlWnd__CalculateVSBRange_x                              0x936420
#define CStmlWnd__CanBreakAtCharacter_x                            0x93A7D0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x93B3C0
#define CStmlWnd__ForceParseNow_x                                  0x9359F0
#define CStmlWnd__GetNextTagPiece_x                                0x93A730
#define CStmlWnd__GetSTMLText_x                                    0x4F5130
#define CStmlWnd__GetVisibleText_x                                 0x935A10
#define CStmlWnd__InitializeWindowVariables_x                      0x93B210
#define CStmlWnd__MakeStmlColorTag_x                               0x934B90
#define CStmlWnd__MakeWndNotificationTag_x                         0x934C00
#define CStmlWnd__SetSTMLText_x                                    0x933C60
#define CStmlWnd__StripFirstSTMLLines_x                            0x93C510
#define CStmlWnd__UpdateHistoryString_x                            0x93B5D0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9401C0
#define CTabWnd__DrawCurrentPage_x                                 0x9407E0
#define CTabWnd__DrawTab_x                                         0x9405B0
#define CTabWnd__GetCurrentPage_x                                  0x93FA20
#define CTabWnd__GetPageInnerRect_x                                0x93FC60
#define CTabWnd__GetTabInnerRect_x                                 0x93FBA0
#define CTabWnd__GetTabRect_x                                      0x93FA50
#define CTabWnd__InsertPage_x                                      0x93FE50
#define CTabWnd__SetPage_x                                         0x93FCE0
#define CTabWnd__SetPageRect_x                                     0x940100
#define CTabWnd__UpdatePage_x                                      0x940470
#define CTabWnd__GetPageFromTabIndex_x                             0x9404F0
#define CTabWnd__GetCurrentTabIndex_x                              0x93FA10

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x74EFE0
#define CPageWnd__SetTabText_x                                     0x94C7C0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A66C0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x90B500
#define CTextureFont__GetTextExtent_x                              0x90B6C0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x69C190
#define CHtmlComponentWnd__ValidateUri_x                           0x72DD50
#define CHtmlWnd__SetClientCallbacks_x                             0x6091E0
#define CHtmlWnd__AddObserver_x                                    0x609200
#define CHtmlWnd__RemoveObserver_x                                 0x609260
#define Window__getProgress_x                                      0x8474D0
#define Window__getStatus_x                                        0x8474F0
#define Window__getURI_x                                           0x847500

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x948D40

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F8520

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ADE20
#define CXStr__CXStr1_x                                            0x4F02B0
#define CXStr__CXStr3_x                                            0x8E4810
#define CXStr__dCXStr_x                                            0x473090
#define CXStr__operator_equal_x                                    0x8E4A40
#define CXStr__operator_equal1_x                                   0x8E4A80
#define CXStr__operator_plus_equal1_x                              0x8E5510

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x92CA30
#define CXWnd__BringToTop_x                                        0x911CF0
#define CXWnd__Center_x                                            0x911870
#define CXWnd__ClrFocus_x                                          0x9116A0
#define CXWnd__Destroy_x                                           0x911750
#define CXWnd__DoAllDrawing_x                                      0x90DE30
#define CXWnd__DrawChildren_x                                      0x90DE00
#define CXWnd__DrawColoredRect_x                                   0x90E270
#define CXWnd__DrawTooltip_x                                       0x90C950
#define CXWnd__DrawTooltipAtPoint_x                                0x90CA10
#define CXWnd__GetBorderFrame_x                                    0x90E0D0
#define CXWnd__GetChildWndAt_x                                     0x911D90
#define CXWnd__GetClientClipRect_x                                 0x910000
#define CXWnd__GetScreenClipRect_x                                 0x9100D0
#define CXWnd__GetScreenRect_x                                     0x910260
#define CXWnd__GetTooltipRect_x                                    0x90E2C0
#define CXWnd__GetWindowTextA_x                                    0x497E00
#define CXWnd__IsActive_x                                          0x914C40
#define CXWnd__IsDescendantOf_x                                    0x910C40
#define CXWnd__IsReallyVisible_x                                   0x910C70
#define CXWnd__IsType_x                                            0x9123D0
#define CXWnd__Move_x                                              0x910CD0
#define CXWnd__Move1_x                                             0x910D80
#define CXWnd__ProcessTransition_x                                 0x911820
#define CXWnd__Refade_x                                            0x911040
#define CXWnd__Resize_x                                            0x9112C0
#define CXWnd__Right_x                                             0x911AB0
#define CXWnd__SetFocus_x                                          0x911660
#define CXWnd__SetFont_x                                           0x9116D0
#define CXWnd__SetKeyTooltip_x                                     0x9121F0
#define CXWnd__SetMouseOver_x                                      0x90F1F0
#define CXWnd__StartFade_x                                         0x910B10
#define CXWnd__GetChildItem_x                                      0x911EF0
#define CXWnd__SetParent_x                                         0x9109E0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x944320

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x914C80
#define CXWndManager__DrawWindows_x                                0x914CA0
#define CXWndManager__GetKeyboardFlags_x                           0x917400
#define CXWndManager__HandleKeyboardMsg_x                          0x917010
#define CXWndManager__RemoveWnd_x                                  0x917650
#define CXWndManager__RemovePendingDeletionWnd_x                   0x917BA0

// CDBStr
#define CDBStr__GetString_x                                        0x52BBF0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8F40
#define EQ_Character__Cur_HP_x                                     0x4CF0F0
#define EQ_Character__Cur_Mana_x                                   0x4D6800
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BBE50
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFA20
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFB70
#define EQ_Character__GetHPRegen_x                                 0x4DC760
#define EQ_Character__GetEnduranceRegen_x                          0x4DCD70
#define EQ_Character__GetManaRegen_x                               0x4DD1B0
#define EQ_Character__Max_Endurance_x                              0x62F250
#define EQ_Character__Max_HP_x                                     0x4CEF20
#define EQ_Character__Max_Mana_x                                   0x62F050
#define EQ_Character__doCombatAbility_x                            0x631720
#define EQ_Character__UseSkill_x                                   0x4DEFC0
#define EQ_Character__GetConLevel_x                                0x6285F0
#define EQ_Character__IsExpansionFlag_x                            0x58EFF0
#define EQ_Character__TotalEffect_x                                0x4C24D0
#define EQ_Character__GetPCSpellAffect_x                           0x4BCA40
#define EQ_Character__SpellDuration_x                              0x4BC570
#define EQ_Character__FindItemByRecord_x                           0x4D4700
#define EQ_Character__GetAdjustedSkill_x                           0x4D1E30
#define EQ_Character__GetBaseSkill_x                               0x4D2DD0
#define EQ_Character__CanUseItem_x                                 0x4D6B10

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B6040

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6455C0

//PcClient
#define PcClient__PcClient_x                                       0x625D30

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6BD0
#define CCharacterListWnd__EnterWorld_x                            0x4B6610
#define CCharacterListWnd__Quit_x                                  0x4B6320
#define CCharacterListWnd__UpdateList_x                            0x4B67A0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x60A410
#define EQ_Item__CreateItemTagString_x                             0x890670
#define EQ_Item__IsStackable_x                                     0x895090
#define EQ_Item__GetImageNum_x                                     0x8920A0
#define EQ_Item__CreateItemClient_x                                0x6095E0
#define EQ_Item__GetItemValue_x                                    0x893310
#define EQ_Item__ValueSellMerchant_x                               0x896870
#define EQ_Item__IsKeyRingItem_x                                   0x8949E0
#define EQ_Item__CanGoInBag_x                                      0x60A530
#define EQ_Item__GetMaxItemCount_x                                 0x8936E0
#define EQ_Item__GetHeldItem_x                                     0x891F70
#define EQ_Item__GetAugmentFitBySlot_x                             0x88FFC0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54A070
#define EQ_LoadingS__Array_x                                       0xBEA130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x62FBB0
#define EQ_PC__GetAlternateAbilityId_x                             0x89FB10
#define EQ_PC__GetCombatAbility_x                                  0x8A0180
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A01F0
#define EQ_PC__GetItemRecastTimer_x                                0x631CA0
#define EQ_PC__HasLoreItem_x                                       0x628DC0
#define EQ_PC__AlertInventoryChanged_x                             0x627F30
#define EQ_PC__GetPcZoneClient_x                                   0x653E10
#define EQ_PC__RemoveMyAffect_x                                    0x634E90
#define EQ_PC__GetKeyRingItems_x                                   0x8A0A90
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A0810
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A0D80

// EQItemList 
#define EQItemList__EQItemList_x                                   0x595460
#define EQItemList__add_object_x                                   0x5C0E20
#define EQItemList__add_item_x                                     0x595A70
#define EQItemList__delete_item_x                                  0x595AC0
#define EQItemList__FreeItemList_x                                 0x5959C0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x529190

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x646E40
#define EQPlayer__dEQPlayer_x                                      0x63A500
#define EQPlayer__DoAttack_x                                       0x64EAD0
#define EQPlayer__EQPlayer_x                                       0x63ABB0
#define EQPlayer__SetNameSpriteState_x                             0x63EE70
#define EQPlayer__SetNameSpriteTint_x                              0x63FD40
#define PlayerBase__HasProperty_j_x                                0x9770E0
#define EQPlayer__IsTargetable_x                                   0x977580
#define EQPlayer__CanSee_x                                         0x9773E0
#define EQPlayer__CanSee1_x                                        0x9774B0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9771A0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6518A0
#define PlayerZoneClient__GetLevel_x                               0x653E50
#define PlayerZoneClient__IsValidTeleport_x                        0x5C1F70
#define PlayerZoneClient__LegalPlayerRace_x                        0x5433F0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x649C10
#define EQPlayerManager__GetSpawnByName_x                          0x649C30
#define EQPlayerManager__GetPlayerFromPartialName_x                0x649CC0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x60DDB0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x60DDF0
#define KeypressHandler__ClearCommandStateArray_x                  0x60F1E0
#define KeypressHandler__HandleKeyDown_x                           0x60F200
#define KeypressHandler__HandleKeyUp_x                             0x60F2A0
#define KeypressHandler__SaveKeymapping_x                          0x60F680

// MapViewMap 
#define MapViewMap__Clear_x                                        0x765AC0
#define MapViewMap__SaveEx_x                                       0x768E60
#define MapViewMap__SetZoom_x                                      0x76D520

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B3F30

// StringTable 
#define StringTable__getString_x                                   0x8AEEE0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x634B00
#define PcZoneClient__RemovePetEffect_x                            0x635130
#define PcZoneClient__HasAlternateAbility_x                        0x62EE90
#define PcZoneClient__GetCurrentMod_x                              0x4E20C0
#define PcZoneClient__GetModCap_x                                  0x4E1FC0
#define PcZoneClient__CanEquipItem_x                               0x62F540
#define PcZoneClient__GetItemByID_x                                0x632110
#define PcZoneClient__GetItemByItemClass_x                         0x632260
#define PcZoneClient__RemoveBuffEffect_x                           0x635150
#define PcZoneClient__BandolierSwap_x                              0x630170

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C6C20

//IconCache
#define IconCache__GetIcon_x                                       0x706640

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6FE150
#define CContainerMgr__CloseContainer_x                            0x6FE420
#define CContainerMgr__OpenExperimentContainer_x                   0x6FEEA0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C0FF0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x602630

//CLootWnd
#define CLootWnd__LootAll_x                                        0x75BF80
#define CLootWnd__RequestLootSlot_x                                0x75B330

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x562510
#define EQ_Spell__SpellAffects_x                                   0x562980
#define EQ_Spell__SpellAffectBase_x                                0x562740
#define EQ_Spell__IsStackable_x                                    0x4C6CB0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6B30
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3F50
#define EQ_Spell__IsSPAStacking_x                                  0x5637B0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x562CD0
#define EQ_Spell__IsNoRemove_x                                     0x4C6C90
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5637C0
#define __IsResEffectSpell_x                                       0x4C6010

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA890

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8BE4E0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8067D0
#define CTargetWnd__WndNotification_x                              0x806060
#define CTargetWnd__RefreshTargetBuffs_x                           0x806330
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8051C0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x80AEA0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x526BB0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x55DA90
#define EqSoundManager__PlayScriptMp3_x                            0x55DBF0
#define EqSoundManager__SoundAssistPlay_x                          0x66C6E0
#define EqSoundManager__WaveInstancePlay_x                         0x66BC50

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51ABC0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x930180

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x551DA0
#define CAltAbilityData__GetMercMaxRank_x                          0x551D40
#define CAltAbilityData__GetMaxRank_x                              0x547150

//CTargetRing
#define CTargetRing__Cast_x                                        0x600730

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6B10
#define CharacterBase__CreateItemGlobalIndex_x                     0x500BF0
#define CharacterBase__CreateItemIndex_x                           0x6087F0
#define CharacterBase__GetItemPossession_x                         0x4B3E00
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C6B70
#define CharacterBase__GetEffectId_x                               0x4C6AC0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E62B0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E6AD0

//messages
#define msg_spell_worn_off_x                                       0x587090
#define msg_new_text_x                                             0x57BEB0
#define __msgTokenTextParam_x                                      0x589700
#define msgTokenText_x                                             0x589950

//SpellManager
#define SpellManager__vftable_x                                    0xAB1A90
#define SpellManager__SpellManager_x                               0x66FA10
#define Spellmanager__LoadTextSpells_x                             0x6702E0
#define SpellManager__GetSpellByGroupAndRank_x                     0x66FBE0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x97B050

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5012A0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x58D530
#define ItemGlobalIndex__IsEquippedLocation_x                      0x621550
#define ItemGlobalIndex__IsValidIndex_x                            0x501300

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8BEE20
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8BF0A0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x754930

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x702890
#define CCursorAttachment__Deactivate_x                            0x703870

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x942820
#define CEQSuiteTextureLoader__GetTexture_x                        0x9424E0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4FE210

//IString
#define IString__Append_x                                          0x4EF3A0

//Camera
#define CDisplay__cameraType_x                                     0xDC3B34
#define EverQuest__Cameras_x                                       0xE86840

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x506990
#define LootFiltersManager__GetItemFilterData_x                    0x506290
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5062C0
#define LootFiltersManager__SetItemLootFilter_x                    0x5064E0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7AEEE0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x980D70
#define CResolutionHandler__GetWindowedStyle_x                     0x6672B0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6FAF10

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D1670

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x71B100
#define CGroupWnd__UpdateDisplay_x                                 0x71A470

//ItemBase
#define ItemBase__IsLore_x                                         0x894A40
#define ItemBase__IsLoreEquipped_x                                 0x894AB0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
