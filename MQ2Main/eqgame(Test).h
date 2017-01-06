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
#define __ExpectedVersionDate                                     "Dec 19 2016"
#define __ExpectedVersionTime                                     "12:55:31"
#define __ActualVersionDate_x                                      0xAC5990
#define __ActualVersionTime_x                                      0xAC599C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x596A30
#define __MemChecker1_x                                            0x88B5E0
#define __MemChecker2_x                                            0x62C890
#define __MemChecker3_x                                            0x62C7E0
#define __MemChecker4_x                                            0x7DEDA0
#define __EncryptPad0_x                                            0xC29608
#define __EncryptPad1_x                                            0xD20A68
#define __EncryptPad2_x                                            0xC57C18
#define __EncryptPad3_x                                            0xC57818
#define __EncryptPad4_x                                            0xD0B6B8
#define __EncryptPad5_x                                            0x10CA898
#define __AC1_x                                                    0x79E795
#define __AC2_x                                                    0x5508C7
#define __AC3_x                                                    0x54EA60
#define __AC4_x                                                    0x5612D0
#define __AC5_x                                                    0x57401B
#define __AC6_x                                                    0x577BBE
#define __AC7_x                                                    0x56E68C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FA5E20

// Direct Input
#define DI8__Main_x                                                0x10CA870
#define DI8__Keyboard_x                                            0x10CA874
#define DI8__Mouse_x                                               0x10CA878
#define DI8__Mouse_Copy_x                                          0xF38F5C
#define DI8__Mouse_Check_x                                         0xFC275C
#define __Attack_x                                                 0xFBD443
#define __Autofire_x                                               0xFBD444
#define __BindList_x                                               0xC00418
#define g_eqCommandStates_x                                        0xF27F88
#define __Clicks_x                                                 0xF39018
#define __CommandList_x                                            0xC02F28
#define __CurrentMapLabel_x                                        0x10D02F8
#define __CurrentSocial_x                                          0xBCE084
#define __DoAbilityList_x                                          0xF6F6F8
#define __do_loot_x                                                0x520250
#define __DrawHandler_x                                            0x17371BC
#define __GroupCount_x                                             0xF295B2

#define __Guilds_x                                                 0xF2F1C8
#define __gWorld_x                                                 0xF2BA6C
#define __HotkeyPage_x                                             0xFB60F8
#define __HWnd_x                                                   0xFC2778
#define __InChatMode_x                                             0xF38F44
#define __LastTell_x                                               0xF3ADF4
#define __LMouseHeldTime_x                                         0xF39084
#define __Mouse_x                                                  0x10CA87C
#define __MouseLook_x                                              0xF38FDE
#define __MouseEventTime_x                                         0xFBDC44
#define __gpbCommandEvent_x                                        0xF2BB34
#define __NetStatusToggle_x                                        0xF38FE1
#define __PCNames_x                                                0xF3A410
#define __RangeAttackReady_x                                       0xF3A14C
#define __RMouseHeldTime_x                                         0xF39080
#define __RunWalkState_x                                           0xF38F48
#define __ScreenMode_x                                             0xE77C88
#define __ScreenX_x                                                0xF38EFC
#define __ScreenY_x                                                0xF38EF8
#define __ScreenXMax_x                                             0xF38F00
#define __ScreenYMax_x                                             0xF38F04
#define __ServerHost_x                                             0xF294FC
#define __ServerName_x                                             0xF6F6B8
#define __ShiftKeyDown_x                                           0xF395D8
#define __ShowNames_x                                              0xF3A30C
#define __Socials_x                                                0xF6F7B8
#define __SubscriptionType_x                                       0x10FE304
#define __TargetAggroHolder_x                                      0x10D2534
#define __ZoneType_x                                               0xF393DC
#define __GroupAggro_x                                             0x10D2574
#define __LoginName_x                                              0xFC1354
#define __Inviter_x                                                0xFBD3C0
#define __AttackOnAssist_x                                         0xF3A2C8
#define __UseTellWindows_x                                         0xF3A5A8

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF2BB58
#define instEQZoneInfo_x                                           0xF391D4
#define instKeypressHandler_x                                      0xFBDC28
#define pinstActiveBanker_x                                        0xF2BB10
#define pinstActiveCorpse_x                                        0xF2BB14
#define pinstActiveGMaster_x                                       0xF2BB18
#define pinstActiveMerchant_x                                      0xF2BB0C
#define pinstAggroInfo_x                                           0xD356E8
#define pinstAltAdvManager_x                                       0xE78D50
#define pinstAuraMgr_x                                             0xD45E58
#define pinstBandageTarget_x                                       0xF2BAF8
#define pinstCamActor_x                                            0xE786A0
#define pinstCDBStr_x                                              0xE77C1C
#define pinstCDisplay_x                                            0xF2BB20
#define pinstCEverQuest_x                                          0x10CA9F0
#define pinstCharData_x                                            0xF2BADC
#define pinstCharSpawn_x                                           0xF2BB04
#define pinstControlledMissile_x                                   0xF2BAD8
#define pinstControlledPlayer_x                                    0xF2BB04
#define pinstCSidlManager_x                                        0x17365AC
#define pinstCXWndManager_x                                        0x17365A4
#define instDynamicZone_x                                          0xF38D90
#define pinstDZMember_x                                            0xF38EA0
#define pinstDZTimerInfo_x                                         0xF38EA4
#define pinstEQItemList_x                                          0xF281D8
#define pinstEQObjectList_x                                        0xF28FAC
#define instEQMisc_x                                               0xBE6428
#define pinstEQSoundManager_x                                      0xE79320
#define instExpeditionLeader_x                                     0xF38DDA
#define instExpeditionName_x                                       0xF38E1A
#define pinstGroup_x                                               0xF295AE
#define pinstImeManager_x                                          0x17365B0
#define pinstLocalPlayer_x                                         0xF2BAF0
#define pinstMercenaryData_x                                       0xFBE2A8
#define pinstMercenaryStats_x                                      0x10D2680
#define pinstMercAltAbilities_x                                    0xE790D8
#define pinstModelPlayer_x                                         0xF2BB1C
#define pinstPCData_x                                              0xF2BADC
#define pinstSkillMgr_x                                            0xFBF110
#define pinstSpawnManager_x                                        0xFBE9F8
#define pinstSpellManager_x                                        0xFBF258
#define pinstSpellSets_x                                           0xFB615C
#define pinstStringTable_x                                         0xF2BA84
#define pinstSwitchManager_x                                       0xF29140
#define pinstTarget_x                                              0xF2BB08
#define pinstTargetObject_x                                        0xF2BAE0
#define pinstTargetSwitch_x                                        0xF2BAE4
#define pinstTaskMember_x                                          0xE77B68
#define pinstTrackTarget_x                                         0xF2BAFC
#define pinstTradeTarget_x                                         0xF2BAEC
#define instTributeActive_x                                        0xBE644D
#define pinstViewActor_x                                           0xE7869C
#define pinstWorldData_x                                           0xF2BAC0
#define pinstZoneAddr_x                                            0xF39474
#define pinstPlayerPath_x                                          0xFBEA58
#define pinstTargetIndicator_x                                     0xFBF3F0
#define pinstCTargetManager_x                                      0xFBF450

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAchievementsWnd_x                                    0xE78614
#define pinstCTextOverlay_x                                        0xD35BE0
#define pinstCAudioTriggersWindow_x                                0xD35A70
#define pinstCCharacterSelect_x                                    0xE7852C
#define pinstCFacePick_x                                           0xE782DC
#define pinstCNoteWnd_x                                            0xE784E4
#define pinstCBookWnd_x                                            0xE784EC
#define pinstCPetInfoWnd_x                                         0xE784F0
#define pinstCTrainWnd_x                                           0xE784F4
#define pinstCSkillsWnd_x                                          0xE784F8
#define pinstCSkillsSelectWnd_x                                    0xE784FC
#define pinstCCombatSkillsSelectWnd_x                              0xE78500
#define pinstCFriendsWnd_x                                         0xE78504
#define pinstCAuraWnd_x                                            0xE78508
#define pinstCRespawnWnd_x                                         0xE7850C
#define pinstCBandolierWnd_x                                       0xE78510
#define pinstCPotionBeltWnd_x                                      0xE78514
#define pinstCAAWnd_x                                              0xE78518
#define pinstCGroupSearchFiltersWnd_x                              0xE7851C
#define pinstCLoadskinWnd_x                                        0xE78520
#define pinstCAlarmWnd_x                                           0xE78524
#define pinstCMusicPlayerWnd_x                                     0xE78528
#define pinstCMailWnd_x                                            0xE78530
#define pinstCMailCompositionWnd_x                                 0xE78534
#define pinstCMailAddressBookWnd_x                                 0xE78538
#define pinstCRaidWnd_x                                            0xE78540
#define pinstCRaidOptionsWnd_x                                     0xE78544
#define pinstCBreathWnd_x                                          0xE78548
#define pinstCMapViewWnd_x                                         0xE7854C
#define pinstCMapToolbarWnd_x                                      0xE78550
#define pinstCEditLabelWnd_x                                       0xE78554
#define pinstCTargetWnd_x                                          0xE78558
#define pinstCColorPickerWnd_x                                     0xE7855C
#define pinstCPlayerWnd_x                                          0xE78560
#define pinstCOptionsWnd_x                                         0xE78564
#define pinstCBuffWindowNORMAL_x                                   0xE78568
#define pinstCBuffWindowSHORT_x                                    0xE7856C
#define pinstCharacterCreation_x                                   0xE78570
#define pinstCCursorAttachment_x                                   0xE78574
#define pinstCCastingWnd_x                                         0xE78578
#define pinstCCastSpellWnd_x                                       0xE7857C
#define pinstCSpellBookWnd_x                                       0xE78580
#define pinstCInventoryWnd_x                                       0xE78584
#define pinstCBankWnd_x                                            0xE7858C
#define pinstCQuantityWnd_x                                        0xE78590
#define pinstCLootWnd_x                                            0xE78594
#define pinstCActionsWnd_x                                         0xE78598
#define pinstCCombatAbilityWnd_x                                   0xE785A0
#define pinstCMerchantWnd_x                                        0xE785A4
#define pinstCTradeWnd_x                                           0xE785A8
#define pinstCSelectorWnd_x                                        0xE785AC
#define pinstCBazaarWnd_x                                          0xE785B0
#define pinstCBazaarSearchWnd_x                                    0xE785B4
#define pinstCGiveWnd_x                                            0xE785D0
#define pinstCTrackingWnd_x                                        0xE785D8
#define pinstCInspectWnd_x                                         0xE785DC
#define pinstCSocialEditWnd_x                                      0xE785E0
#define pinstCFeedbackWnd_x                                        0xE785E4
#define pinstCBugReportWnd_x                                       0xE785E8
#define pinstCVideoModesWnd_x                                      0xE785EC
#define pinstCTextEntryWnd_x                                       0xE785F4
#define pinstCFileSelectionWnd_x                                   0xE785F8
#define pinstCCompassWnd_x                                         0xE785FC
#define pinstCPlayerNotesWnd_x                                     0xE78600
#define pinstCGemsGameWnd_x                                        0xE78604
#define pinstCTimeLeftWnd_x                                        0xE78608
#define pinstCPetitionQWnd_x                                       0xE78624
#define pinstCSoulmarkWnd_x                                        0xE78628
#define pinstCStoryWnd_x                                           0xE7862C
#define pinstCJournalTextWnd_x                                     0xE78630
#define pinstCJournalCatWnd_x                                      0xE78634
#define pinstCBodyTintWnd_x                                        0xE78638
#define pinstCServerListWnd_x                                      0xE7863C
#define pinstCAvaZoneWnd_x                                         0xE78648
#define pinstCBlockedBuffWnd_x                                     0xE7864C
#define pinstCBlockedPetBuffWnd_x                                  0xE78650
#define pinstCInvSlotMgr_x                                         0xE78694
#define pinstCContainerMgr_x                                       0xE78698
#define pinstCAdventureLeaderboardWnd_x                            0x10CB3A0
#define pinstCAdventureRequestWnd_x                                0x10CB418
#define pinstCAltStorageWnd_x                                      0x10CB6F8
#define pinstCAdventureStatsWnd_x                                  0x10CB490
#define pinstCBarterMerchantWnd_x                                  0x10CC2E0
#define pinstCBarterSearchWnd_x                                    0x10CC358
#define pinstCBarterWnd_x                                          0x10CC3D0
#define pinstCChatWindowManager_x                                  0x10CCA60
#define pinstCDynamicZoneWnd_x                                     0x10CCF10
#define pinstCEQMainWnd_x                                          0x10CD0A8
#define pinstCFellowshipWnd_x                                      0x10CCEA4
#define pinstCFindLocationWnd_x                                    0x10CD378
#define pinstCGroupSearchWnd_x                                     0x10CD648
#define pinstCGroupWnd_x                                           0x10CD6C0
#define pinstCGuildBankWnd_x                                       0x10CD738
#define pinstCGuildMgmtWnd_x                                       0x10CF828
#define pinstCHotButtonWnd_x                                       0x10CF924
#define pinstCHotButtonWnd1_x                                      0x10CF924
#define pinstCHotButtonWnd2_x                                      0x10CF928
#define pinstCHotButtonWnd3_x                                      0x10CF92C
#define pinstCHotButtonWnd4_x                                      0x10CF950
#define pinstCItemDisplayManager_x                                 0x10CFC48
#define pinstCItemExpTransferWnd_x                                 0x10CFCC4
#define pinstCLFGuildWnd_x                                         0x10CFFA0
#define pinstCMIZoneSelectWnd_x                                    0x10D0588
#define pinstCConfirmationDialog_x                                 0x10D0C90
#define pinstCPopupWndManager_x                                    0x10D0C90
#define pinstCProgressionSelectionWnd_x                            0x10D0D80
#define pinstCPvPStatsWnd_x                                        0x10D0E70
#define pinstCLargeDialogWnd_x                                     0x10D1578
#define pinstCTaskWnd_x                                            0x10D2940
#define pinstCTaskSomething_x                                      0xD46710
#define pinstCTaskTemplateSelectWnd_x                              0x10D28C8
#define pinstCTipWndOFDAY_x                                        0x10D2AA8
#define pinstCTipWndCONTEXT_x                                      0x10D2AAC
#define pinstCTitleWnd_x                                           0x10D2B28
#define pinstCContextMenuManager_x                                 0x173651C
#define pinstCVoiceMacroWnd_x                                      0xFBF828
#define pinstCHtmlWnd_x                                            0xFBF918
#define pinstIconCache_x                                           0x10CD07C
#define pinstCTradeskillWnd_x                                      0x10D2C28
#define pinstCAdvancedLootWnd_x                                    0xE78688
#define pinstRewardSelectionWnd_x                                  0x10D1398

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x537540
#define __ConvertItemTags_x                                        0x524DB0
#define __ExecuteCmd_x                                             0x50F4F0
#define __EQGetTime_x                                              0x88B270
#define __get_melee_range_x                                        0x5160B0
#define __GetGaugeValueFromEQ_x                                    0x79D4D0
#define __GetLabelFromEQ_x                                         0x79E720
#define __ToggleKeyRingItem_x                                      0x480020
#define __GetXTargetType_x                                         0x91C310
#define __LoadFrontEnd_x                                           0x62BF60
#define __NewUIINI_x                                               0x79CEB0
#define __ProcessGameEvents_x                                      0x570420
#define __ProcessMouseEvent_x                                      0x56FBC0
#define CrashDetected_x                                            0x62D920
#define wwsCrashReportCheckForUploader_x                           0x7EADB0
#define DrawNetStatus_x                                            0x5A65F0
#define Util__FastTime_x                                           0x88AF10
#define Expansion_HoT_x                                            0xF3A2B8
#define __HelpPath_x                                               0xFBD9B0
#define __STMLToText_x                                             0x8D0FA0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420550
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B2F0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B0D0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C7520
#define AltAdvManager__IsAbilityReady_x                            0x4C7590
#define AltAdvManager__GetAAById_x                                 0x4C7950
#define AltAdvManager__CanTrainAbility_x                           0x4C8250
#define AltAdvManager__CanSeeAbility_x                             0x4C7E10

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463690
#define CharacterZoneClient__MakeMeVisible_x                       0x468050
#define CharacterZoneClient__IsStackBlocked_x                      0x447C00
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4470C0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4614C0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4615A0
#define CharacterZoneClient__GetCursorItemCount_x                  0x461680

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x65BA30

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x669DF0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x585A60
#define CButtonWnd__CButtonWnd_x                                   0x8C5390

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x684E00
#define CChatManager__InitContextMenu_x                            0x685980
#define CChatManager__FreeChatWindow_x                             0x684900
#define CChatManager__GetLockedActiveChatWindow_x                  0x68A090
#define CChatManager__SetLockedActiveChatWindow_x                  0x684DD0
// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8CF300
#define CContextMenu__dCContextMenu_x                              0x8CF510
#define CContextMenu__AddMenuItem_x                                0x8CF520
#define CContextMenu__RemoveMenuItem_x                             0x8CF810
#define CContextMenu__RemoveAllMenuItems_x                         0x8CF830
#define CContextMenuManager__AddMenu_x                             0x8BB910
#define CContextMenuManager__RemoveMenu_x                          0x8BBCB0
#define CContextMenuManager__PopupMenu_x                           0x8BC100
#define CContextMenuManager__Flush_x                               0x8BB980
#define CContextMenuManager__GetMenu_x                             0x4169B0
#define CContextMenu__CheckMenuItem_x                              0x8CF8B0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x86F6F0
#define CChatService__GetFriendName_x                              0x86F700

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x68ABE0
#define CChatWindow__Clear_x                                       0x68A7B0
#define CChatWindow__WndNotification_x                             0x68B110

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8BF760
#define CComboWnd__Draw_x                                          0x8BF970
#define CComboWnd__GetCurChoice_x                                  0x8BF510
#define CComboWnd__GetListRect_x                                   0x8BFC10
#define CComboWnd__GetTextRect_x                                   0x8BF7D0
#define CComboWnd__InsertChoice_x                                  0x8BFC80
#define CComboWnd__SetColors_x                                     0x8BF4A0
#define CComboWnd__SetChoice_x                                     0x8BF4D0
#define CComboWnd__GetItemCount_x                                  0x8BF500
#define CComboWnd__GetCurChoiceText_x                              0x8BF550

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6942F0
#define CContainerWnd__vftable_x                                   0xACF470

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B5A00
#define CDisplay__GetClickedActor_x                                0x4AE330
#define CDisplay__GetUserDefinedColor_x                            0x4ACF10
#define CDisplay__GetWorldFilePath_x                               0x4AC360
#define CDisplay__is3dON_x                                         0x4AB7F0
#define CDisplay__ReloadUI_x                                       0x4C0F70
#define CDisplay__WriteTextHD2_x                                   0x4B1DC0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E5930

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D3830
#define CEditWnd__GetCharIndexPt_x                                 0x8D48C0
#define CEditWnd__GetDisplayString_x                               0x8D39E0
#define CEditWnd__GetHorzOffset_x                                  0x8D3D20
#define CEditWnd__GetLineForPrintableChar_x                        0x8D4390
#define CEditWnd__GetSelStartPt_x                                  0x8D4B70
#define CEditWnd__GetSTMLSafeText_x                                0x8D3EC0
#define CEditWnd__PointFromPrintableChar_x                         0x8D4480
#define CEditWnd__SelectableCharFromPoint_x                        0x8D4600
#define CEditWnd__SetEditable_x                                    0x8D3E90

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x551010
#define CEverQuest__CreateTargetIndicator_x                        0x551F00
#define CEverQuest__DeleteTargetIndicator_x                        0x551F80
#define CEverQuest__DoTellWindow_x                                 0x472CA0
#define CEverQuest__OutputTextToLog_x                              0x472900
#define CEverQuest__DropHeldItemOnGround_x                         0x568120
#define CEverQuest__dsp_chat_x                                     0x472FE0
#define CEverQuest__trimName_x                                     0x54D960
#define CEverQuest__Emote_x                                        0x566470
#define CEverQuest__EnterZone_x                                    0x561460
#define CEverQuest__GetBodyTypeDesc_x                              0x54B3C0
#define CEverQuest__GetClassDesc_x                                 0x554C90
#define CEverQuest__GetClassThreeLetterCode_x                      0x555290
#define CEverQuest__GetDeityDesc_x                                 0x54BCA0
#define CEverQuest__GetLangDesc_x                                  0x54B750
#define CEverQuest__GetRaceDesc_x                                  0x555450
#define CEverQuest__InterpretCmd_x                                 0x559280
#define CEverQuest__LeftClickedOnPlayer_x                          0x56CAE0
#define CEverQuest__LMouseUp_x                                     0x56EBE0
#define CEverQuest__RightClickedOnPlayer_x                         0x56D5F0
#define CEverQuest__RMouseUp_x                                     0x56E640
#define CEverQuest__SetGameState_x                                 0x5518D0
#define CEverQuest__UPCNotificationFlush_x                         0x5491D0
#define CEverQuest__IssuePetCommand_x                              0x559C60

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A5040
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A50A0
#define CGaugeWnd__Draw_x                                          0x6A54D0

// CGuild
#define CGuild__FindMemberByName_x                                 0x437430
#define CGuild__GetGuildName_x                                     0x437900
#define CGuild__GetGuildIndex_x                                    0x438AD0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C1530

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6CE690
#define CInvSlotMgr__MoveItem_x                                    0x6CF530
#define CInvSlotMgr__SelectSlot_x                                  0x6CE740

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6CDB30
#define CInvSlot__SliderComplete_x                                 0x6CB340
#define CInvSlot__GetItemBase_x                                    0x6CA7E0
#define CInvSlot__UpdateItem_x                                     0x6CAD60

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D0950
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6D1A60

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x798EE0
#define CItemDisplayWnd__UpdateStrings_x                           0x6D2A70
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6DF9B0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6DFED0
#define CItemDisplayWnd__SetItem_x                                 0x6E5930

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7CFE70

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6D9860

// CLabel 
#define CLabel__Draw_x                                             0x6EC640

// CListWnd
#define CListWnd__CListWnd_x                                       0x8AB360
#define CListWnd__dCListWnd_x                                      0x8AC580
#define CListWnd__AddColumn_x                                      0x8AC520
#define CListWnd__AddColumn1_x                                     0x8ABBC0
#define CListWnd__AddLine_x                                        0x8AB620
#define CListWnd__AddString_x                                      0x8AB840
#define CListWnd__CalculateFirstVisibleLine_x                      0x8A8600
#define CListWnd__CalculateVSBRange_x                              0x8AA830
#define CListWnd__ClearSel_x                                       0x8A7910
#define CListWnd__ClearAllSel_x                                    0x8A78C0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8AB1F0
#define CListWnd__Compare_x                                        0x8A9170
#define CListWnd__Draw_x                                           0x8AA430
#define CListWnd__DrawColumnSeparators_x                           0x8AA2C0
#define CListWnd__DrawHeader_x                                     0x8A7BD0
#define CListWnd__DrawItem_x                                       0x8A97F0
#define CListWnd__DrawLine_x                                       0x8A9F60
#define CListWnd__DrawSeparator_x                                  0x8AA360
#define CListWnd__EnableLine_x                                     0x8A7AF0
#define CListWnd__EnsureVisible_x                                  0x8A8760
#define CListWnd__ExtendSel_x                                      0x8A9700
#define CListWnd__GetColumnMinWidth_x                              0x8A72C0
#define CListWnd__GetColumnWidth_x                                 0x8A71F0
#define CListWnd__GetCurSel_x                                      0x8A69C0
#define CListWnd__GetItemAtPoint_x                                 0x8A89F0
#define CListWnd__GetItemAtPoint1_x                                0x8A8A60
#define CListWnd__GetItemData_x                                    0x8A6D00
#define CListWnd__GetItemHeight_x                                  0x8A8250
#define CListWnd__GetItemIcon_x                                    0x8A6EF0
#define CListWnd__GetItemRect_x                                    0x8A8830
#define CListWnd__GetItemText_x                                    0x8A6DA0
#define CListWnd__GetSelList_x                                     0x8ABAB0
#define CListWnd__GetSeparatorRect_x                               0x8A9090
#define CListWnd__InsertLine_x                                     0x8ABA20
#define CListWnd__RemoveLine_x                                     0x8ABA30
#define CListWnd__SetColors_x                                      0x8A6B10
#define CListWnd__SetColumnJustification_x                         0x8A7550
#define CListWnd__SetColumnWidth_x                                 0x8A7270
#define CListWnd__SetCurSel_x                                      0x8A6A00
#define CListWnd__SetItemColor_x                                   0x8AAEE0
#define CListWnd__SetItemData_x                                    0x8A7970
#define CListWnd__SetItemText_x                                    0x8AAD20
#define CListWnd__ShiftColumnSeparator_x                           0x8AABB0
#define CListWnd__Sort_x                                           0x8AC680
#define CListWnd__ToggleSel_x                                      0x8A7840

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7057D0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x726A70
#define CMerchantWnd__RequestBuyItem_x                             0x72DAF0
#define CMerchantWnd__RequestSellItem_x                            0x72E5C0
#define CMerchantWnd__SelectRecoverySlot_x                         0x726D20
#define CMerchantWnd__SelectBuySellSlot_x                          0x725F20
#define CMerchantWnd__ActualSelect_x                               0x72A9E0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x83E9C0
#define CPacketScrambler__hton_x                                   0x83E9D0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8CA320
#define CSidlManager__CreateLabel_x                                0x78EDE0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8C87F0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8CA600

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x652DE0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x652D10
#define CSidlScreenWnd__ConvertToRes_x                             0x8E5810
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8C20F0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C32C0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C3370
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C2840
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8C1AA0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8C1220
#define CSidlScreenWnd__GetSidlPiece_x                             0x8C1C90
#define CSidlScreenWnd__Init1_x                                    0x8C2F90
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C21A0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8C13E0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C2A80
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C0E80
#define CSidlScreenWnd__StoreIniVis_x                              0x8C11D0
#define CSidlScreenWnd__WndNotification_x                          0x8C2D10
#define CSidlScreenWnd__GetChildItem_x                             0x8C12F0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B4B40
#define CSidlScreenWnd__m_layoutCopy_x                             0x1736580

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F1870
#define CSkillMgr__GetSkillCap_x                                   0x5F1A50
#define CSkillMgr__GetNameToken_x                                  0x5F1490

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E4AD0
#define CSliderWnd__SetValue_x                                     0x8E4CA0
#define CSliderWnd__SetNumTicks_x                                  0x8E5420

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x796B50

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8E0490
#define CStmlWnd__CalculateHSBRange_x                              0x8D89E0
#define CStmlWnd__CalculateVSBRange_x                              0x8D8A70
#define CStmlWnd__CanBreakAtCharacter_x                            0x8D8BF0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8D94D0
#define CStmlWnd__ForceParseNow_x                                  0x8E0DE0
#define CStmlWnd__GetNextTagPiece_x                                0x8D93D0
#define CStmlWnd__GetSTMLText_x                                    0x68A050
#define CStmlWnd__GetVisibleText_x                                 0x8D9F20
#define CStmlWnd__InitializeWindowVariables_x                      0x8DC2A0
#define CStmlWnd__MakeStmlColorTag_x                               0x8D7CE0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D7D40
#define CStmlWnd__SetSTMLText_x                                    0x8DDAF0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E0130
#define CStmlWnd__UpdateHistoryString_x                            0x8DAE60

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8D73F0
#define CTabWnd__DrawCurrentPage_x                                 0x8D6C80
#define CTabWnd__DrawTab_x                                         0x8D6A40
#define CTabWnd__GetCurrentPage_x                                  0x8D7030
#define CTabWnd__GetPageInnerRect_x                                0x8D6730
#define CTabWnd__GetTabInnerRect_x                                 0x8D6930
#define CTabWnd__GetTabRect_x                                      0x8D6800
#define CTabWnd__InsertPage_x                                      0x8D76E0
#define CTabWnd__SetPage_x                                         0x8D7060
#define CTabWnd__SetPageRect_x                                     0x8D7330
#define CTabWnd__UpdatePage_x                                      0x8D7680
#define CTabWnd__GetPageFromTabIndex_x                             0x8D6990
#define CTabWnd__GetCurrentTabIndex_x                              0x8D66C0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6D1C10
#define CPageWnd__SetTabText_x                                     0x8EE7F0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432FB0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8BF110
#define CTextureFont__GetTextExtent_x                              0x8BEE70

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x62A1D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8EAC30

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A4B20

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402A00
#define CXStr__CXStr1_x                                            0x43FF10
#define CXStr__CXStr3_x                                            0x8881F0
#define CXStr__dCXStr_x                                            0x8E1890
#define CXStr__operator_equal_x                                    0x888360
#define CXStr__operator_equal1_x                                   0x8883B0
#define CXStr__operator_plus_equal1_x                              0x8894B0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B3D60
#define CXWnd__Center_x                                            0x8B9F10
#define CXWnd__ClrFocus_x                                          0x8B3930
#define CXWnd__Destroy_x                                           0x8BA9F0
#define CXWnd__DoAllDrawing_x                                      0x8B9B60
#define CXWnd__DrawChildren_x                                      0x8B9D00
#define CXWnd__DrawColoredRect_x                                   0x8B4130
#define CXWnd__DrawTooltip_x                                       0x8B43D0
#define CXWnd__DrawTooltipAtPoint_x                                0x8B8AE0
#define CXWnd__GetBorderFrame_x                                    0x8B4830
#define CXWnd__GetChildWndAt_x                                     0x8BA8E0
#define CXWnd__GetClientClipRect_x                                 0x8B45F0
#define CXWnd__GetScreenClipRect_x                                 0x8B91E0
#define CXWnd__GetScreenRect_x                                     0x8B49E0
#define CXWnd__GetTooltipRect_x                                    0x8B4260
#define CXWnd__GetWindowTextA_x                                    0x4245F0
#define CXWnd__IsActive_x                                          0x8AF2F0
#define CXWnd__IsDescendantOf_x                                    0x8B4780
#define CXWnd__IsReallyVisible_x                                   0x8B7AF0
#define CXWnd__IsType_x                                            0x8E7470
#define CXWnd__Move_x                                              0x8B71E0
#define CXWnd__Move1_x                                             0x8B9820
#define CXWnd__ProcessTransition_x                                 0x8B3D00
#define CXWnd__Refade_x                                            0x8B3AD0
#define CXWnd__Resize_x                                            0x8B4AA0
#define CXWnd__Right_x                                             0x8B8FE0
#define CXWnd__SetFocus_x                                          0x8B6340
#define CXWnd__SetFont_x                                           0x8B3980
#define CXWnd__SetKeyTooltip_x                                     0x8B4D10
#define CXWnd__SetMouseOver_x                                      0x8B9530
#define CXWnd__StartFade_x                                         0x8B3DB0
#define CXWnd__GetChildItem_x                                      0x8B9470
#define CXWnd__SetParent_x                                         0x8BA890

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B0B90
#define CXWndManager__DrawWindows_x                                0x8B07E0
#define CXWndManager__GetKeyboardFlags_x                           0x8AEE60
#define CXWndManager__HandleKeyboardMsg_x                          0x8AF790
#define CXWndManager__RemoveWnd_x                                  0x8AF480

// CDBStr
#define CDBStr__GetString_x                                        0x4A9DA0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E180
#define EQ_Character__Cur_HP_x                                     0x462D30
#define EQ_Character__Cur_Mana_x                                   0x456850
#define EQ_Character__GetAACastingTimeModifier_x                   0x4473D0
#define EQ_Character__GetCharInfo2_x                               0x85B710
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F680
#define EQ_Character__GetFocusRangeModifier_x                      0x43F6E0
#define EQ_Character__GetHPRegen_x                                 0x465EA0
#define EQ_Character__GetEnduranceRegen_x                          0x462150
#define EQ_Character__GetManaRegen_x                               0x466440
#define EQ_Character__Max_Endurance_x                              0x5B7F10
#define EQ_Character__Max_HP_x                                     0x459470
#define EQ_Character__Max_Mana_x                                   0x5B7D40
#define EQ_Character__doCombatAbility_x                            0x5B5430
#define EQ_Character__UseSkill_x                                   0x46D0D0
#define EQ_Character__GetConLevel_x                                0x5AAB90
#define EQ_Character__IsExpansionFlag_x                            0x423B30
#define EQ_Character__TotalEffect_x                                0x44B420
#define EQ_Character__GetPCSpellAffect_x                           0x4477D0
#define EQ_Character__SpellDuration_x                              0x4456D0
#define EQ_Character__FindItemByRecord_x                           0x460190

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x4429E0
#define CCharacterSelect__EnterWorld_x                             0x4421B0
#define CCharacterSelect__Quit_x                                   0x440DA0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x58B270
#define EQ_Item__CreateItemTagString_x                             0x83D380
#define EQ_Item__IsStackable_x                                     0x832DC0
#define EQ_Item__GetImageNum_x                                     0x835850
#define EQ_Item__CreateItemClient_x                                0x58BE50
#define EQ_Item__GetItemValue_x                                    0x83C0E0
#define EQ_Item__ValueSellMerchant_x                               0x83E620
#define EQ_Item__IsKeyRingItem_x                                   0x833810
#define EQ_Item__CanGoInBag_x                                      0x58B400
#define EQ_Item__GetMaxItemCount_x                                 0x832CB0
#define EQ_Item__GetHeldItem_x                                     0x834650
#define EQ_Item__GetAugmentFitBySlot_x                             0x83E450

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C9650
#define EQ_LoadingS__Array_x                                       0xBEF2A8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BA430
#define EQ_PC__GetAlternateAbilityId_x                             0x846A20
#define EQ_PC__GetCombatAbility_x                                  0x846AB0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8417D0
#define EQ_PC__GetItemRecastTimer_x                                0x5B3AF0
#define EQ_PC__HasLoreItem_x                                       0x5AE0B0
#define EQ_PC__AlertInventoryChanged_x                             0x5AAB60
#define EQ_PC__GetPcZoneClient_x                                   0x5D4190
#define EQ_PC__RemoveMyAffect_x                                    0x5B2F80
#define EQ_PC__GetKeyRingItems_x                                   0x841BF0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x514150
#define EQItemList__add_object_x                                   0x540210
#define EQItemList__add_item_x                                     0x514090
#define EQItemList__delete_item_x                                  0x514540
#define EQItemList__FreeItemList_x                                 0x514440

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A8EF0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5BFB60
#define EQPlayer__dEQPlayer_x                                      0x5C8100
#define EQPlayer__DoAttack_x                                       0x5DA080
#define EQPlayer__EQPlayer_x                                       0x5CA810
#define EQPlayer__SetNameSpriteState_x                             0x5C5070
#define EQPlayer__SetNameSpriteTint_x                              0x5C0F70
#define PlayerBase__HasProperty_j_x                                0x918510
#define EQPlayer__IsTargetable_x                                   0x918E10
#define EQPlayer__CanSee_x                                         0x919330
#define PlayerZoneClient__ChangeHeight_x                           0x5D9F40
#define EQPlayer__CanSeeTargetIndicator_x                          0x919420
#define PlayerBase__GetVisibilityLineSegment_x                     0x9190C0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5CE7E0
#define EQPlayerManager__GetSpawnByName_x                          0x5CEC40
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5CE810

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x591300
#define KeypressHandler__AttachKeyToEqCommand_x                    0x591340
#define KeypressHandler__ClearCommandStateArray_x                  0x590EF0
#define KeypressHandler__HandleKeyDown_x                           0x58F850
#define KeypressHandler__HandleKeyUp_x                             0x58FB70
#define KeypressHandler__SaveKeymapping_x                          0x590FC0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6FE160
#define MapViewMap__SaveEx_x                                       0x701490

#define PlayerPointManager__GetAltCurrency_x                       0x859870

// StringTable 
#define StringTable__getString_x                                   0x8544D0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B79A0
#define PcZoneClient__RemovePetEffect_x                            0x5B3FC0
#define PcZoneClient__HasAlternateAbility_x                        0x5B4960
#define PcZoneClient__GetCurrentMod_x                              0x458810
#define PcZoneClient__GetModCap_x                                  0x455FD0
#define PcZoneClient__CanEquipItem_x                               0x5B4F10
#define PcZoneClient__GetItemByID_x                                0x5B9910
#define PcZoneClient__GetItemByItemClass_x                         0x5BA350

//Doors
#define EQSwitch__UseSwitch_x                                      0x547B00

//IconCache
#define IconCache__GetIcon_x                                       0x69A8D0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6916A0
#define CContainerMgr__CloseContainer_x                            0x691EC0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x75ED20

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5844E0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E3420
#define EQ_Spell__SpellAffects_x                                   0x4E0AD0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4E0B40
#define CharacterZoneClient__CalcAffectChange_x                    0x446800
#define CLootWnd__LootAll_x                                        0x6F3A20
#define CLootWnd__RequestLootSlot_x                                0x6F4230

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7A5990
#define CTargetWnd__WndNotification_x                              0x7A5480
#define CTargetWnd__RefreshTargetBuffs_x                           0x7A5B70

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7AABE0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4DC190

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x498950

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8D2E60
#define CSidlManager__FindAnimation1_x                             0x8C8220

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D0DD0
#define CAltAbilityData__GetMercMaxRank_x                          0x4D0D80
#define CAltAbilityData__GetMaxRank_x                              0x4C5BD0

//CTargetRing
#define CTargetRing__Cast_x                                        0x581DD0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x454FF0
#define CharacterBase__CreateItemGlobalIndex_x                     0x471EA0
#define CharacterBase__CreateItemIndex_x                           0x50D630
#define CharacterBase__GetItemPossession_x                         0x50EAC0
#define CharacterBase__GetItemByGlobalIndex_x                      0x869860

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x67BF40
#define CCastSpellWnd__IsBardSongPlaying_x                         0x67B6A0

//messages
#define msg_spell_worn_off_x                                       0x4EB040
#define msg_new_text_x                                             0x4F45E0
#define msgTokenTextParam_x                                        0x4F0F90

//SpellManager
#define SpellManager__vftable_x                                    0xAABFF0
#define SpellManager__SpellManager_x                               0x47ACB0
#define Spellmanager__CheckSpellRequirementAssociations_x          0x5F8700

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x91CE50

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E7560
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43AE00
#define ItemGlobalIndex__IsEquippedLocation_x                      0x445060
#define ItemGlobalIndex__IsValidIndex_x                            0x454890

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x867680
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8665C0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6EC890

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6964F0
#define CCursorAttachment__Deactivate_x                            0x695A40
