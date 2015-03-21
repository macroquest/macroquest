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
#define __ExpectedVersionDate                                     "Mar 10 2015"
#define __ExpectedVersionTime                                     "10:32:55"
#define __ActualVersionDate_x                                      0xA57810
#define __ActualVersionTime_x                                      0xA5781C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x573E40
#define __MemChecker1_x                                            0x83C190
#define __MemChecker2_x                                            0x60B700
#define __MemChecker3_x                                            0x60B650
#define __MemChecker4_x                                            0x7BFFC0
#define __EncryptPad0_x                                            0xBC6648
#define __EncryptPad1_x                                            0xD498D8
#define __EncryptPad2_x                                            0xC0F2B8
#define __EncryptPad3_x                                            0xC0EEB8
#define __EncryptPad4_x                                            0xD26000
#define __AC1_x                                                    0x77D645
#define __AC2_x                                                    0x52A427
#define __AC3_x                                                    0x53EB80
#define __AC4_x                                                    0x544EB0
#define __AC5_x                                                    0x550C0E
#define __AC6_x                                                    0x554752
#define __AC7_x                                                    0x54B2FC
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x10FB1F8
#define DI8__Keyboard_x                                            0x10FB1FC
#define DI8__Mouse_x                                               0x10FB200
#define __AltTimerReady_x                                          0xF5ACC1
#define __Attack_x                                                 0xFEDD9B
#define __Autofire_x                                               0xFEDD9C
#define __BindList_x                                               0xB89388
#define __bCommandEnabled_x                                        0xF58DD0
#define __Clicks_x                                                 0xF69908
#define __CommandList_x                                            0xB8D620
#define __CurrentMapLabel_x                                        0x1100C50
#define __CurrentSocial_x                                          0xB4DABC
#define __DoAbilityList_x                                          0xFA0050
#define __do_loot_x                                                0x4F1D20
#define __DrawHandler_x                                            0x176584C
#define __GroupCount_x                                             0xF5A39A

#define __Guilds_x                                                 0xF5FE88
#define __gWorld_x                                                 0xF5C854
#define __HotkeyPage_x                                             0xFE6A50
#define __HWnd_x                                                   0xFF3100
#define __InChatMode_x                                             0xF69834
#define __LastTell_x                                               0xF6B758
#define __LMouseHeldTime_x                                         0xF69974
#define __Mouse_x                                                  0x10FB204
#define __MouseLook_x                                              0xF698CE
#define __MouseEventTime_x                                         0xFEE58C
#define __NetStatusToggle_x                                        0xF698D1
#define __PCNames_x                                                0xF6AD88
#define __RangeAttackReady_x                                       0xF6AA58
#define __RMouseHeldTime_x                                         0xF69970
#define __RunWalkState_x                                           0xF69838
#define __ScreenMode_x                                             0xEA8D90
#define __ScreenX_x                                                0xF697EC
#define __ScreenY_x                                                0xF697E8
#define __ScreenXMax_x                                             0xF697F0
#define __ScreenYMax_x                                             0xF697F4
#define __ServerHost_x                                             0xF5A2E4
#define __ServerName_x                                             0xFA0010
#define __ShiftKeyDown_x                                           0xF69EDC
#define __ShowNames_x                                              0xF6AC2C
#define __Socials_x                                                0xFA0110
#define __SubscriptionType_x                                       0x112CFE0
#define __TargetAggroHolder_x                                      0x1102E8C
#define __GroupAggro_x                                             0x1102ECC
#define __LoginName_x                                              0xFF1CD8
#define __Inviter_x                                                0xFEDD18


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF5C940
#define instEQZoneInfo_x                                           0xF69AC4
#define instKeypressHandler_x                                      0xFEE570
#define pinstActiveBanker_x                                        0xF5C8F8
#define pinstActiveCorpse_x                                        0xF5C8FC
#define pinstActiveGMaster_x                                       0xF5C900
#define pinstActiveMerchant_x                                      0xF5C8F4
#define pinstAggroInfo_x                                           0xD6D378
#define pinstAltAdvManager_x                                       0xEA9E68
#define pinstAuraMgr_x                                             0xD77240
#define pinstBandageTarget_x                                       0xF5C8E0
#define pinstCamActor_x                                            0xEA9774
#define pinstCDBStr_x                                              0xEA8D24
#define pinstCDisplay_x                                            0xF5C908
#define pinstCEverQuest_x                                          0x10FB378
#define pinstCharData_x                                            0xF5C8C4
#define pinstCharSpawn_x                                           0xF5C8EC
#define pinstControlledMissile_x                                   0xF5C8C0
#define pinstControlledPlayer_x                                    0xF5C8EC
#define pinstCSidlManager_x                                        0x1764C78
#define pinstCXWndManager_x                                        0x1764C70
#define instDynamicZone_x                                          0xF69680
#define pinstDZMember_x                                            0xF69790
#define pinstDZTimerInfo_x                                         0xF69794
#define pinstEQItemList_x                                          0xF5901C
#define instEQMisc_x                                               0xB69E88
#define pinstEQSoundManager_x                                      0xEAA168
#define instExpeditionLeader_x                                     0xF696CA
#define instExpeditionName_x                                       0xF6970A
#define pinstGroup_x                                               0xF5A396
#define pinstImeManager_x                                          0x1764C7C
#define pinstLocalPlayer_x                                         0xF5C8D8
#define pinstMercenaryData_x                                       0xFEEBC0
#define pinstMercAltAbilities_x                                    0xEAA088
#define pinstModelPlayer_x                                         0xF5C904
#define pinstPCData_x                                              0xF5C8C4
#define pinstSkillMgr_x                                            0xFEF9F8
#define pinstSpawnManager_x                                        0xFEF2E0
#define pinstSpellManager_x                                        0xFEFB40
#define pinstSpellSets_x                                           0xFE6AB4
#define pinstStringTable_x                                         0xF5C86C
#define pinstSwitchManager_x                                       0xF59F28
#define pinstTarget_x                                              0xF5C8F0
#define pinstTargetObject_x                                        0xF5C8C8
#define pinstTargetSwitch_x                                        0xF5C8CC
#define pinstTaskMember_x                                          0xEA8C70
#define pinstTrackTarget_x                                         0xF5C8E4
#define pinstTradeTarget_x                                         0xF5C8D4
#define instTributeActive_x                                        0xB69EAD
#define pinstViewActor_x                                           0xEA9770
#define pinstWorldData_x                                           0xF5C8A8


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD6D858
#define pinstCAudioTriggersWindow_x                                0xD6D6E8
#define pinstCCharacterSelect_x                                    0xEA961C
#define pinstCFacePick_x                                           0xEA93CC
#define pinstCNoteWnd_x                                            0xEA95D4
#define pinstCBookWnd_x                                            0xEA95DC
#define pinstCPetInfoWnd_x                                         0xEA95E0
#define pinstCTrainWnd_x                                           0xEA95E4
#define pinstCSkillsWnd_x                                          0xEA95E8
#define pinstCSkillsSelectWnd_x                                    0xEA95EC
#define pinstCCombatSkillSelectWnd_x                               0xEA95F0
#define pinstCFriendsWnd_x                                         0xEA95F4
#define pinstCAuraWnd_x                                            0xEA95F8
#define pinstCRespawnWnd_x                                         0xEA95FC
#define pinstCBandolierWnd_x                                       0xEA9600
#define pinstCPotionBeltWnd_x                                      0xEA9604
#define pinstCAAWnd_x                                              0xEA9608
#define pinstCGroupSearchFiltersWnd_x                              0xEA960C
#define pinstCLoadskinWnd_x                                        0xEA9610
#define pinstCAlarmWnd_x                                           0xEA9614
#define pinstCMusicPlayerWnd_x                                     0xEA9618
#define pinstCMailWnd_x                                            0xEA9620
#define pinstCMailCompositionWnd_x                                 0xEA9624
#define pinstCMailAddressBookWnd_x                                 0xEA9628
#define pinstCRaidWnd_x                                            0xEA9630
#define pinstCRaidOptionsWnd_x                                     0xEA9634
#define pinstCBreathWnd_x                                          0xEA9638
#define pinstCMapViewWnd_x                                         0xEA963C
#define pinstCMapToolbarWnd_x                                      0xEA9640
#define pinstCEditLabelWnd_x                                       0xEA9644
#define pinstCTargetWnd_x                                          0xEA9648
#define pinstCColorPickerWnd_x                                     0xEA964C
#define pinstCPlayerWnd_x                                          0xEA9650
#define pinstCOptionsWnd_x                                         0xEA9654
#define pinstCBuffWindowNORMAL_x                                   0xEA9658
#define pinstCBuffWindowSHORT_x                                    0xEA965C
#define pinstCharacterCreation_x                                   0xEA9660
#define pinstCCursorAttachment_x                                   0xEA9664
#define pinstCCastingWnd_x                                         0xEA9668
#define pinstCCastSpellWnd_x                                       0xEA966C
#define pinstCSpellBookWnd_x                                       0xEA9670
#define pinstCInventoryWnd_x                                       0xEA9674
#define pinstCBankWnd_x                                            0xEA9678
#define pinstCQuantityWnd_x                                        0xEA967C
#define pinstCLootWnd_x                                            0xEA9680
#define pinstCActionsWnd_x                                         0xEA9684
#define pinstCCombatAbilityWnd_x                                   0xEA9688
#define pinstCMerchantWnd_x                                        0xEA968C
#define pinstCTradeWnd_x                                           0xEA9690
#define pinstCSelectorWnd_x                                        0xEA9694
#define pinstCBazaarWnd_x                                          0xEA9698
#define pinstCBazaarSearchWnd_x                                    0xEA969C
#define pinstCGiveWnd_x                                            0xEA96B8
#define pinstCTrackingWnd_x                                        0xEA96C0
#define pinstCInspectWnd_x                                         0xEA96C4
#define pinstCSocialEditWnd_x                                      0xEA96C8
#define pinstCFeedbackWnd_x                                        0xEA96CC
#define pinstCBugReportWnd_x                                       0xEA96D0
#define pinstCVideoModesWnd_x                                      0xEA96D4
#define pinstCTextEntryWnd_x                                       0xEA96DC
#define pinstCFileSelectionWnd_x                                   0xEA96E0
#define pinstCCompassWnd_x                                         0xEA96E4
#define pinstCPlayerNotesWnd_x                                     0xEA96E8
#define pinstCGemsGameWnd_x                                        0xEA96EC
#define pinstCTimeLeftWnd_x                                        0xEA96F0
#define pinstCPetitionQWnd_x                                       0xEA9704
#define pinstCSoulmarkWnd_x                                        0xEA9708
#define pinstCStoryWnd_x                                           0xEA970C
#define pinstCJournalTextWnd_x                                     0xEA9710
#define pinstCJournalCatWnd_x                                      0xEA9714
#define pinstCBodyTintWnd_x                                        0xEA9718
#define pinstCServerListWnd_x                                      0xEA971C
#define pinstCAvaZoneWnd_x                                         0xEA9728
#define pinstCBlockedBuffWnd_x                                     0xEA972C
#define pinstCBlockedPetBuffWnd_x                                  0xEA9730
#define pinstCInvSlotMgr_x                                         0xEA9768
#define pinstCContainerMgr_x                                       0xEA976C
#define pinstCAdventureLeaderboardWnd_x                            0x10FBD28
#define pinstCAdventureRequestWnd_x                                0x10FBDA0
#define pinstCAltStorageWnd_x                                      0x10FC080
#define pinstCAdventureStatsWnd_x                                  0x10FBE18
#define pinstCBarterMerchantWnd_x                                  0x10FCC68
#define pinstCBarterSearchWnd_x                                    0x10FCCE0
#define pinstCBarterWnd_x                                          0x10FCD58
#define pinstCChatManager_x                                        0x10FD3E8
#define pinstCDynamicZoneWnd_x                                     0x10FD898
#define pinstCEQMainWnd_x                                          0x10FDA30
#define pinstCFellowshipWnd_x                                      0x10FD82C
#define pinstCFindLocationWnd_x                                    0x10FDD00
#define pinstCGroupSearchWnd_x                                     0x10FDFD0
#define pinstCGroupWnd_x                                           0x10FE048
#define pinstCGuildBankWnd_x                                       0x10FE0C0
#define pinstCGuildMgmtWnd_x                                       0x11001B0
#define pinstCHotButtonWnd_x                                       0x110027C
#define pinstCHotButtonWnd1_x                                      0x110027C
#define pinstCHotButtonWnd2_x                                      0x1100280
#define pinstCHotButtonWnd3_x                                      0x1100284
#define pinstCHotButtonWnd4_x                                      0x11002A8
#define pinstCItemDisplayManager_x                                 0x11005A0
#define pinstCItemExpTransferWnd_x                                 0x110061C
#define pinstCLFGuildWnd_x                                         0x11008F8
#define pinstCMIZoneSelectWnd_x                                    0x1100EE0
#define pinstCConfirmationDialog_x                                 0x11015E8
#define pinstCPopupWndManager_x                                    0x11015E8
#define pinstCProgressionSelectionWnd_x                            0x11016D8
#define pinstCPvPStatsWnd_x                                        0x11017C8
#define pinstCSystemInfoDialogBox_x                                0x1101ED0
#define pinstCTaskWnd_x                                            0x1103298
#define pinstCTaskSomething_x                                      0xD77818
#define pinstCTaskTemplateSelectWnd_x                              0x1103220
#define pinstCTipWndOFDAY_x                                        0x11034F0
#define pinstCTipWndCONTEXT_x                                      0x11034F4
#define pinstCTitleWnd_x                                           0x1103570
#define pinstCContextMenuManager_x                                 0x176488C
#define pinstCVoiceMacroWnd_x                                      0xFF01A8
#define pinstCHtmlWnd_x                                            0xFF02A0
#define pinstIconCache_x                                           0x10FDA04
#define pinstCTradeskillWnd_x                                      0x1103670

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x509690
#define __ConvertItemTags_x                                        0x4F6910
#define __ExecuteCmd_x                                             0x4E1520
#define __EQGetTime_x                                              0x83CCF0
#define __get_melee_range_x                                        0x4E81E0
#define __GetGaugeValueFromEQ_x                                    0x77C390
#define __GetLabelFromEQ_x                                         0x77D5D0
#define __ToggleMount_x                                            0x6A5E30
#define __GetXTargetType_x                                         0x8FA5B0
#define __LoadFrontEnd_x                                           0x60ADB0
#define __NewUIINI_x                                               0x77BC90
#define __ProcessGameEvents_x                                      0x54D060
#define __ProcessMouseEvent_x                                      0x54C800
#define CrashDetected_x                                            0x60C880
#define wwsCrashReportCheckForUploader_x                           0x7D13E0
#define DrawNetStatus_x                                            0x583AC0
#define Util__FastTime_x                                           0x83C000
#define Expansion_HoT_x                                            0xF6ABC4
#define __HelpPath_x                                               0xFEE2F8

//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A5D20
#define AltAdvManager__IsAbilityReady_x                            0x4A5D90
#define AltAdvManager__GetAltAbility_x                             0x4A6150

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x452C50
#define CharacterZoneClient__MakeMeVisible_x                       0x457D10
// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x63A570

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x648420

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x562FD0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6639F0
#define CChatManager__InitContextMenu_x                            0x664510

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x88BE20
#define CContextMenu__dCContextMenu_x                              0x88C030
#define CContextMenu__AddMenuItem_x                                0x88C040
#define CContextMenu__RemoveMenuItem_x                             0x88C330
#define CContextMenu__RemoveAllMenuItems_x                         0x88C350
#define CContextMenuManager__AddMenu_x                             0x892540
#define CContextMenuManager__RemoveMenu_x                          0x892890
#define CContextMenuManager__PopupMenu_x                           0x892CE0
#define CContextMenuManager__Flush_x                               0x8925B0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x822D10
#define CChatService__GetFriendName_x                              0x822D20

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x669350
#define CChatWindow__Clear_x                                       0x668F10
#define CChatWindow__WndNotification_x                             0x669890

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x89B660
#define CComboWnd__Draw_x                                          0x89B860
#define CComboWnd__GetCurChoice_x                                  0x89B480
#define CComboWnd__GetListRect_x                                   0x89BB00
#define CComboWnd__GetTextRect_x                                   0x89B6C0
#define CComboWnd__InsertChoice_x                                  0x89BB70
#define CComboWnd__SetColors_x                                     0x89B410
#define CComboWnd__SetChoice_x                                     0x89B440

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x672B00
#define CContainerWnd__vftable_x                                   0xA60F88

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4947D0
#define CDisplay__GetClickedActor_x                                0x48D360
#define CDisplay__GetUserDefinedColor_x                            0x48BC20
#define CDisplay__GetWorldFilePath_x                               0x48B070
#define CDisplay__is3dON_x                                         0x48A440
#define CDisplay__ReloadUI_x                                       0x49FA50
#define CDisplay__WriteTextHD2_x                                   0x490B70

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8BD3E0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8ABF90
#define CEditWnd__GetCharIndexPt_x                                 0x8ACFC0
#define CEditWnd__GetDisplayString_x                               0x8AC140
#define CEditWnd__GetHorzOffset_x                                  0x8AC480
#define CEditWnd__GetLineForPrintableChar_x                        0x8ACA80
#define CEditWnd__GetSelStartPt_x                                  0x8AD280
#define CEditWnd__GetSTMLSafeText_x                                0x8AC620
#define CEditWnd__PointFromPrintableChar_x                         0x8ACB70
#define CEditWnd__SelectableCharFromPoint_x                        0x8ACCF0
#define CEditWnd__SetEditable_x                                    0x8AC5F0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x52AB70
#define CEverQuest__DoTellWindow_x                                 0x530570
#define CEverQuest__DropHeldItemOnGround_x                         0x539000
#define CEverQuest__dsp_chat_x                                     0x531D10
#define CEverQuest__Emote_x                                        0x531F70
#define CEverQuest__EnterZone_x                                    0x5456D0
#define CEverQuest__GetBodyTypeDesc_x                              0x5274A0
#define CEverQuest__GetClassDesc_x                                 0x52D0E0
#define CEverQuest__GetClassThreeLetterCode_x                      0x52D6E0
#define CEverQuest__GetDeityDesc_x                                 0x527D80
#define CEverQuest__GetLangDesc_x                                  0x527830
#define CEverQuest__GetRaceDesc_x                                  0x52D8A0
#define CEverQuest__InterpretCmd_x                                 0x532850
#define CEverQuest__LeftClickedOnPlayer_x                          0x549760
#define CEverQuest__LMouseUp_x                                     0x54B850
#define CEverQuest__RightClickedOnPlayer_x                         0x54A260
#define CEverQuest__RMouseUp_x                                     0x54B2B0
#define CEverQuest__SetGameState_x                                 0x52B220
#define CEverQuest__UPCNotificationFlush_x                         0x5339F0
#define CEverQuest__IssuePetCommand_x                              0x533550

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x683700
#define CGaugeWnd__CalcLinesFillRect_x                             0x683760
#define CGaugeWnd__Draw_x                                          0x683B90

// CGuild
#define CGuild__FindMemberByName_x                                 0x4245D0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6A08A0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6AE680
#define CInvSlotMgr__MoveItem_x                                    0x6AF5C0
#define CInvSlotMgr__SelectSlot_x                                  0x6AE730

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6ADB20
#define CInvSlot__SliderComplete_x                                 0x6AB4E0
#define CInvSlot__GetItemBase_x                                    0x6AA950

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6B0740

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x778E80
#define CItemDisplayWnd__UpdateStrings_x                           0x6B1A70

// CLabel 
#define CLabel__Draw_x                                             0x6CC790

// CListWnd
#define CListWnd__CListWnd_x                                       0x8884D0
#define CListWnd__dCListWnd_x                                      0x889550
#define CListWnd__AddColumn_x                                      0x8894F0
#define CListWnd__AddColumn1_x                                     0x888CE0
#define CListWnd__AddLine_x                                        0x888790
#define CListWnd__AddString_x                                      0x8889A0
#define CListWnd__CalculateFirstVisibleLine_x                      0x885820
#define CListWnd__CalculateVSBRange_x                              0x887990
#define CListWnd__ClearAllSel_x                                    0x884AE0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x888360
#define CListWnd__Compare_x                                        0x886310
#define CListWnd__Draw_x                                           0x8875A0
#define CListWnd__DrawColumnSeparators_x                           0x887430
#define CListWnd__DrawHeader_x                                     0x884DF0
#define CListWnd__DrawItem_x                                       0x886960
#define CListWnd__DrawLine_x                                       0x8870D0
#define CListWnd__DrawSeparator_x                                  0x8874D0
#define CListWnd__EnsureVisible_x                                  0x885980
#define CListWnd__ExtendSel_x                                      0x886870
#define CListWnd__GetColumnMinWidth_x                              0x884500
#define CListWnd__GetColumnWidth_x                                 0x884420
#define CListWnd__GetCurSel_x                                      0x883BF0
#define CListWnd__GetItemAtPoint_x                                 0x885C20
#define CListWnd__GetItemAtPoint1_x                                0x885C90
#define CListWnd__GetItemData_x                                    0x883F30
#define CListWnd__GetItemHeight_x                                  0x885480
#define CListWnd__GetItemIcon_x                                    0x884110
#define CListWnd__GetItemRect_x                                    0x885A60
#define CListWnd__GetItemText_x                                    0x883FC0
#define CListWnd__GetSelList_x                                     0x888BD0
#define CListWnd__GetSeparatorRect_x                               0x886240
#define CListWnd__RemoveLine_x                                     0x888B80
#define CListWnd__SetColors_x                                      0x883D40
#define CListWnd__SetColumnJustification_x                         0x8847D0
#define CListWnd__SetColumnWidth_x                                 0x8844B0
#define CListWnd__SetCurSel_x                                      0x883C30
#define CListWnd__SetItemColor_x                                   0x888040
#define CListWnd__SetItemData_x                                    0x884B90
#define CListWnd__SetItemText_x                                    0x887E80
#define CListWnd__ShiftColumnSeparator_x                           0x887D10
#define CListWnd__Sort_x                                           0x889650
#define CListWnd__ToggleSel_x                                      0x884A60

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6E5D50

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x706F40
#define CMerchantWnd__RequestBuyItem_x                             0x70DDB0
#define CMerchantWnd__RequestSellItem_x                            0x70E820
#define CMerchantWnd__SelectRecoverySlot_x                         0x7071F0
#define CMerchantWnd__SelectBuySellSlot_x                          0x706450
#define CMerchantWnd__ActualSelect_x                               0x70ACD0

// CObfuscator
#define CObfuscator__doit_x                                        0x802FF0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8A0DD0
#define CSidlManager__CreateLabel_x                                0x76EE20

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x6317A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x631680
#define CSidlScreenWnd__ConvertToRes_x                             0x8BD2C0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x88E610
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x88FB20
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x88FBD0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x88F0A0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x88E0F0
#define CSidlScreenWnd__EnableIniStorage_x                         0x88D840
#define CSidlScreenWnd__GetSidlPiece_x                             0x88E2E0
#define CSidlScreenWnd__Init1_x                                    0x88F800
#define CSidlScreenWnd__LoadIniInfo_x                              0x88E6C0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x88DA00
#define CSidlScreenWnd__LoadSidlScreen_x                           0x88F2F0
#define CSidlScreenWnd__StoreIniInfo_x                             0x88D300
#define CSidlScreenWnd__StoreIniVis_x                              0x88D7D0
#define CSidlScreenWnd__WndNotification_x                          0x88F580
#define CSidlScreenWnd__GetChildItem_x                             0x88D910
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8944B0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5CCDC0
#define CSkillMgr__GetSkillCap_x                                   0x5CCF60
#define CSkillMgr__GetNameToken_x                                  0x5CCA30

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8C7380
#define CSliderWnd__SetValue_x                                     0x8C7550
#define CSliderWnd__SetNumTicks_x                                  0x8C7CD0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x776B20

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8B76B0
#define CStmlWnd__CalculateHSBRange_x                              0x8AFBE0
#define CStmlWnd__CalculateVSBRange_x                              0x8AFC70
#define CStmlWnd__CanBreakAtCharacter_x                            0x8AFDF0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8B06D0
#define CStmlWnd__ForceParseNow_x                                  0x8B8000
#define CStmlWnd__GetNextTagPiece_x                                0x8B05D0
#define CStmlWnd__GetSTMLText_x                                    0x6687B0
#define CStmlWnd__GetVisibleText_x                                 0x8B1120
#define CStmlWnd__InitializeWindowVariables_x                      0x8B3490
#define CStmlWnd__MakeStmlColorTag_x                               0x8AEEE0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8AEF40
#define CStmlWnd__SetSTMLText_x                                    0x8B4CF0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8B7350
#define CStmlWnd__UpdateHistoryString_x                            0x8B2050

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8BEAC0
#define CTabWnd__DrawCurrentPage_x                                 0x8BE330
#define CTabWnd__DrawTab_x                                         0x8BE0F0
#define CTabWnd__GetCurrentPage_x                                  0x8BE700
#define CTabWnd__GetPageInnerRect_x                                0x8BDDE0
#define CTabWnd__GetTabInnerRect_x                                 0x8BDFE0
#define CTabWnd__GetTabRect_x                                      0x8BDEB0
#define CTabWnd__InsertPage_x                                      0x8BEDB0
#define CTabWnd__SetPage_x                                         0x8BE730
#define CTabWnd__SetPageRect_x                                     0x8BEA00
#define CTabWnd__UpdatePage_x                                      0x8BED50

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4203A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8BAB20

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8C3D40

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x881D10

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x570540
#define CXStr__CXStr1_x                                            0x718A00
#define CXStr__CXStr3_x                                            0x839090
#define CXStr__dCXStr_x                                            0x718A10
#define CXStr__operator_equal_x                                    0x839200
#define CXStr__operator_equal1_x                                   0x839250
#define CXStr__operator_plus_equal1_x                              0x83A330

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8936F0
#define CXWnd__Center_x                                            0x899950
#define CXWnd__ClrFocus_x                                          0x8932E0
#define CXWnd__DoAllDrawing_x                                      0x899580
#define CXWnd__DrawChildren_x                                      0x899730
#define CXWnd__DrawColoredRect_x                                   0x893A80
#define CXWnd__DrawTooltip_x                                       0x893D20
#define CXWnd__DrawTooltipAtPoint_x                                0x8984E0
#define CXWnd__GetBorderFrame_x                                    0x894170
#define CXWnd__GetChildWndAt_x                                     0x89A310
#define CXWnd__GetClientClipRect_x                                 0x893F40
#define CXWnd__GetScreenClipRect_x                                 0x898BE0
#define CXWnd__GetScreenRect_x                                     0x894340
#define CXWnd__GetTooltipRect_x                                    0x893BB0
#define CXWnd__GetWindowTextA_x                                    0x4118B0
#define CXWnd__IsActive_x                                          0x8A6DD0
#define CXWnd__IsDescendantOf_x                                    0x8940B0
#define CXWnd__IsReallyVisible_x                                   0x8974F0
#define CXWnd__IsType_x                                            0x8C0470
#define CXWnd__Move_x                                              0x896BE0
#define CXWnd__Move1_x                                             0x899220
#define CXWnd__ProcessTransition_x                                 0x8936A0
#define CXWnd__Refade_x                                            0x893470
#define CXWnd__Resize_x                                            0x894410
#define CXWnd__Right_x                                             0x8989E0
#define CXWnd__SetFocus_x                                          0x895D10
#define CXWnd__SetFont_x                                           0x893330
#define CXWnd__SetKeyTooltip_x                                     0x894680
#define CXWnd__SetMouseOver_x                                      0x898F10
#define CXWnd__StartFade_x                                         0x893740
#define CXWnd__GetChildItem_x                                      0x898E60

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8A8710
#define CXWndManager__DrawWindows_x                                0x8A8350
#define CXWndManager__GetKeyboardFlags_x                           0x8A6900
#define CXWndManager__HandleKeyboardMsg_x                          0x8A7270
#define CXWndManager__RemoveWnd_x                                  0x8A6F60

// CDBStr
#define CDBStr__GetString_x                                        0x488850

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x43C620
#define EQ_Character__Cur_HP_x                                     0x452320
#define EQ_Character__GetAACastingTimeModifier_x                   0x435720
#define EQ_Character__GetCharInfo2_x                               0x80D700
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42D9F0
#define EQ_Character__GetFocusRangeModifier_x                      0x42DBD0
#define EQ_Character__Max_Endurance_x                              0x595800
#define EQ_Character__Max_HP_x                                     0x448600
#define EQ_Character__Max_Mana_x                                   0x595630
#define EQ_Character__doCombatAbility_x                            0x592C20
#define EQ_Character__UseSkill_x                                   0x45CE50
#define EQ_Character__GetConLevel_x                                0x588100
#define EQ_Character__IsExpansionFlag_x                            0x410E00
#define EQ_Character__TotalEffect_x                                0x43A750

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x568790
#define EQ_Item__CreateItemTagString_x                             0x7EDA30
#define EQ_Item__IsStackable_x                                     0x7E1C60
#define EQ_Item__GetImageNum_x                                     0x7E48F0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A7F00
#define EQ_LoadingS__Array_x                                       0xB779F8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x596FA0
#define EQ_PC__GetAltAbilityIndex_x                                0x7F5D70
#define EQ_PC__GetCombatAbility_x                                  0x7F5E00
#define EQ_PC__GetCombatAbilityTimer_x                             0x7F5EB0
#define EQ_PC__GetItemTimerValue_x                                 0x590A10
#define EQ_PC__HasLoreItem_x                                       0x58B3D0
#define EQ_PC__AlertInventoryChanged_x                             0x5880D0
#define EQ_PC__GetPcZoneClient_x                                   0x5B1370
#define EQ_PC__RemoveMyAffect_x									   0x58FF20

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E61A0
#define EQItemList__add_item_x                                     0x4E60E0
#define EQItemList__delete_item_x                                  0x4E65A0
#define EQItemList__FreeItemList_x                                 0x4E64A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x487AE0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x59C430
#define EQPlayer__dEQPlayer_x                                      0x5A51F0
#define EQPlayer__DoAttack_x                                       0x5B7170
#define EQPlayer__EQPlayer_x                                       0x5A7610
#define EQPlayer__SetNameSpriteState_x                             0x5A1F20
#define EQPlayer__SetNameSpriteTint_x                              0x59D800
#define EQPlayer__IsBodyType_j_x                                   0x8F67C0
#define EQPlayer__IsTargetable_x                                   0x8F7080
#define EQPlayer__CanSee_x                                         0x8F75A0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5AB950
#define EQPlayerManager__GetSpawnByName_x                          0x5ABDB0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56E870
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56E8B0
#define KeypressHandler__ClearCommandStateArray_x                  0x56E450
#define KeypressHandler__HandleKeyDown_x                           0x56CDB0
#define KeypressHandler__HandleKeyUp_x                             0x56D0D0
#define KeypressHandler__SaveKeymapping_x                          0x56E520

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6DE130
#define MapViewMap__SaveEx_x                                       0x6E1A10

#define PlayerPointManager__GetAltCurrency_x                       0x8078E0

// StringTable 
#define StringTable__getString_x                                   0x803290

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5952B0

//Doors
#define EQSwitch__UseSwitch_x                                      0x524840

//IconCache
#define IconCache__GetIcon_x                                       0x678F80

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x66FE10
#define CContainerMgr__CloseContainer_x                            0x670630

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x73F200

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x561A90

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B6480
#define EQ_Spell__SpellAffects_x                                   0x4B6520
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B6550
#define CharacterZoneClient__CalcAffectChange_x                    0x436A40
#define CLootWnd__LootAll_x                                        0x6D3AE0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x784900
#define CTargetWnd__WndNotification_x                              0x7843F0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x789AC0
