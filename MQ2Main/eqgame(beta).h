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
#define __ExpectedVersionDate                                     "Dec  7 2017"
#define __ExpectedVersionTime                                     "04:18:07"
#define __ActualVersionDate_x                                      0xAE30D8
#define __ActualVersionTime_x                                      0xAE30E4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5A9930
#define __MemChecker1_x                                            0x8A1F10
#define __MemChecker2_x                                            0x63F640
#define __MemChecker3_x                                            0x63F590
#define __MemChecker4_x                                            0x7F37A0
#define __EncryptPad0_x                                            0xC3DFE8
#define __EncryptPad1_x                                            0xD17BA0
#define __EncryptPad2_x                                            0xC66ED0
#define __EncryptPad3_x                                            0xC66AD0
#define __EncryptPad4_x                                            0xD061A0
#define __EncryptPad5_x                                            0x10C12E0
#define __AC1_x                                                    0x7B2FE5
#define __AC2_x                                                    0x562C07
#define __AC3_x                                                    0x560D80
#define __AC4_x                                                    0x572F51
#define __AC5_x                                                    0x586CAB
#define __AC6_x                                                    0x58A84E
#define __AC7_x                                                    0x5812AC
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
#define __do_loot_x                                                0x531BE0
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
#define __CastRay_x                                                0x549490
#define __CastRay2_x                                               0x548DC0
#define __HeadingDiff_x                                            0x9325F0
#define __FixHeading_x                                             0x932580
#define __get_bearing_x                                            0x538D30
#define __ConvertItemTags_x                                        0x536800
#define __ExecuteCmd_x                                             0x521140
#define __EQGetTime_x                                              0x8A18B0
#define __get_melee_range_x                                        0x527DC0
#define __GetGaugeValueFromEQ_x                                    0x7B1BA0
#define __GetLabelFromEQ_x                                         0x7B2F70
#define __ToggleKeyRingItem_x                                      0x48F770
#define __GetXTargetType_x                                         0x9341F0
#define __LoadFrontEnd_x                                           0x63ED10
#define __NewUIINI_x                                               0x7B1580
#define __ProcessGameEvents_x                                      0x583040
#define __ProcessMouseEvent_x                                      0x5827E0
#define CrashDetected_x                                            0x6406D0
#define wwsCrashReportCheckForUploader_x                           0x7FF7E0
#define __AppCrashWrapper_x                                        0xC66AC4
#define __pCrashHandler_x                                          0x10D6A00
#define __CrashHandler_x                                           0x7FF270
#define wwsCrashReportPlatformLaunchUploader_x                     0x801A20
#define DrawNetStatus_x                                            0x5B9640
#define Util__FastTime_x                                           0x8A1550
#define Expansion_HoT_x                                            0xF307D0
#define __HelpPath_x                                               0xFB3F80
#define __STMLToText_x                                             0x8E7D10
#define __GetAnimationCache_x                                      0x6AE4D0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4232E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DF40
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DD10

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D79F0
#define AltAdvManager__IsAbilityReady_x                            0x4D7A60
#define AltAdvManager__GetAAById_x                                 0x4D7F50
#define AltAdvManager__CanTrainAbility_x                           0x4D8B80
#define AltAdvManager__CanSeeAbility_x                             0x4D8740

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46AC80
#define CharacterZoneClient__HasSkill_x                            0x466B90
#define CharacterZoneClient__MakeMeVisible_x                       0x46C7F0
#define CharacterZoneClient__IsStackBlocked_x                      0x44BCF0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B210
#define CharacterZoneClient__GetItemCountWorn_x                    0x4650F0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4651D0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4652B0
#define CharacterZoneClient__FindAffectSlot_x                      0x451380
#define CharacterZoneClient__BardCastBard_x                        0x44A980
#define CharacterZoneClient__GetMaxEffects_x                       0x449510
#define CharacterZoneClient__GetEffect_x                           0x44B440
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4511E0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449860
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FD30

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66E6B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67C500

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x598150
#define CButtonWnd__CButtonWnd_x                                   0x8DBEC0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x697690
#define CChatManager__InitContextMenu_x                            0x6987E0
#define CChatManager__FreeChatWindow_x                             0x697140
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A0980
#define CChatManager__SetLockedActiveChatWindow_x                  0x697660

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E6060
#define CContextMenu__dCContextMenu_x                              0x8E6270
#define CContextMenu__AddMenuItem_x                                0x8E6790
#define CContextMenu__RemoveMenuItem_x                             0x8E63F0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E6410
#define CContextMenu__CheckMenuItem_x                              0x8E6490
#define CContextMenu__SetMenuItem_x                                0x8E6310

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D24A0
#define CContextMenuManager__RemoveMenu_x                          0x8D2840
#define CContextMenuManager__PopupMenu_x                           0x8D2C90
#define CContextMenuManager__Flush_x                               0x8D2510
#define CContextMenuManager__GetMenu_x                             0x419410

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x885960
#define CChatService__GetFriendName_x                              0x885970

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69E450
#define CChatWindow__Clear_x                                       0x69DD30
#define CChatWindow__WndNotification_x                             0x69ED60

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D62F0
#define CComboWnd__Draw_x                                          0x8D6500
#define CComboWnd__GetCurChoice_x                                  0x8D60A0
#define CComboWnd__GetListRect_x                                   0x8D67A0
#define CComboWnd__GetTextRect_x                                   0x8D6360
#define CComboWnd__InsertChoice_x                                  0x8D6900
#define CComboWnd__SetColors_x                                     0x8D6030
#define CComboWnd__SetChoice_x                                     0x8D6060
#define CComboWnd__GetItemCount_x                                  0x8D6090
#define CComboWnd__GetCurChoiceText_x                              0x8D60E0


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A8650
#define CContainerWnd__vftable_x                                   0xAEC9F0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C5930
#define CDisplay__GetClickedActor_x                                0x4BE1F0
#define CDisplay__GetUserDefinedColor_x                            0x4BCDD0
#define CDisplay__GetWorldFilePath_x                               0x4BC220
#define CDisplay__is3dON_x                                         0x4BB6B0
#define CDisplay__ReloadUI_x                                       0x4CF6F0
#define CDisplay__WriteTextHD2_x                                   0x4C1CC0
#define CDisplay__TrueDistance_x                                   0x4BEE20

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FD3F0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EA5C0
#define CEditWnd__GetCharIndexPt_x                                 0x8EB710
#define CEditWnd__GetDisplayString_x                               0x8EA770
#define CEditWnd__GetHorzOffset_x                                  0x8EAAB0
#define CEditWnd__GetLineForPrintableChar_x                        0x8EB1E0
#define CEditWnd__GetSelStartPt_x                                  0x8EB9C0
#define CEditWnd__GetSTMLSafeText_x                                0x8EAC50
#define CEditWnd__PointFromPrintableChar_x                         0x8EB2D0
#define CEditWnd__SelectableCharFromPoint_x                        0x8EB450
#define CEditWnd__SetEditable_x                                    0x8EAC20

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x569780
#define CEverQuest__ClickedPlayer_x                                0x563350
#define CEverQuest__CreateTargetIndicator_x                        0x564250
#define CEverQuest__DeleteTargetIndicator_x                        0x5642D0
#define CEverQuest__DoTellWindow_x                                 0x475EF0
#define CEverQuest__OutputTextToLog_x                              0x475B50
#define CEverQuest__DropHeldItemOnGround_x                         0x579CF0
#define CEverQuest__dsp_chat_x                                     0x476230
#define CEverQuest__trimName_x                                     0x55FC60
#define CEverQuest__Emote_x                                        0x578000
#define CEverQuest__EnterZone_x                                    0x5730E0
#define CEverQuest__GetBodyTypeDesc_x                              0x55D6A0
#define CEverQuest__GetClassDesc_x                                 0x566B90
#define CEverQuest__GetClassThreeLetterCode_x                      0x567190
#define CEverQuest__GetDeityDesc_x                                 0x55DF80
#define CEverQuest__GetLangDesc_x                                  0x55DA30
#define CEverQuest__GetRaceDesc_x                                  0x567350
#define CEverQuest__InterpretCmd_x                                 0x56AF00
#define CEverQuest__LeftClickedOnPlayer_x                          0x57F850
#define CEverQuest__LMouseUp_x                                     0x581800
#define CEverQuest__RightClickedOnPlayer_x                         0x580360
#define CEverQuest__RMouseUp_x                                     0x581260
#define CEverQuest__SetGameState_x                                 0x563C20
#define CEverQuest__UPCNotificationFlush_x                         0x55C030
#define CEverQuest__IssuePetCommand_x                              0x56B8E0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B9270
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B92D0
#define CGaugeWnd__Draw_x                                          0x6B9700

// CGuild
#define CGuild__FindMemberByName_x                                 0x43AF10
#define CGuild__GetGuildName_x                                     0x43B3E0
#define CGuild__GetGuildIndex_x                                    0x43C5F0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D57F0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E2BA0
#define CInvSlotMgr__MoveItem_x                                    0x6E3360
#define CInvSlotMgr__SelectSlot_x                                  0x6E24A0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E1900
#define CInvSlot__SliderComplete_x                                 0x6DF120
#define CInvSlot__GetItemBase_x                                    0x6DE5B0
#define CInvSlot__UpdateItem_x                                     0x6DEB30

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E47C0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E58F0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7ADA10
#define CItemDisplayWnd__UpdateStrings_x                           0x6E69F0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F3230
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F3740
#define CItemDisplayWnd__SetItem_x                                 0x6F8FB0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E4A00

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6ECF20

// CLabel 
#define CLabel__Draw_x                                             0x6FFD80

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C20A0
#define CListWnd__dCListWnd_x                                      0x8C3350
#define CListWnd__AddColumn_x                                      0x8C32F0
#define CListWnd__AddColumn1_x                                     0x8C2990
#define CListWnd__AddLine_x                                        0x8C2370
#define CListWnd__AddString_x                                      0x8C2590
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BF1C0
#define CListWnd__CalculateVSBRange_x                              0x8C1570
#define CListWnd__ClearSel_x                                       0x8BE4E0
#define CListWnd__ClearAllSel_x                                    0x8BE490
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C1F30
#define CListWnd__Compare_x                                        0x8BFEB0
#define CListWnd__Draw_x                                           0x8C1170
#define CListWnd__DrawColumnSeparators_x                           0x8C1000
#define CListWnd__DrawHeader_x                                     0x8BE7A0
#define CListWnd__DrawItem_x                                       0x8C0530
#define CListWnd__DrawLine_x                                       0x8C0CA0
#define CListWnd__DrawSeparator_x                                  0x8C10A0
#define CListWnd__EnableLine_x                                     0x8BE6C0
#define CListWnd__EnsureVisible_x                                  0x8BF320
#define CListWnd__ExtendSel_x                                      0x8C0440
#define CListWnd__GetColumnMinWidth_x                              0x8BDDD0
#define CListWnd__GetColumnWidth_x                                 0x8BDD00
#define CListWnd__GetCurSel_x                                      0x8BD4E0
#define CListWnd__GetItemAtPoint_x                                 0x8BF5B0
#define CListWnd__GetItemAtPoint1_x                                0x8BF620
#define CListWnd__GetItemData_x                                    0x8BD810
#define CListWnd__GetItemHeight_x                                  0x8BEE20
#define CListWnd__GetItemIcon_x                                    0x8BDA00
#define CListWnd__GetItemRect_x                                    0x8BF3F0
#define CListWnd__GetItemText_x                                    0x8BD8B0
#define CListWnd__GetSelList_x                                     0x8C2880
#define CListWnd__GetSeparatorRect_x                               0x8BFDD0
#define CListWnd__InsertLine_x                                     0x8C2770
#define CListWnd__RemoveLine_x                                     0x8C2780
#define CListWnd__SetColors_x                                      0x8BD630
#define CListWnd__SetColumnJustification_x                         0x8BE060
#define CListWnd__SetColumnWidth_x                                 0x8BDD80
#define CListWnd__SetCurSel_x                                      0x8BD520
#define CListWnd__SetItemColor_x                                   0x8C1C20
#define CListWnd__SetItemData_x                                    0x8BE540
#define CListWnd__SetItemText_x                                    0x8C1A60
#define CListWnd__ShiftColumnSeparator_x                           0x8C18F0
#define CListWnd__Sort_x                                           0x8C3450
#define CListWnd__ToggleSel_x                                      0x8BE410

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x718F80

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73E720
#define CMerchantWnd__RequestBuyItem_x                             0x7462C0
#define CMerchantWnd__RequestSellItem_x                            0x7488C0
#define CMerchantWnd__SelectRecoverySlot_x                         0x73B9E0
#define CMerchantWnd__SelectBuySellSlot_x                          0x739860
#define CMerchantWnd__ActualSelect_x                               0x740510

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x853C20
#define CPacketScrambler__hton_x                                   0x853C30

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E0F10
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E0FF0
#define CSidlManager__CreateLabel_x                                0x7A2910
#define CSidlManager__CreateXWndFromTemplate_x                     0x8DF4A0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E12D0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D8330
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D8230
#define CSidlScreenWnd__ConvertToRes_x                             0x8FD2D0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D8C30
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D9E20
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D9ED0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D9390
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D85E0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D7D60
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D87D0
#define CSidlScreenWnd__Init1_x                                    0x8D9AF0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D8CF0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D7F20
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D95D0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D79C0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D7D10
#define CSidlScreenWnd__WndNotification_x                          0x8D9870
#define CSidlScreenWnd__GetChildItem_x                             0x8D7E30
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CB810
#define CSidlScreenWnd__m_layoutCopy_x                             0x172FE40

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6047A0
#define CSkillMgr__GetSkillCap_x                                   0x604980
#define CSkillMgr__GetNameToken_x                                  0x604350

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FC580
#define CSliderWnd__SetValue_x                                     0x8FC750
#define CSliderWnd__SetNumTicks_x                                  0x8FCED0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A8D00

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F6000
#define CStmlWnd__CalculateHSBRange_x                              0x8EE570
#define CStmlWnd__CalculateVSBRange_x                              0x8EE4E0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EE6F0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EEEF0
#define CStmlWnd__ForceParseNow_x                                  0x8F6980
#define CStmlWnd__GetNextTagPiece_x                                0x8EEDF0
#define CStmlWnd__GetSTMLText_x                                    0x4840C0
#define CStmlWnd__GetVisibleText_x                                 0x8EF940
#define CStmlWnd__InitializeWindowVariables_x                      0x8F1F00
#define CStmlWnd__MakeStmlColorTag_x                               0x8ED7C0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8ED820
#define CStmlWnd__SetSTMLText_x                                    0x8F3750
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F5CA0
#define CStmlWnd__UpdateHistoryString_x                            0x8F0880

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8F9EA0
#define CTabWnd__DrawCurrentPage_x                                 0x8F9730
#define CTabWnd__DrawTab_x                                         0x8F94F0
#define CTabWnd__GetCurrentPage_x                                  0x8F9AE0
#define CTabWnd__GetPageInnerRect_x                                0x8F91E0
#define CTabWnd__GetTabInnerRect_x                                 0x8F93E0
#define CTabWnd__GetTabRect_x                                      0x8F92B0
#define CTabWnd__InsertPage_x                                      0x8FA190
#define CTabWnd__SetPage_x                                         0x8F9B10
#define CTabWnd__SetPageRect_x                                     0x8F9DE0
#define CTabWnd__UpdatePage_x                                      0x8FA130
#define CTabWnd__GetPageFromTabIndex_x                             0x8F9440
#define CTabWnd__GetCurrentTabIndex_x                              0x8F9170

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E5AA0
#define CPageWnd__SetTabText_x                                     0x906600

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436AB0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D5CA0
#define CTextureFont__GetTextExtent_x                              0x8D5A00

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63CFA0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x902A40

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BB440

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5A5D70
#define CXStr__CXStr1_x                                            0x7E0740
#define CXStr__CXStr3_x                                            0x89E7E0
#define CXStr__dCXStr_x                                            0x47BE40
#define CXStr__operator_equal_x                                    0x89E950
#define CXStr__operator_equal1_x                                   0x89E9A0
#define CXStr__operator_plus_equal1_x                              0x89FAA0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D37B0
#define CXWnd__BringToTop_x                                        0x8CAAA0
#define CXWnd__Center_x                                            0x8D0AB0
#define CXWnd__ClrFocus_x                                          0x8CA670
#define CXWnd__Destroy_x                                           0x8D1580
#define CXWnd__DoAllDrawing_x                                      0x8D0700
#define CXWnd__DrawChildren_x                                      0x8D08A0
#define CXWnd__DrawColoredRect_x                                   0x8CAE70
#define CXWnd__DrawTooltip_x                                       0x8CB110
#define CXWnd__DrawTooltipAtPoint_x                                0x8CF6A0
#define CXWnd__GetBorderFrame_x                                    0x8CB500
#define CXWnd__GetChildWndAt_x                                     0x8D1460
#define CXWnd__GetClientClipRect_x                                 0x8CB310
#define CXWnd__GetScreenClipRect_x                                 0x8CFDA0
#define CXWnd__GetScreenRect_x                                     0x8CB6B0
#define CXWnd__GetTooltipRect_x                                    0x8CAFA0
#define CXWnd__GetWindowTextA_x                                    0x426E50
#define CXWnd__IsActive_x                                          0x8C60F0
#define CXWnd__IsDescendantOf_x                                    0x8CB450
#define CXWnd__IsReallyVisible_x                                   0x8CE710
#define CXWnd__IsType_x                                            0x8D0B20
#define CScreenPieceTemplate__IsType_x                             0x8FF150
#define CXWnd__Move_x                                              0x8CDE50
#define CXWnd__Move1_x                                             0x8D03C0
#define CXWnd__ProcessTransition_x                                 0x8CAA50
#define CXWnd__Refade_x                                            0x8CA820
#define CXWnd__Resize_x                                            0x8CB770
#define CXWnd__Right_x                                             0x8CFBA0
#define CXWnd__SetFocus_x                                          0x8CCFC0
#define CXWnd__SetFont_x                                           0x8CA6C0
#define CXWnd__SetKeyTooltip_x                                     0x8CB9E0
#define CXWnd__SetMouseOver_x                                      0x8D00E0
#define CXWnd__StartFade_x                                         0x8CAAF0
#define CXWnd__GetChildItem_x                                      0x8D0020
#define CXWnd__SetParent_x                                         0x8D1410

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C7990
#define CXWndManager__DrawWindows_x                                0x8C75E0
#define CXWndManager__GetKeyboardFlags_x                           0x8C5C30
#define CXWndManager__HandleKeyboardMsg_x                          0x8C6580
#define CXWndManager__RemoveWnd_x                                  0x8C6280

// CDBStr
#define CDBStr__GetString_x                                        0x4B9EF0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452440
#define EQ_Character__Cur_HP_x                                     0x466770
#define EQ_Character__Cur_Mana_x                                   0x45B750
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B520
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4434C0
#define EQ_Character__GetFocusRangeModifier_x                      0x443610
#define EQ_Character__GetHPRegen_x                                 0x46A310
#define EQ_Character__GetEnduranceRegen_x                          0x465D80
#define EQ_Character__GetManaRegen_x                               0x46A8B0
#define EQ_Character__Max_Endurance_x                              0x5CB3C0
#define EQ_Character__Max_HP_x                                     0x45E2D0
#define EQ_Character__Max_Mana_x                                   0x5CB1F0
#define EQ_Character__doCombatAbility_x                            0x5C88C0
#define EQ_Character__UseSkill_x                                   0x4726A0
#define EQ_Character__GetConLevel_x                                0x5BDC20
#define EQ_Character__IsExpansionFlag_x                            0x4B61F0
#define EQ_Character__TotalEffect_x                                0x44F670
#define EQ_Character__GetPCSpellAffect_x                           0x44B8B0
#define EQ_Character__SpellDuration_x                              0x4498B0
#define EQ_Character__FindItemByRecord_x                           0x463DC0
#define EQ_Character__GetAdjustedSkill_x                           0x466940
#define EQ_Character__GetBaseSkill_x                               0x45E1B0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x871B80

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D3A40

//PcClient
#define PcClient__PcClient_x                                       0x5BFA50

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x4469C0
#define CCharacterSelect__EnterWorld_x                             0x446190
#define CCharacterSelect__Quit_x                                   0x444D50

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59DAB0
#define EQ_Item__CreateItemTagString_x                             0x851E20
#define EQ_Item__IsStackable_x                                     0x847500
#define EQ_Item__GetImageNum_x                                     0x849FD0
#define EQ_Item__CreateItemClient_x                                0x59EBD0
#define EQ_Item__GetItemValue_x                                    0x8508F0
#define EQ_Item__ValueSellMerchant_x                               0x853880
#define EQ_Item__IsKeyRingItem_x                                   0x847FE0
#define EQ_Item__CanGoInBag_x                                      0x59DC40
#define EQ_Item__GetMaxItemCount_x                                 0x8473F0
#define EQ_Item__GetHeldItem_x                                     0x848DE0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8536A0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4D9F90
#define EQ_LoadingS__Array_x                                       0xC0AC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CD8F0
#define EQ_PC__GetAlternateAbilityId_x                             0x85BD30
#define EQ_PC__GetCombatAbility_x                                  0x85BDC0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8568D0
#define EQ_PC__GetItemRecastTimer_x                                0x5C70B0
#define EQ_PC__HasLoreItem_x                                       0x5C1210
#define EQ_PC__AlertInventoryChanged_x                             0x5BDBD0
#define EQ_PC__GetPcZoneClient_x                                   0x5E7F80
#define EQ_PC__RemoveMyAffect_x                                    0x5C64E0
#define EQ_PC__GetKeyRingItems_x                                   0x856CF0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x869A40
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85DCB0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x525E60
#define EQItemList__add_object_x                                   0x552F90
#define EQItemList__add_item_x                                     0x525DA0
#define EQItemList__delete_item_x                                  0x526250
#define EQItemList__FreeItemList_x                                 0x526150

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B91A0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D3700
#define EQPlayer__dEQPlayer_x                                      0x5DBE90
#define EQPlayer__DoAttack_x                                       0x5ED760
#define EQPlayer__EQPlayer_x                                       0x5DE5C0
#define EQPlayer__SetNameSpriteState_x                             0x5D8CE0
#define EQPlayer__SetNameSpriteTint_x                              0x5D4C00
#define PlayerBase__HasProperty_j_x                                0x9309F0
#define EQPlayer__IsTargetable_x                                   0x930C90
#define EQPlayer__CanSee_x                                         0x9311F0
#define PlayerZoneClient__ChangeHeight_x                           0x5ED620
#define EQPlayer__CanSee1_x                                        0x9312E0
#define PlayerBase__GetVisibilityLineSegment_x                     0x930F80

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E8130
#define PlayerZoneClient__IsValidTeleport_x                        0x553830
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D22E0


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E25C0
#define EQPlayerManager__GetSpawnByName_x                          0x5E2A20
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E25F0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A4100
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A4140
#define KeypressHandler__ClearCommandStateArray_x                  0x5A3CF0
#define KeypressHandler__HandleKeyDown_x                           0x5A2610
#define KeypressHandler__HandleKeyUp_x                             0x5A2930
#define KeypressHandler__SaveKeymapping_x                          0x5A3DC0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x711910
#define MapViewMap__SaveEx_x                                       0x714C40
#define MapViewMap__SetZoom_x                                      0x711590

#define PlayerPointManager__GetAltCurrency_x                       0x86FC40

// StringTable 
#define StringTable__getString_x                                   0x869D70

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CAE50
#define PcZoneClient__RemovePetEffect_x                            0x5C7580
#define PcZoneClient__HasAlternateAbility_x                        0x5C7F20
#define PcZoneClient__GetCurrentMod_x                              0x45D780
#define PcZoneClient__GetModCap_x                                  0x45AEB0
#define PcZoneClient__CanEquipItem_x                               0x5C8400
#define PcZoneClient__GetItemByID_x                                0x5CCC60
#define PcZoneClient__GetItemByItemClass_x                         0x5CD810
#define PcZoneClient__RemoveBuffEffect_x                           0x5C6790

//Doors
#define EQSwitch__UseSwitch_x                                      0x55A950

//IconCache
#define IconCache__GetIcon_x                                       0x6AEB00

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A59F0
#define CContainerMgr__CloseContainer_x                            0x6A6210

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7726E0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x596B80

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F46A0
#define EQ_Spell__SpellAffects_x                                   0x4F1880
#define EQ_Spell__SpellAffectBase_x                                0x4F18F0
#define CharacterZoneClient__CalcAffectChange_x                    0x44B740
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44A9E0
#define CLootWnd__LootAll_x                                        0x707130
#define CLootWnd__RequestLootSlot_x                                0x707940
#define EQ_Spell__IsStackable_x                                    0x458F20
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449360
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EA10
#define EQ_Spell__IsSPAStacking_x                                  0x4F13F0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2490
#define EQ_Spell__IsNoRemove_x                                     0x434B00
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F1410

#define __IsResEffectSpell_x                                       0x449400

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87B7F0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BA670
#define CTargetWnd__WndNotification_x                              0x7BA160
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BA850

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7BF7A0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ECF70
#define EqSoundManager__PlayScriptMp3_x                            0x4EEA10

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A82F0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E9BF0
#define CSidlManager__FindAnimation1_x                             0x8DEED0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E17C0
#define CAltAbilityData__GetMercMaxRank_x                          0x4E1770
#define CAltAbilityData__GetMaxRank_x                              0x4D60A0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5947D0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459210
#define CharacterBase__CreateItemGlobalIndex_x                     0x4750D0
#define CharacterBase__CreateItemIndex_x                           0x51F470
#define CharacterBase__GetItemPossession_x                         0x4441E0
#define CharacterBase__GetItemByGlobalIndex_x                      0x87F650
#define CharacterBase__GetEffectId_x                               0x4591D0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68E880
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68DFE0

//messages
#define msg_spell_worn_off_x                                       0x4FC210
#define msg_new_text_x                                             0x5059A0
#define msgTokenTextParam_x                                        0x5021A0

//SpellManager
#define SpellManager__vftable_x                                    0xAC8260
#define SpellManager__SpellManager_x                               0x47DD20
#define Spellmanager__LoadTextSpells_x                             0x60B680

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x934D10

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487810
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43E920
#define ItemGlobalIndex__IsEquippedLocation_x                      0x4490A0
#define ItemGlobalIndex__IsValidIndex_x                            0x458A60

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87D4C0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87C400

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6FFFD0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AA720
#define CCursorAttachment__Deactivate_x                            0x6A9C60

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FBA80
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FBC00

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                        0x603370

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C090

//IString
#define IString__Append_x                                          0x47E970

//Camera
#define CDisplay__cameraType_x                                     0xE6E7E8
#define EverQuest__Cameras_x                                       0xF30AE8
