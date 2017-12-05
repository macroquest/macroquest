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
#define __ExpectedVersionDate                                     "Dec  5 2017"
#define __ExpectedVersionTime                                     "04:17:59"
#define __ActualVersionDate_x                                      0xAE50E0
#define __ActualVersionTime_x                                      0xAE50EC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5AB2B0
#define __MemChecker1_x                                            0x8A3990
#define __MemChecker2_x                                            0x641250
#define __MemChecker3_x                                            0x6411A0
#define __MemChecker4_x                                            0x7F5190
#define __EncryptPad0_x                                            0xC3FFE8
#define __EncryptPad1_x                                            0xD19BA0
#define __EncryptPad2_x                                            0xC68ED0
#define __EncryptPad3_x                                            0xC68AD0
#define __EncryptPad4_x                                            0xD081A0
#define __EncryptPad5_x                                            0x10C32E0
#define __AC1_x                                                    0x7B4965
#define __AC2_x                                                    0x564547
#define __AC3_x                                                    0x5626C0
#define __AC4_x                                                    0x574891
#define __AC5_x                                                    0x5885EB
#define __AC6_x                                                    0x58C19E
#define __AC7_x                                                    0x582BEC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FA4EE0

// Direct Input
#define DI8__Main_x                                                0x10C32B8
#define DI8__Keyboard_x                                            0x10C32BC
#define DI8__Mouse_x                                               0x10C32C0
#define DI8__Mouse_Copy_x                                          0xF31474
#define DI8__Mouse_Check_x                                         0xFBAFA4
#define __AutoSkillArray_x                                         0xF32388
#define __Attack_x                                                 0xFB5A7B
#define __Autofire_x                                               0xFB5A7C
#define __BindList_x                                               0xC1C368
#define g_eqCommandStates_x                                        0xF201C0
#define __Clicks_x                                                 0xF31530
#define __CommandList_x                                            0xC1EA80
#define __CurrentMapLabel_x                                        0x10C92B0
#define __CurrentSocial_x                                          0xBEB8E8
#define __DoAbilityList_x                                          0xF67C40
#define __do_loot_x                                                0x533350
#define __DrawHandler_x                                            0x1732F2C
#define __GroupCount_x                                             0xF21ACA

#define __Guilds_x                                                 0xF276E0
#define __gWorld_x                                                 0xF23F84
#define __HotkeyPage_x                                             0xFAE640
#define __HWnd_x                                                   0xFBB0C0
#define __InChatMode_x                                             0xF3145C
#define __LastTell_x                                               0xF3333C
#define __LMouseHeldTime_x                                         0xF3159C
#define __Mouse_x                                                  0x10C32C4
#define __MouseLook_x                                              0xF314F6
#define __MouseEventTime_x                                         0xFB6214
#define __gpbCommandEvent_x                                        0xF2404C
#define __NetStatusToggle_x                                        0xF314F9
#define __PCNames_x                                                0xF32944
#define __RangeAttackReady_x                                       0xF3266C
#define __RMouseHeldTime_x                                         0xF31598
#define __RunWalkState_x                                           0xF31460
#define __ScreenMode_x                                             0xE6FDA0
#define __ScreenX_x                                                0xF31414
#define __ScreenY_x                                                0xF31410
#define __ScreenXMax_x                                             0xF31418
#define __ScreenYMax_x                                             0xF3141C
#define __ServerHost_x                                             0xF21A14
#define __ServerName_x                                             0xF67C00
#define __ShiftKeyDown_x                                           0xF31AF0
#define __ShowNames_x                                              0xF32824
#define __Socials_x                                                0xF67D00
#define __SubscriptionType_x                                       0x10F9A34
#define __TargetAggroHolder_x                                      0x10CB40C
#define __ZoneType_x                                               0xF318F4
#define __GroupAggro_x                                             0x10CB44C
#define __LoginName_x                                              0xFB9B9C
#define __Inviter_x                                                0xFB59F8
#define __AttackOnAssist_x                                         0xF327E0
#define __UseTellWindows_x                                         0xF32ADC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF24070
#define instEQZoneInfo_x                                           0xF316EC
#define instKeypressHandler_x                                      0xFB61F8
#define pinstActiveBanker_x                                        0xF24028
#define pinstActiveCorpse_x                                        0xF2402C
#define pinstActiveGMaster_x                                       0xF24030
#define pinstActiveMerchant_x                                      0xF24024
#define pinstAggroInfo_x                                           0xD2D40C
#define pinstAltAdvManager_x                                       0xE70F08
#define pinstAuraMgr_x                                             0xD3DC10
#define pinstBandageTarget_x                                       0xF24010
#define pinstCamActor_x                                            0xE707D8
#define pinstCDBStr_x                                              0xE6FD34
#define pinstCDisplay_x                                            0xF24038
#define pinstCEverQuest_x                                          0x10C3438
#define pinstEverQuestInfo_x                                       0xF31408
#define pinstCharData_x                                            0xF23FF4
#define pinstCharSpawn_x                                           0xF2401C
#define pinstControlledMissile_x                                   0xF23FF0
#define pinstControlledPlayer_x                                    0xF2401C
#define pinstCSidlManager_x                                        0x1731E98
#define pinstCXWndManager_x                                        0x1731E90
#define instDynamicZone_x                                          0xF312A8
#define pinstDZMember_x                                            0xF313B8
#define pinstDZTimerInfo_x                                         0xF313BC
#define pinstEQItemList_x                                          0xF20498
#define pinstEQObjectList_x                                        0xF214C4
#define instEQMisc_x                                               0xC047A8
#define pinstEQSoundManager_x                                      0xE714D8
#define instExpeditionLeader_x                                     0xF312F2
#define instExpeditionName_x                                       0xF31332
#define pinstGroup_x                                               0xF21AC6
#define pinstImeManager_x                                          0x1731E9C
#define pinstLocalPlayer_x                                         0xF24008
#define pinstMercenaryData_x                                       0xFB6860
#define pinstMercenaryStats_x                                      0x10CB558
#define pinstMercAltAbilities_x                                    0xE71290
#define pinstModelPlayer_x                                         0xF24034
#define pinstPCData_x                                              0xF23FF4
#define pinstSkillMgr_x                                            0xFB7858
#define pinstSpawnManager_x                                        0xFB70B0
#define pinstSpellManager_x                                        0xFB79A0
#define pinstSpellSets_x                                           0xFAE6A4
#define pinstStringTable_x                                         0xF23F9C
#define pinstSwitchManager_x                                       0xF21658
#define pinstTarget_x                                              0xF24020
#define pinstTargetObject_x                                        0xF23FF8
#define pinstTargetSwitch_x                                        0xF23FFC
#define pinstTaskMember_x                                          0xE6FC80
#define pinstTrackTarget_x                                         0xF24014
#define pinstTradeTarget_x                                         0xF24004
#define instTributeActive_x                                        0xC047CD
#define pinstViewActor_x                                           0xE707D4
#define pinstWorldData_x                                           0xF23FD8
#define pinstZoneAddr_x                                            0xF3198C
#define pinstPlayerPath_x                                          0xFB7110
#define pinstTargetIndicator_x                                     0xFB7B38
#define pinstCTargetManager_x                                      0xFB7B98
#define EQObject_Top_x                                             0xF23FE8
#define pinstRealEstateItems_x                                     0xFB76C4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE706F0
#define pinstCAchievementsWnd_x                                    0xE7074C
#define pinstCTextOverlay_x                                        0xD2D9A0
#define pinstCAudioTriggersWindow_x                                0xD2D788
#define pinstCCharacterSelect_x                                    0xE7065C
#define pinstCFacePick_x                                           0xE7040C
#define pinstCFindItemWnd_x                                        0xE706EC
#define pinstCNoteWnd_x                                            0xE70614
#define pinstCBookWnd_x                                            0xE7061C
#define pinstCPetInfoWnd_x                                         0xE70620
#define pinstCTrainWnd_x                                           0xE70624
#define pinstCSkillsWnd_x                                          0xE70628
#define pinstCSkillsSelectWnd_x                                    0xE7062C
#define pinstCCombatSkillsSelectWnd_x                              0xE70630
#define pinstCFriendsWnd_x                                         0xE70634
#define pinstCAuraWnd_x                                            0xE70638
#define pinstCRespawnWnd_x                                         0xE7063C
#define pinstCBandolierWnd_x                                       0xE70640
#define pinstCPotionBeltWnd_x                                      0xE70644
#define pinstCAAWnd_x                                              0xE70648
#define pinstCAlarmWnd_x                                           0xE70654
#define pinstCGroupSearchFiltersWnd_x                              0xE7064C
#define pinstCLoadskinWnd_x                                        0xE70650
#define pinstCLargeDialogWnd_x                                     0x10CA4B8
#define pinstCMusicPlayerWnd_x                                     0xE70658
#define pinstCMailWnd_x                                            0xE70660
#define pinstCMailCompositionWnd_x                                 0xE70664
#define pinstCMailAddressBookWnd_x                                 0xE70668
#define pinstCRaidWnd_x                                            0xE70670
#define pinstCRaidOptionsWnd_x                                     0xE70674
#define pinstCBreathWnd_x                                          0xE70678
#define pinstCMapViewWnd_x                                         0xE7067C
#define pinstCMapToolbarWnd_x                                      0xE70680
#define pinstCEditLabelWnd_x                                       0xE70684
#define pinstCTargetWnd_x                                          0xE70688
#define pinstCColorPickerWnd_x                                     0xE7068C
#define pinstCPlayerWnd_x                                          0xE70690
#define pinstCOptionsWnd_x                                         0xE70694
#define pinstCBuffWindowNORMAL_x                                   0xE70698
#define pinstCBuffWindowSHORT_x                                    0xE7069C
#define pinstCharacterCreation_x                                   0xE706A0
#define pinstCCursorAttachment_x                                   0xE706A4
#define pinstCCastingWnd_x                                         0xE706A8
#define pinstCCastSpellWnd_x                                       0xE706AC
#define pinstCSpellBookWnd_x                                       0xE706B0
#define pinstCInventoryWnd_x                                       0xE706B4
#define pinstCBankWnd_x                                            0xE706BC
#define pinstCQuantityWnd_x                                        0xE706C0
#define pinstCLootWnd_x                                            0xE706C4
#define pinstCActionsWnd_x                                         0xE706C8
#define pinstCCombatAbilityWnd_x                                   0xE706D0
#define pinstCMerchantWnd_x                                        0xE706D4
#define pinstCTradeWnd_x                                           0xE706DC
#define pinstCSelectorWnd_x                                        0xE706E0
#define pinstCBazaarWnd_x                                          0xE706E4
#define pinstCBazaarSearchWnd_x                                    0xE706E8
#define pinstCGiveWnd_x                                            0xE70708
#define pinstCTrackingWnd_x                                        0xE70710
#define pinstCInspectWnd_x                                         0xE70714
#define pinstCSocialEditWnd_x                                      0xE70718
#define pinstCFeedbackWnd_x                                        0xE7071C
#define pinstCBugReportWnd_x                                       0xE70720
#define pinstCVideoModesWnd_x                                      0xE70724
#define pinstCTextEntryWnd_x                                       0xE7072C
#define pinstCFileSelectionWnd_x                                   0xE70730
#define pinstCCompassWnd_x                                         0xE70734
#define pinstCPlayerNotesWnd_x                                     0xE70738
#define pinstCGemsGameWnd_x                                        0xE7073C
#define pinstCTimeLeftWnd_x                                        0xE70758
#define pinstCPetitionQWnd_x                                       0xE7075C
#define pinstCStoryWnd_x                                           0xE70760
#define pinstCJournalTextWnd_x                                     0xE70764
#define pinstCJournalCatWnd_x                                      0xE70768
#define pinstCBodyTintWnd_x                                        0xE7076C
#define pinstCServerListWnd_x                                      0xE70770
#define pinstCAvaZoneWnd_x                                         0xE7077C
#define pinstCBlockedBuffWnd_x                                     0xE70780
#define pinstCBlockedPetBuffWnd_x                                  0xE70784
#define pinstCInvSlotMgr_x                                         0xE707CC
#define pinstCContainerMgr_x                                       0xE707D0
#define pinstCAdventureLeaderboardWnd_x                            0x10C3DE8
#define pinstCAdventureRequestWnd_x                                0x10C3E60
#define pinstCAltStorageWnd_x                                      0x10C4140
#define pinstCAdventureStatsWnd_x                                  0x10C3ED8
#define pinstCBarterMerchantWnd_x                                  0x10C4E88
#define pinstCBarterSearchWnd_x                                    0x10C4F00
#define pinstCBarterWnd_x                                          0x10C4F78
#define pinstCChatWindowManager_x                                  0x10C5788
#define pinstCDynamicZoneWnd_x                                     0x10C5CB8
#define pinstCEQMainWnd_x                                          0x10C5E80
#define pinstCFellowshipWnd_x                                      0x10C5C4C
#define pinstCFindLocationWnd_x                                    0x10C6150
#define pinstCGroupSearchWnd_x                                     0x10C6420
#define pinstCGroupWnd_x                                           0x10C6498
#define pinstCGuildBankWnd_x                                       0x10C6510
#define pinstCGuildMgmtWnd_x                                       0x10C8600
#define pinstCHotButtonWnd_x                                       0x10C86FC
#define pinstCHotButtonWnd1_x                                      0x10C86FC
#define pinstCHotButtonWnd2_x                                      0x10C8700
#define pinstCHotButtonWnd3_x                                      0x10C8704
#define pinstCHotButtonWnd4_x                                      0x10C8728
#define pinstCItemDisplayManager_x                                 0x10C8B80
#define pinstCItemExpTransferWnd_x                                 0x10C8C7C
#define pinstCLFGuildWnd_x                                         0x10C8F58
#define pinstCMIZoneSelectWnd_x                                    0x10C9538
#define pinstCConfirmationDialog_x                                 0x10C9B50
#define pinstCPopupWndManager_x                                    0x10C9B50
#define pinstCProgressionSelectionWnd_x                            0x10C9C40
#define pinstCPvPStatsWnd_x                                        0x10C9D30
#define pinstCTaskWnd_x                                            0x10CB838
#define pinstCTaskSomething_x                                      0xD3E828
#define pinstCTaskTemplateSelectWnd_x                              0x10CB7C0
#define pinstCTipWndOFDAY_x                                        0x10CB9A0
#define pinstCTipWndCONTEXT_x                                      0x10CB9A4
#define pinstCTitleWnd_x                                           0x10CBA20
#define pinstCContextMenuManager_x                                 0x1731D20
#define pinstCVoiceMacroWnd_x                                      0xFB7F70
#define pinstCHtmlWnd_x                                            0xFB8060
#define pinstItemIconCache_x                                       0x10C5E28
#define pinstCTradeskillWnd_x                                      0x10CBB20
#define pinstCAdvancedLootWnd_x                                    0xE707C0
#define pinstRewardSelectionWnd_x                                  0x10CA258
#define pinstEQSuiteTextureLoader_x                                0xD1BA88

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x54AC10
#define __CastRay2_x                                               0x54A540
#define __HeadingDiff_x                                            0x933CB0
#define __FixHeading_x                                             0x933C40
#define __get_bearing_x                                            0x53A4A0
#define __ConvertItemTags_x                                        0x537F70
#define __ExecuteCmd_x                                             0x522850
#define __EQGetTime_x                                              0x8A3330
#define __get_melee_range_x                                        0x529510
#define __GetGaugeValueFromEQ_x                                    0x7B3520
#define __GetLabelFromEQ_x                                         0x7B48F0
#define __ToggleKeyRingItem_x                                      0x48FD70
#define __GetXTargetType_x                                         0x935920
#define __LoadFrontEnd_x                                           0x640920
#define __NewUIINI_x                                               0x7B2EF0
#define __ProcessGameEvents_x                                      0x584980
#define __ProcessMouseEvent_x                                      0x584120
#define CrashDetected_x                                            0x6422E0
#define wwsCrashReportCheckForUploader_x                           0x8011B0
#define __AppCrashWrapper_x                                        0xC68AC4
#define __pCrashHandler_x                                          0x10D8A00
#define __CrashHandler_x                                           0x800C40
#define wwsCrashReportPlatformLaunchUploader_x                     0x8033E0
#define DrawNetStatus_x                                            0x5BB090
#define Util__FastTime_x                                           0x8A2FD0
#define Expansion_HoT_x                                            0xF327D0
#define __HelpPath_x                                               0xFB5F80
#define __STMLToText_x                                             0x8E95F0
#define __GetAnimationCache_x                                      0x6B0060

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423460
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41E0C0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DE90

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D7FF0
#define AltAdvManager__IsAbilityReady_x                            0x4D8060
#define AltAdvManager__GetAAById_x                                 0x4D8550
#define AltAdvManager__CanTrainAbility_x                           0x4D9180
#define AltAdvManager__CanSeeAbility_x                             0x4D8D40

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46AFF0
#define CharacterZoneClient__HasSkill_x                            0x466F00
#define CharacterZoneClient__MakeMeVisible_x                       0x46CB60
#define CharacterZoneClient__IsStackBlocked_x                      0x44BEF0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B410
#define CharacterZoneClient__GetItemCountWorn_x                    0x465460
#define CharacterZoneClient__GetItemCountInInventory_x             0x465540
#define CharacterZoneClient__GetCursorItemCount_x                  0x465620
#define CharacterZoneClient__FindAffectSlot_x                      0x4515A0
#define CharacterZoneClient__BardCastBard_x                        0x44AB80
#define CharacterZoneClient__GetMaxEffects_x                       0x449710
#define CharacterZoneClient__GetEffect_x                           0x44B640
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451400
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449A60
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FF50

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x670370

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67E170

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x599AB0
#define CButtonWnd__CButtonWnd_x                                   0x8DD830

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x699290
#define CChatManager__InitContextMenu_x                            0x69A3E0
#define CChatManager__FreeChatWindow_x                             0x698D40
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A2520
#define CChatManager__SetLockedActiveChatWindow_x                  0x699260

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E7940
#define CContextMenu__dCContextMenu_x                              0x8E7B50
#define CContextMenu__AddMenuItem_x                                0x8E8070
#define CContextMenu__RemoveMenuItem_x                             0x8E7CD0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E7CF0
#define CContextMenu__CheckMenuItem_x                              0x8E7D70
#define CContextMenu__SetMenuItem_x                                0x8E7BF0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D3E00
#define CContextMenuManager__RemoveMenu_x                          0x8D4180
#define CContextMenuManager__PopupMenu_x                           0x8D45D0
#define CContextMenuManager__Flush_x                               0x8D3E70
#define CContextMenuManager__GetMenu_x                             0x419590

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8874D0
#define CChatService__GetFriendName_x                              0x8874E0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6A0010
#define CChatWindow__Clear_x                                       0x69F8F0
#define CChatWindow__WndNotification_x                             0x6A0910

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D7C30
#define CComboWnd__Draw_x                                          0x8D7E40
#define CComboWnd__GetCurChoice_x                                  0x8D79E0
#define CComboWnd__GetListRect_x                                   0x8D80E0
#define CComboWnd__GetTextRect_x                                   0x8D7CA0
#define CComboWnd__InsertChoice_x                                  0x8D8240
#define CComboWnd__SetColors_x                                     0x8D7970
#define CComboWnd__SetChoice_x                                     0x8D79A0
#define CComboWnd__GetItemCount_x                                  0x8D79D0
#define CComboWnd__GetCurChoiceText_x                              0x8D7A20


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6AA1F0
#define CContainerWnd__vftable_x                                   0xAEE9F8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C5F90
#define CDisplay__GetClickedActor_x                                0x4BE850
#define CDisplay__GetUserDefinedColor_x                            0x4BD430
#define CDisplay__GetWorldFilePath_x                               0x4BC880
#define CDisplay__is3dON_x                                         0x4BBD10
#define CDisplay__ReloadUI_x                                       0x4CFD50
#define CDisplay__WriteTextHD2_x                                   0x4C2320
#define CDisplay__TrueDistance_x                                   0x4BF480

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FEA30

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EBEC0
#define CEditWnd__GetCharIndexPt_x                                 0x8ED020
#define CEditWnd__GetDisplayString_x                               0x8EC070
#define CEditWnd__GetHorzOffset_x                                  0x8EC3B0
#define CEditWnd__GetLineForPrintableChar_x                        0x8ECAE0
#define CEditWnd__GetSelStartPt_x                                  0x8ED2E0
#define CEditWnd__GetSTMLSafeText_x                                0x8EC550
#define CEditWnd__PointFromPrintableChar_x                         0x8ECBD0
#define CEditWnd__SelectableCharFromPoint_x                        0x8ECD50
#define CEditWnd__SetEditable_x                                    0x8EC520

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56B0C0
#define CEverQuest__ClickedPlayer_x                                0x564C90
#define CEverQuest__CreateTargetIndicator_x                        0x565B90
#define CEverQuest__DeleteTargetIndicator_x                        0x565C10
#define CEverQuest__DoTellWindow_x                                 0x476240
#define CEverQuest__OutputTextToLog_x                              0x475EA0
#define CEverQuest__DropHeldItemOnGround_x                         0x57B630
#define CEverQuest__dsp_chat_x                                     0x476580
#define CEverQuest__trimName_x                                     0x5615A0
#define CEverQuest__Emote_x                                        0x579940
#define CEverQuest__EnterZone_x                                    0x574A20
#define CEverQuest__GetBodyTypeDesc_x                              0x55EFE0
#define CEverQuest__GetClassDesc_x                                 0x5684D0
#define CEverQuest__GetClassThreeLetterCode_x                      0x568AD0
#define CEverQuest__GetDeityDesc_x                                 0x55F8C0
#define CEverQuest__GetLangDesc_x                                  0x55F370
#define CEverQuest__GetRaceDesc_x                                  0x568C90
#define CEverQuest__InterpretCmd_x                                 0x56C840
#define CEverQuest__LeftClickedOnPlayer_x                          0x581190
#define CEverQuest__LMouseUp_x                                     0x583140
#define CEverQuest__RightClickedOnPlayer_x                         0x581CA0
#define CEverQuest__RMouseUp_x                                     0x582BA0
#define CEverQuest__SetGameState_x                                 0x565560
#define CEverQuest__UPCNotificationFlush_x                         0x55D970
#define CEverQuest__IssuePetCommand_x                              0x56D220

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BADD0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BAE30
#define CGaugeWnd__Draw_x                                          0x6BB260

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B1A0
#define CGuild__GetGuildName_x                                     0x43B670
#define CGuild__GetGuildIndex_x                                    0x43C880

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D7270

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E4660
#define CInvSlotMgr__MoveItem_x                                    0x6E4E20
#define CInvSlotMgr__SelectSlot_x                                  0x6E3F50

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E33A0
#define CInvSlot__SliderComplete_x                                 0x6E0BC0
#define CInvSlot__GetItemBase_x                                    0x6E0020
#define CInvSlot__UpdateItem_x                                     0x6E05A0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E6280
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E73C0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AF350
#define CItemDisplayWnd__UpdateStrings_x                           0x6E8490
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F4D40
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F5270
#define CItemDisplayWnd__SetItem_x                                 0x6FAAD0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E6490

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EEA30

// CLabel 
#define CLabel__Draw_x                                             0x7018D0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C38A0
#define CListWnd__dCListWnd_x                                      0x8C4B40
#define CListWnd__AddColumn_x                                      0x8C4AE0
#define CListWnd__AddColumn1_x                                     0x8C4180
#define CListWnd__AddLine_x                                        0x8C3B60
#define CListWnd__AddString_x                                      0x8C3D80
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C0990
#define CListWnd__CalculateVSBRange_x                              0x8C2D60
#define CListWnd__ClearSel_x                                       0x8BFCB0
#define CListWnd__ClearAllSel_x                                    0x8BFC60
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C3730
#define CListWnd__Compare_x                                        0x8C1690
#define CListWnd__Draw_x                                           0x8C2960
#define CListWnd__DrawColumnSeparators_x                           0x8C27F0
#define CListWnd__DrawHeader_x                                     0x8BFF70
#define CListWnd__DrawItem_x                                       0x8C1D20
#define CListWnd__DrawLine_x                                       0x8C2490
#define CListWnd__DrawSeparator_x                                  0x8C2890
#define CListWnd__EnableLine_x                                     0x8BFE90
#define CListWnd__EnsureVisible_x                                  0x8C0AF0
#define CListWnd__ExtendSel_x                                      0x8C1C30
#define CListWnd__GetColumnMinWidth_x                              0x8BF5A0
#define CListWnd__GetColumnWidth_x                                 0x8BF4D0
#define CListWnd__GetCurSel_x                                      0x8BECB0
#define CListWnd__GetItemAtPoint_x                                 0x8C0D90
#define CListWnd__GetItemAtPoint1_x                                0x8C0E00
#define CListWnd__GetItemData_x                                    0x8BEFE0
#define CListWnd__GetItemHeight_x                                  0x8C05F0
#define CListWnd__GetItemIcon_x                                    0x8BF1D0
#define CListWnd__GetItemRect_x                                    0x8C0BD0
#define CListWnd__GetItemText_x                                    0x8BF080
#define CListWnd__GetSelList_x                                     0x8C4070
#define CListWnd__GetSeparatorRect_x                               0x8C15B0
#define CListWnd__InsertLine_x                                     0x8C3F60
#define CListWnd__RemoveLine_x                                     0x8C3F70
#define CListWnd__SetColors_x                                      0x8BEE00
#define CListWnd__SetColumnJustification_x                         0x8BF830
#define CListWnd__SetColumnWidth_x                                 0x8BF550
#define CListWnd__SetCurSel_x                                      0x8BECF0
#define CListWnd__SetItemColor_x                                   0x8C3420
#define CListWnd__SetItemData_x                                    0x8BFD10
#define CListWnd__SetItemText_x                                    0x8C3260
#define CListWnd__ShiftColumnSeparator_x                           0x8C30F0
#define CListWnd__Sort_x                                           0x8C4C40
#define CListWnd__ToggleSel_x                                      0x8BFBE0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71A9D0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x740120
#define CMerchantWnd__RequestBuyItem_x                             0x747CD0
#define CMerchantWnd__RequestSellItem_x                            0x74A2E0
#define CMerchantWnd__SelectRecoverySlot_x                         0x73D3D0
#define CMerchantWnd__SelectBuySellSlot_x                          0x73B260
#define CMerchantWnd__ActualSelect_x                               0x741F00

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8557C0
#define CPacketScrambler__hton_x                                   0x8557D0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E2820
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E2900
#define CSidlManager__CreateLabel_x                                0x7A4350
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E0DD0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E2BE0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D9C80
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D9B70
#define CSidlScreenWnd__ConvertToRes_x                             0x8FE910
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8DA590
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DB760
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DB810
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DACE0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D9F40
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D96A0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8DA130
#define CSidlScreenWnd__Init1_x                                    0x8DB430
#define CSidlScreenWnd__LoadIniInfo_x                              0x8DA640
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D9860
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DAF20
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D9300
#define CSidlScreenWnd__StoreIniVis_x                              0x8D9650
#define CSidlScreenWnd__WndNotification_x                          0x8DB1B0
#define CSidlScreenWnd__GetChildItem_x                             0x8D9770
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CCFD0
#define CSidlScreenWnd__m_layoutCopy_x                             0x1731E40

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6060F0
#define CSkillMgr__GetSkillCap_x                                   0x6062D0
#define CSkillMgr__GetNameToken_x                                  0x605CA0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FDBD0
#define CSliderWnd__SetValue_x                                     0x8FDDA0
#define CSliderWnd__SetNumTicks_x                                  0x8FE520

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7AA640

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F7970
#define CStmlWnd__CalculateHSBRange_x                              0x8EFEC0
#define CStmlWnd__CalculateVSBRange_x                              0x8EFE30
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F0040
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F0840
#define CStmlWnd__ForceParseNow_x                                  0x8F82F0
#define CStmlWnd__GetNextTagPiece_x                                0x8F0740
#define CStmlWnd__GetSTMLText_x                                    0x484400
#define CStmlWnd__GetVisibleText_x                                 0x8F1290
#define CStmlWnd__InitializeWindowVariables_x                      0x8F3860
#define CStmlWnd__MakeStmlColorTag_x                               0x8EF110
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EF170
#define CStmlWnd__SetSTMLText_x                                    0x8F50B0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F7610
#define CStmlWnd__UpdateHistoryString_x                            0x8F21D0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FB820
#define CTabWnd__DrawCurrentPage_x                                 0x8FB0B0
#define CTabWnd__DrawTab_x                                         0x8FAE70
#define CTabWnd__GetCurrentPage_x                                  0x8FB460
#define CTabWnd__GetPageInnerRect_x                                0x8FAB60
#define CTabWnd__GetTabInnerRect_x                                 0x8FAD60
#define CTabWnd__GetTabRect_x                                      0x8FAC30
#define CTabWnd__InsertPage_x                                      0x8FBB10
#define CTabWnd__SetPage_x                                         0x8FB490
#define CTabWnd__SetPageRect_x                                     0x8FB760
#define CTabWnd__UpdatePage_x                                      0x8FBAB0
#define CTabWnd__GetPageFromTabIndex_x                             0x8FADC0
#define CTabWnd__GetCurrentTabIndex_x                              0x8FAAF0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E7570
#define CPageWnd__SetTabText_x                                     0x907CF0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436D90

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D75E0
#define CTextureFont__GetTextExtent_x                              0x8D7340

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63EBC0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x904130

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BCF10

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029D0
#define CXStr__CXStr1_x                                            0x751BB0
#define CXStr__CXStr3_x                                            0x8A0220
#define CXStr__dCXStr_x                                            0x47C180
#define CXStr__operator_equal_x                                    0x8A0390
#define CXStr__operator_equal1_x                                   0x8A03E0
#define CXStr__operator_plus_equal1_x                              0x8A14E0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D50E0
#define CXWnd__BringToTop_x                                        0x8CC1D0
#define CXWnd__Center_x                                            0x8D2400
#define CXWnd__ClrFocus_x                                          0x8CBDB0
#define CXWnd__Destroy_x                                           0x8D2EE0
#define CXWnd__DoAllDrawing_x                                      0x8D2050
#define CXWnd__DrawChildren_x                                      0x8D21F0
#define CXWnd__DrawColoredRect_x                                   0x8CC5B0
#define CXWnd__DrawTooltip_x                                       0x8CC860
#define CXWnd__DrawTooltipAtPoint_x                                0x8D0FB0
#define CXWnd__GetBorderFrame_x                                    0x8CCCC0
#define CXWnd__GetChildWndAt_x                                     0x8D2DD0
#define CXWnd__GetClientClipRect_x                                 0x8CCA80
#define CXWnd__GetScreenClipRect_x                                 0x8D16B0
#define CXWnd__GetScreenRect_x                                     0x8CCE70
#define CXWnd__GetTooltipRect_x                                    0x8CC6F0
#define CXWnd__GetWindowTextA_x                                    0x427010
#define CXWnd__IsActive_x                                          0x8C78B0
#define CXWnd__IsDescendantOf_x                                    0x8CCC10
#define CXWnd__IsReallyVisible_x                                   0x8CFFD0
#define CXWnd__IsType_x                                            0x8D2470
#define CScreenPieceTemplate__IsType_x                             0x9007B0
#define CXWnd__Move_x                                              0x8CF6B0
#define CXWnd__Move1_x                                             0x8D1D00
#define CXWnd__ProcessTransition_x                                 0x8CC170
#define CXWnd__Refade_x                                            0x8CBF40
#define CXWnd__Resize_x                                            0x8CCF30
#define CXWnd__Right_x                                             0x8D14B0
#define CXWnd__SetFocus_x                                          0x8CE800
#define CXWnd__SetFont_x                                           0x8CBE00
#define CXWnd__SetKeyTooltip_x                                     0x8CD1A0
#define CXWnd__SetMouseOver_x                                      0x8D19F0
#define CXWnd__StartFade_x                                         0x8CC220
#define CXWnd__GetChildItem_x                                      0x8D1930
#define CXWnd__SetParent_x                                         0x8D2D80

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C9170
#define CXWndManager__DrawWindows_x                                0x8C8DB0
#define CXWndManager__GetKeyboardFlags_x                           0x8C7420
#define CXWndManager__HandleKeyboardMsg_x                          0x8C7D50
#define CXWndManager__RemoveWnd_x                                  0x8C7A40

// CDBStr
#define CDBStr__GetString_x                                        0x4BA560

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452660
#define EQ_Character__Cur_HP_x                                     0x466AE0
#define EQ_Character__Cur_Mana_x                                   0x45BAD0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B720
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443740
#define EQ_Character__GetFocusRangeModifier_x                      0x443890
#define EQ_Character__GetHPRegen_x                                 0x46A680
#define EQ_Character__GetEnduranceRegen_x                          0x4660F0
#define EQ_Character__GetManaRegen_x                               0x46AC20
#define EQ_Character__Max_Endurance_x                              0x5CCC10
#define EQ_Character__Max_HP_x                                     0x45E650
#define EQ_Character__Max_Mana_x                                   0x5CCA40
#define EQ_Character__doCombatAbility_x                            0x5CA110
#define EQ_Character__UseSkill_x                                   0x472A10
#define EQ_Character__GetConLevel_x                                0x5BF670
#define EQ_Character__IsExpansionFlag_x                            0x4B67E0
#define EQ_Character__TotalEffect_x                                0x44F890
#define EQ_Character__GetPCSpellAffect_x                           0x44BAB0
#define EQ_Character__SpellDuration_x                              0x449AB0
#define EQ_Character__FindItemByRecord_x                           0x464130
#define EQ_Character__GetAdjustedSkill_x                           0x466CB0
#define EQ_Character__GetBaseSkill_x                               0x45E530

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8736A0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D5290

//PcClient
#define PcClient__PcClient_x                                       0x5C14C0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446BC0
#define CCharacterSelect__EnterWorld_x                             0x446390
#define CCharacterSelect__Quit_x                                   0x444F50

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59F470
#define EQ_Item__CreateItemTagString_x                             0x853970
#define EQ_Item__IsStackable_x                                     0x848DC0
#define EQ_Item__GetImageNum_x                                     0x84B950
#define EQ_Item__CreateItemClient_x                                0x5A0580
#define EQ_Item__GetItemValue_x                                    0x8523F0
#define EQ_Item__ValueSellMerchant_x                               0x855420
#define EQ_Item__IsKeyRingItem_x                                   0x849950
#define EQ_Item__CanGoInBag_x                                      0x59F600
#define EQ_Item__GetMaxItemCount_x                                 0x848CB0
#define EQ_Item__GetHeldItem_x                                     0x84A760
#define EQ_Item__GetAugmentFitBySlot_x                             0x855240

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA5C0
#define EQ_LoadingS__Array_x                                       0xC0CC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CF140
#define EQ_PC__GetAlternateAbilityId_x                             0x85D8F0
#define EQ_PC__GetCombatAbility_x                                  0x85D980
#define EQ_PC__GetCombatAbilityTimer_x                             0x858470
#define EQ_PC__GetItemRecastTimer_x                                0x5C8900
#define EQ_PC__HasLoreItem_x                                       0x5C2C80
#define EQ_PC__AlertInventoryChanged_x                             0x5BF620
#define EQ_PC__GetPcZoneClient_x                                   0x5E9820
#define EQ_PC__RemoveMyAffect_x                                    0x5C7D30
#define EQ_PC__GetKeyRingItems_x                                   0x858890
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86B600
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85F890

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5275A0
#define EQItemList__add_object_x                                   0x554820
#define EQItemList__add_item_x                                     0x5274E0
#define EQItemList__delete_item_x                                  0x527990
#define EQItemList__FreeItemList_x                                 0x527890

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B97F0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D4F50
#define EQPlayer__dEQPlayer_x                                      0x5DD700
#define EQPlayer__DoAttack_x                                       0x5EF000
#define EQPlayer__EQPlayer_x                                       0x5DFE20
#define EQPlayer__SetNameSpriteState_x                             0x5DA530
#define EQPlayer__SetNameSpriteTint_x                              0x5D6450
#define PlayerBase__HasProperty_j_x                                0x9320C0
#define EQPlayer__IsTargetable_x                                   0x932360
#define EQPlayer__CanSee_x                                         0x9328C0
#define PlayerZoneClient__ChangeHeight_x                           0x5EEEC0
#define EQPlayer__CanSee1_x                                        0x9329B0
#define PlayerBase__GetVisibilityLineSegment_x                     0x932650

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E99D0
#define PlayerZoneClient__IsValidTeleport_x                        0x5550C0
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2940


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E3E60
#define EQPlayerManager__GetSpawnByName_x                          0x5E42C0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E3E90

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A5A80
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A5AC0
#define KeypressHandler__ClearCommandStateArray_x                  0x5A5670
#define KeypressHandler__HandleKeyDown_x                           0x5A3F90
#define KeypressHandler__HandleKeyUp_x                             0x5A42B0
#define KeypressHandler__SaveKeymapping_x                          0x5A5740

// MapViewMap 
#define MapViewMap__Clear_x                                        0x713360
#define MapViewMap__SaveEx_x                                       0x716690
#define MapViewMap__SetZoom_x                                      0x712FE0

#define PlayerPointManager__GetAltCurrency_x                       0x871760

// StringTable 
#define StringTable__getString_x                                   0x86B930

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CC6A0
#define PcZoneClient__RemovePetEffect_x                            0x5C8DD0
#define PcZoneClient__HasAlternateAbility_x                        0x5C9770
#define PcZoneClient__GetCurrentMod_x                              0x45DB00
#define PcZoneClient__GetModCap_x                                  0x45B230
#define PcZoneClient__CanEquipItem_x                               0x5C9C50
#define PcZoneClient__GetItemByID_x                                0x5CE4B0
#define PcZoneClient__GetItemByItemClass_x                         0x5CF060
#define PcZoneClient__RemoveBuffEffect_x                           0x5C7FE0

//Doors
#define EQSwitch__UseSwitch_x                                      0x55C1F0

//IconCache
#define IconCache__GetIcon_x                                       0x6B0690

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A7590
#define CContainerMgr__CloseContainer_x                            0x6A7DB0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x774150

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5984E0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F4CA0
#define EQ_Spell__SpellAffects_x                                   0x4F1E80
#define EQ_Spell__SpellAffectBase_x                                0x4F1EF0
#define CharacterZoneClient__CalcAffectChange_x                    0x44B940
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44ABE0
#define CLootWnd__LootAll_x                                        0x708BB0
#define CLootWnd__RequestLootSlot_x                                0x7093C0
#define EQ_Spell__IsStackable_x                                    0x459150
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449560
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EC90
#define EQ_Spell__IsSPAStacking_x                                  0x4F19F0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2A90
#define EQ_Spell__IsNoRemove_x                                     0x434DF0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F1A10

#define __IsResEffectSpell_x                                       0x449600

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87D350

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BBF80
#define CTargetWnd__WndNotification_x                              0x7BBA70
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BC160

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C10A0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED550
#define EqSoundManager__PlayScriptMp3_x                            0x4EEFF0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8860

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EB4D0
#define CSidlManager__FindAnimation1_x                             0x8E0800

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E1F20
#define CAltAbilityData__GetMercMaxRank_x                          0x4E1ED0
#define CAltAbilityData__GetMaxRank_x                              0x4D66A0

//CTargetRing
#define CTargetRing__Cast_x                                        0x596110

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4594B0
#define CharacterBase__CreateItemGlobalIndex_x                     0x475440
#define CharacterBase__CreateItemIndex_x                           0x520BB0
#define CharacterBase__GetItemPossession_x                         0x444400
#define CharacterBase__GetItemByGlobalIndex_x                      0x8811A0
#define CharacterBase__GetEffectId_x                               0x459470

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6904F0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68FC50

//messages
#define msg_spell_worn_off_x                                       0x4FC820
#define msg_new_text_x                                             0x505FA0
#define msgTokenTextParam_x                                        0x5027A0

//SpellManager
#define SpellManager__vftable_x                                    0xACA280
#define SpellManager__SpellManager_x                               0x47E030
#define Spellmanager__LoadTextSpells_x                             0x60D020

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x936440

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487DE0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EBB0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x4492B0
#define ItemGlobalIndex__IsValidIndex_x                            0x458C90

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87F010
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87DF50

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x701B20

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AC2B0
#define CCursorAttachment__Deactivate_x                            0x6AB800

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FD0D0
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FD250

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                        0x604BF0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C640

//IString
#define IString__Append_x                                          0x47EC60

//Camera
#define CDisplay__cameraType_x                                     0xE707E8
#define EverQuest__Cameras_x                                       0xF32AE8
