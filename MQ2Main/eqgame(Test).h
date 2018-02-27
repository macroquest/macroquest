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
#define __ExpectedVersionDate                                     "Feb 23 2018"
#define __ExpectedVersionTime                                     "15:09:27"
#define __ActualVersionDate_x                                      0xADDC18
#define __ActualVersionTime_x                                      0xADDC0C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x6AAFD0
#define __MemChecker1_x                                            0x99ECF0
#define __MemChecker2_x                                            0x744160
#define __MemChecker3_x                                            0x7440A0
#define __MemChecker4_x                                            0x8F8F00
#define __EncryptPad0_x                                            0xC40F60
#define __EncryptPad1_x                                            0xD179E0
#define __EncryptPad2_x                                            0xC69DF8
#define __EncryptPad3_x                                            0xC699F8
#define __EncryptPad4_x                                            0xD08750
#define __EncryptPad5_x                                            0x10C444C
#define __AC1_x                                                    0x8B4686
#define __AC2_x                                                    0x664A2D
#define __AC3_x                                                    0x66B8DD
#define __AC4_x                                                    0x66F7EE
#define __AC5_x                                                    0x675A4D
#define __AC6_x                                                    0x679F20
#define __AC7_x                                                    0x66449E
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FACF70

// Direct Input
#define DI8__Main_x                                                0xFB9290
#define DI8__Keyboard_x                                            0xFB9294
#define DI8__Mouse_x                                               0xFB93AC
#define DI8__Mouse_Copy_x                                          0xF323B4
#define DI8__Mouse_Check_x                                         0xFB96D0
#define __AutoSkillArray_x                                         0xF332C4
#define __Attack_x                                                 0xFB69B7
#define __Autofire_x                                               0xFB69B8
#define __BindList_x                                               0xC1D100
#define g_eqCommandStates_x                                        0xC1DE60
#define __Clicks_x                                                 0xF3246C
#define __CommandList_x                                            0xC1FA28
#define __CurrentMapLabel_x                                        0x10CA380
#define __CurrentSocial_x                                          0xBED410
#define __DoAbilityList_x                                          0xF68B7C
#define __do_loot_x                                                0x630E30
#define __DrawHandler_x                                            0x1733F28
#define __GroupCount_x                                             0xF226E2

#define __Guilds_x                                                 0xF28620
#define __gWorld_x                                                 0xF22F20
#define __HotkeyPage_x                                             0xFAF57C
#define __HWnd_x                                                   0xFB93B0
#define __InChatMode_x                                             0xF3239C
#define __LastTell_x                                               0xF34278
#define __LMouseHeldTime_x                                         0xF324D8
#define __Mouse_x                                                  0xFB9278
#define __MouseLook_x                                              0xF32432
#define __MouseEventTime_x                                         0xFB7170
#define __gpbCommandEvent_x                                        0xF228D4
#define __NetStatusToggle_x                                        0xF32435
#define __PCNames_x                                                0xF33880
#define __RangeAttackReady_x                                       0xF335A8
#define __RMouseHeldTime_x                                         0xF324D4
#define __RunWalkState_x                                           0xF323A0
#define __ScreenMode_x                                             0xE716A4
#define __ScreenX_x                                                0xF32354
#define __ScreenY_x                                                0xF32350
#define __ScreenXMax_x                                             0xF32358
#define __ScreenYMax_x                                             0xF3235C
#define __ServerHost_x                                             0xF22B43
#define __ServerName_x                                             0xF68B3C
#define __ShiftKeyDown_x                                           0xF32A2C
#define __ShowNames_x                                              0xF33760
#define __Socials_x                                                0xF68C3C
#define __SubscriptionType_x                                       0x10FAC4C
#define __TargetAggroHolder_x                                      0x10CC5BC
#define __ZoneType_x                                               0xF32830
#define __GroupAggro_x                                             0x10CC5FC
#define __LoginName_x                                              0x10C40EC
#define __Inviter_x                                                0xFB6934
#define __AttackOnAssist_x                                         0xF3371C
#define __UseTellWindows_x                                         0xF33A18

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF24FB0
#define instEQZoneInfo_x                                           0xF32628
#define instKeypressHandler_x                                      0xFB7150
#define pinstActiveBanker_x                                        0xF24F3C
#define pinstActiveCorpse_x                                        0xF24F34
#define pinstActiveGMaster_x                                       0xF24F38
#define pinstActiveMerchant_x                                      0xF24F30
#define pinstAggroInfo_x                                           0xD2E488
#define pinstAltAdvManager_x                                       0xE72000
#define pinstAuraMgr_x                                             0xD3EC50
#define pinstBandageTarget_x                                       0xF24F4C
#define pinstCamActor_x                                            0xE71698
#define pinstCDBStr_x                                              0xE70E28
#define pinstCDisplay_x                                            0xF22698
#define pinstCEverQuest_x                                          0xFB91F0
#define pinstEverQuestInfo_x                                       0xF32348
#define pinstCharData_x                                            0xF226BC
#define pinstCharSpawn_x                                           0xF24F88
#define pinstControlledMissile_x                                   0xF22690
#define pinstControlledPlayer_x                                    0xF24F88
#define pinstCSidlManager_x                                        0x1733178
#define pinstCXWndManager_x                                        0x1733174
#define instDynamicZone_x                                          0xF321E8
#define pinstDZMember_x                                            0xF322F8
#define pinstDZTimerInfo_x                                         0xF322FC
#define pinstEQItemList_x                                          0xF21430
#define pinstEQObjectList_x                                        0xF22468
#define instEQMisc_x                                               0xE70D88
#define pinstEQSoundManager_x                                      0xE725F0
#define pinstEQSpellStrings_x                                      0xD3C2D0
#define instExpeditionLeader_x                                     0xF32232
#define instExpeditionName_x                                       0xF32272
#define pinstGroup_x                                               0xF226DE
#define pinstImeManager_x                                          0x1733170
#define pinstLocalPlayer_x                                         0xF22F2C
#define pinstMercenaryData_x                                       0xFB77C4
#define pinstMercenaryStats_x                                      0x10CC708
#define pinstMercAltAbilities_x                                    0xE72420
#define pinstModelPlayer_x                                         0xF24F44
#define pinstPCData_x                                              0xF226BC
#define pinstSkillMgr_x                                            0xFB8818
#define pinstSpawnManager_x                                        0xFB8040
#define pinstSpellManager_x                                        0xFB8968
#define pinstSpellSets_x                                           0xFAF5E0
#define pinstStringTable_x                                         0xF22E1C
#define pinstSwitchManager_x                                       0xF22598
#define pinstTarget_x                                              0xF24F80
#define pinstTargetObject_x                                        0xF24F84
#define pinstTargetSwitch_x                                        0xF226C0
#define pinstTaskMember_x                                          0xE70C48
#define pinstTrackTarget_x                                         0xF24F8C
#define pinstTradeTarget_x                                         0xF24F40
#define instTributeActive_x                                        0xE70DAD
#define pinstViewActor_x                                           0xE71694
#define pinstWorldData_x                                           0xF228D8
#define pinstZoneAddr_x                                            0xF328C8
#define pinstPlayerPath_x                                          0xFB80A8
#define pinstTargetIndicator_x                                     0xFB8B10
#define pinstCTargetManager_x                                      0xFB8B78
#define EQObject_Top_x                                             0xF22F28
#define pinstRealEstateItems_x                                     0xFB8770
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE716B8
#define pinstCAchievementsWnd_x                                    0xE71710
#define pinstCActionsWnd_x                                         0xE71614
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE71550
#define pinstCAdvancedLootWnd_x                                    0xE70E98
#define pinstCAdventureLeaderboardWnd_x                            0x10C4E10
#define pinstCAdventureRequestWnd_x                                0x10C4E90
#define pinstCAdventureStatsWnd_x                                  0x10C4F10
#define pinstCAggroMeterWnd_x                                      0xE715EC
#define pinstCAlarmWnd_x                                           0xE715F4
#define pinstCAlertHistoryWnd_x                                    0xE715E8
#define pinstCAlertStackWnd_x                                      0xE71134
#define pinstCAlertWnd_x                                           0xE7155C
#define pinstCAltStorageWnd_x                                      0x10C5180
#define pinstCAudioTriggersWindow_x                                0xD2E7B0
#define pinstCAuraWnd_x                                            0xE715BC
#define pinstCAvaZoneWnd_x                                         0xE716E8
#define pinstCBandolierWnd_x                                       0xE715F8
#define pinstCBankWnd_x                                            0xE71548
#define pinstCBarterMerchantWnd_x                                  0x10C5ED0
#define pinstCBarterSearchWnd_x                                    0x10C5F50
#define pinstCBarterWnd_x                                          0x10C5FD0
#define pinstCBazaarConfirmationWnd_x                              0xE71674
#define pinstCBazaarSearchWnd_x                                    0xE71588
#define pinstCBazaarWnd_x                                          0xE71648
#define pinstCBlockedBuffWnd_x                                     0xE715B4
#define pinstCBlockedPetBuffWnd_x                                  0xE715E0
#define pinstCBodyTintWnd_x                                        0xE71544
#define pinstCBookWnd_x                                            0xE7161C
#define pinstCBreathWnd_x                                          0xE716D0
#define pinstCBuffWindowNORMAL_x                                   0xE71594
#define pinstCBuffWindowSHORT_x                                    0xE71598
#define pinstCBugReportWnd_x                                       0xE716FC
#define pinstCCastingWnd_x                                         0xE715A8
#define pinstCCastSpellWnd_x                                       0xE71658
#define pinstCCharacterListWnd_x                                   0xE70E9C
#define pinstCChatWindowManager_x                                  0x10C67F0
#define pinstCClaimWnd_x                                           0x10C68E8
#define pinstCColorPickerWnd_x                                     0xE71670
#define pinstCCombatAbilityWnd_x                                   0xE71690
#define pinstCCombatSkillsSelectWnd_x                              0xE70EA8
#define pinstCCompassWnd_x                                         0xE7153C
#define pinstCConfirmationDialog_x                                 0x10CAC30
#define pinstCContainerMgr_x                                       0xE7165C
#define pinstCContextMenuManager_x                                 0x1733128
#define pinstCCursorAttachment_x                                   0xE715A4
#define pinstCDynamicZoneWnd_x                                     0x10C6D30
#define pinstCEditLabelWnd_x                                       0xE7159C
#define pinstCEQMainWnd_x                                          0x10C6EF8
#define pinstCEventCalendarWnd_x                                   0xE715B0
#define pinstCFacePick_x                                           0xE71540
#define pinstCFeedbackWnd_x                                        0xE716EC
#define pinstCFellowshipWnd_x                                      0x10C70E0
#define pinstCFileSelectionWnd_x                                   0xE716F4
#define pinstCFindItemWnd_x                                        0xE71714
#define pinstCFindLocationWnd_x                                    0x10C71D8
#define pinstCFriendsWnd_x                                         0xE70EBC
#define pinstCGemsGameWnd_x                                        0xE715CC
#define pinstCGiveWnd_x                                            0xE71650
#define pinstCGroupSearchFiltersWnd_x                              0xE71610
#define pinstCGroupSearchWnd_x                                     0x10C74B0
#define pinstCGroupWnd_x                                           0x10C7530
#define pinstCGuildBankWnd_x                                       0x10C75B0
#define pinstCGuildCreationWnd_x                                   0x10C7630
#define pinstCGuildMgmtWnd_x                                       0x10C76B4
#define pinstCharacterCreation_x                                   0xE70EA4
#define pinstCHelpWnd_x                                            0xE71570
#define pinstCHeritageSelectionWnd_x                               0xE71568
#define pinstCHotButtonWnd_x                                       0x10C97AC
#define pinstCHotButtonWnd1_x                                      0x10C97AC
#define pinstCHotButtonWnd2_x                                      0x10C97B0
#define pinstCHotButtonWnd3_x                                      0x10C97B4
#define pinstCHotButtonWnd4_x                                      0x10C97D8
#define pinstCIconSelectionWnd_x                                   0xE71604
#define pinstCInspectWnd_x                                         0xE716B4
#define pinstCInventoryWnd_x                                       0xE71704
#define pinstCInvSlotMgr_x                                         0xE71618
#define pinstCItemDisplayManager_x                                 0x10C9C38
#define pinstCItemExpTransferWnd_x                                 0x10C9D38
#define pinstCItemOverflowWnd_x                                    0xE71590
#define pinstCJournalCatWnd_x                                      0xE7170C
#define pinstCJournalTextWnd_x                                     0xE716C8
#define pinstCKeyRingWnd_x                                         0xE70EB4
#define pinstCLargeDialogWnd_x                                     0x10CB5C8
#define pinstCLayoutCopyWnd_x                                      0x10C9F98
#define pinstCLFGuildWnd_x                                         0x10CA018
#define pinstCLoadskinWnd_x                                        0xE715E4
#define pinstCLootFiltersCopyWnd_x                                 0xD3F228
#define pinstCLootFiltersWnd_x                                     0xE716C4
#define pinstCLootSettingsWnd_x                                    0xE716DC
#define pinstCLootWnd_x                                            0xE715C0
#define pinstCMailAddressBookWnd_x                                 0xE716E0
#define pinstCMailCompositionWnd_x                                 0xE716BC
#define pinstCMailIgnoreListWnd_x                                  0xE716E4
#define pinstCMailWnd_x                                            0xE7168C
#define pinstCManageLootWnd_x                                      0xE72328
#define pinstCMapToolbarWnd_x                                      0xE71584
#define pinstCMapViewWnd_x                                         0xE71558
#define pinstCMarketplaceWnd_x                                     0xE7156C
#define pinstCMerchantWnd_x                                        0xE71578
#define pinstCMIZoneSelectWnd_x                                    0x10CA610
#define pinstCMusicPlayerWnd_x                                     0xE7164C
#define pinstCNameChangeMercWnd_x                                  0xE7171C
#define pinstCNameChangePetWnd_x                                   0xE716F8
#define pinstCNameChangeWnd_x                                      0xE70EAC
#define pinstCNoteWnd_x                                            0xE71564
#define pinstCObjectPreviewWnd_x                                   0xE71580
#define pinstCOptionsWnd_x                                         0xE71554
#define pinstCPetInfoWnd_x                                         0xE71654
#define pinstCPetitionQWnd_x                                       0xE71680
#define pinstCPlayerNotesWnd_x                                     0xE71560
#define pinstCPlayerWnd_x                                          0xE715AC
#define pinstCPopupWndManager_x                                    0x10CAC30
#define pinstCPotionBeltWnd_x                                      0xE7160C
#define pinstCProgressionSelectionWnd_x                            0x10CAD28
#define pinstCPurchaseGroupWnd_x                                   0xE715C4
#define pinstCPurchaseWnd_x                                        0xE715A0
#define pinstCPvPLeaderboardWnd_x                                  0x10CADA8
#define pinstCPvPStatsWnd_x                                        0x10CAE28
#define pinstCQuantityWnd_x                                        0xE7157C
#define pinstCRaceChangeWnd_x                                      0xE7154C
#define pinstCRaidOptionsWnd_x                                     0xE71600
#define pinstCRaidWnd_x                                            0xE71688
#define pinstCRealEstateItemsWnd_x                                 0xE71700
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE7167C
#define pinstCRealEstateManageWnd_x                                0xE715F0
#define pinstCRealEstateNeighborhoodWnd_x                          0xE71608
#define pinstCRealEstatePlotSearchWnd_x                            0xE71620
#define pinstCRealEstatePurchaseWnd_x                              0xE71644
#define pinstCRespawnWnd_x                                         0xE715D8
#define pinstCSelectorWnd_x                                        0xE715FC
#define pinstCSendMoneyWnd_x                                       0xE71668
#define pinstCServerListWnd_x                                      0xE7158C
#define pinstCSkillsSelectWnd_x                                    0xE71718
#define pinstCSkillsWnd_x                                          0xE716F0
#define pinstCSocialEditWnd_x                                      0xE716D4
#define pinstCSocialWnd_x                                          0xE71660
#define pinstCSpellBookWnd_x                                       0xE716A8
#define pinstCStoryWnd_x                                           0xE70EB0
#define pinstCTargetOfTargetWnd_x                                  0x10CC790
#define pinstCTargetWnd_x                                          0xE715DC
#define pinstCTaskOverlayWnd_x                                     0xE7172C
#define pinstCTaskSelectWnd_x                                      0x10CC888
#define pinstCTaskSomething_x                                      0xD3F7F0
#define pinstCTaskTemplateSelectWnd_x                              0x10CC908
#define pinstCTaskWnd_x                                            0x10CC988
#define pinstCTextEntryWnd_x                                       0xE71574
#define pinstCTextOverlay_x                                        0xD2E9C8
#define pinstCTimeLeftWnd_x                                        0xE7166C
#define pinstCTipWndCONTEXT_x                                      0x10CCAFC
#define pinstCTipWndOFDAY_x                                        0x10CCAF8
#define pinstCTitleWnd_x                                           0x10CCB78
#define pinstCTrackingWnd_x                                        0xE71684
#define pinstCTradeskillWnd_x                                      0x10CCC80
#define pinstCTradeWnd_x                                           0xE715D4
#define pinstCTrainWnd_x                                           0xE71678
#define pinstCTributeBenefitWnd_x                                  0x10CCDF0
#define pinstCTributeMasterWnd_x                                   0x10CCE70
#define pinstCTributeTrophyWnd_x                                   0x10CCEF0
#define pinstCVideoModesWnd_x                                      0xE71664
#define pinstCVoiceMacroWnd_x                                      0xFB8F78
#define pinstCVoteResultsWnd_x                                     0xE716D8
#define pinstCVoteWnd_x                                            0xE716CC
#define pinstCWebManager_x                                         0xFB907C
#define pinstCZoneGuideWnd_x                                       0xE715B8
#define pinstCZonePathWnd_x                                        0xE715D0
#define pinstEQSuiteTextureLoader_x                                0xD19274
#define pinstItemIconCache_x                                       0x10C6EA0
#define pinstRewardSelectionWnd_x                                  0x10CB360

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC699E8
#define __CastRay_x                                                0x62C1A0
#define __CastRay2_x                                               0x62C1F0
#define __ConvertItemTags_x                                        0x647230
#define __CrashHandler_x                                           0x902BB0
#define __EQGetTime_x                                              0x99E630
#define __ExecuteCmd_x                                             0x6249D0
#define __FixHeading_x                                             0xA2DD30
#define __get_bearing_x                                            0x62BCE0
#define __get_melee_range_x                                        0x62C420
#define __GetAnimationCache_x                                      0x7AFD80
#define __GetGaugeValueFromEQ_x                                    0x8B2E80
#define __GetLabelFromEQ_x                                         0x8B4610
#define __GetXTargetType_x                                         0xA2F7A0
#define __HeadingDiff_x                                            0xA2DDA0
#define __HelpPath_x                                               0xFB6ECC
#define __LoadFrontEnd_x                                           0x73FA80
#define __NewUIINI_x                                               0x8B2B50
#define __pCrashHandler_x                                          0x10D9BA0
#define __ProcessGameEvents_x                                      0x68AB00
#define __ProcessMouseEvent_x                                      0x68A2D0
#define __STMLToText_x                                             0x9D25A0
#define __ToggleKeyRingItem_x                                      0x594AC0
#define CrashDetected_x                                            0x741710
#define DrawNetStatus_x                                            0x6BA8F0
#define Expansion_HoT_x                                            0xF3370C
#define Teleport_Table_Size_x                                      0xF22974
#define Teleport_Table_x                                           0xF22F30
#define Util__FastTime_x                                           0x99E220
#define wwsCrashReportCheckForUploader_x                           0x903610
#define wwsCrashReportPlatformLaunchUploader_x                     0x905C60
#define __SaveColors_x                                             0x5D39F0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x51F000
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x528010
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x527DF0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5DC1D0
#define AltAdvManager__IsAbilityReady_x                            0x5DB240
#define AltAdvManager__GetAAById_x                                 0x5DB440
#define AltAdvManager__CanTrainAbility_x                           0x5DB4B0
#define AltAdvManager__CanSeeAbility_x                             0x5DB6E0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x55CFA0
#define CharacterZoneClient__HasSkill_x                            0x5687E0
#define CharacterZoneClient__MakeMeVisible_x                       0x569F30
#define CharacterZoneClient__IsStackBlocked_x                      0x550B50
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x54D100
#define CharacterZoneClient__GetItemCountWorn_x                    0x56C6E0
#define CharacterZoneClient__GetItemCountInInventory_x             0x56C7C0
#define CharacterZoneClient__GetCursorItemCount_x                  0x56C8A0
#define CharacterZoneClient__FindAffectSlot_x                      0x555880
#define CharacterZoneClient__BardCastBard_x                        0x558850
#define CharacterZoneClient__GetMaxEffects_x                       0x54D1D0
#define CharacterZoneClient__GetEffect_x                           0x54D040
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x556900
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x5569D0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x556A20

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x76EB20

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x77CF20

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x699D60
#define CButtonWnd__CButtonWnd_x                                   0x9CE930

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x79D280
#define CChatManager__InitContextMenu_x                            0x797630
#define CChatManager__FreeChatWindow_x                             0x79C1A0
#define CChatManager__GetLockedActiveChatWindow_x                  0x7A0E80
#define CChatManager__SetLockedActiveChatWindow_x                  0x79D010

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9E3000
#define CContextMenu__dCContextMenu_x                              0x9E3240
#define CContextMenu__AddMenuItem_x                                0x9E3250
#define CContextMenu__RemoveMenuItem_x                             0x9E3550
#define CContextMenu__RemoveAllMenuItems_x                         0x9E3570
#define CContextMenu__CheckMenuItem_x                              0x9E35F0
#define CContextMenu__SetMenuItem_x                                0x9E3470

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9E3BC0
#define CContextMenuManager__RemoveMenu_x                          0x9E3C30
#define CContextMenuManager__PopupMenu_x                           0x9E3CF0
#define CContextMenuManager__Flush_x                               0x9E3B60
#define CContextMenuManager__GetMenu_x                             0x529FB0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x982220
#define CChatService__GetFriendName_x                              0x982230

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x79D810
#define CChatWindow__Clear_x                                       0x79E8E0
#define CChatWindow__WndNotification_x                             0x79EE40

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x9E0590
#define CComboWnd__Draw_x                                          0x9DFA40
#define CComboWnd__GetCurChoice_x                                  0x9E03D0
#define CComboWnd__GetListRect_x                                   0x9DFF20
#define CComboWnd__GetTextRect_x                                   0x9E0600
#define CComboWnd__InsertChoice_x                                  0x9E00C0
#define CComboWnd__SetColors_x                                     0x9E0090
#define CComboWnd__SetChoice_x                                     0x9E03A0
#define CComboWnd__GetItemCount_x                                  0x9E03E0
#define CComboWnd__GetCurChoiceText_x                              0x9E0420

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7A78B0
#define CContainerWnd__vftable_x                                   0xAE7730

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x5D37C0
#define CDisplay__GetClickedActor_x                                0x5C6280
#define CDisplay__GetUserDefinedColor_x                            0x5BE6B0
#define CDisplay__GetWorldFilePath_x                               0x5C7CD0
#define CDisplay__is3dON_x                                         0x5C2ED0
#define CDisplay__ReloadUI_x                                       0x5CD330
#define CDisplay__WriteTextHD2_x                                   0x5C2CA0
#define CDisplay__TrueDistance_x                                   0x5C9930

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9F9610

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9E6AE0
#define CEditWnd__GetCharIndexPt_x                                 0x9E7A80
#define CEditWnd__GetDisplayString_x                               0x9E7900
#define CEditWnd__GetHorzOffset_x                                  0x9E60C0
#define CEditWnd__GetLineForPrintableChar_x                        0x9E8BE0
#define CEditWnd__GetSelStartPt_x                                  0x9E7D60
#define CEditWnd__GetSTMLSafeText_x                                0x9E7710
#define CEditWnd__PointFromPrintableChar_x                         0x9E8800
#define CEditWnd__SelectableCharFromPoint_x                        0x9E8970
#define CEditWnd__SetEditable_x                                    0x9E7E30

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x679450
#define CEverQuest__ClickedPlayer_x                                0x66B6C0
#define CEverQuest__CreateTargetIndicator_x                        0x687D90
#define CEverQuest__DeleteTargetIndicator_x                        0x687E20
#define CEverQuest__DoTellWindow_x                                 0x579350
#define CEverQuest__OutputTextToLog_x                              0x5795B0
#define CEverQuest__DropHeldItemOnGround_x                         0x6611A0
#define CEverQuest__dsp_chat_x                                     0x5799A0
#define CEverQuest__trimName_x                                     0x684330
#define CEverQuest__Emote_x                                        0x679C50
#define CEverQuest__EnterZone_x                                    0x673DF0
#define CEverQuest__GetBodyTypeDesc_x                              0x67DA80
#define CEverQuest__GetClassDesc_x                                 0x67E080
#define CEverQuest__GetClassThreeLetterCode_x                      0x67E680
#define CEverQuest__GetDeityDesc_x                                 0x686750
#define CEverQuest__GetLangDesc_x                                  0x67E840
#define CEverQuest__GetRaceDesc_x                                  0x67E060
#define CEverQuest__InterpretCmd_x                                 0x686D80
#define CEverQuest__LeftClickedOnPlayer_x                          0x665130
#define CEverQuest__LMouseUp_x                                     0x663450
#define CEverQuest__RightClickedOnPlayer_x                         0x665A40
#define CEverQuest__RMouseUp_x                                     0x664460
#define CEverQuest__SetGameState_x                                 0x660F40
#define CEverQuest__UPCNotificationFlush_x                         0x684230
#define CEverQuest__IssuePetCommand_x                              0x67FC50
#define CEverQuest__ReportSuccessfulHit_x                          0x67A900

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7BB410
#define CGaugeWnd__CalcLinesFillRect_x                             0x7BB470
#define CGaugeWnd__Draw_x                                          0x7BAA80

// CGuild
#define CGuild__FindMemberByName_x                                 0x541970
#define CGuild__GetGuildName_x                                     0x5409C0
#define CGuild__GetGuildIndex_x                                    0x540D40

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7D7DE0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7E5B80
#define CInvSlotMgr__MoveItem_x                                    0x7E46B0
#define CInvSlotMgr__SelectSlot_x                                  0x7E5C50

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7E2CF0
#define CInvSlot__SliderComplete_x                                 0x7E0790
#define CInvSlot__GetItemBase_x                                    0x7E0140
#define CInvSlot__UpdateItem_x                                     0x7E02B0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7E74A0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7E67C0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8AEA70
#define CItemDisplayWnd__UpdateStrings_x                           0x7F61A0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7EFBD0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7F0120
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7F6500
#define CItemDisplayWnd__AboutToShow_x                             0x7F5DE0
#define CItemDisplayWnd__WndNotification_x                         0x7F74D0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8E9540

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7FB920

// CLabel 
#define CLabel__Draw_x                                             0x801CA0

// CListWnd
#define CListWnd__CListWnd_x                                       0x9B8A80
#define CListWnd__dCListWnd_x                                      0x9B8DB0
#define CListWnd__AddColumn_x                                      0x9BD2F0
#define CListWnd__AddColumn1_x                                     0x9BD340
#define CListWnd__AddLine_x                                        0x9BD720
#define CListWnd__AddString_x                                      0x9BD510
#define CListWnd__CalculateFirstVisibleLine_x                      0x9BD0A0
#define CListWnd__CalculateVSBRange_x                              0x9BCE60
#define CListWnd__ClearSel_x                                       0x9BDEF0
#define CListWnd__ClearAllSel_x                                    0x9BDF50
#define CListWnd__CloseAndUpdateEditWindow_x                       0x9BE980
#define CListWnd__Compare_x                                        0x9BC760
#define CListWnd__Draw_x                                           0x9B8EC0
#define CListWnd__DrawColumnSeparators_x                           0x9BB720
#define CListWnd__DrawHeader_x                                     0x9BBB90
#define CListWnd__DrawItem_x                                       0x9BBFE0
#define CListWnd__DrawLine_x                                       0x9BB890
#define CListWnd__DrawSeparator_x                                  0x9BB7C0
#define CListWnd__EnableLine_x                                     0x9BAFF0
#define CListWnd__EnsureVisible_x                                  0x9BE8A0
#define CListWnd__ExtendSel_x                                      0x9BDE20
#define CListWnd__GetColumnMinWidth_x                              0x9BAB40
#define CListWnd__GetColumnWidth_x                                 0x9BAAB0
#define CListWnd__GetCurSel_x                                      0x9BA410
#define CListWnd__GetItemAtPoint_x                                 0x9BB270
#define CListWnd__GetItemAtPoint1_x                                0x9BB2E0
#define CListWnd__GetItemData_x                                    0x9BA490
#define CListWnd__GetItemHeight_x                                  0x9BA870
#define CListWnd__GetItemIcon_x                                    0x9BA630
#define CListWnd__GetItemRect_x                                    0x9BB0E0
#define CListWnd__GetItemText_x                                    0x9BA4D0
#define CListWnd__GetSelList_x                                     0x9BDFA0
#define CListWnd__GetSeparatorRect_x                               0x9BB520
#define CListWnd__InsertLine_x                                     0x9BDB00
#define CListWnd__RemoveLine_x                                     0x9BDC50
#define CListWnd__SetColors_x                                      0x9BCE30
#define CListWnd__SetColumnJustification_x                         0x9BCB50
#define CListWnd__SetColumnWidth_x                                 0x9BCA60
#define CListWnd__SetCurSel_x                                      0x9BDD60
#define CListWnd__SetItemColor_x                                   0x9BE550
#define CListWnd__SetItemData_x                                    0x9BE510
#define CListWnd__SetItemText_x                                    0x9BE120
#define CListWnd__ShiftColumnSeparator_x                           0x9BCC10
#define CListWnd__Sort_x                                           0x9BC900
#define CListWnd__ToggleSel_x                                      0x9BDD90

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x8188B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x83D4D0
#define CMerchantWnd__RequestBuyItem_x                             0x83DD70
#define CMerchantWnd__RequestSellItem_x                            0x83E2A0
#define CMerchantWnd__SelectRecoverySlot_x                         0x841440
//did this get another arg?
#define CMerchantWnd__SelectBuySellSlot_x                          0x83DAF0
#define CMerchantWnd__ActualSelect_x                               0x847150

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x94EAF0
#define CPacketScrambler__hton_x                                   0x94EAE0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x9D8120
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9D7F10
#define CSidlManager__CreateLabel_x                                0x8A5050
#define CSidlManager__CreateXWndFromTemplate_x                     0x9DB2F0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9DB4D0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9D4700
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9D45F0
#define CSidlScreenWnd__ConvertToRes_x                             0x9F94D0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9D40E0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9D3DC0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9D3E90
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9D3F60
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9D4BA0
#define CSidlScreenWnd__EnableIniStorage_x                         0x9D5070
#define CSidlScreenWnd__GetSidlPiece_x                             0x9D4D90
#define CSidlScreenWnd__Init1_x                                    0x9D39B0
#define CSidlScreenWnd__LoadIniInfo_x                              0x9D50C0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9D5C00
#define CSidlScreenWnd__LoadSidlScreen_x                           0x9D2DC0
#define CSidlScreenWnd__StoreIniInfo_x                             0x9D5780
#define CSidlScreenWnd__StoreIniVis_x                              0x9D5AE0
#define CSidlScreenWnd__WndNotification_x                          0x9D4AB0
#define CSidlScreenWnd__GetChildItem_x                             0x9D4FF0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9C4600
#define CSidlScreenWnd__m_layoutCopy_x                             0x1732FB8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x7059C0
#define CSkillMgr__GetSkillCap_x                                   0x705BA0
#define CSkillMgr__GetNameToken_x                                  0x705140

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9F8B90
#define CSliderWnd__SetValue_x                                     0x9F8A00
#define CSliderWnd__SetNumTicks_x                                  0x9F8A60

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x8AB840

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9EAB20
#define CStmlWnd__CalculateHSBRange_x                              0x9EBC70
#define CStmlWnd__CalculateVSBRange_x                              0x9EBBE0
#define CStmlWnd__CanBreakAtCharacter_x                            0x9F0B70
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9F1720
#define CStmlWnd__ForceParseNow_x                                  0x9EB120
#define CStmlWnd__GetNextTagPiece_x                                0x9F0AD0
#define CStmlWnd__GetSTMLText_x                                    0x5881E0
#define CStmlWnd__GetVisibleText_x                                 0x9EB140
#define CStmlWnd__InitializeWindowVariables_x                      0x9F1570
#define CStmlWnd__MakeStmlColorTag_x                               0x9EA240
#define CStmlWnd__MakeWndNotificationTag_x                         0x9EA2B0
#define CStmlWnd__SetSTMLText_x                                    0x9E92D0
#define CStmlWnd__StripFirstSTMLLines_x                            0x9F29F0
#define CStmlWnd__UpdateHistoryString_x                            0x9F1930

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9F5BC0
#define CTabWnd__DrawCurrentPage_x                                 0x9F6210
#define CTabWnd__DrawTab_x                                         0x9F5FC0
#define CTabWnd__GetCurrentPage_x                                  0x9F5420
#define CTabWnd__GetPageInnerRect_x                                0x9F5660
#define CTabWnd__GetTabInnerRect_x                                 0x9F55A0
#define CTabWnd__GetTabRect_x                                      0x9F5450
#define CTabWnd__InsertPage_x                                      0x9F5850
#define CTabWnd__SetPage_x                                         0x9F56E0
#define CTabWnd__SetPageRect_x                                     0x9F5B00
#define CTabWnd__UpdatePage_x                                      0x9F5E80
#define CTabWnd__GetPageFromTabIndex_x                             0x9F5F00
#define CTabWnd__GetCurrentTabIndex_x                              0x9F5410

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7FBEB0
#define CPageWnd__SetTabText_x                                     0xA029B0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x53AC20

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x9C1410
#define CTextureFont__GetTextExtent_x                              0x9C15F0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x73C040
#define CHtmlComponentWnd__ValidateUri_x                           0x7D96B0
#define CHtmlWnd__SetClientCallbacks_x                             0x69E980
#define CHtmlWnd__AddObserver_x                                    0x69E9A0
#define CHtmlWnd__RemoveObserver_x                                 0x69EA00
#define Window__getProgress_x                                      0x900580
#define Window__getStatus_x                                        0x9005A0
#define Window__getURI_x                                           0x9005B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9FF120

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x9AE1A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5064C0
#define CXStr__CXStr1_x                                            0x9B6F20
#define CXStr__CXStr3_x                                            0x99A7C0
#define CXStr__dCXStr_x                                            0x57F810
#define CXStr__operator_equal_x                                    0x99A9F0
#define CXStr__operator_equal1_x                                   0x99AA30
#define CXStr__operator_plus_equal1_x                              0x99B4C0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9E2C40
#define CXWnd__BringToTop_x                                        0x9C7FA0
#define CXWnd__Center_x                                            0x9C7B20

#define CXWnd__ClrFocus_x                                          0x9C7950
#define CXWnd__Destroy_x                                           0x9C7A00
#define CXWnd__DoAllDrawing_x                                      0x9C3D90
#define CXWnd__DrawChildren_x                                      0x9C3D60
#define CXWnd__DrawColoredRect_x                                   0x9C41F0
#define CXWnd__DrawTooltip_x                                       0x9C2850
#define CXWnd__DrawTooltipAtPoint_x                                0x9C2920
#define CXWnd__GetBorderFrame_x                                    0x9C4050
#define CXWnd__GetChildWndAt_x                                     0x9C8040
#define CXWnd__GetClientClipRect_x                                 0x9C6230
#define CXWnd__GetScreenClipRect_x                                 0x9C62E0
#define CXWnd__GetScreenRect_x                                     0x9C6490
#define CXWnd__GetTooltipRect_x                                    0x9C4240
#define CXWnd__GetWindowTextA_x                                    0x52B9E0
#define CXWnd__IsActive_x                                          0x9CAEE0
#define CXWnd__IsDescendantOf_x                                    0x9C6EB0
#define CXWnd__IsReallyVisible_x                                   0x9C6EE0
#define CXWnd__IsType_x                                            0x9C86D0
#define CScreenPieceTemplate__IsType_x                             0x9FA5A0
#define CXWnd__Move_x                                              0x9C6F50
#define CXWnd__Move1_x                                             0x9C7000
#define CXWnd__ProcessTransition_x                                 0x9C7AD0
#define CXWnd__Refade_x                                            0x9C72D0
#define CXWnd__Resize_x                                            0x9C7570
#define CXWnd__Right_x                                             0x9C7D60
#define CXWnd__SetFocus_x                                          0x9C7910
#define CXWnd__SetFont_x                                           0x9C7980
#define CXWnd__SetKeyTooltip_x                                     0x9C84D0
#define CXWnd__SetMouseOver_x                                      0x9C51A0
#define CXWnd__StartFade_x                                         0x9C6D80
#define CXWnd__GetChildItem_x                                      0x9C81B0
#define CXWnd__SetParent_x                                         0x9C6C40

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9CAF20
#define CXWndManager__DrawWindows_x                                0x9CAF40
#define CXWndManager__GetKeyboardFlags_x                           0x9CD720
#define CXWndManager__HandleKeyboardMsg_x                          0x9CD320
#define CXWndManager__RemoveWnd_x                                  0x9CD960
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9CDE90

// CDBStr
#define CDBStr__GetString_x                                        0x5BD510

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x54E070
#define EQ_Character__Cur_HP_x                                     0x5656F0
#define EQ_Character__Cur_Mana_x                                   0x56CD10
#define EQ_Character__GetAACastingTimeModifier_x                   0x551120
#define EQ_Character__GetFocusCastingTimeModifier_x                0x5448E0
#define EQ_Character__GetFocusRangeModifier_x                      0x544A50
#define EQ_Character__GetHPRegen_x                                 0x572630
#define EQ_Character__GetEnduranceRegen_x                          0x572C70
#define EQ_Character__GetManaRegen_x                               0x5730C0
#define EQ_Character__Max_Endurance_x                              0x6C8850
#define EQ_Character__Max_HP_x                                     0x565520
#define EQ_Character__Max_Mana_x                                   0x6C86D0
#define EQ_Character__doCombatAbility_x                            0x6CB280
#define EQ_Character__UseSkill_x                                   0x575000
#define EQ_Character__GetConLevel_x                                0x6C1C80
#define EQ_Character__IsExpansionFlag_x                            0x5BD430
#define EQ_Character__TotalEffect_x                                0x557DD0
#define EQ_Character__GetPCSpellAffect_x                           0x551D40
#define EQ_Character__SpellDuration_x                              0x551850
#define EQ_Character__FindItemByRecord_x                           0x56AF40
#define EQ_Character__GetAdjustedSkill_x                           0x5685A0
#define EQ_Character__GetBaseSkill_x                               0x569540
#define EQ_Character__CanUseItem_x                                 0x56D040

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x96D880

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6DF7F0

//PcClient
#define PcClient__PcClient_x                                       0x6BF590

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x54BB40
#define CCharacterListWnd__EnterWorld_x                            0x54B560
#define CCharacterListWnd__Quit_x                                  0x54B270
#define CCharacterListWnd__UpdateList_x                            0x54B700

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x69FD80
#define EQ_Item__CreateItemTagString_x                             0x948AF0
#define EQ_Item__IsStackable_x                                     0x94CEF0
#define EQ_Item__GetImageNum_x                                     0x94A360
#define EQ_Item__CreateItemClient_x                                0x69EFD0
#define EQ_Item__GetItemValue_x                                    0x94B410
#define EQ_Item__ValueSellMerchant_x                               0x94E6E0
#define EQ_Item__IsKeyRingItem_x                                   0x94C840
#define EQ_Item__CanGoInBag_x                                      0x69FEA0
#define EQ_Item__GetMaxItemCount_x                                 0x94B510
#define EQ_Item__GetHeldItem_x                                     0x94A170
#define EQ_Item__GetAugmentFitBySlot_x                             0x948630

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5DD0D0
#define EQ_LoadingS__Array_x                                       0xC0D240

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6C91F0
#define EQ_PC__GetAlternateAbilityId_x                             0x9577E0
#define EQ_PC__GetCombatAbility_x                                  0x957E60
#define EQ_PC__GetCombatAbilityTimer_x                             0x957ED0
#define EQ_PC__GetItemRecastTimer_x                                0x6CB810
#define EQ_PC__HasLoreItem_x                                       0x6C2400
#define EQ_PC__AlertInventoryChanged_x                             0x6C1770
#define EQ_PC__GetPcZoneClient_x                                   0x6EE8B0
#define EQ_PC__RemoveMyAffect_x                                    0x6CEBB0
#define EQ_PC__GetKeyRingItems_x                                   0x958770
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x9584F0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x958A60

// EQItemList 
#define EQItemList__EQItemList_x                                   0x6295B0
#define EQItemList__add_object_x                                   0x6562B0
#define EQItemList__add_item_x                                     0x629BA0
#define EQItemList__delete_item_x                                  0x629BF0
#define EQItemList__FreeItemList_x                                 0x629AF0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5BA9C0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6E1080
#define EQPlayer__dEQPlayer_x                                      0x6D4640
#define EQPlayer__DoAttack_x                                       0x6E9290
#define EQPlayer__EQPlayer_x                                       0x6D4D40
#define EQPlayer__SetNameSpriteState_x                             0x6D8F30
#define EQPlayer__SetNameSpriteTint_x                              0x6D9DC0
#define PlayerBase__HasProperty_j_x                                0xA2C060
#define EQPlayer__IsTargetable_x                                   0xA2C580
#define EQPlayer__CanSee_x                                         0xA2C3A0
#define PlayerZoneClient__ChangeHeight_x                           0x6EC330
#define EQPlayer__CanSee1_x                                        0xA2C490
#define PlayerBase__GetVisibilityLineSegment_x                     0xA2C120

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x6EE8F0
#define PlayerZoneClient__IsValidTeleport_x                        0x6575D0
#define PlayerZoneClient__LegalPlayerRace_x                        0x5D57E0


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6E3EC0
#define EQPlayerManager__GetSpawnByName_x                          0x6E3EE0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6E3F70

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6A3E80
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6A3EC0
#define KeypressHandler__ClearCommandStateArray_x                  0x6A52C0
#define KeypressHandler__HandleKeyDown_x                           0x6A52E0
#define KeypressHandler__HandleKeyUp_x                             0x6A5380
#define KeypressHandler__SaveKeymapping_x                          0x6A5810

// MapViewMap 
#define MapViewMap__Clear_x                                        0x814400
#define MapViewMap__SaveEx_x                                       0x817A30
#define MapViewMap__SetZoom_x                                      0x81C850

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x96B7E0

// StringTable 
#define StringTable__getString_x                                   0x966610

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6CE810
#define PcZoneClient__RemovePetEffect_x                            0x6CEE50
#define PcZoneClient__HasAlternateAbility_x                        0x6C84E0
#define PcZoneClient__GetCurrentMod_x                              0x577F00
#define PcZoneClient__GetModCap_x                                  0x577E00
#define PcZoneClient__CanEquipItem_x                               0x6C8AE0
#define PcZoneClient__GetItemByID_x                                0x6CBD20
#define PcZoneClient__GetItemByItemClass_x                         0x6CBDB0
#define PcZoneClient__RemoveBuffEffect_x                           0x6CEE70

//Doors
#define EQSwitch__UseSwitch_x                                      0x65C290

//IconCache
#define IconCache__GetIcon_x                                       0x7AF5F0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7A6830
#define CContainerMgr__CloseContainer_x                            0x7A6B20

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x875090

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x698320

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5F6F20
#define EQ_Spell__SpellAffects_x                                   0x5F73B0
#define EQ_Spell__SpellAffectBase_x                                0x5F7150
#define CharacterZoneClient__CalcAffectChange_x                    0x556B70
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x556D40
#define CLootWnd__LootAll_x                                        0x809E20
#define CLootWnd__RequestLootSlot_x                                0x809140
#define EQ_Spell__IsStackable_x                                    0x55C660
#define EQ_Spell__GetSpellAffectBySlot_x                           0x55C3F0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x548F50
#define EQ_Spell__IsSPAStacking_x                                  0x5F7FA0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5F7710
#define EQ_Spell__IsNoRemove_x                                     0x53A970
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5F7FB0

#define __IsResEffectSpell_x                                       0x55BB70

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x53F250

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x9776D0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8BE850
#define CTargetWnd__WndNotification_x                              0x8BE0D0
#define CTargetWnd__RefreshTargetBuffs_x                           0x8BE3A0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8BD130

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8C35B0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5F1F90
#define EqSoundManager__PlayScriptMp3_x                            0x5F20A0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5AB950

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9E57C0
#define CSidlManager__FindAnimation1_x                             0x9D7D10

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5E5A10
#define CAltAbilityData__GetMercMaxRank_x                          0x5E59B0
#define CAltAbilityData__GetMaxRank_x                              0x5D9FA0

//CTargetRing
#define CTargetRing__Cast_x                                        0x695BD0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x55C3A0
#define CharacterBase__CreateItemGlobalIndex_x                     0x578680
#define CharacterBase__CreateItemIndex_x                           0x623060
#define CharacterBase__GetItemPossession_x                         0x548DA0
#define CharacterBase__GetItemByGlobalIndex_x                      0x97FD20
#define CharacterBase__GetEffectId_x                               0x55C320

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x78DFA0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x78E7C0

//messages
#define msg_spell_worn_off_x                                       0x61C240
#define msg_new_text_x                                             0x610F50
#define __msgTokenTextParam_x                                      0x61E900
#define msgTokenText_x                                             0x61EB70

//SpellManager
#define SpellManager__vftable_x                                    0xAC3250
#define SpellManager__SpellManager_x                               0x580DF0
#define Spellmanager__LoadTextSpells_x                             0x70CF10

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0xA30110

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5917A0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x548980
#define ItemGlobalIndex__IsEquippedLocation_x                      0x55C620
#define ItemGlobalIndex__IsValidIndex_x                            0x55C760

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x977FF0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x978280

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x802010

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7AB4E0
#define CCursorAttachment__Deactivate_x                            0x7AC4A0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9F7F30
#define CEQSuiteTextureLoader__GetTexture_x                        0x9F7BC0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x58E310

//IString
#define IString__Append_x                                          0x581B00

//Camera
#define CDisplay__cameraType_x                                     0xE70EB8
#define EverQuest__Cameras_x                                       0xF33A24

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x596E40
#define pinstLootFiltersManager_x                                  0xD3F2A8
#define LootFiltersManager__GetItemFilterData_x                    0x596710
#define LootFiltersManager__RemoveItemLootFilter_x                 0x596740
#define LootFiltersManager__SetItemLootFilter_x                    0x596970
