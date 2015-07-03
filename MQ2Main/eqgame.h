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
#define __ExpectedVersionDate                                     "Jun 29 2015"
#define __ExpectedVersionTime                                     "17:35:38"
#define __ActualVersionDate_x                                      0xA7FF38
#define __ActualVersionTime_x                                      0xA7FF44

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x594780
#define __MemChecker1_x                                            0x85E960
#define __MemChecker2_x                                            0x62D290
#define __MemChecker3_x                                            0x62D1E0
#define __MemChecker4_x                                            0x7E2500
#define __EncryptPad0_x                                            0xBFE5A0
#define __EncryptPad1_x                                            0xD85F18
#define __EncryptPad2_x                                            0xC47EE8
#define __EncryptPad3_x                                            0xC47AE8
#define __EncryptPad4_x                                            0xD61F80
#define __AC1_x                                                    0x79F7C5
#define __AC2_x                                                    0x54A697
#define __AC3_x                                                    0x55EE90
#define __AC4_x                                                    0x565250
#define __AC5_x                                                    0x57106E
#define __AC6_x                                                    0x574B19
#define __AC7_x                                                    0x56B71C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x1138000
#define DI8__Keyboard_x                                            0x1138004
#define DI8__Mouse_x                                               0x1138008
#define __AltTimerReady_x                                          0xF97971
#define __Attack_x                                                 0x102AB8F
#define __Autofire_x                                               0x102AB90
#define __BindList_x                                               0xBC0818
#define __bCommandEnabled_x                                        0xF95A80
#define __Clicks_x                                                 0xFA66E0
#define __CommandList_x                                            0xBC4B70
#define __CurrentMapLabel_x                                        0x113DA58
#define __CurrentSocial_x                                          0xB7BE7C
#define __DoAbilityList_x                                          0xFDCE44
#define __do_loot_x                                                0x511E20
#define __DrawHandler_x                                            0x17A2664
#define __GroupCount_x                                             0xF9704A

#define __Guilds_x                                                 0xF9CC60
#define __gWorld_x                                                 0xF99504
#define __HotkeyPage_x                                             0x1023844
#define __HWnd_x                                                   0x102FF08
#define __InChatMode_x                                             0xFA660C
#define __LastTell_x                                               0xFA854C
#define __LMouseHeldTime_x                                         0xFA674C
#define __Mouse_x                                                  0x113800C
#define __MouseLook_x                                              0xFA66A6
#define __MouseEventTime_x                                         0x102B394
#define __gpbCommandEvent_x                                        0xF995CC
#define __NetStatusToggle_x                                        0xFA66A9
#define __PCNames_x                                                0xFA7B6C
#define __RangeAttackReady_x                                       0xFA7830
#define __RMouseHeldTime_x                                         0xFA6748
#define __RunWalkState_x                                           0xFA6610
#define __ScreenMode_x                                             0xEE58B8
#define __ScreenX_x                                                0xFA65C4
#define __ScreenY_x                                                0xFA65C0
#define __ScreenXMax_x                                             0xFA65C8
#define __ScreenYMax_x                                             0xFA65CC
#define __ServerHost_x                                             0xF96F94
#define __ServerName_x                                             0xFDCE04
#define __ShiftKeyDown_x                                           0xFA6CB4
#define __ShowNames_x                                              0xFA7A04
#define __Socials_x                                                0xFDCF04
#define __SubscriptionType_x                                       0x1169DE8
#define __TargetAggroHolder_x                                      0x113FC94
#define __GroupAggro_x                                             0x113FCD4
#define __LoginName_x                                              0x102EAE0
#define __Inviter_x                                                0x102AB0C


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF995F0
#define instEQZoneInfo_x                                           0xFA689C
#define instKeypressHandler_x                                      0x102B378
#define pinstActiveBanker_x                                        0xF995A8
#define pinstActiveCorpse_x                                        0xF995AC
#define pinstActiveGMaster_x                                       0xF995B0
#define pinstActiveMerchant_x                                      0xF995A4
#define pinstAggroInfo_x                                           0xDA9D38
#define pinstAltAdvManager_x                                       0xEE69A8
#define pinstAuraMgr_x                                             0xDB3C00
#define pinstBandageTarget_x                                       0xF99590
#define pinstCamActor_x                                            0xEE62B0
#define pinstCDBStr_x                                              0xEE584C
#define pinstCDisplay_x                                            0xF995B8
#define pinstCEverQuest_x                                          0x1138180
#define pinstCharData_x                                            0xF99574
#define pinstCharSpawn_x                                           0xF9959C
#define pinstControlledMissile_x                                   0xF99570
#define pinstControlledPlayer_x                                    0xF9959C
#define pinstCSidlManager_x                                        0x17A1A9C
#define pinstCXWndManager_x                                        0x17A1A94
#define instDynamicZone_x                                          0xFA6458
#define pinstDZMember_x                                            0xFA6568
#define pinstDZTimerInfo_x                                         0xFA656C
#define pinstEQItemList_x                                          0xF95CD0
#define instEQMisc_x                                               0xB9CAC0
#define pinstEQSoundManager_x                                      0xEE6E18
#define instExpeditionLeader_x                                     0xFA64A2
#define instExpeditionName_x                                       0xFA64E2
#define pinstGroup_x                                               0xF97046
#define pinstImeManager_x                                          0x17A1AA0
#define pinstLocalPlayer_x                                         0xF99588
#define pinstMercenaryData_x                                       0x102B9C8
#define pinstMercAltAbilities_x                                    0xEE6D34
#define pinstModelPlayer_x                                         0xF995B4
#define pinstPCData_x                                              0xF99574
#define pinstSkillMgr_x                                            0x102C800
#define pinstSpawnManager_x                                        0x102C0E8
#define pinstSpellManager_x                                        0x102C948
#define pinstSpellSets_x                                           0x10238A8
#define pinstStringTable_x                                         0xF9951C
#define pinstSwitchManager_x                                       0xF96BD8
#define pinstTarget_x                                              0xF995A0
#define pinstTargetObject_x                                        0xF99578
#define pinstTargetSwitch_x                                        0xF9957C
#define pinstTaskMember_x                                          0xEE5798
#define pinstTrackTarget_x                                         0xF99594
#define pinstTradeTarget_x                                         0xF99584
#define instTributeActive_x                                        0xB9CAE5
#define pinstViewActor_x                                           0xEE62AC
#define pinstWorldData_x                                           0xF99558


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xDAA218
#define pinstCAudioTriggersWindow_x                                0xDAA0A8
#define pinstCCharacterSelect_x                                    0xEE614C
#define pinstCFacePick_x                                           0xEE5EFC
#define pinstCNoteWnd_x                                            0xEE6104
#define pinstCBookWnd_x                                            0xEE610C
#define pinstCPetInfoWnd_x                                         0xEE6110
#define pinstCTrainWnd_x                                           0xEE6114
#define pinstCSkillsWnd_x                                          0xEE6118
#define pinstCSkillsSelectWnd_x                                    0xEE611C
#define pinstCCombatSkillSelectWnd_x                               0xEE6120
#define pinstCFriendsWnd_x                                         0xEE6124
#define pinstCAuraWnd_x                                            0xEE6128
#define pinstCRespawnWnd_x                                         0xEE612C
#define pinstCBandolierWnd_x                                       0xEE6130
#define pinstCPotionBeltWnd_x                                      0xEE6134
#define pinstCAAWnd_x                                              0xEE6138
#define pinstCGroupSearchFiltersWnd_x                              0xEE613C
#define pinstCLoadskinWnd_x                                        0xEE6140
#define pinstCAlarmWnd_x                                           0xEE6144
#define pinstCMusicPlayerWnd_x                                     0xEE6148
#define pinstCMailWnd_x                                            0xEE6150
#define pinstCMailCompositionWnd_x                                 0xEE6154
#define pinstCMailAddressBookWnd_x                                 0xEE6158
#define pinstCRaidWnd_x                                            0xEE6160
#define pinstCRaidOptionsWnd_x                                     0xEE6164
#define pinstCBreathWnd_x                                          0xEE6168
#define pinstCMapViewWnd_x                                         0xEE616C
#define pinstCMapToolbarWnd_x                                      0xEE6170
#define pinstCEditLabelWnd_x                                       0xEE6174
#define pinstCTargetWnd_x                                          0xEE6178
#define pinstCColorPickerWnd_x                                     0xEE617C
#define pinstCPlayerWnd_x                                          0xEE6180
#define pinstCOptionsWnd_x                                         0xEE6184
#define pinstCBuffWindowNORMAL_x                                   0xEE6188
#define pinstCBuffWindowSHORT_x                                    0xEE618C
#define pinstCharacterCreation_x                                   0xEE6190
#define pinstCCursorAttachment_x                                   0xEE6194
#define pinstCCastingWnd_x                                         0xEE6198
#define pinstCCastSpellWnd_x                                       0xEE619C
#define pinstCSpellBookWnd_x                                       0xEE61A0
#define pinstCInventoryWnd_x                                       0xEE61A4
#define pinstCBankWnd_x                                            0xEE61A8
#define pinstCQuantityWnd_x                                        0xEE61AC
#define pinstCLootWnd_x                                            0xEE61B0
#define pinstCActionsWnd_x                                         0xEE61B4
#define pinstCCombatAbilityWnd_x                                   0xEE61B8
#define pinstCMerchantWnd_x                                        0xEE61BC
#define pinstCTradeWnd_x                                           0xEE61C0
#define pinstCSelectorWnd_x                                        0xEE61C4
#define pinstCBazaarWnd_x                                          0xEE61C8
#define pinstCBazaarSearchWnd_x                                    0xEE61CC
#define pinstCGiveWnd_x                                            0xEE61E8
#define pinstCTrackingWnd_x                                        0xEE61F0
#define pinstCInspectWnd_x                                         0xEE61F4
#define pinstCSocialEditWnd_x                                      0xEE61F8
#define pinstCFeedbackWnd_x                                        0xEE61FC
#define pinstCBugReportWnd_x                                       0xEE6200
#define pinstCVideoModesWnd_x                                      0xEE6204
#define pinstCTextEntryWnd_x                                       0xEE620C
#define pinstCFileSelectionWnd_x                                   0xEE6210
#define pinstCCompassWnd_x                                         0xEE6214
#define pinstCPlayerNotesWnd_x                                     0xEE6218
#define pinstCGemsGameWnd_x                                        0xEE621C
#define pinstCTimeLeftWnd_x                                        0xEE6220
#define pinstCPetitionQWnd_x                                       0xEE6234
#define pinstCSoulmarkWnd_x                                        0xEE6238
#define pinstCStoryWnd_x                                           0xEE623C
#define pinstCJournalTextWnd_x                                     0xEE6240
#define pinstCJournalCatWnd_x                                      0xEE6244
#define pinstCBodyTintWnd_x                                        0xEE6248
#define pinstCServerListWnd_x                                      0xEE624C
#define pinstCAvaZoneWnd_x                                         0xEE6258
#define pinstCBlockedBuffWnd_x                                     0xEE625C
#define pinstCBlockedPetBuffWnd_x                                  0xEE6260
#define pinstCInvSlotMgr_x                                         0xEE62A4
#define pinstCContainerMgr_x                                       0xEE62A8
#define pinstCAdventureLeaderboardWnd_x                            0x1138B30
#define pinstCAdventureRequestWnd_x                                0x1138BA8
#define pinstCAltStorageWnd_x                                      0x1138E88
#define pinstCAdventureStatsWnd_x                                  0x1138C20
#define pinstCBarterMerchantWnd_x                                  0x1139A70
#define pinstCBarterSearchWnd_x                                    0x1139AE8
#define pinstCBarterWnd_x                                          0x1139B60
#define pinstCChatManager_x                                        0x113A1F0
#define pinstCDynamicZoneWnd_x                                     0x113A6A0
#define pinstCEQMainWnd_x                                          0x113A838
#define pinstCFellowshipWnd_x                                      0x113A634
#define pinstCFindLocationWnd_x                                    0x113AB08
#define pinstCGroupSearchWnd_x                                     0x113ADD8
#define pinstCGroupWnd_x                                           0x113AE50
#define pinstCGuildBankWnd_x                                       0x113AEC8
#define pinstCGuildMgmtWnd_x                                       0x113CFB8
#define pinstCHotButtonWnd_x                                       0x113D084
#define pinstCHotButtonWnd1_x                                      0x113D084
#define pinstCHotButtonWnd2_x                                      0x113D088
#define pinstCHotButtonWnd3_x                                      0x113D08C
#define pinstCHotButtonWnd4_x                                      0x113D0B0
#define pinstCItemDisplayManager_x                                 0x113D3A8
#define pinstCItemExpTransferWnd_x                                 0x113D424
#define pinstCLFGuildWnd_x                                         0x113D700
#define pinstCMIZoneSelectWnd_x                                    0x113DCE8
#define pinstCConfirmationDialog_x                                 0x113E3F0
#define pinstCPopupWndManager_x                                    0x113E3F0
#define pinstCProgressionSelectionWnd_x                            0x113E4E0
#define pinstCPvPStatsWnd_x                                        0x113E5D0
#define pinstCSystemInfoDialogBox_x                                0x113ECD8
#define pinstCTaskWnd_x                                            0x11400A0
#define pinstCTaskSomething_x                                      0xDB4340
#define pinstCTaskTemplateSelectWnd_x                              0x1140028
#define pinstCTipWndOFDAY_x                                        0x11402F8
#define pinstCTipWndCONTEXT_x                                      0x11402FC
#define pinstCTitleWnd_x                                           0x1140378
#define pinstCContextMenuManager_x                                 0x17A1A0C
#define pinstCVoiceMacroWnd_x                                      0x102CFB0
#define pinstCHtmlWnd_x                                            0x102D0A8
#define pinstIconCache_x                                           0x113A80C
#define pinstCTradeskillWnd_x                                      0x1140478
#define pinstCAdvancedLootWnd_x                                    0xEE6298
#define pinstRewardSelectionWnd_x                                  0x113EAF8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5297B0
#define __ConvertItemTags_x                                        0x516AA0
#define __ExecuteCmd_x                                             0x501470
#define __EQGetTime_x                                              0x85EC80
#define __get_melee_range_x                                        0x508140
#define __GetGaugeValueFromEQ_x                                    0x79E510
#define __GetLabelFromEQ_x                                         0x79F750
#define __ToggleMount_x                                            0x6C7950
#define __GetXTargetType_x                                         0x91D920
#define __LoadFrontEnd_x                                           0x62C940
#define __NewUIINI_x                                               0x79DE10
#define __ProcessGameEvents_x                                      0x56D480
#define __ProcessMouseEvent_x                                      0x56CC20
#define CrashDetected_x                                            0x62E410
#define wwsCrashReportCheckForUploader_x                           0x7F3570
#define DrawNetStatus_x                                            0x5A4160
#define Util__FastTime_x                                           0x85E7D0
#define Expansion_HoT_x                                            0xFA799C
#define __HelpPath_x                                               0x102B100

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41ED00
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419B50

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C1120
#define AltAdvManager__IsAbilityReady_x                            0x4C1190
#define AltAdvManager__GetAltAbility_x                             0x4C1550

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x464E40
#define CharacterZoneClient__MakeMeVisible_x                       0x469F70
// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x65C1A0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66A580

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x583740

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x685450
#define CChatManager__InitContextMenu_x                            0x685F70

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8CF310
#define CContextMenu__dCContextMenu_x                              0x8CF520
#define CContextMenu__AddMenuItem_x                                0x8CF530
#define CContextMenu__RemoveMenuItem_x                             0x8CF820
#define CContextMenu__RemoveAllMenuItems_x                         0x8CF840
#define CContextMenuManager__AddMenu_x                             0x8BB270
#define CContextMenuManager__RemoveMenu_x                          0x8BB5B0
#define CContextMenuManager__PopupMenu_x                           0x8BBA00
#define CContextMenuManager__Flush_x                               0x8BB2E0
#define CContextMenuManager__GetMenu_x                             0x4151A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x844DC0
#define CChatService__GetFriendName_x                              0x844DD0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x68AFD0
#define CChatWindow__Clear_x                                       0x68AB90
#define CChatWindow__WndNotification_x                             0x68B510

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8BF170
#define CComboWnd__Draw_x                                          0x8BF380
#define CComboWnd__GetCurChoice_x                                  0x8BEF40
#define CComboWnd__GetListRect_x                                   0x8BF620
#define CComboWnd__GetTextRect_x                                   0x8BF1E0
#define CComboWnd__InsertChoice_x                                  0x8BF690
#define CComboWnd__SetColors_x                                     0x8BEED0
#define CComboWnd__SetChoice_x                                     0x8BEF00
#define CComboWnd__GetItemCount_x                                  0x8BEF30

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x694730
#define CContainerWnd__vftable_x                                   0xA89698

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4AF430
#define CDisplay__GetClickedActor_x                                0x4A7FB0
#define CDisplay__GetUserDefinedColor_x                            0x4A6870
#define CDisplay__GetWorldFilePath_x                               0x4A5CC0
#define CDisplay__is3dON_x                                         0x4A5090
#define CDisplay__ReloadUI_x                                       0x4BA900
#define CDisplay__WriteTextHD2_x                                   0x4AB7D0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E5AD0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D3DB0
#define CEditWnd__GetCharIndexPt_x                                 0x8D4E50
#define CEditWnd__GetDisplayString_x                               0x8D3F60
#define CEditWnd__GetHorzOffset_x                                  0x8D42A0
#define CEditWnd__GetLineForPrintableChar_x                        0x8D4910
#define CEditWnd__GetSelStartPt_x                                  0x8D5110
#define CEditWnd__GetSTMLSafeText_x                                0x8D4440
#define CEditWnd__PointFromPrintableChar_x                         0x8D4A00
#define CEditWnd__SelectableCharFromPoint_x                        0x8D4B80
#define CEditWnd__SetEditable_x                                    0x8D4410

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x54ADE0
#define CEverQuest__DoTellWindow_x                                 0x5507E0
#define CEverQuest__DropHeldItemOnGround_x                         0x559310
#define CEverQuest__dsp_chat_x                                     0x551F80
#define CEverQuest__Emote_x                                        0x5521E0
#define CEverQuest__EnterZone_x                                    0x565A70
#define CEverQuest__GetBodyTypeDesc_x                              0x547640
#define CEverQuest__GetClassDesc_x                                 0x54D350
#define CEverQuest__GetClassThreeLetterCode_x                      0x54D950
#define CEverQuest__GetDeityDesc_x                                 0x547F20
#define CEverQuest__GetLangDesc_x                                  0x5479D0
#define CEverQuest__GetRaceDesc_x                                  0x54DB10
#define CEverQuest__InterpretCmd_x                                 0x552AC0
#define CEverQuest__LeftClickedOnPlayer_x                          0x569B80
#define CEverQuest__LMouseUp_x                                     0x56BC70
#define CEverQuest__RightClickedOnPlayer_x                         0x56A680
#define CEverQuest__RMouseUp_x                                     0x56B6D0
#define CEverQuest__SetGameState_x                                 0x54B490
#define CEverQuest__UPCNotificationFlush_x                         0x553C60
#define CEverQuest__IssuePetCommand_x                              0x5537C0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A52D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A5330
#define CGaugeWnd__Draw_x                                          0x6A5760

// CGuild
#define CGuild__FindMemberByName_x                                 0x435B20

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C2390

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D0160
#define CInvSlotMgr__MoveItem_x                                    0x6D10A0
#define CInvSlotMgr__SelectSlot_x                                  0x6D0210

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6CF600
#define CInvSlot__SliderComplete_x                                 0x6CCFD0
#define CInvSlot__GetItemBase_x                                    0x6CC460

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D2220

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79B010
#define CItemDisplayWnd__UpdateStrings_x                           0x6D3560

// CLabel 
#define CLabel__Draw_x                                             0x6EE390

// CListWnd
#define CListWnd__CListWnd_x                                       0x8AAE20
#define CListWnd__dCListWnd_x                                      0x8ABE50
#define CListWnd__AddColumn_x                                      0x8ABDF0
#define CListWnd__AddColumn1_x                                     0x8AB660
#define CListWnd__AddLine_x                                        0x8AB0E0
#define CListWnd__AddString_x                                      0x8AB2F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8A8160
#define CListWnd__CalculateVSBRange_x                              0x8AA2E0
#define CListWnd__ClearAllSel_x                                    0x8A7420
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8AACB0
#define CListWnd__Compare_x                                        0x8A8C60
#define CListWnd__Draw_x                                           0x8A9EF0
#define CListWnd__DrawColumnSeparators_x                           0x8A9D80
#define CListWnd__DrawHeader_x                                     0x8A7730
#define CListWnd__DrawItem_x                                       0x8A92B0
#define CListWnd__DrawLine_x                                       0x8A9A20
#define CListWnd__DrawSeparator_x                                  0x8A9E20
#define CListWnd__EnsureVisible_x                                  0x8A82C0
#define CListWnd__ExtendSel_x                                      0x8A91C0
#define CListWnd__GetColumnMinWidth_x                              0x8A6DE0
#define CListWnd__GetColumnWidth_x                                 0x8A6D00
#define CListWnd__GetCurSel_x                                      0x8A64D0
#define CListWnd__GetItemAtPoint_x                                 0x8A8560
#define CListWnd__GetItemAtPoint1_x                                0x8A85D0
#define CListWnd__GetItemData_x                                    0x8A6810
#define CListWnd__GetItemHeight_x                                  0x8A7DC0
#define CListWnd__GetItemIcon_x                                    0x8A69F0
#define CListWnd__GetItemRect_x                                    0x8A83A0
#define CListWnd__GetItemText_x                                    0x8A68A0
#define CListWnd__GetSelList_x                                     0x8AB550
#define CListWnd__GetSeparatorRect_x                               0x8A8B90
#define CListWnd__RemoveLine_x                                     0x8AB4D0
#define CListWnd__SetColors_x                                      0x8A6620
#define CListWnd__SetColumnJustification_x                         0x8A70B0
#define CListWnd__SetColumnWidth_x                                 0x8A6D90
#define CListWnd__SetCurSel_x                                      0x8A6510
#define CListWnd__SetItemColor_x                                   0x8AA990
#define CListWnd__SetItemData_x                                    0x8A74D0
#define CListWnd__SetItemText_x                                    0x8AA7D0
#define CListWnd__ShiftColumnSeparator_x                           0x8AA660
#define CListWnd__Sort_x                                           0x8ABF50
#define CListWnd__ToggleSel_x                                      0x8A73A0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x707800

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x728AA0
#define CMerchantWnd__RequestBuyItem_x                             0x72F8C0
#define CMerchantWnd__RequestSellItem_x                            0x730310
#define CMerchantWnd__SelectRecoverySlot_x                         0x728D50
#define CMerchantWnd__SelectBuySellSlot_x                          0x727FB0
#define CMerchantWnd__ActualSelect_x                               0x72C7F0

// CObfuscator
#define CObfuscator__doit_x                                        0x825040

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8CA2F0
#define CSidlManager__CreateLabel_x                                0x791030

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x6534E0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x653410
#define CSidlScreenWnd__ConvertToRes_x                             0x8E59B0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8C1E00
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C32E0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C3390
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C2850
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8C17B0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8C0F00
#define CSidlScreenWnd__GetSidlPiece_x                             0x8C19A0
#define CSidlScreenWnd__Init1_x                                    0x8C2FB0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C1EB0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8C10C0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C2AA0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C09D0
#define CSidlScreenWnd__StoreIniVis_x                              0x8C0E90
#define CSidlScreenWnd__WndNotification_x                          0x8C2D30
#define CSidlScreenWnd__GetChildItem_x                             0x8C0FD0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B44F0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5EEAF0
#define CSkillMgr__GetSkillCap_x                                   0x5EEC90
#define CSkillMgr__GetNameToken_x                                  0x5EE760

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E4C50
#define CSliderWnd__SetValue_x                                     0x8E4E20
#define CSliderWnd__SetNumTicks_x                                  0x8E55A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x798CB0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8DF5B0
#define CStmlWnd__CalculateHSBRange_x                              0x8D7AF0
#define CStmlWnd__CalculateVSBRange_x                              0x8D7B80
#define CStmlWnd__CanBreakAtCharacter_x                            0x8D7CF0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8D85D0
#define CStmlWnd__ForceParseNow_x                                  0x8DFF70
#define CStmlWnd__GetNextTagPiece_x                                0x8D84D0
#define CStmlWnd__GetSTMLText_x                                    0x68A430
#define CStmlWnd__GetVisibleText_x                                 0x8D9020
#define CStmlWnd__InitializeWindowVariables_x                      0x8DB390
#define CStmlWnd__MakeStmlColorTag_x                               0x8D6DF0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D6E50
#define CStmlWnd__SetSTMLText_x                                    0x8DCBF0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8DF250
#define CStmlWnd__UpdateHistoryString_x                            0x8D9F50

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E7280
#define CTabWnd__DrawCurrentPage_x                                 0x8E6AF0
#define CTabWnd__DrawTab_x                                         0x8E68B0
#define CTabWnd__GetCurrentPage_x                                  0x8E6EC0
#define CTabWnd__GetPageInnerRect_x                                0x8E65A0
#define CTabWnd__GetTabInnerRect_x                                 0x8E67A0
#define CTabWnd__GetTabRect_x                                      0x8E6670
#define CTabWnd__InsertPage_x                                      0x8E7570
#define CTabWnd__SetPage_x                                         0x8E6EF0
#define CTabWnd__SetPageRect_x                                     0x8E71C0
#define CTabWnd__UpdatePage_x                                      0x8E7510

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431870

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8BEB40

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8EC480

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A46C0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402290
#define CXStr__CXStr1_x                                            0x8EB1B0
#define CXStr__CXStr3_x                                            0x85B860
#define CXStr__dCXStr_x                                            0x4C2970
#define CXStr__operator_equal_x                                    0x85B9D0
#define CXStr__operator_equal1_x                                   0x85BA20
#define CXStr__operator_plus_equal1_x                              0x85CB00

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B3750
#define CXWnd__Center_x                                            0x8B9860
#define CXWnd__ClrFocus_x                                          0x8B3320
#define CXWnd__DoAllDrawing_x                                      0x8B94B0
#define CXWnd__DrawChildren_x                                      0x8B9650
#define CXWnd__DrawColoredRect_x                                   0x8B3B10
#define CXWnd__DrawTooltip_x                                       0x8B3DB0
#define CXWnd__DrawTooltipAtPoint_x                                0x8B8450
#define CXWnd__GetBorderFrame_x                                    0x8B41C0
#define CXWnd__GetChildWndAt_x                                     0x8BA220
#define CXWnd__GetClientClipRect_x                                 0x8B3FC0
#define CXWnd__GetScreenClipRect_x                                 0x8B8B50
#define CXWnd__GetScreenRect_x                                     0x8B4390
#define CXWnd__GetTooltipRect_x                                    0x8B3C40
#define CXWnd__GetWindowTextA_x                                    0x422C80
#define CXWnd__IsActive_x                                          0x8AEC30
#define CXWnd__IsDescendantOf_x                                    0x8B4100
#define CXWnd__IsReallyVisible_x                                   0x8B74A0
#define CXWnd__IsType_x                                            0x8E8C50
#define CXWnd__Move_x                                              0x8B6C20
#define CXWnd__Move1_x                                             0x8B9170
#define CXWnd__ProcessTransition_x                                 0x8B3700
#define CXWnd__Refade_x                                            0x8B3700
#define CXWnd__Resize_x                                            0x8B4450
#define CXWnd__Right_x                                             0x8B8950
#define CXWnd__SetFocus_x                                          0x8B5D60
#define CXWnd__SetFont_x                                           0x8B3370
#define CXWnd__SetKeyTooltip_x                                     0x8B46C0
#define CXWnd__SetMouseOver_x                                      0x8B8E60
#define CXWnd__StartFade_x                                         0x8B37A0
#define CXWnd__GetChildItem_x                                      0x8B8DA0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B0560
#define CXWndManager__DrawWindows_x                                0x8B01A0
#define CXWndManager__GetKeyboardFlags_x                           0x8AE760
#define CXWndManager__HandleKeyboardMsg_x                          0x8AF0C0
#define CXWndManager__RemoveWnd_x                                  0x8AEDC0

// CDBStr
#define CDBStr__GetString_x                                        0x4A34E0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44F010
#define EQ_Character__Cur_HP_x                                     0x464510
#define EQ_Character__GetAACastingTimeModifier_x                   0x446E00
#define EQ_Character__GetCharInfo2_x                               0x82F870
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EF20
#define EQ_Character__GetFocusRangeModifier_x                      0x43F100
#define EQ_Character__Max_Endurance_x                              0x5B63D0
#define EQ_Character__Max_HP_x                                     0x45A190
#define EQ_Character__Max_Mana_x                                   0x5B6200
#define EQ_Character__doCombatAbility_x                            0x5B37F0
#define EQ_Character__UseSkill_x                                   0x46F160
#define EQ_Character__GetConLevel_x                                0x5A8790
#define EQ_Character__IsExpansionFlag_x                            0x4221B0
#define EQ_Character__TotalEffect_x                                0x44BFE0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x588EF0
#define EQ_Item__CreateItemTagString_x                             0x80ED90
#define EQ_Item__IsStackable_x                                     0x803190
#define EQ_Item__GetImageNum_x                                     0x805E90

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C3300
#define EQ_LoadingS__Array_x                                       0xBAA848

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5B7B60
#define EQ_PC__GetAltAbilityIndex_x                                0x817DB0
#define EQ_PC__GetCombatAbility_x                                  0x817E40
#define EQ_PC__GetCombatAbilityTimer_x                             0x812E60
#define EQ_PC__GetItemTimerValue_x                                 0x5B15D0
#define EQ_PC__HasLoreItem_x                                       0x5ABAE0
#define EQ_PC__AlertInventoryChanged_x                             0x5A8760
#define EQ_PC__GetPcZoneClient_x                                   0x5D20F0
#define EQ_PC__RemoveMyAffect_x									   0x5B0AE0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x506140
#define EQItemList__add_item_x                                     0x506080
#define EQItemList__delete_item_x                                  0x506540
#define EQItemList__FreeItemList_x                                 0x506440

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A2670

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5BD120
#define EQPlayer__dEQPlayer_x                                      0x5C5F50
#define EQPlayer__DoAttack_x                                       0x5D7FA0
#define EQPlayer__EQPlayer_x                                       0x5C8370
#define EQPlayer__SetNameSpriteState_x                             0x5C2C20
#define EQPlayer__SetNameSpriteTint_x                              0x5BE4F0
#define EQPlayer__IsBodyType_j_x                                   0x919B50
#define EQPlayer__IsTargetable_x                                   0x91A410
#define EQPlayer__CanSee_x                                         0x91A930

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5CC700
#define EQPlayerManager__GetSpawnByName_x                          0x5CCB60

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x58F090
#define KeypressHandler__AttachKeyToEqCommand_x                    0x58F0D0
#define KeypressHandler__ClearCommandStateArray_x                  0x58EC70
#define KeypressHandler__HandleKeyDown_x                           0x58D5D0
#define KeypressHandler__HandleKeyUp_x                             0x58D8F0
#define KeypressHandler__SaveKeymapping_x                          0x58ED40

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6FFBE0
#define MapViewMap__SaveEx_x                                       0x7034C0

#define PlayerPointManager__GetAltCurrency_x                       0x82A770

// StringTable 
#define StringTable__getString_x                                   0x8252E0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B5E80

//Doors
#define EQSwitch__UseSwitch_x                                      0x544A60

//IconCache
#define IconCache__GetIcon_x                                       0x69AB90

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x691A30
#define CContainerMgr__CloseContainer_x                            0x692250

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x761330

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x582200

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D6980
#define EQ_Spell__SpellAffects_x                                   0x4D6A20
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D6A50
#define CharacterZoneClient__CalcAffectChange_x                    0x448120
#define CLootWnd__LootAll_x                                        0x6F5520

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7A6A80
#define CTargetWnd__WndNotification_x                              0x7A6570

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7ABC50

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D02C0
