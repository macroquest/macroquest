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
#define __ExpectedVersionDate                                     "Dec  9 2017"
#define __ExpectedVersionTime                                     "04:17:23"
#define __ActualVersionDate_x                                      0xAE4098
#define __ActualVersionTime_x                                      0xAE40A4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5AA060
#define __MemChecker1_x                                            0x8A2D70
#define __MemChecker2_x                                            0x63FDB0
#define __MemChecker3_x                                            0x63FD00
#define __MemChecker4_x                                            0x7F4C50
#define __EncryptPad0_x                                            0xC3EFE8
#define __EncryptPad1_x                                            0xD18BA0
#define __EncryptPad2_x                                            0xC67ED0
#define __EncryptPad3_x                                            0xC67AD0
#define __EncryptPad4_x                                            0xD071A0
#define __EncryptPad5_x                                            0x10C22E0
#define __AC1_x                                                    0x7B3985
#define __AC2_x                                                    0x563257
#define __AC3_x                                                    0x5613D0
#define __AC4_x                                                    0x5735A1
#define __AC5_x                                                    0x5872FB
#define __AC6_x                                                    0x58AEAE
#define __AC7_x                                                    0x5818FC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FA4EE0

// Direct Input
#define DI8__Main_x                                                0x10C22B8
#define DI8__Keyboard_x                                            0x10C22BC
#define DI8__Mouse_x                                               0x10C22C0
#define DI8__Mouse_Copy_x                                          0xF30474
#define DI8__Mouse_Check_x                                         0xFB9FA4
#define __AutoSkillArray_x                                         0xF31388
#define __Attack_x                                                 0xFB4A7B
#define __Autofire_x                                               0xFB4A7C
#define __BindList_x                                               0xC1B368
#define g_eqCommandStates_x                                        0xF1F1C0
#define __Clicks_x                                                 0xF30530
#define __CommandList_x                                            0xC1DA80
#define __CurrentMapLabel_x                                        0x10C82B0
#define __CurrentSocial_x                                          0xBEA8E8
#define __DoAbilityList_x                                          0xF66C40
#define __do_loot_x                                                0x532270
#define __DrawHandler_x                                            0x1731F2C
#define __GroupCount_x                                             0xF20ACA

#define __Guilds_x                                                 0xF266E0
#define __gWorld_x                                                 0xF22F84
#define __HotkeyPage_x                                             0xFAD640
#define __HWnd_x                                                   0xFBA0C0
#define __InChatMode_x                                             0xF3045C
#define __LastTell_x                                               0xF3233C
#define __LMouseHeldTime_x                                         0xF3059C
#define __Mouse_x                                                  0x10C22C4
#define __MouseLook_x                                              0xF304F6
#define __MouseEventTime_x                                         0xFB5214
#define __gpbCommandEvent_x                                        0xF2304C
#define __NetStatusToggle_x                                        0xF304F9
#define __PCNames_x                                                0xF31944
#define __RangeAttackReady_x                                       0xF3166C
#define __RMouseHeldTime_x                                         0xF30598
#define __RunWalkState_x                                           0xF30460
#define __ScreenMode_x                                             0xE6EDA0
#define __ScreenX_x                                                0xF30414
#define __ScreenY_x                                                0xF30410
#define __ScreenXMax_x                                             0xF30418
#define __ScreenYMax_x                                             0xF3041C
#define __ServerHost_x                                             0xF20A14
#define __ServerName_x                                             0xF66C00
#define __ShiftKeyDown_x                                           0xF30AF0
#define __ShowNames_x                                              0xF31824
#define __Socials_x                                                0xF66D00
#define __SubscriptionType_x                                       0x10F8A34
#define __TargetAggroHolder_x                                      0x10CA40C
#define __ZoneType_x                                               0xF308F4
#define __GroupAggro_x                                             0x10CA44C
#define __LoginName_x                                              0xFB8B9C
#define __Inviter_x                                                0xFB49F8
#define __AttackOnAssist_x                                         0xF317E0
#define __UseTellWindows_x                                         0xF31ADC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF23070
#define instEQZoneInfo_x                                           0xF306EC
#define instKeypressHandler_x                                      0xFB51F8
#define pinstActiveBanker_x                                        0xF23028
#define pinstActiveCorpse_x                                        0xF2302C
#define pinstActiveGMaster_x                                       0xF23030
#define pinstActiveMerchant_x                                      0xF23024
#define pinstAggroInfo_x                                           0xD2C40C
#define pinstAltAdvManager_x                                       0xE6FF08
#define pinstAuraMgr_x                                             0xD3CC10
#define pinstBandageTarget_x                                       0xF23010
#define pinstCamActor_x                                            0xE6F7D8
#define pinstCDBStr_x                                              0xE6ED34
#define pinstCDisplay_x                                            0xF23038
#define pinstCEverQuest_x                                          0x10C2438
#define pinstEverQuestInfo_x                                       0xF30408
#define pinstCharData_x                                            0xF22FF4
#define pinstCharSpawn_x                                           0xF2301C
#define pinstControlledMissile_x                                   0xF22FF0
#define pinstControlledPlayer_x                                    0xF2301C
#define pinstCSidlManager_x                                        0x1730E98
#define pinstCXWndManager_x                                        0x1730E90
#define instDynamicZone_x                                          0xF302A8
#define pinstDZMember_x                                            0xF303B8
#define pinstDZTimerInfo_x                                         0xF303BC
#define pinstEQItemList_x                                          0xF1F498
#define pinstEQObjectList_x                                        0xF204C4
#define instEQMisc_x                                               0xC037A8
#define pinstEQSoundManager_x                                      0xE704D8
#define instExpeditionLeader_x                                     0xF302F2
#define instExpeditionName_x                                       0xF30332
#define pinstGroup_x                                               0xF20AC6
#define pinstImeManager_x                                          0x1730E9C
#define pinstLocalPlayer_x                                         0xF23008
#define pinstMercenaryData_x                                       0xFB5860
#define pinstMercenaryStats_x                                      0x10CA558
#define pinstMercAltAbilities_x                                    0xE70290
#define pinstModelPlayer_x                                         0xF23034
#define pinstPCData_x                                              0xF22FF4
#define pinstSkillMgr_x                                            0xFB6858
#define pinstSpawnManager_x                                        0xFB60B0
#define pinstSpellManager_x                                        0xFB69A0
#define pinstSpellSets_x                                           0xFAD6A4
#define pinstStringTable_x                                         0xF22F9C
#define pinstSwitchManager_x                                       0xF20658
#define pinstTarget_x                                              0xF23020
#define pinstTargetObject_x                                        0xF22FF8
#define pinstTargetSwitch_x                                        0xF22FFC
#define pinstTaskMember_x                                          0xE6EC80
#define pinstTrackTarget_x                                         0xF23014
#define pinstTradeTarget_x                                         0xF23004
#define instTributeActive_x                                        0xC037CD
#define pinstViewActor_x                                           0xE6F7D4
#define pinstWorldData_x                                           0xF22FD8
#define pinstZoneAddr_x                                            0xF3098C
#define pinstPlayerPath_x                                          0xFB6110
#define pinstTargetIndicator_x                                     0xFB6B38
#define pinstCTargetManager_x                                      0xFB6B98
#define EQObject_Top_x                                             0xF22FE8
#define pinstRealEstateItems_x                                     0xFB66C4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE6F6F0
#define pinstCAchievementsWnd_x                                    0xE6F74C
#define pinstCTextOverlay_x                                        0xD2C9A0
#define pinstCAudioTriggersWindow_x                                0xD2C788
#define pinstCCharacterSelect_x                                    0xE6F65C
#define pinstCFacePick_x                                           0xE6F40C
#define pinstCFindItemWnd_x                                        0xE6F6EC
#define pinstCNoteWnd_x                                            0xE6F614
#define pinstCBookWnd_x                                            0xE6F61C
#define pinstCPetInfoWnd_x                                         0xE6F620
#define pinstCTrainWnd_x                                           0xE6F624
#define pinstCSkillsWnd_x                                          0xE6F628
#define pinstCSkillsSelectWnd_x                                    0xE6F62C
#define pinstCCombatSkillsSelectWnd_x                              0xE6F630
#define pinstCFriendsWnd_x                                         0xE6F634
#define pinstCAuraWnd_x                                            0xE6F638
#define pinstCRespawnWnd_x                                         0xE6F63C
#define pinstCBandolierWnd_x                                       0xE6F640
#define pinstCPotionBeltWnd_x                                      0xE6F644
#define pinstCAAWnd_x                                              0xE6F648
#define pinstCAlarmWnd_x                                           0xE6F654
#define pinstCGroupSearchFiltersWnd_x                              0xE6F64C
#define pinstCLoadskinWnd_x                                        0xE6F650
#define pinstCLargeDialogWnd_x                                     0x10C94B8
#define pinstCMusicPlayerWnd_x                                     0xE6F658
#define pinstCMailWnd_x                                            0xE6F660
#define pinstCMailCompositionWnd_x                                 0xE6F664
#define pinstCMailAddressBookWnd_x                                 0xE6F668
#define pinstCRaidWnd_x                                            0xE6F670
#define pinstCRaidOptionsWnd_x                                     0xE6F674
#define pinstCBreathWnd_x                                          0xE6F678
#define pinstCMapViewWnd_x                                         0xE6F67C
#define pinstCMapToolbarWnd_x                                      0xE6F680
#define pinstCEditLabelWnd_x                                       0xE6F684
#define pinstCTargetWnd_x                                          0xE6F688
#define pinstCColorPickerWnd_x                                     0xE6F68C
#define pinstCPlayerWnd_x                                          0xE6F690
#define pinstCOptionsWnd_x                                         0xE6F694
#define pinstCBuffWindowNORMAL_x                                   0xE6F698
#define pinstCBuffWindowSHORT_x                                    0xE6F69C
#define pinstCharacterCreation_x                                   0xE6F6A0
#define pinstCCursorAttachment_x                                   0xE6F6A4
#define pinstCCastingWnd_x                                         0xE6F6A8
#define pinstCCastSpellWnd_x                                       0xE6F6AC
#define pinstCSpellBookWnd_x                                       0xE6F6B0
#define pinstCInventoryWnd_x                                       0xE6F6B4
#define pinstCBankWnd_x                                            0xE6F6BC
#define pinstCQuantityWnd_x                                        0xE6F6C0
#define pinstCLootWnd_x                                            0xE6F6C4
#define pinstCActionsWnd_x                                         0xE6F6C8
#define pinstCCombatAbilityWnd_x                                   0xE6F6D0
#define pinstCMerchantWnd_x                                        0xE6F6D4
#define pinstCTradeWnd_x                                           0xE6F6DC
#define pinstCSelectorWnd_x                                        0xE6F6E0
#define pinstCBazaarWnd_x                                          0xE6F6E4
#define pinstCBazaarSearchWnd_x                                    0xE6F6E8
#define pinstCGiveWnd_x                                            0xE6F708
#define pinstCTrackingWnd_x                                        0xE6F710
#define pinstCInspectWnd_x                                         0xE6F714
#define pinstCSocialEditWnd_x                                      0xE6F718
#define pinstCFeedbackWnd_x                                        0xE6F71C
#define pinstCBugReportWnd_x                                       0xE6F720
#define pinstCVideoModesWnd_x                                      0xE6F724
#define pinstCTextEntryWnd_x                                       0xE6F72C
#define pinstCFileSelectionWnd_x                                   0xE6F730
#define pinstCCompassWnd_x                                         0xE6F734
#define pinstCPlayerNotesWnd_x                                     0xE6F738
#define pinstCGemsGameWnd_x                                        0xE6F73C
#define pinstCTimeLeftWnd_x                                        0xE6F758
#define pinstCPetitionQWnd_x                                       0xE6F75C
#define pinstCStoryWnd_x                                           0xE6F760
#define pinstCJournalTextWnd_x                                     0xE6F764
#define pinstCJournalCatWnd_x                                      0xE6F768
#define pinstCBodyTintWnd_x                                        0xE6F76C
#define pinstCServerListWnd_x                                      0xE6F770
#define pinstCAvaZoneWnd_x                                         0xE6F77C
#define pinstCBlockedBuffWnd_x                                     0xE6F780
#define pinstCBlockedPetBuffWnd_x                                  0xE6F784
#define pinstCInvSlotMgr_x                                         0xE6F7CC
#define pinstCContainerMgr_x                                       0xE6F7D0
#define pinstCAdventureLeaderboardWnd_x                            0x10C2DE8
#define pinstCAdventureRequestWnd_x                                0x10C2E60
#define pinstCAltStorageWnd_x                                      0x10C3140
#define pinstCAdventureStatsWnd_x                                  0x10C2ED8
#define pinstCBarterMerchantWnd_x                                  0x10C3E88
#define pinstCBarterSearchWnd_x                                    0x10C3F00
#define pinstCBarterWnd_x                                          0x10C3F78
#define pinstCChatWindowManager_x                                  0x10C4788
#define pinstCDynamicZoneWnd_x                                     0x10C4CB8
#define pinstCEQMainWnd_x                                          0x10C4E80
#define pinstCFellowshipWnd_x                                      0x10C4C4C
#define pinstCFindLocationWnd_x                                    0x10C5150
#define pinstCGroupSearchWnd_x                                     0x10C5420
#define pinstCGroupWnd_x                                           0x10C5498
#define pinstCGuildBankWnd_x                                       0x10C5510
#define pinstCGuildMgmtWnd_x                                       0x10C7600
#define pinstCHotButtonWnd_x                                       0x10C76FC
#define pinstCHotButtonWnd1_x                                      0x10C76FC
#define pinstCHotButtonWnd2_x                                      0x10C7700
#define pinstCHotButtonWnd3_x                                      0x10C7704
#define pinstCHotButtonWnd4_x                                      0x10C7728
#define pinstCItemDisplayManager_x                                 0x10C7B80
#define pinstCItemExpTransferWnd_x                                 0x10C7C7C
#define pinstCLFGuildWnd_x                                         0x10C7F58
#define pinstCMIZoneSelectWnd_x                                    0x10C8538
#define pinstCConfirmationDialog_x                                 0x10C8B50
#define pinstCPopupWndManager_x                                    0x10C8B50
#define pinstCProgressionSelectionWnd_x                            0x10C8C40
#define pinstCPvPStatsWnd_x                                        0x10C8D30
#define pinstCTaskWnd_x                                            0x10CA838
#define pinstCTaskSomething_x                                      0xD3D828
#define pinstCTaskTemplateSelectWnd_x                              0x10CA7C0
#define pinstCTipWndOFDAY_x                                        0x10CA9A0
#define pinstCTipWndCONTEXT_x                                      0x10CA9A4
#define pinstCTitleWnd_x                                           0x10CAA20
#define pinstCContextMenuManager_x                                 0x1730D20
#define pinstCVoiceMacroWnd_x                                      0xFB6F70
#define pinstCHtmlWnd_x                                            0xFB7060
#define pinstItemIconCache_x                                       0x10C4E28
#define pinstCTradeskillWnd_x                                      0x10CAB20
#define pinstCAdvancedLootWnd_x                                    0xE6F7C0
#define pinstRewardSelectionWnd_x                                  0x10C9258
#define pinstEQSuiteTextureLoader_x                                0xD1AA88

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x549B20
#define __CastRay2_x                                               0x549450
#define __HeadingDiff_x                                            0x933430
#define __FixHeading_x                                             0x9333C0
#define __get_bearing_x                                            0x5393C0
#define __ConvertItemTags_x                                        0x536E90
#define __ExecuteCmd_x                                             0x521760
#define __EQGetTime_x                                              0x8A2710
#define __get_melee_range_x                                        0x528430
#define __GetGaugeValueFromEQ_x                                    0x7B2540
#define __GetLabelFromEQ_x                                         0x7B3910
#define __ToggleKeyRingItem_x                                      0x48FB70
#define __GetXTargetType_x                                         0x9350A0
#define __LoadFrontEnd_x                                           0x63F480
#define __NewUIINI_x                                               0x7B1F10
#define __ProcessGameEvents_x                                      0x583690
#define __ProcessMouseEvent_x                                      0x582E30
#define CrashDetected_x                                            0x640E40
#define wwsCrashReportCheckForUploader_x                           0x800630
#define __AppCrashWrapper_x                                        0xC67AC4
#define __pCrashHandler_x                                          0x10D7A00
#define __CrashHandler_x                                           0x8000C0
#define wwsCrashReportPlatformLaunchUploader_x                     0x802860
#define DrawNetStatus_x                                            0x5B9D40
#define Util__FastTime_x                                           0x8A23B0
#define Expansion_HoT_x                                            0xF317D0
#define __HelpPath_x                                               0xFB4F80
#define __STMLToText_x                                             0x8E8D50
#define __GetAnimationCache_x                                      0x6AEB50

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4233F0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41E060
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DE30

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D8030
#define AltAdvManager__IsAbilityReady_x                            0x4D80A0
#define AltAdvManager__GetAAById_x                                 0x4D8590
#define AltAdvManager__CanTrainAbility_x                           0x4D91C0
#define AltAdvManager__CanSeeAbility_x                             0x4D8D80

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46AF00
#define CharacterZoneClient__HasSkill_x                            0x466E10
#define CharacterZoneClient__MakeMeVisible_x                       0x46CA70
#define CharacterZoneClient__IsStackBlocked_x                      0x44BE70
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B390
#define CharacterZoneClient__GetItemCountWorn_x                    0x465370
#define CharacterZoneClient__GetItemCountInInventory_x             0x465450
#define CharacterZoneClient__GetCursorItemCount_x                  0x465530
#define CharacterZoneClient__FindAffectSlot_x                      0x451520
#define CharacterZoneClient__BardCastBard_x                        0x44AB00
#define CharacterZoneClient__GetMaxEffects_x                       0x449690
#define CharacterZoneClient__GetEffect_x                           0x44B5C0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451380
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4499E0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FED0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66EDC0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67CD50

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5987B0
#define CButtonWnd__CButtonWnd_x                                   0x8DCFB0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x697CF0
#define CChatManager__InitContextMenu_x                            0x698E40
#define CChatManager__FreeChatWindow_x                             0x6977A0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A0FE0
#define CChatManager__SetLockedActiveChatWindow_x                  0x697CC0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E70A0
#define CContextMenu__dCContextMenu_x                              0x8E72B0
#define CContextMenu__AddMenuItem_x                                0x8E77D0
#define CContextMenu__RemoveMenuItem_x                             0x8E7430
#define CContextMenu__RemoveAllMenuItems_x                         0x8E7450
#define CContextMenu__CheckMenuItem_x                              0x8E74D0
#define CContextMenu__SetMenuItem_x                                0x8E7350

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D3560
#define CContextMenuManager__RemoveMenu_x                          0x8D38F0
#define CContextMenuManager__PopupMenu_x                           0x8D3D40
#define CContextMenuManager__Flush_x                               0x8D35D0
#define CContextMenuManager__GetMenu_x                             0x419530

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x886890
#define CChatService__GetFriendName_x                              0x8868A0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69EAB0
#define CChatWindow__Clear_x                                       0x69E390
#define CChatWindow__WndNotification_x                             0x69F3C0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D73B0
#define CComboWnd__Draw_x                                          0x8D75C0
#define CComboWnd__GetCurChoice_x                                  0x8D7160
#define CComboWnd__GetListRect_x                                   0x8D7860
#define CComboWnd__GetTextRect_x                                   0x8D7420
#define CComboWnd__InsertChoice_x                                  0x8D79C0
#define CComboWnd__SetColors_x                                     0x8D70F0
#define CComboWnd__SetChoice_x                                     0x8D7120
#define CComboWnd__GetItemCount_x                                  0x8D7150
#define CComboWnd__GetCurChoiceText_x                              0x8D71A0


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A8CE0
#define CContainerWnd__vftable_x                                   0xAED9B0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C5E10
#define CDisplay__GetClickedActor_x                                0x4BE6D0
#define CDisplay__GetUserDefinedColor_x                            0x4BD2B0
#define CDisplay__GetWorldFilePath_x                               0x4BC700
#define CDisplay__is3dON_x                                         0x4BBB90
#define CDisplay__ReloadUI_x                                       0x4CFBD0
#define CDisplay__WriteTextHD2_x                                   0x4C21A0
#define CDisplay__TrueDistance_x                                   0x4BF300

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FE190

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EB600
#define CEditWnd__GetCharIndexPt_x                                 0x8EC760
#define CEditWnd__GetDisplayString_x                               0x8EB7B0
#define CEditWnd__GetHorzOffset_x                                  0x8EBAF0
#define CEditWnd__GetLineForPrintableChar_x                        0x8EC220
#define CEditWnd__GetSelStartPt_x                                  0x8ECA20
#define CEditWnd__GetSTMLSafeText_x                                0x8EBC90
#define CEditWnd__PointFromPrintableChar_x                         0x8EC310
#define CEditWnd__SelectableCharFromPoint_x                        0x8EC490
#define CEditWnd__SetEditable_x                                    0x8EBC60

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x569DD0
#define CEverQuest__ClickedPlayer_x                                0x5639A0
#define CEverQuest__CreateTargetIndicator_x                        0x5648A0
#define CEverQuest__DeleteTargetIndicator_x                        0x564920
#define CEverQuest__DoTellWindow_x                                 0x476130
#define CEverQuest__OutputTextToLog_x                              0x475D90
#define CEverQuest__DropHeldItemOnGround_x                         0x57A340
#define CEverQuest__dsp_chat_x                                     0x476470
#define CEverQuest__trimName_x                                     0x5602B0
#define CEverQuest__Emote_x                                        0x578650
#define CEverQuest__EnterZone_x                                    0x573730
#define CEverQuest__GetBodyTypeDesc_x                              0x55DCF0
#define CEverQuest__GetClassDesc_x                                 0x5671E0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5677E0
#define CEverQuest__GetDeityDesc_x                                 0x55E5D0
#define CEverQuest__GetLangDesc_x                                  0x55E080
#define CEverQuest__GetRaceDesc_x                                  0x5679A0
#define CEverQuest__InterpretCmd_x                                 0x56B550
#define CEverQuest__LeftClickedOnPlayer_x                          0x57FEA0
#define CEverQuest__LMouseUp_x                                     0x581E50
#define CEverQuest__RightClickedOnPlayer_x                         0x5809B0
#define CEverQuest__RMouseUp_x                                     0x5818B0
#define CEverQuest__SetGameState_x                                 0x564270
#define CEverQuest__UPCNotificationFlush_x                         0x55C680
#define CEverQuest__IssuePetCommand_x                              0x56BF30

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B98D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B9930
#define CGaugeWnd__Draw_x                                          0x6B9D60

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B100
#define CGuild__GetGuildName_x                                     0x43B5D0
#define CGuild__GetGuildIndex_x                                    0x43C7E0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D5DE0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E31B0
#define CInvSlotMgr__MoveItem_x                                    0x6E3970
#define CInvSlotMgr__SelectSlot_x                                  0x6E2AA0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E1EF0
#define CInvSlot__SliderComplete_x                                 0x6DF710
#define CInvSlot__GetItemBase_x                                    0x6DEB90
#define CInvSlot__UpdateItem_x                                     0x6DF110

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E4DD0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E5F00

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AE3B0
#define CItemDisplayWnd__UpdateStrings_x                           0x6E7020
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F38D0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F3E00
#define CItemDisplayWnd__SetItem_x                                 0x6F9750

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E5420

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6ED5D0

// CLabel 
#define CLabel__Draw_x                                             0x7005E0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C2EF0
#define CListWnd__dCListWnd_x                                      0x8C41A0
#define CListWnd__AddColumn_x                                      0x8C4140
#define CListWnd__AddColumn1_x                                     0x8C37E0
#define CListWnd__AddLine_x                                        0x8C31C0
#define CListWnd__AddString_x                                      0x8C33E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BFFF0
#define CListWnd__CalculateVSBRange_x                              0x8C23B0
#define CListWnd__ClearSel_x                                       0x8BF310
#define CListWnd__ClearAllSel_x                                    0x8BF2C0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C2D80
#define CListWnd__Compare_x                                        0x8C0CE0
#define CListWnd__Draw_x                                           0x8C1FB0
#define CListWnd__DrawColumnSeparators_x                           0x8C1E40
#define CListWnd__DrawHeader_x                                     0x8BF5D0
#define CListWnd__DrawItem_x                                       0x8C1370
#define CListWnd__DrawLine_x                                       0x8C1AE0
#define CListWnd__DrawSeparator_x                                  0x8C1EE0
#define CListWnd__EnableLine_x                                     0x8BF4F0
#define CListWnd__EnsureVisible_x                                  0x8C0150
#define CListWnd__ExtendSel_x                                      0x8C1280
#define CListWnd__GetColumnMinWidth_x                              0x8BEC00
#define CListWnd__GetColumnWidth_x                                 0x8BEB30
#define CListWnd__GetCurSel_x                                      0x8BE300
#define CListWnd__GetItemAtPoint_x                                 0x8C03F0
#define CListWnd__GetItemAtPoint1_x                                0x8C0460
#define CListWnd__GetItemData_x                                    0x8BE650
#define CListWnd__GetItemHeight_x                                  0x8BFC50
#define CListWnd__GetItemIcon_x                                    0x8BE840
#define CListWnd__GetItemRect_x                                    0x8C0230
#define CListWnd__GetItemText_x                                    0x8BE6F0
#define CListWnd__GetSelList_x                                     0x8C36D0
#define CListWnd__GetSeparatorRect_x                               0x8C0C00
#define CListWnd__InsertLine_x                                     0x8C35C0
#define CListWnd__RemoveLine_x                                     0x8C35D0
#define CListWnd__SetColors_x                                      0x8BE450
#define CListWnd__SetColumnJustification_x                         0x8BEE90
#define CListWnd__SetColumnWidth_x                                 0x8BEBB0
#define CListWnd__SetCurSel_x                                      0x8BE340
#define CListWnd__SetItemColor_x                                   0x8C2A70
#define CListWnd__SetItemData_x                                    0x8BF370
#define CListWnd__SetItemText_x                                    0x8C28B0
#define CListWnd__ShiftColumnSeparator_x                           0x8C2740
#define CListWnd__Sort_x                                           0x8C42A0
#define CListWnd__ToggleSel_x                                      0x8BF240

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7197A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73EE70
#define CMerchantWnd__RequestBuyItem_x                             0x746A30
#define CMerchantWnd__RequestSellItem_x                            0x7490B0
#define CMerchantWnd__SelectRecoverySlot_x                         0x73C120
#define CMerchantWnd__SelectBuySellSlot_x                          0x739FC0
#define CMerchantWnd__ActualSelect_x                               0x740C60

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x854C10
#define CPacketScrambler__hton_x                                   0x854C20

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E1FF0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E20D0
#define CSidlManager__CreateLabel_x                                0x7A3260
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E0580
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E23B0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D9420
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D9310
#define CSidlScreenWnd__ConvertToRes_x                             0x8FE070
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D9D30
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DAF00
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DAFB0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DA490
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D96E0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D8E40
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D98D0
#define CSidlScreenWnd__Init1_x                                    0x8DABE0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D9DF0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D9000
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DA6D0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D8A90
#define CSidlScreenWnd__StoreIniVis_x                              0x8D8DF0
#define CSidlScreenWnd__WndNotification_x                          0x8DA960
#define CSidlScreenWnd__GetChildItem_x                             0x8D8F10
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CC6E0
#define CSidlScreenWnd__m_layoutCopy_x                             0x1730E40

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x604DA0
#define CSkillMgr__GetSkillCap_x                                   0x604F80
#define CSkillMgr__GetNameToken_x                                  0x604950

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FD310
#define CSliderWnd__SetValue_x                                     0x8FD4E0
#define CSliderWnd__SetNumTicks_x                                  0x8FDC60

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A9690

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F70B0
#define CStmlWnd__CalculateHSBRange_x                              0x8EF600
#define CStmlWnd__CalculateVSBRange_x                              0x8EF570
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EF780
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EFF80
#define CStmlWnd__ForceParseNow_x                                  0x8F7A30
#define CStmlWnd__GetNextTagPiece_x                                0x8EFE80
#define CStmlWnd__GetSTMLText_x                                    0x484270
#define CStmlWnd__GetVisibleText_x                                 0x8F09D0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F2FA0
#define CStmlWnd__MakeStmlColorTag_x                               0x8EE850
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EE8B0
#define CStmlWnd__SetSTMLText_x                                    0x8F47F0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F6D50
#define CStmlWnd__UpdateHistoryString_x                            0x8F1910

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FAFA0
#define CTabWnd__DrawCurrentPage_x                                 0x8FA830
#define CTabWnd__DrawTab_x                                         0x8FA5F0
#define CTabWnd__GetCurrentPage_x                                  0x8FABE0
#define CTabWnd__GetPageInnerRect_x                                0x8FA2E0
#define CTabWnd__GetTabInnerRect_x                                 0x8FA4E0
#define CTabWnd__GetTabRect_x                                      0x8FA3B0
#define CTabWnd__InsertPage_x                                      0x8FB290
#define CTabWnd__SetPage_x                                         0x8FAC10
#define CTabWnd__SetPageRect_x                                     0x8FAEE0
#define CTabWnd__UpdatePage_x                                      0x8FB230
#define CTabWnd__GetPageFromTabIndex_x                             0x8FA540
#define CTabWnd__GetCurrentTabIndex_x                              0x8FA270

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E60B0
#define CPageWnd__SetTabText_x                                     0x9073E0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436C50

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D6D60
#define CTextureFont__GetTextExtent_x                              0x8D6AC0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63D700

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x903820

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BC3A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029C0
#define CXStr__CXStr1_x                                            0x7E1150
#define CXStr__CXStr3_x                                            0x89F600
#define CXStr__dCXStr_x                                            0x7A3210
#define CXStr__operator_equal_x                                    0x89F770
#define CXStr__operator_equal1_x                                   0x89F7C0
#define CXStr__operator_plus_equal1_x                              0x8A08C0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D4860
#define CXWnd__BringToTop_x                                        0x8CB920
#define CXWnd__Center_x                                            0x8D1B50
#define CXWnd__ClrFocus_x                                          0x8CB4F0
#define CXWnd__Destroy_x                                           0x8D2640
#define CXWnd__DoAllDrawing_x                                      0x8D17A0
#define CXWnd__DrawChildren_x                                      0x8D1940
#define CXWnd__DrawColoredRect_x                                   0x8CBCD0
#define CXWnd__DrawTooltip_x                                       0x8CBF80
#define CXWnd__DrawTooltipAtPoint_x                                0x8D0700
#define CXWnd__GetBorderFrame_x                                    0x8CC3A0
#define CXWnd__GetChildWndAt_x                                     0x8D2520
#define CXWnd__GetClientClipRect_x                                 0x8CC1A0
#define CXWnd__GetScreenClipRect_x                                 0x8D0E00
#define CXWnd__GetScreenRect_x                                     0x8CC570
#define CXWnd__GetTooltipRect_x                                    0x8CBE10
#define CXWnd__GetWindowTextA_x                                    0x426EF0
#define CXWnd__IsActive_x                                          0x8C6F60
#define CXWnd__IsDescendantOf_x                                    0x8CC2E0
#define CXWnd__IsReallyVisible_x                                   0x8CF720
#define CXWnd__IsType_x                                            0x8D1BC0
#define CScreenPieceTemplate__IsType_x                             0x8FFF30
#define CXWnd__Move_x                                              0x8CEE00
#define CXWnd__Move1_x                                             0x8D1440
#define CXWnd__ProcessTransition_x                                 0x8CB8C0
#define CXWnd__Refade_x                                            0x8CB6A0
#define CXWnd__Resize_x                                            0x8CC640
#define CXWnd__Right_x                                             0x8D0C00
#define CXWnd__SetFocus_x                                          0x8CDF40
#define CXWnd__SetFont_x                                           0x8CB540
#define CXWnd__SetKeyTooltip_x                                     0x8CC8B0
#define CXWnd__SetMouseOver_x                                      0x8D1130
#define CXWnd__StartFade_x                                         0x8CB970
#define CXWnd__GetChildItem_x                                      0x8D1080
#define CXWnd__SetParent_x                                         0x8D24D0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C87F0
#define CXWndManager__DrawWindows_x                                0x8C8430
#define CXWndManager__GetKeyboardFlags_x                           0x8C6A90
#define CXWndManager__HandleKeyboardMsg_x                          0x8C73F0
#define CXWndManager__RemoveWnd_x                                  0x8C70F0

// CDBStr
#define CDBStr__GetString_x                                        0x4BA3B0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4525E0
#define EQ_Character__Cur_HP_x                                     0x4669F0
#define EQ_Character__Cur_Mana_x                                   0x45B9F0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B6A0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4436B0
#define EQ_Character__GetFocusRangeModifier_x                      0x443800
#define EQ_Character__GetHPRegen_x                                 0x46A590
#define EQ_Character__GetEnduranceRegen_x                          0x466000
#define EQ_Character__GetManaRegen_x                               0x46AB30
#define EQ_Character__Max_Endurance_x                              0x5CB720
#define EQ_Character__Max_HP_x                                     0x45E570
#define EQ_Character__Max_Mana_x                                   0x5CB550
#define EQ_Character__doCombatAbility_x                            0x5C8C20
#define EQ_Character__UseSkill_x                                   0x472920
#define EQ_Character__GetConLevel_x                                0x5BE3E0
#define EQ_Character__IsExpansionFlag_x                            0x4B6700
#define EQ_Character__TotalEffect_x                                0x44F810
#define EQ_Character__GetPCSpellAffect_x                           0x44BA30
#define EQ_Character__SpellDuration_x                              0x449A30
#define EQ_Character__FindItemByRecord_x                           0x464060
#define EQ_Character__GetAdjustedSkill_x                           0x466BC0
#define EQ_Character__GetBaseSkill_x                               0x45E450

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x872960

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D3E00

//PcClient
#define PcClient__PcClient_x                                       0x5C0220

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446B40
#define CCharacterSelect__EnterWorld_x                             0x446310
#define CCharacterSelect__Quit_x                                   0x444ED0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59E160
#define EQ_Item__CreateItemTagString_x                             0x852DF0
#define EQ_Item__IsStackable_x                                     0x8481E0
#define EQ_Item__GetImageNum_x                                     0x84AD20
#define EQ_Item__CreateItemClient_x                                0x59F290
#define EQ_Item__GetItemValue_x                                    0x8517D0
#define EQ_Item__ValueSellMerchant_x                               0x8548A0
#define EQ_Item__IsKeyRingItem_x                                   0x848D50
#define EQ_Item__CanGoInBag_x                                      0x59E2F0
#define EQ_Item__GetMaxItemCount_x                                 0x8480D0
#define EQ_Item__GetHeldItem_x                                     0x849B40
#define EQ_Item__GetAugmentFitBySlot_x                             0x8546C0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA650
#define EQ_LoadingS__Array_x                                       0xC0BC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CDC50
#define EQ_PC__GetAlternateAbilityId_x                             0x85CCC0
#define EQ_PC__GetCombatAbility_x                                  0x85CD50
#define EQ_PC__GetCombatAbilityTimer_x                             0x8578C0
#define EQ_PC__GetItemRecastTimer_x                                0x5C7410
#define EQ_PC__HasLoreItem_x                                       0x5C19E0
#define EQ_PC__AlertInventoryChanged_x                             0x5BE390
#define EQ_PC__GetPcZoneClient_x                                   0x5E8340
#define EQ_PC__RemoveMyAffect_x                                    0x5C6840
#define EQ_PC__GetKeyRingItems_x                                   0x857CE0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86A9D0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85EC30

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5264B0
#define EQItemList__add_object_x                                   0x5535B0
#define EQItemList__add_item_x                                     0x5263F0
#define EQItemList__delete_item_x                                  0x5268A0
#define EQItemList__FreeItemList_x                                 0x5267A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9660

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D3AC0
#define EQPlayer__dEQPlayer_x                                      0x5DC270
#define EQPlayer__DoAttack_x                                       0x5EDB10
#define EQPlayer__EQPlayer_x                                       0x5DE990
#define EQPlayer__SetNameSpriteState_x                             0x5D90A0
#define EQPlayer__SetNameSpriteTint_x                              0x5D4FC0
#define PlayerBase__HasProperty_j_x                                0x931830
#define EQPlayer__IsTargetable_x                                   0x931AD0
#define EQPlayer__CanSee_x                                         0x932030
#define PlayerZoneClient__ChangeHeight_x                           0x5ED9D0
#define EQPlayer__CanSee1_x                                        0x932120
#define PlayerBase__GetVisibilityLineSegment_x                     0x931DC0

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E84F0
#define PlayerZoneClient__IsValidTeleport_x                        0x553E50
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D27C0


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E2980
#define EQPlayerManager__GetSpawnByName_x                          0x5E2DE0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E29B0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A4870
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A48B0
#define KeypressHandler__ClearCommandStateArray_x                  0x5A4460
#define KeypressHandler__HandleKeyDown_x                           0x5A2D80
#define KeypressHandler__HandleKeyUp_x                             0x5A30A0
#define KeypressHandler__SaveKeymapping_x                          0x5A4530

// MapViewMap 
#define MapViewMap__Clear_x                                        0x712130
#define MapViewMap__SaveEx_x                                       0x715460
#define MapViewMap__SetZoom_x                                      0x711DB0

#define PlayerPointManager__GetAltCurrency_x                       0x8709F0

// StringTable 
#define StringTable__getString_x                                   0x86AD00

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CB1B0
#define PcZoneClient__RemovePetEffect_x                            0x5C78E0
#define PcZoneClient__HasAlternateAbility_x                        0x5C8280
#define PcZoneClient__GetCurrentMod_x                              0x45DA20
#define PcZoneClient__GetModCap_x                                  0x45B150
#define PcZoneClient__CanEquipItem_x                               0x5C8760
#define PcZoneClient__GetItemByID_x                                0x5CCFC0
#define PcZoneClient__GetItemByItemClass_x                         0x5CDB70
#define PcZoneClient__RemoveBuffEffect_x                           0x5C6AF0

//Doors
#define EQSwitch__UseSwitch_x                                      0x55AFA0

//IconCache
#define IconCache__GetIcon_x                                       0x6AF180

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A6060
#define CContainerMgr__CloseContainer_x                            0x6A6880

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7730E0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5971E0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F4C80
#define EQ_Spell__SpellAffects_x                                   0x4F1E60
#define EQ_Spell__SpellAffectBase_x                                0x4F1ED0
#define CharacterZoneClient__CalcAffectChange_x                    0x44B8C0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AB60
#define CLootWnd__LootAll_x                                        0x7079E0
#define CLootWnd__RequestLootSlot_x                                0x7081F0
#define EQ_Spell__IsStackable_x                                    0x4590F0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4494E0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EC00
#define EQ_Spell__IsSPAStacking_x                                  0x4F19D0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2A70
#define EQ_Spell__IsNoRemove_x                                     0x434C80
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F19F0

#define __IsResEffectSpell_x                                       0x449580

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87C5E0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BB010
#define CTargetWnd__WndNotification_x                              0x7BAB00
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BB1F0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C0140

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED550
#define EqSoundManager__PlayScriptMp3_x                            0x4EEFF0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A87F0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EAC30
#define CSidlManager__FindAnimation1_x                             0x8DFFB0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E1EE0
#define CAltAbilityData__GetMercMaxRank_x                          0x4E1E90
#define CAltAbilityData__GetMaxRank_x                              0x4D66E0

//CTargetRing
#define CTargetRing__Cast_x                                        0x594E20

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4593E0
#define CharacterBase__CreateItemGlobalIndex_x                     0x475350
#define CharacterBase__CreateItemIndex_x                           0x51FAB0
#define CharacterBase__GetItemPossession_x                         0x4443D0
#define CharacterBase__GetItemByGlobalIndex_x                      0x880430
#define CharacterBase__GetEffectId_x                               0x4593A0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68EF20
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68E680

//messages
#define msg_spell_worn_off_x                                       0x4FC740
#define msg_new_text_x                                             0x505EC0
#define msgTokenTextParam_x                                        0x5026C0

//SpellManager
#define SpellManager__vftable_x                                    0xAC9258
#define SpellManager__SpellManager_x                               0x47DEF0
#define Spellmanager__LoadTextSpells_x                             0x60BC40

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x935BC0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487BF0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EB10
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449230
#define ItemGlobalIndex__IsValidIndex_x                            0x458BF0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87E2A0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87D1E0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x700830

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AADB0
#define CCursorAttachment__Deactivate_x                            0x6AA300

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FC810
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FC990

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                        0x6039E0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C460

//IString
#define IString__Append_x                                          0x47EB40

//Camera
#define CDisplay__cameraType_x                                     0xE6F7E8
#define EverQuest__Cameras_x                                       0xF31AE8
