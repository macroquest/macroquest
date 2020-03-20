/*
 * MacroQuest2: The extension platform for EverQuest
 * Copyright (C) 2002-2019 MacroQuest Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Mar 18 2020"
#define __ExpectedVersionTime                                     "19:02:11"
#define __ActualVersionDate_x                                      0xB19380
#define __ActualVersionTime_x                                      0xB19374
#define __ActualVersionBuild_x                                     0xB050CC

// Memory Protection
#define __MemChecker0_x                                            0x63C750
#define __MemChecker1_x                                            0x910180
#define __MemChecker2_x                                            0x6CB090
#define __MemChecker3_x                                            0x6CAFE0
#define __MemChecker4_x                                            0x866260
#define __EncryptPad0_x                                            0xC514E8
#define __EncryptPad1_x                                            0xCAF650
#define __EncryptPad2_x                                            0xC61D80
#define __EncryptPad3_x                                            0xC61980
#define __EncryptPad4_x                                            0xC9FC00
#define __EncryptPad5_x                                            0xF707DC
#define __AC1_x                                                    0x823056
#define __AC2_x                                                    0x5F64DF
#define __AC3_x                                                    0x5FDBDF
#define __AC4_x                                                    0x601BB0
#define __AC5_x                                                    0x607EBF
#define __AC6_x                                                    0x60C3B6
#define __AC7_x                                                    0x5F5F50
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x72178

// Direct Input
#define DI8__Main_x                                                0xF707FC
#define DI8__Keyboard_x                                            0xF70800
#define DI8__Mouse_x                                               0xF7081C
#define DI8__Mouse_Copy_x                                          0xECBE84
#define DI8__Mouse_Check_x                                         0xF712C8
#define __AutoSkillArray_x                                         0xECCD9C
#define __Attack_x                                                 0xF6ABC3
#define __Autofire_x                                               0xF6ABC4
#define __BindList_x                                               0xC3FF30
#define g_eqCommandStates_x                                        0xC40CB0
#define __Clicks_x                                                 0xECBF3C
#define __CommandList_x                                            0xC41870
#define __CurrentMapLabel_x                                        0xF8368C
#define __CurrentSocial_x                                          0xC297CC
#define __DoAbilityList_x                                          0xF026E4
#define __do_loot_x                                                0x5C1EF0
#define __DrawHandler_x                                            0x1602A08
#define __GroupCount_x                                             0xEC6A1A
#define __Guilds_x                                                 0xECADC8
#define __gWorld_x                                                 0xEC6C10
#define __HWnd_x                                                   0xF712A8
#define __heqmain_x                                                0xF7375C
#define __InChatMode_x                                             0xECBE6C
#define __LastTell_x                                               0xECDDE0
#define __LMouseHeldTime_x                                         0xECBFA8
#define __Mouse_x                                                  0xF707E8
#define __MouseLook_x                                              0xECBF02
#define __MouseEventTime_x                                         0xF6B6A4
#define __gpbCommandEvent_x                                        0xEC6C1C
#define __NetStatusToggle_x                                        0xECBF05
#define __PCNames_x                                                0xECD38C
#define __RangeAttackReady_x                                       0xECD080
#define __RMouseHeldTime_x                                         0xECBFA4
#define __RunWalkState_x                                           0xECBE70
#define __ScreenMode_x                                             0xE121A8
#define __ScreenX_x                                                0xECBE24
#define __ScreenY_x                                                0xECBE20
#define __ScreenXMax_x                                             0xECBE28
#define __ScreenYMax_x                                             0xECBE2C
#define __ServerHost_x                                             0xEC6E4B
#define __ServerName_x                                             0xF026A4
#define __ShiftKeyDown_x                                           0xECC4FC
#define __ShowNames_x                                              0xECD23C
#define __SocialChangedList_x                                      0xF0272C
#define __Socials_x                                                0xF027A4
#define __SubscriptionType_x                                       0xFC7B98
#define __TargetAggroHolder_x                                      0xF86040
#define __ZoneType_x                                               0xECC300
#define __GroupAggro_x                                             0xF86080
#define __LoginName_x                                              0xF70F54
#define __Inviter_x                                                0xF6AB40
#define __AttackOnAssist_x                                         0xECD1F8
#define __UseTellWindows_x                                         0xECD528
#define __gfMaxZoomCameraDistance_x                                0xB0ECE0
#define __gfMaxCameraDistance_x                                    0xB3B084
#define __pulAutoRun_x                                             0xECBF20
#define __pulForward_x                                             0xECD560
#define __pulBackward_x                                            0xECD564
#define __pulTurnRight_x                                           0xECD568
#define __pulTurnLeft_x                                            0xECD56C
#define __pulStrafeLeft_x                                          0xECD570
#define __pulStrafeRight_x                                         0xECD574

////
//Section 1: Vital Offsets
////
#define instCRaid_x                                                0xEC7160
#define instEQZoneInfo_x                                           0xECC0F8
#define pinstActiveBanker_x                                        0xEC6CF8
#define pinstActiveCorpse_x                                        0xEC6CF0
#define pinstActiveGMaster_x                                       0xEC6CF4
#define pinstActiveMerchant_x                                      0xEC6CEC
#define pinstAltAdvManager_x                                       0xE13390
#define pinstBandageTarget_x                                       0xEC6D08
#define pinstCamActor_x                                            0xE12198
#define pinstCDBStr_x                                              0xE120AC
#define pinstCDisplay_x                                            0xEC6868
#define pinstCEverQuest_x                                          0xF70818
#define pinstEverQuestInfo_x                                       0xECBE18
#define pinstCharData_x                                            0xEC6A04
#define pinstCharSpawn_x                                           0xEC6D40
#define pinstControlledMissile_x                                   0xEC4854
#define pinstControlledPlayer_x                                    0xEC6D40
#define pinstCResolutionHandler_x                                  0x1602C38
#define pinstCSidlManager_x                                        0x1601BD0
#define pinstCXWndManager_x                                        0x1601BCC
#define instDynamicZone_x                                          0xECACA0
#define pinstDZMember_x                                            0xECADB0
#define pinstDZTimerInfo_x                                         0xECADB4
#define pinstEqLogin_x                                             0xF708A0
#define instEQMisc_x                                               0xE11FF0
#define pinstEQSoundManager_x                                      0xE14360
#define pinstEQSpellStrings_x                                      0xCD49F8
#define instExpeditionLeader_x                                     0xECACEA
#define instExpeditionName_x                                       0xECAD2A
#define pinstSGraphicsEngine_x                                     0x16029FC
#define pinstGroup_x                                               0xEC6A16
#define pinstImeManager_x                                          0x1601BC8
#define pinstLocalPlayer_x                                         0xEC6CE8
#define pinstMercenaryData_x                                       0xF6D19C
#define pinstMercenaryStats_x                                      0xF8618C
#define pinstModelPlayer_x                                         0xEC6D00
#define pinstPCData_x                                              0xEC6A04
#define pinstSkillMgr_x                                            0xF6F300
#define pinstSpawnManager_x                                        0xF6DDA8
#define pinstSpellManager_x                                        0xF6F540
#define pinstSpellSets_x                                           0xF637EC
#define pinstStringTable_x                                         0xEC6C08
#define pinstSwitchManager_x                                       0xEC4700
#define pinstTarget_x                                              0xEC6D3C
#define pinstTargetObject_x                                        0xEC6F54
#define pinstTargetSwitch_x                                        0xEC485C
#define pinstTaskMember_x                                          0xE11E80
#define pinstTrackTarget_x                                         0xEC6D44
#define pinstTradeTarget_x                                         0xEC6CFC
#define instTributeActive_x                                        0xE12011
#define pinstViewActor_x                                           0xE12194
#define pinstWorldData_x                                           0xEC6864
#define pinstZoneAddr_x                                            0xECC398
#define pinstPlayerPath_x                                          0xF6DE40
#define pinstTargetIndicator_x                                     0xF6F7A8
#define EQObject_Top_x                                             0xEC6CE4

////
//Section 2:  UI Related Offsets
////
#define pinstCAAWnd_x                                              0xE1247C
#define pinstCAchievementsWnd_x                                    0xE1298C
#define pinstCActionsWnd_x                                         0xE124D4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE121BC
#define pinstCAdvancedLootWnd_x                                    0xE12154
#define pinstCAdventureLeaderboardWnd_x                            0xF7CE60
#define pinstCAdventureRequestWnd_x                                0xF7CF10
#define pinstCAdventureStatsWnd_x                                  0xF7CFC0
#define pinstCAggroMeterWnd_x                                      0xE121C0
#define pinstCAlarmWnd_x                                           0xE129CC
#define pinstCAlertHistoryWnd_x                                    0xE12210
#define pinstCAlertStackWnd_x                                      0xE12158
#define pinstCAlertWnd_x                                           0xE12178
#define pinstCAltStorageWnd_x                                      0xF7D320
#define pinstCAudioTriggersWindow_x                                0xCC6D28
#define pinstCAuraWnd_x                                            0xE12164
#define pinstCAvaZoneWnd_x                                         0xE12214
#define pinstCBandolierWnd_x                                       0xE121B4
#define pinstCBankWnd_x                                            0xE121FC
#define pinstCBarterMerchantWnd_x                                  0xF7E560
#define pinstCBarterSearchWnd_x                                    0xF7E610
#define pinstCBarterWnd_x                                          0xF7E6C0
#define pinstCBazaarConfirmationWnd_x                              0xE129C8
#define pinstCBazaarSearchWnd_x                                    0xE12480
#define pinstCBazaarWnd_x                                          0xE129AC
#define pinstCBlockedBuffWnd_x                                     0xE12170
#define pinstCBlockedPetBuffWnd_x                                  0xE12190
#define pinstCBodyTintWnd_x                                        0xE12948
#define pinstCBookWnd_x                                            0xE121E8
#define pinstCBreathWnd_x                                          0xE12490
#define pinstCBuffWindowNORMAL_x                                   0xE12148
#define pinstCBuffWindowSHORT_x                                    0xE1214C
#define pinstCBugReportWnd_x                                       0xE121F8
#define pinstCButtonWnd_x                                          0x1601E38
#define pinstCCastingWnd_x                                         0xE121D4
#define pinstCCastSpellWnd_x                                       0xE12484
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE12960
#define pinstCChatWindowManager_x                                  0xF7F180
#define pinstCClaimWnd_x                                           0xF7F2D8
#define pinstCColorPickerWnd_x                                     0xE12248
#define pinstCCombatAbilityWnd_x                                   0xE129BC
#define pinstCCombatSkillsSelectWnd_x                              0xE12970
#define pinstCCompassWnd_x                                         0xE1253C
#define pinstCConfirmationDialog_x                                 0xF841D8
#define pinstCContainerMgr_x                                       0xE1295C
#define pinstCContextMenuManager_x                                 0x1601B88
#define pinstCCursorAttachment_x                                   0xE121C8
#define pinstCDynamicZoneWnd_x                                     0xF7F8A0
#define pinstCEditLabelWnd_x                                       0xE129E0
#define pinstCEQMainWnd_x                                          0xF7FAE8
#define pinstCEventCalendarWnd_x                                   0xE12474
#define pinstCExtendedTargetWnd_x                                  0xE1218C
#define pinstCFacePick_x                                           0xE12988
#define pinstCFactionWnd_x                                         0xE12998
#define pinstCFellowshipWnd_x                                      0xF7FCE8
#define pinstCFileSelectionWnd_x                                   0xE1223C
#define pinstCFindItemWnd_x                                        0xE12980
#define pinstCFindLocationWnd_x                                    0xF7FE40
#define pinstCFriendsWnd_x                                         0xE1297C
#define pinstCGemsGameWnd_x                                        0xE12994
#define pinstCGiveWnd_x                                            0xE129D4
#define pinstCGroupSearchFiltersWnd_x                              0xE121D8
#define pinstCGroupSearchWnd_x                                     0xF80238
#define pinstCGroupWnd_x                                           0xF802E8
#define pinstCGuildBankWnd_x                                       0xECD1DC
#define pinstCGuildCreationWnd_x                                   0xF80448
#define pinstCGuildMgmtWnd_x                                       0xF804F8
#define pinstCharacterCreation_x                                   0xE12978
#define pinstCHelpWnd_x                                            0xE129C4
#define pinstCHeritageSelectionWnd_x                               0xE1299C
#define pinstCHotButtonWnd_x                                       0xF82650
#define pinstCHotButtonWnd1_x                                      0xF82650
#define pinstCHotButtonWnd2_x                                      0xF82654
#define pinstCHotButtonWnd3_x                                      0xF82658
#define pinstCHotButtonWnd4_x                                      0xF8265C
#define pinstCIconSelectionWnd_x                                   0xE121C4
#define pinstCInspectWnd_x                                         0xE1219C
#define pinstCInventoryWnd_x                                       0xE1216C
#define pinstCInvSlotMgr_x                                         0xE1248C
#define pinstCItemDisplayManager_x                                 0xF82BE0
#define pinstCItemExpTransferWnd_x                                 0xF82D10
#define pinstCItemOverflowWnd_x                                    0xE12488
#define pinstCJournalCatWnd_x                                      0xE12460
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE12218
#define pinstCKeyRingWnd_x                                         0xE121D0
#define pinstCLargeDialogWnd_x                                     0xF84E58
#define pinstCLayoutCopyWnd_x                                      0xF83060
#define pinstCLFGuildWnd_x                                         0xF83110
#define pinstCLoadskinWnd_x                                        0xE129A8
#define pinstCLootFiltersCopyWnd_x                                 0xCE3388
#define pinstCLootFiltersWnd_x                                     0xE1215C
#define pinstCLootSettingsWnd_x                                    0xE12184
#define pinstCLootWnd_x                                            0xE12464
#define pinstCMailAddressBookWnd_x                                 0xE12494
#define pinstCMailCompositionWnd_x                                 0xE12478
#define pinstCMailIgnoreListWnd_x                                  0xE12498
#define pinstCMailWnd_x                                            0xE12250
#define pinstCManageLootWnd_x                                      0xE13840
#define pinstCMapToolbarWnd_x                                      0xE129D0
#define pinstCMapViewWnd_x                                         0xE129A0
#define pinstCMarketplaceWnd_x                                     0xE12160
#define pinstCMerchantWnd_x                                        0xE12470
#define pinstCMIZoneSelectWnd_x                                    0xF83948
#define pinstCMusicPlayerWnd_x                                     0xE12208
#define pinstCNameChangeMercWnd_x                                  0xE129B0
#define pinstCNameChangePetWnd_x                                   0xE12990
#define pinstCNameChangeWnd_x                                      0xE129D8
#define pinstCNoteWnd_x                                            0xE129B4
#define pinstCObjectPreviewWnd_x                                   0xE1217C
#define pinstCOptionsWnd_x                                         0xE129C0
#define pinstCPetInfoWnd_x                                         0xE12230
#define pinstCPetitionQWnd_x                                       0xE12964
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE12950
#define pinstCPlayerWnd_x                                          0xE12238
#define pinstCPopupWndManager_x                                    0xF841D8
#define pinstCProgressionSelectionWnd_x                            0xF84288
#define pinstCPurchaseGroupWnd_x                                   0xE121EC
#define pinstCPurchaseWnd_x                                        0xE121B8
#define pinstCPvPLeaderboardWnd_x                                  0xF84338
#define pinstCPvPStatsWnd_x                                        0xF843E8
#define pinstCQuantityWnd_x                                        0xE1221C
#define pinstCRaceChangeWnd_x                                      0xE12150
#define pinstCRaidOptionsWnd_x                                     0xE121E4
#define pinstCRaidWnd_x                                            0xE12468
#define pinstCRealEstateItemsWnd_x                                 0xE12984
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE124C0
#define pinstCRealEstateManageWnd_x                                0xE121F4
#define pinstCRealEstateNeighborhoodWnd_x                          0xE1220C
#define pinstCRealEstatePlotSearchWnd_x                            0xE1222C
#define pinstCRealEstatePurchaseWnd_x                              0xE12244
#define pinstCRespawnWnd_x                                         0xE12188
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE1296C
#define pinstCSendMoneyWnd_x                                       0xE129DC
#define pinstCServerListWnd_x                                      0xE12254
#define pinstCSkillsSelectWnd_x                                    0xE12958
#define pinstCSkillsWnd_x                                          0xE12944
#define pinstCSocialEditWnd_x                                      0xE121CC
#define pinstCSocialWnd_x                                          0xE129A4
#define pinstCSpellBookWnd_x                                       0xE129B8
#define pinstCStoryWnd_x                                           0xE124BC
#define pinstCTargetOfTargetWnd_x                                  0xF86210
#define pinstCTargetWnd_x                                          0xE12180
#define pinstCTaskOverlayWnd_x                                     0xE121E0
#define pinstCTaskSelectWnd_x                                      0xF86368
#define pinstCTaskManager_x                                        0xCE3CC8
#define pinstCTaskTemplateSelectWnd_x                              0xF86418
#define pinstCTaskWnd_x                                            0xF864C8
#define pinstCTextEntryWnd_x                                       0xE121DC
#define pinstCTimeLeftWnd_x                                        0xE1294C
#define pinstCTipWndCONTEXT_x                                      0xF866CC
#define pinstCTipWndOFDAY_x                                        0xF866C8
#define pinstCTitleWnd_x                                           0xF86778
#define pinstCTrackingWnd_x                                        0xE12174
#define pinstCTradeskillWnd_x                                      0xF868E0
#define pinstCTradeWnd_x                                           0xE12954
#define pinstCTrainWnd_x                                           0xE1245C
#define pinstCTributeBenefitWnd_x                                  0xF86AE0
#define pinstCTributeMasterWnd_x                                   0xF86B90
#define pinstCTributeTrophyWnd_x                                   0xF86C40
#define pinstCVideoModesWnd_x                                      0xE12240
#define pinstCVoiceMacroWnd_x                                      0xF6FF10
#define pinstCVoteResultsWnd_x                                     0xE12974
#define pinstCVoteWnd_x                                            0xE12968
#define pinstCWebManager_x                                         0xF7058C
#define pinstCZoneGuideWnd_x                                       0xE121F0
#define pinstCZonePathWnd_x                                        0xE12200
#define pinstEQSuiteTextureLoader_x                                0xCB1128
#define pinstItemIconCache_x                                       0xF7FAA0
#define pinstLootFiltersManager_x                                  0xCE3438
#define pinstRewardSelectionWnd_x                                  0xF84B30

////
// Section 3: Miscellaneous Offsets
////
#define __CastRay_x                                                0x5BD2C0
#define __CastRay2_x                                               0x5BD310
#define __ConvertItemTags_x                                        0x5D8ED0
#define __CleanItemTags_x                                          0x47D000
#define __CreateCascadeMenuItems_x                                 0x558B70
#define __DoesFileExist_x                                          0x9131B0
#define __EQGetTime_x                                              0x90FC50
#define __ExecuteCmd_x                                             0x5B5B50
#define __FixHeading_x                                             0x9AAE80
#define __FlushDxKeyboard_x                                        0x6C6F50
#define __GameLoop_x                                               0x6CA260
#define __get_bearing_x                                            0x5BCE30
#define __get_melee_range_x                                        0x5BD500
#define __GetAnimationCache_x                                      0x72F880
#define __GetGaugeValueFromEQ_x                                    0x821500
#define __GetLabelFromEQ_x                                         0x822FE0
#define __GetXTargetType_x                                         0x9AC860
#define __HandleMouseWheel_x                                       0x6CB140
#define __HeadingDiff_x                                            0x9AAEF0
#define __HelpPath_x                                               0xF6B294
#define __LoadFrontEnd_x                                           0x6C7580
#define __NewUIINI_x                                               0x8211D0
#define __ProcessGameEvents_x                                      0x61DCB0
#define __ProcessKeyboardEvents_x                                  0x6C8AC0
#define __ProcessMouseEvents_x                                     0x61D470
#define __SaveColors_x                                             0x558A50
#define __STMLToText_x                                             0x94E330
#define __WndProc_x                                                0x6C9520
#define CMemoryMappedFile__SetFile_x                               0xA9A000
#define CrashDetected_x                                            0x6C9020
#define DrawNetStatus_x                                            0x649930
#define Expansion_HoT_x                                            0xECD1E4
#define Teleport_Table_Size_x                                      0xEC6CA4
#define Teleport_Table_x                                           0xEC4860
#define Util__FastTime_x                                           0x90F820
#define __eq_delete_x                                              0x9B335E
#define __eq_new_x                                                 0x9B3914

////
// Section 4: Function Offsets
////

// CAAwnd
#define CAAWnd__ShowAbility_x                                      0x6D74E0

// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490370
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499290
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499060
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493910
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492D60

// AltAdvManager
#define AltAdvManager__GetCalculatedTimer_x                        0x560BB0
#define AltAdvManager__IsAbilityReady_x                            0x55F950
#define AltAdvManager__GetAAById_x                                 0x55FCE0
#define AltAdvManager__CanTrainAbility_x                           0x55FD50
#define AltAdvManager__CanSeeAbility_x                             0x5600B0

// CharacterZoneClient
#define CharacterZoneClient__BardCastBard_x                        0x4C5820
#define CharacterZoneClient__CalcAffectChange_x                    0x4C3F60
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4130
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BABD0
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9DC0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2CA0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D72C0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6D40
#define CharacterZoneClient__GetCurrentMod_x                       0x4E4A70
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D8EC0
#define CharacterZoneClient__GetEffect_x                           0x4BAB10
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3DC0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2A30
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8DE0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8D00
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3E10
#define CharacterZoneClient__GetMaxEffects_x                       0x4BACA0
#define CharacterZoneClient__GetModCap_x                           0x4E4970
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3CF0
#define CharacterZoneClient__HasSkill_x                            0x4D4C40
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE5A0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6360

// CBankWnd
#define CBankWnd__GetNumBankSlots_x                                0x6F0E70
#define CBankWnd__WndNotification_x                                0x6F0C50

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6FE9E0

// CButtonWnd
#define CButtonWnd__SetCheck_x                                     0x62C3D0
#define CButtonWnd__CButtonWnd_x                                   0x94A6F0
#define CButtonWnd__dCButtonWnd_x                                  0x94A9C0
#define CButtonWnd__vftable_x                                      0xB53DB8

// CChatWindowManager
#define CChatWindowManager__GetRGBAFromIndex_x                     0x71E920
#define CChatWindowManager__InitContextMenu_x                      0x717A50
#define CChatWindowManager__FreeChatWindow_x                       0x71D460
#define CChatWindowManager__GetLockedActiveChatWindow_x            0x4E8410
#define CChatWindowManager__SetLockedActiveChatWindow_x            0x71E5A0
#define CChatWindowManager__CreateChatWindow_x                     0x71DAA0

// ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8520

// CChatWindow
#define CChatWindow__CChatWindow_x                                 0x71F150
#define CChatWindow__Clear_x                                       0x720410
#define CChatWindow__WndNotification_x                             0x720BA0
#define CChatWindow__AddHistory_x                                  0x71FCD0

// CContextMenu
#define CContextMenu__CContextMenu_x                               0x95ED50
#define CContextMenu__dCContextMenu_x                              0x95EF90
#define CContextMenu__AddMenuItem_x                                0x95EFA0
#define CContextMenu__RemoveMenuItem_x                             0x95F2B0
#define CContextMenu__RemoveAllMenuItems_x                         0x95F2D0
#define CContextMenu__CheckMenuItem_x                              0x95F350
#define CContextMenu__SetMenuItem_x                                0x95F1D0
#define CContextMenu__AddSeparator_x                               0x95F130

// CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x95F8F0
#define CContextMenuManager__RemoveMenu_x                          0x95F960
#define CContextMenuManager__PopupMenu_x                           0x95FA20
#define CContextMenuManager__Flush_x                               0x95F890
#define CContextMenuManager__GetMenu_x                             0x49B3E0
#define CContextMenuManager__CreateDefaultMenu_x                   0x72A080

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8EADE0
#define CChatService__GetFriendName_x                              0x8EADF0

// CComboWnd
#define CComboWnd__DeleteAll_x                                     0x95C1A0
#define CComboWnd__Draw_x                                          0x95B680
#define CComboWnd__GetCurChoice_x                                  0x95BFE0
#define CComboWnd__GetListRect_x                                   0x95BB40
#define CComboWnd__GetTextRect_x                                   0x95C210
#define CComboWnd__InsertChoice_x                                  0x95BCD0
#define CComboWnd__SetColors_x                                     0x95BCA0
#define CComboWnd__SetChoice_x                                     0x95BFB0
#define CComboWnd__GetItemCount_x                                  0x95BFF0
#define CComboWnd__GetCurChoiceText_x                              0x95C030
#define CComboWnd__GetChoiceText_x                                 0x95C000
#define CComboWnd__InsertChoiceAtIndex_x                           0x95BD70

// CContainerWnd
#define CContainerWnd__HandleCombine_x                             0x727A60
#define CContainerWnd__vftable_x                                   0xB22564
#define CContainerWnd__SetContainer_x                              0x728FC0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x553400
#define CDisplay__PreZoneMainUI_x                                  0x553410
#define CDisplay__CleanGameUI_x                                    0x558810
#define CDisplay__GetClickedActor_x                                0x54B700
#define CDisplay__GetUserDefinedColor_x                            0x543D60
#define CDisplay__GetWorldFilePath_x                               0x54D170
#define CDisplay__is3dON_x                                         0x548360
#define CDisplay__ReloadUI_x                                       0x552880
#define CDisplay__WriteTextHD2_x                                   0x548150
#define CDisplay__TrueDistance_x                                   0x54EE30
#define CDisplay__SetViewActor_x                                   0x54B020
#define CDisplay__GetFloorHeight_x                                 0x548420
#define CDisplay__SetRenderWindow_x                                0x546D80
#define CDisplay__ToggleScreenshotMode_x                           0x54AAF0

// CEditBaseWnd
#define CEditBaseWnd__SetSel_x                                     0x97EB20

// CEditWnd
#define CEditWnd__DrawCaret_x                                      0x9622C0
#define CEditWnd__EnsureCaretVisible_x                             0x964490
#define CEditWnd__GetCaretPt_x                                     0x963440
#define CEditWnd__GetCharIndexPt_x                                 0x9631F0
#define CEditWnd__GetDisplayString_x                               0x963090
#define CEditWnd__GetHorzOffset_x                                  0x9618F0
#define CEditWnd__GetLineForPrintableChar_x                        0x964390
#define CEditWnd__GetSelStartPt_x                                  0x9634A0
#define CEditWnd__GetSTMLSafeText_x                                0x962EB0
#define CEditWnd__PointFromPrintableChar_x                         0x963FC0
#define CEditWnd__ReplaceSelection_x                               0x963C30
#define CEditWnd__SelectableCharFromPoint_x                        0x964130
#define CEditWnd__SetEditable_x                                    0x963570
#define CEditWnd__SetWindowTextA_x                                 0x962C30

// CEverQuest
#define CEverQuest__DoPercentConvert_x                             0x60B890
#define CEverQuest__ClickedPlayer_x                                0x5FD9C0
#define CEverQuest__CreateTargetIndicator_x                        0x61AF50
#define CEverQuest__DeleteTargetIndicator_x                        0x61AFE0
#define CEverQuest__DoTellWindow_x                                 0x4E8600
#define CEverQuest__OutputTextToLog_x                              0x4E88D0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F2A00
#define CEverQuest__dsp_chat_x                                     0x4E8C60
#define CEverQuest__trimName_x                                     0x6170C0
#define CEverQuest__Emote_x                                        0x60C0F0
#define CEverQuest__EnterZone_x                                    0x606190
#define CEverQuest__GetBodyTypeDesc_x                              0x6109B0
#define CEverQuest__GetClassDesc_x                                 0x610FF0
#define CEverQuest__GetClassThreeLetterCode_x                      0x6115F0
#define CEverQuest__GetDeityDesc_x                                 0x6197A0
#define CEverQuest__GetLangDesc_x                                  0x6117B0
#define CEverQuest__GetRaceDesc_x                                  0x610FD0
#define CEverQuest__InterpretCmd_x                                 0x619D70
#define CEverQuest__LeftClickedOnPlayer_x                          0x5F6C00
#define CEverQuest__LMouseUp_x                                     0x5F4F90
#define CEverQuest__RightClickedOnPlayer_x                         0x5F74E0
#define CEverQuest__RMouseUp_x                                     0x5F5F10
#define CEverQuest__SetGameState_x                                 0x5F2790
#define CEverQuest__UPCNotificationFlush_x                         0x616FC0
#define CEverQuest__IssuePetCommand_x                              0x612BB0
#define CEverQuest__ReportSuccessfulHeal_x                         0x60CE10
#define CEverQuest__ReportSuccessfulHit_x                          0x60D440

// CGaugeWnd
// not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x739A60
#define CGaugeWnd__CalcLinesFillRect_x                             0x739AC0
#define CGaugeWnd__Draw_x                                          0x7390E0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF4D0
#define CGuild__GetGuildName_x                                     0x4AE510
#define CGuild__GetGuildIndex_x                                    0x4AE950

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton_x                               0x753C40

//CHotButton
#define CHotButton__SetButtonSize_x                                0x62C790

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot_x                                 0x760BC0
#define CInvSlotMgr__MoveItem_x                                    0x75F930
#define CInvSlotMgr__SelectSlot_x                                  0x760C90

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x75E1B0
#define CInvSlot__SliderComplete_x                                 0x75BF10
#define CInvSlot__GetItemBase_x                                    0x75B8B0
#define CInvSlot__UpdateItem_x                                     0x75BA20

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x762710
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7618B0
#define CInvSlotWnd__HandleLButtonUp_x                             0x762290

// CItemDisplayWnd
#define CItemDisplayWnd__SetSpell_x                                0x81C890
#define CItemDisplayWnd__UpdateStrings_x                           0x770D60
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x76AAC0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x76AFC0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x771370
#define CItemDisplayWnd__AboutToShow_x                             0x7709A0
#define CItemDisplayWnd__WndNotification_x                         0x772490
#define CItemDisplayWnd__RequestConvertItem_x                      0x771F10
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x76FA00
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7707C0

// CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x855340

// CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7769C0

// CKeyRingWnd
#define CKeyRingWnd__ExecuteRightClick_x                           0x519880

// CLabel
#define CLabel__Draw_x                                             0x77C440

// CListWnd
#define CListWnd__CListWnd_x                                       0x934750
#define CListWnd__dCListWnd_x                                      0x934A70
#define CListWnd__vftable_x                                        0xB53690
#define CListWnd__AddColumn_x                                      0x938EB0
#define CListWnd__AddColumn1_x                                     0x938F00
#define CListWnd__AddLine_x                                        0x939290
#define CListWnd__AddString_x                                      0x939090
#define CListWnd__CalculateFirstVisibleLine_x                      0x938C70
#define CListWnd__CalculateVSBRange_x                              0x938A70
#define CListWnd__ClearSel_x                                       0x939A70
#define CListWnd__ClearAllSel_x                                    0x939AD0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x93A4F0
#define CListWnd__Compare_x                                        0x9383A0
#define CListWnd__Draw_x                                           0x934BA0
#define CListWnd__DrawColumnSeparators_x                           0x937380
#define CListWnd__DrawHeader_x                                     0x9377E0
#define CListWnd__DrawItem_x                                       0x937CE0
#define CListWnd__DrawLine_x                                       0x9374E0
#define CListWnd__DrawSeparator_x                                  0x937420
#define CListWnd__EnableLine_x                                     0x936C60
#define CListWnd__EnsureVisible_x                                  0x93A410
#define CListWnd__ExtendSel_x                                      0x9399A0
#define CListWnd__GetColumnTooltip_x                               0x9367A0
#define CListWnd__GetColumnMinWidth_x                              0x936810
#define CListWnd__GetColumnWidth_x                                 0x936710
#define CListWnd__GetCurSel_x                                      0x9360A0
#define CListWnd__GetItemAtPoint_x                                 0x936ED0
#define CListWnd__GetItemAtPoint1_x                                0x936F40
#define CListWnd__GetItemData_x                                    0x936120
#define CListWnd__GetItemHeight_x                                  0x9364E0
#define CListWnd__GetItemIcon_x                                    0x9362B0
#define CListWnd__GetItemRect_x                                    0x936D50
#define CListWnd__GetItemText_x                                    0x936160
#define CListWnd__GetSelList_x                                     0x939B20
#define CListWnd__GetSeparatorRect_x                               0x937180
#define CListWnd__InsertLine_x                                     0x939680
#define CListWnd__RemoveLine_x                                     0x9397D0
#define CListWnd__SetColors_x                                      0x938A40
#define CListWnd__SetColumnJustification_x                         0x938770
#define CListWnd__SetColumnLabel_x                                 0x939030
#define CListWnd__SetColumnWidth_x                                 0x938690
#define CListWnd__SetCurSel_x                                      0x9398E0
#define CListWnd__SetItemColor_x                                   0x93A0C0
#define CListWnd__SetItemData_x                                    0x93A080
#define CListWnd__SetItemText_x                                    0x939C90
#define CListWnd__ShiftColumnSeparator_x                           0x938830
#define CListWnd__Sort_x                                           0x938520
#define CListWnd__ToggleSel_x                                      0x939910
#define CListWnd__SetColumnsSizable_x                              0x9388E0
#define CListWnd__SetItemWnd_x                                     0x939F40
#define CListWnd__GetItemWnd_x                                     0x936300
#define CListWnd__SetItemIcon_x                                    0x939D10
#define CListWnd__CalculateCustomWindowPositions_x                 0x938D70
#define CListWnd__SetVScrollPos_x                                  0x938670

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd_x                                 0x791B70

// MapViewMap
#define MapViewMap__MapViewMap_x                                   0x78D060
#define MapViewMap__dMapViewMap_x                                  0x78D1B0
#define MapViewMap__vftable_x                                      0xB29BA8
#define MapViewMap__Clear_x                                        0x78D9E0
#define MapViewMap__SaveEx_x                                       0x790DA0
#define MapViewMap__SetZoom_x                                      0x795460
#define MapViewMap__HandleLButtonDown_x                            0x78D2C0
#define MapViewMap__GetWorldCoordinates_x                          0x790280

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7B1D10
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7B25F0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7B2B20
#define CMerchantWnd__SelectRecoverySlot_x                         0x7B5A90
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7B0890
#define CMerchantWnd__SelectBuySellSlot_x                          0x7BB640
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7B1930

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8B8AD0
#define CPacketScrambler__hton_x                                   0x8B8AC0

// CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x957D40
#define CSidlManagerBase__CreatePageWnd_x                          0x957530
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9537B0
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x953740
#define CSidlManagerBase__FindAnimation1_x                         0x953990
#define CSidlManagerBase__FindScreenPieceTemplate_x                0x953DA0
#define CSidlManagerBase__FindScreenPieceTemplate1_x               0x953B90
#define CSidlManagerBase__CreateLabel_x                            0x813AA0
#define CSidlManagerBase__CreateXWndFromTemplate_x                 0x956D00
#define CSidlManagerBase__CreateXWndFromTemplate1_x                0x956EE0
#define CSidlManagerBase__CreateXWnd_x                             0x8139D0

// CSidlManager
#define CSidlManager__CreateHotButtonWnd_x                         0x813FA0

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange_x                        0x950450
#define CSidlScreenWnd__CalculateVSBRange_x                        0x950350
#define CSidlScreenWnd__ConvertToRes_x                             0x979600
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x94FDE0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x94FAD0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x94FBA0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x94FC70
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9508E0
#define CSidlScreenWnd__EnableIniStorage_x                         0x950DB0
#define CSidlScreenWnd__GetChildItem_x                             0x950D30
#define CSidlScreenWnd__GetSidlPiece_x                             0x950AD0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x940360
#define CSidlScreenWnd__Init1_x                                    0x94F6D0
#define CSidlScreenWnd__LoadIniInfo_x                              0x950E00
#define CSidlScreenWnd__LoadIniListWnd_x                           0x951940
#define CSidlScreenWnd__LoadSidlScreen_x                           0x94EAE0
#define CSidlScreenWnd__m_layoutCopy_x                             0x1601A58
#define CSidlScreenWnd__StoreIniInfo_x                             0x9514C0
#define CSidlScreenWnd__StoreIniVis_x                              0x951820
#define CSidlScreenWnd__vftable_x                                  0xB54048
#define CSidlScreenWnd__WndNotification_x                          0x9507F0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x690E80
#define CSkillMgr__GetSkillCap_x                                   0x691060
#define CSkillMgr__GetNameToken_x                                  0x690600
#define CSkillMgr__IsActivatedSkill_x                              0x690740
#define CSkillMgr__IsCombatSkill_x                                 0x690680

// CSliderWnd
#define CSliderWnd__GetValue_x                                     0x9606D0
#define CSliderWnd__SetValue_x                                     0x960540
#define CSliderWnd__SetNumTicks_x                                  0x9605A0

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet_x                               0x819B90

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x968EE0
#define CStmlWnd__CalculateHSBRange_x                              0x96A000
#define CStmlWnd__CalculateVSBRange_x                              0x969F70
#define CStmlWnd__CanBreakAtCharacter_x                            0x96E330
#define CStmlWnd__FastForwardToEndOfTag_x                          0x96EFC0
#define CStmlWnd__ForceParseNow_x                                  0x9694D0
#define CStmlWnd__GetNextTagPiece_x                                0x96E290
#define CStmlWnd__GetSTMLText_x                                    0x509270
#define CStmlWnd__GetVisibleText_x                                 0x9694F0
#define CStmlWnd__InitializeWindowVariables_x                      0x96EE10
#define CStmlWnd__MakeStmlColorTag_x                               0x968550
#define CStmlWnd__MakeWndNotificationTag_x                         0x9685C0
#define CStmlWnd__SetSTMLText_x                                    0x967600
#define CStmlWnd__StripFirstSTMLLines_x                            0x970090
#define CStmlWnd__UpdateHistoryString_x                            0x96F1D0

// CTabWnd
#define CTabWnd__Draw_x                                            0x966750
#define CTabWnd__DrawCurrentPage_x                                 0x966E80
#define CTabWnd__DrawTab_x                                         0x966BA0
#define CTabWnd__GetCurrentPage_x                                  0x965F50
#define CTabWnd__GetCurrentTabIndex_x                              0x965F40
#define CTabWnd__GetPageFromTabIndex_x                             0x966AE0
#define CTabWnd__GetPageInnerRect_x                                0x966190
#define CTabWnd__GetTabInnerRect_x                                 0x9660D0
#define CTabWnd__GetTabRect_x                                      0x965F80
#define CTabWnd__InsertPage_x                                      0x9663A0
#define CTabWnd__RemovePage_x                                      0x966510
#define CTabWnd__SetPage_x                                         0x966210
#define CTabWnd__SetPageRect_x                                     0x966690
#define CTabWnd__UpdatePage_x                                      0x966A60

// CPageWnd
#define CPageWnd__FlashTab_x                                       0x965B00
#define CPageWnd__GetTabText_x                                     0x776DD0
#define CPageWnd__SetTabText_x                                     0x965AA0


// CTextOverlay
#define CTextOverlay__DisplayText_x                                0x4A8FA0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x93D1E0
#define CTextureFont__DrawWrappedText1_x                           0x93D110
#define CTextureFont__DrawWrappedText2_x                           0x93D230
#define CTextureFont__GetTextExtent_x                              0x93D3A0

// CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6C43E0
#define CHtmlComponentWnd__ValidateUri_x                           0x755630
#define CHtmlWnd__SetClientCallbacks_x                             0x631810
#define CHtmlWnd__AddObserver_x                                    0x631830
#define CHtmlWnd__RemoveObserver_x                                 0x631890
#define Window__getProgress_x                                      0x86D8A0
#define Window__getStatus_x                                        0x86D8C0
#define Window__getURI_x                                           0x86D8D0

// CXMLDataManager
#define CXMLDataManager__GetXMLData_x                              0x976410

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead_x                             0x92A440

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr_x                                             0x4E8250
#define CXStr__CXStr1_x                                            0x481500
#define CXStr__CXStr3_x                                            0x90BDB0
#define CXStr__dCXStr_x                                            0x478740
#define CXStr__operator_equal_x                                    0x90BFE0
#define CXStr__operator_equal1_x                                   0x90C020
#define CXStr__operator_plus_equal1_x                              0x90CAB0
#define CXStr__SetString_x                                         0x90E9A0
#define CXStr__operator_char_p_x                                   0x90C4F0
#define CXStr__GetChar_x                                           0x90E2F0
#define CXStr__Delete_x                                            0x90DBA0
#define CXStr__GetUnicode_x                                        0x90E360
#define CXStr__GetLength_x                                         0x47D3B0
#define CXStr__Mid_x                                               0x47D3C0
#define CXStr__Insert_x                                            0x90E3C0
#define CXStr__FindNext_x                                          0x90E010
#define CXStr__gFreeLists_x                                        0xCAF580
#define CXStr__gCXStrAccess_x                                      0x160117C

// CTileLayoutWnd
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x95E960

// CXWnd
#define CXWnd__BringToTop_x                                        0x943B70
#define CXWnd__Center_x                                            0x9436F0
#define CXWnd__ClrFocus_x                                          0x943500
#define CXWnd__Destroy_x                                           0x9435B0
#define CXWnd__DoAllDrawing_x                                      0x93FAF0
#define CXWnd__DrawChildren_x                                      0x93FAC0
#define CXWnd__DrawColoredRect_x                                   0x93FF50
#define CXWnd__DrawTooltip_x                                       0x93E600
#define CXWnd__DrawTooltipAtPoint_x                                0x93E6C0
#define CXWnd__GetBorderFrame_x                                    0x93FDB0
#define CXWnd__GetChildItem_x                                      0x943D80
#define CXWnd__GetChildWndAt_x                                     0x943C10
#define CXWnd__GetClientClipRect_x                                 0x941D90
#define CXWnd__GetRelativeRect_x                                   0x9420F0
#define CXWnd__GetScreenClipRect_x                                 0x941E60
#define CXWnd__GetScreenRect_x                                     0x942030
#define CXWnd__GetTooltipRect_x                                    0x93FFA0
#define CXWnd__GetWindowTextA_x                                    0x49CB60
#define CXWnd__IsActive_x                                          0x9406E0
#define CXWnd__IsDescendantOf_x                                    0x942A30
#define CXWnd__IsReallyVisible_x                                   0x942A60
#define CXWnd__IsType_x                                            0x944270
#define CXWnd__Minimize_x                                          0x943180
#define CXWnd__Move_x                                              0x942AD0
#define CXWnd__Move1_x                                             0x942B90
#define CXWnd__ProcessTransition_x                                 0x9436A0
#define CXWnd__Refade_x                                            0x942E70
#define CXWnd__Resize_x                                            0x943110
#define CXWnd__Right_x                                             0x943930
#define CXWnd__SetFocus_x                                          0x9434C0
#define CXWnd__SetFont_x                                           0x943530
#define CXWnd__SetKeyTooltip_x                                     0x944090
#define CXWnd__SetMouseOver_x                                      0x940EE0
#define CXWnd__SetParent_x                                         0x9427D0
#define CXWnd__StartFade_x                                         0x942910
#define CXWnd__vftable_x                                           0xB53AD4
#define CXWnd__CXWnd_x                                             0x93D6C0
#define CXWnd__dCXWnd_x                                            0x93DC00

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x97A680

// CXWndManager
#define CXWndManager__DrawCursor_x                                 0x946AD0
#define CXWndManager__DrawWindows_x                                0x946AF0
#define CXWndManager__GetKeyboardFlags_x                           0x9492F0
#define CXWndManager__HandleKeyboardMsg_x                          0x948EA0
#define CXWndManager__RemoveWnd_x                                  0x949510
#define CXWndManager__RemovePendingDeletionWnd_x                   0x949A80

// CDBStr
#define CDBStr__GetString_x                                        0x542C40

// CharacterZoneClient
#define CharacterZoneClient__CanUseItem_x                          0x4D96D0
#define CharacterZoneClient__CastSpell_x                           0x4BBBB0
#define CharacterZoneClient__Cur_HP_x                              0x4D1C80
#define CharacterZoneClient__Cur_Mana_x                            0x4D93C0
#define CharacterZoneClient__GetAdjustedSkill_x                    0x4D4A00
#define CharacterZoneClient__GetBaseSkill_x                        0x4D59A0
#define CharacterZoneClient__GetCastingTimeModifier_x              0x4BEBF0
#define CharacterZoneClient__GetEnduranceRegen_x                   0x4DF790
#define CharacterZoneClient__GetFocusCastingTimeModifier_x         0x4B2670
#define CharacterZoneClient__GetFocusRangeModifier_x               0x4B27C0
#define CharacterZoneClient__GetHPRegen_x                          0x4DF190
#define CharacterZoneClient__GetManaRegen_x                        0x4DFBD0
#define CharacterZoneClient__GetPCSpellAffect_x                    0x4BF940
#define CharacterZoneClient__Max_Endurance_x                       0x6577B0
#define CharacterZoneClient__Max_HP_x                              0x4D1AB0
#define CharacterZoneClient__Max_Mana_x                            0x6575B0
#define CharacterZoneClient__SpellDuration_x                       0x4BF470
#define CharacterZoneClient__TotalEffect_x                         0x4C4F60
#define CharacterZoneClient__UseSkill_x                            0x4E19B0

// ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8D7E10

// PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x66DD90

// PcClient
#define PcClient__PcClient_x                                       0x64E010
#define PcClient__GetConLevel_x                                    0x6508C0

// CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9820
#define CCharacterListWnd__EnterWorld_x                            0x4B9260
#define CCharacterListWnd__Quit_x                                  0x4B8FB0
#define CCharacterListWnd__UpdateList_x                            0x4B93F0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6329D0
#define EQ_Item__CreateItemTagString_x                             0x8B2050
#define EQ_Item__IsStackable_x                                     0x8B6D40
#define EQ_Item__GetImageNum_x                                     0x8B3B10
#define EQ_Item__CreateItemClient_x                                0x631C10
#define EQ_Item__GetItemValue_x                                    0x8B4F30
#define EQ_Item__ValueSellMerchant_x                               0x8B86B0
#define EQ_Item__IsKeyRingItem_x                                   0x8B6660
#define EQ_Item__CanGoInBag_x                                      0x632AF0
#define EQ_Item__IsEmpty_x                                         0x8B61A0
#define EQ_Item__GetMaxItemCount_x                                 0x8B5340
#define EQ_Item__GetHeldItem_x                                     0x8B39E0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8B18B0
#define ItemClient__ItemClient_x                                   0x5B28D0
#define ItemClient__dItemClient_x                                  0x631B60

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar_x                              0x561880
#define EQ_LoadingS__Array_x                                       0xC38C60

// EQ_PC
#define EQ_PC__GetAlternateAbilityId_x                             0x8C1B30
#define EQ_PC__GetCombatAbility_x                                  0x8C21A0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8C2210
#define EQ_PC__GetItemRecastTimer_x                                0x65A160
#define EQ_PC__HasLoreItem_x                                       0x651080
#define EQ_PC__AlertInventoryChanged_x                             0x650200
#define EQ_PC__GetPcZoneClient_x                                   0x67C810
#define EQ_PC__RemoveMyAffect_x                                    0x65D390
#define EQ_PC__GetKeyRingItems_x                                   0x8C2AA0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8C2830
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8C2DA0

// EQItemList
#define EQItemList__EQItemList_x                                   0x5BA850
#define EQItemList__add_object_x                                   0x5E8110
#define EQItemList__add_item_x                                     0x5BADB0
#define EQItemList__delete_item_x                                  0x5BAE00
#define EQItemList__FreeItemList_x                                 0x5BAD00

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53F7C0

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite_x                         0x66F610
#define EQPlayer__dEQPlayer_x                                      0x662910
#define EQPlayer__DoAttack_x                                       0x6774B0
#define EQPlayer__EQPlayer_x                                       0x662FD0
#define EQPlayer__SetNameSpriteState_x                             0x6672F0
#define EQPlayer__SetNameSpriteTint_x                              0x6681C0
#define PlayerBase__HasProperty_j_x                                0x9A9280
#define EQPlayer__IsTargetable_x                                   0x9A9720
#define EQPlayer__CanSee_x                                         0x9A9580
#define EQPlayer__CanSee1_x                                        0x9A9650
#define PlayerBase__GetVisibilityLineSegment_x                     0x9A9340

// PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67A2B0
#define PlayerZoneClient__GetLevel_x                               0x67C850
#define PlayerZoneClient__IsValidTeleport_x                        0x5E9280
#define PlayerZoneClient__LegalPlayerRace_x                        0x55A670

// EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6723D0
#define EQPlayerManager__GetSpawnByName_x                          0x672480
#define EQPlayerManager__GetPlayerFromPartialName_x                0x672510

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6360C0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x636140
#define KeypressHandler__AttachKeyToEqCommand_x                    0x636180
#define KeypressHandler__ClearCommandStateArray_x                  0x637590
#define KeypressHandler__HandleKeyDown_x                           0x6375B0
#define KeypressHandler__HandleKeyUp_x                             0x637650
#define KeypressHandler__SaveKeymapping_x                          0x637AA0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8D5E70

// StringTable
#define StringTable__getString_x                                   0x8D0DA0

// PcZoneClient
#define PcZoneClient__doCombatAbility_x                            0x659BE0
#define PcZoneClient__DestroyHeldItemOrMoney_x                     0x6580F0
#define PcZoneClient__GetPcSkillLimit_x                            0x65D000
#define PcZoneClient__RemovePetEffect_x                            0x65D630
#define PcZoneClient__HasAlternateAbility_x                        0x6573E0
#define PcZoneClient__CanEquipItem_x                               0x657A90
#define PcZoneClient__GetItemByID_x                                0x65A5D0
#define PcZoneClient__GetItemByItemClass_x                         0x65A720
#define PcZoneClient__RemoveBuffEffect_x                           0x65D650
#define PcZoneClient__BandolierSwap_x                              0x6586A0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65A100

// Doors
#define EQSwitch__UseSwitch_x                                      0x5EDE00

// IconCache
#define IconCache__GetIcon_x                                       0x72F120

// CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x726C00
#define CContainerMgr__CloseContainer_x                            0x726ED0
#define CContainerMgr__OpenExperimentContainer_x                   0x727950

// CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7E5F10

// CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62AB90

// CLootWnd
#define CLootWnd__LootAll_x                                        0x783F10
#define CLootWnd__RequestLootSlot_x                                0x783140

// EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x587E90
#define EQ_Spell__SpellAffects_x                                   0x588300
#define EQ_Spell__SpellAffectBase_x                                0x5880C0
#define EQ_Spell__IsStackable_x                                    0x4C96D0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9520
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6B60
#define EQ_Spell__IsSPAStacking_x                                  0x589150
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x588660
#define EQ_Spell__IsNoRemove_x                                     0x4C96B0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x589160
#define __IsResEffectSpell_x                                       0x4C89C0

// EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD090

// EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8E03A0

// CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x82D040
#define CTargetWnd__WndNotification_x                              0x82C880
#define CTargetWnd__RefreshTargetBuffs_x                           0x82CB50
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x82B9E0

// CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x831680
#define CTaskWnd__ConfirmAbandonTask_x                             0x8342C0

// CTaskManager
#define CTaskManager__GetEntry_x                                   0x53D210
#define CTaskManager__HandleMessage_x                              0x53B690
#define CTaskManager__GetTaskStatus_x                              0x53D2C0
#define CTaskManager__GetElementDescription_x                      0x53D340

// EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x583050
#define EqSoundManager__PlayScriptMp3_x                            0x583310
#define EqSoundManager__SoundAssistPlay_x                          0x694DB0
#define EqSoundManager__WaveInstancePlay_x                         0x694320

// CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52E8F0

// CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x964FB0

// CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5692F0
#define CAltAbilityData__GetMercMaxRank_x                          0x569280
#define CAltAbilityData__GetMaxRank_x                              0x55E7D0

// CTargetRing
#define CTargetRing__Cast_x                                        0x628C90

// CharacterBase
#define CharacterBase__CreateItemGlobalIndex_x                     0x515E50
#define CharacterBase__CreateItemIndex_x                           0x630DC0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8E89D0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8E8A30
#define CharacterBase__GetItemPossession_x                         0x501D40
#define CharacterBase__GetMemorizedSpell_x                         0x4C9500
#define CharacterBase__IsExpansionFlag_x                           0x5B4370

// CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x70DCB0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x70E4E0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x70E590

// messages
#define msg_spell_worn_off_x                                       0x5ACA80
#define msg_new_text_x                                             0x5A1460
#define __msgTokenTextParam_x                                      0x5AED20
#define msgTokenText_x                                             0x5AEF70

// SpellManager
#define SpellManager__vftable_x                                    0xAFC158
#define SpellManager__SpellManager_x                               0x6980E0
#define Spellmanager__LoadTextSpells_x                             0x6989D0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6982B0

// CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x 0x9AD150

// ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8E0D40
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8E0FC0

// CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x77C780

// CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x72B320
#define CCursorAttachment__AttachToCursor1_x                       0x72B360
#define CCursorAttachment__Deactivate_x                            0x72C350

// CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x974F40
#define CEQSuiteTextureLoader__GetTexture_x                        0x974C00

// CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x513490
#define CFindItemWnd__WndNotification_x                            0x513F70
#define CFindItemWnd__Update_x                                     0x514AE0
#define CFindItemWnd__PickupSelectedItem_x                         0x512CE0

// IString
#define IString__Append_x                                          0x503590

// Camera
#define CDisplay__cameraType_x                                     0xE1224C
#define EverQuest__Cameras_x                                       0xECD534

// LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51BC10
#define LootFiltersManager__GetItemFilterData_x                    0x51B520
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51B550
#define LootFiltersManager__SetItemLootFilter_x                    0x51B770

// COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7D3D20

// CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9B2DD0
#define CResolutionHandler__GetWindowedStyle_x                     0x68FA60

// CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7238B0

// CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8F6340
#define CDistillerInfo__Instance_x                                 0x8F62E0

// CGroupWnd
#define CGroupWnd__WndNotification_x                               0x742A40
#define CGroupWnd__UpdateDisplay_x                                 0x741D90

// ItemBase
#define ItemBase__IsLore_x                                         0x8B6710
#define ItemBase__IsLoreEquipped_x                                 0x8B6780

// EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5E8070
#define EQPlacedItemManager__GetItemByGuid_x                       0x5E81B0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5E8210

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x684F20
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6888F0

// CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x509870

// FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F5F80
#define FactionManagerClient__HandleFactionMessage_x               0x4F65F0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F6BF0
#define FactionManagerClient__GetMaxFaction_x                      0x4F6C0F
#define FactionManagerClient__GetMinFaction_x                      0x4F6BC0

// BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x501D10

// ArrayClass
#define ArrayClass__DeleteElement_x                                0x93C160

// AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE70

// ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x501FA0

// MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x5687B0

// CTargetManager
#define CTargetManager__Get_x                                      0x69B9D0

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x684F20

// CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8D60

// EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BACA0

// EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF6ABC8

// KeyCombo
#define KeyCombo__GetTextDescription_x                             0x9269D0

//
// EQGraphicsDX9.dll offsets (maybe this should go in eqgraphics.h?)
//

#define __eqgraphics_fopen_x                                       0x10147468
#define CParticleSystem__Render_x                                  0x10071190
