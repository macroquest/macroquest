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
#define __ExpectedVersionDate                                     "Apr 11 2017"
#define __ExpectedVersionTime                                     "17:25:49"
#define __ActualVersionDate_x                                      0xACBDC8
#define __ActualVersionTime_x                                      0xACBDD4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x59C630
#define __MemChecker1_x                                            0x891A20
#define __MemChecker2_x                                            0x632760
#define __MemChecker3_x                                            0x6326B0
#define __MemChecker4_x                                            0x7E44F0
#define __EncryptPad0_x                                            0xC252A8
#define __EncryptPad1_x                                            0xCFFF38
#define __EncryptPad2_x                                            0xC4E928
#define __EncryptPad3_x                                            0xC4E528
#define __EncryptPad4_x                                            0xCEE538
#define __EncryptPad5_x                                            0x10A8B50
#define __AC1_x                                                    0x7A3915
#define __AC2_x                                                    0x5563B7
#define __AC3_x                                                    0x554550
#define __AC4_x                                                    0x566610
#define __AC5_x                                                    0x57966B
#define __AC6_x                                                    0x57D21E
#define __AC7_x                                                    0x573C6C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FE5D20

// Direct Input
#define DI8__Main_x                                                0x10A8B28
#define DI8__Keyboard_x                                            0x10A8B2C
#define DI8__Mouse_x                                               0x10A8B30
#define DI8__Mouse_Copy_x                                          0xF16EF4
#define DI8__Mouse_Check_x                                         0xFA0814
#define __Attack_x                                                 0xF9B3FB
#define __Autofire_x                                               0xF9B3FC
#define __BindList_x                                               0xC00110
#define g_eqCommandStates_x                                        0xF05F18
#define __Clicks_x                                                 0xF16FB0
#define __CommandList_x                                            0xC02770
#define __CurrentMapLabel_x                                        0x10AE5B0
#define __CurrentSocial_x                                          0xBD2348
#define __DoAbilityList_x                                          0xF4D6B0
#define __do_loot_x                                                0x525250
#define __DrawHandler_x                                            0x1715464
#define __GroupCount_x                                             0xF0754A

#define __Guilds_x                                                 0xF0D160
#define __gWorld_x                                                 0xF09A04
#define __HotkeyPage_x                                             0xF940B0
#define __HWnd_x                                                   0xFA0930
#define __InChatMode_x                                             0xF16EDC
#define __LastTell_x                                               0xF18DAC
#define __LMouseHeldTime_x                                         0xF1701C
#define __Mouse_x                                                  0x10A8B34
#define __MouseLook_x                                              0xF16F76
#define __MouseEventTime_x                                         0xF9BBFC
#define __gpbCommandEvent_x                                        0xF09ACC
#define __NetStatusToggle_x                                        0xF16F79
#define __PCNames_x                                                0xF183C4
#define __RangeAttackReady_x                                       0xF180EC
#define __RMouseHeldTime_x                                         0xF17018
#define __RunWalkState_x                                           0xF16EE0
#define __ScreenMode_x                                             0xE55C08
#define __ScreenX_x                                                0xF16E94
#define __ScreenY_x                                                0xF16E90
#define __ScreenXMax_x                                             0xF16E98
#define __ScreenYMax_x                                             0xF16E9C
#define __ServerHost_x                                             0xF07494
#define __ServerName_x                                             0xF4D670
#define __ShiftKeyDown_x                                           0xF17570
#define __ShowNames_x                                              0xF182AC
#define __Socials_x                                                0xF4D770
#define __SubscriptionType_x                                       0x10DC574
#define __TargetAggroHolder_x                                      0x10B0784
#define __ZoneType_x                                               0xF17374
#define __GroupAggro_x                                             0x10B07C4
#define __LoginName_x                                              0xF9F40C
#define __Inviter_x                                                0xF9B378
#define __AttackOnAssist_x                                         0xF18268
#define __UseTellWindows_x                                         0xF1855C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF09AF0
#define instEQZoneInfo_x                                           0xF1716C
#define instKeypressHandler_x                                      0xF9BBE0
#define pinstActiveBanker_x                                        0xF09AA8
#define pinstActiveCorpse_x                                        0xF09AAC
#define pinstActiveGMaster_x                                       0xF09AB0
#define pinstActiveMerchant_x                                      0xF09AA4
#define pinstAggroInfo_x                                           0xD135E8
#define pinstAltAdvManager_x                                       0xE56CE0
#define pinstAuraMgr_x                                             0xD23D58
#define pinstBandageTarget_x                                       0xF09A90
#define pinstCamActor_x                                            0xE56634
#define pinstCDBStr_x                                              0xE55B9C
#define pinstCDisplay_x                                            0xF09AB8
#define pinstCEverQuest_x                                          0x10A8CA8
#define pinstEverQuestInfo_x                                       0xF16E88
#define pinstCharData_x                                            0xF09A74
#define pinstCharSpawn_x                                           0xF09A9C
#define pinstControlledMissile_x                                   0xF09A70
#define pinstControlledPlayer_x                                    0xF09A9C
#define pinstCSidlManager_x                                        0x1714854
#define pinstCXWndManager_x                                        0x171484C
#define instDynamicZone_x                                          0xF16D28
#define pinstDZMember_x                                            0xF16E38
#define pinstDZTimerInfo_x                                         0xF16E3C
#define pinstEQItemList_x                                          0xF0616C
#define pinstEQObjectList_x                                        0xF06F44
#define instEQMisc_x                                               0xBE8808
#define pinstEQSoundManager_x                                      0xE572B0
#define instExpeditionLeader_x                                     0xF16D72
#define instExpeditionName_x                                       0xF16DB2
#define pinstGroup_x                                               0xF07546
#define pinstImeManager_x                                          0x1714858
#define pinstLocalPlayer_x                                         0xF09A88
#define pinstMercenaryData_x                                       0xF9C260
#define pinstMercenaryStats_x                                      0x10B08D0
#define pinstMercAltAbilities_x                                    0xE57068
#define pinstModelPlayer_x                                         0xF09AB4
#define pinstPCData_x                                              0xF09A74
#define pinstSkillMgr_x                                            0xF9D0C8
#define pinstSpawnManager_x                                        0xF9C9B0
#define pinstSpellManager_x                                        0xF9D210
#define pinstSpellSets_x                                           0xF94114
#define pinstStringTable_x                                         0xF09A1C
#define pinstSwitchManager_x                                       0xF070D8
#define pinstTarget_x                                              0xF09AA0
#define pinstTargetObject_x                                        0xF09A78
#define pinstTargetSwitch_x                                        0xF09A7C
#define pinstTaskMember_x                                          0xE55AE8
#define pinstTrackTarget_x                                         0xF09A94
#define pinstTradeTarget_x                                         0xF09A84
#define instTributeActive_x                                        0xBE882D
#define pinstViewActor_x                                           0xE56630
#define pinstWorldData_x                                           0xF09A58
#define pinstZoneAddr_x                                            0xF1740C
#define pinstPlayerPath_x                                          0xF9CA10
#define pinstTargetIndicator_x                                     0xF9D3A8
#define pinstCTargetManager_x                                      0xF9D408
#define EQObject_Top_x                                             0xF09A68
#define pinstRealEstateItems_x                                     0xF9CFB4

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE56550
#define pinstCAchievementsWnd_x                                    0xE565AC
#define pinstCTextOverlay_x                                        0xD13AE0
#define pinstCAudioTriggersWindow_x                                0xD13970
#define pinstCCharacterSelect_x                                    0xE564C0
#define pinstCFacePick_x                                           0xE56470
#define pinstCNoteWnd_x                                            0xE56478
#define pinstCBookWnd_x                                            0xE56480
#define pinstCPetInfoWnd_x                                         0xE56484
#define pinstCTrainWnd_x                                           0xE56488
#define pinstCSkillsWnd_x                                          0xE5648C
#define pinstCSkillsSelectWnd_x                                    0xE56490
#define pinstCCombatSkillsSelectWnd_x                              0xE56494
#define pinstCFriendsWnd_x                                         0xE56498
#define pinstCAuraWnd_x                                            0xE5649C
#define pinstCRespawnWnd_x                                         0xE564A0
#define pinstCBandolierWnd_x                                       0xE564A4
#define pinstCPotionBeltWnd_x                                      0xE564A8
#define pinstCAAWnd_x                                              0xE564AC
#define pinstCGroupSearchFiltersWnd_x                              0xE564B0
#define pinstCLoadskinWnd_x                                        0xE564B4
#define pinstCAlarmWnd_x                                           0xE564B8
#define pinstCMusicPlayerWnd_x                                     0xE564BC
#define pinstCMailWnd_x                                            0xE564C4
#define pinstCMailCompositionWnd_x                                 0xE564C8
#define pinstCMailAddressBookWnd_x                                 0xE564CC
#define pinstCRaidWnd_x                                            0xE564D4
#define pinstCRaidOptionsWnd_x                                     0xE564D8
#define pinstCBreathWnd_x                                          0xE564DC
#define pinstCMapViewWnd_x                                         0xE564E0
#define pinstCMapToolbarWnd_x                                      0xE564E4
#define pinstCEditLabelWnd_x                                       0xE564E8
#define pinstCTargetWnd_x                                          0xE564EC
#define pinstCColorPickerWnd_x                                     0xE564F0
#define pinstCPlayerWnd_x                                          0xE564F4
#define pinstCOptionsWnd_x                                         0xE564F8
#define pinstCBuffWindowNORMAL_x                                   0xE564FC
#define pinstCBuffWindowSHORT_x                                    0xE56500
#define pinstCharacterCreation_x                                   0xE56504
#define pinstCCursorAttachment_x                                   0xE56508
#define pinstCCastingWnd_x                                         0xE5650C
#define pinstCCastSpellWnd_x                                       0xE56510
#define pinstCSpellBookWnd_x                                       0xE56514
#define pinstCInventoryWnd_x                                       0xE56518
#define pinstCBankWnd_x                                            0xE56520
#define pinstCQuantityWnd_x                                        0xE56524
#define pinstCLootWnd_x                                            0xE56528
#define pinstCActionsWnd_x                                         0xE5652C
#define pinstCCombatAbilityWnd_x                                   0xE56534
#define pinstCMerchantWnd_x                                        0xE56538
#define pinstCTradeWnd_x                                           0xE56540
#define pinstCSelectorWnd_x                                        0xE56544
#define pinstCBazaarWnd_x                                          0xE56548
#define pinstCBazaarSearchWnd_x                                    0xE5654C
#define pinstCGiveWnd_x                                            0xE56568
#define pinstCTrackingWnd_x                                        0xE56570
#define pinstCInspectWnd_x                                         0xE56574
#define pinstCSocialEditWnd_x                                      0xE56578
#define pinstCFeedbackWnd_x                                        0xE5657C
#define pinstCBugReportWnd_x                                       0xE56580
#define pinstCVideoModesWnd_x                                      0xE56584
#define pinstCTextEntryWnd_x                                       0xE5658C
#define pinstCFileSelectionWnd_x                                   0xE56590
#define pinstCCompassWnd_x                                         0xE56594
#define pinstCPlayerNotesWnd_x                                     0xE56598
#define pinstCGemsGameWnd_x                                        0xE5659C
#define pinstCTimeLeftWnd_x                                        0xE565A0
#define pinstCPetitionQWnd_x                                       0xE565BC
#define pinstCStoryWnd_x                                           0xE565C0
#define pinstCJournalTextWnd_x                                     0xE565C4
#define pinstCJournalCatWnd_x                                      0xE565C8
#define pinstCBodyTintWnd_x                                        0xE565CC
#define pinstCServerListWnd_x                                      0xE565D0
#define pinstCAvaZoneWnd_x                                         0xE565DC
#define pinstCBlockedBuffWnd_x                                     0xE565E0
#define pinstCBlockedPetBuffWnd_x                                  0xE565E4
#define pinstCInvSlotMgr_x                                         0xE56628
#define pinstCContainerMgr_x                                       0xE5662C
#define pinstCAdventureLeaderboardWnd_x                            0x10A9658
#define pinstCAdventureRequestWnd_x                                0x10A96D0
#define pinstCAltStorageWnd_x                                      0x10A99B0
#define pinstCAdventureStatsWnd_x                                  0x10A9748
#define pinstCBarterMerchantWnd_x                                  0x10AA598
#define pinstCBarterSearchWnd_x                                    0x10AA610
#define pinstCBarterWnd_x                                          0x10AA688
#define pinstCChatWindowManager_x                                  0x10AAD18
#define pinstCDynamicZoneWnd_x                                     0x10AB1C8
#define pinstCEQMainWnd_x                                          0x10AB360
#define pinstCFellowshipWnd_x                                      0x10AB15C
#define pinstCFindLocationWnd_x                                    0x10AB630
#define pinstCGroupSearchWnd_x                                     0x10AB900
#define pinstCGroupWnd_x                                           0x10AB978
#define pinstCGuildBankWnd_x                                       0x10AB9F0
#define pinstCGuildMgmtWnd_x                                       0x10ADAE0
#define pinstCHotButtonWnd_x                                       0x10ADBDC
#define pinstCHotButtonWnd1_x                                      0x10ADBDC
#define pinstCHotButtonWnd2_x                                      0x10ADBE0
#define pinstCHotButtonWnd3_x                                      0x10ADBE4
#define pinstCHotButtonWnd4_x                                      0x10ADC08
#define pinstCItemDisplayManager_x                                 0x10ADF00
#define pinstCItemExpTransferWnd_x                                 0x10ADF7C
#define pinstCLFGuildWnd_x                                         0x10AE258
#define pinstCMIZoneSelectWnd_x                                    0x10AE840
#define pinstCConfirmationDialog_x                                 0x10AEF48
#define pinstCPopupWndManager_x                                    0x10AEF48
#define pinstCProgressionSelectionWnd_x                            0x10AF038
#define pinstCPvPStatsWnd_x                                        0x10AF128
#define pinstCLargeDialogWnd_x                                     0x10AF830
#define pinstCTaskWnd_x                                            0x10B0BB0
#define pinstCTaskSomething_x                                      0xD24690
#define pinstCTaskTemplateSelectWnd_x                              0x10B0B38
#define pinstCTipWndOFDAY_x                                        0x10B0D18
#define pinstCTipWndCONTEXT_x                                      0x10B0D1C
#define pinstCTitleWnd_x                                           0x10B0D98
#define pinstCContextMenuManager_x                                 0x17147C4
#define pinstCVoiceMacroWnd_x                                      0xF9D7E0
#define pinstCHtmlWnd_x                                            0xF9D8D0
#define pinstIconCache_x                                           0x10AB334
#define pinstCTradeskillWnd_x                                      0x10B0E98
#define pinstCAdvancedLootWnd_x                                    0xE5661C
#define pinstRewardSelectionWnd_x                                  0x10AF650

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x53C390
#define __ConvertItemTags_x                                        0x529D50
#define __ExecuteCmd_x                                             0x5148B0
#define __EQGetTime_x                                              0x8916B0
#define __get_melee_range_x                                        0x51B520
#define __GetGaugeValueFromEQ_x                                    0x7A24D0
#define __GetLabelFromEQ_x                                         0x7A38A0
#define __ToggleKeyRingItem_x                                      0x484150
#define __GetXTargetType_x                                         0x922120
#define __LoadFrontEnd_x                                           0x631E30
#define __NewUIINI_x                                               0x7A1EA0
#define __ProcessGameEvents_x                                      0x575A00
#define __ProcessMouseEvent_x                                      0x5751A0
#define CrashDetected_x                                            0x6337F0
#define wwsCrashReportCheckForUploader_x                           0x7F0420
#define __AppCrashWrapper_x                                        0xC4E51C
#define __pCrashHandler_x                                          0x10BDD48
#define __CrashHandler_x                                           0x7EFE80
#define wwsCrashReportPlatformLaunchUploader_x                     0x7F2620
#define DrawNetStatus_x                                            0x5AC2A0
#define Util__FastTime_x                                           0x891350
#define Expansion_HoT_x                                            0xF18258
#define __HelpPath_x                                               0xF9B968
#define __STMLToText_x                                             0x8D7420

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x422F20
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DCC0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DAA0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4CBBD0
#define AltAdvManager__IsAbilityReady_x                            0x4CBC40
#define AltAdvManager__GetAAById_x                                 0x4CC130
#define AltAdvManager__CanTrainAbility_x                           0x4CCD60
#define AltAdvManager__CanSeeAbility_x                             0x4CC920

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x465CE0
#define CharacterZoneClient__MakeMeVisible_x                       0x46A3C0
#define CharacterZoneClient__IsStackBlocked_x                      0x44A360
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x449820
#define CharacterZoneClient__GetItemCountWorn_x                    0x463C60
#define CharacterZoneClient__GetItemCountInInventory_x             0x463D40
#define CharacterZoneClient__GetCursorItemCount_x                  0x463E20
#define CharacterZoneClient__FindAffectSlot_x                      0x44F890

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6617A0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66FB60

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58B340
#define CButtonWnd__CButtonWnd_x                                   0x8CB790

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68AAE0
#define CChatManager__InitContextMenu_x                            0x68BC30
#define CChatManager__FreeChatWindow_x                             0x68A570
#define CChatManager__GetLockedActiveChatWindow_x                  0x6934B0
#define CChatManager__SetLockedActiveChatWindow_x                  0x68AAB0
// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D5780
#define CContextMenu__dCContextMenu_x                              0x8D5990
#define CContextMenu__AddMenuItem_x                                0x8D59A0
#define CContextMenu__RemoveMenuItem_x                             0x8D5C90
#define CContextMenu__RemoveAllMenuItems_x                         0x8D5CB0
#define CContextMenuManager__AddMenu_x                             0x8C1CE0
#define CContextMenuManager__RemoveMenu_x                          0x8C2090
#define CContextMenuManager__PopupMenu_x                           0x8C24E0
#define CContextMenuManager__Flush_x                               0x8C1D50
#define CContextMenuManager__GetMenu_x                             0x4193A0
#define CContextMenu__CheckMenuItem_x                              0x8D5D30

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x875AD0
#define CChatService__GetFriendName_x                              0x875AE0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x691820
#define CChatWindow__Clear_x                                       0x691110
#define CChatWindow__WndNotification_x                             0x691D60

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C5B40
#define CComboWnd__Draw_x                                          0x8C5D50
#define CComboWnd__GetCurChoice_x                                  0x8C58F0
#define CComboWnd__GetListRect_x                                   0x8C5FF0
#define CComboWnd__GetTextRect_x                                   0x8C5BB0
#define CComboWnd__InsertChoice_x                                  0x8C6060
#define CComboWnd__SetColors_x                                     0x8C5880
#define CComboWnd__SetChoice_x                                     0x8C58B0
#define CComboWnd__GetItemCount_x                                  0x8C58E0
#define CComboWnd__GetCurChoiceText_x                              0x8C5930

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69B170
#define CContainerWnd__vftable_x                                   0xAD59B0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4BA020
#define CDisplay__GetClickedActor_x                                0x4B2950
#define CDisplay__GetUserDefinedColor_x                            0x4B1530
#define CDisplay__GetWorldFilePath_x                               0x4B0980
#define CDisplay__is3dON_x                                         0x4AFE10
#define CDisplay__ReloadUI_x                                       0x4C55A0
#define CDisplay__WriteTextHD2_x                                   0x4B63E0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8EBEB0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D9CD0
#define CEditWnd__GetCharIndexPt_x                                 0x8DAD60
#define CEditWnd__GetDisplayString_x                               0x8D9E80
#define CEditWnd__GetHorzOffset_x                                  0x8DA1C0
#define CEditWnd__GetLineForPrintableChar_x                        0x8DA830
#define CEditWnd__GetSelStartPt_x                                  0x8DB010
#define CEditWnd__GetSTMLSafeText_x                                0x8DA360
#define CEditWnd__PointFromPrintableChar_x                         0x8DA920
#define CEditWnd__SelectableCharFromPoint_x                        0x8DAAA0
#define CEditWnd__SetEditable_x                                    0x8DA330

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x55CE40
#define CEverQuest__ClickedPlayer_x                                0x556B00
#define CEverQuest__CreateTargetIndicator_x                        0x5579F0
#define CEverQuest__DeleteTargetIndicator_x                        0x557A70
#define CEverQuest__DoTellWindow_x                                 0x474F30
#define CEverQuest__OutputTextToLog_x                              0x474B90
#define CEverQuest__DropHeldItemOnGround_x                         0x56D850
#define CEverQuest__dsp_chat_x                                     0x475270
#define CEverQuest__trimName_x                                     0x553450
#define CEverQuest__Emote_x                                        0x56B630
#define CEverQuest__EnterZone_x                                    0x5667A0
#define CEverQuest__GetBodyTypeDesc_x                              0x550EB0
#define CEverQuest__GetClassDesc_x                                 0x55A280
#define CEverQuest__GetClassThreeLetterCode_x                      0x55A880
#define CEverQuest__GetDeityDesc_x                                 0x551790
#define CEverQuest__GetLangDesc_x                                  0x551240
#define CEverQuest__GetRaceDesc_x                                  0x55AA40
#define CEverQuest__InterpretCmd_x                                 0x55E5C0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5720C0
#define CEverQuest__LMouseUp_x                                     0x5741C0
#define CEverQuest__RightClickedOnPlayer_x                         0x572BD0
#define CEverQuest__RMouseUp_x                                     0x573C20
#define CEverQuest__SetGameState_x                                 0x5573C0
#define CEverQuest__UPCNotificationFlush_x                         0x54ECC0
#define CEverQuest__IssuePetCommand_x                              0x55EFA0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6ABE50
#define CGaugeWnd__CalcLinesFillRect_x                             0x6ABEB0
#define CGaugeWnd__Draw_x                                          0x6AC2E0

// CGuild
#define CGuild__FindMemberByName_x                                 0x439BE0
#define CGuild__GetGuildName_x                                     0x43A0B0
#define CGuild__GetGuildIndex_x                                    0x43B280

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C83E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D5590
#define CInvSlotMgr__MoveItem_x                                    0x6D6440
#define CInvSlotMgr__SelectSlot_x                                  0x6D5640

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D4A40
#define CInvSlot__SliderComplete_x                                 0x6D2250
#define CInvSlot__GetItemBase_x                                    0x6D16F0
#define CInvSlot__UpdateItem_x                                     0x6D1C70

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D7870
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6D8990

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79DEA0
#define CItemDisplayWnd__UpdateStrings_x                           0x6D99E0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6E6490
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6E69A0
#define CItemDisplayWnd__SetItem_x                                 0x6EC440

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7D5460

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6DFF90

// CLabel 
#define CLabel__Draw_x                                             0x6F30C0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B1850
#define CListWnd__dCListWnd_x                                      0x8B2A70
#define CListWnd__AddColumn_x                                      0x8B2A10
#define CListWnd__AddColumn1_x                                     0x8B20B0
#define CListWnd__AddLine_x                                        0x8B1B10
#define CListWnd__AddString_x                                      0x8B1D30
#define CListWnd__CalculateFirstVisibleLine_x                      0x8AEAE0
#define CListWnd__CalculateVSBRange_x                              0x8B0D20
#define CListWnd__ClearSel_x                                       0x8ADE00
#define CListWnd__ClearAllSel_x                                    0x8ADDB0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B16E0
#define CListWnd__Compare_x                                        0x8AF660
#define CListWnd__Draw_x                                           0x8B0920
#define CListWnd__DrawColumnSeparators_x                           0x8B07B0
#define CListWnd__DrawHeader_x                                     0x8AE0C0
#define CListWnd__DrawItem_x                                       0x8AFCE0
#define CListWnd__DrawLine_x                                       0x8B0450
#define CListWnd__DrawSeparator_x                                  0x8B0850
#define CListWnd__EnableLine_x                                     0x8ADFE0
#define CListWnd__EnsureVisible_x                                  0x8AEC40
#define CListWnd__ExtendSel_x                                      0x8AFBF0
#define CListWnd__GetColumnMinWidth_x                              0x8AD7B0
#define CListWnd__GetColumnWidth_x                                 0x8AD6E0
#define CListWnd__GetCurSel_x                                      0x8ACED0
#define CListWnd__GetItemAtPoint_x                                 0x8AEEE0
#define CListWnd__GetItemAtPoint1_x                                0x8AEF50
#define CListWnd__GetItemData_x                                    0x8AD200
#define CListWnd__GetItemHeight_x                                  0x8AE740
#define CListWnd__GetItemIcon_x                                    0x8AD3F0
#define CListWnd__GetItemRect_x                                    0x8AED20
#define CListWnd__GetItemText_x                                    0x8AD2A0
#define CListWnd__GetSelList_x                                     0x8B1FA0
#define CListWnd__GetSeparatorRect_x                               0x8AF580
#define CListWnd__InsertLine_x                                     0x8B1F10
#define CListWnd__RemoveLine_x                                     0x8B1F20
#define CListWnd__SetColors_x                                      0x8AD020
#define CListWnd__SetColumnJustification_x                         0x8ADA40
#define CListWnd__SetColumnWidth_x                                 0x8AD760
#define CListWnd__SetCurSel_x                                      0x8ACF10
#define CListWnd__SetItemColor_x                                   0x8B13D0
#define CListWnd__SetItemData_x                                    0x8ADE60
#define CListWnd__SetItemText_x                                    0x8B1210
#define CListWnd__ShiftColumnSeparator_x                           0x8B10A0
#define CListWnd__Sort_x                                           0x8B2B70
#define CListWnd__ToggleSel_x                                      0x8ADD30

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70C010

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72D550
#define CMerchantWnd__RequestBuyItem_x                             0x734600
#define CMerchantWnd__RequestSellItem_x                            0x7350D0
#define CMerchantWnd__SelectRecoverySlot_x                         0x72D800
#define CMerchantWnd__SelectBuySellSlot_x                          0x72CA00
#define CMerchantWnd__ActualSelect_x                               0x7314D0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x844070
#define CPacketScrambler__hton_x                                   0x844080

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8D06A0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D0780
#define CSidlManager__CreateLabel_x                                0x7957D0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8CEC40
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8D0A60

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x658B7F
#define CSidlScreenWnd__CalculateVSBRange_x                        0x658AB0
#define CSidlScreenWnd__ConvertToRes_x                             0x8EBD90
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8C8500
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C96D0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C9780
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C8C50
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8C7EB0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8C7620
#define CSidlScreenWnd__GetSidlPiece_x                             0x8C80A0
#define CSidlScreenWnd__Init1_x                                    0x8C93A0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C85B0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8C77E0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C8E90
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C7270
#define CSidlScreenWnd__StoreIniVis_x                              0x8C75D0
#define CSidlScreenWnd__WndNotification_x                          0x8C9120
#define CSidlScreenWnd__GetChildItem_x                             0x8C76F0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BAF40
#define CSidlScreenWnd__m_layoutCopy_x                             0x1714828

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F76D0
#define CSkillMgr__GetSkillCap_x                                   0x5F78B0
#define CSkillMgr__GetNameToken_x                                  0x5F72F0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8EB030
#define CSliderWnd__SetValue_x                                     0x8EB200
#define CSliderWnd__SetNumTicks_x                                  0x8EB980

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79BB00

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8E69D0
#define CStmlWnd__CalculateHSBRange_x                              0x8DEF90
#define CStmlWnd__CalculateVSBRange_x                              0x8DEF00
#define CStmlWnd__CanBreakAtCharacter_x                            0x8DF110
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8DF9F0
#define CStmlWnd__ForceParseNow_x                                  0x8E7320
#define CStmlWnd__GetNextTagPiece_x                                0x8DF8F0
#define CStmlWnd__GetSTMLText_x                                    0x693470
#define CStmlWnd__GetVisibleText_x                                 0x8E0440
#define CStmlWnd__InitializeWindowVariables_x                      0x8E27D0
#define CStmlWnd__MakeStmlColorTag_x                               0x8DE200
#define CStmlWnd__MakeWndNotificationTag_x                         0x8DE260
#define CStmlWnd__SetSTMLText_x                                    0x8E4020
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E6670
#define CStmlWnd__UpdateHistoryString_x                            0x8E1380

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8DD890
#define CTabWnd__DrawCurrentPage_x                                 0x8DD120
#define CTabWnd__DrawTab_x                                         0x8DCEE0
#define CTabWnd__GetCurrentPage_x                                  0x8DD4D0
#define CTabWnd__GetPageInnerRect_x                                0x8DCBD0
#define CTabWnd__GetTabInnerRect_x                                 0x8DCDD0
#define CTabWnd__GetTabRect_x                                      0x8DCCA0
#define CTabWnd__InsertPage_x                                      0x8DDB80
#define CTabWnd__SetPage_x                                         0x8DD500
#define CTabWnd__SetPageRect_x                                     0x8DD7D0
#define CTabWnd__UpdatePage_x                                      0x8DDB20
#define CTabWnd__GetPageFromTabIndex_x                             0x8DCE30
#define CTabWnd__GetCurrentTabIndex_x                              0x8DCB60

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6D8B40
#define CPageWnd__SetTabText_x                                     0x8F4D50

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x435760

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C54F0
#define CTextureFont__GetTextExtent_x                              0x8C5250

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6300C0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F1190

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8AB170

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x598B20
#define CXStr__CXStr1_x                                            0x8AC0F0
#define CXStr__CXStr3_x                                            0x88E5F0
#define CXStr__dCXStr_x                                            0x8E7DE0
#define CXStr__operator_equal_x                                    0x88E760
#define CXStr__operator_equal1_x                                   0x88E7B0
#define CXStr__operator_plus_equal1_x                              0x88F8B0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BA140
#define CXWnd__Center_x                                            0x8C02E0
#define CXWnd__ClrFocus_x                                          0x8B9D10
#define CXWnd__Destroy_x                                           0x8C0DB0
#define CXWnd__DoAllDrawing_x                                      0x8BFF30
#define CXWnd__DrawChildren_x                                      0x8C00D0
#define CXWnd__DrawColoredRect_x                                   0x8BA510
#define CXWnd__DrawTooltip_x                                       0x8BA7C0
#define CXWnd__DrawTooltipAtPoint_x                                0x8BEE80
#define CXWnd__GetBorderFrame_x                                    0x8BAC10
#define CXWnd__GetChildWndAt_x                                     0x8C0C90
#define CXWnd__GetClientClipRect_x                                 0x8BA9D0
#define CXWnd__GetScreenClipRect_x                                 0x8BF580
#define CXWnd__GetScreenRect_x                                     0x8BADD0
#define CXWnd__GetTooltipRect_x                                    0x8BA650
#define CXWnd__GetWindowTextA_x                                    0x426F70
#define CXWnd__IsActive_x                                          0x8B5850
#define CXWnd__IsDescendantOf_x                                    0x8BAB60
#define CXWnd__IsReallyVisible_x                                   0x8BDEE0
#define CXWnd__IsType_x                                            0x8ED9D0
#define CXWnd__Move_x                                              0x8BD5C0
#define CXWnd__Move1_x                                             0x8BFBD0
#define CXWnd__ProcessTransition_x                                 0x8BA0E0
#define CXWnd__Refade_x                                            0x8B9EB0
#define CXWnd__Resize_x                                            0x8BAEA0
#define CXWnd__Right_x                                             0x8BF380
#define CXWnd__SetFocus_x                                          0x8BC710
#define CXWnd__SetFont_x                                           0x8B9D60
#define CXWnd__SetKeyTooltip_x                                     0x8BB110
#define CXWnd__SetMouseOver_x                                      0x8BF8B0
#define CXWnd__StartFade_x                                         0x8BA190
#define CXWnd__GetChildItem_x                                      0x8BF7F0
#define CXWnd__SetParent_x                                         0x8C0C40

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B70E0
#define CXWndManager__DrawWindows_x                                0x8B6D30
#define CXWndManager__GetKeyboardFlags_x                           0x8B5380
#define CXWndManager__HandleKeyboardMsg_x                          0x8B5CE0
#define CXWndManager__RemoveWnd_x                                  0x8B59E0

// CDBStr
#define CDBStr__GetString_x                                        0x4AE3C0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4508C0
#define EQ_Character__Cur_HP_x                                     0x4652E0
#define EQ_Character__Cur_Mana_x                                   0x459090
#define EQ_Character__GetAACastingTimeModifier_x                   0x449B30
#define EQ_Character__GetFocusCastingTimeModifier_x                0x441E00
#define EQ_Character__GetFocusRangeModifier_x                      0x441E60
#define EQ_Character__GetHPRegen_x                                 0x4684C0
#define EQ_Character__GetEnduranceRegen_x                          0x4648F0
#define EQ_Character__GetManaRegen_x                               0x468A60
#define EQ_Character__Max_Endurance_x                              0x5BE050
#define EQ_Character__Max_HP_x                                     0x45BC00
#define EQ_Character__Max_Mana_x                                   0x5BDE80
#define EQ_Character__doCombatAbility_x                            0x5BB560
#define EQ_Character__UseSkill_x                                   0x46F440
#define EQ_Character__GetConLevel_x                                0x5B08B0
#define EQ_Character__IsExpansionFlag_x                            0x4264B0
#define EQ_Character__TotalEffect_x                                0x44DBC0
#define EQ_Character__GetPCSpellAffect_x                           0x449F30
#define EQ_Character__SpellDuration_x                              0x447ED0
#define EQ_Character__FindItemByRecord_x                           0x462930
#define EQ_Character__GetAdjustedSkill_x                           0x465A90
#define EQ_Character__GetBaseSkill_x                               0x45BAE0

//ProfileManager_
#define ProfileManager__GetCurrentProfile_x                        0x861510

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5C6010

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x4451D0
#define CCharacterSelect__EnterWorld_x                             0x4449A0
#define CCharacterSelect__Quit_x                                   0x443580

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x590DC0
#define EQ_Item__CreateItemTagString_x                             0x842A60
#define EQ_Item__IsStackable_x                                     0x838490
#define EQ_Item__GetImageNum_x                                     0x83AED0
#define EQ_Item__CreateItemClient_x                                0x5919C0
#define EQ_Item__GetItemValue_x                                    0x841740
#define EQ_Item__ValueSellMerchant_x                               0x843D00
#define EQ_Item__IsKeyRingItem_x                                   0x838EE0
#define EQ_Item__CanGoInBag_x                                      0x590F50
#define EQ_Item__GetMaxItemCount_x                                 0x838380
#define EQ_Item__GetHeldItem_x                                     0x839CE0
#define EQ_Item__GetAugmentFitBySlot_x                             0x843B30

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4CE1B0
#define EQ_LoadingS__Array_x                                       0xBF0BB8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C04E0
#define EQ_PC__GetAlternateAbilityId_x                             0x84C080
#define EQ_PC__GetCombatAbility_x                                  0x84C110
#define EQ_PC__GetCombatAbilityTimer_x                             0x846D20
#define EQ_PC__GetItemRecastTimer_x                                0x5B9C10
#define EQ_PC__HasLoreItem_x                                       0x5B3EA0
#define EQ_PC__AlertInventoryChanged_x                             0x5B0880
#define EQ_PC__GetPcZoneClient_x                                   0x5DA4B0
#define EQ_PC__RemoveMyAffect_x                                    0x5B90E0
#define EQ_PC__GetKeyRingItems_x                                   0x847140
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x859D90
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x84E000

// EQItemList 
#define EQItemList__EQItemList_x                                   0x519580
#define EQItemList__add_object_x                                   0x545D20
#define EQItemList__add_item_x                                     0x5194C0
#define EQItemList__delete_item_x                                  0x519970
#define EQItemList__FreeItemList_x                                 0x519870

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4AD6B0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C5DB0
#define EQPlayer__dEQPlayer_x                                      0x5CE340
#define EQPlayer__DoAttack_x                                       0x5E01A0
#define EQPlayer__EQPlayer_x                                       0x5D0A50
#define EQPlayer__SetNameSpriteState_x                             0x5CB290
#define EQPlayer__SetNameSpriteTint_x                              0x5C71C0
#define PlayerBase__HasProperty_j_x                                0x91E8E0
#define EQPlayer__IsTargetable_x                                   0x91EB80
#define EQPlayer__CanSee_x                                         0x91F0E0
#define PlayerZoneClient__ChangeHeight_x                           0x5E0060
#define EQPlayer__CanSeeTargetIndicator_x                          0x91F1D0
#define PlayerBase__GetVisibilityLineSegment_x                     0x91EE70

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D4B00
#define EQPlayerManager__GetSpawnByName_x                          0x5D4F60
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D4B30

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x596EC0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x596F00
#define KeypressHandler__ClearCommandStateArray_x                  0x596AB0
#define KeypressHandler__HandleKeyDown_x                           0x595410
#define KeypressHandler__HandleKeyUp_x                             0x595730
#define KeypressHandler__SaveKeymapping_x                          0x596B80

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7049A0
#define MapViewMap__SaveEx_x                                       0x707CD0

#define PlayerPointManager__GetAltCurrency_x                       0x85F600

// StringTable 
#define StringTable__getString_x                                   0x85A0C0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BDAE0
#define PcZoneClient__RemovePetEffect_x                            0x5BA0E0
#define PcZoneClient__HasAlternateAbility_x                        0x5BAA80
#define PcZoneClient__GetCurrentMod_x                              0x45B0B0
#define PcZoneClient__GetModCap_x                                  0x4587F0
#define PcZoneClient__CanEquipItem_x                               0x5BB030
#define PcZoneClient__GetItemByID_x                                0x5BF8D0
#define PcZoneClient__GetItemByItemClass_x                         0x5C0400

//Doors
#define EQSwitch__UseSwitch_x                                      0x54D610

//IconCache
#define IconCache__GetIcon_x                                       0x6A1630

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6984F0
#define CContainerMgr__CloseContainer_x                            0x698D10

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x765740

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x589D60

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E8390
#define EQ_Spell__SpellAffects_x                                   0x4E5A40
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4E5AB0
#define CharacterZoneClient__CalcAffectChange_x                    0x449000
#define CLootWnd__LootAll_x                                        0x6FA340
#define CLootWnd__RequestLootSlot_x                                0x6FAB50

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AADF0
#define CTargetWnd__WndNotification_x                              0x7AA8E0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7AAFD0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7AFEE0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4E1070

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x49CA10

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8D9300
#define CSidlManager__FindAnimation1_x                             0x8CE670

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D59B0
#define CAltAbilityData__GetMercMaxRank_x                          0x4D5960
#define CAltAbilityData__GetMaxRank_x                              0x4CA280

//CTargetRing
#define CTargetRing__Cast_x                                        0x587640

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x457720
#define CharacterBase__CreateItemGlobalIndex_x                     0x474100
#define CharacterBase__CreateItemIndex_x                           0x512B50
#define CharacterBase__GetItemPossession_x                         0x442A80
#define CharacterBase__GetItemByGlobalIndex_x                      0x86F6E0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x681CC0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x681420

//messages
#define msg_spell_worn_off_x                                       0x4EFDB0
#define msg_new_text_x                                             0x4F9370
#define msgTokenTextParam_x                                        0x4F5BD0

//SpellManager
#define SpellManager__vftable_x                                    0xAB20F0
#define SpellManager__SpellManager_x                               0x47D0D0
#define Spellmanager__CheckSpellRequirementAssociations_x          0x5FE5F0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x922C40

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4EC510
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43D590
#define ItemGlobalIndex__IsEquippedLocation_x                      0x447830
#define ItemGlobalIndex__IsValidIndex_x                            0x456FD0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x86D550
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x86C490

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F3310

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x69D220
#define CCursorAttachment__Deactivate_x                            0x69C760
