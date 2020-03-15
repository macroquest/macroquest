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
#define __ExpectedVersionDate                                     "Mar  9 2020"
#define __ExpectedVersionTime                                     "12:02:41"
#define __ActualVersionDate_x                                      0xB193C8
#define __ActualVersionTime_x                                      0xB193BC
#define __ActualVersionBuild_x                                     0xB050DC

// Memory Protection
#define __MemChecker0_x                                            0x63CC10
#define __MemChecker1_x                                            0x910590
#define __MemChecker2_x                                            0x6CB520
#define __MemChecker3_x                                            0x6CB470
#define __MemChecker4_x                                            0x866BA0
#define __EncryptPad0_x                                            0xC514E8
#define __EncryptPad1_x                                            0xCAF650
#define __EncryptPad2_x                                            0xC61D80
#define __EncryptPad3_x                                            0xC61980
#define __EncryptPad4_x                                            0xC9FC00
#define __EncryptPad5_x                                            0xF707DC
#define __AC1_x                                                    0x823536
#define __AC2_x                                                    0x5F680F
#define __AC3_x                                                    0x5FDF0F
#define __AC4_x                                                    0x601EE0
#define __AC5_x                                                    0x6081EF
#define __AC6_x                                                    0x60C6E6
#define __AC7_x                                                    0x5F6280
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
#define __do_loot_x                                                0x5C22C0
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
#define __gfMaxZoomCameraDistance_x                                0xB0ECF0
#define __gfMaxCameraDistance_x                                    0xB3B08C
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
#define pinstCamActor_x                                            0xE1219C
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
#define pinstViewActor_x                                           0xE12198
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
#define pinstCInspectWnd_x                                         0xE12194
#define pinstCInventoryWnd_x                                       0xE12168
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
#define pinstCMailIgnoreListWnd_x                                  0xE1249C
#define pinstCMailWnd_x                                            0xE1224C
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
#define pinstCRealEstatePurchaseWnd_x                              0xE12240
#define pinstCRespawnWnd_x                                         0xE12188
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE1296C
#define pinstCSendMoneyWnd_x                                       0xE129DC
#define pinstCServerListWnd_x                                      0xE12250
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
#define pinstCTrainWnd_x                                           0xE1225C
#define pinstCTributeBenefitWnd_x                                  0xF86AE0
#define pinstCTributeMasterWnd_x                                   0xF86B90
#define pinstCTributeTrophyWnd_x                                   0xF86C40
#define pinstCVideoModesWnd_x                                      0xE12244
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
#define __CastRay_x                                                0x5BD690
#define __CastRay2_x                                               0x5BD6E0
#define __ConvertItemTags_x                                        0x5D92B0
#define __CleanItemTags_x                                          0x47D050
#define __CreateCascadeMenuItems_x                                 0x558850
#define __DoesFileExist_x                                          0x9135D0
#define __EQGetTime_x                                              0x910060
#define __ExecuteCmd_x                                             0x5B5EC0
#define __FixHeading_x                                             0x9AAE20
#define __FlushDxKeyboard_x                                        0x6C73E0
#define __GameLoop_x                                               0x6CA6F0
#define __get_bearing_x                                            0x5BD200
#define __get_melee_range_x                                        0x5BD8D0
#define __GetAnimationCache_x                                      0x72FD70
#define __GetGaugeValueFromEQ_x                                    0x8219E0
#define __GetLabelFromEQ_x                                         0x8234C0
#define __GetXTargetType_x                                         0x9AC800
#define __HandleMouseWheel_x                                       0x6CB5D0
#define __HeadingDiff_x                                            0x9AAE90
#define __HelpPath_x                                               0xF6B294
#define __LoadFrontEnd_x                                           0x6C7A10
#define __NewUIINI_x                                               0x8216B0
#define __ProcessGameEvents_x                                      0x61DFF0
#define __ProcessKeyboardEvents_x                                  0x6C8F50
#define __ProcessMouseEvents_x                                     0x61D7B0
#define __SaveColors_x                                             0x558730
#define __STMLToText_x                                             0x94E220
#define __WndProc_x                                                0x6C99B0
#define CMemoryMappedFile__SetFile_x                               0xA9A0C0
#define CrashDetected_x                                            0x6C94B0
#define DrawNetStatus_x                                            0x649E40
#define Expansion_HoT_x                                            0xECD1E4
#define Teleport_Table_Size_x                                      0xEC6CA4
#define Teleport_Table_x                                           0xEC4860
#define Util__FastTime_x                                           0x90FC30
#define __eq_delete_x                                              0x9B320E
#define __eq_new_x                                                 0x9B37D4

////
// Section 4: Function Offsets
////

// CAAwnd
#define CAAWnd__ShowAbility_x                                      0x6D7970

// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4903A0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4992C0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499090
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493940
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492D90

// AltAdvManager
#define AltAdvManager__GetCalculatedTimer_x                        0x5608F0
#define AltAdvManager__IsAbilityReady_x                            0x55F690
#define AltAdvManager__GetAAById_x                                 0x55FA20
#define AltAdvManager__CanTrainAbility_x                           0x55FA90
#define AltAdvManager__CanSeeAbility_x                             0x55FDF0

// CharacterZoneClient
#define CharacterZoneClient__BardCastBard_x                        0x4C57B0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C3EF0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C40C0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAB60
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9E00
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2C30
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7300
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6D80
#define CharacterZoneClient__GetCurrentMod_x                       0x4E4A60
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D8EE0
#define CharacterZoneClient__GetEffect_x                           0x4BAAA0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3D50
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B29A0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8E00
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8D20
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3DA0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAC30
#define CharacterZoneClient__GetModCap_x                           0x4E4960
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3C80
#define CharacterZoneClient__HasSkill_x                            0x4D4C80
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE530
#define CharacterZoneClient__MakeMeVisible_x                       0x4D63A0

// CBankWnd
#define CBankWnd__GetNumBankSlots_x                                0x6F12A0
#define CBankWnd__WndNotification_x                                0x6F1080

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6FE9D0

// CButtonWnd
#define CButtonWnd__SetCheck_x                                     0x62C8D0
#define CButtonWnd__CButtonWnd_x                                   0x94A5D0
#define CButtonWnd__dCButtonWnd_x                                  0x94A8B0
#define CButtonWnd__vftable_x                                      0xB53DC8

// CChatWindowManager
#define CChatWindowManager__GetRGBAFromIndex_x                     0x71EE10
#define CChatWindowManager__InitContextMenu_x                      0x717F40
#define CChatWindowManager__FreeChatWindow_x                       0x71D950
#define CChatWindowManager__GetLockedActiveChatWindow_x            0x4E8440
#define CChatWindowManager__SetLockedActiveChatWindow_x            0x71EA90
#define CChatWindowManager__CreateChatWindow_x                     0x71DF90

// ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8550

// CChatWindow
#define CChatWindow__CChatWindow_x                                 0x71F640
#define CChatWindow__Clear_x                                       0x720900
#define CChatWindow__WndNotification_x                             0x721090
#define CChatWindow__AddHistory_x                                  0x7201C0

// CContextMenu
#define CContextMenu__CContextMenu_x                               0x95EC20
#define CContextMenu__dCContextMenu_x                              0x95EE50
#define CContextMenu__AddMenuItem_x                                0x95EE60
#define CContextMenu__RemoveMenuItem_x                             0x95F160
#define CContextMenu__RemoveAllMenuItems_x                         0x95F180
#define CContextMenu__CheckMenuItem_x                              0x95F200
#define CContextMenu__SetMenuItem_x                                0x95F090
#define CContextMenu__AddSeparator_x                               0x95EFF0

// CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x95F7A0
#define CContextMenuManager__RemoveMenu_x                          0x95F810
#define CContextMenuManager__PopupMenu_x                           0x95F8D0
#define CContextMenuManager__Flush_x                               0x95F740
#define CContextMenuManager__GetMenu_x                             0x49B410
#define CContextMenuManager__CreateDefaultMenu_x                   0x72A570

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8EB140
#define CChatService__GetFriendName_x                              0x8EB150

// CComboWnd
#define CComboWnd__DeleteAll_x                                     0x95C090
#define CComboWnd__Draw_x                                          0x95B590
#define CComboWnd__GetCurChoice_x                                  0x95BED0
#define CComboWnd__GetListRect_x                                   0x95BA40
#define CComboWnd__GetTextRect_x                                   0x95C0F0
#define CComboWnd__InsertChoice_x                                  0x95BBD0
#define CComboWnd__SetColors_x                                     0x95BBA0
#define CComboWnd__SetChoice_x                                     0x95BEA0
#define CComboWnd__GetItemCount_x                                  0x95BEE0
#define CComboWnd__GetCurChoiceText_x                              0x95BF20
#define CComboWnd__GetChoiceText_x                                 0x95BEF0
#define CComboWnd__InsertChoiceAtIndex_x                           0x95BC60

// CContainerWnd
#define CContainerWnd__HandleCombine_x                             0x727F50
#define CContainerWnd__vftable_x                                   0xB225BC
#define CContainerWnd__SetContainer_x                              0x7294B0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x5530E0
#define CDisplay__PreZoneMainUI_x                                  0x5530F0
#define CDisplay__CleanGameUI_x                                    0x5584F0
#define CDisplay__GetClickedActor_x                                0x54B3E0
#define CDisplay__GetUserDefinedColor_x                            0x543A40
#define CDisplay__GetWorldFilePath_x                               0x54CE50
#define CDisplay__is3dON_x                                         0x548040
#define CDisplay__ReloadUI_x                                       0x552560
#define CDisplay__WriteTextHD2_x                                   0x547E30
#define CDisplay__TrueDistance_x                                   0x54EB10
#define CDisplay__SetViewActor_x                                   0x54AD00
#define CDisplay__GetFloorHeight_x                                 0x548100
#define CDisplay__SetRenderWindow_x                                0x546A60
#define CDisplay__ToggleScreenshotMode_x                           0x54A7D0

// CEditBaseWnd
#define CEditBaseWnd__SetSel_x                                     0x97EA60

// CEditWnd
#define CEditWnd__DrawCaret_x                                      0x962180
#define CEditWnd__EnsureCaretVisible_x                             0x964340
#define CEditWnd__GetCaretPt_x                                     0x9632F0
#define CEditWnd__GetCharIndexPt_x                                 0x9630A0
#define CEditWnd__GetDisplayString_x                               0x962F40
#define CEditWnd__GetHorzOffset_x                                  0x9617B0
#define CEditWnd__GetLineForPrintableChar_x                        0x964240
#define CEditWnd__GetSelStartPt_x                                  0x963350
#define CEditWnd__GetSTMLSafeText_x                                0x962D60
#define CEditWnd__PointFromPrintableChar_x                         0x963E70
#define CEditWnd__ReplaceSelection_x                               0x963AE0
#define CEditWnd__SelectableCharFromPoint_x                        0x963FE0
#define CEditWnd__SetEditable_x                                    0x963420
#define CEditWnd__SetWindowTextA_x                                 0x962AE0

// CEverQuest
#define CEverQuest__DoPercentConvert_x                             0x60BBC0
#define CEverQuest__ClickedPlayer_x                                0x5FDCF0
#define CEverQuest__CreateTargetIndicator_x                        0x61B280
#define CEverQuest__DeleteTargetIndicator_x                        0x61B310
#define CEverQuest__DoTellWindow_x                                 0x4E8630
#define CEverQuest__OutputTextToLog_x                              0x4E8900
#define CEverQuest__DropHeldItemOnGround_x                         0x5F2D30
#define CEverQuest__dsp_chat_x                                     0x4E8C90
#define CEverQuest__trimName_x                                     0x6173F0
#define CEverQuest__Emote_x                                        0x60C420
#define CEverQuest__EnterZone_x                                    0x6064C0
#define CEverQuest__GetBodyTypeDesc_x                              0x610CE0
#define CEverQuest__GetClassDesc_x                                 0x611320
#define CEverQuest__GetClassThreeLetterCode_x                      0x611920
#define CEverQuest__GetDeityDesc_x                                 0x619AD0
#define CEverQuest__GetLangDesc_x                                  0x611AE0
#define CEverQuest__GetRaceDesc_x                                  0x611300
#define CEverQuest__InterpretCmd_x                                 0x61A0A0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5F6F30
#define CEverQuest__LMouseUp_x                                     0x5F52C0
#define CEverQuest__RightClickedOnPlayer_x                         0x5F7810
#define CEverQuest__RMouseUp_x                                     0x5F6240
#define CEverQuest__SetGameState_x                                 0x5F2AC0
#define CEverQuest__UPCNotificationFlush_x                         0x6172F0
#define CEverQuest__IssuePetCommand_x                              0x612EE0
#define CEverQuest__ReportSuccessfulHeal_x                         0x60D140
#define CEverQuest__ReportSuccessfulHit_x                          0x60D770

// CGaugeWnd
// not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x739D60
#define CGaugeWnd__CalcLinesFillRect_x                             0x739DC0
#define CGaugeWnd__Draw_x                                          0x7393F0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF410
#define CGuild__GetGuildName_x                                     0x4AE450
#define CGuild__GetGuildIndex_x                                    0x4AE890

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton_x                               0x753F60

//CHotButton
#define CHotButton__SetButtonSize_x                                0x62CC90

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot_x                                 0x760F60
#define CInvSlotMgr__MoveItem_x                                    0x75FC80
#define CInvSlotMgr__SelectSlot_x                                  0x761030

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x75E500
#define CInvSlot__SliderComplete_x                                 0x75C260
#define CInvSlot__GetItemBase_x                                    0x75BBE0
#define CInvSlot__UpdateItem_x                                     0x75BD50

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x762AB0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x761C50
#define CInvSlotWnd__HandleLButtonUp_x                             0x762630

// CItemDisplayWnd
#define CItemDisplayWnd__SetSpell_x                                0x81CD80
#define CItemDisplayWnd__UpdateStrings_x                           0x771220
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x76AF00
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x76B410
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x771820
#define CItemDisplayWnd__AboutToShow_x                             0x770E60
#define CItemDisplayWnd__WndNotification_x                         0x772960
#define CItemDisplayWnd__RequestConvertItem_x                      0x7723D0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x76FEC0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x770C80

// CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8559D0

// CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x776E60

// CKeyRingWnd
#define CKeyRingWnd__ExecuteRightClick_x                           0x5196E0

// CLabel
#define CLabel__Draw_x                                             0x77C8A0

// CListWnd
#define CListWnd__CListWnd_x                                       0x934920
#define CListWnd__dCListWnd_x                                      0x934C40
#define CListWnd__vftable_x                                        0xB536A0
#define CListWnd__AddColumn_x                                      0x939090
#define CListWnd__AddColumn1_x                                     0x9390E0
#define CListWnd__AddLine_x                                        0x939470
#define CListWnd__AddString_x                                      0x939270
#define CListWnd__CalculateFirstVisibleLine_x                      0x938E50
#define CListWnd__CalculateVSBRange_x                              0x938C30
#define CListWnd__ClearSel_x                                       0x939C50
#define CListWnd__ClearAllSel_x                                    0x939CB0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x93A6B0
#define CListWnd__Compare_x                                        0x938560
#define CListWnd__Draw_x                                           0x934D70
#define CListWnd__DrawColumnSeparators_x                           0x937550
#define CListWnd__DrawHeader_x                                     0x9379B0
#define CListWnd__DrawItem_x                                       0x937EA0
#define CListWnd__DrawLine_x                                       0x9376B0
#define CListWnd__DrawSeparator_x                                  0x9375F0
#define CListWnd__EnableLine_x                                     0x936E30
#define CListWnd__EnsureVisible_x                                  0x93A5E0
#define CListWnd__ExtendSel_x                                      0x939B80
#define CListWnd__GetColumnTooltip_x                               0x936970
#define CListWnd__GetColumnMinWidth_x                              0x9369E0
#define CListWnd__GetColumnWidth_x                                 0x9368E0
#define CListWnd__GetCurSel_x                                      0x936270
#define CListWnd__GetItemAtPoint_x                                 0x9370A0
#define CListWnd__GetItemAtPoint1_x                                0x937110
#define CListWnd__GetItemData_x                                    0x9362F0
#define CListWnd__GetItemHeight_x                                  0x9366B0
#define CListWnd__GetItemIcon_x                                    0x936480
#define CListWnd__GetItemRect_x                                    0x936F20
#define CListWnd__GetItemText_x                                    0x936330
#define CListWnd__GetSelList_x                                     0x939D00
#define CListWnd__GetSeparatorRect_x                               0x937350
#define CListWnd__InsertLine_x                                     0x939860
#define CListWnd__RemoveLine_x                                     0x9399B0
#define CListWnd__SetColors_x                                      0x938C00
#define CListWnd__SetColumnJustification_x                         0x938930
#define CListWnd__SetColumnLabel_x                                 0x939210
#define CListWnd__SetColumnWidth_x                                 0x938850
#define CListWnd__SetCurSel_x                                      0x939AC0
#define CListWnd__SetItemColor_x                                   0x93A2A0
#define CListWnd__SetItemData_x                                    0x93A260
#define CListWnd__SetItemText_x                                    0x939E70
#define CListWnd__ShiftColumnSeparator_x                           0x9389F0
#define CListWnd__Sort_x                                           0x9386E0
#define CListWnd__ToggleSel_x                                      0x939AF0
#define CListWnd__SetColumnsSizable_x                              0x938AA0
#define CListWnd__SetItemWnd_x                                     0x93A120
#define CListWnd__GetItemWnd_x                                     0x9364D0
#define CListWnd__SetItemIcon_x                                    0x939EF0
#define CListWnd__CalculateCustomWindowPositions_x                 0x938F50
#define CListWnd__SetVScrollPos_x                                  0x938830

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd_x                                 0x791FC0

// MapViewMap
#define MapViewMap__MapViewMap_x                                   0x78D4B0
#define MapViewMap__dMapViewMap_x                                  0x78D600
#define MapViewMap__vftable_x                                      0xB29C00
#define MapViewMap__Clear_x                                        0x78DE30
#define MapViewMap__SaveEx_x                                       0x7911F0
#define MapViewMap__SetZoom_x                                      0x7958B0
#define MapViewMap__HandleLButtonDown_x                            0x78D710
#define MapViewMap__GetWorldCoordinates_x                          0x7906D0

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7B22B0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7B2B90
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7B30C0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7B6030
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7B0E20
#define CMerchantWnd__SelectBuySellSlot_x                          0x7BBBE0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7B1EC0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8B8F10
#define CPacketScrambler__hton_x                                   0x8B8F00

// CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x957BC0
#define CSidlManagerBase__CreatePageWnd_x                          0x9573C0
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x953650
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9535E0
#define CSidlManagerBase__FindAnimation1_x                         0x953830
#define CSidlManagerBase__FindScreenPieceTemplate_x                0x953C40
#define CSidlManagerBase__FindScreenPieceTemplate1_x               0x953A30
#define CSidlManagerBase__CreateLabel_x                            0x813F80
#define CSidlManagerBase__CreateXWndFromTemplate_x                 0x956BA0
#define CSidlManagerBase__CreateXWndFromTemplate1_x                0x956D70
#define CSidlManagerBase__CreateXWnd_x                             0x813EB0

// CSidlManager
#define CSidlManager__CreateHotButtonWnd_x                         0x814470

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange_x                        0x950340
#define CSidlScreenWnd__CalculateVSBRange_x                        0x950240
#define CSidlScreenWnd__ConvertToRes_x                             0x9795B0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x94FCD0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x94F9C0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x94FA90
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x94FB60
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9507E0
#define CSidlScreenWnd__EnableIniStorage_x                         0x950CB0
#define CSidlScreenWnd__GetChildItem_x                             0x950C30
#define CSidlScreenWnd__GetSidlPiece_x                             0x9509D0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x940410
#define CSidlScreenWnd__Init1_x                                    0x94F5C0
#define CSidlScreenWnd__LoadIniInfo_x                              0x950D00
#define CSidlScreenWnd__LoadIniListWnd_x                           0x951810
#define CSidlScreenWnd__LoadSidlScreen_x                           0x94E9E0
#define CSidlScreenWnd__m_layoutCopy_x                             0x1601A58
#define CSidlScreenWnd__StoreIniInfo_x                             0x9513A0
#define CSidlScreenWnd__StoreIniVis_x                              0x9516F0
#define CSidlScreenWnd__vftable_x                                  0xB54058
#define CSidlScreenWnd__WndNotification_x                          0x9506F0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6910F0
#define CSkillMgr__GetSkillCap_x                                   0x6912D0
#define CSkillMgr__GetNameToken_x                                  0x690870
#define CSkillMgr__IsActivatedSkill_x                              0x6909B0
#define CSkillMgr__IsCombatSkill_x                                 0x6908F0

// CSliderWnd
#define CSliderWnd__GetValue_x                                     0x960580
#define CSliderWnd__SetValue_x                                     0x9603F0
#define CSliderWnd__SetNumTicks_x                                  0x960450

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet_x                               0x81A130

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x968D90
#define CStmlWnd__CalculateHSBRange_x                              0x969EF0
#define CStmlWnd__CalculateVSBRange_x                              0x969E70
#define CStmlWnd__CanBreakAtCharacter_x                            0x96E230
#define CStmlWnd__FastForwardToEndOfTag_x                          0x96EEC0
#define CStmlWnd__ForceParseNow_x                                  0x9693D0
#define CStmlWnd__GetNextTagPiece_x                                0x96E190
#define CStmlWnd__GetSTMLText_x                                    0x5090D0
#define CStmlWnd__GetVisibleText_x                                 0x9693F0
#define CStmlWnd__InitializeWindowVariables_x                      0x96ED10
#define CStmlWnd__MakeStmlColorTag_x                               0x968400
#define CStmlWnd__MakeWndNotificationTag_x                         0x968470
#define CStmlWnd__SetSTMLText_x                                    0x9674B0
#define CStmlWnd__StripFirstSTMLLines_x                            0x96FF90
#define CStmlWnd__UpdateHistoryString_x                            0x96F0D0

// CTabWnd
#define CTabWnd__Draw_x                                            0x966600
#define CTabWnd__DrawCurrentPage_x                                 0x966D30
#define CTabWnd__DrawTab_x                                         0x966A50
#define CTabWnd__GetCurrentPage_x                                  0x965E00
#define CTabWnd__GetCurrentTabIndex_x                              0x965DF0
#define CTabWnd__GetPageFromTabIndex_x                             0x966990
#define CTabWnd__GetPageInnerRect_x                                0x966040
#define CTabWnd__GetTabInnerRect_x                                 0x965F80
#define CTabWnd__GetTabRect_x                                      0x965E30
#define CTabWnd__InsertPage_x                                      0x966250
#define CTabWnd__RemovePage_x                                      0x9663C0
#define CTabWnd__SetPage_x                                         0x9660C0
#define CTabWnd__SetPageRect_x                                     0x966540
#define CTabWnd__UpdatePage_x                                      0x966910

// CPageWnd
#define CPageWnd__FlashTab_x                                       0x9659B0
#define CPageWnd__GetTabText_x                                     0x777230
#define CPageWnd__SetTabText_x                                     0x965950


// CTextOverlay
#define CTextOverlay__DisplayText_x                                0x4A8E50

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x93D320
#define CTextureFont__DrawWrappedText1_x                           0x93D250
#define CTextureFont__DrawWrappedText2_x                           0x93D370
#define CTextureFont__GetTextExtent_x                              0x93D4E0

// CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6C45D0
#define CHtmlComponentWnd__ValidateUri_x                           0x755950
#define CHtmlWnd__SetClientCallbacks_x                             0x631D10
#define CHtmlWnd__AddObserver_x                                    0x631D30
#define CHtmlWnd__RemoveObserver_x                                 0x631D90
#define Window__getProgress_x                                      0x86E1A0
#define Window__getStatus_x                                        0x86E1C0
#define Window__getURI_x                                           0x86E1D0

// CXMLDataManager
#define CXMLDataManager__GetXMLData_x                              0x9763C0

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead_x                             0x92A5B0

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr_x                                             0x4E8280
#define CXStr__CXStr1_x                                            0xA01590
#define CXStr__CXStr3_x                                            0x90C200
#define CXStr__dCXStr_x                                            0x4786B0
#define CXStr__operator_equal_x                                    0x90C430
#define CXStr__operator_equal1_x                                   0x90C470
#define CXStr__operator_plus_equal1_x                              0x90CF00
#define CXStr__SetString_x                                         0x90EDF0
#define CXStr__operator_char_p_x                                   0x90C940
#define CXStr__GetChar_x                                           0x90E720
#define CXStr__Delete_x                                            0x90DFF0
#define CXStr__GetUnicode_x                                        0x90E790
#define CXStr__GetLength_x                                         0x4A8C00
#define CXStr__Mid_x                                               0x47D400
#define CXStr__Insert_x                                            0x90E7F0
#define CXStr__FindNext_x                                          0x90E460
#define CXStr__gFreeLists_x                                        0xCAF580
#define CXStr__gCXStrAccess_x                                      0x160117C

// CTileLayoutWnd
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x95E840

// CXWnd
#define CXWnd__BringToTop_x                                        0x943B80
#define CXWnd__Center_x                                            0x943700
#define CXWnd__ClrFocus_x                                          0x943520
#define CXWnd__Destroy_x                                           0x9435C0
#define CXWnd__DoAllDrawing_x                                      0x93FBD0
#define CXWnd__DrawChildren_x                                      0x93FBA0
#define CXWnd__DrawColoredRect_x                                   0x940020
#define CXWnd__DrawTooltip_x                                       0x93E6F0
#define CXWnd__DrawTooltipAtPoint_x                                0x93E7B0
#define CXWnd__GetBorderFrame_x                                    0x93FE80
#define CXWnd__GetChildItem_x                                      0x943D90
#define CXWnd__GetChildWndAt_x                                     0x943C20
#define CXWnd__GetClientClipRect_x                                 0x941E40
#define CXWnd__GetRelativeRect_x                                   0x942180
#define CXWnd__GetScreenClipRect_x                                 0x941F10
#define CXWnd__GetScreenRect_x                                     0x9420C0
#define CXWnd__GetTooltipRect_x                                    0x940070
#define CXWnd__GetWindowTextA_x                                    0x49CAF0
#define CXWnd__IsActive_x                                          0x940780
#define CXWnd__IsDescendantOf_x                                    0x942AA0
#define CXWnd__IsReallyVisible_x                                   0x942AD0
#define CXWnd__IsType_x                                            0x944280
#define CXWnd__Minimize_x                                          0x9431B0
#define CXWnd__Move_x                                              0x942B40
#define CXWnd__Move1_x                                             0x942BF0
#define CXWnd__ProcessTransition_x                                 0x9436B0
#define CXWnd__Refade_x                                            0x942EB0
#define CXWnd__Resize_x                                            0x943140
#define CXWnd__Right_x                                             0x943940
#define CXWnd__SetFocus_x                                          0x9434E0
#define CXWnd__SetFont_x                                           0x943550
#define CXWnd__SetKeyTooltip_x                                     0x9440A0
#define CXWnd__SetMouseOver_x                                      0x940FC0
#define CXWnd__SetParent_x                                         0x942840
#define CXWnd__StartFade_x                                         0x942980
#define CXWnd__vftable_x                                           0xB53AE4
#define CXWnd__CXWnd_x                                             0x93D800
#define CXWnd__dCXWnd_x                                            0x93DCF0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x97A630

// CXWndManager
#define CXWndManager__DrawCursor_x                                 0x946AA0
#define CXWndManager__DrawWindows_x                                0x946AC0
#define CXWndManager__GetKeyboardFlags_x                           0x949210
#define CXWndManager__HandleKeyboardMsg_x                          0x948DC0
#define CXWndManager__RemoveWnd_x                                  0x949430
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9499A0

// CDBStr
#define CDBStr__GetString_x                                        0x5429F0

// CharacterZoneClient
#define CharacterZoneClient__CanUseItem_x                          0x4D96F0
#define CharacterZoneClient__CastSpell_x                           0x4BBB40
#define CharacterZoneClient__Cur_HP_x                              0x4D1CC0
#define CharacterZoneClient__Cur_Mana_x                            0x4D93E0
#define CharacterZoneClient__GetAdjustedSkill_x                    0x4D4A40
#define CharacterZoneClient__GetBaseSkill_x                        0x4D59E0
#define CharacterZoneClient__GetCastingTimeModifier_x              0x4BEB80
#define CharacterZoneClient__GetEnduranceRegen_x                   0x4DF780
#define CharacterZoneClient__GetFocusCastingTimeModifier_x         0x4B25E0
#define CharacterZoneClient__GetFocusRangeModifier_x               0x4B2730
#define CharacterZoneClient__GetHPRegen_x                          0x4DF180
#define CharacterZoneClient__GetManaRegen_x                        0x4DFBC0
#define CharacterZoneClient__GetPCSpellAffect_x                    0x4BF8D0
#define CharacterZoneClient__Max_Endurance_x                       0x657E40
#define CharacterZoneClient__Max_HP_x                              0x4D1AF0
#define CharacterZoneClient__Max_Mana_x                            0x657C40
#define CharacterZoneClient__SpellDuration_x                       0x4BF400
#define CharacterZoneClient__TotalEffect_x                         0x4C4EF0
#define CharacterZoneClient__UseSkill_x                            0x4E19A0

// ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8D80D0

// PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x66E350

// PcClient
#define PcClient__PcClient_x                                       0x64E4D0
#define PcClient__GetConLevel_x                                    0x650D80

// CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B97A0
#define CCharacterListWnd__EnterWorld_x                            0x4B91E0
#define CCharacterListWnd__Quit_x                                  0x4B8F30
#define CCharacterListWnd__UpdateList_x                            0x4B9370

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x632ED0
#define EQ_Item__CreateItemTagString_x                             0x8B24F0
#define EQ_Item__IsStackable_x                                     0x8B7170
#define EQ_Item__GetImageNum_x                                     0x8B3F90
#define EQ_Item__CreateItemClient_x                                0x632110
#define EQ_Item__GetItemValue_x                                    0x8B5350
#define EQ_Item__ValueSellMerchant_x                               0x8B8AF0
#define EQ_Item__IsKeyRingItem_x                                   0x8B6A70
#define EQ_Item__CanGoInBag_x                                      0x632FF0
#define EQ_Item__IsEmpty_x                                         0x8B65E0
#define EQ_Item__GetMaxItemCount_x                                 0x8B5770
#define EQ_Item__GetHeldItem_x                                     0x8B3E60
#define EQ_Item__GetAugmentFitBySlot_x                             0x8B1D30
#define ItemClient__ItemClient_x                                   0x5B2A50
#define ItemClient__dItemClient_x                                  0x632060

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar_x                              0x561600
#define EQ_LoadingS__Array_x                                       0xC38C60

// EQ_PC
#define EQ_PC__GetAlternateAbilityId_x                             0x8C1F10
#define EQ_PC__GetCombatAbility_x                                  0x8C2580
#define EQ_PC__GetCombatAbilityTimer_x                             0x8C25F0
#define EQ_PC__GetItemRecastTimer_x                                0x65A7F0
#define EQ_PC__HasLoreItem_x                                       0x651590
#define EQ_PC__AlertInventoryChanged_x                             0x6506C0
#define EQ_PC__GetPcZoneClient_x                                   0x67CD60
#define EQ_PC__RemoveMyAffect_x                                    0x65DA20
#define EQ_PC__GetKeyRingItems_x                                   0x8C2E80
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8C2C10
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8C3180

// EQItemList
#define EQItemList__EQItemList_x                                   0x5BABC0
#define EQItemList__add_object_x                                   0x5E85B0
#define EQItemList__add_item_x                                     0x5BB120
#define EQItemList__delete_item_x                                  0x5BB170
#define EQItemList__FreeItemList_x                                 0x5BB070

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53F590

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite_x                         0x66FBD0
#define EQPlayer__dEQPlayer_x                                      0x662EE0
#define EQPlayer__DoAttack_x                                       0x677A00
#define EQPlayer__EQPlayer_x                                       0x6635A0
#define EQPlayer__SetNameSpriteState_x                             0x6678B0
#define EQPlayer__SetNameSpriteTint_x                              0x668780
#define PlayerBase__HasProperty_j_x                                0x9A9230
#define EQPlayer__IsTargetable_x                                   0x9A96D0
#define EQPlayer__CanSee_x                                         0x9A9530
#define EQPlayer__CanSee1_x                                        0x9A9600
#define PlayerBase__GetVisibilityLineSegment_x                     0x9A92F0

// PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67A800
#define PlayerZoneClient__GetLevel_x                               0x67CDA0
#define PlayerZoneClient__IsValidTeleport_x                        0x5E9720
#define PlayerZoneClient__LegalPlayerRace_x                        0x55A3B0

// EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x672920
#define EQPlayerManager__GetSpawnByName_x                          0x6729D0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x672A60

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x636640
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6366C0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x636700
#define KeypressHandler__ClearCommandStateArray_x                  0x637B10
#define KeypressHandler__HandleKeyDown_x                           0x637B30
#define KeypressHandler__HandleKeyUp_x                             0x637BD0
#define KeypressHandler__SaveKeymapping_x                          0x638020

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8D6130

// StringTable
#define StringTable__getString_x                                   0x8D1100

// PcZoneClient
#define PcZoneClient__doCombatAbility_x                            0x65A270
#define PcZoneClient__DestroyHeldItemOrMoney_x                     0x658780
#define PcZoneClient__GetPcSkillLimit_x                            0x65D690
#define PcZoneClient__RemovePetEffect_x                            0x65DCC0
#define PcZoneClient__HasAlternateAbility_x                        0x657A70
#define PcZoneClient__CanEquipItem_x                               0x658120
#define PcZoneClient__GetItemByID_x                                0x65AC60
#define PcZoneClient__GetItemByItemClass_x                         0x65ADB0
#define PcZoneClient__RemoveBuffEffect_x                           0x65DCE0
#define PcZoneClient__BandolierSwap_x                              0x658D30
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65A790

// Doors
#define EQSwitch__UseSwitch_x                                      0x5EE240

// IconCache
#define IconCache__GetIcon_x                                       0x72F610

// CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7270F0
#define CContainerMgr__CloseContainer_x                            0x7273C0
#define CContainerMgr__OpenExperimentContainer_x                   0x727E40

// CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7E62F0

// CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62B0B0

// CLootWnd
#define CLootWnd__LootAll_x                                        0x784370
#define CLootWnd__RequestLootSlot_x                                0x7835A0

// EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x587EF0
#define EQ_Spell__SpellAffects_x                                   0x588360
#define EQ_Spell__SpellAffectBase_x                                0x588120
#define EQ_Spell__IsStackable_x                                    0x4C9710
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9560
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6AF0
#define EQ_Spell__IsSPAStacking_x                                  0x5891B0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5886C0
#define EQ_Spell__IsNoRemove_x                                     0x4C96F0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5891C0
#define __IsResEffectSpell_x                                       0x4C8970

// EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACFE0

// EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8E06C0

// CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x82D550
#define CTargetWnd__WndNotification_x                              0x82CD90
#define CTargetWnd__RefreshTargetBuffs_x                           0x82D060
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x82BEF0

// CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x831B90

// CTaskManager
#define CTaskManager__GetEntry_x                                   0x53CFB0
#define CTaskManager__HandleMessage_x                              0x53B440
#define CTaskManager__GetTaskStatus_x                              0x53D060
#define CTaskManager__GetElementDescription_x                      0x53D0E0

// EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5830C0
#define EqSoundManager__PlayScriptMp3_x                            0x583380
#define EqSoundManager__SoundAssistPlay_x                          0x694FE0
#define EqSoundManager__WaveInstancePlay_x                         0x694550

// CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52E6B0

// CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x964E60

// CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x569120
#define CAltAbilityData__GetMercMaxRank_x                          0x5690B0
#define CAltAbilityData__GetMaxRank_x                              0x55E510

// CTargetRing
#define CTargetRing__Cast_x                                        0x6291D0

// CharacterBase
#define CharacterBase__CreateItemGlobalIndex_x                     0x515CF0
#define CharacterBase__CreateItemIndex_x                           0x6312C0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8E8CF0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8E8D50
#define CharacterBase__GetItemPossession_x                         0x501A30
#define CharacterBase__GetMemorizedSpell_x                         0x4C9540
#define CharacterBase__IsExpansionFlag_x                           0x5B4690

// CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x70E0A0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x70E8D0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x70E980

// messages
#define msg_spell_worn_off_x                                       0x5ACC00
#define msg_new_text_x                                             0x5A15C0
#define __msgTokenTextParam_x                                      0x5AEE90
#define msgTokenText_x                                             0x5AF0E0

// SpellManager
#define SpellManager__vftable_x                                    0xAFC150
#define SpellManager__SpellManager_x                               0x698300
#define Spellmanager__LoadTextSpells_x                             0x698BF0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6984D0

// CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x 0x9AD0F0

// ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8E1060
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8E12E0

// CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x77CBE0

// CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x72B810
#define CCursorAttachment__AttachToCursor1_x                       0x72B850
#define CCursorAttachment__Deactivate_x                            0x72C840

// CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9750E0
#define CEQSuiteTextureLoader__GetTexture_x                        0x974DA0

// CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x513390
#define CFindItemWnd__WndNotification_x                            0x513E70
#define CFindItemWnd__Update_x                                     0x5149E0
#define CFindItemWnd__PickupSelectedItem_x                         0x512BE0

// IString
#define IString__Append_x                                          0x503250

// Camera
#define CDisplay__cameraType_x                                     0xE12258
#define EverQuest__Cameras_x                                       0xECD534

// LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51BA80
#define LootFiltersManager__GetItemFilterData_x                    0x51B380
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51B3B0
#define LootFiltersManager__SetItemLootFilter_x                    0x51B5D0

// COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7D40A0

// CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9B2C80
#define CResolutionHandler__GetWindowedStyle_x                     0x68FC00

// CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x723DA0

// CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8F65F0
#define CDistillerInfo__Instance_x                                 0x8F6590

// CGroupWnd
#define CGroupWnd__WndNotification_x                               0x742CF0
#define CGroupWnd__UpdateDisplay_x                                 0x742040

// ItemBase
#define ItemBase__IsLore_x                                         0x8B6B20
#define ItemBase__IsLoreEquipped_x                                 0x8B6BA0

// EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5E8510
#define EQPlacedItemManager__GetItemByGuid_x                       0x5E8650
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5E86B0

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x685470
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x688DF0

// CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x509740

// FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F5DA0
#define FactionManagerClient__HandleFactionMessage_x               0x4F6410
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F6A10
#define FactionManagerClient__GetMaxFaction_x                      0x4F6A2F
#define FactionManagerClient__GetMinFaction_x                      0x4F69E0

// BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x501A00

// ArrayClass
#define ArrayClass__DeleteElement_x                                0x93C370

// AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE00

// ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x501C60

// MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x5685C0

// CTargetManager
#define CTargetManager__Get_x                                      0x69BB60

// RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x685470

// CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8C10

// EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BB010

// EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF6ABC8

// KeyCombo
#define KeyCombo__GetTextDescription_x                             0x926B20

//
// EQGraphicsDX9.dll offsets (maybe this should go in eqgraphics.h?)
//

#define __eqgraphics_fopen_x                                       0x10147468
#define CParticleSystem__Render_x                                  0x10071190
