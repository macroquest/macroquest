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
#include "eqgame-private(Test).h"
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Jul 23 2015"
#define __ExpectedVersionTime                                     "14:44:52"
#define __ActualVersionDate_x                                      0xA81FF0
#define __ActualVersionTime_x                                      0xA81FFC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5964F0
#define __MemChecker1_x                                            0x861340
#define __MemChecker2_x                                            0x62F320
#define __MemChecker3_x                                            0x62F270
#define __MemChecker4_x                                            0x7E4D80
#define __EncryptPad0_x                                            0xC005D0
#define __EncryptPad1_x                                            0xD87F80
#define __EncryptPad2_x                                            0xC49F18
#define __EncryptPad3_x                                            0xC49B18
#define __EncryptPad4_x                                            0xD63FE8
#define __AC1_x                                                    0x7A22F5
#define __AC2_x                                                    0x54BA87
#define __AC3_x                                                    0x560280
#define __AC4_x                                                    0x566F00
#define __AC5_x                                                    0x572D2E
#define __AC6_x                                                    0x5767D9
#define __AC7_x                                                    0x56D3DC
#define __AC1_Data                                                 0x11111111

// Direct Input
#define DI8__Main_x                                                0x113A090
#define DI8__Keyboard_x                                            0x113A094
#define DI8__Mouse_x                                               0x113A098
#define DI8__Mouse_Copy_x                                          0xFA86AC
#define DI8__Mouse_Check_x                                         0x1031F7C
#define __AltTimerReady_x                                          0xF999F9
#define __Attack_x                                                 0x102CC1B
#define __Autofire_x                                               0x102CC1C
#define __BindList_x                                               0xBC2828
#define __bCommandEnabled_x                                        0xF97B08
#define __Clicks_x                                                 0xFA8768
#define __CommandList_x                                            0xBC6B80
#define __CurrentMapLabel_x                                        0x113FAE8
#define __CurrentSocial_x                                          0xB7DE7C
#define __DoAbilityList_x                                          0xFDEED0
#define __do_loot_x                                                0x5132E0
#define __DrawHandler_x                                            0x17A46F4
#define __GroupCount_x                                             0xF990D2

#define __Guilds_x                                                 0xF9ECE8
#define __gWorld_x                                                 0xF9B58C
#define __HotkeyPage_x                                             0x10258D0
#define __HWnd_x                                                   0x1031F98
#define __InChatMode_x                                             0xFA8694
#define __LastTell_x                                               0xFAA5D8
#define __LMouseHeldTime_x                                         0xFA87D4
#define __Mouse_x                                                  0x113A09C
#define __MouseLook_x                                              0xFA872E
#define __MouseEventTime_x                                         0x102D424
#define __gpbCommandEvent_x                                        0xF9B654
#define __NetStatusToggle_x                                        0xFA8731
#define __PCNames_x                                                0xFA9BF8
#define __RangeAttackReady_x                                       0xFA98B8
#define __RMouseHeldTime_x                                         0xFA87D0
#define __RunWalkState_x                                           0xFA8698
#define __ScreenMode_x                                             0xEE7938
#define __ScreenX_x                                                0xFA864C
#define __ScreenY_x                                                0xFA8648
#define __ScreenXMax_x                                             0xFA8650
#define __ScreenYMax_x                                             0xFA8654
#define __ServerHost_x                                             0xF9901C
#define __ServerName_x                                             0xFDEE90
#define __ShiftKeyDown_x                                           0xFA8D3C
#define __ShowNames_x                                              0xFA9A8C
#define __Socials_x                                                0xFDEF90
#define __SubscriptionType_x                                       0x116BE78
#define __TargetAggroHolder_x                                      0x1141D24
#define __GroupAggro_x                                             0x1141D64
#define __LoginName_x                                              0x1030B70
#define __Inviter_x                                                0x102CB98


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF9B678
#define instEQZoneInfo_x                                           0xFA8924
#define instKeypressHandler_x                                      0x102D408
#define pinstActiveBanker_x                                        0xF9B630
#define pinstActiveCorpse_x                                        0xF9B634
#define pinstActiveGMaster_x                                       0xF9B638
#define pinstActiveMerchant_x                                      0xF9B62C
#define pinstAggroInfo_x                                           0xDABDB8
#define pinstAltAdvManager_x                                       0xEE8A30
#define pinstAuraMgr_x                                             0xDB5C80
#define pinstBandageTarget_x                                       0xF9B618
#define pinstCamActor_x                                            0xEE833C
#define pinstCDBStr_x                                              0xEE78CC
#define pinstCDisplay_x                                            0xF9B640
#define pinstCEverQuest_x                                          0x113A210
#define pinstCharData_x                                            0xF9B5FC
#define pinstCharSpawn_x                                           0xF9B624
#define pinstControlledMissile_x                                   0xF9B5F8
#define pinstControlledPlayer_x                                    0xF9B624
#define pinstCSidlManager_x                                        0x17A3B2C
#define pinstCXWndManager_x                                        0x17A3B24
#define instDynamicZone_x                                          0xFA84E0
#define pinstDZMember_x                                            0xFA85F0
#define pinstDZTimerInfo_x                                         0xFA85F4
#define pinstEQItemList_x                                          0xF97D58
#define instEQMisc_x                                               0xB9EAC0
#define pinstEQSoundManager_x                                      0xEE8EA0
#define instExpeditionLeader_x                                     0xFA852A
#define instExpeditionName_x                                       0xFA856A
#define pinstGroup_x                                               0xF990CE
#define pinstImeManager_x                                          0x17A3B30
#define pinstLocalPlayer_x                                         0xF9B610
#define pinstMercenaryData_x                                       0x102DA58
#define pinstMercenaryStats_x                                      0x0
#define pinstMercAltAbilities_x                                    0xEE8DBC
#define pinstModelPlayer_x                                         0xF9B63C
#define pinstPCData_x                                              0xF9B5FC
#define pinstSkillMgr_x                                            0x102E890
#define pinstSpawnManager_x                                        0x102E178
#define pinstSpellManager_x                                        0x102E9D8
#define pinstSpellSets_x                                           0x1025934
#define pinstStringTable_x                                         0xF9B5A4
#define pinstSwitchManager_x                                       0xF98C60
#define pinstTarget_x                                              0xF9B628
#define pinstTargetObject_x                                        0xF9B600
#define pinstTargetSwitch_x                                        0xF9B604
#define pinstTaskMember_x                                          0xEE7818
#define pinstTrackTarget_x                                         0xF9B61C
#define pinstTradeTarget_x                                         0xF9B60C
#define instTributeActive_x                                        0xB9EAE5
#define pinstViewActor_x                                           0xEE8338
#define pinstWorldData_x                                           0xF9B5E0


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xDAC298
#define pinstCAudioTriggersWindow_x                                0xDAC128
#define pinstCCharacterSelect_x                                    0xEE81D8
#define pinstCFacePick_x                                           0xEE8188
#define pinstCNoteWnd_x                                            0xEE8190
#define pinstCBookWnd_x                                            0xEE8198
#define pinstCPetInfoWnd_x                                         0xEE819C
#define pinstCTrainWnd_x                                           0xEE81A0
#define pinstCSkillsWnd_x                                          0xEE81A4
#define pinstCSkillsSelectWnd_x                                    0xEE81A8
#define pinstCCombatSkillsSelectWnd_x                              0xEE81AC
#define pinstCFriendsWnd_x                                         0xEE81B0
#define pinstCAuraWnd_x                                            0xEE81B4
#define pinstCRespawnWnd_x                                         0xEE81B8
#define pinstCBandolierWnd_x                                       0xEE81BC
#define pinstCPotionBeltWnd_x                                      0xEE81C0
#define pinstCAAWnd_x                                              0xEE81C4
#define pinstCGroupSearchFiltersWnd_x                              0xEE81C8
#define pinstCLoadskinWnd_x                                        0xEE81CC
#define pinstCAlarmWnd_x                                           0xEE81D0
#define pinstCMusicPlayerWnd_x                                     0xEE81D4
#define pinstCMailWnd_x                                            0xEE81DC
#define pinstCMailCompositionWnd_x                                 0xEE81E0
#define pinstCMailAddressBookWnd_x                                 0xEE81E4
#define pinstCRaidWnd_x                                            0xEE81EC
#define pinstCRaidOptionsWnd_x                                     0xEE81F0
#define pinstCBreathWnd_x                                          0xEE81F4
#define pinstCMapViewWnd_x                                         0xEE81F8
#define pinstCMapToolbarWnd_x                                      0xEE81FC
#define pinstCEditLabelWnd_x                                       0xEE8200
#define pinstCTargetWnd_x                                          0xEE8204
#define pinstCColorPickerWnd_x                                     0xEE8208
#define pinstCPlayerWnd_x                                          0xEE820C
#define pinstCOptionsWnd_x                                         0xEE8210
#define pinstCBuffWindowNORMAL_x                                   0xEE8214
#define pinstCBuffWindowSHORT_x                                    0xEE8218
#define pinstCharacterCreation_x                                   0xEE821C
#define pinstCCursorAttachment_x                                   0xEE8220
#define pinstCCastingWnd_x                                         0xEE8224
#define pinstCCastSpellWnd_x                                       0xEE8228
#define pinstCSpellBookWnd_x                                       0xEE822C
#define pinstCInventoryWnd_x                                       0xEE8230
#define pinstCBankWnd_x                                            0xEE8234
#define pinstCQuantityWnd_x                                        0xEE8238
#define pinstCLootWnd_x                                            0xEE823C
#define pinstCActionsWnd_x                                         0xEE8240
#define pinstCCombatAbilityWnd_x                                   0xEE8244
#define pinstCMerchantWnd_x                                        0xEE8248
#define pinstCTradeWnd_x                                           0xEE824C
#define pinstCSelectorWnd_x                                        0xEE8250
#define pinstCBazaarWnd_x                                          0xEE8254
#define pinstCBazaarSearchWnd_x                                    0xEE8258
#define pinstCGiveWnd_x                                            0xEE8274
#define pinstCTrackingWnd_x                                        0xEE827C
#define pinstCInspectWnd_x                                         0xEE8280
#define pinstCSocialEditWnd_x                                      0xEE8284
#define pinstCFeedbackWnd_x                                        0xEE8288
#define pinstCBugReportWnd_x                                       0xEE828C
#define pinstCVideoModesWnd_x                                      0xEE8290
#define pinstCTextEntryWnd_x                                       0xEE8298
#define pinstCFileSelectionWnd_x                                   0xEE829C
#define pinstCCompassWnd_x                                         0xEE82A0
#define pinstCPlayerNotesWnd_x                                     0xEE82A4
#define pinstCGemsGameWnd_x                                        0xEE82A8
#define pinstCTimeLeftWnd_x                                        0xEE82AC
#define pinstCPetitionQWnd_x                                       0xEE82C0
#define pinstCSoulmarkWnd_x                                        0xEE82C4
#define pinstCStoryWnd_x                                           0xEE82C8
#define pinstCJournalTextWnd_x                                     0xEE82CC
#define pinstCJournalCatWnd_x                                      0xEE82D0
#define pinstCBodyTintWnd_x                                        0xEE82D4
#define pinstCServerListWnd_x                                      0xEE82D8
#define pinstCAvaZoneWnd_x                                         0xEE82E4
#define pinstCBlockedBuffWnd_x                                     0xEE82E8
#define pinstCBlockedPetBuffWnd_x                                  0xEE82EC
#define pinstCInvSlotMgr_x                                         0xEE8330
#define pinstCContainerMgr_x                                       0xEE8334
#define pinstCAdventureLeaderboardWnd_x                            0x113ABC0
#define pinstCAdventureRequestWnd_x                                0x113AC38
#define pinstCAltStorageWnd_x                                      0x113AF18
#define pinstCAdventureStatsWnd_x                                  0x113ACB0
#define pinstCBarterMerchantWnd_x                                  0x113BB00
#define pinstCBarterSearchWnd_x                                    0x113BB78
#define pinstCBarterWnd_x                                          0x113BBF0
#define pinstCChatManager_x                                        0x113C280
#define pinstCDynamicZoneWnd_x                                     0x113C730
#define pinstCEQMainWnd_x                                          0x113C8C8
#define pinstCFellowshipWnd_x                                      0x113C6C4
#define pinstCFindLocationWnd_x                                    0x113CB98
#define pinstCGroupSearchWnd_x                                     0x113CE68
#define pinstCGroupWnd_x                                           0x113CEE0
#define pinstCGuildBankWnd_x                                       0x113CF58
#define pinstCGuildMgmtWnd_x                                       0x113F048
#define pinstCHotButtonWnd_x                                       0x113F114
#define pinstCHotButtonWnd1_x                                      0x113F114
#define pinstCHotButtonWnd2_x                                      0x113F118
#define pinstCHotButtonWnd3_x                                      0x113F11C
#define pinstCHotButtonWnd4_x                                      0x113F140
#define pinstCItemDisplayManager_x                                 0x113F438
#define pinstCItemExpTransferWnd_x                                 0x113F4B4
#define pinstCLFGuildWnd_x                                         0x113F790
#define pinstCMIZoneSelectWnd_x                                    0x113FD78
#define pinstCConfirmationDialog_x                                 0x1140480
#define pinstCPopupWndManager_x                                    0x1140480
#define pinstCProgressionSelectionWnd_x                            0x1140570
#define pinstCPvPStatsWnd_x                                        0x1140660
#define pinstCSystemInfoDialogBox_x                                0x1140D68
#define pinstCTaskWnd_x                                            0x1142130
#define pinstCTaskSomething_x                                      0xDB63C0
#define pinstCTaskTemplateSelectWnd_x                              0x11420B8
#define pinstCTipWndOFDAY_x                                        0x1142388
#define pinstCTipWndCONTEXT_x                                      0x114238C
#define pinstCTitleWnd_x                                           0x1142408
#define pinstCContextMenuManager_x                                 0x17A3A9C
#define pinstCVoiceMacroWnd_x                                      0x102F040
#define pinstCHtmlWnd_x                                            0x102F138
#define pinstIconCache_x                                           0x113C89C
#define pinstCTradeskillWnd_x                                      0x1142508
#define pinstCAdvancedLootWnd_x                                    0xEE8324
#define pinstRewardSelectionWnd_x                                  0x1140B88

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x52AC70
#define __ConvertItemTags_x                                        0x517F60
#define __ExecuteCmd_x                                             0x502940
#define __EQGetTime_x                                              0x861660
#define __get_melee_range_x                                        0x509600
#define __GetGaugeValueFromEQ_x                                    0x7A1040
#define __GetLabelFromEQ_x                                         0x7A2280
#define __ToggleMount_x                                            0x6CA190
#define __GetXTargetType_x                                         0x91FDE0
#define __LoadFrontEnd_x                                           0x62E9D0
#define __NewUIINI_x                                               0x7A0940
#define __ProcessGameEvents_x                                      0x56F140
#define __ProcessMouseEvent_x                                      0x56E8E0
#define CrashDetected_x                                            0x6304A0
#define wwsCrashReportCheckForUploader_x                           0x7F5D90
#define DrawNetStatus_x                                            0x5A6060
#define Util__FastTime_x                                           0x8611B0
#define Expansion_HoT_x                                            0xFA9A24
#define __HelpPath_x                                               0x102D190
//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41F180
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419FD0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C2910
#define AltAdvManager__IsAbilityReady_x                            0x4C2980
#define AltAdvManager__GetAltAbility_x                             0x4C2D40

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x465910
#define CharacterZoneClient__MakeMeVisible_x                       0x46B340

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x65E4D0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66C2B0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5854D0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x687850
#define CChatManager__InitContextMenu_x                            0x6883D0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D1A90
#define CContextMenu__AddMenuItem_x                                0x8D1CB0
#define CContextMenu__dCContextMenu_x                              0x8D1CA0
#define CContextMenu__RemoveMenuItem_x                             0x8D1FA0
#define CContextMenu__RemoveAllMenuItems_x                         0x8D1FC0
#define CContextMenuManager__AddMenu_x                             0x8BD940
#define CContextMenuManager__RemoveMenu_x                          0x8BDC80
#define CContextMenuManager__PopupMenu_x                           0x8BE0D0
#define CContextMenuManager__Flush_x                               0x8BD9B0
#define CContextMenuManager__GetMenu_x                             0x415620

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x847730
#define CChatService__GetFriendName_x                              0x847740

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x68D680
#define CChatWindow__Clear_x                                       0x68D230
#define CChatWindow__WndNotification_x                             0x68DBC0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C1850
#define CComboWnd__Draw_x                                          0x8C1A60
#define CComboWnd__GetCurChoice_x                                  0x8C1620
#define CComboWnd__GetListRect_x                                   0x8C1D00
#define CComboWnd__GetTextRect_x                                   0x8C18C0
#define CComboWnd__InsertChoice_x                                  0x8C1D70
#define CComboWnd__SetColors_x                                     0x8C15B0
#define CComboWnd__SetChoice_x                                     0x8C15E0
#define CComboWnd__GetItemCount_x                                  0x8C1610

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x696DC0
#define CContainerWnd__vftable_x                                   0xA8B780

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B0BD0
#define CDisplay__GetClickedActor_x                                0x4A9760
#define CDisplay__GetUserDefinedColor_x                            0x4A8020
#define CDisplay__GetWorldFilePath_x                               0x4A7470
#define CDisplay__is3dON_x                                         0x4A6840
#define CDisplay__ReloadUI_x                                       0x4BC0A0
#define CDisplay__WriteTextHD2_x                                   0x4ACF70

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E80F0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D6430
#define CEditWnd__GetCharIndexPt_x                                 0x8D74D0
#define CEditWnd__GetDisplayString_x                               0x8D65E0
#define CEditWnd__GetHorzOffset_x                                  0x8D6920
#define CEditWnd__GetLineForPrintableChar_x                        0x8D6F90
#define CEditWnd__GetSelStartPt_x                                  0x8D7790
#define CEditWnd__GetSTMLSafeText_x                                0x8D6AC0
#define CEditWnd__PointFromPrintableChar_x                         0x8D7080
#define CEditWnd__SelectableCharFromPoint_x                        0x8D7200
#define CEditWnd__SetEditable_x                                    0x8D6A90

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x54C1D0
#define CEverQuest__DoTellWindow_x                                 0x551BD0
#define CEverQuest__DropHeldItemOnGround_x                         0x55A700
#define CEverQuest__dsp_chat_x                                     0x553370
#define CEverQuest__Emote_x                                        0x5535D0
#define CEverQuest__EnterZone_x                                    0x567720
#define CEverQuest__GetBodyTypeDesc_x                              0x548A30
#define CEverQuest__GetClassDesc_x                                 0x54E740
#define CEverQuest__GetClassThreeLetterCode_x                      0x54ED40
#define CEverQuest__GetDeityDesc_x                                 0x549310
#define CEverQuest__GetLangDesc_x                                  0x548DC0
#define CEverQuest__GetRaceDesc_x                                  0x54EF00
#define CEverQuest__InterpretCmd_x                                 0x553EB0
#define CEverQuest__LeftClickedOnPlayer_x                          0x56B840
#define CEverQuest__LMouseUp_x                                     0x56D930
#define CEverQuest__RightClickedOnPlayer_x                         0x56C340
#define CEverQuest__RMouseUp_x                                     0x56D390
#define CEverQuest__SetGameState_x                                 0x54C880
#define CEverQuest__UPCNotificationFlush_x                         0x555050
#define CEverQuest__IssuePetCommand_x                              0x554BB0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A7A20
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A7A80
#define CGaugeWnd__Draw_x                                          0x6A7EB0

// CGuild
#define CGuild__FindMemberByName_x                                 0x435F80

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C4BC0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D29F0
#define CInvSlotMgr__MoveItem_x                                    0x6D3930
#define CInvSlotMgr__SelectSlot_x                                  0x6D2AA0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D1E80
#define CInvSlot__SliderComplete_x                                 0x6CF840
#define CInvSlot__GetItemBase_x                                    0x6CECB0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D4AF0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79DA40
#define CItemDisplayWnd__UpdateStrings_x                           0x6D5E20

// CLabel 
#define CLabel__Draw_x                                             0x6F0C30

// CListWnd 
#define CListWnd__CListWnd_x                                       0x8AD580
#define CListWnd__dCListWnd_x                                      0x8AE5B0
#define CListWnd__AddColumn_x                                      0x8AE550
#define CListWnd__AddColumn1_x                                     0x8ADDC0
#define CListWnd__AddLine_x                                        0x8AD840
#define CListWnd__AddString_x                                      0x8ADA50
#define CListWnd__CalculateFirstVisibleLine_x                      0x8AA8A0
#define CListWnd__CalculateVSBRange_x                              0x8ACA30
#define CListWnd__ClearAllSel_x                                    0x8A9B50
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8AD410
#define CListWnd__Compare_x                                        0x8AB3B0
#define CListWnd__Draw_x                                           0x8AC640
#define CListWnd__DrawColumnSeparators_x                           0x8AC4D0
#define CListWnd__DrawHeader_x                                     0x8A9E60
#define CListWnd__DrawItem_x                                       0x8ABA00
#define CListWnd__DrawLine_x                                       0x8AC170
#define CListWnd__DrawSeparator_x                                  0x8AC570
#define CListWnd__EnsureVisible_x                                  0x8AAA00
#define CListWnd__ExtendSel_x                                      0x8AB910
#define CListWnd__GetColumnMinWidth_x                              0x8A9510
#define CListWnd__GetColumnWidth_x                                 0x8A9430
#define CListWnd__GetCurSel_x                                      0x8A8C00
#define CListWnd__GetItemAtPoint_x                                 0x8AACA0
#define CListWnd__GetItemAtPoint1_x                                0x8AAD10
#define CListWnd__GetItemData_x                                    0x8A8F50
#define CListWnd__GetItemHeight_x                                  0x8AA4F0
#define CListWnd__GetItemIcon_x                                    0x8A9130
#define CListWnd__GetItemRect_x                                    0x8AAAE0
#define CListWnd__GetItemText_x                                    0x8A8FE0
#define CListWnd__GetSelList_x                                     0x8ADCB0
#define CListWnd__GetSeparatorRect_x                               0x8AB2D0
#define CListWnd__RemoveLine_x                                     0x8ADC30
#define CListWnd__SetColors_x                                      0x8A8D50
#define CListWnd__SetColumnJustification_x                         0x8A97E0
#define CListWnd__SetColumnWidth_x                                 0x8A94C0
#define CListWnd__SetCurSel_x                                      0x8A8C40
#define CListWnd__SetItemColor_x                                   0x8AD0F0
#define CListWnd__SetItemData_x                                    0x8A9C00
#define CListWnd__SetItemText_x                                    0x8ACF30
#define CListWnd__ShiftColumnSeparator_x                           0x8ACDC0
#define CListWnd__Sort_x                                           0x8AE6B0
#define CListWnd__ToggleSel_x                                      0x8A9AD0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70A140

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72B3C0
#define CMerchantWnd__RequestBuyItem_x                             0x732210
#define CMerchantWnd__RequestSellItem_x                            0x732C80
#define CMerchantWnd__SelectRecoverySlot_x                         0x72B670
#define CMerchantWnd__SelectBuySellSlot_x                          0x72A8D0
#define CMerchantWnd__ActualSelect_x                               0x72F140

// CObfuscator
#define CObfuscator__doit_x                                        0x827800

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8CCA00
#define CSidlManager__CreateLabel_x                                0x793A40

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x6557C0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x6556E0
#define CSidlScreenWnd__ConvertToRes_x                             0x8E7FD0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8C4500
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C5A00
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C5AB0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C4F60
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8C3EB0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8C35E0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8C40A0
#define CSidlScreenWnd__Init1_x                                    0x8C56D0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C45B0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8C37A0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C51B0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C30B0
#define CSidlScreenWnd__StoreIniVis_x                              0x8C3570
#define CSidlScreenWnd__WndNotification_x                          0x8C5450
#define CSidlScreenWnd__GetChildItem_x                             0x8C36B0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B6BE0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F0A50
#define CSkillMgr__GetSkillCap_x                                   0x5F0BF0
#define CSkillMgr__GetNameToken_x                                  0x5F06C0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E7280
#define CSliderWnd__SetValue_x                                     0x8E7450
#define CSliderWnd__SetNumTicks_x                                  0x8E7BD0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79B6E0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8E1C80
#define CStmlWnd__CalculateHSBRange_x                              0x8DA180
#define CStmlWnd__CalculateVSBRange_x                              0x8DA210
#define CStmlWnd__CanBreakAtCharacter_x                            0x8DA390
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8DAC70
#define CStmlWnd__ForceParseNow_x                                  0x8E25D0
#define CStmlWnd__GetNextTagPiece_x                                0x8DAB70
#define CStmlWnd__GetSTMLText_x                                    0x68CAD0
#define CStmlWnd__GetVisibleText_x                                 0x8DB6C0
#define CStmlWnd__InitializeWindowVariables_x                      0x8DDA50
#define CStmlWnd__MakeStmlColorTag_x                               0x8D9480
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D94E0
#define CStmlWnd__SetSTMLText_x                                    0x8DF2C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E1920
#define CStmlWnd__UpdateHistoryString_x                            0x8DC600

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E97D0
#define CTabWnd__DrawCurrentPage_x                                 0x8E9040
#define CTabWnd__DrawTab_x                                         0x8E8E00
#define CTabWnd__GetCurrentPage_x                                  0x8E9410
#define CTabWnd__GetPageInnerRect_x                                0x8E8AF0
#define CTabWnd__GetTabInnerRect_x                                 0x8E8CF0
#define CTabWnd__GetTabRect_x                                      0x8E8BC0
#define CTabWnd__InsertPage_x                                      0x8E9AC0
#define CTabWnd__SetPage_x                                         0x8E9440
#define CTabWnd__SetPageRect_x                                     0x8E9710
#define CTabWnd__UpdatePage_x                                      0x8E9A60

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431D00

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C1220

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8EE990

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A6D60

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x592AB0
#define CXStr__CXStr1_x                                            0x4DC400
#define CXStr__CXStr3_x                                            0x85E240
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x85E3B0
#define CXStr__operator_equal1_x                                   0x85E400
#define CXStr__operator_plus_equal1_x                              0x85F4E0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B5E00
#define CXWnd__Center_x                                            0x8BBF10
#define CXWnd__ClrFocus_x                                          0x8B59D0
#define CXWnd__DoAllDrawing_x                                      0x8BBB60
#define CXWnd__DrawChildren_x                                      0x8BBD00
#define CXWnd__DrawColoredRect_x                                   0x8B61B0
#define CXWnd__DrawTooltip_x                                       0x8B6460
#define CXWnd__DrawTooltipAtPoint_x                                0x8BAAD0
#define CXWnd__GetBorderFrame_x                                    0x8B68C0
#define CXWnd__GetChildWndAt_x                                     0x8BC8E0
#define CXWnd__GetClientClipRect_x                                 0x8B6670
#define CXWnd__GetScreenClipRect_x                                 0x8BB1D0
#define CXWnd__GetScreenRect_x                                     0x8B6A90
#define CXWnd__GetTooltipRect_x                                    0x8B62F0
#define CXWnd__GetWindowTextA_x                                    0x423250
#define CXWnd__IsActive_x                                          0x8B1390
#define CXWnd__IsDescendantOf_x                                    0x8B6800
#define CXWnd__IsReallyVisible_x                                   0x8B9B10
#define CXWnd__IsType_x                                            0x8EB190
#define CXWnd__Move_x                                              0x8B9290
#define CXWnd__Move1_x                                             0x8BB820
#define CXWnd__ProcessTransition_x                                 0x8B5DB0
#define CXWnd__Refade_x                                            0x8B5B80
#define CXWnd__Resize_x                                            0x8B6B40
#define CXWnd__Right_x                                             0x8BAFD0
#define CXWnd__SetFocus_x                                          0x8B8400
#define CXWnd__SetFont_x                                           0x8B5A20
#define CXWnd__SetKeyTooltip_x                                     0x8B6DB0
#define CXWnd__SetMouseOver_x                                      0x8BB510
#define CXWnd__StartFade_x                                         0x8B5E50
#define CXWnd__GetChildItem_x                                      0x8BB450

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B2CD0
#define CXWndManager__DrawWindows_x                                0x8B2910
#define CXWndManager__GetKeyboardFlags_x                           0x8B0EC0
#define CXWndManager__HandleKeyboardMsg_x                          0x8B1830
#define CXWndManager__RemoveWnd_x                                  0x8B1520

// CDBStr
#define CDBStr__GetString_x                                        0x4A4E10

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44FA10
#define EQ_Character__Cur_HP_x                                     0x464FE0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4473B0
#define EQ_Character__GetCharInfo2_x                               0x832060
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F590
#define EQ_Character__GetFocusRangeModifier_x                      0x43F770
#define EQ_Character__Max_Endurance_x                              0x5B86A0
#define EQ_Character__Max_HP_x                                     0x45AC70
#define EQ_Character__Max_Mana_x                                   0x5B84D0
#define EQ_Character__doCombatAbility_x                            0x5B5AB0
#define EQ_Character__UseSkill_x                                   0x470540
#define EQ_Character__GetConLevel_x                                0x5AA730
#define EQ_Character__IsExpansionFlag_x                            0x422790
#define EQ_Character__TotalEffect_x                                0x44C750

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x58AC70
#define EQ_Item__CreateItemTagString_x                             0x811560
#define EQ_Item__IsStackable_x                                     0x8059B0
#define EQ_Item__GetImageNum_x                                     0x808740

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C4A00
#define EQ_LoadingS__Array_x                                       0xBAC858

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5B9E40
#define EQ_PC__GetAltAbilityIndex_x                                0x81A5C0
#define EQ_PC__GetCombatAbility_x                                  0x81A650
#define EQ_PC__GetCombatAbilityTimer_x                             0x8155B0
#define EQ_PC__GetItemTimerValue_x                                 0x5B3880
#define EQ_PC__HasLoreItem_x                                       0x5ADAA0
#define EQ_PC__AlertInventoryChanged_x                             0x5AA700
#define EQ_PC__GetPcZoneClient_x                                   0x5D43C0
#define EQ_PC__RemoveMyAffect_x                                    0x5B2D90

// EQItemList 
#define EQItemList__EQItemList_x                                   0x507610
#define EQItemList__add_item_x                                     0x507550
#define EQItemList__delete_item_x                                  0x507A10
#define EQItemList__FreeItemList_x                                 0x507910

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A40F0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5BF3E0
#define EQPlayer__dEQPlayer_x                                      0x5C8210
#define EQPlayer__DoAttack_x                                       0x5DA280
#define EQPlayer__EQPlayer_x                                       0x5CA630
#define EQPlayer__SetNameSpriteState_x                             0x5C4EE0
#define EQPlayer__SetNameSpriteTint_x                              0x5C07B0
#define EQPlayer__IsBodyType_j_x                                   0x91C010
#define EQPlayer__IsTargetable_x                                   0x91C8D0
#define EQPlayer__CanSee_x                                         0x91CDF0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5CE9A0
#define EQPlayerManager__GetSpawnByName_x                          0x5CEE00

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x590DE0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x590E20
#define KeypressHandler__ClearCommandStateArray_x                  0x5909C0
#define KeypressHandler__HandleKeyDown_x                           0x58F320
#define KeypressHandler__HandleKeyUp_x                             0x58F640
#define KeypressHandler__SaveKeymapping_x                          0x590A90

// MapViewMap 
#define MapViewMap__Clear_x                                        0x702520
#define MapViewMap__SaveEx_x                                       0x705E00

#define PlayerPointManager__GetAltCurrency_x                       0x82CF80

// StringTable 
#define StringTable__getString_x                                   0x827AA0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B8150

//Doors
#define EQSwitch__UseSwitch_x                                      0x545E70

//IconCache
#define IconCache__GetIcon_x                                       0x69D240

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6940D0
#define CContainerMgr__CloseContainer_x                            0x6948F0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x763D70

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x583F90

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D81C0
#define EQ_Spell__SpellAffects_x                                   0x4D8260
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D8290
#define CharacterZoneClient__CalcAffectChange_x                    0x4487A0
#define CLootWnd__LootAll_x                                        0x6F7E10
//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x74DBB0
#define CTargetWnd__WndNotification_x                              0x7A90B0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7AE770

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D1AF0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x494CE0

