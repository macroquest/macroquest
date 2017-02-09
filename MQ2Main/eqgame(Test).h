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
#define __ExpectedVersionDate                                     "Feb  7 2017"
#define __ExpectedVersionTime                                     "20:43:26"
#define __ActualVersionDate_x                                      0xAC6A20
#define __ActualVersionTime_x                                      0xAC6A2C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x597F90
#define __MemChecker1_x                                            0x88D120
#define __MemChecker2_x                                            0x62DF40
#define __MemChecker3_x                                            0x62DE90
#define __MemChecker4_x                                            0x7E0450
#define __EncryptPad0_x                                            0xC1E5E0
#define __EncryptPad1_x                                            0xCF9E78
#define __EncryptPad2_x                                            0xC47C40
#define __EncryptPad3_x                                            0xC47840
#define __EncryptPad4_x                                            0xCE84A0
#define __EncryptPad5_x                                            0x10A26E8
#define __AC1_x                                                    0x79FB85
#define __AC2_x                                                    0x552217
#define __AC3_x                                                    0x5503B0
#define __AC4_x                                                    0x562770
#define __AC5_x                                                    0x5754CB
#define __AC6_x                                                    0x57907E
#define __AC7_x                                                    0x56FB3C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FE53E0

// Direct Input
#define DI8__Main_x                                                0x10A26C0
#define DI8__Keyboard_x                                            0x10A26C4
#define DI8__Mouse_x                                               0x10A26C8
#define DI8__Mouse_Copy_x                                          0xF10DA4
#define DI8__Mouse_Check_x                                         0xF9A5AC
#define __Attack_x                                                 0xF95293
#define __Autofire_x                                               0xF95294
#define __BindList_x                                               0xBF9400
#define g_eqCommandStates_x                                        0xEFFDD0
#define __Clicks_x                                                 0xF10E60
#define __CommandList_x                                            0xBFBA60
#define __CurrentMapLabel_x                                        0x10A8148
#define __CurrentSocial_x                                          0xBCC334
#define __DoAbilityList_x                                          0xF47548
#define __do_loot_x                                                0x520DA0
#define __DrawHandler_x                                            0x170F074
#define __GroupCount_x                                             0xF013FA

#define __Guilds_x                                                 0xF07010
#define __gWorld_x                                                 0xF038B4
#define __HotkeyPage_x                                             0xF8DF48
#define __HWnd_x                                                   0xF9A5C8
#define __InChatMode_x                                             0xF10D8C
#define __LastTell_x                                               0xF12C44
#define __LMouseHeldTime_x                                         0xF10ECC
#define __Mouse_x                                                  0x10A26CC
#define __MouseLook_x                                              0xF10E26
#define __MouseEventTime_x                                         0xF95A94
#define __gpbCommandEvent_x                                        0xF0397C
#define __NetStatusToggle_x                                        0xF10E29
#define __PCNames_x                                                0xF12260
#define __RangeAttackReady_x                                       0xF11F94
#define __RMouseHeldTime_x                                         0xF10EC8
#define __RunWalkState_x                                           0xF10D90
#define __ScreenMode_x                                             0xE4FAC8
#define __ScreenX_x                                                0xF10D44
#define __ScreenY_x                                                0xF10D40
#define __ScreenXMax_x                                             0xF10D48
#define __ScreenYMax_x                                             0xF10D4C
#define __ServerHost_x                                             0xF01344
#define __ServerName_x                                             0xF47508
#define __ShiftKeyDown_x                                           0xF11420
#define __ShowNames_x                                              0xF12154
#define __Socials_x                                                0xF47608
#define __SubscriptionType_x                                       0x10D6184
#define __TargetAggroHolder_x                                      0x10AA390
#define __ZoneType_x                                               0xF11224
#define __GroupAggro_x                                             0x10AA3D0
#define __LoginName_x                                              0xF991A4
#define __Inviter_x                                                0xF95210
#define __AttackOnAssist_x                                         0xF12110
#define __UseTellWindows_x                                         0xF123F8

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF039A0
#define instEQZoneInfo_x                                           0xF1101C
#define instKeypressHandler_x                                      0xF95A78
#define pinstActiveBanker_x                                        0xF03958
#define pinstActiveCorpse_x                                        0xF0395C
#define pinstActiveGMaster_x                                       0xF03960
#define pinstActiveMerchant_x                                      0xF03954
#define pinstAggroInfo_x                                           0xD0D528
#define pinstAltAdvManager_x                                       0xE50B98
#define pinstAuraMgr_x                                             0xD1DC98
#define pinstBandageTarget_x                                       0xF03940
#define pinstCamActor_x                                            0xE504E8
#define pinstCDBStr_x                                              0xE4FA5C
#define pinstCDisplay_x                                            0xF03968
#define pinstCEverQuest_x                                          0x10A2840
#define pinstEverQuestInfo_x                                       0xF10D38
#define pinstCharData_x                                            0xF03924
#define pinstCharSpawn_x                                           0xF0394C
#define pinstControlledMissile_x                                   0xF03920
#define pinstControlledPlayer_x                                    0xF0394C
#define pinstCSidlManager_x                                        0x170E464
#define pinstCXWndManager_x                                        0x170E45C
#define instDynamicZone_x                                          0xF10BD8
#define pinstDZMember_x                                            0xF10CE8
#define pinstDZTimerInfo_x                                         0xF10CEC
#define pinstEQItemList_x                                          0xF00020
#define pinstEQObjectList_x                                        0xF00DF4
#define instEQMisc_x                                               0xBE1B18
#define pinstEQSoundManager_x                                      0xE51168
#define instExpeditionLeader_x                                     0xF10C22
#define instExpeditionName_x                                       0xF10C62
#define pinstGroup_x                                               0xF013F6
#define pinstImeManager_x                                          0x170E468
#define pinstLocalPlayer_x                                         0xF03938
#define pinstMercenaryData_x                                       0xF960F8
#define pinstMercenaryStats_x                                      0x10AA4DC
#define pinstMercAltAbilities_x                                    0xE50F20
#define pinstModelPlayer_x                                         0xF03964
#define pinstPCData_x                                              0xF03924
#define pinstSkillMgr_x                                            0xF96F60
#define pinstSpawnManager_x                                        0xF96848
#define pinstSpellManager_x                                        0xF970A8
#define pinstSpellSets_x                                           0xF8DFAC
#define pinstStringTable_x                                         0xF038CC
#define pinstSwitchManager_x                                       0xF00F88
#define pinstTarget_x                                              0xF03950
#define pinstTargetObject_x                                        0xF03928
#define pinstTargetSwitch_x                                        0xF0392C
#define pinstTaskMember_x                                          0xE4F9A8
#define pinstTrackTarget_x                                         0xF03944
#define pinstTradeTarget_x                                         0xF03934
#define instTributeActive_x                                        0xBE1B3D
#define pinstViewActor_x                                           0xE504E4
#define pinstWorldData_x                                           0xF03908
#define pinstZoneAddr_x                                            0xF112BC
#define pinstPlayerPath_x                                          0xF968A8
#define pinstTargetIndicator_x                                     0xF97240
#define pinstCTargetManager_x                                      0xF972A0
#define EQObject_Top_x                                             0xF03918
#define pinstRealEstateItems_x                                     0xF96E4C

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE50400
#define pinstCAchievementsWnd_x                                    0xE5045C
#define pinstCTextOverlay_x                                        0xD0DA20
#define pinstCAudioTriggersWindow_x                                0xD0D8B0
#define pinstCCharacterSelect_x                                    0xE50374
#define pinstCFacePick_x                                           0xE50124
#define pinstCNoteWnd_x                                            0xE5032C
#define pinstCBookWnd_x                                            0xE50334
#define pinstCPetInfoWnd_x                                         0xE50338
#define pinstCTrainWnd_x                                           0xE5033C
#define pinstCSkillsWnd_x                                          0xE50340
#define pinstCSkillsSelectWnd_x                                    0xE50344
#define pinstCCombatSkillsSelectWnd_x                              0xE50348
#define pinstCFriendsWnd_x                                         0xE5034C
#define pinstCAuraWnd_x                                            0xE50350
#define pinstCRespawnWnd_x                                         0xE50354
#define pinstCBandolierWnd_x                                       0xE50358
#define pinstCPotionBeltWnd_x                                      0xE5035C
#define pinstCAAWnd_x                                              0xE50360
#define pinstCGroupSearchFiltersWnd_x                              0xE50364
#define pinstCLoadskinWnd_x                                        0xE50368
#define pinstCAlarmWnd_x                                           0xE5036C
#define pinstCMusicPlayerWnd_x                                     0xE50370
#define pinstCMailWnd_x                                            0xE50378
#define pinstCMailCompositionWnd_x                                 0xE5037C
#define pinstCMailAddressBookWnd_x                                 0xE50380
#define pinstCRaidWnd_x                                            0xE50388
#define pinstCRaidOptionsWnd_x                                     0xE5038C
#define pinstCBreathWnd_x                                          0xE50390
#define pinstCMapViewWnd_x                                         0xE50394
#define pinstCMapToolbarWnd_x                                      0xE50398
#define pinstCEditLabelWnd_x                                       0xE5039C
#define pinstCTargetWnd_x                                          0xE503A0
#define pinstCColorPickerWnd_x                                     0xE503A4
#define pinstCPlayerWnd_x                                          0xE503A8
#define pinstCOptionsWnd_x                                         0xE503AC
#define pinstCBuffWindowNORMAL_x                                   0xE503B0
#define pinstCBuffWindowSHORT_x                                    0xE503B4
#define pinstCharacterCreation_x                                   0xE503B8
#define pinstCCursorAttachment_x                                   0xE503BC
#define pinstCCastingWnd_x                                         0xE503C0
#define pinstCCastSpellWnd_x                                       0xE503C4
#define pinstCSpellBookWnd_x                                       0xE503C8
#define pinstCInventoryWnd_x                                       0xE503CC
#define pinstCBankWnd_x                                            0xE503D4
#define pinstCQuantityWnd_x                                        0xE503D8
#define pinstCLootWnd_x                                            0xE503DC
#define pinstCActionsWnd_x                                         0xE503E0
#define pinstCCombatAbilityWnd_x                                   0xE503E8
#define pinstCMerchantWnd_x                                        0xE503EC
#define pinstCTradeWnd_x                                           0xE503F0
#define pinstCSelectorWnd_x                                        0xE503F4
#define pinstCBazaarWnd_x                                          0xE503F8
#define pinstCBazaarSearchWnd_x                                    0xE503FC
#define pinstCGiveWnd_x                                            0xE50418
#define pinstCTrackingWnd_x                                        0xE50420
#define pinstCInspectWnd_x                                         0xE50424
#define pinstCSocialEditWnd_x                                      0xE50428
#define pinstCFeedbackWnd_x                                        0xE5042C
#define pinstCBugReportWnd_x                                       0xE50430
#define pinstCVideoModesWnd_x                                      0xE50434
#define pinstCTextEntryWnd_x                                       0xE5043C
#define pinstCFileSelectionWnd_x                                   0xE50440
#define pinstCCompassWnd_x                                         0xE50444
#define pinstCPlayerNotesWnd_x                                     0xE50448
#define pinstCGemsGameWnd_x                                        0xE5044C
#define pinstCTimeLeftWnd_x                                        0xE50450
#define pinstCPetitionQWnd_x                                       0xE5046C
#define pinstCSoulmarkWnd_x                                        0xE50470
#define pinstCStoryWnd_x                                           0xE50474
#define pinstCJournalTextWnd_x                                     0xE50478
#define pinstCJournalCatWnd_x                                      0xE5047C
#define pinstCBodyTintWnd_x                                        0xE50480
#define pinstCServerListWnd_x                                      0xE50484
#define pinstCAvaZoneWnd_x                                         0xE50490
#define pinstCBlockedBuffWnd_x                                     0xE50494
#define pinstCBlockedPetBuffWnd_x                                  0xE50498
#define pinstCInvSlotMgr_x                                         0xE504DC
#define pinstCContainerMgr_x                                       0xE504E0
#define pinstCAdventureLeaderboardWnd_x                            0x10A31F0
#define pinstCAdventureRequestWnd_x                                0x10A3268
#define pinstCAltStorageWnd_x                                      0x10A3548
#define pinstCAdventureStatsWnd_x                                  0x10A32E0
#define pinstCBarterMerchantWnd_x                                  0x10A4130
#define pinstCBarterSearchWnd_x                                    0x10A41A8
#define pinstCBarterWnd_x                                          0x10A4220
#define pinstCChatWindowManager_x                                  0x10A48B0
#define pinstCDynamicZoneWnd_x                                     0x10A4D60
#define pinstCEQMainWnd_x                                          0x10A4EF8
#define pinstCFellowshipWnd_x                                      0x10A4CF4
#define pinstCFindLocationWnd_x                                    0x10A51C8
#define pinstCGroupSearchWnd_x                                     0x10A5498
#define pinstCGroupWnd_x                                           0x10A5510
#define pinstCGuildBankWnd_x                                       0x10A5588
#define pinstCGuildMgmtWnd_x                                       0x10A7678
#define pinstCHotButtonWnd_x                                       0x10A7774
#define pinstCHotButtonWnd1_x                                      0x10A7774
#define pinstCHotButtonWnd2_x                                      0x10A7778
#define pinstCHotButtonWnd3_x                                      0x10A777C
#define pinstCHotButtonWnd4_x                                      0x10A77A0
#define pinstCItemDisplayManager_x                                 0x10A7A98
#define pinstCItemExpTransferWnd_x                                 0x10A7B14
#define pinstCLFGuildWnd_x                                         0x10A7DF0
#define pinstCMIZoneSelectWnd_x                                    0x10A83D8
#define pinstCConfirmationDialog_x                                 0x10A8AE0
#define pinstCPopupWndManager_x                                    0x10A8AE0
#define pinstCProgressionSelectionWnd_x                            0x10A8BD0
#define pinstCPvPStatsWnd_x                                        0x10A8CC0
#define pinstCLargeDialogWnd_x                                     0x10A93C8
#define pinstCTaskWnd_x                                            0x10AA7C0
#define pinstCTaskSomething_x                                      0xD1E550
#define pinstCTaskTemplateSelectWnd_x                              0x10AA748
#define pinstCTipWndOFDAY_x                                        0x10AA928
#define pinstCTipWndCONTEXT_x                                      0x10AA92C
#define pinstCTitleWnd_x                                           0x10AA9A8
#define pinstCContextMenuManager_x                                 0x170E3D4
#define pinstCVoiceMacroWnd_x                                      0xF97678
#define pinstCHtmlWnd_x                                            0xF97768
#define pinstIconCache_x                                           0x10A4ECC
#define pinstCTradeskillWnd_x                                      0x10AAAA8
#define pinstCAdvancedLootWnd_x                                    0xE504D0
#define pinstRewardSelectionWnd_x                                  0x10A91E8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x538040
#define __ConvertItemTags_x                                        0x5258A0
#define __ExecuteCmd_x                                             0x510230
#define __EQGetTime_x                                              0x88CDB0
#define __get_melee_range_x                                        0x516E00
#define __GetGaugeValueFromEQ_x                                    0x79E8C0
#define __GetLabelFromEQ_x                                         0x79FB10
#define __ToggleKeyRingItem_x                                      0x480270
#define __GetXTargetType_x                                         0x91D890
#define __LoadFrontEnd_x                                           0x62D610
#define __NewUIINI_x                                               0x79E290
#define __ProcessGameEvents_x                                      0x5718D0
#define __ProcessMouseEvent_x                                      0x571070
#define CrashDetected_x                                            0x62EFD0
#define wwsCrashReportCheckForUploader_x                           0x7EC480
#define __AppCrashWrapper_x                                        0xC47834
#define __pCrashHandler_x                                          0x10B7958
#define __CrashHandler_x                                           0x7EBF10
#define wwsCrashReportPlatformLaunchUploader_x                     0x7EE6B0
#define DrawNetStatus_x                                            0x5A7C70
#define Util__FastTime_x                                           0x88CA50
#define Expansion_HoT_x                                            0xF12100
#define __HelpPath_x                                               0xF95800
#define __STMLToText_x                                             0x8D2CB0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4205E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B380
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B160

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C7820
#define AltAdvManager__IsAbilityReady_x                            0x4C7890
#define AltAdvManager__GetAAById_x                                 0x4C7D80
#define AltAdvManager__CanTrainAbility_x                           0x4C89B0
#define AltAdvManager__CanSeeAbility_x                             0x4C8570

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463790
#define CharacterZoneClient__MakeMeVisible_x                       0x4681A0
#define CharacterZoneClient__IsStackBlocked_x                      0x447B70
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x447030
#define CharacterZoneClient__GetItemCountWorn_x                    0x461520
#define CharacterZoneClient__GetItemCountInInventory_x             0x461600
#define CharacterZoneClient__GetCursorItemCount_x                  0x4616E0
#define CharacterZoneClient__FindAffectSlot_x                      0x44D090

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x65CDE0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66AEB0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x586F70
#define CButtonWnd__CButtonWnd_x                                   0x8C7050

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x686390
#define CChatManager__InitContextMenu_x                            0x686F10
#define CChatManager__FreeChatWindow_x                             0x685E70
#define CChatManager__GetLockedActiveChatWindow_x                  0x68B6C0
#define CChatManager__SetLockedActiveChatWindow_x                  0x686360
// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D1010
#define CContextMenu__dCContextMenu_x                              0x8D1220
#define CContextMenu__AddMenuItem_x                                0x8D1230
#define CContextMenu__RemoveMenuItem_x                             0x8D1520
#define CContextMenu__RemoveAllMenuItems_x                         0x8D1540
#define CContextMenuManager__AddMenu_x                             0x8BD5C0
#define CContextMenuManager__RemoveMenu_x                          0x8BD950
#define CContextMenuManager__PopupMenu_x                           0x8BDDA0
#define CContextMenuManager__Flush_x                               0x8BD630
#define CContextMenuManager__GetMenu_x                             0x416A60
#define CContextMenu__CheckMenuItem_x                              0x8D15C0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x871240
#define CChatService__GetFriendName_x                              0x871250

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x68C210
#define CChatWindow__Clear_x                                       0x68BDE0
#define CChatWindow__WndNotification_x                             0x68C750

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C1420
#define CComboWnd__Draw_x                                          0x8C1630
#define CComboWnd__GetCurChoice_x                                  0x8C11D0
#define CComboWnd__GetListRect_x                                   0x8C18D0
#define CComboWnd__GetTextRect_x                                   0x8C1490
#define CComboWnd__InsertChoice_x                                  0x8C1940
#define CComboWnd__SetColors_x                                     0x8C1160
#define CComboWnd__SetChoice_x                                     0x8C1190
#define CComboWnd__GetItemCount_x                                  0x8C11C0
#define CComboWnd__GetCurChoiceText_x                              0x8C1210

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x695960
#define CContainerWnd__vftable_x                                   0xAD04E8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B5D10
#define CDisplay__GetClickedActor_x                                0x4AE640
#define CDisplay__GetUserDefinedColor_x                            0x4AD220
#define CDisplay__GetWorldFilePath_x                               0x4AC670
#define CDisplay__is3dON_x                                         0x4ABB00
#define CDisplay__ReloadUI_x                                       0x4C1280
#define CDisplay__WriteTextHD2_x                                   0x4B20D0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E76D0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D5540
#define CEditWnd__GetCharIndexPt_x                                 0x8D65E0
#define CEditWnd__GetDisplayString_x                               0x8D56F0
#define CEditWnd__GetHorzOffset_x                                  0x8D5A30
#define CEditWnd__GetLineForPrintableChar_x                        0x8D60A0
#define CEditWnd__GetSelStartPt_x                                  0x8D68A0
#define CEditWnd__GetSTMLSafeText_x                                0x8D5BD0
#define CEditWnd__PointFromPrintableChar_x                         0x8D6190
#define CEditWnd__SelectableCharFromPoint_x                        0x8D6310
#define CEditWnd__SetEditable_x                                    0x8D5BA0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x558FA0
#define CEverQuest__ClickedPlayer_x                                0x552960
#define CEverQuest__CreateTargetIndicator_x                        0x553850
#define CEverQuest__DeleteTargetIndicator_x                        0x5538D0
#define CEverQuest__DoTellWindow_x                                 0x472E20
#define CEverQuest__OutputTextToLog_x                              0x472A80
#define CEverQuest__DropHeldItemOnGround_x                         0x5695C0
#define CEverQuest__dsp_chat_x                                     0x473160
#define CEverQuest__trimName_x                                     0x54F2B0
#define CEverQuest__Emote_x                                        0x567910
#define CEverQuest__EnterZone_x                                    0x562900
#define CEverQuest__GetBodyTypeDesc_x                              0x54CD10
#define CEverQuest__GetClassDesc_x                                 0x5560E0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5566E0
#define CEverQuest__GetDeityDesc_x                                 0x54D5F0
#define CEverQuest__GetLangDesc_x                                  0x54D0A0
#define CEverQuest__GetRaceDesc_x                                  0x5568A0
#define CEverQuest__InterpretCmd_x                                 0x55A720
#define CEverQuest__LeftClickedOnPlayer_x                          0x56DF90
#define CEverQuest__LMouseUp_x                                     0x570090
#define CEverQuest__RightClickedOnPlayer_x                         0x56EAA0
#define CEverQuest__RMouseUp_x                                     0x56FAF0
#define CEverQuest__SetGameState_x                                 0x553220
#define CEverQuest__UPCNotificationFlush_x                         0x54AB20
#define CEverQuest__IssuePetCommand_x                              0x55B100

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A67E0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A6840
#define CGaugeWnd__Draw_x                                          0x6A6C70

// CGuild
#define CGuild__FindMemberByName_x                                 0x437380
#define CGuild__GetGuildName_x                                     0x437850
#define CGuild__GetGuildIndex_x                                    0x438A20

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C2D30

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6CFEB0
#define CInvSlotMgr__MoveItem_x                                    0x6D0D60
#define CInvSlotMgr__SelectSlot_x                                  0x6CFF60

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6CF360
#define CInvSlot__SliderComplete_x                                 0x6CCB70
#define CInvSlot__GetItemBase_x                                    0x6CBFF0
#define CInvSlot__UpdateItem_x                                     0x6CC570

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D21B0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6D32D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79A2C0
#define CItemDisplayWnd__UpdateStrings_x                           0x6D4340
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6E0DD0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6E1300
#define CItemDisplayWnd__SetItem_x                                 0x6E6DE0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7D14B0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6DA910

// CLabel 
#define CLabel__Draw_x                                             0x6EDA80

// CListWnd
#define CListWnd__CListWnd_x                                       0x8AD010
#define CListWnd__dCListWnd_x                                      0x8AE230
#define CListWnd__AddColumn_x                                      0x8AE1D0
#define CListWnd__AddColumn1_x                                     0x8AD870
#define CListWnd__AddLine_x                                        0x8AD2D0
#define CListWnd__AddString_x                                      0x8AD4F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8AA280
#define CListWnd__CalculateVSBRange_x                              0x8AC4D0
#define CListWnd__ClearSel_x                                       0x8A9590
#define CListWnd__ClearAllSel_x                                    0x8A9540
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8ACEA0
#define CListWnd__Compare_x                                        0x8AAE00
#define CListWnd__Draw_x                                           0x8AC0D0
#define CListWnd__DrawColumnSeparators_x                           0x8ABF60
#define CListWnd__DrawHeader_x                                     0x8A9850
#define CListWnd__DrawItem_x                                       0x8AB490
#define CListWnd__DrawLine_x                                       0x8ABC00
#define CListWnd__DrawSeparator_x                                  0x8AC000
#define CListWnd__EnableLine_x                                     0x8A9770
#define CListWnd__EnsureVisible_x                                  0x8AA3E0
#define CListWnd__ExtendSel_x                                      0x8AB3A0
#define CListWnd__GetColumnMinWidth_x                              0x8A8F40
#define CListWnd__GetColumnWidth_x                                 0x8A8E70
#define CListWnd__GetCurSel_x                                      0x8A8630
#define CListWnd__GetItemAtPoint_x                                 0x8AA680
#define CListWnd__GetItemAtPoint1_x                                0x8AA6F0
#define CListWnd__GetItemData_x                                    0x8A8980
#define CListWnd__GetItemHeight_x                                  0x8A9ED0
#define CListWnd__GetItemIcon_x                                    0x8A8B70
#define CListWnd__GetItemRect_x                                    0x8AA4C0
#define CListWnd__GetItemText_x                                    0x8A8A20
#define CListWnd__GetSelList_x                                     0x8AD760
#define CListWnd__GetSeparatorRect_x                               0x8AAD20
#define CListWnd__InsertLine_x                                     0x8AD6D0
#define CListWnd__RemoveLine_x                                     0x8AD6E0
#define CListWnd__SetColors_x                                      0x8A8780
#define CListWnd__SetColumnJustification_x                         0x8A91D0
#define CListWnd__SetColumnWidth_x                                 0x8A8EF0
#define CListWnd__SetCurSel_x                                      0x8A8670
#define CListWnd__SetItemColor_x                                   0x8ACB90
#define CListWnd__SetItemData_x                                    0x8A95F0
#define CListWnd__SetItemText_x                                    0x8AC9D0
#define CListWnd__ShiftColumnSeparator_x                           0x8AC860
#define CListWnd__Sort_x                                           0x8AE330
#define CListWnd__ToggleSel_x                                      0x8A94C0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x706A00

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x727FD0
#define CMerchantWnd__RequestBuyItem_x                             0x72F080
#define CMerchantWnd__RequestSellItem_x                            0x72FB50
#define CMerchantWnd__SelectRecoverySlot_x                         0x728280
#define CMerchantWnd__SelectBuySellSlot_x                          0x727480
#define CMerchantWnd__ActualSelect_x                               0x72BF60

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x83FEF0
#define CPacketScrambler__hton_x                                   0x83FF00

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8CBF30
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8CC010
#define CSidlManager__CreateLabel_x                                0x7901B0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8CA4D0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8CC2F0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x6541A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x6540C0
#define CSidlScreenWnd__ConvertToRes_x                             0x8E75B0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8C3DE0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C4F80
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C5030
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C4500
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8C3790
#define CSidlScreenWnd__EnableIniStorage_x                         0x8C2EE0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8C3980
#define CSidlScreenWnd__Init1_x                                    0x8C4C50
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C3E90
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8C30A0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C4740
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C2B40
#define CSidlScreenWnd__StoreIniVis_x                              0x8C2E90
#define CSidlScreenWnd__WndNotification_x                          0x8C49D0
#define CSidlScreenWnd__GetChildItem_x                             0x8C2FB0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B6820
#define CSidlScreenWnd__m_layoutCopy_x                             0x170E438

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F2F50
#define CSkillMgr__GetSkillCap_x                                   0x5F3130
#define CSkillMgr__GetNameToken_x                                  0x5F2B70

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E6850
#define CSliderWnd__SetValue_x                                     0x8E6A20
#define CSliderWnd__SetNumTicks_x                                  0x8E71A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x797F20

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8E2210
#define CStmlWnd__CalculateHSBRange_x                              0x8DA730
#define CStmlWnd__CalculateVSBRange_x                              0x8DA7C0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8DA940
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8DB220
#define CStmlWnd__ForceParseNow_x                                  0x8E2B60
#define CStmlWnd__GetNextTagPiece_x                                0x8DB120
#define CStmlWnd__GetSTMLText_x                                    0x68B680
#define CStmlWnd__GetVisibleText_x                                 0x8DBC70
#define CStmlWnd__InitializeWindowVariables_x                      0x8DE000
#define CStmlWnd__MakeStmlColorTag_x                               0x8D9A30
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D9A90
#define CStmlWnd__SetSTMLText_x                                    0x8DF860
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E1EB0
#define CStmlWnd__UpdateHistoryString_x                            0x8DCBB0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8D9140
#define CTabWnd__DrawCurrentPage_x                                 0x8D89D0
#define CTabWnd__DrawTab_x                                         0x8D8790
#define CTabWnd__GetCurrentPage_x                                  0x8D8D80
#define CTabWnd__GetPageInnerRect_x                                0x8D8480
#define CTabWnd__GetTabInnerRect_x                                 0x8D8680
#define CTabWnd__GetTabRect_x                                      0x8D8550
#define CTabWnd__InsertPage_x                                      0x8D9430
#define CTabWnd__SetPage_x                                         0x8D8DB0
#define CTabWnd__SetPageRect_x                                     0x8D9080
#define CTabWnd__UpdatePage_x                                      0x8D93D0
#define CTabWnd__GetPageFromTabIndex_x                             0x8D86E0
#define CTabWnd__GetCurrentTabIndex_x                              0x8D8410

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6D3480
#define CPageWnd__SetTabText_x                                     0x8F05A0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432FA0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C0DD0
#define CTextureFont__GetTextExtent_x                              0x8C0B30

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x62B8B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8EC9E0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A66D0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402A00
#define CXStr__CXStr1_x                                            0x4E8150
#define CXStr__CXStr3_x                                            0x889D30
#define CXStr__dCXStr_x                                            0x8B5300
#define CXStr__operator_equal_x                                    0x889EA0
#define CXStr__operator_equal1_x                                   0x889EF0
#define CXStr__operator_plus_equal1_x                              0x88AFF0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B5A00
#define CXWnd__Center_x                                            0x8BBBA0
#define CXWnd__ClrFocus_x                                          0x8B55F0
#define CXWnd__Destroy_x                                           0x8BC690
#define CXWnd__DoAllDrawing_x                                      0x8BB7F0
#define CXWnd__DrawChildren_x                                      0x8BB990
#define CXWnd__DrawColoredRect_x                                   0x8B5DF0
#define CXWnd__DrawTooltip_x                                       0x8B60A0
#define CXWnd__DrawTooltipAtPoint_x                                0x8BA760
#define CXWnd__GetBorderFrame_x                                    0x8B6510
#define CXWnd__GetChildWndAt_x                                     0x8BC570
#define CXWnd__GetClientClipRect_x                                 0x8B62C0
#define CXWnd__GetScreenClipRect_x                                 0x8BAE60
#define CXWnd__GetScreenRect_x                                     0x8B66D0
#define CXWnd__GetTooltipRect_x                                    0x8B5F30
#define CXWnd__GetWindowTextA_x                                    0x424540
#define CXWnd__IsActive_x                                          0x8B1010
#define CXWnd__IsDescendantOf_x                                    0x8B6450
#define CXWnd__IsReallyVisible_x                                   0x8B9780
#define CXWnd__IsType_x                                            0x8E9220
#define CXWnd__Move_x                                              0x8B8F10
#define CXWnd__Move1_x                                             0x8BB4B0
#define CXWnd__ProcessTransition_x                                 0x8B59A0
#define CXWnd__Refade_x                                            0x8B5780
#define CXWnd__Resize_x                                            0x8B6790
#define CXWnd__Right_x                                             0x8BAC60
#define CXWnd__SetFocus_x                                          0x8B8060
#define CXWnd__SetFont_x                                           0x8B5640
#define CXWnd__SetKeyTooltip_x                                     0x8B69F0
#define CXWnd__SetMouseOver_x                                      0x8BB1A0
#define CXWnd__StartFade_x                                         0x8B5A50
#define CXWnd__GetChildItem_x                                      0x8BB0E0
#define CXWnd__SetParent_x                                         0x8BC520

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B28C0
#define CXWndManager__DrawWindows_x                                0x8B2500
#define CXWndManager__GetKeyboardFlags_x                           0x8B0B40
#define CXWndManager__HandleKeyboardMsg_x                          0x8B14B0
#define CXWndManager__RemoveWnd_x                                  0x8B11A0

// CDBStr
#define CDBStr__GetString_x                                        0x4AA020

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E100
#define EQ_Character__Cur_HP_x                                     0x462D90
#define EQ_Character__Cur_Mana_x                                   0x456850
#define EQ_Character__GetAACastingTimeModifier_x                   0x447340
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F590
#define EQ_Character__GetFocusRangeModifier_x                      0x43F5F0
#define EQ_Character__GetHPRegen_x                                 0x465FA0
#define EQ_Character__GetEnduranceRegen_x                          0x4621B0
#define EQ_Character__GetManaRegen_x                               0x466540
#define EQ_Character__Max_Endurance_x                              0x5B9E70
#define EQ_Character__Max_HP_x                                     0x4594D0
#define EQ_Character__Max_Mana_x                                   0x5B9CA0
#define EQ_Character__doCombatAbility_x                            0x5B7390
#define EQ_Character__UseSkill_x                                   0x46D220
#define EQ_Character__GetConLevel_x                                0x5AC2F0
#define EQ_Character__IsExpansionFlag_x                            0x423A90
#define EQ_Character__TotalEffect_x                                0x44B3A0
#define EQ_Character__GetPCSpellAffect_x                           0x447740
#define EQ_Character__SpellDuration_x                              0x445640
#define EQ_Character__FindItemByRecord_x                           0x4601F0
#define EQ_Character__GetAdjustedSkill_x                           0x463540
#define EQ_Character__GetBaseSkill_x                               0x4593B0

//ProfileManager_
#define ProfileManager__GetCurrentProfile_x                        0x85CCF0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5C1B30

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x442970
#define CCharacterSelect__EnterWorld_x                             0x442140
#define CCharacterSelect__Quit_x                                   0x440D20

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x58C770
#define EQ_Item__CreateItemTagString_x                             0x83E8A0
#define EQ_Item__IsStackable_x                                     0x8342B0
#define EQ_Item__GetImageNum_x                                     0x836D60
#define EQ_Item__CreateItemClient_x                                0x58D340
#define EQ_Item__GetItemValue_x                                    0x83D600
#define EQ_Item__ValueSellMerchant_x                               0x83FB50
#define EQ_Item__IsKeyRingItem_x                                   0x834D00
#define EQ_Item__CanGoInBag_x                                      0x58C900
#define EQ_Item__GetMaxItemCount_x                                 0x8341A0
#define EQ_Item__GetHeldItem_x                                     0x835B50
#define EQ_Item__GetAugmentFitBySlot_x                             0x83F970

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C9DB0
#define EQ_LoadingS__Array_x                                       0xBE9EB0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BC210
#define EQ_PC__GetAlternateAbilityId_x                             0x847EA0
#define EQ_PC__GetCombatAbility_x                                  0x847F30
#define EQ_PC__GetCombatAbilityTimer_x                             0x842D00
#define EQ_PC__GetItemRecastTimer_x                                0x5B5A50
#define EQ_PC__HasLoreItem_x                                       0x5AF900
#define EQ_PC__AlertInventoryChanged_x                             0x5AC2C0
#define EQ_PC__GetPcZoneClient_x                                   0x5D5FD0
#define EQ_PC__RemoveMyAffect_x                                    0x5B4F20
#define EQ_PC__GetKeyRingItems_x                                   0x843120
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x855620
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x849E20

// EQItemList 
#define EQItemList__EQItemList_x                                   0x514EB0
#define EQItemList__add_object_x                                   0x5419C0
#define EQItemList__add_item_x                                     0x514DF0
#define EQItemList__delete_item_x                                  0x5152A0
#define EQItemList__FreeItemList_x                                 0x5151A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A9310

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C18D0
#define EQPlayer__dEQPlayer_x                                      0x5C9E90
#define EQPlayer__DoAttack_x                                       0x5DBEC0
#define EQPlayer__EQPlayer_x                                       0x5CC5A0
#define EQPlayer__SetNameSpriteState_x                             0x5C6DE0
#define EQPlayer__SetNameSpriteTint_x                              0x5C2CE0
#define PlayerBase__HasProperty_j_x                                0x91A070
#define EQPlayer__IsTargetable_x                                   0x91A310
#define EQPlayer__CanSee_x                                         0x91A870
#define PlayerZoneClient__ChangeHeight_x                           0x5DBD80
#define EQPlayer__CanSeeTargetIndicator_x                          0x91A960
#define PlayerBase__GetVisibilityLineSegment_x                     0x91A600

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D0620
#define EQPlayerManager__GetSpawnByName_x                          0x5D0A80
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D0650

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x592800
#define KeypressHandler__AttachKeyToEqCommand_x                    0x592840
#define KeypressHandler__ClearCommandStateArray_x                  0x5923F0
#define KeypressHandler__HandleKeyDown_x                           0x590D50
#define KeypressHandler__HandleKeyUp_x                             0x591070
#define KeypressHandler__SaveKeymapping_x                          0x5924C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6FF390
#define MapViewMap__SaveEx_x                                       0x7026C0

#define PlayerPointManager__GetAltCurrency_x                       0x85AE10

// StringTable 
#define StringTable__getString_x                                   0x855950

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B9900
#define PcZoneClient__RemovePetEffect_x                            0x5B5F20
#define PcZoneClient__HasAlternateAbility_x                        0x5B68C0
#define PcZoneClient__GetCurrentMod_x                              0x458870
#define PcZoneClient__GetModCap_x                                  0x455FD0
#define PcZoneClient__CanEquipItem_x                               0x5B6E70
#define PcZoneClient__GetItemByID_x                                0x5BB6F0
#define PcZoneClient__GetItemByItemClass_x                         0x5BC130

//Doors
#define EQSwitch__UseSwitch_x                                      0x549390

//IconCache
#define IconCache__GetIcon_x                                       0x69BF60

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x692CE0
#define CContainerMgr__CloseContainer_x                            0x693500

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7601D0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5859D0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E4020
#define EQ_Spell__SpellAffects_x                                   0x4E16D0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4E1740
#define CharacterZoneClient__CalcAffectChange_x                    0x446770
#define CLootWnd__LootAll_x                                        0x6F4CE0
#define CLootWnd__RequestLootSlot_x                                0x6F54F0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7A7170
#define CTargetWnd__WndNotification_x                              0x7A6C60
#define CTargetWnd__RefreshTargetBuffs_x                           0x7A7350

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7AC260

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4DCCF0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x498BC0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8D4B70
#define CSidlManager__FindAnimation1_x                             0x8C9F00

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D1530
#define CAltAbilityData__GetMercMaxRank_x                          0x4D14E0
#define CAltAbilityData__GetMaxRank_x                              0x4C5EB0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5832C0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x454FB0
#define CharacterBase__CreateItemGlobalIndex_x                     0x471FF0
#define CharacterBase__CreateItemIndex_x                           0x50E350
#define CharacterBase__GetItemPossession_x                         0x4401C0
#define CharacterBase__GetItemByGlobalIndex_x                      0x86AF20

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x67D3C0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x67CB20

//messages
#define msg_spell_worn_off_x                                       0x4EBBB0
#define msg_new_text_x                                             0x4F5020
#define msgTokenTextParam_x                                        0x4F19D0

//SpellManager
#define SpellManager__vftable_x                                    0xAAD010
#define SpellManager__SpellManager_x                               0x47AEE0
#define Spellmanager__CheckSpellRequirementAssociations_x          0x5F9E00

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x91E3B0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E8120
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43AD10
#define ItemGlobalIndex__IsEquippedLocation_x                      0x444FE0
#define ItemGlobalIndex__IsValidIndex_x                            0x454840

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x868D40
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x867C80

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6EDCD0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x697B70
#define CCursorAttachment__Deactivate_x                            0x6970B0
