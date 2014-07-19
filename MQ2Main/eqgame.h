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
#define __ExpectedVersionDate                                     "Jul 16 2014"
#define __ExpectedVersionTime                                     "19:39:08"
#define __ActualVersionDate_x                                      0xA49588
#define __ActualVersionTime_x                                      0xA49594

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5711A0
#define __MemChecker1_x                                            0x833D20
#define __MemChecker2_x                                            0x607FB0
#define __MemChecker3_x                                            0x607F00
#define __MemChecker4_x                                            0x7B8A80
#define __EncryptPad0_x                                            0xBB3000
#define __EncryptPad1_x                                            0xD2A700
#define __EncryptPad2_x                                            0xBF9A50
#define __EncryptPad3_x                                            0xBF9650
#define __EncryptPad4_x                                            0xD08550
#define __AC1_x                                                    0x775B45
#define __AC2_x                                                    0x5279C7
#define __AC3_x                                                    0x53C0B0
#define __AC4_x                                                    0x5421E0
#define __AC5_x                                                    0x54E811
#define __AC6_x                                                    0x552352
#define __AC7_x                                                    0x5482EC
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x10DB070
#define DI8__Keyboard_x                                            0x10DB074
#define DI8__Mouse_x                                               0x10DB078
#define __AltTimerReady_x                                          0xF3AB19
#define __Attack_x                                                 0xFCDC1A
#define __Autofire_x                                               0xFCDC1B
#define __BindList_x                                               0xB77840
#define __Clicks_x                                                 0xF49760
#define __CommandList_x                                            0xB7B8E0
#define __CurrentMapLabel_x                                        0x10E0CF0
#define __CurrentSocial_x                                          0xB3DA50
#define __DoAbilityList_x                                          0xF7FED0
#define __do_loot_x                                                0x4F0230
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
#define __CastRay_x                                                0x506F70
#define __ConvertItemTags_x                                        0x4F4EF0
#define __ExecuteCmd_x                                             0x4DFAE0
#define __EQGetTime_x                                              0x834880
#define __get_melee_range_x                                        0x4E6760
#define __GetGaugeValueFromEQ_x                                    0x7748A0
#define __GetLabelFromEQ_x                                         0x775AD0
#define __GetXTargetType_x                                         0x8F2080
#define __LoadFrontEnd_x                                           0x607660
#define __NewUIINI_x                                               0x7741E0
#define __ProcessGameEvents_x                                      0x54A430
#define CrashDetected_x                                            0x609130
#define DrawNetStatus_x                                            0x5809A0
#define Util__FastTime_x                                           0x833B90
#define Expansion_HoT_x                                            0xF4AA18
#define __HelpPath_x                                               0xFCE170
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A55B0
#define AltAdvManager__IsAbilityReady_x                            0x4A5620
#define AltAdvManager__GetAltAbility_x                             0x4A59E0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x452800
#define CharacterZoneClient__MakeMeVisible_x                       0x4577A0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x637390

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x644FE0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x560B30

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x660530
#define CChatManager__InitContextMenu_x                            0x661050

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x81A950
#define CChatService__GetFriendName_x                              0x81A960

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x665DF0
#define CChatWindow__Clear_x                                       0x6659A0
#define CChatWindow__WndNotification_x                             0x666320

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x893060
#define CComboWnd__Draw_x                                          0x893240
#define CComboWnd__GetCurChoice_x                                  0x892E80
#define CComboWnd__GetListRect_x                                   0x8934E0
#define CComboWnd__GetTextRect_x                                   0x8930C0
#define CComboWnd__InsertChoice_x                                  0x893550
#define CComboWnd__SetColors_x                                     0x892E10
#define CComboWnd__SetChoice_x                                     0x892E40

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x66F4A0
#define CContainerWnd__vftable_x                                   0xA52D50

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x493FA0
#define CDisplay__GetClickedActor_x                                0x48CBD0
#define CDisplay__GetUserDefinedColor_x                            0x48B490
#define CDisplay__GetWorldFilePath_x                               0x48A890
#define CDisplay__is3dON_x                                         0x489C60
#define CDisplay__ReloadUI_x                                       0x49F370
#define CDisplay__WriteTextHD2_x                                   0x490410

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8B4F70

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8A3B70
#define CEditWnd__GetCharIndexPt_x                                 0x8A4B80
#define CEditWnd__GetDisplayString_x                               0x8A3D20
#define CEditWnd__GetHorzOffset_x                                  0x8A4060
#define CEditWnd__GetLineForPrintableChar_x                        0x8A4650
#define CEditWnd__GetSelStartPt_x                                  0x8A4E30
#define CEditWnd__GetSTMLSafeText_x                                0x8A41F0
#define CEditWnd__PointFromPrintableChar_x                         0x8A4740
#define CEditWnd__SelectableCharFromPoint_x                        0x8A48C0
#define CEditWnd__SetEditable_x                                    0x8A41C0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x528110
#define CEverQuest__DoTellWindow_x                                 0x52DAA0
#define CEverQuest__DropHeldItemOnGround_x                         0x536530
#define CEverQuest__dsp_chat_x                                     0x52F240
#define CEverQuest__Emote_x                                        0x52F4A0
#define CEverQuest__EnterZone_x                                    0x542370
#define CEverQuest__GetBodyTypeDesc_x                              0x524A40
#define CEverQuest__GetClassDesc_x                                 0x52A610
#define CEverQuest__GetClassThreeLetterCode_x                      0x52AC10
#define CEverQuest__GetDeityDesc_x                                 0x525320
#define CEverQuest__GetLangDesc_x                                  0x524DD0
#define CEverQuest__GetRaceDesc_x                                  0x52ADD0
#define CEverQuest__InterpretCmd_x                                 0x52FD80
#define CEverQuest__LeftClickedOnPlayer_x                          0x546760
#define CEverQuest__LMouseUp_x                                     0x548A50
#define CEverQuest__RightClickedOnPlayer_x                         0x547260
#define CEverQuest__RMouseUp_x                                     0x5482A0
#define CEverQuest__SetGameState_x                                 0x5287C0
#define CEverQuest__UPCNotificationFlush_x                         0x530F20

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x67FE50
#define CGaugeWnd__CalcLinesFillRect_x                             0x67FEB0
#define CGaugeWnd__Draw_x                                          0x6802E0

// CGuild
#define CGuild__FindMemberByName_x                                 0x424420

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x69C670

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6A8410
#define CInvSlotMgr__MoveItem_x                                    0x6A9350
#define CInvSlotMgr__SelectSlot_x                                  0x6A84C0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6A7740
#define CInvSlot__SliderComplete_x                                 0x6A5590
#define CInvSlot__GetItemBase_x                                    0x6A4A10

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6AA140

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x771500
#define CItemDisplayWnd__UpdateStrings_x                           0x6AB490

// CLabel 
#define CLabel__Draw_x                                             0x6C5FB0

// CListWnd 
#define CListWnd__AddColumn_x                                      0x881010
#define CListWnd__AddColumn1_x                                     0x880800
#define CListWnd__AddLine_x                                        0x8802B0
#define CListWnd__AddString_x                                      0x8804C0
#define CListWnd__CalculateFirstVisibleLine_x                      0x87D3A0
#define CListWnd__CalculateVSBRange_x                              0x87F4A0
#define CListWnd__ClearAllSel_x                                    0x87C680
#define CListWnd__CloseAndUpdateEditWindow_x                       0x87FE80
#define CListWnd__Compare_x                                        0x87DE80
#define CListWnd__Draw_x                                           0x87F100
#define CListWnd__DrawColumnSeparators_x                           0x87EF90
#define CListWnd__DrawHeader_x                                     0x87C990
#define CListWnd__DrawItem_x                                       0x87E4D0
#define CListWnd__DrawLine_x                                       0x87EC30
#define CListWnd__DrawSeparator_x                                  0x87F030
#define CListWnd__EnsureVisible_x                                  0x87D500
#define CListWnd__ExtendSel_x                                      0x87E3E0
#define CListWnd__GetColumnMinWidth_x                              0x87C0A0
#define CListWnd__GetColumnWidth_x                                 0x87BFC0
#define CListWnd__GetCurSel_x                                      0x87B890
#define CListWnd__GetItemAtPoint_x                                 0x87D790
#define CListWnd__GetItemAtPoint1_x                                0x87D800
#define CListWnd__GetItemData_x                                    0x87BAD0
#define CListWnd__GetItemHeight_x                                  0x87D010
#define CListWnd__GetItemIcon_x                                    0x87BCB0
#define CListWnd__GetItemRect_x                                    0x87D5D0
#define CListWnd__GetItemText_x                                    0x87BB60
#define CListWnd__GetSelList_x                                     0x8806F0
#define CListWnd__GetSeparatorRect_x                               0x87DDB0
#define CListWnd__RemoveLine_x                                     0x8806A0
#define CListWnd__SetColors_x                                      0x87B8F0
#define CListWnd__SetColumnJustification_x                         0x87C370
#define CListWnd__SetColumnWidth_x                                 0x87C050
#define CListWnd__SetCurSel_x                                      0x87B8D0
#define CListWnd__SetItemColor_x                                   0x87FB60
#define CListWnd__SetItemData_x                                    0x87C730
#define CListWnd__SetItemText_x                                    0x87F9A0
#define CListWnd__ShiftColumnSeparator_x                           0x87F830
#define CListWnd__Sort_x                                           0x88117D
#define CListWnd__ToggleSel_x                                      0x87C600

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6DF250

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7001B0
#define CMerchantWnd__RequestBuyItem_x                             0x706AC0
#define CMerchantWnd__RequestSellItem_x                            0x72E610
#define CMerchantWnd__SelectRecoverySlot_x                         0x700460
#define CMerchantWnd__SelectBuySellSlot_x                          0x6FF6C0
#define CMerchantWnd__ActualSelect_x                               0x703EB0

// CObfuscator
#define CObfuscator__doit_x                                        0x7FAEE0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8987F0
#define CSidlManager__CreateLabel_x                                0x7674A0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x62E540
#define CSidlScreenWnd__CalculateVSBRange_x                        0x62E460
#define CSidlScreenWnd__ConvertToRes_x                             0x8B4E50
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x886130
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x887630
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8876E0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x886BB0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x885C10
#define CSidlScreenWnd__EnableIniStorage_x                         0x885350
#define CSidlScreenWnd__GetSidlPiece_x                             0x885E00
#define CSidlScreenWnd__Init1_x                                    0x887310
#define CSidlScreenWnd__LoadIniInfo_x                              0x8861E0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x885510
#define CSidlScreenWnd__LoadSidlScreen_x                           0x886E00
#define CSidlScreenWnd__StoreIniInfo_x                             0x884E10
#define CSidlScreenWnd__StoreIniVis_x                              0x8852E0
#define CSidlScreenWnd__WndNotification_x                          0x887090
#define CSidlScreenWnd__GetChildItem_x                             0x885420
#define CSidlScreenWnd__HandleLButtonUp_x                          0x88BFE0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5C97C0
#define CSkillMgr__GetSkillCap_x                                   0x5C9960
#define CSkillMgr__GetNameToken_x                                  0x5C9430

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8BEE50
#define CSliderWnd__SetValue_x                                     0x8BF020
#define CSliderWnd__SetNumTicks_x                                  0x8BF7A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x76F1A0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8AF240
#define CStmlWnd__CalculateHSBRange_x                              0x8A7780
#define CStmlWnd__CalculateVSBRange_x                              0x8A7810
#define CStmlWnd__CanBreakAtCharacter_x                            0x8A7990
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8A8270
#define CStmlWnd__ForceParseNow_x                                  0x8AFB90
#define CStmlWnd__GetNextTagPiece_x                                0x8A8170
#define CStmlWnd__GetSTMLText_x                                    0x665240
#define CStmlWnd__GetVisibleText_x                                 0x8A8CC0
#define CStmlWnd__InitializeWindowVariables_x                      0x8AB030
#define CStmlWnd__MakeStmlColorTag_x                               0x8A6A80
#define CStmlWnd__MakeWndNotificationTag_x                         0x8A6AE0
#define CStmlWnd__SetSTMLText_x                                    0x8AC890
#define CStmlWnd__StripFirstSTMLLines_x                            0x8AEEE0
#define CStmlWnd__UpdateHistoryString_x                            0x8A9BF0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8B6640
#define CTabWnd__DrawCurrentPage_x                                 0x8B5EB0
#define CTabWnd__DrawTab_x                                         0x8B5C80
#define CTabWnd__GetCurrentPage_x                                  0x8B6280
#define CTabWnd__GetPageInnerRect_x                                0x8B5970
#define CTabWnd__GetTabInnerRect_x                                 0x8B5B70
#define CTabWnd__GetTabRect_x                                      0x8B5A40
#define CTabWnd__InsertPage_x                                      0x8B6930
#define CTabWnd__SetPage_x                                         0x8B62B0
#define CTabWnd__SetPageRect_x                                     0x8B6580
#define CTabWnd__UpdatePage_x                                      0x8B68D0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4201A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8B26B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8BB810

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x879890

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x56D8D0
#define CXStr__CXStr1_x                                            0x7A5790
#define CXStr__CXStr3_x                                            0x830C20
#define CXStr__dCXStr_x                                            0x7114E0
#define CXStr__operator_equal_x                                    0x830D90
#define CXStr__operator_equal1_x                                   0x830DE0
#define CXStr__operator_plus_equal1_x                              0x831EC0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x88B1D0
#define CXWnd__Center_x                                            0x8914B0
#define CXWnd__ClrFocus_x                                          0x88ADA0
#define CXWnd__DoAllDrawing_x                                      0x891100
#define CXWnd__DrawChildren_x                                      0x8912A0
#define CXWnd__DrawColoredRect_x                                   0x88B590
#define CXWnd__DrawTooltip_x                                       0x88B830
#define CXWnd__DrawTooltipAtPoint_x                                0x890090
#define CXWnd__GetBorderFrame_x                                    0x88BCA0
#define CXWnd__GetChildWndAt_x                                     0x88F030
#define CXWnd__GetClientClipRect_x                                 0x88BA50
#define CXWnd__GetScreenClipRect_x                                 0x890780
#define CXWnd__GetScreenRect_x                                     0x88BE70
#define CXWnd__GetTooltipRect_x                                    0x88B6C0
#define CXWnd__GetWindowTextA_x                                    0x4116D0
#define CXWnd__IsActive_x                                          0x89E870
#define CXWnd__IsDescendantOf_x                                    0x88BBE0
#define CXWnd__IsReallyVisible_x                                   0x88F010
#define CXWnd__IsType_x                                            0x8B7FE0
#define CXWnd__Move_x                                              0x88E6F0
#define CXWnd__Move1_x                                             0x890DB0
#define CXWnd__ProcessTransition_x                                 0x88B170
#define CXWnd__Refade_x                                            0x88AF40
#define CXWnd__Resize_x                                            0x88BF40
#define CXWnd__Right_x                                             0x890580
#define CXWnd__SetFocus_x                                          0x88D830
#define CXWnd__SetFont_x                                           0x88ADF0
#define CXWnd__SetKeyTooltip_x                                     0x88C1B0
#define CXWnd__SetMouseOver_x                                      0x890AA0
#define CXWnd__StartFade_x                                         0x88B220
#define CXWnd__GetChildItem_x                                      0x8909F0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8A0180
#define CXWndManager__DrawWindows_x                                0x89FDC0
#define CXWndManager__GetKeyboardFlags_x                           0x89E3A0
#define CXWndManager__HandleKeyboardMsg_x                          0x89ED00
#define CXWndManager__RemoveWnd_x                                  0x89EA00

// CDBStr
#define CDBStr__GetString_x                                        0x488080

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8EF0D0
#define EQ_Character__CastSpell_x                                  0x43C470
#define EQ_Character__Cur_HP_x                                     0x451EC0
#define EQ_Character__GetAACastingTimeModifier_x                   0x435540
#define EQ_Character__GetCharInfo2_x                               0x805650
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42D8E0
#define EQ_Character__GetFocusRangeModifier_x                      0x42DAC0
#define EQ_Character__Max_Endurance_x                              0x592750
#define EQ_Character__Max_HP_x                                     0x4484D0
#define EQ_Character__Max_Mana_x                                   0x592580
#define EQ_Character__doCombatAbility_x                            0x58FDB0
#define EQ_Character__UseSkill_x                                   0x45CA00
#define EQ_Character__GetConLevel_x                                0x585000
#define EQ_Character__IsExpansionFlag_x                            0x410C10
#define EQ_Character__TotalEffect_x                                0x43A5A0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x565B50
#define EQ_Item__CreateItemTagString_x                             0x7E5DE0
#define EQ_Item__IsStackable_x                                     0x7DA2E0
#define EQ_Item__GetImageNum_x                                     0x7DCF10

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A76A0
#define EQ_LoadingS__Array_x                                       0xB66688

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x593DB0
#define EQ_PC__GetAltAbilityIndex_x                                0x7EE020
#define EQ_PC__GetCombatAbility_x                                  0x7EE0B0
#define EQ_PC__GetCombatAbilityTimer_x                             0x7EE160
#define EQ_PC__GetItemTimerValue_x                                 0x58DBA0
#define EQ_PC__HasLoreItem_x                                       0x5881A0
#define EQ_PC__AlertInventoryChanged_x                             0x584FD0
#define EQ_PC__GetPcZoneClient_x                                   0x5ADF30
#define EQ_PC__RemoveMyAffect_x									   0x58D0D0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E46E0
#define EQItemList__add_item_x                                     0x4E4620
#define EQItemList__delete_item_x                                  0x4E4AE0
#define EQItemList__FreeItemList_x                                 0x4E49E0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x487590

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5991C0
#define EQPlayer__dEQPlayer_x                                      0x5A1D40
#define EQPlayer__DoAttack_x                                       0x5B3D30
#define EQPlayer__EQPlayer_x                                       0x5A4190
#define EQPlayer__SetNameSpriteState_x                             0x59EB60
#define EQPlayer__SetNameSpriteTint_x                              0x59A4F0
#define EQPlayer__IsBodyType_j_x                                   0x8EE380
#define EQPlayer__IsTargetable_x                                   0x8EEBB0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5A84A0
#define EQPlayerManager__GetSpawnByName_x                          0x5A8900

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56BC00
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56BC40
#define KeypressHandler__ClearCommandStateArray_x                  0x56B7E0
#define KeypressHandler__HandleKeyDown_x                           0x0
#define KeypressHandler__HandleKeyUp_x                             0x56A450
#define KeypressHandler__SaveKeymapping_x                          0x56B8B0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6D7630
#define MapViewMap__SaveEx_x                                       0x6DAF10

#define PlayerPointManager__GetAltCurrency_x                       0x7FF750

// StringTable 
#define StringTable__getString_x                                   0x7FB180

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x592200

//Doors
#define EQSwitch__UseSwitch_x                                      0x521DB0

//IconCache
#define IconCache__GetIcon_x                                       0x6757E0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x66C7D0
#define CContainerMgr__CloseContainer_x                            0x66CFE0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x737600

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x55F610

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B5C70
#define EQ_Spell__SpellAffects_x                                   0x4B5D10
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B5D40
#define CharacterZoneClient__CalcAffectChange_x                    0x436860
#define CLootWnd__LootAll_x                                        0x6CD140
#define CTargetWnd__GetBuffCaster_x                                0x77CE40
