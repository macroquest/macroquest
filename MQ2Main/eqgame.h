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
#define __ExpectedVersionDate                                     "Jan 16 2013"
#define __ExpectedVersionTime                                     "16:40:39"
#define __ActualVersionDate_x                                      0x9D4B90
#define __ActualVersionTime_x                                      0x9D4B9C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x562C00
#define __MemChecker1_x                                            0x805720
#define __MemChecker2_x                                            0x5F8040
#define __MemChecker3_x                                            0x5F7F90
#define __MemChecker4_x                                            0x8C8580
#define __EncryptPad0_x                                            0xAD92F0
#define __EncryptPad1_x                                            0xB54298
#define __EncryptPad2_x                                            0xAF2250
#define __EncryptPad3_x                                            0xAF1E50
#define __EncryptPad4_x                                            0xB59A48
#define __AC1_x                                                    0x7603C5
#define __AC2_x                                                    0x517597
#define __AC3_x                                                    0x52A900
#define __AC4_x                                                    0x530974
#define __AC5_x                                                    0x53C87B
#define __AC6_x                                                    0x5401F2
#define __AC7_x                                                    0x5367AC
#define __AC1_Data                                                 0x33333333
// Direct Input
#define DI8__Main_x                                                0xDED230
#define DI8__Keyboard_x                                            0xDED234
#define DI8__Mouse_x                                               0xDED238
#define __AltTimerReady_x                                          0xD56461
#define __Attack_x                                                 0xDE8FDE
#define __Autofire_x                                               0xDE8FDF
#define __BindList_x                                               0xAC15C8
#define __Clicks_x                                                 0xD65174
#define __CommandList_x                                            0xAC2C14
#define __CurrentMapLabel_x                                        0xEF8F10
#define __CurrentSocial_x                                          0xAAC688
#define __DoAbilityList_x                                          0xD9B884
#define __do_loot_x                                                0x4E6630
#define __DrawHandler_x                                            0x155933C
#define __GroupCount_x                                             0xD55B3A

#define __Guilds_x                                                 0xD5B740
#define __gWorld_x                                                 0xD57FF4
#define __HotkeyPage_x                                             0xDE2284
#define __HWnd_x                                                   0xDECF88
#define __InChatMode_x                                             0xD650AC
#define __LastTell_x                                               0xD66F8C
#define __LMouseHeldTime_x                                         0xD651E0
#define __Mouse_x                                                  0xDED23C
#define __MouseLook_x                                              0xD65142
#define __MouseEventTime_x                                         0xDE932C
#define __NetStatusToggle_x                                        0xD65145
#define __PCNames_x                                                0xD66600
#define __RangeAttackReady_x                                       0xD6629C
#define __RMouseHeldTime_x                                         0xD651DC
#define __RunWalkState_x                                           0xD650B0
#define __ScreenMode_x                                             0xCA4F18
#define __ScreenX_x                                                0xD65064
#define __ScreenY_x                                                0xD65060
#define __ScreenXMax_x                                             0xD65068
#define __ScreenYMax_x                                             0xD6506C
#define __ServerHost_x                                             0xD55A84
#define __ServerName_x                                             0xD9B844
#define __ShiftKeyDown_x                                           0xD65738
#define __ShowNames_x                                              0xD664A8
#define __Socials_x                                                0xD9B944


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xD580D8
#define instEQZoneInfo_x                                           0xD65330
#define instKeypressHandler_x                                      0xDE9310
#define pinstActiveBanker_x                                        0xD58098
#define pinstActiveCorpse_x                                        0xD5809C
#define pinstActiveGMaster_x                                       0xD580A0
#define pinstActiveMerchant_x                                      0xD58094
#define pinstAggroInfo_x                                           0xB6B920
#define pinstAltAdvManager_x                                       0xCA5E80
#define pinstAuraMgr_x                                             0xB75108
#define pinstBandageTarget_x                                       0xD58080
#define pinstCamActor_x                                            0xCA58EC
#define pinstCDBStr_x                                              0xCA4EF0
#define pinstCDisplay_x                                            0xD580A8
#define pinstCEverQuest_x                                          0xDED3B4
#define pinstCharData_x                                            0xD58064
#define pinstCharSpawn_x                                           0xD5808C
#define pinstControlledMissile_x                                   0xD58060
#define pinstControlledPlayer_x                                    0xD5808C
#define pinstCSidlManager_x                                        0x15589A0
#define pinstCXWndManager_x                                        0x1558998
#define instDynamicZone_x                                          0xD64F18
#define pinstDZMember_x                                            0xD65028
#define pinstDZTimerInfo_x                                         0xD6502C
#define pinstEQItemList_x                                          0xD54BE0
#define instEQMisc_x                                               0xAB5630
#define pinstEQSoundManager_x                                      0xCA5F48
#define instExpeditionLeader_x                                     0xD64F62
#define instExpeditionName_x                                       0xD64FA2
#define pinstGroup_x                                               0xD55B36
#define pinstImeManager_x                                          0x15589A4
#define pinstLocalPlayer_x                                         0xD58078
#define pinstMercenaryData_x                                       0xDE9788
#define pinstModelPlayer_x                                         0xD580A4
#define pinstPCData_x                                              0xD58064
#define pinstSkillMgr_x                                            0xDE9DC8
#define pinstSpawnManager_x                                        0xDE9A28
#define pinstSpellManager_x                                        0xDE9E40
#define pinstSpellSets_x                                           0xDE22E8
#define pinstStringTable_x                                         0xD5800C
#define pinstSwitchManager_x                                       0xD55750
#define pinstTarget_x                                              0xD58090
#define pinstTargetObject_x                                        0xD58068
#define pinstTargetSwitch_x                                        0xD5806C
#define pinstTaskMember_x                                          0xCA4EA0
#define pinstTrackTarget_x                                         0xD58084
#define pinstTradeTarget_x                                         0xD58074
#define instTributeActive_x                                        0xAB5655
#define pinstViewActor_x                                           0xCA58E8
#define pinstWorldData_x                                           0xD58048


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xB6BB08
#define pinstCAudioTriggersWindow_x                                0xB6BA70
#define pinstCCharacterSelect_x                                    0xCA5794
#define pinstCFacePick_x                                           0xCA5544
#define pinstCNoteWnd_x                                            0xCA574C
#define pinstCBookWnd_x                                            0xCA5754
#define pinstCPetInfoWnd_x                                         0xCA5758
#define pinstCTrainWnd_x                                           0xCA575C
#define pinstCSkillsWnd_x                                          0xCA5760
#define pinstCSkillsSelectWnd_x                                    0xCA5764
#define pinstCCombatSkillSelectWnd_x                               0xCA5768
#define pinstCFriendsWnd_x                                         0xCA576C
#define pinstCAuraWnd_x                                            0xCA5770
#define pinstCRespawnWnd_x                                         0xCA5774
#define pinstCBandolierWnd_x                                       0xCA5778
#define pinstCPotionBeltWnd_x                                      0xCA577C
#define pinstCAAWnd_x                                              0xCA5780
#define pinstCGroupSearchFiltersWnd_x                              0xCA5784
#define pinstCLoadskinWnd_x                                        0xCA5788
#define pinstCAlarmWnd_x                                           0xCA578C
#define pinstCMusicPlayerWnd_x                                     0xCA5790
#define pinstCMailWnd_x                                            0xCA5798
#define pinstCMailCompositionWnd_x                                 0xCA579C
#define pinstCMailAddressBookWnd_x                                 0xCA57A0
#define pinstCRaidWnd_x                                            0xCA57A8
#define pinstCRaidOptionsWnd_x                                     0xCA57AC
#define pinstCBreathWnd_x                                          0xCA57B0
#define pinstCMapViewWnd_x                                         0xCA57B4
#define pinstCMapToolbarWnd_x                                      0xCA57B8
#define pinstCEditLabelWnd_x                                       0xCA57BC
#define pinstCTargetWnd_x                                          0xCA57C0
#define pinstCColorPickerWnd_x                                     0xCA57C4
#define pinstCPlayerWnd_x                                          0xCA57C8
#define pinstCOptionsWnd_x                                         0xCA57CC
#define pinstCBuffWindowNORMAL_x                                   0xCA57D0
#define pinstCBuffWindowSHORT_x                                    0xCA57D4
#define pinstCharacterCreation_x                                   0xCA57D8
#define pinstCCursorAttachment_x                                   0xCA57DC
#define pinstCCastingWnd_x                                         0xCA57E0
#define pinstCCastSpellWnd_x                                       0xCA57E4
#define pinstCSpellBookWnd_x                                       0xCA57E8
#define pinstCInventoryWnd_x                                       0xCA57EC
#define pinstCBankWnd_x                                            0xCA57F0
#define pinstCQuantityWnd_x                                        0xCA57F4
#define pinstCLootWnd_x                                            0xCA57F8
#define pinstCActionsWnd_x                                         0xCA57FC
#define pinstCCombatAbilityWnd_x                                   0xCA5800
#define pinstCMerchantWnd_x                                        0xCA5804
#define pinstCTradeWnd_x                                           0xCA5808
#define pinstCSelectorWnd_x                                        0xCA580C
#define pinstCBazaarWnd_x                                          0xCA5810
#define pinstCBazaarSearchWnd_x                                    0xCA5814
#define pinstCGiveWnd_x                                            0xCA5830
#define pinstCTrackingWnd_x                                        0xCA5838
#define pinstCInspectWnd_x                                         0xCA583C
#define pinstCSocialEditWnd_x                                      0xCA5840
#define pinstCFeedbackWnd_x                                        0xCA5844
#define pinstCBugReportWnd_x                                       0xCA5848
#define pinstCVideoModesWnd_x                                      0xCA584C
#define pinstCTextEntryWnd_x                                       0xCA5854
#define pinstCFileSelectionWnd_x                                   0xCA5858
#define pinstCCompassWnd_x                                         0xCA585C
#define pinstCPlayerNotesWnd_x                                     0xCA5860
#define pinstCGemsGameWnd_x                                        0xCA5864
#define pinstCTimeLeftWnd_x                                        0xCA5868
#define pinstCPetitionQWnd_x                                       0xCA587C
#define pinstCSoulmarkWnd_x                                        0xCA5880
#define pinstCStoryWnd_x                                           0xCA5884
#define pinstCJournalTextWnd_x                                     0xCA5888
#define pinstCJournalCatWnd_x                                      0xCA588C
#define pinstCBodyTintWnd_x                                        0xCA5890
#define pinstCServerListWnd_x                                      0xCA5894
#define pinstCAvaZoneWnd_x                                         0xCA58A0
#define pinstCBlockedBuffWnd_x                                     0xCA58A4
#define pinstCBlockedPetBuffWnd_x                                  0xCA58A8
#define pinstCInvSlotMgr_x                                         0xCA58E0
#define pinstCContainerMgr_x                                       0xCA58E4
#define pinstCAdventureLeaderboardWnd_x                            0xEF5B68
#define pinstCAdventureRequestWnd_x                                0xEF5B50
#define pinstCAltStorageWnd_x                                      0xEF5CA8
#define pinstCAdventureStatsWnd_x                                  0xEF5B68
#define pinstCBarterMerchantWnd_x                                  0xEF60E8
#define pinstCBarterSearchWnd_x                                    0xEF6100
#define pinstCBarterWnd_x                                          0xEF6138
#define pinstCChatManager_x                                        0xEF6410
#define pinstCDynamicZoneWnd_x                                     0xEF6600
#define pinstCEQMainWnd_x                                          0xEF66C0
#define pinstCFellowshipWnd_x                                      0xEF65DC
#define pinstCFindLocationWnd_x                                    0xEF67F0
#define pinstCGroupSearchWnd_x                                     0xEF6950
#define pinstCGroupWnd_x                                           0xEF6988
#define pinstCGuildBankWnd_x                                       0xEF69A0
#define pinstCGuildMgmtWnd_x                                       0xEF8A30
#define pinstCGuildTributeMasterWnd_x                              0xEFA850
#define pinstCHotButtonWnd_x                                       0xEF8A84
#define pinstCHotButtonWnd1_x                                      0xEF8A84
#define pinstCHotButtonWnd2_x                                      0xEF8A88
#define pinstCHotButtonWnd3_x                                      0xEF8A8C
#define pinstCHotButtonWnd4_x                                      0xEF8AB0
#define pinstCItemDisplayManager_x                                 0xEF8C00
#define pinstCItemExpTransferWnd_x                                 0xEF8C3C
#define pinstCLeadershipWnd_x                                      0xEF8D80
#define pinstCLFGuildWnd_x                                         0xEF8DA0
#define pinstCMIZoneSelectWnd_x                                    0xEF9040
#define pinstCAdventureMerchantWnd_x                               0xEF9308
#define pinstCConfirmationDialog_x                                 0xEF9328
#define pinstCPopupWndManager_x                                    0xEF9328
#define pinstCProgressionSelectionWnd_x                            0xEF9390
#define pinstCPvPLeaderboardWnd_x                                  0xEF93E0
#define pinstCPvPStatsWnd_x                                        0xEF9400
#define pinstCSystemInfoDialogBox_x                                0xEF96E8
#define pinstCTargetOfTargetWnd_x                                  0xEFA4CC
#define pinstCTaskSelectWnd_x                                      0xEF95A4
#define pinstCTaskTemplateSelectWnd_x                              0xEFA588
#define pinstCTaskWnd_x                                            0xEFA5D8
#define pinstCTipWndOFDAY_x                                        0xEFA6B8
#define pinstCTipWndCONTEXT_x                                      0xEFA6BC
#define pinstCTitleWnd_x                                           0xEFA6F0
#define pinstCTradeskillWnd_x                                      0xEFA74C
#define pinstCTributeBenefitWnd_x                                  0xEFA818
#define pinstCTributeMasterWnd_x                                   0xEFA850
#define pinstCContextMenuManager_x                                 0x15585B4
#define pinstCVoiceMacroWnd_x                                      0xDEA188
#define pinstCHtmlWnd_x                                            0xDEA200


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x4FBF50
#define __ConvertItemTags_x                                        0x4EBEB0
#define __ExecuteCmd_x                                             0x4D6300
#define __EQGetTime_x                                              0x806280
#define __get_melee_range_x                                        0x4DCF00
#define __GetGaugeValueFromEQ_x                                    0x75F120
#define __GetLabelFromEQ_x                                         0x760350
#define __GetXTargetType_x                                         0x8D01F0
#define __LoadFrontEnd_x                                           0x5F76F0
#define __NewUIINI_x                                               0x75EA50
#define __ProcessGameEvents_x                                      0x538880
#define CrashDetected_x                                            0x5F9D6B
#define DrawNetStatus_x                                            0x571D30
#define Util__FastTime_x                                           0x8055C0
#define Expansion_HoT_x                                            0xD66408
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A16D0
#define AltAdvManager__IsAbilityReady_x                            0x4A1710
#define AltAdvManager__GetAltAbility_x                             0x4A1AE0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x44A1E0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x626580

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x633B10

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x54E510

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x64E8C0
#define CChatManager__InitContextMenu_x                            0x64F3B0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x7EC510
#define CChatService__GetFriendName_x                              0x7EC520

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6540E0
#define CChatWindow__Clear_x                                       0x653C90
#define CChatWindow__WndNotification_x                             0x654620

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x867120
#define CComboWnd__Draw_x                                          0x867300
#define CComboWnd__GetCurChoice_x                                  0x866F40
#define CComboWnd__GetListRect_x                                   0x8675A0
#define CComboWnd__GetTextRect_x                                   0x867180
#define CComboWnd__InsertChoice_x                                  0x867610
#define CComboWnd__SetColors_x                                     0x866ED0
#define CComboWnd__SetChoice_x                                     0x866F00

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x65D6A0
#define CContainerWnd__vftable_x                                   0x9DDBE0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4916E0
#define CDisplay__GetClickedActor_x                                0x489800
#define CDisplay__GetUserDefinedColor_x                            0x4880D0
#define CDisplay__GetWorldFilePath_x                               0x4874D0
#define CDisplay__is3dON_x                                         0x4865B0
#define CDisplay__ReloadUI_x                                       0x49B6B0
#define CDisplay__WriteTextHD2_x                                   0x48CC10

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x888890

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x877A30
#define CEditWnd__GetCharIndexPt_x                                 0x878A60
#define CEditWnd__GetDisplayString_x                               0x877BE0
#define CEditWnd__GetHorzOffset_x                                  0x877F20
#define CEditWnd__GetLineForPrintableChar_x                        0x878520
#define CEditWnd__GetSelStartPt_x                                  0x878D20
#define CEditWnd__GetSTMLSafeText_x                                0x8780C0
#define CEditWnd__PointFromPrintableChar_x                         0x878610
#define CEditWnd__SelectableCharFromPoint_x                        0x878790
#define CEditWnd__SetEditable_x                                    0x878090

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x517CE0
#define CEverQuest__DoTellWindow_x                                 0x51C580
#define CEverQuest__DropHeldItemOnGround_x                         0x524E00
#define CEverQuest__dsp_chat_x                                     0x51DD20
#define CEverQuest__Emote_x                                        0x51DF80
#define CEverQuest__EnterZone_x                                    0x530B00
#define CEverQuest__GetBodyTypeDesc_x                              0x5142B0
#define CEverQuest__GetClassDesc_x                                 0x513A10
#define CEverQuest__GetClassThreeLetterCode_x                      0x514010
#define CEverQuest__GetDeityDesc_x                                 0x514BC0
#define CEverQuest__GetLangDesc_x                                  0x514640
#define CEverQuest__GetRaceDesc_x                                  0x514930
#define CEverQuest__InterpretCmd_x                                 0x51E860
#define CEverQuest__LeftClickedOnPlayer_x                          0x534D40
#define CEverQuest__LMouseUp_x                                     0x536F00
#define CEverQuest__RightClickedOnPlayer_x                         0x5357B0
#define CEverQuest__RMouseUp_x                                     0x536760
#define CEverQuest__SetGameState_x                                 0x518390
#define CEverQuest__UPCNotificationFlush_x                         0x51F7F0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x66D180
#define CGaugeWnd__CalcLinesFillRect_x                             0x66D1E0
#define CGaugeWnd__Draw_x                                          0x66D610

// CGuild
#define CGuild__FindMemberByName_x                                 0x423DF0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x68A300

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6957C0
#define CInvSlotMgr__MoveItem_x                                    0x6966F0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x694C20
#define CInvSlot__SliderComplete_x                                 0x692DB0
#define CInvSlot__GetItemBase_x                                    0x6922D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x697400

// CItemDisplayWnd
#define CItemDisplayWnd__SetSpell_x                                0x75BDF0
#define CItemDisplayWnd__UpdateStrings_x                           0x698740

// CLabel 
#define CLabel__Draw_x                                             0x6B25F0

// CListWnd 
#define CListWnd__AddColumn_x                                      0x855510
#define CListWnd__AddColumn1_x                                     0x854CF0
#define CListWnd__AddLine_x                                        0x8547A0
#define CListWnd__AddString_x                                      0x8549B0
#define CListWnd__CalculateFirstVisibleLine_x                      0x851860
#define CListWnd__CalculateVSBRange_x                              0x853990
#define CListWnd__ClearAllSel_x                                    0x850B10
#define CListWnd__CloseAndUpdateEditWindow_x                       0x854370
#define CListWnd__Compare_x                                        0x852370
#define CListWnd__Draw_x                                           0x8535F0
#define CListWnd__DrawColumnSeparators_x                           0x853480
#define CListWnd__DrawHeader_x                                     0x850E20
#define CListWnd__DrawItem_x                                       0x8529B0
#define CListWnd__DrawLine_x                                       0x853120
#define CListWnd__DrawSeparator_x                                  0x853520
#define CListWnd__EnsureVisible_x                                  0x8519C0
#define CListWnd__ExtendSel_x                                      0x8528C0
#define CListWnd__GetColumnMinWidth_x                              0x850530
#define CListWnd__GetColumnWidth_x                                 0x850450
#define CListWnd__GetCurSel_x                                      0x84FD20
#define CListWnd__GetItemAtPoint_x                                 0x851C60
#define CListWnd__GetItemAtPoint1_x                                0x851CD0
#define CListWnd__GetItemData_x                                    0x84FF60
#define CListWnd__GetItemHeight_x                                  0x8514B0
#define CListWnd__GetItemIcon_x                                    0x850140
#define CListWnd__GetItemRect_x                                    0x851AA0
#define CListWnd__GetItemText_x                                    0x84FFF0
#define CListWnd__GetSelList_x                                     0x854BE0
#define CListWnd__GetSeparatorRect_x                               0x852290
#define CListWnd__RemoveLine_x                                     0x854B90
#define CListWnd__SetColors_x                                      0x84FD80
#define CListWnd__SetColumnJustification_x                         0x850800
#define CListWnd__SetColumnWidth_x                                 0x8504E0
#define CListWnd__SetCurSel_x                                      0x84FD60
#define CListWnd__SetItemColor_x                                   0x854050
#define CListWnd__SetItemData_x                                    0x850BC0
#define CListWnd__SetItemText_x                                    0x853E90
#define CListWnd__ShiftColumnSeparator_x                           0x853D20
#define CListWnd__Sort_x                                           0x855670
#define CListWnd__ToggleSel_x                                      0x850A90

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6CD290

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6ECE70
#define CMerchantWnd__RequestBuyItem_x                             0x6F3100
#define CMerchantWnd__RequestSellItem_x                            0x719DA0
#define CMerchantWnd__SelectBuySellSlot_x                          0x6ED120

// CObfuscator
#define CObfuscator__doit_x                                        0x7CCD50

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x86C830
#define CSidlManager__CreateLabel_x                                0x752690

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x61D730
#define CSidlScreenWnd__CalculateVSBRange_x                        0x61D650
#define CSidlScreenWnd__ConvertToRes_x                             0x888770
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x85A530
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x85B840
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x85B8F0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x85ADD0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x85A010
#define CSidlScreenWnd__EnableIniStorage_x                         0x859760
#define CSidlScreenWnd__GetSidlPiece_x                             0x85A200
#define CSidlScreenWnd__Init1_x                                    0x85B510
#define CSidlScreenWnd__LoadIniInfo_x                              0x85A5E0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x859920
#define CSidlScreenWnd__LoadSidlScreen_x                           0x85B020
#define CSidlScreenWnd__StoreIniInfo_x                             0x859310
#define CSidlScreenWnd__StoreIniVis_x                              0x8596F0
#define CSidlScreenWnd__WndNotification_x                          0x85B290
#define CSidlScreenWnd__GetChildItem_x                             0x859830

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5B9320
#define CSkillMgr__GetSkillCap_x                                   0x5B9390

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x892780
#define CSliderWnd__SetValue_x                                     0x892950
#define CSliderWnd__SetNumTicks_x                                  0x8930D0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x759860

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x882F30
#define CStmlWnd__CalculateHSBRange_x                              0x87B690
#define CStmlWnd__CalculateVSBRange_x                              0x87B720
#define CStmlWnd__CanBreakAtCharacter_x                            0x87B8A0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x87C180
#define CStmlWnd__ForceParseNow_x                                  0x883880
#define CStmlWnd__GetNextTagPiece_x                                0x87C080
#define CStmlWnd__GetSTMLText_x                                    0x653530
#define CStmlWnd__GetVisibleText_x                                 0x87CBD0
#define CStmlWnd__InitializeWindowVariables_x                      0x87EDB0
#define CStmlWnd__MakeStmlColorTag_x                               0x87A8E0
#define CStmlWnd__MakeWndNotificationTag_x                         0x87A940
#define CStmlWnd__SetSTMLText_x                                    0x880620
#define CStmlWnd__StripFirstSTMLLines_x                            0x882BD0
#define CStmlWnd__UpdateHistoryString_x                            0x87DB10

// CTabWnd 
#define CTabWnd__Draw_x                                            0x889F70
#define CTabWnd__DrawCurrentPage_x                                 0x8897E0
#define CTabWnd__DrawTab_x                                         0x8895A0
#define CTabWnd__GetCurrentPage_x                                  0x889BB0
#define CTabWnd__GetPageInnerRect_x                                0x889290
#define CTabWnd__GetTabInnerRect_x                                 0x889490
#define CTabWnd__GetTabRect_x                                      0x889360
#define CTabWnd__InsertPage_x                                      0x88A260
#define CTabWnd__SetPage_x                                         0x889BE0
#define CTabWnd__SetPageRect_x                                     0x889EB0
#define CTabWnd__UpdatePage_x                                      0x88A200

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x41F960

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x886350

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x88F0F0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x84DE80

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x411200
#define CXStr__CXStr1_x                                            0x4DABA0
#define CXStr__CXStr3_x                                            0x802650
#define CXStr__dCXStr_x                                            0x41CE00
#define CXStr__operator_equal_x                                    0x8027C0
#define CXStr__operator_equal1_x                                   0x802810
#define CXStr__operator_plus_equal1_x                              0x8038F0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x85F420
#define CXWnd__Center_x                                            0x865560
#define CXWnd__ClrFocus_x                                          0x85EFF0
#define CXWnd__DoAllDrawing_x                                      0x8651F0
#define CXWnd__DrawChildren_x                                      0x865370
#define CXWnd__DrawColoredRect_x                                   0x85F7E0
#define CXWnd__DrawTooltip_x                                       0x85FA90
#define CXWnd__DrawTooltipAtPoint_x                                0x864180
#define CXWnd__GetBorderFrame_x                                    0x85FEE0
#define CXWnd__GetChildWndAt_x                                     0x863130
#define CXWnd__GetClientClipRect_x                                 0x85FCA0
#define CXWnd__GetScreenClipRect_x                                 0x864880
#define CXWnd__GetScreenRect_x                                     0x860090
#define CXWnd__GetTooltipRect_x                                    0x85F920
#define CXWnd__GetWindowTextA_x                                    0x411240
#define CXWnd__IsActive_x                                          0x8727B0
#define CXWnd__IsDescendantOf_x                                    0x85FE30
#define CXWnd__IsReallyVisible_x                                   0x863110
#define CXWnd__IsType_x                                            0x88B900
#define CXWnd__Move_x                                              0x862850
#define CXWnd__Move1_x                                             0x864EA0
#define CXWnd__ProcessTransition_x                                 0x85F3C0
#define CXWnd__Refade_x                                            0x85F1A0
#define CXWnd__Resize_x                                            0x860150
#define CXWnd__Right_x                                             0x864680
#define CXWnd__SetFocus_x                                          0x8619A0
#define CXWnd__SetFont_x                                           0x85F040
#define CXWnd__SetKeyTooltip_x                                     0x8603B0
#define CXWnd__SetMouseOver_x                                      0x864B90
#define CXWnd__StartFade_x                                         0x85F470
#define CXWnd__GetChildItem_x                                      0x864AD0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8740B0
#define CXWndManager__DrawWindows_x                                0x873D00
#define CXWndManager__GetKeyboardFlags_x                           0x872320
#define CXWndManager__HandleKeyboardMsg_x                          0x872C40
#define CXWndManager__RemoveWnd_x                                  0x872940

// CDBStr
#define CDBStr__GetString_x                                        0x484830

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8CCB50
#define EQ_Character__CastSpell_x                                  0x43A860
#define EQ_Character__Cur_HP_x                                     0x449E30
#define EQ_Character__GetAACastingTimeModifier_x                   0x4337B0
#define EQ_Character__GetCharInfo2_x                               0x7D7D20
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42CA10
#define EQ_Character__GetFocusRangeModifier_x                      0x42CBF0
#define EQ_Character__Max_Endurance_x                              0x5808E0
#define EQ_Character__Max_HP_x                                     0x443FD0
#define EQ_Character__Max_Mana_x                                   0x580720
#define EQ_Character__doCombatAbility_x                            0x57F180
#define EQ_Character__UseSkill_x                                   0x45A7B0
#define EQ_Character__GetConLevel_x                                0x576350
#define EQ_Character__IsExpansionFlag_x                            0x410750
#define EQ_Character__TotalEffect_x                                0x438A70

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x553770
#define EQ_Item__CreateItemTagString_x                             0x7B8650
#define EQ_Item__IsStackable_x                                     0x7ACDD0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A36C0
#define EQ_LoadingS__Array_x                                       0xABBB48

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x584BC0
#define EQ_PC__GetAltAbilityIndex_x                                0x7C0E20
#define EQ_PC__GetCombatAbility_x                                  0x7C0EB0
#define EQ_PC__GetCombatAbilityTimer_x                             0x7C0F60
#define EQ_PC__GetItemTimerValue_x                                 0x57EEC0
#define EQ_PC__HasLoreItem_x                                       0x5794D0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4DAC70
#define EQItemList__add_item_x                                     0x4DABB0
#define EQItemList__delete_item_x                                  0x4DB080
#define EQItemList__FreeItemList_x                                 0x4DAF70

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x483D70

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x58A780
#define EQPlayer__dEQPlayer_x                                      0x58F300
#define EQPlayer__DoAttack_x                                       0x5A3790
#define EQPlayer__EQPlayer_x                                       0x594A80
#define EQPlayer__SetNameSpriteState_x                             0x58CBB0
#define EQPlayer__SetNameSpriteTint_x                              0x58A7F0
#define EQPlayer__IsBodyType_j_x                                   0x8CC3F0
#define EQPlayer__IsTargetable_x                                   0x8CC6C0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x597F20
#define EQPlayerManager__GetSpawnByName_x                          0x598380

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x559840
#define KeypressHandler__AttachKeyToEqCommand_x                    0x559880
#define KeypressHandler__ClearCommandStateArray_x                  0x559420
#define KeypressHandler__HandleKeyDown_x                           0x557D80
#define KeypressHandler__HandleKeyUp_x                             0x5580A0
#define KeypressHandler__SaveKeymapping_x                          0x5594F0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6C56F0
#define MapViewMap__SaveEx_x                                       0x6C8FA0

#define PlayerPointManager__GetAltCurrency_x                       0x7D1E50

// StringTable 
#define StringTable__getString_x                                   0x7CCFF0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5834C0