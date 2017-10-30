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
#define __ExpectedVersionDate                                     "Oct 30 2017"
#define __ExpectedVersionTime                                     "04:16:35"
#define __ActualVersionDate_x                                      0xAED378
#define __ActualVersionTime_x                                      0xAED384

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5AB380
#define __MemChecker1_x                                            0x8AA6D0
#define __MemChecker2_x                                            0x641620
#define __MemChecker3_x                                            0x641570
#define __MemChecker4_x                                            0x7FC7F0
#define __EncryptPad0_x                                            0xC4B6A0
#define __EncryptPad1_x                                            0xD278E8
#define __EncryptPad2_x                                            0xC75268
#define __EncryptPad3_x                                            0xC74E68
#define __EncryptPad4_x                                            0xD15EE8
#define __EncryptPad5_x                                            0x10D1218
#define __AC1_x                                                    0x7BB2E5
#define __AC2_x                                                    0x563CB7
#define __AC3_x                                                    0x561E30
#define __AC4_x                                                    0x574051
#define __AC5_x                                                    0x587E3B
#define __AC6_x                                                    0x58B9EE
#define __AC7_x                                                    0x58243C
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
#define __do_loot_x                                                0x532A60
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
#define __CastRay_x                                                0x54A570
#define __CastRay2_x                                               0x549EA0
#define __HeadingDiff_x                                            0x93A790
#define __FixHeading_x                                             0x93A720
#define __get_bearing_x                                            0x539BB0
#define __ConvertItemTags_x                                        0x537680
#define __ExecuteCmd_x                                             0x521FB0
#define __EQGetTime_x                                              0x8AA070
#define __get_melee_range_x                                        0x528C60
#define __GetGaugeValueFromEQ_x                                    0x7B9EA0
#define __GetLabelFromEQ_x                                         0x7BB270
#define __ToggleKeyRingItem_x                                      0x4903D0
#define __GetXTargetType_x                                         0x93C390
#define __LoadFrontEnd_x                                           0x640CF0
#define __NewUIINI_x                                               0x7B9870
#define __ProcessGameEvents_x                                      0x5841D0
#define __ProcessMouseEvent_x                                      0x583970
#define CrashDetected_x                                            0x6426B0
#define wwsCrashReportCheckForUploader_x                           0x8084B0
#define __AppCrashWrapper_x                                        0xC74E5C
#define __pCrashHandler_x                                          0x10E6A28
#define __CrashHandler_x                                           0x807F40
#define wwsCrashReportPlatformLaunchUploader_x                     0x80A6E0
#define DrawNetStatus_x                                            0x5BAF50
#define Util__FastTime_x                                           0x8A9D10
#define Expansion_HoT_x                                            0xF40588
#define __HelpPath_x                                               0xFC3E28
#define __STMLToText_x                                             0x8F0710
#define __GetAnimationCache_x                                      0x6B0390

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423270
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DED0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DCA0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D8980
#define AltAdvManager__IsAbilityReady_x                            0x4D89F0
#define AltAdvManager__GetAAById_x                                 0x4D8EE0
#define AltAdvManager__CanTrainAbility_x                           0x4D9B10
#define AltAdvManager__CanSeeAbility_x                             0x4D96D0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x469E20
#define CharacterZoneClient__HasSkill_x                            0x465E90
#define CharacterZoneClient__MakeMeVisible_x                       0x46B990
#define CharacterZoneClient__IsStackBlocked_x                      0x44C010
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B540
#define CharacterZoneClient__GetItemCountWorn_x                    0x4643F0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4644D0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4645B0
#define CharacterZoneClient__FindAffectSlot_x                      0x451690
#define CharacterZoneClient__BardCastBard_x                        0x44ACB0
#define CharacterZoneClient__GetMaxEffects_x                       0x449840
#define CharacterZoneClient__GetEffect_x                           0x44B770
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4514F0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449B90
#define CharacterZoneClient__GetLastEffectSlot_x                   0x450040

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6705E0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67E500

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x599AA0
#define CButtonWnd__CButtonWnd_x                                   0x8E4980

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x699550
#define CChatManager__InitContextMenu_x                            0x69A6A0
#define CChatManager__FreeChatWindow_x                             0x699000
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A2830
#define CChatManager__SetLockedActiveChatWindow_x                  0x699520

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8EEA60
#define CContextMenu__dCContextMenu_x                              0x8EEC70
#define CContextMenu__AddMenuItem_x                                0x8EF190
#define CContextMenu__RemoveMenuItem_x                             0x8EEDF0
#define CContextMenu__RemoveAllMenuItems_x                         0x8EEE10
#define CContextMenu__CheckMenuItem_x                              0x8EEE90

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8DAF30
#define CContextMenuManager__RemoveMenu_x                          0x8DB2C0
#define CContextMenuManager__PopupMenu_x                           0x8DB710
#define CContextMenuManager__Flush_x                               0x8DAFA0
#define CContextMenuManager__GetMenu_x                             0x4193F0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x88E2A0
#define CChatService__GetFriendName_x                              0x88E2B0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6A0310
#define CChatWindow__Clear_x                                       0x69FBF0
#define CChatWindow__WndNotification_x                             0x6A0C10

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8DED70
#define CComboWnd__Draw_x                                          0x8DEF80
#define CComboWnd__GetCurChoice_x                                  0x8DEB20
#define CComboWnd__GetListRect_x                                   0x8DF220
#define CComboWnd__GetTextRect_x                                   0x8DEDE0
#define CComboWnd__InsertChoice_x                                  0x8DF380
#define CComboWnd__SetColors_x                                     0x8DEAB0
#define CComboWnd__SetChoice_x                                     0x8DEAE0
#define CComboWnd__GetItemCount_x                                  0x8DEB10
#define CComboWnd__GetCurChoiceText_x                              0x8DEB60


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6AA520
#define CContainerWnd__vftable_x                                   0xAF6C88

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C66F0
#define CDisplay__GetClickedActor_x                                0x4BEFB0
#define CDisplay__GetUserDefinedColor_x                            0x4BDB90
#define CDisplay__GetWorldFilePath_x                               0x4BCFE0
#define CDisplay__is3dON_x                                         0x4BC470
#define CDisplay__ReloadUI_x                                       0x4D06D0
#define CDisplay__WriteTextHD2_x                                   0x4C2A80
#define CDisplay__TrueDistance_x                                   0x4BFBE0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x905B00

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8F2FC0
#define CEditWnd__GetCharIndexPt_x                                 0x8F4110
#define CEditWnd__GetDisplayString_x                               0x8F3170
#define CEditWnd__GetHorzOffset_x                                  0x8F34B0
#define CEditWnd__GetLineForPrintableChar_x                        0x8F3BE0
#define CEditWnd__GetSelStartPt_x                                  0x8F43C0
#define CEditWnd__GetSTMLSafeText_x                                0x8F3650
#define CEditWnd__PointFromPrintableChar_x                         0x8F3CD0
#define CEditWnd__SelectableCharFromPoint_x                        0x8F3E50
#define CEditWnd__SetEditable_x                                    0x8F3620

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56A880
#define CEverQuest__ClickedPlayer_x                                0x564400
#define CEverQuest__CreateTargetIndicator_x                        0x565300
#define CEverQuest__DeleteTargetIndicator_x                        0x565380
#define CEverQuest__DoTellWindow_x                                 0x4765A0
#define CEverQuest__OutputTextToLog_x                              0x476200
#define CEverQuest__DropHeldItemOnGround_x                         0x57ADF0
#define CEverQuest__dsp_chat_x                                     0x4768E0
#define CEverQuest__trimName_x                                     0x560D10
#define CEverQuest__Emote_x                                        0x579100
#define CEverQuest__EnterZone_x                                    0x5741E0
#define CEverQuest__GetBodyTypeDesc_x                              0x55E750
#define CEverQuest__GetClassDesc_x                                 0x567CA0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5682A0
#define CEverQuest__GetDeityDesc_x                                 0x55F030
#define CEverQuest__GetLangDesc_x                                  0x55EAE0
#define CEverQuest__GetRaceDesc_x                                  0x568460
#define CEverQuest__InterpretCmd_x                                 0x56C000
#define CEverQuest__LeftClickedOnPlayer_x                          0x580950
#define CEverQuest__LMouseUp_x                                     0x582990
#define CEverQuest__RightClickedOnPlayer_x                         0x581460
#define CEverQuest__RMouseUp_x                                     0x5823F0
#define CEverQuest__SetGameState_x                                 0x564CD0
#define CEverQuest__UPCNotificationFlush_x                         0x55D0E0
#define CEverQuest__IssuePetCommand_x                              0x56C9E0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BB170
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BB1D0
#define CGaugeWnd__Draw_x                                          0x6BB600

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B4D0
#define CGuild__GetGuildName_x                                     0x43B9A0
#define CGuild__GetGuildIndex_x                                    0x43CBB0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D7700

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E4B80
#define CInvSlotMgr__MoveItem_x                                    0x6E5340
#define CInvSlotMgr__SelectSlot_x                                  0x6E4470

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E38D0
#define CInvSlot__SliderComplete_x                                 0x6E1060
#define CInvSlot__GetItemBase_x                                    0x6E04C0
#define CInvSlot__UpdateItem_x                                     0x6E0A40

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E67A0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E78E0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7B5DC0
#define CItemDisplayWnd__UpdateStrings_x                           0x6E8A00
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F5570
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F5A80
#define CItemDisplayWnd__SetItem_x                                 0x6FB2F0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7ECF50

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EEF00

// CLabel 
#define CLabel__Draw_x                                             0x702080

// CListWnd
#define CListWnd__CListWnd_x                                       0x8CA880
#define CListWnd__dCListWnd_x                                      0x8CBB30
#define CListWnd__AddColumn_x                                      0x8CBAD0
#define CListWnd__AddColumn1_x                                     0x8CB170
#define CListWnd__AddLine_x                                        0x8CAB50
#define CListWnd__AddString_x                                      0x8CAD70
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C7980
#define CListWnd__CalculateVSBRange_x                              0x8C9D40
#define CListWnd__ClearSel_x                                       0x8C6CA0
#define CListWnd__ClearAllSel_x                                    0x8C6C50
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8CA710
#define CListWnd__Compare_x                                        0x8C8680
#define CListWnd__Draw_x                                           0x8C9940
#define CListWnd__DrawColumnSeparators_x                           0x8C97D0
#define CListWnd__DrawHeader_x                                     0x8C6F60
#define CListWnd__DrawItem_x                                       0x8C8D00
#define CListWnd__DrawLine_x                                       0x8C9470
#define CListWnd__DrawSeparator_x                                  0x8C9870
#define CListWnd__EnableLine_x                                     0x8C6E80
#define CListWnd__EnsureVisible_x                                  0x8C7AE0
#define CListWnd__ExtendSel_x                                      0x8C8C10
#define CListWnd__GetColumnMinWidth_x                              0x8C6590
#define CListWnd__GetColumnWidth_x                                 0x8C64C0
#define CListWnd__GetCurSel_x                                      0x8C5C90
#define CListWnd__GetItemAtPoint_x                                 0x8C7D80
#define CListWnd__GetItemAtPoint1_x                                0x8C7DF0
#define CListWnd__GetItemData_x                                    0x8C5FD0
#define CListWnd__GetItemHeight_x                                  0x8C75E0
#define CListWnd__GetItemIcon_x                                    0x8C61C0
#define CListWnd__GetItemRect_x                                    0x8C7BC0
#define CListWnd__GetItemText_x                                    0x8C6070
#define CListWnd__GetSelList_x                                     0x8CB060
#define CListWnd__GetSeparatorRect_x                               0x8C85A0
#define CListWnd__InsertLine_x                                     0x8CAF50
#define CListWnd__RemoveLine_x                                     0x8CAF60
#define CListWnd__SetColors_x                                      0x8C5DE0
#define CListWnd__SetColumnJustification_x                         0x8C6820
#define CListWnd__SetColumnWidth_x                                 0x8C6540
#define CListWnd__SetCurSel_x                                      0x8C5CD0
#define CListWnd__SetItemColor_x                                   0x8CA400
#define CListWnd__SetItemData_x                                    0x8C6D00
#define CListWnd__SetItemText_x                                    0x8CA240
#define CListWnd__ShiftColumnSeparator_x                           0x8CA0D0
#define CListWnd__Sort_x                                           0x8CBC30
#define CListWnd__ToggleSel_x                                      0x8C6BD0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71B0D0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73E8D0
#define CMerchantWnd__RequestBuyItem_x                             0x7478F0
#define CMerchantWnd__RequestSellItem_x                            0x74A040
#define CMerchantWnd__SelectRecoverySlot_x                         0x73EE80
#define CMerchantWnd__SelectBuySellSlot_x                          0x73BE50
#define CMerchantWnd__ActualSelect_x                               0x73FC90

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x85C670
#define CPacketScrambler__hton_x                                   0x85C680

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E9970
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E9A50
#define CSidlManager__CreateLabel_x                                0x7AAD30
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E7F10
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E9D30

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8E0DD0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8E0CC0
#define CSidlScreenWnd__ConvertToRes_x                             0x9059E0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8E16E0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8E28D0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8E2980
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8E1E40
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8E1090
#define CSidlScreenWnd__EnableIniStorage_x                         0x8E07F0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8E1280
#define CSidlScreenWnd__Init1_x                                    0x8E25A0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8E17A0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8E09B0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8E2080
#define CSidlScreenWnd__StoreIniInfo_x                             0x8E0450
#define CSidlScreenWnd__StoreIniVis_x                              0x8E07A0
#define CSidlScreenWnd__WndNotification_x                          0x8E2320
#define CSidlScreenWnd__GetChildItem_x                             0x8E08C0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8D4140
#define CSidlScreenWnd__m_layoutCopy_x                             0x173FE68

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x606600
#define CSkillMgr__GetSkillCap_x                                   0x6067E0
#define CSkillMgr__GetNameToken_x                                  0x6061B0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x904C90
#define CSliderWnd__SetValue_x                                     0x904E60
#define CSliderWnd__SetNumTicks_x                                  0x9055E0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7B1000

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8FEA30
#define CStmlWnd__CalculateHSBRange_x                              0x8F6F80
#define CStmlWnd__CalculateVSBRange_x                              0x8F6EF0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F7100
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F7900
#define CStmlWnd__ForceParseNow_x                                  0x8FF3B0
#define CStmlWnd__GetNextTagPiece_x                                0x8F7800
#define CStmlWnd__GetSTMLText_x                                    0x484730
#define CStmlWnd__GetVisibleText_x                                 0x8F8350
#define CStmlWnd__InitializeWindowVariables_x                      0x8FA920
#define CStmlWnd__MakeStmlColorTag_x                               0x8F61D0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8F6230
#define CStmlWnd__SetSTMLText_x                                    0x8FC170
#define CStmlWnd__StripFirstSTMLLines_x                            0x8FE6D0
#define CStmlWnd__UpdateHistoryString_x                            0x8F9290

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9028F0
#define CTabWnd__DrawCurrentPage_x                                 0x902180
#define CTabWnd__DrawTab_x                                         0x901F40
#define CTabWnd__GetCurrentPage_x                                  0x902530
#define CTabWnd__GetPageInnerRect_x                                0x901C30
#define CTabWnd__GetTabInnerRect_x                                 0x901E30
#define CTabWnd__GetTabRect_x                                      0x901D00
#define CTabWnd__InsertPage_x                                      0x902BE0
#define CTabWnd__SetPage_x                                         0x902560
#define CTabWnd__SetPageRect_x                                     0x902830
#define CTabWnd__UpdatePage_x                                      0x902B80
#define CTabWnd__GetPageFromTabIndex_x                             0x901E90
#define CTabWnd__GetCurrentTabIndex_x                              0x901BC0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E7A90
#define CPageWnd__SetTabText_x                                     0x90ED20

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x437100

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8DE720
#define CTextureFont__GetTextExtent_x                              0x8DE480

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63EF90

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x90B160

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8C3E40

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5A7840
#define CXStr__CXStr1_x                                            0x8C4EB0
#define CXStr__CXStr3_x                                            0x8A6FA0
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x8A7110
#define CXStr__operator_equal1_x                                   0x8A7160
#define CXStr__operator_plus_equal1_x                              0x8A8260

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8DC230
#define CXWnd__BringToTop_x                                        0x8D3310
#define CXWnd__Center_x                                            0x8D9530
#define CXWnd__ClrFocus_x                                          0x8D2EF0
#define CXWnd__Destroy_x                                           0x8DA020
#define CXWnd__DoAllDrawing_x                                      0x8D9190
#define CXWnd__DrawChildren_x                                      0x8D9330
#define CXWnd__DrawColoredRect_x                                   0x8D36F0
#define CXWnd__DrawTooltip_x                                       0x8D39A0
#define CXWnd__DrawTooltipAtPoint_x                                0x8D80E0
#define CXWnd__GetBorderFrame_x                                    0x8D3DF0
#define CXWnd__GetChildWndAt_x                                     0x8D9F00
#define CXWnd__GetClientClipRect_x                                 0x8D3BC0
#define CXWnd__GetScreenClipRect_x                                 0x8D87E0
#define CXWnd__GetScreenRect_x                                     0x8D3FD0
#define CXWnd__GetTooltipRect_x                                    0x8D3830
#define CXWnd__GetWindowTextA_x                                    0x427300
#define CXWnd__IsActive_x                                          0x8CE920
#define CXWnd__IsDescendantOf_x                                    0x8D3D30
#define CXWnd__IsReallyVisible_x                                   0x8D7100
#define CXWnd__IsType_x                                            0x8D95A0
#define CScreenPieceTemplate__IsType_x                             0x9078A0
#define CXWnd__Move_x                                              0x8D67E0
#define CXWnd__Move1_x                                             0x8D8E40
#define CXWnd__ProcessTransition_x                                 0x8D32B0
#define CXWnd__Refade_x                                            0x8D3090
#define CXWnd__Resize_x                                            0x8D40A0
#define CXWnd__Right_x                                             0x8D85E0
#define CXWnd__SetFocus_x                                          0x8D5940
#define CXWnd__SetFont_x                                           0x8D2F40
#define CXWnd__SetKeyTooltip_x                                     0x8D4310
#define CXWnd__SetMouseOver_x                                      0x8D8B20
#define CXWnd__StartFade_x                                         0x8D3360
#define CXWnd__GetChildItem_x                                      0x8D8A60
#define CXWnd__SetParent_x                                         0x8D9EB0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8D01E0
#define CXWndManager__DrawWindows_x                                0x8CFE20
#define CXWndManager__GetKeyboardFlags_x                           0x8CE450
#define CXWndManager__HandleKeyboardMsg_x                          0x8CEDC0
#define CXWndManager__RemoveWnd_x                                  0x8CEAB0

// CDBStr
#define CDBStr__GetString_x                                        0x4BAC90

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452850
#define EQ_Character__Cur_HP_x                                     0x465A70
#define EQ_Character__Cur_Mana_x                                   0x45AEE0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B850
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443780
#define EQ_Character__GetFocusRangeModifier_x                      0x4438D0
#define EQ_Character__GetHPRegen_x                                 0x4694B0
#define EQ_Character__GetEnduranceRegen_x                          0x465080
#define EQ_Character__GetManaRegen_x                               0x469A50
#define EQ_Character__Max_Endurance_x                              0x5CC960
#define EQ_Character__Max_HP_x                                     0x45DA60
#define EQ_Character__Max_Mana_x                                   0x5CC790
#define EQ_Character__doCombatAbility_x                            0x5C9E60
#define EQ_Character__UseSkill_x                                   0x470A30
#define EQ_Character__GetConLevel_x                                0x5BF5A0
#define EQ_Character__IsExpansionFlag_x                            0x426830
#define EQ_Character__TotalEffect_x                                0x44F980
#define EQ_Character__GetPCSpellAffect_x                           0x44BBE0
#define EQ_Character__SpellDuration_x                              0x449BE0
#define EQ_Character__FindItemByRecord_x                           0x4630E0
#define EQ_Character__GetAdjustedSkill_x                           0x465C40
#define EQ_Character__GetBaseSkill_x                               0x45D940

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x87A4A0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D4EC0

//PcClient
#define PcClient__PcClient_x                                       0x5C13E0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446C90
#define CCharacterSelect__EnterWorld_x                             0x446460
#define CCharacterSelect__Quit_x                                   0x445020

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59F440
#define EQ_Item__CreateItemTagString_x                             0x85A880
#define EQ_Item__IsStackable_x                                     0x84FEE0
#define EQ_Item__GetImageNum_x                                     0x852A20
#define EQ_Item__CreateItemClient_x                                0x5A04F0
#define EQ_Item__GetItemValue_x                                    0x859340
#define EQ_Item__ValueSellMerchant_x                               0x85C2D0
#define EQ_Item__IsKeyRingItem_x                                   0x850A30
#define EQ_Item__CanGoInBag_x                                      0x59F5D0
#define EQ_Item__GetMaxItemCount_x                                 0x84FDD0
#define EQ_Item__GetHeldItem_x                                     0x851820
#define EQ_Item__GetAugmentFitBySlot_x                             0x85C0F0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DAF80
#define EQ_LoadingS__Array_x                                       0xC16958

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CEE90
#define EQ_PC__GetAlternateAbilityId_x                             0x8646F0
#define EQ_PC__GetCombatAbility_x                                  0x864780
#define EQ_PC__GetCombatAbilityTimer_x                             0x85F320
#define EQ_PC__GetItemRecastTimer_x                                0x5C8610
#define EQ_PC__HasLoreItem_x                                       0x5C2BA0
#define EQ_PC__AlertInventoryChanged_x                             0x5BF550
#define EQ_PC__GetPcZoneClient_x                                   0x5E9510
#define EQ_PC__RemoveMyAffect_x                                    0x5C7A70
#define EQ_PC__GetKeyRingItems_x                                   0x85F740
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8723B0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x866640

// EQItemList 
#define EQItemList__EQItemList_x                                   0x526D00
#define EQItemList__add_object_x                                   0x5540B0
#define EQItemList__add_item_x                                     0x526C40
#define EQItemList__delete_item_x                                  0x5270F0
#define EQItemList__FreeItemList_x                                 0x526FF0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9F50

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D4C60
#define EQPlayer__dEQPlayer_x                                      0x5DD340
#define EQPlayer__DoAttack_x                                       0x5EEEA0
#define EQPlayer__EQPlayer_x                                       0x5DFA70
#define EQPlayer__SetNameSpriteState_x                             0x5DA170
#define EQPlayer__SetNameSpriteTint_x                              0x5D6080
#define PlayerBase__HasProperty_j_x                                0x938B50
#define EQPlayer__IsTargetable_x                                   0x938DF0
#define EQPlayer__CanSee_x                                         0x939350
#define PlayerZoneClient__ChangeHeight_x                           0x5EED60
#define EQPlayer__CanSee1_x                                        0x939440
#define PlayerBase__GetVisibilityLineSegment_x                     0x9390E0

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E96C0
#define PlayerZoneClient__IsValidTeleport_x                        0x554950
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D32D0


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E3AB0
#define EQPlayerManager__GetSpawnByName_x                          0x5E3F10
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E3AE0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A5BD0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A5C10
#define KeypressHandler__ClearCommandStateArray_x                  0x5A57C0
#define KeypressHandler__HandleKeyDown_x                           0x5A40E0
#define KeypressHandler__HandleKeyUp_x                             0x5A4400
#define KeypressHandler__SaveKeymapping_x                          0x5A5890

// MapViewMap 
#define MapViewMap__Clear_x                                        0x713A60
#define MapViewMap__SaveEx_x                                       0x716D90

#define PlayerPointManager__GetAltCurrency_x                       0x878550

// StringTable 
#define StringTable__getString_x                                   0x8726E0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CC3F0
#define PcZoneClient__RemovePetEffect_x                            0x5C8AE0
#define PcZoneClient__HasAlternateAbility_x                        0x5C9480
#define PcZoneClient__GetCurrentMod_x                              0x45CF10
#define PcZoneClient__GetModCap_x                                  0x45A640
#define PcZoneClient__CanEquipItem_x                               0x5C99A0
#define PcZoneClient__GetItemByID_x                                0x5CE200
#define PcZoneClient__GetItemByItemClass_x                         0x5CEDB0
#define PcZoneClient__RemoveBuffEffect_x                           0x5C7D20

//Doors
#define EQSwitch__UseSwitch_x                                      0x55B9A0

//IconCache
#define IconCache__GetIcon_x                                       0x6B09C0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A78B0
#define CContainerMgr__CloseContainer_x                            0x6A80D0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x77AC30

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5984B0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F5500
#define EQ_Spell__SpellAffects_x                                   0x4F26F0
#define EQ_Spell__SpellAffectBase_x                           0x4F2760
#define CharacterZoneClient__CalcAffectChange_x                    0x44BA70
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AD10
#define CLootWnd__LootAll_x                                        0x7092C0
#define CLootWnd__RequestLootSlot_x                                0x709AD0
#define EQ_Spell__IsStackable_x                                    0x4495D0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449680
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EF80
#define EQ_Spell__IsSPAStacking_x                                  0x4F2260
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F3300
#define EQ_Spell__IsNoRemove_x                                     0x435120
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F2280

#define __IsResEffectSpell_x                                       0x449730

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x884110

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7C28E0
#define CTargetWnd__WndNotification_x                              0x7C23D0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7C2AC0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C7A10

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4EDD50
#define EqSoundManager__PlayScriptMp3_x                            0x4EF7F0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A9020

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8F25F0
#define CSidlManager__FindAnimation1_x                             0x8E7940

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E28D0
#define CAltAbilityData__GetMercMaxRank_x                          0x4E2880
#define CAltAbilityData__GetMaxRank_x                              0x4D7030

//CTargetRing
#define CTargetRing__Cast_x                                        0x595D70

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459650
#define CharacterBase__CreateItemGlobalIndex_x                     0x4757B0
#define CharacterBase__CreateItemIndex_x                           0x520310
#define CharacterBase__GetItemPossession_x                         0x4444F0
#define CharacterBase__GetItemByGlobalIndex_x                      0x887F70
#define CharacterBase__GetEffectId_x                               0x459610

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x690720
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68FE80

//messages
#define msg_spell_worn_off_x                                       0x4FCF70
#define msg_new_text_x                                             0x5066D0
#define msgTokenTextParam_x                                        0x502EB0

//SpellManager
#define SpellManager__vftable_x                                    0xAD2418
#define SpellManager__SpellManager_x                               0x47E380
#define Spellmanager__LoadTextSpells_x          0x60D4B0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x93CEB0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x488310
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EEB0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449380
#define ItemGlobalIndex__IsValidIndex_x                            0x458EB0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x885DD0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x884D10

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7022D0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AC5D0
#define CCursorAttachment__Deactivate_x                            0x6ABB20

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x904190
#define CEQSuiteTextureLoader__GetTexture_x                        0x904310

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                                0x605170

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                                0x48CBA0

//IString
#define IString__Append_x                                           0x47EFD0
