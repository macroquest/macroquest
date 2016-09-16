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
#define __ExpectedVersionDate                                     "Aug 15 2016"
#define __ExpectedVersionTime                                     "13:13:08"
#define __ActualVersionDate_x                                      0xAD3280
#define __ActualVersionTime_x                                      0xAD328C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59C6C0
#define __MemChecker1_x                                            0x895A20
#define __MemChecker2_x                                            0x6332D0
#define __MemChecker3_x                                            0x633220
#define __MemChecker4_x                                            0x7E4430
#define __EncryptPad0_x                                            0xC72C08
#define __EncryptPad1_x                                            0xDFDED0
#define __EncryptPad2_x                                            0xCBB878
#define __EncryptPad3_x                                            0xCBB478
#define __EncryptPad4_x                                            0xDD4A30
#define __EncryptPad5_x                                            0x11AED10
#define __AC1_x                                                    0x7A4835
#define __AC2_x                                                    0x556817
#define __AC3_x                                                    0x5549B0
#define __AC4_x                                                    0x5671C0
#define __AC5_x                                                    0x579D2B
#define __AC6_x                                                    0x57D8CE
#define __AC7_x                                                    0x5743CC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FD63C

// Direct Input
#define DI8__Main_x                                                0x11AECE8
#define DI8__Keyboard_x                                            0x11AECEC
#define DI8__Mouse_x                                               0x11AECF0
#define DI8__Mouse_Copy_x                                          0x101D3DC
#define DI8__Mouse_Check_x                                         0x10A6BD4
#define __Attack_x                                                 0x10A18B7
#define __Autofire_x                                               0x10A18B8
#define __BindList_x                                               0xC34700
#define g_eqCommandStates_x                                        0x100C840
#define __Clicks_x                                                 0x101D498
#define __CommandList_x                                            0xC38AE8
#define __CurrentMapLabel_x                                        0x11B4770
#define __CurrentSocial_x                                          0xBEB0A0
#define __DoAbilityList_x                                          0x1053B6C
#define __do_loot_x                                                0x51B3D0
#define __DrawHandler_x                                            0x181B744
#define __GroupCount_x                                             0x100DE0A

#define __Guilds_x                                                 0x1013A20
#define __gWorld_x                                                 0x10102C4
#define __HotkeyPage_x                                             0x109A56C
#define __HWnd_x                                                   0x10A6BF0
#define __InChatMode_x                                             0x101D3C4
#define __LastTell_x                                               0x101F268
#define __LMouseHeldTime_x                                         0x101D504
#define __Mouse_x                                                  0x11AECF4
#define __MouseLook_x                                              0x101D45E
#define __MouseEventTime_x                                         0x10A20BC
#define __gpbCommandEvent_x                                        0x101038C
#define __NetStatusToggle_x                                        0x101D461
#define __PCNames_x                                                0x101E888
#define __RangeAttackReady_x                                       0x101E5C4
#define __RMouseHeldTime_x                                         0x101D500
#define __RunWalkState_x                                           0x101D3C8
#define __ScreenMode_x                                             0xF5C5C0
#define __ScreenX_x                                                0x101D37C
#define __ScreenY_x                                                0x101D378
#define __ScreenXMax_x                                             0x101D380
#define __ScreenYMax_x                                             0x101D384
#define __ServerHost_x                                             0x100DD54
#define __ServerName_x                                             0x1053B2C
#define __ShiftKeyDown_x                                           0x101DA50
#define __ShowNames_x                                              0x101E784
#define __Socials_x                                                0x1053C2C
#define __SubscriptionType_x                                       0x11E289C
#define __TargetAggroHolder_x                                      0x11B69AC
#define __ZoneType_x                                               0x101D85C
#define __GroupAggro_x                                             0x11B69EC
#define __LoginName_x                                              0x10A57CC
#define __Inviter_x                                                0x10A1834
#define __AttackOnAssist_x                                         0x101E740
#define __UseTellWindows_x                                         0x101EA20

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x10103B0
#define instEQZoneInfo_x                                           0x101D654
#define instKeypressHandler_x                                      0x10A20A0
#define pinstActiveBanker_x                                        0x1010368
#define pinstActiveCorpse_x                                        0x101036C
#define pinstActiveGMaster_x                                       0x1010370
#define pinstActiveMerchant_x                                      0x1010364
#define pinstAggroInfo_x                                           0xE1A0E8
#define pinstAltAdvManager_x                                       0xF5D680
#define pinstAuraMgr_x                                             0xE2A858
#define pinstBandageTarget_x                                       0x1010350
#define pinstCamActor_x                                            0xF5CFD4
#define pinstCDBStr_x                                              0xF5C554
#define pinstCDisplay_x                                            0x1010378
#define pinstCEverQuest_x                                          0x11AEE68
#define pinstCharData_x                                            0x1010334
#define pinstCharSpawn_x                                           0x101035C
#define pinstControlledMissile_x                                   0x1010330
#define pinstControlledPlayer_x                                    0x101035C
#define pinstCSidlManager_x                                        0x181AB34
#define pinstCXWndManager_x                                        0x181AB2C
#define instDynamicZone_x                                          0x101D210
#define pinstDZMember_x                                            0x101D320
#define pinstDZTimerInfo_x                                         0x101D324
#define pinstEQItemList_x                                          0x100CA90
#define pinstEQObjectList_x                                        0x100D804
#define instEQMisc_x                                               0xC0EEB8
#define pinstEQSoundManager_x                                      0xF5DBD8
#define instExpeditionLeader_x                                     0x101D25A
#define instExpeditionName_x                                       0x101D29A
#define pinstGroup_x                                               0x100DE06
#define pinstImeManager_x                                          0x181AB38
#define pinstLocalPlayer_x                                         0x1010348
#define pinstMercenaryData_x                                       0x10A2720
#define pinstMercenaryStats_x                                      0x11B6AF8
#define pinstMercAltAbilities_x                                    0xF5DA08
#define pinstModelPlayer_x                                         0x1010374
#define pinstPCData_x                                              0x1010334
#define pinstSkillMgr_x                                            0x10A3588
#define pinstSpawnManager_x                                        0x10A2E70
#define pinstSpellManager_x                                        0x10A36D0
#define pinstSpellSets_x                                           0x109A5D0
#define pinstStringTable_x                                         0x10102DC
#define pinstSwitchManager_x                                       0x100D998
#define pinstTarget_x                                              0x1010360
#define pinstTargetObject_x                                        0x1010338
#define pinstTargetSwitch_x                                        0x101033C
#define pinstTaskMember_x                                          0xF5C4A0
#define pinstTrackTarget_x                                         0x1010354
#define pinstTradeTarget_x                                         0x1010344
#define instTributeActive_x                                        0xC0EEDD
#define pinstViewActor_x                                           0xF5CFD0
#define pinstWorldData_x                                           0x1010318
#define pinstZoneAddr_x                                            0x101D8F4
#define pinstPlayerPath_x                                          0x10A2ED0
#define pinstTargetIndicator_x                                     0x10A3868
#define pinstCTargetManager_x                                      0x10A38C8

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE1A5E0
#define pinstCAudioTriggersWindow_x                                0xE1A470
#define pinstCCharacterSelect_x                                    0xF5CE64
#define pinstCFacePick_x                                           0xF5CC14
#define pinstCNoteWnd_x                                            0xF5CE1C
#define pinstCBookWnd_x                                            0xF5CE24
#define pinstCPetInfoWnd_x                                         0xF5CE28
#define pinstCTrainWnd_x                                           0xF5CE2C
#define pinstCSkillsWnd_x                                          0xF5CE30
#define pinstCSkillsSelectWnd_x                                    0xF5CE34
#define pinstCCombatSkillsSelectWnd_x                              0xF5CE38
#define pinstCFriendsWnd_x                                         0xF5CE3C
#define pinstCAuraWnd_x                                            0xF5CE40
#define pinstCRespawnWnd_x                                         0xF5CE44
#define pinstCBandolierWnd_x                                       0xF5CE48
#define pinstCPotionBeltWnd_x                                      0xF5CE4C
#define pinstCAAWnd_x                                              0xF5CE50
#define pinstCGroupSearchFiltersWnd_x                              0xF5CE54
#define pinstCLoadskinWnd_x                                        0xF5CE58
#define pinstCAlarmWnd_x                                           0xF5CE5C
#define pinstCMusicPlayerWnd_x                                     0xF5CE60
#define pinstCMailWnd_x                                            0xF5CE68
#define pinstCMailCompositionWnd_x                                 0xF5CE6C
#define pinstCMailAddressBookWnd_x                                 0xF5CE70
#define pinstCRaidWnd_x                                            0xF5CE78
#define pinstCRaidOptionsWnd_x                                     0xF5CE7C
#define pinstCBreathWnd_x                                          0xF5CE80
#define pinstCMapViewWnd_x                                         0xF5CE84
#define pinstCMapToolbarWnd_x                                      0xF5CE88
#define pinstCEditLabelWnd_x                                       0xF5CE8C
#define pinstCTargetWnd_x                                          0xF5CE90
#define pinstCColorPickerWnd_x                                     0xF5CE94
#define pinstCPlayerWnd_x                                          0xF5CE98
#define pinstCOptionsWnd_x                                         0xF5CE9C
#define pinstCBuffWindowNORMAL_x                                   0xF5CEA0
#define pinstCBuffWindowSHORT_x                                    0xF5CEA4
#define pinstCharacterCreation_x                                   0xF5CEA8
#define pinstCCursorAttachment_x                                   0xF5CEAC
#define pinstCCastingWnd_x                                         0xF5CEB0
#define pinstCCastSpellWnd_x                                       0xF5CEB4
#define pinstCSpellBookWnd_x                                       0xF5CEB8
#define pinstCInventoryWnd_x                                       0xF5CEBC
#define pinstCBankWnd_x                                            0xF5CEC4
#define pinstCQuantityWnd_x                                        0xF5CEC8
#define pinstCLootWnd_x                                            0xF5CECC
#define pinstCActionsWnd_x                                         0xF5CED0
#define pinstCCombatAbilityWnd_x                                   0xF5CED4
#define pinstCMerchantWnd_x                                        0xF5CED8
#define pinstCTradeWnd_x                                           0xF5CEDC
#define pinstCSelectorWnd_x                                        0xF5CEE0
#define pinstCBazaarWnd_x                                          0xF5CEE4
#define pinstCBazaarSearchWnd_x                                    0xF5CEE8
#define pinstCGiveWnd_x                                            0xF5CF04
#define pinstCTrackingWnd_x                                        0xF5CF0C
#define pinstCInspectWnd_x                                         0xF5CF10
#define pinstCSocialEditWnd_x                                      0xF5CF14
#define pinstCFeedbackWnd_x                                        0xF5CF18
#define pinstCBugReportWnd_x                                       0xF5CF1C
#define pinstCVideoModesWnd_x                                      0xF5CF20
#define pinstCTextEntryWnd_x                                       0xF5CF28
#define pinstCFileSelectionWnd_x                                   0xF5CF2C
#define pinstCCompassWnd_x                                         0xF5CF30
#define pinstCPlayerNotesWnd_x                                     0xF5CF34
#define pinstCGemsGameWnd_x                                        0xF5CF38
#define pinstCTimeLeftWnd_x                                        0xF5CF3C
#define pinstCPetitionQWnd_x                                       0xF5CF58
#define pinstCSoulmarkWnd_x                                        0xF5CF5C
#define pinstCStoryWnd_x                                           0xF5CF60
#define pinstCJournalTextWnd_x                                     0xF5CF64
#define pinstCJournalCatWnd_x                                      0xF5CF68
#define pinstCBodyTintWnd_x                                        0xF5CF6C
#define pinstCServerListWnd_x                                      0xF5CF70
#define pinstCAvaZoneWnd_x                                         0xF5CF7C
#define pinstCBlockedBuffWnd_x                                     0xF5CF80
#define pinstCBlockedPetBuffWnd_x                                  0xF5CF84
#define pinstCInvSlotMgr_x                                         0xF5CFC8
#define pinstCContainerMgr_x                                       0xF5CFCC
#define pinstCAdventureLeaderboardWnd_x                            0x11AF818
#define pinstCAdventureRequestWnd_x                                0x11AF890
#define pinstCAltStorageWnd_x                                      0x11AFB70
#define pinstCAdventureStatsWnd_x                                  0x11AF908
#define pinstCBarterMerchantWnd_x                                  0x11B0758
#define pinstCBarterSearchWnd_x                                    0x11B07D0
#define pinstCBarterWnd_x                                          0x11B0848
#define pinstCChatManager_x                                        0x11B0ED8
#define pinstCDynamicZoneWnd_x                                     0x11B1388
#define pinstCEQMainWnd_x                                          0x11B1520
#define pinstCFellowshipWnd_x                                      0x11B131C
#define pinstCFindLocationWnd_x                                    0x11B17F0
#define pinstCGroupSearchWnd_x                                     0x11B1AC0
#define pinstCGroupWnd_x                                           0x11B1B38
#define pinstCGuildBankWnd_x                                       0x11B1BB0
#define pinstCGuildMgmtWnd_x                                       0x11B3CA0
#define pinstCHotButtonWnd_x                                       0x11B3D9C
#define pinstCHotButtonWnd1_x                                      0x11B3D9C
#define pinstCHotButtonWnd2_x                                      0x11B3DA0
#define pinstCHotButtonWnd3_x                                      0x11B3DA4
#define pinstCHotButtonWnd4_x                                      0x11B3DC8
#define pinstCItemDisplayManager_x                                 0x11B40C0
#define pinstCItemExpTransferWnd_x                                 0x11B413C
#define pinstCLFGuildWnd_x                                         0x11B4418
#define pinstCMIZoneSelectWnd_x                                    0x11B4A00
#define pinstCConfirmationDialog_x                                 0x11B5108
#define pinstCPopupWndManager_x                                    0x11B5108
#define pinstCProgressionSelectionWnd_x                            0x11B51F8
#define pinstCPvPStatsWnd_x                                        0x11B52E8
#define pinstCSystemInfoDialogBox_x                                0x11B59F0
#define pinstCTaskWnd_x                                            0x11B6DB8
#define pinstCTaskSomething_x                                      0xE2B048
#define pinstCTaskTemplateSelectWnd_x                              0x11B6D40
#define pinstCTipWndOFDAY_x                                        0x11B6F20
#define pinstCTipWndCONTEXT_x                                      0x11B6F24
#define pinstCTitleWnd_x                                           0x11B6FA0
#define pinstCContextMenuManager_x                                 0x181AAA4
#define pinstCVoiceMacroWnd_x                                      0x10A3CA0
#define pinstCHtmlWnd_x                                            0x10A3D90
#define pinstIconCache_x                                           0x11B14F4
#define pinstCTradeskillWnd_x                                      0x11B70A0
#define pinstCAdvancedLootWnd_x                                    0xF5CFBC
#define pinstRewardSelectionWnd_x                                  0x11B5810

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x532530
#define __ConvertItemTags_x                                        0x51FF30
#define __ExecuteCmd_x                                             0x50A860
#define __EQGetTime_x                                              0x895650
#define __get_melee_range_x                                        0x5113F0
#define __GetGaugeValueFromEQ_x                                    0x7A3570
#define __GetLabelFromEQ_x                                         0x7A47C0
#define __ToggleKeyRingItem_x                                      0x47D7A0
#define __GetXTargetType_x                                         0x92B840
#define __LoadFrontEnd_x                                           0x6329A0
#define __NewUIINI_x                                               0x7A2F50
#define __ProcessGameEvents_x                                      0x576130
#define __ProcessMouseEvent_x                                      0x5758D0
#define CrashDetected_x                                            0x634360
#define wwsCrashReportCheckForUploader_x                           0x7F3140
#define DrawNetStatus_x                                            0x5AC250
#define Util__FastTime_x                                           0x895160
#define Expansion_HoT_x                                            0x101E730
#define __HelpPath_x                                               0x10A1E28
#define __STMLToText_x                                             0x8E0690

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4205D0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B440
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B220

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C4600
#define AltAdvManager__IsAbilityReady_x                            0x4C4670
#define AltAdvManager__GetAAById_x                                 0x4C4A30
#define AltAdvManager__CanTrainAbility_x                           0x4C52F0
#define AltAdvManager__CanSeeAbility_x                             0x4C4EF0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x462FD0
#define CharacterZoneClient__MakeMeVisible_x                       0x467A70
#define CharacterZoneClient__IsStackBlocked_x                      0x447620
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x446AE0
#define CharacterZoneClient__GetItemCountWorn_x                    0x460E30
#define CharacterZoneClient__GetItemCountInInventory_x             0x460F10
#define CharacterZoneClient__GetCursorItemCount_x                  0x460FF0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x662790

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x670D90

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58B6E0
#define CButtonWnd__CButtonWnd_x                                   0x8D4A50

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68BBE0
#define CChatManager__InitContextMenu_x                            0x68C760

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DE9F0
#define CContextMenu__dCContextMenu_x                              0x8DEC00
#define CContextMenu__AddMenuItem_x                                0x8DEC10
#define CContextMenu__RemoveMenuItem_x                             0x8DEF00
#define CContextMenu__RemoveAllMenuItems_x                         0x8DEF20
#define CContextMenuManager__AddMenu_x                             0x8CB080
#define CContextMenuManager__RemoveMenu_x                          0x8CB3C0
#define CContextMenuManager__PopupMenu_x                           0x8CB810
#define CContextMenuManager__Flush_x                               0x8CB0F0
#define CContextMenuManager__GetMenu_x                             0x416A80

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87A070
#define CChatService__GetFriendName_x                              0x87A080

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6919C0
#define CChatWindow__Clear_x                                       0x691590
#define CChatWindow__WndNotification_x                             0x691EF0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CEE40
#define CComboWnd__Draw_x                                          0x8CF050
#define CComboWnd__GetCurChoice_x                                  0x8CEC00
#define CComboWnd__GetListRect_x                                   0x8CF2F0
#define CComboWnd__GetTextRect_x                                   0x8CEEB0
#define CComboWnd__InsertChoice_x                                  0x8CF360
#define CComboWnd__SetColors_x                                     0x8CEB90
#define CComboWnd__SetChoice_x                                     0x8CEBC0
#define CComboWnd__GetItemCount_x                                  0x8CEBF0
#define CComboWnd__GetCurChoiceText_x                              0x8CEC40


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69AEF0
#define CContainerWnd__vftable_x                                   0xADCC78

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B2B80
#define CDisplay__GetClickedActor_x                                0x4AB440
#define CDisplay__GetUserDefinedColor_x                            0x4AA020
#define CDisplay__GetWorldFilePath_x                               0x4A9470
#define CDisplay__is3dON_x                                         0x4A8900
#define CDisplay__ReloadUI_x                                       0x4BE070
#define CDisplay__WriteTextHD2_x                                   0x4AEED0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F5050

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E2F20
#define CEditWnd__GetCharIndexPt_x                                 0x8E3FB0
#define CEditWnd__GetDisplayString_x                               0x8E30D0
#define CEditWnd__GetHorzOffset_x                                  0x8E3410
#define CEditWnd__GetLineForPrintableChar_x                        0x8E3A80
#define CEditWnd__GetSelStartPt_x                                  0x8E4260
#define CEditWnd__GetSTMLSafeText_x                                0x8E35B0
#define CEditWnd__PointFromPrintableChar_x                         0x8E3B70
#define CEditWnd__SelectableCharFromPoint_x                        0x8E3CF0
#define CEditWnd__SetEditable_x                                    0x8E3580

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x556F60
#define CEverQuest__CreateTargetIndicator_x                        0x557E50
#define CEverQuest__DeleteTargetIndicator_x                        0x557ED0
#define CEverQuest__DoTellWindow_x                                 0x4726F0
#define CEverQuest__DropHeldItemOnGround_x                         0x56E000
#define CEverQuest__dsp_chat_x                                     0x472A30
#define CEverQuest__trimName_x                                     0x5538B0
#define CEverQuest__Emote_x                                        0x56C350
#define CEverQuest__EnterZone_x                                    0x567350
#define CEverQuest__GetBodyTypeDesc_x                              0x551310
#define CEverQuest__GetClassDesc_x                                 0x55ABE0
#define CEverQuest__GetClassThreeLetterCode_x                      0x55B1E0
#define CEverQuest__GetDeityDesc_x                                 0x551BF0
#define CEverQuest__GetLangDesc_x                                  0x5516A0
#define CEverQuest__GetRaceDesc_x                                  0x55B3A0
#define CEverQuest__InterpretCmd_x                                 0x55F1B0
#define CEverQuest__LeftClickedOnPlayer_x                          0x572820
#define CEverQuest__LMouseUp_x                                     0x574920
#define CEverQuest__RightClickedOnPlayer_x                         0x573330
#define CEverQuest__RMouseUp_x                                     0x574380
#define CEverQuest__SetGameState_x                                 0x557820
#define CEverQuest__UPCNotificationFlush_x                         0x54F130
#define CEverQuest__IssuePetCommand_x                              0x55FB90

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6ABC90
#define CGaugeWnd__CalcLinesFillRect_x                             0x6ABCF0
#define CGaugeWnd__Draw_x                                          0x6AC120

// CGuild
#define CGuild__FindMemberByName_x                                 0x437480

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C80F0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D5250
#define CInvSlotMgr__MoveItem_x                                    0x6D60F0
#define CInvSlotMgr__SelectSlot_x                                  0x6D5300

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D4700
#define CInvSlot__SliderComplete_x                                 0x6D1F10
#define CInvSlot__GetItemBase_x                                    0x6D13B0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D7510

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79EFA0
#define CItemDisplayWnd__UpdateStrings_x                           0x6D9640

// CLabel 
#define CLabel__Draw_x                                             0x6F2CC0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8BAE60
#define CListWnd__dCListWnd_x                                      0x8BBE90
#define CListWnd__AddColumn_x                                      0x8BBE30
#define CListWnd__AddColumn1_x                                     0x8BB6B0
#define CListWnd__AddLine_x                                        0x8BB120
#define CListWnd__AddString_x                                      0x8BB340
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B8120
#define CListWnd__CalculateVSBRange_x                              0x8BA320
#define CListWnd__ClearSel_x                                       0x8B7430
#define CListWnd__ClearAllSel_x                                    0x8B73E0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8BACF0
#define CListWnd__Compare_x                                        0x8B8C90
#define CListWnd__Draw_x                                           0x8B9F20
#define CListWnd__DrawColumnSeparators_x                           0x8B9DB0
#define CListWnd__DrawHeader_x                                     0x8B76F0
#define CListWnd__DrawItem_x                                       0x8B92E0
#define CListWnd__DrawLine_x                                       0x8B9A50
#define CListWnd__DrawSeparator_x                                  0x8B9E50
#define CListWnd__EnsureVisible_x                                  0x8B8280
#define CListWnd__ExtendSel_x                                      0x8B91F0
#define CListWnd__GetColumnMinWidth_x                              0x8B6DE0
#define CListWnd__GetColumnWidth_x                                 0x8B6D10
#define CListWnd__GetCurSel_x                                      0x8B64E0
#define CListWnd__GetItemAtPoint_x                                 0x8B8520
#define CListWnd__GetItemAtPoint1_x                                0x8B8590
#define CListWnd__GetItemData_x                                    0x8B6820
#define CListWnd__GetItemHeight_x                                  0x8B7D70
#define CListWnd__GetItemIcon_x                                    0x8B6A10
#define CListWnd__GetItemRect_x                                    0x8B8360
#define CListWnd__GetItemText_x                                    0x8B68C0
#define CListWnd__GetSelList_x                                     0x8BB5A0
#define CListWnd__GetSeparatorRect_x                               0x8B8BB0
#define CListWnd__RemoveLine_x                                     0x8BB520
#define CListWnd__SetColors_x                                      0x8B6630
#define CListWnd__SetColumnJustification_x                         0x8B7070
#define CListWnd__SetColumnWidth_x                                 0x8B6D90
#define CListWnd__SetCurSel_x                                      0x8B6520
#define CListWnd__SetItemColor_x                                   0x8BA9E0
#define CListWnd__SetItemData_x                                    0x8B7490
#define CListWnd__SetItemText_x                                    0x8BA820
#define CListWnd__ShiftColumnSeparator_x                           0x8BA6B0
#define CListWnd__Sort_x                                           0x8BBF90
#define CListWnd__ToggleSel_x                                      0x8B7360

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70BE90

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72D220
#define CMerchantWnd__RequestBuyItem_x                             0x734280
#define CMerchantWnd__RequestSellItem_x                            0x734D50
#define CMerchantWnd__SelectRecoverySlot_x                         0x72D4D0
#define CMerchantWnd__SelectBuySellSlot_x                          0x72C6D0
#define CMerchantWnd__ActualSelect_x                               0x731170

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x846BC0
#define CPacketScrambler__hton_x                                   0x846BD0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D9A50
#define CSidlManager__CreateLabel_x                                0x794F30

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x659BA0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x659AC0
#define CSidlScreenWnd__ConvertToRes_x                             0x8F4F30
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D17D0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D2980
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D2A30
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D1F10
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D1180
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D08F0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D1370
#define CSidlScreenWnd__Init1_x                                    0x8D2660
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D1880
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D0AB0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D2150
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D0550
#define CSidlScreenWnd__StoreIniVis_x                              0x8D08A0
#define CSidlScreenWnd__WndNotification_x                          0x8D23E0
#define CSidlScreenWnd__GetChildItem_x                             0x8D09C0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C4330
#define CSidlScreenWnd__m_layoutCopy_x                             0x181AB08

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F77E0
#define CSkillMgr__GetSkillCap_x                                   0x5F79C0
#define CSkillMgr__GetNameToken_x                                  0x5F7400

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F41F0
#define CSliderWnd__SetValue_x                                     0x8F43C0
#define CSliderWnd__SetNumTicks_x                                  0x8F4B40

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79CC00

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EFBA0
#define CStmlWnd__CalculateHSBRange_x                              0x8E80D0
#define CStmlWnd__CalculateVSBRange_x                              0x8E8160
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E82E0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E8BC0
#define CStmlWnd__ForceParseNow_x                                  0x8F04F0
#define CStmlWnd__GetNextTagPiece_x                                0x8E8AC0
#define CStmlWnd__GetSTMLText_x                                    0x690E30
#define CStmlWnd__GetVisibleText_x                                 0x8E9610
#define CStmlWnd__InitializeWindowVariables_x                      0x8EB9A0
#define CStmlWnd__MakeStmlColorTag_x                               0x8E73D0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E7430
#define CStmlWnd__SetSTMLText_x                                    0x8ED200
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EF840
#define CStmlWnd__UpdateHistoryString_x                            0x8EA550

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E6AE0
#define CTabWnd__DrawCurrentPage_x                                 0x8E6370
#define CTabWnd__DrawTab_x                                         0x8E6130
#define CTabWnd__GetCurrentPage_x                                  0x8E6720
#define CTabWnd__GetPageInnerRect_x                                0x8E5E20
#define CTabWnd__GetTabInnerRect_x                                 0x8E6020
#define CTabWnd__GetTabRect_x                                      0x8E5EF0
#define CTabWnd__InsertPage_x                                      0x8E6DD0
#define CTabWnd__SetPage_x                                         0x8E6750
#define CTabWnd__SetPageRect_x                                     0x8E6A20
#define CTabWnd__UpdatePage_x                                      0x8E6D70

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x433000

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CE800

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x630B20

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8FA350

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B46D0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029A0
#define CXStr__CXStr1_x                                            0x8A9480
#define CXStr__CXStr3_x                                            0x892290
#define CXStr__dCXStr_x                                            0x478790
#define CXStr__operator_equal_x                                    0x892400
#define CXStr__operator_equal1_x                                   0x892450
#define CXStr__operator_plus_equal1_x                              0x893550

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C35A0
#define CXWnd__Center_x                                            0x8C9680
#define CXWnd__ClrFocus_x                                          0x8C31A0
#define CXWnd__DoAllDrawing_x                                      0x8C92D0
#define CXWnd__DrawChildren_x                                      0x8C9470
#define CXWnd__DrawColoredRect_x                                   0x8C3930
#define CXWnd__DrawTooltip_x                                       0x8C3BE0
#define CXWnd__DrawTooltipAtPoint_x                                0x8C8260
#define CXWnd__GetBorderFrame_x                                    0x8C4030
#define CXWnd__GetChildWndAt_x                                     0x8CA050
#define CXWnd__GetClientClipRect_x                                 0x8C3DF0
#define CXWnd__GetScreenClipRect_x                                 0x8C8960
#define CXWnd__GetScreenRect_x                                     0x8C41E0
#define CXWnd__GetTooltipRect_x                                    0x8C3A70
#define CXWnd__GetWindowTextA_x                                    0x424650
#define CXWnd__IsActive_x                                          0x8BEC40
#define CXWnd__IsDescendantOf_x                                    0x8C3F80
#define CXWnd__IsReallyVisible_x                                   0x8C7290
#define CXWnd__IsType_x                                            0x8F6B70
#define CXWnd__Move_x                                              0x8C69F0
#define CXWnd__Move1_x                                             0x8C8F80
#define CXWnd__ProcessTransition_x                                 0x8C3540
#define CXWnd__Refade_x                                            0x8C3320
#define CXWnd__Resize_x                                            0x8C42A0
#define CXWnd__Right_x                                             0x8C8760
#define CXWnd__SetFocus_x                                          0x8C5B70
#define CXWnd__SetFont_x                                           0x8C31F0
#define CXWnd__SetKeyTooltip_x                                     0x8C4500
#define CXWnd__SetMouseOver_x                                      0x8C8C90
#define CXWnd__StartFade_x                                         0x8C35F0
#define CXWnd__GetChildItem_x                                      0x8C8BE0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C04D0
#define CXWndManager__DrawWindows_x                                0x8C0120
#define CXWndManager__GetKeyboardFlags_x                           0x8BE7B0
#define CXWndManager__HandleKeyboardMsg_x                          0x8BF0E0
#define CXWndManager__RemoveWnd_x                                  0x8BEDD0

// CDBStr
#define CDBStr__GetString_x                                        0x4A6E30

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44DBA0
#define EQ_Character__Cur_HP_x                                     0x462670
#define EQ_Character__Cur_Mana_x                                   0x4561D0
#define EQ_Character__GetAACastingTimeModifier_x                   0x446DF0
#define EQ_Character__GetCharInfo2_x                               0x866370
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F1A0
#define EQ_Character__GetFocusRangeModifier_x                      0x43F200
#define EQ_Character__Max_Endurance_x                              0x5BDF00
#define EQ_Character__Max_HP_x                                     0x458DF0
#define EQ_Character__Max_Mana_x                                   0x5BDD30
#define EQ_Character__doCombatAbility_x                            0x5BB420
#define EQ_Character__UseSkill_x                                   0x46CAF0
#define EQ_Character__GetConLevel_x                                0x5B0850
#define EQ_Character__IsExpansionFlag_x                            0x423B70
#define EQ_Character__TotalEffect_x                                0x44AE40
#define EQ_Character__GetPCSpellAffect_x                           0x4471F0
#define EQ_Character__SpellDuration_x                              0x4450F0
#define EQ_Character__FindItemByRecord_x                           0x45FB20

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x442440
#define CCharacterSelect__EnterWorld_x                             0x441C10
#define CCharacterSelect__Quit_x                                   0x440800

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x590EE0
#define EQ_Item__CreateItemTagString_x                             0x845500
#define EQ_Item__IsStackable_x                                     0x83AE10
#define EQ_Item__GetImageNum_x                                     0x83D850
#define EQ_Item__CreateItemClient_x                                0x591AC0
#define EQ_Item__GetItemValue_x                                    0x844230
#define EQ_Item__ValueSellMerchant_x                               0x846810
#define EQ_Item__IsKeyRingItem_x                                   0x83B840
#define EQ_Item__CanGoInBag_x                                      0x591070
#define EQ_Item__GetMaxItemCount_x                                 0x83AA90
#define EQ_Item__GetHeldItem_x                                     0x83C670

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C66F0
#define EQ_LoadingS__Array_x                                       0xC1B728

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C0420
#define EQ_PC__GetAlternateAbilityId_x                             0x84EBE0
#define EQ_PC__GetCombatAbility_x                                  0x84EC70
#define EQ_PC__GetCombatAbilityTimer_x                             0x8499E0
#define EQ_PC__GetItemTimerValue_x                                 0x5B9AD0
#define EQ_PC__HasLoreItem_x                                       0x5B3D60
#define EQ_PC__AlertInventoryChanged_x                             0x5B0820
#define EQ_PC__GetPcZoneClient_x                                   0x5DAB80
#define EQ_PC__RemoveMyAffect_x                                    0x5B8F80
#define EQ_PC__GetKeyRingItems_x                                   0x849E00

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50F4A0
#define EQItemList__add_object_x                                   0x53BC30
#define EQItemList__add_item_x                                     0x50F3E0
#define EQItemList__delete_item_x                                  0x50F890
#define EQItemList__FreeItemList_x                                 0x50F790

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A6140

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C5AC0
#define EQPlayer__dEQPlayer_x                                      0x5CE8F0
#define EQPlayer__DoAttack_x                                       0x5E08B0
#define EQPlayer__EQPlayer_x                                       0x5D0D10
#define EQPlayer__SetNameSpriteState_x                             0x5CB890
#define EQPlayer__SetNameSpriteTint_x                              0x5C6F00
#define PlayerBase__HasProperty_j_x                                0x927A20
#define EQPlayer__IsTargetable_x                                   0x928320
#define EQPlayer__CanSee_x                                         0x928840
#define PlayerZoneClient__ChangeHeight_x                           0x5E0770
#define EQPlayer__CanSeeTargetIndicator_x                          0x928930
#define PlayerBase__GetVisibilityLineSegment_x                     0x9285D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D5050
#define EQPlayerManager__GetSpawnByName_x                          0x5D54B0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D5080

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x596F40
#define KeypressHandler__AttachKeyToEqCommand_x                    0x596F80
#define KeypressHandler__ClearCommandStateArray_x                  0x596B30
#define KeypressHandler__HandleKeyDown_x                           0x595490
#define KeypressHandler__HandleKeyUp_x                             0x5957B0
#define KeypressHandler__SaveKeymapping_x                          0x596C00

// MapViewMap 
#define MapViewMap__Clear_x                                        0x704820
#define MapViewMap__SaveEx_x                                       0x707B50

#define PlayerPointManager__GetAltCurrency_x                       0x8612B0

// StringTable 
#define StringTable__getString_x                                   0x85BF40

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BD990
#define PcZoneClient__RemovePetEffect_x                            0x5B9FA0
#define PcZoneClient__HasAlternateAbility_x                        0x5BA940
#define PcZoneClient__GetCurrentMod_x                              0x458190
#define PcZoneClient__GetModCap_x                                  0x455950
#define PcZoneClient__CanEquipItem_x                               0x5BAEF0

//Doors
#define EQSwitch__UseSwitch_x                                      0x54DA90

//IconCache
#define IconCache__GetIcon_x                                       0x6A1480

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x698290
#define CContainerMgr__CloseContainer_x                            0x698AB0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x765130

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58A160

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DE400
#define EQ_Spell__SpellAffects_x                                   0x4DBAB0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DBB20
#define CharacterZoneClient__CalcAffectChange_x                    0x446220
#define CLootWnd__LootAll_x                                        0x6FA040
#define CLootWnd__RequestLootSlot_x                                0x6FA850

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AB9C0
#define CTargetWnd__WndNotification_x                              0x7AB4B0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7ABBA0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B0B90

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D7390

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x495F90

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E2550
#define CSidlManager__FindAnimation1_x                             0x8D7950

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CDD40
#define CAltAbilityData__GetMercMaxRank_x                          0x4CDCF0
#define CAltAbilityData__GetMaxRank_x                              0x4C2CB0

//CTargetRing
#define CTargetRing__Cast_x                                        0x587A30

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x454A70
#define CharacterBase__CreateItemGlobalIndex_x                     0x4718C0
#define CharacterBase__CreateItemIndex_x                           0x5087F0
#define CharacterBase__GetItemPossession_x                         0x509CD0
#define CharacterBase__GetItemByGlobalIndex_x                      0x874190

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x682C90
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6823F0

//messages
#define msg_spell_worn_off_x                                       0x4E5E60
#define msg_new_text_x                                             0x4EF2B0
#define msgTokenTextParam_x                                        0x4EBC90

//SpellManager
#define SpellManager__vftable_x                                    0xAB8F30
#define SpellManager__SpellManager_x                               0x47A6A0
#define Spellmanager__CheckSpellRequirementAssociations_x          0x5FE6C0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x92C360

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E2400
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43A860
#define ItemGlobalIndex__IsEquippedLocation_x                      0x444AC0
#define ItemGlobalIndex__IsValidIndex_x                            0x4542E0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x871FB0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x870EF0






