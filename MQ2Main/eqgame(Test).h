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
#define __ExpectedVersionDate                                     "Aug 20 2015"
#define __ExpectedVersionTime                                     "14:49:12"
#define __ActualVersionDate_x                                      0xA83FD8
#define __ActualVersionTime_x                                      0xA83FE4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x597D70
#define __MemChecker1_x                                            0x862B70
#define __MemChecker2_x                                            0x630920
#define __MemChecker3_x                                            0x630870
#define __MemChecker4_x                                            0x7E63D0
#define __EncryptPad0_x                                            0xC025D0
#define __EncryptPad1_x                                            0xD89F80
#define __EncryptPad2_x                                            0xC4BF18
#define __EncryptPad3_x                                            0xC4BB18
#define __EncryptPad4_x                                            0xD65FE8
#define __AC1_x                                                    0x7A37E5
#define __AC2_x                                                    0x54D217
#define __AC3_x                                                    0x561A10
#define __AC4_x                                                    0x568690
#define __AC5_x                                                    0x5744BE
#define __AC6_x                                                    0x577F69
#define __AC7_x                                                    0x56EB6C
#define __AC1_Data                                                 0x11111111

// Direct Input
#define DI8__Main_x                                                0x113C090
#define DI8__Keyboard_x                                            0x113C094
#define DI8__Mouse_x                                               0x113C098
#define DI8__Mouse_Copy_x                                          0xFAA6AC
#define DI8__Mouse_Check_x                                         0x1033F7C
#define __AltTimerReady_x                                          0xF9B9F9
#define __Attack_x                                                 0x102EC1B
#define __Autofire_x                                               0x102EC1C
#define __BindList_x                                               0xBC4828
#define __bCommandEnabled_x                                        0xF99B08
#define __Clicks_x                                                 0xFAA768
#define __CommandList_x                                            0xBC8B80
#define __CurrentMapLabel_x                                        0x1141AE8
#define __CurrentSocial_x                                          0xB7FE7C
#define __DoAbilityList_x                                          0xFE0ED0
#define __do_loot_x                                                0x514800
#define __DrawHandler_x                                            0x17A66F4
#define __GroupCount_x                                             0xF9B0D2

#define __Guilds_x                                                 0xFA0CE8
#define __gWorld_x                                                 0xF9D58C
#define __HotkeyPage_x                                             0x10278D0
#define __HWnd_x                                                   0x1033F98
#define __InChatMode_x                                             0xFAA694
#define __LastTell_x                                               0xFAC5D8
#define __LMouseHeldTime_x                                         0xFAA7D4
#define __Mouse_x                                                  0x113C09C
#define __MouseLook_x                                              0xFAA72E
#define __MouseEventTime_x                                         0x102F424
#define __gpbCommandEvent_x                                        0xF9D654
#define __NetStatusToggle_x                                        0xFAA731
#define __PCNames_x                                                0xFABBF8
#define __RangeAttackReady_x                                       0xFAB8B8
#define __RMouseHeldTime_x                                         0xFAA7D0
#define __RunWalkState_x                                           0xFAA698
#define __ScreenMode_x                                             0xEE9938
#define __ScreenX_x                                                0xFAA64C
#define __ScreenY_x                                                0xFAA648
#define __ScreenXMax_x                                             0xFAA650
#define __ScreenYMax_x                                             0xFAA654
#define __ServerHost_x                                             0xF9B01C
#define __ServerName_x                                             0xFE0E90
#define __ShiftKeyDown_x                                           0xFAAD3C
#define __ShowNames_x                                              0xFABA8C
#define __Socials_x                                                0xFE0F90
#define __SubscriptionType_x                                       0x116DE78
#define __TargetAggroHolder_x                                      0x1143D24
#define __GroupAggro_x                                             0x1143D64
#define __LoginName_x                                              0x1032B70
#define __Inviter_x                                                0x102EB98


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF9D678
#define instEQZoneInfo_x                                           0xFAA924
#define instKeypressHandler_x                                      0x102F408
#define pinstActiveBanker_x                                        0xF9D630
#define pinstActiveCorpse_x                                        0xF9D634
#define pinstActiveGMaster_x                                       0xF9D638
#define pinstActiveMerchant_x                                      0xF9D62C
#define pinstAggroInfo_x                                           0xDADDB8
#define pinstAltAdvManager_x                                       0xEEAA30
#define pinstAuraMgr_x                                             0xDB7C80
#define pinstBandageTarget_x                                       0xF9D618
#define pinstCamActor_x                                            0xEEA33C
#define pinstCDBStr_x                                              0xEE98CC
#define pinstCDisplay_x                                            0xF9D640
#define pinstCEverQuest_x                                          0x113C210
#define pinstCharData_x                                            0xF9D5FC
#define pinstCharSpawn_x                                           0xF9D624
#define pinstControlledMissile_x                                   0xF9D5F8
#define pinstControlledPlayer_x                                    0xF9D624
#define pinstCSidlManager_x                                        0x17A5B2C
#define pinstCXWndManager_x                                        0x17A5B24
#define instDynamicZone_x                                          0xFAA4E0
#define pinstDZMember_x                                            0xFAA5F0
#define pinstDZTimerInfo_x                                         0xFAA5F4
#define pinstEQItemList_x                                          0xF99D58
#define instEQMisc_x                                               0xBA0AC0
#define pinstEQSoundManager_x                                      0xEEAEA0
#define instExpeditionLeader_x                                     0xFAA52A
#define instExpeditionName_x                                       0xFAA56A
#define pinstGroup_x                                               0xF9B0CE
#define pinstImeManager_x                                          0x17A5B30
#define pinstLocalPlayer_x                                         0xF9D610
#define pinstMercenaryData_x                                       0x102FA58
#define pinstMercenaryStats_x                                      0x1143E70
#define pinstMercAltAbilities_x                                    0xEEADBC
#define pinstModelPlayer_x                                         0xF9D63C
#define pinstPCData_x                                              0xF9D5FC
#define pinstSkillMgr_x                                            0x1030890
#define pinstSpawnManager_x                                        0x1030178
#define pinstSpellManager_x                                        0x10309D8
#define pinstSpellSets_x                                           0x1027934
#define pinstStringTable_x                                         0xF9D5A4
#define pinstSwitchManager_x                                       0xF9AC60
#define pinstTarget_x                                              0xF9D628
#define pinstTargetObject_x                                        0xF9D600
#define pinstTargetSwitch_x                                        0xF9D604
#define pinstTaskMember_x                                          0xEE9818
#define pinstTrackTarget_x                                         0xF9D61C
#define pinstTradeTarget_x                                         0xF9D60C
#define instTributeActive_x                                        0xBA0AE5
#define pinstViewActor_x                                           0xEEA338
#define pinstWorldData_x                                           0xF9D5E0


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xDAE298
#define pinstCAudioTriggersWindow_x                                0xDAE128
#define pinstCCharacterSelect_x                                    0xEEA1D8
#define pinstCFacePick_x                                           0xEEA188
#define pinstCNoteWnd_x                                            0xEEA190
#define pinstCBookWnd_x                                            0xEEA198
#define pinstCPetInfoWnd_x                                         0xEEA19C
#define pinstCTrainWnd_x                                           0xEEA1A0
#define pinstCSkillsWnd_x                                          0xEEA1A4
#define pinstCSkillsSelectWnd_x                                    0xEEA1A8
#define pinstCCombatSkillsSelectWnd_x                              0xEEA1AC
#define pinstCFriendsWnd_x                                         0xEEA1B0
#define pinstCAuraWnd_x                                            0xEEA1B4
#define pinstCRespawnWnd_x                                         0xEEA1B8
#define pinstCBandolierWnd_x                                       0xEEA1BC
#define pinstCPotionBeltWnd_x                                      0xEEA1C0
#define pinstCAAWnd_x                                              0xEEA1C4
#define pinstCGroupSearchFiltersWnd_x                              0xEEA1C8
#define pinstCLoadskinWnd_x                                        0xEEA1CC
#define pinstCAlarmWnd_x                                           0xEEA1D0
#define pinstCMusicPlayerWnd_x                                     0xEEA1D4
#define pinstCMailWnd_x                                            0xEEA1DC
#define pinstCMailCompositionWnd_x                                 0xEEA1E0
#define pinstCMailAddressBookWnd_x                                 0xEEA1E4
#define pinstCRaidWnd_x                                            0xEEA1EC
#define pinstCRaidOptionsWnd_x                                     0xEEA1F0
#define pinstCBreathWnd_x                                          0xEEA1F4
#define pinstCMapViewWnd_x                                         0xEEA1F8
#define pinstCMapToolbarWnd_x                                      0xEEA1FC
#define pinstCEditLabelWnd_x                                       0xEEA200
#define pinstCTargetWnd_x                                          0xEEA204
#define pinstCColorPickerWnd_x                                     0xEEA208
#define pinstCPlayerWnd_x                                          0xEEA20C
#define pinstCOptionsWnd_x                                         0xEEA210
#define pinstCBuffWindowNORMAL_x                                   0xEEA214
#define pinstCBuffWindowSHORT_x                                    0xEEA218
#define pinstCharacterCreation_x                                   0xEEA21C
#define pinstCCursorAttachment_x                                   0xEEA220
#define pinstCCastingWnd_x                                         0xEEA224
#define pinstCCastSpellWnd_x                                       0xEEA228
#define pinstCSpellBookWnd_x                                       0xEEA22C
#define pinstCInventoryWnd_x                                       0xEEA230
#define pinstCBankWnd_x                                            0xEEA234
#define pinstCQuantityWnd_x                                        0xEEA238
#define pinstCLootWnd_x                                            0xEEA23C
#define pinstCActionsWnd_x                                         0xEEA240
#define pinstCCombatAbilityWnd_x                                   0xEEA244
#define pinstCMerchantWnd_x                                        0xEEA248
#define pinstCTradeWnd_x                                           0xEEA24C
#define pinstCSelectorWnd_x                                        0xEEA250
#define pinstCBazaarWnd_x                                          0xEEA254
#define pinstCBazaarSearchWnd_x                                    0xEEA258
#define pinstCGiveWnd_x                                            0xEEA274
#define pinstCTrackingWnd_x                                        0xEEA27C
#define pinstCInspectWnd_x                                         0xEEA280
#define pinstCSocialEditWnd_x                                      0xEEA284
#define pinstCFeedbackWnd_x                                        0xEEA288
#define pinstCBugReportWnd_x                                       0xEEA28C
#define pinstCVideoModesWnd_x                                      0xEEA290
#define pinstCTextEntryWnd_x                                       0xEEA298
#define pinstCFileSelectionWnd_x                                   0xEEA29C
#define pinstCCompassWnd_x                                         0xEEA2A0
#define pinstCPlayerNotesWnd_x                                     0xEEA2A4
#define pinstCGemsGameWnd_x                                        0xEEA2A8
#define pinstCTimeLeftWnd_x                                        0xEEA2AC
#define pinstCPetitionQWnd_x                                       0xEEA2C0
#define pinstCSoulmarkWnd_x                                        0xEEA2C4
#define pinstCStoryWnd_x                                           0xEEA2C8
#define pinstCJournalTextWnd_x                                     0xEEA2CC
#define pinstCJournalCatWnd_x                                      0xEEA2D0
#define pinstCBodyTintWnd_x                                        0xEEA2D4
#define pinstCServerListWnd_x                                      0xEEA2D8
#define pinstCAvaZoneWnd_x                                         0xEEA2E4
#define pinstCBlockedBuffWnd_x                                     0xEEA2E8
#define pinstCBlockedPetBuffWnd_x                                  0xEEA2EC
#define pinstCInvSlotMgr_x                                         0xEEA330
#define pinstCContainerMgr_x                                       0xEEA334
#define pinstCAdventureLeaderboardWnd_x                            0x113CBC0
#define pinstCAdventureRequestWnd_x                                0x113CC38
#define pinstCAltStorageWnd_x                                      0x113CF18
#define pinstCAdventureStatsWnd_x                                  0x113CCB0
#define pinstCBarterMerchantWnd_x                                  0x113DB00
#define pinstCBarterSearchWnd_x                                    0x113DB78
#define pinstCBarterWnd_x                                          0x113DBF0
#define pinstCChatManager_x                                        0x113E280
#define pinstCDynamicZoneWnd_x                                     0x113E730
#define pinstCEQMainWnd_x                                          0x113E8C8
#define pinstCFellowshipWnd_x                                      0x113E6C4
#define pinstCFindLocationWnd_x                                    0x113EB98
#define pinstCGroupSearchWnd_x                                     0x113EE68
#define pinstCGroupWnd_x                                           0x113EEE0
#define pinstCGuildBankWnd_x                                       0x113EF58
#define pinstCGuildMgmtWnd_x                                       0x1141048
#define pinstCHotButtonWnd_x                                       0x1141114
#define pinstCHotButtonWnd1_x                                      0x1141114
#define pinstCHotButtonWnd2_x                                      0x1141118
#define pinstCHotButtonWnd3_x                                      0x114111C
#define pinstCHotButtonWnd4_x                                      0x1141140
#define pinstCItemDisplayManager_x                                 0x1141438
#define pinstCItemExpTransferWnd_x                                 0x11414B4
#define pinstCLFGuildWnd_x                                         0x1141790
#define pinstCMIZoneSelectWnd_x                                    0x1141D78
#define pinstCConfirmationDialog_x                                 0x1142480
#define pinstCPopupWndManager_x                                    0x1142480
#define pinstCProgressionSelectionWnd_x                            0x1142570
#define pinstCPvPStatsWnd_x                                        0x1142660
#define pinstCSystemInfoDialogBox_x                                0x1142D68
#define pinstCTaskWnd_x                                            0x1144130
#define pinstCTaskSomething_x                                      0xDB83C0
#define pinstCTaskTemplateSelectWnd_x                              0x11440B8
#define pinstCTipWndOFDAY_x                                        0x1144388
#define pinstCTipWndCONTEXT_x                                      0x114438C
#define pinstCTitleWnd_x                                           0x1144408
#define pinstCContextMenuManager_x                                 0x17A5A9C
#define pinstCVoiceMacroWnd_x                                      0x1031040
#define pinstCHtmlWnd_x                                            0x1031138
#define pinstIconCache_x                                           0x113E89C
#define pinstCTradeskillWnd_x                                      0x1144508
#define pinstCAdvancedLootWnd_x                                    0xEEA324
#define pinstRewardSelectionWnd_x                                  0x1142B88

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x52C340
#define __ConvertItemTags_x                                        0x519480
#define __ExecuteCmd_x                                             0x503F70
#define __EQGetTime_x                                              0x862ED0
#define __get_melee_range_x                                        0x50AC40
#define __GetGaugeValueFromEQ_x                                    0x7A2520
#define __GetLabelFromEQ_x                                         0x7A3770
#define __ToggleMount_x                                            0x6CB5B0
#define __GetXTargetType_x                                         0x921980
#define __LoadFrontEnd_x                                           0x62FFD0
#define __NewUIINI_x                                               0x7A1E20
#define __ProcessGameEvents_x                                      0x5708D0
#define __ProcessMouseEvent_x                                      0x570070
#define CrashDetected_x                                            0x631AA0
#define wwsCrashReportCheckForUploader_x                           0x7F73A0
#define DrawNetStatus_x                                            0x5A76D0
#define Util__FastTime_x                                           0x8629E0
#define Expansion_HoT_x                                            0xFABA24
#define __HelpPath_x                                               0x102F190
//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41F050
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419EA0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C2870
#define AltAdvManager__IsAbilityReady_x                            0x4C28E0
#define AltAdvManager__GetAltAbility_x                             0x4C2CA0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4659B0
#define CharacterZoneClient__MakeMeVisible_x                       0x46B3E0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x65F960

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66DD80

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x586C20

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x688C50
#define CChatManager__InitContextMenu_x                            0x6897D0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D35D0
#define CContextMenu__AddMenuItem_x                                0x8D37F0
#define CContextMenu__dCContextMenu_x                              0x8D37E0
#define CContextMenu__RemoveMenuItem_x                             0x8D3AE0
#define CContextMenu__RemoveAllMenuItems_x                         0x8D3B00
#define CContextMenuManager__AddMenu_x                             0x8BF3D0
#define CContextMenuManager__RemoveMenu_x                          0x8BF710
#define CContextMenuManager__PopupMenu_x                           0x8BFB60
#define CContextMenuManager__Flush_x                               0x8BF440
#define CContextMenuManager__GetMenu_x                             0x4154F0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x848FC0
#define CChatService__GetFriendName_x                              0x848FD0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x68EA80
#define CChatWindow__Clear_x                                       0x68E630
#define CChatWindow__WndNotification_x                             0x68EFC0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C32C0
#define CComboWnd__Draw_x                                          0x8C34D0
#define CComboWnd__GetCurChoice_x                                  0x8C3090
#define CComboWnd__GetListRect_x                                   0x8C3770
#define CComboWnd__GetTextRect_x                                   0x8C3330
#define CComboWnd__InsertChoice_x                                  0x8C37E0
#define CComboWnd__SetColors_x                                     0x8C3020
#define CComboWnd__SetChoice_x                                     0x8C3050
#define CComboWnd__GetItemCount_x                                  0x8C3080

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x698230
#define CContainerWnd__vftable_x                                   0xA8D768

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B0C20
#define CDisplay__GetClickedActor_x                                0x4A97A0
#define CDisplay__GetUserDefinedColor_x                            0x4A8060
#define CDisplay__GetWorldFilePath_x                               0x4A74B0
#define CDisplay__is3dON_x                                         0x4A6880
#define CDisplay__ReloadUI_x                                       0x4BC0F0
#define CDisplay__WriteTextHD2_x                                   0x4ACFC0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E9C90

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D8010
#define CEditWnd__GetCharIndexPt_x                                 0x8D90A0
#define CEditWnd__GetDisplayString_x                               0x8D81C0
#define CEditWnd__GetHorzOffset_x                                  0x8D8500
#define CEditWnd__GetLineForPrintableChar_x                        0x8D8B70
#define CEditWnd__GetSelStartPt_x                                  0x8D9350
#define CEditWnd__GetSTMLSafeText_x                                0x8D86A0
#define CEditWnd__PointFromPrintableChar_x                         0x8D8C60
#define CEditWnd__SelectableCharFromPoint_x                        0x8D8DE0
#define CEditWnd__SetEditable_x                                    0x8D8670

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x54D960
#define CEverQuest__DoTellWindow_x                                 0x553360
#define CEverQuest__DropHeldItemOnGround_x                         0x55BE90
#define CEverQuest__dsp_chat_x                                     0x554B00
#define CEverQuest__Emote_x                                        0x554D60
#define CEverQuest__EnterZone_x                                    0x568EB0
#define CEverQuest__GetBodyTypeDesc_x                              0x54A1C0
#define CEverQuest__GetClassDesc_x                                 0x54FED0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5504D0
#define CEverQuest__GetDeityDesc_x                                 0x54AAA0
#define CEverQuest__GetLangDesc_x                                  0x54A550
#define CEverQuest__GetRaceDesc_x                                  0x550690
#define CEverQuest__InterpretCmd_x                                 0x555640
#define CEverQuest__LeftClickedOnPlayer_x                          0x56CFD0
#define CEverQuest__LMouseUp_x                                     0x56F0C0
#define CEverQuest__RightClickedOnPlayer_x                         0x56DAD0
#define CEverQuest__RMouseUp_x                                     0x56EB20
#define CEverQuest__SetGameState_x                                 0x54E010
#define CEverQuest__UPCNotificationFlush_x                         0x5567E0
#define CEverQuest__IssuePetCommand_x                              0x556340

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A8E60
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A8EC0
#define CGaugeWnd__Draw_x                                          0x6A92F0

// CGuild
#define CGuild__FindMemberByName_x                                 0x435EA0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C5FE0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D3E60
#define CInvSlotMgr__MoveItem_x                                    0x6D4DA0
#define CInvSlotMgr__SelectSlot_x                                  0x6D3F10

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D32F0
#define CInvSlot__SliderComplete_x                                 0x6D0CB0
#define CInvSlot__GetItemBase_x                                    0x6D0100

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D5F60

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79EEC0
#define CItemDisplayWnd__UpdateStrings_x                           0x6D7290

// CLabel 
#define CLabel__Draw_x                                             0x6F2140

// CListWnd 
#define CListWnd__CListWnd_x                                       0x8AEF90
#define CListWnd__dCListWnd_x                                      0x8AFFC0
#define CListWnd__AddColumn_x                                      0x8AFF60
#define CListWnd__AddColumn1_x                                     0x8AF7D0
#define CListWnd__AddLine_x                                        0x8AF250
#define CListWnd__AddString_x                                      0x8AF460
#define CListWnd__CalculateFirstVisibleLine_x                      0x8AC2B0
#define CListWnd__CalculateVSBRange_x                              0x8AE440
#define CListWnd__ClearAllSel_x                                    0x8AB560
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8AEE20
#define CListWnd__Compare_x                                        0x8ACDC0
#define CListWnd__Draw_x                                           0x8AE050
#define CListWnd__DrawColumnSeparators_x                           0x8ADEE0
#define CListWnd__DrawHeader_x                                     0x8AB870
#define CListWnd__DrawItem_x                                       0x8AD410
#define CListWnd__DrawLine_x                                       0x8ADB80
#define CListWnd__DrawSeparator_x                                  0x8ADF80
#define CListWnd__EnsureVisible_x                                  0x8AC410
#define CListWnd__ExtendSel_x                                      0x8AD320
#define CListWnd__GetColumnMinWidth_x                              0x8AAF20
#define CListWnd__GetColumnWidth_x                                 0x8AAE40
#define CListWnd__GetCurSel_x                                      0x8AA620
#define CListWnd__GetItemAtPoint_x                                 0x8AC6B0
#define CListWnd__GetItemAtPoint1_x                                0x8AC720
#define CListWnd__GetItemData_x                                    0x8AA950
#define CListWnd__GetItemHeight_x                                  0x8ABF00
#define CListWnd__GetItemIcon_x                                    0x8AAB30
#define CListWnd__GetItemRect_x                                    0x8AC4F0
#define CListWnd__GetItemText_x                                    0x8AA9E0
#define CListWnd__GetSelList_x                                     0x8AF6C0
#define CListWnd__GetSeparatorRect_x                               0x8ACCE0
#define CListWnd__RemoveLine_x                                     0x8AF640
#define CListWnd__SetColors_x                                      0x8AA770
#define CListWnd__SetColumnJustification_x                         0x8AB1F0
#define CListWnd__SetColumnWidth_x                                 0x8AAED0
#define CListWnd__SetCurSel_x                                      0x8AA660
#define CListWnd__SetItemColor_x                                   0x8AEB00
#define CListWnd__SetItemData_x                                    0x8AB610
#define CListWnd__SetItemText_x                                    0x8AE940
#define CListWnd__ShiftColumnSeparator_x                           0x8AE7D0
#define CListWnd__Sort_x                                           0x8B00C0
#define CListWnd__ToggleSel_x                                      0x8AB4E0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70B790

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72C8A0
#define CMerchantWnd__RequestBuyItem_x                             0x7336D0
#define CMerchantWnd__RequestSellItem_x                            0x734120
#define CMerchantWnd__SelectRecoverySlot_x                         0x72CB50
#define CMerchantWnd__SelectBuySellSlot_x                          0x72BDB0
#define CMerchantWnd__ActualSelect_x                               0x730600

// CObfuscator
#define CObfuscator__doit_x                                        0x829130

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8CE470
#define CSidlManager__CreateLabel_x                                0x794EF0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x656C70
#define CSidlScreenWnd__CalculateVSBRange_x                        0x656B90
#define CSidlScreenWnd__ConvertToRes_x                             0x8E9B70
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8C5F70
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C7490
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C7540
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C69F0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8C5920
#define CSidlScreenWnd__EnableIniStorage_x                         0x8C5050
#define CSidlScreenWnd__GetSidlPiece_x                             0x8C5B10
#define CSidlScreenWnd__Init1_x                                    0x8C7160
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C6020
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8C5210
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C6C40
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C4B10
#define CSidlScreenWnd__StoreIniVis_x                              0x8C4FE0
#define CSidlScreenWnd__WndNotification_x                          0x8C6EE0
#define CSidlScreenWnd__GetChildItem_x                             0x8C5120
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B85E0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F1E60
#define CSkillMgr__GetSkillCap_x                                   0x5F2000
#define CSkillMgr__GetNameToken_x                                  0x5F1AD0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E8E20
#define CSliderWnd__SetValue_x                                     0x8E8FF0
#define CSliderWnd__SetNumTicks_x                                  0x8E9770

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79CB70

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8E3820
#define CStmlWnd__CalculateHSBRange_x                              0x8DBD20
#define CStmlWnd__CalculateVSBRange_x                              0x8DBDB0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8DBF30
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8DC810
#define CStmlWnd__ForceParseNow_x                                  0x8E4170
#define CStmlWnd__GetNextTagPiece_x                                0x8DC710
#define CStmlWnd__GetSTMLText_x                                    0x68DED0
#define CStmlWnd__GetVisibleText_x                                 0x8DD260
#define CStmlWnd__InitializeWindowVariables_x                      0x8DF5F0
#define CStmlWnd__MakeStmlColorTag_x                               0x8DB020
#define CStmlWnd__MakeWndNotificationTag_x                         0x8DB080
#define CStmlWnd__SetSTMLText_x                                    0x8E0E60
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E34C0
#define CStmlWnd__UpdateHistoryString_x                            0x8DE1A0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8EB360
#define CTabWnd__DrawCurrentPage_x                                 0x8EABD0
#define CTabWnd__DrawTab_x                                         0x8EA990
#define CTabWnd__GetCurrentPage_x                                  0x8EAFA0
#define CTabWnd__GetPageInnerRect_x                                0x8EA680
#define CTabWnd__GetTabInnerRect_x                                 0x8EA880
#define CTabWnd__GetTabRect_x                                      0x8EA750
#define CTabWnd__InsertPage_x                                      0x8EB650
#define CTabWnd__SetPage_x                                         0x8EAFD0
#define CTabWnd__SetPageRect_x                                     0x8EB2A0
#define CTabWnd__UpdatePage_x                                      0x8EB5F0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431C10

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C2C90

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F0500

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A88D0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5943A0
#define CXStr__CXStr1_x                                            0x89D5B0
#define CXStr__CXStr3_x                                            0x85FA70
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x85FBE0
#define CXStr__operator_equal1_x                                   0x85FC30
#define CXStr__operator_plus_equal1_x                              0x860D10

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B7820
#define CXWnd__Center_x                                            0x8BDA00
#define CXWnd__ClrFocus_x                                          0x8B7410
#define CXWnd__DoAllDrawing_x                                      0x8BD630
#define CXWnd__DrawChildren_x                                      0x8BD7E0
#define CXWnd__DrawColoredRect_x                                   0x8B7BD0
#define CXWnd__DrawTooltip_x                                       0x8B7E80
#define CXWnd__DrawTooltipAtPoint_x                                0x8BC580
#define CXWnd__GetBorderFrame_x                                    0x8B82D0
#define CXWnd__GetChildWndAt_x                                     0x8BE3B0
#define CXWnd__GetClientClipRect_x                                 0x8B8090
#define CXWnd__GetScreenClipRect_x                                 0x8BCC80
#define CXWnd__GetScreenRect_x                                     0x8B8480
#define CXWnd__GetTooltipRect_x                                    0x8B7D10
#define CXWnd__GetWindowTextA_x                                    0x4230E0
#define CXWnd__IsActive_x                                          0x8B2DE0
#define CXWnd__IsDescendantOf_x                                    0x8B8220
#define CXWnd__IsReallyVisible_x                                   0x8BB5B0
#define CXWnd__IsType_x                                            0x8ECD00
#define CXWnd__Move_x                                              0x8BACB0
#define CXWnd__Move1_x                                             0x8BD2D0
#define CXWnd__ProcessTransition_x                                 0x8B77C0
#define CXWnd__Refade_x                                            0x8B7590
#define CXWnd__Resize_x                                            0x8B8550
#define CXWnd__Right_x                                             0x8BCA80
#define CXWnd__SetFocus_x                                          0x8B9DE0
#define CXWnd__SetFont_x                                           0x8B7460
#define CXWnd__SetKeyTooltip_x                                     0x8B87B0
#define CXWnd__SetMouseOver_x                                      0x8BCFC0
#define CXWnd__StartFade_x                                         0x8B7870
#define CXWnd__GetChildItem_x                                      0x8BCF00

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B4710
#define CXWndManager__DrawWindows_x                                0x8B4350
#define CXWndManager__GetKeyboardFlags_x                           0x8B2910
#define CXWndManager__HandleKeyboardMsg_x                          0x8B3270
#define CXWndManager__RemoveWnd_x                                  0x8B2F70

// CDBStr
#define CDBStr__GetString_x                                        0x4A4DB0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44F9F0
#define EQ_Character__Cur_HP_x                                     0x465080
#define EQ_Character__GetAACastingTimeModifier_x                   0x447380
#define EQ_Character__GetCharInfo2_x                               0x833A30
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F4F0
#define EQ_Character__GetFocusRangeModifier_x                      0x43F6D0
#define EQ_Character__Max_Endurance_x                              0x5B9980
#define EQ_Character__Max_HP_x                                     0x45ACF0
#define EQ_Character__Max_Mana_x                                   0x5B97B0
#define EQ_Character__doCombatAbility_x                            0x5B6D90
#define EQ_Character__UseSkill_x                                   0x4705E0
#define EQ_Character__GetConLevel_x                                0x5ABD30
#define EQ_Character__IsExpansionFlag_x                            0x422620
#define EQ_Character__TotalEffect_x                                0x44C730

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x58C3E0
#define EQ_Item__CreateItemTagString_x                             0x812EA0
#define EQ_Item__IsStackable_x                                     0x807060
#define EQ_Item__GetImageNum_x                                     0x809D00

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C49A0
#define EQ_LoadingS__Array_x                                       0xBAE858

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BB120
#define EQ_PC__GetAltAbilityIndex_x                                0x81BE90
#define EQ_PC__GetCombatAbility_x                                  0x81BF20
#define EQ_PC__GetCombatAbilityTimer_x                             0x816FB0
#define EQ_PC__GetItemTimerValue_x                                 0x5B4B60
#define EQ_PC__HasLoreItem_x                                       0x5AF080
#define EQ_PC__AlertInventoryChanged_x                             0x5ABD00
#define EQ_PC__GetPcZoneClient_x                                   0x5D5690
#define EQ_PC__RemoveMyAffect_x                                    0x5B4070

// EQItemList 
#define EQItemList__EQItemList_x                                   0x508C90
#define EQItemList__add_item_x                                     0x508BD0
#define EQItemList__delete_item_x                                  0x509090
#define EQItemList__FreeItemList_x                                 0x508F90

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A4090

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C06F0
#define EQPlayer__dEQPlayer_x                                      0x5C9560
#define EQPlayer__DoAttack_x                                       0x5DB5A0
#define EQPlayer__EQPlayer_x                                       0x5CB980
#define EQPlayer__SetNameSpriteState_x                             0x5C6230
#define EQPlayer__SetNameSpriteTint_x                              0x5C1B00
#define EQPlayer__IsBodyType_j_x                                   0x91DAB0
#define EQPlayer__IsTargetable_x                                   0x91E370
#define EQPlayer__CanSee_x                                         0x91E890

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5CFC90
#define EQPlayerManager__GetSpawnByName_x                          0x5D00F0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5926C0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x592700
#define KeypressHandler__ClearCommandStateArray_x                  0x5922A0
#define KeypressHandler__HandleKeyDown_x                           0x590C00
#define KeypressHandler__HandleKeyUp_x                             0x590F20
#define KeypressHandler__SaveKeymapping_x                          0x592370

// MapViewMap 
#define MapViewMap__Clear_x                                        0x703B70
#define MapViewMap__SaveEx_x                                       0x707450

#define PlayerPointManager__GetAltCurrency_x                       0x82E950

// StringTable 
#define StringTable__getString_x                                   0x8293D0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B9430

//Doors
#define EQSwitch__UseSwitch_x                                      0x547600

//IconCache
#define IconCache__GetIcon_x                                       0x69E6A0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x695540
#define CContainerMgr__CloseContainer_x                            0x695D60

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x765180

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5856E0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D8230
#define EQ_Spell__SpellAffects_x                                   0x4D82D0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D8300
#define CharacterZoneClient__CalcAffectChange_x                    0x448770
#define CLootWnd__LootAll_x                                        0x6F9500
//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x74F010
#define CTargetWnd__WndNotification_x                              0x7AA620

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7AFD00

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D1B70

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x494D20
