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
#define __ExpectedVersionDate                                     "Aug 20 2015"
#define __ExpectedVersionTime                                     "18:29:53"
#define __ActualVersionDate_x                                      0xA81FD0
#define __ActualVersionTime_x                                      0xA81FDC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x596900
#define __MemChecker1_x                                            0x861680
#define __MemChecker2_x                                            0x62F840
#define __MemChecker3_x                                            0x62F790
#define __MemChecker4_x                                            0x7E4E90
#define __EncryptPad0_x                                            0xC005D0
#define __EncryptPad1_x                                            0xD87F80
#define __EncryptPad2_x                                            0xC49F18
#define __EncryptPad3_x                                            0xC49B18
#define __EncryptPad4_x                                            0xD63FE8
#define __AC1_x                                                    0x7A2615
#define __AC2_x                                                    0x54BF77
#define __AC3_x                                                    0x560770
#define __AC4_x                                                    0x5673F0
#define __AC5_x                                                    0x57320E
#define __AC6_x                                                    0x576CB9
#define __AC7_x                                                    0x56D8BC
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x113A098
#define DI8__Keyboard_x                                            0x113A09C
#define DI8__Mouse_x                                               0x113A0A0
#define DI8__Mouse_Copy_x                                          0xFA86B4
#define DI8__Mouse_Check_x                                         0x1031F84
#define __AltTimerReady_x                                          0xF99A01
#define __Attack_x                                                 0x102CC23
#define __Autofire_x                                               0x102CC24
#define __BindList_x                                               0xBC2828
#define __bCommandEnabled_x                                        0xF97B10
#define __Clicks_x                                                 0xFA8770
#define __CommandList_x                                            0xBC6B80
#define __CurrentMapLabel_x                                        0x113FAF0
#define __CurrentSocial_x                                          0xB7DE7C
#define __DoAbilityList_x                                          0xFDEED8
#define __do_loot_x                                                0x513570
#define __DrawHandler_x                                            0x17A46FC
#define __GroupCount_x                                             0xF990DA

#define __Guilds_x                                                 0xF9ECF0
#define __gWorld_x                                                 0xF9B594
#define __HotkeyPage_x                                             0x10258D8
#define __HWnd_x                                                   0x1031FA0
#define __InChatMode_x                                             0xFA869C
#define __LastTell_x                                               0xFAA5E0
#define __LMouseHeldTime_x                                         0xFA87DC
#define __Mouse_x                                                  0x113A0A4
#define __MouseLook_x                                              0xFA8736
#define __MouseEventTime_x                                         0x102D42C
#define __gpbCommandEvent_x                                        0xF9B65C
#define __NetStatusToggle_x                                        0xFA8739
#define __PCNames_x                                                0xFA9C00
#define __RangeAttackReady_x                                       0xFA98C0
#define __RMouseHeldTime_x                                         0xFA87D8
#define __RunWalkState_x                                           0xFA86A0
#define __ScreenMode_x                                             0xEE7938
#define __ScreenX_x                                                0xFA8654
#define __ScreenY_x                                                0xFA8650
#define __ScreenXMax_x                                             0xFA8658
#define __ScreenYMax_x                                             0xFA865C
#define __ServerHost_x                                             0xF99024
#define __ServerName_x                                             0xFDEE98
#define __ShiftKeyDown_x                                           0xFA8D44
#define __ShowNames_x                                              0xFA9A94
#define __Socials_x                                                0xFDEF98
#define __SubscriptionType_x                                       0x116BE80
#define __TargetAggroHolder_x                                      0x1141D2C
#define __GroupAggro_x                                             0x1141D6C
#define __LoginName_x                                              0x1030B78
#define __Inviter_x                                                0x102CBA0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF9B680
#define instEQZoneInfo_x                                           0xFA892C
#define instKeypressHandler_x                                      0x102D410
#define pinstActiveBanker_x                                        0xF9B638
#define pinstActiveCorpse_x                                        0xF9B63C
#define pinstActiveGMaster_x                                       0xF9B640
#define pinstActiveMerchant_x                                      0xF9B634
#define pinstAggroInfo_x                                           0xDABDB8
#define pinstAltAdvManager_x                                       0xEE8A38
#define pinstAuraMgr_x                                             0xDB5C80
#define pinstBandageTarget_x                                       0xF9B620
#define pinstCamActor_x                                            0xEE8340
#define pinstCDBStr_x                                              0xEE78CC
#define pinstCDisplay_x                                            0xF9B648
#define pinstCEverQuest_x                                          0x113A218
#define pinstCharData_x                                            0xF9B604
#define pinstCharSpawn_x                                           0xF9B62C
#define pinstControlledMissile_x                                   0xF9B600
#define pinstControlledPlayer_x                                    0xF9B62C
#define pinstCSidlManager_x                                        0x17A3B34
#define pinstCXWndManager_x                                        0x17A3B2C
#define instDynamicZone_x                                          0xFA84E8
#define pinstDZMember_x                                            0xFA85F8
#define pinstDZTimerInfo_x                                         0xFA85FC
#define pinstEQItemList_x                                          0xF97D60
#define instEQMisc_x                                               0xB9EAC0
#define pinstEQSoundManager_x                                      0xEE8EA8
#define instExpeditionLeader_x                                     0xFA8532
#define instExpeditionName_x                                       0xFA8572
#define pinstGroup_x                                               0xF990D6
#define pinstImeManager_x                                          0x17A3B38
#define pinstLocalPlayer_x                                         0xF9B618
#define pinstMercenaryData_x                                       0x102DA60
#define pinstMercenaryStats_x                                      0x1141E78
#define pinstMercAltAbilities_x                                    0xEE8DC4
#define pinstModelPlayer_x                                         0xF9B644
#define pinstPCData_x                                              0xF9B604
#define pinstSkillMgr_x                                            0x102E898
#define pinstSpawnManager_x                                        0x102E180
#define pinstSpellManager_x                                        0x102E9E0
#define pinstSpellSets_x                                           0x102593C
#define pinstStringTable_x                                         0xF9B5AC
#define pinstSwitchManager_x                                       0xF98C68
#define pinstTarget_x                                              0xF9B630
#define pinstTargetObject_x                                        0xF9B608
#define pinstTargetSwitch_x                                        0xF9B60C
#define pinstTaskMember_x                                          0xEE7818
#define pinstTrackTarget_x                                         0xF9B624
#define pinstTradeTarget_x                                         0xF9B614
#define instTributeActive_x                                        0xB9EAE5
#define pinstViewActor_x                                           0xEE833C
#define pinstWorldData_x                                           0xF9B5E8


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xDAC298
#define pinstCAudioTriggersWindow_x                                0xDAC128
#define pinstCCharacterSelect_x                                    0xEE81DC
#define pinstCFacePick_x                                           0xEE7F8C
#define pinstCNoteWnd_x                                            0xEE8194
#define pinstCBookWnd_x                                            0xEE819C
#define pinstCPetInfoWnd_x                                         0xEE81A0
#define pinstCTrainWnd_x                                           0xEE81A4
#define pinstCSkillsWnd_x                                          0xEE81A8
#define pinstCSkillsSelectWnd_x                                    0xEE81AC
#define pinstCCombatSkillsSelectWnd_x                              0xEE81B0
#define pinstCFriendsWnd_x                                         0xEE81B4
#define pinstCAuraWnd_x                                            0xEE81B8
#define pinstCRespawnWnd_x                                         0xEE81BC
#define pinstCBandolierWnd_x                                       0xEE81C0
#define pinstCPotionBeltWnd_x                                      0xEE81C4
#define pinstCAAWnd_x                                              0xEE81C8
#define pinstCGroupSearchFiltersWnd_x                              0xEE81CC
#define pinstCLoadskinWnd_x                                        0xEE81D0
#define pinstCAlarmWnd_x                                           0xEE81D4
#define pinstCMusicPlayerWnd_x                                     0xEE81D8
#define pinstCMailWnd_x                                            0xEE81E0
#define pinstCMailCompositionWnd_x                                 0xEE81E4
#define pinstCMailAddressBookWnd_x                                 0xEE81E8
#define pinstCRaidWnd_x                                            0xEE81F0
#define pinstCRaidOptionsWnd_x                                     0xEE81F4
#define pinstCBreathWnd_x                                          0xEE81F8
#define pinstCMapViewWnd_x                                         0xEE81FC
#define pinstCMapToolbarWnd_x                                      0xEE8200
#define pinstCEditLabelWnd_x                                       0xEE8204
#define pinstCTargetWnd_x                                          0xEE8208
#define pinstCColorPickerWnd_x                                     0xEE820C
#define pinstCPlayerWnd_x                                          0xEE8210
#define pinstCOptionsWnd_x                                         0xEE8214
#define pinstCBuffWindowNORMAL_x                                   0xEE8218
#define pinstCBuffWindowSHORT_x                                    0xEE821C
#define pinstCharacterCreation_x                                   0xEE8220
#define pinstCCursorAttachment_x                                   0xEE8224
#define pinstCCastingWnd_x                                         0xEE8228
#define pinstCCastSpellWnd_x                                       0xEE822C
#define pinstCSpellBookWnd_x                                       0xEE8230
#define pinstCInventoryWnd_x                                       0xEE8234
#define pinstCBankWnd_x                                            0xEE8238
#define pinstCQuantityWnd_x                                        0xEE823C
#define pinstCLootWnd_x                                            0xEE8240
#define pinstCActionsWnd_x                                         0xEE8244
#define pinstCCombatAbilityWnd_x                                   0xEE8248
#define pinstCMerchantWnd_x                                        0xEE824C
#define pinstCTradeWnd_x                                           0xEE8250
#define pinstCSelectorWnd_x                                        0xEE8254
#define pinstCBazaarWnd_x                                          0xEE8258
#define pinstCBazaarSearchWnd_x                                    0xEE825C
#define pinstCGiveWnd_x                                            0xEE8278
#define pinstCTrackingWnd_x                                        0xEE8280
#define pinstCInspectWnd_x                                         0xEE8284
#define pinstCSocialEditWnd_x                                      0xEE8288
#define pinstCFeedbackWnd_x                                        0xEE828C
#define pinstCBugReportWnd_x                                       0xEE8290
#define pinstCVideoModesWnd_x                                      0xEE8294
#define pinstCTextEntryWnd_x                                       0xEE829C
#define pinstCFileSelectionWnd_x                                   0xEE82A0
#define pinstCCompassWnd_x                                         0xEE82A4
#define pinstCPlayerNotesWnd_x                                     0xEE82A8
#define pinstCGemsGameWnd_x                                        0xEE82AC
#define pinstCTimeLeftWnd_x                                        0xEE82B0
#define pinstCPetitionQWnd_x                                       0xEE82C4
#define pinstCSoulmarkWnd_x                                        0xEE82C8
#define pinstCStoryWnd_x                                           0xEE82CC
#define pinstCJournalTextWnd_x                                     0xEE82D0
#define pinstCJournalCatWnd_x                                      0xEE82D4
#define pinstCBodyTintWnd_x                                        0xEE82D8
#define pinstCServerListWnd_x                                      0xEE82DC
#define pinstCAvaZoneWnd_x                                         0xEE82E8
#define pinstCBlockedBuffWnd_x                                     0xEE82EC
#define pinstCBlockedPetBuffWnd_x                                  0xEE82F0
#define pinstCInvSlotMgr_x                                         0xEE8334
#define pinstCContainerMgr_x                                       0xEE8338
#define pinstCAdventureLeaderboardWnd_x                            0x113ABC8
#define pinstCAdventureRequestWnd_x                                0x113AC40
#define pinstCAltStorageWnd_x                                      0x113AF20
#define pinstCAdventureStatsWnd_x                                  0x113ACB8
#define pinstCBarterMerchantWnd_x                                  0x113BB08
#define pinstCBarterSearchWnd_x                                    0x113BB80
#define pinstCBarterWnd_x                                          0x113BBF8
#define pinstCChatManager_x                                        0x113C288
#define pinstCDynamicZoneWnd_x                                     0x113C738
#define pinstCEQMainWnd_x                                          0x113C8D0
#define pinstCFellowshipWnd_x                                      0x113C6CC
#define pinstCFindLocationWnd_x                                    0x113CBA0
#define pinstCGroupSearchWnd_x                                     0x113CE70
#define pinstCGroupWnd_x                                           0x113CEE8
#define pinstCGuildBankWnd_x                                       0x113CF60
#define pinstCGuildMgmtWnd_x                                       0x113F050
#define pinstCHotButtonWnd_x                                       0x113F11C
#define pinstCHotButtonWnd1_x                                      0x113F11C
#define pinstCHotButtonWnd2_x                                      0x113F120
#define pinstCHotButtonWnd3_x                                      0x113F124
#define pinstCHotButtonWnd4_x                                      0x113F148
#define pinstCItemDisplayManager_x                                 0x113F440
#define pinstCItemExpTransferWnd_x                                 0x113F4BC
#define pinstCLFGuildWnd_x                                         0x113F798
#define pinstCMIZoneSelectWnd_x                                    0x113FD80
#define pinstCConfirmationDialog_x                                 0x1140488
#define pinstCPopupWndManager_x                                    0x1140488
#define pinstCProgressionSelectionWnd_x                            0x1140578
#define pinstCPvPStatsWnd_x                                        0x1140668
#define pinstCSystemInfoDialogBox_x                                0x1140D70
#define pinstCTaskWnd_x                                            0x1142138
#define pinstCTaskSomething_x                                      0xDB63C0
#define pinstCTaskTemplateSelectWnd_x                              0x11420C0
#define pinstCTipWndOFDAY_x                                        0x1142390
#define pinstCTipWndCONTEXT_x                                      0x1142394
#define pinstCTitleWnd_x                                           0x1142410
#define pinstCContextMenuManager_x                                 0x17A3AA4
#define pinstCVoiceMacroWnd_x                                      0x102F048
#define pinstCHtmlWnd_x                                            0x102F140
#define pinstIconCache_x                                           0x113C8A4
#define pinstCTradeskillWnd_x                                      0x1142510
#define pinstCAdvancedLootWnd_x                                    0xEE8328
#define pinstRewardSelectionWnd_x                                  0x1140B90

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x52B0B0
#define __ConvertItemTags_x                                        0x5181F0
#define __ExecuteCmd_x                                             0x502D20
#define __EQGetTime_x                                              0x8619E0
#define __get_melee_range_x                                        0x5099C0
#define __GetGaugeValueFromEQ_x                                    0x7A1350
#define __GetLabelFromEQ_x                                         0x7A25A0
#define __ToggleMount_x                                            0x6CA2F0
#define __GetXTargetType_x                                         0x920090
#define __LoadFrontEnd_x                                           0x62EEF0
#define __NewUIINI_x                                               0x7A0C60
#define __ProcessGameEvents_x                                      0x56F620
#define __ProcessMouseEvent_x                                      0x56EDC0
#define CrashDetected_x                                            0x6309C0
#define wwsCrashReportCheckForUploader_x                           0x7F6040
#define DrawNetStatus_x                                            0x5A6390
#define Util__FastTime_x                                           0x8614F0
#define Expansion_HoT_x                                            0xFA9A2C
#define __HelpPath_x                                               0x102D198

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41EF30
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419D90

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C27E0
#define AltAdvManager__IsAbilityReady_x                            0x4C2850
#define AltAdvManager__GetAltAbility_x                             0x4C2C10

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x465910
#define CharacterZoneClient__MakeMeVisible_x                       0x46B340
// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x65E7D0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66CD70

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x585900

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x687C00
#define CChatManager__InitContextMenu_x                            0x688780

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D1DE0
#define CContextMenu__dCContextMenu_x                              0x8D1FF0
#define CContextMenu__AddMenuItem_x                                0x8D2000
#define CContextMenu__RemoveMenuItem_x                             0x8D22F0
#define CContextMenu__RemoveAllMenuItems_x                         0x8D2310
#define CContextMenuManager__AddMenu_x                             0x8BDD00
#define CContextMenuManager__RemoveMenu_x                          0x8BE030
#define CContextMenuManager__PopupMenu_x                           0x8BE480
#define CContextMenuManager__Flush_x                               0x8BDD70
#define CContextMenuManager__GetMenu_x                             0x4153D0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8479B0
#define CChatService__GetFriendName_x                              0x8479C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x68DA20
#define CChatWindow__Clear_x                                       0x68D5E0
#define CChatWindow__WndNotification_x                             0x68DF50

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C1BC0
#define CComboWnd__Draw_x                                          0x8C1DD0
#define CComboWnd__GetCurChoice_x                                  0x8C1990
#define CComboWnd__GetListRect_x                                   0x8C2070
#define CComboWnd__GetTextRect_x                                   0x8C1C30
#define CComboWnd__InsertChoice_x                                  0x8C20E0
#define CComboWnd__SetColors_x                                     0x8C1920
#define CComboWnd__SetChoice_x                                     0x8C1950
#define CComboWnd__GetItemCount_x                                  0x8C1980

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x697150
#define CContainerWnd__vftable_x                                   0xA8B760

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B0AE0
#define CDisplay__GetClickedActor_x                                0x4A9660
#define CDisplay__GetUserDefinedColor_x                            0x4A7F20
#define CDisplay__GetWorldFilePath_x                               0x4A7370
#define CDisplay__is3dON_x                                         0x4A6740
#define CDisplay__ReloadUI_x                                       0x4BBFB0
#define CDisplay__WriteTextHD2_x                                   0x4ACE80

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E84A0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D6820
#define CEditWnd__GetCharIndexPt_x                                 0x8D78C0
#define CEditWnd__GetDisplayString_x                               0x8D69D0
#define CEditWnd__GetHorzOffset_x                                  0x8D6D10
#define CEditWnd__GetLineForPrintableChar_x                        0x8D7380
#define CEditWnd__GetSelStartPt_x                                  0x8D7B80
#define CEditWnd__GetSTMLSafeText_x                                0x8D6EB0
#define CEditWnd__PointFromPrintableChar_x                         0x8D7470
#define CEditWnd__SelectableCharFromPoint_x                        0x8D75F0
#define CEditWnd__SetEditable_x                                    0x8D6E80

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x54C6C0
#define CEverQuest__DoTellWindow_x                                 0x5520C0
#define CEverQuest__DropHeldItemOnGround_x                         0x55ABF0
#define CEverQuest__dsp_chat_x                                     0x553860
#define CEverQuest__Emote_x                                        0x553AC0
#define CEverQuest__EnterZone_x                                    0x567C10
#define CEverQuest__GetBodyTypeDesc_x                              0x548F20
#define CEverQuest__GetClassDesc_x                                 0x54EC30
#define CEverQuest__GetClassThreeLetterCode_x                      0x54F230
#define CEverQuest__GetDeityDesc_x                                 0x549800
#define CEverQuest__GetLangDesc_x                                  0x5492B0
#define CEverQuest__GetRaceDesc_x                                  0x54F3F0
#define CEverQuest__InterpretCmd_x                                 0x5543A0
#define CEverQuest__LeftClickedOnPlayer_x                          0x56BD20
#define CEverQuest__LMouseUp_x                                     0x56DE10
#define CEverQuest__RightClickedOnPlayer_x                         0x56C820
#define CEverQuest__RMouseUp_x                                     0x56D870
#define CEverQuest__SetGameState_x                                 0x54CD70
#define CEverQuest__UPCNotificationFlush_x                         0x555540
#define CEverQuest__IssuePetCommand_x                              0x5550A0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A7C70
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A7CD0
#define CGaugeWnd__Draw_x                                          0x6A8100

// CGuild
#define CGuild__FindMemberByName_x                                 0x435D80

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C4D20

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D2B40
#define CInvSlotMgr__MoveItem_x                                    0x6D3A70
#define CInvSlotMgr__SelectSlot_x                                  0x6D2BF0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D1FD0
#define CInvSlot__SliderComplete_x                                 0x6CF990
#define CInvSlot__GetItemBase_x                                    0x6CEE20

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D4C00

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79DD10
#define CItemDisplayWnd__UpdateStrings_x                           0x6D5F30

// CLabel 
#define CLabel__Draw_x                                             0x6F0CF0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8ADA10
#define CListWnd__dCListWnd_x                                      0x8AEA30
#define CListWnd__AddColumn_x                                      0x8AE9D0
#define CListWnd__AddColumn1_x                                     0x8AE240
#define CListWnd__AddLine_x                                        0x8ADCC0
#define CListWnd__AddString_x                                      0x8ADED0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8AAD60
#define CListWnd__CalculateVSBRange_x                              0x8ACED0
#define CListWnd__ClearAllSel_x                                    0x8AA020
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8AD8A0
#define CListWnd__Compare_x                                        0x8AB860
#define CListWnd__Draw_x                                           0x8ACAE0
#define CListWnd__DrawColumnSeparators_x                           0x8AC970
#define CListWnd__DrawHeader_x                                     0x8AA330
#define CListWnd__DrawItem_x                                       0x8ABEA0
#define CListWnd__DrawLine_x                                       0x8AC610
#define CListWnd__DrawSeparator_x                                  0x8ACA10
#define CListWnd__EnsureVisible_x                                  0x8AAEC0
#define CListWnd__ExtendSel_x                                      0x8ABDB0
#define CListWnd__GetColumnMinWidth_x                              0x8A99E0
#define CListWnd__GetColumnWidth_x                                 0x8A9900
#define CListWnd__GetCurSel_x                                      0x8A90E0
#define CListWnd__GetItemAtPoint_x                                 0x8AB160
#define CListWnd__GetItemAtPoint1_x                                0x8AB1D0
#define CListWnd__GetItemData_x                                    0x8A9410
#define CListWnd__GetItemHeight_x                                  0x8AA9C0
#define CListWnd__GetItemIcon_x                                    0x8A95F0
#define CListWnd__GetItemRect_x                                    0x8AAFA0
#define CListWnd__GetItemText_x                                    0x8A94A0
#define CListWnd__GetSelList_x                                     0x8AE130
#define CListWnd__GetSeparatorRect_x                               0x8AB780
#define CListWnd__RemoveLine_x                                     0x8AE0B0
#define CListWnd__SetColors_x                                      0x8A9230
#define CListWnd__SetColumnJustification_x                         0x8A9CB0
#define CListWnd__SetColumnWidth_x                                 0x8A9990
#define CListWnd__SetCurSel_x                                      0x8A9120
#define CListWnd__SetItemColor_x                                   0x8AD580
#define CListWnd__SetItemData_x                                    0x8AA0D0
#define CListWnd__SetItemText_x                                    0x8AD3C0
#define CListWnd__ShiftColumnSeparator_x                           0x8AD250
#define CListWnd__Sort_x                                           0x8AEB30
#define CListWnd__ToggleSel_x                                      0x8A9FA0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70A2F0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72B3C0
#define CMerchantWnd__RequestBuyItem_x                             0x732230
#define CMerchantWnd__RequestSellItem_x                            0x732CA0
#define CMerchantWnd__SelectRecoverySlot_x                         0x72B670
#define CMerchantWnd__SelectBuySellSlot_x                          0x72A8D0
#define CMerchantWnd__ActualSelect_x                               0x72F150

// CObfuscator
#define CObfuscator__doit_x                                        0x827C80

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8CCC40
#define CSidlManager__CreateLabel_x                                0x793CF0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x655AF0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x655A20
#define CSidlScreenWnd__ConvertToRes_x                             0x8E8380
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8C4820
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C5D10
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C5DC0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C5290
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8C41D0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8C3930
#define CSidlScreenWnd__GetSidlPiece_x                             0x8C43C0
#define CSidlScreenWnd__Init1_x                                    0x8C59F0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C48D0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8C3AF0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C54E0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C3400
#define CSidlScreenWnd__StoreIniVis_x                              0x8C38C0
#define CSidlScreenWnd__WndNotification_x                          0x8C5770
#define CSidlScreenWnd__GetChildItem_x                             0x8C3A00
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B6FC0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F10A0
#define CSkillMgr__GetSkillCap_x                                   0x5F1240
#define CSkillMgr__GetNameToken_x                                  0x5F0D10

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E7650
#define CSliderWnd__SetValue_x                                     0x8E7820
#define CSliderWnd__SetNumTicks_x                                  0x8E7FA0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79B9C0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8E2020
#define CStmlWnd__CalculateHSBRange_x                              0x8DA550
#define CStmlWnd__CalculateVSBRange_x                              0x8DA5E0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8DA760
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8DB040
#define CStmlWnd__ForceParseNow_x                                  0x8E2970
#define CStmlWnd__GetNextTagPiece_x                                0x8DAF40
#define CStmlWnd__GetSTMLText_x                                    0x68CE80
#define CStmlWnd__GetVisibleText_x                                 0x8DBA90
#define CStmlWnd__InitializeWindowVariables_x                      0x8DDE20
#define CStmlWnd__MakeStmlColorTag_x                               0x8D9850
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D98B0
#define CStmlWnd__SetSTMLText_x                                    0x8DF680
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E1CC0
#define CStmlWnd__UpdateHistoryString_x                            0x8DC9D0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E9B80
#define CTabWnd__DrawCurrentPage_x                                 0x8E93F0
#define CTabWnd__DrawTab_x                                         0x8E91B0
#define CTabWnd__GetCurrentPage_x                                  0x8E97C0
#define CTabWnd__GetPageInnerRect_x                                0x8E8EA0
#define CTabWnd__GetTabInnerRect_x                                 0x8E90A0
#define CTabWnd__GetTabRect_x                                      0x8E8F70
#define CTabWnd__InsertPage_x                                      0x8E9E70
#define CTabWnd__SetPage_x                                         0x8E97F0
#define CTabWnd__SetPageRect_x                                     0x8E9AC0
#define CTabWnd__UpdatePage_x                                      0x8E9E10

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431B80

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C1590

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8EED20

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A7240

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4022B0
#define CXStr__CXStr1_x                                            0x7D2110
#define CXStr__CXStr3_x                                            0x85E580
#define CXStr__dCXStr_x                                            0x8E3420
#define CXStr__operator_equal_x                                    0x85E6F0
#define CXStr__operator_equal1_x                                   0x85E740
#define CXStr__operator_plus_equal1_x                              0x85F820

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B6220
#define CXWnd__Center_x                                            0x8BC370
#define CXWnd__ClrFocus_x                                          0x8B5DE0
#define CXWnd__DoAllDrawing_x                                      0x8BBFC0
#define CXWnd__DrawChildren_x                                      0x8BC160
#define CXWnd__DrawColoredRect_x                                   0x8B65A0
#define CXWnd__DrawTooltip_x                                       0x8B6850
#define CXWnd__DrawTooltipAtPoint_x                                0x8BAF50
#define CXWnd__GetBorderFrame_x                                    0x8B6CB0
#define CXWnd__GetChildWndAt_x                                     0x8BCD20
#define CXWnd__GetClientClipRect_x                                 0x8B6A70
#define CXWnd__GetScreenClipRect_x                                 0x8BB650
#define CXWnd__GetScreenRect_x                                     0x8B6E60
#define CXWnd__GetTooltipRect_x                                    0x8B66E0
#define CXWnd__GetWindowTextA_x                                    0x423000
#define CXWnd__IsActive_x                                          0x8B1810
#define CXWnd__IsDescendantOf_x                                    0x8B6C00
#define CXWnd__IsReallyVisible_x                                   0x8B9F40
#define CXWnd__IsType_x                                            0x8EB540
#define CXWnd__Move_x                                              0x8B9620
#define CXWnd__Move1_x                                             0x8BBC70
#define CXWnd__ProcessTransition_x                                 0x8B61C0
#define CXWnd__Refade_x                                            0x8B61C0
#define CXWnd__Resize_x                                            0x8B6F20
#define CXWnd__Right_x                                             0x8BB450
#define CXWnd__SetFocus_x                                          0x8B8790
#define CXWnd__SetFont_x                                           0x8B5E30
#define CXWnd__SetKeyTooltip_x                                     0x8B7190
#define CXWnd__SetMouseOver_x                                      0x8BB970
#define CXWnd__StartFade_x                                         0x8B6270
#define CXWnd__GetChildItem_x                                      0x8BB8B0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B3120
#define CXWndManager__DrawWindows_x                                0x8B2D70
#define CXWndManager__GetKeyboardFlags_x                           0x8B1380
#define CXWndManager__HandleKeyboardMsg_x                          0x8B1CB0
#define CXWndManager__RemoveWnd_x                                  0x8B19A0

// CDBStr
#define CDBStr__GetString_x                                        0x4A4CE0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44F920
#define EQ_Character__Cur_HP_x                                     0x464FE0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4472E0
#define EQ_Character__GetCharInfo2_x                               0x832410
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F3E0
#define EQ_Character__GetFocusRangeModifier_x                      0x43F5C0
#define EQ_Character__Max_Endurance_x                              0x5B8870
#define EQ_Character__Max_HP_x                                     0x45AC50
#define EQ_Character__Max_Mana_x                                   0x5B86A0
#define EQ_Character__doCombatAbility_x                            0x5B5C90
#define EQ_Character__UseSkill_x                                   0x470540
#define EQ_Character__GetConLevel_x                                0x5AAA40
#define EQ_Character__IsExpansionFlag_x                            0x422540
#define EQ_Character__TotalEffect_x                                0x44C660

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x58B130
#define EQ_Item__CreateItemTagString_x                             0x811920
#define EQ_Item__IsStackable_x                                     0x805CE0
#define EQ_Item__GetImageNum_x                                     0x808A10

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C4900
#define EQ_LoadingS__Array_x                                       0xBAC858

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BA010
#define EQ_PC__GetAltAbilityIndex_x                                0x81A9E0
#define EQ_PC__GetCombatAbility_x                                  0x81AA70
#define EQ_PC__GetCombatAbilityTimer_x                             0x815A00
#define EQ_PC__GetItemTimerValue_x                                 0x5B3A80
#define EQ_PC__HasLoreItem_x                                       0x5ADDC0
#define EQ_PC__AlertInventoryChanged_x                             0x5AAA10
#define EQ_PC__GetPcZoneClient_x                                   0x5D4600
#define EQ_PC__RemoveMyAffect_x									   0x5B2F90

// EQItemList 
#define EQItemList__EQItemList_x                                   0x507A20
#define EQItemList__add_item_x                                     0x507960
#define EQItemList__delete_item_x                                  0x507E20
#define EQItemList__FreeItemList_x                                 0x507D20

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A3FD0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5BF5D0
#define EQPlayer__dEQPlayer_x                                      0x5C8430
#define EQPlayer__DoAttack_x                                       0x5DA510
#define EQPlayer__EQPlayer_x                                       0x5CA850
#define EQPlayer__SetNameSpriteState_x                             0x5C5110
#define EQPlayer__SetNameSpriteTint_x                              0x5C09E0
#define EQPlayer__IsBodyType_j_x                                   0x91C320
#define EQPlayer__IsTargetable_x                                   0x91CBE0
#define EQPlayer__CanSee_x                                         0x91D100

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5CEB50
#define EQPlayerManager__GetSpawnByName_x                          0x5CEFB0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x591220
#define KeypressHandler__AttachKeyToEqCommand_x                    0x591260
#define KeypressHandler__ClearCommandStateArray_x                  0x590E00
#define KeypressHandler__HandleKeyDown_x                           0x58F760
#define KeypressHandler__HandleKeyUp_x                             0x58FA80
#define KeypressHandler__SaveKeymapping_x                          0x590ED0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7026D0
#define MapViewMap__SaveEx_x                                       0x705FB0

#define PlayerPointManager__GetAltCurrency_x                       0x82D3A0

// StringTable 
#define StringTable__getString_x                                   0x827F20

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B8320
#define PcZoneClient__RemovePetEffect_x                            0x5B3CB0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5462D0

//IconCache
#define IconCache__GetIcon_x                                       0x69D5B0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x694480
#define CContainerMgr__CloseContainer_x                            0x694CA0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x763EB0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5843C0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D80A0
#define EQ_Spell__SpellAffects_x                                   0x4D8140
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D8170
#define CharacterZoneClient__CalcAffectChange_x                    0x4486D0
#define CLootWnd__LootAll_x                                        0x6F7FD0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7A9900
#define CTargetWnd__WndNotification_x                              0x7A93F0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7AEAE0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D19C0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x494B80
