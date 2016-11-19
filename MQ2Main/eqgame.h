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
#define __ExpectedVersionDate                                     "Nov 14 2016"
#define __ExpectedVersionTime                                     "14:43:01"
#define __ActualVersionDate_x                                      0xAD0658
#define __ActualVersionTime_x                                      0xAD0664

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5A0E60
#define __MemChecker1_x                                            0x895C40
#define __MemChecker2_x                                            0x6374A0
#define __MemChecker3_x                                            0x6373F0
#define __MemChecker4_x                                            0x7E9F00
#define __EncryptPad0_x                                            0xC74450
#define __EncryptPad1_x                                            0xE00A60
#define __EncryptPad2_x                                            0xCBD250
#define __EncryptPad3_x                                            0xCBCE50
#define __EncryptPad4_x                                            0xDD6A30
#define __EncryptPad5_x                                            0x11B1C98
#define __AC1_x                                                    0x7A9725
#define __AC2_x                                                    0x55AC27
#define __AC3_x                                                    0x558DC0
#define __AC4_x                                                    0x56B630
#define __AC5_x                                                    0x57E38B
#define __AC6_x                                                    0x581F3E
#define __AC7_x                                                    0x5789FC
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
#define __do_loot_x                                                0x520020
#define __DrawHandler_x                                            0x181E5BC
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
#define __SubscriptionType_x                                       0x11E5704
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
#define pinstCSidlManager_x                                        0x181D9AC
#define pinstCXWndManager_x                                        0x181D9A4
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
#define pinstImeManager_x                                          0x181D9B0
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
#define pinstCAchievementsWnd_x                                    0xF5FA74
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
#define pinstCContextMenuManager_x                                 0x181D91C
#define pinstCVoiceMacroWnd_x                                      0x10A6C28
#define pinstCHtmlWnd_x                                            0x10A6D18
#define pinstIconCache_x                                           0x11B447C
#define pinstCTradeskillWnd_x                                      0x11BA028
#define pinstCAdvancedLootWnd_x                                    0xF5FAE8
#define pinstRewardSelectionWnd_x                                  0x11B8798

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5372C0
#define __ConvertItemTags_x                                        0x524B80
#define __ExecuteCmd_x                                             0x50F420
#define __EQGetTime_x                                              0x8958D0
#define __get_melee_range_x                                        0x516010
#define __GetGaugeValueFromEQ_x                                    0x7A8460
#define __GetLabelFromEQ_x                                         0x7A96B0
#define __ToggleKeyRingItem_x                                      0x47FE60
#define __GetXTargetType_x                                         0x926A00
#define __LoadFrontEnd_x                                           0x636B70
#define __NewUIINI_x                                               0x7A7E30
#define __ProcessGameEvents_x                                      0x57A790
#define __ProcessMouseEvent_x                                      0x579F30
#define CrashDetected_x                                            0x638530
#define wwsCrashReportCheckForUploader_x                           0x7F5F60
#define DrawNetStatus_x                                            0x5B08E0
#define Util__FastTime_x                                           0x895570
#define Expansion_HoT_x                                            0x10216B8
#define __HelpPath_x                                               0x10A4DB0
#define __STMLToText_x                                             0x8DB7D0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4204D0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B270
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B050

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C7460
#define AltAdvManager__IsAbilityReady_x                            0x4C74D0
#define AltAdvManager__GetAAById_x                                 0x4C7890
#define AltAdvManager__CanTrainAbility_x                           0x4C8190
#define AltAdvManager__CanSeeAbility_x                             0x4C7D50

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463400
#define CharacterZoneClient__MakeMeVisible_x                       0x467DC0
#define CharacterZoneClient__IsStackBlocked_x                      0x4478B0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x446D70
#define CharacterZoneClient__GetItemCountWorn_x                    0x461230
#define CharacterZoneClient__GetItemCountInInventory_x             0x461310
#define CharacterZoneClient__GetCursorItemCount_x                  0x4613F0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x666640

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6747D0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58FE70
#define CButtonWnd__CButtonWnd_x                                   0x8CFA50

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68FC00
#define CChatManager__InitContextMenu_x                            0x690780

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D9B30
#define CContextMenu__dCContextMenu_x                              0x8D9D40
#define CContextMenu__AddMenuItem_x                                0x8D9D50
#define CContextMenu__RemoveMenuItem_x                             0x8DA040
#define CContextMenu__RemoveAllMenuItems_x                         0x8DA060
#define CContextMenuManager__AddMenu_x                             0x8C6000
#define CContextMenuManager__RemoveMenu_x                          0x8C63B0
#define CContextMenuManager__PopupMenu_x                           0x8C6800
#define CContextMenuManager__Flush_x                               0x8C6070
#define CContextMenuManager__GetMenu_x                             0x416950

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87A290
#define CChatService__GetFriendName_x                              0x87A2A0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6959E0
#define CChatWindow__Clear_x                                       0x6955B0
#define CChatWindow__WndNotification_x                             0x695F20

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C9E60
#define CComboWnd__Draw_x                                          0x8CA070
#define CComboWnd__GetCurChoice_x                                  0x8C9C10
#define CComboWnd__GetListRect_x                                   0x8CA310
#define CComboWnd__GetTextRect_x                                   0x8C9ED0
#define CComboWnd__InsertChoice_x                                  0x8CA380
#define CComboWnd__SetColors_x                                     0x8C9BA0
#define CComboWnd__SetChoice_x                                     0x8C9BD0
#define CComboWnd__GetItemCount_x                                  0x8C9C00
#define CComboWnd__GetCurChoiceText_x                              0x8C9C50


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69F0A0
#define CContainerWnd__vftable_x                                   0xADA138

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B5920
#define CDisplay__GetClickedActor_x                                0x4AE250
#define CDisplay__GetUserDefinedColor_x                            0x4ACE30
#define CDisplay__GetWorldFilePath_x                               0x4AC280
#define CDisplay__is3dON_x                                         0x4AB710
#define CDisplay__ReloadUI_x                                       0x4C0E90
#define CDisplay__WriteTextHD2_x                                   0x4B1CE0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F0180

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DE060
#define CEditWnd__GetCharIndexPt_x                                 0x8DF100
#define CEditWnd__GetDisplayString_x                               0x8DE210
#define CEditWnd__GetHorzOffset_x                                  0x8DE550
#define CEditWnd__GetLineForPrintableChar_x                        0x8DEBC0
#define CEditWnd__GetSelStartPt_x                                  0x8DF3C0
#define CEditWnd__GetSTMLSafeText_x                                0x8DE6F0
#define CEditWnd__PointFromPrintableChar_x                         0x8DECB0
#define CEditWnd__SelectableCharFromPoint_x                        0x8DEE30
#define CEditWnd__SetEditable_x                                    0x8DE6C0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x55B370
#define CEverQuest__CreateTargetIndicator_x                        0x55C260
#define CEverQuest__DeleteTargetIndicator_x                        0x55C2E0
#define CEverQuest__DoTellWindow_x                                 0x472A90
#define CEverQuest__DropHeldItemOnGround_x                         0x572480
#define CEverQuest__dsp_chat_x                                     0x472DD0
#define CEverQuest__trimName_x                                     0x557CC0
#define CEverQuest__Emote_x                                        0x5707D0
#define CEverQuest__EnterZone_x                                    0x56B7C0
#define CEverQuest__GetBodyTypeDesc_x                              0x555720
#define CEverQuest__GetClassDesc_x                                 0x55EFF0
#define CEverQuest__GetClassThreeLetterCode_x                      0x55F5F0
#define CEverQuest__GetDeityDesc_x                                 0x556000
#define CEverQuest__GetLangDesc_x                                  0x555AB0
#define CEverQuest__GetRaceDesc_x                                  0x55F7B0
#define CEverQuest__InterpretCmd_x                                 0x5635E0
#define CEverQuest__LeftClickedOnPlayer_x                          0x576E50
#define CEverQuest__LMouseUp_x                                     0x578F50
#define CEverQuest__RightClickedOnPlayer_x                         0x577960
#define CEverQuest__RMouseUp_x                                     0x5789B0
#define CEverQuest__SetGameState_x                                 0x55BC30
#define CEverQuest__UPCNotificationFlush_x                         0x553530
#define CEverQuest__IssuePetCommand_x                              0x563FC0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AFE80
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AFEE0
#define CGaugeWnd__Draw_x                                          0x6B0310

// CGuild
#define CGuild__FindMemberByName_x                                 0x437190
#define CGuild__GetGuildName_x                                     0x437660
#define CGuild__GetGuildIndex_x                                    0x438830

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CC410

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D95A0
#define CInvSlotMgr__MoveItem_x                                    0x6DA450
#define CInvSlotMgr__SelectSlot_x                                  0x6D9650

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D8A50
#define CInvSlot__SliderComplete_x                                 0x6D6260
#define CInvSlot__GetItemBase_x                                    0x6D56F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DB8B0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A3E60
#define CItemDisplayWnd__UpdateStrings_x                           0x6DDA00

// CLabel 
#define CLabel__Draw_x                                             0x6F74C0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B59C0
#define CListWnd__dCListWnd_x                                      0x8B6BD0
#define CListWnd__AddColumn_x                                      0x8B6B70
#define CListWnd__AddColumn1_x                                     0x8B6210
#define CListWnd__AddLine_x                                        0x8B5C70
#define CListWnd__AddString_x                                      0x8B5E90
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B2C40
#define CListWnd__CalculateVSBRange_x                              0x8B4E80
#define CListWnd__ClearSel_x                                       0x8B1F50
#define CListWnd__ClearAllSel_x                                    0x8B1F00
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B5850
#define CListWnd__Compare_x                                        0x8B37C0
#define CListWnd__Draw_x                                           0x8B4A80
#define CListWnd__DrawColumnSeparators_x                           0x8B4910
#define CListWnd__DrawHeader_x                                     0x8B2210
#define CListWnd__DrawItem_x                                       0x8B3E40
#define CListWnd__DrawLine_x                                       0x8B45B0
#define CListWnd__DrawSeparator_x                                  0x8B49B0
#define CListWnd__EnsureVisible_x                                  0x8B2DA0
#define CListWnd__ExtendSel_x                                      0x8B3D50
#define CListWnd__GetColumnMinWidth_x                              0x8B1900
#define CListWnd__GetColumnWidth_x                                 0x8B1830
#define CListWnd__GetCurSel_x                                      0x8B0FF0
#define CListWnd__GetItemAtPoint_x                                 0x8B3040
#define CListWnd__GetItemAtPoint1_x                                0x8B30B0
#define CListWnd__GetItemData_x                                    0x8B1340
#define CListWnd__GetItemHeight_x                                  0x8B2890
#define CListWnd__GetItemIcon_x                                    0x8B1530
#define CListWnd__GetItemRect_x                                    0x8B2E80
#define CListWnd__GetItemText_x                                    0x8B13E0
#define CListWnd__GetSelList_x                                     0x8B6100
#define CListWnd__GetSeparatorRect_x                               0x8B36E0
#define CListWnd__RemoveLine_x                                     0x8B6080
#define CListWnd__SetColors_x                                      0x8B1140
#define CListWnd__SetColumnJustification_x                         0x8B1B90
#define CListWnd__SetColumnWidth_x                                 0x8B18B0
#define CListWnd__SetCurSel_x                                      0x8B1030
#define CListWnd__SetItemColor_x                                   0x8B5540
#define CListWnd__SetItemData_x                                    0x8B1FB0
#define CListWnd__SetItemText_x                                    0x8B5380
#define CListWnd__ShiftColumnSeparator_x                           0x8B5210
#define CListWnd__Sort_x                                           0x8B6CD0
#define CListWnd__ToggleSel_x                                      0x8B1E80

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x710460

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7318B0
#define CMerchantWnd__RequestBuyItem_x                             0x738950
#define CMerchantWnd__RequestSellItem_x                            0x739410
#define CMerchantWnd__SelectRecoverySlot_x                         0x731B60
#define CMerchantWnd__SelectBuySellSlot_x                          0x730D60
#define CMerchantWnd__ActualSelect_x                               0x735830

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x849B90
#define CPacketScrambler__hton_x                                   0x849BA0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D4A30
#define CSidlManager__CreateLabel_x                                0x799D80

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65DA20
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65D940
#define CSidlScreenWnd__ConvertToRes_x                             0x8F0060
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CC800
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CD9B0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CDA60
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CCF40
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CC1B0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CB910
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CC3A0
#define CSidlScreenWnd__Init1_x                                    0x8CD690
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CC8B0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CBAD0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CD180
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CB570
#define CSidlScreenWnd__StoreIniVis_x                              0x8CB8C0
#define CSidlScreenWnd__WndNotification_x                          0x8CD410
#define CSidlScreenWnd__GetChildItem_x                             0x8CB9E0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BF1F0
#define CSidlScreenWnd__m_layoutCopy_x                             0x181D980

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FC4E0
#define CSkillMgr__GetSkillCap_x                                   0x5FC6C0
#define CSkillMgr__GetNameToken_x                                  0x5FC100

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8EF320
#define CSliderWnd__SetValue_x                                     0x8EF4F0
#define CSliderWnd__SetNumTicks_x                                  0x8EFC70

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A1AC0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EACF0
#define CStmlWnd__CalculateHSBRange_x                              0x8E3230
#define CStmlWnd__CalculateVSBRange_x                              0x8E32C0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E3440
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E3D20
#define CStmlWnd__ForceParseNow_x                                  0x8EB640
#define CStmlWnd__GetNextTagPiece_x                                0x8E3C20
#define CStmlWnd__GetSTMLText_x                                    0x694E50
#define CStmlWnd__GetVisibleText_x                                 0x8E4770
#define CStmlWnd__InitializeWindowVariables_x                      0x8E6B00
#define CStmlWnd__MakeStmlColorTag_x                               0x8E2530
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E2590
#define CStmlWnd__SetSTMLText_x                                    0x8E8360
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EA990
#define CStmlWnd__UpdateHistoryString_x                            0x8E56B0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E1C50
#define CTabWnd__DrawCurrentPage_x                                 0x8E14E0
#define CTabWnd__DrawTab_x                                         0x8E12A0
#define CTabWnd__GetCurrentPage_x                                  0x8E1890
#define CTabWnd__GetPageInnerRect_x                                0x8E0F90
#define CTabWnd__GetTabInnerRect_x                                 0x8E1190
#define CTabWnd__GetTabRect_x                                      0x8E1060
#define CTabWnd__InsertPage_x                                      0x8E1F40
#define CTabWnd__SetPage_x                                         0x8E18C0
#define CTabWnd__SetPageRect_x                                     0x8E1B90
#define CTabWnd__UpdatePage_x                                      0x8E1EE0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432DD0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C9810

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x634E00

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F5490

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8AF2A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59D390
#define CXStr__CXStr1_x                                            0x743C70
#define CXStr__CXStr3_x                                            0x892850
#define CXStr__dCXStr_x                                            0x4029B0
#define CXStr__operator_equal_x                                    0x8929C0
#define CXStr__operator_equal1_x                                   0x892A10
#define CXStr__operator_plus_equal1_x                              0x893B10

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BE3A0
#define CXWnd__Center_x                                            0x8C45F0
#define CXWnd__ClrFocus_x                                          0x8BDF70
#define CXWnd__DoAllDrawing_x                                      0x8C4250
#define CXWnd__DrawChildren_x                                      0x8C43F0
#define CXWnd__DrawColoredRect_x                                   0x8BE790
#define CXWnd__DrawTooltip_x                                       0x8BEA40
#define CXWnd__DrawTooltipAtPoint_x                                0x8C31A0
#define CXWnd__GetBorderFrame_x                                    0x8BEEA0
#define CXWnd__GetChildWndAt_x                                     0x8C4FB0
#define CXWnd__GetClientClipRect_x                                 0x8BEC50
#define CXWnd__GetScreenClipRect_x                                 0x8C38A0
#define CXWnd__GetScreenRect_x                                     0x8BF080
#define CXWnd__GetTooltipRect_x                                    0x8BE8D0
#define CXWnd__GetWindowTextA_x                                    0x4244D0
#define CXWnd__IsActive_x                                          0x8B99B0
#define CXWnd__IsDescendantOf_x                                    0x8BEDE0
#define CXWnd__IsReallyVisible_x                                   0x8C21E0
#define CXWnd__IsType_x                                            0x8F1CB0
#define CXWnd__Move_x                                              0x8C18D0
#define CXWnd__Move1_x                                             0x8C3EF0
#define CXWnd__ProcessTransition_x                                 0x8BE340
#define CXWnd__Refade_x                                            0x8BE120
#define CXWnd__Resize_x                                            0x8BF150
#define CXWnd__Right_x                                             0x8C36A0
#define CXWnd__SetFocus_x                                          0x8C0A20
#define CXWnd__SetFont_x                                           0x8BDFC0
#define CXWnd__SetKeyTooltip_x                                     0x8BF3C0
#define CXWnd__SetMouseOver_x                                      0x8C3BD0
#define CXWnd__StartFade_x                                         0x8BE3F0
#define CXWnd__GetChildItem_x                                      0x8C3B10

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BB250
#define CXWndManager__DrawWindows_x                                0x8BAE90
#define CXWndManager__GetKeyboardFlags_x                           0x8B94E0
#define CXWndManager__HandleKeyboardMsg_x                          0x8B9E40
#define CXWndManager__RemoveWnd_x                                  0x8B9B40

// CDBStr
#define CDBStr__GetString_x                                        0x4A9C50

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44DE60
#define EQ_Character__Cur_HP_x                                     0x462AA0
#define EQ_Character__Cur_Mana_x                                   0x4565C0
#define EQ_Character__GetAACastingTimeModifier_x                   0x447080
#define EQ_Character__GetCharInfo2_x                               0x866270
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F330
#define EQ_Character__GetFocusRangeModifier_x                      0x43F390
#define EQ_Character__Max_Endurance_x                              0x5C2950
#define EQ_Character__Max_HP_x                                     0x4591E0
#define EQ_Character__Max_Mana_x                                   0x5C2780
#define EQ_Character__doCombatAbility_x                            0x5BFE70
#define EQ_Character__UseSkill_x                                   0x46CE40
#define EQ_Character__GetConLevel_x                                0x5B4EF0
#define EQ_Character__IsExpansionFlag_x                            0x423A10
#define EQ_Character__TotalEffect_x                                0x44B100
#define EQ_Character__GetPCSpellAffect_x                           0x447480
#define EQ_Character__SpellDuration_x                              0x445380
#define EQ_Character__FindItemByRecord_x                           0x45FF00

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x442690
#define CCharacterSelect__EnterWorld_x                             0x441E60
#define CCharacterSelect__Quit_x                                   0x440A40

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x595680
#define EQ_Item__CreateItemTagString_x                             0x8484D0
#define EQ_Item__IsStackable_x                                     0x83DCD0
#define EQ_Item__GetImageNum_x                                     0x840800
#define EQ_Item__CreateItemClient_x                                0x596240
#define EQ_Item__GetItemValue_x                                    0x847210
#define EQ_Item__ValueSellMerchant_x                               0x8497E0
#define EQ_Item__IsKeyRingItem_x                                   0x83E7B0
#define EQ_Item__CanGoInBag_x                                      0x595810
#define EQ_Item__GetMaxItemCount_x                                 0x83DBC0
#define EQ_Item__GetHeldItem_x                                     0x83F600

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C9590
#define EQ_LoadingS__Array_x                                       0xC1B680

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C4E70
#define EQ_PC__GetAlternateAbilityId_x                             0x851B90
#define EQ_PC__GetCombatAbility_x                                  0x851C20
#define EQ_PC__GetCombatAbilityTimer_x                             0x84C9A0
#define EQ_PC__GetItemTimerValue_x                                 0x5BE520
#define EQ_PC__HasLoreItem_x                                       0x5B8400
#define EQ_PC__AlertInventoryChanged_x                             0x5B4EC0
#define EQ_PC__GetPcZoneClient_x                                   0x5DF570
#define EQ_PC__RemoveMyAffect_x                                    0x5BD9B0
#define EQ_PC__GetKeyRingItems_x                                   0x84CDC0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5140A0
#define EQItemList__add_object_x                                   0x53FF50
#define EQItemList__add_item_x                                     0x513FE0
#define EQItemList__delete_item_x                                  0x514490
#define EQItemList__FreeItemList_x                                 0x514390

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A8EF0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5CA510
#define EQPlayer__dEQPlayer_x                                      0x5D33E0
#define EQPlayer__DoAttack_x                                       0x5E5460
#define EQPlayer__EQPlayer_x                                       0x5D5AF0
#define EQPlayer__SetNameSpriteState_x                             0x5D0330
#define EQPlayer__SetNameSpriteTint_x                              0x5CB920
#define PlayerBase__HasProperty_j_x                                0x922BD0
#define EQPlayer__IsTargetable_x                                   0x9234D0
#define EQPlayer__CanSee_x                                         0x9239F0
#define PlayerZoneClient__ChangeHeight_x                           0x5E5320
#define EQPlayer__CanSeeTargetIndicator_x                          0x923AE0
#define PlayerBase__GetVisibilityLineSegment_x                     0x923780

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D9B60
#define EQPlayerManager__GetSpawnByName_x                          0x5D9FC0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D9B90

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59B730
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59B770
#define KeypressHandler__ClearCommandStateArray_x                  0x59B320
#define KeypressHandler__HandleKeyDown_x                           0x599C80
#define KeypressHandler__HandleKeyUp_x                             0x599FA0
#define KeypressHandler__SaveKeymapping_x                          0x59B3F0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x708DF0
#define MapViewMap__SaveEx_x                                       0x70C120

#define PlayerPointManager__GetAltCurrency_x                       0x8643D0

// StringTable 
#define StringTable__getString_x                                   0x85F010

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C23E0
#define PcZoneClient__RemovePetEffect_x                            0x5BE9F0
#define PcZoneClient__HasAlternateAbility_x                        0x5BF390
#define PcZoneClient__GetCurrentMod_x                              0x458580
#define PcZoneClient__GetModCap_x                                  0x455D40
#define PcZoneClient__CanEquipItem_x                               0x5BF940

//Doors
#define EQSwitch__UseSwitch_x                                      0x551DC0

//IconCache
#define IconCache__GetIcon_x                                       0x6A56B0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69C430
#define CContainerMgr__CloseContainer_x                            0x69CC50

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x769BD0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58E8F0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E33D0
#define EQ_Spell__SpellAffects_x                                   0x4E0A80
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4E0AF0
#define CharacterZoneClient__CalcAffectChange_x                    0x4464B0
#define CLootWnd__LootAll_x                                        0x6FE720
#define CLootWnd__RequestLootSlot_x                                0x6FEF30

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B08B0
#define CTargetWnd__WndNotification_x                              0x7B03A0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7B0A90

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B5B10

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4DC120

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4989A0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DD690
#define CSidlManager__FindAnimation1_x                             0x8D2920

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D0CB0
#define CAltAbilityData__GetMercMaxRank_x                          0x4D0C60
#define CAltAbilityData__GetMaxRank_x                              0x4C5AF0

//CTargetRing
#define CTargetRing__Cast_x                                        0x58C1D0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x454CB0
#define CharacterBase__CreateItemGlobalIndex_x                     0x471C10
#define CharacterBase__CreateItemIndex_x                           0x50D530
#define CharacterBase__GetItemPossession_x                         0x50E9C0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8743B0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x686C50
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6863B0

//messages
#define msg_spell_worn_off_x                                       0x4EAF90
#define msg_new_text_x                                             0x4F4530
#define msgTokenTextParam_x                                        0x4F0EE0

//SpellManager
#define SpellManager__vftable_x                                    0xAB5FE0
#define SpellManager__SpellManager_x                               0x47AAF0
#define Spellmanager__CheckSpellRequirementAssociations_x          0x6033E0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x927520

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E74F0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43AAB0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x444D00
#define ItemGlobalIndex__IsValidIndex_x                            0x454570

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8721D0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x871110

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F7710
