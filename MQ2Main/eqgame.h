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
#define __ExpectedVersionDate                                     "Dec  3 2013"
#define __ExpectedVersionTime                                     "17:42:04"
#define __ActualVersionDate_x                                      0x9EDB70
#define __ActualVersionTime_x                                      0x9EDB7C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x56AC60
#define __MemChecker1_x                                            0x8260C0
#define __MemChecker2_x                                            0x6007D0
#define __MemChecker3_x                                            0x600720
#define __MemChecker4_x                                            0x7AED60
#define __EncryptPad0_x                                            0xAF8A20
#define __EncryptPad1_x                                            0xB7D328
#define __EncryptPad2_x                                            0xB13020
#define __EncryptPad3_x                                            0xB12C20
#define __EncryptPad4_x                                            0xB79778
#define __AC1_x                                                    0x76C475
#define __AC2_x                                                    0x51EBA7
#define __AC3_x                                                    0x531FD0
#define __AC4_x                                                    0x538034
#define __AC5_x                                                    0x5444F1
#define __AC6_x                                                    0x547FB2
#define __AC7_x                                                    0x53E00C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0xF1F0F8
#define DI8__Keyboard_x                                            0xF1F0FC
#define DI8__Mouse_x                                               0xF1F100
#define __AltTimerReady_x                                          0xD7FAB9
#define __Attack_x                                                 0xE1295A
#define __Autofire_x                                               0xE1295B
#define __BindList_x                                               0xADF970
#define __Clicks_x                                                 0xD8E7E8
#define __CommandList_x                                            0xAE1130
#define __CurrentMapLabel_x                                        0xF23A08
#define __CurrentSocial_x                                          0xAC91E0
#define __DoAbilityList_x                                          0xDC4F08
#define __do_loot_x                                                0x4ECCB0
#define __DrawHandler_x                                            0x1584B2C
#define __GroupCount_x                                             0xD7F192

#define __Guilds_x                                                 0xD84D98
#define __gWorld_x                                                 0xD8164C
#define __HotkeyPage_x                                             0xE0B908
#define __HWnd_x                                                   0xE17000
#define __InChatMode_x                                             0xD8E71C
#define __LastTell_x                                               0xD90610
#define __LMouseHeldTime_x                                         0xD8E854
#define __Mouse_x                                                  0xF1F104
#define __MouseLook_x                                              0xD8E7B6
#define __MouseEventTime_x                                         0xE12E44
#define __NetStatusToggle_x                                        0xD8E7B9
#define __PCNames_x                                                0xD8FC7C
#define __RangeAttackReady_x                                       0xD8F91C
#define __RMouseHeldTime_x                                         0xD8E850
#define __RunWalkState_x                                           0xD8E720
#define __ScreenMode_x                                             0xCCE200
#define __ScreenX_x                                                0xD8E6D4
#define __ScreenY_x                                                0xD8E6D0
#define __ScreenXMax_x                                             0xD8E6D8
#define __ScreenYMax_x                                             0xD8E6DC
#define __ServerHost_x                                             0xD7F0DC
#define __ServerName_x                                             0xDC4EC8
#define __ShiftKeyDown_x                                           0xD8EDB4
#define __ShowNames_x                                              0xD8FB24
#define __Socials_x                                                0xDC4FC8
#define __SubscriptionType_x                                       0xF4C618
#define __TargetAggroHolder_x                                      0xF25328
#define __GroupAggro_x                                             0xF25368


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xD81730
#define instEQZoneInfo_x                                           0xD8E9A4
#define instKeypressHandler_x                                      0xE12E28
#define pinstActiveBanker_x                                        0xD816F0
#define pinstActiveCorpse_x                                        0xD816F4
#define pinstActiveGMaster_x                                       0xD816F8
#define pinstActiveMerchant_x                                      0xD816EC
#define pinstAggroInfo_x                                           0xB92EE0
#define pinstAltAdvManager_x                                       0xCCF1E8
#define pinstAuraMgr_x                                             0xB9C950
#define pinstBandageTarget_x                                       0xD816D8
#define pinstCamActor_x                                            0xCCEBD4
#define pinstCDBStr_x                                              0xCCE1C0
#define pinstCDisplay_x                                            0xD81700
#define pinstCEverQuest_x                                          0xF1F27C
#define pinstCharData_x                                            0xD816BC
#define pinstCharSpawn_x                                           0xD816E4
#define pinstControlledMissile_x                                   0xD816B8
#define pinstControlledPlayer_x                                    0xD816E4
#define pinstCSidlManager_x                                        0x15841E0
#define pinstCXWndManager_x                                        0x15841D8
#define instDynamicZone_x                                          0xD8E570
#define pinstDZMember_x                                            0xD8E680
#define pinstDZTimerInfo_x                                         0xD8E684
#define pinstEQItemList_x                                          0xD7E0D8
#define instEQMisc_x                                               0xAD2A00
#define pinstEQSoundManager_x                                      0xCCF380
#define instExpeditionLeader_x                                     0xD8E5BA
#define instExpeditionName_x                                       0xD8E5FA
#define pinstGroup_x                                               0xD7F18E
#define pinstImeManager_x                                          0x15841E4
#define pinstLocalPlayer_x                                         0xD816D0
#define pinstMercenaryData_x                                       0xE13368
#define pinstMercAltAbilities_x                                    0xCCF2FC
#define pinstModelPlayer_x                                         0xD816FC
#define pinstPCData_x                                              0xD816BC
#define pinstSkillMgr_x                                            0xE13C60
#define pinstSpawnManager_x                                        0xE13788
#define pinstSpellManager_x                                        0xE13D20
#define pinstSpellSets_x                                           0xE0B96C
#define pinstStringTable_x                                         0xD81664
#define pinstSwitchManager_x                                       0xD7ED78
#define pinstTarget_x                                              0xD816E8
#define pinstTargetObject_x                                        0xD816C0
#define pinstTargetSwitch_x                                        0xD816C4
#define pinstTaskMember_x                                          0xCCE148
#define pinstTrackTarget_x                                         0xD816DC
#define pinstTradeTarget_x                                         0xD816CC
#define instTributeActive_x                                        0xAD2A25
#define pinstViewActor_x                                           0xCCEBD0
#define pinstWorldData_x                                           0xD816A0


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xB931D0
#define pinstCAudioTriggersWindow_x                                0xB930F0
#define pinstCCharacterSelect_x                                    0xCCEA7C
#define pinstCFacePick_x                                           0xCCE82C
#define pinstCNoteWnd_x                                            0xCCEA34
#define pinstCBookWnd_x                                            0xCCEA3C
#define pinstCPetInfoWnd_x                                         0xCCEA40
#define pinstCTrainWnd_x                                           0xCCEA44
#define pinstCSkillsWnd_x                                          0xCCEA48
#define pinstCSkillsSelectWnd_x                                    0xCCEA4C
#define pinstCCombatSkillSelectWnd_x                               0xCCEA50
#define pinstCFriendsWnd_x                                         0xCCEA54
#define pinstCAuraWnd_x                                            0xCCEA58
#define pinstCRespawnWnd_x                                         0xCCEA5C
#define pinstCBandolierWnd_x                                       0xCCEA60
#define pinstCPotionBeltWnd_x                                      0xCCEA64
#define pinstCAAWnd_x                                              0xCCEA68
#define pinstCGroupSearchFiltersWnd_x                              0xCCEA6C
#define pinstCLoadskinWnd_x                                        0xCCEA70
#define pinstCAlarmWnd_x                                           0xCCEA74
#define pinstCMusicPlayerWnd_x                                     0xCCEA78
#define pinstCMailWnd_x                                            0xCCEA80
#define pinstCMailCompositionWnd_x                                 0xCCEA84
#define pinstCMailAddressBookWnd_x                                 0xCCEA88
#define pinstCRaidWnd_x                                            0xCCEA90
#define pinstCRaidOptionsWnd_x                                     0xCCEA94
#define pinstCBreathWnd_x                                          0xCCEA98
#define pinstCMapViewWnd_x                                         0xCCEA9C
#define pinstCMapToolbarWnd_x                                      0xCCEAA0
#define pinstCEditLabelWnd_x                                       0xCCEAA4
#define pinstCTargetWnd_x                                          0xCCEAA8
#define pinstCColorPickerWnd_x                                     0xCCEAAC
#define pinstCPlayerWnd_x                                          0xCCEAB0
#define pinstCOptionsWnd_x                                         0xCCEAB4
#define pinstCBuffWindowNORMAL_x                                   0xCCEAB8
#define pinstCBuffWindowSHORT_x                                    0xCCEABC
#define pinstCharacterCreation_x                                   0xCCEAC0
#define pinstCCursorAttachment_x                                   0xCCEAC4
#define pinstCCastingWnd_x                                         0xCCEAC8
#define pinstCCastSpellWnd_x                                       0xCCEACC
#define pinstCSpellBookWnd_x                                       0xCCEAD0
#define pinstCInventoryWnd_x                                       0xCCEAD4
#define pinstCBankWnd_x                                            0xCCEAD8
#define pinstCQuantityWnd_x                                        0xCCEADC
#define pinstCLootWnd_x                                            0xCCEAE0
#define pinstCActionsWnd_x                                         0xCCEAE4
#define pinstCCombatAbilityWnd_x                                   0xCCEAE8
#define pinstCMerchantWnd_x                                        0xCCEAEC
#define pinstCTradeWnd_x                                           0xCCEAF0
#define pinstCSelectorWnd_x                                        0xCCEAF4
#define pinstCBazaarWnd_x                                          0xCCEAF8
#define pinstCBazaarSearchWnd_x                                    0xCCEAFC
#define pinstCGiveWnd_x                                            0xCCEB18
#define pinstCTrackingWnd_x                                        0xCCEB20
#define pinstCInspectWnd_x                                         0xCCEB24
#define pinstCSocialEditWnd_x                                      0xCCEB28
#define pinstCFeedbackWnd_x                                        0xCCEB2C
#define pinstCBugReportWnd_x                                       0xCCEB30
#define pinstCVideoModesWnd_x                                      0xCCEB34
#define pinstCTextEntryWnd_x                                       0xCCEB3C
#define pinstCFileSelectionWnd_x                                   0xCCEB40
#define pinstCCompassWnd_x                                         0xCCEB44
#define pinstCPlayerNotesWnd_x                                     0xCCEB48
#define pinstCGemsGameWnd_x                                        0xCCEB4C
#define pinstCTimeLeftWnd_x                                        0xCCEB50
#define pinstCPetitionQWnd_x                                       0xCCEB64
#define pinstCSoulmarkWnd_x                                        0xCCEB68
#define pinstCStoryWnd_x                                           0xCCEB6C
#define pinstCJournalTextWnd_x                                     0xCCEB70
#define pinstCJournalCatWnd_x                                      0xCCEB74
#define pinstCBodyTintWnd_x                                        0xCCEB78
#define pinstCServerListWnd_x                                      0xCCEB7C
#define pinstCAvaZoneWnd_x                                         0xCCEB88
#define pinstCBlockedBuffWnd_x                                     0xCCEB8C
#define pinstCBlockedPetBuffWnd_x                                  0xCCEB90
#define pinstCInvSlotMgr_x                                         0xCCEBC8
#define pinstCContainerMgr_x                                       0xCCEBCC
#define pinstCAdventureLeaderboardWnd_x                            0xF1FC80
#define pinstCAdventureRequestWnd_x                                0xF1FCD0
#define pinstCAltStorageWnd_x                                      0xF1FEA0
#define pinstCAdventureStatsWnd_x                                  0xF1FD20
#define pinstCBarterMerchantWnd_x                                  0xF20580
#define pinstCBarterSearchWnd_x                                    0xF205D0
#define pinstCBarterWnd_x                                          0xF20620
#define pinstCChatManager_x                                        0xF20A20
#define pinstCDynamicZoneWnd_x                                     0xF20D00
#define pinstCEQMainWnd_x                                          0xF20E08
#define pinstCFellowshipWnd_x                                      0xF20CC4
#define pinstCFindLocationWnd_x                                    0xF20FC8
#define pinstCGroupSearchWnd_x                                     0xF211D0
#define pinstCGroupWnd_x                                           0xF21220
#define pinstCGuildBankWnd_x                                       0xF21270
#define pinstCGuildMgmtWnd_x                                       0xF23310
#define pinstCHotButtonWnd_x                                       0xF23384
#define pinstCHotButtonWnd1_x                                      0xF23384
#define pinstCHotButtonWnd2_x                                      0xF23388
#define pinstCHotButtonWnd3_x                                      0xF2338C
#define pinstCHotButtonWnd4_x                                      0xF233B0
#define pinstCItemDisplayManager_x                                 0xF23590
#define pinstCItemExpTransferWnd_x                                 0xF235E4
#define pinstCLFGuildWnd_x                                         0xF237F0
#define pinstCMIZoneSelectWnd_x                                    0xF23BB0
#define pinstCConfirmationDialog_x                                 0xF24000
#define pinstCPopupWndManager_x                                    0xF24000
#define pinstCProgressionSelectionWnd_x                            0xF24098
#define pinstCPvPStatsWnd_x                                        0xF24138
#define pinstCSystemInfoDialogBox_x                                0xF24588
#define pinstCTaskTemplateSelectWnd_x                              0xF255F8
#define pinstCTipWndOFDAY_x                                        0xF257B8
#define pinstCTipWndCONTEXT_x                                      0xF257BC
#define pinstCTitleWnd_x                                           0xF25808
#define pinstCContextMenuManager_x                                 0x1583DF4
#define pinstCVoiceMacroWnd_x                                      0xE14188
#define pinstCHtmlWnd_x                                            0xE14230


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x502930
#define __ConvertItemTags_x                                        0x4F27B0
#define __ExecuteCmd_x                                             0x4DC390
#define __EQGetTime_x                                              0x826C20
#define __get_melee_range_x                                        0x4E2FF0
#define __GetGaugeValueFromEQ_x                                    0x76B1A0
#define __GetLabelFromEQ_x                                         0x76C400
#define __GetXTargetType_x                                         0x8E2890
#define __LoadFrontEnd_x                                           0x5FFE80
#define __NewUIINI_x                                               0x76AAE0
#define __ProcessGameEvents_x                                      0x540150
#define CrashDetected_x                                            0x603CD0
#define DrawNetStatus_x                                            0x57A3E0
#define Util__FastTime_x                                           0x825F60
#define Expansion_HoT_x                                            0xD8FA84
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A4180
#define AltAdvManager__IsAbilityReady_x                            0x4A41F0
#define AltAdvManager__GetAltAbility_x                             0x4A45B0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x44A440

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x62F980

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x63D550

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x556430

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x658530
#define CChatManager__InitContextMenu_x                            0x659050

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x80CC60
#define CChatService__GetFriendName_x                              0x80CC70

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x65DD70
#define CChatWindow__Clear_x                                       0x65D930
#define CChatWindow__WndNotification_x                             0x65E2A0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x884D50
#define CComboWnd__Draw_x                                          0x884F20
#define CComboWnd__GetCurChoice_x                                  0x884B70
#define CComboWnd__GetListRect_x                                   0x8851C0
#define CComboWnd__GetTextRect_x                                   0x884DB0
#define CComboWnd__InsertChoice_x                                  0x885230
#define CComboWnd__SetColors_x                                     0x884B00
#define CComboWnd__SetChoice_x                                     0x884B30

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6674B0
#define CContainerWnd__vftable_x                                   0x9F7190

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x493ED0
#define CDisplay__GetClickedActor_x                                0x48BBD0
#define CDisplay__GetUserDefinedColor_x                            0x48A490
#define CDisplay__GetWorldFilePath_x                               0x489890
#define CDisplay__is3dON_x                                         0x488960
#define CDisplay__ReloadUI_x                                       0x49DEA0
#define CDisplay__WriteTextHD2_x                                   0x48F320

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8A66B0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x895670
#define CEditWnd__GetCharIndexPt_x                                 0x896690
#define CEditWnd__GetDisplayString_x                               0x895820
#define CEditWnd__GetHorzOffset_x                                  0x895B60
#define CEditWnd__GetLineForPrintableChar_x                        0x896160
#define CEditWnd__GetSelStartPt_x                                  0x896940
#define CEditWnd__GetSTMLSafeText_x                                0x895D00
#define CEditWnd__PointFromPrintableChar_x                         0x896250
#define CEditWnd__SelectableCharFromPoint_x                        0x8963D0
#define CEditWnd__SetEditable_x                                    0x895CD0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x51F2F0
#define CEverQuest__DoTellWindow_x                                 0x523C10
#define CEverQuest__DropHeldItemOnGround_x                         0x52C4D0
#define CEverQuest__dsp_chat_x                                     0x5253B0
#define CEverQuest__Emote_x                                        0x525610
#define CEverQuest__EnterZone_x                                    0x5381C0
#define CEverQuest__GetBodyTypeDesc_x                              0x51B970
#define CEverQuest__GetClassDesc_x                                 0x51B0D0
#define CEverQuest__GetClassThreeLetterCode_x                      0x51B6D0
#define CEverQuest__GetDeityDesc_x                                 0x51C280
#define CEverQuest__GetLangDesc_x                                  0x51BD00
#define CEverQuest__GetRaceDesc_x                                  0x51BFF0
#define CEverQuest__InterpretCmd_x                                 0x525EF0
#define CEverQuest__LeftClickedOnPlayer_x                          0x53C550
#define CEverQuest__LMouseUp_x                                     0x53E770
#define CEverQuest__RightClickedOnPlayer_x                         0x53D010
#define CEverQuest__RMouseUp_x                                     0x53DFC0
#define CEverQuest__SetGameState_x                                 0x51F9A0
#define CEverQuest__UPCNotificationFlush_x                         0x526E80

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x677360
#define CGaugeWnd__CalcLinesFillRect_x                             0x6773C0
#define CGaugeWnd__Draw_x                                          0x6777F0

// CGuild
#define CGuild__FindMemberByName_x                                 0x423E40

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6944D0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x69FE00
#define CInvSlotMgr__MoveItem_x                                    0x6A0D30

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x69F200
#define CInvSlot__SliderComplete_x                                 0x69D050
#define CInvSlot__GetItemBase_x                                    0x69C4D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6A1B00

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x767DD0
#define CItemDisplayWnd__UpdateStrings_x                           0x6A2E30

// CLabel 
#define CLabel__Draw_x                                             0x6BD590

// CListWnd 
#define CListWnd__AddColumn_x                                      0x873090
#define CListWnd__AddColumn1_x                                     0x872870
#define CListWnd__AddLine_x                                        0x872320
#define CListWnd__AddString_x                                      0x872530
#define CListWnd__CalculateFirstVisibleLine_x                      0x86F400
#define CListWnd__CalculateVSBRange_x                              0x871520
#define CListWnd__ClearAllSel_x                                    0x86E6B0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x871EF0
#define CListWnd__Compare_x                                        0x86FEF0
#define CListWnd__Draw_x                                           0x871180
#define CListWnd__DrawColumnSeparators_x                           0x871010
#define CListWnd__DrawHeader_x                                     0x86E9C0
#define CListWnd__DrawItem_x                                       0x870540
#define CListWnd__DrawLine_x                                       0x870CB0
#define CListWnd__DrawSeparator_x                                  0x8710B0
#define CListWnd__EnsureVisible_x                                  0x86F560
#define CListWnd__ExtendSel_x                                      0x870450
#define CListWnd__GetColumnMinWidth_x                              0x86E0D0
#define CListWnd__GetColumnWidth_x                                 0x86DFF0
#define CListWnd__GetCurSel_x                                      0x86D8D0
#define CListWnd__GetItemAtPoint_x                                 0x86F7F0
#define CListWnd__GetItemAtPoint1_x                                0x86F860
#define CListWnd__GetItemData_x                                    0x86DB10
#define CListWnd__GetItemHeight_x                                  0x86F050
#define CListWnd__GetItemIcon_x                                    0x86DCF0
#define CListWnd__GetItemRect_x                                    0x86F630
#define CListWnd__GetItemText_x                                    0x86DBA0
#define CListWnd__GetSelList_x                                     0x872760
#define CListWnd__GetSeparatorRect_x                               0x86FE10
#define CListWnd__RemoveLine_x                                     0x872710
#define CListWnd__SetColors_x                                      0x86D930
#define CListWnd__SetColumnJustification_x                         0x86E3A0
#define CListWnd__SetColumnWidth_x                                 0x86E080
#define CListWnd__SetCurSel_x                                      0x86D910
#define CListWnd__SetItemColor_x                                   0x871BD0
#define CListWnd__SetItemData_x                                    0x86E760
#define CListWnd__SetItemText_x                                    0x871A10
#define CListWnd__ShiftColumnSeparator_x                           0x8718A0
#define CListWnd__Sort_x                                           0x8731F0
#define CListWnd__ToggleSel_x                                      0x86E630

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6D8390

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6F8100
#define CMerchantWnd__RequestBuyItem_x                             0x6FE6B0
#define CMerchantWnd__RequestSellItem_x                            0x725960
#define CMerchantWnd__SelectBuySellSlot_x                          0x6F83B0

// CObfuscator
#define CObfuscator__doit_x                                        0x7EC8D0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x88A4B0
#define CSidlManager__CreateLabel_x                                0x75E4A0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x626AD0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x626A00
#define CSidlScreenWnd__ConvertToRes_x                             0x8A6590
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
#define CSkillMgr__IsAvailable_x                                   0x5C1FE0
#define CSkillMgr__GetSkillCap_x                                   0x5C2060

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8B04F0
#define CSliderWnd__SetValue_x                                     0x8B06C0
#define CSliderWnd__SetNumTicks_x                                  0x8B0E40

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x765890

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8A0CC0
#define CStmlWnd__CalculateHSBRange_x                              0x899330
#define CStmlWnd__CalculateVSBRange_x                              0x8993B0
#define CStmlWnd__CanBreakAtCharacter_x                            0x899530
#define CStmlWnd__FastForwardToEndOfTag_x                          0x899E10
#define CStmlWnd__ForceParseNow_x                                  0x8A1680
#define CStmlWnd__GetNextTagPiece_x                                0x899D10
#define CStmlWnd__GetSTMLText_x                                    0x65D1D0
#define CStmlWnd__GetVisibleText_x                                 0x89A860
#define CStmlWnd__InitializeWindowVariables_x                      0x89CB00
#define CStmlWnd__MakeStmlColorTag_x                               0x898510
#define CStmlWnd__MakeWndNotificationTag_x                         0x898570
#define CStmlWnd__SetSTMLText_x                                    0x89E360
#define CStmlWnd__StripFirstSTMLLines_x                            0x8A0960
#define CStmlWnd__UpdateHistoryString_x                            0x89B7A0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8A7D80
#define CTabWnd__DrawCurrentPage_x                                 0x8A75F0
#define CTabWnd__DrawTab_x                                         0x8A73B0
#define CTabWnd__GetCurrentPage_x                                  0x8A79C0
#define CTabWnd__GetPageInnerRect_x                                0x8A70A0
#define CTabWnd__GetTabInnerRect_x                                 0x8A72A0
#define CTabWnd__GetTabRect_x                                      0x8A7170
#define CTabWnd__InsertPage_x                                      0x8A8070
#define CTabWnd__SetPage_x                                         0x8A79F0
#define CTabWnd__SetPageRect_x                                     0x8A7CC0
#define CTabWnd__UpdatePage_x                                      0x8A8010

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x41F910

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8A4170

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8ACEB0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x86BA30

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x411230
#define CXStr__CXStr1_x                                            0x709160
#define CXStr__CXStr3_x                                            0x822FF0
#define CXStr__dCXStr_x                                            0x768E80
#define CXStr__operator_equal_x                                    0x823160
#define CXStr__operator_equal1_x                                   0x8231B0
#define CXStr__operator_plus_equal1_x                              0x824290

// CXWnd 
#define CXWnd__BringToTop_x                                        0x87D030
#define CXWnd__Center_x                                            0x8831C0
#define CXWnd__ClrFocus_x                                          0x87CC20
#define CXWnd__DoAllDrawing_x                                      0x882E40
#define CXWnd__DrawChildren_x                                      0x882FC0
#define CXWnd__DrawColoredRect_x                                   0x87D3E0
#define CXWnd__DrawTooltip_x                                       0x87D680
#define CXWnd__DrawTooltipAtPoint_x                                0x881DD0
#define CXWnd__GetBorderFrame_x                                    0x87DAD0
#define CXWnd__GetChildWndAt_x                                     0x880D90
#define CXWnd__GetClientClipRect_x                                 0x87D890
#define CXWnd__GetScreenClipRect_x                                 0x8824D0
#define CXWnd__GetScreenRect_x                                     0x87DC80
#define CXWnd__GetTooltipRect_x                                    0x87D510
#define CXWnd__GetWindowTextA_x                                    0x411270
#define CXWnd__IsActive_x                                          0x8903F0
#define CXWnd__IsDescendantOf_x                                    0x87DA20
#define CXWnd__IsReallyVisible_x                                   0x880D70
#define CXWnd__IsType_x                                            0x8A96F0
#define CXWnd__Move_x                                              0x880470
#define CXWnd__Move1_x                                             0x882AF0
#define CXWnd__ProcessTransition_x                                 0x87CFE0
#define CXWnd__Refade_x                                            0x87CDC0
#define CXWnd__Resize_x                                            0x87DD40
#define CXWnd__Right_x                                             0x8822D0
#define CXWnd__SetFocus_x                                          0x87F600
#define CXWnd__SetFont_x                                           0x87CC70
#define CXWnd__SetKeyTooltip_x                                     0x87DFB0
#define CXWnd__SetMouseOver_x                                      0x882800
#define CXWnd__StartFade_x                                         0x87D080
#define CXWnd__GetChildItem_x                                      0x882740

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x891CF0
#define CXWndManager__DrawWindows_x                                0x891940
#define CXWndManager__GetKeyboardFlags_x                           0x88FF60
#define CXWndManager__HandleKeyboardMsg_x                          0x890880
#define CXWndManager__RemoveWnd_x                                  0x890580

// CDBStr
#define CDBStr__GetString_x                                        0x486B50

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8DF190
#define EQ_Character__CastSpell_x                                  0x43A980
#define EQ_Character__Cur_HP_x                                     0x44A090
#define EQ_Character__GetAACastingTimeModifier_x                   0x433800
#define EQ_Character__GetCharInfo2_x                               0x7F77D0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42CA40
#define EQ_Character__GetFocusRangeModifier_x                      0x42CC20
#define EQ_Character__Max_Endurance_x                              0x588B40
#define EQ_Character__Max_HP_x                                     0x444200
#define EQ_Character__Max_Mana_x                                   0x588980
#define EQ_Character__doCombatAbility_x                            0x587490
#define EQ_Character__UseSkill_x                                   0x45B540
#define EQ_Character__GetConLevel_x                                0x57E9B0
#define EQ_Character__IsExpansionFlag_x                            0x410770
#define EQ_Character__TotalEffect_x                                0x438AE0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x55B6B0
#define EQ_Item__CreateItemTagString_x                             0x7D75E0
#define EQ_Item__IsStackable_x                                     0x7CBC90

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A6240
#define EQ_LoadingS__Array_x                                       0xAD92F0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x58D140
#define EQ_PC__GetAltAbilityIndex_x                                0x7E00F0
#define EQ_PC__GetCombatAbility_x                                  0x7E0180
#define EQ_PC__GetCombatAbilityTimer_x                             0x7E0230
#define EQ_PC__GetItemTimerValue_x                                 0x5871D0
#define EQ_PC__HasLoreItem_x                                       0x581B60

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E0D30
#define EQItemList__add_item_x                                     0x4E0C70
#define EQItemList__delete_item_x                                  0x4E1130
#define EQItemList__FreeItemList_x                                 0x4E1030

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x486050

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x592EB0
#define EQPlayer__dEQPlayer_x                                      0x597B20
#define EQPlayer__DoAttack_x                                       0x5AC120
#define EQPlayer__EQPlayer_x                                       0x59D310
#define EQPlayer__SetNameSpriteState_x                             0x595330
#define EQPlayer__SetNameSpriteTint_x                              0x592F20
#define EQPlayer__IsBodyType_j_x                                   0x8DEA00
#define EQPlayer__IsTargetable_x                                   0x8DECD0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5A0810
#define EQPlayerManager__GetSpawnByName_x                          0x5A0C70

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x561860
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5618A0
#define KeypressHandler__ClearCommandStateArray_x                  0x561440
#define KeypressHandler__HandleKeyDown_x                           0x55FDA0
#define KeypressHandler__HandleKeyUp_x                             0x5600C0
#define KeypressHandler__SaveKeymapping_x                          0x561510

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6D07B0
#define MapViewMap__SaveEx_x                                       0x6D4090

#define PlayerPointManager__GetAltCurrency_x                       0x7F19D0

// StringTable 
#define StringTable__getString_x                                   0x7ECB70

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x58BA40

//Doors
#define EQSwitch__UseSwitch_x                                      0x517F90
