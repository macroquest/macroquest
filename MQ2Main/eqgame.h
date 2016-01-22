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
#define __ExpectedVersionDate                                     "Jan 21 2016"
#define __ExpectedVersionTime                                     "17:47:02"
#define __ActualVersionDate_x                                      0xAD9580
#define __ActualVersionTime_x                                      0xAD958C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59FAD0
#define __MemChecker1_x                                            0x8A1740
#define __MemChecker2_x                                            0x638EF0
#define __MemChecker3_x                                            0x638E40
#define __MemChecker4_x                                            0x7ED540
#define __EncryptPad0_x                                            0xC76388
#define __EncryptPad1_x                                            0xE01508
#define __EncryptPad2_x                                            0xCBFE70
#define __EncryptPad3_x                                            0xCBFA70
#define __EncryptPad4_x                                            0xDDA5F8
#define __EncryptPad5_x                                            0x11AD3D0
#define __AC1_x                                                    0x7AABA5
#define __AC2_x                                                    0x553C67
#define __AC3_x                                                    0x568820
#define __AC4_x                                                    0x56F4A0
#define __AC5_x                                                    0x57BC4E
#define __AC6_x                                                    0x57F7F9
#define __AC7_x                                                    0x5762FC
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
#define __do_loot_x                                                0x51B1D0
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
#define pinstCamActor_x                                            0xF5B55C
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
#define pinstViewActor_x                                           0xF5B558
#define pinstWorldData_x                                           0x100E8F0
#define pinstZoneAddr_x                                            0x101BEF4
#define pinstPlayerPath_x                                          0x10A14F0
#define pinstTargetIndicator_x                                     0x10A1E88
#define pinstCTargetManager_x                                      0x10A1EE8

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE1D420
#define pinstCAudioTriggersWindow_x                                0xE1D2B0
#define pinstCCharacterSelect_x                                    0xF5B3EC
#define pinstCFacePick_x                                           0xF5B19C
#define pinstCNoteWnd_x                                            0xF5B3A4
#define pinstCBookWnd_x                                            0xF5B3AC
#define pinstCPetInfoWnd_x                                         0xF5B3B0
#define pinstCTrainWnd_x                                           0xF5B3B4
#define pinstCSkillsWnd_x                                          0xF5B3B8
#define pinstCSkillsSelectWnd_x                                    0xF5B3BC
#define pinstCCombatSkillsSelectWnd_x                              0xF5B3C0
#define pinstCFriendsWnd_x                                         0xF5B3C4
#define pinstCAuraWnd_x                                            0xF5B3C8
#define pinstCRespawnWnd_x                                         0xF5B3CC
#define pinstCBandolierWnd_x                                       0xF5B3D0
#define pinstCPotionBeltWnd_x                                      0xF5B3D4
#define pinstCAAWnd_x                                              0xF5B3D8
#define pinstCGroupSearchFiltersWnd_x                              0xF5B3DC
#define pinstCLoadskinWnd_x                                        0xF5B3E0
#define pinstCAlarmWnd_x                                           0xF5B3E4
#define pinstCMusicPlayerWnd_x                                     0xF5B3E8
#define pinstCMailWnd_x                                            0xF5B3F0
#define pinstCMailCompositionWnd_x                                 0xF5B3F4
#define pinstCMailAddressBookWnd_x                                 0xF5B3F8
#define pinstCRaidWnd_x                                            0xF5B400
#define pinstCRaidOptionsWnd_x                                     0xF5B404
#define pinstCBreathWnd_x                                          0xF5B408
#define pinstCMapViewWnd_x                                         0xF5B40C
#define pinstCMapToolbarWnd_x                                      0xF5B410
#define pinstCEditLabelWnd_x                                       0xF5B414
#define pinstCTargetWnd_x                                          0xF5B418
#define pinstCColorPickerWnd_x                                     0xF5B41C
#define pinstCPlayerWnd_x                                          0xF5B420
#define pinstCOptionsWnd_x                                         0xF5B424
#define pinstCBuffWindowNORMAL_x                                   0xF5B428
#define pinstCBuffWindowSHORT_x                                    0xF5B42C
#define pinstCharacterCreation_x                                   0xF5B430
#define pinstCCursorAttachment_x                                   0xF5B434
#define pinstCCastingWnd_x                                         0xF5B438
#define pinstCCastSpellWnd_x                                       0xF5B43C
#define pinstCSpellBookWnd_x                                       0xF5B440
#define pinstCInventoryWnd_x                                       0xF5B444
#define pinstCBankWnd_x                                            0xF5B44C
#define pinstCQuantityWnd_x                                        0xF5B450
#define pinstCLootWnd_x                                            0xF5B454
#define pinstCActionsWnd_x                                         0xF5B458
#define pinstCCombatAbilityWnd_x                                   0xF5B45C
#define pinstCMerchantWnd_x                                        0xF5B460
#define pinstCTradeWnd_x                                           0xF5B464
#define pinstCSelectorWnd_x                                        0xF5B468
#define pinstCBazaarWnd_x                                          0xF5B46C
#define pinstCBazaarSearchWnd_x                                    0xF5B470
#define pinstCGiveWnd_x                                            0xF5B48C
#define pinstCTrackingWnd_x                                        0xF5B494
#define pinstCInspectWnd_x                                         0xF5B498
#define pinstCSocialEditWnd_x                                      0xF5B49C
#define pinstCFeedbackWnd_x                                        0xF5B4A0
#define pinstCBugReportWnd_x                                       0xF5B4A4
#define pinstCVideoModesWnd_x                                      0xF5B4A8
#define pinstCTextEntryWnd_x                                       0xF5B4B0
#define pinstCFileSelectionWnd_x                                   0xF5B4B4
#define pinstCCompassWnd_x                                         0xF5B4B8
#define pinstCPlayerNotesWnd_x                                     0xF5B4BC
#define pinstCGemsGameWnd_x                                        0xF5B4C0
#define pinstCTimeLeftWnd_x                                        0xF5B4C4
#define pinstCPetitionQWnd_x                                       0xF5B4E0
#define pinstCSoulmarkWnd_x                                        0xF5B4E4
#define pinstCStoryWnd_x                                           0xF5B4E8
#define pinstCJournalTextWnd_x                                     0xF5B4EC
#define pinstCJournalCatWnd_x                                      0xF5B4F0
#define pinstCBodyTintWnd_x                                        0xF5B4F4
#define pinstCServerListWnd_x                                      0xF5B4F8
#define pinstCAvaZoneWnd_x                                         0xF5B504
#define pinstCBlockedBuffWnd_x                                     0xF5B508
#define pinstCBlockedPetBuffWnd_x                                  0xF5B50C
#define pinstCInvSlotMgr_x                                         0xF5B550
#define pinstCContainerMgr_x                                       0xF5B554
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
#define pinstCAdvancedLootWnd_x                                    0xF5B544
#define pinstRewardSelectionWnd_x                                  0x11B3EA0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x532D00
#define __ConvertItemTags_x                                        0x51FE40
#define __ExecuteCmd_x                                             0x50A910
#define __EQGetTime_x                                              0x8A1370
#define __get_melee_range_x                                        0x5115A0
#define __GetGaugeValueFromEQ_x                                    0x7A98E0
#define __GetLabelFromEQ_x                                         0x7AAB30
#define __ToggleKeyRingItem_x                                      0x47EB90
#define __GetXTargetType_x                                         0x932D20
#define __LoadFrontEnd_x                                           0x6385A0
#define __NewUIINI_x                                               0x7A91E0
#define __ProcessGameEvents_x                                      0x578060
#define __ProcessMouseEvent_x                                      0x577800
#define CrashDetected_x                                            0x63A070
#define wwsCrashReportCheckForUploader_x                           0x7FD060
#define DrawNetStatus_x                                            0x5AF5D0
#define Util__FastTime_x                                           0x8A0E80
#define Expansion_HoT_x                                            0x101CD34
#define __HelpPath_x                                               0x10A04A8
#define __STMLToText_x                                             0x8E7480

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41FB50
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41A9C0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C5BC0
#define AltAdvManager__IsAbilityReady_x                            0x4C5C30
#define AltAdvManager__GetAAById_x                                 0x4C5FF0
#define AltAdvManager__CanTrainAbility_x                           0x4C68B0
#define AltAdvManager__CanSeeAbility_x                             0x4C64B0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x464BC0
#define CharacterZoneClient__MakeMeVisible_x                       0x46A5A0
#define CharacterZoneClient__IsStackBlocked_x                      0x446AD0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x668010

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x676750

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58E990
#define CButtonWnd__CButtonWnd_x                                   0x8DB6B0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x691490
#define CChatManager__InitContextMenu_x                            0x692010

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E57E0
#define CContextMenu__dCContextMenu_x                              0x8E59F0
#define CContextMenu__AddMenuItem_x                                0x8E5A00
#define CContextMenu__RemoveMenuItem_x                             0x8E5CF0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E5D10
#define CContextMenuManager__AddMenu_x                             0x8D1680
#define CContextMenuManager__RemoveMenu_x                          0x8D19C0
#define CContextMenuManager__PopupMenu_x                           0x8D1E10
#define CContextMenuManager__Flush_x                               0x8D16F0
#define CContextMenuManager__GetMenu_x                             0x416030

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x886720
#define CChatService__GetFriendName_x                              0x886730

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6972B0
#define CChatWindow__Clear_x                                       0x696E70
#define CChatWindow__WndNotification_x                             0x6977E0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D5560
#define CComboWnd__Draw_x                                          0x8D5770
#define CComboWnd__GetCurChoice_x                                  0x8D5330
#define CComboWnd__GetListRect_x                                   0x8D5A10
#define CComboWnd__GetTextRect_x                                   0x8D55D0
#define CComboWnd__InsertChoice_x                                  0x8D5A80
#define CComboWnd__SetColors_x                                     0x8D52C0
#define CComboWnd__SetChoice_x                                     0x8D52F0
#define CComboWnd__GetItemCount_x                                  0x8D5320

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A0890
#define CContainerWnd__vftable_x                                   0xAE2F68

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B3C80
#define CDisplay__GetClickedActor_x                                0x4AC7C0
#define CDisplay__GetUserDefinedColor_x                            0x4AB080
#define CDisplay__GetWorldFilePath_x                               0x4AA4D0
#define CDisplay__is3dON_x                                         0x4A98A0
#define CDisplay__ReloadUI_x                                       0x4BF260
#define CDisplay__WriteTextHD2_x                                   0x4AFFE0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FC380

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EA180
#define CEditWnd__GetCharIndexPt_x                                 0x8EB210
#define CEditWnd__GetDisplayString_x                               0x8EA330
#define CEditWnd__GetHorzOffset_x                                  0x8EA670
#define CEditWnd__GetLineForPrintableChar_x                        0x8EACE0
#define CEditWnd__GetSelStartPt_x                                  0x8EB4C0
#define CEditWnd__GetSTMLSafeText_x                                0x8EA810
#define CEditWnd__PointFromPrintableChar_x                         0x8EADD0
#define CEditWnd__SelectableCharFromPoint_x                        0x8EAF50
#define CEditWnd__SetEditable_x                                    0x8EA7E0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x5543B0
#define CEverQuest__CreateTargetIndicator_x                        0x554FE0
#define CEverQuest__DeleteTargetIndicator_x                        0x555060
#define CEverQuest__DoTellWindow_x                                 0x559DB0
#define CEverQuest__DropHeldItemOnGround_x                         0x562CA0
#define CEverQuest__dsp_chat_x                                     0x55B760
#define CEverQuest__Emote_x                                        0x55B9C0
#define CEverQuest__EnterZone_x                                    0x56FDF0
#define CEverQuest__GetBodyTypeDesc_x                              0x550C10
#define CEverQuest__GetClassDesc_x                                 0x556920
#define CEverQuest__GetClassThreeLetterCode_x                      0x556F20
#define CEverQuest__GetDeityDesc_x                                 0x5514F0
#define CEverQuest__GetLangDesc_x                                  0x550FA0
#define CEverQuest__GetRaceDesc_x                                  0x5570E0
#define CEverQuest__InterpretCmd_x                                 0x55C2A0
#define CEverQuest__LeftClickedOnPlayer_x                          0x574760
#define CEverQuest__LMouseUp_x                                     0x576850
#define CEverQuest__RightClickedOnPlayer_x                         0x575260
#define CEverQuest__RMouseUp_x                                     0x5762B0
#define CEverQuest__SetGameState_x                                 0x554A60
#define CEverQuest__UPCNotificationFlush_x                         0x55D600
#define CEverQuest__IssuePetCommand_x                              0x55CF60

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B15D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B1630
#define CGaugeWnd__Draw_x                                          0x6B1A60

// CGuild
#define CGuild__FindMemberByName_x                                 0x436790

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CE6A0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DAE20
#define CInvSlotMgr__MoveItem_x                                    0x6DBD60
#define CInvSlotMgr__SelectSlot_x                                  0x6DAED0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6DA2B0
#define CInvSlot__SliderComplete_x                                 0x6D7AE0
#define CInvSlot__GetItemBase_x                                    0x6D6F70

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DD130

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A6230
#define CItemDisplayWnd__UpdateStrings_x                           0x6DE450

// CLabel 
#define CLabel__Draw_x                                             0x6F9230

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C12F0
#define CListWnd__dCListWnd_x                                      0x8C2310
#define CListWnd__AddColumn_x                                      0x8C22B0
#define CListWnd__AddColumn1_x                                     0x8C1B30
#define CListWnd__AddLine_x                                        0x8C15B0
#define CListWnd__AddString_x                                      0x8C17C0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BE650
#define CListWnd__CalculateVSBRange_x                              0x8C07B0
#define CListWnd__ClearAllSel_x                                    0x8BD900
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C1180
#define CListWnd__Compare_x                                        0x8BF140
#define CListWnd__Draw_x                                           0x8C03C0
#define CListWnd__DrawColumnSeparators_x                           0x8C0250
#define CListWnd__DrawHeader_x                                     0x8BDC10
#define CListWnd__DrawItem_x                                       0x8BF780
#define CListWnd__DrawLine_x                                       0x8BFEF0
#define CListWnd__DrawSeparator_x                                  0x8C02F0
#define CListWnd__EnsureVisible_x                                  0x8BE7B0
#define CListWnd__ExtendSel_x                                      0x8BF690
#define CListWnd__GetColumnMinWidth_x                              0x8BD2C0
#define CListWnd__GetColumnWidth_x                                 0x8BD1E0
#define CListWnd__GetCurSel_x                                      0x8BC9D0
#define CListWnd__GetItemAtPoint_x                                 0x8BEA50
#define CListWnd__GetItemAtPoint1_x                                0x8BEAC0
#define CListWnd__GetItemData_x                                    0x8BCD00
#define CListWnd__GetItemHeight_x                                  0x8BE2A0
#define CListWnd__GetItemIcon_x                                    0x8BCEE0
#define CListWnd__GetItemRect_x                                    0x8BE890
#define CListWnd__GetItemText_x                                    0x8BCD90
#define CListWnd__GetSelList_x                                     0x8C1A20
#define CListWnd__GetSeparatorRect_x                               0x8BF060
#define CListWnd__RemoveLine_x                                     0x8C19A0
#define CListWnd__SetColors_x                                      0x8BCB20
#define CListWnd__SetColumnJustification_x                         0x8BD590
#define CListWnd__SetColumnWidth_x                                 0x8BD270
#define CListWnd__SetCurSel_x                                      0x8BCA10
#define CListWnd__SetItemColor_x                                   0x8C0E60
#define CListWnd__SetItemData_x                                    0x8BD9B0
#define CListWnd__SetItemText_x                                    0x8C0CA0
#define CListWnd__ShiftColumnSeparator_x                           0x8C0B30
#define CListWnd__Sort_x                                           0x8C2410
#define CListWnd__ToggleSel_x                                      0x8BD880

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x712850

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x733A90
#define CMerchantWnd__RequestBuyItem_x                             0x73A8B0
#define CMerchantWnd__RequestSellItem_x                            0x73B300
#define CMerchantWnd__SelectRecoverySlot_x                         0x733D40
#define CMerchantWnd__SelectBuySellSlot_x                          0x732FA0
#define CMerchantWnd__ActualSelect_x                               0x7377E0

// CObfuscator
#define CObfuscator__doit_x                                        0x851DA0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E0650
#define CSidlManager__CreateLabel_x                                0x79C220

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65F320
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65F250
#define CSidlScreenWnd__ConvertToRes_x                             0x8FC260
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D81F0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D96F0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D97A0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D8C70
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D7BA0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D72F0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D7D90
#define CSidlScreenWnd__Init1_x                                    0x8D93D0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D82A0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D74B0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D8EC0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D6DB0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D7280
#define CSidlScreenWnd__WndNotification_x                          0x8D9150
#define CSidlScreenWnd__GetChildItem_x                             0x8D73C0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CA940

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FA370
#define CSkillMgr__GetSkillCap_x                                   0x5FA530
#define CSkillMgr__GetNameToken_x                                  0x5F9F90

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FB520
#define CSliderWnd__SetValue_x                                     0x8FB6F0
#define CSliderWnd__SetNumTicks_x                                  0x8FBE70

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A3EE0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F6EB0
#define CStmlWnd__CalculateHSBRange_x                              0x8EF3D0
#define CStmlWnd__CalculateVSBRange_x                              0x8EF460
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EF5E0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EFEC0
#define CStmlWnd__ForceParseNow_x                                  0x8F7800
#define CStmlWnd__GetNextTagPiece_x                                0x8EFDC0
#define CStmlWnd__GetSTMLText_x                                    0x696710
#define CStmlWnd__GetVisibleText_x                                 0x8F0910
#define CStmlWnd__InitializeWindowVariables_x                      0x8F2CA0
#define CStmlWnd__MakeStmlColorTag_x                               0x8EE6D0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EE730
#define CStmlWnd__SetSTMLText_x                                    0x8F4500
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F6B50
#define CStmlWnd__UpdateHistoryString_x                            0x8F1850

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8EDD50
#define CTabWnd__DrawCurrentPage_x                                 0x8ED5C0
#define CTabWnd__DrawTab_x                                         0x8ED380
#define CTabWnd__GetCurrentPage_x                                  0x8ED990
#define CTabWnd__GetPageInnerRect_x                                0x8ED070
#define CTabWnd__GetTabInnerRect_x                                 0x8ED270
#define CTabWnd__GetTabRect_x                                      0x8ED140
#define CTabWnd__InsertPage_x                                      0x8EE040
#define CTabWnd__SetPage_x                                         0x8ED9C0
#define CTabWnd__SetPageRect_x                                     0x8EDC90
#define CTabWnd__UpdatePage_x                                      0x8EDFE0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432540

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D4F30

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9016E0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BAC30

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4022C0
#define CXStr__CXStr1_x                                            0x900410
#define CXStr__CXStr3_x                                            0x89DF10
#define CXStr__dCXStr_x                                            0x7A73F0
#define CXStr__operator_equal_x                                    0x89E080
#define CXStr__operator_equal1_x                                   0x89E0D0
#define CXStr__operator_plus_equal1_x                              0x89F1B0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C9BA0
#define CXWnd__Center_x                                            0x8CFCA0
#define CXWnd__ClrFocus_x                                          0x8C9780
#define CXWnd__DoAllDrawing_x                                      0x8CF900
#define CXWnd__DrawChildren_x                                      0x8CFAA0
#define CXWnd__DrawColoredRect_x                                   0x8C9F50
#define CXWnd__DrawTooltip_x                                       0x8CA200
#define CXWnd__DrawTooltipAtPoint_x                                0x8CE890
#define CXWnd__GetBorderFrame_x                                    0x8CA640
#define CXWnd__GetChildWndAt_x                                     0x8D0660
#define CXWnd__GetClientClipRect_x                                 0x8CA420
#define CXWnd__GetScreenClipRect_x                                 0x8CEF90
#define CXWnd__GetScreenRect_x                                     0x8CA7E0
#define CXWnd__GetTooltipRect_x                                    0x8CA090
#define CXWnd__GetWindowTextA_x                                    0x423B00
#define CXWnd__IsActive_x                                          0x8C5110
#define CXWnd__IsDescendantOf_x                                    0x8CA590
#define CXWnd__IsReallyVisible_x                                   0x8CD8A0
#define CXWnd__IsType_x                                            0x8FDEB0
#define CXWnd__Move_x                                              0x8CCFA0
#define CXWnd__Move1_x                                             0x8CF5C0
#define CXWnd__ProcessTransition_x                                 0x8C9B50
#define CXWnd__Refade_x                                            0x8C9930
#define CXWnd__Resize_x                                            0x8CA8A0
#define CXWnd__Right_x                                             0x8CED90
#define CXWnd__SetFocus_x                                          0x8CC100
#define CXWnd__SetFont_x                                           0x8C97D0
#define CXWnd__SetKeyTooltip_x                                     0x8CAB10
#define CXWnd__SetMouseOver_x                                      0x8CF2C0
#define CXWnd__StartFade_x                                         0x8C9BF0
#define CXWnd__GetChildItem_x                                      0x8CF210

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C6A30
#define CXWndManager__DrawWindows_x                                0x8C6680
#define CXWndManager__GetKeyboardFlags_x                           0x8C4C80
#define CXWndManager__HandleKeyboardMsg_x                          0x8C55A0
#define CXWndManager__RemoveWnd_x                                  0x8C52A0

// CDBStr
#define CDBStr__GetString_x                                        0x4A7E00

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E6B0
#define EQ_Character__Cur_HP_x                                     0x464290
#define EQ_Character__GetAACastingTimeModifier_x                   0x446650
#define EQ_Character__GetCharInfo2_x                               0x8712F0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43E990
#define EQ_Character__GetFocusRangeModifier_x                      0x43EB80
#define EQ_Character__Max_Endurance_x                              0x5C1E10
#define EQ_Character__Max_HP_x                                     0x459EC0
#define EQ_Character__Max_Mana_x                                   0x5C1C40
#define EQ_Character__doCombatAbility_x                            0x5BF290
#define EQ_Character__UseSkill_x                                   0x46F7A0
#define EQ_Character__GetConLevel_x                                0x5B3C20
#define EQ_Character__IsExpansionFlag_x                            0x423050
#define EQ_Character__TotalEffect_x                                0x44B990

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x594300
#define EQ_Item__CreateItemTagString_x                             0x850660
#define EQ_Item__IsStackable_x                                     0x844A40
#define EQ_Item__GetImageNum_x                                     0x847710
#define EQ_Item__CreateItemClient_x                                0x594EC0
#define EQ_Item__GetItemValue_x                                    0x84F300
#define EQ_Item__ValueSellMerchant_x                               0x8519E0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C7CB0
#define EQ_LoadingS__Array_x                                       0xC1F720

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C3470
#define EQ_PC__GetAlternateAbilityId_x                             0x859BD0
#define EQ_PC__GetCombatAbility_x                                  0x859C60
#define EQ_PC__GetCombatAbilityTimer_x                             0x854B20
#define EQ_PC__GetItemTimerValue_x                                 0x5BCDC0
#define EQ_PC__HasLoreItem_x                                       0x5B70E0
#define EQ_PC__AlertInventoryChanged_x                             0x5B3BF0
#define EQ_PC__GetPcZoneClient_x                                   0x5DDAD0
#define EQ_PC__RemoveMyAffect_x                                    0x5BC260

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50F600
#define EQItemList__add_item_x                                     0x50F540
#define EQItemList__delete_item_x                                  0x50FA00
#define EQItemList__FreeItemList_x                                 0x50F900

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A6FD0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C89E0
#define EQPlayer__dEQPlayer_x                                      0x5D1860
#define EQPlayer__DoAttack_x                                       0x5E39B0
#define EQPlayer__EQPlayer_x                                       0x5D3C80
#define EQPlayer__SetNameSpriteState_x                             0x5CE530
#define EQPlayer__SetNameSpriteTint_x                              0x5C9DF0
#define EQPlayer__IsBodyType_j_x                                   0x92EF10
#define EQPlayer__IsTargetable_x                                   0x92F810
#define EQPlayer__CanSee_x                                         0x92FD30
#define PlayerZoneClient__ChangeHeight_x                           0x5E3870
#define EQPlayer__CanSeeTargetIndicator_x                          0x92FE20

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D8000
#define EQPlayerManager__GetSpawnByName_x                          0x5D8460

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59A3E0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59A420
#define KeypressHandler__ClearCommandStateArray_x                  0x599FC0
#define KeypressHandler__HandleKeyDown_x                           0x598920
#define KeypressHandler__HandleKeyUp_x                             0x598C40
#define KeypressHandler__SaveKeymapping_x                          0x59A090

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70AC30
#define MapViewMap__SaveEx_x                                       0x70E510

#define PlayerPointManager__GetAltCurrency_x                       0x86C1E0

// StringTable 
#define StringTable__getString_x                                   0x866CD0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C18C0
#define PcZoneClient__RemovePetEffect_x                            0x5BD2B0
#define PcZoneClient__HasAlternateAbility_x                        0x5BDD70

//Doors
#define EQSwitch__UseSwitch_x                                      0x54DFB0

//IconCache
#define IconCache__GetIcon_x                                       0x6A6DA0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69DBB0
#define CContainerMgr__CloseContainer_x                            0x69E3D0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76C490

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58D420

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DF2E0
#define EQ_Spell__SpellAffects_x                                   0x4DF380
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DF3B0
#define CharacterZoneClient__CalcAffectChange_x                    0x447A50
#define CLootWnd__LootAll_x                                        0x700520

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B1E80
#define CTargetWnd__WndNotification_x                              0x7B1970

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B7050

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D8BD0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x497690

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E97B0
#define CSidlManager__FindAnimation1_x                             0x8DE540

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CF230
#define CAltAbilityData__GetMercMaxRank_x                          0x4CF1E0
#define CAltAbilityData__GetMaxRank_x                              0x4C4280

//CTargetRing
#define CTargetRing__Cast_x                                        0x58AD20
