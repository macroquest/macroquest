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
#define __ExpectedVersionDate                                     "Oct 29 2017"
#define __ExpectedVersionTime                                     "04:18:35"
#define __ActualVersionDate_x                                      0xAED358
#define __ActualVersionTime_x                                      0xAED364

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5AC510
#define __MemChecker1_x                                            0x8AB3B0
#define __MemChecker2_x                                            0x6423D0
#define __MemChecker3_x                                            0x642320
#define __MemChecker4_x                                            0x7FCED0
#define __EncryptPad0_x                                            0xC4B6A0
#define __EncryptPad1_x                                            0xD278E8
#define __EncryptPad2_x                                            0xC75268
#define __EncryptPad3_x                                            0xC74E68
#define __EncryptPad4_x                                            0xD15EE8
#define __EncryptPad5_x                                            0x10D1218
#define __AC1_x                                                    0x7BC225
#define __AC2_x                                                    0x564FE7
#define __AC3_x                                                    0x563160
#define __AC4_x                                                    0x575381
#define __AC5_x                                                    0x58915B
#define __AC6_x                                                    0x58CCFE
#define __AC7_x                                                    0x58375C
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
#define __do_loot_x                                                0x533CB0
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
#define __CastRay_x                                                0x54B7B0
#define __CastRay2_x                                               0x54B0E0
#define __HeadingDiff_x                                            0x93AFA0
#define __FixHeading_x                                             0x93AF30
#define __get_bearing_x                                            0x53AE00
#define __ConvertItemTags_x                                        0x5388D0
#define __ExecuteCmd_x                                             0x523230
#define __EQGetTime_x                                              0x8AAD50
#define __get_melee_range_x                                        0x529ED0
#define __GetGaugeValueFromEQ_x                                    0x7BADE0
#define __GetLabelFromEQ_x                                         0x7BC1B0
#define __ToggleKeyRingItem_x                                      0x490350
#define __GetXTargetType_x                                         0x93CBA0
#define __LoadFrontEnd_x                                           0x641AA0
#define __NewUIINI_x                                               0x7BA7C0
#define __ProcessGameEvents_x                                      0x5854F0
#define __ProcessMouseEvent_x                                      0x584C90
#define CrashDetected_x                                            0x643460
#define wwsCrashReportCheckForUploader_x                           0x808F60
#define __AppCrashWrapper_x                                        0xC74E5C
#define __pCrashHandler_x                                          0x10E6A28
#define __CrashHandler_x                                           0x8089F0
#define wwsCrashReportPlatformLaunchUploader_x                     0x80B190
#define DrawNetStatus_x                                            0x5BBF00
#define Util__FastTime_x                                           0x8AA9F0
#define Expansion_HoT_x                                            0xF40588
#define __HelpPath_x                                               0xFC3E28
#define __STMLToText_x                                             0x8F0E80
#define __GetAnimationCache_x                                      0x6B1170

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4234E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41E140
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DF10

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D8780
#define AltAdvManager__IsAbilityReady_x                            0x4D87F0
#define AltAdvManager__GetAAById_x                                 0x4D8CE0
#define AltAdvManager__CanTrainAbility_x                           0x4D9910
#define AltAdvManager__CanSeeAbility_x                             0x4D94D0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x469ED0
#define CharacterZoneClient__HasSkill_x                            0x465F40
#define CharacterZoneClient__MakeMeVisible_x                       0x46BA40
#define CharacterZoneClient__IsStackBlocked_x                      0x44C090
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B5C0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4644A0
#define CharacterZoneClient__GetItemCountInInventory_x             0x464580
#define CharacterZoneClient__GetCursorItemCount_x                  0x464660
#define CharacterZoneClient__FindAffectSlot_x                      0x4516F0
#define CharacterZoneClient__BardCastBard_x                        0x44AD30
#define CharacterZoneClient__GetMaxEffects_x                       0x4498C0
#define CharacterZoneClient__GetEffect_x                           0x44B7F0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451550
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449C10
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4500A0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6714A0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67F1D0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x59AD20
#define CButtonWnd__CButtonWnd_x                                   0x8E50D0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x69A370
#define CChatManager__InitContextMenu_x                            0x69B4C0
#define CChatManager__FreeChatWindow_x                             0x699E20
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A35E0
#define CChatManager__SetLockedActiveChatWindow_x                  0x69A340

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8EF1D0
#define CContextMenu__dCContextMenu_x                              0x8EF3E0
#define CContextMenu__AddMenuItem_x                                0x8EF900
#define CContextMenu__RemoveMenuItem_x                             0x8EF560
#define CContextMenu__RemoveAllMenuItems_x                         0x8EF580
#define CContextMenu__CheckMenuItem_x                              0x8EF600

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8DB6E0
#define CContextMenuManager__RemoveMenu_x                          0x8DBA70
#define CContextMenuManager__PopupMenu_x                           0x8DBEC0
#define CContextMenuManager__Flush_x                               0x8DB750
#define CContextMenuManager__GetMenu_x                             0x419660

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x88EFA0
#define CChatService__GetFriendName_x                              0x88EFB0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6A10D0
#define CChatWindow__Clear_x                                       0x6A09C0
#define CChatWindow__WndNotification_x                             0x6A19D0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8DF500
#define CComboWnd__Draw_x                                          0x8DF710
#define CComboWnd__GetCurChoice_x                                  0x8DF2B0
#define CComboWnd__GetListRect_x                                   0x8DF9B0
#define CComboWnd__GetTextRect_x                                   0x8DF570
#define CComboWnd__InsertChoice_x                                  0x8DFB10
#define CComboWnd__SetColors_x                                     0x8DF240
#define CComboWnd__SetChoice_x                                     0x8DF270
#define CComboWnd__GetItemCount_x                                  0x8DF2A0
#define CComboWnd__GetCurChoiceText_x                              0x8DF2F0


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6AB340
#define CContainerWnd__vftable_x                                   0xAF6C68

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C6500
#define CDisplay__GetClickedActor_x                                0x4BEDC0
#define CDisplay__GetUserDefinedColor_x                            0x4BD9A0
#define CDisplay__GetWorldFilePath_x                               0x4BCDF0
#define CDisplay__is3dON_x                                         0x4BC280
#define CDisplay__ReloadUI_x                                       0x4D04E0
#define CDisplay__WriteTextHD2_x                                   0x4C2890
#define CDisplay__TrueDistance_x                                   0x4BF9F0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x906250

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8F3730
#define CEditWnd__GetCharIndexPt_x                                 0x8F4890
#define CEditWnd__GetDisplayString_x                               0x8F38E0
#define CEditWnd__GetHorzOffset_x                                  0x8F3C20
#define CEditWnd__GetLineForPrintableChar_x                        0x8F4350
#define CEditWnd__GetSelStartPt_x                                  0x8F4B50
#define CEditWnd__GetSTMLSafeText_x                                0x8F3DC0
#define CEditWnd__PointFromPrintableChar_x                         0x8F4440
#define CEditWnd__SelectableCharFromPoint_x                        0x8F45C0
#define CEditWnd__SetEditable_x                                    0x8F3D90

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56BBB0
#define CEverQuest__ClickedPlayer_x                                0x565730
#define CEverQuest__CreateTargetIndicator_x                        0x566630
#define CEverQuest__DeleteTargetIndicator_x                        0x5666B0
#define CEverQuest__DoTellWindow_x                                 0x476650
#define CEverQuest__OutputTextToLog_x                              0x4762B0
#define CEverQuest__DropHeldItemOnGround_x                         0x57C120
#define CEverQuest__dsp_chat_x                                     0x476990
#define CEverQuest__trimName_x                                     0x562040
#define CEverQuest__Emote_x                                        0x57A430
#define CEverQuest__EnterZone_x                                    0x575510
#define CEverQuest__GetBodyTypeDesc_x                              0x55FA80
#define CEverQuest__GetClassDesc_x                                 0x568FD0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5695D0
#define CEverQuest__GetDeityDesc_x                                 0x560360
#define CEverQuest__GetLangDesc_x                                  0x55FE10
#define CEverQuest__GetRaceDesc_x                                  0x569790
#define CEverQuest__InterpretCmd_x                                 0x56D330
#define CEverQuest__LeftClickedOnPlayer_x                          0x581C70
#define CEverQuest__LMouseUp_x                                     0x583CB0
#define CEverQuest__RightClickedOnPlayer_x                         0x582780
#define CEverQuest__RMouseUp_x                                     0x583710
#define CEverQuest__SetGameState_x                                 0x566000
#define CEverQuest__UPCNotificationFlush_x                         0x55E410
#define CEverQuest__IssuePetCommand_x                              0x56DD10

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BC040
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BC0A0
#define CGaugeWnd__Draw_x                                          0x6BC4D0

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B680
#define CGuild__GetGuildName_x                                     0x43BB50
#define CGuild__GetGuildIndex_x                                    0x43CD60

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D8540

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E5970
#define CInvSlotMgr__MoveItem_x                                    0x6E6130
#define CInvSlotMgr__SelectSlot_x                                  0x6E5270

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E46D0
#define CInvSlot__SliderComplete_x                                 0x6E1E60
#define CInvSlot__GetItemBase_x                                    0x6E1300
#define CInvSlot__UpdateItem_x                                     0x6E1880

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E7550
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E8680

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7B6D10
#define CItemDisplayWnd__UpdateStrings_x                           0x6E9790
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F6340
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F6840
#define CItemDisplayWnd__SetItem_x                                 0x6FC120

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7EDCE0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EFCE0

// CLabel 
#define CLabel__Draw_x                                             0x702E80

// CListWnd
#define CListWnd__CListWnd_x                                       0x8CB400
#define CListWnd__dCListWnd_x                                      0x8CC6C0
#define CListWnd__AddColumn_x                                      0x8CC660
#define CListWnd__AddColumn1_x                                     0x8CBCF0
#define CListWnd__AddLine_x                                        0x8CB6D0
#define CListWnd__AddString_x                                      0x8CB8F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C8520
#define CListWnd__CalculateVSBRange_x                              0x8CA8D0
#define CListWnd__ClearSel_x                                       0x8C7830
#define CListWnd__ClearAllSel_x                                    0x8C77E0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8CB290
#define CListWnd__Compare_x                                        0x8C9210
#define CListWnd__Draw_x                                           0x8CA4D0
#define CListWnd__DrawColumnSeparators_x                           0x8CA360
#define CListWnd__DrawHeader_x                                     0x8C7AF0
#define CListWnd__DrawItem_x                                       0x8C9890
#define CListWnd__DrawLine_x                                       0x8CA000
#define CListWnd__DrawSeparator_x                                  0x8CA400
#define CListWnd__EnableLine_x                                     0x8C7A10
#define CListWnd__EnsureVisible_x                                  0x8C8680
#define CListWnd__ExtendSel_x                                      0x8C97A0
#define CListWnd__GetColumnMinWidth_x                              0x8C7120
#define CListWnd__GetColumnWidth_x                                 0x8C7050
#define CListWnd__GetCurSel_x                                      0x8C6820
#define CListWnd__GetItemAtPoint_x                                 0x8C8920
#define CListWnd__GetItemAtPoint1_x                                0x8C8990
#define CListWnd__GetItemData_x                                    0x8C6B60
#define CListWnd__GetItemHeight_x                                  0x8C8170
#define CListWnd__GetItemIcon_x                                    0x8C6D50
#define CListWnd__GetItemRect_x                                    0x8C8760
#define CListWnd__GetItemText_x                                    0x8C6C00
#define CListWnd__GetSelList_x                                     0x8CBBE0
#define CListWnd__GetSeparatorRect_x                               0x8C9130
#define CListWnd__InsertLine_x                                     0x8CBAD0
#define CListWnd__RemoveLine_x                                     0x8CBAE0
#define CListWnd__SetColors_x                                      0x8C6970
#define CListWnd__SetColumnJustification_x                         0x8C73B0
#define CListWnd__SetColumnWidth_x                                 0x8C70D0
#define CListWnd__SetCurSel_x                                      0x8C6860
#define CListWnd__SetItemColor_x                                   0x8CAF80
#define CListWnd__SetItemData_x                                    0x8C7890
#define CListWnd__SetItemText_x                                    0x8CADC0
#define CListWnd__ShiftColumnSeparator_x                           0x8CAC50
#define CListWnd__Sort_x                                           0x8CC7C0
#define CListWnd__ToggleSel_x                                      0x8C7760

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71C0A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73F6C0
#define CMerchantWnd__RequestBuyItem_x                             0x7486C0
#define CMerchantWnd__RequestSellItem_x                            0x74AE10
#define CMerchantWnd__SelectRecoverySlot_x                         0x73FC70
#define CMerchantWnd__SelectBuySellSlot_x                          0x73CC40
#define CMerchantWnd__ActualSelect_x                               0x740A80

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x85D2D0
#define CPacketScrambler__hton_x                                   0x85D2E0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8EA0D0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8EA1B0
#define CSidlManager__CreateLabel_x                                0x7ABC80
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E8680
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8EA490

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8E1540
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8E1440
#define CSidlScreenWnd__ConvertToRes_x                             0x906130
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8E1E40
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8E3000
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8E30B0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8E2580
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8E17F0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8E0F70
#define CSidlScreenWnd__GetSidlPiece_x                             0x8E19E0
#define CSidlScreenWnd__Init1_x                                    0x8E2CD0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8E1EF0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8E1130
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8E27C0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8E0BD0
#define CSidlScreenWnd__StoreIniVis_x                              0x8E0F20
#define CSidlScreenWnd__WndNotification_x                          0x8E2A50
#define CSidlScreenWnd__GetChildItem_x                             0x8E1040
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8D4AA0
#define CSidlScreenWnd__m_layoutCopy_x                             0x173FE68

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x607660
#define CSkillMgr__GetSkillCap_x                                   0x607840
#define CSkillMgr__GetNameToken_x                                  0x607210

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9053F0
#define CSliderWnd__SetValue_x                                     0x9055C0
#define CSliderWnd__SetNumTicks_x                                  0x905D40

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7B1F60

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8FF1C0
#define CStmlWnd__CalculateHSBRange_x                              0x8F7720
#define CStmlWnd__CalculateVSBRange_x                              0x8F7690
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F78A0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F80A0
#define CStmlWnd__ForceParseNow_x                                  0x8FFB40
#define CStmlWnd__GetNextTagPiece_x                                0x8F7FA0
#define CStmlWnd__GetSTMLText_x                                    0x484940
#define CStmlWnd__GetVisibleText_x                                 0x8F8AF0
#define CStmlWnd__InitializeWindowVariables_x                      0x8FB0C0
#define CStmlWnd__MakeStmlColorTag_x                               0x8F6970
#define CStmlWnd__MakeWndNotificationTag_x                         0x8F69D0
#define CStmlWnd__SetSTMLText_x                                    0x8FC910
#define CStmlWnd__StripFirstSTMLLines_x                            0x8FEE60
#define CStmlWnd__UpdateHistoryString_x                            0x8F9A30

// CTabWnd 
#define CTabWnd__Draw_x                                            0x903050
#define CTabWnd__DrawCurrentPage_x                                 0x9028E0
#define CTabWnd__DrawTab_x                                         0x9026A0
#define CTabWnd__GetCurrentPage_x                                  0x902C90
#define CTabWnd__GetPageInnerRect_x                                0x902390
#define CTabWnd__GetTabInnerRect_x                                 0x902590
#define CTabWnd__GetTabRect_x                                      0x902460
#define CTabWnd__InsertPage_x                                      0x903340
#define CTabWnd__SetPage_x                                         0x902CC0
#define CTabWnd__SetPageRect_x                                     0x902F90
#define CTabWnd__UpdatePage_x                                      0x9032E0
#define CTabWnd__GetPageFromTabIndex_x                             0x9025F0
#define CTabWnd__GetCurrentTabIndex_x                              0x902320

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E8830
#define CPageWnd__SetTabText_x                                     0x90F490

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x437290

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8DEEB0
#define CTextureFont__GetTextExtent_x                              0x8DEC10

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63FD30

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x90B8D0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8C4A80

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5A8940
#define CXStr__CXStr1_x                                            0x755B10
#define CXStr__CXStr3_x                                            0x8A7C40
#define CXStr__dCXStr_x                                            0x6BBF20
#define CXStr__operator_equal_x                                    0x8A7DB0
#define CXStr__operator_equal1_x                                   0x8A7E00
#define CXStr__operator_plus_equal1_x                              0x8A8F00

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8DC9D0
#define CXWnd__BringToTop_x                                        0x8D3D20
#define CXWnd__Center_x                                            0x8D9D50
#define CXWnd__ClrFocus_x                                          0x8D3900
#define CXWnd__Destroy_x                                           0x8DA800
#define CXWnd__DoAllDrawing_x                                      0x8D99A0
#define CXWnd__DrawChildren_x                                      0x8D9B40
#define CXWnd__DrawColoredRect_x                                   0x8D40D0
#define CXWnd__DrawTooltip_x                                       0x8D4380
#define CXWnd__DrawTooltipAtPoint_x                                0x8D8960
#define CXWnd__GetBorderFrame_x                                    0x8D47B0
#define CXWnd__GetChildWndAt_x                                     0x8DA6F0
#define CXWnd__GetClientClipRect_x                                 0x8D4580
#define CXWnd__GetScreenClipRect_x                                 0x8D9060
#define CXWnd__GetScreenRect_x                                     0x8D4940
#define CXWnd__GetTooltipRect_x                                    0x8D4210
#define CXWnd__GetWindowTextA_x                                    0x427570
#define CXWnd__IsActive_x                                          0x8CF430
#define CXWnd__IsDescendantOf_x                                    0x8D4700
#define CXWnd__IsReallyVisible_x                                   0x8D79B0
#define CXWnd__IsType_x                                            0x8D9DC0
#define CScreenPieceTemplate__IsType_x                             0x908020
#define CXWnd__Move_x                                              0x8D70C0
#define CXWnd__Move1_x                                             0x8D9660
#define CXWnd__ProcessTransition_x                                 0x8D3CD0
#define CXWnd__Refade_x                                            0x8D3AB0
#define CXWnd__Resize_x                                            0x8D4A00
#define CXWnd__Right_x                                             0x8D8E60
#define CXWnd__SetFocus_x                                          0x8D6250
#define CXWnd__SetFont_x                                           0x8D3950
#define CXWnd__SetKeyTooltip_x                                     0x8D4C70
#define CXWnd__SetMouseOver_x                                      0x8D9370
#define CXWnd__StartFade_x                                         0x8D3D70
#define CXWnd__GetChildItem_x                                      0x8D92B0
#define CXWnd__SetParent_x                                         0x8DA6A0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8D0CE0
#define CXWndManager__DrawWindows_x                                0x8D0930
#define CXWndManager__GetKeyboardFlags_x                           0x8CEFA0
#define CXWndManager__HandleKeyboardMsg_x                          0x8CF8D0
#define CXWndManager__RemoveWnd_x                                  0x8CF5C0

// CDBStr
#define CDBStr__GetString_x                                        0x4BAAF0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4528B0
#define EQ_Character__Cur_HP_x                                     0x465B20
#define EQ_Character__Cur_Mana_x                                   0x45AF70
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B8D0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443900
#define EQ_Character__GetFocusRangeModifier_x                      0x443A50
#define EQ_Character__GetHPRegen_x                                 0x469560
#define EQ_Character__GetEnduranceRegen_x                          0x465130
#define EQ_Character__GetManaRegen_x                               0x469B00
#define EQ_Character__Max_Endurance_x                              0x5CD950
#define EQ_Character__Max_HP_x                                     0x45DAF0
#define EQ_Character__Max_Mana_x                                   0x5CD780
#define EQ_Character__doCombatAbility_x                            0x5CAE50
#define EQ_Character__UseSkill_x                                   0x470AE0
#define EQ_Character__GetConLevel_x                                0x5C0570
#define EQ_Character__IsExpansionFlag_x                            0x426A90
#define EQ_Character__TotalEffect_x                                0x44F9E0
#define EQ_Character__GetPCSpellAffect_x                           0x44BC60
#define EQ_Character__SpellDuration_x                              0x449C60
#define EQ_Character__FindItemByRecord_x                           0x463170
#define EQ_Character__GetAdjustedSkill_x                           0x465CF0
#define EQ_Character__GetBaseSkill_x                               0x45D9D0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x87B1A0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D5F70

//PcClient
#define PcClient__PcClient_x                                       0x5C23B0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446D30
#define CCharacterSelect__EnterWorld_x                             0x446500
#define CCharacterSelect__Quit_x                                   0x4450C0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5A06D0
#define EQ_Item__CreateItemTagString_x                             0x85B4E0
#define EQ_Item__IsStackable_x                                     0x850B30
#define EQ_Item__GetImageNum_x                                     0x8536B0
#define EQ_Item__CreateItemClient_x                                0x5A1790
#define EQ_Item__GetItemValue_x                                    0x859FA0
#define EQ_Item__ValueSellMerchant_x                               0x85CF30
#define EQ_Item__IsKeyRingItem_x                                   0x851670
#define EQ_Item__CanGoInBag_x                                      0x5A0860
#define EQ_Item__GetMaxItemCount_x                                 0x850A20
#define EQ_Item__GetHeldItem_x                                     0x8524C0
#define EQ_Item__GetAugmentFitBySlot_x                             0x85CD60

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DAD60
#define EQ_LoadingS__Array_x                                       0xC16958

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CFE70
#define EQ_PC__GetAlternateAbilityId_x                             0x865360
#define EQ_PC__GetCombatAbility_x                                  0x8653F0
#define EQ_PC__GetCombatAbilityTimer_x                             0x85FF80
#define EQ_PC__GetItemRecastTimer_x                                0x5C9600
#define EQ_PC__HasLoreItem_x                                       0x5C3B70
#define EQ_PC__AlertInventoryChanged_x                             0x5C0520
#define EQ_PC__GetPcZoneClient_x                                   0x5EA510
#define EQ_PC__RemoveMyAffect_x                                    0x5C8A60
#define EQ_PC__GetKeyRingItems_x                                   0x8603A0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x873050
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8672E0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x527F50
#define EQItemList__add_object_x                                   0x5552B0
#define EQItemList__add_item_x                                     0x527E90
#define EQItemList__delete_item_x                                  0x528340
#define EQItemList__FreeItemList_x                                 0x528240

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9D80

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D5D10
#define EQPlayer__dEQPlayer_x                                      0x5DE3D0
#define EQPlayer__DoAttack_x                                       0x5EFE90
#define EQPlayer__EQPlayer_x                                       0x5E0AF0
#define EQPlayer__SetNameSpriteState_x                             0x5DB220
#define EQPlayer__SetNameSpriteTint_x                              0x5D7130
#define PlayerBase__HasProperty_j_x                                0x9393B0
#define EQPlayer__IsTargetable_x                                   0x939650
#define EQPlayer__CanSee_x                                         0x939BB0
#define PlayerZoneClient__ChangeHeight_x                           0x5EFD50
#define EQPlayer__CanSee1_x                                        0x939CA0
#define PlayerBase__GetVisibilityLineSegment_x                     0x939940

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5EA6C0
#define PlayerZoneClient__IsValidTeleport_x                        0x555B50
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D30E0


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E4B30
#define EQPlayerManager__GetSpawnByName_x                          0x5E4F90
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E4B60

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A6CD0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A6D10
#define KeypressHandler__ClearCommandStateArray_x                  0x5A68C0
#define KeypressHandler__HandleKeyDown_x                           0x5A51E0
#define KeypressHandler__HandleKeyUp_x                             0x5A5500
#define KeypressHandler__SaveKeymapping_x                          0x5A6990

// MapViewMap 
#define MapViewMap__Clear_x                                        0x714A30
#define MapViewMap__SaveEx_x                                       0x717D60

#define PlayerPointManager__GetAltCurrency_x                       0x8791B0

// StringTable 
#define StringTable__getString_x                                   0x873380

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CD3E0
#define PcZoneClient__RemovePetEffect_x                            0x5C9AD0
#define PcZoneClient__HasAlternateAbility_x                        0x5CA470
#define PcZoneClient__GetCurrentMod_x                              0x45CFA0
#define PcZoneClient__GetModCap_x                                  0x45A6D0
#define PcZoneClient__CanEquipItem_x                               0x5CA990
#define PcZoneClient__GetItemByID_x                                0x5CF1F0
#define PcZoneClient__GetItemByItemClass_x                         0x5CFD90
#define PcZoneClient__RemoveBuffEffect_x                           0x5C8D10

//Doors
#define EQSwitch__UseSwitch_x                                      0x55CC70

//IconCache
#define IconCache__GetIcon_x                                       0x6B17A0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A8700
#define CContainerMgr__CloseContainer_x                            0x6A8F20

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x77BB70

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x599760

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F5570
#define EQ_Spell__SpellAffects_x                                   0x4F2760
#define EQ_Spell__SpellAffectBase_x                           0x4F27D0
#define CharacterZoneClient__CalcAffectChange_x                    0x44BAF0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AD90
#define CLootWnd__LootAll_x                                        0x70A2F0
#define CLootWnd__RequestLootSlot_x                                0x70AB00
#define EQ_Spell__IsStackable_x                                    0x449680
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449730
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43F100
#define EQ_Spell__IsSPAStacking_x                                  0x4F22D0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F3370
#define EQ_Spell__IsNoRemove_x                                     0x4352D0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F22F0

#define __IsResEffectSpell_x                                       0x4497B0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x884E40

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7C3890
#define CTargetWnd__WndNotification_x                              0x7C3380
#define CTargetWnd__RefreshTargetBuffs_x                           0x7C3A70

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C89B0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4EDDB0
#define EqSoundManager__PlayScriptMp3_x                            0x4EF850

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8E90

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8F2D60
#define CSidlManager__FindAnimation1_x                             0x8E80B0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E2750
#define CAltAbilityData__GetMercMaxRank_x                          0x4E2700
#define CAltAbilityData__GetMaxRank_x                              0x4D6E30

//CTargetRing
#define CTargetRing__Cast_x                                        0x597020

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459690
#define CharacterBase__CreateItemGlobalIndex_x                     0x475860
#define CharacterBase__CreateItemIndex_x                           0x5215B0
#define CharacterBase__GetItemPossession_x                         0x4445C0
#define CharacterBase__GetItemByGlobalIndex_x                      0x888C90
#define CharacterBase__GetEffectId_x                               0x459650

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6915A0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x690D00

//messages
#define msg_spell_worn_off_x                                       0x4FD010
#define msg_new_text_x                                             0x506780
#define msgTokenTextParam_x                                        0x502F60

//SpellManager
#define SpellManager__vftable_x                                    0xAD23F8
#define SpellManager__SpellManager_x                               0x47E4F0
#define Spellmanager__LoadTextSpells_x          0x60E4F0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x93D6C0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4883E0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43F030
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449420
#define ItemGlobalIndex__IsValidIndex_x                            0x458F20

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x886B00
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x885A40

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7030D0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AD3E0
#define CCursorAttachment__Deactivate_x                            0x6AC930

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9048F0
#define CEQSuiteTextureLoader__GetTexture_x                        0x904A70

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                                0x6062D0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                                0x48CC70

//IString
#define IString__Append_x                                           0x47F190
