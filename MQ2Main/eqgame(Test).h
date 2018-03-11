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
#define __ExpectedVersionDate                                     "Mar  9 2018"
#define __ExpectedVersionTime                                     "14:46:10"
#define __ActualVersionDate_x                                      0xADBC88
#define __ActualVersionTime_x                                      0xADBC7C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x6AA230
#define __MemChecker1_x                                            0x99D4E0
#define __MemChecker2_x                                            0x742930
#define __MemChecker3_x                                            0x742870
#define __MemChecker4_x                                            0x8F7B30
#define __EncryptPad0_x                                            0xC411A0
#define __EncryptPad1_x                                            0xD1B1B0
#define __EncryptPad2_x                                            0xC6ADA0
#define __EncryptPad3_x                                            0xC6A9A0
#define __EncryptPad4_x                                            0xD0BF20
#define __EncryptPad5_x                                            0xFBFD7C
#define __AC1_x                                                    0x8B3026
#define __AC2_x                                                    0x663E8D
#define __AC3_x                                                    0x66AD3D
#define __AC4_x                                                    0x66EC4E
#define __AC5_x                                                    0x674E83
#define __AC6_x                                                    0x679350
#define __AC7_x                                                    0x6638FE
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0xD3EDC

// Direct Input
#define DI8__Main_x                                                0xFBFE28
#define DI8__Keyboard_x                                            0xFBFE2C
#define DI8__Mouse_x                                               0xFBFF44
#define DI8__Mouse_Copy_x                                          0xF35BD4
#define DI8__Mouse_Check_x                                         0xFC0268
#define __AutoSkillArray_x                                         0xF36AE4
#define __Attack_x                                                 0xFBD537
#define __Autofire_x                                               0xFBD538
#define __BindList_x                                               0xC1C868
#define g_eqCommandStates_x                                        0xC1D610
#define __Clicks_x                                                 0xF35C8C
#define __CommandList_x                                            0xC1F278
#define __CurrentMapLabel_x                                        0x10D0F00
#define __CurrentSocial_x                                          0xBEBC64
#define __DoAbilityList_x                                          0xF6C3E0
#define __do_loot_x                                                0x630740
#define __DrawHandler_x                                            0x173AA18
#define __GroupCount_x                                             0xF25F5A

#define __Guilds_x                                                 0xF2BE40
#define __gWorld_x                                                 0xF2679C
#define __HotkeyPage_x                                             0xFB60FC
#define __HWnd_x                                                   0xFBFF48
#define __InChatMode_x                                             0xF35BBC
#define __LastTell_x                                               0xF37ADC
#define __LMouseHeldTime_x                                         0xF35CF8
#define __Mouse_x                                                  0xFBFE10
#define __MouseLook_x                                              0xF35C52
#define __MouseEventTime_x                                         0xFBDCF0
#define __gpbCommandEvent_x                                        0xF26150
#define __NetStatusToggle_x                                        0xF35C55
#define __PCNames_x                                                0xF370A0
#define __RangeAttackReady_x                                       0xF36DC8
#define __RMouseHeldTime_x                                         0xF35CF4
#define __RunWalkState_x                                           0xF35BC0
#define __ScreenMode_x                                             0xE74EB8
#define __ScreenX_x                                                0xF35B74
#define __ScreenY_x                                                0xF35B70
#define __ScreenXMax_x                                             0xF35B78
#define __ScreenYMax_x                                             0xF35B7C
#define __ServerHost_x                                             0xF263B3
#define __ServerName_x                                             0xF6C3A0
#define __ShiftKeyDown_x                                           0xF3624C
#define __ShowNames_x                                              0xF36F80
#define __Socials_x                                                0xF6C4A0
#define __SubscriptionType_x                                       0x110173C
#define __TargetAggroHolder_x                                      0x10D30C4
#define __ZoneType_x                                               0xF36050
#define __GroupAggro_x                                             0x10D3104
#define __LoginName_x                                              0x10CAC84
#define __Inviter_x                                                0xFBD4B4
#define __AttackOnAssist_x                                         0xF36F3C
#define __UseTellWindows_x                                         0xF37238

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF287D0
#define instEQZoneInfo_x                                           0xF35E48
#define instKeypressHandler_x                                      0xFBDCD0
#define pinstActiveBanker_x                                        0xF25EAC
#define pinstActiveCorpse_x                                        0xF287B0
#define pinstActiveGMaster_x                                       0xF25EA8
#define pinstActiveMerchant_x                                      0xF287AC
#define pinstAggroInfo_x                                           0xD31CA8
#define pinstAltAdvManager_x                                       0xE75820
#define pinstAuraMgr_x                                             0xD42470
#define pinstBandageTarget_x                                       0xF25EBC
#define pinstCamActor_x                                            0xE74EAC
#define pinstCDBStr_x                                              0xE74648
#define pinstCDisplay_x                                            0xF25F08
#define pinstCEverQuest_x                                          0xFBFD88
#define pinstEverQuestInfo_x                                       0xF35B68
#define pinstCharData_x                                            0xF25F34
#define pinstCharSpawn_x                                           0xF25EF8
#define pinstControlledMissile_x                                   0xF25F10
#define pinstControlledPlayer_x                                    0xF25EF8
#define pinstCSidlManager_x                                        0x1739C68
#define pinstCXWndManager_x                                        0x1739C64
#define instDynamicZone_x                                          0xF35A08
#define pinstDZMember_x                                            0xF35B18
#define pinstDZTimerInfo_x                                         0xF35B1C
#define pinstEQItemList_x                                          0xF24C50
#define pinstEQObjectList_x                                        0xF25C88
#define instEQMisc_x                                               0xE745A8
#define pinstEQSoundManager_x                                      0xE75E10
#define pinstEQSpellStrings_x                                      0xD3FAF0
#define instExpeditionLeader_x                                     0xF35A52
#define instExpeditionName_x                                       0xF35A92
#define pinstGroup_x                                               0xF25F56
#define pinstImeManager_x                                          0x1739C60
#define pinstLocalPlayer_x                                         0xF287A8
#define pinstMercenaryData_x                                       0xFBE344
#define pinstMercenaryStats_x                                      0x10D3210
#define pinstMercAltAbilities_x                                    0xE75C40
#define pinstModelPlayer_x                                         0xF25EB4
#define pinstPCData_x                                              0xF25F34
#define pinstSkillMgr_x                                            0xFBF398
#define pinstSpawnManager_x                                        0xFBEBC0
#define pinstSpellManager_x                                        0xFBF4E8
#define pinstSpellSets_x                                           0xFB6160
#define pinstStringTable_x                                         0xF26798
#define pinstSwitchManager_x                                       0xF25DB8
#define pinstTarget_x                                              0xF25EF0
#define pinstTargetObject_x                                        0xF25EF4
#define pinstTargetSwitch_x                                        0xF25F3C
#define pinstTaskMember_x                                          0xE74468
#define pinstTrackTarget_x                                         0xF25EFC
#define pinstTradeTarget_x                                         0xF25EB0
#define instTributeActive_x                                        0xE745CD
#define pinstViewActor_x                                           0xE74EA4
#define pinstWorldData_x                                           0xF26154
#define pinstZoneAddr_x                                            0xF360E8
#define pinstPlayerPath_x                                          0xFBEC28
#define pinstTargetIndicator_x                                     0xFBF690
#define pinstCTargetManager_x                                      0xFBF6F8
#define EQObject_Top_x                                             0xF267A4
#define pinstRealEstateItems_x                                     0xFBF2F0
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE74EE8
#define pinstCAchievementsWnd_x                                    0xE746B8
#define pinstCActionsWnd_x                                         0xE74E38
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE74D7C
#define pinstCAdvancedLootWnd_x                                    0xE746CC
#define pinstCAdventureLeaderboardWnd_x                            0x10CB990
#define pinstCAdventureRequestWnd_x                                0x10CBA10
#define pinstCAdventureStatsWnd_x                                  0x10CBA90
#define pinstCAggroMeterWnd_x                                      0xE74E24
#define pinstCAlarmWnd_x                                           0xE74E20
#define pinstCAlertHistoryWnd_x                                    0xE74E18
#define pinstCAlertStackWnd_x                                      0xE74970
#define pinstCAlertWnd_x                                           0xE74D90
#define pinstCAltStorageWnd_x                                      0x10CBD00
#define pinstCAudioTriggersWindow_x                                0xD31FD0
#define pinstCAuraWnd_x                                            0xE74DF4
#define pinstCAvaZoneWnd_x                                         0xE74F18
#define pinstCBandolierWnd_x                                       0xE74E30
#define pinstCBankWnd_x                                            0xE7496C
#define pinstCBarterMerchantWnd_x                                  0x10CCA50
#define pinstCBarterSearchWnd_x                                    0x10CCAD0
#define pinstCBarterWnd_x                                          0x10CCB50
#define pinstCBazaarConfirmationWnd_x                              0xE74EA0
#define pinstCBazaarSearchWnd_x                                    0xE74DB4
#define pinstCBazaarWnd_x                                          0xE74E70
#define pinstCBlockedBuffWnd_x                                     0xE74DDC
#define pinstCBlockedPetBuffWnd_x                                  0xE74E08
#define pinstCBodyTintWnd_x                                        0xE74904
#define pinstCBookWnd_x                                            0xE74E48
#define pinstCBreathWnd_x                                          0xE74EF4
#define pinstCBuffWindowNORMAL_x                                   0xE74DC4
#define pinstCBuffWindowSHORT_x                                    0xE74DC8
#define pinstCBugReportWnd_x                                       0xE74F24
#define pinstCCastingWnd_x                                         0xE74DD8
#define pinstCCastSpellWnd_x                                       0xE74E84
#define pinstCCharacterListWnd_x                                   0xE746D8
#define pinstCChatWindowManager_x                                  0x10CD370
#define pinstCClaimWnd_x                                           0x10CD468
#define pinstCColorPickerWnd_x                                     0xE74E9C
#define pinstCCombatAbilityWnd_x                                   0xE74ED0
#define pinstCCombatSkillsSelectWnd_x                              0xE748E0
#define pinstCCompassWnd_x                                         0xE74900
#define pinstCConfirmationDialog_x                                 0x10D17B0
#define pinstCContainerMgr_x                                       0xE74E88
#define pinstCContextMenuManager_x                                 0x1739C18
#define pinstCCursorAttachment_x                                   0xE74DD0
#define pinstCDynamicZoneWnd_x                                     0x10CD8B0
#define pinstCEditLabelWnd_x                                       0xE74DCC
#define pinstCEQMainWnd_x                                          0x10CDA78
#define pinstCEventCalendarWnd_x                                   0xE74DE4
#define pinstCFacePick_x                                           0xE74D78
#define pinstCFeedbackWnd_x                                        0xE74F04
#define pinstCFellowshipWnd_x                                      0x10CDC60
#define pinstCFileSelectionWnd_x                                   0xE74F1C
#define pinstCFindItemWnd_x                                        0xE74F3C
#define pinstCFindLocationWnd_x                                    0x10CDD58
#define pinstCFriendsWnd_x                                         0xE748EC
#define pinstCGemsGameWnd_x                                        0xE74DF0
#define pinstCGiveWnd_x                                            0xE74E7C
#define pinstCGroupSearchFiltersWnd_x                              0xE74E44
#define pinstCGroupSearchWnd_x                                     0x10CE030
#define pinstCGroupWnd_x                                           0x10CE0B0
#define pinstCGuildBankWnd_x                                       0x10CE130
#define pinstCGuildCreationWnd_x                                   0x10CE1B0
#define pinstCGuildMgmtWnd_x                                       0x10CE230
#define pinstCharacterCreation_x                                   0xE746D0
#define pinstCHelpWnd_x                                            0xE74DB8
#define pinstCHeritageSelectionWnd_x                               0xE74D94
#define pinstCHotButtonWnd_x                                       0x10D032C
#define pinstCHotButtonWnd1_x                                      0x10D032C
#define pinstCHotButtonWnd2_x                                      0x10D0330
#define pinstCHotButtonWnd3_x                                      0x10D0334
#define pinstCHotButtonWnd4_x                                      0x10D035C
#define pinstCIconSelectionWnd_x                                   0xE74E2C
#define pinstCInspectWnd_x                                         0xE74EE4
#define pinstCInventoryWnd_x                                       0xE74F28
#define pinstCInvSlotMgr_x                                         0xE74E40
#define pinstCItemDisplayManager_x                                 0x10D07B8
#define pinstCItemExpTransferWnd_x                                 0x10D08B8
#define pinstCItemOverflowWnd_x                                    0xE74DC0
#define pinstCJournalCatWnd_x                                      0xE74F30
#define pinstCJournalTextWnd_x                                     0xE74EEC
#define pinstCKeyRingWnd_x                                         0xE748E4
#define pinstCLargeDialogWnd_x                                     0x10D20D0
#define pinstCLayoutCopyWnd_x                                      0x10D0B18
#define pinstCLFGuildWnd_x                                         0x10D0B98
#define pinstCLoadskinWnd_x                                        0xE74E10
#define pinstCLootFiltersCopyWnd_x                                 0xD42A48
#define pinstCLootFiltersWnd_x                                     0xE74EF8
#define pinstCLootSettingsWnd_x                                    0xE74F0C
#define pinstCLootWnd_x                                            0xE74DEC
#define pinstCMailAddressBookWnd_x                                 0xE74F10
#define pinstCMailCompositionWnd_x                                 0xE74EF0
#define pinstCMailIgnoreListWnd_x                                  0xE74F14
#define pinstCMailWnd_x                                            0xE74ED4
#define pinstCManageLootWnd_x                                      0xE75B48
#define pinstCMapToolbarWnd_x                                      0xE74DAC
#define pinstCMapViewWnd_x                                         0xE74D88
#define pinstCMarketplaceWnd_x                                     0xE74D98
#define pinstCMerchantWnd_x                                        0xE74DA4
#define pinstCMIZoneSelectWnd_x                                    0x10D1190
#define pinstCMusicPlayerWnd_x                                     0xE74E74
#define pinstCNameChangeMercWnd_x                                  0xE746C0
#define pinstCNameChangePetWnd_x                                   0xE74F2C
#define pinstCNameChangeWnd_x                                      0xE748E8
#define pinstCNoteWnd_x                                            0xE74D9C
#define pinstCObjectPreviewWnd_x                                   0xE74DB0
#define pinstCOptionsWnd_x                                         0xE74D84
#define pinstCPetInfoWnd_x                                         0xE74E8C
#define pinstCPetitionQWnd_x                                       0xE74ECC
#define pinstCPlayerNotesWnd_x                                     0xE74D8C
#define pinstCPlayerWnd_x                                          0xE74DE0
#define pinstCPopupWndManager_x                                    0x10D17B0
#define pinstCProgressionSelectionWnd_x                            0x10D1830
#define pinstCPurchaseGroupWnd_x                                   0xE74DF8
#define pinstCPurchaseWnd_x                                        0xE74DD4
#define pinstCPvPLeaderboardWnd_x                                  0x10D18B0
#define pinstCPvPStatsWnd_x                                        0x10D1930
#define pinstCQuantityWnd_x                                        0xE74DA8
#define pinstCRaceChangeWnd_x                                      0xE74D80
#define pinstCRaidOptionsWnd_x                                     0xE74E3C
#define pinstCRaidWnd_x                                            0xE74EDC
#define pinstCRealEstateItemsWnd_x                                 0xE74F34
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE74EC8
#define pinstCRealEstateManageWnd_x                                0xE74E1C
#define pinstCRealEstateNeighborhoodWnd_x                          0xE74E34
#define pinstCRealEstatePlotSearchWnd_x                            0xE74E4C
#define pinstCRealEstatePurchaseWnd_x                              0xE74E78
#define pinstCRespawnWnd_x                                         0xE74E14
#define pinstCSelectorWnd_x                                        0xE74E28
#define pinstCSendMoneyWnd_x                                       0xE74E90
#define pinstCServerListWnd_x                                      0xE74DBC
#define pinstCSkillsSelectWnd_x                                    0xE746BC
#define pinstCSkillsWnd_x                                          0xE74F20
#define pinstCSocialEditWnd_x                                      0xE74F00
#define pinstCSocialWnd_x                                          0xE74E94
#define pinstCSpellBookWnd_x                                       0xE74ED8
#define pinstCStoryWnd_x                                           0xE746DC
#define pinstCTargetOfTargetWnd_x                                  0x10D3298
#define pinstCTargetWnd_x                                          0xE74E00
#define pinstCTaskOverlayWnd_x                                     0xE746C8
#define pinstCTaskSelectWnd_x                                      0x10D3390
#define pinstCTaskSomething_x                                      0xD43010
#define pinstCTaskTemplateSelectWnd_x                              0x10D3410
#define pinstCTaskWnd_x                                            0x10D3490
#define pinstCTextEntryWnd_x                                       0xE74DA0
#define pinstCTextOverlay_x                                        0xD321E8
#define pinstCTimeLeftWnd_x                                        0xE74E98
#define pinstCTipWndCONTEXT_x                                      0x10D3604
#define pinstCTipWndOFDAY_x                                        0x10D3600
#define pinstCTitleWnd_x                                           0x10D3680
#define pinstCTrackingWnd_x                                        0xE74EC0
#define pinstCTradeskillWnd_x                                      0x10D3788
#define pinstCTradeWnd_x                                           0xE74DFC
#define pinstCTrainWnd_x                                           0xE74EA8
#define pinstCTributeBenefitWnd_x                                  0x10D38F8
#define pinstCTributeMasterWnd_x                                   0x10D3978
#define pinstCTributeTrophyWnd_x                                   0x10D39F8
#define pinstCVideoModesWnd_x                                      0xE74E80
#define pinstCVoiceMacroWnd_x                                      0xFBFAF8
#define pinstCVoteResultsWnd_x                                     0xE74F08
#define pinstCVoteWnd_x                                            0xE74EFC
#define pinstCWebManager_x                                         0xFBFBFC
#define pinstCZoneGuideWnd_x                                       0xE74DE8
#define pinstCZonePathWnd_x                                        0xE74E04
#define pinstEQSuiteTextureLoader_x                                0xD1CA44
#define pinstItemIconCache_x                                       0x10CDA20
#define pinstRewardSelectionWnd_x                                  0x10D1E68

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC6A994
#define __CastRay_x                                                0x62BAB0
#define __CastRay2_x                                               0x62BB00
#define __ConvertItemTags_x                                        0x646A20
#define __CrashHandler_x                                           0x9017A0
#define __EQGetTime_x                                              0x99CE20
#define __ExecuteCmd_x                                             0x6243B0
#define __FixHeading_x                                             0xA2C590
#define __get_bearing_x                                            0x62B5F0
#define __get_melee_range_x                                        0x62BD30
#define __GetAnimationCache_x                                      0x7AE480
#define __GetGaugeValueFromEQ_x                                    0x8B1820
#define __GetLabelFromEQ_x                                         0x8B2FB0
#define __GetXTargetType_x                                         0xA2E070
#define __HeadingDiff_x                                            0xA2C600
#define __HelpPath_x                                               0xFBDA4C
#define __LoadFrontEnd_x                                           0x73E250
#define __NewUIINI_x                                               0x8B14F0
#define __pCrashHandler_x                                          0x10E06A8
#define __ProcessGameEvents_x                                      0x689F40
#define __ProcessMouseEvent_x                                      0x689710
#define __STMLToText_x                                             0x9D0DF0
#define __ToggleKeyRingItem_x                                      0x594A90
#define CrashDetected_x                                            0x73FEE0
#define DrawNetStatus_x                                            0x6B9860
#define Expansion_HoT_x                                            0xF36F2C
#define Teleport_Table_Size_x                                      0xF261DC
#define Teleport_Table_x                                           0xF267A8
#define Util__FastTime_x                                           0x99CA10
#define wwsCrashReportCheckForUploader_x                           0x902400
#define wwsCrashReportPlatformLaunchUploader_x                     0x904A50
#define __SaveColors_x                                             0x5D36F0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x51EF90
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x527FA0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x527D80

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5DBF20
#define AltAdvManager__IsAbilityReady_x                            0x5DAF90
#define AltAdvManager__GetAAById_x                                 0x5DB190
#define AltAdvManager__CanTrainAbility_x                           0x5DB200
#define AltAdvManager__CanSeeAbility_x                             0x5DB430

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x55CE90
#define CharacterZoneClient__HasSkill_x                            0x568620
#define CharacterZoneClient__MakeMeVisible_x                       0x569D50
#define CharacterZoneClient__IsStackBlocked_x                      0x5509D0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x54CF90
#define CharacterZoneClient__GetItemCountWorn_x                    0x56C4E0
#define CharacterZoneClient__GetItemCountInInventory_x             0x56C5C0
#define CharacterZoneClient__GetCursorItemCount_x                  0x56C6A0
#define CharacterZoneClient__FindAffectSlot_x                      0x555700
#define CharacterZoneClient__BardCastBard_x                        0x5586E0
#define CharacterZoneClient__GetMaxEffects_x                       0x54D060
#define CharacterZoneClient__GetEffect_x                           0x54CED0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x556780
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x556850
#define CharacterZoneClient__GetLastEffectSlot_x                   0x5568A0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x76D2C0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x77B520

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x699160
#define CButtonWnd__CButtonWnd_x                                   0x9CD190

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x79BA60
#define CChatManager__InitContextMenu_x                            0x795E10
#define CChatManager__FreeChatWindow_x                             0x79A980
#define CChatManager__GetLockedActiveChatWindow_x                  0x79F670
#define CChatManager__SetLockedActiveChatWindow_x                  0x79B7F0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9E1930
#define CContextMenu__dCContextMenu_x                              0x9E1B70
#define CContextMenu__AddMenuItem_x                                0x9E1B80
#define CContextMenu__RemoveMenuItem_x                             0x9E1E80
#define CContextMenu__RemoveAllMenuItems_x                         0x9E1EA0
#define CContextMenu__CheckMenuItem_x                              0x9E1F20
#define CContextMenu__SetMenuItem_x                                0x9E1DA0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9E24F0
#define CContextMenuManager__RemoveMenu_x                          0x9E2560
#define CContextMenuManager__PopupMenu_x                           0x9E2620
#define CContextMenuManager__Flush_x                               0x9E2490
#define CContextMenuManager__GetMenu_x                             0x529FA0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x980810
#define CChatService__GetFriendName_x                              0x980820

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x79C000
#define CChatWindow__Clear_x                                       0x79D0D0
#define CChatWindow__WndNotification_x                             0x79D630

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x9DEEC0
#define CComboWnd__Draw_x                                          0x9DE380
#define CComboWnd__GetCurChoice_x                                  0x9DED00
#define CComboWnd__GetListRect_x                                   0x9DE850
#define CComboWnd__GetTextRect_x                                   0x9DEF30
#define CComboWnd__InsertChoice_x                                  0x9DE9F0
#define CComboWnd__SetColors_x                                     0x9DE9C0
#define CComboWnd__SetChoice_x                                     0x9DECD0
#define CComboWnd__GetItemCount_x                                  0x9DED10
#define CComboWnd__GetCurChoiceText_x                              0x9DED50

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7A6000
#define CContainerWnd__vftable_x                                   0xAE57A0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x5D34C0
#define CDisplay__GetClickedActor_x                                0x5C5FE0
#define CDisplay__GetUserDefinedColor_x                            0x5BE410
#define CDisplay__GetWorldFilePath_x                               0x5C7A30
#define CDisplay__is3dON_x                                         0x5C2C30
#define CDisplay__ReloadUI_x                                       0x5CD090
#define CDisplay__WriteTextHD2_x                                   0x5C2A00
#define CDisplay__TrueDistance_x                                   0x5C9690

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0xA00E60

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9E5400
#define CEditWnd__GetCharIndexPt_x                                 0x9E6390
#define CEditWnd__GetDisplayString_x                               0x9E6210
#define CEditWnd__GetHorzOffset_x                                  0x9E4A00
#define CEditWnd__GetLineForPrintableChar_x                        0x9E74D0
#define CEditWnd__GetSelStartPt_x                                  0x9E6660
#define CEditWnd__GetSTMLSafeText_x                                0x9E6020
#define CEditWnd__PointFromPrintableChar_x                         0x9E7100
#define CEditWnd__SelectableCharFromPoint_x                        0x9E7270
#define CEditWnd__SetEditable_x                                    0x9E6730

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x678880
#define CEverQuest__ClickedPlayer_x                                0x66AB20
#define CEverQuest__CreateTargetIndicator_x                        0x6871D0
#define CEverQuest__DeleteTargetIndicator_x                        0x687260
#define CEverQuest__DoTellWindow_x                                 0x5790C0
#define CEverQuest__OutputTextToLog_x                              0x579320
#define CEverQuest__DropHeldItemOnGround_x                         0x660600
#define CEverQuest__dsp_chat_x                                     0x579710
#define CEverQuest__trimName_x                                     0x683770
#define CEverQuest__Emote_x                                        0x679080
#define CEverQuest__EnterZone_x                                    0x673240
#define CEverQuest__GetBodyTypeDesc_x                              0x67CE70
#define CEverQuest__GetClassDesc_x                                 0x67D4B0
#define CEverQuest__GetClassThreeLetterCode_x                      0x67DAB0
#define CEverQuest__GetDeityDesc_x                                 0x685B90
#define CEverQuest__GetLangDesc_x                                  0x67DC70
#define CEverQuest__GetRaceDesc_x                                  0x67D490
#define CEverQuest__InterpretCmd_x                                 0x6861C0
#define CEverQuest__LeftClickedOnPlayer_x                          0x664590
#define CEverQuest__LMouseUp_x                                     0x6628B0
#define CEverQuest__RightClickedOnPlayer_x                         0x664EA0
#define CEverQuest__RMouseUp_x                                     0x6638C0
#define CEverQuest__SetGameState_x                                 0x6603A0
#define CEverQuest__UPCNotificationFlush_x                         0x683670
#define CEverQuest__IssuePetCommand_x                              0x67F080
#define CEverQuest__ReportSuccessfulHit_x                          0x679D30

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7B9BF0
#define CGaugeWnd__CalcLinesFillRect_x                             0x7B9C50
#define CGaugeWnd__Draw_x                                          0x7B9270

// CGuild
#define CGuild__FindMemberByName_x                                 0x541790
#define CGuild__GetGuildName_x                                     0x5407E0
#define CGuild__GetGuildIndex_x                                    0x540B60

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7D6570

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7E42E0
#define CInvSlotMgr__MoveItem_x                                    0x7E2E10
#define CInvSlotMgr__SelectSlot_x                                  0x7E43B0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7E1450
#define CInvSlot__SliderComplete_x                                 0x7DEF00
#define CInvSlot__GetItemBase_x                                    0x7DE8B0
#define CInvSlot__UpdateItem_x                                     0x7DEA20

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7E5BF0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7E4F10

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8AD350
#define CItemDisplayWnd__UpdateStrings_x                           0x7F4C70
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7EE550
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7EEAA0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7F51E0
#define CItemDisplayWnd__AboutToShow_x                             0x7F48C0
#define CItemDisplayWnd__WndNotification_x                         0x7F6700

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8E7E80

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7FADF0

// CLabel 
#define CLabel__Draw_x                                             0x801230

// CListWnd
#define CListWnd__CListWnd_x                                       0x9B7310
#define CListWnd__dCListWnd_x                                      0x9B7640
#define CListWnd__AddColumn_x                                      0x9BBB70
#define CListWnd__AddColumn1_x                                     0x9BBBC0
#define CListWnd__AddLine_x                                        0x9BBFA0
#define CListWnd__AddString_x                                      0x9BBD90
#define CListWnd__CalculateFirstVisibleLine_x                      0x9BB920
#define CListWnd__CalculateVSBRange_x                              0x9BB6E0
#define CListWnd__ClearSel_x                                       0x9BC770
#define CListWnd__ClearAllSel_x                                    0x9BC7D0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x9BD200
#define CListWnd__Compare_x                                        0x9BAFE0
#define CListWnd__Draw_x                                           0x9B7750
#define CListWnd__DrawColumnSeparators_x                           0x9B9FA0
#define CListWnd__DrawHeader_x                                     0x9BA410
#define CListWnd__DrawItem_x                                       0x9BA860
#define CListWnd__DrawLine_x                                       0x9BA110
#define CListWnd__DrawSeparator_x                                  0x9BA040
#define CListWnd__EnableLine_x                                     0x9B9870
#define CListWnd__EnsureVisible_x                                  0x9BD120
#define CListWnd__ExtendSel_x                                      0x9BC6A0
#define CListWnd__GetColumnMinWidth_x                              0x9B93C0
#define CListWnd__GetColumnWidth_x                                 0x9B9330
#define CListWnd__GetCurSel_x                                      0x9B8C90
#define CListWnd__GetItemAtPoint_x                                 0x9B9AF0
#define CListWnd__GetItemAtPoint1_x                                0x9B9B60
#define CListWnd__GetItemData_x                                    0x9B8D10
#define CListWnd__GetItemHeight_x                                  0x9B90F0
#define CListWnd__GetItemIcon_x                                    0x9B8EB0
#define CListWnd__GetItemRect_x                                    0x9B9960
#define CListWnd__GetItemText_x                                    0x9B8D50
#define CListWnd__GetSelList_x                                     0x9BC820
#define CListWnd__GetSeparatorRect_x                               0x9B9DA0
#define CListWnd__InsertLine_x                                     0x9BC380
#define CListWnd__RemoveLine_x                                     0x9BC4D0
#define CListWnd__SetColors_x                                      0x9BB6B0
#define CListWnd__SetColumnJustification_x                         0x9BB3D0
#define CListWnd__SetColumnWidth_x                                 0x9BB2E0
#define CListWnd__SetCurSel_x                                      0x9BC5E0
#define CListWnd__SetItemColor_x                                   0x9BCDD0
#define CListWnd__SetItemData_x                                    0x9BCD90
#define CListWnd__SetItemText_x                                    0x9BC9A0
#define CListWnd__ShiftColumnSeparator_x                           0x9BB490
#define CListWnd__Sort_x                                           0x9BB180
#define CListWnd__ToggleSel_x                                      0x9BC610

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x817E70

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x83CA80
#define CMerchantWnd__RequestBuyItem_x                             0x83D3C0
#define CMerchantWnd__RequestSellItem_x                            0x83D940
#define CMerchantWnd__SelectRecoverySlot_x                         0x840B60
//did this get another arg?
#define CMerchantWnd__SelectBuySellSlot_x                          0x83D140
#define CMerchantWnd__ActualSelect_x                               0x846850

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x94D440
#define CPacketScrambler__hton_x                                   0x94D430

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x9D6990
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9D6780
#define CSidlManager__CreateLabel_x                                0x8A3A40
#define CSidlManager__CreateXWndFromTemplate_x                     0x9D9B60
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9D9D30

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9D2F60
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9D2E60
#define CSidlScreenWnd__ConvertToRes_x                             0x9F7D80
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9D2940
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9D2620
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9D26F0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9D27C0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9D3400
#define CSidlScreenWnd__EnableIniStorage_x                         0x9D38D0
#define CSidlScreenWnd__GetSidlPiece_x                             0x9D35F0
#define CSidlScreenWnd__Init1_x                                    0x9D2210
#define CSidlScreenWnd__LoadIniInfo_x                              0x9D3920
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9D4470
#define CSidlScreenWnd__LoadSidlScreen_x                           0x9D1610
#define CSidlScreenWnd__StoreIniInfo_x                             0x9D3FF0
#define CSidlScreenWnd__StoreIniVis_x                              0x9D4350
#define CSidlScreenWnd__WndNotification_x                          0x9D3310
#define CSidlScreenWnd__GetChildItem_x                             0x9D3850
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9C2E40
#define CSidlScreenWnd__m_layoutCopy_x                             0x1739AA8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x703F70
#define CSkillMgr__GetSkillCap_x                                   0x704150
#define CSkillMgr__GetNameToken_x                                  0x7036F0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9F7440
#define CSliderWnd__SetValue_x                                     0x9F72B0
#define CSliderWnd__SetNumTicks_x                                  0x9F7310

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x8AA130

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9E9410
#define CStmlWnd__CalculateHSBRange_x                              0x9EA560
#define CStmlWnd__CalculateVSBRange_x                              0x9EA4D0
#define CStmlWnd__CanBreakAtCharacter_x                            0x9EF460
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9F0010
#define CStmlWnd__ForceParseNow_x                                  0x9E9A10
#define CStmlWnd__GetNextTagPiece_x                                0x9EF3C0
#define CStmlWnd__GetSTMLText_x                                    0x588130
#define CStmlWnd__GetVisibleText_x                                 0x9E9A30
#define CStmlWnd__InitializeWindowVariables_x                      0x9EFE60
#define CStmlWnd__MakeStmlColorTag_x                               0x9E8B30
#define CStmlWnd__MakeWndNotificationTag_x                         0x9E8BA0
#define CStmlWnd__SetSTMLText_x                                    0x9E7BC0
#define CStmlWnd__StripFirstSTMLLines_x                            0x9F12E0
#define CStmlWnd__UpdateHistoryString_x                            0x9F0220

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9F44A0
#define CTabWnd__DrawCurrentPage_x                                 0x9F4AF0
#define CTabWnd__DrawTab_x                                         0x9F48A0
#define CTabWnd__GetCurrentPage_x                                  0x9F3D00
#define CTabWnd__GetPageInnerRect_x                                0x9F3F40
#define CTabWnd__GetTabInnerRect_x                                 0x9F3E80
#define CTabWnd__GetTabRect_x                                      0x9F3D30
#define CTabWnd__InsertPage_x                                      0x9F4130
#define CTabWnd__SetPage_x                                         0x9F3FC0
#define CTabWnd__SetPageRect_x                                     0x9F43E0
#define CTabWnd__UpdatePage_x                                      0x9F4760
#define CTabWnd__GetPageFromTabIndex_x                             0x9F47E0
#define CTabWnd__GetCurrentTabIndex_x                              0x9F3CF0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7FB430
#define CPageWnd__SetTabText_x                                     0xA01250

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x53AB40

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x9BFC80
#define CTextureFont__GetTextExtent_x                              0x9BFE60

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x73A830
#define CHtmlComponentWnd__ValidateUri_x                           0x7D7E30
#define CHtmlWnd__SetClientCallbacks_x                             0x69DD70
#define CHtmlWnd__AddObserver_x                                    0x69DD90
#define CHtmlWnd__RemoveObserver_x                                 0x69DDF0
#define Window__getProgress_x                                      0x8FF170
#define Window__getStatus_x                                        0x8FF190
#define Window__getURI_x                                           0x8FF1A0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9FD8B0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x9ACB70

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x506120
#define CXStr__CXStr1_x                                            0x9FBB30
#define CXStr__CXStr3_x                                            0x998F70
#define CXStr__dCXStr_x                                            0x579CE0
#define CXStr__operator_equal_x                                    0x9991A0
#define CXStr__operator_equal1_x                                   0x9991E0
#define CXStr__operator_plus_equal1_x                              0x999C70

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9E1570
#define CXWnd__BringToTop_x                                        0x9C67A0
#define CXWnd__Center_x                                            0x9C6320

#define CXWnd__ClrFocus_x                                          0x9C6150
#define CXWnd__Destroy_x                                           0x9C6200
#define CXWnd__DoAllDrawing_x                                      0x9C25D0
#define CXWnd__DrawChildren_x                                      0x9C25A0
#define CXWnd__DrawColoredRect_x                                   0x9C2A30
#define CXWnd__DrawTooltip_x                                       0x9C10A0
#define CXWnd__DrawTooltipAtPoint_x                                0x9C1170
#define CXWnd__GetBorderFrame_x                                    0x9C2890
#define CXWnd__GetChildWndAt_x                                     0x9C6840
#define CXWnd__GetClientClipRect_x                                 0x9C4A60
#define CXWnd__GetScreenClipRect_x                                 0x9C4B00
#define CXWnd__GetScreenRect_x                                     0x9C4C80
#define CXWnd__GetTooltipRect_x                                    0x9C2A80
#define CXWnd__GetWindowTextA_x                                    0x52B980
#define CXWnd__IsActive_x                                          0x9C9690
#define CXWnd__IsDescendantOf_x                                    0x9C56A0
#define CXWnd__IsReallyVisible_x                                   0x9C56D0
#define CXWnd__IsType_x                                            0x9C6EC0
#define CScreenPieceTemplate__IsType_x                             0x9F8D50
#define CXWnd__Move_x                                              0x9C5750
#define CXWnd__Move1_x                                             0x9C5810
#define CXWnd__ProcessTransition_x                                 0x9C62D0
#define CXWnd__Refade_x                                            0x9C5AD0
#define CXWnd__Resize_x                                            0x9C5D60
#define CXWnd__Right_x                                             0x9C6560
#define CXWnd__SetFocus_x                                          0x9C6110
#define CXWnd__SetFont_x                                           0x9C6180
#define CXWnd__SetKeyTooltip_x                                     0x9C6CD0
#define CXWnd__SetMouseOver_x                                      0x9C39F0
#define CXWnd__StartFade_x                                         0x9C5570
#define CXWnd__GetChildItem_x                                      0x9C69B0
#define CXWnd__SetParent_x                                         0x9C5430

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9C96D0
#define CXWndManager__DrawWindows_x                                0x9C96F0
#define CXWndManager__GetKeyboardFlags_x                           0x9CBED0
#define CXWndManager__HandleKeyboardMsg_x                          0x9CBAD0
#define CXWndManager__RemoveWnd_x                                  0x9CC120
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9CC670

// CDBStr
#define CDBStr__GetString_x                                        0x5BD290

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x54DF00
#define EQ_Character__Cur_HP_x                                     0x565530
#define EQ_Character__Cur_Mana_x                                   0x56CB10
#define EQ_Character__GetAACastingTimeModifier_x                   0x550FA0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x544760
#define EQ_Character__GetFocusRangeModifier_x                      0x5448D0
#define EQ_Character__GetHPRegen_x                                 0x5723E0
#define EQ_Character__GetEnduranceRegen_x                          0x572A20
#define EQ_Character__GetManaRegen_x                               0x572E70
#define EQ_Character__Max_Endurance_x                              0x6C7830
#define EQ_Character__Max_HP_x                                     0x565360
#define EQ_Character__Max_Mana_x                                   0x6C76B0
#define EQ_Character__doCombatAbility_x                            0x6C9B70
#define EQ_Character__UseSkill_x                                   0x574DB0
#define EQ_Character__GetConLevel_x                                0x6C0AE0
#define EQ_Character__IsExpansionFlag_x                            0x5BD1B0
#define EQ_Character__TotalEffect_x                                0x557C60
#define EQ_Character__GetPCSpellAffect_x                           0x551BC0
#define EQ_Character__SpellDuration_x                              0x5516D0
#define EQ_Character__FindItemByRecord_x                           0x56AD60
#define EQ_Character__GetAdjustedSkill_x                           0x5683E0
#define EQ_Character__GetBaseSkill_x                               0x569380
#define EQ_Character__CanUseItem_x                                 0x56CE40

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x96BEC0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6DE060

//PcClient
#define PcClient__PcClient_x                                       0x6BE440

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x54B9F0
#define CCharacterListWnd__EnterWorld_x                            0x54B410
#define CCharacterListWnd__Quit_x                                  0x54B120
#define CCharacterListWnd__UpdateList_x                            0x54B5B0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x69F0C0
#define EQ_Item__CreateItemTagString_x                             0x9475F0
#define EQ_Item__IsStackable_x                                     0x94B840
#define EQ_Item__GetImageNum_x                                     0x948E80
#define EQ_Item__CreateItemClient_x                                0x69E3B0
#define EQ_Item__GetItemValue_x                                    0x949F30
#define EQ_Item__ValueSellMerchant_x                               0x94D030
#define EQ_Item__IsKeyRingItem_x                                   0x94B200
#define EQ_Item__CanGoInBag_x                                      0x69F1E0
#define EQ_Item__GetMaxItemCount_x                                 0x94A030
#define EQ_Item__GetHeldItem_x                                     0x948C90
#define EQ_Item__GetAugmentFitBySlot_x                             0x947110

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5DCE20
#define EQ_LoadingS__Array_x                                       0xC0C4A0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6C81D0
#define EQ_PC__GetAlternateAbilityId_x                             0x955FE0
#define EQ_PC__GetCombatAbility_x                                  0x956660
#define EQ_PC__GetCombatAbilityTimer_x                             0x9566D0
#define EQ_PC__GetItemRecastTimer_x                                0x6CA100
#define EQ_PC__HasLoreItem_x                                       0x6C12B0
#define EQ_PC__AlertInventoryChanged_x                             0x6C05E0
#define EQ_PC__GetPcZoneClient_x                                   0x6ED1B0
#define EQ_PC__RemoveMyAffect_x                                    0x6CD4B0
#define EQ_PC__GetKeyRingItems_x                                   0x956F70
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x956CF0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x957260

// EQItemList 
#define EQItemList__EQItemList_x                                   0x628EC0
#define EQItemList__add_object_x                                   0x6556C0
#define EQItemList__add_item_x                                     0x6294B0
#define EQItemList__delete_item_x                                  0x629500
#define EQItemList__FreeItemList_x                                 0x629400

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5BA820

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6DF8F0
#define EQPlayer__dEQPlayer_x                                      0x6D2EB0
#define EQPlayer__DoAttack_x                                       0x6E7B90
#define EQPlayer__EQPlayer_x                                       0x6D35B0
#define EQPlayer__SetNameSpriteState_x                             0x6D77A0
#define EQPlayer__SetNameSpriteTint_x                              0x6D8630
#define PlayerBase__HasProperty_j_x                                0xA2A860
#define EQPlayer__IsTargetable_x                                   0xA2AD80
#define EQPlayer__CanSee_x                                         0xA2ABA0
#define PlayerZoneClient__ChangeHeight_x                           0x6EAC30
#define EQPlayer__CanSee1_x                                        0xA2AC90
#define PlayerBase__GetVisibilityLineSegment_x                     0xA2A920

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x6ED1F0
#define PlayerZoneClient__IsValidTeleport_x                        0x6569E0
#define PlayerZoneClient__LegalPlayerRace_x                        0x5D54B0


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6E27A0
#define EQPlayerManager__GetSpawnByName_x                          0x6E27C0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6E2850

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6A3120
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6A3160
#define KeypressHandler__ClearCommandStateArray_x                  0x6A4550
#define KeypressHandler__HandleKeyDown_x                           0x6A4570
#define KeypressHandler__HandleKeyUp_x                             0x6A4610
#define KeypressHandler__SaveKeymapping_x                          0x6A4AA0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x8139C0
#define MapViewMap__SaveEx_x                                       0x816FF0
#define MapViewMap__SetZoom_x                                      0x81BE10

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x969E20

// StringTable 
#define StringTable__getString_x                                   0x964D20

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6CD110
#define PcZoneClient__RemovePetEffect_x                            0x6CD750
#define PcZoneClient__HasAlternateAbility_x                        0x6C74C0
#define PcZoneClient__GetCurrentMod_x                              0x577CA0
#define PcZoneClient__GetModCap_x                                  0x577BA0
#define PcZoneClient__CanEquipItem_x                               0x6C7AC0
#define PcZoneClient__GetItemByID_x                                0x6CA620
#define PcZoneClient__GetItemByItemClass_x                         0x6CA6B0
#define PcZoneClient__RemoveBuffEffect_x                           0x6CD770

//Doors
#define EQSwitch__UseSwitch_x                                      0x65B6A0

//IconCache
#define IconCache__GetIcon_x                                       0x7ADCF0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7A4F80
#define CContainerMgr__CloseContainer_x                            0x7A5270

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x873A50

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x697740

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5F70D0
#define EQ_Spell__SpellAffects_x                                   0x5F7560
#define EQ_Spell__SpellAffectBase_x                                0x5F7300
#define CharacterZoneClient__CalcAffectChange_x                    0x5569F0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x556BC0
#define CLootWnd__LootAll_x                                        0x809370
#define CLootWnd__RequestLootSlot_x                                0x808690
#define EQ_Spell__IsStackable_x                                    0x55C520
#define EQ_Spell__GetSpellAffectBySlot_x                           0x55C2D0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x548E00
#define EQ_Spell__IsSPAStacking_x                                  0x5F8150
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5F78C0
#define EQ_Spell__IsNoRemove_x                                     0x53A890
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5F8160

#define __IsResEffectSpell_x                                       0x55BA00

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x53F100

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x975D20

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8BD1F0
#define CTargetWnd__WndNotification_x                              0x8BCA70
#define CTargetWnd__RefreshTargetBuffs_x                           0x8BCD40
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8BBAC0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8C1F20

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5F2140
#define EqSoundManager__PlayScriptMp3_x                            0x5F2250

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5AB760

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9E4100
#define CSidlManager__FindAnimation1_x                             0x9D6580

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5E5770
#define CAltAbilityData__GetMercMaxRank_x                          0x5E5710
#define CAltAbilityData__GetMaxRank_x                              0x5D9CD0

//CTargetRing
#define CTargetRing__Cast_x                                        0x695000

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x55C280
#define CharacterBase__CreateItemGlobalIndex_x                     0x5783E0
#define CharacterBase__CreateItemIndex_x                           0x6229A0
#define CharacterBase__GetItemPossession_x                         0x548C50
#define CharacterBase__GetItemByGlobalIndex_x                      0x97E370
#define CharacterBase__GetEffectId_x                               0x55C1F0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x78C6D0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x78CEF0

//messages
#define msg_spell_worn_off_x                                       0x61BA80
#define msg_new_text_x                                             0x6107D0
#define __msgTokenTextParam_x                                      0x61E140
#define msgTokenText_x                                             0x61E3B0

//SpellManager
#define SpellManager__vftable_x                                    0xAC12D8
#define SpellManager__SpellManager_x                               0x580D30
#define Spellmanager__LoadTextSpells_x                             0x70B4E0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0xA2E9E0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x591850
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x548800
#define ItemGlobalIndex__IsEquippedLocation_x                      0x55C4F0
#define ItemGlobalIndex__IsValidIndex_x                            0x55C620

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x976640
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x9768D0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x8015A0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7A9C10
#define CCursorAttachment__Deactivate_x                            0x7AABC0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9F66D0
#define CEQSuiteTextureLoader__GetTexture_x                        0x9F6360

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x58E370

//IString
#define IString__Append_x                                          0x581A60

//Camera
#define CDisplay__cameraType_x                                     0xE746D4
#define EverQuest__Cameras_x                                       0xF37244

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x596E10
#define pinstLootFiltersManager_x                                  0xD42AC8
#define LootFiltersManager__GetItemFilterData_x                    0x5966E0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x596710
#define LootFiltersManager__SetItemLootFilter_x                    0x596940

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x8600B0
