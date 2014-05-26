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
#define __ExpectedVersionDate                                     "May 19 2014"
#define __ExpectedVersionTime                                     "17:59:03"
#define __ActualVersionDate_x                                      0xA47478
#define __ActualVersionTime_x                                      0xA47484

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x570AB0
#define __MemChecker1_x                                            0x8328B0
#define __MemChecker2_x                                            0x607360
#define __MemChecker3_x                                            0x6072B0
#define __MemChecker4_x                                            0x7B7460
#define __EncryptPad0_x                                            0xBB0938
#define __EncryptPad1_x                                            0xD26E58
#define __EncryptPad2_x                                            0xBF7048
#define __EncryptPad3_x                                            0xBF6C48
#define __EncryptPad4_x                                            0xD04EE8
#define __AC1_x                                                    0x7747C5
#define __AC2_x                                                    0x5271E7
#define __AC3_x                                                    0x53B940
#define __AC4_x                                                    0x541A70
#define __AC5_x                                                    0x54E091
#define __AC6_x                                                    0x551BD2
#define __AC7_x                                                    0x547B6C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x10D6628
#define DI8__Keyboard_x                                            0x10D662C
#define DI8__Mouse_x                                               0x10D6630
#define __AltTimerReady_x                                          0xF363D9
#define __Attack_x                                                 0xFC91D2
#define __Autofire_x                                               0xFC91D3
#define __BindList_x                                               0xB75420
#define __Clicks_x                                                 0xF45020
#define __CommandList_x                                            0xB79490
#define __CurrentMapLabel_x                                        0x10DC2A8
#define __CurrentSocial_x                                          0xB3B8C0
#define __DoAbilityList_x                                          0xF7B780
#define __do_loot_x                                                0x4EFD80
#define __DrawHandler_x                                            0x173E80C
#define __GroupCount_x                                             0xF35AB2

#define __Guilds_x                                                 0xF3B5A0
#define __gWorld_x                                                 0xF37F6C
#define __HotkeyPage_x                                             0xFC2180
#define __HWnd_x                                                   0xFCE530
#define __InChatMode_x                                             0xF44F4C
#define __LastTell_x                                               0xF46E88
#define __LMouseHeldTime_x                                         0xF4508C
#define __Mouse_x                                                  0x10D6634
#define __MouseLook_x                                              0xF44FE6
#define __MouseEventTime_x                                         0xFC99BC
#define __NetStatusToggle_x                                        0xF44FE9
#define __PCNames_x                                                0xF464C8
#define __RangeAttackReady_x                                       0xF46160
#define __RMouseHeldTime_x                                         0xF45088
#define __RunWalkState_x                                           0xF44F50
#define __ScreenMode_x                                             0xE844B0
#define __ScreenX_x                                                0xF44F04
#define __ScreenY_x                                                0xF44F00
#define __ScreenXMax_x                                             0xF44F08
#define __ScreenYMax_x                                             0xF44F0C
#define __ServerHost_x                                             0xF359FC
#define __ServerName_x                                             0xF7B740
#define __ShiftKeyDown_x                                           0xF455F0
#define __ShowNames_x                                              0xF4636C
#define __Socials_x                                                0xF7B840
#define __SubscriptionType_x                                       0x1105FE0
#define __TargetAggroHolder_x                                      0x10DE4C0
#define __GroupAggro_x                                             0x10DE500
#define __LoginName_x                                              0xFCD108
#define __Inviter_x                                                0xFC9150


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF38058
#define instEQZoneInfo_x                                           0xF451DC
#define instKeypressHandler_x                                      0xFC99A0
#define pinstActiveBanker_x                                        0xF38010
#define pinstActiveCorpse_x                                        0xF38014
#define pinstActiveGMaster_x                                       0xF38018
#define pinstActiveMerchant_x                                      0xF3800C
#define pinstAggroInfo_x                                           0xD48A98
#define pinstAltAdvManager_x                                       0xE85580
#define pinstAuraMgr_x                                             0xD52960
#define pinstBandageTarget_x                                       0xF37FF8
#define pinstCamActor_x                                            0xE84E8C
#define pinstCDBStr_x                                              0xE84444
#define pinstCDisplay_x                                            0xF38020
#define pinstCEverQuest_x                                          0x10D67AC
#define pinstCharData_x                                            0xF37FDC
#define pinstCharSpawn_x                                           0xF38004
#define pinstControlledMissile_x                                   0xF37FD8
#define pinstControlledPlayer_x                                    0xF38004
#define pinstCSidlManager_x                                        0x173DC78
#define pinstCXWndManager_x                                        0x173DC70
#define instDynamicZone_x                                          0xF44D98
#define pinstDZMember_x                                            0xF44EA8
#define pinstDZTimerInfo_x                                         0xF44EAC
#define pinstEQItemList_x                                          0xF34734
#define instEQMisc_x                                               0xB56D80
#define pinstEQSoundManager_x                                      0xE85880
#define instExpeditionLeader_x                                     0xF44DE2
#define instExpeditionName_x                                       0xF44E22
#define pinstGroup_x                                               0xF35AAE
#define pinstImeManager_x                                          0x173DC7C
#define pinstLocalPlayer_x                                         0xF37FF0
#define pinstMercenaryData_x                                       0xFC9FF0
#define pinstMercAltAbilities_x                                    0xE857A0
#define pinstModelPlayer_x                                         0xF3801C
#define pinstPCData_x                                              0xF37FDC
#define pinstSkillMgr_x                                            0xFCAE28
#define pinstSpawnManager_x                                        0xFCA710
#define pinstSpellManager_x                                        0xFCAF70
#define pinstSpellSets_x                                           0xFC21E4
#define pinstStringTable_x                                         0xF37F84
#define pinstSwitchManager_x                                       0xF35640
#define pinstTarget_x                                              0xF38008
#define pinstTargetObject_x                                        0xF37FE0
#define pinstTargetSwitch_x                                        0xF37FE4
#define pinstTaskMember_x                                          0xE84390
#define pinstTrackTarget_x                                         0xF37FFC
#define pinstTradeTarget_x                                         0xF37FEC
#define instTributeActive_x                                        0xB56DA5
#define pinstViewActor_x                                           0xE84E88
#define pinstWorldData_x                                           0xF37FC0


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD48F78
#define pinstCAudioTriggersWindow_x                                0xD48E08
#define pinstCCharacterSelect_x                                    0xE84D34
#define pinstCFacePick_x                                           0xE84AE4
#define pinstCNoteWnd_x                                            0xE84CEC
#define pinstCBookWnd_x                                            0xE84CF4
#define pinstCPetInfoWnd_x                                         0xE84CF8
#define pinstCTrainWnd_x                                           0xE84CFC
#define pinstCSkillsWnd_x                                          0xE84D00
#define pinstCSkillsSelectWnd_x                                    0xE84D04
#define pinstCCombatSkillSelectWnd_x                               0xE84D08
#define pinstCFriendsWnd_x                                         0xE84D0C
#define pinstCAuraWnd_x                                            0xE84D10
#define pinstCRespawnWnd_x                                         0xE84D14
#define pinstCBandolierWnd_x                                       0xE84D18
#define pinstCPotionBeltWnd_x                                      0xE84D1C
#define pinstCAAWnd_x                                              0xE84D20
#define pinstCGroupSearchFiltersWnd_x                              0xE84D24
#define pinstCLoadskinWnd_x                                        0xE84D28
#define pinstCAlarmWnd_x                                           0xE84D2C
#define pinstCMusicPlayerWnd_x                                     0xE84D30
#define pinstCMailWnd_x                                            0xE84D38
#define pinstCMailCompositionWnd_x                                 0xE84D3C
#define pinstCMailAddressBookWnd_x                                 0xE84D40
#define pinstCRaidWnd_x                                            0xE84D48
#define pinstCRaidOptionsWnd_x                                     0xE84D4C
#define pinstCBreathWnd_x                                          0xE84D50
#define pinstCMapViewWnd_x                                         0xE84D54
#define pinstCMapToolbarWnd_x                                      0xE84D58
#define pinstCEditLabelWnd_x                                       0xE84D5C
#define pinstCTargetWnd_x                                          0xE84D60
#define pinstCColorPickerWnd_x                                     0xE84D64
#define pinstCPlayerWnd_x                                          0xE84D68
#define pinstCOptionsWnd_x                                         0xE84D6C
#define pinstCBuffWindowNORMAL_x                                   0xE84D70
#define pinstCBuffWindowSHORT_x                                    0xE84D74
#define pinstCharacterCreation_x                                   0xE84D78
#define pinstCCursorAttachment_x                                   0xE84D7C
#define pinstCCastingWnd_x                                         0xE84D80
#define pinstCCastSpellWnd_x                                       0xE84D84
#define pinstCSpellBookWnd_x                                       0xE84D88
#define pinstCInventoryWnd_x                                       0xE84D8C
#define pinstCBankWnd_x                                            0xE84D90
#define pinstCQuantityWnd_x                                        0xE84D94
#define pinstCLootWnd_x                                            0xE84D98
#define pinstCActionsWnd_x                                         0xE84D9C
#define pinstCCombatAbilityWnd_x                                   0xE84DA0
#define pinstCMerchantWnd_x                                        0xE84DA4
#define pinstCTradeWnd_x                                           0xE84DA8
#define pinstCSelectorWnd_x                                        0xE84DAC
#define pinstCBazaarWnd_x                                          0xE84DB0
#define pinstCBazaarSearchWnd_x                                    0xE84DB4
#define pinstCGiveWnd_x                                            0xE84DD0
#define pinstCTrackingWnd_x                                        0xE84DD8
#define pinstCInspectWnd_x                                         0xE84DDC
#define pinstCSocialEditWnd_x                                      0xE84DE0
#define pinstCFeedbackWnd_x                                        0xE84DE4
#define pinstCBugReportWnd_x                                       0xE84DE8
#define pinstCVideoModesWnd_x                                      0xE84DEC
#define pinstCTextEntryWnd_x                                       0xE84DF4
#define pinstCFileSelectionWnd_x                                   0xE84DF8
#define pinstCCompassWnd_x                                         0xE84DFC
#define pinstCPlayerNotesWnd_x                                     0xE84E00
#define pinstCGemsGameWnd_x                                        0xE84E04
#define pinstCTimeLeftWnd_x                                        0xE84E08
#define pinstCPetitionQWnd_x                                       0xE84E1C
#define pinstCSoulmarkWnd_x                                        0xE84E20
#define pinstCStoryWnd_x                                           0xE84E24
#define pinstCJournalTextWnd_x                                     0xE84E28
#define pinstCJournalCatWnd_x                                      0xE84E2C
#define pinstCBodyTintWnd_x                                        0xE84E30
#define pinstCServerListWnd_x                                      0xE84E34
#define pinstCAvaZoneWnd_x                                         0xE84E40
#define pinstCBlockedBuffWnd_x                                     0xE84E44
#define pinstCBlockedPetBuffWnd_x                                  0xE84E48
#define pinstCInvSlotMgr_x                                         0xE84E80
#define pinstCContainerMgr_x                                       0xE84E84
#define pinstCAdventureLeaderboardWnd_x                            0x10D7380
#define pinstCAdventureRequestWnd_x                                0x10D73F8
#define pinstCAltStorageWnd_x                                      0x10D76D8
#define pinstCAdventureStatsWnd_x                                  0x10D7470
#define pinstCBarterMerchantWnd_x                                  0x10D82C0
#define pinstCBarterSearchWnd_x                                    0x10D8338
#define pinstCBarterWnd_x                                          0x10D83B0
#define pinstCChatManager_x                                        0x10D8A40
#define pinstCDynamicZoneWnd_x                                     0x10D8EF0
#define pinstCEQMainWnd_x                                          0x10D9088
#define pinstCFellowshipWnd_x                                      0x10D8E84
#define pinstCFindLocationWnd_x                                    0x10D9358
#define pinstCGroupSearchWnd_x                                     0x10D9628
#define pinstCGroupWnd_x                                           0x10D96A0
#define pinstCGuildBankWnd_x                                       0x10D9718
#define pinstCGuildMgmtWnd_x                                       0x10DB808
#define pinstCHotButtonWnd_x                                       0x10DB8D4
#define pinstCHotButtonWnd1_x                                      0x10DB8D4
#define pinstCHotButtonWnd2_x                                      0x10DB8D8
#define pinstCHotButtonWnd3_x                                      0x10DB8DC
#define pinstCHotButtonWnd4_x                                      0x10DB900
#define pinstCItemDisplayManager_x                                 0x10DBBF8
#define pinstCItemExpTransferWnd_x                                 0x10DBC74
#define pinstCLFGuildWnd_x                                         0x10DBF50
#define pinstCMIZoneSelectWnd_x                                    0x10DC538
#define pinstCConfirmationDialog_x                                 0x10DCC40
#define pinstCPopupWndManager_x                                    0x10DCC40
#define pinstCProgressionSelectionWnd_x                            0x10DCD30
#define pinstCPvPStatsWnd_x                                        0x10DCE20
#define pinstCSystemInfoDialogBox_x                                0x10DD528
#define pinstCTaskWnd_x                                            0x10DE8C0
#define pinstCTaskTemplateSelectWnd_x                              0x10DE848
#define pinstCTipWndOFDAY_x                                        0x10DEB18
#define pinstCTipWndCONTEXT_x                                      0x10DEB1C
#define pinstCTitleWnd_x                                           0x10DEB98
#define pinstCContextMenuManager_x                                 0x173D88C
#define pinstCVoiceMacroWnd_x                                      0xFCB5D8
#define pinstCHtmlWnd_x                                            0xFCB6D0
#define pinstIconCache_x                                           0x10D905C
#define pinstCTradeskillWnd_x                                      0x10DEC98

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x506A60
#define __ConvertItemTags_x                                        0x4F4A40
#define __ExecuteCmd_x                                             0x4DF7F0
#define __EQGetTime_x                                              0x833410
#define __get_melee_range_x                                        0x4E6410
#define __GetGaugeValueFromEQ_x                                    0x773520
#define __GetLabelFromEQ_x                                         0x774750
#define __GetXTargetType_x                                         0x8EFCD0
#define __LoadFrontEnd_x                                           0x606A10
#define __NewUIINI_x                                               0x772E50
#define __ProcessGameEvents_x                                      0x549CB0
#define CrashDetected_x                                            0x6084E0
#define DrawNetStatus_x                                            0x580490
#define Util__FastTime_x                                           0x832720
#define Expansion_HoT_x                                            0xF462CC
#define __HelpPath_x                                               0xFC9728
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A5410
#define AltAdvManager__IsAbilityReady_x                            0x4A5480
#define AltAdvManager__GetAltAbility_x                             0x4A5840

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4524C0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x636600

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x643FE0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x560340

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x65F880
#define CChatManager__InitContextMenu_x                            0x6603A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x819520
#define CChatService__GetFriendName_x                              0x819530

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x665140
#define CChatWindow__Clear_x                                       0x664CF0
#define CChatWindow__WndNotification_x                             0x665680

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x891A10
#define CComboWnd__Draw_x                                          0x891BF0
#define CComboWnd__GetCurChoice_x                                  0x891830
#define CComboWnd__GetListRect_x                                   0x891E90
#define CComboWnd__GetTextRect_x                                   0x891A70
#define CComboWnd__InsertChoice_x                                  0x891F00
#define CComboWnd__SetColors_x                                     0x8917C0
#define CComboWnd__SetChoice_x                                     0x8917F0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x66E810
#define CContainerWnd__vftable_x                                   0xA50C28

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x493CC0
#define CDisplay__GetClickedActor_x                                0x48C8E0
#define CDisplay__GetUserDefinedColor_x                            0x48B1A0
#define CDisplay__GetWorldFilePath_x                               0x48A5A0
#define CDisplay__is3dON_x                                         0x489970
#define CDisplay__ReloadUI_x                                       0x49F090
#define CDisplay__WriteTextHD2_x                                   0x490130

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8B34B0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8A2410
#define CEditWnd__GetCharIndexPt_x                                 0x8A3430
#define CEditWnd__GetDisplayString_x                               0x8A25C0
#define CEditWnd__GetHorzOffset_x                                  0x8A2900
#define CEditWnd__GetLineForPrintableChar_x                        0x8A2F00
#define CEditWnd__GetSelStartPt_x                                  0x8A36E0
#define CEditWnd__GetSTMLSafeText_x                                0x8A2AA0
#define CEditWnd__PointFromPrintableChar_x                         0x8A2FF0
#define CEditWnd__SelectableCharFromPoint_x                        0x8A3170
#define CEditWnd__SetEditable_x                                    0x8A2A70

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x527930
#define CEverQuest__DoTellWindow_x                                 0x52D320
#define CEverQuest__DropHeldItemOnGround_x                         0x535DC0
#define CEverQuest__dsp_chat_x                                     0x52EAC0
#define CEverQuest__Emote_x                                        0x52ED20
#define CEverQuest__EnterZone_x                                    0x541C00
#define CEverQuest__GetBodyTypeDesc_x                              0x524260
#define CEverQuest__GetClassDesc_x                                 0x529E90
#define CEverQuest__GetClassThreeLetterCode_x                      0x52A490
#define CEverQuest__GetDeityDesc_x                                 0x524B40
#define CEverQuest__GetLangDesc_x                                  0x5245F0
#define CEverQuest__GetRaceDesc_x                                  0x52A650
#define CEverQuest__InterpretCmd_x                                 0x52F600
#define CEverQuest__LeftClickedOnPlayer_x                          0x545FE0
#define CEverQuest__LMouseUp_x                                     0x5482D0
#define CEverQuest__RightClickedOnPlayer_x                         0x546AE0
#define CEverQuest__RMouseUp_x                                     0x547B20
#define CEverQuest__SetGameState_x                                 0x527FE0
#define CEverQuest__UPCNotificationFlush_x                         0x5307A0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x67F1F0
#define CGaugeWnd__CalcLinesFillRect_x                             0x67F250
#define CGaugeWnd__Draw_x                                          0x67F680

// CGuild
#define CGuild__FindMemberByName_x                                 0x4243A0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x69BA00

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6A77A0
#define CInvSlotMgr__MoveItem_x                                    0x6A86E0
#define CInvSlotMgr__SelectSlot_x                                  0x6A7850

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6A6AD0
#define CInvSlot__SliderComplete_x                                 0x6A4920
#define CInvSlot__GetItemBase_x                                    0x6A3D90

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6A94D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x770150
#define CItemDisplayWnd__UpdateStrings_x                           0x6AA800

// CLabel 
#define CLabel__Draw_x                                             0x6C5290

// CListWnd 
#define CListWnd__AddColumn_x                                      0x87FA40
#define CListWnd__AddColumn1_x                                     0x87F230
#define CListWnd__AddLine_x                                        0x87ECE0
#define CListWnd__AddString_x                                      0x87EEF0
#define CListWnd__CalculateFirstVisibleLine_x                      0x87BDB0
#define CListWnd__CalculateVSBRange_x                              0x87DED0
#define CListWnd__ClearAllSel_x                                    0x87B070
#define CListWnd__CloseAndUpdateEditWindow_x                       0x87E8B0
#define CListWnd__Compare_x                                        0x87C8A0
#define CListWnd__Draw_x                                           0x87DB30
#define CListWnd__DrawColumnSeparators_x                           0x87D9C0
#define CListWnd__DrawHeader_x                                     0x87B380
#define CListWnd__DrawItem_x                                       0x87CEF0
#define CListWnd__DrawLine_x                                       0x87D660
#define CListWnd__DrawSeparator_x                                  0x87DA60
#define CListWnd__EnsureVisible_x                                  0x87BF10
#define CListWnd__ExtendSel_x                                      0x87CE00
#define CListWnd__GetColumnMinWidth_x                              0x87AA90
#define CListWnd__GetColumnWidth_x                                 0x87A9B0
#define CListWnd__GetCurSel_x                                      0x87A280
#define CListWnd__GetItemAtPoint_x                                 0x87C1B0
#define CListWnd__GetItemAtPoint1_x                                0x87C220
#define CListWnd__GetItemData_x                                    0x87A4C0
#define CListWnd__GetItemHeight_x                                  0x87BA10
#define CListWnd__GetItemIcon_x                                    0x87A6A0
#define CListWnd__GetItemRect_x                                    0x87BFF0
#define CListWnd__GetItemText_x                                    0x87A550
#define CListWnd__GetSelList_x                                     0x87F120
#define CListWnd__GetSeparatorRect_x                               0x87C7D0
#define CListWnd__RemoveLine_x                                     0x87F0D0
#define CListWnd__SetColors_x                                      0x87A2E0
#define CListWnd__SetColumnJustification_x                         0x87AD60
#define CListWnd__SetColumnWidth_x                                 0x87AA40
#define CListWnd__SetCurSel_x                                      0x87A2C0
#define CListWnd__SetItemColor_x                                   0x87E590
#define CListWnd__SetItemData_x                                    0x87B120
#define CListWnd__SetItemText_x                                    0x87E3D0
#define CListWnd__ShiftColumnSeparator_x                           0x87E260
#define CListWnd__Sort_x                                           0x87FBAD
#define CListWnd__ToggleSel_x                                      0x87AFF0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6DE630

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6FF3B0
#define CMerchantWnd__RequestBuyItem_x                             0x705CA0
#define CMerchantWnd__RequestSellItem_x                            0x72D5E0
#define CMerchantWnd__SelectRecoverySlot_x                         0x6FF660
#define CMerchantWnd__SelectBuySellSlot_x                          0x6FE8C0
#define CMerchantWnd__ActualSelect_x                               0x7030A0

// CObfuscator
#define CObfuscator__doit_x                                        0x7FA0A0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8972B0
#define CSidlManager__CreateLabel_x                                0x766140

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x62D780
#define CSidlScreenWnd__CalculateVSBRange_x                        0x62D6A0
#define CSidlScreenWnd__ConvertToRes_x                             0x8B3390
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x884B70
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x886040
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8860F0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8855C0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x884650
#define CSidlScreenWnd__EnableIniStorage_x                         0x883D90
#define CSidlScreenWnd__GetSidlPiece_x                             0x884840
#define CSidlScreenWnd__Init1_x                                    0x885D20
#define CSidlScreenWnd__LoadIniInfo_x                              0x884C20
#define CSidlScreenWnd__LoadIniListWnd_x                           0x883F50
#define CSidlScreenWnd__LoadSidlScreen_x                           0x885810
#define CSidlScreenWnd__StoreIniInfo_x                             0x883860
#define CSidlScreenWnd__StoreIniVis_x                              0x883D20
#define CSidlScreenWnd__WndNotification_x                          0x885AA0
#define CSidlScreenWnd__GetChildItem_x                             0x883E60
#define CSidlScreenWnd__HandleLButtonUp_x                          0x88AA50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5C8AA0
#define CSkillMgr__GetSkillCap_x                                   0x5C8C40

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8BD360
#define CSliderWnd__SetValue_x                                     0x8BD530
#define CSliderWnd__SetNumTicks_x                                  0x8BDCB0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x76DDF0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8ADA90
#define CStmlWnd__CalculateHSBRange_x                              0x8A5FD0
#define CStmlWnd__CalculateVSBRange_x                              0x8A6060
#define CStmlWnd__CanBreakAtCharacter_x                            0x8A61D0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8A6AB0
#define CStmlWnd__ForceParseNow_x                                  0x8AE450
#define CStmlWnd__GetNextTagPiece_x                                0x8A69B0
#define CStmlWnd__GetSTMLText_x                                    0x664590
#define CStmlWnd__GetVisibleText_x                                 0x8A7500
#define CStmlWnd__InitializeWindowVariables_x                      0x8A9870
#define CStmlWnd__MakeStmlColorTag_x                               0x8A52D0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8A5330
#define CStmlWnd__SetSTMLText_x                                    0x8AB0D0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8AD730
#define CStmlWnd__UpdateHistoryString_x                            0x8A8430

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8B4B80
#define CTabWnd__DrawCurrentPage_x                                 0x8B43F0
#define CTabWnd__DrawTab_x                                         0x8B41B0
#define CTabWnd__GetCurrentPage_x                                  0x8B47C0
#define CTabWnd__GetPageInnerRect_x                                0x8B3EA0
#define CTabWnd__GetTabInnerRect_x                                 0x8B40A0
#define CTabWnd__GetTabRect_x                                      0x8B3F70
#define CTabWnd__InsertPage_x                                      0x8B4E70
#define CTabWnd__SetPage_x                                         0x8B47F0
#define CTabWnd__SetPageRect_x                                     0x8B4AC0
#define CTabWnd__UpdatePage_x                                      0x8B4E10

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4200B0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8B0F70

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8B9D20

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x878320

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4116D0
#define CXStr__CXStr1_x                                            0x7A43F0
#define CXStr__CXStr3_x                                            0x82F7B0
#define CXStr__dCXStr_x                                            0x710680
#define CXStr__operator_equal_x                                    0x82F920
#define CXStr__operator_equal1_x                                   0x82F970
#define CXStr__operator_plus_equal1_x                              0x830A50

// CXWnd 
#define CXWnd__BringToTop_x                                        0x889C70
#define CXWnd__Center_x                                            0x88FE60
#define CXWnd__ClrFocus_x                                          0x889850
#define CXWnd__DoAllDrawing_x                                      0x88FAB0
#define CXWnd__DrawChildren_x                                      0x88FC50
#define CXWnd__DrawColoredRect_x                                   0x88A010
#define CXWnd__DrawTooltip_x                                       0x88A2B0
#define CXWnd__DrawTooltipAtPoint_x                                0x88EA40
#define CXWnd__GetBorderFrame_x                                    0x88A720
#define CXWnd__GetChildWndAt_x                                     0x88DA10
#define CXWnd__GetClientClipRect_x                                 0x88A4D0
#define CXWnd__GetScreenClipRect_x                                 0x88F140
#define CXWnd__GetScreenRect_x                                     0x88A8F0
#define CXWnd__GetTooltipRect_x                                    0x88A140
#define CXWnd__GetWindowTextA_x                                    0x411710
#define CXWnd__IsActive_x                                          0x89D1D0
#define CXWnd__IsDescendantOf_x                                    0x88A660
#define CXWnd__IsReallyVisible_x                                   0x88D9F0
#define CXWnd__IsType_x                                            0x8B6520
#define CXWnd__Move_x                                              0x88D160
#define CXWnd__Move1_x                                             0x88F770
#define CXWnd__ProcessTransition_x                                 0x889C10
#define CXWnd__Refade_x                                            0x8899F0
#define CXWnd__Resize_x                                            0x88A9B0
#define CXWnd__Right_x                                             0x88EF40
#define CXWnd__SetFocus_x                                          0x88C2B0
#define CXWnd__SetFont_x                                           0x8898A0
#define CXWnd__SetKeyTooltip_x                                     0x88AC20
#define CXWnd__SetMouseOver_x                                      0x88F460
#define CXWnd__StartFade_x                                         0x889CC0
#define CXWnd__GetChildItem_x                                      0x88F3B0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x89EB10
#define CXWndManager__DrawWindows_x                                0x89E750
#define CXWndManager__GetKeyboardFlags_x                           0x89CD00
#define CXWndManager__HandleKeyboardMsg_x                          0x89D670
#define CXWndManager__RemoveWnd_x                                  0x89D360

// CDBStr
#define CDBStr__GetString_x                                        0x487E00

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8EC5B0
#define EQ_Character__CastSpell_x                                  0x43C170
#define EQ_Character__Cur_HP_x                                     0x451B80
#define EQ_Character__GetAACastingTimeModifier_x                   0x435240
#define EQ_Character__GetCharInfo2_x                               0x804240
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42D550
#define EQ_Character__GetFocusRangeModifier_x                      0x42D730
#define EQ_Character__Max_Endurance_x                              0x592080
#define EQ_Character__Max_HP_x                                     0x4481A0
#define EQ_Character__Max_Mana_x                                   0x591EB0
#define EQ_Character__doCombatAbility_x                            0x58F6E0
#define EQ_Character__UseSkill_x                                   0x45C6C0
#define EQ_Character__GetConLevel_x                                0x584B40
#define EQ_Character__IsExpansionFlag_x                            0x410C10
#define EQ_Character__TotalEffect_x                                0x43A2A0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x565340
#define EQ_Item__CreateItemTagString_x                             0x7E4FF0
#define EQ_Item__IsStackable_x                                     0x7D9160
#define EQ_Item__GetImageNum_x                                     0x7DBE70

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A7500
#define EQ_LoadingS__Array_x                                       0xB64328

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5936E0
#define EQ_PC__GetAltAbilityIndex_x                                0x7ED250
#define EQ_PC__GetCombatAbility_x                                  0x7ED2E0
#define EQ_PC__GetCombatAbilityTimer_x                             0x7ED390
#define EQ_PC__GetItemTimerValue_x                                 0x58D4B0
#define EQ_PC__HasLoreItem_x                                       0x587CE0
#define EQ_PC__AlertInventoryChanged_x                             0x584B10
#define EQ_PC__GetPcZoneClient_x                                   0x5AD0F0
// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E43C0
#define EQItemList__add_item_x                                     0x4E4300
#define EQItemList__delete_item_x                                  0x4E47C0
#define EQItemList__FreeItemList_x                                 0x4E46C0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x487200

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x598B30
#define EQPlayer__dEQPlayer_x                                      0x5A1640
#define EQPlayer__DoAttack_x                                       0x5B2EE0
#define EQPlayer__EQPlayer_x                                       0x5A3A90
#define EQPlayer__SetNameSpriteState_x                             0x59E460
#define EQPlayer__SetNameSpriteTint_x                              0x599E60
#define EQPlayer__IsBodyType_j_x                                   0x8EB8C0
#define EQPlayer__IsTargetable_x                                   0x8EC090

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5A7700
#define EQPlayerManager__GetSpawnByName_x                          0x5A7B60

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56B510
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56B550
#define KeypressHandler__ClearCommandStateArray_x                  0x56B0F0
#define KeypressHandler__HandleKeyDown_x                           0x569A40
#define KeypressHandler__HandleKeyUp_x                             0x569D60
#define KeypressHandler__SaveKeymapping_x                          0x56B1C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6D6A10
#define MapViewMap__SaveEx_x                                       0x6DA2F0

#define PlayerPointManager__GetAltCurrency_x                       0x7FE3F0

// StringTable 
#define StringTable__getString_x                                   0x7FA340

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x591B30

//Doors
#define EQSwitch__UseSwitch_x                                      0x5216C0

//IconCache
#define IconCache__GetIcon_x                                       0x674AF0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x66BB40
#define CContainerMgr__CloseContainer_x                            0x66C350

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x736570

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x55EE20

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B5930
#define EQ_Spell__SpellAffects_x                                   0x4B59D0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B5A00
#define CharacterZoneClient__CalcAffectChange_x                    0x436560
#define CLootWnd__LootAll_x                                        0x6CC590
#define CTargetWnd__GetBuffCaster_x                                0x77BA50
