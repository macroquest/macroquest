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
#define __ExpectedVersionDate                                     "Oct 23 2017"
#define __ExpectedVersionTime                                     "04:14:59"
#define __ActualVersionDate_x                                      0xAEC368
#define __ActualVersionTime_x                                      0xAEC374

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5AC5A0
#define __MemChecker1_x                                            0x8A9990
#define __MemChecker2_x                                            0x642710
#define __MemChecker3_x                                            0x642660
#define __MemChecker4_x                                            0x7FB360
#define __EncryptPad0_x                                            0xC4A6A0
#define __EncryptPad1_x                                            0xD268E8
#define __EncryptPad2_x                                            0xC74268
#define __EncryptPad3_x                                            0xC73E68
#define __EncryptPad4_x                                            0xD14EE8
#define __EncryptPad5_x                                            0x10D0218
#define __AC1_x                                                    0x7BA1F5
#define __AC2_x                                                    0x565197
#define __AC3_x                                                    0x563310
#define __AC4_x                                                    0x575531
#define __AC5_x                                                    0x58935B
#define __AC6_x                                                    0x58CF0E
#define __AC7_x                                                    0x58395C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FA4BA0

// Direct Input
#define DI8__Main_x                                                0x10D01F0
#define DI8__Keyboard_x                                            0x10D01F4
#define DI8__Mouse_x                                               0x10D01F8
#define DI8__Mouse_Copy_x                                          0xF3E224
#define DI8__Mouse_Check_x                                         0xFC7EDC
#define __AutoSkillArray_x                                         0xF3F138
#define __Attack_x                                                 0xFC2833
#define __Autofire_x                                               0xFC2834
#define __BindList_x                                               0xC25058
#define g_eqCommandStates_x                                        0xF2CF70
#define __Clicks_x                                                 0xF3E2E0
#define __CommandList_x                                            0xC27770
#define __CurrentMapLabel_x                                        0x10D61E8
#define __CurrentSocial_x                                          0xBF45D0
#define __DoAbilityList_x                                          0xF749F8
#define __do_loot_x                                                0x533DC0
#define __DrawHandler_x                                            0x173FF54
#define __GroupCount_x                                             0xF2E87A

#define __Guilds_x                                                 0xF34490
#define __gWorld_x                                                 0xF30D34
#define __HotkeyPage_x                                             0xFBB3F8
#define __HWnd_x                                                   0xFC7FF8
#define __InChatMode_x                                             0xF3E20C
#define __LastTell_x                                               0xF400F4
#define __LMouseHeldTime_x                                         0xF3E34C
#define __Mouse_x                                                  0x10D01FC
#define __MouseLook_x                                              0xF3E2A6
#define __MouseEventTime_x                                         0xFC30BC
#define __gpbCommandEvent_x                                        0xF30DFC
#define __NetStatusToggle_x                                        0xF3E2A9
#define __PCNames_x                                                0xF3F6FC
#define __RangeAttackReady_x                                       0xF3F41C
#define __RMouseHeldTime_x                                         0xF3E348
#define __RunWalkState_x                                           0xF3E210
#define __ScreenMode_x                                             0xE7CB50
#define __ScreenX_x                                                0xF3E1C4
#define __ScreenY_x                                                0xF3E1C0
#define __ScreenXMax_x                                             0xF3E1C8
#define __ScreenYMax_x                                             0xF3E1CC
#define __ServerHost_x                                             0xF2E7C4
#define __ServerName_x                                             0xF749B8
#define __ShiftKeyDown_x                                           0xF3E8A0
#define __ShowNames_x                                              0xF3F5DC
#define __Socials_x                                                0xF74AB8
#define __SubscriptionType_x                                       0x1106A5C
#define __TargetAggroHolder_x                                      0x10D8434
#define __ZoneType_x                                               0xF3E6A4
#define __GroupAggro_x                                             0x10D8474
#define __LoginName_x                                              0xFC6AD4
#define __Inviter_x                                                0xFC27B0
#define __AttackOnAssist_x                                         0xF3F598
#define __UseTellWindows_x                                         0xF3F894

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF30E20
#define instEQZoneInfo_x                                           0xF3E49C
#define instKeypressHandler_x                                      0xFC30A0
#define pinstActiveBanker_x                                        0xF30DD8
#define pinstActiveCorpse_x                                        0xF30DDC
#define pinstActiveGMaster_x                                       0xF30DE0
#define pinstActiveMerchant_x                                      0xF30DD4
#define pinstAggroInfo_x                                           0xD3A1A8
#define pinstAltAdvManager_x                                       0xE7DCB8
#define pinstAuraMgr_x                                             0xD4A9C0
#define pinstBandageTarget_x                                       0xF30DC0
#define pinstCamActor_x                                            0xE7D588
#define pinstCDBStr_x                                              0xE7CAE4
#define pinstCDisplay_x                                            0xF30DE8
#define pinstCEverQuest_x                                          0x10D0370
#define pinstEverQuestInfo_x                                       0xF3E1B8
#define pinstCharData_x                                            0xF30DA4
#define pinstCharSpawn_x                                           0xF30DCC
#define pinstControlledMissile_x                                   0xF30DA0
#define pinstControlledPlayer_x                                    0xF30DCC
#define pinstCSidlManager_x                                        0x173EEC0
#define pinstCXWndManager_x                                        0x173EEB8
#define instDynamicZone_x                                          0xF3E058
#define pinstDZMember_x                                            0xF3E168
#define pinstDZTimerInfo_x                                         0xF3E16C
#define pinstEQItemList_x                                          0xF2D248
#define pinstEQObjectList_x                                        0xF2E274
#define instEQMisc_x                                               0xC0D498
#define pinstEQSoundManager_x                                      0xE7E288
#define instExpeditionLeader_x                                     0xF3E0A2
#define instExpeditionName_x                                       0xF3E0E2
#define pinstGroup_x                                               0xF2E876
#define pinstImeManager_x                                          0x173EEC4
#define pinstLocalPlayer_x                                         0xF30DB8
#define pinstMercenaryData_x                                       0xFC3720
#define pinstMercenaryStats_x                                      0x10D8580
#define pinstMercAltAbilities_x                                    0xE7E040
#define pinstModelPlayer_x                                         0xF30DE4
#define pinstPCData_x                                              0xF30DA4
#define pinstSkillMgr_x                                            0xFC4790
#define pinstSpawnManager_x                                        0xFC3F70
#define pinstSpellManager_x                                        0xFC48D8
#define pinstSpellSets_x                                           0xFBB45C
#define pinstStringTable_x                                         0xF30D4C
#define pinstSwitchManager_x                                       0xF2E408
#define pinstTarget_x                                              0xF30DD0
#define pinstTargetObject_x                                        0xF30DA8
#define pinstTargetSwitch_x                                        0xF30DAC
#define pinstTaskMember_x                                          0xE7CA30
#define pinstTrackTarget_x                                         0xF30DC4
#define pinstTradeTarget_x                                         0xF30DB4
#define instTributeActive_x                                        0xC0D4BD
#define pinstViewActor_x                                           0xE7D584
#define pinstWorldData_x                                           0xF30D88
#define pinstZoneAddr_x                                            0xF3E73C
#define pinstPlayerPath_x                                          0xFC3FD0
#define pinstTargetIndicator_x                                     0xFC4A70
#define pinstCTargetManager_x                                      0xFC4AD0
#define EQObject_Top_x                                             0xF30D98
#define pinstRealEstateItems_x                                     0xFC45FC
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE7D4A0
#define pinstCAchievementsWnd_x                                    0xE7D4FC
#define pinstCTextOverlay_x                                        0xD3A750
#define pinstCAudioTriggersWindow_x                                0xD3A538
#define pinstCCharacterSelect_x                                    0xE7D40C
#define pinstCFacePick_x                                           0xE7D1BC
#define pinstCFindItemWnd_x                                        0xE7D49C
#define pinstCNoteWnd_x                                            0xE7D3C4
#define pinstCBookWnd_x                                            0xE7D3CC
#define pinstCPetInfoWnd_x                                         0xE7D3D0
#define pinstCTrainWnd_x                                           0xE7D3D4
#define pinstCSkillsWnd_x                                          0xE7D3D8
#define pinstCSkillsSelectWnd_x                                    0xE7D3DC
#define pinstCCombatSkillsSelectWnd_x                              0xE7D3E0
#define pinstCFriendsWnd_x                                         0xE7D3E4
#define pinstCAuraWnd_x                                            0xE7D3E8
#define pinstCRespawnWnd_x                                         0xE7D3EC
#define pinstCBandolierWnd_x                                       0xE7D3F0
#define pinstCPotionBeltWnd_x                                      0xE7D3F4
#define pinstCAAWnd_x                                              0xE7D3F8
#define pinstCAlarmWnd_x                                           0xE7D404
#define pinstCGroupSearchFiltersWnd_x                              0xE7D3FC
#define pinstCLoadskinWnd_x                                        0xE7D400
#define pinstCLargeDialogWnd_x                                     0x10D74E0
#define pinstCMusicPlayerWnd_x                                     0xE7D408
#define pinstCMailWnd_x                                            0xE7D410
#define pinstCMailCompositionWnd_x                                 0xE7D414
#define pinstCMailAddressBookWnd_x                                 0xE7D418
#define pinstCRaidWnd_x                                            0xE7D420
#define pinstCRaidOptionsWnd_x                                     0xE7D424
#define pinstCBreathWnd_x                                          0xE7D428
#define pinstCMapViewWnd_x                                         0xE7D42C
#define pinstCMapToolbarWnd_x                                      0xE7D430
#define pinstCEditLabelWnd_x                                       0xE7D434
#define pinstCTargetWnd_x                                          0xE7D438
#define pinstCColorPickerWnd_x                                     0xE7D43C
#define pinstCPlayerWnd_x                                          0xE7D440
#define pinstCOptionsWnd_x                                         0xE7D444
#define pinstCBuffWindowNORMAL_x                                   0xE7D448
#define pinstCBuffWindowSHORT_x                                    0xE7D44C
#define pinstCharacterCreation_x                                   0xE7D450
#define pinstCCursorAttachment_x                                   0xE7D454
#define pinstCCastingWnd_x                                         0xE7D458
#define pinstCCastSpellWnd_x                                       0xE7D45C
#define pinstCSpellBookWnd_x                                       0xE7D460
#define pinstCInventoryWnd_x                                       0xE7D464
#define pinstCBankWnd_x                                            0xE7D46C
#define pinstCQuantityWnd_x                                        0xE7D470
#define pinstCLootWnd_x                                            0xE7D474
#define pinstCActionsWnd_x                                         0xE7D478
#define pinstCCombatAbilityWnd_x                                   0xE7D480
#define pinstCMerchantWnd_x                                        0xE7D484
#define pinstCTradeWnd_x                                           0xE7D48C
#define pinstCSelectorWnd_x                                        0xE7D490
#define pinstCBazaarWnd_x                                          0xE7D494
#define pinstCBazaarSearchWnd_x                                    0xE7D498
#define pinstCGiveWnd_x                                            0xE7D4B8
#define pinstCTrackingWnd_x                                        0xE7D4C0
#define pinstCInspectWnd_x                                         0xE7D4C4
#define pinstCSocialEditWnd_x                                      0xE7D4C8
#define pinstCFeedbackWnd_x                                        0xE7D4CC
#define pinstCBugReportWnd_x                                       0xE7D4D0
#define pinstCVideoModesWnd_x                                      0xE7D4D4
#define pinstCTextEntryWnd_x                                       0xE7D4DC
#define pinstCFileSelectionWnd_x                                   0xE7D4E0
#define pinstCCompassWnd_x                                         0xE7D4E4
#define pinstCPlayerNotesWnd_x                                     0xE7D4E8
#define pinstCGemsGameWnd_x                                        0xE7D4EC
#define pinstCTimeLeftWnd_x                                        0xE7D508
#define pinstCPetitionQWnd_x                                       0xE7D50C
#define pinstCStoryWnd_x                                           0xE7D510
#define pinstCJournalTextWnd_x                                     0xE7D514
#define pinstCJournalCatWnd_x                                      0xE7D518
#define pinstCBodyTintWnd_x                                        0xE7D51C
#define pinstCServerListWnd_x                                      0xE7D520
#define pinstCAvaZoneWnd_x                                         0xE7D52C
#define pinstCBlockedBuffWnd_x                                     0xE7D530
#define pinstCBlockedPetBuffWnd_x                                  0xE7D534
#define pinstCInvSlotMgr_x                                         0xE7D57C
#define pinstCContainerMgr_x                                       0xE7D580
#define pinstCAdventureLeaderboardWnd_x                            0x10D0D20
#define pinstCAdventureRequestWnd_x                                0x10D0D98
#define pinstCAltStorageWnd_x                                      0x10D1078
#define pinstCAdventureStatsWnd_x                                  0x10D0E10
#define pinstCBarterMerchantWnd_x                                  0x10D1DC0
#define pinstCBarterSearchWnd_x                                    0x10D1E38
#define pinstCBarterWnd_x                                          0x10D1EB0
#define pinstCChatWindowManager_x                                  0x10D26C0
#define pinstCDynamicZoneWnd_x                                     0x10D2BF0
#define pinstCEQMainWnd_x                                          0x10D2DB8
#define pinstCFellowshipWnd_x                                      0x10D2B84
#define pinstCFindLocationWnd_x                                    0x10D3088
#define pinstCGroupSearchWnd_x                                     0x10D3358
#define pinstCGroupWnd_x                                           0x10D33D0
#define pinstCGuildBankWnd_x                                       0x10D3448
#define pinstCGuildMgmtWnd_x                                       0x10D5538
#define pinstCHotButtonWnd_x                                       0x10D5634
#define pinstCHotButtonWnd1_x                                      0x10D5634
#define pinstCHotButtonWnd2_x                                      0x10D5638
#define pinstCHotButtonWnd3_x                                      0x10D563C
#define pinstCHotButtonWnd4_x                                      0x10D5660
#define pinstCItemDisplayManager_x                                 0x10D5AB8
#define pinstCItemExpTransferWnd_x                                 0x10D5BB4
#define pinstCLFGuildWnd_x                                         0x10D5E90
#define pinstCMIZoneSelectWnd_x                                    0x10D6470
#define pinstCConfirmationDialog_x                                 0x10D6B78
#define pinstCPopupWndManager_x                                    0x10D6B78
#define pinstCProgressionSelectionWnd_x                            0x10D6C68
#define pinstCPvPStatsWnd_x                                        0x10D6D58
#define pinstCTaskWnd_x                                            0x10D8860
#define pinstCTaskSomething_x                                      0xD4B5D8
#define pinstCTaskTemplateSelectWnd_x                              0x10D87E8
#define pinstCTipWndOFDAY_x                                        0x10D89C8
#define pinstCTipWndCONTEXT_x                                      0x10D89CC
#define pinstCTitleWnd_x                                           0x10D8A48
#define pinstCContextMenuManager_x                                 0x173ED48
#define pinstCVoiceMacroWnd_x                                      0xFC4EA8
#define pinstCHtmlWnd_x                                            0xFC4F98
#define pinstItemIconCache_x                                       0x10D2D60
#define pinstCTradeskillWnd_x                                      0x10D8B48
#define pinstCAdvancedLootWnd_x                                    0xE7D570
#define pinstRewardSelectionWnd_x                                  0x10D7280
#define pinstEQSuiteTextureLoader_x                                0xD287B0
#define pinstCPointMerchantWnd_x                                   0x10D6B00

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x54B8D0
#define __CastRay2_x                                               0x54B200
#define __HeadingDiff_x                                            0x939BB0
#define __FixHeading_x                                             0x939B40
#define __get_bearing_x                                            0x53AF10
#define __ConvertItemTags_x                                        0x5389E0
#define __ExecuteCmd_x                                             0x5232A0
#define __EQGetTime_x                                              0x8A9330
#define __get_melee_range_x                                        0x529F60
#define __GetGaugeValueFromEQ_x                                    0x7B8DB0
#define __GetLabelFromEQ_x                                         0x7BA180
#define __ToggleKeyRingItem_x                                      0x490C70
#define __GetXTargetType_x                                         0x93B7B0
#define __LoadFrontEnd_x                                           0x641DE0
#define __NewUIINI_x                                               0x7B8780
#define __ProcessGameEvents_x                                      0x5856F0
#define __ProcessMouseEvent_x                                      0x584E90
#define CrashDetected_x                                            0x6437A0
#define wwsCrashReportCheckForUploader_x                           0x806FE0
#define __AppCrashWrapper_x                                        0xC73E5C
#define __pCrashHandler_x                                          0x10E5A28
#define __CrashHandler_x                                           0x806A40
#define wwsCrashReportPlatformLaunchUploader_x                     0x8091E0
#define DrawNetStatus_x                                            0x5BC240
#define Util__FastTime_x                                           0x8A8FD0
#define Expansion_HoT_x                                            0xF3F588
#define __HelpPath_x                                               0xFC2E28
#define __STMLToText_x                                             0x8EF6C0
#define __GetAnimationCache_x                                      0x6B13F0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423310
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DFC0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DD90

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D91D0
#define AltAdvManager__IsAbilityReady_x                            0x4D9240
#define AltAdvManager__GetAAById_x                                 0x4D9730
#define AltAdvManager__CanTrainAbility_x                           0x4DA360
#define AltAdvManager__CanSeeAbility_x                             0x4D9F20

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46AAF0
#define CharacterZoneClient__HasSkill_x                            0x4663C0
#define CharacterZoneClient__MakeMeVisible_x                       0x46C660
#define CharacterZoneClient__IsStackBlocked_x                      0x44C030
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B4F0
#define CharacterZoneClient__GetItemCountWorn_x                    0x464920
#define CharacterZoneClient__GetItemCountInInventory_x             0x464A00
#define CharacterZoneClient__GetCursorItemCount_x                  0x464AE0
#define CharacterZoneClient__FindAffectSlot_x                      0x451660
#define CharacterZoneClient__BardCastBard_x                        0x44AC70
#define CharacterZoneClient__GetMaxEffects_x                       0x449800
#define CharacterZoneClient__GetEffect_x                           0x44B720
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4514C0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449B50
#define CharacterZoneClient__GetLastEffectSlot_x                   0x450010

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x671670

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67F6A0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x59AF60
#define CButtonWnd__CButtonWnd_x                                   0x8E3970

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x69A5E0
#define CChatManager__InitContextMenu_x                            0x69B730
#define CChatManager__FreeChatWindow_x                             0x69A090
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A3880
#define CChatManager__SetLockedActiveChatWindow_x                  0x69A5B0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8EDA10
#define CContextMenu__dCContextMenu_x                              0x8EDC20
#define CContextMenu__AddMenuItem_x                                0x8EE140
#define CContextMenu__RemoveMenuItem_x                             0x8EDDA0
#define CContextMenu__RemoveAllMenuItems_x                         0x8EDDC0
#define CContextMenu__CheckMenuItem_x                              0x8EDE40

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D9FC0
#define CContextMenuManager__RemoveMenu_x                          0x8DA340
#define CContextMenuManager__PopupMenu_x                           0x8DA790
#define CContextMenuManager__Flush_x                               0x8DA030
#define CContextMenuManager__GetMenu_x                             0x419530

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x88D460
#define CChatService__GetFriendName_x                              0x88D470

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6A1370
#define CChatWindow__Clear_x                                       0x6A0C50
#define CChatWindow__WndNotification_x                             0x6A1C70

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8DDDF0
#define CComboWnd__Draw_x                                          0x8DE000
#define CComboWnd__GetCurChoice_x                                  0x8DDBA0
#define CComboWnd__GetListRect_x                                   0x8DE2A0
#define CComboWnd__GetTextRect_x                                   0x8DDE60
#define CComboWnd__InsertChoice_x                                  0x8DE400
#define CComboWnd__SetColors_x                                     0x8DDB30
#define CComboWnd__SetChoice_x                                     0x8DDB60
#define CComboWnd__GetItemCount_x                                  0x8DDB90
#define CComboWnd__GetCurChoiceText_x                              0x8DDBE0


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6AB590
#define CContainerWnd__vftable_x                                   0xAF5C78

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C6EF0
#define CDisplay__GetClickedActor_x                                0x4BF7B0
#define CDisplay__GetUserDefinedColor_x                            0x4BE390
#define CDisplay__GetWorldFilePath_x                               0x4BD7E0
#define CDisplay__is3dON_x                                         0x4BCC70
#define CDisplay__ReloadUI_x                                       0x4D0ED0
#define CDisplay__WriteTextHD2_x                                   0x4C3280
#define CDisplay__TrueDistance_x                                   0x4C03E0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x904CF0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8F1F70
#define CEditWnd__GetCharIndexPt_x                                 0x8F30D0
#define CEditWnd__GetDisplayString_x                               0x8F2120
#define CEditWnd__GetHorzOffset_x                                  0x8F2460
#define CEditWnd__GetLineForPrintableChar_x                        0x8F2B90
#define CEditWnd__GetSelStartPt_x                                  0x8F3390
#define CEditWnd__GetSTMLSafeText_x                                0x8F2600
#define CEditWnd__PointFromPrintableChar_x                         0x8F2C80
#define CEditWnd__SelectableCharFromPoint_x                        0x8F2E00
#define CEditWnd__SetEditable_x                                    0x8F25D0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56BD60
#define CEverQuest__ClickedPlayer_x                                0x5658E0
#define CEverQuest__CreateTargetIndicator_x                        0x5667E0
#define CEverQuest__DeleteTargetIndicator_x                        0x566860
#define CEverQuest__DoTellWindow_x                                 0x477260
#define CEverQuest__OutputTextToLog_x                              0x476EC0
#define CEverQuest__DropHeldItemOnGround_x                         0x57C2D0
#define CEverQuest__dsp_chat_x                                     0x4775A0
#define CEverQuest__trimName_x                                     0x5621F0
#define CEverQuest__Emote_x                                        0x57A5E0
#define CEverQuest__EnterZone_x                                    0x5756C0
#define CEverQuest__GetBodyTypeDesc_x                              0x55FC30
#define CEverQuest__GetClassDesc_x                                 0x569180
#define CEverQuest__GetClassThreeLetterCode_x                      0x569780
#define CEverQuest__GetDeityDesc_x                                 0x560510
#define CEverQuest__GetLangDesc_x                                  0x55FFC0
#define CEverQuest__GetRaceDesc_x                                  0x569940
#define CEverQuest__InterpretCmd_x                                 0x56D4E0
#define CEverQuest__LeftClickedOnPlayer_x                          0x581E30
#define CEverQuest__LMouseUp_x                                     0x583EB0
#define CEverQuest__RightClickedOnPlayer_x                         0x582940
#define CEverQuest__RMouseUp_x                                     0x583910
#define CEverQuest__SetGameState_x                                 0x5661B0
#define CEverQuest__UPCNotificationFlush_x                         0x55E5C0
#define CEverQuest__IssuePetCommand_x                              0x56DEC0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BC1E0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BC240
#define CGaugeWnd__Draw_x                                          0x6BC670

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B560
#define CGuild__GetGuildName_x                                     0x43BA30
#define CGuild__GetGuildIndex_x                                    0x43CC40

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D86B0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E5B20
#define CInvSlotMgr__MoveItem_x                                    0x6E62E0
#define CInvSlotMgr__SelectSlot_x                                  0x6E5410

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E4870
#define CInvSlot__SliderComplete_x                                 0x6E2000
#define CInvSlot__GetItemBase_x                                    0x6E1460
#define CInvSlot__UpdateItem_x                                     0x6E19E0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E7740
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E8870

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7B4C90
#define CItemDisplayWnd__UpdateStrings_x                           0x6E9980
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F6600
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F6B30
#define CItemDisplayWnd__SetItem_x                                 0x6FC4C0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7EBCA0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EFFA0

// CLabel 
#define CLabel__Draw_x                                             0x7032F0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C99F0
#define CListWnd__dCListWnd_x                                      0x8CAC80
#define CListWnd__AddColumn_x                                      0x8CAC20
#define CListWnd__AddColumn1_x                                     0x8CA2C0
#define CListWnd__AddLine_x                                        0x8C9CA0
#define CListWnd__AddString_x                                      0x8C9EC0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C6AF0
#define CListWnd__CalculateVSBRange_x                              0x8C8EB0
#define CListWnd__ClearSel_x                                       0x8C5E10
#define CListWnd__ClearAllSel_x                                    0x8C5DC0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C9880
#define CListWnd__Compare_x                                        0x8C77E0
#define CListWnd__Draw_x                                           0x8C8AB0
#define CListWnd__DrawColumnSeparators_x                           0x8C8940
#define CListWnd__DrawHeader_x                                     0x8C60D0
#define CListWnd__DrawItem_x                                       0x8C7E70
#define CListWnd__DrawLine_x                                       0x8C85E0
#define CListWnd__DrawSeparator_x                                  0x8C89E0
#define CListWnd__EnableLine_x                                     0x8C5FF0
#define CListWnd__EnsureVisible_x                                  0x8C6C50
#define CListWnd__ExtendSel_x                                      0x8C7D80
#define CListWnd__GetColumnMinWidth_x                              0x8C5700
#define CListWnd__GetColumnWidth_x                                 0x8C5630
#define CListWnd__GetCurSel_x                                      0x8C4E00
#define CListWnd__GetItemAtPoint_x                                 0x8C6EF0
#define CListWnd__GetItemAtPoint1_x                                0x8C6F60
#define CListWnd__GetItemData_x                                    0x8C5140
#define CListWnd__GetItemHeight_x                                  0x8C6750
#define CListWnd__GetItemIcon_x                                    0x8C5330
#define CListWnd__GetItemRect_x                                    0x8C6D30
#define CListWnd__GetItemText_x                                    0x8C51E0
#define CListWnd__GetSelList_x                                     0x8CA1B0
#define CListWnd__GetSeparatorRect_x                               0x8C7700
#define CListWnd__InsertLine_x                                     0x8CA0A0
#define CListWnd__RemoveLine_x                                     0x8CA0B0
#define CListWnd__SetColors_x                                      0x8C4F50
#define CListWnd__SetColumnJustification_x                         0x8C5990
#define CListWnd__SetColumnWidth_x                                 0x8C56B0
#define CListWnd__SetCurSel_x                                      0x8C4E40
#define CListWnd__SetItemColor_x                                   0x8C9570
#define CListWnd__SetItemData_x                                    0x8C5E70
#define CListWnd__SetItemText_x                                    0x8C93B0
#define CListWnd__ShiftColumnSeparator_x                           0x8C9240
#define CListWnd__Sort_x                                           0x8CAD80
#define CListWnd__ToggleSel_x                                      0x8C5D40

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71C3F0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73F6B0
#define CMerchantWnd__RequestBuyItem_x                             0x7472B0
#define CMerchantWnd__RequestSellItem_x                            0x748880
#define CMerchantWnd__SelectRecoverySlot_x                         0x73FB50
#define CMerchantWnd__SelectBuySellSlot_x                          0x73CF90
#define CMerchantWnd__ActualSelect_x                               0x7402C0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x85B7A0
#define CPacketScrambler__hton_x                                   0x85B7B0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E8930
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E8A10
#define CSidlManager__CreateLabel_x                                0x7A9CF0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E6ED0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E8CF0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8DFE20
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8DFD10
#define CSidlScreenWnd__ConvertToRes_x                             0x904BD0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8E0730
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8E18D0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8E1980
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8E0E80
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8E00E0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8DF840
#define CSidlScreenWnd__GetSidlPiece_x                             0x8E02D0
#define CSidlScreenWnd__Init1_x                                    0x8E15D0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8E07E0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8DFA00
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8E10C0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8DF4A0
#define CSidlScreenWnd__StoreIniVis_x                              0x8DF7F0
#define CSidlScreenWnd__WndNotification_x                          0x8E1350
#define CSidlScreenWnd__GetChildItem_x                             0x8DF910
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8D31E0
#define CSidlScreenWnd__m_layoutCopy_x                             0x173EE68

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x607830
#define CSkillMgr__GetSkillCap_x                                   0x607A10
#define CSkillMgr__GetNameToken_x                                  0x6073E0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x903E90
#define CSliderWnd__SetValue_x                                     0x904060
#define CSliderWnd__SetNumTicks_x                                  0x9047E0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7AFFD0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8FDA00
#define CStmlWnd__CalculateHSBRange_x                              0x8F5F60
#define CStmlWnd__CalculateVSBRange_x                              0x8F5ED0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F60E0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F68E0
#define CStmlWnd__ForceParseNow_x                                  0x8FE380
#define CStmlWnd__GetNextTagPiece_x                                0x8F67E0
#define CStmlWnd__GetSTMLText_x                                    0x485450
#define CStmlWnd__GetVisibleText_x                                 0x8F7330
#define CStmlWnd__InitializeWindowVariables_x                      0x8F9900
#define CStmlWnd__MakeStmlColorTag_x                               0x8F51B0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8F5210
#define CStmlWnd__SetSTMLText_x                                    0x8FB150
#define CStmlWnd__StripFirstSTMLLines_x                            0x8FD6A0
#define CStmlWnd__UpdateHistoryString_x                            0x8F8270

// CTabWnd 
#define CTabWnd__Draw_x                                            0x901890
#define CTabWnd__DrawCurrentPage_x                                 0x901120
#define CTabWnd__DrawTab_x                                         0x900EE0
#define CTabWnd__GetCurrentPage_x                                  0x9014D0
#define CTabWnd__GetPageInnerRect_x                                0x900BD0
#define CTabWnd__GetTabInnerRect_x                                 0x900DD0
#define CTabWnd__GetTabRect_x                                      0x900CA0
#define CTabWnd__InsertPage_x                                      0x901B80
#define CTabWnd__SetPage_x                                         0x901500
#define CTabWnd__SetPageRect_x                                     0x9017D0
#define CTabWnd__UpdatePage_x                                      0x901B20
#define CTabWnd__GetPageFromTabIndex_x                             0x900E30
#define CTabWnd__GetCurrentTabIndex_x                              0x900B60

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E8A20
#define CPageWnd__SetTabText_x                                     0x90DF20

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x437120

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8DD7A0
#define CTextureFont__GetTextExtent_x                              0x8DD500

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x640080

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x90A360

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8C2F10

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029D0
#define CXStr__CXStr1_x                                            0x403770
#define CXStr__CXStr3_x                                            0x8A6260
#define CXStr__dCXStr_x                                            0x4DAE00
#define CXStr__operator_equal_x                                    0x8A63D0
#define CXStr__operator_equal1_x                                   0x8A6420
#define CXStr__operator_plus_equal1_x                              0x8A7520

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8DB2A0
#define CXWnd__BringToTop_x                                        0x8D23E0
#define CXWnd__Center_x                                            0x8D8600
#define CXWnd__ClrFocus_x                                          0x8D1FA0
#define CXWnd__Destroy_x                                           0x8D90D0
#define CXWnd__DoAllDrawing_x                                      0x8D8250
#define CXWnd__DrawChildren_x                                      0x8D83F0
#define CXWnd__DrawColoredRect_x                                   0x8D27C0
#define CXWnd__DrawTooltip_x                                       0x8D2A70
#define CXWnd__DrawTooltipAtPoint_x                                0x8D71C0
#define CXWnd__GetBorderFrame_x                                    0x8D2ED0
#define CXWnd__GetChildWndAt_x                                     0x8D8FC0
#define CXWnd__GetClientClipRect_x                                 0x8D2C90
#define CXWnd__GetScreenClipRect_x                                 0x8D78C0
#define CXWnd__GetScreenRect_x                                     0x8D3080
#define CXWnd__GetTooltipRect_x                                    0x8D2900
#define CXWnd__GetWindowTextA_x                                    0x427420
#define CXWnd__IsActive_x                                          0x8CDA20
#define CXWnd__IsDescendantOf_x                                    0x8D2E20
#define CXWnd__IsReallyVisible_x                                   0x8D61E0
#define CXWnd__IsType_x                                            0x8D8670
#define CScreenPieceTemplate__IsType_x                             0x906A70
#define CXWnd__Move_x                                              0x8D58E0
#define CXWnd__Move1_x                                             0x8D7EF0
#define CXWnd__ProcessTransition_x                                 0x8D2380
#define CXWnd__Refade_x                                            0x8D2150
#define CXWnd__Resize_x                                            0x8D3140
#define CXWnd__Right_x                                             0x8D76C0
#define CXWnd__SetFocus_x                                          0x8D4A40
#define CXWnd__SetFont_x                                           0x8D1FF0
#define CXWnd__SetKeyTooltip_x                                     0x8D33B0
#define CXWnd__SetMouseOver_x                                      0x8D7BE0
#define CXWnd__StartFade_x                                         0x8D2430
#define CXWnd__GetChildItem_x                                      0x8D7B30
#define CXWnd__SetParent_x                                         0x8D8F70

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8CF2C0
#define CXWndManager__DrawWindows_x                                0x8CEF10
#define CXWndManager__GetKeyboardFlags_x                           0x8CD590
#define CXWndManager__HandleKeyboardMsg_x                          0x8CDEB0
#define CXWndManager__RemoveWnd_x                                  0x8CDBB0

// CDBStr
#define CDBStr__GetString_x                                        0x4BB4D0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452820
#define EQ_Character__Cur_HP_x                                     0x465FA0
#define EQ_Character__Cur_Mana_x                                   0x45AEC0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B800
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4438D0
#define EQ_Character__GetFocusRangeModifier_x                      0x443930
#define EQ_Character__GetHPRegen_x                                 0x46A180
#define EQ_Character__GetEnduranceRegen_x                          0x4655B0
#define EQ_Character__GetManaRegen_x                               0x46A720
#define EQ_Character__Max_Endurance_x                              0x5CE180
#define EQ_Character__Max_HP_x                                     0x45DA40
#define EQ_Character__Max_Mana_x                                   0x5CDFB0
#define EQ_Character__doCombatAbility_x                            0x5CB680
#define EQ_Character__UseSkill_x                                   0x4716F0
#define EQ_Character__GetConLevel_x                                0x5C0820
#define EQ_Character__IsExpansionFlag_x                            0x426950
#define EQ_Character__TotalEffect_x                                0x44F950
#define EQ_Character__GetPCSpellAffect_x                           0x44BC00
#define EQ_Character__SpellDuration_x                              0x449BA0
#define EQ_Character__FindItemByRecord_x                           0x4635F0
#define EQ_Character__GetAdjustedSkill_x                           0x466170
#define EQ_Character__GetBaseSkill_x                               0x45D920

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x879670

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D66D0

//PcClient
#define PcClient__PcClient_x                                       0x5C2660

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446C70
#define CCharacterSelect__EnterWorld_x                             0x446440
#define CCharacterSelect__Quit_x                                   0x445000

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5A0890
#define EQ_Item__CreateItemTagString_x                             0x859940
#define EQ_Item__IsStackable_x                                     0x84ECA0
#define EQ_Item__GetImageNum_x                                     0x851750
#define EQ_Item__CreateItemClient_x                                0x5A1890
#define EQ_Item__GetItemValue_x                                    0x858390
#define EQ_Item__ValueSellMerchant_x                               0x85B3F0
#define EQ_Item__IsKeyRingItem_x                                   0x84F740
#define EQ_Item__CanGoInBag_x                                      0x5A0A20
#define EQ_Item__GetMaxItemCount_x                                 0x84EB90
#define EQ_Item__GetHeldItem_x                                     0x850570
#define EQ_Item__GetAugmentFitBySlot_x                             0x85B210

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DB790
#define EQ_LoadingS__Array_x                                       0xC15958

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5D0690
#define EQ_PC__GetAlternateAbilityId_x                             0x863830
#define EQ_PC__GetCombatAbility_x                                  0x8638C0
#define EQ_PC__GetCombatAbilityTimer_x                             0x85E450
#define EQ_PC__GetItemRecastTimer_x                                0x5C9E30
#define EQ_PC__HasLoreItem_x                                       0x5C3E20
#define EQ_PC__AlertInventoryChanged_x                             0x5C07D0
#define EQ_PC__GetPcZoneClient_x                                   0x5EAC30
#define EQ_PC__RemoveMyAffect_x                                    0x5C9290
#define EQ_PC__GetKeyRingItems_x                                   0x85E870
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x871560
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8657D0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x527FF0
#define EQItemList__add_object_x                                   0x555470
#define EQItemList__add_item_x                                     0x527F30
#define EQItemList__delete_item_x                                  0x5283E0
#define EQItemList__FreeItemList_x                                 0x5282E0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4BA7C0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D6470
#define EQPlayer__dEQPlayer_x                                      0x5DEAC0
#define EQPlayer__DoAttack_x                                       0x5F05B0
#define EQPlayer__EQPlayer_x                                       0x5E11F0
#define EQPlayer__SetNameSpriteState_x                             0x5DB980
#define EQPlayer__SetNameSpriteTint_x                              0x5D7890
#define PlayerBase__HasProperty_j_x                                0x937F60
#define EQPlayer__IsTargetable_x                                   0x938200
#define EQPlayer__CanSee_x                                         0x938760
#define PlayerZoneClient__ChangeHeight_x                           0x5F0470
#define EQPlayer__CanSee1_x                                        0x938850
#define PlayerBase__GetVisibilityLineSegment_x                     0x9384F0

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5EADE0
#define PlayerZoneClient__IsValidTeleport_x                        0x555D10
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D3AD0


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E5250
#define EQPlayerManager__GetSpawnByName_x                          0x5E56B0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E5280

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A6DF0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A6E30
#define KeypressHandler__ClearCommandStateArray_x                  0x5A69E0
#define KeypressHandler__HandleKeyDown_x                           0x5A5300
#define KeypressHandler__HandleKeyUp_x                             0x5A5620
#define KeypressHandler__SaveKeymapping_x                          0x5A6AB0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x714D80
#define MapViewMap__SaveEx_x                                       0x7180B0

#define PlayerPointManager__GetAltCurrency_x                       0x877680

// StringTable 
#define StringTable__getString_x                                   0x871890

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CDC10
#define PcZoneClient__RemovePetEffect_x                            0x5CA300
#define PcZoneClient__HasAlternateAbility_x                        0x5CACA0
#define PcZoneClient__GetCurrentMod_x                              0x45CEF0
#define PcZoneClient__GetModCap_x                                  0x45A620
#define PcZoneClient__CanEquipItem_x                               0x5CB1C0
#define PcZoneClient__GetItemByID_x                                0x5CFA10
#define PcZoneClient__GetItemByItemClass_x                         0x5D05B0
#define PcZoneClient__RemoveBuffEffect_x                           0x5C9540

//Doors
#define EQSwitch__UseSwitch_x                                      0x55CE50

//IconCache
#define IconCache__GetIcon_x                                       0x6B1A20

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A8940
#define CContainerMgr__CloseContainer_x                            0x6A9160

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x779B60

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x599990

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F5BB0
#define EQ_Spell__SpellAffects_x                                   0x4F2DD0
#define EQ_Spell__SpellAffectBase_x                           0x4F2E40
#define CharacterZoneClient__CalcAffectChange_x                    0x44BA90
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44ACD0
#define CLootWnd__LootAll_x                                        0x70A6A0
#define CLootWnd__RequestLootSlot_x                                0x70AEB0
#define EQ_Spell__IsStackable_x                                    0x4495B0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449660
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43F0C0
#define EQ_Spell__IsSPAStacking_x                                  0x4F2940
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F39B0
#define EQ_Spell__IsNoRemove_x                                     0x435170
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F2960

#define __IsResEffectSpell_x                                       0x4496F0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8832F0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7C1860
#define CTargetWnd__WndNotification_x                              0x7C1350
#define CTargetWnd__RefreshTargetBuffs_x                           0x7C1A40

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C6990

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4EE520
#define EqSoundManager__PlayScriptMp3_x                            0x4EFFC0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A9970

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8F15A0
#define CSidlManager__FindAnimation1_x                             0x8E6900

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E2FD0
#define CAltAbilityData__GetMercMaxRank_x                          0x4E2F80
#define CAltAbilityData__GetMaxRank_x                              0x4D7880

//CTargetRing
#define CTargetRing__Cast_x                                        0x597230

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459630
#define CharacterBase__CreateItemGlobalIndex_x                     0x476470
#define CharacterBase__CreateItemIndex_x                           0x5215E0
#define CharacterBase__GetItemPossession_x                         0x4444D0
#define CharacterBase__GetItemByGlobalIndex_x                      0x887150
#define CharacterBase__GetEffectId_x                               0x4595F0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6917F0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x690F50

//messages
#define msg_spell_worn_off_x                                       0x4FD770
#define msg_new_text_x                                             0x506E20
#define msgTokenTextParam_x                                        0x503600

//SpellManager
#define SpellManager__vftable_x                                    0xAD1408
#define SpellManager__SpellManager_x                               0x47F0D0
#define Spellmanager__LoadTextSpells_x          0x60E6C0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x93C2D0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x488CC0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EFD0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449360
#define ItemGlobalIndex__IsValidIndex_x                            0x458EB0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x884FB0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x883EF0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x703540

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AD650
#define CCursorAttachment__Deactivate_x                            0x6ACBA0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x903390
#define CEQSuiteTextureLoader__GetTexture_x                        0x903510

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                                0x606390

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                                0x48D530
