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
#define __ExpectedVersionDate                                     "Oct 27 2016"
#define __ExpectedVersionTime                                     "04:15:57"
#define __ActualVersionDate_x                                      0xAD0638
#define __ActualVersionTime_x                                      0xAD0644

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTrayBeta"
#define __MacroQuestWinName                                       "MacroQuestBeta"

// Memory Protection
#define __MemChecker0_x                                            0x5A0E20
#define __MemChecker1_x                                            0x895BB0
#define __MemChecker2_x                                            0x637640
#define __MemChecker3_x                                            0x637590
#define __MemChecker4_x                                            0x7E9EF0
#define __EncryptPad0_x                                            0xC74450
#define __EncryptPad1_x                                            0xE00A60
#define __EncryptPad2_x                                            0xCBD250
#define __EncryptPad3_x                                            0xCBCE50
#define __EncryptPad4_x                                            0xDD6A30
#define __EncryptPad5_x                                            0x11B1C98
#define __AC1_x                                                    0x7A9585
#define __AC2_x                                                    0x55AAD7
#define __AC3_x                                                    0x558C70
#define __AC4_x                                                    0x56B4E0
#define __AC5_x                                                    0x57E23B
#define __AC6_x                                                    0x581DEE
#define __AC7_x                                                    0x5788AC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E7620

// Direct Input
#define DI8__Main_x                                                0x11B1C70
#define DI8__Keyboard_x                                            0x11B1C74
#define DI8__Mouse_x                                               0x11B1C78
#define DI8__Mouse_Copy_x                                          0x102035C
#define DI8__Mouse_Check_x                                         0x10A9B5C
#define __Attack_x                                                 0x10A4843
#define __Autofire_x                                               0x10A4844
#define __BindList_x                                               0xC35D90
#define g_eqCommandStates_x                                        0x100F3E8
#define __Clicks_x                                                 0x1020418
#define __CommandList_x                                            0xC3A190
#define __CurrentMapLabel_x                                        0x11B76F8
#define __CurrentSocial_x                                          0xBE8194
#define __DoAbilityList_x                                          0x1056AF8
#define __do_loot_x                                                0x51FF70
#define __DrawHandler_x                                            0x181E5BC
#define __GroupCount_x                                             0x10109B2

#define __Guilds_x                                                 0x10165C8
#define __gWorld_x                                                 0x1012E6C
#define __HotkeyPage_x                                             0x109D4F8
#define __HWnd_x                                                   0x10A9B78
#define __InChatMode_x                                             0x1020344
#define __LastTell_x                                               0x10221F4
#define __LMouseHeldTime_x                                         0x1020484
#define __Mouse_x                                                  0x11B1C7C
#define __MouseLook_x                                              0x10203DE
#define __MouseEventTime_x                                         0x10A5044
#define __gpbCommandEvent_x                                        0x1012F34
#define __NetStatusToggle_x                                        0x10203E1
#define __PCNames_x                                                0x1021810
#define __RangeAttackReady_x                                       0x102154C
#define __RMouseHeldTime_x                                         0x1020480
#define __RunWalkState_x                                           0x1020348
#define __ScreenMode_x                                             0xF5F0E8
#define __ScreenX_x                                                0x10202FC
#define __ScreenY_x                                                0x10202F8
#define __ScreenXMax_x                                             0x1020300
#define __ScreenYMax_x                                             0x1020304
#define __ServerHost_x                                             0x10108FC
#define __ServerName_x                                             0x1056AB8
#define __ShiftKeyDown_x                                           0x10209D8
#define __ShowNames_x                                              0x102170C
#define __Socials_x                                                0x1056BB8
#define __SubscriptionType_x                                       0x11E5704
#define __TargetAggroHolder_x                                      0x11B9934
#define __ZoneType_x                                               0x10207DC
#define __GroupAggro_x                                             0x11B9974
#define __LoginName_x                                              0x10A8754
#define __Inviter_x                                                0x10A47C0
#define __AttackOnAssist_x                                         0x10216C8
#define __UseTellWindows_x                                         0x10219A8

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x1012F58
#define instEQZoneInfo_x                                           0x10205D4
#define instKeypressHandler_x                                      0x10A5028
#define pinstActiveBanker_x                                        0x1012F10
#define pinstActiveCorpse_x                                        0x1012F14
#define pinstActiveGMaster_x                                       0x1012F18
#define pinstActiveMerchant_x                                      0x1012F0C
#define pinstAggroInfo_x                                           0xE1CB48
#define pinstAltAdvManager_x                                       0xF601B0
#define pinstAuraMgr_x                                             0xE2D2B8
#define pinstBandageTarget_x                                       0x1012EF8
#define pinstCamActor_x                                            0xF5FB00
#define pinstCDBStr_x                                              0xF5F07C
#define pinstCDisplay_x                                            0x1012F20
#define pinstCEverQuest_x                                          0x11B1DF0
#define pinstCharData_x                                            0x1012EDC
#define pinstCharSpawn_x                                           0x1012F04
#define pinstControlledMissile_x                                   0x1012ED8
#define pinstControlledPlayer_x                                    0x1012F04
#define pinstCSidlManager_x                                        0x181D9AC
#define pinstCXWndManager_x                                        0x181D9A4
#define instDynamicZone_x                                          0x1020190
#define pinstDZMember_x                                            0x10202A0
#define pinstDZTimerInfo_x                                         0x10202A4
#define pinstEQItemList_x                                          0x100F638
#define pinstEQObjectList_x                                        0x10103AC
#define instEQMisc_x                                               0xC0EDD0
#define pinstEQSoundManager_x                                      0xF60780
#define instExpeditionLeader_x                                     0x10201DA
#define instExpeditionName_x                                       0x102021A
#define pinstGroup_x                                               0x10109AE
#define pinstImeManager_x                                          0x181D9B0
#define pinstLocalPlayer_x                                         0x1012EF0
#define pinstMercenaryData_x                                       0x10A56A8
#define pinstMercenaryStats_x                                      0x11B9A80
#define pinstMercAltAbilities_x                                    0xF60538
#define pinstModelPlayer_x                                         0x1012F1C
#define pinstPCData_x                                              0x1012EDC
#define pinstSkillMgr_x                                            0x10A6510
#define pinstSpawnManager_x                                        0x10A5DF8
#define pinstSpellManager_x                                        0x10A6658
#define pinstSpellSets_x                                           0x109D55C
#define pinstStringTable_x                                         0x1012E84
#define pinstSwitchManager_x                                       0x1010540
#define pinstTarget_x                                              0x1012F08
#define pinstTargetObject_x                                        0x1012EE0
#define pinstTargetSwitch_x                                        0x1012EE4
#define pinstTaskMember_x                                          0xF5EFC8
#define pinstTrackTarget_x                                         0x1012EFC
#define pinstTradeTarget_x                                         0x1012EEC
#define instTributeActive_x                                        0xC0EDF5
#define pinstViewActor_x                                           0xF5FAFC
#define pinstWorldData_x                                           0x1012EC0
#define pinstZoneAddr_x                                            0x1020874
#define pinstPlayerPath_x                                          0x10A5E58
#define pinstTargetIndicator_x                                     0x10A67F0
#define pinstCTargetManager_x                                      0x10A6850

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE1D040
#define pinstCAudioTriggersWindow_x                                0xE1CED0
#define pinstCCharacterSelect_x                                    0xF5F98C
#define pinstCFacePick_x                                           0xF5F73C
#define pinstCNoteWnd_x                                            0xF5F944
#define pinstCBookWnd_x                                            0xF5F94C
#define pinstCPetInfoWnd_x                                         0xF5F950
#define pinstCTrainWnd_x                                           0xF5F954
#define pinstCSkillsWnd_x                                          0xF5F958
#define pinstCSkillsSelectWnd_x                                    0xF5F95C
#define pinstCCombatSkillsSelectWnd_x                              0xF5F960
#define pinstCFriendsWnd_x                                         0xF5F964
#define pinstCAuraWnd_x                                            0xF5F968
#define pinstCRespawnWnd_x                                         0xF5F96C
#define pinstCBandolierWnd_x                                       0xF5F970
#define pinstCPotionBeltWnd_x                                      0xF5F974
#define pinstCAAWnd_x                                              0xF5F978
#define pinstCAlarmWnd_x                                           0xF5F984
#define pinstCGroupSearchFiltersWnd_x                              0xF5F97C
#define pinstCLoadskinWnd_x                                        0xF5F980
#define pinstCLargeDialogWnd_x                                     0x11B8978
#define pinstCMusicPlayerWnd_x                                     0xF5F988
#define pinstCMailWnd_x                                            0xF5F990
#define pinstCMailCompositionWnd_x                                 0xF5F994
#define pinstCMailAddressBookWnd_x                                 0xF5F998
#define pinstCRaidWnd_x                                            0xF5F9A0
#define pinstCRaidOptionsWnd_x                                     0xF5F9A4
#define pinstCBreathWnd_x                                          0xF5F9A8
#define pinstCMapViewWnd_x                                         0xF5F9AC
#define pinstCMapToolbarWnd_x                                      0xF5F9B0
#define pinstCEditLabelWnd_x                                       0xF5F9B4
#define pinstCTargetWnd_x                                          0xF5F9B8
#define pinstCColorPickerWnd_x                                     0xF5F9BC
#define pinstCPlayerWnd_x                                          0xF5F9C0
#define pinstCOptionsWnd_x                                         0xF5F9C4
#define pinstCBuffWindowNORMAL_x                                   0xF5F9C8
#define pinstCBuffWindowSHORT_x                                    0xF5F9CC
#define pinstCharacterCreation_x                                   0xF5F9D0
#define pinstCCursorAttachment_x                                   0xF5F9D4
#define pinstCCastingWnd_x                                         0xF5F9D8
#define pinstCCastSpellWnd_x                                       0xF5F9DC
#define pinstCSpellBookWnd_x                                       0xF5F9E0
#define pinstCInventoryWnd_x                                       0xF5F9E4
#define pinstCBankWnd_x                                            0xF5F9EC
#define pinstCQuantityWnd_x                                        0xF5F9F0
#define pinstCLootWnd_x                                            0xF5F9F4
#define pinstCActionsWnd_x                                         0xF5F9F8
#define pinstCCombatAbilityWnd_x                                   0xF5FA00
#define pinstCMerchantWnd_x                                        0xF5FA04
#define pinstCTradeWnd_x                                           0xF5FA08
#define pinstCSelectorWnd_x                                        0xF5FA0C
#define pinstCBazaarWnd_x                                          0xF5FA10
#define pinstCBazaarSearchWnd_x                                    0xF5FA14
#define pinstCGiveWnd_x                                            0xF5FA30
#define pinstCTrackingWnd_x                                        0xF5FA38
#define pinstCInspectWnd_x                                         0xF5FA3C
#define pinstCSocialEditWnd_x                                      0xF5FA40
#define pinstCFeedbackWnd_x                                        0xF5FA44
#define pinstCBugReportWnd_x                                       0xF5FA48
#define pinstCVideoModesWnd_x                                      0xF5FA4C
#define pinstCTextEntryWnd_x                                       0xF5FA54
#define pinstCFileSelectionWnd_x                                   0xF5FA58
#define pinstCCompassWnd_x                                         0xF5FA5C
#define pinstCPlayerNotesWnd_x                                     0xF5FA60
#define pinstCGemsGameWnd_x                                        0xF5FA64
#define pinstCTimeLeftWnd_x                                        0xF5FA68
#define pinstCPetitionQWnd_x                                       0xF5FA84
#define pinstCSoulmarkWnd_x                                        0xF5FA88
#define pinstCStoryWnd_x                                           0xF5FA8C
#define pinstCJournalTextWnd_x                                     0xF5FA90
#define pinstCJournalCatWnd_x                                      0xF5FA94
#define pinstCBodyTintWnd_x                                        0xF5FA98
#define pinstCServerListWnd_x                                      0xF5FA9C
#define pinstCAvaZoneWnd_x                                         0xF5FAA8
#define pinstCBlockedBuffWnd_x                                     0xF5FAAC
#define pinstCBlockedPetBuffWnd_x                                  0xF5FAB0
#define pinstCInvSlotMgr_x                                         0xF5FAF4
#define pinstCContainerMgr_x                                       0xF5FAF8
#define pinstCAdventureLeaderboardWnd_x                            0x11B27A0
#define pinstCAdventureRequestWnd_x                                0x11B2818
#define pinstCAltStorageWnd_x                                      0x11B2AF8
#define pinstCAdventureStatsWnd_x                                  0x11B2890
#define pinstCBarterMerchantWnd_x                                  0x11B36E0
#define pinstCBarterSearchWnd_x                                    0x11B3758
#define pinstCBarterWnd_x                                          0x11B37D0
#define pinstCChatManager_x                                        0x11B3E60
#define pinstCDynamicZoneWnd_x                                     0x11B4310
#define pinstCEQMainWnd_x                                          0x11B44A8
#define pinstCFellowshipWnd_x                                      0x11B42A4
#define pinstCFindLocationWnd_x                                    0x11B4778
#define pinstCGroupSearchWnd_x                                     0x11B4A48
#define pinstCGroupWnd_x                                           0x11B4AC0
#define pinstCGuildBankWnd_x                                       0x11B4B38
#define pinstCGuildMgmtWnd_x                                       0x11B6C28
#define pinstCHotButtonWnd_x                                       0x11B6D24
#define pinstCHotButtonWnd1_x                                      0x11B6D24
#define pinstCHotButtonWnd2_x                                      0x11B6D28
#define pinstCHotButtonWnd3_x                                      0x11B6D2C
#define pinstCHotButtonWnd4_x                                      0x11B6D50
#define pinstCItemDisplayManager_x                                 0x11B7048
#define pinstCItemExpTransferWnd_x                                 0x11B70C4
#define pinstCLFGuildWnd_x                                         0x11B73A0
#define pinstCMIZoneSelectWnd_x                                    0x11B7988
#define pinstCConfirmationDialog_x                                 0x11B8090
#define pinstCPopupWndManager_x                                    0x11B8090
#define pinstCProgressionSelectionWnd_x                            0x11B8180
#define pinstCPvPStatsWnd_x                                        0x11B8270
#define pinstCTaskWnd_x                                            0x11B9D40
#define pinstCTaskSomething_x                                      0xE2DB70
#define pinstCTaskTemplateSelectWnd_x                              0x11B9CC8
#define pinstCTipWndOFDAY_x                                        0x11B9EA8
#define pinstCTipWndCONTEXT_x                                      0x11B9EAC
#define pinstCTitleWnd_x                                           0x11B9F28
#define pinstCContextMenuManager_x                                 0x181D91C
#define pinstCVoiceMacroWnd_x                                      0x10A6C28
#define pinstCHtmlWnd_x                                            0x10A6D18
#define pinstIconCache_x                                           0x11B447C
#define pinstCTradeskillWnd_x                                      0x11BA028
#define pinstCAdvancedLootWnd_x                                    0xF5FAE8
#define pinstRewardSelectionWnd_x                                  0x11B8798

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x537210
#define __ConvertItemTags_x                                        0x524AD0
#define __ExecuteCmd_x                                             0x50F380
#define __EQGetTime_x                                              0x895840
#define __get_melee_range_x                                        0x515F60
#define __GetGaugeValueFromEQ_x                                    0x7A82C0
#define __GetLabelFromEQ_x                                         0x7A9510
#define __ToggleKeyRingItem_x                                      0x4800C0
#define __GetXTargetType_x                                         0x926570
#define __LoadFrontEnd_x                                           0x636D10
#define __NewUIINI_x                                               0x7A7C90
#define __ProcessGameEvents_x                                      0x57A640
#define __ProcessMouseEvent_x                                      0x579DE0
#define CrashDetected_x                                            0x6386D0
#define wwsCrashReportCheckForUploader_x                           0x7F5E60
#define DrawNetStatus_x                                            0x5B0BB0
#define Util__FastTime_x                                           0x8954E0
#define Expansion_HoT_x                                            0x10216B8
#define __HelpPath_x                                               0x10A4DB0
#define __STMLToText_x                                             0x8DB3D0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4204D0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B270
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B050

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C73D0
#define AltAdvManager__IsAbilityReady_x                            0x4C7440
#define AltAdvManager__GetAAById_x                                 0x4C7800
#define AltAdvManager__CanTrainAbility_x                           0x4C8100
#define AltAdvManager__CanSeeAbility_x                             0x4C7CC0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463570
#define CharacterZoneClient__MakeMeVisible_x                       0x468020
#define CharacterZoneClient__IsStackBlocked_x                      0x447B70
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x447030
#define CharacterZoneClient__GetItemCountWorn_x                    0x4613A0
#define CharacterZoneClient__GetItemCountInInventory_x             0x461480
#define CharacterZoneClient__GetCursorItemCount_x                  0x461560

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6667B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x674BB0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58FC70
#define CButtonWnd__CButtonWnd_x                                   0x8CF7A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68FBD0
#define CChatManager__InitContextMenu_x                            0x690750

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D9730
#define CContextMenu__dCContextMenu_x                              0x8D9940
#define CContextMenu__AddMenuItem_x                                0x8D9950
#define CContextMenu__RemoveMenuItem_x                             0x8D9C40
#define CContextMenu__RemoveAllMenuItems_x                         0x8D9C60
#define CContextMenuManager__AddMenu_x                             0x8C5D10
#define CContextMenuManager__RemoveMenu_x                          0x8C60B0
#define CContextMenuManager__PopupMenu_x                           0x8C6500
#define CContextMenuManager__Flush_x                               0x8C5D80
#define CContextMenuManager__GetMenu_x                             0x416950

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87A320
#define CChatService__GetFriendName_x                              0x87A330

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6959B0
#define CChatWindow__Clear_x                                       0x695580
#define CChatWindow__WndNotification_x                             0x695EF0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C9B80
#define CComboWnd__Draw_x                                          0x8C9D90
#define CComboWnd__GetCurChoice_x                                  0x8C9930
#define CComboWnd__GetListRect_x                                   0x8CA030
#define CComboWnd__GetTextRect_x                                   0x8C9BF0
#define CComboWnd__InsertChoice_x                                  0x8CA0A0
#define CComboWnd__SetColors_x                                     0x8C98C0
#define CComboWnd__SetChoice_x                                     0x8C98F0
#define CComboWnd__GetItemCount_x                                  0x8C9920
#define CComboWnd__GetCurChoiceText_x                              0x8C9970


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69F060
#define CContainerWnd__vftable_x                                   0xADA118

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B58F0
#define CDisplay__GetClickedActor_x                                0x4AE220
#define CDisplay__GetUserDefinedColor_x                            0x4ACE00
#define CDisplay__GetWorldFilePath_x                               0x4AC250
#define CDisplay__is3dON_x                                         0x4AB6E0
#define CDisplay__ReloadUI_x                                       0x4C0E60
#define CDisplay__WriteTextHD2_x                                   0x4B1CB0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8EFD60

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DDC60
#define CEditWnd__GetCharIndexPt_x                                 0x8DECF0
#define CEditWnd__GetDisplayString_x                               0x8DDE10
#define CEditWnd__GetHorzOffset_x                                  0x8DE150
#define CEditWnd__GetLineForPrintableChar_x                        0x8DE7C0
#define CEditWnd__GetSelStartPt_x                                  0x8DEFA0
#define CEditWnd__GetSTMLSafeText_x                                0x8DE2F0
#define CEditWnd__PointFromPrintableChar_x                         0x8DE8B0
#define CEditWnd__SelectableCharFromPoint_x                        0x8DEA30
#define CEditWnd__SetEditable_x                                    0x8DE2C0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x55B220
#define CEverQuest__CreateTargetIndicator_x                        0x55C110
#define CEverQuest__DeleteTargetIndicator_x                        0x55C190
#define CEverQuest__DoTellWindow_x                                 0x472C60
#define CEverQuest__DropHeldItemOnGround_x                         0x572330
#define CEverQuest__dsp_chat_x                                     0x472FA0
#define CEverQuest__trimName_x                                     0x557B70
#define CEverQuest__Emote_x                                        0x570680
#define CEverQuest__EnterZone_x                                    0x56B670
#define CEverQuest__GetBodyTypeDesc_x                              0x5555D0
#define CEverQuest__GetClassDesc_x                                 0x55EEA0
#define CEverQuest__GetClassThreeLetterCode_x                      0x55F4A0
#define CEverQuest__GetDeityDesc_x                                 0x555EB0
#define CEverQuest__GetLangDesc_x                                  0x555960
#define CEverQuest__GetRaceDesc_x                                  0x55F660
#define CEverQuest__InterpretCmd_x                                 0x563490
#define CEverQuest__LeftClickedOnPlayer_x                          0x576D00
#define CEverQuest__LMouseUp_x                                     0x578E00
#define CEverQuest__RightClickedOnPlayer_x                         0x577810
#define CEverQuest__RMouseUp_x                                     0x578860
#define CEverQuest__SetGameState_x                                 0x55BAE0
#define CEverQuest__UPCNotificationFlush_x                         0x5533E0
#define CEverQuest__IssuePetCommand_x                              0x563E70

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AFE00
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AFE60
#define CGaugeWnd__Draw_x                                          0x6B0290

// CGuild
#define CGuild__FindMemberByName_x                                 0x437430
#define CGuild__GetGuildName_x                                     0x437900
#define CGuild__GetGuildIndex_x                                    0x438AD0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CC310

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D94B0
#define CInvSlotMgr__MoveItem_x                                    0x6DA360
#define CInvSlotMgr__SelectSlot_x                                  0x6D9560

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D8960
#define CInvSlot__SliderComplete_x                                 0x6D6170
#define CInvSlot__GetItemBase_x                                    0x6D55F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DB7B0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A3CB0
#define CItemDisplayWnd__UpdateStrings_x                           0x6DD8F0

// CLabel 
#define CLabel__Draw_x                                             0x6F73B0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B5950
#define CListWnd__dCListWnd_x                                      0x8B6B60
#define CListWnd__AddColumn_x                                      0x8B6B00
#define CListWnd__AddColumn1_x                                     0x8B61A0
#define CListWnd__AddLine_x                                        0x8B5C00
#define CListWnd__AddString_x                                      0x8B5E20
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B2BF0
#define CListWnd__CalculateVSBRange_x                              0x8B4E20
#define CListWnd__ClearSel_x                                       0x8B1F10
#define CListWnd__ClearAllSel_x                                    0x8B1EC0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B57E0
#define CListWnd__Compare_x                                        0x8B3750
#define CListWnd__Draw_x                                           0x8B4A20
#define CListWnd__DrawColumnSeparators_x                           0x8B48B0
#define CListWnd__DrawHeader_x                                     0x8B21D0
#define CListWnd__DrawItem_x                                       0x8B3DE0
#define CListWnd__DrawLine_x                                       0x8B4550
#define CListWnd__DrawSeparator_x                                  0x8B4950
#define CListWnd__EnsureVisible_x                                  0x8B2D50
#define CListWnd__ExtendSel_x                                      0x8B3CF0
#define CListWnd__GetColumnMinWidth_x                              0x8B18C0
#define CListWnd__GetColumnWidth_x                                 0x8B17F0
#define CListWnd__GetCurSel_x                                      0x8B0FD0
#define CListWnd__GetItemAtPoint_x                                 0x8B2FE0
#define CListWnd__GetItemAtPoint1_x                                0x8B3050
#define CListWnd__GetItemData_x                                    0x8B1300
#define CListWnd__GetItemHeight_x                                  0x8B2850
#define CListWnd__GetItemIcon_x                                    0x8B14F0
#define CListWnd__GetItemRect_x                                    0x8B2E20
#define CListWnd__GetItemText_x                                    0x8B13A0
#define CListWnd__GetSelList_x                                     0x8B6090
#define CListWnd__GetSeparatorRect_x                               0x8B3680
#define CListWnd__RemoveLine_x                                     0x8B6010
#define CListWnd__SetColors_x                                      0x8B1120
#define CListWnd__SetColumnJustification_x                         0x8B1B50
#define CListWnd__SetColumnWidth_x                                 0x8B1870
#define CListWnd__SetCurSel_x                                      0x8B1010
#define CListWnd__SetItemColor_x                                   0x8B54D0
#define CListWnd__SetItemData_x                                    0x8B1F70
#define CListWnd__SetItemText_x                                    0x8B5310
#define CListWnd__ShiftColumnSeparator_x                           0x8B51A0
#define CListWnd__Sort_x                                           0x8B6C60
#define CListWnd__ToggleSel_x                                      0x8B1E40

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x710560

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x731900
#define CMerchantWnd__RequestBuyItem_x                             0x7389A0
#define CMerchantWnd__RequestSellItem_x                            0x739470
#define CMerchantWnd__SelectRecoverySlot_x                         0x731BB0
#define CMerchantWnd__SelectBuySellSlot_x                          0x730DB0
#define CMerchantWnd__ActualSelect_x                               0x735870

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x849AC0
#define CPacketScrambler__hton_x                                   0x849AD0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D47C0
#define CSidlManager__CreateLabel_x                                0x799C60

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65DB30
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65DA60
#define CSidlScreenWnd__ConvertToRes_x                             0x8EFC40
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CC510
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CD6F0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CD7A0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CCC70
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CBEC0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CB640
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CC0B0
#define CSidlScreenWnd__Init1_x                                    0x8CD3D0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CC5C0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CB800
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CCEB0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CB290
#define CSidlScreenWnd__StoreIniVis_x                              0x8CB5F0
#define CSidlScreenWnd__WndNotification_x                          0x8CD150
#define CSidlScreenWnd__GetChildItem_x                             0x8CB710
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BEFD0
#define CSidlScreenWnd__m_layoutCopy_x                             0x181D980

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FC9A0
#define CSkillMgr__GetSkillCap_x                                   0x5FCB80
#define CSkillMgr__GetNameToken_x                                  0x5FC5C0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8EEF10
#define CSliderWnd__SetValue_x                                     0x8EF0E0
#define CSliderWnd__SetNumTicks_x                                  0x8EF860

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A1910

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EA890
#define CStmlWnd__CalculateHSBRange_x                              0x8E2DF0
#define CStmlWnd__CalculateVSBRange_x                              0x8E2E80
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E3000
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E38E0
#define CStmlWnd__ForceParseNow_x                                  0x8EB1E0
#define CStmlWnd__GetNextTagPiece_x                                0x8E37E0
#define CStmlWnd__GetSTMLText_x                                    0x694E20
#define CStmlWnd__GetVisibleText_x                                 0x8E4330
#define CStmlWnd__InitializeWindowVariables_x                      0x8E66A0
#define CStmlWnd__MakeStmlColorTag_x                               0x8E20F0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E2150
#define CStmlWnd__SetSTMLText_x                                    0x8E7EF0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EA530
#define CStmlWnd__UpdateHistoryString_x                            0x8E5260

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E1810
#define CTabWnd__DrawCurrentPage_x                                 0x8E10A0
#define CTabWnd__DrawTab_x                                         0x8E0E60
#define CTabWnd__GetCurrentPage_x                                  0x8E1450
#define CTabWnd__GetPageInnerRect_x                                0x8E0B50
#define CTabWnd__GetTabInnerRect_x                                 0x8E0D50
#define CTabWnd__GetTabRect_x                                      0x8E0C20
#define CTabWnd__InsertPage_x                                      0x8E1B00
#define CTabWnd__SetPage_x                                         0x8E1480
#define CTabWnd__SetPageRect_x                                     0x8E1750
#define CTabWnd__UpdatePage_x                                      0x8E1AA0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432FC0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C9530

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x634FB0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F5070

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8AF020

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59D2E0
#define CXStr__CXStr1_x                                            0x8A3F20
#define CXStr__CXStr3_x                                            0x8927C0
#define CXStr__dCXStr_x                                            0x59D6E0
#define CXStr__operator_equal_x                                    0x892930
#define CXStr__operator_equal1_x                                   0x892980
#define CXStr__operator_plus_equal1_x                              0x893A80

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BE210
#define CXWnd__Center_x                                            0x8C4340
#define CXWnd__ClrFocus_x                                          0x8BDDE0
#define CXWnd__DoAllDrawing_x                                      0x8C3F90
#define CXWnd__DrawChildren_x                                      0x8C4130
#define CXWnd__DrawColoredRect_x                                   0x8BE5D0
#define CXWnd__DrawTooltip_x                                       0x8BE860
#define CXWnd__DrawTooltipAtPoint_x                                0x8C2F10
#define CXWnd__GetBorderFrame_x                                    0x8BECA0
#define CXWnd__GetChildWndAt_x                                     0x8C4D00
#define CXWnd__GetClientClipRect_x                                 0x8BEA70
#define CXWnd__GetScreenClipRect_x                                 0x8C3610
#define CXWnd__GetScreenRect_x                                     0x8BEE70
#define CXWnd__GetTooltipRect_x                                    0x8BE6F0
#define CXWnd__GetWindowTextA_x                                    0x4245C0
#define CXWnd__IsActive_x                                          0x8B9910
#define CXWnd__IsDescendantOf_x                                    0x8BEBE0
#define CXWnd__IsReallyVisible_x                                   0x8C1F90
#define CXWnd__IsType_x                                            0x8F1890
#define CXWnd__Move_x                                              0x8C1680
#define CXWnd__Move1_x                                             0x8C3C50
#define CXWnd__ProcessTransition_x                                 0x8BE1B0
#define CXWnd__Refade_x                                            0x8BDF80
#define CXWnd__Resize_x                                            0x8BEF30
#define CXWnd__Right_x                                             0x8C3410
#define CXWnd__SetFocus_x                                          0x8C07F0
#define CXWnd__SetFont_x                                           0x8BDE30
#define CXWnd__SetKeyTooltip_x                                     0x8BF1A0
#define CXWnd__SetMouseOver_x                                      0x8C3950
#define CXWnd__StartFade_x                                         0x8BE260
#define CXWnd__GetChildItem_x                                      0x8C3890

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BB1B0
#define CXWndManager__DrawWindows_x                                0x8BADF0
#define CXWndManager__GetKeyboardFlags_x                           0x8B9440
#define CXWndManager__HandleKeyboardMsg_x                          0x8B9DA0
#define CXWndManager__RemoveWnd_x                                  0x8B9AA0

// CDBStr
#define CDBStr__GetString_x                                        0x4A9C10

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E110
#define EQ_Character__Cur_HP_x                                     0x462C10
#define EQ_Character__Cur_Mana_x                                   0x456740
#define EQ_Character__GetAACastingTimeModifier_x                   0x447340
#define EQ_Character__GetCharInfo2_x                               0x8662E0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F630
#define EQ_Character__GetFocusRangeModifier_x                      0x43F690
#define EQ_Character__Max_Endurance_x                              0x5C26F0
#define EQ_Character__Max_HP_x                                     0x459360
#define EQ_Character__Max_Mana_x                                   0x5C2520
#define EQ_Character__doCombatAbility_x                            0x5BFC10
#define EQ_Character__UseSkill_x                                   0x46D0A0
#define EQ_Character__GetConLevel_x                                0x5B51E0
#define EQ_Character__IsExpansionFlag_x                            0x423B00
#define EQ_Character__TotalEffect_x                                0x44B3A0
#define EQ_Character__GetPCSpellAffect_x                           0x447740
#define EQ_Character__SpellDuration_x                              0x445640
#define EQ_Character__FindItemByRecord_x                           0x460090

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x442960
#define CCharacterSelect__EnterWorld_x                             0x442130
#define CCharacterSelect__Quit_x                                   0x440D10

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5954E0
#define EQ_Item__CreateItemTagString_x                             0x8484C0
#define EQ_Item__IsStackable_x                                     0x83DE70
#define EQ_Item__GetImageNum_x                                     0x840940
#define EQ_Item__CreateItemClient_x                                0x5960C0
#define EQ_Item__GetItemValue_x                                    0x8471A0
#define EQ_Item__ValueSellMerchant_x                               0x849760
#define EQ_Item__IsKeyRingItem_x                                   0x83E950
#define EQ_Item__CanGoInBag_x                                      0x595670
#define EQ_Item__GetMaxItemCount_x                                 0x83DD60
#define EQ_Item__GetHeldItem_x                                     0x83F740

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C95B0
#define EQ_LoadingS__Array_x                                       0xC1B680

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C4C10
#define EQ_PC__GetAlternateAbilityId_x                             0x851AC0
#define EQ_PC__GetCombatAbility_x                                  0x851B50
#define EQ_PC__GetCombatAbilityTimer_x                             0x84C8D0
#define EQ_PC__GetItemTimerValue_x                                 0x5BE2D0
#define EQ_PC__HasLoreItem_x                                       0x5B8700
#define EQ_PC__AlertInventoryChanged_x                             0x5B51B0
#define EQ_PC__GetPcZoneClient_x                                   0x5DF400
#define EQ_PC__RemoveMyAffect_x                                    0x5BD760
#define EQ_PC__GetKeyRingItems_x                                   0x84CCF0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x514000
#define EQItemList__add_object_x                                   0x53FF50
#define EQItemList__add_item_x                                     0x513F40
#define EQItemList__delete_item_x                                  0x5143F0
#define EQItemList__FreeItemList_x                                 0x5142F0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A8F30

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5CA270
#define EQPlayer__dEQPlayer_x                                      0x5D3140
#define EQPlayer__DoAttack_x                                       0x5E5300
#define EQPlayer__EQPlayer_x                                       0x5D5850
#define EQPlayer__SetNameSpriteState_x                             0x5D0090
#define EQPlayer__SetNameSpriteTint_x                              0x5CB680
#define PlayerBase__HasProperty_j_x                                0x922750
#define EQPlayer__IsTargetable_x                                   0x923050
#define EQPlayer__CanSee_x                                         0x923570
#define PlayerZoneClient__ChangeHeight_x                           0x5E51C0
#define EQPlayer__CanSeeTargetIndicator_x                          0x923660
#define PlayerBase__GetVisibilityLineSegment_x                     0x923300

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D9A50
#define EQPlayerManager__GetSpawnByName_x                          0x5D9EB0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D9A80

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59B670
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59B6B0
#define KeypressHandler__ClearCommandStateArray_x                  0x59B260
#define KeypressHandler__HandleKeyDown_x                           0x599BC0
#define KeypressHandler__HandleKeyUp_x                             0x599EE0
#define KeypressHandler__SaveKeymapping_x                          0x59B330

// MapViewMap 
#define MapViewMap__Clear_x                                        0x708EF0
#define MapViewMap__SaveEx_x                                       0x70C220

#define PlayerPointManager__GetAltCurrency_x                       0x864360

// StringTable 
#define StringTable__getString_x                                   0x85EF10

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C2180
#define PcZoneClient__RemovePetEffect_x                            0x5BE7A0
#define PcZoneClient__HasAlternateAbility_x                        0x5BF140
#define PcZoneClient__GetCurrentMod_x                              0x458700
#define PcZoneClient__GetModCap_x                                  0x455EC0
#define PcZoneClient__CanEquipItem_x                               0x5BF6F0

//Doors
#define EQSwitch__UseSwitch_x                                      0x551D30

//IconCache
#define IconCache__GetIcon_x                                       0x6A5690

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69C3F0
#define CContainerMgr__CloseContainer_x                            0x69CC10

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x769B70

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58E6E0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E32E0
#define EQ_Spell__SpellAffects_x                                   0x4E0990
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4E0A00
#define CharacterZoneClient__CalcAffectChange_x                    0x446770
#define CLootWnd__LootAll_x                                        0x6FE750
#define CLootWnd__RequestLootSlot_x                                0x6FEF60

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B0710
#define CTargetWnd__WndNotification_x                              0x7B0200
#define CTargetWnd__RefreshTargetBuffs_x                           0x7B08F0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B5970

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4DC1A0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x498940

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DD290
#define CSidlManager__FindAnimation1_x                             0x8D26A0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D0C30
#define CAltAbilityData__GetMercMaxRank_x                          0x4D0BE0
#define CAltAbilityData__GetMaxRank_x                              0x4C5A80

//CTargetRing
#define CTargetRing__Cast_x                                        0x58BFD0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x454F80
#define CharacterBase__CreateItemGlobalIndex_x                     0x471E70
#define CharacterBase__CreateItemIndex_x                           0x50D490
#define CharacterBase__GetItemPossession_x                         0x50E920
#define CharacterBase__GetItemByGlobalIndex_x                      0x874440

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x686CA0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x686400

//messages
#define msg_spell_worn_off_x                                       0x4EAE90
#define msg_new_text_x                                             0x4F4430
#define msgTokenTextParam_x                                        0x4F0DE0

//SpellManager
#define SpellManager__vftable_x                                    0xAB5FF8
#define SpellManager__SpellManager_x                               0x47AD20
#define Spellmanager__CheckSpellRequirementAssociations_x          0x6037A0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x927090

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E7430
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43AD30
#define ItemGlobalIndex__IsEquippedLocation_x                      0x444FD0
#define ItemGlobalIndex__IsValidIndex_x                            0x454840

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x872250
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x871190

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F7600
