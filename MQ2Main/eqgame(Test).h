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
#define __ExpectedVersionDate                                     "Oct 23 2015"
#define __ExpectedVersionTime                                     "11:33:07"
#define __ActualVersionDate_x                                      0xAD0E40
#define __ActualVersionTime_x                                      0xAD0E4C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x599350
#define __MemChecker1_x                                            0x89AD90
#define __MemChecker2_x                                            0x6322D0
#define __MemChecker3_x                                            0x632220
#define __MemChecker4_x                                            0x7E7F00
#define __EncryptPad0_x                                            0xC67FE8
#define __EncryptPad1_x                                            0xDF1D98
#define __EncryptPad2_x                                            0xCB1AD0
#define __EncryptPad3_x                                            0xCB16D0
#define __EncryptPad4_x                                            0xDCC248
#define __EncryptPad5_x                                            0x119DB00
#define __AC1_x                                                    0x7A51B5
#define __AC2_x                                                    0x54E987
#define __AC3_x                                                    0x563140
#define __AC4_x                                                    0x569DC0
#define __AC5_x                                                    0x575C4E
#define __AC6_x                                                    0x5796F9
#define __AC7_x                                                    0x5702FC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data                                                 0x845E8

// Direct Input
#define DI8__Main_x                                                0x119DAD8
#define DI8__Keyboard_x                                            0x119DADC
#define DI8__Mouse_x                                               0x119DAE0
#define DI8__Mouse_Copy_x                                          0x100C0F4
#define DI8__Mouse_Check_x                                         0x10959C4
#define __AltTimerReady_x                                          0xFFD441
#define __Attack_x                                                 0x1090663
#define __Autofire_x                                               0x1090664
#define __BindList_x                                               0xC2A0E0
#define __bCommandEnabled_x                                        0xFFB550
#define __Clicks_x                                                 0x100C1B0
#define __CommandList_x                                            0xC2E450
#define __CurrentMapLabel_x                                        0x11A3530
#define __CurrentSocial_x                                          0xBE3F44
#define __DoAbilityList_x                                          0x1042918
#define __do_loot_x                                                0x515FA0
#define __DrawHandler_x                                            0x180A27C
#define __GroupCount_x                                             0xFFCB1A

#define __Guilds_x                                                 0x1002730
#define __gWorld_x                                                 0xFFEFD4
#define __HotkeyPage_x                                             0x1089318
#define __HWnd_x                                                   0x10959E0
#define __InChatMode_x                                             0x100C0DC
#define __LastTell_x                                               0x100E020
#define __LMouseHeldTime_x                                         0x100C21C
#define __Mouse_x                                                  0x119DAE4
#define __MouseLook_x                                              0x100C176
#define __MouseEventTime_x                                         0x1090E6C
#define __gpbCommandEvent_x                                        0xFFF09C
#define __NetStatusToggle_x                                        0x100C179
#define __PCNames_x                                                0x100D640
#define __RangeAttackReady_x                                       0x100D300
#define __RMouseHeldTime_x                                         0x100C218
#define __RunWalkState_x                                           0x100C0E0
#define __ScreenMode_x                                             0xF4B308
#define __ScreenX_x                                                0x100C094
#define __ScreenY_x                                                0x100C090
#define __ScreenXMax_x                                             0x100C098
#define __ScreenYMax_x                                             0x100C09C
#define __ServerHost_x                                             0xFFCA64
#define __ServerName_x                                             0x10428D8
#define __ShiftKeyDown_x                                           0x100C784
#define __ShowNames_x                                              0x100D4D4
#define __Socials_x                                                0x10429D8
#define __SubscriptionType_x                                       0x11D1A60
#define __TargetAggroHolder_x                                      0x11A576C
#define __GroupAggro_x                                             0x11A57AC
#define __LoginName_x                                              0x10945B8
#define __Inviter_x                                                0x10905E0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xFFF0C0
#define instEQZoneInfo_x                                           0x100C36C
#define instKeypressHandler_x                                      0x1090E50
#define pinstActiveBanker_x                                        0xFFF078
#define pinstActiveCorpse_x                                        0xFFF07C
#define pinstActiveGMaster_x                                       0xFFF080
#define pinstActiveMerchant_x                                      0xFFF074
#define pinstAggroInfo_x                                           0xE0D778
#define pinstAltAdvManager_x                                       0xF4C408
#define pinstAuraMgr_x                                             0xE19648
#define pinstBandageTarget_x                                       0xFFF060
#define pinstCamActor_x                                            0xF4BD10
#define pinstCDBStr_x                                              0xF4B29C
#define pinstCDisplay_x                                            0xFFF088
#define pinstCEverQuest_x                                          0x119DC58
#define pinstCharData_x                                            0xFFF044
#define pinstCharSpawn_x                                           0xFFF06C
#define pinstControlledMissile_x                                   0xFFF040
#define pinstControlledPlayer_x                                    0xFFF06C
#define pinstCSidlManager_x                                        0x18096B4
#define pinstCXWndManager_x                                        0x18096AC
#define instDynamicZone_x                                          0x100BF28
#define pinstDZMember_x                                            0x100C038
#define pinstDZTimerInfo_x                                         0x100C03C
#define pinstEQItemList_x                                          0xFFB7A0
#define instEQMisc_x                                               0xC04C48
#define pinstEQSoundManager_x                                      0xF4C8E8
#define instExpeditionLeader_x                                     0x100BF72
#define instExpeditionName_x                                       0x100BFB2
#define pinstGroup_x                                               0xFFCB16
#define pinstImeManager_x                                          0x18096B8
#define pinstLocalPlayer_x                                         0xFFF058
#define pinstMercenaryData_x                                       0x10914A0
#define pinstMercenaryStats_x                                      0x11A58B8
#define pinstMercAltAbilities_x                                    0xF4C790
#define pinstModelPlayer_x                                         0xFFF084
#define pinstPCData_x                                              0xFFF044
#define pinstSkillMgr_x                                            0x10922D8
#define pinstSpawnManager_x                                        0x1091BC0
#define pinstSpellManager_x                                        0x1092420
#define pinstSpellSets_x                                           0x108937C
#define pinstStringTable_x                                         0xFFEFEC
#define pinstSwitchManager_x                                       0xFFC6A8
#define pinstTarget_x                                              0xFFF070
#define pinstTargetObject_x                                        0xFFF048
#define pinstTargetSwitch_x                                        0xFFF04C
#define pinstTaskMember_x                                          0xF4B1E8
#define pinstTrackTarget_x                                         0xFFF064
#define pinstTradeTarget_x                                         0xFFF054
#define instTributeActive_x                                        0xC04C6D
#define pinstViewActor_x                                           0xF4BD0C
#define pinstWorldData_x                                           0xFFF028
#define pinstZoneAddr_x                                            0x100C62C

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE0DC58
#define pinstCAudioTriggersWindow_x                                0xE0DAE8
#define pinstCCharacterSelect_x                                    0xF4BBA8
#define pinstCFacePick_x                                           0xF4BB58
#define pinstCNoteWnd_x                                            0xF4BB60
#define pinstCBookWnd_x                                            0xF4BB68
#define pinstCPetInfoWnd_x                                         0xF4BB6C
#define pinstCTrainWnd_x                                           0xF4BB70
#define pinstCSkillsWnd_x                                          0xF4BB74
#define pinstCSkillsSelectWnd_x                                    0xF4BB78
#define pinstCCombatSkillsSelectWnd_x                              0xF4BB7C
#define pinstCFriendsWnd_x                                         0xF4BB80
#define pinstCAuraWnd_x                                            0xF4BB84
#define pinstCRespawnWnd_x                                         0xF4BB88
#define pinstCBandolierWnd_x                                       0xF4BB8C
#define pinstCPotionBeltWnd_x                                      0xF4BB90
#define pinstCAAWnd_x                                              0xF4BB94
#define pinstCGroupSearchFiltersWnd_x                              0xF4BB98
#define pinstCLoadskinWnd_x                                        0xF4BB9C
#define pinstCAlarmWnd_x                                           0xF4BBA0
#define pinstCMusicPlayerWnd_x                                     0xF4BBA4
#define pinstCMailWnd_x                                            0xF4BBAC
#define pinstCMailCompositionWnd_x                                 0xF4BBB0
#define pinstCMailAddressBookWnd_x                                 0xF4BBB4
#define pinstCRaidWnd_x                                            0xF4BBBC
#define pinstCRaidOptionsWnd_x                                     0xF4BBC0
#define pinstCBreathWnd_x                                          0xF4BBC4
#define pinstCMapViewWnd_x                                         0xF4BBC8
#define pinstCMapToolbarWnd_x                                      0xF4BBCC
#define pinstCEditLabelWnd_x                                       0xF4BBD0
#define pinstCTargetWnd_x                                          0xF4BBD4
#define pinstCColorPickerWnd_x                                     0xF4BBD8
#define pinstCPlayerWnd_x                                          0xF4BBDC
#define pinstCOptionsWnd_x                                         0xF4BBE0
#define pinstCBuffWindowNORMAL_x                                   0xF4BBE4
#define pinstCBuffWindowSHORT_x                                    0xF4BBE8
#define pinstCharacterCreation_x                                   0xF4BBEC
#define pinstCCursorAttachment_x                                   0xF4BBF0
#define pinstCCastingWnd_x                                         0xF4BBF4
#define pinstCCastSpellWnd_x                                       0xF4BBF8
#define pinstCSpellBookWnd_x                                       0xF4BBFC
#define pinstCInventoryWnd_x                                       0xF4BC00
#define pinstCBankWnd_x                                            0xF4BC04
#define pinstCQuantityWnd_x                                        0xF4BC08
#define pinstCLootWnd_x                                            0xF4BC0C
#define pinstCActionsWnd_x                                         0xF4BC10
#define pinstCCombatAbilityWnd_x                                   0xF4BC14
#define pinstCMerchantWnd_x                                        0xF4BC18
#define pinstCTradeWnd_x                                           0xF4BC1C
#define pinstCSelectorWnd_x                                        0xF4BC20
#define pinstCBazaarWnd_x                                          0xF4BC24
#define pinstCBazaarSearchWnd_x                                    0xF4BC28
#define pinstCGiveWnd_x                                            0xF4BC44
#define pinstCTrackingWnd_x                                        0xF4BC4C
#define pinstCInspectWnd_x                                         0xF4BC50
#define pinstCSocialEditWnd_x                                      0xF4BC54
#define pinstCFeedbackWnd_x                                        0xF4BC58
#define pinstCBugReportWnd_x                                       0xF4BC5C
#define pinstCVideoModesWnd_x                                      0xF4BC60
#define pinstCTextEntryWnd_x                                       0xF4BC68
#define pinstCFileSelectionWnd_x                                   0xF4BC6C
#define pinstCCompassWnd_x                                         0xF4BC70
#define pinstCPlayerNotesWnd_x                                     0xF4BC74
#define pinstCGemsGameWnd_x                                        0xF4BC78
#define pinstCTimeLeftWnd_x                                        0xF4BC7C
#define pinstCPetitionQWnd_x                                       0xF4BC94
#define pinstCSoulmarkWnd_x                                        0xF4BC98
#define pinstCStoryWnd_x                                           0xF4BC9C
#define pinstCJournalTextWnd_x                                     0xF4BCA0
#define pinstCJournalCatWnd_x                                      0xF4BCA4
#define pinstCBodyTintWnd_x                                        0xF4BCA8
#define pinstCServerListWnd_x                                      0xF4BCAC
#define pinstCAvaZoneWnd_x                                         0xF4BCB8
#define pinstCBlockedBuffWnd_x                                     0xF4BCBC
#define pinstCBlockedPetBuffWnd_x                                  0xF4BCC0
#define pinstCInvSlotMgr_x                                         0xF4BD04
#define pinstCContainerMgr_x                                       0xF4BD08
#define pinstCAdventureLeaderboardWnd_x                            0x119E608
#define pinstCAdventureRequestWnd_x                                0x119E680
#define pinstCAltStorageWnd_x                                      0x119E960
#define pinstCAdventureStatsWnd_x                                  0x119E6F8
#define pinstCBarterMerchantWnd_x                                  0x119F548
#define pinstCBarterSearchWnd_x                                    0x119F5C0
#define pinstCBarterWnd_x                                          0x119F638
#define pinstCChatManager_x                                        0x119FCC8
#define pinstCDynamicZoneWnd_x                                     0x11A0178
#define pinstCEQMainWnd_x                                          0x11A0310
#define pinstCFellowshipWnd_x                                      0x11A010C
#define pinstCFindLocationWnd_x                                    0x11A05E0
#define pinstCGroupSearchWnd_x                                     0x11A08B0
#define pinstCGroupWnd_x                                           0x11A0928
#define pinstCGuildBankWnd_x                                       0x11A09A0
#define pinstCGuildMgmtWnd_x                                       0x11A2A90
#define pinstCHotButtonWnd_x                                       0x11A2B5C
#define pinstCHotButtonWnd1_x                                      0x11A2B5C
#define pinstCHotButtonWnd2_x                                      0x11A2B60
#define pinstCHotButtonWnd3_x                                      0x11A2B64
#define pinstCHotButtonWnd4_x                                      0x11A2B88
#define pinstCItemDisplayManager_x                                 0x11A2E80
#define pinstCItemExpTransferWnd_x                                 0x11A2EFC
#define pinstCLFGuildWnd_x                                         0x11A31D8
#define pinstCMIZoneSelectWnd_x                                    0x11A37C0
#define pinstCConfirmationDialog_x                                 0x11A3EC8
#define pinstCPopupWndManager_x                                    0x11A3EC8
#define pinstCProgressionSelectionWnd_x                            0x11A3FB8
#define pinstCPvPStatsWnd_x                                        0x11A40A8
#define pinstCSystemInfoDialogBox_x                                0x11A47B0
#define pinstCTaskWnd_x                                            0x11A5B78
#define pinstCTaskSomething_x                                      0xE19D90
#define pinstCTaskTemplateSelectWnd_x                              0x11A5B00
#define pinstCTipWndOFDAY_x                                        0x11A5DD0
#define pinstCTipWndCONTEXT_x                                      0x11A5DD4
#define pinstCTitleWnd_x                                           0x11A5E50
#define pinstCContextMenuManager_x                                 0x1809624
#define pinstCVoiceMacroWnd_x                                      0x1092A88
#define pinstCHtmlWnd_x                                            0x1092B80
#define pinstIconCache_x                                           0x11A02E4
#define pinstCTradeskillWnd_x                                      0x11A5F50
#define pinstCAdvancedLootWnd_x                                    0xF4BCF8
#define pinstRewardSelectionWnd_x                                  0x11A45D0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x52DAC0
#define __ConvertItemTags_x                                        0x51AC20
#define __ExecuteCmd_x                                             0x505700
#define __EQGetTime_x                                              0x89B0F0
#define __get_melee_range_x                                        0x50C3E0
#define __GetGaugeValueFromEQ_x                                    0x7A3EF0
#define __GetLabelFromEQ_x                                         0x7A5140
#define __ToggleMount_x                                            0x6CD000
#define __GetXTargetType_x                                         0x92C410
#define __LoadFrontEnd_x                                           0x631980
#define __NewUIINI_x                                               0x7A37F0
#define __ProcessGameEvents_x                                      0x572060
#define __ProcessMouseEvent_x                                      0x571800
#define CrashDetected_x                                            0x633450
#define wwsCrashReportCheckForUploader_x                           0x7F7A50
#define DrawNetStatus_x                                            0x5A8D20
#define Util__FastTime_x                                           0x89AA40
#define Expansion_HoT_x                                            0x100D46C
#define __HelpPath_x                                               0x1090BD8
#define __STMLToText_x                                             0x8DFBE0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41F0B0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419F00

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C2070
#define AltAdvManager__IsAbilityReady_x                            0x4C20E0
#define AltAdvManager__GetAAById_x                                 0x4C24A0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4640B0
#define CharacterZoneClient__MakeMeVisible_x                       0x469A90
#define CharacterZoneClient__IsStackBlocked_x                      0x446560

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x661380

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66F940

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x588440

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68A810
#define CChatManager__InitContextMenu_x                            0x68B390

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DDF40
#define CContextMenu__AddMenuItem_x                                0x8DE160
#define CContextMenu__dCContextMenu_x                              0x8DE150
#define CContextMenu__RemoveMenuItem_x                             0x8DE450
#define CContextMenu__RemoveAllMenuItems_x                         0x8DE470
#define CContextMenuManager__AddMenu_x                             0x8C9E40
#define CContextMenuManager__RemoveMenu_x                          0x8CA180
#define CContextMenuManager__PopupMenu_x                           0x8CA5D0
#define CContextMenuManager__Flush_x                               0x8C9EB0
#define CContextMenuManager__GetMenu_x                             0x415550

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x881020
#define CChatService__GetFriendName_x                              0x881030

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x690640
#define CChatWindow__Clear_x                                       0x6901F0
#define CChatWindow__WndNotification_x                             0x690B80

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CDD40
#define CComboWnd__Draw_x                                          0x8CDF50
#define CComboWnd__GetCurChoice_x                                  0x8CDB10
#define CComboWnd__GetListRect_x                                   0x8CE1F0
#define CComboWnd__GetTextRect_x                                   0x8CDDB0
#define CComboWnd__InsertChoice_x                                  0x8CE260
#define CComboWnd__SetColors_x                                     0x8CDAA0
#define CComboWnd__SetChoice_x                                     0x8CDAD0
#define CComboWnd__GetItemCount_x                                  0x8CDB00

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x699E00
#define CContainerWnd__vftable_x                                   0xADA7D8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B0210
#define CDisplay__GetClickedActor_x                                0x4A8D90
#define CDisplay__GetUserDefinedColor_x                            0x4A7650
#define CDisplay__GetWorldFilePath_x                               0x4A6AA0
#define CDisplay__is3dON_x                                         0x4A5E70
#define CDisplay__ReloadUI_x                                       0x4BB730
#define CDisplay__WriteTextHD2_x                                   0x4AC5B0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F4600

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E2990
#define CEditWnd__GetCharIndexPt_x                                 0x8E3A30
#define CEditWnd__GetDisplayString_x                               0x8E2B40
#define CEditWnd__GetHorzOffset_x                                  0x8E2E80
#define CEditWnd__GetLineForPrintableChar_x                        0x8E34F0
#define CEditWnd__GetSelStartPt_x                                  0x8E3CF0
#define CEditWnd__GetSTMLSafeText_x                                0x8E3020
#define CEditWnd__PointFromPrintableChar_x                         0x8E35E0
#define CEditWnd__SelectableCharFromPoint_x                        0x8E3760
#define CEditWnd__SetEditable_x                                    0x8E2FF0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x54F0D0
#define CEverQuest__DoTellWindow_x                                 0x554AD0
#define CEverQuest__DropHeldItemOnGround_x                         0x55D5C0
#define CEverQuest__dsp_chat_x                                     0x556270
#define CEverQuest__Emote_x                                        0x5564D0
#define CEverQuest__EnterZone_x                                    0x56A5F0
#define CEverQuest__GetBodyTypeDesc_x                              0x54B930
#define CEverQuest__GetClassDesc_x                                 0x551640
#define CEverQuest__GetClassThreeLetterCode_x                      0x551C40
#define CEverQuest__GetDeityDesc_x                                 0x54C210
#define CEverQuest__GetLangDesc_x                                  0x54BCC0
#define CEverQuest__GetRaceDesc_x                                  0x551E00
#define CEverQuest__InterpretCmd_x                                 0x556DB0
#define CEverQuest__LeftClickedOnPlayer_x                          0x56E760
#define CEverQuest__LMouseUp_x                                     0x570850
#define CEverQuest__RightClickedOnPlayer_x                         0x56F260
#define CEverQuest__RMouseUp_x                                     0x5702B0
#define CEverQuest__SetGameState_x                                 0x54F780
#define CEverQuest__UPCNotificationFlush_x                         0x557F10
#define CEverQuest__IssuePetCommand_x                              0x557A70

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AA980
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AA9E0
#define CGaugeWnd__Draw_x                                          0x6AAE10

// CGuild
#define CGuild__FindMemberByName_x                                 0x435F10

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C7A40

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D5840
#define CInvSlotMgr__MoveItem_x                                    0x6D6780
#define CInvSlotMgr__SelectSlot_x                                  0x6D58F0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D4CD0
#define CInvSlot__SliderComplete_x                                 0x6D2690
#define CInvSlot__GetItemBase_x                                    0x6D1B20

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D78F0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A08A0
#define CItemDisplayWnd__UpdateStrings_x                           0x6D8C20

// CLabel 
#define CLabel__Draw_x                                             0x6F3960

// CListWnd 
#define CListWnd__CListWnd_x                                       0x8B9950
#define CListWnd__dCListWnd_x                                      0x8BA970
#define CListWnd__AddColumn_x                                      0x8BA910
#define CListWnd__AddColumn1_x                                     0x8BA180
#define CListWnd__AddLine_x                                        0x8B9C00
#define CListWnd__AddString_x                                      0x8B9E10
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B6C80
#define CListWnd__CalculateVSBRange_x                              0x8B8E00
#define CListWnd__ClearAllSel_x                                    0x8B5F30
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B97E0
#define CListWnd__Compare_x                                        0x8B7790
#define CListWnd__Draw_x                                           0x8B8A10
#define CListWnd__DrawColumnSeparators_x                           0x8B88A0
#define CListWnd__DrawHeader_x                                     0x8B6240
#define CListWnd__DrawItem_x                                       0x8B7DD0
#define CListWnd__DrawLine_x                                       0x8B8540
#define CListWnd__DrawSeparator_x                                  0x8B8940
#define CListWnd__EnsureVisible_x                                  0x8B6DE0
#define CListWnd__ExtendSel_x                                      0x8B7CE0
#define CListWnd__GetColumnMinWidth_x                              0x8B58F0
#define CListWnd__GetColumnWidth_x                                 0x8B5810
#define CListWnd__GetCurSel_x                                      0x8B4FD0
#define CListWnd__GetItemAtPoint_x                                 0x8B7080
#define CListWnd__GetItemAtPoint1_x                                0x8B70F0
#define CListWnd__GetItemData_x                                    0x8B5320
#define CListWnd__GetItemHeight_x                                  0x8B68D0
#define CListWnd__GetItemIcon_x                                    0x8B5500
#define CListWnd__GetItemRect_x                                    0x8B6EC0
#define CListWnd__GetItemText_x                                    0x8B53B0
#define CListWnd__GetSelList_x                                     0x8BA070
#define CListWnd__GetSeparatorRect_x                               0x8B76B0
#define CListWnd__RemoveLine_x                                     0x8B9FF0
#define CListWnd__SetColors_x                                      0x8B5120
#define CListWnd__SetColumnJustification_x                         0x8B5BC0
#define CListWnd__SetColumnWidth_x                                 0x8B58A0
#define CListWnd__SetCurSel_x                                      0x8B5010
#define CListWnd__SetItemColor_x                                   0x8B94C0
#define CListWnd__SetItemData_x                                    0x8B5FE0
#define CListWnd__SetItemText_x                                    0x8B9300
#define CListWnd__ShiftColumnSeparator_x                           0x8B9190
#define CListWnd__Sort_x                                           0x8BAA70
#define CListWnd__ToggleSel_x                                      0x8B5EB0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70CD60

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72E0B0
#define CMerchantWnd__RequestBuyItem_x                             0x734EA0
#define CMerchantWnd__RequestSellItem_x                            0x7358F0
#define CMerchantWnd__SelectRecoverySlot_x                         0x72E360
#define CMerchantWnd__SelectBuySellSlot_x                          0x72D5C0
#define CMerchantWnd__ActualSelect_x                               0x731DE0

// CObfuscator
#define CObfuscator__doit_x                                        0x861240

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D8EA0
#define CSidlManager__CreateLabel_x                                0x796860

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateVSBRange_x                        0x658580
#define CSidlScreenWnd__CalculateHSBRange_x                        0x658660
#define CSidlScreenWnd__ConvertToRes_x                             0x8F44E0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D09D0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D1EC0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D1F70
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D1440
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D0380
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CFAC0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D0570
#define CSidlScreenWnd__Init1_x                                    0x8D1BA0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D0A80
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CFC80
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D1690
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CF590
#define CSidlScreenWnd__StoreIniVis_x                              0x8CFA50
#define CSidlScreenWnd__WndNotification_x                          0x8D1920
#define CSidlScreenWnd__GetChildItem_x                             0x8CFB90
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C3050

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F3650
#define CSkillMgr__GetSkillCap_x                                   0x5F3810
#define CSkillMgr__GetNameToken_x                                  0x5F3270

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F37B0
#define CSliderWnd__SetValue_x                                     0x8F3980
#define CSliderWnd__SetNumTicks_x                                  0x8F4100

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79E550

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EE1B0
#define CStmlWnd__CalculateHSBRange_x                              0x8E66D0
#define CStmlWnd__CalculateVSBRange_x                              0x8E6760
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E68E0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E71C0
#define CStmlWnd__ForceParseNow_x                                  0x8EEB00
#define CStmlWnd__GetNextTagPiece_x                                0x8E70C0
#define CStmlWnd__GetSTMLText_x                                    0x68FA90
#define CStmlWnd__GetVisibleText_x                                 0x8E7C10
#define CStmlWnd__InitializeWindowVariables_x                      0x8E9FA0
#define CStmlWnd__MakeStmlColorTag_x                               0x8E59D0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E5A30
#define CStmlWnd__SetSTMLText_x                                    0x8EB810
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EDE50
#define CStmlWnd__UpdateHistoryString_x                            0x8E8B50

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8F5CF0
#define CTabWnd__DrawCurrentPage_x                                 0x8F5560
#define CTabWnd__DrawTab_x                                         0x8F5320
#define CTabWnd__GetCurrentPage_x                                  0x8F5930
#define CTabWnd__GetPageInnerRect_x                                0x8F5010
#define CTabWnd__GetTabInnerRect_x                                 0x8F5210
#define CTabWnd__GetTabRect_x                                      0x8F50E0
#define CTabWnd__InsertPage_x                                      0x8F5FE0
#define CTabWnd__SetPage_x                                         0x8F5960
#define CTabWnd__SetPageRect_x                                     0x8F5C30
#define CTabWnd__UpdatePage_x                                      0x8F5F80

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431CF0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CD710

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8FAF40

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B3230

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x595950
#define CXStr__CXStr1_x                                            0x8A7E90
#define CXStr__CXStr3_x                                            0x897AD0
#define CXStr__dCXStr_x                                            0x49D920
#define CXStr__operator_equal_x                                    0x897C40
#define CXStr__operator_equal1_x                                   0x897C90
#define CXStr__operator_plus_equal1_x                              0x898D70

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C2230
#define CXWnd__Center_x                                            0x8C8450
#define CXWnd__ClrFocus_x                                          0x8C1E20
#define CXWnd__DoAllDrawing_x                                      0x8C8090
#define CXWnd__DrawChildren_x                                      0x8C8240
#define CXWnd__DrawColoredRect_x                                   0x8C25F0
#define CXWnd__DrawTooltip_x                                       0x8C28A0
#define CXWnd__DrawTooltipAtPoint_x                                0x8C6FF0
#define CXWnd__GetBorderFrame_x                                    0x8C2D10
#define CXWnd__GetChildWndAt_x                                     0x8C8E10
#define CXWnd__GetClientClipRect_x                                 0x8C2AC0
#define CXWnd__GetScreenClipRect_x                                 0x8C76F0
#define CXWnd__GetScreenRect_x                                     0x8C2EE0
#define CXWnd__GetTooltipRect_x                                    0x8C2730
#define CXWnd__GetWindowTextA_x                                    0x423110
#define CXWnd__IsActive_x                                          0x8BD790
#define CXWnd__IsDescendantOf_x                                    0x8C2C50
#define CXWnd__IsReallyVisible_x                                   0x8C6010
#define CXWnd__IsType_x                                            0x8F7670
#define CXWnd__Move_x                                              0x8C5720
#define CXWnd__Move1_x                                             0x8C7D40
#define CXWnd__ProcessTransition_x                                 0x8C21E0
#define CXWnd__Refade_x                                            0x8C1FC0
#define CXWnd__Resize_x                                            0x8C2FB0
#define CXWnd__Right_x                                             0x8C74F0
#define CXWnd__SetFocus_x                                          0x8C4860
#define CXWnd__SetFont_x                                           0x8C1E70
#define CXWnd__SetKeyTooltip_x                                     0x8C3220
#define CXWnd__SetMouseOver_x                                      0x8C7A30
#define CXWnd__StartFade_x                                         0x8C2280
#define CXWnd__GetChildItem_x                                      0x8C7970

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BF0C0
#define CXWndManager__DrawWindows_x                                0x8BED00
#define CXWndManager__GetKeyboardFlags_x                           0x8BD2C0
#define CXWndManager__HandleKeyboardMsg_x                          0x8BDC20
#define CXWndManager__RemoveWnd_x                                  0x8BD920

// CDBStr
#define CDBStr__GetString_x                                        0x4A4400

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E1C0
#define EQ_Character__Cur_HP_x                                     0x463780
#define EQ_Character__GetAACastingTimeModifier_x                   0x4460E0
#define EQ_Character__GetCharInfo2_x                               0x86BB40
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43E0E0
#define EQ_Character__GetFocusRangeModifier_x                      0x43E2D0
#define EQ_Character__Max_Endurance_x                              0x5BAC70
#define EQ_Character__Max_HP_x                                     0x459400
#define EQ_Character__Max_Mana_x                                   0x5BAAA0
#define EQ_Character__doCombatAbility_x                            0x5B8080
#define EQ_Character__UseSkill_x                                   0x46EC90
#define EQ_Character__GetConLevel_x                                0x5AD330
#define EQ_Character__IsExpansionFlag_x                            0x422640
#define EQ_Character__TotalEffect_x                                0x44B460

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x58DBD0
#define EQ_Item__CreateItemTagString_x                             0x84B340
#define EQ_Item__IsStackable_x                                     0x83F500
#define EQ_Item__GetImageNum_x                                     0x8421A0
#define EQ_Item__CreateItemClient_x                                0x58E7B0
#define EQ_Item__GetItemValue_x                                    0x849FD0
#define EQ_Item__ValueSellMerchant_x                               0x84C6C0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C4160
#define EQ_LoadingS__Array_x                                       0xC12A20

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BC410
#define EQ_PC__GetAlternateAbilityId_x                             0x854600
#define EQ_PC__GetCombatAbility_x                                  0x854690
#define EQ_PC__GetCombatAbilityTimer_x                             0x84F630
#define EQ_PC__GetItemTimerValue_x                                 0x5B5E60
#define EQ_PC__HasLoreItem_x                                       0x5B0680
#define EQ_PC__AlertInventoryChanged_x                             0x5AD300
#define EQ_PC__GetPcZoneClient_x                                   0x5D6A30
#define EQ_PC__RemoveMyAffect_x                                    0x5B5370

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50A420
#define EQItemList__add_item_x                                     0x50A360
#define EQItemList__delete_item_x                                  0x50A820
#define EQItemList__FreeItemList_x                                 0x50A720

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A35E0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C19D0
#define EQPlayer__dEQPlayer_x                                      0x5CA850
#define EQPlayer__DoAttack_x                                       0x5DC950
#define EQPlayer__EQPlayer_x                                       0x5CCC70
#define EQPlayer__SetNameSpriteState_x                             0x5C7520
#define EQPlayer__SetNameSpriteTint_x                              0x5C2DE0
#define EQPlayer__IsBodyType_j_x                                   0x928610
#define EQPlayer__IsTargetable_x                                   0x928F10
#define EQPlayer__CanSee_x                                         0x929430
#define PlayerZoneClient__ChangeHeight_x                           0x5DC810

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D0FE0
#define EQPlayerManager__GetSpawnByName_x                          0x5D1440

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x593C80
#define KeypressHandler__AttachKeyToEqCommand_x                    0x593CC0
#define KeypressHandler__ClearCommandStateArray_x                  0x593860
#define KeypressHandler__HandleKeyDown_x                           0x5921C0
#define KeypressHandler__HandleKeyUp_x                             0x5924E0
#define KeypressHandler__SaveKeymapping_x                          0x593930

// MapViewMap 
#define MapViewMap__Clear_x                                        0x705140
#define MapViewMap__SaveEx_x                                       0x708A20

#define PlayerPointManager__GetAltCurrency_x                       0x866B10

// StringTable 
#define StringTable__getString_x                                   0x8614E0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BA720
#define PcZoneClient__RemovePetEffect_x                            0x5B6090

//Doors
#define EQSwitch__UseSwitch_x                                      0x548CD0

//IconCache
#define IconCache__GetIcon_x                                       0x6A0270

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x697110
#define CContainerMgr__CloseContainer_x                            0x697930

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x766A00

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x586F00

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DA540
#define EQ_Spell__SpellAffects_x                                   0x4DA5E0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DA610
#define CharacterZoneClient__CalcAffectChange_x                    0x4474D0
#define CLootWnd__LootAll_x                                        0x6FAAE0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x750890
#define CTargetWnd__WndNotification_x                              0x7ABFF0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B16E0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D3E30

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4938E0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E1FC0
#define CSidlManager__FindAnimation1_x                             0x8D6D80

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CB6B0
#define CAltAbilityData__GetMercMaxRank_x                          0x4CB660
#define CAltAbilityData__GetMaxRank_x                              0x4C0730
