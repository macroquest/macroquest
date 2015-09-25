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
#define __ExpectedVersionDate                                     "Sep 23 2015"
#define __ExpectedVersionTime                                     "10:55:44"
#define __ActualVersionDate_x                                      0xACBAF8
#define __ActualVersionTime_x                                      0xACBB04

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x599050
#define __MemChecker1_x                                            0x896120
#define __MemChecker2_x                                            0x631FE0
#define __MemChecker3_x                                            0x631F30
#define __MemChecker4_x                                            0x7E78A0
#define __EncryptPad0_x                                            0xC61FE0
#define __EncryptPad1_x                                            0xDEBB58
#define __EncryptPad2_x                                            0xCABAC8
#define __EncryptPad3_x                                            0xCAB6C8
#define __EncryptPad4_x                                            0xDC6240
#define __AC1_x                                                    0x7A5075
#define __AC2_x                                                    0x54E627
#define __AC3_x                                                    0x562E20
#define __AC4_x                                                    0x569AA0
#define __AC5_x                                                    0x57591E
#define __AC6_x                                                    0x5793B9
#define __AC7_x                                                    0x56FFCC
#define __AC1_Data                                                 0x11111111

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
#define __do_loot_x                                                0x515BE0
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
#define __CastRay_x                                                0x52D700
#define __ConvertItemTags_x                                        0x51A860
#define __ExecuteCmd_x                                             0x505370
#define __EQGetTime_x                                              0x896480
#define __get_melee_range_x                                        0x50C030
#define __GetGaugeValueFromEQ_x                                    0x7A3DB0
#define __GetLabelFromEQ_x                                         0x7A5000
#define __ToggleMount_x                                            0x6CCC00
#define __GetXTargetType_x                                         0x9276F0
#define __LoadFrontEnd_x                                           0x631690
#define __NewUIINI_x                                               0x7A36C0
#define __ProcessGameEvents_x                                      0x571D30
#define __ProcessMouseEvent_x                                      0x5714D0
#define CrashDetected_x                                            0x633160
#define wwsCrashReportCheckForUploader_x                           0x7F77B0
#define DrawNetStatus_x                                            0x5A8A70
#define Util__FastTime_x                                           0x895DD0
#define Expansion_HoT_x                                            0x100725C
#define __HelpPath_x                                               0x108A9C8
//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41EFA0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419DF0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C25E0
#define AltAdvManager__IsAbilityReady_x                            0x4C2650
#define AltAdvManager__GetAltAbility_x                             0x4C2A10

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4654F0
#define CharacterZoneClient__MakeMeVisible_x                       0x46AED0
#define CharacterZoneClient__IsStackBlocked_x                      0x447A80

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x661150

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66F800

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5880E0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68A490
#define CChatManager__InitContextMenu_x                            0x68B010

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D91B0
#define CContextMenu__AddMenuItem_x                                0x8D93D0
#define CContextMenu__dCContextMenu_x                              0x8D93C0
#define CContextMenu__RemoveMenuItem_x                             0x8D96C0
#define CContextMenu__RemoveAllMenuItems_x                         0x8D96E0
#define CContextMenuManager__AddMenu_x                             0x8C50D0
#define CContextMenuManager__RemoveMenu_x                          0x8C5410
#define CContextMenuManager__PopupMenu_x                           0x8C5860
#define CContextMenuManager__Flush_x                               0x8C5140
#define CContextMenuManager__GetMenu_x                             0x415450

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87C1B0
#define CChatService__GetFriendName_x                              0x87C1C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6902B0
#define CChatWindow__Clear_x                                       0x68FE70
#define CChatWindow__WndNotification_x                             0x6907F0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C8FB0
#define CComboWnd__Draw_x                                          0x8C91C0
#define CComboWnd__GetCurChoice_x                                  0x8C8D80
#define CComboWnd__GetListRect_x                                   0x8C9460
#define CComboWnd__GetTextRect_x                                   0x8C9020
#define CComboWnd__InsertChoice_x                                  0x8C94D0
#define CComboWnd__SetColors_x                                     0x8C8D10
#define CComboWnd__SetChoice_x                                     0x8C8D40
#define CComboWnd__GetItemCount_x                                  0x8C8D70

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6999E0
#define CContainerWnd__vftable_x                                   0xAD5490

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B08C0
#define CDisplay__GetClickedActor_x                                0x4A9440
#define CDisplay__GetUserDefinedColor_x                            0x4A7D00
#define CDisplay__GetWorldFilePath_x                               0x4A7150
#define CDisplay__is3dON_x                                         0x4A6520
#define CDisplay__ReloadUI_x                                       0x4BBDE0
#define CDisplay__WriteTextHD2_x                                   0x4ACC60

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8EF8B0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DDBF0
#define CEditWnd__GetCharIndexPt_x                                 0x8DEC80
#define CEditWnd__GetDisplayString_x                               0x8DDDA0
#define CEditWnd__GetHorzOffset_x                                  0x8DE0E0
#define CEditWnd__GetLineForPrintableChar_x                        0x8DE750
#define CEditWnd__GetSelStartPt_x                                  0x8DEF30
#define CEditWnd__GetSTMLSafeText_x                                0x8DE280
#define CEditWnd__PointFromPrintableChar_x                         0x8DE840
#define CEditWnd__SelectableCharFromPoint_x                        0x8DE9C0
#define CEditWnd__SetEditable_x                                    0x8DE250

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x54ED70
#define CEverQuest__DoTellWindow_x                                 0x554770
#define CEverQuest__DropHeldItemOnGround_x                         0x55D2A0
#define CEverQuest__dsp_chat_x                                     0x555F10
#define CEverQuest__Emote_x                                        0x556170
#define CEverQuest__EnterZone_x                                    0x56A2C0
#define CEverQuest__GetBodyTypeDesc_x                              0x54B5D0
#define CEverQuest__GetClassDesc_x                                 0x5512E0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5518E0
#define CEverQuest__GetDeityDesc_x                                 0x54BEB0
#define CEverQuest__GetLangDesc_x                                  0x54B960
#define CEverQuest__GetRaceDesc_x                                  0x551AA0
#define CEverQuest__InterpretCmd_x                                 0x556A50
#define CEverQuest__LeftClickedOnPlayer_x                          0x56E430
#define CEverQuest__LMouseUp_x                                     0x570520
#define CEverQuest__RightClickedOnPlayer_x                         0x56EF30
#define CEverQuest__RMouseUp_x                                     0x56FF80
#define CEverQuest__SetGameState_x                                 0x54F420
#define CEverQuest__UPCNotificationFlush_x                         0x557BF0
#define CEverQuest__IssuePetCommand_x                              0x557750

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AA560
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AA5C0
#define CGaugeWnd__Draw_x                                          0x6AA9F0

// CGuild
#define CGuild__FindMemberByName_x                                 0x435C90

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C7630

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D5450
#define CInvSlotMgr__MoveItem_x                                    0x6D6380
#define CInvSlotMgr__SelectSlot_x                                  0x6D5500

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D48E0
#define CInvSlot__SliderComplete_x                                 0x6D22A0
#define CInvSlot__GetItemBase_x                                    0x6D1730

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D7500

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A0710
#define CItemDisplayWnd__UpdateStrings_x                           0x6D8850

// CLabel 
#define CLabel__Draw_x                                             0x6F3660

// CListWnd 
#define CListWnd__CListWnd_x                                       0x8B4C00
#define CListWnd__dCListWnd_x                                      0x8B5C30
#define CListWnd__AddColumn_x                                      0x8B5BD0
#define CListWnd__AddColumn1_x                                     0x8B5440
#define CListWnd__AddLine_x                                        0x8B4EC0
#define CListWnd__AddString_x                                      0x8B50D0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B1F40
#define CListWnd__CalculateVSBRange_x                              0x8B40C0
#define CListWnd__ClearAllSel_x                                    0x8B11F0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B4A90
#define CListWnd__Compare_x                                        0x8B2A40
#define CListWnd__Draw_x                                           0x8B3CD0
#define CListWnd__DrawColumnSeparators_x                           0x8B3B60
#define CListWnd__DrawHeader_x                                     0x8B1500
#define CListWnd__DrawItem_x                                       0x8B3090
#define CListWnd__DrawLine_x                                       0x8B3800
#define CListWnd__DrawSeparator_x                                  0x8B3C00
#define CListWnd__EnsureVisible_x                                  0x8B20A0
#define CListWnd__ExtendSel_x                                      0x8B2FA0
#define CListWnd__GetColumnMinWidth_x                              0x8B0BB0
#define CListWnd__GetColumnWidth_x                                 0x8B0AD0
#define CListWnd__GetCurSel_x                                      0x8B0290
#define CListWnd__GetItemAtPoint_x                                 0x8B2330
#define CListWnd__GetItemAtPoint1_x                                0x8B23A0
#define CListWnd__GetItemData_x                                    0x8B05E0
#define CListWnd__GetItemHeight_x                                  0x8B1B90
#define CListWnd__GetItemIcon_x                                    0x8B07C0
#define CListWnd__GetItemRect_x                                    0x8B2170
#define CListWnd__GetItemText_x                                    0x8B0670
#define CListWnd__GetSelList_x                                     0x8B5330
#define CListWnd__GetSeparatorRect_x                               0x8B2960
#define CListWnd__RemoveLine_x                                     0x8B52B0
#define CListWnd__SetColors_x                                      0x8B03E0
#define CListWnd__SetColumnJustification_x                         0x8B0E80
#define CListWnd__SetColumnWidth_x                                 0x8B0B60
#define CListWnd__SetCurSel_x                                      0x8B02D0
#define CListWnd__SetItemColor_x                                   0x8B4770
#define CListWnd__SetItemData_x                                    0x8B12A0
#define CListWnd__SetItemText_x                                    0x8B45B0
#define CListWnd__ShiftColumnSeparator_x                           0x8B4440
#define CListWnd__Sort_x                                           0x8B5D30
#define CListWnd__ToggleSel_x                                      0x8B1170

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70CBF0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72DE00
#define CMerchantWnd__RequestBuyItem_x                             0x734C70
#define CMerchantWnd__RequestSellItem_x                            0x7356E0
#define CMerchantWnd__SelectRecoverySlot_x                         0x72E0B0
#define CMerchantWnd__SelectBuySellSlot_x                          0x72D310
#define CMerchantWnd__ActualSelect_x                               0x731B90

// CObfuscator
#define CObfuscator__doit_x                                        0x85C5D0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D4100
#define CSidlManager__CreateLabel_x                                0x7965F0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x658440
#define CSidlScreenWnd__CalculateVSBRange_x                        0x658370
#define CSidlScreenWnd__ConvertToRes_x                             0x8EF790
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CBC10
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CD100
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CD1B0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CC670
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CB5C0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CAD30
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CB7B0
#define CSidlScreenWnd__Init1_x                                    0x8CCDD0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CBCC0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CAEF0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CC8C0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CA800
#define CSidlScreenWnd__StoreIniVis_x                              0x8CACC0
#define CSidlScreenWnd__WndNotification_x                          0x8CCB50
#define CSidlScreenWnd__GetChildItem_x                             0x8CAE00
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BE250

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F3580
#define CSkillMgr__GetSkillCap_x                                   0x5F3740
#define CSkillMgr__GetNameToken_x                                  0x5F31A0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8EEA40
#define CSliderWnd__SetValue_x                                     0x8EEC10
#define CSliderWnd__SetNumTicks_x                                  0x8EF390

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79E3C0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8E93D0
#define CStmlWnd__CalculateHSBRange_x                              0x8E1980
#define CStmlWnd__CalculateVSBRange_x                              0x8E1900
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E1B00
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E23E0
#define CStmlWnd__ForceParseNow_x                                  0x8E9D90
#define CStmlWnd__GetNextTagPiece_x                                0x8E22E0
#define CStmlWnd__GetSTMLText_x                                    0x68F710
#define CStmlWnd__GetVisibleText_x                                 0x8E2E30
#define CStmlWnd__InitializeWindowVariables_x                      0x8E51B0
#define CStmlWnd__MakeStmlColorTag_x                               0x8E0C00
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E0C60
#define CStmlWnd__SetSTMLText_x                                    0x8E6A10
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E9070
#define CStmlWnd__UpdateHistoryString_x                            0x8E3D70

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8F0F90
#define CTabWnd__DrawCurrentPage_x                                 0x8F0800
#define CTabWnd__DrawTab_x                                         0x8F05C0
#define CTabWnd__GetCurrentPage_x                                  0x8F0BD0
#define CTabWnd__GetPageInnerRect_x                                0x8F02B0
#define CTabWnd__GetTabInnerRect_x                                 0x8F04B0
#define CTabWnd__GetTabRect_x                                      0x8F0380
#define CTabWnd__InsertPage_x                                      0x8F1280
#define CTabWnd__SetPage_x                                         0x8F0C00
#define CTabWnd__SetPageRect_x                                     0x8F0ED0
#define CTabWnd__UpdatePage_x                                      0x8F1220

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431A80

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C8980

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F6140

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8AE3A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x595640
#define CXStr__CXStr1_x                                            0x4022B0
#define CXStr__CXStr3_x                                            0x892E60
#define CXStr__dCXStr_x                                            0x4C3DA0
#define CXStr__operator_equal_x                                    0x892FD0
#define CXStr__operator_equal1_x                                   0x893020
#define CXStr__operator_plus_equal1_x                              0x894100

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BD4A0
#define CXWnd__Center_x                                            0x8C3690
#define CXWnd__ClrFocus_x                                          0x8BD080
#define CXWnd__DoAllDrawing_x                                      0x8C32E0
#define CXWnd__DrawChildren_x                                      0x8C3480
#define CXWnd__DrawColoredRect_x                                   0x8BD850
#define CXWnd__DrawTooltip_x                                       0x8BDAF0
#define CXWnd__DrawTooltipAtPoint_x                                0x8C2230
#define CXWnd__GetBorderFrame_x                                    0x8BDF10
#define CXWnd__GetChildWndAt_x                                     0x8C4050
#define CXWnd__GetClientClipRect_x                                 0x8BDD10
#define CXWnd__GetScreenClipRect_x                                 0x8C2930
#define CXWnd__GetScreenRect_x                                     0x8BE0F0
#define CXWnd__GetTooltipRect_x                                    0x8BD980
#define CXWnd__GetWindowTextA_x                                    0x423020
#define CXWnd__IsActive_x                                          0x8B8A40
#define CXWnd__IsDescendantOf_x                                    0x8BDE50
#define CXWnd__IsReallyVisible_x                                   0x8C1240
#define CXWnd__IsType_x                                            0x8F2940
#define CXWnd__Move_x                                              0x8C0960
#define CXWnd__Move1_x                                             0x8C2F80
#define CXWnd__ProcessTransition_x                                 0x8BD440
#define CXWnd__Refade_x                                            0x8BD220
#define CXWnd__Resize_x                                            0x8BE1C0
#define CXWnd__Right_x                                             0x8C2730
#define CXWnd__SetFocus_x                                          0x8BFAB0
#define CXWnd__SetFont_x                                           0x8BD0D0
#define CXWnd__SetKeyTooltip_x                                     0x8BE420
#define CXWnd__SetMouseOver_x                                      0x8C2C70
#define CXWnd__StartFade_x                                         0x8BD4F0
#define CXWnd__GetChildItem_x                                      0x8C2BB0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BA360
#define CXWndManager__DrawWindows_x                                0x8B9FA0
#define CXWndManager__GetKeyboardFlags_x                           0x8B8580
#define CXWndManager__HandleKeyboardMsg_x                          0x8B8ED0
#define CXWndManager__RemoveWnd_x                                  0x8B8BD0

// CDBStr
#define CDBStr__GetString_x                                        0x4A4A40

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44F6E0
#define EQ_Character__Cur_HP_x                                     0x464BC0
#define EQ_Character__GetAACastingTimeModifier_x                   0x447600
#define EQ_Character__GetCharInfo2_x                               0x866DA0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F5B0
#define EQ_Character__GetFocusRangeModifier_x                      0x43F7A0
#define EQ_Character__Max_Endurance_x                              0x5BACD0
#define EQ_Character__Max_HP_x                                     0x45A830
#define EQ_Character__Max_Mana_x                                   0x5BAB00
#define EQ_Character__doCombatAbility_x                            0x5B80E0
#define EQ_Character__UseSkill_x                                   0x4700D0
#define EQ_Character__GetConLevel_x                                0x5AD140
#define EQ_Character__IsExpansionFlag_x                            0x422570
#define EQ_Character__TotalEffect_x                                0x44C980

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x58D890
#define EQ_Item__CreateItemTagString_x                             0x846360
#define EQ_Item__IsStackable_x                                     0x83A7A0
#define EQ_Item__GetImageNum_x                                     0x83D550
#define EQ_Item__CreateItemClient_x                                0x58E460
#define EQ_Item__GetItemValue_x                                    0x844FC0
#define EQ_Item__ValueSellMerchant_x                               0x847660

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C4730
#define EQ_LoadingS__Array_x                                       0xC0CA30

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BC470
#define EQ_PC__GetAltAbilityIndex_x                                0x84F350
#define EQ_PC__GetCombatAbility_x                                  0x84F3E0
#define EQ_PC__GetCombatAbilityTimer_x                             0x84A390
#define EQ_PC__GetItemTimerValue_x                                 0x5B5EB0
#define EQ_PC__HasLoreItem_x                                       0x5B04B0
#define EQ_PC__AlertInventoryChanged_x                             0x5AD110
#define EQ_PC__GetPcZoneClient_x                                   0x5D69F0
#define EQ_PC__RemoveMyAffect_x                                    0x5B53C0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50A070
#define EQItemList__add_item_x                                     0x509FB0
#define EQItemList__delete_item_x                                  0x50A470
#define EQItemList__FreeItemList_x                                 0x50A370

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A3D00

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C1A00
#define EQPlayer__dEQPlayer_x                                      0x5CA870
#define EQPlayer__DoAttack_x                                       0x5DC910
#define EQPlayer__EQPlayer_x                                       0x5CCC90
#define EQPlayer__SetNameSpriteState_x                             0x5C7550
#define EQPlayer__SetNameSpriteTint_x                              0x5C2E10
#define EQPlayer__IsBodyType_j_x                                   0x923870
#define EQPlayer__IsTargetable_x                                   0x924170
#define EQPlayer__CanSee_x                                         0x924690

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D0F90
#define EQPlayerManager__GetSpawnByName_x                          0x5D13F0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x593960
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5939A0
#define KeypressHandler__ClearCommandStateArray_x                  0x593540
#define KeypressHandler__HandleKeyDown_x                           0x591EA0
#define KeypressHandler__HandleKeyUp_x                             0x5921C0
#define KeypressHandler__SaveKeymapping_x                          0x593610

// MapViewMap 
#define MapViewMap__Clear_x                                        0x704FD0
#define MapViewMap__SaveEx_x                                       0x7088B0

#define PlayerPointManager__GetAltCurrency_x                       0x861D00

// StringTable 
#define StringTable__getString_x                                   0x85C870

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BA780
#define PcZoneClient__RemovePetEffect_x                            0x5B60E0

//Doors
#define EQSwitch__UseSwitch_x                                      0x548990

//IconCache
#define IconCache__GetIcon_x                                       0x69FE40

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x696D00
#define CContainerMgr__CloseContainer_x                            0x697520

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7668D0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x586BA0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DA670
#define EQ_Spell__SpellAffects_x                                   0x4DA710
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DA740
#define CharacterZoneClient__CalcAffectChange_x                    0x4489F0
#define CLootWnd__LootAll_x                                        0x6FA950
//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x750690
#define CTargetWnd__WndNotification_x                              0x7ABE40

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B1540

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D3EC0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x494930

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DD220
#define CSidlManager__FindAnimation1_x                             0x8D1FF0
