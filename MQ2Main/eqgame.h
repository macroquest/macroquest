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
#define __ExpectedVersionDate                                     "Aug 14 2015"
#define __ExpectedVersionTime                                     "16:59:34"
#define __ActualVersionDate_x                                      0xA81FF8
#define __ActualVersionTime_x                                      0xA82004

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5968C0
#define __MemChecker1_x                                            0x861670
#define __MemChecker2_x                                            0x62F7F0
#define __MemChecker3_x                                            0x62F740
#define __MemChecker4_x                                            0x7E4E90
#define __EncryptPad0_x                                            0xC005D0
#define __EncryptPad1_x                                            0xD87F80
#define __EncryptPad2_x                                            0xC49F18
#define __EncryptPad3_x                                            0xC49B18
#define __EncryptPad4_x                                            0xD63FE8
#define __AC1_x                                                    0x7A2615
#define __AC2_x                                                    0x54BF27
#define __AC3_x                                                    0x560720
#define __AC4_x                                                    0x5673A0
#define __AC5_x                                                    0x5731CE
#define __AC6_x                                                    0x576C89
#define __AC7_x                                                    0x56D86C
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
#define __do_loot_x                                                0x5134E0
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
#define __CastRay_x                                                0x52B020
#define __ConvertItemTags_x                                        0x518160
#define __ExecuteCmd_x                                             0x502C90
#define __EQGetTime_x                                              0x861990
#define __get_melee_range_x                                        0x509930
#define __GetGaugeValueFromEQ_x                                    0x7A1350
#define __GetLabelFromEQ_x                                         0x7A25A0
#define __ToggleMount_x                                            0x6CA2F0
#define __GetXTargetType_x                                         0x920010
#define __LoadFrontEnd_x                                           0x62EEA0
#define __NewUIINI_x                                               0x7A0C60
#define __ProcessGameEvents_x                                      0x56F5D0
#define __ProcessMouseEvent_x                                      0x56ED70
#define CrashDetected_x                                            0x630970
#define wwsCrashReportCheckForUploader_x                           0x7F5FF0
#define DrawNetStatus_x                                            0x5A6340
#define Util__FastTime_x                                           0x8614E0
#define Expansion_HoT_x                                            0xFA9A2C
#define __HelpPath_x                                               0x102D198

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41EF30
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419D90

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C2720
#define AltAdvManager__IsAbilityReady_x                            0x4C2790
#define AltAdvManager__GetAltAbility_x                             0x4C2B50

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4658D0
#define CharacterZoneClient__MakeMeVisible_x                       0x46B300
// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x65E770

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66CD10

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5858C0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x687B80
#define CChatManager__InitContextMenu_x                            0x688700

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D1D20
#define CContextMenu__dCContextMenu_x                              0x8D1F30
#define CContextMenu__AddMenuItem_x                                0x8D1F40
#define CContextMenu__RemoveMenuItem_x                             0x8D2230
#define CContextMenu__RemoveAllMenuItems_x                         0x8D2250
#define CContextMenuManager__AddMenu_x                             0x8BDCA0
#define CContextMenuManager__RemoveMenu_x                          0x8BDFD0
#define CContextMenuManager__PopupMenu_x                           0x8BE420
#define CContextMenuManager__Flush_x                               0x8BDD10
#define CContextMenuManager__GetMenu_x                             0x4153D0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8479B0
#define CChatService__GetFriendName_x                              0x8479C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x68D9A0
#define CChatWindow__Clear_x                                       0x68D560
#define CChatWindow__WndNotification_x                             0x68DED0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C1B70
#define CComboWnd__Draw_x                                          0x8C1D80
#define CComboWnd__GetCurChoice_x                                  0x8C1940
#define CComboWnd__GetListRect_x                                   0x8C2020
#define CComboWnd__GetTextRect_x                                   0x8C1BE0
#define CComboWnd__InsertChoice_x                                  0x8C2090
#define CComboWnd__SetColors_x                                     0x8C18D0
#define CComboWnd__SetChoice_x                                     0x8C1900
#define CComboWnd__GetItemCount_x                                  0x8C1930

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6970D0
#define CContainerWnd__vftable_x                                   0xA8B788

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B0A20
#define CDisplay__GetClickedActor_x                                0x4A95A0
#define CDisplay__GetUserDefinedColor_x                            0x4A7E60
#define CDisplay__GetWorldFilePath_x                               0x4A72B0
#define CDisplay__is3dON_x                                         0x4A6680
#define CDisplay__ReloadUI_x                                       0x4BBEF0
#define CDisplay__WriteTextHD2_x                                   0x4ACDC0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E83C0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D6760
#define CEditWnd__GetCharIndexPt_x                                 0x8D7800
#define CEditWnd__GetDisplayString_x                               0x8D6910
#define CEditWnd__GetHorzOffset_x                                  0x8D6C50
#define CEditWnd__GetLineForPrintableChar_x                        0x8D72C0
#define CEditWnd__GetSelStartPt_x                                  0x8D7AC0
#define CEditWnd__GetSTMLSafeText_x                                0x8D6DF0
#define CEditWnd__PointFromPrintableChar_x                         0x8D73B0
#define CEditWnd__SelectableCharFromPoint_x                        0x8D7530
#define CEditWnd__SetEditable_x                                    0x8D6DC0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x54C670
#define CEverQuest__DoTellWindow_x                                 0x552070
#define CEverQuest__DropHeldItemOnGround_x                         0x55ABA0
#define CEverQuest__dsp_chat_x                                     0x553810
#define CEverQuest__Emote_x                                        0x553A70
#define CEverQuest__EnterZone_x                                    0x567BC0
#define CEverQuest__GetBodyTypeDesc_x                              0x548ED0
#define CEverQuest__GetClassDesc_x                                 0x54EBE0
#define CEverQuest__GetClassThreeLetterCode_x                      0x54F1E0
#define CEverQuest__GetDeityDesc_x                                 0x5497B0
#define CEverQuest__GetLangDesc_x                                  0x549260
#define CEverQuest__GetRaceDesc_x                                  0x54F3A0
#define CEverQuest__InterpretCmd_x                                 0x554350
#define CEverQuest__LeftClickedOnPlayer_x                          0x56BCD0
#define CEverQuest__LMouseUp_x                                     0x56DDC0
#define CEverQuest__RightClickedOnPlayer_x                         0x56C7D0
#define CEverQuest__RMouseUp_x                                     0x56D820
#define CEverQuest__SetGameState_x                                 0x54CD20
#define CEverQuest__UPCNotificationFlush_x                         0x5554F0
#define CEverQuest__IssuePetCommand_x                              0x555050

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A7C20
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A7C80
#define CGaugeWnd__Draw_x                                          0x6A80B0

// CGuild
#define CGuild__FindMemberByName_x                                 0x435D80

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C4CF0

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
#define CListWnd__CListWnd_x                                       0x8AD9C0
#define CListWnd__dCListWnd_x                                      0x8AE9E0
#define CListWnd__AddColumn_x                                      0x8AE980
#define CListWnd__AddColumn1_x                                     0x8AE1F0
#define CListWnd__AddLine_x                                        0x8ADC70
#define CListWnd__AddString_x                                      0x8ADE80
#define CListWnd__CalculateFirstVisibleLine_x                      0x8AAD10
#define CListWnd__CalculateVSBRange_x                              0x8ACE80
#define CListWnd__ClearAllSel_x                                    0x8A9FD0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8AD850
#define CListWnd__Compare_x                                        0x8AB810
#define CListWnd__Draw_x                                           0x8ACA90
#define CListWnd__DrawColumnSeparators_x                           0x8AC920
#define CListWnd__DrawHeader_x                                     0x8AA2E0
#define CListWnd__DrawItem_x                                       0x8ABE50
#define CListWnd__DrawLine_x                                       0x8AC5C0
#define CListWnd__DrawSeparator_x                                  0x8AC9C0
#define CListWnd__EnsureVisible_x                                  0x8AAE70
#define CListWnd__ExtendSel_x                                      0x8ABD60
#define CListWnd__GetColumnMinWidth_x                              0x8A9990
#define CListWnd__GetColumnWidth_x                                 0x8A98B0
#define CListWnd__GetCurSel_x                                      0x8A9090
#define CListWnd__GetItemAtPoint_x                                 0x8AB110
#define CListWnd__GetItemAtPoint1_x                                0x8AB180
#define CListWnd__GetItemData_x                                    0x8A93C0
#define CListWnd__GetItemHeight_x                                  0x8AA970
#define CListWnd__GetItemIcon_x                                    0x8A95A0
#define CListWnd__GetItemRect_x                                    0x8AAF50
#define CListWnd__GetItemText_x                                    0x8A9450
#define CListWnd__GetSelList_x                                     0x8AE0E0
#define CListWnd__GetSeparatorRect_x                               0x8AB730
#define CListWnd__RemoveLine_x                                     0x8AE060
#define CListWnd__SetColors_x                                      0x8A91E0
#define CListWnd__SetColumnJustification_x                         0x8A9C60
#define CListWnd__SetColumnWidth_x                                 0x8A9940
#define CListWnd__SetCurSel_x                                      0x8A90D0
#define CListWnd__SetItemColor_x                                   0x8AD530
#define CListWnd__SetItemData_x                                    0x8AA080
#define CListWnd__SetItemText_x                                    0x8AD370
#define CListWnd__ShiftColumnSeparator_x                           0x8AD200
#define CListWnd__Sort_x                                           0x8AEAE0
#define CListWnd__ToggleSel_x                                      0x8A9F50

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70A1A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72B3C0
#define CMerchantWnd__RequestBuyItem_x                             0x732230
#define CMerchantWnd__RequestSellItem_x                            0x732CA0
#define CMerchantWnd__SelectRecoverySlot_x                         0x72B670
#define CMerchantWnd__SelectBuySellSlot_x                          0x72A8D0
#define CMerchantWnd__ActualSelect_x                               0x72F150

// CObfuscator
#define CObfuscator__doit_x                                        0x827C60

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8CCBE0
#define CSidlManager__CreateLabel_x                                0x793D00

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x655AA0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x6559D0
#define CSidlScreenWnd__ConvertToRes_x                             0x8E82A0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8C47C0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C5CB0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C5D60
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C5230
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8C4170
#define CSidlScreenWnd__EnableIniStorage_x                         0x8C38D0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8C4360
#define CSidlScreenWnd__Init1_x                                    0x8C5990
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C4870
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8C3A90
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C5480
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C33A0
#define CSidlScreenWnd__StoreIniVis_x                              0x8C3860
#define CSidlScreenWnd__WndNotification_x                          0x8C5710
#define CSidlScreenWnd__GetChildItem_x                             0x8C39A0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B6F60

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F1050
#define CSkillMgr__GetSkillCap_x                                   0x5F11F0
#define CSkillMgr__GetNameToken_x                                  0x5F0CC0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E7570
#define CSliderWnd__SetValue_x                                     0x8E7740
#define CSliderWnd__SetNumTicks_x                                  0x8E7EC0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79B9C0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8E1F60
#define CStmlWnd__CalculateHSBRange_x                              0x8DA490
#define CStmlWnd__CalculateVSBRange_x                              0x8DA520
#define CStmlWnd__CanBreakAtCharacter_x                            0x8DA6A0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8DAF80
#define CStmlWnd__ForceParseNow_x                                  0x8E28B0
#define CStmlWnd__GetNextTagPiece_x                                0x8DAE80
#define CStmlWnd__GetSTMLText_x                                    0x68CE00
#define CStmlWnd__GetVisibleText_x                                 0x8DB9D0
#define CStmlWnd__InitializeWindowVariables_x                      0x8DDD60
#define CStmlWnd__MakeStmlColorTag_x                               0x8D9790
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D97F0
#define CStmlWnd__SetSTMLText_x                                    0x8DF5C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E1C00
#define CStmlWnd__UpdateHistoryString_x                            0x8DC910

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E9AA0
#define CTabWnd__DrawCurrentPage_x                                 0x8E9310
#define CTabWnd__DrawTab_x                                         0x8E90D0
#define CTabWnd__GetCurrentPage_x                                  0x8E96E0
#define CTabWnd__GetPageInnerRect_x                                0x8E8DC0
#define CTabWnd__GetTabInnerRect_x                                 0x8E8FC0
#define CTabWnd__GetTabRect_x                                      0x8E8E90
#define CTabWnd__InsertPage_x                                      0x8E9D90
#define CTabWnd__SetPage_x                                         0x8E9710
#define CTabWnd__SetPageRect_x                                     0x8E99E0
#define CTabWnd__UpdatePage_x                                      0x8E9D30

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431B80

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C1540

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8EEC40

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A71E0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4022B0
#define CXStr__CXStr1_x                                            0x7D2110
#define CXStr__CXStr3_x                                            0x85E570
#define CXStr__dCXStr_x                                            0x6A7B00
#define CXStr__operator_equal_x                                    0x85E6E0
#define CXStr__operator_equal1_x                                   0x85E730
#define CXStr__operator_plus_equal1_x                              0x85F810

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B61C0
#define CXWnd__Center_x                                            0x8BC310
#define CXWnd__ClrFocus_x                                          0x8B5D80
#define CXWnd__DoAllDrawing_x                                      0x8BBF60
#define CXWnd__DrawChildren_x                                      0x8BC100
#define CXWnd__DrawColoredRect_x                                   0x8B6540
#define CXWnd__DrawTooltip_x                                       0x8B67F0
#define CXWnd__DrawTooltipAtPoint_x                                0x8BAEF0
#define CXWnd__GetBorderFrame_x                                    0x8B6C50
#define CXWnd__GetChildWndAt_x                                     0x8BCCC0
#define CXWnd__GetClientClipRect_x                                 0x8B6A10
#define CXWnd__GetScreenClipRect_x                                 0x8BB5F0
#define CXWnd__GetScreenRect_x                                     0x8B6E00
#define CXWnd__GetTooltipRect_x                                    0x8B6680
#define CXWnd__GetWindowTextA_x                                    0x423000
#define CXWnd__IsActive_x                                          0x8B17C0
#define CXWnd__IsDescendantOf_x                                    0x8B6BA0
#define CXWnd__IsReallyVisible_x                                   0x8B9EE0
#define CXWnd__IsType_x                                            0x8EB460
#define CXWnd__Move_x                                              0x8B95C0
#define CXWnd__Move1_x                                             0x8BBC10
#define CXWnd__ProcessTransition_x                                 0x8B6160
#define CXWnd__Refade_x                                            0x8B6160
#define CXWnd__Resize_x                                            0x8B6EC0
#define CXWnd__Right_x                                             0x8BB3F0
#define CXWnd__SetFocus_x                                          0x8B8730
#define CXWnd__SetFont_x                                           0x8B5DD0
#define CXWnd__SetKeyTooltip_x                                     0x8B7130
#define CXWnd__SetMouseOver_x                                      0x8BB910
#define CXWnd__StartFade_x                                         0x8B6210
#define CXWnd__GetChildItem_x                                      0x8BB850

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B30D0
#define CXWndManager__DrawWindows_x                                0x8B2D20
#define CXWndManager__GetKeyboardFlags_x                           0x8B1330
#define CXWndManager__HandleKeyboardMsg_x                          0x8B1C60
#define CXWndManager__RemoveWnd_x                                  0x8B1950

// CDBStr
#define CDBStr__GetString_x                                        0x4A4C40

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44F8D0
#define EQ_Character__Cur_HP_x                                     0x464FA0
#define EQ_Character__GetAACastingTimeModifier_x                   0x447290
#define EQ_Character__GetCharInfo2_x                               0x8323F0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F3E0
#define EQ_Character__GetFocusRangeModifier_x                      0x43F5C0
#define EQ_Character__Max_Endurance_x                              0x5B8810
#define EQ_Character__Max_HP_x                                     0x45AC10
#define EQ_Character__Max_Mana_x                                   0x5B8640
#define EQ_Character__doCombatAbility_x                            0x5B5C30
#define EQ_Character__UseSkill_x                                   0x470500
#define EQ_Character__GetConLevel_x                                0x5AA9F0
#define EQ_Character__IsExpansionFlag_x                            0x422540
#define EQ_Character__TotalEffect_x                                0x44C610

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x58B0F0
#define EQ_Item__CreateItemTagString_x                             0x8118D0
#define EQ_Item__IsStackable_x                                     0x805C90
#define EQ_Item__GetImageNum_x                                     0x8089C0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C4840
#define EQ_LoadingS__Array_x                                       0xBAC858

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5B9FB0
#define EQ_PC__GetAltAbilityIndex_x                                0x81A9C0
#define EQ_PC__GetCombatAbility_x                                  0x81AA50
#define EQ_PC__GetCombatAbilityTimer_x                             0x8159B0
#define EQ_PC__GetItemTimerValue_x                                 0x5B3A20
#define EQ_PC__HasLoreItem_x                                       0x5ADD70
#define EQ_PC__AlertInventoryChanged_x                             0x5AA9C0
#define EQ_PC__GetPcZoneClient_x                                   0x5D45B0
#define EQ_PC__RemoveMyAffect_x									   0x5B2F30

// EQItemList 
#define EQItemList__EQItemList_x                                   0x507990
#define EQItemList__add_item_x                                     0x5078D0
#define EQItemList__delete_item_x                                  0x507D90
#define EQItemList__FreeItemList_x                                 0x507C90

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A3F40

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5BF540
#define EQPlayer__dEQPlayer_x                                      0x5C83A0
#define EQPlayer__DoAttack_x                                       0x5DA4C0
#define EQPlayer__EQPlayer_x                                       0x5CA7C0
#define EQPlayer__SetNameSpriteState_x                             0x5C5080
#define EQPlayer__SetNameSpriteTint_x                              0x5C0950
#define EQPlayer__IsBodyType_j_x                                   0x91C2A0
#define EQPlayer__IsTargetable_x                                   0x91CB60
#define EQPlayer__CanSee_x                                         0x91D080

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5CEAC0
#define EQPlayerManager__GetSpawnByName_x                          0x5CEF20

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5911E0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x591220
#define KeypressHandler__ClearCommandStateArray_x                  0x590DC0
#define KeypressHandler__HandleKeyDown_x                           0x58F720
#define KeypressHandler__HandleKeyUp_x                             0x58FA40
#define KeypressHandler__SaveKeymapping_x                          0x590E90

// MapViewMap 
#define MapViewMap__Clear_x                                        0x702580
#define MapViewMap__SaveEx_x                                       0x705E60

#define PlayerPointManager__GetAltCurrency_x                       0x82D380

// StringTable 
#define StringTable__getString_x                                   0x827F00

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B82C0

//Doors
#define EQSwitch__UseSwitch_x                                      0x546290

//IconCache
#define IconCache__GetIcon_x                                       0x69D530

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x694400
#define CContainerMgr__CloseContainer_x                            0x694C20

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x763EB0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x584380

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D8010
#define EQ_Spell__SpellAffects_x                                   0x4D80B0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D80E0
#define CharacterZoneClient__CalcAffectChange_x                    0x448680
#define CLootWnd__LootAll_x                                        0x6F7E60

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7A9900
#define CTargetWnd__WndNotification_x                              0x7A93F0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7AEAE0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D1930

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x494B10
