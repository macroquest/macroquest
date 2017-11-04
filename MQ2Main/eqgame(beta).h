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
#define __ExpectedVersionDate                                     "Nov  3 2017"
#define __ExpectedVersionTime                                     "04:15:56"
#define __ActualVersionDate_x                                      0xAE4110
#define __ActualVersionTime_x                                      0xAE411C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5AA530
#define __MemChecker1_x                                            0x8A3370
#define __MemChecker2_x                                            0x63FFC0
#define __MemChecker3_x                                            0x63FF10
#define __MemChecker4_x                                            0x7F4790
#define __EncryptPad0_x                                            0xC3F000
#define __EncryptPad1_x                                            0xD18BB8
#define __EncryptPad2_x                                            0xC67EE8
#define __EncryptPad3_x                                            0xC67AE8
#define __EncryptPad4_x                                            0xD071B8
#define __EncryptPad5_x                                            0x10C22F0
#define __AC1_x                                                    0x7B3B55
#define __AC2_x                                                    0x563837
#define __AC3_x                                                    0x5619B0
#define __AC4_x                                                    0x573BD1
#define __AC5_x                                                    0x58792B
#define __AC6_x                                                    0x58B4DE
#define __AC7_x                                                    0x581F2C
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
#define __do_loot_x                                                0x5325A0
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
#define __CastRay_x                                                0x54A0B0
#define __CastRay2_x                                               0x5499E0
#define __HeadingDiff_x                                            0x9334F0
#define __FixHeading_x                                             0x933480
#define __get_bearing_x                                            0x5396F0
#define __ConvertItemTags_x                                        0x5371C0
#define __ExecuteCmd_x                                             0x521B70
#define __EQGetTime_x                                              0x8A2D10
#define __get_melee_range_x                                        0x5287C0
#define __GetGaugeValueFromEQ_x                                    0x7B2710
#define __GetLabelFromEQ_x                                         0x7B3AE0
#define __ToggleKeyRingItem_x                                      0x48FEF0
#define __GetXTargetType_x                                         0x9350F0
#define __LoadFrontEnd_x                                           0x63F690
#define __NewUIINI_x                                               0x7B20F0
#define __ProcessGameEvents_x                                      0x583CC0
#define __ProcessMouseEvent_x                                      0x583460
#define CrashDetected_x                                            0x641050
#define wwsCrashReportCheckForUploader_x                           0x8007E0
#define __AppCrashWrapper_x                                        0xC67ADC
#define __pCrashHandler_x                                          0x10D7A10
#define __CrashHandler_x                                           0x800270
#define wwsCrashReportPlatformLaunchUploader_x                     0x802A20
#define DrawNetStatus_x                                            0x5BA040
#define Util__FastTime_x                                           0x8A29B0
#define Expansion_HoT_x                                            0xF317C8
#define __HelpPath_x                                               0xFB4F78
#define __STMLToText_x                                             0x8E90E0
#define __GetAnimationCache_x                                      0x6AEE30

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423390
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DFF0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DDC0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D8320
#define AltAdvManager__IsAbilityReady_x                            0x4D8390
#define AltAdvManager__GetAAById_x                                 0x4D8880
#define AltAdvManager__CanTrainAbility_x                           0x4D94B0
#define AltAdvManager__CanSeeAbility_x                             0x4D9070

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x469A90
#define CharacterZoneClient__HasSkill_x                            0x465B00
#define CharacterZoneClient__MakeMeVisible_x                       0x46B600
#define CharacterZoneClient__IsStackBlocked_x                      0x44BC50
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B170
#define CharacterZoneClient__GetItemCountWorn_x                    0x464060
#define CharacterZoneClient__GetItemCountInInventory_x             0x464140
#define CharacterZoneClient__GetCursorItemCount_x                  0x464220
#define CharacterZoneClient__FindAffectSlot_x                      0x451300
#define CharacterZoneClient__BardCastBard_x                        0x44A8E0
#define CharacterZoneClient__GetMaxEffects_x                       0x449470
#define CharacterZoneClient__GetEffect_x                           0x44B3A0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451160
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4497C0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FCB0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66F080

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67CCF0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x598D80
#define CButtonWnd__CButtonWnd_x                                   0x8DD3E0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x698000
#define CChatManager__InitContextMenu_x                            0x699150
#define CChatManager__FreeChatWindow_x                             0x697AB0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A12F0
#define CChatManager__SetLockedActiveChatWindow_x                  0x697FD0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E7430
#define CContextMenu__dCContextMenu_x                              0x8E7640
#define CContextMenu__AddMenuItem_x                                0x8E7B60
#define CContextMenu__RemoveMenuItem_x                             0x8E77C0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E77E0
#define CContextMenu__CheckMenuItem_x                              0x8E7860

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D39C0
#define CContextMenuManager__RemoveMenu_x                          0x8D3D70
#define CContextMenuManager__PopupMenu_x                           0x8D41C0
#define CContextMenuManager__Flush_x                               0x8D3A30
#define CContextMenuManager__GetMenu_x                             0x419510

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x886E20
#define CChatService__GetFriendName_x                              0x886E30

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69EDC0
#define CChatWindow__Clear_x                                       0x69E6A0
#define CChatWindow__WndNotification_x                             0x69F6D0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D7830
#define CComboWnd__Draw_x                                          0x8D7A40
#define CComboWnd__GetCurChoice_x                                  0x8D75E0
#define CComboWnd__GetListRect_x                                   0x8D7CE0
#define CComboWnd__GetTextRect_x                                   0x8D78A0
#define CComboWnd__InsertChoice_x                                  0x8D7E40
#define CComboWnd__SetColors_x                                     0x8D7570
#define CComboWnd__SetChoice_x                                     0x8D75A0
#define CComboWnd__GetItemCount_x                                  0x8D75D0
#define CComboWnd__GetCurChoiceText_x                              0x8D7620


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A8FD0
#define CContainerWnd__vftable_x                                   0xAEDA20

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
#define CEditBaseWnd__SetSel_x                                     0x8FE5E0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EB990
#define CEditWnd__GetCharIndexPt_x                                 0x8ECAF0
#define CEditWnd__GetDisplayString_x                               0x8EBB40
#define CEditWnd__GetHorzOffset_x                                  0x8EBE80
#define CEditWnd__GetLineForPrintableChar_x                        0x8EC5B0
#define CEditWnd__GetSelStartPt_x                                  0x8ECDB0
#define CEditWnd__GetSTMLSafeText_x                                0x8EC020
#define CEditWnd__PointFromPrintableChar_x                         0x8EC6A0
#define CEditWnd__SelectableCharFromPoint_x                        0x8EC820
#define CEditWnd__SetEditable_x                                    0x8EBFF0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56A400
#define CEverQuest__ClickedPlayer_x                                0x563F80
#define CEverQuest__CreateTargetIndicator_x                        0x564E80
#define CEverQuest__DeleteTargetIndicator_x                        0x564F00
#define CEverQuest__DoTellWindow_x                                 0x476210
#define CEverQuest__OutputTextToLog_x                              0x475E70
#define CEverQuest__DropHeldItemOnGround_x                         0x57A970
#define CEverQuest__dsp_chat_x                                     0x476550
#define CEverQuest__trimName_x                                     0x560890
#define CEverQuest__Emote_x                                        0x578C80
#define CEverQuest__EnterZone_x                                    0x573D60
#define CEverQuest__GetBodyTypeDesc_x                              0x55E2D0
#define CEverQuest__GetClassDesc_x                                 0x567820
#define CEverQuest__GetClassThreeLetterCode_x                      0x567E20
#define CEverQuest__GetDeityDesc_x                                 0x55EBB0
#define CEverQuest__GetLangDesc_x                                  0x55E660
#define CEverQuest__GetRaceDesc_x                                  0x567FE0
#define CEverQuest__InterpretCmd_x                                 0x56BB80
#define CEverQuest__LeftClickedOnPlayer_x                          0x5804D0
#define CEverQuest__LMouseUp_x                                     0x582480
#define CEverQuest__RightClickedOnPlayer_x                         0x580FE0
#define CEverQuest__RMouseUp_x                                     0x581EE0
#define CEverQuest__SetGameState_x                                 0x564850
#define CEverQuest__UPCNotificationFlush_x                         0x55CC60
#define CEverQuest__IssuePetCommand_x                              0x56C560

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B9C50
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B9CB0
#define CGaugeWnd__Draw_x                                          0x6BA0E0

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B1C0
#define CGuild__GetGuildName_x                                     0x43B690
#define CGuild__GetGuildIndex_x                                    0x43C8A0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D6150

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E34E0
#define CInvSlotMgr__MoveItem_x                                    0x6E3CA0
#define CInvSlotMgr__SelectSlot_x                                  0x6E2DE0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E2240
#define CInvSlot__SliderComplete_x                                 0x6DFA60
#define CInvSlot__GetItemBase_x                                    0x6DEEF0
#define CInvSlot__UpdateItem_x                                     0x6DF470

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E5100
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E6240

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AE640
#define CItemDisplayWnd__UpdateStrings_x                           0x6E7350
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F3F80
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F44B0
#define CItemDisplayWnd__SetItem_x                                 0x6F9E30

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E5530

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6ED910

// CLabel 
#define CLabel__Draw_x                                             0x700C20

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C3420
#define CListWnd__dCListWnd_x                                      0x8C46C0
#define CListWnd__AddColumn_x                                      0x8C4660
#define CListWnd__AddColumn1_x                                     0x8C3D00
#define CListWnd__AddLine_x                                        0x8C36E0
#define CListWnd__AddString_x                                      0x8C3900
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C0520
#define CListWnd__CalculateVSBRange_x                              0x8C28E0
#define CListWnd__ClearSel_x                                       0x8BF840
#define CListWnd__ClearAllSel_x                                    0x8BF7F0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C32B0
#define CListWnd__Compare_x                                        0x8C1210
#define CListWnd__Draw_x                                           0x8C24E0
#define CListWnd__DrawColumnSeparators_x                           0x8C2370
#define CListWnd__DrawHeader_x                                     0x8BFB00
#define CListWnd__DrawItem_x                                       0x8C18A0
#define CListWnd__DrawLine_x                                       0x8C2010
#define CListWnd__DrawSeparator_x                                  0x8C2410
#define CListWnd__EnableLine_x                                     0x8BFA20
#define CListWnd__EnsureVisible_x                                  0x8C0680
#define CListWnd__ExtendSel_x                                      0x8C17B0
#define CListWnd__GetColumnMinWidth_x                              0x8BF130
#define CListWnd__GetColumnWidth_x                                 0x8BF060
#define CListWnd__GetCurSel_x                                      0x8BE840
#define CListWnd__GetItemAtPoint_x                                 0x8C0920
#define CListWnd__GetItemAtPoint1_x                                0x8C0990
#define CListWnd__GetItemData_x                                    0x8BEB80
#define CListWnd__GetItemHeight_x                                  0x8C0180
#define CListWnd__GetItemIcon_x                                    0x8BED70
#define CListWnd__GetItemRect_x                                    0x8C0760
#define CListWnd__GetItemText_x                                    0x8BEC20
#define CListWnd__GetSelList_x                                     0x8C3BF0
#define CListWnd__GetSeparatorRect_x                               0x8C1140
#define CListWnd__InsertLine_x                                     0x8C3AE0
#define CListWnd__RemoveLine_x                                     0x8C3AF0
#define CListWnd__SetColors_x                                      0x8BE990
#define CListWnd__SetColumnJustification_x                         0x8BF3C0
#define CListWnd__SetColumnWidth_x                                 0x8BF0E0
#define CListWnd__SetCurSel_x                                      0x8BE880
#define CListWnd__SetItemColor_x                                   0x8C2FA0
#define CListWnd__SetItemData_x                                    0x8BF8A0
#define CListWnd__SetItemText_x                                    0x8C2DE0
#define CListWnd__ShiftColumnSeparator_x                           0x8C2C70
#define CListWnd__Sort_x                                           0x8C47C0
#define CListWnd__ToggleSel_x                                      0x8BF770

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x719C80

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73D610
#define CMerchantWnd__RequestBuyItem_x                             0x746D70
#define CMerchantWnd__RequestSellItem_x                            0x749490
#define CMerchantWnd__SelectRecoverySlot_x                         0x73DBB0
#define CMerchantWnd__SelectBuySellSlot_x                          0x73AA00
#define CMerchantWnd__ActualSelect_x                               0x73EB40

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x855120
#define CPacketScrambler__hton_x                                   0x855130

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E2350
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E2430
#define CSidlManager__CreateLabel_x                                0x7A33A0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E08E0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E2710

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D9880
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D9770
#define CSidlScreenWnd__ConvertToRes_x                             0x8FE4C0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8DA170
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DB360
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DB410
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DA8D0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D9B20
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D92A0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D9D10
#define CSidlScreenWnd__Init1_x                                    0x8DB030
#define CSidlScreenWnd__LoadIniInfo_x                              0x8DA230
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D9460
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DAB10
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D8F00
#define CSidlScreenWnd__StoreIniVis_x                              0x8D9250
#define CSidlScreenWnd__WndNotification_x                          0x8DADB0
#define CSidlScreenWnd__GetChildItem_x                             0x8D9370
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CCC10
#define CSidlScreenWnd__m_layoutCopy_x                             0x1730E50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x605160
#define CSkillMgr__GetSkillCap_x                                   0x605340
#define CSkillMgr__GetNameToken_x                                  0x604D10

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FD770
#define CSliderWnd__SetValue_x                                     0x8FD940
#define CSliderWnd__SetNumTicks_x                                  0x8FE0C0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A9870

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F7410
#define CStmlWnd__CalculateHSBRange_x                              0x8EF990
#define CStmlWnd__CalculateVSBRange_x                              0x8EF900
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EFB00
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F0300
#define CStmlWnd__ForceParseNow_x                                  0x8F7DD0
#define CStmlWnd__GetNextTagPiece_x                                0x8F0200
#define CStmlWnd__GetSTMLText_x                                    0x4843A0
#define CStmlWnd__GetVisibleText_x                                 0x8F0D50
#define CStmlWnd__InitializeWindowVariables_x                      0x8F3300
#define CStmlWnd__MakeStmlColorTag_x                               0x8EEBE0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EEC40
#define CStmlWnd__SetSTMLText_x                                    0x8F4B50
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F70B0
#define CStmlWnd__UpdateHistoryString_x                            0x8F1C80

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FB2F0
#define CTabWnd__DrawCurrentPage_x                                 0x8FAB80
#define CTabWnd__DrawTab_x                                         0x8FA940
#define CTabWnd__GetCurrentPage_x                                  0x8FAF30
#define CTabWnd__GetPageInnerRect_x                                0x8FA630
#define CTabWnd__GetTabInnerRect_x                                 0x8FA830
#define CTabWnd__GetTabRect_x                                      0x8FA700
#define CTabWnd__InsertPage_x                                      0x8FB5E0
#define CTabWnd__SetPage_x                                         0x8FAF60
#define CTabWnd__SetPageRect_x                                     0x8FB230
#define CTabWnd__UpdatePage_x                                      0x8FB580
#define CTabWnd__GetPageFromTabIndex_x                             0x8FA890
#define CTabWnd__GetCurrentTabIndex_x                              0x8FA5C0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E63F0
#define CPageWnd__SetTabText_x                                     0x9077D0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436D30

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D71E0
#define CTextureFont__GetTextExtent_x                              0x8D6F40

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63D930

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x903C10

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BC890

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402A20
#define CXStr__CXStr1_x                                            0x4F90D0
#define CXStr__CXStr3_x                                            0x89FC00
#define CXStr__dCXStr_x                                            0x750CA0
#define CXStr__operator_equal_x                                    0x89FD70
#define CXStr__operator_equal1_x                                   0x89FDC0
#define CXStr__operator_plus_equal1_x                              0x8A0EC0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D4CF0
#define CXWnd__BringToTop_x                                        0x8CBE00
#define CXWnd__Center_x                                            0x8D1FE0
#define CXWnd__ClrFocus_x                                          0x8CB9E0
#define CXWnd__Destroy_x                                           0x8D2AC0
#define CXWnd__DoAllDrawing_x                                      0x8D1C30
#define CXWnd__DrawChildren_x                                      0x8D1DD0
#define CXWnd__DrawColoredRect_x                                   0x8CC1E0
#define CXWnd__DrawTooltip_x                                       0x8CC480
#define CXWnd__DrawTooltipAtPoint_x                                0x8D0BA0
#define CXWnd__GetBorderFrame_x                                    0x8CC8E0
#define CXWnd__GetChildWndAt_x                                     0x8D29A0
#define CXWnd__GetClientClipRect_x                                 0x8CC690
#define CXWnd__GetScreenClipRect_x                                 0x8D12A0
#define CXWnd__GetScreenRect_x                                     0x8CCAB0
#define CXWnd__GetTooltipRect_x                                    0x8CC310
#define CXWnd__GetWindowTextA_x                                    0x426E00
#define CXWnd__IsActive_x                                          0x8C7460
#define CXWnd__IsDescendantOf_x                                    0x8CC820
#define CXWnd__IsReallyVisible_x                                   0x8CFBF0
#define CXWnd__IsType_x                                            0x8D2050
#define CScreenPieceTemplate__IsType_x                             0x900340
#define CXWnd__Move_x                                              0x8CF2D0
#define CXWnd__Move1_x                                             0x8D18D0
#define CXWnd__ProcessTransition_x                                 0x8CBDA0
#define CXWnd__Refade_x                                            0x8CBB80
#define CXWnd__Resize_x                                            0x8CCB70
#define CXWnd__Right_x                                             0x8D10A0
#define CXWnd__SetFocus_x                                          0x8CE450
#define CXWnd__SetFont_x                                           0x8CBA30
#define CXWnd__SetKeyTooltip_x                                     0x8CCDE0
#define CXWnd__SetMouseOver_x                                      0x8D15E0
#define CXWnd__StartFade_x                                         0x8CBE50
#define CXWnd__GetChildItem_x                                      0x8D1520
#define CXWnd__SetParent_x                                         0x8D2950

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C8D10
#define CXWndManager__DrawWindows_x                                0x8C8950
#define CXWndManager__GetKeyboardFlags_x                           0x8C6FA0
#define CXWndManager__HandleKeyboardMsg_x                          0x8C78F0
#define CXWndManager__RemoveWnd_x                                  0x8C75F0

// CDBStr
#define CDBStr__GetString_x                                        0x4BA7A0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4524C0
#define EQ_Character__Cur_HP_x                                     0x4656E0
#define EQ_Character__Cur_Mana_x                                   0x45AB20
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B480
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443490
#define EQ_Character__GetFocusRangeModifier_x                      0x4435E0
#define EQ_Character__GetHPRegen_x                                 0x469120
#define EQ_Character__GetEnduranceRegen_x                          0x464CF0
#define EQ_Character__GetManaRegen_x                               0x4696C0
#define EQ_Character__Max_Endurance_x                              0x5CB990
#define EQ_Character__Max_HP_x                                     0x45D6A0
#define EQ_Character__Max_Mana_x                                   0x5CB7C0
#define EQ_Character__doCombatAbility_x                            0x5C8E90
#define EQ_Character__UseSkill_x                                   0x4706A0
#define EQ_Character__GetConLevel_x                                0x5BE630
#define EQ_Character__IsExpansionFlag_x                            0x4B6AC0
#define EQ_Character__TotalEffect_x                                0x44F5F0
#define EQ_Character__GetPCSpellAffect_x                           0x44B810
#define EQ_Character__SpellDuration_x                              0x449810
#define EQ_Character__FindItemByRecord_x                           0x462D30
#define EQ_Character__GetAdjustedSkill_x                           0x4658B0
#define EQ_Character__GetBaseSkill_x                               0x45D580

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x872FB0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D3F40

//PcClient
#define PcClient__PcClient_x                                       0x5C0470

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446920
#define CCharacterSelect__EnterWorld_x                             0x4460F0
#define CCharacterSelect__Quit_x                                   0x444CB0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59E740
#define EQ_Item__CreateItemTagString_x                             0x8532C0
#define EQ_Item__IsStackable_x                                     0x8485F0
#define EQ_Item__GetImageNum_x                                     0x84B0C0
#define EQ_Item__CreateItemClient_x                                0x59F820
#define EQ_Item__GetItemValue_x                                    0x851D20
#define EQ_Item__ValueSellMerchant_x                               0x854D70
#define EQ_Item__IsKeyRingItem_x                                   0x8490B0
#define EQ_Item__CanGoInBag_x                                      0x59E8D0
#define EQ_Item__GetMaxItemCount_x                                 0x8484E0
#define EQ_Item__GetHeldItem_x                                     0x849EE0
#define EQ_Item__GetAugmentFitBySlot_x                             0x854B90

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA8F0
#define EQ_LoadingS__Array_x                                       0xC0BC78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CDEB0
#define EQ_PC__GetAlternateAbilityId_x                             0x85D260
#define EQ_PC__GetCombatAbility_x                                  0x85D2F0
#define EQ_PC__GetCombatAbilityTimer_x                             0x857DD0
#define EQ_PC__GetItemRecastTimer_x                                0x5C7640
#define EQ_PC__HasLoreItem_x                                       0x5C1C30
#define EQ_PC__AlertInventoryChanged_x                             0x5BE5E0
#define EQ_PC__GetPcZoneClient_x                                   0x5E8460
#define EQ_PC__RemoveMyAffect_x                                    0x5C6AA0
#define EQ_PC__GetKeyRingItems_x                                   0x8581F0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86AF90
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85F200

// EQItemList 
#define EQItemList__EQItemList_x                                   0x526890
#define EQItemList__add_object_x                                   0x553BE0
#define EQItemList__add_item_x                                     0x5267D0
#define EQItemList__delete_item_x                                  0x526C80
#define EQItemList__FreeItemList_x                                 0x526B80

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9A60

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D3CE0
#define EQPlayer__dEQPlayer_x                                      0x5DC380
#define EQPlayer__DoAttack_x                                       0x5EDDE0
#define EQPlayer__EQPlayer_x                                       0x5DEAB0
#define EQPlayer__SetNameSpriteState_x                             0x5D91E0
#define EQPlayer__SetNameSpriteTint_x                              0x5D5100
#define PlayerBase__HasProperty_j_x                                0x931900
#define EQPlayer__IsTargetable_x                                   0x931BA0
#define EQPlayer__CanSee_x                                         0x932100
#define PlayerZoneClient__ChangeHeight_x                           0x5EDCA0
#define EQPlayer__CanSee1_x                                        0x9321F0
#define PlayerBase__GetVisibilityLineSegment_x                     0x931E90

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E8610
#define PlayerZoneClient__IsValidTeleport_x                        0x554480
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2B60


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E2AA0
#define EQPlayerManager__GetSpawnByName_x                          0x5E2F00
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E2AD0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A4D40
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A4D80
#define KeypressHandler__ClearCommandStateArray_x                  0x5A4930
#define KeypressHandler__HandleKeyDown_x                           0x5A3250
#define KeypressHandler__HandleKeyUp_x                             0x5A3570
#define KeypressHandler__SaveKeymapping_x                          0x5A4A00

// MapViewMap 
#define MapViewMap__Clear_x                                        0x712610
#define MapViewMap__SaveEx_x                                       0x715940

#define PlayerPointManager__GetAltCurrency_x                       0x871070

// StringTable 
#define StringTable__getString_x                                   0x86B2C0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CB420
#define PcZoneClient__RemovePetEffect_x                            0x5C7B10
#define PcZoneClient__HasAlternateAbility_x                        0x5C84B0
#define PcZoneClient__GetCurrentMod_x                              0x45CB50
#define PcZoneClient__GetModCap_x                                  0x45A280
#define PcZoneClient__CanEquipItem_x                               0x5C89D0
#define PcZoneClient__GetItemByID_x                                0x5CD230
#define PcZoneClient__GetItemByItemClass_x                         0x5CDDD0
#define PcZoneClient__RemoveBuffEffect_x                           0x5C6D50

//Doors
#define EQSwitch__UseSwitch_x                                      0x55B5C0

//IconCache
#define IconCache__GetIcon_x                                       0x6AF460

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A6370
#define CContainerMgr__CloseContainer_x                            0x6A6B90

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x773320

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x597780

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F4F40
#define EQ_Spell__SpellAffects_x                                   0x4F2130
#define EQ_Spell__SpellAffectBase_x                           0x4F21A0
#define CharacterZoneClient__CalcAffectChange_x                    0x44B6A0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44A940
#define CLootWnd__LootAll_x                                        0x707E60
#define CLootWnd__RequestLootSlot_x                                0x708670
#define EQ_Spell__IsStackable_x                                    0x449230
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4492E0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EC80
#define EQ_Spell__IsSPAStacking_x                                  0x4F1CA0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2D40
#define EQ_Spell__IsNoRemove_x                                     0x434D60
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F1CC0

#define __IsResEffectSpell_x                                       0x449360

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87CC60

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BB1C0
#define CTargetWnd__WndNotification_x                              0x7BACB0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BB3A0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C02F0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED810
#define EqSoundManager__PlayScriptMp3_x                            0x4EF2B0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8B90

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EAFC0
#define CSidlManager__FindAnimation1_x                             0x8E0310

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E2220
#define CAltAbilityData__GetMercMaxRank_x                          0x4E21D0
#define CAltAbilityData__GetMaxRank_x                              0x4D69D0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5953C0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459270
#define CharacterBase__CreateItemGlobalIndex_x                     0x475430
#define CharacterBase__CreateItemIndex_x                           0x51FEB0
#define CharacterBase__GetItemPossession_x                         0x4441B0
#define CharacterBase__GetItemByGlobalIndex_x                      0x880AB0
#define CharacterBase__GetEffectId_x                               0x459230

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68F1E0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68E940

//messages
#define msg_spell_worn_off_x                                       0x4FCAC0
#define msg_new_text_x                                             0x506240
#define msgTokenTextParam_x                                        0x502A40

//SpellManager
#define SpellManager__vftable_x                                    0xAC9278
#define SpellManager__SpellManager_x                               0x47DFD0
#define Spellmanager__LoadTextSpells_x          0x60BFF0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x935C10

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487E60
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EBA0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x448FF0
#define ItemGlobalIndex__IsValidIndex_x                            0x458B10

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87E920
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87D860

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x700E70

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AB0A0
#define CCursorAttachment__Deactivate_x                            0x6AA5E0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FCC70
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FCDF0

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                        0x603CF0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C6D0

//IString
#define IString__Append_x                                          0x47EC80

//Camera
#define CDisplay__cameraType_x                                     0xE6F7E0
#define EverQuest__Cameras_x                                       0xF31AE0
