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
#define __ExpectedVersionDate                                     "Apr  8 2020"
#define __ExpectedVersionTime                                     "12:45:29"
#define __ActualVersionDate_x                                      0xB1A3F8
#define __ActualVersionTime_x                                      0xB1A3EC
#define __ActualVersionBuild_x                                     0xB060E4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x63D7A0
#define __MemChecker1_x                                            0x911F70
#define __MemChecker2_x                                            0x6CCA00
#define __MemChecker3_x                                            0x6CC950
#define __MemChecker4_x                                            0x868220
#define __EncryptPad0_x                                            0xC524E0
#define __EncryptPad1_x                                            0xCB0648
#define __EncryptPad2_x                                            0xC62D78
#define __EncryptPad3_x                                            0xC62978
#define __EncryptPad4_x                                            0xCA0BF8
#define __EncryptPad5_x                                            0xF73C78
#define __AC1_x                                                    0x824E06
#define __AC2_x                                                    0x5F748F
#define __AC3_x                                                    0x5FEADF
#define __AC4_x                                                    0x602AA0
#define __AC5_x                                                    0x608D4F
#define __AC6_x                                                    0x60D246
#define __AC7_x                                                    0x5F6F00
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x70AF4

// Direct Input
#define DI8__Main_x                                                0xF73C98
#define DI8__Keyboard_x                                            0xF73C9C
#define DI8__Mouse_x                                               0xF73CB4
#define DI8__Mouse_Copy_x                                          0xECCE6C
#define DI8__Mouse_Check_x                                         0xF717CC
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
#define __do_loot_x                                                0x5C2C00
#define __DrawHandler_x                                            0x16039F0
#define __GroupCount_x                                             0xEC7EC2
#define __Guilds_x                                                 0xECBDB0
#define __gWorld_x                                                 0xEC7E50
#define __HWnd_x                                                   0xF73CB8
#define __heqmain_x                                                0xF73C60
#define __InChatMode_x                                             0xECCE54
#define __LastTell_x                                               0xECEDC8
#define __LMouseHeldTime_x                                         0xECCF90
#define __Mouse_x                                                  0xF73C84
#define __MouseLook_x                                              0xECCEEA
#define __MouseEventTime_x                                         0xF6C68C
#define __gpbCommandEvent_x                                        0xEC80C0
#define __NetStatusToggle_x                                        0xECCEED
#define __PCNames_x                                                0xECE374
#define __RangeAttackReady_x                                       0xECE068
#define __RMouseHeldTime_x                                         0xECCF8C
#define __RunWalkState_x                                           0xECCE58
#define __ScreenMode_x                                             0xE131B0
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
#define __gfMaxZoomCameraDistance_x                                0xB0FD38
#define __gfMaxCameraDistance_x                                    0xB3C164
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
#define pinstActiveBanker_x                                        0xEC585C
#define pinstActiveCorpse_x                                        0xEC5848
#define pinstActiveGMaster_x                                       0xEC5854
#define pinstActiveMerchant_x                                      0xEC5844
#define pinstAltAdvManager_x                                       0xE14378
#define pinstBandageTarget_x                                       0xEC5878
#define pinstCamActor_x                                            0xE131A4
#define pinstCDBStr_x                                              0xE13094
#define pinstCDisplay_x                                            0xEC7D0C
#define pinstCEverQuest_x                                          0xF73CB0
#define pinstEverQuestInfo_x                                       0xECCE00
#define pinstCharData_x                                            0xEC7EAC
#define pinstCharSpawn_x                                           0xEC58D8
#define pinstControlledMissile_x                                   0xEC5AF4
#define pinstControlledPlayer_x                                    0xEC58D8
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
#define pinstLocalPlayer_x                                         0xEC5840
#define pinstMercenaryData_x                                       0xF6E184
#define pinstMercenaryStats_x                                      0xF87174
#define pinstModelPlayer_x                                         0xEC5870
#define pinstPCData_x                                              0xEC7EAC
#define pinstSkillMgr_x                                            0xF702E8
#define pinstSpawnManager_x                                        0xF6ED90
#define pinstSpellManager_x                                        0xF70528
#define pinstSpellSets_x                                           0xF647D4
#define pinstStringTable_x                                         0xEC80B0
#define pinstSwitchManager_x                                       0xEC56E8
#define pinstTarget_x                                              0xEC58D4
#define pinstTargetObject_x                                        0xEC58E0
#define pinstTargetSwitch_x                                        0xEC5D04
#define pinstTaskMember_x                                          0xE12E68
#define pinstTrackTarget_x                                         0xEC58DC
#define pinstTradeTarget_x                                         0xEC5864
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
#define pinstCAAWnd_x                                              0xE134A4
#define pinstCAchievementsWnd_x                                    0xE139B4
#define pinstCActionsWnd_x                                         0xE134EC
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE131EC
#define pinstCAdvancedLootWnd_x                                    0xE13180
#define pinstCAdventureLeaderboardWnd_x                            0xF7DE48
#define pinstCAdventureRequestWnd_x                                0xF7DEF8
#define pinstCAdventureStatsWnd_x                                  0xF7DFA8
#define pinstCAggroMeterWnd_x                                      0xE131E0
#define pinstCAlarmWnd_x                                           0xE1315C
#define pinstCAlertHistoryWnd_x                                    0xE13244
#define pinstCAlertStackWnd_x                                      0xE13184
#define pinstCAlertWnd_x                                           0xE131BC
#define pinstCAltStorageWnd_x                                      0xF7E308
#define pinstCAudioTriggersWindow_x                                0xCC7D10
#define pinstCAuraWnd_x                                            0xE13188
#define pinstCAvaZoneWnd_x                                         0xE13254
#define pinstCBandolierWnd_x                                       0xE131DC
#define pinstCBankWnd_x                                            0xE13224
#define pinstCBarterMerchantWnd_x                                  0xF7F548
#define pinstCBarterSearchWnd_x                                    0xF7F5F8
#define pinstCBarterWnd_x                                          0xF7F6A8
#define pinstCBazaarConfirmationWnd_x                              0xE13160
#define pinstCBazaarSearchWnd_x                                    0xE134A8
#define pinstCBazaarWnd_x                                          0xE13130
#define pinstCBlockedBuffWnd_x                                     0xE13198
#define pinstCBlockedPetBuffWnd_x                                  0xE131D4
#define pinstCBodyTintWnd_x                                        0xE13970
#define pinstCBookWnd_x                                            0xE13208
#define pinstCBreathWnd_x                                          0xE134B8
#define pinstCBuffWindowNORMAL_x                                   0xE13174
#define pinstCBuffWindowSHORT_x                                    0xE13178
#define pinstCBugReportWnd_x                                       0xE1321C
#define pinstCButtonWnd_x                                          0x1602E20
#define pinstCCastingWnd_x                                         0xE131FC
#define pinstCCastSpellWnd_x                                       0xE134AC
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE13988
#define pinstCChatWindowManager_x                                  0xF80168
#define pinstCClaimWnd_x                                           0xF802C0
#define pinstCColorPickerWnd_x                                     0xE13470
#define pinstCCombatAbilityWnd_x                                   0xE13148
#define pinstCCombatSkillsSelectWnd_x                              0xE13998
#define pinstCCompassWnd_x                                         0xE13568
#define pinstCConfirmationDialog_x                                 0xF851C0
#define pinstCContainerMgr_x                                       0xE13984
#define pinstCContextMenuManager_x                                 0x1602B70
#define pinstCCursorAttachment_x                                   0xE131F0
#define pinstCDynamicZoneWnd_x                                     0xF80888
#define pinstCEditLabelWnd_x                                       0xE1316C
#define pinstCEQMainWnd_x                                          0xF80AD0
#define pinstCEventCalendarWnd_x                                   0xE134A0
#define pinstCExtendedTargetWnd_x                                  0xE131D0
#define pinstCFacePick_x                                           0xE139A8
#define pinstCFactionWnd_x                                         0xE139C4
#define pinstCFellowshipWnd_x                                      0xF80CD0
#define pinstCFileSelectionWnd_x                                   0xE1346C
#define pinstCFindItemWnd_x                                        0xE139AC
#define pinstCFindLocationWnd_x                                    0xF80E28
#define pinstCFriendsWnd_x                                         0xE139A4
#define pinstCGemsGameWnd_x                                        0xE139C0
#define pinstCGiveWnd_x                                            0xE13158
#define pinstCGroupSearchFiltersWnd_x                              0xE13200
#define pinstCGroupSearchWnd_x                                     0xF81220
#define pinstCGroupWnd_x                                           0xF812D0
#define pinstCGuildBankWnd_x                                       0xECE1C4
#define pinstCGuildCreationWnd_x                                   0xF81430
#define pinstCGuildMgmtWnd_x                                       0xF814E0
#define pinstCharacterCreation_x                                   0xE1399C
#define pinstCHelpWnd_x                                            0xE13150
#define pinstCHeritageSelectionWnd_x                               0xE139BC
#define pinstCHotButtonWnd_x                                       0xF83638
#define pinstCHotButtonWnd1_x                                      0xF83638
#define pinstCHotButtonWnd2_x                                      0xF8363C
#define pinstCHotButtonWnd3_x                                      0xF83640
#define pinstCHotButtonWnd4_x                                      0xF83644
#define pinstCIconSelectionWnd_x                                   0xE131E4
#define pinstCInspectWnd_x                                         0xE131D8
#define pinstCInventoryWnd_x                                       0xE13190
#define pinstCInvSlotMgr_x                                         0xE134B4
#define pinstCItemDisplayManager_x                                 0xF83BC8
#define pinstCItemExpTransferWnd_x                                 0xF83CF8
#define pinstCItemOverflowWnd_x                                    0xE134B0
#define pinstCJournalCatWnd_x                                      0xE13490
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE13250
#define pinstCKeyRingWnd_x                                         0xE131F8
#define pinstCLargeDialogWnd_x                                     0xF85E40
#define pinstCLayoutCopyWnd_x                                      0xF84048
#define pinstCLFGuildWnd_x                                         0xF840F8
#define pinstCLoadskinWnd_x                                        0xE13138
#define pinstCLootFiltersCopyWnd_x                                 0xCE4370
#define pinstCLootFiltersWnd_x                                     0xE1318C
#define pinstCLootSettingsWnd_x                                    0xE131CC
#define pinstCLootWnd_x                                            0xE13488
#define pinstCMailAddressBookWnd_x                                 0xE134BC
#define pinstCMailCompositionWnd_x                                 0xE13498
#define pinstCMailIgnoreListWnd_x                                  0xE134C0
#define pinstCMailWnd_x                                            0xE13474
#define pinstCManageLootWnd_x                                      0xE14828
#define pinstCMapToolbarWnd_x                                      0xE13154
#define pinstCMapViewWnd_x                                         0xE139C8
#define pinstCMarketplaceWnd_x                                     0xE13194
#define pinstCMerchantWnd_x                                        0xE13494
#define pinstCMIZoneSelectWnd_x                                    0xF84930
#define pinstCMusicPlayerWnd_x                                     0xE13238
#define pinstCNameChangeMercWnd_x                                  0xE13144
#define pinstCNameChangePetWnd_x                                   0xE139B8
#define pinstCNameChangeWnd_x                                      0xE13164
#define pinstCNoteWnd_x                                            0xE1313C
#define pinstCObjectPreviewWnd_x                                   0xE131C8
#define pinstCOptionsWnd_x                                         0xE1314C
#define pinstCPetInfoWnd_x                                         0xE1325C
#define pinstCPetitionQWnd_x                                       0xE1398C
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE1397C
#define pinstCPlayerWnd_x                                          0xE13468
#define pinstCPopupWndManager_x                                    0xF851C0
#define pinstCProgressionSelectionWnd_x                            0xF85270
#define pinstCPurchaseGroupWnd_x                                   0xE13214
#define pinstCPurchaseWnd_x                                        0xE131E8
#define pinstCPvPLeaderboardWnd_x                                  0xF85320
#define pinstCPvPStatsWnd_x                                        0xF853D0
#define pinstCQuantityWnd_x                                        0xE1324C
#define pinstCRaceChangeWnd_x                                      0xE1317C
#define pinstCRaidOptionsWnd_x                                     0xE13204
#define pinstCRaidWnd_x                                            0xE1348C
#define pinstCRealEstateItemsWnd_x                                 0xE139B0
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE134E8
#define pinstCRealEstateManageWnd_x                                0xE13220
#define pinstCRealEstateNeighborhoodWnd_x                          0xE13240
#define pinstCRealEstatePlotSearchWnd_x                            0xE13260
#define pinstCRealEstatePurchaseWnd_x                              0xE13478
#define pinstCRespawnWnd_x                                         0xE131C4
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE13990
#define pinstCSendMoneyWnd_x                                       0xE13168
#define pinstCServerListWnd_x                                      0xE1347C
#define pinstCSkillsSelectWnd_x                                    0xE13980
#define pinstCSkillsWnd_x                                          0xE13564
#define pinstCSocialEditWnd_x                                      0xE131F4
#define pinstCSocialWnd_x                                          0xE13134
#define pinstCSpellBookWnd_x                                       0xE13140
#define pinstCStoryWnd_x                                           0xE134E4
#define pinstCTargetOfTargetWnd_x                                  0xF871F8
#define pinstCTargetWnd_x                                          0xE131C0
#define pinstCTaskOverlayWnd_x                                     0xE13210
#define pinstCTaskSelectWnd_x                                      0xF87350
#define pinstCTaskManager_x                                        0xCE4CB0
#define pinstCTaskTemplateSelectWnd_x                              0xF87400
#define pinstCTaskWnd_x                                            0xF874B0
#define pinstCTextEntryWnd_x                                       0xE1320C
#define pinstCTimeLeftWnd_x                                        0xE13978
#define pinstCTipWndCONTEXT_x                                      0xF876B4
#define pinstCTipWndOFDAY_x                                        0xF876B0
#define pinstCTitleWnd_x                                           0xF87760
#define pinstCTrackingWnd_x                                        0xE1319C
#define pinstCTradeskillWnd_x                                      0xF878C8
#define pinstCTradeWnd_x                                           0xE13974
#define pinstCTrainWnd_x                                           0xE13480
#define pinstCTributeBenefitWnd_x                                  0xF87AC8
#define pinstCTributeMasterWnd_x                                   0xF87B78
#define pinstCTributeTrophyWnd_x                                   0xF87C28
#define pinstCVideoModesWnd_x                                      0xE13258
#define pinstCVoiceMacroWnd_x                                      0xF70EF8
#define pinstCVoteResultsWnd_x                                     0xE139A0
#define pinstCVoteWnd_x                                            0xE13994
#define pinstCWebManager_x                                         0xF71574
#define pinstCZoneGuideWnd_x                                       0xE13218
#define pinstCZonePathWnd_x                                        0xE13234

#define pinstEQSuiteTextureLoader_x                                0xCB2120
#define pinstItemIconCache_x                                       0xF80A88
#define pinstLootFiltersManager_x                                  0xCE4420
#define pinstRewardSelectionWnd_x                                  0xF85B18

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5BDFD0
#define __CastRay2_x                                               0x5BE020
#define __ConvertItemTags_x                                        0x5D9E60
#define __CleanItemTags_x                                          0x47CFF0
#define __DoesFileExist_x                                          0x914FA0
#define __EQGetTime_x                                              0x911A40
#define __ExecuteCmd_x                                             0x5B6870
#define __FixHeading_x                                             0x9AC610
#define __GameLoop_x                                               0x6CBBD0
#define __get_bearing_x                                            0x5BDB40
#define __get_melee_range_x                                        0x5BE210
#define __GetAnimationCache_x                                      0x731100
#define __GetGaugeValueFromEQ_x                                    0x8232B0
#define __GetLabelFromEQ_x                                         0x824D90
#define __GetXTargetType_x                                         0x9AE140
#define __HandleMouseWheel_x                                       0x6CCAB0
#define __HeadingDiff_x                                            0x9AC680
#define __HelpPath_x                                               0xF6C27C
#define __LoadFrontEnd_x                                           0x6C8EF0
#define __NewUIINI_x                                               0x822F80
#define __ProcessGameEvents_x                                      0x61EC60
#define __ProcessMouseEvent_x                                      0x61E420
#define __SaveColors_x                                             0x558A40
#define __STMLToText_x                                             0x94FB60
#define __ToggleKeyRingItem_x                                      0x519A60
#define CMemoryMappedFile__SetFile_x                               0xA9B8B0
#define CrashDetected_x                                            0x6CA990
#define DrawNetStatus_x                                            0x64AAF0
#define Expansion_HoT_x                                            0xECE1CC
#define Teleport_Table_Size_x                                      0xEC584C
#define Teleport_Table_x                                           0xEC5D08
#define Util__FastTime_x                                           0x911610

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490370
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499270
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499040
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493910
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492D60

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x560B50
#define AltAdvManager__IsAbilityReady_x                            0x55F8F0
#define AltAdvManager__GetAAById_x                                 0x55FC80
#define AltAdvManager__CanTrainAbility_x                           0x55FCF0
#define AltAdvManager__CanSeeAbility_x                             0x560050

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA080
#define CharacterZoneClient__HasSkill_x                            0x4D4F00
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6620
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE6C0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BACF0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8FB0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9090
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9170
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2DC0
#define CharacterZoneClient__BardCastBard_x                        0x4C5940
#define CharacterZoneClient__GetMaxEffects_x                       0x4BADC0
#define CharacterZoneClient__GetEffect_x                           0x4BAC30
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3E10
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3EE0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3F30
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4080
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4250
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2B50
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7580
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7000

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6F2680
#define CBankWnd__WndNotification_x                                0x6F2460

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x7000B0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x62D420
#define CButtonWnd__CButtonWnd_x                                   0x94BF40

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x7201A0
#define CChatManager__InitContextMenu_x                            0x7192D0
#define CChatManager__FreeChatWindow_x                             0x71ECE0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8570
#define CChatManager__SetLockedActiveChatWindow_x                  0x71FE20
#define CChatManager__CreateChatWindow_x                           0x71F320

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8680

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x960540
#define CContextMenu__dCContextMenu_x                              0x960780
#define CContextMenu__AddMenuItem_x                                0x960790
#define CContextMenu__RemoveMenuItem_x                             0x960AA0
#define CContextMenu__RemoveAllMenuItems_x                         0x960AC0
#define CContextMenu__CheckMenuItem_x                              0x960B40
#define CContextMenu__SetMenuItem_x                                0x9609C0
#define CContextMenu__AddSeparator_x                               0x960920

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9610E0
#define CContextMenuManager__RemoveMenu_x                          0x961150
#define CContextMenuManager__PopupMenu_x                           0x961210
#define CContextMenuManager__Flush_x                               0x961080
#define CContextMenuManager__GetMenu_x                             0x49B5C0
#define CContextMenuManager__CreateDefaultMenu_x                   0x72B900

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8ECD00
#define CChatService__GetFriendName_x                              0x8ECD10

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x720A10
#define CChatWindow__Clear_x                                       0x721CE0
#define CChatWindow__WndNotification_x                             0x722470
#define CChatWindow__AddHistory_x                                  0x7215A0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x95D9A0
#define CComboWnd__Draw_x                                          0x95CE90
#define CComboWnd__GetCurChoice_x                                  0x95D7E0
#define CComboWnd__GetListRect_x                                   0x95D340
#define CComboWnd__GetTextRect_x                                   0x95DA10
#define CComboWnd__InsertChoice_x                                  0x95D4D0
#define CComboWnd__SetColors_x                                     0x95D4A0
#define CComboWnd__SetChoice_x                                     0x95D7B0
#define CComboWnd__GetItemCount_x                                  0x95D7F0
#define CComboWnd__GetCurChoiceText_x                              0x95D830
#define CComboWnd__GetChoiceText_x                                 0x95D800
#define CComboWnd__InsertChoiceAtIndex_x                           0x95D570

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x729320
#define CContainerWnd__vftable_x                                   0xB235D4
#define CContainerWnd__SetContainer_x                              0x72A870

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x5533F0
#define CDisplay__PreZoneMainUI_x                                  0x553400
#define CDisplay__CleanGameUI_x                                    0x558800
#define CDisplay__GetClickedActor_x                                0x54B7B0
#define CDisplay__GetUserDefinedColor_x                            0x543E10
#define CDisplay__GetWorldFilePath_x                               0x54D220
#define CDisplay__is3dON_x                                         0x548410
#define CDisplay__ReloadUI_x                                       0x552870
#define CDisplay__WriteTextHD2_x                                   0x548200
#define CDisplay__TrueDistance_x                                   0x54EEE0
#define CDisplay__SetViewActor_x                                   0x54B0D0
#define CDisplay__GetFloorHeight_x                                 0x5484D0
#define CDisplay__SetRenderWindow_x                                0x546E30
#define CDisplay__ToggleScreenshotMode_x                           0x54ABA0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9801F0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x963AB0
#define CEditWnd__EnsureCaretVisible_x                             0x965C40
#define CEditWnd__GetCaretPt_x                                     0x964C20
#define CEditWnd__GetCharIndexPt_x                                 0x9649D0
#define CEditWnd__GetDisplayString_x                               0x964880
#define CEditWnd__GetHorzOffset_x                                  0x9630F0
#define CEditWnd__GetLineForPrintableChar_x                        0x965B40
#define CEditWnd__GetSelStartPt_x                                  0x964C80
#define CEditWnd__GetSTMLSafeText_x                                0x9646A0
#define CEditWnd__PointFromPrintableChar_x                         0x965780
#define CEditWnd__SelectableCharFromPoint_x                        0x9658F0
#define CEditWnd__SetEditable_x                                    0x964D40
#define CEditWnd__SetWindowTextA_x                                 0x964420
#define CEditWnd__ReplaceSelection_x                               0x965400
#define CEditWnd__ReplaceSelection1_x                              0x965380

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60C720
#define CEverQuest__ClickedPlayer_x                                0x5FE8C0
#define CEverQuest__CreateTargetIndicator_x                        0x61BEF0
#define CEverQuest__DeleteTargetIndicator_x                        0x61BF80
#define CEverQuest__DoTellWindow_x                                 0x4E8760
#define CEverQuest__OutputTextToLog_x                              0x4E8A30
#define CEverQuest__DropHeldItemOnGround_x                         0x5F39B0
#define CEverQuest__dsp_chat_x                                     0x4E8DC0
#define CEverQuest__trimName_x                                     0x618100
#define CEverQuest__Emote_x                                        0x60CF80
#define CEverQuest__EnterZone_x                                    0x607020
#define CEverQuest__GetBodyTypeDesc_x                              0x611840
#define CEverQuest__GetClassDesc_x                                 0x611E80
#define CEverQuest__GetClassThreeLetterCode_x                      0x612480
#define CEverQuest__GetDeityDesc_x                                 0x61A740
#define CEverQuest__GetLangDesc_x                                  0x612640
#define CEverQuest__GetRaceDesc_x                                  0x611E60
#define CEverQuest__InterpretCmd_x                                 0x61AD10
#define CEverQuest__LeftClickedOnPlayer_x                          0x5F7BB0
#define CEverQuest__LMouseUp_x                                     0x5F5F40
#define CEverQuest__RightClickedOnPlayer_x                         0x5F8490
#define CEverQuest__RMouseUp_x                                     0x5F6EC0
#define CEverQuest__SetGameState_x                                 0x5F3740
#define CEverQuest__UPCNotificationFlush_x                         0x618000
#define CEverQuest__IssuePetCommand_x                              0x613A40
#define CEverQuest__ReportSuccessfulHit_x                          0x60E2D0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x73B230
#define CGaugeWnd__CalcLinesFillRect_x                             0x73B290
#define CGaugeWnd__Draw_x                                          0x73A8C0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF650
#define CGuild__GetGuildName_x                                     0x4AE690
#define CGuild__GetGuildIndex_x                                    0x4AEAD0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x755430

//CHotButton
#define CHotButton__SetButtonSize_x                                0x62D7E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x762450
#define CInvSlotMgr__MoveItem_x                                    0x761160
#define CInvSlotMgr__SelectSlot_x                                  0x762520

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x75F9D0
#define CInvSlot__SliderComplete_x                                 0x75D730
#define CInvSlot__GetItemBase_x                                    0x75D0B0
#define CInvSlot__UpdateItem_x                                     0x75D220

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x763FA0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x763140
#define CInvSlotWnd__HandleLButtonUp_x                             0x763B20

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x81E660
#define CItemDisplayWnd__UpdateStrings_x                           0x7727C0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x76C450
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x76C980
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x772DC0
#define CItemDisplayWnd__AboutToShow_x                             0x772410
#define CItemDisplayWnd__WndNotification_x                         0x773F00
#define CItemDisplayWnd__RequestConvertItem_x                      0x773970
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x771470
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x772230

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8570A0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x778400

// CLabel 
#define CLabel__Draw_x                                             0x77DE60

// CListWnd
#define CListWnd__CListWnd_x                                       0x936180
#define CListWnd__dCListWnd_x                                      0x9364A0
#define CListWnd__AddColumn_x                                      0x93A8E0
#define CListWnd__AddColumn1_x                                     0x93A930
#define CListWnd__AddLine_x                                        0x93ACC0
#define CListWnd__AddString_x                                      0x93AAC0
#define CListWnd__CalculateFirstVisibleLine_x                      0x93A6B0
#define CListWnd__CalculateVSBRange_x                              0x93A4A0
#define CListWnd__ClearSel_x                                       0x93B4A0
#define CListWnd__ClearAllSel_x                                    0x93B500
#define CListWnd__CloseAndUpdateEditWindow_x                       0x93BEF0
#define CListWnd__Compare_x                                        0x939DD0
#define CListWnd__Draw_x                                           0x9365D0
#define CListWnd__DrawColumnSeparators_x                           0x938DB0
#define CListWnd__DrawHeader_x                                     0x939210
#define CListWnd__DrawItem_x                                       0x939710
#define CListWnd__DrawLine_x                                       0x938F10
#define CListWnd__DrawSeparator_x                                  0x938E50
#define CListWnd__EnableLine_x                                     0x938690
#define CListWnd__EnsureVisible_x                                  0x93BE20
#define CListWnd__ExtendSel_x                                      0x93B3D0
#define CListWnd__GetColumnTooltip_x                               0x9381D0
#define CListWnd__GetColumnMinWidth_x                              0x938240
#define CListWnd__GetColumnWidth_x                                 0x938140
#define CListWnd__GetCurSel_x                                      0x937AD0
#define CListWnd__GetItemAtPoint_x                                 0x938900
#define CListWnd__GetItemAtPoint1_x                                0x938970
#define CListWnd__GetItemData_x                                    0x937B50
#define CListWnd__GetItemHeight_x                                  0x937F10
#define CListWnd__GetItemIcon_x                                    0x937CE0
#define CListWnd__GetItemRect_x                                    0x938780
#define CListWnd__GetItemText_x                                    0x937B90
#define CListWnd__GetSelList_x                                     0x93B550
#define CListWnd__GetSeparatorRect_x                               0x938BB0
#define CListWnd__InsertLine_x                                     0x93B0B0
#define CListWnd__RemoveLine_x                                     0x93B200
#define CListWnd__SetColors_x                                      0x93A470
#define CListWnd__SetColumnJustification_x                         0x93A1A0
#define CListWnd__SetColumnLabel_x                                 0x93AA60
#define CListWnd__SetColumnWidth_x                                 0x93A0C0
#define CListWnd__SetCurSel_x                                      0x93B310
#define CListWnd__SetItemColor_x                                   0x93BAE0
#define CListWnd__SetItemData_x                                    0x93BAA0
#define CListWnd__SetItemText_x                                    0x93B6C0
#define CListWnd__ShiftColumnSeparator_x                           0x93A260
#define CListWnd__Sort_x                                           0x939F50
#define CListWnd__ToggleSel_x                                      0x93B340
#define CListWnd__SetColumnsSizable_x                              0x93A310
#define CListWnd__SetItemWnd_x                                     0x93B970
#define CListWnd__GetItemWnd_x                                     0x937D30
#define CListWnd__SetItemIcon_x                                    0x93B740
#define CListWnd__CalculateCustomWindowPositions_x                 0x93A7A0
#define CListWnd__SetVScrollPos_x                                  0x93A0A0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x793650
#define CMapViewWnd__GetWorldCoordinates_x                         0x791D60
#define CMapViewWnd__HandleLButtonDown_x                           0x78EDA0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7B37A0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7B4080
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7B45B0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7B7540
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7B2300
#define CMerchantWnd__SelectBuySellSlot_x                          0x7BD100
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7B33B0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8BA6B0
#define CPacketScrambler__hton_x                                   0x8BA6A0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x955140
#define CSidlManager__FindScreenPieceTemplate_x                    0x955550
#define CSidlManager__FindScreenPieceTemplate1_x                   0x955340
#define CSidlManager__CreateLabel_x                                0x8158E0
#define CSidlManager__CreateXWndFromTemplate_x                     0x9584B0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x958690
#define CSidlManager__CreateXWnd_x                                 0x815810
#define CSidlManager__CreateHotButtonWnd_x                         0x815DE0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x951C50
#define CSidlScreenWnd__CalculateVSBRange_x                        0x951B60
#define CSidlScreenWnd__ConvertToRes_x                             0x97ACE0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9515F0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9512E0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9513B0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x951480
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9520E0
#define CSidlScreenWnd__EnableIniStorage_x                         0x9525B0
#define CSidlScreenWnd__GetSidlPiece_x                             0x9522D0
#define CSidlScreenWnd__Init1_x                                    0x950F00
#define CSidlScreenWnd__LoadIniInfo_x                              0x952600
#define CSidlScreenWnd__LoadIniListWnd_x                           0x953120
#define CSidlScreenWnd__LoadSidlScreen_x                           0x950310
#define CSidlScreenWnd__StoreIniInfo_x                             0x952CA0
#define CSidlScreenWnd__StoreIniVis_x                              0x953000
#define CSidlScreenWnd__WndNotification_x                          0x951FF0
#define CSidlScreenWnd__GetChildItem_x                             0x952530
#define CSidlScreenWnd__HandleLButtonUp_x                          0x941D20
#define CSidlScreenWnd__m_layoutCopy_x                             0x1602A40

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x692540
#define CSkillMgr__GetSkillCap_x                                   0x692720
#define CSkillMgr__GetNameToken_x                                  0x691CC0
#define CSkillMgr__IsActivatedSkill_x                              0x691E00
#define CSkillMgr__IsCombatSkill_x                                 0x691D40

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x961ED0
#define CSliderWnd__SetValue_x                                     0x961D40
#define CSliderWnd__SetNumTicks_x                                  0x961DA0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x81BA30

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x96A6B0
#define CStmlWnd__ParseSTML_x                                      0x96BA20
#define CStmlWnd__CalculateHSBRange_x                              0x96B800
#define CStmlWnd__CalculateVSBRange_x                              0x96B780
#define CStmlWnd__CanBreakAtCharacter_x                            0x96FB30
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9707C0
#define CStmlWnd__ForceParseNow_x                                  0x96ACE0
#define CStmlWnd__GetNextTagPiece_x                                0x96FA90
#define CStmlWnd__GetSTMLText_x                                    0x509400
#define CStmlWnd__GetVisibleText_x                                 0x96AD00
#define CStmlWnd__InitializeWindowVariables_x                      0x970610
#define CStmlWnd__MakeStmlColorTag_x                               0x969D20
#define CStmlWnd__MakeWndNotificationTag_x                         0x969D90
#define CStmlWnd__SetSTMLText_x                                    0x968DD0
#define CStmlWnd__StripFirstSTMLLines_x                            0x971880
#define CStmlWnd__UpdateHistoryString_x                            0x9709D0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x967F00
#define CTabWnd__DrawCurrentPage_x                                 0x968630
#define CTabWnd__DrawTab_x                                         0x968350
#define CTabWnd__GetCurrentPage_x                                  0x967700
#define CTabWnd__GetPageInnerRect_x                                0x967940
#define CTabWnd__GetTabInnerRect_x                                 0x967880
#define CTabWnd__GetTabRect_x                                      0x967730
#define CTabWnd__InsertPage_x                                      0x967B50
#define CTabWnd__RemovePage_x                                      0x967CC0
#define CTabWnd__SetPage_x                                         0x9679C0
#define CTabWnd__SetPageRect_x                                     0x967E40
#define CTabWnd__UpdatePage_x                                      0x968210
#define CTabWnd__GetPageFromTabIndex_x                             0x968290
#define CTabWnd__GetCurrentTabIndex_x                              0x9676F0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7787F0
#define CPageWnd__SetTabText_x                                     0x967240
#define CPageWnd__FlashTab_x                                       0x9672A0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8FA0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x93EBD0
#define CTextureFont__GetTextExtent_x                              0x93ED90

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6C5A90
#define CHtmlComponentWnd__ValidateUri_x                           0x756E20
#define CHtmlWnd__SetClientCallbacks_x                             0x632870
#define CHtmlWnd__AddObserver_x                                    0x632890
#define CHtmlWnd__RemoveObserver_x                                 0x6328F0
#define Window__getProgress_x                                      0x86F7F0
#define Window__getStatus_x                                        0x86F810
#define Window__getURI_x                                           0x86F820

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x977AF0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x92BDA0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E83B0
#define CXStr__CXStr1_x                                            0xA02E10
#define CXStr__CXStr3_x                                            0x90DBA0
#define CXStr__dCXStr_x                                            0x478770
#define CXStr__operator_equal_x                                    0x90DDD0
#define CXStr__operator_equal1_x                                   0x90DE10
#define CXStr__operator_plus_equal1_x                              0x90E8A0
#define CXStr__SetString_x                                         0x910790
#define CXStr__operator_char_p_x                                   0x90E2E0
#define CXStr__GetChar_x                                           0x9100C0
#define CXStr__Delete_x                                            0x90F990
#define CXStr__GetUnicode_x                                        0x910130
#define CXStr__GetLength_x                                         0x47D3A0
#define CXStr__Mid_x                                               0x47D3B0
#define CXStr__Insert_x                                            0x910190
#define CXStr__FindNext_x                                          0x90FE00

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x960160
#define CXWnd__BringToTop_x                                        0x945440
#define CXWnd__Center_x                                            0x944FC0
#define CXWnd__ClrFocus_x                                          0x944DE0
#define CXWnd__Destroy_x                                           0x944E80
#define CXWnd__DoAllDrawing_x                                      0x9414B0
#define CXWnd__DrawChildren_x                                      0x941480
#define CXWnd__DrawColoredRect_x                                   0x941910
#define CXWnd__DrawTooltip_x                                       0x93FFC0
#define CXWnd__DrawTooltipAtPoint_x                                0x940080
#define CXWnd__GetBorderFrame_x                                    0x941770
#define CXWnd__GetChildWndAt_x                                     0x9454E0
#define CXWnd__GetClientClipRect_x                                 0x943740
#define CXWnd__GetScreenClipRect_x                                 0x943810
#define CXWnd__GetScreenRect_x                                     0x9439D0
#define CXWnd__GetRelativeRect_x                                   0x943A80
#define CXWnd__GetTooltipRect_x                                    0x941960
#define CXWnd__GetWindowTextA_x                                    0x49CC90
#define CXWnd__IsActive_x                                          0x942090
#define CXWnd__IsDescendantOf_x                                    0x944390
#define CXWnd__IsReallyVisible_x                                   0x9443C0
#define CXWnd__IsType_x                                            0x945B40
#define CXWnd__Move_x                                              0x944420
#define CXWnd__Move1_x                                             0x9444D0
#define CXWnd__ProcessTransition_x                                 0x944F70
#define CXWnd__Refade_x                                            0x944780
#define CXWnd__Resize_x                                            0x944A20
#define CXWnd__Right_x                                             0x945200
#define CXWnd__SetFocus_x                                          0x944DA0
#define CXWnd__SetFont_x                                           0x944E10
#define CXWnd__SetKeyTooltip_x                                     0x945960
#define CXWnd__SetMouseOver_x                                      0x942890
#define CXWnd__StartFade_x                                         0x944270
#define CXWnd__GetChildItem_x                                      0x945650
#define CXWnd__SetParent_x                                         0x944130
#define CXWnd__Minimize_x                                          0x944A90

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x97BD60

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x948390
#define CXWndManager__DrawWindows_x                                0x9483B0
#define CXWndManager__GetKeyboardFlags_x                           0x94ABB0
#define CXWndManager__HandleKeyboardMsg_x                          0x94A760
#define CXWndManager__RemoveWnd_x                                  0x94ADE0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x94B360

// CDBStr
#define CDBStr__GetString_x                                        0x542DE0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBCD0
#define EQ_Character__Cur_HP_x                                     0x4D1F40
#define EQ_Character__Cur_Mana_x                                   0x4D9670
#define EQ_Character__GetCastingTimeModifier_x                     0x4BED10
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2790
#define EQ_Character__GetFocusRangeModifier_x                      0x4B28E0
#define EQ_Character__GetHPRegen_x                                 0x4DF410
#define EQ_Character__GetEnduranceRegen_x                          0x4DFA10
#define EQ_Character__GetManaRegen_x                               0x4DFE50
#define EQ_Character__Max_Endurance_x                              0x6592C0
#define EQ_Character__Max_HP_x                                     0x4D1D70
#define EQ_Character__Max_Mana_x                                   0x6590C0
#define EQ_Character__doCombatAbility_x                            0x65B6F0
#define EQ_Character__UseSkill_x                                   0x4E1C40
#define EQ_Character__GetConLevel_x                                0x651A60
#define EQ_Character__IsExpansionFlag_x                            0x5B50C0
#define EQ_Character__TotalEffect_x                                0x4C5080
#define EQ_Character__GetPCSpellAffect_x                           0x4BFA60
#define EQ_Character__SpellDuration_x                              0x4BF590
#define EQ_Character__MySpellDuration_x                            0x4B10C0
#define EQ_Character__GetAdjustedSkill_x                           0x4D4CC0
#define EQ_Character__GetBaseSkill_x                               0x4D5C60
#define EQ_Character__CanUseItem_x                                 0x4D9980

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8D9B10

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x66F5F0

//PcClient
#define PcClient__PcClient_x                                       0x64F1A0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9900
#define CCharacterListWnd__EnterWorld_x                            0x4B9340
#define CCharacterListWnd__Quit_x                                  0x4B9090
#define CCharacterListWnd__UpdateList_x                            0x4B94D0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x633A30
#define EQ_Item__CreateItemTagString_x                             0x8B3D10
#define EQ_Item__IsStackable_x                                     0x8B8930
#define EQ_Item__GetImageNum_x                                     0x8B5870
#define EQ_Item__CreateItemClient_x                                0x632C70
#define EQ_Item__GetItemValue_x                                    0x8B6B80
#define EQ_Item__ValueSellMerchant_x                               0x8BA290
#define EQ_Item__IsKeyRingItem_x                                   0x8B8250
#define EQ_Item__CanGoInBag_x                                      0x633B50
#define EQ_Item__IsEmpty_x                                         0x8B7D90
#define EQ_Item__GetMaxItemCount_x                                 0x8B6F90
#define EQ_Item__GetHeldItem_x                                     0x8B5740
#define EQ_Item__GetAugmentFitBySlot_x                             0x8B3550

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5618E0
#define EQ_LoadingS__Array_x                                       0xC39C60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x659C00
#define EQ_PC__GetAlternateAbilityId_x                             0x8C3740
#define EQ_PC__GetCombatAbility_x                                  0x8C3DB0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8C3E20
#define EQ_PC__GetItemRecastTimer_x                                0x65BC70
#define EQ_PC__HasLoreItem_x                                       0x652270
#define EQ_PC__AlertInventoryChanged_x                             0x6513A0
#define EQ_PC__GetPcZoneClient_x                                   0x67E0C0
#define EQ_PC__RemoveMyAffect_x                                    0x65EEA0
#define EQ_PC__GetKeyRingItems_x                                   0x8C46B0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8C4440
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8C49B0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BB570
#define EQItemList__add_object_x                                   0x5E9150
#define EQItemList__add_item_x                                     0x5BBAD0
#define EQItemList__delete_item_x                                  0x5BBB20
#define EQItemList__FreeItemList_x                                 0x5BBA20

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53F930

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x670E70
#define EQPlayer__dEQPlayer_x                                      0x664360
#define EQPlayer__DoAttack_x                                       0x678D70
#define EQPlayer__EQPlayer_x                                       0x664A20
#define EQPlayer__SetNameSpriteState_x                             0x668C80
#define EQPlayer__SetNameSpriteTint_x                              0x669B50
#define PlayerBase__HasProperty_j_x                                0x9AAA20
#define EQPlayer__IsTargetable_x                                   0x9AAEC0
#define EQPlayer__CanSee_x                                         0x9AAD20
#define EQPlayer__CanSee1_x                                        0x9AADF0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9AAAE0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67BB50
#define PlayerZoneClient__GetLevel_x                               0x67E100
#define PlayerZoneClient__IsValidTeleport_x                        0x5EA2C0
#define PlayerZoneClient__LegalPlayerRace_x                        0x55A630

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x673C30
#define EQPlayerManager__GetSpawnByName_x                          0x673CE0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x673D70

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x637140
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6371C0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x637200
#define KeypressHandler__ClearCommandStateArray_x                  0x638610
#define KeypressHandler__HandleKeyDown_x                           0x638630
#define KeypressHandler__HandleKeyUp_x                             0x6386D0
#define KeypressHandler__SaveKeymapping_x                          0x638B20

// MapViewMap 
#define MapViewMap__Clear_x                                        0x78F4C0
#define MapViewMap__SaveEx_x                                       0x792880
#define MapViewMap__SetZoom_x                                      0x796F40

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8D7A90

// StringTable 
#define StringTable__getString_x                                   0x8D28F0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x65EB10
#define PcZoneClient__RemovePetEffect_x                            0x65F140
#define PcZoneClient__HasAlternateAbility_x                        0x658EF0
#define PcZoneClient__GetCurrentMod_x                              0x4E4D00
#define PcZoneClient__GetModCap_x                                  0x4E4C00
#define PcZoneClient__CanEquipItem_x                               0x6595A0
#define PcZoneClient__GetItemByID_x                                0x65C0E0
#define PcZoneClient__GetItemByItemClass_x                         0x65C230
#define PcZoneClient__RemoveBuffEffect_x                           0x65F160
#define PcZoneClient__BandolierSwap_x                              0x65A1C0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65BC10

//Doors
#define EQSwitch__UseSwitch_x                                      0x5EEE30

//IconCache
#define IconCache__GetIcon_x                                       0x7309A0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7284C0
#define CContainerMgr__CloseContainer_x                            0x728790
#define CContainerMgr__OpenExperimentContainer_x                   0x729210

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7E7C00

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62BC10

//CLootWnd
#define CLootWnd__LootAll_x                                        0x785940
#define CLootWnd__RequestLootSlot_x                                0x784B70

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x587EA0
#define EQ_Spell__SpellAffects_x                                   0x588310
#define EQ_Spell__SpellAffectBase_x                                0x5880D0
#define EQ_Spell__IsStackable_x                                    0x4C9960
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9750
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6C60
#define EQ_Spell__IsSPAStacking_x                                  0x589160
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x588670
#define EQ_Spell__IsNoRemove_x                                     0x4C9940
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x589170
#define __IsResEffectSpell_x                                       0x4C8B00

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD170

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8E21C0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x82ED90
#define CTargetWnd__WndNotification_x                              0x82E5D0
#define CTargetWnd__RefreshTargetBuffs_x                           0x82E8A0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x82D740

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8333D0
#define CTaskWnd__ConfirmAbandonTask_x                             0x836010

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53D3A0
#define CTaskManager__HandleMessage_x                              0x53B850
#define CTaskManager__GetTaskStatus_x                              0x53D450
#define CTaskManager__GetElementDescription_x                      0x53D4D0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5830C0
#define EqSoundManager__PlayScriptMp3_x                            0x583380
#define EqSoundManager__SoundAssistPlay_x                          0x6964B0
#define EqSoundManager__WaveInstancePlay_x                         0x695A20

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52EA10

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x966740
#define CTextureAnimation__Draw_x                                  0x966940

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x962830

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x569380
#define CAltAbilityData__GetMercMaxRank_x                          0x569310
#define CAltAbilityData__GetMaxRank_x                              0x55E770

//CTargetRing
#define CTargetRing__Cast_x                                        0x629D30

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9730
#define CharacterBase__CreateItemGlobalIndex_x                     0x516100
#define CharacterBase__CreateItemIndex_x                           0x631E20
#define CharacterBase__GetItemPossession_x                         0x501DF0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8EA8F0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8EA950
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x70F4C0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x70FCF0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x70FDA0

//messages
#define msg_spell_worn_off_x                                       0x5ACFF0
#define msg_new_text_x                                             0x5A1970
#define __msgTokenTextParam_x                                      0x5AF290
#define msgTokenText_x                                             0x5AF4E0

//SpellManager
#define SpellManager__vftable_x                                    0xAFD150
#define SpellManager__SpellManager_x                               0x6997E0
#define Spellmanager__LoadTextSpells_x                             0x69A0D0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6999B0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9AEA30

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x516750
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B3470
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64A950
#define ItemGlobalIndex__IsValidIndex_x                            0x5167B0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8E2B60
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8E2DE0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x77E1A0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x72CBA0
#define CCursorAttachment__AttachToCursor1_x                       0x72CBE0
#define CCursorAttachment__Deactivate_x                            0x72DBC0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x9594F0
#define CSidlManagerBase__CreatePageWnd_x                          0x958CE0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x954F60
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x954EF0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x976470
#define CEQSuiteTextureLoader__GetTexture_x                        0x976130

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x513670
#define CFindItemWnd__WndNotification_x                            0x514150
#define CFindItemWnd__Update_x                                     0x514CC0
#define CFindItemWnd__PickupSelectedItem_x                         0x512EB0

//IString
#define IString__Append_x                                          0x503640

//Camera
#define CDisplay__cameraType_x                                     0xE13264
#define EverQuest__Cameras_x                                       0xECE51C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51BE00
#define LootFiltersManager__GetItemFilterData_x                    0x51B700
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51B730
#define LootFiltersManager__SetItemLootFilter_x                    0x51B950

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7D5A00

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9B4600
#define CResolutionHandler__GetWindowedStyle_x                     0x691070

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x725170

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8F8060
#define CDistillerInfo__Instance_x                                 0x8F8000

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x744200
#define CGroupWnd__UpdateDisplay_x                                 0x743550

//ItemBase
#define ItemBase__IsLore_x                                         0x8B8300
#define ItemBase__IsLoreEquipped_x                                 0x8B8370

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5E90B0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5E91F0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5E9250

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6867D0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68A140

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x509AA0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F5F90
#define FactionManagerClient__HandleFactionMessage_x               0x4F6600
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F6BC0
#define FactionManagerClient__GetMaxFaction_x                      0x4F6BDF
#define FactionManagerClient__GetMinFaction_x                      0x4F6B90

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x501DC0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x93DB90

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BFA0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x502050

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x568830

//CTargetManager
#define CTargetManager__Get_x                                      0x69D070

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6867D0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8D60

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BB9C0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF6BBB0

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6D8DF0
#define CAAWnd__UpdateSelected_x                                   0x6D5660
#define CAAWnd__Update_x                                           0x6D8110

//CXRect
#define CXRect__operator_and_x                                     0x73B2F0

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
