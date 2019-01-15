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
#define __ExpectedVersionDate                                     "Dec 10 2018"
#define __ExpectedVersionTime                                     "04:21:11"
#define __ActualVersionDate_x                                      0xAD2184
#define __ActualVersionTime_x                                      0xAD2178

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x615EA0
#define __MemChecker1_x                                            0x8EB260
#define __MemChecker2_x                                            0x6A53C0
#define __MemChecker3_x                                            0x6A5310
#define __MemChecker4_x                                            0x8423B0
#define __EncryptPad0_x                                            0xC06340
#define __EncryptPad1_x                                            0xC645D0
#define __EncryptPad2_x                                            0xC16EC8
#define __EncryptPad3_x                                            0xC16AC8
#define __EncryptPad4_x                                            0xC54E40
#define __EncryptPad5_x                                            0x1035AE8
#define __AC1_x                                                    0x7FEE86
#define __AC2_x                                                    0x5D0CFF
#define __AC3_x                                                    0x5D7B8F
#define __AC4_x                                                    0x5DB9B0
#define __AC5_x                                                    0x5E1C20
#define __AC6_x                                                    0x5E61F6
#define __AC7_x                                                    0x5D0770
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E8A344

// Direct Input
#define DI8__Main_x                                                0x1035B0C
#define DI8__Keyboard_x                                            0x1035B10
#define DI8__Mouse_x                                               0xF2B450
#define DI8__Mouse_Copy_x                                          0xE891AC
#define DI8__Mouse_Check_x                                         0xF2B774
#define __AutoSkillArray_x                                         0xE8A0C4
#define __Attack_x                                                 0xF27ECB
#define __Autofire_x                                               0xF27ECC
#define __BindList_x                                               0xBF4F20
#define g_eqCommandStates_x                                        0xBF5C90
#define __Clicks_x                                                 0xE89264
#define __CommandList_x                                            0xBF6848
#define __CurrentMapLabel_x                                        0x103DA74
#define __CurrentSocial_x                                          0xBDF730
#define __DoAbilityList_x                                          0xEBF9EC
#define __do_loot_x                                                0x59E150
#define __DrawHandler_x                                            0x16BA448
#define __GroupCount_x                                             0xE7945A
#define __Guilds_x                                                 0xE7F9B8
#define __gWorld_x                                                 0xE7BCC8
#define __HWnd_x                                                   0xF2B454
#define __heqmain_x                                                0x1035AD0
#define __InChatMode_x                                             0xE89194
#define __LastTell_x                                               0xE8B0E8
#define __LMouseHeldTime_x                                         0xE892D0
#define __Mouse_x                                                  0x1035AF4
#define __MouseLook_x                                              0xE8922A
#define __MouseEventTime_x                                         0xF28980
#define __gpbCommandEvent_x                                        0xE7B77C
#define __NetStatusToggle_x                                        0xE8922D
#define __PCNames_x                                                0xE8A6A4
#define __RangeAttackReady_x                                       0xE8A3A8
#define __RMouseHeldTime_x                                         0xE892CC
#define __RunWalkState_x                                           0xE89198
#define __ScreenMode_x                                             0xDC7AA4
#define __ScreenX_x                                                0xE8914C
#define __ScreenY_x                                                0xE89148
#define __ScreenXMax_x                                             0xE89150
#define __ScreenYMax_x                                             0xE89154
#define __ServerHost_x                                             0xE7B9B3
#define __ServerName_x                                             0xEBF9AC
#define __ShiftKeyDown_x                                           0xE89824
#define __ShowNames_x                                              0xE8A564
#define __Socials_x                                                0xEBFAAC
#define __SubscriptionType_x                                       0x107F5C4
#define __TargetAggroHolder_x                                      0x1040430
#define __ZoneType_x                                               0xE89628
#define __GroupAggro_x                                             0x1040470
#define __LoginName_x                                              0x1036364
#define __Inviter_x                                                0xF27E48
#define __AttackOnAssist_x                                         0xE8A520
#define __UseTellWindows_x                                         0xE8A83C
#define __gfMaxZoomCameraDistance_x                                0xAC7680
#define __gfMaxCameraDistance_x                                    0xAF4AF0
#define __pulAutoRun_x                                             0xE89248
#define __pulForward_x                                             0xE8A874
#define __pulBackward_x                                            0xE8A878
#define __pulTurnRight_x                                           0xE8A87C
#define __pulTurnLeft_x                                            0xE8A880
#define __pulStrafeLeft_x                                          0xE8A884
#define __pulStrafeRight_x                                         0xE8A888
//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE7BD50
#define instEQZoneInfo_x                                           0xE89420
#define instKeypressHandler_x                                      0xF28930
#define pinstActiveBanker_x                                        0xE7B85C
#define pinstActiveCorpse_x                                        0xE7B854
#define pinstActiveGMaster_x                                       0xE7B858
#define pinstActiveMerchant_x                                      0xE7B850
#define pinstAggroInfo_x                                           0xC7AE08
#define pinstAltAdvManager_x                                       0xDC86F8
#define pinstAuraMgr_x                                             0xC96988
#define pinstBandageTarget_x                                       0xE7B86C
#define pinstCamActor_x                                            0xDC7A98
#define pinstCDBStr_x                                              0xDC742C
#define pinstCDisplay_x                                            0xE7BABC
#define pinstCEverQuest_x                                          0x1035C28
#define pinstEverQuestInfo_x                                       0xE89140
#define pinstCharData_x                                            0xE7BCD0
#define pinstCharSpawn_x                                           0xE7B8A4
#define pinstControlledMissile_x                                   0xE7BCCC
#define pinstControlledPlayer_x                                    0xE7B8A4
#define pinstCResolutionHandler_x                                  0x16BA678
#define pinstCSidlManager_x                                        0x16B950C
#define pinstCXWndManager_x                                        0x16B9500
#define instDynamicZone_x                                          0xE7F890
#define pinstDZMember_x                                            0xE7F9A0
#define pinstDZTimerInfo_x                                         0xE7F9A4
#define pinstEQItemList_x                                          0xE77F40
#define pinstEQObjectList_x                                        0xE79130
#define instEQMisc_x                                               0xDC7368
#define pinstEQSoundManager_x                                      0xDC8F58
#define pinstEQSpellStrings_x                                      0xC88F40
#define instExpeditionLeader_x                                     0xE7F8DA
#define instExpeditionName_x                                       0xE7F91A
#define pinstGroup_x                                               0xE79456
#define pinstImeManager_x                                          0x16B9504
#define pinstLocalPlayer_x                                         0xE7B84C
#define pinstMercenaryData_x                                       0xF2912C
#define pinstMercenaryStats_x                                      0x104057C
#define pinstMercAltAbilities_x                                    0xDC8CC8
#define pinstModelPlayer_x                                         0xE7B864
#define pinstPCData_x                                              0xE7BCD0
#define pinstRealEstateItems_x                                     0xF2A610
#define pinstSkillMgr_x                                            0xF2A6E0
#define pinstSpawnManager_x                                        0xF29CD0
#define pinstSpellManager_x                                        0xF2A8B8
#define pinstSpellSets_x                                           0xF20AF4
#define pinstStringTable_x                                         0xE7B650
#define pinstSwitchManager_x                                       0xE792F0
#define pinstTarget_x                                              0xE7B8A0
#define pinstTargetObject_x                                        0xE7B8AC
#define pinstTargetSwitch_x                                        0xE7BCF0
#define pinstTaskMember_x                                          0xDC71FC
#define pinstTrackTarget_x                                         0xE7B8A8
#define pinstTradeTarget_x                                         0xE7B860
#define instTributeActive_x                                        0xDC738D
#define pinstViewActor_x                                           0xDC7A94
#define pinstWorldData_x                                           0xE7B76C
#define pinstZoneAddr_x                                            0xE896C0
#define pinstPlayerPath_x                                          0xF29D68
#define pinstTargetIndicator_x                                     0xF2AB20
#define pinstCTargetManager_x                                      0xF2ABB8
#define EQObject_Top_x                                             0xE7B80C

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDC7554
#define pinstCAchievementsWnd_x                                    0xDC7544
#define pinstCActionsWnd_x                                         0xDC75B8
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDC7A58
#define pinstCAdvancedLootWnd_x                                    0xDC759C
#define pinstCAdventureLeaderboardWnd_x                            0x1037248
#define pinstCAdventureRequestWnd_x                                0x10372F8
#define pinstCAdventureStatsWnd_x                                  0x10373A8
#define pinstCAggroMeterWnd_x                                      0xDC7AD8
#define pinstCAlarmWnd_x                                           0xDC7B48
#define pinstCAlertHistoryWnd_x                                    0xDC7500
#define pinstCAlertStackWnd_x                                      0xDC7AF0
#define pinstCAlertWnd_x                                           0xDC7B10
#define pinstCAltStorageWnd_x                                      0x1037708
#define pinstCAudioTriggersWindow_x                                0xC7B298
#define pinstCAuraWnd_x                                            0xDC7AD4
#define pinstCAvaZoneWnd_x                                         0xDC7504
#define pinstCBandolierWnd_x                                       0xDC7B18
#define pinstCBankWnd_x                                            0xDC74FC
#define pinstCBarterMerchantWnd_x                                  0x1038948
#define pinstCBarterSearchWnd_x                                    0x10389F8
#define pinstCBarterWnd_x                                          0x1038AA8
#define pinstCBazaarConfirmationWnd_x                              0xDC7AE8
#define pinstCBazaarSearchWnd_x                                    0xDC75DC
#define pinstCBazaarWnd_x                                          0xDC7B1C
#define pinstCBlockedBuffWnd_x                                     0xDC74DC
#define pinstCBlockedPetBuffWnd_x                                  0xDC7510
#define pinstCBodyTintWnd_x                                        0xDC7ABC
#define pinstCBookWnd_x                                            0xDC7B3C
#define pinstCBreathWnd_x                                          0xDC7558
#define pinstCBuffWindowNORMAL_x                                   0xDC7D58
#define pinstCBuffWindowSHORT_x                                    0xDC7D5C
#define pinstCBugReportWnd_x                                       0xDC754C
#define pinstCButtonWnd_x                                          0x16B9730
#define pinstCCastingWnd_x                                         0xDC7548
#define pinstCCastSpellWnd_x                                       0xDC7A54
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDC755C
#define pinstCChatWindowManager_x                                  0x1039568
#define pinstCClaimWnd_x                                           0x10396C0
#define pinstCColorPickerWnd_x                                     0xDC7588
#define pinstCCombatAbilityWnd_x                                   0xDC7AE4
#define pinstCCombatSkillsSelectWnd_x                              0xDC75B0
#define pinstCCompassWnd_x                                         0xDC7A8C
#define pinstCConfirmationDialog_x                                 0x103E5C0
#define pinstCContainerMgr_x                                       0xDC7AEC
#define pinstCContextMenuManager_x                                 0x16B94C0
#define pinstCCursorAttachment_x                                   0xDC7540
#define pinstCDistillerInfo_x                                      0x103CFCC
#define pinstCDynamicZoneWnd_x                                     0x1039C88
#define pinstCEditLabelWnd_x                                       0xDC7B4C
#define pinstCEQMainWnd_x                                          0x1039ED0
#define pinstCEventCalendarWnd_x                                   0xDC7574
#define pinstCExtendedTargetWnd_x                                  0xDC7AC8
#define pinstCFacePick_x                                           0xDC7580
#define pinstCFactionWnd_x                                         0xDC753C
#define pinstCFellowshipWnd_x                                      0x103A0D0
#define pinstCFileSelectionWnd_x                                   0xDC7590
#define pinstCFindItemWnd_x                                        0xDC7B38
#define pinstCFindLocationWnd_x                                    0x103A228
#define pinstCFriendsWnd_x                                         0xDC75D4
#define pinstCGemsGameWnd_x                                        0xDC7B14
#define pinstCGiveWnd_x                                            0xDC7B40
#define pinstCGroupSearchFiltersWnd_x                              0xDC7AF8
#define pinstCGroupSearchWnd_x                                     0x103A620
#define pinstCGroupWnd_x                                           0x103A6D0
#define pinstCGuildBankWnd_x                                       0xE8A504
#define pinstCGuildCreationWnd_x                                   0x103A830
#define pinstCGuildMgmtWnd_x                                       0x103A8E0
#define pinstCharacterCreation_x                                   0xDC7ADC
#define pinstCHelpWnd_x                                            0xDC7A88
#define pinstCHeritageSelectionWnd_x                               0xDC7594
#define pinstCHotButtonWnd_x                                       0x103CA38
#define pinstCHotButtonWnd1_x                                      0x103CA38
#define pinstCHotButtonWnd2_x                                      0x103CA3C
#define pinstCHotButtonWnd3_x                                      0x103CA40
#define pinstCHotButtonWnd4_x                                      0x103CA44
#define pinstCIconSelectionWnd_x                                   0xDC7520
#define pinstCInspectWnd_x                                         0xDC751C
#define pinstCInventoryWnd_x                                       0xDC7B20
#define pinstCInvSlotMgr_x                                         0xDC7AB0
#define pinstCItemDisplayManager_x                                 0x103CFC8
#define pinstCItemExpTransferWnd_x                                 0x103D0F8
#define pinstCItemFuseWnd_x                                        0xDC7534
#define pinstCItemOverflowWnd_x                                    0xDC7644
#define pinstCJournalCatWnd_x                                      0xDC75A8
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDC756C
#define pinstCKeyRingWnd_x                                         0xDC74D8
#define pinstCLargeDialogWnd_x                                     0x103F240
#define pinstCLayoutCopyWnd_x                                      0x103D448
#define pinstCLFGuildWnd_x                                         0x103D4F8
#define pinstCLoadskinWnd_x                                        0xDC7B2C
#define pinstCLootFiltersCopyWnd_x                                 0xC972C0
#define pinstCLootFiltersWnd_x                                     0xDC7B34
#define pinstCLootSettingsWnd_x                                    0xDC7D54
#define pinstCLootWnd_x                                            0xDC7578
#define pinstCMailAddressBookWnd_x                                 0xDC7514
#define pinstCMailCompositionWnd_x                                 0xDC74EC
#define pinstCMailIgnoreListWnd_x                                  0xDC7518
#define pinstCMailWnd_x                                            0xDC74CC
#define pinstCManageLootWnd_x                                      0xDC8B70
#define pinstCMapToolbarWnd_x                                      0xDC7B28
#define pinstCMapViewWnd_x                                         0xDC7B00
#define pinstCMarketplaceWnd_x                                     0xDC757C
#define pinstCMerchantWnd_x                                        0xDC75AC
#define pinstCMIZoneSelectWnd_x                                    0x103DD30
#define pinstCMusicPlayerWnd_x                                     0xDC74D4
#define pinstCNameChangeMercWnd_x                                  0xDC7AC0
#define pinstCNameChangePetWnd_x                                   0xDC7A80
#define pinstCNameChangeWnd_x                                      0xDC7560
#define pinstCNoteWnd_x                                            0xDC7A60
#define pinstCObjectPreviewWnd_x                                   0xDC75A0
#define pinstCOptionsWnd_x                                         0xDC7B30
#define pinstCPetInfoWnd_x                                         0xDC74F0
#define pinstCPetitionQWnd_x                                       0xDC75C0
//#define pinstCPlayerCustomizationWnd_x                           0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDC7AB8
#define pinstCPlayerWnd_x                                          0xDC75BC
#define pinstCPopupWndManager_x                                    0x103E5C0
#define pinstCProgressionSelectionWnd_x                            0x103E670
#define pinstCPurchaseGroupWnd_x                                   0xDC7A4C
#define pinstCPurchaseWnd_x                                        0xDC75B4
#define pinstCPvPLeaderboardWnd_x                                  0x103E720
#define pinstCPvPStatsWnd_x                                        0x103E7D0
#define pinstCQuantityWnd_x                                        0xDC7528
#define pinstCRaceChangeWnd_x                                      0xDC7584
#define pinstCRaidOptionsWnd_x                                     0xDC7AFC
#define pinstCRaidWnd_x                                            0xDC752C
#define pinstCRealEstateItemsWnd_x                                 0xDC7550
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDC7570
#define pinstCRealEstateManageWnd_x                                0xDC74C8
#define pinstCRealEstateNeighborhoodWnd_x                          0xDC74E0
#define pinstCRealEstatePlotSearchWnd_x                            0xDC7508
#define pinstCRealEstatePurchaseWnd_x                              0xDC7530
#define pinstCRespawnWnd_x                                         0xDC7AF4
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDC7ACC
#define pinstCSendMoneyWnd_x                                       0xDC7D50
#define pinstCServerListWnd_x                                      0xDC74F8
#define pinstCSkillsSelectWnd_x                                    0xDC758C
#define pinstCSkillsWnd_x                                          0xDC7568
#define pinstCSocialEditWnd_x                                      0xDC7538
#define pinstCSocialWnd_x                                          0xDC7AD0
#define pinstCSpellBookWnd_x                                       0xDC7AC4
#define pinstCStoryWnd_x                                           0xDC7A5C
#define pinstCTargetOfTargetWnd_x                                  0x1040600
#define pinstCTargetWnd_x                                          0xDC74E8
#define pinstCTaskOverlayWnd_x                                     0xDC750C
#define pinstCTaskSelectWnd_x                                      0x1040758
#define pinstCTaskManager_x                                        0xC97AC0
#define pinstCTaskTemplateSelectWnd_x                              0x1040808
#define pinstCTaskWnd_x                                            0x10408B8
#define pinstCTextEntryWnd_x                                       0xDC7A90
#define pinstCTextOverlay_x                                        0xC7B5A8
#define pinstCTimeLeftWnd_x                                        0xDC7598
#define pinstCTipWndCONTEXT_x                                      0x1040ABC
#define pinstCTipWndOFDAY_x                                        0x1040AB8
#define pinstCTitleWnd_x                                           0x1040B68
#define pinstCTrackingWnd_x                                        0xDC74F4
#define pinstCTradeskillWnd_x                                      0x1040CD0
#define pinstCTradeWnd_x                                           0xDC7AB4
#define pinstCTrainWnd_x                                           0xDC7524
#define pinstCTributeBenefitWnd_x                                  0x1040ED0
#define pinstCTributeMasterWnd_x                                   0x1040F80
#define pinstCTributeTrophyWnd_x                                   0x1041030
#define pinstCVideoModesWnd_x                                      0xDC7AE0
#define pinstCVoiceMacroWnd_x                                      0xF2B0E8
#define pinstCVoteResultsWnd_x                                     0xDC7A50
#define pinstCVoteWnd_x                                            0xDC75C4
#define pinstCWebManager_x                                         0xF2B24C
#define pinstCZoneGuideWnd_x                                       0xDC74D0
#define pinstCZonePathWnd_x                                        0xDC74E4

#define pinstEQSuiteTextureLoader_x                                0xC660A0
#define pinstItemIconCache_x                                       0x1039E88
#define pinstLootFiltersManager_x                                  0xC97370
#define pinstRewardSelectionWnd_x                                  0x103EF18

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC16ABC
#define __CastRay_x                                                0x599670
#define __CastRay2_x                                               0x5996C0
#define __ConvertItemTags_x                                        0x5B42F0
#define __CrashHandler_x                                           0x84BDA0
#define __EQGetTime_x                                              0x8EAD50
#define __ExecuteCmd_x                                             0x591FB0
#define __FixHeading_x                                             0x97BC90
#define __get_bearing_x                                            0x5991C0
#define __get_melee_range_x                                        0x5998B0
#define __GetAnimationCache_x                                      0x708EC0
#define __GetGaugeValueFromEQ_x                                    0x7FD690
#define __GetLabelFromEQ_x                                         0x7FEE10
#define __GetXTargetType_x                                         0x97D6F0
#define __HandleMouseWheel_x                                       0x6A5470
#define __HeadingDiff_x                                            0x97BD00
#define __HelpPath_x                                               0xF2859C
#define __LoadFrontEnd_x                                           0x6A1220
#define __NewUIINI_x                                               0x7FD360
#define __pCrashHandler_x                                          0x105E420
#define __ProcessGameEvents_x                                      0x5F7500
#define __ProcessMouseEvent_x                                      0x5F6CC0
#define __SaveColors_x                                             0x542900
#define __STMLToText_x                                             0x91EA70
#define __ToggleKeyRingItem_x                                      0x505BF0
#define CrashDetected_x                                            0x6A2D10
#define DrawNetStatus_x                                            0x6233F0
#define Expansion_HoT_x                                            0xE8A50C
#define Teleport_Table_Size_x                                      0xE7B808
#define Teleport_Table_x                                           0xE79648
#define Util__FastTime_x                                           0x8EA910
#define wwsCrashReportCheckForUploader_x                           0x84CAA0
#define wwsCrashReportPlatformLaunchUploader_x                     0x84F160

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B5B0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x494430
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4941F0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54A350
#define AltAdvManager__IsAbilityReady_x                            0x5492A0
#define AltAdvManager__GetAAById_x                                 0x5494A0
#define AltAdvManager__CanTrainAbility_x                           0x549510
#define AltAdvManager__CanSeeAbility_x                             0x549870

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C7530
#define CharacterZoneClient__HasSkill_x                            0x4D2200
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3920
#define CharacterZoneClient__IsStackBlocked_x                      0x4BB970
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B80F0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D62C0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D63A0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D6480
#define CharacterZoneClient__FindAffectSlot_x                      0x4C0450
#define CharacterZoneClient__BardCastBard_x                        0x4C30C0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B81C0
#define CharacterZoneClient__GetEffect_x                           0x4B8030
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C1450
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C1520
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1570
#define CharacterZoneClient__CalcAffectChange_x                    0x4C16C0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1890
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4AFF70
#define CharacterZoneClient__FindItemByGuid_x                      0x4D4890
#define CharacterZoneClient__FindItemByRecord_x                    0x0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6CB220
#define CBankWnd__WndNotification_x                                0x6CB000

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D8B20

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x605C80
#define CButtonWnd__CButtonWnd_x                                   0x91AE60

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F7800
#define CChatManager__InitContextMenu_x                            0x6F18A0
#define CChatManager__FreeChatWindow_x                             0x6F6710
#define CChatManager__GetLockedActiveChatWindow_x                  0x6FB170
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F75A0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x92F7B0
#define CContextMenu__dCContextMenu_x                              0x92F9E0
#define CContextMenu__AddMenuItem_x                                0x92F9F0
#define CContextMenu__RemoveMenuItem_x                             0x92FD00
#define CContextMenu__RemoveAllMenuItems_x                         0x92FD20
#define CContextMenu__CheckMenuItem_x                              0x92FDA0
#define CContextMenu__SetMenuItem_x                                0x92FC20
#define CContextMenu__AddSeparator_x                               0x92FB80

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x930330
#define CContextMenuManager__RemoveMenu_x                          0x9303A0
#define CContextMenuManager__PopupMenu_x                           0x930460
#define CContextMenuManager__Flush_x                               0x9302D0
#define CContextMenuManager__GetMenu_x                             0x496600
#define CContextMenuManager__CreateDefaultMenu_x                   0x703670

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CB540
#define CChatService__GetFriendName_x                              0x8CB550

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F7D70
#define CChatWindow__Clear_x                                       0x6F8DD0
#define CChatWindow__WndNotification_x                             0x6F9340

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x92CC30
#define CComboWnd__Draw_x                                          0x92C140
#define CComboWnd__GetCurChoice_x                                  0x92CA70
#define CComboWnd__GetListRect_x                                   0x92C5E0
#define CComboWnd__GetTextRect_x                                   0x92CCA0
#define CComboWnd__InsertChoice_x                                  0x92C770
#define CComboWnd__SetColors_x                                     0x92C740
#define CComboWnd__SetChoice_x                                     0x92CA40
#define CComboWnd__GetItemCount_x                                  0x92CA80
#define CComboWnd__GetCurChoiceText_x                              0x92CAC0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x701060
#define CContainerWnd__vftable_x                                   0xADB430
#define CContainerWnd__SetContainer_x                              0x7025D0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x5426C0
#define CDisplay__GetClickedActor_x                                0x535670
#define CDisplay__GetUserDefinedColor_x                            0x52DD50
#define CDisplay__GetWorldFilePath_x                               0x5370C0
#define CDisplay__is3dON_x                                         0x532340
#define CDisplay__ReloadUI_x                                       0x53C7E0
#define CDisplay__WriteTextHD2_x                                   0x532120
#define CDisplay__TrueDistance_x                                   0x538D20
#define CDisplay__SetViewActor_x                                   0x534FC0
#define CDisplay__GetFloorHeight_x                                 0x532400
#define CDisplay__SetRenderWindow_x                                0x530D30
#define CDisplay__ToggleScreenshotMode_x                           0x534A90

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x94F430

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x933EA0
#define CEditWnd__GetCharIndexPt_x                                 0x934DA0
#define CEditWnd__GetDisplayString_x                               0x934C40
#define CEditWnd__GetHorzOffset_x                                  0x9334D0
#define CEditWnd__GetLineForPrintableChar_x                        0x935FA0
#define CEditWnd__GetSelStartPt_x                                  0x935050
#define CEditWnd__GetSTMLSafeText_x                                0x934A60
#define CEditWnd__PointFromPrintableChar_x                         0x935BD0
#define CEditWnd__SelectableCharFromPoint_x                        0x935D40
#define CEditWnd__SetEditable_x                                    0x935120

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E5720
#define CEverQuest__ClickedPlayer_x                                0x5D7970
#define CEverQuest__CreateTargetIndicator_x                        0x5F47B0
#define CEverQuest__DeleteTargetIndicator_x                        0x5F4840
#define CEverQuest__DoTellWindow_x                                 0x4E34E0
#define CEverQuest__OutputTextToLog_x                              0x4E3710
#define CEverQuest__DropHeldItemOnGround_x                         0x5CD230
#define CEverQuest__dsp_chat_x                                     0x4E3AA0
#define CEverQuest__trimName_x                                     0x5F0B30
#define CEverQuest__Emote_x                                        0x5E5F30
#define CEverQuest__EnterZone_x                                    0x5DFFD0
#define CEverQuest__GetBodyTypeDesc_x                              0x5EA3D0
#define CEverQuest__GetClassDesc_x                                 0x5EAA10
#define CEverQuest__GetClassThreeLetterCode_x                      0x5EB010
#define CEverQuest__GetDeityDesc_x                                 0x5F3100
#define CEverQuest__GetLangDesc_x                                  0x5EB1D0
#define CEverQuest__GetRaceDesc_x                                  0x5EA9F0
#define CEverQuest__InterpretCmd_x                                 0x5F36D0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D1420
#define CEverQuest__LMouseUp_x                                     0x5CF7A0
#define CEverQuest__RightClickedOnPlayer_x                         0x5D1D00
#define CEverQuest__RMouseUp_x                                     0x5D0730
#define CEverQuest__SetGameState_x                                 0x5CCFC0
#define CEverQuest__UPCNotificationFlush_x                         0x5F0A30
#define CEverQuest__IssuePetCommand_x                              0x5EC5D0
#define CEverQuest__ReportSuccessfulHit_x                          0x5E7330

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x713040
#define CGaugeWnd__CalcLinesFillRect_x                             0x7130A0
#define CGaugeWnd__Draw_x                                          0x712730

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACC60
#define CGuild__GetGuildName_x                                     0x4ABD40
#define CGuild__GetGuildIndex_x                                    0x4AC0D0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x72E430

//CHotButton
#define CHotButton__SetButtonSize_x                                0x606040

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x73B440
#define CInvSlotMgr__MoveItem_x                                    0x73A160
#define CInvSlotMgr__SelectSlot_x                                  0x73B510

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x738A10
#define CInvSlot__SliderComplete_x                                 0x736770
#define CInvSlot__GetItemBase_x                                    0x7360E0
#define CInvSlot__UpdateItem_x                                     0x736250

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x73CE60
#define CInvSlotWnd__CInvSlotWnd_x                                 0x73C130
#define CInvSlotWnd__HandleLButtonUp_x                             0x73C9E0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F9870
#define CItemDisplayWnd__UpdateStrings_x                           0x74B150
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x745040
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x745570
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x74B760
#define CItemDisplayWnd__AboutToShow_x                             0x74AD90
#define CItemDisplayWnd__WndNotification_x                         0x74CCB0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x831250

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x750E10

// CLabel 
#define CLabel__Draw_x                                             0x756880

// CListWnd
#define CListWnd__CListWnd_x                                       0x905250
#define CListWnd__dCListWnd_x                                      0x905570
#define CListWnd__AddColumn_x                                      0x9098A0
#define CListWnd__AddColumn1_x                                     0x9098F0
#define CListWnd__AddLine_x                                        0x909C80
#define CListWnd__AddString_x                                      0x909A80
#define CListWnd__CalculateFirstVisibleLine_x                      0x909660
#define CListWnd__CalculateVSBRange_x                              0x909430
#define CListWnd__ClearSel_x                                       0x90A460
#define CListWnd__ClearAllSel_x                                    0x90A4C0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x90AEF0
#define CListWnd__Compare_x                                        0x908D80
#define CListWnd__Draw_x                                           0x905670
#define CListWnd__DrawColumnSeparators_x                           0x907E50
#define CListWnd__DrawHeader_x                                     0x9082C0
#define CListWnd__DrawItem_x                                       0x9086C0
#define CListWnd__DrawLine_x                                       0x907FC0
#define CListWnd__DrawSeparator_x                                  0x907EF0
#define CListWnd__EnableLine_x                                     0x907720
#define CListWnd__EnsureVisible_x                                  0x90AE10
#define CListWnd__ExtendSel_x                                      0x90A390
#define CListWnd__GetColumnMinWidth_x                              0x907260
#define CListWnd__GetColumnWidth_x                                 0x9071D0
#define CListWnd__GetCurSel_x                                      0x906B60
#define CListWnd__GetItemAtPoint_x                                 0x9079A0
#define CListWnd__GetItemAtPoint1_x                                0x907A10
#define CListWnd__GetItemData_x                                    0x906BE0
#define CListWnd__GetItemHeight_x                                  0x906FA0
#define CListWnd__GetItemIcon_x                                    0x906D70
#define CListWnd__GetItemRect_x                                    0x907810
#define CListWnd__GetItemText_x                                    0x906C20
#define CListWnd__GetSelList_x                                     0x90A510
#define CListWnd__GetSeparatorRect_x                               0x907C50
#define CListWnd__InsertLine_x                                     0x90A070
#define CListWnd__RemoveLine_x                                     0x90A1C0
#define CListWnd__SetColors_x                                      0x909410
#define CListWnd__SetColumnJustification_x                         0x909140
#define CListWnd__SetColumnWidth_x                                 0x909060
#define CListWnd__SetCurSel_x                                      0x90A2D0
#define CListWnd__SetItemColor_x                                   0x90AAC0
#define CListWnd__SetItemData_x                                    0x90AA80
#define CListWnd__SetItemText_x                                    0x90A690
#define CListWnd__ShiftColumnSeparator_x                           0x909200
#define CListWnd__Sort_x                                           0x908F00
#define CListWnd__ToggleSel_x                                      0x90A300
#define CListWnd__SetColumnsSizable_x                              0x0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x76BE40
#define CMapViewWnd__GetWorldCoordinates_x                         0x76A550
#define CMapViewWnd__HandleLButtonDown_x                           0x7675B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x78F0E0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x78F9C0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x78FF00
#define CMerchantWnd__SelectRecoverySlot_x                         0x792D40
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x78DAC0
#define CMerchantWnd__SelectBuySellSlot_x                          0x798940
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x78ED10

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8993C0
#define CPacketScrambler__hton_x                                   0x8993B0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x924080
#define CSidlManager__FindScreenPieceTemplate_x                    0x924490
#define CSidlManager__FindScreenPieceTemplate1_x                   0x924280
#define CSidlManager__CreateLabel_x                                0x7F0BF0
#define CSidlManager__CreateXWndFromTemplate_x                     0x927560
#define CSidlManager__CreateXWndFromTemplate1_x                    0x927740
#define CSidlManager__CreateXWnd_x                                 0x7F0B20
#define CSidlManager__CreateHotButtonWnd_x                         0x7F10F0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x920BF0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x920AE0
#define CSidlScreenWnd__ConvertToRes_x                             0x946270
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x920570
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x920260
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x920330
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x920400
#define CSidlScreenWnd__DrawSidlPiece_x                            0x921090
#define CSidlScreenWnd__EnableIniStorage_x                         0x921560
#define CSidlScreenWnd__GetSidlPiece_x                             0x921280
#define CSidlScreenWnd__Init1_x                                    0x91FE50
#define CSidlScreenWnd__LoadIniInfo_x                              0x9215B0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9220F0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x91F250
#define CSidlScreenWnd__StoreIniInfo_x                             0x921C70
#define CSidlScreenWnd__StoreIniVis_x                              0x921FD0
#define CSidlScreenWnd__WndNotification_x                          0x920FA0
#define CSidlScreenWnd__GetChildItem_x                             0x9214E0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x910D20
#define CSidlScreenWnd__m_layoutCopy_x                             0x16B9390

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66A2B0
#define CSkillMgr__GetSkillCap_x                                   0x66A490
#define CSkillMgr__GetNameToken_x                                  0x669A40
#define CSkillMgr__IsActivatedSkill_x                              0x669B80
#define CSkillMgr__IsCombatSkill_x                                 0x669AC0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x931120
#define CSliderWnd__SetValue_x                                     0x930F90
#define CSliderWnd__SetNumTicks_x                                  0x930FF0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7F6AE0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x937F30
#define CStmlWnd__CalculateHSBRange_x                              0x938FE0
#define CStmlWnd__CalculateVSBRange_x                              0x938F50
#define CStmlWnd__CanBreakAtCharacter_x                            0x93D350
#define CStmlWnd__FastForwardToEndOfTag_x                          0x93DFE0
#define CStmlWnd__ForceParseNow_x                                  0x9384D0
#define CStmlWnd__GetNextTagPiece_x                                0x93D2B0
#define CStmlWnd__GetSTMLText_x                                    0x4F5100
#define CStmlWnd__GetVisibleText_x                                 0x9384F0
#define CStmlWnd__InitializeWindowVariables_x                      0x93DE30
#define CStmlWnd__MakeStmlColorTag_x                               0x937610
#define CStmlWnd__MakeWndNotificationTag_x                         0x937680
#define CStmlWnd__SetSTMLText_x                                    0x9366C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x93F140
#define CStmlWnd__UpdateHistoryString_x                            0x93E1F0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x942DD0
#define CTabWnd__DrawCurrentPage_x                                 0x9433F0
#define CTabWnd__DrawTab_x                                         0x9431C0
#define CTabWnd__GetCurrentPage_x                                  0x942630
#define CTabWnd__GetPageInnerRect_x                                0x942870
#define CTabWnd__GetTabInnerRect_x                                 0x9427B0
#define CTabWnd__GetTabRect_x                                      0x942660
#define CTabWnd__InsertPage_x                                      0x942A60
#define CTabWnd__SetPage_x                                         0x9428F0
#define CTabWnd__SetPageRect_x                                     0x942D10
#define CTabWnd__UpdatePage_x                                      0x943080
#define CTabWnd__GetPageFromTabIndex_x                             0x943100
#define CTabWnd__GetCurrentTabIndex_x                              0x942620

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x751270
#define CPageWnd__SetTabText_x                                     0x94F840

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A6720

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x90DB90
#define CTextureFont__GetTextExtent_x                              0x90DD50

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x69E050
#define CHtmlComponentWnd__ValidateUri_x                           0x72FE20
#define CHtmlWnd__SetClientCallbacks_x                             0x60B000
#define CHtmlWnd__AddObserver_x                                    0x60B020
#define CHtmlWnd__RemoveObserver_x                                 0x60B080
#define Window__getProgress_x                                      0x8499F0
#define Window__getStatus_x                                        0x849A10
#define Window__getURI_x                                           0x849A20

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x94BDC0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8FAAC0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ADFC0
#define CXStr__CXStr1_x                                            0x9035D0
#define CXStr__CXStr3_x                                            0x8E6E80
#define CXStr__dCXStr_x                                            0x473020
#define CXStr__operator_equal_x                                    0x8E70B0
#define CXStr__operator_equal1_x                                   0x8E70F0
#define CXStr__operator_plus_equal1_x                              0x8E7B80

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x92F3C0
#define CXWnd__BringToTop_x                                        0x914520
#define CXWnd__Center_x                                            0x9140A0
#define CXWnd__ClrFocus_x                                          0x913ED0
#define CXWnd__Destroy_x                                           0x913F80
#define CXWnd__DoAllDrawing_x                                      0x9104B0
#define CXWnd__DrawChildren_x                                      0x910480
#define CXWnd__DrawColoredRect_x                                   0x910910
#define CXWnd__DrawTooltip_x                                       0x90F000
#define CXWnd__DrawTooltipAtPoint_x                                0x90F0C0
#define CXWnd__GetBorderFrame_x                                    0x910770
#define CXWnd__GetChildWndAt_x                                     0x9145C0
#define CXWnd__GetClientClipRect_x                                 0x912780
#define CXWnd__GetScreenClipRect_x                                 0x912850
#define CXWnd__GetScreenRect_x                                     0x9129F0
#define CXWnd__GetTooltipRect_x                                    0x910960
#define CXWnd__GetWindowTextA_x                                    0x497D70
#define CXWnd__IsActive_x                                          0x917430
#define CXWnd__IsDescendantOf_x                                    0x913410
#define CXWnd__IsReallyVisible_x                                   0x913440
#define CXWnd__IsType_x                                            0x914C30
#define CXWnd__Move_x                                              0x9134B0
#define CXWnd__Move1_x                                             0x913570
#define CXWnd__ProcessTransition_x                                 0x914050
#define CXWnd__Refade_x                                            0x913850
#define CXWnd__Resize_x                                            0x913B20
#define CXWnd__Right_x                                             0x9142E0
#define CXWnd__SetFocus_x                                          0x913E90
#define CXWnd__SetFont_x                                           0x913F00
#define CXWnd__SetKeyTooltip_x                                     0x914A50
#define CXWnd__SetMouseOver_x                                      0x911900
#define CXWnd__StartFade_x                                         0x9132F0
#define CXWnd__GetChildItem_x                                      0x914730
#define CXWnd__SetParent_x                                         0x9131B0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x947340

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x917470
#define CXWndManager__DrawWindows_x                                0x917490
#define CXWndManager__GetKeyboardFlags_x                           0x919B50
#define CXWndManager__HandleKeyboardMsg_x                          0x919750
#define CXWndManager__RemoveWnd_x                                  0x919DA0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x91A2D0

// CDBStr
#define CDBStr__GetString_x                                        0x52CD20

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B90A0
#define EQ_Character__Cur_HP_x                                     0x4CF280
#define EQ_Character__Cur_Mana_x                                   0x4D6980
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BBFB0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFBB0
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFD00
#define EQ_Character__GetHPRegen_x                                 0x4DC900
#define EQ_Character__GetEnduranceRegen_x                          0x4DCF10
#define EQ_Character__GetManaRegen_x                               0x4DD350
#define EQ_Character__Max_Endurance_x                              0x631070
#define EQ_Character__Max_HP_x                                     0x4CF0B0
#define EQ_Character__Max_Mana_x                                   0x630E70
#define EQ_Character__doCombatAbility_x                            0x633530
#define EQ_Character__UseSkill_x                                   0x4DF140
#define EQ_Character__GetConLevel_x                                0x62A370
#define EQ_Character__IsExpansionFlag_x                            0x590760
#define EQ_Character__TotalEffect_x                                0x4C2640
#define EQ_Character__GetPCSpellAffect_x                           0x4BCBA0
#define EQ_Character__SpellDuration_x                              0x4BC6D0
#define EQ_Character__GetAdjustedSkill_x                           0x4D1FC0
#define EQ_Character__GetBaseSkill_x                               0x4D2F60
#define EQ_Character__CanUseItem_x                                 0x4D6C90

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B8550

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6473A0

//PcClient
#define PcClient__PcClient_x                                       0x627AA0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6D30
#define CCharacterListWnd__EnterWorld_x                            0x4B6770
#define CCharacterListWnd__Quit_x                                  0x4B6480
#define CCharacterListWnd__UpdateList_x                            0x4B6900

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x60C220
#define EQ_Item__CreateItemTagString_x                             0x892D50
#define EQ_Item__IsStackable_x                                     0x897790
#define EQ_Item__GetImageNum_x                                     0x894770
#define EQ_Item__CreateItemClient_x                                0x60B3E0
#define EQ_Item__GetItemValue_x                                    0x8959D0
#define EQ_Item__ValueSellMerchant_x                               0x898F60
#define EQ_Item__IsKeyRingItem_x                                   0x8970E0
#define EQ_Item__CanGoInBag_x                                      0x60C340
#define EQ_Item__IsEmpty_x                                         0x896C10
#define EQ_Item__GetMaxItemCount_x                                 0x895DA0
#define EQ_Item__GetHeldItem_x                                     0x894640
#define EQ_Item__GetAugmentFitBySlot_x                             0x892690

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54B030
#define EQ_LoadingS__Array_x                                       0xBEE130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6319D0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A2220
#define EQ_PC__GetCombatAbility_x                                  0x8A2890
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A2900
#define EQ_PC__GetItemRecastTimer_x                                0x633AB0
#define EQ_PC__HasLoreItem_x                                       0x62AB40
#define EQ_PC__AlertInventoryChanged_x                             0x629CA0
#define EQ_PC__GetPcZoneClient_x                                   0x655BB0
#define EQ_PC__RemoveMyAffect_x                                    0x636CA0
#define EQ_PC__GetKeyRingItems_x                                   0x8A31A0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A2F20
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A3490

// EQItemList 
#define EQItemList__EQItemList_x                                   0x596BF0
#define EQItemList__add_object_x                                   0x5C2900
#define EQItemList__add_item_x                                     0x597200
#define EQItemList__delete_item_x                                  0x597250
#define EQItemList__FreeItemList_x                                 0x597150

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52A2C0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x648C20
#define EQPlayer__dEQPlayer_x                                      0x63C300
#define EQPlayer__DoAttack_x                                       0x650890
#define EQPlayer__EQPlayer_x                                       0x63C9B0
#define EQPlayer__SetNameSpriteState_x                             0x640C50
#define EQPlayer__SetNameSpriteTint_x                              0x641B20
#define PlayerBase__HasProperty_j_x                                0x97A040
#define EQPlayer__IsTargetable_x                                   0x97A4E0
#define EQPlayer__CanSee_x                                         0x97A340
#define EQPlayer__CanSee1_x                                        0x97A410
#define PlayerBase__GetVisibilityLineSegment_x                     0x97A100

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x653660
#define PlayerZoneClient__GetLevel_x                               0x655BF0
#define PlayerZoneClient__IsValidTeleport_x                        0x5C3A50
#define PlayerZoneClient__LegalPlayerRace_x                        0x5444A0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x64B9B0
#define EQPlayerManager__GetSpawnByName_x                          0x64B9D0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x64BA60

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x60FAC0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x60FB00
#define KeypressHandler__ClearCommandStateArray_x                  0x610EF0
#define KeypressHandler__HandleKeyDown_x                           0x610F10
#define KeypressHandler__HandleKeyUp_x                             0x610FB0
#define KeypressHandler__SaveKeymapping_x                          0x611390

// MapViewMap 
#define MapViewMap__Clear_x                                        0x767CD0
#define MapViewMap__SaveEx_x                                       0x76B070
#define MapViewMap__SetZoom_x                                      0x76F740

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B6440

// StringTable 
#define StringTable__getString_x                                   0x8B1430

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x636910
#define PcZoneClient__RemovePetEffect_x                            0x636F40
#define PcZoneClient__HasAlternateAbility_x                        0x630CB0
#define PcZoneClient__GetCurrentMod_x                              0x4E2240
#define PcZoneClient__GetModCap_x                                  0x4E2140
#define PcZoneClient__CanEquipItem_x                               0x631360
#define PcZoneClient__GetItemByID_x                                0x633F20
#define PcZoneClient__GetItemByItemClass_x                         0x634070
#define PcZoneClient__RemoveBuffEffect_x                           0x636F60
#define PcZoneClient__BandolierSwap_x                              0x631F90
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x633A50

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C86C0

//IconCache
#define IconCache__GetIcon_x                                       0x708750

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x700200
#define CContainerMgr__CloseContainer_x                            0x7004D0
#define CContainerMgr__OpenExperimentContainer_x                   0x700F50

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C3210

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x604460

//CLootWnd
#define CLootWnd__LootAll_x                                        0x75E070
#define CLootWnd__RequestLootSlot_x                                0x75D430

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5634F0
#define EQ_Spell__SpellAffects_x                                   0x563960
#define EQ_Spell__SpellAffectBase_x                                0x563720
#define EQ_Spell__IsStackable_x                                    0x4C6E30
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6CB0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B40C0
#define EQ_Spell__IsSPAStacking_x                                  0x564790
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x563CB0
#define EQ_Spell__IsNoRemove_x                                     0x4C6E10
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5647A0
#define __IsResEffectSpell_x                                       0x4C61A0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA8F0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C09B0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x808C30
#define CTargetWnd__WndNotification_x                              0x8084C0
#define CTargetWnd__RefreshTargetBuffs_x                           0x808790
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x807610

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x80D300

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x527C70
#define CTaskManager__HandleMessage_x                              0x5263C0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x55EA90
#define EqSoundManager__PlayScriptMp3_x                            0x55EBF0
#define EqSoundManager__SoundAssistPlay_x                          0x66E180
#define EqSoundManager__WaveInstancePlay_x                         0x66D6F0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51BC20

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x932B00

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x552D00
#define CAltAbilityData__GetMercMaxRank_x                          0x552CA0
#define CAltAbilityData__GetMaxRank_x                              0x548150

//CTargetRing
#define CTargetRing__Cast_x                                        0x602560

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6C90
#define CharacterBase__CreateItemGlobalIndex_x                     0x502040
#define CharacterBase__CreateItemIndex_x                           0x60A640
#define CharacterBase__GetItemPossession_x                         0x0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C9030
#define CharacterBase__GetEffectId_x                               0x4C6C40

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E82B0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E8AD0

//messages
#define msg_spell_worn_off_x                                       0x588940
#define msg_new_text_x                                             0x57D760
#define __msgTokenTextParam_x                                      0x58AFB0
#define msgTokenText_x                                             0x58B200

//SpellManager
#define SpellManager__vftable_x                                    0xAB5A88
#define SpellManager__SpellManager_x                               0x6714B0
#define Spellmanager__LoadTextSpells_x                             0x671D80
#define SpellManager__GetSpellByGroupAndRank_x                     0x671680

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x97DFE0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5026F0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x58EDF0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x623250
#define ItemGlobalIndex__IsValidIndex_x                            0x502750

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C12F0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C1570

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x756BC0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor1_x                        0x704960
#define CCursorAttachment__Deactivate_x                            0x705940

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x928590
#define CSidlManagerBase__CreatePageWnd_x                          0x927D90

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x945440
#define CEQSuiteTextureLoader__GetTexture_x                        0x945100

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4FF5C0

//IString
#define IString__Append_x                                          0x4EF360

//Camera
#define CDisplay__cameraType_x                                     0xDC7B44
#define EverQuest__Cameras_x                                       0xE8A848

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x507E70
#define LootFiltersManager__GetItemFilterData_x                    0x507760
#define LootFiltersManager__RemoveItemLootFilter_x                 0x507790
#define LootFiltersManager__SetItemLootFilter_x                    0x5079B0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B1210

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x983D20
#define CResolutionHandler__GetWindowedStyle_x                     0x668EB0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6FCFD0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D3A40

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x71D1E0
#define CGroupWnd__UpdateDisplay_x                                 0x71C540

//ItemBase
#define ItemBase__IsLore_x                                         0x897140
#define ItemBase__IsLoreEquipped_x                                 0x8971B0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C27F0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C29A0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C2A00

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x65E640
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x662270

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F58A0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4E4F60
#define FactionManagerClient__HandleFactionMessage_x               0x4E55E0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4E5BC0
#define FactionManagerClient__GetMaxFaction_x                      0x4E5C10
#define FactionManagerClient__GetMinFaction_x                      0x4E5B90

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
