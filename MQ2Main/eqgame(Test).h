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
#define __ExpectedVersionDate                                     "May 15 2015"
#define __ExpectedVersionTime                                     "15:32:58"
#define __ActualVersionDate_x                                      0xA7DF58
#define __ActualVersionTime_x                                      0xA7DF64

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5942A0
#define __MemChecker1_x                                            0x85D1C0
#define __MemChecker2_x                                            0x62C6A0
#define __MemChecker3_x                                            0x62C5F0
#define __MemChecker4_x                                            0x7E1620
#define __EncryptPad0_x                                            0xBFC5A0
#define __EncryptPad1_x                                            0xD83F18
#define __EncryptPad2_x                                            0xC45EE8
#define __EncryptPad3_x                                            0xC45AE8
#define __EncryptPad4_x                                            0xD5FF80
#define __AC1_x                                                    0x79E7D5
#define __AC2_x                                                    0x54A097
#define __AC3_x                                                    0x55E880
#define __AC4_x                                                    0x564C30
#define __AC5_x                                                    0x570A5E
#define __AC6_x                                                    0x574509
#define __AC7_x                                                    0x56B10C
#define __AC1_Data                                                 0x11111111

// Direct Input
#define DI8__Main_x                                                0x1135FF8
#define DI8__Keyboard_x                                            0x1135FFC
#define DI8__Mouse_x                                               0x1136000
#define __AltTimerReady_x                                          0xF95969
#define __Attack_x                                                 0x1028B87
#define __Autofire_x                                               0x1028B88
#define __BindList_x                                               0xBBE818
#define __bCommandEnabled_x                                        0xF93A78
#define __Clicks_x                                                 0xFA46D8
#define __CommandList_x                                            0xBC2B70
#define __CurrentMapLabel_x                                        0x113BA50
#define __CurrentSocial_x                                          0xB79E7C
#define __DoAbilityList_x                                          0xFDAE3C
#define __do_loot_x                                                0x511800
#define __DrawHandler_x                                            0x17A065C
#define __GroupCount_x                                             0xF95042

#define __Guilds_x                                                 0xF9AC58
#define __gWorld_x                                                 0xF974FC
#define __HotkeyPage_x                                             0x102183C
#define __HWnd_x                                                   0x102DF00
#define __InChatMode_x                                             0xFA4604
#define __LastTell_x                                               0xFA6544
#define __LMouseHeldTime_x                                         0xFA4744
#define __Mouse_x                                                  0x1136004
#define __MouseLook_x                                              0xFA469E
#define __MouseEventTime_x                                         0x102938C
#define __gpbCommandEvent_x                                        0xF975C4
#define __NetStatusToggle_x                                        0xFA46A1
#define __PCNames_x                                                0xFA5B64
#define __RangeAttackReady_x                                       0xFA5828
#define __RMouseHeldTime_x                                         0xFA4740
#define __RunWalkState_x                                           0xFA4608
#define __ScreenMode_x                                             0xEE38B8
#define __ScreenX_x                                                0xFA45BC
#define __ScreenY_x                                                0xFA45B8
#define __ScreenXMax_x                                             0xFA45C0
#define __ScreenYMax_x                                             0xFA45C4
#define __ServerHost_x                                             0xF94F8C
#define __ServerName_x                                             0xFDADFC
#define __ShiftKeyDown_x                                           0xFA4CAC
#define __ShowNames_x                                              0xFA59FC
#define __Socials_x                                                0xFDAEFC
#define __SubscriptionType_x                                       0x1167DE0
#define __TargetAggroHolder_x                                      0x113DC8C
#define __GroupAggro_x                                             0x113DCCC
#define __LoginName_x                                              0x102CAD8
#define __Inviter_x                                                0x1028B04


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF975E8
#define instEQZoneInfo_x                                           0xFA4894
#define instKeypressHandler_x                                      0x1029370
#define pinstActiveBanker_x                                        0xF975A0
#define pinstActiveCorpse_x                                        0xF975A4
#define pinstActiveGMaster_x                                       0xF975A8
#define pinstActiveMerchant_x                                      0xF9759C
#define pinstAggroInfo_x                                           0xDA7D38
#define pinstAltAdvManager_x                                       0xEE49A0
#define pinstAuraMgr_x                                             0xDB1C00
#define pinstBandageTarget_x                                       0xF97588
#define pinstCamActor_x                                            0xEE42AC
#define pinstCDBStr_x                                              0xEE384C
#define pinstCDisplay_x                                            0xF975B0
#define pinstCEverQuest_x                                          0x1136178
#define pinstCharData_x                                            0xF9756C
#define pinstCharSpawn_x                                           0xF97594
#define pinstControlledMissile_x                                   0xF97568
#define pinstControlledPlayer_x                                    0xF97594
#define pinstCSidlManager_x                                        0x179FA94
#define pinstCXWndManager_x                                        0x179FA8C
#define instDynamicZone_x                                          0xFA4450
#define pinstDZMember_x                                            0xFA4560
#define pinstDZTimerInfo_x                                         0xFA4564
#define pinstEQItemList_x                                          0xF93CC8
#define instEQMisc_x                                               0xB9AAC0
#define pinstEQSoundManager_x                                      0xEE4E10
#define instExpeditionLeader_x                                     0xFA449A
#define instExpeditionName_x                                       0xFA44DA
#define pinstGroup_x                                               0xF9503E
#define pinstImeManager_x                                          0x179FA98
#define pinstLocalPlayer_x                                         0xF97580
#define pinstMercenaryData_x                                       0x10299C0
#define pinstMercAltAbilities_x                                    0xEE4D2C
#define pinstModelPlayer_x                                         0xF975AC
#define pinstPCData_x                                              0xF9756C
#define pinstSkillMgr_x                                            0x102A7F8
#define pinstSpawnManager_x                                        0x102A0E0
#define pinstSpellManager_x                                        0x102A940
#define pinstSpellSets_x                                           0x10218A0
#define pinstStringTable_x                                         0xF97514
#define pinstSwitchManager_x                                       0xF94BD0
#define pinstTarget_x                                              0xF97598
#define pinstTargetObject_x                                        0xF97570
#define pinstTargetSwitch_x                                        0xF97574
#define pinstTaskMember_x                                          0xEE3798
#define pinstTrackTarget_x                                         0xF9758C
#define pinstTradeTarget_x                                         0xF9757C
#define instTributeActive_x                                        0xB9AAE5
#define pinstViewActor_x                                           0xEE42A8
#define pinstWorldData_x                                           0xF97550


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xDA8218
#define pinstCAudioTriggersWindow_x                                0xDA80A8
#define pinstCCharacterSelect_x                                    0xEE4148
#define pinstCFacePick_x                                           0xEE40F8
#define pinstCNoteWnd_x                                            0xEE4100
#define pinstCBookWnd_x                                            0xEE4108
#define pinstCPetInfoWnd_x                                         0xEE410C
#define pinstCTrainWnd_x                                           0xEE4110
#define pinstCSkillsWnd_x                                          0xEE4114
#define pinstCSkillsSelectWnd_x                                    0xEE4118
#define pinstCCombatSkillSelectWnd_x                               0xEE411C
#define pinstCFriendsWnd_x                                         0xEE4120
#define pinstCAuraWnd_x                                            0xEE4124
#define pinstCRespawnWnd_x                                         0xEE4128
#define pinstCBandolierWnd_x                                       0xEE412C
#define pinstCPotionBeltWnd_x                                      0xEE4130
#define pinstCAAWnd_x                                              0xEE4134
#define pinstCGroupSearchFiltersWnd_x                              0xEE4138
#define pinstCLoadskinWnd_x                                        0xEE413C
#define pinstCAlarmWnd_x                                           0xEE4140
#define pinstCMusicPlayerWnd_x                                     0xEE4144
#define pinstCMailWnd_x                                            0xEE414C
#define pinstCMailCompositionWnd_x                                 0xEE4150
#define pinstCMailAddressBookWnd_x                                 0xEE4154
#define pinstCRaidWnd_x                                            0xEE415C
#define pinstCRaidOptionsWnd_x                                     0xEE4160
#define pinstCBreathWnd_x                                          0xEE4164
#define pinstCMapViewWnd_x                                         0xEE4168
#define pinstCMapToolbarWnd_x                                      0xEE416C
#define pinstCEditLabelWnd_x                                       0xEE4170
#define pinstCTargetWnd_x                                          0xEE4174
#define pinstCColorPickerWnd_x                                     0xEE4178
#define pinstCPlayerWnd_x                                          0xEE417C
#define pinstCOptionsWnd_x                                         0xEE4180
#define pinstCBuffWindowNORMAL_x                                   0xEE4184
#define pinstCBuffWindowSHORT_x                                    0xEE4188
#define pinstCharacterCreation_x                                   0xEE418C
#define pinstCCursorAttachment_x                                   0xEE4190
#define pinstCCastingWnd_x                                         0xEE4194
#define pinstCCastSpellWnd_x                                       0xEE4198
#define pinstCSpellBookWnd_x                                       0xEE419C
#define pinstCInventoryWnd_x                                       0xEE41A0
#define pinstCBankWnd_x                                            0xEE41A4
#define pinstCQuantityWnd_x                                        0xEE41A8
#define pinstCLootWnd_x                                            0xEE41AC
#define pinstCActionsWnd_x                                         0xEE41B0
#define pinstCCombatAbilityWnd_x                                   0xEE41B4
#define pinstCMerchantWnd_x                                        0xEE41B8
#define pinstCTradeWnd_x                                           0xEE41BC
#define pinstCSelectorWnd_x                                        0xEE41C0
#define pinstCBazaarWnd_x                                          0xEE41C4
#define pinstCBazaarSearchWnd_x                                    0xEE41C8
#define pinstCGiveWnd_x                                            0xEE41E4
#define pinstCTrackingWnd_x                                        0xEE41EC
#define pinstCInspectWnd_x                                         0xEE41F0
#define pinstCSocialEditWnd_x                                      0xEE41F4
#define pinstCFeedbackWnd_x                                        0xEE41F8
#define pinstCBugReportWnd_x                                       0xEE41FC
#define pinstCVideoModesWnd_x                                      0xEE4200
#define pinstCTextEntryWnd_x                                       0xEE4208
#define pinstCFileSelectionWnd_x                                   0xEE420C
#define pinstCCompassWnd_x                                         0xEE4210
#define pinstCPlayerNotesWnd_x                                     0xEE4214
#define pinstCGemsGameWnd_x                                        0xEE4218
#define pinstCTimeLeftWnd_x                                        0xEE421C
#define pinstCPetitionQWnd_x                                       0xEE4230
#define pinstCSoulmarkWnd_x                                        0xEE4234
#define pinstCStoryWnd_x                                           0xEE4238
#define pinstCJournalTextWnd_x                                     0xEE423C
#define pinstCJournalCatWnd_x                                      0xEE4240
#define pinstCBodyTintWnd_x                                        0xEE4244
#define pinstCServerListWnd_x                                      0xEE4248
#define pinstCAvaZoneWnd_x                                         0xEE4254
#define pinstCBlockedBuffWnd_x                                     0xEE4258
#define pinstCBlockedPetBuffWnd_x                                  0xEE425C
#define pinstCInvSlotMgr_x                                         0xEE42A0
#define pinstCContainerMgr_x                                       0xEE42A4
#define pinstCAdventureLeaderboardWnd_x                            0x1136B28
#define pinstCAdventureRequestWnd_x                                0x1136BA0
#define pinstCAltStorageWnd_x                                      0x1136E80
#define pinstCAdventureStatsWnd_x                                  0x1136C18
#define pinstCBarterMerchantWnd_x                                  0x1137A68
#define pinstCBarterSearchWnd_x                                    0x1137AE0
#define pinstCBarterWnd_x                                          0x1137B58
#define pinstCChatManager_x                                        0x11381E8
#define pinstCDynamicZoneWnd_x                                     0x1138698
#define pinstCEQMainWnd_x                                          0x1138830
#define pinstCFellowshipWnd_x                                      0x113862C
#define pinstCFindLocationWnd_x                                    0x1138B00
#define pinstCGroupSearchWnd_x                                     0x1138DD0
#define pinstCGroupWnd_x                                           0x1138E48
#define pinstCGuildBankWnd_x                                       0x1138EC0
#define pinstCGuildMgmtWnd_x                                       0x113AFB0
#define pinstCHotButtonWnd_x                                       0x113B07C
#define pinstCHotButtonWnd1_x                                      0x113B07C
#define pinstCHotButtonWnd2_x                                      0x113B080
#define pinstCHotButtonWnd3_x                                      0x113B084
#define pinstCHotButtonWnd4_x                                      0x113B0A8
#define pinstCItemDisplayManager_x                                 0x113B3A0
#define pinstCItemExpTransferWnd_x                                 0x113B41C
#define pinstCLFGuildWnd_x                                         0x113B6F8
#define pinstCMIZoneSelectWnd_x                                    0x113BCE0
#define pinstCConfirmationDialog_x                                 0x113C3E8
#define pinstCPopupWndManager_x                                    0x113C3E8
#define pinstCProgressionSelectionWnd_x                            0x113C4D8
#define pinstCPvPStatsWnd_x                                        0x113C5C8
#define pinstCSystemInfoDialogBox_x                                0x113CCD0
#define pinstCTaskWnd_x                                            0x113E098
#define pinstCTaskSomething_x                                      0xDB2340
#define pinstCTaskTemplateSelectWnd_x                              0x113E020
#define pinstCTipWndOFDAY_x                                        0x113E2F0
#define pinstCTipWndCONTEXT_x                                      0x113E2F4
#define pinstCTitleWnd_x                                           0x113E370
#define pinstCContextMenuManager_x                                 0x179FA04
#define pinstCVoiceMacroWnd_x                                      0x102AFA8
#define pinstCHtmlWnd_x                                            0x102B0A0
#define pinstIconCache_x                                           0x1138804
#define pinstCTradeskillWnd_x                                      0x113E470
#define pinstCAdvancedLootWnd_x                                    0xEE4294
#define pinstRewardSelectionWnd_x                                  0x113CAF0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x529200
#define __ConvertItemTags_x                                        0x516480
#define __ExecuteCmd_x                                             0x500E70
#define __EQGetTime_x                                              0x85D4E0
#define __get_melee_range_x                                        0x507B30
#define __GetGaugeValueFromEQ_x                                    0x79D520
#define __GetLabelFromEQ_x                                         0x79E760
#define __ToggleMount_x                                            0x6C6C30
#define __GetXTargetType_x                                         0x91B7B0
#define __LoadFrontEnd_x                                           0x62BD50
#define __NewUIINI_x                                               0x79CE30
#define __ProcessGameEvents_x                                      0x56CE70
#define __ProcessMouseEvent_x                                      0x56C610
#define CrashDetected_x                                            0x62D820
#define wwsCrashReportCheckForUploader_x                           0x7F25B0
#define DrawNetStatus_x                                            0x5A3C90
#define Util__FastTime_x                                           0x85D030
#define Expansion_HoT_x                                            0xFA5994
#define __HelpPath_x                                               0x10290F8
//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41ED10
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419B80

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C0CC0
#define AltAdvManager__IsAbilityReady_x                            0x4C0D30
#define AltAdvManager__GetAltAbility_x                             0x4C10F0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4649B0
#define CharacterZoneClient__MakeMeVisible_x                       0x469AE0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x65B430

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x669AD0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x583290

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x684710
#define CChatManager__InitContextMenu_x                            0x685230

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8CD600
#define CContextMenu__AddMenuItem_x                                0x8CD810
#define CContextMenu__dCContextMenu_x                              0x8CD800
#define CContextMenu__RemoveMenuItem_x                             0x8CDAF0
#define CContextMenu__RemoveAllMenuItems_x                         0x8CDB10
#define CContextMenuManager__AddMenu_x                             0x8B95C0
#define CContextMenuManager__RemoveMenu_x                          0x8B98F0
#define CContextMenuManager__PopupMenu_x                           0x8B9D40
#define CContextMenuManager__Flush_x                               0x8B9630
#define CContextMenuManager__GetMenu_x                             0x4151D0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x843BB0
#define CChatService__GetFriendName_x                              0x843BC0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x68A2A0
#define CChatWindow__Clear_x                                       0x689E50
#define CChatWindow__WndNotification_x                             0x68A7D0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8BD490
#define CComboWnd__Draw_x                                          0x8BD6A0
#define CComboWnd__GetCurChoice_x                                  0x8BD260
#define CComboWnd__GetListRect_x                                   0x8BD940
#define CComboWnd__GetTextRect_x                                   0x8BD500
#define CComboWnd__InsertChoice_x                                  0x8BD9B0
#define CComboWnd__SetColors_x                                     0x8BD1F0
#define CComboWnd__SetChoice_x                                     0x8BD220
#define CComboWnd__GetItemCount_x                                  0x8BD250

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x693990
#define CContainerWnd__vftable_x                                   0xA876B8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4AEF60
#define CDisplay__GetClickedActor_x                                0x4A7AE0
#define CDisplay__GetUserDefinedColor_x                            0x4A63A0
#define CDisplay__GetWorldFilePath_x                               0x4A57F0
#define CDisplay__is3dON_x                                         0x4A4BC0
#define CDisplay__ReloadUI_x                                       0x4BA430
#define CDisplay__WriteTextHD2_x                                   0x4AB300

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E3B30

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D1F30
#define CEditWnd__GetCharIndexPt_x                                 0x8D2FB0
#define CEditWnd__GetDisplayString_x                               0x8D20E0
#define CEditWnd__GetHorzOffset_x                                  0x8D2420
#define CEditWnd__GetLineForPrintableChar_x                        0x8D2A80
#define CEditWnd__GetSelStartPt_x                                  0x8D3260
#define CEditWnd__GetSTMLSafeText_x                                0x8D25B0
#define CEditWnd__PointFromPrintableChar_x                         0x8D2B70
#define CEditWnd__SelectableCharFromPoint_x                        0x8D2CF0
#define CEditWnd__SetEditable_x                                    0x8D2580

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x54A7E0
#define CEverQuest__DoTellWindow_x                                 0x5501D0
#define CEverQuest__DropHeldItemOnGround_x                         0x558D00
#define CEverQuest__dsp_chat_x                                     0x551970
#define CEverQuest__Emote_x                                        0x551BD0
#define CEverQuest__EnterZone_x                                    0x565450
#define CEverQuest__GetBodyTypeDesc_x                              0x547040
#define CEverQuest__GetClassDesc_x                                 0x54CD50
#define CEverQuest__GetClassThreeLetterCode_x                      0x54D350
#define CEverQuest__GetDeityDesc_x                                 0x547920
#define CEverQuest__GetLangDesc_x                                  0x5473D0
#define CEverQuest__GetRaceDesc_x                                  0x54D510
#define CEverQuest__InterpretCmd_x                                 0x5524B0
#define CEverQuest__LeftClickedOnPlayer_x                          0x569570
#define CEverQuest__LMouseUp_x                                     0x56B660
#define CEverQuest__RightClickedOnPlayer_x                         0x56A070
#define CEverQuest__RMouseUp_x                                     0x56B0C0
#define CEverQuest__SetGameState_x                                 0x54AE90
#define CEverQuest__UPCNotificationFlush_x                         0x553650
#define CEverQuest__IssuePetCommand_x                              0x5531B0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A4550
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A45B0
#define CGaugeWnd__Draw_x                                          0x6A49E0

// CGuild
#define CGuild__FindMemberByName_x                                 0x435B60

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C1670

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6CF450
#define CInvSlotMgr__MoveItem_x                                    0x6D0380
#define CInvSlotMgr__SelectSlot_x                                  0x6CF500

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6CE8F0
#define CInvSlot__SliderComplete_x                                 0x6CC2B0
#define CInvSlot__GetItemBase_x                                    0x6CB730

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D1550

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79A040
#define CItemDisplayWnd__UpdateStrings_x                           0x6D2890

// CLabel 
#define CLabel__Draw_x                                             0x6ED640

// CListWnd 
#define CListWnd__CListWnd_x                                       0x8A93D0
#define CListWnd__dCListWnd_x                                      0x8AA3E0
#define CListWnd__AddColumn_x                                      0x8AA380
#define CListWnd__AddColumn1_x                                     0x8A9C00
#define CListWnd__AddLine_x                                        0x8A9680
#define CListWnd__AddString_x                                      0x8A9890
#define CListWnd__CalculateFirstVisibleLine_x                      0x8A6720
#define CListWnd__CalculateVSBRange_x                              0x8A8880
#define CListWnd__ClearAllSel_x                                    0x8A59E0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8A9260
#define CListWnd__Compare_x                                        0x8A7210
#define CListWnd__Draw_x                                           0x8A8490
#define CListWnd__DrawColumnSeparators_x                           0x8A8320
#define CListWnd__DrawHeader_x                                     0x8A5CF0
#define CListWnd__DrawItem_x                                       0x8A7860
#define CListWnd__DrawLine_x                                       0x8A7FC0
#define CListWnd__DrawSeparator_x                                  0x8A83C0
#define CListWnd__EnsureVisible_x                                  0x8A6880
#define CListWnd__ExtendSel_x                                      0x8A7770
#define CListWnd__GetColumnMinWidth_x                              0x8A53A0
#define CListWnd__GetColumnWidth_x                                 0x8A52C0
#define CListWnd__GetCurSel_x                                      0x8A4A90
#define CListWnd__GetItemAtPoint_x                                 0x8A6B10
#define CListWnd__GetItemAtPoint1_x                                0x8A6B80
#define CListWnd__GetItemData_x                                    0x8A4DD0
#define CListWnd__GetItemHeight_x                                  0x8A6380
#define CListWnd__GetItemIcon_x                                    0x8A4FB0
#define CListWnd__GetItemRect_x                                    0x8A6950
#define CListWnd__GetItemText_x                                    0x8A4E60
#define CListWnd__GetSelList_x                                     0x8A9AF0
#define CListWnd__GetSeparatorRect_x                               0x8A7130
#define CListWnd__RemoveLine_x                                     0x8A9A70
#define CListWnd__SetColors_x                                      0x8A4BE0
#define CListWnd__SetColumnJustification_x                         0x8A5670
#define CListWnd__SetColumnWidth_x                                 0x8A5350
#define CListWnd__SetCurSel_x                                      0x8A4AD0
#define CListWnd__SetItemColor_x                                   0x8A8F40
#define CListWnd__SetItemData_x                                    0x8A5A90
#define CListWnd__SetItemText_x                                    0x8A8D80
#define CListWnd__ShiftColumnSeparator_x                           0x8A8C10
#define CListWnd__Sort_x                                           0x8AA4E0
#define CListWnd__ToggleSel_x                                      0x8A5960

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x706BF0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x727D00
#define CMerchantWnd__RequestBuyItem_x                             0x72EB40
#define CMerchantWnd__RequestSellItem_x                            0x72F5B0
#define CMerchantWnd__SelectRecoverySlot_x                         0x727FB0
#define CMerchantWnd__SelectBuySellSlot_x                          0x727210
#define CMerchantWnd__ActualSelect_x                               0x72BA70

// CObfuscator
#define CObfuscator__doit_x                                        0x823E30

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8C8490
#define CSidlManager__CreateLabel_x                                0x790060

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x652760
#define CSidlScreenWnd__CalculateVSBRange_x                        0x652680
#define CSidlScreenWnd__ConvertToRes_x                             0x8E3A10
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8C0110
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C15F0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C16A0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C0B90
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8BFAC0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8BF210
#define CSidlScreenWnd__GetSidlPiece_x                             0x8BFCB0
#define CSidlScreenWnd__Init1_x                                    0x8C12E0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C01C0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8BF3D0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C0DE0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8BECD0
#define CSidlScreenWnd__StoreIniVis_x                              0x8BF1A0
#define CSidlScreenWnd__WndNotification_x                          0x8C1060
#define CSidlScreenWnd__GetChildItem_x                             0x8BF2E0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B28A0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5EDE10
#define CSkillMgr__GetSkillCap_x                                   0x5EDFB0
#define CSkillMgr__GetNameToken_x                                  0x5EDA80

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E2CE0
#define CSliderWnd__SetValue_x                                     0x8E2EB0
#define CSliderWnd__SetNumTicks_x                                  0x8E3630

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x797CE0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8DD6F0
#define CStmlWnd__CalculateHSBRange_x                              0x8D5CB0
#define CStmlWnd__CalculateVSBRange_x                              0x8D5C20
#define CStmlWnd__CanBreakAtCharacter_x                            0x8D5E30
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8D6710
#define CStmlWnd__ForceParseNow_x                                  0x8DE040
#define CStmlWnd__GetNextTagPiece_x                                0x8D6610
#define CStmlWnd__GetSTMLText_x                                    0x6896F0
#define CStmlWnd__GetVisibleText_x                                 0x8D7160
#define CStmlWnd__InitializeWindowVariables_x                      0x8D94F0
#define CStmlWnd__MakeStmlColorTag_x                               0x8D4F20
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D4F80
#define CStmlWnd__SetSTMLText_x                                    0x8DAD60
#define CStmlWnd__StripFirstSTMLLines_x                            0x8DD390
#define CStmlWnd__UpdateHistoryString_x                            0x8D80A0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E5200
#define CTabWnd__DrawCurrentPage_x                                 0x8E4A70
#define CTabWnd__DrawTab_x                                         0x8E4840
#define CTabWnd__GetCurrentPage_x                                  0x8E4E40
#define CTabWnd__GetPageInnerRect_x                                0x8E4530
#define CTabWnd__GetTabInnerRect_x                                 0x8E4730
#define CTabWnd__GetTabRect_x                                      0x8E4600
#define CTabWnd__InsertPage_x                                      0x8E54F0
#define CTabWnd__SetPage_x                                         0x8E4E70
#define CTabWnd__SetPageRect_x                                     0x8E5140
#define CTabWnd__UpdatePage_x                                      0x8E5490

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431940

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8BCE60

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8EA3A0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A2BA0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402290
#define CXStr__CXStr1_x                                            0x8E90D0
#define CXStr__CXStr3_x                                            0x85A0C0
#define CXStr__dCXStr_x                                            0x6A4430
#define CXStr__operator_equal_x                                    0x85A230
#define CXStr__operator_equal1_x                                   0x85A280
#define CXStr__operator_plus_equal1_x                              0x85B360

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B1B00
#define CXWnd__Center_x                                            0x8B7C20
#define CXWnd__ClrFocus_x                                          0x8B16E0
#define CXWnd__DoAllDrawing_x                                      0x8B7870
#define CXWnd__DrawChildren_x                                      0x8B7A10

#define CXWnd__DrawColoredRect_x                                   0x8B1EA0
#define CXWnd__DrawTooltip_x                                       0x8B2150
#define CXWnd__DrawTooltipAtPoint_x                                0x8B6810
#define CXWnd__GetBorderFrame_x                                    0x8B25B0
#define CXWnd__GetChildWndAt_x                                     0x8B85C0
#define CXWnd__GetClientClipRect_x                                 0x8B2370
#define CXWnd__GetScreenClipRect_x                                 0x8B6F00
#define CXWnd__GetScreenRect_x                                     0x8B2740
#define CXWnd__GetTooltipRect_x                                    0x8B1FE0
#define CXWnd__GetWindowTextA_x                                    0x422D20
#define CXWnd__IsActive_x                                          0x8AD180
#define CXWnd__IsDescendantOf_x                                    0x8B2500
#define CXWnd__IsReallyVisible_x                                   0x8B5850
#define CXWnd__IsType_x                                            0x8E6B70
#define CXWnd__Move_x                                              0x8B4F30
#define CXWnd__Move1_x                                             0x8B7520
#define CXWnd__ProcessTransition_x                                 0x8B1AA0
#define CXWnd__Refade_x                                            0x8B1880
#define CXWnd__Resize_x                                            0x8B2800
#define CXWnd__Right_x                                             0x8B6D00
#define CXWnd__SetFocus_x                                          0x8B40A0
#define CXWnd__SetFont_x                                           0x8B1730
#define CXWnd__SetKeyTooltip_x                                     0x8B2A70
#define CXWnd__SetMouseOver_x                                      0x8B7230
#define CXWnd__StartFade_x                                         0x8B1B50
#define CXWnd__GetChildItem_x                                      0x8B7180

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8AEA90
#define CXWndManager__DrawWindows_x                                0x8AE6E0
#define CXWndManager__GetKeyboardFlags_x                           0x8ACCF0
#define CXWndManager__HandleKeyboardMsg_x                          0x8AD610
#define CXWndManager__RemoveWnd_x                                  0x8AD310

// CDBStr
#define CDBStr__GetString_x                                        0x4A2FD0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44EDA0
#define EQ_Character__Cur_HP_x                                     0x464080
#define EQ_Character__GetAACastingTimeModifier_x                   0x446E10
#define EQ_Character__GetCharInfo2_x                               0x82E5A0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EF60
#define EQ_Character__GetFocusRangeModifier_x                      0x43F140
#define EQ_Character__Max_Endurance_x                              0x5B5A40
#define EQ_Character__Max_HP_x                                     0x459D00
#define EQ_Character__Max_Mana_x                                   0x5B5870
#define EQ_Character__doCombatAbility_x                            0x5B2E70
#define EQ_Character__UseSkill_x                                   0x46ECE0
#define EQ_Character__GetConLevel_x                                0x5A82A0
#define EQ_Character__IsExpansionFlag_x                            0x422260
#define EQ_Character__TotalEffect_x                                0x44BF20

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x588A10
#define EQ_Item__CreateItemTagString_x                             0x80DCE0
#define EQ_Item__IsStackable_x                                     0x8021E0
#define EQ_Item__GetImageNum_x                                     0x804F10

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C2E30
#define EQ_LoadingS__Array_x                                       0xBA8848

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5B71E0
#define EQ_PC__GetAltAbilityIndex_x                                0x816B90
#define EQ_PC__GetCombatAbility_x                                  0x816C20
#define EQ_PC__GetCombatAbilityTimer_x                             0x816CD0
#define EQ_PC__GetItemTimerValue_x                                 0x5B0C50
#define EQ_PC__HasLoreItem_x                                       0x5AB5E0
#define EQ_PC__AlertInventoryChanged_x                             0x5A8270
#define EQ_PC__GetPcZoneClient_x                                   0x5D1750
#define EQ_PC__RemoveMyAffect_x                                    0x5B0160

// EQItemList 
#define EQItemList__EQItemList_x                                   0x505B20
#define EQItemList__add_item_x                                     0x505A60
#define EQItemList__delete_item_x                                  0x505F20
#define EQItemList__FreeItemList_x                                 0x505E20

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A2240

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5BC790
#define EQPlayer__dEQPlayer_x                                      0x5C55B0
#define EQPlayer__DoAttack_x                                       0x5D7620
#define EQPlayer__EQPlayer_x                                       0x5C79D0
#define EQPlayer__SetNameSpriteState_x                             0x5C2290
#define EQPlayer__SetNameSpriteTint_x                              0x5BDB60
#define EQPlayer__IsBodyType_j_x                                   0x917A30
#define EQPlayer__IsTargetable_x                                   0x9182F0
#define EQPlayer__CanSee_x                                         0x918810

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5CBCF0
#define EQPlayerManager__GetSpawnByName_x                          0x5CC150

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x58EB50
#define KeypressHandler__AttachKeyToEqCommand_x                    0x58EB90
#define KeypressHandler__ClearCommandStateArray_x                  0x58E730
#define KeypressHandler__HandleKeyDown_x                           0x58D090
#define KeypressHandler__HandleKeyUp_x                             0x58D3B0
#define KeypressHandler__SaveKeymapping_x                          0x58E800

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6FEFD0
#define MapViewMap__SaveEx_x                                       0x7028B0

#define PlayerPointManager__GetAltCurrency_x                       0x829560

// StringTable 
#define StringTable__getString_x                                   0x8240D0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B54F0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5443E0

//IconCache
#define IconCache__GetIcon_x                                       0x699DE0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x690CB0
#define CContainerMgr__CloseContainer_x                            0x6914D0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7602B0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x581D40

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D6720
#define EQ_Spell__SpellAffects_x                                   0x4D67C0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D67F0
#define CharacterZoneClient__CalcAffectChange_x                    0x448130
#define CLootWnd__LootAll_x                                        0x6F4930
//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x74A1B0
#define CTargetWnd__WndNotification_x                              0x7A55F0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7AACC0
