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
#define __ExpectedVersionDate                                     "Jul  7 2020"
#define __ExpectedVersionTime                                     "11:34:32"
#define __ActualVersionDate_x                                      0xB1C6AC
#define __ActualVersionTime_x                                      0xB1C6A0
#define __ActualVersionBuild_x                                     0xB0832C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x640140
#define __MemChecker1_x                                            0x919E30
#define __MemChecker2_x                                            0x6CEF20
#define __MemChecker3_x                                            0x6CEE70
#define __MemChecker4_x                                            0x870970
#define __EncryptPad0_x                                            0xC57520
#define __EncryptPad1_x                                            0xCB5700
#define __EncryptPad2_x                                            0xC67DB8
#define __EncryptPad3_x                                            0xC679B8
#define __EncryptPad4_x                                            0xCA5C90
#define __EncryptPad5_x                                            0xF77BD0
#define __AC1_x                                                    0x827226
#define __AC2_x                                                    0x5F9ABF
#define __AC3_x                                                    0x60110F
#define __AC4_x                                                    0x6050D0
#define __AC5_x                                                    0x60B38F
#define __AC6_x                                                    0x60F896
#define __AC7_x                                                    0x5F9530
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x70E0C

// Direct Input
#define DI8__Main_x                                                0xF77BF0
#define DI8__Keyboard_x                                            0xF77BF4
#define DI8__Mouse_x                                               0xF77C0C
#define DI8__Mouse_Copy_x                                          0xED0DBC
#define DI8__Mouse_Check_x                                         0xF75724
#define __AutoSkillArray_x                                         0xED1CD4
#define __Attack_x                                                 0xF6FAFB
#define __Autofire_x                                               0xF6FAFC
#define __BindList_x                                               0xC45F38
#define g_eqCommandStates_x                                        0xC46CB8
#define __Clicks_x                                                 0xED0E74
#define __CommandList_x                                            0xC47878
#define __CurrentMapLabel_x                                        0xF885C4
#define __CurrentSocial_x                                          0xC2F7C8
#define __DoAbilityList_x                                          0xF0761C
#define __do_loot_x                                                0x5C5770
#define __DrawHandler_x                                            0x16076E8
#define __GroupCount_x                                             0xECBE92
#define __Guilds_x                                                 0xECFCF8
#define __gWorld_x                                                 0xECBD28
#define __HWnd_x                                                   0xF77C10
#define __heqmain_x                                                0xF77BB8
#define __InChatMode_x                                             0xED0DA4
#define __LastTell_x                                               0xED2D18
#define __LMouseHeldTime_x                                         0xED0EE0
#define __Mouse_x                                                  0xF77BDC
#define __MouseLook_x                                              0xED0E3A
#define __MouseEventTime_x                                         0xF705DC
#define __gpbCommandEvent_x                                        0xEC978C
#define __NetStatusToggle_x                                        0xED0E3D
#define __PCNames_x                                                0xED22C4
#define __RangeAttackReady_x                                       0xED1FB8
#define __RMouseHeldTime_x                                         0xED0EDC
#define __RunWalkState_x                                           0xED0DA8
#define __ScreenMode_x                                             0xE17138
#define __ScreenX_x                                                0xED0D5C
#define __ScreenY_x                                                0xED0D58
#define __ScreenXMax_x                                             0xED0D60
#define __ScreenYMax_x                                             0xED0D64
#define __ServerHost_x                                             0xEC9973
#define __ServerName_x                                             0xF075DC
#define __ShiftKeyDown_x                                           0xED1434
#define __ShowNames_x                                              0xED2174
#define EverQuestInfo__bSocialChanged_x                            0xF07664
#define __Socials_x                                                0xF076DC
#define __SubscriptionType_x                                       0xFCC9B8
#define __TargetAggroHolder_x                                      0xF8AF78
#define __ZoneType_x                                               0xED1238
#define __GroupAggro_x                                             0xF8AFB8
#define __LoginName_x                                              0xF7834C
#define __Inviter_x                                                0xF6FA78
#define __AttackOnAssist_x                                         0xED2130
#define __UseTellWindows_x                                         0xED2460
#define __gfMaxZoomCameraDistance_x                                0xB11F90
#define __gfMaxCameraDistance_x                                    0xB3E428
#define __pulAutoRun_x                                             0xED0E58
#define __pulForward_x                                             0xED2498
#define __pulBackward_x                                            0xED249C
#define __pulTurnRight_x                                           0xED24A0
#define __pulTurnLeft_x                                            0xED24A4
#define __pulStrafeLeft_x                                          0xED24A8
#define __pulStrafeRight_x                                         0xED24AC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xECC090
#define instEQZoneInfo_x                                           0xED1030
#define pinstActiveBanker_x                                        0xEC9868
#define pinstActiveCorpse_x                                        0xEC9860
#define pinstActiveGMaster_x                                       0xEC9864
#define pinstActiveMerchant_x                                      0xEC985C
#define pinstAltAdvManager_x                                       0xE182C0
#define pinstBandageTarget_x                                       0xEC9C88
#define pinstCamActor_x                                            0xE17124
#define pinstCDBStr_x                                              0xE16FDC
#define pinstCDisplay_x                                            0xECBCE0
#define pinstCEverQuest_x                                          0xF77C08
#define pinstEverQuestInfo_x                                       0xED0D50
#define pinstCharData_x                                            0xECBE7C
#define pinstCharSpawn_x                                           0xEC9CC0
#define pinstControlledMissile_x                                   0xEC9CD0
#define pinstControlledPlayer_x                                    0xEC9CC0
#define pinstCResolutionHandler_x                                  0x1607918
#define pinstCSidlManager_x                                        0x16068B0
#define pinstCXWndManager_x                                        0x16068AC
#define instDynamicZone_x                                          0xECFBD0
#define pinstDZMember_x                                            0xECFCE0
#define pinstDZTimerInfo_x                                         0xECFCE4
#define pinstEqLogin_x                                             0xF77C98
#define instEQMisc_x                                               0xE16F20
#define pinstEQSoundManager_x                                      0xE19290
#define pinstEQSpellStrings_x                                      0xCD9938
#define instExpeditionLeader_x                                     0xECFC1A
#define instExpeditionName_x                                       0xECFC5A
#define pinstGroup_x                                               0xECBE8E
#define pinstImeManager_x                                          0x16068A8
#define pinstLocalPlayer_x                                         0xEC9858
#define pinstMercenaryData_x                                       0xF720D4
#define pinstMercenaryStats_x                                      0xF8B0C4
#define pinstModelPlayer_x                                         0xEC9A7C
#define pinstPCData_x                                              0xECBE7C
#define pinstSkillMgr_x                                            0xF74238
#define pinstSpawnManager_x                                        0xF72CE0
#define pinstSpellManager_x                                        0xF74478
#define pinstSpellSets_x                                           0xF68724
#define pinstStringTable_x                                         0xECC084
#define pinstSwitchManager_x                                       0xEC9630
#define pinstTarget_x                                              0xEC9CBC
#define pinstTargetObject_x                                        0xEC9CC8
#define pinstTargetSwitch_x                                        0xECBCD8
#define pinstTaskMember_x                                          0xE16DB0
#define pinstTrackTarget_x                                         0xEC9CC4
#define pinstTradeTarget_x                                         0xEC986C
#define instTributeActive_x                                        0xE16F41
#define pinstViewActor_x                                           0xE17120
#define pinstWorldData_x                                           0xECC088
#define pinstZoneAddr_x                                            0xED12D0
#define pinstPlayerPath_x                                          0xF72D78
#define pinstTargetIndicator_x                                     0xF746E0
#define EQObject_Top_x                                             0xEC9854
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE17444
#define pinstCAchievementsWnd_x                                    0xE170B4
#define pinstCActionsWnd_x                                         0xE178E4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE17164
#define pinstCAdvancedLootWnd_x                                    0xE17100
#define pinstCAdventureLeaderboardWnd_x                            0xF81D98
#define pinstCAdventureRequestWnd_x                                0xF81E48
#define pinstCAdventureStatsWnd_x                                  0xF81EF8
#define pinstCAggroMeterWnd_x                                      0xE17168
#define pinstCAlarmWnd_x                                           0xE170CC
#define pinstCAlertHistoryWnd_x                                    0xE171DC
#define pinstCAlertStackWnd_x                                      0xE17118
#define pinstCAlertWnd_x                                           0xE1714C
#define pinstCAltStorageWnd_x                                      0xF82258
#define pinstCAudioTriggersWindow_x                                0xCCBC68
#define pinstCAuraWnd_x                                            0xE17104
#define pinstCAvaZoneWnd_x                                         0xE1719C
#define pinstCBandolierWnd_x                                       0xE17160
#define pinstCBankWnd_x                                            0xE17198
#define pinstCBarterMerchantWnd_x                                  0xF83498
#define pinstCBarterSearchWnd_x                                    0xF83548
#define pinstCBarterWnd_x                                          0xF835F8
#define pinstCBazaarConfirmationWnd_x                              0xE170E8
#define pinstCBazaarSearchWnd_x                                    0xE17448
#define pinstCBazaarWnd_x                                          0xE170B0
#define pinstCBlockedBuffWnd_x                                     0xE17110
#define pinstCBlockedPetBuffWnd_x                                  0xE17150
#define pinstCBodyTintWnd_x                                        0xE178F0
#define pinstCBookWnd_x                                            0xE17190
#define pinstCBreathWnd_x                                          0xE174D0
#define pinstCBuffWindowNORMAL_x                                   0xE170F4
#define pinstCBuffWindowSHORT_x                                    0xE170F8
#define pinstCBugReportWnd_x                                       0xE17194
#define pinstCButtonWnd_x                                          0x1606B18
#define pinstCCastingWnd_x                                         0xE1717C
#define pinstCCastSpellWnd_x                                       0xE174C8
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE1790C
#define pinstCChatWindowManager_x                                  0xF840B8
#define pinstCClaimWnd_x                                           0xF84210
#define pinstCColorPickerWnd_x                                     0xE173FC
#define pinstCCombatAbilityWnd_x                                   0xE170C4
#define pinstCCombatSkillsSelectWnd_x                              0xE17078
#define pinstCCompassWnd_x                                         0xE178E8
#define pinstCConfirmationDialog_x                                 0xF89110
#define pinstCContainerMgr_x                                       0xE17904
#define pinstCContextMenuManager_x                                 0x1606868
#define pinstCCursorAttachment_x                                   0xE17170
#define pinstCDynamicZoneWnd_x                                     0xF847D8
#define pinstCEditLabelWnd_x                                       0xE170EC
#define pinstCEQMainWnd_x                                          0xF84A20
#define pinstCEventCalendarWnd_x                                   0xE174CC
#define pinstCExtendedTargetWnd_x                                  0xE17148
#define pinstCFacePick_x                                           0xE17090
#define pinstCFactionWnd_x                                         0xE1709C
#define pinstCFellowshipWnd_x                                      0xF84C20
#define pinstCFileSelectionWnd_x                                   0xE171F0
#define pinstCFindItemWnd_x                                        0xE17088
#define pinstCFindLocationWnd_x                                    0xF84D78
#define pinstCFriendsWnd_x                                         0xE1708C
#define pinstCGemsGameWnd_x                                        0xE17098
#define pinstCGiveWnd_x                                            0xE170D4
#define pinstCGroupSearchFiltersWnd_x                              0xE17184
#define pinstCGroupSearchWnd_x                                     0xF85170
#define pinstCGroupWnd_x                                           0xF85220
#define pinstCGuildBankWnd_x                                       0xED2114
#define pinstCGuildCreationWnd_x                                   0xF85380
#define pinstCGuildMgmtWnd_x                                       0xF85430
#define pinstCharacterCreation_x                                   0xE17080
#define pinstCHelpWnd_x                                            0xE170D0
#define pinstCHeritageSelectionWnd_x                               0xE170A0
#define pinstCHotButtonWnd_x                                       0xF87588
#define pinstCHotButtonWnd1_x                                      0xF87588
#define pinstCHotButtonWnd2_x                                      0xF8758C
#define pinstCHotButtonWnd3_x                                      0xF87590
#define pinstCHotButtonWnd4_x                                      0xF87594
#define pinstCIconSelectionWnd_x                                   0xE1716C
#define pinstCInspectWnd_x                                         0xE17154
#define pinstCInventoryWnd_x                                       0xE17108
#define pinstCInvSlotMgr_x                                         0xE174C4
#define pinstCItemDisplayManager_x                                 0xF87B18
#define pinstCItemExpTransferWnd_x                                 0xF87C48
#define pinstCItemOverflowWnd_x                                    0xE1745C
#define pinstCJournalCatWnd_x                                      0xE17408
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE171C0
#define pinstCKeyRingWnd_x                                         0xE17178
#define pinstCLargeDialogWnd_x                                     0xF89D90
#define pinstCLayoutCopyWnd_x                                      0xF87F98
#define pinstCLFGuildWnd_x                                         0xF88048
#define pinstCLoadskinWnd_x                                        0xE170AC
#define pinstCLootFiltersCopyWnd_x                                 0xCE82B8
#define pinstCLootFiltersWnd_x                                     0xE17128
#define pinstCLootSettingsWnd_x                                    0xE1715C
#define pinstCLootWnd_x                                            0xE1740C
#define pinstCMailAddressBookWnd_x                                 0xE174D4
#define pinstCMailCompositionWnd_x                                 0xE17440
#define pinstCMailIgnoreListWnd_x                                  0xE174D8
#define pinstCMailWnd_x                                            0xE17400
#define pinstCManageLootWnd_x                                      0xE18770
#define pinstCMapToolbarWnd_x                                      0xE170D8
#define pinstCMapViewWnd_x                                         0xE170A8
#define pinstCMarketplaceWnd_x                                     0xE17144
#define pinstCMerchantWnd_x                                        0xE17418
#define pinstCMIZoneSelectWnd_x                                    0xF88880
#define pinstCMusicPlayerWnd_x                                     0xE171E0
#define pinstCNameChangeMercWnd_x                                  0xE170E0
#define pinstCNameChangePetWnd_x                                   0xE170B8
#define pinstCNameChangeWnd_x                                      0xE170F0
#define pinstCNoteWnd_x                                            0xE170BC
#define pinstCObjectPreviewWnd_x                                   0xE17158
#define pinstCOptionsWnd_x                                         0xE170C8
#define pinstCPetInfoWnd_x                                         0xE171D8
#define pinstCPetitionQWnd_x                                       0xE1707C
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE178F8
#define pinstCPlayerWnd_x                                          0xE171E8
#define pinstCPopupWndManager_x                                    0xF89110
#define pinstCProgressionSelectionWnd_x                            0xF891C0
#define pinstCPurchaseGroupWnd_x                                   0xE171A8
#define pinstCPurchaseWnd_x                                        0xE17188
#define pinstCPvPLeaderboardWnd_x                                  0xF89270
#define pinstCPvPStatsWnd_x                                        0xF89320
#define pinstCQuantityWnd_x                                        0xE171C4
#define pinstCRaceChangeWnd_x                                      0xE17114
#define pinstCRaidOptionsWnd_x                                     0xE1718C
#define pinstCRaidWnd_x                                            0xE17410
#define pinstCRealEstateItemsWnd_x                                 0xE170A4
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE178F4
#define pinstCRealEstateManageWnd_x                                0xE171B0
#define pinstCRealEstateNeighborhoodWnd_x                          0xE171D4
#define pinstCRealEstatePlotSearchWnd_x                            0xE171F4
#define pinstCRealEstatePurchaseWnd_x                              0xE17414
#define pinstCRespawnWnd_x                                         0xE1712C
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE17910
#define pinstCSendMoneyWnd_x                                       0xE170E4
#define pinstCServerListWnd_x                                      0xE1741C
#define pinstCSkillsSelectWnd_x                                    0xE17900
#define pinstCSkillsWnd_x                                          0xE178EC
#define pinstCSocialEditWnd_x                                      0xE17174
#define pinstCSocialWnd_x                                          0xE170DC
#define pinstCSpellBookWnd_x                                       0xE170C0
#define pinstCStoryWnd_x                                           0xE178E0
#define pinstCTargetOfTargetWnd_x                                  0xF8B148
#define pinstCTargetWnd_x                                          0xE1711C
#define pinstCTaskOverlayWnd_x                                     0xE171A0
#define pinstCTaskSelectWnd_x                                      0xF8B2A0
#define pinstCTaskManager_x                                        0xCE8BF8
#define pinstCTaskTemplateSelectWnd_x                              0xF8B350
#define pinstCTaskWnd_x                                            0xF8B400
#define pinstCTextEntryWnd_x                                       0xE17180
#define pinstCTimeLeftWnd_x                                        0xE17908
#define pinstCTipWndCONTEXT_x                                      0xF8B604
#define pinstCTipWndOFDAY_x                                        0xF8B600
#define pinstCTitleWnd_x                                           0xF8B6B0
#define pinstCTrackingWnd_x                                        0xE1710C
#define pinstCTradeskillWnd_x                                      0xF8B818
#define pinstCTradeWnd_x                                           0xE178FC
#define pinstCTrainWnd_x                                           0xE17404
#define pinstCTributeBenefitWnd_x                                  0xF8BA18
#define pinstCTributeMasterWnd_x                                   0xF8BAC8
#define pinstCTributeTrophyWnd_x                                   0xF8BB78
#define pinstCVideoModesWnd_x                                      0xE171E4
#define pinstCVoiceMacroWnd_x                                      0xF74E48
#define pinstCVoteResultsWnd_x                                     0xE17094
#define pinstCVoteWnd_x                                            0xE17084
#define pinstCWebManager_x                                         0xF754C4
#define pinstCZoneGuideWnd_x                                       0xE171A4
#define pinstCZonePathWnd_x                                        0xE171C8

#define pinstEQSuiteTextureLoader_x                                0xCB6020
#define pinstItemIconCache_x                                       0xF849D8
#define pinstLootFiltersManager_x                                  0xCE8368
#define pinstRewardSelectionWnd_x                                  0xF89A68

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C0B40
#define __CastRay2_x                                               0x5C0B90
#define __ConvertItemTags_x                                        0x5DCA00
#define __CleanItemTags_x                                          0x47D5D0
#define __DoesFileExist_x                                          0x91CEB0
#define __EQGetTime_x                                              0x919900
#define __ExecuteCmd_x                                             0x5B93E0
#define __FixHeading_x                                             0x9AE8E0
#define __FlushDxKeyboard_x                                        0x6CADC0
#define __GameLoop_x                                               0x6CE0F0
#define __get_bearing_x                                            0x5C06A0
#define __get_melee_range_x                                        0x5C0D80
#define __GetAnimationCache_x                                      0x733540
#define __GetGaugeValueFromEQ_x                                    0x8256D0
#define __GetLabelFromEQ_x                                         0x8271B0
#define __GetXTargetType_x                                         0x9B03A0
#define __HandleMouseWheel_x                                       0x6CEFD0
#define __HeadingDiff_x                                            0x9AE950
#define __HelpPath_x                                               0xF701CC
#define __LoadFrontEnd_x                                           0x6CB400
#define __NewUIINI_x                                               0x8253A0
#define __ProcessGameEvents_x                                      0x621490
#define __ProcessMouseEvent_x                                      0x620C20
#define __SaveColors_x                                             0x55B000
#define __STMLToText_x                                             0x951C30
#define __ToggleKeyRingItem_x                                      0x519A60
#define CMemoryMappedFile__SetFile_x                               0xA9DC10
#define CrashDetected_x                                            0x6CCEB0
#define DrawNetStatus_x                                            0x64D420
#define Expansion_HoT_x                                            0xED211C
#define Teleport_Table_Size_x                                      0xEC9814
#define Teleport_Table_x                                           0xEC9CD8
#define Util__FastTime_x                                           0x9194D0
#define __CopyLayout_x                                             0x63B8C0
#define __WndProc_x                                                0x6CD3B0
#define __ProcessKeyboardEvent_x                                   0x6CC950

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490980
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499960
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499730
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493F10
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x493360

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5631A0
#define AltAdvManager__IsAbilityReady_x                            0x561F40
#define AltAdvManager__GetAAById_x                                 0x5622D0
#define AltAdvManager__CanTrainAbility_x                           0x562340
#define AltAdvManager__CanSeeAbility_x                             0x5626A0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB740
#define CharacterZoneClient__HasSkill_x                            0x4D65C0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7CE0
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2E70
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BC300
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA6A0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA780
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA860
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4F50
#define CharacterZoneClient__BardCastBard_x                        0x4C7960
#define CharacterZoneClient__GetMaxEffects_x                       0x4BFD20
#define CharacterZoneClient__GetEffect_x                           0x4BC240
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5FA0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C6070
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C60C0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C6210
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C63F0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B4080
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8C40
#define CharacterZoneClient__FindItemByRecord_x                    0x4D86C0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6F4AD0
#define CBankWnd__WndNotification_x                                0x6F48B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x702410

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x62FD60
#define CButtonWnd__CButtonWnd_x                                   0x94DFE0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x722620
#define CChatManager__InitContextMenu_x                            0x71B750
#define CChatManager__FreeChatWindow_x                             0x721160
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9FB0
#define CChatManager__SetLockedActiveChatWindow_x                  0x7222A0
#define CChatManager__CreateChatWindow_x                           0x7217A0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4EA0C0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9625C0
#define CContextMenu__dCContextMenu_x                              0x962800
#define CContextMenu__AddMenuItem_x                                0x962810
#define CContextMenu__RemoveMenuItem_x                             0x962B20
#define CContextMenu__RemoveAllMenuItems_x                         0x962B40
#define CContextMenu__CheckMenuItem_x                              0x962BC0
#define CContextMenu__SetMenuItem_x                                0x962A40
#define CContextMenu__AddSeparator_x                               0x9629A0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x963160
#define CContextMenuManager__RemoveMenu_x                          0x9631D0
#define CContextMenuManager__PopupMenu_x                           0x963290
#define CContextMenuManager__Flush_x                               0x963100
#define CContextMenuManager__GetMenu_x                             0x49BC60
#define CContextMenuManager__CreateDefaultMenu_x                   0x72DD60

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8F44A0
#define CChatService__GetFriendName_x                              0x8F44B0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x722E90
#define CChatWindow__Clear_x                                       0x724150
#define CChatWindow__WndNotification_x                             0x7248E0
#define CChatWindow__AddHistory_x                                  0x723A10

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x95FA20
#define CComboWnd__Draw_x                                          0x95EF10
#define CComboWnd__GetCurChoice_x                                  0x95F860
#define CComboWnd__GetListRect_x                                   0x95F3C0
#define CComboWnd__GetTextRect_x                                   0x95FA90
#define CComboWnd__InsertChoice_x                                  0x95F550
#define CComboWnd__SetColors_x                                     0x95F520
#define CComboWnd__SetChoice_x                                     0x95F830
#define CComboWnd__GetItemCount_x                                  0x95F870
#define CComboWnd__GetCurChoiceText_x                              0x95F8B0
#define CComboWnd__GetChoiceText_x                                 0x95F880
#define CComboWnd__InsertChoiceAtIndex_x                           0x95F5F0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x72B780
#define CContainerWnd__vftable_x                                   0xB25894
#define CContainerWnd__SetContainer_x                              0x72CCD0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x5559B0
#define CDisplay__PreZoneMainUI_x                                  0x5559C0
#define CDisplay__CleanGameUI_x                                    0x55ADC0
#define CDisplay__GetClickedActor_x                                0x54DD80
#define CDisplay__GetUserDefinedColor_x                            0x546400
#define CDisplay__GetWorldFilePath_x                               0x54F7F0
#define CDisplay__is3dON_x                                         0x54A9E0
#define CDisplay__ReloadUI_x                                       0x554E30
#define CDisplay__WriteTextHD2_x                                   0x54A7D0
#define CDisplay__TrueDistance_x                                   0x5514B0
#define CDisplay__SetViewActor_x                                   0x54D6A0
#define CDisplay__GetFloorHeight_x                                 0x54AAA0
#define CDisplay__SetRenderWindow_x                                0x549420
#define CDisplay__ToggleScreenshotMode_x                           0x54D170

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x982460

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x965AC0
#define CEditWnd__EnsureCaretVisible_x                             0x967C90
#define CEditWnd__GetCaretPt_x                                     0x966C40
#define CEditWnd__GetCharIndexPt_x                                 0x9669F0
#define CEditWnd__GetDisplayString_x                               0x966890
#define CEditWnd__GetHorzOffset_x                                  0x965160
#define CEditWnd__GetLineForPrintableChar_x                        0x967B90
#define CEditWnd__GetSelStartPt_x                                  0x966CA0
#define CEditWnd__GetSTMLSafeText_x                                0x9666B0
#define CEditWnd__PointFromPrintableChar_x                         0x9677C0
#define CEditWnd__SelectableCharFromPoint_x                        0x967930
#define CEditWnd__SetEditable_x                                    0x966D70
#define CEditWnd__SetWindowTextA_x                                 0x966430
#define CEditWnd__ReplaceSelection_x                               0x967430
#define CEditWnd__ReplaceSelection1_x                              0x9673B0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60ED70
#define CEverQuest__ClickedPlayer_x                                0x600EF0
#define CEverQuest__CreateTargetIndicator_x                        0x61E620
#define CEverQuest__DeleteTargetIndicator_x                        0x61E6B0
#define CEverQuest__DoTellWindow_x                                 0x4EA1A0
#define CEverQuest__OutputTextToLog_x                              0x4EA470
#define CEverQuest__DropHeldItemOnGround_x                         0x5F6050
#define CEverQuest__dsp_chat_x                                     0x4EA800
#define CEverQuest__trimName_x                                     0x61A830
#define CEverQuest__Emote_x                                        0x60F5D0
#define CEverQuest__EnterZone_x                                    0x609660
#define CEverQuest__GetBodyTypeDesc_x                              0x613DD0
#define CEverQuest__GetClassDesc_x                                 0x614410
#define CEverQuest__GetClassThreeLetterCode_x                      0x614A10
#define CEverQuest__GetDeityDesc_x                                 0x61CE70
#define CEverQuest__GetLangDesc_x                                  0x614BD0
#define CEverQuest__GetRaceDesc_x                                  0x6143F0
#define CEverQuest__InterpretCmd_x                                 0x61D440
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FA1E0
#define CEverQuest__LMouseUp_x                                     0x5F8570
#define CEverQuest__RightClickedOnPlayer_x                         0x5FAAC0
#define CEverQuest__RMouseUp_x                                     0x5F94F0
#define CEverQuest__SetGameState_x                                 0x5F5DE0
#define CEverQuest__UPCNotificationFlush_x                         0x61A730
#define CEverQuest__IssuePetCommand_x                              0x615FD0
#define CEverQuest__ReportSuccessfulHit_x                          0x610920

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x73D670
#define CGaugeWnd__CalcLinesFillRect_x                             0x73D6D0
#define CGaugeWnd__Draw_x                                          0x73CCF0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4B03B0
#define CGuild__GetGuildName_x                                     0x4AEE60
#define CGuild__GetGuildIndex_x                                    0x4AF460

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x757840

//CHotButton
#define CHotButton__SetButtonSize_x                                0x630120

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x764940
#define CInvSlotMgr__MoveItem_x                                    0x763600
#define CInvSlotMgr__SelectSlot_x                                  0x764A10

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x761DF0
#define CInvSlot__SliderComplete_x                                 0x75FB30
#define CInvSlot__GetItemBase_x                                    0x75F4B0
#define CInvSlot__UpdateItem_x                                     0x75F620

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x766480
#define CInvSlotWnd__CInvSlotWnd_x                                 0x765610
#define CInvSlotWnd__HandleLButtonUp_x                             0x766000

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x820A70
#define CItemDisplayWnd__UpdateStrings_x                           0x774C90
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x76E8F0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x76EE20
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7752A0
#define CItemDisplayWnd__AboutToShow_x                             0x7748E0
#define CItemDisplayWnd__WndNotification_x                         0x7763E0
#define CItemDisplayWnd__RequestConvertItem_x                      0x775E50
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x773940
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x774700

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x859650

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x77A920

// CLabel 
#define CLabel__Draw_x                                             0x780370

// CListWnd
#define CListWnd__CListWnd_x                                       0x938190
#define CListWnd__dCListWnd_x                                      0x9384B0
#define CListWnd__AddColumn_x                                      0x93C900
#define CListWnd__AddColumn1_x                                     0x93C950
#define CListWnd__AddLine_x                                        0x93CCE0
#define CListWnd__AddString_x                                      0x93CAE0
#define CListWnd__CalculateFirstVisibleLine_x                      0x93C6C0
#define CListWnd__CalculateVSBRange_x                              0x93C4C0
#define CListWnd__ClearSel_x                                       0x93D4C0
#define CListWnd__ClearAllSel_x                                    0x93D520
#define CListWnd__CloseAndUpdateEditWindow_x                       0x93DF40
#define CListWnd__Compare_x                                        0x93BDF0
#define CListWnd__Draw_x                                           0x9385E0
#define CListWnd__DrawColumnSeparators_x                           0x93ADD0
#define CListWnd__DrawHeader_x                                     0x93B230
#define CListWnd__DrawItem_x                                       0x93B730
#define CListWnd__DrawLine_x                                       0x93AF30
#define CListWnd__DrawSeparator_x                                  0x93AE70
#define CListWnd__EnableLine_x                                     0x93A6B0
#define CListWnd__EnsureVisible_x                                  0x93DE60
#define CListWnd__ExtendSel_x                                      0x93D3F0
#define CListWnd__GetColumnTooltip_x                               0x93A1F0
#define CListWnd__GetColumnMinWidth_x                              0x93A260
#define CListWnd__GetColumnWidth_x                                 0x93A160
#define CListWnd__GetCurSel_x                                      0x939AF0
#define CListWnd__GetItemAtPoint_x                                 0x93A920
#define CListWnd__GetItemAtPoint1_x                                0x93A990
#define CListWnd__GetItemData_x                                    0x939B70
#define CListWnd__GetItemHeight_x                                  0x939F30
#define CListWnd__GetItemIcon_x                                    0x939D00
#define CListWnd__GetItemRect_x                                    0x93A7A0
#define CListWnd__GetItemText_x                                    0x939BB0
#define CListWnd__GetSelList_x                                     0x93D570
#define CListWnd__GetSeparatorRect_x                               0x93ABD0
#define CListWnd__InsertLine_x                                     0x93D0D0
#define CListWnd__RemoveLine_x                                     0x93D220
#define CListWnd__SetColors_x                                      0x93C490
#define CListWnd__SetColumnJustification_x                         0x93C1C0
#define CListWnd__SetColumnLabel_x                                 0x93CA80
#define CListWnd__SetColumnWidth_x                                 0x93C0E0
#define CListWnd__SetCurSel_x                                      0x93D330
#define CListWnd__SetItemColor_x                                   0x93DB10
#define CListWnd__SetItemData_x                                    0x93DAD0
#define CListWnd__SetItemText_x                                    0x93D6E0
#define CListWnd__ShiftColumnSeparator_x                           0x93C280
#define CListWnd__Sort_x                                           0x93BF70
#define CListWnd__ToggleSel_x                                      0x93D360
#define CListWnd__SetColumnsSizable_x                              0x93C330
#define CListWnd__SetItemWnd_x                                     0x93D990
#define CListWnd__GetItemWnd_x                                     0x939D50
#define CListWnd__SetItemIcon_x                                    0x93D760
#define CListWnd__CalculateCustomWindowPositions_x                 0x93C7C0
#define CListWnd__SetVScrollPos_x                                  0x93C0C0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7959F0
#define CMapViewWnd__GetWorldCoordinates_x                         0x794100
#define CMapViewWnd__HandleLButtonDown_x                           0x791140

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7B5D00
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7B65E0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7B6B10
#define CMerchantWnd__SelectRecoverySlot_x                         0x7B9AA0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7B4860
#define CMerchantWnd__SelectBuySellSlot_x                          0x7BF660
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7B5910

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8C26A0
#define CPacketScrambler__hton_x                                   0x8C2690

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9571D0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9575E0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9573D0
#define CSidlManager__CreateLabel_x                                0x817DB0
#define CSidlManager__CreateXWndFromTemplate_x                     0x95A540
#define CSidlManager__CreateXWndFromTemplate1_x                    0x95A710
#define CSidlManager__CreateXWnd_x                                 0x817CE0
#define CSidlManager__CreateHotButtonWnd_x                         0x818290

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x953CF0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x953BF0
#define CSidlScreenWnd__ConvertToRes_x                             0x97CFB0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9536E0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9533D0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9534A0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x953570
#define CSidlScreenWnd__DrawSidlPiece_x                            0x954170
#define CSidlScreenWnd__EnableIniStorage_x                         0x954640
#define CSidlScreenWnd__GetSidlPiece_x                             0x954360
#define CSidlScreenWnd__Init1_x                                    0x952FD0
#define CSidlScreenWnd__LoadIniInfo_x                              0x954690
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9551B0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x9523E0
#define CSidlScreenWnd__StoreIniInfo_x                             0x954D30
#define CSidlScreenWnd__StoreIniVis_x                              0x955090
#define CSidlScreenWnd__WndNotification_x                          0x954080
#define CSidlScreenWnd__GetChildItem_x                             0x9545C0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x943D60
#define CSidlScreenWnd__m_layoutCopy_x                             0x1606738

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x695540
#define CSkillMgr__GetSkillCap_x                                   0x695720
#define CSkillMgr__GetNameToken_x                                  0x694CC0
#define CSkillMgr__IsActivatedSkill_x                              0x694E00
#define CSkillMgr__IsCombatSkill_x                                 0x694D40

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x963F30
#define CSliderWnd__SetValue_x                                     0x963DA0
#define CSliderWnd__SetNumTicks_x                                  0x963E00

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x81DE40

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x96C8A0
#define CStmlWnd__ParseSTML_x                                      0x96DBE0
#define CStmlWnd__CalculateHSBRange_x                              0x96D9C0
#define CStmlWnd__CalculateVSBRange_x                              0x96D930
#define CStmlWnd__CanBreakAtCharacter_x                            0x971CF0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x972980
#define CStmlWnd__ForceParseNow_x                                  0x96CE90
#define CStmlWnd__GetNextTagPiece_x                                0x971C50
#define CStmlWnd__GetSTMLText_x                                    0x50AF30
#define CStmlWnd__GetVisibleText_x                                 0x96CEB0
#define CStmlWnd__InitializeWindowVariables_x                      0x9727D0
#define CStmlWnd__MakeStmlColorTag_x                               0x96BF10
#define CStmlWnd__MakeWndNotificationTag_x                         0x96BF80
#define CStmlWnd__SetSTMLText_x                                    0x96AFC0
#define CStmlWnd__StripFirstSTMLLines_x                            0x973A50
#define CStmlWnd__UpdateHistoryString_x                            0x972B90

// CTabWnd 
#define CTabWnd__Draw_x                                            0x96A100
#define CTabWnd__DrawCurrentPage_x                                 0x96A830
#define CTabWnd__DrawTab_x                                         0x96A550
#define CTabWnd__GetCurrentPage_x                                  0x969900
#define CTabWnd__GetPageInnerRect_x                                0x969B40
#define CTabWnd__GetTabInnerRect_x                                 0x969A80
#define CTabWnd__GetTabRect_x                                      0x969930
#define CTabWnd__InsertPage_x                                      0x969D50
#define CTabWnd__RemovePage_x                                      0x969EC0
#define CTabWnd__SetPage_x                                         0x969BC0
#define CTabWnd__SetPageRect_x                                     0x96A040
#define CTabWnd__UpdatePage_x                                      0x96A410
#define CTabWnd__GetPageFromTabIndex_x                             0x96A490
#define CTabWnd__GetCurrentTabIndex_x                              0x9698F0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x77ACF0
#define CPageWnd__SetTabText_x                                     0x969440
#define CPageWnd__FlashTab_x                                       0x9694A0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9770

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x940C60
#define CTextureFont__GetTextExtent_x                              0x940E20

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6C8260
#define CHtmlComponentWnd__ValidateUri_x                           0x759230
#define CHtmlWnd__SetClientCallbacks_x                             0x6351B0
#define CHtmlWnd__AddObserver_x                                    0x6351D0
#define CHtmlWnd__RemoveObserver_x                                 0x635230
#define Window__getProgress_x                                      0x877FA0
#define Window__getStatus_x                                        0x877FC0
#define Window__getURI_x                                           0x877FD0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x979DC0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x92DE50

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9EA0
#define CXStr__CXStr1_x                                            0x8686D0
#define CXStr__CXStr3_x                                            0x915880
#define CXStr__dCXStr_x                                            0x478870
#define CXStr__operator_equal_x                                    0x915AB0
#define CXStr__operator_equal1_x                                   0x915AF0
#define CXStr__operator_plus_equal1_x                              0x916580
#define CXStr__SetString_x                                         0x918470
#define CXStr__operator_char_p_x                                   0x915FC0
#define CXStr__GetChar_x                                           0x917DC0
#define CXStr__Delete_x                                            0x917670
#define CXStr__GetUnicode_x                                        0x917E30
#define CXStr__GetLength_x                                         0x4A9520
#define CXStr__Mid_x                                               0x47D980
#define CXStr__Insert_x                                            0x917E90
#define CXStr__FindNext_x                                          0x917AE0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9621E0
#define CXWnd__BringToTop_x                                        0x947560
#define CXWnd__Center_x                                            0x9470E0
#define CXWnd__ClrFocus_x                                          0x946F00
#define CXWnd__Destroy_x                                           0x946FA0
#define CXWnd__DoAllDrawing_x                                      0x943500
#define CXWnd__DrawChildren_x                                      0x9434D0
#define CXWnd__DrawColoredRect_x                                   0x943950
#define CXWnd__DrawTooltip_x                                       0x942030
#define CXWnd__DrawTooltipAtPoint_x                                0x9420F0
#define CXWnd__GetBorderFrame_x                                    0x9437B0
#define CXWnd__GetChildWndAt_x                                     0x947600
#define CXWnd__GetClientClipRect_x                                 0x9457A0
#define CXWnd__GetScreenClipRect_x                                 0x945870
#define CXWnd__GetScreenRect_x                                     0x945A40
#define CXWnd__GetRelativeRect_x                                   0x945B00
#define CXWnd__GetTooltipRect_x                                    0x9439A0
#define CXWnd__GetWindowTextA_x                                    0x49D360
#define CXWnd__IsActive_x                                          0x9440E0
#define CXWnd__IsDescendantOf_x                                    0x946450
#define CXWnd__IsReallyVisible_x                                   0x946480
#define CXWnd__IsType_x                                            0x947C50
#define CXWnd__Move_x                                              0x946500
#define CXWnd__Move1_x                                             0x9465C0
#define CXWnd__ProcessTransition_x                                 0x947090
#define CXWnd__Refade_x                                            0x946890
#define CXWnd__Resize_x                                            0x946B10
#define CXWnd__Right_x                                             0x947320
#define CXWnd__SetFocus_x                                          0x946EC0
#define CXWnd__SetFont_x                                           0x946F30
#define CXWnd__SetKeyTooltip_x                                     0x947A80
#define CXWnd__SetMouseOver_x                                      0x9448F0
#define CXWnd__StartFade_x                                         0x946330
#define CXWnd__GetChildItem_x                                      0x947770
#define CXWnd__SetParent_x                                         0x9461E0
#define CXWnd__Minimize_x                                          0x946B80

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x97E030

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x94A490
#define CXWndManager__DrawWindows_x                                0x94A4B0
#define CXWndManager__GetKeyboardFlags_x                           0x94CC50
#define CXWndManager__HandleKeyboardMsg_x                          0x94C800
#define CXWndManager__RemoveWnd_x                                  0x94CE80
#define CXWndManager__RemovePendingDeletionWnd_x                   0x94D400

// CDBStr
#define CDBStr__GetString_x                                        0x5453A0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4C0480
#define EQ_Character__Cur_HP_x                                     0x4D3600
#define EQ_Character__Cur_Mana_x                                   0x4DAD60
#define EQ_Character__GetCastingTimeModifier_x                     0x4C34D0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3CC0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3E10
#define EQ_Character__GetHPRegen_x                                 0x4E0BA0
#define EQ_Character__GetEnduranceRegen_x                          0x4E11A0
#define EQ_Character__GetManaRegen_x                               0x4E15E0
#define EQ_Character__Max_Endurance_x                              0x65BD00
#define EQ_Character__Max_HP_x                                     0x4D3430
#define EQ_Character__Max_Mana_x                                   0x65BB00
#define EQ_Character__doCombatAbility_x                            0x65E0F0
#define EQ_Character__UseSkill_x                                   0x4E33E0
#define EQ_Character__GetConLevel_x                                0x654300
#define EQ_Character__IsExpansionFlag_x                            0x5B7B80
#define EQ_Character__TotalEffect_x                                0x4C7250
#define EQ_Character__GetPCSpellAffect_x                           0x4C4220
#define EQ_Character__SpellDuration_x                              0x4C3D50
#define EQ_Character__MySpellDuration_x                            0x4B25F0
#define EQ_Character__GetAdjustedSkill_x                           0x4D6380
#define EQ_Character__GetBaseSkill_x                               0x4D7320
#define EQ_Character__CanUseItem_x                                 0x4DB070

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8E14D0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6720F0

//PcClient
#define PcClient__vftable_x                                        0xB16FF4
#define PcClient__PcClient_x                                       0x651A70

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BAEB0
#define CCharacterListWnd__EnterWorld_x                            0x4BA890
#define CCharacterListWnd__Quit_x                                  0x4BA5E0
#define CCharacterListWnd__UpdateList_x                            0x4BAA80

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6363A0
#define EQ_Item__CreateItemTagString_x                             0x8BBC70
#define EQ_Item__IsStackable_x                                     0x8C08E0
#define EQ_Item__GetImageNum_x                                     0x8BD800
#define EQ_Item__CreateItemClient_x                                0x6355D0
#define EQ_Item__GetItemValue_x                                    0x8BEB10
#define EQ_Item__ValueSellMerchant_x                               0x8C2280
#define EQ_Item__IsKeyRingItem_x                                   0x8C0200
#define EQ_Item__CanGoInBag_x                                      0x6364C0
#define EQ_Item__IsEmpty_x                                         0x8BFD40
#define EQ_Item__GetMaxItemCount_x                                 0x8BEF20
#define EQ_Item__GetHeldItem_x                                     0x8BD6D0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8BB5B0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x563E70
#define EQ_LoadingS__Array_x                                       0xC3EC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65C600
#define EQ_PC__GetAlternateAbilityId_x                             0x8CB250
#define EQ_PC__GetCombatAbility_x                                  0x8CB8C0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8CB930
#define EQ_PC__GetItemRecastTimer_x                                0x65E670
#define EQ_PC__HasLoreItem_x                                       0x654B10
#define EQ_PC__AlertInventoryChanged_x                             0x653C40
#define EQ_PC__GetPcZoneClient_x                                   0x6810E0
#define EQ_PC__RemoveMyAffect_x                                    0x6618A0
#define EQ_PC__GetKeyRingItems_x                                   0x8CC1C0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8CBF50
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8CC4C0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BE090
#define EQItemList__add_object_x                                   0x5EB7D0
#define EQItemList__add_item_x                                     0x5BE5F0
#define EQItemList__delete_item_x                                  0x5BE640
#define EQItemList__FreeItemList_x                                 0x5BE540

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x541E90

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6739F0
#define EQPlayer__dEQPlayer_x                                      0x666D90
#define EQPlayer__DoAttack_x                                       0x67B870
#define EQPlayer__EQPlayer_x                                       0x667450
#define EQPlayer__SetNameSpriteState_x                             0x66B720
#define EQPlayer__SetNameSpriteTint_x                              0x66C600
#define PlayerBase__HasProperty_j_x                                0x9ACCE0
#define EQPlayer__IsTargetable_x                                   0x9AD180
#define EQPlayer__CanSee_x                                         0x9ACFE0
#define EQPlayer__CanSee1_x                                        0x9AD0B0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9ACDA0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67EB70
#define PlayerZoneClient__GetLevel_x                               0x681120
#define PlayerZoneClient__IsValidTeleport_x                        0x5EC940
#define PlayerZoneClient__LegalPlayerRace_x                        0x55CC50

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x676730
#define EQPlayerManager__GetSpawnByName_x                          0x6767E0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x676870

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x639B00
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x639B80
#define KeypressHandler__AttachKeyToEqCommand_x                    0x639BC0
#define KeypressHandler__ClearCommandStateArray_x                  0x63AFD0
#define KeypressHandler__HandleKeyDown_x                           0x63AFF0
#define KeypressHandler__HandleKeyUp_x                             0x63B090
#define KeypressHandler__SaveKeymapping_x                          0x63B4E0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x791860
#define MapViewMap__SaveEx_x                                       0x794C20
#define MapViewMap__SetZoom_x                                      0x7992E0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8DF530

// StringTable 
#define StringTable__getString_x                                   0x8DA3E0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x661510
#define PcZoneClient__RemovePetEffect_x                            0x661B40
#define PcZoneClient__HasAlternateAbility_x                        0x65B930
#define PcZoneClient__GetCurrentMod_x                              0x4E6490
#define PcZoneClient__GetModCap_x                                  0x4E6390
#define PcZoneClient__CanEquipItem_x                               0x65BFE0
#define PcZoneClient__GetItemByID_x                                0x65EAE0
#define PcZoneClient__GetItemByItemClass_x                         0x65EC30
#define PcZoneClient__RemoveBuffEffect_x                           0x661B60
#define PcZoneClient__BandolierSwap_x                              0x65CBC0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65E610

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F14C0

//IconCache
#define IconCache__GetIcon_x                                       0x732DE0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x72A920
#define CContainerMgr__CloseContainer_x                            0x72ABF0
#define CContainerMgr__OpenExperimentContainer_x                   0x72B670

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7E9E50

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62E520

//CLootWnd
#define CLootWnd__LootAll_x                                        0x787D90
#define CLootWnd__RequestLootSlot_x                                0x787060

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58ACD0
#define EQ_Spell__SpellAffects_x                                   0x58B140
#define EQ_Spell__SpellAffectBase_x                                0x58AF00
#define EQ_Spell__IsStackable_x                                    0x4CB060
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CAE50
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B81B0
#define EQ_Spell__IsSPAStacking_x                                  0x58BF90
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58B4A0
#define EQ_Spell__IsNoRemove_x                                     0x4CB040
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58BFA0
#define __IsResEffectSpell_x                                       0x4CA190

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD910

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8E9B20

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x831200
#define CTargetWnd__WndNotification_x                              0x830A40
#define CTargetWnd__RefreshTargetBuffs_x                           0x830D10
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x82FBB0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x835830
#define CTaskWnd__ConfirmAbandonTask_x                             0x838460

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53F8C0
#define CTaskManager__HandleMessage_x                              0x53DD60
#define CTaskManager__GetTaskStatus_x                              0x53F970
#define CTaskManager__GetElementDescription_x                      0x53F9F0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x585EE0
#define EqSoundManager__PlayScriptMp3_x                            0x5861A0
#define EqSoundManager__SoundAssistPlay_x                          0x699410
#define EqSoundManager__WaveInstancePlay_x                         0x698980

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x530E00

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x968950
#define CTextureAnimation__Draw_x                                  0x968B50

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x9648A0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56B940
#define CAltAbilityData__GetMercMaxRank_x                          0x56B8D0
#define CAltAbilityData__GetMaxRank_x                              0x560DC0

//CTargetRing
#define CTargetRing__Cast_x                                        0x62C640

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CAE30
#define CharacterBase__CreateItemGlobalIndex_x                     0x517B60
#define CharacterBase__CreateItemIndex_x                           0x634760
#define CharacterBase__GetItemPossession_x                         0x503840
#define CharacterBase__GetItemByGlobalIndex_x                      0x8F2190
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8F21F0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x711900
#define CCastSpellWnd__IsBardSongPlaying_x                         0x712130
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x7121E0

//messages
#define msg_spell_worn_off_x                                       0x5AFAE0
#define msg_new_text_x                                             0x5A4450
#define __msgTokenTextParam_x                                      0x5B1D80
#define msgTokenText_x                                             0x5B1FD0

//SpellManager
#define SpellManager__vftable_x                                    0xAFF31C
#define SpellManager__SpellManager_x                               0x69C740
#define Spellmanager__LoadTextSpells_x                             0x69D030
#define SpellManager__GetSpellByGroupAndRank_x                     0x69C910

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9B0C90

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5181B0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B5F40
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64D280
#define ItemGlobalIndex__IsValidIndex_x                            0x518240

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8EA4C0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8EA740

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7806B0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x72EFF0
#define CCursorAttachment__AttachToCursor1_x                       0x72F030
#define CCursorAttachment__Deactivate_x                            0x730020

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x95B530
#define CSidlManagerBase__CreatePageWnd_x                          0x95AD40
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x956FF0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x956F80

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x978980
#define CEQSuiteTextureLoader__GetTexture_x                        0x978640

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x515140
#define CFindItemWnd__WndNotification_x                            0x515C20
#define CFindItemWnd__Update_x                                     0x516760
#define CFindItemWnd__PickupSelectedItem_x                         0x514960

//IString
#define IString__Append_x                                          0x5050B0

//Camera
#define CDisplay__cameraType_x                                     0xE171EC
#define EverQuest__Cameras_x                                       0xED246C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51DC00
#define LootFiltersManager__GetItemFilterData_x                    0x51D500
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51D530
#define LootFiltersManager__SetItemLootFilter_x                    0x51D750

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7D7C60

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9B68C0
#define CResolutionHandler__GetWindowedStyle_x                     0x693FB0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7275E0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8FFB00
#define CDistillerInfo__Instance_x                                 0x8FFAA0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7465F0
#define CGroupWnd__UpdateDisplay_x                                 0x745940

//ItemBase
#define ItemBase__IsLore_x                                         0x8C02B0
#define ItemBase__IsLoreEquipped_x                                 0x8C0320

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EB730
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EB870
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EB8D0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6897F0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68D1A0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50B560

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F7650
#define FactionManagerClient__HandleFactionMessage_x               0x4F7CC0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F82C0
#define FactionManagerClient__GetMaxFaction_x                      0x4F82DF
#define FactionManagerClient__GetMinFaction_x                      0x4F8290

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x503810

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x93FBE0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C670

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x503AC0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56ADF0

//CTargetManager
#define CTargetManager__Get_x                                      0x69FF50

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6897F0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A9530

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BE4E0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF6FB00

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6DB260
#define CAAWnd__UpdateSelected_x                                   0x6D7AD0
#define CAAWnd__Update_x                                           0x6DA580

//CXRect
#define CXRect__operator_and_x                                     0x73D730

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x4835E0

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
