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
#define __ExpectedVersionDate                                     "Oct 31 2013"
#define __ExpectedVersionTime                                     "20:59:16"
#define __ActualVersionDate_x                                      0x9EDB88
#define __ActualVersionTime_x                                      0x9EDB94

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x56B170
#define __MemChecker1_x                                            0x825E80
#define __MemChecker2_x                                            0x6009E0
#define __MemChecker3_x                                            0x600930
#define __MemChecker4_x                                            0x7AEAA0
#define __EncryptPad0_x                                            0xAF89E0
#define __EncryptPad1_x                                            0xB7D290
#define __EncryptPad2_x                                            0xB12FC8
#define __EncryptPad3_x                                            0xB12BC8
#define __EncryptPad4_x                                            0xB796E0
#define __AC1_x                                                    0x76C3B5
#define __AC2_x                                                    0x51F067
#define __AC3_x                                                    0x532490
#define __AC4_x                                                    0x5384F4
#define __AC5_x                                                    0x5449C0
#define __AC6_x                                                    0x548472
#define __AC7_x                                                    0x53E4CC
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
#define __TargetAggroHolder_x					   0xF25280
#define __GroupAggro_x						   0xF252C0


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
#define pinstMercAltAbilities_x					   0xCCF25C
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
#define __EQGetTime_x                                              0x8269E0
#define __get_melee_range_x                                        0x4E3440
#define __GetGaugeValueFromEQ_x                                    0x76B0E0
#define __GetLabelFromEQ_x                                         0x76C340
#define __GetXTargetType_x                                         0x8E25C0
#define __LoadFrontEnd_x                                           0x600090
#define __NewUIINI_x                                               0x76AA20
#define __ProcessGameEvents_x                                      0x540610
#define CrashDetected_x                                            0x603EE0
#define DrawNetStatus_x                                            0x57A640
#define Util__FastTime_x                                           0x825D20
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
#define CBankWnd__GetNumBankSlots_x                                0x62FB40

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x63E150

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5568A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x658700
#define CChatManager__InitContextMenu_x                            0x659220

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x80CBD0
#define CChatService__GetFriendName_x                              0x80CBE0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x65DF40
#define CChatWindow__Clear_x                                       0x65DB00
#define CChatWindow__WndNotification_x                             0x65E470

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x884AA0
#define CComboWnd__Draw_x                                          0x884C70
#define CComboWnd__GetCurChoice_x                                  0x8848C0
#define CComboWnd__GetListRect_x                                   0x884F10
#define CComboWnd__GetTextRect_x                                   0x884B00
#define CComboWnd__InsertChoice_x                                  0x884F80
#define CComboWnd__SetColors_x                                     0x884850
#define CComboWnd__SetChoice_x                                     0x884880

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x667680
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
#define CEditBaseWnd__SetSel_x                                     0x8A6360

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x895320
#define CEditWnd__GetCharIndexPt_x                                 0x896340
#define CEditWnd__GetDisplayString_x                               0x8954D0
#define CEditWnd__GetHorzOffset_x                                  0x895810
#define CEditWnd__GetLineForPrintableChar_x                        0x895E10
#define CEditWnd__GetSelStartPt_x                                  0x8965F0
#define CEditWnd__GetSTMLSafeText_x                                0x8959B0
#define CEditWnd__PointFromPrintableChar_x                         0x895F00
#define CEditWnd__SelectableCharFromPoint_x                        0x896080
#define CEditWnd__SetEditable_x                                    0x895980

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x51F7B0
#define CEverQuest__DoTellWindow_x                                 0x5240D0
#define CEverQuest__DropHeldItemOnGround_x                         0x52C990
#define CEverQuest__dsp_chat_x                                     0x525870
#define CEverQuest__Emote_x                                        0x525AD0
#define CEverQuest__EnterZone_x                                    0x538680
#define CEverQuest__GetBodyTypeDesc_x                              0x51BE30
#define CEverQuest__GetClassDesc_x                                 0x51B590
#define CEverQuest__GetClassThreeLetterCode_x                      0x51BB90
#define CEverQuest__GetDeityDesc_x                                 0x51C740
#define CEverQuest__GetLangDesc_x                                  0x51C1C0
#define CEverQuest__GetRaceDesc_x                                  0x51C4B0
#define CEverQuest__InterpretCmd_x                                 0x5263B0
#define CEverQuest__LeftClickedOnPlayer_x                          0x53CA10
#define CEverQuest__LMouseUp_x                                     0x53EC30
#define CEverQuest__RightClickedOnPlayer_x                         0x53D4D0
#define CEverQuest__RMouseUp_x                                     0x53E480
#define CEverQuest__SetGameState_x                                 0x51FE60
#define CEverQuest__UPCNotificationFlush_x                         0x527340

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6775E0
#define CGaugeWnd__CalcLinesFillRect_x                             0x677640
#define CGaugeWnd__Draw_x                                          0x677A70

// CGuild
#define CGuild__FindMemberByName_x                                 0x424080

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x694680

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x69FFB0
#define CInvSlotMgr__MoveItem_x                                    0x6A0EE0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x69F3A0
#define CInvSlot__SliderComplete_x                                 0x69D1F0
#define CInvSlot__GetItemBase_x                                    0x69C670

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6A1CB0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x767D00
#define CItemDisplayWnd__UpdateStrings_x                           0x6A2FE0

// CLabel 
#define CLabel__Draw_x                                             0x6BD7B0

// CListWnd 
#define CListWnd__AddColumn_x                                      0x872DF0
#define CListWnd__AddColumn1_x                                     0x8725D0
#define CListWnd__AddLine_x                                        0x872080
#define CListWnd__AddString_x                                      0x872290
#define CListWnd__CalculateFirstVisibleLine_x                      0x86F160
#define CListWnd__CalculateVSBRange_x                              0x871280
#define CListWnd__ClearAllSel_x                                    0x86E410
#define CListWnd__CloseAndUpdateEditWindow_x                       0x871C50
#define CListWnd__Compare_x                                        0x86FC50
#define CListWnd__Draw_x                                           0x870EE0
#define CListWnd__DrawColumnSeparators_x                           0x870D70
#define CListWnd__DrawHeader_x                                     0x86E720
#define CListWnd__DrawItem_x                                       0x8702A0
#define CListWnd__DrawLine_x                                       0x870A10
#define CListWnd__DrawSeparator_x                                  0x870E10
#define CListWnd__EnsureVisible_x                                  0x86F2C0
#define CListWnd__ExtendSel_x                                      0x8701B0
#define CListWnd__GetColumnMinWidth_x                              0x86DE30
#define CListWnd__GetColumnWidth_x                                 0x86DD50
#define CListWnd__GetCurSel_x                                      0x86D630
#define CListWnd__GetItemAtPoint_x                                 0x86F550
#define CListWnd__GetItemAtPoint1_x                                0x86F5C0
#define CListWnd__GetItemData_x                                    0x86D870
#define CListWnd__GetItemHeight_x                                  0x86EDB0
#define CListWnd__GetItemIcon_x                                    0x86DA50
#define CListWnd__GetItemRect_x                                    0x86F390
#define CListWnd__GetItemText_x                                    0x86D900
#define CListWnd__GetSelList_x                                     0x8724C0
#define CListWnd__GetSeparatorRect_x                               0x86FB70
#define CListWnd__RemoveLine_x                                     0x872470
#define CListWnd__SetColors_x                                      0x86D690
#define CListWnd__SetColumnJustification_x                         0x86E100
#define CListWnd__SetColumnWidth_x                                 0x86DDE0
#define CListWnd__SetCurSel_x                                      0x86D670
#define CListWnd__SetItemColor_x                                   0x871930
#define CListWnd__SetItemData_x                                    0x86E4C0
#define CListWnd__SetItemText_x                                    0x871770
#define CListWnd__ShiftColumnSeparator_x                           0x871600
#define CListWnd__Sort_x                                           0x872F50
#define CListWnd__ToggleSel_x                                      0x86E390

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6D84B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6F82D0
#define CMerchantWnd__RequestBuyItem_x                             0x6FE880
#define CMerchantWnd__RequestSellItem_x                            0x725AC0
#define CMerchantWnd__SelectBuySellSlot_x                          0x6F8580

// CObfuscator
#define CObfuscator__doit_x                                        0x7EC910

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x88A210
#define CSidlManager__CreateLabel_x                                0x75E420

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x626CB0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x626BE0
#define CSidlScreenWnd__ConvertToRes_x                             0x8A6240
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x877E40
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8791E0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x879290
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x878770
#define CSidlScreenWnd__DrawSidlPiece_x                            0x877920
#define CSidlScreenWnd__EnableIniStorage_x                         0x877090
#define CSidlScreenWnd__GetSidlPiece_x                             0x877B10
#define CSidlScreenWnd__Init1_x                                    0x878EB0
#define CSidlScreenWnd__LoadIniInfo_x                              0x877EF0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x877250
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8789C0
#define CSidlScreenWnd__StoreIniInfo_x                             0x876C00
#define CSidlScreenWnd__StoreIniVis_x                              0x877020
#define CSidlScreenWnd__WndNotification_x                          0x878C30
#define CSidlScreenWnd__GetChildItem_x                             0x877160

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5C22A0
#define CSkillMgr__GetSkillCap_x                                   0x5C2320

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8B0290
#define CSliderWnd__SetValue_x                                     0x8B0460
#define CSliderWnd__SetNumTicks_x                                  0x8B0BE0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7657C0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8A0970
#define CStmlWnd__CalculateHSBRange_x                              0x898FE0
#define CStmlWnd__CalculateVSBRange_x                              0x899060
#define CStmlWnd__CanBreakAtCharacter_x                            0x8991E0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x899AC0
#define CStmlWnd__ForceParseNow_x                                  0x8A1330
#define CStmlWnd__GetNextTagPiece_x                                0x8999C0
#define CStmlWnd__GetSTMLText_x                                    0x65D3A0
#define CStmlWnd__GetVisibleText_x                                 0x89A510
#define CStmlWnd__InitializeWindowVariables_x                      0x89C7B0
#define CStmlWnd__MakeStmlColorTag_x                               0x8981C0
#define CStmlWnd__MakeWndNotificationTag_x                         0x898220
#define CStmlWnd__SetSTMLText_x                                    0x89E010
#define CStmlWnd__StripFirstSTMLLines_x                            0x8A0610
#define CStmlWnd__UpdateHistoryString_x                            0x89B450

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8A7A30
#define CTabWnd__DrawCurrentPage_x                                 0x8A72A0
#define CTabWnd__DrawTab_x                                         0x8A7060
#define CTabWnd__GetCurrentPage_x                                  0x8A7670
#define CTabWnd__GetPageInnerRect_x                                0x8A6D50
#define CTabWnd__GetTabInnerRect_x                                 0x8A6F50
#define CTabWnd__GetTabRect_x                                      0x8A6E20
#define CTabWnd__InsertPage_x                                      0x8A7D20
#define CTabWnd__SetPage_x                                         0x8A76A0
#define CTabWnd__SetPageRect_x                                     0x8A7970
#define CTabWnd__UpdatePage_x                                      0x8A7CC0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x41FC10

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8A3E20

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8ACC50

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x86B740

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4112E0
#define CXStr__CXStr1_x                                            0x860E40
#define CXStr__CXStr3_x                                            0x822DB0
#define CXStr__dCXStr_x                                            0x768DB0
#define CXStr__operator_equal_x                                    0x822F20
#define CXStr__operator_equal1_x                                   0x822F70
#define CXStr__operator_plus_equal1_x                              0x824050

// CXWnd 
#define CXWnd__BringToTop_x                                        0x87CD80
#define CXWnd__Center_x                                            0x882F10
#define CXWnd__ClrFocus_x                                          0x87C970
#define CXWnd__DoAllDrawing_x                                      0x882B90
#define CXWnd__DrawChildren_x                                      0x882D10
#define CXWnd__DrawColoredRect_x                                   0x87D130
#define CXWnd__DrawTooltip_x                                       0x87D3D0
#define CXWnd__DrawTooltipAtPoint_x                                0x881B20
#define CXWnd__GetBorderFrame_x                                    0x87D820
#define CXWnd__GetChildWndAt_x                                     0x880AE0
#define CXWnd__GetClientClipRect_x                                 0x87D5E0
#define CXWnd__GetScreenClipRect_x                                 0x882220
#define CXWnd__GetScreenRect_x                                     0x87D9D0
#define CXWnd__GetTooltipRect_x                                    0x87D260
#define CXWnd__GetWindowTextA_x                                    0x411320
#define CXWnd__IsActive_x                                          0x8900D0
#define CXWnd__IsDescendantOf_x                                    0x87D770
#define CXWnd__IsReallyVisible_x                                   0x880AC0
#define CXWnd__IsType_x                                            0x8A9450
#define CXWnd__Move_x                                              0x8801C0
#define CXWnd__Move1_x                                             0x882840
#define CXWnd__ProcessTransition_x                                 0x87CD30
#define CXWnd__Refade_x                                            0x87CB10
#define CXWnd__Resize_x                                            0x87DA90
#define CXWnd__Right_x                                             0x882020
#define CXWnd__SetFocus_x                                          0x87F350
#define CXWnd__SetFont_x                                           0x87C9C0
#define CXWnd__SetKeyTooltip_x                                     0x87DD00
#define CXWnd__SetMouseOver_x                                      0x882550
#define CXWnd__StartFade_x                                         0x87CDD0
#define CXWnd__GetChildItem_x                                      0x882490

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8919D0
#define CXWndManager__DrawWindows_x                                0x891620
#define CXWndManager__GetKeyboardFlags_x                           0x88FC40
#define CXWndManager__HandleKeyboardMsg_x                          0x890560
#define CXWndManager__RemoveWnd_x                                  0x890260

// CDBStr
#define CDBStr__GetString_x                                        0x486DC0

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8DEEC0
#define EQ_Character__CastSpell_x                                  0x43ACA0
#define EQ_Character__Cur_HP_x                                     0x44A340
#define EQ_Character__GetAACastingTimeModifier_x                   0x433B20
#define EQ_Character__GetCharInfo2_x                               0x7F7770
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42CD90
#define EQ_Character__GetFocusRangeModifier_x                      0x42CF70
#define EQ_Character__Max_Endurance_x                              0x589120
#define EQ_Character__Max_HP_x                                     0x4444B0
#define EQ_Character__Max_Mana_x                                   0x588F60
#define EQ_Character__doCombatAbility_x                            0x587A70
#define EQ_Character__UseSkill_x                                   0x45B7F0
#define EQ_Character__GetConLevel_x                                0x57EC60
#define EQ_Character__IsExpansionFlag_x                            0x410810
#define EQ_Character__TotalEffect_x                                0x438E00

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x55BBA0
#define EQ_Item__CreateItemTagString_x                             0x7D7560
#define EQ_Item__IsStackable_x                                     0x7CBC00

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A64B0
#define EQ_LoadingS__Array_x                                       0xAD92C8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x58D720
#define EQ_PC__GetAltAbilityIndex_x                                0x7E0130
#define EQ_PC__GetCombatAbility_x                                  0x7E01C0
#define EQ_PC__GetCombatAbilityTimer_x                             0x7E0270
#define EQ_PC__GetItemTimerValue_x                                 0x5877B0
#define EQ_PC__HasLoreItem_x                                       0x581E10

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E1180
#define EQItemList__add_item_x                                     0x4E10C0
#define EQItemList__delete_item_x                                  0x4E1580
#define EQItemList__FreeItemList_x                                 0x4E1480

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x486260

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x593470
#define EQPlayer__dEQPlayer_x                                      0x5980E0
#define EQPlayer__DoAttack_x                                       0x5AC720
#define EQPlayer__EQPlayer_x                                       0x59D8D0
#define EQPlayer__SetNameSpriteState_x                             0x5958F0
#define EQPlayer__SetNameSpriteTint_x                              0x5934E0
#define EQPlayer__IsBodyType_j_x                                   0x8DE730
#define EQPlayer__IsTargetable_x                                   0x8DEA00

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5A0DD0
#define EQPlayerManager__GetSpawnByName_x                          0x5A1230

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x561D50
#define KeypressHandler__AttachKeyToEqCommand_x                    0x561D90
#define KeypressHandler__ClearCommandStateArray_x                  0x561930
#define KeypressHandler__HandleKeyDown_x                           0x560290
#define KeypressHandler__HandleKeyUp_x                             0x5605B0
#define KeypressHandler__SaveKeymapping_x                          0x561A00

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6D08D0
#define MapViewMap__SaveEx_x                                       0x6D41B0

#define PlayerPointManager__GetAltCurrency_x                       0x7F18A0

// StringTable 
#define StringTable__getString_x                                   0x7ECBB0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x58C020

//Doors
#define EQSwitch__UseSwitch_x					   0x5183E0
