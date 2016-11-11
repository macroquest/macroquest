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
#if defined(BETA)
#include "eqgame-private(beta).h"
#endif
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Nov 10 2016"
#define __ExpectedVersionTime                                     "04:16:23"
#define __ActualVersionDate_x                                      0xAD1648
#define __ActualVersionTime_x                                      0xAD1654

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x5A1340
#define __MemChecker1_x                                            0x8960C0
#define __MemChecker2_x                                            0x6378E0
#define __MemChecker3_x                                            0x637830
#define __MemChecker4_x                                            0x7EA3B0
#define __EncryptPad0_x                                            0xC75450
#define __EncryptPad1_x                                            0xE01A60
#define __EncryptPad2_x                                            0xCBE250
#define __EncryptPad3_x                                            0xCBDE50
#define __EncryptPad4_x                                            0xDD7A30
#define __EncryptPad5_x                                            0x11B2C98
#define __AC1_x                                                    0x7A9B25
#define __AC2_x                                                    0x55B007
#define __AC3_x                                                    0x5591A0
#define __AC4_x                                                    0x56BA10
#define __AC5_x                                                    0x57E75B
#define __AC6_x                                                    0x58230E
#define __AC7_x                                                    0x578DCC
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
#define __do_loot_x                                                0x5203C0
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
#define __CastRay_x                                                0x537660
#define __ConvertItemTags_x                                        0x524F20
#define __ExecuteCmd_x                                             0x50F7C0
#define __EQGetTime_x                                              0x895D50
#define __get_melee_range_x                                        0x5163B0
#define __GetGaugeValueFromEQ_x                                    0x7A8860
#define __GetLabelFromEQ_x                                         0x7A9AB0
#define __ToggleKeyRingItem_x                                      0x47FF50
#define __GetXTargetType_x                                         0x926D80
#define __LoadFrontEnd_x                                           0x636FB0
#define __NewUIINI_x                                               0x7A8230
#define __ProcessGameEvents_x                                      0x57AB60
#define __ProcessMouseEvent_x                                      0x57A300
#define CrashDetected_x                                            0x638970
#define wwsCrashReportCheckForUploader_x                           0x7F6260
#define DrawNetStatus_x                                            0x5B0E30
#define Util__FastTime_x                                           0x8959F0
#define Expansion_HoT_x                                            0x10226B8
#define __HelpPath_x                                               0x10A5DB0
#define __STMLToText_x                                             0x8DBB80

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420560
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B300
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B0E0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C72A0
#define AltAdvManager__IsAbilityReady_x                            0x4C7310
#define AltAdvManager__GetAAById_x                                 0x4C76D0
#define AltAdvManager__CanTrainAbility_x                           0x4C7FD0
#define AltAdvManager__CanSeeAbility_x                             0x4C7B90

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463530
#define CharacterZoneClient__MakeMeVisible_x                       0x467EF0
#define CharacterZoneClient__IsStackBlocked_x                      0x4479F0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x446EB0
#define CharacterZoneClient__GetItemCountWorn_x                    0x461360
#define CharacterZoneClient__GetItemCountInInventory_x             0x461440
#define CharacterZoneClient__GetCursorItemCount_x                  0x461520

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x666AE0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x674FB0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5902B0
#define CButtonWnd__CButtonWnd_x                                   0x8CFF10

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68FE90
#define CChatManager__InitContextMenu_x                            0x690A10

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D9EE0
#define CContextMenu__dCContextMenu_x                              0x8DA0F0
#define CContextMenu__AddMenuItem_x                                0x8DA100
#define CContextMenu__RemoveMenuItem_x                             0x8DA3F0
#define CContextMenu__RemoveAllMenuItems_x                         0x8DA410
#define CContextMenuManager__AddMenu_x                             0x8C64D0
#define CContextMenuManager__RemoveMenu_x                          0x8C6860
#define CContextMenuManager__PopupMenu_x                           0x8C6CB0
#define CContextMenuManager__Flush_x                               0x8C6540
#define CContextMenuManager__GetMenu_x                             0x4169E0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87A730
#define CChatService__GetFriendName_x                              0x87A740

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x695C70
#define CChatWindow__Clear_x                                       0x695840
#define CChatWindow__WndNotification_x                             0x6961B0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CA320
#define CComboWnd__Draw_x                                          0x8CA530
#define CComboWnd__GetCurChoice_x                                  0x8CA0D0
#define CComboWnd__GetListRect_x                                   0x8CA7D0
#define CComboWnd__GetTextRect_x                                   0x8CA390
#define CComboWnd__InsertChoice_x                                  0x8CA840
#define CComboWnd__SetColors_x                                     0x8CA060
#define CComboWnd__SetChoice_x                                     0x8CA090
#define CComboWnd__GetItemCount_x                                  0x8CA0C0
#define CComboWnd__GetCurChoiceText_x                              0x8CA110


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69F3F0
#define CContainerWnd__vftable_x                                   0xADB128

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B57A0
#define CDisplay__GetClickedActor_x                                0x4AE0D0
#define CDisplay__GetUserDefinedColor_x                            0x4ACCB0
#define CDisplay__GetWorldFilePath_x                               0x4AC100
#define CDisplay__is3dON_x                                         0x4AB590
#define CDisplay__ReloadUI_x                                       0x4C0D10
#define CDisplay__WriteTextHD2_x                                   0x4B1B60

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F0550

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DE410
#define CEditWnd__GetCharIndexPt_x                                 0x8DF4A0
#define CEditWnd__GetDisplayString_x                               0x8DE5C0
#define CEditWnd__GetHorzOffset_x                                  0x8DE900
#define CEditWnd__GetLineForPrintableChar_x                        0x8DEF70
#define CEditWnd__GetSelStartPt_x                                  0x8DF750
#define CEditWnd__GetSTMLSafeText_x                                0x8DEAA0
#define CEditWnd__PointFromPrintableChar_x                         0x8DF060
#define CEditWnd__SelectableCharFromPoint_x                        0x8DF1E0
#define CEditWnd__SetEditable_x                                    0x8DEA70

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x55B750
#define CEverQuest__CreateTargetIndicator_x                        0x55C640
#define CEverQuest__DeleteTargetIndicator_x                        0x55C6C0
#define CEverQuest__DoTellWindow_x                                 0x472B40
#define CEverQuest__DropHeldItemOnGround_x                         0x572860
#define CEverQuest__dsp_chat_x                                     0x472E80
#define CEverQuest__trimName_x                                     0x5580A0
#define CEverQuest__Emote_x                                        0x570BB0
#define CEverQuest__EnterZone_x                                    0x56BBA0
#define CEverQuest__GetBodyTypeDesc_x                              0x555B00
#define CEverQuest__GetClassDesc_x                                 0x55F3D0
#define CEverQuest__GetClassThreeLetterCode_x                      0x55F9D0
#define CEverQuest__GetDeityDesc_x                                 0x5563E0
#define CEverQuest__GetLangDesc_x                                  0x555E90
#define CEverQuest__GetRaceDesc_x                                  0x55FB90
#define CEverQuest__InterpretCmd_x                                 0x5639C0
#define CEverQuest__LeftClickedOnPlayer_x                          0x577220
#define CEverQuest__LMouseUp_x                                     0x579320
#define CEverQuest__RightClickedOnPlayer_x                         0x577D30
#define CEverQuest__RMouseUp_x                                     0x578D80
#define CEverQuest__SetGameState_x                                 0x55C010
#define CEverQuest__UPCNotificationFlush_x                         0x553910
#define CEverQuest__IssuePetCommand_x                              0x5643A0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B00F0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B0150
#define CGaugeWnd__Draw_x                                          0x6B0580

// CGuild
#define CGuild__FindMemberByName_x                                 0x4372A0
#define CGuild__GetGuildName_x                                     0x437770
#define CGuild__GetGuildIndex_x                                    0x438940

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CC670

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D97E0
#define CInvSlotMgr__MoveItem_x                                    0x6DA690
#define CInvSlotMgr__SelectSlot_x                                  0x6D9890

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D8C90
#define CInvSlot__SliderComplete_x                                 0x6D64A0
#define CInvSlot__GetItemBase_x                                    0x6D5940

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DBAC0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A4250
#define CItemDisplayWnd__UpdateStrings_x                           0x6DDC10

// CLabel 
#define CLabel__Draw_x                                             0x6F7800

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B6120
#define CListWnd__dCListWnd_x                                      0x8B7340
#define CListWnd__AddColumn_x                                      0x8B72E0
#define CListWnd__AddColumn1_x                                     0x8B6980
#define CListWnd__AddLine_x                                        0x8B63E0
#define CListWnd__AddString_x                                      0x8B6600
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B33A0
#define CListWnd__CalculateVSBRange_x                              0x8B55E0
#define CListWnd__ClearSel_x                                       0x8B26B0
#define CListWnd__ClearAllSel_x                                    0x8B2660
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B5FB0
#define CListWnd__Compare_x                                        0x8B3F20
#define CListWnd__Draw_x                                           0x8B51E0
#define CListWnd__DrawColumnSeparators_x                           0x8B5070
#define CListWnd__DrawHeader_x                                     0x8B2970
#define CListWnd__DrawItem_x                                       0x8B45A0
#define CListWnd__DrawLine_x                                       0x8B4D10
#define CListWnd__DrawSeparator_x                                  0x8B5110
#define CListWnd__EnsureVisible_x                                  0x8B3500
#define CListWnd__ExtendSel_x                                      0x8B44B0
#define CListWnd__GetColumnMinWidth_x                              0x8B2060
#define CListWnd__GetColumnWidth_x                                 0x8B1F90
#define CListWnd__GetCurSel_x                                      0x8B1750
#define CListWnd__GetItemAtPoint_x                                 0x8B37A0
#define CListWnd__GetItemAtPoint1_x                                0x8B3810
#define CListWnd__GetItemData_x                                    0x8B1AA0
#define CListWnd__GetItemHeight_x                                  0x8B2FF0
#define CListWnd__GetItemIcon_x                                    0x8B1C90
#define CListWnd__GetItemRect_x                                    0x8B35E0
#define CListWnd__GetItemText_x                                    0x8B1B40
#define CListWnd__GetSelList_x                                     0x8B6870
#define CListWnd__GetSeparatorRect_x                               0x8B3E40
#define CListWnd__RemoveLine_x                                     0x8B67F0
#define CListWnd__SetColors_x                                      0x8B18A0
#define CListWnd__SetColumnJustification_x                         0x8B22F0
#define CListWnd__SetColumnWidth_x                                 0x8B2010
#define CListWnd__SetCurSel_x                                      0x8B1790
#define CListWnd__SetItemColor_x                                   0x8B5CA0
#define CListWnd__SetItemData_x                                    0x8B2710
#define CListWnd__SetItemText_x                                    0x8B5AE0
#define CListWnd__ShiftColumnSeparator_x                           0x8B5970
#define CListWnd__Sort_x                                           0x8B7440
#define CListWnd__ToggleSel_x                                      0x8B25E0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x710890

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x731CB0
#define CMerchantWnd__RequestBuyItem_x                             0x738D60
#define CMerchantWnd__RequestSellItem_x                            0x739830
#define CMerchantWnd__SelectRecoverySlot_x                         0x731F60
#define CMerchantWnd__SelectBuySellSlot_x                          0x731160
#define CMerchantWnd__ActualSelect_x                               0x735C30

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x84A030
#define CPacketScrambler__hton_x                                   0x84A040

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D4F30
#define CSidlManager__CreateLabel_x                                0x79A1D0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65DEE0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65DE00
#define CSidlScreenWnd__ConvertToRes_x                             0x8F0430
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CCCC0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CDE60
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CDF10
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CD3E0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CC670
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CBDD0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CC860
#define CSidlScreenWnd__Init1_x                                    0x8CDB30
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CCD70
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CBF90
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CD620
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CBA30
#define CSidlScreenWnd__StoreIniVis_x                              0x8CBD80
#define CSidlScreenWnd__WndNotification_x                          0x8CD8B0
#define CSidlScreenWnd__GetChildItem_x                             0x8CBEA0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BF810
#define CSidlScreenWnd__m_layoutCopy_x                             0x181E980

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FCAB0
#define CSkillMgr__GetSkillCap_x                                   0x5FCC90
#define CSkillMgr__GetNameToken_x                                  0x5FC6D0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8EF6E0
#define CSliderWnd__SetValue_x                                     0x8EF8B0
#define CSliderWnd__SetNumTicks_x                                  0x8F0030

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A1EA0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EB0B0
#define CStmlWnd__CalculateHSBRange_x                              0x8E35D0
#define CStmlWnd__CalculateVSBRange_x                              0x8E3660
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E37E0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E40C0
#define CStmlWnd__ForceParseNow_x                                  0x8EBA00
#define CStmlWnd__GetNextTagPiece_x                                0x8E3FC0
#define CStmlWnd__GetSTMLText_x                                    0x6950E0
#define CStmlWnd__GetVisibleText_x                                 0x8E4B10
#define CStmlWnd__InitializeWindowVariables_x                      0x8E6EA0
#define CStmlWnd__MakeStmlColorTag_x                               0x8E28D0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E2930
#define CStmlWnd__SetSTMLText_x                                    0x8E8700
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EAD50
#define CStmlWnd__UpdateHistoryString_x                            0x8E5A50

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E1FE0
#define CTabWnd__DrawCurrentPage_x                                 0x8E1870
#define CTabWnd__DrawTab_x                                         0x8E1630
#define CTabWnd__GetCurrentPage_x                                  0x8E1C20
#define CTabWnd__GetPageInnerRect_x                                0x8E1320
#define CTabWnd__GetTabInnerRect_x                                 0x8E1520
#define CTabWnd__GetTabRect_x                                      0x8E13F0
#define CTabWnd__InsertPage_x                                      0x8E22D0
#define CTabWnd__SetPage_x                                         0x8E1C50
#define CTabWnd__SetPageRect_x                                     0x8E1F20
#define CTabWnd__UpdatePage_x                                      0x8E2270

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432ED0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C9CD0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x635250

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F5850

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8AF940

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029A0
#define CXStr__CXStr1_x                                            0x8A4540
#define CXStr__CXStr3_x                                            0x892C90
#define CXStr__dCXStr_x                                            0x5FF750
#define CXStr__operator_equal_x                                    0x892E00
#define CXStr__operator_equal1_x                                   0x892E50
#define CXStr__operator_plus_equal1_x                              0x893F50

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BE9E0
#define CXWnd__Center_x                                            0x8C4AC0
#define CXWnd__ClrFocus_x                                          0x8BE5B0
#define CXWnd__DoAllDrawing_x                                      0x8C4720
#define CXWnd__DrawChildren_x                                      0x8C48C0
#define CXWnd__DrawColoredRect_x                                   0x8BEDD0
#define CXWnd__DrawTooltip_x                                       0x8BF080
#define CXWnd__DrawTooltipAtPoint_x                                0x8C36F0
#define CXWnd__GetBorderFrame_x                                    0x8BF4F0
#define CXWnd__GetChildWndAt_x                                     0x8C5490
#define CXWnd__GetClientClipRect_x                                 0x8BF2A0
#define CXWnd__GetScreenClipRect_x                                 0x8C3DF0
#define CXWnd__GetScreenRect_x                                     0x8BF6B0
#define CXWnd__GetTooltipRect_x                                    0x8BEF10
#define CXWnd__GetWindowTextA_x                                    0x4245B0
#define CXWnd__IsActive_x                                          0x8BA100
#define CXWnd__IsDescendantOf_x                                    0x8BF430
#define CXWnd__IsReallyVisible_x                                   0x8C2720
#define CXWnd__IsType_x                                            0x8F20B0
#define CXWnd__Move_x                                              0x8C1EB0
#define CXWnd__Move1_x                                             0x8C4400
#define CXWnd__ProcessTransition_x                                 0x8BE980
#define CXWnd__Refade_x                                            0x8BE750
#define CXWnd__Resize_x                                            0x8BF770
#define CXWnd__Right_x                                             0x8C3BF0
#define CXWnd__SetFocus_x                                          0x8C1000
#define CXWnd__SetFont_x                                           0x8BE600
#define CXWnd__SetKeyTooltip_x                                     0x8BF9E0
#define CXWnd__SetMouseOver_x                                      0x8C40F0
#define CXWnd__StartFade_x                                         0x8BEA30
#define CXWnd__GetChildItem_x                                      0x8C4030

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BB990
#define CXWndManager__DrawWindows_x                                0x8BB5E0
#define CXWndManager__GetKeyboardFlags_x                           0x8B9C40
#define CXWndManager__HandleKeyboardMsg_x                          0x8BA5A0
#define CXWndManager__RemoveWnd_x                                  0x8BA290

// CDBStr
#define CDBStr__GetString_x                                        0x4A9B60

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44DF70
#define EQ_Character__Cur_HP_x                                     0x462BD0
#define EQ_Character__Cur_Mana_x                                   0x456700
#define EQ_Character__GetAACastingTimeModifier_x                   0x4471C0
#define EQ_Character__GetCharInfo2_x                               0x866710
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F4A0
#define EQ_Character__GetFocusRangeModifier_x                      0x43F500
#define EQ_Character__Max_Endurance_x                              0x5C29B0
#define EQ_Character__Max_HP_x                                     0x459320
#define EQ_Character__Max_Mana_x                                   0x5C27E0
#define EQ_Character__doCombatAbility_x                            0x5BFED0
#define EQ_Character__UseSkill_x                                   0x46CF70
#define EQ_Character__GetConLevel_x                                0x5B5490
#define EQ_Character__IsExpansionFlag_x                            0x423AF0
#define EQ_Character__TotalEffect_x                                0x44B210
#define EQ_Character__GetPCSpellAffect_x                           0x4475C0
#define EQ_Character__SpellDuration_x                              0x4454C0
#define EQ_Character__FindItemByRecord_x                           0x460050

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x4427F0
#define CCharacterSelect__EnterWorld_x                             0x441FC0
#define CCharacterSelect__Quit_x                                   0x440BA0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x595AC0
#define EQ_Item__CreateItemTagString_x                             0x8489A0
#define EQ_Item__IsStackable_x                                     0x83E250
#define EQ_Item__GetImageNum_x                                     0x840C70
#define EQ_Item__CreateItemClient_x                                0x5966B0
#define EQ_Item__GetItemValue_x                                    0x847700
#define EQ_Item__ValueSellMerchant_x                               0x849CC0
#define EQ_Item__IsKeyRingItem_x                                   0x83EC90
#define EQ_Item__CanGoInBag_x                                      0x595C50
#define EQ_Item__GetMaxItemCount_x                                 0x83E140
#define EQ_Item__GetHeldItem_x                                     0x83FA80

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C94A0
#define EQ_LoadingS__Array_x                                       0xC1C680

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C4ED0
#define EQ_PC__GetAlternateAbilityId_x                             0x851EF0
#define EQ_PC__GetCombatAbility_x                                  0x851F80
#define EQ_PC__GetCombatAbilityTimer_x                             0x84CE40
#define EQ_PC__GetItemTimerValue_x                                 0x5BE580
#define EQ_PC__HasLoreItem_x                                       0x5B89B0
#define EQ_PC__AlertInventoryChanged_x                             0x5B5460
#define EQ_PC__GetPcZoneClient_x                                   0x5DF580
#define EQ_PC__RemoveMyAffect_x                                    0x5BDA10
#define EQ_PC__GetKeyRingItems_x                                   0x84D260

// EQItemList 
#define EQItemList__EQItemList_x                                   0x514440
#define EQItemList__add_object_x                                   0x540350
#define EQItemList__add_item_x                                     0x514380
#define EQItemList__delete_item_x                                  0x514830
#define EQItemList__FreeItemList_x                                 0x514730

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A8E10

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5CA570
#define EQPlayer__dEQPlayer_x                                      0x5D3440
#define EQPlayer__DoAttack_x                                       0x5E5470
#define EQPlayer__EQPlayer_x                                       0x5D5B50
#define EQPlayer__SetNameSpriteState_x                             0x5D0390
#define EQPlayer__SetNameSpriteTint_x                              0x5CB980
#define PlayerBase__HasProperty_j_x                                0x922FC0
#define EQPlayer__IsTargetable_x                                   0x9238C0
#define EQPlayer__CanSee_x                                         0x923DE0
#define PlayerZoneClient__ChangeHeight_x                           0x5E5330
#define EQPlayer__CanSeeTargetIndicator_x                          0x923ED0
#define PlayerBase__GetVisibilityLineSegment_x                     0x923B70

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D9BD0
#define EQPlayerManager__GetSpawnByName_x                          0x5DA030
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D9C00

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59BC40
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59BC80
#define KeypressHandler__ClearCommandStateArray_x                  0x59B830
#define KeypressHandler__HandleKeyDown_x                           0x59A190
#define KeypressHandler__HandleKeyUp_x                             0x59A4B0
#define KeypressHandler__SaveKeymapping_x                          0x59B900

// MapViewMap 
#define MapViewMap__Clear_x                                        0x709220
#define MapViewMap__SaveEx_x                                       0x70C550

#define PlayerPointManager__GetAltCurrency_x                       0x864870

// StringTable 
#define StringTable__getString_x                                   0x85F360

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C2440
#define PcZoneClient__RemovePetEffect_x                            0x5BEA50
#define PcZoneClient__HasAlternateAbility_x                        0x5BF3F0
#define PcZoneClient__GetCurrentMod_x                              0x4586C0
#define PcZoneClient__GetModCap_x                                  0x455E80
#define PcZoneClient__CanEquipItem_x                               0x5BF9A0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5521B0

//IconCache
#define IconCache__GetIcon_x                                       0x6A5A10

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69C780
#define CContainerMgr__CloseContainer_x                            0x69CFA0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76A070

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58ED30

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E3500
#define EQ_Spell__SpellAffects_x                                   0x4E0BB0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4E0C20
#define CharacterZoneClient__CalcAffectChange_x                    0x4465F0
#define CLootWnd__LootAll_x                                        0x6FEBA0
#define CLootWnd__RequestLootSlot_x                                0x6FF3B0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B0CB0
#define CTargetWnd__WndNotification_x                              0x7B07A0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7B0E90

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B5F30

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4DC250

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4987C0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DDA40
#define CSidlManager__FindAnimation1_x                             0x8D2E30

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D0BE0
#define CAltAbilityData__GetMercMaxRank_x                          0x4D0B90
#define CAltAbilityData__GetMaxRank_x                              0x4C5950

//CTargetRing
#define CTargetRing__Cast_x                                        0x58C610

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x454E80
#define CharacterBase__CreateItemGlobalIndex_x                     0x471D40
#define CharacterBase__CreateItemIndex_x                           0x50D940
#define CharacterBase__GetItemPossession_x                         0x50EDA0
#define CharacterBase__GetItemByGlobalIndex_x                      0x874850

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x687010
#define CCastSpellWnd__IsBardSongPlaying_x                         0x686770

//messages
#define msg_spell_worn_off_x                                       0x4EB0B0
#define msg_new_text_x                                             0x4F4650
#define msgTokenTextParam_x                                        0x4F1000

//SpellManager
#define SpellManager__vftable_x                                    0xAB6FF0
#define SpellManager__SpellManager_x                               0x47ABD0
#define Spellmanager__CheckSpellRequirementAssociations_x          0x603940

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9278A0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E7630
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43AC20
#define ItemGlobalIndex__IsEquippedLocation_x                      0x444E60
#define ItemGlobalIndex__IsValidIndex_x                            0x454670

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x872660
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8715A0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F7A50
