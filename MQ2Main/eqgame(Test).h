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
#define __ExpectedVersionDate                                     "Sep 24 2015"
#define __ExpectedVersionTime                                     "11:33:07"
#define __ActualVersionDate_x                                      0xACBA90
#define __ActualVersionTime_x                                      0xACBA9C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x599470
#define __MemChecker1_x                                            0x896AD0
#define __MemChecker2_x                                            0x632500
#define __MemChecker3_x                                            0x632450
#define __MemChecker4_x                                            0x7E8160
#define __EncryptPad0_x                                            0xC61FE0
#define __EncryptPad1_x                                            0xDEBB58
#define __EncryptPad2_x                                            0xCABAC8
#define __EncryptPad3_x                                            0xCAB6C8
#define __EncryptPad4_x                                            0xDC6240
#define __EncryptPad5_x                                            0x11978F0
#define __AC1_x                                                    0x7A5475
#define __AC2_x                                                    0x54E827
#define __AC3_x                                                    0x563020
#define __AC4_x                                                    0x569CA0
#define __AC5_x                                                    0x575B2E
#define __AC6_x                                                    0x5795D9
#define __AC7_x                                                    0x5701DC
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
#define __do_loot_x                                                0x515D70
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
#define pinstCamActor_x                                            0xF45AF8
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
#define pinstViewActor_x                                           0xF45AF4
#define pinstWorldData_x                                           0xFF8E18


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE07A18
#define pinstCAudioTriggersWindow_x                                0xE078A8
#define pinstCCharacterSelect_x                                    0xF45990
#define pinstCFacePick_x                                           0xF45940
#define pinstCNoteWnd_x                                            0xF45948
#define pinstCBookWnd_x                                            0xF45950
#define pinstCPetInfoWnd_x                                         0xF45954
#define pinstCTrainWnd_x                                           0xF45958
#define pinstCSkillsWnd_x                                          0xF4595C
#define pinstCSkillsSelectWnd_x                                    0xF45960
#define pinstCCombatSkillsSelectWnd_x                              0xF45964
#define pinstCFriendsWnd_x                                         0xF45968
#define pinstCAuraWnd_x                                            0xF4596C
#define pinstCRespawnWnd_x                                         0xF45970
#define pinstCBandolierWnd_x                                       0xF45974
#define pinstCPotionBeltWnd_x                                      0xF45978
#define pinstCAAWnd_x                                              0xF4597C
#define pinstCGroupSearchFiltersWnd_x                              0xF45980
#define pinstCLoadskinWnd_x                                        0xF45984
#define pinstCAlarmWnd_x                                           0xF45988
#define pinstCMusicPlayerWnd_x                                     0xF4598C
#define pinstCMailWnd_x                                            0xF45994
#define pinstCMailCompositionWnd_x                                 0xF45998
#define pinstCMailAddressBookWnd_x                                 0xF4599C
#define pinstCRaidWnd_x                                            0xF459A4
#define pinstCRaidOptionsWnd_x                                     0xF459A8
#define pinstCBreathWnd_x                                          0xF459AC
#define pinstCMapViewWnd_x                                         0xF459B0
#define pinstCMapToolbarWnd_x                                      0xF459B4
#define pinstCEditLabelWnd_x                                       0xF459B8
#define pinstCTargetWnd_x                                          0xF459BC
#define pinstCColorPickerWnd_x                                     0xF459C0
#define pinstCPlayerWnd_x                                          0xF459C4
#define pinstCOptionsWnd_x                                         0xF459C8
#define pinstCBuffWindowNORMAL_x                                   0xF459CC
#define pinstCBuffWindowSHORT_x                                    0xF459D0
#define pinstCharacterCreation_x                                   0xF459D4
#define pinstCCursorAttachment_x                                   0xF459D8
#define pinstCCastingWnd_x                                         0xF459DC
#define pinstCCastSpellWnd_x                                       0xF459E0
#define pinstCSpellBookWnd_x                                       0xF459E4
#define pinstCInventoryWnd_x                                       0xF459E8
#define pinstCBankWnd_x                                            0xF459EC
#define pinstCQuantityWnd_x                                        0xF459F0
#define pinstCLootWnd_x                                            0xF459F4
#define pinstCActionsWnd_x                                         0xF459F8
#define pinstCCombatAbilityWnd_x                                   0xF459FC
#define pinstCMerchantWnd_x                                        0xF45A00
#define pinstCTradeWnd_x                                           0xF45A04
#define pinstCSelectorWnd_x                                        0xF45A08
#define pinstCBazaarWnd_x                                          0xF45A0C
#define pinstCBazaarSearchWnd_x                                    0xF45A10
#define pinstCGiveWnd_x                                            0xF45A2C
#define pinstCTrackingWnd_x                                        0xF45A34
#define pinstCInspectWnd_x                                         0xF45A38
#define pinstCSocialEditWnd_x                                      0xF45A3C
#define pinstCFeedbackWnd_x                                        0xF45A40
#define pinstCBugReportWnd_x                                       0xF45A44
#define pinstCVideoModesWnd_x                                      0xF45A48
#define pinstCTextEntryWnd_x                                       0xF45A50
#define pinstCFileSelectionWnd_x                                   0xF45A54
#define pinstCCompassWnd_x                                         0xF45A58
#define pinstCPlayerNotesWnd_x                                     0xF45A5C
#define pinstCGemsGameWnd_x                                        0xF45A60
#define pinstCTimeLeftWnd_x                                        0xF45A64
#define pinstCPetitionQWnd_x                                       0xF45A7C
#define pinstCSoulmarkWnd_x                                        0xF45A80
#define pinstCStoryWnd_x                                           0xF45A84
#define pinstCJournalTextWnd_x                                     0xF45A88
#define pinstCJournalCatWnd_x                                      0xF45A8C
#define pinstCBodyTintWnd_x                                        0xF45A90
#define pinstCServerListWnd_x                                      0xF45A94
#define pinstCAvaZoneWnd_x                                         0xF45AA0
#define pinstCBlockedBuffWnd_x                                     0xF45AA4
#define pinstCBlockedPetBuffWnd_x                                  0xF45AA8
#define pinstCInvSlotMgr_x                                         0xF45AEC
#define pinstCContainerMgr_x                                       0xF45AF0
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
#define pinstCAdvancedLootWnd_x                                    0xF45AE0
#define pinstRewardSelectionWnd_x                                  0x119E3C0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x52D890
#define __ConvertItemTags_x                                        0x51A9F0
#define __ExecuteCmd_x                                             0x505530
#define __EQGetTime_x                                              0x896E30
#define __get_melee_range_x                                        0x50C1C0
#define __GetGaugeValueFromEQ_x                                    0x7A41B0
#define __GetLabelFromEQ_x                                         0x7A5400
#define __ToggleMount_x                                            0x6CD080
#define __GetXTargetType_x                                         0x927CB0
#define __LoadFrontEnd_x                                           0x631BB0
#define __NewUIINI_x                                               0x7A3AC0
#define __ProcessGameEvents_x                                      0x571F40
#define __ProcessMouseEvent_x                                      0x5716E0
#define CrashDetected_x                                            0x633680
#define wwsCrashReportCheckForUploader_x                           0x7F7D40
#define DrawNetStatus_x                                            0x5A8EF0
#define Util__FastTime_x                                           0x896780
#define Expansion_HoT_x                                            0x100725C
#define __HelpPath_x                                               0x108A9C8
//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41F010
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419E70

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C2680
#define AltAdvManager__IsAbilityReady_x                            0x4C26F0
#define AltAdvManager__GetAltAbility_x                             0x4C2AB0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x465550
#define CharacterZoneClient__MakeMeVisible_x                       0x46AF30
#define CharacterZoneClient__IsStackBlocked_x                      0x447B10

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6615F0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66F3E0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x588360

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68A880
#define CChatManager__InitContextMenu_x                            0x68B400

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D98C0
#define CContextMenu__AddMenuItem_x                                0x8D9AE0
#define CContextMenu__dCContextMenu_x                              0x8D9AD0
#define CContextMenu__RemoveMenuItem_x                             0x8D9DD0
#define CContextMenu__RemoveAllMenuItems_x                         0x8D9DF0
#define CContextMenuManager__AddMenu_x                             0x8C5850
#define CContextMenuManager__RemoveMenu_x                          0x8C5B80
#define CContextMenuManager__PopupMenu_x                           0x8C5FD0
#define CContextMenuManager__Flush_x                               0x8C58C0
#define CContextMenuManager__GetMenu_x                             0x4154A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87CDA0
#define CChatService__GetFriendName_x                              0x87CDB0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6906B0
#define CChatWindow__Clear_x                                       0x690260
#define CChatWindow__WndNotification_x                             0x690BE0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C9710
#define CComboWnd__Draw_x                                          0x8C9920
#define CComboWnd__GetCurChoice_x                                  0x8C94E0
#define CComboWnd__GetListRect_x                                   0x8C9BC0
#define CComboWnd__GetTextRect_x                                   0x8C9780
#define CComboWnd__InsertChoice_x                                  0x8C9C30
#define CComboWnd__SetColors_x                                     0x8C9470
#define CComboWnd__SetChoice_x                                     0x8C94A0
#define CComboWnd__GetItemCount_x                                  0x8C94D0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x699E60
#define CContainerWnd__vftable_x                                   0xAD5428

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B08E0
#define CDisplay__GetClickedActor_x                                0x4A9460
#define CDisplay__GetUserDefinedColor_x                            0x4A7D20
#define CDisplay__GetWorldFilePath_x                               0x4A7170
#define CDisplay__is3dON_x                                         0x4A6540
#define CDisplay__ReloadUI_x                                       0x4BBE00
#define CDisplay__WriteTextHD2_x                                   0x4ACC80

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8EFFB0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DE300
#define CEditWnd__GetCharIndexPt_x                                 0x8DF3A0
#define CEditWnd__GetDisplayString_x                               0x8DE4B0
#define CEditWnd__GetHorzOffset_x                                  0x8DE7F0
#define CEditWnd__GetLineForPrintableChar_x                        0x8DEE60
#define CEditWnd__GetSelStartPt_x                                  0x8DF660
#define CEditWnd__GetSTMLSafeText_x                                0x8DE990
#define CEditWnd__PointFromPrintableChar_x                         0x8DEF50
#define CEditWnd__SelectableCharFromPoint_x                        0x8DF0D0
#define CEditWnd__SetEditable_x                                    0x8DE960

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x54EF70
#define CEverQuest__DoTellWindow_x                                 0x554970
#define CEverQuest__DropHeldItemOnGround_x                         0x55D4A0
#define CEverQuest__dsp_chat_x                                     0x556110
#define CEverQuest__Emote_x                                        0x556370
#define CEverQuest__EnterZone_x                                    0x56A4C0
#define CEverQuest__GetBodyTypeDesc_x                              0x54B7D0
#define CEverQuest__GetClassDesc_x                                 0x5514E0
#define CEverQuest__GetClassThreeLetterCode_x                      0x551AE0
#define CEverQuest__GetDeityDesc_x                                 0x54C0B0
#define CEverQuest__GetLangDesc_x                                  0x54BB60
#define CEverQuest__GetRaceDesc_x                                  0x551CA0
#define CEverQuest__InterpretCmd_x                                 0x556C50
#define CEverQuest__LeftClickedOnPlayer_x                          0x56E640
#define CEverQuest__LMouseUp_x                                     0x570730
#define CEverQuest__RightClickedOnPlayer_x                         0x56F140
#define CEverQuest__RMouseUp_x                                     0x570190
#define CEverQuest__SetGameState_x                                 0x54F620
#define CEverQuest__UPCNotificationFlush_x                         0x557DF0
#define CEverQuest__IssuePetCommand_x                              0x557950

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AA9F0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AAA50
#define CGaugeWnd__Draw_x                                          0x6AAE80

// CGuild
#define CGuild__FindMemberByName_x                                 0x435D10

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C7AB0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D58C0
#define CInvSlotMgr__MoveItem_x                                    0x6D67F0
#define CInvSlotMgr__SelectSlot_x                                  0x6D5970

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D4D50
#define CInvSlot__SliderComplete_x                                 0x6D2710
#define CInvSlot__GetItemBase_x                                    0x6D1B90

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D79C0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A0B60
#define CItemDisplayWnd__UpdateStrings_x                           0x6D8CF0

// CLabel 
#define CLabel__Draw_x                                             0x6F3BC0

// CListWnd 
#define CListWnd__CListWnd_x                                       0x8B55E0
#define CListWnd__dCListWnd_x                                      0x8B6610
#define CListWnd__AddColumn_x                                      0x8B65B0
#define CListWnd__AddColumn1_x                                     0x8B5E20
#define CListWnd__AddLine_x                                        0x8B58A0
#define CListWnd__AddString_x                                      0x8B5AB0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B2900
#define CListWnd__CalculateVSBRange_x                              0x8B4A90
#define CListWnd__ClearAllSel_x                                    0x8B1BC0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B5470
#define CListWnd__Compare_x                                        0x8B3410
#define CListWnd__Draw_x                                           0x8B46A0
#define CListWnd__DrawColumnSeparators_x                           0x8B4530
#define CListWnd__DrawHeader_x                                     0x8B1ED0
#define CListWnd__DrawItem_x                                       0x8B3A60
#define CListWnd__DrawLine_x                                       0x8B41D0
#define CListWnd__DrawSeparator_x                                  0x8B45D0
#define CListWnd__EnsureVisible_x                                  0x8B2A60
#define CListWnd__ExtendSel_x                                      0x8B3970
#define CListWnd__GetColumnMinWidth_x                              0x8B1580
#define CListWnd__GetColumnWidth_x                                 0x8B14A0
#define CListWnd__GetCurSel_x                                      0x8B0C70
#define CListWnd__GetItemAtPoint_x                                 0x8B2D00
#define CListWnd__GetItemAtPoint1_x                                0x8B2D70
#define CListWnd__GetItemData_x                                    0x8B0FB0
#define CListWnd__GetItemHeight_x                                  0x8B2560
#define CListWnd__GetItemIcon_x                                    0x8B1190
#define CListWnd__GetItemRect_x                                    0x8B2B40
#define CListWnd__GetItemText_x                                    0x8B1040
#define CListWnd__GetSelList_x                                     0x8B5D10
#define CListWnd__GetSeparatorRect_x                               0x8B3330
#define CListWnd__RemoveLine_x                                     0x8B5C90
#define CListWnd__SetColors_x                                      0x8B0DC0
#define CListWnd__SetColumnJustification_x                         0x8B1850
#define CListWnd__SetColumnWidth_x                                 0x8B1530
#define CListWnd__SetCurSel_x                                      0x8B0CB0
#define CListWnd__SetItemColor_x                                   0x8B5150
#define CListWnd__SetItemData_x                                    0x8B1C70
#define CListWnd__SetItemText_x                                    0x8B4F90
#define CListWnd__ShiftColumnSeparator_x                           0x8B4E20
#define CListWnd__Sort_x                                           0x8B6710
#define CListWnd__ToggleSel_x                                      0x8B1B40

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70D280

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72E490
#define CMerchantWnd__RequestBuyItem_x                             0x735300
#define CMerchantWnd__RequestSellItem_x                            0x735D70
#define CMerchantWnd__SelectRecoverySlot_x                         0x72E740
#define CMerchantWnd__SelectBuySellSlot_x                          0x72D9A0
#define CMerchantWnd__ActualSelect_x                               0x732220

// CObfuscator
#define CObfuscator__doit_x                                        0x85CF70

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D4770
#define CSidlManager__CreateLabel_x                                0x796B60

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateVSBRange_x                        0x658800
#define CSidlScreenWnd__CalculateHSBRange_x                        0x6588E0
#define CSidlScreenWnd__ConvertToRes_x                             0x8EFE90
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CC380
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CD850
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CD900
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CCDC0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CBD30
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CB480
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CBF20
#define CSidlScreenWnd__Init1_x                                    0x8CD520
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CC430
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CB640
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CD010
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CAF50
#define CSidlScreenWnd__StoreIniVis_x                              0x8CB410
#define CSidlScreenWnd__WndNotification_x                          0x8CD2A0
#define CSidlScreenWnd__GetChildItem_x                             0x8CB550
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BEBD0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F37B0
#define CSkillMgr__GetSkillCap_x                                   0x5F3970
#define CSkillMgr__GetNameToken_x                                  0x5F33D0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8EF140
#define CSliderWnd__SetValue_x                                     0x8EF310
#define CSliderWnd__SetNumTicks_x                                  0x8EFA90

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79E810

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8E9B30
#define CStmlWnd__CalculateHSBRange_x                              0x8E2050
#define CStmlWnd__CalculateVSBRange_x                              0x8E20E0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E2260
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E2B40
#define CStmlWnd__ForceParseNow_x                                  0x8EA480
#define CStmlWnd__GetNextTagPiece_x                                0x8E2A40
#define CStmlWnd__GetSTMLText_x                                    0x68FB00
#define CStmlWnd__GetVisibleText_x                                 0x8E3590
#define CStmlWnd__InitializeWindowVariables_x                      0x8E5920
#define CStmlWnd__MakeStmlColorTag_x                               0x8E1350
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E13B0
#define CStmlWnd__SetSTMLText_x                                    0x8E7180
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E97D0
#define CStmlWnd__UpdateHistoryString_x                            0x8E44D0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8F1690
#define CTabWnd__DrawCurrentPage_x                                 0x8F0F00
#define CTabWnd__DrawTab_x                                         0x8F0CC0
#define CTabWnd__GetCurrentPage_x                                  0x8F12D0
#define CTabWnd__GetPageInnerRect_x                                0x8F09B0
#define CTabWnd__GetTabInnerRect_x                                 0x8F0BB0
#define CTabWnd__GetTabRect_x                                      0x8F0A80
#define CTabWnd__InsertPage_x                                      0x8F1980
#define CTabWnd__SetPage_x                                         0x8F1300
#define CTabWnd__SetPageRect_x                                     0x8F15D0
#define CTabWnd__UpdatePage_x                                      0x8F1920

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431B20

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C90E0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F68E0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8AEDD0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x595A20
#define CXStr__CXStr1_x                                            0x4DE8D0
#define CXStr__CXStr3_x                                            0x893800
#define CXStr__dCXStr_x                                            0x8BD730
#define CXStr__operator_equal_x                                    0x893970
#define CXStr__operator_equal1_x                                   0x8939C0
#define CXStr__operator_plus_equal1_x                              0x894AB0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BDE40
#define CXWnd__Center_x                                            0x8C3E60
#define CXWnd__ClrFocus_x                                          0x8BDA20
#define CXWnd__DoAllDrawing_x                                      0x8C3AB0
#define CXWnd__DrawChildren_x                                      0x8C3C50
#define CXWnd__DrawColoredRect_x                                   0x8BE1C0
#define CXWnd__DrawTooltip_x                                       0x8BE470
#define CXWnd__DrawTooltipAtPoint_x                                0x8C2A50
#define CXWnd__GetBorderFrame_x                                    0x8BE8D0
#define CXWnd__GetChildWndAt_x                                     0x8C4830
#define CXWnd__GetClientClipRect_x                                 0x8BE690
#define CXWnd__GetScreenClipRect_x                                 0x8C3150
#define CXWnd__GetScreenRect_x                                     0x8BEA70
#define CXWnd__GetTooltipRect_x                                    0x8BE300
#define CXWnd__GetWindowTextA_x                                    0x4230A0
#define CXWnd__IsActive_x                                          0x8B93D0
#define CXWnd__IsDescendantOf_x                                    0x8BE820
#define CXWnd__IsReallyVisible_x                                   0x8C1AA0
#define CXWnd__IsType_x                                            0x8F3030
#define CXWnd__Move_x                                              0x8C1210
#define CXWnd__Move1_x                                             0x8C3780
#define CXWnd__ProcessTransition_x                                 0x8BDDE0
#define CXWnd__Refade_x                                            0x8BDBC0
#define CXWnd__Resize_x                                            0x8BEB30
#define CXWnd__Right_x                                             0x8C2F50
#define CXWnd__SetFocus_x                                          0x8C03B0
#define CXWnd__SetFont_x                                           0x8BDA70
#define CXWnd__SetKeyTooltip_x                                     0x8BEDA0
#define CXWnd__SetMouseOver_x                                      0x8C3490
#define CXWnd__StartFade_x                                         0x8BDE90
#define CXWnd__GetChildItem_x                                      0x8C33D0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BACD0
#define CXWndManager__DrawWindows_x                                0x8BA920
#define CXWndManager__GetKeyboardFlags_x                           0x8B8F40
#define CXWndManager__HandleKeyboardMsg_x                          0x8B9860
#define CXWndManager__RemoveWnd_x                                  0x8B9560

// CDBStr
#define CDBStr__GetString_x                                        0x4A4A80

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44F7A0
#define EQ_Character__Cur_HP_x                                     0x464C20
#define EQ_Character__GetAACastingTimeModifier_x                   0x447690
#define EQ_Character__GetCharInfo2_x                               0x8678A0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F660
#define EQ_Character__GetFocusRangeModifier_x                      0x43F850
#define EQ_Character__Max_Endurance_x                              0x5BAF10
#define EQ_Character__Max_HP_x                                     0x45A890
#define EQ_Character__Max_Mana_x                                   0x5BAD40
#define EQ_Character__doCombatAbility_x                            0x5B8330
#define EQ_Character__UseSkill_x                                   0x470130
#define EQ_Character__GetConLevel_x                                0x5AD4E0
#define EQ_Character__IsExpansionFlag_x                            0x4225D0
#define EQ_Character__TotalEffect_x                                0x44CA40

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x58DB80
#define EQ_Item__CreateItemTagString_x                             0x846BD0
#define EQ_Item__IsStackable_x                                     0x83AD70
#define EQ_Item__GetImageNum_x                                     0x83DA50
#define EQ_Item__CreateItemClient_x                                0x58E760
#define EQ_Item__GetItemValue_x                                    0x845870
#define EQ_Item__ValueSellMerchant_x                               0x847F60

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C4770
#define EQ_LoadingS__Array_x                                       0xC0CA30

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BC6B0
#define EQ_PC__GetAltAbilityIndex_x                                0x84FCD0
#define EQ_PC__GetCombatAbility_x                                  0x84FD60
#define EQ_PC__GetCombatAbilityTimer_x                             0x84ACD0
#define EQ_PC__GetItemTimerValue_x                                 0x5B6100
#define EQ_PC__HasLoreItem_x                                       0x5B0850
#define EQ_PC__AlertInventoryChanged_x                             0x5AD4B0
#define EQ_PC__GetPcZoneClient_x                                   0x5D6BE0
#define EQ_PC__RemoveMyAffect_x                                    0x5B5610

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50A230
#define EQItemList__add_item_x                                     0x50A170
#define EQItemList__delete_item_x                                  0x50A630
#define EQItemList__FreeItemList_x                                 0x50A530

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A3CC0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C1C40
#define EQPlayer__dEQPlayer_x                                      0x5CAAB0
#define EQPlayer__DoAttack_x                                       0x5DCB00
#define EQPlayer__EQPlayer_x                                       0x5CCED0
#define EQPlayer__SetNameSpriteState_x                             0x5C7790
#define EQPlayer__SetNameSpriteTint_x                              0x5C3050
#define EQPlayer__IsBodyType_j_x                                   0x923E30
#define EQPlayer__IsTargetable_x                                   0x924730
#define EQPlayer__CanSee_x                                         0x924C50
#define PlayerZoneClient__ChangeHeight_x                           0x5DC9C0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D11E0
#define EQPlayerManager__GetSpawnByName_x                          0x5D1640

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x593D50
#define KeypressHandler__AttachKeyToEqCommand_x                    0x593D90
#define KeypressHandler__ClearCommandStateArray_x                  0x593930
#define KeypressHandler__HandleKeyDown_x                           0x592290
#define KeypressHandler__HandleKeyUp_x                             0x5925B0
#define KeypressHandler__SaveKeymapping_x                          0x593A00

// MapViewMap 
#define MapViewMap__Clear_x                                        0x705660
#define MapViewMap__SaveEx_x                                       0x708F40

#define PlayerPointManager__GetAltCurrency_x                       0x862830

// StringTable 
#define StringTable__getString_x                                   0x85D210

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BA9C0
#define PcZoneClient__RemovePetEffect_x                            0x5B6330

//Doors
#define EQSwitch__UseSwitch_x                                      0x548B20

//IconCache
#define IconCache__GetIcon_x                                       0x6A02B0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x697190
#define CContainerMgr__CloseContainer_x                            0x6979B0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x766E70

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x586E20

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DA5D0
#define EQ_Spell__SpellAffects_x                                   0x4DA670
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DA6A0
#define CharacterZoneClient__CalcAffectChange_x                    0x448A80
#define CLootWnd__LootAll_x                                        0x6FAF20

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x750CD0
#define CTargetWnd__WndNotification_x                              0x7AC250

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B1940

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D3E30

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x494910

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DD930
#define CSidlManager__FindAnimation1_x                             0x8D2670
