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
#define __ExpectedVersionDate                                     "Mar  6 2018"
#define __ExpectedVersionTime                                     "13:09:50"
#define __ActualVersionDate_x                                      0xADBC48
#define __ActualVersionTime_x                                      0xADBC3C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x6AA720
#define __MemChecker1_x                                            0x99D980
#define __MemChecker2_x                                            0x742FF0
#define __MemChecker3_x                                            0x742F30
#define __MemChecker4_x                                            0x8F7860
#define __EncryptPad0_x                                            0xC411A0
#define __EncryptPad1_x                                            0xD1B1B0
#define __EncryptPad2_x                                            0xC6ADA0
#define __EncryptPad3_x                                            0xC6A9A0
#define __EncryptPad4_x                                            0xD0BF20
#define __EncryptPad5_x                                            0xFBFD78
#define __AC1_x                                                    0x8B31E6
#define __AC2_x                                                    0x66436D
#define __AC3_x                                                    0x66B21D
#define __AC4_x                                                    0x66F12E
#define __AC5_x                                                    0x67536D
#define __AC6_x                                                    0x679840
#define __AC7_x                                                    0x663DDE
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0xd3ed8

// Direct Input
#define DI8__Main_x                                                0xFBFE24
#define DI8__Keyboard_x                                            0xFBFE28
#define DI8__Mouse_x                                               0xFBFF40
#define DI8__Mouse_Copy_x                                          0xF35BD4
#define DI8__Mouse_Check_x                                         0xFC0264
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
#define __do_loot_x                                                0x630B20
#define __DrawHandler_x                                            0x173AA18
#define __GroupCount_x                                             0xF25F02

#define __Guilds_x                                                 0xF2BE40
#define __gWorld_x                                                 0xF26740
#define __HotkeyPage_x                                             0xFB60FC
#define __HWnd_x                                                   0xFBFF44
#define __InChatMode_x                                             0xF35BBC
#define __LastTell_x                                               0xF37ADC
#define __LMouseHeldTime_x                                         0xF35CF8
#define __Mouse_x                                                  0xFBFD8C
#define __MouseLook_x                                              0xF35C52
#define __MouseEventTime_x                                         0xFBDCF0
#define __gpbCommandEvent_x                                        0xF260F4
#define __NetStatusToggle_x                                        0xF35C55
#define __PCNames_x                                                0xF370A0
#define __RangeAttackReady_x                                       0xF36DC8
#define __RMouseHeldTime_x                                         0xF35CF4
#define __RunWalkState_x                                           0xF35BC0
#define __ScreenMode_x                                             0xE74EB0
#define __ScreenX_x                                                0xF35B74
#define __ScreenY_x                                                0xF35B70
#define __ScreenXMax_x                                             0xF35B78
#define __ScreenYMax_x                                             0xF35B7C
#define __ServerHost_x                                             0xF2635B
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
#define pinstActiveBanker_x                                        0xF2875C
#define pinstActiveCorpse_x                                        0xF28754
#define pinstActiveGMaster_x                                       0xF28758
#define pinstActiveMerchant_x                                      0xF28750
#define pinstAggroInfo_x                                           0xD31CA8
#define pinstAltAdvManager_x                                       0xE75820
#define pinstAuraMgr_x                                             0xD42470
#define pinstBandageTarget_x                                       0xF2876C
#define pinstCamActor_x                                            0xE74EA4
#define pinstCDBStr_x                                              0xE74648
#define pinstCDisplay_x                                            0xF25EAC
#define pinstCEverQuest_x                                          0xFBFD84
#define pinstEverQuestInfo_x                                       0xF35B68
#define pinstCharData_x                                            0xF25ED8
#define pinstCharSpawn_x                                           0xF287A8
#define pinstControlledMissile_x                                   0xF25EB4
#define pinstControlledPlayer_x                                    0xF287A8
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
#define pinstGroup_x                                               0xF25EFE
#define pinstImeManager_x                                          0x1739C60
#define pinstLocalPlayer_x                                         0xF2674C
#define pinstMercenaryData_x                                       0xFBE340
#define pinstMercenaryStats_x                                      0x10D3210
#define pinstMercAltAbilities_x                                    0xE75C40
#define pinstModelPlayer_x                                         0xF28764
#define pinstPCData_x                                              0xF25ED8
#define pinstSkillMgr_x                                            0xFBF398
#define pinstSpawnManager_x                                        0xFBEBC0
#define pinstSpellManager_x                                        0xFBF4E8
#define pinstSpellSets_x                                           0xFB6160
#define pinstStringTable_x                                         0xF2663C
#define pinstSwitchManager_x                                       0xF25DB8
#define pinstTarget_x                                              0xF287A0
#define pinstTargetObject_x                                        0xF287A4
#define pinstTargetSwitch_x                                        0xF25EE0
#define pinstTaskMember_x                                          0xE74468
#define pinstTrackTarget_x                                         0xF287AC
#define pinstTradeTarget_x                                         0xF28760
#define instTributeActive_x                                        0xE745CD
#define pinstViewActor_x                                           0xE74EA0
#define pinstWorldData_x                                           0xF260F8
#define pinstZoneAddr_x                                            0xF360E8
#define pinstPlayerPath_x                                          0xFBEC28
#define pinstTargetIndicator_x                                     0xFBF690
#define pinstCTargetManager_x                                      0xFBF6F8
#define EQObject_Top_x                                             0xF26748
#define pinstRealEstateItems_x                                     0xFBF2F0
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE74EE4
#define pinstCAchievementsWnd_x                                    0xE74F48
#define pinstCActionsWnd_x                                         0xE74E34
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE74D78
#define pinstCAdvancedLootWnd_x                                    0xE746C8
#define pinstCAdventureLeaderboardWnd_x                            0x10CB990
#define pinstCAdventureRequestWnd_x                                0x10CBA10
#define pinstCAdventureStatsWnd_x                                  0x10CBA90
#define pinstCAggroMeterWnd_x                                      0xE74E20
#define pinstCAlarmWnd_x                                           0xE74E1C
#define pinstCAlertHistoryWnd_x                                    0xE74E14
#define pinstCAlertStackWnd_x                                      0xE74970
#define pinstCAlertWnd_x                                           0xE74D90
#define pinstCAltStorageWnd_x                                      0x10CBD00
#define pinstCAudioTriggersWindow_x                                0xD31FD0
#define pinstCAuraWnd_x                                            0xE74DF0
#define pinstCAvaZoneWnd_x                                         0xE74F14
#define pinstCBandolierWnd_x                                       0xE74E2C
#define pinstCBankWnd_x                                            0xE74968
#define pinstCBarterMerchantWnd_x                                  0x10CCA50
#define pinstCBarterSearchWnd_x                                    0x10CCAD0
#define pinstCBarterWnd_x                                          0x10CCB50
#define pinstCBazaarConfirmationWnd_x                              0xE74E9C
#define pinstCBazaarSearchWnd_x                                    0xE74DB0
#define pinstCBazaarWnd_x                                          0xE74E6C
#define pinstCBlockedBuffWnd_x                                     0xE74DDC
#define pinstCBlockedPetBuffWnd_x                                  0xE74E04
#define pinstCBodyTintWnd_x                                        0xE74964
#define pinstCBookWnd_x                                            0xE74E44
#define pinstCBreathWnd_x                                          0xE74EF0
#define pinstCBuffWindowNORMAL_x                                   0xE74DC0
#define pinstCBuffWindowSHORT_x                                    0xE74DC4
#define pinstCBugReportWnd_x                                       0xE74F20
#define pinstCCastingWnd_x                                         0xE74DD4
#define pinstCCastSpellWnd_x                                       0xE74E80
#define pinstCCharacterListWnd_x                                   0xE746D4
#define pinstCChatWindowManager_x                                  0x10CD370
#define pinstCClaimWnd_x                                           0x10CD468
#define pinstCColorPickerWnd_x                                     0xE74E98
#define pinstCCombatAbilityWnd_x                                   0xE74ED0
#define pinstCCombatSkillsSelectWnd_x                              0xE748DC
#define pinstCCompassWnd_x                                         0xE748FC
#define pinstCConfirmationDialog_x                                 0x10D17B0
#define pinstCContainerMgr_x                                       0xE74E84
#define pinstCContextMenuManager_x                                 0x1739C18
#define pinstCCursorAttachment_x                                   0xE74DCC
#define pinstCDynamicZoneWnd_x                                     0x10CD8B0
#define pinstCEditLabelWnd_x                                       0xE74DC8
#define pinstCEQMainWnd_x                                          0x10CDA78
#define pinstCEventCalendarWnd_x                                   0xE74DE0
#define pinstCFacePick_x                                           0xE7496C
#define pinstCFeedbackWnd_x                                        0xE74F00
#define pinstCFellowshipWnd_x                                      0x10CDC60
#define pinstCFileSelectionWnd_x                                   0xE74F18
#define pinstCFindItemWnd_x                                        0xE74F40
#define pinstCFindLocationWnd_x                                    0x10CDD58
#define pinstCFriendsWnd_x                                         0xE748E8
#define pinstCGemsGameWnd_x                                        0xE74DEC
#define pinstCGiveWnd_x                                            0xE74E7C
#define pinstCGroupSearchFiltersWnd_x                              0xE74E40
#define pinstCGroupSearchWnd_x                                     0x10CE030
#define pinstCGroupWnd_x                                           0x10CE0B0
#define pinstCGuildBankWnd_x                                       0x10CE130
#define pinstCGuildCreationWnd_x                                   0x10CE1B0
#define pinstCGuildMgmtWnd_x                                       0x10CE234
#define pinstCharacterCreation_x                                   0xE746CC
#define pinstCHelpWnd_x                                            0xE74DB4
#define pinstCHeritageSelectionWnd_x                               0xE74D8C
#define pinstCHotButtonWnd_x                                       0x10D0328
#define pinstCHotButtonWnd1_x                                      0x10D0328
#define pinstCHotButtonWnd2_x                                      0x10D032C
#define pinstCHotButtonWnd3_x                                      0x10D0330
#define pinstCHotButtonWnd4_x                                      0x10D035C
#define pinstCIconSelectionWnd_x                                   0xE74E28
#define pinstCInspectWnd_x                                         0xE74EE0
#define pinstCInventoryWnd_x                                       0xE74F24
#define pinstCInvSlotMgr_x                                         0xE74E3C
#define pinstCItemDisplayManager_x                                 0x10D07B8
#define pinstCItemExpTransferWnd_x                                 0x10D08BC
#define pinstCItemOverflowWnd_x                                    0xE74DBC
#define pinstCJournalCatWnd_x                                      0xE74F38
#define pinstCJournalTextWnd_x                                     0xE74EE8
#define pinstCKeyRingWnd_x                                         0xE748E0
#define pinstCLargeDialogWnd_x                                     0x10D20D0
#define pinstCLayoutCopyWnd_x                                      0x10D0B18
#define pinstCLFGuildWnd_x                                         0x10D0B98
#define pinstCLoadskinWnd_x                                        0xE74E0C
#define pinstCLootFiltersCopyWnd_x                                 0xD42A48
#define pinstCLootFiltersWnd_x                                     0xE74EF4
#define pinstCLootSettingsWnd_x                                    0xE74F10
#define pinstCLootWnd_x                                            0xE74DE8
#define pinstCMailAddressBookWnd_x                                 0xE74F04
#define pinstCMailCompositionWnd_x                                 0xE74EEC
#define pinstCMailIgnoreListWnd_x                                  0xE74F08
#define pinstCMailWnd_x                                            0xE74EC8
#define pinstCManageLootWnd_x                                      0xE75B48
#define pinstCMapToolbarWnd_x                                      0xE74DA8
#define pinstCMapViewWnd_x                                         0xE74D84
#define pinstCMarketplaceWnd_x                                     0xE74D94
#define pinstCMerchantWnd_x                                        0xE74DA0
#define pinstCMIZoneSelectWnd_x                                    0x10D1190
#define pinstCMusicPlayerWnd_x                                     0xE74E70
#define pinstCNameChangeMercWnd_x                                  0xE746C0
#define pinstCNameChangePetWnd_x                                   0xE74F34
#define pinstCNameChangeWnd_x                                      0xE748E4
#define pinstCNoteWnd_x                                            0xE74D98
#define pinstCObjectPreviewWnd_x                                   0xE74DAC
#define pinstCOptionsWnd_x                                         0xE74D80
#define pinstCPetInfoWnd_x                                         0xE74E88
#define pinstCPetitionQWnd_x                                       0xE74ECC
#define pinstCPlayerNotesWnd_x                                     0xE74D88
#define pinstCPlayerWnd_x                                          0xE74DD8
#define pinstCPopupWndManager_x                                    0x10D17B0
#define pinstCProgressionSelectionWnd_x                            0x10D1830
#define pinstCPurchaseGroupWnd_x                                   0xE74DF4
#define pinstCPurchaseWnd_x                                        0xE74DD0
#define pinstCPvPLeaderboardWnd_x                                  0x10D18B0
#define pinstCPvPStatsWnd_x                                        0x10D1930
#define pinstCQuantityWnd_x                                        0xE74DA4
#define pinstCRaceChangeWnd_x                                      0xE74D7C
#define pinstCRaidOptionsWnd_x                                     0xE74E38
#define pinstCRaidWnd_x                                            0xE74EDC
#define pinstCRealEstateItemsWnd_x                                 0xE74F3C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE74EC4
#define pinstCRealEstateManageWnd_x                                0xE74E18
#define pinstCRealEstateNeighborhoodWnd_x                          0xE74E30
#define pinstCRealEstatePlotSearchWnd_x                            0xE74E48
#define pinstCRealEstatePurchaseWnd_x                              0xE74E74
#define pinstCRespawnWnd_x                                         0xE74E10
#define pinstCSelectorWnd_x                                        0xE74E24
#define pinstCSendMoneyWnd_x                                       0xE74E8C
#define pinstCServerListWnd_x                                      0xE74DB8
#define pinstCSkillsSelectWnd_x                                    0xE746BC
#define pinstCSkillsWnd_x                                          0xE74F1C
#define pinstCSocialEditWnd_x                                      0xE74EFC
#define pinstCSocialWnd_x                                          0xE74E90
#define pinstCSpellBookWnd_x                                       0xE74ED8
#define pinstCStoryWnd_x                                           0xE748D8
#define pinstCTargetOfTargetWnd_x                                  0x10D3298
#define pinstCTargetWnd_x                                          0xE74DFC
#define pinstCTaskOverlayWnd_x                                     0xE746C4
#define pinstCTaskSelectWnd_x                                      0x10D3390
#define pinstCTaskSomething_x                                      0xD43010
#define pinstCTaskTemplateSelectWnd_x                              0x10D3410
#define pinstCTaskWnd_x                                            0x10D3490
#define pinstCTextEntryWnd_x                                       0xE74D9C
#define pinstCTextOverlay_x                                        0xD321E8
#define pinstCTimeLeftWnd_x                                        0xE74E94
#define pinstCTipWndCONTEXT_x                                      0x10D3604
#define pinstCTipWndOFDAY_x                                        0x10D3600
#define pinstCTitleWnd_x                                           0x10D3680
#define pinstCTrackingWnd_x                                        0xE74EC0
#define pinstCTradeskillWnd_x                                      0x10D3788
#define pinstCTradeWnd_x                                           0xE74DF8
#define pinstCTrainWnd_x                                           0xE74EBC
#define pinstCTributeBenefitWnd_x                                  0x10D38F8
#define pinstCTributeMasterWnd_x                                   0x10D3978
#define pinstCTributeTrophyWnd_x                                   0x10D39F8
#define pinstCVideoModesWnd_x                                      0xE74E78
#define pinstCVoiceMacroWnd_x                                      0xFBFAF8
#define pinstCVoteResultsWnd_x                                     0xE74F0C
#define pinstCVoteWnd_x                                            0xE74EF8
#define pinstCWebManager_x                                         0xFBFBFC
#define pinstCZoneGuideWnd_x                                       0xE74DE4
#define pinstCZonePathWnd_x                                        0xE74E00
#define pinstEQSuiteTextureLoader_x                                0xD1CA44
#define pinstItemIconCache_x                                       0x10CDA20
#define pinstRewardSelectionWnd_x                                  0x10D1E68

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC6A994
#define __CastRay_x                                                0x62BE90
#define __CastRay2_x                                               0x62BEE0
#define __ConvertItemTags_x                                        0x646E10
#define __CrashHandler_x                                           0x9014E0
#define __EQGetTime_x                                              0x99D2C0
#define __ExecuteCmd_x                                             0x624710
#define __FixHeading_x                                             0xA2CD00
#define __get_bearing_x                                            0x62B9D0
#define __get_melee_range_x                                        0x62C110
#define __GetAnimationCache_x                                      0x7AEAC0
#define __GetGaugeValueFromEQ_x                                    0x8B19E0
#define __GetLabelFromEQ_x                                         0x8B3170
#define __GetXTargetType_x                                         0xA2E770
#define __HeadingDiff_x                                            0xA2CD70
#define __HelpPath_x                                               0xFBDA4C
#define __LoadFrontEnd_x                                           0x73E910
#define __NewUIINI_x                                               0x8B16B0
#define __pCrashHandler_x                                          0x10E06A8
#define __ProcessGameEvents_x                                      0x68A430
#define __ProcessMouseEvent_x                                      0x689C00
#define __STMLToText_x                                             0x9D12D0
#define __ToggleKeyRingItem_x                                      0x594780
#define CrashDetected_x                                            0x7405A0
#define DrawNetStatus_x                                            0x6B9EF0
#define Expansion_HoT_x                                            0xF36F2C
#define Teleport_Table_Size_x                                      0xF26180
#define Teleport_Table_x                                           0xF26750
#define Util__FastTime_x                                           0x99CEB0
#define wwsCrashReportCheckForUploader_x                           0x9024D0
#define wwsCrashReportPlatformLaunchUploader_x                     0x904B20
#define __SaveColors_x                                             0x5D3660

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x51EEF0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x527EF0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x527CD0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5DBF80
#define AltAdvManager__IsAbilityReady_x                            0x5DAFF0
#define AltAdvManager__GetAAById_x                                 0x5DB1F0
#define AltAdvManager__CanTrainAbility_x                           0x5DB260
#define AltAdvManager__CanSeeAbility_x                             0x5DB490

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x55CE20
#define CharacterZoneClient__HasSkill_x                            0x5685B0
#define CharacterZoneClient__MakeMeVisible_x                       0x569CE0
#define CharacterZoneClient__IsStackBlocked_x                      0x5509C0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x54CF80
#define CharacterZoneClient__GetItemCountWorn_x                    0x56C470
#define CharacterZoneClient__GetItemCountInInventory_x             0x56C550
#define CharacterZoneClient__GetCursorItemCount_x                  0x56C630
#define CharacterZoneClient__FindAffectSlot_x                      0x5556F0
#define CharacterZoneClient__BardCastBard_x                        0x5586D0
#define CharacterZoneClient__GetMaxEffects_x                       0x54D050
#define CharacterZoneClient__GetEffect_x                           0x54CEC0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x556770
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x556840
#define CharacterZoneClient__GetLastEffectSlot_x                   0x556890

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x76D990

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x77BD20

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x6995F0
#define CButtonWnd__CButtonWnd_x                                   0x9CD660

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x79C070
#define CChatManager__InitContextMenu_x                            0x796420
#define CChatManager__FreeChatWindow_x                             0x79AF90
#define CChatManager__GetLockedActiveChatWindow_x                  0x79FC80
#define CChatManager__SetLockedActiveChatWindow_x                  0x79BE00

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9E1D00
#define CContextMenu__dCContextMenu_x                              0x9E1F30
#define CContextMenu__AddMenuItem_x                                0x9E1F40
#define CContextMenu__RemoveMenuItem_x                             0x9E2240
#define CContextMenu__RemoveAllMenuItems_x                         0x9E2260
#define CContextMenu__CheckMenuItem_x                              0x9E22E0
#define CContextMenu__SetMenuItem_x                                0x9E2160

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9E28A0
#define CContextMenuManager__RemoveMenu_x                          0x9E2910
#define CContextMenuManager__PopupMenu_x                           0x9E29D0
#define CContextMenuManager__Flush_x                               0x9E2840
#define CContextMenuManager__GetMenu_x                             0x529F00

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x980DC0
#define CChatService__GetFriendName_x                              0x980DD0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x79C600
#define CChatWindow__Clear_x                                       0x79D6E0
#define CChatWindow__WndNotification_x                             0x79DC40

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x9DF2A0
#define CComboWnd__Draw_x                                          0x9DE770
#define CComboWnd__GetCurChoice_x                                  0x9DF0E0
#define CComboWnd__GetListRect_x                                   0x9DEC30
#define CComboWnd__GetTextRect_x                                   0x9DF310
#define CComboWnd__InsertChoice_x                                  0x9DEDD0
#define CComboWnd__SetColors_x                                     0x9DEDA0
#define CComboWnd__SetChoice_x                                     0x9DF0B0
#define CComboWnd__GetItemCount_x                                  0x9DF0F0
#define CComboWnd__GetCurChoiceText_x                              0x9DF130

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7A6610
#define CContainerWnd__vftable_x                                   0xAE5760

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x5D3430
#define CDisplay__GetClickedActor_x                                0x5C5F50
#define CDisplay__GetUserDefinedColor_x                            0x5BE380
#define CDisplay__GetWorldFilePath_x                               0x5C79A0
#define CDisplay__is3dON_x                                         0x5C2BA0
#define CDisplay__ReloadUI_x                                       0x5CD000
#define CDisplay__WriteTextHD2_x                                   0x5C2970
#define CDisplay__TrueDistance_x                                   0x5C9600

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0xA014C0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9E57C0
#define CEditWnd__GetCharIndexPt_x                                 0x9E6760
#define CEditWnd__GetDisplayString_x                               0x9E65E0
#define CEditWnd__GetHorzOffset_x                                  0x9E4DA0
#define CEditWnd__GetLineForPrintableChar_x                        0x9E78C0
#define CEditWnd__GetSelStartPt_x                                  0x9E6A40
#define CEditWnd__GetSTMLSafeText_x                                0x9E63F0
#define CEditWnd__PointFromPrintableChar_x                         0x9E74E0
#define CEditWnd__SelectableCharFromPoint_x                        0x9E7650
#define CEditWnd__SetEditable_x                                    0x9E6B10

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x678D70
#define CEverQuest__ClickedPlayer_x                                0x66B000
#define CEverQuest__CreateTargetIndicator_x                        0x6876C0
#define CEverQuest__DeleteTargetIndicator_x                        0x687750
#define CEverQuest__DoTellWindow_x                                 0x5790A0
#define CEverQuest__OutputTextToLog_x                              0x579300
#define CEverQuest__DropHeldItemOnGround_x                         0x660AE0
#define CEverQuest__dsp_chat_x                                     0x5796F0
#define CEverQuest__trimName_x                                     0x683C60
#define CEverQuest__Emote_x                                        0x679570
#define CEverQuest__EnterZone_x                                    0x673720
#define CEverQuest__GetBodyTypeDesc_x                              0x67D3A0
#define CEverQuest__GetClassDesc_x                                 0x67D9A0
#define CEverQuest__GetClassThreeLetterCode_x                      0x67DFA0
#define CEverQuest__GetDeityDesc_x                                 0x686080
#define CEverQuest__GetLangDesc_x                                  0x67E160
#define CEverQuest__GetRaceDesc_x                                  0x67D980
#define CEverQuest__InterpretCmd_x                                 0x6866B0
#define CEverQuest__LeftClickedOnPlayer_x                          0x664A70
#define CEverQuest__LMouseUp_x                                     0x662D90
#define CEverQuest__RightClickedOnPlayer_x                         0x665380
#define CEverQuest__RMouseUp_x                                     0x663DA0
#define CEverQuest__SetGameState_x                                 0x660880
#define CEverQuest__UPCNotificationFlush_x                         0x683B60
#define CEverQuest__IssuePetCommand_x                              0x67F570
#define CEverQuest__ReportSuccessfulHit_x                          0x67A220

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7BA180
#define CGaugeWnd__CalcLinesFillRect_x                             0x7BA1E0
#define CGaugeWnd__Draw_x                                          0x7B97F0

// CGuild
#define CGuild__FindMemberByName_x                                 0x541890
#define CGuild__GetGuildName_x                                     0x5408E0
#define CGuild__GetGuildIndex_x                                    0x540C60

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7D6B30

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7E4890
#define CInvSlotMgr__MoveItem_x                                    0x7E33C0
#define CInvSlotMgr__SelectSlot_x                                  0x7E4960

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7E1A00
#define CInvSlot__SliderComplete_x                                 0x7DF4C0
#define CInvSlot__GetItemBase_x                                    0x7DEE80
#define CInvSlot__UpdateItem_x                                     0x7DEFF0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7E61A0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7E54C0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8AD530
#define CItemDisplayWnd__UpdateStrings_x                           0x7F51F0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7EEAD0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7EF020
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7F5760
#define CItemDisplayWnd__AboutToShow_x                             0x7F4E40
#define CItemDisplayWnd__WndNotification_x                         0x7F6C80

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8E8080

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7FB3B0

// CLabel 
#define CLabel__Draw_x                                             0x801780

// CListWnd
#define CListWnd__CListWnd_x                                       0x9B7950
#define CListWnd__dCListWnd_x                                      0x9B7C80
#define CListWnd__AddColumn_x                                      0x9BC190
#define CListWnd__AddColumn1_x                                     0x9BC1E0
#define CListWnd__AddLine_x                                        0x9BC5C0
#define CListWnd__AddString_x                                      0x9BC3B0
#define CListWnd__CalculateFirstVisibleLine_x                      0x9BBF40
#define CListWnd__CalculateVSBRange_x                              0x9BBD20
#define CListWnd__ClearSel_x                                       0x9BCD90
#define CListWnd__ClearAllSel_x                                    0x9BCDF0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x9BD820
#define CListWnd__Compare_x                                        0x9BB620
#define CListWnd__Draw_x                                           0x9B7D90
#define CListWnd__DrawColumnSeparators_x                           0x9BA5E0
#define CListWnd__DrawHeader_x                                     0x9BAA50
#define CListWnd__DrawItem_x                                       0x9BAEA0
#define CListWnd__DrawLine_x                                       0x9BA750
#define CListWnd__DrawSeparator_x                                  0x9BA680
#define CListWnd__EnableLine_x                                     0x9B9EB0
#define CListWnd__EnsureVisible_x                                  0x9BD740
#define CListWnd__ExtendSel_x                                      0x9BCCC0
#define CListWnd__GetColumnMinWidth_x                              0x9B9A00
#define CListWnd__GetColumnWidth_x                                 0x9B9970
#define CListWnd__GetCurSel_x                                      0x9B92D0
#define CListWnd__GetItemAtPoint_x                                 0x9BA130
#define CListWnd__GetItemAtPoint1_x                                0x9BA1A0
#define CListWnd__GetItemData_x                                    0x9B9350
#define CListWnd__GetItemHeight_x                                  0x9B9730
#define CListWnd__GetItemIcon_x                                    0x9B94F0
#define CListWnd__GetItemRect_x                                    0x9B9FA0
#define CListWnd__GetItemText_x                                    0x9B9390
#define CListWnd__GetSelList_x                                     0x9BCE40
#define CListWnd__GetSeparatorRect_x                               0x9BA3E0
#define CListWnd__InsertLine_x                                     0x9BC9A0
#define CListWnd__RemoveLine_x                                     0x9BCAF0
#define CListWnd__SetColors_x                                      0x9BBCF0
#define CListWnd__SetColumnJustification_x                         0x9BBA10
#define CListWnd__SetColumnWidth_x                                 0x9BB920
#define CListWnd__SetCurSel_x                                      0x9BCC00
#define CListWnd__SetItemColor_x                                   0x9BD3F0
#define CListWnd__SetItemData_x                                    0x9BD3B0
#define CListWnd__SetItemText_x                                    0x9BCFC0
#define CListWnd__ShiftColumnSeparator_x                           0x9BBAD0
#define CListWnd__Sort_x                                           0x9BB7C0
#define CListWnd__ToggleSel_x                                      0x9BCC30

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x818400

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x83CFF0
#define CMerchantWnd__RequestBuyItem_x                             0x83D930
#define CMerchantWnd__RequestSellItem_x                            0x83DEC0
#define CMerchantWnd__SelectRecoverySlot_x                         0x841060
//did this get another arg?
#define CMerchantWnd__SelectBuySellSlot_x                          0x83D6B0
#define CMerchantWnd__ActualSelect_x                               0x846D30

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x94D890
#define CPacketScrambler__hton_x                                   0x94D880

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x9D6E80
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9D6C70
#define CSidlManager__CreateLabel_x                                0x8A3C00
#define CSidlManager__CreateXWndFromTemplate_x                     0x9DA050
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9DA230

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9D3450
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9D3350
#define CSidlScreenWnd__ConvertToRes_x                             0x9F83F0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9D2E30
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9D2B10
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9D2BE0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9D2CB0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9D38F0
#define CSidlScreenWnd__EnableIniStorage_x                         0x9D3DC0
#define CSidlScreenWnd__GetSidlPiece_x                             0x9D3AE0
#define CSidlScreenWnd__Init1_x                                    0x9D2700
#define CSidlScreenWnd__LoadIniInfo_x                              0x9D3E10
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9D4960
#define CSidlScreenWnd__LoadSidlScreen_x                           0x9D1B00
#define CSidlScreenWnd__StoreIniInfo_x                             0x9D44E0
#define CSidlScreenWnd__StoreIniVis_x                              0x9D4840
#define CSidlScreenWnd__WndNotification_x                          0x9D3800
#define CSidlScreenWnd__GetChildItem_x                             0x9D3D40
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9C3370
#define CSidlScreenWnd__m_layoutCopy_x                             0x1739AA8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x7048D0
#define CSkillMgr__GetSkillCap_x                                   0x704AB0
#define CSkillMgr__GetNameToken_x                                  0x704050

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9F7AC0
#define CSliderWnd__SetValue_x                                     0x9F7930
#define CSliderWnd__SetNumTicks_x                                  0x9F7990

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x8AA310

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9E9800
#define CStmlWnd__CalculateHSBRange_x                              0x9EA950
#define CStmlWnd__CalculateVSBRange_x                              0x9EA8C0
#define CStmlWnd__CanBreakAtCharacter_x                            0x9EF850
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9F0400
#define CStmlWnd__ForceParseNow_x                                  0x9E9E00
#define CStmlWnd__GetNextTagPiece_x                                0x9EF7B0
#define CStmlWnd__GetSTMLText_x                                    0x587FC0
#define CStmlWnd__GetVisibleText_x                                 0x9E9E20
#define CStmlWnd__InitializeWindowVariables_x                      0x9F0250
#define CStmlWnd__MakeStmlColorTag_x                               0x9E8F20
#define CStmlWnd__MakeWndNotificationTag_x                         0x9E8F90
#define CStmlWnd__SetSTMLText_x                                    0x9E7FB0
#define CStmlWnd__StripFirstSTMLLines_x                            0x9F16D0
#define CStmlWnd__UpdateHistoryString_x                            0x9F0610

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9F4920
#define CTabWnd__DrawCurrentPage_x                                 0x9F4F70
#define CTabWnd__DrawTab_x                                         0x9F4D20
#define CTabWnd__GetCurrentPage_x                                  0x9F4180
#define CTabWnd__GetPageInnerRect_x                                0x9F43C0
#define CTabWnd__GetTabInnerRect_x                                 0x9F4300
#define CTabWnd__GetTabRect_x                                      0x9F41B0
#define CTabWnd__InsertPage_x                                      0x9F45B0
#define CTabWnd__SetPage_x                                         0x9F4440
#define CTabWnd__SetPageRect_x                                     0x9F4860
#define CTabWnd__UpdatePage_x                                      0x9F4BE0
#define CTabWnd__GetPageFromTabIndex_x                             0x9F4C60
#define CTabWnd__GetCurrentTabIndex_x                              0x9F4170

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7FB990
#define CPageWnd__SetTabText_x                                     0xA018B0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x53ACA0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x9C0200
#define CTextureFont__GetTextExtent_x                              0x9C03E0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x73AEE0
#define CHtmlComponentWnd__ValidateUri_x                           0x7D83F0
#define CHtmlWnd__SetClientCallbacks_x                             0x69E210
#define CHtmlWnd__AddObserver_x                                    0x69E230
#define CHtmlWnd__RemoveObserver_x                                 0x69E290
#define Window__getProgress_x                                      0x8FEEB0
#define Window__getStatus_x                                        0x8FEED0
#define Window__getURI_x                                           0x8FEEE0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9FDF10

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x9AD1B0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x506020
#define CXStr__CXStr1_x                                            0x548850
#define CXStr__CXStr3_x                                            0x999450
#define CXStr__dCXStr_x                                            0x9FC690
#define CXStr__operator_equal_x                                    0x999680
#define CXStr__operator_equal1_x                                   0x9996C0
#define CXStr__operator_plus_equal1_x                              0x99A150

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9E1930
#define CXWnd__BringToTop_x                                        0x9C6D10
#define CXWnd__Center_x                                            0x9C6890

#define CXWnd__ClrFocus_x                                          0x9C66C0
#define CXWnd__Destroy_x                                           0x9C6770
#define CXWnd__DoAllDrawing_x                                      0x9C2B00
#define CXWnd__DrawChildren_x                                      0x9C2AD0
#define CXWnd__DrawColoredRect_x                                   0x9C2F60
#define CXWnd__DrawTooltip_x                                       0x9C1610
#define CXWnd__DrawTooltipAtPoint_x                                0x9C16E0
#define CXWnd__GetBorderFrame_x                                    0x9C2DC0
#define CXWnd__GetChildWndAt_x                                     0x9C6DB0
#define CXWnd__GetClientClipRect_x                                 0x9C4F70
#define CXWnd__GetScreenClipRect_x                                 0x9C5040
#define CXWnd__GetScreenRect_x                                     0x9C5200
#define CXWnd__GetTooltipRect_x                                    0x9C2FB0
#define CXWnd__GetWindowTextA_x                                    0x52B8D0
#define CXWnd__IsActive_x                                          0x9C9BD0
#define CXWnd__IsDescendantOf_x                                    0x9C5C10
#define CXWnd__IsReallyVisible_x                                   0x9C5C40
#define CXWnd__IsType_x                                            0x9C7420
#define CScreenPieceTemplate__IsType_x                             0x9F93B0
#define CXWnd__Move_x                                              0x9C5CC0
#define CXWnd__Move1_x                                             0x9C5D70
#define CXWnd__ProcessTransition_x                                 0x9C6840
#define CXWnd__Refade_x                                            0x9C6040
#define CXWnd__Resize_x                                            0x9C62D0
#define CXWnd__Right_x                                             0x9C6AD0
#define CXWnd__SetFocus_x                                          0x9C6680
#define CXWnd__SetFont_x                                           0x9C66F0
#define CXWnd__SetKeyTooltip_x                                     0x9C7220
#define CXWnd__SetMouseOver_x                                      0x9C3F20
#define CXWnd__StartFade_x                                         0x9C5AF0
#define CXWnd__GetChildItem_x                                      0x9C6F20
#define CXWnd__SetParent_x                                         0x9C59B0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9C9C10
#define CXWndManager__DrawWindows_x                                0x9C9C30
#define CXWndManager__GetKeyboardFlags_x                           0x9CC410
#define CXWndManager__HandleKeyboardMsg_x                          0x9CC010
#define CXWndManager__RemoveWnd_x                                  0x9CC650
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9CCB70

// CDBStr
#define CDBStr__GetString_x                                        0x5BD0F0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x54DEF0
#define EQ_Character__Cur_HP_x                                     0x5654C0
#define EQ_Character__Cur_Mana_x                                   0x56CAA0
#define EQ_Character__GetAACastingTimeModifier_x                   0x550F90
#define EQ_Character__GetFocusCastingTimeModifier_x                0x5447B0
#define EQ_Character__GetFocusRangeModifier_x                      0x544920
#define EQ_Character__GetHPRegen_x                                 0x572370
#define EQ_Character__GetEnduranceRegen_x                          0x5729B0
#define EQ_Character__GetManaRegen_x                               0x572E00
#define EQ_Character__Max_Endurance_x                              0x6C7BD0
#define EQ_Character__Max_HP_x                                     0x5652F0
#define EQ_Character__Max_Mana_x                                   0x6C7A50
#define EQ_Character__doCombatAbility_x                            0x6C9F00
#define EQ_Character__UseSkill_x                                   0x574D30
#define EQ_Character__GetConLevel_x                                0x6C11A0
#define EQ_Character__IsExpansionFlag_x                            0x5BD010
#define EQ_Character__TotalEffect_x                                0x557C50
#define EQ_Character__GetPCSpellAffect_x                           0x551BB0
#define EQ_Character__SpellDuration_x                              0x5516C0
#define EQ_Character__FindItemByRecord_x                           0x56ACF0
#define EQ_Character__GetAdjustedSkill_x                           0x568370
#define EQ_Character__GetBaseSkill_x                               0x569310
#define EQ_Character__CanUseItem_x                                 0x56CDD0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x96C430

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6DE8B0

//PcClient
#define PcClient__PcClient_x                                       0x6BEAF0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x54B9D0
#define CCharacterListWnd__EnterWorld_x                            0x54B3F0
#define CCharacterListWnd__Quit_x                                  0x54B100
#define CCharacterListWnd__UpdateList_x                            0x54B590

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x69F560
#define EQ_Item__CreateItemTagString_x                             0x947A20
#define EQ_Item__IsStackable_x                                     0x94BC90
#define EQ_Item__GetImageNum_x                                     0x949290
#define EQ_Item__CreateItemClient_x                                0x69E860
#define EQ_Item__GetItemValue_x                                    0x94A320
#define EQ_Item__ValueSellMerchant_x                               0x94D480
#define EQ_Item__IsKeyRingItem_x                                   0x94B650
#define EQ_Item__CanGoInBag_x                                      0x69F680
#define EQ_Item__GetMaxItemCount_x                                 0x94A420
#define EQ_Item__GetHeldItem_x                                     0x9490A0
#define EQ_Item__GetAugmentFitBySlot_x                             0x947540

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5DCE80
#define EQ_LoadingS__Array_x                                       0xC0C4A0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6C8570
#define EQ_PC__GetAlternateAbilityId_x                             0x9564D0
#define EQ_PC__GetCombatAbility_x                                  0x956B50
#define EQ_PC__GetCombatAbilityTimer_x                             0x956BC0
#define EQ_PC__GetItemRecastTimer_x                                0x6CA490
#define EQ_PC__HasLoreItem_x                                       0x6C1970
#define EQ_PC__AlertInventoryChanged_x                             0x6C0C90
#define EQ_PC__GetPcZoneClient_x                                   0x6ED9E0
#define EQ_PC__RemoveMyAffect_x                                    0x6CD840
#define EQ_PC__GetKeyRingItems_x                                   0x957460
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x9571E0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x957750

// EQItemList 
#define EQItemList__EQItemList_x                                   0x629220
#define EQItemList__add_object_x                                   0x655AB0
#define EQItemList__add_item_x                                     0x629810
#define EQItemList__delete_item_x                                  0x629860
#define EQItemList__FreeItemList_x                                 0x629760

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5BA610

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6E0140
#define EQPlayer__dEQPlayer_x                                      0x6D32C0
#define EQPlayer__DoAttack_x                                       0x6E83D0
#define EQPlayer__EQPlayer_x                                       0x6D39C0
#define EQPlayer__SetNameSpriteState_x                             0x6D7FF0
#define EQPlayer__SetNameSpriteTint_x                              0x6D8E80
#define PlayerBase__HasProperty_j_x                                0xA2B030
#define EQPlayer__IsTargetable_x                                   0xA2B550
#define EQPlayer__CanSee_x                                         0xA2B370
#define PlayerZoneClient__ChangeHeight_x                           0x6EB470
#define EQPlayer__CanSee1_x                                        0xA2B460
#define PlayerBase__GetVisibilityLineSegment_x                     0xA2B0F0

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x6EDA20
#define PlayerZoneClient__IsValidTeleport_x                        0x656DD0
#define PlayerZoneClient__LegalPlayerRace_x                        0x5D5420


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6E2F80
#define EQPlayerManager__GetSpawnByName_x                          0x6E2FA0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6E3030

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6A3630
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6A3670
#define KeypressHandler__ClearCommandStateArray_x                  0x6A4A60
#define KeypressHandler__HandleKeyDown_x                           0x6A4A80
#define KeypressHandler__HandleKeyUp_x                             0x6A4B20
#define KeypressHandler__SaveKeymapping_x                          0x6A4FB0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x813F50
#define MapViewMap__SaveEx_x                                       0x817580
#define MapViewMap__SetZoom_x                                      0x81C3A0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x96A390

// StringTable 
#define StringTable__getString_x                                   0x965260

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6CD4A0
#define PcZoneClient__RemovePetEffect_x                            0x6CDAE0
#define PcZoneClient__HasAlternateAbility_x                        0x6C7860
#define PcZoneClient__GetCurrentMod_x                              0x577C20
#define PcZoneClient__GetModCap_x                                  0x577B20
#define PcZoneClient__CanEquipItem_x                               0x6C7E60
#define PcZoneClient__GetItemByID_x                                0x6CA9B0
#define PcZoneClient__GetItemByItemClass_x                         0x6CAA40
#define PcZoneClient__RemoveBuffEffect_x                           0x6CDB00

//Doors
#define EQSwitch__UseSwitch_x                                      0x65BB70

//IconCache
#define IconCache__GetIcon_x                                       0x7AE330

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x7A5590
#define CContainerMgr__CloseContainer_x                            0x7A5880

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x873D90

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x697BC0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5F7170
#define EQ_Spell__SpellAffects_x                                   0x5F7600
#define EQ_Spell__SpellAffectBase_x                                0x5F73A0
#define CharacterZoneClient__CalcAffectChange_x                    0x5569E0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x556BB0
#define CLootWnd__LootAll_x                                        0x8098D0
#define CLootWnd__RequestLootSlot_x                                0x808C10
#define EQ_Spell__IsStackable_x                                    0x55C4C0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x55C250
#define EQ_Spell__GetSpellAffectByIndex_x                          0x548E30
#define EQ_Spell__IsSPAStacking_x                                  0x5F81F0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5F7960
#define EQ_Spell__IsNoRemove_x                                     0x53A9F0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5F8200

#define __IsResEffectSpell_x                                       0x55B9F0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x53F230

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x976280

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8BD3B0
#define CTargetWnd__WndNotification_x                              0x8BCC30
#define CTargetWnd__RefreshTargetBuffs_x                           0x8BCF00
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8BBC80

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8C20E0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5F2140
#define EqSoundManager__PlayScriptMp3_x                            0x5F2250

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5AB560

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9E44A0
#define CSidlManager__FindAnimation1_x                             0x9D6A70

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5E57C0
#define CAltAbilityData__GetMercMaxRank_x                          0x5E5760
#define CAltAbilityData__GetMaxRank_x                              0x5D9D30

//CTargetRing
#define CTargetRing__Cast_x                                        0x695470

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x55C200
#define CharacterBase__CreateItemGlobalIndex_x                     0x5783A0
#define CharacterBase__CreateItemIndex_x                           0x622DD0
#define CharacterBase__GetItemPossession_x                         0x548C80
#define CharacterBase__GetItemByGlobalIndex_x                      0x97E8E0
#define CharacterBase__GetEffectId_x                               0x55C180

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x78CCF0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x78D510

//messages
#define msg_spell_worn_off_x                                       0x61C070
#define msg_new_text_x                                             0x610C80
#define __msgTokenTextParam_x                                      0x61E730
#define msgTokenText_x                                             0x61E9A0

//SpellManager
#define SpellManager__vftable_x                                    0xAC12D8
#define SpellManager__SpellManager_x                               0x580C40
#define Spellmanager__LoadTextSpells_x                             0x70BDE0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0xA2F0E0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5914F0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x548860
#define ItemGlobalIndex__IsEquippedLocation_x                      0x55C480
#define ItemGlobalIndex__IsValidIndex_x                            0x55C5C0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x976BA0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x976E30

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x801AF0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7AA230
#define CCursorAttachment__Deactivate_x                            0x7AB1F0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9F6FB0
#define CEQSuiteTextureLoader__GetTexture_x                        0x9F6C40

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x58DFB0

//IString
#define IString__Append_x                                          0x581950

//Camera
#define CDisplay__cameraType_x                                     0xE746D0
#define EverQuest__Cameras_x                                       0xF37244

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x596B00
#define pinstLootFiltersManager_x                                  0xD42AC8
#define LootFiltersManager__GetItemFilterData_x                    0x5963D0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x596400
#define LootFiltersManager__SetItemLootFilter_x                    0x596630

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x860510
