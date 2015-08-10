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
#include "eqgame-private.h"
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Aug  7 2015"
#define __ExpectedVersionTime                                     "18:28:20"
#define __ActualVersionDate_x                                      0xA83008
#define __ActualVersionTime_x                                      0xA83014

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5977D0
#define __MemChecker1_x                                            0x862150
#define __MemChecker2_x                                            0x630200
#define __MemChecker3_x                                            0x630150
#define __MemChecker4_x                                            0x7E5B10
#define __EncryptPad0_x                                            0xC015D0
#define __EncryptPad1_x                                            0xD88F80
#define __EncryptPad2_x                                            0xC4AF18
#define __EncryptPad3_x                                            0xC4AB18
#define __EncryptPad4_x                                            0xD64FE8
#define __AC1_x                                                    0x7A2E25
#define __AC2_x                                                    0x54CCD7
#define __AC3_x                                                    0x5614D0
#define __AC4_x                                                    0x568150
#define __AC5_x                                                    0x573F7E
#define __AC6_x                                                    0x577A29
#define __AC7_x                                                    0x56E62C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x113B098
#define DI8__Keyboard_x                                            0x113B09C
#define DI8__Mouse_x                                               0x113B0A0
#define DI8__Mouse_Copy_x                                          0xFA96B4
#define DI8__Mouse_Check_x                                         0x1032F84
#define __AltTimerReady_x                                          0xF9AA01
#define __Attack_x                                                 0x102DC23
#define __Autofire_x                                               0x102DC24
#define __BindList_x                                               0xBC3828
#define __bCommandEnabled_x                                        0xF98B10
#define __Clicks_x                                                 0xFA9770
#define __CommandList_x                                            0xBC7B80
#define __CurrentMapLabel_x                                        0x1140AF0
#define __CurrentSocial_x                                          0xB7EE7C
#define __DoAbilityList_x                                          0xFDFED8
#define __do_loot_x                                                0x514450
#define __DrawHandler_x                                            0x17A56FC
#define __GroupCount_x                                             0xF9A0DA

#define __Guilds_x                                                 0xF9FCF0
#define __gWorld_x                                                 0xF9C594
#define __HotkeyPage_x                                             0x10268D8
#define __HWnd_x                                                   0x1032FA0
#define __InChatMode_x                                             0xFA969C
#define __LastTell_x                                               0xFAB5E0
#define __LMouseHeldTime_x                                         0xFA97DC
#define __Mouse_x                                                  0x113B0A4
#define __MouseLook_x                                              0xFA9736
#define __MouseEventTime_x                                         0x102E42C
#define __gpbCommandEvent_x                                        0xF9C65C
#define __NetStatusToggle_x                                        0xFA9739
#define __PCNames_x                                                0xFAAC00
#define __RangeAttackReady_x                                       0xFAA8C0
#define __RMouseHeldTime_x                                         0xFA97D8
#define __RunWalkState_x                                           0xFA96A0
#define __ScreenMode_x                                             0xEE8938
#define __ScreenX_x                                                0xFA9654
#define __ScreenY_x                                                0xFA9650
#define __ScreenXMax_x                                             0xFA9658
#define __ScreenYMax_x                                             0xFA965C
#define __ServerHost_x                                             0xF9A024
#define __ServerName_x                                             0xFDFE98
#define __ShiftKeyDown_x                                           0xFA9D44
#define __ShowNames_x                                              0xFAAA94
#define __Socials_x                                                0xFDFF98
#define __SubscriptionType_x                                       0x116CE80
#define __TargetAggroHolder_x                                      0x1142D2C
#define __GroupAggro_x                                             0x1142D6C
#define __LoginName_x                                              0x1031B78
#define __Inviter_x                                                0x102DBA0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF9C680
#define instEQZoneInfo_x                                           0xFA992C
#define instKeypressHandler_x                                      0x102E410
#define pinstActiveBanker_x                                        0xF9C638
#define pinstActiveCorpse_x                                        0xF9C63C
#define pinstActiveGMaster_x                                       0xF9C640
#define pinstActiveMerchant_x                                      0xF9C634
#define pinstAggroInfo_x                                           0xDACDB8
#define pinstAltAdvManager_x                                       0xEE9A38
#define pinstAuraMgr_x                                             0xDB6C80
#define pinstBandageTarget_x                                       0xF9C620
#define pinstCamActor_x                                            0xEE9340
#define pinstCDBStr_x                                              0xEE88CC
#define pinstCDisplay_x                                            0xF9C648
#define pinstCEverQuest_x                                          0x113B218
#define pinstCharData_x                                            0xF9C604
#define pinstCharSpawn_x                                           0xF9C62C
#define pinstControlledMissile_x                                   0xF9C600
#define pinstControlledPlayer_x                                    0xF9C62C
#define pinstCSidlManager_x                                        0x17A4B34
#define pinstCXWndManager_x                                        0x17A4B2C
#define instDynamicZone_x                                          0xFA94E8
#define pinstDZMember_x                                            0xFA95F8
#define pinstDZTimerInfo_x                                         0xFA95FC
#define pinstEQItemList_x                                          0xF98D60
#define instEQMisc_x                                               0xB9FAC0
#define pinstEQSoundManager_x                                      0xEE9EA8
#define instExpeditionLeader_x                                     0xFA9532
#define instExpeditionName_x                                       0xFA9572
#define pinstGroup_x                                               0xF9A0D6
#define pinstImeManager_x                                          0x17A4B38
#define pinstLocalPlayer_x                                         0xF9C618
#define pinstMercenaryData_x                                       0x102EA60
#define pinstMercenaryStats_x                                      0x1142E78
#define pinstMercAltAbilities_x                                    0xEE9DC4
#define pinstModelPlayer_x                                         0xF9C644
#define pinstPCData_x                                              0xF9C604
#define pinstSkillMgr_x                                            0x102F898
#define pinstSpawnManager_x                                        0x102F180
#define pinstSpellManager_x                                        0x102F9E0
#define pinstSpellSets_x                                           0x102693C
#define pinstStringTable_x                                         0xF9C5AC
#define pinstSwitchManager_x                                       0xF99C68
#define pinstTarget_x                                              0xF9C630
#define pinstTargetObject_x                                        0xF9C608
#define pinstTargetSwitch_x                                        0xF9C60C
#define pinstTaskMember_x                                          0xEE8818
#define pinstTrackTarget_x                                         0xF9C624
#define pinstTradeTarget_x                                         0xF9C614
#define instTributeActive_x                                        0xB9FAE5
#define pinstViewActor_x                                           0xEE933C
#define pinstWorldData_x                                           0xF9C5E8


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xDAD298
#define pinstCAudioTriggersWindow_x                                0xDAD128
#define pinstCCharacterSelect_x                                    0xEE91DC
#define pinstCFacePick_x                                           0xEE8F8C
#define pinstCNoteWnd_x                                            0xEE9194
#define pinstCBookWnd_x                                            0xEE919C
#define pinstCPetInfoWnd_x                                         0xEE91A0
#define pinstCTrainWnd_x                                           0xEE91A4
#define pinstCSkillsWnd_x                                          0xEE91A8
#define pinstCSkillsSelectWnd_x                                    0xEE91AC
#define pinstCCombatSkillsSelectWnd_x                              0xEE91B0
#define pinstCFriendsWnd_x                                         0xEE91B4
#define pinstCAuraWnd_x                                            0xEE91B8
#define pinstCRespawnWnd_x                                         0xEE91BC
#define pinstCBandolierWnd_x                                       0xEE91C0
#define pinstCPotionBeltWnd_x                                      0xEE91C4
#define pinstCAAWnd_x                                              0xEE91C8
#define pinstCGroupSearchFiltersWnd_x                              0xEE91CC
#define pinstCLoadskinWnd_x                                        0xEE91D0
#define pinstCAlarmWnd_x                                           0xEE91D4
#define pinstCMusicPlayerWnd_x                                     0xEE91D8
#define pinstCMailWnd_x                                            0xEE91E0
#define pinstCMailCompositionWnd_x                                 0xEE91E4
#define pinstCMailAddressBookWnd_x                                 0xEE91E8
#define pinstCRaidWnd_x                                            0xEE91F0
#define pinstCRaidOptionsWnd_x                                     0xEE91F4
#define pinstCBreathWnd_x                                          0xEE91F8
#define pinstCMapViewWnd_x                                         0xEE91FC
#define pinstCMapToolbarWnd_x                                      0xEE9200
#define pinstCEditLabelWnd_x                                       0xEE9204
#define pinstCTargetWnd_x                                          0xEE9208
#define pinstCColorPickerWnd_x                                     0xEE920C
#define pinstCPlayerWnd_x                                          0xEE9210
#define pinstCOptionsWnd_x                                         0xEE9214
#define pinstCBuffWindowNORMAL_x                                   0xEE9218
#define pinstCBuffWindowSHORT_x                                    0xEE921C
#define pinstCharacterCreation_x                                   0xEE9220
#define pinstCCursorAttachment_x                                   0xEE9224
#define pinstCCastingWnd_x                                         0xEE9228
#define pinstCCastSpellWnd_x                                       0xEE922C
#define pinstCSpellBookWnd_x                                       0xEE9230
#define pinstCInventoryWnd_x                                       0xEE9234
#define pinstCBankWnd_x                                            0xEE9238
#define pinstCQuantityWnd_x                                        0xEE923C
#define pinstCLootWnd_x                                            0xEE9240
#define pinstCActionsWnd_x                                         0xEE9244
#define pinstCCombatAbilityWnd_x                                   0xEE9248
#define pinstCMerchantWnd_x                                        0xEE924C
#define pinstCTradeWnd_x                                           0xEE9250
#define pinstCSelectorWnd_x                                        0xEE9254
#define pinstCBazaarWnd_x                                          0xEE9258
#define pinstCBazaarSearchWnd_x                                    0xEE925C
#define pinstCGiveWnd_x                                            0xEE9278
#define pinstCTrackingWnd_x                                        0xEE9280
#define pinstCInspectWnd_x                                         0xEE9284
#define pinstCSocialEditWnd_x                                      0xEE9288
#define pinstCFeedbackWnd_x                                        0xEE928C
#define pinstCBugReportWnd_x                                       0xEE9290
#define pinstCVideoModesWnd_x                                      0xEE9294
#define pinstCTextEntryWnd_x                                       0xEE929C
#define pinstCFileSelectionWnd_x                                   0xEE92A0
#define pinstCCompassWnd_x                                         0xEE92A4
#define pinstCPlayerNotesWnd_x                                     0xEE92A8
#define pinstCGemsGameWnd_x                                        0xEE92AC
#define pinstCTimeLeftWnd_x                                        0xEE92B0
#define pinstCPetitionQWnd_x                                       0xEE92C4
#define pinstCSoulmarkWnd_x                                        0xEE92C8
#define pinstCStoryWnd_x                                           0xEE92CC
#define pinstCJournalTextWnd_x                                     0xEE92D0
#define pinstCJournalCatWnd_x                                      0xEE92D4
#define pinstCBodyTintWnd_x                                        0xEE92D8
#define pinstCServerListWnd_x                                      0xEE92DC
#define pinstCAvaZoneWnd_x                                         0xEE92E8
#define pinstCBlockedBuffWnd_x                                     0xEE92EC
#define pinstCBlockedPetBuffWnd_x                                  0xEE92F0
#define pinstCInvSlotMgr_x                                         0xEE9334
#define pinstCContainerMgr_x                                       0xEE9338
#define pinstCAdventureLeaderboardWnd_x                            0x113BBC8
#define pinstCAdventureRequestWnd_x                                0x113BC40
#define pinstCAltStorageWnd_x                                      0x113BF20
#define pinstCAdventureStatsWnd_x                                  0x113BCB8
#define pinstCBarterMerchantWnd_x                                  0x113CB08
#define pinstCBarterSearchWnd_x                                    0x113CB80
#define pinstCBarterWnd_x                                          0x113CBF8
#define pinstCChatManager_x                                        0x113D288
#define pinstCDynamicZoneWnd_x                                     0x113D738
#define pinstCEQMainWnd_x                                          0x113D8D0
#define pinstCFellowshipWnd_x                                      0x113D6CC
#define pinstCFindLocationWnd_x                                    0x113DBA0
#define pinstCGroupSearchWnd_x                                     0x113DE70
#define pinstCGroupWnd_x                                           0x113DEE8
#define pinstCGuildBankWnd_x                                       0x113DF60
#define pinstCGuildMgmtWnd_x                                       0x1140050
#define pinstCHotButtonWnd_x                                       0x114011C
#define pinstCHotButtonWnd1_x                                      0x114011C
#define pinstCHotButtonWnd2_x                                      0x1140120
#define pinstCHotButtonWnd3_x                                      0x1140124
#define pinstCHotButtonWnd4_x                                      0x1140148
#define pinstCItemDisplayManager_x                                 0x1140440
#define pinstCItemExpTransferWnd_x                                 0x11404BC
#define pinstCLFGuildWnd_x                                         0x1140798
#define pinstCMIZoneSelectWnd_x                                    0x1140D80
#define pinstCConfirmationDialog_x                                 0x1141488
#define pinstCPopupWndManager_x                                    0x1141488
#define pinstCProgressionSelectionWnd_x                            0x1141578
#define pinstCPvPStatsWnd_x                                        0x1141668
#define pinstCSystemInfoDialogBox_x                                0x1141D70
#define pinstCTaskWnd_x                                            0x1143138
#define pinstCTaskSomething_x                                      0xDB73C0
#define pinstCTaskTemplateSelectWnd_x                              0x11430C0
#define pinstCTipWndOFDAY_x                                        0x1143390
#define pinstCTipWndCONTEXT_x                                      0x1143394
#define pinstCTitleWnd_x                                           0x1143410
#define pinstCContextMenuManager_x                                 0x17A4AA4
#define pinstCVoiceMacroWnd_x                                      0x1030048
#define pinstCHtmlWnd_x                                            0x1030140
#define pinstIconCache_x                                           0x113D8A4
#define pinstCTradeskillWnd_x                                      0x1143510
#define pinstCAdvancedLootWnd_x                                    0xEE9328
#define pinstRewardSelectionWnd_x                                  0x1141B90

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x52BDE0
#define __ConvertItemTags_x                                        0x5190D0
#define __ExecuteCmd_x                                             0x503AB0
#define __EQGetTime_x                                              0x862470
#define __get_melee_range_x                                        0x50A770
#define __GetGaugeValueFromEQ_x                                    0x7A1B70
#define __GetLabelFromEQ_x                                         0x7A2DB0
#define __ToggleMount_x                                            0x6CACE0
#define __GetXTargetType_x                                         0x920FA0
#define __LoadFrontEnd_x                                           0x62F8B0
#define __NewUIINI_x                                               0x7A1470
#define __ProcessGameEvents_x                                      0x570390
#define __ProcessMouseEvent_x                                      0x56FB30
#define CrashDetected_x                                            0x631380
#define wwsCrashReportCheckForUploader_x                           0x7F6E90
#define DrawNetStatus_x                                            0x5A7130
#define Util__FastTime_x                                           0x861FC0
#define Expansion_HoT_x                                            0xFAAA2C
#define __HelpPath_x                                               0x102E198

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41EFC0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419E10

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C2980
#define AltAdvManager__IsAbilityReady_x                            0x4C29F0
#define AltAdvManager__GetAltAbility_x                             0x4C2DB0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4659E0
#define CharacterZoneClient__MakeMeVisible_x                       0x46B410
// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x65F1A0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66CD90

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x586620

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x688570
#define CChatManager__InitContextMenu_x                            0x6890F0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D2CE0
#define CContextMenu__dCContextMenu_x                              0x8D2EF0
#define CContextMenu__AddMenuItem_x                                0x8D2F00
#define CContextMenu__RemoveMenuItem_x                             0x8D31F0
#define CContextMenu__RemoveAllMenuItems_x                         0x8D3210
#define CContextMenuManager__AddMenu_x                             0x8BEB30
#define CContextMenuManager__RemoveMenu_x                          0x8BEE80
#define CContextMenuManager__PopupMenu_x                           0x8BF2D0
#define CContextMenuManager__Flush_x                               0x8BEBA0
#define CContextMenuManager__GetMenu_x                             0x415450

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8485B0
#define CChatService__GetFriendName_x                              0x8485C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x68E3A0
#define CChatWindow__Clear_x                                       0x68DF50
#define CChatWindow__WndNotification_x                             0x68E8E0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C2A30
#define CComboWnd__Draw_x                                          0x8C2C40
#define CComboWnd__GetCurChoice_x                                  0x8C2800
#define CComboWnd__GetListRect_x                                   0x8C2EE0
#define CComboWnd__GetTextRect_x                                   0x8C2AA0
#define CComboWnd__InsertChoice_x                                  0x8C2F50
#define CComboWnd__SetColors_x                                     0x8C2790
#define CComboWnd__SetChoice_x                                     0x8C27C0
#define CComboWnd__GetItemCount_x                                  0x8C27F0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x697AE0
#define CContainerWnd__vftable_x                                   0xA8C798

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B0C70
#define CDisplay__GetClickedActor_x                                0x4A97F0
#define CDisplay__GetUserDefinedColor_x                            0x4A80B0
#define CDisplay__GetWorldFilePath_x                               0x4A7500
#define CDisplay__is3dON_x                                         0x4A68D0
#define CDisplay__ReloadUI_x                                       0x4BC140
#define CDisplay__WriteTextHD2_x                                   0x4AD010

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E9290

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D7630
#define CEditWnd__GetCharIndexPt_x                                 0x8D86C0
#define CEditWnd__GetDisplayString_x                               0x8D77E0
#define CEditWnd__GetHorzOffset_x                                  0x8D7B20
#define CEditWnd__GetLineForPrintableChar_x                        0x8D8190
#define CEditWnd__GetSelStartPt_x                                  0x8D8970
#define CEditWnd__GetSTMLSafeText_x                                0x8D7CC0
#define CEditWnd__PointFromPrintableChar_x                         0x8D8280
#define CEditWnd__SelectableCharFromPoint_x                        0x8D8400
#define CEditWnd__SetEditable_x                                    0x8D7C90

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x54D420
#define CEverQuest__DoTellWindow_x                                 0x552E20
#define CEverQuest__DropHeldItemOnGround_x                         0x55B950
#define CEverQuest__dsp_chat_x                                     0x5545C0
#define CEverQuest__Emote_x                                        0x554820
#define CEverQuest__EnterZone_x                                    0x568970
#define CEverQuest__GetBodyTypeDesc_x                              0x549C80
#define CEverQuest__GetClassDesc_x                                 0x54F990
#define CEverQuest__GetClassThreeLetterCode_x                      0x54FF90
#define CEverQuest__GetDeityDesc_x                                 0x54A560
#define CEverQuest__GetLangDesc_x                                  0x54A010
#define CEverQuest__GetRaceDesc_x                                  0x550150
#define CEverQuest__InterpretCmd_x                                 0x555100
#define CEverQuest__LeftClickedOnPlayer_x                          0x56CA90
#define CEverQuest__LMouseUp_x                                     0x56EB80
#define CEverQuest__RightClickedOnPlayer_x                         0x56D590
#define CEverQuest__RMouseUp_x                                     0x56E5E0
#define CEverQuest__SetGameState_x                                 0x54DAD0
#define CEverQuest__UPCNotificationFlush_x                         0x5562A0
#define CEverQuest__IssuePetCommand_x                              0x555E00

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A8680
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A86E0
#define CGaugeWnd__Draw_x                                          0x6A8B10

// CGuild
#define CGuild__FindMemberByName_x                                 0x435F60

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C5710

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D3520
#define CInvSlotMgr__MoveItem_x                                    0x6D4460
#define CInvSlotMgr__SelectSlot_x                                  0x6D35D0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D29B0
#define CInvSlot__SliderComplete_x                                 0x6D0370
#define CInvSlot__GetItemBase_x                                    0x6CF7E0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D5620

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79E580
#define CItemDisplayWnd__UpdateStrings_x                           0x6D6990

// CLabel 
#define CLabel__Draw_x                                             0x6F17B0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8AE750
#define CListWnd__dCListWnd_x                                      0x8AF780
#define CListWnd__AddColumn_x                                      0x8AF720
#define CListWnd__AddColumn1_x                                     0x8AEF90
#define CListWnd__AddLine_x                                        0x8AEA10
#define CListWnd__AddString_x                                      0x8AEC20
#define CListWnd__CalculateFirstVisibleLine_x                      0x8ABA90
#define CListWnd__CalculateVSBRange_x                              0x8ADC10
#define CListWnd__ClearAllSel_x                                    0x8AAD40
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8AE5E0
#define CListWnd__Compare_x                                        0x8AC590
#define CListWnd__Draw_x                                           0x8AD820
#define CListWnd__DrawColumnSeparators_x                           0x8AD6B0
#define CListWnd__DrawHeader_x                                     0x8AB050
#define CListWnd__DrawItem_x                                       0x8ACBE0
#define CListWnd__DrawLine_x                                       0x8AD350
#define CListWnd__DrawSeparator_x                                  0x8AD750
#define CListWnd__EnsureVisible_x                                  0x8ABBF0
#define CListWnd__ExtendSel_x                                      0x8ACAF0
#define CListWnd__GetColumnMinWidth_x                              0x8AA700
#define CListWnd__GetColumnWidth_x                                 0x8AA620
#define CListWnd__GetCurSel_x                                      0x8A9DF0
#define CListWnd__GetItemAtPoint_x                                 0x8ABE80
#define CListWnd__GetItemAtPoint1_x                                0x8ABEF0
#define CListWnd__GetItemData_x                                    0x8AA130
#define CListWnd__GetItemHeight_x                                  0x8AB6E0
#define CListWnd__GetItemIcon_x                                    0x8AA310
#define CListWnd__GetItemRect_x                                    0x8ABCC0
#define CListWnd__GetItemText_x                                    0x8AA1C0
#define CListWnd__GetSelList_x                                     0x8AEE80
#define CListWnd__GetSeparatorRect_x                               0x8AC4B0
#define CListWnd__RemoveLine_x                                     0x8AEE00
#define CListWnd__SetColors_x                                      0x8A9F40
#define CListWnd__SetColumnJustification_x                         0x8AA9D0
#define CListWnd__SetColumnWidth_x                                 0x8AA6B0
#define CListWnd__SetCurSel_x                                      0x8A9E30
#define CListWnd__SetItemColor_x                                   0x8AE2C0
#define CListWnd__SetItemData_x                                    0x8AADF0
#define CListWnd__SetItemText_x                                    0x8AE100
#define CListWnd__ShiftColumnSeparator_x                           0x8ADF90
#define CListWnd__Sort_x                                           0x8AF880
#define CListWnd__ToggleSel_x                                      0x8AACC0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70AC20

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72BEF0
#define CMerchantWnd__RequestBuyItem_x                             0x732D30
#define CMerchantWnd__RequestSellItem_x                            0x7337A0
#define CMerchantWnd__SelectRecoverySlot_x                         0x72C1A0
#define CMerchantWnd__SelectBuySellSlot_x                          0x72B400
#define CMerchantWnd__ActualSelect_x                               0x72FC60

// CObfuscator
#define CObfuscator__doit_x                                        0x828740

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8CDC00
#define CSidlManager__CreateLabel_x                                0x794530

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x6564B0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x6563E0
#define CSidlScreenWnd__ConvertToRes_x                             0x8E9170
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8C56E0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C6BE0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C6C90
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C6140
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8C5090
#define CSidlScreenWnd__EnableIniStorage_x                         0x8C47D0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8C5280
#define CSidlScreenWnd__Init1_x                                    0x8C68B0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C5790
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8C4990
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C6390
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C4290
#define CSidlScreenWnd__StoreIniVis_x                              0x8C4760
#define CSidlScreenWnd__WndNotification_x                          0x8C6630
#define CSidlScreenWnd__GetChildItem_x                             0x8C48A0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B7E20

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F1860
#define CSkillMgr__GetSkillCap_x                                   0x5F1A00
#define CSkillMgr__GetNameToken_x                                  0x5F14D0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E8420
#define CSliderWnd__SetValue_x                                     0x8E85F0
#define CSliderWnd__SetNumTicks_x                                  0x8E8D70

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79C220

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8E2E20
#define CStmlWnd__CalculateHSBRange_x                              0x8DB340
#define CStmlWnd__CalculateVSBRange_x                              0x8DB3D0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8DB550
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8DBE30
#define CStmlWnd__ForceParseNow_x                                  0x8E3770
#define CStmlWnd__GetNextTagPiece_x                                0x8DBD30
#define CStmlWnd__GetSTMLText_x                                    0x68D7F0
#define CStmlWnd__GetVisibleText_x                                 0x8DC880
#define CStmlWnd__InitializeWindowVariables_x                      0x8DEC00
#define CStmlWnd__MakeStmlColorTag_x                               0x8DA640
#define CStmlWnd__MakeWndNotificationTag_x                         0x8DA6A0
#define CStmlWnd__SetSTMLText_x                                    0x8E0460
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E2AC0
#define CStmlWnd__UpdateHistoryString_x                            0x8DD7C0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8EA960
#define CTabWnd__DrawCurrentPage_x                                 0x8EA1D0
#define CTabWnd__DrawTab_x                                         0x8E9F90
#define CTabWnd__GetCurrentPage_x                                  0x8EA5A0
#define CTabWnd__GetPageInnerRect_x                                0x8E9C80
#define CTabWnd__GetTabInnerRect_x                                 0x8E9E80
#define CTabWnd__GetTabRect_x                                      0x8E9D50
#define CTabWnd__InsertPage_x                                      0x8EAC50
#define CTabWnd__SetPage_x                                         0x8EA5D0
#define CTabWnd__SetPageRect_x                                     0x8EA8A0
#define CTabWnd__UpdatePage_x                                      0x8EABF0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431CB0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C2400

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8EFBF0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A7F00

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x593D70
#define CXStr__CXStr1_x                                            0x7DEC80
#define CXStr__CXStr3_x                                            0x85F050
#define CXStr__dCXStr_x                                            0x8EE910
#define CXStr__operator_equal_x                                    0x85F1C0
#define CXStr__operator_equal1_x                                   0x85F210
#define CXStr__operator_plus_equal1_x                              0x8602F0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B7060
#define CXWnd__Center_x                                            0x8BD130
#define CXWnd__ClrFocus_x                                          0x8B6C40
#define CXWnd__DoAllDrawing_x                                      0x8BCD80
#define CXWnd__DrawChildren_x                                      0x8BCF20
#define CXWnd__DrawColoredRect_x                                   0x8B7420
#define CXWnd__DrawTooltip_x                                       0x8B76C0
#define CXWnd__DrawTooltipAtPoint_x                                0x8BBCF0
#define CXWnd__GetBorderFrame_x                                    0x8B7B20
#define CXWnd__GetChildWndAt_x                                     0x8BDAE0
#define CXWnd__GetClientClipRect_x                                 0x8B78E0
#define CXWnd__GetScreenClipRect_x                                 0x8BC3F0
#define CXWnd__GetScreenRect_x                                     0x8B7CD0
#define CXWnd__GetTooltipRect_x                                    0x8B7550
#define CXWnd__GetWindowTextA_x                                    0x422F40
#define CXWnd__IsActive_x                                          0x8B2560
#define CXWnd__IsDescendantOf_x                                    0x8B7A70
#define CXWnd__IsReallyVisible_x                                   0x8BAD40
#define CXWnd__IsType_x                                            0x8EC3B0
#define CXWnd__Move_x                                              0x8BA4E0
#define CXWnd__Move1_x                                             0x8BCA40
#define CXWnd__ProcessTransition_x                                 0x8B7000
#define CXWnd__Refade_x                                            0x8B7000
#define CXWnd__Resize_x                                            0x8B7D90
#define CXWnd__Right_x                                             0x8BC1F0
#define CXWnd__SetFocus_x                                          0x8B9650
#define CXWnd__SetFont_x                                           0x8B6C90
#define CXWnd__SetKeyTooltip_x                                     0x8B7FF0
#define CXWnd__SetMouseOver_x                                      0x8BC730
#define CXWnd__StartFade_x                                         0x8B70B0
#define CXWnd__GetChildItem_x                                      0x8BC670

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B3E90
#define CXWndManager__DrawWindows_x                                0x8B3AD0
#define CXWndManager__GetKeyboardFlags_x                           0x8B2090
#define CXWndManager__HandleKeyboardMsg_x                          0x8B29F0
#define CXWndManager__RemoveWnd_x                                  0x8B26F0

// CDBStr
#define CDBStr__GetString_x                                        0x4A4EA0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44FA80
#define EQ_Character__Cur_HP_x                                     0x4650B0
#define EQ_Character__GetAACastingTimeModifier_x                   0x447410
#define EQ_Character__GetCharInfo2_x                               0x833020
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F560
#define EQ_Character__GetFocusRangeModifier_x                      0x43F740
#define EQ_Character__Max_Endurance_x                              0x5B9340
#define EQ_Character__Max_HP_x                                     0x45AD30
#define EQ_Character__Max_Mana_x                                   0x5B9170
#define EQ_Character__doCombatAbility_x                            0x5B6750
#define EQ_Character__UseSkill_x                                   0x470610
#define EQ_Character__GetConLevel_x                                0x5AB790
#define EQ_Character__IsExpansionFlag_x                            0x422490
#define EQ_Character__TotalEffect_x                                0x44C7B0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x58BE20
#define EQ_Item__CreateItemTagString_x                             0x812510
#define EQ_Item__IsStackable_x                                     0x806A90
#define EQ_Item__GetImageNum_x                                     0x809770

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C4B20
#define EQ_LoadingS__Array_x                                       0xBAD858

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BAAE0
#define EQ_PC__GetAltAbilityIndex_x                                0x81B4F0
#define EQ_PC__GetCombatAbility_x                                  0x81B580
#define EQ_PC__GetCombatAbilityTimer_x                             0x8165A0
#define EQ_PC__GetItemTimerValue_x                                 0x5B4540
#define EQ_PC__HasLoreItem_x                                       0x5AEAF0
#define EQ_PC__AlertInventoryChanged_x                             0x5AB760
#define EQ_PC__GetPcZoneClient_x                                   0x5D5030
#define EQ_PC__RemoveMyAffect_x									   0x5B3A50

// EQItemList 
#define EQItemList__EQItemList_x                                   0x508780
#define EQItemList__add_item_x                                     0x5086C0
#define EQItemList__delete_item_x                                  0x508B80
#define EQItemList__FreeItemList_x                                 0x508A80

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A40A0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C0070
#define EQPlayer__dEQPlayer_x                                      0x5C8EA0
#define EQPlayer__DoAttack_x                                       0x5DAEF0
#define EQPlayer__EQPlayer_x                                       0x5CB2C0
#define EQPlayer__SetNameSpriteState_x                             0x5C5B70
#define EQPlayer__SetNameSpriteTint_x                              0x5C1440
#define EQPlayer__IsBodyType_j_x                                   0x91D150
#define EQPlayer__IsTargetable_x                                   0x91DA10
#define EQPlayer__CanSee_x                                         0x91DF30

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5CF5D0
#define EQPlayerManager__GetSpawnByName_x                          0x5CFA30

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5920A0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5920E0
#define KeypressHandler__ClearCommandStateArray_x                  0x591C80
#define KeypressHandler__HandleKeyDown_x                           0x5905E0
#define KeypressHandler__HandleKeyUp_x                             0x590900
#define KeypressHandler__SaveKeymapping_x                          0x591D50

// MapViewMap 
#define MapViewMap__Clear_x                                        0x703000
#define MapViewMap__SaveEx_x                                       0x7068E0

#define PlayerPointManager__GetAltCurrency_x                       0x82DF00

// StringTable 
#define StringTable__getString_x                                   0x8289E0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B8DF0

//Doors
#define EQSwitch__UseSwitch_x                                      0x547070

//IconCache
#define IconCache__GetIcon_x                                       0x69DF30

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x694DF0
#define CContainerMgr__CloseContainer_x                            0x695610

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x764870

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5850E0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D84E0
#define EQ_Spell__SpellAffects_x                                   0x4D8580
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D85B0
#define CharacterZoneClient__CalcAffectChange_x                    0x448800
#define CLootWnd__LootAll_x                                        0x6F8930

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AA0E0
#define CTargetWnd__WndNotification_x                              0x7A9BD0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7AF2A0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D1E00

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x494C90
