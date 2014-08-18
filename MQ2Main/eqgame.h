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
#define __ExpectedVersionDate                                     "Jul 24 2014"
#define __ExpectedVersionTime                                     "13:37:04"
#define __ActualVersionDate_x                                      0xA495E8
#define __ActualVersionTime_x                                      0xA495F4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x571360
#define __MemChecker1_x                                            0x833FF0
#define __MemChecker2_x                                            0x608250
#define __MemChecker3_x                                            0x6081A0
#define __MemChecker4_x                                            0x7B8830
#define __EncryptPad0_x                                            0xBB3000
#define __EncryptPad1_x                                            0xD2A700
#define __EncryptPad2_x                                            0xBF9A50
#define __EncryptPad3_x                                            0xBF9650
#define __EncryptPad4_x                                            0xD08550
#define __AC1_x                                                    0x775C75
#define __AC2_x                                                    0x527BA7
#define __AC3_x                                                    0x53C290
#define __AC4_x                                                    0x5423C0
#define __AC5_x                                                    0x54E9F1
#define __AC6_x                                                    0x552532
#define __AC7_x                                                    0x5484CC
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x10DB070
#define DI8__Keyboard_x                                            0x10DB074
#define DI8__Mouse_x                                               0x10DB078
#define __AltTimerReady_x                                          0xF3AB19
#define __Attack_x                                                 0xFCDC1A
#define __Autofire_x                                               0xFCDC1B
#define __BindList_x                                               0xB77840
#define __bCommandEnabled_x                                        0xF38C28
#define __Clicks_x                                                 0xF49760
#define __CommandList_x                                            0xB7B8E0
#define __CurrentMapLabel_x                                        0x10E0CF0
#define __CurrentSocial_x                                          0xB3DA50
#define __DoAbilityList_x                                          0xF7FED0
#define __do_loot_x                                                0x4F0450
#define __DrawHandler_x                                            0x17432AC
#define __GroupCount_x                                             0xF3A1F2

#define __Guilds_x                                                 0xF3FCE0
#define __gWorld_x                                                 0xF3C6AC
#define __HotkeyPage_x                                             0xFC68D0
#define __HWnd_x                                                   0xFD2F78
#define __InChatMode_x                                             0xF4968C
#define __LastTell_x                                               0xF4B5D8
#define __LMouseHeldTime_x                                         0xF497CC
#define __Mouse_x                                                  0x10DB07C
#define __MouseLook_x                                              0xF49726
#define __MouseEventTime_x                                         0xFCE404
#define __NetStatusToggle_x                                        0xF49729
#define __PCNames_x                                                0xF4AC14
#define __RangeAttackReady_x                                       0xF4A8AC
#define __RMouseHeldTime_x                                         0xF497C8
#define __RunWalkState_x                                           0xF49690
#define __ScreenMode_x                                             0xE88BF0
#define __ScreenX_x                                                0xF49644
#define __ScreenY_x                                                0xF49640
#define __ScreenXMax_x                                             0xF49648
#define __ScreenYMax_x                                             0xF4964C
#define __ServerHost_x                                             0xF3A13C
#define __ServerName_x                                             0xF7FE90
#define __ShiftKeyDown_x                                           0xF49D30
#define __ShowNames_x                                              0xF4AAB8
#define __Socials_x                                                0xF7FF90
#define __SubscriptionType_x                                       0x110AA28
#define __TargetAggroHolder_x                                      0x10E2F08
#define __GroupAggro_x                                             0x10E2F48
#define __LoginName_x                                              0xFD1B50
#define __Inviter_x                                                0xFCDB98


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF3C798
#define instEQZoneInfo_x                                           0xF4991C
#define instKeypressHandler_x                                      0xFCE3E8
#define pinstActiveBanker_x                                        0xF3C750
#define pinstActiveCorpse_x                                        0xF3C754
#define pinstActiveGMaster_x                                       0xF3C758
#define pinstActiveMerchant_x                                      0xF3C74C
#define pinstAggroInfo_x                                           0xD4D1D8
#define pinstAltAdvManager_x                                       0xE89CC0
#define pinstAuraMgr_x                                             0xD570A0
#define pinstBandageTarget_x                                       0xF3C738
#define pinstCamActor_x                                            0xE895CC
#define pinstCDBStr_x                                              0xE88B84
#define pinstCDisplay_x                                            0xF3C760
#define pinstCEverQuest_x                                          0x10DB1F4
#define pinstCharData_x                                            0xF3C71C
#define pinstCharSpawn_x                                           0xF3C744
#define pinstControlledMissile_x                                   0xF3C718
#define pinstControlledPlayer_x                                    0xF3C744
#define pinstCSidlManager_x                                        0x17426C0
#define pinstCXWndManager_x                                        0x17426B8
#define instDynamicZone_x                                          0xF494D8
#define pinstDZMember_x                                            0xF495E8
#define pinstDZTimerInfo_x                                         0xF495EC
#define pinstEQItemList_x                                          0xF38E74
#define instEQMisc_x                                               0xB59060
#define pinstEQSoundManager_x                                      0xE89FC0
#define instExpeditionLeader_x                                     0xF49522
#define instExpeditionName_x                                       0xF49562
#define pinstGroup_x                                               0xF3A1EE
#define pinstImeManager_x                                          0x17426C4
#define pinstLocalPlayer_x                                         0xF3C730
#define pinstMercenaryData_x                                       0xFCEA38
#define pinstMercAltAbilities_x                                    0xE89EE0
#define pinstModelPlayer_x                                         0xF3C75C
#define pinstPCData_x                                              0xF3C71C
#define pinstSkillMgr_x                                            0xFCF870
#define pinstSpawnManager_x                                        0xFCF158
#define pinstSpellManager_x                                        0xFCF9B8
#define pinstSpellSets_x                                           0xFC6934
#define pinstStringTable_x                                         0xF3C6C4
#define pinstSwitchManager_x                                       0xF39D80
#define pinstTarget_x                                              0xF3C748
#define pinstTargetObject_x                                        0xF3C720
#define pinstTargetSwitch_x                                        0xF3C724
#define pinstTaskMember_x                                          0xE88AD0
#define pinstTrackTarget_x                                         0xF3C73C
#define pinstTradeTarget_x                                         0xF3C72C
#define instTributeActive_x                                        0xB59085
#define pinstViewActor_x                                           0xE895C8
#define pinstWorldData_x                                           0xF3C700


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD4D6B8
#define pinstCAudioTriggersWindow_x                                0xD4D548
#define pinstCCharacterSelect_x                                    0xE89474
#define pinstCFacePick_x                                           0xE89224
#define pinstCNoteWnd_x                                            0xE8942C
#define pinstCBookWnd_x                                            0xE89434
#define pinstCPetInfoWnd_x                                         0xE89438
#define pinstCTrainWnd_x                                           0xE8943C
#define pinstCSkillsWnd_x                                          0xE89440
#define pinstCSkillsSelectWnd_x                                    0xE89444
#define pinstCCombatSkillSelectWnd_x                               0xE89448
#define pinstCFriendsWnd_x                                         0xE8944C
#define pinstCAuraWnd_x                                            0xE89450
#define pinstCRespawnWnd_x                                         0xE89454
#define pinstCBandolierWnd_x                                       0xE89458
#define pinstCPotionBeltWnd_x                                      0xE8945C
#define pinstCAAWnd_x                                              0xE89460
#define pinstCGroupSearchFiltersWnd_x                              0xE89464
#define pinstCLoadskinWnd_x                                        0xE89468
#define pinstCAlarmWnd_x                                           0xE8946C
#define pinstCMusicPlayerWnd_x                                     0xE89470
#define pinstCMailWnd_x                                            0xE89478
#define pinstCMailCompositionWnd_x                                 0xE8947C
#define pinstCMailAddressBookWnd_x                                 0xE89480
#define pinstCRaidWnd_x                                            0xE89488
#define pinstCRaidOptionsWnd_x                                     0xE8948C
#define pinstCBreathWnd_x                                          0xE89490
#define pinstCMapViewWnd_x                                         0xE89494
#define pinstCMapToolbarWnd_x                                      0xE89498
#define pinstCEditLabelWnd_x                                       0xE8949C
#define pinstCTargetWnd_x                                          0xE894A0
#define pinstCColorPickerWnd_x                                     0xE894A4
#define pinstCPlayerWnd_x                                          0xE894A8
#define pinstCOptionsWnd_x                                         0xE894AC
#define pinstCBuffWindowNORMAL_x                                   0xE894B0
#define pinstCBuffWindowSHORT_x                                    0xE894B4
#define pinstCharacterCreation_x                                   0xE894B8
#define pinstCCursorAttachment_x                                   0xE894BC
#define pinstCCastingWnd_x                                         0xE894C0
#define pinstCCastSpellWnd_x                                       0xE894C4
#define pinstCSpellBookWnd_x                                       0xE894C8
#define pinstCInventoryWnd_x                                       0xE894CC
#define pinstCBankWnd_x                                            0xE894D0
#define pinstCQuantityWnd_x                                        0xE894D4
#define pinstCLootWnd_x                                            0xE894D8
#define pinstCActionsWnd_x                                         0xE894DC
#define pinstCCombatAbilityWnd_x                                   0xE894E0
#define pinstCMerchantWnd_x                                        0xE894E4
#define pinstCTradeWnd_x                                           0xE894E8
#define pinstCSelectorWnd_x                                        0xE894EC
#define pinstCBazaarWnd_x                                          0xE894F0
#define pinstCBazaarSearchWnd_x                                    0xE894F4
#define pinstCGiveWnd_x                                            0xE89510
#define pinstCTrackingWnd_x                                        0xE89518
#define pinstCInspectWnd_x                                         0xE8951C
#define pinstCSocialEditWnd_x                                      0xE89520
#define pinstCFeedbackWnd_x                                        0xE89524
#define pinstCBugReportWnd_x                                       0xE89528
#define pinstCVideoModesWnd_x                                      0xE8952C
#define pinstCTextEntryWnd_x                                       0xE89534
#define pinstCFileSelectionWnd_x                                   0xE89538
#define pinstCCompassWnd_x                                         0xE8953C
#define pinstCPlayerNotesWnd_x                                     0xE89540
#define pinstCGemsGameWnd_x                                        0xE89544
#define pinstCTimeLeftWnd_x                                        0xE89548
#define pinstCPetitionQWnd_x                                       0xE8955C
#define pinstCSoulmarkWnd_x                                        0xE89560
#define pinstCStoryWnd_x                                           0xE89564
#define pinstCJournalTextWnd_x                                     0xE89568
#define pinstCJournalCatWnd_x                                      0xE8956C
#define pinstCBodyTintWnd_x                                        0xE89570
#define pinstCServerListWnd_x                                      0xE89574
#define pinstCAvaZoneWnd_x                                         0xE89580
#define pinstCBlockedBuffWnd_x                                     0xE89584
#define pinstCBlockedPetBuffWnd_x                                  0xE89588
#define pinstCInvSlotMgr_x                                         0xE895C0
#define pinstCContainerMgr_x                                       0xE895C4
#define pinstCAdventureLeaderboardWnd_x                            0x10DBDC8
#define pinstCAdventureRequestWnd_x                                0x10DBE40
#define pinstCAltStorageWnd_x                                      0x10DC120
#define pinstCAdventureStatsWnd_x                                  0x10DBEB8
#define pinstCBarterMerchantWnd_x                                  0x10DCD08
#define pinstCBarterSearchWnd_x                                    0x10DCD80
#define pinstCBarterWnd_x                                          0x10DCDF8
#define pinstCChatManager_x                                        0x10DD488
#define pinstCDynamicZoneWnd_x                                     0x10DD938
#define pinstCEQMainWnd_x                                          0x10DDAD0
#define pinstCFellowshipWnd_x                                      0x10DD8CC
#define pinstCFindLocationWnd_x                                    0x10DDDA0
#define pinstCGroupSearchWnd_x                                     0x10DE070
#define pinstCGroupWnd_x                                           0x10DE0E8
#define pinstCGuildBankWnd_x                                       0x10DE160
#define pinstCGuildMgmtWnd_x                                       0x10E0250
#define pinstCHotButtonWnd_x                                       0x10E031C
#define pinstCHotButtonWnd1_x                                      0x10E031C
#define pinstCHotButtonWnd2_x                                      0x10E0320
#define pinstCHotButtonWnd3_x                                      0x10E0324
#define pinstCHotButtonWnd4_x                                      0x10E0348
#define pinstCItemDisplayManager_x                                 0x10E0640
#define pinstCItemExpTransferWnd_x                                 0x10E06BC
#define pinstCLFGuildWnd_x                                         0x10E0998
#define pinstCMIZoneSelectWnd_x                                    0x10E0F80
#define pinstCConfirmationDialog_x                                 0x10E1688
#define pinstCPopupWndManager_x                                    0x10E1688
#define pinstCProgressionSelectionWnd_x                            0x10E1778
#define pinstCPvPStatsWnd_x                                        0x10E1868
#define pinstCSystemInfoDialogBox_x                                0x10E1F70
#define pinstCTaskWnd_x                                            0x10E3308
#define pinstCTaskTemplateSelectWnd_x                              0x10E3290
#define pinstCTipWndOFDAY_x                                        0x10E3560
#define pinstCTipWndCONTEXT_x                                      0x10E3564
#define pinstCTitleWnd_x                                           0x10E35E0
#define pinstCContextMenuManager_x                                 0x17422D4
#define pinstCVoiceMacroWnd_x                                      0xFD0020
#define pinstCHtmlWnd_x                                            0xFD0118
#define pinstIconCache_x                                           0x10DDAA4
#define pinstCTradeskillWnd_x                                      0x10E36E0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x507190
#define __ConvertItemTags_x                                        0x4F5110
#define __ExecuteCmd_x                                             0x4DFD40
#define __EQGetTime_x                                              0x834B50
#define __get_melee_range_x                                        0x4E6980
#define __GetGaugeValueFromEQ_x                                    0x7749D0
#define __GetLabelFromEQ_x                                         0x775C00
#define __GetXTargetType_x                                         0x8F2130
#define __LoadFrontEnd_x                                           0x607900
#define __NewUIINI_x                                               0x774310
#define __ProcessGameEvents_x                                      0x54A610
#define CrashDetected_x                                            0x6093D0
#define DrawNetStatus_x                                            0x580CA0
#define Util__FastTime_x                                           0x833E60
#define Expansion_HoT_x                                            0xF4AA18
#define __HelpPath_x                                               0xFCE170
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A56A0
#define AltAdvManager__IsAbilityReady_x                            0x4A5710
#define AltAdvManager__GetAltAbility_x                             0x4A5AD0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4527A0
#define CharacterZoneClient__MakeMeVisible_x                       0x457740

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x637680

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x645B00

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x560D00

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x660960
#define CChatManager__InitContextMenu_x                            0x661480

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x81AC70
#define CChatService__GetFriendName_x                              0x81AC80

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x666220
#define CChatWindow__Clear_x                                       0x665DD0
#define CChatWindow__WndNotification_x                             0x666750

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8933A0
#define CComboWnd__Draw_x                                          0x893580
#define CComboWnd__GetCurChoice_x                                  0x8931C0
#define CComboWnd__GetListRect_x                                   0x893820
#define CComboWnd__GetTextRect_x                                   0x893400
#define CComboWnd__InsertChoice_x                                  0x893890
#define CComboWnd__SetColors_x                                     0x893150
#define CComboWnd__SetChoice_x                                     0x893180

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x66F8D0
#define CContainerWnd__vftable_x                                   0xA52DB0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x494070
#define CDisplay__GetClickedActor_x                                0x48CCA0
#define CDisplay__GetUserDefinedColor_x                            0x48B560
#define CDisplay__GetWorldFilePath_x                               0x48A960
#define CDisplay__is3dON_x                                         0x489D30
#define CDisplay__ReloadUI_x                                       0x49F440
#define CDisplay__WriteTextHD2_x                                   0x4904E0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8B51A0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8A3DB0
#define CEditWnd__GetCharIndexPt_x                                 0x8A4DC0
#define CEditWnd__GetDisplayString_x                               0x8A3F60
#define CEditWnd__GetHorzOffset_x                                  0x8A42A0
#define CEditWnd__GetLineForPrintableChar_x                        0x8A4890
#define CEditWnd__GetSelStartPt_x                                  0x8A5070
#define CEditWnd__GetSTMLSafeText_x                                0x8A4430
#define CEditWnd__PointFromPrintableChar_x                         0x8A4980
#define CEditWnd__SelectableCharFromPoint_x                        0x8A4B00
#define CEditWnd__SetEditable_x                                    0x8A4400

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x5282F0
#define CEverQuest__DoTellWindow_x                                 0x52DC80
#define CEverQuest__DropHeldItemOnGround_x                         0x536710
#define CEverQuest__dsp_chat_x                                     0x52F420
#define CEverQuest__Emote_x                                        0x52F680
#define CEverQuest__EnterZone_x                                    0x542550
#define CEverQuest__GetBodyTypeDesc_x                              0x524C20
#define CEverQuest__GetClassDesc_x                                 0x52A7F0
#define CEverQuest__GetClassThreeLetterCode_x                      0x52ADF0
#define CEverQuest__GetDeityDesc_x                                 0x525500
#define CEverQuest__GetLangDesc_x                                  0x524FB0
#define CEverQuest__GetRaceDesc_x                                  0x52AFB0
#define CEverQuest__InterpretCmd_x                                 0x52FF60
#define CEverQuest__LeftClickedOnPlayer_x                          0x546940
#define CEverQuest__LMouseUp_x                                     0x548C30
#define CEverQuest__RightClickedOnPlayer_x                         0x547440
#define CEverQuest__RMouseUp_x                                     0x548480
#define CEverQuest__SetGameState_x                                 0x5289A0
#define CEverQuest__UPCNotificationFlush_x                         0x531100

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6802D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x680330
#define CGaugeWnd__Draw_x                                          0x680760

// CGuild
#define CGuild__FindMemberByName_x                                 0x424460

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x69CB00

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6A8890
#define CInvSlotMgr__MoveItem_x                                    0x6A97D0
#define CInvSlotMgr__SelectSlot_x                                  0x6A8940

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6A7BC0
#define CInvSlot__SliderComplete_x                                 0x6A5A10
#define CInvSlot__GetItemBase_x                                    0x6A4E90

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6AA5C0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x771630
#define CItemDisplayWnd__UpdateStrings_x                           0x6AB910

// CLabel 
#define CLabel__Draw_x                                             0x6C6440

// CListWnd 
#define CListWnd__AddColumn_x                                      0x8812B0
#define CListWnd__AddColumn1_x                                     0x880AA0
#define CListWnd__AddLine_x                                        0x880550
#define CListWnd__AddString_x                                      0x880760
#define CListWnd__CalculateFirstVisibleLine_x                      0x87D640
#define CListWnd__CalculateVSBRange_x                              0x87F740
#define CListWnd__ClearAllSel_x                                    0x87C920
#define CListWnd__CloseAndUpdateEditWindow_x                       0x880120
#define CListWnd__Compare_x                                        0x87E120
#define CListWnd__Draw_x                                           0x87F3A0
#define CListWnd__DrawColumnSeparators_x                           0x87F230
#define CListWnd__DrawHeader_x                                     0x87CC30
#define CListWnd__DrawItem_x                                       0x87E770
#define CListWnd__DrawLine_x                                       0x87EED0
#define CListWnd__DrawSeparator_x                                  0x87F2D0
#define CListWnd__EnsureVisible_x                                  0x87D7A0
#define CListWnd__ExtendSel_x                                      0x87E680
#define CListWnd__GetColumnMinWidth_x                              0x87C340
#define CListWnd__GetColumnWidth_x                                 0x87C260
#define CListWnd__GetCurSel_x                                      0x87BB30
#define CListWnd__GetItemAtPoint_x                                 0x87DA30
#define CListWnd__GetItemAtPoint1_x                                0x87DAA0
#define CListWnd__GetItemData_x                                    0x87BD70
#define CListWnd__GetItemHeight_x                                  0x87D2B0
#define CListWnd__GetItemIcon_x                                    0x87BF50
#define CListWnd__GetItemRect_x                                    0x87D870
#define CListWnd__GetItemText_x                                    0x87BE00
#define CListWnd__GetSelList_x                                     0x880990
#define CListWnd__GetSeparatorRect_x                               0x87E050
#define CListWnd__RemoveLine_x                                     0x880940
#define CListWnd__SetColors_x                                      0x87BB90
#define CListWnd__SetColumnJustification_x                         0x87C610
#define CListWnd__SetColumnWidth_x                                 0x87C2F0
#define CListWnd__SetCurSel_x                                      0x87BB70
#define CListWnd__SetItemColor_x                                   0x87FE00
#define CListWnd__SetItemData_x                                    0x87C9D0
#define CListWnd__SetItemText_x                                    0x87FC40
#define CListWnd__ShiftColumnSeparator_x                           0x87FAD0
#define CListWnd__Sort_x                                           0x881410
#define CListWnd__ToggleSel_x                                      0x87C8A0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6DF7D0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7005D0
#define CMerchantWnd__RequestBuyItem_x                             0x706EE0
#define CMerchantWnd__RequestSellItem_x                            0x72E9D0
#define CMerchantWnd__SelectRecoverySlot_x                         0x700880
#define CMerchantWnd__SelectBuySellSlot_x                          0x6FFAE0
#define CMerchantWnd__ActualSelect_x                               0x7042D0

// CObfuscator
#define CObfuscator__doit_x                                        0x7FB2B0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x898B30
#define CSidlManager__CreateLabel_x                                0x767620

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x62E7F0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x62E710
#define CSidlScreenWnd__ConvertToRes_x                             0x8B5080
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8863D0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8878D0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x887980
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x886E50
#define CSidlScreenWnd__DrawSidlPiece_x                            0x885EB0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8855F0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8860A0
#define CSidlScreenWnd__Init1_x                                    0x8875B0
#define CSidlScreenWnd__LoadIniInfo_x                              0x886480
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8857B0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8870A0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8850B0
#define CSidlScreenWnd__StoreIniVis_x                              0x885580
#define CSidlScreenWnd__WndNotification_x                          0x887330
#define CSidlScreenWnd__GetChildItem_x                             0x8856C0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x88C320

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5C9960
#define CSkillMgr__GetSkillCap_x                                   0x5C9B00
#define CSkillMgr__GetNameToken_x                                  0x5C95D0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8BF050
#define CSliderWnd__SetValue_x                                     0x8BF220
#define CSliderWnd__SetNumTicks_x                                  0x8BF9A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x76F2D0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8AF480
#define CStmlWnd__CalculateHSBRange_x                              0x8A79C0
#define CStmlWnd__CalculateVSBRange_x                              0x8A7A50
#define CStmlWnd__CanBreakAtCharacter_x                            0x8A7BD0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8A84B0
#define CStmlWnd__ForceParseNow_x                                  0x8AFDD0
#define CStmlWnd__GetNextTagPiece_x                                0x8A83B0
#define CStmlWnd__GetSTMLText_x                                    0x665670
#define CStmlWnd__GetVisibleText_x                                 0x8A8F00
#define CStmlWnd__InitializeWindowVariables_x                      0x8AB270
#define CStmlWnd__MakeStmlColorTag_x                               0x8A6CC0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8A6D20
#define CStmlWnd__SetSTMLText_x                                    0x8ACAD0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8AF120
#define CStmlWnd__UpdateHistoryString_x                            0x8A9E30

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8B6870
#define CTabWnd__DrawCurrentPage_x                                 0x8B60E0
#define CTabWnd__DrawTab_x                                         0x8B5EB0
#define CTabWnd__GetCurrentPage_x                                  0x8B64B0
#define CTabWnd__GetPageInnerRect_x                                0x8B5BA0
#define CTabWnd__GetTabInnerRect_x                                 0x8B5DA0
#define CTabWnd__GetTabRect_x                                      0x8B5C70
#define CTabWnd__InsertPage_x                                      0x8B6B60
#define CTabWnd__SetPage_x                                         0x8B64E0
#define CTabWnd__SetPageRect_x                                     0x8B67B0
#define CTabWnd__UpdatePage_x                                      0x8B6B00

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4201A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8B28F0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8BBA10

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x879BA0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4116C0
#define CXStr__CXStr1_x                                            0x7B1C90
#define CXStr__CXStr3_x                                            0x830EF0
#define CXStr__dCXStr_x                                            0x467090
#define CXStr__operator_equal_x                                    0x831060
#define CXStr__operator_equal1_x                                   0x8310B0
#define CXStr__operator_plus_equal1_x                              0x832190

// CXWnd 
#define CXWnd__BringToTop_x                                        0x88B510
#define CXWnd__Center_x                                            0x8917F0
#define CXWnd__ClrFocus_x                                          0x88B0E0
#define CXWnd__DoAllDrawing_x                                      0x891440
#define CXWnd__DrawChildren_x                                      0x8915E0
#define CXWnd__DrawColoredRect_x                                   0x88B8D0
#define CXWnd__DrawTooltip_x                                       0x88BB70
#define CXWnd__DrawTooltipAtPoint_x                                0x8903D0
#define CXWnd__GetBorderFrame_x                                    0x88BFE0
#define CXWnd__GetChildWndAt_x                                     0x88F370
#define CXWnd__GetClientClipRect_x                                 0x88BD90
#define CXWnd__GetScreenClipRect_x                                 0x890AC0
#define CXWnd__GetScreenRect_x                                     0x88C1B0
#define CXWnd__GetTooltipRect_x                                    0x88BA00
#define CXWnd__GetWindowTextA_x                                    0x411700
#define CXWnd__IsActive_x                                          0x89EB20
#define CXWnd__IsDescendantOf_x                                    0x88BF20
#define CXWnd__IsReallyVisible_x                                   0x88F350
#define CXWnd__IsType_x                                            0x8B8210
#define CXWnd__Move_x                                              0x88EA30
#define CXWnd__Move1_x                                             0x8910F0
#define CXWnd__ProcessTransition_x                                 0x88B4B0
#define CXWnd__Refade_x                                            0x88B280
#define CXWnd__Resize_x                                            0x88C280
#define CXWnd__Right_x                                             0x8908C0
#define CXWnd__SetFocus_x                                          0x88DB70
#define CXWnd__SetFont_x                                           0x88B130
#define CXWnd__SetKeyTooltip_x                                     0x88C4F0
#define CXWnd__SetMouseOver_x                                      0x890DE0
#define CXWnd__StartFade_x                                         0x88B560
#define CXWnd__GetChildItem_x                                      0x890D30

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8A0430
#define CXWndManager__DrawWindows_x                                0x8A0070
#define CXWndManager__GetKeyboardFlags_x                           0x89E650
#define CXWndManager__HandleKeyboardMsg_x                          0x89EFB0
#define CXWndManager__RemoveWnd_x                                  0x89ECB0

// CDBStr
#define CDBStr__GetString_x                                        0x488130

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8EF150
#define EQ_Character__CastSpell_x                                  0x43C460
#define EQ_Character__Cur_HP_x                                     0x451E60
#define EQ_Character__GetAACastingTimeModifier_x                   0x435530
#define EQ_Character__GetCharInfo2_x                               0x805900
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42D8E0
#define EQ_Character__GetFocusRangeModifier_x                      0x42DAC0
#define EQ_Character__Max_Endurance_x                              0x5928C0
#define EQ_Character__Max_HP_x                                     0x448470
#define EQ_Character__Max_Mana_x                                   0x5926F0
#define EQ_Character__doCombatAbility_x                            0x58FF20
#define EQ_Character__UseSkill_x                                   0x45C9A0
#define EQ_Character__GetConLevel_x                                0x5852B0
#define EQ_Character__IsExpansionFlag_x                            0x410C00
#define EQ_Character__TotalEffect_x                                0x43A590

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x565D30
#define EQ_Item__CreateItemTagString_x                             0x7E6140
#define EQ_Item__IsStackable_x                                     0x7DA640
#define EQ_Item__GetImageNum_x                                     0x7DD270

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A7790
#define EQ_LoadingS__Array_x                                       0xB66688

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x593F20
#define EQ_PC__GetAltAbilityIndex_x                                0x7EE3F0
#define EQ_PC__GetCombatAbility_x                                  0x7EE480
#define EQ_PC__GetCombatAbilityTimer_x                             0x7EE530
#define EQ_PC__GetItemTimerValue_x                                 0x58DD10
#define EQ_PC__HasLoreItem_x                                       0x588450
#define EQ_PC__AlertInventoryChanged_x                             0x585280
#define EQ_PC__GetPcZoneClient_x                                   0x5AE0B0
#define EQ_PC__RemoveMyAffect_x									   0x58D240

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E4940
#define EQItemList__add_item_x                                     0x4E4880
#define EQItemList__delete_item_x                                  0x4E4D40
#define EQItemList__FreeItemList_x                                 0x4E4C40

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x487620

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x599350
#define EQPlayer__dEQPlayer_x                                      0x5A1ED0
#define EQPlayer__DoAttack_x                                       0x5B3EB0
#define EQPlayer__EQPlayer_x                                       0x5A4320
#define EQPlayer__SetNameSpriteState_x                             0x59ECF0
#define EQPlayer__SetNameSpriteTint_x                              0x59A680
#define EQPlayer__IsBodyType_j_x                                   0x8EE400
#define EQPlayer__IsTargetable_x                                   0x8EEC30

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5A8620
#define EQPlayerManager__GetSpawnByName_x                          0x5A8A80

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56BE30
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56BE70
#define KeypressHandler__ClearCommandStateArray_x                  0x56BA10
#define KeypressHandler__HandleKeyDown_x                           0x56A360
#define KeypressHandler__HandleKeyUp_x                             0x56A680
#define KeypressHandler__SaveKeymapping_x                          0x56BAE0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6D7BB0
#define MapViewMap__SaveEx_x                                       0x6DB490

#define PlayerPointManager__GetAltCurrency_x                       0x7FFAC0

// StringTable 
#define StringTable__getString_x                                   0x7FB550

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x592370

//Doors
#define EQSwitch__UseSwitch_x                                      0x522050

//IconCache
#define IconCache__GetIcon_x                                       0x675BE0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x66CC00
#define CContainerMgr__CloseContainer_x                            0x66D410

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x737950

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x55F7E0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B5DB0
#define EQ_Spell__SpellAffects_x                                   0x4B5E50
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B5E80
#define CharacterZoneClient__CalcAffectChange_x                    0x436850
#define CLootWnd__LootAll_x                                        0x6CD740
#define CTargetWnd__GetBuffCaster_x                                0x77CF70
