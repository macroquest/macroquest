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
#define __ExpectedVersionDate                                     "Jan 12 2016"
#define __ExpectedVersionTime                                     "11:46:34"
#define __ActualVersionDate_x                                      0xADA580
#define __ActualVersionTime_x                                      0xADA58C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59F5B0
#define __MemChecker1_x                                            0x8A1B60
#define __MemChecker2_x                                            0x638970
#define __MemChecker3_x                                            0x6388C0
#define __MemChecker4_x                                            0x7EDB10
#define __EncryptPad0_x                                            0xC77388
#define __EncryptPad1_x                                            0xE02508
#define __EncryptPad2_x                                            0xCC0E70
#define __EncryptPad3_x                                            0xCC0A70
#define __EncryptPad4_x                                            0xDDB5F8
#define __EncryptPad5_x                                            0x11AE3D0
#define __AC1_x                                                    0x7AAB25
#define __AC2_x                                                    0x553857
#define __AC3_x                                                    0x568410
#define __AC4_x                                                    0x56F090
#define __AC5_x                                                    0x57B84E
#define __AC6_x                                                    0x57F3F9
#define __AC7_x                                                    0x575EFC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FD27C

// Direct Input
#define DI8__Main_x                                                0x11AE3A8
#define DI8__Keyboard_x                                            0x11AE3AC
#define DI8__Mouse_x                                               0x11AE3B0
#define DI8__Mouse_Copy_x                                          0x101C9BC
#define DI8__Mouse_Check_x                                         0x10A6294
#define __AltTimerReady_x                                          0x100DD09
#define __Attack_x                                                 0x10A0F37
#define __Autofire_x                                               0x10A0F38
#define __BindList_x                                               0xC39458
#define __bCommandEnabled_x                                        0x100BE18
#define __Clicks_x                                                 0x101CA78
#define __CommandList_x                                            0xC3D7C8
#define __CurrentMapLabel_x                                        0x11B3E00
#define __CurrentSocial_x                                          0xBF05BC
#define __DoAbilityList_x                                          0x10531EC
#define __do_loot_x                                                0x51AC90
#define __DrawHandler_x                                            0x181ABB4
#define __GroupCount_x                                             0x100D3E2

#define __Guilds_x                                                 0x1012FF8
#define __gWorld_x                                                 0x100F89C
#define __HotkeyPage_x                                             0x1099BEC
#define __HWnd_x                                                   0x10A62B0
#define __InChatMode_x                                             0x101C9A4
#define __LastTell_x                                               0x101E8E8
#define __LMouseHeldTime_x                                         0x101CAE4
#define __Mouse_x                                                  0x11AE3B4
#define __MouseLook_x                                              0x101CA3E
#define __MouseEventTime_x                                         0x10A173C
#define __gpbCommandEvent_x                                        0x100F964
#define __NetStatusToggle_x                                        0x101CA41
#define __PCNames_x                                                0x101DF08
#define __RangeAttackReady_x                                       0x101DBC8
#define __RMouseHeldTime_x                                         0x101CAE0
#define __RunWalkState_x                                           0x101C9A8
#define __ScreenMode_x                                             0xF5BB48
#define __ScreenX_x                                                0x101C95C
#define __ScreenY_x                                                0x101C958
#define __ScreenXMax_x                                             0x101C960
#define __ScreenYMax_x                                             0x101C964
#define __ServerHost_x                                             0x100D32C
#define __ServerName_x                                             0x10531AC
#define __ShiftKeyDown_x                                           0x101D04C
#define __ShowNames_x                                              0x101DD9C
#define __Socials_x                                                0x10532AC
#define __SubscriptionType_x                                       0x11E2330
#define __TargetAggroHolder_x                                      0x11B603C
#define __GroupAggro_x                                             0x11B607C
#define __LoginName_x                                              0x10A4E88
#define __Inviter_x                                                0x10A0EB4


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x100F988
#define instEQZoneInfo_x                                           0x101CC34
#define instKeypressHandler_x                                      0x10A1720
#define pinstActiveBanker_x                                        0x100F940
#define pinstActiveCorpse_x                                        0x100F944
#define pinstActiveGMaster_x                                       0x100F948
#define pinstActiveMerchant_x                                      0x100F93C
#define pinstAggroInfo_x                                           0xE1DF40
#define pinstAltAdvManager_x                                       0xF5CC50
#define pinstAuraMgr_x                                             0xE29E10
#define pinstBandageTarget_x                                       0x100F928
#define pinstCamActor_x                                            0xF5C55C
#define pinstCDBStr_x                                              0xF5BADC
#define pinstCDisplay_x                                            0x100F950
#define pinstCEverQuest_x                                          0x11AE528
#define pinstCharData_x                                            0x100F90C
#define pinstCharSpawn_x                                           0x100F934
#define pinstControlledMissile_x                                   0x100F908
#define pinstControlledPlayer_x                                    0x100F934
#define pinstCSidlManager_x                                        0x181A0F4
#define pinstCXWndManager_x                                        0x181A0EC
#define instDynamicZone_x                                          0x101C7F0
#define pinstDZMember_x                                            0x101C900
#define pinstDZTimerInfo_x                                         0x101C904
#define pinstEQItemList_x                                          0x100C068
#define instEQMisc_x                                               0xC12948
#define pinstEQSoundManager_x                                      0xF5D1B0
#define instExpeditionLeader_x                                     0x101C83A
#define instExpeditionName_x                                       0x101C87A
#define pinstGroup_x                                               0x100D3DE
#define pinstImeManager_x                                          0x181A0F8
#define pinstLocalPlayer_x                                         0x100F920
#define pinstMercenaryData_x                                       0x10A1D70
#define pinstMercenaryStats_x                                      0x11B6188
#define pinstMercAltAbilities_x                                    0xF5CFDC
#define pinstModelPlayer_x                                         0x100F94C
#define pinstPCData_x                                              0x100F90C
#define pinstSkillMgr_x                                            0x10A2BA8
#define pinstSpawnManager_x                                        0x10A2490
#define pinstSpellManager_x                                        0x10A2CF0
#define pinstSpellSets_x                                           0x1099C50
#define pinstStringTable_x                                         0x100F8B4
#define pinstSwitchManager_x                                       0x100CF70
#define pinstTarget_x                                              0x100F938
#define pinstTargetObject_x                                        0x100F910
#define pinstTargetSwitch_x                                        0x100F914
#define pinstTaskMember_x                                          0xF5BA28
#define pinstTrackTarget_x                                         0x100F92C
#define pinstTradeTarget_x                                         0x100F91C
#define instTributeActive_x                                        0xC1296D
#define pinstViewActor_x                                           0xF5C558
#define pinstWorldData_x                                           0x100F8F0
#define pinstZoneAddr_x                                            0x101CEF4
#define pinstPlayerPath_x                                          0x10A24F0
#define pinstTargetIndicator_x                                     0x10A2E88
#define pinstCTargetManager_x                                      0x10A2EE8

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE1E420
#define pinstCAudioTriggersWindow_x                                0xE1E2B0
#define pinstCCharacterSelect_x                                    0xF5C3EC
#define pinstCFacePick_x                                           0xF5C19C
#define pinstCNoteWnd_x                                            0xF5C3A4
#define pinstCBookWnd_x                                            0xF5C3AC
#define pinstCPetInfoWnd_x                                         0xF5C3B0
#define pinstCTrainWnd_x                                           0xF5C3B4
#define pinstCSkillsWnd_x                                          0xF5C3B8
#define pinstCSkillsSelectWnd_x                                    0xF5C3BC
#define pinstCCombatSkillsSelectWnd_x                              0xF5C3C0
#define pinstCFriendsWnd_x                                         0xF5C3C4
#define pinstCAuraWnd_x                                            0xF5C3C8
#define pinstCRespawnWnd_x                                         0xF5C3CC
#define pinstCBandolierWnd_x                                       0xF5C3D0
#define pinstCPotionBeltWnd_x                                      0xF5C3D4
#define pinstCAAWnd_x                                              0xF5C3D8
#define pinstCGroupSearchFiltersWnd_x                              0xF5C3DC
#define pinstCLoadskinWnd_x                                        0xF5C3E0
#define pinstCAlarmWnd_x                                           0xF5C3E4
#define pinstCMusicPlayerWnd_x                                     0xF5C3E8
#define pinstCMailWnd_x                                            0xF5C3F0
#define pinstCMailCompositionWnd_x                                 0xF5C3F4
#define pinstCMailAddressBookWnd_x                                 0xF5C3F8
#define pinstCRaidWnd_x                                            0xF5C400
#define pinstCRaidOptionsWnd_x                                     0xF5C404
#define pinstCBreathWnd_x                                          0xF5C408
#define pinstCMapViewWnd_x                                         0xF5C40C
#define pinstCMapToolbarWnd_x                                      0xF5C410
#define pinstCEditLabelWnd_x                                       0xF5C414
#define pinstCTargetWnd_x                                          0xF5C418
#define pinstCColorPickerWnd_x                                     0xF5C41C
#define pinstCPlayerWnd_x                                          0xF5C420
#define pinstCOptionsWnd_x                                         0xF5C424
#define pinstCBuffWindowNORMAL_x                                   0xF5C428
#define pinstCBuffWindowSHORT_x                                    0xF5C42C
#define pinstCharacterCreation_x                                   0xF5C430
#define pinstCCursorAttachment_x                                   0xF5C434
#define pinstCCastingWnd_x                                         0xF5C438
#define pinstCCastSpellWnd_x                                       0xF5C43C
#define pinstCSpellBookWnd_x                                       0xF5C440
#define pinstCInventoryWnd_x                                       0xF5C444
#define pinstCBankWnd_x                                            0xF5C44C
#define pinstCQuantityWnd_x                                        0xF5C450
#define pinstCLootWnd_x                                            0xF5C454
#define pinstCActionsWnd_x                                         0xF5C458
#define pinstCCombatAbilityWnd_x                                   0xF5C45C
#define pinstCMerchantWnd_x                                        0xF5C460
#define pinstCTradeWnd_x                                           0xF5C464
#define pinstCSelectorWnd_x                                        0xF5C468
#define pinstCBazaarWnd_x                                          0xF5C46C
#define pinstCBazaarSearchWnd_x                                    0xF5C470
#define pinstCGiveWnd_x                                            0xF5C48C
#define pinstCTrackingWnd_x                                        0xF5C494
#define pinstCInspectWnd_x                                         0xF5C498
#define pinstCSocialEditWnd_x                                      0xF5C49C
#define pinstCFeedbackWnd_x                                        0xF5C4A0
#define pinstCBugReportWnd_x                                       0xF5C4A4
#define pinstCVideoModesWnd_x                                      0xF5C4A8
#define pinstCTextEntryWnd_x                                       0xF5C4B0
#define pinstCFileSelectionWnd_x                                   0xF5C4B4
#define pinstCCompassWnd_x                                         0xF5C4B8
#define pinstCPlayerNotesWnd_x                                     0xF5C4BC
#define pinstCGemsGameWnd_x                                        0xF5C4C0
#define pinstCTimeLeftWnd_x                                        0xF5C4C4
#define pinstCPetitionQWnd_x                                       0xF5C4E0
#define pinstCSoulmarkWnd_x                                        0xF5C4E4
#define pinstCStoryWnd_x                                           0xF5C4E8
#define pinstCJournalTextWnd_x                                     0xF5C4EC
#define pinstCJournalCatWnd_x                                      0xF5C4F0
#define pinstCBodyTintWnd_x                                        0xF5C4F4
#define pinstCServerListWnd_x                                      0xF5C4F8
#define pinstCAvaZoneWnd_x                                         0xF5C504
#define pinstCBlockedBuffWnd_x                                     0xF5C508
#define pinstCBlockedPetBuffWnd_x                                  0xF5C50C
#define pinstCInvSlotMgr_x                                         0xF5C550
#define pinstCContainerMgr_x                                       0xF5C554
#define pinstCAdventureLeaderboardWnd_x                            0x11AEED8
#define pinstCAdventureRequestWnd_x                                0x11AEF50
#define pinstCAltStorageWnd_x                                      0x11AF230
#define pinstCAdventureStatsWnd_x                                  0x11AEFC8
#define pinstCBarterMerchantWnd_x                                  0x11AFE18
#define pinstCBarterSearchWnd_x                                    0x11AFE90
#define pinstCBarterWnd_x                                          0x11AFF08
#define pinstCChatManager_x                                        0x11B0598
#define pinstCDynamicZoneWnd_x                                     0x11B0A48
#define pinstCEQMainWnd_x                                          0x11B0BE0
#define pinstCFellowshipWnd_x                                      0x11B09DC
#define pinstCFindLocationWnd_x                                    0x11B0EB0
#define pinstCGroupSearchWnd_x                                     0x11B1180
#define pinstCGroupWnd_x                                           0x11B11F8
#define pinstCGuildBankWnd_x                                       0x11B1270
#define pinstCGuildMgmtWnd_x                                       0x11B3360
#define pinstCHotButtonWnd_x                                       0x11B342C
#define pinstCHotButtonWnd1_x                                      0x11B342C
#define pinstCHotButtonWnd2_x                                      0x11B3430
#define pinstCHotButtonWnd3_x                                      0x11B3434
#define pinstCHotButtonWnd4_x                                      0x11B3458
#define pinstCItemDisplayManager_x                                 0x11B3750
#define pinstCItemExpTransferWnd_x                                 0x11B37CC
#define pinstCLFGuildWnd_x                                         0x11B3AA8
#define pinstCMIZoneSelectWnd_x                                    0x11B4090
#define pinstCConfirmationDialog_x                                 0x11B4798
#define pinstCPopupWndManager_x                                    0x11B4798
#define pinstCProgressionSelectionWnd_x                            0x11B4888
#define pinstCPvPStatsWnd_x                                        0x11B4978
#define pinstCSystemInfoDialogBox_x                                0x11B5080
#define pinstCTaskWnd_x                                            0x11B6448
#define pinstCTaskSomething_x                                      0xE2A5D0
#define pinstCTaskTemplateSelectWnd_x                              0x11B63D0
#define pinstCTipWndOFDAY_x                                        0x11B66A0
#define pinstCTipWndCONTEXT_x                                      0x11B66A4
#define pinstCTitleWnd_x                                           0x11B6720
#define pinstCContextMenuManager_x                                 0x181A064
#define pinstCVoiceMacroWnd_x                                      0x10A3358
#define pinstCHtmlWnd_x                                            0x10A3450
#define pinstIconCache_x                                           0x11B0BB4
#define pinstCTradeskillWnd_x                                      0x11B6820
#define pinstCAdvancedLootWnd_x                                    0xF5C544
#define pinstRewardSelectionWnd_x                                  0x11B4EA0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5327E0
#define __ConvertItemTags_x                                        0x51F910
#define __ExecuteCmd_x                                             0x50A450
#define __EQGetTime_x                                              0x8A1790
#define __get_melee_range_x                                        0x5110D0
#define __GetGaugeValueFromEQ_x                                    0x7A9860
#define __GetLabelFromEQ_x                                         0x7AAAB0
#define __ToggleKeyRingItem_x                                      0x47EBD0
#define __GetXTargetType_x                                         0x933220
#define __LoadFrontEnd_x                                           0x638020
#define __NewUIINI_x                                               0x7A9160
#define __ProcessGameEvents_x                                      0x577C60
#define __ProcessMouseEvent_x                                      0x577400
#define CrashDetected_x                                            0x639AF0
#define wwsCrashReportCheckForUploader_x                           0x7FD310
#define DrawNetStatus_x                                            0x5AF090
#define Util__FastTime_x                                           0x8A12A0
#define Expansion_HoT_x                                            0x101DD34
#define __HelpPath_x                                               0x10A14A8
#define __STMLToText_x                                             0x8E7B50

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41FC40
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41AA90

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C5AA0
#define AltAdvManager__IsAbilityReady_x                            0x4C5B10
#define AltAdvManager__GetAAById_x                                 0x4C5ED0
#define AltAdvManager__CanTrainAbility_x                           0x4C6790
#define AltAdvManager__CanSeeAbility_x                             0x4C6390

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x464D90
#define CharacterZoneClient__MakeMeVisible_x                       0x46A770
#define CharacterZoneClient__IsStackBlocked_x                      0x446D10

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x667BB0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x675A80

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58E590
#define CButtonWnd__CButtonWnd_x                                   0x8DBDC0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6910D0
#define CChatManager__InitContextMenu_x                            0x691C50

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E5EB0
#define CContextMenu__dCContextMenu_x                              0x8E60C0
#define CContextMenu__AddMenuItem_x                                0x8E60D0
#define CContextMenu__RemoveMenuItem_x                             0x8E63C0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E63E0
#define CContextMenuManager__AddMenu_x                             0x8D1D50
#define CContextMenuManager__RemoveMenu_x                          0x8D20B0
#define CContextMenuManager__PopupMenu_x                           0x8D2500
#define CContextMenuManager__Flush_x                               0x8D1DC0
#define CContextMenuManager__GetMenu_x                             0x4160F0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x886AC0
#define CChatService__GetFriendName_x                              0x886AD0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x696F00
#define CChatWindow__Clear_x                                       0x696AB0
#define CChatWindow__WndNotification_x                             0x697440

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D5C70
#define CComboWnd__Draw_x                                          0x8D5E80
#define CComboWnd__GetCurChoice_x                                  0x8D5A40
#define CComboWnd__GetListRect_x                                   0x8D6120
#define CComboWnd__GetTextRect_x                                   0x8D5CE0
#define CComboWnd__InsertChoice_x                                  0x8D6190
#define CComboWnd__SetColors_x                                     0x8D59D0
#define CComboWnd__SetChoice_x                                     0x8D5A00
#define CComboWnd__GetItemCount_x                                  0x8D5A30

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A0510
#define CContainerWnd__vftable_x                                   0xAE3F68

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B3C80
#define CDisplay__GetClickedActor_x                                0x4AC7D0
#define CDisplay__GetUserDefinedColor_x                            0x4AB090
#define CDisplay__GetWorldFilePath_x                               0x4AA4E0
#define CDisplay__is3dON_x                                         0x4A98B0
#define CDisplay__ReloadUI_x                                       0x4BF260
#define CDisplay__WriteTextHD2_x                                   0x4AFFE0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FCA80

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EA860
#define CEditWnd__GetCharIndexPt_x                                 0x8EB900
#define CEditWnd__GetDisplayString_x                               0x8EAA10
#define CEditWnd__GetHorzOffset_x                                  0x8EAD50
#define CEditWnd__GetLineForPrintableChar_x                        0x8EB3C0
#define CEditWnd__GetSelStartPt_x                                  0x8EBBC0
#define CEditWnd__GetSTMLSafeText_x                                0x8EAEF0
#define CEditWnd__PointFromPrintableChar_x                         0x8EB4B0
#define CEditWnd__SelectableCharFromPoint_x                        0x8EB630
#define CEditWnd__SetEditable_x                                    0x8EAEC0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x553FA0
#define CEverQuest__CreateTargetIndicator_x                        0x554BD0
#define CEverQuest__DeleteTargetIndicator_x                        0x554C50
#define CEverQuest__DoTellWindow_x                                 0x5599A0
#define CEverQuest__DropHeldItemOnGround_x                         0x562890
#define CEverQuest__dsp_chat_x                                     0x55B350
#define CEverQuest__Emote_x                                        0x55B5B0
#define CEverQuest__EnterZone_x                                    0x56F9E0
#define CEverQuest__GetBodyTypeDesc_x                              0x550800
#define CEverQuest__GetClassDesc_x                                 0x556510
#define CEverQuest__GetClassThreeLetterCode_x                      0x556B10
#define CEverQuest__GetDeityDesc_x                                 0x5510E0
#define CEverQuest__GetLangDesc_x                                  0x550B90
#define CEverQuest__GetRaceDesc_x                                  0x556CD0
#define CEverQuest__InterpretCmd_x                                 0x55BE90
#define CEverQuest__LeftClickedOnPlayer_x                          0x574360
#define CEverQuest__LMouseUp_x                                     0x576450
#define CEverQuest__RightClickedOnPlayer_x                         0x574E60
#define CEverQuest__RMouseUp_x                                     0x575EB0
#define CEverQuest__SetGameState_x                                 0x554650
#define CEverQuest__UPCNotificationFlush_x                         0x55D1F0
#define CEverQuest__IssuePetCommand_x                              0x55CB50

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B11E0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B1240
#define CGaugeWnd__Draw_x                                          0x6B1670

// CGuild
#define CGuild__FindMemberByName_x                                 0x436A50

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CE2D0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DAA80
#define CInvSlotMgr__MoveItem_x                                    0x6DB9C0
#define CInvSlotMgr__SelectSlot_x                                  0x6DAB30

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D9F10
#define CInvSlot__SliderComplete_x                                 0x6D7740
#define CInvSlot__GetItemBase_x                                    0x6D6BB0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DCDD0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A61D0
#define CItemDisplayWnd__UpdateStrings_x                           0x6DE110

// CLabel 
#define CLabel__Draw_x                                             0x6F8FA0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C1830
#define CListWnd__dCListWnd_x                                      0x8C2850
#define CListWnd__AddColumn_x                                      0x8C27F0
#define CListWnd__AddColumn1_x                                     0x8C2060
#define CListWnd__AddLine_x                                        0x8C1AE0
#define CListWnd__AddString_x                                      0x8C1CF0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BEB50
#define CListWnd__CalculateVSBRange_x                              0x8C0CE0
#define CListWnd__ClearAllSel_x                                    0x8BDE00
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C16C0
#define CListWnd__Compare_x                                        0x8BF660
#define CListWnd__Draw_x                                           0x8C08F0
#define CListWnd__DrawColumnSeparators_x                           0x8C0780
#define CListWnd__DrawHeader_x                                     0x8BE110
#define CListWnd__DrawItem_x                                       0x8BFCB0
#define CListWnd__DrawLine_x                                       0x8C0420
#define CListWnd__DrawSeparator_x                                  0x8C0820
#define CListWnd__EnsureVisible_x                                  0x8BECB0
#define CListWnd__ExtendSel_x                                      0x8BFBC0
#define CListWnd__GetColumnMinWidth_x                              0x8BD7C0
#define CListWnd__GetColumnWidth_x                                 0x8BD6E0
#define CListWnd__GetCurSel_x                                      0x8BCEA0
#define CListWnd__GetItemAtPoint_x                                 0x8BEF50
#define CListWnd__GetItemAtPoint1_x                                0x8BEFC0
#define CListWnd__GetItemData_x                                    0x8BD1F0
#define CListWnd__GetItemHeight_x                                  0x8BE7A0
#define CListWnd__GetItemIcon_x                                    0x8BD3D0
#define CListWnd__GetItemRect_x                                    0x8BED90
#define CListWnd__GetItemText_x                                    0x8BD280
#define CListWnd__GetSelList_x                                     0x8C1F50
#define CListWnd__GetSeparatorRect_x                               0x8BF580
#define CListWnd__RemoveLine_x                                     0x8C1ED0
#define CListWnd__SetColors_x                                      0x8BCFF0
#define CListWnd__SetColumnJustification_x                         0x8BDA90
#define CListWnd__SetColumnWidth_x                                 0x8BD770
#define CListWnd__SetCurSel_x                                      0x8BCEE0
#define CListWnd__SetItemColor_x                                   0x8C13A0
#define CListWnd__SetItemData_x                                    0x8BDEB0
#define CListWnd__SetItemText_x                                    0x8C11E0
#define CListWnd__ShiftColumnSeparator_x                           0x8C1070
#define CListWnd__Sort_x                                           0x8C2950
#define CListWnd__ToggleSel_x                                      0x8BDD80

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x712430

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x733820
#define CMerchantWnd__RequestBuyItem_x                             0x73A610
#define CMerchantWnd__RequestSellItem_x                            0x73B060
#define CMerchantWnd__SelectRecoverySlot_x                         0x733AD0
#define CMerchantWnd__SelectBuySellSlot_x                          0x732D30
#define CMerchantWnd__ActualSelect_x                               0x737550

// CObfuscator
#define CObfuscator__doit_x                                        0x852080

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E0DF0
#define CSidlManager__CreateLabel_x                                0x79C160

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65EED0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65EDF0
#define CSidlScreenWnd__ConvertToRes_x                             0x8FC960
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D8910
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D9E00
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D9EB0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D9380
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D82C0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D79F0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D84B0
#define CSidlScreenWnd__Init1_x                                    0x8D9AE0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D89C0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D7BB0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D95D0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D74C0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D7980
#define CSidlScreenWnd__WndNotification_x                          0x8D9860
#define CSidlScreenWnd__GetChildItem_x                             0x8D7AC0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CAE80

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F9EB0
#define CSkillMgr__GetSkillCap_x                                   0x5FA070
#define CSkillMgr__GetNameToken_x                                  0x5F9AD0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FBC30
#define CSliderWnd__SetValue_x                                     0x8FBE00
#define CSliderWnd__SetNumTicks_x                                  0x8FC580

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A3E80

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F75A0
#define CStmlWnd__CalculateHSBRange_x                              0x8EFAC0
#define CStmlWnd__CalculateVSBRange_x                              0x8EFB50
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EFCD0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F05B0
#define CStmlWnd__ForceParseNow_x                                  0x8F7EF0
#define CStmlWnd__GetNextTagPiece_x                                0x8F04B0
#define CStmlWnd__GetSTMLText_x                                    0x696350
#define CStmlWnd__GetVisibleText_x                                 0x8F1000
#define CStmlWnd__InitializeWindowVariables_x                      0x8F3390
#define CStmlWnd__MakeStmlColorTag_x                               0x8EEDC0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EEE20
#define CStmlWnd__SetSTMLText_x                                    0x8F4C00
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F7240
#define CStmlWnd__UpdateHistoryString_x                            0x8F1F40

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8EE460
#define CTabWnd__DrawCurrentPage_x                                 0x8EDCD0
#define CTabWnd__DrawTab_x                                         0x8EDA90
#define CTabWnd__GetCurrentPage_x                                  0x8EE0A0
#define CTabWnd__GetPageInnerRect_x                                0x8ED780
#define CTabWnd__GetTabInnerRect_x                                 0x8ED980
#define CTabWnd__GetTabRect_x                                      0x8ED850
#define CTabWnd__InsertPage_x                                      0x8EE750
#define CTabWnd__SetPage_x                                         0x8EE0D0
#define CTabWnd__SetPageRect_x                                     0x8EE3A0
#define CTabWnd__UpdatePage_x                                      0x8EE6F0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4328A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D5640

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x901DE0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BB060

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59BB50
#define CXStr__CXStr1_x                                            0x7E6650
#define CXStr__CXStr3_x                                            0x89E330
#define CXStr__dCXStr_x                                            0x79C110
#define CXStr__operator_equal_x                                    0x89E4A0
#define CXStr__operator_equal1_x                                   0x89E4F0
#define CXStr__operator_plus_equal1_x                              0x89F5D0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8CA090
#define CXWnd__Center_x                                            0x8D0340
#define CXWnd__ClrFocus_x                                          0x8C9C70
#define CXWnd__DoAllDrawing_x                                      0x8CFF90
#define CXWnd__DrawChildren_x                                      0x8D0130
#define CXWnd__DrawColoredRect_x                                   0x8CA420
#define CXWnd__DrawTooltip_x                                       0x8CA6D0
#define CXWnd__DrawTooltipAtPoint_x                                0x8CEEB0
#define CXWnd__GetBorderFrame_x                                    0x8CAB40
#define CXWnd__GetChildWndAt_x                                     0x8D0D00
#define CXWnd__GetClientClipRect_x                                 0x8CA8F0
#define CXWnd__GetScreenClipRect_x                                 0x8CF5B0
#define CXWnd__GetScreenRect_x                                     0x8CAD20
#define CXWnd__GetTooltipRect_x                                    0x8CA560
#define CXWnd__GetWindowTextA_x                                    0x423C50
#define CXWnd__IsActive_x                                          0x8C5630
#define CXWnd__IsDescendantOf_x                                    0x8CAA80
#define CXWnd__IsReallyVisible_x                                   0x8CDEC0
#define CXWnd__IsType_x                                            0x8FE5E0
#define CXWnd__Move_x                                              0x8CD5D0
#define CXWnd__Move1_x                                             0x8CFC20
#define CXWnd__ProcessTransition_x                                 0x8CA040
#define CXWnd__Refade_x                                            0x8C9E20
#define CXWnd__Resize_x                                            0x8CADF0
#define CXWnd__Right_x                                             0x8CF3B0
#define CXWnd__SetFocus_x                                          0x8CC720
#define CXWnd__SetFont_x                                           0x8C9CC0
#define CXWnd__SetKeyTooltip_x                                     0x8CB050
#define CXWnd__SetMouseOver_x                                      0x8CF900
#define CXWnd__StartFade_x                                         0x8CA0E0
#define CXWnd__GetChildItem_x                                      0x8CF840

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C6F50
#define CXWndManager__DrawWindows_x                                0x8C6B90
#define CXWndManager__GetKeyboardFlags_x                           0x8C5160
#define CXWndManager__HandleKeyboardMsg_x                          0x8C5AC0
#define CXWndManager__RemoveWnd_x                                  0x8C57C0

// CDBStr
#define CDBStr__GetString_x                                        0x4A7E30

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E8C0
#define EQ_Character__Cur_HP_x                                     0x464460
#define EQ_Character__GetAACastingTimeModifier_x                   0x446890
#define EQ_Character__GetCharInfo2_x                               0x8715C0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EC40
#define EQ_Character__GetFocusRangeModifier_x                      0x43EE30
#define EQ_Character__Max_Endurance_x                              0x5C1AB0
#define EQ_Character__Max_HP_x                                     0x45A0A0
#define EQ_Character__Max_Mana_x                                   0x5C18E0
#define EQ_Character__doCombatAbility_x                            0x5BEF30
#define EQ_Character__UseSkill_x                                   0x46F970
#define EQ_Character__GetConLevel_x                                0x5B36F0
#define EQ_Character__IsExpansionFlag_x                            0x4231A0
#define EQ_Character__TotalEffect_x                                0x44BBA0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x593DD0
#define EQ_Item__CreateItemTagString_x                             0x850940
#define EQ_Item__IsStackable_x                                     0x844D00
#define EQ_Item__GetImageNum_x                                     0x8479E0
#define EQ_Item__CreateItemClient_x                                0x594990
#define EQ_Item__GetItemValue_x                                    0x84F5F0
#define EQ_Item__ValueSellMerchant_x                               0x851CC0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C7B90
#define EQ_LoadingS__Array_x                                       0xC20720

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C3110
#define EQ_PC__GetAlternateAbilityId_x                             0x859FA0
#define EQ_PC__GetCombatAbility_x                                  0x85A030
#define EQ_PC__GetCombatAbilityTimer_x                             0x854E00
#define EQ_PC__GetItemTimerValue_x                                 0x5BCA40
#define EQ_PC__HasLoreItem_x                                       0x5B6BC0
#define EQ_PC__AlertInventoryChanged_x                             0x5B36C0
#define EQ_PC__GetPcZoneClient_x                                   0x5DD690
#define EQ_PC__RemoveMyAffect_x                                    0x5BBEE0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50F140
#define EQItemList__add_item_x                                     0x50F080
#define EQItemList__delete_item_x                                  0x50F540
#define EQItemList__FreeItemList_x                                 0x50F440

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A70E0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C8680
#define EQPlayer__dEQPlayer_x                                      0x5D1500
#define EQPlayer__DoAttack_x                                       0x5E3570
#define EQPlayer__EQPlayer_x                                       0x5D3920
#define EQPlayer__SetNameSpriteState_x                             0x5CE1D0
#define EQPlayer__SetNameSpriteTint_x                              0x5C9A90
#define EQPlayer__IsBodyType_j_x                                   0x92F410
#define EQPlayer__IsTargetable_x                                   0x92FD10
#define EQPlayer__CanSee_x                                         0x930230
#define PlayerZoneClient__ChangeHeight_x                           0x5E3430
#define EQPlayer__CanSeeTargetIndicator_x                          0x930320

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D7C30
#define EQPlayerManager__GetSpawnByName_x                          0x5D8090

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x599E80
#define KeypressHandler__AttachKeyToEqCommand_x                    0x599EC0
#define KeypressHandler__ClearCommandStateArray_x                  0x599A60
#define KeypressHandler__HandleKeyDown_x                           0x5983C0
#define KeypressHandler__HandleKeyUp_x                             0x5986E0
#define KeypressHandler__SaveKeymapping_x                          0x599B30

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70A810
#define MapViewMap__SaveEx_x                                       0x70E0F0

#define PlayerPointManager__GetAltCurrency_x                       0x86C590

// StringTable 
#define StringTable__getString_x                                   0x867080

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C1560
#define PcZoneClient__RemovePetEffect_x                            0x5BCF30
#define PcZoneClient__HasAlternateAbility_x                        0x5BD9F0

//Doors
#define EQSwitch__UseSwitch_x                                      0x54DAF0

//IconCache
#define IconCache__GetIcon_x                                       0x6A6A50

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69D820
#define CContainerMgr__CloseContainer_x                            0x69E040

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76C430

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58D030

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DF1C0
#define EQ_Spell__SpellAffects_x                                   0x4DF260
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DF290
#define CharacterZoneClient__CalcAffectChange_x                    0x447C30
#define CLootWnd__LootAll_x                                        0x700150

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B1E00
#define CTargetWnd__WndNotification_x                              0x7B18F0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B6FE0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D8A90

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x497760

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E9E80
#define CSidlManager__FindAnimation1_x                             0x8DECD0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CF100
#define CAltAbilityData__GetMercMaxRank_x                          0x4CF0B0
#define CAltAbilityData__GetMaxRank_x                              0x4C4160

//CTargetRing
#define CTargetRing__Cast_x                                        0x58A920
