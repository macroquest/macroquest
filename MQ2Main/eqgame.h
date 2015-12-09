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
#define __ExpectedVersionDate                                     "Dec  8 2015"
#define __ExpectedVersionTime                                     "11:35:09"
#define __ActualVersionDate_x                                      0xADA578
#define __ActualVersionTime_x                                      0xADA584

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59FC20
#define __MemChecker1_x                                            0x8A22F0
#define __MemChecker2_x                                            0x639030
#define __MemChecker3_x                                            0x638F80
#define __MemChecker4_x                                            0x7EE290
#define __EncryptPad0_x                                            0xC77388
#define __EncryptPad1_x                                            0xE02508
#define __EncryptPad2_x                                            0xCC0E70
#define __EncryptPad3_x                                            0xCC0A70
#define __EncryptPad4_x                                            0xDDB5F8
#define __EncryptPad5_x                                            0x11AE3D0
#define __AC1_x                                                    0x7AB1A5
#define __AC2_x                                                    0x553DA7
#define __AC3_x                                                    0x568960
#define __AC4_x                                                    0x56F5E0
#define __AC5_x                                                    0x57BD9E
#define __AC6_x                                                    0x57F959
#define __AC7_x                                                    0x57644C
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
#define __do_loot_x                                                0x51B300
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
#define pinstPlayerPath_x                                          0x109E610
#define pinstTargetIndicator_x                                     0x109EFA8
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
#define __CastRay_x                                                0x532E50
#define __ConvertItemTags_x                                        0x51FF80
#define __ExecuteCmd_x                                             0x50AAA0
#define __EQGetTime_x                                              0x8A1F20
#define __get_melee_range_x                                        0x511740
#define __GetGaugeValueFromEQ_x                                    0x7A9EE0
#define __GetLabelFromEQ_x                                         0x7AB130
#define __ToggleKeyRingItem_x                                      0x47EDD0
#define __GetXTargetType_x                                         0x933840
#define __LoadFrontEnd_x                                           0x6386E0
#define __NewUIINI_x                                               0x7A97E0
#define __ProcessGameEvents_x                                      0x5781B0
#define __ProcessMouseEvent_x                                      0x577950
#define CrashDetected_x                                            0x63A1B0
#define wwsCrashReportCheckForUploader_x                           0x7FD9D0
#define DrawNetStatus_x                                            0x5AF760
#define Util__FastTime_x                                           0x8A1A30
#define Expansion_HoT_x                                            0x101DD34
#define __HelpPath_x                                               0x10A14A8
#define __STMLToText_x                                             0x8E7F60

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41FBC0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41AA20

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C5C90
#define AltAdvManager__IsAbilityReady_x                            0x4C5D00
#define AltAdvManager__GetAAById_x                                 0x4C60C0
#define AltAdvManager__CanTrainAbility_x                           0x4C6980
#define AltAdvManager__CanSeeAbility_x                             0x4C6580

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x465020
#define CharacterZoneClient__MakeMeVisible_x                       0x46AA00
#define CharacterZoneClient__IsStackBlocked_x                      0x446E70

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x668250

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x676760

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58EB20
#define CButtonWnd__CButtonWnd_x                                   0x8DC210

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x691720
#define CChatManager__InitContextMenu_x                            0x6922A0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E62D0
#define CContextMenu__dCContextMenu_x                              0x8E64E0
#define CContextMenu__AddMenuItem_x                                0x8E64F0
#define CContextMenu__RemoveMenuItem_x                             0x8E67D0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E67F0
#define CContextMenuManager__AddMenu_x                             0x8D21D0
#define CContextMenuManager__RemoveMenu_x                          0x8D2520
#define CContextMenuManager__PopupMenu_x                           0x8D2970
#define CContextMenuManager__Flush_x                               0x8D2240
#define CContextMenuManager__GetMenu_x                             0x416080

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8452A0
#define CChatService__GetFriendName_x                              0x887250

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x697550
#define CChatWindow__Clear_x                                       0x697100
#define CChatWindow__WndNotification_x                             0x697A90

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D60E0
#define CComboWnd__Draw_x                                          0x8D62F0
#define CComboWnd__GetCurChoice_x                                  0x8D5EB0
#define CComboWnd__GetListRect_x                                   0x8D6590
#define CComboWnd__GetTextRect_x                                   0x8D6150
#define CComboWnd__InsertChoice_x                                  0x8D6600
#define CComboWnd__SetColors_x                                     0x8D5E40
#define CComboWnd__SetChoice_x                                     0x8D5E70
#define CComboWnd__GetItemCount_x                                  0x8D5EA0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A0CB0
#define CContainerWnd__vftable_x                                   0xAE3F60

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B3F10
#define CDisplay__GetClickedActor_x                                0x4ACA50
#define CDisplay__GetUserDefinedColor_x                            0x4AB310
#define CDisplay__GetWorldFilePath_x                               0x4AA760
#define CDisplay__is3dON_x                                         0x4A9B30
#define CDisplay__ReloadUI_x                                       0x4BF4F0
#define CDisplay__WriteTextHD2_x                                   0x4B0270

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FCE90

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EACC0
#define CEditWnd__GetCharIndexPt_x                                 0x8EBD30
#define CEditWnd__GetDisplayString_x                               0x8EAE70
#define CEditWnd__GetHorzOffset_x                                  0x8EB1B0
#define CEditWnd__GetLineForPrintableChar_x                        0x8EB810
#define CEditWnd__GetSelStartPt_x                                  0x8EBFE0
#define CEditWnd__GetSTMLSafeText_x                                0x8EB340
#define CEditWnd__PointFromPrintableChar_x                         0x8EB900
#define CEditWnd__SelectableCharFromPoint_x                        0x8EBA70
#define CEditWnd__SetEditable_x                                    0x8EB310

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x5544F0
#define CEverQuest__CreateTargetIndicator_x                        0x555120
#define CEverQuest__DeleteTargetIndicator_x                        0x5551A0
#define CEverQuest__DoTellWindow_x                                 0x559EF0
#define CEverQuest__DropHeldItemOnGround_x                         0x562DE0
#define CEverQuest__dsp_chat_x                                     0x55B8A0
#define CEverQuest__Emote_x                                        0x55BB00
#define CEverQuest__EnterZone_x                                    0x56FF30
#define CEverQuest__GetBodyTypeDesc_x                              0x550D50
#define CEverQuest__GetClassDesc_x                                 0x556A60
#define CEverQuest__GetClassThreeLetterCode_x                      0x557060
#define CEverQuest__GetDeityDesc_x                                 0x551630
#define CEverQuest__GetLangDesc_x                                  0x5510E0
#define CEverQuest__GetRaceDesc_x                                  0x557220
#define CEverQuest__InterpretCmd_x                                 0x55C3E0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5748B0
#define CEverQuest__LMouseUp_x                                     0x5769A0
#define CEverQuest__RightClickedOnPlayer_x                         0x5753B0
#define CEverQuest__RMouseUp_x                                     0x576400
#define CEverQuest__SetGameState_x                                 0x554BA0
#define CEverQuest__UPCNotificationFlush_x                         0x55D740
#define CEverQuest__IssuePetCommand_x                              0x55D0A0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B1930
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B1990
#define CGaugeWnd__Draw_x                                          0x6B1DC0

// CGuild
#define CGuild__FindMemberByName_x                                 0x436B40

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CEA00

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DB170
#define CInvSlotMgr__MoveItem_x                                    0x6DC0B0
#define CInvSlotMgr__SelectSlot_x                                  0x6DB220

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6DA600
#define CInvSlot__SliderComplete_x                                 0x6D7E30
#define CInvSlot__GetItemBase_x                                    0x6D72B0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DD4B0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A68A0
#define CItemDisplayWnd__UpdateStrings_x                           0x6DE7F0

// CLabel 
#define CLabel__Draw_x                                             0x6F9740

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C1DF0
#define CListWnd__dCListWnd_x                                      0x8C2E00
#define CListWnd__AddColumn_x                                      0x8C2DA0
#define CListWnd__AddColumn1_x                                     0x8C2620
#define CListWnd__AddLine_x                                        0x8C20A0
#define CListWnd__AddString_x                                      0x8C22B0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BF140
#define CListWnd__CalculateVSBRange_x                              0x8C12A0
#define CListWnd__ClearAllSel_x                                    0x8BE410
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C1C80
#define CListWnd__Compare_x                                        0x8BFC30
#define CListWnd__Draw_x                                           0x8C0EB0
#define CListWnd__DrawColumnSeparators_x                           0x8C0D40
#define CListWnd__DrawHeader_x                                     0x8BE720
#define CListWnd__DrawItem_x                                       0x8C0280
#define CListWnd__DrawLine_x                                       0x8C09E0
#define CListWnd__DrawSeparator_x                                  0x8C0DE0
#define CListWnd__EnsureVisible_x                                  0x8BF2A0
#define CListWnd__ExtendSel_x                                      0x8C0190
#define CListWnd__GetColumnMinWidth_x                              0x8BDDD0
#define CListWnd__GetColumnWidth_x                                 0x8BDCF0
#define CListWnd__GetCurSel_x                                      0x8BD4B0
#define CListWnd__GetItemAtPoint_x                                 0x8BF530
#define CListWnd__GetItemAtPoint1_x                                0x8BF5A0
#define CListWnd__GetItemData_x                                    0x8BD800
#define CListWnd__GetItemHeight_x                                  0x8BEDB0
#define CListWnd__GetItemIcon_x                                    0x8BD9E0
#define CListWnd__GetItemRect_x                                    0x8BF370
#define CListWnd__GetItemText_x                                    0x8BD890
#define CListWnd__GetSelList_x                                     0x8C2510
#define CListWnd__GetSeparatorRect_x                               0x8BFB50
#define CListWnd__RemoveLine_x                                     0x8C2490
#define CListWnd__SetColors_x                                      0x8BD600
#define CListWnd__SetColumnJustification_x                         0x8BE0A0
#define CListWnd__SetColumnWidth_x                                 0x8BDD80
#define CListWnd__SetCurSel_x                                      0x8BD4F0
#define CListWnd__SetItemColor_x                                   0x8C1960
#define CListWnd__SetItemData_x                                    0x8BE4C0
#define CListWnd__SetItemText_x                                    0x8C17A0
#define CListWnd__ShiftColumnSeparator_x                           0x8C1630
#define CListWnd__Sort_x                                           0x8C2F00
#define CListWnd__ToggleSel_x                                      0x8BE390

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x712BB0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x733FD0
#define CMerchantWnd__RequestBuyItem_x                             0x73AE30
#define CMerchantWnd__RequestSellItem_x                            0x73B8A0
#define CMerchantWnd__SelectRecoverySlot_x                         0x734280
#define CMerchantWnd__SelectBuySellSlot_x                          0x7334E0
#define CMerchantWnd__ActualSelect_x                               0x737D50

// CObfuscator
#define CObfuscator__doit_x                                        0x852850

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E1190
#define CSidlManager__CreateLabel_x                                0x79C8C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65F570
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65F490
#define CSidlScreenWnd__ConvertToRes_x                             0x8FCD70
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D8D60
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DA240
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DA2F0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D97D0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D8710
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D7E50
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D8900
#define CSidlScreenWnd__Init1_x                                    0x8D9F30
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D8E10
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D8010
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D9A20
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D7920
#define CSidlScreenWnd__StoreIniVis_x                              0x8D7DE0
#define CSidlScreenWnd__WndNotification_x                          0x8D9CB0
#define CSidlScreenWnd__GetChildItem_x                             0x8D7F20
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CB460

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FA360
#define CSkillMgr__GetSkillCap_x                                   0x5FA520
#define CSkillMgr__GetNameToken_x                                  0x5F9F80

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FC040
#define CSliderWnd__SetValue_x                                     0x8FC210
#define CSliderWnd__SetNumTicks_x                                  0x8FC990

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A4550

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F7970
#define CStmlWnd__CalculateHSBRange_x                              0x8EFEB0
#define CStmlWnd__CalculateVSBRange_x                              0x8EFF40
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F00C0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F09A0
#define CStmlWnd__ForceParseNow_x                                  0x8F82C0
#define CStmlWnd__GetNextTagPiece_x                                0x8F08A0
#define CStmlWnd__GetSTMLText_x                                    0x6969A0
#define CStmlWnd__GetVisibleText_x                                 0x8F13F0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F3780
#define CStmlWnd__MakeStmlColorTag_x                               0x8EF1B0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EF210
#define CStmlWnd__SetSTMLText_x                                    0x8F4FE0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F7610
#define CStmlWnd__UpdateHistoryString_x                            0x8F2330

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8EE850
#define CTabWnd__DrawCurrentPage_x                                 0x8EE0C0
#define CTabWnd__DrawTab_x                                         0x8EDE90
#define CTabWnd__GetCurrentPage_x                                  0x8EE490
#define CTabWnd__GetPageInnerRect_x                                0x8EDB80
#define CTabWnd__GetTabInnerRect_x                                 0x8EDD80
#define CTabWnd__GetTabRect_x                                      0x8EDC50
#define CTabWnd__InsertPage_x                                      0x8EEB40
#define CTabWnd__SetPage_x                                         0x8EE4C0
#define CTabWnd__SetPageRect_x                                     0x8EE790
#define CTabWnd__UpdatePage_x                                      0x8EEAE0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432900

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D5AB0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9021D0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BB600

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59C200
#define CXStr__CXStr1_x                                            0x8BC6D0
#define CXStr__CXStr3_x                                            0x89EAC0
#define CXStr__dCXStr_x                                            0x409B80
#define CXStr__operator_equal_x                                    0x89EC30
#define CXStr__operator_equal1_x                                   0x89EC80
#define CXStr__operator_plus_equal1_x                              0x89FD60

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8CA660
#define CXWnd__Center_x                                            0x8D0830
#define CXWnd__ClrFocus_x                                          0x8CA250
#define CXWnd__DoAllDrawing_x                                      0x8D0480
#define CXWnd__DrawChildren_x                                      0x8D0620
#define CXWnd__DrawColoredRect_x                                   0x8CAA20
#define CXWnd__DrawTooltip_x                                       0x8CACD0
#define CXWnd__DrawTooltipAtPoint_x                                0x8CF3E0
#define CXWnd__GetBorderFrame_x                                    0x8CB130
#define CXWnd__GetChildWndAt_x                                     0x8D11E0
#define CXWnd__GetClientClipRect_x                                 0x8CAEE0
#define CXWnd__GetScreenClipRect_x                                 0x8CFAD0
#define CXWnd__GetScreenRect_x                                     0x8CB310
#define CXWnd__GetTooltipRect_x                                    0x8CAB60
#define CXWnd__GetWindowTextA_x                                    0x423D10
#define CXWnd__IsActive_x                                          0x8C5BE0
#define CXWnd__IsDescendantOf_x                                    0x8CB070
#define CXWnd__IsReallyVisible_x                                   0x8CE410
#define CXWnd__IsType_x                                            0x8FE9F0
#define CXWnd__Move_x                                              0x8CDB50
#define CXWnd__Move1_x                                             0x8D0120
#define CXWnd__ProcessTransition_x                                 0x8CA610
#define CXWnd__Refade_x                                            0x8CA3F0
#define CXWnd__Resize_x                                            0x8CB3D0
#define CXWnd__Right_x                                             0x8CF8D0
#define CXWnd__SetFocus_x                                          0x8CCCC0
#define CXWnd__SetFont_x                                           0x8CA2A0
#define CXWnd__SetKeyTooltip_x                                     0x8CB630
#define CXWnd__SetMouseOver_x                                      0x8CFE00
#define CXWnd__StartFade_x                                         0x8CA6B0
#define CXWnd__GetChildItem_x                                      0x8CFD50

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C7510
#define CXWndManager__DrawWindows_x                                0x8C7150
#define CXWndManager__GetKeyboardFlags_x                           0x8C5710
#define CXWndManager__HandleKeyboardMsg_x                          0x8C6070
#define CXWndManager__RemoveWnd_x                                  0x8C5D70

// CDBStr
#define CDBStr__GetString_x                                        0x4A8030

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44EAE0
#define EQ_Character__Cur_HP_x                                     0x4646F0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4469F0
#define EQ_Character__GetCharInfo2_x                               0x871E80
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43ED20
#define EQ_Character__GetFocusRangeModifier_x                      0x43EF10
#define EQ_Character__Max_Endurance_x                              0x5C1C90
#define EQ_Character__Max_HP_x                                     0x45A320
#define EQ_Character__Max_Mana_x                                   0x5C1AC0
#define EQ_Character__doCombatAbility_x                            0x5BF110
#define EQ_Character__UseSkill_x                                   0x46FBF0
#define EQ_Character__GetConLevel_x                                0x5B3E30
#define EQ_Character__IsExpansionFlag_x                            0x423260
#define EQ_Character__TotalEffect_x                                0x44BD90

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x594420
#define EQ_Item__CreateItemTagString_x                             0x851170
#define EQ_Item__IsStackable_x                                     0x8456C0
#define EQ_Item__GetImageNum_x                                     0x8483C0
#define EQ_Item__CreateItemClient_x                                0x595000
#define EQ_Item__GetItemValue_x                                    0x84FE60
#define EQ_Item__ValueSellMerchant_x                               0x8524A0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C7DC0
#define EQ_LoadingS__Array_x                                       0xC20720

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C32E0
#define EQ_PC__GetAlternateAbilityId_x                             0x85A740
#define EQ_PC__GetCombatAbility_x                                  0x85A7D0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8555E0
#define EQ_PC__GetItemTimerValue_x                                 0x5BCC30
#define EQ_PC__HasLoreItem_x                                       0x5B7310
#define EQ_PC__AlertInventoryChanged_x                             0x5B3E00
#define EQ_PC__GetPcZoneClient_x                                   0x5DD830
#define EQ_PC__RemoveMyAffect_x                                    0x5BC0F0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50F790
#define EQItemList__add_item_x                                     0x50F6D0
#define EQItemList__delete_item_x                                  0x50FB90
#define EQItemList__FreeItemList_x                                 0x50FA90

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A7310

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C8870
#define EQPlayer__dEQPlayer_x                                      0x5D16F0
#define EQPlayer__DoAttack_x                                       0x5E3720
#define EQPlayer__EQPlayer_x                                       0x5D3B10
#define EQPlayer__SetNameSpriteState_x                             0x5CE3C0
#define EQPlayer__SetNameSpriteTint_x                              0x5C9C80
#define EQPlayer__IsBodyType_j_x                                   0x92FA70
#define EQPlayer__IsTargetable_x                                   0x930370
#define EQPlayer__CanSee_x                                         0x930890
#define PlayerZoneClient__ChangeHeight_x                           0x5E35E0
#define EQPlayer__CanSeeTargetIndicator_x                          0x930980

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D7E30
#define EQPlayerManager__GetSpawnByName_x                          0x5D8290

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59A530
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59A570
#define KeypressHandler__ClearCommandStateArray_x                  0x59A110
#define KeypressHandler__HandleKeyDown_x                           0x598A70
#define KeypressHandler__HandleKeyUp_x                             0x598D90
#define KeypressHandler__SaveKeymapping_x                          0x59A1E0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70AF90
#define MapViewMap__SaveEx_x                                       0x70E870

#define PlayerPointManager__GetAltCurrency_x                       0x86CE50

// StringTable 
#define StringTable__getString_x                                   0x867830

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C1740
#define PcZoneClient__RemovePetEffect_x                            0x5BD120
#define PcZoneClient__HasAlternateAbility_x                        0x5BDBE0

//Doors
#define EQSwitch__UseSwitch_x                                      0x54E060

//IconCache
#define IconCache__GetIcon_x                                       0x6A71B0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69DFC0
#define CContainerMgr__CloseContainer_x                            0x69E7E0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76CBD0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58D5C0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DF450
#define EQ_Spell__SpellAffects_x                                   0x4DF4F0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DF520
#define CharacterZoneClient__CalcAffectChange_x                    0x447DE0
#define CLootWnd__LootAll_x                                        0x700910

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B24F0
#define CTargetWnd__WndNotification_x                              0x7B1FE0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B76D0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D8D20

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x497910

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EA2F0
#define CSidlManager__FindAnimation1_x                             0x8DF070

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CF380
#define CAltAbilityData__GetMercMaxRank_x                          0x4CF330
#define CAltAbilityData__GetMaxRank_x                              0x4C4350

//CTargetRing
#define CTargetRing__Cast_x                                        0x58AEC0
