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
#define __ExpectedVersionDate                                     "May 14 2014"
#define __ExpectedVersionTime                                     "17:46:31"
#define __ActualVersionDate_x                                      0xA464B8
#define __ActualVersionTime_x                                      0xA464C4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x571760
#define __MemChecker1_x                                            0x832310
#define __MemChecker2_x                                            0x607E80
#define __MemChecker3_x                                            0x607DD0
#define __MemChecker4_x                                            0x7B7120
#define __EncryptPad0_x                                            0xBAF930
#define __EncryptPad1_x                                            0xD25E50
#define __EncryptPad2_x                                            0xBF6040
#define __EncryptPad3_x                                            0xBF5C40
#define __EncryptPad4_x                                            0xD03EE0
#define __AC1_x                                                    0x774705
#define __AC2_x                                                    0x527F47
#define __AC3_x                                                    0x53C6A0
#define __AC4_x                                                    0x5427D0
#define __AC5_x                                                    0x54EDE1
#define __AC6_x                                                    0x552902
#define __AC7_x                                                    0x5488BC
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x10D5628
#define DI8__Keyboard_x                                            0x10D562C
#define DI8__Mouse_x                                               0x10D5630
#define __AltTimerReady_x                                          0xF353D9
#define __Attack_x                                                 0xFC81D2
#define __Autofire_x                                               0xFC81D3
#define __BindList_x                                               0xB74418
#define __Clicks_x                                                 0xF44020
#define __CommandList_x                                            0xB78488
#define __CurrentMapLabel_x                                        0x10DB2A8
#define __CurrentSocial_x                                          0xB3A8C0
#define __DoAbilityList_x                                          0xF7A780
#define __do_loot_x                                                0x4F0A40
#define __DrawHandler_x                                            0x173D804
#define __GroupCount_x                                             0xF34AB2

#define __Guilds_x                                                 0xF3A5A0
#define __gWorld_x                                                 0xF36F6C
#define __HotkeyPage_x                                             0xFC1180
#define __HWnd_x                                                   0xFCD530
#define __InChatMode_x                                             0xF43F4C
#define __LastTell_x                                               0xF45E88
#define __LMouseHeldTime_x                                         0xF4408C
#define __Mouse_x                                                  0x10D5634
#define __MouseLook_x                                              0xF43FE6
#define __MouseEventTime_x                                         0xFC89BC
#define __NetStatusToggle_x                                        0xF43FE9
#define __PCNames_x                                                0xF454C8
#define __RangeAttackReady_x                                       0xF45160
#define __RMouseHeldTime_x                                         0xF44088
#define __RunWalkState_x                                           0xF43F50
#define __ScreenMode_x                                             0xE834B0
#define __ScreenX_x                                                0xF43F04
#define __ScreenY_x                                                0xF43F00
#define __ScreenXMax_x                                             0xF43F08
#define __ScreenYMax_x                                             0xF43F0C
#define __ServerHost_x                                             0xF349FC
#define __ServerName_x                                             0xF7A740
#define __ShiftKeyDown_x                                           0xF445F0
#define __ShowNames_x                                              0xF4536C
#define __Socials_x                                                0xF7A840
#define __SubscriptionType_x                                       0x1104FD8
#define __TargetAggroHolder_x                                      0x10DD4C0
#define __GroupAggro_x                                             0x10DD500
#define __LoginName_x                                              0xFCC108
#define __Inviter_x                                                0xFC8150


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF37058
#define instEQZoneInfo_x                                           0xF441DC
#define instKeypressHandler_x                                      0xFC89A0
#define pinstActiveBanker_x                                        0xF37010
#define pinstActiveCorpse_x                                        0xF37014
#define pinstActiveGMaster_x                                       0xF37018
#define pinstActiveMerchant_x                                      0xF3700C
#define pinstAggroInfo_x                                           0xD47A98
#define pinstAltAdvManager_x                                       0xE84580
#define pinstAuraMgr_x                                             0xD51960
#define pinstBandageTarget_x                                       0xF36FF8
#define pinstCamActor_x                                            0xE83E8C
#define pinstCDBStr_x                                              0xE83444
#define pinstCDisplay_x                                            0xF37020
#define pinstCEverQuest_x                                          0x10D57AC
#define pinstCharData_x                                            0xF36FDC
#define pinstCharSpawn_x                                           0xF37004
#define pinstControlledMissile_x                                   0xF36FD8
#define pinstControlledPlayer_x                                    0xF37004
#define pinstCSidlManager_x                                        0x173CC70
#define pinstCXWndManager_x                                        0x173CC68
#define instDynamicZone_x                                          0xF43D98
#define pinstDZMember_x                                            0xF43EA8
#define pinstDZTimerInfo_x                                         0xF43EAC
#define pinstEQItemList_x                                          0xF33734
#define instEQMisc_x                                               0xB55D80
#define pinstEQSoundManager_x                                      0xE84880
#define instExpeditionLeader_x                                     0xF43DE2
#define instExpeditionName_x                                       0xF43E22
#define pinstGroup_x                                               0xF34AAE
#define pinstImeManager_x                                          0x173CC74
#define pinstLocalPlayer_x                                         0xF36FF0
#define pinstMercenaryData_x                                       0xFC8FF0
#define pinstMercAltAbilities_x                                    0xE847A0
#define pinstModelPlayer_x                                         0xF3701C
#define pinstPCData_x                                              0xF36FDC
#define pinstSkillMgr_x                                            0xFC9E28
#define pinstSpawnManager_x                                        0xFC9710
#define pinstSpellManager_x                                        0xFC9F70
#define pinstSpellSets_x                                           0xFC11E4
#define pinstStringTable_x                                         0xF36F84
#define pinstSwitchManager_x                                       0xF34640
#define pinstTarget_x                                              0xF37008
#define pinstTargetObject_x                                        0xF36FE0
#define pinstTargetSwitch_x                                        0xF36FE4
#define pinstTaskMember_x                                          0xE83390
#define pinstTrackTarget_x                                         0xF36FFC
#define pinstTradeTarget_x                                         0xF36FEC
#define instTributeActive_x                                        0xB55DA5
#define pinstViewActor_x                                           0xE83E88
#define pinstWorldData_x                                           0xF36FC0


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD47F78
#define pinstCAudioTriggersWindow_x                                0xD47E08
#define pinstCCharacterSelect_x                                    0xE83D34
#define pinstCFacePick_x                                           0xE83AE4
#define pinstCNoteWnd_x                                            0xE83CEC
#define pinstCBookWnd_x                                            0xE83CF4
#define pinstCPetInfoWnd_x                                         0xE83CF8
#define pinstCTrainWnd_x                                           0xE83CFC
#define pinstCSkillsWnd_x                                          0xE83D00
#define pinstCSkillsSelectWnd_x                                    0xE83D04
#define pinstCCombatSkillSelectWnd_x                               0xE83D08
#define pinstCFriendsWnd_x                                         0xE83D0C
#define pinstCAuraWnd_x                                            0xE83D10
#define pinstCRespawnWnd_x                                         0xE83D14
#define pinstCBandolierWnd_x                                       0xE83D18
#define pinstCPotionBeltWnd_x                                      0xE83D1C
#define pinstCAAWnd_x                                              0xE83D20
#define pinstCGroupSearchFiltersWnd_x                              0xE83D24
#define pinstCLoadskinWnd_x                                        0xE83D28
#define pinstCAlarmWnd_x                                           0xE83D2C
#define pinstCMusicPlayerWnd_x                                     0xE83D30
#define pinstCMailWnd_x                                            0xE83D38
#define pinstCMailCompositionWnd_x                                 0xE83D3C
#define pinstCMailAddressBookWnd_x                                 0xE83D40
#define pinstCRaidWnd_x                                            0xE83D48
#define pinstCRaidOptionsWnd_x                                     0xE83D4C
#define pinstCBreathWnd_x                                          0xE83D50
#define pinstCMapViewWnd_x                                         0xE83D54
#define pinstCMapToolbarWnd_x                                      0xE83D58
#define pinstCEditLabelWnd_x                                       0xE83D5C
#define pinstCTargetWnd_x                                          0xE83D60
#define pinstCColorPickerWnd_x                                     0xE83D64
#define pinstCPlayerWnd_x                                          0xE83D68
#define pinstCOptionsWnd_x                                         0xE83D6C
#define pinstCBuffWindowNORMAL_x                                   0xE83D70
#define pinstCBuffWindowSHORT_x                                    0xE83D74
#define pinstCharacterCreation_x                                   0xE83D78
#define pinstCCursorAttachment_x                                   0xE83D7C
#define pinstCCastingWnd_x                                         0xE83D80
#define pinstCCastSpellWnd_x                                       0xE83D84
#define pinstCSpellBookWnd_x                                       0xE83D88
#define pinstCInventoryWnd_x                                       0xE83D8C
#define pinstCBankWnd_x                                            0xE83D90
#define pinstCQuantityWnd_x                                        0xE83D94
#define pinstCLootWnd_x                                            0xE83D98
#define pinstCActionsWnd_x                                         0xE83D9C
#define pinstCCombatAbilityWnd_x                                   0xE83DA0
#define pinstCMerchantWnd_x                                        0xE83DA4
#define pinstCTradeWnd_x                                           0xE83DA8
#define pinstCSelectorWnd_x                                        0xE83DAC
#define pinstCBazaarWnd_x                                          0xE83DB0
#define pinstCBazaarSearchWnd_x                                    0xE83DB4
#define pinstCGiveWnd_x                                            0xE83DD0
#define pinstCTrackingWnd_x                                        0xE83DD8
#define pinstCInspectWnd_x                                         0xE83DDC
#define pinstCSocialEditWnd_x                                      0xE83DE0
#define pinstCFeedbackWnd_x                                        0xE83DE4
#define pinstCBugReportWnd_x                                       0xE83DE8
#define pinstCVideoModesWnd_x                                      0xE83DEC
#define pinstCTextEntryWnd_x                                       0xE83DF4
#define pinstCFileSelectionWnd_x                                   0xE83DF8
#define pinstCCompassWnd_x                                         0xE83DFC
#define pinstCPlayerNotesWnd_x                                     0xE83E00
#define pinstCGemsGameWnd_x                                        0xE83E04
#define pinstCTimeLeftWnd_x                                        0xE83E08
#define pinstCPetitionQWnd_x                                       0xE83E1C
#define pinstCSoulmarkWnd_x                                        0xE83E20
#define pinstCStoryWnd_x                                           0xE83E24
#define pinstCJournalTextWnd_x                                     0xE83E28
#define pinstCJournalCatWnd_x                                      0xE83E2C
#define pinstCBodyTintWnd_x                                        0xE83E30
#define pinstCServerListWnd_x                                      0xE83E34
#define pinstCAvaZoneWnd_x                                         0xE83E40
#define pinstCBlockedBuffWnd_x                                     0xE83E44
#define pinstCBlockedPetBuffWnd_x                                  0xE83E48
#define pinstCInvSlotMgr_x                                         0xE83E80
#define pinstCContainerMgr_x                                       0xE83E84
#define pinstCAdventureLeaderboardWnd_x                            0x10D6380
#define pinstCAdventureRequestWnd_x                                0x10D63F8
#define pinstCAltStorageWnd_x                                      0x10D66D8
#define pinstCAdventureStatsWnd_x                                  0x10D6470
#define pinstCBarterMerchantWnd_x                                  0x10D72C0
#define pinstCBarterSearchWnd_x                                    0x10D7338
#define pinstCBarterWnd_x                                          0x10D73B0
#define pinstCChatManager_x                                        0x10D7A40
#define pinstCDynamicZoneWnd_x                                     0x10D7EF0
#define pinstCEQMainWnd_x                                          0x10D8088
#define pinstCFellowshipWnd_x                                      0x10D7E84
#define pinstCFindLocationWnd_x                                    0x10D8358
#define pinstCGroupSearchWnd_x                                     0x10D8628
#define pinstCGroupWnd_x                                           0x10D86A0
#define pinstCGuildBankWnd_x                                       0x10D8718
#define pinstCGuildMgmtWnd_x                                       0x10DA808
#define pinstCHotButtonWnd_x                                       0x10DA8D4
#define pinstCHotButtonWnd1_x                                      0x10DA8D4
#define pinstCHotButtonWnd2_x                                      0x10DA8D8
#define pinstCHotButtonWnd3_x                                      0x10DA8DC
#define pinstCHotButtonWnd4_x                                      0x10DA900
#define pinstCItemDisplayManager_x                                 0x10DABF8
#define pinstCItemExpTransferWnd_x                                 0x10DAC74
#define pinstCLFGuildWnd_x                                         0x10DAF50
#define pinstCMIZoneSelectWnd_x                                    0x10DB538
#define pinstCConfirmationDialog_x                                 0x10DBC40
#define pinstCPopupWndManager_x                                    0x10DBC40
#define pinstCProgressionSelectionWnd_x                            0x10DBD30
#define pinstCPvPStatsWnd_x                                        0x10DBE20
#define pinstCSystemInfoDialogBox_x                                0x10DC528
#define pinstCTaskWnd_x                                            0x10DD8B8
#define pinstCTaskTemplateSelectWnd_x                              0x10DD840
#define pinstCTipWndOFDAY_x                                        0x10DDB10
#define pinstCTipWndCONTEXT_x                                      0x10DDB14
#define pinstCTitleWnd_x                                           0x10DDB90
#define pinstCContextMenuManager_x                                 0x173C884
#define pinstCVoiceMacroWnd_x                                      0xFCA5D8
#define pinstCHtmlWnd_x                                            0xFCA6D0
#define pinstIconCache_x                                           0x10D805C
#define pinstCTradeskillWnd_x                                      0x10DDC90

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x507680
#define __ConvertItemTags_x                                        0x4F5700
#define __ExecuteCmd_x                                             0x4E04A0
#define __EQGetTime_x                                              0x832E70
#define __get_melee_range_x                                        0x4E70E0
#define __GetGaugeValueFromEQ_x                                    0x773460
#define __GetLabelFromEQ_x                                         0x774690
#define __GetXTargetType_x                                         0x8EF780
#define __LoadFrontEnd_x                                           0x607530
#define __NewUIINI_x                                               0x772D90
#define __ProcessGameEvents_x                                      0x54AA00
#define CrashDetected_x                                            0x609000
#define DrawNetStatus_x                                            0x580E20
#define Util__FastTime_x                                           0x832180
#define Expansion_HoT_x                                            0xF452CC
#define __HelpPath_x                                               0xFC8728
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A4EC0
#define AltAdvManager__IsAbilityReady_x                            0x4A4F30
#define AltAdvManager__GetAltAbility_x                             0x4A52F0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4522E0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6370C0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x645640

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5610D0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x660100
#define CChatManager__InitContextMenu_x                            0x660C20

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x7D9170
#define CChatService__GetFriendName_x                              0x818E40

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6659C0
#define CChatWindow__Clear_x                                       0x665570
#define CChatWindow__WndNotification_x                             0x665F00

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8914B0
#define CComboWnd__Draw_x                                          0x891690
#define CComboWnd__GetCurChoice_x                                  0x8912D0
#define CComboWnd__GetListRect_x                                   0x891930
#define CComboWnd__GetTextRect_x                                   0x891510
#define CComboWnd__InsertChoice_x                                  0x8919A0
#define CComboWnd__SetColors_x                                     0x891260
#define CComboWnd__SetChoice_x                                     0x891290

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x66F030
#define CContainerWnd__vftable_x                                   0xA4FC68

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x493890
#define CDisplay__GetClickedActor_x                                0x48C4C0
#define CDisplay__GetUserDefinedColor_x                            0x48AD80
#define CDisplay__GetWorldFilePath_x                               0x48A180
#define CDisplay__is3dON_x                                         0x489550
#define CDisplay__ReloadUI_x                                       0x49EC60
#define CDisplay__WriteTextHD2_x                                   0x48FD00

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8B2F80

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8A1F20
#define CEditWnd__GetCharIndexPt_x                                 0x8A2F40
#define CEditWnd__GetDisplayString_x                               0x8A20D0
#define CEditWnd__GetHorzOffset_x                                  0x8A2410
#define CEditWnd__GetLineForPrintableChar_x                        0x8A2A10
#define CEditWnd__GetSelStartPt_x                                  0x8A31F0
#define CEditWnd__GetSTMLSafeText_x                                0x8A25B0
#define CEditWnd__PointFromPrintableChar_x                         0x8A2B00
#define CEditWnd__SelectableCharFromPoint_x                        0x8A2C80
#define CEditWnd__SetEditable_x                                    0x8A2580

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x528690
#define CEverQuest__DoTellWindow_x                                 0x52E080
#define CEverQuest__DropHeldItemOnGround_x                         0x536B20
#define CEverQuest__dsp_chat_x                                     0x52F820
#define CEverQuest__Emote_x                                        0x52FA80
#define CEverQuest__EnterZone_x                                    0x542960
#define CEverQuest__GetBodyTypeDesc_x                              0x524FC0
#define CEverQuest__GetClassDesc_x                                 0x52ABF0
#define CEverQuest__GetClassThreeLetterCode_x                      0x52B1F0
#define CEverQuest__GetDeityDesc_x                                 0x5258A0
#define CEverQuest__GetLangDesc_x                                  0x525350
#define CEverQuest__GetRaceDesc_x                                  0x52B3B0
#define CEverQuest__InterpretCmd_x                                 0x530360
#define CEverQuest__LeftClickedOnPlayer_x                          0x546D30
#define CEverQuest__LMouseUp_x                                     0x549020
#define CEverQuest__RightClickedOnPlayer_x                         0x547830
#define CEverQuest__RMouseUp_x                                     0x548870
#define CEverQuest__SetGameState_x                                 0x528D40
#define CEverQuest__UPCNotificationFlush_x                         0x531500

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x67FB10
#define CGaugeWnd__CalcLinesFillRect_x                             0x67FB70
#define CGaugeWnd__Draw_x                                          0x67FFA0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4243E0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x69C2E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6A8050
#define CInvSlotMgr__MoveItem_x                                    0x6A8F90
#define CInvSlotMgr__SelectSlot_x                                  0x6A8100

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6A7380
#define CInvSlot__SliderComplete_x                                 0x6A51D0
#define CInvSlot__GetItemBase_x                                    0x6A4660

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6A9D40

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7700B0
#define CItemDisplayWnd__UpdateStrings_x                           0x6AB070

// CLabel 
#define CLabel__Draw_x                                             0x6C5A30

// CListWnd 
#define CListWnd__AddColumn_x                                      0x87F510
#define CListWnd__AddColumn1_x                                     0x87ED00
#define CListWnd__AddLine_x                                        0x87E7B0
#define CListWnd__AddString_x                                      0x87E9C0
#define CListWnd__CalculateFirstVisibleLine_x                      0x87B890
#define CListWnd__CalculateVSBRange_x                              0x87D9B0
#define CListWnd__ClearAllSel_x                                    0x87AB40
#define CListWnd__CloseAndUpdateEditWindow_x                       0x87E380
#define CListWnd__Compare_x                                        0x87C380
#define CListWnd__Draw_x                                           0x87D610
#define CListWnd__DrawColumnSeparators_x                           0x87D4A0
#define CListWnd__DrawHeader_x                                     0x87AE50
#define CListWnd__DrawItem_x                                       0x87C9D0
#define CListWnd__DrawLine_x                                       0x87D140
#define CListWnd__DrawSeparator_x                                  0x87D540
#define CListWnd__EnsureVisible_x                                  0x87B9F0
#define CListWnd__ExtendSel_x                                      0x87C8E0
#define CListWnd__GetColumnMinWidth_x                              0x87A560
#define CListWnd__GetColumnWidth_x                                 0x87A480
#define CListWnd__GetCurSel_x                                      0x879D40
#define CListWnd__GetItemAtPoint_x                                 0x87BC80
#define CListWnd__GetItemAtPoint1_x                                0x87BCF0
#define CListWnd__GetItemData_x                                    0x879F90
#define CListWnd__GetItemHeight_x                                  0x87B4E0
#define CListWnd__GetItemIcon_x                                    0x87A170
#define CListWnd__GetItemRect_x                                    0x87BAC0
#define CListWnd__GetItemText_x                                    0x87A020
#define CListWnd__GetSelList_x                                     0x87EBF0
#define CListWnd__GetSeparatorRect_x                               0x87C2A0
#define CListWnd__RemoveLine_x                                     0x87EBA0
#define CListWnd__SetColors_x                                      0x879DA0
#define CListWnd__SetColumnJustification_x                         0x87A830
#define CListWnd__SetColumnWidth_x                                 0x87A510
#define CListWnd__SetCurSel_x                                      0x879D80
#define CListWnd__SetItemColor_x                                   0x87E060
#define CListWnd__SetItemData_x                                    0x87ABF0
#define CListWnd__SetItemText_x                                    0x87DEA0
#define CListWnd__ShiftColumnSeparator_x                           0x87DD30
#define CListWnd__Sort_x                                           0x87F67D
#define CListWnd__ToggleSel_x                                      0x87AAC0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6DECD0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6FFAA0
#define CMerchantWnd__RequestBuyItem_x                             0x705FF0
#define CMerchantWnd__RequestSellItem_x                            0x72D910
#define CMerchantWnd__SelectRecoverySlot_x                         0x6FFD50
#define CMerchantWnd__SelectBuySellSlot_x                          0x6FEF60
#define CMerchantWnd__ActualSelect_x                               0x703470

// CObfuscator
#define CObfuscator__doit_x                                        0x7F98E0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x896C70
#define CSidlManager__CreateLabel_x                                0x766510

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x62E220
#define CSidlScreenWnd__CalculateVSBRange_x                        0x62E150
#define CSidlScreenWnd__ConvertToRes_x                             0x8B2E60
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x884640
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x885B30
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x885BE0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8850B0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x884120
#define CSidlScreenWnd__EnableIniStorage_x                         0x883860
#define CSidlScreenWnd__GetSidlPiece_x                             0x884310
#define CSidlScreenWnd__Init1_x                                    0x885810
#define CSidlScreenWnd__LoadIniInfo_x                              0x8846F0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x883A20
#define CSidlScreenWnd__LoadSidlScreen_x                           0x885300
#define CSidlScreenWnd__StoreIniInfo_x                             0x883320
#define CSidlScreenWnd__StoreIniVis_x                              0x8837F0
#define CSidlScreenWnd__WndNotification_x                          0x885590
#define CSidlScreenWnd__GetChildItem_x                             0x883930
#define CSidlScreenWnd__HandleLButtonUp_x                          0x88A4D0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5C9430
#define CSkillMgr__GetSkillCap_x                                   0x5C95D0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8BCEA0
#define CSliderWnd__SetValue_x                                     0x8BD070
#define CSliderWnd__SetNumTicks_x                                  0x8BD7F0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x76DD50

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8AD5C0
#define CStmlWnd__CalculateHSBRange_x                              0x8A5BF0
#define CStmlWnd__CalculateVSBRange_x                              0x8A5C80
#define CStmlWnd__CanBreakAtCharacter_x                            0x8A5E00
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8A66E0
#define CStmlWnd__ForceParseNow_x                                  0x8ADF10
#define CStmlWnd__GetNextTagPiece_x                                0x8A65E0
#define CStmlWnd__GetSTMLText_x                                    0x664E10
#define CStmlWnd__GetVisibleText_x                                 0x8A7130
#define CStmlWnd__InitializeWindowVariables_x                      0x8A93E0
#define CStmlWnd__MakeStmlColorTag_x                               0x8A4DD0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8A4E30
#define CStmlWnd__SetSTMLText_x                                    0x8AAC40
#define CStmlWnd__StripFirstSTMLLines_x                            0x8AD260
#define CStmlWnd__UpdateHistoryString_x                            0x8A8070

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8B4660
#define CTabWnd__DrawCurrentPage_x                                 0x8B3ED0
#define CTabWnd__DrawTab_x                                         0x8B3C90
#define CTabWnd__GetCurrentPage_x                                  0x8B42A0
#define CTabWnd__GetPageInnerRect_x                                0x8B3980
#define CTabWnd__GetTabInnerRect_x                                 0x8B3B80
#define CTabWnd__GetTabRect_x                                      0x8B3A50
#define CTabWnd__InsertPage_x                                      0x8B4950
#define CTabWnd__SetPage_x                                         0x8B42D0
#define CTabWnd__SetPageRect_x                                     0x8B45A0
#define CTabWnd__UpdatePage_x                                      0x8B48F0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4200E0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8B0A30

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8B9860

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x877F20

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x411860
#define CXStr__CXStr1_x                                            0x878F60
#define CXStr__CXStr3_x                                            0x82F210
#define CXStr__dCXStr_x                                            0x8B85C0
#define CXStr__operator_equal_x                                    0x82F380
#define CXStr__operator_equal1_x                                   0x82F3D0
#define CXStr__operator_plus_equal1_x                              0x8304B0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8896D0
#define CXWnd__Center_x                                            0x88F8F0
#define CXWnd__ClrFocus_x                                          0x8892A0
#define CXWnd__DoAllDrawing_x                                      0x88F520
#define CXWnd__DrawChildren_x                                      0x88F6D0
#define CXWnd__DrawColoredRect_x                                   0x889A90
#define CXWnd__DrawTooltip_x                                       0x889D30
#define CXWnd__DrawTooltipAtPoint_x                                0x88E500
#define CXWnd__GetBorderFrame_x                                    0x88A1A0
#define CXWnd__GetChildWndAt_x                                     0x88D4B0
#define CXWnd__GetClientClipRect_x                                 0x889F50
#define CXWnd__GetScreenClipRect_x                                 0x88EC00
#define CXWnd__GetScreenRect_x                                     0x88A370
#define CXWnd__GetTooltipRect_x                                    0x889BC0
#define CXWnd__GetWindowTextA_x                                    0x4118A0
#define CXWnd__IsActive_x                                          0x89CCE0
#define CXWnd__IsDescendantOf_x                                    0x88A0E0
#define CXWnd__IsReallyVisible_x                                   0x88D490
#define CXWnd__IsType_x                                            0x8B6060
#define CXWnd__Move_x                                              0x88CC00
#define CXWnd__Move1_x                                             0x88F1F0
#define CXWnd__ProcessTransition_x                                 0x889670
#define CXWnd__Refade_x                                            0x889450
#define CXWnd__Resize_x                                            0x88A430
#define CXWnd__Right_x                                             0x88EA00
#define CXWnd__SetFocus_x                                          0x88BD50
#define CXWnd__SetFont_x                                           0x8892F0
#define CXWnd__SetKeyTooltip_x                                     0x88A6A0
#define CXWnd__SetMouseOver_x                                      0x88EEF0
#define CXWnd__StartFade_x                                         0x889720
#define CXWnd__GetChildItem_x                                      0x88EE40

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x89E600
#define CXWndManager__DrawWindows_x                                0x89E240
#define CXWndManager__GetKeyboardFlags_x                           0x89C810
#define CXWndManager__HandleKeyboardMsg_x                          0x89D160
#define CXWndManager__RemoveWnd_x                                  0x89CE70

// CDBStr
#define CDBStr__GetString_x                                        0x4879E0

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8EC080
#define EQ_Character__CastSpell_x                                  0x43C090
#define EQ_Character__Cur_HP_x                                     0x4519A0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4351F0
#define EQ_Character__GetCharInfo2_x                               0x803B80
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42D520
#define EQ_Character__GetFocusRangeModifier_x                      0x42D700
#define EQ_Character__Max_Endurance_x                              0x5926B0
#define EQ_Character__Max_HP_x                                     0x448090
#define EQ_Character__Max_Mana_x                                   0x5924E0
#define EQ_Character__doCombatAbility_x                            0x58FD10
#define EQ_Character__UseSkill_x                                   0x45C4E0
#define EQ_Character__GetConLevel_x                                0x585480
#define EQ_Character__IsExpansionFlag_x                            0x410D80
#define EQ_Character__TotalEffect_x                                0x43A1C0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x566150
#define EQ_Item__CreateItemTagString_x                             0x7E48B0
#define EQ_Item__IsStackable_x                                     0x7D8AF0
#define EQ_Item__GetImageNum_x                                     0x7DB740

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A6FE0
#define EQ_LoadingS__Array_x                                       0xB63320

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x593D10
#define EQ_PC__GetAltAbilityIndex_x                                0x7ECAA0
#define EQ_PC__GetCombatAbility_x                                  0x7ECB30
#define EQ_PC__GetCombatAbilityTimer_x                             0x7ECBE0
#define EQ_PC__GetItemTimerValue_x                                 0x58DAF0
#define EQ_PC__HasLoreItem_x                                       0x588610
#define EQ_PC__AlertInventoryChanged_x                             0x585450
#define EQ_PC__GetPcZoneClient_x                                   0x5AD790
// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E5060
#define EQItemList__add_item_x                                     0x4E4FA0
#define EQItemList__delete_item_x                                  0x4E5460
#define EQItemList__FreeItemList_x                                 0x4E5360

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x486EB0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x599110
#define EQPlayer__dEQPlayer_x                                      0x5A1C10
#define EQPlayer__DoAttack_x                                       0x5B35C0
#define EQPlayer__EQPlayer_x                                       0x5A4060
#define EQPlayer__SetNameSpriteState_x                             0x59EA30
#define EQPlayer__SetNameSpriteTint_x                              0x59A440
#define EQPlayer__IsBodyType_j_x                                   0x8EB390
#define EQPlayer__IsTargetable_x                                   0x8EBB60

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5A7CE0
#define EQPlayerManager__GetSpawnByName_x                          0x5A8140

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56C240
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56C280
#define KeypressHandler__ClearCommandStateArray_x                  0x56BE20
#define KeypressHandler__HandleKeyDown_x                           0x56A770
#define KeypressHandler__HandleKeyUp_x                             0x56AA90
#define KeypressHandler__SaveKeymapping_x                          0x56BEF0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6D70F0
#define MapViewMap__SaveEx_x                                       0x6DA9D0

#define PlayerPointManager__GetAltCurrency_x                       0x7FDD40

// StringTable 
#define StringTable__getString_x                                   0x7F9B80

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x592160

//Doors
#define EQSwitch__UseSwitch_x                                      0x5223F0

//IconCache
#define IconCache__GetIcon_x                                       0x675330

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x66C360
#define CContainerMgr__CloseContainer_x                            0x66CB70

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x736980

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x55FBB0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B5550
#define EQ_Spell__SpellAffects_x                                   0x4B55F0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B5620
#define CharacterZoneClient__CalcAffectChange_x                    0x436510
#define CLootWnd__LootAll_x                                        0x6CCD30
#define CTargetWnd__GetBuffCaster_x                                0x77B8F0
