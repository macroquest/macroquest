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
#if defined(LIVE)
#include "eqgame-private(live).h"
#endif
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Oct 27 2017"
#define __ExpectedVersionTime                                     "04:18:56"
#define __ActualVersionDate_x                                      0xAED3B8
#define __ActualVersionTime_x                                      0xAED3C4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5AB5F0
#define __MemChecker1_x                                            0x8AAEC0
#define __MemChecker2_x                                            0x641AD0
#define __MemChecker3_x                                            0x641A20
#define __MemChecker4_x                                            0x7FC760
#define __EncryptPad0_x                                            0xC4B6A0
#define __EncryptPad1_x                                            0xD278E8
#define __EncryptPad2_x                                            0xC75268
#define __EncryptPad3_x                                            0xC74E68
#define __EncryptPad4_x                                            0xD15EE8
#define __EncryptPad5_x                                            0x10D1218
#define __AC1_x                                                    0x7BB895
#define __AC2_x                                                    0x564187
#define __AC3_x                                                    0x562300
#define __AC4_x                                                    0x574521
#define __AC5_x                                                    0x58830B
#define __AC6_x                                                    0x58BEAE
#define __AC7_x                                                    0x58290C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FA4BA0

// Direct Input
#define DI8__Main_x                                                0x10D11F0
#define DI8__Keyboard_x                                            0x10D11F4
#define DI8__Mouse_x                                               0x10D11F8
#define DI8__Mouse_Copy_x                                          0xF3F224
#define DI8__Mouse_Check_x                                         0xFC8EDC
#define __AutoSkillArray_x                                         0xF40138
#define __Attack_x                                                 0xFC3833
#define __Autofire_x                                               0xFC3834
#define __BindList_x                                               0xC26058
#define g_eqCommandStates_x                                        0xF2DF70
#define __Clicks_x                                                 0xF3F2E0
#define __CommandList_x                                            0xC28770
#define __CurrentMapLabel_x                                        0x10D71E8
#define __CurrentSocial_x                                          0xBF55D0
#define __DoAbilityList_x                                          0xF759F8
#define __do_loot_x                                                0x532FC0
#define __DrawHandler_x                                            0x1740F54
#define __GroupCount_x                                             0xF2F87A

#define __Guilds_x                                                 0xF35490
#define __gWorld_x                                                 0xF31D34
#define __HotkeyPage_x                                             0xFBC3F8
#define __HWnd_x                                                   0xFC8FF8
#define __InChatMode_x                                             0xF3F20C
#define __LastTell_x                                               0xF410F4
#define __LMouseHeldTime_x                                         0xF3F34C
#define __Mouse_x                                                  0x10D11FC
#define __MouseLook_x                                              0xF3F2A6
#define __MouseEventTime_x                                         0xFC40BC
#define __gpbCommandEvent_x                                        0xF31DFC
#define __NetStatusToggle_x                                        0xF3F2A9
#define __PCNames_x                                                0xF406FC
#define __RangeAttackReady_x                                       0xF4041C
#define __RMouseHeldTime_x                                         0xF3F348
#define __RunWalkState_x                                           0xF3F210
#define __ScreenMode_x                                             0xE7DB50
#define __ScreenX_x                                                0xF3F1C4
#define __ScreenY_x                                                0xF3F1C0
#define __ScreenXMax_x                                             0xF3F1C8
#define __ScreenYMax_x                                             0xF3F1CC
#define __ServerHost_x                                             0xF2F7C4
#define __ServerName_x                                             0xF759B8
#define __ShiftKeyDown_x                                           0xF3F8A0
#define __ShowNames_x                                              0xF405DC
#define __Socials_x                                                0xF75AB8
#define __SubscriptionType_x                                       0x1107A5C
#define __TargetAggroHolder_x                                      0x10D9434
#define __ZoneType_x                                               0xF3F6A4
#define __GroupAggro_x                                             0x10D9474
#define __LoginName_x                                              0xFC7AD4
#define __Inviter_x                                                0xFC37B0
#define __AttackOnAssist_x                                         0xF40598
#define __UseTellWindows_x                                         0xF40894

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF31E20
#define instEQZoneInfo_x                                           0xF3F49C
#define instKeypressHandler_x                                      0xFC40A0
#define pinstActiveBanker_x                                        0xF31DD8
#define pinstActiveCorpse_x                                        0xF31DDC
#define pinstActiveGMaster_x                                       0xF31DE0
#define pinstActiveMerchant_x                                      0xF31DD4
#define pinstAggroInfo_x                                           0xD3B1A8
#define pinstAltAdvManager_x                                       0xE7ECB8
#define pinstAuraMgr_x                                             0xD4B9C0
#define pinstBandageTarget_x                                       0xF31DC0
#define pinstCamActor_x                                            0xE7E588
#define pinstCDBStr_x                                              0xE7DAE4
#define pinstCDisplay_x                                            0xF31DE8
#define pinstCEverQuest_x                                          0x10D1370
#define pinstEverQuestInfo_x                                       0xF3F1B8
#define pinstCharData_x                                            0xF31DA4
#define pinstCharSpawn_x                                           0xF31DCC
#define pinstControlledMissile_x                                   0xF31DA0
#define pinstControlledPlayer_x                                    0xF31DCC
#define pinstCSidlManager_x                                        0x173FEC0
#define pinstCXWndManager_x                                        0x173FEB8
#define instDynamicZone_x                                          0xF3F058
#define pinstDZMember_x                                            0xF3F168
#define pinstDZTimerInfo_x                                         0xF3F16C
#define pinstEQItemList_x                                          0xF2E248
#define pinstEQObjectList_x                                        0xF2F274
#define instEQMisc_x                                               0xC0E498
#define pinstEQSoundManager_x                                      0xE7F288
#define instExpeditionLeader_x                                     0xF3F0A2
#define instExpeditionName_x                                       0xF3F0E2
#define pinstGroup_x                                               0xF2F876
#define pinstImeManager_x                                          0x173FEC4
#define pinstLocalPlayer_x                                         0xF31DB8
#define pinstMercenaryData_x                                       0xFC4720
#define pinstMercenaryStats_x                                      0x10D9580
#define pinstMercAltAbilities_x                                    0xE7F040
#define pinstModelPlayer_x                                         0xF31DE4
#define pinstPCData_x                                              0xF31DA4
#define pinstSkillMgr_x                                            0xFC5790
#define pinstSpawnManager_x                                        0xFC4F70
#define pinstSpellManager_x                                        0xFC58D8
#define pinstSpellSets_x                                           0xFBC45C
#define pinstStringTable_x                                         0xF31D4C
#define pinstSwitchManager_x                                       0xF2F408
#define pinstTarget_x                                              0xF31DD0
#define pinstTargetObject_x                                        0xF31DA8
#define pinstTargetSwitch_x                                        0xF31DAC
#define pinstTaskMember_x                                          0xE7DA30
#define pinstTrackTarget_x                                         0xF31DC4
#define pinstTradeTarget_x                                         0xF31DB4
#define instTributeActive_x                                        0xC0E4BD
#define pinstViewActor_x                                           0xE7E584
#define pinstWorldData_x                                           0xF31D88
#define pinstZoneAddr_x                                            0xF3F73C
#define pinstPlayerPath_x                                          0xFC4FD0
#define pinstTargetIndicator_x                                     0xFC5A70
#define pinstCTargetManager_x                                      0xFC5AD0
#define EQObject_Top_x                                             0xF31D98
#define pinstRealEstateItems_x                                     0xFC55FC
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE7E4A0
#define pinstCAchievementsWnd_x                                    0xE7E4FC
#define pinstCTextOverlay_x                                        0xD3B750
#define pinstCAudioTriggersWindow_x                                0xD3B538
#define pinstCCharacterSelect_x                                    0xE7E40C
#define pinstCFacePick_x                                           0xE7E1BC
#define pinstCFindItemWnd_x                                        0xE7E49C
#define pinstCNoteWnd_x                                            0xE7E3C4
#define pinstCBookWnd_x                                            0xE7E3CC
#define pinstCPetInfoWnd_x                                         0xE7E3D0
#define pinstCTrainWnd_x                                           0xE7E3D4
#define pinstCSkillsWnd_x                                          0xE7E3D8
#define pinstCSkillsSelectWnd_x                                    0xE7E3DC
#define pinstCCombatSkillsSelectWnd_x                              0xE7E3E0
#define pinstCFriendsWnd_x                                         0xE7E3E4
#define pinstCAuraWnd_x                                            0xE7E3E8
#define pinstCRespawnWnd_x                                         0xE7E3EC
#define pinstCBandolierWnd_x                                       0xE7E3F0
#define pinstCPotionBeltWnd_x                                      0xE7E3F4
#define pinstCAAWnd_x                                              0xE7E3F8
#define pinstCAlarmWnd_x                                           0xE7E404
#define pinstCGroupSearchFiltersWnd_x                              0xE7E3FC
#define pinstCLoadskinWnd_x                                        0xE7E400
#define pinstCLargeDialogWnd_x                                     0x10D84E0
#define pinstCMusicPlayerWnd_x                                     0xE7E408
#define pinstCMailWnd_x                                            0xE7E410
#define pinstCMailCompositionWnd_x                                 0xE7E414
#define pinstCMailAddressBookWnd_x                                 0xE7E418
#define pinstCRaidWnd_x                                            0xE7E420
#define pinstCRaidOptionsWnd_x                                     0xE7E424
#define pinstCBreathWnd_x                                          0xE7E428
#define pinstCMapViewWnd_x                                         0xE7E42C
#define pinstCMapToolbarWnd_x                                      0xE7E430
#define pinstCEditLabelWnd_x                                       0xE7E434
#define pinstCTargetWnd_x                                          0xE7E438
#define pinstCColorPickerWnd_x                                     0xE7E43C
#define pinstCPlayerWnd_x                                          0xE7E440
#define pinstCOptionsWnd_x                                         0xE7E444
#define pinstCBuffWindowNORMAL_x                                   0xE7E448
#define pinstCBuffWindowSHORT_x                                    0xE7E44C
#define pinstCharacterCreation_x                                   0xE7E450
#define pinstCCursorAttachment_x                                   0xE7E454
#define pinstCCastingWnd_x                                         0xE7E458
#define pinstCCastSpellWnd_x                                       0xE7E45C
#define pinstCSpellBookWnd_x                                       0xE7E460
#define pinstCInventoryWnd_x                                       0xE7E464
#define pinstCBankWnd_x                                            0xE7E46C
#define pinstCQuantityWnd_x                                        0xE7E470
#define pinstCLootWnd_x                                            0xE7E474
#define pinstCActionsWnd_x                                         0xE7E478
#define pinstCCombatAbilityWnd_x                                   0xE7E480
#define pinstCMerchantWnd_x                                        0xE7E484
#define pinstCTradeWnd_x                                           0xE7E48C
#define pinstCSelectorWnd_x                                        0xE7E490
#define pinstCBazaarWnd_x                                          0xE7E494
#define pinstCBazaarSearchWnd_x                                    0xE7E498
#define pinstCGiveWnd_x                                            0xE7E4B8
#define pinstCTrackingWnd_x                                        0xE7E4C0
#define pinstCInspectWnd_x                                         0xE7E4C4
#define pinstCSocialEditWnd_x                                      0xE7E4C8
#define pinstCFeedbackWnd_x                                        0xE7E4CC
#define pinstCBugReportWnd_x                                       0xE7E4D0
#define pinstCVideoModesWnd_x                                      0xE7E4D4
#define pinstCTextEntryWnd_x                                       0xE7E4DC
#define pinstCFileSelectionWnd_x                                   0xE7E4E0
#define pinstCCompassWnd_x                                         0xE7E4E4
#define pinstCPlayerNotesWnd_x                                     0xE7E4E8
#define pinstCGemsGameWnd_x                                        0xE7E4EC
#define pinstCTimeLeftWnd_x                                        0xE7E508
#define pinstCPetitionQWnd_x                                       0xE7E50C
#define pinstCStoryWnd_x                                           0xE7E510
#define pinstCJournalTextWnd_x                                     0xE7E514
#define pinstCJournalCatWnd_x                                      0xE7E518
#define pinstCBodyTintWnd_x                                        0xE7E51C
#define pinstCServerListWnd_x                                      0xE7E520
#define pinstCAvaZoneWnd_x                                         0xE7E52C
#define pinstCBlockedBuffWnd_x                                     0xE7E530
#define pinstCBlockedPetBuffWnd_x                                  0xE7E534
#define pinstCInvSlotMgr_x                                         0xE7E57C
#define pinstCContainerMgr_x                                       0xE7E580
#define pinstCAdventureLeaderboardWnd_x                            0x10D1D20
#define pinstCAdventureRequestWnd_x                                0x10D1D98
#define pinstCAltStorageWnd_x                                      0x10D2078
#define pinstCAdventureStatsWnd_x                                  0x10D1E10
#define pinstCBarterMerchantWnd_x                                  0x10D2DC0
#define pinstCBarterSearchWnd_x                                    0x10D2E38
#define pinstCBarterWnd_x                                          0x10D2EB0
#define pinstCChatWindowManager_x                                  0x10D36C0
#define pinstCDynamicZoneWnd_x                                     0x10D3BF0
#define pinstCEQMainWnd_x                                          0x10D3DB8
#define pinstCFellowshipWnd_x                                      0x10D3B84
#define pinstCFindLocationWnd_x                                    0x10D4088
#define pinstCGroupSearchWnd_x                                     0x10D4358
#define pinstCGroupWnd_x                                           0x10D43D0
#define pinstCGuildBankWnd_x                                       0x10D4448
#define pinstCGuildMgmtWnd_x                                       0x10D6538
#define pinstCHotButtonWnd_x                                       0x10D6634
#define pinstCHotButtonWnd1_x                                      0x10D6634
#define pinstCHotButtonWnd2_x                                      0x10D6638
#define pinstCHotButtonWnd3_x                                      0x10D663C
#define pinstCHotButtonWnd4_x                                      0x10D6660
#define pinstCItemDisplayManager_x                                 0x10D6AB8
#define pinstCItemExpTransferWnd_x                                 0x10D6BB4
#define pinstCLFGuildWnd_x                                         0x10D6E90
#define pinstCMIZoneSelectWnd_x                                    0x10D7470
#define pinstCConfirmationDialog_x                                 0x10D7B78
#define pinstCPopupWndManager_x                                    0x10D7B78
#define pinstCProgressionSelectionWnd_x                            0x10D7C68
#define pinstCPvPStatsWnd_x                                        0x10D7D58
#define pinstCTaskWnd_x                                            0x10D9860
#define pinstCTaskSomething_x                                      0xD4C5D8
#define pinstCTaskTemplateSelectWnd_x                              0x10D97E8
#define pinstCTipWndOFDAY_x                                        0x10D99C8
#define pinstCTipWndCONTEXT_x                                      0x10D99CC
#define pinstCTitleWnd_x                                           0x10D9A48
#define pinstCContextMenuManager_x                                 0x173FD48
#define pinstCVoiceMacroWnd_x                                      0xFC5EA8
#define pinstCHtmlWnd_x                                            0xFC5F98
#define pinstItemIconCache_x                                       0x10D3D60
#define pinstCTradeskillWnd_x                                      0x10D9B48
#define pinstCAdvancedLootWnd_x                                    0xE7E570
#define pinstRewardSelectionWnd_x                                  0x10D8280
#define pinstEQSuiteTextureLoader_x                                0xD297B0
#define pinstCPointMerchantWnd_x                                   0x10D7B00

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x54AAD0
#define __CastRay2_x                                               0x54A400
#define __HeadingDiff_x                                            0x93AEF0
#define __FixHeading_x                                             0x93AE80
#define __get_bearing_x                                            0x53A110
#define __ConvertItemTags_x                                        0x537BE0
#define __ExecuteCmd_x                                             0x522540
#define __EQGetTime_x                                              0x8AA860
#define __get_melee_range_x                                        0x5291E0
#define __GetGaugeValueFromEQ_x                                    0x7BA450
#define __GetLabelFromEQ_x                                         0x7BB820
#define __ToggleKeyRingItem_x                                      0x490C70
#define __GetXTargetType_x                                         0x93CAF0
#define __LoadFrontEnd_x                                           0x6411A0
#define __NewUIINI_x                                               0x7B9E30
#define __ProcessGameEvents_x                                      0x5846A0
#define __ProcessMouseEvent_x                                      0x583E40
#define CrashDetected_x                                            0x642B60
#define wwsCrashReportCheckForUploader_x                           0x808820
#define __AppCrashWrapper_x                                        0xC74E5C
#define __pCrashHandler_x                                          0x10E6A28
#define __CrashHandler_x                                           0x8082B0
#define wwsCrashReportPlatformLaunchUploader_x                     0x80AA50
#define DrawNetStatus_x                                            0x5BB240
#define Util__FastTime_x                                           0x8AA500
#define Expansion_HoT_x                                            0xF40588
#define __HelpPath_x                                               0xFC3E28
#define __STMLToText_x                                             0x8F0B30
#define __GetAnimationCache_x                                      0x6B0810

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423280
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DEE0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DCB0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D9180
#define AltAdvManager__IsAbilityReady_x                            0x4D91F0
#define AltAdvManager__GetAAById_x                                 0x4D96E0
#define AltAdvManager__CanTrainAbility_x                           0x4DA310
#define AltAdvManager__CanSeeAbility_x                             0x4D9ED0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46AAE0
#define CharacterZoneClient__HasSkill_x                            0x4663B0
#define CharacterZoneClient__MakeMeVisible_x                       0x46C650
#define CharacterZoneClient__IsStackBlocked_x                      0x44C060
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B540
#define CharacterZoneClient__GetItemCountWorn_x                    0x464910
#define CharacterZoneClient__GetItemCountInInventory_x             0x4649F0
#define CharacterZoneClient__GetCursorItemCount_x                  0x464AD0
#define CharacterZoneClient__FindAffectSlot_x                      0x4516A0
#define CharacterZoneClient__BardCastBard_x                        0x44ACB0
#define CharacterZoneClient__GetMaxEffects_x                       0x449840
#define CharacterZoneClient__GetEffect_x                           0x44B770
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451500
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449B90
#define CharacterZoneClient__GetLastEffectSlot_x                   0x450050

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x670A10

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67E680

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x599EE0
#define CButtonWnd__CButtonWnd_x                                   0x8E4DD0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x699A50
#define CChatManager__InitContextMenu_x                            0x69ABA0
#define CChatManager__FreeChatWindow_x                             0x699500
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A2CE0
#define CChatManager__SetLockedActiveChatWindow_x                  0x699A20

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8EEE80
#define CContextMenu__dCContextMenu_x                              0x8EF090
#define CContextMenu__AddMenuItem_x                                0x8EF5B0
#define CContextMenu__RemoveMenuItem_x                             0x8EF210
#define CContextMenu__RemoveAllMenuItems_x                         0x8EF230
#define CContextMenu__CheckMenuItem_x                              0x8EF2B0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8DB420
#define CContextMenuManager__RemoveMenu_x                          0x8DB7B0
#define CContextMenuManager__PopupMenu_x                           0x8DBC00
#define CContextMenuManager__Flush_x                               0x8DB490
#define CContextMenuManager__GetMenu_x                             0x419460

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x88EB00
#define CChatService__GetFriendName_x                              0x88EB10

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6A07D0
#define CChatWindow__Clear_x                                       0x6A00B0
#define CChatWindow__WndNotification_x                             0x6A10D0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8DF250
#define CComboWnd__Draw_x                                          0x8DF460
#define CComboWnd__GetCurChoice_x                                  0x8DF000
#define CComboWnd__GetListRect_x                                   0x8DF700
#define CComboWnd__GetTextRect_x                                   0x8DF2C0
#define CComboWnd__InsertChoice_x                                  0x8DF860
#define CComboWnd__SetColors_x                                     0x8DEF90
#define CComboWnd__SetChoice_x                                     0x8DEFC0
#define CComboWnd__GetItemCount_x                                  0x8DEFF0
#define CComboWnd__GetCurChoiceText_x                              0x8DF040


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6AA9D0
#define CContainerWnd__vftable_x                                   0xAF6CC8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C6E00
#define CDisplay__GetClickedActor_x                                0x4BF6C0
#define CDisplay__GetUserDefinedColor_x                            0x4BE2A0
#define CDisplay__GetWorldFilePath_x                               0x4BD6F0
#define CDisplay__is3dON_x                                         0x4BCB80
#define CDisplay__ReloadUI_x                                       0x4D0DE0
#define CDisplay__WriteTextHD2_x                                   0x4C3190
#define CDisplay__TrueDistance_x                                   0x4C02F0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x906260

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8F33E0
#define CEditWnd__GetCharIndexPt_x                                 0x8F4530
#define CEditWnd__GetDisplayString_x                               0x8F3590
#define CEditWnd__GetHorzOffset_x                                  0x8F38D0
#define CEditWnd__GetLineForPrintableChar_x                        0x8F4000
#define CEditWnd__GetSelStartPt_x                                  0x8F47E0
#define CEditWnd__GetSTMLSafeText_x                                0x8F3A70
#define CEditWnd__PointFromPrintableChar_x                         0x8F40F0
#define CEditWnd__SelectableCharFromPoint_x                        0x8F4270
#define CEditWnd__SetEditable_x                                    0x8F3A40

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56AD50
#define CEverQuest__ClickedPlayer_x                                0x5648D0
#define CEverQuest__CreateTargetIndicator_x                        0x5657D0
#define CEverQuest__DeleteTargetIndicator_x                        0x565850
#define CEverQuest__DoTellWindow_x                                 0x477270
#define CEverQuest__OutputTextToLog_x                              0x476ED0
#define CEverQuest__DropHeldItemOnGround_x                         0x57B2C0
#define CEverQuest__dsp_chat_x                                     0x4775B0
#define CEverQuest__trimName_x                                     0x5611E0
#define CEverQuest__Emote_x                                        0x5795D0
#define CEverQuest__EnterZone_x                                    0x5746B0
#define CEverQuest__GetBodyTypeDesc_x                              0x55EC20
#define CEverQuest__GetClassDesc_x                                 0x568170
#define CEverQuest__GetClassThreeLetterCode_x                      0x568770
#define CEverQuest__GetDeityDesc_x                                 0x55F500
#define CEverQuest__GetLangDesc_x                                  0x55EFB0
#define CEverQuest__GetRaceDesc_x                                  0x568930
#define CEverQuest__InterpretCmd_x                                 0x56C4D0
#define CEverQuest__LeftClickedOnPlayer_x                          0x580E20
#define CEverQuest__LMouseUp_x                                     0x582E60
#define CEverQuest__RightClickedOnPlayer_x                         0x581930
#define CEverQuest__RMouseUp_x                                     0x5828C0
#define CEverQuest__SetGameState_x                                 0x5651A0
#define CEverQuest__UPCNotificationFlush_x                         0x55D5B0
#define CEverQuest__IssuePetCommand_x                              0x56CEB0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BB5E0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BB640
#define CGaugeWnd__Draw_x                                          0x6BBA70

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B580
#define CGuild__GetGuildName_x                                     0x43BA50
#define CGuild__GetGuildIndex_x                                    0x43CC60

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D7AD0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E4EF0
#define CInvSlotMgr__MoveItem_x                                    0x6E56B0
#define CInvSlotMgr__SelectSlot_x                                  0x6E47F0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E3C50
#define CInvSlot__SliderComplete_x                                 0x6E13E0
#define CInvSlot__GetItemBase_x                                    0x6E0870
#define CInvSlot__UpdateItem_x                                     0x6E0DF0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E6B10
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E7C50

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7B6310
#define CItemDisplayWnd__UpdateStrings_x                           0x6E8D60
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F59E0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F5F10
#define CItemDisplayWnd__SetItem_x                                 0x6FB8A0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7ED4B0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EF370

// CLabel 
#define CLabel__Draw_x                                             0x7026C0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8CAF90
#define CListWnd__dCListWnd_x                                      0x8CC250
#define CListWnd__AddColumn_x                                      0x8CC1F0
#define CListWnd__AddColumn1_x                                     0x8CB880
#define CListWnd__AddLine_x                                        0x8CB260
#define CListWnd__AddString_x                                      0x8CB480
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C8080
#define CListWnd__CalculateVSBRange_x                              0x8CA450
#define CListWnd__ClearSel_x                                       0x8C7390
#define CListWnd__ClearAllSel_x                                    0x8C7340
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8CAE20
#define CListWnd__Compare_x                                        0x8C8D80
#define CListWnd__Draw_x                                           0x8CA050
#define CListWnd__DrawColumnSeparators_x                           0x8C9EE0
#define CListWnd__DrawHeader_x                                     0x8C7650
#define CListWnd__DrawItem_x                                       0x8C9410
#define CListWnd__DrawLine_x                                       0x8C9B80
#define CListWnd__DrawSeparator_x                                  0x8C9F80
#define CListWnd__EnableLine_x                                     0x8C7570
#define CListWnd__EnsureVisible_x                                  0x8C81E0
#define CListWnd__ExtendSel_x                                      0x8C9320
#define CListWnd__GetColumnMinWidth_x                              0x8C6C80
#define CListWnd__GetColumnWidth_x                                 0x8C6BB0
#define CListWnd__GetCurSel_x                                      0x8C6390
#define CListWnd__GetItemAtPoint_x                                 0x8C8480
#define CListWnd__GetItemAtPoint1_x                                0x8C84F0
#define CListWnd__GetItemData_x                                    0x8C66D0
#define CListWnd__GetItemHeight_x                                  0x8C7CD0
#define CListWnd__GetItemIcon_x                                    0x8C68C0
#define CListWnd__GetItemRect_x                                    0x8C82C0
#define CListWnd__GetItemText_x                                    0x8C6770
#define CListWnd__GetSelList_x                                     0x8CB770
#define CListWnd__GetSeparatorRect_x                               0x8C8CA0
#define CListWnd__InsertLine_x                                     0x8CB660
#define CListWnd__RemoveLine_x                                     0x8CB670
#define CListWnd__SetColors_x                                      0x8C64E0
#define CListWnd__SetColumnJustification_x                         0x8C6F10
#define CListWnd__SetColumnWidth_x                                 0x8C6C30
#define CListWnd__SetCurSel_x                                      0x8C63D0
#define CListWnd__SetItemColor_x                                   0x8CAB10
#define CListWnd__SetItemData_x                                    0x8C73F0
#define CListWnd__SetItemText_x                                    0x8CA950
#define CListWnd__ShiftColumnSeparator_x                           0x8CA7E0
#define CListWnd__Sort_x                                           0x8CC350
#define CListWnd__ToggleSel_x                                      0x8C72C0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71B730

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73ECF0
#define CMerchantWnd__RequestBuyItem_x                             0x747D00
#define CMerchantWnd__RequestSellItem_x                            0x74A400
#define CMerchantWnd__SelectRecoverySlot_x                         0x73F2A0
#define CMerchantWnd__SelectBuySellSlot_x                          0x73C280
#define CMerchantWnd__ActualSelect_x                               0x7400B0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x85CDC0
#define CPacketScrambler__hton_x                                   0x85CDD0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E9D70
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E9E50
#define CSidlManager__CreateLabel_x                                0x7AB1F0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E8310
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8EA130

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8E12A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8E11A0
#define CSidlScreenWnd__ConvertToRes_x                             0x906140
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8E1BB0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8E2D60
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8E2E10
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8E22E0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8E1560
#define CSidlScreenWnd__EnableIniStorage_x                         0x8E0CD0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8E1750
#define CSidlScreenWnd__Init1_x                                    0x8E2A30
#define CSidlScreenWnd__LoadIniInfo_x                              0x8E1C60
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8E0E90
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8E2520
#define CSidlScreenWnd__StoreIniInfo_x                             0x8E0930
#define CSidlScreenWnd__StoreIniVis_x                              0x8E0C80
#define CSidlScreenWnd__WndNotification_x                          0x8E27B0
#define CSidlScreenWnd__GetChildItem_x                             0x8E0DA0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8D4750
#define CSidlScreenWnd__m_layoutCopy_x                             0x173FE68

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6069F0
#define CSkillMgr__GetSkillCap_x                                   0x606BD0
#define CSkillMgr__GetNameToken_x                                  0x6065A0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x905400
#define CSliderWnd__SetValue_x                                     0x9055D0
#define CSliderWnd__SetNumTicks_x                                  0x905D50

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7B1560

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8FEE70
#define CStmlWnd__CalculateHSBRange_x                              0x8F73B0
#define CStmlWnd__CalculateVSBRange_x                              0x8F7320
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F7530
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F7D30
#define CStmlWnd__ForceParseNow_x                                  0x8FF7F0
#define CStmlWnd__GetNextTagPiece_x                                0x8F7C30
#define CStmlWnd__GetSTMLText_x                                    0x4854A0
#define CStmlWnd__GetVisibleText_x                                 0x8F8780
#define CStmlWnd__InitializeWindowVariables_x                      0x8FAD50
#define CStmlWnd__MakeStmlColorTag_x                               0x8F6600
#define CStmlWnd__MakeWndNotificationTag_x                         0x8F6660
#define CStmlWnd__SetSTMLText_x                                    0x8FC5B0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8FEB10
#define CStmlWnd__UpdateHistoryString_x                            0x8F96C0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x902D70
#define CTabWnd__DrawCurrentPage_x                                 0x902600
#define CTabWnd__DrawTab_x                                         0x9023C0
#define CTabWnd__GetCurrentPage_x                                  0x9029B0
#define CTabWnd__GetPageInnerRect_x                                0x9020B0
#define CTabWnd__GetTabInnerRect_x                                 0x9022B0
#define CTabWnd__GetTabRect_x                                      0x902180
#define CTabWnd__InsertPage_x                                      0x903060
#define CTabWnd__SetPage_x                                         0x9029E0
#define CTabWnd__SetPageRect_x                                     0x902CB0
#define CTabWnd__UpdatePage_x                                      0x903000
#define CTabWnd__GetPageFromTabIndex_x                             0x902310
#define CTabWnd__GetCurrentTabIndex_x                              0x902040

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E7E00
#define CPageWnd__SetTabText_x                                     0x90F460

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x437180

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8DEC00
#define CTextureFont__GetTextExtent_x                              0x8DE960

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63F440

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x90B8A0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8C4580

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029E0
#define CXStr__CXStr1_x                                            0x7F56D0
#define CXStr__CXStr3_x                                            0x8A7790
#define CXStr__dCXStr_x                                            0x6BB4C0
#define CXStr__operator_equal_x                                    0x8A7900
#define CXStr__operator_equal1_x                                   0x8A7950
#define CXStr__operator_plus_equal1_x                              0x8A8A50

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8DC710
#define CXWnd__BringToTop_x                                        0x8D3980
#define CXWnd__Center_x                                            0x8D9A30
#define CXWnd__ClrFocus_x                                          0x8D3560
#define CXWnd__Destroy_x                                           0x8DA510
#define CXWnd__DoAllDrawing_x                                      0x8D9680
#define CXWnd__DrawChildren_x                                      0x8D9820
#define CXWnd__DrawColoredRect_x                                   0x8D3D40
#define CXWnd__DrawTooltip_x                                       0x8D3FF0
#define CXWnd__DrawTooltipAtPoint_x                                0x8D8620
#define CXWnd__GetBorderFrame_x                                    0x8D4450
#define CXWnd__GetChildWndAt_x                                     0x8DA400
#define CXWnd__GetClientClipRect_x                                 0x8D4210
#define CXWnd__GetScreenClipRect_x                                 0x8D8D20
#define CXWnd__GetScreenRect_x                                     0x8D45F0
#define CXWnd__GetTooltipRect_x                                    0x8D3E80
#define CXWnd__GetWindowTextA_x                                    0x4272F0
#define CXWnd__IsActive_x                                          0x8CF070
#define CXWnd__IsDescendantOf_x                                    0x8D43A0
#define CXWnd__IsReallyVisible_x                                   0x8D7670
#define CXWnd__IsType_x                                            0x8D9AA0
#define CScreenPieceTemplate__IsType_x                             0x907FF0
#define CXWnd__Move_x                                              0x8D6DF0
#define CXWnd__Move1_x                                             0x8D9350
#define CXWnd__ProcessTransition_x                                 0x8D3920
#define CXWnd__Refade_x                                            0x8D36F0
#define CXWnd__Resize_x                                            0x8D46B0
#define CXWnd__Right_x                                             0x8D8B20
#define CXWnd__SetFocus_x                                          0x8D5F70
#define CXWnd__SetFont_x                                           0x8D35B0
#define CXWnd__SetKeyTooltip_x                                     0x8D4920
#define CXWnd__SetMouseOver_x                                      0x8D9060
#define CXWnd__StartFade_x                                         0x8D39D0
#define CXWnd__GetChildItem_x                                      0x8D8FA0
#define CXWnd__SetParent_x                                         0x8DA3B0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8D0910
#define CXWndManager__DrawWindows_x                                0x8D0560
#define CXWndManager__GetKeyboardFlags_x                           0x8CEBE0
#define CXWndManager__HandleKeyboardMsg_x                          0x8CF510
#define CXWndManager__RemoveWnd_x                                  0x8CF200

// CDBStr
#define CDBStr__GetString_x                                        0x4BB3E0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452860
#define EQ_Character__Cur_HP_x                                     0x465F90
#define EQ_Character__Cur_Mana_x                                   0x45AEE0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B850
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443890
#define EQ_Character__GetFocusRangeModifier_x                      0x4438F0
#define EQ_Character__GetHPRegen_x                                 0x46A170
#define EQ_Character__GetEnduranceRegen_x                          0x4655A0
#define EQ_Character__GetManaRegen_x                               0x46A710
#define EQ_Character__Max_Endurance_x                              0x5CCFE0
#define EQ_Character__Max_HP_x                                     0x45DA60
#define EQ_Character__Max_Mana_x                                   0x5CCE10
#define EQ_Character__doCombatAbility_x                            0x5CA4E0
#define EQ_Character__UseSkill_x                                   0x4716E0
#define EQ_Character__GetConLevel_x                                0x5BF890
#define EQ_Character__IsExpansionFlag_x                            0x426820
#define EQ_Character__TotalEffect_x                                0x44F990
#define EQ_Character__GetPCSpellAffect_x                           0x44BC30
#define EQ_Character__SpellDuration_x                              0x449BE0
#define EQ_Character__FindItemByRecord_x                           0x463600
#define EQ_Character__GetAdjustedSkill_x                           0x466160
#define EQ_Character__GetBaseSkill_x                               0x45D940

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x87AD00

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D5600

//PcClient
#define PcClient__PcClient_x                                       0x5C16D0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446CB0
#define CCharacterSelect__EnterWorld_x                             0x446480
#define CCharacterSelect__Quit_x                                   0x445040

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59F810
#define EQ_Item__CreateItemTagString_x                             0x85AF50
#define EQ_Item__IsStackable_x                                     0x850420
#define EQ_Item__GetImageNum_x                                     0x852EF0
#define EQ_Item__CreateItemClient_x                                0x5A08D0
#define EQ_Item__GetItemValue_x                                    0x8599C0
#define EQ_Item__ValueSellMerchant_x                               0x85CA10
#define EQ_Item__IsKeyRingItem_x                                   0x850EE0
#define EQ_Item__CanGoInBag_x                                      0x59F9A0
#define EQ_Item__GetMaxItemCount_x                                 0x850310
#define EQ_Item__GetHeldItem_x                                     0x851D00
#define EQ_Item__GetAugmentFitBySlot_x                             0x85C830

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DB720
#define EQ_LoadingS__Array_x                                       0xC16958

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CF4F0
#define EQ_PC__GetAlternateAbilityId_x                             0x864F10
#define EQ_PC__GetCombatAbility_x                                  0x864FA0
#define EQ_PC__GetCombatAbilityTimer_x                             0x85FA70
#define EQ_PC__GetItemRecastTimer_x                                0x5C8C90
#define EQ_PC__HasLoreItem_x                                       0x5C2E90
#define EQ_PC__AlertInventoryChanged_x                             0x5BF840
#define EQ_PC__GetPcZoneClient_x                                   0x5E9B20
#define EQ_PC__RemoveMyAffect_x                                    0x5C80F0
#define EQ_PC__GetKeyRingItems_x                                   0x85FE90
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x872BF0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x866E80

// EQItemList 
#define EQItemList__EQItemList_x                                   0x527260
#define EQItemList__add_object_x                                   0x554560
#define EQItemList__add_item_x                                     0x5271A0
#define EQItemList__delete_item_x                                  0x527650
#define EQItemList__FreeItemList_x                                 0x527550

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4BA6F0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D53A0
#define EQPlayer__dEQPlayer_x                                      0x5DD9D0
#define EQPlayer__DoAttack_x                                       0x5EF490
#define EQPlayer__EQPlayer_x                                       0x5E0100
#define EQPlayer__SetNameSpriteState_x                             0x5DA8B0
#define EQPlayer__SetNameSpriteTint_x                              0x5D67C0
#define PlayerBase__HasProperty_j_x                                0x9392A0
#define EQPlayer__IsTargetable_x                                   0x939540
#define EQPlayer__CanSee_x                                         0x939AA0
#define PlayerZoneClient__ChangeHeight_x                           0x5EF350
#define EQPlayer__CanSee1_x                                        0x939B90
#define PlayerBase__GetVisibilityLineSegment_x                     0x939830

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E9CD0
#define PlayerZoneClient__IsValidTeleport_x                        0x554E00
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D39E0


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E4160
#define EQPlayerManager__GetSpawnByName_x                          0x5E45C0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E4190

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A5E30
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A5E70
#define KeypressHandler__ClearCommandStateArray_x                  0x5A5A20
#define KeypressHandler__HandleKeyDown_x                           0x5A4340
#define KeypressHandler__HandleKeyUp_x                             0x5A4660
#define KeypressHandler__SaveKeymapping_x                          0x5A5AF0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7140C0
#define MapViewMap__SaveEx_x                                       0x7173F0

#define PlayerPointManager__GetAltCurrency_x                       0x878DB0

// StringTable 
#define StringTable__getString_x                                   0x872F20

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CCA70
#define PcZoneClient__RemovePetEffect_x                            0x5C9160
#define PcZoneClient__HasAlternateAbility_x                        0x5C9B00
#define PcZoneClient__GetCurrentMod_x                              0x45CF10
#define PcZoneClient__GetModCap_x                                  0x45A640
#define PcZoneClient__CanEquipItem_x                               0x5CA020
#define PcZoneClient__GetItemByID_x                                0x5CE870
#define PcZoneClient__GetItemByItemClass_x                         0x5CF410
#define PcZoneClient__RemoveBuffEffect_x                           0x5C83A0

//Doors
#define EQSwitch__UseSwitch_x                                      0x55BE50

//IconCache
#define IconCache__GetIcon_x                                       0x6B0E40

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A7D70
#define CContainerMgr__CloseContainer_x                            0x6A8590

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x77B180

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x598900

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F5C80
#define EQ_Spell__SpellAffects_x                                   0x4F2EA0
#define EQ_Spell__SpellAffectBase_x                           0x4F2F10
#define CharacterZoneClient__CalcAffectChange_x                    0x44BAC0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AD10
#define CLootWnd__LootAll_x                                        0x709A70
#define CLootWnd__RequestLootSlot_x                                0x70A280
#define EQ_Spell__IsStackable_x                                    0x4495D0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449680
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43F080
#define EQ_Spell__IsSPAStacking_x                                  0x4F2A10
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F3A80
#define EQ_Spell__IsNoRemove_x                                     0x4351C0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F2A30

#define __IsResEffectSpell_x                                       0x449730

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x884990

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7C2F20
#define CTargetWnd__WndNotification_x                              0x7C2A10
#define CTargetWnd__RefreshTargetBuffs_x                           0x7C3100

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C8040

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4EE590
#define EqSoundManager__PlayScriptMp3_x                            0x4F0030

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A9840

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8F2A10
#define CSidlManager__FindAnimation1_x                             0x8E7D40

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E2FF0
#define CAltAbilityData__GetMercMaxRank_x                          0x4E2FA0
#define CAltAbilityData__GetMaxRank_x                              0x4D7830

//CTargetRing
#define CTargetRing__Cast_x                                        0x5961D0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459620
#define CharacterBase__CreateItemGlobalIndex_x                     0x476470
#define CharacterBase__CreateItemIndex_x                           0x520880
#define CharacterBase__GetItemPossession_x                         0x444540
#define CharacterBase__GetItemByGlobalIndex_x                      0x8887E0
#define CharacterBase__GetEffectId_x                               0x4595E0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x690B60
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6902C0

//messages
#define msg_spell_worn_off_x                                       0x4FD740
#define msg_new_text_x                                             0x506EA0
#define msgTokenTextParam_x                                        0x503680

//SpellManager
#define SpellManager__vftable_x                                    0xAD2410
#define SpellManager__SpellManager_x                               0x47F150
#define Spellmanager__LoadTextSpells_x          0x60D8F0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x93D610

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x488C30
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EFA0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449380
#define ItemGlobalIndex__IsValidIndex_x                            0x458EF0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x886650
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x885590

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x702920

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6ACA90
#define CCursorAttachment__Deactivate_x                            0x6ABFE0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x904900
#define CEQSuiteTextureLoader__GetTexture_x                        0x904A80

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                                0x605530

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                                0x48D4C0

//IString
#define IString__Append_x                                           0x47FD80
