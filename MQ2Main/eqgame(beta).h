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
#define __ExpectedVersionDate                                     "Dec 10 2017"
#define __ExpectedVersionTime                                     "04:19:56"
#define __ActualVersionDate_x                                      0xAE4088
#define __ActualVersionTime_x                                      0xAE4094

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5A9F30
#define __MemChecker1_x                                            0x8A28F0
#define __MemChecker2_x                                            0x63FDB0
#define __MemChecker3_x                                            0x63FD00
#define __MemChecker4_x                                            0x7F4690
#define __EncryptPad0_x                                            0xC3EFE8
#define __EncryptPad1_x                                            0xD18BA0
#define __EncryptPad2_x                                            0xC67ED0
#define __EncryptPad3_x                                            0xC67AD0
#define __EncryptPad4_x                                            0xD071A0
#define __EncryptPad5_x                                            0x10C22E0
#define __AC1_x                                                    0x7B3685
#define __AC2_x                                                    0x563317
#define __AC3_x                                                    0x561490
#define __AC4_x                                                    0x573661
#define __AC5_x                                                    0x5873BB
#define __AC6_x                                                    0x58AF6E
#define __AC7_x                                                    0x5819BC
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
#define __do_loot_x                                                0x5323C0
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
#define __CastRay_x                                                0x549C70
#define __CastRay2_x                                               0x5495A0
#define __HeadingDiff_x                                            0x932E40
#define __FixHeading_x                                             0x932DD0
#define __get_bearing_x                                            0x539510
#define __ConvertItemTags_x                                        0x536FE0
#define __ExecuteCmd_x                                             0x5218C0
#define __EQGetTime_x                                              0x8A2290
#define __get_melee_range_x                                        0x528580
#define __GetGaugeValueFromEQ_x                                    0x7B2240
#define __GetLabelFromEQ_x                                         0x7B3610
#define __ToggleKeyRingItem_x                                      0x48FE00
#define __GetXTargetType_x                                         0x934A40
#define __LoadFrontEnd_x                                           0x63F480
#define __NewUIINI_x                                               0x7B1C10
#define __ProcessGameEvents_x                                      0x583750
#define __ProcessMouseEvent_x                                      0x582EF0
#define CrashDetected_x                                            0x640E40
#define wwsCrashReportCheckForUploader_x                           0x8002E0
#define __AppCrashWrapper_x                                        0xC67AC4
#define __pCrashHandler_x                                          0x10D7A00
#define __CrashHandler_x                                           0x7FFD70
#define wwsCrashReportPlatformLaunchUploader_x                     0x802510
#define DrawNetStatus_x                                            0x5B9B60
#define Util__FastTime_x                                           0x8A1F30
#define Expansion_HoT_x                                            0xF317D0
#define __HelpPath_x                                               0xFB4F80
#define __STMLToText_x                                             0x8E8720
#define __GetAnimationCache_x                                      0x6AEDB0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423330
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DF90
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DD60

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D8140
#define AltAdvManager__IsAbilityReady_x                            0x4D81B0
#define AltAdvManager__GetAAById_x                                 0x4D86A0
#define AltAdvManager__CanTrainAbility_x                           0x4D92D0
#define AltAdvManager__CanSeeAbility_x                             0x4D8E90

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46AFC0
#define CharacterZoneClient__HasSkill_x                            0x466ED0
#define CharacterZoneClient__MakeMeVisible_x                       0x46CB30
#define CharacterZoneClient__IsStackBlocked_x                      0x44BF20
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B440
#define CharacterZoneClient__GetItemCountWorn_x                    0x465430
#define CharacterZoneClient__GetItemCountInInventory_x             0x465510
#define CharacterZoneClient__GetCursorItemCount_x                  0x4655F0
#define CharacterZoneClient__FindAffectSlot_x                      0x4515B0
#define CharacterZoneClient__BardCastBard_x                        0x44ABB0
#define CharacterZoneClient__GetMaxEffects_x                       0x449740
#define CharacterZoneClient__GetEffect_x                           0x44B670
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451410
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449A90
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FF60

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66ED80

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67CBE0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x598810
#define CButtonWnd__CButtonWnd_x                                   0x8DC980

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x697F80
#define CChatManager__InitContextMenu_x                            0x6990D0
#define CChatManager__FreeChatWindow_x                             0x697A30
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A1270
#define CChatManager__SetLockedActiveChatWindow_x                  0x697F50

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E6A70
#define CContextMenu__dCContextMenu_x                              0x8E6C80
#define CContextMenu__AddMenuItem_x                                0x8E71A0
#define CContextMenu__RemoveMenuItem_x                             0x8E6E00
#define CContextMenu__RemoveAllMenuItems_x                         0x8E6E20
#define CContextMenu__CheckMenuItem_x                              0x8E6EA0
#define CContextMenu__SetMenuItem_x                                0x8E6D20

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D2F40
#define CContextMenuManager__RemoveMenu_x                          0x8D32F0
#define CContextMenuManager__PopupMenu_x                           0x8D3740
#define CContextMenuManager__Flush_x                               0x8D2FB0
#define CContextMenuManager__GetMenu_x                             0x419420

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8864A0
#define CChatService__GetFriendName_x                              0x8864B0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69ED40
#define CChatWindow__Clear_x                                       0x69E620
#define CChatWindow__WndNotification_x                             0x69F650

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D6DA0
#define CComboWnd__Draw_x                                          0x8D6FB0
#define CComboWnd__GetCurChoice_x                                  0x8D6B50
#define CComboWnd__GetListRect_x                                   0x8D7250
#define CComboWnd__GetTextRect_x                                   0x8D6E10
#define CComboWnd__InsertChoice_x                                  0x8D73B0
#define CComboWnd__SetColors_x                                     0x8D6AE0
#define CComboWnd__SetChoice_x                                     0x8D6B10
#define CComboWnd__GetItemCount_x                                  0x8D6B40
#define CComboWnd__GetCurChoiceText_x                              0x8D6B90


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A8F50
#define CContainerWnd__vftable_x                                   0xAED9A0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C60F0
#define CDisplay__GetClickedActor_x                                0x4BE9B0
#define CDisplay__GetUserDefinedColor_x                            0x4BD590
#define CDisplay__GetWorldFilePath_x                               0x4BC9E0
#define CDisplay__is3dON_x                                         0x4BBE70
#define CDisplay__ReloadUI_x                                       0x4CFEB0
#define CDisplay__WriteTextHD2_x                                   0x4C2480
#define CDisplay__TrueDistance_x                                   0x4BF5E0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FDB20

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EAFD0
#define CEditWnd__GetCharIndexPt_x                                 0x8EC130
#define CEditWnd__GetDisplayString_x                               0x8EB180
#define CEditWnd__GetHorzOffset_x                                  0x8EB4C0
#define CEditWnd__GetLineForPrintableChar_x                        0x8EBBF0
#define CEditWnd__GetSelStartPt_x                                  0x8EC3F0
#define CEditWnd__GetSTMLSafeText_x                                0x8EB660
#define CEditWnd__PointFromPrintableChar_x                         0x8EBCE0
#define CEditWnd__SelectableCharFromPoint_x                        0x8EBE60
#define CEditWnd__SetEditable_x                                    0x8EB630

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x569E90
#define CEverQuest__ClickedPlayer_x                                0x563A60
#define CEverQuest__CreateTargetIndicator_x                        0x564960
#define CEverQuest__DeleteTargetIndicator_x                        0x5649E0
#define CEverQuest__DoTellWindow_x                                 0x476240
#define CEverQuest__OutputTextToLog_x                              0x475EA0
#define CEverQuest__DropHeldItemOnGround_x                         0x57A400
#define CEverQuest__dsp_chat_x                                     0x476580
#define CEverQuest__trimName_x                                     0x560370
#define CEverQuest__Emote_x                                        0x578710
#define CEverQuest__EnterZone_x                                    0x5737F0
#define CEverQuest__GetBodyTypeDesc_x                              0x55DDB0
#define CEverQuest__GetClassDesc_x                                 0x5672A0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5678A0
#define CEverQuest__GetDeityDesc_x                                 0x55E690
#define CEverQuest__GetLangDesc_x                                  0x55E140
#define CEverQuest__GetRaceDesc_x                                  0x567A60
#define CEverQuest__InterpretCmd_x                                 0x56B610
#define CEverQuest__LeftClickedOnPlayer_x                          0x57FF60
#define CEverQuest__LMouseUp_x                                     0x581F10
#define CEverQuest__RightClickedOnPlayer_x                         0x580A70
#define CEverQuest__RMouseUp_x                                     0x581970
#define CEverQuest__SetGameState_x                                 0x564330
#define CEverQuest__UPCNotificationFlush_x                         0x55C740
#define CEverQuest__IssuePetCommand_x                              0x56BFF0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B9BD0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B9C30
#define CGaugeWnd__Draw_x                                          0x6BA060

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B190
#define CGuild__GetGuildName_x                                     0x43B660
#define CGuild__GetGuildIndex_x                                    0x43C870

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D60F0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E34B0
#define CInvSlotMgr__MoveItem_x                                    0x6E3C70
#define CInvSlotMgr__SelectSlot_x                                  0x6E2DA0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E2200
#define CInvSlot__SliderComplete_x                                 0x6DFA20
#define CInvSlot__GetItemBase_x                                    0x6DEEB0
#define CInvSlot__UpdateItem_x                                     0x6DF430

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E50D0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E6200

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AE0C0
#define CItemDisplayWnd__UpdateStrings_x                           0x6E72E0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F3B10
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F4040
#define CItemDisplayWnd__SetItem_x                                 0x6F9930

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E5340

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6ED810

// CLabel 
#define CLabel__Draw_x                                             0x700730

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C2980
#define CListWnd__dCListWnd_x                                      0x8C3C30
#define CListWnd__AddColumn_x                                      0x8C3BD0
#define CListWnd__AddColumn1_x                                     0x8C3270
#define CListWnd__AddLine_x                                        0x8C2C50
#define CListWnd__AddString_x                                      0x8C2E70
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BFA80
#define CListWnd__CalculateVSBRange_x                              0x8C1E40
#define CListWnd__ClearSel_x                                       0x8BED90
#define CListWnd__ClearAllSel_x                                    0x8BED40
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C2810
#define CListWnd__Compare_x                                        0x8C0780
#define CListWnd__Draw_x                                           0x8C1A40
#define CListWnd__DrawColumnSeparators_x                           0x8C18D0
#define CListWnd__DrawHeader_x                                     0x8BF050
#define CListWnd__DrawItem_x                                       0x8C0E00
#define CListWnd__DrawLine_x                                       0x8C1570
#define CListWnd__DrawSeparator_x                                  0x8C1970
#define CListWnd__EnableLine_x                                     0x8BEF70
#define CListWnd__EnsureVisible_x                                  0x8BFBE0
#define CListWnd__ExtendSel_x                                      0x8C0D10
#define CListWnd__GetColumnMinWidth_x                              0x8BE680
#define CListWnd__GetColumnWidth_x                                 0x8BE5B0
#define CListWnd__GetCurSel_x                                      0x8BDDA0
#define CListWnd__GetItemAtPoint_x                                 0x8BFE80
#define CListWnd__GetItemAtPoint1_x                                0x8BFEF0
#define CListWnd__GetItemData_x                                    0x8BE0D0
#define CListWnd__GetItemHeight_x                                  0x8BF6D0
#define CListWnd__GetItemIcon_x                                    0x8BE2C0
#define CListWnd__GetItemRect_x                                    0x8BFCC0
#define CListWnd__GetItemText_x                                    0x8BE170
#define CListWnd__GetSelList_x                                     0x8C3160
#define CListWnd__GetSeparatorRect_x                               0x8C06A0
#define CListWnd__InsertLine_x                                     0x8C3050
#define CListWnd__RemoveLine_x                                     0x8C3060
#define CListWnd__SetColors_x                                      0x8BDEF0
#define CListWnd__SetColumnJustification_x                         0x8BE910
#define CListWnd__SetColumnWidth_x                                 0x8BE630
#define CListWnd__SetCurSel_x                                      0x8BDDE0
#define CListWnd__SetItemColor_x                                   0x8C2500
#define CListWnd__SetItemData_x                                    0x8BEDF0
#define CListWnd__SetItemText_x                                    0x8C2340
#define CListWnd__ShiftColumnSeparator_x                           0x8C21D0
#define CListWnd__Sort_x                                           0x8C3D30
#define CListWnd__ToggleSel_x                                      0x8BECC0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x719810

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73EFF0
#define CMerchantWnd__RequestBuyItem_x                             0x746B90
#define CMerchantWnd__RequestSellItem_x                            0x749200
#define CMerchantWnd__SelectRecoverySlot_x                         0x73C2B0
#define CMerchantWnd__SelectBuySellSlot_x                          0x73A140
#define CMerchantWnd__ActualSelect_x                               0x740DD0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8546D0
#define CPacketScrambler__hton_x                                   0x8546E0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E1920
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E1A00
#define CSidlManager__CreateLabel_x                                0x7A3080
#define CSidlManager__CreateXWndFromTemplate_x                     0x8DFEB0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E1CE0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D8E00
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D8CF0
#define CSidlScreenWnd__ConvertToRes_x                             0x8FDA00
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D9710
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DA8E0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DA990
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D9E60
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D90C0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D8820
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D92B0
#define CSidlScreenWnd__Init1_x                                    0x8DA5B0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D97D0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D89E0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DA0A0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D8480
#define CSidlScreenWnd__StoreIniVis_x                              0x8D87D0
#define CSidlScreenWnd__WndNotification_x                          0x8DA330
#define CSidlScreenWnd__GetChildItem_x                             0x8D88F0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CC1A0
#define CSidlScreenWnd__m_layoutCopy_x                             0x1730E40

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x604E70
#define CSkillMgr__GetSkillCap_x                                   0x605050
#define CSkillMgr__GetNameToken_x                                  0x604A20

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FCCA0
#define CSliderWnd__SetValue_x                                     0x8FCE70
#define CSliderWnd__SetNumTicks_x                                  0x8FD5F0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A93A0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F6A80
#define CStmlWnd__CalculateHSBRange_x                              0x8EEFD0
#define CStmlWnd__CalculateVSBRange_x                              0x8EEF40
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EF150
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EF950
#define CStmlWnd__ForceParseNow_x                                  0x8F7400
#define CStmlWnd__GetNextTagPiece_x                                0x8EF850
#define CStmlWnd__GetSTMLText_x                                    0x484460
#define CStmlWnd__GetVisibleText_x                                 0x8F03A0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F2970
#define CStmlWnd__MakeStmlColorTag_x                               0x8EE220
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EE280
#define CStmlWnd__SetSTMLText_x                                    0x8F41D0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F6720
#define CStmlWnd__UpdateHistoryString_x                            0x8F12E0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FA940
#define CTabWnd__DrawCurrentPage_x                                 0x8FA1D0
#define CTabWnd__DrawTab_x                                         0x8F9F90
#define CTabWnd__GetCurrentPage_x                                  0x8FA580
#define CTabWnd__GetPageInnerRect_x                                0x8F9C80
#define CTabWnd__GetTabInnerRect_x                                 0x8F9E80
#define CTabWnd__GetTabRect_x                                      0x8F9D50
#define CTabWnd__InsertPage_x                                      0x8FAC30
#define CTabWnd__SetPage_x                                         0x8FA5B0
#define CTabWnd__SetPageRect_x                                     0x8FA880
#define CTabWnd__UpdatePage_x                                      0x8FABD0
#define CTabWnd__GetPageFromTabIndex_x                             0x8F9EE0
#define CTabWnd__GetCurrentTabIndex_x                              0x8F9C10

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E63B0
#define CPageWnd__SetTabText_x                                     0x906D60

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436D80

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D6750
#define CTextureFont__GetTextExtent_x                              0x8D64B0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63D700

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9031A0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BBF90

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029F0
#define CXStr__CXStr1_x                                            0x750B00
#define CXStr__CXStr3_x                                            0x89F180
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x89F2F0
#define CXStr__operator_equal1_x                                   0x89F340
#define CXStr__operator_plus_equal1_x                              0x8A0440

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D4260
#define CXWnd__BringToTop_x                                        0x8CB3A0
#define CXWnd__Center_x                                            0x8D1520
#define CXWnd__ClrFocus_x                                          0x8CAF60
#define CXWnd__Destroy_x                                           0x8D1FF0
#define CXWnd__DoAllDrawing_x                                      0x8D1180
#define CXWnd__DrawChildren_x                                      0x8D1320
#define CXWnd__DrawColoredRect_x                                   0x8CB790
#define CXWnd__DrawTooltip_x                                       0x8CBA40
#define CXWnd__DrawTooltipAtPoint_x                                0x8D00F0
#define CXWnd__GetBorderFrame_x                                    0x8CBE90
#define CXWnd__GetChildWndAt_x                                     0x8D1ED0
#define CXWnd__GetClientClipRect_x                                 0x8CBC50
#define CXWnd__GetScreenClipRect_x                                 0x8D07F0
#define CXWnd__GetScreenRect_x                                     0x8CC040
#define CXWnd__GetTooltipRect_x                                    0x8CB8D0
#define CXWnd__GetWindowTextA_x                                    0x426E30
#define CXWnd__IsActive_x                                          0x8C69E0
#define CXWnd__IsDescendantOf_x                                    0x8CBDE0
#define CXWnd__IsReallyVisible_x                                   0x8CF120
#define CXWnd__IsType_x                                            0x8D1590
#define CScreenPieceTemplate__IsType_x                             0x8FF8F0
#define CXWnd__Move_x                                              0x8CE860
#define CXWnd__Move1_x                                             0x8D0E30
#define CXWnd__ProcessTransition_x                                 0x8CB340
#define CXWnd__Refade_x                                            0x8CB110
#define CXWnd__Resize_x                                            0x8CC110
#define CXWnd__Right_x                                             0x8D05F0
#define CXWnd__SetFocus_x                                          0x8CD9A0
#define CXWnd__SetFont_x                                           0x8CAFB0
#define CXWnd__SetKeyTooltip_x                                     0x8CC370
#define CXWnd__SetMouseOver_x                                      0x8D0B20
#define CXWnd__StartFade_x                                         0x8CB3F0
#define CXWnd__GetChildItem_x                                      0x8D0A60
#define CXWnd__SetParent_x                                         0x8D1E80

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C8270
#define CXWndManager__DrawWindows_x                                0x8C7EC0
#define CXWndManager__GetKeyboardFlags_x                           0x8C6510
#define CXWndManager__HandleKeyboardMsg_x                          0x8C6E70
#define CXWndManager__RemoveWnd_x                                  0x8C6B70

// CDBStr
#define CDBStr__GetString_x                                        0x4BA690

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452670
#define EQ_Character__Cur_HP_x                                     0x466AB0
#define EQ_Character__Cur_Mana_x                                   0x45BAB0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B750
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443720
#define EQ_Character__GetFocusRangeModifier_x                      0x443870
#define EQ_Character__GetHPRegen_x                                 0x46A650
#define EQ_Character__GetEnduranceRegen_x                          0x4660C0
#define EQ_Character__GetManaRegen_x                               0x46ABF0
#define EQ_Character__Max_Endurance_x                              0x5CBB70
#define EQ_Character__Max_HP_x                                     0x45E630
#define EQ_Character__Max_Mana_x                                   0x5CB9A0
#define EQ_Character__doCombatAbility_x                            0x5C9070
#define EQ_Character__UseSkill_x                                   0x4729E0
#define EQ_Character__GetConLevel_x                                0x5BE200
#define EQ_Character__IsExpansionFlag_x                            0x4B6A00
#define EQ_Character__TotalEffect_x                                0x44F8A0
#define EQ_Character__GetPCSpellAffect_x                           0x44BAE0
#define EQ_Character__SpellDuration_x                              0x449AE0
#define EQ_Character__FindItemByRecord_x                           0x464120
#define EQ_Character__GetAdjustedSkill_x                           0x466C80
#define EQ_Character__GetBaseSkill_x                               0x45E510

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8726C0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D4200

//PcClient
#define PcClient__PcClient_x                                       0x5C0040

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446BE0
#define CCharacterSelect__EnterWorld_x                             0x4463B0
#define CCharacterSelect__Quit_x                                   0x444F70

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59E130
#define EQ_Item__CreateItemTagString_x                             0x852900
#define EQ_Item__IsStackable_x                                     0x847F20
#define EQ_Item__GetImageNum_x                                     0x84AA20
#define EQ_Item__CreateItemClient_x                                0x59F280
#define EQ_Item__GetItemValue_x                                    0x851340
#define EQ_Item__ValueSellMerchant_x                               0x854360
#define EQ_Item__IsKeyRingItem_x                                   0x848A10
#define EQ_Item__CanGoInBag_x                                      0x59E2C0
#define EQ_Item__GetMaxItemCount_x                                 0x847E10
#define EQ_Item__GetHeldItem_x                                     0x849830
#define EQ_Item__GetAugmentFitBySlot_x                             0x854180

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA6E0
#define EQ_LoadingS__Array_x                                       0xC0BC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CE090
#define EQ_PC__GetAlternateAbilityId_x                             0x85C860
#define EQ_PC__GetCombatAbility_x                                  0x85C8F0
#define EQ_PC__GetCombatAbilityTimer_x                             0x857380
#define EQ_PC__GetItemRecastTimer_x                                0x5C7870
#define EQ_PC__HasLoreItem_x                                       0x5C1800
#define EQ_PC__AlertInventoryChanged_x                             0x5BE1B0
#define EQ_PC__GetPcZoneClient_x                                   0x5E8800
#define EQ_PC__RemoveMyAffect_x                                    0x5C6CA0
#define EQ_PC__GetKeyRingItems_x                                   0x8577A0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86A560
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85E7B0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x526610
#define EQItemList__add_object_x                                   0x5536F0
#define EQItemList__add_item_x                                     0x526550
#define EQItemList__delete_item_x                                  0x526A00
#define EQItemList__FreeItemList_x                                 0x526900

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9940

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D3EC0
#define EQPlayer__dEQPlayer_x                                      0x5DC680
#define EQPlayer__DoAttack_x                                       0x5EDFE0
#define EQPlayer__EQPlayer_x                                       0x5DEDA0
#define EQPlayer__SetNameSpriteState_x                             0x5D94B0
#define EQPlayer__SetNameSpriteTint_x                              0x5D53C0
#define PlayerBase__HasProperty_j_x                                0x931250
#define EQPlayer__IsTargetable_x                                   0x9314F0
#define EQPlayer__CanSee_x                                         0x931A50
#define PlayerZoneClient__ChangeHeight_x                           0x5EDEA0
#define EQPlayer__CanSee1_x                                        0x931B40
#define PlayerBase__GetVisibilityLineSegment_x                     0x9317E0

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E89B0
#define PlayerZoneClient__IsValidTeleport_x                        0x553F90
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2AA0


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E2DF0
#define EQPlayerManager__GetSpawnByName_x                          0x5E3250
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E2E20

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A47A0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A47E0
#define KeypressHandler__ClearCommandStateArray_x                  0x5A4390
#define KeypressHandler__HandleKeyDown_x                           0x5A2CB0
#define KeypressHandler__HandleKeyUp_x                             0x5A2FD0
#define KeypressHandler__SaveKeymapping_x                          0x5A4460

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7121A0
#define MapViewMap__SaveEx_x                                       0x7154D0
#define MapViewMap__SetZoom_x                                      0x711E20

#define PlayerPointManager__GetAltCurrency_x                       0x870780

// StringTable 
#define StringTable__getString_x                                   0x86A890

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CB600
#define PcZoneClient__RemovePetEffect_x                            0x5C7D40
#define PcZoneClient__HasAlternateAbility_x                        0x5C86E0
#define PcZoneClient__GetCurrentMod_x                              0x45DAE0
#define PcZoneClient__GetModCap_x                                  0x45B210
#define PcZoneClient__CanEquipItem_x                               0x5C8BC0
#define PcZoneClient__GetItemByID_x                                0x5CD410
#define PcZoneClient__GetItemByItemClass_x                         0x5CDFB0
#define PcZoneClient__RemoveBuffEffect_x                           0x5C6F50

//Doors
#define EQSwitch__UseSwitch_x                                      0x55AFF0

//IconCache
#define IconCache__GetIcon_x                                       0x6AF3E0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A62E0
#define CContainerMgr__CloseContainer_x                            0x6A6B00

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7730B0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x597230

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F4DD0
#define EQ_Spell__SpellAffects_x                                   0x4F1FB0
#define EQ_Spell__SpellAffectBase_x                                0x4F2020
#define CharacterZoneClient__CalcAffectChange_x                    0x44B970
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AC10
#define CLootWnd__LootAll_x                                        0x7079A0
#define CLootWnd__RequestLootSlot_x                                0x7081B0
#define EQ_Spell__IsStackable_x                                    0x459150
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449580
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EC70
#define EQ_Spell__IsSPAStacking_x                                  0x4F1B20
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2BC0
#define EQ_Spell__IsNoRemove_x                                     0x434DB0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F1B40

#define __IsResEffectSpell_x                                       0x449630

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87C350

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BAD10
#define CTargetWnd__WndNotification_x                              0x7BA800
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BAEF0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7BFE40

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED620
#define EqSoundManager__PlayScriptMp3_x                            0x4EF0C0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A89D0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EA600
#define CSidlManager__FindAnimation1_x                             0x8DF8E0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E1F60
#define CAltAbilityData__GetMercMaxRank_x                          0x4E1F10
#define CAltAbilityData__GetMaxRank_x                              0x4D67F0

//CTargetRing
#define CTargetRing__Cast_x                                        0x594E60

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4594F0
#define CharacterBase__CreateItemGlobalIndex_x                     0x475410
#define CharacterBase__CreateItemIndex_x                           0x51FC70
#define CharacterBase__GetItemPossession_x                         0x444410
#define CharacterBase__GetItemByGlobalIndex_x                      0x880190
#define CharacterBase__GetEffectId_x                               0x4594B0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68EF30
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68E690

//messages
#define msg_spell_worn_off_x                                       0x4FC8B0
#define msg_new_text_x                                             0x506030
#define msgTokenTextParam_x                                        0x502830

//SpellManager
#define SpellManager__vftable_x                                    0xAC9278
#define SpellManager__SpellManager_x                               0x47E070
#define Spellmanager__LoadTextSpells_x                             0x60BD40

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x935560

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487E60
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EBA0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x4492C0
#define ItemGlobalIndex__IsValidIndex_x                            0x458C90

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87E010
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87CF50

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x700980

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AB010
#define CCursorAttachment__Deactivate_x                            0x6AA550

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FC1A0
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FC320

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                        0x603970

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C6D0

//IString
#define IString__Append_x                                          0x47ECC0

//Camera
#define CDisplay__cameraType_x                                     0xE6F7E8
#define EverQuest__Cameras_x                                       0xF31AE8
