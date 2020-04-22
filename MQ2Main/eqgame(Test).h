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
#define __ExpectedVersionDate                                     "Apr 21 2020"
#define __ExpectedVersionTime                                     "10:40:35"
#define __ActualVersionDate_x                                      0xB1A3E8
#define __ActualVersionTime_x                                      0xB1A3DC
#define __ActualVersionBuild_x                                     0xB060DC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x63CCC0
#define __MemChecker1_x                                            0x911280
#define __MemChecker2_x                                            0x6CBAA0
#define __MemChecker3_x                                            0x6CB9F0
#define __MemChecker4_x                                            0x867280
#define __EncryptPad0_x                                            0xC524E0
#define __EncryptPad1_x                                            0xCB0648
#define __EncryptPad2_x                                            0xC62D78
#define __EncryptPad3_x                                            0xC62978
#define __EncryptPad4_x                                            0xCA0BF8
#define __EncryptPad5_x                                            0xF73C7C
#define __AC1_x                                                    0x823EE6
#define __AC2_x                                                    0x5F6ABF
#define __AC3_x                                                    0x5FE10F
#define __AC4_x                                                    0x6020D0
#define __AC5_x                                                    0x60837F
#define __AC6_x                                                    0x60C876
#define __AC7_x                                                    0x5F6530
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x70AF0

// Direct Input
#define DI8__Main_x                                                0xF73C9C
#define DI8__Keyboard_x                                            0xF73CA0
#define DI8__Mouse_x                                               0xF73CB8
#define DI8__Mouse_Copy_x                                          0xECCE6C
#define DI8__Mouse_Check_x                                         0xF717D0
#define __AutoSkillArray_x                                         0xECDD84
#define __Attack_x                                                 0xF6BBAB
#define __Autofire_x                                               0xF6BBAC
#define __BindList_x                                               0xC40F30
#define g_eqCommandStates_x                                        0xC41CB0
#define __Clicks_x                                                 0xECCF24
#define __CommandList_x                                            0xC42870
#define __CurrentMapLabel_x                                        0xF84674
#define __CurrentSocial_x                                          0xC2A7CC
#define __DoAbilityList_x                                          0xF036CC
#define __do_loot_x                                                0x5C2200
#define __DrawHandler_x                                            0x16039F0
#define __GroupCount_x                                             0xEC7EC2
#define __Guilds_x                                                 0xECBDB0
#define __gWorld_x                                                 0xEC7E50
#define __HWnd_x                                                   0xF73CBC
#define __heqmain_x                                                0xF73C64
#define __InChatMode_x                                             0xECCE54
#define __LastTell_x                                               0xECEDC8
#define __LMouseHeldTime_x                                         0xECCF90
#define __Mouse_x                                                  0xF73C88
#define __MouseLook_x                                              0xECCEEA
#define __MouseEventTime_x                                         0xF6C68C
#define __gpbCommandEvent_x                                        0xEC80C0
#define __NetStatusToggle_x                                        0xECCEED
#define __PCNames_x                                                0xECE374
#define __RangeAttackReady_x                                       0xECE068
#define __RMouseHeldTime_x                                         0xECCF8C
#define __RunWalkState_x                                           0xECCE58
#define __ScreenMode_x                                             0xE131B4
#define __ScreenX_x                                                0xECCE0C
#define __ScreenY_x                                                0xECCE08
#define __ScreenXMax_x                                             0xECCE10
#define __ScreenYMax_x                                             0xECCE14
#define __ServerHost_x                                             0xEC59EB
#define __ServerName_x                                             0xF0368C
#define __ShiftKeyDown_x                                           0xECD4E4
#define __ShowNames_x                                              0xECE224
#define EverQuestInfo__bSocialChanged_x                            0xF03714
#define __Socials_x                                                0xF0378C
#define __SubscriptionType_x                                       0xFC8B80
#define __TargetAggroHolder_x                                      0xF87028
#define __ZoneType_x                                               0xECD2E8
#define __GroupAggro_x                                             0xF87068
#define __LoginName_x                                              0xF743F4
#define __Inviter_x                                                0xF6BB28
#define __AttackOnAssist_x                                         0xECE1E0
#define __UseTellWindows_x                                         0xECE510
#define __gfMaxZoomCameraDistance_x                                0xB0FD30
#define __gfMaxCameraDistance_x                                    0xB3C154
#define __pulAutoRun_x                                             0xECCF08
#define __pulForward_x                                             0xECE548
#define __pulBackward_x                                            0xECE54C
#define __pulTurnRight_x                                           0xECE550
#define __pulTurnLeft_x                                            0xECE554
#define __pulStrafeLeft_x                                          0xECE558
#define __pulStrafeRight_x                                         0xECE55C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEC8148
#define instEQZoneInfo_x                                           0xECD0E0
#define pinstActiveBanker_x                                        0xEC5850
#define pinstActiveCorpse_x                                        0xEC5844
#define pinstActiveGMaster_x                                       0xEC584C
#define pinstActiveMerchant_x                                      0xEC5840
#define pinstAltAdvManager_x                                       0xE14378
#define pinstBandageTarget_x                                       0xEC5864
#define pinstCamActor_x                                            0xE131A4
#define pinstCDBStr_x                                              0xE13094
#define pinstCDisplay_x                                            0xEC7D0C
#define pinstCEverQuest_x                                          0xF73CB4
#define pinstEverQuestInfo_x                                       0xECCE00
#define pinstCharData_x                                            0xEC7EAC
#define pinstCharSpawn_x                                           0xEC58B0
#define pinstControlledMissile_x                                   0xEC5AF4
#define pinstControlledPlayer_x                                    0xEC58B0
#define pinstCResolutionHandler_x                                  0x1603C20
#define pinstCSidlManager_x                                        0x1602BB8
#define pinstCXWndManager_x                                        0x1602BB4
#define instDynamicZone_x                                          0xECBC88
#define pinstDZMember_x                                            0xECBD98
#define pinstDZTimerInfo_x                                         0xECBD9C
#define pinstEqLogin_x                                             0xF73D40
#define instEQMisc_x                                               0xE12FD8
#define pinstEQSoundManager_x                                      0xE15348
#define pinstEQSpellStrings_x                                      0xCD59E0
#define instExpeditionLeader_x                                     0xECBCD2
#define instExpeditionName_x                                       0xECBD12
#define pinstGroup_x                                               0xEC7EBE
#define pinstImeManager_x                                          0x1602BB0
#define pinstLocalPlayer_x                                         0xEC583C
#define pinstMercenaryData_x                                       0xF6E184
#define pinstMercenaryStats_x                                      0xF87174
#define pinstModelPlayer_x                                         0xEC5858
#define pinstPCData_x                                              0xEC7EAC
#define pinstSkillMgr_x                                            0xF702E8
#define pinstSpawnManager_x                                        0xF6ED90
#define pinstSpellManager_x                                        0xF70528
#define pinstSpellSets_x                                           0xF647D4
#define pinstStringTable_x                                         0xEC80B0
#define pinstSwitchManager_x                                       0xEC56E8
#define pinstTarget_x                                              0xEC58A4
#define pinstTargetObject_x                                        0xEC58E0
#define pinstTargetSwitch_x                                        0xEC5D04
#define pinstTaskMember_x                                          0xE12E68
#define pinstTrackTarget_x                                         0xEC58B8
#define pinstTradeTarget_x                                         0xEC5854
#define instTributeActive_x                                        0xE12FF9
#define pinstViewActor_x                                           0xE131A0
#define pinstWorldData_x                                           0xEC5D00
#define pinstZoneAddr_x                                            0xECD380
#define pinstPlayerPath_x                                          0xF6EE28
#define pinstTargetIndicator_x                                     0xF70790
#define EQObject_Top_x                                             0xEC5838
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE134AC
#define pinstCAchievementsWnd_x                                    0xE139BC
#define pinstCActionsWnd_x                                         0xE134F4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE131F4
#define pinstCAdvancedLootWnd_x                                    0xE13188
#define pinstCAdventureLeaderboardWnd_x                            0xF7DE48
#define pinstCAdventureRequestWnd_x                                0xF7DEF8
#define pinstCAdventureStatsWnd_x                                  0xF7DFA8
#define pinstCAggroMeterWnd_x                                      0xE131E8
#define pinstCAlarmWnd_x                                           0xE13164
#define pinstCAlertHistoryWnd_x                                    0xE13250
#define pinstCAlertStackWnd_x                                      0xE1318C
#define pinstCAlertWnd_x                                           0xE131C4
#define pinstCAltStorageWnd_x                                      0xF7E308
#define pinstCAudioTriggersWindow_x                                0xCC7D10
#define pinstCAuraWnd_x                                            0xE13190
#define pinstCAvaZoneWnd_x                                         0xE13260
#define pinstCBandolierWnd_x                                       0xE131E4
#define pinstCBankWnd_x                                            0xE1322C
#define pinstCBarterMerchantWnd_x                                  0xF7F548
#define pinstCBarterSearchWnd_x                                    0xF7F5F8
#define pinstCBarterWnd_x                                          0xF7F6A8
#define pinstCBazaarConfirmationWnd_x                              0xE13168
#define pinstCBazaarSearchWnd_x                                    0xE134B0
#define pinstCBazaarWnd_x                                          0xE13138
#define pinstCBlockedBuffWnd_x                                     0xE131A8
#define pinstCBlockedPetBuffWnd_x                                  0xE131DC
#define pinstCBodyTintWnd_x                                        0xE13978
#define pinstCBookWnd_x                                            0xE13210
#define pinstCBreathWnd_x                                          0xE134C0
#define pinstCBuffWindowNORMAL_x                                   0xE1317C
#define pinstCBuffWindowSHORT_x                                    0xE13180
#define pinstCBugReportWnd_x                                       0xE13224
#define pinstCButtonWnd_x                                          0x1602E20
#define pinstCCastingWnd_x                                         0xE13204
#define pinstCCastSpellWnd_x                                       0xE134B4
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE13990
#define pinstCChatWindowManager_x                                  0xF80168
#define pinstCClaimWnd_x                                           0xF802C0
#define pinstCColorPickerWnd_x                                     0xE13478
#define pinstCCombatAbilityWnd_x                                   0xE13150
#define pinstCCombatSkillsSelectWnd_x                              0xE139A0
#define pinstCCompassWnd_x                                         0xE13570
#define pinstCConfirmationDialog_x                                 0xF851C0
#define pinstCContainerMgr_x                                       0xE1398C
#define pinstCContextMenuManager_x                                 0x1602B70
#define pinstCCursorAttachment_x                                   0xE131F8
#define pinstCDynamicZoneWnd_x                                     0xF80888
#define pinstCEditLabelWnd_x                                       0xE13178
#define pinstCEQMainWnd_x                                          0xF80AD0
#define pinstCEventCalendarWnd_x                                   0xE134A8
#define pinstCExtendedTargetWnd_x                                  0xE131D8
#define pinstCFacePick_x                                           0xE139B0
#define pinstCFactionWnd_x                                         0xE13130
#define pinstCFellowshipWnd_x                                      0xF80CD0
#define pinstCFileSelectionWnd_x                                   0xE13474
#define pinstCFindItemWnd_x                                        0xE139B4
#define pinstCFindLocationWnd_x                                    0xF80E28
#define pinstCFriendsWnd_x                                         0xE139AC
#define pinstCGemsGameWnd_x                                        0xE139C8
#define pinstCGiveWnd_x                                            0xE13160
#define pinstCGroupSearchFiltersWnd_x                              0xE13208
#define pinstCGroupSearchWnd_x                                     0xF81220
#define pinstCGroupWnd_x                                           0xF812D0
#define pinstCGuildBankWnd_x                                       0xECE1C4
#define pinstCGuildCreationWnd_x                                   0xF81430
#define pinstCGuildMgmtWnd_x                                       0xF814E0
#define pinstCharacterCreation_x                                   0xE139A4
#define pinstCHelpWnd_x                                            0xE13158
#define pinstCHeritageSelectionWnd_x                               0xE139C4
#define pinstCHotButtonWnd_x                                       0xF83638
#define pinstCHotButtonWnd1_x                                      0xF83638
#define pinstCHotButtonWnd2_x                                      0xF8363C
#define pinstCHotButtonWnd3_x                                      0xF83640
#define pinstCHotButtonWnd4_x                                      0xF83644
#define pinstCIconSelectionWnd_x                                   0xE131EC
#define pinstCInspectWnd_x                                         0xE131E0
#define pinstCInventoryWnd_x                                       0xE13198
#define pinstCInvSlotMgr_x                                         0xE134BC
#define pinstCItemDisplayManager_x                                 0xF83BC8
#define pinstCItemExpTransferWnd_x                                 0xF83CF8
#define pinstCItemOverflowWnd_x                                    0xE134B8
#define pinstCJournalCatWnd_x                                      0xE13498
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE1325C
#define pinstCKeyRingWnd_x                                         0xE13200
#define pinstCLargeDialogWnd_x                                     0xF85E40
#define pinstCLayoutCopyWnd_x                                      0xF84048
#define pinstCLFGuildWnd_x                                         0xF840F8
#define pinstCLoadskinWnd_x                                        0xE13140
#define pinstCLootFiltersCopyWnd_x                                 0xCE4370
#define pinstCLootFiltersWnd_x                                     0xE13194
#define pinstCLootSettingsWnd_x                                    0xE131D4
#define pinstCLootWnd_x                                            0xE13490
#define pinstCMailAddressBookWnd_x                                 0xE134C4
#define pinstCMailCompositionWnd_x                                 0xE134A0
#define pinstCMailIgnoreListWnd_x                                  0xE134C8
#define pinstCMailWnd_x                                            0xE1347C
#define pinstCManageLootWnd_x                                      0xE14828
#define pinstCMapToolbarWnd_x                                      0xE1315C
#define pinstCMapViewWnd_x                                         0xE13134
#define pinstCMarketplaceWnd_x                                     0xE1319C
#define pinstCMerchantWnd_x                                        0xE1349C
#define pinstCMIZoneSelectWnd_x                                    0xF84930
#define pinstCMusicPlayerWnd_x                                     0xE13240
#define pinstCNameChangeMercWnd_x                                  0xE1314C
#define pinstCNameChangePetWnd_x                                   0xE139C0
#define pinstCNameChangeWnd_x                                      0xE1316C
#define pinstCNoteWnd_x                                            0xE13144
#define pinstCObjectPreviewWnd_x                                   0xE131D0
#define pinstCOptionsWnd_x                                         0xE13154
#define pinstCPetInfoWnd_x                                         0xE13264
#define pinstCPetitionQWnd_x                                       0xE13994
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE13984
#define pinstCPlayerWnd_x                                          0xE13470
#define pinstCPopupWndManager_x                                    0xF851C0
#define pinstCProgressionSelectionWnd_x                            0xF85270
#define pinstCPurchaseGroupWnd_x                                   0xE1321C
#define pinstCPurchaseWnd_x                                        0xE131F0
#define pinstCPvPLeaderboardWnd_x                                  0xF85320
#define pinstCPvPStatsWnd_x                                        0xF853D0
#define pinstCQuantityWnd_x                                        0xE13254
#define pinstCRaceChangeWnd_x                                      0xE13184
#define pinstCRaidOptionsWnd_x                                     0xE1320C
#define pinstCRaidWnd_x                                            0xE13494
#define pinstCRealEstateItemsWnd_x                                 0xE139B8
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE134F0
#define pinstCRealEstateManageWnd_x                                0xE13228
#define pinstCRealEstateNeighborhoodWnd_x                          0xE13248
#define pinstCRealEstatePlotSearchWnd_x                            0xE1326C
#define pinstCRealEstatePurchaseWnd_x                              0xE13480
#define pinstCRespawnWnd_x                                         0xE131CC
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE13998
#define pinstCSendMoneyWnd_x                                       0xE13170
#define pinstCServerListWnd_x                                      0xE13484
#define pinstCSkillsSelectWnd_x                                    0xE13988
#define pinstCSkillsWnd_x                                          0xE1356C
#define pinstCSocialEditWnd_x                                      0xE131FC
#define pinstCSocialWnd_x                                          0xE1313C
#define pinstCSpellBookWnd_x                                       0xE13148
#define pinstCStoryWnd_x                                           0xE134EC
#define pinstCTargetOfTargetWnd_x                                  0xF871F8
#define pinstCTargetWnd_x                                          0xE131C8
#define pinstCTaskOverlayWnd_x                                     0xE13218
#define pinstCTaskSelectWnd_x                                      0xF87350
#define pinstCTaskManager_x                                        0xCE4CB0
#define pinstCTaskTemplateSelectWnd_x                              0xF87400
#define pinstCTaskWnd_x                                            0xF874B0
#define pinstCTextEntryWnd_x                                       0xE13214
#define pinstCTimeLeftWnd_x                                        0xE13980
#define pinstCTipWndCONTEXT_x                                      0xF876B4
#define pinstCTipWndOFDAY_x                                        0xF876B0
#define pinstCTitleWnd_x                                           0xF87760
#define pinstCTrackingWnd_x                                        0xE131B8
#define pinstCTradeskillWnd_x                                      0xF878C8
#define pinstCTradeWnd_x                                           0xE1397C
#define pinstCTrainWnd_x                                           0xE13488
#define pinstCTributeBenefitWnd_x                                  0xF87AC8
#define pinstCTributeMasterWnd_x                                   0xF87B78
#define pinstCTributeTrophyWnd_x                                   0xF87C28
#define pinstCVideoModesWnd_x                                      0xE13258
#define pinstCVoiceMacroWnd_x                                      0xF70EF8
#define pinstCVoteResultsWnd_x                                     0xE139A8
#define pinstCVoteWnd_x                                            0xE1399C
#define pinstCWebManager_x                                         0xF71574
#define pinstCZoneGuideWnd_x                                       0xE13220
#define pinstCZonePathWnd_x                                        0xE1323C

#define pinstEQSuiteTextureLoader_x                                0xCB2120
#define pinstItemIconCache_x                                       0xF80A88
#define pinstLootFiltersManager_x                                  0xCE4420
#define pinstRewardSelectionWnd_x                                  0xF85B18

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5BD5D0
#define __CastRay2_x                                               0x5BD620
#define __ConvertItemTags_x                                        0x5D9460
#define __CleanItemTags_x                                          0x47D150
#define __DoesFileExist_x                                          0x9142B0
#define __EQGetTime_x                                              0x910D50
#define __ExecuteCmd_x                                             0x5B5E40
#define __FixHeading_x                                             0x9ABEC0
#define __GameLoop_x                                               0x6CAC70
#define __get_bearing_x                                            0x5BD140
#define __get_melee_range_x                                        0x5BD810
#define __GetAnimationCache_x                                      0x7300D0
#define __GetGaugeValueFromEQ_x                                    0x822390
#define __GetLabelFromEQ_x                                         0x823E70
#define __GetXTargetType_x                                         0x9AD910
#define __HandleMouseWheel_x                                       0x6CBB50
#define __HeadingDiff_x                                            0x9ABF30
#define __HelpPath_x                                               0xF6C27C
#define __LoadFrontEnd_x                                           0x6C7F90
#define __NewUIINI_x                                               0x822060
#define __ProcessGameEvents_x                                      0x61E280
#define __ProcessMouseEvent_x                                      0x61DA40
#define __SaveColors_x                                             0x5585A0
#define __STMLToText_x                                             0x94F180
#define __ToggleKeyRingItem_x                                      0x519580
#define CMemoryMappedFile__SetFile_x                               0xA9B1E0
#define CrashDetected_x                                            0x6C9A30
#define DrawNetStatus_x                                            0x649FB0
#define Expansion_HoT_x                                            0xECE1CC
#define Teleport_Table_Size_x                                      0xEC5860
#define Teleport_Table_x                                           0xEC5D08
#define Util__FastTime_x                                           0x910920

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490440
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499330
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499100
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4939D0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492E20

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x560730
#define AltAdvManager__IsAbilityReady_x                            0x55F4D0
#define AltAdvManager__GetAAById_x                                 0x55F860
#define AltAdvManager__CanTrainAbility_x                           0x55F8D0
#define AltAdvManager__CanSeeAbility_x                             0x55FC30

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9D10
#define CharacterZoneClient__HasSkill_x                            0x4D4B90
#define CharacterZoneClient__MakeMeVisible_x                       0x4D62B0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE540
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAB70
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8C20
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8D00
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D8DE0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2C40
#define CharacterZoneClient__BardCastBard_x                        0x4C57C0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAC40
#define CharacterZoneClient__GetEffect_x                           0x4BAAB0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3C90
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3D60
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3DB0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C3F00
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C40D0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2A10
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7210
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6C90

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6F1750
#define CBankWnd__WndNotification_x                                0x6F1530

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6FF210

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x62CA40
#define CButtonWnd__CButtonWnd_x                                   0x94B530

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x71F150
#define CChatManager__InitContextMenu_x                            0x718280
#define CChatManager__FreeChatWindow_x                             0x71DC90
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8300
#define CChatManager__SetLockedActiveChatWindow_x                  0x71EDD0
#define CChatManager__CreateChatWindow_x                           0x71E2D0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8410

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x95FBD0
#define CContextMenu__dCContextMenu_x                              0x95FE10
#define CContextMenu__AddMenuItem_x                                0x95FE20
#define CContextMenu__RemoveMenuItem_x                             0x960130
#define CContextMenu__RemoveAllMenuItems_x                         0x960150
#define CContextMenu__CheckMenuItem_x                              0x9601D0
#define CContextMenu__SetMenuItem_x                                0x960050
#define CContextMenu__AddSeparator_x                               0x95FFB0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x960770
#define CContextMenuManager__RemoveMenu_x                          0x9607E0
#define CContextMenuManager__PopupMenu_x                           0x9608A0
#define CContextMenuManager__Flush_x                               0x960710
#define CContextMenuManager__GetMenu_x                             0x49B4C0
#define CContextMenuManager__CreateDefaultMenu_x                   0x72A8A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8EBF10
#define CChatService__GetFriendName_x                              0x8EBF20

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x71F980
#define CChatWindow__Clear_x                                       0x720C50
#define CChatWindow__WndNotification_x                             0x7213E0
#define CChatWindow__AddHistory_x                                  0x720510

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x95D030
#define CComboWnd__Draw_x                                          0x95C510
#define CComboWnd__GetCurChoice_x                                  0x95CE70
#define CComboWnd__GetListRect_x                                   0x95C9D0
#define CComboWnd__GetTextRect_x                                   0x95D0A0
#define CComboWnd__InsertChoice_x                                  0x95CB60
#define CComboWnd__SetColors_x                                     0x95CB30
#define CComboWnd__SetChoice_x                                     0x95CE40
#define CComboWnd__GetItemCount_x                                  0x95CE80
#define CComboWnd__GetCurChoiceText_x                              0x95CEC0
#define CComboWnd__GetChoiceText_x                                 0x95CE90
#define CComboWnd__InsertChoiceAtIndex_x                           0x95CC00

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7282C0
#define CContainerWnd__vftable_x                                   0xB235CC
#define CContainerWnd__SetContainer_x                              0x729810

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x552F50
#define CDisplay__PreZoneMainUI_x                                  0x552F60
#define CDisplay__CleanGameUI_x                                    0x558360
#define CDisplay__GetClickedActor_x                                0x54B310
#define CDisplay__GetUserDefinedColor_x                            0x543970
#define CDisplay__GetWorldFilePath_x                               0x54CD80
#define CDisplay__is3dON_x                                         0x547F70
#define CDisplay__ReloadUI_x                                       0x5523D0
#define CDisplay__WriteTextHD2_x                                   0x547D60
#define CDisplay__TrueDistance_x                                   0x54EA40
#define CDisplay__SetViewActor_x                                   0x54AC30
#define CDisplay__GetFloorHeight_x                                 0x548030
#define CDisplay__SetRenderWindow_x                                0x546990
#define CDisplay__ToggleScreenshotMode_x                           0x54A700

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x97FAD0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x963160
#define CEditWnd__EnsureCaretVisible_x                             0x965330
#define CEditWnd__GetCaretPt_x                                     0x9642E0
#define CEditWnd__GetCharIndexPt_x                                 0x964090
#define CEditWnd__GetDisplayString_x                               0x963F30
#define CEditWnd__GetHorzOffset_x                                  0x962790
#define CEditWnd__GetLineForPrintableChar_x                        0x965230
#define CEditWnd__GetSelStartPt_x                                  0x964340
#define CEditWnd__GetSTMLSafeText_x                                0x963D50
#define CEditWnd__PointFromPrintableChar_x                         0x964E60
#define CEditWnd__SelectableCharFromPoint_x                        0x964FD0
#define CEditWnd__SetEditable_x                                    0x964410
#define CEditWnd__SetWindowTextA_x                                 0x963AD0
#define CEditWnd__ReplaceSelection_x                               0x964AD0
#define CEditWnd__ReplaceSelection1_x                              0x964A50

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60BD50
#define CEverQuest__ClickedPlayer_x                                0x5FDEF0
#define CEverQuest__CreateTargetIndicator_x                        0x61B520
#define CEverQuest__DeleteTargetIndicator_x                        0x61B5B0
#define CEverQuest__DoTellWindow_x                                 0x4E84F0
#define CEverQuest__OutputTextToLog_x                              0x4E87C0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F2FE0
#define CEverQuest__dsp_chat_x                                     0x4E8B50
#define CEverQuest__trimName_x                                     0x617730
#define CEverQuest__Emote_x                                        0x60C5B0
#define CEverQuest__EnterZone_x                                    0x606650
#define CEverQuest__GetBodyTypeDesc_x                              0x610E70
#define CEverQuest__GetClassDesc_x                                 0x6114B0
#define CEverQuest__GetClassThreeLetterCode_x                      0x611AB0
#define CEverQuest__GetDeityDesc_x                                 0x619D70
#define CEverQuest__GetLangDesc_x                                  0x611C70
#define CEverQuest__GetRaceDesc_x                                  0x611490
#define CEverQuest__InterpretCmd_x                                 0x61A340
#define CEverQuest__LeftClickedOnPlayer_x                          0x5F71E0
#define CEverQuest__LMouseUp_x                                     0x5F5570
#define CEverQuest__RightClickedOnPlayer_x                         0x5F7AC0
#define CEverQuest__RMouseUp_x                                     0x5F64F0
#define CEverQuest__SetGameState_x                                 0x5F2D70
#define CEverQuest__UPCNotificationFlush_x                         0x617630
#define CEverQuest__IssuePetCommand_x                              0x613070
#define CEverQuest__ReportSuccessfulHit_x                          0x60D900

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x73A3D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x73A430
#define CGaugeWnd__Draw_x                                          0x739A60

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF4E0
#define CGuild__GetGuildName_x                                     0x4AE520
#define CGuild__GetGuildIndex_x                                    0x4AE960

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x754570

//CHotButton
#define CHotButton__SetButtonSize_x                                0x62CE00

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7614F0
#define CInvSlotMgr__MoveItem_x                                    0x760260
#define CInvSlotMgr__SelectSlot_x                                  0x7615C0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x75EAE0
#define CInvSlot__SliderComplete_x                                 0x75C840
#define CInvSlot__GetItemBase_x                                    0x75C1E0
#define CInvSlot__UpdateItem_x                                     0x75C350

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x763040
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7621E0
#define CInvSlotWnd__HandleLButtonUp_x                             0x762BC0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x81D6E0
#define CItemDisplayWnd__UpdateStrings_x                           0x7717B0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x76B490
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x76B9B0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x771DB0
#define CItemDisplayWnd__AboutToShow_x                             0x7713F0
#define CItemDisplayWnd__WndNotification_x                         0x772ED0
#define CItemDisplayWnd__RequestConvertItem_x                      0x772950
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x770450
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x771210

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x856420

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7773D0

// CLabel 
#define CLabel__Draw_x                                             0x77CE80

// CListWnd
#define CListWnd__CListWnd_x                                       0x9357E0
#define CListWnd__dCListWnd_x                                      0x935B00
#define CListWnd__AddColumn_x                                      0x939F80
#define CListWnd__AddColumn1_x                                     0x939FD0
#define CListWnd__AddLine_x                                        0x93A360
#define CListWnd__AddString_x                                      0x93A160
#define CListWnd__CalculateFirstVisibleLine_x                      0x939D40
#define CListWnd__CalculateVSBRange_x                              0x939B20
#define CListWnd__ClearSel_x                                       0x93AB40
#define CListWnd__ClearAllSel_x                                    0x93ABA0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x93B5C0
#define CListWnd__Compare_x                                        0x939450
#define CListWnd__Draw_x                                           0x935C30
#define CListWnd__DrawColumnSeparators_x                           0x938420
#define CListWnd__DrawHeader_x                                     0x938890
#define CListWnd__DrawItem_x                                       0x938D90
#define CListWnd__DrawLine_x                                       0x938590
#define CListWnd__DrawSeparator_x                                  0x9384C0
#define CListWnd__EnableLine_x                                     0x937CF0
#define CListWnd__EnsureVisible_x                                  0x93B4E0
#define CListWnd__ExtendSel_x                                      0x93AA70
#define CListWnd__GetColumnTooltip_x                               0x937830
#define CListWnd__GetColumnMinWidth_x                              0x9378A0
#define CListWnd__GetColumnWidth_x                                 0x9377A0
#define CListWnd__GetCurSel_x                                      0x937130
#define CListWnd__GetItemAtPoint_x                                 0x937F70
#define CListWnd__GetItemAtPoint1_x                                0x937FE0
#define CListWnd__GetItemData_x                                    0x9371B0
#define CListWnd__GetItemHeight_x                                  0x937570
#define CListWnd__GetItemIcon_x                                    0x937340
#define CListWnd__GetItemRect_x                                    0x937DE0
#define CListWnd__GetItemText_x                                    0x9371F0
#define CListWnd__GetSelList_x                                     0x93ABF0
#define CListWnd__GetSeparatorRect_x                               0x938220
#define CListWnd__InsertLine_x                                     0x93A750
#define CListWnd__RemoveLine_x                                     0x93A8A0
#define CListWnd__SetColors_x                                      0x939AF0
#define CListWnd__SetColumnJustification_x                         0x939820
#define CListWnd__SetColumnLabel_x                                 0x93A100
#define CListWnd__SetColumnWidth_x                                 0x939740
#define CListWnd__SetCurSel_x                                      0x93A9B0
#define CListWnd__SetItemColor_x                                   0x93B190
#define CListWnd__SetItemData_x                                    0x93B150
#define CListWnd__SetItemText_x                                    0x93AD60
#define CListWnd__ShiftColumnSeparator_x                           0x9398E0
#define CListWnd__Sort_x                                           0x9395D0
#define CListWnd__ToggleSel_x                                      0x93A9E0
#define CListWnd__SetColumnsSizable_x                              0x939990
#define CListWnd__SetItemWnd_x                                     0x93B010
#define CListWnd__GetItemWnd_x                                     0x937390
#define CListWnd__SetItemIcon_x                                    0x93ADE0
#define CListWnd__CalculateCustomWindowPositions_x                 0x939E40
#define CListWnd__SetVScrollPos_x                                  0x939720

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7926E0
#define CMapViewWnd__GetWorldCoordinates_x                         0x790DF0
#define CMapViewWnd__HandleLButtonDown_x                           0x78DE30

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7B2A70
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7B3350
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7B3880
#define CMerchantWnd__SelectRecoverySlot_x                         0x7B6800
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7B15E0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7BC3B0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7B2680

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8B97E0
#define CPacketScrambler__hton_x                                   0x8B97D0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x954790
#define CSidlManager__FindScreenPieceTemplate_x                    0x954BA0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x954990
#define CSidlManager__CreateLabel_x                                0x814980
#define CSidlManager__CreateXWndFromTemplate_x                     0x957B00
#define CSidlManager__CreateXWndFromTemplate1_x                    0x957CE0
#define CSidlManager__CreateXWnd_x                                 0x8148B0
#define CSidlManager__CreateHotButtonWnd_x                         0x814E70

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x951280
#define CSidlScreenWnd__CalculateVSBRange_x                        0x951180
#define CSidlScreenWnd__ConvertToRes_x                             0x97A5B0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x950C10
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x950900
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9509D0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x950AA0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x951720
#define CSidlScreenWnd__EnableIniStorage_x                         0x951BF0
#define CSidlScreenWnd__GetSidlPiece_x                             0x951910
#define CSidlScreenWnd__Init1_x                                    0x950520
#define CSidlScreenWnd__LoadIniInfo_x                              0x951C40
#define CSidlScreenWnd__LoadIniListWnd_x                           0x952770
#define CSidlScreenWnd__LoadSidlScreen_x                           0x94F930
#define CSidlScreenWnd__StoreIniInfo_x                             0x9522F0
#define CSidlScreenWnd__StoreIniVis_x                              0x952650
#define CSidlScreenWnd__WndNotification_x                          0x951630
#define CSidlScreenWnd__GetChildItem_x                             0x951B70
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9413E0
#define CSidlScreenWnd__m_layoutCopy_x                             0x1602A40

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x691B00
#define CSkillMgr__GetSkillCap_x                                   0x691CE0
#define CSkillMgr__GetNameToken_x                                  0x691280
#define CSkillMgr__IsActivatedSkill_x                              0x6913C0
#define CSkillMgr__IsCombatSkill_x                                 0x691300

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x961560
#define CSliderWnd__SetValue_x                                     0x9613D0
#define CSliderWnd__SetNumTicks_x                                  0x961430

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x81AA60

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x969D90
#define CStmlWnd__ParseSTML_x                                      0x96B0E0
#define CStmlWnd__CalculateHSBRange_x                              0x96AEB0
#define CStmlWnd__CalculateVSBRange_x                              0x96AE30
#define CStmlWnd__CanBreakAtCharacter_x                            0x96F1F0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x96FE80
#define CStmlWnd__ForceParseNow_x                                  0x96A380
#define CStmlWnd__GetNextTagPiece_x                                0x96F150
#define CStmlWnd__GetSTMLText_x                                    0x508F40
#define CStmlWnd__GetVisibleText_x                                 0x96A3A0
#define CStmlWnd__InitializeWindowVariables_x                      0x96FCD0
#define CStmlWnd__MakeStmlColorTag_x                               0x969400
#define CStmlWnd__MakeWndNotificationTag_x                         0x969470
#define CStmlWnd__SetSTMLText_x                                    0x9684B0
#define CStmlWnd__StripFirstSTMLLines_x                            0x970F80
#define CStmlWnd__UpdateHistoryString_x                            0x970090

// CTabWnd 
#define CTabWnd__Draw_x                                            0x967600
#define CTabWnd__DrawCurrentPage_x                                 0x967D30
#define CTabWnd__DrawTab_x                                         0x967A50
#define CTabWnd__GetCurrentPage_x                                  0x966E00
#define CTabWnd__GetPageInnerRect_x                                0x967040
#define CTabWnd__GetTabInnerRect_x                                 0x966F80
#define CTabWnd__GetTabRect_x                                      0x966E30
#define CTabWnd__InsertPage_x                                      0x967250
#define CTabWnd__RemovePage_x                                      0x9673C0
#define CTabWnd__SetPage_x                                         0x9670C0
#define CTabWnd__SetPageRect_x                                     0x967540
#define CTabWnd__UpdatePage_x                                      0x967910
#define CTabWnd__GetPageFromTabIndex_x                             0x967990
#define CTabWnd__GetCurrentTabIndex_x                              0x966DF0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x777810
#define CPageWnd__SetTabText_x                                     0x966940
#define CPageWnd__FlashTab_x                                       0x9669A0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8E50

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x93E280
#define CTextureFont__GetTextExtent_x                              0x93E440

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6C4E00
#define CHtmlComponentWnd__ValidateUri_x                           0x755F60
#define CHtmlWnd__SetClientCallbacks_x                             0x631E80
#define CHtmlWnd__AddObserver_x                                    0x631EA0
#define CHtmlWnd__RemoveObserver_x                                 0x631F00
#define Window__getProgress_x                                      0x86E850
#define Window__getStatus_x                                        0x86E870
#define Window__getURI_x                                           0x86E880

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x977380

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x92B410

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8040
#define CXStr__CXStr1_x                                            0xA02720
#define CXStr__CXStr3_x                                            0x90CEB0
#define CXStr__dCXStr_x                                            0x478700
#define CXStr__operator_equal_x                                    0x90D0E0
#define CXStr__operator_equal1_x                                   0x90D120
#define CXStr__operator_plus_equal1_x                              0x90DBB0
#define CXStr__SetString_x                                         0x90FAA0
#define CXStr__operator_char_p_x                                   0x90D620
#define CXStr__GetChar_x                                           0x90F3F0
#define CXStr__Delete_x                                            0x90ECA0
#define CXStr__GetUnicode_x                                        0x90F460
#define CXStr__GetLength_x                                         0x47D500
#define CXStr__Mid_x                                               0x47D510
#define CXStr__Insert_x                                            0x90F4C0
#define CXStr__FindNext_x                                          0x90F110

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x95F7F0
#define CXWnd__BringToTop_x                                        0x944AF0
#define CXWnd__Center_x                                            0x944670
#define CXWnd__ClrFocus_x                                          0x944480
#define CXWnd__Destroy_x                                           0x944530
#define CXWnd__DoAllDrawing_x                                      0x940B70
#define CXWnd__DrawChildren_x                                      0x940B40
#define CXWnd__DrawColoredRect_x                                   0x940FD0
#define CXWnd__DrawTooltip_x                                       0x93F680
#define CXWnd__DrawTooltipAtPoint_x                                0x93F740
#define CXWnd__GetBorderFrame_x                                    0x940E30
#define CXWnd__GetChildWndAt_x                                     0x944B90
#define CXWnd__GetClientClipRect_x                                 0x942E10
#define CXWnd__GetScreenClipRect_x                                 0x942EE0
#define CXWnd__GetScreenRect_x                                     0x9430B0
#define CXWnd__GetRelativeRect_x                                   0x943170
#define CXWnd__GetTooltipRect_x                                    0x941020
#define CXWnd__GetWindowTextA_x                                    0x49CBA0
#define CXWnd__IsActive_x                                          0x941750
#define CXWnd__IsDescendantOf_x                                    0x943A80
#define CXWnd__IsReallyVisible_x                                   0x943AB0
#define CXWnd__IsType_x                                            0x945200
#define CXWnd__Move_x                                              0x943B20
#define CXWnd__Move1_x                                             0x943BD0
#define CXWnd__ProcessTransition_x                                 0x944620
#define CXWnd__Refade_x                                            0x943E80
#define CXWnd__Resize_x                                            0x944110
#define CXWnd__Right_x                                             0x9448B0
#define CXWnd__SetFocus_x                                          0x944440
#define CXWnd__SetFont_x                                           0x9444B0
#define CXWnd__SetKeyTooltip_x                                     0x945020
#define CXWnd__SetMouseOver_x                                      0x941F90
#define CXWnd__StartFade_x                                         0x943960
#define CXWnd__GetChildItem_x                                      0x944D00
#define CXWnd__SetParent_x                                         0x943810
#define CXWnd__Minimize_x                                          0x944170

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x97B630

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x947980
#define CXWndManager__DrawWindows_x                                0x9479A0
#define CXWndManager__GetKeyboardFlags_x                           0x94A170
#define CXWndManager__HandleKeyboardMsg_x                          0x949D20
#define CXWndManager__RemoveWnd_x                                  0x94A3A0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x94A900

// CDBStr
#define CDBStr__GetString_x                                        0x542920

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBB50
#define EQ_Character__Cur_HP_x                                     0x4D1BD0
#define EQ_Character__Cur_Mana_x                                   0x4D92E0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEB90
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2650
#define EQ_Character__GetFocusRangeModifier_x                      0x4B27A0
#define EQ_Character__GetHPRegen_x                                 0x4DF080
#define EQ_Character__GetEnduranceRegen_x                          0x4DF680
#define EQ_Character__GetManaRegen_x                               0x4DFAC0
#define EQ_Character__Max_Endurance_x                              0x6588B0
#define EQ_Character__Max_HP_x                                     0x4D1A00
#define EQ_Character__Max_Mana_x                                   0x6586B0
#define EQ_Character__doCombatAbility_x                            0x65ACD0
#define EQ_Character__UseSkill_x                                   0x4E18A0
#define EQ_Character__GetConLevel_x                                0x650F90
#define EQ_Character__IsExpansionFlag_x                            0x5B4630
#define EQ_Character__TotalEffect_x                                0x4C4F00
#define EQ_Character__GetPCSpellAffect_x                           0x4BF8E0
#define EQ_Character__SpellDuration_x                              0x4BF410
#define EQ_Character__MySpellDuration_x                            0x4B0F80
#define EQ_Character__GetAdjustedSkill_x                           0x4D4950
#define EQ_Character__GetBaseSkill_x                               0x4D58F0
#define EQ_Character__CanUseItem_x                                 0x4D95F0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8D8E00

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x66EBD0

//PcClient
#define PcClient__PcClient_x                                       0x64E6C0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B97C0
#define CCharacterListWnd__EnterWorld_x                            0x4B9200
#define CCharacterListWnd__Quit_x                                  0x4B8F50
#define CCharacterListWnd__UpdateList_x                            0x4B9390

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x633040
#define EQ_Item__CreateItemTagString_x                             0x8B2DC0
#define EQ_Item__IsStackable_x                                     0x8B7A40
#define EQ_Item__GetImageNum_x                                     0x8B4910
#define EQ_Item__CreateItemClient_x                                0x632280
#define EQ_Item__GetItemValue_x                                    0x8B5C30
#define EQ_Item__ValueSellMerchant_x                               0x8B93C0
#define EQ_Item__IsKeyRingItem_x                                   0x8B7360
#define EQ_Item__CanGoInBag_x                                      0x633160
#define EQ_Item__IsEmpty_x                                         0x8B6EA0
#define EQ_Item__GetMaxItemCount_x                                 0x8B6040
#define EQ_Item__GetHeldItem_x                                     0x8B47E0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8B2610

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5614B0
#define EQ_LoadingS__Array_x                                       0xC39C60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6591F0
#define EQ_PC__GetAlternateAbilityId_x                             0x8C2890
#define EQ_PC__GetCombatAbility_x                                  0x8C2F00
#define EQ_PC__GetCombatAbilityTimer_x                             0x8C2F70
#define EQ_PC__GetItemRecastTimer_x                                0x65B250
#define EQ_PC__HasLoreItem_x                                       0x651750
#define EQ_PC__AlertInventoryChanged_x                             0x6508C0
#define EQ_PC__GetPcZoneClient_x                                   0x67D710
#define EQ_PC__RemoveMyAffect_x                                    0x65E480
#define EQ_PC__GetKeyRingItems_x                                   0x8C3800
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8C3590
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8C3B00

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BAB40
#define EQItemList__add_object_x                                   0x5E87D0
#define EQItemList__add_item_x                                     0x5BB0A0
#define EQItemList__delete_item_x                                  0x5BB0F0
#define EQItemList__FreeItemList_x                                 0x5BAFF0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53F470

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x670450
#define EQPlayer__dEQPlayer_x                                      0x663940
#define EQPlayer__DoAttack_x                                       0x6783D0
#define EQPlayer__EQPlayer_x                                       0x664000
#define EQPlayer__SetNameSpriteState_x                             0x668260
#define EQPlayer__SetNameSpriteTint_x                              0x669130
#define PlayerBase__HasProperty_j_x                                0x9AA2C0
#define EQPlayer__IsTargetable_x                                   0x9AA760
#define EQPlayer__CanSee_x                                         0x9AA5C0
#define EQPlayer__CanSee1_x                                        0x9AA690
#define PlayerBase__GetVisibilityLineSegment_x                     0x9AA380

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67B1B0
#define PlayerZoneClient__GetLevel_x                               0x67D750
#define PlayerZoneClient__IsValidTeleport_x                        0x5E9940
#define PlayerZoneClient__LegalPlayerRace_x                        0x55A1C0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x673240
#define EQPlayerManager__GetSpawnByName_x                          0x6732F0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x673380

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6366B0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x636730
#define KeypressHandler__AttachKeyToEqCommand_x                    0x636770
#define KeypressHandler__ClearCommandStateArray_x                  0x637B80
#define KeypressHandler__HandleKeyDown_x                           0x637BA0
#define KeypressHandler__HandleKeyUp_x                             0x637C40
#define KeypressHandler__SaveKeymapping_x                          0x638090

// MapViewMap 
#define MapViewMap__Clear_x                                        0x78E550
#define MapViewMap__SaveEx_x                                       0x791910
#define MapViewMap__SetZoom_x                                      0x795FD0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8D6D70

// StringTable 
#define StringTable__getString_x                                   0x8D1B50

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x65E0F0
#define PcZoneClient__RemovePetEffect_x                            0x65E720
#define PcZoneClient__HasAlternateAbility_x                        0x6584E0
#define PcZoneClient__GetCurrentMod_x                              0x4E4960
#define PcZoneClient__GetModCap_x                                  0x4E4860
#define PcZoneClient__CanEquipItem_x                               0x658B90
#define PcZoneClient__GetItemByID_x                                0x65B6C0
#define PcZoneClient__GetItemByItemClass_x                         0x65B810
#define PcZoneClient__RemoveBuffEffect_x                           0x65E740
#define PcZoneClient__BandolierSwap_x                              0x6597A0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65B1F0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5EE4B0

//IconCache
#define IconCache__GetIcon_x                                       0x72F970

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x727460
#define CContainerMgr__CloseContainer_x                            0x727730
#define CContainerMgr__OpenExperimentContainer_x                   0x7281B0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7E6D70

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62B220

//CLootWnd
#define CLootWnd__LootAll_x                                        0x784960
#define CLootWnd__RequestLootSlot_x                                0x783B90

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x587D90
#define EQ_Spell__SpellAffects_x                                   0x588200
#define EQ_Spell__SpellAffectBase_x                                0x587FC0
#define EQ_Spell__IsStackable_x                                    0x4C9630
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9450
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6B40
#define EQ_Spell__IsSPAStacking_x                                  0x589050
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x588560
#define EQ_Spell__IsNoRemove_x                                     0x4C9610
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x589060
#define __IsResEffectSpell_x                                       0x4C8960

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD0B0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8E13F0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x82DEE0
#define CTargetWnd__WndNotification_x                              0x82D720
#define CTargetWnd__RefreshTargetBuffs_x                           0x82D9F0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x82C880

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x832520
#define CTaskWnd__ConfirmAbandonTask_x                             0x835160

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53CF10
#define CTaskManager__HandleMessage_x                              0x53B3A0
#define CTaskManager__GetTaskStatus_x                              0x53CFC0
#define CTaskManager__GetElementDescription_x                      0x53D040

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x582EE0
#define EqSoundManager__PlayScriptMp3_x                            0x5831A0
#define EqSoundManager__SoundAssistPlay_x                          0x695A10
#define EqSoundManager__WaveInstancePlay_x                         0x694F80

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52E5B0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x965E50
#define CTextureAnimation__Draw_x                                  0x966050

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x961ED0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x569020
#define CAltAbilityData__GetMercMaxRank_x                          0x568FB0
#define CAltAbilityData__GetMaxRank_x                              0x55E350

//CTargetRing
#define CTargetRing__Cast_x                                        0x629340

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9430
#define CharacterBase__CreateItemGlobalIndex_x                     0x515BA0
#define CharacterBase__CreateItemIndex_x                           0x631430
#define CharacterBase__GetItemPossession_x                         0x501870
#define CharacterBase__GetItemByGlobalIndex_x                      0x8E9B00
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8E9B60
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x70E530
#define CCastSpellWnd__IsBardSongPlaying_x                         0x70ED60
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x70EE10

//messages
#define msg_spell_worn_off_x                                       0x5AC6B0
#define msg_new_text_x                                             0x5A1070
#define __msgTokenTextParam_x                                      0x5AE950
#define msgTokenText_x                                             0x5AEBA0

//SpellManager
#define SpellManager__vftable_x                                    0xAFD148
#define SpellManager__SpellManager_x                               0x698D40
#define Spellmanager__LoadTextSpells_x                             0x699630
#define SpellManager__GetSpellByGroupAndRank_x                     0x698F10

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9AE210

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x516230
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B2AF0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x649E10
#define ItemGlobalIndex__IsValidIndex_x                            0x516290

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8E1D90
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8E2010

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x77D1C0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x72BB40
#define CCursorAttachment__AttachToCursor1_x                       0x72BB80
#define CCursorAttachment__Deactivate_x                            0x72CB70

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x958B30
#define CSidlManagerBase__CreatePageWnd_x                          0x958330
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9545B0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x954540

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x975FE0
#define CEQSuiteTextureLoader__GetTexture_x                        0x975CA0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x513140
#define CFindItemWnd__WndNotification_x                            0x513C20
#define CFindItemWnd__Update_x                                     0x514790
#define CFindItemWnd__PickupSelectedItem_x                         0x512980

//IString
#define IString__Append_x                                          0x503090

//Camera
#define CDisplay__cameraType_x                                     0xE13268
#define EverQuest__Cameras_x                                       0xECE51C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51B920
#define LootFiltersManager__GetItemFilterData_x                    0x51B220
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51B250
#define LootFiltersManager__SetItemLootFilter_x                    0x51B470

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7D4AB0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9B3E30
#define CResolutionHandler__GetWindowedStyle_x                     0x690650

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7240F0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8F7400
#define CDistillerInfo__Instance_x                                 0x8F73A0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x743370
#define CGroupWnd__UpdateDisplay_x                                 0x7426C0

//ItemBase
#define ItemBase__IsLore_x                                         0x8B7410
#define ItemBase__IsLoreEquipped_x                                 0x8B7480

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5E8730
#define EQPlacedItemManager__GetItemByGuid_x                       0x5E8870
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5E88D0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x685E40
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6897C0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x509540

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F5BC0
#define FactionManagerClient__HandleFactionMessage_x               0x4F6230
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F6830
#define FactionManagerClient__GetMaxFaction_x                      0x4F684F
#define FactionManagerClient__GetMinFaction_x                      0x4F6800

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x501840

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x93D230

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BEB0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x501AA0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x5684D0

//CTargetManager
#define CTargetManager__Get_x                                      0x69C5C0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x685E40

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8C10

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BAF90

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF6BBB0

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6D7F10
#define CAAWnd__UpdateSelected_x                                   0x6D4780
#define CAAWnd__Update_x                                           0x6D7230

//CXRect
#define CXRect__operator_and_x                                     0x73A490

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
