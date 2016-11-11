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
#if defined(BETA)
#include "eqgame-private(beta).h"
#endif
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Nov 11 2016"
#define __ExpectedVersionTime                                     "04:18:19"
#define __ActualVersionDate_x                                      0xAD2660
#define __ActualVersionTime_x                                      0xAD266C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x5A23A0
#define __MemChecker1_x                                            0x897340
#define __MemChecker2_x                                            0x6388E0
#define __MemChecker3_x                                            0x638830
#define __MemChecker4_x                                            0x7EB8A0
#define __EncryptPad0_x                                            0xC76450
#define __EncryptPad1_x                                            0xE02A60
#define __EncryptPad2_x                                            0xCBF250
#define __EncryptPad3_x                                            0xCBEE50
#define __EncryptPad4_x                                            0xDD8A30
#define __EncryptPad5_x                                            0x11B3C98
#define __AC1_x                                                    0x7AABA5
#define __AC2_x                                                    0x55C0C7
#define __AC3_x                                                    0x55A260
#define __AC4_x                                                    0x56CAC0
#define __AC5_x                                                    0x57F80B
#define __AC6_x                                                    0x5833BE
#define __AC7_x                                                    0x579E7C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1EB620

// Direct Input
#define DI8__Main_x                                                0x11B3C70
#define DI8__Keyboard_x                                            0x11B3C74
#define DI8__Mouse_x                                               0x11B3C78
#define DI8__Mouse_Copy_x                                          0x102235C
#define DI8__Mouse_Check_x                                         0x10ABB5C
#define __Attack_x                                                 0x10A6843
#define __Autofire_x                                               0x10A6844
#define __BindList_x                                               0xC37D90
#define g_eqCommandStates_x                                        0x10113E8
#define __Clicks_x                                                 0x1022418
#define __CommandList_x                                            0xC3C190
#define __CurrentMapLabel_x                                        0x11B96F8
#define __CurrentSocial_x                                          0xBEA194
#define __DoAbilityList_x                                          0x1058AF8
#define __do_loot_x                                                0x521490
#define __DrawHandler_x                                            0x18205BC
#define __GroupCount_x                                             0x10129B2

#define __Guilds_x                                                 0x10185C8
#define __gWorld_x                                                 0x1014E6C
#define __HotkeyPage_x                                             0x109F4F8
#define __HWnd_x                                                   0x10ABB78
#define __InChatMode_x                                             0x1022344
#define __LastTell_x                                               0x10241F4
#define __LMouseHeldTime_x                                         0x1022484
#define __Mouse_x                                                  0x11B3C7C
#define __MouseLook_x                                              0x10223DE
#define __MouseEventTime_x                                         0x10A7044
#define __gpbCommandEvent_x                                        0x1014F34
#define __NetStatusToggle_x                                        0x10223E1
#define __PCNames_x                                                0x1023810
#define __RangeAttackReady_x                                       0x102354C
#define __RMouseHeldTime_x                                         0x1022480
#define __RunWalkState_x                                           0x1022348
#define __ScreenMode_x                                             0xF610E8
#define __ScreenX_x                                                0x10222FC
#define __ScreenY_x                                                0x10222F8
#define __ScreenXMax_x                                             0x1022300
#define __ScreenYMax_x                                             0x1022304
#define __ServerHost_x                                             0x10128FC
#define __ServerName_x                                             0x1058AB8
#define __ShiftKeyDown_x                                           0x10229D8
#define __ShowNames_x                                              0x102370C
#define __Socials_x                                                0x1058BB8
#define __SubscriptionType_x                                       0x11E7704
#define __TargetAggroHolder_x                                      0x11BB934
#define __ZoneType_x                                               0x10227DC
#define __GroupAggro_x                                             0x11BB974
#define __LoginName_x                                              0x10AA754
#define __Inviter_x                                                0x10A67C0
#define __AttackOnAssist_x                                         0x10236C8
#define __UseTellWindows_x                                         0x10239A8

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x1014F58
#define instEQZoneInfo_x                                           0x10225D4
#define instKeypressHandler_x                                      0x10A7028
#define pinstActiveBanker_x                                        0x1014F10
#define pinstActiveCorpse_x                                        0x1014F14
#define pinstActiveGMaster_x                                       0x1014F18
#define pinstActiveMerchant_x                                      0x1014F0C
#define pinstAggroInfo_x                                           0xE1EB48
#define pinstAltAdvManager_x                                       0xF621B0
#define pinstAuraMgr_x                                             0xE2F2B8
#define pinstBandageTarget_x                                       0x1014EF8
#define pinstCamActor_x                                            0xF61B00
#define pinstCDBStr_x                                              0xF6107C
#define pinstCDisplay_x                                            0x1014F20
#define pinstCEverQuest_x                                          0x11B3DF0
#define pinstCharData_x                                            0x1014EDC
#define pinstCharSpawn_x                                           0x1014F04
#define pinstControlledMissile_x                                   0x1014ED8
#define pinstControlledPlayer_x                                    0x1014F04
#define pinstCSidlManager_x                                        0x181F9AC
#define pinstCXWndManager_x                                        0x181F9A4
#define instDynamicZone_x                                          0x1022190
#define pinstDZMember_x                                            0x10222A0
#define pinstDZTimerInfo_x                                         0x10222A4
#define pinstEQItemList_x                                          0x1011638
#define pinstEQObjectList_x                                        0x10123AC
#define instEQMisc_x                                               0xC10DD0
#define pinstEQSoundManager_x                                      0xF62780
#define instExpeditionLeader_x                                     0x10221DA
#define instExpeditionName_x                                       0x102221A
#define pinstGroup_x                                               0x10129AE
#define pinstImeManager_x                                          0x181F9B0
#define pinstLocalPlayer_x                                         0x1014EF0
#define pinstMercenaryData_x                                       0x10A76A8
#define pinstMercenaryStats_x                                      0x11BBA80
#define pinstMercAltAbilities_x                                    0xF62538
#define pinstModelPlayer_x                                         0x1014F1C
#define pinstPCData_x                                              0x1014EDC
#define pinstSkillMgr_x                                            0x10A8510
#define pinstSpawnManager_x                                        0x10A7DF8
#define pinstSpellManager_x                                        0x10A8658
#define pinstSpellSets_x                                           0x109F55C
#define pinstStringTable_x                                         0x1014E84
#define pinstSwitchManager_x                                       0x1012540
#define pinstTarget_x                                              0x1014F08
#define pinstTargetObject_x                                        0x1014EE0
#define pinstTargetSwitch_x                                        0x1014EE4
#define pinstTaskMember_x                                          0xF60FC8
#define pinstTrackTarget_x                                         0x1014EFC
#define pinstTradeTarget_x                                         0x1014EEC
#define instTributeActive_x                                        0xC10DF5
#define pinstViewActor_x                                           0xF61AFC
#define pinstWorldData_x                                           0x1014EC0
#define pinstZoneAddr_x                                            0x1022874
#define pinstPlayerPath_x                                          0x10A7E58
#define pinstTargetIndicator_x                                     0x10A87F0
#define pinstCTargetManager_x                                      0x10A8850

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE1F040
#define pinstCAudioTriggersWindow_x                                0xE1EED0
#define pinstCCharacterSelect_x                                    0xF6198C
#define pinstCFacePick_x                                           0xF6173C
#define pinstCNoteWnd_x                                            0xF61944
#define pinstCBookWnd_x                                            0xF6194C
#define pinstCPetInfoWnd_x                                         0xF61950
#define pinstCTrainWnd_x                                           0xF61954
#define pinstCSkillsWnd_x                                          0xF61958
#define pinstCSkillsSelectWnd_x                                    0xF6195C
#define pinstCCombatSkillsSelectWnd_x                              0xF61960
#define pinstCFriendsWnd_x                                         0xF61964
#define pinstCAuraWnd_x                                            0xF61968
#define pinstCRespawnWnd_x                                         0xF6196C
#define pinstCBandolierWnd_x                                       0xF61970
#define pinstCPotionBeltWnd_x                                      0xF61974
#define pinstCAAWnd_x                                              0xF61978
#define pinstCAlarmWnd_x                                           0xF61984
#define pinstCGroupSearchFiltersWnd_x                              0xF6197C
#define pinstCLoadskinWnd_x                                        0xF61980
#define pinstCLargeDialogWnd_x                                     0x11BA978
#define pinstCMusicPlayerWnd_x                                     0xF61988
#define pinstCMailWnd_x                                            0xF61990
#define pinstCMailCompositionWnd_x                                 0xF61994
#define pinstCMailAddressBookWnd_x                                 0xF61998
#define pinstCRaidWnd_x                                            0xF619A0
#define pinstCRaidOptionsWnd_x                                     0xF619A4
#define pinstCBreathWnd_x                                          0xF619A8
#define pinstCMapViewWnd_x                                         0xF619AC
#define pinstCMapToolbarWnd_x                                      0xF619B0
#define pinstCEditLabelWnd_x                                       0xF619B4
#define pinstCTargetWnd_x                                          0xF619B8
#define pinstCColorPickerWnd_x                                     0xF619BC
#define pinstCPlayerWnd_x                                          0xF619C0
#define pinstCOptionsWnd_x                                         0xF619C4
#define pinstCBuffWindowNORMAL_x                                   0xF619C8
#define pinstCBuffWindowSHORT_x                                    0xF619CC
#define pinstCharacterCreation_x                                   0xF619D0
#define pinstCCursorAttachment_x                                   0xF619D4
#define pinstCCastingWnd_x                                         0xF619D8
#define pinstCCastSpellWnd_x                                       0xF619DC
#define pinstCSpellBookWnd_x                                       0xF619E0
#define pinstCInventoryWnd_x                                       0xF619E4
#define pinstCBankWnd_x                                            0xF619EC
#define pinstCQuantityWnd_x                                        0xF619F0
#define pinstCLootWnd_x                                            0xF619F4
#define pinstCActionsWnd_x                                         0xF619F8
#define pinstCCombatAbilityWnd_x                                   0xF61A00
#define pinstCMerchantWnd_x                                        0xF61A04
#define pinstCTradeWnd_x                                           0xF61A08
#define pinstCSelectorWnd_x                                        0xF61A0C
#define pinstCBazaarWnd_x                                          0xF61A10
#define pinstCBazaarSearchWnd_x                                    0xF61A14
#define pinstCGiveWnd_x                                            0xF61A30
#define pinstCTrackingWnd_x                                        0xF61A38
#define pinstCInspectWnd_x                                         0xF61A3C
#define pinstCSocialEditWnd_x                                      0xF61A40
#define pinstCFeedbackWnd_x                                        0xF61A44
#define pinstCBugReportWnd_x                                       0xF61A48
#define pinstCVideoModesWnd_x                                      0xF61A4C
#define pinstCTextEntryWnd_x                                       0xF61A54
#define pinstCFileSelectionWnd_x                                   0xF61A58
#define pinstCCompassWnd_x                                         0xF61A5C
#define pinstCPlayerNotesWnd_x                                     0xF61A60
#define pinstCGemsGameWnd_x                                        0xF61A64
#define pinstCTimeLeftWnd_x                                        0xF61A68
#define pinstCPetitionQWnd_x                                       0xF61A84
#define pinstCSoulmarkWnd_x                                        0xF61A88
#define pinstCStoryWnd_x                                           0xF61A8C
#define pinstCJournalTextWnd_x                                     0xF61A90
#define pinstCJournalCatWnd_x                                      0xF61A94
#define pinstCBodyTintWnd_x                                        0xF61A98
#define pinstCServerListWnd_x                                      0xF61A9C
#define pinstCAvaZoneWnd_x                                         0xF61AA8
#define pinstCBlockedBuffWnd_x                                     0xF61AAC
#define pinstCBlockedPetBuffWnd_x                                  0xF61AB0
#define pinstCInvSlotMgr_x                                         0xF61AF4
#define pinstCContainerMgr_x                                       0xF61AF8
#define pinstCAdventureLeaderboardWnd_x                            0x11B47A0
#define pinstCAdventureRequestWnd_x                                0x11B4818
#define pinstCAltStorageWnd_x                                      0x11B4AF8
#define pinstCAdventureStatsWnd_x                                  0x11B4890
#define pinstCBarterMerchantWnd_x                                  0x11B56E0
#define pinstCBarterSearchWnd_x                                    0x11B5758
#define pinstCBarterWnd_x                                          0x11B57D0
#define pinstCChatManager_x                                        0x11B5E60
#define pinstCDynamicZoneWnd_x                                     0x11B6310
#define pinstCEQMainWnd_x                                          0x11B64A8
#define pinstCFellowshipWnd_x                                      0x11B62A4
#define pinstCFindLocationWnd_x                                    0x11B6778
#define pinstCGroupSearchWnd_x                                     0x11B6A48
#define pinstCGroupWnd_x                                           0x11B6AC0
#define pinstCGuildBankWnd_x                                       0x11B6B38
#define pinstCGuildMgmtWnd_x                                       0x11B8C28
#define pinstCHotButtonWnd_x                                       0x11B8D24
#define pinstCHotButtonWnd1_x                                      0x11B8D24
#define pinstCHotButtonWnd2_x                                      0x11B8D28
#define pinstCHotButtonWnd3_x                                      0x11B8D2C
#define pinstCHotButtonWnd4_x                                      0x11B8D50
#define pinstCItemDisplayManager_x                                 0x11B9048
#define pinstCItemExpTransferWnd_x                                 0x11B90C4
#define pinstCLFGuildWnd_x                                         0x11B93A0
#define pinstCMIZoneSelectWnd_x                                    0x11B9988
#define pinstCConfirmationDialog_x                                 0x11BA090
#define pinstCPopupWndManager_x                                    0x11BA090
#define pinstCProgressionSelectionWnd_x                            0x11BA180
#define pinstCPvPStatsWnd_x                                        0x11BA270
#define pinstCTaskWnd_x                                            0x11BBD40
#define pinstCTaskSomething_x                                      0xE2FB70
#define pinstCTaskTemplateSelectWnd_x                              0x11BBCC8
#define pinstCTipWndOFDAY_x                                        0x11BBEA8
#define pinstCTipWndCONTEXT_x                                      0x11BBEAC
#define pinstCTitleWnd_x                                           0x11BBF28
#define pinstCContextMenuManager_x                                 0x181F91C
#define pinstCVoiceMacroWnd_x                                      0x10A8C28
#define pinstCHtmlWnd_x                                            0x10A8D18
#define pinstIconCache_x                                           0x11B647C
#define pinstCTradeskillWnd_x                                      0x11BC028
#define pinstCAdvancedLootWnd_x                                    0xF61AE8
#define pinstRewardSelectionWnd_x                                  0x11BA798

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x538730
#define __ConvertItemTags_x                                        0x525FF0
#define __ExecuteCmd_x                                             0x5108B0
#define __EQGetTime_x                                              0x896FD0
#define __get_melee_range_x                                        0x517480
#define __GetGaugeValueFromEQ_x                                    0x7A98E0
#define __GetLabelFromEQ_x                                         0x7AAB30
#define __ToggleKeyRingItem_x                                      0x47FE80
#define __GetXTargetType_x                                         0x928030
#define __LoadFrontEnd_x                                           0x637FB0
#define __NewUIINI_x                                               0x7A92B0
#define __ProcessGameEvents_x                                      0x57BC10
#define __ProcessMouseEvent_x                                      0x57B3B0
#define CrashDetected_x                                            0x639970
#define wwsCrashReportCheckForUploader_x                           0x7F7530
#define DrawNetStatus_x                                            0x5B1E70
#define Util__FastTime_x                                           0x896C70
#define Expansion_HoT_x                                            0x10236B8
#define __HelpPath_x                                               0x10A6DB0
#define __STMLToText_x                                             0x8DCDA0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420500
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B2B0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B090

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C7230
#define AltAdvManager__IsAbilityReady_x                            0x4C72A0
#define AltAdvManager__GetAAById_x                                 0x4C7660
#define AltAdvManager__CanTrainAbility_x                           0x4C7F60
#define AltAdvManager__CanSeeAbility_x                             0x4C7B20

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463460
#define CharacterZoneClient__MakeMeVisible_x                       0x467E20
#define CharacterZoneClient__IsStackBlocked_x                      0x447950
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x446E10
#define CharacterZoneClient__GetItemCountWorn_x                    0x461290
#define CharacterZoneClient__GetItemCountInInventory_x             0x461370
#define CharacterZoneClient__GetCursorItemCount_x                  0x461450

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x667AD0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x675F20

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5912D0
#define CButtonWnd__CButtonWnd_x                                   0x8D11C0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x690E50
#define CChatManager__InitContextMenu_x                            0x6919D0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DB100
#define CContextMenu__dCContextMenu_x                              0x8DB310
#define CContextMenu__AddMenuItem_x                                0x8DB320
#define CContextMenu__RemoveMenuItem_x                             0x8DB610
#define CContextMenu__RemoveAllMenuItems_x                         0x8DB630
#define CContextMenuManager__AddMenu_x                             0x8C7750
#define CContextMenuManager__RemoveMenu_x                          0x8C7AF0
#define CContextMenuManager__PopupMenu_x                           0x8C7F40
#define CContextMenuManager__Flush_x                               0x8C77C0
#define CContextMenuManager__GetMenu_x                             0x4169A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87BB20
#define CChatService__GetFriendName_x                              0x87BB30

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x696C30
#define CChatWindow__Clear_x                                       0x696800
#define CChatWindow__WndNotification_x                             0x697170

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CB5B0
#define CComboWnd__Draw_x                                          0x8CB7C0
#define CComboWnd__GetCurChoice_x                                  0x8CB360
#define CComboWnd__GetListRect_x                                   0x8CBA60
#define CComboWnd__GetTextRect_x                                   0x8CB620
#define CComboWnd__InsertChoice_x                                  0x8CBAD0
#define CComboWnd__SetColors_x                                     0x8CB2F0
#define CComboWnd__SetChoice_x                                     0x8CB320
#define CComboWnd__GetItemCount_x                                  0x8CB350
#define CComboWnd__GetCurChoiceText_x                              0x8CB3A0


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A02F0
#define CContainerWnd__vftable_x                                   0xADC140

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B5600
#define CDisplay__GetClickedActor_x                                0x4ADF40
#define CDisplay__GetUserDefinedColor_x                            0x4ACB20
#define CDisplay__GetWorldFilePath_x                               0x4ABF70
#define CDisplay__is3dON_x                                         0x4AB400
#define CDisplay__ReloadUI_x                                       0x4C0B70
#define CDisplay__WriteTextHD2_x                                   0x4B19C0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F1730

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DF630
#define CEditWnd__GetCharIndexPt_x                                 0x8E06C0
#define CEditWnd__GetDisplayString_x                               0x8DF7E0
#define CEditWnd__GetHorzOffset_x                                  0x8DFB20
#define CEditWnd__GetLineForPrintableChar_x                        0x8E0190
#define CEditWnd__GetSelStartPt_x                                  0x8E0970
#define CEditWnd__GetSTMLSafeText_x                                0x8DFCC0
#define CEditWnd__PointFromPrintableChar_x                         0x8E0280
#define CEditWnd__SelectableCharFromPoint_x                        0x8E0400
#define CEditWnd__SetEditable_x                                    0x8DFC90

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x55C810
#define CEverQuest__CreateTargetIndicator_x                        0x55D700
#define CEverQuest__DeleteTargetIndicator_x                        0x55D780
#define CEverQuest__DoTellWindow_x                                 0x472A80
#define CEverQuest__DropHeldItemOnGround_x                         0x573910
#define CEverQuest__dsp_chat_x                                     0x472DC0
#define CEverQuest__trimName_x                                     0x559160
#define CEverQuest__Emote_x                                        0x571C60
#define CEverQuest__EnterZone_x                                    0x56CC50
#define CEverQuest__GetBodyTypeDesc_x                              0x556BC0
#define CEverQuest__GetClassDesc_x                                 0x560490
#define CEverQuest__GetClassThreeLetterCode_x                      0x560A90
#define CEverQuest__GetDeityDesc_x                                 0x5574A0
#define CEverQuest__GetLangDesc_x                                  0x556F50
#define CEverQuest__GetRaceDesc_x                                  0x560C50
#define CEverQuest__InterpretCmd_x                                 0x564A80
#define CEverQuest__LeftClickedOnPlayer_x                          0x5782D0
#define CEverQuest__LMouseUp_x                                     0x57A3D0
#define CEverQuest__RightClickedOnPlayer_x                         0x578DE0
#define CEverQuest__RMouseUp_x                                     0x579E30
#define CEverQuest__SetGameState_x                                 0x55D0D0
#define CEverQuest__UPCNotificationFlush_x                         0x5549D0
#define CEverQuest__IssuePetCommand_x                              0x565460

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B1060
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B10C0
#define CGaugeWnd__Draw_x                                          0x6B14F0

// CGuild
#define CGuild__FindMemberByName_x                                 0x437330
#define CGuild__GetGuildName_x                                     0x437800
#define CGuild__GetGuildIndex_x                                    0x4389D0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CD5F0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DA790
#define CInvSlotMgr__MoveItem_x                                    0x6DB640
#define CInvSlotMgr__SelectSlot_x                                  0x6DA840

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D9C40
#define CInvSlot__SliderComplete_x                                 0x6D7450
#define CInvSlot__GetItemBase_x                                    0x6D68C0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DCA70

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A52C0
#define CItemDisplayWnd__UpdateStrings_x                           0x6DEBD0

// CLabel 
#define CLabel__Draw_x                                             0x6F86B0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B7150
#define CListWnd__dCListWnd_x                                      0x8B8360
#define CListWnd__AddColumn_x                                      0x8B8300
#define CListWnd__AddColumn1_x                                     0x8B79A0
#define CListWnd__AddLine_x                                        0x8B7400
#define CListWnd__AddString_x                                      0x8B7620
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B43D0
#define CListWnd__CalculateVSBRange_x                              0x8B6610
#define CListWnd__ClearSel_x                                       0x8B36E0
#define CListWnd__ClearAllSel_x                                    0x8B3690
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B6FE0
#define CListWnd__Compare_x                                        0x8B4F40
#define CListWnd__Draw_x                                           0x8B6210
#define CListWnd__DrawColumnSeparators_x                           0x8B60A0
#define CListWnd__DrawHeader_x                                     0x8B39A0
#define CListWnd__DrawItem_x                                       0x8B55D0
#define CListWnd__DrawLine_x                                       0x8B5D40
#define CListWnd__DrawSeparator_x                                  0x8B6140
#define CListWnd__EnsureVisible_x                                  0x8B4530
#define CListWnd__ExtendSel_x                                      0x8B54E0
#define CListWnd__GetColumnMinWidth_x                              0x8B3090
#define CListWnd__GetColumnWidth_x                                 0x8B2FC0
#define CListWnd__GetCurSel_x                                      0x8B2780
#define CListWnd__GetItemAtPoint_x                                 0x8B47D0
#define CListWnd__GetItemAtPoint1_x                                0x8B4840
#define CListWnd__GetItemData_x                                    0x8B2AD0
#define CListWnd__GetItemHeight_x                                  0x8B4020
#define CListWnd__GetItemIcon_x                                    0x8B2CC0
#define CListWnd__GetItemRect_x                                    0x8B4610
#define CListWnd__GetItemText_x                                    0x8B2B70
#define CListWnd__GetSelList_x                                     0x8B7890
#define CListWnd__GetSeparatorRect_x                               0x8B4E60
#define CListWnd__RemoveLine_x                                     0x8B7810
#define CListWnd__SetColors_x                                      0x8B28D0
#define CListWnd__SetColumnJustification_x                         0x8B3320
#define CListWnd__SetColumnWidth_x                                 0x8B3040
#define CListWnd__SetCurSel_x                                      0x8B27C0
#define CListWnd__SetItemColor_x                                   0x8B6CD0
#define CListWnd__SetItemData_x                                    0x8B3740
#define CListWnd__SetItemText_x                                    0x8B6B10
#define CListWnd__ShiftColumnSeparator_x                           0x8B69A0
#define CListWnd__Sort_x                                           0x8B8460
#define CListWnd__ToggleSel_x                                      0x8B3610

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7118A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x732C70
#define CMerchantWnd__RequestBuyItem_x                             0x739D20
#define CMerchantWnd__RequestSellItem_x                            0x73A7F0
#define CMerchantWnd__SelectRecoverySlot_x                         0x732F20
#define CMerchantWnd__SelectBuySellSlot_x                          0x732120
#define CMerchantWnd__ActualSelect_x                               0x736BF0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x84B230
#define CPacketScrambler__hton_x                                   0x84B240

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D6120
#define CSidlManager__CreateLabel_x                                0x79B240

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65EE60
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65ED80
#define CSidlScreenWnd__ConvertToRes_x                             0x8F1610
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CDF60
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CF110
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CF1C0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CE6B0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CD910
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CD060
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CDB00
#define CSidlScreenWnd__Init1_x                                    0x8CEE00
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CE010
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CD220
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CE8F0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CCCC0
#define CSidlScreenWnd__StoreIniVis_x                              0x8CD010
#define CSidlScreenWnd__WndNotification_x                          0x8CEB80
#define CSidlScreenWnd__GetChildItem_x                             0x8CD130
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C0940
#define CSidlScreenWnd__m_layoutCopy_x                             0x181F980

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FD8B0
#define CSkillMgr__GetSkillCap_x                                   0x5FDA90
#define CSkillMgr__GetNameToken_x                                  0x5FD4D0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F08D0
#define CSliderWnd__SetValue_x                                     0x8F0AA0
#define CSliderWnd__SetNumTicks_x                                  0x8F1220

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A2F20

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EC290
#define CStmlWnd__CalculateHSBRange_x                              0x8E47D0
#define CStmlWnd__CalculateVSBRange_x                              0x8E4860
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E49E0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E52C0
#define CStmlWnd__ForceParseNow_x                                  0x8ECBE0
#define CStmlWnd__GetNextTagPiece_x                                0x8E51C0
#define CStmlWnd__GetSTMLText_x                                    0x6960A0
#define CStmlWnd__GetVisibleText_x                                 0x8E5D10
#define CStmlWnd__InitializeWindowVariables_x                      0x8E80A0
#define CStmlWnd__MakeStmlColorTag_x                               0x8E3AD0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E3B30
#define CStmlWnd__SetSTMLText_x                                    0x8E9900
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EBF30
#define CStmlWnd__UpdateHistoryString_x                            0x8E6C50

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E31F0
#define CTabWnd__DrawCurrentPage_x                                 0x8E2A80
#define CTabWnd__DrawTab_x                                         0x8E2840
#define CTabWnd__GetCurrentPage_x                                  0x8E2E30
#define CTabWnd__GetPageInnerRect_x                                0x8E2530
#define CTabWnd__GetTabInnerRect_x                                 0x8E2730
#define CTabWnd__GetTabRect_x                                      0x8E2600
#define CTabWnd__InsertPage_x                                      0x8E34E0
#define CTabWnd__SetPage_x                                         0x8E2E60
#define CTabWnd__SetPageRect_x                                     0x8E3130
#define CTabWnd__UpdatePage_x                                      0x8E3480

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432F50

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CAF60

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x636230

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F69F0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B09E0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59E860
#define CXStr__CXStr1_x                                            0x4E7550
#define CXStr__CXStr3_x                                            0x893F10
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x894080
#define CXStr__operator_equal1_x                                   0x8940D0
#define CXStr__operator_plus_equal1_x                              0x8951D0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BFB70
#define CXWnd__Center_x                                            0x8C5D60
#define CXWnd__ClrFocus_x                                          0x8BF740
#define CXWnd__DoAllDrawing_x                                      0x8C59B0
#define CXWnd__DrawChildren_x                                      0x8C5B50
#define CXWnd__DrawColoredRect_x                                   0x8BFF50
#define CXWnd__DrawTooltip_x                                       0x8C0200
#define CXWnd__DrawTooltipAtPoint_x                                0x8C4920
#define CXWnd__GetBorderFrame_x                                    0x8C0610
#define CXWnd__GetChildWndAt_x                                     0x8C6720
#define CXWnd__GetClientClipRect_x                                 0x8C0410
#define CXWnd__GetScreenClipRect_x                                 0x8C5020
#define CXWnd__GetScreenRect_x                                     0x8C07E0
#define CXWnd__GetTooltipRect_x                                    0x8C0090
#define CXWnd__GetWindowTextA_x                                    0x424590
#define CXWnd__IsActive_x                                          0x8BB160
#define CXWnd__IsDescendantOf_x                                    0x8C0550
#define CXWnd__IsReallyVisible_x                                   0x8C3950
#define CXWnd__IsType_x                                            0x8F3230
#define CXWnd__Move_x                                              0x8C3030
#define CXWnd__Move1_x                                             0x8C5660
#define CXWnd__ProcessTransition_x                                 0x8BFB10
#define CXWnd__Refade_x                                            0x8BF8F0
#define CXWnd__Resize_x                                            0x8C08A0
#define CXWnd__Right_x                                             0x8C4E20
#define CXWnd__SetFocus_x                                          0x8C2180
#define CXWnd__SetFont_x                                           0x8BF790
#define CXWnd__SetKeyTooltip_x                                     0x8C0B10
#define CXWnd__SetMouseOver_x                                      0x8C5350
#define CXWnd__StartFade_x                                         0x8BFBC0
#define CXWnd__GetChildItem_x                                      0x8C52A0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BC9E0
#define CXWndManager__DrawWindows_x                                0x8BC620
#define CXWndManager__GetKeyboardFlags_x                           0x8BAC90
#define CXWndManager__HandleKeyboardMsg_x                          0x8BB600
#define CXWndManager__RemoveWnd_x                                  0x8BB2F0

// CDBStr
#define CDBStr__GetString_x                                        0x4A9980

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44DED0
#define EQ_Character__Cur_HP_x                                     0x462B00
#define EQ_Character__Cur_Mana_x                                   0x456630
#define EQ_Character__GetAACastingTimeModifier_x                   0x447120
#define EQ_Character__GetCharInfo2_x                               0x867AF0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F470
#define EQ_Character__GetFocusRangeModifier_x                      0x43F4D0
#define EQ_Character__Max_Endurance_x                              0x5C39F0
#define EQ_Character__Max_HP_x                                     0x459250
#define EQ_Character__Max_Mana_x                                   0x5C3820
#define EQ_Character__doCombatAbility_x                            0x5C0F10
#define EQ_Character__UseSkill_x                                   0x46CEA0
#define EQ_Character__GetConLevel_x                                0x5B6480
#define EQ_Character__IsExpansionFlag_x                            0x423AE0
#define EQ_Character__TotalEffect_x                                0x44B170
#define EQ_Character__GetPCSpellAffect_x                           0x447520
#define EQ_Character__SpellDuration_x                              0x445420
#define EQ_Character__FindItemByRecord_x                           0x45FF80

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x442770
#define CCharacterSelect__EnterWorld_x                             0x441F40
#define CCharacterSelect__Quit_x                                   0x440B20

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x596B30
#define EQ_Item__CreateItemTagString_x                             0x849B50
#define EQ_Item__IsStackable_x                                     0x83F2B0
#define EQ_Item__GetImageNum_x                                     0x841CD0
#define EQ_Item__CreateItemClient_x                                0x597720
#define EQ_Item__GetItemValue_x                                    0x848890
#define EQ_Item__ValueSellMerchant_x                               0x84AE80
#define EQ_Item__IsKeyRingItem_x                                   0x83FD00
#define EQ_Item__CanGoInBag_x                                      0x596CC0
#define EQ_Item__GetMaxItemCount_x                                 0x83F1A0
#define EQ_Item__GetHeldItem_x                                     0x840AF0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C93E0
#define EQ_LoadingS__Array_x                                       0xC1D680

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C5F10
#define EQ_PC__GetAlternateAbilityId_x                             0x853230
#define EQ_PC__GetCombatAbility_x                                  0x8532C0
#define EQ_PC__GetCombatAbilityTimer_x                             0x84E040
#define EQ_PC__GetItemTimerValue_x                                 0x5BF5C0
#define EQ_PC__HasLoreItem_x                                       0x5B9990
#define EQ_PC__AlertInventoryChanged_x                             0x5B6450
#define EQ_PC__GetPcZoneClient_x                                   0x5E05D0
#define EQ_PC__RemoveMyAffect_x                                    0x5BEA50
#define EQ_PC__GetKeyRingItems_x                                   0x84E460

// EQItemList 
#define EQItemList__EQItemList_x                                   0x515530
#define EQItemList__add_object_x                                   0x541400
#define EQItemList__add_item_x                                     0x515470
#define EQItemList__delete_item_x                                  0x515920
#define EQItemList__FreeItemList_x                                 0x515820

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A8C80

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5CB5E0
#define EQPlayer__dEQPlayer_x                                      0x5D44B0
#define EQPlayer__DoAttack_x                                       0x5E64D0
#define EQPlayer__EQPlayer_x                                       0x5D6BC0
#define EQPlayer__SetNameSpriteState_x                             0x5D1400
#define EQPlayer__SetNameSpriteTint_x                              0x5CC9F0
#define PlayerBase__HasProperty_j_x                                0x924280
#define EQPlayer__IsTargetable_x                                   0x924B80
#define EQPlayer__CanSee_x                                         0x9250A0
#define PlayerZoneClient__ChangeHeight_x                           0x5E6390
#define EQPlayer__CanSeeTargetIndicator_x                          0x925190
#define PlayerBase__GetVisibilityLineSegment_x                     0x924E30

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5DAC20
#define EQPlayerManager__GetSpawnByName_x                          0x5DB080
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5DAC50

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59CC00
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59CC40
#define KeypressHandler__ClearCommandStateArray_x                  0x59C7F0
#define KeypressHandler__HandleKeyDown_x                           0x59B150
#define KeypressHandler__HandleKeyUp_x                             0x59B470
#define KeypressHandler__SaveKeymapping_x                          0x59C8C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70A230
#define MapViewMap__SaveEx_x                                       0x70D560

#define PlayerPointManager__GetAltCurrency_x                       0x865C20

// StringTable 
#define StringTable__getString_x                                   0x8606B0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C3480
#define PcZoneClient__RemovePetEffect_x                            0x5BFA90
#define PcZoneClient__HasAlternateAbility_x                        0x5C0430
#define PcZoneClient__GetCurrentMod_x                              0x4585F0
#define PcZoneClient__GetModCap_x                                  0x455DB0
#define PcZoneClient__CanEquipItem_x                               0x5C09E0

//Doors
#define EQSwitch__UseSwitch_x                                      0x553290

//IconCache
#define IconCache__GetIcon_x                                       0x6A6920

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69D680
#define CContainerMgr__CloseContainer_x                            0x69DEA0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76B070

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58FD50

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E3380
#define EQ_Spell__SpellAffects_x                                   0x4E0A30
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4E0AA0
#define CharacterZoneClient__CalcAffectChange_x                    0x446550
#define CLootWnd__LootAll_x                                        0x6FFA90
#define CLootWnd__RequestLootSlot_x                                0x7002A0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B1DA0
#define CTargetWnd__WndNotification_x                              0x7B1890
#define CTargetWnd__RefreshTargetBuffs_x                           0x7B1F80

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B7000

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4DC050

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4986A0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DEC60
#define CSidlManager__FindAnimation1_x                             0x8D4020

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D0A80
#define CAltAbilityData__GetMercMaxRank_x                          0x4D0A30
#define CAltAbilityData__GetMaxRank_x                              0x4C58E0

//CTargetRing
#define CTargetRing__Cast_x                                        0x58D620

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x454D50
#define CharacterBase__CreateItemGlobalIndex_x                     0x471C70
#define CharacterBase__CreateItemIndex_x                           0x50EA00
#define CharacterBase__GetItemPossession_x                         0x50FE50
#define CharacterBase__GetItemByGlobalIndex_x                      0x875C40

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x687FD0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x687730

//messages
#define msg_spell_worn_off_x                                       0x4EAFF0
#define msg_new_text_x                                             0x4F4590
#define msgTokenTextParam_x                                        0x4F0F40

//SpellManager
#define SpellManager__vftable_x                                    0xAB8010
#define SpellManager__SpellManager_x                               0x47AB00
#define Spellmanager__CheckSpellRequirementAssociations_x          0x604760

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x928B70

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E7530
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43AC00
#define ItemGlobalIndex__IsEquippedLocation_x                      0x444DE0
#define ItemGlobalIndex__IsValidIndex_x                            0x4545E0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x873A50
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x872990

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F8900
