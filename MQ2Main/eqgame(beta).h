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
#define __ExpectedVersionDate                                     "Oct 24 2016"
#define __ExpectedVersionTime                                     "04:15:41"
#define __ActualVersionDate_x                                      0xAD0648
#define __ActualVersionTime_x                                      0xAD0654

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTrayBeta"
#define __MacroQuestWinName                                       "MacroQuestBeta"

// Memory Protection
#define __MemChecker0_x                                            0x5A0B80
#define __MemChecker1_x                                            0x895B60
#define __MemChecker2_x                                            0x637290
#define __MemChecker3_x                                            0x6371E0
#define __MemChecker4_x                                            0x7E9BE0
#define __EncryptPad0_x                                            0xC74450
#define __EncryptPad1_x                                            0xE00A60
#define __EncryptPad2_x                                            0xCBD250
#define __EncryptPad3_x                                            0xCBCE50
#define __EncryptPad4_x                                            0xDD6A30
#define __EncryptPad5_x                                            0x11B1C98
#define __AC1_x                                                    0x7A96C5
#define __AC2_x                                                    0x55A877
#define __AC3_x                                                    0x558A10
#define __AC4_x                                                    0x56B280
#define __AC5_x                                                    0x57DFDB
#define __AC6_x                                                    0x581B8E
#define __AC7_x                                                    0x57864C
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
#define __do_loot_x                                                0x51FD90
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
#define __CastRay_x                                                0x537030
#define __ConvertItemTags_x                                        0x5248F0
#define __ExecuteCmd_x                                             0x50F1A0
#define __EQGetTime_x                                              0x8957F0
#define __get_melee_range_x                                        0x515D80
#define __GetGaugeValueFromEQ_x                                    0x7A8400
#define __GetLabelFromEQ_x                                         0x7A9650
#define __ToggleKeyRingItem_x                                      0x480000
#define __GetXTargetType_x                                         0x9266B0
#define __LoadFrontEnd_x                                           0x636960
#define __NewUIINI_x                                               0x7A7DD0
#define __ProcessGameEvents_x                                      0x57A3E0
#define __ProcessMouseEvent_x                                      0x579B80
#define CrashDetected_x                                            0x638320
#define wwsCrashReportCheckForUploader_x                           0x7F5A80
#define DrawNetStatus_x                                            0x5B0790
#define Util__FastTime_x                                           0x895490
#define Expansion_HoT_x                                            0x10216B8
#define __HelpPath_x                                               0x10A4DB0
#define __STMLToText_x                                             0x8DB480

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4204D0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B270
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B050

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C74D0
#define AltAdvManager__IsAbilityReady_x                            0x4C7540
#define AltAdvManager__GetAAById_x                                 0x4C7900
#define AltAdvManager__CanTrainAbility_x                           0x4C8200
#define AltAdvManager__CanSeeAbility_x                             0x4C7DC0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463520
#define CharacterZoneClient__MakeMeVisible_x                       0x467FD0
#define CharacterZoneClient__IsStackBlocked_x                      0x447AA0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x446F60
#define CharacterZoneClient__GetItemCountWorn_x                    0x461350
#define CharacterZoneClient__GetItemCountInInventory_x             0x461430
#define CharacterZoneClient__GetCursorItemCount_x                  0x461510

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x666400

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6747C0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58FB30
#define CButtonWnd__CButtonWnd_x                                   0x8CF7E0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68F830
#define CChatManager__InitContextMenu_x                            0x6903B0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D97E0
#define CContextMenu__dCContextMenu_x                              0x8D99F0
#define CContextMenu__AddMenuItem_x                                0x8D9A00
#define CContextMenu__RemoveMenuItem_x                             0x8D9CF0
#define CContextMenu__RemoveAllMenuItems_x                         0x8D9D10
#define CContextMenuManager__AddMenu_x                             0x8C5D60
#define CContextMenuManager__RemoveMenu_x                          0x8C6110
#define CContextMenuManager__PopupMenu_x                           0x8C6560
#define CContextMenuManager__Flush_x                               0x8C5DD0
#define CContextMenuManager__GetMenu_x                             0x416950

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87A260
#define CChatService__GetFriendName_x                              0x87A270

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x695610
#define CChatWindow__Clear_x                                       0x6951E0
#define CChatWindow__WndNotification_x                             0x695B50

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C9BD0
#define CComboWnd__Draw_x                                          0x8C9DE0
#define CComboWnd__GetCurChoice_x                                  0x8C9980
#define CComboWnd__GetListRect_x                                   0x8CA080
#define CComboWnd__GetTextRect_x                                   0x8C9C40
#define CComboWnd__InsertChoice_x                                  0x8CA0F0
#define CComboWnd__SetColors_x                                     0x8C9910
#define CComboWnd__SetChoice_x                                     0x8C9940
#define CComboWnd__GetItemCount_x                                  0x8C9970
#define CComboWnd__GetCurChoiceText_x                              0x8C99C0


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69ED20
#define CContainerWnd__vftable_x                                   0xADA128

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B5A10
#define CDisplay__GetClickedActor_x                                0x4AE340
#define CDisplay__GetUserDefinedColor_x                            0x4ACF20
#define CDisplay__GetWorldFilePath_x                               0x4AC370
#define CDisplay__is3dON_x                                         0x4AB800
#define CDisplay__ReloadUI_x                                       0x4C0F80
#define CDisplay__WriteTextHD2_x                                   0x4B1DD0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8EFE20

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DDD10
#define CEditWnd__GetCharIndexPt_x                                 0x8DEDA0
#define CEditWnd__GetDisplayString_x                               0x8DDEC0
#define CEditWnd__GetHorzOffset_x                                  0x8DE200
#define CEditWnd__GetLineForPrintableChar_x                        0x8DE870
#define CEditWnd__GetSelStartPt_x                                  0x8DF050
#define CEditWnd__GetSTMLSafeText_x                                0x8DE3A0
#define CEditWnd__PointFromPrintableChar_x                         0x8DE960
#define CEditWnd__SelectableCharFromPoint_x                        0x8DEAE0
#define CEditWnd__SetEditable_x                                    0x8DE370

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x55AFC0
#define CEverQuest__CreateTargetIndicator_x                        0x55BEB0
#define CEverQuest__DeleteTargetIndicator_x                        0x55BF30
#define CEverQuest__DoTellWindow_x                                 0x472C60
#define CEverQuest__DropHeldItemOnGround_x                         0x5720D0
#define CEverQuest__dsp_chat_x                                     0x472FA0
#define CEverQuest__trimName_x                                     0x557910
#define CEverQuest__Emote_x                                        0x570420
#define CEverQuest__EnterZone_x                                    0x56B410
#define CEverQuest__GetBodyTypeDesc_x                              0x555370
#define CEverQuest__GetClassDesc_x                                 0x55EC40
#define CEverQuest__GetClassThreeLetterCode_x                      0x55F240
#define CEverQuest__GetDeityDesc_x                                 0x555C50
#define CEverQuest__GetLangDesc_x                                  0x555700
#define CEverQuest__GetRaceDesc_x                                  0x55F400
#define CEverQuest__InterpretCmd_x                                 0x563230
#define CEverQuest__LeftClickedOnPlayer_x                          0x576AA0
#define CEverQuest__LMouseUp_x                                     0x578BA0
#define CEverQuest__RightClickedOnPlayer_x                         0x5775B0
#define CEverQuest__RMouseUp_x                                     0x578600
#define CEverQuest__SetGameState_x                                 0x55B880
#define CEverQuest__UPCNotificationFlush_x                         0x553180
#define CEverQuest__IssuePetCommand_x                              0x563C10

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AFCC0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AFD20
#define CGaugeWnd__Draw_x                                          0x6B0150

// CGuild
#define CGuild__FindMemberByName_x                                 0x437370
#define CGuild__GetGuildName_x                                     0x437840
#define CGuild__GetGuildIndex_x                                    0x438A10

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CC1D0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D9370
#define CInvSlotMgr__MoveItem_x                                    0x6DA220
#define CInvSlotMgr__SelectSlot_x                                  0x6D9420

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D8820
#define CInvSlot__SliderComplete_x                                 0x6D6030
#define CInvSlot__GetItemBase_x                                    0x6D54C0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DB670

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A3DF0
#define CItemDisplayWnd__UpdateStrings_x                           0x6DD7A0

// CLabel 
#define CLabel__Draw_x                                             0x6F7340

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B57C0
#define CListWnd__dCListWnd_x                                      0x8B69F0
#define CListWnd__AddColumn_x                                      0x8B6990
#define CListWnd__AddColumn1_x                                     0x8B6020
#define CListWnd__AddLine_x                                        0x8B5A80
#define CListWnd__AddString_x                                      0x8B5CA0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B2A60
#define CListWnd__CalculateVSBRange_x                              0x8B4C90
#define CListWnd__ClearSel_x                                       0x8B1D80
#define CListWnd__ClearAllSel_x                                    0x8B1D30
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B5650
#define CListWnd__Compare_x                                        0x8B35C0
#define CListWnd__Draw_x                                           0x8B4890
#define CListWnd__DrawColumnSeparators_x                           0x8B4720
#define CListWnd__DrawHeader_x                                     0x8B2040
#define CListWnd__DrawItem_x                                       0x8B3C50
#define CListWnd__DrawLine_x                                       0x8B43C0
#define CListWnd__DrawSeparator_x                                  0x8B47C0
#define CListWnd__EnsureVisible_x                                  0x8B2BC0
#define CListWnd__ExtendSel_x                                      0x8B3B60
#define CListWnd__GetColumnMinWidth_x                              0x8B1730
#define CListWnd__GetColumnWidth_x                                 0x8B1660
#define CListWnd__GetCurSel_x                                      0x8B0E30
#define CListWnd__GetItemAtPoint_x                                 0x8B2E50
#define CListWnd__GetItemAtPoint1_x                                0x8B2EC0
#define CListWnd__GetItemData_x                                    0x8B1170
#define CListWnd__GetItemHeight_x                                  0x8B26C0
#define CListWnd__GetItemIcon_x                                    0x8B1360
#define CListWnd__GetItemRect_x                                    0x8B2C90
#define CListWnd__GetItemText_x                                    0x8B1210
#define CListWnd__GetSelList_x                                     0x8B5F10
#define CListWnd__GetSeparatorRect_x                               0x8B34F0
#define CListWnd__RemoveLine_x                                     0x8B5E90
#define CListWnd__SetColors_x                                      0x8B0F80
#define CListWnd__SetColumnJustification_x                         0x8B19C0
#define CListWnd__SetColumnWidth_x                                 0x8B16E0
#define CListWnd__SetCurSel_x                                      0x8B0E70
#define CListWnd__SetItemColor_x                                   0x8B5340
#define CListWnd__SetItemData_x                                    0x8B1DE0
#define CListWnd__SetItemText_x                                    0x8B5180
#define CListWnd__ShiftColumnSeparator_x                           0x8B5010
#define CListWnd__Sort_x                                           0x8B6AF0
#define CListWnd__ToggleSel_x                                      0x8B1CB0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x710510

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7318D0
#define CMerchantWnd__RequestBuyItem_x                             0x738970
#define CMerchantWnd__RequestSellItem_x                            0x739430
#define CMerchantWnd__SelectRecoverySlot_x                         0x731B80
#define CMerchantWnd__SelectBuySellSlot_x                          0x730D80
#define CMerchantWnd__ActualSelect_x                               0x735850

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x849A30
#define CPacketScrambler__hton_x                                   0x849A40

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D47E0
#define CSidlManager__CreateLabel_x                                0x799CA0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65D7E0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65D710
#define CSidlScreenWnd__ConvertToRes_x                             0x8EFD00
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CC560
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CD710
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CD7C0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CCC90
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CBF10
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CB690
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CC100
#define CSidlScreenWnd__Init1_x                                    0x8CD3E0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CC610
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CB850
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CCED0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CB2F0
#define CSidlScreenWnd__StoreIniVis_x                              0x8CB640
#define CSidlScreenWnd__WndNotification_x                          0x8CD160
#define CSidlScreenWnd__GetChildItem_x                             0x8CB760
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BEFA0
#define CSidlScreenWnd__m_layoutCopy_x                             0x181D980

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FC240
#define CSkillMgr__GetSkillCap_x                                   0x5FC420
#define CSkillMgr__GetNameToken_x                                  0x5FBE60

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8EEFB0
#define CSliderWnd__SetValue_x                                     0x8EF180
#define CSliderWnd__SetNumTicks_x                                  0x8EF900

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A1A50

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EA970
#define CStmlWnd__CalculateHSBRange_x                              0x8E2EC0
#define CStmlWnd__CalculateVSBRange_x                              0x8E2F50
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E30D0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E39B0
#define CStmlWnd__ForceParseNow_x                                  0x8EB2C0
#define CStmlWnd__GetNextTagPiece_x                                0x8E38B0
#define CStmlWnd__GetSTMLText_x                                    0x694A80
#define CStmlWnd__GetVisibleText_x                                 0x8E4400
#define CStmlWnd__InitializeWindowVariables_x                      0x8E6770
#define CStmlWnd__MakeStmlColorTag_x                               0x8E21C0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E2220
#define CStmlWnd__SetSTMLText_x                                    0x8E7FC0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EA610
#define CStmlWnd__UpdateHistoryString_x                            0x8E5330

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E18D0
#define CTabWnd__DrawCurrentPage_x                                 0x8E1160
#define CTabWnd__DrawTab_x                                         0x8E0F20
#define CTabWnd__GetCurrentPage_x                                  0x8E1510
#define CTabWnd__GetPageInnerRect_x                                0x8E0C10
#define CTabWnd__GetTabInnerRect_x                                 0x8E0E10
#define CTabWnd__GetTabRect_x                                      0x8E0CE0
#define CTabWnd__InsertPage_x                                      0x8E1BC0
#define CTabWnd__SetPage_x                                         0x8E1540
#define CTabWnd__SetPageRect_x                                     0x8E1810
#define CTabWnd__UpdatePage_x                                      0x8E1B60

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432F20

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C9580

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x634BF0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F5150

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8AF0E0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59D050
#define CXStr__CXStr1_x                                            0x743C10
#define CXStr__CXStr3_x                                            0x892730
#define CXStr__dCXStr_x                                            0x4C8C90
#define CXStr__operator_equal_x                                    0x8928A0
#define CXStr__operator_equal1_x                                   0x8928F0
#define CXStr__operator_plus_equal1_x                              0x8939F0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BE1A0
#define CXWnd__Center_x                                            0x8C4330
#define CXWnd__ClrFocus_x                                          0x8BDD90
#define CXWnd__DoAllDrawing_x                                      0x8C3F80
#define CXWnd__DrawChildren_x                                      0x8C4120
#define CXWnd__DrawColoredRect_x                                   0x8BE580
#define CXWnd__DrawTooltip_x                                       0x8BE810
#define CXWnd__DrawTooltipAtPoint_x                                0x8C2EF0
#define CXWnd__GetBorderFrame_x                                    0x8BEC80
#define CXWnd__GetChildWndAt_x                                     0x8C4D00
#define CXWnd__GetClientClipRect_x                                 0x8BEA30
#define CXWnd__GetScreenClipRect_x                                 0x8C35F0
#define CXWnd__GetScreenRect_x                                     0x8BEE50
#define CXWnd__GetTooltipRect_x                                    0x8BE6A0
#define CXWnd__GetWindowTextA_x                                    0x424440
#define CXWnd__IsActive_x                                          0x8B97E0
#define CXWnd__IsDescendantOf_x                                    0x8BEBC0
#define CXWnd__IsReallyVisible_x                                   0x8C1F30
#define CXWnd__IsType_x                                            0x8F1970
#define CXWnd__Move_x                                              0x8C16A0
#define CXWnd__Move1_x                                             0x8C3C40
#define CXWnd__ProcessTransition_x                                 0x8BE150
#define CXWnd__Refade_x                                            0x8BDF20
#define CXWnd__Resize_x                                            0x8BEF00
#define CXWnd__Right_x                                             0x8C33F0
#define CXWnd__SetFocus_x                                          0x8C07E0
#define CXWnd__SetFont_x                                           0x8BDDE0
#define CXWnd__SetKeyTooltip_x                                     0x8BF170
#define CXWnd__SetMouseOver_x                                      0x8C3930
#define CXWnd__StartFade_x                                         0x8BE1F0
#define CXWnd__GetChildItem_x                                      0x8C3870

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BB080
#define CXWndManager__DrawWindows_x                                0x8BACC0
#define CXWndManager__GetKeyboardFlags_x                           0x8B9310
#define CXWndManager__HandleKeyboardMsg_x                          0x8B9C70
#define CXWndManager__RemoveWnd_x                                  0x8B9970

// CDBStr
#define CDBStr__GetString_x                                        0x4A9D00

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E060
#define EQ_Character__Cur_HP_x                                     0x462BC0
#define EQ_Character__Cur_Mana_x                                   0x4566D0
#define EQ_Character__GetAACastingTimeModifier_x                   0x447270
#define EQ_Character__GetCharInfo2_x                               0x8661E0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F5A0
#define EQ_Character__GetFocusRangeModifier_x                      0x43F600
#define EQ_Character__Max_Endurance_x                              0x5C27F0
#define EQ_Character__Max_HP_x                                     0x4592F0
#define EQ_Character__Max_Mana_x                                   0x5C2620
#define EQ_Character__doCombatAbility_x                            0x5BFD10
#define EQ_Character__UseSkill_x                                   0x46D050
#define EQ_Character__GetConLevel_x                                0x5B4DA0
#define EQ_Character__IsExpansionFlag_x                            0x423990
#define EQ_Character__TotalEffect_x                                0x44B2F0
#define EQ_Character__GetPCSpellAffect_x                           0x447670
#define EQ_Character__SpellDuration_x                              0x445570
#define EQ_Character__FindItemByRecord_x                           0x460020

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x442880
#define CCharacterSelect__EnterWorld_x                             0x442050
#define CCharacterSelect__Quit_x                                   0x440C30

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x595350
#define EQ_Item__CreateItemTagString_x                             0x848370
#define EQ_Item__IsStackable_x                                     0x83D9B0
#define EQ_Item__GetImageNum_x                                     0x8404F0
#define EQ_Item__CreateItemClient_x                                0x595F20
#define EQ_Item__GetItemValue_x                                    0x8470A0
#define EQ_Item__ValueSellMerchant_x                               0x849680
#define EQ_Item__IsKeyRingItem_x                                   0x83E4A0
#define EQ_Item__CanGoInBag_x                                      0x5954E0
#define EQ_Item__GetMaxItemCount_x                                 0x83D8A0
#define EQ_Item__GetHeldItem_x                                     0x83F2F0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C9630
#define EQ_LoadingS__Array_x                                       0xC1B680

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C4D10
#define EQ_PC__GetAlternateAbilityId_x                             0x851A10
#define EQ_PC__GetCombatAbility_x                                  0x851AA0
#define EQ_PC__GetCombatAbilityTimer_x                             0x84C840
#define EQ_PC__GetItemTimerValue_x                                 0x5BE3C0
#define EQ_PC__HasLoreItem_x                                       0x5B82D0
#define EQ_PC__AlertInventoryChanged_x                             0x5B4D70
#define EQ_PC__GetPcZoneClient_x                                   0x5DF440
#define EQ_PC__RemoveMyAffect_x                                    0x5BD850
#define EQ_PC__GetKeyRingItems_x                                   0x84CC60

// EQItemList 
#define EQItemList__EQItemList_x                                   0x513E20
#define EQItemList__add_object_x                                   0x53FC70
#define EQItemList__add_item_x                                     0x513D60
#define EQItemList__delete_item_x                                  0x514210
#define EQItemList__FreeItemList_x                                 0x514110

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A8FD0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5CA420
#define EQPlayer__dEQPlayer_x                                      0x5D32F0
#define EQPlayer__DoAttack_x                                       0x5E5310
#define EQPlayer__EQPlayer_x                                       0x5D5A00
#define EQPlayer__SetNameSpriteState_x                             0x5D0240
#define EQPlayer__SetNameSpriteTint_x                              0x5CB830
#define PlayerBase__HasProperty_j_x                                0x922850
#define EQPlayer__IsTargetable_x                                   0x923150
#define EQPlayer__CanSee_x                                         0x923670
#define PlayerZoneClient__ChangeHeight_x                           0x5E51D0
#define EQPlayer__CanSeeTargetIndicator_x                          0x923760
#define PlayerBase__GetVisibilityLineSegment_x                     0x923400

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D9A30
#define EQPlayerManager__GetSpawnByName_x                          0x5D9E90
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D9A60

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59B3F0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59B430
#define KeypressHandler__ClearCommandStateArray_x                  0x59AFE0
#define KeypressHandler__HandleKeyDown_x                           0x599940
#define KeypressHandler__HandleKeyUp_x                             0x599C60
#define KeypressHandler__SaveKeymapping_x                          0x59B0B0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x708EA0
#define MapViewMap__SaveEx_x                                       0x70C1D0

#define PlayerPointManager__GetAltCurrency_x                       0x864290

// StringTable 
#define StringTable__getString_x                                   0x85EEB0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C2280
#define PcZoneClient__RemovePetEffect_x                            0x5BE890
#define PcZoneClient__HasAlternateAbility_x                        0x5BF230
#define PcZoneClient__GetCurrentMod_x                              0x458690
#define PcZoneClient__GetModCap_x                                  0x455E50
#define PcZoneClient__CanEquipItem_x                               0x5BF7E0

//Doors
#define EQSwitch__UseSwitch_x                                      0x551AE0

//IconCache
#define IconCache__GetIcon_x                                       0x6A5340

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69C0A0
#define CContainerMgr__CloseContainer_x                            0x69C8C0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x769BF0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58E5B0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E3220
#define EQ_Spell__SpellAffects_x                                   0x4E08D0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4E0940
#define CharacterZoneClient__CalcAffectChange_x                    0x4466A0
#define CLootWnd__LootAll_x                                        0x6FE6E0
#define CLootWnd__RequestLootSlot_x                                0x6FEEF0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B08C0
#define CTargetWnd__WndNotification_x                              0x7B03B0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7B0AA0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B5AA0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4DC190

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x498AB0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DD340
#define CSidlManager__FindAnimation1_x                             0x8D26C0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D0D70
#define CAltAbilityData__GetMercMaxRank_x                          0x4D0D20
#define CAltAbilityData__GetMaxRank_x                              0x4C5B60

//CTargetRing
#define CTargetRing__Cast_x                                        0x58BEA0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x454F00
#define CharacterBase__CreateItemGlobalIndex_x                     0x471E20
#define CharacterBase__CreateItemIndex_x                           0x50D2A0
#define CharacterBase__GetItemPossession_x                         0x50E760
#define CharacterBase__GetItemByGlobalIndex_x                      0x874370

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x686970
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6860D0

//messages
#define msg_spell_worn_off_x                                       0x4EADF0
#define msg_new_text_x                                             0x4F4370
#define msgTokenTextParam_x                                        0x4F0D40

//SpellManager
#define SpellManager__vftable_x                                    0xAB5FE0
#define SpellManager__SpellManager_x                               0x47AC20
#define Spellmanager__CheckSpellRequirementAssociations_x          0x6030A0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9271D0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E7370
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43ACB0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x444EF0
#define ItemGlobalIndex__IsValidIndex_x                            0x454790

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x872190
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8710D0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F7590
