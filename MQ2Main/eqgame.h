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
#define __ExpectedVersionDate                                     "Jan 21 2014"
#define __ExpectedVersionTime                                     "16:19:56"
#define __ActualVersionDate_x                                      0x9F7410
#define __ActualVersionTime_x                                      0x9F741C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x56A510
#define __MemChecker1_x                                            0x82A6D0
#define __MemChecker2_x                                            0x5FFD70
#define __MemChecker3_x                                            0x5FFCC0
#define __MemChecker4_x                                            0x7AE610
#define __EncryptPad0_x                                            0xB03A20
#define __EncryptPad1_x                                            0xB88570
#define __EncryptPad2_x                                            0xB1E030
#define __EncryptPad3_x                                            0xB1DC30
#define __EncryptPad4_x                                            0xB84788
#define __AC1_x                                                    0x76C235
#define __AC2_x                                                    0x51E527
#define __AC3_x                                                    0x531980
#define __AC4_x                                                    0x537990
#define __AC5_x                                                    0x543E51
#define __AC6_x                                                    0x547912
#define __AC7_x                                                    0x53D96C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0xF2A440
#define DI8__Keyboard_x                                            0xF2A444
#define DI8__Mouse_x                                               0xF2A448
#define __AltTimerReady_x                                          0xD8ADF9
#define __Attack_x                                                 0xE1DCA2
#define __Autofire_x                                               0xE1DCA3
#define __BindList_x                                               0xAEA970
#define __Clicks_x                                                 0xD99B30
#define __CommandList_x                                            0xAEC130
#define __CurrentMapLabel_x                                        0xF2ED50
#define __CurrentSocial_x                                          0xAD41E0
#define __DoAbilityList_x                                          0xDD0250
#define __do_loot_x                                                0x4EC280
#define __DrawHandler_x                                            0x158FEA4
#define __GroupCount_x                                             0xD8A4D2

#define __Guilds_x                                                 0xD900D8
#define __gWorld_x                                                 0xD8C98C
#define __HotkeyPage_x                                             0xE16C50
#define __HWnd_x                                                   0xE22348
#define __InChatMode_x                                             0xD99A5C
#define __LastTell_x                                               0xD9B958
#define __LMouseHeldTime_x                                         0xD99B9C
#define __Mouse_x                                                  0xF2A44C
#define __MouseLook_x                                              0xD99AF6
#define __MouseEventTime_x                                         0xE1E18C
#define __NetStatusToggle_x                                        0xD99AF9
#define __PCNames_x                                                0xD9AFC4
#define __RangeAttackReady_x                                       0xD9AC64
#define __RMouseHeldTime_x                                         0xD99B98
#define __RunWalkState_x                                           0xD99A60
#define __ScreenMode_x                                             0xCD9540
#define __ScreenX_x                                                0xD99A14
#define __ScreenY_x                                                0xD99A10
#define __ScreenXMax_x                                             0xD99A18
#define __ScreenYMax_x                                             0xD99A1C
#define __ServerHost_x                                             0xD8A41C
#define __ServerName_x                                             0xDD0210
#define __ShiftKeyDown_x                                           0xD9A0FC
#define __ShowNames_x                                              0xD9AE6C
#define __Socials_x                                                0xDD0310
#define __SubscriptionType_x                                       0xF57990
#define __TargetAggroHolder_x                                      0xF30670
#define __GroupAggro_x                                             0xF306B0
#define __LoginName_x                                              0xE20F20

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xD8CA70
#define instEQZoneInfo_x                                           0xD99CEC
#define instKeypressHandler_x                                      0xE1E170
#define pinstActiveBanker_x                                        0xD8CA30
#define pinstActiveCorpse_x                                        0xD8CA34
#define pinstActiveGMaster_x                                       0xD8CA38
#define pinstActiveMerchant_x                                      0xD8CA2C
#define pinstAggroInfo_x                                           0xB9E220
#define pinstAltAdvManager_x                                       0xCDA528
#define pinstAuraMgr_x                                             0xBA7C90
#define pinstBandageTarget_x                                       0xD8CA18
#define pinstCamActor_x                                            0xCD9F14
#define pinstCDBStr_x                                              0xCD9500
#define pinstCDisplay_x                                            0xD8CA40
#define pinstCEverQuest_x                                          0xF2A5C4
#define pinstCharData_x                                            0xD8C9FC
#define pinstCharSpawn_x                                           0xD8CA24
#define pinstControlledMissile_x                                   0xD8C9F8
#define pinstControlledPlayer_x                                    0xD8CA24
#define pinstCSidlManager_x                                        0x158F558
#define pinstCXWndManager_x                                        0x158F550
#define instDynamicZone_x                                          0xD998B0
#define pinstDZMember_x                                            0xD999C0
#define pinstDZTimerInfo_x                                         0xD999C4
#define pinstEQItemList_x                                          0xD89418
#define instEQMisc_x                                               0xADDA00
#define pinstEQSoundManager_x                                      0xCDA6C0
#define instExpeditionLeader_x                                     0xD998FA
#define instExpeditionName_x                                       0xD9993A
#define pinstGroup_x                                               0xD8A4CE
#define pinstImeManager_x                                          0x158F55C
#define pinstLocalPlayer_x                                         0xD8CA10
#define pinstMercenaryData_x                                       0xE1E6B0
#define pinstMercAltAbilities_x                                    0xCDA63C
#define pinstModelPlayer_x                                         0xD8CA3C
#define pinstPCData_x                                              0xD8C9FC
#define pinstSkillMgr_x                                            0xE1EFA8
#define pinstSpawnManager_x                                        0xE1EAD0
#define pinstSpellManager_x                                        0xE1F068
#define pinstSpellSets_x                                           0xE16CB4
#define pinstStringTable_x                                         0xD8C9A4
#define pinstSwitchManager_x                                       0xD8A0B8
#define pinstTarget_x                                              0xD8CA28
#define pinstTargetObject_x                                        0xD8CA00
#define pinstTargetSwitch_x                                        0xD8CA04
#define pinstTaskMember_x                                          0xCD9488
#define pinstTrackTarget_x                                         0xD8CA1C
#define pinstTradeTarget_x                                         0xD8CA0C
#define instTributeActive_x                                        0xADDA25
#define pinstViewActor_x                                           0xCD9F10
#define pinstWorldData_x                                           0xD8C9E0


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xB9E510
#define pinstCAudioTriggersWindow_x                                0xB9E430
#define pinstCCharacterSelect_x                                    0xCD9DBC
#define pinstCFacePick_x                                           0xCD9B6C
#define pinstCNoteWnd_x                                            0xCD9D74
#define pinstCBookWnd_x                                            0xCD9D7C
#define pinstCPetInfoWnd_x                                         0xCD9D80
#define pinstCTrainWnd_x                                           0xCD9D84
#define pinstCSkillsWnd_x                                          0xCD9D88
#define pinstCSkillsSelectWnd_x                                    0xCD9D8C
#define pinstCCombatSkillSelectWnd_x                               0xCD9D90
#define pinstCFriendsWnd_x                                         0xCD9D94
#define pinstCAuraWnd_x                                            0xCD9D98
#define pinstCRespawnWnd_x                                         0xCD9D9C
#define pinstCBandolierWnd_x                                       0xCD9DA0
#define pinstCPotionBeltWnd_x                                      0xCD9DA4
#define pinstCAAWnd_x                                              0xCD9DA8
#define pinstCGroupSearchFiltersWnd_x                              0xCD9DAC
#define pinstCLoadskinWnd_x                                        0xCD9DB0
#define pinstCAlarmWnd_x                                           0xCD9DB4
#define pinstCMusicPlayerWnd_x                                     0xCD9DB8
#define pinstCMailWnd_x                                            0xCD9DC0
#define pinstCMailCompositionWnd_x                                 0xCD9DC4
#define pinstCMailAddressBookWnd_x                                 0xCD9DC8
#define pinstCRaidWnd_x                                            0xCD9DD0
#define pinstCRaidOptionsWnd_x                                     0xCD9DD4
#define pinstCBreathWnd_x                                          0xCD9DD8
#define pinstCMapViewWnd_x                                         0xCD9DDC
#define pinstCMapToolbarWnd_x                                      0xCD9DE0
#define pinstCEditLabelWnd_x                                       0xCD9DE4
#define pinstCTargetWnd_x                                          0xCD9DE8
#define pinstCColorPickerWnd_x                                     0xCD9DEC
#define pinstCPlayerWnd_x                                          0xCD9DF0
#define pinstCOptionsWnd_x                                         0xCD9DF4
#define pinstCBuffWindowNORMAL_x                                   0xCD9DF8
#define pinstCBuffWindowSHORT_x                                    0xCD9DFC
#define pinstCharacterCreation_x                                   0xCD9E00
#define pinstCCursorAttachment_x                                   0xCD9E04
#define pinstCCastingWnd_x                                         0xCD9E08
#define pinstCCastSpellWnd_x                                       0xCD9E0C
#define pinstCSpellBookWnd_x                                       0xCD9E10
#define pinstCInventoryWnd_x                                       0xCD9E14
#define pinstCBankWnd_x                                            0xCD9E18
#define pinstCQuantityWnd_x                                        0xCD9E1C
#define pinstCLootWnd_x                                            0xCD9E20
#define pinstCActionsWnd_x                                         0xCD9E24
#define pinstCCombatAbilityWnd_x                                   0xCD9E28
#define pinstCMerchantWnd_x                                        0xCD9E2C
#define pinstCTradeWnd_x                                           0xCD9E30
#define pinstCSelectorWnd_x                                        0xCD9E34
#define pinstCBazaarWnd_x                                          0xCD9E38
#define pinstCBazaarSearchWnd_x                                    0xCD9E3C
#define pinstCGiveWnd_x                                            0xCD9E58
#define pinstCTrackingWnd_x                                        0xCD9E60
#define pinstCInspectWnd_x                                         0xCD9E64
#define pinstCSocialEditWnd_x                                      0xCD9E68
#define pinstCFeedbackWnd_x                                        0xCD9E6C
#define pinstCBugReportWnd_x                                       0xCD9E70
#define pinstCVideoModesWnd_x                                      0xCD9E74
#define pinstCTextEntryWnd_x                                       0xCD9E7C
#define pinstCFileSelectionWnd_x                                   0xCD9E80
#define pinstCCompassWnd_x                                         0xCD9E84
#define pinstCPlayerNotesWnd_x                                     0xCD9E88
#define pinstCGemsGameWnd_x                                        0xCD9E8C
#define pinstCTimeLeftWnd_x                                        0xCD9E90
#define pinstCPetitionQWnd_x                                       0xCD9EA4
#define pinstCSoulmarkWnd_x                                        0xCD9EA8
#define pinstCStoryWnd_x                                           0xCD9EAC
#define pinstCJournalTextWnd_x                                     0xCD9EB0
#define pinstCJournalCatWnd_x                                      0xCD9EB4
#define pinstCBodyTintWnd_x                                        0xCD9EB8
#define pinstCServerListWnd_x                                      0xCD9EBC
#define pinstCAvaZoneWnd_x                                         0xCD9EC8
#define pinstCBlockedBuffWnd_x                                     0xCD9ECC
#define pinstCBlockedPetBuffWnd_x                                  0xCD9ED0
#define pinstCInvSlotMgr_x                                         0xCD9F08
#define pinstCContainerMgr_x                                       0xCD9F0C
#define pinstCAdventureLeaderboardWnd_x                            0xF2AFC8
#define pinstCAdventureRequestWnd_x                                0xF2B018
#define pinstCAltStorageWnd_x                                      0xF2B1E8
#define pinstCAdventureStatsWnd_x                                  0xF2B068
#define pinstCBarterMerchantWnd_x                                  0xF2B8C8
#define pinstCBarterSearchWnd_x                                    0xF2B918
#define pinstCBarterWnd_x                                          0xF2B968
#define pinstCChatManager_x                                        0xF2BD68
#define pinstCDynamicZoneWnd_x                                     0xF2C048
#define pinstCEQMainWnd_x                                          0xF2C150
#define pinstCFellowshipWnd_x                                      0xF2C00C
#define pinstCFindLocationWnd_x                                    0xF2C310
#define pinstCGroupSearchWnd_x                                     0xF2C518
#define pinstCGroupWnd_x                                           0xF2C568
#define pinstCGuildBankWnd_x                                       0xF2C5B8
#define pinstCGuildMgmtWnd_x                                       0xF2E658
#define pinstCHotButtonWnd_x                                       0xF2E6CC
#define pinstCHotButtonWnd1_x                                      0xF2E6CC
#define pinstCHotButtonWnd2_x                                      0xF2E6D0
#define pinstCHotButtonWnd3_x                                      0xF2E6D4
#define pinstCHotButtonWnd4_x                                      0xF2E6F8
#define pinstCItemDisplayManager_x                                 0xF2E8D8
#define pinstCItemExpTransferWnd_x                                 0xF2E92C
#define pinstCLFGuildWnd_x                                         0xF2EB38
#define pinstCMIZoneSelectWnd_x                                    0xF2EEF8
#define pinstCConfirmationDialog_x                                 0xF2F348
#define pinstCPopupWndManager_x                                    0xF2F348
#define pinstCProgressionSelectionWnd_x                            0xF2F3E0
#define pinstCPvPStatsWnd_x                                        0xF2F480
#define pinstCSystemInfoDialogBox_x                                0xF2F8D0
#define pinstCTaskWnd_x											   0xF30990
#define pinstCTaskTemplateSelectWnd_x                              0xF30940
#define pinstCTipWndOFDAY_x                                        0xF30B00
#define pinstCTipWndCONTEXT_x                                      0xF30B04
#define pinstCTitleWnd_x                                           0xF30B50
#define pinstCContextMenuManager_x                                 0x158F16C
#define pinstCVoiceMacroWnd_x                                      0xE1F4D0
#define pinstCHtmlWnd_x                                            0xE1F578


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5020B0
#define __ConvertItemTags_x                                        0x4F1D80
#define __ExecuteCmd_x                                             0x4DBA30
#define __EQGetTime_x                                              0x82B230
#define __get_melee_range_x                                        0x4E26C0
#define __GetGaugeValueFromEQ_x                                    0x76AF60
#define __GetLabelFromEQ_x                                         0x76C1C0
#define __GetXTargetType_x                                         0x8E6F10
#define __LoadFrontEnd_x                                           0x5FF420
#define __NewUIINI_x                                               0x76A890
#define __ProcessGameEvents_x                                      0x53FAB0
#define CrashDetected_x                                            0x604C10
#define DrawNetStatus_x                                            0x579A50
#define Util__FastTime_x                                           0x82A570
#define Expansion_HoT_x                                            0xD9ADCC
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A4610
#define AltAdvManager__IsAbilityReady_x                            0x4A4680
#define AltAdvManager__GetAltAbility_x                             0x4A4A40

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x44A7C0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x62F1F0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x63CF50

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x555DD0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x657D30
#define CChatManager__InitContextMenu_x                            0x658850

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x811070
#define CChatService__GetFriendName_x                              0x811080

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x65D580
#define CChatWindow__Clear_x                                       0x65D140
#define CChatWindow__WndNotification_x                             0x65DAB0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x889380
#define CComboWnd__Draw_x                                          0x889560
#define CComboWnd__GetCurChoice_x                                  0x8891A0
#define CComboWnd__GetListRect_x                                   0x889800
#define CComboWnd__GetTextRect_x                                   0x8893E0
#define CComboWnd__InsertChoice_x                                  0x889870
#define CComboWnd__SetColors_x                                     0x889130
#define CComboWnd__SetChoice_x                                     0x889160

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x666C00
#define CContainerWnd__vftable_x                                   0xA001F0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4943A0
#define CDisplay__GetClickedActor_x                                0x48C090
#define CDisplay__GetUserDefinedColor_x                            0x48A950
#define CDisplay__GetWorldFilePath_x                               0x489D50
#define CDisplay__is3dON_x                                         0x488E20
#define CDisplay__ReloadUI_x                                       0x49E370
#define CDisplay__WriteTextHD2_x                                   0x48F7F0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8AAC90

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x899C60
#define CEditWnd__GetCharIndexPt_x                                 0x89AC70
#define CEditWnd__GetDisplayString_x                               0x899E10
#define CEditWnd__GetHorzOffset_x                                  0x89A150
#define CEditWnd__GetLineForPrintableChar_x                        0x89A740
#define CEditWnd__GetSelStartPt_x                                  0x89AF20
#define CEditWnd__GetSTMLSafeText_x                                0x89A2E0
#define CEditWnd__PointFromPrintableChar_x                         0x89A830
#define CEditWnd__SelectableCharFromPoint_x                        0x89A9B0
#define CEditWnd__SetEditable_x                                    0x89A2B0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x51EC70
#define CEverQuest__DoTellWindow_x                                 0x5235A0
#define CEverQuest__DropHeldItemOnGround_x                         0x52BE80
#define CEverQuest__dsp_chat_x                                     0x524D40
#define CEverQuest__Emote_x                                        0x524FA0
#define CEverQuest__EnterZone_x                                    0x537B20
#define CEverQuest__GetBodyTypeDesc_x                              0x51B2F0
#define CEverQuest__GetClassDesc_x                                 0x51AA50
#define CEverQuest__GetClassThreeLetterCode_x                      0x51B050
#define CEverQuest__GetDeityDesc_x                                 0x51BC00
#define CEverQuest__GetLangDesc_x                                  0x51B680
#define CEverQuest__GetRaceDesc_x                                  0x51B970
#define CEverQuest__InterpretCmd_x                                 0x525880
#define CEverQuest__LeftClickedOnPlayer_x                          0x53BEB0
#define CEverQuest__LMouseUp_x                                     0x53E0D0
#define CEverQuest__RightClickedOnPlayer_x                         0x53C970
#define CEverQuest__RMouseUp_x                                     0x53D920
#define CEverQuest__SetGameState_x                                 0x51F320
#define CEverQuest__UPCNotificationFlush_x                         0x526830

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x676CF0
#define CGaugeWnd__CalcLinesFillRect_x                             0x676D50
#define CGaugeWnd__Draw_x                                          0x677180

// CGuild
#define CGuild__FindMemberByName_x                                 0x424130

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x693DE0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x69F800
#define CInvSlotMgr__MoveItem_x                                    0x6A0740

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x69EB30
#define CInvSlot__SliderComplete_x                                 0x69C980
#define CInvSlot__GetItemBase_x                                    0x69BE00

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6A1510

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x767B60
#define CItemDisplayWnd__UpdateStrings_x                           0x6A2850

// CLabel 
#define CLabel__Draw_x                                             0x6BCF60

// CListWnd 
#define CListWnd__AddColumn_x                                      0x877680
#define CListWnd__AddColumn1_x                                     0x876E70
#define CListWnd__AddLine_x                                        0x876920
#define CListWnd__AddString_x                                      0x876B30
#define CListWnd__CalculateFirstVisibleLine_x                      0x873A50
#define CListWnd__CalculateVSBRange_x                              0x875B40
#define CListWnd__ClearAllSel_x                                    0x872D10
#define CListWnd__CloseAndUpdateEditWindow_x                       0x876500
#define CListWnd__Compare_x                                        0x874520
#define CListWnd__Draw_x                                           0x8757A0
#define CListWnd__DrawColumnSeparators_x                           0x875630
#define CListWnd__DrawHeader_x                                     0x873020
#define CListWnd__DrawItem_x                                       0x874B70
#define CListWnd__DrawLine_x                                       0x8752D0
#define CListWnd__DrawSeparator_x                                  0x8756D0
#define CListWnd__EnsureVisible_x                                  0x873BB0
#define CListWnd__ExtendSel_x                                      0x874A80
#define CListWnd__GetColumnMinWidth_x                              0x872730
#define CListWnd__GetColumnWidth_x                                 0x872650
#define CListWnd__GetCurSel_x                                      0x871F20
#define CListWnd__GetItemAtPoint_x                                 0x873E30
#define CListWnd__GetItemAtPoint1_x                                0x873EA0
#define CListWnd__GetItemData_x                                    0x872160
#define CListWnd__GetItemHeight_x                                  0x8736B0
#define CListWnd__GetItemIcon_x                                    0x872340
#define CListWnd__GetItemRect_x                                    0x873C70
#define CListWnd__GetItemText_x                                    0x8721F0
#define CListWnd__GetSelList_x                                     0x876D60
#define CListWnd__GetSeparatorRect_x                               0x874440
#define CListWnd__RemoveLine_x                                     0x876D10
#define CListWnd__SetColors_x                                      0x871F80
#define CListWnd__SetColumnJustification_x                         0x872A00
#define CListWnd__SetColumnWidth_x                                 0x8726E0
#define CListWnd__SetCurSel_x                                      0x871F60
#define CListWnd__SetItemColor_x                                   0x8761E0
#define CListWnd__SetItemData_x                                    0x872DC0
#define CListWnd__SetItemText_x                                    0x876020
#define CListWnd__ShiftColumnSeparator_x                           0x875EB0
#define CListWnd__Sort_x                                           0x8777E0
#define CListWnd__ToggleSel_x                                      0x872C90

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6D7CF0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6F7F00
#define CMerchantWnd__RequestBuyItem_x                             0x6FE480
#define CMerchantWnd__RequestSellItem_x                            0x7255F0
#define CMerchantWnd__SelectBuySellSlot_x                          0x6F81B0

// CObfuscator
#define CObfuscator__doit_x                                        0x7F0E10

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x88EA60
#define CSidlManager__CreateLabel_x                                0x75E040

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x626360
#define CSidlScreenWnd__CalculateVSBRange_x                        0x626290
#define CSidlScreenWnd__ConvertToRes_x                             0x8AAB70
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x87C6A0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x87DA30
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x87DAE0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x87CFD0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x87C180
#define CSidlScreenWnd__EnableIniStorage_x                         0x87B8F0
#define CSidlScreenWnd__GetSidlPiece_x                             0x87C370
#define CSidlScreenWnd__Init1_x                                    0x87D710
#define CSidlScreenWnd__LoadIniInfo_x                              0x87C750
#define CSidlScreenWnd__LoadIniListWnd_x                           0x87BAB0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x87D220
#define CSidlScreenWnd__StoreIniInfo_x                             0x87B460
#define CSidlScreenWnd__StoreIniVis_x                              0x87B880
#define CSidlScreenWnd__WndNotification_x                          0x87D490
#define CSidlScreenWnd__GetChildItem_x                             0x87B9C0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5C1450
#define CSkillMgr__GetSkillCap_x                                   0x5C14D0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8B4B10
#define CSliderWnd__SetValue_x                                     0x8B4CE0
#define CSliderWnd__SetNumTicks_x                                  0x8B5460

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x765810

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8A5280
#define CStmlWnd__CalculateHSBRange_x                              0x89D910
#define CStmlWnd__CalculateVSBRange_x                              0x89D990
#define CStmlWnd__CanBreakAtCharacter_x                            0x89DB10
#define CStmlWnd__FastForwardToEndOfTag_x                          0x89E3F0
#define CStmlWnd__ForceParseNow_x                                  0x8A5C40
#define CStmlWnd__GetNextTagPiece_x                                0x89E2F0
#define CStmlWnd__GetSTMLText_x                                    0x65C9D0
#define CStmlWnd__GetVisibleText_x                                 0x89EE40
#define CStmlWnd__InitializeWindowVariables_x                      0x8A10E0
#define CStmlWnd__MakeStmlColorTag_x                               0x89CAF0
#define CStmlWnd__MakeWndNotificationTag_x                         0x89CB50
#define CStmlWnd__SetSTMLText_x                                    0x8A2940
#define CStmlWnd__StripFirstSTMLLines_x                            0x8A4F20
#define CStmlWnd__UpdateHistoryString_x                            0x89FD80

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8AC360
#define CTabWnd__DrawCurrentPage_x                                 0x8ABBD0
#define CTabWnd__DrawTab_x                                         0x8AB9A0
#define CTabWnd__GetCurrentPage_x                                  0x8ABFA0
#define CTabWnd__GetPageInnerRect_x                                0x8AB690
#define CTabWnd__GetTabInnerRect_x                                 0x8AB890
#define CTabWnd__GetTabRect_x                                      0x8AB760
#define CTabWnd__InsertPage_x                                      0x8AC650
#define CTabWnd__SetPage_x                                         0x8ABFD0
#define CTabWnd__SetPageRect_x                                     0x8AC2A0
#define CTabWnd__UpdatePage_x                                      0x8AC5F0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x41FC90

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8A8750

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8B14D0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x870080

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x562E10
#define CXStr__CXStr1_x                                            0x865780
#define CXStr__CXStr3_x                                            0x827600
#define CXStr__dCXStr_x                                            0x563160
#define CXStr__operator_equal_x                                    0x827770
#define CXStr__operator_equal1_x                                   0x8277C0
#define CXStr__operator_plus_equal1_x                              0x8288A0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x881640
#define CXWnd__Center_x                                            0x887800
#define CXWnd__ClrFocus_x                                          0x881230
#define CXWnd__DoAllDrawing_x                                      0x887470
#define CXWnd__DrawChildren_x                                      0x887600
#define CXWnd__DrawColoredRect_x                                   0x8819F0
#define CXWnd__DrawTooltip_x                                       0x881C90
#define CXWnd__DrawTooltipAtPoint_x                                0x886400
#define CXWnd__GetBorderFrame_x                                    0x8820E0
#define CXWnd__GetChildWndAt_x                                     0x8853A0
#define CXWnd__GetClientClipRect_x                                 0x881EA0
#define CXWnd__GetScreenClipRect_x                                 0x886AF0
#define CXWnd__GetScreenRect_x                                     0x882290
#define CXWnd__GetTooltipRect_x                                    0x881B20
#define CXWnd__GetWindowTextA_x                                    0x411480
#define CXWnd__IsActive_x                                          0x894A10
#define CXWnd__IsDescendantOf_x                                    0x882030
#define CXWnd__IsReallyVisible_x                                   0x885380
#define CXWnd__IsType_x                                            0x8ADCD0
#define CXWnd__Move_x                                              0x884A70
#define CXWnd__Move1_x                                             0x887120
#define CXWnd__ProcessTransition_x                                 0x8815F0
#define CXWnd__Refade_x                                            0x8813D0
#define CXWnd__Resize_x                                            0x882350
#define CXWnd__Right_x                                             0x8868F0
#define CXWnd__SetFocus_x                                          0x883C00
#define CXWnd__SetFont_x                                           0x881280
#define CXWnd__SetKeyTooltip_x                                     0x8825C0
#define CXWnd__SetMouseOver_x                                      0x886E10
#define CXWnd__StartFade_x                                         0x881690
#define CXWnd__GetChildItem_x                                      0x886D60

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x896310
#define CXWndManager__DrawWindows_x                                0x895F60
#define CXWndManager__GetKeyboardFlags_x                           0x894580
#define CXWndManager__HandleKeyboardMsg_x                          0x894EB0
#define CXWndManager__RemoveWnd_x                                  0x894BA0

// CDBStr
#define CDBStr__GetString_x                                        0x487030

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8E37B0
#define EQ_Character__CastSpell_x                                  0x43ADE0
#define EQ_Character__Cur_HP_x                                     0x44A410
#define EQ_Character__GetAACastingTimeModifier_x                   0x433B20
#define EQ_Character__GetCharInfo2_x                               0x7FBBF0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42CD40
#define EQ_Character__GetFocusRangeModifier_x                      0x42CF20
#define EQ_Character__Max_Endurance_x                              0x588490
#define EQ_Character__Max_HP_x                                     0x444580
#define EQ_Character__Max_Mana_x                                   0x5882D0
#define EQ_Character__doCombatAbility_x                            0x586DE0
#define EQ_Character__UseSkill_x                                   0x45B8E0
#define EQ_Character__GetConLevel_x                                0x57E070
#define EQ_Character__IsExpansionFlag_x                            0x4109A0
#define EQ_Character__TotalEffect_x                                0x438F50

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x55B050
#define EQ_Item__CreateItemTagString_x                             0x7DBAB0
#define EQ_Item__IsStackable_x                                     0x7D0050

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A67C0
#define EQ_LoadingS__Array_x                                       0xAE42F0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x58CAB0
#define EQ_PC__GetAltAbilityIndex_x                                0x7E4620
#define EQ_PC__GetCombatAbility_x                                  0x7E46B0
#define EQ_PC__GetCombatAbilityTimer_x                             0x7E4760
#define EQ_PC__GetItemTimerValue_x                                 0x586B20
#define EQ_PC__HasLoreItem_x                                       0x581220

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E0400
#define EQItemList__add_item_x                                     0x4E0340
#define EQItemList__delete_item_x                                  0x4E0800
#define EQItemList__FreeItemList_x                                 0x4E0700

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x486550

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x592800
#define EQPlayer__dEQPlayer_x                                      0x597480
#define EQPlayer__DoAttack_x                                       0x5AB860
#define EQPlayer__EQPlayer_x                                       0x59CC70
#define EQPlayer__SetNameSpriteState_x                             0x594C90
#define EQPlayer__SetNameSpriteTint_x                              0x592870
#define EQPlayer__IsBodyType_j_x                                   0x8E3020
#define EQPlayer__IsTargetable_x                                   0x8E32F0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5A01D0
#define EQPlayerManager__GetSpawnByName_x                          0x5A0630

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x561140
#define KeypressHandler__AttachKeyToEqCommand_x                    0x561180
#define KeypressHandler__ClearCommandStateArray_x                  0x560D20
#define KeypressHandler__HandleKeyDown_x                           0x55F680
#define KeypressHandler__HandleKeyUp_x                             0x55F9A0
#define KeypressHandler__SaveKeymapping_x                          0x560DF0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6D0110
#define MapViewMap__SaveEx_x                                       0x6D39F0

#define PlayerPointManager__GetAltCurrency_x                       0x7F5DD0

// StringTable 
#define StringTable__getString_x                                   0x7F10B0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x58B3A0

//Doors
#define EQSwitch__UseSwitch_x                                      0x517850
