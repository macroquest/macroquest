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
#define __ExpectedVersionDate                                     "Apr 17 2017"
#define __ExpectedVersionTime                                     "15:23:53"
#define __ActualVersionDate_x                                      0xACCE18
#define __ActualVersionTime_x                                      0xACCE24

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x59D8A0
#define __MemChecker1_x                                            0x892CF0
#define __MemChecker2_x                                            0x6339D0
#define __MemChecker3_x                                            0x633920
#define __MemChecker4_x                                            0x7E5A10
#define __EncryptPad0_x                                            0xC262A8
#define __EncryptPad1_x                                            0xD00F38
#define __EncryptPad2_x                                            0xC4F928
#define __EncryptPad3_x                                            0xC4F528
#define __EncryptPad4_x                                            0xCEF538
#define __EncryptPad5_x                                            0x10A9B50
#define __AC1_x                                                    0x7A4F95
#define __AC2_x                                                    0x557677
#define __AC3_x                                                    0x555810
#define __AC4_x                                                    0x5678D0
#define __AC5_x                                                    0x57A93B
#define __AC6_x                                                    0x57E4EE
#define __AC7_x                                                    0x574F3C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FE7D20

// Direct Input
#define DI8__Main_x                                                0x10A9B28
#define DI8__Keyboard_x                                            0x10A9B2C
#define DI8__Mouse_x                                               0x10A9B30
#define DI8__Mouse_Copy_x                                          0xF17EF4
#define DI8__Mouse_Check_x                                         0xFA1814
#define __AutoSkillArray_x                                         0xF18E08
#define __Attack_x                                                 0xF9C3FB
#define __Autofire_x                                               0xF9C3FC
#define __BindList_x                                               0xC01110
#define g_eqCommandStates_x                                        0xF06F18
#define __Clicks_x                                                 0xF17FB0
#define __CommandList_x                                            0xC03770
#define __CurrentMapLabel_x                                        0x10AF5B0
#define __CurrentSocial_x                                          0xBD3348
#define __DoAbilityList_x                                          0xF4E6B0
#define __do_loot_x                                                0x5264C0
#define __DrawHandler_x                                            0x1716464
#define __GroupCount_x                                             0xF0854A

#define __Guilds_x                                                 0xF0E160
#define __gWorld_x                                                 0xF0AA04
#define __HotkeyPage_x                                             0xF950B0
#define __HWnd_x                                                   0xFA1930
#define __InChatMode_x                                             0xF17EDC
#define __LastTell_x                                               0xF19DAC
#define __LMouseHeldTime_x                                         0xF1801C
#define __Mouse_x                                                  0x10A9B34
#define __MouseLook_x                                              0xF17F76
#define __MouseEventTime_x                                         0xF9CBFC
#define __gpbCommandEvent_x                                        0xF0AACC
#define __NetStatusToggle_x                                        0xF17F79
#define __PCNames_x                                                0xF193C4
#define __RangeAttackReady_x                                       0xF190EC
#define __RMouseHeldTime_x                                         0xF18018
#define __RunWalkState_x                                           0xF17EE0
#define __ScreenMode_x                                             0xE56C08
#define __ScreenX_x                                                0xF17E94
#define __ScreenY_x                                                0xF17E90
#define __ScreenXMax_x                                             0xF17E98
#define __ScreenYMax_x                                             0xF17E9C
#define __ServerHost_x                                             0xF08494
#define __ServerName_x                                             0xF4E670
#define __ShiftKeyDown_x                                           0xF18570
#define __ShowNames_x                                              0xF192AC
#define __Socials_x                                                0xF4E770
#define __SubscriptionType_x                                       0x10DD574
#define __TargetAggroHolder_x                                      0x10B1784
#define __ZoneType_x                                               0xF18374
#define __GroupAggro_x                                             0x10B17C4
#define __LoginName_x                                              0xFA040C
#define __Inviter_x                                                0xF9C378
#define __AttackOnAssist_x                                         0xF19268
#define __UseTellWindows_x                                         0xF1955C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF0AAF0
#define instEQZoneInfo_x                                           0xF1816C
#define instKeypressHandler_x                                      0xF9CBE0
#define pinstActiveBanker_x                                        0xF0AAA8
#define pinstActiveCorpse_x                                        0xF0AAAC
#define pinstActiveGMaster_x                                       0xF0AAB0
#define pinstActiveMerchant_x                                      0xF0AAA4
#define pinstAggroInfo_x                                           0xD145E8
#define pinstAltAdvManager_x                                       0xE57CE0
#define pinstAuraMgr_x                                             0xD24D58
#define pinstBandageTarget_x                                       0xF0AA90
#define pinstCamActor_x                                            0xE57634
#define pinstCDBStr_x                                              0xE56B9C
#define pinstCDisplay_x                                            0xF0AAB8
#define pinstCEverQuest_x                                          0x10A9CA8
#define pinstEverQuestInfo_x                                       0xF17E88
#define pinstCharData_x                                            0xF0AA74
#define pinstCharSpawn_x                                           0xF0AA9C
#define pinstControlledMissile_x                                   0xF0AA70
#define pinstControlledPlayer_x                                    0xF0AA9C
#define pinstCSidlManager_x                                        0x1715854
#define pinstCXWndManager_x                                        0x171584C
#define instDynamicZone_x                                          0xF17D28
#define pinstDZMember_x                                            0xF17E38
#define pinstDZTimerInfo_x                                         0xF17E3C
#define pinstEQItemList_x                                          0xF0716C
#define pinstEQObjectList_x                                        0xF07F44
#define instEQMisc_x                                               0xBE9808
#define pinstEQSoundManager_x                                      0xE582B0
#define instExpeditionLeader_x                                     0xF17D72
#define instExpeditionName_x                                       0xF17DB2
#define pinstGroup_x                                               0xF08546
#define pinstImeManager_x                                          0x1715858
#define pinstLocalPlayer_x                                         0xF0AA88
#define pinstMercenaryData_x                                       0xF9D260
#define pinstMercenaryStats_x                                      0x10B18D0
#define pinstMercAltAbilities_x                                    0xE58068
#define pinstModelPlayer_x                                         0xF0AAB4
#define pinstPCData_x                                              0xF0AA74
#define pinstSkillMgr_x                                            0xF9E0C8
#define pinstSpawnManager_x                                        0xF9D9B0
#define pinstSpellManager_x                                        0xF9E210
#define pinstSpellSets_x                                           0xF95114
#define pinstStringTable_x                                         0xF0AA1C
#define pinstSwitchManager_x                                       0xF080D8
#define pinstTarget_x                                              0xF0AAA0
#define pinstTargetObject_x                                        0xF0AA78
#define pinstTargetSwitch_x                                        0xF0AA7C
#define pinstTaskMember_x                                          0xE56AE8
#define pinstTrackTarget_x                                         0xF0AA94
#define pinstTradeTarget_x                                         0xF0AA84
#define instTributeActive_x                                        0xBE982D
#define pinstViewActor_x                                           0xE57630
#define pinstWorldData_x                                           0xF0AA58
#define pinstZoneAddr_x                                            0xF1840C
#define pinstPlayerPath_x                                          0xF9DA10
#define pinstTargetIndicator_x                                     0xF9E3A8
#define pinstCTargetManager_x                                      0xF9E408
#define EQObject_Top_x                                             0xF0AA68
#define pinstRealEstateItems_x                                     0xF9DFB4

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE57550
#define pinstCAchievementsWnd_x                                    0xE575AC
#define pinstCTextOverlay_x                                        0xD14AE0
#define pinstCAudioTriggersWindow_x                                0xD14970
#define pinstCCharacterSelect_x                                    0xE574C0
#define pinstCFacePick_x                                           0xE57470
#define pinstCNoteWnd_x                                            0xE57478
#define pinstCBookWnd_x                                            0xE57480
#define pinstCPetInfoWnd_x                                         0xE57484
#define pinstCTrainWnd_x                                           0xE57488
#define pinstCSkillsWnd_x                                          0xE5748C
#define pinstCSkillsSelectWnd_x                                    0xE57490
#define pinstCCombatSkillsSelectWnd_x                              0xE57494
#define pinstCFriendsWnd_x                                         0xE57498
#define pinstCAuraWnd_x                                            0xE5749C
#define pinstCRespawnWnd_x                                         0xE574A0
#define pinstCBandolierWnd_x                                       0xE574A4
#define pinstCPotionBeltWnd_x                                      0xE574A8
#define pinstCAAWnd_x                                              0xE574AC
#define pinstCGroupSearchFiltersWnd_x                              0xE574B0
#define pinstCLoadskinWnd_x                                        0xE574B4
#define pinstCAlarmWnd_x                                           0xE574B8
#define pinstCMusicPlayerWnd_x                                     0xE574BC
#define pinstCMailWnd_x                                            0xE574C4
#define pinstCMailCompositionWnd_x                                 0xE574C8
#define pinstCMailAddressBookWnd_x                                 0xE574CC
#define pinstCRaidWnd_x                                            0xE574D4
#define pinstCRaidOptionsWnd_x                                     0xE574D8
#define pinstCBreathWnd_x                                          0xE574DC
#define pinstCMapViewWnd_x                                         0xE574E0
#define pinstCMapToolbarWnd_x                                      0xE574E4
#define pinstCEditLabelWnd_x                                       0xE574E8
#define pinstCTargetWnd_x                                          0xE574EC
#define pinstCColorPickerWnd_x                                     0xE574F0
#define pinstCPlayerWnd_x                                          0xE574F4
#define pinstCOptionsWnd_x                                         0xE574F8
#define pinstCBuffWindowNORMAL_x                                   0xE574FC
#define pinstCBuffWindowSHORT_x                                    0xE57500
#define pinstCharacterCreation_x                                   0xE57504
#define pinstCCursorAttachment_x                                   0xE57508
#define pinstCCastingWnd_x                                         0xE5750C
#define pinstCCastSpellWnd_x                                       0xE57510
#define pinstCSpellBookWnd_x                                       0xE57514
#define pinstCInventoryWnd_x                                       0xE57518
#define pinstCBankWnd_x                                            0xE57520
#define pinstCQuantityWnd_x                                        0xE57524
#define pinstCLootWnd_x                                            0xE57528
#define pinstCActionsWnd_x                                         0xE5752C
#define pinstCCombatAbilityWnd_x                                   0xE57534
#define pinstCMerchantWnd_x                                        0xE57538
#define pinstCTradeWnd_x                                           0xE57540
#define pinstCSelectorWnd_x                                        0xE57544
#define pinstCBazaarWnd_x                                          0xE57548
#define pinstCBazaarSearchWnd_x                                    0xE5754C
#define pinstCGiveWnd_x                                            0xE57568
#define pinstCTrackingWnd_x                                        0xE57570
#define pinstCInspectWnd_x                                         0xE57574
#define pinstCSocialEditWnd_x                                      0xE57578
#define pinstCFeedbackWnd_x                                        0xE5757C
#define pinstCBugReportWnd_x                                       0xE57580
#define pinstCVideoModesWnd_x                                      0xE57584
#define pinstCTextEntryWnd_x                                       0xE5758C
#define pinstCFileSelectionWnd_x                                   0xE57590
#define pinstCCompassWnd_x                                         0xE57594
#define pinstCPlayerNotesWnd_x                                     0xE57598
#define pinstCGemsGameWnd_x                                        0xE5759C
#define pinstCTimeLeftWnd_x                                        0xE575A0
#define pinstCPetitionQWnd_x                                       0xE575BC
#define pinstCStoryWnd_x                                           0xE575C0
#define pinstCJournalTextWnd_x                                     0xE575C4
#define pinstCJournalCatWnd_x                                      0xE575C8
#define pinstCBodyTintWnd_x                                        0xE575CC
#define pinstCServerListWnd_x                                      0xE575D0
#define pinstCAvaZoneWnd_x                                         0xE575DC
#define pinstCBlockedBuffWnd_x                                     0xE575E0
#define pinstCBlockedPetBuffWnd_x                                  0xE575E4
#define pinstCInvSlotMgr_x                                         0xE57628
#define pinstCContainerMgr_x                                       0xE5762C
#define pinstCAdventureLeaderboardWnd_x                            0x10AA658
#define pinstCAdventureRequestWnd_x                                0x10AA6D0
#define pinstCAltStorageWnd_x                                      0x10AA9B0
#define pinstCAdventureStatsWnd_x                                  0x10AA748
#define pinstCBarterMerchantWnd_x                                  0x10AB598
#define pinstCBarterSearchWnd_x                                    0x10AB610
#define pinstCBarterWnd_x                                          0x10AB688
#define pinstCChatWindowManager_x                                  0x10ABD18
#define pinstCDynamicZoneWnd_x                                     0x10AC1C8
#define pinstCEQMainWnd_x                                          0x10AC360
#define pinstCFellowshipWnd_x                                      0x10AC15C
#define pinstCFindLocationWnd_x                                    0x10AC630
#define pinstCGroupSearchWnd_x                                     0x10AC900
#define pinstCGroupWnd_x                                           0x10AC978
#define pinstCGuildBankWnd_x                                       0x10AC9F0
#define pinstCGuildMgmtWnd_x                                       0x10AEAE0
#define pinstCHotButtonWnd_x                                       0x10AEBDC
#define pinstCHotButtonWnd1_x                                      0x10AEBDC
#define pinstCHotButtonWnd2_x                                      0x10AEBE0
#define pinstCHotButtonWnd3_x                                      0x10AEBE4
#define pinstCHotButtonWnd4_x                                      0x10AEC08
#define pinstCItemDisplayManager_x                                 0x10AEF00
#define pinstCItemExpTransferWnd_x                                 0x10AEF7C
#define pinstCLFGuildWnd_x                                         0x10AF258
#define pinstCMIZoneSelectWnd_x                                    0x10AF840
#define pinstCConfirmationDialog_x                                 0x10AFF48
#define pinstCPopupWndManager_x                                    0x10AFF48
#define pinstCProgressionSelectionWnd_x                            0x10B0038
#define pinstCPvPStatsWnd_x                                        0x10B0128
#define pinstCLargeDialogWnd_x                                     0x10B0830
#define pinstCTaskWnd_x                                            0x10B1BB0
#define pinstCTaskSomething_x                                      0xD25690
#define pinstCTaskTemplateSelectWnd_x                              0x10B1B38
#define pinstCTipWndOFDAY_x                                        0x10B1D18
#define pinstCTipWndCONTEXT_x                                      0x10B1D1C
#define pinstCTitleWnd_x                                           0x10B1D98
#define pinstCContextMenuManager_x                                 0x17157C4
#define pinstCVoiceMacroWnd_x                                      0xF9E7E0
#define pinstCHtmlWnd_x                                            0xF9E8D0
#define pinstIconCache_x                                           0x10AC334
#define pinstCTradeskillWnd_x                                      0x10B1E98
#define pinstCAdvancedLootWnd_x                                    0xE5761C
#define pinstRewardSelectionWnd_x                                  0x10B0650

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x53D5F0
#define __ConvertItemTags_x                                        0x52AFC0
#define __ExecuteCmd_x                                             0x515B40
#define __EQGetTime_x                                              0x892980
#define __get_melee_range_x                                        0x51C790
#define __GetGaugeValueFromEQ_x                                    0x7A3B50
#define __GetLabelFromEQ_x                                         0x7A4F20
#define __ToggleKeyRingItem_x                                      0x484340
#define __GetXTargetType_x                                         0x923360
#define __LoadFrontEnd_x                                           0x6330A0
#define __NewUIINI_x                                               0x7A3520
#define __ProcessGameEvents_x                                      0x576CD0
#define __ProcessMouseEvent_x                                      0x576470
#define CrashDetected_x                                            0x634A60
#define wwsCrashReportCheckForUploader_x                           0x7F18B0
#define __AppCrashWrapper_x                                        0xC4F51C
#define __pCrashHandler_x                                          0x10BED48
#define __CrashHandler_x                                           0x7F1310
#define wwsCrashReportPlatformLaunchUploader_x                     0x7F3AC0
#define DrawNetStatus_x                                            0x5AD4F0
#define Util__FastTime_x                                           0x892620
#define Expansion_HoT_x                                            0xF19258
#define __HelpPath_x                                               0xF9C968
#define __STMLToText_x                                             0x8D8640

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4230E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DE90
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DC70

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4CBE90
#define AltAdvManager__IsAbilityReady_x                            0x4CBF00
#define AltAdvManager__GetAAById_x                                 0x4CC3F0
#define AltAdvManager__CanTrainAbility_x                           0x4CD020
#define AltAdvManager__CanSeeAbility_x                             0x4CCBE0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x466110
#define CharacterZoneClient__MakeMeVisible_x                       0x46A7F0
#define CharacterZoneClient__IsStackBlocked_x                      0x44A7F0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x449CB0
#define CharacterZoneClient__GetItemCountWorn_x                    0x464090
#define CharacterZoneClient__GetItemCountInInventory_x             0x464170
#define CharacterZoneClient__GetCursorItemCount_x                  0x464250
#define CharacterZoneClient__FindAffectSlot_x                      0x44FD40

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x662980

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x670EE0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58C580
#define CButtonWnd__CButtonWnd_x                                   0x8CC9A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68BF60
#define CChatManager__InitContextMenu_x                            0x68D0B0
#define CChatManager__FreeChatWindow_x                             0x68B9F0
#define CChatManager__GetLockedActiveChatWindow_x                  0x694950
#define CChatManager__SetLockedActiveChatWindow_x                  0x68BF30
// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D69B0
#define CContextMenu__dCContextMenu_x                              0x8D6BC0
#define CContextMenu__AddMenuItem_x                                0x8D6BD0
#define CContextMenu__RemoveMenuItem_x                             0x8D6EB0
#define CContextMenu__RemoveAllMenuItems_x                         0x8D6ED0
#define CContextMenuManager__AddMenu_x                             0x8C2F20
#define CContextMenuManager__RemoveMenu_x                          0x8C32C0
#define CContextMenuManager__PopupMenu_x                           0x8C3710
#define CContextMenuManager__Flush_x                               0x8C2F90
#define CContextMenuManager__GetMenu_x                             0x419570
#define CContextMenu__CheckMenuItem_x                              0x8D6F50

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x876D10
#define CChatService__GetFriendName_x                              0x876D20

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x692CC0
#define CChatWindow__Clear_x                                       0x6925A0
#define CChatWindow__WndNotification_x                             0x693200

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C6D80
#define CComboWnd__Draw_x                                          0x8C6F90
#define CComboWnd__GetCurChoice_x                                  0x8C6B30
#define CComboWnd__GetListRect_x                                   0x8C7230
#define CComboWnd__GetTextRect_x                                   0x8C6DF0
#define CComboWnd__InsertChoice_x                                  0x8C72A0
#define CComboWnd__SetColors_x                                     0x8C6AC0
#define CComboWnd__SetChoice_x                                     0x8C6AF0
#define CComboWnd__GetItemCount_x                                  0x8C6B20
#define CComboWnd__GetCurChoiceText_x                              0x8C6B70

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69C6D0
#define CContainerWnd__vftable_x                                   0xAD6A00

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4BA1A0
#define CDisplay__GetClickedActor_x                                0x4B2AD0
#define CDisplay__GetUserDefinedColor_x                            0x4B16B0
#define CDisplay__GetWorldFilePath_x                               0x4B0B00
#define CDisplay__is3dON_x                                         0x4AFF90
#define CDisplay__ReloadUI_x                                       0x4C5720
#define CDisplay__WriteTextHD2_x                                   0x4B6560

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8ECFD0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DAEF0
#define CEditWnd__GetCharIndexPt_x                                 0x8DBF70
#define CEditWnd__GetDisplayString_x                               0x8DB0A0
#define CEditWnd__GetHorzOffset_x                                  0x8DB3E0
#define CEditWnd__GetLineForPrintableChar_x                        0x8DBA40
#define CEditWnd__GetSelStartPt_x                                  0x8DC220
#define CEditWnd__GetSTMLSafeText_x                                0x8DB570
#define CEditWnd__PointFromPrintableChar_x                         0x8DBB30
#define CEditWnd__SelectableCharFromPoint_x                        0x8DBCB0
#define CEditWnd__SetEditable_x                                    0x8DB540

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x55E100
#define CEverQuest__ClickedPlayer_x                                0x557DC0
#define CEverQuest__CreateTargetIndicator_x                        0x558CB0
#define CEverQuest__DeleteTargetIndicator_x                        0x558D30
#define CEverQuest__DoTellWindow_x                                 0x4753C0
#define CEverQuest__OutputTextToLog_x                              0x475020
#define CEverQuest__DropHeldItemOnGround_x                         0x56EB10
#define CEverQuest__dsp_chat_x                                     0x475700
#define CEverQuest__trimName_x                                     0x554710
#define CEverQuest__Emote_x                                        0x56C8F0
#define CEverQuest__EnterZone_x                                    0x567A60
#define CEverQuest__GetBodyTypeDesc_x                              0x552170
#define CEverQuest__GetClassDesc_x                                 0x55B540
#define CEverQuest__GetClassThreeLetterCode_x                      0x55BB40
#define CEverQuest__GetDeityDesc_x                                 0x552A50
#define CEverQuest__GetLangDesc_x                                  0x552500
#define CEverQuest__GetRaceDesc_x                                  0x55BD00
#define CEverQuest__InterpretCmd_x                                 0x55F880
#define CEverQuest__LeftClickedOnPlayer_x                          0x573390
#define CEverQuest__LMouseUp_x                                     0x575490
#define CEverQuest__RightClickedOnPlayer_x                         0x573EA0
#define CEverQuest__RMouseUp_x                                     0x574EF0
#define CEverQuest__SetGameState_x                                 0x558680
#define CEverQuest__UPCNotificationFlush_x                         0x54FF80
#define CEverQuest__IssuePetCommand_x                              0x560260

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AD430
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AD490
#define CGaugeWnd__Draw_x                                          0x6AD8C0

// CGuild
#define CGuild__FindMemberByName_x                                 0x43A0D0
#define CGuild__GetGuildName_x                                     0x43A5A0
#define CGuild__GetGuildIndex_x                                    0x43B770

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C9950

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D6B00
#define CInvSlotMgr__MoveItem_x                                    0x6D79B0
#define CInvSlotMgr__SelectSlot_x                                  0x6D6BB0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D5FB0
#define CInvSlot__SliderComplete_x                                 0x6D37C0
#define CInvSlot__GetItemBase_x                                    0x6D2C40
#define CInvSlot__UpdateItem_x                                     0x6D31C0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D8E10
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6D9F30

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79F560
#define CItemDisplayWnd__UpdateStrings_x                           0x6DAF90
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6E7A80
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6E7FC0
#define CItemDisplayWnd__SetItem_x                                 0x6EDB00

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7D6840

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6E1570

// CLabel 
#define CLabel__Draw_x                                             0x6F47B0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B2990
#define CListWnd__dCListWnd_x                                      0x8B3BB0
#define CListWnd__AddColumn_x                                      0x8B3B50
#define CListWnd__AddColumn1_x                                     0x8B31F0
#define CListWnd__AddLine_x                                        0x8B2C50
#define CListWnd__AddString_x                                      0x8B2E70
#define CListWnd__CalculateFirstVisibleLine_x                      0x8AFC60
#define CListWnd__CalculateVSBRange_x                              0x8B1E60
#define CListWnd__ClearSel_x                                       0x8AEF90
#define CListWnd__ClearAllSel_x                                    0x8AEF40
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B2820
#define CListWnd__Compare_x                                        0x8B07B0
#define CListWnd__Draw_x                                           0x8B1A70
#define CListWnd__DrawColumnSeparators_x                           0x8B1900
#define CListWnd__DrawHeader_x                                     0x8AF250
#define CListWnd__DrawItem_x                                       0x8B0E40
#define CListWnd__DrawLine_x                                       0x8B15A0
#define CListWnd__DrawSeparator_x                                  0x8B19A0
#define CListWnd__EnableLine_x                                     0x8AF170
#define CListWnd__EnsureVisible_x                                  0x8AFDC0
#define CListWnd__ExtendSel_x                                      0x8B0D50
#define CListWnd__GetColumnMinWidth_x                              0x8AE940
#define CListWnd__GetColumnWidth_x                                 0x8AE870
#define CListWnd__GetCurSel_x                                      0x8AE040
#define CListWnd__GetItemAtPoint_x                                 0x8B0040
#define CListWnd__GetItemAtPoint1_x                                0x8B00B0
#define CListWnd__GetItemData_x                                    0x8AE390
#define CListWnd__GetItemHeight_x                                  0x8AF8D0
#define CListWnd__GetItemIcon_x                                    0x8AE580
#define CListWnd__GetItemRect_x                                    0x8AFE80
#define CListWnd__GetItemText_x                                    0x8AE430
#define CListWnd__GetSelList_x                                     0x8B30E0
#define CListWnd__GetSeparatorRect_x                               0x8B06D0
#define CListWnd__InsertLine_x                                     0x8B3050
#define CListWnd__RemoveLine_x                                     0x8B3060
#define CListWnd__SetColors_x                                      0x8AE190
#define CListWnd__SetColumnJustification_x                         0x8AEBD0
#define CListWnd__SetColumnWidth_x                                 0x8AE8F0
#define CListWnd__SetCurSel_x                                      0x8AE080
#define CListWnd__SetItemColor_x                                   0x8B2510
#define CListWnd__SetItemData_x                                    0x8AEFF0
#define CListWnd__SetItemText_x                                    0x8B2350
#define CListWnd__ShiftColumnSeparator_x                           0x8B21E0
#define CListWnd__Sort_x                                           0x8B3CB0
#define CListWnd__ToggleSel_x                                      0x8AEEC0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70D710

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72EBB0
#define CMerchantWnd__RequestBuyItem_x                             0x735C70
#define CMerchantWnd__RequestSellItem_x                            0x736740
#define CMerchantWnd__SelectRecoverySlot_x                         0x72EE60
#define CMerchantWnd__SelectBuySellSlot_x                          0x72E060
#define CMerchantWnd__ActualSelect_x                               0x732B40

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x845250
#define CPacketScrambler__hton_x                                   0x845260

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8D1840
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D1920
#define CSidlManager__CreateLabel_x                                0x796E60
#define CSidlManager__CreateXWndFromTemplate_x                     0x8CFDE0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8D1C00

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8C8E10
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8C8D10
#define CSidlScreenWnd__ConvertToRes_x                             0x8ECEB0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8C9720
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CA8E0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CA990
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C9E70
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8C90D0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8C8840
#define CSidlScreenWnd__GetSidlPiece_x                             0x8C92C0
#define CSidlScreenWnd__Init1_x                                    0x8CA5C0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C97D0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8C8A00
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CA0B0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C84A0
#define CSidlScreenWnd__StoreIniVis_x                              0x8C87F0
#define CSidlScreenWnd__WndNotification_x                          0x8CA340
#define CSidlScreenWnd__GetChildItem_x                             0x8C8910
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BC170
#define CSidlScreenWnd__m_layoutCopy_x                             0x1715828

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F8840
#define CSkillMgr__GetSkillCap_x                                   0x5F8A20
#define CSkillMgr__GetNameToken_x                                  0x5F83F0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8EC160
#define CSliderWnd__SetValue_x                                     0x8EC330
#define CSliderWnd__SetNumTicks_x                                  0x8ECAB0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79D1C0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8E7B20
#define CStmlWnd__CalculateHSBRange_x                              0x8E0110
#define CStmlWnd__CalculateVSBRange_x                              0x8E0080
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E0290
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E0B70
#define CStmlWnd__ForceParseNow_x                                  0x8E8470
#define CStmlWnd__GetNextTagPiece_x                                0x8E0A70
#define CStmlWnd__GetSTMLText_x                                    0x694910
#define CStmlWnd__GetVisibleText_x                                 0x8E15C0
#define CStmlWnd__InitializeWindowVariables_x                      0x8E3940
#define CStmlWnd__MakeStmlColorTag_x                               0x8DF380
#define CStmlWnd__MakeWndNotificationTag_x                         0x8DF3E0
#define CStmlWnd__SetSTMLText_x                                    0x8E5190
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E77C0
#define CStmlWnd__UpdateHistoryString_x                            0x8E2500

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8DEA90
#define CTabWnd__DrawCurrentPage_x                                 0x8DE320
#define CTabWnd__DrawTab_x                                         0x8DE0F0
#define CTabWnd__GetCurrentPage_x                                  0x8DE6D0
#define CTabWnd__GetPageInnerRect_x                                0x8DDDE0
#define CTabWnd__GetTabInnerRect_x                                 0x8DDFE0
#define CTabWnd__GetTabRect_x                                      0x8DDEB0
#define CTabWnd__InsertPage_x                                      0x8DED80
#define CTabWnd__SetPage_x                                         0x8DE700
#define CTabWnd__SetPageRect_x                                     0x8DE9D0
#define CTabWnd__UpdatePage_x                                      0x8DED20
#define CTabWnd__GetPageFromTabIndex_x                             0x8DE040
#define CTabWnd__GetCurrentTabIndex_x                              0x8DDD70

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6DA0E0
#define CPageWnd__SetTabText_x                                     0x8F5ED0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x435C20

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C6730
#define CTextureFont__GetTextExtent_x                              0x8C6490

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x631310

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F2310

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8AC2F0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x599D70
#define CXStr__CXStr1_x                                            0x740F90
#define CXStr__CXStr3_x                                            0x88F8C0
#define CXStr__dCXStr_x                                            0x8F10B0
#define CXStr__operator_equal_x                                    0x88FA30
#define CXStr__operator_equal1_x                                   0x88FA80
#define CXStr__operator_plus_equal1_x                              0x890B80

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BB360
#define CXWnd__Center_x                                            0x8C1520
#define CXWnd__ClrFocus_x                                          0x8BAF30
#define CXWnd__Destroy_x                                           0x8C2000
#define CXWnd__DoAllDrawing_x                                      0x8C1170
#define CXWnd__DrawChildren_x                                      0x8C1310
#define CXWnd__DrawColoredRect_x                                   0x8BB740
#define CXWnd__DrawTooltip_x                                       0x8BB9E0
#define CXWnd__DrawTooltipAtPoint_x                                0x8C0100
#define CXWnd__GetBorderFrame_x                                    0x8BBE40
#define CXWnd__GetChildWndAt_x                                     0x8C1EE0
#define CXWnd__GetClientClipRect_x                                 0x8BBBF0
#define CXWnd__GetScreenClipRect_x                                 0x8C07F0
#define CXWnd__GetScreenRect_x                                     0x8BC010
#define CXWnd__GetTooltipRect_x                                    0x8BB870
#define CXWnd__GetWindowTextA_x                                    0x4271F0
#define CXWnd__IsActive_x                                          0x8B69A0
#define CXWnd__IsDescendantOf_x                                    0x8BBD80
#define CXWnd__IsReallyVisible_x                                   0x8BF150
#define CXWnd__IsType_x                                            0x8C1590
#define CScreenPieceTemplate__IsType_x                             0x8EEB50
#define CXWnd__Move_x                                              0x8BE850
#define CXWnd__Move1_x                                             0x8C0E20
#define CXWnd__ProcessTransition_x                                 0x8BB300
#define CXWnd__Refade_x                                            0x8BB0D0
#define CXWnd__Resize_x                                            0x8BC0D0
#define CXWnd__Right_x                                             0x8C05F0
#define CXWnd__SetFocus_x                                          0x8BD9B0
#define CXWnd__SetFont_x                                           0x8BAF80
#define CXWnd__SetKeyTooltip_x                                     0x8BC340
#define CXWnd__SetMouseOver_x                                      0x8C0B10
#define CXWnd__StartFade_x                                         0x8BB3B0
#define CXWnd__GetChildItem_x                                      0x8C0A60
#define CXWnd__SetParent_x                                         0x8C1E90

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B8240
#define CXWndManager__DrawWindows_x                                0x8B7E80
#define CXWndManager__GetKeyboardFlags_x                           0x8B64D0
#define CXWndManager__HandleKeyboardMsg_x                          0x8B6E30
#define CXWndManager__RemoveWnd_x                                  0x8B6B30

// CDBStr
#define CDBStr__GetString_x                                        0x4AE560

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x450D70
#define EQ_Character__Cur_HP_x                                     0x465710
#define EQ_Character__Cur_Mana_x                                   0x4594C0
#define EQ_Character__GetAACastingTimeModifier_x                   0x449FC0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x442310
#define EQ_Character__GetFocusRangeModifier_x                      0x442370
#define EQ_Character__GetHPRegen_x                                 0x4688F0
#define EQ_Character__GetEnduranceRegen_x                          0x464D20
#define EQ_Character__GetManaRegen_x                               0x468E90
#define EQ_Character__Max_Endurance_x                              0x5BF350
#define EQ_Character__Max_HP_x                                     0x45C030
#define EQ_Character__Max_Mana_x                                   0x5BF180
#define EQ_Character__doCombatAbility_x                            0x5BC860
#define EQ_Character__UseSkill_x                                   0x46F870
#define EQ_Character__GetConLevel_x                                0x5B1B80
#define EQ_Character__IsExpansionFlag_x                            0x426720
#define EQ_Character__TotalEffect_x                                0x44E070
#define EQ_Character__GetPCSpellAffect_x                           0x44A3C0
#define EQ_Character__SpellDuration_x                              0x448360
#define EQ_Character__FindItemByRecord_x                           0x462D60
#define EQ_Character__GetAdjustedSkill_x                           0x465EC0
#define EQ_Character__GetBaseSkill_x                               0x45BF10

//ProfileManager_
#define ProfileManager__GetCurrentProfile_x                        0x862840

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5C7300

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x445670
#define CCharacterSelect__EnterWorld_x                             0x444E40
#define CCharacterSelect__Quit_x                                   0x443A20

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x591FF0
#define EQ_Item__CreateItemTagString_x                             0x843BE0
#define EQ_Item__IsStackable_x                                     0x839660
#define EQ_Item__GetImageNum_x                                     0x83C0B0
#define EQ_Item__CreateItemClient_x                                0x592BF0
#define EQ_Item__GetItemValue_x                                    0x842930
#define EQ_Item__ValueSellMerchant_x                               0x844EB0
#define EQ_Item__IsKeyRingItem_x                                   0x83A0A0
#define EQ_Item__CanGoInBag_x                                      0x592180
#define EQ_Item__GetMaxItemCount_x                                 0x839550
#define EQ_Item__GetHeldItem_x                                     0x83AEB0
#define EQ_Item__GetAugmentFitBySlot_x                             0x844CD0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4CE420
#define EQ_LoadingS__Array_x                                       0xBF1BB8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C17E0
#define EQ_PC__GetAlternateAbilityId_x                             0x84D2E0
#define EQ_PC__GetCombatAbility_x                                  0x84D370
#define EQ_PC__GetCombatAbilityTimer_x                             0x847F00
#define EQ_PC__GetItemRecastTimer_x                                0x5BAF20
#define EQ_PC__HasLoreItem_x                                       0x5B5190
#define EQ_PC__AlertInventoryChanged_x                             0x5B1B50
#define EQ_PC__GetPcZoneClient_x                                   0x5DB740
#define EQ_PC__RemoveMyAffect_x                                    0x5BA3F0
#define EQ_PC__GetKeyRingItems_x                                   0x848320
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x85B050
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x84F2C0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x51A810
#define EQItemList__add_object_x                                   0x546EE0
#define EQItemList__add_item_x                                     0x51A750
#define EQItemList__delete_item_x                                  0x51AC00
#define EQItemList__FreeItemList_x                                 0x51AB00

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4AD830

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C70A0
#define EQPlayer__dEQPlayer_x                                      0x5CF640
#define EQPlayer__DoAttack_x                                       0x5E13C0
#define EQPlayer__EQPlayer_x                                       0x5D1D50
#define EQPlayer__SetNameSpriteState_x                             0x5CC590
#define EQPlayer__SetNameSpriteTint_x                              0x5C84B0
#define PlayerBase__HasProperty_j_x                                0x91FB00
#define EQPlayer__IsTargetable_x                                   0x91FDA0
#define EQPlayer__CanSee_x                                         0x920300
#define PlayerZoneClient__ChangeHeight_x                           0x5E1280
#define EQPlayer__CanSeeTargetIndicator_x                          0x9203F0
#define PlayerBase__GetVisibilityLineSegment_x                     0x920090

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D5DA0
#define EQPlayerManager__GetSpawnByName_x                          0x5D6200
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D5DD0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x598110
#define KeypressHandler__AttachKeyToEqCommand_x                    0x598150
#define KeypressHandler__ClearCommandStateArray_x                  0x597D00
#define KeypressHandler__HandleKeyDown_x                           0x596660
#define KeypressHandler__HandleKeyUp_x                             0x596980
#define KeypressHandler__SaveKeymapping_x                          0x597DD0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7060A0
#define MapViewMap__SaveEx_x                                       0x7093D0

#define PlayerPointManager__GetAltCurrency_x                       0x860920

// StringTable 
#define StringTable__getString_x                                   0x85B380

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BEDE0
#define PcZoneClient__RemovePetEffect_x                            0x5BB3F0
#define PcZoneClient__HasAlternateAbility_x                        0x5BBD90
#define PcZoneClient__GetCurrentMod_x                              0x45B4E0
#define PcZoneClient__GetModCap_x                                  0x458C20
#define PcZoneClient__CanEquipItem_x                               0x5BC340
#define PcZoneClient__GetItemByID_x                                0x5C0BD0
#define PcZoneClient__GetItemByItemClass_x                         0x5C1700

//Doors
#define EQSwitch__UseSwitch_x                                      0x54E8A0

//IconCache
#define IconCache__GetIcon_x                                       0x6A2B80

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x699A60
#define CContainerMgr__CloseContainer_x                            0x69A280

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x766E30

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58AFA0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E8390
#define EQ_Spell__SpellAffects_x                                   0x4E5A40
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4E5AB0
#define CharacterZoneClient__CalcAffectChange_x                    0x449490
#define CLootWnd__LootAll_x                                        0x6FBA20
#define CLootWnd__RequestLootSlot_x                                0x6FC230

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AC480
#define CTargetWnd__WndNotification_x                              0x7ABF70
#define CTargetWnd__RefreshTargetBuffs_x                           0x7AC660

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B1570

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4E0FF0
#define EqSoundManager__PlayScriptMp3_x                            0x4E2A90

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x49CBC0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DA520
#define CSidlManager__FindAnimation1_x                             0x8CF810

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D5B00
#define CAltAbilityData__GetMercMaxRank_x                          0x4D5AB0
#define CAltAbilityData__GetMaxRank_x                              0x4CA540

//CTargetRing
#define CTargetRing__Cast_x                                        0x588890

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x457C30
#define CharacterBase__CreateItemGlobalIndex_x                     0x474540
#define CharacterBase__CreateItemIndex_x                           0x513D50
#define CharacterBase__GetItemPossession_x                         0x442EC0
#define CharacterBase__GetItemByGlobalIndex_x                      0x870A10

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x682F50
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6826B0

//messages
#define msg_spell_worn_off_x                                       0x4EFDE0
#define msg_new_text_x                                             0x4F93A0
#define msgTokenTextParam_x                                        0x4F5C00

//SpellManager
#define SpellManager__vftable_x                                    0xAB3118
#define SpellManager__SpellManager_x                               0x47D330
#define Spellmanager__CheckSpellRequirementAssociations_x          0x5FF770

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x923E80

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4EC4D0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43DA90
#define ItemGlobalIndex__IsEquippedLocation_x                      0x447CD0
#define ItemGlobalIndex__IsValidIndex_x                            0x457480

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x86E880
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x86D7C0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F4A00

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x69E780
#define CCursorAttachment__Deactivate_x                            0x69DCC0
