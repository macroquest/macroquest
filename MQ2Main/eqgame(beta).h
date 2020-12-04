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
#define __ExpectedVersionDate                                     "Nov 24 2020"
#define __ExpectedVersionTime                                     "04:20:38"
#define __ActualVersionDate_x                                      0xAF655C
#define __ActualVersionTime_x                                      0xAF6550
#define __ActualVersionBuild_x                                     0xAE457C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x644160
#define __MemChecker1_x                                            0x8F7720
#define __MemChecker2_x                                            0x6B4910
#define __MemChecker3_x                                            0x6B4860
#define __MemChecker4_x                                            0x84DAE0
#define __EncryptPad0_x                                            0xC2C9C8
#define __EncryptPad1_x                                            0xC8A210
#define __EncryptPad2_x                                            0xC3CD90
#define __EncryptPad3_x                                            0xC3C990
#define __EncryptPad4_x                                            0xC7A7A0
#define __EncryptPad5_x                                            0xF4D0F0
#define __AC1_x                                                    0x80C536
#define __AC2_x                                                    0x5FD96F
#define __AC3_x                                                    0x604FC0
#define __AC4_x                                                    0x608F70
#define __AC5_x                                                    0x60F26F
#define __AC6_x                                                    0x613726
#define __AC7_x                                                    0x5FD3E0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1912E0

// Direct Input
#define DI8__Main_x                                                0xF4D118
#define DI8__Keyboard_x                                            0xF4D11C
#define DI8__Mouse_x                                               0xF4D0FC
#define DI8__Mouse_Copy_x                                          0xEA59E4
#define DI8__Mouse_Check_x                                         0xF4AC44
#define __AutoSkillArray_x                                         0xEA6900
#define __Attack_x                                                 0xF4472F
#define __Autofire_x                                               0xF44730
#define __BindList_x                                               0xC1B400
#define g_eqCommandStates_x                                        0xC1C180
#define __Clicks_x                                                 0xEA5A9C
#define __CommandList_x                                            0xC1CD40
#define __CurrentMapLabel_x                                        0xF5D14C
#define __CurrentSocial_x                                          0xC047D4
#define __DoAbilityList_x                                          0xEDC250
#define __do_loot_x                                                0x5C9480
#define __DrawHandler_x                                            0x15DC140
#define __GroupCount_x                                             0xE9E502
#define __Guilds_x                                                 0xEA4920
#define __gWorld_x                                                 0xE9EC98
#define __HWnd_x                                                   0xF4D100
#define __heqmain_x                                                0xF4D0D8
#define __InChatMode_x                                             0xEA59CC
#define __LastTell_x                                               0xEA794C
#define __LMouseHeldTime_x                                         0xEA5B08
#define __Mouse_x                                                  0xF4D104
#define __MouseLook_x                                              0xEA5A62
#define __MouseEventTime_x                                         0xF45214
#define __gpbCommandEvent_x                                        0xE9E758
#define __NetStatusToggle_x                                        0xEA5A65
#define __PCNames_x                                                0xEA6EFC
#define __RangeAttackReady_x                                       0xEA6BE4
#define __RMouseHeldTime_x                                         0xEA5B04
#define __RunWalkState_x                                           0xEA59D0
#define __ScreenMode_x                                             0xDEC4B0
#define __ScreenX_x                                                0xEA5984
#define __ScreenY_x                                                0xEA5980
#define __ScreenXMax_x                                             0xEA5988
#define __ScreenYMax_x                                             0xEA598C
#define __ServerHost_x                                             0xE9E92B
#define __ServerName_x                                             0xEDC210
#define __ShiftKeyDown_x                                           0xEA6060
#define __ShowNames_x                                              0xEA6DA0
#define EverQuestInfo__bSocialChanged_x                            0xEDC298
#define __Socials_x                                                0xEDC310
#define __SubscriptionType_x                                       0xFA1410
#define __TargetAggroHolder_x                                      0xF5FB00
#define __ZoneType_x                                               0xEA5E60
#define __GroupAggro_x                                             0xF5FB40
#define __LoginName_x                                              0xF4A8D4
#define __Inviter_x                                                0xF446AC
#define __AttackOnAssist_x                                         0xEA6D5C
#define __UseTellWindows_x                                         0xEA7094
#define __gfMaxZoomCameraDistance_x                                0xAEE178
#define __gfMaxCameraDistance_x                                    0xB16E08
#define __pulAutoRun_x                                             0xEA5A80
#define __pulForward_x                                             0xEA70CC
#define __pulBackward_x                                            0xEA70D0
#define __pulTurnRight_x                                           0xEA70D4
#define __pulTurnLeft_x                                            0xEA70D8
#define __pulStrafeLeft_x                                          0xEA70DC
#define __pulStrafeRight_x                                         0xEA70E0

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEA0CB8
#define instEQZoneInfo_x                                           0xEA5C58
#define pinstActiveBanker_x                                        0xE9EC44
#define pinstActiveCorpse_x                                        0xE9EC3C
#define pinstActiveGMaster_x                                       0xE9EC40
#define pinstActiveMerchant_x                                      0xE9EA34
#define pinstAltAdvManager_x                                       0xDECEF0
#define pinstBandageTarget_x                                       0xE9EC54
#define pinstCamActor_x                                            0xDEC4A4
#define pinstCDBStr_x                                              0xDEBC0C
#define pinstCDisplay_x                                            0xE9ECA4
#define pinstCEverQuest_x                                          0xF4A19C
#define pinstEverQuestInfo_x                                       0xEA5978
#define pinstCharData_x                                            0xE9E744
#define pinstCharSpawn_x                                           0xE9EC8C
#define pinstControlledMissile_x                                   0xE9ECA0
#define pinstControlledPlayer_x                                    0xE9EC8C
#define pinstCResolutionHandler_x                                  0x15DC370
#define pinstCSidlManager_x                                        0x15DB308
#define pinstCXWndManager_x                                        0x15DB304
#define instDynamicZone_x                                          0xEA47F8
#define pinstDZMember_x                                            0xEA4908
#define pinstDZTimerInfo_x                                         0xEA490C
#define pinstEqLogin_x                                             0xF4A220
#define instEQMisc_x                                               0xDEBB50
#define pinstEQSoundManager_x                                      0xDEDEC0
#define pinstEQSpellStrings_x                                      0xCAE448
#define instExpeditionLeader_x                                     0xEA4842
#define instExpeditionName_x                                       0xEA4882
#define pinstGroup_x                                               0xE9E4FE
#define pinstImeManager_x                                          0x15DB300
#define pinstLocalPlayer_x                                         0xE9E824
#define pinstMercenaryData_x                                       0xF46D0C
#define pinstMercenaryStats_x                                      0xF5FBCC
#define pinstModelPlayer_x                                         0xE9EC4C
#define pinstPCData_x                                              0xE9E744
#define pinstSkillMgr_x                                            0xF48E68
#define pinstSpawnManager_x                                        0xF47910
#define pinstSpellManager_x                                        0xF490A8
#define pinstSpellSets_x                                           0xF3D358
#define pinstStringTable_x                                         0xE9E74C
#define pinstSwitchManager_x                                       0xE9E258
#define pinstTarget_x                                              0xE9EC88
#define pinstTargetObject_x                                        0xE9EC94
#define pinstTargetSwitch_x                                        0xE9ECAC
#define pinstTaskMember_x                                          0xDEB9E0
#define pinstTrackTarget_x                                         0xE9EC90
#define pinstTradeTarget_x                                         0xE9EC48
#define instTributeActive_x                                        0xDEBB71
#define pinstViewActor_x                                           0xDEC4A0
#define pinstWorldData_x                                           0xE9E3A8
#define pinstZoneAddr_x                                            0xEA5EF8
#define pinstPlayerPath_x                                          0xF479A8
#define pinstTargetIndicator_x                                     0xF49310
#define EQObject_Top_x                                             0xE9E820
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDEBF44
#define pinstCAchievementsWnd_x                                    0xDEC45C
#define pinstCActionsWnd_x                                         0xDEBF80
#define pinstCAdvancedDisplayOptionsWindow_x                       0xDEC51C
#define pinstCAdvancedLootWnd_x                                    0xDEC4CC
#define pinstCAdventureLeaderboardWnd_x                            0xF56920
#define pinstCAdventureRequestWnd_x                                0xF569D0
#define pinstCAdventureStatsWnd_x                                  0xF56A80
#define pinstCAggroMeterWnd_x                                      0xDEC500
#define pinstCAlarmWnd_x                                           0xDEC488
#define pinstCAlertHistoryWnd_x                                    0xDEBEF4
#define pinstCAlertStackWnd_x                                      0xDEC4E8
#define pinstCAlertWnd_x                                           0xDEC4FC
#define pinstCAltStorageWnd_x                                      0xF56DE0
#define pinstCAudioTriggersWindow_x                                0xCA0778
#define pinstCAuraWnd_x                                            0xDEC4D0
#define pinstCAvaZoneWnd_x                                         0xDEBEFC
#define pinstCBandolierWnd_x                                       0xDEC514
#define pinstCBankWnd_x                                            0xDEBCB8
#define pinstCBarterMerchantWnd_x                                  0xF58020
#define pinstCBarterSearchWnd_x                                    0xF580D0
#define pinstCBarterWnd_x                                          0xF58180
#define pinstCBazaarConfirmationWnd_x                              0xDEC498
#define pinstCBazaarSearchWnd_x                                    0xDEBF48
#define pinstCBazaarWnd_x                                          0xDEC464
#define pinstCBlockedBuffWnd_x                                     0xDEC4DC
#define pinstCBlockedPetBuffWnd_x                                  0xDEC504
#define pinstCBodyTintWnd_x                                        0xDEBFA4
#define pinstCBookWnd_x                                            0xDEBCAC
#define pinstCBreathWnd_x                                          0xDEBF58
#define pinstCBuffWindowNORMAL_x                                   0xDEC4C4
#define pinstCBuffWindowSHORT_x                                    0xDEC4C8
#define pinstCBugReportWnd_x                                       0xDEBCB4
#define pinstCButtonWnd_x                                          0x15DB570
#define pinstCCastingWnd_x                                         0xDEC540
#define pinstCCastSpellWnd_x                                       0xDEBF54
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDEC014
#define pinstCChatWindowManager_x                                  0xF58C40
#define pinstCClaimWnd_x                                           0xF58D98
#define pinstCColorPickerWnd_x                                     0xDEBF0C
#define pinstCCombatAbilityWnd_x                                   0xDEC478
#define pinstCCombatSkillsSelectWnd_x                              0xDEC42C
#define pinstCCompassWnd_x                                         0xDEBF84
#define pinstCConfirmationDialog_x                                 0xF5DC98
#define pinstCContainerMgr_x                                       0xDEBF9C
#define pinstCContextMenuManager_x                                 0x15DB2C0
#define pinstCCursorAttachment_x                                   0xDEC534
#define pinstCDynamicZoneWnd_x                                     0xF59360
#define pinstCEditLabelWnd_x                                       0xDEC4C0
#define pinstCEQMainWnd_x                                          0xF595A8
#define pinstCEventCalendarWnd_x                                   0xDEBF4C
#define pinstCExtendedTargetWnd_x                                  0xDEC4E0
#define pinstCPlayerCustomizationWnd_x                             0xDEC430
#define pinstCFactionWnd_x                                         0xDEC450
#define pinstCFellowshipWnd_x                                      0xF597A8
#define pinstCFileSelectionWnd_x                                   0xDEBF08
#define pinstCFindItemWnd_x                                        0xDEC444
#define pinstCFindLocationWnd_x                                    0xF59900
#define pinstCFriendsWnd_x                                         0xDEC440
#define pinstCGemsGameWnd_x                                        0xDEC44C
#define pinstCGiveWnd_x                                            0xDEC48C
#define pinstCGroupSearchFiltersWnd_x                              0xDEC518
#define pinstCGroupSearchWnd_x                                     0xF59CF8
#define pinstCGroupWnd_x                                           0xF59DA8
#define pinstCGuildBankWnd_x                                       0xF59E58
#define pinstCGuildCreationWnd_x                                   0xF59F08
#define pinstCGuildMgmtWnd_x                                       0xF59FB8
#define pinstCharacterCreation_x                                   0xDEC438
#define pinstCHelpWnd_x                                            0xDEC484
#define pinstCHeritageSelectionWnd_x                               0xDEC43C
#define pinstCHotButtonWnd_x                                       0xF5C110
#define pinstCHotButtonWnd1_x                                      0xF5C110
#define pinstCHotButtonWnd2_x                                      0xF5C114
#define pinstCHotButtonWnd3_x                                      0xF5C118
#define pinstCHotButtonWnd4_x                                      0xF5C11C
#define pinstCIconSelectionWnd_x                                   0xDEC528
#define pinstCInspectWnd_x                                         0xDEC508
#define pinstCInventoryWnd_x                                       0xDEC4D4
#define pinstCInvSlotMgr_x                                         0xDEBF38
#define pinstCItemDisplayManager_x                                 0xF5C6A0
#define pinstCItemExpTransferWnd_x                                 0xF5C7D0
#define pinstCItemOverflowWnd_x                                    0xDEBF50
#define pinstCJournalCatWnd_x                                      0xDEBF20
#define pinstCJournalNPCWnd_x                                      0xDEBEE0
#define pinstCJournalTextWnd_x                                     0xDEBEE0
#define pinstCKeyRingWnd_x                                         0xDEC53C
#define pinstCLargeDialogWnd_x                                     0xF5E918
#define pinstCLayoutCopyWnd_x                                      0xF5CB20
#define pinstCLFGuildWnd_x                                         0xF5CBD0
#define pinstCLoadskinWnd_x                                        0xDEC468
#define pinstCLootFiltersCopyWnd_x                                 0xCBCEE8
#define pinstCLootFiltersWnd_x                                     0xDEC4EC
#define pinstCLootSettingsWnd_x                                    0xDEC510
#define pinstCLootWnd_x                                            0xDEBF24
#define pinstCMailAddressBookWnd_x                                 0xDEBF3C
#define pinstCMailCompositionWnd_x                                 0xDEBF10
#define pinstCMailIgnoreListWnd_x                                  0xDEBF40
#define pinstCMailWnd_x                                            0xDEBF00
#define pinstCManageLootWnd_x                                      0xDED3A0
#define pinstCMapToolbarWnd_x                                      0xDEC490
#define pinstCMapViewWnd_x                                         0xDEC458
#define pinstCMarketplaceWnd_x                                     0xDEC4F0
#define pinstCMerchantWnd_x                                        0xDEBF34
#define pinstCMIZoneSelectWnd_x                                    0xF5D408
#define pinstCMusicPlayerWnd_x                                     0xDEBED4
#define pinstCNameChangeMercWnd_x                                  0xDEC494
#define pinstCNameChangePetWnd_x                                   0xDEC460
#define pinstCNameChangeWnd_x                                      0xDEC4BC
#define pinstCNoteWnd_x                                            0xDEC470
#define pinstCObjectPreviewWnd_x                                   0xDEC50C
#define pinstCOptionsWnd_x                                         0xDEC47C
#define pinstCPetInfoWnd_x                                         0xDEBEF8
#define pinstCPetitionQWnd_x                                       0xDEC428
#define pinstCPlayerNotesWnd_x                                     0xDEC00C
#define pinstCPlayerWnd_x                                          0xDEBEF0
#define pinstCPopupWndManager_x                                    0xF5DC98
#define pinstCProgressionSelectionWnd_x                            0xF5DD48
#define pinstCPurchaseGroupWnd_x                                   0xDEBCC8
#define pinstCPurchaseWnd_x                                        0xDEC544
#define pinstCPvPLeaderboardWnd_x                                  0xF5DDF8
#define pinstCPvPStatsWnd_x                                        0xF5DEA8
#define pinstCQuantityWnd_x                                        0xDEBEDC
#define pinstCRaceChangeWnd_x                                      0xDEC4D8
#define pinstCRaidOptionsWnd_x                                     0xDEC520
#define pinstCRaidWnd_x                                            0xDEBF2C
#define pinstCRealEstateItemsWnd_x                                 0xDEC454
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDEBF8C
#define pinstCRealEstateManageWnd_x                                0xDEBED0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDEBEE8
#define pinstCRealEstatePlotSearchWnd_x                            0xDEBF04
#define pinstCRealEstatePurchaseWnd_x                              0xDEBF1C
#define pinstCRespawnWnd_x                                         0xDEC4F8
#define pinstCRewardSelectionWnd_x                                 0xF5E5F0
#define pinstCSelectorWnd_x                                        0xDEC424
#define pinstCSendMoneyWnd_x                                       0xDEC49C
#define pinstCServerListWnd_x                                      0xDEBF28
#define pinstCSkillsSelectWnd_x                                    0xDEC420
#define pinstCSkillsWnd_x                                          0xDEBF88
#define pinstCSocialEditWnd_x                                      0xDEC538
#define pinstCSocialWnd_x                                          0xDEC480
#define pinstCSpellBookWnd_x                                       0xDEC474
#define pinstCStoryWnd_x                                           0xDEBF5C
#define pinstCTargetOfTargetWnd_x                                  0xF5FC50
#define pinstCTargetWnd_x                                          0xDEC4F4
#define pinstCTaskOverlayWnd_x                                     0xDEBCC0
#define pinstCTaskSelectWnd_x                                      0xF5FDA8
#define pinstCTaskManager_x                                        0xCBD828
#define pinstCTaskTemplateSelectWnd_x                              0xF5FE58
#define pinstCTaskWnd_x                                            0xF5FF08
#define pinstCTextEntryWnd_x                                       0xDEBCA8
#define pinstCTimeLeftWnd_x                                        0xDEC41C
#define pinstCTipWndCONTEXT_x                                      0xF6010C
#define pinstCTipWndOFDAY_x                                        0xF60108
#define pinstCTitleWnd_x                                           0xF601B8
#define pinstCTrackingWnd_x                                        0xDEC4E4
#define pinstCTradeskillWnd_x                                      0xF60320
#define pinstCTradeWnd_x                                           0xDEC010
#define pinstCTrainWnd_x                                           0xDEBF14
#define pinstCTributeBenefitWnd_x                                  0xF60520
#define pinstCTributeMasterWnd_x                                   0xF605D0
#define pinstCTributeTrophyWnd_x                                   0xF60680
#define pinstCVideoModesWnd_x                                      0xDEBCBC
#define pinstCVoiceMacroWnd_x                                      0xF498C8
#define pinstCVoteResultsWnd_x                                     0xDEC448
#define pinstCVoteWnd_x                                            0xDEC434
#define pinstCWebManager_x                                         0xF49F44
#define pinstCZoneGuideWnd_x                                       0xDEBCC4
#define pinstCZonePathWnd_x                                        0xDEBED8

#define pinstEQSuiteTextureLoader_x                                0xC8AB30
#define pinstItemIconCache_x                                       0xF59560
#define pinstLootFiltersManager_x                                  0xCBCF98
#define pinstRewardSelectionWnd_x                                  0xF5E5F0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C4B70
#define __CastRay2_x                                               0x5C4BC0
#define __ConvertItemTags_x                                        0x5E0890
#define __CleanItemTags_x                                          0x47D1C0
#define __DoesFileExist_x                                          0x8FA7A0
#define __EQGetTime_x                                              0x8F7350
#define __ExecuteCmd_x                                             0x5BD4D0
#define __FixHeading_x                                             0x98C760
#define __FlushDxKeyboard_x                                        0x6B07B0
#define __GameLoop_x                                               0x6B3AE0
#define __get_bearing_x                                            0x5C46D0
#define __get_melee_range_x                                        0x5C4DB0
#define __GetAnimationCache_x                                      0x719010
#define __GetGaugeValueFromEQ_x                                    0x80A9E0
#define __GetLabelFromEQ_x                                         0x80C4C0
#define __GetXTargetType_x                                         0x98E1B0
#define __HandleMouseWheel_x                                       0x6B49C0
#define __HeadingDiff_x                                            0x98C7D0
#define __HelpPath_x                                               0xF44E04
#define __LoadFrontEnd_x                                           0x6B0DF0
#define __NewUIINI_x                                               0x80A6B0
#define __ProcessGameEvents_x                                      0x625600
#define __ProcessMouseEvent_x                                      0x624D90
#define __SaveColors_x                                             0x55DCE0
#define __STMLToText_x                                             0x92FA40
#define __ToggleKeyRingItem_x                                      0x51C340
#define CMemoryMappedFile__SetFile_x                               0xA7B8F0
#define CrashDetected_x                                            0x6B28A0
#define DrawNetStatus_x                                            0x651690
#define Expansion_HoT_x                                            0xEA6D48
#define Teleport_Table_Size_x                                      0xE9E7E0
#define Teleport_Table_x                                           0xE9ECB0
#define Util__FastTime_x                                           0x8F6F10
#define __CopyLayout_x                                             0x63F820
#define __WndProc_x                                                0x6B2DA0
#define __ProcessKeyboardEvent_x                                   0x6B2340

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490490
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499480
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499250
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A30
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492E80

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x565EF0
#define AltAdvManager__IsAbilityReady_x                            0x564C90
#define AltAdvManager__GetAAById_x                                 0x565020
#define AltAdvManager__CanTrainAbility_x                           0x565090
#define AltAdvManager__CanSeeAbility_x                             0x5653F0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB070
#define CharacterZoneClient__HasSkill_x                            0x4D5EF0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7610
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2860
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBD00
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9F80
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA060
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA140
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4950
#define CharacterZoneClient__BardCastBard_x                        0x4C7380
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF710
#define CharacterZoneClient__GetEffect_x                           0x4BBC40
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C59C0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5A90
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5AE0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5C30
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5E10
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3BB0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8570
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7FF0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DA5C0
#define CBankWnd__WndNotification_x                                0x6DA390

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E7DF0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92D210
#define CButtonWnd__CButtonWnd_x                                   0x92BDE0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x7080B0
#define CChatManager__InitContextMenu_x                            0x7011E0
#define CChatManager__FreeChatWindow_x                             0x706BF0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9990
#define CChatManager__SetLockedActiveChatWindow_x                  0x707D30
#define CChatManager__CreateChatWindow_x                           0x707230

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9AA0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x940300
#define CContextMenu__dCContextMenu_x                              0x940540
#define CContextMenu__AddMenuItem_x                                0x940550
#define CContextMenu__RemoveMenuItem_x                             0x940860
#define CContextMenu__RemoveAllMenuItems_x                         0x940880
#define CContextMenu__CheckMenuItem_x                              0x940900
#define CContextMenu__SetMenuItem_x                                0x940780
#define CContextMenu__AddSeparator_x                               0x9406E0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x940E90
#define CContextMenuManager__RemoveMenu_x                          0x940F00
#define CContextMenuManager__PopupMenu_x                           0x940FC0
#define CContextMenuManager__Flush_x                               0x940E30
#define CContextMenuManager__GetMenu_x                             0x49B6F0
#define CContextMenuManager__CreateDefaultMenu_x                   0x713950

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D20C0
#define CChatService__GetFriendName_x                              0x8D20D0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7089E0
#define CChatWindow__Clear_x                                       0x709CA0
#define CChatWindow__WndNotification_x                             0x70A430
#define CChatWindow__AddHistory_x                                  0x709560

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93D750
#define CComboWnd__Draw_x                                          0x93CC40
#define CComboWnd__GetCurChoice_x                                  0x93D590
#define CComboWnd__GetListRect_x                                   0x93D0F0
#define CComboWnd__GetTextRect_x                                   0x93D7C0
#define CComboWnd__InsertChoice_x                                  0x93D280
#define CComboWnd__SetColors_x                                     0x93D250
#define CComboWnd__SetChoice_x                                     0x93D560
#define CComboWnd__GetItemCount_x                                  0x93D5A0
#define CComboWnd__GetCurChoiceText_x                              0x93D5E0
#define CComboWnd__GetChoiceText_x                                 0x93D5B0
#define CComboWnd__InsertChoiceAtIndex_x                           0x93D320

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x711370
#define CContainerWnd__vftable_x                                   0xAFF774
#define CContainerWnd__SetContainer_x                              0x7128D0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x558640
#define CDisplay__PreZoneMainUI_x                                  0x558650
#define CDisplay__CleanGameUI_x                                    0x55DAA0
#define CDisplay__GetClickedActor_x                                0x550AA0
#define CDisplay__GetUserDefinedColor_x                            0x549110
#define CDisplay__GetWorldFilePath_x                               0x552510
#define CDisplay__is3dON_x                                         0x54D700
#define CDisplay__ReloadUI_x                                       0x557B50
#define CDisplay__WriteTextHD2_x                                   0x54D4F0
#define CDisplay__TrueDistance_x                                   0x5541D0
#define CDisplay__SetViewActor_x                                   0x5503C0
#define CDisplay__GetFloorHeight_x                                 0x54D7C0
#define CDisplay__SetRenderWindow_x                                0x54C140
#define CDisplay__ToggleScreenshotMode_x                           0x54FE90

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x960200

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x943810
#define CEditWnd__EnsureCaretVisible_x                             0x9459E0
#define CEditWnd__GetCaretPt_x                                     0x944990
#define CEditWnd__GetCharIndexPt_x                                 0x944740
#define CEditWnd__GetDisplayString_x                               0x9445E0
#define CEditWnd__GetHorzOffset_x                                  0x942EB0
#define CEditWnd__GetLineForPrintableChar_x                        0x9458E0
#define CEditWnd__GetSelStartPt_x                                  0x9449F0
#define CEditWnd__GetSTMLSafeText_x                                0x944400
#define CEditWnd__PointFromPrintableChar_x                         0x945510
#define CEditWnd__SelectableCharFromPoint_x                        0x945680
#define CEditWnd__SetEditable_x                                    0x944AC0
#define CEditWnd__SetWindowTextA_x                                 0x944180
#define CEditWnd__ReplaceSelection_x                               0x945180
#define CEditWnd__ReplaceSelection1_x                              0x945100

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x612C00
#define CEverQuest__ClickedPlayer_x                                0x604DA0
#define CEverQuest__CreateTargetIndicator_x                        0x622770
#define CEverQuest__DeleteTargetIndicator_x                        0x622800
#define CEverQuest__DoTellWindow_x                                 0x4E9B80
#define CEverQuest__OutputTextToLog_x                              0x4E9E50
#define CEverQuest__DropHeldItemOnGround_x                         0x5F9F00
#define CEverQuest__dsp_chat_x                                     0x4EA1E0
#define CEverQuest__trimName_x                                     0x61E920
#define CEverQuest__Emote_x                                        0x613460
#define CEverQuest__EnterZone_x                                    0x60D560
#define CEverQuest__GetBodyTypeDesc_x                              0x617EB0
#define CEverQuest__GetClassDesc_x                                 0x6184F0
#define CEverQuest__GetClassThreeLetterCode_x                      0x618AF0
#define CEverQuest__GetDeityDesc_x                                 0x620FC0
#define CEverQuest__GetLangDesc_x                                  0x618CB0
#define CEverQuest__GetRaceDesc_x                                  0x6184D0
#define CEverQuest__InterpretCmd_x                                 0x621590
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FE090
#define CEverQuest__LMouseUp_x                                     0x5FC420
#define CEverQuest__RightClickedOnPlayer_x                         0x5FE970
#define CEverQuest__RMouseUp_x                                     0x5FD3A0
#define CEverQuest__SetGameState_x                                 0x5F9C90
#define CEverQuest__UPCNotificationFlush_x                         0x61E820
#define CEverQuest__IssuePetCommand_x                              0x61A0C0
#define CEverQuest__ReportSuccessfulHit_x                          0x6147B0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x723090
#define CGaugeWnd__CalcLinesFillRect_x                             0x7230F0
#define CGaugeWnd__Draw_x                                          0x722710

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFE20
#define CGuild__GetGuildName_x                                     0x4AE8D0
#define CGuild__GetGuildIndex_x                                    0x4AEED0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73CCF0

//CHotButton
#define CHotButton__SetCheck_x                                     0x633D90
#define CHotButton__SetButtonSize_x                                0x634150

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x749F90
#define CInvSlotMgr__MoveItem_x                                    0x748C50
#define CInvSlotMgr__SelectSlot_x                                  0x74A060

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x747440
#define CInvSlot__SliderComplete_x                                 0x745180
#define CInvSlot__GetItemBase_x                                    0x744AF0
#define CInvSlot__UpdateItem_x                                     0x744C60

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74BAF0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74AC80
#define CInvSlotWnd__HandleLButtonUp_x                             0x74B670

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x805D80
#define CItemDisplayWnd__UpdateStrings_x                           0x75A290
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x753F50
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x754460
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x75A890
#define CItemDisplayWnd__AboutToShow_x                             0x759ED0
#define CItemDisplayWnd__WndNotification_x                         0x75BB10
#define CItemDisplayWnd__RequestConvertItem_x                      0x75B440
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x758F30
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x759CF0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8367D0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x760010

// CLabel 
#define CLabel__Draw_x                                             0x765A90

// CListWnd
#define CListWnd__CListWnd_x                                       0x915F20
#define CListWnd__dCListWnd_x                                      0x916240
#define CListWnd__AddColumn_x                                      0x91A6C0
#define CListWnd__AddColumn1_x                                     0x91A710
#define CListWnd__AddLine_x                                        0x91AAA0
#define CListWnd__AddString_x                                      0x91A8A0
#define CListWnd__CalculateFirstVisibleLine_x                      0x91A480
#define CListWnd__CalculateVSBRange_x                              0x91A260
#define CListWnd__ClearSel_x                                       0x91B280
#define CListWnd__ClearAllSel_x                                    0x91B2E0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91BD00
#define CListWnd__Compare_x                                        0x919B90
#define CListWnd__Draw_x                                           0x916370
#define CListWnd__DrawColumnSeparators_x                           0x918B60
#define CListWnd__DrawHeader_x                                     0x918FD0
#define CListWnd__DrawItem_x                                       0x9194D0
#define CListWnd__DrawLine_x                                       0x918CD0
#define CListWnd__DrawSeparator_x                                  0x918C00
#define CListWnd__EnableLine_x                                     0x918430
#define CListWnd__EnsureVisible_x                                  0x91BC20
#define CListWnd__ExtendSel_x                                      0x91B1B0
#define CListWnd__GetColumnTooltip_x                               0x917F70
#define CListWnd__GetColumnMinWidth_x                              0x917FE0
#define CListWnd__GetColumnWidth_x                                 0x917EE0
#define CListWnd__GetCurSel_x                                      0x917870
#define CListWnd__GetItemAtPoint_x                                 0x9186B0
#define CListWnd__GetItemAtPoint1_x                                0x918720
#define CListWnd__GetItemData_x                                    0x9178F0
#define CListWnd__GetItemHeight_x                                  0x917CB0
#define CListWnd__GetItemIcon_x                                    0x917A80
#define CListWnd__GetItemRect_x                                    0x918520
#define CListWnd__GetItemText_x                                    0x917930
#define CListWnd__GetSelList_x                                     0x91B330
#define CListWnd__GetSeparatorRect_x                               0x918960
#define CListWnd__InsertLine_x                                     0x91AE90
#define CListWnd__RemoveLine_x                                     0x91AFE0
#define CListWnd__SetColors_x                                      0x91A230
#define CListWnd__SetColumnJustification_x                         0x919F60
#define CListWnd__SetColumnLabel_x                                 0x91A840
#define CListWnd__SetColumnWidth_x                                 0x919E80
#define CListWnd__SetCurSel_x                                      0x91B0F0
#define CListWnd__SetItemColor_x                                   0x91B8D0
#define CListWnd__SetItemData_x                                    0x91B890
#define CListWnd__SetItemText_x                                    0x91B4A0
#define CListWnd__ShiftColumnSeparator_x                           0x91A020
#define CListWnd__Sort_x                                           0x919D10
#define CListWnd__ToggleSel_x                                      0x91B120
#define CListWnd__SetColumnsSizable_x                              0x91A0D0
#define CListWnd__SetItemWnd_x                                     0x91B750
#define CListWnd__GetItemWnd_x                                     0x917AD0
#define CListWnd__SetItemIcon_x                                    0x91B520
#define CListWnd__CalculateCustomWindowPositions_x                 0x91A580
#define CListWnd__SetVScrollPos_x                                  0x919E60

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77B250
#define CMapViewWnd__GetWorldCoordinates_x                         0x779960
#define CMapViewWnd__HandleLButtonDown_x                           0x7769A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79B460
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79BD40
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79C270
#define CMerchantWnd__SelectRecoverySlot_x                         0x79F230
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x799FC0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A4E00
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79B070

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89FD30
#define CPacketScrambler__hton_x                                   0x89FD20

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x935020
#define CSidlManager__FindScreenPieceTemplate_x                    0x935430
#define CSidlManager__FindScreenPieceTemplate1_x                   0x935220
#define CSidlManager__CreateLabel_x                                0x7FCFE0
#define CSidlManager__CreateXWndFromTemplate_x                     0x938390
#define CSidlManager__CreateXWndFromTemplate1_x                    0x938570
#define CSidlManager__CreateXWnd_x                                 0x7FCF10
#define CSidlManager__CreateHotButtonWnd_x                         0x7FD4D0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x931AE0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9319E0
#define CSidlScreenWnd__ConvertToRes_x                             0x95ACF0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9314D0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9311C0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x931290
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x931360
#define CSidlScreenWnd__DrawSidlPiece_x                            0x931F80
#define CSidlScreenWnd__EnableIniStorage_x                         0x932450
#define CSidlScreenWnd__GetSidlPiece_x                             0x932170
#define CSidlScreenWnd__Init1_x                                    0x930DE0
#define CSidlScreenWnd__LoadIniInfo_x                              0x9324A0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x933000
#define CSidlScreenWnd__LoadSidlScreen_x                           0x9301F0
#define CSidlScreenWnd__StoreIniInfo_x                             0x932B70
#define CSidlScreenWnd__StoreIniVis_x                              0x932EE0
#define CSidlScreenWnd__WndNotification_x                          0x931E90
#define CSidlScreenWnd__GetChildItem_x                             0x9323D0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x921B50
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DB190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x699800
#define CSkillMgr__GetSkillCap_x                                   0x6999E0
#define CSkillMgr__GetNameToken_x                                  0x698F80
#define CSkillMgr__IsActivatedSkill_x                              0x6990C0
#define CSkillMgr__IsCombatSkill_x                                 0x699000

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x941C80
#define CSliderWnd__SetValue_x                                     0x941AF0
#define CSliderWnd__SetNumTicks_x                                  0x941B50

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x803110

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x94A5E0
#define CStmlWnd__ParseSTML_x                                      0x94B8F0
#define CStmlWnd__CalculateHSBRange_x                              0x94B6C0
#define CStmlWnd__CalculateVSBRange_x                              0x94B630
#define CStmlWnd__CanBreakAtCharacter_x                            0x94FA00
#define CStmlWnd__FastForwardToEndOfTag_x                          0x950690
#define CStmlWnd__ForceParseNow_x                                  0x94AB80
#define CStmlWnd__GetNextTagPiece_x                                0x94F960
#define CStmlWnd__GetSTMLText_x                                    0x50D4C0
#define CStmlWnd__GetVisibleText_x                                 0x94ABA0
#define CStmlWnd__InitializeWindowVariables_x                      0x9504E0
#define CStmlWnd__MakeStmlColorTag_x                               0x949C50
#define CStmlWnd__MakeWndNotificationTag_x                         0x949CC0
#define CStmlWnd__SetSTMLText_x                                    0x948D00
#define CStmlWnd__StripFirstSTMLLines_x                            0x951790
#define CStmlWnd__UpdateHistoryString_x                            0x9508A0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x947E50
#define CTabWnd__DrawCurrentPage_x                                 0x948580
#define CTabWnd__DrawTab_x                                         0x9482A0
#define CTabWnd__GetCurrentPage_x                                  0x947650
#define CTabWnd__GetPageInnerRect_x                                0x947890
#define CTabWnd__GetTabInnerRect_x                                 0x9477D0
#define CTabWnd__GetTabRect_x                                      0x947680
#define CTabWnd__InsertPage_x                                      0x947AA0
#define CTabWnd__RemovePage_x                                      0x947C10
#define CTabWnd__SetPage_x                                         0x947910
#define CTabWnd__SetPageRect_x                                     0x947D90
#define CTabWnd__UpdatePage_x                                      0x948160
#define CTabWnd__GetPageFromTabIndex_x                             0x9481E0
#define CTabWnd__GetCurrentTabIndex_x                              0x947640

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x760420
#define CPageWnd__SetTabText_x                                     0x947190
#define CPageWnd__FlashTab_x                                       0x9471F0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9110

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91E9F0
#define CTextureFont__GetTextExtent_x                              0x91EBB0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AD970
#define CHtmlComponentWnd__ValidateUri_x                           0x73E6E0
#define CHtmlWnd__SetClientCallbacks_x                             0x6391E0
#define CHtmlWnd__AddObserver_x                                    0x639200
#define CHtmlWnd__RemoveObserver_x                                 0x639260
#define Window__getProgress_x                                      0x855070
#define Window__getStatus_x                                        0x855090
#define Window__getURI_x                                           0x8550A0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x957B00

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90B9E0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9850
#define CXStr__CXStr1_x                                            0x5C27A0
#define CXStr__CXStr3_x                                            0x8F32C0
#define CXStr__dCXStr_x                                            0x478430
#define CXStr__operator_equal_x                                    0x8F34F0
#define CXStr__operator_equal1_x                                   0x8F3530
#define CXStr__operator_plus_equal1_x                              0x8F3FC0
#define CXStr__SetString_x                                         0x8F5EB0
#define CXStr__operator_char_p_x                                   0x8F3A30
#define CXStr__GetChar_x                                           0x8F5800
#define CXStr__Delete_x                                            0x8F50B0
#define CXStr__GetUnicode_x                                        0x8F5870
#define CXStr__GetLength_x                                         0x47D570
#define CXStr__Mid_x                                               0x47D580
#define CXStr__Insert_x                                            0x8F58D0
#define CXStr__FindNext_x                                          0x8F5520

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93FF10
#define CXWnd__BringToTop_x                                        0x9252C0
#define CXWnd__Center_x                                            0x924E40
#define CXWnd__ClrFocus_x                                          0x924C60
#define CXWnd__Destroy_x                                           0x924D00
#define CXWnd__DoAllDrawing_x                                      0x9212E0
#define CXWnd__DrawChildren_x                                      0x9212B0
#define CXWnd__DrawColoredRect_x                                   0x921740
#define CXWnd__DrawTooltip_x                                       0x91FE10
#define CXWnd__DrawTooltipAtPoint_x                                0x91FED0
#define CXWnd__GetBorderFrame_x                                    0x9215A0
#define CXWnd__GetChildWndAt_x                                     0x925360
#define CXWnd__GetClientClipRect_x                                 0x923570
#define CXWnd__GetScreenClipRect_x                                 0x923640
#define CXWnd__GetScreenRect_x                                     0x923800
#define CXWnd__GetRelativeRect_x                                   0x9238C0
#define CXWnd__GetTooltipRect_x                                    0x921790
#define CXWnd__GetWindowTextA_x                                    0x49CDF0
#define CXWnd__IsActive_x                                          0x921ED0
#define CXWnd__IsDescendantOf_x                                    0x9241F0
#define CXWnd__IsReallyVisible_x                                   0x924220
#define CXWnd__IsType_x                                            0x9259C0
#define CXWnd__Move_x                                              0x924280
#define CXWnd__Move1_x                                             0x924330
#define CXWnd__ProcessTransition_x                                 0x924DF0
#define CXWnd__Refade_x                                            0x924600
#define CXWnd__Resize_x                                            0x924880
#define CXWnd__Right_x                                             0x925080
#define CXWnd__SetFocus_x                                          0x924C20
#define CXWnd__SetFont_x                                           0x924C90
#define CXWnd__SetKeyTooltip_x                                     0x9257F0
#define CXWnd__SetMouseOver_x                                      0x9226F0
#define CXWnd__StartFade_x                                         0x9240D0
#define CXWnd__GetChildItem_x                                      0x9254D0
#define CXWnd__SetParent_x                                         0x923FA0
#define CXWnd__Minimize_x                                          0x9248F0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95BD70

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9281C0
#define CXWndManager__DrawWindows_x                                0x9281E0
#define CXWndManager__GetKeyboardFlags_x                           0x92A9A0
#define CXWndManager__HandleKeyboardMsg_x                          0x92A550
#define CXWndManager__RemoveWnd_x                                  0x92ABD0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92B150

// CDBStr
#define CDBStr__GetString_x                                        0x5480B0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFE70
#define EQ_Character__Cur_HP_x                                     0x4D2F30
#define EQ_Character__Cur_Mana_x                                   0x4DA640
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2ED0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B37F0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3940
#define EQ_Character__GetHPRegen_x                                 0x4E0510
#define EQ_Character__GetEnduranceRegen_x                          0x4E0B10
#define EQ_Character__GetManaRegen_x                               0x4E0F50
#define EQ_Character__Max_Endurance_x                              0x65FA10
#define EQ_Character__Max_HP_x                                     0x4D2D60
#define EQ_Character__Max_Mana_x                                   0x65F810
#define EQ_Character__doCombatAbility_x                            0x661E00
#define EQ_Character__UseSkill_x                                   0x4E2D60
#define EQ_Character__GetConLevel_x                                0x6585E0
#define EQ_Character__IsExpansionFlag_x                            0x5BBC60
#define EQ_Character__TotalEffect_x                                0x4C6C70
#define EQ_Character__GetPCSpellAffect_x                           0x4C3C20
#define EQ_Character__SpellDuration_x                              0x4C3750
#define EQ_Character__MySpellDuration_x                            0x4B2120
#define EQ_Character__GetAdjustedSkill_x                           0x4D5CB0
#define EQ_Character__GetBaseSkill_x                               0x4D6C50
#define EQ_Character__CanUseItem_x                                 0x4DA950

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BF100

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x675D10

//PcClient
#define PcClient__vftable_x                                        0xAF31D4
#define PcClient__PcClient_x                                       0x655D50

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA880
#define CCharacterListWnd__EnterWorld_x                            0x4BA250
#define CCharacterListWnd__Quit_x                                  0x4B9FA0
#define CCharacterListWnd__UpdateList_x                            0x4BA440

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x63A3B0
#define EQ_Item__CreateItemTagString_x                             0x8991D0
#define EQ_Item__IsStackable_x                                     0x89DEF0
#define EQ_Item__GetImageNum_x                                     0x89AD60
#define EQ_Item__CreateItemClient_x                                0x6395E0
#define EQ_Item__GetItemValue_x                                    0x89C050
#define EQ_Item__ValueSellMerchant_x                               0x89F910
#define EQ_Item__IsKeyRingItem_x                                   0x89D780
#define EQ_Item__CanGoInBag_x                                      0x63A4D0
#define EQ_Item__IsEmpty_x                                         0x89D2F0
#define EQ_Item__GetMaxItemCount_x                                 0x89C470
#define EQ_Item__GetHeldItem_x                                     0x89AC30
#define EQ_Item__GetAugmentFitBySlot_x                             0x898A20

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x566C00
#define EQ_LoadingS__Array_x                                       0xC14130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x660310
#define EQ_PC__GetAlternateAbilityId_x                             0x8A8CE0
#define EQ_PC__GetCombatAbility_x                                  0x8A9350
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A93C0
#define EQ_PC__GetItemRecastTimer_x                                0x662380
#define EQ_PC__HasLoreItem_x                                       0x658E50
#define EQ_PC__AlertInventoryChanged_x                             0x657F20
#define EQ_PC__GetPcZoneClient_x                                   0x684D70
#define EQ_PC__RemoveMyAffect_x                                    0x6655B0
#define EQ_PC__GetKeyRingItems_x                                   0x8A9C90
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A9A10
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A9F90

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C20D0
#define EQItemList__add_object_x                                   0x5EF760
#define EQItemList__add_item_x                                     0x5C2630
#define EQItemList__delete_item_x                                  0x5C2680
#define EQItemList__FreeItemList_x                                 0x5C2580

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x544C60

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x677610
#define EQPlayer__dEQPlayer_x                                      0x66A980
#define EQPlayer__DoAttack_x                                       0x67F500
#define EQPlayer__EQPlayer_x                                       0x66B040
#define EQPlayer__SetNameSpriteState_x                             0x66F320
#define EQPlayer__SetNameSpriteTint_x                              0x670200
#define PlayerBase__HasProperty_j_x                                0x98AB20
#define EQPlayer__IsTargetable_x                                   0x98AFC0
#define EQPlayer__CanSee_x                                         0x98AE20
#define EQPlayer__CanSee1_x                                        0x98AEF0
#define PlayerBase__GetVisibilityLineSegment_x                     0x98ABE0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x682800
#define PlayerZoneClient__GetLevel_x                               0x684DB0
#define PlayerZoneClient__IsValidTeleport_x                        0x5F08D0
#define PlayerZoneClient__LegalPlayerRace_x                        0x55F8D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x67A3E0
#define EQPlayerManager__GetSpawnByName_x                          0x67A490
#define EQPlayerManager__GetPlayerFromPartialName_x                0x67A520

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63DA80
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63DB00
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63DB40
#define KeypressHandler__ClearCommandStateArray_x                  0x63EF30
#define KeypressHandler__HandleKeyDown_x                           0x63EF50
#define KeypressHandler__HandleKeyUp_x                             0x63EFF0
#define KeypressHandler__SaveKeymapping_x                          0x63F440

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7770C0
#define MapViewMap__SaveEx_x                                       0x77A480
#define MapViewMap__SetZoom_x                                      0x77EB40

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BD170

// StringTable 
#define StringTable__getString_x                                   0x8B8100

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x665220
#define PcZoneClient__RemovePetEffect_x                            0x665850
#define PcZoneClient__HasAlternateAbility_x                        0x65F640
#define PcZoneClient__GetCurrentMod_x                              0x4E5E80
#define PcZoneClient__GetModCap_x                                  0x4E5D80
#define PcZoneClient__CanEquipItem_x                               0x65FCF0
#define PcZoneClient__GetItemByID_x                                0x6627F0
#define PcZoneClient__GetItemByItemClass_x                         0x662940
#define PcZoneClient__RemoveBuffEffect_x                           0x665870
#define PcZoneClient__BandolierSwap_x                              0x6608D0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x662320

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F5450

//IconCache
#define IconCache__GetIcon_x                                       0x718A10

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x710510
#define CContainerMgr__CloseContainer_x                            0x7107E0
#define CContainerMgr__OpenExperimentContainer_x                   0x711260

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CF6C0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x632570

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76D5A0
#define CLootWnd__RequestLootSlot_x                                0x76C870

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58EB30
#define EQ_Spell__SpellAffects_x                                   0x58EFA0
#define EQ_Spell__SpellAffectBase_x                                0x58ED60
#define EQ_Spell__IsStackable_x                                    0x4CA960
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA7E0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7AD0
#define EQ_Spell__IsSPAStacking_x                                  0x58FDF0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58F300
#define EQ_Spell__IsNoRemove_x                                     0x4CA940
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58FE00
#define __IsResEffectSpell_x                                       0x4C9CC0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD360

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C7720

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x816480
#define CTargetWnd__WndNotification_x                              0x815CC0
#define CTargetWnd__RefreshTargetBuffs_x                           0x815F90
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x814E20

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81AAF0
#define CTaskWnd__ConfirmAbandonTask_x                             0x81D730

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x542650
#define CTaskManager__HandleMessage_x                              0x540AC0
#define CTaskManager__GetTaskStatus_x                              0x542700
#define CTaskManager__GetElementDescription_x                      0x542780

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x589AC0
#define EqSoundManager__PlayScriptMp3_x                            0x589D80
#define EqSoundManager__SoundAssistPlay_x                          0x69D7D0
#define EqSoundManager__WaveInstancePlay_x                         0x69CD40

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5339D0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9466A0
#define CTextureAnimation__Draw_x                                  0x9468A0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x9425F0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56E6B0
#define CAltAbilityData__GetMercMaxRank_x                          0x56E640
#define CAltAbilityData__GetMaxRank_x                              0x563B10

//CTargetRing
#define CTargetRing__Cast_x                                        0x630690

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA7C0
#define CharacterBase__CreateItemGlobalIndex_x                     0x51A3E0
#define CharacterBase__CreateItemIndex_x                           0x638780
#define CharacterBase__GetItemPossession_x                         0x506020
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CFDB0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CFE10
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F73B0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F7BE0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F7C90

//messages
#define msg_spell_worn_off_x                                       0x5B3B10
#define msg_new_text_x                                             0x5A8490
#define __msgTokenTextParam_x                                      0x5B5DB0
#define msgTokenText_x                                             0x5B6000

//SpellManager
#define SpellManager__vftable_x                                    0xADB534
#define SpellManager__SpellManager_x                               0x6A0AF0
#define Spellmanager__LoadTextSpells_x                             0x6A13E0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6A0CC0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98EAA0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x51AAD0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5BA010
#define ItemGlobalIndex__IsEquippedLocation_x                      0x6514F0
#define ItemGlobalIndex__IsValidIndex_x                            0x51AB60

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C80E0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C8270

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x765DD0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x714C00
#define CCursorAttachment__AttachToCursor1_x                       0x714C40
#define CCursorAttachment__Deactivate_x                            0x715C30

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x9393C0
#define CSidlManagerBase__CreatePageWnd_x                          0x938BC0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x934E40
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x934DD0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9564A0
#define CEQSuiteTextureLoader__GetTexture_x                        0x956160

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x5176B0
#define CFindItemWnd__WndNotification_x                            0x5182F0
#define CFindItemWnd__Update_x                                     0x518E40
#define CFindItemWnd__PickupSelectedItem_x                         0x516EE0

//IString
#define IString__Append_x                                          0x5078B0

//Camera
#define CDisplay__cameraType_x                                     0xDEBCCC
#define EverQuest__Cameras_x                                       0xEA70A0

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x520490
#define LootFiltersManager__GetItemFilterData_x                    0x51FD90
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51FDC0
#define LootFiltersManager__SetItemLootFilter_x                    0x51FFE0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BD440

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x994690
#define CResolutionHandler__GetWindowedStyle_x                     0x698230

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70D140

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D3B60
#define CDistillerInfo__Instance_x                                 0x8D3B00

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72C080
#define CGroupWnd__UpdateDisplay_x                                 0x72B3D0

//ItemBase
#define ItemBase__IsLore_x                                         0x89D830
#define ItemBase__IsLoreEquipped_x                                 0x89D8B0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EF6C0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EF800
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EF860

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68D490
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x690E60

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50DE00

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4FA010
#define FactionManagerClient__HandleFactionMessage_x               0x4FA680
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FAC80
#define FactionManagerClient__GetMaxFaction_x                      0x4FAC9F
#define FactionManagerClient__GetMinFaction_x                      0x4FAC50

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x505FF0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91D9A0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C100

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x5062C0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56DB60

//CTargetManager
#define CTargetManager__Get_x                                      0x6A4320

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68D490

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8ED0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C2520

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF44734

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6C0CC0
#define CAAWnd__UpdateSelected_x                                   0x6BD530
#define CAAWnd__Update_x                                           0x6BFFE0

//CXRect
#define CXRect__operator_and_x                                     0x723150

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x4831F0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";

//__eqgraphics_fopen
//Jan 09 2020 EQGraphicsDX9.dll
//IDA Style Sig: E8 ? ? ? ? 83 C4 08 89 45 A0
//#define __eqgraphics_fopen_x                                       0x101473C8
static PBYTE efPattern = (PBYTE)"\xE8\x00\x00\x00\x00\x83\xC4\x08\x89\x45\xA0";
static char efMask[] = "x????xxxxxx";
