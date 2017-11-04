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
#define __ExpectedVersionDate                                     "Nov  4 2017"
#define __ExpectedVersionTime                                     "04:19:24"
#define __ActualVersionDate_x                                      0xAE40E8
#define __ActualVersionTime_x                                      0xAE40F4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5AA7A0
#define __MemChecker1_x                                            0x8A3030
#define __MemChecker2_x                                            0x640580
#define __MemChecker3_x                                            0x6404D0
#define __MemChecker4_x                                            0x7F4B90
#define __EncryptPad0_x                                            0xC3F000
#define __EncryptPad1_x                                            0xD18BB8
#define __EncryptPad2_x                                            0xC67EE8
#define __EncryptPad3_x                                            0xC67AE8
#define __EncryptPad4_x                                            0xD071B8
#define __EncryptPad5_x                                            0x10C22F0
#define __AC1_x                                                    0x7B3D65
#define __AC2_x                                                    0x563987
#define __AC3_x                                                    0x561B00
#define __AC4_x                                                    0x573D21
#define __AC5_x                                                    0x587A7B
#define __AC6_x                                                    0x58B62E
#define __AC7_x                                                    0x58207C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FA4908

// Direct Input
#define DI8__Main_x                                                0x10C22C8
#define DI8__Keyboard_x                                            0x10C22CC
#define DI8__Mouse_x                                               0x10C22D0
#define DI8__Mouse_Copy_x                                          0xF3046C
#define DI8__Mouse_Check_x                                         0xFB9FB4
#define __AutoSkillArray_x                                         0xF31380
#define __Attack_x                                                 0xFB4A73
#define __Autofire_x                                               0xFB4A74
#define __BindList_x                                               0xC1B378
#define g_eqCommandStates_x                                        0xF1F1B8
#define __Clicks_x                                                 0xF30528
#define __CommandList_x                                            0xC1DA90
#define __CurrentMapLabel_x                                        0x10C82C0
#define __CurrentSocial_x                                          0xBEA8F0
#define __DoAbilityList_x                                          0xF66C38
#define __do_loot_x                                                0x532730
#define __DrawHandler_x                                            0x1731F3C
#define __GroupCount_x                                             0xF20AC2

#define __Guilds_x                                                 0xF266D8
#define __gWorld_x                                                 0xF22F7C
#define __HotkeyPage_x                                             0xFAD638
#define __HWnd_x                                                   0xFBA0D0
#define __InChatMode_x                                             0xF30454
#define __LastTell_x                                               0xF32334
#define __LMouseHeldTime_x                                         0xF30594
#define __Mouse_x                                                  0x10C22D4
#define __MouseLook_x                                              0xF304EE
#define __MouseEventTime_x                                         0xFB520C
#define __gpbCommandEvent_x                                        0xF23044
#define __NetStatusToggle_x                                        0xF304F1
#define __PCNames_x                                                0xF3193C
#define __RangeAttackReady_x                                       0xF31664
#define __RMouseHeldTime_x                                         0xF30590
#define __RunWalkState_x                                           0xF30458
#define __ScreenMode_x                                             0xE6ED98
#define __ScreenX_x                                                0xF3040C
#define __ScreenY_x                                                0xF30408
#define __ScreenXMax_x                                             0xF30410
#define __ScreenYMax_x                                             0xF30414
#define __ServerHost_x                                             0xF20A0C
#define __ServerName_x                                             0xF66BF8
#define __ShiftKeyDown_x                                           0xF30AE8
#define __ShowNames_x                                              0xF3181C
#define __Socials_x                                                0xF66CF8
#define __SubscriptionType_x                                       0x10F8A44
#define __TargetAggroHolder_x                                      0x10CA41C
#define __ZoneType_x                                               0xF308EC
#define __GroupAggro_x                                             0x10CA45C
#define __LoginName_x                                              0xFB8BAC
#define __Inviter_x                                                0xFB49F0
#define __AttackOnAssist_x                                         0xF317D8
#define __UseTellWindows_x                                         0xF31AD4

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF23068
#define instEQZoneInfo_x                                           0xF306E4
#define instKeypressHandler_x                                      0xFB51F0
#define pinstActiveBanker_x                                        0xF23020
#define pinstActiveCorpse_x                                        0xF23024
#define pinstActiveGMaster_x                                       0xF23028
#define pinstActiveMerchant_x                                      0xF2301C
#define pinstAggroInfo_x                                           0xD2C3EC
#define pinstAltAdvManager_x                                       0xE6FF00
#define pinstAuraMgr_x                                             0xD3CC08
#define pinstBandageTarget_x                                       0xF23008
#define pinstCamActor_x                                            0xE6F7D0
#define pinstCDBStr_x                                              0xE6ED2C
#define pinstCDisplay_x                                            0xF23030
#define pinstCEverQuest_x                                          0x10C2448
#define pinstEverQuestInfo_x                                       0xF30400
#define pinstCharData_x                                            0xF22FEC
#define pinstCharSpawn_x                                           0xF23014
#define pinstControlledMissile_x                                   0xF22FE8
#define pinstControlledPlayer_x                                    0xF23014
#define pinstCSidlManager_x                                        0x1730EA8
#define pinstCXWndManager_x                                        0x1730EA0
#define instDynamicZone_x                                          0xF302A0
#define pinstDZMember_x                                            0xF303B0
#define pinstDZTimerInfo_x                                         0xF303B4
#define pinstEQItemList_x                                          0xF1F490
#define pinstEQObjectList_x                                        0xF204BC
#define instEQMisc_x                                               0xC037B8
#define pinstEQSoundManager_x                                      0xE704D0
#define instExpeditionLeader_x                                     0xF302EA
#define instExpeditionName_x                                       0xF3032A
#define pinstGroup_x                                               0xF20ABE
#define pinstImeManager_x                                          0x1730EAC
#define pinstLocalPlayer_x                                         0xF23000
#define pinstMercenaryData_x                                       0xFB5870
#define pinstMercenaryStats_x                                      0x10CA568
#define pinstMercAltAbilities_x                                    0xE70288
#define pinstModelPlayer_x                                         0xF2302C
#define pinstPCData_x                                              0xF22FEC
#define pinstSkillMgr_x                                            0xFB6868
#define pinstSpawnManager_x                                        0xFB60C0
#define pinstSpellManager_x                                        0xFB69B0
#define pinstSpellSets_x                                           0xFAD69C
#define pinstStringTable_x                                         0xF22F94
#define pinstSwitchManager_x                                       0xF20650
#define pinstTarget_x                                              0xF23018
#define pinstTargetObject_x                                        0xF22FF0
#define pinstTargetSwitch_x                                        0xF22FF4
#define pinstTaskMember_x                                          0xE6EC78
#define pinstTrackTarget_x                                         0xF2300C
#define pinstTradeTarget_x                                         0xF22FFC
#define instTributeActive_x                                        0xC037DD
#define pinstViewActor_x                                           0xE6F7CC
#define pinstWorldData_x                                           0xF22FD0
#define pinstZoneAddr_x                                            0xF30984
#define pinstPlayerPath_x                                          0xFB6120
#define pinstTargetIndicator_x                                     0xFB6B48
#define pinstCTargetManager_x                                      0xFB6BA8
#define EQObject_Top_x                                             0xF22FE0
#define pinstRealEstateItems_x                                     0xFB66D4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE6F6E8
#define pinstCAchievementsWnd_x                                    0xE6F744
#define pinstCTextOverlay_x                                        0xD2C998
#define pinstCAudioTriggersWindow_x                                0xD2C780
#define pinstCCharacterSelect_x                                    0xE6F654
#define pinstCFacePick_x                                           0xE6F404
#define pinstCFindItemWnd_x                                        0xE6F6E4
#define pinstCNoteWnd_x                                            0xE6F60C
#define pinstCBookWnd_x                                            0xE6F614
#define pinstCPetInfoWnd_x                                         0xE6F618
#define pinstCTrainWnd_x                                           0xE6F61C
#define pinstCSkillsWnd_x                                          0xE6F620
#define pinstCSkillsSelectWnd_x                                    0xE6F624
#define pinstCCombatSkillsSelectWnd_x                              0xE6F628
#define pinstCFriendsWnd_x                                         0xE6F62C
#define pinstCAuraWnd_x                                            0xE6F630
#define pinstCRespawnWnd_x                                         0xE6F634
#define pinstCBandolierWnd_x                                       0xE6F638
#define pinstCPotionBeltWnd_x                                      0xE6F63C
#define pinstCAAWnd_x                                              0xE6F640
#define pinstCAlarmWnd_x                                           0xE6F64C
#define pinstCGroupSearchFiltersWnd_x                              0xE6F644
#define pinstCLoadskinWnd_x                                        0xE6F648
#define pinstCLargeDialogWnd_x                                     0x10C94C8
#define pinstCMusicPlayerWnd_x                                     0xE6F650
#define pinstCMailWnd_x                                            0xE6F658
#define pinstCMailCompositionWnd_x                                 0xE6F65C
#define pinstCMailAddressBookWnd_x                                 0xE6F660
#define pinstCRaidWnd_x                                            0xE6F668
#define pinstCRaidOptionsWnd_x                                     0xE6F66C
#define pinstCBreathWnd_x                                          0xE6F670
#define pinstCMapViewWnd_x                                         0xE6F674
#define pinstCMapToolbarWnd_x                                      0xE6F678
#define pinstCEditLabelWnd_x                                       0xE6F67C
#define pinstCTargetWnd_x                                          0xE6F680
#define pinstCColorPickerWnd_x                                     0xE6F684
#define pinstCPlayerWnd_x                                          0xE6F688
#define pinstCOptionsWnd_x                                         0xE6F68C
#define pinstCBuffWindowNORMAL_x                                   0xE6F690
#define pinstCBuffWindowSHORT_x                                    0xE6F694
#define pinstCharacterCreation_x                                   0xE6F698
#define pinstCCursorAttachment_x                                   0xE6F69C
#define pinstCCastingWnd_x                                         0xE6F6A0
#define pinstCCastSpellWnd_x                                       0xE6F6A4
#define pinstCSpellBookWnd_x                                       0xE6F6A8
#define pinstCInventoryWnd_x                                       0xE6F6AC
#define pinstCBankWnd_x                                            0xE6F6B4
#define pinstCQuantityWnd_x                                        0xE6F6B8
#define pinstCLootWnd_x                                            0xE6F6BC
#define pinstCActionsWnd_x                                         0xE6F6C0
#define pinstCCombatAbilityWnd_x                                   0xE6F6C8
#define pinstCMerchantWnd_x                                        0xE6F6CC
#define pinstCTradeWnd_x                                           0xE6F6D4
#define pinstCSelectorWnd_x                                        0xE6F6D8
#define pinstCBazaarWnd_x                                          0xE6F6DC
#define pinstCBazaarSearchWnd_x                                    0xE6F6E0
#define pinstCGiveWnd_x                                            0xE6F700
#define pinstCTrackingWnd_x                                        0xE6F708
#define pinstCInspectWnd_x                                         0xE6F70C
#define pinstCSocialEditWnd_x                                      0xE6F710
#define pinstCFeedbackWnd_x                                        0xE6F714
#define pinstCBugReportWnd_x                                       0xE6F718
#define pinstCVideoModesWnd_x                                      0xE6F71C
#define pinstCTextEntryWnd_x                                       0xE6F724
#define pinstCFileSelectionWnd_x                                   0xE6F728
#define pinstCCompassWnd_x                                         0xE6F72C
#define pinstCPlayerNotesWnd_x                                     0xE6F730
#define pinstCGemsGameWnd_x                                        0xE6F734
#define pinstCTimeLeftWnd_x                                        0xE6F750
#define pinstCPetitionQWnd_x                                       0xE6F754
#define pinstCStoryWnd_x                                           0xE6F758
#define pinstCJournalTextWnd_x                                     0xE6F75C
#define pinstCJournalCatWnd_x                                      0xE6F760
#define pinstCBodyTintWnd_x                                        0xE6F764
#define pinstCServerListWnd_x                                      0xE6F768
#define pinstCAvaZoneWnd_x                                         0xE6F774
#define pinstCBlockedBuffWnd_x                                     0xE6F778
#define pinstCBlockedPetBuffWnd_x                                  0xE6F77C
#define pinstCInvSlotMgr_x                                         0xE6F7C4
#define pinstCContainerMgr_x                                       0xE6F7C8
#define pinstCAdventureLeaderboardWnd_x                            0x10C2DF8
#define pinstCAdventureRequestWnd_x                                0x10C2E70
#define pinstCAltStorageWnd_x                                      0x10C3150
#define pinstCAdventureStatsWnd_x                                  0x10C2EE8
#define pinstCBarterMerchantWnd_x                                  0x10C3E98
#define pinstCBarterSearchWnd_x                                    0x10C3F10
#define pinstCBarterWnd_x                                          0x10C3F88
#define pinstCChatWindowManager_x                                  0x10C4798
#define pinstCDynamicZoneWnd_x                                     0x10C4CC8
#define pinstCEQMainWnd_x                                          0x10C4E90
#define pinstCFellowshipWnd_x                                      0x10C4C5C
#define pinstCFindLocationWnd_x                                    0x10C5160
#define pinstCGroupSearchWnd_x                                     0x10C5430
#define pinstCGroupWnd_x                                           0x10C54A8
#define pinstCGuildBankWnd_x                                       0x10C5520
#define pinstCGuildMgmtWnd_x                                       0x10C7610
#define pinstCHotButtonWnd_x                                       0x10C770C
#define pinstCHotButtonWnd1_x                                      0x10C770C
#define pinstCHotButtonWnd2_x                                      0x10C7710
#define pinstCHotButtonWnd3_x                                      0x10C7714
#define pinstCHotButtonWnd4_x                                      0x10C7738
#define pinstCItemDisplayManager_x                                 0x10C7B90
#define pinstCItemExpTransferWnd_x                                 0x10C7C8C
#define pinstCLFGuildWnd_x                                         0x10C7F68
#define pinstCMIZoneSelectWnd_x                                    0x10C8548
#define pinstCConfirmationDialog_x                                 0x10C8B60
#define pinstCPopupWndManager_x                                    0x10C8B60
#define pinstCProgressionSelectionWnd_x                            0x10C8C50
#define pinstCPvPStatsWnd_x                                        0x10C8D40
#define pinstCTaskWnd_x                                            0x10CA848
#define pinstCTaskSomething_x                                      0xD3D820
#define pinstCTaskTemplateSelectWnd_x                              0x10CA7D0
#define pinstCTipWndOFDAY_x                                        0x10CA9B0
#define pinstCTipWndCONTEXT_x                                      0x10CA9B4
#define pinstCTitleWnd_x                                           0x10CAA30
#define pinstCContextMenuManager_x                                 0x1730D30
#define pinstCVoiceMacroWnd_x                                      0xFB6F80
#define pinstCHtmlWnd_x                                            0xFB7070
#define pinstItemIconCache_x                                       0x10C4E38
#define pinstCTradeskillWnd_x                                      0x10CAB30
#define pinstCAdvancedLootWnd_x                                    0xE6F7B8
#define pinstRewardSelectionWnd_x                                  0x10C9268
#define pinstEQSuiteTextureLoader_x                                0xD1AA80

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x54A230
#define __CastRay2_x                                               0x549B60
#define __HeadingDiff_x                                            0x932B60
#define __FixHeading_x                                             0x932AF0
#define __get_bearing_x                                            0x539880
#define __ConvertItemTags_x                                        0x537350
#define __ExecuteCmd_x                                             0x521C90
#define __EQGetTime_x                                              0x8A29D0
#define __get_melee_range_x                                        0x528930
#define __GetGaugeValueFromEQ_x                                    0x7B2920
#define __GetLabelFromEQ_x                                         0x7B3CF0
#define __ToggleKeyRingItem_x                                      0x48FF20
#define __GetXTargetType_x                                         0x934830
#define __LoadFrontEnd_x                                           0x63FC50
#define __NewUIINI_x                                               0x7B22F0
#define __ProcessGameEvents_x                                      0x583E10
#define __ProcessMouseEvent_x                                      0x5835B0
#define CrashDetected_x                                            0x641610
#define wwsCrashReportCheckForUploader_x                           0x8007E0
#define __AppCrashWrapper_x                                        0xC67ADC
#define __pCrashHandler_x                                          0x10D7A10
#define __CrashHandler_x                                           0x800270
#define wwsCrashReportPlatformLaunchUploader_x                     0x802A20
#define DrawNetStatus_x                                            0x5BA260
#define Util__FastTime_x                                           0x8A2670
#define Expansion_HoT_x                                            0xF317C8
#define __HelpPath_x                                               0xFB4F78
#define __STMLToText_x                                             0x8E8C00
#define __GetAnimationCache_x                                      0x6AF390

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423330
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DF90
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DD60

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D8350
#define AltAdvManager__IsAbilityReady_x                            0x4D83C0
#define AltAdvManager__GetAAById_x                                 0x4D88B0
#define AltAdvManager__CanTrainAbility_x                           0x4D94E0
#define AltAdvManager__CanSeeAbility_x                             0x4D90A0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x469AE0
#define CharacterZoneClient__HasSkill_x                            0x465B50
#define CharacterZoneClient__MakeMeVisible_x                       0x46B650
#define CharacterZoneClient__IsStackBlocked_x                      0x44BD10
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B230
#define CharacterZoneClient__GetItemCountWorn_x                    0x4640B0
#define CharacterZoneClient__GetItemCountInInventory_x             0x464190
#define CharacterZoneClient__GetCursorItemCount_x                  0x464270
#define CharacterZoneClient__FindAffectSlot_x                      0x4513C0
#define CharacterZoneClient__BardCastBard_x                        0x44A9A0
#define CharacterZoneClient__GetMaxEffects_x                       0x449530
#define CharacterZoneClient__GetEffect_x                           0x44B460
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451220
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449880
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FD70

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66F5D0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67D3A0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x598FC0
#define CButtonWnd__CButtonWnd_x                                   0x8DCE90

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6985C0
#define CChatManager__InitContextMenu_x                            0x699710
#define CChatManager__FreeChatWindow_x                             0x698070
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A1850
#define CChatManager__SetLockedActiveChatWindow_x                  0x698590

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E6F50
#define CContextMenu__dCContextMenu_x                              0x8E7160
#define CContextMenu__AddMenuItem_x                                0x8E7680
#define CContextMenu__RemoveMenuItem_x                             0x8E72E0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E7300
#define CContextMenu__CheckMenuItem_x                              0x8E7380

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D34E0
#define CContextMenuManager__RemoveMenu_x                          0x8D3870
#define CContextMenuManager__PopupMenu_x                           0x8D3CC0
#define CContextMenuManager__Flush_x                               0x8D3550
#define CContextMenuManager__GetMenu_x                             0x419490

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x886B20
#define CChatService__GetFriendName_x                              0x886B30

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69F340
#define CChatWindow__Clear_x                                       0x69EC20
#define CChatWindow__WndNotification_x                             0x69FC40

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D7320
#define CComboWnd__Draw_x                                          0x8D7530
#define CComboWnd__GetCurChoice_x                                  0x8D70D0
#define CComboWnd__GetListRect_x                                   0x8D77D0
#define CComboWnd__GetTextRect_x                                   0x8D7390
#define CComboWnd__InsertChoice_x                                  0x8D7930
#define CComboWnd__SetColors_x                                     0x8D7060
#define CComboWnd__SetChoice_x                                     0x8D7090
#define CComboWnd__GetItemCount_x                                  0x8D70C0
#define CComboWnd__GetCurChoiceText_x                              0x8D7110


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A9530
#define CContainerWnd__vftable_x                                   0xAED9F8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C61B0
#define CDisplay__GetClickedActor_x                                0x4BEA70
#define CDisplay__GetUserDefinedColor_x                            0x4BD650
#define CDisplay__GetWorldFilePath_x                               0x4BCAA0
#define CDisplay__is3dON_x                                         0x4BBF30
#define CDisplay__ReloadUI_x                                       0x4CFF70
#define CDisplay__WriteTextHD2_x                                   0x4C2540
#define CDisplay__TrueDistance_x                                   0x4BF6A0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FDF10

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EB4B0
#define CEditWnd__GetCharIndexPt_x                                 0x8EC600
#define CEditWnd__GetDisplayString_x                               0x8EB660
#define CEditWnd__GetHorzOffset_x                                  0x8EB9A0
#define CEditWnd__GetLineForPrintableChar_x                        0x8EC0D0
#define CEditWnd__GetSelStartPt_x                                  0x8EC8B0
#define CEditWnd__GetSTMLSafeText_x                                0x8EBB40
#define CEditWnd__PointFromPrintableChar_x                         0x8EC1C0
#define CEditWnd__SelectableCharFromPoint_x                        0x8EC340
#define CEditWnd__SetEditable_x                                    0x8EBB10

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56A550
#define CEverQuest__ClickedPlayer_x                                0x5640D0
#define CEverQuest__CreateTargetIndicator_x                        0x564FD0
#define CEverQuest__DeleteTargetIndicator_x                        0x565050
#define CEverQuest__DoTellWindow_x                                 0x476280
#define CEverQuest__OutputTextToLog_x                              0x475EE0
#define CEverQuest__DropHeldItemOnGround_x                         0x57AAC0
#define CEverQuest__dsp_chat_x                                     0x4765C0
#define CEverQuest__trimName_x                                     0x5609E0
#define CEverQuest__Emote_x                                        0x578DD0
#define CEverQuest__EnterZone_x                                    0x573EB0
#define CEverQuest__GetBodyTypeDesc_x                              0x55E420
#define CEverQuest__GetClassDesc_x                                 0x567970
#define CEverQuest__GetClassThreeLetterCode_x                      0x567F70
#define CEverQuest__GetDeityDesc_x                                 0x55ED00
#define CEverQuest__GetLangDesc_x                                  0x55E7B0
#define CEverQuest__GetRaceDesc_x                                  0x568130
#define CEverQuest__InterpretCmd_x                                 0x56BCD0
#define CEverQuest__LeftClickedOnPlayer_x                          0x580620
#define CEverQuest__LMouseUp_x                                     0x5825D0
#define CEverQuest__RightClickedOnPlayer_x                         0x581130
#define CEverQuest__RMouseUp_x                                     0x582030
#define CEverQuest__SetGameState_x                                 0x5649A0
#define CEverQuest__UPCNotificationFlush_x                         0x55CDB0
#define CEverQuest__IssuePetCommand_x                              0x56C6B0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BA1B0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BA210
#define CGaugeWnd__Draw_x                                          0x6BA640

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B140
#define CGuild__GetGuildName_x                                     0x43B610
#define CGuild__GetGuildIndex_x                                    0x43C820

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D6670

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E3A10
#define CInvSlotMgr__MoveItem_x                                    0x6E41D0
#define CInvSlotMgr__SelectSlot_x                                  0x6E3300

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E2760
#define CInvSlot__SliderComplete_x                                 0x6DFF90
#define CInvSlot__GetItemBase_x                                    0x6DF420
#define CInvSlot__UpdateItem_x                                     0x6DF9A0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E5620
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E6760

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AE800
#define CItemDisplayWnd__UpdateStrings_x                           0x6E7880
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F4490
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F49C0
#define CItemDisplayWnd__SetItem_x                                 0x6FA370

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E57E0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EDE30

// CLabel 
#define CLabel__Draw_x                                             0x701120

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C3090
#define CListWnd__dCListWnd_x                                      0x8C4330
#define CListWnd__AddColumn_x                                      0x8C42D0
#define CListWnd__AddColumn1_x                                     0x8C3960
#define CListWnd__AddLine_x                                        0x8C3340
#define CListWnd__AddString_x                                      0x8C3560
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C01C0
#define CListWnd__CalculateVSBRange_x                              0x8C2560
#define CListWnd__ClearSel_x                                       0x8BF4E0
#define CListWnd__ClearAllSel_x                                    0x8BF490
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C2F20
#define CListWnd__Compare_x                                        0x8C0EA0
#define CListWnd__Draw_x                                           0x8C2160
#define CListWnd__DrawColumnSeparators_x                           0x8C1FF0
#define CListWnd__DrawHeader_x                                     0x8BF7A0
#define CListWnd__DrawItem_x                                       0x8C1520
#define CListWnd__DrawLine_x                                       0x8C1C90
#define CListWnd__DrawSeparator_x                                  0x8C2090
#define CListWnd__EnableLine_x                                     0x8BF6C0
#define CListWnd__EnsureVisible_x                                  0x8C0320
#define CListWnd__ExtendSel_x                                      0x8C1430
#define CListWnd__GetColumnMinWidth_x                              0x8BEDD0
#define CListWnd__GetColumnWidth_x                                 0x8BED00
#define CListWnd__GetCurSel_x                                      0x8BE4D0
#define CListWnd__GetItemAtPoint_x                                 0x8C05B0
#define CListWnd__GetItemAtPoint1_x                                0x8C0620
#define CListWnd__GetItemData_x                                    0x8BE810
#define CListWnd__GetItemHeight_x                                  0x8BFE20
#define CListWnd__GetItemIcon_x                                    0x8BEA00
#define CListWnd__GetItemRect_x                                    0x8C03F0
#define CListWnd__GetItemText_x                                    0x8BE8B0
#define CListWnd__GetSelList_x                                     0x8C3850
#define CListWnd__GetSeparatorRect_x                               0x8C0DD0
#define CListWnd__InsertLine_x                                     0x8C3740
#define CListWnd__RemoveLine_x                                     0x8C3750
#define CListWnd__SetColors_x                                      0x8BE620
#define CListWnd__SetColumnJustification_x                         0x8BF060
#define CListWnd__SetColumnWidth_x                                 0x8BED80
#define CListWnd__SetCurSel_x                                      0x8BE510
#define CListWnd__SetItemColor_x                                   0x8C2C10
#define CListWnd__SetItemData_x                                    0x8BF540
#define CListWnd__SetItemText_x                                    0x8C2A50
#define CListWnd__ShiftColumnSeparator_x                           0x8C28E0
#define CListWnd__Sort_x                                           0x8C4430
#define CListWnd__ToggleSel_x                                      0x8BF410

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71A1B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73DB90
#define CMerchantWnd__RequestBuyItem_x                             0x747310
#define CMerchantWnd__RequestSellItem_x                            0x749A30
#define CMerchantWnd__SelectRecoverySlot_x                         0x73E130
#define CMerchantWnd__SelectBuySellSlot_x                          0x73ACD0
#define CMerchantWnd__ActualSelect_x                               0x73F0D0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x854EE0
#define CPacketScrambler__hton_x                                   0x854EF0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E1E20
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E1F00
#define CSidlManager__CreateLabel_x                                0x7A3720
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E03C0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E21E0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D9350
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D9250
#define CSidlScreenWnd__ConvertToRes_x                             0x8FDDF0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D9C40
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DADF0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DAEA0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DA390
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D95F0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D8D80
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D97E0
#define CSidlScreenWnd__Init1_x                                    0x8DAAE0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D9CF0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D8F40
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DA5D0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D89E0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D8D30
#define CSidlScreenWnd__WndNotification_x                          0x8DA860
#define CSidlScreenWnd__GetChildItem_x                             0x8D8E50
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CC790
#define CSidlScreenWnd__m_layoutCopy_x                             0x1730E50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6054D0
#define CSkillMgr__GetSkillCap_x                                   0x6056B0
#define CSkillMgr__GetNameToken_x                                  0x605080

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FD0C0
#define CSliderWnd__SetValue_x                                     0x8FD290
#define CSliderWnd__SetNumTicks_x                                  0x8FDA10

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A9A00

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F6EE0
#define CStmlWnd__CalculateHSBRange_x                              0x8EF460
#define CStmlWnd__CalculateVSBRange_x                              0x8EF3D0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EF5E0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EFDE0
#define CStmlWnd__ForceParseNow_x                                  0x8F7860
#define CStmlWnd__GetNextTagPiece_x                                0x8EFCE0
#define CStmlWnd__GetSTMLText_x                                    0x4844D0
#define CStmlWnd__GetVisibleText_x                                 0x8F0830
#define CStmlWnd__InitializeWindowVariables_x                      0x8F2DE0
#define CStmlWnd__MakeStmlColorTag_x                               0x8EE6B0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EE710
#define CStmlWnd__SetSTMLText_x                                    0x8F4630
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F6B80
#define CStmlWnd__UpdateHistoryString_x                            0x8F1760

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FAD70
#define CTabWnd__DrawCurrentPage_x                                 0x8FA600
#define CTabWnd__DrawTab_x                                         0x8FA3C0
#define CTabWnd__GetCurrentPage_x                                  0x8FA9B0
#define CTabWnd__GetPageInnerRect_x                                0x8FA0B0
#define CTabWnd__GetTabInnerRect_x                                 0x8FA2B0
#define CTabWnd__GetTabRect_x                                      0x8FA180
#define CTabWnd__InsertPage_x                                      0x8FB060
#define CTabWnd__SetPage_x                                         0x8FA9E0
#define CTabWnd__SetPageRect_x                                     0x8FACB0
#define CTabWnd__UpdatePage_x                                      0x8FB000
#define CTabWnd__GetPageFromTabIndex_x                             0x8FA310
#define CTabWnd__GetCurrentTabIndex_x                              0x8FA040

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E6910
#define CPageWnd__SetTabText_x                                     0x907140

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436CA0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D6CD0
#define CTextureFont__GetTextExtent_x                              0x8D6A30

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63DEE0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x903580

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BC780

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029D0
#define CXStr__CXStr1_x                                            0x7ED9E0
#define CXStr__CXStr3_x                                            0x89F900
#define CXStr__dCXStr_x                                            0x47C210
#define CXStr__operator_equal_x                                    0x89FA70
#define CXStr__operator_equal1_x                                   0x89FAC0
#define CXStr__operator_plus_equal1_x                              0x8A0BC0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D47D0
#define CXWnd__BringToTop_x                                        0x8CBA00
#define CXWnd__Center_x                                            0x8D1B10
#define CXWnd__ClrFocus_x                                          0x8CB5D0
#define CXWnd__Destroy_x                                           0x8D25E0
#define CXWnd__DoAllDrawing_x                                      0x8D1770
#define CXWnd__DrawChildren_x                                      0x8D1910
#define CXWnd__DrawColoredRect_x                                   0x8CBDE0
#define CXWnd__DrawTooltip_x                                       0x8CC070
#define CXWnd__DrawTooltipAtPoint_x                                0x8D06D0
#define CXWnd__GetBorderFrame_x                                    0x8CC480
#define CXWnd__GetChildWndAt_x                                     0x8D24D0
#define CXWnd__GetClientClipRect_x                                 0x8CC290
#define CXWnd__GetScreenClipRect_x                                 0x8D0DD0
#define CXWnd__GetScreenRect_x                                     0x8CC630
#define CXWnd__GetTooltipRect_x                                    0x8CBF00
#define CXWnd__GetWindowTextA_x                                    0x426F10
#define CXWnd__IsActive_x                                          0x8C70A0
#define CXWnd__IsDescendantOf_x                                    0x8CC3D0
#define CXWnd__IsReallyVisible_x                                   0x8CF710
#define CXWnd__IsType_x                                            0x8D1B80
#define CScreenPieceTemplate__IsType_x                             0x8FFCD0
#define CXWnd__Move_x                                              0x8CEDF0
#define CXWnd__Move1_x                                             0x8D1430
#define CXWnd__ProcessTransition_x                                 0x8CB9A0
#define CXWnd__Refade_x                                            0x8CB770
#define CXWnd__Resize_x                                            0x8CC6F0
#define CXWnd__Right_x                                             0x8D0BD0
#define CXWnd__SetFocus_x                                          0x8CDF40
#define CXWnd__SetFont_x                                           0x8CB620
#define CXWnd__SetKeyTooltip_x                                     0x8CC960
#define CXWnd__SetMouseOver_x                                      0x8D1120
#define CXWnd__StartFade_x                                         0x8CBA50
#define CXWnd__GetChildItem_x                                      0x8D1060
#define CXWnd__SetParent_x                                         0x8D2480

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C8930
#define CXWndManager__DrawWindows_x                                0x8C8580
#define CXWndManager__GetKeyboardFlags_x                           0x8C6C10
#define CXWndManager__HandleKeyboardMsg_x                          0x8C7530
#define CXWndManager__RemoveWnd_x                                  0x8C7230

// CDBStr
#define CDBStr__GetString_x                                        0x4BA750

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452580
#define EQ_Character__Cur_HP_x                                     0x465730
#define EQ_Character__Cur_Mana_x                                   0x45ABA0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B540
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443430
#define EQ_Character__GetFocusRangeModifier_x                      0x443580
#define EQ_Character__GetHPRegen_x                                 0x469170
#define EQ_Character__GetEnduranceRegen_x                          0x464D40
#define EQ_Character__GetManaRegen_x                               0x469710
#define EQ_Character__Max_Endurance_x                              0x5CBC50
#define EQ_Character__Max_HP_x                                     0x45D720
#define EQ_Character__Max_Mana_x                                   0x5CBA80
#define EQ_Character__doCombatAbility_x                            0x5C9150
#define EQ_Character__UseSkill_x                                   0x4706F0
#define EQ_Character__GetConLevel_x                                0x5BE8D0
#define EQ_Character__IsExpansionFlag_x                            0x4B69F0
#define EQ_Character__TotalEffect_x                                0x44F6B0
#define EQ_Character__GetPCSpellAffect_x                           0x44B8D0
#define EQ_Character__SpellDuration_x                              0x4498D0
#define EQ_Character__FindItemByRecord_x                           0x462DA0
#define EQ_Character__GetAdjustedSkill_x                           0x465900
#define EQ_Character__GetBaseSkill_x                               0x45D600

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x872D30

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D4260

//PcClient
#define PcClient__PcClient_x                                       0x5C0700

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x4469A0
#define CCharacterSelect__EnterWorld_x                             0x446170
#define CCharacterSelect__Quit_x                                   0x444D30

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59E8F0
#define EQ_Item__CreateItemTagString_x                             0x853070
#define EQ_Item__IsStackable_x                                     0x8483D0
#define EQ_Item__GetImageNum_x                                     0x84AE90
#define EQ_Item__CreateItemClient_x                                0x59F9B0
#define EQ_Item__GetItemValue_x                                    0x851AE0
#define EQ_Item__ValueSellMerchant_x                               0x854B30
#define EQ_Item__IsKeyRingItem_x                                   0x848E60
#define EQ_Item__CanGoInBag_x                                      0x59EA80
#define EQ_Item__GetMaxItemCount_x                                 0x8482C0
#define EQ_Item__GetHeldItem_x                                     0x849C90
#define EQ_Item__GetAugmentFitBySlot_x                             0x854950

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA930
#define EQ_LoadingS__Array_x                                       0xC0BC78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CE170
#define EQ_PC__GetAlternateAbilityId_x                             0x85CED0
#define EQ_PC__GetCombatAbility_x                                  0x85CF60
#define EQ_PC__GetCombatAbilityTimer_x                             0x857B90
#define EQ_PC__GetItemRecastTimer_x                                0x5C7900
#define EQ_PC__HasLoreItem_x                                       0x5C1EC0
#define EQ_PC__AlertInventoryChanged_x                             0x5BE880
#define EQ_PC__GetPcZoneClient_x                                   0x5E8780
#define EQ_PC__RemoveMyAffect_x                                    0x5C6D60
#define EQ_PC__GetKeyRingItems_x                                   0x857FB0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86ABB0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85EE40

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5269E0
#define EQItemList__add_object_x                                   0x553D30
#define EQItemList__add_item_x                                     0x526920
#define EQItemList__delete_item_x                                  0x526DD0
#define EQItemList__FreeItemList_x                                 0x526CD0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B99B0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D4000
#define EQPlayer__dEQPlayer_x                                      0x5DC6D0
#define EQPlayer__DoAttack_x                                       0x5EE0F0
#define EQPlayer__EQPlayer_x                                       0x5DEDF0
#define EQPlayer__SetNameSpriteState_x                             0x5D9500
#define EQPlayer__SetNameSpriteTint_x                              0x5D5420
#define PlayerBase__HasProperty_j_x                                0x930F60
#define EQPlayer__IsTargetable_x                                   0x931200
#define EQPlayer__CanSee_x                                         0x931760
#define PlayerZoneClient__ChangeHeight_x                           0x5EDFB0
#define EQPlayer__CanSee1_x                                        0x931850
#define PlayerBase__GetVisibilityLineSegment_x                     0x9314F0

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E8930
#define PlayerZoneClient__IsValidTeleport_x                        0x5545D0
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2B60


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E2DC0
#define EQPlayerManager__GetSpawnByName_x                          0x5E3220
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E2DF0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A4FD0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A5010
#define KeypressHandler__ClearCommandStateArray_x                  0x5A4BC0
#define KeypressHandler__HandleKeyDown_x                           0x5A34E0
#define KeypressHandler__HandleKeyUp_x                             0x5A3800
#define KeypressHandler__SaveKeymapping_x                          0x5A4C90

// MapViewMap 
#define MapViewMap__Clear_x                                        0x712B40
#define MapViewMap__SaveEx_x                                       0x715E70

#define PlayerPointManager__GetAltCurrency_x                       0x870DF0

// StringTable 
#define StringTable__getString_x                                   0x86AEE0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CB6E0
#define PcZoneClient__RemovePetEffect_x                            0x5C7DD0
#define PcZoneClient__HasAlternateAbility_x                        0x5C8770
#define PcZoneClient__GetCurrentMod_x                              0x45CBD0
#define PcZoneClient__GetModCap_x                                  0x45A300
#define PcZoneClient__CanEquipItem_x                               0x5C8C90
#define PcZoneClient__GetItemByID_x                                0x5CD4F0
#define PcZoneClient__GetItemByItemClass_x                         0x5CE090
#define PcZoneClient__RemoveBuffEffect_x                           0x5C7010

//Doors
#define EQSwitch__UseSwitch_x                                      0x55B710

//IconCache
#define IconCache__GetIcon_x                                       0x6AF9C0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A68D0
#define CContainerMgr__CloseContainer_x                            0x6A70F0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x773780

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5979F0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F5060
#define EQ_Spell__SpellAffects_x                                   0x4F2250
#define EQ_Spell__SpellAffectBase_x                           0x4F22C0
#define CharacterZoneClient__CalcAffectChange_x                    0x44B760
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AA00
#define CLootWnd__LootAll_x                                        0x708390
#define CLootWnd__RequestLootSlot_x                                0x708BA0
#define EQ_Spell__IsStackable_x                                    0x4492F0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4493A0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EC20
#define EQ_Spell__IsSPAStacking_x                                  0x4F1DC0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2E60
#define EQ_Spell__IsNoRemove_x                                     0x434CE0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F1DE0

#define __IsResEffectSpell_x                                       0x449420

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87C9A0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BB3D0
#define CTargetWnd__WndNotification_x                              0x7BAEC0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BB5B0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C04F0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED900
#define EqSoundManager__PlayScriptMp3_x                            0x4EF3A0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8A70

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EAAE0
#define CSidlManager__FindAnimation1_x                             0x8DFDF0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E2260
#define CAltAbilityData__GetMercMaxRank_x                          0x4E2210
#define CAltAbilityData__GetMaxRank_x                              0x4D6A00

//CTargetRing
#define CTargetRing__Cast_x                                        0x595630

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459340
#define CharacterBase__CreateItemGlobalIndex_x                     0x475470
#define CharacterBase__CreateItemIndex_x                           0x51FFE0
#define CharacterBase__GetItemPossession_x                         0x4441D0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8807F0
#define CharacterBase__GetEffectId_x                               0x459300

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68F6D0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68EE30

//messages
#define msg_spell_worn_off_x                                       0x4FCAA0
#define msg_new_text_x                                             0x506220
#define msgTokenTextParam_x                                        0x502A20

//SpellManager
#define SpellManager__vftable_x                                    0xAC9288
#define SpellManager__SpellManager_x                               0x47E140
#define Spellmanager__LoadTextSpells_x                             0x60C350

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x935350

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487F20
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EB40
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449090
#define ItemGlobalIndex__IsValidIndex_x                            0x458BD0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87E660
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87D5A0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x701370

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AB5F0
#define CCursorAttachment__Deactivate_x                            0x6AAB40

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FC5C0
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FC740

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                        0x603F60

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C7A0

//IString
#define IString__Append_x                                          0x47ED70

//Camera
#define CDisplay__cameraType_x                                     0xE6F7E0
#define EverQuest__Cameras_x                                       0xF31AE0
