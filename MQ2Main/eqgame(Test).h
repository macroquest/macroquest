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
#define __ExpectedVersionDate                                     "Nov  7 2016"
#define __ExpectedVersionTime                                     "15:52:32"
#define __ActualVersionDate_x                                      0xAD06A8
#define __ActualVersionTime_x                                      0xAD06B4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x5A0AD0
#define __MemChecker1_x                                            0x895A00
#define __MemChecker2_x                                            0x6370D0
#define __MemChecker3_x                                            0x637020
#define __MemChecker4_x                                            0x7E9F70
#define __EncryptPad0_x                                            0xC74450
#define __EncryptPad1_x                                            0xE00A60
#define __EncryptPad2_x                                            0xCBD250
#define __EncryptPad3_x                                            0xCBCE50
#define __EncryptPad4_x                                            0xDD6A30
#define __EncryptPad5_x                                            0x11B1C98
#define __AC1_x                                                    0x7A9105
#define __AC2_x                                                    0x55A967
#define __AC3_x                                                    0x558B00
#define __AC4_x                                                    0x56B370
#define __AC5_x                                                    0x57E0CB
#define __AC6_x                                                    0x581C7E
#define __AC7_x                                                    0x57873C
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
#define __do_loot_x                                                0x51FDF0
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
#define pinstCGroupSearchFiltersWnd_x                              0xF5F97C
#define pinstCLoadskinWnd_x                                        0xF5F980
#define pinstCAlarmWnd_x                                           0xF5F984
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
#define pinstCLargeDialogWnd_x                                     0x11B8978
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
#define __CastRay_x                                                0x537090
#define __ConvertItemTags_x                                        0x524950
#define __ExecuteCmd_x                                             0x50F200
#define __EQGetTime_x                                              0x895690
#define __get_melee_range_x                                        0x515DE0
#define __GetGaugeValueFromEQ_x                                    0x7A7E40
#define __GetLabelFromEQ_x                                         0x7A9090
#define __ToggleKeyRingItem_x                                      0x47FEF0
#define __GetXTargetType_x                                         0x926490
#define __LoadFrontEnd_x                                           0x6367A0
#define __NewUIINI_x                                               0x7A7810
#define __ProcessGameEvents_x                                      0x57A4D0
#define __ProcessMouseEvent_x                                      0x579C70
#define CrashDetected_x                                            0x638160
#define wwsCrashReportCheckForUploader_x                           0x7F5B10
#define DrawNetStatus_x                                            0x5B0530
#define Util__FastTime_x                                           0x895330
#define Expansion_HoT_x                                            0x10216B8
#define __HelpPath_x                                               0x10A4DB0
#define __STMLToText_x                                             0x8DB240

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4205A0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B340
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B120

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C73B0
#define AltAdvManager__IsAbilityReady_x                            0x4C7420
#define AltAdvManager__GetAAById_x                                 0x4C77E0
#define AltAdvManager__CanTrainAbility_x                           0x4C80E0
#define AltAdvManager__CanSeeAbility_x                             0x4C7CA0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4634F0
#define CharacterZoneClient__MakeMeVisible_x                       0x467EB0
#define CharacterZoneClient__IsStackBlocked_x                      0x447A70
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x446F30
#define CharacterZoneClient__GetItemCountWorn_x                    0x461320
#define CharacterZoneClient__GetItemCountInInventory_x             0x461400
#define CharacterZoneClient__GetCursorItemCount_x                  0x4614E0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x666280

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x674570

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58FAD0
#define CButtonWnd__CButtonWnd_x                                   0x8CF620

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68F690
#define CChatManager__InitContextMenu_x                            0x690210

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D9590
#define CContextMenu__dCContextMenu_x                              0x8D97A0
#define CContextMenu__AddMenuItem_x                                0x8D97B0
#define CContextMenu__RemoveMenuItem_x                             0x8D9AA0
#define CContextMenu__RemoveAllMenuItems_x                         0x8D9AC0
#define CContextMenuManager__AddMenu_x                             0x8C5BE0
#define CContextMenuManager__RemoveMenu_x                          0x8C5F60
#define CContextMenuManager__PopupMenu_x                           0x8C63B0
#define CContextMenuManager__Flush_x                               0x8C5C50
#define CContextMenuManager__GetMenu_x                             0x416A20

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87A170
#define CChatService__GetFriendName_x                              0x87A180

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x695470
#define CChatWindow__Clear_x                                       0x695040
#define CChatWindow__WndNotification_x                             0x6959A0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C9A30
#define CComboWnd__Draw_x                                          0x8C9C40
#define CComboWnd__GetCurChoice_x                                  0x8C97E0
#define CComboWnd__GetListRect_x                                   0x8C9EE0
#define CComboWnd__GetTextRect_x                                   0x8C9AA0
#define CComboWnd__InsertChoice_x                                  0x8C9F50
#define CComboWnd__SetColors_x                                     0x8C9770
#define CComboWnd__SetChoice_x                                     0x8C97A0
#define CComboWnd__GetItemCount_x                                  0x8C97D0
#define CComboWnd__GetCurChoiceText_x                              0x8C9820

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69EB30
#define CContainerWnd__vftable_x                                   0xADA188

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B58A0
#define CDisplay__GetClickedActor_x                                0x4AE1D0
#define CDisplay__GetUserDefinedColor_x                            0x4ACDB0
#define CDisplay__GetWorldFilePath_x                               0x4AC200
#define CDisplay__is3dON_x                                         0x4AB690
#define CDisplay__ReloadUI_x                                       0x4C0E10
#define CDisplay__WriteTextHD2_x                                   0x4B1C60

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8EFBB0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DDAD0
#define CEditWnd__GetCharIndexPt_x                                 0x8DEB60
#define CEditWnd__GetDisplayString_x                               0x8DDC80
#define CEditWnd__GetHorzOffset_x                                  0x8DDFC0
#define CEditWnd__GetLineForPrintableChar_x                        0x8DE630
#define CEditWnd__GetSelStartPt_x                                  0x8DEE10
#define CEditWnd__GetSTMLSafeText_x                                0x8DE160
#define CEditWnd__PointFromPrintableChar_x                         0x8DE720
#define CEditWnd__SelectableCharFromPoint_x                        0x8DE8A0
#define CEditWnd__SetEditable_x                                    0x8DE130

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x55B0B0
#define CEverQuest__CreateTargetIndicator_x                        0x55BFA0
#define CEverQuest__DeleteTargetIndicator_x                        0x55C020
#define CEverQuest__DoTellWindow_x                                 0x472B40
#define CEverQuest__DropHeldItemOnGround_x                         0x5721C0
#define CEverQuest__dsp_chat_x                                     0x472E80
#define CEverQuest__trimName_x                                     0x557A00
#define CEverQuest__Emote_x                                        0x570510
#define CEverQuest__EnterZone_x                                    0x56B500
#define CEverQuest__GetBodyTypeDesc_x                              0x555460
#define CEverQuest__GetClassDesc_x                                 0x55ED30
#define CEverQuest__GetClassThreeLetterCode_x                      0x55F330
#define CEverQuest__GetDeityDesc_x                                 0x555D40
#define CEverQuest__GetLangDesc_x                                  0x5557F0
#define CEverQuest__GetRaceDesc_x                                  0x55F4F0
#define CEverQuest__InterpretCmd_x                                 0x563320
#define CEverQuest__LeftClickedOnPlayer_x                          0x576B90
#define CEverQuest__LMouseUp_x                                     0x578C90
#define CEverQuest__RightClickedOnPlayer_x                         0x5776A0
#define CEverQuest__RMouseUp_x                                     0x5786F0
#define CEverQuest__SetGameState_x                                 0x55B970
#define CEverQuest__UPCNotificationFlush_x                         0x553270
#define CEverQuest__IssuePetCommand_x                              0x563D00

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AF910
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AF970
#define CGaugeWnd__Draw_x                                          0x6AFDA0

// CGuild
#define CGuild__FindMemberByName_x                                 0x437360
#define CGuild__GetGuildName_x                                     0x437830
#define CGuild__GetGuildIndex_x                                    0x438A00

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CBE40

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D8FD0
#define CInvSlotMgr__MoveItem_x                                    0x6D9E80
#define CInvSlotMgr__SelectSlot_x                                  0x6D9080

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D8480
#define CInvSlot__SliderComplete_x                                 0x6D5C90
#define CInvSlot__GetItemBase_x                                    0x6D5110

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DB2E0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A3860
#define CItemDisplayWnd__UpdateStrings_x                           0x6DD3E0

// CLabel 
#define CLabel__Draw_x                                             0x6F6E80

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B57A0
#define CListWnd__dCListWnd_x                                      0x8B69C0
#define CListWnd__AddColumn_x                                      0x8B6960
#define CListWnd__AddColumn1_x                                     0x8B6000
#define CListWnd__AddLine_x                                        0x8B5A60
#define CListWnd__AddString_x                                      0x8B5C80
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B2A40
#define CListWnd__CalculateVSBRange_x                              0x8B4C70
#define CListWnd__ClearSel_x                                       0x8B1D60
#define CListWnd__ClearAllSel_x                                    0x8B1D10
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B5630
#define CListWnd__Compare_x                                        0x8B35A0
#define CListWnd__Draw_x                                           0x8B4870
#define CListWnd__DrawColumnSeparators_x                           0x8B4700
#define CListWnd__DrawHeader_x                                     0x8B2020
#define CListWnd__DrawItem_x                                       0x8B3C30
#define CListWnd__DrawLine_x                                       0x8B43A0
#define CListWnd__DrawSeparator_x                                  0x8B47A0
#define CListWnd__EnsureVisible_x                                  0x8B2BA0
#define CListWnd__ExtendSel_x                                      0x8B3B40
#define CListWnd__GetColumnMinWidth_x                              0x8B1710
#define CListWnd__GetColumnWidth_x                                 0x8B1640
#define CListWnd__GetCurSel_x                                      0x8B0E20
#define CListWnd__GetItemAtPoint_x                                 0x8B2E30
#define CListWnd__GetItemAtPoint1_x                                0x8B2EA0
#define CListWnd__GetItemData_x                                    0x8B1150
#define CListWnd__GetItemHeight_x                                  0x8B26A0
#define CListWnd__GetItemIcon_x                                    0x8B1340
#define CListWnd__GetItemRect_x                                    0x8B2C70
#define CListWnd__GetItemText_x                                    0x8B11F0
#define CListWnd__GetSelList_x                                     0x8B5EF0
#define CListWnd__GetSeparatorRect_x                               0x8B34D0
#define CListWnd__RemoveLine_x                                     0x8B5E70
#define CListWnd__SetColors_x                                      0x8B0F70
#define CListWnd__SetColumnJustification_x                         0x8B19A0
#define CListWnd__SetColumnWidth_x                                 0x8B16C0
#define CListWnd__SetCurSel_x                                      0x8B0E60
#define CListWnd__SetItemColor_x                                   0x8B5320
#define CListWnd__SetItemData_x                                    0x8B1DC0
#define CListWnd__SetItemText_x                                    0x8B5160
#define CListWnd__ShiftColumnSeparator_x                           0x8B4FF0
#define CListWnd__Sort_x                                           0x8B6AC0
#define CListWnd__ToggleSel_x                                      0x8B1C90

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70FDC0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7311D0
#define CMerchantWnd__RequestBuyItem_x                             0x738260
#define CMerchantWnd__RequestSellItem_x                            0x738D20
#define CMerchantWnd__SelectRecoverySlot_x                         0x731480
#define CMerchantWnd__SelectBuySellSlot_x                          0x730680
#define CMerchantWnd__ActualSelect_x                               0x735130

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8497D0
#define CPacketScrambler__hton_x                                   0x8497E0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D45F0
#define CSidlManager__CreateLabel_x                                0x799730

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65D660
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65D590
#define CSidlScreenWnd__ConvertToRes_x                             0x8EFA90
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CC3A0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CD550
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CD600
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CCAD0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CBD50
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CB4D0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CBF40
#define CSidlScreenWnd__Init1_x                                    0x8CD220
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CC450
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CB690
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CCD10
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CB130
#define CSidlScreenWnd__StoreIniVis_x                              0x8CB480
#define CSidlScreenWnd__WndNotification_x                          0x8CCFA0
#define CSidlScreenWnd__GetChildItem_x                             0x8CB5A0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BEE90
#define CSidlScreenWnd__m_layoutCopy_x                             0x181D980

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FC1F0
#define CSkillMgr__GetSkillCap_x                                   0x5FC3D0
#define CSkillMgr__GetNameToken_x                                  0x5FBE10

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8EED50
#define CSliderWnd__SetValue_x                                     0x8EEF20
#define CSliderWnd__SetNumTicks_x                                  0x8EF6A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A14C0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EA720
#define CStmlWnd__CalculateHSBRange_x                              0x8E2C80
#define CStmlWnd__CalculateVSBRange_x                              0x8E2D10
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E2E90
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E3770
#define CStmlWnd__ForceParseNow_x                                  0x8EB070
#define CStmlWnd__GetNextTagPiece_x                                0x8E3670
#define CStmlWnd__GetSTMLText_x                                    0x6948E0
#define CStmlWnd__GetVisibleText_x                                 0x8E41C0
#define CStmlWnd__InitializeWindowVariables_x                      0x8E6530
#define CStmlWnd__MakeStmlColorTag_x                               0x8E1F80
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E1FE0
#define CStmlWnd__SetSTMLText_x                                    0x8E7D80
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EA3C0
#define CStmlWnd__UpdateHistoryString_x                            0x8E50F0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E1690
#define CTabWnd__DrawCurrentPage_x                                 0x8E0F20
#define CTabWnd__DrawTab_x                                         0x8E0CE0
#define CTabWnd__GetCurrentPage_x                                  0x8E12D0
#define CTabWnd__GetPageInnerRect_x                                0x8E09D0
#define CTabWnd__GetTabInnerRect_x                                 0x8E0BD0
#define CTabWnd__GetTabRect_x                                      0x8E0AA0
#define CTabWnd__InsertPage_x                                      0x8E1980
#define CTabWnd__SetPage_x                                         0x8E1300
#define CTabWnd__SetPageRect_x                                     0x8E15D0
#define CTabWnd__UpdatePage_x                                      0x8E1920

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432F70

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C93E0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x634A30

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F4EB0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8AEFC0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59CFE0
#define CXStr__CXStr1_x                                            0x743480
#define CXStr__CXStr3_x                                            0x8925D0
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x892740
#define CXStr__operator_equal1_x                                   0x892790
#define CXStr__operator_plus_equal1_x                              0x893890

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BE120
#define CXWnd__Center_x                                            0x8C41B0
#define CXWnd__ClrFocus_x                                          0x8BDCF0
#define CXWnd__DoAllDrawing_x                                      0x8C3E00
#define CXWnd__DrawChildren_x                                      0x8C3FA0
#define CXWnd__DrawColoredRect_x                                   0x8BE510
#define CXWnd__DrawTooltip_x                                       0x8BE7A0
#define CXWnd__DrawTooltipAtPoint_x                                0x8C2D90
#define CXWnd__GetBorderFrame_x                                    0x8BEBA0
#define CXWnd__GetChildWndAt_x                                     0x8C4B80
#define CXWnd__GetClientClipRect_x                                 0x8BE9B0
#define CXWnd__GetScreenClipRect_x                                 0x8C3490
#define CXWnd__GetScreenRect_x                                     0x8BED40
#define CXWnd__GetTooltipRect_x                                    0x8BE630
#define CXWnd__GetWindowTextA_x                                    0x4245E0
#define CXWnd__IsActive_x                                          0x8B9730
#define CXWnd__IsDescendantOf_x                                    0x8BEAF0
#define CXWnd__IsReallyVisible_x                                   0x8C1DE0
#define CXWnd__IsType_x                                            0x8F16F0
#define CXWnd__Move_x                                              0x8C1540
#define CXWnd__Move1_x                                             0x8C3AE0
#define CXWnd__ProcessTransition_x                                 0x8BE0C0
#define CXWnd__Refade_x                                            0x8BDE90
#define CXWnd__Resize_x                                            0x8BEDF0
#define CXWnd__Right_x                                             0x8C3290
#define CXWnd__SetFocus_x                                          0x8C06A0
#define CXWnd__SetFont_x                                           0x8BDD40
#define CXWnd__SetKeyTooltip_x                                     0x8BF060
#define CXWnd__SetMouseOver_x                                      0x8C37E0
#define CXWnd__StartFade_x                                         0x8BE170
#define CXWnd__GetChildItem_x                                      0x8C3720

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BAFD0
#define CXWndManager__DrawWindows_x                                0x8BAC10
#define CXWndManager__GetKeyboardFlags_x                           0x8B92A0
#define CXWndManager__HandleKeyboardMsg_x                          0x8B9BC0
#define CXWndManager__RemoveWnd_x                                  0x8B98C0

// CDBStr
#define CDBStr__GetString_x                                        0x4A9BC0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E020
#define EQ_Character__Cur_HP_x                                     0x462B90
#define EQ_Character__Cur_Mana_x                                   0x4566C0
#define EQ_Character__GetAACastingTimeModifier_x                   0x447240
#define EQ_Character__GetCharInfo2_x                               0x866140
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F4E0
#define EQ_Character__GetFocusRangeModifier_x                      0x43F540
#define EQ_Character__Max_Endurance_x                              0x5C21E0
#define EQ_Character__Max_HP_x                                     0x4592E0
#define EQ_Character__Max_Mana_x                                   0x5C2010
#define EQ_Character__doCombatAbility_x                            0x5BF700
#define EQ_Character__UseSkill_x                                   0x46CF30
#define EQ_Character__GetConLevel_x                                0x5B4BB0
#define EQ_Character__IsExpansionFlag_x                            0x423B30
#define EQ_Character__TotalEffect_x                                0x44B2C0
#define EQ_Character__GetPCSpellAffect_x                           0x447640
#define EQ_Character__SpellDuration_x                              0x445540
#define EQ_Character__FindItemByRecord_x                           0x460010

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x442890
#define CCharacterSelect__EnterWorld_x                             0x442060
#define CCharacterSelect__Quit_x                                   0x440C50

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5952D0
#define EQ_Item__CreateItemTagString_x                             0x848130
#define EQ_Item__IsStackable_x                                     0x83D7E0
#define EQ_Item__GetImageNum_x                                     0x840220
#define EQ_Item__CreateItemClient_x                                0x595EC0
#define EQ_Item__GetItemValue_x                                    0x846DC0
#define EQ_Item__ValueSellMerchant_x                               0x849460
#define EQ_Item__IsKeyRingItem_x                                   0x83E230
#define EQ_Item__CanGoInBag_x                                      0x595460
#define EQ_Item__GetMaxItemCount_x                                 0x83D6D0
#define EQ_Item__GetHeldItem_x                                     0x83F020

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C94E0
#define EQ_LoadingS__Array_x                                       0xC1B680

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C4700
#define EQ_PC__GetAlternateAbilityId_x                             0x8518D0
#define EQ_PC__GetCombatAbility_x                                  0x851960
#define EQ_PC__GetCombatAbilityTimer_x                             0x84C5E0
#define EQ_PC__GetItemTimerValue_x                                 0x5BDDB0
#define EQ_PC__HasLoreItem_x                                       0x5B80C0
#define EQ_PC__AlertInventoryChanged_x                             0x5B4B80
#define EQ_PC__GetPcZoneClient_x                                   0x5DEE30
#define EQ_PC__RemoveMyAffect_x                                    0x5BD240
#define EQ_PC__GetKeyRingItems_x                                   0x84CA00

// EQItemList 
#define EQItemList__EQItemList_x                                   0x513E80
#define EQItemList__add_object_x                                   0x53FD30
#define EQItemList__add_item_x                                     0x513DC0
#define EQItemList__delete_item_x                                  0x514270
#define EQItemList__FreeItemList_x                                 0x514170

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A8EC0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C9DE0
#define EQPlayer__dEQPlayer_x                                      0x5D2CB0
#define EQPlayer__DoAttack_x                                       0x5E4D30
#define EQPlayer__EQPlayer_x                                       0x5D53C0
#define EQPlayer__SetNameSpriteState_x                             0x5CFC00
#define EQPlayer__SetNameSpriteTint_x                              0x5CB1F0
#define PlayerBase__HasProperty_j_x                                0x9226D0
#define EQPlayer__IsTargetable_x                                   0x922FD0
#define EQPlayer__CanSee_x                                         0x9234F0
#define PlayerZoneClient__ChangeHeight_x                           0x5E4BF0
#define EQPlayer__CanSeeTargetIndicator_x                          0x9235E0
#define PlayerBase__GetVisibilityLineSegment_x                     0x923280

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D9480
#define EQPlayerManager__GetSpawnByName_x                          0x5D98E0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D94B0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59B380
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59B3C0
#define KeypressHandler__ClearCommandStateArray_x                  0x59AF70
#define KeypressHandler__HandleKeyDown_x                           0x5998D0
#define KeypressHandler__HandleKeyUp_x                             0x599BF0
#define KeypressHandler__SaveKeymapping_x                          0x59B040

// MapViewMap 
#define MapViewMap__Clear_x                                        0x708750
#define MapViewMap__SaveEx_x                                       0x70BA80

#define PlayerPointManager__GetAltCurrency_x                       0x8641B0

// StringTable 
#define StringTable__getString_x                                   0x85EDD0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C1C70
#define PcZoneClient__RemovePetEffect_x                            0x5BE280
#define PcZoneClient__HasAlternateAbility_x                        0x5BEC20
#define PcZoneClient__GetCurrentMod_x                              0x458680
#define PcZoneClient__GetModCap_x                                  0x455E40
#define PcZoneClient__CanEquipItem_x                               0x5BF1D0

//Doors
#define EQSwitch__UseSwitch_x                                      0x551B00

//IconCache
#define IconCache__GetIcon_x                                       0x6A5140

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69BEE0
#define CContainerMgr__CloseContainer_x                            0x69C700

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x769480

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58E550

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E3460
#define EQ_Spell__SpellAffects_x                                   0x4E0B10
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4E0B80
#define CharacterZoneClient__CalcAffectChange_x                    0x446670
#define CLootWnd__LootAll_x                                        0x6FE0E0
#define CLootWnd__RequestLootSlot_x                                0x6FE8F0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B0300
#define CTargetWnd__WndNotification_x                              0x7AFDF0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7B04E0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B5550

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4DC150

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x498950

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DD100
#define CSidlManager__FindAnimation1_x                             0x8D24F0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D0CC0
#define CAltAbilityData__GetMercMaxRank_x                          0x4D0C70
#define CAltAbilityData__GetMaxRank_x                              0x4C5A60

//CTargetRing
#define CTargetRing__Cast_x                                        0x58BE40

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x454EA0
#define CharacterBase__CreateItemGlobalIndex_x                     0x471D00
#define CharacterBase__CreateItemIndex_x                           0x50D350
#define CharacterBase__GetItemPossession_x                         0x50E7E0
#define CharacterBase__GetItemByGlobalIndex_x                      0x874280

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6866F0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x685E50

//messages
#define msg_spell_worn_off_x                                       0x4EAF90
#define msg_new_text_x                                             0x4F4530
#define msgTokenTextParam_x                                        0x4F0EE0

//SpellManager
#define SpellManager__vftable_x                                    0xAB5FE8
#define SpellManager__SpellManager_x                               0x47AB90
#define Spellmanager__CheckSpellRequirementAssociations_x          0x603050

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x926FB0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E7530
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43AC60
#define ItemGlobalIndex__IsEquippedLocation_x                      0x444F00
#define ItemGlobalIndex__IsValidIndex_x                            0x454730

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x872090
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x870FD0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F70D0
