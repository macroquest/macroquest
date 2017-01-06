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
#if defined(LIVE)
#include "eqgame-private(live).h"
#endif
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Dec 13 2016"
#define __ExpectedVersionTime                                     "12:16:05"
#define __ActualVersionDate_x                                      0xAC6930
#define __ActualVersionTime_x                                      0xAC693C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5978C0
#define __MemChecker1_x                                            0x88C9D0
#define __MemChecker2_x                                            0x62D4E0
#define __MemChecker3_x                                            0x62D430
#define __MemChecker4_x                                            0x7DFFE0
#define __EncryptPad0_x                                            0xC2A608
#define __EncryptPad1_x                                            0xD21A68
#define __EncryptPad2_x                                            0xC58C18
#define __EncryptPad3_x                                            0xC58818
#define __EncryptPad4_x                                            0xD0C6B8
#define __EncryptPad5_x                                            0x10CB898
#define __AC1_x                                                    0x79F9C5
#define __AC2_x                                                    0x551477
#define __AC3_x                                                    0x54F610
#define __AC4_x                                                    0x561E80
#define __AC5_x                                                    0x574BDB
#define __AC6_x                                                    0x57878E
#define __AC7_x                                                    0x56F24C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FBBE20

// Direct Input
#define DI8__Main_x                                                0x10CB870
#define DI8__Keyboard_x                                            0x10CB874
#define DI8__Mouse_x                                               0x10CB878
#define DI8__Mouse_Copy_x                                          0xF39F5C
#define DI8__Mouse_Check_x                                         0xFC375C
#define __Attack_x                                                 0xFBE443
#define __Autofire_x                                               0xFBE444
#define __BindList_x                                               0xC01418
#define g_eqCommandStates_x                                        0xF28F88
#define __Clicks_x                                                 0xF3A018
#define __CommandList_x                                            0xC03F28
#define __CurrentMapLabel_x                                        0x10D12F8
#define __CurrentSocial_x                                          0xBCF084
#define __DoAbilityList_x                                          0xF706F8
#define __do_loot_x                                                0x520E50
#define __DrawHandler_x                                            0x17381BC
#define __GroupCount_x                                             0xF2A5B2

#define __Guilds_x                                                 0xF301C8
#define __gWorld_x                                                 0xF2CA6C
#define __HotkeyPage_x                                             0xFB70F8
#define __HWnd_x                                                   0xFC3778
#define __InChatMode_x                                             0xF39F44
#define __LastTell_x                                               0xF3BDF4
#define __LMouseHeldTime_x                                         0xF3A084
#define __Mouse_x                                                  0x10CB87C
#define __MouseLook_x                                              0xF39FDE
#define __MouseEventTime_x                                         0xFBEC44
#define __gpbCommandEvent_x                                        0xF2CB34
#define __NetStatusToggle_x                                        0xF39FE1
#define __PCNames_x                                                0xF3B410
#define __RangeAttackReady_x                                       0xF3B14C
#define __RMouseHeldTime_x                                         0xF3A080
#define __RunWalkState_x                                           0xF39F48
#define __ScreenMode_x                                             0xE78C88
#define __ScreenX_x                                                0xF39EFC
#define __ScreenY_x                                                0xF39EF8
#define __ScreenXMax_x                                             0xF39F00
#define __ScreenYMax_x                                             0xF39F04
#define __ServerHost_x                                             0xF2A4FC
#define __ServerName_x                                             0xF706B8
#define __ShiftKeyDown_x                                           0xF3A5D8
#define __ShowNames_x                                              0xF3B30C
#define __Socials_x                                                0xF707B8
#define __SubscriptionType_x                                       0x10FF304
#define __TargetAggroHolder_x                                      0x10D3534
#define __ZoneType_x                                               0xF3A3DC
#define __GroupAggro_x                                             0x10D3574
#define __LoginName_x                                              0xFC2354
#define __Inviter_x                                                0xFBE3C0
#define __AttackOnAssist_x                                         0xF3B2C8
#define __UseTellWindows_x                                         0xF3B5A8

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF2CB58
#define instEQZoneInfo_x                                           0xF3A1D4
#define instKeypressHandler_x                                      0xFBEC28
#define pinstActiveBanker_x                                        0xF2CB10
#define pinstActiveCorpse_x                                        0xF2CB14
#define pinstActiveGMaster_x                                       0xF2CB18
#define pinstActiveMerchant_x                                      0xF2CB0C
#define pinstAggroInfo_x                                           0xD366E8
#define pinstAltAdvManager_x                                       0xE79D50
#define pinstAuraMgr_x                                             0xD46E58
#define pinstBandageTarget_x                                       0xF2CAF8
#define pinstCamActor_x                                            0xE796A0
#define pinstCDBStr_x                                              0xE78C1C
#define pinstCDisplay_x                                            0xF2CB20
#define pinstCEverQuest_x                                          0x10CB9F0
#define pinstCharData_x                                            0xF2CADC
#define pinstCharSpawn_x                                           0xF2CB04
#define pinstControlledMissile_x                                   0xF2CAD8
#define pinstControlledPlayer_x                                    0xF2CB04
#define pinstCSidlManager_x                                        0x17375AC
#define pinstCXWndManager_x                                        0x17375A4
#define instDynamicZone_x                                          0xF39D90
#define pinstDZMember_x                                            0xF39EA0
#define pinstDZTimerInfo_x                                         0xF39EA4
#define pinstEQItemList_x                                          0xF291D8
#define pinstEQObjectList_x                                        0xF29FAC
#define instEQMisc_x                                               0xBE7428
#define pinstEQSoundManager_x                                      0xE7A320
#define instExpeditionLeader_x                                     0xF39DDA
#define instExpeditionName_x                                       0xF39E1A
#define pinstGroup_x                                               0xF2A5AE
#define pinstImeManager_x                                          0x17375B0
#define pinstLocalPlayer_x                                         0xF2CAF0
#define pinstMercenaryData_x                                       0xFBF2A8
#define pinstMercenaryStats_x                                      0x10D3680
#define pinstMercAltAbilities_x                                    0xE7A0D8
#define pinstModelPlayer_x                                         0xF2CB1C
#define pinstPCData_x                                              0xF2CADC
#define pinstSkillMgr_x                                            0xFC0110
#define pinstSpawnManager_x                                        0xFBF9F8
#define pinstSpellManager_x                                        0xFC0258
#define pinstSpellSets_x                                           0xFB715C
#define pinstStringTable_x                                         0xF2CA84
#define pinstSwitchManager_x                                       0xF2A140
#define pinstTarget_x                                              0xF2CB08
#define pinstTargetObject_x                                        0xF2CAE0
#define pinstTargetSwitch_x                                        0xF2CAE4
#define pinstTaskMember_x                                          0xE78B68
#define pinstTrackTarget_x                                         0xF2CAFC
#define pinstTradeTarget_x                                         0xF2CAEC
#define instTributeActive_x                                        0xBE744D
#define pinstViewActor_x                                           0xE7969C
#define pinstWorldData_x                                           0xF2CAC0
#define pinstZoneAddr_x                                            0xF3A474
#define pinstPlayerPath_x                                          0xFBFA58
#define pinstTargetIndicator_x                                     0xFC03F0
#define pinstCTargetManager_x                                      0xFC0450

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAchievementsWnd_x                                    0xE79614
#define pinstCTextOverlay_x                                        0xD36BE0
#define pinstCAudioTriggersWindow_x                                0xD36A70
#define pinstCCharacterSelect_x                                    0xE7952C
#define pinstCFacePick_x                                           0xE792DC
#define pinstCNoteWnd_x                                            0xE794E4
#define pinstCBookWnd_x                                            0xE794EC
#define pinstCPetInfoWnd_x                                         0xE794F0
#define pinstCTrainWnd_x                                           0xE794F4
#define pinstCSkillsWnd_x                                          0xE794F8
#define pinstCSkillsSelectWnd_x                                    0xE794FC
#define pinstCCombatSkillsSelectWnd_x                              0xE79500
#define pinstCFriendsWnd_x                                         0xE79504
#define pinstCAuraWnd_x                                            0xE79508
#define pinstCRespawnWnd_x                                         0xE7950C
#define pinstCBandolierWnd_x                                       0xE79510
#define pinstCPotionBeltWnd_x                                      0xE79514
#define pinstCAAWnd_x                                              0xE79518
#define pinstCAlarmWnd_x                                           0xE79524
#define pinstCGroupSearchFiltersWnd_x                              0xE7951C
#define pinstCLoadskinWnd_x                                        0xE79520
#define pinstCLargeDialogWnd_x                                     0x10D2578
#define pinstCMusicPlayerWnd_x                                     0xE79528
#define pinstCMailWnd_x                                            0xE79530
#define pinstCMailCompositionWnd_x                                 0xE79534
#define pinstCMailAddressBookWnd_x                                 0xE79538
#define pinstCRaidWnd_x                                            0xE79540
#define pinstCRaidOptionsWnd_x                                     0xE79544
#define pinstCBreathWnd_x                                          0xE79548
#define pinstCMapViewWnd_x                                         0xE7954C
#define pinstCMapToolbarWnd_x                                      0xE79550
#define pinstCEditLabelWnd_x                                       0xE79554
#define pinstCTargetWnd_x                                          0xE79558
#define pinstCColorPickerWnd_x                                     0xE7955C
#define pinstCPlayerWnd_x                                          0xE79560
#define pinstCOptionsWnd_x                                         0xE79564
#define pinstCBuffWindowNORMAL_x                                   0xE79568
#define pinstCBuffWindowSHORT_x                                    0xE7956C
#define pinstCharacterCreation_x                                   0xE79570
#define pinstCCursorAttachment_x                                   0xE79574
#define pinstCCastingWnd_x                                         0xE79578
#define pinstCCastSpellWnd_x                                       0xE7957C
#define pinstCSpellBookWnd_x                                       0xE79580
#define pinstCInventoryWnd_x                                       0xE79584
#define pinstCBankWnd_x                                            0xE7958C
#define pinstCQuantityWnd_x                                        0xE79590
#define pinstCLootWnd_x                                            0xE79594
#define pinstCActionsWnd_x                                         0xE79598
#define pinstCCombatAbilityWnd_x                                   0xE795A0
#define pinstCMerchantWnd_x                                        0xE795A4
#define pinstCTradeWnd_x                                           0xE795A8
#define pinstCSelectorWnd_x                                        0xE795AC
#define pinstCBazaarWnd_x                                          0xE795B0
#define pinstCBazaarSearchWnd_x                                    0xE795B4
#define pinstCGiveWnd_x                                            0xE795D0
#define pinstCTrackingWnd_x                                        0xE795D8
#define pinstCInspectWnd_x                                         0xE795DC
#define pinstCSocialEditWnd_x                                      0xE795E0
#define pinstCFeedbackWnd_x                                        0xE795E4
#define pinstCBugReportWnd_x                                       0xE795E8
#define pinstCVideoModesWnd_x                                      0xE795EC
#define pinstCTextEntryWnd_x                                       0xE795F4
#define pinstCFileSelectionWnd_x                                   0xE795F8
#define pinstCCompassWnd_x                                         0xE795FC
#define pinstCPlayerNotesWnd_x                                     0xE79600
#define pinstCGemsGameWnd_x                                        0xE79604
#define pinstCTimeLeftWnd_x                                        0xE79608
#define pinstCPetitionQWnd_x                                       0xE79624
#define pinstCSoulmarkWnd_x                                        0xE79628
#define pinstCStoryWnd_x                                           0xE7962C
#define pinstCJournalTextWnd_x                                     0xE79630
#define pinstCJournalCatWnd_x                                      0xE79634
#define pinstCBodyTintWnd_x                                        0xE79638
#define pinstCServerListWnd_x                                      0xE7963C
#define pinstCAvaZoneWnd_x                                         0xE79648
#define pinstCBlockedBuffWnd_x                                     0xE7964C
#define pinstCBlockedPetBuffWnd_x                                  0xE79650
#define pinstCInvSlotMgr_x                                         0xE79694
#define pinstCContainerMgr_x                                       0xE79698
#define pinstCAdventureLeaderboardWnd_x                            0x10CC3A0
#define pinstCAdventureRequestWnd_x                                0x10CC418
#define pinstCAltStorageWnd_x                                      0x10CC6F8
#define pinstCAdventureStatsWnd_x                                  0x10CC490
#define pinstCBarterMerchantWnd_x                                  0x10CD2E0
#define pinstCBarterSearchWnd_x                                    0x10CD358
#define pinstCBarterWnd_x                                          0x10CD3D0
#define pinstCChatWindowManager_x                                  0x10CDA60
#define pinstCDynamicZoneWnd_x                                     0x10CDF10
#define pinstCEQMainWnd_x                                          0x10CE0A8
#define pinstCFellowshipWnd_x                                      0x10CDEA4
#define pinstCFindLocationWnd_x                                    0x10CE378
#define pinstCGroupSearchWnd_x                                     0x10CE648
#define pinstCGroupWnd_x                                           0x10CE6C0
#define pinstCGuildBankWnd_x                                       0x10CE738
#define pinstCGuildMgmtWnd_x                                       0x10D0828
#define pinstCHotButtonWnd_x                                       0x10D0924
#define pinstCHotButtonWnd1_x                                      0x10D0924
#define pinstCHotButtonWnd2_x                                      0x10D0928
#define pinstCHotButtonWnd3_x                                      0x10D092C
#define pinstCHotButtonWnd4_x                                      0x10D0950
#define pinstCItemDisplayManager_x                                 0x10D0C48
#define pinstCItemExpTransferWnd_x                                 0x10D0CC4
#define pinstCLFGuildWnd_x                                         0x10D0FA0
#define pinstCMIZoneSelectWnd_x                                    0x10D1588
#define pinstCConfirmationDialog_x                                 0x10D1C90
#define pinstCPopupWndManager_x                                    0x10D1C90
#define pinstCProgressionSelectionWnd_x                            0x10D1D80
#define pinstCPvPStatsWnd_x                                        0x10D1E70
#define pinstCTaskWnd_x                                            0x10D3940
#define pinstCTaskSomething_x                                      0xD47710
#define pinstCTaskTemplateSelectWnd_x                              0x10D38C8
#define pinstCTipWndOFDAY_x                                        0x10D3AA8
#define pinstCTipWndCONTEXT_x                                      0x10D3AAC
#define pinstCTitleWnd_x                                           0x10D3B28
#define pinstCContextMenuManager_x                                 0x173751C
#define pinstCVoiceMacroWnd_x                                      0xFC0828
#define pinstCHtmlWnd_x                                            0xFC0918
#define pinstIconCache_x                                           0x10CE07C
#define pinstCTradeskillWnd_x                                      0x10D3C28
#define pinstCAdvancedLootWnd_x                                    0xE79688
#define pinstRewardSelectionWnd_x                                  0x10D2398

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x538130
#define __ConvertItemTags_x                                        0x5259B0
#define __ExecuteCmd_x                                             0x510090
#define __EQGetTime_x                                              0x88C660
#define __get_melee_range_x                                        0x516CA0
#define __GetGaugeValueFromEQ_x                                    0x79E700
#define __GetLabelFromEQ_x                                         0x79F950
#define __ToggleKeyRingItem_x                                      0x480140
#define __GetXTargetType_x                                         0x91D700
#define __LoadFrontEnd_x                                           0x62CBB0
#define __NewUIINI_x                                               0x79E0D0
#define __ProcessGameEvents_x                                      0x570FE0
#define __ProcessMouseEvent_x                                      0x570780
#define CrashDetected_x                                            0x62E570
#define wwsCrashReportCheckForUploader_x                           0x7EC030
#define DrawNetStatus_x                                            0x5A7210
#define Util__FastTime_x                                           0x88C300
#define Expansion_HoT_x                                            0xF3B2B8
#define __HelpPath_x                                               0xFBE9B0
#define __STMLToText_x                                             0x8D23F0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420460
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B200
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41AFE0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C7570
#define AltAdvManager__IsAbilityReady_x                            0x4C75E0
#define AltAdvManager__GetAAById_x                                 0x4C79A0
#define AltAdvManager__CanTrainAbility_x                           0x4C82A0
#define AltAdvManager__CanSeeAbility_x                             0x4C7E60

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463700
#define CharacterZoneClient__MakeMeVisible_x                       0x4680C0
#define CharacterZoneClient__IsStackBlocked_x                      0x447B70
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x447030
#define CharacterZoneClient__GetItemCountWorn_x                    0x461530
#define CharacterZoneClient__GetItemCountInInventory_x             0x461610
#define CharacterZoneClient__GetCursorItemCount_x                  0x4616F0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x65C5E0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66A8E0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x586830
#define CButtonWnd__CButtonWnd_x                                   0x8C6760

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x685B70
#define CChatManager__InitContextMenu_x                            0x6866F0
#define CChatManager__FreeChatWindow_x                             0x685670
#define CChatManager__GetLockedActiveChatWindow_x                  0x68AE00
#define CChatManager__SetLockedActiveChatWindow_x                  0x685B40

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D0750
#define CContextMenu__dCContextMenu_x                              0x8D0960
#define CContextMenu__AddMenuItem_x                                0x8D0970
#define CContextMenu__RemoveMenuItem_x                             0x8D0C60
#define CContextMenu__RemoveAllMenuItems_x                         0x8D0C80
#define CContextMenu__CheckMenuItem_x                              0x8D0D00

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8BCCF0
#define CContextMenuManager__RemoveMenu_x                          0x8BD090
#define CContextMenuManager__PopupMenu_x                           0x8BD4E0
#define CContextMenuManager__Flush_x                               0x8BCD60
#define CContextMenuManager__GetMenu_x                             0x4168E0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x870B00
#define CChatService__GetFriendName_x                              0x870B10

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x68B960
#define CChatWindow__Clear_x                                       0x68B530
#define CChatWindow__WndNotification_x                             0x68BEA0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C0B50
#define CComboWnd__Draw_x                                          0x8C0D60
#define CComboWnd__GetCurChoice_x                                  0x8C0900
#define CComboWnd__GetListRect_x                                   0x8C1000
#define CComboWnd__GetTextRect_x                                   0x8C0BC0
#define CComboWnd__InsertChoice_x                                  0x8C1070
#define CComboWnd__SetColors_x                                     0x8C0890
#define CComboWnd__SetChoice_x                                     0x8C08C0
#define CComboWnd__GetItemCount_x                                  0x8C08F0
#define CComboWnd__GetCurChoiceText_x                              0x8C0940


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6950B0
#define CContainerWnd__vftable_x                                   0xAD0410

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B59C0
#define CDisplay__GetClickedActor_x                                0x4AE300
#define CDisplay__GetUserDefinedColor_x                            0x4ACEE0
#define CDisplay__GetWorldFilePath_x                               0x4AC330
#define CDisplay__is3dON_x                                         0x4AB7C0
#define CDisplay__ReloadUI_x                                       0x4C0F30
#define CDisplay__WriteTextHD2_x                                   0x4B1D80

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E6DC0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D4C80
#define CEditWnd__GetCharIndexPt_x                                 0x8D5D20
#define CEditWnd__GetDisplayString_x                               0x8D4E30
#define CEditWnd__GetHorzOffset_x                                  0x8D5170
#define CEditWnd__GetLineForPrintableChar_x                        0x8D57E0
#define CEditWnd__GetSelStartPt_x                                  0x8D5FE0
#define CEditWnd__GetSTMLSafeText_x                                0x8D5310
#define CEditWnd__PointFromPrintableChar_x                         0x8D58D0
#define CEditWnd__SelectableCharFromPoint_x                        0x8D5A50
#define CEditWnd__SetEditable_x                                    0x8D52E0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x551BC0
#define CEverQuest__CreateTargetIndicator_x                        0x552AB0
#define CEverQuest__DeleteTargetIndicator_x                        0x552B30
#define CEverQuest__DoTellWindow_x                                 0x472D00
#define CEverQuest__OutputTextToLog_x                              0x472960
#define CEverQuest__DropHeldItemOnGround_x                         0x568CD0
#define CEverQuest__dsp_chat_x                                     0x473040
#define CEverQuest__trimName_x                                     0x54E510
#define CEverQuest__Emote_x                                        0x567020
#define CEverQuest__EnterZone_x                                    0x562010
#define CEverQuest__GetBodyTypeDesc_x                              0x54BF70
#define CEverQuest__GetClassDesc_x                                 0x555840
#define CEverQuest__GetClassThreeLetterCode_x                      0x555E40
#define CEverQuest__GetDeityDesc_x                                 0x54C850
#define CEverQuest__GetLangDesc_x                                  0x54C300
#define CEverQuest__GetRaceDesc_x                                  0x556000
#define CEverQuest__InterpretCmd_x                                 0x559E30
#define CEverQuest__LeftClickedOnPlayer_x                          0x56D6A0
#define CEverQuest__LMouseUp_x                                     0x56F7A0
#define CEverQuest__RightClickedOnPlayer_x                         0x56E1B0
#define CEverQuest__RMouseUp_x                                     0x56F200
#define CEverQuest__SetGameState_x                                 0x552480
#define CEverQuest__UPCNotificationFlush_x                         0x549D80
#define CEverQuest__IssuePetCommand_x                              0x55A810

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A5E70
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A5ED0
#define CGaugeWnd__Draw_x                                          0x6A6300

// CGuild
#define CGuild__FindMemberByName_x                                 0x4373E0
#define CGuild__GetGuildName_x                                     0x4378B0
#define CGuild__GetGuildIndex_x                                    0x438A80

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C2410

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6CF5A0
#define CInvSlotMgr__MoveItem_x                                    0x6D0450
#define CInvSlotMgr__SelectSlot_x                                  0x6CF650

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6CEA50
#define CInvSlot__SliderComplete_x                                 0x6CC260
#define CInvSlot__GetItemBase_x                                    0x6CB6F0
#define CInvSlot__UpdateItem_x                                     0x6CBC70

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D18B0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6D29D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79A100
#define CItemDisplayWnd__UpdateStrings_x                           0x6D39F0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6E09B0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6E0EF0
#define CItemDisplayWnd__SetItem_x                                 0x6E69F0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7D1290

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6DA850

// CLabel 
#define CLabel__Draw_x                                             0x6ED6D0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8AC7D0
#define CListWnd__dCListWnd_x                                      0x8AD9F0
#define CListWnd__AddColumn_x                                      0x8AD990
#define CListWnd__AddColumn1_x                                     0x8AD020
#define CListWnd__AddLine_x                                        0x8ACA80
#define CListWnd__AddString_x                                      0x8ACCA0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8A9A50
#define CListWnd__CalculateVSBRange_x                              0x8ABC90
#define CListWnd__ClearSel_x                                       0x8A8D70
#define CListWnd__ClearAllSel_x                                    0x8A8D20
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8AC660
#define CListWnd__Compare_x                                        0x8AA5C0
#define CListWnd__Draw_x                                           0x8AB890
#define CListWnd__DrawColumnSeparators_x                           0x8AB720
#define CListWnd__DrawHeader_x                                     0x8A9030
#define CListWnd__DrawItem_x                                       0x8AAC50
#define CListWnd__DrawLine_x                                       0x8AB3C0
#define CListWnd__DrawSeparator_x                                  0x8AB7C0
#define CListWnd__EnableLine_x                                     0x8A8F50
#define CListWnd__EnsureVisible_x                                  0x8A9BB0
#define CListWnd__ExtendSel_x                                      0x8AAB60
#define CListWnd__GetColumnMinWidth_x                              0x8A8720
#define CListWnd__GetColumnWidth_x                                 0x8A8650
#define CListWnd__GetCurSel_x                                      0x8A7E20
#define CListWnd__GetItemAtPoint_x                                 0x8A9E50
#define CListWnd__GetItemAtPoint1_x                                0x8A9EC0
#define CListWnd__GetItemData_x                                    0x8A8160
#define CListWnd__GetItemHeight_x                                  0x8A96B0
#define CListWnd__GetItemIcon_x                                    0x8A8350
#define CListWnd__GetItemRect_x                                    0x8A9C90
#define CListWnd__GetItemText_x                                    0x8A8200
#define CListWnd__GetSelList_x                                     0x8ACF10
#define CListWnd__GetSeparatorRect_x                               0x8AA4F0
#define CListWnd__InsertLine_x                                     0x8ACE80
#define CListWnd__RemoveLine_x                                     0x8ACE90
#define CListWnd__SetColors_x                                      0x8A7F70
#define CListWnd__SetColumnJustification_x                         0x8A89B0
#define CListWnd__SetColumnWidth_x                                 0x8A86D0
#define CListWnd__SetCurSel_x                                      0x8A7E60
#define CListWnd__SetItemColor_x                                   0x8AC350
#define CListWnd__SetItemData_x                                    0x8A8DD0
#define CListWnd__SetItemText_x                                    0x8AC190
#define CListWnd__ShiftColumnSeparator_x                           0x8AC020
#define CListWnd__Sort_x                                           0x8ADAF0
#define CListWnd__ToggleSel_x                                      0x8A8CA0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x706720

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x727BC0
#define CMerchantWnd__RequestBuyItem_x                             0x72EC80
#define CMerchantWnd__RequestSellItem_x                            0x72F750
#define CMerchantWnd__SelectRecoverySlot_x                         0x727E70
#define CMerchantWnd__SelectBuySellSlot_x                          0x727070
#define CMerchantWnd__ActualSelect_x                               0x72BB60

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x83FE20
#define CPacketScrambler__hton_x                                   0x83FE30

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8CB740
#define CSidlManager__CreateLabel_x                                0x790020
#define CSidlManager__CreateXWndFromTemplate_x                     0x8C9C00
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8CBA20

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x6539C0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x6538E0
#define CSidlScreenWnd__ConvertToRes_x                             0x8E6CA0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8C3500
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C46C0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C4770
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C3C40
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8C2EB0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8C2610
#define CSidlScreenWnd__GetSidlPiece_x                             0x8C30A0
#define CSidlScreenWnd__Init1_x                                    0x8C43A0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C35B0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8C27D0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C3E80
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C2260
#define CSidlScreenWnd__StoreIniVis_x                              0x8C25C0
#define CSidlScreenWnd__WndNotification_x                          0x8C4120
#define CSidlScreenWnd__GetChildItem_x                             0x8C26E0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B5FD0
#define CSidlScreenWnd__m_layoutCopy_x                             0x1737580

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F2500
#define CSkillMgr__GetSkillCap_x                                   0x5F26E0
#define CSkillMgr__GetNameToken_x                                  0x5F2120

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E5F70
#define CSliderWnd__SetValue_x                                     0x8E6140
#define CSliderWnd__SetNumTicks_x                                  0x8E68C0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x797D60

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8E18D0
#define CStmlWnd__CalculateHSBRange_x                              0x8D9E50
#define CStmlWnd__CalculateVSBRange_x                              0x8D9EE0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8DA050
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8DA930
#define CStmlWnd__ForceParseNow_x                                  0x8E2290
#define CStmlWnd__GetNextTagPiece_x                                0x8DA830
#define CStmlWnd__GetSTMLText_x                                    0x68ADC0
#define CStmlWnd__GetVisibleText_x                                 0x8DB380
#define CStmlWnd__InitializeWindowVariables_x                      0x8DD6F0
#define CStmlWnd__MakeStmlColorTag_x                               0x8D9150
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D91B0
#define CStmlWnd__SetSTMLText_x                                    0x8DEF40
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E1570
#define CStmlWnd__UpdateHistoryString_x                            0x8DC2B0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8D8870
#define CTabWnd__DrawCurrentPage_x                                 0x8D8100
#define CTabWnd__DrawTab_x                                         0x8D7EC0
#define CTabWnd__GetCurrentPage_x                                  0x8D84B0
#define CTabWnd__GetPageInnerRect_x                                0x8D7BB0
#define CTabWnd__GetTabInnerRect_x                                 0x8D7DB0
#define CTabWnd__GetTabRect_x                                      0x8D7C80
#define CTabWnd__InsertPage_x                                      0x8D8B60
#define CTabWnd__SetPage_x                                         0x8D84E0
#define CTabWnd__SetPageRect_x                                     0x8D87B0
#define CTabWnd__UpdatePage_x                                      0x8D8B00
#define CTabWnd__GetPageFromTabIndex_x                             0x8D7E10
#define CTabWnd__GetCurrentTabIndex_x                              0x8D7B40

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6D2B80
#define CPageWnd__SetTabText_x                                     0x8EFC80

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432F80

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C0500
#define CTextureFont__GetTextExtent_x                              0x8C0260

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x62AE30

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8EC0C0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A5FE0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402A80
#define CXStr__CXStr1_x                                            0x4E7820
#define CXStr__CXStr3_x                                            0x8895E0
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x889750
#define CXStr__operator_equal1_x                                   0x8897A0
#define CXStr__operator_plus_equal1_x                              0x88A8A0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B51F0
#define CXWnd__Center_x                                            0x8BB330
#define CXWnd__ClrFocus_x                                          0x8B4DC0
#define CXWnd__Destroy_x                                           0x8BBDF0
#define CXWnd__DoAllDrawing_x                                      0x8BAF60
#define CXWnd__DrawChildren_x                                      0x8BB110
#define CXWnd__DrawColoredRect_x                                   0x8B55D0
#define CXWnd__DrawTooltip_x                                       0x8B5870
#define CXWnd__DrawTooltipAtPoint_x                                0x8B9ED0
#define CXWnd__GetBorderFrame_x                                    0x8B5CD0
#define CXWnd__GetChildWndAt_x                                     0x8BBCD0
#define CXWnd__GetClientClipRect_x                                 0x8B5A90
#define CXWnd__GetScreenClipRect_x                                 0x8BA5D0
#define CXWnd__GetScreenRect_x                                     0x8B5E70
#define CXWnd__GetTooltipRect_x                                    0x8B5700
#define CXWnd__GetWindowTextA_x                                    0x424460
#define CXWnd__IsActive_x                                          0x8B07A0
#define CXWnd__IsDescendantOf_x                                    0x8B5C20
#define CXWnd__IsReallyVisible_x                                   0x8B8F30
#define CXWnd__IsType_x                                            0x8E8920
#define CXWnd__Move_x                                              0x8B8690
#define CXWnd__Move1_x                                             0x8BAC20
#define CXWnd__ProcessTransition_x                                 0x8B5190
#define CXWnd__Refade_x                                            0x8B4F60
#define CXWnd__Resize_x                                            0x8B5F30
#define CXWnd__Right_x                                             0x8BA3D0
#define CXWnd__SetFocus_x                                          0x8B77D0
#define CXWnd__SetFont_x                                           0x8B4E10
#define CXWnd__SetKeyTooltip_x                                     0x8B61A0
#define CXWnd__SetMouseOver_x                                      0x8BA910
#define CXWnd__StartFade_x                                         0x8B5240
#define CXWnd__GetChildItem_x                                      0x8BA850
#define CXWnd__SetParent_x                                         0x8BBC80

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B2050
#define CXWndManager__DrawWindows_x                                0x8B1C90
#define CXWndManager__GetKeyboardFlags_x                           0x8B02D0
#define CXWndManager__HandleKeyboardMsg_x                          0x8B0C40
#define CXWndManager__RemoveWnd_x                                  0x8B0930

// CDBStr
#define CDBStr__GetString_x                                        0x4A9D60

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E120
#define EQ_Character__Cur_HP_x                                     0x462DA0
#define EQ_Character__Cur_Mana_x                                   0x4568B0
#define EQ_Character__GetAACastingTimeModifier_x                   0x447340
#define EQ_Character__GetCharInfo2_x                               0x85CB10
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F620
#define EQ_Character__GetFocusRangeModifier_x                      0x43F680
#define EQ_Character__GetHPRegen_x                                 0x465F10
#define EQ_Character__GetEnduranceRegen_x                          0x4621C0
#define EQ_Character__GetManaRegen_x                               0x4664B0
#define EQ_Character__Max_Endurance_x                              0x5B9110
#define EQ_Character__Max_HP_x                                     0x4594D0
#define EQ_Character__Max_Mana_x                                   0x5B8F40
#define EQ_Character__doCombatAbility_x                            0x5B6630
#define EQ_Character__UseSkill_x                                   0x46D140
#define EQ_Character__GetConLevel_x                                0x5AB890
#define EQ_Character__IsExpansionFlag_x                            0x4239A0
#define EQ_Character__TotalEffect_x                                0x44B3C0
#define EQ_Character__GetPCSpellAffect_x                           0x447740
#define EQ_Character__SpellDuration_x                              0x445640
#define EQ_Character__FindItemByRecord_x                           0x460200

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x442950
#define CCharacterSelect__EnterWorld_x                             0x442120
#define CCharacterSelect__Quit_x                                   0x440D00

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x58C0B0
#define EQ_Item__CreateItemTagString_x                             0x83E760
#define EQ_Item__IsStackable_x                                     0x833FA0
#define EQ_Item__GetImageNum_x                                     0x836AB0
#define EQ_Item__CreateItemClient_x                                0x58CC90
#define EQ_Item__GetItemValue_x                                    0x83D4A0
#define EQ_Item__ValueSellMerchant_x                               0x83FA70
#define EQ_Item__IsKeyRingItem_x                                   0x834A80
#define EQ_Item__CanGoInBag_x                                      0x58C240
#define EQ_Item__GetMaxItemCount_x                                 0x833E90
#define EQ_Item__GetHeldItem_x                                     0x8358C0
#define EQ_Item__GetAugmentFitBySlot_x                             0x83F890

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C96A0
#define EQ_LoadingS__Array_x                                       0xBF02A8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BB630
#define EQ_PC__GetAlternateAbilityId_x                             0x847E30
#define EQ_PC__GetCombatAbility_x                                  0x847EC0
#define EQ_PC__GetCombatAbilityTimer_x                             0x842C30
#define EQ_PC__GetItemRecastTimer_x                                0x5B4CE0
#define EQ_PC__HasLoreItem_x                                       0x5AEDC0
#define EQ_PC__AlertInventoryChanged_x                             0x5AB860
#define EQ_PC__GetPcZoneClient_x                                   0x5D53E0
#define EQ_PC__RemoveMyAffect_x                                    0x5B4170
#define EQ_PC__GetKeyRingItems_x                                   0x843060

// EQItemList 
#define EQItemList__EQItemList_x                                   0x514D10
#define EQItemList__add_object_x                                   0x540DC0
#define EQItemList__add_item_x                                     0x514C50
#define EQItemList__delete_item_x                                  0x515100
#define EQItemList__FreeItemList_x                                 0x515000

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A9090

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C0C90
#define EQPlayer__dEQPlayer_x                                      0x5C9240
#define EQPlayer__DoAttack_x                                       0x5DB2C0
#define EQPlayer__EQPlayer_x                                       0x5CB950
#define EQPlayer__SetNameSpriteState_x                             0x5C6190
#define EQPlayer__SetNameSpriteTint_x                              0x5C20A0
#define PlayerBase__HasProperty_j_x                                0x9198F0
#define EQPlayer__IsTargetable_x                                   0x91A1F0
#define EQPlayer__CanSee_x                                         0x91A710
#define PlayerZoneClient__ChangeHeight_x                           0x5DB180
#define EQPlayer__CanSeeTargetIndicator_x                          0x91A800
#define PlayerBase__GetVisibilityLineSegment_x                     0x91A4A0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5CF990
#define EQPlayerManager__GetSpawnByName_x                          0x5CFDF0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5CF9C0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x592190
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5921D0
#define KeypressHandler__ClearCommandStateArray_x                  0x591D80
#define KeypressHandler__HandleKeyDown_x                           0x5906E0
#define KeypressHandler__HandleKeyUp_x                             0x590A00
#define KeypressHandler__SaveKeymapping_x                          0x591E50

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6FF0B0
#define MapViewMap__SaveEx_x                                       0x7023E0

#define PlayerPointManager__GetAltCurrency_x                       0x85AC70

// StringTable 
#define StringTable__getString_x                                   0x855980

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B8BA0
#define PcZoneClient__RemovePetEffect_x                            0x5B51B0
#define PcZoneClient__HasAlternateAbility_x                        0x5B5B50
#define PcZoneClient__GetCurrentMod_x                              0x458870
#define PcZoneClient__GetModCap_x                                  0x456030
#define PcZoneClient__CanEquipItem_x                               0x5B6100
#define PcZoneClient__GetItemByID_x                                0x5BAB10
#define PcZoneClient__GetItemByItemClass_x                         0x5BB550

//Doors
#define EQSwitch__UseSwitch_x                                      0x5486B0

//IconCache
#define IconCache__GetIcon_x                                       0x69B6E0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x692430
#define CContainerMgr__CloseContainer_x                            0x692C50

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x75FF10

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5852B0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E36E0
#define EQ_Spell__SpellAffects_x                                   0x4E0D90
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4E0E00
#define CharacterZoneClient__CalcAffectChange_x                    0x446770
#define CLootWnd__LootAll_x                                        0x6F4950
#define CLootWnd__RequestLootSlot_x                                0x6F5160

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7A6BD0
#define CTargetWnd__WndNotification_x                              0x7A66C0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7A6DB0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7ABE30

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4DC430

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x498AC0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8D42B0
#define CSidlManager__FindAnimation1_x                             0x8C9630

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D0EE0
#define CAltAbilityData__GetMercMaxRank_x                          0x4D0E90
#define CAltAbilityData__GetMaxRank_x                              0x4C5C20

//CTargetRing
#define CTargetRing__Cast_x                                        0x582BA0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x455010
#define CharacterBase__CreateItemGlobalIndex_x                     0x471F10
#define CharacterBase__CreateItemIndex_x                           0x50E1C0
#define CharacterBase__GetItemPossession_x                         0x50F650
#define CharacterBase__GetItemByGlobalIndex_x                      0x86AC60

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x67CB80
#define CCastSpellWnd__IsBardSongPlaying_x                         0x67C2E0

//messages
#define msg_spell_worn_off_x                                       0x4EB2A0
#define msg_new_text_x                                             0x4F4840
#define msgTokenTextParam_x                                        0x4F11F0

//SpellManager
#define SpellManager__vftable_x                                    0xAACFE0
#define SpellManager__SpellManager_x                               0x47ADA0
#define Spellmanager__CheckSpellRequirementAssociations_x          0x5F93B0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x91E220

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E77F0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43ADA0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x444FC0
#define ItemGlobalIndex__IsValidIndex_x                            0x454830

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x868A80
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8679C0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6ED920

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6972E0
#define CCursorAttachment__Deactivate_x                            0x696820