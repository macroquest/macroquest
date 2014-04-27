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
#define __ExpectedVersionDate                                     "Nov 13 2013"
#define __ExpectedVersionTime                                     "10:48:19"
#define __ActualVersionDate_x                                      0x9EDB88
#define __ActualVersionTime_x                                      0x9EDB94

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x56B1E0
#define __MemChecker1_x                                            0x826170
#define __MemChecker2_x                                            0x600A70
#define __MemChecker3_x                                            0x6009C0
#define __MemChecker4_x                                            0x7AEB60
#define __EncryptPad0_x                                            0xAF89E0
#define __EncryptPad1_x                                            0xB7D290
#define __EncryptPad2_x                                            0xB12FC8
#define __EncryptPad3_x                                            0xB12BC8
#define __EncryptPad4_x                                            0xB796E0
#define __AC1_x                                                    0x76C485
#define __AC2_x                                                    0x51F0C7
#define __AC3_x                                                    0x5324F0
#define __AC4_x                                                    0x538554
#define __AC5_x                                                    0x544A11
#define __AC6_x                                                    0x5484D2
#define __AC7_x                                                    0x53E52C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0xF1F050
#define DI8__Keyboard_x                                            0xF1F054
#define DI8__Mouse_x                                               0xF1F058
#define __AltTimerReady_x                                          0xD7FA19
#define __Attack_x                                                 0xE128B6
#define __Autofire_x                                               0xE128B7
#define __BindList_x                                               0xADF948
#define __Clicks_x                                                 0xD8E748
#define __CommandList_x                                            0xAE1108
#define __CurrentMapLabel_x                                        0xF23960
#define __CurrentSocial_x                                          0xAC91CC
#define __DoAbilityList_x                                          0xDC4E64
#define __do_loot_x                                                0x4ED100
#define __DrawHandler_x                                            0x1584A84
#define __GroupCount_x                                             0xD7F0F2

#define __Guilds_x                                                 0xD84CF8
#define __gWorld_x                                                 0xD815AC
#define __HotkeyPage_x                                             0xE0B864
#define __HWnd_x                                                   0xE16F58
#define __InChatMode_x                                             0xD8E67C
#define __LastTell_x                                               0xD9056C
#define __LMouseHeldTime_x                                         0xD8E7B4
#define __Mouse_x                                                  0xF1F05C
#define __MouseLook_x                                              0xD8E716
#define __MouseEventTime_x                                         0xE12D9C
#define __NetStatusToggle_x                                        0xD8E719
#define __PCNames_x                                                0xD8FBDC
#define __RangeAttackReady_x                                       0xD8F87C
#define __RMouseHeldTime_x                                         0xD8E7B0
#define __RunWalkState_x                                           0xD8E680
#define __ScreenMode_x                                             0xCCE160
#define __ScreenX_x                                                0xD8E634
#define __ScreenY_x                                                0xD8E630
#define __ScreenXMax_x                                             0xD8E638
#define __ScreenYMax_x                                             0xD8E63C
#define __ServerHost_x                                             0xD7F03C
#define __ServerName_x                                             0xDC4E24
#define __ShiftKeyDown_x                                           0xD8ED14
#define __ShowNames_x                                              0xD8FA84
#define __Socials_x                                                0xDC4F24
#define __SubscriptionType_x                                       0xF4C570
#define __TargetAggroHolder_x									   0xF25280
#define __GroupAggro_x											   0xF252C0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xD81690
#define instEQZoneInfo_x                                           0xD8E904
#define instKeypressHandler_x                                      0xE12D80
#define pinstActiveBanker_x                                        0xD81650
#define pinstActiveCorpse_x                                        0xD81654
#define pinstActiveGMaster_x                                       0xD81658
#define pinstActiveMerchant_x                                      0xD8164C
#define pinstAggroInfo_x                                           0xB92E40
#define pinstAltAdvManager_x                                       0xCCF148
#define pinstAuraMgr_x                                             0xB9C8B0
#define pinstBandageTarget_x                                       0xD81638
#define pinstCamActor_x                                            0xCCEB34
#define pinstCDBStr_x                                              0xCCE120
#define pinstCDisplay_x                                            0xD81660
#define pinstCEverQuest_x                                          0xF1F1D4
#define pinstCharData_x                                            0xD8161C
#define pinstCharSpawn_x                                           0xD81644
#define pinstControlledMissile_x                                   0xD81618
#define pinstControlledPlayer_x                                    0xD81644
#define pinstCSidlManager_x                                        0x1584138
#define pinstCXWndManager_x                                        0x1584130
#define instDynamicZone_x                                          0xD8E4D0
#define pinstDZMember_x                                            0xD8E5E0
#define pinstDZTimerInfo_x                                         0xD8E5E4
#define pinstEQItemList_x                                          0xD7E038
#define instEQMisc_x                                               0xAD29E0
#define pinstEQSoundManager_x                                      0xCCF2E0
#define instExpeditionLeader_x                                     0xD8E51A
#define instExpeditionName_x                                       0xD8E55A
#define pinstGroup_x                                               0xD7F0EE
#define pinstImeManager_x                                          0x158413C
#define pinstLocalPlayer_x                                         0xD81630
#define pinstMercenaryData_x                                       0xE132C0
#define pinstMercAltAbilities_x									   0xCCF25C
#define pinstModelPlayer_x                                         0xD8165C
#define pinstPCData_x                                              0xD8161C
#define pinstSkillMgr_x                                            0xE13BB8
#define pinstSpawnManager_x                                        0xE136E0
#define pinstSpellManager_x                                        0xE13C78
#define pinstSpellSets_x                                           0xE0B8C8
#define pinstStringTable_x                                         0xD815C4
#define pinstSwitchManager_x                                       0xD7ECD8
#define pinstTarget_x                                              0xD81648
#define pinstTargetObject_x                                        0xD81620
#define pinstTargetSwitch_x                                        0xD81624
#define pinstTaskMember_x                                          0xCCE0A8
#define pinstTrackTarget_x                                         0xD8163C
#define pinstTradeTarget_x                                         0xD8162C
#define instTributeActive_x                                        0xAD2A05
#define pinstViewActor_x                                           0xCCEB30
#define pinstWorldData_x                                           0xD81600


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xB93130
#define pinstCAudioTriggersWindow_x                                0xB93050
#define pinstCCharacterSelect_x                                    0xCCE9DC
#define pinstCFacePick_x                                           0xCCE78C
#define pinstCNoteWnd_x                                            0xCCE994
#define pinstCBookWnd_x                                            0xCCE99C
#define pinstCPetInfoWnd_x                                         0xCCE9A0
#define pinstCTrainWnd_x                                           0xCCE9A4
#define pinstCSkillsWnd_x                                          0xCCE9A8
#define pinstCSkillsSelectWnd_x                                    0xCCE9AC
#define pinstCCombatSkillSelectWnd_x                               0xCCE9B0
#define pinstCFriendsWnd_x                                         0xCCE9B4
#define pinstCAuraWnd_x                                            0xCCE9B8
#define pinstCRespawnWnd_x                                         0xCCE9BC
#define pinstCBandolierWnd_x                                       0xCCE9C0
#define pinstCPotionBeltWnd_x                                      0xCCE9C4
#define pinstCAAWnd_x                                              0xCCE9C8
#define pinstCGroupSearchFiltersWnd_x                              0xCCE9CC
#define pinstCLoadskinWnd_x                                        0xCCE9D0
#define pinstCAlarmWnd_x                                           0xCCE9D4
#define pinstCMusicPlayerWnd_x                                     0xCCE9D8
#define pinstCMailWnd_x                                            0xCCE9E0
#define pinstCMailCompositionWnd_x                                 0xCCE9E4
#define pinstCMailAddressBookWnd_x                                 0xCCE9E8
#define pinstCRaidWnd_x                                            0xCCE9F0
#define pinstCRaidOptionsWnd_x                                     0xCCE9F4
#define pinstCBreathWnd_x                                          0xCCE9F8
#define pinstCMapViewWnd_x                                         0xCCE9FC
#define pinstCMapToolbarWnd_x                                      0xCCEA00
#define pinstCEditLabelWnd_x                                       0xCCEA04
#define pinstCTargetWnd_x                                          0xCCEA08
#define pinstCColorPickerWnd_x                                     0xCCEA0C
#define pinstCPlayerWnd_x                                          0xCCEA10
#define pinstCOptionsWnd_x                                         0xCCEA14
#define pinstCBuffWindowNORMAL_x                                   0xCCEA18
#define pinstCBuffWindowSHORT_x                                    0xCCEA1C
#define pinstCharacterCreation_x                                   0xCCEA20
#define pinstCCursorAttachment_x                                   0xCCEA24
#define pinstCCastingWnd_x                                         0xCCEA28
#define pinstCCastSpellWnd_x                                       0xCCEA2C
#define pinstCSpellBookWnd_x                                       0xCCEA30
#define pinstCInventoryWnd_x                                       0xCCEA34
#define pinstCBankWnd_x                                            0xCCEA38
#define pinstCQuantityWnd_x                                        0xCCEA3C
#define pinstCLootWnd_x                                            0xCCEA40
#define pinstCActionsWnd_x                                         0xCCEA44
#define pinstCCombatAbilityWnd_x                                   0xCCEA48
#define pinstCMerchantWnd_x                                        0xCCEA4C
#define pinstCTradeWnd_x                                           0xCCEA50
#define pinstCSelectorWnd_x                                        0xCCEA54
#define pinstCBazaarWnd_x                                          0xCCEA58
#define pinstCBazaarSearchWnd_x                                    0xCCEA5C
#define pinstCGiveWnd_x                                            0xCCEA78
#define pinstCTrackingWnd_x                                        0xCCEA80
#define pinstCInspectWnd_x                                         0xCCEA84
#define pinstCSocialEditWnd_x                                      0xCCEA88
#define pinstCFeedbackWnd_x                                        0xCCEA8C
#define pinstCBugReportWnd_x                                       0xCCEA90
#define pinstCVideoModesWnd_x                                      0xCCEA94
#define pinstCTextEntryWnd_x                                       0xCCEA9C
#define pinstCFileSelectionWnd_x                                   0xCCEAA0
#define pinstCCompassWnd_x                                         0xCCEAA4
#define pinstCPlayerNotesWnd_x                                     0xCCEAA8
#define pinstCGemsGameWnd_x                                        0xCCEAAC
#define pinstCTimeLeftWnd_x                                        0xCCEAB0
#define pinstCPetitionQWnd_x                                       0xCCEAC4
#define pinstCSoulmarkWnd_x                                        0xCCEAC8
#define pinstCStoryWnd_x                                           0xCCEACC
#define pinstCJournalTextWnd_x                                     0xCCEAD0
#define pinstCJournalCatWnd_x                                      0xCCEAD4
#define pinstCBodyTintWnd_x                                        0xCCEAD8
#define pinstCServerListWnd_x                                      0xCCEADC
#define pinstCAvaZoneWnd_x                                         0xCCEAE8
#define pinstCBlockedBuffWnd_x                                     0xCCEAEC
#define pinstCBlockedPetBuffWnd_x                                  0xCCEAF0
#define pinstCInvSlotMgr_x                                         0xCCEB28
#define pinstCContainerMgr_x                                       0xCCEB2C
#define pinstCAdventureLeaderboardWnd_x                            0xF1FBD8
#define pinstCAdventureRequestWnd_x                                0xF1FC28
#define pinstCAltStorageWnd_x                                      0xF1FDF8
#define pinstCAdventureStatsWnd_x                                  0xF1FC78
#define pinstCBarterMerchantWnd_x                                  0xF204D8
#define pinstCBarterSearchWnd_x                                    0xF20528
#define pinstCBarterWnd_x                                          0xF20578
#define pinstCChatManager_x                                        0xF20978
#define pinstCDynamicZoneWnd_x                                     0xF20C58
#define pinstCEQMainWnd_x                                          0xF20D60
#define pinstCFellowshipWnd_x                                      0xF20C1C
#define pinstCFindLocationWnd_x                                    0xF20F20
#define pinstCGroupSearchWnd_x                                     0xF21128
#define pinstCGroupWnd_x                                           0xF21178
#define pinstCGuildBankWnd_x                                       0xF211C8
#define pinstCGuildMgmtWnd_x                                       0xF23268
#define pinstCHotButtonWnd_x                                       0xF232DC
#define pinstCHotButtonWnd1_x                                      0xF232DC
#define pinstCHotButtonWnd2_x                                      0xF232E0
#define pinstCHotButtonWnd3_x                                      0xF232E4
#define pinstCHotButtonWnd4_x                                      0xF23308
#define pinstCItemDisplayManager_x                                 0xF234E8
#define pinstCItemExpTransferWnd_x                                 0xF2353C
#define pinstCLFGuildWnd_x                                         0xF23748
#define pinstCMIZoneSelectWnd_x                                    0xF23B08
#define pinstCConfirmationDialog_x                                 0xF23F58
#define pinstCPopupWndManager_x                                    0xF23F58
#define pinstCProgressionSelectionWnd_x                            0xF23FF0
#define pinstCPvPStatsWnd_x                                        0xF24090
#define pinstCSystemInfoDialogBox_x                                0xF244E0
#define pinstCTaskTemplateSelectWnd_x                              0xF25550
#define pinstCTipWndOFDAY_x                                        0xF25710
#define pinstCTipWndCONTEXT_x                                      0xF25714
#define pinstCTitleWnd_x                                           0xF25760
#define pinstCContextMenuManager_x                                 0x1583D4C
#define pinstCVoiceMacroWnd_x                                      0xE140E0
#define pinstCHtmlWnd_x                                            0xE14188


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x502D80
#define __ConvertItemTags_x                                        0x4F2C00
#define __ExecuteCmd_x                                             0x4DC810
#define __EQGetTime_x                                              0x826CD0
#define __get_melee_range_x                                        0x4E3440
#define __GetGaugeValueFromEQ_x                                    0x76B1B0
#define __GetLabelFromEQ_x                                         0x76C410
#define __GetXTargetType_x                                         0x8E28D0
#define __LoadFrontEnd_x                                           0x600120
#define __NewUIINI_x                                               0x76AAF0
#define __ProcessGameEvents_x                                      0x540670
#define CrashDetected_x                                            0x603F70
#define DrawNetStatus_x                                            0x57A6C0
#define Util__FastTime_x                                           0x826010
#define Expansion_HoT_x                                            0xD8F9E4
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A43E0
#define AltAdvManager__IsAbilityReady_x                            0x4A4450
#define AltAdvManager__GetAltAbility_x                             0x4A4810

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x44A6F0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x62FBB0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x63E1C0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x556930

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x658750
#define CChatManager__InitContextMenu_x                            0x659270

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x80CCD0
#define CChatService__GetFriendName_x                              0x80CCE0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x65DF90
#define CChatWindow__Clear_x                                       0x65DB50
#define CChatWindow__WndNotification_x                             0x65E4C0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x884D80
#define CComboWnd__Draw_x                                          0x884F50
#define CComboWnd__GetCurChoice_x                                  0x884BA0
#define CComboWnd__GetListRect_x                                   0x8851F0
#define CComboWnd__GetTextRect_x                                   0x884DE0
#define CComboWnd__InsertChoice_x                                  0x885260
#define CComboWnd__SetColors_x                                     0x884B30
#define CComboWnd__SetChoice_x                                     0x884B60

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6676D0
#define CContainerWnd__vftable_x                                   0x9F71A8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4940C0
#define CDisplay__GetClickedActor_x                                0x48BDC0
#define CDisplay__GetUserDefinedColor_x                            0x48A680
#define CDisplay__GetWorldFilePath_x                               0x489A80
#define CDisplay__is3dON_x                                         0x488B50
#define CDisplay__ReloadUI_x                                       0x49E090
#define CDisplay__WriteTextHD2_x                                   0x48F510

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8A6650

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x895610
#define CEditWnd__GetCharIndexPt_x                                 0x896630
#define CEditWnd__GetDisplayString_x                               0x8957C0
#define CEditWnd__GetHorzOffset_x                                  0x895B00
#define CEditWnd__GetLineForPrintableChar_x                        0x896100
#define CEditWnd__GetSelStartPt_x                                  0x8968E0
#define CEditWnd__GetSTMLSafeText_x                                0x895CA0
#define CEditWnd__PointFromPrintableChar_x                         0x8961F0
#define CEditWnd__SelectableCharFromPoint_x                        0x896370
#define CEditWnd__SetEditable_x                                    0x895C70

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x51F810
#define CEverQuest__DoTellWindow_x                                 0x524130
#define CEverQuest__DropHeldItemOnGround_x                         0x52C9F0
#define CEverQuest__dsp_chat_x                                     0x5258D0
#define CEverQuest__Emote_x                                        0x525B30
#define CEverQuest__EnterZone_x                                    0x5386E0
#define CEverQuest__GetBodyTypeDesc_x                              0x51BE90
#define CEverQuest__GetClassDesc_x                                 0x51B5F0
#define CEverQuest__GetClassThreeLetterCode_x                      0x51BBF0
#define CEverQuest__GetDeityDesc_x                                 0x51C7A0
#define CEverQuest__GetLangDesc_x                                  0x51C220
#define CEverQuest__GetRaceDesc_x                                  0x51C510
#define CEverQuest__InterpretCmd_x                                 0x526410
#define CEverQuest__LeftClickedOnPlayer_x                          0x53CA70
#define CEverQuest__LMouseUp_x                                     0x53EC90
#define CEverQuest__RightClickedOnPlayer_x                         0x53D530
#define CEverQuest__RMouseUp_x                                     0x53E4E0
#define CEverQuest__SetGameState_x                                 0x51FEC0
#define CEverQuest__UPCNotificationFlush_x                         0x5273A0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x677640
#define CGaugeWnd__CalcLinesFillRect_x                             0x6776A0
#define CGaugeWnd__Draw_x                                          0x677AD0

// CGuild
#define CGuild__FindMemberByName_x                                 0x424080

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x694710

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6A0030
#define CInvSlotMgr__MoveItem_x                                    0x6A0F60

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x69F430
#define CInvSlot__SliderComplete_x                                 0x69D280
#define CInvSlot__GetItemBase_x                                    0x69C700

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6A1D30

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x767DD0
#define CItemDisplayWnd__UpdateStrings_x                           0x6A3060

// CLabel 
#define CLabel__Draw_x                                             0x6BD830

// CListWnd 
#define CListWnd__AddColumn_x                                      0x8730D0
#define CListWnd__AddColumn1_x                                     0x8728B0
#define CListWnd__AddLine_x                                        0x872360
#define CListWnd__AddString_x                                      0x872570
#define CListWnd__CalculateFirstVisibleLine_x                      0x86F440
#define CListWnd__CalculateVSBRange_x                              0x871560
#define CListWnd__ClearAllSel_x                                    0x86E6F0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x871F30
#define CListWnd__Compare_x                                        0x86FF30
#define CListWnd__Draw_x                                           0x8711C0
#define CListWnd__DrawColumnSeparators_x                           0x871050
#define CListWnd__DrawHeader_x                                     0x86EA00
#define CListWnd__DrawItem_x                                       0x870580
#define CListWnd__DrawLine_x                                       0x870CF0
#define CListWnd__DrawSeparator_x                                  0x8710F0
#define CListWnd__EnsureVisible_x                                  0x86F5A0
#define CListWnd__ExtendSel_x                                      0x870490
#define CListWnd__GetColumnMinWidth_x                              0x86E110
#define CListWnd__GetColumnWidth_x                                 0x86E030
#define CListWnd__GetCurSel_x                                      0x86D910
#define CListWnd__GetItemAtPoint_x                                 0x86F830
#define CListWnd__GetItemAtPoint1_x                                0x86F8A0
#define CListWnd__GetItemData_x                                    0x86DB50
#define CListWnd__GetItemHeight_x                                  0x86F090
#define CListWnd__GetItemIcon_x                                    0x86DD30
#define CListWnd__GetItemRect_x                                    0x86F670
#define CListWnd__GetItemText_x                                    0x86DBE0
#define CListWnd__GetSelList_x                                     0x8727A0
#define CListWnd__GetSeparatorRect_x                               0x86FE50
#define CListWnd__RemoveLine_x                                     0x872750
#define CListWnd__SetColors_x                                      0x86D970
#define CListWnd__SetColumnJustification_x                         0x86E3E0
#define CListWnd__SetColumnWidth_x                                 0x86E0C0
#define CListWnd__SetCurSel_x                                      0x86D950
#define CListWnd__SetItemColor_x                                   0x871C10
#define CListWnd__SetItemData_x                                    0x86E7A0
#define CListWnd__SetItemText_x                                    0x871A50
#define CListWnd__ShiftColumnSeparator_x                           0x8718E0
#define CListWnd__Sort_x                                           0x873230
#define CListWnd__ToggleSel_x                                      0x86E670

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6D8530

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6F8380
#define CMerchantWnd__RequestBuyItem_x                             0x6FE930
#define CMerchantWnd__RequestSellItem_x                            0x725BA0
#define CMerchantWnd__SelectBuySellSlot_x                          0x6F8630

// CObfuscator
#define CObfuscator__doit_x                                        0x7EC9E0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x88A4F0
#define CSidlManager__CreateLabel_x                                0x75E4F0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x626D30
#define CSidlScreenWnd__CalculateVSBRange_x                        0x626C60
#define CSidlScreenWnd__ConvertToRes_x                             0x8A6530
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x878120
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8794C0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x879570
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x878A50
#define CSidlScreenWnd__DrawSidlPiece_x                            0x877C00
#define CSidlScreenWnd__EnableIniStorage_x                         0x877370
#define CSidlScreenWnd__GetSidlPiece_x                             0x877DF0
#define CSidlScreenWnd__Init1_x                                    0x879190
#define CSidlScreenWnd__LoadIniInfo_x                              0x8781D0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x877530
#define CSidlScreenWnd__LoadSidlScreen_x                           0x878CA0
#define CSidlScreenWnd__StoreIniInfo_x                             0x876EE0
#define CSidlScreenWnd__StoreIniVis_x                              0x877300
#define CSidlScreenWnd__WndNotification_x                          0x878F10
#define CSidlScreenWnd__GetChildItem_x                             0x877440

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5C2310
#define CSkillMgr__GetSkillCap_x                                   0x5C2390

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8B0580
#define CSliderWnd__SetValue_x                                     0x8B0750
#define CSliderWnd__SetNumTicks_x                                  0x8B0ED0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x765890

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8A0C60
#define CStmlWnd__CalculateHSBRange_x                              0x8992D0
#define CStmlWnd__CalculateVSBRange_x                              0x899350
#define CStmlWnd__CanBreakAtCharacter_x                            0x8994D0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x899DB0
#define CStmlWnd__ForceParseNow_x                                  0x8A1620
#define CStmlWnd__GetNextTagPiece_x                                0x899CB0
#define CStmlWnd__GetSTMLText_x                                    0x65D3F0
#define CStmlWnd__GetVisibleText_x                                 0x89A800
#define CStmlWnd__InitializeWindowVariables_x                      0x89CAA0
#define CStmlWnd__MakeStmlColorTag_x                               0x8984B0
#define CStmlWnd__MakeWndNotificationTag_x                         0x898510
#define CStmlWnd__SetSTMLText_x                                    0x89E300
#define CStmlWnd__StripFirstSTMLLines_x                            0x8A0900
#define CStmlWnd__UpdateHistoryString_x                            0x89B740

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8A7D20
#define CTabWnd__DrawCurrentPage_x                                 0x8A7590
#define CTabWnd__DrawTab_x                                         0x8A7350
#define CTabWnd__GetCurrentPage_x                                  0x8A7960
#define CTabWnd__GetPageInnerRect_x                                0x8A7040
#define CTabWnd__GetTabInnerRect_x                                 0x8A7240
#define CTabWnd__GetTabRect_x                                      0x8A7110
#define CTabWnd__InsertPage_x                                      0x8A8010
#define CTabWnd__SetPage_x                                         0x8A7990
#define CTabWnd__SetPageRect_x                                     0x8A7C60
#define CTabWnd__UpdatePage_x                                      0x8A7FB0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x41FC10

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8A4110

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8ACF40

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x86BA20

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4112E0
#define CXStr__CXStr1_x                                            0x861120
#define CXStr__CXStr3_x                                            0x8230A0
#define CXStr__dCXStr_x                                            0x768E80
#define CXStr__operator_equal_x                                    0x823210
#define CXStr__operator_equal1_x                                   0x823260
#define CXStr__operator_plus_equal1_x                              0x824340

// CXWnd 
#define CXWnd__BringToTop_x                                        0x87D060
#define CXWnd__Center_x                                            0x8831F0
#define CXWnd__ClrFocus_x                                          0x87CC50
#define CXWnd__DoAllDrawing_x                                      0x882E70
#define CXWnd__DrawChildren_x                                      0x882FF0
#define CXWnd__DrawColoredRect_x                                   0x87D410
#define CXWnd__DrawTooltip_x                                       0x87D6B0
#define CXWnd__DrawTooltipAtPoint_x                                0x881E00
#define CXWnd__GetBorderFrame_x                                    0x87DB00
#define CXWnd__GetChildWndAt_x                                     0x880DC0
#define CXWnd__GetClientClipRect_x                                 0x87D8C0
#define CXWnd__GetScreenClipRect_x                                 0x882500
#define CXWnd__GetScreenRect_x                                     0x87DCB0
#define CXWnd__GetTooltipRect_x                                    0x87D540
#define CXWnd__GetWindowTextA_x                                    0x411320
#define CXWnd__IsActive_x                                          0x8903C0
#define CXWnd__IsDescendantOf_x                                    0x87DA50
#define CXWnd__IsReallyVisible_x                                   0x880DA0
#define CXWnd__IsType_x                                            0x8A9740
#define CXWnd__Move_x                                              0x8804A0
#define CXWnd__Move1_x                                             0x882B20
#define CXWnd__ProcessTransition_x                                 0x87D010
#define CXWnd__Refade_x                                            0x87CDF0
#define CXWnd__Resize_x                                            0x87DD70
#define CXWnd__Right_x                                             0x882300
#define CXWnd__SetFocus_x                                          0x87F630
#define CXWnd__SetFont_x                                           0x87CCA0
#define CXWnd__SetKeyTooltip_x                                     0x87DFE0
#define CXWnd__SetMouseOver_x                                      0x882830
#define CXWnd__StartFade_x                                         0x87D0B0
#define CXWnd__GetChildItem_x                                      0x882770

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x891CC0
#define CXWndManager__DrawWindows_x                                0x891910
#define CXWndManager__GetKeyboardFlags_x                           0x88FF30
#define CXWndManager__HandleKeyboardMsg_x                          0x890850
#define CXWndManager__RemoveWnd_x                                  0x890550

// CDBStr
#define CDBStr__GetString_x                                        0x486DC0

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8DF1D0
#define EQ_Character__CastSpell_x                                  0x43ACA0
#define EQ_Character__Cur_HP_x                                     0x44A340
#define EQ_Character__GetAACastingTimeModifier_x                   0x433B20
#define EQ_Character__GetCharInfo2_x                               0x7F7850
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42CD90
#define EQ_Character__GetFocusRangeModifier_x                      0x42CF70
#define EQ_Character__Max_Endurance_x                              0x5891A0
#define EQ_Character__Max_HP_x                                     0x4444B0
#define EQ_Character__Max_Mana_x                                   0x588FE0
#define EQ_Character__doCombatAbility_x                            0x587AF0
#define EQ_Character__UseSkill_x                                   0x45B7F0
#define EQ_Character__GetConLevel_x                                0x57ECE0
#define EQ_Character__IsExpansionFlag_x                            0x410810
#define EQ_Character__TotalEffect_x                                0x438E00

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x55BC20
#define EQ_Item__CreateItemTagString_x                             0x7D7620
#define EQ_Item__IsStackable_x                                     0x7CBCC0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A64B0
#define EQ_LoadingS__Array_x                                       0xAD92C8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x58D7A0
#define EQ_PC__GetAltAbilityIndex_x                                0x7E01F0
#define EQ_PC__GetCombatAbility_x                                  0x7E0280
#define EQ_PC__GetCombatAbilityTimer_x                             0x7E0330
#define EQ_PC__GetItemTimerValue_x                                 0x587830
#define EQ_PC__HasLoreItem_x                                       0x581E90

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E1180
#define EQItemList__add_item_x                                     0x4E10C0
#define EQItemList__delete_item_x                                  0x4E1580
#define EQItemList__FreeItemList_x                                 0x4E1480

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x486260

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5934F0
#define EQPlayer__dEQPlayer_x                                      0x598160
#define EQPlayer__DoAttack_x                                       0x5AC790
#define EQPlayer__EQPlayer_x                                       0x59D950
#define EQPlayer__SetNameSpriteState_x                             0x595970
#define EQPlayer__SetNameSpriteTint_x                              0x593560
#define EQPlayer__IsBodyType_j_x                                   0x8DEA40
#define EQPlayer__IsTargetable_x                                   0x8DED10

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5A0E50
#define EQPlayerManager__GetSpawnByName_x                          0x5A12B0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x561DD0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x561E10
#define KeypressHandler__ClearCommandStateArray_x                  0x5619B0
#define KeypressHandler__HandleKeyDown_x                           0x560310
#define KeypressHandler__HandleKeyUp_x                             0x560630
#define KeypressHandler__SaveKeymapping_x                          0x561A80

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6D0950
#define MapViewMap__SaveEx_x                                       0x6D4230

#define PlayerPointManager__GetAltCurrency_x                       0x7F1980

// StringTable 
#define StringTable__getString_x                                   0x7ECC80

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x58C0A0

//Doors
#define EQSwitch__UseSwitch_x									   0x5183E0
