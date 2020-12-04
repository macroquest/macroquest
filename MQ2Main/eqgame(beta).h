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
#define __ExpectedVersionDate                                     "Nov 29 2020"
#define __ExpectedVersionTime                                     "04:19:16"
#define __ActualVersionDate_x                                      0xAF6550
#define __ActualVersionTime_x                                      0xAF6544
#define __ActualVersionBuild_x                                     0xAE4574

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x644190
#define __MemChecker1_x                                            0x8F7850
#define __MemChecker2_x                                            0x6B4970
#define __MemChecker3_x                                            0x6B48C0
#define __MemChecker4_x                                            0x84DBD0
#define __EncryptPad0_x                                            0xC2C9C8
#define __EncryptPad1_x                                            0xC8A210
#define __EncryptPad2_x                                            0xC3CD90
#define __EncryptPad3_x                                            0xC3C990
#define __EncryptPad4_x                                            0xC7A7A0
#define __EncryptPad5_x                                            0xF4D0E0
#define __AC1_x                                                    0x80C776
#define __AC2_x                                                    0x5FD96F
#define __AC3_x                                                    0x604FC0
#define __AC4_x                                                    0x608F70
#define __AC5_x                                                    0x60F26F
#define __AC6_x                                                    0x613726
#define __AC7_x                                                    0x5FD3E0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1912F0

// Direct Input
#define DI8__Main_x                                                0xF4D108
#define DI8__Keyboard_x                                            0xF4D10C
#define DI8__Mouse_x                                               0xF4D0EC
#define DI8__Mouse_Copy_x                                          0xEA59E4
#define DI8__Mouse_Check_x                                         0xF4AC34
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
#define __do_loot_x                                                0x5C94C0
#define __DrawHandler_x                                            0x15DC140
#define __GroupCount_x                                             0xE9E502
#define __Guilds_x                                                 0xEA4920
#define __gWorld_x                                                 0xE9EC98
#define __HWnd_x                                                   0xF4D0F0
#define __heqmain_x                                                0xF4D0C8
#define __InChatMode_x                                             0xEA59CC
#define __LastTell_x                                               0xEA794C
#define __LMouseHeldTime_x                                         0xEA5B08
#define __Mouse_x                                                  0xF4D0F4
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
#define __ServerHost_x                                             0xE9E923
#define __ServerName_x                                             0xEDC210
#define __ShiftKeyDown_x                                           0xEA6060
#define __ShowNames_x                                              0xEA6DA0
#define EverQuestInfo__bSocialChanged_x                            0xEDC298
#define __Socials_x                                                0xEDC310
#define __SubscriptionType_x                                       0xFA1410
#define __TargetAggroHolder_x                                      0xF5FB00
#define __ZoneType_x                                               0xEA5E60
#define __GroupAggro_x                                             0xF5FB40
#define __LoginName_x                                              0xF4A8C4
#define __Inviter_x                                                0xF446AC
#define __AttackOnAssist_x                                         0xEA6D5C
#define __UseTellWindows_x                                         0xEA7094
#define __gfMaxZoomCameraDistance_x                                0xAEE170
#define __gfMaxCameraDistance_x                                    0xB16DF8
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
#define pinstActiveMerchant_x                                      0xE9EC38
#define pinstAltAdvManager_x                                       0xDECEF0
#define pinstBandageTarget_x                                       0xE9EC54
#define pinstCamActor_x                                            0xDEC49C
#define pinstCDBStr_x                                              0xDEBC0C
#define pinstCDisplay_x                                            0xE9ECA4
#define pinstCEverQuest_x                                          0xF4A188
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
#define pinstEqLogin_x                                             0xF4A210
#define instEQMisc_x                                               0xDEBB50
#define pinstEQSoundManager_x                                      0xDEDEC0
#define pinstEQSpellStrings_x                                      0xCAE448
#define instExpeditionLeader_x                                     0xEA4842
#define instExpeditionName_x                                       0xEA4882
#define pinstGroup_x                                               0xE9E4FE
#define pinstImeManager_x                                          0x15DB300
#define pinstLocalPlayer_x                                         0xE9EC34
#define pinstMercenaryData_x                                       0xF46D08
#define pinstMercenaryStats_x                                      0xF5FBCC
#define pinstModelPlayer_x                                         0xE9EC4C
#define pinstPCData_x                                              0xE9E744
#define pinstSkillMgr_x                                            0xF48E68
#define pinstSpawnManager_x                                        0xF47910
#define pinstSpellManager_x                                        0xF490A8
#define pinstSpellSets_x                                           0xF3D358
#define pinstStringTable_x                                         0xE9E748
#define pinstSwitchManager_x                                       0xE9E258
#define pinstTarget_x                                              0xE9EC88
#define pinstTargetObject_x                                        0xE9EC94
#define pinstTargetSwitch_x                                        0xE9ECAC
#define pinstTaskMember_x                                          0xDEB9E0
#define pinstTrackTarget_x                                         0xE9EC90
#define pinstTradeTarget_x                                         0xE9EC48
#define instTributeActive_x                                        0xDEBB71
#define pinstViewActor_x                                           0xDEC498
#define pinstWorldData_x                                           0xE9E3A8
#define pinstZoneAddr_x                                            0xEA5EF8
#define pinstPlayerPath_x                                          0xF479A8
#define pinstTargetIndicator_x                                     0xF49310
#define EQObject_Top_x                                             0xE9EA2C
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDEBF3C
#define pinstCAchievementsWnd_x                                    0xDEC454
#define pinstCActionsWnd_x                                         0xDEBF78
#define pinstCAdvancedDisplayOptionsWindow_x                       0xDEC514
#define pinstCAdvancedLootWnd_x                                    0xDEC4C4
#define pinstCAdventureLeaderboardWnd_x                            0xF56920
#define pinstCAdventureRequestWnd_x                                0xF569D0
#define pinstCAdventureStatsWnd_x                                  0xF56A80
#define pinstCAggroMeterWnd_x                                      0xDEC4F8
#define pinstCAlarmWnd_x                                           0xDEC480
#define pinstCAlertHistoryWnd_x                                    0xDEBEEC
#define pinstCAlertStackWnd_x                                      0xDEC4E0
#define pinstCAlertWnd_x                                           0xDEC4F4
#define pinstCAltStorageWnd_x                                      0xF56DE0
#define pinstCAudioTriggersWindow_x                                0xCA0778
#define pinstCAuraWnd_x                                            0xDEC4C8
#define pinstCAvaZoneWnd_x                                         0xDEBEF0
#define pinstCBandolierWnd_x                                       0xDEC50C
#define pinstCBankWnd_x                                            0xDEBCB0
#define pinstCBarterMerchantWnd_x                                  0xF58020
#define pinstCBarterSearchWnd_x                                    0xF580D0
#define pinstCBarterWnd_x                                          0xF58180
#define pinstCBazaarConfirmationWnd_x                              0xDEC490
#define pinstCBazaarSearchWnd_x                                    0xDEBF40
#define pinstCBazaarWnd_x                                          0xDEC45C
#define pinstCBlockedBuffWnd_x                                     0xDEC4D4
#define pinstCBlockedPetBuffWnd_x                                  0xDEC4FC
#define pinstCBodyTintWnd_x                                        0xDEC404
#define pinstCBookWnd_x                                            0xDEC544
#define pinstCBreathWnd_x                                          0xDEBF50
#define pinstCBuffWindowNORMAL_x                                   0xDEC4BC
#define pinstCBuffWindowSHORT_x                                    0xDEC4C0
#define pinstCBugReportWnd_x                                       0xDEBCAC
#define pinstCButtonWnd_x                                          0x15DB570
#define pinstCCastingWnd_x                                         0xDEC538
#define pinstCCastSpellWnd_x                                       0xDEBF4C
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDEC410
#define pinstCChatWindowManager_x                                  0xF58C40
#define pinstCClaimWnd_x                                           0xF58D98
#define pinstCColorPickerWnd_x                                     0xDEBF04
#define pinstCCombatAbilityWnd_x                                   0xDEC46C
#define pinstCCombatSkillsSelectWnd_x                              0xDEC424
#define pinstCCompassWnd_x                                         0xDEBF7C
#define pinstCConfirmationDialog_x                                 0xF5DC98
#define pinstCContainerMgr_x                                       0xDEC400
#define pinstCContextMenuManager_x                                 0x15DB2C0
#define pinstCCursorAttachment_x                                   0xDEC520
#define pinstCDynamicZoneWnd_x                                     0xF59360
#define pinstCEditLabelWnd_x                                       0xDEC4A8
#define pinstCEQMainWnd_x                                          0xF595A8
#define pinstCEventCalendarWnd_x                                   0xDEBF44
#define pinstCExtendedTargetWnd_x                                  0xDEC4D8
#define pinstCPlayerCustomizationWnd_x                             0xDEC428
#define pinstCFactionWnd_x                                         0xDEC448
#define pinstCFellowshipWnd_x                                      0xF597A8
#define pinstCFileSelectionWnd_x                                   0xDEBF00
#define pinstCFindItemWnd_x                                        0xDEC43C
#define pinstCFindLocationWnd_x                                    0xF59900
#define pinstCFriendsWnd_x                                         0xDEC438
#define pinstCGemsGameWnd_x                                        0xDEC444
#define pinstCGiveWnd_x                                            0xDEC484
#define pinstCGroupSearchFiltersWnd_x                              0xDEC510
#define pinstCGroupSearchWnd_x                                     0xF59CF8
#define pinstCGroupWnd_x                                           0xF59DA8
#define pinstCGuildBankWnd_x                                       0xF59E58
#define pinstCGuildCreationWnd_x                                   0xF59F08
#define pinstCGuildMgmtWnd_x                                       0xF59FB8
#define pinstCharacterCreation_x                                   0xDEC430
#define pinstCHelpWnd_x                                            0xDEC47C
#define pinstCHeritageSelectionWnd_x                               0xDEC434
#define pinstCHotButtonWnd_x                                       0xF5C110
#define pinstCHotButtonWnd1_x                                      0xF5C110
#define pinstCHotButtonWnd2_x                                      0xF5C114
#define pinstCHotButtonWnd3_x                                      0xF5C118
#define pinstCHotButtonWnd4_x                                      0xF5C11C
#define pinstCIconSelectionWnd_x                                   0xDEC51C
#define pinstCInspectWnd_x                                         0xDEC500
#define pinstCInventoryWnd_x                                       0xDEC4CC
#define pinstCInvSlotMgr_x                                         0xDEBF30
#define pinstCItemDisplayManager_x                                 0xF5C6A0
#define pinstCItemExpTransferWnd_x                                 0xF5C7D0
#define pinstCItemOverflowWnd_x                                    0xDEBF48
#define pinstCJournalCatWnd_x                                      0xDEBF1C
#define pinstCJournalNPCWnd_x                                      0xDEBEDC
#define pinstCJournalTextWnd_x                                     0xDEBEDC
#define pinstCKeyRingWnd_x                                         0xDEC534
#define pinstCLargeDialogWnd_x                                     0xF5E918
#define pinstCLayoutCopyWnd_x                                      0xF5CB20
#define pinstCLFGuildWnd_x                                         0xF5CBD0
#define pinstCLoadskinWnd_x                                        0xDEC460
#define pinstCLootFiltersCopyWnd_x                                 0xCBCEE8
#define pinstCLootFiltersWnd_x                                     0xDEC4E4
#define pinstCLootSettingsWnd_x                                    0xDEC508
#define pinstCLootWnd_x                                            0xDEBF20
#define pinstCMailAddressBookWnd_x                                 0xDEBF34
#define pinstCMailCompositionWnd_x                                 0xDEBF0C
#define pinstCMailIgnoreListWnd_x                                  0xDEBF38
#define pinstCMailWnd_x                                            0xDEBEF8
#define pinstCManageLootWnd_x                                      0xDED3A0
#define pinstCMapToolbarWnd_x                                      0xDEC488
#define pinstCMapViewWnd_x                                         0xDEC450
#define pinstCMarketplaceWnd_x                                     0xDEC4E8
#define pinstCMerchantWnd_x                                        0xDEBF2C
#define pinstCMIZoneSelectWnd_x                                    0xF5D408
#define pinstCMusicPlayerWnd_x                                     0xDEBCCC
#define pinstCNameChangeMercWnd_x                                  0xDEC48C
#define pinstCNameChangePetWnd_x                                   0xDEC458
#define pinstCNameChangeWnd_x                                      0xDEC4A0
#define pinstCNoteWnd_x                                            0xDEC464
#define pinstCObjectPreviewWnd_x                                   0xDEC504
#define pinstCOptionsWnd_x                                         0xDEC474
#define pinstCPetInfoWnd_x                                         0xDEBEF4
#define pinstCPetitionQWnd_x                                       0xDEC420
#define pinstCPlayerNotesWnd_x                                     0xDEC408
#define pinstCPlayerWnd_x                                          0xDEBEE8
#define pinstCPopupWndManager_x                                    0xF5DC98
#define pinstCProgressionSelectionWnd_x                            0xF5DD48
#define pinstCPurchaseGroupWnd_x                                   0xDEBCC0
#define pinstCPurchaseWnd_x                                        0xDEC53C
#define pinstCPvPLeaderboardWnd_x                                  0xF5DDF8
#define pinstCPvPStatsWnd_x                                        0xF5DEA8
#define pinstCQuantityWnd_x                                        0xDEBED8
#define pinstCRaceChangeWnd_x                                      0xDEC4D0
#define pinstCRaidOptionsWnd_x                                     0xDEC518
#define pinstCRaidWnd_x                                            0xDEBF28
#define pinstCRealEstateItemsWnd_x                                 0xDEC44C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDEBFF8
#define pinstCRealEstateManageWnd_x                                0xDEBCC4
#define pinstCRealEstateNeighborhoodWnd_x                          0xDEBEE4
#define pinstCRealEstatePlotSearchWnd_x                            0xDEBEFC
#define pinstCRealEstatePurchaseWnd_x                              0xDEBF18
#define pinstCRespawnWnd_x                                         0xDEC4F0
#define pinstCRewardSelectionWnd_x                                 0xF5E5F0
#define pinstCSelectorWnd_x                                        0xDEC41C
#define pinstCSendMoneyWnd_x                                       0xDEC494
#define pinstCServerListWnd_x                                      0xDEBF24
#define pinstCSkillsSelectWnd_x                                    0xDEC418
#define pinstCSkillsWnd_x                                          0xDEBFF4
#define pinstCSocialEditWnd_x                                      0xDEC52C
#define pinstCSocialWnd_x                                          0xDEC478
#define pinstCSpellBookWnd_x                                       0xDEC468
#define pinstCStoryWnd_x                                           0xDEBF74
#define pinstCTargetOfTargetWnd_x                                  0xF5FC50
#define pinstCTargetWnd_x                                          0xDEC4EC
#define pinstCTaskOverlayWnd_x                                     0xDEBCB4
#define pinstCTaskSelectWnd_x                                      0xF5FDA8
#define pinstCTaskManager_x                                        0xCBD828
#define pinstCTaskTemplateSelectWnd_x                              0xF5FE58
#define pinstCTaskWnd_x                                            0xF5FF08
#define pinstCTextEntryWnd_x                                       0xDEC540
#define pinstCTimeLeftWnd_x                                        0xDEC414
#define pinstCTipWndCONTEXT_x                                      0xF6010C
#define pinstCTipWndOFDAY_x                                        0xF60108
#define pinstCTitleWnd_x                                           0xF601B8
#define pinstCTrackingWnd_x                                        0xDEC4DC
#define pinstCTradeskillWnd_x                                      0xF60320
#define pinstCTradeWnd_x                                           0xDEC40C
#define pinstCTrainWnd_x                                           0xDEBF10
#define pinstCTributeBenefitWnd_x                                  0xF60520
#define pinstCTributeMasterWnd_x                                   0xF605D0
#define pinstCTributeTrophyWnd_x                                   0xF60680
#define pinstCVideoModesWnd_x                                      0xDEBCB8
#define pinstCVoiceMacroWnd_x                                      0xF498C8
#define pinstCVoteResultsWnd_x                                     0xDEC440
#define pinstCVoteWnd_x                                            0xDEC42C
#define pinstCWebManager_x                                         0xF49F44
#define pinstCZoneGuideWnd_x                                       0xDEBCBC
#define pinstCZonePathWnd_x                                        0xDEBED0

#define pinstEQSuiteTextureLoader_x                                0xC8AB30
#define pinstItemIconCache_x                                       0xF59560
#define pinstLootFiltersManager_x                                  0xCBCF98
#define pinstRewardSelectionWnd_x                                  0xF5E5F0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C4BB0
#define __CastRay2_x                                               0x5C4C00
#define __ConvertItemTags_x                                        0x5E08B0
#define __CleanItemTags_x                                          0x47D3D0
#define __DoesFileExist_x                                          0x8FA8A0
#define __EQGetTime_x                                              0x8F7480
#define __ExecuteCmd_x                                             0x5BD510
#define __FixHeading_x                                             0x98C0D0
#define __FlushDxKeyboard_x                                        0x6B0810
#define __GameLoop_x                                               0x6B3B40
#define __get_bearing_x                                            0x5C4710
#define __get_melee_range_x                                        0x5C4DF0
#define __GetAnimationCache_x                                      0x718FC0
#define __GetGaugeValueFromEQ_x                                    0x80AC20
#define __GetLabelFromEQ_x                                         0x80C700
#define __GetXTargetType_x                                         0x98DB90
#define __HandleMouseWheel_x                                       0x6B4A20
#define __HeadingDiff_x                                            0x98C140
#define __HelpPath_x                                               0xF44E04
#define __LoadFrontEnd_x                                           0x6B0E50
#define __NewUIINI_x                                               0x80A8F0
#define __ProcessGameEvents_x                                      0x625600
#define __ProcessMouseEvent_x                                      0x624D90
#define __SaveColors_x                                             0x55DF00
#define __STMLToText_x                                             0x92F430
#define __ToggleKeyRingItem_x                                      0x51C670
#define CMemoryMappedFile__SetFile_x                               0xA7B620
#define CrashDetected_x                                            0x6B2900
#define DrawNetStatus_x                                            0x6515F0
#define Expansion_HoT_x                                            0xEA6D48
#define Teleport_Table_Size_x                                      0xE9E7E0
#define Teleport_Table_x                                           0xE9ECB0
#define Util__FastTime_x                                           0x8F7050
#define __CopyLayout_x                                             0x63F850
#define __WndProc_x                                                0x6B2E00
#define __ProcessKeyboardEvent_x                                   0x6B23A0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490670
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499670
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499440
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493C10
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x493060

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5660B0
#define AltAdvManager__IsAbilityReady_x                            0x564E50
#define AltAdvManager__GetAAById_x                                 0x5651E0
#define AltAdvManager__CanTrainAbility_x                           0x565250
#define AltAdvManager__CanSeeAbility_x                             0x5655B0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB3B0
#define CharacterZoneClient__HasSkill_x                            0x4D6230
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7960
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2A90
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBF20
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA310
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA3F0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA4D0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4B80
#define CharacterZoneClient__BardCastBard_x                        0x4C75B0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF930
#define CharacterZoneClient__GetEffect_x                           0x4BBE60
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5BF0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5CC0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5D10
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5E60
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C6040
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3E70
#define CharacterZoneClient__FindItemByGuid_x                      0x4D88C0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D8340

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DA630
#define CBankWnd__WndNotification_x                                0x6DA400

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E7F30

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92CC10
#define CButtonWnd__CButtonWnd_x                                   0x92B7E0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x708190
#define CChatManager__InitContextMenu_x                            0x7012C0
#define CChatManager__FreeChatWindow_x                             0x706CD0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9C90
#define CChatManager__SetLockedActiveChatWindow_x                  0x707E10
#define CChatManager__CreateChatWindow_x                           0x707310

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9DA0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93FE40
#define CContextMenu__dCContextMenu_x                              0x940080
#define CContextMenu__AddMenuItem_x                                0x940090
#define CContextMenu__RemoveMenuItem_x                             0x9403A0
#define CContextMenu__RemoveAllMenuItems_x                         0x9403C0
#define CContextMenu__CheckMenuItem_x                              0x940440
#define CContextMenu__SetMenuItem_x                                0x9402C0
#define CContextMenu__AddSeparator_x                               0x940220

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9409D0
#define CContextMenuManager__RemoveMenu_x                          0x940A40
#define CContextMenuManager__PopupMenu_x                           0x940B00
#define CContextMenuManager__Flush_x                               0x940970
#define CContextMenuManager__GetMenu_x                             0x49B8F0
#define CContextMenuManager__CreateDefaultMenu_x                   0x713920

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D20B0
#define CChatService__GetFriendName_x                              0x8D20C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x708A00
#define CChatWindow__Clear_x                                       0x709CD0
#define CChatWindow__WndNotification_x                             0x70A460
#define CChatWindow__AddHistory_x                                  0x709590

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93D290
#define CComboWnd__Draw_x                                          0x93C780
#define CComboWnd__GetCurChoice_x                                  0x93D0D0
#define CComboWnd__GetListRect_x                                   0x93CC30
#define CComboWnd__GetTextRect_x                                   0x93D300
#define CComboWnd__InsertChoice_x                                  0x93CDC0
#define CComboWnd__SetColors_x                                     0x93CD90
#define CComboWnd__SetChoice_x                                     0x93D0A0
#define CComboWnd__GetItemCount_x                                  0x93D0E0
#define CComboWnd__GetCurChoiceText_x                              0x93D120
#define CComboWnd__GetChoiceText_x                                 0x93D0F0
#define CComboWnd__InsertChoiceAtIndex_x                           0x93CE60

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x711330
#define CContainerWnd__vftable_x                                   0xAFF754
#define CContainerWnd__SetContainer_x                              0x712890

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x558860
#define CDisplay__PreZoneMainUI_x                                  0x558870
#define CDisplay__CleanGameUI_x                                    0x55DCC0
#define CDisplay__GetClickedActor_x                                0x550CC0
#define CDisplay__GetUserDefinedColor_x                            0x549330
#define CDisplay__GetWorldFilePath_x                               0x552730
#define CDisplay__is3dON_x                                         0x54D920
#define CDisplay__ReloadUI_x                                       0x557D70
#define CDisplay__WriteTextHD2_x                                   0x54D710
#define CDisplay__TrueDistance_x                                   0x5543F0
#define CDisplay__SetViewActor_x                                   0x5505E0
#define CDisplay__GetFloorHeight_x                                 0x54D9E0
#define CDisplay__SetRenderWindow_x                                0x54C360
#define CDisplay__ToggleScreenshotMode_x                           0x5500B0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95FC90

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x943330
#define CEditWnd__EnsureCaretVisible_x                             0x945500
#define CEditWnd__GetCaretPt_x                                     0x9444B0
#define CEditWnd__GetCharIndexPt_x                                 0x944260
#define CEditWnd__GetDisplayString_x                               0x944100
#define CEditWnd__GetHorzOffset_x                                  0x9429D0
#define CEditWnd__GetLineForPrintableChar_x                        0x945400
#define CEditWnd__GetSelStartPt_x                                  0x944510
#define CEditWnd__GetSTMLSafeText_x                                0x943F20
#define CEditWnd__PointFromPrintableChar_x                         0x945030
#define CEditWnd__SelectableCharFromPoint_x                        0x9451A0
#define CEditWnd__SetEditable_x                                    0x9445E0
#define CEditWnd__SetWindowTextA_x                                 0x943CA0
#define CEditWnd__ReplaceSelection_x                               0x944CA0
#define CEditWnd__ReplaceSelection1_x                              0x944C20

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x612C00
#define CEverQuest__ClickedPlayer_x                                0x604DA0
#define CEverQuest__CreateTargetIndicator_x                        0x622770
#define CEverQuest__DeleteTargetIndicator_x                        0x622800
#define CEverQuest__DoTellWindow_x                                 0x4E9E80
#define CEverQuest__OutputTextToLog_x                              0x4EA150
#define CEverQuest__DropHeldItemOnGround_x                         0x5F9EF0
#define CEverQuest__dsp_chat_x                                     0x4EA4E0
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
#define CEverQuest__LMouseUp_x                                     0x5FC410
#define CEverQuest__RightClickedOnPlayer_x                         0x5FE970
#define CEverQuest__RMouseUp_x                                     0x5FD3A0
#define CEverQuest__SetGameState_x                                 0x5F9C80
#define CEverQuest__UPCNotificationFlush_x                         0x61E820
#define CEverQuest__IssuePetCommand_x                              0x61A0C0
#define CEverQuest__ReportSuccessfulHit_x                          0x6147B0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x723030
#define CGaugeWnd__CalcLinesFillRect_x                             0x723090
#define CGaugeWnd__Draw_x                                          0x7226B0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4B01D0
#define CGuild__GetGuildName_x                                     0x4AEC80
#define CGuild__GetGuildIndex_x                                    0x4AF280

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73CCE0

//CHotButton
#define CHotButton__SetCheck_x                                     0x633E20
#define CHotButton__SetButtonSize_x                                0x6341E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x749EE0
#define CInvSlotMgr__MoveItem_x                                    0x748BF0
#define CInvSlotMgr__SelectSlot_x                                  0x749FB0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x747420
#define CInvSlot__SliderComplete_x                                 0x745150
#define CInvSlot__GetItemBase_x                                    0x744AE0
#define CInvSlot__UpdateItem_x                                     0x744C50

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74BA30
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74ABD0
#define CInvSlotWnd__HandleLButtonUp_x                             0x74B5B0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x805F90
#define CItemDisplayWnd__UpdateStrings_x                           0x75A1F0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x753ED0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7543F0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x75A800
#define CItemDisplayWnd__AboutToShow_x                             0x759E30
#define CItemDisplayWnd__WndNotification_x                         0x75BA50
#define CItemDisplayWnd__RequestConvertItem_x                      0x75B3A0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x758E90
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x759C50

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8369C0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75FFA0

// CLabel 
#define CLabel__Draw_x                                             0x765A90

// CListWnd
#define CListWnd__CListWnd_x                                       0x915AF0
#define CListWnd__dCListWnd_x                                      0x915E10
#define CListWnd__AddColumn_x                                      0x91A290
#define CListWnd__AddColumn1_x                                     0x91A2E0
#define CListWnd__AddLine_x                                        0x91A670
#define CListWnd__AddString_x                                      0x91A470
#define CListWnd__CalculateFirstVisibleLine_x                      0x91A050
#define CListWnd__CalculateVSBRange_x                              0x919E30
#define CListWnd__ClearSel_x                                       0x91AE50
#define CListWnd__ClearAllSel_x                                    0x91AEB0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91B8C0
#define CListWnd__Compare_x                                        0x919760
#define CListWnd__Draw_x                                           0x915F40
#define CListWnd__DrawColumnSeparators_x                           0x918730
#define CListWnd__DrawHeader_x                                     0x918BA0
#define CListWnd__DrawItem_x                                       0x9190A0
#define CListWnd__DrawLine_x                                       0x9188A0
#define CListWnd__DrawSeparator_x                                  0x9187D0
#define CListWnd__EnableLine_x                                     0x918000
#define CListWnd__EnsureVisible_x                                  0x91B7E0
#define CListWnd__ExtendSel_x                                      0x91AD80
#define CListWnd__GetColumnTooltip_x                               0x917B40
#define CListWnd__GetColumnMinWidth_x                              0x917BB0
#define CListWnd__GetColumnWidth_x                                 0x917AB0
#define CListWnd__GetCurSel_x                                      0x917440
#define CListWnd__GetItemAtPoint_x                                 0x918280
#define CListWnd__GetItemAtPoint1_x                                0x9182F0
#define CListWnd__GetItemData_x                                    0x9174C0
#define CListWnd__GetItemHeight_x                                  0x917880
#define CListWnd__GetItemIcon_x                                    0x917650
#define CListWnd__GetItemRect_x                                    0x9180F0
#define CListWnd__GetItemText_x                                    0x917500
#define CListWnd__GetSelList_x                                     0x91AF00
#define CListWnd__GetSeparatorRect_x                               0x918530
#define CListWnd__InsertLine_x                                     0x91AA60
#define CListWnd__RemoveLine_x                                     0x91ABB0
#define CListWnd__SetColors_x                                      0x919E00
#define CListWnd__SetColumnJustification_x                         0x919B30
#define CListWnd__SetColumnLabel_x                                 0x91A410
#define CListWnd__SetColumnWidth_x                                 0x919A50
#define CListWnd__SetCurSel_x                                      0x91ACC0
#define CListWnd__SetItemColor_x                                   0x91B490
#define CListWnd__SetItemData_x                                    0x91B450
#define CListWnd__SetItemText_x                                    0x91B070
#define CListWnd__ShiftColumnSeparator_x                           0x919BF0
#define CListWnd__Sort_x                                           0x9198E0
#define CListWnd__ToggleSel_x                                      0x91ACF0
#define CListWnd__SetColumnsSizable_x                              0x919CA0
#define CListWnd__SetItemWnd_x                                     0x91B320
#define CListWnd__GetItemWnd_x                                     0x9176A0
#define CListWnd__SetItemIcon_x                                    0x91B0F0
#define CListWnd__CalculateCustomWindowPositions_x                 0x91A150
#define CListWnd__SetVScrollPos_x                                  0x919A30

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77B0D0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7797E0
#define CMapViewWnd__HandleLButtonDown_x                           0x776820

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79B4E0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79BDC0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79C2F0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79F2A0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x79A050
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A4E70
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79B100

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89FC50
#define CPacketScrambler__hton_x                                   0x89FC40

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x934A00
#define CSidlManager__FindScreenPieceTemplate_x                    0x934E10
#define CSidlManager__FindScreenPieceTemplate1_x                   0x934C00
#define CSidlManager__CreateLabel_x                                0x7FD010
#define CSidlManager__CreateXWndFromTemplate_x                     0x937D70
#define CSidlManager__CreateXWndFromTemplate1_x                    0x937F50
#define CSidlManager__CreateXWnd_x                                 0x7FCF40
#define CSidlManager__CreateHotButtonWnd_x                         0x7FD510

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9314E0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9313E0
#define CSidlScreenWnd__ConvertToRes_x                             0x95A740
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x930ED0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x930BC0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x930C90
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x930D60
#define CSidlScreenWnd__DrawSidlPiece_x                            0x931980
#define CSidlScreenWnd__EnableIniStorage_x                         0x931E50
#define CSidlScreenWnd__GetSidlPiece_x                             0x931B70
#define CSidlScreenWnd__Init1_x                                    0x9307C0
#define CSidlScreenWnd__LoadIniInfo_x                              0x931EA0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9329E0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92FBE0
#define CSidlScreenWnd__StoreIniInfo_x                             0x932560
#define CSidlScreenWnd__StoreIniVis_x                              0x9328C0
#define CSidlScreenWnd__WndNotification_x                          0x931890
#define CSidlScreenWnd__GetChildItem_x                             0x931DD0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9216F0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DB190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6997C0
#define CSkillMgr__GetSkillCap_x                                   0x6999A0
#define CSkillMgr__GetNameToken_x                                  0x698F40
#define CSkillMgr__IsActivatedSkill_x                              0x699080
#define CSkillMgr__IsCombatSkill_x                                 0x698FC0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9417B0
#define CSliderWnd__SetValue_x                                     0x941620
#define CSliderWnd__SetNumTicks_x                                  0x941680

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x8032B0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x94A100
#define CStmlWnd__ParseSTML_x                                      0x94B410
#define CStmlWnd__CalculateHSBRange_x                              0x94B1E0
#define CStmlWnd__CalculateVSBRange_x                              0x94B150
#define CStmlWnd__CanBreakAtCharacter_x                            0x94F520
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9501B0
#define CStmlWnd__ForceParseNow_x                                  0x94A6A0
#define CStmlWnd__GetNextTagPiece_x                                0x94F480
#define CStmlWnd__GetSTMLText_x                                    0x50D8E0
#define CStmlWnd__GetVisibleText_x                                 0x94A6C0
#define CStmlWnd__InitializeWindowVariables_x                      0x950000
#define CStmlWnd__MakeStmlColorTag_x                               0x949770
#define CStmlWnd__MakeWndNotificationTag_x                         0x9497E0
#define CStmlWnd__SetSTMLText_x                                    0x948820
#define CStmlWnd__StripFirstSTMLLines_x                            0x9512B0
#define CStmlWnd__UpdateHistoryString_x                            0x9503C0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x947970
#define CTabWnd__DrawCurrentPage_x                                 0x9480A0
#define CTabWnd__DrawTab_x                                         0x947DC0
#define CTabWnd__GetCurrentPage_x                                  0x947170
#define CTabWnd__GetPageInnerRect_x                                0x9473B0
#define CTabWnd__GetTabInnerRect_x                                 0x9472F0
#define CTabWnd__GetTabRect_x                                      0x9471A0
#define CTabWnd__InsertPage_x                                      0x9475C0
#define CTabWnd__RemovePage_x                                      0x947730
#define CTabWnd__SetPage_x                                         0x947430
#define CTabWnd__SetPageRect_x                                     0x9478B0
#define CTabWnd__UpdatePage_x                                      0x947C80
#define CTabWnd__GetPageFromTabIndex_x                             0x947D00
#define CTabWnd__GetCurrentTabIndex_x                              0x947160

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x760420
#define CPageWnd__SetTabText_x                                     0x946CB0
#define CPageWnd__FlashTab_x                                       0x946D10

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9410

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91E5C0
#define CTextureFont__GetTextExtent_x                              0x91E780

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AD9F0
#define CHtmlComponentWnd__ValidateUri_x                           0x73E6D0
#define CHtmlWnd__SetClientCallbacks_x                             0x639270
#define CHtmlWnd__AddObserver_x                                    0x639290
#define CHtmlWnd__RemoveObserver_x                                 0x6392F0
#define Window__getProgress_x                                      0x8551D0
#define Window__getStatus_x                                        0x8551F0
#define Window__getURI_x                                           0x855200

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x957550

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90B6E0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9B80
#define CXStr__CXStr1_x                                            0x9E29F0
#define CXStr__CXStr3_x                                            0x8F3440
#define CXStr__dCXStr_x                                            0x478440
#define CXStr__operator_equal_x                                    0x8F3670
#define CXStr__operator_equal1_x                                   0x8F36B0
#define CXStr__operator_plus_equal1_x                              0x8F4140
#define CXStr__SetString_x                                         0x8F6030
#define CXStr__operator_char_p_x                                   0x8F3B80
#define CXStr__GetChar_x                                           0x8F5980
#define CXStr__Delete_x                                            0x8F5230
#define CXStr__GetUnicode_x                                        0x8F59F0
#define CXStr__GetLength_x                                         0x47D780
#define CXStr__Mid_x                                               0x47D790
#define CXStr__Insert_x                                            0x8F5A50
#define CXStr__FindNext_x                                          0x8F56A0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93FA50
#define CXWnd__BringToTop_x                                        0x924E50
#define CXWnd__Center_x                                            0x9249D0
#define CXWnd__ClrFocus_x                                          0x9247E0
#define CXWnd__Destroy_x                                           0x924890
#define CXWnd__DoAllDrawing_x                                      0x920E80
#define CXWnd__DrawChildren_x                                      0x920E50
#define CXWnd__DrawColoredRect_x                                   0x9212E0
#define CXWnd__DrawTooltip_x                                       0x91F9C0
#define CXWnd__DrawTooltipAtPoint_x                                0x91FA80
#define CXWnd__GetBorderFrame_x                                    0x921140
#define CXWnd__GetChildWndAt_x                                     0x924EF0
#define CXWnd__GetClientClipRect_x                                 0x9230F0
#define CXWnd__GetScreenClipRect_x                                 0x9231C0
#define CXWnd__GetScreenRect_x                                     0x923380
#define CXWnd__GetRelativeRect_x                                   0x923450
#define CXWnd__GetTooltipRect_x                                    0x921330
#define CXWnd__GetWindowTextA_x                                    0x49CFE0
#define CXWnd__IsActive_x                                          0x921A70
#define CXWnd__IsDescendantOf_x                                    0x923D60
#define CXWnd__IsReallyVisible_x                                   0x923D90
#define CXWnd__IsType_x                                            0x925560
#define CXWnd__Move_x                                              0x923E00
#define CXWnd__Move1_x                                             0x923EC0
#define CXWnd__ProcessTransition_x                                 0x924980
#define CXWnd__Refade_x                                            0x924190
#define CXWnd__Resize_x                                            0x9243F0
#define CXWnd__Right_x                                             0x924C10
#define CXWnd__SetFocus_x                                          0x9247A0
#define CXWnd__SetFont_x                                           0x924810
#define CXWnd__SetKeyTooltip_x                                     0x925380
#define CXWnd__SetMouseOver_x                                      0x9222A0
#define CXWnd__StartFade_x                                         0x923C50
#define CXWnd__GetChildItem_x                                      0x925060
#define CXWnd__SetParent_x                                         0x923B30
#define CXWnd__Minimize_x                                          0x924460

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95B7C0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x927D60
#define CXWndManager__DrawWindows_x                                0x927D80
#define CXWndManager__GetKeyboardFlags_x                           0x92A480
#define CXWndManager__HandleKeyboardMsg_x                          0x92A030
#define CXWndManager__RemoveWnd_x                                  0x92A6A0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92ABF0

// CDBStr
#define CDBStr__GetString_x                                        0x5482E0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4C0090
#define EQ_Character__Cur_HP_x                                     0x4D3270
#define EQ_Character__Cur_Mana_x                                   0x4DA9D0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C3100
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3AB0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3C00
#define EQ_Character__GetHPRegen_x                                 0x4E08D0
#define EQ_Character__GetEnduranceRegen_x                          0x4E0ED0
#define EQ_Character__GetManaRegen_x                               0x4E1310
#define EQ_Character__Max_Endurance_x                              0x65FBA0
#define EQ_Character__Max_HP_x                                     0x4D30A0
#define EQ_Character__Max_Mana_x                                   0x65F9A0
#define EQ_Character__doCombatAbility_x                            0x661F90
#define EQ_Character__UseSkill_x                                   0x4E3120
#define EQ_Character__GetConLevel_x                                0x658530
#define EQ_Character__IsExpansionFlag_x                            0x5BBCC0
#define EQ_Character__TotalEffect_x                                0x4C6EA0
#define EQ_Character__GetPCSpellAffect_x                           0x4C3E50
#define EQ_Character__SpellDuration_x                              0x4C3980
#define EQ_Character__MySpellDuration_x                            0x4B23E0
#define EQ_Character__GetAdjustedSkill_x                           0x4D5FF0
#define EQ_Character__GetBaseSkill_x                               0x4D6F90
#define EQ_Character__CanUseItem_x                                 0x4DACE0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BF070

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x675EA0

//PcClient
#define PcClient__vftable_x                                        0xAF31C8
#define PcClient__PcClient_x                                       0x655C90

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BAAD0
#define CCharacterListWnd__EnterWorld_x                            0x4BA4A0
#define CCharacterListWnd__Quit_x                                  0x4BA1F0
#define CCharacterListWnd__UpdateList_x                            0x4BA690

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x63A430
#define EQ_Item__CreateItemTagString_x                             0x8990F0
#define EQ_Item__IsStackable_x                                     0x89DE10
#define EQ_Item__GetImageNum_x                                     0x89AC80
#define EQ_Item__CreateItemClient_x                                0x639670
#define EQ_Item__GetItemValue_x                                    0x89BF70
#define EQ_Item__ValueSellMerchant_x                               0x89F820
#define EQ_Item__IsKeyRingItem_x                                   0x89D6A0
#define EQ_Item__CanGoInBag_x                                      0x63A550
#define EQ_Item__IsEmpty_x                                         0x89D1F0
#define EQ_Item__GetMaxItemCount_x                                 0x89C390
#define EQ_Item__GetHeldItem_x                                     0x89AB50
#define EQ_Item__GetAugmentFitBySlot_x                             0x898940

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x566DC0
#define EQ_LoadingS__Array_x                                       0xC14130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6604A0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A8B10
#define EQ_PC__GetCombatAbility_x                                  0x8A9180
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A91F0
#define EQ_PC__GetItemRecastTimer_x                                0x662510
#define EQ_PC__HasLoreItem_x                                       0x658D50
#define EQ_PC__AlertInventoryChanged_x                             0x657E60
#define EQ_PC__GetPcZoneClient_x                                   0x684F70
#define EQ_PC__RemoveMyAffect_x                                    0x665740
#define EQ_PC__GetKeyRingItems_x                                   0x8A9AC0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A9840
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A9DC0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C2110
#define EQItemList__add_object_x                                   0x5EF710
#define EQItemList__add_item_x                                     0x5C2670
#define EQItemList__delete_item_x                                  0x5C26C0
#define EQItemList__FreeItemList_x                                 0x5C25C0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x544E90

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6777A0
#define EQPlayer__dEQPlayer_x                                      0x66AB30
#define EQPlayer__DoAttack_x                                       0x67F700
#define EQPlayer__EQPlayer_x                                       0x66B1F0
#define EQPlayer__SetNameSpriteState_x                             0x66F4B0
#define EQPlayer__SetNameSpriteTint_x                              0x670390
#define PlayerBase__HasProperty_j_x                                0x98A4E0
#define EQPlayer__IsTargetable_x                                   0x98A980
#define EQPlayer__CanSee_x                                         0x98A7E0
#define EQPlayer__CanSee1_x                                        0x98A8B0
#define PlayerBase__GetVisibilityLineSegment_x                     0x98A5A0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x682A00
#define PlayerZoneClient__GetLevel_x                               0x684FB0
#define PlayerZoneClient__IsValidTeleport_x                        0x5F0880
#define PlayerZoneClient__LegalPlayerRace_x                        0x55FB20

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x67A600
#define EQPlayerManager__GetSpawnByName_x                          0x67A6B0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x67A740

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63DAB0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63DB30
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63DB70
#define KeypressHandler__ClearCommandStateArray_x                  0x63EF60
#define KeypressHandler__HandleKeyDown_x                           0x63EF80
#define KeypressHandler__HandleKeyUp_x                             0x63F020
#define KeypressHandler__SaveKeymapping_x                          0x63F470

// MapViewMap 
#define MapViewMap__Clear_x                                        0x776F40
#define MapViewMap__SaveEx_x                                       0x77A300
#define MapViewMap__SetZoom_x                                      0x77E9C0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BD0E0

// StringTable 
#define StringTable__getString_x                                   0x8B7FC0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6653B0
#define PcZoneClient__RemovePetEffect_x                            0x6659E0
#define PcZoneClient__HasAlternateAbility_x                        0x65F7D0
#define PcZoneClient__GetCurrentMod_x                              0x4E6240
#define PcZoneClient__GetModCap_x                                  0x4E6140
#define PcZoneClient__CanEquipItem_x                               0x65FE80
#define PcZoneClient__GetItemByID_x                                0x662990
#define PcZoneClient__GetItemByItemClass_x                         0x662AE0
#define PcZoneClient__RemoveBuffEffect_x                           0x665A00
#define PcZoneClient__BandolierSwap_x                              0x660A60
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x6624B0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F5410

//IconCache
#define IconCache__GetIcon_x                                       0x7189C0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7104D0
#define CContainerMgr__CloseContainer_x                            0x7107A0
#define CContainerMgr__OpenExperimentContainer_x                   0x711220

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CF6C0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x6325E0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76D520
#define CLootWnd__RequestLootSlot_x                                0x76C7F0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58EA70
#define EQ_Spell__SpellAffects_x                                   0x58EEE0
#define EQ_Spell__SpellAffectBase_x                                0x58ECA0
#define EQ_Spell__IsStackable_x                                    0x4CACB0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CAAD0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7D70
#define EQ_Spell__IsSPAStacking_x                                  0x58FD30
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58F240
#define EQ_Spell__IsNoRemove_x                                     0x4CAC90
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58FD40
#define __IsResEffectSpell_x                                       0x4C9ED0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD660

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C76B0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8166B0
#define CTargetWnd__WndNotification_x                              0x815EF0
#define CTargetWnd__RefreshTargetBuffs_x                           0x8161C0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x815050

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81AD20
#define CTaskWnd__ConfirmAbandonTask_x                             0x81D960

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x542860
#define CTaskManager__HandleMessage_x                              0x540CF0
#define CTaskManager__GetTaskStatus_x                              0x542910
#define CTaskManager__GetElementDescription_x                      0x542990

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x589BD0
#define EqSoundManager__PlayScriptMp3_x                            0x589E90
#define EqSoundManager__SoundAssistPlay_x                          0x69D770
#define EqSoundManager__WaveInstancePlay_x                         0x69CCE0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x533C90

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9461C0
#define CTextureAnimation__Draw_x                                  0x9463C0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x942110

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56E9B0
#define CAltAbilityData__GetMercMaxRank_x                          0x56E940
#define CAltAbilityData__GetMaxRank_x                              0x563CD0

//CTargetRing
#define CTargetRing__Cast_x                                        0x630700

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CAAB0
#define CharacterBase__CreateItemGlobalIndex_x                     0x51A7C0
#define CharacterBase__CreateItemIndex_x                           0x638820
#define CharacterBase__GetItemPossession_x                         0x506230
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CFD60
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CFDC0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F7490
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F7CC0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F7D70

//messages
#define msg_spell_worn_off_x                                       0x5B3BD0
#define msg_new_text_x                                             0x5A8520
#define __msgTokenTextParam_x                                      0x5B5E70
#define msgTokenText_x                                             0x5B60C0

//SpellManager
#define SpellManager__vftable_x                                    0xADB53C
#define SpellManager__SpellManager_x                               0x6A0AA0
#define Spellmanager__LoadTextSpells_x                             0x6A1390
#define SpellManager__GetSpellByGroupAndRank_x                     0x6A0C70

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98E4A0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x51AEA0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5BA0E0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x651450
#define ItemGlobalIndex__IsValidIndex_x                            0x51AF30

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C8070
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C8200

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x765DD0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x714BC0
#define CCursorAttachment__AttachToCursor1_x                       0x714C00
#define CCursorAttachment__Deactivate_x                            0x715BF0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x938DB0
#define CSidlManagerBase__CreatePageWnd_x                          0x9385A0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x934820
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9347B0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x955F30
#define CEQSuiteTextureLoader__GetTexture_x                        0x955BF0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x517A80
#define CFindItemWnd__WndNotification_x                            0x5186C0
#define CFindItemWnd__Update_x                                     0x519230
#define CFindItemWnd__PickupSelectedItem_x                         0x5172A0

//IString
#define IString__Append_x                                          0x507AE0

//Camera
#define CDisplay__cameraType_x                                     0xDEBCC8
#define EverQuest__Cameras_x                                       0xEA70A0

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5207B0
#define LootFiltersManager__GetItemFilterData_x                    0x5200C0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5200F0
#define LootFiltersManager__SetItemLootFilter_x                    0x520310

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BD4F0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x994150
#define CResolutionHandler__GetWindowedStyle_x                     0x698130

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70D180

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D3B40
#define CDistillerInfo__Instance_x                                 0x8D3AE0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72C000
#define CGroupWnd__UpdateDisplay_x                                 0x72B350

//ItemBase
#define ItemBase__IsLore_x                                         0x89D750
#define ItemBase__IsLoreEquipped_x                                 0x89D7D0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EF670
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EF7B0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EF810

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68D710
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x691080

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50E130

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4FA360
#define FactionManagerClient__HandleFactionMessage_x               0x4FA9D0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FAF90
#define FactionManagerClient__GetMaxFaction_x                      0x4FAFAF
#define FactionManagerClient__GetMinFaction_x                      0x4FAF60

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x506200

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91D570

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C2F0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x5064E0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56DE60

//CTargetManager
#define CTargetManager__Get_x                                      0x6A42F0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68D710

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A91D0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C2560

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF44734

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6C0D70
#define CAAWnd__UpdateSelected_x                                   0x6BD5E0
#define CAAWnd__Update_x                                           0x6C0090

//CXRect
#define CXRect__operator_and_x                                     0x7230F0

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x4833B0

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
