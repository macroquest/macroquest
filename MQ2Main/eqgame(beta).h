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
#define __ExpectedVersionDate                                     "Oct 11 2016"
#define __ExpectedVersionTime                                     "04:15:44"
#define __ActualVersionDate_x                                      0xAD06B8
#define __ActualVersionTime_x                                      0xAD06C4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5A0640
#define __MemChecker1_x                                            0x897490
#define __MemChecker2_x                                            0x636BE0
#define __MemChecker3_x                                            0x636B30
#define __MemChecker4_x                                            0x7E9650
#define __EncryptPad0_x                                            0xC74450
#define __EncryptPad1_x                                            0xE00E18
#define __EncryptPad2_x                                            0xCBD250
#define __EncryptPad3_x                                            0xCBCE50
#define __EncryptPad4_x                                            0xDD6A20
#define __EncryptPad5_x                                            0x11B1C98
#define __AC1_x                                                    0x7A8FA5
#define __AC2_x                                                    0x55A4A7
#define __AC3_x                                                    0x558640
#define __AC4_x                                                    0x56AEB0
#define __AC5_x                                                    0x57DB4B
#define __AC6_x                                                    0x5816FE
#define __AC7_x                                                    0x5781CC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E7620

// Direct Input
#define DI8__Main_x                                                0x11B1C70
#define DI8__Keyboard_x                                            0x11B1C74
#define DI8__Mouse_x                                               0x11B1C78
#define DI8__Mouse_Copy_x                                          0x102035C
#define DI8__Mouse_Check_x                                         0x10A9B5C
#define __Attack_x                                                 0x10A4843
#define __Autofire_x                                               0x10A4844
#define __BindList_x                                               0xC35D90
#define g_eqCommandStates_x                                        0x100F3E8
#define __Clicks_x                                                 0x1020418
#define __CommandList_x                                            0xC3A190
#define __CurrentMapLabel_x                                        0x11B76F8
#define __CurrentSocial_x                                          0xBE8194
#define __DoAbilityList_x                                          0x1056AF8
#define __do_loot_x                                                0x51F9B0
#define __DrawHandler_x                                            0x181E6DC
#define __GroupCount_x                                             0x10109B2

#define __Guilds_x                                                 0x10165C8
#define __gWorld_x                                                 0x1012E6C
#define __HotkeyPage_x                                             0x109D4F8
#define __HWnd_x                                                   0x10A9B78
#define __InChatMode_x                                             0x1020344
#define __LastTell_x                                               0x10221F4
#define __LMouseHeldTime_x                                         0x1020484
#define __Mouse_x                                                  0x11B1C7C
#define __MouseLook_x                                              0x10203DE
#define __MouseEventTime_x                                         0x10A5044
#define __gpbCommandEvent_x                                        0x1012F34
#define __NetStatusToggle_x                                        0x10203E1
#define __PCNames_x                                                0x1021810
#define __RangeAttackReady_x                                       0x102154C
#define __RMouseHeldTime_x                                         0x1020480
#define __RunWalkState_x                                           0x1020348
#define __ScreenMode_x                                             0xF5F0E8
#define __ScreenX_x                                                0x10202FC
#define __ScreenY_x                                                0x10202F8
#define __ScreenXMax_x                                             0x1020300
#define __ScreenYMax_x                                             0x1020304
#define __ServerHost_x                                             0x10108FC
#define __ServerName_x                                             0x1056AB8
#define __ShiftKeyDown_x                                           0x10209D8
#define __ShowNames_x                                              0x102170C
#define __Socials_x                                                0x1056BB8
#define __SubscriptionType_x                                       0x11E5824
#define __TargetAggroHolder_x                                      0x11B9934
#define __ZoneType_x                                               0x10207DC
#define __GroupAggro_x                                             0x11B9974
#define __LoginName_x                                              0x10A8754
#define __Inviter_x                                                0x10A47C0
#define __AttackOnAssist_x                                         0x10216C8
#define __UseTellWindows_x                                         0x10219A8

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x1012F58
#define instEQZoneInfo_x                                           0x10205D4
#define instKeypressHandler_x                                      0x10A5028
#define pinstActiveBanker_x                                        0x1012F10
#define pinstActiveCorpse_x                                        0x1012F14
#define pinstActiveGMaster_x                                       0x1012F18
#define pinstActiveMerchant_x                                      0x1012F0C
#define pinstAggroInfo_x                                           0xE1CB48
#define pinstAltAdvManager_x                                       0xF601B0
#define pinstAuraMgr_x                                             0xE2D2B8
#define pinstBandageTarget_x                                       0x1012EF8
#define pinstCamActor_x                                            0xF5FB00
#define pinstCDBStr_x                                              0xF5F07C
#define pinstCDisplay_x                                            0x1012F20
#define pinstCEverQuest_x                                          0x11B1DF0
#define pinstCharData_x                                            0x1012EDC
#define pinstCharSpawn_x                                           0x1012F04
#define pinstControlledMissile_x                                   0x1012ED8
#define pinstControlledPlayer_x                                    0x1012F04
#define pinstCSidlManager_x                                        0x181DACC
#define pinstCXWndManager_x                                        0x181DAC4
#define instDynamicZone_x                                          0x1020190
#define pinstDZMember_x                                            0x10202A0
#define pinstDZTimerInfo_x                                         0x10202A4
#define pinstEQItemList_x                                          0x100F638
#define pinstEQObjectList_x                                        0x10103AC
#define instEQMisc_x                                               0xC0EDD0
#define pinstEQSoundManager_x                                      0xF60780
#define instExpeditionLeader_x                                     0x10201DA
#define instExpeditionName_x                                       0x102021A
#define pinstGroup_x                                               0x10109AE
#define pinstImeManager_x                                          0x181DAD0
#define pinstLocalPlayer_x                                         0x1012EF0
#define pinstMercenaryData_x                                       0x10A56A8
#define pinstMercenaryStats_x                                      0x11B9A80
#define pinstMercAltAbilities_x                                    0xF60538
#define pinstModelPlayer_x                                         0x1012F1C
#define pinstPCData_x                                              0x1012EDC
#define pinstSkillMgr_x                                            0x10A6510
#define pinstSpawnManager_x                                        0x10A5DF8
#define pinstSpellManager_x                                        0x10A6658
#define pinstSpellSets_x                                           0x109D55C
#define pinstStringTable_x                                         0x1012E84
#define pinstSwitchManager_x                                       0x1010540
#define pinstTarget_x                                              0x1012F08
#define pinstTargetObject_x                                        0x1012EE0
#define pinstTargetSwitch_x                                        0x1012EE4
#define pinstTaskMember_x                                          0xF5EFC8
#define pinstTrackTarget_x                                         0x1012EFC
#define pinstTradeTarget_x                                         0x1012EEC
#define instTributeActive_x                                        0xC0EDF5
#define pinstViewActor_x                                           0xF5FAFC
#define pinstWorldData_x                                           0x1012EC0
#define pinstZoneAddr_x                                            0x1020874
#define pinstPlayerPath_x                                          0x10A5E58
#define pinstTargetIndicator_x                                     0x10A67F0
#define pinstCTargetManager_x                                      0x10A6850

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE1D040
#define pinstCAudioTriggersWindow_x                                0xE1CED0
#define pinstCCharacterSelect_x                                    0xF5F98C
#define pinstCFacePick_x                                           0xF5F73C
#define pinstCNoteWnd_x                                            0xF5F944
#define pinstCBookWnd_x                                            0xF5F94C
#define pinstCPetInfoWnd_x                                         0xF5F950
#define pinstCTrainWnd_x                                           0xF5F954
#define pinstCSkillsWnd_x                                          0xF5F958
#define pinstCSkillsSelectWnd_x                                    0xF5F95C
#define pinstCCombatSkillsSelectWnd_x                              0xF5F960
#define pinstCFriendsWnd_x                                         0xF5F964
#define pinstCAuraWnd_x                                            0xF5F968
#define pinstCRespawnWnd_x                                         0xF5F96C
#define pinstCBandolierWnd_x                                       0xF5F970
#define pinstCPotionBeltWnd_x                                      0xF5F974
#define pinstCAAWnd_x                                              0xF5F978
#define pinstCAlarmWnd_x                                           0xF5F984
#define pinstCGroupSearchFiltersWnd_x                              0xF5F97C
#define pinstCLoadskinWnd_x                                        0xF5F980
#define pinstCLargeDialogWnd_x                                     0x11B8978
#define pinstCMusicPlayerWnd_x                                     0xF5F988
#define pinstCMailWnd_x                                            0xF5F990
#define pinstCMailCompositionWnd_x                                 0xF5F994
#define pinstCMailAddressBookWnd_x                                 0xF5F998
#define pinstCRaidWnd_x                                            0xF5F9A0
#define pinstCRaidOptionsWnd_x                                     0xF5F9A4
#define pinstCBreathWnd_x                                          0xF5F9A8
#define pinstCMapViewWnd_x                                         0xF5F9AC
#define pinstCMapToolbarWnd_x                                      0xF5F9B0
#define pinstCEditLabelWnd_x                                       0xF5F9B4
#define pinstCTargetWnd_x                                          0xF5F9B8
#define pinstCColorPickerWnd_x                                     0xF5F9BC
#define pinstCPlayerWnd_x                                          0xF5F9C0
#define pinstCOptionsWnd_x                                         0xF5F9C4
#define pinstCBuffWindowNORMAL_x                                   0xF5F9C8
#define pinstCBuffWindowSHORT_x                                    0xF5F9CC
#define pinstCharacterCreation_x                                   0xF5F9D0
#define pinstCCursorAttachment_x                                   0xF5F9D4
#define pinstCCastingWnd_x                                         0xF5F9D8
#define pinstCCastSpellWnd_x                                       0xF5F9DC
#define pinstCSpellBookWnd_x                                       0xF5F9E0
#define pinstCInventoryWnd_x                                       0xF5F9E4
#define pinstCBankWnd_x                                            0xF5F9EC
#define pinstCQuantityWnd_x                                        0xF5F9F0
#define pinstCLootWnd_x                                            0xF5F9F4
#define pinstCActionsWnd_x                                         0xF5F9F8
#define pinstCCombatAbilityWnd_x                                   0xF5FA00
#define pinstCMerchantWnd_x                                        0xF5FA04
#define pinstCTradeWnd_x                                           0xF5FA08
#define pinstCSelectorWnd_x                                        0xF5FA0C
#define pinstCBazaarWnd_x                                          0xF5FA10
#define pinstCBazaarSearchWnd_x                                    0xF5FA14
#define pinstCGiveWnd_x                                            0xF5FA30
#define pinstCTrackingWnd_x                                        0xF5FA38
#define pinstCInspectWnd_x                                         0xF5FA3C
#define pinstCSocialEditWnd_x                                      0xF5FA40
#define pinstCFeedbackWnd_x                                        0xF5FA44
#define pinstCBugReportWnd_x                                       0xF5FA48
#define pinstCVideoModesWnd_x                                      0xF5FA4C
#define pinstCTextEntryWnd_x                                       0xF5FA54
#define pinstCFileSelectionWnd_x                                   0xF5FA58
#define pinstCCompassWnd_x                                         0xF5FA5C
#define pinstCPlayerNotesWnd_x                                     0xF5FA60
#define pinstCGemsGameWnd_x                                        0xF5FA64
#define pinstCTimeLeftWnd_x                                        0xF5FA68
#define pinstCPetitionQWnd_x                                       0xF5FA84
#define pinstCSoulmarkWnd_x                                        0xF5FA88
#define pinstCStoryWnd_x                                           0xF5FA8C
#define pinstCJournalTextWnd_x                                     0xF5FA90
#define pinstCJournalCatWnd_x                                      0xF5FA94
#define pinstCBodyTintWnd_x                                        0xF5FA98
#define pinstCServerListWnd_x                                      0xF5FA9C
#define pinstCAvaZoneWnd_x                                         0xF5FAA8
#define pinstCBlockedBuffWnd_x                                     0xF5FAAC
#define pinstCBlockedPetBuffWnd_x                                  0xF5FAB0
#define pinstCInvSlotMgr_x                                         0xF5FAF4
#define pinstCContainerMgr_x                                       0xF5FAF8
#define pinstCAdventureLeaderboardWnd_x                            0x11B27A0
#define pinstCAdventureRequestWnd_x                                0x11B2818
#define pinstCAltStorageWnd_x                                      0x11B2AF8
#define pinstCAdventureStatsWnd_x                                  0x11B2890
#define pinstCBarterMerchantWnd_x                                  0x11B36E0
#define pinstCBarterSearchWnd_x                                    0x11B3758
#define pinstCBarterWnd_x                                          0x11B37D0
#define pinstCChatManager_x                                        0x11B3E60
#define pinstCDynamicZoneWnd_x                                     0x11B4310
#define pinstCEQMainWnd_x                                          0x11B44A8
#define pinstCFellowshipWnd_x                                      0x11B42A4
#define pinstCFindLocationWnd_x                                    0x11B4778
#define pinstCGroupSearchWnd_x                                     0x11B4A48
#define pinstCGroupWnd_x                                           0x11B4AC0
#define pinstCGuildBankWnd_x                                       0x11B4B38
#define pinstCGuildMgmtWnd_x                                       0x11B6C28
#define pinstCHotButtonWnd_x                                       0x11B6D24
#define pinstCHotButtonWnd1_x                                      0x11B6D24
#define pinstCHotButtonWnd2_x                                      0x11B6D28
#define pinstCHotButtonWnd3_x                                      0x11B6D2C
#define pinstCHotButtonWnd4_x                                      0x11B6D50
#define pinstCItemDisplayManager_x                                 0x11B7048
#define pinstCItemExpTransferWnd_x                                 0x11B70C4
#define pinstCLFGuildWnd_x                                         0x11B73A0
#define pinstCMIZoneSelectWnd_x                                    0x11B7988
#define pinstCConfirmationDialog_x                                 0x11B8090
#define pinstCPopupWndManager_x                                    0x11B8090
#define pinstCProgressionSelectionWnd_x                            0x11B8180
#define pinstCPvPStatsWnd_x                                        0x11B8270
#define pinstCTaskWnd_x                                            0x11B9D40
#define pinstCTaskSomething_x                                      0xE2DB70
#define pinstCTaskTemplateSelectWnd_x                              0x11B9CC8
#define pinstCTipWndOFDAY_x                                        0x11B9EA8
#define pinstCTipWndCONTEXT_x                                      0x11B9EAC
#define pinstCTitleWnd_x                                           0x11B9F28
#define pinstCContextMenuManager_x                                 0x181DA3C
#define pinstCVoiceMacroWnd_x                                      0x10A6C28
#define pinstCHtmlWnd_x                                            0x10A6D18
#define pinstIconCache_x                                           0x11B447C
#define pinstCTradeskillWnd_x                                      0x11BA028
#define pinstCAdvancedLootWnd_x                                    0xF5FAE8
#define pinstRewardSelectionWnd_x                                  0x11B8798

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x536C50
#define __ConvertItemTags_x                                        0x524510
#define __ExecuteCmd_x                                             0x50EDC0
#define __EQGetTime_x                                              0x897120
#define __get_melee_range_x                                        0x5159A0
#define __GetGaugeValueFromEQ_x                                    0x7A7CE0
#define __GetLabelFromEQ_x                                         0x7A8F30
#define __ToggleKeyRingItem_x                                      0x47FAE0
#define __GetXTargetType_x                                         0x9283E0
#define __LoadFrontEnd_x                                           0x6362B0
#define __NewUIINI_x                                               0x7A76B0
#define __ProcessGameEvents_x                                      0x579F60
#define __ProcessMouseEvent_x                                      0x579700
#define CrashDetected_x                                            0x637C70
#define wwsCrashReportCheckForUploader_x                           0x7F7EE0
#define DrawNetStatus_x                                            0x5B0140
#define Util__FastTime_x                                           0x896DC0
#define Expansion_HoT_x                                            0x10216B8
#define __HelpPath_x                                               0x10A4DB0
#define __STMLToText_x                                             0x8DCFD0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420310
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B0B0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41AE90

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C7060
#define AltAdvManager__IsAbilityReady_x                            0x4C70D0
#define AltAdvManager__GetAAById_x                                 0x4C7490
#define AltAdvManager__CanTrainAbility_x                           0x4C7D90
#define AltAdvManager__CanSeeAbility_x                             0x4C7950

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x462F80
#define CharacterZoneClient__MakeMeVisible_x                       0x467A20
#define CharacterZoneClient__IsStackBlocked_x                      0x447590
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x446A50
#define CharacterZoneClient__GetItemCountWorn_x                    0x460DB0
#define CharacterZoneClient__GetItemCountInInventory_x             0x460E90
#define CharacterZoneClient__GetCursorItemCount_x                  0x460F70

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x666080

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6745B0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58F670
#define CButtonWnd__CButtonWnd_x                                   0x8D13A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68F600
#define CChatManager__InitContextMenu_x                            0x690180

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DB330
#define CContextMenu__dCContextMenu_x                              0x8DB540
#define CContextMenu__AddMenuItem_x                                0x8DB550
#define CContextMenu__RemoveMenuItem_x                             0x8DB840
#define CContextMenu__RemoveAllMenuItems_x                         0x8DB860
#define CContextMenuManager__AddMenu_x                             0x8C7910
#define CContextMenuManager__RemoveMenu_x                          0x8C7CB0
#define CContextMenuManager__PopupMenu_x                           0x8C8100
#define CContextMenuManager__Flush_x                               0x8C7980
#define CContextMenuManager__GetMenu_x                             0x416790

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87BAC0
#define CChatService__GetFriendName_x                              0x87BAD0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6953D0
#define CChatWindow__Clear_x                                       0x694FB0
#define CChatWindow__WndNotification_x                             0x695910

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CB770
#define CComboWnd__Draw_x                                          0x8CB980
#define CComboWnd__GetCurChoice_x                                  0x8CB520
#define CComboWnd__GetListRect_x                                   0x8CBC20
#define CComboWnd__GetTextRect_x                                   0x8CB7E0
#define CComboWnd__InsertChoice_x                                  0x8CBC90
#define CComboWnd__SetColors_x                                     0x8CB4B0
#define CComboWnd__SetChoice_x                                     0x8CB4E0
#define CComboWnd__GetItemCount_x                                  0x8CB510
#define CComboWnd__GetCurChoiceText_x                              0x8CB560


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69EAA0
#define CContainerWnd__vftable_x                                   0xADA1D0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B54C0
#define CDisplay__GetClickedActor_x                                0x4ADD90
#define CDisplay__GetUserDefinedColor_x                            0x4AC970
#define CDisplay__GetWorldFilePath_x                               0x4ABDC0
#define CDisplay__is3dON_x                                         0x4AB250
#define CDisplay__ReloadUI_x                                       0x4C0A30
#define CDisplay__WriteTextHD2_x                                   0x4B1810

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F19F0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DF860
#define CEditWnd__GetCharIndexPt_x                                 0x8E08F0
#define CEditWnd__GetDisplayString_x                               0x8DFA10
#define CEditWnd__GetHorzOffset_x                                  0x8DFD50
#define CEditWnd__GetLineForPrintableChar_x                        0x8E03C0
#define CEditWnd__GetSelStartPt_x                                  0x8E0BA0
#define CEditWnd__GetSTMLSafeText_x                                0x8DFEF0
#define CEditWnd__PointFromPrintableChar_x                         0x8E04B0
#define CEditWnd__SelectableCharFromPoint_x                        0x8E0630
#define CEditWnd__SetEditable_x                                    0x8DFEC0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x55ABF0
#define CEverQuest__CreateTargetIndicator_x                        0x55BAE0
#define CEverQuest__DeleteTargetIndicator_x                        0x55BB60
#define CEverQuest__DoTellWindow_x                                 0x472650
#define CEverQuest__DropHeldItemOnGround_x                         0x571D00
#define CEverQuest__dsp_chat_x                                     0x472990
#define CEverQuest__trimName_x                                     0x557540
#define CEverQuest__Emote_x                                        0x570050
#define CEverQuest__EnterZone_x                                    0x56B040
#define CEverQuest__GetBodyTypeDesc_x                              0x554FA0
#define CEverQuest__GetClassDesc_x                                 0x55E870
#define CEverQuest__GetClassThreeLetterCode_x                      0x55EE70
#define CEverQuest__GetDeityDesc_x                                 0x555880
#define CEverQuest__GetLangDesc_x                                  0x555330
#define CEverQuest__GetRaceDesc_x                                  0x55F030
#define CEverQuest__InterpretCmd_x                                 0x562E60
#define CEverQuest__LeftClickedOnPlayer_x                          0x576620
#define CEverQuest__LMouseUp_x                                     0x578720
#define CEverQuest__RightClickedOnPlayer_x                         0x577130
#define CEverQuest__RMouseUp_x                                     0x578180
#define CEverQuest__SetGameState_x                                 0x55B4B0
#define CEverQuest__UPCNotificationFlush_x                         0x552DB0
#define CEverQuest__IssuePetCommand_x                              0x563840

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AF9A0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AFA00
#define CGaugeWnd__Draw_x                                          0x6AFE30

// CGuild
#define CGuild__FindMemberByName_x                                 0x436F60

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CBED0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D9080
#define CInvSlotMgr__MoveItem_x                                    0x6D9F30
#define CInvSlotMgr__SelectSlot_x                                  0x6D9130

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D8530
#define CInvSlot__SliderComplete_x                                 0x6D5D40
#define CInvSlot__GetItemBase_x                                    0x6D51C0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DB390

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A36E0
#define CItemDisplayWnd__UpdateStrings_x                           0x6DD4C0

// CLabel 
#define CLabel__Draw_x                                             0x6F6B60

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B73A0
#define CListWnd__dCListWnd_x                                      0x8B85C0
#define CListWnd__AddColumn_x                                      0x8B8560
#define CListWnd__AddColumn1_x                                     0x8B7C00
#define CListWnd__AddLine_x                                        0x8B7660
#define CListWnd__AddString_x                                      0x8B7880
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B4630
#define CListWnd__CalculateVSBRange_x                              0x8B6870
#define CListWnd__ClearSel_x                                       0x8B3950
#define CListWnd__ClearAllSel_x                                    0x8B3900
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B7230
#define CListWnd__Compare_x                                        0x8B51A0
#define CListWnd__Draw_x                                           0x8B6470
#define CListWnd__DrawColumnSeparators_x                           0x8B6300
#define CListWnd__DrawHeader_x                                     0x8B3C10
#define CListWnd__DrawItem_x                                       0x8B5830
#define CListWnd__DrawLine_x                                       0x8B5FA0
#define CListWnd__DrawSeparator_x                                  0x8B63A0
#define CListWnd__EnsureVisible_x                                  0x8B4790
#define CListWnd__ExtendSel_x                                      0x8B5740
#define CListWnd__GetColumnMinWidth_x                              0x8B3300
#define CListWnd__GetColumnWidth_x                                 0x8B3230
#define CListWnd__GetCurSel_x                                      0x8B2A00
#define CListWnd__GetItemAtPoint_x                                 0x8B4A20
#define CListWnd__GetItemAtPoint1_x                                0x8B4A90
#define CListWnd__GetItemData_x                                    0x8B2D50
#define CListWnd__GetItemHeight_x                                  0x8B4290
#define CListWnd__GetItemIcon_x                                    0x8B2F40
#define CListWnd__GetItemRect_x                                    0x8B4860
#define CListWnd__GetItemText_x                                    0x8B2DF0
#define CListWnd__GetSelList_x                                     0x8B7AF0
#define CListWnd__GetSeparatorRect_x                               0x8B50C0
#define CListWnd__RemoveLine_x                                     0x8B7A70
#define CListWnd__SetColors_x                                      0x8B2B50
#define CListWnd__SetColumnJustification_x                         0x8B3590
#define CListWnd__SetColumnWidth_x                                 0x8B32B0
#define CListWnd__SetCurSel_x                                      0x8B2A40
#define CListWnd__SetItemColor_x                                   0x8B6F20
#define CListWnd__SetItemData_x                                    0x8B39B0
#define CListWnd__SetItemText_x                                    0x8B6D60
#define CListWnd__ShiftColumnSeparator_x                           0x8B6BF0
#define CListWnd__Sort_x                                           0x8B86C0
#define CListWnd__ToggleSel_x                                      0x8B3880

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70FCB0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x731110
#define CMerchantWnd__RequestBuyItem_x                             0x7381C0
#define CMerchantWnd__RequestSellItem_x                            0x738C90
#define CMerchantWnd__SelectRecoverySlot_x                         0x7313C0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7305C0
#define CMerchantWnd__ActualSelect_x                               0x735090

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x84B320
#define CPacketScrambler__hton_x                                   0x84B330

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D6320
#define CSidlManager__CreateLabel_x                                0x799620

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65D390
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65D2C0
#define CSidlScreenWnd__ConvertToRes_x                             0x8F18D0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CE110
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CF2E0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CF390
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CE860
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CDAC0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CD230
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CDCB0
#define CSidlScreenWnd__Init1_x                                    0x8CEFB0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CE1C0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CD3F0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CEAA0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CCE90
#define CSidlScreenWnd__StoreIniVis_x                              0x8CD1E0
#define CSidlScreenWnd__WndNotification_x                          0x8CED30
#define CSidlScreenWnd__GetChildItem_x                             0x8CD300
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C0AC0
#define CSidlScreenWnd__m_layoutCopy_x                             0x181DAA0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FBC60
#define CSkillMgr__GetSkillCap_x                                   0x5FBE40
#define CSkillMgr__GetNameToken_x                                  0x5FB880

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F0B80
#define CSliderWnd__SetValue_x                                     0x8F0D50
#define CSliderWnd__SetNumTicks_x                                  0x8F14D0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A1340

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EC4B0
#define CStmlWnd__CalculateHSBRange_x                              0x8E4A00
#define CStmlWnd__CalculateVSBRange_x                              0x8E4A80
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E4C00
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E54E0
#define CStmlWnd__ForceParseNow_x                                  0x8ECE70
#define CStmlWnd__GetNextTagPiece_x                                0x8E53E0
#define CStmlWnd__GetSTMLText_x                                    0x694850
#define CStmlWnd__GetVisibleText_x                                 0x8E5F30
#define CStmlWnd__InitializeWindowVariables_x                      0x8E82B0
#define CStmlWnd__MakeStmlColorTag_x                               0x8E3D00
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E3D60
#define CStmlWnd__SetSTMLText_x                                    0x8E9B00
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EC150
#define CStmlWnd__UpdateHistoryString_x                            0x8E6E70

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E3410
#define CTabWnd__DrawCurrentPage_x                                 0x8E2CA0
#define CTabWnd__DrawTab_x                                         0x8E2A60
#define CTabWnd__GetCurrentPage_x                                  0x8E3050
#define CTabWnd__GetPageInnerRect_x                                0x8E2750
#define CTabWnd__GetTabInnerRect_x                                 0x8E2950
#define CTabWnd__GetTabRect_x                                      0x8E2820
#define CTabWnd__InsertPage_x                                      0x8E3700
#define CTabWnd__SetPage_x                                         0x8E3080
#define CTabWnd__SetPageRect_x                                     0x8E3350
#define CTabWnd__UpdatePage_x                                      0x8E36A0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432B10

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CB120

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x634550

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F6CE0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B0BA0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029B0
#define CXStr__CXStr1_x                                            0x7433D0
#define CXStr__CXStr3_x                                            0x8940A0
#define CXStr__dCXStr_x                                            0x478740
#define CXStr__operator_equal_x                                    0x894210
#define CXStr__operator_equal1_x                                   0x894260
#define CXStr__operator_plus_equal1_x                              0x895360

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BFCA0
#define CXWnd__Center_x                                            0x8C5EE0
#define CXWnd__ClrFocus_x                                          0x8BF880
#define CXWnd__DoAllDrawing_x                                      0x8C5B30
#define CXWnd__DrawChildren_x                                      0x8C5CD0
#define CXWnd__DrawColoredRect_x                                   0x8C0070
#define CXWnd__DrawTooltip_x                                       0x8C0310
#define CXWnd__DrawTooltipAtPoint_x                                0x8C4AB0
#define CXWnd__GetBorderFrame_x                                    0x8C0780
#define CXWnd__GetChildWndAt_x                                     0x8C68A0
#define CXWnd__GetClientClipRect_x                                 0x8C0530
#define CXWnd__GetScreenClipRect_x                                 0x8C51B0
#define CXWnd__GetScreenRect_x                                     0x8C0950
#define CXWnd__GetTooltipRect_x                                    0x8C01A0
#define CXWnd__GetWindowTextA_x                                    0x424270
#define CXWnd__IsActive_x                                          0x8BB370
#define CXWnd__IsDescendantOf_x                                    0x8C06C0
#define CXWnd__IsReallyVisible_x                                   0x8C3AE0
#define CXWnd__IsType_x                                            0x8F3540
#define CXWnd__Move_x                                              0x8C31C0
#define CXWnd__Move1_x                                             0x8C57D0
#define CXWnd__ProcessTransition_x                                 0x8BFC40
#define CXWnd__Refade_x                                            0x8BFA20
#define CXWnd__Resize_x                                            0x8C0A20
#define CXWnd__Right_x                                             0x8C4FB0
#define CXWnd__SetFocus_x                                          0x8C22F0
#define CXWnd__SetFont_x                                           0x8BF8D0
#define CXWnd__SetKeyTooltip_x                                     0x8C0C90
#define CXWnd__SetMouseOver_x                                      0x8C54C0
#define CXWnd__StartFade_x                                         0x8BFCF0
#define CXWnd__GetChildItem_x                                      0x8C5400

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BCBF0
#define CXWndManager__DrawWindows_x                                0x8BC830
#define CXWndManager__GetKeyboardFlags_x                           0x8BAEA0
#define CXWndManager__HandleKeyboardMsg_x                          0x8BB800
#define CXWndManager__RemoveWnd_x                                  0x8BB500

// CDBStr
#define CDBStr__GetString_x                                        0x4A9700

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44DB30
#define EQ_Character__Cur_HP_x                                     0x462620
#define EQ_Character__Cur_Mana_x                                   0x456130
#define EQ_Character__GetAACastingTimeModifier_x                   0x446D60
#define EQ_Character__GetCharInfo2_x                               0x867A70
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EFF0
#define EQ_Character__GetFocusRangeModifier_x                      0x43F050
#define EQ_Character__Max_Endurance_x                              0x5C1FD0
#define EQ_Character__Max_HP_x                                     0x458D50
#define EQ_Character__Max_Mana_x                                   0x5C1E00
#define EQ_Character__doCombatAbility_x                            0x5BF4F0
#define EQ_Character__UseSkill_x                                   0x46CAA0
#define EQ_Character__GetConLevel_x                                0x5B47C0
#define EQ_Character__IsExpansionFlag_x                            0x4237C0
#define EQ_Character__TotalEffect_x                                0x44ADC0
#define EQ_Character__GetPCSpellAffect_x                           0x447160
#define EQ_Character__SpellDuration_x                              0x445060
#define EQ_Character__FindItemByRecord_x                           0x45FA80

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x442380
#define CCharacterSelect__EnterWorld_x                             0x441B50
#define CCharacterSelect__Quit_x                                   0x440730

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x594EA0
#define EQ_Item__CreateItemTagString_x                             0x849CF0
#define EQ_Item__IsStackable_x                                     0x83F710
#define EQ_Item__GetImageNum_x                                     0x842160
#define EQ_Item__CreateItemClient_x                                0x595A80
#define EQ_Item__GetItemValue_x                                    0x8489C0
#define EQ_Item__ValueSellMerchant_x                               0x84AFB0
#define EQ_Item__IsKeyRingItem_x                                   0x840150
#define EQ_Item__CanGoInBag_x                                      0x595030
#define EQ_Item__GetMaxItemCount_x                                 0x83F600
#define EQ_Item__GetHeldItem_x                                     0x840F60

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C91E0
#define EQ_LoadingS__Array_x                                       0xC1B680

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C44F0
#define EQ_PC__GetAlternateAbilityId_x                             0x853280
#define EQ_PC__GetCombatAbility_x                                  0x853310
#define EQ_PC__GetCombatAbilityTimer_x                             0x84E130
#define EQ_PC__GetItemTimerValue_x                                 0x5BDBA0
#define EQ_PC__HasLoreItem_x                                       0x5B7CD0
#define EQ_PC__AlertInventoryChanged_x                             0x5B4790
#define EQ_PC__GetPcZoneClient_x                                   0x5DEB90
#define EQ_PC__RemoveMyAffect_x                                    0x5BD030
#define EQ_PC__GetKeyRingItems_x                                   0x84E550

// EQItemList 
#define EQItemList__EQItemList_x                                   0x513A40
#define EQItemList__add_object_x                                   0x53F930
#define EQItemList__add_item_x                                     0x513980
#define EQItemList__delete_item_x                                  0x513E30
#define EQItemList__FreeItemList_x                                 0x513D30

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A89D0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C9BC0
#define EQPlayer__dEQPlayer_x                                      0x5D2A90
#define EQPlayer__DoAttack_x                                       0x5E4A80
#define EQPlayer__EQPlayer_x                                       0x5D51A0
#define EQPlayer__SetNameSpriteState_x                             0x5CF9E0
#define EQPlayer__SetNameSpriteTint_x                              0x5CAFD0
#define PlayerBase__HasProperty_j_x                                0x9245B0
#define EQPlayer__IsTargetable_x                                   0x924EB0
#define EQPlayer__CanSee_x                                         0x9253D0
#define PlayerZoneClient__ChangeHeight_x                           0x5E4940
#define EQPlayer__CanSeeTargetIndicator_x                          0x9254C0
#define PlayerBase__GetVisibilityLineSegment_x                     0x925160

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D91D0
#define EQPlayerManager__GetSpawnByName_x                          0x5D9630
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D9200

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59AF80
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59AFC0
#define KeypressHandler__ClearCommandStateArray_x                  0x59AB70
#define KeypressHandler__HandleKeyDown_x                           0x5994D0
#define KeypressHandler__HandleKeyUp_x                             0x5997F0
#define KeypressHandler__SaveKeymapping_x                          0x59AC40

// MapViewMap 
#define MapViewMap__Clear_x                                        0x708640
#define MapViewMap__SaveEx_x                                       0x70B970

#define PlayerPointManager__GetAltCurrency_x                       0x865BE0

// StringTable 
#define StringTable__getString_x                                   0x860700

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C1A60
#define PcZoneClient__RemovePetEffect_x                            0x5BE070
#define PcZoneClient__HasAlternateAbility_x                        0x5BEA10
#define PcZoneClient__GetCurrentMod_x                              0x4580F0
#define PcZoneClient__GetModCap_x                                  0x4558B0
#define PcZoneClient__CanEquipItem_x                               0x5BEFC0

//Doors
#define EQSwitch__UseSwitch_x                                      0x551700

//IconCache
#define IconCache__GetIcon_x                                       0x6A50C0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69BE20
#define CContainerMgr__CloseContainer_x                            0x69C640

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7693E0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58E0E0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E29F0
#define EQ_Spell__SpellAffects_x                                   0x4E00A0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4E0110
#define CharacterZoneClient__CalcAffectChange_x                    0x446190
#define CLootWnd__LootAll_x                                        0x6FDF10
#define CLootWnd__RequestLootSlot_x                                0x6FE720

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B01B0
#define CTargetWnd__WndNotification_x                              0x7AFCA0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7B0390

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B5390

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4DB980

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x498500

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DEE90
#define CSidlManager__FindAnimation1_x                             0x8D4210

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D0940
#define CAltAbilityData__GetMercMaxRank_x                          0x4D08F0
#define CAltAbilityData__GetMaxRank_x                              0x4C5710

//CTargetRing
#define CTargetRing__Cast_x                                        0x58B9D0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4549C0
#define CharacterBase__CreateItemGlobalIndex_x                     0x471870
#define CharacterBase__CreateItemIndex_x                           0x50CE70
#define CharacterBase__GetItemPossession_x                         0x50E370
#define CharacterBase__GetItemByGlobalIndex_x                      0x875BE0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6866B0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x685E10

//messages
#define msg_spell_worn_off_x                                       0x4EA4C0
#define msg_new_text_x                                             0x4F3A00
#define msgTokenTextParam_x                                        0x4F0560

//SpellManager
#define SpellManager__vftable_x                                    0xAB5FE0
#define SpellManager__SpellManager_x                               0x47A780
#define Spellmanager__CheckSpellRequirementAssociations_x          0x602B20

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x928F00

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E6A70
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43A710
#define ItemGlobalIndex__IsEquippedLocation_x                      0x4449E0
#define ItemGlobalIndex__IsValidIndex_x                            0x454270

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8739F0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x872930

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F6DB0