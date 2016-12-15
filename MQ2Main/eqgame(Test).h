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
#if defined(TEST)
#include "eqgame-private(test).h"
#endif
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Dec  6 2016"
#define __ExpectedVersionTime                                     "16:33:31"
#define __ActualVersionDate_x                                      0xAC6930
#define __ActualVersionTime_x                                      0xAC693C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x597A60
#define __MemChecker1_x                                            0x88C8A0
#define __MemChecker2_x                                            0x62D780
#define __MemChecker3_x                                            0x62D6D0
#define __MemChecker4_x                                            0x7E0210
#define __EncryptPad0_x                                            0xC2A608
#define __EncryptPad1_x                                            0xD21A68
#define __EncryptPad2_x                                            0xC58C18
#define __EncryptPad3_x                                            0xC58818
#define __EncryptPad4_x                                            0xD0C6B8
#define __EncryptPad5_x                                            0x10CB898
#define __AC1_x                                                    0x79F9F5
#define __AC2_x                                                    0x551787
#define __AC3_x                                                    0x54F920
#define __AC4_x                                                    0x562190
#define __AC5_x                                                    0x574ECB
#define __AC6_x                                                    0x578A6E
#define __AC7_x                                                    0x56F53C
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
#define __do_loot_x                                                0x521000
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
#define pinstCGroupSearchFiltersWnd_x                              0xE7951C
#define pinstCLoadskinWnd_x                                        0xE79520
#define pinstCAlarmWnd_x                                           0xE79524
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
#define pinstCLargeDialogWnd_x                                     0x10D2578
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
#define __CastRay_x                                                0x5382F0
#define __ConvertItemTags_x                                        0x525B60
#define __ExecuteCmd_x                                             0x5102A0
#define __EQGetTime_x                                              0x88C530
#define __get_melee_range_x                                        0x516E60
#define __GetGaugeValueFromEQ_x                                    0x79E730
#define __GetLabelFromEQ_x                                         0x79F980
#define __ToggleKeyRingItem_x                                      0x47FF80
#define __GetXTargetType_x                                         0x91D3A0
#define __LoadFrontEnd_x                                           0x62CE50
#define __NewUIINI_x                                               0x79E110
#define __ProcessGameEvents_x                                      0x5712D0
#define __ProcessMouseEvent_x                                      0x570A70
#define CrashDetected_x                                            0x62E810
#define wwsCrashReportCheckForUploader_x                           0x7EBE80
#define DrawNetStatus_x                                            0x5A77E0
#define Util__FastTime_x                                           0x88C1D0
#define Expansion_HoT_x                                            0xF3B2B8
#define __HelpPath_x                                               0xFBE9B0
#define __STMLToText_x                                             0x8D2200

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420420
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B1C0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41AFA0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C7420
#define AltAdvManager__IsAbilityReady_x                            0x4C7490
#define AltAdvManager__GetAAById_x                                 0x4C7850
#define AltAdvManager__CanTrainAbility_x                           0x4C8150
#define AltAdvManager__CanSeeAbility_x                             0x4C7D10

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463560
#define CharacterZoneClient__MakeMeVisible_x                       0x467F20
#define CharacterZoneClient__IsStackBlocked_x                      0x447A70
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x446F30
#define CharacterZoneClient__GetItemCountWorn_x                    0x461390
#define CharacterZoneClient__GetItemCountInInventory_x             0x461470
#define CharacterZoneClient__GetCursorItemCount_x                  0x461550

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x65C940

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66ABD0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x586A20
#define CButtonWnd__CButtonWnd_x                                   0x8C6590

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x685CD0
#define CChatManager__InitContextMenu_x                            0x686850
#define CChatManager__FreeChatWindow_x                             0x6857D0
#define CChatManager__GetLockedActiveChatWindow_x                  0x68AF60
#define CChatManager__SetLockedActiveChatWindow_x                  0x685CA0
// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D0560
#define CContextMenu__dCContextMenu_x                              0x8D0770
#define CContextMenu__AddMenuItem_x                                0x8D0780
#define CContextMenu__RemoveMenuItem_x                             0x8D0A70
#define CContextMenu__RemoveAllMenuItems_x                         0x8D0A90
#define CContextMenuManager__AddMenu_x                             0x8BCB50
#define CContextMenuManager__RemoveMenu_x                          0x8BCEE0
#define CContextMenuManager__PopupMenu_x                           0x8BD330
#define CContextMenuManager__Flush_x                               0x8BCBC0
#define CContextMenuManager__GetMenu_x                             0x4168A0
#define CContextMenu__CheckMenuItem_x                              0x8D0B10

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x870A70
#define CChatService__GetFriendName_x                              0x870A80

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x68BAB0
#define CChatWindow__Clear_x                                       0x68B680
#define CChatWindow__WndNotification_x                             0x68BFE0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C0980
#define CComboWnd__Draw_x                                          0x8C0B90
#define CComboWnd__GetCurChoice_x                                  0x8C0730
#define CComboWnd__GetListRect_x                                   0x8C0E30
#define CComboWnd__GetTextRect_x                                   0x8C09F0
#define CComboWnd__InsertChoice_x                                  0x8C0EA0
#define CComboWnd__SetColors_x                                     0x8C06C0
#define CComboWnd__SetChoice_x                                     0x8C06F0
#define CComboWnd__GetItemCount_x                                  0x8C0720
#define CComboWnd__GetCurChoiceText_x                              0x8C0770

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x695140
#define CContainerWnd__vftable_x                                   0xAD0410

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B5940
#define CDisplay__GetClickedActor_x                                0x4AE270
#define CDisplay__GetUserDefinedColor_x                            0x4ACE50
#define CDisplay__GetWorldFilePath_x                               0x4AC2A0
#define CDisplay__is3dON_x                                         0x4AB730
#define CDisplay__ReloadUI_x                                       0x4C0EB0
#define CDisplay__WriteTextHD2_x                                   0x4B1D00

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E6B80

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D4A90
#define CEditWnd__GetCharIndexPt_x                                 0x8D5B20
#define CEditWnd__GetDisplayString_x                               0x8D4C40
#define CEditWnd__GetHorzOffset_x                                  0x8D4F80
#define CEditWnd__GetLineForPrintableChar_x                        0x8D55F0
#define CEditWnd__GetSelStartPt_x                                  0x8D5DD0
#define CEditWnd__GetSTMLSafeText_x                                0x8D5120
#define CEditWnd__PointFromPrintableChar_x                         0x8D56E0
#define CEditWnd__SelectableCharFromPoint_x                        0x8D5860
#define CEditWnd__SetEditable_x                                    0x8D50F0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x551ED0
#define CEverQuest__CreateTargetIndicator_x                        0x552DC0
#define CEverQuest__DeleteTargetIndicator_x                        0x552E40
#define CEverQuest__DoTellWindow_x                                 0x472B70
#define CEverQuest__OutputTextToLog_x                              0x4727D0
#define CEverQuest__DropHeldItemOnGround_x                         0x568FE0
#define CEverQuest__dsp_chat_x                                     0x472EB0
#define CEverQuest__trimName_x                                     0x54E820
#define CEverQuest__Emote_x                                        0x567330
#define CEverQuest__EnterZone_x                                    0x562320
#define CEverQuest__GetBodyTypeDesc_x                              0x54C280
#define CEverQuest__GetClassDesc_x                                 0x555B50
#define CEverQuest__GetClassThreeLetterCode_x                      0x556150
#define CEverQuest__GetDeityDesc_x                                 0x54CB60
#define CEverQuest__GetLangDesc_x                                  0x54C610
#define CEverQuest__GetRaceDesc_x                                  0x556310
#define CEverQuest__InterpretCmd_x                                 0x55A140
#define CEverQuest__LeftClickedOnPlayer_x                          0x56D990
#define CEverQuest__LMouseUp_x                                     0x56FA90
#define CEverQuest__RightClickedOnPlayer_x                         0x56E4A0
#define CEverQuest__RMouseUp_x                                     0x56F4F0
#define CEverQuest__SetGameState_x                                 0x552790
#define CEverQuest__UPCNotificationFlush_x                         0x54A090
#define CEverQuest__IssuePetCommand_x                              0x55AB20

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A5F20
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A5F80
#define CGaugeWnd__Draw_x                                          0x6A63B0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4372E0
#define CGuild__GetGuildName_x                                     0x4377B0
#define CGuild__GetGuildIndex_x                                    0x438980

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C2480

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6CF600
#define CInvSlotMgr__MoveItem_x                                    0x6D04A0
#define CInvSlotMgr__SelectSlot_x                                  0x6CF6B0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6CEAB0
#define CInvSlot__SliderComplete_x                                 0x6CC2C0
#define CInvSlot__GetItemBase_x                                    0x6CB760
#define CInvSlot__UpdateItem_x                                     0x6CBCE0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D18D0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6D29F0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79A180
#define CItemDisplayWnd__UpdateStrings_x                           0x6D3A00
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6E09A0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6E0EC0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7D0F30

// CLabel 
#define CLabel__Draw_x                                             0x6ED680

// CListWnd
#define CListWnd__CListWnd_x                                       0x8AC840
#define CListWnd__dCListWnd_x                                      0x8ADA70
#define CListWnd__AddColumn_x                                      0x8ADA10
#define CListWnd__AddColumn1_x                                     0x8AD0A0
#define CListWnd__AddLine_x                                        0x8ACB00
#define CListWnd__AddString_x                                      0x8ACD20
#define CListWnd__CalculateFirstVisibleLine_x                      0x8A9AD0
#define CListWnd__CalculateVSBRange_x                              0x8ABD10
#define CListWnd__ClearSel_x                                       0x8A8DF0
#define CListWnd__ClearAllSel_x                                    0x8A8DA0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8AC6D0
#define CListWnd__Compare_x                                        0x8AA640
#define CListWnd__Draw_x                                           0x8AB910
#define CListWnd__DrawColumnSeparators_x                           0x8AB7A0
#define CListWnd__DrawHeader_x                                     0x8A90B0
#define CListWnd__DrawItem_x                                       0x8AACD0
#define CListWnd__DrawLine_x                                       0x8AB440
#define CListWnd__DrawSeparator_x                                  0x8AB840
#define CListWnd__EnsureVisible_x                                  0x8A9C30
#define CListWnd__ExtendSel_x                                      0x8AABE0
#define CListWnd__GetColumnMinWidth_x                              0x8A87A0
#define CListWnd__GetColumnWidth_x                                 0x8A86D0
#define CListWnd__GetCurSel_x                                      0x8A7EA0
#define CListWnd__GetItemAtPoint_x                                 0x8A9EC0
#define CListWnd__GetItemAtPoint1_x                                0x8A9F30
#define CListWnd__GetItemData_x                                    0x8A81E0
#define CListWnd__GetItemHeight_x                                  0x8A9730
#define CListWnd__GetItemIcon_x                                    0x8A83D0
#define CListWnd__GetItemRect_x                                    0x8A9D00
#define CListWnd__GetItemText_x                                    0x8A8280
#define CListWnd__GetSelList_x                                     0x8ACF90
#define CListWnd__GetSeparatorRect_x                               0x8AA560
#define CListWnd__RemoveLine_x                                     0x8ACF10
#define CListWnd__SetColors_x                                      0x8A7FF0
#define CListWnd__SetColumnJustification_x                         0x8A8A30
#define CListWnd__SetColumnWidth_x                                 0x8A8750
#define CListWnd__SetCurSel_x                                      0x8A7EE0
#define CListWnd__SetItemColor_x                                   0x8AC3C0
#define CListWnd__SetItemData_x                                    0x8A8E50
#define CListWnd__SetItemText_x                                    0x8AC200
#define CListWnd__ShiftColumnSeparator_x                           0x8AC090
#define CListWnd__Sort_x                                           0x8ADB70
#define CListWnd__ToggleSel_x                                      0x8A8D20

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x706630

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x727BB0
#define CMerchantWnd__RequestBuyItem_x                             0x72EC50
#define CMerchantWnd__RequestSellItem_x                            0x72F720
#define CMerchantWnd__SelectRecoverySlot_x                         0x727E60
#define CMerchantWnd__SelectBuySellSlot_x                          0x727060
#define CMerchantWnd__ActualSelect_x                               0x72BB30

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x83FC20
#define CPacketScrambler__hton_x                                   0x83FC30

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8CB590
#define CSidlManager__CreateLabel_x                                0x7900A0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8C9A60
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8CB870

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x653D20
#define CSidlScreenWnd__CalculateVSBRange_x                        0x653C50
#define CSidlScreenWnd__ConvertToRes_x                             0x8E6A60
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8C3310
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C44D0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C4580
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C3A50
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8C2CC0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8C2440
#define CSidlScreenWnd__GetSidlPiece_x                             0x8C2EB0
#define CSidlScreenWnd__Init1_x                                    0x8C41A0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C33C0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8C2600
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C3C90
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C20A0
#define CSidlScreenWnd__StoreIniVis_x                              0x8C23F0
#define CSidlScreenWnd__WndNotification_x                          0x8C3F20
#define CSidlScreenWnd__GetChildItem_x                             0x8C2510
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B5E70
#define CSidlScreenWnd__m_layoutCopy_x                             0x1737580

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F2A20
#define CSkillMgr__GetSkillCap_x                                   0x5F2C00
#define CSkillMgr__GetNameToken_x                                  0x5F2640

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E5D10
#define CSliderWnd__SetValue_x                                     0x8E5EE0
#define CSliderWnd__SetNumTicks_x                                  0x8E6660

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x797DE0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8E16F0
#define CStmlWnd__CalculateHSBRange_x                              0x8D9C40
#define CStmlWnd__CalculateVSBRange_x                              0x8D9CD0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8D9E50
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8DA730
#define CStmlWnd__ForceParseNow_x                                  0x8E2040
#define CStmlWnd__GetNextTagPiece_x                                0x8DA630
#define CStmlWnd__GetSTMLText_x                                    0x68AF20
#define CStmlWnd__GetVisibleText_x                                 0x8DB180
#define CStmlWnd__InitializeWindowVariables_x                      0x8DD500
#define CStmlWnd__MakeStmlColorTag_x                               0x8D8F40
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D8FA0
#define CStmlWnd__SetSTMLText_x                                    0x8DED50
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E1390
#define CStmlWnd__UpdateHistoryString_x                            0x8DC0C0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8D8650
#define CTabWnd__DrawCurrentPage_x                                 0x8D7EE0
#define CTabWnd__DrawTab_x                                         0x8D7CA0
#define CTabWnd__GetCurrentPage_x                                  0x8D8290
#define CTabWnd__GetPageInnerRect_x                                0x8D7990
#define CTabWnd__GetTabInnerRect_x                                 0x8D7B90
#define CTabWnd__GetTabRect_x                                      0x8D7A60
#define CTabWnd__InsertPage_x                                      0x8D8940
#define CTabWnd__SetPage_x                                         0x8D82C0
#define CTabWnd__SetPageRect_x                                     0x8D8590
#define CTabWnd__UpdatePage_x                                      0x8D88E0
#define CTabWnd__GetPageFromTabIndex_x                             0x8D7BF0
#define CTabWnd__GetCurrentTabIndex_x                              0x8D7920

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6D2BA0
#define CPageWnd__SetTabText_x                                     0x8EFA60

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432EA0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C0330

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x62B0E0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8EBEA0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A5F10

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029B0
#define CXStr__CXStr1_x                                            0x8EAC10
#define CXStr__CXStr3_x                                            0x889470
#define CXStr__dCXStr_x                                            0x40A530
#define CXStr__operator_equal_x                                    0x8895E0
#define CXStr__operator_equal1_x                                   0x889630
#define CXStr__operator_plus_equal1_x                              0x88A730

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B50D0
#define CXWnd__Center_x                                            0x8BB140
#define CXWnd__ClrFocus_x                                          0x8B4C90
#define CXWnd__Destroy_x                                           0x8BBC20
#define CXWnd__DoAllDrawing_x                                      0x8BAD90
#define CXWnd__DrawChildren_x                                      0x8BAF30
#define CXWnd__DrawColoredRect_x                                   0x8B5480
#define CXWnd__DrawTooltip_x                                       0x8B5720
#define CXWnd__DrawTooltipAtPoint_x                                0x8B9D80
#define CXWnd__GetBorderFrame_x                                    0x8B5B80
#define CXWnd__GetChildWndAt_x                                     0x8BBB10
#define CXWnd__GetClientClipRect_x                                 0x8B5940
#define CXWnd__GetScreenClipRect_x                                 0x8BA480
#define CXWnd__GetScreenRect_x                                     0x8B5D20
#define CXWnd__GetTooltipRect_x                                    0x8B55B0
#define CXWnd__GetWindowTextA_x                                    0x424380
#define CXWnd__IsActive_x                                          0x8B07E0
#define CXWnd__IsDescendantOf_x                                    0x8B5AD0
#define CXWnd__IsReallyVisible_x                                   0x8B8DC0
#define CXWnd__IsType_x                                            0x8E86B0
#define CXWnd__Move_x                                              0x8B8530
#define CXWnd__Move1_x                                             0x8BAA70
#define CXWnd__ProcessTransition_x                                 0x8B5070
#define CXWnd__Refade_x                                            0x8B4E40
#define CXWnd__Resize_x                                            0x8B5DD0
#define CXWnd__Right_x                                             0x8BA280
#define CXWnd__SetFocus_x                                          0x8B76A0
#define CXWnd__SetFont_x                                           0x8B4CE0
#define CXWnd__SetKeyTooltip_x                                     0x8B6040
#define CXWnd__SetMouseOver_x                                      0x8BA790
#define CXWnd__StartFade_x                                         0x8B5120
#define CXWnd__GetChildItem_x                                      0x8BA6D0
#define CXWnd__SetParent_x                                         0x8BBAC0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B2070
#define CXWndManager__DrawWindows_x                                0x8B1CC0
#define CXWndManager__GetKeyboardFlags_x                           0x8B0350
#define CXWndManager__HandleKeyboardMsg_x                          0x8B0C70
#define CXWndManager__RemoveWnd_x                                  0x8B0970

// CDBStr
#define CDBStr__GetString_x                                        0x4A9CA0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44DFF0
#define EQ_Character__Cur_HP_x                                     0x462C00
#define EQ_Character__Cur_Mana_x                                   0x456710
#define EQ_Character__GetAACastingTimeModifier_x                   0x447240
#define EQ_Character__GetCharInfo2_x                               0x85CA60
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F530
#define EQ_Character__GetFocusRangeModifier_x                      0x43F590
#define EQ_Character__GetHPRegen_x                                 0x465D70
#define EQ_Character__GetEnduranceRegen_x                          0x462020
#define EQ_Character__GetManaRegen_x                               0x466310
#define EQ_Character__Max_Endurance_x                              0x5B9500
#define EQ_Character__Max_HP_x                                     0x459330
#define EQ_Character__Max_Mana_x                                   0x5B9330
#define EQ_Character__doCombatAbility_x                            0x5B6A20
#define EQ_Character__UseSkill_x                                   0x46CFA0
#define EQ_Character__GetConLevel_x                                0x5ABDF0
#define EQ_Character__IsExpansionFlag_x                            0x4238B0
#define EQ_Character__TotalEffect_x                                0x44B290
#define EQ_Character__GetPCSpellAffect_x                           0x447640
#define EQ_Character__SpellDuration_x                              0x445540
#define EQ_Character__FindItemByRecord_x                           0x460060

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x442880
#define CCharacterSelect__EnterWorld_x                             0x442050
#define CCharacterSelect__Quit_x                                   0x440C40

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x58C2C0
#define EQ_Item__CreateItemTagString_x                             0x83E560
#define EQ_Item__IsStackable_x                                     0x833E70
#define EQ_Item__GetImageNum_x                                     0x8368B0
#define EQ_Item__CreateItemClient_x                                0x58CE90
#define EQ_Item__GetItemValue_x                                    0x83D2A0
#define EQ_Item__ValueSellMerchant_x                               0x83F870
#define EQ_Item__IsKeyRingItem_x                                   0x8348C0
#define EQ_Item__CanGoInBag_x                                      0x58C450
#define EQ_Item__GetMaxItemCount_x                                 0x833D60
#define EQ_Item__GetHeldItem_x                                     0x8356D0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C95C0
#define EQ_LoadingS__Array_x                                       0xBF02A8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BBA20
#define EQ_PC__GetAlternateAbilityId_x                             0x847C10
#define EQ_PC__GetCombatAbility_x                                  0x847CA0
#define EQ_PC__GetCombatAbilityTimer_x                             0x842A30
#define EQ_PC__GetItemRecastTimer_x                                0x5B50D0
#define EQ_PC__HasLoreItem_x                                       0x5AF320
#define EQ_PC__AlertInventoryChanged_x                             0x5ABDC0
#define EQ_PC__GetPcZoneClient_x                                   0x5D56F0
#define EQ_PC__RemoveMyAffect_x                                    0x5B4560
#define EQ_PC__GetKeyRingItems_x                                   0x842E50

// EQItemList 
#define EQItemList__EQItemList_x                                   0x514F00
#define EQItemList__add_object_x                                   0x540FD0
#define EQItemList__add_item_x                                     0x514E40
#define EQItemList__delete_item_x                                  0x5152F0
#define EQItemList__FreeItemList_x                                 0x5151F0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A8FA0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C10A0
#define EQPlayer__dEQPlayer_x                                      0x5C9640
#define EQPlayer__DoAttack_x                                       0x5DB5F0
#define EQPlayer__EQPlayer_x                                       0x5CBD50
#define EQPlayer__SetNameSpriteState_x                             0x5C65B0
#define EQPlayer__SetNameSpriteTint_x                              0x5C24B0
#define PlayerBase__HasProperty_j_x                                0x919500
#define EQPlayer__IsTargetable_x                                   0x919E00
#define EQPlayer__CanSee_x                                         0x91A320
#define PlayerZoneClient__ChangeHeight_x                           0x5DB4B0
#define EQPlayer__CanSeeTargetIndicator_x                          0x91A410
#define PlayerBase__GetVisibilityLineSegment_x                     0x91A0B0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5CFD30
#define EQPlayerManager__GetSpawnByName_x                          0x5D0190
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5CFD60

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x592350
#define KeypressHandler__AttachKeyToEqCommand_x                    0x592390
#define KeypressHandler__ClearCommandStateArray_x                  0x591F40
#define KeypressHandler__HandleKeyDown_x                           0x5908A0
#define KeypressHandler__HandleKeyUp_x                             0x590BC0
#define KeypressHandler__SaveKeymapping_x                          0x592010

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6FEFC0
#define MapViewMap__SaveEx_x                                       0x7022F0

#define PlayerPointManager__GetAltCurrency_x                       0x85ABC0

// StringTable 
#define StringTable__getString_x                                   0x855770

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B8F90
#define PcZoneClient__RemovePetEffect_x                            0x5B55A0
#define PcZoneClient__HasAlternateAbility_x                        0x5B5F40
#define PcZoneClient__GetCurrentMod_x                              0x4586D0
#define PcZoneClient__GetModCap_x                                  0x455E90
#define PcZoneClient__CanEquipItem_x                               0x5B64F0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5489C0

//IconCache
#define IconCache__GetIcon_x                                       0x69B740

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6924F0
#define CContainerMgr__CloseContainer_x                            0x692D10

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x75FF20

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5854B0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E3420
#define EQ_Spell__SpellAffects_x                                   0x4E0AD0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4E0B40
#define CharacterZoneClient__CalcAffectChange_x                    0x446670
#define CLootWnd__LootAll_x                                        0x6F48B0
#define CLootWnd__RequestLootSlot_x                                0x6F50C0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7A6BF0
#define CTargetWnd__WndNotification_x                              0x7A66E0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7A6DD0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7ABE40

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4DC190

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x498A70

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8D40C0
#define CSidlManager__FindAnimation1_x                             0x8C9490

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D0C90
#define CAltAbilityData__GetMercMaxRank_x                          0x4D0C40
#define CAltAbilityData__GetMaxRank_x                              0x4C5AD0

//CTargetRing
#define CTargetRing__Cast_x                                        0x582DA0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x454E50
#define CharacterBase__CreateItemGlobalIndex_x                     0x471D70
#define CharacterBase__CreateItemIndex_x                           0x50E400
#define CharacterBase__GetItemPossession_x                         0x50F880
#define CharacterBase__GetItemByGlobalIndex_x                      0x86ABD0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x67CE50
#define CCastSpellWnd__IsBardSongPlaying_x                         0x67C5B0

//messages
#define msg_spell_worn_off_x                                       0x4EAF50
#define msg_new_text_x                                             0x4F44F0
#define msgTokenTextParam_x                                        0x4F0EA0

//SpellManager
#define SpellManager__vftable_x                                    0xAACFE8
#define SpellManager__SpellManager_x                               0x47ABE0
#define Spellmanager__CheckSpellRequirementAssociations_x          0x5F98C0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x91DEC0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E74D0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43ACB0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x444F00
#define ItemGlobalIndex__IsValidIndex_x                            0x454720

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8689E0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x867920

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6ED8D0
