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
#define __ExpectedVersionDate                                     "Oct 17 2016"
#define __ExpectedVersionTime                                     "19:23:45"
#define __ActualVersionDate_x                                      0xAD52C0
#define __ActualVersionTime_x                                      0xAD52CC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59DD00
#define __MemChecker1_x                                            0x894AB0
#define __MemChecker2_x                                            0x633E70
#define __MemChecker3_x                                            0x633DC0
#define __MemChecker4_x                                            0x7E5740
#define __EncryptPad0_x                                            0xC779F0
#define __EncryptPad1_x                                            0xE038D0
#define __EncryptPad2_x                                            0xCC0688
#define __EncryptPad3_x                                            0xCC0288
#define __EncryptPad4_x                                            0xDD98A0
#define __EncryptPad5_x                                            0x11B4BC0
#define __AC1_x                                                    0x7A5795
#define __AC2_x                                                    0x557CA7
#define __AC3_x                                                    0x555E40
#define __AC4_x                                                    0x568650
#define __AC5_x                                                    0x57B1CB
#define __AC6_x                                                    0x57ED7E
#define __AC7_x                                                    0x57586C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1ED21C

// Direct Input
#define DI8__Main_x                                                0x11B4B98
#define DI8__Keyboard_x                                            0x11B4B9C
#define DI8__Mouse_x                                               0x11B4BA0
#define DI8__Mouse_Copy_x                                          0x1023284
#define DI8__Mouse_Check_x                                         0x10ACA84
#define __Attack_x                                                 0x10A7767
#define __Autofire_x                                               0x10A7768
#define __BindList_x                                               0xC394A8
#define g_eqCommandStates_x                                        0x10126E8
#define __Clicks_x                                                 0x1023340
#define __CommandList_x                                            0xC3D890
#define __CurrentMapLabel_x                                        0x11BA620
#define __CurrentSocial_x                                          0xBED0B8
#define __DoAbilityList_x                                          0x1059A1C
#define __do_loot_x                                                0x51D2C0
#define __DrawHandler_x                                            0x1821534
#define __GroupCount_x                                             0x1013CB2

#define __Guilds_x                                                 0x10198C8
#define __gWorld_x                                                 0x101616C
#define __HotkeyPage_x                                             0x10A041C
#define __HWnd_x                                                   0x10ACAA0
#define __InChatMode_x                                             0x102326C
#define __LastTell_x                                               0x1025118
#define __LMouseHeldTime_x                                         0x10233AC
#define __Mouse_x                                                  0x11B4BA4
#define __MouseLook_x                                              0x1023306
#define __MouseEventTime_x                                         0x10A7F6C
#define __gpbCommandEvent_x                                        0x1016234
#define __NetStatusToggle_x                                        0x1023309
#define __PCNames_x                                                0x1024738
#define __RangeAttackReady_x                                       0x1024474
#define __RMouseHeldTime_x                                         0x10233A8
#define __RunWalkState_x                                           0x1023270
#define __ScreenMode_x                                             0xF62468
#define __ScreenX_x                                                0x1023224
#define __ScreenY_x                                                0x1023220
#define __ScreenXMax_x                                             0x1023228
#define __ScreenYMax_x                                             0x102322C
#define __ServerHost_x                                             0x1013BFC
#define __ServerName_x                                             0x10599DC
#define __ShiftKeyDown_x                                           0x1023900
#define __ShowNames_x                                              0x1024634
#define __Socials_x                                                0x1059ADC
#define __SubscriptionType_x                                       0x11E862C
#define __TargetAggroHolder_x                                      0x11BC85C
#define __ZoneType_x                                               0x1023704
#define __GroupAggro_x                                             0x11BC89C
#define __LoginName_x                                              0x10AB67C
#define __Inviter_x                                                0x10A76E4
#define __AttackOnAssist_x                                         0x10245F0
#define __UseTellWindows_x                                         0x10248D0

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x1016258
#define instEQZoneInfo_x                                           0x10234FC
#define instKeypressHandler_x                                      0x10A7F50
#define pinstActiveBanker_x                                        0x1016210
#define pinstActiveCorpse_x                                        0x1016214
#define pinstActiveGMaster_x                                       0x1016218
#define pinstActiveMerchant_x                                      0x101620C
#define pinstAggroInfo_x                                           0xE1FEC8
#define pinstAltAdvManager_x                                       0xF63528
#define pinstAuraMgr_x                                             0xE30638
#define pinstBandageTarget_x                                       0x10161F8
#define pinstCamActor_x                                            0xF62E7C
#define pinstCDBStr_x                                              0xF623FC
#define pinstCDisplay_x                                            0x1016220
#define pinstCEverQuest_x                                          0x11B4D18
#define pinstCharData_x                                            0x10161DC
#define pinstCharSpawn_x                                           0x1016204
#define pinstControlledMissile_x                                   0x10161D8
#define pinstControlledPlayer_x                                    0x1016204
#define pinstCSidlManager_x                                        0x1820924
#define pinstCXWndManager_x                                        0x182091C
#define instDynamicZone_x                                          0x10230B8
#define pinstDZMember_x                                            0x10231C8
#define pinstDZTimerInfo_x                                         0x10231CC
#define pinstEQItemList_x                                          0x1012938
#define pinstEQObjectList_x                                        0x10136AC
#define instEQMisc_x                                               0xC13C40
#define pinstEQSoundManager_x                                      0xF63A80
#define instExpeditionLeader_x                                     0x1023102
#define instExpeditionName_x                                       0x1023142
#define pinstGroup_x                                               0x1013CAE
#define pinstImeManager_x                                          0x1820928
#define pinstLocalPlayer_x                                         0x10161F0
#define pinstMercenaryData_x                                       0x10A85D0
#define pinstMercenaryStats_x                                      0x11BC9A8
#define pinstMercAltAbilities_x                                    0xF638B0
#define pinstModelPlayer_x                                         0x101621C
#define pinstPCData_x                                              0x10161DC
#define pinstSkillMgr_x                                            0x10A9438
#define pinstSpawnManager_x                                        0x10A8D20
#define pinstSpellManager_x                                        0x10A9580
#define pinstSpellSets_x                                           0x10A0480
#define pinstStringTable_x                                         0x1016184
#define pinstSwitchManager_x                                       0x1013840
#define pinstTarget_x                                              0x1016208
#define pinstTargetObject_x                                        0x10161E0
#define pinstTargetSwitch_x                                        0x10161E4
#define pinstTaskMember_x                                          0xF62348
#define pinstTrackTarget_x                                         0x10161FC
#define pinstTradeTarget_x                                         0x10161EC
#define instTributeActive_x                                        0xC13C65
#define pinstViewActor_x                                           0xF62E78
#define pinstWorldData_x                                           0x10161C0
#define pinstZoneAddr_x                                            0x102379C
#define pinstPlayerPath_x                                          0x10A8D80
#define pinstTargetIndicator_x                                     0x10A9718
#define pinstCTargetManager_x                                      0x10A9778

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE203C0
#define pinstCAudioTriggersWindow_x                                0xE20250
#define pinstCCharacterSelect_x                                    0xF62D0C
#define pinstCFacePick_x                                           0xF62ABC
#define pinstCNoteWnd_x                                            0xF62CC4
#define pinstCBookWnd_x                                            0xF62CCC
#define pinstCPetInfoWnd_x                                         0xF62CD0
#define pinstCTrainWnd_x                                           0xF62CD4
#define pinstCSkillsWnd_x                                          0xF62CD8
#define pinstCSkillsSelectWnd_x                                    0xF62CDC
#define pinstCCombatSkillsSelectWnd_x                              0xF62CE0
#define pinstCFriendsWnd_x                                         0xF62CE4
#define pinstCAuraWnd_x                                            0xF62CE8
#define pinstCRespawnWnd_x                                         0xF62CEC
#define pinstCBandolierWnd_x                                       0xF62CF0
#define pinstCPotionBeltWnd_x                                      0xF62CF4
#define pinstCAAWnd_x                                              0xF62CF8
#define pinstCAlarmWnd_x                                           0xF62D04
#define pinstCGroupSearchFiltersWnd_x                              0xF62CFC
#define pinstCLoadskinWnd_x                                        0xF62D00
#define pinstCLargeDialogWnd_x                                     0x11BB8A0
#define pinstCMusicPlayerWnd_x                                     0xF62D08
#define pinstCMailWnd_x                                            0xF62D10
#define pinstCMailCompositionWnd_x                                 0xF62D14
#define pinstCMailAddressBookWnd_x                                 0xF62D18
#define pinstCRaidWnd_x                                            0xF62D20
#define pinstCRaidOptionsWnd_x                                     0xF62D24
#define pinstCBreathWnd_x                                          0xF62D28
#define pinstCMapViewWnd_x                                         0xF62D2C
#define pinstCMapToolbarWnd_x                                      0xF62D30
#define pinstCEditLabelWnd_x                                       0xF62D34
#define pinstCTargetWnd_x                                          0xF62D38
#define pinstCColorPickerWnd_x                                     0xF62D3C
#define pinstCPlayerWnd_x                                          0xF62D40
#define pinstCOptionsWnd_x                                         0xF62D44
#define pinstCBuffWindowNORMAL_x                                   0xF62D48
#define pinstCBuffWindowSHORT_x                                    0xF62D4C
#define pinstCharacterCreation_x                                   0xF62D50
#define pinstCCursorAttachment_x                                   0xF62D54
#define pinstCCastingWnd_x                                         0xF62D58
#define pinstCCastSpellWnd_x                                       0xF62D5C
#define pinstCSpellBookWnd_x                                       0xF62D60
#define pinstCInventoryWnd_x                                       0xF62D64
#define pinstCBankWnd_x                                            0xF62D6C
#define pinstCQuantityWnd_x                                        0xF62D70
#define pinstCLootWnd_x                                            0xF62D74
#define pinstCActionsWnd_x                                         0xF62D78
#define pinstCCombatAbilityWnd_x                                   0xF62D7C
#define pinstCMerchantWnd_x                                        0xF62D80
#define pinstCTradeWnd_x                                           0xF62D84
#define pinstCSelectorWnd_x                                        0xF62D88
#define pinstCBazaarWnd_x                                          0xF62D8C
#define pinstCBazaarSearchWnd_x                                    0xF62D90
#define pinstCGiveWnd_x                                            0xF62DAC
#define pinstCTrackingWnd_x                                        0xF62DB4
#define pinstCInspectWnd_x                                         0xF62DB8
#define pinstCSocialEditWnd_x                                      0xF62DBC
#define pinstCFeedbackWnd_x                                        0xF62DC0
#define pinstCBugReportWnd_x                                       0xF62DC4
#define pinstCVideoModesWnd_x                                      0xF62DC8
#define pinstCTextEntryWnd_x                                       0xF62DD0
#define pinstCFileSelectionWnd_x                                   0xF62DD4
#define pinstCCompassWnd_x                                         0xF62DD8
#define pinstCPlayerNotesWnd_x                                     0xF62DDC
#define pinstCGemsGameWnd_x                                        0xF62DE0
#define pinstCTimeLeftWnd_x                                        0xF62DE4
#define pinstCPetitionQWnd_x                                       0xF62E00
#define pinstCSoulmarkWnd_x                                        0xF62E04
#define pinstCStoryWnd_x                                           0xF62E08
#define pinstCJournalTextWnd_x                                     0xF62E0C
#define pinstCJournalCatWnd_x                                      0xF62E10
#define pinstCBodyTintWnd_x                                        0xF62E14
#define pinstCServerListWnd_x                                      0xF62E18
#define pinstCAvaZoneWnd_x                                         0xF62E24
#define pinstCBlockedBuffWnd_x                                     0xF62E28
#define pinstCBlockedPetBuffWnd_x                                  0xF62E2C
#define pinstCInvSlotMgr_x                                         0xF62E70
#define pinstCContainerMgr_x                                       0xF62E74
#define pinstCAdventureLeaderboardWnd_x                            0x11B56C8
#define pinstCAdventureRequestWnd_x                                0x11B5740
#define pinstCAltStorageWnd_x                                      0x11B5A20
#define pinstCAdventureStatsWnd_x                                  0x11B57B8
#define pinstCBarterMerchantWnd_x                                  0x11B6608
#define pinstCBarterSearchWnd_x                                    0x11B6680
#define pinstCBarterWnd_x                                          0x11B66F8
#define pinstCChatManager_x                                        0x11B6D88
#define pinstCDynamicZoneWnd_x                                     0x11B7238
#define pinstCEQMainWnd_x                                          0x11B73D0
#define pinstCFellowshipWnd_x                                      0x11B71CC
#define pinstCFindLocationWnd_x                                    0x11B76A0
#define pinstCGroupSearchWnd_x                                     0x11B7970
#define pinstCGroupWnd_x                                           0x11B79E8
#define pinstCGuildBankWnd_x                                       0x11B7A60
#define pinstCGuildMgmtWnd_x                                       0x11B9B50
#define pinstCHotButtonWnd_x                                       0x11B9C4C
#define pinstCHotButtonWnd1_x                                      0x11B9C4C
#define pinstCHotButtonWnd2_x                                      0x11B9C50
#define pinstCHotButtonWnd3_x                                      0x11B9C54
#define pinstCHotButtonWnd4_x                                      0x11B9C78
#define pinstCItemDisplayManager_x                                 0x11B9F70
#define pinstCItemExpTransferWnd_x                                 0x11B9FEC
#define pinstCLFGuildWnd_x                                         0x11BA2C8
#define pinstCMIZoneSelectWnd_x                                    0x11BA8B0
#define pinstCConfirmationDialog_x                                 0x11BAFB8
#define pinstCPopupWndManager_x                                    0x11BAFB8
#define pinstCProgressionSelectionWnd_x                            0x11BB0A8
#define pinstCPvPStatsWnd_x                                        0x11BB198
#define pinstCTaskWnd_x                                            0x11BCC68
#define pinstCTaskSomething_x                                      0xE30EF0
#define pinstCTaskTemplateSelectWnd_x                              0x11BCBF0
#define pinstCTipWndOFDAY_x                                        0x11BCDD0
#define pinstCTipWndCONTEXT_x                                      0x11BCDD4
#define pinstCTitleWnd_x                                           0x11BCE50
#define pinstCContextMenuManager_x                                 0x1820894
#define pinstCVoiceMacroWnd_x                                      0x10A9B50
#define pinstCHtmlWnd_x                                            0x10A9C40
#define pinstIconCache_x                                           0x11B73A4
#define pinstCTradeskillWnd_x                                      0x11BCF50
#define pinstCAdvancedLootWnd_x                                    0xF62E64
#define pinstRewardSelectionWnd_x                                  0x11BB6C0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x534500
#define __ConvertItemTags_x                                        0x521E20
#define __ExecuteCmd_x                                             0x50C6E0
#define __EQGetTime_x                                              0x894740
#define __get_melee_range_x                                        0x5132C0
#define __GetGaugeValueFromEQ_x                                    0x7A44D0
#define __GetLabelFromEQ_x                                         0x7A5720
#define __ToggleKeyRingItem_x                                      0x47F9E0
#define __GetXTargetType_x                                         0x92ABF0
#define __LoadFrontEnd_x                                           0x633540
#define __NewUIINI_x                                               0x7A3EA0
#define __ProcessGameEvents_x                                      0x5775D0
#define __ProcessMouseEvent_x                                      0x576D70
#define CrashDetected_x                                            0x634F00
#define wwsCrashReportCheckForUploader_x                           0x7F18E0
#define DrawNetStatus_x                                            0x5AD9A0
#define Util__FastTime_x                                           0x8942B0
#define Expansion_HoT_x                                            0x10245E0
#define __HelpPath_x                                               0x10A7CD8
#define __STMLToText_x                                             0x8DFA70

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420420
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B1C0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41AFA0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C67D0
#define AltAdvManager__IsAbilityReady_x                            0x4C6840
#define AltAdvManager__GetAAById_x                                 0x4C6C00
#define AltAdvManager__CanTrainAbility_x                           0x4C7500
#define AltAdvManager__CanSeeAbility_x                             0x4C70C0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463070
#define CharacterZoneClient__MakeMeVisible_x                       0x467B20
#define CharacterZoneClient__IsStackBlocked_x                      0x4475E0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x446AA0
#define CharacterZoneClient__GetItemCountWorn_x                    0x460EB0
#define CharacterZoneClient__GetItemCountInInventory_x             0x460F90
#define CharacterZoneClient__GetCursorItemCount_x                  0x461070

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6630B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6712F0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58CC50
#define CButtonWnd__CButtonWnd_x                                   0x8D3C90

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68C440
#define CChatManager__InitContextMenu_x                            0x68CFC0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DDDD0
#define CContextMenu__dCContextMenu_x                              0x8DDFE0
#define CContextMenu__AddMenuItem_x                                0x8DDFF0
#define CContextMenu__RemoveMenuItem_x                             0x8DE2E0
#define CContextMenu__RemoveAllMenuItems_x                         0x8DE300
#define CContextMenuManager__AddMenu_x                             0x8CA200
#define CContextMenuManager__RemoveMenu_x                          0x8CA540
#define CContextMenuManager__PopupMenu_x                           0x8CA990
#define CContextMenuManager__Flush_x                               0x8CA270
#define CContextMenuManager__GetMenu_x                             0x4168A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x879050
#define CChatService__GetFriendName_x                              0x879060

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x692220
#define CChatWindow__Clear_x                                       0x691DF0
#define CChatWindow__WndNotification_x                             0x692750

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CE010
#define CComboWnd__Draw_x                                          0x8CE220
#define CComboWnd__GetCurChoice_x                                  0x8CDDC0
#define CComboWnd__GetListRect_x                                   0x8CE4C0
#define CComboWnd__GetTextRect_x                                   0x8CE080
#define CComboWnd__InsertChoice_x                                  0x8CE530
#define CComboWnd__SetColors_x                                     0x8CDD50
#define CComboWnd__SetChoice_x                                     0x8CDD80
#define CComboWnd__GetItemCount_x                                  0x8CDDB0
#define CComboWnd__GetCurChoiceText_x                              0x8CDE00


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69B8D0
#define CContainerWnd__vftable_x                                   0xADECC0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B4C50
#define CDisplay__GetClickedActor_x                                0x4AD590
#define CDisplay__GetUserDefinedColor_x                            0x4AC170
#define CDisplay__GetWorldFilePath_x                               0x4AB5C0
#define CDisplay__is3dON_x                                         0x4AAA50
#define CDisplay__ReloadUI_x                                       0x4C0160
#define CDisplay__WriteTextHD2_x                                   0x4B1010

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F44F0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E2300
#define CEditWnd__GetCharIndexPt_x                                 0x8E33A0
#define CEditWnd__GetDisplayString_x                               0x8E24B0
#define CEditWnd__GetHorzOffset_x                                  0x8E27F0
#define CEditWnd__GetLineForPrintableChar_x                        0x8E2E60
#define CEditWnd__GetSelStartPt_x                                  0x8E3660
#define CEditWnd__GetSTMLSafeText_x                                0x8E2990
#define CEditWnd__PointFromPrintableChar_x                         0x8E2F50
#define CEditWnd__SelectableCharFromPoint_x                        0x8E30D0
#define CEditWnd__SetEditable_x                                    0x8E2960

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x5583F0
#define CEverQuest__CreateTargetIndicator_x                        0x5592E0
#define CEverQuest__DeleteTargetIndicator_x                        0x559360
#define CEverQuest__DoTellWindow_x                                 0x4727A0
#define CEverQuest__DropHeldItemOnGround_x                         0x56F490
#define CEverQuest__dsp_chat_x                                     0x472AE0
#define CEverQuest__trimName_x                                     0x554D40
#define CEverQuest__Emote_x                                        0x56D7E0
#define CEverQuest__EnterZone_x                                    0x5687E0
#define CEverQuest__GetBodyTypeDesc_x                              0x5527A0
#define CEverQuest__GetClassDesc_x                                 0x55C070
#define CEverQuest__GetClassThreeLetterCode_x                      0x55C670
#define CEverQuest__GetDeityDesc_x                                 0x553080
#define CEverQuest__GetLangDesc_x                                  0x552B30
#define CEverQuest__GetRaceDesc_x                                  0x55C830
#define CEverQuest__InterpretCmd_x                                 0x560640
#define CEverQuest__LeftClickedOnPlayer_x                          0x573CC0
#define CEverQuest__LMouseUp_x                                     0x575DC0
#define CEverQuest__RightClickedOnPlayer_x                         0x5747D0
#define CEverQuest__RMouseUp_x                                     0x575820
#define CEverQuest__SetGameState_x                                 0x558CB0
#define CEverQuest__UPCNotificationFlush_x                         0x5505B0
#define CEverQuest__IssuePetCommand_x                              0x561020

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AC660
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AC6C0
#define CGaugeWnd__Draw_x                                          0x6ACAF0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4372B0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C8B30

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D5CC0
#define CInvSlotMgr__MoveItem_x                                    0x6D6B70
#define CInvSlotMgr__SelectSlot_x                                  0x6D5D70

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D5170
#define CInvSlot__SliderComplete_x                                 0x6D2980
#define CInvSlot__GetItemBase_x                                    0x6D1DE0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D7FD0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79FEA0
#define CItemDisplayWnd__UpdateStrings_x                           0x6DA0E0

// CLabel 
#define CLabel__Draw_x                                             0x6F37D0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B9D00
#define CListWnd__dCListWnd_x                                      0x8BAF20
#define CListWnd__AddColumn_x                                      0x8BAEC0
#define CListWnd__AddColumn1_x                                     0x8BA560
#define CListWnd__AddLine_x                                        0x8B9FC0
#define CListWnd__AddString_x                                      0x8BA1E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B6F70
#define CListWnd__CalculateVSBRange_x                              0x8B91C0
#define CListWnd__ClearSel_x                                       0x8B6280
#define CListWnd__ClearAllSel_x                                    0x8B6230
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B9B90
#define CListWnd__Compare_x                                        0x8B7AF0
#define CListWnd__Draw_x                                           0x8B8DC0
#define CListWnd__DrawColumnSeparators_x                           0x8B8C50
#define CListWnd__DrawHeader_x                                     0x8B6540
#define CListWnd__DrawItem_x                                       0x8B8180
#define CListWnd__DrawLine_x                                       0x8B88F0
#define CListWnd__DrawSeparator_x                                  0x8B8CF0
#define CListWnd__EnsureVisible_x                                  0x8B70D0
#define CListWnd__ExtendSel_x                                      0x8B8090
#define CListWnd__GetColumnMinWidth_x                              0x8B5C30
#define CListWnd__GetColumnWidth_x                                 0x8B5B60
#define CListWnd__GetCurSel_x                                      0x8B5330
#define CListWnd__GetItemAtPoint_x                                 0x8B7370
#define CListWnd__GetItemAtPoint1_x                                0x8B73E0
#define CListWnd__GetItemData_x                                    0x8B5670
#define CListWnd__GetItemHeight_x                                  0x8B6BC0
#define CListWnd__GetItemIcon_x                                    0x8B5860
#define CListWnd__GetItemRect_x                                    0x8B71B0
#define CListWnd__GetItemText_x                                    0x8B5710
#define CListWnd__GetSelList_x                                     0x8BA450
#define CListWnd__GetSeparatorRect_x                               0x8B7A10
#define CListWnd__RemoveLine_x                                     0x8BA3D0
#define CListWnd__SetColors_x                                      0x8B5480
#define CListWnd__SetColumnJustification_x                         0x8B5EC0
#define CListWnd__SetColumnWidth_x                                 0x8B5BE0
#define CListWnd__SetCurSel_x                                      0x8B5370
#define CListWnd__SetItemColor_x                                   0x8B9880
#define CListWnd__SetItemData_x                                    0x8B62E0
#define CListWnd__SetItemText_x                                    0x8B96C0
#define CListWnd__ShiftColumnSeparator_x                           0x8B9550
#define CListWnd__Sort_x                                           0x8BB020
#define CListWnd__ToggleSel_x                                      0x8B61B0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70C920

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72DD00
#define CMerchantWnd__RequestBuyItem_x                             0x734DA0
#define CMerchantWnd__RequestSellItem_x                            0x735860
#define CMerchantWnd__SelectRecoverySlot_x                         0x72DFB0
#define CMerchantWnd__SelectBuySellSlot_x                          0x72D1B0
#define CMerchantWnd__ActualSelect_x                               0x731C80

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8458B0
#define CPacketScrambler__hton_x                                   0x8458C0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D8CC0
#define CSidlManager__CreateLabel_x                                0x795E10

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65A3E1
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65A300
#define CSidlScreenWnd__ConvertToRes_x                             0x8F43D0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D09E0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D1BB0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D1C60
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D1130
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D0390
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CFAE0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D0580
#define CSidlScreenWnd__Init1_x                                    0x8D1880
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D0A90
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CFCA0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D1370
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CF730
#define CSidlScreenWnd__StoreIniVis_x                              0x8CFA90
#define CSidlScreenWnd__WndNotification_x                          0x8D1600
#define CSidlScreenWnd__GetChildItem_x                             0x8CFBB0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C3400
#define CSidlScreenWnd__m_layoutCopy_x                             0x18208F8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F8FD0
#define CSkillMgr__GetSkillCap_x                                   0x5F91B0
#define CSkillMgr__GetNameToken_x                                  0x5F8BF0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F3680
#define CSliderWnd__SetValue_x                                     0x8F3850
#define CSliderWnd__SetNumTicks_x                                  0x8F3FD0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79DB00

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EF050
#define CStmlWnd__CalculateHSBRange_x                              0x8E7570
#define CStmlWnd__CalculateVSBRange_x                              0x8E7600
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E7780
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E8060
#define CStmlWnd__ForceParseNow_x                                  0x8EF9A0
#define CStmlWnd__GetNextTagPiece_x                                0x8E7F60
#define CStmlWnd__GetSTMLText_x                                    0x691690
#define CStmlWnd__GetVisibleText_x                                 0x8E8AB0
#define CStmlWnd__InitializeWindowVariables_x                      0x8EAE40
#define CStmlWnd__MakeStmlColorTag_x                               0x8E6870
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E68D0
#define CStmlWnd__SetSTMLText_x                                    0x8EC6A0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EECF0
#define CStmlWnd__UpdateHistoryString_x                            0x8E99F0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E5F00
#define CTabWnd__DrawCurrentPage_x                                 0x8E5790
#define CTabWnd__DrawTab_x                                         0x8E5550
#define CTabWnd__GetCurrentPage_x                                  0x8E5B40
#define CTabWnd__GetPageInnerRect_x                                0x8E5240
#define CTabWnd__GetTabInnerRect_x                                 0x8E5440
#define CTabWnd__GetTabRect_x                                      0x8E5310
#define CTabWnd__InsertPage_x                                      0x8E61F0
#define CTabWnd__SetPage_x                                         0x8E5B70
#define CTabWnd__SetPageRect_x                                     0x8E5E40
#define CTabWnd__UpdatePage_x                                      0x8E6190

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432E30

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CD9C0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6317E0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F9810

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B3590

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029D0
#define CXStr__CXStr1_x                                            0x73FF20
#define CXStr__CXStr3_x                                            0x891500
#define CXStr__dCXStr_x                                            0x59A590
#define CXStr__operator_equal_x                                    0x891670
#define CXStr__operator_equal1_x                                   0x8916C0
#define CXStr__operator_plus_equal1_x                              0x8927C0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C2610
#define CXWnd__Center_x                                            0x8C87E0
#define CXWnd__ClrFocus_x                                          0x8C21E0
#define CXWnd__DoAllDrawing_x                                      0x8C8430
#define CXWnd__DrawChildren_x                                      0x8C85D0
#define CXWnd__DrawColoredRect_x                                   0x8C29D0
#define CXWnd__DrawTooltip_x                                       0x8C2C80
#define CXWnd__DrawTooltipAtPoint_x                                0x8C7390
#define CXWnd__GetBorderFrame_x                                    0x8C30D0
#define CXWnd__GetChildWndAt_x                                     0x8C91B0
#define CXWnd__GetClientClipRect_x                                 0x8C2E90
#define CXWnd__GetScreenClipRect_x                                 0x8C7A90
#define CXWnd__GetScreenRect_x                                     0x8C32A0
#define CXWnd__GetTooltipRect_x                                    0x8C2B10
#define CXWnd__GetWindowTextA_x                                    0x424520
#define CXWnd__IsActive_x                                          0x8BDD10
#define CXWnd__IsDescendantOf_x                                    0x8C3010
#define CXWnd__IsReallyVisible_x                                   0x8C63C0
#define CXWnd__IsType_x                                            0x8F6030
#define CXWnd__Move_x                                              0x8C5AD0
#define CXWnd__Move1_x                                             0x8C80E0
#define CXWnd__ProcessTransition_x                                 0x8C25C0
#define CXWnd__Refade_x                                            0x8C2390
#define CXWnd__Resize_x                                            0x8C3360
#define CXWnd__Right_x                                             0x8C7890
#define CXWnd__SetFocus_x                                          0x8C4C30
#define CXWnd__SetFont_x                                           0x8C2230
#define CXWnd__SetKeyTooltip_x                                     0x8C35D0
#define CXWnd__SetMouseOver_x                                      0x8C7DD0
#define CXWnd__StartFade_x                                         0x8C2660
#define CXWnd__GetChildItem_x                                      0x8C7D10

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BF5B0
#define CXWndManager__DrawWindows_x                                0x8BF1F0
#define CXWndManager__GetKeyboardFlags_x                           0x8BD840
#define CXWndManager__HandleKeyboardMsg_x                          0x8BE1A0
#define CXWndManager__RemoveWnd_x                                  0x8BDEA0

// CDBStr
#define CDBStr__GetString_x                                        0x4A9010

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44DBA0
#define EQ_Character__Cur_HP_x                                     0x462710
#define EQ_Character__Cur_Mana_x                                   0x456240
#define EQ_Character__GetAACastingTimeModifier_x                   0x446DB0
#define EQ_Character__GetCharInfo2_x                               0x865300
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F0C0
#define EQ_Character__GetFocusRangeModifier_x                      0x43F120
#define EQ_Character__Max_Endurance_x                              0x5BF6E0
#define EQ_Character__Max_HP_x                                     0x458E60
#define EQ_Character__Max_Mana_x                                   0x5BF510
#define EQ_Character__doCombatAbility_x                            0x5BCC00
#define EQ_Character__UseSkill_x                                   0x46CBA0
#define EQ_Character__GetConLevel_x                                0x5B1FB0
#define EQ_Character__IsExpansionFlag_x                            0x423A60
#define EQ_Character__TotalEffect_x                                0x44AE30
#define EQ_Character__GetPCSpellAffect_x                           0x4471B0
#define EQ_Character__SpellDuration_x                              0x4450B0
#define EQ_Character__FindItemByRecord_x                           0x45FB80

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x4423F0
#define CCharacterSelect__EnterWorld_x                             0x441BC0
#define CCharacterSelect__Quit_x                                   0x4407A0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5924D0
#define EQ_Item__CreateItemTagString_x                             0x8441F0
#define EQ_Item__IsStackable_x                                     0x839AA0
#define EQ_Item__GetImageNum_x                                     0x83C520
#define EQ_Item__CreateItemClient_x                                0x593090
#define EQ_Item__GetItemValue_x                                    0x842F30
#define EQ_Item__ValueSellMerchant_x                               0x845500
#define EQ_Item__IsKeyRingItem_x                                   0x83A4D0
#define EQ_Item__CanGoInBag_x                                      0x592660
#define EQ_Item__GetMaxItemCount_x                                 0x839720
#define EQ_Item__GetHeldItem_x                                     0x83B320

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C8900
#define EQ_LoadingS__Array_x                                       0xC204C0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C1C00
#define EQ_PC__GetAlternateAbilityId_x                             0x84D8E0
#define EQ_PC__GetCombatAbility_x                                  0x84D970
#define EQ_PC__GetCombatAbilityTimer_x                             0x8486C0
#define EQ_PC__GetItemTimerValue_x                                 0x5BB2B0
#define EQ_PC__HasLoreItem_x                                       0x5B54C0
#define EQ_PC__AlertInventoryChanged_x                             0x5B1F80
#define EQ_PC__GetPcZoneClient_x                                   0x5DC260
#define EQ_PC__RemoveMyAffect_x                                    0x5BA750
#define EQ_PC__GetKeyRingItems_x                                   0x848AE0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x511340
#define EQItemList__add_object_x                                   0x53D0A0
#define EQItemList__add_item_x                                     0x511280
#define EQItemList__delete_item_x                                  0x511730
#define EQItemList__FreeItemList_x                                 0x511630

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A82E0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C7290
#define EQPlayer__dEQPlayer_x                                      0x5D0150
#define EQPlayer__DoAttack_x                                       0x5E2120
#define EQPlayer__EQPlayer_x                                       0x5D2570
#define EQPlayer__SetNameSpriteState_x                             0x5CD0A0
#define EQPlayer__SetNameSpriteTint_x                              0x5C86A0
#define PlayerBase__HasProperty_j_x                                0x926E30
#define EQPlayer__IsTargetable_x                                   0x927730
#define EQPlayer__CanSee_x                                         0x927C50
#define PlayerZoneClient__ChangeHeight_x                           0x5E1FE0
#define EQPlayer__CanSeeTargetIndicator_x                          0x927D40
#define PlayerBase__GetVisibilityLineSegment_x                     0x9279E0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D68B0
#define EQPlayerManager__GetSpawnByName_x                          0x5D6D10
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D68E0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x598580
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5985C0
#define KeypressHandler__ClearCommandStateArray_x                  0x598170
#define KeypressHandler__HandleKeyDown_x                           0x596AD0
#define KeypressHandler__HandleKeyUp_x                             0x596DF0
#define KeypressHandler__SaveKeymapping_x                          0x598240

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7052B0
#define MapViewMap__SaveEx_x                                       0x7085E0

#define PlayerPointManager__GetAltCurrency_x                       0x860200

// StringTable 
#define StringTable__getString_x                                   0x85AC70

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BF170
#define PcZoneClient__RemovePetEffect_x                            0x5BB780
#define PcZoneClient__HasAlternateAbility_x                        0x5BC120
#define PcZoneClient__GetCurrentMod_x                              0x458200
#define PcZoneClient__GetModCap_x                                  0x4559C0
#define PcZoneClient__CanEquipItem_x                               0x5BC6D0

//Doors
#define EQSwitch__UseSwitch_x                                      0x54EE90

//IconCache
#define IconCache__GetIcon_x                                       0x6A1EA0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x698C50
#define CContainerMgr__CloseContainer_x                            0x699470

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x765CD0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58B6C0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E06D0
#define EQ_Spell__SpellAffects_x                                   0x4DDD80
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DDDF0
#define CharacterZoneClient__CalcAffectChange_x                    0x4461E0
#define CLootWnd__LootAll_x                                        0x6FAB70
#define CLootWnd__RequestLootSlot_x                                0x6FB380

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AC920
#define CTargetWnd__WndNotification_x                              0x7AC410
#define CTargetWnd__RefreshTargetBuffs_x                           0x7ACB00

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B1B00

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D95D0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4982A0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E1930
#define CSidlManager__FindAnimation1_x                             0x8D6BC0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CFF00
#define CAltAbilityData__GetMercMaxRank_x                          0x4CFEB0
#define CAltAbilityData__GetMaxRank_x                              0x4C4E80

//CTargetRing
#define CTargetRing__Cast_x                                        0x588FB0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x454A60
#define CharacterBase__CreateItemGlobalIndex_x                     0x471970
#define CharacterBase__CreateItemIndex_x                           0x50A800
#define CharacterBase__GetItemPossession_x                         0x50BBE0
#define CharacterBase__GetItemByGlobalIndex_x                      0x873160

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x683580
#define CCastSpellWnd__IsBardSongPlaying_x                         0x682CE0

//messages
#define msg_spell_worn_off_x                                       0x4E8200
#define msg_new_text_x                                             0x4F1670
#define msgTokenTextParam_x                                        0x4EE040

//SpellManager
#define SpellManager__vftable_x                                    0xABAFB8
#define SpellManager__SpellManager_x                               0x47A770
#define Spellmanager__CheckSpellRequirementAssociations_x          0x5FFE10

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x92B710

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E47B0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43A7E0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x444A60
#define ItemGlobalIndex__IsValidIndex_x                            0x4542E0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x870F80
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x86FEC0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F3A20
