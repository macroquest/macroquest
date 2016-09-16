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
#elif defined(TEST)
#include "eqgame-private(test).h"
#endif
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Sep 14 2016"
#define __ExpectedVersionTime                                     "16:34:56"
#define __ActualVersionDate_x                                      0xAD52D8
#define __ActualVersionTime_x                                      0xAD52E4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59E040
#define __MemChecker1_x                                            0x896F60
#define __MemChecker2_x                                            0x634140
#define __MemChecker3_x                                            0x634090
#define __MemChecker4_x                                            0x7E5F40
#define __EncryptPad0_x                                            0xC779F0
#define __EncryptPad1_x                                            0xE03C88
#define __EncryptPad2_x                                            0xCC0688
#define __EncryptPad3_x                                            0xCC0288
#define __EncryptPad4_x                                            0xDD9890
#define __EncryptPad5_x                                            0x11B4BE0
#define __AC1_x                                                    0x7A5AB5
#define __AC2_x                                                    0x558007
#define __AC3_x                                                    0x5561A0
#define __AC4_x                                                    0x5689B0
#define __AC5_x                                                    0x57B53B
#define __AC6_x                                                    0x57F0EE
#define __AC7_x                                                    0x575BDC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1ED21C

// Direct Input
#define DI8__Main_x                                                0x11B4BB8
#define DI8__Keyboard_x                                            0x11B4BBC
#define DI8__Mouse_x                                               0x11B4BC0
#define DI8__Mouse_Copy_x                                          0x10232A4
#define DI8__Mouse_Check_x                                         0x10ACAA4
#define __Attack_x                                                 0x10A7787
#define __Autofire_x                                               0x10A7788
#define __BindList_x                                               0xC394A8
#define g_eqCommandStates_x                                        0x1012708
#define __Clicks_x                                                 0x1023360
#define __CommandList_x                                            0xC3D890
#define __CurrentMapLabel_x                                        0x11BA640
#define __CurrentSocial_x                                          0xBED0B8
#define __DoAbilityList_x                                          0x1059A3C
#define __do_loot_x                                                0x51D600
#define __DrawHandler_x                                            0x1821674
#define __GroupCount_x                                             0x1013CD2

#define __Guilds_x                                                 0x10198E8
#define __gWorld_x                                                 0x101618C
#define __HotkeyPage_x                                             0x10A043C
#define __HWnd_x                                                   0x10ACAC0
#define __InChatMode_x                                             0x102328C
#define __LastTell_x                                               0x1025138
#define __LMouseHeldTime_x                                         0x10233CC
#define __Mouse_x                                                  0x11B4BC4
#define __MouseLook_x                                              0x1023326
#define __MouseEventTime_x                                         0x10A7F8C
#define __gpbCommandEvent_x                                        0x1016254
#define __NetStatusToggle_x                                        0x1023329
#define __PCNames_x                                                0x1024758
#define __RangeAttackReady_x                                       0x1024494
#define __RMouseHeldTime_x                                         0x10233C8
#define __RunWalkState_x                                           0x1023290
#define __ScreenMode_x                                             0xF62488
#define __ScreenX_x                                                0x1023244
#define __ScreenY_x                                                0x1023240
#define __ScreenXMax_x                                             0x1023248
#define __ScreenYMax_x                                             0x102324C
#define __ServerHost_x                                             0x1013C1C
#define __ServerName_x                                             0x10599FC
#define __ShiftKeyDown_x                                           0x1023920
#define __ShowNames_x                                              0x1024654
#define __Socials_x                                                0x1059AFC
#define __SubscriptionType_x                                       0x11E876C
#define __TargetAggroHolder_x                                      0x11BC87C
#define __ZoneType_x                                               0x1023724
#define __GroupAggro_x                                             0x11BC8BC
#define __LoginName_x                                              0x10AB69C
#define __Inviter_x                                                0x10A7704
#define __AttackOnAssist_x                                         0x1024610
#define __UseTellWindows_x                                         0x10248F0

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x1016278
#define instEQZoneInfo_x                                           0x102351C
#define instKeypressHandler_x                                      0x10A7F70
#define pinstActiveBanker_x                                        0x1016230
#define pinstActiveCorpse_x                                        0x1016234
#define pinstActiveGMaster_x                                       0x1016238
#define pinstActiveMerchant_x                                      0x101622C
#define pinstAggroInfo_x                                           0xE1FEE8
#define pinstAltAdvManager_x                                       0xF63548
#define pinstAuraMgr_x                                             0xE30658
#define pinstBandageTarget_x                                       0x1016218
#define pinstCamActor_x                                            0xF62E9C
#define pinstCDBStr_x                                              0xF6241C
#define pinstCDisplay_x                                            0x1016240
#define pinstCEverQuest_x                                          0x11B4D38
#define pinstCharData_x                                            0x10161FC
#define pinstCharSpawn_x                                           0x1016224
#define pinstControlledMissile_x                                   0x10161F8
#define pinstControlledPlayer_x                                    0x1016224
#define pinstCSidlManager_x                                        0x1820A64
#define pinstCXWndManager_x                                        0x1820A5C
#define instDynamicZone_x                                          0x10230D8
#define pinstDZMember_x                                            0x10231E8
#define pinstDZTimerInfo_x                                         0x10231EC
#define pinstEQItemList_x                                          0x1012958
#define pinstEQObjectList_x                                        0x10136CC
#define instEQMisc_x                                               0xC13C40
#define pinstEQSoundManager_x                                      0xF63AA0
#define instExpeditionLeader_x                                     0x1023122
#define instExpeditionName_x                                       0x1023162
#define pinstGroup_x                                               0x1013CCE
#define pinstImeManager_x                                          0x1820A68
#define pinstLocalPlayer_x                                         0x1016210
#define pinstMercenaryData_x                                       0x10A85F0
#define pinstMercenaryStats_x                                      0x11BC9C8
#define pinstMercAltAbilities_x                                    0xF638D0
#define pinstModelPlayer_x                                         0x101623C
#define pinstPCData_x                                              0x10161FC
#define pinstSkillMgr_x                                            0x10A9458
#define pinstSpawnManager_x                                        0x10A8D40
#define pinstSpellManager_x                                        0x10A95A0
#define pinstSpellSets_x                                           0x10A04A0
#define pinstStringTable_x                                         0x10161A4
#define pinstSwitchManager_x                                       0x1013860
#define pinstTarget_x                                              0x1016228
#define pinstTargetObject_x                                        0x1016200
#define pinstTargetSwitch_x                                        0x1016204
#define pinstTaskMember_x                                          0xF62368
#define pinstTrackTarget_x                                         0x101621C
#define pinstTradeTarget_x                                         0x101620C
#define instTributeActive_x                                        0xC13C65
#define pinstViewActor_x                                           0xF62E98
#define pinstWorldData_x                                           0x10161E0
#define pinstZoneAddr_x                                            0x10237BC
#define pinstPlayerPath_x                                          0x10A8DA0
#define pinstTargetIndicator_x                                     0x10A9738
#define pinstCTargetManager_x                                      0x10A9798

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE203E0
#define pinstCAudioTriggersWindow_x                                0xE20270
#define pinstCCharacterSelect_x                                    0xF62D2C
#define pinstCFacePick_x                                           0xF62ADC
#define pinstCNoteWnd_x                                            0xF62CE4
#define pinstCBookWnd_x                                            0xF62CEC
#define pinstCPetInfoWnd_x                                         0xF62CF0
#define pinstCTrainWnd_x                                           0xF62CF4
#define pinstCSkillsWnd_x                                          0xF62CF8
#define pinstCSkillsSelectWnd_x                                    0xF62CFC
#define pinstCCombatSkillsSelectWnd_x                              0xF62D00
#define pinstCFriendsWnd_x                                         0xF62D04
#define pinstCAuraWnd_x                                            0xF62D08
#define pinstCRespawnWnd_x                                         0xF62D0C
#define pinstCBandolierWnd_x                                       0xF62D10
#define pinstCPotionBeltWnd_x                                      0xF62D14
#define pinstCAAWnd_x                                              0xF62D18
#define pinstCGroupSearchFiltersWnd_x                              0xF62D1C
#define pinstCLoadskinWnd_x                                        0xF62D20
#define pinstCAlarmWnd_x                                           0xF62D24
#define pinstCMusicPlayerWnd_x                                     0xF62D28
#define pinstCMailWnd_x                                            0xF62D30
#define pinstCMailCompositionWnd_x                                 0xF62D34
#define pinstCMailAddressBookWnd_x                                 0xF62D38
#define pinstCRaidWnd_x                                            0xF62D40
#define pinstCRaidOptionsWnd_x                                     0xF62D44
#define pinstCBreathWnd_x                                          0xF62D48
#define pinstCMapViewWnd_x                                         0xF62D4C
#define pinstCMapToolbarWnd_x                                      0xF62D50
#define pinstCEditLabelWnd_x                                       0xF62D54
#define pinstCTargetWnd_x                                          0xF62D58
#define pinstCColorPickerWnd_x                                     0xF62D5C
#define pinstCPlayerWnd_x                                          0xF62D60
#define pinstCOptionsWnd_x                                         0xF62D64
#define pinstCBuffWindowNORMAL_x                                   0xF62D68
#define pinstCBuffWindowSHORT_x                                    0xF62D6C
#define pinstCharacterCreation_x                                   0xF62D70
#define pinstCCursorAttachment_x                                   0xF62D74
#define pinstCCastingWnd_x                                         0xF62D78
#define pinstCCastSpellWnd_x                                       0xF62D7C
#define pinstCSpellBookWnd_x                                       0xF62D80
#define pinstCInventoryWnd_x                                       0xF62D84
#define pinstCBankWnd_x                                            0xF62D8C
#define pinstCQuantityWnd_x                                        0xF62D90
#define pinstCLootWnd_x                                            0xF62D94
#define pinstCActionsWnd_x                                         0xF62D98
#define pinstCCombatAbilityWnd_x                                   0xF62D9C
#define pinstCMerchantWnd_x                                        0xF62DA0
#define pinstCTradeWnd_x                                           0xF62DA4
#define pinstCSelectorWnd_x                                        0xF62DA8
#define pinstCBazaarWnd_x                                          0xF62DAC
#define pinstCBazaarSearchWnd_x                                    0xF62DB0
#define pinstCGiveWnd_x                                            0xF62DCC
#define pinstCTrackingWnd_x                                        0xF62DD4
#define pinstCInspectWnd_x                                         0xF62DD8
#define pinstCSocialEditWnd_x                                      0xF62DDC
#define pinstCFeedbackWnd_x                                        0xF62DE0
#define pinstCBugReportWnd_x                                       0xF62DE4
#define pinstCVideoModesWnd_x                                      0xF62DE8
#define pinstCTextEntryWnd_x                                       0xF62DF0
#define pinstCFileSelectionWnd_x                                   0xF62DF4
#define pinstCCompassWnd_x                                         0xF62DF8
#define pinstCPlayerNotesWnd_x                                     0xF62DFC
#define pinstCGemsGameWnd_x                                        0xF62E00
#define pinstCTimeLeftWnd_x                                        0xF62E04
#define pinstCPetitionQWnd_x                                       0xF62E20
#define pinstCSoulmarkWnd_x                                        0xF62E24
#define pinstCStoryWnd_x                                           0xF62E28
#define pinstCJournalTextWnd_x                                     0xF62E2C
#define pinstCJournalCatWnd_x                                      0xF62E30
#define pinstCBodyTintWnd_x                                        0xF62E34
#define pinstCServerListWnd_x                                      0xF62E38
#define pinstCAvaZoneWnd_x                                         0xF62E44
#define pinstCBlockedBuffWnd_x                                     0xF62E48
#define pinstCBlockedPetBuffWnd_x                                  0xF62E4C
#define pinstCInvSlotMgr_x                                         0xF62E90
#define pinstCContainerMgr_x                                       0xF62E94
#define pinstCAdventureLeaderboardWnd_x                            0x11B56E8
#define pinstCAdventureRequestWnd_x                                0x11B5760
#define pinstCAltStorageWnd_x                                      0x11B5A40
#define pinstCAdventureStatsWnd_x                                  0x11B57D8
#define pinstCBarterMerchantWnd_x                                  0x11B6628
#define pinstCBarterSearchWnd_x                                    0x11B66A0
#define pinstCBarterWnd_x                                          0x11B6718
#define pinstCChatManager_x                                        0x11B6DA8
#define pinstCDynamicZoneWnd_x                                     0x11B7258
#define pinstCEQMainWnd_x                                          0x11B73F0
#define pinstCFellowshipWnd_x                                      0x11B71EC
#define pinstCFindLocationWnd_x                                    0x11B76C0
#define pinstCGroupSearchWnd_x                                     0x11B7990
#define pinstCGroupWnd_x                                           0x11B7A08
#define pinstCGuildBankWnd_x                                       0x11B7A80
#define pinstCGuildMgmtWnd_x                                       0x11B9B70
#define pinstCHotButtonWnd_x                                       0x11B9C6C
#define pinstCHotButtonWnd1_x                                      0x11B9C6C
#define pinstCHotButtonWnd2_x                                      0x11B9C70
#define pinstCHotButtonWnd3_x                                      0x11B9C74
#define pinstCHotButtonWnd4_x                                      0x11B9C98
#define pinstCItemDisplayManager_x                                 0x11B9F90
#define pinstCItemExpTransferWnd_x                                 0x11BA00C
#define pinstCLFGuildWnd_x                                         0x11BA2E8
#define pinstCMIZoneSelectWnd_x                                    0x11BA8D0
#define pinstCConfirmationDialog_x                                 0x11BAFD8
#define pinstCPopupWndManager_x                                    0x11BAFD8
#define pinstCProgressionSelectionWnd_x                            0x11BB0C8
#define pinstCPvPStatsWnd_x                                        0x11BB1B8
#define pinstCSystemInfoDialogBox_x                                0x11BB8C0
#define pinstCTaskWnd_x                                            0x11BCC88
#define pinstCTaskSomething_x                                      0xE30F10
#define pinstCTaskTemplateSelectWnd_x                              0x11BCC10
#define pinstCTipWndOFDAY_x                                        0x11BCDF0
#define pinstCTipWndCONTEXT_x                                      0x11BCDF4
#define pinstCTitleWnd_x                                           0x11BCE70
#define pinstCContextMenuManager_x                                 0x18209D4
#define pinstCVoiceMacroWnd_x                                      0x10A9B70
#define pinstCHtmlWnd_x                                            0x10A9C60
#define pinstIconCache_x                                           0x11B73C4
#define pinstCTradeskillWnd_x                                      0x11BCF70
#define pinstCAdvancedLootWnd_x                                    0xF62E84
#define pinstRewardSelectionWnd_x                                  0x11BB6E0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x534830
#define __ConvertItemTags_x                                        0x522160
#define __ExecuteCmd_x                                             0x50CA50
#define __EQGetTime_x                                              0x896B90
#define __get_melee_range_x                                        0x513600
#define __GetGaugeValueFromEQ_x                                    0x7A47F0
#define __GetLabelFromEQ_x                                         0x7A5A40
#define __ToggleKeyRingItem_x                                      0x47F7F0
#define __GetXTargetType_x                                         0x92CE70
#define __LoadFrontEnd_x                                           0x633810
#define __NewUIINI_x                                               0x7A41C0
#define __ProcessGameEvents_x                                      0x577940
#define __ProcessMouseEvent_x                                      0x5770E0
#define CrashDetected_x                                            0x6351D0
#define wwsCrashReportCheckForUploader_x                           0x7F44E0
#define DrawNetStatus_x                                            0x5ADB70
#define Util__FastTime_x                                           0x8966A0
#define Expansion_HoT_x                                            0x1024600
#define __HelpPath_x                                               0x10A7CF8
#define __STMLToText_x                                             0x8E1D30

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420520
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B370
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B150

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C6860
#define AltAdvManager__IsAbilityReady_x                            0x4C68D0
#define AltAdvManager__GetAAById_x                                 0x4C6C90
#define AltAdvManager__CanTrainAbility_x                           0x4C7550
#define AltAdvManager__CanSeeAbility_x                             0x4C7150

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x462EE0
#define CharacterZoneClient__MakeMeVisible_x                       0x467980
#define CharacterZoneClient__IsStackBlocked_x                      0x447530
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4469F0
#define CharacterZoneClient__GetItemCountWorn_x                    0x460D20
#define CharacterZoneClient__GetItemCountInInventory_x             0x460E00
#define CharacterZoneClient__GetCursorItemCount_x                  0x460EE0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6635B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x671560

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58CFC0
#define CButtonWnd__CButtonWnd_x                                   0x8D6020

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68CA20
#define CChatManager__InitContextMenu_x                            0x68D5A0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E0090
#define CContextMenu__dCContextMenu_x                              0x8E02A0
#define CContextMenu__AddMenuItem_x                                0x8E02B0
#define CContextMenu__RemoveMenuItem_x                             0x8E05A0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E05C0
#define CContextMenuManager__AddMenu_x                             0x8CC5F0
#define CContextMenuManager__RemoveMenu_x                          0x8CC940
#define CContextMenuManager__PopupMenu_x                           0x8CCD90
#define CContextMenuManager__Flush_x                               0x8CC660
#define CContextMenuManager__GetMenu_x                             0x416990

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87B330
#define CChatService__GetFriendName_x                              0x87B340

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x692800
#define CChatWindow__Clear_x                                       0x6923D0
#define CChatWindow__WndNotification_x                             0x692D40

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D0410
#define CComboWnd__Draw_x                                          0x8D0620
#define CComboWnd__GetCurChoice_x                                  0x8D01C0
#define CComboWnd__GetListRect_x                                   0x8D08C0
#define CComboWnd__GetTextRect_x                                   0x8D0480
#define CComboWnd__InsertChoice_x                                  0x8D0930
#define CComboWnd__SetColors_x                                     0x8D0150
#define CComboWnd__SetChoice_x                                     0x8D0180
#define CComboWnd__GetItemCount_x                                  0x8D01B0
#define CComboWnd__GetCurChoiceText_x                              0x8D0200

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69BED0
#define CContainerWnd__vftable_x                                   0xADECE8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B4C30
#define CDisplay__GetClickedActor_x                                0x4AD4F0
#define CDisplay__GetUserDefinedColor_x                            0x4AC0D0
#define CDisplay__GetWorldFilePath_x                               0x4AB520
#define CDisplay__is3dON_x                                         0x4AA9B0
#define CDisplay__ReloadUI_x                                       0x4C0140
#define CDisplay__WriteTextHD2_x                                   0x4B0F80

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F6710

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E45C0
#define CEditWnd__GetCharIndexPt_x                                 0x8E5650
#define CEditWnd__GetDisplayString_x                               0x8E4770
#define CEditWnd__GetHorzOffset_x                                  0x8E4AB0
#define CEditWnd__GetLineForPrintableChar_x                        0x8E5120
#define CEditWnd__GetSelStartPt_x                                  0x8E5900
#define CEditWnd__GetSTMLSafeText_x                                0x8E4C50
#define CEditWnd__PointFromPrintableChar_x                         0x8E5210
#define CEditWnd__SelectableCharFromPoint_x                        0x8E5390
#define CEditWnd__SetEditable_x                                    0x8E4C20

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x558750
#define CEverQuest__CreateTargetIndicator_x                        0x559640
#define CEverQuest__DeleteTargetIndicator_x                        0x5596C0
#define CEverQuest__DoTellWindow_x                                 0x4725B0
#define CEverQuest__DropHeldItemOnGround_x                         0x56F7F0
#define CEverQuest__dsp_chat_x                                     0x4728F0
#define CEverQuest__trimName_x                                     0x5550A0
#define CEverQuest__Emote_x                                        0x56DB40
#define CEverQuest__EnterZone_x                                    0x568B40
#define CEverQuest__GetBodyTypeDesc_x                              0x552B00
#define CEverQuest__GetClassDesc_x                                 0x55C3D0
#define CEverQuest__GetClassThreeLetterCode_x                      0x55C9D0
#define CEverQuest__GetDeityDesc_x                                 0x5533E0
#define CEverQuest__GetLangDesc_x                                  0x552E90
#define CEverQuest__GetRaceDesc_x                                  0x55CB90
#define CEverQuest__InterpretCmd_x                                 0x5609A0
#define CEverQuest__LeftClickedOnPlayer_x                          0x574030
#define CEverQuest__LMouseUp_x                                     0x576130
#define CEverQuest__RightClickedOnPlayer_x                         0x574B40
#define CEverQuest__RMouseUp_x                                     0x575B90
#define CEverQuest__SetGameState_x                                 0x559010
#define CEverQuest__UPCNotificationFlush_x                         0x550920
#define CEverQuest__IssuePetCommand_x                              0x561380

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6ACC90
#define CGaugeWnd__CalcLinesFillRect_x                             0x6ACCF0
#define CGaugeWnd__Draw_x                                          0x6AD120

// CGuild
#define CGuild__FindMemberByName_x                                 0x437330

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C90E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D6250
#define CInvSlotMgr__MoveItem_x                                    0x6D7100
#define CInvSlotMgr__SelectSlot_x                                  0x6D6300

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D5700
#define CInvSlot__SliderComplete_x                                 0x6D2F10
#define CInvSlot__GetItemBase_x                                    0x6D23B0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D8520

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A01F0
#define CItemDisplayWnd__UpdateStrings_x                           0x6DA660

// CLabel 
#define CLabel__Draw_x                                             0x6F3C30

// CListWnd
#define CListWnd__CListWnd_x                                       0x8BC210
#define CListWnd__dCListWnd_x                                      0x8BD250
#define CListWnd__AddColumn_x                                      0x8BD1F0
#define CListWnd__AddColumn1_x                                     0x8BCA60
#define CListWnd__AddLine_x                                        0x8BC4C0
#define CListWnd__AddString_x                                      0x8BC6E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B94E0
#define CListWnd__CalculateVSBRange_x                              0x8BB6E0
#define CListWnd__ClearSel_x                                       0x8B87F0
#define CListWnd__ClearAllSel_x                                    0x8B87A0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8BC0A0
#define CListWnd__Compare_x                                        0x8BA050
#define CListWnd__Draw_x                                           0x8BB2E0
#define CListWnd__DrawColumnSeparators_x                           0x8BB170
#define CListWnd__DrawHeader_x                                     0x8B8AB0
#define CListWnd__DrawItem_x                                       0x8BA6A0
#define CListWnd__DrawLine_x                                       0x8BAE10
#define CListWnd__DrawSeparator_x                                  0x8BB210
#define CListWnd__EnsureVisible_x                                  0x8B9640
#define CListWnd__ExtendSel_x                                      0x8BA5B0
#define CListWnd__GetColumnMinWidth_x                              0x8B81A0
#define CListWnd__GetColumnWidth_x                                 0x8B80D0
#define CListWnd__GetCurSel_x                                      0x8B7890
#define CListWnd__GetItemAtPoint_x                                 0x8B98D0
#define CListWnd__GetItemAtPoint1_x                                0x8B9940
#define CListWnd__GetItemData_x                                    0x8B7BE0
#define CListWnd__GetItemHeight_x                                  0x8B9130
#define CListWnd__GetItemIcon_x                                    0x8B7DD0
#define CListWnd__GetItemRect_x                                    0x8B9710
#define CListWnd__GetItemText_x                                    0x8B7C80
#define CListWnd__GetSelList_x                                     0x8BC950
#define CListWnd__GetSeparatorRect_x                               0x8B9F70
#define CListWnd__RemoveLine_x                                     0x8BC8D0
#define CListWnd__SetColors_x                                      0x8B79E0
#define CListWnd__SetColumnJustification_x                         0x8B8430
#define CListWnd__SetColumnWidth_x                                 0x8B8150
#define CListWnd__SetCurSel_x                                      0x8B78D0
#define CListWnd__SetItemColor_x                                   0x8BBD90
#define CListWnd__SetItemData_x                                    0x8B8850
#define CListWnd__SetItemText_x                                    0x8BBBD0
#define CListWnd__ShiftColumnSeparator_x                           0x8BBA60
#define CListWnd__Sort_x                                           0x8BD350
#define CListWnd__ToggleSel_x                                      0x8B8720

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70CD80

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72E120
#define CMerchantWnd__RequestBuyItem_x                             0x7351C0
#define CMerchantWnd__RequestSellItem_x                            0x735C80
#define CMerchantWnd__SelectRecoverySlot_x                         0x72E3D0
#define CMerchantWnd__SelectBuySellSlot_x                          0x72D5D0
#define CMerchantWnd__ActualSelect_x                               0x7320A0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x847DB0
#define CPacketScrambler__hton_x                                   0x847DC0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8DB050
#define CSidlManager__CreateLabel_x                                0x796050

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65A950
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65A880
#define CSidlScreenWnd__ConvertToRes_x                             0x8F65F0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D2DC0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D3F70
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D4020
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D34F0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D2770
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D1ED0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D2960
#define CSidlScreenWnd__Init1_x                                    0x8D3C50
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D2E70
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D2090
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D3730
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D1B30
#define CSidlScreenWnd__StoreIniVis_x                              0x8D1E80
#define CSidlScreenWnd__WndNotification_x                          0x8D39D0
#define CSidlScreenWnd__GetChildItem_x                             0x8D1FA0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C5830
#define CSidlScreenWnd__m_layoutCopy_x                             0x1820A38

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F9290
#define CSkillMgr__GetSkillCap_x                                   0x5F9470
#define CSkillMgr__GetNameToken_x                                  0x5F8EB0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F58C0
#define CSliderWnd__SetValue_x                                     0x8F5A90
#define CSliderWnd__SetNumTicks_x                                  0x8F6210

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79DE50

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F1270
#define CStmlWnd__CalculateHSBRange_x                              0x8E97D0
#define CStmlWnd__CalculateVSBRange_x                              0x8E9860
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E99E0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EA2C0
#define CStmlWnd__ForceParseNow_x                                  0x8F1BC0
#define CStmlWnd__GetNextTagPiece_x                                0x8EA1C0
#define CStmlWnd__GetSTMLText_x                                    0x691C70
#define CStmlWnd__GetVisibleText_x                                 0x8EAD10
#define CStmlWnd__InitializeWindowVariables_x                      0x8ED090
#define CStmlWnd__MakeStmlColorTag_x                               0x8E8AD0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E8B30
#define CStmlWnd__SetSTMLText_x                                    0x8EE8E0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F0F10
#define CStmlWnd__UpdateHistoryString_x                            0x8EBC50

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E8170
#define CTabWnd__DrawCurrentPage_x                                 0x8E7A00
#define CTabWnd__DrawTab_x                                         0x8E77C0
#define CTabWnd__GetCurrentPage_x                                  0x8E7DB0
#define CTabWnd__GetPageInnerRect_x                                0x8E74B0
#define CTabWnd__GetTabInnerRect_x                                 0x8E76B0
#define CTabWnd__GetTabRect_x                                      0x8E7580
#define CTabWnd__InsertPage_x                                      0x8E8460
#define CTabWnd__SetPage_x                                         0x8E7DE0
#define CTabWnd__SetPageRect_x                                     0x8E80B0
#define CTabWnd__UpdatePage_x                                      0x8E8400

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432E70

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CFDC0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6319B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8FBA20

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B5AE0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59A520
#define CXStr__CXStr1_x                                            0x8B6AB0
#define CXStr__CXStr3_x                                            0x8938F0
#define CXStr__dCXStr_x                                            0x4029B0
#define CXStr__operator_equal_x                                    0x893A60
#define CXStr__operator_equal1_x                                   0x893AB0
#define CXStr__operator_plus_equal1_x                              0x894BB0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C4A30
#define CXWnd__Center_x                                            0x8CABF0
#define CXWnd__ClrFocus_x                                          0x8C4610
#define CXWnd__DoAllDrawing_x                                      0x8CA840
#define CXWnd__DrawChildren_x                                      0x8CA9E0
#define CXWnd__DrawColoredRect_x                                   0x8C4DF0
#define CXWnd__DrawTooltip_x                                       0x8C5090
#define CXWnd__DrawTooltipAtPoint_x                                0x8C97A0
#define CXWnd__GetBorderFrame_x                                    0x8C5500
#define CXWnd__GetChildWndAt_x                                     0x8CB5B0
#define CXWnd__GetClientClipRect_x                                 0x8C52B0
#define CXWnd__GetScreenClipRect_x                                 0x8C9EA0
#define CXWnd__GetScreenRect_x                                     0x8C56D0
#define CXWnd__GetTooltipRect_x                                    0x8C4F20
#define CXWnd__GetWindowTextA_x                                    0x4244D0
#define CXWnd__IsActive_x                                          0x8C0040
#define CXWnd__IsDescendantOf_x                                    0x8C5440
#define CXWnd__IsReallyVisible_x                                   0x8C87D0
#define CXWnd__IsType_x                                            0x8F8240
#define CXWnd__Move_x                                              0x8C7F30
#define CXWnd__Move1_x                                             0x8CA500
#define CXWnd__ProcessTransition_x                                 0x8C49D0
#define CXWnd__Refade_x                                            0x8C47B0
#define CXWnd__Resize_x                                            0x8C5790
#define CXWnd__Right_x                                             0x8C9CA0
#define CXWnd__SetFocus_x                                          0x8C7090
#define CXWnd__SetFont_x                                           0x8C4660
#define CXWnd__SetKeyTooltip_x                                     0x8C5A00
#define CXWnd__SetMouseOver_x                                      0x8CA1F0
#define CXWnd__StartFade_x                                         0x8C4A80
#define CXWnd__GetChildItem_x                                      0x8CA130

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C18B0
#define CXWndManager__DrawWindows_x                                0x8C14F0
#define CXWndManager__GetKeyboardFlags_x                           0x8BFB70
#define CXWndManager__HandleKeyboardMsg_x                          0x8C04D0
#define CXWndManager__RemoveWnd_x                                  0x8C01D0

// CDBStr
#define CDBStr__GetString_x                                        0x4A8ED0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44DAC0
#define EQ_Character__Cur_HP_x                                     0x462580
#define EQ_Character__Cur_Mana_x                                   0x4560B0
#define EQ_Character__GetAACastingTimeModifier_x                   0x446D00
#define EQ_Character__GetCharInfo2_x                               0x867600
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F000
#define EQ_Character__GetFocusRangeModifier_x                      0x43F060
#define EQ_Character__Max_Endurance_x                              0x5BF990
#define EQ_Character__Max_HP_x                                     0x458CD0
#define EQ_Character__Max_Mana_x                                   0x5BF7C0
#define EQ_Character__doCombatAbility_x                            0x5BCEB0
#define EQ_Character__UseSkill_x                                   0x46C9F0
#define EQ_Character__GetConLevel_x                                0x5B21D0
#define EQ_Character__IsExpansionFlag_x                            0x423A10
#define EQ_Character__TotalEffect_x                                0x44AD50
#define EQ_Character__GetPCSpellAffect_x                           0x447100
#define EQ_Character__SpellDuration_x                              0x445000
#define EQ_Character__FindItemByRecord_x                           0x45F9F0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x442350
#define CCharacterSelect__EnterWorld_x                             0x441B20
#define CCharacterSelect__Quit_x                                   0x440700

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x592850
#define EQ_Item__CreateItemTagString_x                             0x8467B0
#define EQ_Item__IsStackable_x                                     0x83C1C0
#define EQ_Item__GetImageNum_x                                     0x83EC40
#define EQ_Item__CreateItemClient_x                                0x593420
#define EQ_Item__GetItemValue_x                                    0x8454A0
#define EQ_Item__ValueSellMerchant_x                               0x847A40
#define EQ_Item__IsKeyRingItem_x                                   0x83CC00
#define EQ_Item__CanGoInBag_x                                      0x5929E0
#define EQ_Item__GetMaxItemCount_x                                 0x83BE40
#define EQ_Item__GetHeldItem_x                                     0x83DA40

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C89B0
#define EQ_LoadingS__Array_x                                       0xC204C0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C1EB0
#define EQ_PC__GetAlternateAbilityId_x                             0x84FD40
#define EQ_PC__GetCombatAbility_x                                  0x84FDD0
#define EQ_PC__GetCombatAbilityTimer_x                             0x84ABC0
#define EQ_PC__GetItemTimerValue_x                                 0x5BB570
#define EQ_PC__HasLoreItem_x                                       0x5B56D0
#define EQ_PC__AlertInventoryChanged_x                             0x5B21A0
#define EQ_PC__GetPcZoneClient_x                                   0x5DC500
#define EQ_PC__RemoveMyAffect_x                                    0x5BAA10
#define EQ_PC__GetKeyRingItems_x                                   0x84AFE0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5116B0
#define EQItemList__add_object_x                                   0x53D470
#define EQItemList__add_item_x                                     0x5115F0
#define EQItemList__delete_item_x                                  0x511AA0
#define EQItemList__FreeItemList_x                                 0x5119A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A81E0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C7510
#define EQPlayer__dEQPlayer_x                                      0x5D03D0
#define EQPlayer__DoAttack_x                                       0x5E23C0
#define EQPlayer__EQPlayer_x                                       0x5D27F0
#define EQPlayer__SetNameSpriteState_x                             0x5CD320
#define EQPlayer__SetNameSpriteTint_x                              0x5C8920
#define PlayerBase__HasProperty_j_x                                0x9290B0
#define EQPlayer__IsTargetable_x                                   0x9299B0
#define EQPlayer__CanSee_x                                         0x929ED0
#define PlayerZoneClient__ChangeHeight_x                           0x5E2280
#define EQPlayer__CanSeeTargetIndicator_x                          0x929FC0
#define PlayerBase__GetVisibilityLineSegment_x                     0x929C60

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D6B40
#define EQPlayerManager__GetSpawnByName_x                          0x5D6FA0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D6B70

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5988B0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5988F0
#define KeypressHandler__ClearCommandStateArray_x                  0x5984A0
#define KeypressHandler__HandleKeyDown_x                           0x596E00
#define KeypressHandler__HandleKeyUp_x                             0x597120
#define KeypressHandler__SaveKeymapping_x                          0x598570

// MapViewMap 
#define MapViewMap__Clear_x                                        0x705710
#define MapViewMap__SaveEx_x                                       0x708A40

#define PlayerPointManager__GetAltCurrency_x                       0x8624A0

// StringTable 
#define StringTable__getString_x                                   0x85D0F0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BF420
#define PcZoneClient__RemovePetEffect_x                            0x5BBA40
#define PcZoneClient__HasAlternateAbility_x                        0x5BC3E0
#define PcZoneClient__GetCurrentMod_x                              0x458070
#define PcZoneClient__GetModCap_x                                  0x455830
#define PcZoneClient__CanEquipItem_x                               0x5BC990

//Doors
#define EQSwitch__UseSwitch_x                                      0x54F240

//IconCache
#define IconCache__GetIcon_x                                       0x6A2490

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x699250
#define CContainerMgr__CloseContainer_x                            0x699A70

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x765FC0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58BA40

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E0880
#define EQ_Spell__SpellAffects_x                                   0x4DDF30
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DDFA0
#define CharacterZoneClient__CalcAffectChange_x                    0x446130
#define CLootWnd__LootAll_x                                        0x6FB000
#define CLootWnd__RequestLootSlot_x                                0x6FB810

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7ACCB0
#define CTargetWnd__WndNotification_x                              0x7AC7A0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7ACE90

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B1EB0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D9810

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x498110

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E3BF0
#define CSidlManager__FindAnimation1_x                             0x8D8F30

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D00D0
#define CAltAbilityData__GetMercMaxRank_x                          0x4D0080
#define CAltAbilityData__GetMaxRank_x                              0x4C4F10

//CTargetRing
#define CTargetRing__Cast_x                                        0x589310

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4549A0
#define CharacterBase__CreateItemGlobalIndex_x                     0x4717C0
#define CharacterBase__CreateItemIndex_x                           0x50AB40
#define CharacterBase__GetItemPossession_x                         0x50BF80
#define CharacterBase__GetItemByGlobalIndex_x                      0x875440

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x683B80
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6832E0

//messages
#define msg_spell_worn_off_x                                       0x4E8340
#define msg_new_text_x                                             0x4F17A0
#define msgTokenTextParam_x                                        0x4EE180

//SpellManager
#define SpellManager__vftable_x                                    0xABAFB0
#define SpellManager__SpellManager_x                               0x47A590
#define Spellmanager__CheckSpellRequirementAssociations_x          0x6000F0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x92D990

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E4900
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43A6C0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x4449C0
#define ItemGlobalIndex__IsValidIndex_x                            0x454200

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x873260
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8721A0
