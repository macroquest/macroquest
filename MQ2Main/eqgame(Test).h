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
#define __ExpectedVersionDate                                     "Nov 18 2016"
#define __ExpectedVersionTime                                     "10:25:23"
#define __ActualVersionDate_x                                      0xAD1630
#define __ActualVersionTime_x                                      0xAD163C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x5A0CF0
#define __MemChecker1_x                                            0x895F70
#define __MemChecker2_x                                            0x637250
#define __MemChecker3_x                                            0x6371A0
#define __MemChecker4_x                                            0x7E9DC0
#define __EncryptPad0_x                                            0xC75450
#define __EncryptPad1_x                                            0xE01A60
#define __EncryptPad2_x                                            0xCBE250
#define __EncryptPad3_x                                            0xCBDE50
#define __EncryptPad4_x                                            0xDD7A30
#define __EncryptPad5_x                                            0x11B2C98
#define __AC1_x                                                    0x7A94A5
#define __AC2_x                                                    0x55AB27
#define __AC3_x                                                    0x558CC0
#define __AC4_x                                                    0x56B4A0
#define __AC5_x                                                    0x57E1FB
#define __AC6_x                                                    0x581DAE
#define __AC7_x                                                    0x57886C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E5620

// Direct Input
#define DI8__Main_x                                                0x11B2C70
#define DI8__Keyboard_x                                            0x11B2C74
#define DI8__Mouse_x                                               0x11B2C78
#define DI8__Mouse_Copy_x                                          0x102135C
#define DI8__Mouse_Check_x                                         0x10AAB5C
#define __Attack_x                                                 0x10A5843
#define __Autofire_x                                               0x10A5844
#define __BindList_x                                               0xC36D90
#define g_eqCommandStates_x                                        0x10103E8
#define __Clicks_x                                                 0x1021418
#define __CommandList_x                                            0xC3B190
#define __CurrentMapLabel_x                                        0x11B86F8
#define __CurrentSocial_x                                          0xBE9194
#define __DoAbilityList_x                                          0x1057AF8
#define __do_loot_x                                                0x520020
#define __DrawHandler_x                                            0x181F5BC
#define __GroupCount_x                                             0x10119B2

#define __Guilds_x                                                 0x10175C8
#define __gWorld_x                                                 0x1013E6C
#define __HotkeyPage_x                                             0x109E4F8
#define __HWnd_x                                                   0x10AAB78
#define __InChatMode_x                                             0x1021344
#define __LastTell_x                                               0x10231F4
#define __LMouseHeldTime_x                                         0x1021484
#define __Mouse_x                                                  0x11B2C7C
#define __MouseLook_x                                              0x10213DE
#define __MouseEventTime_x                                         0x10A6044
#define __gpbCommandEvent_x                                        0x1013F34
#define __NetStatusToggle_x                                        0x10213E1
#define __PCNames_x                                                0x1022810
#define __RangeAttackReady_x                                       0x102254C
#define __RMouseHeldTime_x                                         0x1021480
#define __RunWalkState_x                                           0x1021348
#define __ScreenMode_x                                             0xF600E8
#define __ScreenX_x                                                0x10212FC
#define __ScreenY_x                                                0x10212F8
#define __ScreenXMax_x                                             0x1021300
#define __ScreenYMax_x                                             0x1021304
#define __ServerHost_x                                             0x10118FC
#define __ServerName_x                                             0x1057AB8
#define __ShiftKeyDown_x                                           0x10219D8
#define __ShowNames_x                                              0x102270C
#define __Socials_x                                                0x1057BB8
#define __SubscriptionType_x                                       0x11E6704
#define __TargetAggroHolder_x                                      0x11BA934
#define __ZoneType_x                                               0x10217DC
#define __GroupAggro_x                                             0x11BA974
#define __LoginName_x                                              0x10A9754
#define __Inviter_x                                                0x10A57C0
#define __AttackOnAssist_x                                         0x10226C8
#define __UseTellWindows_x                                         0x10229A8

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x1013F58
#define instEQZoneInfo_x                                           0x10215D4
#define instKeypressHandler_x                                      0x10A6028
#define pinstActiveBanker_x                                        0x1013F10
#define pinstActiveCorpse_x                                        0x1013F14
#define pinstActiveGMaster_x                                       0x1013F18
#define pinstActiveMerchant_x                                      0x1013F0C
#define pinstAggroInfo_x                                           0xE1DB48
#define pinstAltAdvManager_x                                       0xF611B0
#define pinstAuraMgr_x                                             0xE2E2B8
#define pinstBandageTarget_x                                       0x1013EF8
#define pinstCamActor_x                                            0xF60B00
#define pinstCDBStr_x                                              0xF6007C
#define pinstCDisplay_x                                            0x1013F20
#define pinstCEverQuest_x                                          0x11B2DF0
#define pinstCharData_x                                            0x1013EDC
#define pinstCharSpawn_x                                           0x1013F04
#define pinstControlledMissile_x                                   0x1013ED8
#define pinstControlledPlayer_x                                    0x1013F04
#define pinstCSidlManager_x                                        0x181E9AC
#define pinstCXWndManager_x                                        0x181E9A4
#define instDynamicZone_x                                          0x1021190
#define pinstDZMember_x                                            0x10212A0
#define pinstDZTimerInfo_x                                         0x10212A4
#define pinstEQItemList_x                                          0x1010638
#define pinstEQObjectList_x                                        0x10113AC
#define instEQMisc_x                                               0xC0FDD0
#define pinstEQSoundManager_x                                      0xF61780
#define instExpeditionLeader_x                                     0x10211DA
#define instExpeditionName_x                                       0x102121A
#define pinstGroup_x                                               0x10119AE
#define pinstImeManager_x                                          0x181E9B0
#define pinstLocalPlayer_x                                         0x1013EF0
#define pinstMercenaryData_x                                       0x10A66A8
#define pinstMercenaryStats_x                                      0x11BAA80
#define pinstMercAltAbilities_x                                    0xF61538
#define pinstModelPlayer_x                                         0x1013F1C
#define pinstPCData_x                                              0x1013EDC
#define pinstSkillMgr_x                                            0x10A7510
#define pinstSpawnManager_x                                        0x10A6DF8
#define pinstSpellManager_x                                        0x10A7658
#define pinstSpellSets_x                                           0x109E55C
#define pinstStringTable_x                                         0x1013E84
#define pinstSwitchManager_x                                       0x1011540
#define pinstTarget_x                                              0x1013F08
#define pinstTargetObject_x                                        0x1013EE0
#define pinstTargetSwitch_x                                        0x1013EE4
#define pinstTaskMember_x                                          0xF5FFC8
#define pinstTrackTarget_x                                         0x1013EFC
#define pinstTradeTarget_x                                         0x1013EEC
#define instTributeActive_x                                        0xC0FDF5
#define pinstViewActor_x                                           0xF60AFC
#define pinstWorldData_x                                           0x1013EC0
#define pinstZoneAddr_x                                            0x1021874
#define pinstPlayerPath_x                                          0x10A6E58
#define pinstTargetIndicator_x                                     0x10A77F0
#define pinstCTargetManager_x                                      0x10A7850

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAchievementsWnd_x                                    0xF60A74
#define pinstCTextOverlay_x                                        0xE1E040
#define pinstCAudioTriggersWindow_x                                0xE1DED0
#define pinstCCharacterSelect_x                                    0xF6098C
#define pinstCFacePick_x                                           0xF6073C
#define pinstCNoteWnd_x                                            0xF60944
#define pinstCBookWnd_x                                            0xF6094C
#define pinstCPetInfoWnd_x                                         0xF60950
#define pinstCTrainWnd_x                                           0xF60954
#define pinstCSkillsWnd_x                                          0xF60958
#define pinstCSkillsSelectWnd_x                                    0xF6095C
#define pinstCCombatSkillsSelectWnd_x                              0xF60960
#define pinstCFriendsWnd_x                                         0xF60964
#define pinstCAuraWnd_x                                            0xF60968
#define pinstCRespawnWnd_x                                         0xF6096C
#define pinstCBandolierWnd_x                                       0xF60970
#define pinstCPotionBeltWnd_x                                      0xF60974
#define pinstCAAWnd_x                                              0xF60978
#define pinstCGroupSearchFiltersWnd_x                              0xF6097C
#define pinstCLoadskinWnd_x                                        0xF60980
#define pinstCAlarmWnd_x                                           0xF60984
#define pinstCMusicPlayerWnd_x                                     0xF60988
#define pinstCMailWnd_x                                            0xF60990
#define pinstCMailCompositionWnd_x                                 0xF60994
#define pinstCMailAddressBookWnd_x                                 0xF60998
#define pinstCRaidWnd_x                                            0xF609A0
#define pinstCRaidOptionsWnd_x                                     0xF609A4
#define pinstCBreathWnd_x                                          0xF609A8
#define pinstCMapViewWnd_x                                         0xF609AC
#define pinstCMapToolbarWnd_x                                      0xF609B0
#define pinstCEditLabelWnd_x                                       0xF609B4
#define pinstCTargetWnd_x                                          0xF609B8
#define pinstCColorPickerWnd_x                                     0xF609BC
#define pinstCPlayerWnd_x                                          0xF609C0
#define pinstCOptionsWnd_x                                         0xF609C4
#define pinstCBuffWindowNORMAL_x                                   0xF609C8
#define pinstCBuffWindowSHORT_x                                    0xF609CC
#define pinstCharacterCreation_x                                   0xF609D0
#define pinstCCursorAttachment_x                                   0xF609D4
#define pinstCCastingWnd_x                                         0xF609D8
#define pinstCCastSpellWnd_x                                       0xF609DC
#define pinstCSpellBookWnd_x                                       0xF609E0
#define pinstCInventoryWnd_x                                       0xF609E4
#define pinstCBankWnd_x                                            0xF609EC
#define pinstCQuantityWnd_x                                        0xF609F0
#define pinstCLootWnd_x                                            0xF609F4
#define pinstCActionsWnd_x                                         0xF609F8
#define pinstCCombatAbilityWnd_x                                   0xF60A00
#define pinstCMerchantWnd_x                                        0xF60A04
#define pinstCTradeWnd_x                                           0xF60A08
#define pinstCSelectorWnd_x                                        0xF60A0C
#define pinstCBazaarWnd_x                                          0xF60A10
#define pinstCBazaarSearchWnd_x                                    0xF60A14
#define pinstCGiveWnd_x                                            0xF60A30
#define pinstCTrackingWnd_x                                        0xF60A38
#define pinstCInspectWnd_x                                         0xF60A3C
#define pinstCSocialEditWnd_x                                      0xF60A40
#define pinstCFeedbackWnd_x                                        0xF60A44
#define pinstCBugReportWnd_x                                       0xF60A48
#define pinstCVideoModesWnd_x                                      0xF60A4C
#define pinstCTextEntryWnd_x                                       0xF60A54
#define pinstCFileSelectionWnd_x                                   0xF60A58
#define pinstCCompassWnd_x                                         0xF60A5C
#define pinstCPlayerNotesWnd_x                                     0xF60A60
#define pinstCGemsGameWnd_x                                        0xF60A64
#define pinstCTimeLeftWnd_x                                        0xF60A68
#define pinstCPetitionQWnd_x                                       0xF60A84
#define pinstCSoulmarkWnd_x                                        0xF60A88
#define pinstCStoryWnd_x                                           0xF60A8C
#define pinstCJournalTextWnd_x                                     0xF60A90
#define pinstCJournalCatWnd_x                                      0xF60A94
#define pinstCBodyTintWnd_x                                        0xF60A98
#define pinstCServerListWnd_x                                      0xF60A9C
#define pinstCAvaZoneWnd_x                                         0xF60AA8
#define pinstCBlockedBuffWnd_x                                     0xF60AAC
#define pinstCBlockedPetBuffWnd_x                                  0xF60AB0
#define pinstCInvSlotMgr_x                                         0xF60AF4
#define pinstCContainerMgr_x                                       0xF60AF8
#define pinstCAdventureLeaderboardWnd_x                            0x11B37A0
#define pinstCAdventureRequestWnd_x                                0x11B3818
#define pinstCAltStorageWnd_x                                      0x11B3AF8
#define pinstCAdventureStatsWnd_x                                  0x11B3890
#define pinstCBarterMerchantWnd_x                                  0x11B46E0
#define pinstCBarterSearchWnd_x                                    0x11B4758
#define pinstCBarterWnd_x                                          0x11B47D0
#define pinstCChatManager_x                                        0x11B4E60
#define pinstCDynamicZoneWnd_x                                     0x11B5310
#define pinstCEQMainWnd_x                                          0x11B54A8
#define pinstCFellowshipWnd_x                                      0x11B52A4
#define pinstCFindLocationWnd_x                                    0x11B5778
#define pinstCGroupSearchWnd_x                                     0x11B5A48
#define pinstCGroupWnd_x                                           0x11B5AC0
#define pinstCGuildBankWnd_x                                       0x11B5B38
#define pinstCGuildMgmtWnd_x                                       0x11B7C28
#define pinstCHotButtonWnd_x                                       0x11B7D24
#define pinstCHotButtonWnd1_x                                      0x11B7D24
#define pinstCHotButtonWnd2_x                                      0x11B7D28
#define pinstCHotButtonWnd3_x                                      0x11B7D2C
#define pinstCHotButtonWnd4_x                                      0x11B7D50
#define pinstCItemDisplayManager_x                                 0x11B8048
#define pinstCItemExpTransferWnd_x                                 0x11B80C4
#define pinstCLFGuildWnd_x                                         0x11B83A0
#define pinstCMIZoneSelectWnd_x                                    0x11B8988
#define pinstCConfirmationDialog_x                                 0x11B9090
#define pinstCPopupWndManager_x                                    0x11B9090
#define pinstCProgressionSelectionWnd_x                            0x11B9180
#define pinstCPvPStatsWnd_x                                        0x11B9270
#define pinstCLargeDialogWnd_x                                     0x11B9978
#define pinstCTaskWnd_x                                            0x11BAD40
#define pinstCTaskSomething_x                                      0xE2EB70
#define pinstCTaskTemplateSelectWnd_x                              0x11BACC8
#define pinstCTipWndOFDAY_x                                        0x11BAEA8
#define pinstCTipWndCONTEXT_x                                      0x11BAEAC
#define pinstCTitleWnd_x                                           0x11BAF28
#define pinstCContextMenuManager_x                                 0x181E91C
#define pinstCVoiceMacroWnd_x                                      0x10A7C28
#define pinstCHtmlWnd_x                                            0x10A7D18
#define pinstIconCache_x                                           0x11B547C
#define pinstCTradeskillWnd_x                                      0x11BB028
#define pinstCAdvancedLootWnd_x                                    0xF60AE8
#define pinstRewardSelectionWnd_x                                  0x11B9798

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5372B0
#define __ConvertItemTags_x                                        0x524B80
#define __ExecuteCmd_x                                             0x50F3F0
#define __EQGetTime_x                                              0x895C00
#define __get_melee_range_x                                        0x516010
#define __GetGaugeValueFromEQ_x                                    0x7A81E0
#define __GetLabelFromEQ_x                                         0x7A9430
#define __ToggleKeyRingItem_x                                      0x47FCF0
#define __GetXTargetType_x                                         0x926D40
#define __LoadFrontEnd_x                                           0x636920
#define __NewUIINI_x                                               0x7A7BB0
#define __ProcessGameEvents_x                                      0x57A600
#define __ProcessMouseEvent_x                                      0x579DA0
#define CrashDetected_x                                            0x6382E0
#define wwsCrashReportCheckForUploader_x                           0x7F5C50
#define DrawNetStatus_x                                            0x5B08B0
#define Util__FastTime_x                                           0x8958A0
#define Expansion_HoT_x                                            0x10226B8
#define __HelpPath_x                                               0x10A5DB0
#define __STMLToText_x                                             0x8DBC20

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420470
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B210
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41AFF0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C7420
#define AltAdvManager__IsAbilityReady_x                            0x4C7490
#define AltAdvManager__GetAAById_x                                 0x4C7850
#define AltAdvManager__CanTrainAbility_x                           0x4C8150
#define AltAdvManager__CanSeeAbility_x                             0x4C7D10

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463330
#define CharacterZoneClient__MakeMeVisible_x                       0x467CF0
#define CharacterZoneClient__IsStackBlocked_x                      0x4478C0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x446D80
#define CharacterZoneClient__GetItemCountWorn_x                    0x461160
#define CharacterZoneClient__GetItemCountInInventory_x             0x461240
#define CharacterZoneClient__GetCursorItemCount_x                  0x461320

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x666390

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x674660

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58FCC0
#define CButtonWnd__CButtonWnd_x                                   0x8CFEF0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68F740
#define CChatManager__InitContextMenu_x                            0x6902C0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D9F80
#define CContextMenu__dCContextMenu_x                              0x8DA190
#define CContextMenu__AddMenuItem_x                                0x8DA1A0
#define CContextMenu__RemoveMenuItem_x                             0x8DA490
#define CContextMenu__RemoveAllMenuItems_x                         0x8DA4B0
#define CContextMenuManager__AddMenu_x                             0x8C64A0
#define CContextMenuManager__RemoveMenu_x                          0x8C6830
#define CContextMenuManager__PopupMenu_x                           0x8C6C80
#define CContextMenuManager__Flush_x                               0x8C6510
#define CContextMenuManager__GetMenu_x                             0x4168F0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87A750
#define CChatService__GetFriendName_x                              0x87A760

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x695510
#define CChatWindow__Clear_x                                       0x6950F0
#define CChatWindow__WndNotification_x                             0x695A50

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CA2F0
#define CComboWnd__Draw_x                                          0x8CA500
#define CComboWnd__GetCurChoice_x                                  0x8CA0A0
#define CComboWnd__GetListRect_x                                   0x8CA7A0
#define CComboWnd__GetTextRect_x                                   0x8CA360
#define CComboWnd__InsertChoice_x                                  0x8CA810
#define CComboWnd__SetColors_x                                     0x8CA030
#define CComboWnd__SetChoice_x                                     0x8CA060
#define CComboWnd__GetItemCount_x                                  0x8CA090
#define CComboWnd__GetCurChoiceText_x                              0x8CA0E0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69EBE0
#define CContainerWnd__vftable_x                                   0xADB110

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B5810
#define CDisplay__GetClickedActor_x                                0x4AE140
#define CDisplay__GetUserDefinedColor_x                            0x4ACD20
#define CDisplay__GetWorldFilePath_x                               0x4AC170
#define CDisplay__is3dON_x                                         0x4AB600
#define CDisplay__ReloadUI_x                                       0x4C0D80
#define CDisplay__WriteTextHD2_x                                   0x4B1BD0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F05C0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DE4B0
#define CEditWnd__GetCharIndexPt_x                                 0x8DF550
#define CEditWnd__GetDisplayString_x                               0x8DE660
#define CEditWnd__GetHorzOffset_x                                  0x8DE9A0
#define CEditWnd__GetLineForPrintableChar_x                        0x8DF010
#define CEditWnd__GetSelStartPt_x                                  0x8DF810
#define CEditWnd__GetSTMLSafeText_x                                0x8DEB40
#define CEditWnd__PointFromPrintableChar_x                         0x8DF100
#define CEditWnd__SelectableCharFromPoint_x                        0x8DF280
#define CEditWnd__SetEditable_x                                    0x8DEB10

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x55B270
#define CEverQuest__CreateTargetIndicator_x                        0x55C160
#define CEverQuest__DeleteTargetIndicator_x                        0x55C1E0
#define CEverQuest__DoTellWindow_x                                 0x472930
#define CEverQuest__DropHeldItemOnGround_x                         0x5722F0
#define CEverQuest__dsp_chat_x                                     0x472C70
#define CEverQuest__trimName_x                                     0x557BC0
#define CEverQuest__Emote_x                                        0x570640
#define CEverQuest__EnterZone_x                                    0x56B630
#define CEverQuest__GetBodyTypeDesc_x                              0x555620
#define CEverQuest__GetClassDesc_x                                 0x55EEF0
#define CEverQuest__GetClassThreeLetterCode_x                      0x55F4F0
#define CEverQuest__GetDeityDesc_x                                 0x555F00
#define CEverQuest__GetLangDesc_x                                  0x5559B0
#define CEverQuest__GetRaceDesc_x                                  0x55F6B0
#define CEverQuest__InterpretCmd_x                                 0x563450
#define CEverQuest__LeftClickedOnPlayer_x                          0x576CC0
#define CEverQuest__LMouseUp_x                                     0x578DC0
#define CEverQuest__RightClickedOnPlayer_x                         0x5777D0
#define CEverQuest__RMouseUp_x                                     0x578820
#define CEverQuest__SetGameState_x                                 0x55BB30
#define CEverQuest__UPCNotificationFlush_x                         0x553430
#define CEverQuest__IssuePetCommand_x                              0x563E30

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AFA90
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AFAF0
#define CGaugeWnd__Draw_x                                          0x6AFF20

// CGuild
#define CGuild__FindMemberByName_x                                 0x437170
#define CGuild__GetGuildName_x                                     0x437640
#define CGuild__GetGuildIndex_x                                    0x438810

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CBFF0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D91C0
#define CInvSlotMgr__MoveItem_x                                    0x6DA070
#define CInvSlotMgr__SelectSlot_x                                  0x6D9270

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D8660
#define CInvSlot__SliderComplete_x                                 0x6D5E70
#define CInvSlot__GetItemBase_x                                    0x6D52D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DB4D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A3BE0
#define CItemDisplayWnd__UpdateStrings_x                           0x6DD620

// CLabel 
#define CLabel__Draw_x                                             0x6F71D0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B5EB0
#define CListWnd__dCListWnd_x                                      0x8B70C0
#define CListWnd__AddColumn_x                                      0x8B7060
#define CListWnd__AddColumn1_x                                     0x8B6700
#define CListWnd__AddLine_x                                        0x8B6160
#define CListWnd__AddString_x                                      0x8B6380
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B3130
#define CListWnd__CalculateVSBRange_x                              0x8B5380
#define CListWnd__ClearSel_x                                       0x8B2440
#define CListWnd__ClearAllSel_x                                    0x8B23F0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B5D40
#define CListWnd__Compare_x                                        0x8B3CB0
#define CListWnd__Draw_x                                           0x8B4F80
#define CListWnd__DrawColumnSeparators_x                           0x8B4E10
#define CListWnd__DrawHeader_x                                     0x8B2700
#define CListWnd__DrawItem_x                                       0x8B4340
#define CListWnd__DrawLine_x                                       0x8B4AB0
#define CListWnd__DrawSeparator_x                                  0x8B4EB0
#define CListWnd__EnsureVisible_x                                  0x8B3290
#define CListWnd__ExtendSel_x                                      0x8B4250
#define CListWnd__GetColumnMinWidth_x                              0x8B1DF0
#define CListWnd__GetColumnWidth_x                                 0x8B1D20
#define CListWnd__GetCurSel_x                                      0x8B14E0
#define CListWnd__GetItemAtPoint_x                                 0x8B3530
#define CListWnd__GetItemAtPoint1_x                                0x8B35A0
#define CListWnd__GetItemData_x                                    0x8B1830
#define CListWnd__GetItemHeight_x                                  0x8B2D80
#define CListWnd__GetItemIcon_x                                    0x8B1A20
#define CListWnd__GetItemRect_x                                    0x8B3370
#define CListWnd__GetItemText_x                                    0x8B18D0
#define CListWnd__GetSelList_x                                     0x8B65F0
#define CListWnd__GetSeparatorRect_x                               0x8B3BD0
#define CListWnd__RemoveLine_x                                     0x8B6570
#define CListWnd__SetColors_x                                      0x8B1630
#define CListWnd__SetColumnJustification_x                         0x8B2080
#define CListWnd__SetColumnWidth_x                                 0x8B1DA0
#define CListWnd__SetCurSel_x                                      0x8B1520
#define CListWnd__SetItemColor_x                                   0x8B5A30
#define CListWnd__SetItemData_x                                    0x8B24A0
#define CListWnd__SetItemText_x                                    0x8B5870
#define CListWnd__ShiftColumnSeparator_x                           0x8B5700
#define CListWnd__Sort_x                                           0x8B71C0
#define CListWnd__ToggleSel_x                                      0x8B2370

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x710170

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7316C0
#define CMerchantWnd__RequestBuyItem_x                             0x738770
#define CMerchantWnd__RequestSellItem_x                            0x739240
#define CMerchantWnd__SelectRecoverySlot_x                         0x731970
#define CMerchantWnd__SelectBuySellSlot_x                          0x730B70
#define CMerchantWnd__ActualSelect_x                               0x735640

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x849D80
#define CPacketScrambler__hton_x                                   0x849D90

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D4F00
#define CSidlManager__CreateLabel_x                                0x799B90

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65D770
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65D6A0
#define CSidlScreenWnd__ConvertToRes_x                             0x8F04A0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CCC90
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CDE40
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CDEF0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CD3D0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CC640
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CBDA0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CC830
#define CSidlScreenWnd__Init1_x                                    0x8CDB20
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CCD40
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CBF60
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CD610
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CBA00
#define CSidlScreenWnd__StoreIniVis_x                              0x8CBD50
#define CSidlScreenWnd__WndNotification_x                          0x8CD8A0
#define CSidlScreenWnd__GetChildItem_x                             0x8CBE70
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BF630
#define CSidlScreenWnd__m_layoutCopy_x                             0x181E980

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FC4A0
#define CSkillMgr__GetSkillCap_x                                   0x5FC680
#define CSkillMgr__GetNameToken_x                                  0x5FC0C0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8EF770
#define CSliderWnd__SetValue_x                                     0x8EF940
#define CSliderWnd__SetNumTicks_x                                  0x8F00C0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A1840

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EB120
#define CStmlWnd__CalculateHSBRange_x                              0x8E3670
#define CStmlWnd__CalculateVSBRange_x                              0x8E3700
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E3880
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E4160
#define CStmlWnd__ForceParseNow_x                                  0x8EBA70
#define CStmlWnd__GetNextTagPiece_x                                0x8E4060
#define CStmlWnd__GetSTMLText_x                                    0x694990
#define CStmlWnd__GetVisibleText_x                                 0x8E4BB0
#define CStmlWnd__InitializeWindowVariables_x                      0x8E6F40
#define CStmlWnd__MakeStmlColorTag_x                               0x8E2970
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E29D0
#define CStmlWnd__SetSTMLText_x                                    0x8E8790
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EADC0
#define CStmlWnd__UpdateHistoryString_x                            0x8E5AF0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E2090
#define CTabWnd__DrawCurrentPage_x                                 0x8E1920
#define CTabWnd__DrawTab_x                                         0x8E16E0
#define CTabWnd__GetCurrentPage_x                                  0x8E1CD0
#define CTabWnd__GetPageInnerRect_x                                0x8E13D0
#define CTabWnd__GetTabInnerRect_x                                 0x8E15D0
#define CTabWnd__GetTabRect_x                                      0x8E14A0
#define CTabWnd__InsertPage_x                                      0x8E2380
#define CTabWnd__SetPage_x                                         0x8E1D00
#define CTabWnd__SetPageRect_x                                     0x8E1FD0
#define CTabWnd__UpdatePage_x                                      0x8E2320

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432D70

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C9CA0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x634B80

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F58D0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8AF440

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029A0
#define CXStr__CXStr1_x                                            0x43FB80
#define CXStr__CXStr3_x                                            0x892B80
#define CXStr__dCXStr_x                                            0x5FF200
#define CXStr__operator_equal_x                                    0x892CF0
#define CXStr__operator_equal1_x                                   0x892D40
#define CXStr__operator_plus_equal1_x                              0x893E40

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BE7F0
#define CXWnd__Center_x                                            0x8C4AB0
#define CXWnd__ClrFocus_x                                          0x8BE3C0
#define CXWnd__DoAllDrawing_x                                      0x8C4700
#define CXWnd__DrawChildren_x                                      0x8C48A0
#define CXWnd__DrawColoredRect_x                                   0x8BEBD0
#define CXWnd__DrawTooltip_x                                       0x8BEE80
#define CXWnd__DrawTooltipAtPoint_x                                0x8C3650
#define CXWnd__GetBorderFrame_x                                    0x8BF2F0
#define CXWnd__GetChildWndAt_x                                     0x8C5460
#define CXWnd__GetClientClipRect_x                                 0x8BF0A0
#define CXWnd__GetScreenClipRect_x                                 0x8C3D50
#define CXWnd__GetScreenRect_x                                     0x8BF4C0
#define CXWnd__GetTooltipRect_x                                    0x8BED10
#define CXWnd__GetWindowTextA_x                                    0x4243A0
#define CXWnd__IsActive_x                                          0x8B9E70
#define CXWnd__IsDescendantOf_x                                    0x8BF230
#define CXWnd__IsReallyVisible_x                                   0x8C2650
#define CXWnd__IsType_x                                            0x8F2130
#define CXWnd__Move_x                                              0x8C1D30
#define CXWnd__Move1_x                                             0x8C43A0
#define CXWnd__ProcessTransition_x                                 0x8BE790
#define CXWnd__Refade_x                                            0x8BE560
#define CXWnd__Resize_x                                            0x8BF590
#define CXWnd__Right_x                                             0x8C3B50
#define CXWnd__SetFocus_x                                          0x8C0E70
#define CXWnd__SetFont_x                                           0x8BE410
#define CXWnd__SetKeyTooltip_x                                     0x8BF800
#define CXWnd__SetMouseOver_x                                      0x8C4080
#define CXWnd__StartFade_x                                         0x8BE840
#define CXWnd__GetChildItem_x                                      0x8C3FC0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BB710
#define CXWndManager__DrawWindows_x                                0x8BB350
#define CXWndManager__GetKeyboardFlags_x                           0x8B99A0
#define CXWndManager__HandleKeyboardMsg_x                          0x8BA300
#define CXWndManager__RemoveWnd_x                                  0x8BA000

// CDBStr
#define CDBStr__GetString_x                                        0x4A9B40

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44DE70
#define EQ_Character__Cur_HP_x                                     0x4629D0
#define EQ_Character__Cur_Mana_x                                   0x456500
#define EQ_Character__GetAACastingTimeModifier_x                   0x447090
#define EQ_Character__GetCharInfo2_x                               0x866710
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F2F0
#define EQ_Character__GetFocusRangeModifier_x                      0x43F350
#define EQ_Character__Max_Endurance_x                              0x5C2690
#define EQ_Character__Max_HP_x                                     0x459120
#define EQ_Character__Max_Mana_x                                   0x5C24C0
#define EQ_Character__doCombatAbility_x                            0x5BFBB0
#define EQ_Character__UseSkill_x                                   0x46CD70
#define EQ_Character__GetConLevel_x                                0x5B4EC0
#define EQ_Character__IsExpansionFlag_x                            0x4238F0
#define EQ_Character__TotalEffect_x                                0x44B110
#define EQ_Character__GetPCSpellAffect_x                           0x447490
#define EQ_Character__SpellDuration_x                              0x445390
#define EQ_Character__FindItemByRecord_x                           0x45FE50

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x4426C0
#define CCharacterSelect__EnterWorld_x                             0x441E90
#define CCharacterSelect__Quit_x                                   0x440A70

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5954B0
#define EQ_Item__CreateItemTagString_x                             0x8486A0
#define EQ_Item__IsStackable_x                                     0x83DDC0
#define EQ_Item__GetImageNum_x                                     0x840800
#define EQ_Item__CreateItemClient_x                                0x596090
#define EQ_Item__GetItemValue_x                                    0x8473C0
#define EQ_Item__ValueSellMerchant_x                               0x8499D0
#define EQ_Item__IsKeyRingItem_x                                   0x83E820
#define EQ_Item__CanGoInBag_x                                      0x595640
#define EQ_Item__GetMaxItemCount_x                                 0x83DCB0
#define EQ_Item__GetHeldItem_x                                     0x83F610

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C9660
#define EQ_LoadingS__Array_x                                       0xC1C680

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C4BB0
#define EQ_PC__GetAlternateAbilityId_x                             0x851E60
#define EQ_PC__GetCombatAbility_x                                  0x851EF0
#define EQ_PC__GetCombatAbilityTimer_x                             0x84CB90
#define EQ_PC__GetItemTimerValue_x                                 0x5BE260
#define EQ_PC__HasLoreItem_x                                       0x5B83D0
#define EQ_PC__AlertInventoryChanged_x                             0x5B4E90
#define EQ_PC__GetPcZoneClient_x                                   0x5DF220
#define EQ_PC__RemoveMyAffect_x                                    0x5BD6F0
#define EQ_PC__GetKeyRingItems_x                                   0x84CFB0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x514070
#define EQItemList__add_object_x                                   0x53FF30
#define EQItemList__add_item_x                                     0x513FB0
#define EQItemList__delete_item_x                                  0x514460
#define EQItemList__FreeItemList_x                                 0x514360

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A8E90

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5CA210
#define EQPlayer__dEQPlayer_x                                      0x5D30E0
#define EQPlayer__DoAttack_x                                       0x5E5120
#define EQPlayer__EQPlayer_x                                       0x5D57F0
#define EQPlayer__SetNameSpriteState_x                             0x5D0030
#define EQPlayer__SetNameSpriteTint_x                              0x5CB620
#define PlayerBase__HasProperty_j_x                                0x922EC0
#define EQPlayer__IsTargetable_x                                   0x9237C0
#define EQPlayer__CanSee_x                                         0x923CE0
#define PlayerZoneClient__ChangeHeight_x                           0x5E4FE0
#define EQPlayer__CanSeeTargetIndicator_x                          0x923DD0
#define PlayerBase__GetVisibilityLineSegment_x                     0x923A70

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D9860
#define EQPlayerManager__GetSpawnByName_x                          0x5D9CC0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D9890

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59B570
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59B5B0
#define KeypressHandler__ClearCommandStateArray_x                  0x59B160
#define KeypressHandler__HandleKeyDown_x                           0x599AC0
#define KeypressHandler__HandleKeyUp_x                             0x599DE0
#define KeypressHandler__SaveKeymapping_x                          0x59B230

// MapViewMap 
#define MapViewMap__Clear_x                                        0x708B00
#define MapViewMap__SaveEx_x                                       0x70BE30

#define PlayerPointManager__GetAltCurrency_x                       0x864840

// StringTable 
#define StringTable__getString_x                                   0x85F340

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C2120
#define PcZoneClient__RemovePetEffect_x                            0x5BE730
#define PcZoneClient__HasAlternateAbility_x                        0x5BF0D0
#define PcZoneClient__GetCurrentMod_x                              0x4584C0
#define PcZoneClient__GetModCap_x                                  0x455C80
#define PcZoneClient__CanEquipItem_x                               0x5BF680

//Doors
#define EQSwitch__UseSwitch_x                                      0x551CD0

//IconCache
#define IconCache__GetIcon_x                                       0x6A5200

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69BF60
#define CContainerMgr__CloseContainer_x                            0x69C780

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x769960

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58E720

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E3300
#define EQ_Spell__SpellAffects_x                                   0x4E09B0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4E0A20
#define CharacterZoneClient__CalcAffectChange_x                    0x4464C0
#define CLootWnd__LootAll_x                                        0x6FE400
#define CLootWnd__RequestLootSlot_x                                0x6FEC10

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B0640
#define CTargetWnd__WndNotification_x                              0x7B0130
#define CTargetWnd__RefreshTargetBuffs_x                           0x7B0820

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B5890

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4DC070

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x498840

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DDAE0
#define CSidlManager__FindAnimation1_x                             0x8D2E00

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D0CB0
#define CAltAbilityData__GetMercMaxRank_x                          0x4D0C60
#define CAltAbilityData__GetMaxRank_x                              0x4C5AD0

//CTargetRing
#define CTargetRing__Cast_x                                        0x58BFD0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x454C90
#define CharacterBase__CreateItemGlobalIndex_x                     0x471B40
#define CharacterBase__CreateItemIndex_x                           0x50D500
#define CharacterBase__GetItemPossession_x                         0x50E9C0
#define CharacterBase__GetItemByGlobalIndex_x                      0x874860

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6868D0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x686030

//messages
#define msg_spell_worn_off_x                                       0x4EAEF0
#define msg_new_text_x                                             0x4F4490
#define msgTokenTextParam_x                                        0x4F0E40

//SpellManager
#define SpellManager__vftable_x                                    0xAB6FF0
#define SpellManager__SpellManager_x                               0x47A900
#define Spellmanager__CheckSpellRequirementAssociations_x          0x603360

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x927860

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E7490
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43AA70
#define ItemGlobalIndex__IsEquippedLocation_x                      0x444D30
#define ItemGlobalIndex__IsValidIndex_x                            0x454580

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x872670
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8715B0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F7420
