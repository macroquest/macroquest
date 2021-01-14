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
#define __ExpectedVersionDate                                     "Jan 12 2021"
#define __ExpectedVersionTime                                     "12:07:13"
#define __ActualVersionDate_x                                      0xAEC0FC
#define __ActualVersionTime_x                                      0xAEC0F0
#define __ActualVersionBuild_x                                     0xADA43C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x640F50
#define __MemChecker1_x                                            0x8EE740
#define __MemChecker2_x                                            0x6B0060
#define __MemChecker3_x                                            0x6AFFB0
#define __MemChecker4_x                                            0x847590
#define __EncryptPad0_x                                            0xC1F4E0
#define __EncryptPad1_x                                            0xC7BEF0
#define __EncryptPad2_x                                            0xC2EA50
#define __EncryptPad3_x                                            0xC2E650
#define __EncryptPad4_x                                            0xC6C488
#define __EncryptPad5_x                                            0xF3E8A8
#define __AC1_x                                                    0x806026
#define __AC2_x                                                    0x5FB08F
#define __AC3_x                                                    0x6026E0
#define __AC4_x                                                    0x606690
#define __AC5_x                                                    0x60C97F
#define __AC6_x                                                    0x610E26
#define __AC7_x                                                    0x5FAB00
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1F3448

// Direct Input
#define DI8__Main_x                                                0xF3E8D0
#define DI8__Keyboard_x                                            0xF3E8D4
#define DI8__Mouse_x                                               0xF3E8B4
#define DI8__Mouse_Copy_x                                          0xE974B4
#define DI8__Mouse_Check_x                                         0xF3C3FC
#define __AutoSkillArray_x                                         0xE983D0
#define __Attack_x                                                 0xF361FF
#define __Autofire_x                                               0xF36200
#define __BindList_x                                               0xC0E3F8
#define g_eqCommandStates_x                                        0xC0F178
#define __Clicks_x                                                 0xE9756C
#define __CommandList_x                                            0xC0FD38
#define __CurrentMapLabel_x                                        0xF4E8C4
#define __CurrentSocial_x                                          0xBF77D4
#define __DoAbilityList_x                                          0xECDD20
#define __do_loot_x                                                0x5C6C50
#define __DrawHandler_x                                            0x15CD6B8
#define __GroupCount_x                                             0xE8FFBA
#define __Guilds_x                                                 0xE963F0
#define __gWorld_x                                                 0xE90778
#define __HWnd_x                                                   0xF3E8B8
#define __heqmain_x                                                0xF3E890
#define __InChatMode_x                                             0xE9749C
#define __LastTell_x                                               0xE9941C
#define __LMouseHeldTime_x                                         0xE975D8
#define __Mouse_x                                                  0xF3E8BC
#define __MouseLook_x                                              0xE97532
#define __MouseEventTime_x                                         0xF36C3C
#define __gpbCommandEvent_x                                        0xE90224
#define __NetStatusToggle_x                                        0xE97535
#define __PCNames_x                                                0xE989CC
#define __RangeAttackReady_x                                       0xE986B4
#define __RMouseHeldTime_x                                         0xE975D4
#define __RunWalkState_x                                           0xE974A0
#define __ScreenMode_x                                             0xDDDF64
#define __ScreenX_x                                                0xE97454
#define __ScreenY_x                                                0xE97450
#define __ScreenXMax_x                                             0xE97458
#define __ScreenYMax_x                                             0xE9745C
#define __ServerHost_x                                             0xE903F3
#define __ServerName_x                                             0xECDCE0
#define __ShiftKeyDown_x                                           0xE97B30
#define __ShowNames_x                                              0xE98870
#define EverQuestInfo__bSocialChanged_x                            0xECDD68
#define __Socials_x                                                0xECDDE0
#define __SubscriptionType_x                                       0xF92988
#define __TargetAggroHolder_x                                      0xF51278
#define __ZoneType_x                                               0xE97930
#define __GroupAggro_x                                             0xF512B8
#define __LoginName_x                                              0xF3C08C
#define __Inviter_x                                                0xF3617C
#define __AttackOnAssist_x                                         0xE9882C
#define __UseTellWindows_x                                         0xE98B64
#define __gfMaxZoomCameraDistance_x                                0xAE4010
#define __gfMaxCameraDistance_x                                    0xB0C740
#define __pulAutoRun_x                                             0xE97550
#define __pulForward_x                                             0xE98B9C
#define __pulBackward_x                                            0xE98BA0
#define __pulTurnRight_x                                           0xE98BA4
#define __pulTurnLeft_x                                            0xE98BA8
#define __pulStrafeLeft_x                                          0xE98BAC
#define __pulStrafeRight_x                                         0xE98BB0

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE92788
#define instEQZoneInfo_x                                           0xE97728
#define pinstActiveBanker_x                                        0xE90714
#define pinstActiveCorpse_x                                        0xE9070C
#define pinstActiveGMaster_x                                       0xE90710
#define pinstActiveMerchant_x                                      0xE90708
#define pinstAltAdvManager_x                                       0xDDE9C0
#define pinstBandageTarget_x                                       0xE90724
#define pinstCamActor_x                                            0xDDDF54
#define pinstCDBStr_x                                              0xDDD6DC
#define pinstCDisplay_x                                            0xE90780
#define pinstCEverQuest_x                                          0xF3B950
#define pinstEverQuestInfo_x                                       0xE97448
#define pinstCharData_x                                            0xE901A8
#define pinstCharSpawn_x                                           0xE9075C
#define pinstControlledMissile_x                                   0xE9076C
#define pinstControlledPlayer_x                                    0xE9075C
#define pinstCResolutionHandler_x                                  0x15CD8E8
#define pinstCSidlManager_x                                        0x15CC880
#define pinstCXWndManager_x                                        0x15CC87C
#define instDynamicZone_x                                          0xE962C8
#define pinstDZMember_x                                            0xE963D8
#define pinstDZTimerInfo_x                                         0xE963DC
#define pinstEqLogin_x                                             0xF3B9D8
#define instEQMisc_x                                               0xDDD620
#define pinstEQSoundManager_x                                      0xDDF990
#define pinstEQSpellStrings_x                                      0xC9FF18
#define instExpeditionLeader_x                                     0xE96312
#define instExpeditionName_x                                       0xE96352
#define pinstGroup_x                                               0xE8FFB6
#define pinstImeManager_x                                          0x15CC878
#define pinstLocalPlayer_x                                         0xE90704
#define pinstMercenaryData_x                                       0xF38730
#define pinstMercenaryStats_x                                      0xF51344
#define pinstModelPlayer_x                                         0xE9071C
#define pinstPCData_x                                              0xE901A8
#define pinstSkillMgr_x                                            0xF3A878
#define pinstSpawnManager_x                                        0xF39320
#define pinstSpellManager_x                                        0xF3AAB8
#define pinstSpellSets_x                                           0xF2EE28
#define pinstStringTable_x                                         0xE901B0
#define pinstSwitchManager_x                                       0xE8FD28
#define pinstTarget_x                                              0xE90758
#define pinstTargetObject_x                                        0xE90764
#define pinstTargetSwitch_x                                        0xE90774
#define pinstTaskMember_x                                          0xDDD4B0
#define pinstTrackTarget_x                                         0xE90760
#define pinstTradeTarget_x                                         0xE90718
#define instTributeActive_x                                        0xDDD641
#define pinstViewActor_x                                           0xDDDF50
#define pinstWorldData_x                                           0xE8FE7C
#define pinstZoneAddr_x                                            0xE979C8
#define pinstPlayerPath_x                                          0xF393B8
#define pinstTargetIndicator_x                                     0xF3AD20
#define EQObject_Top_x                                             0xE904FC
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDDD998
#define pinstCAchievementsWnd_x                                    0xDDDEAC
#define pinstCActionsWnd_x                                         0xDDD9D4
#define pinstCAdvancedDisplayOptionsWindow_x                       0xDDDF58
#define pinstCAdvancedLootWnd_x                                    0xDDDF00
#define pinstCAdventureLeaderboardWnd_x                            0xF480E8
#define pinstCAdventureRequestWnd_x                                0xF48198
#define pinstCAdventureStatsWnd_x                                  0xF48248
#define pinstCAggroMeterWnd_x                                      0xDDDF38
#define pinstCAlarmWnd_x                                           0xDDDED8
#define pinstCAlertHistoryWnd_x                                    0xDDDFCC
#define pinstCAlertStackWnd_x                                      0xDDDF10
#define pinstCAlertWnd_x                                           0xDDDF34
#define pinstCAltStorageWnd_x                                      0xF485A8
#define pinstCAudioTriggersWindow_x                                0xC92248
#define pinstCAuraWnd_x                                            0xDDDF04
#define pinstCAvaZoneWnd_x                                         0xDDDFD0
#define pinstCBandolierWnd_x                                       0xDDDF4C
#define pinstCBankWnd_x                                            0xDDDFA0
#define pinstCBarterMerchantWnd_x                                  0xF497E8
#define pinstCBarterSearchWnd_x                                    0xF49898
#define pinstCBarterWnd_x                                          0xF49948
#define pinstCBazaarConfirmationWnd_x                              0xDDDEE8
#define pinstCBazaarSearchWnd_x                                    0xDDD99C
#define pinstCBazaarWnd_x                                          0xDDDEB8
#define pinstCBlockedBuffWnd_x                                     0xDDDF1C
#define pinstCBlockedPetBuffWnd_x                                  0xDDDF48
#define pinstCBodyTintWnd_x                                        0xDDDE5C
#define pinstCBookWnd_x                                            0xDDDF94
#define pinstCBreathWnd_x                                          0xDDD9C8
#define pinstCBuffWindowNORMAL_x                                   0xDDDEF8
#define pinstCBuffWindowSHORT_x                                    0xDDDEFC
#define pinstCBugReportWnd_x                                       0xDDDF98
#define pinstCButtonWnd_x                                          0x15CCAE8
#define pinstCCastingWnd_x                                         0xDDDF8C
#define pinstCCastSpellWnd_x                                       0xDDD9A4
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDDDE68
#define pinstCChatWindowManager_x                                  0xF4A3F0
#define pinstCClaimWnd_x                                           0xF4A548
#define pinstCColorPickerWnd_x                                     0xDDDFFC
#define pinstCCombatAbilityWnd_x                                   0xDDDEC8
#define pinstCCombatSkillsSelectWnd_x                              0xDDDE84
#define pinstCCompassWnd_x                                         0xDDDA4C
#define pinstCConfirmationDialog_x                                 0xF4F410
#define pinstCContainerMgr_x                                       0xDDDE74
#define pinstCContextMenuManager_x                                 0x15CC838
#define pinstCCursorAttachment_x                                   0xDDDF7C
#define pinstCDynamicZoneWnd_x                                     0xF4AB10
#define pinstCEditLabelWnd_x                                       0xDDDEF4
#define pinstCEQMainWnd_x                                          0xF4AD58
#define pinstCEventCalendarWnd_x                                   0xDDD994
#define pinstCExtendedTargetWnd_x                                  0xDDDF18
#define pinstCPlayerCustomizationWnd_x                             0xDDDE88
#define pinstCFactionWnd_x                                         0xDDDEA8
#define pinstCFellowshipWnd_x                                      0xF4AF58
#define pinstCFileSelectionWnd_x                                   0xDDDFF0
#define pinstCFindItemWnd_x                                        0xDDDE94
#define pinstCFindLocationWnd_x                                    0xF4B0B0
#define pinstCFriendsWnd_x                                         0xDDDE98
#define pinstCGemsGameWnd_x                                        0xDDDEA4
#define pinstCGiveWnd_x                                            0xDDDEDC
#define pinstCGroupSearchFiltersWnd_x                              0xDDDF70
#define pinstCGroupSearchWnd_x                                     0xF4B4A8
#define pinstCGroupWnd_x                                           0xF4B558
#define pinstCGuildBankWnd_x                                       0xF4B608
#define pinstCGuildCreationWnd_x                                   0xF4B6B8
#define pinstCGuildMgmtWnd_x                                       0xF4B768
#define pinstCharacterCreation_x                                   0xDDDE8C
#define pinstCHelpWnd_x                                            0xDDDEE0
#define pinstCHeritageSelectionWnd_x                               0xDDDE9C
#define pinstCHotButtonWnd_x                                       0xF4D8C0
#define pinstCHotButtonWnd1_x                                      0xF4D8C0
#define pinstCHotButtonWnd2_x                                      0xF4D8C4
#define pinstCHotButtonWnd3_x                                      0xF4D8C8
#define pinstCHotButtonWnd4_x                                      0xF4D8CC
#define pinstCIconSelectionWnd_x                                   0xDDDF78
#define pinstCInspectWnd_x                                         0xDDDF44
#define pinstCInventoryWnd_x                                       0xDDDF08
#define pinstCInvSlotMgr_x                                         0xDDD9AC
#define pinstCItemDisplayManager_x                                 0xF4DE18
#define pinstCItemExpTransferWnd_x                                 0xF4DF48
#define pinstCItemOverflowWnd_x                                    0xDDD9A0
#define pinstCJournalCatWnd_x                                      0xDDD778
#define pinstCJournalNPCWnd_x                                      0xDDDFC8
#define pinstCJournalTextWnd_x                                     0xDDDFC8
#define pinstCKeyRingWnd_x                                         0xDDDF84
#define pinstCLargeDialogWnd_x                                     0xF50090
#define pinstCLayoutCopyWnd_x                                      0xF4E298
#define pinstCLFGuildWnd_x                                         0xF4E348
#define pinstCLoadskinWnd_x                                        0xDDDEBC
#define pinstCLootFiltersCopyWnd_x                                 0xCAE9B8
#define pinstCLootFiltersWnd_x                                     0xDDDF20
#define pinstCLootSettingsWnd_x                                    0xDDDF3C
#define pinstCLootWnd_x                                            0xDDD77C
#define pinstCMailAddressBookWnd_x                                 0xDDD98C
#define pinstCMailCompositionWnd_x                                 0xDDE010
#define pinstCMailIgnoreListWnd_x                                  0xDDD990
#define pinstCMailWnd_x                                            0xDDDFE8
#define pinstCManageLootWnd_x                                      0xDDEE70
#define pinstCMapToolbarWnd_x                                      0xDDDEE4
#define pinstCMapViewWnd_x                                         0xDDDEB4
#define pinstCMarketplaceWnd_x                                     0xDDDF24
#define pinstCMerchantWnd_x                                        0xDDD988
#define pinstCMIZoneSelectWnd_x                                    0xF4EB80
#define pinstCMusicPlayerWnd_x                                     0xDDDFB0
#define pinstCNameChangeMercWnd_x                                  0xDDDED4
#define pinstCNameChangePetWnd_x                                   0xDDDEB0
#define pinstCNameChangeWnd_x                                      0xDDDEF0
#define pinstCNoteWnd_x                                            0xDDDEC0
#define pinstCObjectPreviewWnd_x                                   0xDDDF40
#define pinstCOptionsWnd_x                                         0xDDDED0
#define pinstCPetInfoWnd_x                                         0xDDDFE0
#define pinstCPetitionQWnd_x                                       0xDDDE7C
#define pinstCPlayerNotesWnd_x                                     0xDDDE60
#define pinstCPlayerWnd_x                                          0xDDDFEC
#define pinstCPopupWndManager_x                                    0xF4F410
#define pinstCProgressionSelectionWnd_x                            0xF4F4C0
#define pinstCPurchaseGroupWnd_x                                   0xDDDFA8
#define pinstCPurchaseWnd_x                                        0xDDDF88
#define pinstCPvPLeaderboardWnd_x                                  0xF4F570
#define pinstCPvPStatsWnd_x                                        0xF4F620
#define pinstCQuantityWnd_x                                        0xDDDFC0
#define pinstCRaceChangeWnd_x                                      0xDDDF0C
#define pinstCRaidOptionsWnd_x                                     0xDDDF74
#define pinstCRaidWnd_x                                            0xDDD984
#define pinstCRealEstateItemsWnd_x                                 0xDDDEA0
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDDDA50
#define pinstCRealEstateManageWnd_x                                0xDDDFAC
#define pinstCRealEstateNeighborhoodWnd_x                          0xDDDFC4
#define pinstCRealEstatePlotSearchWnd_x                            0xDDDFE4
#define pinstCRealEstatePurchaseWnd_x                              0xDDE008
#define pinstCRespawnWnd_x                                         0xDDDF30
#define pinstCRewardSelectionWnd_x                                 0xF4FD68
#define pinstCSelectorWnd_x                                        0xDDDE78
#define pinstCSendMoneyWnd_x                                       0xDDDEEC
#define pinstCServerListWnd_x                                      0xDDD980
#define pinstCSkillsSelectWnd_x                                    0xDDDE70
#define pinstCSkillsWnd_x                                          0xDDDE58
#define pinstCSocialEditWnd_x                                      0xDDDF80
#define pinstCSocialWnd_x                                          0xDDDECC
#define pinstCSpellBookWnd_x                                       0xDDDEC4
#define pinstCStoryWnd_x                                           0xDDD9D0
#define pinstCTargetOfTargetWnd_x                                  0xF513C8
#define pinstCTargetWnd_x                                          0xDDDF2C
#define pinstCTaskOverlayWnd_x                                     0xDDDF9C
#define pinstCTaskSelectWnd_x                                      0xF51520
#define pinstCTaskManager_x                                        0xCAF2F8
#define pinstCTaskTemplateSelectWnd_x                              0xF515D0
#define pinstCTaskWnd_x                                            0xF51680
#define pinstCTextEntryWnd_x                                       0xDDDF90
#define pinstCTimeLeftWnd_x                                        0xDDDE6C
#define pinstCTipWndCONTEXT_x                                      0xF51884
#define pinstCTipWndOFDAY_x                                        0xF51880
#define pinstCTitleWnd_x                                           0xF51930
#define pinstCTrackingWnd_x                                        0xDDDF14
#define pinstCTradeskillWnd_x                                      0xF51A98
#define pinstCTradeWnd_x                                           0xDDDE64
#define pinstCTrainWnd_x                                           0xDDE00C
#define pinstCTributeBenefitWnd_x                                  0xF51C98
#define pinstCTributeMasterWnd_x                                   0xF51D48
#define pinstCTributeTrophyWnd_x                                   0xF51DF8
#define pinstCVideoModesWnd_x                                      0xDDE004
#define pinstCVoiceMacroWnd_x                                      0xF3B2D8
#define pinstCVoteResultsWnd_x                                     0xDDDE90
#define pinstCVoteWnd_x                                            0xDDDE80
#define pinstCZoneGuideWnd_x                                       0xDDDFA4
#define pinstCZonePathWnd_x                                        0xDDDFB8

#define pinstEQSuiteTextureLoader_x                                0xC7C810
#define pinstItemIconCache_x                                       0xF4AD10
#define pinstLootFiltersManager_x                                  0xCAEA68
#define pinstRewardSelectionWnd_x                                  0xF4FD68

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C2340
#define __CastRay2_x                                               0x5C2390
#define __ConvertItemTags_x                                        0x5DE040
#define __CleanItemTags_x                                          0x47B380
#define __DoesFileExist_x                                          0x8F17C0
#define __EQGetTime_x                                              0x8EE370
#define __ExecuteCmd_x                                             0x5BACF0
#define __FixHeading_x                                             0x982EC0
#define __FlushDxKeyboard_x                                        0x6ABF00
#define __GameLoop_x                                               0x6AF230
#define __get_bearing_x                                            0x5C1EA0
#define __get_melee_range_x                                        0x5C2580
#define __GetAnimationCache_x                                      0x714610
#define __GetGaugeValueFromEQ_x                                    0x8045C0
#define __GetLabelFromEQ_x                                         0x805FB0
#define __GetXTargetType_x                                         0x9848A0
#define __HandleMouseWheel_x                                       0x6B0110
#define __HeadingDiff_x                                            0x982F30
#define __HelpPath_x                                               0xF368D4
#define __LoadFrontEnd_x                                           0x6AC540
#define __NewUIINI_x                                               0x804290
#define __ProcessGameEvents_x                                      0x622E00
#define __ProcessMouseEvent_x                                      0x622590
#define __SaveColors_x                                             0x55BA70
#define __STMLToText_x                                             0x926900
#define __ToggleKeyRingItem_x                                      0x51A380
#define CMemoryMappedFile__SetFile_x                               0xA72110
#define CrashDetected_x                                            0x6ADFF0
#define DrawNetStatus_x                                            0x64E420
#define Expansion_HoT_x                                            0xE98818
#define Teleport_Table_Size_x                                      0xE902B0
#define Teleport_Table_x                                           0xE90788
#define Util__FastTime_x                                           0x8EDF40
#define __CopyLayout_x                                             0x63C670
#define __WndProc_x                                                0x6AE4F0
#define __ProcessKeyboardEvent_x                                   0x6ADA90

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48E140
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x497130
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x496F00
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4916D0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x490B20

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x563D10
#define AltAdvManager__IsAbilityReady_x                            0x562AB0
#define AltAdvManager__GetAAById_x                                 0x562E40
#define AltAdvManager__CanTrainAbility_x                           0x562EB0
#define AltAdvManager__CanSeeAbility_x                             0x563210

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C8CD0
#define CharacterZoneClient__HasSkill_x                            0x4D3B50
#define CharacterZoneClient__MakeMeVisible_x                       0x4D5260
#define CharacterZoneClient__IsStackBlocked_x                      0x4C0410
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B98B0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D7C10
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D7CF0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D7DD0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2500
#define CharacterZoneClient__BardCastBard_x                        0x4C4F30
#define CharacterZoneClient__GetMaxEffects_x                       0x4BD2C0
#define CharacterZoneClient__GetEffect_x                           0x4B97F0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3570
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3640
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3690
#define CharacterZoneClient__CalcAffectChange_x                    0x4C37E0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C39C0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B1800
#define CharacterZoneClient__FindItemByGuid_x                      0x4D61C0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D5C40

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D5CE0
#define CBankWnd__WndNotification_x                                0x6D5AB0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E3490

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x9240F0
#define CButtonWnd__CButtonWnd_x                                   0x922D00

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x703790
#define CChatManager__InitContextMenu_x                            0x6FC8C0
#define CChatManager__FreeChatWindow_x                             0x7022D0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E7750
#define CChatManager__SetLockedActiveChatWindow_x                  0x703410
#define CChatManager__CreateChatWindow_x                           0x702910

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E7870

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9372C0
#define CContextMenu__dCContextMenu_x                              0x937500
#define CContextMenu__AddMenuItem_x                                0x937510
#define CContextMenu__RemoveMenuItem_x                             0x937820
#define CContextMenu__RemoveAllMenuItems_x                         0x937840
#define CContextMenu__CheckMenuItem_x                              0x9378C0
#define CContextMenu__SetMenuItem_x                                0x937740
#define CContextMenu__AddSeparator_x                               0x9376A0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x937E60
#define CContextMenuManager__RemoveMenu_x                          0x937ED0
#define CContextMenuManager__PopupMenu_x                           0x937F90
#define CContextMenuManager__Flush_x                               0x937E00
#define CContextMenuManager__GetMenu_x                             0x4993D0
#define CContextMenuManager__CreateDefaultMenu_x                   0x70EF80

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8C90A0
#define CChatService__GetFriendName_x                              0x8C90B0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x704000
#define CChatWindow__Clear_x                                       0x7052C0
#define CChatWindow__WndNotification_x                             0x705A50
#define CChatWindow__AddHistory_x                                  0x704B80

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x934700
#define CComboWnd__Draw_x                                          0x933BF0
#define CComboWnd__GetCurChoice_x                                  0x934540
#define CComboWnd__GetListRect_x                                   0x9340A0
#define CComboWnd__GetTextRect_x                                   0x934770
#define CComboWnd__InsertChoice_x                                  0x934230
#define CComboWnd__SetColors_x                                     0x934200
#define CComboWnd__SetChoice_x                                     0x934510
#define CComboWnd__GetItemCount_x                                  0x934550
#define CComboWnd__GetCurChoiceText_x                              0x934590
#define CComboWnd__GetChoiceText_x                                 0x934560
#define CComboWnd__InsertChoiceAtIndex_x                           0x9342D0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70C9A0
#define CContainerWnd__vftable_x                                   0xAF5304
#define CContainerWnd__SetContainer_x                              0x70DEF0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x556400
#define CDisplay__PreZoneMainUI_x                                  0x556410
#define CDisplay__CleanGameUI_x                                    0x55B850
#define CDisplay__GetClickedActor_x                                0x54E890
#define CDisplay__GetUserDefinedColor_x                            0x546F10
#define CDisplay__GetWorldFilePath_x                               0x550300
#define CDisplay__is3dON_x                                         0x54B4F0
#define CDisplay__ReloadUI_x                                       0x555940
#define CDisplay__WriteTextHD2_x                                   0x54B2E0
#define CDisplay__TrueDistance_x                                   0x551FC0
#define CDisplay__SetViewActor_x                                   0x54E1B0
#define CDisplay__GetFloorHeight_x                                 0x54B5B0
#define CDisplay__SetRenderWindow_x                                0x549F30
#define CDisplay__ToggleScreenshotMode_x                           0x54DC80

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x956E60

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x93A7B0
#define CEditWnd__EnsureCaretVisible_x                             0x93C940
#define CEditWnd__GetCaretPt_x                                     0x93B920
#define CEditWnd__GetCharIndexPt_x                                 0x93B6D0
#define CEditWnd__GetDisplayString_x                               0x93B580
#define CEditWnd__GetHorzOffset_x                                  0x939E60
#define CEditWnd__GetLineForPrintableChar_x                        0x93C840
#define CEditWnd__GetSelStartPt_x                                  0x93B980
#define CEditWnd__GetSTMLSafeText_x                                0x93B3A0
#define CEditWnd__PointFromPrintableChar_x                         0x93C480
#define CEditWnd__SelectableCharFromPoint_x                        0x93C5F0
#define CEditWnd__SetEditable_x                                    0x93BA40
#define CEditWnd__SetWindowTextA_x                                 0x93B120
#define CEditWnd__ReplaceSelection_x                               0x93C100
#define CEditWnd__ReplaceSelection1_x                              0x93C080

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x610300
#define CEverQuest__ClickedPlayer_x                                0x6024C0
#define CEverQuest__CreateTargetIndicator_x                        0x61FF70
#define CEverQuest__DeleteTargetIndicator_x                        0x620000
#define CEverQuest__DoTellWindow_x                                 0x4E7950
#define CEverQuest__OutputTextToLog_x                              0x4E7C20
#define CEverQuest__DropHeldItemOnGround_x                         0x5F7610
#define CEverQuest__dsp_chat_x                                     0x4E7FB0
#define CEverQuest__trimName_x                                     0x61C120
#define CEverQuest__Emote_x                                        0x610B60
#define CEverQuest__EnterZone_x                                    0x60AC80
#define CEverQuest__GetBodyTypeDesc_x                              0x6155B0
#define CEverQuest__GetClassDesc_x                                 0x615BF0
#define CEverQuest__GetClassThreeLetterCode_x                      0x6161F0
#define CEverQuest__GetDeityDesc_x                                 0x61E7C0
#define CEverQuest__GetLangDesc_x                                  0x6163B0
#define CEverQuest__GetRaceDesc_x                                  0x615BD0
#define CEverQuest__InterpretCmd_x                                 0x61ED90
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FB7B0
#define CEverQuest__LMouseUp_x                                     0x5F9B30
#define CEverQuest__RightClickedOnPlayer_x                         0x5FC090
#define CEverQuest__RMouseUp_x                                     0x5FAAC0
#define CEverQuest__SetGameState_x                                 0x5F73A0
#define CEverQuest__UPCNotificationFlush_x                         0x61C020
#define CEverQuest__IssuePetCommand_x                              0x6177C0
#define CEverQuest__ReportSuccessfulHit_x                          0x611EB0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x71E560
#define CGaugeWnd__CalcLinesFillRect_x                             0x71E5C0
#define CGaugeWnd__Draw_x                                          0x71DBF0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ADAD0
#define CGuild__GetGuildName_x                                     0x4AC580
#define CGuild__GetGuildIndex_x                                    0x4ACB80

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x738170

//CHotButton
#define CHotButton__SetCheck_x                                     0x631660
#define CHotButton__SetButtonSize_x                                0x631A20

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x743B00
#define CInvSlotMgr__MoveItem_x                                    0x742810
#define CInvSlotMgr__SelectSlot_x                                  0x743BD0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x741000
#define CInvSlot__SliderComplete_x                                 0x73ED30
#define CInvSlot__GetItemBase_x                                    0x73E6B0
#define CInvSlot__UpdateItem_x                                     0x73E820

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x745660
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7447F0
#define CInvSlotWnd__HandleLButtonUp_x                             0x7451E0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7FF970
#define CItemDisplayWnd__UpdateStrings_x                           0x753E30
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x74DB00
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x74E020
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x754440
#define CItemDisplayWnd__AboutToShow_x                             0x753A80
#define CItemDisplayWnd__WndNotification_x                         0x755690
#define CItemDisplayWnd__RequestConvertItem_x                      0x754FE0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x752AF0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7538A0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x830170

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x759BD0

// CLabel 
#define CLabel__Draw_x                                             0x75F680

// CListWnd
#define CListWnd__CListWnd_x                                       0x90CF40
#define CListWnd__dCListWnd_x                                      0x90D260
#define CListWnd__AddColumn_x                                      0x9116D0
#define CListWnd__AddColumn1_x                                     0x911720
#define CListWnd__AddLine_x                                        0x911AB0
#define CListWnd__AddString_x                                      0x9118B0
#define CListWnd__CalculateFirstVisibleLine_x                      0x9114A0
#define CListWnd__CalculateVSBRange_x                              0x911280
#define CListWnd__ClearSel_x                                       0x912290
#define CListWnd__ClearAllSel_x                                    0x9122F0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x912CE0
#define CListWnd__Compare_x                                        0x910BB0
#define CListWnd__Draw_x                                           0x90D390
#define CListWnd__DrawColumnSeparators_x                           0x90FB80
#define CListWnd__DrawHeader_x                                     0x90FFF0
#define CListWnd__DrawItem_x                                       0x9104F0
#define CListWnd__DrawLine_x                                       0x90FCF0
#define CListWnd__DrawSeparator_x                                  0x90FC20
#define CListWnd__EnableLine_x                                     0x90F460
#define CListWnd__EnsureVisible_x                                  0x912C10
#define CListWnd__ExtendSel_x                                      0x9121C0
#define CListWnd__GetColumnTooltip_x                               0x90EFA0
#define CListWnd__GetColumnMinWidth_x                              0x90F010
#define CListWnd__GetColumnWidth_x                                 0x90EF10
#define CListWnd__GetCurSel_x                                      0x90E8A0
#define CListWnd__GetItemAtPoint_x                                 0x90F6D0
#define CListWnd__GetItemAtPoint1_x                                0x90F740
#define CListWnd__GetItemData_x                                    0x90E920
#define CListWnd__GetItemHeight_x                                  0x90ECE0
#define CListWnd__GetItemIcon_x                                    0x90EAB0
#define CListWnd__GetItemRect_x                                    0x90F550
#define CListWnd__GetItemText_x                                    0x90E960
#define CListWnd__GetSelList_x                                     0x912340
#define CListWnd__GetSeparatorRect_x                               0x90F980
#define CListWnd__InsertLine_x                                     0x911EA0
#define CListWnd__RemoveLine_x                                     0x911FF0
#define CListWnd__SetColors_x                                      0x911250
#define CListWnd__SetColumnJustification_x                         0x910F80
#define CListWnd__SetColumnLabel_x                                 0x911850
#define CListWnd__SetColumnWidth_x                                 0x910EA0
#define CListWnd__SetCurSel_x                                      0x912100
#define CListWnd__SetItemColor_x                                   0x9128D0
#define CListWnd__SetItemData_x                                    0x912890
#define CListWnd__SetItemText_x                                    0x9124B0
#define CListWnd__ShiftColumnSeparator_x                           0x911040
#define CListWnd__Sort_x                                           0x910D30
#define CListWnd__ToggleSel_x                                      0x912130
#define CListWnd__SetColumnsSizable_x                              0x9110F0
#define CListWnd__SetItemWnd_x                                     0x912760
#define CListWnd__GetItemWnd_x                                     0x90EB00
#define CListWnd__SetItemIcon_x                                    0x912530
#define CListWnd__CalculateCustomWindowPositions_x                 0x911590
#define CListWnd__SetVScrollPos_x                                  0x910E80

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x774D30
#define CMapViewWnd__GetWorldCoordinates_x                         0x773440
#define CMapViewWnd__HandleLButtonDown_x                           0x770480

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x794F90
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x795870
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x795DA0
#define CMerchantWnd__SelectRecoverySlot_x                         0x798D50
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x793B00
#define CMerchantWnd__SelectBuySellSlot_x                          0x79E920
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x794BB0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x896C70
#define CPacketScrambler__hton_x                                   0x896C60

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x92BEA0
#define CSidlManager__FindScreenPieceTemplate_x                    0x92C2B0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x92C0A0
#define CSidlManager__CreateLabel_x                                0x7F6CA0
#define CSidlManager__CreateXWndFromTemplate_x                     0x92F210
#define CSidlManager__CreateXWndFromTemplate1_x                    0x92F3F0
#define CSidlManager__CreateXWnd_x                                 0x7F6BE0
#define CSidlManager__CreateHotButtonWnd_x                         0x7F70E0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9289D0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9288D0
#define CSidlScreenWnd__ConvertToRes_x                             0x951A70
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9283C0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9280B0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x928180
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x928250
#define CSidlScreenWnd__DrawSidlPiece_x                            0x928E70
#define CSidlScreenWnd__EnableIniStorage_x                         0x929340
#define CSidlScreenWnd__GetSidlPiece_x                             0x929060
#define CSidlScreenWnd__Init1_x                                    0x927CB0
#define CSidlScreenWnd__LoadIniInfo_x                              0x929390
#define CSidlScreenWnd__LoadIniListWnd_x                           0x929E80
#define CSidlScreenWnd__LoadSidlScreen_x                           0x9270B0
#define CSidlScreenWnd__StoreIniInfo_x                             0x929A10
#define CSidlScreenWnd__StoreIniVis_x                              0x929D60
#define CSidlScreenWnd__WndNotification_x                          0x928D80
#define CSidlScreenWnd__GetChildItem_x                             0x9292C0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x918B40
#define CSidlScreenWnd__m_layoutCopy_x                             0x15CC708

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x696650
#define CSkillMgr__GetSkillCap_x                                   0x696830
#define CSkillMgr__GetNameToken_x                                  0x695DD0
#define CSkillMgr__IsActivatedSkill_x                              0x695F10
#define CSkillMgr__IsCombatSkill_x                                 0x695E50

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x938C40
#define CSliderWnd__SetValue_x                                     0x938AB0
#define CSliderWnd__SetNumTicks_x                                  0x938B10

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FCD40

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x941520
#define CStmlWnd__ParseSTML_x                                      0x942860
#define CStmlWnd__CalculateHSBRange_x                              0x942630
#define CStmlWnd__CalculateVSBRange_x                              0x9425B0
#define CStmlWnd__CanBreakAtCharacter_x                            0x946970
#define CStmlWnd__FastForwardToEndOfTag_x                          0x947600
#define CStmlWnd__ForceParseNow_x                                  0x941B10
#define CStmlWnd__GetNextTagPiece_x                                0x9468D0
#define CStmlWnd__GetSTMLText_x                                    0x50B810
#define CStmlWnd__GetVisibleText_x                                 0x941B30
#define CStmlWnd__InitializeWindowVariables_x                      0x947450
#define CStmlWnd__MakeStmlColorTag_x                               0x940B90
#define CStmlWnd__MakeWndNotificationTag_x                         0x940C00
#define CStmlWnd__SetSTMLText_x                                    0x93FC40
#define CStmlWnd__StripFirstSTMLLines_x                            0x9486F0
#define CStmlWnd__UpdateHistoryString_x                            0x947810

// CTabWnd 
#define CTabWnd__Draw_x                                            0x93ED90
#define CTabWnd__DrawCurrentPage_x                                 0x93F4C0
#define CTabWnd__DrawTab_x                                         0x93F1E0
#define CTabWnd__GetCurrentPage_x                                  0x93E590
#define CTabWnd__GetPageInnerRect_x                                0x93E7D0
#define CTabWnd__GetTabInnerRect_x                                 0x93E710
#define CTabWnd__GetTabRect_x                                      0x93E5C0
#define CTabWnd__InsertPage_x                                      0x93E9E0
#define CTabWnd__RemovePage_x                                      0x93EB50
#define CTabWnd__SetPage_x                                         0x93E850
#define CTabWnd__SetPageRect_x                                     0x93ECD0
#define CTabWnd__UpdatePage_x                                      0x93F0A0
#define CTabWnd__GetPageFromTabIndex_x                             0x93F120
#define CTabWnd__GetCurrentTabIndex_x                              0x93E580

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75A070
#define CPageWnd__SetTabText_x                                     0x93E0D0
#define CPageWnd__FlashTab_x                                       0x93E130

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A6DC0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x9159F0
#define CTextureFont__GetTextExtent_x                              0x915BB0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x94E880

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x902A20

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E7490
#define CXStr__CXStr1_x                                            0x9D95C0
#define CXStr__CXStr3_x                                            0x8EA2F0
#define CXStr__dCXStr_x                                            0x4765E0
#define CXStr__operator_equal_x                                    0x8EA520
#define CXStr__operator_equal1_x                                   0x8EA560
#define CXStr__operator_plus_equal1_x                              0x8EAFF0
#define CXStr__SetString_x                                         0x8ECEE0
#define CXStr__operator_char_p_x                                   0x8EAA60
#define CXStr__GetChar_x                                           0x8EC810
#define CXStr__Delete_x                                            0x8EC0E0
#define CXStr__GetUnicode_x                                        0x8EC880
#define CXStr__GetLength_x                                         0x4A6B70
#define CXStr__Mid_x                                               0x47B730
#define CXStr__Insert_x                                            0x8EC8E0
#define CXStr__FindNext_x                                          0x8EC550

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x936EC0
#define CXWnd__BringToTop_x                                        0x91C280
#define CXWnd__Center_x                                            0x91BE00
#define CXWnd__ClrFocus_x                                          0x91BC20
#define CXWnd__Destroy_x                                           0x91BCC0
#define CXWnd__DoAllDrawing_x                                      0x9182E0
#define CXWnd__DrawChildren_x                                      0x9182B0
#define CXWnd__DrawColoredRect_x                                   0x918730
#define CXWnd__DrawTooltip_x                                       0x916DF0
#define CXWnd__DrawTooltipAtPoint_x                                0x916EB0
#define CXWnd__GetBorderFrame_x                                    0x918590
#define CXWnd__GetChildWndAt_x                                     0x91C320
#define CXWnd__GetClientClipRect_x                                 0x91A5A0
#define CXWnd__GetScreenClipRect_x                                 0x91A670
#define CXWnd__GetScreenRect_x                                     0x91A830
#define CXWnd__GetRelativeRect_x                                   0x91A8E0
#define CXWnd__GetTooltipRect_x                                    0x918780
#define CXWnd__GetWindowTextA_x                                    0x49AAB0
#define CXWnd__IsActive_x                                          0x918EC0
#define CXWnd__IsDescendantOf_x                                    0x91B200
#define CXWnd__IsReallyVisible_x                                   0x91B230
#define CXWnd__IsType_x                                            0x91C990
#define CXWnd__Move_x                                              0x91B2A0
#define CXWnd__Move1_x                                             0x91B350
#define CXWnd__ProcessTransition_x                                 0x8AF020
#define CXWnd__Refade_x                                            0x91B600
#define CXWnd__Resize_x                                            0x91B8A0
#define CXWnd__Right_x                                             0x91C040
#define CXWnd__SetFocus_x                                          0x91BBE0
#define CXWnd__SetFont_x                                           0x91BC50
#define CXWnd__SetKeyTooltip_x                                     0x91C7B0
#define CXWnd__SetMouseOver_x                                      0x9196F0
#define CXWnd__StartFade_x                                         0x91B0E0
#define CXWnd__GetChildItem_x                                      0x91C490
#define CXWnd__SetParent_x                                         0x91AF90
#define CXWnd__Minimize_x                                          0x91B900

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x952B00

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x91F1A0
#define CXWndManager__DrawWindows_x                                0x91F1C0
#define CXWndManager__GetKeyboardFlags_x                           0x921980
#define CXWndManager__HandleKeyboardMsg_x                          0x921530
#define CXWndManager__RemoveWnd_x                                  0x921BB0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x922110

// CDBStr
#define CDBStr__GetString_x                                        0x545EA0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BDA10
#define EQ_Character__Cur_HP_x                                     0x4D0B90
#define EQ_Character__Cur_Mana_x                                   0x4D82E0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C0A80
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B1440
#define EQ_Character__GetFocusRangeModifier_x                      0x4B1590
#define EQ_Character__GetHPRegen_x                                 0x4DE1E0
#define EQ_Character__GetEnduranceRegen_x                          0x4DE7E0
#define EQ_Character__GetManaRegen_x                               0x4DEC20
#define EQ_Character__Max_Endurance_x                              0x65C9A0
#define EQ_Character__Max_HP_x                                     0x4D09C0
#define EQ_Character__Max_Mana_x                                   0x65C7A0
#define EQ_Character__doCombatAbility_x                            0x65EE50
#define EQ_Character__UseSkill_x                                   0x4E0A30
#define EQ_Character__GetConLevel_x                                0x655380
#define EQ_Character__IsExpansionFlag_x                            0x5B9520
#define EQ_Character__TotalEffect_x                                0x4C4820
#define EQ_Character__GetPCSpellAffect_x                           0x4C17D0
#define EQ_Character__SpellDuration_x                              0x4C1300
#define EQ_Character__MySpellDuration_x                            0x4AFD70
#define EQ_Character__GetAdjustedSkill_x                           0x4D3910
#define EQ_Character__GetBaseSkill_x                               0x4D48B0
#define EQ_Character__CanUseItem_x                                 0x4D85F0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B6130

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x672DE0

//PcClient
#define PcClient__vftable_x                                        0xAE8E40
#define PcClient__PcClient_x                                       0x652B10

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B8470
#define CCharacterListWnd__EnterWorld_x                            0x4B7E40
#define CCharacterListWnd__Quit_x                                  0x4B7B90
#define CCharacterListWnd__UpdateList_x                            0x4B8030

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x637160
#define EQ_Item__CreateItemTagString_x                             0x8900B0
#define EQ_Item__IsStackable_x                                     0x894E20
#define EQ_Item__GetImageNum_x                                     0x891C70
#define EQ_Item__CreateItemClient_x                                0x636380
#define EQ_Item__GetItemValue_x                                    0x892F90
#define EQ_Item__ValueSellMerchant_x                               0x896850
#define EQ_Item__IsKeyRingItem_x                                   0x8946D0
#define EQ_Item__CanGoInBag_x                                      0x637280
#define EQ_Item__IsEmpty_x                                         0x894200
#define EQ_Item__GetMaxItemCount_x                                 0x8933A0
#define EQ_Item__GetHeldItem_x                                     0x891B40
#define EQ_Item__GetAugmentFitBySlot_x                             0x88F910

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x564AC0
#define EQ_LoadingS__Array_x                                       0xC07128

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65D2A0
#define EQ_PC__GetAlternateAbilityId_x                             0x89FB20
#define EQ_PC__GetCombatAbility_x                                  0x8A0190
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A0200
#define EQ_PC__GetItemRecastTimer_x                                0x65F3D0
#define EQ_PC__HasLoreItem_x                                       0x655BA0
#define EQ_PC__AlertInventoryChanged_x                             0x654CC0
#define EQ_PC__GetPcZoneClient_x                                   0x681DF0
#define EQ_PC__RemoveMyAffect_x                                    0x6625F0
#define EQ_PC__GetKeyRingItems_x                                   0x8A0AD0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A0850
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A0DD0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BF8C0
#define EQItemList__add_object_x                                   0x5ECE70
#define EQItemList__add_item_x                                     0x5BFE20
#define EQItemList__delete_item_x                                  0x5BFE70
#define EQItemList__FreeItemList_x                                 0x5BFD70

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x542A30

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6746E0
#define EQPlayer__dEQPlayer_x                                      0x667AA0
#define EQPlayer__DoAttack_x                                       0x67C580
#define EQPlayer__EQPlayer_x                                       0x668160
#define EQPlayer__SetNameSpriteState_x                             0x66C3F0
#define EQPlayer__SetNameSpriteTint_x                              0x66D2D0
#define PlayerBase__HasProperty_j_x                                0x9812D0
#define EQPlayer__IsTargetable_x                                   0x981770
#define EQPlayer__CanSee_x                                         0x9815D0
#define EQPlayer__CanSee1_x                                        0x9816A0
#define PlayerBase__GetVisibilityLineSegment_x                     0x981390

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67F880
#define PlayerZoneClient__GetLevel_x                               0x681E30
#define PlayerZoneClient__IsValidTeleport_x                        0x5EDFE0
#define PlayerZoneClient__LegalPlayerRace_x                        0x55D690

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6774A0
#define EQPlayerManager__GetSpawnByName_x                          0x677550
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6775E0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63A8D0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63A950
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63A990
#define KeypressHandler__ClearCommandStateArray_x                  0x63BD80
#define KeypressHandler__HandleKeyDown_x                           0x63BDA0
#define KeypressHandler__HandleKeyUp_x                             0x63BE40
#define KeypressHandler__SaveKeymapping_x                          0x63C290

// MapViewMap 
#define MapViewMap__Clear_x                                        0x770BA0
#define MapViewMap__SaveEx_x                                       0x773F60
#define MapViewMap__SetZoom_x                                      0x778620

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B4190

// StringTable 
#define StringTable__getString_x                                   0x8AF020

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x662260
#define PcZoneClient__RemovePetEffect_x                            0x662890
#define PcZoneClient__HasAlternateAbility_x                        0x65C5D0
#define PcZoneClient__GetCurrentMod_x                              0x4E3B50
#define PcZoneClient__GetModCap_x                                  0x4E3A50
#define PcZoneClient__CanEquipItem_x                               0x65CC80
#define PcZoneClient__GetItemByID_x                                0x65F840
#define PcZoneClient__GetItemByItemClass_x                         0x65F990
#define PcZoneClient__RemoveBuffEffect_x                           0x6628B0
#define PcZoneClient__BandolierSwap_x                              0x65D860
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65F370

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F2B60

//IconCache
#define IconCache__GetIcon_x                                       0x714010

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70BB40
#define CContainerMgr__CloseContainer_x                            0x70BE10
#define CContainerMgr__OpenExperimentContainer_x                   0x70C890

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C91E0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62FE30

//CLootWnd
#define CLootWnd__LootAll_x                                        0x766FD0
#define CLootWnd__RequestLootSlot_x                                0x7662A0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58C680
#define EQ_Spell__SpellAffects_x                                   0x58CAF0
#define EQ_Spell__SpellAffectBase_x                                0x58C8B0
#define EQ_Spell__IsStackable_x                                    0x4C85F0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C8410
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B5720
#define EQ_Spell__IsSPAStacking_x                                  0x58D940
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58CE50
#define EQ_Spell__IsNoRemove_x                                     0x4C85D0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58D950
#define __IsResEffectSpell_x                                       0x4C7850

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AB010

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8BE830

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x80FF30
#define CTargetWnd__WndNotification_x                              0x80F770
#define CTargetWnd__RefreshTargetBuffs_x                           0x80FA40
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x80E8E0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8145C0
#define CTaskWnd__ConfirmAbandonTask_x                             0x817200

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x540440
#define CTaskManager__HandleMessage_x                              0x53E890
#define CTaskManager__GetTaskStatus_x                              0x5404F0
#define CTaskManager__GetElementDescription_x                      0x540570

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x587720
#define EqSoundManager__PlayScriptMp3_x                            0x5879E0
#define EqSoundManager__SoundAssistPlay_x                          0x69A620
#define EqSoundManager__WaveInstancePlay_x                         0x699B90

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5317F0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x93D5E0
#define CTextureAnimation__Draw_x                                  0x93D7E0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x9395A0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56C620
#define CAltAbilityData__GetMercMaxRank_x                          0x56C5B0
#define CAltAbilityData__GetMaxRank_x                              0x561930

//CTargetRing
#define CTargetRing__Cast_x                                        0x62DF50

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C83F0
#define CharacterBase__CreateItemGlobalIndex_x                     0x518490
#define CharacterBase__CreateItemIndex_x                           0x636070
#define CharacterBase__GetItemPossession_x                         0x5042A0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C6CC0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8C6D20
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F2AA0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F32D0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F3380

//messages
#define msg_spell_worn_off_x                                       0x5B1380
#define msg_new_text_x                                             0x5A5D90
#define __msgTokenTextParam_x                                      0x5B3620
#define msgTokenText_x                                             0x5B3870

//SpellManager
#define SpellManager__vftable_x                                    0xAD1404
#define SpellManager__SpellManager_x                               0x69D950
#define Spellmanager__LoadTextSpells_x                             0x69E240
#define SpellManager__GetSpellByGroupAndRank_x                     0x69DB20

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x985190

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x518B10
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B78B0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64E280
#define ItemGlobalIndex__IsValidIndex_x                            0x518BA0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8BF1F0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8BF380

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x75F9C0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x710220
#define CCursorAttachment__AttachToCursor1_x                       0x710260
#define CCursorAttachment__Deactivate_x                            0x711240

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x930250
#define CSidlManagerBase__CreatePageWnd_x                          0x92FA40
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x92BCC0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x92BC50

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x94D5A0
#define CEQSuiteTextureLoader__GetTexture_x                        0x94D260

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x515780
#define CFindItemWnd__WndNotification_x                            0x5163C0
#define CFindItemWnd__Update_x                                     0x516F30
#define CFindItemWnd__PickupSelectedItem_x                         0x514FA0

//IString
#define IString__Append_x                                          0x505B70

//Camera
#define CDisplay__cameraType_x                                     0xDDE014
#define EverQuest__Cameras_x                                       0xE98B70

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51E4B0
#define LootFiltersManager__GetItemFilterData_x                    0x51DDC0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51DDF0
#define LootFiltersManager__SetItemLootFilter_x                    0x51E010

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B7080

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x98AE60
#define CResolutionHandler__GetWindowedStyle_x                     0x6950C0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x708770

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8CAB30
#define CDistillerInfo__Instance_x                                 0x8CAAD0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7274E0
#define CGroupWnd__UpdateDisplay_x                                 0x726830

//ItemBase
#define ItemBase__IsLore_x                                         0x894780
#define ItemBase__IsLoreEquipped_x                                 0x8947F0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5ECDD0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5ECF10
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5ECF70

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68A510
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68DED0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50BE10

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F7FD0
#define FactionManagerClient__HandleFactionMessage_x               0x4F8640
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F8C40
#define FactionManagerClient__GetMaxFaction_x                      0x4F8C5F
#define FactionManagerClient__GetMinFaction_x                      0x4F8C10

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x504270

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x914980

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x499DC0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x504580

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56BAA0

//CTargetManager
#define CTargetManager__Get_x                                      0x6A11B0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68A510

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A6B80

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BFD10

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF36204

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BC420
#define CAAWnd__UpdateSelected_x                                   0x6B8C90
#define CAAWnd__Update_x                                           0x6BB740

//CXRect
#define CXRect__operator_and_x                                     0x71E620

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x480F40

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
