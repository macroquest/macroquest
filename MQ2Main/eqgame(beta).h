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
#define __ExpectedVersionDate                                     "Nov 21 2020"
#define __ExpectedVersionTime                                     "04:18:16"
#define __ActualVersionDate_x                                      0xAF653C
#define __ActualVersionTime_x                                      0xAF6530
#define __ActualVersionBuild_x                                     0xAE455C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x6441F0
#define __MemChecker1_x                                            0x8F7C10
#define __MemChecker2_x                                            0x6B4B00
#define __MemChecker3_x                                            0x6B4A50
#define __MemChecker4_x                                            0x84DD00
#define __EncryptPad0_x                                            0xC2C9C8
#define __EncryptPad1_x                                            0xC8A210
#define __EncryptPad2_x                                            0xC3CD90
#define __EncryptPad3_x                                            0xC3C990
#define __EncryptPad4_x                                            0xC7A7A0
#define __EncryptPad5_x                                            0xF4D0E0
#define __AC1_x                                                    0x80C676
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
#define __do_loot_x                                                0x5C9440
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
#define __ScreenMode_x                                             0xDEC4A4
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
#define __LoginName_x                                              0xF4A8C4
#define __Inviter_x                                                0xF446AC
#define __AttackOnAssist_x                                         0xEA6D5C
#define __UseTellWindows_x                                         0xEA7094
#define __gfMaxZoomCameraDistance_x                                0xAEE158
#define __gfMaxCameraDistance_x                                    0xB16DD0
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
#define pinstCamActor_x                                            0xDEC498
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
#define pinstLocalPlayer_x                                         0xE9E824
#define pinstMercenaryData_x                                       0xF46D08
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
#define pinstViewActor_x                                           0xDEC494
#define pinstWorldData_x                                           0xE9E3A8
#define pinstZoneAddr_x                                            0xEA5EF8
#define pinstPlayerPath_x                                          0xF479A8
#define pinstTargetIndicator_x                                     0xF49310
#define EQObject_Top_x                                             0xE9E820
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDEBF38
#define pinstCAchievementsWnd_x                                    0xDEC44C
#define pinstCActionsWnd_x                                         0xDEBF74
#define pinstCAdvancedDisplayOptionsWindow_x                       0xDEC50C
#define pinstCAdvancedLootWnd_x                                    0xDEC4C0
#define pinstCAdventureLeaderboardWnd_x                            0xF56920
#define pinstCAdventureRequestWnd_x                                0xF569D0
#define pinstCAdventureStatsWnd_x                                  0xF56A80
#define pinstCAggroMeterWnd_x                                      0xDEC4F4
#define pinstCAlarmWnd_x                                           0xDEC478
#define pinstCAlertHistoryWnd_x                                    0xDEBEEC
#define pinstCAlertStackWnd_x                                      0xDEC4DC
#define pinstCAlertWnd_x                                           0xDEC4F0
#define pinstCAltStorageWnd_x                                      0xF56DE0
#define pinstCAudioTriggersWindow_x                                0xCA0778
#define pinstCAuraWnd_x                                            0xDEC4C4
#define pinstCAvaZoneWnd_x                                         0xDEBEE8
#define pinstCBandolierWnd_x                                       0xDEC508
#define pinstCBankWnd_x                                            0xDEBCAC
#define pinstCBarterMerchantWnd_x                                  0xF58020
#define pinstCBarterSearchWnd_x                                    0xF580D0
#define pinstCBarterWnd_x                                          0xF58180
#define pinstCBazaarConfirmationWnd_x                              0xDEC48C
#define pinstCBazaarSearchWnd_x                                    0xDEBF3C
#define pinstCBazaarWnd_x                                          0xDEC458
#define pinstCBlockedBuffWnd_x                                     0xDEC4D0
#define pinstCBlockedPetBuffWnd_x                                  0xDEC4F8
#define pinstCBodyTintWnd_x                                        0xDEC400
#define pinstCBookWnd_x                                            0xDEC540
#define pinstCBreathWnd_x                                          0xDEBF4C
#define pinstCBuffWindowNORMAL_x                                   0xDEC4B8
#define pinstCBuffWindowSHORT_x                                    0xDEC4BC
#define pinstCBugReportWnd_x                                       0xDEBCA8
#define pinstCButtonWnd_x                                          0x15DB570
#define pinstCCastingWnd_x                                         0xDEC534
#define pinstCCastSpellWnd_x                                       0xDEBF48
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDEC40C
#define pinstCChatWindowManager_x                                  0xF58C40
#define pinstCClaimWnd_x                                           0xF58D98
#define pinstCColorPickerWnd_x                                     0xDEBF04
#define pinstCCombatAbilityWnd_x                                   0xDEC46C
#define pinstCCombatSkillsSelectWnd_x                              0xDEC420
#define pinstCCompassWnd_x                                         0xDEBFEC
#define pinstCConfirmationDialog_x                                 0xF5DC98
#define pinstCContainerMgr_x                                       0xDEC3FC
#define pinstCContextMenuManager_x                                 0x15DB2C0
#define pinstCCursorAttachment_x                                   0xDEC528
#define pinstCDynamicZoneWnd_x                                     0xF59360
#define pinstCEditLabelWnd_x                                       0xDEC4B4
#define pinstCEQMainWnd_x                                          0xF595A8
#define pinstCEventCalendarWnd_x                                   0xDEBF40
#define pinstCExtendedTargetWnd_x                                  0xDEC4D4
#define pinstCPlayerCustomizationWnd_x                             0xDEC424
#define pinstCFactionWnd_x                                         0xDEC444
#define pinstCFellowshipWnd_x                                      0xF597A8
#define pinstCFileSelectionWnd_x                                   0xDEBEFC
#define pinstCFindItemWnd_x                                        0xDEC438
#define pinstCFindLocationWnd_x                                    0xF59900
#define pinstCFriendsWnd_x                                         0xDEC434
#define pinstCGemsGameWnd_x                                        0xDEC440
#define pinstCGiveWnd_x                                            0xDEC480
#define pinstCGroupSearchFiltersWnd_x                              0xDEC510
#define pinstCGroupSearchWnd_x                                     0xF59CF8
#define pinstCGroupWnd_x                                           0xF59DA8
#define pinstCGuildBankWnd_x                                       0xF59E58
#define pinstCGuildCreationWnd_x                                   0xF59F08
#define pinstCGuildMgmtWnd_x                                       0xF59FB8
#define pinstCharacterCreation_x                                   0xDEC42C
#define pinstCHelpWnd_x                                            0xDEC47C
#define pinstCHeritageSelectionWnd_x                               0xDEC430
#define pinstCHotButtonWnd_x                                       0xF5C110
#define pinstCHotButtonWnd1_x                                      0xF5C110
#define pinstCHotButtonWnd2_x                                      0xF5C114
#define pinstCHotButtonWnd3_x                                      0xF5C118
#define pinstCHotButtonWnd4_x                                      0xF5C11C
#define pinstCIconSelectionWnd_x                                   0xDEC518
#define pinstCInspectWnd_x                                         0xDEC4FC
#define pinstCInventoryWnd_x                                       0xDEC4C8
#define pinstCInvSlotMgr_x                                         0xDEBF2C
#define pinstCItemDisplayManager_x                                 0xF5C6A0
#define pinstCItemExpTransferWnd_x                                 0xF5C7D0
#define pinstCItemOverflowWnd_x                                    0xDEBF44
#define pinstCJournalCatWnd_x                                      0xDEBF18
#define pinstCJournalNPCWnd_x                                      0xDEBED8
#define pinstCJournalTextWnd_x                                     0xDEBED8
#define pinstCKeyRingWnd_x                                         0xDEC530
#define pinstCLargeDialogWnd_x                                     0xF5E918
#define pinstCLayoutCopyWnd_x                                      0xF5CB20
#define pinstCLFGuildWnd_x                                         0xF5CBD0
#define pinstCLoadskinWnd_x                                        0xDEC45C
#define pinstCLootFiltersCopyWnd_x                                 0xCBCEE8
#define pinstCLootFiltersWnd_x                                     0xDEC4E0
#define pinstCLootSettingsWnd_x                                    0xDEC504
#define pinstCLootWnd_x                                            0xDEBF1C
#define pinstCMailAddressBookWnd_x                                 0xDEBF30
#define pinstCMailCompositionWnd_x                                 0xDEBF08
#define pinstCMailIgnoreListWnd_x                                  0xDEBF34
#define pinstCMailWnd_x                                            0xDEBEF4
#define pinstCManageLootWnd_x                                      0xDED3A0
#define pinstCMapToolbarWnd_x                                      0xDEC488
#define pinstCMapViewWnd_x                                         0xDEC450
#define pinstCMarketplaceWnd_x                                     0xDEC4E4
#define pinstCMerchantWnd_x                                        0xDEBF28
#define pinstCMIZoneSelectWnd_x                                    0xF5D408
#define pinstCMusicPlayerWnd_x                                     0xDEBEC8
#define pinstCNameChangeMercWnd_x                                  0xDEC484
#define pinstCNameChangePetWnd_x                                   0xDEC454
#define pinstCNameChangeWnd_x                                      0xDEC4AC
#define pinstCNoteWnd_x                                            0xDEC460
#define pinstCObjectPreviewWnd_x                                   0xDEC500
#define pinstCOptionsWnd_x                                         0xDEC470
#define pinstCPetInfoWnd_x                                         0xDEBEF0
#define pinstCPetitionQWnd_x                                       0xDEC41C
#define pinstCPlayerNotesWnd_x                                     0xDEC404
#define pinstCPlayerWnd_x                                          0xDEBEE4
#define pinstCPopupWndManager_x                                    0xF5DC98
#define pinstCProgressionSelectionWnd_x                            0xF5DD48
#define pinstCPurchaseGroupWnd_x                                   0xDEBCBC
#define pinstCPurchaseWnd_x                                        0xDEC538
#define pinstCPvPLeaderboardWnd_x                                  0xF5DDF8
#define pinstCPvPStatsWnd_x                                        0xF5DEA8
#define pinstCQuantityWnd_x                                        0xDEBED4
#define pinstCRaceChangeWnd_x                                      0xDEC4CC
#define pinstCRaidOptionsWnd_x                                     0xDEC514
#define pinstCRaidWnd_x                                            0xDEBF24
#define pinstCRealEstateItemsWnd_x                                 0xDEC448
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDEBFF4
#define pinstCRealEstateManageWnd_x                                0xDEBCC4
#define pinstCRealEstateNeighborhoodWnd_x                          0xDEBEE0
#define pinstCRealEstatePlotSearchWnd_x                            0xDEBEF8
#define pinstCRealEstatePurchaseWnd_x                              0xDEBF14
#define pinstCRespawnWnd_x                                         0xDEC4EC
#define pinstCRewardSelectionWnd_x                                 0xF5E5F0
#define pinstCSelectorWnd_x                                        0xDEC418
#define pinstCSendMoneyWnd_x                                       0xDEC490
#define pinstCServerListWnd_x                                      0xDEBF20
#define pinstCSkillsSelectWnd_x                                    0xDEC414
#define pinstCSkillsWnd_x                                          0xDEBFF0
#define pinstCSocialEditWnd_x                                      0xDEC52C
#define pinstCSocialWnd_x                                          0xDEC474
#define pinstCSpellBookWnd_x                                       0xDEC464
#define pinstCStoryWnd_x                                           0xDEBF70
#define pinstCTargetOfTargetWnd_x                                  0xF5FC50
#define pinstCTargetWnd_x                                          0xDEC4E8
#define pinstCTaskOverlayWnd_x                                     0xDEBCB4
#define pinstCTaskSelectWnd_x                                      0xF5FDA8
#define pinstCTaskManager_x                                        0xCBD828
#define pinstCTaskTemplateSelectWnd_x                              0xF5FE58
#define pinstCTaskWnd_x                                            0xF5FF08
#define pinstCTextEntryWnd_x                                       0xDEC53C
#define pinstCTimeLeftWnd_x                                        0xDEC410
#define pinstCTipWndCONTEXT_x                                      0xF6010C
#define pinstCTipWndOFDAY_x                                        0xF60108
#define pinstCTitleWnd_x                                           0xF601B8
#define pinstCTrackingWnd_x                                        0xDEC4D8
#define pinstCTradeskillWnd_x                                      0xF60320
#define pinstCTradeWnd_x                                           0xDEC408
#define pinstCTrainWnd_x                                           0xDEBF10
#define pinstCTributeBenefitWnd_x                                  0xF60520
#define pinstCTributeMasterWnd_x                                   0xF605D0
#define pinstCTributeTrophyWnd_x                                   0xF60680
#define pinstCVideoModesWnd_x                                      0xDEBCB0
#define pinstCVoiceMacroWnd_x                                      0xF498C8
#define pinstCVoteResultsWnd_x                                     0xDEC43C
#define pinstCVoteWnd_x                                            0xDEC428
#define pinstCWebManager_x                                         0xF49F44
#define pinstCZoneGuideWnd_x                                       0xDEBCB8
#define pinstCZonePathWnd_x                                        0xDEBED0

#define pinstEQSuiteTextureLoader_x                                0xC8AB30
#define pinstItemIconCache_x                                       0xF59560
#define pinstLootFiltersManager_x                                  0xCBCF98
#define pinstRewardSelectionWnd_x                                  0xF5E5F0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C4B30
#define __CastRay2_x                                               0x5C4B80
#define __ConvertItemTags_x                                        0x5E0840
#define __CleanItemTags_x                                          0x47D240
#define __DoesFileExist_x                                          0x8FAC40
#define __EQGetTime_x                                              0x8F7840
#define __ExecuteCmd_x                                             0x5BD4A0
#define __FixHeading_x                                             0x98CD60
#define __FlushDxKeyboard_x                                        0x6B09A0
#define __GameLoop_x                                               0x6B3CD0
#define __get_bearing_x                                            0x5C4690
#define __get_melee_range_x                                        0x5C4D70
#define __GetAnimationCache_x                                      0x719150
#define __GetGaugeValueFromEQ_x                                    0x80AB20
#define __GetLabelFromEQ_x                                         0x80C600
#define __GetXTargetType_x                                         0x98E7B0
#define __HandleMouseWheel_x                                       0x6B4BB0
#define __HeadingDiff_x                                            0x98CDD0
#define __HelpPath_x                                               0xF44E04
#define __LoadFrontEnd_x                                           0x6B0FE0
#define __NewUIINI_x                                               0x80A7F0
#define __ProcessGameEvents_x                                      0x625600
#define __ProcessMouseEvent_x                                      0x624D90
#define __SaveColors_x                                             0x55CF60
#define __STMLToText_x                                             0x9300D0
#define __ToggleKeyRingItem_x                                      0x51B9D0
#define CMemoryMappedFile__SetFile_x                               0xA7BF40
#define CrashDetected_x                                            0x6B2A90
#define DrawNetStatus_x                                            0x651550
#define Expansion_HoT_x                                            0xEA6D48
#define Teleport_Table_Size_x                                      0xE9E7E0
#define Teleport_Table_x                                           0xE9ECB0
#define Util__FastTime_x                                           0x8F7410
#define __CopyLayout_x                                             0x63F8C0
#define __WndProc_x                                                0x6B2F90
#define __ProcessKeyboardEvent_x                                   0x6B2530

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490570
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499560
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499330
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493B00
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492F50

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5650A0
#define AltAdvManager__IsAbilityReady_x                            0x563E40
#define AltAdvManager__GetAAById_x                                 0x5641D0
#define AltAdvManager__CanTrainAbility_x                           0x564240
#define AltAdvManager__CanSeeAbility_x                             0x5645A0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB320
#define CharacterZoneClient__HasSkill_x                            0x4D61A0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D78C0
#define CharacterZoneClient__IsStackBlocked_x                      0x4C28D0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBD60
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA230
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA310
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA3F0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C49C0
#define CharacterZoneClient__BardCastBard_x                        0x4C73F0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF770
#define CharacterZoneClient__GetEffect_x                           0x4BBCA0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5A30
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5B00
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5B50
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5CA0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5E80
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3C90
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8820
#define CharacterZoneClient__FindItemByRecord_x                    0x4D82A0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DA7D0
#define CBankWnd__WndNotification_x                                0x6DA5A0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E8020

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92D8B0
#define CButtonWnd__CButtonWnd_x                                   0x92C480

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x708370
#define CChatManager__InitContextMenu_x                            0x7014A0
#define CChatManager__FreeChatWindow_x                             0x706EB0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9BE0
#define CChatManager__SetLockedActiveChatWindow_x                  0x707FF0
#define CChatManager__CreateChatWindow_x                           0x7074F0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9CF0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x940A80
#define CContextMenu__dCContextMenu_x                              0x940CC0
#define CContextMenu__AddMenuItem_x                                0x940CD0
#define CContextMenu__RemoveMenuItem_x                             0x940FE0
#define CContextMenu__RemoveAllMenuItems_x                         0x941000
#define CContextMenu__CheckMenuItem_x                              0x941080
#define CContextMenu__SetMenuItem_x                                0x940F00
#define CContextMenu__AddSeparator_x                               0x940E60

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x941620
#define CContextMenuManager__RemoveMenu_x                          0x941690
#define CContextMenuManager__PopupMenu_x                           0x941750
#define CContextMenuManager__Flush_x                               0x9415C0
#define CContextMenuManager__GetMenu_x                             0x49B8D0
#define CContextMenuManager__CreateDefaultMenu_x                   0x713AB0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D2610
#define CChatService__GetFriendName_x                              0x8D2620

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x708BA0
#define CChatWindow__Clear_x                                       0x709E60
#define CChatWindow__WndNotification_x                             0x70A5F0
#define CChatWindow__AddHistory_x                                  0x709720

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93DEE0
#define CComboWnd__Draw_x                                          0x93D3E0
#define CComboWnd__GetCurChoice_x                                  0x93DD20
#define CComboWnd__GetListRect_x                                   0x93D890
#define CComboWnd__GetTextRect_x                                   0x93DF50
#define CComboWnd__InsertChoice_x                                  0x93DA20
#define CComboWnd__SetColors_x                                     0x93D9F0
#define CComboWnd__SetChoice_x                                     0x93DCF0
#define CComboWnd__GetItemCount_x                                  0x93DD30
#define CComboWnd__GetCurChoiceText_x                              0x93DD70
#define CComboWnd__GetChoiceText_x                                 0x93DD40
#define CComboWnd__InsertChoiceAtIndex_x                           0x93DAB0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7114C0
#define CContainerWnd__vftable_x                                   0xAFF73C
#define CContainerWnd__SetContainer_x                              0x712A10

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x5578C0
#define CDisplay__PreZoneMainUI_x                                  0x5578D0
#define CDisplay__CleanGameUI_x                                    0x55CD20
#define CDisplay__GetClickedActor_x                                0x54FD20
#define CDisplay__GetUserDefinedColor_x                            0x548390
#define CDisplay__GetWorldFilePath_x                               0x551790
#define CDisplay__is3dON_x                                         0x54C980
#define CDisplay__ReloadUI_x                                       0x556DD0
#define CDisplay__WriteTextHD2_x                                   0x54C770
#define CDisplay__TrueDistance_x                                   0x553450
#define CDisplay__SetViewActor_x                                   0x54F640
#define CDisplay__GetFloorHeight_x                                 0x54CA40
#define CDisplay__SetRenderWindow_x                                0x54B3C0
#define CDisplay__ToggleScreenshotMode_x                           0x54F110

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x960A40

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x943F80
#define CEditWnd__EnsureCaretVisible_x                             0x946150
#define CEditWnd__GetCaretPt_x                                     0x945100
#define CEditWnd__GetCharIndexPt_x                                 0x944EB0
#define CEditWnd__GetDisplayString_x                               0x944D50
#define CEditWnd__GetHorzOffset_x                                  0x943630
#define CEditWnd__GetLineForPrintableChar_x                        0x946050
#define CEditWnd__GetSelStartPt_x                                  0x945160
#define CEditWnd__GetSTMLSafeText_x                                0x944B70
#define CEditWnd__PointFromPrintableChar_x                         0x945C80
#define CEditWnd__SelectableCharFromPoint_x                        0x945DF0
#define CEditWnd__SetEditable_x                                    0x945230
#define CEditWnd__SetWindowTextA_x                                 0x9448F0
#define CEditWnd__ReplaceSelection_x                               0x9458F0
#define CEditWnd__ReplaceSelection1_x                              0x945870

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x612C00
#define CEverQuest__ClickedPlayer_x                                0x604DA0
#define CEverQuest__CreateTargetIndicator_x                        0x622770
#define CEverQuest__DeleteTargetIndicator_x                        0x622800
#define CEverQuest__DoTellWindow_x                                 0x4E9DD0
#define CEverQuest__OutputTextToLog_x                              0x4EA0A0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F9F00
#define CEverQuest__dsp_chat_x                                     0x4EA430
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
#define CGaugeWnd__CalcFillRect_x                                  0x723270
#define CGaugeWnd__CalcLinesFillRect_x                             0x7232D0
#define CGaugeWnd__Draw_x                                          0x7228F0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFEF0
#define CGuild__GetGuildName_x                                     0x4AE9A0
#define CGuild__GetGuildIndex_x                                    0x4AEFA0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73CEE0

//CHotButton
#define CHotButton__SetCheck_x                                     0x633DF0
#define CHotButton__SetButtonSize_x                                0x6341B0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x749FC0
#define CInvSlotMgr__MoveItem_x                                    0x748C90
#define CInvSlotMgr__SelectSlot_x                                  0x74A090

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7474C0
#define CInvSlot__SliderComplete_x                                 0x745210
#define CInvSlot__GetItemBase_x                                    0x744B90
#define CInvSlot__UpdateItem_x                                     0x744D00

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74BB10
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74ACB0
#define CInvSlotWnd__HandleLButtonUp_x                             0x74B690

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x805EB0
#define CItemDisplayWnd__UpdateStrings_x                           0x75A210
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x753EA0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7543D0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x75A810
#define CItemDisplayWnd__AboutToShow_x                             0x759E50
#define CItemDisplayWnd__WndNotification_x                         0x75BA80
#define CItemDisplayWnd__RequestConvertItem_x                      0x75B3C0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x758EC0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x759C70

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x836B10

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75FF80

// CLabel 
#define CLabel__Draw_x                                             0x765A40

// CListWnd
#define CListWnd__CListWnd_x                                       0x916640
#define CListWnd__dCListWnd_x                                      0x916960
#define CListWnd__AddColumn_x                                      0x91AD90
#define CListWnd__AddColumn1_x                                     0x91ADE0
#define CListWnd__AddLine_x                                        0x91B170
#define CListWnd__AddString_x                                      0x91AF70
#define CListWnd__CalculateFirstVisibleLine_x                      0x91AB50
#define CListWnd__CalculateVSBRange_x                              0x91A950
#define CListWnd__ClearSel_x                                       0x91B950
#define CListWnd__ClearAllSel_x                                    0x91B9B0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91C3C0
#define CListWnd__Compare_x                                        0x91A290
#define CListWnd__Draw_x                                           0x916A90
#define CListWnd__DrawColumnSeparators_x                           0x919270
#define CListWnd__DrawHeader_x                                     0x9196D0
#define CListWnd__DrawItem_x                                       0x919BD0
#define CListWnd__DrawLine_x                                       0x9193D0
#define CListWnd__DrawSeparator_x                                  0x919310
#define CListWnd__EnableLine_x                                     0x918B50
#define CListWnd__EnsureVisible_x                                  0x91C2E0
#define CListWnd__ExtendSel_x                                      0x91B880
#define CListWnd__GetColumnTooltip_x                               0x918690
#define CListWnd__GetColumnMinWidth_x                              0x918700
#define CListWnd__GetColumnWidth_x                                 0x918600
#define CListWnd__GetCurSel_x                                      0x917F90
#define CListWnd__GetItemAtPoint_x                                 0x918DC0
#define CListWnd__GetItemAtPoint1_x                                0x918E30
#define CListWnd__GetItemData_x                                    0x918010
#define CListWnd__GetItemHeight_x                                  0x9183D0
#define CListWnd__GetItemIcon_x                                    0x9181A0
#define CListWnd__GetItemRect_x                                    0x918C40
#define CListWnd__GetItemText_x                                    0x918050
#define CListWnd__GetSelList_x                                     0x91BA00
#define CListWnd__GetSeparatorRect_x                               0x919070
#define CListWnd__InsertLine_x                                     0x91B560
#define CListWnd__RemoveLine_x                                     0x91B6B0
#define CListWnd__SetColors_x                                      0x91A930
#define CListWnd__SetColumnJustification_x                         0x91A660
#define CListWnd__SetColumnLabel_x                                 0x91AF10
#define CListWnd__SetColumnWidth_x                                 0x91A580
#define CListWnd__SetCurSel_x                                      0x91B7C0
#define CListWnd__SetItemColor_x                                   0x91BF90
#define CListWnd__SetItemData_x                                    0x91BF50
#define CListWnd__SetItemText_x                                    0x91BB70
#define CListWnd__ShiftColumnSeparator_x                           0x91A720
#define CListWnd__Sort_x                                           0x91A410
#define CListWnd__ToggleSel_x                                      0x91B7F0
#define CListWnd__SetColumnsSizable_x                              0x91A7D0
#define CListWnd__SetItemWnd_x                                     0x91BE20
#define CListWnd__GetItemWnd_x                                     0x9181F0
#define CListWnd__SetItemIcon_x                                    0x91BBF0
#define CListWnd__CalculateCustomWindowPositions_x                 0x91AC50
#define CListWnd__SetVScrollPos_x                                  0x91A560

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77B210
#define CMapViewWnd__GetWorldCoordinates_x                         0x779920
#define CMapViewWnd__HandleLButtonDown_x                           0x776960

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79B5B0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79BE90
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79C3C0
#define CMerchantWnd__SelectRecoverySlot_x                         0x79F370
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x79A130
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A4F30
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79B1D0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89FED0
#define CPacketScrambler__hton_x                                   0x89FEC0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9356B0
#define CSidlManager__FindScreenPieceTemplate_x                    0x935AC0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9358B0
#define CSidlManager__CreateLabel_x                                0x7FD100
#define CSidlManager__CreateXWndFromTemplate_x                     0x938A20
#define CSidlManager__CreateXWndFromTemplate1_x                    0x938BF0
#define CSidlManager__CreateXWnd_x                                 0x7FD030
#define CSidlManager__CreateHotButtonWnd_x                         0x7FD600

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9321A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9320A0
#define CSidlScreenWnd__ConvertToRes_x                             0x95B590
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x931B90
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x931880
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x931950
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x931A20
#define CSidlScreenWnd__DrawSidlPiece_x                            0x932630
#define CSidlScreenWnd__EnableIniStorage_x                         0x932B00
#define CSidlScreenWnd__GetSidlPiece_x                             0x932820
#define CSidlScreenWnd__Init1_x                                    0x931480
#define CSidlScreenWnd__LoadIniInfo_x                              0x932B50
#define CSidlScreenWnd__LoadIniListWnd_x                           0x933690
#define CSidlScreenWnd__LoadSidlScreen_x                           0x930880
#define CSidlScreenWnd__StoreIniInfo_x                             0x933210
#define CSidlScreenWnd__StoreIniVis_x                              0x933570
#define CSidlScreenWnd__WndNotification_x                          0x932540
#define CSidlScreenWnd__GetChildItem_x                             0x932A80
#define CSidlScreenWnd__HandleLButtonUp_x                          0x922220
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DB190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x699950
#define CSkillMgr__GetSkillCap_x                                   0x699B30
#define CSkillMgr__GetNameToken_x                                  0x6990D0
#define CSkillMgr__IsActivatedSkill_x                              0x699210
#define CSkillMgr__IsCombatSkill_x                                 0x699150

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x942400
#define CSliderWnd__SetValue_x                                     0x942270
#define CSliderWnd__SetNumTicks_x                                  0x9422D0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x803260

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x94AD50
#define CStmlWnd__ParseSTML_x                                      0x94C090
#define CStmlWnd__CalculateHSBRange_x                              0x94BE70
#define CStmlWnd__CalculateVSBRange_x                              0x94BDE0
#define CStmlWnd__CanBreakAtCharacter_x                            0x9501A0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x950E30
#define CStmlWnd__ForceParseNow_x                                  0x94B340
#define CStmlWnd__GetNextTagPiece_x                                0x950100
#define CStmlWnd__GetSTMLText_x                                    0x50D1C0
#define CStmlWnd__GetVisibleText_x                                 0x94B360
#define CStmlWnd__InitializeWindowVariables_x                      0x950C80
#define CStmlWnd__MakeStmlColorTag_x                               0x94A3C0
#define CStmlWnd__MakeWndNotificationTag_x                         0x94A430
#define CStmlWnd__SetSTMLText_x                                    0x949470
#define CStmlWnd__StripFirstSTMLLines_x                            0x951F00
#define CStmlWnd__UpdateHistoryString_x                            0x951040

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9485C0
#define CTabWnd__DrawCurrentPage_x                                 0x948CF0
#define CTabWnd__DrawTab_x                                         0x948A10
#define CTabWnd__GetCurrentPage_x                                  0x947DC0
#define CTabWnd__GetPageInnerRect_x                                0x948000
#define CTabWnd__GetTabInnerRect_x                                 0x947F40
#define CTabWnd__GetTabRect_x                                      0x947DF0
#define CTabWnd__InsertPage_x                                      0x948210
#define CTabWnd__RemovePage_x                                      0x948380
#define CTabWnd__SetPage_x                                         0x948080
#define CTabWnd__SetPageRect_x                                     0x948500
#define CTabWnd__UpdatePage_x                                      0x9488D0
#define CTabWnd__GetPageFromTabIndex_x                             0x948950
#define CTabWnd__GetCurrentTabIndex_x                              0x947DB0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7603B0
#define CPageWnd__SetTabText_x                                     0x947900
#define CPageWnd__FlashTab_x                                       0x947960

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9270

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91F0B0
#define CTextureFont__GetTextExtent_x                              0x91F270

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6ADB80
#define CHtmlComponentWnd__ValidateUri_x                           0x73E8F0
#define CHtmlWnd__SetClientCallbacks_x                             0x639220
#define CHtmlWnd__AddObserver_x                                    0x639240
#define CHtmlWnd__RemoveObserver_x                                 0x6392A0
#define Window__getProgress_x                                      0x8552C0
#define Window__getStatus_x                                        0x8552E0
#define Window__getURI_x                                           0x8552F0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9583A0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90C110

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9A20
#define CXStr__CXStr1_x                                            0x4B7500
#define CXStr__CXStr3_x                                            0x8F37C0
#define CXStr__dCXStr_x                                            0x478410
#define CXStr__operator_equal_x                                    0x8F39F0
#define CXStr__operator_equal1_x                                   0x8F3A30
#define CXStr__operator_plus_equal1_x                              0x8F44C0
#define CXStr__SetString_x                                         0x8F63B0
#define CXStr__operator_char_p_x                                   0x8F3F00
#define CXStr__GetChar_x                                           0x8F5CE0
#define CXStr__Delete_x                                            0x8F55B0
#define CXStr__GetUnicode_x                                        0x8F5D50
#define CXStr__GetLength_x                                         0x4A9020
#define CXStr__Mid_x                                               0x47D5F0
#define CXStr__Insert_x                                            0x8F5DB0
#define CXStr__FindNext_x                                          0x8F5A20

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9406A0
#define CXWnd__BringToTop_x                                        0x9259D0
#define CXWnd__Center_x                                            0x925550
#define CXWnd__ClrFocus_x                                          0x925360
#define CXWnd__Destroy_x                                           0x925410
#define CXWnd__DoAllDrawing_x                                      0x9219B0
#define CXWnd__DrawChildren_x                                      0x921980
#define CXWnd__DrawColoredRect_x                                   0x921E10
#define CXWnd__DrawTooltip_x                                       0x9204B0
#define CXWnd__DrawTooltipAtPoint_x                                0x920570
#define CXWnd__GetBorderFrame_x                                    0x921C70
#define CXWnd__GetChildWndAt_x                                     0x925A70
#define CXWnd__GetClientClipRect_x                                 0x923C70
#define CXWnd__GetScreenClipRect_x                                 0x923D40
#define CXWnd__GetScreenRect_x                                     0x923F00
#define CXWnd__GetRelativeRect_x                                   0x923FC0
#define CXWnd__GetTooltipRect_x                                    0x921E60
#define CXWnd__GetWindowTextA_x                                    0x49D000
#define CXWnd__IsActive_x                                          0x9225A0
#define CXWnd__IsDescendantOf_x                                    0x924900
#define CXWnd__IsReallyVisible_x                                   0x924930
#define CXWnd__IsType_x                                            0x9260D0
#define CXWnd__Move_x                                              0x9249A0
#define CXWnd__Move1_x                                             0x924A60
#define CXWnd__ProcessTransition_x                                 0x925500
#define CXWnd__Refade_x                                            0x924D30
#define CXWnd__Resize_x                                            0x924FC0
#define CXWnd__Right_x                                             0x925790
#define CXWnd__SetFocus_x                                          0x925320
#define CXWnd__SetFont_x                                           0x925390
#define CXWnd__SetKeyTooltip_x                                     0x925EF0
#define CXWnd__SetMouseOver_x                                      0x922DC0
#define CXWnd__StartFade_x                                         0x9247F0
#define CXWnd__GetChildItem_x                                      0x925BE0
#define CXWnd__SetParent_x                                         0x9246A0
#define CXWnd__Minimize_x                                          0x925020

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95C610

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x928910
#define CXWndManager__DrawWindows_x                                0x928930
#define CXWndManager__GetKeyboardFlags_x                           0x92B120
#define CXWndManager__HandleKeyboardMsg_x                          0x92ACD0
#define CXWndManager__RemoveWnd_x                                  0x92B340
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92B8A0

// CDBStr
#define CDBStr__GetString_x                                        0x547360

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFED0
#define EQ_Character__Cur_HP_x                                     0x4D31E0
#define EQ_Character__Cur_Mana_x                                   0x4DA8F0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2F40
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B38D0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3A20
#define EQ_Character__GetHPRegen_x                                 0x4E07C0
#define EQ_Character__GetEnduranceRegen_x                          0x4E0DC0
#define EQ_Character__GetManaRegen_x                               0x4E1200
#define EQ_Character__Max_Endurance_x                              0x65FD80
#define EQ_Character__Max_HP_x                                     0x4D3010
#define EQ_Character__Max_Mana_x                                   0x65FB80
#define EQ_Character__doCombatAbility_x                            0x662170
#define EQ_Character__UseSkill_x                                   0x4E3000
#define EQ_Character__GetConLevel_x                                0x6584D0
#define EQ_Character__IsExpansionFlag_x                            0x5BBC80
#define EQ_Character__TotalEffect_x                                0x4C6CE0
#define EQ_Character__GetPCSpellAffect_x                           0x4C3C90
#define EQ_Character__SpellDuration_x                              0x4C37C0
#define EQ_Character__MySpellDuration_x                            0x4B2200
#define EQ_Character__GetAdjustedSkill_x                           0x4D5F60
#define EQ_Character__GetBaseSkill_x                               0x4D6F00
#define EQ_Character__CanUseItem_x                                 0x4DAC00

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BF5A0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6760C0

//PcClient
#define PcClient__vftable_x                                        0xAF31B8
#define PcClient__PcClient_x                                       0x655C30

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA8F0
#define CCharacterListWnd__EnterWorld_x                            0x4BA2C0
#define CCharacterListWnd__Quit_x                                  0x4BA010
#define CCharacterListWnd__UpdateList_x                            0x4BA4B0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x63A400
#define EQ_Item__CreateItemTagString_x                             0x899490
#define EQ_Item__IsStackable_x                                     0x89E120
#define EQ_Item__GetImageNum_x                                     0x89AFD0
#define EQ_Item__CreateItemClient_x                                0x639640
#define EQ_Item__GetItemValue_x                                    0x89C2F0
#define EQ_Item__ValueSellMerchant_x                               0x89FAB0
#define EQ_Item__IsKeyRingItem_x                                   0x89DA40
#define EQ_Item__CanGoInBag_x                                      0x63A520
#define EQ_Item__IsEmpty_x                                         0x89D580
#define EQ_Item__GetMaxItemCount_x                                 0x89C700
#define EQ_Item__GetHeldItem_x                                     0x89AEA0
#define EQ_Item__GetAugmentFitBySlot_x                             0x898D00

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x565D70
#define EQ_LoadingS__Array_x                                       0xC14130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x660680
#define EQ_PC__GetAlternateAbilityId_x                             0x8A8F50
#define EQ_PC__GetCombatAbility_x                                  0x8A95C0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A9630
#define EQ_PC__GetItemRecastTimer_x                                0x6626F0
#define EQ_PC__HasLoreItem_x                                       0x658CF0
#define EQ_PC__AlertInventoryChanged_x                             0x657E00
#define EQ_PC__GetPcZoneClient_x                                   0x6850E0
#define EQ_PC__RemoveMyAffect_x                                    0x665920
#define EQ_PC__GetKeyRingItems_x                                   0x8A9F00
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A9C80
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8AA200

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C20A0
#define EQItemList__add_object_x                                   0x5EF6E0
#define EQItemList__add_item_x                                     0x5C2600
#define EQItemList__delete_item_x                                  0x5C2650
#define EQItemList__FreeItemList_x                                 0x5C2550

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x543EE0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6779C0
#define EQPlayer__dEQPlayer_x                                      0x66AD30
#define EQPlayer__DoAttack_x                                       0x67F880
#define EQPlayer__EQPlayer_x                                       0x66B3F0
#define EQPlayer__SetNameSpriteState_x                             0x66F6D0
#define EQPlayer__SetNameSpriteTint_x                              0x6705B0
#define PlayerBase__HasProperty_j_x                                0x98B170
#define EQPlayer__IsTargetable_x                                   0x98B610
#define EQPlayer__CanSee_x                                         0x98B470
#define EQPlayer__CanSee1_x                                        0x98B540
#define PlayerBase__GetVisibilityLineSegment_x                     0x98B230

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x682B80
#define PlayerZoneClient__GetLevel_x                               0x685120
#define PlayerZoneClient__IsValidTeleport_x                        0x5F0850
#define PlayerZoneClient__LegalPlayerRace_x                        0x55EBB0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x67A7A0
#define EQPlayerManager__GetSpawnByName_x                          0x67A850
#define EQPlayerManager__GetPlayerFromPartialName_x                0x67A8E0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63DB20
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63DBA0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63DBE0
#define KeypressHandler__ClearCommandStateArray_x                  0x63EFD0
#define KeypressHandler__HandleKeyDown_x                           0x63EFF0
#define KeypressHandler__HandleKeyUp_x                             0x63F090
#define KeypressHandler__SaveKeymapping_x                          0x63F4E0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x777080
#define MapViewMap__SaveEx_x                                       0x77A440
#define MapViewMap__SetZoom_x                                      0x77EB00

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BD600

// StringTable 
#define StringTable__getString_x                                   0x8B8480

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x665590
#define PcZoneClient__RemovePetEffect_x                            0x665BC0
#define PcZoneClient__HasAlternateAbility_x                        0x65F9B0
#define PcZoneClient__GetCurrentMod_x                              0x4E6120
#define PcZoneClient__GetModCap_x                                  0x4E6020
#define PcZoneClient__CanEquipItem_x                               0x660060
#define PcZoneClient__GetItemByID_x                                0x662B60
#define PcZoneClient__GetItemByItemClass_x                         0x662CB0
#define PcZoneClient__RemoveBuffEffect_x                           0x665BE0
#define PcZoneClient__BandolierSwap_x                              0x660C40
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x662690

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F53C0

//IconCache
#define IconCache__GetIcon_x                                       0x718B50

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x710660
#define CContainerMgr__CloseContainer_x                            0x710930
#define CContainerMgr__OpenExperimentContainer_x                   0x7113B0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CF820

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x6325E0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76D4C0
#define CLootWnd__RequestLootSlot_x                                0x76C7A0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58D860
#define EQ_Spell__SpellAffects_x                                   0x58DCD0
#define EQ_Spell__SpellAffectBase_x                                0x58DA90
#define EQ_Spell__IsStackable_x                                    0x4CAC20
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CAA10
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7BC0
#define EQ_Spell__IsSPAStacking_x                                  0x58EB20
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58E030
#define EQ_Spell__IsNoRemove_x                                     0x4CAC00
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58EB30
#define __IsResEffectSpell_x                                       0x4C9D30

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD450

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C7C40

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8165A0
#define CTargetWnd__WndNotification_x                              0x815DE0
#define CTargetWnd__RefreshTargetBuffs_x                           0x8160B0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x814F50

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81AC10
#define CTaskWnd__ConfirmAbandonTask_x                             0x81D850

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5418D0
#define CTaskManager__HandleMessage_x                              0x53FD40
#define CTaskManager__GetTaskStatus_x                              0x541980
#define CTaskManager__GetElementDescription_x                      0x541A00

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5889E0
#define EqSoundManager__PlayScriptMp3_x                            0x588CA0
#define EqSoundManager__SoundAssistPlay_x                          0x69D8B0
#define EqSoundManager__WaveInstancePlay_x                         0x69CE20

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x532CB0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x946E10
#define CTextureAnimation__Draw_x                                  0x947010

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x942D70

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56D8C0
#define CAltAbilityData__GetMercMaxRank_x                          0x56D850
#define CAltAbilityData__GetMaxRank_x                              0x562CC0

//CTargetRing
#define CTargetRing__Cast_x                                        0x630700

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA9F0
#define CharacterBase__CreateItemGlobalIndex_x                     0x519BE0
#define CharacterBase__CreateItemIndex_x                           0x6387D0
#define CharacterBase__GetItemPossession_x                         0x505D90
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D0290
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D02F0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F7590
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F7DC0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F7E70

//messages
#define msg_spell_worn_off_x                                       0x5B3CA0
#define msg_new_text_x                                             0x5A85D0
#define __msgTokenTextParam_x                                      0x5B5F40
#define msgTokenText_x                                             0x5B6190

//SpellManager
#define SpellManager__vftable_x                                    0xADB574
#define SpellManager__SpellManager_x                               0x6A0BD0
#define Spellmanager__LoadTextSpells_x                             0x6A14C0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6A0DA0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98F0A0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x51A230
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5BA190
#define ItemGlobalIndex__IsEquippedLocation_x                      0x6513B0
#define ItemGlobalIndex__IsValidIndex_x                            0x51A2C0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C85E0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C8860

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x765D80

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x714D50
#define CCursorAttachment__AttachToCursor1_x                       0x714D90
#define CCursorAttachment__Deactivate_x                            0x715D80

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x939A50
#define CSidlManagerBase__CreatePageWnd_x                          0x939240
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9354D0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x935460

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x956D30
#define CEQSuiteTextureLoader__GetTexture_x                        0x9569F0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x517160
#define CFindItemWnd__WndNotification_x                            0x517C40
#define CFindItemWnd__Update_x                                     0x5187B0
#define CFindItemWnd__PickupSelectedItem_x                         0x516990

//IString
#define IString__Append_x                                          0x5075E0

//Camera
#define CDisplay__cameraType_x                                     0xDEBCC0
#define EverQuest__Cameras_x                                       0xEA70A0

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51FB30
#define LootFiltersManager__GetItemFilterData_x                    0x51F440
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51F470
#define LootFiltersManager__SetItemLootFilter_x                    0x51F690

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BD5A0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x994C40
#define CResolutionHandler__GetWindowedStyle_x                     0x698390

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70D310

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DDBF0
#define CDistillerInfo__Instance_x                                 0x8DDB90

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72C230
#define CGroupWnd__UpdateDisplay_x                                 0x72B590

//ItemBase
#define ItemBase__IsLore_x                                         0x89DAF0
#define ItemBase__IsLoreEquipped_x                                 0x89DB60

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EF640
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EF780
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EF7E0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68D880
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6911F0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50D7C0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F9A70
#define FactionManagerClient__HandleFactionMessage_x               0x4FA0E0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FA6A0
#define FactionManagerClient__GetMaxFaction_x                      0x4FA6BF
#define FactionManagerClient__GetMinFaction_x                      0x4FA670

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x505D60

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91E060

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C2E0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x505FF0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56CD60

//CTargetManager
#define CTargetManager__Get_x                                      0x6A4410

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68D880

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A9030

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C24F0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF44734

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6C0ED0
#define CAAWnd__UpdateSelected_x                                   0x6BD740
#define CAAWnd__Update_x                                           0x6C01F0

//CXRect
#define CXRect__operator_and_x                                     0x723330

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x483210

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
