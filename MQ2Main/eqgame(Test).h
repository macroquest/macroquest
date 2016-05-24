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
#define __ExpectedVersionDate                                     "May 23 2016"
#define __ExpectedVersionTime                                     "12:09:13"
#define __ActualVersionDate_x                                      0xACB050
#define __ActualVersionTime_x                                      0xACB05C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59C6E0
#define __MemChecker1_x                                            0x8948E0
#define __MemChecker2_x                                            0x6326B0
#define __MemChecker3_x                                            0x632600
#define __MemChecker4_x                                            0x7E3CB0
#define __EncryptPad0_x                                            0xC69828
#define __EncryptPad1_x                                            0xDF40A8
#define __EncryptPad2_x                                            0xCB22E8
#define __EncryptPad3_x                                            0xCB1EE8
#define __EncryptPad4_x                                            0xDCAEB8
#define __EncryptPad5_x                                            0x11A0070
#define __AC1_x                                                    0x7A4095
#define __AC2_x                                                    0x556717
#define __AC3_x                                                    0x5548B0
#define __AC4_x                                                    0x5670B0
#define __AC5_x                                                    0x579B6B
#define __AC6_x                                                    0x57D70E
#define __AC7_x                                                    0x57422C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E4E80

// Direct Input
#define DI8__Main_x                                                0x11A0048
#define DI8__Keyboard_x                                            0x11A004C
#define DI8__Mouse_x                                               0x11A0050
#define DI8__Mouse_Copy_x                                          0x100E7A4
#define DI8__Mouse_Check_x                                         0x1097F34
#define __Attack_x                                                 0x1092C7B
#define __Autofire_x                                               0x1092C7C
#define __BindList_x                                               0xC2B480
#define g_eqCommandStates_x                                        0xFFDC08
#define __Clicks_x                                                 0x100E860
#define __CommandList_x                                            0xC2F850
#define __CurrentMapLabel_x                                        0x11A5AA0
#define __CurrentSocial_x                                          0xBE1FB8
#define __DoAbilityList_x                                          0x1044F30
#define __do_loot_x                                                0x51B2E0
#define __DrawHandler_x                                            0x180C4BC
#define __GroupCount_x                                             0xFFF1D2

#define __Guilds_x                                                 0x1004DE8
#define __gWorld_x                                                 0x100168C
#define __HotkeyPage_x                                             0x108B930
#define __HWnd_x                                                   0x1097F50
#define __InChatMode_x                                             0x100E78C
#define __LastTell_x                                               0x101062C
#define __LMouseHeldTime_x                                         0x100E8CC
#define __Mouse_x                                                  0x11A0054
#define __MouseLook_x                                              0x100E826
#define __MouseEventTime_x                                         0x109347C
#define __gpbCommandEvent_x                                        0x1001754
#define __NetStatusToggle_x                                        0x100E829
#define __PCNames_x                                                0x100FC50
#define __RangeAttackReady_x                                       0x100F98C
#define __RMouseHeldTime_x                                         0x100E8C8
#define __RunWalkState_x                                           0x100E790
#define __ScreenMode_x                                             0xF4D988
#define __ScreenX_x                                                0x100E744
#define __ScreenY_x                                                0x100E740
#define __ScreenXMax_x                                             0x100E748
#define __ScreenYMax_x                                             0x100E74C
#define __ServerHost_x                                             0xFFF11C
#define __ServerName_x                                             0x1044EF0
#define __ShiftKeyDown_x                                           0x100EE18
#define __ShowNames_x                                              0x100FB4C
#define __Socials_x                                                0x1044FF0
#define __SubscriptionType_x                                       0x11D3B50
#define __TargetAggroHolder_x                                      0x11A7CDC
#define __ZoneType_x                                               0x100EC24
#define __GroupAggro_x                                             0x11A7D1C
#define __LoginName_x                                              0x1096B2C
#define __Inviter_x                                                0x1092BF8
#define __AttackOnAssist_x                                         0x100FB08

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x1001778
#define instEQZoneInfo_x                                           0x100EA1C
#define instKeypressHandler_x                                      0x1093460
#define pinstActiveBanker_x                                        0x1001730
#define pinstActiveCorpse_x                                        0x1001734
#define pinstActiveGMaster_x                                       0x1001738
#define pinstActiveMerchant_x                                      0x100172C
#define pinstAggroInfo_x                                           0xE0FCC8
#define pinstAltAdvManager_x                                       0xF4EA48
#define pinstAuraMgr_x                                             0xE1BC50
#define pinstBandageTarget_x                                       0x1001718
#define pinstCamActor_x                                            0xF4E39C
#define pinstCDBStr_x                                              0xF4D91C
#define pinstCDisplay_x                                            0x1001740
#define pinstCEverQuest_x                                          0x11A01C8
#define pinstCharData_x                                            0x10016FC
#define pinstCharSpawn_x                                           0x1001724
#define pinstControlledMissile_x                                   0x10016F8
#define pinstControlledPlayer_x                                    0x1001724
#define pinstCSidlManager_x                                        0x180B9FC
#define pinstCXWndManager_x                                        0x180B9F4
#define instDynamicZone_x                                          0x100E5D8
#define pinstDZMember_x                                            0x100E6E8
#define pinstDZTimerInfo_x                                         0x100E6EC
#define pinstEQItemList_x                                          0xFFDE58
#define pinstEQObjectList_x                                        0xFFEBCC
#define instEQMisc_x                                               0xC05CF8
#define pinstEQSoundManager_x                                      0xF4EFA0
#define instExpeditionLeader_x                                     0x100E622
#define instExpeditionName_x                                       0x100E662
#define pinstGroup_x                                               0xFFF1CE
#define pinstImeManager_x                                          0x180BA00
#define pinstLocalPlayer_x                                         0x1001710
#define pinstMercenaryData_x                                       0x1093AB0
#define pinstMercenaryStats_x                                      0x11A7E28
#define pinstMercAltAbilities_x                                    0xF4EDD0
#define pinstModelPlayer_x                                         0x100173C
#define pinstPCData_x                                              0x10016FC
#define pinstSkillMgr_x                                            0x10948E8
#define pinstSpawnManager_x                                        0x10941D0
#define pinstSpellManager_x                                        0x1094A30
#define pinstSpellSets_x                                           0x108B994
#define pinstStringTable_x                                         0x10016A4
#define pinstSwitchManager_x                                       0xFFED60
#define pinstTarget_x                                              0x1001728
#define pinstTargetObject_x                                        0x1001700
#define pinstTargetSwitch_x                                        0x1001704
#define pinstTaskMember_x                                          0xF4D868
#define pinstTrackTarget_x                                         0x100171C
#define pinstTradeTarget_x                                         0x100170C
#define instTributeActive_x                                        0xC05D1D
#define pinstViewActor_x                                           0xF4E398
#define pinstWorldData_x                                           0x10016E0
#define pinstZoneAddr_x                                            0x100ECBC
#define pinstPlayerPath_x                                          0x1094230
#define pinstTargetIndicator_x                                     0x1094BC8
#define pinstCTargetManager_x                                      0x1094C28

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE101C0
#define pinstCAudioTriggersWindow_x                                0xE10050
#define pinstCCharacterSelect_x                                    0xF4E22C
#define pinstCFacePick_x                                           0xF4DFDC
#define pinstCNoteWnd_x                                            0xF4E1E4
#define pinstCBookWnd_x                                            0xF4E1EC
#define pinstCPetInfoWnd_x                                         0xF4E1F0
#define pinstCTrainWnd_x                                           0xF4E1F4
#define pinstCSkillsWnd_x                                          0xF4E1F8
#define pinstCSkillsSelectWnd_x                                    0xF4E1FC
#define pinstCCombatSkillsSelectWnd_x                              0xF4E200
#define pinstCFriendsWnd_x                                         0xF4E204
#define pinstCAuraWnd_x                                            0xF4E208
#define pinstCRespawnWnd_x                                         0xF4E20C
#define pinstCBandolierWnd_x                                       0xF4E210
#define pinstCPotionBeltWnd_x                                      0xF4E214
#define pinstCAAWnd_x                                              0xF4E218
#define pinstCGroupSearchFiltersWnd_x                              0xF4E21C
#define pinstCLoadskinWnd_x                                        0xF4E220
#define pinstCAlarmWnd_x                                           0xF4E224
#define pinstCMusicPlayerWnd_x                                     0xF4E228
#define pinstCMailWnd_x                                            0xF4E230
#define pinstCMailCompositionWnd_x                                 0xF4E234
#define pinstCMailAddressBookWnd_x                                 0xF4E238
#define pinstCRaidWnd_x                                            0xF4E240
#define pinstCRaidOptionsWnd_x                                     0xF4E244
#define pinstCBreathWnd_x                                          0xF4E248
#define pinstCMapViewWnd_x                                         0xF4E24C
#define pinstCMapToolbarWnd_x                                      0xF4E250
#define pinstCEditLabelWnd_x                                       0xF4E254
#define pinstCTargetWnd_x                                          0xF4E258
#define pinstCColorPickerWnd_x                                     0xF4E25C
#define pinstCPlayerWnd_x                                          0xF4E260
#define pinstCOptionsWnd_x                                         0xF4E264
#define pinstCBuffWindowNORMAL_x                                   0xF4E268
#define pinstCBuffWindowSHORT_x                                    0xF4E26C
#define pinstCharacterCreation_x                                   0xF4E270
#define pinstCCursorAttachment_x                                   0xF4E274
#define pinstCCastingWnd_x                                         0xF4E278
#define pinstCCastSpellWnd_x                                       0xF4E27C
#define pinstCSpellBookWnd_x                                       0xF4E280
#define pinstCInventoryWnd_x                                       0xF4E284
#define pinstCBankWnd_x                                            0xF4E28C
#define pinstCQuantityWnd_x                                        0xF4E290
#define pinstCLootWnd_x                                            0xF4E294
#define pinstCActionsWnd_x                                         0xF4E298
#define pinstCCombatAbilityWnd_x                                   0xF4E29C
#define pinstCMerchantWnd_x                                        0xF4E2A0
#define pinstCTradeWnd_x                                           0xF4E2A4
#define pinstCSelectorWnd_x                                        0xF4E2A8
#define pinstCBazaarWnd_x                                          0xF4E2AC
#define pinstCBazaarSearchWnd_x                                    0xF4E2B0
#define pinstCGiveWnd_x                                            0xF4E2CC
#define pinstCTrackingWnd_x                                        0xF4E2D4
#define pinstCInspectWnd_x                                         0xF4E2D8
#define pinstCSocialEditWnd_x                                      0xF4E2DC
#define pinstCFeedbackWnd_x                                        0xF4E2E0
#define pinstCBugReportWnd_x                                       0xF4E2E4
#define pinstCVideoModesWnd_x                                      0xF4E2E8
#define pinstCTextEntryWnd_x                                       0xF4E2F0
#define pinstCFileSelectionWnd_x                                   0xF4E2F4
#define pinstCCompassWnd_x                                         0xF4E2F8
#define pinstCPlayerNotesWnd_x                                     0xF4E2FC
#define pinstCGemsGameWnd_x                                        0xF4E300
#define pinstCTimeLeftWnd_x                                        0xF4E304
#define pinstCPetitionQWnd_x                                       0xF4E320
#define pinstCSoulmarkWnd_x                                        0xF4E324
#define pinstCStoryWnd_x                                           0xF4E328
#define pinstCJournalTextWnd_x                                     0xF4E32C
#define pinstCJournalCatWnd_x                                      0xF4E330
#define pinstCBodyTintWnd_x                                        0xF4E334
#define pinstCServerListWnd_x                                      0xF4E338
#define pinstCAvaZoneWnd_x                                         0xF4E344
#define pinstCBlockedBuffWnd_x                                     0xF4E348
#define pinstCBlockedPetBuffWnd_x                                  0xF4E34C
#define pinstCInvSlotMgr_x                                         0xF4E390
#define pinstCContainerMgr_x                                       0xF4E394
#define pinstCAdventureLeaderboardWnd_x                            0x11A0B78
#define pinstCAdventureRequestWnd_x                                0x11A0BF0
#define pinstCAltStorageWnd_x                                      0x11A0ED0
#define pinstCAdventureStatsWnd_x                                  0x11A0C68
#define pinstCBarterMerchantWnd_x                                  0x11A1AB8
#define pinstCBarterSearchWnd_x                                    0x11A1B30
#define pinstCBarterWnd_x                                          0x11A1BA8
#define pinstCChatManager_x                                        0x11A2238
#define pinstCDynamicZoneWnd_x                                     0x11A26E8
#define pinstCEQMainWnd_x                                          0x11A2880
#define pinstCFellowshipWnd_x                                      0x11A267C
#define pinstCFindLocationWnd_x                                    0x11A2B50
#define pinstCGroupSearchWnd_x                                     0x11A2E20
#define pinstCGroupWnd_x                                           0x11A2E98
#define pinstCGuildBankWnd_x                                       0x11A2F10
#define pinstCGuildMgmtWnd_x                                       0x11A5000
#define pinstCHotButtonWnd_x                                       0x11A50CC
#define pinstCHotButtonWnd1_x                                      0x11A50CC
#define pinstCHotButtonWnd2_x                                      0x11A50D0
#define pinstCHotButtonWnd3_x                                      0x11A50D4
#define pinstCHotButtonWnd4_x                                      0x11A50F8
#define pinstCItemDisplayManager_x                                 0x11A53F0
#define pinstCItemExpTransferWnd_x                                 0x11A546C
#define pinstCLFGuildWnd_x                                         0x11A5748
#define pinstCMIZoneSelectWnd_x                                    0x11A5D30
#define pinstCConfirmationDialog_x                                 0x11A6438
#define pinstCPopupWndManager_x                                    0x11A6438
#define pinstCProgressionSelectionWnd_x                            0x11A6528
#define pinstCPvPStatsWnd_x                                        0x11A6618
#define pinstCSystemInfoDialogBox_x                                0x11A6D20
#define pinstCTaskWnd_x                                            0x11A80E8
#define pinstCTaskSomething_x                                      0xE1C410
#define pinstCTaskTemplateSelectWnd_x                              0x11A8070
#define pinstCTipWndOFDAY_x                                        0x11A8250
#define pinstCTipWndCONTEXT_x                                      0x11A8254
#define pinstCTitleWnd_x                                           0x11A82D0
#define pinstCContextMenuManager_x                                 0x180B96C
#define pinstCVoiceMacroWnd_x                                      0x1095000
#define pinstCHtmlWnd_x                                            0x10950F0
#define pinstIconCache_x                                           0x11A2854
#define pinstCTradeskillWnd_x                                      0x11A83D0
#define pinstCAdvancedLootWnd_x                                    0xF4E384
#define pinstRewardSelectionWnd_x                                  0x11A6B40

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x532440
#define __ConvertItemTags_x                                        0x51FE40
#define __ExecuteCmd_x                                             0x50A7A0
#define __EQGetTime_x                                              0x894510
#define __get_melee_range_x                                        0x511390
#define __GetGaugeValueFromEQ_x                                    0x7A2DD0
#define __GetLabelFromEQ_x                                         0x7A4020
#define __ToggleKeyRingItem_x                                      0x47DE80
#define __GetXTargetType_x                                         0x924EB0
#define __LoadFrontEnd_x                                           0x631D80
#define __NewUIINI_x                                               0x7A27B0
#define __ProcessGameEvents_x                                      0x575F90
#define __ProcessMouseEvent_x                                      0x575730
#define CrashDetected_x                                            0x633740
#define wwsCrashReportCheckForUploader_x                           0x7F2810
#define DrawNetStatus_x                                            0x5AC400
#define Util__FastTime_x                                           0x894020
#define Expansion_HoT_x                                            0x100FAF8
#define __HelpPath_x                                               0x10931E8
#define __STMLToText_x                                             0x8D9E70

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4204C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B320
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B100

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C4AC0
#define AltAdvManager__IsAbilityReady_x                            0x4C4B30
#define AltAdvManager__GetAAById_x                                 0x4C4EF0
#define AltAdvManager__CanTrainAbility_x                           0x4C57B0
#define AltAdvManager__CanSeeAbility_x                             0x4C53B0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x462C90
#define CharacterZoneClient__MakeMeVisible_x                       0x468590
#define CharacterZoneClient__IsStackBlocked_x                      0x446FA0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x446460
#define CharacterZoneClient__GetItemCountWorn_x                    0x4606B0
#define CharacterZoneClient__GetItemCountInInventory_x             0x460790
#define CharacterZoneClient__GetCursorItemCount_x                  0x460870

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x661880

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66F820

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58B5A0
#define CButtonWnd__CButtonWnd_x                                   0x8CE1C0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68AB00
#define CChatManager__InitContextMenu_x                            0x68B680

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D81D0
#define CContextMenu__dCContextMenu_x                              0x8D83E0
#define CContextMenu__AddMenuItem_x                                0x8D83F0
#define CContextMenu__RemoveMenuItem_x                             0x8D86E0
#define CContextMenu__RemoveAllMenuItems_x                         0x8D8700
#define CContextMenuManager__AddMenu_x                             0x8C4870
#define CContextMenuManager__RemoveMenu_x                          0x8C4BB0
#define CContextMenuManager__PopupMenu_x                           0x8C5000
#define CContextMenuManager__Flush_x                               0x8C48E0
#define CContextMenuManager__GetMenu_x                             0x416960

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x879050
#define CChatService__GetFriendName_x                              0x879060

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6908C0
#define CChatWindow__Clear_x                                       0x6904A0
#define CChatWindow__WndNotification_x                             0x690DF0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C8620
#define CComboWnd__Draw_x                                          0x8C8830
#define CComboWnd__GetCurChoice_x                                  0x8C83F0
#define CComboWnd__GetListRect_x                                   0x8C8AD0
#define CComboWnd__GetTextRect_x                                   0x8C8690
#define CComboWnd__InsertChoice_x                                  0x8C8B40
#define CComboWnd__SetColors_x                                     0x8C8380
#define CComboWnd__SetChoice_x                                     0x8C83B0
#define CComboWnd__GetItemCount_x                                  0x8C83E0
#define CComboWnd__GetCurChoiceText_x                              0x8C8430

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x699E70
#define CContainerWnd__vftable_x                                   0xAD4A28

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B2E50
#define CDisplay__GetClickedActor_x                                0x4AB710
#define CDisplay__GetUserDefinedColor_x                            0x4AA2F0
#define CDisplay__GetWorldFilePath_x                               0x4A9740
#define CDisplay__is3dON_x                                         0x4A8BD0
#define CDisplay__ReloadUI_x                                       0x4BE340
#define CDisplay__WriteTextHD2_x                                   0x4AF1A0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8EE840

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DC700
#define CEditWnd__GetCharIndexPt_x                                 0x8DD7A0
#define CEditWnd__GetDisplayString_x                               0x8DC8B0
#define CEditWnd__GetHorzOffset_x                                  0x8DCBF0
#define CEditWnd__GetLineForPrintableChar_x                        0x8DD260
#define CEditWnd__GetSelStartPt_x                                  0x8DDA60
#define CEditWnd__GetSTMLSafeText_x                                0x8DCD90
#define CEditWnd__PointFromPrintableChar_x                         0x8DD350
#define CEditWnd__SelectableCharFromPoint_x                        0x8DD4D0
#define CEditWnd__SetEditable_x                                    0x8DCD60

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x556E60
#define CEverQuest__CreateTargetIndicator_x                        0x557D50
#define CEverQuest__DeleteTargetIndicator_x                        0x557DD0
#define CEverQuest__DoTellWindow_x                                 0x4731E0
#define CEverQuest__DropHeldItemOnGround_x                         0x56DEF0
#define CEverQuest__dsp_chat_x                                     0x473520
#define CEverQuest__trimName_x                                     0x5537B0
#define CEverQuest__Emote_x                                        0x56C240
#define CEverQuest__EnterZone_x                                    0x567240
#define CEverQuest__GetBodyTypeDesc_x                              0x551210
#define CEverQuest__GetClassDesc_x                                 0x55AAE0
#define CEverQuest__GetClassThreeLetterCode_x                      0x55B0E0
#define CEverQuest__GetDeityDesc_x                                 0x551AF0
#define CEverQuest__GetLangDesc_x                                  0x5515A0
#define CEverQuest__GetRaceDesc_x                                  0x55B2A0
#define CEverQuest__InterpretCmd_x                                 0x55F0B0
#define CEverQuest__LeftClickedOnPlayer_x                          0x572680
#define CEverQuest__LMouseUp_x                                     0x574780
#define CEverQuest__RightClickedOnPlayer_x                         0x573190
#define CEverQuest__RMouseUp_x                                     0x5741E0
#define CEverQuest__SetGameState_x                                 0x557720
#define CEverQuest__UPCNotificationFlush_x                         0x54F030
#define CEverQuest__IssuePetCommand_x                              0x55FA90

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AAA80
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AAAE0
#define CGaugeWnd__Draw_x                                          0x6AAF10

// CGuild
#define CGuild__FindMemberByName_x                                 0x436F20

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C6E20

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D3EB0
#define CInvSlotMgr__MoveItem_x                                    0x6D4D50
#define CInvSlotMgr__SelectSlot_x                                  0x6D3F60

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D3360
#define CInvSlot__SliderComplete_x                                 0x6D0BD0
#define CInvSlot__GetItemBase_x                                    0x6D0070

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D6180

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79E800
#define CItemDisplayWnd__UpdateStrings_x                           0x6D82C0

// CLabel 
#define CLabel__Draw_x                                             0x6F1870

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B47F0
#define CListWnd__dCListWnd_x                                      0x8B5810
#define CListWnd__AddColumn_x                                      0x8B57B0
#define CListWnd__AddColumn1_x                                     0x8B5020
#define CListWnd__AddLine_x                                        0x8B4AA0
#define CListWnd__AddString_x                                      0x8B4CB0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B1B30
#define CListWnd__CalculateVSBRange_x                              0x8B3CB0
#define CListWnd__ClearSel_x                                       0x8B0E30
#define CListWnd__ClearAllSel_x                                    0x8B0DE0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B4680
#define CListWnd__Compare_x                                        0x8B2630
#define CListWnd__Draw_x                                           0x8B38C0
#define CListWnd__DrawColumnSeparators_x                           0x8B3750
#define CListWnd__DrawHeader_x                                     0x8B10F0
#define CListWnd__DrawItem_x                                       0x8B2C80
#define CListWnd__DrawLine_x                                       0x8B33F0
#define CListWnd__DrawSeparator_x                                  0x8B37F0
#define CListWnd__EnsureVisible_x                                  0x8B1C90
#define CListWnd__ExtendSel_x                                      0x8B2B90
#define CListWnd__GetColumnMinWidth_x                              0x8B07A0
#define CListWnd__GetColumnWidth_x                                 0x8B06C0
#define CListWnd__GetCurSel_x                                      0x8AFE90
#define CListWnd__GetItemAtPoint_x                                 0x8B1F30
#define CListWnd__GetItemAtPoint1_x                                0x8B1FA0
#define CListWnd__GetItemData_x                                    0x8B01D0
#define CListWnd__GetItemHeight_x                                  0x8B1780
#define CListWnd__GetItemIcon_x                                    0x8B03B0
#define CListWnd__GetItemRect_x                                    0x8B1D70
#define CListWnd__GetItemText_x                                    0x8B0260
#define CListWnd__GetSelList_x                                     0x8B4F10
#define CListWnd__GetSeparatorRect_x                               0x8B2550
#define CListWnd__RemoveLine_x                                     0x8B4E90
#define CListWnd__SetColors_x                                      0x8AFFE0
#define CListWnd__SetColumnJustification_x                         0x8B0A70
#define CListWnd__SetColumnWidth_x                                 0x8B0750
#define CListWnd__SetCurSel_x                                      0x8AFED0
#define CListWnd__SetItemColor_x                                   0x8B4360
#define CListWnd__SetItemData_x                                    0x8B0E90
#define CListWnd__SetItemText_x                                    0x8B41A0
#define CListWnd__ShiftColumnSeparator_x                           0x8B4030
#define CListWnd__Sort_x                                           0x8B5910
#define CListWnd__ToggleSel_x                                      0x8B0D60

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70A9D0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72BD00
#define CMerchantWnd__RequestBuyItem_x                             0x732D70
#define CMerchantWnd__RequestSellItem_x                            0x733840
#define CMerchantWnd__SelectRecoverySlot_x                         0x72BFB0
#define CMerchantWnd__SelectBuySellSlot_x                          0x72B1B0
#define CMerchantWnd__ActualSelect_x                               0x72FC50

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x845FB0
#define CPacketScrambler__hton_x                                   0x845FC0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D3230
#define CSidlManager__CreateLabel_x                                0x794640

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x658B70
#define CSidlScreenWnd__CalculateVSBRange_x                        0x658AA0
#define CSidlScreenWnd__ConvertToRes_x                             0x8EE720
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CAF90
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CC120
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CC1D0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CB6B0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CA940
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CA0B0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CAB30
#define CSidlScreenWnd__Init1_x                                    0x8CBE00
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CB040
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CA270
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CB8F0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C9D10
#define CSidlScreenWnd__StoreIniVis_x                              0x8CA060
#define CSidlScreenWnd__WndNotification_x                          0x8CBB80
#define CSidlScreenWnd__GetChildItem_x                             0x8CA180
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BDC30

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F68F0
#define CSkillMgr__GetSkillCap_x                                   0x5F6AB0
#define CSkillMgr__GetNameToken_x                                  0x5F6510

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8ED9E0
#define CSliderWnd__SetValue_x                                     0x8EDBB0
#define CSliderWnd__SetNumTicks_x                                  0x8EE330

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79C460

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8E9360
#define CStmlWnd__CalculateHSBRange_x                              0x8E18B0
#define CStmlWnd__CalculateVSBRange_x                              0x8E1940
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E1AC0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E23A0
#define CStmlWnd__ForceParseNow_x                                  0x8E9CB0
#define CStmlWnd__GetNextTagPiece_x                                0x8E22A0
#define CStmlWnd__GetSTMLText_x                                    0x68FD40
#define CStmlWnd__GetVisibleText_x                                 0x8E2DF0
#define CStmlWnd__InitializeWindowVariables_x                      0x8E5180
#define CStmlWnd__MakeStmlColorTag_x                               0x8E0BB0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E0C10
#define CStmlWnd__SetSTMLText_x                                    0x8E69D0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E9000
#define CStmlWnd__UpdateHistoryString_x                            0x8E3D30

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E02D0
#define CTabWnd__DrawCurrentPage_x                                 0x8DFB60
#define CTabWnd__DrawTab_x                                         0x8DF920
#define CTabWnd__GetCurrentPage_x                                  0x8DFF10
#define CTabWnd__GetPageInnerRect_x                                0x8DF610
#define CTabWnd__GetTabInnerRect_x                                 0x8DF810
#define CTabWnd__GetTabRect_x                                      0x8DF6E0
#define CTabWnd__InsertPage_x                                      0x8E05C0
#define CTabWnd__SetPage_x                                         0x8DFF40
#define CTabWnd__SetPageRect_x                                     0x8E0210
#define CTabWnd__UpdatePage_x                                      0x8E0560

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432D10

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C7FF0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F3B40

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8ADFA0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x598BF0
#define CXStr__CXStr1_x                                            0x8A2DD0
#define CXStr__CXStr3_x                                            0x891110
#define CXStr__dCXStr_x                                            0x4C6240
#define CXStr__operator_equal_x                                    0x891280
#define CXStr__operator_equal1_x                                   0x8912D0
#define CXStr__operator_plus_equal1_x                              0x8923D0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BCE80
#define CXWnd__Center_x                                            0x8C2ED0
#define CXWnd__ClrFocus_x                                          0x8BCA60
#define CXWnd__DoAllDrawing_x                                      0x8C2B20
#define CXWnd__DrawChildren_x                                      0x8C2CC0
#define CXWnd__DrawColoredRect_x                                   0x8BD220
#define CXWnd__DrawTooltip_x                                       0x8BD4D0
#define CXWnd__DrawTooltipAtPoint_x                                0x8C1AB0
#define CXWnd__GetBorderFrame_x                                    0x8BD930
#define CXWnd__GetChildWndAt_x                                     0x8C3880
#define CXWnd__GetClientClipRect_x                                 0x8BD6F0
#define CXWnd__GetScreenClipRect_x                                 0x8C21B0
#define CXWnd__GetScreenRect_x                                     0x8BDAD0
#define CXWnd__GetTooltipRect_x                                    0x8BD360
#define CXWnd__GetWindowTextA_x                                    0x4244D0
#define CXWnd__IsActive_x                                          0x8B85B0
#define CXWnd__IsDescendantOf_x                                    0x8BD880
#define CXWnd__IsReallyVisible_x                                   0x8C0AF0
#define CXWnd__IsType_x                                            0x8F0360
#define CXWnd__Move_x                                              0x8C0270
#define CXWnd__Move1_x                                             0x8C27F0
#define CXWnd__ProcessTransition_x                                 0x8BCE30
#define CXWnd__Refade_x                                            0x8BCC00
#define CXWnd__Resize_x                                            0x8BDB90
#define CXWnd__Right_x                                             0x8C1FB0
#define CXWnd__SetFocus_x                                          0x8BF400
#define CXWnd__SetFont_x                                           0x8BCAB0
#define CXWnd__SetKeyTooltip_x                                     0x8BDE00
#define CXWnd__SetMouseOver_x                                      0x8C2500
#define CXWnd__StartFade_x                                         0x8BCED0
#define CXWnd__GetChildItem_x                                      0x8C2440

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B9E40
#define CXWndManager__DrawWindows_x                                0x8B9A90
#define CXWndManager__GetKeyboardFlags_x                           0x8B8120
#define CXWndManager__HandleKeyboardMsg_x                          0x8B8A50
#define CXWndManager__RemoveWnd_x                                  0x8B8740

// CDBStr
#define CDBStr__GetString_x                                        0x4A7130

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44D430
#define EQ_Character__Cur_HP_x                                     0x462380
#define EQ_Character__Cur_Mana_x                                   0x455A90
#define EQ_Character__GetAACastingTimeModifier_x                   0x446770
#define EQ_Character__GetCharInfo2_x                               0x8653A0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EB60
#define EQ_Character__GetFocusRangeModifier_x                      0x43EBC0
#define EQ_Character__Max_Endurance_x                              0x5BE8F0
#define EQ_Character__Max_HP_x                                     0x4586D0
#define EQ_Character__Max_Mana_x                                   0x5BE720
#define EQ_Character__doCombatAbility_x                            0x5BBE30
#define EQ_Character__UseSkill_x                                   0x46D610
#define EQ_Character__GetConLevel_x                                0x5B09F0
#define EQ_Character__IsExpansionFlag_x                            0x423A00
#define EQ_Character__TotalEffect_x                                0x44A680
#define EQ_Character__GetPCSpellAffect_x                           0x446B70
#define EQ_Character__SpellDuration_x                              0x444A70

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x590E40
#define EQ_Item__CreateItemTagString_x                             0x844930
#define EQ_Item__IsStackable_x                                     0x83A2B0
#define EQ_Item__GetImageNum_x                                     0x83CD00
#define EQ_Item__CreateItemClient_x                                0x591A00
#define EQ_Item__GetItemValue_x                                    0x8436A0
#define EQ_Item__ValueSellMerchant_x                               0x845C10

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C6BD0
#define EQ_LoadingS__Array_x                                       0xC12530

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BFF40
#define EQ_PC__GetAlternateAbilityId_x                             0x84DD90
#define EQ_PC__GetCombatAbility_x                                  0x84DE20
#define EQ_PC__GetCombatAbilityTimer_x                             0x848DC0
#define EQ_PC__GetItemTimerValue_x                                 0x5B9960
#define EQ_PC__HasLoreItem_x                                       0x5B3ED0
#define EQ_PC__AlertInventoryChanged_x                             0x5B09C0
#define EQ_PC__GetPcZoneClient_x                                   0x5DA5B0
#define EQ_PC__RemoveMyAffect_x                                    0x5B8E10

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50F3E0
#define EQItemList__add_object_x                                   0x53BAD0
#define EQItemList__add_item_x                                     0x50F320
#define EQItemList__delete_item_x                                  0x50F7D0
#define EQItemList__FreeItemList_x                                 0x50F6D0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A6420

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C54E0
#define EQPlayer__dEQPlayer_x                                      0x5CE2F0
#define EQPlayer__DoAttack_x                                       0x5E02D0
#define EQPlayer__EQPlayer_x                                       0x5D0710
#define EQPlayer__SetNameSpriteState_x                             0x5CB290
#define EQPlayer__SetNameSpriteTint_x                              0x5C6920
#define PlayerBase__HasProperty_j_x                                0x921100
#define EQPlayer__IsTargetable_x                                   0x921A00
#define EQPlayer__CanSee_x                                         0x921F20
#define PlayerZoneClient__ChangeHeight_x                           0x5E0190
#define EQPlayer__CanSeeTargetIndicator_x                          0x922010

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D4AB0
#define EQPlayerManager__GetSpawnByName_x                          0x5D4F10
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D4AE0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x596F90
#define KeypressHandler__AttachKeyToEqCommand_x                    0x596FD0
#define KeypressHandler__ClearCommandStateArray_x                  0x596B80
#define KeypressHandler__HandleKeyDown_x                           0x5954E0
#define KeypressHandler__HandleKeyUp_x                             0x595800
#define KeypressHandler__SaveKeymapping_x                          0x596C50

// MapViewMap 
#define MapViewMap__Clear_x                                        0x703360
#define MapViewMap__SaveEx_x                                       0x706690

#define PlayerPointManager__GetAltCurrency_x                       0x860330

// StringTable 
#define StringTable__getString_x                                   0x85ACB0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BE3A0
#define PcZoneClient__RemovePetEffect_x                            0x5B9E30
#define PcZoneClient__HasAlternateAbility_x                        0x5BA8E0
#define PcZoneClient__GetCurrentMod_x                              0x457A50
#define PcZoneClient__GetModCap_x                                  0x4552A0

//Doors
#define EQSwitch__UseSwitch_x                                      0x54D8D0

//IconCache
#define IconCache__GetIcon_x                                       0x6A03F0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x697210
#define CContainerMgr__CloseContainer_x                            0x697A30

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7646C0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58A040

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DEA00
#define EQ_Spell__SpellAffects_x                                   0x4DC0B0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DC120
#define CharacterZoneClient__CalcAffectChange_x                    0x445BA0
#define CLootWnd__LootAll_x                                        0x6F8C00

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AB2B0
#define CTargetWnd__WndNotification_x                              0x7AADA0
#define CTargetWnd__UpdateBuffs_x                                  0x7AB490

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B0480

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D7970

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x496630

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DBD30
#define CSidlManager__FindAnimation1_x                             0x8D1130

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CE2B0
#define CAltAbilityData__GetMercMaxRank_x                          0x4CE260
#define CAltAbilityData__GetMaxRank_x                              0x4C3170

//CTargetRing
#define CTargetRing__Cast_x                                        0x587920

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x454310

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x681C80
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6813E0

//messages
#define msg_spell_worn_off_x                                       0x4E6460
#define msg_new_text_x                                             0x4EF7C0
#define msgTokenTextParam_x                                        0x4EC2C0

//SpellManager
#define SpellManager__vftable_x                                    0xAB0DA0
#define SpellManager__SpellManager_x                               0x47ADA0
