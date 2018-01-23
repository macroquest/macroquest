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
#define __ExpectedVersionDate                                     "Jan 22 2018"
#define __ExpectedVersionTime                                     "10:35:37"
#define __ActualVersionDate_x                                      0xAE60B8
#define __ActualVersionTime_x                                      0xAE60C4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x5AA3C0
#define __MemChecker1_x                                            0x8A48F0
#define __MemChecker2_x                                            0x640350
#define __MemChecker3_x                                            0x6402A0
#define __MemChecker4_x                                            0x7F5F70
#define __EncryptPad0_x                                            0xC40FE8
#define __EncryptPad1_x                                            0xD1ABA0
#define __EncryptPad2_x                                            0xC69ED0
#define __EncryptPad3_x                                            0xC69AD0
#define __EncryptPad4_x                                            0xD091A0
#define __EncryptPad5_x                                            0x10C42E0
#define __AC1_x                                                    0x7B40C5
#define __AC2_x                                                    0x563507
#define __AC3_x                                                    0x561680
#define __AC4_x                                                    0x5738E1
#define __AC5_x                                                    0x58768B
#define __AC6_x                                                    0x58B24E
#define __AC7_x                                                    0x581C8C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FACEE0

// Direct Input
#define DI8__Main_x                                                0x10C42B8
#define DI8__Keyboard_x                                            0x10C42BC
#define DI8__Mouse_x                                               0x10C42C0
#define DI8__Mouse_Copy_x                                          0xF32474
#define DI8__Mouse_Check_x                                         0xFBBFA4
#define __AutoSkillArray_x                                         0xF33388
#define __Attack_x                                                 0xFB6A7B
#define __Autofire_x                                               0xFB6A7C
#define __BindList_x                                               0xC1D368
#define g_eqCommandStates_x                                        0xF211C0
#define __Clicks_x                                                 0xF32530
#define __CommandList_x                                            0xC1FA80
#define __CurrentMapLabel_x                                        0x10CA2B0
#define __CurrentSocial_x                                          0xBEC8E8
#define __DoAbilityList_x                                          0xF68C40
#define __do_loot_x                                                0x5324D0
#define __DrawHandler_x                                            0x1733F5C
#define __GroupCount_x                                             0xF22ACA

#define __Guilds_x                                                 0xF286E0
#define __gWorld_x                                                 0xF24F84
#define __HotkeyPage_x                                             0xFAF640
#define __HWnd_x                                                   0xFBC0C0
#define __InChatMode_x                                             0xF3245C
#define __LastTell_x                                               0xF3433C
#define __LMouseHeldTime_x                                         0xF3259C
#define __Mouse_x                                                  0x10C42C4
#define __MouseLook_x                                              0xF324F6
#define __MouseEventTime_x                                         0xFB7214
#define __gpbCommandEvent_x                                        0xF2504C
#define __NetStatusToggle_x                                        0xF324F9
#define __PCNames_x                                                0xF33944
#define __RangeAttackReady_x                                       0xF3366C
#define __RMouseHeldTime_x                                         0xF32598
#define __RunWalkState_x                                           0xF32460
#define __ScreenMode_x                                             0xE70DA0
#define __ScreenX_x                                                0xF32414
#define __ScreenY_x                                                0xF32410
#define __ScreenXMax_x                                             0xF32418
#define __ScreenYMax_x                                             0xF3241C
#define __ServerHost_x                                             0xF22A14
#define __ServerName_x                                             0xF68C00
#define __ShiftKeyDown_x                                           0xF32AF0
#define __ShowNames_x                                              0xF33824
#define __Socials_x                                                0xF68D00
#define __SubscriptionType_x                                       0x10FAA34
#define __TargetAggroHolder_x                                      0x10CC40C
#define __ZoneType_x                                               0xF328F4
#define __GroupAggro_x                                             0x10CC44C
#define __LoginName_x                                              0xFBAB9C
#define __Inviter_x                                                0xFB69F8
#define __AttackOnAssist_x                                         0xF337E0
#define __UseTellWindows_x                                         0xF33ADC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF25070
#define instEQZoneInfo_x                                           0xF326EC
#define instKeypressHandler_x                                      0xFB71F8
#define pinstActiveBanker_x                                        0xF25028
#define pinstActiveCorpse_x                                        0xF2502C
#define pinstActiveGMaster_x                                       0xF25030
#define pinstActiveMerchant_x                                      0xF25024
#define pinstAggroInfo_x                                           0xD2E40C
#define pinstAltAdvManager_x                                       0xE71F08
#define pinstAuraMgr_x                                             0xD3EC10
#define pinstBandageTarget_x                                       0xF25010
#define pinstCamActor_x                                            0xE717D8
#define pinstCDBStr_x                                              0xE70D34
#define pinstCDisplay_x                                            0xF25038
#define pinstCEverQuest_x                                          0x10C4438
#define pinstEverQuestInfo_x                                       0xF32408
#define pinstCharData_x                                            0xF24FF4
#define pinstCharSpawn_x                                           0xF2501C
#define pinstControlledMissile_x                                   0xF24FF0
#define pinstControlledPlayer_x                                    0xF2501C
#define pinstCSidlManager_x                                        0x1732E98
#define pinstCXWndManager_x                                        0x1732E90
#define instDynamicZone_x                                          0xF322A8
#define pinstDZMember_x                                            0xF323B8
#define pinstDZTimerInfo_x                                         0xF323BC
#define pinstEQItemList_x                                          0xF21498
#define pinstEQObjectList_x                                        0xF224C4
#define instEQMisc_x                                               0xC057A8
#define pinstEQSoundManager_x                                      0xE724D8
#define instExpeditionLeader_x                                     0xF322F2
#define instExpeditionName_x                                       0xF32332
#define pinstGroup_x                                               0xF22AC6
#define pinstImeManager_x                                          0x1732E9C
#define pinstLocalPlayer_x                                         0xF25008
#define pinstMercenaryData_x                                       0xFB7860
#define pinstMercenaryStats_x                                      0x10CC558
#define pinstMercAltAbilities_x                                    0xE72290
#define pinstModelPlayer_x                                         0xF25034
#define pinstPCData_x                                              0xF24FF4
#define pinstSkillMgr_x                                            0xFB8858
#define pinstSpawnManager_x                                        0xFB80B0
#define pinstSpellManager_x                                        0xFB89A0
#define pinstSpellSets_x                                           0xFAF6A4
#define pinstStringTable_x                                         0xF24F9C
#define pinstSwitchManager_x                                       0xF22658
#define pinstTarget_x                                              0xF25020
#define pinstTargetObject_x                                        0xF24FF8
#define pinstTargetSwitch_x                                        0xF24FFC
#define pinstTaskMember_x                                          0xE70C80
#define pinstTrackTarget_x                                         0xF25014
#define pinstTradeTarget_x                                         0xF25004
#define instTributeActive_x                                        0xC057CD
#define pinstViewActor_x                                           0xE717D4
#define pinstWorldData_x                                           0xF24FD8
#define pinstZoneAddr_x                                            0xF3298C
#define pinstPlayerPath_x                                          0xFB8110
#define pinstTargetIndicator_x                                     0xFB8B38
#define pinstCTargetManager_x                                      0xFB8B98
#define EQObject_Top_x                                             0xF24FE8
#define pinstRealEstateItems_x                                     0xFB86C4

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE716F0
#define pinstCAchievementsWnd_x                                    0xE7174C
#define pinstCTextOverlay_x                                        0xD2E9A0
#define pinstCAudioTriggersWindow_x                                0xD2E788
#define pinstCCharacterSelect_x                                    0xE7165C
#define pinstCFacePick_x                                           0xE7140C
#define pinstCFindItemWnd_x                                        0xE716EC
#define pinstCNoteWnd_x                                            0xE71614
#define pinstCBookWnd_x                                            0xE7161C
#define pinstCPetInfoWnd_x                                         0xE71620
#define pinstCTrainWnd_x                                           0xE71624
#define pinstCSkillsWnd_x                                          0xE71628
#define pinstCSkillsSelectWnd_x                                    0xE7162C
#define pinstCCombatSkillsSelectWnd_x                              0xE71630
#define pinstCFriendsWnd_x                                         0xE71634
#define pinstCAuraWnd_x                                            0xE71638
#define pinstCRespawnWnd_x                                         0xE7163C
#define pinstCBandolierWnd_x                                       0xE71640
#define pinstCPotionBeltWnd_x                                      0xE71644
#define pinstCAAWnd_x                                              0xE71648
#define pinstCGroupSearchFiltersWnd_x                              0xE7164C
#define pinstCLoadskinWnd_x                                        0xE71650
#define pinstCAlarmWnd_x                                           0xE71654
#define pinstCMusicPlayerWnd_x                                     0xE71658
#define pinstCMailWnd_x                                            0xE71660
#define pinstCMailCompositionWnd_x                                 0xE71664
#define pinstCMailAddressBookWnd_x                                 0xE71668
#define pinstCRaidWnd_x                                            0xE71670
#define pinstCRaidOptionsWnd_x                                     0xE71674
#define pinstCBreathWnd_x                                          0xE71678
#define pinstCMapViewWnd_x                                         0xE7167C
#define pinstCMapToolbarWnd_x                                      0xE71680
#define pinstCEditLabelWnd_x                                       0xE71684
#define pinstCTargetWnd_x                                          0xE71688
#define pinstCColorPickerWnd_x                                     0xE7168C
#define pinstCPlayerWnd_x                                          0xE71690
#define pinstCOptionsWnd_x                                         0xE71694
#define pinstCBuffWindowNORMAL_x                                   0xE71698
#define pinstCBuffWindowSHORT_x                                    0xE7169C
#define pinstCharacterCreation_x                                   0xE716A0
#define pinstCCursorAttachment_x                                   0xE716A4
#define pinstCCastingWnd_x                                         0xE716A8
#define pinstCCastSpellWnd_x                                       0xE716AC
#define pinstCSpellBookWnd_x                                       0xE716B0
#define pinstCInventoryWnd_x                                       0xE716B4
#define pinstCBankWnd_x                                            0xE716BC
#define pinstCQuantityWnd_x                                        0xE716C0
#define pinstCLootWnd_x                                            0xE716C4
#define pinstCActionsWnd_x                                         0xE716C8
#define pinstCCombatAbilityWnd_x                                   0xE716D0
#define pinstCMerchantWnd_x                                        0xE716D4
#define pinstCTradeWnd_x                                           0xE716DC
#define pinstCSelectorWnd_x                                        0xE716E0
#define pinstCBazaarWnd_x                                          0xE716E4
#define pinstCBazaarSearchWnd_x                                    0xE716E8
#define pinstCGiveWnd_x                                            0xE71708
#define pinstCTrackingWnd_x                                        0xE71710
#define pinstCInspectWnd_x                                         0xE71714
#define pinstCSocialEditWnd_x                                      0xE71718
#define pinstCFeedbackWnd_x                                        0xE7171C
#define pinstCBugReportWnd_x                                       0xE71720
#define pinstCVideoModesWnd_x                                      0xE71724
#define pinstCTextEntryWnd_x                                       0xE7172C
#define pinstCFileSelectionWnd_x                                   0xE71730
#define pinstCCompassWnd_x                                         0xE71734
#define pinstCPlayerNotesWnd_x                                     0xE71738
#define pinstCGemsGameWnd_x                                        0xE7173C
#define pinstCTimeLeftWnd_x                                        0xE71758
#define pinstCPetitionQWnd_x                                       0xE7175C
#define pinstCStoryWnd_x                                           0xE71760
#define pinstCJournalTextWnd_x                                     0xE71764
#define pinstCJournalCatWnd_x                                      0xE71768
#define pinstCBodyTintWnd_x                                        0xE7176C
#define pinstCServerListWnd_x                                      0xE71770
#define pinstCAvaZoneWnd_x                                         0xE7177C
#define pinstCBlockedBuffWnd_x                                     0xE71780
#define pinstCBlockedPetBuffWnd_x                                  0xE71784
#define pinstCInvSlotMgr_x                                         0xE717CC
#define pinstCContainerMgr_x                                       0xE717D0
#define pinstCAdventureLeaderboardWnd_x                            0x10C4DE8
#define pinstCAdventureRequestWnd_x                                0x10C4E60
#define pinstCAltStorageWnd_x                                      0x10C5140
#define pinstCAdventureStatsWnd_x                                  0x10C4ED8
#define pinstCBarterMerchantWnd_x                                  0x10C5E88
#define pinstCBarterSearchWnd_x                                    0x10C5F00
#define pinstCBarterWnd_x                                          0x10C5F78
#define pinstCChatWindowManager_x                                  0x10C6788
#define pinstCDynamicZoneWnd_x                                     0x10C6CB8
#define pinstCEQMainWnd_x                                          0x10C6E80
#define pinstCFellowshipWnd_x                                      0x10C6C4C
#define pinstCFindLocationWnd_x                                    0x10C7150
#define pinstCGroupSearchWnd_x                                     0x10C7420
#define pinstCGroupWnd_x                                           0x10C7498
#define pinstCGuildBankWnd_x                                       0x10C7510
#define pinstCGuildMgmtWnd_x                                       0x10C9600
#define pinstCHotButtonWnd_x                                       0x10C96FC
#define pinstCHotButtonWnd1_x                                      0x10C96FC
#define pinstCHotButtonWnd2_x                                      0x10C9700
#define pinstCHotButtonWnd3_x                                      0x10C9704
#define pinstCHotButtonWnd4_x                                      0x10C9728
#define pinstCItemDisplayManager_x                                 0x10C9B80
#define pinstCItemExpTransferWnd_x                                 0x10C9C7C
#define pinstCLFGuildWnd_x                                         0x10C9F58
#define pinstCMIZoneSelectWnd_x                                    0x10CA538
#define pinstCConfirmationDialog_x                                 0x10CAB50
#define pinstCPopupWndManager_x                                    0x10CAB50
#define pinstCProgressionSelectionWnd_x                            0x10CAC40
#define pinstCPvPStatsWnd_x                                        0x10CAD30
#define pinstCLargeDialogWnd_x                                     0x10CB4B8
#define pinstCTaskWnd_x                                            0x10CC838
#define pinstCTaskSomething_x                                      0xD3F828
#define pinstCTaskTemplateSelectWnd_x                              0x10CC7C0
#define pinstCTipWndOFDAY_x                                        0x10CC9A0
#define pinstCTipWndCONTEXT_x                                      0x10CC9A4
#define pinstCTitleWnd_x                                           0x10CCA20
#define pinstCContextMenuManager_x                                 0x1732D20
#define pinstCVoiceMacroWnd_x                                      0xFB8F70
#define pinstCHtmlWnd_x                                            0xFB9060
#define pinstItemIconCache_x                                       0x10C6E28
#define pinstCTradeskillWnd_x                                      0x10CCB20
#define pinstCAdvancedLootWnd_x                                    0xE717C0
#define pinstRewardSelectionWnd_x                                  0x10CB258
#define pinstEQSuiteTextureLoader_x                                0xD1CA98

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x549D70
#define __CastRay2_x                                               0x5496A0
#define __HeadingDiff_x                                            0x9358D0
#define __FixHeading_x                                             0x935860
#define __get_bearing_x                                            0x539620
#define __ConvertItemTags_x                                        0x5370F0
#define __ExecuteCmd_x                                             0x5219A0
#define __EQGetTime_x                                              0x8A4290
#define __get_melee_range_x                                        0x528690
#define __GetGaugeValueFromEQ_x                                    0x7B2C80
#define __GetLabelFromEQ_x                                         0x7B4050
#define __ToggleKeyRingItem_x                                      0x48FA80
#define __GetXTargetType_x                                         0x937540
#define __LoadFrontEnd_x                                           0x63FA20
#define __NewUIINI_x                                               0x7B2650
#define __ProcessGameEvents_x                                      0x583A20
#define __ProcessMouseEvent_x                                      0x5831C0
#define CrashDetected_x                                            0x6413E0
#define wwsCrashReportCheckForUploader_x                           0x801F60
#define __AppCrashWrapper_x                                        0xC69AC4
#define __pCrashHandler_x                                          0x10D9A00
#define __CrashHandler_x                                           0x8019C0
#define wwsCrashReportPlatformLaunchUploader_x                     0x804160
#define DrawNetStatus_x                                            0x5BA110
#define Util__FastTime_x                                           0x8A3F30
#define Expansion_HoT_x                                            0xF337D0
#define __HelpPath_x                                               0xFB6F80
#define __STMLToText_x                                             0x8EAB90
#define __GetAnimationCache_x                                      0x6AF2F0
#define Teleport_Table_x                                           0xF22CB8
#define Teleport_Table_Size_x                                      0xF24F8C

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423160
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DDC0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DB90

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D7E20
#define AltAdvManager__IsAbilityReady_x                            0x4D7E90
#define AltAdvManager__GetAAById_x                                 0x4D8380
#define AltAdvManager__CanTrainAbility_x                           0x4D8FB0
#define AltAdvManager__CanSeeAbility_x                             0x4D8B70

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46AFE0
#define CharacterZoneClient__HasSkill_x                            0x466EF0
#define CharacterZoneClient__MakeMeVisible_x                       0x46CB50
#define CharacterZoneClient__IsStackBlocked_x                      0x44BBA0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B0C0
#define CharacterZoneClient__GetItemCountWorn_x                    0x465450
#define CharacterZoneClient__GetItemCountInInventory_x             0x465530
#define CharacterZoneClient__GetCursorItemCount_x                  0x465610
#define CharacterZoneClient__FindAffectSlot_x                      0x4511A0
#define CharacterZoneClient__BardCastBard_x                        0x44A830
#define CharacterZoneClient__GetMaxEffects_x                       0x4493C0
#define CharacterZoneClient__GetEffect_x                           0x44B2F0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451000
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449710
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FB50

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66F2B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67D120

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x598C20
#define CButtonWnd__CButtonWnd_x                                   0x8DED70

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x698340
#define CChatManager__InitContextMenu_x                            0x699490
#define CChatManager__FreeChatWindow_x                             0x697DF0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A15E0
#define CChatManager__SetLockedActiveChatWindow_x                  0x698310

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E8F00
#define CContextMenu__dCContextMenu_x                              0x8E9100
#define CContextMenu__AddMenuItem_x                                0x8E9610
#define CContextMenu__RemoveMenuItem_x                             0x8E9270
#define CContextMenu__RemoveAllMenuItems_x                         0x8E9290
#define CContextMenu__CheckMenuItem_x                              0x8E9310
#define CContextMenu__SetMenuItem_x                                0x8E91A0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D5300
#define CContextMenuManager__RemoveMenu_x                          0x8D56B0
#define CContextMenuManager__PopupMenu_x                           0x8D5B00
#define CContextMenuManager__Flush_x                               0x8D5380
#define CContextMenuManager__GetMenu_x                             0x419290

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x888430
#define CChatService__GetFriendName_x                              0x888440

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69F0D0
#define CChatWindow__Clear_x                                       0x69E9B0
#define CChatWindow__WndNotification_x                             0x69F9D0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D9160
#define CComboWnd__Draw_x                                          0x8D9370
#define CComboWnd__GetCurChoice_x                                  0x8D8F10
#define CComboWnd__GetListRect_x                                   0x8D9610
#define CComboWnd__GetTextRect_x                                   0x8D91D0
#define CComboWnd__InsertChoice_x                                  0x8D9770
#define CComboWnd__SetColors_x                                     0x8D8EA0
#define CComboWnd__SetChoice_x                                     0x8D8ED0
#define CComboWnd__GetItemCount_x                                  0x8D8F00
#define CComboWnd__GetCurChoiceText_x                              0x8D8F50

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A9480
#define CContainerWnd__vftable_x                                   0xAEF9D0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C5D50
#define CDisplay__GetClickedActor_x                                0x4BE5F0
#define CDisplay__GetUserDefinedColor_x                            0x4BD1D0
#define CDisplay__GetWorldFilePath_x                               0x4BC620
#define CDisplay__is3dON_x                                         0x4BBAB0
#define CDisplay__ReloadUI_x                                       0x4CFB30
#define CDisplay__WriteTextHD2_x                                   0x4C20C0
#define CDisplay__TrueDistance_x                                   0x4BF220

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9006F0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8ED440
#define CEditWnd__GetCharIndexPt_x                                 0x8EE580
#define CEditWnd__GetDisplayString_x                               0x8ED5F0
#define CEditWnd__GetHorzOffset_x                                  0x8ED930
#define CEditWnd__GetLineForPrintableChar_x                        0x8EE050
#define CEditWnd__GetSelStartPt_x                                  0x8EE830
#define CEditWnd__GetSTMLSafeText_x                                0x8EDAC0
#define CEditWnd__PointFromPrintableChar_x                         0x8EE140
#define CEditWnd__SelectableCharFromPoint_x                        0x8EE2C0
#define CEditWnd__SetEditable_x                                    0x8EDA90

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56A100
#define CEverQuest__ClickedPlayer_x                                0x563C50
#define CEverQuest__CreateTargetIndicator_x                        0x564B50
#define CEverQuest__DeleteTargetIndicator_x                        0x564BD0
#define CEverQuest__DoTellWindow_x                                 0x476220
#define CEverQuest__OutputTextToLog_x                              0x475E80
#define CEverQuest__DropHeldItemOnGround_x                         0x57A680
#define CEverQuest__dsp_chat_x                                     0x476560
#define CEverQuest__trimName_x                                     0x560560
#define CEverQuest__Emote_x                                        0x578990
#define CEverQuest__EnterZone_x                                    0x573A70
#define CEverQuest__GetBodyTypeDesc_x                              0x55DFA0
#define CEverQuest__GetClassDesc_x                                 0x567510
#define CEverQuest__GetClassThreeLetterCode_x                      0x567B10
#define CEverQuest__GetDeityDesc_x                                 0x55E880
#define CEverQuest__GetLangDesc_x                                  0x55E330
#define CEverQuest__GetRaceDesc_x                                  0x567CD0
#define CEverQuest__InterpretCmd_x                                 0x56B890
#define CEverQuest__LeftClickedOnPlayer_x                          0x580230
#define CEverQuest__LMouseUp_x                                     0x5821E0
#define CEverQuest__RightClickedOnPlayer_x                         0x580D40
#define CEverQuest__RMouseUp_x                                     0x581C40
#define CEverQuest__SetGameState_x                                 0x564520
#define CEverQuest__UPCNotificationFlush_x                         0x55C930
#define CEverQuest__IssuePetCommand_x                              0x56C270
#define CEverQuest__ReportSuccessfulHit_x                          0x5751C0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BA050
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BA0B0
#define CGaugeWnd__Draw_x                                          0x6BA4E0

// CGuild
#define CGuild__FindMemberByName_x                                 0x43AE10
#define CGuild__GetGuildName_x                                     0x43B2E0
#define CGuild__GetGuildIndex_x                                    0x43C4F0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D6990

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E3D30
#define CInvSlotMgr__MoveItem_x                                    0x6E44F0
#define CInvSlotMgr__SelectSlot_x                                  0x6E3620

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E2A80
#define CInvSlot__SliderComplete_x                                 0x6E02B0
#define CInvSlot__GetItemBase_x                                    0x6DF750
#define CInvSlot__UpdateItem_x                                     0x6DFCD0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E5910
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E6A40

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AEAB0
#define CItemDisplayWnd__UpdateStrings_x                           0x6E7B40
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F4410
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F4910
#define CItemDisplayWnd__SetItem_x                                 0x6FA180
#define CItemDisplayWnd__AboutToShow_x                             0x6EE2A0
#define CItemDisplayWnd__WndNotification_x                         0x6FA930

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E6C70

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EE110

// CLabel 
#define CLabel__Draw_x                                             0x700F40

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C4C10
#define CListWnd__dCListWnd_x                                      0x8C5FF0
#define CListWnd__AddColumn_x                                      0x8C5F90
#define CListWnd__AddColumn1_x                                     0x8C54F0
#define CListWnd__AddLine_x                                        0x8C4ED0
#define CListWnd__AddString_x                                      0x8C50F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C1BE0
#define CListWnd__CalculateVSBRange_x                              0x8C3B90
#define CListWnd__ClearSel_x                                       0x8C0F00
#define CListWnd__ClearAllSel_x                                    0x8C0EB0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C4AA0
#define CListWnd__Compare_x                                        0x8C28D0
#define CListWnd__Draw_x                                           0x8C4490
#define CListWnd__DrawColumnSeparators_x                           0x8C3A20
#define CListWnd__DrawHeader_x                                     0x8C11C0
#define CListWnd__DrawItem_x                                       0x8C2F60
#define CListWnd__DrawLine_x                                       0x8C36C0
#define CListWnd__DrawSeparator_x                                  0x8C3AC0
#define CListWnd__EnableLine_x                                     0x8C10E0
#define CListWnd__EnsureVisible_x                                  0x8C1D40
#define CListWnd__ExtendSel_x                                      0x8C2E70
#define CListWnd__GetColumnMinWidth_x                              0x8C07C0
#define CListWnd__GetColumnWidth_x                                 0x8C06F0
#define CListWnd__GetCurSel_x                                      0x8BFEC0
#define CListWnd__GetItemAtPoint_x                                 0x8C1FD0
#define CListWnd__GetItemAtPoint1_x                                0x8C2040
#define CListWnd__GetItemData_x                                    0x8C0200
#define CListWnd__GetItemHeight_x                                  0x8C1840
#define CListWnd__GetItemIcon_x                                    0x8C03F0
#define CListWnd__GetItemRect_x                                    0x8C1E10
#define CListWnd__GetItemText_x                                    0x8C02A0
#define CListWnd__GetSelList_x                                     0x8C53E0
#define CListWnd__GetSeparatorRect_x                               0x8C27F0
#define CListWnd__InsertLine_x                                     0x8C52D0
#define CListWnd__RemoveLine_x                                     0x8C52E0
#define CListWnd__SetColors_x                                      0x8C0010
#define CListWnd__SetColumnJustification_x                         0x8C0A50
#define CListWnd__SetColumnWidth_x                                 0x8C0770
#define CListWnd__SetCurSel_x                                      0x8BFF00
#define CListWnd__SetItemColor_x                                   0x8C42D0
#define CListWnd__SetItemData_x                                    0x8C0F60
#define CListWnd__SetItemText_x                                    0x8C4110
#define CListWnd__ShiftColumnSeparator_x                           0x8C3F20
#define CListWnd__Sort_x                                           0x8C60F0
#define CListWnd__ToggleSel_x                                      0x8C0E30

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71A0A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73F830
#define CMerchantWnd__RequestBuyItem_x                             0x747510
#define CMerchantWnd__RequestSellItem_x                            0x749B30
#define CMerchantWnd__SelectRecoverySlot_x                         0x73CA60
#define CMerchantWnd__SelectBuySellSlot_x                          0x73A8F0
#define CMerchantWnd__ActualSelect_x                               0x741670

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8566E0
#define CPacketScrambler__hton_x                                   0x8566F0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E3D80
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E3E60
#define CSidlManager__CreateLabel_x                                0x7A3A50
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E2320
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E4140

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8DB1C0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8DB0B0
#define CSidlScreenWnd__ConvertToRes_x                             0x9005D0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8DBAD0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DCCA0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DCD50
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DC220
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8DB480
#define CSidlScreenWnd__EnableIniStorage_x                         0x8DABE0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8DB670
#define CSidlScreenWnd__Init1_x                                    0x8DC970
#define CSidlScreenWnd__LoadIniInfo_x                              0x8DBB80
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8DADA0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DC460
#define CSidlScreenWnd__StoreIniInfo_x                             0x8DA830
#define CSidlScreenWnd__StoreIniVis_x                              0x8DAB90
#define CSidlScreenWnd__WndNotification_x                          0x8DC6F0
#define CSidlScreenWnd__GetChildItem_x                             0x8DACB0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CE4E0
#define CSidlScreenWnd__m_layoutCopy_x                             0x1732E40

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6051B0
#define CSkillMgr__GetSkillCap_x                                   0x605390
#define CSkillMgr__GetNameToken_x                                  0x604D60

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FF880
#define CSliderWnd__SetValue_x                                     0x8FFA50
#define CSliderWnd__SetNumTicks_x                                  0x9001D0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A9D30

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F8E90
#define CStmlWnd__CalculateHSBRange_x                              0x8F13F0
#define CStmlWnd__CalculateVSBRange_x                              0x8F1360
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F1570
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F1D70
#define CStmlWnd__ForceParseNow_x                                  0x8F9810
#define CStmlWnd__GetNextTagPiece_x                                0x8F1C70
#define CStmlWnd__GetSTMLText_x                                    0x484510
#define CStmlWnd__GetVisibleText_x                                 0x8F27C0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F4D90
#define CStmlWnd__MakeStmlColorTag_x                               0x8F0640
#define CStmlWnd__MakeWndNotificationTag_x                         0x8F06A0
#define CStmlWnd__SetSTMLText_x                                    0x8F65F0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F8B30
#define CStmlWnd__UpdateHistoryString_x                            0x8F3700

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FCD10
#define CTabWnd__DrawCurrentPage_x                                 0x8FC5A0
#define CTabWnd__DrawTab_x                                         0x8FC370
#define CTabWnd__GetCurrentPage_x                                  0x8FC950
#define CTabWnd__GetPageInnerRect_x                                0x8FC060
#define CTabWnd__GetTabInnerRect_x                                 0x8FC260
#define CTabWnd__GetTabRect_x                                      0x8FC130
#define CTabWnd__InsertPage_x                                      0x8FD000
#define CTabWnd__SetPage_x                                         0x8FC980
#define CTabWnd__SetPageRect_x                                     0x8FCC50
#define CTabWnd__UpdatePage_x                                      0x8FCFA0
#define CTabWnd__GetPageFromTabIndex_x                             0x8FC2C0
#define CTabWnd__GetCurrentTabIndex_x                              0x8FBFF0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E6BF0
#define CPageWnd__SetTabText_x                                     0x909920

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436A10

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D8B10
#define CTextureFont__GetTextExtent_x                              0x8D8870

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63DCB0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x905D60

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BE110

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402940
#define CXStr__CXStr1_x                                            0x8BF0E0
#define CXStr__CXStr3_x                                            0x8A11C0
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x8A1330
#define CXStr__operator_equal1_x                                   0x8A1380
#define CXStr__operator_plus_equal1_x                              0x8A2480

// CXWnd 
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D6610
#define CXWnd__BringToTop_x                                        0x8CD740
#define CXWnd__Center_x                                            0x8D38E0
#define CXWnd__ClrFocus_x                                          0x8CD330
#define CXWnd__Destroy_x                                           0x8D43C0
#define CXWnd__DoAllDrawing_x                                      0x8D3530
#define CXWnd__DrawChildren_x                                      0x8D36D0
#define CXWnd__DrawColoredRect_x                                   0x8CDB20
#define CXWnd__DrawTooltip_x                                       0x8CDDD0
#define CXWnd__DrawTooltipAtPoint_x                                0x8D24A0
#define CXWnd__GetBorderFrame_x                                    0x8CE1E0
#define CXWnd__GetChildWndAt_x                                     0x8D42B0
#define CXWnd__GetClientClipRect_x                                 0x8CDFF0
#define CXWnd__GetScreenClipRect_x                                 0x8D2B90
#define CXWnd__GetScreenRect_x                                     0x8CE390
#define CXWnd__GetTooltipRect_x                                    0x8CDC60
#define CXWnd__GetWindowTextA_x                                    0x426CC0
#define CXWnd__IsActive_x                                          0x8C8D70
#define CXWnd__IsDescendantOf_x                                    0x8CE130
#define CXWnd__IsReallyVisible_x                                   0x8D14C0
#define CXWnd__IsType_x                                            0x8D3950
#define CScreenPieceTemplate__IsType_x                             0x902470
#define CXWnd__Move_x                                              0x8D0BE0
#define CXWnd__Move1_x                                             0x8D31D0
#define CXWnd__ProcessTransition_x                                 0x8CD6E0
#define CXWnd__Refade_x                                            0x8CD4C0
#define CXWnd__Resize_x                                            0x8CE450
#define CXWnd__Right_x                                             0x8D2990
#define CXWnd__SetFocus_x                                          0x8CFD40
#define CXWnd__SetFont_x                                           0x8CD380
#define CXWnd__SetKeyTooltip_x                                     0x8CE6B0
#define CXWnd__SetMouseOver_x                                      0x8D2EC0
#define CXWnd__StartFade_x                                         0x8CD790
#define CXWnd__GetChildItem_x                                      0x8D2E00
#define CXWnd__SetParent_x                                         0x8D4260

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8CA620
#define CXWndManager__DrawWindows_x                                0x8CA260
#define CXWndManager__GetKeyboardFlags_x                           0x8C88E0
#define CXWndManager__HandleKeyboardMsg_x                          0x8C9200
#define CXWndManager__RemoveWnd_x                                  0x8C8F00

// CDBStr
#define CDBStr__GetString_x                                        0x4BA300

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452350
#define EQ_Character__Cur_HP_x                                     0x466AD0
#define EQ_Character__Cur_Mana_x                                   0x45B750
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B3D0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443380
#define EQ_Character__GetFocusRangeModifier_x                      0x4434D0
#define EQ_Character__GetHPRegen_x                                 0x46A670
#define EQ_Character__GetEnduranceRegen_x                          0x4660E0
#define EQ_Character__GetManaRegen_x                               0x46AC10
#define EQ_Character__Max_Endurance_x                              0x5CBA90
#define EQ_Character__Max_HP_x                                     0x45E2D0
#define EQ_Character__Max_Mana_x                                   0x5CB8C0
#define EQ_Character__doCombatAbility_x                            0x5C8F90
#define EQ_Character__UseSkill_x                                   0x472A10
#define EQ_Character__GetConLevel_x                                0x5BE760
#define EQ_Character__IsExpansionFlag_x                            0x4B6680
#define EQ_Character__TotalEffect_x                                0x44F490
#define EQ_Character__GetPCSpellAffect_x                           0x44B760
#define EQ_Character__SpellDuration_x                              0x449760
#define EQ_Character__FindItemByRecord_x                           0x464110
#define EQ_Character__GetAdjustedSkill_x                           0x466CA0
#define EQ_Character__GetBaseSkill_x                               0x45E1B0
#define EQ_Character__CanUseItem_x                                 0x468B80

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x874600

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D41A0

//PcClient
#define PcClient__PcClient_x                                       0x5C05A0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446830
#define CCharacterSelect__EnterWorld_x                             0x446000
#define CCharacterSelect__Quit_x                                   0x444BC0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59E5D0
#define EQ_Item__CreateItemTagString_x                             0x854860
#define EQ_Item__IsStackable_x                                     0x849AE0
#define EQ_Item__GetImageNum_x                                     0x84C6A0
#define EQ_Item__CreateItemClient_x                                0x59F710
#define EQ_Item__GetItemValue_x                                    0x8532C0
#define EQ_Item__ValueSellMerchant_x                               0x856320
#define EQ_Item__IsKeyRingItem_x                                   0x84A670
#define EQ_Item__CanGoInBag_x                                      0x59E760
#define EQ_Item__GetMaxItemCount_x                                 0x8499D0
#define EQ_Item__GetHeldItem_x                                     0x84B4C0
#define EQ_Item__GetAugmentFitBySlot_x                             0x856150

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA3F0
#define EQ_LoadingS__Array_x                                       0xC0DC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CDFB0
#define EQ_PC__GetAlternateAbilityId_x                             0x85E7F0
#define EQ_PC__GetCombatAbility_x                                  0x85E880
#define EQ_PC__GetCombatAbilityTimer_x                             0x859390
#define EQ_PC__GetItemRecastTimer_x                                0x5C7770
#define EQ_PC__HasLoreItem_x                                       0x5C1D50
#define EQ_PC__AlertInventoryChanged_x                             0x5BE710
#define EQ_PC__GetPcZoneClient_x                                   0x5E87C0
#define EQ_PC__RemoveMyAffect_x                                    0x5C6BA0
#define EQ_PC__GetKeyRingItems_x                                   0x8597B0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86C540
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8607A0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5266F0
#define EQItemList__add_object_x                                   0x5538E0
#define EQItemList__add_item_x                                     0x526630
#define EQItemList__delete_item_x                                  0x526AE0
#define EQItemList__FreeItemList_x                                 0x5269E0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B95F0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D3E60
#define EQPlayer__dEQPlayer_x                                      0x5DC620
#define EQPlayer__DoAttack_x                                       0x5EDFB0
#define EQPlayer__EQPlayer_x                                       0x5DED50
#define EQPlayer__SetNameSpriteState_x                             0x5D9450
#define EQPlayer__SetNameSpriteTint_x                              0x5D5370
#define PlayerBase__HasProperty_j_x                                0x933CE0
#define EQPlayer__IsTargetable_x                                   0x933F80
#define EQPlayer__CanSee_x                                         0x9344E0
#define PlayerZoneClient__ChangeHeight_x                           0x5EDE70
#define EQPlayer__CanSee1_x                                        0x9345D0
#define PlayerBase__GetVisibilityLineSegment_x                     0x934270

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E8970
#define PlayerZoneClient__IsValidTeleport_x                        0x554180
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2720

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E2E00
#define EQPlayerManager__GetSpawnByName_x                          0x5E3260
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E2E30

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A4BF0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A4C30
#define KeypressHandler__ClearCommandStateArray_x                  0x5A47E0
#define KeypressHandler__HandleKeyDown_x                           0x5A3100
#define KeypressHandler__HandleKeyUp_x                             0x5A3420
#define KeypressHandler__SaveKeymapping_x                          0x5A48B0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x712A30
#define MapViewMap__SaveEx_x                                       0x715D60
#define MapViewMap__SetZoom_x                                      0x7126C0

#define PlayerPointManager__GetAltCurrency_x                       0x8726C0

// StringTable 
#define StringTable__getString_x                                   0x86C870

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CB520
#define PcZoneClient__RemovePetEffect_x                            0x5C7C50
#define PcZoneClient__HasAlternateAbility_x                        0x5C85F0
#define PcZoneClient__GetCurrentMod_x                              0x45D780
#define PcZoneClient__GetModCap_x                                  0x45AEB0
#define PcZoneClient__CanEquipItem_x                               0x5C8AD0
#define PcZoneClient__GetItemByID_x                                0x5CD330
#define PcZoneClient__GetItemByItemClass_x                         0x5CDED0
#define PcZoneClient__RemoveBuffEffect_x                           0x5C6E50

//Doors
#define EQSwitch__UseSwitch_x                                      0x55B1D0

//IconCache
#define IconCache__GetIcon_x                                       0x6AF920

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A6830
#define CContainerMgr__CloseContainer_x                            0x6A7050

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7738D0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x597650

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F4AF0
#define EQ_Spell__SpellAffects_x                                   0x4F1CD0
#define EQ_Spell__SpellAffectBase_x                                0x4F1D40
#define CharacterZoneClient__CalcAffectChange_x                    0x44B5F0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44A890
#define CLootWnd__LootAll_x                                        0x7082D0
#define CLootWnd__RequestLootSlot_x                                0x708AE0
#define EQ_Spell__IsStackable_x                                    0x458E50
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449230
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43E8D0
#define EQ_Spell__IsSPAStacking_x                                  0x4F1840
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F28E0
#define EQ_Spell__IsNoRemove_x                                     0x434A30
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F1860

#define __IsResEffectSpell_x                                       0x4492B0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87E2C0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BB6E0
#define CTargetWnd__WndNotification_x                              0x7BB1D0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BB8C0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C0800

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED340
#define EqSoundManager__PlayScriptMp3_x                            0x4EEDE0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A86B0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8ECA70
#define CSidlManager__FindAnimation1_x                             0x8E1D50

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E1D10
#define CAltAbilityData__GetMercMaxRank_x                          0x4E1CC0
#define CAltAbilityData__GetMaxRank_x                              0x4D64D0

//CTargetRing
#define CTargetRing__Cast_x                                        0x595290

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459170
#define CharacterBase__CreateItemGlobalIndex_x                     0x475440
#define CharacterBase__CreateItemIndex_x                           0x51FD00
#define CharacterBase__GetItemPossession_x                         0x444090
#define CharacterBase__GetItemByGlobalIndex_x                      0x882100
#define CharacterBase__GetEffectId_x                               0x459130

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68F480
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68EBE0

//messages
#define msg_spell_worn_off_x                                       0x4FC5D0
#define msg_new_text_x                                             0x505D50
#define msgTokenTextParam_x                                        0x502550

//SpellManager
#define SpellManager__vftable_x                                    0xACB288
#define SpellManager__SpellManager_x                               0x47E130
#define Spellmanager__LoadTextSpells_x                             0x60C120

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x938060

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487A60
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43E7F0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x448F20
#define ItemGlobalIndex__IsValidIndex_x                            0x458990

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87FF80
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87EEC0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x701190

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AB540
#define CCursorAttachment__Deactivate_x                            0x6AAA90

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FED80
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FEF00

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C2D0

//IString
#define IString__Append_x                                          0x47ED80

//Camera
#define CDisplay__cameraType_x                                     0xE717E8
#define EverQuest__Cameras_x                                       0xF33AE8

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x493F50
#define pinstLootFiltersManager_x                                  0xD3F248
