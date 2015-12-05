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
#define __ExpectedVersionDate                                     "Dec  4 2015"
#define __ExpectedVersionTime                                     "14:24:29"
#define __ActualVersionDate_x                                      0xADA580
#define __ActualVersionTime_x                                      0xADA58C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5A09F0
#define __MemChecker1_x                                            0x8A2700
#define __MemChecker2_x                                            0x639B60
#define __MemChecker3_x                                            0x639AB0
#define __MemChecker4_x                                            0x7EE690
#define __EncryptPad0_x                                            0xC77388
#define __EncryptPad1_x                                            0xE02508
#define __EncryptPad2_x                                            0xCC0E70
#define __EncryptPad3_x                                            0xCC0A70
#define __EncryptPad4_x                                            0xDDB5F8
#define __EncryptPad5_x                                            0x11AE3D0
#define __AC1_x                                                    0x7AB995
#define __AC2_x                                                    0x554C57
#define __AC3_x                                                    0x569810
#define __AC4_x                                                    0x570490
#define __AC5_x                                                    0x57CC3E
#define __AC6_x                                                    0x5807F9
#define __AC7_x                                                    0x5772EC
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
#define __do_loot_x                                                0x51C070
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
#define pinstCamActor_x                                            0xF5C558
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
#define pinstViewActor_x                                           0xF5C554
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
#define pinstCCharacterSelect_x                                    0xF5C3E8
#define pinstCFacePick_x                                           0xF5C398
#define pinstCNoteWnd_x                                            0xF5C3A0
#define pinstCBookWnd_x                                            0xF5C3A8
#define pinstCPetInfoWnd_x                                         0xF5C3AC
#define pinstCTrainWnd_x                                           0xF5C3B0
#define pinstCSkillsWnd_x                                          0xF5C3B4
#define pinstCSkillsSelectWnd_x                                    0xF5C3B8
#define pinstCCombatSkillsSelectWnd_x                              0xF5C3BC
#define pinstCFriendsWnd_x                                         0xF5C3C0
#define pinstCAuraWnd_x                                            0xF5C3C4
#define pinstCRespawnWnd_x                                         0xF5C3C8
#define pinstCBandolierWnd_x                                       0xF5C3CC
#define pinstCPotionBeltWnd_x                                      0xF5C3D0
#define pinstCAAWnd_x                                              0xF5C3D4
#define pinstCGroupSearchFiltersWnd_x                              0xF5C3D8
#define pinstCLoadskinWnd_x                                        0xF5C3DC
#define pinstCAlarmWnd_x                                           0xF5C3E0
#define pinstCMusicPlayerWnd_x                                     0xF5C3E4
#define pinstCMailWnd_x                                            0xF5C3EC
#define pinstCMailCompositionWnd_x                                 0xF5C3F0
#define pinstCMailAddressBookWnd_x                                 0xF5C3F4
#define pinstCRaidWnd_x                                            0xF5C3FC
#define pinstCRaidOptionsWnd_x                                     0xF5C400
#define pinstCBreathWnd_x                                          0xF5C404
#define pinstCMapViewWnd_x                                         0xF5C408
#define pinstCMapToolbarWnd_x                                      0xF5C40C
#define pinstCEditLabelWnd_x                                       0xF5C410
#define pinstCTargetWnd_x                                          0xF5C414
#define pinstCColorPickerWnd_x                                     0xF5C418
#define pinstCPlayerWnd_x                                          0xF5C41C
#define pinstCOptionsWnd_x                                         0xF5C420
#define pinstCBuffWindowNORMAL_x                                   0xF5C424
#define pinstCBuffWindowSHORT_x                                    0xF5C428
#define pinstCharacterCreation_x                                   0xF5C42C
#define pinstCCursorAttachment_x                                   0xF5C430
#define pinstCCastingWnd_x                                         0xF5C434
#define pinstCCastSpellWnd_x                                       0xF5C438
#define pinstCSpellBookWnd_x                                       0xF5C43C
#define pinstCInventoryWnd_x                                       0xF5C440
#define pinstCBankWnd_x                                            0xF5C448
#define pinstCQuantityWnd_x                                        0xF5C44C
#define pinstCLootWnd_x                                            0xF5C450
#define pinstCActionsWnd_x                                         0xF5C454
#define pinstCCombatAbilityWnd_x                                   0xF5C458
#define pinstCMerchantWnd_x                                        0xF5C45C
#define pinstCTradeWnd_x                                           0xF5C460
#define pinstCSelectorWnd_x                                        0xF5C464
#define pinstCBazaarWnd_x                                          0xF5C468
#define pinstCBazaarSearchWnd_x                                    0xF5C46C
#define pinstCGiveWnd_x                                            0xF5C488
#define pinstCTrackingWnd_x                                        0xF5C490
#define pinstCInspectWnd_x                                         0xF5C494
#define pinstCSocialEditWnd_x                                      0xF5C498
#define pinstCFeedbackWnd_x                                        0xF5C49C
#define pinstCBugReportWnd_x                                       0xF5C4A0
#define pinstCVideoModesWnd_x                                      0xF5C4A4
#define pinstCTextEntryWnd_x                                       0xF5C4AC
#define pinstCFileSelectionWnd_x                                   0xF5C4B0
#define pinstCCompassWnd_x                                         0xF5C4B4
#define pinstCPlayerNotesWnd_x                                     0xF5C4B8
#define pinstCGemsGameWnd_x                                        0xF5C4BC
#define pinstCTimeLeftWnd_x                                        0xF5C4C0
#define pinstCPetitionQWnd_x                                       0xF5C4DC
#define pinstCSoulmarkWnd_x                                        0xF5C4E0
#define pinstCStoryWnd_x                                           0xF5C4E4
#define pinstCJournalTextWnd_x                                     0xF5C4E8
#define pinstCJournalCatWnd_x                                      0xF5C4EC
#define pinstCBodyTintWnd_x                                        0xF5C4F0
#define pinstCServerListWnd_x                                      0xF5C4F4
#define pinstCAvaZoneWnd_x                                         0xF5C500
#define pinstCBlockedBuffWnd_x                                     0xF5C504
#define pinstCBlockedPetBuffWnd_x                                  0xF5C508
#define pinstCInvSlotMgr_x                                         0xF5C54C
#define pinstCContainerMgr_x                                       0xF5C550
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
#define pinstCAdvancedLootWnd_x                                    0xF5C540
#define pinstRewardSelectionWnd_x                                  0x11B4EA0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x533BC0
#define __ConvertItemTags_x                                        0x520CF0
#define __ExecuteCmd_x                                             0x50B820
#define __EQGetTime_x                                              0x8A2330
#define __get_melee_range_x                                        0x5124B0
#define __GetGaugeValueFromEQ_x                                    0x7AA6D0
#define __GetLabelFromEQ_x                                         0x7AB920
#define __ToggleKeyRingItem_x                                      0x47ECE0
#define __GetXTargetType_x                                         0x933BE0
#define __LoadFrontEnd_x                                           0x639210
#define __NewUIINI_x                                               0x7A9FD0
#define __ProcessGameEvents_x                                      0x579050
#define __ProcessMouseEvent_x                                      0x5787F0
#define CrashDetected_x                                            0x63ACE0
#define wwsCrashReportCheckForUploader_x                           0x7FDEC0
#define DrawNetStatus_x                                            0x5B0380
#define Util__FastTime_x                                           0x8A1E40
#define Expansion_HoT_x                                            0x101DD34
#define __HelpPath_x                                               0x10A14A8
#define __STMLToText_x                                             0x8E82A0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41FCA0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41AB00

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C5BA0
#define AltAdvManager__IsAbilityReady_x                            0x4C5C10
#define AltAdvManager__GetAAById_x                                 0x4C5FD0
#define AltAdvManager__CanTrainAbility_x                           0x4C6890
#define AltAdvManager__CanSeeAbility_x                             0x4C6490


// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x464ED0
#define CharacterZoneClient__MakeMeVisible_x                       0x46A8B0
#define CharacterZoneClient__IsStackBlocked_x                      0x446DC0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x668CC0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6774C0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58F8E0
#define CButtonWnd__CButtonWnd_x                                   0x8DC5F0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x691F40
#define CChatManager__InitContextMenu_x                            0x692AC0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E6620
#define CContextMenu__dCContextMenu_x                              0x8E6820
#define CContextMenu__AddMenuItem_x                                0x8E6830
#define CContextMenu__RemoveMenuItem_x                             0x8E6B10
#define CContextMenu__RemoveAllMenuItems_x                         0x8E6B30
#define CContextMenuManager__AddMenu_x                             0x8D2570
#define CContextMenuManager__RemoveMenu_x                          0x8D28C0
#define CContextMenuManager__PopupMenu_x                           0x8D2D10
#define CContextMenuManager__Flush_x                               0x8D25E0
#define CContextMenuManager__GetMenu_x                             0x416150

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x887760
#define CChatService__GetFriendName_x                              0x887770

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x697D70
#define CChatWindow__Clear_x                                       0x697920
#define CChatWindow__WndNotification_x                             0x6982A0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D6480
#define CComboWnd__Draw_x                                          0x8D6690
#define CComboWnd__GetCurChoice_x                                  0x8D6250
#define CComboWnd__GetListRect_x                                   0x8D6930
#define CComboWnd__GetTextRect_x                                   0x8D64F0
#define CComboWnd__InsertChoice_x                                  0x8D69A0
#define CComboWnd__SetColors_x                                     0x8D61E0
#define CComboWnd__SetChoice_x                                     0x8D6210
#define CComboWnd__GetItemCount_x                                  0x8D6240

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A1480
#define CContainerWnd__vftable_x                                   0xAE3F68

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B3D50
#define CDisplay__GetClickedActor_x                                0x4AC890
#define CDisplay__GetUserDefinedColor_x                            0x4AB150
#define CDisplay__GetWorldFilePath_x                               0x4AA5A0
#define CDisplay__is3dON_x                                         0x4A9970
#define CDisplay__ReloadUI_x                                       0x4BF320
#define CDisplay__WriteTextHD2_x                                   0x4B00B0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FD270

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EB0C0
#define CEditWnd__GetCharIndexPt_x                                 0x8EC140
#define CEditWnd__GetDisplayString_x                               0x8EB270
#define CEditWnd__GetHorzOffset_x                                  0x8EB5B0
#define CEditWnd__GetLineForPrintableChar_x                        0x8EBC10
#define CEditWnd__GetSelStartPt_x                                  0x8EC3F0
#define CEditWnd__GetSTMLSafeText_x                                0x8EB740
#define CEditWnd__PointFromPrintableChar_x                         0x8EBD00
#define CEditWnd__SelectableCharFromPoint_x                        0x8EBE80
#define CEditWnd__SetEditable_x                                    0x8EB710

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x5553A0
#define CEverQuest__CreateTargetIndicator_x                        0x555FD0
#define CEverQuest__DeleteTargetIndicator_x                        0x556050
#define CEverQuest__DoTellWindow_x                                 0x55ADA0
#define CEverQuest__DropHeldItemOnGround_x                         0x563C90
#define CEverQuest__dsp_chat_x                                     0x55C750
#define CEverQuest__Emote_x                                        0x55C9B0
#define CEverQuest__EnterZone_x                                    0x570DE0
#define CEverQuest__GetBodyTypeDesc_x                              0x551C00
#define CEverQuest__GetClassDesc_x                                 0x557910
#define CEverQuest__GetClassThreeLetterCode_x                      0x557F10
#define CEverQuest__GetDeityDesc_x                                 0x5524E0
#define CEverQuest__GetLangDesc_x                                  0x551F90
#define CEverQuest__GetRaceDesc_x                                  0x5580D0
#define CEverQuest__InterpretCmd_x                                 0x55D290
#define CEverQuest__LeftClickedOnPlayer_x                          0x575750
#define CEverQuest__LMouseUp_x                                     0x577840
#define CEverQuest__RightClickedOnPlayer_x                         0x576250
#define CEverQuest__RMouseUp_x                                     0x5772A0
#define CEverQuest__SetGameState_x                                 0x555A50
#define CEverQuest__UPCNotificationFlush_x                         0x55E5F0
#define CEverQuest__IssuePetCommand_x                              0x55DF50

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B20A0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B2100
#define CGaugeWnd__Draw_x                                          0x6B2530

// CGuild
#define CGuild__FindMemberByName_x                                 0x436A90

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CF160

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DB8E0
#define CInvSlotMgr__MoveItem_x                                    0x6DC820
#define CInvSlotMgr__SelectSlot_x                                  0x6DB990

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6DAD70
#define CInvSlot__SliderComplete_x                                 0x6D85A0
#define CInvSlot__GetItemBase_x                                    0x6D7A30

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DDBE0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A7030
#define CItemDisplayWnd__UpdateStrings_x                           0x6DEF00

// CLabel 
#define CLabel__Draw_x                                             0x6F9DC0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C2210
#define CListWnd__dCListWnd_x                                      0x8C3230
#define CListWnd__AddColumn_x                                      0x8C31D0
#define CListWnd__AddColumn1_x                                     0x8C2A50
#define CListWnd__AddLine_x                                        0x8C24D0
#define CListWnd__AddString_x                                      0x8C26E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BF560
#define CListWnd__CalculateVSBRange_x                              0x8C16C0
#define CListWnd__ClearAllSel_x                                    0x8BE840
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C20A0
#define CListWnd__Compare_x                                        0x8C0050
#define CListWnd__Draw_x                                           0x8C12D0
#define CListWnd__DrawColumnSeparators_x                           0x8C1160
#define CListWnd__DrawHeader_x                                     0x8BEB50
#define CListWnd__DrawItem_x                                       0x8C06A0
#define CListWnd__DrawLine_x                                       0x8C0E00
#define CListWnd__DrawSeparator_x                                  0x8C1200
#define CListWnd__EnsureVisible_x                                  0x8BF6C0
#define CListWnd__ExtendSel_x                                      0x8C05B0
#define CListWnd__GetColumnMinWidth_x                              0x8BE200
#define CListWnd__GetColumnWidth_x                                 0x8BE120
#define CListWnd__GetCurSel_x                                      0x8BD900
#define CListWnd__GetItemAtPoint_x                                 0x8BF950
#define CListWnd__GetItemAtPoint1_x                                0x8BF9C0
#define CListWnd__GetItemData_x                                    0x8BDC30
#define CListWnd__GetItemHeight_x                                  0x8BF1D0
#define CListWnd__GetItemIcon_x                                    0x8BDE10
#define CListWnd__GetItemRect_x                                    0x8BF790
#define CListWnd__GetItemText_x                                    0x8BDCC0
#define CListWnd__GetSelList_x                                     0x8C2940
#define CListWnd__GetSeparatorRect_x                               0x8BFF80
#define CListWnd__RemoveLine_x                                     0x8C28C0
#define CListWnd__SetColors_x                                      0x8BDA50
#define CListWnd__SetColumnJustification_x                         0x8BE4D0
#define CListWnd__SetColumnWidth_x                                 0x8BE1B0
#define CListWnd__SetCurSel_x                                      0x8BD940
#define CListWnd__SetItemColor_x                                   0x8C1D80
#define CListWnd__SetItemData_x                                    0x8BE8F0
#define CListWnd__SetItemText_x                                    0x8C1BC0
#define CListWnd__ShiftColumnSeparator_x                           0x8C1A50
#define CListWnd__Sort_x                                           0x8C3330
#define CListWnd__ToggleSel_x                                      0x8BE7C0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7133A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7345C0
#define CMerchantWnd__RequestBuyItem_x                             0x73B410
#define CMerchantWnd__RequestSellItem_x                            0x73BE80
#define CMerchantWnd__SelectRecoverySlot_x                         0x734870
#define CMerchantWnd__SelectBuySellSlot_x                          0x733AD0
#define CMerchantWnd__ActualSelect_x                               0x738340

// CObfuscator
#define CObfuscator__doit_x                                        0x852D20

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E1590
#define CSidlManager__CreateLabel_x                                0x79CF50

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65FFE0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65FF00
#define CSidlScreenWnd__ConvertToRes_x                             0x8FD150
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D9100
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DA610
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DA6C0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D9B80
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D8AB0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D8200
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D8CA0
#define CSidlScreenWnd__Init1_x                                    0x8DA2E0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D91B0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D83C0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D9DD0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D7CC0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D8190
#define CSidlScreenWnd__WndNotification_x                          0x8DA060
#define CSidlScreenWnd__GetChildItem_x                             0x8D82D0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CB870

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FAFE0
#define CSkillMgr__GetSkillCap_x                                   0x5FB1A0
#define CSkillMgr__GetNameToken_x                                  0x5FAC00

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FC410
#define CSliderWnd__SetValue_x                                     0x8FC5E0
#define CSliderWnd__SetNumTicks_x                                  0x8FCD60

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A4CE0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F7D80
#define CStmlWnd__CalculateHSBRange_x                              0x8F02D0
#define CStmlWnd__CalculateVSBRange_x                              0x8F0360
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F04E0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F0DC0
#define CStmlWnd__ForceParseNow_x                                  0x8F86D0
#define CStmlWnd__GetNextTagPiece_x                                0x8F0CC0
#define CStmlWnd__GetSTMLText_x                                    0x6971C0
#define CStmlWnd__GetVisibleText_x                                 0x8F1810
#define CStmlWnd__InitializeWindowVariables_x                      0x8F3B80
#define CStmlWnd__MakeStmlColorTag_x                               0x8EF5D0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EF630
#define CStmlWnd__SetSTMLText_x                                    0x8F53E0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F7A20
#define CStmlWnd__UpdateHistoryString_x                            0x8F2740

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8EEC60
#define CTabWnd__DrawCurrentPage_x                                 0x8EE4D0
#define CTabWnd__DrawTab_x                                         0x8EE2A0
#define CTabWnd__GetCurrentPage_x                                  0x8EE8A0
#define CTabWnd__GetPageInnerRect_x                                0x8EDF90
#define CTabWnd__GetTabInnerRect_x                                 0x8EE190
#define CTabWnd__GetTabRect_x                                      0x8EE060
#define CTabWnd__InsertPage_x                                      0x8EEF50
#define CTabWnd__SetPage_x                                         0x8EE8D0
#define CTabWnd__SetPageRect_x                                     0x8EEBA0
#define CTabWnd__UpdatePage_x                                      0x8EEEF0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432870

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D5E50

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x902680

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BBB60

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59CFA0
#define CXStr__CXStr1_x                                            0x4030C0
#define CXStr__CXStr3_x                                            0x89EED0
#define CXStr__dCXStr_x                                            0x79CF00
#define CXStr__operator_equal_x                                    0x89F040
#define CXStr__operator_equal1_x                                   0x89F090
#define CXStr__operator_plus_equal1_x                              0x8A0170

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8CAAD0
#define CXWnd__Center_x                                            0x8D0BA0
#define CXWnd__ClrFocus_x                                          0x8CA6A0
#define CXWnd__DoAllDrawing_x                                      0x8D07F0
#define CXWnd__DrawChildren_x                                      0x8D0990
#define CXWnd__DrawColoredRect_x                                   0x8CAE90
#define CXWnd__DrawTooltip_x                                       0x8CB130
#define CXWnd__DrawTooltipAtPoint_x                                0x8CF7C0
#define CXWnd__GetBorderFrame_x                                    0x8CB580
#define CXWnd__GetChildWndAt_x                                     0x8D1550
#define CXWnd__GetClientClipRect_x                                 0x8CB340
#define CXWnd__GetScreenClipRect_x                                 0x8CFEB0
#define CXWnd__GetScreenRect_x                                     0x8CB710
#define CXWnd__GetTooltipRect_x                                    0x8CAFC0
#define CXWnd__GetWindowTextA_x                                    0x423CE0
#define CXWnd__IsActive_x                                          0x8C5FD0
#define CXWnd__IsDescendantOf_x                                    0x8CB4D0
#define CXWnd__IsReallyVisible_x                                   0x8CE810
#define CXWnd__IsType_x                                            0x8FEE80
#define CXWnd__Move_x                                              0x8CDEF0
#define CXWnd__Move1_x                                             0x8D04B0
#define CXWnd__ProcessTransition_x                                 0x8CAA70
#define CXWnd__Refade_x                                            0x8CA840
#define CXWnd__Resize_x                                            0x8CB7D0
#define CXWnd__Right_x                                             0x8CFCB0
#define CXWnd__SetFocus_x                                          0x8CD060
#define CXWnd__SetFont_x                                           0x8CA6F0
#define CXWnd__SetKeyTooltip_x                                     0x8CBA40
#define CXWnd__SetMouseOver_x                                      0x8D01B0
#define CXWnd__StartFade_x                                         0x8CAB20
#define CXWnd__GetChildItem_x                                      0x8D00F0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C78F0
#define CXWndManager__DrawWindows_x                                0x8C7530
#define CXWndManager__GetKeyboardFlags_x                           0x8C5B40
#define CXWndManager__HandleKeyboardMsg_x                          0x8C6460
#define CXWndManager__RemoveWnd_x                                  0x8C6160

// CDBStr
#define CDBStr__GetString_x                                        0x4A7EE0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44EA10
#define EQ_Character__Cur_HP_x                                     0x4645A0
#define EQ_Character__GetAACastingTimeModifier_x                   0x446940
#define EQ_Character__GetCharInfo2_x                               0x872340
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EC60
#define EQ_Character__GetFocusRangeModifier_x                      0x43EE50
#define EQ_Character__Max_Endurance_x                              0x5C28A0
#define EQ_Character__Max_HP_x                                     0x45A1E0
#define EQ_Character__Max_Mana_x                                   0x5C26D0
#define EQ_Character__doCombatAbility_x                            0x5BFD20
#define EQ_Character__UseSkill_x                                   0x46FAB0
#define EQ_Character__GetConLevel_x                                0x5B4970
#define EQ_Character__IsExpansionFlag_x                            0x423230
#define EQ_Character__TotalEffect_x                                0x44BCC0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x595210
#define EQ_Item__CreateItemTagString_x                             0x8515E0
#define EQ_Item__IsStackable_x                                     0x845950
#define EQ_Item__GetImageNum_x                                     0x8486B0
#define EQ_Item__CreateItemClient_x                                0x595DF0
#define EQ_Item__GetItemValue_x                                    0x850290
#define EQ_Item__ValueSellMerchant_x                               0x852960

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C7CD0
#define EQ_LoadingS__Array_x                                       0xC20720

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C3F00
#define EQ_PC__GetAlternateAbilityId_x                             0x85AC80
#define EQ_PC__GetCombatAbility_x                                  0x85AD10
#define EQ_PC__GetCombatAbilityTimer_x                             0x855AA0
#define EQ_PC__GetItemTimerValue_x                                 0x5BD830
#define EQ_PC__HasLoreItem_x                                       0x5B7E40
#define EQ_PC__AlertInventoryChanged_x                             0x5B4940
#define EQ_PC__GetPcZoneClient_x                                   0x5DE500
#define EQ_PC__RemoveMyAffect_x                                    0x5BCCF0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x510510
#define EQItemList__add_item_x                                     0x510450
#define EQItemList__delete_item_x                                  0x510910
#define EQItemList__FreeItemList_x                                 0x510810

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A71A0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C9470
#define EQPlayer__dEQPlayer_x                                      0x5D22F0
#define EQPlayer__DoAttack_x                                       0x5E4400
#define EQPlayer__EQPlayer_x                                       0x5D4710
#define EQPlayer__SetNameSpriteState_x                             0x5CEFC0
#define EQPlayer__SetNameSpriteTint_x                              0x5CA880
#define EQPlayer__IsBodyType_j_x                                   0x92FD70
#define EQPlayer__IsTargetable_x                                   0x930670
#define EQPlayer__CanSee_x                                         0x930B90
#define PlayerZoneClient__ChangeHeight_x                           0x5E42C0
#define EQPlayer__CanSeeTargetIndicator_x                          0x930C80

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D8A90
#define EQPlayerManager__GetSpawnByName_x                          0x5D8EF0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59B2D0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59B310
#define KeypressHandler__ClearCommandStateArray_x                  0x59AEB0
#define KeypressHandler__HandleKeyDown_x                           0x599810
#define KeypressHandler__HandleKeyUp_x                             0x599B30
#define KeypressHandler__SaveKeymapping_x                          0x59AF80

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70B780
#define MapViewMap__SaveEx_x                                       0x70F060

#define PlayerPointManager__GetAltCurrency_x                       0x86D2F0

// StringTable 
#define StringTable__getString_x                                   0x867D60

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C2350
#define PcZoneClient__RemovePetEffect_x                            0x5BDD20
#define PcZoneClient__HasAlternateAbility_x                        0x5BE7E0

//Doors
#define EQSwitch__UseSwitch_x                                      0x54EFB0

//IconCache
#define IconCache__GetIcon_x                                       0x6A79A0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69E7A0
#define CContainerMgr__CloseContainer_x                            0x69EFC0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76D0F0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58E380

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DF590
#define EQ_Spell__SpellAffects_x                                   0x4DF630
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DF660
#define CharacterZoneClient__CalcAffectChange_x                    0x447D30
#define CLootWnd__LootAll_x                                        0x7010F0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B2CE0
#define CTargetWnd__WndNotification_x                              0x7B27D0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B7EC0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D8E00

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x497820

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EA6F0
#define CSidlManager__FindAnimation1_x                             0x8DF490

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CF370
#define CAltAbilityData__GetMercMaxRank_x                          0x4CF320
#define CAltAbilityData__GetMaxRank_x                              0x4C4260

//CTargetRing
#define CTargetRing__Cast_x                                        0x58BC60
