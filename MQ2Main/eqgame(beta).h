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
#elif defined(TEST)
#include "eqgame-private(test).h"
#endif
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Nov  4 2016"
#define __ExpectedVersionTime                                     "04:15:50"
#define __ActualVersionDate_x                                      0xAD1660
#define __ActualVersionTime_x                                      0xAD166C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTrayBeta"
#define __MacroQuestWinName                                       "MacroQuestBeta"

// Memory Protection
#define __MemChecker0_x                                            0x5A1DB0
#define __MemChecker1_x                                            0x896990
#define __MemChecker2_x                                            0x638250
#define __MemChecker3_x                                            0x6381A0
#define __MemChecker4_x                                            0x7EB1F0
#define __EncryptPad0_x                                            0xC75450
#define __EncryptPad1_x                                            0xE01A60
#define __EncryptPad2_x                                            0xCBE250
#define __EncryptPad3_x                                            0xCBDE50
#define __EncryptPad4_x                                            0xDD7A30
#define __EncryptPad5_x                                            0x11B2C98
#define __AC1_x                                                    0x7AA3A5
#define __AC2_x                                                    0x55B9C7
#define __AC3_x                                                    0x559B60
#define __AC4_x                                                    0x56C3D0
#define __AC5_x                                                    0x57F12B
#define __AC6_x                                                    0x582CDE
#define __AC7_x                                                    0x57979C
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
#define __do_loot_x                                                0x520EE0
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
#define pinstCAlarmWnd_x                                           0xF60984
#define pinstCGroupSearchFiltersWnd_x                              0xF6097C
#define pinstCLoadskinWnd_x                                        0xF60980
#define pinstCLargeDialogWnd_x                                     0x11B9978
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
#define __CastRay_x                                                0x538180
#define __ConvertItemTags_x                                        0x525A40
#define __ExecuteCmd_x                                             0x510310
#define __EQGetTime_x                                              0x896620
#define __get_melee_range_x                                        0x516ED0
#define __GetGaugeValueFromEQ_x                                    0x7A90E0
#define __GetLabelFromEQ_x                                         0x7AA330
#define __ToggleKeyRingItem_x                                      0x47FFA0
#define __GetXTargetType_x                                         0x927420
#define __LoadFrontEnd_x                                           0x637920
#define __NewUIINI_x                                               0x7A8AB0
#define __ProcessGameEvents_x                                      0x57B530
#define __ProcessMouseEvent_x                                      0x57ACD0
#define CrashDetected_x                                            0x6392E0
#define wwsCrashReportCheckForUploader_x                           0x7F6DD0
#define DrawNetStatus_x                                            0x5B19B0
#define Util__FastTime_x                                           0x8962C0
#define Expansion_HoT_x                                            0x10226B8
#define __HelpPath_x                                               0x10A5DB0
#define __STMLToText_x                                             0x8DC240

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420500
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B2A0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B080

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C72D0
#define AltAdvManager__IsAbilityReady_x                            0x4C7340
#define AltAdvManager__GetAAById_x                                 0x4C7700
#define AltAdvManager__CanTrainAbility_x                           0x4C8000
#define AltAdvManager__CanSeeAbility_x                             0x4C7BC0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4635A0
#define CharacterZoneClient__MakeMeVisible_x                       0x468050
#define CharacterZoneClient__IsStackBlocked_x                      0x447B80
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x447040
#define CharacterZoneClient__GetItemCountWorn_x                    0x4613D0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4614B0
#define CharacterZoneClient__GetCursorItemCount_x                  0x461590

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6673B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6757F0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x590CF0
#define CButtonWnd__CButtonWnd_x                                   0x8D05F0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x690830
#define CChatManager__InitContextMenu_x                            0x6913B0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DA5B0
#define CContextMenu__dCContextMenu_x                              0x8DA7B0
#define CContextMenu__AddMenuItem_x                                0x8DA7C0
#define CContextMenu__RemoveMenuItem_x                             0x8DAAA0
#define CContextMenu__RemoveAllMenuItems_x                         0x8DAAC0
#define CContextMenuManager__AddMenu_x                             0x8C6BB0
#define CContextMenuManager__RemoveMenu_x                          0x8C6F40
#define CContextMenuManager__PopupMenu_x                           0x8C7390
#define CContextMenuManager__Flush_x                               0x8C6C20
#define CContextMenuManager__GetMenu_x                             0x416980

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87B160
#define CChatService__GetFriendName_x                              0x87B170

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x696610
#define CChatWindow__Clear_x                                       0x6961E0
#define CChatWindow__WndNotification_x                             0x696B40

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CA9E0
#define CComboWnd__Draw_x                                          0x8CABF0
#define CComboWnd__GetCurChoice_x                                  0x8CA790
#define CComboWnd__GetListRect_x                                   0x8CAE90
#define CComboWnd__GetTextRect_x                                   0x8CAA50
#define CComboWnd__InsertChoice_x                                  0x8CAF00
#define CComboWnd__SetColors_x                                     0x8CA720
#define CComboWnd__SetChoice_x                                     0x8CA750
#define CComboWnd__GetItemCount_x                                  0x8CA780
#define CComboWnd__GetCurChoiceText_x                              0x8CA7D0


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69FCA0
#define CContainerWnd__vftable_x                                   0xADB140

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B57F0
#define CDisplay__GetClickedActor_x                                0x4AE120
#define CDisplay__GetUserDefinedColor_x                            0x4ACD00
#define CDisplay__GetWorldFilePath_x                               0x4AC150
#define CDisplay__is3dON_x                                         0x4AB5E0
#define CDisplay__ReloadUI_x                                       0x4C0D60
#define CDisplay__WriteTextHD2_x                                   0x4B1BB0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F0BB0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DEAD0
#define CEditWnd__GetCharIndexPt_x                                 0x8DFB50
#define CEditWnd__GetDisplayString_x                               0x8DEC80
#define CEditWnd__GetHorzOffset_x                                  0x8DEFC0
#define CEditWnd__GetLineForPrintableChar_x                        0x8DF620
#define CEditWnd__GetSelStartPt_x                                  0x8DFE00
#define CEditWnd__GetSTMLSafeText_x                                0x8DF150
#define CEditWnd__PointFromPrintableChar_x                         0x8DF710
#define CEditWnd__SelectableCharFromPoint_x                        0x8DF890
#define CEditWnd__SetEditable_x                                    0x8DF120

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x55C110
#define CEverQuest__CreateTargetIndicator_x                        0x55D000
#define CEverQuest__DeleteTargetIndicator_x                        0x55D080
#define CEverQuest__DoTellWindow_x                                 0x472C60
#define CEverQuest__DropHeldItemOnGround_x                         0x573220
#define CEverQuest__dsp_chat_x                                     0x472FA0
#define CEverQuest__trimName_x                                     0x558A60
#define CEverQuest__Emote_x                                        0x571570
#define CEverQuest__EnterZone_x                                    0x56C560
#define CEverQuest__GetBodyTypeDesc_x                              0x5564C0
#define CEverQuest__GetClassDesc_x                                 0x55FD90
#define CEverQuest__GetClassThreeLetterCode_x                      0x560390
#define CEverQuest__GetDeityDesc_x                                 0x556DA0
#define CEverQuest__GetLangDesc_x                                  0x556850
#define CEverQuest__GetRaceDesc_x                                  0x560550
#define CEverQuest__InterpretCmd_x                                 0x564380
#define CEverQuest__LeftClickedOnPlayer_x                          0x577BF0
#define CEverQuest__LMouseUp_x                                     0x579CF0
#define CEverQuest__RightClickedOnPlayer_x                         0x578700
#define CEverQuest__RMouseUp_x                                     0x579750
#define CEverQuest__SetGameState_x                                 0x55C9D0
#define CEverQuest__UPCNotificationFlush_x                         0x5542D0
#define CEverQuest__IssuePetCommand_x                              0x564D60

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B0A70
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B0AD0
#define CGaugeWnd__Draw_x                                          0x6B0F00

// CGuild
#define CGuild__FindMemberByName_x                                 0x437430
#define CGuild__GetGuildName_x                                     0x437900
#define CGuild__GetGuildIndex_x                                    0x438AD0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CCF40

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DA0E0
#define CInvSlotMgr__MoveItem_x                                    0x6DAF90
#define CInvSlotMgr__SelectSlot_x                                  0x6DA190

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D9590
#define CInvSlot__SliderComplete_x                                 0x6D6DA0
#define CInvSlot__GetItemBase_x                                    0x6D6200

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DC3F0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A4AF0
#define CItemDisplayWnd__UpdateStrings_x                           0x6DE530

// CLabel 
#define CLabel__Draw_x                                             0x6F7FF0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B6870
#define CListWnd__dCListWnd_x                                      0x8B7AA0
#define CListWnd__AddColumn_x                                      0x8B7A40
#define CListWnd__AddColumn1_x                                     0x8B70D0
#define CListWnd__AddLine_x                                        0x8B6B30
#define CListWnd__AddString_x                                      0x8B6D50
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B3B10
#define CListWnd__CalculateVSBRange_x                              0x8B5D30
#define CListWnd__ClearSel_x                                       0x8B2E30
#define CListWnd__ClearAllSel_x                                    0x8B2DE0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B6700
#define CListWnd__Compare_x                                        0x8B4680
#define CListWnd__Draw_x                                           0x8B5940
#define CListWnd__DrawColumnSeparators_x                           0x8B57D0
#define CListWnd__DrawHeader_x                                     0x8B30F0
#define CListWnd__DrawItem_x                                       0x8B4D10
#define CListWnd__DrawLine_x                                       0x8B5470
#define CListWnd__DrawSeparator_x                                  0x8B5870
#define CListWnd__EnsureVisible_x                                  0x8B3C70
#define CListWnd__ExtendSel_x                                      0x8B4C20
#define CListWnd__GetColumnMinWidth_x                              0x8B27E0
#define CListWnd__GetColumnWidth_x                                 0x8B2710
#define CListWnd__GetCurSel_x                                      0x8B1EE0
#define CListWnd__GetItemAtPoint_x                                 0x8B3F00
#define CListWnd__GetItemAtPoint1_x                                0x8B3F70
#define CListWnd__GetItemData_x                                    0x8B2220
#define CListWnd__GetItemHeight_x                                  0x8B3770
#define CListWnd__GetItemIcon_x                                    0x8B2410
#define CListWnd__GetItemRect_x                                    0x8B3D40
#define CListWnd__GetItemText_x                                    0x8B22C0
#define CListWnd__GetSelList_x                                     0x8B6FC0
#define CListWnd__GetSeparatorRect_x                               0x8B45A0
#define CListWnd__RemoveLine_x                                     0x8B6F40
#define CListWnd__SetColors_x                                      0x8B2030
#define CListWnd__SetColumnJustification_x                         0x8B2A70
#define CListWnd__SetColumnWidth_x                                 0x8B2790
#define CListWnd__SetCurSel_x                                      0x8B1F20
#define CListWnd__SetItemColor_x                                   0x8B63F0
#define CListWnd__SetItemData_x                                    0x8B2E90
#define CListWnd__SetItemText_x                                    0x8B6230
#define CListWnd__ShiftColumnSeparator_x                           0x8B60C0
#define CListWnd__Sort_x                                           0x8B7BA0
#define CListWnd__ToggleSel_x                                      0x8B2D60

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x710F50

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7323C0
#define CMerchantWnd__RequestBuyItem_x                             0x739470
#define CMerchantWnd__RequestSellItem_x                            0x739F40
#define CMerchantWnd__SelectRecoverySlot_x                         0x732670
#define CMerchantWnd__SelectBuySellSlot_x                          0x731870
#define CMerchantWnd__ActualSelect_x                               0x736340

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x84A980
#define CPacketScrambler__hton_x                                   0x84A990

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D5590
#define CSidlManager__CreateLabel_x                                0x79A9E0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65E750
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65E670
#define CSidlScreenWnd__ConvertToRes_x                             0x8F0A90
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CD370
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CE520
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CE5D0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CDAA0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CCD20
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CC480
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CCF10
#define CSidlScreenWnd__Init1_x                                    0x8CE1F0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CD420
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CC640
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CDCE0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CC0E0
#define CSidlScreenWnd__StoreIniVis_x                              0x8CC430
#define CSidlScreenWnd__WndNotification_x                          0x8CDF70
#define CSidlScreenWnd__GetChildItem_x                             0x8CC550
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BFF20
#define CSidlScreenWnd__m_layoutCopy_x                             0x181E980

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FD380
#define CSkillMgr__GetSkillCap_x                                   0x5FD560
#define CSkillMgr__GetNameToken_x                                  0x5FCFA0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8EFD40
#define CSliderWnd__SetValue_x                                     0x8EFF10
#define CSliderWnd__SetNumTicks_x                                  0x8F0690

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A2740

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EB720
#define CStmlWnd__CalculateHSBRange_x                              0x8E3C70
#define CStmlWnd__CalculateVSBRange_x                              0x8E3D00
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E3E80
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E4760
#define CStmlWnd__ForceParseNow_x                                  0x8EC070
#define CStmlWnd__GetNextTagPiece_x                                0x8E4660
#define CStmlWnd__GetSTMLText_x                                    0x695A80
#define CStmlWnd__GetVisibleText_x                                 0x8E51B0
#define CStmlWnd__InitializeWindowVariables_x                      0x8E7540
#define CStmlWnd__MakeStmlColorTag_x                               0x8E2F70
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E2FD0
#define CStmlWnd__SetSTMLText_x                                    0x8E8DA0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EB3C0
#define CStmlWnd__UpdateHistoryString_x                            0x8E60F0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E2670
#define CTabWnd__DrawCurrentPage_x                                 0x8E1F00
#define CTabWnd__DrawTab_x                                         0x8E1CD0
#define CTabWnd__GetCurrentPage_x                                  0x8E22B0
#define CTabWnd__GetPageInnerRect_x                                0x8E19C0
#define CTabWnd__GetTabInnerRect_x                                 0x8E1BC0
#define CTabWnd__GetTabRect_x                                      0x8E1A90
#define CTabWnd__InsertPage_x                                      0x8E2960
#define CTabWnd__SetPage_x                                         0x8E22E0
#define CTabWnd__SetPageRect_x                                     0x8E25B0
#define CTabWnd__UpdatePage_x                                      0x8E2900

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x433060

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CA390

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x635BA0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F5EA0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B0190

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59E280
#define CXStr__CXStr1_x                                            0x7D7720
#define CXStr__CXStr3_x                                            0x893560
#define CXStr__dCXStr_x                                            0x40A510
#define CXStr__operator_equal_x                                    0x8936D0
#define CXStr__operator_equal1_x                                   0x893720
#define CXStr__operator_plus_equal1_x                              0x894820

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BF150
#define CXWnd__Center_x                                            0x8C51E0
#define CXWnd__ClrFocus_x                                          0x8BED30
#define CXWnd__DoAllDrawing_x                                      0x8C4E30
#define CXWnd__DrawChildren_x                                      0x8C4FD0
#define CXWnd__DrawColoredRect_x                                   0x8BF530
#define CXWnd__DrawTooltip_x                                       0x8BF7E0
#define CXWnd__DrawTooltipAtPoint_x                                0x8C3DF0
#define CXWnd__GetBorderFrame_x                                    0x8BFC40
#define CXWnd__GetChildWndAt_x                                     0x8C5B90
#define CXWnd__GetClientClipRect_x                                 0x8BFA00
#define CXWnd__GetScreenClipRect_x                                 0x8C44E0
#define CXWnd__GetScreenRect_x                                     0x8BFDC0
#define CXWnd__GetTooltipRect_x                                    0x8BF670
#define CXWnd__GetWindowTextA_x                                    0x424590
#define CXWnd__IsActive_x                                          0x8BA870
#define CXWnd__IsDescendantOf_x                                    0x8BFB90
#define CXWnd__IsReallyVisible_x                                   0x8C2E40
#define CXWnd__IsType_x                                            0x8F2720
#define CXWnd__Move_x                                              0x8C2590
#define CXWnd__Move1_x                                             0x8C4B10
#define CXWnd__ProcessTransition_x                                 0x8BF0F0
#define CXWnd__Refade_x                                            0x8BEED0
#define CXWnd__Resize_x                                            0x8BFE80
#define CXWnd__Right_x                                             0x8C42E0
#define CXWnd__SetFocus_x                                          0x8C1720
#define CXWnd__SetFont_x                                           0x8BED80
#define CXWnd__SetKeyTooltip_x                                     0x8C00F0
#define CXWnd__SetMouseOver_x                                      0x8C4810
#define CXWnd__StartFade_x                                         0x8BF1A0
#define CXWnd__GetChildItem_x                                      0x8C4750

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BC0F0
#define CXWndManager__DrawWindows_x                                0x8BBD30
#define CXWndManager__GetKeyboardFlags_x                           0x8BA3E0
#define CXWndManager__HandleKeyboardMsg_x                          0x8BACF0
#define CXWndManager__RemoveWnd_x                                  0x8BAA00

// CDBStr
#define CDBStr__GetString_x                                        0x4A9B80

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E110
#define EQ_Character__Cur_HP_x                                     0x462C40
#define EQ_Character__Cur_Mana_x                                   0x456780
#define EQ_Character__GetAACastingTimeModifier_x                   0x447350
#define EQ_Character__GetCharInfo2_x                               0x867120
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F570
#define EQ_Character__GetFocusRangeModifier_x                      0x43F5D0
#define EQ_Character__Max_Endurance_x                              0x5C36C0
#define EQ_Character__Max_HP_x                                     0x4593A0
#define EQ_Character__Max_Mana_x                                   0x5C34F0
#define EQ_Character__doCombatAbility_x                            0x5C0BE0
#define EQ_Character__UseSkill_x                                   0x46D0D0
#define EQ_Character__GetConLevel_x                                0x5B5FD0
#define EQ_Character__IsExpansionFlag_x                            0x423AB0
#define EQ_Character__TotalEffect_x                                0x44B3B0
#define EQ_Character__GetPCSpellAffect_x                           0x447750
#define EQ_Character__SpellDuration_x                              0x445650
#define EQ_Character__FindItemByRecord_x                           0x4600C0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x442940
#define CCharacterSelect__EnterWorld_x                             0x442110
#define CCharacterSelect__Quit_x                                   0x440D00

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x596550
#define EQ_Item__CreateItemTagString_x                             0x849370
#define EQ_Item__IsStackable_x                                     0x83EDD0
#define EQ_Item__GetImageNum_x                                     0x841800
#define EQ_Item__CreateItemClient_x                                0x597120
#define EQ_Item__GetItemValue_x                                    0x848040
#define EQ_Item__ValueSellMerchant_x                               0x84A610
#define EQ_Item__IsKeyRingItem_x                                   0x83F820
#define EQ_Item__CanGoInBag_x                                      0x5966E0
#define EQ_Item__GetMaxItemCount_x                                 0x83ECC0
#define EQ_Item__GetHeldItem_x                                     0x840610

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C9400
#define EQ_LoadingS__Array_x                                       0xC1C680

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C5BE0
#define EQ_PC__GetAlternateAbilityId_x                             0x852A50
#define EQ_PC__GetCombatAbility_x                                  0x852AE0
#define EQ_PC__GetCombatAbilityTimer_x                             0x84D790
#define EQ_PC__GetItemTimerValue_x                                 0x5BF2A0
#define EQ_PC__HasLoreItem_x                                       0x5B9500
#define EQ_PC__AlertInventoryChanged_x                             0x5B5FA0
#define EQ_PC__GetPcZoneClient_x                                   0x5E0220
#define EQ_PC__RemoveMyAffect_x                                    0x5BE730
#define EQ_PC__GetKeyRingItems_x                                   0x84DBB0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x514F90
#define EQItemList__add_object_x                                   0x540DF0
#define EQItemList__add_item_x                                     0x514ED0
#define EQItemList__delete_item_x                                  0x515380
#define EQItemList__FreeItemList_x                                 0x515280

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A8E70

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5CB240
#define EQPlayer__dEQPlayer_x                                      0x5D4110
#define EQPlayer__DoAttack_x                                       0x5E6110
#define EQPlayer__EQPlayer_x                                       0x5D6820
#define EQPlayer__SetNameSpriteState_x                             0x5D1060
#define EQPlayer__SetNameSpriteTint_x                              0x5CC650
#define PlayerBase__HasProperty_j_x                                0x923620
#define EQPlayer__IsTargetable_x                                   0x923F20
#define EQPlayer__CanSee_x                                         0x924440
#define PlayerZoneClient__ChangeHeight_x                           0x5E5FD0
#define EQPlayer__CanSeeTargetIndicator_x                          0x924530
#define PlayerBase__GetVisibilityLineSegment_x                     0x9241D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5DA870
#define EQPlayerManager__GetSpawnByName_x                          0x5DACD0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5DA8A0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59C620
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59C660
#define KeypressHandler__ClearCommandStateArray_x                  0x59C210
#define KeypressHandler__HandleKeyDown_x                           0x59AB70
#define KeypressHandler__HandleKeyUp_x                             0x59AE90
#define KeypressHandler__SaveKeymapping_x                          0x59C2E0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7098E0
#define MapViewMap__SaveEx_x                                       0x70CC10

#define PlayerPointManager__GetAltCurrency_x                       0x865280

// StringTable 
#define StringTable__getString_x                                   0x85FE90

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C3150
#define PcZoneClient__RemovePetEffect_x                            0x5BF770
#define PcZoneClient__HasAlternateAbility_x                        0x5C0110
#define PcZoneClient__GetCurrentMod_x                              0x458740
#define PcZoneClient__GetModCap_x                                  0x455F00
#define PcZoneClient__CanEquipItem_x                               0x5C06C0

//Doors
#define EQSwitch__UseSwitch_x                                      0x552B90

//IconCache
#define IconCache__GetIcon_x                                       0x6A62A0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69D050
#define CContainerMgr__CloseContainer_x                            0x69D870

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76A7F0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58F770

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E32B0
#define EQ_Spell__SpellAffects_x                                   0x4E0960
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4E09D0
#define CharacterZoneClient__CalcAffectChange_x                    0x446780
#define CLootWnd__LootAll_x                                        0x6FF250
#define CLootWnd__RequestLootSlot_x                                0x6FFA60

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B1530
#define CTargetWnd__WndNotification_x                              0x7B1020
#define CTargetWnd__RefreshTargetBuffs_x                           0x7B1710

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B6780

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4DBFA0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4988F0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DE100
#define CSidlManager__FindAnimation1_x                             0x8D3490

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D0B90
#define CAltAbilityData__GetMercMaxRank_x                          0x4D0B40
#define CAltAbilityData__GetMaxRank_x                              0x4C5980

//CTargetRing
#define CTargetRing__Cast_x                                        0x58D060

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x454FE0
#define CharacterBase__CreateItemGlobalIndex_x                     0x471EA0
#define CharacterBase__CreateItemIndex_x                           0x50E3F0
#define CharacterBase__GetItemPossession_x                         0x50F8A0
#define CharacterBase__GetItemByGlobalIndex_x                      0x875280

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x687970
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6870D0

//messages
#define msg_spell_worn_off_x                                       0x4EAE70
#define msg_new_text_x                                             0x4F4410
#define msgTokenTextParam_x                                        0x4F0DC0

//SpellManager
#define SpellManager__vftable_x                                    0xAB6FF8
#define SpellManager__SpellManager_x                               0x47ABF0
#define Spellmanager__CheckSpellRequirementAssociations_x          0x6041C0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x927F40

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E7400
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43AD00
#define ItemGlobalIndex__IsEquippedLocation_x                      0x444FB0
#define ItemGlobalIndex__IsValidIndex_x                            0x454860

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x873090
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x871FD0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F8240
