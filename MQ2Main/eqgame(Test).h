adv/******************************************************************************
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
#include "eqgame-private(Test).h"
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Apr 15 2015"
#define __ExpectedVersionTime                                     "10:44:19"
#define __ActualVersionDate_x                                      0xA7BD80
#define __ActualVersionTime_x                                      0xA7BD8C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5936B0
#define __MemChecker1_x                                            0x85C0F0
#define __MemChecker2_x                                            0x62AF10
#define __MemChecker3_x                                            0x62AE60
#define __MemChecker4_x                                            0x7DFA80
#define __EncryptPad0_x                                            0xBF7D80
#define __EncryptPad1_x                                            0xD7CA00
#define __EncryptPad2_x                                            0xC40EB0
#define __EncryptPad3_x                                            0xC40AB0
#define __EncryptPad4_x                                            0xD59008
#define __AC1_x                                                    0x79CFF5
#define __AC2_x                                                    0x549487
#define __AC3_x                                                    0x55DC80
#define __AC4_x                                                    0x5640C0
#define __AC5_x                                                    0x56FEDE
#define __AC6_x                                                    0x5739A2
#define __AC7_x                                                    0x56A58C
#define __AC1_Data                                                 0x11111111

// Direct Input
#define DI8__Main_x                                                0x112E840
#define DI8__Keyboard_x                                            0x112E844
#define DI8__Mouse_x                                               0x112E848
#define __AltTimerReady_x                                          0xF8E1B1
#define __Attack_x                                                 0x10213CF
#define __Autofire_x                                               0x10213D0
#define __BindList_x                                               0xBBA640
#define __bCommandEnabled_x                                        0xF8C2C0
#define __Clicks_x                                                 0xF9CF20
#define __CommandList_x                                            0xBBE920
#define __CurrentMapLabel_x                                        0x1134298
#define __CurrentSocial_x                                          0xB77A44
#define __DoAbilityList_x                                          0xFD3684
#define __do_loot_x                                                0x510E70
#define __DrawHandler_x                                            0x1798EA4
#define __GroupCount_x                                             0xF8D88A

#define __Guilds_x                                                 0xF934A0
#define __gWorld_x                                                 0xF8FD44
#define __HotkeyPage_x                                             0x101A084
#define __HWnd_x                                                   0x1026748
#define __InChatMode_x                                             0xF9CE4C
#define __LastTell_x                                               0xF9ED8C
#define __LMouseHeldTime_x                                         0xF9CF8C
#define __Mouse_x                                                  0x112E84C
#define __MouseLook_x                                              0xF9CEE6
#define __MouseEventTime_x                                         0x1021BD4
#define __NetStatusToggle_x                                        0xF9CEE9
#define __PCNames_x                                                0xF9E3AC
#define __RangeAttackReady_x                                       0xF9E070
#define __RMouseHeldTime_x                                         0xF9CF88
#define __RunWalkState_x                                           0xF9CE50
#define __ScreenMode_x                                             0xEDC178
#define __ScreenX_x                                                0xF9CE04
#define __ScreenY_x                                                0xF9CE00
#define __ScreenXMax_x                                             0xF9CE08
#define __ScreenYMax_x                                             0xF9CE0C
#define __ServerHost_x                                             0xF8D7D4
#define __ServerName_x                                             0xFD3644
#define __ShiftKeyDown_x                                           0xF9D4F4
#define __ShowNames_x                                              0xF9E244
#define __Socials_x                                                0xFD3744
#define __SubscriptionType_x                                       0x1160628
#define __TargetAggroHolder_x                                      0x11364D4
#define __GroupAggro_x                                             0x1136514
#define __LoginName_x                                              0x1025320
#define __Inviter_x                                                0x102134C


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF8FE30
#define instEQZoneInfo_x                                           0xF9D0DC
#define instKeypressHandler_x                                      0x1021BB8
#define pinstActiveBanker_x                                        0xF8FDE8
#define pinstActiveCorpse_x                                        0xF8FDEC
#define pinstActiveGMaster_x                                       0xF8FDF0
#define pinstActiveMerchant_x                                      0xF8FDE4
#define pinstAggroInfo_x                                           0xDA05F8
#define pinstAltAdvManager_x                                       0xEDD260
#define pinstAuraMgr_x                                             0xDAA4C0
#define pinstBandageTarget_x                                       0xF8FDD0
#define pinstCamActor_x                                            0xEDCB68
#define pinstCDBStr_x                                              0xEDC10C
#define pinstCDisplay_x                                            0xF8FDF8
#define pinstCEverQuest_x                                          0x112E9C0
#define pinstCharData_x                                            0xF8FDB4
#define pinstCharSpawn_x                                           0xF8FDDC
#define pinstControlledMissile_x                                   0xF8FDB0
#define pinstControlledPlayer_x                                    0xF8FDDC
#define pinstCSidlManager_x                                        0x17982DC
#define pinstCXWndManager_x                                        0x17982D4
#define instDynamicZone_x                                          0xF9CC98
#define pinstDZMember_x                                            0xF9CDA8
#define pinstDZTimerInfo_x                                         0xF9CDAC
#define pinstEQItemList_x                                          0xF8C510
#define instEQMisc_x                                               0xB982C8
#define pinstEQSoundManager_x                                      0xEDD658
#define instExpeditionLeader_x                                     0xF9CCE2
#define instExpeditionName_x                                       0xF9CD22
#define pinstGroup_x                                               0xF8D886
#define pinstImeManager_x                                          0x17982E0
#define pinstLocalPlayer_x                                         0xF8FDC8
#define pinstMercenaryData_x                                       0x1022208
#define pinstMercAltAbilities_x                                    0xEDD574
#define pinstModelPlayer_x                                         0xF8FDF4
#define pinstPCData_x                                              0xF8FDB4
#define pinstSkillMgr_x                                            0x1023040
#define pinstSpawnManager_x                                        0x1022928
#define pinstSpellManager_x                                        0x1023188
#define pinstSpellSets_x                                           0x101A0E8
#define pinstStringTable_x                                         0xF8FD5C
#define pinstSwitchManager_x                                       0xF8D418
#define pinstTarget_x                                              0xF8FDE0
#define pinstTargetObject_x                                        0xF8FDB8
#define pinstTargetSwitch_x                                        0xF8FDBC
#define pinstTaskMember_x                                          0xEDC058
#define pinstTrackTarget_x                                         0xF8FDD4
#define pinstTradeTarget_x                                         0xF8FDC4
#define instTributeActive_x                                        0xB982ED
#define pinstViewActor_x                                           0xEDCB64
#define pinstWorldData_x                                           0xF8FD98


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xDA0AD8
#define pinstCAudioTriggersWindow_x                                0xDA0968
#define pinstCCharacterSelect_x                                    0xEDCA08
#define pinstCFacePick_x                                           0xEDC9B8
#define pinstCNoteWnd_x                                            0xEDC9C0
#define pinstCBookWnd_x                                            0xEDC9C8
#define pinstCPetInfoWnd_x                                         0xEDC9CC
#define pinstCTrainWnd_x                                           0xEDC9D0
#define pinstCSkillsWnd_x                                          0xEDC9D4
#define pinstCSkillsSelectWnd_x                                    0xEDC9D8
#define pinstCCombatSkillSelectWnd_x                               0xEDC9DC
#define pinstCFriendsWnd_x                                         0xEDC9E0
#define pinstCAuraWnd_x                                            0xEDC9E4
#define pinstCRespawnWnd_x                                         0xEDC9E8
#define pinstCBandolierWnd_x                                       0xEDC9EC
#define pinstCPotionBeltWnd_x                                      0xEDC9F0
#define pinstCAAWnd_x                                              0xEDC9F4
#define pinstCGroupSearchFiltersWnd_x                              0xEDC9F8
#define pinstCLoadskinWnd_x                                        0xEDC9FC
#define pinstCAlarmWnd_x                                           0xEDCA00
#define pinstCMusicPlayerWnd_x                                     0xEDCA04
#define pinstCMailWnd_x                                            0xEDCA0C
#define pinstCMailCompositionWnd_x                                 0xEDCA10
#define pinstCMailAddressBookWnd_x                                 0xEDCA14
#define pinstCRaidWnd_x                                            0xEDCA1C
#define pinstCRaidOptionsWnd_x                                     0xEDCA20
#define pinstCBreathWnd_x                                          0xEDCA24
#define pinstCMapViewWnd_x                                         0xEDCA28
#define pinstCMapToolbarWnd_x                                      0xEDCA2C
#define pinstCEditLabelWnd_x                                       0xEDCA30
#define pinstCTargetWnd_x                                          0xEDCA34
#define pinstCColorPickerWnd_x                                     0xEDCA38
#define pinstCPlayerWnd_x                                          0xEDCA3C
#define pinstCOptionsWnd_x                                         0xEDCA40
#define pinstCBuffWindowNORMAL_x                                   0xEDCA44
#define pinstCBuffWindowSHORT_x                                    0xEDCA48
#define pinstCharacterCreation_x                                   0xEDCA4C
#define pinstCCursorAttachment_x                                   0xEDCA50
#define pinstCCastingWnd_x                                         0xEDCA54
#define pinstCCastSpellWnd_x                                       0xEDCA58
#define pinstCSpellBookWnd_x                                       0xEDCA5C
#define pinstCInventoryWnd_x                                       0xEDCA60
#define pinstCBankWnd_x                                            0xEDCA64
#define pinstCQuantityWnd_x                                        0xEDCA68
#define pinstCLootWnd_x                                            0xEDCA6C
#define pinstCActionsWnd_x                                         0xEDCA70
#define pinstCCombatAbilityWnd_x                                   0xEDCA74
#define pinstCMerchantWnd_x                                        0xEDCA78
#define pinstCTradeWnd_x                                           0xEDCA7C
#define pinstCSelectorWnd_x                                        0xEDCA80
#define pinstCBazaarWnd_x                                          0xEDCA84
#define pinstCBazaarSearchWnd_x                                    0xEDCA88
#define pinstCGiveWnd_x                                            0xEDCAA4
#define pinstCTrackingWnd_x                                        0xEDCAAC
#define pinstCInspectWnd_x                                         0xEDCAB0
#define pinstCSocialEditWnd_x                                      0xEDCAB4
#define pinstCFeedbackWnd_x                                        0xEDCAB8
#define pinstCBugReportWnd_x                                       0xEDCABC
#define pinstCVideoModesWnd_x                                      0xEDCAC0
#define pinstCTextEntryWnd_x                                       0xEDCAC8
#define pinstCFileSelectionWnd_x                                   0xEDCACC
#define pinstCCompassWnd_x                                         0xEDCAD0
#define pinstCPlayerNotesWnd_x                                     0xEDCAD4
#define pinstCGemsGameWnd_x                                        0xEDCAD8
#define pinstCTimeLeftWnd_x                                        0xEDCADC
#define pinstCPetitionQWnd_x                                       0xEDCAF0
#define pinstCSoulmarkWnd_x                                        0xEDCAF4
#define pinstCStoryWnd_x                                           0xEDCAF8
#define pinstCJournalTextWnd_x                                     0xEDCAFC
#define pinstCJournalCatWnd_x                                      0xEDCB00
#define pinstCBodyTintWnd_x                                        0xEDCB04
#define pinstCServerListWnd_x                                      0xEDCB08
#define pinstCAvaZoneWnd_x                                         0xEDCB14
#define pinstCBlockedBuffWnd_x                                     0xEDCB18
#define pinstCBlockedPetBuffWnd_x                                  0xEDCB1C
#define pinstCInvSlotMgr_x                                         0xEDCB5C
#define pinstCContainerMgr_x                                       0xEDCB60
#define pinstCAdventureLeaderboardWnd_x                            0x112F370
#define pinstCAdventureRequestWnd_x                                0x112F3E8
#define pinstCAltStorageWnd_x                                      0x112F6C8
#define pinstCAdventureStatsWnd_x                                  0x112F460
#define pinstCBarterMerchantWnd_x                                  0x11302B0
#define pinstCBarterSearchWnd_x                                    0x1130328
#define pinstCBarterWnd_x                                          0x11303A0
#define pinstCChatManager_x                                        0x1130A30
#define pinstCDynamicZoneWnd_x                                     0x1130EE0
#define pinstCEQMainWnd_x                                          0x1131078
#define pinstCFellowshipWnd_x                                      0x1130E74
#define pinstCFindLocationWnd_x                                    0x1131348
#define pinstCGroupSearchWnd_x                                     0x1131618
#define pinstCGroupWnd_x                                           0x1131690
#define pinstCGuildBankWnd_x                                       0x1131708
#define pinstCGuildMgmtWnd_x                                       0x11337F8
#define pinstCHotButtonWnd_x                                       0x11338C4
#define pinstCHotButtonWnd1_x                                      0x11338C4
#define pinstCHotButtonWnd2_x                                      0x11338C8
#define pinstCHotButtonWnd3_x                                      0x11338CC
#define pinstCHotButtonWnd4_x                                      0x11338F0
#define pinstCItemDisplayManager_x                                 0x1133BE8
#define pinstCItemExpTransferWnd_x                                 0x1133C64
#define pinstCLFGuildWnd_x                                         0x1133F40
#define pinstCMIZoneSelectWnd_x                                    0x1134528
#define pinstCConfirmationDialog_x                                 0x1134C30
#define pinstCPopupWndManager_x                                    0x1134C30
#define pinstCProgressionSelectionWnd_x                            0x1134D20
#define pinstCPvPStatsWnd_x                                        0x1134E10
#define pinstCSystemInfoDialogBox_x                                0x1135518
#define pinstCTaskWnd_x                                            0x11368E0
#define pinstCTaskSomething_x                                      0xDAAC00
#define pinstCTaskTemplateSelectWnd_x                              0x1136868
#define pinstCTipWndOFDAY_x                                        0x1136B38
#define pinstCTipWndCONTEXT_x                                      0x1136B3C
#define pinstCTitleWnd_x                                           0x1136BB8
#define pinstCContextMenuManager_x                                 0x179824C
#define pinstCVoiceMacroWnd_x                                      0x10237F0
#define pinstCHtmlWnd_x                                            0x10238E8
#define pinstIconCache_x                                           0x113104C
#define pinstCTradeskillWnd_x                                      0x1136CB8
#define pinstCAdvancedLootWnd_x                                    0xEDCB54
#define pinstRewardSelectionWnd_x                                  0x1135338

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x528880
#define __ConvertItemTags_x                                        0x515B00
#define __ExecuteCmd_x                                             0x500480
#define __EQGetTime_x                                              0x85C410
#define __get_melee_range_x                                        0x5071A0
#define __GetGaugeValueFromEQ_x                                    0x79BD40
#define __GetLabelFromEQ_x                                         0x79CF80
#define __ToggleMount_x                                            0x6C5530
#define __GetXTargetType_x                                         0x91A840
#define __LoadFrontEnd_x                                           0x62A5C0
#define __NewUIINI_x                                               0x79B650
#define __ProcessGameEvents_x                                      0x56C2F0
#define __ProcessMouseEvent_x                                      0x56BA90
#define CrashDetected_x                                            0x62C090
#define wwsCrashReportCheckForUploader_x                           0x7F0FE0
#define DrawNetStatus_x                                            0x5A3230
#define Util__FastTime_x                                           0x85BF60
#define Expansion_HoT_x                                            0xF9E1DC
#define __HelpPath_x                                               0x1021940
//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41ED80
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419BE0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C0A00
#define AltAdvManager__IsAbilityReady_x                            0x4C0A70
#define AltAdvManager__GetAltAbility_x                             0x4C0E30

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4647D0
#define CharacterZoneClient__MakeMeVisible_x                       0x469900

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x659D90

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x667E60

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5826D0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x682F60
#define CChatManager__InitContextMenu_x                            0x683A80

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8CC7D0
#define CContextMenu__AddMenuItem_x                                0x8CC9F0
#define CContextMenu__dCContextMenu_x                              0x8CC9E0
#define CContextMenu__RemoveMenuItem_x                             0x8CCCE0
#define CContextMenu__RemoveAllMenuItems_x                         0x8CCD00
#define CContextMenuManager__AddMenu_x                             0x8B8870
#define CContextMenuManager__RemoveMenu_x                          0x8B8BC0
#define CContextMenuManager__PopupMenu_x                           0x8B9010
#define CContextMenuManager__Flush_x                               0x8B88E0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x842BD0
#define CChatService__GetFriendName_x                              0x842BE0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x688B00
#define CChatWindow__Clear_x                                       0x6886B0
#define CChatWindow__WndNotification_x                             0x689040

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8BC760
#define CComboWnd__Draw_x                                          0x8BC970
#define CComboWnd__GetCurChoice_x                                  0x8BC530
#define CComboWnd__GetListRect_x                                   0x8BCC10
#define CComboWnd__GetTextRect_x                                   0x8BC7D0
#define CComboWnd__InsertChoice_x                                  0x8BCC80
#define CComboWnd__SetColors_x                                     0x8BC4C0
#define CComboWnd__SetChoice_x                                     0x8BC4F0
#define CComboWnd__GetItemCount_x                                  0x8BC520

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x692240
#define CContainerWnd__vftable_x                                   0xA854E0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4AED00
#define CDisplay__GetClickedActor_x                                0x4A7880
#define CDisplay__GetUserDefinedColor_x                            0x4A6140
#define CDisplay__GetWorldFilePath_x                               0x4A5590
#define CDisplay__is3dON_x                                         0x4A4960
#define CDisplay__ReloadUI_x                                       0x4BA170
#define CDisplay__WriteTextHD2_x                                   0x4AB0A0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E2E90

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D1210
#define CEditWnd__GetCharIndexPt_x                                 0x8D22B0
#define CEditWnd__GetDisplayString_x                               0x8D13C0
#define CEditWnd__GetHorzOffset_x                                  0x8D1700
#define CEditWnd__GetLineForPrintableChar_x                        0x8D1D70
#define CEditWnd__GetSelStartPt_x                                  0x8D2570
#define CEditWnd__GetSTMLSafeText_x                                0x8D18A0
#define CEditWnd__PointFromPrintableChar_x                         0x8D1E60
#define CEditWnd__SelectableCharFromPoint_x                        0x8D1FE0
#define CEditWnd__SetEditable_x                                    0x8D1870

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x549BD0
#define CEverQuest__DoTellWindow_x                                 0x54F5D0
#define CEverQuest__DropHeldItemOnGround_x                         0x558100
#define CEverQuest__dsp_chat_x                                     0x550D70
#define CEverQuest__Emote_x                                        0x550FD0
#define CEverQuest__EnterZone_x                                    0x5648E0
#define CEverQuest__GetBodyTypeDesc_x                              0x546430
#define CEverQuest__GetClassDesc_x                                 0x54C140
#define CEverQuest__GetClassThreeLetterCode_x                      0x54C740
#define CEverQuest__GetDeityDesc_x                                 0x546D10
#define CEverQuest__GetLangDesc_x                                  0x5467C0
#define CEverQuest__GetRaceDesc_x                                  0x54C900
#define CEverQuest__InterpretCmd_x                                 0x5518B0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5689F0
#define CEverQuest__LMouseUp_x                                     0x56AAE0
#define CEverQuest__RightClickedOnPlayer_x                         0x5694F0
#define CEverQuest__RMouseUp_x                                     0x56A540
#define CEverQuest__SetGameState_x                                 0x54A280
#define CEverQuest__UPCNotificationFlush_x                         0x552A50
#define CEverQuest__IssuePetCommand_x                              0x5525B0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A2EB0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A2F10
#define CGaugeWnd__Draw_x                                          0x6A3340

// CGuild
#define CGuild__FindMemberByName_x                                 0x435AE0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6BFF70

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6CDD70
#define CInvSlotMgr__MoveItem_x                                    0x6CECA0
#define CInvSlotMgr__SelectSlot_x                                  0x6CDE20

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6CD210
#define CInvSlot__SliderComplete_x                                 0x6CABE0
#define CInvSlot__GetItemBase_x                                    0x6CA050

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6CFE30

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x798860
#define CItemDisplayWnd__UpdateStrings_x                           0x6D1160

// CLabel 
#define CLabel__Draw_x                                             0x6EBF50

// CListWnd 
#define CListWnd__CListWnd_x                                       0x8A8320
#define CListWnd__dCListWnd_x                                      0x8A9340
#define CListWnd__AddColumn_x                                      0x8A92E0
#define CListWnd__AddColumn1_x                                     0x8A8B50
#define CListWnd__AddLine_x                                        0x8A85D0
#define CListWnd__AddString_x                                      0x8A87E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8A5640
#define CListWnd__CalculateVSBRange_x                              0x8A77D0
#define CListWnd__ClearAllSel_x                                    0x8A48F0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8A81B0
#define CListWnd__Compare_x                                        0x8A6150
#define CListWnd__Draw_x                                           0x8A73E0
#define CListWnd__DrawColumnSeparators_x                           0x8A7270
#define CListWnd__DrawHeader_x                                     0x8A4C00
#define CListWnd__DrawItem_x                                       0x8A67A0
#define CListWnd__DrawLine_x                                       0x8A6F10
#define CListWnd__DrawSeparator_x                                  0x8A7310
#define CListWnd__EnsureVisible_x                                  0x8A57A0
#define CListWnd__ExtendSel_x                                      0x8A66B0
#define CListWnd__GetColumnMinWidth_x                              0x8A42B0
#define CListWnd__GetColumnWidth_x                                 0x8A41D0
#define CListWnd__GetCurSel_x                                      0x8A39A0
#define CListWnd__GetItemAtPoint_x                                 0x8A5A40
#define CListWnd__GetItemAtPoint1_x                                0x8A5AB0
#define CListWnd__GetItemData_x                                    0x8A3CF0
#define CListWnd__GetItemHeight_x                                  0x8A5290
#define CListWnd__GetItemIcon_x                                    0x8A3ED0
#define CListWnd__GetItemRect_x                                    0x8A5880
#define CListWnd__GetItemText_x                                    0x8A3D80
#define CListWnd__GetSelList_x                                     0x8A8A40
#define CListWnd__GetSeparatorRect_x                               0x8A6070
#define CListWnd__RemoveLine_x                                     0x8A89C0
#define CListWnd__SetColors_x                                      0x8A3AF0
#define CListWnd__SetColumnJustification_x                         0x8A4580
#define CListWnd__SetColumnWidth_x                                 0x8A4260
#define CListWnd__SetCurSel_x                                      0x8A39E0
#define CListWnd__SetItemColor_x                                   0x8A7E90
#define CListWnd__SetItemData_x                                    0x8A49A0
#define CListWnd__SetItemText_x                                    0x8A7CD0
#define CListWnd__ShiftColumnSeparator_x                           0x8A7B60
#define CListWnd__Sort_x                                           0x8A9440
#define CListWnd__ToggleSel_x                                      0x8A4870

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7054B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7265E0
#define CMerchantWnd__RequestBuyItem_x                             0x72D410
#define CMerchantWnd__RequestSellItem_x                            0x72DE80
#define CMerchantWnd__SelectRecoverySlot_x                         0x726890
#define CMerchantWnd__SelectBuySellSlot_x                          0x725AF0
#define CMerchantWnd__ActualSelect_x                               0x72A340

// CObfuscator
#define CObfuscator__doit_x                                        0x822D70

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8C7700
#define CSidlManager__CreateLabel_x                                0x78E7F0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x651090
#define CSidlScreenWnd__CalculateVSBRange_x                        0x650FB0
#define CSidlScreenWnd__ConvertToRes_x                             0x8E2D70
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8BF3E0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C08F0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C09A0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8BFE60
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8BEDB0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8BE4F0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8BEFA0
#define CSidlScreenWnd__Init1_x                                    0x8C05D0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8BF490
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8BE6B0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C00B0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8BDFB0
#define CSidlScreenWnd__StoreIniVis_x                              0x8BE480
#define CSidlScreenWnd__WndNotification_x                          0x8C0350
#define CSidlScreenWnd__GetChildItem_x                             0x8BE5C0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B1A00

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5EC750
#define CSkillMgr__GetSkillCap_x                                   0x5EC8F0
#define CSkillMgr__GetNameToken_x                                  0x5EC3C0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E2030
#define CSliderWnd__SetValue_x                                     0x8E2200
#define CSliderWnd__SetNumTicks_x                                  0x8E2980

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x796500

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8DCA30
#define CStmlWnd__CalculateHSBRange_x                              0x8D4FE0
#define CStmlWnd__CalculateVSBRange_x                              0x8D4F50
#define CStmlWnd__CanBreakAtCharacter_x                            0x8D5160
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8D5A40
#define CStmlWnd__ForceParseNow_x                                  0x8DD380
#define CStmlWnd__GetNextTagPiece_x                                0x8D5940
#define CStmlWnd__GetSTMLText_x                                    0x687F40
#define CStmlWnd__GetVisibleText_x                                 0x8D6490
#define CStmlWnd__InitializeWindowVariables_x                      0x8D8820
#define CStmlWnd__MakeStmlColorTag_x                               0x8D4250
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D42B0
#define CStmlWnd__SetSTMLText_x                                    0x8DA090
#define CStmlWnd__StripFirstSTMLLines_x                            0x8DC6D0
#define CStmlWnd__UpdateHistoryString_x                            0x8D73D0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E4570
#define CTabWnd__DrawCurrentPage_x                                 0x8E3DE0
#define CTabWnd__DrawTab_x                                         0x8E3BA0
#define CTabWnd__GetCurrentPage_x                                  0x8E41B0
#define CTabWnd__GetPageInnerRect_x                                0x8E3890
#define CTabWnd__GetTabInnerRect_x                                 0x8E3A90
#define CTabWnd__GetTabRect_x                                      0x8E3960
#define CTabWnd__InsertPage_x                                      0x8E4860
#define CTabWnd__SetPage_x                                         0x8E41E0
#define CTabWnd__SetPageRect_x                                     0x8E44B0
#define CTabWnd__UpdatePage_x                                      0x8E4800

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431830

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8BC130

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8E97D0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A1AB0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x58FD60
#define CXStr__CXStr1_x                                            0x7D8E80
#define CXStr__CXStr3_x                                            0x858FF0
#define CXStr__dCXStr_x                                            0x8B04D0
#define CXStr__operator_equal_x                                    0x859160
#define CXStr__operator_equal1_x                                   0x8591B0
#define CXStr__operator_plus_equal1_x                              0x85A290

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B0BE0
#define CXWnd__Center_x                                            0x8B6E90
#define CXWnd__ClrFocus_x                                          0x8B07C0
#define CXWnd__DoAllDrawing_x                                      0x8B6AE0
#define CXWnd__DrawChildren_x                                      0x8B6C80

#define CXWnd__DrawColoredRect_x                                   0x8B0F90
#define CXWnd__DrawTooltip_x                                       0x8B1240
#define CXWnd__DrawTooltipAtPoint_x                                0x8B5A60
#define CXWnd__GetBorderFrame_x                                    0x8B16B0
#define CXWnd__GetChildWndAt_x                                     0x8B7850
#define CXWnd__GetClientClipRect_x                                 0x8B1460
#define CXWnd__GetScreenClipRect_x                                 0x8B6160
#define CXWnd__GetScreenRect_x                                     0x8B1890
#define CXWnd__GetTooltipRect_x                                    0x8B10D0
#define CXWnd__GetWindowTextA_x                                    0x422C70
#define CXWnd__IsActive_x                                          0x8AC160
#define CXWnd__IsDescendantOf_x                                    0x8B15F0
#define CXWnd__IsReallyVisible_x                                   0x8B4A70
#define CXWnd__IsType_x                                            0x8E5EF0
#define CXWnd__Move_x                                              0x8B4140
#define CXWnd__Move1_x                                             0x8B6780
#define CXWnd__ProcessTransition_x                                 0x8B0B80
#define CXWnd__Refade_x                                            0x8B0960
#define CXWnd__Resize_x                                            0x8B1960
#define CXWnd__Right_x                                             0x8B5F60
#define CXWnd__SetFocus_x                                          0x8B3280
#define CXWnd__SetFont_x                                           0x8B0810
#define CXWnd__SetKeyTooltip_x                                     0x8B1BD0
#define CXWnd__SetMouseOver_x                                      0x8B6480
#define CXWnd__StartFade_x                                         0x8B0C30
#define CXWnd__GetChildItem_x                                      0x8B63C0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8ADA80
#define CXWndManager__DrawWindows_x                                0x8AD6D0
#define CXWndManager__GetKeyboardFlags_x                           0x8ABC90
#define CXWndManager__HandleKeyboardMsg_x                          0x8AC600
#define CXWndManager__RemoveWnd_x                                  0x8AC2F0

// CDBStr
#define CDBStr__GetString_x                                        0x4A2D90

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44EB60
#define EQ_Character__Cur_HP_x                                     0x463EA0
#define EQ_Character__GetAACastingTimeModifier_x                   0x446CE0
#define EQ_Character__GetCharInfo2_x                               0x82D5A0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EF30
#define EQ_Character__GetFocusRangeModifier_x                      0x43F110
#define EQ_Character__Max_Endurance_x                              0x5B4E60
#define EQ_Character__Max_HP_x                                     0x45A1A0
#define EQ_Character__Max_Mana_x                                   0x5B4C90
#define EQ_Character__doCombatAbility_x                            0x5B2290
#define EQ_Character__UseSkill_x                                   0x46EAF0
#define EQ_Character__GetConLevel_x                                0x5A7870
#define EQ_Character__IsExpansionFlag_x                            0x4221B0
#define EQ_Character__TotalEffect_x                                0x44BD10

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x587EC0
#define EQ_Item__CreateItemTagString_x                             0x80CA60
#define EQ_Item__IsStackable_x                                     0x800C70
#define EQ_Item__GetImageNum_x                                     0x8038F0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C2B30
#define EQ_LoadingS__Array_x                                       0xBA5F10

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5B65F0
#define EQ_PC__GetAltAbilityIndex_x                                0x815AC0
#define EQ_PC__GetCombatAbility_x                                  0x815B50
#define EQ_PC__GetCombatAbilityTimer_x                             0x815C00
#define EQ_PC__GetItemTimerValue_x                                 0x5B0060
#define EQ_PC__HasLoreItem_x                                       0x5AABC0
#define EQ_PC__AlertInventoryChanged_x                             0x5A7840
#define EQ_PC__GetPcZoneClient_x                                   0x5D09F0
#define EQ_PC__RemoveMyAffect_x                                    0x5AF570

// EQItemList 
#define EQItemList__EQItemList_x                                   0x505170
#define EQItemList__add_item_x                                     0x5050B0
#define EQItemList__delete_item_x                                  0x505570
#define EQItemList__FreeItemList_x                                 0x505470

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A1F80

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5BBA70
#define EQPlayer__dEQPlayer_x                                      0x5C4880
#define EQPlayer__DoAttack_x                                       0x5D68B0
#define EQPlayer__EQPlayer_x                                       0x5C6CA0
#define EQPlayer__SetNameSpriteState_x                             0x5C1560
#define EQPlayer__SetNameSpriteTint_x                              0x5BCE40
#define EQPlayer__IsBodyType_j_x                                   0x916A50
#define EQPlayer__IsTargetable_x                                   0x917310
#define EQPlayer__CanSee_x                                         0x917830

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5CAFA0
#define EQPlayerManager__GetSpawnByName_x                          0x5CB400

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x58E090
#define KeypressHandler__AttachKeyToEqCommand_x                    0x58E0D0
#define KeypressHandler__ClearCommandStateArray_x                  0x58DC70
#define KeypressHandler__HandleKeyDown_x                           0x58C5D0
#define KeypressHandler__HandleKeyUp_x                             0x58C8F0
#define KeypressHandler__SaveKeymapping_x                          0x58DD40

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6FD890
#define MapViewMap__SaveEx_x                                       0x701170

#define PlayerPointManager__GetAltCurrency_x                       0x828580

// StringTable 
#define StringTable__getString_x                                   0x823010

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B4910

//Doors
#define EQSwitch__UseSwitch_x                                      0x543840

//IconCache
#define IconCache__GetIcon_x                                       0x698690

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x68F520
#define CContainerMgr__CloseContainer_x                            0x68FD40

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x75EB80

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x581180

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D5620
#define EQ_Spell__SpellAffects_x                                   0x4D56C0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D56F0
#define CharacterZoneClient__CalcAffectChange_x                    0x448000
#define CLootWnd__LootAll_x                                        0x6F3230
//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x748970
#define CTargetWnd__WndNotification_x                              0x7A3E10

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7A94F0
