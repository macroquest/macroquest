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
#define __ExpectedVersionDate                                     "Jan 13 2016"
#define __ExpectedVersionTime                                     "12:22:39"
#define __ActualVersionDate_x                                      0xADA580
#define __ActualVersionTime_x                                      0xADA58C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5A00D0
#define __MemChecker1_x                                            0x8A29E0
#define __MemChecker2_x                                            0x639100
#define __MemChecker3_x                                            0x639050
#define __MemChecker4_x                                            0x7EE980
#define __EncryptPad0_x                                            0xC77388
#define __EncryptPad1_x                                            0xE02508
#define __EncryptPad2_x                                            0xCC0E70
#define __EncryptPad3_x                                            0xCC0A70
#define __EncryptPad4_x                                            0xDDB5F8
#define __EncryptPad5_x                                            0x11AE3D0
#define __AC1_x                                                    0x7AB5D5
#define __AC2_x                                                    0x5543C7
#define __AC3_x                                                    0x568F80
#define __AC4_x                                                    0x56FC00
#define __AC5_x                                                    0x57C3BE
#define __AC6_x                                                    0x57FF69
#define __AC7_x                                                    0x576A6C
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
#define __do_loot_x                                                0x51B8E0
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
#define pinstPlayerPath_x                                          0x10A24F0
#define pinstTargetIndicator_x                                     0x10A2E88
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
#define __CastRay_x                                                0x533430
#define __ConvertItemTags_x                                        0x520560
#define __ExecuteCmd_x                                             0x50B070
#define __EQGetTime_x                                              0x8A2610
#define __get_melee_range_x                                        0x511D20
#define __GetGaugeValueFromEQ_x                                    0x7AA310
#define __GetLabelFromEQ_x                                         0x7AB560
#define __ToggleKeyRingItem_x                                      0x47EE70
#define __GetXTargetType_x                                         0x933DB0
#define __LoadFrontEnd_x                                           0x6387B0
#define __NewUIINI_x                                               0x7A9C10
#define __ProcessGameEvents_x                                      0x5787D0
#define __ProcessMouseEvent_x                                      0x577F70
#define CrashDetected_x                                            0x63A280
#define wwsCrashReportCheckForUploader_x                           0x7FDF50
#define DrawNetStatus_x                                            0x5AFBE0
#define Util__FastTime_x                                           0x8A2120
#define Expansion_HoT_x                                            0x101DD34
#define __HelpPath_x                                               0x10A14A8
#define __STMLToText_x                                             0x8E8610

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41FC50
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41AAA0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C6060
#define AltAdvManager__IsAbilityReady_x                            0x4C60D0
#define AltAdvManager__GetAAById_x                                 0x4C6490
#define AltAdvManager__CanTrainAbility_x                           0x4C6D50
#define AltAdvManager__CanSeeAbility_x                             0x4C6950


// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x464FB0
#define CharacterZoneClient__MakeMeVisible_x                       0x46A990
#define CharacterZoneClient__IsStackBlocked_x                      0x446F50

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x668370

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x676040

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58F010
#define CButtonWnd__CButtonWnd_x                                   0x8DC950

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x691750
#define CChatManager__InitContextMenu_x                            0x6922D0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E6970
#define CContextMenu__dCContextMenu_x                              0x8E6B80
#define CContextMenu__AddMenuItem_x                                0x8E6B90
#define CContextMenu__RemoveMenuItem_x                             0x8E6E80
#define CContextMenu__RemoveAllMenuItems_x                         0x8E6EA0
#define CContextMenuManager__AddMenu_x                             0x8D2880
#define CContextMenuManager__RemoveMenu_x                          0x8D2BE0
#define CContextMenuManager__PopupMenu_x                           0x8D3030
#define CContextMenuManager__Flush_x                               0x8D28F0
#define CContextMenuManager__GetMenu_x                             0x4160D0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x887940
#define CChatService__GetFriendName_x                              0x887950

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x697570
#define CChatWindow__Clear_x                                       0x697130
#define CChatWindow__WndNotification_x                             0x697AA0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D6790
#define CComboWnd__Draw_x                                          0x8D69A0
#define CComboWnd__GetCurChoice_x                                  0x8D6560
#define CComboWnd__GetListRect_x                                   0x8D6C40
#define CComboWnd__GetTextRect_x                                   0x8D6800
#define CComboWnd__InsertChoice_x                                  0x8D6CB0
#define CComboWnd__SetColors_x                                     0x8D64F0
#define CComboWnd__SetChoice_x                                     0x8D6520
#define CComboWnd__GetItemCount_x                                  0x8D6550

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A0C30
#define CContainerWnd__vftable_x                                   0xAE3F68

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B4130
#define CDisplay__GetClickedActor_x                                0x4ACC70
#define CDisplay__GetUserDefinedColor_x                            0x4AB530
#define CDisplay__GetWorldFilePath_x                               0x4AA980
#define CDisplay__is3dON_x                                         0x4A9D50
#define CDisplay__ReloadUI_x                                       0x4BF710
#define CDisplay__WriteTextHD2_x                                   0x4B0490

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FD5C0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EB310
#define CEditWnd__GetCharIndexPt_x                                 0x8EC3B0
#define CEditWnd__GetDisplayString_x                               0x8EB4C0
#define CEditWnd__GetHorzOffset_x                                  0x8EB800
#define CEditWnd__GetLineForPrintableChar_x                        0x8EBE70
#define CEditWnd__GetSelStartPt_x                                  0x8EC670
#define CEditWnd__GetSTMLSafeText_x                                0x8EB9A0
#define CEditWnd__PointFromPrintableChar_x                         0x8EBF60
#define CEditWnd__SelectableCharFromPoint_x                        0x8EC0E0
#define CEditWnd__SetEditable_x                                    0x8EB970

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x554B10
#define CEverQuest__CreateTargetIndicator_x                        0x555740
#define CEverQuest__DeleteTargetIndicator_x                        0x5557C0
#define CEverQuest__DoTellWindow_x                                 0x55A510
#define CEverQuest__DropHeldItemOnGround_x                         0x563400
#define CEverQuest__dsp_chat_x                                     0x55BEC0
#define CEverQuest__Emote_x                                        0x55C120
#define CEverQuest__EnterZone_x                                    0x570550
#define CEverQuest__GetBodyTypeDesc_x                              0x551370
#define CEverQuest__GetClassDesc_x                                 0x557080
#define CEverQuest__GetClassThreeLetterCode_x                      0x557680
#define CEverQuest__GetDeityDesc_x                                 0x551C50
#define CEverQuest__GetLangDesc_x                                  0x551700
#define CEverQuest__GetRaceDesc_x                                  0x557840
#define CEverQuest__InterpretCmd_x                                 0x55CA00
#define CEverQuest__LeftClickedOnPlayer_x                          0x574ED0
#define CEverQuest__LMouseUp_x                                     0x576FC0
#define CEverQuest__RightClickedOnPlayer_x                         0x5759D0
#define CEverQuest__RMouseUp_x                                     0x576A20
#define CEverQuest__SetGameState_x                                 0x5551C0
#define CEverQuest__UPCNotificationFlush_x                         0x55DD60
#define CEverQuest__IssuePetCommand_x                              0x55D6C0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B1A40
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B1AA0
#define CGaugeWnd__Draw_x                                          0x6B1ED0

// CGuild
#define CGuild__FindMemberByName_x                                 0x436BF0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CEB70

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DB2F0
#define CInvSlotMgr__MoveItem_x                                    0x6DC230
#define CInvSlotMgr__SelectSlot_x                                  0x6DB3A0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6DA780
#define CInvSlot__SliderComplete_x                                 0x6D7FB0
#define CInvSlot__GetItemBase_x                                    0x6D7430

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DD630

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A6C90
#define CItemDisplayWnd__UpdateStrings_x                           0x6DE970

// CLabel 
#define CLabel__Draw_x                                             0x6F98D0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C2520
#define CListWnd__dCListWnd_x                                      0x8C3550
#define CListWnd__AddColumn_x                                      0x8C34F0
#define CListWnd__AddColumn1_x                                     0x8C2D60
#define CListWnd__AddLine_x                                        0x8C27E0
#define CListWnd__AddString_x                                      0x8C29F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BF850
#define CListWnd__CalculateVSBRange_x                              0x8C19E0
#define CListWnd__ClearAllSel_x                                    0x8BEB00
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C23B0
#define CListWnd__Compare_x                                        0x8C0360
#define CListWnd__Draw_x                                           0x8C15F0
#define CListWnd__DrawColumnSeparators_x                           0x8C1480
#define CListWnd__DrawHeader_x                                     0x8BEE10
#define CListWnd__DrawItem_x                                       0x8C09B0
#define CListWnd__DrawLine_x                                       0x8C1120
#define CListWnd__DrawSeparator_x                                  0x8C1520
#define CListWnd__EnsureVisible_x                                  0x8BF9B0
#define CListWnd__ExtendSel_x                                      0x8C08C0
#define CListWnd__GetColumnMinWidth_x                              0x8BE4C0
#define CListWnd__GetColumnWidth_x                                 0x8BE3E0
#define CListWnd__GetCurSel_x                                      0x8BDBB0
#define CListWnd__GetItemAtPoint_x                                 0x8BFC50
#define CListWnd__GetItemAtPoint1_x                                0x8BFCC0
#define CListWnd__GetItemData_x                                    0x8BDEF0
#define CListWnd__GetItemHeight_x                                  0x8BF4A0
#define CListWnd__GetItemIcon_x                                    0x8BE0D0
#define CListWnd__GetItemRect_x                                    0x8BFA90
#define CListWnd__GetItemText_x                                    0x8BDF80
#define CListWnd__GetSelList_x                                     0x8C2C50
#define CListWnd__GetSeparatorRect_x                               0x8C0280
#define CListWnd__RemoveLine_x                                     0x8C2BD0
#define CListWnd__SetColors_x                                      0x8BDD00
#define CListWnd__SetColumnJustification_x                         0x8BE790
#define CListWnd__SetColumnWidth_x                                 0x8BE470
#define CListWnd__SetCurSel_x                                      0x8BDBF0
#define CListWnd__SetItemColor_x                                   0x8C2090
#define CListWnd__SetItemData_x                                    0x8BEBB0
#define CListWnd__SetItemText_x                                    0x8C1ED0
#define CListWnd__ShiftColumnSeparator_x                           0x8C1D60
#define CListWnd__Sort_x                                           0x8C3650
#define CListWnd__ToggleSel_x                                      0x8BEA80

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x712EB0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x734320
#define CMerchantWnd__RequestBuyItem_x                             0x73B160
#define CMerchantWnd__RequestSellItem_x                            0x73BBD0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7345D0
#define CMerchantWnd__SelectBuySellSlot_x                          0x733830
#define CMerchantWnd__ActualSelect_x                               0x738090

// CObfuscator
#define CObfuscator__doit_x                                        0x852F60

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E1910
#define CSidlManager__CreateLabel_x                                0x79CBE0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65F6B0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65F5E0
#define CSidlScreenWnd__ConvertToRes_x                             0x8FD4A0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D9440
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DA940
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DA9F0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D9EA0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D8DF0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D8530
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D8FE0
#define CSidlScreenWnd__Init1_x                                    0x8DA610
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D94F0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D86F0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DA0F0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D7FF0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D84C0
#define CSidlScreenWnd__WndNotification_x                          0x8DA390
#define CSidlScreenWnd__GetChildItem_x                             0x8D8600
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CBB90

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FA850
#define CSkillMgr__GetSkillCap_x                                   0x5FAA10
#define CSkillMgr__GetNameToken_x                                  0x5FA470

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FC740
#define CSliderWnd__SetValue_x                                     0x8FC910
#define CSliderWnd__SetNumTicks_x                                  0x8FD090

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A4940

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F8070
#define CStmlWnd__CalculateHSBRange_x                              0x8F0580
#define CStmlWnd__CalculateVSBRange_x                              0x8F0610
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F0790
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F1070
#define CStmlWnd__ForceParseNow_x                                  0x8F89C0
#define CStmlWnd__GetNextTagPiece_x                                0x8F0F70
#define CStmlWnd__GetSTMLText_x                                    0x6969D0
#define CStmlWnd__GetVisibleText_x                                 0x8F1AC0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F3E50
#define CStmlWnd__MakeStmlColorTag_x                               0x8EF880
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EF8E0
#define CStmlWnd__SetSTMLText_x                                    0x8F56B0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F7D10
#define CStmlWnd__UpdateHistoryString_x                            0x8F2A00

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8EEF10
#define CTabWnd__DrawCurrentPage_x                                 0x8EE780
#define CTabWnd__DrawTab_x                                         0x8EE540
#define CTabWnd__GetCurrentPage_x                                  0x8EEB50
#define CTabWnd__GetPageInnerRect_x                                0x8EE230
#define CTabWnd__GetTabInnerRect_x                                 0x8EE430
#define CTabWnd__GetTabRect_x                                      0x8EE300
#define CTabWnd__InsertPage_x                                      0x8EF200
#define CTabWnd__SetPage_x                                         0x8EEB80
#define CTabWnd__SetPageRect_x                                     0x8EEE50
#define CTabWnd__UpdatePage_x                                      0x8EF1A0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432A30

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D6160

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x902950

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BBE00

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59C640
#define CXStr__CXStr1_x                                            0x8BCDD0
#define CXStr__CXStr3_x                                            0x89F1B0
#define CXStr__dCXStr_x                                            0x4C0080
#define CXStr__operator_equal_x                                    0x89F320
#define CXStr__operator_equal1_x                                   0x89F370
#define CXStr__operator_plus_equal1_x                              0x8A0450

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8CADD0
#define CXWnd__Center_x                                            0x8D0E70
#define CXWnd__ClrFocus_x                                          0x8CA9B0
#define CXWnd__DoAllDrawing_x                                      0x8D0AA0
#define CXWnd__DrawChildren_x                                      0x8D0C50
#define CXWnd__DrawColoredRect_x                                   0x8CB180
#define CXWnd__DrawTooltip_x                                       0x8CB430
#define CXWnd__DrawTooltipAtPoint_x                                0x8CFA30
#define CXWnd__GetBorderFrame_x                                    0x8CB890
#define CXWnd__GetChildWndAt_x                                     0x8D1820
#define CXWnd__GetClientClipRect_x                                 0x8CB650
#define CXWnd__GetScreenClipRect_x                                 0x8D0130
#define CXWnd__GetScreenRect_x                                     0x8CBA40
#define CXWnd__GetTooltipRect_x                                    0x8CB2C0
#define CXWnd__GetWindowTextA_x                                    0x423C60
#define CXWnd__IsActive_x                                          0x8C6350
#define CXWnd__IsDescendantOf_x                                    0x8CB7E0
#define CXWnd__IsReallyVisible_x                                   0x8CEA70
#define CXWnd__IsType_x                                            0x8FF170
#define CXWnd__Move_x                                              0x8CE240
#define CXWnd__Move1_x                                             0x8D0760
#define CXWnd__ProcessTransition_x                                 0x8CAD80
#define CXWnd__Refade_x                                            0x8CAB60
#define CXWnd__Resize_x                                            0x8CBB00
#define CXWnd__Right_x                                             0x8CFF30
#define CXWnd__SetFocus_x                                          0x8CD3C0
#define CXWnd__SetFont_x                                           0x8CAA00
#define CXWnd__SetKeyTooltip_x                                     0x8CBD60
#define CXWnd__SetMouseOver_x                                      0x8D0450
#define CXWnd__StartFade_x                                         0x8CAE20
#define CXWnd__GetChildItem_x                                      0x8D0390

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C7C70
#define CXWndManager__DrawWindows_x                                0x8C78B0
#define CXWndManager__GetKeyboardFlags_x                           0x8C5E80
#define CXWndManager__HandleKeyboardMsg_x                          0x8C67E0
#define CXWndManager__RemoveWnd_x                                  0x8C64E0

// CDBStr
#define CDBStr__GetString_x                                        0x4A8240

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44EB00
#define EQ_Character__Cur_HP_x                                     0x464680
#define EQ_Character__GetAACastingTimeModifier_x                   0x446AD0
#define EQ_Character__GetCharInfo2_x                               0x872550
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EDD0
#define EQ_Character__GetFocusRangeModifier_x                      0x43EFC0
#define EQ_Character__Max_Endurance_x                              0x5C2350
#define EQ_Character__Max_HP_x                                     0x45A2D0
#define EQ_Character__Max_Mana_x                                   0x5C2180
#define EQ_Character__doCombatAbility_x                            0x5BF7C0
#define EQ_Character__UseSkill_x                                   0x46FB90
#define EQ_Character__GetConLevel_x                                0x5B4220
#define EQ_Character__IsExpansionFlag_x                            0x4231B0
#define EQ_Character__TotalEffect_x                                0x44BDE0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5948F0
#define EQ_Item__CreateItemTagString_x                             0x851820
#define EQ_Item__IsStackable_x                                     0x8459D0
#define EQ_Item__GetImageNum_x                                     0x8486B0
#define EQ_Item__CreateItemClient_x                                0x5954A0
#define EQ_Item__GetItemValue_x                                    0x8504C0
#define EQ_Item__ValueSellMerchant_x                               0x852BA0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C81A0
#define EQ_LoadingS__Array_x                                       0xC20720

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C39B0
#define EQ_PC__GetAlternateAbilityId_x                             0x85AE20
#define EQ_PC__GetCombatAbility_x                                  0x85AEB0
#define EQ_PC__GetCombatAbilityTimer_x                             0x855CF0
#define EQ_PC__GetItemTimerValue_x                                 0x5BD2F0
#define EQ_PC__HasLoreItem_x                                       0x5B76F0
#define EQ_PC__AlertInventoryChanged_x                             0x5B41F0
#define EQ_PC__GetPcZoneClient_x                                   0x5DDEE0
#define EQ_PC__RemoveMyAffect_x                                    0x5BC790

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50FD60
#define EQItemList__add_item_x                                     0x50FCA0
#define EQItemList__delete_item_x                                  0x510160
#define EQItemList__FreeItemList_x                                 0x510060

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A73F0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C8F40
#define EQPlayer__dEQPlayer_x                                      0x5D1DC0
#define EQPlayer__DoAttack_x                                       0x5E3DC0
#define EQPlayer__EQPlayer_x                                       0x5D41E0
#define EQPlayer__SetNameSpriteState_x                             0x5CEA90
#define EQPlayer__SetNameSpriteTint_x                              0x5CA350
#define EQPlayer__IsBodyType_j_x                                   0x92FFB0
#define EQPlayer__IsTargetable_x                                   0x9308B0
#define EQPlayer__CanSee_x                                         0x930DD0
#define PlayerZoneClient__ChangeHeight_x                           0x5E3C80
#define EQPlayer__CanSeeTargetIndicator_x                          0x930EC0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D84E0
#define EQPlayerManager__GetSpawnByName_x                          0x5D8940

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59A970
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59A9B0
#define KeypressHandler__ClearCommandStateArray_x                  0x59A550
#define KeypressHandler__HandleKeyDown_x                           0x598EB0
#define KeypressHandler__HandleKeyUp_x                             0x5991D0
#define KeypressHandler__SaveKeymapping_x                          0x59A620

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70B290
#define MapViewMap__SaveEx_x                                       0x70EB70

#define PlayerPointManager__GetAltCurrency_x                       0x86D4F0

// StringTable 
#define StringTable__getString_x                                   0x867F20

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C1E00
#define PcZoneClient__RemovePetEffect_x                            0x5BD7E0
#define PcZoneClient__HasAlternateAbility_x                        0x5BE2A0

//Doors
#define EQSwitch__UseSwitch_x                                      0x54E6D0

//IconCache
#define IconCache__GetIcon_x                                       0x6A7160

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69DF30
#define CContainerMgr__CloseContainer_x                            0x69E750

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76CE70

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58DAB0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DF8C0
#define EQ_Spell__SpellAffects_x                                   0x4DF960
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DF990
#define CharacterZoneClient__CalcAffectChange_x                    0x447E70
#define CLootWnd__LootAll_x                                        0x700A90

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B28B0
#define CTargetWnd__WndNotification_x                              0x7B23A0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B7A90

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D9190

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4979E0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EA940
#define CSidlManager__FindAnimation1_x                             0x8DF800

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CF7C0
#define CAltAbilityData__GetMercMaxRank_x                          0x4CF770
#define CAltAbilityData__GetMaxRank_x                              0x4C4720

//CTargetRing
#define CTargetRing__Cast_x                                        0x58B3A0
