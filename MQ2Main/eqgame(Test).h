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
#define __ExpectedVersionDate                                     "Aug 12 2015"
#define __ExpectedVersionTime                                     "13:09:46"
#define __ActualVersionDate_x                                      0xA82040
#define __ActualVersionTime_x                                      0xA8204C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5969F0
#define __MemChecker1_x                                            0x861600
#define __MemChecker2_x                                            0x62F6A0
#define __MemChecker3_x                                            0x62F5F0
#define __MemChecker4_x                                            0x7E4B70
#define __EncryptPad0_x                                            0xC005D0
#define __EncryptPad1_x                                            0xD87F80
#define __EncryptPad2_x                                            0xC49F18
#define __EncryptPad3_x                                            0xC49B18
#define __EncryptPad4_x                                            0xD63FE8
#define __AC1_x                                                    0x7A2325
#define __AC2_x                                                    0x54BFF7
#define __AC3_x                                                    0x5607F0
#define __AC4_x                                                    0x567470
#define __AC5_x                                                    0x5732AE
#define __AC6_x                                                    0x576D59
#define __AC7_x                                                    0x56D94C
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
#define __do_loot_x                                                0x5136B0
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
#define pinstMercenaryStats_x                                      0x1141E70
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
#define __CastRay_x                                                0x52B1E0
#define __ConvertItemTags_x                                        0x518330
#define __ExecuteCmd_x                                             0x502E60
#define __EQGetTime_x                                              0x861920
#define __get_melee_range_x                                        0x509B00
#define __GetGaugeValueFromEQ_x                                    0x7A1060
#define __GetLabelFromEQ_x                                         0x7A22B0
#define __ToggleMount_x                                            0x6CA200
#define __GetXTargetType_x                                         0x91FF10
#define __LoadFrontEnd_x                                           0x62ED50
#define __NewUIINI_x                                               0x7A0970
#define __ProcessGameEvents_x                                      0x56F6B0
#define __ProcessMouseEvent_x                                      0x56EE50
#define CrashDetected_x                                            0x630820
#define wwsCrashReportCheckForUploader_x                           0x7F61F0
#define DrawNetStatus_x                                            0x5A63F0
#define Util__FastTime_x                                           0x861470
#define Expansion_HoT_x                                            0xFA9A24
#define __HelpPath_x                                               0x102D190
//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41F030
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419E80

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C28C0
#define AltAdvManager__IsAbilityReady_x                            0x4C2930
#define AltAdvManager__GetAltAbility_x                             0x4C2CF0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x465910
#define CharacterZoneClient__MakeMeVisible_x                       0x46B340

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x65E770

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66C350

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x585A20

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x687A80
#define CChatManager__InitContextMenu_x                            0x688600

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D1C40
#define CContextMenu__AddMenuItem_x                                0x8D1E60
#define CContextMenu__dCContextMenu_x                              0x8D1E50
#define CContextMenu__RemoveMenuItem_x                             0x8D2150
#define CContextMenu__RemoveAllMenuItems_x                         0x8D2170
#define CContextMenuManager__AddMenu_x                             0x8BDC20
#define CContextMenuManager__RemoveMenu_x                          0x8BDF50
#define CContextMenuManager__PopupMenu_x                           0x8BE3A0
#define CContextMenuManager__Flush_x                               0x8BDC90
#define CContextMenuManager__GetMenu_x                             0x4154D0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x847A30
#define CChatService__GetFriendName_x                              0x847A40

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x68D8A0
#define CChatWindow__Clear_x                                       0x68D460
#define CChatWindow__WndNotification_x                             0x68DDD0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C1AE0
#define CComboWnd__Draw_x                                          0x8C1CF0
#define CComboWnd__GetCurChoice_x                                  0x8C18B0
#define CComboWnd__GetListRect_x                                   0x8C1F90
#define CComboWnd__GetTextRect_x                                   0x8C1B50
#define CComboWnd__InsertChoice_x                                  0x8C2000
#define CComboWnd__SetColors_x                                     0x8C1840
#define CComboWnd__SetChoice_x                                     0x8C1870
#define CComboWnd__GetItemCount_x                                  0x8C18A0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x696F90
#define CContainerWnd__vftable_x                                   0xA8B7D0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B0BB0
#define CDisplay__GetClickedActor_x                                0x4A9730
#define CDisplay__GetUserDefinedColor_x                            0x4A7FF0
#define CDisplay__GetWorldFilePath_x                               0x4A7440
#define CDisplay__is3dON_x                                         0x4A6810
#define CDisplay__ReloadUI_x                                       0x4BC080
#define CDisplay__WriteTextHD2_x                                   0x4ACF50

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E8240

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D65F0
#define CEditWnd__GetCharIndexPt_x                                 0x8D7680
#define CEditWnd__GetDisplayString_x                               0x8D67A0
#define CEditWnd__GetHorzOffset_x                                  0x8D6AE0
#define CEditWnd__GetLineForPrintableChar_x                        0x8D7150
#define CEditWnd__GetSelStartPt_x                                  0x8D7930
#define CEditWnd__GetSTMLSafeText_x                                0x8D6C80
#define CEditWnd__PointFromPrintableChar_x                         0x8D7240
#define CEditWnd__SelectableCharFromPoint_x                        0x8D73C0
#define CEditWnd__SetEditable_x                                    0x8D6C50

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x54C740
#define CEverQuest__DoTellWindow_x                                 0x552140
#define CEverQuest__DropHeldItemOnGround_x                         0x55AC70
#define CEverQuest__dsp_chat_x                                     0x5538E0
#define CEverQuest__Emote_x                                        0x553B40
#define CEverQuest__EnterZone_x                                    0x567C90
#define CEverQuest__GetBodyTypeDesc_x                              0x548FA0
#define CEverQuest__GetClassDesc_x                                 0x54ECB0
#define CEverQuest__GetClassThreeLetterCode_x                      0x54F2B0
#define CEverQuest__GetDeityDesc_x                                 0x549880
#define CEverQuest__GetLangDesc_x                                  0x549330
#define CEverQuest__GetRaceDesc_x                                  0x54F470
#define CEverQuest__InterpretCmd_x                                 0x554420
#define CEverQuest__LeftClickedOnPlayer_x                          0x56BDB0
#define CEverQuest__LMouseUp_x                                     0x56DEA0
#define CEverQuest__RightClickedOnPlayer_x                         0x56C8B0
#define CEverQuest__RMouseUp_x                                     0x56D900
#define CEverQuest__SetGameState_x                                 0x54CDF0
#define CEverQuest__UPCNotificationFlush_x                         0x5555C0
#define CEverQuest__IssuePetCommand_x                              0x555120

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A7B40
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A7BA0
#define CGaugeWnd__Draw_x                                          0x6A7FD0

// CGuild
#define CGuild__FindMemberByName_x                                 0x435E10

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C4C30

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D2A30
#define CInvSlotMgr__MoveItem_x                                    0x6D3960
#define CInvSlotMgr__SelectSlot_x                                  0x6D2AE0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D1EC0
#define CInvSlot__SliderComplete_x                                 0x6CF880
#define CInvSlot__GetItemBase_x                                    0x6CED00

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D4B30

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79D9D0
#define CItemDisplayWnd__UpdateStrings_x                           0x6D5E60

// CLabel 
#define CLabel__Draw_x                                             0x6F0C30

// CListWnd 
#define CListWnd__CListWnd_x                                       0x8AD9C0
#define CListWnd__dCListWnd_x                                      0x8AE9E0
#define CListWnd__AddColumn_x                                      0x8AE980
#define CListWnd__AddColumn1_x                                     0x8AE1F0
#define CListWnd__AddLine_x                                        0x8ADC70
#define CListWnd__AddString_x                                      0x8ADE80
#define CListWnd__CalculateFirstVisibleLine_x                      0x8AAD10
#define CListWnd__CalculateVSBRange_x                              0x8ACE80
#define CListWnd__ClearAllSel_x                                    0x8A9FC0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8AD850
#define CListWnd__Compare_x                                        0x8AB800
#define CListWnd__Draw_x                                           0x8ACA90
#define CListWnd__DrawColumnSeparators_x                           0x8AC920
#define CListWnd__DrawHeader_x                                     0x8AA2D0
#define CListWnd__DrawItem_x                                       0x8ABE50
#define CListWnd__DrawLine_x                                       0x8AC5C0
#define CListWnd__DrawSeparator_x                                  0x8AC9C0
#define CListWnd__EnsureVisible_x                                  0x8AAE70
#define CListWnd__ExtendSel_x                                      0x8ABD60
#define CListWnd__GetColumnMinWidth_x                              0x8A9980
#define CListWnd__GetColumnWidth_x                                 0x8A98A0
#define CListWnd__GetCurSel_x                                      0x8A9080
#define CListWnd__GetItemAtPoint_x                                 0x8AB100
#define CListWnd__GetItemAtPoint1_x                                0x8AB170
#define CListWnd__GetItemData_x                                    0x8A93B0
#define CListWnd__GetItemHeight_x                                  0x8AA960
#define CListWnd__GetItemIcon_x                                    0x8A9590
#define CListWnd__GetItemRect_x                                    0x8AAF40
#define CListWnd__GetItemText_x                                    0x8A9440
#define CListWnd__GetSelList_x                                     0x8AE0E0
#define CListWnd__GetSeparatorRect_x                               0x8AB720
#define CListWnd__RemoveLine_x                                     0x8AE060
#define CListWnd__SetColors_x                                      0x8A91D0
#define CListWnd__SetColumnJustification_x                         0x8A9C50
#define CListWnd__SetColumnWidth_x                                 0x8A9930
#define CListWnd__SetCurSel_x                                      0x8A90C0
#define CListWnd__SetItemColor_x                                   0x8AD530
#define CListWnd__SetItemData_x                                    0x8AA070
#define CListWnd__SetItemText_x                                    0x8AD370
#define CListWnd__ShiftColumnSeparator_x                           0x8AD200
#define CListWnd__Sort_x                                           0x8AEAE0
#define CListWnd__ToggleSel_x                                      0x8A9F40

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70A260

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72B360
#define CMerchantWnd__RequestBuyItem_x                             0x732180
#define CMerchantWnd__RequestSellItem_x                            0x732BD0
#define CMerchantWnd__SelectRecoverySlot_x                         0x72B610
#define CMerchantWnd__SelectBuySellSlot_x                          0x72A870
#define CMerchantWnd__ActualSelect_x                               0x72F0B0

// CObfuscator
#define CObfuscator__doit_x                                        0x827BA0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8CCB10
#define CSidlManager__CreateLabel_x                                0x7939C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x655A90
#define CSidlScreenWnd__CalculateVSBRange_x                        0x6559C0
#define CSidlScreenWnd__ConvertToRes_x                             0x8E8120
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8C4720
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C5C10
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C5CC0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C5190
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8C40D0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8C3840
#define CSidlScreenWnd__GetSidlPiece_x                             0x8C42C0
#define CSidlScreenWnd__Init1_x                                    0x8C58F0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C47D0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8C3A00
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C53E0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C3310
#define CSidlScreenWnd__StoreIniVis_x                              0x8C37D0
#define CSidlScreenWnd__WndNotification_x                          0x8C5670
#define CSidlScreenWnd__GetChildItem_x                             0x8C3910
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B6F40

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F0D50
#define CSkillMgr__GetSkillCap_x                                   0x5F0EF0
#define CSkillMgr__GetNameToken_x                                  0x5F09C0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E73F0
#define CSliderWnd__SetValue_x                                     0x8E75C0
#define CSliderWnd__SetNumTicks_x                                  0x8E7D40

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79B680

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8E1D80
#define CStmlWnd__CalculateHSBRange_x                              0x8DA2D0
#define CStmlWnd__CalculateVSBRange_x                              0x8DA350
#define CStmlWnd__CanBreakAtCharacter_x                            0x8DA4D0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8DADB0
#define CStmlWnd__ForceParseNow_x                                  0x8E2740
#define CStmlWnd__GetNextTagPiece_x                                0x8DACB0
#define CStmlWnd__GetSTMLText_x                                    0x68CD00
#define CStmlWnd__GetVisibleText_x                                 0x8DB800
#define CStmlWnd__InitializeWindowVariables_x                      0x8DDB80
#define CStmlWnd__MakeStmlColorTag_x                               0x8D95D0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D9630
#define CStmlWnd__SetSTMLText_x                                    0x8DF3E0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E1A20
#define CStmlWnd__UpdateHistoryString_x                            0x8DC740

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E99E0
#define CTabWnd__DrawCurrentPage_x                                 0x8E9250
#define CTabWnd__DrawTab_x                                         0x8E9010
#define CTabWnd__GetCurrentPage_x                                  0x8E9620
#define CTabWnd__GetPageInnerRect_x                                0x8E8D00
#define CTabWnd__GetTabInnerRect_x                                 0x8E8F00
#define CTabWnd__GetTabRect_x                                      0x8E8DD0
#define CTabWnd__InsertPage_x                                      0x8E9CD0
#define CTabWnd__SetPage_x                                         0x8E9650
#define CTabWnd__SetPageRect_x                                     0x8E9920
#define CTabWnd__UpdatePage_x                                      0x8E9C70

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431B50

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C14B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8EEB70

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A7110

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x592FF0
#define CXStr__CXStr1_x                                            0x73D330
#define CXStr__CXStr3_x                                            0x85E500
#define CXStr__dCXStr_x                                            0x73D340
#define CXStr__operator_equal_x                                    0x85E670
#define CXStr__operator_equal1_x                                   0x85E6C0
#define CXStr__operator_plus_equal1_x                              0x85F7A0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B61A0
#define CXWnd__Center_x                                            0x8BC2A0
#define CXWnd__ClrFocus_x                                          0x8B5D70
#define CXWnd__DoAllDrawing_x                                      0x8BBEF0
#define CXWnd__DrawChildren_x                                      0x8BC090
#define CXWnd__DrawColoredRect_x                                   0x8B6540
#define CXWnd__DrawTooltip_x                                       0x8B67E0
#define CXWnd__DrawTooltipAtPoint_x                                0x8BAE90
#define CXWnd__GetBorderFrame_x                                    0x8B6C30
#define CXWnd__GetChildWndAt_x                                     0x8BCC50
#define CXWnd__GetClientClipRect_x                                 0x8B69F0
#define CXWnd__GetScreenClipRect_x                                 0x8BB590
#define CXWnd__GetScreenRect_x                                     0x8B6DE0
#define CXWnd__GetTooltipRect_x                                    0x8B6670
#define CXWnd__GetWindowTextA_x                                    0x422F90
#define CXWnd__IsActive_x                                          0x8B17E0
#define CXWnd__IsDescendantOf_x                                    0x8B6B80
#define CXWnd__IsReallyVisible_x                                   0x8B9ED0
#define CXWnd__IsType_x                                            0x8EB390
#define CXWnd__Move_x                                              0x8B95E0
#define CXWnd__Move1_x                                             0x8BBBB0
#define CXWnd__ProcessTransition_x                                 0x8B6150
#define CXWnd__Refade_x                                            0x8B5F20
#define CXWnd__Resize_x                                            0x8B6EA0
#define CXWnd__Right_x                                             0x8BB390
#define CXWnd__SetFocus_x                                          0x8B8760
#define CXWnd__SetFont_x                                           0x8B5DC0
#define CXWnd__SetKeyTooltip_x                                     0x8B7110
#define CXWnd__SetMouseOver_x                                      0x8BB8D0
#define CXWnd__StartFade_x                                         0x8B61F0
#define CXWnd__GetChildItem_x                                      0x8BB810

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B30E0
#define CXWndManager__DrawWindows_x                                0x8B2D30
#define CXWndManager__GetKeyboardFlags_x                           0x8B1350
#define CXWndManager__HandleKeyboardMsg_x                          0x8B1C80
#define CXWndManager__RemoveWnd_x                                  0x8B1970

// CDBStr
#define CDBStr__GetString_x                                        0x4A4D50

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44F940
#define EQ_Character__Cur_HP_x                                     0x464FE0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4472D0
#define EQ_Character__GetCharInfo2_x                               0x8323B0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F430
#define EQ_Character__GetFocusRangeModifier_x                      0x43F610
#define EQ_Character__Max_Endurance_x                              0x5B8640
#define EQ_Character__Max_HP_x                                     0x45AC50
#define EQ_Character__Max_Mana_x                                   0x5B8470
#define EQ_Character__doCombatAbility_x                            0x5B5A60
#define EQ_Character__UseSkill_x                                   0x470540
#define EQ_Character__GetConLevel_x                                0x5AAAD0
#define EQ_Character__IsExpansionFlag_x                            0x4224E0
#define EQ_Character__TotalEffect_x                                0x44C670

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x58B1E0
#define EQ_Item__CreateItemTagString_x                             0x8118B0
#define EQ_Item__IsStackable_x                                     0x805E20
#define EQ_Item__GetImageNum_x                                     0x808B10

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C49B0
#define EQ_LoadingS__Array_x                                       0xBAC858

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5B9DE0
#define EQ_PC__GetAltAbilityIndex_x                                0x81A910
#define EQ_PC__GetCombatAbility_x                                  0x81A9A0
#define EQ_PC__GetCombatAbilityTimer_x                             0x815920
#define EQ_PC__GetItemTimerValue_x                                 0x5B3850
#define EQ_PC__HasLoreItem_x                                       0x5ADE30
#define EQ_PC__AlertInventoryChanged_x                             0x5AAAA0
#define EQ_PC__GetPcZoneClient_x                                   0x5D4360
#define EQ_PC__RemoveMyAffect_x                                    0x5B2D60

// EQItemList 
#define EQItemList__EQItemList_x                                   0x507B60
#define EQItemList__add_item_x                                     0x507AA0
#define EQItemList__delete_item_x                                  0x507F60
#define EQItemList__FreeItemList_x                                 0x507E60

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A3FF0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5BF380
#define EQPlayer__dEQPlayer_x                                      0x5C81E0
#define EQPlayer__DoAttack_x                                       0x5DA270
#define EQPlayer__EQPlayer_x                                       0x5CA600
#define EQPlayer__SetNameSpriteState_x                             0x5C4EC0
#define EQPlayer__SetNameSpriteTint_x                              0x5C0790
#define EQPlayer__IsBodyType_j_x                                   0x91C0E0
#define EQPlayer__IsTargetable_x                                   0x91C9A0
#define EQPlayer__CanSee_x                                         0x91CEC0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5CE910
#define EQPlayerManager__GetSpawnByName_x                          0x5CED70

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x591320
#define KeypressHandler__AttachKeyToEqCommand_x                    0x591360
#define KeypressHandler__ClearCommandStateArray_x                  0x590F00
#define KeypressHandler__HandleKeyDown_x                           0x58F860
#define KeypressHandler__HandleKeyUp_x                             0x58FB80
#define KeypressHandler__SaveKeymapping_x                          0x590FD0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x702640
#define MapViewMap__SaveEx_x                                       0x705F20

#define PlayerPointManager__GetAltCurrency_x                       0x82D370

// StringTable 
#define StringTable__getString_x                                   0x827E40

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B80F0

//Doors
#define EQSwitch__UseSwitch_x                                      0x546400

//IconCache
#define IconCache__GetIcon_x                                       0x69D410

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6942C0
#define CContainerMgr__CloseContainer_x                            0x694AE0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x763C70

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5844D0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D81C0
#define EQ_Spell__SpellAffects_x                                   0x4D8260
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D8290
#define CharacterZoneClient__CalcAffectChange_x                    0x4486C0
#define CLootWnd__LootAll_x                                        0x6F7F70
//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x74DB50
#define CTargetWnd__WndNotification_x                              0x7A9160

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7AE840

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D1A80

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x494C70
