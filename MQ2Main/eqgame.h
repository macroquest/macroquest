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
#define __ExpectedVersionDate                                     "May 27 2015"
#define __ExpectedVersionTime                                     "18:23:40"
#define __ActualVersionDate_x                                      0xA7EF98
#define __ActualVersionTime_x                                      0xA7EFA4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x594E50
#define __MemChecker1_x                                            0x85E980
#define __MemChecker2_x                                            0x62D640
#define __MemChecker3_x                                            0x62D590
#define __MemChecker4_x                                            0x7E2A00
#define __EncryptPad0_x                                            0xBFD5A0
#define __EncryptPad1_x                                            0xD84F18
#define __EncryptPad2_x                                            0xC46EE8
#define __EncryptPad3_x                                            0xC46AE8
#define __EncryptPad4_x                                            0xD60F80
#define __AC1_x                                                    0x79FE25
#define __AC2_x                                                    0x54AE57
#define __AC3_x                                                    0x55F650
#define __AC4_x                                                    0x565A10
#define __AC5_x                                                    0x57183E
#define __AC6_x                                                    0x5752E9
#define __AC7_x                                                    0x56BEEC
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x1137000
#define DI8__Keyboard_x                                            0x1137004
#define DI8__Mouse_x                                               0x1137008
#define __AltTimerReady_x                                          0xF96971
#define __Attack_x                                                 0x1029B8F
#define __Autofire_x                                               0x1029B90
#define __BindList_x                                               0xBBF818
#define __bCommandEnabled_x                                        0xF94A80
#define __Clicks_x                                                 0xFA56E0
#define __CommandList_x                                            0xBC3B70
#define __CurrentMapLabel_x                                        0x113CA58
#define __CurrentSocial_x                                          0xB7AE7C
#define __DoAbilityList_x                                          0xFDBE44
#define __do_loot_x                                                0x512640
#define __DrawHandler_x                                            0x17A1664
#define __GroupCount_x                                             0xF9604A

#define __Guilds_x                                                 0xF9BC60
#define __gWorld_x                                                 0xF98504
#define __HotkeyPage_x                                             0x1022844
#define __HWnd_x                                                   0x102EF08
#define __InChatMode_x                                             0xFA560C
#define __LastTell_x                                               0xFA754C
#define __LMouseHeldTime_x                                         0xFA574C
#define __Mouse_x                                                  0x113700C
#define __MouseLook_x                                              0xFA56A6
#define __MouseEventTime_x                                         0x102A394
#define __gpbCommandEvent_x                                        0xF985CC
#define __NetStatusToggle_x                                        0xFA56A9
#define __PCNames_x                                                0xFA6B6C
#define __RangeAttackReady_x                                       0xFA6830
#define __RMouseHeldTime_x                                         0xFA5748
#define __RunWalkState_x                                           0xFA5610
#define __ScreenMode_x                                             0xEE48B8
#define __ScreenX_x                                                0xFA55C4
#define __ScreenY_x                                                0xFA55C0
#define __ScreenXMax_x                                             0xFA55C8
#define __ScreenYMax_x                                             0xFA55CC
#define __ServerHost_x                                             0xF95F94
#define __ServerName_x                                             0xFDBE04
#define __ShiftKeyDown_x                                           0xFA5CB4
#define __ShowNames_x                                              0xFA6A04
#define __Socials_x                                                0xFDBF04
#define __SubscriptionType_x                                       0x1168DE8
#define __TargetAggroHolder_x                                      0x113EC94
#define __GroupAggro_x                                             0x113ECD4
#define __LoginName_x                                              0x102DAE0
#define __Inviter_x                                                0x1029B0C


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF985F0
#define instEQZoneInfo_x                                           0xFA589C
#define instKeypressHandler_x                                      0x102A378
#define pinstActiveBanker_x                                        0xF985A8
#define pinstActiveCorpse_x                                        0xF985AC
#define pinstActiveGMaster_x                                       0xF985B0
#define pinstActiveMerchant_x                                      0xF985A4
#define pinstAggroInfo_x                                           0xDA8D38
#define pinstAltAdvManager_x                                       0xEE59A8
#define pinstAuraMgr_x                                             0xDB2C00
#define pinstBandageTarget_x                                       0xF98590
#define pinstCamActor_x                                            0xEE52B0
#define pinstCDBStr_x                                              0xEE484C
#define pinstCDisplay_x                                            0xF985B8
#define pinstCEverQuest_x                                          0x1137180
#define pinstCharData_x                                            0xF98574
#define pinstCharSpawn_x                                           0xF9859C
#define pinstControlledMissile_x                                   0xF98570
#define pinstControlledPlayer_x                                    0xF9859C
#define pinstCSidlManager_x                                        0x17A0A9C
#define pinstCXWndManager_x                                        0x17A0A94
#define instDynamicZone_x                                          0xFA5458
#define pinstDZMember_x                                            0xFA5568
#define pinstDZTimerInfo_x                                         0xFA556C
#define pinstEQItemList_x                                          0xF94CD0
#define instEQMisc_x                                               0xB9BAC0
#define pinstEQSoundManager_x                                      0xEE5E18
#define instExpeditionLeader_x                                     0xFA54A2
#define instExpeditionName_x                                       0xFA54E2
#define pinstGroup_x                                               0xF96046
#define pinstImeManager_x                                          0x17A0AA0
#define pinstLocalPlayer_x                                         0xF98588
#define pinstMercenaryData_x                                       0x102A9C8
#define pinstMercAltAbilities_x                                    0xEE5D34
#define pinstModelPlayer_x                                         0xF985B4
#define pinstPCData_x                                              0xF98574
#define pinstSkillMgr_x                                            0x102B800
#define pinstSpawnManager_x                                        0x102B0E8
#define pinstSpellManager_x                                        0x102B948
#define pinstSpellSets_x                                           0x10228A8
#define pinstStringTable_x                                         0xF9851C
#define pinstSwitchManager_x                                       0xF95BD8
#define pinstTarget_x                                              0xF985A0
#define pinstTargetObject_x                                        0xF98578
#define pinstTargetSwitch_x                                        0xF9857C
#define pinstTaskMember_x                                          0xEE4798
#define pinstTrackTarget_x                                         0xF98594
#define pinstTradeTarget_x                                         0xF98584
#define instTributeActive_x                                        0xB9BAE5
#define pinstViewActor_x                                           0xEE52AC
#define pinstWorldData_x                                           0xF98558


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xDA9218
#define pinstCAudioTriggersWindow_x                                0xDA90A8
#define pinstCCharacterSelect_x                                    0xEE514C
#define pinstCFacePick_x                                           0xEE4EFC
#define pinstCNoteWnd_x                                            0xEE5104
#define pinstCBookWnd_x                                            0xEE510C
#define pinstCPetInfoWnd_x                                         0xEE5110
#define pinstCTrainWnd_x                                           0xEE5114
#define pinstCSkillsWnd_x                                          0xEE5118
#define pinstCSkillsSelectWnd_x                                    0xEE511C
#define pinstCCombatSkillSelectWnd_x                               0xEE5120
#define pinstCFriendsWnd_x                                         0xEE5124
#define pinstCAuraWnd_x                                            0xEE5128
#define pinstCRespawnWnd_x                                         0xEE512C
#define pinstCBandolierWnd_x                                       0xEE5130
#define pinstCPotionBeltWnd_x                                      0xEE5134
#define pinstCAAWnd_x                                              0xEE5138
#define pinstCGroupSearchFiltersWnd_x                              0xEE513C
#define pinstCLoadskinWnd_x                                        0xEE5140
#define pinstCAlarmWnd_x                                           0xEE5144
#define pinstCMusicPlayerWnd_x                                     0xEE5148
#define pinstCMailWnd_x                                            0xEE5150
#define pinstCMailCompositionWnd_x                                 0xEE5154
#define pinstCMailAddressBookWnd_x                                 0xEE5158
#define pinstCRaidWnd_x                                            0xEE5160
#define pinstCRaidOptionsWnd_x                                     0xEE5164
#define pinstCBreathWnd_x                                          0xEE5168
#define pinstCMapViewWnd_x                                         0xEE516C
#define pinstCMapToolbarWnd_x                                      0xEE5170
#define pinstCEditLabelWnd_x                                       0xEE5174
#define pinstCTargetWnd_x                                          0xEE5178
#define pinstCColorPickerWnd_x                                     0xEE517C
#define pinstCPlayerWnd_x                                          0xEE5180
#define pinstCOptionsWnd_x                                         0xEE5184
#define pinstCBuffWindowNORMAL_x                                   0xEE5188
#define pinstCBuffWindowSHORT_x                                    0xEE518C
#define pinstCharacterCreation_x                                   0xEE5190
#define pinstCCursorAttachment_x                                   0xEE5194
#define pinstCCastingWnd_x                                         0xEE5198
#define pinstCCastSpellWnd_x                                       0xEE519C
#define pinstCSpellBookWnd_x                                       0xEE51A0
#define pinstCInventoryWnd_x                                       0xEE51A4
#define pinstCBankWnd_x                                            0xEE51A8
#define pinstCQuantityWnd_x                                        0xEE51AC
#define pinstCLootWnd_x                                            0xEE51B0
#define pinstCActionsWnd_x                                         0xEE51B4
#define pinstCCombatAbilityWnd_x                                   0xEE51B8
#define pinstCMerchantWnd_x                                        0xEE51BC
#define pinstCTradeWnd_x                                           0xEE51C0
#define pinstCSelectorWnd_x                                        0xEE51C4
#define pinstCBazaarWnd_x                                          0xEE51C8
#define pinstCBazaarSearchWnd_x                                    0xEE51CC
#define pinstCGiveWnd_x                                            0xEE51E8
#define pinstCTrackingWnd_x                                        0xEE51F0
#define pinstCInspectWnd_x                                         0xEE51F4
#define pinstCSocialEditWnd_x                                      0xEE51F8
#define pinstCFeedbackWnd_x                                        0xEE51FC
#define pinstCBugReportWnd_x                                       0xEE5200
#define pinstCVideoModesWnd_x                                      0xEE5204
#define pinstCTextEntryWnd_x                                       0xEE520C
#define pinstCFileSelectionWnd_x                                   0xEE5210
#define pinstCCompassWnd_x                                         0xEE5214
#define pinstCPlayerNotesWnd_x                                     0xEE5218
#define pinstCGemsGameWnd_x                                        0xEE521C
#define pinstCTimeLeftWnd_x                                        0xEE5220
#define pinstCPetitionQWnd_x                                       0xEE5234
#define pinstCSoulmarkWnd_x                                        0xEE5238
#define pinstCStoryWnd_x                                           0xEE523C
#define pinstCJournalTextWnd_x                                     0xEE5240
#define pinstCJournalCatWnd_x                                      0xEE5244
#define pinstCBodyTintWnd_x                                        0xEE5248
#define pinstCServerListWnd_x                                      0xEE524C
#define pinstCAvaZoneWnd_x                                         0xEE5258
#define pinstCBlockedBuffWnd_x                                     0xEE525C
#define pinstCBlockedPetBuffWnd_x                                  0xEE5260
#define pinstCInvSlotMgr_x                                         0xEE52A4
#define pinstCContainerMgr_x                                       0xEE52A8
#define pinstCAdventureLeaderboardWnd_x                            0x1137B30
#define pinstCAdventureRequestWnd_x                                0x1137BA8
#define pinstCAltStorageWnd_x                                      0x1137E88
#define pinstCAdventureStatsWnd_x                                  0x1137C20
#define pinstCBarterMerchantWnd_x                                  0x1138A70
#define pinstCBarterSearchWnd_x                                    0x1138AE8
#define pinstCBarterWnd_x                                          0x1138B60
#define pinstCChatManager_x                                        0x11391F0
#define pinstCDynamicZoneWnd_x                                     0x11396A0
#define pinstCEQMainWnd_x                                          0x1139838
#define pinstCFellowshipWnd_x                                      0x1139634
#define pinstCFindLocationWnd_x                                    0x1139B08
#define pinstCGroupSearchWnd_x                                     0x1139DD8
#define pinstCGroupWnd_x                                           0x1139E50
#define pinstCGuildBankWnd_x                                       0x1139EC8
#define pinstCGuildMgmtWnd_x                                       0x113BFB8
#define pinstCHotButtonWnd_x                                       0x113C084
#define pinstCHotButtonWnd1_x                                      0x113C084
#define pinstCHotButtonWnd2_x                                      0x113C088
#define pinstCHotButtonWnd3_x                                      0x113C08C
#define pinstCHotButtonWnd4_x                                      0x113C0B0
#define pinstCItemDisplayManager_x                                 0x113C3A8
#define pinstCItemExpTransferWnd_x                                 0x113C424
#define pinstCLFGuildWnd_x                                         0x113C700
#define pinstCMIZoneSelectWnd_x                                    0x113CCE8
#define pinstCConfirmationDialog_x                                 0x113D3F0
#define pinstCPopupWndManager_x                                    0x113D3F0
#define pinstCProgressionSelectionWnd_x                            0x113D4E0
#define pinstCPvPStatsWnd_x                                        0x113D5D0
#define pinstCSystemInfoDialogBox_x                                0x113DCD8
#define pinstCTaskWnd_x                                            0x113F0A0
#define pinstCTaskSomething_x                                      0xDB3340
#define pinstCTaskTemplateSelectWnd_x                              0x113F028
#define pinstCTipWndOFDAY_x                                        0x113F2F8
#define pinstCTipWndCONTEXT_x                                      0x113F2FC
#define pinstCTitleWnd_x                                           0x113F378
#define pinstCContextMenuManager_x                                 0x17A0A0C
#define pinstCVoiceMacroWnd_x                                      0x102BFB0
#define pinstCHtmlWnd_x                                            0x102C0A8
#define pinstIconCache_x                                           0x113980C
#define pinstCTradeskillWnd_x                                      0x113F478
#define pinstCAdvancedLootWnd_x                                    0xEE5298
#define pinstRewardSelectionWnd_x                                  0x113DAF8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x52A040
#define __ConvertItemTags_x                                        0x5172C0
#define __ExecuteCmd_x                                             0x501C90
#define __EQGetTime_x                                              0x85ECA0
#define __get_melee_range_x                                        0x508970
#define __GetGaugeValueFromEQ_x                                    0x79EB70
#define __GetLabelFromEQ_x                                         0x79FDB0
#define __ToggleMount_x                                            0x6C7EF0
#define __GetXTargetType_x                                         0x91D0F0
#define __LoadFrontEnd_x                                           0x62CCF0
#define __NewUIINI_x                                               0x79E480
#define __ProcessGameEvents_x                                      0x56DC50
#define __ProcessMouseEvent_x                                      0x56D3F0
#define CrashDetected_x                                            0x62E7C0
#define wwsCrashReportCheckForUploader_x                           0x7F3A20
#define DrawNetStatus_x                                            0x5A4A30
#define Util__FastTime_x                                           0x85E7F0
#define Expansion_HoT_x                                            0xFA699C
#define __HelpPath_x                                               0x102A100

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41ED10
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419B80

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C0A50
#define AltAdvManager__IsAbilityReady_x                            0x4C0AC0
#define AltAdvManager__GetAltAbility_x                             0x4C0E80

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x464870
#define CharacterZoneClient__MakeMeVisible_x                       0x4699A0
// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x65C710

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66A6B0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x583ED0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x685AB0
#define CChatManager__InitContextMenu_x                            0x6865D0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8CEF70
#define CContextMenu__dCContextMenu_x                              0x8CF170
#define CContextMenu__AddMenuItem_x                                0x8CF180
#define CContextMenu__RemoveMenuItem_x                             0x8CF460
#define CContextMenu__RemoveAllMenuItems_x                         0x8CF480
#define CContextMenuManager__AddMenu_x                             0x8BAEF0
#define CContextMenuManager__RemoveMenu_x                          0x8BB220
#define CContextMenuManager__PopupMenu_x                           0x8BB670
#define CContextMenuManager__Flush_x                               0x8BAF60
#define CContextMenuManager__GetMenu_x                             0x4151F0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8453B0
#define CChatService__GetFriendName_x                              0x8453C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x68B640
#define CChatWindow__Clear_x                                       0x68B1F0
#define CChatWindow__WndNotification_x                             0x68BB70

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8BEDC0
#define CComboWnd__Draw_x                                          0x8BEFD0
#define CComboWnd__GetCurChoice_x                                  0x8BEB90
#define CComboWnd__GetListRect_x                                   0x8BF270
#define CComboWnd__GetTextRect_x                                   0x8BEE30
#define CComboWnd__InsertChoice_x                                  0x8BF2E0
#define CComboWnd__SetColors_x                                     0x8BEB20
#define CComboWnd__SetChoice_x                                     0x8BEB50
#define CComboWnd__GetItemCount_x                                  0x8BEB80

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x694D70
#define CContainerWnd__vftable_x                                   0xA886F8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4AED50
#define CDisplay__GetClickedActor_x                                0x4A78D0
#define CDisplay__GetUserDefinedColor_x                            0x4A6190
#define CDisplay__GetWorldFilePath_x                               0x4A55E0
#define CDisplay__is3dON_x                                         0x4A49B0
#define CDisplay__ReloadUI_x                                       0x4BA220
#define CDisplay__WriteTextHD2_x                                   0x4AB0F0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E54A0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D38A0
#define CEditWnd__GetCharIndexPt_x                                 0x8D4920
#define CEditWnd__GetDisplayString_x                               0x8D3A50
#define CEditWnd__GetHorzOffset_x                                  0x8D3D90
#define CEditWnd__GetLineForPrintableChar_x                        0x8D43F0
#define CEditWnd__GetSelStartPt_x                                  0x8D4BD0
#define CEditWnd__GetSTMLSafeText_x                                0x8D3F20
#define CEditWnd__PointFromPrintableChar_x                         0x8D44E0
#define CEditWnd__SelectableCharFromPoint_x                        0x8D4660
#define CEditWnd__SetEditable_x                                    0x8D3EF0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x54B5A0
#define CEverQuest__DoTellWindow_x                                 0x550FA0
#define CEverQuest__DropHeldItemOnGround_x                         0x559AD0
#define CEverQuest__dsp_chat_x                                     0x552740
#define CEverQuest__Emote_x                                        0x5529A0
#define CEverQuest__EnterZone_x                                    0x566230
#define CEverQuest__GetBodyTypeDesc_x                              0x547E00
#define CEverQuest__GetClassDesc_x                                 0x54DB10
#define CEverQuest__GetClassThreeLetterCode_x                      0x54E110
#define CEverQuest__GetDeityDesc_x                                 0x5486E0
#define CEverQuest__GetLangDesc_x                                  0x548190
#define CEverQuest__GetRaceDesc_x                                  0x54E2D0
#define CEverQuest__InterpretCmd_x                                 0x553280
#define CEverQuest__LeftClickedOnPlayer_x                          0x56A350
#define CEverQuest__LMouseUp_x                                     0x56C440
#define CEverQuest__RightClickedOnPlayer_x                         0x56AE50
#define CEverQuest__RMouseUp_x                                     0x56BEA0
#define CEverQuest__SetGameState_x                                 0x54BC50
#define CEverQuest__UPCNotificationFlush_x                         0x554420
#define CEverQuest__IssuePetCommand_x                              0x553F80

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A5880
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A58E0
#define CGaugeWnd__Draw_x                                          0x6A5D10

// CGuild
#define CGuild__FindMemberByName_x                                 0x435A50

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C2930

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D0720
#define CInvSlotMgr__MoveItem_x                                    0x6D1650
#define CInvSlotMgr__SelectSlot_x                                  0x6D07D0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6CFBC0
#define CInvSlot__SliderComplete_x                                 0x6CD580
#define CInvSlot__GetItemBase_x                                    0x6CCA00

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D2810

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79B680
#define CItemDisplayWnd__UpdateStrings_x                           0x6D3B80

// CLabel 
#define CLabel__Draw_x                                             0x6EE940

// CListWnd
#define CListWnd__CListWnd_x                                       0x8AACA0
#define CListWnd__dCListWnd_x                                      0x8ABCC0
#define CListWnd__AddColumn_x                                      0x8ABC60
#define CListWnd__AddColumn1_x                                     0x8AB4E0
#define CListWnd__AddLine_x                                        0x8AAF60
#define CListWnd__AddString_x                                      0x8AB170
#define CListWnd__CalculateFirstVisibleLine_x                      0x8A8000
#define CListWnd__CalculateVSBRange_x                              0x8AA150
#define CListWnd__ClearAllSel_x                                    0x8A72E0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8AAB30
#define CListWnd__Compare_x                                        0x8A8AE0
#define CListWnd__Draw_x                                           0x8A9D60
#define CListWnd__DrawColumnSeparators_x                           0x8A9BF0
#define CListWnd__DrawHeader_x                                     0x8A75F0
#define CListWnd__DrawItem_x                                       0x8A9130
#define CListWnd__DrawLine_x                                       0x8A9890
#define CListWnd__DrawSeparator_x                                  0x8A9C90
#define CListWnd__EnsureVisible_x                                  0x8A8160
#define CListWnd__ExtendSel_x                                      0x8A9040
#define CListWnd__GetColumnMinWidth_x                              0x8A6CA0
#define CListWnd__GetColumnWidth_x                                 0x8A6BC0
#define CListWnd__GetCurSel_x                                      0x8A6390
#define CListWnd__GetItemAtPoint_x                                 0x8A83F0
#define CListWnd__GetItemAtPoint1_x                                0x8A8460
#define CListWnd__GetItemData_x                                    0x8A66D0
#define CListWnd__GetItemHeight_x                                  0x8A7C70
#define CListWnd__GetItemIcon_x                                    0x8A68B0
#define CListWnd__GetItemRect_x                                    0x8A8230
#define CListWnd__GetItemText_x                                    0x8A6760
#define CListWnd__GetSelList_x                                     0x8AB3D0
#define CListWnd__GetSeparatorRect_x                               0x8A8A10
#define CListWnd__RemoveLine_x                                     0x8AB350
#define CListWnd__SetColors_x                                      0x8A64E0
#define CListWnd__SetColumnJustification_x                         0x8A6F70
#define CListWnd__SetColumnWidth_x                                 0x8A6C50
#define CListWnd__SetCurSel_x                                      0x8A63D0
#define CListWnd__SetItemColor_x                                   0x8AA810
#define CListWnd__SetItemData_x                                    0x8A7390
#define CListWnd__SetItemText_x                                    0x8AA650
#define CListWnd__ShiftColumnSeparator_x                           0x8AA4E0
#define CListWnd__Sort_x                                           0x8ABDC0
#define CListWnd__ToggleSel_x                                      0x8A7260

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x707F30

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7290F0
#define CMerchantWnd__RequestBuyItem_x                             0x72FF10
#define CMerchantWnd__RequestSellItem_x                            0x730960
#define CMerchantWnd__SelectRecoverySlot_x                         0x7293A0
#define CMerchantWnd__SelectBuySellSlot_x                          0x728600
#define CMerchantWnd__ActualSelect_x                               0x72CE40

// CObfuscator
#define CObfuscator__doit_x                                        0x8255C0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8C9ED0
#define CSidlManager__CreateLabel_x                                0x791670

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x653990
#define CSidlScreenWnd__CalculateVSBRange_x                        0x6538B0
#define CSidlScreenWnd__ConvertToRes_x                             0x8E5380
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8C1A40
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C2F40
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C2FF0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C24C0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8C13F0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8C0B50
#define CSidlScreenWnd__GetSidlPiece_x                             0x8C15E0
#define CSidlScreenWnd__Init1_x                                    0x8C2C20
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C1AF0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8C0D10
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C2710
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C0610
#define CSidlScreenWnd__StoreIniVis_x                              0x8C0AE0
#define CSidlScreenWnd__WndNotification_x                          0x8C29A0
#define CSidlScreenWnd__GetChildItem_x                             0x8C0C20
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B4180

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5EEE80
#define CSkillMgr__GetSkillCap_x                                   0x5EF020
#define CSkillMgr__GetNameToken_x                                  0x5EEAF0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E4640
#define CSliderWnd__SetValue_x                                     0x8E4810
#define CSliderWnd__SetNumTicks_x                                  0x8E4F90

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x799320

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8DF050
#define CStmlWnd__CalculateHSBRange_x                              0x8D75A0
#define CStmlWnd__CalculateVSBRange_x                              0x8D7630
#define CStmlWnd__CanBreakAtCharacter_x                            0x8D77B0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8D8090
#define CStmlWnd__ForceParseNow_x                                  0x8DF9A0
#define CStmlWnd__GetNextTagPiece_x                                0x8D7F90
#define CStmlWnd__GetSTMLText_x                                    0x68AA90
#define CStmlWnd__GetVisibleText_x                                 0x8D8AE0
#define CStmlWnd__InitializeWindowVariables_x                      0x8DAE50
#define CStmlWnd__MakeStmlColorTag_x                               0x8D68A0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D6900
#define CStmlWnd__SetSTMLText_x                                    0x8DC6B0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8DECF0
#define CStmlWnd__UpdateHistoryString_x                            0x8D9A10

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E6C40
#define CTabWnd__DrawCurrentPage_x                                 0x8E64B0
#define CTabWnd__DrawTab_x                                         0x8E6280
#define CTabWnd__GetCurrentPage_x                                  0x8E6880
#define CTabWnd__GetPageInnerRect_x                                0x8E5F70
#define CTabWnd__GetTabInnerRect_x                                 0x8E6170
#define CTabWnd__GetTabRect_x                                      0x8E6040
#define CTabWnd__InsertPage_x                                      0x8E6F30
#define CTabWnd__SetPage_x                                         0x8E68B0
#define CTabWnd__SetPageRect_x                                     0x8E6B80
#define CTabWnd__UpdatePage_x                                      0x8E6ED0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431870

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8BE790

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8EBE80

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A4640

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4022B0
#define CXStr__CXStr1_x                                            0x899D30
#define CXStr__CXStr3_x                                            0x85B880
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x85B9F0
#define CXStr__operator_equal1_x                                   0x85BA40
#define CXStr__operator_plus_equal1_x                              0x85CB20

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B3430
#define CXWnd__Center_x                                            0x8B9530
#define CXWnd__ClrFocus_x                                          0x8B3010
#define CXWnd__DoAllDrawing_x                                      0x8B9180
#define CXWnd__DrawChildren_x                                      0x8B9320
#define CXWnd__DrawColoredRect_x                                   0x8B37C0
#define CXWnd__DrawTooltip_x                                       0x8B3A60
#define CXWnd__DrawTooltipAtPoint_x                                0x8B8120
#define CXWnd__GetBorderFrame_x                                    0x8B3E70
#define CXWnd__GetChildWndAt_x                                     0x8B9F00
#define CXWnd__GetClientClipRect_x                                 0x8B3C80
#define CXWnd__GetScreenClipRect_x                                 0x8B8810
#define CXWnd__GetScreenRect_x                                     0x8B4020
#define CXWnd__GetTooltipRect_x                                    0x8B38F0
#define CXWnd__GetWindowTextA_x                                    0x422D50
#define CXWnd__IsActive_x                                          0x8AEAA0
#define CXWnd__IsDescendantOf_x                                    0x8B3DC0
#define CXWnd__IsReallyVisible_x                                   0x8B7170
#define CXWnd__IsType_x                                            0x8E8610
#define CXWnd__Move_x                                              0x8B6850
#define CXWnd__Move1_x                                             0x8B8E20
#define CXWnd__ProcessTransition_x                                 0x8B33D0
#define CXWnd__Refade_x                                            0x8B33D0
#define CXWnd__Resize_x                                            0x8B40E0
#define CXWnd__Right_x                                             0x8B8610
#define CXWnd__SetFocus_x                                          0x8B59B0
#define CXWnd__SetFont_x                                           0x8B3060
#define CXWnd__SetKeyTooltip_x                                     0x8B4350
#define CXWnd__SetMouseOver_x                                      0x8B8B30
#define CXWnd__StartFade_x                                         0x8B3480
#define CXWnd__GetChildItem_x                                      0x8B8A80

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B0390
#define CXWndManager__DrawWindows_x                                0x8AFFE0
#define CXWndManager__GetKeyboardFlags_x                           0x8AE610
#define CXWndManager__HandleKeyboardMsg_x                          0x8AEF30
#define CXWndManager__RemoveWnd_x                                  0x8AEC30

// CDBStr
#define CDBStr__GetString_x                                        0x4A2DC0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44EC20
#define EQ_Character__Cur_HP_x                                     0x463F40
#define EQ_Character__GetAACastingTimeModifier_x                   0x446C90
#define EQ_Character__GetCharInfo2_x                               0x82FE00
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EE40
#define EQ_Character__GetFocusRangeModifier_x                      0x43F020
#define EQ_Character__Max_Endurance_x                              0x5B6AA0
#define EQ_Character__Max_HP_x                                     0x459BB0
#define EQ_Character__Max_Mana_x                                   0x5B68D0
#define EQ_Character__doCombatAbility_x                            0x5B3EC0
#define EQ_Character__UseSkill_x                                   0x46EBA0
#define EQ_Character__GetConLevel_x                                0x5A9050
#define EQ_Character__IsExpansionFlag_x                            0x422290
#define EQ_Character__TotalEffect_x                                0x44BDA0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x589610
#define EQ_Item__CreateItemTagString_x                             0x80F2A0
#define EQ_Item__IsStackable_x                                     0x803600
#define EQ_Item__GetImageNum_x                                     0x806380

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C2BC0
#define EQ_LoadingS__Array_x                                       0xBA9848

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5B8240
#define EQ_PC__GetAltAbilityIndex_x                                0x8182E0
#define EQ_PC__GetCombatAbility_x                                  0x818370
#define EQ_PC__GetCombatAbilityTimer_x                             0x818420
#define EQ_PC__GetItemTimerValue_x                                 0x5B1CA0
#define EQ_PC__HasLoreItem_x                                       0x5AC390
#define EQ_PC__AlertInventoryChanged_x                             0x5A9020
#define EQ_PC__GetPcZoneClient_x                                   0x5D2780
#define EQ_PC__RemoveMyAffect_x									   0x5B11B0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x506940
#define EQItemList__add_item_x                                     0x506880
#define EQItemList__delete_item_x                                  0x506D40
#define EQItemList__FreeItemList_x                                 0x506C40

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A20C0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5BD7E0
#define EQPlayer__dEQPlayer_x                                      0x5C6600
#define EQPlayer__DoAttack_x                                       0x5D8650
#define EQPlayer__EQPlayer_x                                       0x5C8A20
#define EQPlayer__SetNameSpriteState_x                             0x5C32E0
#define EQPlayer__SetNameSpriteTint_x                              0x5BEBB0
#define EQPlayer__IsBodyType_j_x                                   0x919320
#define EQPlayer__IsTargetable_x                                   0x919BE0
#define EQPlayer__CanSee_x                                         0x91A100

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5CCD90
#define EQPlayerManager__GetSpawnByName_x                          0x5CD1F0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x58F7D0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x58F810
#define KeypressHandler__ClearCommandStateArray_x                  0x58F3B0
#define KeypressHandler__HandleKeyDown_x                           0x58DD10
#define KeypressHandler__HandleKeyUp_x                             0x58E030
#define KeypressHandler__SaveKeymapping_x                          0x58F480

// MapViewMap 
#define MapViewMap__Clear_x                                        0x700310
#define MapViewMap__SaveEx_x                                       0x703BF0

#define PlayerPointManager__GetAltCurrency_x                       0x82ADA0

// StringTable 
#define StringTable__getString_x                                   0x825860

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B6550

//Doors
#define EQSwitch__UseSwitch_x                                      0x5451C0

//IconCache
#define IconCache__GetIcon_x                                       0x69B1D0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x692090
#define CContainerMgr__CloseContainer_x                            0x6928B0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x761960

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x582980

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D6120
#define EQ_Spell__SpellAffects_x                                   0x4D61C0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D61F0
#define CharacterZoneClient__CalcAffectChange_x                    0x447FB0
#define CLootWnd__LootAll_x                                        0x6F5C40

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7A70E0
#define CTargetWnd__WndNotification_x                              0x7A6BD0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7AC290

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4CFA60

