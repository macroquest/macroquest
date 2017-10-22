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
#define __ExpectedVersionDate                                     "Oct 21 2017"
#define __ExpectedVersionTime                                     "04:18:53"
#define __ActualVersionDate_x                                      0xAEC3A8
#define __ActualVersionTime_x                                      0xAEC3B4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5AD7A0
#define __MemChecker1_x                                            0x8A9C00
#define __MemChecker2_x                                            0x6439A0
#define __MemChecker3_x                                            0x6438F0
#define __MemChecker4_x                                            0x7FB420
#define __EncryptPad0_x                                            0xC4A6A0
#define __EncryptPad1_x                                            0xD268E8
#define __EncryptPad2_x                                            0xC74268
#define __EncryptPad3_x                                            0xC73E68
#define __EncryptPad4_x                                            0xD14EE8
#define __EncryptPad5_x                                            0x10D0218
#define __AC1_x                                                    0x7BA725
#define __AC2_x                                                    0x5661A7
#define __AC3_x                                                    0x564320
#define __AC4_x                                                    0x576541
#define __AC5_x                                                    0x58A36B
#define __AC6_x                                                    0x58DF2E
#define __AC7_x                                                    0x58496C
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
#define __do_loot_x                                                0x534DC0
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
#define __CastRay_x                                                0x54C8D0
#define __CastRay2_x                                               0x54C200
#define __HeadingDiff_x                                            0x939C90
#define __FixHeading_x                                             0x939C20
#define __get_bearing_x                                            0x53BF10
#define __ConvertItemTags_x                                        0x5399E0
#define __ExecuteCmd_x                                             0x524280
#define __EQGetTime_x                                              0x8A95A0
#define __get_melee_range_x                                        0x52AF60
#define __GetGaugeValueFromEQ_x                                    0x7B92E0
#define __GetLabelFromEQ_x                                         0x7BA6B0
#define __ToggleKeyRingItem_x                                      0x491060
#define __GetXTargetType_x                                         0x93B890
#define __LoadFrontEnd_x                                           0x643070
#define __NewUIINI_x                                               0x7B8CB0
#define __ProcessGameEvents_x                                      0x586700
#define __ProcessMouseEvent_x                                      0x585EA0
#define CrashDetected_x                                            0x644A30
#define wwsCrashReportCheckForUploader_x                           0x807400
#define __AppCrashWrapper_x                                        0xC73E5C
#define __pCrashHandler_x                                          0x10E5A28
#define __CrashHandler_x                                           0x806E90
#define wwsCrashReportPlatformLaunchUploader_x                     0x809640
#define DrawNetStatus_x                                            0x5BD510
#define Util__FastTime_x                                           0x8A9240
#define Expansion_HoT_x                                            0xF3F588
#define __HelpPath_x                                               0xFC2E28
#define __STMLToText_x                                             0x8EFC40
#define __GetAnimationCache_x                                      0x6B2830

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423360
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DFF0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DDC0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D96D0
#define AltAdvManager__IsAbilityReady_x                            0x4D9740
#define AltAdvManager__GetAAById_x                                 0x4D9C30
#define AltAdvManager__CanTrainAbility_x                           0x4DA860
#define AltAdvManager__CanSeeAbility_x                             0x4DA420

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46AD80
#define CharacterZoneClient__HasSkill_x                            0x466650
#define CharacterZoneClient__MakeMeVisible_x                       0x46C8F0
#define CharacterZoneClient__IsStackBlocked_x                      0x44C260
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B720
#define CharacterZoneClient__GetItemCountWorn_x                    0x464BB0
#define CharacterZoneClient__GetItemCountInInventory_x             0x464C90
#define CharacterZoneClient__GetCursorItemCount_x                  0x464D70
#define CharacterZoneClient__FindAffectSlot_x                      0x451890
#define CharacterZoneClient__BardCastBard_x                        0x44AEA0
#define CharacterZoneClient__GetMaxEffects_x                       0x449A30
#define CharacterZoneClient__GetEffect_x                           0x44B950
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4516F0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449D80
#define CharacterZoneClient__GetLastEffectSlot_x                   0x450240

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x672A50

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x680890

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x59C010
#define CButtonWnd__CButtonWnd_x                                   0x8E3D70

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x69BA10
#define CChatManager__InitContextMenu_x                            0x69CB60
#define CChatManager__FreeChatWindow_x                             0x69B4C0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A4CA0
#define CChatManager__SetLockedActiveChatWindow_x                  0x69B9E0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8EDF90
#define CContextMenu__dCContextMenu_x                              0x8EE1A0
#define CContextMenu__AddMenuItem_x                                0x8EE6C0
#define CContextMenu__RemoveMenuItem_x                             0x8EE320
#define CContextMenu__RemoveAllMenuItems_x                         0x8EE340
#define CContextMenu__CheckMenuItem_x                              0x8EE3C0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8DA320
#define CContextMenuManager__RemoveMenu_x                          0x8DA6C0
#define CContextMenuManager__PopupMenu_x                           0x8DAB10
#define CContextMenuManager__Flush_x                               0x8DA390
#define CContextMenuManager__GetMenu_x                             0x419560

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x88D7A0
#define CChatService__GetFriendName_x                              0x88D7B0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6A2790
#define CChatWindow__Clear_x                                       0x6A2070
#define CChatWindow__WndNotification_x                             0x6A3090

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8DE160
#define CComboWnd__Draw_x                                          0x8DE370
#define CComboWnd__GetCurChoice_x                                  0x8DDF10
#define CComboWnd__GetListRect_x                                   0x8DE610
#define CComboWnd__GetTextRect_x                                   0x8DE1D0
#define CComboWnd__InsertChoice_x                                  0x8DE770
#define CComboWnd__SetColors_x                                     0x8DDEA0
#define CComboWnd__SetChoice_x                                     0x8DDED0
#define CComboWnd__GetItemCount_x                                  0x8DDF00
#define CComboWnd__GetCurChoiceText_x                              0x8DDF50


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6AC9D0
#define CContainerWnd__vftable_x                                   0xAF5CB8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C7400
#define CDisplay__GetClickedActor_x                                0x4BFCC0
#define CDisplay__GetUserDefinedColor_x                            0x4BE8A0
#define CDisplay__GetWorldFilePath_x                               0x4BDCF0
#define CDisplay__is3dON_x                                         0x4BD180
#define CDisplay__ReloadUI_x                                       0x4D13E0
#define CDisplay__WriteTextHD2_x                                   0x4C3790
#define CDisplay__TrueDistance_x                                   0x4C08F0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x905060

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8F24F0
#define CEditWnd__GetCharIndexPt_x                                 0x8F3640
#define CEditWnd__GetDisplayString_x                               0x8F26A0
#define CEditWnd__GetHorzOffset_x                                  0x8F29E0
#define CEditWnd__GetLineForPrintableChar_x                        0x8F3110
#define CEditWnd__GetSelStartPt_x                                  0x8F38F0
#define CEditWnd__GetSTMLSafeText_x                                0x8F2B80
#define CEditWnd__PointFromPrintableChar_x                         0x8F3200
#define CEditWnd__SelectableCharFromPoint_x                        0x8F3380
#define CEditWnd__SetEditable_x                                    0x8F2B50

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56CD70
#define CEverQuest__ClickedPlayer_x                                0x5668F0
#define CEverQuest__CreateTargetIndicator_x                        0x5677F0
#define CEverQuest__DeleteTargetIndicator_x                        0x567870
#define CEverQuest__DoTellWindow_x                                 0x4774D0
#define CEverQuest__OutputTextToLog_x                              0x477130
#define CEverQuest__DropHeldItemOnGround_x                         0x57D2E0
#define CEverQuest__dsp_chat_x                                     0x477810
#define CEverQuest__trimName_x                                     0x563200
#define CEverQuest__Emote_x                                        0x57B5F0
#define CEverQuest__EnterZone_x                                    0x5766D0
#define CEverQuest__GetBodyTypeDesc_x                              0x560C40
#define CEverQuest__GetClassDesc_x                                 0x56A190
#define CEverQuest__GetClassThreeLetterCode_x                      0x56A790
#define CEverQuest__GetDeityDesc_x                                 0x561520
#define CEverQuest__GetLangDesc_x                                  0x560FD0
#define CEverQuest__GetRaceDesc_x                                  0x56A950
#define CEverQuest__InterpretCmd_x                                 0x56E4F0
#define CEverQuest__LeftClickedOnPlayer_x                          0x582E40
#define CEverQuest__LMouseUp_x                                     0x584EC0
#define CEverQuest__RightClickedOnPlayer_x                         0x583950
#define CEverQuest__RMouseUp_x                                     0x584920
#define CEverQuest__SetGameState_x                                 0x5671C0
#define CEverQuest__UPCNotificationFlush_x                         0x55F5D0
#define CEverQuest__IssuePetCommand_x                              0x56EED0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BD650
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BD6B0
#define CGaugeWnd__Draw_x                                          0x6BDAE0

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B820
#define CGuild__GetGuildName_x                                     0x43BCF0
#define CGuild__GetGuildIndex_x                                    0x43CF00

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D9BF0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E7040
#define CInvSlotMgr__MoveItem_x                                    0x6E7800
#define CInvSlotMgr__SelectSlot_x                                  0x6E6930

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E5D90
#define CInvSlot__SliderComplete_x                                 0x6E3520
#define CInvSlot__GetItemBase_x                                    0x6E29A0
#define CInvSlot__UpdateItem_x                                     0x6E2F20

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E8C60
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E9DA0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7B4D10
#define CItemDisplayWnd__UpdateStrings_x                           0x6EAEC0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F7B30
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F8040
#define CItemDisplayWnd__SetItem_x                                 0x6FD920

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7EC2F0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6F14C0

// CLabel 
#define CLabel__Draw_x                                             0x7046D0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C9C70
#define CListWnd__dCListWnd_x                                      0x8CAF30
#define CListWnd__AddColumn_x                                      0x8CAED0
#define CListWnd__AddColumn1_x                                     0x8CA560
#define CListWnd__AddLine_x                                        0x8C9F40
#define CListWnd__AddString_x                                      0x8CA160
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C6D70
#define CListWnd__CalculateVSBRange_x                              0x8C9130
#define CListWnd__ClearSel_x                                       0x8C6080
#define CListWnd__ClearAllSel_x                                    0x8C6030
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C9B00
#define CListWnd__Compare_x                                        0x8C7A70
#define CListWnd__Draw_x                                           0x8C8D30
#define CListWnd__DrawColumnSeparators_x                           0x8C8BC0
#define CListWnd__DrawHeader_x                                     0x8C6340
#define CListWnd__DrawItem_x                                       0x8C80F0
#define CListWnd__DrawLine_x                                       0x8C8860
#define CListWnd__DrawSeparator_x                                  0x8C8C60
#define CListWnd__EnableLine_x                                     0x8C6260
#define CListWnd__EnsureVisible_x                                  0x8C6ED0
#define CListWnd__ExtendSel_x                                      0x8C8000
#define CListWnd__GetColumnMinWidth_x                              0x8C5970
#define CListWnd__GetColumnWidth_x                                 0x8C58A0
#define CListWnd__GetCurSel_x                                      0x8C5070
#define CListWnd__GetItemAtPoint_x                                 0x8C7170
#define CListWnd__GetItemAtPoint1_x                                0x8C71E0
#define CListWnd__GetItemData_x                                    0x8C53B0
#define CListWnd__GetItemHeight_x                                  0x8C69C0
#define CListWnd__GetItemIcon_x                                    0x8C55A0
#define CListWnd__GetItemRect_x                                    0x8C6FB0
#define CListWnd__GetItemText_x                                    0x8C5450
#define CListWnd__GetSelList_x                                     0x8CA450
#define CListWnd__GetSeparatorRect_x                               0x8C7990
#define CListWnd__InsertLine_x                                     0x8CA340
#define CListWnd__RemoveLine_x                                     0x8CA350
#define CListWnd__SetColors_x                                      0x8C51C0
#define CListWnd__SetColumnJustification_x                         0x8C5C00
#define CListWnd__SetColumnWidth_x                                 0x8C5920
#define CListWnd__SetCurSel_x                                      0x8C50B0
#define CListWnd__SetItemColor_x                                   0x8C97F0
#define CListWnd__SetItemData_x                                    0x8C60E0
#define CListWnd__SetItemText_x                                    0x8C9630
#define CListWnd__ShiftColumnSeparator_x                           0x8C94C0
#define CListWnd__Sort_x                                           0x8CB030
#define CListWnd__ToggleSel_x                                      0x8C5FB0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71D7C0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x740920
#define CMerchantWnd__RequestBuyItem_x                             0x748500
#define CMerchantWnd__RequestSellItem_x                            0x749AD0
#define CMerchantWnd__SelectRecoverySlot_x                         0x740DC0
#define CMerchantWnd__SelectBuySellSlot_x                          0x73E210
#define CMerchantWnd__ActualSelect_x                               0x741530

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x85BAD0
#define CPacketScrambler__hton_x                                   0x85BAE0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E8D80
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E8E60
#define CSidlManager__CreateLabel_x                                0x7AACE0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E7320
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E9140

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8E01C0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8E00C0
#define CSidlScreenWnd__ConvertToRes_x                             0x904F40
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8E0AD0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8E1CB0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8E1D60
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8E1230
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8E0480
#define CSidlScreenWnd__EnableIniStorage_x                         0x8DFBF0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8E0670
#define CSidlScreenWnd__Init1_x                                    0x8E1980
#define CSidlScreenWnd__LoadIniInfo_x                              0x8E0B80
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8DFDB0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8E1470
#define CSidlScreenWnd__StoreIniInfo_x                             0x8DF840
#define CSidlScreenWnd__StoreIniVis_x                              0x8DFBA0
#define CSidlScreenWnd__WndNotification_x                          0x8E1700
#define CSidlScreenWnd__GetChildItem_x                             0x8DFCC0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8D3530
#define CSidlScreenWnd__m_layoutCopy_x                             0x173EE68

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x608A40
#define CSkillMgr__GetSkillCap_x                                   0x608C20
#define CSkillMgr__GetNameToken_x                                  0x6085F0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x904200
#define CSliderWnd__SetValue_x                                     0x9043D0
#define CSliderWnd__SetNumTicks_x                                  0x904B50

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7B0FE0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8FDF80
#define CStmlWnd__CalculateHSBRange_x                              0x8F64C0
#define CStmlWnd__CalculateVSBRange_x                              0x8F6430
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F6640
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F6E40
#define CStmlWnd__ForceParseNow_x                                  0x8FE900
#define CStmlWnd__GetNextTagPiece_x                                0x8F6D40
#define CStmlWnd__GetSTMLText_x                                    0x4856B0
#define CStmlWnd__GetVisibleText_x                                 0x8F7890
#define CStmlWnd__InitializeWindowVariables_x                      0x8F9E60
#define CStmlWnd__MakeStmlColorTag_x                               0x8F5710
#define CStmlWnd__MakeWndNotificationTag_x                         0x8F5770
#define CStmlWnd__SetSTMLText_x                                    0x8FB6C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8FDC20
#define CStmlWnd__UpdateHistoryString_x                            0x8F87D0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x901E10
#define CTabWnd__DrawCurrentPage_x                                 0x9016A0
#define CTabWnd__DrawTab_x                                         0x901460
#define CTabWnd__GetCurrentPage_x                                  0x901A50
#define CTabWnd__GetPageInnerRect_x                                0x901150
#define CTabWnd__GetTabInnerRect_x                                 0x901350
#define CTabWnd__GetTabRect_x                                      0x901220
#define CTabWnd__InsertPage_x                                      0x902100
#define CTabWnd__SetPage_x                                         0x901A80
#define CTabWnd__SetPageRect_x                                     0x901D50
#define CTabWnd__UpdatePage_x                                      0x9020A0
#define CTabWnd__GetPageFromTabIndex_x                             0x9013B0
#define CTabWnd__GetCurrentTabIndex_x                              0x9010E0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E9F50
#define CPageWnd__SetTabText_x                                     0x90E280

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x437380

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8DDB10
#define CTextureFont__GetTextExtent_x                              0x8DD870

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6412F0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x90A6C0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8C3110

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5A9BD0
#define CXStr__CXStr1_x                                            0x7F44E0
#define CXStr__CXStr3_x                                            0x8A6490
#define CXStr__dCXStr_x                                            0x8D2030
#define CXStr__operator_equal_x                                    0x8A6600
#define CXStr__operator_equal1_x                                   0x8A6650
#define CXStr__operator_plus_equal1_x                              0x8A7750

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8DB620
#define CXWnd__BringToTop_x                                        0x8D2730
#define CXWnd__Center_x                                            0x8D8900
#define CXWnd__ClrFocus_x                                          0x8D2320
#define CXWnd__Destroy_x                                           0x8D93E0
#define CXWnd__DoAllDrawing_x                                      0x8D8550
#define CXWnd__DrawChildren_x                                      0x8D86F0
#define CXWnd__DrawColoredRect_x                                   0x8D2B10
#define CXWnd__DrawTooltip_x                                       0x8D2DC0
#define CXWnd__DrawTooltipAtPoint_x                                0x8D74E0
#define CXWnd__GetBorderFrame_x                                    0x8D3220
#define CXWnd__GetChildWndAt_x                                     0x8D92D0
#define CXWnd__GetClientClipRect_x                                 0x8D2FE0
#define CXWnd__GetScreenClipRect_x                                 0x8D7BE0
#define CXWnd__GetScreenRect_x                                     0x8D33D0
#define CXWnd__GetTooltipRect_x                                    0x8D2C50
#define CXWnd__GetWindowTextA_x                                    0x427380
#define CXWnd__IsActive_x                                          0x8CDCE0
#define CXWnd__IsDescendantOf_x                                    0x8D3170
#define CXWnd__IsReallyVisible_x                                   0x8D6500
#define CXWnd__IsType_x                                            0x8D8970
#define CScreenPieceTemplate__IsType_x                             0x906DD0
#define CXWnd__Move_x                                              0x8D5BE0
#define CXWnd__Move1_x                                             0x8D8210
#define CXWnd__ProcessTransition_x                                 0x8D26E0
#define CXWnd__Refade_x                                            0x8D24C0
#define CXWnd__Resize_x                                            0x8D3490
#define CXWnd__Right_x                                             0x8D79E0
#define CXWnd__SetFocus_x                                          0x8D4D40
#define CXWnd__SetFont_x                                           0x8D2370
#define CXWnd__SetKeyTooltip_x                                     0x8D3700
#define CXWnd__SetMouseOver_x                                      0x8D7F00
#define CXWnd__StartFade_x                                         0x8D2780
#define CXWnd__GetChildItem_x                                      0x8D7E40
#define CXWnd__SetParent_x                                         0x8D9280

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8CF580
#define CXWndManager__DrawWindows_x                                0x8CF1D0
#define CXWndManager__GetKeyboardFlags_x                           0x8CD850
#define CXWndManager__HandleKeyboardMsg_x                          0x8CE170
#define CXWndManager__RemoveWnd_x                                  0x8CDE70

// CDBStr
#define CDBStr__GetString_x                                        0x4BB9B0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452A50
#define EQ_Character__Cur_HP_x                                     0x466230
#define EQ_Character__Cur_Mana_x                                   0x45B180
#define EQ_Character__GetAACastingTimeModifier_x                   0x44BA30
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443AF0
#define EQ_Character__GetFocusRangeModifier_x                      0x443B50
#define EQ_Character__GetHPRegen_x                                 0x46A410
#define EQ_Character__GetEnduranceRegen_x                          0x465840
#define EQ_Character__GetManaRegen_x                               0x46A9B0
#define EQ_Character__Max_Endurance_x                              0x5CF430
#define EQ_Character__Max_HP_x                                     0x45DD00
#define EQ_Character__Max_Mana_x                                   0x5CF260
#define EQ_Character__doCombatAbility_x                            0x5CC930
#define EQ_Character__UseSkill_x                                   0x471980
#define EQ_Character__GetConLevel_x                                0x5C1B80
#define EQ_Character__IsExpansionFlag_x                            0x4268B0
#define EQ_Character__TotalEffect_x                                0x44FB80
#define EQ_Character__GetPCSpellAffect_x                           0x44BE30
#define EQ_Character__SpellDuration_x                              0x449DD0
#define EQ_Character__FindItemByRecord_x                           0x4638A0
#define EQ_Character__GetAdjustedSkill_x                           0x466400
#define EQ_Character__GetBaseSkill_x                               0x45DBE0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8798B0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D79D0

//PcClient
#define PcClient__PcClient_x                                       0x5C39C0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446E90
#define CCharacterSelect__EnterWorld_x                             0x446660
#define CCharacterSelect__Quit_x                                   0x445220

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5A1950
#define EQ_Item__CreateItemTagString_x                             0x859C90
#define EQ_Item__IsStackable_x                                     0x84EF60
#define EQ_Item__GetImageNum_x                                     0x851A10
#define EQ_Item__CreateItemClient_x                                0x5A2960
#define EQ_Item__GetItemValue_x                                    0x858660
#define EQ_Item__ValueSellMerchant_x                               0x85B760
#define EQ_Item__IsKeyRingItem_x                                   0x84FA20
#define EQ_Item__CanGoInBag_x                                      0x5A1AE0
#define EQ_Item__GetMaxItemCount_x                                 0x84EE50
#define EQ_Item__GetHeldItem_x                                     0x850810
#define EQ_Item__GetAugmentFitBySlot_x                             0x85B580

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DBC80
#define EQ_LoadingS__Array_x                                       0xC15958

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5D1950
#define EQ_PC__GetAlternateAbilityId_x                             0x863BC0
#define EQ_PC__GetCombatAbility_x                                  0x863C50
#define EQ_PC__GetCombatAbilityTimer_x                             0x85E780
#define EQ_PC__GetItemRecastTimer_x                                0x5CB0E0
#define EQ_PC__HasLoreItem_x                                       0x5C5180
#define EQ_PC__AlertInventoryChanged_x                             0x5C1B30
#define EQ_PC__GetPcZoneClient_x                                   0x5EBF60
#define EQ_PC__RemoveMyAffect_x                                    0x5CA540
#define EQ_PC__GetKeyRingItems_x                                   0x85EBA0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8718A0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x865B30

// EQItemList 
#define EQItemList__EQItemList_x                                   0x528FE0
#define EQItemList__add_object_x                                   0x556540
#define EQItemList__add_item_x                                     0x528F20
#define EQItemList__delete_item_x                                  0x5293D0
#define EQItemList__FreeItemList_x                                 0x5292D0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4BACA0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D7770
#define EQPlayer__dEQPlayer_x                                      0x5DFDB0
#define EQPlayer__DoAttack_x                                       0x5F18E0
#define EQPlayer__EQPlayer_x                                       0x5E24D0
#define EQPlayer__SetNameSpriteState_x                             0x5DCC70
#define EQPlayer__SetNameSpriteTint_x                              0x5D8B90
#define PlayerBase__HasProperty_j_x                                0x9380A0
#define EQPlayer__IsTargetable_x                                   0x938340
#define EQPlayer__CanSee_x                                         0x9388A0
#define PlayerZoneClient__ChangeHeight_x                           0x5F17A0
#define EQPlayer__CanSee1_x                                        0x938990
#define PlayerBase__GetVisibilityLineSegment_x                     0x938630

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5EC110
#define PlayerZoneClient__IsValidTeleport_x                        0x556DE0
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D3FE0


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E65A0
#define EQPlayerManager__GetSpawnByName_x                          0x5E6A00
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E65D0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A7F60
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A7FA0
#define KeypressHandler__ClearCommandStateArray_x                  0x5A7B50
#define KeypressHandler__HandleKeyDown_x                           0x5A6470
#define KeypressHandler__HandleKeyUp_x                             0x5A6790
#define KeypressHandler__SaveKeymapping_x                          0x5A7C20

// MapViewMap 
#define MapViewMap__Clear_x                                        0x716150
#define MapViewMap__SaveEx_x                                       0x719480

#define PlayerPointManager__GetAltCurrency_x                       0x877960

// StringTable 
#define StringTable__getString_x                                   0x871BD0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CEEC0
#define PcZoneClient__RemovePetEffect_x                            0x5CB5B0
#define PcZoneClient__HasAlternateAbility_x                        0x5CBF50
#define PcZoneClient__GetCurrentMod_x                              0x45D1B0
#define PcZoneClient__GetModCap_x                                  0x45A8E0
#define PcZoneClient__CanEquipItem_x                               0x5CC470
#define PcZoneClient__GetItemByID_x                                0x5D0CC0
#define PcZoneClient__GetItemByItemClass_x                         0x5D1870
#define PcZoneClient__RemoveBuffEffect_x                           0x5CA7F0

//Doors
#define EQSwitch__UseSwitch_x                                      0x55DF10

//IconCache
#define IconCache__GetIcon_x                                       0x6B2E60

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A9D70
#define CContainerMgr__CloseContainer_x                            0x6AA590

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x77AB80

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x59AA40

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F60C0
#define EQ_Spell__SpellAffects_x                                   0x4F32E0
#define EQ_Spell__SpellAffectBase_x                           0x4F3350
#define CharacterZoneClient__CalcAffectChange_x                    0x44BCC0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AF00
#define CLootWnd__LootAll_x                                        0x70BAD0
#define CLootWnd__RequestLootSlot_x                                0x70C2E0
#define EQ_Spell__IsStackable_x                                    0x4497F0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4498A0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43F2F0
#define EQ_Spell__IsSPAStacking_x                                  0x4F2E50
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F3EC0
#define EQ_Spell__IsNoRemove_x                                     0x4353A0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F2E70

#define __IsResEffectSpell_x                                       0x449920

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x883530

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7C1D20
#define CTargetWnd__WndNotification_x                              0x7C1810
#define CTargetWnd__RefreshTargetBuffs_x                           0x7C1F00

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C6E40

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4EEA30
#define EqSoundManager__PlayScriptMp3_x                            0x4F04D0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A9D00

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8F1B20
#define CSidlManager__FindAnimation1_x                             0x8E6D50

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E3520
#define CAltAbilityData__GetMercMaxRank_x                          0x4E34D0
#define CAltAbilityData__GetMaxRank_x                              0x4D7D80

//CTargetRing
#define CTargetRing__Cast_x                                        0x5982F0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459860
#define CharacterBase__CreateItemGlobalIndex_x                     0x476700
#define CharacterBase__CreateItemIndex_x                           0x5225F0
#define CharacterBase__GetItemPossession_x                         0x4446F0
#define CharacterBase__GetItemByGlobalIndex_x                      0x887390
#define CharacterBase__GetEffectId_x                               0x459820

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x692C00
#define CCastSpellWnd__IsBardSongPlaying_x                         0x692360

//messages
#define msg_spell_worn_off_x                                       0x4FDB90
#define msg_new_text_x                                             0x507240
#define msgTokenTextParam_x                                        0x503A20

//SpellManager
#define SpellManager__vftable_x                                    0xAD1400
#define SpellManager__SpellManager_x                               0x47F300
#define Spellmanager__LoadTextSpells_x          0x60F9D0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x93C3B0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4890F0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43F220
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449580
#define ItemGlobalIndex__IsValidIndex_x                            0x4590E0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8851F0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x884130

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x704920

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AEA90
#define CCursorAttachment__Deactivate_x                            0x6ADFE0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x903700
#define CEQSuiteTextureLoader__GetTexture_x                        0x903880

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                                0x607640

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                                0x48D980
