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
#define __ExpectedVersionDate                                     "Oct 28 2020"
#define __ExpectedVersionTime                                     "04:17:04"
#define __ActualVersionDate_x                                      0xAF5558
#define __ActualVersionTime_x                                      0xAF554C
#define __ActualVersionBuild_x                                     0xAE355C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x643250
#define __MemChecker1_x                                            0x8F5C80
#define __MemChecker2_x                                            0x6B3670
#define __MemChecker3_x                                            0x6B35C0
#define __MemChecker4_x                                            0x84C400
#define __EncryptPad0_x                                            0xC2A9D0
#define __EncryptPad1_x                                            0xC88210
#define __EncryptPad2_x                                            0xC3AD98
#define __EncryptPad3_x                                            0xC3A998
#define __EncryptPad4_x                                            0xC787A8
#define __EncryptPad5_x                                            0xF4A640
#define __AC1_x                                                    0x80B086
#define __AC2_x                                                    0x5FC83F
#define __AC3_x                                                    0x603E90
#define __AC4_x                                                    0x607E40
#define __AC5_x                                                    0x60E13F
#define __AC6_x                                                    0x6125F6
#define __AC7_x                                                    0x5FC2B0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1907B8

// Direct Input
#define DI8__Main_x                                                0xF4A660
#define DI8__Keyboard_x                                            0xF4A664
#define DI8__Mouse_x                                               0xF4A678
#define DI8__Mouse_Copy_x                                          0xEA39D4
#define DI8__Mouse_Check_x                                         0xF48194
#define __AutoSkillArray_x                                         0xEA48F0
#define __Attack_x                                                 0xF42717
#define __Autofire_x                                               0xF42718
#define __BindList_x                                               0xC19400
#define g_eqCommandStates_x                                        0xC1A180
#define __Clicks_x                                                 0xEA3A8C
#define __CommandList_x                                            0xC1AD40
#define __CurrentMapLabel_x                                        0xF5B13C
#define __CurrentSocial_x                                          0xC027C8
#define __DoAbilityList_x                                          0xEDA238
#define __do_loot_x                                                0x5C8270
#define __DrawHandler_x                                            0x15DA130
#define __GroupCount_x                                             0xE9EA62
#define __Guilds_x                                                 0xEA2910
#define __gWorld_x                                                 0xE9E910
#define __HWnd_x                                                   0xF4A67C
#define __heqmain_x                                                0xF4A628
#define __InChatMode_x                                             0xEA39BC
#define __LastTell_x                                               0xEA5934
#define __LMouseHeldTime_x                                         0xEA3AF8
#define __Mouse_x                                                  0xF4A64C
#define __MouseLook_x                                              0xEA3A52
#define __MouseEventTime_x                                         0xF431FC
#define __gpbCommandEvent_x                                        0xE9C3B4
#define __NetStatusToggle_x                                        0xEA3A55
#define __PCNames_x                                                0xEA4EE0
#define __RangeAttackReady_x                                       0xEA4BD4
#define __RMouseHeldTime_x                                         0xEA3AF4
#define __RunWalkState_x                                           0xEA39C0
#define __ScreenMode_x                                             0xDE9D60
#define __ScreenX_x                                                0xEA3974
#define __ScreenY_x                                                0xEA3970
#define __ScreenXMax_x                                             0xEA3978
#define __ScreenYMax_x                                             0xEA397C
#define __ServerHost_x                                             0xE9C583
#define __ServerName_x                                             0xEDA1F8
#define __ShiftKeyDown_x                                           0xEA4050
#define __ShowNames_x                                              0xEA4D90
#define EverQuestInfo__bSocialChanged_x                            0xEDA280
#define __Socials_x                                                0xEDA2F8
#define __SubscriptionType_x                                       0xF9F400
#define __TargetAggroHolder_x                                      0xF5DAF0
#define __ZoneType_x                                               0xEA3E50
#define __GroupAggro_x                                             0xF5DB30
#define __LoginName_x                                              0xF4ADBC
#define __Inviter_x                                                0xF42694
#define __AttackOnAssist_x                                         0xEA4D4C
#define __UseTellWindows_x                                         0xEA5078
#define __gfMaxZoomCameraDistance_x                                0xAED178
#define __gfMaxCameraDistance_x                                    0xB15DF8
#define __pulAutoRun_x                                             0xEA3A70
#define __pulForward_x                                             0xEA50B0
#define __pulBackward_x                                            0xEA50B4
#define __pulTurnRight_x                                           0xEA50B8
#define __pulTurnLeft_x                                            0xEA50BC
#define __pulStrafeLeft_x                                          0xEA50C0
#define __pulStrafeRight_x                                         0xEA50C4

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE9ECB0
#define instEQZoneInfo_x                                           0xEA3C48
#define pinstActiveBanker_x                                        0xE9C8A0
#define pinstActiveCorpse_x                                        0xE9C898
#define pinstActiveGMaster_x                                       0xE9C89C
#define pinstActiveMerchant_x                                      0xE9C894
#define pinstAltAdvManager_x                                       0xDEAEE0
#define pinstBandageTarget_x                                       0xE9C8B0
#define pinstCamActor_x                                            0xDE9D50
#define pinstCDBStr_x                                              0xDE9BFC
#define pinstCDisplay_x                                            0xE9E908
#define pinstCEverQuest_x                                          0xF4A680
#define pinstEverQuestInfo_x                                       0xEA3968
#define pinstCharData_x                                            0xE9ECA4
#define pinstCharSpawn_x                                           0xE9C8E8
#define pinstControlledMissile_x                                   0xE9C8F8
#define pinstControlledPlayer_x                                    0xE9C8E8
#define pinstCResolutionHandler_x                                  0x15DA360
#define pinstCSidlManager_x                                        0x15D92F8
#define pinstCXWndManager_x                                        0x15D92F4
#define instDynamicZone_x                                          0xEA27E8
#define pinstDZMember_x                                            0xEA28F8
#define pinstDZTimerInfo_x                                         0xEA28FC
#define pinstEqLogin_x                                             0xF4A708
#define instEQMisc_x                                               0xDE9B40
#define pinstEQSoundManager_x                                      0xDEBEB0
#define pinstEQSpellStrings_x                                      0xCAC448
#define instExpeditionLeader_x                                     0xEA2832
#define instExpeditionName_x                                       0xEA2872
#define pinstGroup_x                                               0xE9EA5E
#define pinstImeManager_x                                          0x15D92F0
#define pinstLocalPlayer_x                                         0xE9C68C
#define pinstMercenaryData_x                                       0xF44CF0
#define pinstMercenaryStats_x                                      0xF5DBBC
#define pinstModelPlayer_x                                         0xE9C8A8
#define pinstPCData_x                                              0xE9ECA4
#define pinstSkillMgr_x                                            0xF46E58
#define pinstSpawnManager_x                                        0xF45900
#define pinstSpellManager_x                                        0xF47098
#define pinstSpellSets_x                                           0xF3B340
#define pinstStringTable_x                                         0xE9C3A0
#define pinstSwitchManager_x                                       0xE9C250
#define pinstTarget_x                                              0xE9C8E4
#define pinstTargetObject_x                                        0xE9C8F0
#define pinstTargetSwitch_x                                        0xE9E900
#define pinstTaskMember_x                                          0xDE99D0
#define pinstTrackTarget_x                                         0xE9C8EC
#define pinstTradeTarget_x                                         0xE9C8A4
#define instTributeActive_x                                        0xDE9B61
#define pinstViewActor_x                                           0xDE9D48
#define pinstWorldData_x                                           0xE9C3A4
#define pinstZoneAddr_x                                            0xEA3EE8
#define pinstPlayerPath_x                                          0xF45998
#define pinstTargetIndicator_x                                     0xF47300
#define EQObject_Top_x                                             0xE9C47C
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDEA074
#define pinstCAchievementsWnd_x                                    0xDE9CE8
#define pinstCActionsWnd_x                                         0xDEA0B0
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDE9DA8
#define pinstCAdvancedLootWnd_x                                    0xDE9D40
#define pinstCAdventureLeaderboardWnd_x                            0xF54910
#define pinstCAdventureRequestWnd_x                                0xF549C0
#define pinstCAdventureStatsWnd_x                                  0xF54A70
#define pinstCAggroMeterWnd_x                                      0xDE9D90
#define pinstCAlarmWnd_x                                           0xDE9D10
#define pinstCAlertHistoryWnd_x                                    0xDE9E24
#define pinstCAlertStackWnd_x                                      0xDE9D78
#define pinstCAlertWnd_x                                           0xDE9D8C
#define pinstCAltStorageWnd_x                                      0xF54DD0
#define pinstCAudioTriggersWindow_x                                0xC9E778
#define pinstCAuraWnd_x                                            0xDE9D44
#define pinstCAvaZoneWnd_x                                         0xDE9E20
#define pinstCBandolierWnd_x                                       0xDE9DA4
#define pinstCBankWnd_x                                            0xDE9DD8
#define pinstCBarterMerchantWnd_x                                  0xF56010
#define pinstCBarterSearchWnd_x                                    0xF560C0
#define pinstCBarterWnd_x                                          0xF56170
#define pinstCBazaarConfirmationWnd_x                              0xDE9D24
#define pinstCBazaarSearchWnd_x                                    0xDEA078
#define pinstCBazaarWnd_x                                          0xDE9CF4
#define pinstCBlockedBuffWnd_x                                     0xDE9D6C
#define pinstCBlockedPetBuffWnd_x                                  0xDE9D94
#define pinstCBodyTintWnd_x                                        0xDE9C9C
#define pinstCBookWnd_x                                            0xDE9DD0
#define pinstCBreathWnd_x                                          0xDEA088
#define pinstCBuffWindowNORMAL_x                                   0xDE9D38
#define pinstCBuffWindowSHORT_x                                    0xDE9D3C
#define pinstCBugReportWnd_x                                       0xDE9DD4
#define pinstCButtonWnd_x                                          0x15D9560
#define pinstCCastingWnd_x                                         0xDE9DC4
#define pinstCCastSpellWnd_x                                       0xDEA084
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDE9CA8
#define pinstCChatWindowManager_x                                  0xF56C30
#define pinstCClaimWnd_x                                           0xF56D88
#define pinstCColorPickerWnd_x                                     0xDEA03C
#define pinstCCombatAbilityWnd_x                                   0xDE9D04
#define pinstCCombatSkillsSelectWnd_x                              0xDE9CBC
#define pinstCCompassWnd_x                                         0xDEA0C4
#define pinstCConfirmationDialog_x                                 0xF5BC88
#define pinstCContainerMgr_x                                       0xDE9C98
#define pinstCContextMenuManager_x                                 0x15D92B0
#define pinstCCursorAttachment_x                                   0xDE9DB8
#define pinstCDynamicZoneWnd_x                                     0xF57350
#define pinstCEditLabelWnd_x                                       0xDE9D34
#define pinstCEQMainWnd_x                                          0xF57598
#define pinstCEventCalendarWnd_x                                   0xDEA07C
#define pinstCExtendedTargetWnd_x                                  0xDE9D74
#define pinstCFacePick_x                                           0xDE9CC0
#define pinstCFactionWnd_x                                         0xDE9CE0
#define pinstCFellowshipWnd_x                                      0xF57798
#define pinstCFileSelectionWnd_x                                   0xDEA038
#define pinstCFindItemWnd_x                                        0xDE9CD0
#define pinstCFindLocationWnd_x                                    0xF578F0
#define pinstCFriendsWnd_x                                         0xDE9CD4
#define pinstCGemsGameWnd_x                                        0xDE9CDC
#define pinstCGiveWnd_x                                            0xDE9D14
#define pinstCGroupSearchFiltersWnd_x                              0xDE9DAC
#define pinstCGroupSearchWnd_x                                     0xF57CE8
#define pinstCGroupWnd_x                                           0xF57D98
#define pinstCGuildBankWnd_x                                       0xEA4D30
#define pinstCGuildCreationWnd_x                                   0xF57EF8
#define pinstCGuildMgmtWnd_x                                       0xF57FA8
#define pinstCharacterCreation_x                                   0xDE9CC8
#define pinstCHelpWnd_x                                            0xDE9D18
#define pinstCHeritageSelectionWnd_x                               0xDE9CCC
#define pinstCHotButtonWnd_x                                       0xF5A100
#define pinstCHotButtonWnd1_x                                      0xF5A100
#define pinstCHotButtonWnd2_x                                      0xF5A104
#define pinstCHotButtonWnd3_x                                      0xF5A108
#define pinstCHotButtonWnd4_x                                      0xF5A10C
#define pinstCIconSelectionWnd_x                                   0xDE9DB4
#define pinstCInspectWnd_x                                         0xDE9D98
#define pinstCInventoryWnd_x                                       0xDE9D4C
#define pinstCInvSlotMgr_x                                         0xDEA068
#define pinstCItemDisplayManager_x                                 0xF5A690
#define pinstCItemExpTransferWnd_x                                 0xF5A7C4
#define pinstCItemOverflowWnd_x                                    0xDEA080
#define pinstCJournalCatWnd_x                                      0xDEA054
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDE9E0C
#define pinstCKeyRingWnd_x                                         0xDE9DC0
#define pinstCLargeDialogWnd_x                                     0xF5C908
#define pinstCLayoutCopyWnd_x                                      0xF5AB10
#define pinstCLFGuildWnd_x                                         0xF5ABC0
#define pinstCLoadskinWnd_x                                        0xDE9CF8
#define pinstCLootFiltersCopyWnd_x                                 0xCBAED8
#define pinstCLootFiltersWnd_x                                     0xDE9D7C
#define pinstCLootSettingsWnd_x                                    0xDE9DA0
#define pinstCLootWnd_x                                            0xDEA058
#define pinstCMailAddressBookWnd_x                                 0xDEA06C
#define pinstCMailCompositionWnd_x                                 0xDEA044
#define pinstCMailIgnoreListWnd_x                                  0xDEA070
#define pinstCMailWnd_x                                            0xDEA048
#define pinstCManageLootWnd_x                                      0xDEB390
#define pinstCMapToolbarWnd_x                                      0xDE9D20
#define pinstCMapViewWnd_x                                         0xDE9CEC
#define pinstCMarketplaceWnd_x                                     0xDE9D80
#define pinstCMerchantWnd_x                                        0xDEA064
#define pinstCMIZoneSelectWnd_x                                    0xF5B3F8
#define pinstCMusicPlayerWnd_x                                     0xDEA030
#define pinstCNameChangeMercWnd_x                                  0xDE9D1C
#define pinstCNameChangePetWnd_x                                   0xDE9CF0
#define pinstCNameChangeWnd_x                                      0xDE9D30
#define pinstCNoteWnd_x                                            0xDE9CFC
#define pinstCObjectPreviewWnd_x                                   0xDE9D9C
#define pinstCOptionsWnd_x                                         0xDE9D08
#define pinstCPetInfoWnd_x                                         0xDE9E2C
#define pinstCPetitionQWnd_x                                       0xDE9CB8
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDE9CA0
#define pinstCPlayerWnd_x                                          0xDE9E18
#define pinstCPopupWndManager_x                                    0xF5BC88
#define pinstCProgressionSelectionWnd_x                            0xF5BD38
#define pinstCPurchaseGroupWnd_x                                   0xDE9DF0
#define pinstCPurchaseWnd_x                                        0xDE9DC8
#define pinstCPvPLeaderboardWnd_x                                  0xF5BDE8
#define pinstCPvPStatsWnd_x                                        0xF5BE98
#define pinstCQuantityWnd_x                                        0xDE9E08
#define pinstCRaceChangeWnd_x                                      0xDE9D5C
#define pinstCRaidOptionsWnd_x                                     0xDE9DB0
#define pinstCRaidWnd_x                                            0xDEA060
#define pinstCRealEstateItemsWnd_x                                 0xDE9CE4
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDEA12C
#define pinstCRealEstateManageWnd_x                                0xDE9DF4
#define pinstCRealEstateNeighborhoodWnd_x                          0xDE9E14
#define pinstCRealEstatePlotSearchWnd_x                            0xDEA034
#define pinstCRealEstatePurchaseWnd_x                              0xDEA050
#define pinstCRespawnWnd_x                                         0xDE9D88
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDE9CB4
#define pinstCSendMoneyWnd_x                                       0xDE9D28
#define pinstCServerListWnd_x                                      0xDEA05C
#define pinstCSkillsSelectWnd_x                                    0xDE9CB0
#define pinstCSkillsWnd_x                                          0xDEA130
#define pinstCSocialEditWnd_x                                      0xDE9DBC
#define pinstCSocialWnd_x                                          0xDE9D0C
#define pinstCSpellBookWnd_x                                       0xDE9D00
#define pinstCStoryWnd_x                                           0xDEA0AC
#define pinstCTargetOfTargetWnd_x                                  0xF5DC40
#define pinstCTargetWnd_x                                          0xDE9D84
#define pinstCTaskOverlayWnd_x                                     0xDE9DE8
#define pinstCTaskSelectWnd_x                                      0xF5DD98
#define pinstCTaskManager_x                                        0xCBB818
#define pinstCTaskTemplateSelectWnd_x                              0xF5DE48
#define pinstCTaskWnd_x                                            0xF5DEF8
#define pinstCTextEntryWnd_x                                       0xDE9DCC
#define pinstCTimeLeftWnd_x                                        0xDE9CAC
#define pinstCTipWndCONTEXT_x                                      0xF5E0FC
#define pinstCTipWndOFDAY_x                                        0xF5E0F8
#define pinstCTitleWnd_x                                           0xF5E1A8
#define pinstCTrackingWnd_x                                        0xDE9D70
#define pinstCTradeskillWnd_x                                      0xF5E310
#define pinstCTradeWnd_x                                           0xDE9CA4
#define pinstCTrainWnd_x                                           0xDEA04C
#define pinstCTributeBenefitWnd_x                                  0xF5E510
#define pinstCTributeMasterWnd_x                                   0xF5E5C0
#define pinstCTributeTrophyWnd_x                                   0xF5E670
#define pinstCVideoModesWnd_x                                      0xDE9E1C
#define pinstCVoiceMacroWnd_x                                      0xF478B8
#define pinstCVoteResultsWnd_x                                     0xDE9CD8
#define pinstCVoteWnd_x                                            0xDE9CC4
#define pinstCWebManager_x                                         0xF47F34
#define pinstCZoneGuideWnd_x                                       0xDE9DEC
#define pinstCZonePathWnd_x                                        0xDE9E04

#define pinstEQSuiteTextureLoader_x                                0xC88B30
#define pinstItemIconCache_x                                       0xF57550
#define pinstLootFiltersManager_x                                  0xCBAF88
#define pinstRewardSelectionWnd_x                                  0xF5C5E0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C3960
#define __CastRay2_x                                               0x5C39B0
#define __ConvertItemTags_x                                        0x5DF670
#define __CleanItemTags_x                                          0x47D240
#define __DoesFileExist_x                                          0x8F8CB0
#define __EQGetTime_x                                              0x8F58B0
#define __ExecuteCmd_x                                             0x5BC290
#define __FixHeading_x                                             0x98B2C0
#define __FlushDxKeyboard_x                                        0x6AF510
#define __GameLoop_x                                               0x6B2840
#define __get_bearing_x                                            0x5C34C0
#define __get_melee_range_x                                        0x5C3BA0
#define __GetAnimationCache_x                                      0x717C20
#define __GetGaugeValueFromEQ_x                                    0x809530
#define __GetLabelFromEQ_x                                         0x80B010
#define __GetXTargetType_x                                         0x98CD10
#define __HandleMouseWheel_x                                       0x6B3720
#define __HeadingDiff_x                                            0x98B330
#define __HelpPath_x                                               0xF42DEC
#define __LoadFrontEnd_x                                           0x6AFB50
#define __NewUIINI_x                                               0x809200
#define __ProcessGameEvents_x                                      0x6244D0
#define __ProcessMouseEvent_x                                      0x623C60
#define __SaveColors_x                                             0x55CC20
#define __STMLToText_x                                             0x92E5F0
#define __ToggleKeyRingItem_x                                      0x51B120
#define CMemoryMappedFile__SetFile_x                               0xA7A6E0
#define CrashDetected_x                                            0x6B1600
#define DrawNetStatus_x                                            0x650850
#define Expansion_HoT_x                                            0xEA4D38
#define Teleport_Table_Size_x                                      0xE9C43C
#define Teleport_Table_x                                           0xE9C900
#define Util__FastTime_x                                           0x8F5480
#define __CopyLayout_x                                             0x63E9A0
#define __WndProc_x                                                0x6B1B00
#define __ProcessKeyboardEvent_x                                   0x6B10A0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490460
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499460
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499230
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A00
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492E50

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x564E00
#define AltAdvManager__IsAbilityReady_x                            0x563BA0
#define AltAdvManager__GetAAById_x                                 0x563F30
#define AltAdvManager__CanTrainAbility_x                           0x563FA0
#define AltAdvManager__CanSeeAbility_x                             0x564300

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CAE50
#define CharacterZoneClient__HasSkill_x                            0x4D5CD0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D73F0
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2640
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBAD0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9D90
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9E70
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9F50
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4730
#define CharacterZoneClient__BardCastBard_x                        0x4C7160
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF4E0
#define CharacterZoneClient__GetEffect_x                           0x4BBA10
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C57A0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5870
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C58C0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5A10
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5BF0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3A00
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8350
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7DD0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D9360
#define CBankWnd__WndNotification_x                                0x6D9140

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E6D50

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92BDD0
#define CButtonWnd__CButtonWnd_x                                   0x92A9B0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x706D90
#define CChatManager__InitContextMenu_x                            0x6FFEC0
#define CChatManager__FreeChatWindow_x                             0x7058D0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9720
#define CChatManager__SetLockedActiveChatWindow_x                  0x706A10
#define CChatManager__CreateChatWindow_x                           0x705F10

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9830

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93F050
#define CContextMenu__dCContextMenu_x                              0x93F280
#define CContextMenu__AddMenuItem_x                                0x93F290
#define CContextMenu__RemoveMenuItem_x                             0x93F590
#define CContextMenu__RemoveAllMenuItems_x                         0x93F5B0
#define CContextMenu__CheckMenuItem_x                              0x93F630
#define CContextMenu__SetMenuItem_x                                0x93F4C0
#define CContextMenu__AddSeparator_x                               0x93F420

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93FBD0
#define CContextMenuManager__RemoveMenu_x                          0x93FC40
#define CContextMenuManager__PopupMenu_x                           0x93FD00
#define CContextMenuManager__Flush_x                               0x93FB70
#define CContextMenuManager__GetMenu_x                             0x49B600
#define CContextMenuManager__CreateDefaultMenu_x                   0x712550

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D05E0
#define CChatService__GetFriendName_x                              0x8D05F0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7075C0
#define CChatWindow__Clear_x                                       0x708880
#define CChatWindow__WndNotification_x                             0x709010
#define CChatWindow__AddHistory_x                                  0x708140

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93C4B0
#define CComboWnd__Draw_x                                          0x93B9B0
#define CComboWnd__GetCurChoice_x                                  0x93C2F0
#define CComboWnd__GetListRect_x                                   0x93BE60
#define CComboWnd__GetTextRect_x                                   0x93C510
#define CComboWnd__InsertChoice_x                                  0x93BFF0
#define CComboWnd__SetColors_x                                     0x93BFC0
#define CComboWnd__SetChoice_x                                     0x93C2C0
#define CComboWnd__GetItemCount_x                                  0x93C300
#define CComboWnd__GetCurChoiceText_x                              0x93C340
#define CComboWnd__GetChoiceText_x                                 0x93C310
#define CComboWnd__InsertChoiceAtIndex_x                           0x93C080

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70FF50
#define CContainerWnd__vftable_x                                   0xAFE74C
#define CContainerWnd__SetContainer_x                              0x7114B0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x557580
#define CDisplay__PreZoneMainUI_x                                  0x557590
#define CDisplay__CleanGameUI_x                                    0x55C9E0
#define CDisplay__GetClickedActor_x                                0x54F9E0
#define CDisplay__GetUserDefinedColor_x                            0x548050
#define CDisplay__GetWorldFilePath_x                               0x551450
#define CDisplay__is3dON_x                                         0x54C640
#define CDisplay__ReloadUI_x                                       0x556A90
#define CDisplay__WriteTextHD2_x                                   0x54C430
#define CDisplay__TrueDistance_x                                   0x553110
#define CDisplay__SetViewActor_x                                   0x54F300
#define CDisplay__GetFloorHeight_x                                 0x54C700
#define CDisplay__SetRenderWindow_x                                0x54B080
#define CDisplay__ToggleScreenshotMode_x                           0x54EDD0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95EF20

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x942550
#define CEditWnd__EnsureCaretVisible_x                             0x944710
#define CEditWnd__GetCaretPt_x                                     0x9436C0
#define CEditWnd__GetCharIndexPt_x                                 0x943470
#define CEditWnd__GetDisplayString_x                               0x943310
#define CEditWnd__GetHorzOffset_x                                  0x941BF0
#define CEditWnd__GetLineForPrintableChar_x                        0x944610
#define CEditWnd__GetSelStartPt_x                                  0x943720
#define CEditWnd__GetSTMLSafeText_x                                0x943130
#define CEditWnd__PointFromPrintableChar_x                         0x944240
#define CEditWnd__SelectableCharFromPoint_x                        0x9443B0
#define CEditWnd__SetEditable_x                                    0x9437F0
#define CEditWnd__SetWindowTextA_x                                 0x942EB0
#define CEditWnd__ReplaceSelection_x                               0x943EB0
#define CEditWnd__ReplaceSelection1_x                              0x943E30

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x611AD0
#define CEverQuest__ClickedPlayer_x                                0x603C70
#define CEverQuest__CreateTargetIndicator_x                        0x621640
#define CEverQuest__DeleteTargetIndicator_x                        0x6216D0
#define CEverQuest__DoTellWindow_x                                 0x4E9910
#define CEverQuest__OutputTextToLog_x                              0x4E9BE0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F8DC0
#define CEverQuest__dsp_chat_x                                     0x4E9F70
#define CEverQuest__trimName_x                                     0x61D7F0
#define CEverQuest__Emote_x                                        0x612330
#define CEverQuest__EnterZone_x                                    0x60C430
#define CEverQuest__GetBodyTypeDesc_x                              0x616D80
#define CEverQuest__GetClassDesc_x                                 0x6173C0
#define CEverQuest__GetClassThreeLetterCode_x                      0x6179C0
#define CEverQuest__GetDeityDesc_x                                 0x61FE90
#define CEverQuest__GetLangDesc_x                                  0x617B80
#define CEverQuest__GetRaceDesc_x                                  0x6173A0
#define CEverQuest__InterpretCmd_x                                 0x620460
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FCF60
#define CEverQuest__LMouseUp_x                                     0x5FB2E0
#define CEverQuest__RightClickedOnPlayer_x                         0x5FD840
#define CEverQuest__RMouseUp_x                                     0x5FC270
#define CEverQuest__SetGameState_x                                 0x5F8B50
#define CEverQuest__UPCNotificationFlush_x                         0x61D6F0
#define CEverQuest__IssuePetCommand_x                              0x618F90
#define CEverQuest__ReportSuccessfulHit_x                          0x613680

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x721CD0
#define CGaugeWnd__CalcLinesFillRect_x                             0x721D30
#define CGaugeWnd__Draw_x                                          0x721350

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFCA0
#define CGuild__GetGuildName_x                                     0x4AE750
#define CGuild__GetGuildIndex_x                                    0x4AED50

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73B930

//CHotButton
#define CHotButton__SetCheck_x                                     0x632E60
#define CHotButton__SetButtonSize_x                                0x633220

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7489D0
#define CInvSlotMgr__MoveItem_x                                    0x7476E0
#define CInvSlotMgr__SelectSlot_x                                  0x748AA0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x745ED0
#define CInvSlot__SliderComplete_x                                 0x743C10
#define CInvSlot__GetItemBase_x                                    0x7435A0
#define CInvSlot__UpdateItem_x                                     0x743710

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74A530
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7496C0
#define CInvSlotWnd__HandleLButtonUp_x                             0x74A0B0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8048D0
#define CItemDisplayWnd__UpdateStrings_x                           0x758D10
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7529D0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x752EF0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x759320
#define CItemDisplayWnd__AboutToShow_x                             0x758960
#define CItemDisplayWnd__WndNotification_x                         0x75A570
#define CItemDisplayWnd__RequestConvertItem_x                      0x759EC0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7579C0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x758780

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x835300

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75EAC0

// CLabel 
#define CLabel__Draw_x                                             0x764570

// CListWnd
#define CListWnd__CListWnd_x                                       0x914C50
#define CListWnd__dCListWnd_x                                      0x914F70
#define CListWnd__AddColumn_x                                      0x9193D0
#define CListWnd__AddColumn1_x                                     0x919420
#define CListWnd__AddLine_x                                        0x9197B0
#define CListWnd__AddString_x                                      0x9195B0
#define CListWnd__CalculateFirstVisibleLine_x                      0x919190
#define CListWnd__CalculateVSBRange_x                              0x918F70
#define CListWnd__ClearSel_x                                       0x919F90
#define CListWnd__ClearAllSel_x                                    0x919FF0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91A9F0
#define CListWnd__Compare_x                                        0x9188A0
#define CListWnd__Draw_x                                           0x9150A0
#define CListWnd__DrawColumnSeparators_x                           0x917870
#define CListWnd__DrawHeader_x                                     0x917CE0
#define CListWnd__DrawItem_x                                       0x9181E0
#define CListWnd__DrawLine_x                                       0x9179E0
#define CListWnd__DrawSeparator_x                                  0x917910
#define CListWnd__EnableLine_x                                     0x917160
#define CListWnd__EnsureVisible_x                                  0x91A920
#define CListWnd__ExtendSel_x                                      0x919EC0
#define CListWnd__GetColumnTooltip_x                               0x916CA0
#define CListWnd__GetColumnMinWidth_x                              0x916D10
#define CListWnd__GetColumnWidth_x                                 0x916C10
#define CListWnd__GetCurSel_x                                      0x9165A0
#define CListWnd__GetItemAtPoint_x                                 0x9173D0
#define CListWnd__GetItemAtPoint1_x                                0x917440
#define CListWnd__GetItemData_x                                    0x916620
#define CListWnd__GetItemHeight_x                                  0x9169E0
#define CListWnd__GetItemIcon_x                                    0x9167B0
#define CListWnd__GetItemRect_x                                    0x917250
#define CListWnd__GetItemText_x                                    0x916660
#define CListWnd__GetSelList_x                                     0x91A040
#define CListWnd__GetSeparatorRect_x                               0x917680
#define CListWnd__InsertLine_x                                     0x919BA0
#define CListWnd__RemoveLine_x                                     0x919CF0
#define CListWnd__SetColors_x                                      0x918F40
#define CListWnd__SetColumnJustification_x                         0x918C70
#define CListWnd__SetColumnLabel_x                                 0x919550
#define CListWnd__SetColumnWidth_x                                 0x918B90
#define CListWnd__SetCurSel_x                                      0x919E00
#define CListWnd__SetItemColor_x                                   0x91A5E0
#define CListWnd__SetItemData_x                                    0x91A5A0
#define CListWnd__SetItemText_x                                    0x91A1B0
#define CListWnd__ShiftColumnSeparator_x                           0x918D30
#define CListWnd__Sort_x                                           0x918A20
#define CListWnd__ToggleSel_x                                      0x919E30
#define CListWnd__SetColumnsSizable_x                              0x918DE0
#define CListWnd__SetItemWnd_x                                     0x91A460
#define CListWnd__GetItemWnd_x                                     0x916800
#define CListWnd__SetItemIcon_x                                    0x91A230
#define CListWnd__CalculateCustomWindowPositions_x                 0x919290
#define CListWnd__SetVScrollPos_x                                  0x918B70

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x779CD0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7783E0
#define CMapViewWnd__HandleLButtonDown_x                           0x775420

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x799F80
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79A860
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79AD90
#define CMerchantWnd__SelectRecoverySlot_x                         0x79DD40
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x798AF0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A3910
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x799BA0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89E6A0
#define CPacketScrambler__hton_x                                   0x89E690

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x933BD0
#define CSidlManager__FindScreenPieceTemplate_x                    0x933FE0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x933DD0
#define CSidlManager__CreateLabel_x                                0x7FBB70
#define CSidlManager__CreateXWndFromTemplate_x                     0x936F40
#define CSidlManager__CreateXWndFromTemplate1_x                    0x937120
#define CSidlManager__CreateXWnd_x                                 0x7FBAA0
#define CSidlManager__CreateHotButtonWnd_x                         0x7FC060

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9306A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9305A0
#define CSidlScreenWnd__ConvertToRes_x                             0x959A10
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x930090
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92FD80
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92FE50
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92FF20
#define CSidlScreenWnd__DrawSidlPiece_x                            0x930B40
#define CSidlScreenWnd__EnableIniStorage_x                         0x931010
#define CSidlScreenWnd__GetSidlPiece_x                             0x930D30
#define CSidlScreenWnd__Init1_x                                    0x92F980
#define CSidlScreenWnd__LoadIniInfo_x                              0x931060
#define CSidlScreenWnd__LoadIniListWnd_x                           0x931BA0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92EDA0
#define CSidlScreenWnd__StoreIniInfo_x                             0x931720
#define CSidlScreenWnd__StoreIniVis_x                              0x931A80
#define CSidlScreenWnd__WndNotification_x                          0x930A50
#define CSidlScreenWnd__GetChildItem_x                             0x930F90
#define CSidlScreenWnd__HandleLButtonUp_x                          0x920860
#define CSidlScreenWnd__m_layoutCopy_x                             0x15D9180

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x698870
#define CSkillMgr__GetSkillCap_x                                   0x698A50
#define CSkillMgr__GetNameToken_x                                  0x697FF0
#define CSkillMgr__IsActivatedSkill_x                              0x698130
#define CSkillMgr__IsCombatSkill_x                                 0x698070

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9409C0
#define CSliderWnd__SetValue_x                                     0x940830
#define CSliderWnd__SetNumTicks_x                                  0x940890

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x801CA0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x949300
#define CStmlWnd__ParseSTML_x                                      0x94A610
#define CStmlWnd__CalculateHSBRange_x                              0x94A3E0
#define CStmlWnd__CalculateVSBRange_x                              0x94A350
#define CStmlWnd__CanBreakAtCharacter_x                            0x94E730
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94F3C0
#define CStmlWnd__ForceParseNow_x                                  0x9498A0
#define CStmlWnd__GetNextTagPiece_x                                0x94E690
#define CStmlWnd__GetSTMLText_x                                    0x50C7D0
#define CStmlWnd__GetVisibleText_x                                 0x9498C0
#define CStmlWnd__InitializeWindowVariables_x                      0x94F210
#define CStmlWnd__MakeStmlColorTag_x                               0x948970
#define CStmlWnd__MakeWndNotificationTag_x                         0x9489E0
#define CStmlWnd__SetSTMLText_x                                    0x947A20
#define CStmlWnd__StripFirstSTMLLines_x                            0x9504C0
#define CStmlWnd__UpdateHistoryString_x                            0x94F5D0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x946B70
#define CTabWnd__DrawCurrentPage_x                                 0x9472A0
#define CTabWnd__DrawTab_x                                         0x946FC0
#define CTabWnd__GetCurrentPage_x                                  0x946370
#define CTabWnd__GetPageInnerRect_x                                0x9465B0
#define CTabWnd__GetTabInnerRect_x                                 0x9464F0
#define CTabWnd__GetTabRect_x                                      0x9463A0
#define CTabWnd__InsertPage_x                                      0x9467C0
#define CTabWnd__RemovePage_x                                      0x946930
#define CTabWnd__SetPage_x                                         0x946630
#define CTabWnd__SetPageRect_x                                     0x946AB0
#define CTabWnd__UpdatePage_x                                      0x946E80
#define CTabWnd__GetPageFromTabIndex_x                             0x946F00
#define CTabWnd__GetCurrentTabIndex_x                              0x946360

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75EEF0
#define CPageWnd__SetTabText_x                                     0x945EC0
#define CPageWnd__FlashTab_x                                       0x945F20

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9010

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91D730
#define CTextureFont__GetTextExtent_x                              0x91D8F0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AC9E0
#define CHtmlComponentWnd__ValidateUri_x                           0x73D320
#define CHtmlWnd__SetClientCallbacks_x                             0x6382B0
#define CHtmlWnd__AddObserver_x                                    0x6382D0
#define CHtmlWnd__RemoveObserver_x                                 0x638330
#define Window__getProgress_x                                      0x8539C0
#define Window__getStatus_x                                        0x8539E0
#define Window__getURI_x                                           0x8539F0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x956820

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90A840

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9610
#define CXStr__CXStr1_x                                            0x4B7270
#define CXStr__CXStr3_x                                            0x8F1830
#define CXStr__dCXStr_x                                            0x4783C0
#define CXStr__operator_equal_x                                    0x8F1A60
#define CXStr__operator_equal1_x                                   0x8F1AA0
#define CXStr__operator_plus_equal1_x                              0x8F2530
#define CXStr__SetString_x                                         0x8F4420
#define CXStr__operator_char_p_x                                   0x8F1FA0
#define CXStr__GetChar_x                                           0x8F3D50
#define CXStr__Delete_x                                            0x8F3620
#define CXStr__GetUnicode_x                                        0x8F3DC0
#define CXStr__GetLength_x                                         0x4A8DC0
#define CXStr__Mid_x                                               0x47D5F0
#define CXStr__Insert_x                                            0x8F3E20
#define CXStr__FindNext_x                                          0x8F3A90

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93EC60
#define CXWnd__BringToTop_x                                        0x923FE0
#define CXWnd__Center_x                                            0x923B60
#define CXWnd__ClrFocus_x                                          0x923980
#define CXWnd__Destroy_x                                           0x923A20
#define CXWnd__DoAllDrawing_x                                      0x920010
#define CXWnd__DrawChildren_x                                      0x91FFE0
#define CXWnd__DrawColoredRect_x                                   0x920470
#define CXWnd__DrawTooltip_x                                       0x91EB40
#define CXWnd__DrawTooltipAtPoint_x                                0x91EC00
#define CXWnd__GetBorderFrame_x                                    0x9202D0
#define CXWnd__GetChildWndAt_x                                     0x924080
#define CXWnd__GetClientClipRect_x                                 0x922290
#define CXWnd__GetScreenClipRect_x                                 0x922340
#define CXWnd__GetScreenRect_x                                     0x9224C0
#define CXWnd__GetRelativeRect_x                                   0x922590
#define CXWnd__GetTooltipRect_x                                    0x9204C0
#define CXWnd__GetWindowTextA_x                                    0x49CCF0
#define CXWnd__IsActive_x                                          0x920BE0
#define CXWnd__IsDescendantOf_x                                    0x922EF0
#define CXWnd__IsReallyVisible_x                                   0x922F20
#define CXWnd__IsType_x                                            0x9246E0
#define CXWnd__Move_x                                              0x922F80
#define CXWnd__Move1_x                                             0x923040
#define CXWnd__ProcessTransition_x                                 0x923B10
#define CXWnd__Refade_x                                            0x923320
#define CXWnd__Resize_x                                            0x9235B0
#define CXWnd__Right_x                                             0x923DA0
#define CXWnd__SetFocus_x                                          0x923940
#define CXWnd__SetFont_x                                           0x9239B0
#define CXWnd__SetKeyTooltip_x                                     0x924510
#define CXWnd__SetMouseOver_x                                      0x921420
#define CXWnd__StartFade_x                                         0x922DD0
#define CXWnd__GetChildItem_x                                      0x9241F0
#define CXWnd__SetParent_x                                         0x922C80
#define CXWnd__Minimize_x                                          0x923620

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95AA90

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x926F20
#define CXWndManager__DrawWindows_x                                0x926F40
#define CXWndManager__GetKeyboardFlags_x                           0x929640
#define CXWndManager__HandleKeyboardMsg_x                          0x9291F0
#define CXWndManager__RemoveWnd_x                                  0x929870
#define CXWndManager__RemovePendingDeletionWnd_x                   0x929DD0

// CDBStr
#define CDBStr__GetString_x                                        0x547020

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFC40
#define EQ_Character__Cur_HP_x                                     0x4D2D10
#define EQ_Character__Cur_Mana_x                                   0x4DA450
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2CB0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3640
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3790
#define EQ_Character__GetHPRegen_x                                 0x4E0350
#define EQ_Character__GetEnduranceRegen_x                          0x4E0950
#define EQ_Character__GetManaRegen_x                               0x4E0D90
#define EQ_Character__Max_Endurance_x                              0x65EBE0
#define EQ_Character__Max_HP_x                                     0x4D2B40
#define EQ_Character__Max_Mana_x                                   0x65E9E0
#define EQ_Character__doCombatAbility_x                            0x660FD0
#define EQ_Character__UseSkill_x                                   0x4E2BA0
#define EQ_Character__GetConLevel_x                                0x6577D0
#define EQ_Character__IsExpansionFlag_x                            0x5BAA90
#define EQ_Character__TotalEffect_x                                0x4C6A50
#define EQ_Character__GetPCSpellAffect_x                           0x4C3A00
#define EQ_Character__SpellDuration_x                              0x4C3530
#define EQ_Character__MySpellDuration_x                            0x4B1F70
#define EQ_Character__GetAdjustedSkill_x                           0x4D5A90
#define EQ_Character__GetBaseSkill_x                               0x4D6A30
#define EQ_Character__CanUseItem_x                                 0x4DA760

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BD500

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x674F20

//PcClient
#define PcClient__vftable_x                                        0xAF21D8
#define PcClient__PcClient_x                                       0x654F40

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA6B0
#define CCharacterListWnd__EnterWorld_x                            0x4BA080
#define CCharacterListWnd__Quit_x                                  0x4B9DD0
#define CCharacterListWnd__UpdateList_x                            0x4BA270

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6394A0
#define EQ_Item__CreateItemTagString_x                             0x897C40
#define EQ_Item__IsStackable_x                                     0x89C8F0
#define EQ_Item__GetImageNum_x                                     0x8997D0
#define EQ_Item__CreateItemClient_x                                0x6386D0
#define EQ_Item__GetItemValue_x                                    0x89AAB0
#define EQ_Item__ValueSellMerchant_x                               0x89E280
#define EQ_Item__IsKeyRingItem_x                                   0x89C1F0
#define EQ_Item__CanGoInBag_x                                      0x6395C0
#define EQ_Item__IsEmpty_x                                         0x89BD40
#define EQ_Item__GetMaxItemCount_x                                 0x89AED0
#define EQ_Item__GetHeldItem_x                                     0x8996A0
#define EQ_Item__GetAugmentFitBySlot_x                             0x897480

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x565AD0
#define EQ_LoadingS__Array_x                                       0xC12130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65F4E0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A72A0
#define EQ_PC__GetCombatAbility_x                                  0x8A7910
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A7980
#define EQ_PC__GetItemRecastTimer_x                                0x661550
#define EQ_PC__HasLoreItem_x                                       0x657F90
#define EQ_PC__AlertInventoryChanged_x                             0x657110
#define EQ_PC__GetPcZoneClient_x                                   0x683F50
#define EQ_PC__RemoveMyAffect_x                                    0x664780
#define EQ_PC__GetKeyRingItems_x                                   0x8A8210
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A7FA0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A8510

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C0EF0
#define EQItemList__add_object_x                                   0x5EE520
#define EQItemList__add_item_x                                     0x5C1450
#define EQItemList__delete_item_x                                  0x5C14A0
#define EQItemList__FreeItemList_x                                 0x5C13A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x543B40

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x676820
#define EQPlayer__dEQPlayer_x                                      0x669B90
#define EQPlayer__DoAttack_x                                       0x67E6E0
#define EQPlayer__EQPlayer_x                                       0x66A250
#define EQPlayer__SetNameSpriteState_x                             0x66E530
#define EQPlayer__SetNameSpriteTint_x                              0x66F410
#define PlayerBase__HasProperty_j_x                                0x9896D0
#define EQPlayer__IsTargetable_x                                   0x989B70
#define EQPlayer__CanSee_x                                         0x9899D0
#define EQPlayer__CanSee1_x                                        0x989AA0
#define PlayerBase__GetVisibilityLineSegment_x                     0x989790

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6819E0
#define PlayerZoneClient__GetLevel_x                               0x683F90
#define PlayerZoneClient__IsValidTeleport_x                        0x5EF690
#define PlayerZoneClient__LegalPlayerRace_x                        0x55E870

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x679600
#define EQPlayerManager__GetSpawnByName_x                          0x6796B0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x679740

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63CC00
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63CC80
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63CCC0
#define KeypressHandler__ClearCommandStateArray_x                  0x63E0B0
#define KeypressHandler__HandleKeyDown_x                           0x63E0D0
#define KeypressHandler__HandleKeyUp_x                             0x63E170
#define KeypressHandler__SaveKeymapping_x                          0x63E5C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x775B40
#define MapViewMap__SaveEx_x                                       0x778F00
#define MapViewMap__SetZoom_x                                      0x77D5C0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BB570

// StringTable 
#define StringTable__getString_x                                   0x8B6380

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6643F0
#define PcZoneClient__RemovePetEffect_x                            0x664A20
#define PcZoneClient__HasAlternateAbility_x                        0x65E810
#define PcZoneClient__GetCurrentMod_x                              0x4E5CC0
#define PcZoneClient__GetModCap_x                                  0x4E5BC0
#define PcZoneClient__CanEquipItem_x                               0x65EEC0
#define PcZoneClient__GetItemByID_x                                0x6619C0
#define PcZoneClient__GetItemByItemClass_x                         0x661B10
#define PcZoneClient__RemoveBuffEffect_x                           0x664A40
#define PcZoneClient__BandolierSwap_x                              0x65FAA0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x6614F0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F4200

//IconCache
#define IconCache__GetIcon_x                                       0x717620

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70F0F0
#define CContainerMgr__CloseContainer_x                            0x70F3C0
#define CContainerMgr__OpenExperimentContainer_x                   0x70FE40

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CE170

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x631620

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76C000
#define CLootWnd__RequestLootSlot_x                                0x76B2D0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58D4F0
#define EQ_Spell__SpellAffects_x                                   0x58D960
#define EQ_Spell__SpellAffectBase_x                                0x58D720
#define EQ_Spell__IsStackable_x                                    0x4CA750
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA5A0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7930
#define EQ_Spell__IsSPAStacking_x                                  0x58E7B0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58DCC0
#define EQ_Spell__IsNoRemove_x                                     0x4CA730
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58E7C0
#define __IsResEffectSpell_x                                       0x4C9A80

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD1D0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C5C60

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x814FD0
#define CTargetWnd__WndNotification_x                              0x814810
#define CTargetWnd__RefreshTargetBuffs_x                           0x814AE0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x813970

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x819640
#define CTaskWnd__ConfirmAbandonTask_x                             0x81C280

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x541510
#define CTaskManager__HandleMessage_x                              0x53F950
#define CTaskManager__GetTaskStatus_x                              0x5415C0
#define CTaskManager__GetElementDescription_x                      0x541640

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x588630
#define EqSoundManager__PlayScriptMp3_x                            0x5888F0
#define EqSoundManager__SoundAssistPlay_x                          0x69C760
#define EqSoundManager__WaveInstancePlay_x                         0x69BCD0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x532870

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9453D0
#define CTextureAnimation__Draw_x                                  0x9455D0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x941330

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56D660
#define CAltAbilityData__GetMercMaxRank_x                          0x56D5F0
#define CAltAbilityData__GetMaxRank_x                              0x562A20

//CTargetRing
#define CTargetRing__Cast_x                                        0x62F730

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA580
#define CharacterBase__CreateItemGlobalIndex_x                     0x5191C0
#define CharacterBase__CreateItemIndex_x                           0x637860
#define CharacterBase__GetItemPossession_x                         0x505310
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CE2D0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CE330
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F6150
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F6980
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F6A30

//messages
#define msg_spell_worn_off_x                                       0x5B2A10
#define msg_new_text_x                                             0x5A73A0
#define __msgTokenTextParam_x                                      0x5B4CB0
#define msgTokenText_x                                             0x5B4F00

//SpellManager
#define SpellManager__vftable_x                                    0xADA544
#define SpellManager__SpellManager_x                               0x69FA90
#define Spellmanager__LoadTextSpells_x                             0x6A0380
#define SpellManager__GetSpellByGroupAndRank_x                     0x69FC60

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98D600

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x519840
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B8E70
#define ItemGlobalIndex__IsEquippedLocation_x                      0x6506B0
#define ItemGlobalIndex__IsValidIndex_x                            0x5198D0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C6600
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C6880

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7648B0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7137F0
#define CCursorAttachment__AttachToCursor1_x                       0x713830
#define CCursorAttachment__Deactivate_x                            0x714820

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x937F70
#define CSidlManagerBase__CreatePageWnd_x                          0x937770
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9339F0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x933980

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9553D0
#define CEQSuiteTextureLoader__GetTexture_x                        0x955090

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x516740
#define CFindItemWnd__WndNotification_x                            0x517220
#define CFindItemWnd__Update_x                                     0x517D60
#define CFindItemWnd__PickupSelectedItem_x                         0x515F60

//IString
#define IString__Append_x                                          0x506BC0

//Camera
#define CDisplay__cameraType_x                                     0xDE9E28
#define EverQuest__Cameras_x                                       0xEA5084

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51F290
#define LootFiltersManager__GetItemFilterData_x                    0x51EBA0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51EBD0
#define LootFiltersManager__SetItemLootFilter_x                    0x51EDF0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BBF30

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x993240
#define CResolutionHandler__GetWindowedStyle_x                     0x6972A0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70BD20

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DBC40
#define CDistillerInfo__Instance_x                                 0x8DBBE0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72ACA0
#define CGroupWnd__UpdateDisplay_x                                 0x729FF0

//ItemBase
#define ItemBase__IsLore_x                                         0x89C2A0
#define ItemBase__IsLoreEquipped_x                                 0x89C320

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EE480
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EE5C0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EE620

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C680
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68FFE0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50CE80

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F91A0
#define FactionManagerClient__HandleFactionMessage_x               0x4F9810
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F9E10
#define FactionManagerClient__GetMaxFaction_x                      0x4F9E2F
#define FactionManagerClient__GetMinFaction_x                      0x4F9DE0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5052E0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91C6E0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C000

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x5055D0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56CB10

//CTargetManager
#define CTargetManager__Get_x                                      0x6A3300

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C680

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8DD0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C1340

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF4271C

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BFA00
#define CAAWnd__UpdateSelected_x                                   0x6BC270
#define CAAWnd__Update_x                                           0x6BED20

//CXRect
#define CXRect__operator_and_x                                     0x721D90

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x483200

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
