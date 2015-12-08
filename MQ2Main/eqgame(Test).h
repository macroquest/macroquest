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
#define __ExpectedVersionDate                                     "Dec  7 2015"
#define __ExpectedVersionTime                                     "20:56:06"
#define __ActualVersionDate_x                                      0xAD9568
#define __ActualVersionTime_x                                      0xAD9574

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59F820
#define __MemChecker1_x                                            0x8A1A30
#define __MemChecker2_x                                            0x638C00
#define __MemChecker3_x                                            0x638B50
#define __MemChecker4_x                                            0x7ED410
#define __EncryptPad0_x                                            0xC76388
#define __EncryptPad1_x                                            0xE01508
#define __EncryptPad2_x                                            0xCBFE70
#define __EncryptPad3_x                                            0xCBFA70
#define __EncryptPad4_x                                            0xDDA5F8
#define __EncryptPad5_x                                            0x11AD3D0
#define __AC1_x                                                    0x7AA895
#define __AC2_x                                                    0x553987
#define __AC3_x                                                    0x568540
#define __AC4_x                                                    0x56F1C0
#define __AC5_x                                                    0x57B96E
#define __AC6_x                                                    0x57F519
#define __AC7_x                                                    0x57601C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FF27C

// Direct Input
#define DI8__Main_x                                                0x11AD3A8
#define DI8__Keyboard_x                                            0x11AD3AC
#define DI8__Mouse_x                                               0x11AD3B0
#define DI8__Mouse_Copy_x                                          0x101B9BC
#define DI8__Mouse_Check_x                                         0x10A5294
#define __AltTimerReady_x                                          0x100CD09
#define __Attack_x                                                 0x109FF37
#define __Autofire_x                                               0x109FF38
#define __BindList_x                                               0xC38458
#define __bCommandEnabled_x                                        0x100AE18
#define __Clicks_x                                                 0x101BA78
#define __CommandList_x                                            0xC3C7C8
#define __CurrentMapLabel_x                                        0x11B2E00
#define __CurrentSocial_x                                          0xBEF5BC
#define __DoAbilityList_x                                          0x10521EC
#define __do_loot_x                                                0x51AE20
#define __DrawHandler_x                                            0x1819BB4
#define __GroupCount_x                                             0x100C3E2

#define __Guilds_x                                                 0x1011FF8
#define __gWorld_x                                                 0x100E89C
#define __HotkeyPage_x                                             0x1098BEC
#define __HWnd_x                                                   0x10A52B0
#define __InChatMode_x                                             0x101B9A4
#define __LastTell_x                                               0x101D8E8
#define __LMouseHeldTime_x                                         0x101BAE4
#define __Mouse_x                                                  0x11AD3B4
#define __MouseLook_x                                              0x101BA3E
#define __MouseEventTime_x                                         0x10A073C
#define __gpbCommandEvent_x                                        0x100E964
#define __NetStatusToggle_x                                        0x101BA41
#define __PCNames_x                                                0x101CF08
#define __RangeAttackReady_x                                       0x101CBC8
#define __RMouseHeldTime_x                                         0x101BAE0
#define __RunWalkState_x                                           0x101B9A8
#define __ScreenMode_x                                             0xF5AB48
#define __ScreenX_x                                                0x101B95C
#define __ScreenY_x                                                0x101B958
#define __ScreenXMax_x                                             0x101B960
#define __ScreenYMax_x                                             0x101B964
#define __ServerHost_x                                             0x100C32C
#define __ServerName_x                                             0x10521AC
#define __ShiftKeyDown_x                                           0x101C04C
#define __ShowNames_x                                              0x101CD9C
#define __Socials_x                                                0x10522AC
#define __SubscriptionType_x                                       0x11E1330
#define __TargetAggroHolder_x                                      0x11B503C
#define __GroupAggro_x                                             0x11B507C
#define __LoginName_x                                              0x10A3E88
#define __Inviter_x                                                0x109FEB4


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x100E988
#define instEQZoneInfo_x                                           0x101BC34
#define instKeypressHandler_x                                      0x10A0720
#define pinstActiveBanker_x                                        0x100E940
#define pinstActiveCorpse_x                                        0x100E944
#define pinstActiveGMaster_x                                       0x100E948
#define pinstActiveMerchant_x                                      0x100E93C
#define pinstAggroInfo_x                                           0xE1CF40
#define pinstAltAdvManager_x                                       0xF5BC50
#define pinstAuraMgr_x                                             0xE28E10
#define pinstBandageTarget_x                                       0x100E928
#define pinstCamActor_x                                            0xF5B558
#define pinstCDBStr_x                                              0xF5AADC
#define pinstCDisplay_x                                            0x100E950
#define pinstCEverQuest_x                                          0x11AD528
#define pinstCharData_x                                            0x100E90C
#define pinstCharSpawn_x                                           0x100E934
#define pinstControlledMissile_x                                   0x100E908
#define pinstControlledPlayer_x                                    0x100E934
#define pinstCSidlManager_x                                        0x18190F4
#define pinstCXWndManager_x                                        0x18190EC
#define instDynamicZone_x                                          0x101B7F0
#define pinstDZMember_x                                            0x101B900
#define pinstDZTimerInfo_x                                         0x101B904
#define pinstEQItemList_x                                          0x100B068
#define instEQMisc_x                                               0xC11948
#define pinstEQSoundManager_x                                      0xF5C1B0
#define instExpeditionLeader_x                                     0x101B83A
#define instExpeditionName_x                                       0x101B87A
#define pinstGroup_x                                               0x100C3DE
#define pinstImeManager_x                                          0x18190F8
#define pinstLocalPlayer_x                                         0x100E920
#define pinstMercenaryData_x                                       0x10A0D70
#define pinstMercenaryStats_x                                      0x11B5188
#define pinstMercAltAbilities_x                                    0xF5BFDC
#define pinstModelPlayer_x                                         0x100E94C
#define pinstPCData_x                                              0x100E90C
#define pinstSkillMgr_x                                            0x10A1BA8
#define pinstSpawnManager_x                                        0x10A1490
#define pinstSpellManager_x                                        0x10A1CF0
#define pinstSpellSets_x                                           0x1098C50
#define pinstStringTable_x                                         0x100E8B4
#define pinstSwitchManager_x                                       0x100BF70
#define pinstTarget_x                                              0x100E938
#define pinstTargetObject_x                                        0x100E910
#define pinstTargetSwitch_x                                        0x100E914
#define pinstTaskMember_x                                          0xF5AA28
#define pinstTrackTarget_x                                         0x100E92C
#define pinstTradeTarget_x                                         0x100E91C
#define instTributeActive_x                                        0xC1196D
#define pinstViewActor_x                                           0xF5B554
#define pinstWorldData_x                                           0x100E8F0
#define pinstZoneAddr_x                                            0x101BEF4
#define pinstPlayerPath_x                                          0x109D610
#define pinstTargetIndicator_x                                     0x109DFA8
#define pinstCTargetManager_x                                      0x10A1EE8

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE1D420
#define pinstCAudioTriggersWindow_x                                0xE1D2B0
#define pinstCCharacterSelect_x                                    0xF5B3E8
#define pinstCFacePick_x                                           0xF5B398
#define pinstCNoteWnd_x                                            0xF5B3A0
#define pinstCBookWnd_x                                            0xF5B3A8
#define pinstCPetInfoWnd_x                                         0xF5B3AC
#define pinstCTrainWnd_x                                           0xF5B3B0
#define pinstCSkillsWnd_x                                          0xF5B3B4
#define pinstCSkillsSelectWnd_x                                    0xF5B3B8
#define pinstCCombatSkillsSelectWnd_x                              0xF5B3BC
#define pinstCFriendsWnd_x                                         0xF5B3C0
#define pinstCAuraWnd_x                                            0xF5B3C4
#define pinstCRespawnWnd_x                                         0xF5B3C8
#define pinstCBandolierWnd_x                                       0xF5B3CC
#define pinstCPotionBeltWnd_x                                      0xF5B3D0
#define pinstCAAWnd_x                                              0xF5B3D4
#define pinstCGroupSearchFiltersWnd_x                              0xF5B3D8
#define pinstCLoadskinWnd_x                                        0xF5B3DC
#define pinstCAlarmWnd_x                                           0xF5B3E0
#define pinstCMusicPlayerWnd_x                                     0xF5B3E4
#define pinstCMailWnd_x                                            0xF5B3EC
#define pinstCMailCompositionWnd_x                                 0xF5B3F0
#define pinstCMailAddressBookWnd_x                                 0xF5B3F4
#define pinstCRaidWnd_x                                            0xF5B3FC
#define pinstCRaidOptionsWnd_x                                     0xF5B400
#define pinstCBreathWnd_x                                          0xF5B404
#define pinstCMapViewWnd_x                                         0xF5B408
#define pinstCMapToolbarWnd_x                                      0xF5B40C
#define pinstCEditLabelWnd_x                                       0xF5B410
#define pinstCTargetWnd_x                                          0xF5B414
#define pinstCColorPickerWnd_x                                     0xF5B418
#define pinstCPlayerWnd_x                                          0xF5B41C
#define pinstCOptionsWnd_x                                         0xF5B420
#define pinstCBuffWindowNORMAL_x                                   0xF5B424
#define pinstCBuffWindowSHORT_x                                    0xF5B428
#define pinstCharacterCreation_x                                   0xF5B42C
#define pinstCCursorAttachment_x                                   0xF5B430
#define pinstCCastingWnd_x                                         0xF5B434
#define pinstCCastSpellWnd_x                                       0xF5B438
#define pinstCSpellBookWnd_x                                       0xF5B43C
#define pinstCInventoryWnd_x                                       0xF5B440
#define pinstCBankWnd_x                                            0xF5B448
#define pinstCQuantityWnd_x                                        0xF5B44C
#define pinstCLootWnd_x                                            0xF5B450
#define pinstCActionsWnd_x                                         0xF5B454
#define pinstCCombatAbilityWnd_x                                   0xF5B458
#define pinstCMerchantWnd_x                                        0xF5B45C
#define pinstCTradeWnd_x                                           0xF5B460
#define pinstCSelectorWnd_x                                        0xF5B464
#define pinstCBazaarWnd_x                                          0xF5B468
#define pinstCBazaarSearchWnd_x                                    0xF5B46C
#define pinstCGiveWnd_x                                            0xF5B488
#define pinstCTrackingWnd_x                                        0xF5B490
#define pinstCInspectWnd_x                                         0xF5B494
#define pinstCSocialEditWnd_x                                      0xF5B498
#define pinstCFeedbackWnd_x                                        0xF5B49C
#define pinstCBugReportWnd_x                                       0xF5B4A0
#define pinstCVideoModesWnd_x                                      0xF5B4A4
#define pinstCTextEntryWnd_x                                       0xF5B4AC
#define pinstCFileSelectionWnd_x                                   0xF5B4B0
#define pinstCCompassWnd_x                                         0xF5B4B4
#define pinstCPlayerNotesWnd_x                                     0xF5B4B8
#define pinstCGemsGameWnd_x                                        0xF5B4BC
#define pinstCTimeLeftWnd_x                                        0xF5B4C0
#define pinstCPetitionQWnd_x                                       0xF5B4DC
#define pinstCSoulmarkWnd_x                                        0xF5B4E0
#define pinstCStoryWnd_x                                           0xF5B4E4
#define pinstCJournalTextWnd_x                                     0xF5B4E8
#define pinstCJournalCatWnd_x                                      0xF5B4EC
#define pinstCBodyTintWnd_x                                        0xF5B4F0
#define pinstCServerListWnd_x                                      0xF5B4F4
#define pinstCAvaZoneWnd_x                                         0xF5B500
#define pinstCBlockedBuffWnd_x                                     0xF5B504
#define pinstCBlockedPetBuffWnd_x                                  0xF5B508
#define pinstCInvSlotMgr_x                                         0xF5B54C
#define pinstCContainerMgr_x                                       0xF5B550
#define pinstCAdventureLeaderboardWnd_x                            0x11ADED8
#define pinstCAdventureRequestWnd_x                                0x11ADF50
#define pinstCAltStorageWnd_x                                      0x11AE230
#define pinstCAdventureStatsWnd_x                                  0x11ADFC8
#define pinstCBarterMerchantWnd_x                                  0x11AEE18
#define pinstCBarterSearchWnd_x                                    0x11AEE90
#define pinstCBarterWnd_x                                          0x11AEF08
#define pinstCChatManager_x                                        0x11AF598
#define pinstCDynamicZoneWnd_x                                     0x11AFA48
#define pinstCEQMainWnd_x                                          0x11AFBE0
#define pinstCFellowshipWnd_x                                      0x11AF9DC
#define pinstCFindLocationWnd_x                                    0x11AFEB0
#define pinstCGroupSearchWnd_x                                     0x11B0180
#define pinstCGroupWnd_x                                           0x11B01F8
#define pinstCGuildBankWnd_x                                       0x11B0270
#define pinstCGuildMgmtWnd_x                                       0x11B2360
#define pinstCHotButtonWnd_x                                       0x11B242C
#define pinstCHotButtonWnd1_x                                      0x11B242C
#define pinstCHotButtonWnd2_x                                      0x11B2430
#define pinstCHotButtonWnd3_x                                      0x11B2434
#define pinstCHotButtonWnd4_x                                      0x11B2458
#define pinstCItemDisplayManager_x                                 0x11B2750
#define pinstCItemExpTransferWnd_x                                 0x11B27CC
#define pinstCLFGuildWnd_x                                         0x11B2AA8
#define pinstCMIZoneSelectWnd_x                                    0x11B3090
#define pinstCConfirmationDialog_x                                 0x11B3798
#define pinstCPopupWndManager_x                                    0x11B3798
#define pinstCProgressionSelectionWnd_x                            0x11B3888
#define pinstCPvPStatsWnd_x                                        0x11B3978
#define pinstCSystemInfoDialogBox_x                                0x11B4080
#define pinstCTaskWnd_x                                            0x11B5448
#define pinstCTaskSomething_x                                      0xE295D0
#define pinstCTaskTemplateSelectWnd_x                              0x11B53D0
#define pinstCTipWndOFDAY_x                                        0x11B56A0
#define pinstCTipWndCONTEXT_x                                      0x11B56A4
#define pinstCTitleWnd_x                                           0x11B5720
#define pinstCContextMenuManager_x                                 0x1819064
#define pinstCVoiceMacroWnd_x                                      0x10A2358
#define pinstCHtmlWnd_x                                            0x10A2450
#define pinstIconCache_x                                           0x11AFBB4
#define pinstCTradeskillWnd_x                                      0x11B5820
#define pinstCAdvancedLootWnd_x                                    0xF5B540
#define pinstRewardSelectionWnd_x                                  0x11B3EA0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x532970
#define __ConvertItemTags_x                                        0x51FAA0
#define __ExecuteCmd_x                                             0x50A5F0
#define __EQGetTime_x                                              0x8A1660
#define __get_melee_range_x                                        0x511260
#define __GetGaugeValueFromEQ_x                                    0x7A95D0
#define __GetLabelFromEQ_x                                         0x7AA820
#define __ToggleKeyRingItem_x                                      0x47EEC0
#define __GetXTargetType_x                                         0x932FA0
#define __LoadFrontEnd_x                                           0x6382B0
#define __NewUIINI_x                                               0x7A8ED0
#define __ProcessGameEvents_x                                      0x577D80
#define __ProcessMouseEvent_x                                      0x577520
#define CrashDetected_x                                            0x639D80
#define wwsCrashReportCheckForUploader_x                           0x7FD1A0
#define DrawNetStatus_x                                            0x5AF340
#define Util__FastTime_x                                           0x8A1170
#define Expansion_HoT_x                                            0x101CD34
#define __HelpPath_x                                               0x10A04A8
#define __STMLToText_x                                             0x8E77F0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41FB80
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41A9F0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C5C80
#define AltAdvManager__IsAbilityReady_x                            0x4C5CF0
#define AltAdvManager__GetAAById_x                                 0x4C60B0
#define AltAdvManager__CanTrainAbility_x                           0x4C6970
#define AltAdvManager__CanSeeAbility_x                             0x4C6570


// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x464EA0
#define CharacterZoneClient__MakeMeVisible_x                       0x46A880
#define CharacterZoneClient__IsStackBlocked_x                      0x446D40

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x667DD0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x676220

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58E600
#define CButtonWnd__CButtonWnd_x                                   0x8DBA90

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x691170
#define CChatManager__InitContextMenu_x                            0x691CF0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E5B60
#define CContextMenu__dCContextMenu_x                              0x8E5D70
#define CContextMenu__AddMenuItem_x                                0x8E5D80
#define CContextMenu__RemoveMenuItem_x                             0x8E6060
#define CContextMenu__RemoveAllMenuItems_x                         0x8E6080
#define CContextMenuManager__AddMenu_x                             0x8D19D0
#define CContextMenuManager__RemoveMenu_x                          0x8D1D30
#define CContextMenuManager__PopupMenu_x                           0x8D2180
#define CContextMenuManager__Flush_x                               0x8D1A40
#define CContextMenuManager__GetMenu_x                             0x416060

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x886A10
#define CChatService__GetFriendName_x                              0x886A20

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x696FB0
#define CChatWindow__Clear_x                                       0x696B60
#define CChatWindow__WndNotification_x                             0x6974F0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D5900
#define CComboWnd__Draw_x                                          0x8D5B10
#define CComboWnd__GetCurChoice_x                                  0x8D56D0
#define CComboWnd__GetListRect_x                                   0x8D5DB0
#define CComboWnd__GetTextRect_x                                   0x8D5970
#define CComboWnd__InsertChoice_x                                  0x8D5E20
#define CComboWnd__SetColors_x                                     0x8D5660
#define CComboWnd__SetChoice_x                                     0x8D5690
#define CComboWnd__GetItemCount_x                                  0x8D56C0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A0720
#define CContainerWnd__vftable_x                                   0xAE2F50

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B3DF0
#define CDisplay__GetClickedActor_x                                0x4AC940
#define CDisplay__GetUserDefinedColor_x                            0x4AB200
#define CDisplay__GetWorldFilePath_x                               0x4AA650
#define CDisplay__is3dON_x                                         0x4A9A20
#define CDisplay__ReloadUI_x                                       0x4BF3D0
#define CDisplay__WriteTextHD2_x                                   0x4B0150

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FC730

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EA4F0
#define CEditWnd__GetCharIndexPt_x                                 0x8EB560
#define CEditWnd__GetDisplayString_x                               0x8EA6A0
#define CEditWnd__GetHorzOffset_x                                  0x8EA9E0
#define CEditWnd__GetLineForPrintableChar_x                        0x8EB040
#define CEditWnd__GetSelStartPt_x                                  0x8EB810
#define CEditWnd__GetSTMLSafeText_x                                0x8EAB70
#define CEditWnd__PointFromPrintableChar_x                         0x8EB130
#define CEditWnd__SelectableCharFromPoint_x                        0x8EB2A0
#define CEditWnd__SetEditable_x                                    0x8EAB40

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x5540D0
#define CEverQuest__CreateTargetIndicator_x                        0x554D00
#define CEverQuest__DeleteTargetIndicator_x                        0x554D80
#define CEverQuest__DoTellWindow_x                                 0x559AD0
#define CEverQuest__DropHeldItemOnGround_x                         0x5629C0
#define CEverQuest__dsp_chat_x                                     0x55B480
#define CEverQuest__Emote_x                                        0x55B6E0
#define CEverQuest__EnterZone_x                                    0x56FB10
#define CEverQuest__GetBodyTypeDesc_x                              0x550930
#define CEverQuest__GetClassDesc_x                                 0x556640
#define CEverQuest__GetClassThreeLetterCode_x                      0x556C40
#define CEverQuest__GetDeityDesc_x                                 0x551210
#define CEverQuest__GetLangDesc_x                                  0x550CC0
#define CEverQuest__GetRaceDesc_x                                  0x556E00
#define CEverQuest__InterpretCmd_x                                 0x55BFC0
#define CEverQuest__LeftClickedOnPlayer_x                          0x574480
#define CEverQuest__LMouseUp_x                                     0x576570
#define CEverQuest__RightClickedOnPlayer_x                         0x574F80
#define CEverQuest__RMouseUp_x                                     0x575FD0
#define CEverQuest__SetGameState_x                                 0x554780
#define CEverQuest__UPCNotificationFlush_x                         0x55D320
#define CEverQuest__IssuePetCommand_x                              0x55CC80

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B1330
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B1390
#define CGaugeWnd__Draw_x                                          0x6B17C0

// CGuild
#define CGuild__FindMemberByName_x                                 0x436990

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CE3C0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DAB60
#define CInvSlotMgr__MoveItem_x                                    0x6DBAA0
#define CInvSlotMgr__SelectSlot_x                                  0x6DAC10

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D9FF0
#define CInvSlot__SliderComplete_x                                 0x6D7820
#define CInvSlot__GetItemBase_x                                    0x6D6C90

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DCE60

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A5F60
#define CItemDisplayWnd__UpdateStrings_x                           0x6DE1B0

// CLabel 
#define CLabel__Draw_x                                             0x6F8FD0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C1540
#define CListWnd__dCListWnd_x                                      0x8C2560
#define CListWnd__AddColumn_x                                      0x8C2500
#define CListWnd__AddColumn1_x                                     0x8C1D80
#define CListWnd__AddLine_x                                        0x8C1800
#define CListWnd__AddString_x                                      0x8C1A10
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BE890
#define CListWnd__CalculateVSBRange_x                              0x8C09F0
#define CListWnd__ClearAllSel_x                                    0x8BDB60
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C13D0
#define CListWnd__Compare_x                                        0x8BF380
#define CListWnd__Draw_x                                           0x8C0600
#define CListWnd__DrawColumnSeparators_x                           0x8C0490
#define CListWnd__DrawHeader_x                                     0x8BDE70
#define CListWnd__DrawItem_x                                       0x8BF9D0
#define CListWnd__DrawLine_x                                       0x8C0130
#define CListWnd__DrawSeparator_x                                  0x8C0530
#define CListWnd__EnsureVisible_x                                  0x8BE9F0
#define CListWnd__ExtendSel_x                                      0x8BF8E0
#define CListWnd__GetColumnMinWidth_x                              0x8BD520
#define CListWnd__GetColumnWidth_x                                 0x8BD440
#define CListWnd__GetCurSel_x                                      0x8BCC10
#define CListWnd__GetItemAtPoint_x                                 0x8BEC80
#define CListWnd__GetItemAtPoint1_x                                0x8BECF0
#define CListWnd__GetItemData_x                                    0x8BCF50
#define CListWnd__GetItemHeight_x                                  0x8BE500
#define CListWnd__GetItemIcon_x                                    0x8BD130
#define CListWnd__GetItemRect_x                                    0x8BEAC0
#define CListWnd__GetItemText_x                                    0x8BCFE0
#define CListWnd__GetSelList_x                                     0x8C1C70
#define CListWnd__GetSeparatorRect_x                               0x8BF2A0
#define CListWnd__RemoveLine_x                                     0x8C1BF0
#define CListWnd__SetColors_x                                      0x8BCD60
#define CListWnd__SetColumnJustification_x                         0x8BD7F0
#define CListWnd__SetColumnWidth_x                                 0x8BD4D0
#define CListWnd__SetCurSel_x                                      0x8BCC50
#define CListWnd__SetItemColor_x                                   0x8C10B0
#define CListWnd__SetItemData_x                                    0x8BDC10
#define CListWnd__SetItemText_x                                    0x8C0EF0
#define CListWnd__ShiftColumnSeparator_x                           0x8C0D80
#define CListWnd__Sort_x                                           0x8C2660
#define CListWnd__ToggleSel_x                                      0x8BDAE0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x712640

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7338B0
#define CMerchantWnd__RequestBuyItem_x                             0x73A710
#define CMerchantWnd__RequestSellItem_x                            0x73B180
#define CMerchantWnd__SelectRecoverySlot_x                         0x733B60
#define CMerchantWnd__SelectBuySellSlot_x                          0x732DC0
#define CMerchantWnd__ActualSelect_x                               0x737630

// CObfuscator
#define CObfuscator__doit_x                                        0x8520A0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E0A90
#define CSidlManager__CreateLabel_x                                0x79BFA0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65F0E0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65F000
#define CSidlScreenWnd__ConvertToRes_x                             0x8FC610
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D85A0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D9AA0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D9B50
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D9020
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D7F50
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D7690
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D8140
#define CSidlScreenWnd__Init1_x                                    0x8D9780
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D8650
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D7850
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D9270
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D7150
#define CSidlScreenWnd__StoreIniVis_x                              0x8D7620
#define CSidlScreenWnd__WndNotification_x                          0x8D9500
#define CSidlScreenWnd__GetChildItem_x                             0x8D7760
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CAB90

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F9E50
#define CSkillMgr__GetSkillCap_x                                   0x5FA010
#define CSkillMgr__GetNameToken_x                                  0x5F9A70

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FB8C0
#define CSliderWnd__SetValue_x                                     0x8FBA90
#define CSliderWnd__SetNumTicks_x                                  0x8FC210

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A3C10

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F71D0
#define CStmlWnd__CalculateHSBRange_x                              0x8EF6F0
#define CStmlWnd__CalculateVSBRange_x                              0x8EF780
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EF900
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F01E0
#define CStmlWnd__ForceParseNow_x                                  0x8F7B20
#define CStmlWnd__GetNextTagPiece_x                                0x8F00E0
#define CStmlWnd__GetSTMLText_x                                    0x6963F0
#define CStmlWnd__GetVisibleText_x                                 0x8F0C30
#define CStmlWnd__InitializeWindowVariables_x                      0x8F2FC0
#define CStmlWnd__MakeStmlColorTag_x                               0x8EE9F0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EEA50
#define CStmlWnd__SetSTMLText_x                                    0x8F4820
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F6E70
#define CStmlWnd__UpdateHistoryString_x                            0x8F1B70

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8EE080
#define CTabWnd__DrawCurrentPage_x                                 0x8ED8F0
#define CTabWnd__DrawTab_x                                         0x8ED6C0
#define CTabWnd__GetCurrentPage_x                                  0x8EDCC0
#define CTabWnd__GetPageInnerRect_x                                0x8ED3B0
#define CTabWnd__GetTabInnerRect_x                                 0x8ED5B0
#define CTabWnd__GetTabRect_x                                      0x8ED480
#define CTabWnd__InsertPage_x                                      0x8EE370
#define CTabWnd__SetPage_x                                         0x8EDCF0
#define CTabWnd__SetPageRect_x                                     0x8EDFC0
#define CTabWnd__UpdatePage_x                                      0x8EE310

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432800

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D52D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x901A90

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BAD20

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402270
#define CXStr__CXStr1_x                                            0x4030E0
#define CXStr__CXStr3_x                                            0x89E200
#define CXStr__dCXStr_x                                            0x9007D0
#define CXStr__operator_equal_x                                    0x89E370
#define CXStr__operator_equal1_x                                   0x89E3C0
#define CXStr__operator_plus_equal1_x                              0x89F4A0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C9DA0
#define CXWnd__Center_x                                            0x8CFFE0
#define CXWnd__ClrFocus_x                                          0x8C99A0
#define CXWnd__DoAllDrawing_x                                      0x8CFC30
#define CXWnd__DrawChildren_x                                      0x8CFDD0
#define CXWnd__DrawColoredRect_x                                   0x8CA160
#define CXWnd__DrawTooltip_x                                       0x8CA410
#define CXWnd__DrawTooltipAtPoint_x                                0x8CEBB0
#define CXWnd__GetBorderFrame_x                                    0x8CA850
#define CXWnd__GetChildWndAt_x                                     0x8D09B0
#define CXWnd__GetClientClipRect_x                                 0x8CA620
#define CXWnd__GetScreenClipRect_x                                 0x8CF2A0
#define CXWnd__GetScreenRect_x                                     0x8CAA20
#define CXWnd__GetTooltipRect_x                                    0x8CA2A0
#define CXWnd__GetWindowTextA_x                                    0x423C90
#define CXWnd__IsActive_x                                          0x8C5340
#define CXWnd__IsDescendantOf_x                                    0x8CA790
#define CXWnd__IsReallyVisible_x                                   0x8CDBD0
#define CXWnd__IsType_x                                            0x8FE270
#define CXWnd__Move_x                                              0x8CD2B0
#define CXWnd__Move1_x                                             0x8CF8D0
#define CXWnd__ProcessTransition_x                                 0x8C9D50
#define CXWnd__Refade_x                                            0x8C9B40
#define CXWnd__Resize_x                                            0x8CAAF0
#define CXWnd__Right_x                                             0x8CF0A0
#define CXWnd__SetFocus_x                                          0x8CC400
#define CXWnd__SetFont_x                                           0x8C99F0
#define CXWnd__SetKeyTooltip_x                                     0x8CAD60
#define CXWnd__SetMouseOver_x                                      0x8CF5C0
#define CXWnd__StartFade_x                                         0x8C9DF0
#define CXWnd__GetChildItem_x                                      0x8CF510

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C6C80
#define CXWndManager__DrawWindows_x                                0x8C68C0
#define CXWndManager__GetKeyboardFlags_x                           0x8C4E70
#define CXWndManager__HandleKeyboardMsg_x                          0x8C57E0
#define CXWndManager__RemoveWnd_x                                  0x8C54D0

// CDBStr
#define CDBStr__GetString_x                                        0x4A7F90

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E990
#define EQ_Character__Cur_HP_x                                     0x464570
#define EQ_Character__GetAACastingTimeModifier_x                   0x4468C0
#define EQ_Character__GetCharInfo2_x                               0x871600
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EB70
#define EQ_Character__GetFocusRangeModifier_x                      0x43ED60
#define EQ_Character__Max_Endurance_x                              0x5C19A0
#define EQ_Character__Max_HP_x                                     0x45A1A0
#define EQ_Character__Max_Mana_x                                   0x5C17D0
#define EQ_Character__doCombatAbility_x                            0x5BEE10
#define EQ_Character__UseSkill_x                                   0x46FA70
#define EQ_Character__GetConLevel_x                                0x5B39C0
#define EQ_Character__IsExpansionFlag_x                            0x4231D0
#define EQ_Character__TotalEffect_x                                0x44BC40

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x593EE0
#define EQ_Item__CreateItemTagString_x                             0x850A20
#define EQ_Item__IsStackable_x                                     0x844E90
#define EQ_Item__GetImageNum_x                                     0x847C40
#define EQ_Item__CreateItemClient_x                                0x594AD0
#define EQ_Item__GetItemValue_x                                    0x84F670
#define EQ_Item__ValueSellMerchant_x                               0x851D20

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C7DB0
#define EQ_LoadingS__Array_x                                       0xC1F720

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C2FF0
#define EQ_PC__GetAlternateAbilityId_x                             0x859F70
#define EQ_PC__GetCombatAbility_x                                  0x85A000
#define EQ_PC__GetCombatAbilityTimer_x                             0x854E20
#define EQ_PC__GetItemTimerValue_x                                 0x5BC940
#define EQ_PC__HasLoreItem_x                                       0x5B6EA0
#define EQ_PC__AlertInventoryChanged_x                             0x5B3990
#define EQ_PC__GetPcZoneClient_x                                   0x5DD570
#define EQ_PC__RemoveMyAffect_x                                    0x5BBE00

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50F2E0
#define EQItemList__add_item_x                                     0x50F220
#define EQItemList__delete_item_x                                  0x50F6E0
#define EQItemList__FreeItemList_x                                 0x50F5E0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A72B0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C8580
#define EQPlayer__dEQPlayer_x                                      0x5D1400
#define EQPlayer__DoAttack_x                                       0x5E3460
#define EQPlayer__EQPlayer_x                                       0x5D3820
#define EQPlayer__SetNameSpriteState_x                             0x5CE0D0
#define EQPlayer__SetNameSpriteTint_x                              0x5C9990
#define EQPlayer__IsBodyType_j_x                                   0x92F1F0
#define EQPlayer__IsTargetable_x                                   0x92FAF0
#define EQPlayer__CanSee_x                                         0x930010
#define PlayerZoneClient__ChangeHeight_x                           0x5E3320
#define EQPlayer__CanSeeTargetIndicator_x                          0x930100

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D7B20
#define EQPlayerManager__GetSpawnByName_x                          0x5D7F80

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59A180
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59A1C0
#define KeypressHandler__ClearCommandStateArray_x                  0x599D60
#define KeypressHandler__HandleKeyDown_x                           0x5986C0
#define KeypressHandler__HandleKeyUp_x                             0x5989E0
#define KeypressHandler__SaveKeymapping_x                          0x599E30

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70AA20
#define MapViewMap__SaveEx_x                                       0x70E300

#define PlayerPointManager__GetAltCurrency_x                       0x86C520

// StringTable 
#define StringTable__getString_x                                   0x867060

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C1450
#define PcZoneClient__RemovePetEffect_x                            0x5BCE30
#define PcZoneClient__HasAlternateAbility_x                        0x5BD8F0

//Doors
#define EQSwitch__UseSwitch_x                                      0x54DC60

//IconCache
#define IconCache__GetIcon_x                                       0x6A6C40

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69DA30
#define CContainerMgr__CloseContainer_x                            0x69E250

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76C420

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58D0A0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DF2B0
#define EQ_Spell__SpellAffects_x                                   0x4DF350
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DF380
#define CharacterZoneClient__CalcAffectChange_x                    0x447CB0
#define CLootWnd__LootAll_x                                        0x7002B0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B1BE0
#define CTargetWnd__WndNotification_x                              0x7B16D0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B6DC0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D8B90

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x497940

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E9B20
#define CSidlManager__FindAnimation1_x                             0x8DE990

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CF300
#define CAltAbilityData__GetMercMaxRank_x                          0x4CF2B0
#define CAltAbilityData__GetMaxRank_x                              0x4C4340

//CTargetRing
#define CTargetRing__Cast_x                                        0x58A970
