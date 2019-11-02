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
#define __ExpectedVersionDate                                     "Nov  2 2019"
#define __ExpectedVersionTime                                     "04:24:55"
#define __ActualVersionDate_x                                      0xB06F18
#define __ActualVersionTime_x                                      0xB06F0C
#define __ActualVersionBuild_x                                     0xAF2C04

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62B800
#define __MemChecker1_x                                            0x8FE9E0
#define __MemChecker2_x                                            0x6BA0A0
#define __MemChecker3_x                                            0x6B9FF0
#define __MemChecker4_x                                            0x856380
#define __EncryptPad0_x                                            0xC3D3E0
#define __EncryptPad1_x                                            0xC9B5A0
#define __EncryptPad2_x                                            0xC4DC78
#define __EncryptPad3_x                                            0xC4D878
#define __EncryptPad4_x                                            0xC8BBF8
#define __EncryptPad5_x                                            0xF64CDC
#define __AC1_x                                                    0x812DF6
#define __AC2_x                                                    0x5E57EF
#define __AC3_x                                                    0x5ECEEF
#define __AC4_x                                                    0x5F0EC0
#define __AC5_x                                                    0x5F71CF
#define __AC6_x                                                    0x5FB7E6
#define __AC7_x                                                    0x5E5260
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x192718

// Direct Input
#define DI8__Main_x                                                0xF671B8
#define DI8__Keyboard_x                                            0xF671BC
#define DI8__Mouse_x                                               0xF671D0
#define DI8__Mouse_Copy_x                                          0xEC03A4
#define DI8__Mouse_Check_x                                         0xF64D04
#define __AutoSkillArray_x                                         0xEC12BC
#define __Attack_x                                                 0xF5F0E3
#define __Autofire_x                                               0xF5F0E4
#define __BindList_x                                               0xC2BE18
#define g_eqCommandStates_x                                        0xC2CB98
#define __Clicks_x                                                 0xEC045C
#define __CommandList_x                                            0xC2D758
#define __CurrentMapLabel_x                                        0xF77B64
#define __CurrentSocial_x                                          0xC157CC
#define __DoAbilityList_x                                          0xEF6C04
#define __do_loot_x                                                0x5B1B80
#define __DrawHandler_x                                            0x15F6ED8
#define __GroupCount_x                                             0xEB2C6A
#define __Guilds_x                                                 0xEB6BB0
#define __gWorld_x                                                 0xEB2B34
#define __HWnd_x                                                   0xF671D4
#define __heqmain_x                                                0xF671AC
#define __InChatMode_x                                             0xEC038C
#define __LastTell_x                                               0xEC2300
#define __LMouseHeldTime_x                                         0xEC04C8
#define __Mouse_x                                                  0xF67198
#define __MouseLook_x                                              0xEC0422
#define __MouseEventTime_x                                         0xF5FBC4
#define __gpbCommandEvent_x                                        0xEB2E5C
#define __NetStatusToggle_x                                        0xEC0425
#define __PCNames_x                                                0xEC18AC
#define __RangeAttackReady_x                                       0xEC15A0
#define __RMouseHeldTime_x                                         0xEC04C4
#define __RunWalkState_x                                           0xEC0390
#define __ScreenMode_x                                             0xDFE470
#define __ScreenX_x                                                0xEC0344
#define __ScreenY_x                                                0xEC0340
#define __ScreenXMax_x                                             0xEC0348
#define __ScreenYMax_x                                             0xEC034C
#define __ServerHost_x                                             0xEB079B
#define __ServerName_x                                             0xEF6BC4
#define __ShiftKeyDown_x                                           0xEC0A1C
#define __ShowNames_x                                              0xEC175C
#define __Socials_x                                                0xEF6CC4
#define __SubscriptionType_x                                       0xFBC068
#define __TargetAggroHolder_x                                      0xF7A518
#define __ZoneType_x                                               0xEC0820
#define __GroupAggro_x                                             0xF7A558
#define __LoginName_x                                              0xF67914
#define __Inviter_x                                                0xF5F060
#define __AttackOnAssist_x                                         0xEC1718
#define __UseTellWindows_x                                         0xEC1A48
#define __gfMaxZoomCameraDistance_x                                0xAFC878
#define __gfMaxCameraDistance_x                                    0xB28DB8
#define __pulAutoRun_x                                             0xEC0440
#define __pulForward_x                                             0xEC1A80
#define __pulBackward_x                                            0xEC1A84
#define __pulTurnRight_x                                           0xEC1A88
#define __pulTurnLeft_x                                            0xEC1A8C
#define __pulStrafeLeft_x                                          0xEC1A90
#define __pulStrafeRight_x                                         0xEC1A94

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB2F48
#define instEQZoneInfo_x                                           0xEC0618
#define pinstActiveBanker_x                                        0xEB2E74
#define pinstActiveCorpse_x                                        0xEB2E6C
#define pinstActiveGMaster_x                                       0xEB2E70
#define pinstActiveMerchant_x                                      0xEB2E68
#define pinstAltAdvManager_x                                       0xDFF180
#define pinstBandageTarget_x                                       0xEB2E84
#define pinstCamActor_x                                            0xDFE460
#define pinstCDBStr_x                                              0xDFDE9C
#define pinstCDisplay_x                                            0xEB2B18
#define pinstCEverQuest_x                                          0xF671D8
#define pinstEverQuestInfo_x                                       0xEC0338
#define pinstCharData_x                                            0xEB2C48
#define pinstCharSpawn_x                                           0xEB2F3C
#define pinstControlledMissile_x                                   0xEB0B00
#define pinstControlledPlayer_x                                    0xEB2F3C
#define pinstCResolutionHandler_x                                  0x15F7108
#define pinstCSidlManager_x                                        0x15F60A0
#define pinstCXWndManager_x                                        0x15F609C
#define instDynamicZone_x                                          0xEB6A88
#define pinstDZMember_x                                            0xEB6B98
#define pinstDZTimerInfo_x                                         0xEB6B9C
#define pinstEqLogin_x                                             0xF67260
#define instEQMisc_x                                               0xDFDDE0
#define pinstEQSoundManager_x                                      0xE00150
#define pinstEQSpellStrings_x                                      0xCC0858
#define instExpeditionLeader_x                                     0xEB6AD2
#define instExpeditionName_x                                       0xEB6B12
#define pinstGroup_x                                               0xEB2C66
#define pinstImeManager_x                                          0x15F6098
#define pinstLocalPlayer_x                                         0xEB2E64
#define pinstMercenaryData_x                                       0xF616B4
#define pinstMercenaryStats_x                                      0xF7A664
#define pinstModelPlayer_x                                         0xEB2E7C
#define pinstPCData_x                                              0xEB2C48
#define pinstSkillMgr_x                                            0xF63820
#define pinstSpawnManager_x                                        0xF622C8
#define pinstSpellManager_x                                        0xF63A40
#define pinstSpellSets_x                                           0xF57D0C
#define pinstStringTable_x                                         0xEB2C4C
#define pinstSwitchManager_x                                       0xEB04E8
#define pinstTarget_x                                              0xEB2F38
#define pinstTargetObject_x                                        0xEB0638
#define pinstTargetSwitch_x                                        0xEB2B10
#define pinstTaskMember_x                                          0xDFDC70
#define pinstTrackTarget_x                                         0xEB2F40
#define pinstTradeTarget_x                                         0xEB2E78
#define instTributeActive_x                                        0xDFDE01
#define pinstViewActor_x                                           0xDFE45C
#define pinstWorldData_x                                           0xEB0B0C
#define pinstZoneAddr_x                                            0xEC08B8
#define pinstPlayerPath_x                                          0xF62360
#define pinstTargetIndicator_x                                     0xF63CA8
#define EQObject_Top_x                                             0xEB2E60
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDFE724
#define pinstCAchievementsWnd_x                                    0xDFE4BC
#define pinstCActionsWnd_x                                         0xDFE4E8
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDFDF84
#define pinstCAdvancedLootWnd_x                                    0xDFE7C8
#define pinstCAdventureLeaderboardWnd_x                            0xF71338
#define pinstCAdventureRequestWnd_x                                0xF713E8
#define pinstCAdventureStatsWnd_x                                  0xF71498
#define pinstCAggroMeterWnd_x                                      0xDFE454
#define pinstCAlarmWnd_x                                           0xDFE78C
#define pinstCAlertHistoryWnd_x                                    0xDFE7C0
#define pinstCAlertStackWnd_x                                      0xDFE738
#define pinstCAlertWnd_x                                           0xDFE74C
#define pinstCAltStorageWnd_x                                      0xF717F8
#define pinstCAudioTriggersWindow_x                                0xCB2B88
#define pinstCAuraWnd_x                                            0xDFE428
#define pinstCAvaZoneWnd_x                                         0xDFE788
#define pinstCBandolierWnd_x                                       0xDFE450
#define pinstCBankWnd_x                                            0xDFE424
#define pinstCBarterMerchantWnd_x                                  0xF72A38
#define pinstCBarterSearchWnd_x                                    0xF72AE8
#define pinstCBarterWnd_x                                          0xF72B98
#define pinstCBazaarConfirmationWnd_x                              0xDFE4F8
#define pinstCBazaarSearchWnd_x                                    0xDFE4B0
#define pinstCBazaarWnd_x                                          0xDFE774
#define pinstCBlockedBuffWnd_x                                     0xDFE42C
#define pinstCBlockedPetBuffWnd_x                                  0xDFE44C
#define pinstCBodyTintWnd_x                                        0xDFE4FC
#define pinstCBookWnd_x                                            0xDFE490
#define pinstCBreathWnd_x                                          0xDFE744
#define pinstCBuffWindowNORMAL_x                                   0xDFE010
#define pinstCBuffWindowSHORT_x                                    0xDFE014
#define pinstCBugReportWnd_x                                       0xDFE420
#define pinstCButtonWnd_x                                          0x15F6308
#define pinstCCastingWnd_x                                         0xDFE480
#define pinstCCastSpellWnd_x                                       0xDFE73C
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDFE778
#define pinstCChatWindowManager_x                                  0xF73658
#define pinstCClaimWnd_x                                           0xF737B0
#define pinstCColorPickerWnd_x                                     0xDFE4F0
#define pinstCCombatAbilityWnd_x                                   0xDFE784
#define pinstCCombatSkillsSelectWnd_x                              0xDFE7A8
#define pinstCCompassWnd_x                                         0xDFE4EC
#define pinstCConfirmationDialog_x                                 0xF786B0
#define pinstCContainerMgr_x                                       0xDFE76C
#define pinstCContextMenuManager_x                                 0x15F6058
#define pinstCCursorAttachment_x                                   0xDFE464
#define pinstCDynamicZoneWnd_x                                     0xF73D78
#define pinstCEditLabelWnd_x                                       0xDFDF90
#define pinstCEQMainWnd_x                                          0xF73FC0
#define pinstCEventCalendarWnd_x                                   0xDFE00C
#define pinstCExtendedTargetWnd_x                                  0xDFE440
#define pinstCFacePick_x                                           0xDFE7B8
#define pinstCFactionWnd_x                                         0xDFE764
#define pinstCFellowshipWnd_x                                      0xF741C0
#define pinstCFileSelectionWnd_x                                   0xDFE47C
#define pinstCFindItemWnd_x                                        0xDFE758
#define pinstCFindLocationWnd_x                                    0xF74318
#define pinstCFriendsWnd_x                                         0xDFE7C4
#define pinstCGemsGameWnd_x                                        0xDFE760
#define pinstCGiveWnd_x                                            0xDFE790
#define pinstCGroupSearchFiltersWnd_x                              0xDFE488
#define pinstCGroupSearchWnd_x                                     0xF74710
#define pinstCGroupWnd_x                                           0xF747C0
#define pinstCGuildBankWnd_x                                       0xEC16FC
#define pinstCGuildCreationWnd_x                                   0xF74920
#define pinstCGuildMgmtWnd_x                                       0xF749D0
#define pinstCharacterCreation_x                                   0xDFE7B0
#define pinstCHelpWnd_x                                            0xDFDF7C
#define pinstCHeritageSelectionWnd_x                               0xDFE7D0
#define pinstCHotButtonWnd_x                                       0xF76B28
#define pinstCHotButtonWnd1_x                                      0xF76B28
#define pinstCHotButtonWnd2_x                                      0xF76B2C
#define pinstCHotButtonWnd3_x                                      0xF76B30
#define pinstCHotButtonWnd4_x                                      0xF76B34
#define pinstCIconSelectionWnd_x                                   0xDFE458
#define pinstCInspectWnd_x                                         0xDFDF78
#define pinstCInventoryWnd_x                                       0xDFDF38
#define pinstCInvSlotMgr_x                                         0xDFE720
#define pinstCItemDisplayManager_x                                 0xF770B8
#define pinstCItemExpTransferWnd_x                                 0xF771E8
#define pinstCItemOverflowWnd_x                                    0xDFE4B8
#define pinstCJournalCatWnd_x                                      0xDFE498
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDFE444
#define pinstCKeyRingWnd_x                                         0xDFDF8C
#define pinstCLargeDialogWnd_x                                     0xF79330
#define pinstCLayoutCopyWnd_x                                      0xF77538
#define pinstCLFGuildWnd_x                                         0xF775E8
#define pinstCLoadskinWnd_x                                        0xDFE770
#define pinstCLootFiltersCopyWnd_x                                 0xCCF178
#define pinstCLootFiltersWnd_x                                     0xDFE740
#define pinstCLootSettingsWnd_x                                    0xDFE754
#define pinstCLootWnd_x                                            0xDFE49C
#define pinstCMailAddressBookWnd_x                                 0xDFE72C
#define pinstCMailCompositionWnd_x                                 0xDFE510
#define pinstCMailIgnoreListWnd_x                                  0xDFE730
#define pinstCMailWnd_x                                            0xDFE4E4
#define pinstCManageLootWnd_x                                      0xDFF630
#define pinstCMapToolbarWnd_x                                      0xDFDF80
#define pinstCMapViewWnd_x                                         0xDFDF48
#define pinstCMarketplaceWnd_x                                     0xDFE748
#define pinstCMerchantWnd_x                                        0xDFE4A0
#define pinstCMIZoneSelectWnd_x                                    0xF77E20
#define pinstCMusicPlayerWnd_x                                     0xDFE4A8
#define pinstCNameChangeMercWnd_x                                  0xDFE4E0
#define pinstCNameChangePetWnd_x                                   0xDFE4C0
#define pinstCNameChangeWnd_x                                      0xDFE508
#define pinstCNoteWnd_x                                            0xDFDF4C
#define pinstCObjectPreviewWnd_x                                   0xDFE750
#define pinstCOptionsWnd_x                                         0xDFDF60
#define pinstCPetInfoWnd_x                                         0xDFE4C4
#define pinstCPetitionQWnd_x                                       0xDFE4AC
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDFE500
#define pinstCPlayerWnd_x                                          0xDFE4C8
#define pinstCPopupWndManager_x                                    0xF786B0
#define pinstCProgressionSelectionWnd_x                            0xF78760
#define pinstCPurchaseGroupWnd_x                                   0xDFE798
#define pinstCPurchaseWnd_x                                        0xDFE768
#define pinstCPvPLeaderboardWnd_x                                  0xF78810
#define pinstCPvPStatsWnd_x                                        0xF788C0
#define pinstCQuantityWnd_x                                        0xDFE448
#define pinstCRaceChangeWnd_x                                      0xDFE728
#define pinstCRaidOptionsWnd_x                                     0xDFE48C
#define pinstCRaidWnd_x                                            0xDFE518
#define pinstCRealEstateItemsWnd_x                                 0xDFE4B4
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDFE434
#define pinstCRealEstateManageWnd_x                                0xDFE7A0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDFE7BC
#define pinstCRealEstatePlotSearchWnd_x                            0xDFDF3C
#define pinstCRealEstatePurchaseWnd_x                              0xDFDF74
#define pinstCRespawnWnd_x                                         0xDFE438
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDFE734
#define pinstCSendMoneyWnd_x                                       0xDFE7A4
#define pinstCServerListWnd_x                                      0xDFDF9C
#define pinstCSkillsSelectWnd_x                                    0xDFE77C
#define pinstCSkillsWnd_x                                          0xDFE75C
#define pinstCSocialEditWnd_x                                      0xDFDF88
#define pinstCSocialWnd_x                                          0xDFE4DC
#define pinstCSpellBookWnd_x                                       0xDFE780
#define pinstCStoryWnd_x                                           0xDFE4CC
#define pinstCTargetOfTargetWnd_x                                  0xF7A6E8
#define pinstCTargetWnd_x                                          0xDFE430
#define pinstCTaskOverlayWnd_x                                     0xDFE794
#define pinstCTaskSelectWnd_x                                      0xF7A840
#define pinstCTaskManager_x                                        0xCCFAB8
#define pinstCTaskTemplateSelectWnd_x                              0xF7A8F0
#define pinstCTaskWnd_x                                            0xF7A9A0
#define pinstCTextEntryWnd_x                                       0xDFE018
#define pinstCTimeLeftWnd_x                                        0xDFE484
#define pinstCTipWndCONTEXT_x                                      0xF7ABA4
#define pinstCTipWndOFDAY_x                                        0xF7ABA0
#define pinstCTitleWnd_x                                           0xF7AC50
#define pinstCTrackingWnd_x                                        0xDFDF40
#define pinstCTradeskillWnd_x                                      0xF7ADB8
#define pinstCTradeWnd_x                                           0xDFE50C
#define pinstCTrainWnd_x                                           0xDFE504
#define pinstCTributeBenefitWnd_x                                  0xF7AFB8
#define pinstCTributeMasterWnd_x                                   0xF7B068
#define pinstCTributeTrophyWnd_x                                   0xF7B118
#define pinstCVideoModesWnd_x                                      0xDFE514
#define pinstCVoiceMacroWnd_x                                      0xF64410
#define pinstCVoteResultsWnd_x                                     0xDFE4A4
#define pinstCVoteWnd_x                                            0xDFE494
#define pinstCWebManager_x                                         0xF64A8C
#define pinstCZoneGuideWnd_x                                       0xDFE79C
#define pinstCZonePathWnd_x                                        0xDFE7AC

#define pinstEQSuiteTextureLoader_x                                0xC9D078
#define pinstItemIconCache_x                                       0xF73F78
#define pinstLootFiltersManager_x                                  0xCCF228
#define pinstRewardSelectionWnd_x                                  0xF79008

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5ACFE0
#define __CastRay2_x                                               0x5AD030
#define __ConvertItemTags_x                                        0x5C8B70
#define __CleanItemTags_x                                          0x47D010
#define __DoesFileExist_x                                          0x901A70
#define __EQGetTime_x                                              0x8FE4B0
#define __ExecuteCmd_x                                             0x5A58A0
#define __FixHeading_x                                             0x99A000
#define __GameLoop_x                                               0x6B9290
#define __get_bearing_x                                            0x5ACB50
#define __get_melee_range_x                                        0x5AD220
#define __GetAnimationCache_x                                      0x71E570
#define __GetGaugeValueFromEQ_x                                    0x8112A0
#define __GetLabelFromEQ_x                                         0x812D80
#define __GetXTargetType_x                                         0x99B9E0
#define __HandleMouseWheel_x                                       0x6BA150
#define __HeadingDiff_x                                            0x99A070
#define __HelpPath_x                                               0xF5F7B4
#define __LoadFrontEnd_x                                           0x6B65B0
#define __NewUIINI_x                                               0x810F70
#define __ProcessGameEvents_x                                      0x60D060
#define __ProcessMouseEvent_x                                      0x60C820
#define __SaveColors_x                                             0x54F5A0
#define __STMLToText_x                                             0x93D360
#define __ToggleKeyRingItem_x                                      0x512C80
#define CMemoryMappedFile__SetFile_x                               0xA89220
#define CrashDetected_x                                            0x6B8050
#define DrawNetStatus_x                                            0x638C80
#define Expansion_HoT_x                                            0xEC1704
#define Teleport_Table_Size_x                                      0xEB0640
#define Teleport_Table_x                                           0xEB0B10
#define Util__FastTime_x                                           0x8FE080

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4902C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4991D0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498FA0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493860
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492CB0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5572D0
#define AltAdvManager__IsAbilityReady_x                            0x556200
#define AltAdvManager__GetAAById_x                                 0x556400
#define AltAdvManager__CanTrainAbility_x                           0x556470
#define AltAdvManager__CanSeeAbility_x                             0x5567D0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9FC0
#define CharacterZoneClient__HasSkill_x                            0x4D4EB0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D65D0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE360
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA960
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8F80
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9060
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9140
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3150
#define CharacterZoneClient__BardCastBard_x                        0x4C5CB0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAA30
#define CharacterZoneClient__GetEffect_x                           0x4BA8A0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C41A0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4270
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C42C0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4410
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C45E0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2810
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7530
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6FB0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DFC90
#define CBankWnd__WndNotification_x                                0x6DFA70

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6ED520

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61B670
#define CButtonWnd__CButtonWnd_x                                   0x939720

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x70D6F0
#define CChatManager__InitContextMenu_x                            0x706840
#define CChatManager__FreeChatWindow_x                             0x70C230
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8580
#define CChatManager__SetLockedActiveChatWindow_x                  0x70D370
#define CChatManager__CreateChatWindow_x                           0x70C870

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8690

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x94DE10
#define CContextMenu__dCContextMenu_x                              0x94E050
#define CContextMenu__AddMenuItem_x                                0x94E060
#define CContextMenu__RemoveMenuItem_x                             0x94E370
#define CContextMenu__RemoveAllMenuItems_x                         0x94E390
#define CContextMenu__CheckMenuItem_x                              0x94E410
#define CContextMenu__SetMenuItem_x                                0x94E290
#define CContextMenu__AddSeparator_x                               0x94E1F0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x94E9B0
#define CContextMenuManager__RemoveMenu_x                          0x94EA20
#define CContextMenuManager__PopupMenu_x                           0x94EAE0
#define CContextMenuManager__Flush_x                               0x94E950
#define CContextMenuManager__GetMenu_x                             0x49B320
#define CContextMenuManager__CreateDefaultMenu_x                   0x718D70

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DA830
#define CChatService__GetFriendName_x                              0x8DA840

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x70DF60
#define CChatWindow__Clear_x                                       0x70F220
#define CChatWindow__WndNotification_x                             0x70F9B0
#define CChatWindow__AddHistory_x                                  0x70EAE0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94B250
#define CComboWnd__Draw_x                                          0x94A730
#define CComboWnd__GetCurChoice_x                                  0x94B090
#define CComboWnd__GetListRect_x                                   0x94ABF0
#define CComboWnd__GetTextRect_x                                   0x94B2C0
#define CComboWnd__InsertChoice_x                                  0x94AD80
#define CComboWnd__SetColors_x                                     0x94AD50
#define CComboWnd__SetChoice_x                                     0x94B060
#define CComboWnd__GetItemCount_x                                  0x94B0A0
#define CComboWnd__GetCurChoiceText_x                              0x94B0E0
#define CComboWnd__GetChoiceText_x                                 0x94B0B0
#define CComboWnd__InsertChoiceAtIndex_x                           0x94AE20

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x716740
#define CContainerWnd__vftable_x                                   0xB100F4
#define CContainerWnd__SetContainer_x                              0x717CB0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x549FE0
#define CDisplay__PreZoneMainUI_x                                  0x549FF0
#define CDisplay__CleanGameUI_x                                    0x54F360
#define CDisplay__GetClickedActor_x                                0x542300
#define CDisplay__GetUserDefinedColor_x                            0x53A9C0
#define CDisplay__GetWorldFilePath_x                               0x543D70
#define CDisplay__is3dON_x                                         0x53EF60
#define CDisplay__ReloadUI_x                                       0x549470
#define CDisplay__WriteTextHD2_x                                   0x53ED50
#define CDisplay__TrueDistance_x                                   0x545A30
#define CDisplay__SetViewActor_x                                   0x541C20
#define CDisplay__GetFloorHeight_x                                 0x53F020
#define CDisplay__SetRenderWindow_x                                0x53D980
#define CDisplay__ToggleScreenshotMode_x                           0x5416F0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x96DBB0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x951380
#define CEditWnd__GetCharIndexPt_x                                 0x9522B0
#define CEditWnd__GetDisplayString_x                               0x952150
#define CEditWnd__GetHorzOffset_x                                  0x9509B0
#define CEditWnd__GetLineForPrintableChar_x                        0x953450
#define CEditWnd__GetSelStartPt_x                                  0x952560
#define CEditWnd__GetSTMLSafeText_x                                0x951F70
#define CEditWnd__PointFromPrintableChar_x                         0x953080
#define CEditWnd__SelectableCharFromPoint_x                        0x9531F0
#define CEditWnd__SetEditable_x                                    0x952630
#define CEditWnd__SetWindowTextA_x                                 0x951CF0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FACC0
#define CEverQuest__ClickedPlayer_x                                0x5ECCD0
#define CEverQuest__CreateTargetIndicator_x                        0x60A2F0
#define CEverQuest__DeleteTargetIndicator_x                        0x60A380
#define CEverQuest__DoTellWindow_x                                 0x4E8770
#define CEverQuest__OutputTextToLog_x                              0x4E89F0
#define CEverQuest__DropHeldItemOnGround_x                         0x5E1D10
#define CEverQuest__dsp_chat_x                                     0x4E8D80
#define CEverQuest__trimName_x                                     0x6065D0
#define CEverQuest__Emote_x                                        0x5FB520
#define CEverQuest__EnterZone_x                                    0x5F54A0
#define CEverQuest__GetBodyTypeDesc_x                              0x5FFE90
#define CEverQuest__GetClassDesc_x                                 0x6004D0
#define CEverQuest__GetClassThreeLetterCode_x                      0x600AD0
#define CEverQuest__GetDeityDesc_x                                 0x608C30
#define CEverQuest__GetLangDesc_x                                  0x600C90
#define CEverQuest__GetRaceDesc_x                                  0x6004B0
#define CEverQuest__InterpretCmd_x                                 0x609200
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E5F10
#define CEverQuest__LMouseUp_x                                     0x5E42A0
#define CEverQuest__RightClickedOnPlayer_x                         0x5E67F0
#define CEverQuest__RMouseUp_x                                     0x5E5220
#define CEverQuest__SetGameState_x                                 0x5E1AA0
#define CEverQuest__UPCNotificationFlush_x                         0x6064D0
#define CEverQuest__IssuePetCommand_x                              0x602090
#define CEverQuest__ReportSuccessfulHit_x                          0x5FC910

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x728750
#define CGaugeWnd__CalcLinesFillRect_x                             0x7287B0
#define CGaugeWnd__Draw_x                                          0x727DD0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF270
#define CGuild__GetGuildName_x                                     0x4AE350
#define CGuild__GetGuildIndex_x                                    0x4AE6E0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x743BA0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61BA30

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x750C00
#define CInvSlotMgr__MoveItem_x                                    0x74F910
#define CInvSlotMgr__SelectSlot_x                                  0x750CD0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x74E180
#define CInvSlot__SliderComplete_x                                 0x74BED0
#define CInvSlot__GetItemBase_x                                    0x74B850
#define CInvSlot__UpdateItem_x                                     0x74B9C0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x752750
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7518F0
#define CInvSlotWnd__HandleLButtonUp_x                             0x7522D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80C590
#define CItemDisplayWnd__UpdateStrings_x                           0x760F20
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75ABF0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75B120
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x761530
#define CItemDisplayWnd__AboutToShow_x                             0x760B70
#define CItemDisplayWnd__WndNotification_x                         0x762620
#define CItemDisplayWnd__RequestConvertItem_x                      0x7620E0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x75FBE0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x760990

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x844F70

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x766B70

// CLabel 
#define CLabel__Draw_x                                             0x76C5D0

// CListWnd
#define CListWnd__CListWnd_x                                       0x923810
#define CListWnd__dCListWnd_x                                      0x923B30
#define CListWnd__AddColumn_x                                      0x927FB0
#define CListWnd__AddColumn1_x                                     0x928000
#define CListWnd__AddLine_x                                        0x928390
#define CListWnd__AddString_x                                      0x928190
#define CListWnd__CalculateFirstVisibleLine_x                      0x927D70
#define CListWnd__CalculateVSBRange_x                              0x927B50
#define CListWnd__ClearSel_x                                       0x928B70
#define CListWnd__ClearAllSel_x                                    0x928BD0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x9295F0
#define CListWnd__Compare_x                                        0x927480
#define CListWnd__Draw_x                                           0x923C60
#define CListWnd__DrawColumnSeparators_x                           0x926450
#define CListWnd__DrawHeader_x                                     0x9268C0
#define CListWnd__DrawItem_x                                       0x926DC0
#define CListWnd__DrawLine_x                                       0x9265C0
#define CListWnd__DrawSeparator_x                                  0x9264F0
#define CListWnd__EnableLine_x                                     0x925D20
#define CListWnd__EnsureVisible_x                                  0x929510
#define CListWnd__ExtendSel_x                                      0x928AA0
#define CListWnd__GetColumnTooltip_x                               0x925860
#define CListWnd__GetColumnMinWidth_x                              0x9258D0
#define CListWnd__GetColumnWidth_x                                 0x9257D0
#define CListWnd__GetCurSel_x                                      0x925160
#define CListWnd__GetItemAtPoint_x                                 0x925FA0
#define CListWnd__GetItemAtPoint1_x                                0x926010
#define CListWnd__GetItemData_x                                    0x9251E0
#define CListWnd__GetItemHeight_x                                  0x9255A0
#define CListWnd__GetItemIcon_x                                    0x925370
#define CListWnd__GetItemRect_x                                    0x925E10
#define CListWnd__GetItemText_x                                    0x925220
#define CListWnd__GetSelList_x                                     0x928C20
#define CListWnd__GetSeparatorRect_x                               0x926250
#define CListWnd__InsertLine_x                                     0x928780
#define CListWnd__RemoveLine_x                                     0x9288D0
#define CListWnd__SetColors_x                                      0x927B20
#define CListWnd__SetColumnJustification_x                         0x927850
#define CListWnd__SetColumnWidth_x                                 0x927770
#define CListWnd__SetCurSel_x                                      0x9289E0
#define CListWnd__SetItemColor_x                                   0x9291C0
#define CListWnd__SetItemData_x                                    0x929180
#define CListWnd__SetItemText_x                                    0x928D90
#define CListWnd__ShiftColumnSeparator_x                           0x927910
#define CListWnd__Sort_x                                           0x927600
#define CListWnd__ToggleSel_x                                      0x928A10
#define CListWnd__SetColumnsSizable_x                              0x9279C0
#define CListWnd__SetItemWnd_x                                     0x929040
#define CListWnd__GetItemWnd_x                                     0x9253C0
#define CListWnd__SetItemIcon_x                                    0x928E10
#define CListWnd__CalculateCustomWindowPositions_x                 0x927E70
#define CListWnd__SetVScrollPos_x                                  0x927750

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x781E00
#define CMapViewWnd__GetWorldCoordinates_x                         0x780510
#define CMapViewWnd__HandleLButtonDown_x                           0x77D550

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A1EC0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A27A0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A2CD0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A5C60
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A0A30
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AB820
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A1AE0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A8140
#define CPacketScrambler__hton_x                                   0x8A8130

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9429A0
#define CSidlManager__FindScreenPieceTemplate_x                    0x942DB0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x942BA0
#define CSidlManager__CreateLabel_x                                0x803A40
#define CSidlManager__CreateXWndFromTemplate_x                     0x945D10
#define CSidlManager__CreateXWndFromTemplate1_x                    0x945EE0
#define CSidlManager__CreateXWnd_x                                 0x803970
#define CSidlManager__CreateHotButtonWnd_x                         0x803F20

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x93F480
#define CSidlScreenWnd__CalculateVSBRange_x                        0x93F380
#define CSidlScreenWnd__ConvertToRes_x                             0x964C00
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x93EE10
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x93EB00
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x93EBD0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x93ECA0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x93F920
#define CSidlScreenWnd__EnableIniStorage_x                         0x93FDF0
#define CSidlScreenWnd__GetSidlPiece_x                             0x93FB10
#define CSidlScreenWnd__Init1_x                                    0x93E700
#define CSidlScreenWnd__LoadIniInfo_x                              0x93FE40
#define CSidlScreenWnd__LoadIniListWnd_x                           0x940980
#define CSidlScreenWnd__LoadSidlScreen_x                           0x93DB10
#define CSidlScreenWnd__StoreIniInfo_x                             0x940500
#define CSidlScreenWnd__StoreIniVis_x                              0x940860
#define CSidlScreenWnd__WndNotification_x                          0x93F830
#define CSidlScreenWnd__GetChildItem_x                             0x93FD70
#define CSidlScreenWnd__HandleLButtonUp_x                          0x92F3D0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F5F28

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x680040
#define CSkillMgr__GetSkillCap_x                                   0x680220
#define CSkillMgr__GetNameToken_x                                  0x67F7C0
#define CSkillMgr__IsActivatedSkill_x                              0x67F900
#define CSkillMgr__IsCombatSkill_x                                 0x67F840

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x94F790
#define CSliderWnd__SetValue_x                                     0x94F600
#define CSliderWnd__SetNumTicks_x                                  0x94F660

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x809A20

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x957FA0
#define CStmlWnd__CalculateHSBRange_x                              0x959080
#define CStmlWnd__CalculateVSBRange_x                              0x958FF0
#define CStmlWnd__CanBreakAtCharacter_x                            0x95D3C0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x95E050
#define CStmlWnd__ForceParseNow_x                                  0x958540
#define CStmlWnd__GetNextTagPiece_x                                0x95D320
#define CStmlWnd__GetSTMLText_x                                    0x502640
#define CStmlWnd__GetVisibleText_x                                 0x958560
#define CStmlWnd__InitializeWindowVariables_x                      0x95DEA0
#define CStmlWnd__MakeStmlColorTag_x                               0x957610
#define CStmlWnd__MakeWndNotificationTag_x                         0x957680
#define CStmlWnd__SetSTMLText_x                                    0x9566C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x95F150
#define CStmlWnd__UpdateHistoryString_x                            0x95E260

// CTabWnd 
#define CTabWnd__Draw_x                                            0x955810
#define CTabWnd__DrawCurrentPage_x                                 0x955F40
#define CTabWnd__DrawTab_x                                         0x955C60
#define CTabWnd__GetCurrentPage_x                                  0x955010
#define CTabWnd__GetPageInnerRect_x                                0x955250
#define CTabWnd__GetTabInnerRect_x                                 0x955190
#define CTabWnd__GetTabRect_x                                      0x955040
#define CTabWnd__InsertPage_x                                      0x955460
#define CTabWnd__SetPage_x                                         0x9552D0
#define CTabWnd__SetPageRect_x                                     0x955750
#define CTabWnd__UpdatePage_x                                      0x955B20
#define CTabWnd__GetPageFromTabIndex_x                             0x955BA0
#define CTabWnd__GetCurrentTabIndex_x                              0x955000

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x766F40
#define CPageWnd__SetTabText_x                                     0x954B60

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8EB0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92C270
#define CTextureFont__GetTextExtent_x                              0x92C430

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B3460
#define CHtmlComponentWnd__ValidateUri_x                           0x745590
#define CHtmlWnd__SetClientCallbacks_x                             0x620AA0
#define CHtmlWnd__AddObserver_x                                    0x620AC0
#define CHtmlWnd__RemoveObserver_x                                 0x620B20
#define Window__getProgress_x                                      0x85D960
#define Window__getStatus_x                                        0x85D980
#define Window__getURI_x                                           0x85D990

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96A640

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x919430

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E83C0
#define CXStr__CXStr1_x                                            0x481500
#define CXStr__CXStr3_x                                            0x8FA5B0
#define CXStr__dCXStr_x                                            0x4786A0
#define CXStr__operator_equal_x                                    0x8FA7E0
#define CXStr__operator_equal1_x                                   0x8FA820
#define CXStr__operator_plus_equal1_x                              0x8FB2B0
#define CXStr__SetString_x                                         0x8FD1A0
#define CXStr__operator_char_p_x                                   0x8FACF0
#define CXStr__GetChar_x                                           0x8FCAD0
#define CXStr__Delete_x                                            0x8FC3A0
#define CXStr__GetUnicode_x                                        0x8FCB40
#define CXStr__GetLength_x                                         0x4A8C60
#define CXStr__Mid_x                                               0x47D3C0
#define CXStr__Insert_x                                            0x8FCBA0
#define CXStr__FindNext_x                                          0x8FC810

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x94DA10
#define CXWnd__BringToTop_x                                        0x932BF0
#define CXWnd__Center_x                                            0x932770
#define CXWnd__ClrFocus_x                                          0x932590
#define CXWnd__Destroy_x                                           0x932630
#define CXWnd__DoAllDrawing_x                                      0x92EB60
#define CXWnd__DrawChildren_x                                      0x92EB30
#define CXWnd__DrawColoredRect_x                                   0x92EFC0
#define CXWnd__DrawTooltip_x                                       0x92D680
#define CXWnd__DrawTooltipAtPoint_x                                0x92D740
#define CXWnd__GetBorderFrame_x                                    0x92EE20
#define CXWnd__GetChildWndAt_x                                     0x932C90
#define CXWnd__GetClientClipRect_x                                 0x930E10
#define CXWnd__GetScreenClipRect_x                                 0x930EE0
#define CXWnd__GetScreenRect_x                                     0x9310B0
#define CXWnd__GetTooltipRect_x                                    0x92F010
#define CXWnd__GetWindowTextA_x                                    0x49CAC0
#define CXWnd__IsActive_x                                          0x92F750
#define CXWnd__IsDescendantOf_x                                    0x931AA0
#define CXWnd__IsReallyVisible_x                                   0x931AD0
#define CXWnd__IsType_x                                            0x9332F0
#define CXWnd__Move_x                                              0x931B40
#define CXWnd__Move1_x                                             0x931C00
#define CXWnd__ProcessTransition_x                                 0x932720
#define CXWnd__Refade_x                                            0x931EE0
#define CXWnd__Resize_x                                            0x9321A0
#define CXWnd__Right_x                                             0x9329B0
#define CXWnd__SetFocus_x                                          0x932550
#define CXWnd__SetFont_x                                           0x9325C0
#define CXWnd__SetKeyTooltip_x                                     0x933120
#define CXWnd__SetMouseOver_x                                      0x92FF80
#define CXWnd__StartFade_x                                         0x931980
#define CXWnd__GetChildItem_x                                      0x932E00
#define CXWnd__SetParent_x                                         0x931870
#define CXWnd__Minimize_x                                          0x932210

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x965C80

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x935BF0
#define CXWndManager__DrawWindows_x                                0x935C10
#define CXWndManager__GetKeyboardFlags_x                           0x9383B0
#define CXWndManager__HandleKeyboardMsg_x                          0x937F60
#define CXWndManager__RemoveWnd_x                                  0x938600
#define CXWndManager__RemovePendingDeletionWnd_x                   0x938B60

// CDBStr
#define CDBStr__GetString_x                                        0x539970

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB940
#define EQ_Character__Cur_HP_x                                     0x4D1EF0
#define EQ_Character__Cur_Mana_x                                   0x4D9640
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE9B0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2450
#define EQ_Character__GetFocusRangeModifier_x                      0x4B25A0
#define EQ_Character__GetHPRegen_x                                 0x4DF410
#define EQ_Character__GetEnduranceRegen_x                          0x4DFA10
#define EQ_Character__GetManaRegen_x                               0x4DFE50
#define EQ_Character__Max_Endurance_x                              0x646DB0
#define EQ_Character__Max_HP_x                                     0x4D1D20
#define EQ_Character__Max_Mana_x                                   0x646BB0
#define EQ_Character__doCombatAbility_x                            0x649210
#define EQ_Character__UseSkill_x                                   0x4E1C30
#define EQ_Character__GetConLevel_x                                0x63FBD0
#define EQ_Character__IsExpansionFlag_x                            0x5A4070
#define EQ_Character__TotalEffect_x                                0x4C53F0
#define EQ_Character__GetPCSpellAffect_x                           0x4BF700
#define EQ_Character__SpellDuration_x                              0x4BF230
#define EQ_Character__GetAdjustedSkill_x                           0x4D4C70
#define EQ_Character__GetBaseSkill_x                               0x4D5C10
#define EQ_Character__CanUseItem_x                                 0x4D9950

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C76D0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x65D2A0

//PcClient
#define PcClient__PcClient_x                                       0x63D300

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B95B0
#define CCharacterListWnd__EnterWorld_x                            0x4B8FF0
#define CCharacterListWnd__Quit_x                                  0x4B8D40
#define CCharacterListWnd__UpdateList_x                            0x4B9180

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x621D00
#define EQ_Item__CreateItemTagString_x                             0x8A1970
#define EQ_Item__IsStackable_x                                     0x8A64F0
#define EQ_Item__GetImageNum_x                                     0x8A3400
#define EQ_Item__CreateItemClient_x                                0x620EC0
#define EQ_Item__GetItemValue_x                                    0x8A46E0
#define EQ_Item__ValueSellMerchant_x                               0x8A7D20
#define EQ_Item__IsKeyRingItem_x                                   0x8A5DF0
#define EQ_Item__CanGoInBag_x                                      0x621E20
#define EQ_Item__IsEmpty_x                                         0x8A5940
#define EQ_Item__GetMaxItemCount_x                                 0x8A4B00
#define EQ_Item__GetHeldItem_x                                     0x8A32D0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A12E0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x557FF0
#define EQ_LoadingS__Array_x                                       0xC24B58

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x647710
#define EQ_PC__GetAlternateAbilityId_x                             0x8B0F50
#define EQ_PC__GetCombatAbility_x                                  0x8B15C0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B1630
#define EQ_PC__GetItemRecastTimer_x                                0x649790
#define EQ_PC__HasLoreItem_x                                       0x640390
#define EQ_PC__AlertInventoryChanged_x                             0x63F500
#define EQ_PC__GetPcZoneClient_x                                   0x66BDF0
#define EQ_PC__RemoveMyAffect_x                                    0x64C9D0
#define EQ_PC__GetKeyRingItems_x                                   0x8B1EC0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B1C50
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B21C0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AA5D0
#define EQItemList__add_object_x                                   0x5D7530
#define EQItemList__add_item_x                                     0x5AAB30
#define EQItemList__delete_item_x                                  0x5AAB80
#define EQItemList__FreeItemList_x                                 0x5AAA80

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x536380

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x65EB20
#define EQPlayer__dEQPlayer_x                                      0x651E90
#define EQPlayer__DoAttack_x                                       0x666AA0
#define EQPlayer__EQPlayer_x                                       0x652550
#define EQPlayer__SetNameSpriteState_x                             0x656810
#define EQPlayer__SetNameSpriteTint_x                              0x6576E0
#define PlayerBase__HasProperty_j_x                                0x9983E0
#define EQPlayer__IsTargetable_x                                   0x998880
#define EQPlayer__CanSee_x                                         0x9986E0
#define EQPlayer__CanSee1_x                                        0x9987B0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9984A0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x669880
#define PlayerZoneClient__GetLevel_x                               0x66BE30
#define PlayerZoneClient__IsValidTeleport_x                        0x5D86A0
#define PlayerZoneClient__LegalPlayerRace_x                        0x551220

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x661910
#define EQPlayerManager__GetSpawnByName_x                          0x6619C0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x661A50

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x625340
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6253C0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x625400
#define KeypressHandler__ClearCommandStateArray_x                  0x626810
#define KeypressHandler__HandleKeyDown_x                           0x626830
#define KeypressHandler__HandleKeyUp_x                             0x6268D0
#define KeypressHandler__SaveKeymapping_x                          0x626D20

// MapViewMap 
#define MapViewMap__Clear_x                                        0x77DC70
#define MapViewMap__SaveEx_x                                       0x781030
#define MapViewMap__SetZoom_x                                      0x7856F0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C55F0

// StringTable 
#define StringTable__getString_x                                   0x8C0270

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64C640
#define PcZoneClient__RemovePetEffect_x                            0x64CC70
#define PcZoneClient__HasAlternateAbility_x                        0x6469E0
#define PcZoneClient__GetCurrentMod_x                              0x4E4CF0
#define PcZoneClient__GetModCap_x                                  0x4E4BF0
#define PcZoneClient__CanEquipItem_x                               0x6470B0
#define PcZoneClient__GetItemByID_x                                0x649C10
#define PcZoneClient__GetItemByItemClass_x                         0x649D60
#define PcZoneClient__RemoveBuffEffect_x                           0x64CC90
#define PcZoneClient__BandolierSwap_x                              0x647CD0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x649730

//Doors
#define EQSwitch__UseSwitch_x                                      0x5DD210

//IconCache
#define IconCache__GetIcon_x                                       0x71DE10

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7158E0
#define CContainerMgr__CloseContainer_x                            0x715BB0
#define CContainerMgr__OpenExperimentContainer_x                   0x716630

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D5E00

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x619E40

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7740A0
#define CLootWnd__RequestLootSlot_x                                0x7732D0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x576D10
#define EQ_Spell__SpellAffects_x                                   0x577180
#define EQ_Spell__SpellAffectBase_x                                0x576F40
#define EQ_Spell__IsStackable_x                                    0x4C9930
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C97E0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6900
#define EQ_Spell__IsSPAStacking_x                                  0x577FD0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5774E0
#define EQ_Spell__IsNoRemove_x                                     0x4C9910
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x577FE0
#define __IsResEffectSpell_x                                       0x4C8E30

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACFA0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8CFC20

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81CD80
#define CTargetWnd__WndNotification_x                              0x81C610
#define CTargetWnd__RefreshTargetBuffs_x                           0x81C8E0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81B780

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x821380

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x533DB0
#define CTaskManager__HandleMessage_x                              0x532240
#define CTaskManager__GetTaskStatus_x                              0x533E60
#define CTaskManager__GetElementDescription_x                      0x533EE0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x572280
#define EqSoundManager__PlayScriptMp3_x                            0x5723E0
#define EqSoundManager__SoundAssistPlay_x                          0x683F40
#define EqSoundManager__WaveInstancePlay_x                         0x6834B0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x527AB0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x954070

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x55F970
#define CAltAbilityData__GetMercMaxRank_x                          0x55F900
#define CAltAbilityData__GetMaxRank_x                              0x555080

//CTargetRing
#define CTargetRing__Cast_x                                        0x617F60

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C97C0
#define CharacterBase__CreateItemGlobalIndex_x                     0x50F330
#define CharacterBase__CreateItemIndex_x                           0x620050
#define CharacterBase__GetItemPossession_x                         0x4FB160
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D8230
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D8290
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FCA80
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FD2B0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FD360

//messages
#define msg_spell_worn_off_x                                       0x59C1D0
#define msg_new_text_x                                             0x590F60
#define __msgTokenTextParam_x                                      0x59E700
#define msgTokenText_x                                             0x59E950

//SpellManager
#define SpellManager__vftable_x                                    0xAEA234
#define SpellManager__SpellManager_x                               0x687270
#define Spellmanager__LoadTextSpells_x                             0x687B60
#define SpellManager__GetSpellByGroupAndRank_x                     0x687440

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99C2D0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x50F980
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A24B0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x638AE0
#define ItemGlobalIndex__IsValidIndex_x                            0x50F9E0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D05C0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D0840

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76C910

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71A010
#define CCursorAttachment__AttachToCursor1_x                       0x71A050
#define CCursorAttachment__Deactivate_x                            0x71B040

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x946D00
#define CSidlManagerBase__CreatePageWnd_x                          0x946510
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9427C0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x942750

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x963CB0
#define CEQSuiteTextureLoader__GetTexture_x                        0x963970

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50C900
#define CFindItemWnd__WndNotification_x                            0x50D3E0
#define CFindItemWnd__Update_x                                     0x50DF20
#define CFindItemWnd__PickupSelectedItem_x                         0x50C140

//IString
#define IString__Append_x                                          0x4FC980

//Camera
#define CDisplay__cameraType_x                                     0xDFE51C
#define EverQuest__Cameras_x                                       0xEC1A54

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x515010
#define LootFiltersManager__GetItemFilterData_x                    0x514920
#define LootFiltersManager__RemoveItemLootFilter_x                 0x514950
#define LootFiltersManager__SetItemLootFilter_x                    0x514B70

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C3DE0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A1EC0
#define CResolutionHandler__GetWindowedStyle_x                     0x67EB00

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7126B0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E4A40
#define CDistillerInfo__Instance_x                                 0x8E49E0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x732980
#define CGroupWnd__UpdateDisplay_x                                 0x731CD0

//ItemBase
#define ItemBase__IsLore_x                                         0x8A5E90
#define ItemBase__IsLoreEquipped_x                                 0x8A5F10

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D7490
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D75D0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D7630

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x674510
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x677E90

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x502D10

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F18C0
#define FactionManagerClient__HandleFactionMessage_x               0x4F1F30
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F24F0
#define FactionManagerClient__GetMaxFaction_x                      0x4F250F
#define FactionManagerClient__GetMinFaction_x                      0x4F24C0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FB130

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92B290

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BDA0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FB390

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x55EE30

//CTargetManager
#define CTargetManager__Get_x                                      0x68AAB0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x674510

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8C70

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AAA20

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF5F0E8

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
