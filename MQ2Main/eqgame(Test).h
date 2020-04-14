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
#define __ExpectedVersionDate                                     "Apr 13 2020"
#define __ExpectedVersionTime                                     "13:04:21"
#define __ActualVersionDate_x                                      0xB1A430
#define __ActualVersionTime_x                                      0xB1A424
#define __ActualVersionBuild_x                                     0xB060D4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x63E800
#define __MemChecker1_x                                            0x912A60
#define __MemChecker2_x                                            0x6CD580
#define __MemChecker3_x                                            0x6CD4D0
#define __MemChecker4_x                                            0x868880
#define __EncryptPad0_x                                            0xC524E0
#define __EncryptPad1_x                                            0xCB0648
#define __EncryptPad2_x                                            0xC62D78
#define __EncryptPad3_x                                            0xC62978
#define __EncryptPad4_x                                            0xCA0BF8
#define __EncryptPad5_x                                            0xF73C7C
#define __AC1_x                                                    0x8256C6
#define __AC2_x                                                    0x5F843F
#define __AC3_x                                                    0x5FFA8F
#define __AC4_x                                                    0x603A50
#define __AC5_x                                                    0x609CFF
#define __AC6_x                                                    0x60E1F6
#define __AC7_x                                                    0x5F7EB0
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
#define __do_loot_x                                                0x5C3C70
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
#define __gfMaxZoomCameraDistance_x                                0xB0FD28
#define __gfMaxCameraDistance_x                                    0xB3C14C
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
#define __CastRay_x                                                0x5BF040
#define __CastRay2_x                                               0x5BF090
#define __ConvertItemTags_x                                        0x5DAED0
#define __CleanItemTags_x                                          0x47D1A0
#define __DoesFileExist_x                                          0x915A90
#define __EQGetTime_x                                              0x912530
#define __ExecuteCmd_x                                             0x5B7890
#define __FixHeading_x                                             0x9AC8A0
#define __GameLoop_x                                               0x6CC750
#define __get_bearing_x                                            0x5BEBB0
#define __get_melee_range_x                                        0x5BF280
#define __GetAnimationCache_x                                      0x731C80
#define __GetGaugeValueFromEQ_x                                    0x823B70
#define __GetLabelFromEQ_x                                         0x825650
#define __GetXTargetType_x                                         0x9AE2F0
#define __HandleMouseWheel_x                                       0x6CD630
#define __HeadingDiff_x                                            0x9AC910
#define __HelpPath_x                                               0xF6C27C
#define __LoadFrontEnd_x                                           0x6C9A70
#define __NewUIINI_x                                               0x823840
#define __ProcessGameEvents_x                                      0x61FC00
#define __ProcessMouseEvent_x                                      0x61F3C0
#define __SaveColors_x                                             0x558E40
#define __STMLToText_x                                             0x94FD40
#define __ToggleKeyRingItem_x                                      0x5199D0
#define CMemoryMappedFile__SetFile_x                               0xA9BAE0
#define CrashDetected_x                                            0x6CB510
#define DrawNetStatus_x                                            0x64BA70
#define Expansion_HoT_x                                            0xECE1CC
#define Teleport_Table_Size_x                                      0xEC5860
#define Teleport_Table_x                                           0xEC5D08
#define Util__FastTime_x                                           0x912100

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490440
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499350
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499120
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4939D0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492E20

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x561000
#define AltAdvManager__IsAbilityReady_x                            0x55FDA0
#define AltAdvManager__GetAAById_x                                 0x560130
#define AltAdvManager__CanTrainAbility_x                           0x5601A0
#define AltAdvManager__CanSeeAbility_x                             0x560500

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9FA0
#define CharacterZoneClient__HasSkill_x                            0x4D4E20
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6540
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE5F0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAC20
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8EC0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8FA0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9080
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2CF0
#define CharacterZoneClient__BardCastBard_x                        0x4C5870
#define CharacterZoneClient__GetMaxEffects_x                       0x4BACF0
#define CharacterZoneClient__GetEffect_x                           0x4BAB60
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3D40
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3E10
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3E60
#define CharacterZoneClient__CalcAffectChange_x                    0x4C3FB0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4180
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2AC0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D74A0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6F20

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6F3230
#define CBankWnd__WndNotification_x                                0x6F3010

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x700940

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x62E390
#define CButtonWnd__CButtonWnd_x                                   0x94C0F0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x720D70
#define CChatManager__InitContextMenu_x                            0x719EA0
#define CChatManager__FreeChatWindow_x                             0x71F8B0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E85D0
#define CChatManager__SetLockedActiveChatWindow_x                  0x7209F0
#define CChatManager__CreateChatWindow_x                           0x71FEF0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E86E0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9607E0
#define CContextMenu__dCContextMenu_x                              0x960A20
#define CContextMenu__AddMenuItem_x                                0x960A30
#define CContextMenu__RemoveMenuItem_x                             0x960D40
#define CContextMenu__RemoveAllMenuItems_x                         0x960D60
#define CContextMenu__CheckMenuItem_x                              0x960DE0
#define CContextMenu__SetMenuItem_x                                0x960C60
#define CContextMenu__AddSeparator_x                               0x960BC0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x961380
#define CContextMenuManager__RemoveMenu_x                          0x9613F0
#define CContextMenuManager__PopupMenu_x                           0x9614B0
#define CContextMenuManager__Flush_x                               0x961320
#define CContextMenuManager__GetMenu_x                             0x49B490
#define CContextMenuManager__CreateDefaultMenu_x                   0x72C490

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8B7A30
#define CChatService__GetFriendName_x                              0x8ED4D0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7215A0
#define CChatWindow__Clear_x                                       0x722860
#define CChatWindow__WndNotification_x                             0x722FF0
#define CChatWindow__AddHistory_x                                  0x722120

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x95DC40
#define CComboWnd__Draw_x                                          0x95D120
#define CComboWnd__GetCurChoice_x                                  0x95DA80
#define CComboWnd__GetListRect_x                                   0x95D5E0
#define CComboWnd__GetTextRect_x                                   0x95DCB0
#define CComboWnd__InsertChoice_x                                  0x95D770
#define CComboWnd__SetColors_x                                     0x95D740
#define CComboWnd__SetChoice_x                                     0x95DA50
#define CComboWnd__GetItemCount_x                                  0x95DA90
#define CComboWnd__GetCurChoiceText_x                              0x95DAD0
#define CComboWnd__GetChoiceText_x                                 0x95DAA0
#define CComboWnd__InsertChoiceAtIndex_x                           0x95D810

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x729EB0
#define CContainerWnd__vftable_x                                   0xB2360C
#define CContainerWnd__SetContainer_x                              0x72B400

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x5537F0
#define CDisplay__PreZoneMainUI_x                                  0x553800
#define CDisplay__CleanGameUI_x                                    0x558C00
#define CDisplay__GetClickedActor_x                                0x54BBB0
#define CDisplay__GetUserDefinedColor_x                            0x544210
#define CDisplay__GetWorldFilePath_x                               0x54D620
#define CDisplay__is3dON_x                                         0x548810
#define CDisplay__ReloadUI_x                                       0x552C70
#define CDisplay__WriteTextHD2_x                                   0x548600
#define CDisplay__TrueDistance_x                                   0x54F2E0
#define CDisplay__SetViewActor_x                                   0x54B4D0
#define CDisplay__GetFloorHeight_x                                 0x5488D0
#define CDisplay__SetRenderWindow_x                                0x547230
#define CDisplay__ToggleScreenshotMode_x                           0x54AFA0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x980400

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x963D60
#define CEditWnd__EnsureCaretVisible_x                             0x965EF0
#define CEditWnd__GetCaretPt_x                                     0x964ED0
#define CEditWnd__GetCharIndexPt_x                                 0x964C80
#define CEditWnd__GetDisplayString_x                               0x964B30
#define CEditWnd__GetHorzOffset_x                                  0x9633A0
#define CEditWnd__GetLineForPrintableChar_x                        0x965DF0
#define CEditWnd__GetSelStartPt_x                                  0x964F30
#define CEditWnd__GetSTMLSafeText_x                                0x964950
#define CEditWnd__PointFromPrintableChar_x                         0x965A30
#define CEditWnd__SelectableCharFromPoint_x                        0x965BA0
#define CEditWnd__SetEditable_x                                    0x964FF0
#define CEditWnd__SetWindowTextA_x                                 0x9646D0
#define CEditWnd__ReplaceSelection_x                               0x9656B0
#define CEditWnd__ReplaceSelection1_x                              0x965630

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60D6D0
#define CEverQuest__ClickedPlayer_x                                0x5FF870
#define CEverQuest__CreateTargetIndicator_x                        0x61CEA0
#define CEverQuest__DeleteTargetIndicator_x                        0x61CF30
#define CEverQuest__DoTellWindow_x                                 0x4E87C0
#define CEverQuest__OutputTextToLog_x                              0x4E8A90
#define CEverQuest__DropHeldItemOnGround_x                         0x5F4960
#define CEverQuest__dsp_chat_x                                     0x4E8E20
#define CEverQuest__trimName_x                                     0x6190B0
#define CEverQuest__Emote_x                                        0x60DF30
#define CEverQuest__EnterZone_x                                    0x607FD0
#define CEverQuest__GetBodyTypeDesc_x                              0x6127F0
#define CEverQuest__GetClassDesc_x                                 0x612E30
#define CEverQuest__GetClassThreeLetterCode_x                      0x613430
#define CEverQuest__GetDeityDesc_x                                 0x61B6F0
#define CEverQuest__GetLangDesc_x                                  0x6135F0
#define CEverQuest__GetRaceDesc_x                                  0x612E10
#define CEverQuest__InterpretCmd_x                                 0x61BCC0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5F8B60
#define CEverQuest__LMouseUp_x                                     0x5F6EF0
#define CEverQuest__RightClickedOnPlayer_x                         0x5F9440
#define CEverQuest__RMouseUp_x                                     0x5F7E70
#define CEverQuest__SetGameState_x                                 0x5F46F0
#define CEverQuest__UPCNotificationFlush_x                         0x618FB0
#define CEverQuest__IssuePetCommand_x                              0x6149F0
#define CEverQuest__ReportSuccessfulHit_x                          0x60F280

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x73BE20
#define CGaugeWnd__CalcLinesFillRect_x                             0x73BE80
#define CGaugeWnd__Draw_x                                          0x73B4A0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF580
#define CGuild__GetGuildName_x                                     0x4AE5C0
#define CGuild__GetGuildIndex_x                                    0x4AEA00

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x756010

//CHotButton
#define CHotButton__SetButtonSize_x                                0x62E750

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x762FF0
#define CInvSlotMgr__MoveItem_x                                    0x761D60
#define CInvSlotMgr__SelectSlot_x                                  0x7630C0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7605A0
#define CInvSlot__SliderComplete_x                                 0x75E2F0
#define CInvSlot__GetItemBase_x                                    0x75DC80
#define CInvSlot__UpdateItem_x                                     0x75DDF0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x764B50
#define CInvSlotWnd__CInvSlotWnd_x                                 0x763CE0
#define CInvSlotWnd__HandleLButtonUp_x                             0x7646D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x81EEE0
#define CItemDisplayWnd__UpdateStrings_x                           0x7731D0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x76CF20
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x76D420
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7737E0
#define CItemDisplayWnd__AboutToShow_x                             0x772E30
#define CItemDisplayWnd__WndNotification_x                         0x774900
#define CItemDisplayWnd__RequestConvertItem_x                      0x774380
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x771E90
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x772C50

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x857A30

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x778E30

// CLabel 
#define CLabel__Draw_x                                             0x77E8E0

// CListWnd
#define CListWnd__CListWnd_x                                       0x9363E0
#define CListWnd__dCListWnd_x                                      0x936700
#define CListWnd__AddColumn_x                                      0x93AB50
#define CListWnd__AddColumn1_x                                     0x93ABA0
#define CListWnd__AddLine_x                                        0x93AF30
#define CListWnd__AddString_x                                      0x93AD30
#define CListWnd__CalculateFirstVisibleLine_x                      0x93A920
#define CListWnd__CalculateVSBRange_x                              0x93A710
#define CListWnd__ClearSel_x                                       0x93B710
#define CListWnd__ClearAllSel_x                                    0x93B770
#define CListWnd__CloseAndUpdateEditWindow_x                       0x93C170
#define CListWnd__Compare_x                                        0x93A040
#define CListWnd__Draw_x                                           0x936830
#define CListWnd__DrawColumnSeparators_x                           0x939010
#define CListWnd__DrawHeader_x                                     0x939480
#define CListWnd__DrawItem_x                                       0x939980
#define CListWnd__DrawLine_x                                       0x939180
#define CListWnd__DrawSeparator_x                                  0x9390B0
#define CListWnd__EnableLine_x                                     0x9388F0
#define CListWnd__EnsureVisible_x                                  0x93C0A0
#define CListWnd__ExtendSel_x                                      0x93B640
#define CListWnd__GetColumnTooltip_x                               0x938430
#define CListWnd__GetColumnMinWidth_x                              0x9384A0
#define CListWnd__GetColumnWidth_x                                 0x9383A0
#define CListWnd__GetCurSel_x                                      0x937D30
#define CListWnd__GetItemAtPoint_x                                 0x938B60
#define CListWnd__GetItemAtPoint1_x                                0x938BD0
#define CListWnd__GetItemData_x                                    0x937DB0
#define CListWnd__GetItemHeight_x                                  0x938170
#define CListWnd__GetItemIcon_x                                    0x937F40
#define CListWnd__GetItemRect_x                                    0x9389E0
#define CListWnd__GetItemText_x                                    0x937DF0
#define CListWnd__GetSelList_x                                     0x93B7C0
#define CListWnd__GetSeparatorRect_x                               0x938E10
#define CListWnd__InsertLine_x                                     0x93B320
#define CListWnd__RemoveLine_x                                     0x93B470
#define CListWnd__SetColors_x                                      0x93A6E0
#define CListWnd__SetColumnJustification_x                         0x93A410
#define CListWnd__SetColumnLabel_x                                 0x93ACD0
#define CListWnd__SetColumnWidth_x                                 0x93A330
#define CListWnd__SetCurSel_x                                      0x93B580
#define CListWnd__SetItemColor_x                                   0x93BD60
#define CListWnd__SetItemData_x                                    0x93BD20
#define CListWnd__SetItemText_x                                    0x93B930
#define CListWnd__ShiftColumnSeparator_x                           0x93A4D0
#define CListWnd__Sort_x                                           0x93A1C0
#define CListWnd__ToggleSel_x                                      0x93B5B0
#define CListWnd__SetColumnsSizable_x                              0x93A580
#define CListWnd__SetItemWnd_x                                     0x93BBE0
#define CListWnd__GetItemWnd_x                                     0x937F90
#define CListWnd__SetItemIcon_x                                    0x93B9B0
#define CListWnd__CalculateCustomWindowPositions_x                 0x93AA10
#define CListWnd__SetVScrollPos_x                                  0x93A310

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7940F0
#define CMapViewWnd__GetWorldCoordinates_x                         0x792800
#define CMapViewWnd__HandleLButtonDown_x                           0x78F840

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7B42F0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7B4BD0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7B5100
#define CMerchantWnd__SelectRecoverySlot_x                         0x7B8070
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7B2E60
#define CMerchantWnd__SelectBuySellSlot_x                          0x7BDC10
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7B3F00

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8BB190
#define CPacketScrambler__hton_x                                   0x8BB180

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x955370
#define CSidlManager__FindScreenPieceTemplate_x                    0x955780
#define CSidlManager__FindScreenPieceTemplate1_x                   0x955570
#define CSidlManager__CreateLabel_x                                0x816180
#define CSidlManager__CreateXWndFromTemplate_x                     0x9586E0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9588B0
#define CSidlManager__CreateXWnd_x                                 0x8160B0
#define CSidlManager__CreateHotButtonWnd_x                         0x816680

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x951E50
#define CSidlScreenWnd__CalculateVSBRange_x                        0x951D60
#define CSidlScreenWnd__ConvertToRes_x                             0x97AF50
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9517F0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9514E0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9515B0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x951680
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9522F0
#define CSidlScreenWnd__EnableIniStorage_x                         0x9527C0
#define CSidlScreenWnd__GetSidlPiece_x                             0x9524E0
#define CSidlScreenWnd__Init1_x                                    0x9510E0
#define CSidlScreenWnd__LoadIniInfo_x                              0x952810
#define CSidlScreenWnd__LoadIniListWnd_x                           0x953350
#define CSidlScreenWnd__LoadSidlScreen_x                           0x9504F0
#define CSidlScreenWnd__StoreIniInfo_x                             0x952ED0
#define CSidlScreenWnd__StoreIniVis_x                              0x953230
#define CSidlScreenWnd__WndNotification_x                          0x952200
#define CSidlScreenWnd__GetChildItem_x                             0x952740
#define CSidlScreenWnd__HandleLButtonUp_x                          0x941FD0
#define CSidlScreenWnd__m_layoutCopy_x                             0x1602A40

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x693670
#define CSkillMgr__GetSkillCap_x                                   0x693850
#define CSkillMgr__GetNameToken_x                                  0x692DF0
#define CSkillMgr__IsActivatedSkill_x                              0x692F30
#define CSkillMgr__IsCombatSkill_x                                 0x692E70

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x962170
#define CSliderWnd__SetValue_x                                     0x961FE0
#define CSliderWnd__SetNumTicks_x                                  0x962040

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x81C270

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x96A930
#define CStmlWnd__ParseSTML_x                                      0x96BC60
#define CStmlWnd__CalculateHSBRange_x                              0x96BA30
#define CStmlWnd__CalculateVSBRange_x                              0x96B9B0
#define CStmlWnd__CanBreakAtCharacter_x                            0x96FD70
#define CStmlWnd__FastForwardToEndOfTag_x                          0x970A00
#define CStmlWnd__ForceParseNow_x                                  0x96AF10
#define CStmlWnd__GetNextTagPiece_x                                0x96FCD0
#define CStmlWnd__GetSTMLText_x                                    0x5093C0
#define CStmlWnd__GetVisibleText_x                                 0x96AF30
#define CStmlWnd__InitializeWindowVariables_x                      0x970850
#define CStmlWnd__MakeStmlColorTag_x                               0x969FA0
#define CStmlWnd__MakeWndNotificationTag_x                         0x96A010
#define CStmlWnd__SetSTMLText_x                                    0x969050
#define CStmlWnd__StripFirstSTMLLines_x                            0x971AF0
#define CStmlWnd__UpdateHistoryString_x                            0x970C10

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9681A0
#define CTabWnd__DrawCurrentPage_x                                 0x9688D0
#define CTabWnd__DrawTab_x                                         0x9685F0
#define CTabWnd__GetCurrentPage_x                                  0x9679A0
#define CTabWnd__GetPageInnerRect_x                                0x967BE0
#define CTabWnd__GetTabInnerRect_x                                 0x967B20
#define CTabWnd__GetTabRect_x                                      0x9679D0
#define CTabWnd__InsertPage_x                                      0x967DF0
#define CTabWnd__RemovePage_x                                      0x967F60
#define CTabWnd__SetPage_x                                         0x967C60
#define CTabWnd__SetPageRect_x                                     0x9680E0
#define CTabWnd__UpdatePage_x                                      0x9684B0
#define CTabWnd__GetPageFromTabIndex_x                             0x968530
#define CTabWnd__GetCurrentTabIndex_x                              0x967990

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x779270
#define CPageWnd__SetTabText_x                                     0x9674E0
#define CPageWnd__FlashTab_x                                       0x967540

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8F70

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x93EE80
#define CTextureFont__GetTextExtent_x                              0x93F040

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6C6610
#define CHtmlComponentWnd__ValidateUri_x                           0x757A00
#define CHtmlWnd__SetClientCallbacks_x                             0x633800
#define CHtmlWnd__AddObserver_x                                    0x633820
#define CHtmlWnd__RemoveObserver_x                                 0x633880
#define Window__getProgress_x                                      0x86FE70
#define Window__getStatus_x                                        0x86FE90
#define Window__getURI_x                                           0x86FEA0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x977D60

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x92BEE0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8310
#define CXStr__CXStr1_x                                            0x934910
#define CXStr__CXStr3_x                                            0x90E6D0
#define CXStr__dCXStr_x                                            0x478760
#define CXStr__operator_equal_x                                    0x90E900
#define CXStr__operator_equal1_x                                   0x90E940
#define CXStr__operator_plus_equal1_x                              0x90F3D0
#define CXStr__SetString_x                                         0x9112C0
#define CXStr__operator_char_p_x                                   0x90EE40
#define CXStr__GetChar_x                                           0x910C10
#define CXStr__Delete_x                                            0x9104C0
#define CXStr__GetUnicode_x                                        0x910C80
#define CXStr__GetLength_x                                         0x47D550
#define CXStr__Mid_x                                               0x47D560
#define CXStr__Insert_x                                            0x910CE0
#define CXStr__FindNext_x                                          0x910930

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x960400
#define CXWnd__BringToTop_x                                        0x9456F0
#define CXWnd__Center_x                                            0x945270
#define CXWnd__ClrFocus_x                                          0x945080
#define CXWnd__Destroy_x                                           0x945130
#define CXWnd__DoAllDrawing_x                                      0x941770
#define CXWnd__DrawChildren_x                                      0x941740
#define CXWnd__DrawColoredRect_x                                   0x941BC0
#define CXWnd__DrawTooltip_x                                       0x940280
#define CXWnd__DrawTooltipAtPoint_x                                0x940340
#define CXWnd__GetBorderFrame_x                                    0x941A20
#define CXWnd__GetChildWndAt_x                                     0x945790
#define CXWnd__GetClientClipRect_x                                 0x943A00
#define CXWnd__GetScreenClipRect_x                                 0x943AD0
#define CXWnd__GetScreenRect_x                                     0x943C70
#define CXWnd__GetRelativeRect_x                                   0x943D30
#define CXWnd__GetTooltipRect_x                                    0x941C10
#define CXWnd__GetWindowTextA_x                                    0x49CC30
#define CXWnd__IsActive_x                                          0x942340
#define CXWnd__IsDescendantOf_x                                    0x944660
#define CXWnd__IsReallyVisible_x                                   0x944690
#define CXWnd__IsType_x                                            0x945DF0
#define CXWnd__Move_x                                              0x9446F0
#define CXWnd__Move1_x                                             0x9447A0
#define CXWnd__ProcessTransition_x                                 0x945220
#define CXWnd__Refade_x                                            0x944A70
#define CXWnd__Resize_x                                            0x944CF0
#define CXWnd__Right_x                                             0x9454B0
#define CXWnd__SetFocus_x                                          0x945040
#define CXWnd__SetFont_x                                           0x9450B0
#define CXWnd__SetKeyTooltip_x                                     0x945C10
#define CXWnd__SetMouseOver_x                                      0x942B50
#define CXWnd__StartFade_x                                         0x944550
#define CXWnd__GetChildItem_x                                      0x945900
#define CXWnd__SetParent_x                                         0x944410
#define CXWnd__Minimize_x                                          0x944D50

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x97BFD0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9485C0
#define CXWndManager__DrawWindows_x                                0x9485E0
#define CXWndManager__GetKeyboardFlags_x                           0x94ADA0
#define CXWndManager__HandleKeyboardMsg_x                          0x94A950
#define CXWndManager__RemoveWnd_x                                  0x94AFC0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x94B510

// CDBStr
#define CDBStr__GetString_x                                        0x5431A0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBC00
#define EQ_Character__Cur_HP_x                                     0x4D1E60
#define EQ_Character__Cur_Mana_x                                   0x4D9580
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEC40
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2700
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2850
#define EQ_Character__GetHPRegen_x                                 0x4DF350
#define EQ_Character__GetEnduranceRegen_x                          0x4DF950
#define EQ_Character__GetManaRegen_x                               0x4DFD90
#define EQ_Character__Max_Endurance_x                              0x65A240
#define EQ_Character__Max_HP_x                                     0x4D1C90
#define EQ_Character__Max_Mana_x                                   0x65A040
#define EQ_Character__doCombatAbility_x                            0x65C660
#define EQ_Character__UseSkill_x                                   0x4E1B70
#define EQ_Character__GetConLevel_x                                0x652A60
#define EQ_Character__IsExpansionFlag_x                            0x5B60E0
#define EQ_Character__TotalEffect_x                                0x4C4FB0
#define EQ_Character__GetPCSpellAffect_x                           0x4BF990
#define EQ_Character__SpellDuration_x                              0x4BF4C0
#define EQ_Character__MySpellDuration_x                            0x4B1030
#define EQ_Character__GetAdjustedSkill_x                           0x4D4BE0
#define EQ_Character__GetBaseSkill_x                               0x4D5B80
#define EQ_Character__CanUseItem_x                                 0x4D9890

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8DA320

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6705B0

//PcClient
#define PcClient__PcClient_x                                       0x6501A0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9870
#define CCharacterListWnd__EnterWorld_x                            0x4B92B0
#define CCharacterListWnd__Quit_x                                  0x4B9000
#define CCharacterListWnd__UpdateList_x                            0x4B9440

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6349E0
#define EQ_Item__CreateItemTagString_x                             0x8B4750
#define EQ_Item__IsStackable_x                                     0x8B93F0
#define EQ_Item__GetImageNum_x                                     0x8B62F0
#define EQ_Item__CreateItemClient_x                                0x633C20
#define EQ_Item__GetItemValue_x                                    0x8B75F0
#define EQ_Item__ValueSellMerchant_x                               0x8BAD70
#define EQ_Item__IsKeyRingItem_x                                   0x8B8D10
#define EQ_Item__CanGoInBag_x                                      0x634B00
#define EQ_Item__IsEmpty_x                                         0x8B8840
#define EQ_Item__GetMaxItemCount_x                                 0x8B7A00
#define EQ_Item__GetHeldItem_x                                     0x8B61C0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8B3F90

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x561CD0
#define EQ_LoadingS__Array_x                                       0xC39C60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65AB80
#define EQ_PC__GetAlternateAbilityId_x                             0x8C4240
#define EQ_PC__GetCombatAbility_x                                  0x8C48B0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8C4920
#define EQ_PC__GetItemRecastTimer_x                                0x65CBE0
#define EQ_PC__HasLoreItem_x                                       0x653220
#define EQ_PC__AlertInventoryChanged_x                             0x6523A0
#define EQ_PC__GetPcZoneClient_x                                   0x67F040
#define EQ_PC__RemoveMyAffect_x                                    0x65FE10
#define EQ_PC__GetKeyRingItems_x                                   0x8C51B0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8C4F40
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8C54B0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BC590
#define EQItemList__add_object_x                                   0x5EA1C0
#define EQItemList__add_item_x                                     0x5BCAF0
#define EQItemList__delete_item_x                                  0x5BCB40
#define EQItemList__FreeItemList_x                                 0x5BCA40

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53FD40

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x671E30
#define EQPlayer__dEQPlayer_x                                      0x665300
#define EQPlayer__DoAttack_x                                       0x679D00
#define EQPlayer__EQPlayer_x                                       0x6659C0
#define EQPlayer__SetNameSpriteState_x                             0x669C40
#define EQPlayer__SetNameSpriteTint_x                              0x66AB10
#define PlayerBase__HasProperty_j_x                                0x9AAC50
#define EQPlayer__IsTargetable_x                                   0x9AB0F0
#define EQPlayer__CanSee_x                                         0x9AAF50
#define EQPlayer__CanSee1_x                                        0x9AB020
#define PlayerBase__GetVisibilityLineSegment_x                     0x9AAD10

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67CAE0
#define PlayerZoneClient__GetLevel_x                               0x67F080
#define PlayerZoneClient__IsValidTeleport_x                        0x5EB330
#define PlayerZoneClient__LegalPlayerRace_x                        0x55AAC0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x674C00
#define EQPlayerManager__GetSpawnByName_x                          0x674CB0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x674D40

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6381B0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x638230
#define KeypressHandler__AttachKeyToEqCommand_x                    0x638270
#define KeypressHandler__ClearCommandStateArray_x                  0x639680
#define KeypressHandler__HandleKeyDown_x                           0x6396A0
#define KeypressHandler__HandleKeyUp_x                             0x639740
#define KeypressHandler__SaveKeymapping_x                          0x639B90

// MapViewMap 
#define MapViewMap__Clear_x                                        0x78FF60
#define MapViewMap__SaveEx_x                                       0x793320
#define MapViewMap__SetZoom_x                                      0x7979E0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8D8340

// StringTable 
#define StringTable__getString_x                                   0x8D3310

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x65FA80
#define PcZoneClient__RemovePetEffect_x                            0x6600B0
#define PcZoneClient__HasAlternateAbility_x                        0x659E70
#define PcZoneClient__GetCurrentMod_x                              0x4E4C30
#define PcZoneClient__GetModCap_x                                  0x4E4B30
#define PcZoneClient__CanEquipItem_x                               0x65A520
#define PcZoneClient__GetItemByID_x                                0x65D050
#define PcZoneClient__GetItemByItemClass_x                         0x65D1A0
#define PcZoneClient__RemoveBuffEffect_x                           0x6600D0
#define PcZoneClient__BandolierSwap_x                              0x65B130
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65CB80

//Doors
#define EQSwitch__UseSwitch_x                                      0x5EFDE0

//IconCache
#define IconCache__GetIcon_x                                       0x731520

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x729050
#define CContainerMgr__CloseContainer_x                            0x729320
#define CContainerMgr__OpenExperimentContainer_x                   0x729DA0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7E8450

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62CB50

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7863B0
#define CLootWnd__RequestLootSlot_x                                0x7855E0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5884E0
#define EQ_Spell__SpellAffects_x                                   0x588950
#define EQ_Spell__SpellAffectBase_x                                0x588710
#define EQ_Spell__IsStackable_x                                    0x4C98B0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C96A0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6BD0
#define EQ_Spell__IsSPAStacking_x                                  0x5897A0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x588CB0
#define EQ_Spell__IsNoRemove_x                                     0x4C9890
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5897B0
#define __IsResEffectSpell_x                                       0x4C8A10

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD120

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8E2980

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x82F6C0
#define CTargetWnd__WndNotification_x                              0x82EF00
#define CTargetWnd__RefreshTargetBuffs_x                           0x82F1D0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x82E060

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x833D00
#define CTaskWnd__ConfirmAbandonTask_x                             0x836940

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53D790
#define CTaskManager__HandleMessage_x                              0x53BC10
#define CTaskManager__GetTaskStatus_x                              0x53D840
#define CTaskManager__GetElementDescription_x                      0x53D8C0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x583620
#define EqSoundManager__PlayScriptMp3_x                            0x5838E0
#define EqSoundManager__SoundAssistPlay_x                          0x697600
#define EqSoundManager__WaveInstancePlay_x                         0x696B70

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52EDE0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9669F0
#define CTextureAnimation__Draw_x                                  0x966BF0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x962AE0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x569870
#define CAltAbilityData__GetMercMaxRank_x                          0x569800
#define CAltAbilityData__GetMaxRank_x                              0x55EC20

//CTargetRing
#define CTargetRing__Cast_x                                        0x62AC70

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9680
#define CharacterBase__CreateItemGlobalIndex_x                     0x516050
#define CharacterBase__CreateItemIndex_x                           0x632DA0
#define CharacterBase__GetItemPossession_x                         0x501CD0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8EB080
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8EB0E0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x7100A0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x7108D0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x710980

//messages
#define msg_spell_worn_off_x                                       0x5AE0F0
#define msg_new_text_x                                             0x5A2AC0
#define __msgTokenTextParam_x                                      0x5B0380
#define msgTokenText_x                                             0x5B05D0

//SpellManager
#define SpellManager__vftable_x                                    0xAFD168
#define SpellManager__SpellManager_x                               0x69A930
#define Spellmanager__LoadTextSpells_x                             0x69B220
#define SpellManager__GetSpellByGroupAndRank_x                     0x69AB00

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9AEBE0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5166A0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B4520
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64B8D0
#define ItemGlobalIndex__IsValidIndex_x                            0x516700

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8E3320
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8E35A0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x77EC20

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x72D730
#define CCursorAttachment__AttachToCursor1_x                       0x72D770
#define CCursorAttachment__Deactivate_x                            0x72E750

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x959710
#define CSidlManagerBase__CreatePageWnd_x                          0x958F00
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x955190
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x955120

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x976990
#define CEQSuiteTextureLoader__GetTexture_x                        0x976650

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x5135C0
#define CFindItemWnd__WndNotification_x                            0x5140A0
#define CFindItemWnd__Update_x                                     0x514C10
#define CFindItemWnd__PickupSelectedItem_x                         0x512E10

//IString
#define IString__Append_x                                          0x5035B0

//Camera
#define CDisplay__cameraType_x                                     0xE13268
#define EverQuest__Cameras_x                                       0xECE51C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51BD80
#define LootFiltersManager__GetItemFilterData_x                    0x51B680
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51B6B0
#define LootFiltersManager__SetItemLootFilter_x                    0x51B8D0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7D6230

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9B47C0
#define CResolutionHandler__GetWindowedStyle_x                     0x6920A0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x725D00

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8F8A60
#define CDistillerInfo__Instance_x                                 0x8F8A00

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x744DF0
#define CGroupWnd__UpdateDisplay_x                                 0x744140

//ItemBase
#define ItemBase__IsLore_x                                         0x8B8DC0
#define ItemBase__IsLoreEquipped_x                                 0x8B8E30

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EA120
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EA260
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EA2C0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6877C0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68B180

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x509A00

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F6100
#define FactionManagerClient__HandleFactionMessage_x               0x4F6770
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F6D30
#define FactionManagerClient__GetMaxFaction_x                      0x4F6D4F
#define FactionManagerClient__GetMinFaction_x                      0x4F6D00

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x501CA0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x93DE10

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BF10

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x501FC0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x568D00

//CTargetManager
#define CTargetManager__Get_x                                      0x69E180

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6877C0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8D30

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BC9E0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF6BBB0

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6D9970
#define CAAWnd__UpdateSelected_x                                   0x6D61E0
#define CAAWnd__Update_x                                           0x6D8C90

//CXRect
#define CXRect__operator_and_x                                     0x73BEE0

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
