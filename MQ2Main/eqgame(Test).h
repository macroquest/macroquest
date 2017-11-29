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
#define __ExpectedVersionDate                                     "Nov 28 2017"
#define __ExpectedVersionTime                                     "12:05:38"
#define __ActualVersionDate_x                                      0xAE4078
#define __ActualVersionTime_x                                      0xAE4084

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x5AA8F0
#define __MemChecker1_x                                            0x8A3440
#define __MemChecker2_x                                            0x640350
#define __MemChecker3_x                                            0x6402A0
#define __MemChecker4_x                                            0x7F4F60
#define __EncryptPad0_x                                            0xC3EC10
#define __EncryptPad1_x                                            0xD18050
#define __EncryptPad2_x                                            0xC67978
#define __EncryptPad3_x                                            0xC67578
#define __EncryptPad4_x                                            0xD06650
#define __EncryptPad5_x                                            0x10C1668
#define __AC1_x                                                    0x7B3F65
#define __AC2_x                                                    0x563C17
#define __AC3_x                                                    0x561D90
#define __AC4_x                                                    0x573F51
#define __AC5_x                                                    0x587CAB
#define __AC6_x                                                    0x58B84E
#define __AC7_x                                                    0x5822AC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FA7610

// Direct Input
#define DI8__Main_x                                                0x10C1640
#define DI8__Keyboard_x                                            0x10C1644
#define DI8__Mouse_x                                               0x10C1648
#define DI8__Mouse_Copy_x                                          0xF2F8F4
#define DI8__Mouse_Check_x                                         0xFB932C
#define __AutoSkillArray_x                                         0xF30808
#define __Attack_x                                                 0xFB3E03
#define __Autofire_x                                               0xFB3E04
#define __BindList_x                                               0xC1B0C8
#define g_eqCommandStates_x                                        0xF1E640
#define __Clicks_x                                                 0xF2F9B0
#define __CommandList_x                                            0xC1D7C8
#define __CurrentMapLabel_x                                        0x10C7638
#define __CurrentSocial_x                                          0xBEA800
#define __DoAbilityList_x                                          0xF660B8
#define __do_loot_x                                                0x5329A0
#define __DrawHandler_x                                            0x172EACC
#define __GroupCount_x                                             0xF1FF4A

#define __Guilds_x                                                 0xF25B60
#define __gWorld_x                                                 0xF22404
#define __HotkeyPage_x                                             0xFACAB8
#define __HWnd_x                                                   0xFB9448
#define __InChatMode_x                                             0xF2F8DC
#define __LastTell_x                                               0xF317B4
#define __LMouseHeldTime_x                                         0xF2FA1C
#define __Mouse_x                                                  0x10C164C
#define __MouseLook_x                                              0xF2F976
#define __MouseEventTime_x                                         0xFB459C
#define __gpbCommandEvent_x                                        0xF224CC
#define __NetStatusToggle_x                                        0xF2F979
#define __PCNames_x                                                0xF30DC4
#define __RangeAttackReady_x                                       0xF30AEC
#define __RMouseHeldTime_x                                         0xF2FA18
#define __RunWalkState_x                                           0xF2F8E0
#define __ScreenMode_x                                             0xE6E220
#define __ScreenX_x                                                0xF2F894
#define __ScreenY_x                                                0xF2F890
#define __ScreenXMax_x                                             0xF2F898
#define __ScreenYMax_x                                             0xF2F89C
#define __ServerHost_x                                             0xF1FE94
#define __ServerName_x                                             0xF66078
#define __ShiftKeyDown_x                                           0xF2FF70
#define __ShowNames_x                                              0xF30CA4
#define __Socials_x                                                0xF66178
#define __SubscriptionType_x                                       0x10F55D4
#define __TargetAggroHolder_x                                      0x10C9794
#define __ZoneType_x                                               0xF2FD74
#define __GroupAggro_x                                             0x10C97D4
#define __LoginName_x                                              0xFB7F24
#define __Inviter_x                                                0xFB3D80
#define __AttackOnAssist_x                                         0xF30C60
#define __UseTellWindows_x                                         0xF30F5C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF224F0
#define instEQZoneInfo_x                                           0xF2FB6C
#define instKeypressHandler_x                                      0xFB4580
#define pinstActiveBanker_x                                        0xF224A8
#define pinstActiveCorpse_x                                        0xF224AC
#define pinstActiveGMaster_x                                       0xF224B0
#define pinstActiveMerchant_x                                      0xF224A4
#define pinstAggroInfo_x                                           0xD2B88C
#define pinstAltAdvManager_x                                       0xE6F388
#define pinstAuraMgr_x                                             0xD3C090
#define pinstBandageTarget_x                                       0xF22490
#define pinstCamActor_x                                            0xE6EC58
#define pinstCDBStr_x                                              0xE6E1B4
#define pinstCDisplay_x                                            0xF224B8
#define pinstCEverQuest_x                                          0x10C17C0
#define pinstEverQuestInfo_x                                       0xF2F888
#define pinstCharData_x                                            0xF22474
#define pinstCharSpawn_x                                           0xF2249C
#define pinstControlledMissile_x                                   0xF22470
#define pinstControlledPlayer_x                                    0xF2249C
#define pinstCSidlManager_x                                        0x172DA38
#define pinstCXWndManager_x                                        0x172DA30
#define instDynamicZone_x                                          0xF2F728
#define pinstDZMember_x                                            0xF2F838
#define pinstDZTimerInfo_x                                         0xF2F83C
#define pinstEQItemList_x                                          0xF1E918
#define pinstEQObjectList_x                                        0xF1F944
#define instEQMisc_x                                               0xC035D0
#define pinstEQSoundManager_x                                      0xE6F958
#define instExpeditionLeader_x                                     0xF2F772
#define instExpeditionName_x                                       0xF2F7B2
#define pinstGroup_x                                               0xF1FF46
#define pinstImeManager_x                                          0x172DA3C
#define pinstLocalPlayer_x                                         0xF22488
#define pinstMercenaryData_x                                       0xFB4BE8
#define pinstMercenaryStats_x                                      0x10C98E0
#define pinstMercAltAbilities_x                                    0xE6F710
#define pinstModelPlayer_x                                         0xF224B4
#define pinstPCData_x                                              0xF22474
#define pinstSkillMgr_x                                            0xFB5BE0
#define pinstSpawnManager_x                                        0xFB5438
#define pinstSpellManager_x                                        0xFB5D28
#define pinstSpellSets_x                                           0xFACB1C
#define pinstStringTable_x                                         0xF2241C
#define pinstSwitchManager_x                                       0xF1FAD8
#define pinstTarget_x                                              0xF224A0
#define pinstTargetObject_x                                        0xF22478
#define pinstTargetSwitch_x                                        0xF2247C
#define pinstTaskMember_x                                          0xE6E100
#define pinstTrackTarget_x                                         0xF22494
#define pinstTradeTarget_x                                         0xF22484
#define instTributeActive_x                                        0xC035F5
#define pinstViewActor_x                                           0xE6EC54
#define pinstWorldData_x                                           0xF22458
#define pinstZoneAddr_x                                            0xF2FE0C
#define pinstPlayerPath_x                                          0xFB5498
#define pinstTargetIndicator_x                                     0xFB5EC0
#define pinstCTargetManager_x                                      0xFB5F20
#define EQObject_Top_x                                             0xF22468
#define pinstRealEstateItems_x                                     0xFB5A4C

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE6EB70
#define pinstCAchievementsWnd_x                                    0xE6EBCC
#define pinstCTextOverlay_x                                        0xD2BE20
#define pinstCAudioTriggersWindow_x                                0xD2BC08
#define pinstCCharacterSelect_x                                    0xE6EADC
#define pinstCFacePick_x                                           0xE6E88C
#define pinstCFindItemWnd_x                                        0xE6EB6C
#define pinstCNoteWnd_x                                            0xE6EA94
#define pinstCBookWnd_x                                            0xE6EA9C
#define pinstCPetInfoWnd_x                                         0xE6EAA0
#define pinstCTrainWnd_x                                           0xE6EAA4
#define pinstCSkillsWnd_x                                          0xE6EAA8
#define pinstCSkillsSelectWnd_x                                    0xE6EAAC
#define pinstCCombatSkillsSelectWnd_x                              0xE6EAB0
#define pinstCFriendsWnd_x                                         0xE6EAB4
#define pinstCAuraWnd_x                                            0xE6EAB8
#define pinstCRespawnWnd_x                                         0xE6EABC
#define pinstCBandolierWnd_x                                       0xE6EAC0
#define pinstCPotionBeltWnd_x                                      0xE6EAC4
#define pinstCAAWnd_x                                              0xE6EAC8
#define pinstCGroupSearchFiltersWnd_x                              0xE6EACC
#define pinstCLoadskinWnd_x                                        0xE6EAD0
#define pinstCAlarmWnd_x                                           0xE6EAD4
#define pinstCMusicPlayerWnd_x                                     0xE6EAD8
#define pinstCMailWnd_x                                            0xE6EAE0
#define pinstCMailCompositionWnd_x                                 0xE6EAE4
#define pinstCMailAddressBookWnd_x                                 0xE6EAE8
#define pinstCRaidWnd_x                                            0xE6EAF0
#define pinstCRaidOptionsWnd_x                                     0xE6EAF4
#define pinstCBreathWnd_x                                          0xE6EAF8
#define pinstCMapViewWnd_x                                         0xE6EAFC
#define pinstCMapToolbarWnd_x                                      0xE6EB00
#define pinstCEditLabelWnd_x                                       0xE6EB04
#define pinstCTargetWnd_x                                          0xE6EB08
#define pinstCColorPickerWnd_x                                     0xE6EB0C
#define pinstCPlayerWnd_x                                          0xE6EB10
#define pinstCOptionsWnd_x                                         0xE6EB14
#define pinstCBuffWindowNORMAL_x                                   0xE6EB18
#define pinstCBuffWindowSHORT_x                                    0xE6EB1C
#define pinstCharacterCreation_x                                   0xE6EB20
#define pinstCCursorAttachment_x                                   0xE6EB24
#define pinstCCastingWnd_x                                         0xE6EB28
#define pinstCCastSpellWnd_x                                       0xE6EB2C
#define pinstCSpellBookWnd_x                                       0xE6EB30
#define pinstCInventoryWnd_x                                       0xE6EB34
#define pinstCBankWnd_x                                            0xE6EB3C
#define pinstCQuantityWnd_x                                        0xE6EB40
#define pinstCLootWnd_x                                            0xE6EB44
#define pinstCActionsWnd_x                                         0xE6EB48
#define pinstCCombatAbilityWnd_x                                   0xE6EB50
#define pinstCMerchantWnd_x                                        0xE6EB54
#define pinstCTradeWnd_x                                           0xE6EB5C
#define pinstCSelectorWnd_x                                        0xE6EB60
#define pinstCBazaarWnd_x                                          0xE6EB64
#define pinstCBazaarSearchWnd_x                                    0xE6EB68
#define pinstCGiveWnd_x                                            0xE6EB88
#define pinstCTrackingWnd_x                                        0xE6EB90
#define pinstCInspectWnd_x                                         0xE6EB94
#define pinstCSocialEditWnd_x                                      0xE6EB98
#define pinstCFeedbackWnd_x                                        0xE6EB9C
#define pinstCBugReportWnd_x                                       0xE6EBA0
#define pinstCVideoModesWnd_x                                      0xE6EBA4
#define pinstCTextEntryWnd_x                                       0xE6EBAC
#define pinstCFileSelectionWnd_x                                   0xE6EBB0
#define pinstCCompassWnd_x                                         0xE6EBB4
#define pinstCPlayerNotesWnd_x                                     0xE6EBB8
#define pinstCGemsGameWnd_x                                        0xE6EBBC
#define pinstCTimeLeftWnd_x                                        0xE6EBD8
#define pinstCPetitionQWnd_x                                       0xE6EBDC
#define pinstCStoryWnd_x                                           0xE6EBE0
#define pinstCJournalTextWnd_x                                     0xE6EBE4
#define pinstCJournalCatWnd_x                                      0xE6EBE8
#define pinstCBodyTintWnd_x                                        0xE6EBEC
#define pinstCServerListWnd_x                                      0xE6EBF0
#define pinstCAvaZoneWnd_x                                         0xE6EBFC
#define pinstCBlockedBuffWnd_x                                     0xE6EC00
#define pinstCBlockedPetBuffWnd_x                                  0xE6EC04
#define pinstCInvSlotMgr_x                                         0xE6EC4C
#define pinstCContainerMgr_x                                       0xE6EC50
#define pinstCAdventureLeaderboardWnd_x                            0x10C2170
#define pinstCAdventureRequestWnd_x                                0x10C21E8
#define pinstCAltStorageWnd_x                                      0x10C24C8
#define pinstCAdventureStatsWnd_x                                  0x10C2260
#define pinstCBarterMerchantWnd_x                                  0x10C3210
#define pinstCBarterSearchWnd_x                                    0x10C3288
#define pinstCBarterWnd_x                                          0x10C3300
#define pinstCChatWindowManager_x                                  0x10C3B10
#define pinstCDynamicZoneWnd_x                                     0x10C4040
#define pinstCEQMainWnd_x                                          0x10C4208
#define pinstCFellowshipWnd_x                                      0x10C3FD4
#define pinstCFindLocationWnd_x                                    0x10C44D8
#define pinstCGroupSearchWnd_x                                     0x10C47A8
#define pinstCGroupWnd_x                                           0x10C4820
#define pinstCGuildBankWnd_x                                       0x10C4898
#define pinstCGuildMgmtWnd_x                                       0x10C6988
#define pinstCHotButtonWnd_x                                       0x10C6A84
#define pinstCHotButtonWnd1_x                                      0x10C6A84
#define pinstCHotButtonWnd2_x                                      0x10C6A88
#define pinstCHotButtonWnd3_x                                      0x10C6A8C
#define pinstCHotButtonWnd4_x                                      0x10C6AB0
#define pinstCItemDisplayManager_x                                 0x10C6F08
#define pinstCItemExpTransferWnd_x                                 0x10C7004
#define pinstCLFGuildWnd_x                                         0x10C72E0
#define pinstCMIZoneSelectWnd_x                                    0x10C78C0
#define pinstCConfirmationDialog_x                                 0x10C7ED8
#define pinstCPopupWndManager_x                                    0x10C7ED8
#define pinstCProgressionSelectionWnd_x                            0x10C7FC8
#define pinstCPvPStatsWnd_x                                        0x10C80B8
#define pinstCLargeDialogWnd_x                                     0x10C8840
#define pinstCTaskWnd_x                                            0x10C9BC0
#define pinstCTaskSomething_x                                      0xD3CCA8
#define pinstCTaskTemplateSelectWnd_x                              0x10C9B48
#define pinstCTipWndOFDAY_x                                        0x10C9D28
#define pinstCTipWndCONTEXT_x                                      0x10C9D2C
#define pinstCTitleWnd_x                                           0x10C9DA8
#define pinstCContextMenuManager_x                                 0x172D8C0
#define pinstCVoiceMacroWnd_x                                      0xFB62F8
#define pinstCHtmlWnd_x                                            0xFB63E8
#define pinstItemIconCache_x                                       0x10C41B0
#define pinstCTradeskillWnd_x                                      0x10C9EA8
#define pinstCAdvancedLootWnd_x                                    0xE6EC40
#define pinstRewardSelectionWnd_x                                  0x10C85E0
#define pinstEQSuiteTextureLoader_x                                0xD19F18

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x54A4B0
#define __CastRay2_x                                               0x549DE0
#define __HeadingDiff_x                                            0x933870
#define __FixHeading_x                                             0x933800
#define __get_bearing_x                                            0x539AF0
#define __ConvertItemTags_x                                        0x5375C0
#define __ExecuteCmd_x                                             0x521F40
#define __EQGetTime_x                                              0x8A2DE0
#define __get_melee_range_x                                        0x528BC0
#define __GetGaugeValueFromEQ_x                                    0x7B2B20
#define __GetLabelFromEQ_x                                         0x7B3EF0
#define __ToggleKeyRingItem_x                                      0x48FE20
#define __GetXTargetType_x                                         0x935470
#define __LoadFrontEnd_x                                           0x63FA20
#define __NewUIINI_x                                               0x7B2500
#define __ProcessGameEvents_x                                      0x584040
#define __ProcessMouseEvent_x                                      0x5837E0
#define CrashDetected_x                                            0x6413E0
#define wwsCrashReportCheckForUploader_x                           0x800BD0
#define __AppCrashWrapper_x                                        0xC6756C
#define __pCrashHandler_x                                          0x10D6D88
#define __CrashHandler_x                                           0x800660
#define wwsCrashReportPlatformLaunchUploader_x                     0x802E10
#define DrawNetStatus_x                                            0x5BA410
#define Util__FastTime_x                                           0x8A2A80
#define Expansion_HoT_x                                            0xF30C50
#define __HelpPath_x                                               0xFB4308
#define __STMLToText_x                                             0x8E9470
#define __GetAnimationCache_x                                      0x6AF2C0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423490
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41E0F0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DEC0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D7FE0
#define AltAdvManager__IsAbilityReady_x                            0x4D8050
#define AltAdvManager__GetAAById_x                                 0x4D8540
#define AltAdvManager__CanTrainAbility_x                           0x4D9170
#define AltAdvManager__CanSeeAbility_x                             0x4D8D30

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x469CE0
#define CharacterZoneClient__HasSkill_x                            0x465D50
#define CharacterZoneClient__MakeMeVisible_x                       0x46B850
#define CharacterZoneClient__IsStackBlocked_x                      0x44BFE0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B500
#define CharacterZoneClient__GetItemCountWorn_x                    0x4642B0
#define CharacterZoneClient__GetItemCountInInventory_x             0x464390
#define CharacterZoneClient__GetCursorItemCount_x                  0x464470
#define CharacterZoneClient__FindAffectSlot_x                      0x451690
#define CharacterZoneClient__BardCastBard_x                        0x44AC70
#define CharacterZoneClient__GetMaxEffects_x                       0x449800
#define CharacterZoneClient__GetEffect_x                           0x44B730
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4514F0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449B50
#define CharacterZoneClient__GetLastEffectSlot_x                   0x450040

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66F2F0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67D400

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x599140
#define CButtonWnd__CButtonWnd_x                                   0x8DD630

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x698310
#define CChatManager__InitContextMenu_x                            0x699460
#define CChatManager__FreeChatWindow_x                             0x697DC0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A1600
#define CChatManager__SetLockedActiveChatWindow_x                  0x6982E0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E77C0
#define CContextMenu__dCContextMenu_x                              0x8E79D0
#define CContextMenu__AddMenuItem_x                                0x8E7EF0
#define CContextMenu__RemoveMenuItem_x                             0x8E7B50
#define CContextMenu__RemoveAllMenuItems_x                         0x8E7B70
#define CContextMenu__CheckMenuItem_x                              0x8E7BF0
#define CContextMenu__SetMenuItem_x                                0x8E7A70

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D3C00
#define CContextMenuManager__RemoveMenu_x                          0x8D3FA0
#define CContextMenuManager__PopupMenu_x                           0x8D43F0
#define CContextMenuManager__Flush_x                               0x8D3C70
#define CContextMenuManager__GetMenu_x                             0x419610

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x886F30
#define CChatService__GetFriendName_x                              0x886F40

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69F0D0
#define CChatWindow__Clear_x                                       0x69E9B0
#define CChatWindow__WndNotification_x                             0x69F9E0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D7A50
#define CComboWnd__Draw_x                                          0x8D7C60
#define CComboWnd__GetCurChoice_x                                  0x8D7800
#define CComboWnd__GetListRect_x                                   0x8D7F00
#define CComboWnd__GetTextRect_x                                   0x8D7AC0
#define CComboWnd__InsertChoice_x                                  0x8D8060
#define CComboWnd__SetColors_x                                     0x8D7790
#define CComboWnd__SetChoice_x                                     0x8D77C0
#define CComboWnd__GetItemCount_x                                  0x8D77F0
#define CComboWnd__GetCurChoiceText_x                              0x8D7840

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A9450
#define CContainerWnd__vftable_x                                   0xAED990

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C5F60
#define CDisplay__GetClickedActor_x                                0x4BE820
#define CDisplay__GetUserDefinedColor_x                            0x4BD400
#define CDisplay__GetWorldFilePath_x                               0x4BC850
#define CDisplay__is3dON_x                                         0x4BBCE0
#define CDisplay__ReloadUI_x                                       0x4CFD20
#define CDisplay__WriteTextHD2_x                                   0x4C22F0
#define CDisplay__TrueDistance_x                                   0x4BF450

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FEAF0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EBD20
#define CEditWnd__GetCharIndexPt_x                                 0x8ECE80
#define CEditWnd__GetDisplayString_x                               0x8EBED0
#define CEditWnd__GetHorzOffset_x                                  0x8EC210
#define CEditWnd__GetLineForPrintableChar_x                        0x8EC940
#define CEditWnd__GetSelStartPt_x                                  0x8ED140
#define CEditWnd__GetSTMLSafeText_x                                0x8EC3B0
#define CEditWnd__PointFromPrintableChar_x                         0x8ECA30
#define CEditWnd__SelectableCharFromPoint_x                        0x8ECBB0
#define CEditWnd__SetEditable_x                                    0x8EC380

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56A780
#define CEverQuest__ClickedPlayer_x                                0x564360
#define CEverQuest__CreateTargetIndicator_x                        0x565260
#define CEverQuest__DeleteTargetIndicator_x                        0x5652E0
#define CEverQuest__DoTellWindow_x                                 0x476480
#define CEverQuest__OutputTextToLog_x                              0x4760E0
#define CEverQuest__DropHeldItemOnGround_x                         0x57ACF0
#define CEverQuest__dsp_chat_x                                     0x4767C0
#define CEverQuest__trimName_x                                     0x560C70
#define CEverQuest__Emote_x                                        0x579000
#define CEverQuest__EnterZone_x                                    0x5740E0
#define CEverQuest__GetBodyTypeDesc_x                              0x55E6B0
#define CEverQuest__GetClassDesc_x                                 0x567BA0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5681A0
#define CEverQuest__GetDeityDesc_x                                 0x55EF90
#define CEverQuest__GetLangDesc_x                                  0x55EA40
#define CEverQuest__GetRaceDesc_x                                  0x568360
#define CEverQuest__InterpretCmd_x                                 0x56BF00
#define CEverQuest__LeftClickedOnPlayer_x                          0x580850
#define CEverQuest__LMouseUp_x                                     0x582800
#define CEverQuest__RightClickedOnPlayer_x                         0x581360
#define CEverQuest__RMouseUp_x                                     0x582260
#define CEverQuest__SetGameState_x                                 0x564C30
#define CEverQuest__UPCNotificationFlush_x                         0x55D040
#define CEverQuest__IssuePetCommand_x                              0x56C8E0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B9FC0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BA020
#define CGaugeWnd__Draw_x                                          0x6BA450

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B2A0
#define CGuild__GetGuildName_x                                     0x43B770
#define CGuild__GetGuildIndex_x                                    0x43C980

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D64A0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E3870
#define CInvSlotMgr__MoveItem_x                                    0x6E4030
#define CInvSlotMgr__SelectSlot_x                                  0x6E3170

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E25D0
#define CInvSlot__SliderComplete_x                                 0x6DFDF0
#define CInvSlot__GetItemBase_x                                    0x6DF250
#define CInvSlot__UpdateItem_x                                     0x6DF7D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E5490
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E65D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AEA60
#define CItemDisplayWnd__UpdateStrings_x                           0x6E76F0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F4300
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F4810
#define CItemDisplayWnd__SetItem_x                                 0x6FA0F0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E5BD0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EDC90

// CLabel 
#define CLabel__Draw_x                                             0x700EC0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C3530
#define CListWnd__dCListWnd_x                                      0x8C47D0
#define CListWnd__AddColumn_x                                      0x8C4770
#define CListWnd__AddColumn1_x                                     0x8C3E00
#define CListWnd__AddLine_x                                        0x8C37E0
#define CListWnd__AddString_x                                      0x8C3A00
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C0620
#define CListWnd__CalculateVSBRange_x                              0x8C29F0
#define CListWnd__ClearSel_x                                       0x8BF930
#define CListWnd__ClearAllSel_x                                    0x8BF8E0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C33C0
#define CListWnd__Compare_x                                        0x8C1320
#define CListWnd__Draw_x                                           0x8C25F0
#define CListWnd__DrawColumnSeparators_x                           0x8C2480
#define CListWnd__DrawHeader_x                                     0x8BFBF0
#define CListWnd__DrawItem_x                                       0x8C19B0
#define CListWnd__DrawLine_x                                       0x8C2120
#define CListWnd__DrawSeparator_x                                  0x8C2520
#define CListWnd__EnableLine_x                                     0x8BFB10
#define CListWnd__EnsureVisible_x                                  0x8C0780
#define CListWnd__ExtendSel_x                                      0x8C18C0
#define CListWnd__GetColumnMinWidth_x                              0x8BF220
#define CListWnd__GetColumnWidth_x                                 0x8BF150
#define CListWnd__GetCurSel_x                                      0x8BE910
#define CListWnd__GetItemAtPoint_x                                 0x8C0A20
#define CListWnd__GetItemAtPoint1_x                                0x8C0A90
#define CListWnd__GetItemData_x                                    0x8BEC60
#define CListWnd__GetItemHeight_x                                  0x8C0270
#define CListWnd__GetItemIcon_x                                    0x8BEE50
#define CListWnd__GetItemRect_x                                    0x8C0860
#define CListWnd__GetItemText_x                                    0x8BED00
#define CListWnd__GetSelList_x                                     0x8C3CF0
#define CListWnd__GetSeparatorRect_x                               0x8C1240
#define CListWnd__InsertLine_x                                     0x8C3BE0
#define CListWnd__RemoveLine_x                                     0x8C3BF0
#define CListWnd__SetColors_x                                      0x8BEA60
#define CListWnd__SetColumnJustification_x                         0x8BF4B0
#define CListWnd__SetColumnWidth_x                                 0x8BF1D0
#define CListWnd__SetCurSel_x                                      0x8BE950
#define CListWnd__SetItemColor_x                                   0x8C30B0
#define CListWnd__SetItemData_x                                    0x8BF990
#define CListWnd__SetItemText_x                                    0x8C2EF0
#define CListWnd__ShiftColumnSeparator_x                           0x8C2D80
#define CListWnd__Sort_x                                           0x8C48D0
#define CListWnd__ToggleSel_x                                      0x8BF860

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x719FF0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73F460
#define CMerchantWnd__RequestBuyItem_x                             0x747260
#define CMerchantWnd__RequestSellItem_x                            0x749950
#define CMerchantWnd__SelectRecoverySlot_x                         0x73C780
#define CMerchantWnd__SelectBuySellSlot_x                          0x73A6D0
#define CMerchantWnd__ActualSelect_x                               0x7411E0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x855230
#define CPacketScrambler__hton_x                                   0x855240

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E25E0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E26C0
#define CSidlManager__CreateLabel_x                                0x7A39B0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E0B80
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E29A0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D9AA0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D9990
#define CSidlScreenWnd__ConvertToRes_x                             0x8FE9D0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8DA3B0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DB590
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DB640
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DAB10
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D9D60
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D94C0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D9F50
#define CSidlScreenWnd__Init1_x                                    0x8DB270
#define CSidlScreenWnd__LoadIniInfo_x                              0x8DA470
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D9680
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DAD50
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D9120
#define CSidlScreenWnd__StoreIniVis_x                              0x8D9470
#define CSidlScreenWnd__WndNotification_x                          0x8DAFF0
#define CSidlScreenWnd__GetChildItem_x                             0x8D9590
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CCDF0
#define CSidlScreenWnd__m_layoutCopy_x                             0x172D9E0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x605600
#define CSkillMgr__GetSkillCap_x                                   0x6057E0
#define CSkillMgr__GetNameToken_x                                  0x6051B0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FDC90
#define CSliderWnd__SetValue_x                                     0x8FDE60
#define CSliderWnd__SetNumTicks_x                                  0x8FE5E0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A9CA0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F77D0
#define CStmlWnd__CalculateHSBRange_x                              0x8EFD20
#define CStmlWnd__CalculateVSBRange_x                              0x8EFC90
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EFEA0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F06A0
#define CStmlWnd__ForceParseNow_x                                  0x8F8150
#define CStmlWnd__GetNextTagPiece_x                                0x8F05A0
#define CStmlWnd__GetSTMLText_x                                    0x484660
#define CStmlWnd__GetVisibleText_x                                 0x8F10F0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F36C0
#define CStmlWnd__MakeStmlColorTag_x                               0x8EEF70
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EEFD0
#define CStmlWnd__SetSTMLText_x                                    0x8F4F20
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F7470
#define CStmlWnd__UpdateHistoryString_x                            0x8F2030

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FB690
#define CTabWnd__DrawCurrentPage_x                                 0x8FAF20
#define CTabWnd__DrawTab_x                                         0x8FACE0
#define CTabWnd__GetCurrentPage_x                                  0x8FB2D0
#define CTabWnd__GetPageInnerRect_x                                0x8FA9D0
#define CTabWnd__GetTabInnerRect_x                                 0x8FABD0
#define CTabWnd__GetTabRect_x                                      0x8FAAA0
#define CTabWnd__InsertPage_x                                      0x8FB980
#define CTabWnd__SetPage_x                                         0x8FB300
#define CTabWnd__SetPageRect_x                                     0x8FB5D0
#define CTabWnd__UpdatePage_x                                      0x8FB920
#define CTabWnd__GetPageFromTabIndex_x                             0x8FAC30
#define CTabWnd__GetCurrentTabIndex_x                              0x8FA960

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E6780
#define CPageWnd__SetTabText_x                                     0x907D70

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436ED0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D7400
#define CTextureFont__GetTextExtent_x                              0x8D7160

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63DCB0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x904160

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BCA10

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029D0
#define CXStr__CXStr1_x                                            0x8B2110
#define CXStr__CXStr3_x                                            0x89FD10
#define CXStr__dCXStr_x                                            0x8CB8C0
#define CXStr__operator_equal_x                                    0x89FE80
#define CXStr__operator_equal1_x                                   0x89FED0
#define CXStr__operator_plus_equal1_x                              0x8A0FD0

// CXWnd 
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D4F10
#define CXWnd__BringToTop_x                                        0x8CBFE0
#define CXWnd__Center_x                                            0x8D2200
#define CXWnd__ClrFocus_x                                          0x8CBBB0
#define CXWnd__Destroy_x                                           0x8D2CE0
#define CXWnd__DoAllDrawing_x                                      0x8D1E50
#define CXWnd__DrawChildren_x                                      0x8D1FF0
#define CXWnd__DrawColoredRect_x                                   0x8CC3C0
#define CXWnd__DrawTooltip_x                                       0x8CC670
#define CXWnd__DrawTooltipAtPoint_x                                0x8D0DD0
#define CXWnd__GetBorderFrame_x                                    0x8CCAC0
#define CXWnd__GetChildWndAt_x                                     0x8D2BC0
#define CXWnd__GetClientClipRect_x                                 0x8CC880
#define CXWnd__GetScreenClipRect_x                                 0x8D14D0
#define CXWnd__GetScreenRect_x                                     0x8CCC90
#define CXWnd__GetTooltipRect_x                                    0x8CC500
#define CXWnd__GetWindowTextA_x                                    0x427020
#define CXWnd__IsActive_x                                          0x8C75F0
#define CXWnd__IsDescendantOf_x                                    0x8CCA00
#define CXWnd__IsReallyVisible_x                                   0x8CFDF0
#define CXWnd__IsType_x                                            0x8D2270
#define CScreenPieceTemplate__IsType_x                             0x900870
#define CXWnd__Move_x                                              0x8CF4E0
#define CXWnd__Move1_x                                             0x8D1B00
#define CXWnd__ProcessTransition_x                                 0x8CBF80
#define CXWnd__Refade_x                                            0x8CBD50
#define CXWnd__Resize_x                                            0x8CCD50
#define CXWnd__Right_x                                             0x8D12D0
#define CXWnd__SetFocus_x                                          0x8CE630
#define CXWnd__SetFont_x                                           0x8CBC00
#define CXWnd__SetKeyTooltip_x                                     0x8CCFC0
#define CXWnd__SetMouseOver_x                                      0x8D1810
#define CXWnd__StartFade_x                                         0x8CC030
#define CXWnd__GetChildItem_x                                      0x8D1750
#define CXWnd__SetParent_x                                         0x8D2B70

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C8E90
#define CXWndManager__DrawWindows_x                                0x8C8AE0
#define CXWndManager__GetKeyboardFlags_x                           0x8C7120
#define CXWndManager__HandleKeyboardMsg_x                          0x8C7A90
#define CXWndManager__RemoveWnd_x                                  0x8C7780

// CDBStr
#define CDBStr__GetString_x                                        0x4BA550

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452750
#define EQ_Character__Cur_HP_x                                     0x465930
#define EQ_Character__Cur_Mana_x                                   0x45AD80
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B810
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443740
#define EQ_Character__GetFocusRangeModifier_x                      0x443890
#define EQ_Character__GetHPRegen_x                                 0x469370
#define EQ_Character__GetEnduranceRegen_x                          0x464F40
#define EQ_Character__GetManaRegen_x                               0x469910
#define EQ_Character__Max_Endurance_x                              0x5CBDE0
#define EQ_Character__Max_HP_x                                     0x45D900
#define EQ_Character__Max_Mana_x                                   0x5CBC10
#define EQ_Character__doCombatAbility_x                            0x5C92E0
#define EQ_Character__UseSkill_x                                   0x4708F0
#define EQ_Character__GetConLevel_x                                0x5BEA60
#define EQ_Character__IsExpansionFlag_x                            0x4B6850
#define EQ_Character__TotalEffect_x                                0x44F980
#define EQ_Character__GetPCSpellAffect_x                           0x44BBA0
#define EQ_Character__SpellDuration_x                              0x449BA0
#define EQ_Character__FindItemByRecord_x                           0x462F80
#define EQ_Character__GetAdjustedSkill_x                           0x465B00
#define EQ_Character__GetBaseSkill_x                               0x45D7E0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x873130

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D4350

//PcClient
#define PcClient__PcClient_x                                       0x5C0890

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446C20
#define CCharacterSelect__EnterWorld_x                             0x4463F0
#define CCharacterSelect__Quit_x                                   0x444FB0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59EAA0
#define EQ_Item__CreateItemTagString_x                             0x8533C0
#define EQ_Item__IsStackable_x                                     0x8486A0
#define EQ_Item__GetImageNum_x                                     0x84B1D0
#define EQ_Item__CreateItemClient_x                                0x59FBB0
#define EQ_Item__GetItemValue_x                                    0x851E30
#define EQ_Item__ValueSellMerchant_x                               0x854E80
#define EQ_Item__IsKeyRingItem_x                                   0x8491E0
#define EQ_Item__CanGoInBag_x                                      0x59EC30
#define EQ_Item__GetMaxItemCount_x                                 0x848590
#define EQ_Item__GetHeldItem_x                                     0x849FE0
#define EQ_Item__GetAugmentFitBySlot_x                             0x854CA0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA580
#define EQ_LoadingS__Array_x                                       0xC0BA50

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CE310
#define EQ_PC__GetAlternateAbilityId_x                             0x85D330
#define EQ_PC__GetCombatAbility_x                                  0x85D3C0
#define EQ_PC__GetCombatAbilityTimer_x                             0x857EE0
#define EQ_PC__GetItemRecastTimer_x                                0x5C7A90
#define EQ_PC__HasLoreItem_x                                       0x5C2050
#define EQ_PC__AlertInventoryChanged_x                             0x5BEA10
#define EQ_PC__GetPcZoneClient_x                                   0x5E88E0
#define EQ_PC__RemoveMyAffect_x                                    0x5C6EF0
#define EQ_PC__GetKeyRingItems_x                                   0x858300
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86B0A0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85F330

// EQItemList 
#define EQItemList__EQItemList_x                                   0x526C60
#define EQItemList__add_object_x                                   0x554000
#define EQItemList__add_item_x                                     0x526BA0
#define EQItemList__delete_item_x                                  0x527050
#define EQItemList__FreeItemList_x                                 0x526F50

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9800

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D40F0
#define EQPlayer__dEQPlayer_x                                      0x5DC7A0
#define EQPlayer__DoAttack_x                                       0x5EE260
#define EQPlayer__EQPlayer_x                                       0x5DEEC0
#define EQPlayer__SetNameSpriteState_x                             0x5D95F0
#define EQPlayer__SetNameSpriteTint_x                              0x5D5510
#define PlayerBase__HasProperty_j_x                                0x931C20
#define EQPlayer__IsTargetable_x                                   0x931EC0
#define EQPlayer__CanSee_x                                         0x932420
#define PlayerZoneClient__ChangeHeight_x                           0x5EE120
#define EQPlayer__CanSee1_x                                        0x932510
#define PlayerBase__GetVisibilityLineSegment_x                     0x9321B0

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E8A90
#define PlayerZoneClient__IsValidTeleport_x                        0x5548A0
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2910

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E2F00
#define EQPlayerManager__GetSpawnByName_x                          0x5E3360
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E2F30

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A50A0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A50E0
#define KeypressHandler__ClearCommandStateArray_x                  0x5A4C90
#define KeypressHandler__HandleKeyDown_x                           0x5A35E0
#define KeypressHandler__HandleKeyUp_x                             0x5A3900
#define KeypressHandler__SaveKeymapping_x                          0x5A4D60

// MapViewMap 
#define MapViewMap__Clear_x                                        0x712980
#define MapViewMap__SaveEx_x                                       0x715CB0
#define MapViewMap__SetZoom_x                                      0x712600

#define PlayerPointManager__GetAltCurrency_x                       0x871140

// StringTable 
#define StringTable__getString_x                                   0x86B3D0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CB870
#define PcZoneClient__RemovePetEffect_x                            0x5C7F60
#define PcZoneClient__HasAlternateAbility_x                        0x5C8900
#define PcZoneClient__GetCurrentMod_x                              0x45CDB0
#define PcZoneClient__GetModCap_x                                  0x45A4E0
#define PcZoneClient__CanEquipItem_x                               0x5C8E20
#define PcZoneClient__GetItemByID_x                                0x5CD680
#define PcZoneClient__GetItemByItemClass_x                         0x5CE230
#define PcZoneClient__RemoveBuffEffect_x                           0x5C71A0

//Doors
#define EQSwitch__UseSwitch_x                                      0x55B900

//IconCache
#define IconCache__GetIcon_x                                       0x6AF8F0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A67D0
#define CContainerMgr__CloseContainer_x                            0x6A6FF0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x773760

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x597B70

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F4DA0
#define EQ_Spell__SpellAffects_x                                   0x4F1F90
#define EQ_Spell__SpellAffectBase_x                                0x4F2000
#define CharacterZoneClient__CalcAffectChange_x                    0x44BA30
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44ACD0
#define CLootWnd__LootAll_x                                        0x708280
#define CLootWnd__RequestLootSlot_x                                0x708A90
#define EQ_Spell__IsStackable_x                                    0x4495A0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449650
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43ED40
#define EQ_Spell__IsSPAStacking_x                                  0x4F1B00
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2BA0
#define EQ_Spell__IsNoRemove_x                                     0x434F10
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F1B20

#define __IsResEffectSpell_x                                       0x4496F0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87CDB0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BB5D0
#define CTargetWnd__WndNotification_x                              0x7BB0C0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BB7B0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C0720

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED680
#define EqSoundManager__PlayScriptMp3_x                            0x4EF120

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8950

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EB350
#define CSidlManager__FindAnimation1_x                             0x8E05B0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E1F80
#define CAltAbilityData__GetMercMaxRank_x                          0x4E1F30
#define CAltAbilityData__GetMaxRank_x                              0x4D6690

//CTargetRing
#define CTargetRing__Cast_x                                        0x5957C0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4594F0
#define CharacterBase__CreateItemGlobalIndex_x                     0x475680
#define CharacterBase__CreateItemIndex_x                           0x520290
#define CharacterBase__GetItemPossession_x                         0x444480
#define CharacterBase__GetItemByGlobalIndex_x                      0x880C00
#define CharacterBase__GetEffectId_x                               0x4594B0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68F450
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68EBB0

//messages
#define msg_spell_worn_off_x                                       0x4FC820
#define msg_new_text_x                                             0x505FA0
#define msgTokenTextParam_x                                        0x5027A0

//SpellManager
#define SpellManager__vftable_x                                    0xAC9248
#define SpellManager__SpellManager_x                               0x47E250
#define Spellmanager__LoadTextSpells_x                             0x60C490

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x935F90

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487E90
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EC60
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449300
#define ItemGlobalIndex__IsValidIndex_x                            0x458D90

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87EA70
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87D9B0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x701110

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AB530
#define CCursorAttachment__Deactivate_x                            0x6AAA70

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FD190
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FD310

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C710

//IString
#define IString__Append_x                                          0x47EF20

//Camera
#define CDisplay__cameraType_x                                     0xE6EC68
#define EverQuest__Cameras_x                                       0xF30F68
