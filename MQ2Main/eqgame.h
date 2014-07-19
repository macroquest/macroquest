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
#define __ExpectedVersionDate                                     "Jul 15 2014"
#define __ExpectedVersionTime                                     "16:24:10"
#define __ActualVersionDate_x                                      0xA49588
#define __ActualVersionTime_x                                      0xA49594

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x571160
#define __MemChecker1_x                                            0x833C80
#define __MemChecker2_x                                            0x607F30
#define __MemChecker3_x                                            0x607E80
#define __MemChecker4_x                                            0x7B89E0
#define __EncryptPad0_x                                            0xBB3000
#define __EncryptPad1_x                                            0xD2A700
#define __EncryptPad2_x                                            0xBF9A50
#define __EncryptPad3_x                                            0xBF9650
#define __EncryptPad4_x                                            0xD08550
#define __AC1_x                                                    0x775A95
#define __AC2_x                                                    0x527947
#define __AC3_x                                                    0x53C030
#define __AC4_x                                                    0x542160
#define __AC5_x                                                    0x54E791
#define __AC6_x                                                    0x5522D2
#define __AC7_x                                                    0x54826C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x10DB070
#define DI8__Keyboard_x                                            0x10DB074
#define DI8__Mouse_x                                               0x10DB078
#define __AltTimerReady_x                                          0xF3AB19
#define __Attack_x                                                 0xFCDC16
#define __Autofire_x                                               0xFCDC17
#define __BindList_x                                               0xB77840
#define __Clicks_x                                                 0xF49760
#define __CommandList_x                                            0xB7B8E0
#define __CurrentMapLabel_x                                        0x10E0CF0
#define __CurrentSocial_x                                          0xB3DA50
#define __DoAbilityList_x                                          0xF7FECC
#define __do_loot_x                                                0x4F01D0
#define __DrawHandler_x                                            0x17432AC
#define __GroupCount_x                                             0xF3A1F2

#define __Guilds_x                                                 0xF3FCE0
#define __gWorld_x                                                 0xF3C6AC
#define __HotkeyPage_x                                             0xFC68CC
#define __HWnd_x                                                   0xFD2F78
#define __InChatMode_x                                             0xF4968C
#define __LastTell_x                                               0xF4B5D4
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
#define __ServerName_x                                             0xF7FE8C
#define __ShiftKeyDown_x                                           0xF49D30
#define __ShowNames_x                                              0xF4AAB8
#define __Socials_x                                                0xF7FF8C
#define __SubscriptionType_x                                       0x110AA28
#define __TargetAggroHolder_x                                      0x10E2F08
#define __GroupAggro_x                                             0x10E2F48
#define __LoginName_x                                              0xFD1B50
#define __Inviter_x                                                0xFCDB94


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
#define pinstSpellSets_x                                           0xFC6930
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
#define __CastRay_x                                                0x506F10
#define __ConvertItemTags_x                                        0x4F4E90
#define __ExecuteCmd_x                                             0x4DFAF0
#define __EQGetTime_x                                              0x8347E0
#define __get_melee_range_x                                        0x4E6700
#define __GetGaugeValueFromEQ_x                                    0x7747F0
#define __GetLabelFromEQ_x                                         0x775A20
#define __GetXTargetType_x                                         0x8F1FF0
#define __LoadFrontEnd_x                                           0x6075E0
#define __NewUIINI_x                                               0x774130
#define __ProcessGameEvents_x                                      0x54A3B0
#define CrashDetected_x                                            0x6090B0
#define DrawNetStatus_x                                            0x580960
#define Util__FastTime_x                                           0x833AF0
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
#define CBankWnd__GetNumBankSlots_x                                0x637320

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x644F60

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x560AB0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6604D0
#define CChatManager__InitContextMenu_x                            0x660FF0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x81A8B0
#define CChatService__GetFriendName_x                              0x81A8C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x665D90
#define CChatWindow__Clear_x                                       0x665940
#define CChatWindow__WndNotification_x                             0x6662C0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x892FC0
#define CComboWnd__Draw_x                                          0x8931A0
#define CComboWnd__GetCurChoice_x                                  0x892DE0
#define CComboWnd__GetListRect_x                                   0x893440
#define CComboWnd__GetTextRect_x                                   0x893020
#define CComboWnd__InsertChoice_x                                  0x8934B0
#define CComboWnd__SetColors_x                                     0x892D70
#define CComboWnd__SetChoice_x                                     0x892DA0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x66F440
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
#define CEditBaseWnd__SetSel_x                                     0x8B4ED0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8A3AD0
#define CEditWnd__GetCharIndexPt_x                                 0x8A4AE0
#define CEditWnd__GetDisplayString_x                               0x8A3C80
#define CEditWnd__GetHorzOffset_x                                  0x8A3FC0
#define CEditWnd__GetLineForPrintableChar_x                        0x8A45B0
#define CEditWnd__GetSelStartPt_x                                  0x8A4D90
#define CEditWnd__GetSTMLSafeText_x                                0x8A4150
#define CEditWnd__PointFromPrintableChar_x                         0x8A46A0
#define CEditWnd__SelectableCharFromPoint_x                        0x8A4820
#define CEditWnd__SetEditable_x                                    0x8A4120

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x528090
#define CEverQuest__DoTellWindow_x                                 0x52DA20
#define CEverQuest__DropHeldItemOnGround_x                         0x5364B0
#define CEverQuest__dsp_chat_x                                     0x52F1C0
#define CEverQuest__Emote_x                                        0x52F420
#define CEverQuest__EnterZone_x                                    0x5422F0
#define CEverQuest__GetBodyTypeDesc_x                              0x5249C0
#define CEverQuest__GetClassDesc_x                                 0x52A590
#define CEverQuest__GetClassThreeLetterCode_x                      0x52AB90
#define CEverQuest__GetDeityDesc_x                                 0x5252A0
#define CEverQuest__GetLangDesc_x                                  0x524D50
#define CEverQuest__GetRaceDesc_x                                  0x52AD50
#define CEverQuest__InterpretCmd_x                                 0x52FD00
#define CEverQuest__LeftClickedOnPlayer_x                          0x5466E0
#define CEverQuest__LMouseUp_x                                     0x5489D0
#define CEverQuest__RightClickedOnPlayer_x                         0x5471E0
#define CEverQuest__RMouseUp_x                                     0x548220
#define CEverQuest__SetGameState_x                                 0x528740
#define CEverQuest__UPCNotificationFlush_x                         0x530EA0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x67FDF0
#define CGaugeWnd__CalcLinesFillRect_x                             0x67FE50
#define CGaugeWnd__Draw_x                                          0x680280

// CGuild
#define CGuild__FindMemberByName_x                                 0x424420

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x69C620

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6A83A0
#define CInvSlotMgr__MoveItem_x                                    0x6A92E0
#define CInvSlotMgr__SelectSlot_x                                  0x6A8450

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6A76D0
#define CInvSlot__SliderComplete_x                                 0x6A5520
#define CInvSlot__GetItemBase_x                                    0x6A49A0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6AA0D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x771450
#define CItemDisplayWnd__UpdateStrings_x                           0x6AB420

// CLabel 
#define CLabel__Draw_x                                             0x6C5F40

// CListWnd 
#define CListWnd__AddColumn_x                                      0x880F70
#define CListWnd__AddColumn1_x                                     0x880760
#define CListWnd__AddLine_x                                        0x880210
#define CListWnd__AddString_x                                      0x880420
#define CListWnd__CalculateFirstVisibleLine_x                      0x87D300
#define CListWnd__CalculateVSBRange_x                              0x87F400
#define CListWnd__ClearAllSel_x                                    0x87C5E0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x87FDE0
#define CListWnd__Compare_x                                        0x87DDE0
#define CListWnd__Draw_x                                           0x87F060
#define CListWnd__DrawColumnSeparators_x                           0x87EEF0
#define CListWnd__DrawHeader_x                                     0x87C8F0
#define CListWnd__DrawItem_x                                       0x87E430
#define CListWnd__DrawLine_x                                       0x87EB90
#define CListWnd__DrawSeparator_x                                  0x87EF90
#define CListWnd__EnsureVisible_x                                  0x87D460
#define CListWnd__ExtendSel_x                                      0x87E340
#define CListWnd__GetColumnMinWidth_x                              0x87C000
#define CListWnd__GetColumnWidth_x                                 0x87BF20
#define CListWnd__GetCurSel_x                                      0x87B7F0
#define CListWnd__GetItemAtPoint_x                                 0x87D6F0
#define CListWnd__GetItemAtPoint1_x                                0x87D760
#define CListWnd__GetItemData_x                                    0x87BA30
#define CListWnd__GetItemHeight_x                                  0x87CF70
#define CListWnd__GetItemIcon_x                                    0x87BC10
#define CListWnd__GetItemRect_x                                    0x87D530
#define CListWnd__GetItemText_x                                    0x87BAC0
#define CListWnd__GetSelList_x                                     0x880650
#define CListWnd__GetSeparatorRect_x                               0x87DD10
#define CListWnd__RemoveLine_x                                     0x880600
#define CListWnd__SetColors_x                                      0x87B850
#define CListWnd__SetColumnJustification_x                         0x87C2D0
#define CListWnd__SetColumnWidth_x                                 0x87BFB0
#define CListWnd__SetCurSel_x                                      0x87B830
#define CListWnd__SetItemColor_x                                   0x87FAC0
#define CListWnd__SetItemData_x                                    0x87C690
#define CListWnd__SetItemText_x                                    0x87F900
#define CListWnd__ShiftColumnSeparator_x                           0x87F790
#define CListWnd__Sort_x                                           0x8810DD
#define CListWnd__ToggleSel_x                                      0x87C560

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6DF1C0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x700130
#define CMerchantWnd__RequestBuyItem_x                             0x706A40
#define CMerchantWnd__RequestSellItem_x                            0x72E590
#define CMerchantWnd__SelectRecoverySlot_x                         0x7003E0
#define CMerchantWnd__SelectBuySellSlot_x                          0x6FF640
#define CMerchantWnd__ActualSelect_x                               0x703E30

// CObfuscator
#define CObfuscator__doit_x                                        0x7FAE40

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x898750
#define CSidlManager__CreateLabel_x                                0x7673F0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x62E4D0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x62E3F0
#define CSidlScreenWnd__ConvertToRes_x                             0x8B4DB0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x886090
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x887590
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x887640
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x886B10
#define CSidlScreenWnd__DrawSidlPiece_x                            0x885B70
#define CSidlScreenWnd__EnableIniStorage_x                         0x8852B0
#define CSidlScreenWnd__GetSidlPiece_x                             0x885D60
#define CSidlScreenWnd__Init1_x                                    0x887270
#define CSidlScreenWnd__LoadIniInfo_x                              0x886140
#define CSidlScreenWnd__LoadIniListWnd_x                           0x885470
#define CSidlScreenWnd__LoadSidlScreen_x                           0x886D60
#define CSidlScreenWnd__StoreIniInfo_x                             0x884D70
#define CSidlScreenWnd__StoreIniVis_x                              0x885240
#define CSidlScreenWnd__WndNotification_x                          0x886FF0
#define CSidlScreenWnd__GetChildItem_x                             0x885380
#define CSidlScreenWnd__HandleLButtonUp_x                          0x88BF40

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5C9750
#define CSkillMgr__GetSkillCap_x                                   0x5C98F0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8BEDB0
#define CSliderWnd__SetValue_x                                     0x8BEF80
#define CSliderWnd__SetNumTicks_x                                  0x8BF700

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x76F0F0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8AF1A0
#define CStmlWnd__CalculateHSBRange_x                              0x8A76E0
#define CStmlWnd__CalculateVSBRange_x                              0x8A7770
#define CStmlWnd__CanBreakAtCharacter_x                            0x8A78F0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8A81D0
#define CStmlWnd__ForceParseNow_x                                  0x8AFAF0
#define CStmlWnd__GetNextTagPiece_x                                0x8A80D0
#define CStmlWnd__GetSTMLText_x                                    0x6651E0
#define CStmlWnd__GetVisibleText_x                                 0x8A8C20
#define CStmlWnd__InitializeWindowVariables_x                      0x8AAF90
#define CStmlWnd__MakeStmlColorTag_x                               0x8A69E0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8A6A40
#define CStmlWnd__SetSTMLText_x                                    0x8AC7F0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8AEE40
#define CStmlWnd__UpdateHistoryString_x                            0x8A9B50

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8B65A0
#define CTabWnd__DrawCurrentPage_x                                 0x8B5E10
#define CTabWnd__DrawTab_x                                         0x8B5BE0
#define CTabWnd__GetCurrentPage_x                                  0x8B61E0
#define CTabWnd__GetPageInnerRect_x                                0x8B58D0
#define CTabWnd__GetTabInnerRect_x                                 0x8B5AD0
#define CTabWnd__GetTabRect_x                                      0x8B59A0
#define CTabWnd__InsertPage_x                                      0x8B6890
#define CTabWnd__SetPage_x                                         0x8B6210
#define CTabWnd__SetPageRect_x                                     0x8B64E0
#define CTabWnd__UpdatePage_x                                      0x8B6830

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4201A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8B2610

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8BB770

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8797F0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x56D880
#define CXStr__CXStr1_x                                            0x7A56F0
#define CXStr__CXStr3_x                                            0x830B80
#define CXStr__dCXStr_x                                            0x711460
#define CXStr__operator_equal_x                                    0x830CF0
#define CXStr__operator_equal1_x                                   0x830D40
#define CXStr__operator_plus_equal1_x                              0x831E20

// CXWnd 
#define CXWnd__BringToTop_x                                        0x88B130
#define CXWnd__Center_x                                            0x891410
#define CXWnd__ClrFocus_x                                          0x88AD00
#define CXWnd__DoAllDrawing_x                                      0x891060
#define CXWnd__DrawChildren_x                                      0x891200
#define CXWnd__DrawColoredRect_x                                   0x88B4F0
#define CXWnd__DrawTooltip_x                                       0x88B790
#define CXWnd__DrawTooltipAtPoint_x                                0x88FFF0
#define CXWnd__GetBorderFrame_x                                    0x88BC00
#define CXWnd__GetChildWndAt_x                                     0x88EF90
#define CXWnd__GetClientClipRect_x                                 0x88B9B0
#define CXWnd__GetScreenClipRect_x                                 0x8906E0
#define CXWnd__GetScreenRect_x                                     0x88BDD0
#define CXWnd__GetTooltipRect_x                                    0x88B620
#define CXWnd__GetWindowTextA_x                                    0x4116D0
#define CXWnd__IsActive_x                                          0x89E7D0
#define CXWnd__IsDescendantOf_x                                    0x88BB40
#define CXWnd__IsReallyVisible_x                                   0x88EF70
#define CXWnd__IsType_x                                            0x8B7F40
#define CXWnd__Move_x                                              0x88E650
#define CXWnd__Move1_x                                             0x890D10
#define CXWnd__ProcessTransition_x                                 0x88B0D0
#define CXWnd__Refade_x                                            0x88AEA0
#define CXWnd__Resize_x                                            0x88BEA0
#define CXWnd__Right_x                                             0x8904E0
#define CXWnd__SetFocus_x                                          0x88D790
#define CXWnd__SetFont_x                                           0x88AD50
#define CXWnd__SetKeyTooltip_x                                     0x88C110
#define CXWnd__SetMouseOver_x                                      0x890A00
#define CXWnd__StartFade_x                                         0x88B180
#define CXWnd__GetChildItem_x                                      0x890950

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8A00E0
#define CXWndManager__DrawWindows_x                                0x89FD20
#define CXWndManager__GetKeyboardFlags_x                           0x89E300
#define CXWndManager__HandleKeyboardMsg_x                          0x89EC60
#define CXWndManager__RemoveWnd_x                                  0x89E960

// CDBStr
#define CDBStr__GetString_x                                        0x488080

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8EF030
#define EQ_Character__CastSpell_x                                  0x43C470
#define EQ_Character__Cur_HP_x                                     0x451EC0
#define EQ_Character__GetAACastingTimeModifier_x                   0x435540
#define EQ_Character__GetCharInfo2_x                               0x8055B0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42D8E0
#define EQ_Character__GetFocusRangeModifier_x                      0x42DAC0
#define EQ_Character__Max_Endurance_x                              0x592710
#define EQ_Character__Max_HP_x                                     0x4484D0
#define EQ_Character__Max_Mana_x                                   0x592540
#define EQ_Character__doCombatAbility_x                            0x58FD70
#define EQ_Character__UseSkill_x                                   0x45CA00
#define EQ_Character__GetConLevel_x                                0x584FD0
#define EQ_Character__IsExpansionFlag_x                            0x410C10
#define EQ_Character__TotalEffect_x                                0x43A5A0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x565AD0
#define EQ_Item__CreateItemTagString_x                             0x7E5D40
#define EQ_Item__IsStackable_x                                     0x7DA240
#define EQ_Item__GetImageNum_x                                     0x7DCE70

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A76A0
#define EQ_LoadingS__Array_x                                       0xB66688

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x593D70
#define EQ_PC__GetAltAbilityIndex_x                                0x7EDF80
#define EQ_PC__GetCombatAbility_x                                  0x7EE010
#define EQ_PC__GetCombatAbilityTimer_x                             0x7EE0C0
#define EQ_PC__GetItemTimerValue_x                                 0x58DB60
#define EQ_PC__HasLoreItem_x                                       0x588170
#define EQ_PC__AlertInventoryChanged_x                             0x584FA0
#define EQ_PC__GetPcZoneClient_x                                   0x5ADEE0
#define EQ_PC__RemoveMyAffect_x									   0x58D090

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E46C0
#define EQItemList__add_item_x                                     0x4E4600
#define EQItemList__delete_item_x                                  0x4E4AC0
#define EQItemList__FreeItemList_x                                 0x4E49C0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x487590

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x599170
#define EQPlayer__dEQPlayer_x                                      0x5A1CF0
#define EQPlayer__DoAttack_x                                       0x5B3CE0
#define EQPlayer__EQPlayer_x                                       0x5A4140
#define EQPlayer__SetNameSpriteState_x                             0x59EB10
#define EQPlayer__SetNameSpriteTint_x                              0x59A4A0
#define EQPlayer__IsBodyType_j_x                                   0x8EE2E0
#define EQPlayer__IsTargetable_x                                   0x8EEB10

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5A8450
#define EQPlayerManager__GetSpawnByName_x                          0x5A88B0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56BBB0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56BBF0
#define KeypressHandler__ClearCommandStateArray_x                  0x56B790
#define KeypressHandler__HandleKeyDown_x                           0x56A0B0
#define KeypressHandler__HandleKeyUp_x                             0x56A400
#define KeypressHandler__SaveKeymapping_x                          0x56B860

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6D75A0
#define MapViewMap__SaveEx_x                                       0x6DAE80

#define PlayerPointManager__GetAltCurrency_x                       0x7FF6B0

// StringTable 
#define StringTable__getString_x                                   0x7FB0E0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5921C0

//Doors
#define EQSwitch__UseSwitch_x                                      0x521D10

//IconCache
#define IconCache__GetIcon_x                                       0x675780

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x66C770
#define CContainerMgr__CloseContainer_x                            0x66CF80

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x737550

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x55F590

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B5C70
#define EQ_Spell__SpellAffects_x                                   0x4B5D10
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B5D40
#define CharacterZoneClient__CalcAffectChange_x                    0x436860
#define CLootWnd__LootAll_x                                        0x6CD0D0
#define CTargetWnd__GetBuffCaster_x                                0x77CD90
