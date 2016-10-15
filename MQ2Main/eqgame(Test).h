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
#define __ExpectedVersionDate                                     "Oct 12 2016"
#define __ExpectedVersionTime                                     "14:51:19"
#define __ActualVersionDate_x                                      0xAD52D8
#define __ActualVersionTime_x                                      0xAD52E4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59ED20
#define __MemChecker1_x                                            0x8955F0
#define __MemChecker2_x                                            0x634EA0
#define __MemChecker3_x                                            0x634DF0
#define __MemChecker4_x                                            0x7E6A60
#define __EncryptPad0_x                                            0xC779F0
#define __EncryptPad1_x                                            0xE038D0
#define __EncryptPad2_x                                            0xCC0688
#define __EncryptPad3_x                                            0xCC0288
#define __EncryptPad4_x                                            0xDD98A0
#define __EncryptPad5_x                                            0x11B4BC0
#define __AC1_x                                                    0x7A65D5
#define __AC2_x                                                    0x558CB7
#define __AC3_x                                                    0x556E50
#define __AC4_x                                                    0x569660
#define __AC5_x                                                    0x57C1CB
#define __AC6_x                                                    0x57FD6E
#define __AC7_x                                                    0x57686C
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
#define __do_loot_x                                                0x51E210
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
#define pinstCGroupSearchFiltersWnd_x                              0xF62CFC
#define pinstCLoadskinWnd_x                                        0xF62D00
#define pinstCAlarmWnd_x                                           0xF62D04
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
#define pinstCLargeDialogWnd_x                                     0x11BB8A0
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
#define __CastRay_x                                                0x535440
#define __ConvertItemTags_x                                        0x522D70
#define __ExecuteCmd_x                                             0x50D670
#define __EQGetTime_x                                              0x895280
#define __get_melee_range_x                                        0x514220
#define __GetGaugeValueFromEQ_x                                    0x7A5310
#define __GetLabelFromEQ_x                                         0x7A6560
#define __ToggleKeyRingItem_x                                      0x47F7E0
#define __GetXTargetType_x                                         0x92B560
#define __LoadFrontEnd_x                                           0x634570
#define __NewUIINI_x                                               0x7A4CF0
#define __ProcessGameEvents_x                                      0x5785D0
#define __ProcessMouseEvent_x                                      0x577D70
#define CrashDetected_x                                            0x635F30
#define wwsCrashReportCheckForUploader_x                           0x7F2660
#define DrawNetStatus_x                                            0x5AE9A0
#define Util__FastTime_x                                           0x894DF0
#define Expansion_HoT_x                                            0x10245E0
#define __HelpPath_x                                               0x10A7CD8
#define __STMLToText_x                                             0x8E0560

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4203D0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B170
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41AF50

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C65A0
#define AltAdvManager__IsAbilityReady_x                            0x4C6610
#define AltAdvManager__GetAAById_x                                 0x4C69D0
#define AltAdvManager__CanTrainAbility_x                           0x4C72D0
#define AltAdvManager__CanSeeAbility_x                             0x4C6E90

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x462DB0
#define CharacterZoneClient__MakeMeVisible_x                       0x467860
#define CharacterZoneClient__IsStackBlocked_x                      0x447410
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4468D0
#define CharacterZoneClient__GetItemCountWorn_x                    0x460BF0
#define CharacterZoneClient__GetItemCountInInventory_x             0x460CD0
#define CharacterZoneClient__GetCursorItemCount_x                  0x460DB0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6640B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x672340

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58DCB0
#define CButtonWnd__CButtonWnd_x                                   0x8D47A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68D5A0
#define CChatManager__InitContextMenu_x                            0x68E120

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DE8C0
#define CContextMenu__dCContextMenu_x                              0x8DEAD0
#define CContextMenu__AddMenuItem_x                                0x8DEAE0
#define CContextMenu__RemoveMenuItem_x                             0x8DEDD0
#define CContextMenu__RemoveAllMenuItems_x                         0x8DEDF0
#define CContextMenuManager__AddMenu_x                             0x8CAD80
#define CContextMenuManager__RemoveMenu_x                          0x8CB0E0
#define CContextMenuManager__PopupMenu_x                           0x8CB530
#define CContextMenuManager__Flush_x                               0x8CADF0
#define CContextMenuManager__GetMenu_x                             0x416850

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x879B00
#define CChatService__GetFriendName_x                              0x879B10

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x693380
#define CChatWindow__Clear_x                                       0x692F50
#define CChatWindow__WndNotification_x                             0x6938C0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CEB80
#define CComboWnd__Draw_x                                          0x8CED90
#define CComboWnd__GetCurChoice_x                                  0x8CE930
#define CComboWnd__GetListRect_x                                   0x8CF030
#define CComboWnd__GetTextRect_x                                   0x8CEBF0
#define CComboWnd__InsertChoice_x                                  0x8CF0A0
#define CComboWnd__SetColors_x                                     0x8CE8C0
#define CComboWnd__SetChoice_x                                     0x8CE8F0
#define CComboWnd__GetItemCount_x                                  0x8CE920
#define CComboWnd__GetCurChoiceText_x                              0x8CE970

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69CAB0
#define CContainerWnd__vftable_x                                   0xADECD8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B4A00
#define CDisplay__GetClickedActor_x                                0x4AD340
#define CDisplay__GetUserDefinedColor_x                            0x4ABF20
#define CDisplay__GetWorldFilePath_x                               0x4AB370
#define CDisplay__is3dON_x                                         0x4AA800
#define CDisplay__ReloadUI_x                                       0x4BFF10
#define CDisplay__WriteTextHD2_x                                   0x4B0DC0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F4F80

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E2DF0
#define CEditWnd__GetCharIndexPt_x                                 0x8E3E80
#define CEditWnd__GetDisplayString_x                               0x8E2FA0
#define CEditWnd__GetHorzOffset_x                                  0x8E32E0
#define CEditWnd__GetLineForPrintableChar_x                        0x8E3950
#define CEditWnd__GetSelStartPt_x                                  0x8E4130
#define CEditWnd__GetSTMLSafeText_x                                0x8E3480
#define CEditWnd__PointFromPrintableChar_x                         0x8E3A40
#define CEditWnd__SelectableCharFromPoint_x                        0x8E3BC0
#define CEditWnd__SetEditable_x                                    0x8E3450

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x559400
#define CEverQuest__CreateTargetIndicator_x                        0x55A2F0
#define CEverQuest__DeleteTargetIndicator_x                        0x55A370
#define CEverQuest__DoTellWindow_x                                 0x4724D0
#define CEverQuest__DropHeldItemOnGround_x                         0x5704A0
#define CEverQuest__dsp_chat_x                                     0x472810
#define CEverQuest__trimName_x                                     0x555D50
#define CEverQuest__Emote_x                                        0x56E7F0
#define CEverQuest__EnterZone_x                                    0x5697F0
#define CEverQuest__GetBodyTypeDesc_x                              0x5537B0
#define CEverQuest__GetClassDesc_x                                 0x55D080
#define CEverQuest__GetClassThreeLetterCode_x                      0x55D680
#define CEverQuest__GetDeityDesc_x                                 0x554090
#define CEverQuest__GetLangDesc_x                                  0x553B40
#define CEverQuest__GetRaceDesc_x                                  0x55D840
#define CEverQuest__InterpretCmd_x                                 0x561650
#define CEverQuest__LeftClickedOnPlayer_x                          0x574CC0
#define CEverQuest__LMouseUp_x                                     0x576DC0
#define CEverQuest__RightClickedOnPlayer_x                         0x5757D0
#define CEverQuest__RMouseUp_x                                     0x576820
#define CEverQuest__SetGameState_x                                 0x559CC0
#define CEverQuest__UPCNotificationFlush_x                         0x5515C0
#define CEverQuest__IssuePetCommand_x                              0x562030

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AD800
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AD860
#define CGaugeWnd__Draw_x                                          0x6ADC90

// CGuild
#define CGuild__FindMemberByName_x                                 0x4371F0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C9C80

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D6DF0
#define CInvSlotMgr__MoveItem_x                                    0x6D7C90
#define CInvSlotMgr__SelectSlot_x                                  0x6D6EA0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D6290
#define CInvSlot__SliderComplete_x                                 0x6D3AA0
#define CInvSlot__GetItemBase_x                                    0x6D2F40

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D90B0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A0D20
#define CItemDisplayWnd__UpdateStrings_x                           0x6DB1F0

// CLabel 
#define CLabel__Draw_x                                             0x6F48F0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8BA810
#define CListWnd__dCListWnd_x                                      0x8BBA30
#define CListWnd__AddColumn_x                                      0x8BB9D0
#define CListWnd__AddColumn1_x                                     0x8BB070
#define CListWnd__AddLine_x                                        0x8BAAD0
#define CListWnd__AddString_x                                      0x8BACF0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B7AB0
#define CListWnd__CalculateVSBRange_x                              0x8B9CE0
#define CListWnd__ClearSel_x                                       0x8B6DD0
#define CListWnd__ClearAllSel_x                                    0x8B6D80
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8BA6A0
#define CListWnd__Compare_x                                        0x8B8610
#define CListWnd__Draw_x                                           0x8B98E0
#define CListWnd__DrawColumnSeparators_x                           0x8B9770
#define CListWnd__DrawHeader_x                                     0x8B7090
#define CListWnd__DrawItem_x                                       0x8B8CA0
#define CListWnd__DrawLine_x                                       0x8B9410
#define CListWnd__DrawSeparator_x                                  0x8B9810
#define CListWnd__EnsureVisible_x                                  0x8B7C10
#define CListWnd__ExtendSel_x                                      0x8B8BB0
#define CListWnd__GetColumnMinWidth_x                              0x8B6780
#define CListWnd__GetColumnWidth_x                                 0x8B66B0
#define CListWnd__GetCurSel_x                                      0x8B5E90
#define CListWnd__GetItemAtPoint_x                                 0x8B7EA0
#define CListWnd__GetItemAtPoint1_x                                0x8B7F10
#define CListWnd__GetItemData_x                                    0x8B61C0
#define CListWnd__GetItemHeight_x                                  0x8B7710
#define CListWnd__GetItemIcon_x                                    0x8B63B0
#define CListWnd__GetItemRect_x                                    0x8B7CE0
#define CListWnd__GetItemText_x                                    0x8B6260
#define CListWnd__GetSelList_x                                     0x8BAF60
#define CListWnd__GetSeparatorRect_x                               0x8B8540
#define CListWnd__RemoveLine_x                                     0x8BAEE0
#define CListWnd__SetColors_x                                      0x8B5FE0
#define CListWnd__SetColumnJustification_x                         0x8B6A10
#define CListWnd__SetColumnWidth_x                                 0x8B6730
#define CListWnd__SetCurSel_x                                      0x8B5ED0
#define CListWnd__SetItemColor_x                                   0x8BA390
#define CListWnd__SetItemData_x                                    0x8B6E30
#define CListWnd__SetItemText_x                                    0x8BA1D0
#define CListWnd__ShiftColumnSeparator_x                           0x8BA060
#define CListWnd__Sort_x                                           0x8BBB30
#define CListWnd__ToggleSel_x                                      0x8B6D00

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70DAC0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72ED80
#define CMerchantWnd__RequestBuyItem_x                             0x735DE0
#define CMerchantWnd__RequestSellItem_x                            0x7368B0
#define CMerchantWnd__SelectRecoverySlot_x                         0x72F030
#define CMerchantWnd__SelectBuySellSlot_x                          0x72E230
#define CMerchantWnd__ActualSelect_x                               0x732CD0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x846510
#define CPacketScrambler__hton_x                                   0x846520

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D97F0
#define CSidlManager__CreateLabel_x                                0x796CC0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65B440
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65B370
#define CSidlScreenWnd__ConvertToRes_x                             0x8F4E60
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D1500
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D26D0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D2780
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D1C50
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D0EB0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D0650
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D10A0
#define CSidlScreenWnd__Init1_x                                    0x8D23A0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D15B0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D0810
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D1E90
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D02B0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D0600
#define CSidlScreenWnd__WndNotification_x                          0x8D2120
#define CSidlScreenWnd__GetChildItem_x                             0x8D0720
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C3FB0
#define CSidlScreenWnd__m_layoutCopy_x                             0x18208F8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F9F00
#define CSkillMgr__GetSkillCap_x                                   0x5FA0E0
#define CSkillMgr__GetNameToken_x                                  0x5F9B20

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F4110
#define CSliderWnd__SetValue_x                                     0x8F42E0
#define CSliderWnd__SetNumTicks_x                                  0x8F4A60

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79E980

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EFA40
#define CStmlWnd__CalculateHSBRange_x                              0x8E7FA0
#define CStmlWnd__CalculateVSBRange_x                              0x8E8030
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E81A0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E8A80
#define CStmlWnd__ForceParseNow_x                                  0x8F0400
#define CStmlWnd__GetNextTagPiece_x                                0x8E8980
#define CStmlWnd__GetSTMLText_x                                    0x6927F0
#define CStmlWnd__GetVisibleText_x                                 0x8E94D0
#define CStmlWnd__InitializeWindowVariables_x                      0x8EB840
#define CStmlWnd__MakeStmlColorTag_x                               0x8E72A0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E7300
#define CStmlWnd__SetSTMLText_x                                    0x8ED090
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EF6E0
#define CStmlWnd__UpdateHistoryString_x                            0x8EA400

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E69B0
#define CTabWnd__DrawCurrentPage_x                                 0x8E6240
#define CTabWnd__DrawTab_x                                         0x8E6000
#define CTabWnd__GetCurrentPage_x                                  0x8E65F0
#define CTabWnd__GetPageInnerRect_x                                0x8E5CF0
#define CTabWnd__GetTabInnerRect_x                                 0x8E5EF0
#define CTabWnd__GetTabRect_x                                      0x8E5DC0
#define CTabWnd__InsertPage_x                                      0x8E6CA0
#define CTabWnd__SetPage_x                                         0x8E6620
#define CTabWnd__SetPageRect_x                                     0x8E68F0
#define CTabWnd__UpdatePage_x                                      0x8E6C40

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432DC0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CE530

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x632810

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8FA280

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B4130

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59B270
#define CXStr__CXStr1_x                                            0x8B50B0
#define CXStr__CXStr3_x                                            0x892040
#define CXStr__dCXStr_x                                            0x4C7D60
#define CXStr__operator_equal_x                                    0x8921B0
#define CXStr__operator_equal1_x                                   0x892200
#define CXStr__operator_plus_equal1_x                              0x893300

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C31C0
#define CXWnd__Center_x                                            0x8C9390
#define CXWnd__ClrFocus_x                                          0x8C2D90
#define CXWnd__DoAllDrawing_x                                      0x8C8FE0
#define CXWnd__DrawChildren_x                                      0x8C9180
#define CXWnd__DrawColoredRect_x                                   0x8C3570
#define CXWnd__DrawTooltip_x                                       0x8C3800
#define CXWnd__DrawTooltipAtPoint_x                                0x8C7F60
#define CXWnd__GetBorderFrame_x                                    0x8C3C70
#define CXWnd__GetChildWndAt_x                                     0x8C9D60
#define CXWnd__GetClientClipRect_x                                 0x8C3A20
#define CXWnd__GetScreenClipRect_x                                 0x8C8660
#define CXWnd__GetScreenRect_x                                     0x8C3E50
#define CXWnd__GetTooltipRect_x                                    0x8C3690
#define CXWnd__GetWindowTextA_x                                    0x4244F0
#define CXWnd__IsActive_x                                          0x8BE7E0
#define CXWnd__IsDescendantOf_x                                    0x8C3BB0
#define CXWnd__IsReallyVisible_x                                   0x8C6FB0
#define CXWnd__IsType_x                                            0x8F6B00
#define CXWnd__Move_x                                              0x8C6690
#define CXWnd__Move1_x                                             0x8C8C80
#define CXWnd__ProcessTransition_x                                 0x8C3160
#define CXWnd__Refade_x                                            0x8C2F40
#define CXWnd__Resize_x                                            0x8C3F10
#define CXWnd__Right_x                                             0x8C8460
#define CXWnd__SetFocus_x                                          0x8C5800
#define CXWnd__SetFont_x                                           0x8C2DE0
#define CXWnd__SetKeyTooltip_x                                     0x8C4180
#define CXWnd__SetMouseOver_x                                      0x8C8990
#define CXWnd__StartFade_x                                         0x8C3210
#define CXWnd__GetChildItem_x                                      0x8C88D0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C0080
#define CXWndManager__DrawWindows_x                                0x8BFCC0
#define CXWndManager__GetKeyboardFlags_x                           0x8BE310
#define CXWndManager__HandleKeyboardMsg_x                          0x8BEC70
#define CXWndManager__RemoveWnd_x                                  0x8BE970

// CDBStr
#define CDBStr__GetString_x                                        0x4A8DE0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44D9A0
#define EQ_Character__Cur_HP_x                                     0x462450
#define EQ_Character__Cur_Mana_x                                   0x455F90
#define EQ_Character__GetAACastingTimeModifier_x                   0x446BE0
#define EQ_Character__GetCharInfo2_x                               0x865D10
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EE40
#define EQ_Character__GetFocusRangeModifier_x                      0x43EEA0
#define EQ_Character__Max_Endurance_x                              0x5C0380
#define EQ_Character__Max_HP_x                                     0x458BB0
#define EQ_Character__Max_Mana_x                                   0x5C01B0
#define EQ_Character__doCombatAbility_x                            0x5BD8A0
#define EQ_Character__UseSkill_x                                   0x46C8E0
#define EQ_Character__GetConLevel_x                                0x5B2FB0
#define EQ_Character__IsExpansionFlag_x                            0x423A20
#define EQ_Character__TotalEffect_x                                0x44AC30
#define EQ_Character__GetPCSpellAffect_x                           0x446FE0
#define EQ_Character__SpellDuration_x                              0x444EE0
#define EQ_Character__FindItemByRecord_x                           0x45F8E0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x442250
#define CCharacterSelect__EnterWorld_x                             0x441A20
#define CCharacterSelect__Quit_x                                   0x440600

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x593520
#define EQ_Item__CreateItemTagString_x                             0x844E60
#define EQ_Item__IsStackable_x                                     0x83A6A0
#define EQ_Item__GetImageNum_x                                     0x83D180
#define EQ_Item__CreateItemClient_x                                0x594110
#define EQ_Item__GetItemValue_x                                    0x843B90
#define EQ_Item__ValueSellMerchant_x                               0x846160
#define EQ_Item__IsKeyRingItem_x                                   0x83B190
#define EQ_Item__CanGoInBag_x                                      0x5936B0
#define EQ_Item__GetMaxItemCount_x                                 0x83A320
#define EQ_Item__GetHeldItem_x                                     0x83BFB0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C86F0
#define EQ_LoadingS__Array_x                                       0xC204C0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C28A0
#define EQ_PC__GetAlternateAbilityId_x                             0x84E490
#define EQ_PC__GetCombatAbility_x                                  0x84E520
#define EQ_PC__GetCombatAbilityTimer_x                             0x849320
#define EQ_PC__GetItemTimerValue_x                                 0x5BBF50
#define EQ_PC__HasLoreItem_x                                       0x5B64B0
#define EQ_PC__AlertInventoryChanged_x                             0x5B2F80
#define EQ_PC__GetPcZoneClient_x                                   0x5DCE80
#define EQ_PC__RemoveMyAffect_x                                    0x5BB3F0
#define EQ_PC__GetKeyRingItems_x                                   0x849740

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5122B0
#define EQItemList__add_object_x                                   0x53E110
#define EQItemList__add_item_x                                     0x5121F0
#define EQItemList__delete_item_x                                  0x5126A0
#define EQItemList__FreeItemList_x                                 0x5125A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A8060

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C7F40
#define EQPlayer__dEQPlayer_x                                      0x5D0DD0
#define EQPlayer__DoAttack_x                                       0x5E2D40
#define EQPlayer__EQPlayer_x                                       0x5D31F0
#define EQPlayer__SetNameSpriteState_x                             0x5CDD40
#define EQPlayer__SetNameSpriteTint_x                              0x5C9350
#define PlayerBase__HasProperty_j_x                                0x927790
#define EQPlayer__IsTargetable_x                                   0x928090
#define EQPlayer__CanSee_x                                         0x9285B0
#define PlayerZoneClient__ChangeHeight_x                           0x5E2C00
#define EQPlayer__CanSeeTargetIndicator_x                          0x9286A0
#define PlayerBase__GetVisibilityLineSegment_x                     0x928340

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D74C0
#define EQPlayerManager__GetSpawnByName_x                          0x5D7920
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D74F0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x599600
#define KeypressHandler__AttachKeyToEqCommand_x                    0x599640
#define KeypressHandler__ClearCommandStateArray_x                  0x5991F0
#define KeypressHandler__HandleKeyDown_x                           0x597B50
#define KeypressHandler__HandleKeyUp_x                             0x597E70
#define KeypressHandler__SaveKeymapping_x                          0x5992C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x706450
#define MapViewMap__SaveEx_x                                       0x709780

#define PlayerPointManager__GetAltCurrency_x                       0x860BA0

// StringTable 
#define StringTable__getString_x                                   0x85B820

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BFE10
#define PcZoneClient__RemovePetEffect_x                            0x5BC420
#define PcZoneClient__HasAlternateAbility_x                        0x5BCDC0
#define PcZoneClient__GetCurrentMod_x                              0x457F50
#define PcZoneClient__GetModCap_x                                  0x455710
#define PcZoneClient__CanEquipItem_x                               0x5BD370

//Doors
#define EQSwitch__UseSwitch_x                                      0x54FF00

//IconCache
#define IconCache__GetIcon_x                                       0x6A3090

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x699E40
#define CContainerMgr__CloseContainer_x                            0x69A660

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x766CD0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58C730

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E0570
#define EQ_Spell__SpellAffects_x                                   0x4DDC20
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DDC90
#define CharacterZoneClient__CalcAffectChange_x                    0x446010
#define CLootWnd__LootAll_x                                        0x6FBCC0
#define CLootWnd__RequestLootSlot_x                                0x6FC4D0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AD7D0
#define CTargetWnd__WndNotification_x                              0x7AD2C0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7AD9B0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B29B0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D9480

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x498010

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E2420
#define CSidlManager__FindAnimation1_x                             0x8D76F0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CFD90
#define CAltAbilityData__GetMercMaxRank_x                          0x4CFD40
#define CAltAbilityData__GetMaxRank_x                              0x4C4C50

//CTargetRing
#define CTargetRing__Cast_x                                        0x58A030

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x454860
#define CharacterBase__CreateItemGlobalIndex_x                     0x4716B0
#define CharacterBase__CreateItemIndex_x                           0x50B7C0
#define CharacterBase__GetItemPossession_x                         0x50CB90
#define CharacterBase__GetItemByGlobalIndex_x                      0x873C20

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x684600
#define CCastSpellWnd__IsBardSongPlaying_x                         0x683D60

//messages
#define msg_spell_worn_off_x                                       0x4E80D0
#define msg_new_text_x                                             0x4F1540
#define msgTokenTextParam_x                                        0x4EDF10

//SpellManager
#define SpellManager__vftable_x                                    0xABAFB8
#define SpellManager__SpellManager_x                               0x47A4D0
#define Spellmanager__CheckSpellRequirementAssociations_x          0x600D60

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x92C080

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E4650
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43A550
#define ItemGlobalIndex__IsEquippedLocation_x                      0x4448D0
#define ItemGlobalIndex__IsValidIndex_x                            0x4540F0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x871A40
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x870980

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F4B40
