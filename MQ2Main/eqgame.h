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
#define __ExpectedVersionDate                                     "Sep 24 2015"
#define __ExpectedVersionTime                                     "12:54:05"
#define __ActualVersionDate_x                                      0xACBAB0
#define __ActualVersionTime_x                                      0xACBABC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x599AC0
#define __MemChecker1_x                                            0x896BC0
#define __MemChecker2_x                                            0x632B20
#define __MemChecker3_x                                            0x632A70
#define __MemChecker4_x                                            0x7E8910
#define __EncryptPad0_x                                            0xC61FE0
#define __EncryptPad1_x                                            0xDEBB58
#define __EncryptPad2_x                                            0xCABAC8
#define __EncryptPad3_x                                            0xCAB6C8
#define __EncryptPad4_x                                            0xDC6240
#define __EncryptPad5_x                                            0x11978F0
#define __AC1_x                                                    0x7A5AC5
#define __AC2_x                                                    0x54EEE7
#define __AC3_x                                                    0x5636E0
#define __AC4_x                                                    0x56A360
#define __AC5_x                                                    0x5761EE
#define __AC6_x                                                    0x579C99
#define __AC7_x                                                    0x57089C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data                                                 0x845E8

// Direct Input
#define DI8__Main_x                                                0x11978C8
#define DI8__Keyboard_x                                            0x11978CC
#define DI8__Mouse_x                                               0x11978D0
#define DI8__Mouse_Copy_x                                          0x1005EE4
#define DI8__Mouse_Check_x                                         0x108F7B4
#define __AltTimerReady_x                                          0xFF7231
#define __Attack_x                                                 0x108A453
#define __Autofire_x                                               0x108A454
#define __BindList_x                                               0xC240F0
#define __bCommandEnabled_x                                        0xFF5340
#define __Clicks_x                                                 0x1005FA0
#define __CommandList_x                                            0xC28460
#define __CurrentMapLabel_x                                        0x119D320
#define __CurrentSocial_x                                          0xBDDF54
#define __DoAbilityList_x                                          0x103C708
#define __do_loot_x                                                0x5163B0
#define __DrawHandler_x                                            0x180400C
#define __GroupCount_x                                             0xFF690A

#define __Guilds_x                                                 0xFFC520
#define __gWorld_x                                                 0xFF8DC4
#define __HotkeyPage_x                                             0x1083108
#define __HWnd_x                                                   0x108F7D0
#define __InChatMode_x                                             0x1005ECC
#define __LastTell_x                                               0x1007E10
#define __LMouseHeldTime_x                                         0x100600C
#define __Mouse_x                                                  0x11978D4
#define __MouseLook_x                                              0x1005F66
#define __MouseEventTime_x                                         0x108AC5C
#define __gpbCommandEvent_x                                        0xFF8E8C
#define __NetStatusToggle_x                                        0x1005F69
#define __PCNames_x                                                0x1007430
#define __RangeAttackReady_x                                       0x10070F0
#define __RMouseHeldTime_x                                         0x1006008
#define __RunWalkState_x                                           0x1005ED0
#define __ScreenMode_x                                             0xF450F0
#define __ScreenX_x                                                0x1005E84
#define __ScreenY_x                                                0x1005E80
#define __ScreenXMax_x                                             0x1005E88
#define __ScreenYMax_x                                             0x1005E8C
#define __ServerHost_x                                             0xFF6854
#define __ServerName_x                                             0x103C6C8
#define __ShiftKeyDown_x                                           0x1006574
#define __ShowNames_x                                              0x10072C4
#define __Socials_x                                                0x103C7C8
#define __SubscriptionType_x                                       0x11CB7F0
#define __TargetAggroHolder_x                                      0x119F55C
#define __GroupAggro_x                                             0x119F59C
#define __LoginName_x                                              0x108E3A8
#define __Inviter_x                                                0x108A3D0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xFF8EB0
#define instEQZoneInfo_x                                           0x100615C
#define instKeypressHandler_x                                      0x108AC40
#define pinstActiveBanker_x                                        0xFF8E68
#define pinstActiveCorpse_x                                        0xFF8E6C
#define pinstActiveGMaster_x                                       0xFF8E70
#define pinstActiveMerchant_x                                      0xFF8E64
#define pinstAggroInfo_x                                           0xE07538
#define pinstAltAdvManager_x                                       0xF461F0
#define pinstAuraMgr_x                                             0xE13438
#define pinstBandageTarget_x                                       0xFF8E50
#define pinstCamActor_x                                            0xF45AFC
#define pinstCDBStr_x                                              0xF45084
#define pinstCDisplay_x                                            0xFF8E78
#define pinstCEverQuest_x                                          0x1197A48
#define pinstCharData_x                                            0xFF8E34
#define pinstCharSpawn_x                                           0xFF8E5C
#define pinstControlledMissile_x                                   0xFF8E30
#define pinstControlledPlayer_x                                    0xFF8E5C
#define pinstCSidlManager_x                                        0x1803444
#define pinstCXWndManager_x                                        0x180343C
#define instDynamicZone_x                                          0x1005D18
#define pinstDZMember_x                                            0x1005E28
#define pinstDZTimerInfo_x                                         0x1005E2C
#define pinstEQItemList_x                                          0xFF5590
#define instEQMisc_x                                               0xBFEC58
#define pinstEQSoundManager_x                                      0xF466D8
#define instExpeditionLeader_x                                     0x1005D62
#define instExpeditionName_x                                       0x1005DA2
#define pinstGroup_x                                               0xFF6906
#define pinstImeManager_x                                          0x1803448
#define pinstLocalPlayer_x                                         0xFF8E48
#define pinstMercenaryData_x                                       0x108B290
#define pinstMercenaryStats_x                                      0x119F6A8
#define pinstMercAltAbilities_x                                    0xF4657C
#define pinstModelPlayer_x                                         0xFF8E74
#define pinstPCData_x                                              0xFF8E34
#define pinstSkillMgr_x                                            0x108C0C8
#define pinstSpawnManager_x                                        0x108B9B0
#define pinstSpellManager_x                                        0x108C210
#define pinstSpellSets_x                                           0x108316C
#define pinstStringTable_x                                         0xFF8DDC
#define pinstSwitchManager_x                                       0xFF6498
#define pinstTarget_x                                              0xFF8E60
#define pinstTargetObject_x                                        0xFF8E38
#define pinstTargetSwitch_x                                        0xFF8E3C
#define pinstTaskMember_x                                          0xF44FD0
#define pinstTrackTarget_x                                         0xFF8E54
#define pinstTradeTarget_x                                         0xFF8E44
#define instTributeActive_x                                        0xBFEC7D
#define pinstViewActor_x                                           0xF45AF8
#define pinstWorldData_x                                           0xFF8E18


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE07A18
#define pinstCAudioTriggersWindow_x                                0xE078A8
#define pinstCCharacterSelect_x                                    0xF45994
#define pinstCFacePick_x                                           0xF45744
#define pinstCNoteWnd_x                                            0xF4594C
#define pinstCBookWnd_x                                            0xF45954
#define pinstCPetInfoWnd_x                                         0xF45958
#define pinstCTrainWnd_x                                           0xF4595C
#define pinstCSkillsWnd_x                                          0xF45960
#define pinstCSkillsSelectWnd_x                                    0xF45964
#define pinstCCombatSkillsSelectWnd_x                              0xF45968
#define pinstCFriendsWnd_x                                         0xF4596C
#define pinstCAuraWnd_x                                            0xF45970
#define pinstCRespawnWnd_x                                         0xF45974
#define pinstCBandolierWnd_x                                       0xF45978
#define pinstCPotionBeltWnd_x                                      0xF4597C
#define pinstCAAWnd_x                                              0xF45980
#define pinstCGroupSearchFiltersWnd_x                              0xF45984
#define pinstCLoadskinWnd_x                                        0xF45988
#define pinstCAlarmWnd_x                                           0xF4598C
#define pinstCMusicPlayerWnd_x                                     0xF45990
#define pinstCMailWnd_x                                            0xF45998
#define pinstCMailCompositionWnd_x                                 0xF4599C
#define pinstCMailAddressBookWnd_x                                 0xF459A0
#define pinstCRaidWnd_x                                            0xF459A8
#define pinstCRaidOptionsWnd_x                                     0xF459AC
#define pinstCBreathWnd_x                                          0xF459B0
#define pinstCMapViewWnd_x                                         0xF459B4
#define pinstCMapToolbarWnd_x                                      0xF459B8
#define pinstCEditLabelWnd_x                                       0xF459BC
#define pinstCTargetWnd_x                                          0xF459C0
#define pinstCColorPickerWnd_x                                     0xF459C4
#define pinstCPlayerWnd_x                                          0xF459C8
#define pinstCOptionsWnd_x                                         0xF459CC
#define pinstCBuffWindowNORMAL_x                                   0xF459D0
#define pinstCBuffWindowSHORT_x                                    0xF459D4
#define pinstCharacterCreation_x                                   0xF459D8
#define pinstCCursorAttachment_x                                   0xF459DC
#define pinstCCastingWnd_x                                         0xF459E0
#define pinstCCastSpellWnd_x                                       0xF459E4
#define pinstCSpellBookWnd_x                                       0xF459E8
#define pinstCInventoryWnd_x                                       0xF459EC
#define pinstCBankWnd_x                                            0xF459F0
#define pinstCQuantityWnd_x                                        0xF459F4
#define pinstCLootWnd_x                                            0xF459F8
#define pinstCActionsWnd_x                                         0xF459FC
#define pinstCCombatAbilityWnd_x                                   0xF45A00
#define pinstCMerchantWnd_x                                        0xF45A04
#define pinstCTradeWnd_x                                           0xF45A08
#define pinstCSelectorWnd_x                                        0xF45A0C
#define pinstCBazaarWnd_x                                          0xF45A10
#define pinstCBazaarSearchWnd_x                                    0xF45A14
#define pinstCGiveWnd_x                                            0xF45A30
#define pinstCTrackingWnd_x                                        0xF45A38
#define pinstCInspectWnd_x                                         0xF45A3C
#define pinstCSocialEditWnd_x                                      0xF45A40
#define pinstCFeedbackWnd_x                                        0xF45A44
#define pinstCBugReportWnd_x                                       0xF45A48
#define pinstCVideoModesWnd_x                                      0xF45A4C
#define pinstCTextEntryWnd_x                                       0xF45A54
#define pinstCFileSelectionWnd_x                                   0xF45A58
#define pinstCCompassWnd_x                                         0xF45A5C
#define pinstCPlayerNotesWnd_x                                     0xF45A60
#define pinstCGemsGameWnd_x                                        0xF45A64
#define pinstCTimeLeftWnd_x                                        0xF45A68
#define pinstCPetitionQWnd_x                                       0xF45A80
#define pinstCSoulmarkWnd_x                                        0xF45A84
#define pinstCStoryWnd_x                                           0xF45A88
#define pinstCJournalTextWnd_x                                     0xF45A8C
#define pinstCJournalCatWnd_x                                      0xF45A90
#define pinstCBodyTintWnd_x                                        0xF45A94
#define pinstCServerListWnd_x                                      0xF45A98
#define pinstCAvaZoneWnd_x                                         0xF45AA4
#define pinstCBlockedBuffWnd_x                                     0xF45AA8
#define pinstCBlockedPetBuffWnd_x                                  0xF45AAC
#define pinstCInvSlotMgr_x                                         0xF45AF0
#define pinstCContainerMgr_x                                       0xF45AF4
#define pinstCAdventureLeaderboardWnd_x                            0x11983F8
#define pinstCAdventureRequestWnd_x                                0x1198470
#define pinstCAltStorageWnd_x                                      0x1198750
#define pinstCAdventureStatsWnd_x                                  0x11984E8
#define pinstCBarterMerchantWnd_x                                  0x1199338
#define pinstCBarterSearchWnd_x                                    0x11993B0
#define pinstCBarterWnd_x                                          0x1199428
#define pinstCChatManager_x                                        0x1199AB8
#define pinstCDynamicZoneWnd_x                                     0x1199F68
#define pinstCEQMainWnd_x                                          0x119A100
#define pinstCFellowshipWnd_x                                      0x1199EFC
#define pinstCFindLocationWnd_x                                    0x119A3D0
#define pinstCGroupSearchWnd_x                                     0x119A6A0
#define pinstCGroupWnd_x                                           0x119A718
#define pinstCGuildBankWnd_x                                       0x119A790
#define pinstCGuildMgmtWnd_x                                       0x119C880
#define pinstCHotButtonWnd_x                                       0x119C94C
#define pinstCHotButtonWnd1_x                                      0x119C94C
#define pinstCHotButtonWnd2_x                                      0x119C950
#define pinstCHotButtonWnd3_x                                      0x119C954
#define pinstCHotButtonWnd4_x                                      0x119C978
#define pinstCItemDisplayManager_x                                 0x119CC70
#define pinstCItemExpTransferWnd_x                                 0x119CCEC
#define pinstCLFGuildWnd_x                                         0x119CFC8
#define pinstCMIZoneSelectWnd_x                                    0x119D5B0
#define pinstCConfirmationDialog_x                                 0x119DCB8
#define pinstCPopupWndManager_x                                    0x119DCB8
#define pinstCProgressionSelectionWnd_x                            0x119DDA8
#define pinstCPvPStatsWnd_x                                        0x119DE98
#define pinstCSystemInfoDialogBox_x                                0x119E5A0
#define pinstCTaskWnd_x                                            0x119F968
#define pinstCTaskSomething_x                                      0xE13B78
#define pinstCTaskTemplateSelectWnd_x                              0x119F8F0
#define pinstCTipWndOFDAY_x                                        0x119FBC0
#define pinstCTipWndCONTEXT_x                                      0x119FBC4
#define pinstCTitleWnd_x                                           0x119FC40
#define pinstCContextMenuManager_x                                 0x18033B4
#define pinstCVoiceMacroWnd_x                                      0x108C878
#define pinstCHtmlWnd_x                                            0x108C970
#define pinstIconCache_x                                           0x119A0D4
#define pinstCTradeskillWnd_x                                      0x119FD40
#define pinstCAdvancedLootWnd_x                                    0xF45AE4
#define pinstRewardSelectionWnd_x                                  0x119E3C0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x52DED0
#define __ConvertItemTags_x                                        0x51B030
#define __ExecuteCmd_x                                             0x505B10
#define __EQGetTime_x                                              0x896F20
#define __get_melee_range_x                                        0x50C7F0
#define __GetGaugeValueFromEQ_x                                    0x7A4800
#define __GetLabelFromEQ_x                                         0x7A5A50
#define __ToggleMount_x                                            0x6CD890
#define __GetXTargetType_x                                         0x928210
#define __LoadFrontEnd_x                                           0x6321D0
#define __NewUIINI_x                                               0x7A4100
#define __ProcessGameEvents_x                                      0x572600
#define __ProcessMouseEvent_x                                      0x571DA0
#define CrashDetected_x                                            0x633CA0
#define wwsCrashReportCheckForUploader_x                           0x7F8140
#define DrawNetStatus_x                                            0x5A9410
#define Util__FastTime_x                                           0x896870
#define Expansion_HoT_x                                            0x100725C
#define __HelpPath_x                                               0x108A9C8

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41F0A0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419EF0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C2660
#define AltAdvManager__IsAbilityReady_x                            0x4C26D0
#define AltAdvManager__GetAAById_x                                 0x4C2A90

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x465620
#define CharacterZoneClient__MakeMeVisible_x                       0x46B000
#define CharacterZoneClient__IsStackBlocked_x                      0x447B20

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x661EC0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66FEA0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x588A70
#define CButtonWnd__CButtonWnd_x                                   0x8CFEB0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68B180
#define CChatManager__InitContextMenu_x                            0x68BD00

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D9F50
#define CContextMenu__dCContextMenu_x                              0x8DA160
#define CContextMenu__AddMenuItem_x                                0x8DA170
#define CContextMenu__RemoveMenuItem_x                             0x8DA460
#define CContextMenu__RemoveAllMenuItems_x                         0x8DA480
#define CContextMenuManager__AddMenu_x                             0x8C5E00
#define CContextMenuManager__RemoveMenu_x                          0x8C6130
#define CContextMenuManager__PopupMenu_x                           0x8C6580
#define CContextMenuManager__Flush_x                               0x8C5E70
#define CContextMenuManager__GetMenu_x                             0x415540

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87CE30
#define CChatService__GetFriendName_x                              0x87CE40

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x690FB0
#define CChatWindow__Clear_x                                       0x690B60
#define CChatWindow__WndNotification_x                             0x6914E0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C9CF0
#define CComboWnd__Draw_x                                          0x8C9F00
#define CComboWnd__GetCurChoice_x                                  0x8C9AC0
#define CComboWnd__GetListRect_x                                   0x8CA1A0
#define CComboWnd__GetTextRect_x                                   0x8C9D60
#define CComboWnd__InsertChoice_x                                  0x8CA210
#define CComboWnd__SetColors_x                                     0x8C9A50
#define CComboWnd__SetChoice_x                                     0x8C9A80
#define CComboWnd__GetItemCount_x                                  0x8C9AB0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69A6F0
#define CContainerWnd__vftable_x                                   0xAD5448

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B08C0
#define CDisplay__GetClickedActor_x                                0x4A9440
#define CDisplay__GetUserDefinedColor_x                            0x4A7D00
#define CDisplay__GetWorldFilePath_x                               0x4A7150
#define CDisplay__is3dON_x                                         0x4A6520
#define CDisplay__ReloadUI_x                                       0x4BBDE0
#define CDisplay__WriteTextHD2_x                                   0x4ACC60

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F0640

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DE9E0
#define CEditWnd__GetCharIndexPt_x                                 0x8DFA70
#define CEditWnd__GetDisplayString_x                               0x8DEB90
#define CEditWnd__GetHorzOffset_x                                  0x8DEED0
#define CEditWnd__GetLineForPrintableChar_x                        0x8DF540
#define CEditWnd__GetSelStartPt_x                                  0x8DFD20
#define CEditWnd__GetSTMLSafeText_x                                0x8DF070
#define CEditWnd__PointFromPrintableChar_x                         0x8DF630
#define CEditWnd__SelectableCharFromPoint_x                        0x8DF7B0
#define CEditWnd__SetEditable_x                                    0x8DF040

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x54F630
#define CEverQuest__DoTellWindow_x                                 0x555030
#define CEverQuest__DropHeldItemOnGround_x                         0x55DB60
#define CEverQuest__dsp_chat_x                                     0x5567D0
#define CEverQuest__Emote_x                                        0x556A30
#define CEverQuest__EnterZone_x                                    0x56AB80
#define CEverQuest__GetBodyTypeDesc_x                              0x54BE90
#define CEverQuest__GetClassDesc_x                                 0x551BA0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5521A0
#define CEverQuest__GetDeityDesc_x                                 0x54C770
#define CEverQuest__GetLangDesc_x                                  0x54C220
#define CEverQuest__GetRaceDesc_x                                  0x552360
#define CEverQuest__InterpretCmd_x                                 0x557310
#define CEverQuest__LeftClickedOnPlayer_x                          0x56ED00
#define CEverQuest__LMouseUp_x                                     0x570DF0
#define CEverQuest__RightClickedOnPlayer_x                         0x56F800
#define CEverQuest__RMouseUp_x                                     0x570850
#define CEverQuest__SetGameState_x                                 0x54FCE0
#define CEverQuest__UPCNotificationFlush_x                         0x5584B0
#define CEverQuest__IssuePetCommand_x                              0x558010

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AB240
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AB2A0
#define CGaugeWnd__Draw_x                                          0x6AB6D0

// CGuild
#define CGuild__FindMemberByName_x                                 0x435D40

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C82D0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D60F0
#define CInvSlotMgr__MoveItem_x                                    0x6D7030
#define CInvSlotMgr__SelectSlot_x                                  0x6D61A0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D5580
#define CInvSlot__SliderComplete_x                                 0x6D2F40
#define CInvSlot__GetItemBase_x                                    0x6D23C0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D81D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A1190
#define CItemDisplayWnd__UpdateStrings_x                           0x6D9510

// CLabel 
#define CLabel__Draw_x                                             0x6F4340

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B58E0
#define CListWnd__dCListWnd_x                                      0x8B6910
#define CListWnd__AddColumn_x                                      0x8B68B0
#define CListWnd__AddColumn1_x                                     0x8B6120
#define CListWnd__AddLine_x                                        0x8B5BA0
#define CListWnd__AddString_x                                      0x8B5DB0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B2C00
#define CListWnd__CalculateVSBRange_x                              0x8B4D90
#define CListWnd__ClearAllSel_x                                    0x8B1EB0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B5770
#define CListWnd__Compare_x                                        0x8B3710
#define CListWnd__Draw_x                                           0x8B49A0
#define CListWnd__DrawColumnSeparators_x                           0x8B4830
#define CListWnd__DrawHeader_x                                     0x8B21C0
#define CListWnd__DrawItem_x                                       0x8B3D60
#define CListWnd__DrawLine_x                                       0x8B44D0
#define CListWnd__DrawSeparator_x                                  0x8B48D0
#define CListWnd__EnsureVisible_x                                  0x8B2D60
#define CListWnd__ExtendSel_x                                      0x8B3C70
#define CListWnd__GetColumnMinWidth_x                              0x8B1870
#define CListWnd__GetColumnWidth_x                                 0x8B1790
#define CListWnd__GetCurSel_x                                      0x8B0F60
#define CListWnd__GetItemAtPoint_x                                 0x8B3000
#define CListWnd__GetItemAtPoint1_x                                0x8B3070
#define CListWnd__GetItemData_x                                    0x8B12A0
#define CListWnd__GetItemHeight_x                                  0x8B2850
#define CListWnd__GetItemIcon_x                                    0x8B1480
#define CListWnd__GetItemRect_x                                    0x8B2E40
#define CListWnd__GetItemText_x                                    0x8B1330
#define CListWnd__GetSelList_x                                     0x8B6010
#define CListWnd__GetSeparatorRect_x                               0x8B3630
#define CListWnd__RemoveLine_x                                     0x8B5F90
#define CListWnd__SetColors_x                                      0x8B10B0
#define CListWnd__SetColumnJustification_x                         0x8B1B40
#define CListWnd__SetColumnWidth_x                                 0x8B1820
#define CListWnd__SetCurSel_x                                      0x8B0FA0
#define CListWnd__SetItemColor_x                                   0x8B5450
#define CListWnd__SetItemData_x                                    0x8B1F60
#define CListWnd__SetItemText_x                                    0x8B5290
#define CListWnd__ShiftColumnSeparator_x                           0x8B5120
#define CListWnd__Sort_x                                           0x8B6A10
#define CListWnd__ToggleSel_x                                      0x8B1E30

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70D880

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72EAF0
#define CMerchantWnd__RequestBuyItem_x                             0x735950
#define CMerchantWnd__RequestSellItem_x                            0x7363C0
#define CMerchantWnd__SelectRecoverySlot_x                         0x72EDA0
#define CMerchantWnd__SelectBuySellSlot_x                          0x72E000
#define CMerchantWnd__ActualSelect_x                               0x732870

// CObfuscator
#define CObfuscator__doit_x                                        0x85D1D0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D4E50
#define CSidlManager__CreateLabel_x                                0x7971B0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x659140
#define CSidlScreenWnd__CalculateVSBRange_x                        0x659060
#define CSidlScreenWnd__ConvertToRes_x                             0x8F0520
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CC990
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CDEA0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CDF50
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CD410
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CC340
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CBA80
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CC530
#define CSidlScreenWnd__Init1_x                                    0x8CDB70
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CCA40
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CBC40
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CD660
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CB540
#define CSidlScreenWnd__StoreIniVis_x                              0x8CBA10
#define CSidlScreenWnd__WndNotification_x                          0x8CD8F0
#define CSidlScreenWnd__GetChildItem_x                             0x8CBB50
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BEFD0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F3DE0
#define CSkillMgr__GetSkillCap_x                                   0x5F3FA0
#define CSkillMgr__GetNameToken_x                                  0x5F3A00

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8EF7E0
#define CSliderWnd__SetValue_x                                     0x8EF9B0
#define CSliderWnd__SetNumTicks_x                                  0x8F0130

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79EE40

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EA1F0
#define CStmlWnd__CalculateHSBRange_x                              0x8E2700
#define CStmlWnd__CalculateVSBRange_x                              0x8E2790
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E2910
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E31F0
#define CStmlWnd__ForceParseNow_x                                  0x8EAB40
#define CStmlWnd__GetNextTagPiece_x                                0x8E30F0
#define CStmlWnd__GetSTMLText_x                                    0x690400
#define CStmlWnd__GetVisibleText_x                                 0x8E3C40
#define CStmlWnd__InitializeWindowVariables_x                      0x8E5FD0
#define CStmlWnd__MakeStmlColorTag_x                               0x8E1A00
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E1A60
#define CStmlWnd__SetSTMLText_x                                    0x8E7840
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E9E90
#define CStmlWnd__UpdateHistoryString_x                            0x8E4B80

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8F1D10
#define CTabWnd__DrawCurrentPage_x                                 0x8F1580
#define CTabWnd__DrawTab_x                                         0x8F1340
#define CTabWnd__GetCurrentPage_x                                  0x8F1950
#define CTabWnd__GetPageInnerRect_x                                0x8F1030
#define CTabWnd__GetTabInnerRect_x                                 0x8F1230
#define CTabWnd__GetTabRect_x                                      0x8F1100
#define CTabWnd__InsertPage_x                                      0x8F2000
#define CTabWnd__SetPage_x                                         0x8F1980
#define CTabWnd__SetPageRect_x                                     0x8F1C50
#define CTabWnd__UpdatePage_x                                      0x8F1FA0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431A90

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C96C0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F6EF0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8AEFB0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x596080
#define CXStr__CXStr1_x                                            0x740AE0
#define CXStr__CXStr3_x                                            0x893900
#define CXStr__dCXStr_x                                            0x8BDB40
#define CXStr__operator_equal_x                                    0x893A70
#define CXStr__operator_equal1_x                                   0x893AC0
#define CXStr__operator_plus_equal1_x                              0x894BA0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BE250
#define CXWnd__Center_x                                            0x8C4400
#define CXWnd__ClrFocus_x                                          0x8BDE30
#define CXWnd__DoAllDrawing_x                                      0x8C4050
#define CXWnd__DrawChildren_x                                      0x8C41F0
#define CXWnd__DrawColoredRect_x                                   0x8BE600
#define CXWnd__DrawTooltip_x                                       0x8BE8B0
#define CXWnd__DrawTooltipAtPoint_x                                0x8C2FC0
#define CXWnd__GetBorderFrame_x                                    0x8BECC0
#define CXWnd__GetChildWndAt_x                                     0x8C4DD0
#define CXWnd__GetClientClipRect_x                                 0x8BEAD0
#define CXWnd__GetScreenClipRect_x                                 0x8C36C0
#define CXWnd__GetScreenRect_x                                     0x8BEE70
#define CXWnd__GetTooltipRect_x                                    0x8BE740
#define CXWnd__GetWindowTextA_x                                    0x423010
#define CXWnd__IsActive_x                                          0x8B96F0
#define CXWnd__IsDescendantOf_x                                    0x8BEC10
#define CXWnd__IsReallyVisible_x                                   0x8C1FE0
#define CXWnd__IsType_x                                            0x8F36D0
#define CXWnd__Move_x                                              0x8C16C0
#define CXWnd__Move1_x                                             0x8C3D00
#define CXWnd__ProcessTransition_x                                 0x8BE1F0
#define CXWnd__Refade_x                                            0x8BE1F0
#define CXWnd__Resize_x                                            0x8BEF30
#define CXWnd__Right_x                                             0x8C34C0
#define CXWnd__SetFocus_x                                          0x8C0810
#define CXWnd__SetFont_x                                           0x8BDE80
#define CXWnd__SetKeyTooltip_x                                     0x8BF1A0
#define CXWnd__SetMouseOver_x                                      0x8C39F0
#define CXWnd__StartFade_x                                         0x8BE2A0
#define CXWnd__GetChildItem_x                                      0x8C3930

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BB020
#define CXWndManager__DrawWindows_x                                0x8BAC60
#define CXWndManager__GetKeyboardFlags_x                           0x8B9260
#define CXWndManager__HandleKeyboardMsg_x                          0x8B9B80
#define CXWndManager__RemoveWnd_x                                  0x8B9880

// CDBStr
#define CDBStr__GetString_x                                        0x4A4AC0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44F7A0
#define EQ_Character__Cur_HP_x                                     0x464CF0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4476A0
#define EQ_Character__GetCharInfo2_x                               0x867A00
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F670
#define EQ_Character__GetFocusRangeModifier_x                      0x43F860
#define EQ_Character__Max_Endurance_x                              0x5BB4E0
#define EQ_Character__Max_HP_x                                     0x45A970
#define EQ_Character__Max_Mana_x                                   0x5BB310
#define EQ_Character__doCombatAbility_x                            0x5B88F0
#define EQ_Character__UseSkill_x                                   0x4701F0
#define EQ_Character__GetConLevel_x                                0x5ADA90
#define EQ_Character__IsExpansionFlag_x                            0x422540
#define EQ_Character__TotalEffect_x                                0x44CA40

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x58E1C0
#define EQ_Item__CreateItemTagString_x                             0x846F20
#define EQ_Item__IsStackable_x                                     0x83B4D0
#define EQ_Item__GetImageNum_x                                     0x83E1B0
#define EQ_Item__CreateItemClient_x                                0x58EDB0
#define EQ_Item__GetItemValue_x                                    0x845C10
#define EQ_Item__ValueSellMerchant_x                               0x848220

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C47D0
#define EQ_LoadingS__Array_x                                       0xC0CA30

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BCC70
#define EQ_PC__GetAlternateAbilityId_x                             0x84FF50
#define EQ_PC__GetCombatAbility_x                                  0x84FFE0
#define EQ_PC__GetCombatAbilityTimer_x                             0x84AF90
#define EQ_PC__GetItemTimerValue_x                                 0x5B66D0
#define EQ_PC__HasLoreItem_x                                       0x5B0E00
#define EQ_PC__AlertInventoryChanged_x                             0x5ADA60
#define EQ_PC__GetPcZoneClient_x                                   0x5D7220
#define EQ_PC__RemoveMyAffect_x									   0x5B5BE0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50A830
#define EQItemList__add_item_x                                     0x50A770
#define EQItemList__delete_item_x                                  0x50AC30
#define EQItemList__FreeItemList_x                                 0x50AB30

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A3DA0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C2200
#define EQPlayer__dEQPlayer_x                                      0x5CB080
#define EQPlayer__DoAttack_x                                       0x5DD130
#define EQPlayer__EQPlayer_x                                       0x5CD4A0
#define EQPlayer__SetNameSpriteState_x                             0x5C7D50
#define EQPlayer__SetNameSpriteTint_x                              0x5C3610
#define EQPlayer__IsBodyType_j_x                                   0x9243A0
#define EQPlayer__IsTargetable_x                                   0x924CA0
#define EQPlayer__CanSee_x                                         0x9251C0
#define PlayerZoneClient__ChangeHeight_x                           0x5DCFF0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D1810
#define EQPlayerManager__GetSpawnByName_x                          0x5D1C70

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5943B0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5943F0
#define KeypressHandler__ClearCommandStateArray_x                  0x593F90
#define KeypressHandler__HandleKeyDown_x                           0x5928F0
#define KeypressHandler__HandleKeyUp_x                             0x592C10
#define KeypressHandler__SaveKeymapping_x                          0x594060

// MapViewMap 
#define MapViewMap__Clear_x                                        0x705C60
#define MapViewMap__SaveEx_x                                       0x709540

#define PlayerPointManager__GetAltCurrency_x                       0x8629A0

// StringTable 
#define StringTable__getString_x                                   0x85D470

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BAF90
#define PcZoneClient__RemovePetEffect_x                            0x5B6900

//Doors
#define EQSwitch__UseSwitch_x                                      0x549290

//IconCache
#define IconCache__GetIcon_x                                       0x6A0B30

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6979E0
#define CContainerMgr__CloseContainer_x                            0x698200

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7674A0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x587540

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DA540
#define EQ_Spell__SpellAffects_x                                   0x4DA5E0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DA610
#define CharacterZoneClient__CalcAffectChange_x                    0x448A90
#define CLootWnd__LootAll_x                                        0x6FB650

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7ACE10
#define CTargetWnd__WndNotification_x                              0x7AC900

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B1FE0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D3E30

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x494A00

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DE010
#define CSidlManager__FindAnimation1_x                             0x8D2D50

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                          0x4CBDD0                             
#define CAltAbilityData__GetMercMaxRank_x                              0x4CBD80                              
#define CAltAbilityData__GetMaxRank_x                                  0x4C0D20                            
