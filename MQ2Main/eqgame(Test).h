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
#define __ExpectedVersionDate                                     "Jun  9 2015"
#define __ExpectedVersionTime                                     "19:00:02"
#define __ActualVersionDate_x                                      0xA7FFB0
#define __ActualVersionTime_x                                      0xA7FFBC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5948A0
#define __MemChecker1_x                                            0x85F1B0
#define __MemChecker2_x                                            0x62D780
#define __MemChecker3_x                                            0x62D6D0
#define __MemChecker4_x                                            0x7E24B0
#define __EncryptPad0_x                                            0xBFE5A0
#define __EncryptPad1_x                                            0xD85F18
#define __EncryptPad2_x                                            0xC47EE8
#define __EncryptPad3_x                                            0xC47AE8
#define __EncryptPad4_x                                            0xD61F80
#define __AC1_x                                                    0x79FC45
#define __AC2_x                                                    0x54A767
#define __AC3_x                                                    0x55EF60
#define __AC4_x                                                    0x565320
#define __AC5_x                                                    0x57114E
#define __AC6_x                                                    0x574BF9
#define __AC7_x                                                    0x56B7FC
#define __AC1_Data                                                 0x11111111

// Direct Input
#define DI8__Main_x                                                0x1137FF8
#define DI8__Keyboard_x                                            0x1137FFC
#define DI8__Mouse_x                                               0x1138000
#define __AltTimerReady_x                                          0xF97969
#define __Attack_x                                                 0x102AB87
#define __Autofire_x                                               0x102AB88
#define __BindList_x                                               0xBC0818
#define __bCommandEnabled_x                                        0xF95A78
#define __Clicks_x                                                 0xFA66D8
#define __CommandList_x                                            0xBC4B70
#define __CurrentMapLabel_x                                        0x113DA50
#define __CurrentSocial_x                                          0xB7BE7C
#define __DoAbilityList_x                                          0xFDCE3C
#define __do_loot_x                                                0x511E80
#define __DrawHandler_x                                            0x17A265C
#define __GroupCount_x                                             0xF97042

#define __Guilds_x                                                 0xF9CC58
#define __gWorld_x                                                 0xF994FC
#define __HotkeyPage_x                                             0x102383C
#define __HWnd_x                                                   0x102FF00
#define __InChatMode_x                                             0xFA6604
#define __LastTell_x                                               0xFA8544
#define __LMouseHeldTime_x                                         0xFA6744
#define __Mouse_x                                                  0x1138004
#define __MouseLook_x                                              0xFA669E
#define __MouseEventTime_x                                         0x102B38C
#define __gpbCommandEvent_x                                        0xF995C4
#define __NetStatusToggle_x                                        0xFA66A1
#define __PCNames_x                                                0xFA7B64
#define __RangeAttackReady_x                                       0xFA7828
#define __RMouseHeldTime_x                                         0xFA6740
#define __RunWalkState_x                                           0xFA6608
#define __ScreenMode_x                                             0xEE58B8
#define __ScreenX_x                                                0xFA65BC
#define __ScreenY_x                                                0xFA65B8
#define __ScreenXMax_x                                             0xFA65C0
#define __ScreenYMax_x                                             0xFA65C4
#define __ServerHost_x                                             0xF96F8C
#define __ServerName_x                                             0xFDCDFC
#define __ShiftKeyDown_x                                           0xFA6CAC
#define __ShowNames_x                                              0xFA79FC
#define __Socials_x                                                0xFDCEFC
#define __SubscriptionType_x                                       0x1169DE0
#define __TargetAggroHolder_x                                      0x113FC8C
#define __GroupAggro_x                                             0x113FCCC
#define __LoginName_x                                              0x102EAD8
#define __Inviter_x                                                0x102AB04


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF995E8
#define instEQZoneInfo_x                                           0xFA6894
#define instKeypressHandler_x                                      0x102B370
#define pinstActiveBanker_x                                        0xF995A0
#define pinstActiveCorpse_x                                        0xF995A4
#define pinstActiveGMaster_x                                       0xF995A8
#define pinstActiveMerchant_x                                      0xF9959C
#define pinstAggroInfo_x                                           0xDA9D38
#define pinstAltAdvManager_x                                       0xEE69A0
#define pinstAuraMgr_x                                             0xDB3C00
#define pinstBandageTarget_x                                       0xF99588
#define pinstCamActor_x                                            0xEE62AC
#define pinstCDBStr_x                                              0xEE584C
#define pinstCDisplay_x                                            0xF995B0
#define pinstCEverQuest_x                                          0x1138178
#define pinstCharData_x                                            0xF9956C
#define pinstCharSpawn_x                                           0xF99594
#define pinstControlledMissile_x                                   0xF99568
#define pinstControlledPlayer_x                                    0xF99594
#define pinstCSidlManager_x                                        0x17A1A94
#define pinstCXWndManager_x                                        0x17A1A8C
#define instDynamicZone_x                                          0xFA6450
#define pinstDZMember_x                                            0xFA6560
#define pinstDZTimerInfo_x                                         0xFA6564
#define pinstEQItemList_x                                          0xF95CC8
#define instEQMisc_x                                               0xB9CAC0
#define pinstEQSoundManager_x                                      0xEE6E10
#define instExpeditionLeader_x                                     0xFA649A
#define instExpeditionName_x                                       0xFA64DA
#define pinstGroup_x                                               0xF9703E
#define pinstImeManager_x                                          0x17A1A98
#define pinstLocalPlayer_x                                         0xF99580
#define pinstMercenaryData_x                                       0x102B9C0
#define pinstMercAltAbilities_x                                    0xEE6D2C
#define pinstModelPlayer_x                                         0xF995AC
#define pinstPCData_x                                              0xF9956C
#define pinstSkillMgr_x                                            0x102C7F8
#define pinstSpawnManager_x                                        0x102C0E0
#define pinstSpellManager_x                                        0x102C940
#define pinstSpellSets_x                                           0x10238A0
#define pinstStringTable_x                                         0xF99514
#define pinstSwitchManager_x                                       0xF96BD0
#define pinstTarget_x                                              0xF99598
#define pinstTargetObject_x                                        0xF99570
#define pinstTargetSwitch_x                                        0xF99574
#define pinstTaskMember_x                                          0xEE5798
#define pinstTrackTarget_x                                         0xF9958C
#define pinstTradeTarget_x                                         0xF9957C
#define instTributeActive_x                                        0xB9CAE5
#define pinstViewActor_x                                           0xEE62A8
#define pinstWorldData_x                                           0xF99550


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xDAA218
#define pinstCAudioTriggersWindow_x                                0xDAA0A8
#define pinstCCharacterSelect_x                                    0xEE6148
#define pinstCFacePick_x                                           0xEE60F8
#define pinstCNoteWnd_x                                            0xEE6100
#define pinstCBookWnd_x                                            0xEE6108
#define pinstCPetInfoWnd_x                                         0xEE610C
#define pinstCTrainWnd_x                                           0xEE6110
#define pinstCSkillsWnd_x                                          0xEE6114
#define pinstCSkillsSelectWnd_x                                    0xEE6118
#define pinstCCombatSkillSelectWnd_x                               0xEE611C
#define pinstCFriendsWnd_x                                         0xEE6120
#define pinstCAuraWnd_x                                            0xEE6124
#define pinstCRespawnWnd_x                                         0xEE6128
#define pinstCBandolierWnd_x                                       0xEE612C
#define pinstCPotionBeltWnd_x                                      0xEE6130
#define pinstCAAWnd_x                                              0xEE6134
#define pinstCGroupSearchFiltersWnd_x                              0xEE6138
#define pinstCLoadskinWnd_x                                        0xEE613C
#define pinstCAlarmWnd_x                                           0xEE6140
#define pinstCMusicPlayerWnd_x                                     0xEE6144
#define pinstCMailWnd_x                                            0xEE614C
#define pinstCMailCompositionWnd_x                                 0xEE6150
#define pinstCMailAddressBookWnd_x                                 0xEE6154
#define pinstCRaidWnd_x                                            0xEE615C
#define pinstCRaidOptionsWnd_x                                     0xEE6160
#define pinstCBreathWnd_x                                          0xEE6164
#define pinstCMapViewWnd_x                                         0xEE6168
#define pinstCMapToolbarWnd_x                                      0xEE616C
#define pinstCEditLabelWnd_x                                       0xEE6170
#define pinstCTargetWnd_x                                          0xEE6174
#define pinstCColorPickerWnd_x                                     0xEE6178
#define pinstCPlayerWnd_x                                          0xEE617C
#define pinstCOptionsWnd_x                                         0xEE6180
#define pinstCBuffWindowNORMAL_x                                   0xEE6184
#define pinstCBuffWindowSHORT_x                                    0xEE6188
#define pinstCharacterCreation_x                                   0xEE618C
#define pinstCCursorAttachment_x                                   0xEE6190
#define pinstCCastingWnd_x                                         0xEE6194
#define pinstCCastSpellWnd_x                                       0xEE6198
#define pinstCSpellBookWnd_x                                       0xEE619C
#define pinstCInventoryWnd_x                                       0xEE61A0
#define pinstCBankWnd_x                                            0xEE61A4
#define pinstCQuantityWnd_x                                        0xEE61A8
#define pinstCLootWnd_x                                            0xEE61AC
#define pinstCActionsWnd_x                                         0xEE61B0
#define pinstCCombatAbilityWnd_x                                   0xEE61B4
#define pinstCMerchantWnd_x                                        0xEE61B8
#define pinstCTradeWnd_x                                           0xEE61BC
#define pinstCSelectorWnd_x                                        0xEE61C0
#define pinstCBazaarWnd_x                                          0xEE61C4
#define pinstCBazaarSearchWnd_x                                    0xEE61C8
#define pinstCGiveWnd_x                                            0xEE61E4
#define pinstCTrackingWnd_x                                        0xEE61EC
#define pinstCInspectWnd_x                                         0xEE61F0
#define pinstCSocialEditWnd_x                                      0xEE61F4
#define pinstCFeedbackWnd_x                                        0xEE61F8
#define pinstCBugReportWnd_x                                       0xEE61FC
#define pinstCVideoModesWnd_x                                      0xEE6200
#define pinstCTextEntryWnd_x                                       0xEE6208
#define pinstCFileSelectionWnd_x                                   0xEE620C
#define pinstCCompassWnd_x                                         0xEE6210
#define pinstCPlayerNotesWnd_x                                     0xEE6214
#define pinstCGemsGameWnd_x                                        0xEE6218
#define pinstCTimeLeftWnd_x                                        0xEE621C
#define pinstCPetitionQWnd_x                                       0xEE6230
#define pinstCSoulmarkWnd_x                                        0xEE6234
#define pinstCStoryWnd_x                                           0xEE6238
#define pinstCJournalTextWnd_x                                     0xEE623C
#define pinstCJournalCatWnd_x                                      0xEE6240
#define pinstCBodyTintWnd_x                                        0xEE6244
#define pinstCServerListWnd_x                                      0xEE6248
#define pinstCAvaZoneWnd_x                                         0xEE6254
#define pinstCBlockedBuffWnd_x                                     0xEE6258
#define pinstCBlockedPetBuffWnd_x                                  0xEE625C
#define pinstCInvSlotMgr_x                                         0xEE62A0
#define pinstCContainerMgr_x                                       0xEE62A4
#define pinstCAdventureLeaderboardWnd_x                            0x1138B28
#define pinstCAdventureRequestWnd_x                                0x1138BA0
#define pinstCAltStorageWnd_x                                      0x1138E80
#define pinstCAdventureStatsWnd_x                                  0x1138C18
#define pinstCBarterMerchantWnd_x                                  0x1139A68
#define pinstCBarterSearchWnd_x                                    0x1139AE0
#define pinstCBarterWnd_x                                          0x1139B58
#define pinstCChatManager_x                                        0x113A1E8
#define pinstCDynamicZoneWnd_x                                     0x113A698
#define pinstCEQMainWnd_x                                          0x113A830
#define pinstCFellowshipWnd_x                                      0x113A62C
#define pinstCFindLocationWnd_x                                    0x113AB00
#define pinstCGroupSearchWnd_x                                     0x113ADD0
#define pinstCGroupWnd_x                                           0x113AE48
#define pinstCGuildBankWnd_x                                       0x113AEC0
#define pinstCGuildMgmtWnd_x                                       0x113CFB0
#define pinstCHotButtonWnd_x                                       0x113D07C
#define pinstCHotButtonWnd1_x                                      0x113D07C
#define pinstCHotButtonWnd2_x                                      0x113D080
#define pinstCHotButtonWnd3_x                                      0x113D084
#define pinstCHotButtonWnd4_x                                      0x113D0A8
#define pinstCItemDisplayManager_x                                 0x113D3A0
#define pinstCItemExpTransferWnd_x                                 0x113D41C
#define pinstCLFGuildWnd_x                                         0x113D6F8
#define pinstCMIZoneSelectWnd_x                                    0x113DCE0
#define pinstCConfirmationDialog_x                                 0x113E3E8
#define pinstCPopupWndManager_x                                    0x113E3E8
#define pinstCProgressionSelectionWnd_x                            0x113E4D8
#define pinstCPvPStatsWnd_x                                        0x113E5C8
#define pinstCSystemInfoDialogBox_x                                0x113ECD0
#define pinstCTaskWnd_x                                            0x1140098
#define pinstCTaskSomething_x                                      0xDB4340
#define pinstCTaskTemplateSelectWnd_x                              0x1140020
#define pinstCTipWndOFDAY_x                                        0x11402F0
#define pinstCTipWndCONTEXT_x                                      0x11402F4
#define pinstCTitleWnd_x                                           0x1140370
#define pinstCContextMenuManager_x                                 0x17A1A04
#define pinstCVoiceMacroWnd_x                                      0x102CFA8
#define pinstCHtmlWnd_x                                            0x102D0A0
#define pinstIconCache_x                                           0x113A804
#define pinstCTradeskillWnd_x                                      0x1140470
#define pinstCAdvancedLootWnd_x                                    0xEE6294
#define pinstRewardSelectionWnd_x                                  0x113EAF0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x529890
#define __ConvertItemTags_x                                        0x516B00
#define __ExecuteCmd_x                                             0x5014E0
#define __EQGetTime_x                                              0x85F4D0
#define __get_melee_range_x                                        0x5081A0
#define __GetGaugeValueFromEQ_x                                    0x79E990
#define __GetLabelFromEQ_x                                         0x79FBD0
#define __ToggleMount_x                                            0x6C7C60
#define __GetXTargetType_x                                         0x91DCD0
#define __LoadFrontEnd_x                                           0x62CE30
#define __NewUIINI_x                                               0x79E290
#define __ProcessGameEvents_x                                      0x56D560
#define __ProcessMouseEvent_x                                      0x56CD00
#define CrashDetected_x                                            0x62E900
#define wwsCrashReportCheckForUploader_x                           0x7F3A10
#define DrawNetStatus_x                                            0x5A4420
#define Util__FastTime_x                                           0x85F020
#define Expansion_HoT_x                                            0xFA7994
#define __HelpPath_x                                               0x102B0F8
//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41EDF0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419C40

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C15B0
#define AltAdvManager__IsAbilityReady_x                            0x4C1620
#define AltAdvManager__GetAltAbility_x                             0x4C19E0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x465140
#define CharacterZoneClient__MakeMeVisible_x                       0x46A270

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x65C5B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66AB00

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5837F0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6857F0
#define CChatManager__InitContextMenu_x                            0x686310

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8CF810
#define CContextMenu__AddMenuItem_x                                0x8CFA20
#define CContextMenu__dCContextMenu_x                              0x8CFA10
#define CContextMenu__RemoveMenuItem_x                             0x8CFD10
#define CContextMenu__RemoveAllMenuItems_x                         0x8CFD30
#define CContextMenuManager__AddMenu_x                             0x8BB7E0
#define CContextMenuManager__RemoveMenu_x                          0x8BBB10
#define CContextMenuManager__PopupMenu_x                           0x8BBF60
#define CContextMenuManager__Flush_x                               0x8BB850
#define CContextMenuManager__GetMenu_x                             0x4152A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8456F0
#define CChatService__GetFriendName_x                              0x845700

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x68B390
#define CChatWindow__Clear_x                                       0x68AF40
#define CChatWindow__WndNotification_x                             0x68B8C0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8BF6B0
#define CComboWnd__Draw_x                                          0x8BF8C0
#define CComboWnd__GetCurChoice_x                                  0x8BF480
#define CComboWnd__GetListRect_x                                   0x8BFB60
#define CComboWnd__GetTextRect_x                                   0x8BF720
#define CComboWnd__InsertChoice_x                                  0x8BFBD0
#define CComboWnd__SetColors_x                                     0x8BF410
#define CComboWnd__SetChoice_x                                     0x8BF440
#define CComboWnd__GetItemCount_x                                  0x8BF470

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x694A60
#define CContainerWnd__vftable_x                                   0xA89710

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4AF6B0
#define CDisplay__GetClickedActor_x                                0x4A8230
#define CDisplay__GetUserDefinedColor_x                            0x4A6AF0
#define CDisplay__GetWorldFilePath_x                               0x4A5F40
#define CDisplay__is3dON_x                                         0x4A5310
#define CDisplay__ReloadUI_x                                       0x4BAB80
#define CDisplay__WriteTextHD2_x                                   0x4ABA50

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E5DC0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D4150
#define CEditWnd__GetCharIndexPt_x                                 0x8D51F0
#define CEditWnd__GetDisplayString_x                               0x8D4300
#define CEditWnd__GetHorzOffset_x                                  0x8D4640
#define CEditWnd__GetLineForPrintableChar_x                        0x8D4CB0
#define CEditWnd__GetSelStartPt_x                                  0x8D54B0
#define CEditWnd__GetSTMLSafeText_x                                0x8D47E0
#define CEditWnd__PointFromPrintableChar_x                         0x8D4DA0
#define CEditWnd__SelectableCharFromPoint_x                        0x8D4F20
#define CEditWnd__SetEditable_x                                    0x8D47B0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x54AEB0
#define CEverQuest__DoTellWindow_x                                 0x5508B0
#define CEverQuest__DropHeldItemOnGround_x                         0x5593E0
#define CEverQuest__dsp_chat_x                                     0x552050
#define CEverQuest__Emote_x                                        0x5522B0
#define CEverQuest__EnterZone_x                                    0x565B40
#define CEverQuest__GetBodyTypeDesc_x                              0x547710
#define CEverQuest__GetClassDesc_x                                 0x54D420
#define CEverQuest__GetClassThreeLetterCode_x                      0x54DA20
#define CEverQuest__GetDeityDesc_x                                 0x547FF0
#define CEverQuest__GetLangDesc_x                                  0x547AA0
#define CEverQuest__GetRaceDesc_x                                  0x54DBE0
#define CEverQuest__InterpretCmd_x                                 0x552B90
#define CEverQuest__LeftClickedOnPlayer_x                          0x569C60
#define CEverQuest__LMouseUp_x                                     0x56BD50
#define CEverQuest__RightClickedOnPlayer_x                         0x56A760
#define CEverQuest__RMouseUp_x                                     0x56B7B0
#define CEverQuest__SetGameState_x                                 0x54B560
#define CEverQuest__UPCNotificationFlush_x                         0x553D30
#define CEverQuest__IssuePetCommand_x                              0x553890

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A55D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A5630
#define CGaugeWnd__Draw_x                                          0x6A5A60

// CGuild
#define CGuild__FindMemberByName_x                                 0x435AC0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C2690

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D04D0
#define CInvSlotMgr__MoveItem_x                                    0x6D1410
#define CInvSlotMgr__SelectSlot_x                                  0x6D0580

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6CF970
#define CInvSlot__SliderComplete_x                                 0x6CD330
#define CInvSlot__GetItemBase_x                                    0x6CC7A0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D25D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79B490
#define CItemDisplayWnd__UpdateStrings_x                           0x6D3920

// CLabel 
#define CLabel__Draw_x                                             0x6EE800

// CListWnd 
#define CListWnd__CListWnd_x                                       0x8AB560
#define CListWnd__dCListWnd_x                                      0x8AC590
#define CListWnd__AddColumn_x                                      0x8AC530
#define CListWnd__AddColumn1_x                                     0x8ABDA0
#define CListWnd__AddLine_x                                        0x8AB820
#define CListWnd__AddString_x                                      0x8ABA30
#define CListWnd__CalculateFirstVisibleLine_x                      0x8A8890
#define CListWnd__CalculateVSBRange_x                              0x8AAA10
#define CListWnd__ClearAllSel_x                                    0x8A7B50
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8AB3F0
#define CListWnd__Compare_x                                        0x8A9390
#define CListWnd__Draw_x                                           0x8AA620
#define CListWnd__DrawColumnSeparators_x                           0x8AA4B0
#define CListWnd__DrawHeader_x                                     0x8A7E60
#define CListWnd__DrawItem_x                                       0x8A99E0
#define CListWnd__DrawLine_x                                       0x8AA150
#define CListWnd__DrawSeparator_x                                  0x8AA550
#define CListWnd__EnsureVisible_x                                  0x8A89F0
#define CListWnd__ExtendSel_x                                      0x8A98F0
#define CListWnd__GetColumnMinWidth_x                              0x8A7510
#define CListWnd__GetColumnWidth_x                                 0x8A7430
#define CListWnd__GetCurSel_x                                      0x8A6C20
#define CListWnd__GetItemAtPoint_x                                 0x8A8C90
#define CListWnd__GetItemAtPoint1_x                                0x8A8D00
#define CListWnd__GetItemData_x                                    0x8A6F50
#define CListWnd__GetItemHeight_x                                  0x8A84F0
#define CListWnd__GetItemIcon_x                                    0x8A7130
#define CListWnd__GetItemRect_x                                    0x8A8AD0
#define CListWnd__GetItemText_x                                    0x8A6FE0
#define CListWnd__GetSelList_x                                     0x8ABC90
#define CListWnd__GetSeparatorRect_x                               0x8A92C0
#define CListWnd__RemoveLine_x                                     0x8ABC10
#define CListWnd__SetColors_x                                      0x8A6D70
#define CListWnd__SetColumnJustification_x                         0x8A77E0
#define CListWnd__SetColumnWidth_x                                 0x8A74C0
#define CListWnd__SetCurSel_x                                      0x8A6C60
#define CListWnd__SetItemColor_x                                   0x8AB0D0
#define CListWnd__SetItemData_x                                    0x8A7C00
#define CListWnd__SetItemText_x                                    0x8AAF10
#define CListWnd__ShiftColumnSeparator_x                           0x8AADA0
#define CListWnd__Sort_x                                           0x8AC690
#define CListWnd__ToggleSel_x                                      0x8A7AD0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x707DB0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x728EF0
#define CMerchantWnd__RequestBuyItem_x                             0x72FD30
#define CMerchantWnd__RequestSellItem_x                            0x7307A0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7291A0
#define CMerchantWnd__SelectBuySellSlot_x                          0x728400
#define CMerchantWnd__ActualSelect_x                               0x72CC60

// CObfuscator
#define CObfuscator__doit_x                                        0x825940

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8CA790
#define CSidlManager__CreateLabel_x                                0x791450

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x6538D0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x6537F0
#define CSidlScreenWnd__ConvertToRes_x                             0x8E5CA0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8C2330
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C3840
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C38F0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C2DB0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8C1CE0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8C1430
#define CSidlScreenWnd__GetSidlPiece_x                             0x8C1ED0
#define CSidlScreenWnd__Init1_x                                    0x8C3510
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C23E0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8C15F0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C3000
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C0EF0
#define CSidlScreenWnd__StoreIniVis_x                              0x8C13C0
#define CSidlScreenWnd__WndNotification_x                          0x8C3290
#define CSidlScreenWnd__GetChildItem_x                             0x8C1500
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B4AF0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5EEEC0
#define CSkillMgr__GetSkillCap_x                                   0x5EF060
#define CSkillMgr__GetNameToken_x                                  0x5EEB30

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E4F50
#define CSliderWnd__SetValue_x                                     0x8E5120
#define CSliderWnd__SetNumTicks_x                                  0x8E58A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x799120

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8DF960
#define CStmlWnd__CalculateHSBRange_x                              0x8D7F30
#define CStmlWnd__CalculateVSBRange_x                              0x8D7EA0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8D80B0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8D8990
#define CStmlWnd__ForceParseNow_x                                  0x8E02B0
#define CStmlWnd__GetNextTagPiece_x                                0x8D8890
#define CStmlWnd__GetSTMLText_x                                    0x68A7D0
#define CStmlWnd__GetVisibleText_x                                 0x8D93E0
#define CStmlWnd__InitializeWindowVariables_x                      0x8DB750
#define CStmlWnd__MakeStmlColorTag_x                               0x8D71A0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D7200
#define CStmlWnd__SetSTMLText_x                                    0x8DCFB0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8DF600
#define CStmlWnd__UpdateHistoryString_x                            0x8DA310

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E7580
#define CTabWnd__DrawCurrentPage_x                                 0x8E6DF0
#define CTabWnd__DrawTab_x                                         0x8E6BB0
#define CTabWnd__GetCurrentPage_x                                  0x8E71C0
#define CTabWnd__GetPageInnerRect_x                                0x8E68A0
#define CTabWnd__GetTabInnerRect_x                                 0x8E6AA0
#define CTabWnd__GetTabRect_x                                      0x8E6970
#define CTabWnd__InsertPage_x                                      0x8E7870
#define CTabWnd__SetPage_x                                         0x8E71F0
#define CTabWnd__SetPageRect_x                                     0x8E74C0
#define CTabWnd__UpdatePage_x                                      0x8E7810

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431830

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8BF080

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8EC7F0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A4D30

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x590E20
#define CXStr__CXStr1_x                                            0x73AE60
#define CXStr__CXStr3_x                                            0x85C0B0
#define CXStr__dCXStr_x                                            0x4BB4F0
#define CXStr__operator_equal_x                                    0x85C220
#define CXStr__operator_equal1_x                                   0x85C270
#define CXStr__operator_plus_equal1_x                              0x85D350

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B3DB0
#define CXWnd__Center_x                                            0x8B9DF0
#define CXWnd__ClrFocus_x                                          0x8B3980
#define CXWnd__DoAllDrawing_x                                      0x8B9A40
#define CXWnd__DrawChildren_x                                      0x8B9BE0
#define CXWnd__DrawColoredRect_x                                   0x8B4170
#define CXWnd__DrawTooltip_x                                       0x8B4410
#define CXWnd__DrawTooltipAtPoint_x                                0x8B89C0
#define CXWnd__GetBorderFrame_x                                    0x8B4810
#define CXWnd__GetChildWndAt_x                                     0x8BA7A0
#define CXWnd__GetClientClipRect_x                                 0x8B4620
#define CXWnd__GetScreenClipRect_x                                 0x8B90C0
#define CXWnd__GetScreenRect_x                                     0x8B4990
#define CXWnd__GetTooltipRect_x                                    0x8B42A0
#define CXWnd__GetWindowTextA_x                                    0x422D50
#define CXWnd__IsActive_x                                          0x8AF340
#define CXWnd__IsDescendantOf_x                                    0x8B4760
#define CXWnd__IsReallyVisible_x                                   0x8B7A50
#define CXWnd__IsType_x                                            0x8E8F60
#define CXWnd__Move_x                                              0x8B7140
#define CXWnd__Move1_x                                             0x8B9700
#define CXWnd__ProcessTransition_x                                 0x8B3D50
#define CXWnd__Refade_x                                            0x8B3B30
#define CXWnd__Resize_x                                            0x8B4A50
#define CXWnd__Right_x                                             0x8B8EC0
#define CXWnd__SetFocus_x                                          0x8B62A0
#define CXWnd__SetFont_x                                           0x8B39D0
#define CXWnd__SetKeyTooltip_x                                     0x8B4CC0
#define CXWnd__SetMouseOver_x                                      0x8B9400
#define CXWnd__StartFade_x                                         0x8B3E00
#define CXWnd__GetChildItem_x                                      0x8B9340

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B0C70
#define CXWndManager__DrawWindows_x                                0x8B08B0
#define CXWndManager__GetKeyboardFlags_x                           0x8AEEB0
#define CXWndManager__HandleKeyboardMsg_x                          0x8AF7D0
#define CXWndManager__RemoveWnd_x                                  0x8AF4D0

// CDBStr
#define CDBStr__GetString_x                                        0x4A37C0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44F410
#define EQ_Character__Cur_HP_x                                     0x464810
#define EQ_Character__GetAACastingTimeModifier_x                   0x446E40
#define EQ_Character__GetCharInfo2_x                               0x830130
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EF50
#define EQ_Character__GetFocusRangeModifier_x                      0x43F130
#define EQ_Character__Max_Endurance_x                              0x5B69D0
#define EQ_Character__Max_HP_x                                     0x45A480
#define EQ_Character__Max_Mana_x                                   0x5B6800
#define EQ_Character__doCombatAbility_x                            0x5B3DE0
#define EQ_Character__UseSkill_x                                   0x46F470
#define EQ_Character__GetConLevel_x                                0x5A8A70
#define EQ_Character__IsExpansionFlag_x                            0x422290
#define EQ_Character__TotalEffect_x                                0x44C3F0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x588F70
#define EQ_Item__CreateItemTagString_x                             0x80F570
#define EQ_Item__IsStackable_x                                     0x8036A0
#define EQ_Item__GetImageNum_x                                     0x8063F0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C3780
#define EQ_LoadingS__Array_x                                       0xBAA848

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5B8170
#define EQ_PC__GetAltAbilityIndex_x                                0x8186C0
#define EQ_PC__GetCombatAbility_x                                  0x818750
#define EQ_PC__GetCombatAbilityTimer_x                             0x813650
#define EQ_PC__GetItemTimerValue_x                                 0x5B1BB0
#define EQ_PC__HasLoreItem_x                                       0x5ABDD0
#define EQ_PC__AlertInventoryChanged_x                             0x5A8A40
#define EQ_PC__GetPcZoneClient_x                                   0x5D27A0
#define EQ_PC__RemoveMyAffect_x                                    0x5B10C0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5061B0
#define EQItemList__add_item_x                                     0x5060F0
#define EQItemList__delete_item_x                                  0x5065B0
#define EQItemList__FreeItemList_x                                 0x5064B0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A2AC0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5BD700
#define EQPlayer__dEQPlayer_x                                      0x5C6530
#define EQPlayer__DoAttack_x                                       0x5D8670
#define EQPlayer__EQPlayer_x                                       0x5C8950
#define EQPlayer__SetNameSpriteState_x                             0x5C3200
#define EQPlayer__SetNameSpriteTint_x                              0x5BEAD0
#define EQPlayer__IsBodyType_j_x                                   0x919F50
#define EQPlayer__IsTargetable_x                                   0x91A810
#define EQPlayer__CanSee_x                                         0x91AD30

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5CCD40
#define EQPlayerManager__GetSpawnByName_x                          0x5CD1A0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x58F150
#define KeypressHandler__AttachKeyToEqCommand_x                    0x58F190
#define KeypressHandler__ClearCommandStateArray_x                  0x58ED30
#define KeypressHandler__HandleKeyDown_x                           0x58D690
#define KeypressHandler__HandleKeyUp_x                             0x58D9B0
#define KeypressHandler__SaveKeymapping_x                          0x58EE00

// MapViewMap 
#define MapViewMap__Clear_x                                        0x700190
#define MapViewMap__SaveEx_x                                       0x703A70

#define PlayerPointManager__GetAltCurrency_x                       0x82B0D0

// StringTable 
#define StringTable__getString_x                                   0x825BE0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B6480

//Doors
#define EQSwitch__UseSwitch_x                                      0x544B10

//IconCache
#define IconCache__GetIcon_x                                       0x69AF10

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x691D90
#define CContainerMgr__CloseContainer_x                            0x6925B0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x761780

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5822A0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D6C30
#define EQ_Spell__SpellAffects_x                                   0x4D6CD0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D6D00
#define CharacterZoneClient__CalcAffectChange_x                    0x448160
#define CLootWnd__LootAll_x                                        0x6F5AF0
//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x74B690
#define CTargetWnd__WndNotification_x                              0x7A6A60

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7AC120

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D0BA0
