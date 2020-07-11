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
#define __ExpectedVersionDate                                     "Jul 10 2020"
#define __ExpectedVersionTime                                     "14:56:26"
#define __ActualVersionDate_x                                      0xB1C654
#define __ActualVersionTime_x                                      0xB1C648
#define __ActualVersionBuild_x                                     0xB0832C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x63FC40
#define __MemChecker1_x                                            0x91A310
#define __MemChecker2_x                                            0x6CEF20
#define __MemChecker3_x                                            0x6CEE70
#define __MemChecker4_x                                            0x870DA0
#define __EncryptPad0_x                                            0xC57520
#define __EncryptPad1_x                                            0xCB5700
#define __EncryptPad2_x                                            0xC67DB8
#define __EncryptPad3_x                                            0xC679B8
#define __EncryptPad4_x                                            0xCA5C90
#define __EncryptPad5_x                                            0xF77BD0
#define __AC1_x                                                    0x8273D6
#define __AC2_x                                                    0x5F975F
#define __AC3_x                                                    0x600DAF
#define __AC4_x                                                    0x604D70
#define __AC5_x                                                    0x60B02F
#define __AC6_x                                                    0x60F536
#define __AC7_x                                                    0x5F91D0
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
#define __do_loot_x                                                0x5C5380
#define __DrawHandler_x                                            0x16076E8
#define __GroupCount_x                                             0xECBE92
#define __Guilds_x                                                 0xECFCF8
#define __gWorld_x                                                 0xECBD1C
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
#define __gfMaxCameraDistance_x                                    0xB3E420
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
#define pinstCCastSpellWnd_x                                       0xE17460
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
#define pinstCInvSlotMgr_x                                         0xE17458
#define pinstCItemDisplayManager_x                                 0xF87B18
#define pinstCItemExpTransferWnd_x                                 0xF87C48
#define pinstCItemOverflowWnd_x                                    0xE1744C
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
#define pinstCMailCompositionWnd_x                                 0xE17430
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
#define __CastRay_x                                                0x5C0750
#define __CastRay2_x                                               0x5C07A0
#define __ConvertItemTags_x                                        0x5DC600
#define __CleanItemTags_x                                          0x47D5C0
#define __DoesFileExist_x                                          0x91D340
#define __EQGetTime_x                                              0x919DE0
#define __ExecuteCmd_x                                             0x5B8FF0
#define __FixHeading_x                                             0x9AE590
#define __FlushDxKeyboard_x                                        0x6CADC0
#define __GameLoop_x                                               0x6CE0F0
#define __get_bearing_x                                            0x5C02B0
#define __get_melee_range_x                                        0x5C0990
#define __GetAnimationCache_x                                      0x733570
#define __GetGaugeValueFromEQ_x                                    0x825880
#define __GetLabelFromEQ_x                                         0x827360
#define __GetXTargetType_x                                         0x9AFF70
#define __HandleMouseWheel_x                                       0x6CEFD0
#define __HeadingDiff_x                                            0x9AE600
#define __HelpPath_x                                               0xF701CC
#define __LoadFrontEnd_x                                           0x6CB400
#define __NewUIINI_x                                               0x825550
#define __ProcessGameEvents_x                                      0x621120
#define __ProcessMouseEvent_x                                      0x6208B0
#define __SaveColors_x                                             0x55AD70
#define __STMLToText_x                                             0x9519D0
#define __ToggleKeyRingItem_x                                      0x519A20
#define CMemoryMappedFile__SetFile_x                               0xA9D610
#define CrashDetected_x                                            0x6CCEB0
#define DrawNetStatus_x                                            0x64D070
#define Expansion_HoT_x                                            0xED211C
#define Teleport_Table_Size_x                                      0xEC9814
#define Teleport_Table_x                                           0xEC9CD8
#define Util__FastTime_x                                           0x9199B0
#define __CopyLayout_x                                             0x63B400
#define __WndProc_x                                                0x6CD3B0
#define __ProcessKeyboardEvent_x                                   0x6CC950

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4908C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4998C0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499690
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493E60
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x4932B0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x563060
#define AltAdvManager__IsAbilityReady_x                            0x561E00
#define AltAdvManager__GetAAById_x                                 0x562190
#define AltAdvManager__CanTrainAbility_x                           0x562200
#define AltAdvManager__CanSeeAbility_x                             0x562560

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB730
#define CharacterZoneClient__HasSkill_x                            0x4D65B0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7CD0
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2F80
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BC410
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA620
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA700
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA7E0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C5060
#define CharacterZoneClient__BardCastBard_x                        0x4C7A70
#define CharacterZoneClient__GetMaxEffects_x                       0x4BFE30
#define CharacterZoneClient__GetEffect_x                           0x4BC350
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C60B0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C6180
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C61D0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C6320
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C6500
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B4130
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8C30
#define CharacterZoneClient__FindItemByRecord_x                    0x4D86B0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6F4B20
#define CBankWnd__WndNotification_x                                0x6F4900

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x7025C0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x62F8D0
#define CButtonWnd__CButtonWnd_x                                   0x94DD90

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x7225A0
#define CChatManager__InitContextMenu_x                            0x71B6D0
#define CChatManager__FreeChatWindow_x                             0x7210E0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9FE0
#define CChatManager__SetLockedActiveChatWindow_x                  0x722220
#define CChatManager__CreateChatWindow_x                           0x721720

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4EA0F0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9623B0
#define CContextMenu__dCContextMenu_x                              0x9625F0
#define CContextMenu__AddMenuItem_x                                0x962600
#define CContextMenu__RemoveMenuItem_x                             0x962910
#define CContextMenu__RemoveAllMenuItems_x                         0x962930
#define CContextMenu__CheckMenuItem_x                              0x9629B0
#define CContextMenu__SetMenuItem_x                                0x962830
#define CContextMenu__AddSeparator_x                               0x962790

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x962F50
#define CContextMenuManager__RemoveMenu_x                          0x962FC0
#define CContextMenuManager__PopupMenu_x                           0x963080
#define CContextMenuManager__Flush_x                               0x962EF0
#define CContextMenuManager__GetMenu_x                             0x49BB60
#define CContextMenuManager__CreateDefaultMenu_x                   0x72DD60

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8BD4E0
#define CChatService__GetFriendName_x                              0x8F4BA0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x722E60
#define CChatWindow__Clear_x                                       0x724120
#define CChatWindow__WndNotification_x                             0x7248B0
#define CChatWindow__AddHistory_x                                  0x7239E0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x95F810
#define CComboWnd__Draw_x                                          0x95ECF0
#define CComboWnd__GetCurChoice_x                                  0x95F650
#define CComboWnd__GetListRect_x                                   0x95F1B0
#define CComboWnd__GetTextRect_x                                   0x95F880
#define CComboWnd__InsertChoice_x                                  0x95F340
#define CComboWnd__SetColors_x                                     0x95F310
#define CComboWnd__SetChoice_x                                     0x95F620
#define CComboWnd__GetItemCount_x                                  0x95F660
#define CComboWnd__GetCurChoiceText_x                              0x95F6A0
#define CComboWnd__GetChoiceText_x                                 0x95F670
#define CComboWnd__InsertChoiceAtIndex_x                           0x95F3E0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x72B770
#define CContainerWnd__vftable_x                                   0xB2584C
#define CContainerWnd__SetContainer_x                              0x72CCC0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x555720
#define CDisplay__PreZoneMainUI_x                                  0x555730
#define CDisplay__CleanGameUI_x                                    0x55AB30
#define CDisplay__GetClickedActor_x                                0x54DAF0
#define CDisplay__GetUserDefinedColor_x                            0x546170
#define CDisplay__GetWorldFilePath_x                               0x54F560
#define CDisplay__is3dON_x                                         0x54A750
#define CDisplay__ReloadUI_x                                       0x554BA0
#define CDisplay__WriteTextHD2_x                                   0x54A540
#define CDisplay__TrueDistance_x                                   0x551220
#define CDisplay__SetViewActor_x                                   0x54D410
#define CDisplay__GetFloorHeight_x                                 0x54A810
#define CDisplay__SetRenderWindow_x                                0x549190
#define CDisplay__ToggleScreenshotMode_x                           0x54CEE0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x982050

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9658B0
#define CEditWnd__EnsureCaretVisible_x                             0x967A80
#define CEditWnd__GetCaretPt_x                                     0x966A30
#define CEditWnd__GetCharIndexPt_x                                 0x9667E0
#define CEditWnd__GetDisplayString_x                               0x966680
#define CEditWnd__GetHorzOffset_x                                  0x964F50
#define CEditWnd__GetLineForPrintableChar_x                        0x967980
#define CEditWnd__GetSelStartPt_x                                  0x966A90
#define CEditWnd__GetSTMLSafeText_x                                0x9664A0
#define CEditWnd__PointFromPrintableChar_x                         0x9675B0
#define CEditWnd__SelectableCharFromPoint_x                        0x967720
#define CEditWnd__SetEditable_x                                    0x966B60
#define CEditWnd__SetWindowTextA_x                                 0x966220
#define CEditWnd__ReplaceSelection_x                               0x967220
#define CEditWnd__ReplaceSelection1_x                              0x9671A0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60EA10
#define CEverQuest__ClickedPlayer_x                                0x600B90
#define CEverQuest__CreateTargetIndicator_x                        0x61E2C0
#define CEverQuest__DeleteTargetIndicator_x                        0x61E350
#define CEverQuest__DoTellWindow_x                                 0x4EA1D0
#define CEverQuest__OutputTextToLog_x                              0x4EA4A0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F5CF0
#define CEverQuest__dsp_chat_x                                     0x4EA830
#define CEverQuest__trimName_x                                     0x61A4D0
#define CEverQuest__Emote_x                                        0x60F270
#define CEverQuest__EnterZone_x                                    0x609300
#define CEverQuest__GetBodyTypeDesc_x                              0x613A70
#define CEverQuest__GetClassDesc_x                                 0x6140B0
#define CEverQuest__GetClassThreeLetterCode_x                      0x6146B0
#define CEverQuest__GetDeityDesc_x                                 0x61CB10
#define CEverQuest__GetLangDesc_x                                  0x614870
#define CEverQuest__GetRaceDesc_x                                  0x614090
#define CEverQuest__InterpretCmd_x                                 0x61D0E0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5F9E80
#define CEverQuest__LMouseUp_x                                     0x5F8210
#define CEverQuest__RightClickedOnPlayer_x                         0x5FA760
#define CEverQuest__RMouseUp_x                                     0x5F9190
#define CEverQuest__SetGameState_x                                 0x5F5A80
#define CEverQuest__UPCNotificationFlush_x                         0x61A3D0
#define CEverQuest__IssuePetCommand_x                              0x615C70
#define CEverQuest__ReportSuccessfulHit_x                          0x6105C0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x73D7F0
#define CGaugeWnd__CalcLinesFillRect_x                             0x73D850
#define CGaugeWnd__Draw_x                                          0x73CE70

// CGuild
#define CGuild__FindMemberByName_x                                 0x4B0390
#define CGuild__GetGuildName_x                                     0x4AEE40
#define CGuild__GetGuildIndex_x                                    0x4AF440

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x757A70

//CHotButton
#define CHotButton__SetButtonSize_x                                0x62FC90

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x764AF0
#define CInvSlotMgr__MoveItem_x                                    0x763810
#define CInvSlotMgr__SelectSlot_x                                  0x764BC0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x762000
#define CInvSlot__SliderComplete_x                                 0x75FD50
#define CInvSlot__GetItemBase_x                                    0x75F6E0
#define CInvSlot__UpdateItem_x                                     0x75F850

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x766650
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7657E0
#define CInvSlotWnd__HandleLButtonUp_x                             0x7661D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x820C20
#define CItemDisplayWnd__UpdateStrings_x                           0x774DA0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x76EA90
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x76EFA0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7753A0
#define CItemDisplayWnd__AboutToShow_x                             0x774A00
#define CItemDisplayWnd__WndNotification_x                         0x7764C0
#define CItemDisplayWnd__RequestConvertItem_x                      0x775F40
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x773A60
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x774820

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8597C0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x77A9C0

// CLabel 
#define CLabel__Draw_x                                             0x7803A0

// CListWnd
#define CListWnd__CListWnd_x                                       0x937FE0
#define CListWnd__dCListWnd_x                                      0x938300
#define CListWnd__AddColumn_x                                      0x93C780
#define CListWnd__AddColumn1_x                                     0x93C7D0
#define CListWnd__AddLine_x                                        0x93CB60
#define CListWnd__AddString_x                                      0x93C960
#define CListWnd__CalculateFirstVisibleLine_x                      0x93C540
#define CListWnd__CalculateVSBRange_x                              0x93C320
#define CListWnd__ClearSel_x                                       0x93D340
#define CListWnd__ClearAllSel_x                                    0x93D3A0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x93DDC0
#define CListWnd__Compare_x                                        0x93BC50
#define CListWnd__Draw_x                                           0x938430
#define CListWnd__DrawColumnSeparators_x                           0x93AC20
#define CListWnd__DrawHeader_x                                     0x93B090
#define CListWnd__DrawItem_x                                       0x93B590
#define CListWnd__DrawLine_x                                       0x93AD90
#define CListWnd__DrawSeparator_x                                  0x93ACC0
#define CListWnd__EnableLine_x                                     0x93A500
#define CListWnd__EnsureVisible_x                                  0x93DCE0
#define CListWnd__ExtendSel_x                                      0x93D270
#define CListWnd__GetColumnTooltip_x                               0x93A040
#define CListWnd__GetColumnMinWidth_x                              0x93A0B0
#define CListWnd__GetColumnWidth_x                                 0x939FB0
#define CListWnd__GetCurSel_x                                      0x939940
#define CListWnd__GetItemAtPoint_x                                 0x93A780
#define CListWnd__GetItemAtPoint1_x                                0x93A7F0
#define CListWnd__GetItemData_x                                    0x9399C0
#define CListWnd__GetItemHeight_x                                  0x939D80
#define CListWnd__GetItemIcon_x                                    0x939B50
#define CListWnd__GetItemRect_x                                    0x93A5F0
#define CListWnd__GetItemText_x                                    0x939A00
#define CListWnd__GetSelList_x                                     0x93D3F0
#define CListWnd__GetSeparatorRect_x                               0x93AA30
#define CListWnd__InsertLine_x                                     0x93CF50
#define CListWnd__RemoveLine_x                                     0x93D0A0
#define CListWnd__SetColors_x                                      0x93C2F0
#define CListWnd__SetColumnJustification_x                         0x93C020
#define CListWnd__SetColumnLabel_x                                 0x93C900
#define CListWnd__SetColumnWidth_x                                 0x93BF40
#define CListWnd__SetCurSel_x                                      0x93D1B0
#define CListWnd__SetItemColor_x                                   0x93D990
#define CListWnd__SetItemData_x                                    0x93D950
#define CListWnd__SetItemText_x                                    0x93D560
#define CListWnd__ShiftColumnSeparator_x                           0x93C0E0
#define CListWnd__Sort_x                                           0x93BDD0
#define CListWnd__ToggleSel_x                                      0x93D1E0
#define CListWnd__SetColumnsSizable_x                              0x93C190
#define CListWnd__SetItemWnd_x                                     0x93D810
#define CListWnd__GetItemWnd_x                                     0x939BA0
#define CListWnd__SetItemIcon_x                                    0x93D5E0
#define CListWnd__CalculateCustomWindowPositions_x                 0x93C640
#define CListWnd__SetVScrollPos_x                                  0x93BF20

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x795950
#define CMapViewWnd__GetWorldCoordinates_x                         0x794060
#define CMapViewWnd__HandleLButtonDown_x                           0x7910A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7B5CA0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7B6580
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7B6AB0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7B9A30
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7B4810
#define CMerchantWnd__SelectBuySellSlot_x                          0x7BF5E0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7B58B0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8C2B70
#define CPacketScrambler__hton_x                                   0x8C2B60

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x956FB0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9573C0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9571B0
#define CSidlManager__CreateLabel_x                                0x817E70
#define CSidlManager__CreateXWndFromTemplate_x                     0x95A320
#define CSidlManager__CreateXWndFromTemplate1_x                    0x95A4F0
#define CSidlManager__CreateXWnd_x                                 0x817DA0
#define CSidlManager__CreateHotButtonWnd_x                         0x818370

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x953A90
#define CSidlScreenWnd__CalculateVSBRange_x                        0x953990
#define CSidlScreenWnd__ConvertToRes_x                             0x97CBA0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x953480
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x953170
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x953240
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x953310
#define CSidlScreenWnd__DrawSidlPiece_x                            0x953F30
#define CSidlScreenWnd__EnableIniStorage_x                         0x954400
#define CSidlScreenWnd__GetSidlPiece_x                             0x954120
#define CSidlScreenWnd__Init1_x                                    0x952D70
#define CSidlScreenWnd__LoadIniInfo_x                              0x954450
#define CSidlScreenWnd__LoadIniListWnd_x                           0x954F90
#define CSidlScreenWnd__LoadSidlScreen_x                           0x952190
#define CSidlScreenWnd__StoreIniInfo_x                             0x954B10
#define CSidlScreenWnd__StoreIniVis_x                              0x954E70
#define CSidlScreenWnd__WndNotification_x                          0x953E40
#define CSidlScreenWnd__GetChildItem_x                             0x954380
#define CSidlScreenWnd__HandleLButtonUp_x                          0x943B60
#define CSidlScreenWnd__m_layoutCopy_x                             0x1606738

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x695050
#define CSkillMgr__GetSkillCap_x                                   0x695230
#define CSkillMgr__GetNameToken_x                                  0x6947D0
#define CSkillMgr__IsActivatedSkill_x                              0x694910
#define CSkillMgr__IsCombatSkill_x                                 0x694850

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x963D30
#define CSliderWnd__SetValue_x                                     0x963BA0
#define CSliderWnd__SetNumTicks_x                                  0x963C00

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x81DFB0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x96C690
#define CStmlWnd__ParseSTML_x                                      0x96D9A0
#define CStmlWnd__CalculateHSBRange_x                              0x96D770
#define CStmlWnd__CalculateVSBRange_x                              0x96D6E0
#define CStmlWnd__CanBreakAtCharacter_x                            0x971AB0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x972740
#define CStmlWnd__ForceParseNow_x                                  0x96CC30
#define CStmlWnd__GetNextTagPiece_x                                0x971A10
#define CStmlWnd__GetSTMLText_x                                    0x50ACA0
#define CStmlWnd__GetVisibleText_x                                 0x96CC50
#define CStmlWnd__InitializeWindowVariables_x                      0x972590
#define CStmlWnd__MakeStmlColorTag_x                               0x96BD00
#define CStmlWnd__MakeWndNotificationTag_x                         0x96BD70
#define CStmlWnd__SetSTMLText_x                                    0x96ADB0
#define CStmlWnd__StripFirstSTMLLines_x                            0x973840
#define CStmlWnd__UpdateHistoryString_x                            0x972950

// CTabWnd 
#define CTabWnd__Draw_x                                            0x969F00
#define CTabWnd__DrawCurrentPage_x                                 0x96A630
#define CTabWnd__DrawTab_x                                         0x96A350
#define CTabWnd__GetCurrentPage_x                                  0x969700
#define CTabWnd__GetPageInnerRect_x                                0x969940
#define CTabWnd__GetTabInnerRect_x                                 0x969880
#define CTabWnd__GetTabRect_x                                      0x969730
#define CTabWnd__InsertPage_x                                      0x969B50
#define CTabWnd__RemovePage_x                                      0x969CC0
#define CTabWnd__SetPage_x                                         0x9699C0
#define CTabWnd__SetPageRect_x                                     0x969E40
#define CTabWnd__UpdatePage_x                                      0x96A210
#define CTabWnd__GetPageFromTabIndex_x                             0x96A290
#define CTabWnd__GetCurrentTabIndex_x                              0x9696F0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x77AD90
#define CPageWnd__SetTabText_x                                     0x969240
#define CPageWnd__FlashTab_x                                       0x9692A0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9680

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x940A10
#define CTextureFont__GetTextExtent_x                              0x940BD0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6C7FA0
#define CHtmlComponentWnd__ValidateUri_x                           0x759460
#define CHtmlWnd__SetClientCallbacks_x                             0x634D10
#define CHtmlWnd__AddObserver_x                                    0x634D30
#define CHtmlWnd__RemoveObserver_x                                 0x634D90
#define Window__getProgress_x                                      0x8783D0
#define Window__getStatus_x                                        0x8783F0
#define Window__getURI_x                                           0x878400

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9799B0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x92DC00

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9E20
#define CXStr__CXStr1_x                                            0x481AB0
#define CXStr__CXStr3_x                                            0x915DA0
#define CXStr__dCXStr_x                                            0x478780
#define CXStr__operator_equal_x                                    0x915FD0
#define CXStr__operator_equal1_x                                   0x916010
#define CXStr__operator_plus_equal1_x                              0x916AA0
#define CXStr__SetString_x                                         0x918990
#define CXStr__operator_char_p_x                                   0x9164E0
#define CXStr__GetChar_x                                           0x9182E0
#define CXStr__Delete_x                                            0x917B90
#define CXStr__GetUnicode_x                                        0x918350
#define CXStr__GetLength_x                                         0x47D970
#define CXStr__Mid_x                                               0x47D980
#define CXStr__Insert_x                                            0x9183B0
#define CXStr__FindNext_x                                          0x918000

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x961FD0
#define CXWnd__BringToTop_x                                        0x9472F0
#define CXWnd__Center_x                                            0x946E70
#define CXWnd__ClrFocus_x                                          0x946C80
#define CXWnd__Destroy_x                                           0x946D30
#define CXWnd__DoAllDrawing_x                                      0x943310
#define CXWnd__DrawChildren_x                                      0x9432E0
#define CXWnd__DrawColoredRect_x                                   0x943770
#define CXWnd__DrawTooltip_x                                       0x941E10
#define CXWnd__DrawTooltipAtPoint_x                                0x941ED0
#define CXWnd__GetBorderFrame_x                                    0x9435D0
#define CXWnd__GetChildWndAt_x                                     0x947390
#define CXWnd__GetClientClipRect_x                                 0x945560
#define CXWnd__GetScreenClipRect_x                                 0x945610
#define CXWnd__GetScreenRect_x                                     0x9457C0
#define CXWnd__GetRelativeRect_x                                   0x945890
#define CXWnd__GetTooltipRect_x                                    0x9437C0
#define CXWnd__GetWindowTextA_x                                    0x49D2F0
#define CXWnd__IsActive_x                                          0x943EE0
#define CXWnd__IsDescendantOf_x                                    0x9461E0
#define CXWnd__IsReallyVisible_x                                   0x946210
#define CXWnd__IsType_x                                            0x947A00
#define CXWnd__Move_x                                              0x946270
#define CXWnd__Move1_x                                             0x946330
#define CXWnd__ProcessTransition_x                                 0x946E20
#define CXWnd__Refade_x                                            0x946610
#define CXWnd__Resize_x                                            0x9468A0
#define CXWnd__Right_x                                             0x9470B0
#define CXWnd__SetFocus_x                                          0x946C40
#define CXWnd__SetFont_x                                           0x946CB0
#define CXWnd__SetKeyTooltip_x                                     0x947820
#define CXWnd__SetMouseOver_x                                      0x944700
#define CXWnd__StartFade_x                                         0x9460C0
#define CXWnd__GetChildItem_x                                      0x947500
#define CXWnd__SetParent_x                                         0x945F70
#define CXWnd__Minimize_x                                          0x946910

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x97DC20

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x94A260
#define CXWndManager__DrawWindows_x                                0x94A280
#define CXWndManager__GetKeyboardFlags_x                           0x94CA00
#define CXWndManager__HandleKeyboardMsg_x                          0x94C5B0
#define CXWndManager__RemoveWnd_x                                  0x94CC30
#define CXWndManager__RemovePendingDeletionWnd_x                   0x94D1B0

// CDBStr
#define CDBStr__GetString_x                                        0x545100

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4C0590
#define EQ_Character__Cur_HP_x                                     0x4D35F0
#define EQ_Character__Cur_Mana_x                                   0x4DACE0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C35E0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3D70
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3EC0
#define EQ_Character__GetHPRegen_x                                 0x4E0AF0
#define EQ_Character__GetEnduranceRegen_x                          0x4E10F0
#define EQ_Character__GetManaRegen_x                               0x4E1530
#define EQ_Character__Max_Endurance_x                              0x65B710
#define EQ_Character__Max_HP_x                                     0x4D3420
#define EQ_Character__Max_Mana_x                                   0x65B510
#define EQ_Character__doCombatAbility_x                            0x65DAF0
#define EQ_Character__UseSkill_x                                   0x4E3320
#define EQ_Character__GetConLevel_x                                0x654010
#define EQ_Character__IsExpansionFlag_x                            0x5B77A0
#define EQ_Character__TotalEffect_x                                0x4C7360
#define EQ_Character__GetPCSpellAffect_x                           0x4C4330
#define EQ_Character__SpellDuration_x                              0x4C3E60
#define EQ_Character__MySpellDuration_x                            0x4B26A0
#define EQ_Character__GetAdjustedSkill_x                           0x4D6370
#define EQ_Character__GetBaseSkill_x                               0x4D7310
#define EQ_Character__CanUseItem_x                                 0x4DAFF0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8E1C30

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x671A80

//PcClient
#define PcClient__vftable_x                                        0xB17000
#define PcClient__PcClient_x                                       0x651780

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BAFC0
#define CCharacterListWnd__EnterWorld_x                            0x4BA9A0
#define CCharacterListWnd__Quit_x                                  0x4BA6F0
#define CCharacterListWnd__UpdateList_x                            0x4BAB90

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x635F00
#define EQ_Item__CreateItemTagString_x                             0x8BC100
#define EQ_Item__IsStackable_x                                     0x8C0DA0
#define EQ_Item__GetImageNum_x                                     0x8BDC70
#define EQ_Item__CreateItemClient_x                                0x635130
#define EQ_Item__GetItemValue_x                                    0x8BEF90
#define EQ_Item__ValueSellMerchant_x                               0x8C2750
#define EQ_Item__IsKeyRingItem_x                                   0x8C06C0
#define EQ_Item__CanGoInBag_x                                      0x636020
#define EQ_Item__IsEmpty_x                                         0x8C0210
#define EQ_Item__GetMaxItemCount_x                                 0x8BF3A0
#define EQ_Item__GetHeldItem_x                                     0x8BDB40
#define EQ_Item__GetAugmentFitBySlot_x                             0x8BBA50

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x563D70
#define EQ_LoadingS__Array_x                                       0xC3EC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65C010
#define EQ_PC__GetAlternateAbilityId_x                             0x8CB7E0
#define EQ_PC__GetCombatAbility_x                                  0x8CBE50
#define EQ_PC__GetCombatAbilityTimer_x                             0x8CBEC0
#define EQ_PC__GetItemRecastTimer_x                                0x65E070
#define EQ_PC__HasLoreItem_x                                       0x6547D0
#define EQ_PC__AlertInventoryChanged_x                             0x653950
#define EQ_PC__GetPcZoneClient_x                                   0x680B40
#define EQ_PC__RemoveMyAffect_x                                    0x6612A0
#define EQ_PC__GetKeyRingItems_x                                   0x8CC750
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8CC4E0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8CCA50

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BDCC0
#define EQItemList__add_object_x                                   0x5EB3A0
#define EQItemList__add_item_x                                     0x5BE220
#define EQItemList__delete_item_x                                  0x5BE270
#define EQItemList__FreeItemList_x                                 0x5BE170

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x541CA0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x673380
#define EQPlayer__dEQPlayer_x                                      0x666730
#define EQPlayer__DoAttack_x                                       0x67B2E0
#define EQPlayer__EQPlayer_x                                       0x666DF0
#define EQPlayer__SetNameSpriteState_x                             0x66B0B0
#define EQPlayer__SetNameSpriteTint_x                              0x66BF90
#define PlayerBase__HasProperty_j_x                                0x9AC950
#define EQPlayer__IsTargetable_x                                   0x9ACDF0
#define EQPlayer__CanSee_x                                         0x9ACC50
#define EQPlayer__CanSee1_x                                        0x9ACD20
#define PlayerBase__GetVisibilityLineSegment_x                     0x9ACA10

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67E5E0
#define PlayerZoneClient__GetLevel_x                               0x680B80
#define PlayerZoneClient__IsValidTeleport_x                        0x5EC510
#define PlayerZoneClient__LegalPlayerRace_x                        0x55C9F0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6761F0
#define EQPlayerManager__GetSpawnByName_x                          0x6762A0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x676330

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x639640
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6396C0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x639700
#define KeypressHandler__ClearCommandStateArray_x                  0x63AB10
#define KeypressHandler__HandleKeyDown_x                           0x63AB30
#define KeypressHandler__HandleKeyUp_x                             0x63ABD0
#define KeypressHandler__SaveKeymapping_x                          0x63B020

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7917C0
#define MapViewMap__SaveEx_x                                       0x794B80
#define MapViewMap__SetZoom_x                                      0x799240

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8DFBE0

// StringTable 
#define StringTable__getString_x                                   0x8DA9D0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x660F10
#define PcZoneClient__RemovePetEffect_x                            0x661540
#define PcZoneClient__HasAlternateAbility_x                        0x65B340
#define PcZoneClient__GetCurrentMod_x                              0x4E63E0
#define PcZoneClient__GetModCap_x                                  0x4E62E0
#define PcZoneClient__CanEquipItem_x                               0x65B9F0
#define PcZoneClient__GetItemByID_x                                0x65E4E0
#define PcZoneClient__GetItemByItemClass_x                         0x65E630
#define PcZoneClient__RemoveBuffEffect_x                           0x661560
#define PcZoneClient__BandolierSwap_x                              0x65C5C0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65E010

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F10F0

//IconCache
#define IconCache__GetIcon_x                                       0x732E10

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x72A910
#define CContainerMgr__CloseContainer_x                            0x72ABE0
#define CContainerMgr__OpenExperimentContainer_x                   0x72B660

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7E9FE0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62E080

//CLootWnd
#define CLootWnd__LootAll_x                                        0x787DC0
#define CLootWnd__RequestLootSlot_x                                0x7870A0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58AB10
#define EQ_Spell__SpellAffects_x                                   0x58AF80
#define EQ_Spell__SpellAffectBase_x                                0x58AD40
#define EQ_Spell__IsStackable_x                                    0x4CB030
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CAE20
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B8260
#define EQ_Spell__IsSPAStacking_x                                  0x58BDD0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58B2E0
#define EQ_Spell__IsNoRemove_x                                     0x4CB010
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58BDE0
#define __IsResEffectSpell_x                                       0x4CA290

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD8D0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8EA200

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8313B0
#define CTargetWnd__WndNotification_x                              0x830BF0
#define CTargetWnd__RefreshTargetBuffs_x                           0x830EC0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x82FD50

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8359F0
#define CTaskWnd__ConfirmAbandonTask_x                             0x838630

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53F700
#define CTaskManager__HandleMessage_x                              0x53DB90
#define CTaskManager__GetTaskStatus_x                              0x53F7B0
#define CTaskManager__GetElementDescription_x                      0x53F830

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x585AB0
#define EqSoundManager__PlayScriptMp3_x                            0x585D70
#define EqSoundManager__SoundAssistPlay_x                          0x698F60
#define EqSoundManager__WaveInstancePlay_x                         0x6984D0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x530C20

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x968740
#define CTextureAnimation__Draw_x                                  0x968940

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x964690

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56B870
#define CAltAbilityData__GetMercMaxRank_x                          0x56B800
#define CAltAbilityData__GetMaxRank_x                              0x560C80

//CTargetRing
#define CTargetRing__Cast_x                                        0x62C1A0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CAE00
#define CharacterBase__CreateItemGlobalIndex_x                     0x517C30
#define CharacterBase__CreateItemIndex_x                           0x6342C0
#define CharacterBase__GetItemPossession_x                         0x5034E0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8F2850
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8F28B0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x711900
#define CCastSpellWnd__IsBardSongPlaying_x                         0x712130
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x7121E0

//messages
#define msg_spell_worn_off_x                                       0x5AF750
#define msg_new_text_x                                             0x5A40F0
#define __msgTokenTextParam_x                                      0x5B19F0
#define msgTokenText_x                                             0x5B1C40

//SpellManager
#define SpellManager__vftable_x                                    0xAFF304
#define SpellManager__SpellManager_x                               0x69C290
#define Spellmanager__LoadTextSpells_x                             0x69CB80
#define SpellManager__GetSpellByGroupAndRank_x                     0x69C460

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9B0860

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x518280
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B5BC0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64CED0
#define ItemGlobalIndex__IsValidIndex_x                            0x518310

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8EABA0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8EAE20

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7806E0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x72F010
#define CCursorAttachment__AttachToCursor1_x                       0x72F050
#define CCursorAttachment__Deactivate_x                            0x730040

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x95B350
#define CSidlManagerBase__CreatePageWnd_x                          0x95AB40
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x956DD0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x956D60

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x978600
#define CEQSuiteTextureLoader__GetTexture_x                        0x9782C0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x5151B0
#define CFindItemWnd__WndNotification_x                            0x515C90
#define CFindItemWnd__Update_x                                     0x516800
#define CFindItemWnd__PickupSelectedItem_x                         0x5149E0

//IString
#define IString__Append_x                                          0x504DE0

//Camera
#define CDisplay__cameraType_x                                     0xE171EC
#define EverQuest__Cameras_x                                       0xED246C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51DBB0
#define LootFiltersManager__GetItemFilterData_x                    0x51D4B0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51D4E0
#define LootFiltersManager__SetItemLootFilter_x                    0x51D700

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7D7DB0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9B6410
#define CResolutionHandler__GetWindowedStyle_x                     0x693B40

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7275C0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x900170
#define CDistillerInfo__Instance_x                                 0x900110

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7467D0
#define CGroupWnd__UpdateDisplay_x                                 0x745B20

//ItemBase
#define ItemBase__IsLore_x                                         0x8C0770
#define ItemBase__IsLoreEquipped_x                                 0x8C07E0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EB300
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EB440
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EB4A0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6892B0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68CC10

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50B510

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F77E0
#define FactionManagerClient__HandleFactionMessage_x               0x4F7E50
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F8450
#define FactionManagerClient__GetMaxFaction_x                      0x4F846F
#define FactionManagerClient__GetMinFaction_x                      0x4F8420

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5034B0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x93FA60

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C600

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x5037F0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56AD00

//CTargetManager
#define CTargetManager__Get_x                                      0x69FB20

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6892B0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A9440

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BE110

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF6FB00

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6DB320
#define CAAWnd__UpdateSelected_x                                   0x6D7B90
#define CAAWnd__Update_x                                           0x6DA640

//CXRect
#define CXRect__operator_and_x                                     0x73D8B0

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x4835B0

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
