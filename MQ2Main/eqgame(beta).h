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
#define __ExpectedVersionDate                                     "Dec 11 2017"
#define __ExpectedVersionTime                                     "04:16:51"
#define __ActualVersionDate_x                                      0xAE3090
#define __ActualVersionTime_x                                      0xAE309C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5A9FB0
#define __MemChecker1_x                                            0x8A28C0
#define __MemChecker2_x                                            0x63FD20
#define __MemChecker3_x                                            0x63FC70
#define __MemChecker4_x                                            0x7F4770
#define __EncryptPad0_x                                            0xC3DFE8
#define __EncryptPad1_x                                            0xD17BA0
#define __EncryptPad2_x                                            0xC66ED0
#define __EncryptPad3_x                                            0xC66AD0
#define __EncryptPad4_x                                            0xD061A0
#define __EncryptPad5_x                                            0x10C12E0
#define __AC1_x                                                    0x7B34D5
#define __AC2_x                                                    0x563277
#define __AC3_x                                                    0x5613F0
#define __AC4_x                                                    0x5735C1
#define __AC5_x                                                    0x58730B
#define __AC6_x                                                    0x58AEBE
#define __AC7_x                                                    0x58190C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FA4EE0

// Direct Input
#define DI8__Main_x                                                0x10C12B8
#define DI8__Keyboard_x                                            0x10C12BC
#define DI8__Mouse_x                                               0x10C12C0
#define DI8__Mouse_Copy_x                                          0xF2F474
#define DI8__Mouse_Check_x                                         0xFB8FA4
#define __AutoSkillArray_x                                         0xF30388
#define __Attack_x                                                 0xFB3A7B
#define __Autofire_x                                               0xFB3A7C
#define __BindList_x                                               0xC1A368
#define g_eqCommandStates_x                                        0xF1E1C0
#define __Clicks_x                                                 0xF2F530
#define __CommandList_x                                            0xC1CA80
#define __CurrentMapLabel_x                                        0x10C72B0
#define __CurrentSocial_x                                          0xBE98E8
#define __DoAbilityList_x                                          0xF65C40
#define __do_loot_x                                                0x5320B0
#define __DrawHandler_x                                            0x1730F2C
#define __GroupCount_x                                             0xF1FACA

#define __Guilds_x                                                 0xF256E0
#define __gWorld_x                                                 0xF21F84
#define __HotkeyPage_x                                             0xFAC640
#define __HWnd_x                                                   0xFB90C0
#define __InChatMode_x                                             0xF2F45C
#define __LastTell_x                                               0xF3133C
#define __LMouseHeldTime_x                                         0xF2F59C
#define __Mouse_x                                                  0x10C12C4
#define __MouseLook_x                                              0xF2F4F6
#define __MouseEventTime_x                                         0xFB4214
#define __gpbCommandEvent_x                                        0xF2204C
#define __NetStatusToggle_x                                        0xF2F4F9
#define __PCNames_x                                                0xF30944
#define __RangeAttackReady_x                                       0xF3066C
#define __RMouseHeldTime_x                                         0xF2F598
#define __RunWalkState_x                                           0xF2F460
#define __ScreenMode_x                                             0xE6DDA0
#define __ScreenX_x                                                0xF2F414
#define __ScreenY_x                                                0xF2F410
#define __ScreenXMax_x                                             0xF2F418
#define __ScreenYMax_x                                             0xF2F41C
#define __ServerHost_x                                             0xF1FA14
#define __ServerName_x                                             0xF65C00
#define __ShiftKeyDown_x                                           0xF2FAF0
#define __ShowNames_x                                              0xF30824
#define __Socials_x                                                0xF65D00
#define __SubscriptionType_x                                       0x10F7A34
#define __TargetAggroHolder_x                                      0x10C940C
#define __ZoneType_x                                               0xF2F8F4
#define __GroupAggro_x                                             0x10C944C
#define __LoginName_x                                              0xFB7B9C
#define __Inviter_x                                                0xFB39F8
#define __AttackOnAssist_x                                         0xF307E0
#define __UseTellWindows_x                                         0xF30ADC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF22070
#define instEQZoneInfo_x                                           0xF2F6EC
#define instKeypressHandler_x                                      0xFB41F8
#define pinstActiveBanker_x                                        0xF22028
#define pinstActiveCorpse_x                                        0xF2202C
#define pinstActiveGMaster_x                                       0xF22030
#define pinstActiveMerchant_x                                      0xF22024
#define pinstAggroInfo_x                                           0xD2B40C
#define pinstAltAdvManager_x                                       0xE6EF08
#define pinstAuraMgr_x                                             0xD3BC10
#define pinstBandageTarget_x                                       0xF22010
#define pinstCamActor_x                                            0xE6E7D8
#define pinstCDBStr_x                                              0xE6DD34
#define pinstCDisplay_x                                            0xF22038
#define pinstCEverQuest_x                                          0x10C1438
#define pinstEverQuestInfo_x                                       0xF2F408
#define pinstCharData_x                                            0xF21FF4
#define pinstCharSpawn_x                                           0xF2201C
#define pinstControlledMissile_x                                   0xF21FF0
#define pinstControlledPlayer_x                                    0xF2201C
#define pinstCSidlManager_x                                        0x172FE98
#define pinstCXWndManager_x                                        0x172FE90
#define instDynamicZone_x                                          0xF2F2A8
#define pinstDZMember_x                                            0xF2F3B8
#define pinstDZTimerInfo_x                                         0xF2F3BC
#define pinstEQItemList_x                                          0xF1E498
#define pinstEQObjectList_x                                        0xF1F4C4
#define instEQMisc_x                                               0xC027A8
#define pinstEQSoundManager_x                                      0xE6F4D8
#define instExpeditionLeader_x                                     0xF2F2F2
#define instExpeditionName_x                                       0xF2F332
#define pinstGroup_x                                               0xF1FAC6
#define pinstImeManager_x                                          0x172FE9C
#define pinstLocalPlayer_x                                         0xF22008
#define pinstMercenaryData_x                                       0xFB4860
#define pinstMercenaryStats_x                                      0x10C9558
#define pinstMercAltAbilities_x                                    0xE6F290
#define pinstModelPlayer_x                                         0xF22034
#define pinstPCData_x                                              0xF21FF4
#define pinstSkillMgr_x                                            0xFB5858
#define pinstSpawnManager_x                                        0xFB50B0
#define pinstSpellManager_x                                        0xFB59A0
#define pinstSpellSets_x                                           0xFAC6A4
#define pinstStringTable_x                                         0xF21F9C
#define pinstSwitchManager_x                                       0xF1F658
#define pinstTarget_x                                              0xF22020
#define pinstTargetObject_x                                        0xF21FF8
#define pinstTargetSwitch_x                                        0xF21FFC
#define pinstTaskMember_x                                          0xE6DC80
#define pinstTrackTarget_x                                         0xF22014
#define pinstTradeTarget_x                                         0xF22004
#define instTributeActive_x                                        0xC027CD
#define pinstViewActor_x                                           0xE6E7D4
#define pinstWorldData_x                                           0xF21FD8
#define pinstZoneAddr_x                                            0xF2F98C
#define pinstPlayerPath_x                                          0xFB5110
#define pinstTargetIndicator_x                                     0xFB5B38
#define pinstCTargetManager_x                                      0xFB5B98
#define EQObject_Top_x                                             0xF21FE8
#define pinstRealEstateItems_x                                     0xFB56C4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE6E6F0
#define pinstCAchievementsWnd_x                                    0xE6E74C
#define pinstCTextOverlay_x                                        0xD2B9A0
#define pinstCAudioTriggersWindow_x                                0xD2B788
#define pinstCCharacterSelect_x                                    0xE6E65C
#define pinstCFacePick_x                                           0xE6E40C
#define pinstCFindItemWnd_x                                        0xE6E6EC
#define pinstCNoteWnd_x                                            0xE6E614
#define pinstCBookWnd_x                                            0xE6E61C
#define pinstCPetInfoWnd_x                                         0xE6E620
#define pinstCTrainWnd_x                                           0xE6E624
#define pinstCSkillsWnd_x                                          0xE6E628
#define pinstCSkillsSelectWnd_x                                    0xE6E62C
#define pinstCCombatSkillsSelectWnd_x                              0xE6E630
#define pinstCFriendsWnd_x                                         0xE6E634
#define pinstCAuraWnd_x                                            0xE6E638
#define pinstCRespawnWnd_x                                         0xE6E63C
#define pinstCBandolierWnd_x                                       0xE6E640
#define pinstCPotionBeltWnd_x                                      0xE6E644
#define pinstCAAWnd_x                                              0xE6E648
#define pinstCAlarmWnd_x                                           0xE6E654
#define pinstCGroupSearchFiltersWnd_x                              0xE6E64C
#define pinstCLoadskinWnd_x                                        0xE6E650
#define pinstCLargeDialogWnd_x                                     0x10C84B8
#define pinstCMusicPlayerWnd_x                                     0xE6E658
#define pinstCMailWnd_x                                            0xE6E660
#define pinstCMailCompositionWnd_x                                 0xE6E664
#define pinstCMailAddressBookWnd_x                                 0xE6E668
#define pinstCRaidWnd_x                                            0xE6E670
#define pinstCRaidOptionsWnd_x                                     0xE6E674
#define pinstCBreathWnd_x                                          0xE6E678
#define pinstCMapViewWnd_x                                         0xE6E67C
#define pinstCMapToolbarWnd_x                                      0xE6E680
#define pinstCEditLabelWnd_x                                       0xE6E684
#define pinstCTargetWnd_x                                          0xE6E688
#define pinstCColorPickerWnd_x                                     0xE6E68C
#define pinstCPlayerWnd_x                                          0xE6E690
#define pinstCOptionsWnd_x                                         0xE6E694
#define pinstCBuffWindowNORMAL_x                                   0xE6E698
#define pinstCBuffWindowSHORT_x                                    0xE6E69C
#define pinstCharacterCreation_x                                   0xE6E6A0
#define pinstCCursorAttachment_x                                   0xE6E6A4
#define pinstCCastingWnd_x                                         0xE6E6A8
#define pinstCCastSpellWnd_x                                       0xE6E6AC
#define pinstCSpellBookWnd_x                                       0xE6E6B0
#define pinstCInventoryWnd_x                                       0xE6E6B4
#define pinstCBankWnd_x                                            0xE6E6BC
#define pinstCQuantityWnd_x                                        0xE6E6C0
#define pinstCLootWnd_x                                            0xE6E6C4
#define pinstCActionsWnd_x                                         0xE6E6C8
#define pinstCCombatAbilityWnd_x                                   0xE6E6D0
#define pinstCMerchantWnd_x                                        0xE6E6D4
#define pinstCTradeWnd_x                                           0xE6E6DC
#define pinstCSelectorWnd_x                                        0xE6E6E0
#define pinstCBazaarWnd_x                                          0xE6E6E4
#define pinstCBazaarSearchWnd_x                                    0xE6E6E8
#define pinstCGiveWnd_x                                            0xE6E708
#define pinstCTrackingWnd_x                                        0xE6E710
#define pinstCInspectWnd_x                                         0xE6E714
#define pinstCSocialEditWnd_x                                      0xE6E718
#define pinstCFeedbackWnd_x                                        0xE6E71C
#define pinstCBugReportWnd_x                                       0xE6E720
#define pinstCVideoModesWnd_x                                      0xE6E724
#define pinstCTextEntryWnd_x                                       0xE6E72C
#define pinstCFileSelectionWnd_x                                   0xE6E730
#define pinstCCompassWnd_x                                         0xE6E734
#define pinstCPlayerNotesWnd_x                                     0xE6E738
#define pinstCGemsGameWnd_x                                        0xE6E73C
#define pinstCTimeLeftWnd_x                                        0xE6E758
#define pinstCPetitionQWnd_x                                       0xE6E75C
#define pinstCStoryWnd_x                                           0xE6E760
#define pinstCJournalTextWnd_x                                     0xE6E764
#define pinstCJournalCatWnd_x                                      0xE6E768
#define pinstCBodyTintWnd_x                                        0xE6E76C
#define pinstCServerListWnd_x                                      0xE6E770
#define pinstCAvaZoneWnd_x                                         0xE6E77C
#define pinstCBlockedBuffWnd_x                                     0xE6E780
#define pinstCBlockedPetBuffWnd_x                                  0xE6E784
#define pinstCInvSlotMgr_x                                         0xE6E7CC
#define pinstCContainerMgr_x                                       0xE6E7D0
#define pinstCAdventureLeaderboardWnd_x                            0x10C1DE8
#define pinstCAdventureRequestWnd_x                                0x10C1E60
#define pinstCAltStorageWnd_x                                      0x10C2140
#define pinstCAdventureStatsWnd_x                                  0x10C1ED8
#define pinstCBarterMerchantWnd_x                                  0x10C2E88
#define pinstCBarterSearchWnd_x                                    0x10C2F00
#define pinstCBarterWnd_x                                          0x10C2F78
#define pinstCChatWindowManager_x                                  0x10C3788
#define pinstCDynamicZoneWnd_x                                     0x10C3CB8
#define pinstCEQMainWnd_x                                          0x10C3E80
#define pinstCFellowshipWnd_x                                      0x10C3C4C
#define pinstCFindLocationWnd_x                                    0x10C4150
#define pinstCGroupSearchWnd_x                                     0x10C4420
#define pinstCGroupWnd_x                                           0x10C4498
#define pinstCGuildBankWnd_x                                       0x10C4510
#define pinstCGuildMgmtWnd_x                                       0x10C6600
#define pinstCHotButtonWnd_x                                       0x10C66FC
#define pinstCHotButtonWnd1_x                                      0x10C66FC
#define pinstCHotButtonWnd2_x                                      0x10C6700
#define pinstCHotButtonWnd3_x                                      0x10C6704
#define pinstCHotButtonWnd4_x                                      0x10C6728
#define pinstCItemDisplayManager_x                                 0x10C6B80
#define pinstCItemExpTransferWnd_x                                 0x10C6C7C
#define pinstCLFGuildWnd_x                                         0x10C6F58
#define pinstCMIZoneSelectWnd_x                                    0x10C7538
#define pinstCConfirmationDialog_x                                 0x10C7B50
#define pinstCPopupWndManager_x                                    0x10C7B50
#define pinstCProgressionSelectionWnd_x                            0x10C7C40
#define pinstCPvPStatsWnd_x                                        0x10C7D30
#define pinstCTaskWnd_x                                            0x10C9838
#define pinstCTaskSomething_x                                      0xD3C828
#define pinstCTaskTemplateSelectWnd_x                              0x10C97C0
#define pinstCTipWndOFDAY_x                                        0x10C99A0
#define pinstCTipWndCONTEXT_x                                      0x10C99A4
#define pinstCTitleWnd_x                                           0x10C9A20
#define pinstCContextMenuManager_x                                 0x172FD20
#define pinstCVoiceMacroWnd_x                                      0xFB5F70
#define pinstCHtmlWnd_x                                            0xFB6060
#define pinstItemIconCache_x                                       0x10C3E28
#define pinstCTradeskillWnd_x                                      0x10C9B20
#define pinstCAdvancedLootWnd_x                                    0xE6E7C0
#define pinstRewardSelectionWnd_x                                  0x10C8258
#define pinstEQSuiteTextureLoader_x                                0xD19A88

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x549950
#define __CastRay2_x                                               0x549280
#define __HeadingDiff_x                                            0x932F10
#define __FixHeading_x                                             0x932EA0
#define __get_bearing_x                                            0x539200
#define __ConvertItemTags_x                                        0x536CD0
#define __ExecuteCmd_x                                             0x5215D0
#define __EQGetTime_x                                              0x8A2260
#define __get_melee_range_x                                        0x528270
#define __GetGaugeValueFromEQ_x                                    0x7B2090
#define __GetLabelFromEQ_x                                         0x7B3460
#define __ToggleKeyRingItem_x                                      0x48FC40
#define __GetXTargetType_x                                         0x934B10
#define __LoadFrontEnd_x                                           0x63F3F0
#define __NewUIINI_x                                               0x7B1A60
#define __ProcessGameEvents_x                                      0x5836A0
#define __ProcessMouseEvent_x                                      0x582E40
#define CrashDetected_x                                            0x640DB0
#define wwsCrashReportCheckForUploader_x                           0x800370
#define __AppCrashWrapper_x                                        0xC66AC4
#define __pCrashHandler_x                                          0x10D6A00
#define __CrashHandler_x                                           0x7FFDD0
#define wwsCrashReportPlatformLaunchUploader_x                     0x802570
#define DrawNetStatus_x                                            0x5B9C10
#define Util__FastTime_x                                           0x8A1F00
#define Expansion_HoT_x                                            0xF307D0
#define __HelpPath_x                                               0xFB3F80
#define __STMLToText_x                                             0x8E84F0
#define __GetAnimationCache_x                                      0x6AEBF0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423370
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DFE0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DDB0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D80A0
#define AltAdvManager__IsAbilityReady_x                            0x4D8110
#define AltAdvManager__GetAAById_x                                 0x4D8600
#define AltAdvManager__CanTrainAbility_x                           0x4D9230
#define AltAdvManager__CanSeeAbility_x                             0x4D8DF0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46B060
#define CharacterZoneClient__HasSkill_x                            0x466F70
#define CharacterZoneClient__MakeMeVisible_x                       0x46CBD0
#define CharacterZoneClient__IsStackBlocked_x                      0x44C080
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B5A0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4654D0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4655B0
#define CharacterZoneClient__GetCursorItemCount_x                  0x465690
#define CharacterZoneClient__FindAffectSlot_x                      0x4516F0
#define CharacterZoneClient__BardCastBard_x                        0x44AD10
#define CharacterZoneClient__GetMaxEffects_x                       0x4498A0
#define CharacterZoneClient__GetEffect_x                           0x44B7D0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451550
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449BF0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4500A0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66ED50

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67CBE0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x598730
#define CButtonWnd__CButtonWnd_x                                   0x8DC6D0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x697D50
#define CChatManager__InitContextMenu_x                            0x698EA0
#define CChatManager__FreeChatWindow_x                             0x697800
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A1030
#define CChatManager__SetLockedActiveChatWindow_x                  0x697D20

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E6840
#define CContextMenu__dCContextMenu_x                              0x8E6A50
#define CContextMenu__AddMenuItem_x                                0x8E6F70
#define CContextMenu__RemoveMenuItem_x                             0x8E6BD0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E6BF0
#define CContextMenu__CheckMenuItem_x                              0x8E6C70
#define CContextMenu__SetMenuItem_x                                0x8E6AF0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D2CE0
#define CContextMenuManager__RemoveMenu_x                          0x8D3070
#define CContextMenuManager__PopupMenu_x                           0x8D34C0
#define CContextMenuManager__Flush_x                               0x8D2D50
#define CContextMenuManager__GetMenu_x                             0x4194B0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x886370
#define CChatService__GetFriendName_x                              0x886380

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69EB10
#define CChatWindow__Clear_x                                       0x69E3F0
#define CChatWindow__WndNotification_x                             0x69F410

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D6B30
#define CComboWnd__Draw_x                                          0x8D6D40
#define CComboWnd__GetCurChoice_x                                  0x8D68E0
#define CComboWnd__GetListRect_x                                   0x8D6FE0
#define CComboWnd__GetTextRect_x                                   0x8D6BA0
#define CComboWnd__InsertChoice_x                                  0x8D7140
#define CComboWnd__SetColors_x                                     0x8D6870
#define CComboWnd__SetChoice_x                                     0x8D68A0
#define CComboWnd__GetItemCount_x                                  0x8D68D0
#define CComboWnd__GetCurChoiceText_x                              0x8D6920


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A8D90
#define CContainerWnd__vftable_x                                   0xAEC9A8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C5F10
#define CDisplay__GetClickedActor_x                                0x4BE7D0
#define CDisplay__GetUserDefinedColor_x                            0x4BD3B0
#define CDisplay__GetWorldFilePath_x                               0x4BC800
#define CDisplay__is3dON_x                                         0x4BBC90
#define CDisplay__ReloadUI_x                                       0x4CFCD0
#define CDisplay__WriteTextHD2_x                                   0x4C22A0
#define CDisplay__TrueDistance_x                                   0x4BF400

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FDC40

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EADB0
#define CEditWnd__GetCharIndexPt_x                                 0x8EBF10
#define CEditWnd__GetDisplayString_x                               0x8EAF60
#define CEditWnd__GetHorzOffset_x                                  0x8EB2A0
#define CEditWnd__GetLineForPrintableChar_x                        0x8EB9D0
#define CEditWnd__GetSelStartPt_x                                  0x8EC1D0
#define CEditWnd__GetSTMLSafeText_x                                0x8EB440
#define CEditWnd__PointFromPrintableChar_x                         0x8EBAC0
#define CEditWnd__SelectableCharFromPoint_x                        0x8EBC40
#define CEditWnd__SetEditable_x                                    0x8EB410

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x569DF0
#define CEverQuest__ClickedPlayer_x                                0x5639C0
#define CEverQuest__CreateTargetIndicator_x                        0x5648C0
#define CEverQuest__DeleteTargetIndicator_x                        0x564940
#define CEverQuest__DoTellWindow_x                                 0x4762A0
#define CEverQuest__OutputTextToLog_x                              0x475F00
#define CEverQuest__DropHeldItemOnGround_x                         0x57A360
#define CEverQuest__dsp_chat_x                                     0x4765E0
#define CEverQuest__trimName_x                                     0x5602D0
#define CEverQuest__Emote_x                                        0x578670
#define CEverQuest__EnterZone_x                                    0x573750
#define CEverQuest__GetBodyTypeDesc_x                              0x55DD10
#define CEverQuest__GetClassDesc_x                                 0x567200
#define CEverQuest__GetClassThreeLetterCode_x                      0x567800
#define CEverQuest__GetDeityDesc_x                                 0x55E5F0
#define CEverQuest__GetLangDesc_x                                  0x55E0A0
#define CEverQuest__GetRaceDesc_x                                  0x5679C0
#define CEverQuest__InterpretCmd_x                                 0x56B570
#define CEverQuest__LeftClickedOnPlayer_x                          0x57FEB0
#define CEverQuest__LMouseUp_x                                     0x581E60
#define CEverQuest__RightClickedOnPlayer_x                         0x5809C0
#define CEverQuest__RMouseUp_x                                     0x5818C0
#define CEverQuest__SetGameState_x                                 0x564290
#define CEverQuest__UPCNotificationFlush_x                         0x55C6A0
#define CEverQuest__IssuePetCommand_x                              0x56BF50

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B9AF0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B9B50
#define CGaugeWnd__Draw_x                                          0x6B9F80

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B2A0
#define CGuild__GetGuildName_x                                     0x43B770
#define CGuild__GetGuildIndex_x                                    0x43C980

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D6010

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E33B0
#define CInvSlotMgr__MoveItem_x                                    0x6E3B70
#define CInvSlotMgr__SelectSlot_x                                  0x6E2CA0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E2100
#define CInvSlot__SliderComplete_x                                 0x6DF920
#define CInvSlot__GetItemBase_x                                    0x6DEDC0
#define CInvSlot__UpdateItem_x                                     0x6DF340

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E4FA0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E60E0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7ADEC0
#define CItemDisplayWnd__UpdateStrings_x                           0x6E71D0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F3A20
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F3F40
#define CItemDisplayWnd__SetItem_x                                 0x6F9760

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E50C0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6ED730

// CLabel 
#define CLabel__Draw_x                                             0x700540

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C27B0
#define CListWnd__dCListWnd_x                                      0x8C3A60
#define CListWnd__AddColumn_x                                      0x8C3A00
#define CListWnd__AddColumn1_x                                     0x8C30A0
#define CListWnd__AddLine_x                                        0x8C2A80
#define CListWnd__AddString_x                                      0x8C2CA0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BF8B0
#define CListWnd__CalculateVSBRange_x                              0x8C1C70
#define CListWnd__ClearSel_x                                       0x8BEBC0
#define CListWnd__ClearAllSel_x                                    0x8BEB70
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C2640
#define CListWnd__Compare_x                                        0x8C05A0
#define CListWnd__Draw_x                                           0x8C1870
#define CListWnd__DrawColumnSeparators_x                           0x8C1700
#define CListWnd__DrawHeader_x                                     0x8BEE80
#define CListWnd__DrawItem_x                                       0x8C0C30
#define CListWnd__DrawLine_x                                       0x8C13A0
#define CListWnd__DrawSeparator_x                                  0x8C17A0
#define CListWnd__EnableLine_x                                     0x8BEDA0
#define CListWnd__EnsureVisible_x                                  0x8BFA10
#define CListWnd__ExtendSel_x                                      0x8C0B40
#define CListWnd__GetColumnMinWidth_x                              0x8BE4B0
#define CListWnd__GetColumnWidth_x                                 0x8BE3E0
#define CListWnd__GetCurSel_x                                      0x8BDBB0
#define CListWnd__GetItemAtPoint_x                                 0x8BFCB0
#define CListWnd__GetItemAtPoint1_x                                0x8BFD20
#define CListWnd__GetItemData_x                                    0x8BDEF0
#define CListWnd__GetItemHeight_x                                  0x8BF500
#define CListWnd__GetItemIcon_x                                    0x8BE0E0
#define CListWnd__GetItemRect_x                                    0x8BFAF0
#define CListWnd__GetItemText_x                                    0x8BDF90
#define CListWnd__GetSelList_x                                     0x8C2F90
#define CListWnd__GetSeparatorRect_x                               0x8C04C0
#define CListWnd__InsertLine_x                                     0x8C2E80
#define CListWnd__RemoveLine_x                                     0x8C2E90
#define CListWnd__SetColors_x                                      0x8BDD00
#define CListWnd__SetColumnJustification_x                         0x8BE740
#define CListWnd__SetColumnWidth_x                                 0x8BE460
#define CListWnd__SetCurSel_x                                      0x8BDBF0
#define CListWnd__SetItemColor_x                                   0x8C2330
#define CListWnd__SetItemData_x                                    0x8BEC20
#define CListWnd__SetItemText_x                                    0x8C2170
#define CListWnd__ShiftColumnSeparator_x                           0x8C2000
#define CListWnd__Sort_x                                           0x8C3B60
#define CListWnd__ToggleSel_x                                      0x8BEAF0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x719640

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73ECC0
#define CMerchantWnd__RequestBuyItem_x                             0x746880
#define CMerchantWnd__RequestSellItem_x                            0x748F00
#define CMerchantWnd__SelectRecoverySlot_x                         0x73BF70
#define CMerchantWnd__SelectBuySellSlot_x                          0x739E00
#define CMerchantWnd__ActualSelect_x                               0x740AB0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x854550
#define CPacketScrambler__hton_x                                   0x854560

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E1750
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E1830
#define CSidlManager__CreateLabel_x                                0x7A2E60
#define CSidlManager__CreateXWndFromTemplate_x                     0x8DFCE0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E1B10

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D8B70
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D8A60
#define CSidlScreenWnd__ConvertToRes_x                             0x8FDB20
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D9490
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DA620
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DA6D0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D9BB0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D8E40
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D8590
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D9030
#define CSidlScreenWnd__Init1_x                                    0x8DA300
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D9550
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D8750
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D9DF0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D8200
#define CSidlScreenWnd__StoreIniVis_x                              0x8D8540
#define CSidlScreenWnd__WndNotification_x                          0x8DA080
#define CSidlScreenWnd__GetChildItem_x                             0x8D8660
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CBF20
#define CSidlScreenWnd__m_layoutCopy_x                             0x172FE40

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x604DB0
#define CSkillMgr__GetSkillCap_x                                   0x604F90
#define CSkillMgr__GetNameToken_x                                  0x604960

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FCDD0
#define CSliderWnd__SetValue_x                                     0x8FCFA0
#define CSliderWnd__SetNumTicks_x                                  0x8FD720

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A91B0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F6880
#define CStmlWnd__CalculateHSBRange_x                              0x8EEDC0
#define CStmlWnd__CalculateVSBRange_x                              0x8EED30
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EEF40
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EF740
#define CStmlWnd__ForceParseNow_x                                  0x8F7200
#define CStmlWnd__GetNextTagPiece_x                                0x8EF640
#define CStmlWnd__GetSTMLText_x                                    0x484570
#define CStmlWnd__GetVisibleText_x                                 0x8F0190
#define CStmlWnd__InitializeWindowVariables_x                      0x8F2760
#define CStmlWnd__MakeStmlColorTag_x                               0x8EE010
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EE070
#define CStmlWnd__SetSTMLText_x                                    0x8F3FC0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F6520
#define CStmlWnd__UpdateHistoryString_x                            0x8F10D0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FA720
#define CTabWnd__DrawCurrentPage_x                                 0x8F9FB0
#define CTabWnd__DrawTab_x                                         0x8F9D70
#define CTabWnd__GetCurrentPage_x                                  0x8FA360
#define CTabWnd__GetPageInnerRect_x                                0x8F9A60
#define CTabWnd__GetTabInnerRect_x                                 0x8F9C60
#define CTabWnd__GetTabRect_x                                      0x8F9B30
#define CTabWnd__InsertPage_x                                      0x8FAA10
#define CTabWnd__SetPage_x                                         0x8FA390
#define CTabWnd__SetPageRect_x                                     0x8FA660
#define CTabWnd__UpdatePage_x                                      0x8FA9B0
#define CTabWnd__GetPageFromTabIndex_x                             0x8F9CC0
#define CTabWnd__GetCurrentTabIndex_x                              0x8F99F0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E6290
#define CPageWnd__SetTabText_x                                     0x906E40

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436E90

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D64E0
#define CTextureFont__GetTextExtent_x                              0x8D6240

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63D650

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x903280

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BBE60

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5A63B0
#define CXStr__CXStr1_x                                            0x403750
#define CXStr__CXStr3_x                                            0x89F190
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x89F300
#define CXStr__operator_equal1_x                                   0x89F350
#define CXStr__operator_plus_equal1_x                              0x8A0450

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D3FE0
#define CXWnd__BringToTop_x                                        0x8CB100
#define CXWnd__Center_x                                            0x8D12B0
#define CXWnd__ClrFocus_x                                          0x8CACD0
#define CXWnd__Destroy_x                                           0x8D1DA0
#define CXWnd__DoAllDrawing_x                                      0x8D0F00
#define CXWnd__DrawChildren_x                                      0x8D10A0
#define CXWnd__DrawColoredRect_x                                   0x8CB4E0
#define CXWnd__DrawTooltip_x                                       0x8CB790
#define CXWnd__DrawTooltipAtPoint_x                                0x8CFEB0
#define CXWnd__GetBorderFrame_x                                    0x8CBBF0
#define CXWnd__GetChildWndAt_x                                     0x8D1C80
#define CXWnd__GetClientClipRect_x                                 0x8CB9A0
#define CXWnd__GetScreenClipRect_x                                 0x8D05B0
#define CXWnd__GetScreenRect_x                                     0x8CBDC0
#define CXWnd__GetTooltipRect_x                                    0x8CB620
#define CXWnd__GetWindowTextA_x                                    0x426F60
#define CXWnd__IsActive_x                                          0x8C6800
#define CXWnd__IsDescendantOf_x                                    0x8CBB30
#define CXWnd__IsReallyVisible_x                                   0x8CEED0
#define CXWnd__IsType_x                                            0x8D1320
#define CScreenPieceTemplate__IsType_x                             0x8FF9B0
#define CXWnd__Move_x                                              0x8CE640
#define CXWnd__Move1_x                                             0x8D0BC0
#define CXWnd__ProcessTransition_x                                 0x8CB0B0
#define CXWnd__Refade_x                                            0x8CAE80
#define CXWnd__Resize_x                                            0x8CBE80
#define CXWnd__Right_x                                             0x8D03B0
#define CXWnd__SetFocus_x                                          0x8CD790
#define CXWnd__SetFont_x                                           0x8CAD20
#define CXWnd__SetKeyTooltip_x                                     0x8CC0F0
#define CXWnd__SetMouseOver_x                                      0x8D08B0
#define CXWnd__StartFade_x                                         0x8CB150
#define CXWnd__GetChildItem_x                                      0x8D0800
#define CXWnd__SetParent_x                                         0x8D1C30

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C80A0
#define CXWndManager__DrawWindows_x                                0x8C7CE0
#define CXWndManager__GetKeyboardFlags_x                           0x8C6340
#define CXWndManager__HandleKeyboardMsg_x                          0x8C6C90
#define CXWndManager__RemoveWnd_x                                  0x8C6990

// CDBStr
#define CDBStr__GetString_x                                        0x4BA4B0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4527B0
#define EQ_Character__Cur_HP_x                                     0x466B50
#define EQ_Character__Cur_Mana_x                                   0x45BB30
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B8B0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4437E0
#define EQ_Character__GetFocusRangeModifier_x                      0x443930
#define EQ_Character__GetHPRegen_x                                 0x46A6F0
#define EQ_Character__GetEnduranceRegen_x                          0x466160
#define EQ_Character__GetManaRegen_x                               0x46AC90
#define EQ_Character__Max_Endurance_x                              0x5CB770
#define EQ_Character__Max_HP_x                                     0x45E6B0
#define EQ_Character__Max_Mana_x                                   0x5CB5A0
#define EQ_Character__doCombatAbility_x                            0x5C8C70
#define EQ_Character__UseSkill_x                                   0x472A80
#define EQ_Character__GetConLevel_x                                0x5BE240
#define EQ_Character__IsExpansionFlag_x                            0x4B67E0
#define EQ_Character__TotalEffect_x                                0x44F9E0
#define EQ_Character__GetPCSpellAffect_x                           0x44BC40
#define EQ_Character__SpellDuration_x                              0x449C40
#define EQ_Character__FindItemByRecord_x                           0x4641A0
#define EQ_Character__GetAdjustedSkill_x                           0x466D20
#define EQ_Character__GetBaseSkill_x                               0x45E590

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x872490

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D3E30

//PcClient
#define PcClient__PcClient_x                                       0x5C0090

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446D20
#define CCharacterSelect__EnterWorld_x                             0x4464F0
#define CCharacterSelect__Quit_x                                   0x4450B0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59E100
#define EQ_Item__CreateItemTagString_x                             0x852780
#define EQ_Item__IsStackable_x                                     0x847E70
#define EQ_Item__GetImageNum_x                                     0x84A960
#define EQ_Item__CreateItemClient_x                                0x59F240
#define EQ_Item__GetItemValue_x                                    0x851240
#define EQ_Item__ValueSellMerchant_x                               0x8541B0
#define EQ_Item__IsKeyRingItem_x                                   0x848960
#define EQ_Item__CanGoInBag_x                                      0x59E290
#define EQ_Item__GetMaxItemCount_x                                 0x847D60
#define EQ_Item__GetHeldItem_x                                     0x849770
#define EQ_Item__GetAugmentFitBySlot_x                             0x853FE0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA640
#define EQ_LoadingS__Array_x                                       0xC0AC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CDCA0
#define EQ_PC__GetAlternateAbilityId_x                             0x85C690
#define EQ_PC__GetCombatAbility_x                                  0x85C720
#define EQ_PC__GetCombatAbilityTimer_x                             0x857200
#define EQ_PC__GetItemRecastTimer_x                                0x5C7460
#define EQ_PC__HasLoreItem_x                                       0x5C1850
#define EQ_PC__AlertInventoryChanged_x                             0x5BE1F0
#define EQ_PC__GetPcZoneClient_x                                   0x5E84D0
#define EQ_PC__RemoveMyAffect_x                                    0x5C6890
#define EQ_PC__GetKeyRingItems_x                                   0x857620
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86A400
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85E670

// EQItemList 
#define EQItemList__EQItemList_x                                   0x526320
#define EQItemList__add_object_x                                   0x5534B0
#define EQItemList__add_item_x                                     0x526260
#define EQItemList__delete_item_x                                  0x526710
#define EQItemList__FreeItemList_x                                 0x526610

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9740

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D3AF0
#define EQPlayer__dEQPlayer_x                                      0x5DC2B0
#define EQPlayer__DoAttack_x                                       0x5EDCB0
#define EQPlayer__EQPlayer_x                                       0x5DE9E0
#define EQPlayer__SetNameSpriteState_x                             0x5D90E0
#define EQPlayer__SetNameSpriteTint_x                              0x5D4FF0
#define PlayerBase__HasProperty_j_x                                0x9312C0
#define EQPlayer__IsTargetable_x                                   0x931560
#define EQPlayer__CanSee_x                                         0x931AC0
#define PlayerZoneClient__ChangeHeight_x                           0x5EDB70
#define EQPlayer__CanSee1_x                                        0x931BB0
#define PlayerBase__GetVisibilityLineSegment_x                     0x931850

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E8680
#define PlayerZoneClient__IsValidTeleport_x                        0x553D50
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D28C0


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E2AA0
#define EQPlayerManager__GetSpawnByName_x                          0x5E2F00
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E2AD0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A4740
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A4780
#define KeypressHandler__ClearCommandStateArray_x                  0x5A4330
#define KeypressHandler__HandleKeyDown_x                           0x5A2C50
#define KeypressHandler__HandleKeyUp_x                             0x5A2F70
#define KeypressHandler__SaveKeymapping_x                          0x5A4400

// MapViewMap 
#define MapViewMap__Clear_x                                        0x711FD0
#define MapViewMap__SaveEx_x                                       0x715300
#define MapViewMap__SetZoom_x                                      0x711C50

#define PlayerPointManager__GetAltCurrency_x                       0x870550

// StringTable 
#define StringTable__getString_x                                   0x86A730

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CB200
#define PcZoneClient__RemovePetEffect_x                            0x5C7930
#define PcZoneClient__HasAlternateAbility_x                        0x5C82D0
#define PcZoneClient__GetCurrentMod_x                              0x45DB60
#define PcZoneClient__GetModCap_x                                  0x45B290
#define PcZoneClient__CanEquipItem_x                               0x5C87B0
#define PcZoneClient__GetItemByID_x                                0x5CD010
#define PcZoneClient__GetItemByItemClass_x                         0x5CDBC0
#define PcZoneClient__RemoveBuffEffect_x                           0x5C6B40

//Doors
#define EQSwitch__UseSwitch_x                                      0x55AE80

//IconCache
#define IconCache__GetIcon_x                                       0x6AF220

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A6120
#define CContainerMgr__CloseContainer_x                            0x6A6940

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x772D60

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x597150

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F4C30
#define EQ_Spell__SpellAffects_x                                   0x4F1E10
#define EQ_Spell__SpellAffectBase_x                                0x4F1E80
#define CharacterZoneClient__CalcAffectChange_x                    0x44BAD0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AD70
#define CLootWnd__LootAll_x                                        0x707920
#define CLootWnd__RequestLootSlot_x                                0x708130
#define EQ_Spell__IsStackable_x                                    0x459290
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449700
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43ED30
#define EQ_Spell__IsSPAStacking_x                                  0x4F1980
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2A20
#define EQ_Spell__IsNoRemove_x                                     0x434EC0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F19A0

#define __IsResEffectSpell_x                                       0x449790

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87C110

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BAAF0
#define CTargetWnd__WndNotification_x                              0x7BA5E0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BACD0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7BFC20

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED460
#define EqSoundManager__PlayScriptMp3_x                            0x4EEF00

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8890

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EA3E0
#define CSidlManager__FindAnimation1_x                             0x8DF710

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E1E70
#define CAltAbilityData__GetMercMaxRank_x                          0x4E1E20
#define CAltAbilityData__GetMaxRank_x                              0x4D6750

//CTargetRing
#define CTargetRing__Cast_x                                        0x594D90

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459580
#define CharacterBase__CreateItemGlobalIndex_x                     0x4754B0
#define CharacterBase__CreateItemIndex_x                           0x51F950
#define CharacterBase__GetItemPossession_x                         0x444550
#define CharacterBase__GetItemByGlobalIndex_x                      0x87FF60
#define CharacterBase__GetEffectId_x                               0x459540

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68EF60
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68E6C0

//messages
#define msg_spell_worn_off_x                                       0x4FC760
#define msg_new_text_x                                             0x505EE0
#define msgTokenTextParam_x                                        0x5026E0

//SpellManager
#define SpellManager__vftable_x                                    0xAC8278
#define SpellManager__SpellManager_x                               0x47E1B0
#define Spellmanager__LoadTextSpells_x                             0x60BC90

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x935630

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487BA0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EC40
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449420
#define ItemGlobalIndex__IsValidIndex_x                            0x458DD0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87DDD0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87CD10

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x700790

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AAE50
#define CCursorAttachment__Deactivate_x                            0x6AA390

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FC2D0
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FC450

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                        0x603980

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C410

//IString
#define IString__Append_x                                          0x47EE60

//Camera
#define CDisplay__cameraType_x                                     0xE6E7E8
#define EverQuest__Cameras_x                                       0xF30AE8
