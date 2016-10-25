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
#define __ExpectedVersionDate                                     "Oct 25 2016"
#define __ExpectedVersionTime                                     "04:16:26"
#define __ActualVersionDate_x                                      0xAD06A0
#define __ActualVersionTime_x                                      0xAD06AC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTrayBeta"
#define __MacroQuestWinName                                       "MacroQuestBeta"

// Memory Protection
#define __MemChecker0_x                                            0x5A0DA0
#define __MemChecker1_x                                            0x895870
#define __MemChecker2_x                                            0x637320
#define __MemChecker3_x                                            0x637270
#define __MemChecker4_x                                            0x7E9B60
#define __EncryptPad0_x                                            0xC74450
#define __EncryptPad1_x                                            0xE00A60
#define __EncryptPad2_x                                            0xCBD250
#define __EncryptPad3_x                                            0xCBCE50
#define __EncryptPad4_x                                            0xDD6A30
#define __EncryptPad5_x                                            0x11B1C98
#define __AC1_x                                                    0x7A97E5
#define __AC2_x                                                    0x55A9E7
#define __AC3_x                                                    0x558B80
#define __AC4_x                                                    0x56B3F0
#define __AC5_x                                                    0x57E14B
#define __AC6_x                                                    0x581CFE
#define __AC7_x                                                    0x5787BC
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
#define __do_loot_x                                                0x520020
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
#define __CastRay_x                                                0x5372C0
#define __ConvertItemTags_x                                        0x524B80
#define __ExecuteCmd_x                                             0x50F450
#define __EQGetTime_x                                              0x895500
#define __get_melee_range_x                                        0x516010
#define __GetGaugeValueFromEQ_x                                    0x7A8520
#define __GetLabelFromEQ_x                                         0x7A9770
#define __ToggleKeyRingItem_x                                      0x47FEE0
#define __GetXTargetType_x                                         0x9262E0
#define __LoadFrontEnd_x                                           0x6369F0
#define __NewUIINI_x                                               0x7A7EF0
#define __ProcessGameEvents_x                                      0x57A550
#define __ProcessMouseEvent_x                                      0x579CF0
#define CrashDetected_x                                            0x6383B0
#define wwsCrashReportCheckForUploader_x                           0x7F5BA0
#define DrawNetStatus_x                                            0x5B0840
#define Util__FastTime_x                                           0x8951A0
#define Expansion_HoT_x                                            0x10216B8
#define __HelpPath_x                                               0x10A4DB0
#define __STMLToText_x                                             0x8DB1F0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420570
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B310
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B0F0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C7340
#define AltAdvManager__IsAbilityReady_x                            0x4C73B0
#define AltAdvManager__GetAAById_x                                 0x4C7770
#define AltAdvManager__CanTrainAbility_x                           0x4C8070
#define AltAdvManager__CanSeeAbility_x                             0x4C7C30

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463470
#define CharacterZoneClient__MakeMeVisible_x                       0x467F20
#define CharacterZoneClient__IsStackBlocked_x                      0x447B30
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x446FF0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4612A0
#define CharacterZoneClient__GetItemCountInInventory_x             0x461380
#define CharacterZoneClient__GetCursorItemCount_x                  0x461460

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6665E0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x674960

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58FB60
#define CButtonWnd__CButtonWnd_x                                   0x8CF570

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68FA90
#define CChatManager__InitContextMenu_x                            0x690610

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D9560
#define CContextMenu__dCContextMenu_x                              0x8D9770
#define CContextMenu__AddMenuItem_x                                0x8D9780
#define CContextMenu__RemoveMenuItem_x                             0x8D9A60
#define CContextMenu__RemoveAllMenuItems_x                         0x8D9A80
#define CContextMenuManager__AddMenu_x                             0x8C5AB0
#define CContextMenuManager__RemoveMenu_x                          0x8C5E60
#define CContextMenuManager__PopupMenu_x                           0x8C62B0
#define CContextMenuManager__Flush_x                               0x8C5B20
#define CContextMenuManager__GetMenu_x                             0x4169F0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x879F10
#define CChatService__GetFriendName_x                              0x879F20

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x695870
#define CChatWindow__Clear_x                                       0x695440
#define CChatWindow__WndNotification_x                             0x695DB0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C9910
#define CComboWnd__Draw_x                                          0x8C9B20
#define CComboWnd__GetCurChoice_x                                  0x8C96C0
#define CComboWnd__GetListRect_x                                   0x8C9DC0
#define CComboWnd__GetTextRect_x                                   0x8C9980
#define CComboWnd__InsertChoice_x                                  0x8C9E30
#define CComboWnd__SetColors_x                                     0x8C9650
#define CComboWnd__SetChoice_x                                     0x8C9680
#define CComboWnd__GetItemCount_x                                  0x8C96B0
#define CComboWnd__GetCurChoiceText_x                              0x8C9700


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69EF90
#define CContainerWnd__vftable_x                                   0xADA180

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B58A0
#define CDisplay__GetClickedActor_x                                0x4AE1D0
#define CDisplay__GetUserDefinedColor_x                            0x4ACDB0
#define CDisplay__GetWorldFilePath_x                               0x4AC200
#define CDisplay__is3dON_x                                         0x4AB690
#define CDisplay__ReloadUI_x                                       0x4C0E10
#define CDisplay__WriteTextHD2_x                                   0x4B1C60

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8EFBA0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DDA80
#define CEditWnd__GetCharIndexPt_x                                 0x8DEB00
#define CEditWnd__GetDisplayString_x                               0x8DDC30
#define CEditWnd__GetHorzOffset_x                                  0x8DDF70
#define CEditWnd__GetLineForPrintableChar_x                        0x8DE5D0
#define CEditWnd__GetSelStartPt_x                                  0x8DEDB0
#define CEditWnd__GetSTMLSafeText_x                                0x8DE100
#define CEditWnd__PointFromPrintableChar_x                         0x8DE6C0
#define CEditWnd__SelectableCharFromPoint_x                        0x8DE840
#define CEditWnd__SetEditable_x                                    0x8DE0D0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x55B130
#define CEverQuest__CreateTargetIndicator_x                        0x55C020
#define CEverQuest__DeleteTargetIndicator_x                        0x55C0A0
#define CEverQuest__DoTellWindow_x                                 0x472B90
#define CEverQuest__DropHeldItemOnGround_x                         0x572240
#define CEverQuest__dsp_chat_x                                     0x472ED0
#define CEverQuest__trimName_x                                     0x557A80
#define CEverQuest__Emote_x                                        0x570590
#define CEverQuest__EnterZone_x                                    0x56B580
#define CEverQuest__GetBodyTypeDesc_x                              0x5554E0
#define CEverQuest__GetClassDesc_x                                 0x55EDB0
#define CEverQuest__GetClassThreeLetterCode_x                      0x55F3B0
#define CEverQuest__GetDeityDesc_x                                 0x555DC0
#define CEverQuest__GetLangDesc_x                                  0x555870
#define CEverQuest__GetRaceDesc_x                                  0x55F570
#define CEverQuest__InterpretCmd_x                                 0x5633A0
#define CEverQuest__LeftClickedOnPlayer_x                          0x576C10
#define CEverQuest__LMouseUp_x                                     0x578D10
#define CEverQuest__RightClickedOnPlayer_x                         0x577720
#define CEverQuest__RMouseUp_x                                     0x578770
#define CEverQuest__SetGameState_x                                 0x55B9F0
#define CEverQuest__UPCNotificationFlush_x                         0x5532F0
#define CEverQuest__IssuePetCommand_x                              0x563D80

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AFD20
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AFD80
#define CGaugeWnd__Draw_x                                          0x6B01B0

// CGuild
#define CGuild__FindMemberByName_x                                 0x437390
#define CGuild__GetGuildName_x                                     0x437860
#define CGuild__GetGuildIndex_x                                    0x438A30

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CC210

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D93A0
#define CInvSlotMgr__MoveItem_x                                    0x6DA250
#define CInvSlotMgr__SelectSlot_x                                  0x6D9450

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D8850
#define CInvSlot__SliderComplete_x                                 0x6D6060
#define CInvSlot__GetItemBase_x                                    0x6D54E0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DB6B0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A3F30
#define CItemDisplayWnd__UpdateStrings_x                           0x6DD7F0

// CLabel 
#define CLabel__Draw_x                                             0x6F7300

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B5500
#define CListWnd__dCListWnd_x                                      0x8B6730
#define CListWnd__AddColumn_x                                      0x8B66D0
#define CListWnd__AddColumn1_x                                     0x8B5D60
#define CListWnd__AddLine_x                                        0x8B57C0
#define CListWnd__AddString_x                                      0x8B59E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B27A0
#define CListWnd__CalculateVSBRange_x                              0x8B49C0
#define CListWnd__ClearSel_x                                       0x8B1AC0
#define CListWnd__ClearAllSel_x                                    0x8B1A70
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B5390
#define CListWnd__Compare_x                                        0x8B3310
#define CListWnd__Draw_x                                           0x8B45D0
#define CListWnd__DrawColumnSeparators_x                           0x8B4460
#define CListWnd__DrawHeader_x                                     0x8B1D80
#define CListWnd__DrawItem_x                                       0x8B39A0
#define CListWnd__DrawLine_x                                       0x8B4100
#define CListWnd__DrawSeparator_x                                  0x8B4500
#define CListWnd__EnsureVisible_x                                  0x8B2900
#define CListWnd__ExtendSel_x                                      0x8B38B0
#define CListWnd__GetColumnMinWidth_x                              0x8B1470
#define CListWnd__GetColumnWidth_x                                 0x8B13A0
#define CListWnd__GetCurSel_x                                      0x8B0B70
#define CListWnd__GetItemAtPoint_x                                 0x8B2B90
#define CListWnd__GetItemAtPoint1_x                                0x8B2C00
#define CListWnd__GetItemData_x                                    0x8B0EB0
#define CListWnd__GetItemHeight_x                                  0x8B2400
#define CListWnd__GetItemIcon_x                                    0x8B10A0
#define CListWnd__GetItemRect_x                                    0x8B29D0
#define CListWnd__GetItemText_x                                    0x8B0F50
#define CListWnd__GetSelList_x                                     0x8B5C50
#define CListWnd__GetSeparatorRect_x                               0x8B3230
#define CListWnd__RemoveLine_x                                     0x8B5BD0
#define CListWnd__SetColors_x                                      0x8B0CC0
#define CListWnd__SetColumnJustification_x                         0x8B1700
#define CListWnd__SetColumnWidth_x                                 0x8B1420
#define CListWnd__SetCurSel_x                                      0x8B0BB0
#define CListWnd__SetItemColor_x                                   0x8B5080
#define CListWnd__SetItemData_x                                    0x8B1B20
#define CListWnd__SetItemText_x                                    0x8B4EC0
#define CListWnd__ShiftColumnSeparator_x                           0x8B4D50
#define CListWnd__Sort_x                                           0x8B6830
#define CListWnd__ToggleSel_x                                      0x8B19F0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7103C0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7318F0
#define CMerchantWnd__RequestBuyItem_x                             0x738980
#define CMerchantWnd__RequestSellItem_x                            0x739440
#define CMerchantWnd__SelectRecoverySlot_x                         0x731BA0
#define CMerchantWnd__SelectBuySellSlot_x                          0x730DA0
#define CMerchantWnd__ActualSelect_x                               0x735850

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x849620
#define CPacketScrambler__hton_x                                   0x849630

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D4620
#define CSidlManager__CreateLabel_x                                0x799D60

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65D9B0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65D8D0
#define CSidlScreenWnd__ConvertToRes_x                             0x8EFA80
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CC2D0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CD490
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CD540
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CCA10
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CBC80
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CB3D0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CBE70
#define CSidlScreenWnd__Init1_x                                    0x8CD160
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CC380
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CB590
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CCC50
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CB030
#define CSidlScreenWnd__StoreIniVis_x                              0x8CB380
#define CSidlScreenWnd__WndNotification_x                          0x8CCEE0
#define CSidlScreenWnd__GetChildItem_x                             0x8CB4A0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BECA0
#define CSidlScreenWnd__m_layoutCopy_x                             0x181D980

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FC4D0
#define CSkillMgr__GetSkillCap_x                                   0x5FC6B0
#define CSkillMgr__GetNameToken_x                                  0x5FC0F0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8EED20
#define CSliderWnd__SetValue_x                                     0x8EEEF0
#define CSliderWnd__SetNumTicks_x                                  0x8EF670

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A1B90

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EA6D0
#define CStmlWnd__CalculateHSBRange_x                              0x8E2C10
#define CStmlWnd__CalculateVSBRange_x                              0x8E2CA0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E2E20
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E3700
#define CStmlWnd__ForceParseNow_x                                  0x8EB020
#define CStmlWnd__GetNextTagPiece_x                                0x8E3600
#define CStmlWnd__GetSTMLText_x                                    0x694CE0
#define CStmlWnd__GetVisibleText_x                                 0x8E4150
#define CStmlWnd__InitializeWindowVariables_x                      0x8E64E0
#define CStmlWnd__MakeStmlColorTag_x                               0x8E1F10
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E1F70
#define CStmlWnd__SetSTMLText_x                                    0x8E7D40
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EA370
#define CStmlWnd__UpdateHistoryString_x                            0x8E5090

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E1620
#define CTabWnd__DrawCurrentPage_x                                 0x8E0EB0
#define CTabWnd__DrawTab_x                                         0x8E0C80
#define CTabWnd__GetCurrentPage_x                                  0x8E1260
#define CTabWnd__GetPageInnerRect_x                                0x8E0970
#define CTabWnd__GetTabInnerRect_x                                 0x8E0B70
#define CTabWnd__GetTabRect_x                                      0x8E0A40
#define CTabWnd__InsertPage_x                                      0x8E1910
#define CTabWnd__SetPage_x                                         0x8E1290
#define CTabWnd__SetPageRect_x                                     0x8E1560
#define CTabWnd__UpdatePage_x                                      0x8E18B0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432F50

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C92C0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x634C90

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F4E90

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8AEE20

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59D240
#define CXStr__CXStr1_x                                            0x8A3C50
#define CXStr__CXStr3_x                                            0x892480
#define CXStr__dCXStr_x                                            0x5FF190
#define CXStr__operator_equal_x                                    0x8925F0
#define CXStr__operator_equal1_x                                   0x892640
#define CXStr__operator_plus_equal1_x                              0x893740

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BDEA0
#define CXWnd__Center_x                                            0x8C40A0
#define CXWnd__ClrFocus_x                                          0x8BDA80
#define CXWnd__DoAllDrawing_x                                      0x8C3CF0
#define CXWnd__DrawChildren_x                                      0x8C3E90
#define CXWnd__DrawColoredRect_x                                   0x8BE280
#define CXWnd__DrawTooltip_x                                       0x8BE530
#define CXWnd__DrawTooltipAtPoint_x                                0x8C2C50
#define CXWnd__GetBorderFrame_x                                    0x8BE980
#define CXWnd__GetChildWndAt_x                                     0x8C4A50
#define CXWnd__GetClientClipRect_x                                 0x8BE740
#define CXWnd__GetScreenClipRect_x                                 0x8C3340
#define CXWnd__GetScreenRect_x                                     0x8BEB30
#define CXWnd__GetTooltipRect_x                                    0x8BE3C0
#define CXWnd__GetWindowTextA_x                                    0x424680
#define CXWnd__IsActive_x                                          0x8B9500
#define CXWnd__IsDescendantOf_x                                    0x8BE8D0
#define CXWnd__IsReallyVisible_x                                   0x8C1C80
#define CXWnd__IsType_x                                            0x8F1710
#define CXWnd__Move_x                                              0x8C1350
#define CXWnd__Move1_x                                             0x8C3990
#define CXWnd__ProcessTransition_x                                 0x8BDE40
#define CXWnd__Refade_x                                            0x8BDC20
#define CXWnd__Resize_x                                            0x8BEC00
#define CXWnd__Right_x                                             0x8C3140
#define CXWnd__SetFocus_x                                          0x8C04B0
#define CXWnd__SetFont_x                                           0x8BDAD0
#define CXWnd__SetKeyTooltip_x                                     0x8BEE70
#define CXWnd__SetMouseOver_x                                      0x8C3680
#define CXWnd__StartFade_x                                         0x8BDEF0
#define CXWnd__GetChildItem_x                                      0x8C35C0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BAD90
#define CXWndManager__DrawWindows_x                                0x8BA9D0
#define CXWndManager__GetKeyboardFlags_x                           0x8B9030
#define CXWndManager__HandleKeyboardMsg_x                          0x8B9990
#define CXWndManager__RemoveWnd_x                                  0x8B9690

// CDBStr
#define CDBStr__GetString_x                                        0x4A9BD0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E0D0
#define EQ_Character__Cur_HP_x                                     0x462B10
#define EQ_Character__Cur_Mana_x                                   0x456630
#define EQ_Character__GetAACastingTimeModifier_x                   0x447300
#define EQ_Character__GetCharInfo2_x                               0x865E90
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F570
#define EQ_Character__GetFocusRangeModifier_x                      0x43F5D0
#define EQ_Character__Max_Endurance_x                              0x5C2900
#define EQ_Character__Max_HP_x                                     0x459250
#define EQ_Character__Max_Mana_x                                   0x5C2730
#define EQ_Character__doCombatAbility_x                            0x5BFE20
#define EQ_Character__UseSkill_x                                   0x46CFA0
#define EQ_Character__GetConLevel_x                                0x5B4EA0
#define EQ_Character__IsExpansionFlag_x                            0x423BB0
#define EQ_Character__TotalEffect_x                                0x44B360
#define EQ_Character__GetPCSpellAffect_x                           0x447700
#define EQ_Character__SpellDuration_x                              0x445600
#define EQ_Character__FindItemByRecord_x                           0x45FF80

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x442950
#define CCharacterSelect__EnterWorld_x                             0x442120
#define CCharacterSelect__Quit_x                                   0x440D00

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x595370
#define EQ_Item__CreateItemTagString_x                             0x847FD0
#define EQ_Item__IsStackable_x                                     0x83DAF0
#define EQ_Item__GetImageNum_x                                     0x8404F0
#define EQ_Item__CreateItemClient_x                                0x595F60
#define EQ_Item__GetItemValue_x                                    0x846D40
#define EQ_Item__ValueSellMerchant_x                               0x849280
#define EQ_Item__IsKeyRingItem_x                                   0x83E520
#define EQ_Item__CanGoInBag_x                                      0x595500
#define EQ_Item__GetMaxItemCount_x                                 0x83D9E0
#define EQ_Item__GetHeldItem_x                                     0x83F310

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C9490
#define EQ_LoadingS__Array_x                                       0xC1B680

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C4E20
#define EQ_PC__GetAlternateAbilityId_x                             0x8515E0
#define EQ_PC__GetCombatAbility_x                                  0x851670
#define EQ_PC__GetCombatAbilityTimer_x                             0x84C430
#define EQ_PC__GetItemTimerValue_x                                 0x5BE4E0
#define EQ_PC__HasLoreItem_x                                       0x5B83C0
#define EQ_PC__AlertInventoryChanged_x                             0x5B4E70
#define EQ_PC__GetPcZoneClient_x                                   0x5DF5D0
#define EQ_PC__RemoveMyAffect_x                                    0x5BD970
#define EQ_PC__GetKeyRingItems_x                                   0x84C850

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5140D0
#define EQItemList__add_object_x                                   0x53FEA0
#define EQItemList__add_item_x                                     0x514010
#define EQItemList__delete_item_x                                  0x5144C0
#define EQItemList__FreeItemList_x                                 0x5143C0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A8EE0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5CA570
#define EQPlayer__dEQPlayer_x                                      0x5D3440
#define EQPlayer__DoAttack_x                                       0x5E54C0
#define EQPlayer__EQPlayer_x                                       0x5D5B50
#define EQPlayer__SetNameSpriteState_x                             0x5D0390
#define EQPlayer__SetNameSpriteTint_x                              0x5CB980
#define PlayerBase__HasProperty_j_x                                0x922520
#define EQPlayer__IsTargetable_x                                   0x922E20
#define EQPlayer__CanSee_x                                         0x923340
#define PlayerZoneClient__ChangeHeight_x                           0x5E5380
#define EQPlayer__CanSeeTargetIndicator_x                          0x923430
#define PlayerBase__GetVisibilityLineSegment_x                     0x9230D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D9C20
#define EQPlayerManager__GetSpawnByName_x                          0x5DA080
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D9C50

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59B5E0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59B620
#define KeypressHandler__ClearCommandStateArray_x                  0x59B1D0
#define KeypressHandler__HandleKeyDown_x                           0x599B30
#define KeypressHandler__HandleKeyUp_x                             0x599E50
#define KeypressHandler__SaveKeymapping_x                          0x59B2A0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x708D50
#define MapViewMap__SaveEx_x                                       0x70C080

#define PlayerPointManager__GetAltCurrency_x                       0x863FC0

// StringTable 
#define StringTable__getString_x                                   0x85EAB0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C2390
#define PcZoneClient__RemovePetEffect_x                            0x5BE9B0
#define PcZoneClient__HasAlternateAbility_x                        0x5BF350
#define PcZoneClient__GetCurrentMod_x                              0x4585F0
#define PcZoneClient__GetModCap_x                                  0x455DB0
#define PcZoneClient__CanEquipItem_x                               0x5BF900

//Doors
#define EQSwitch__UseSwitch_x                                      0x551C20

//IconCache
#define IconCache__GetIcon_x                                       0x6A5590

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69C300
#define CContainerMgr__CloseContainer_x                            0x69CB20

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x769B90

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58E5E0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E31B0
#define EQ_Spell__SpellAffects_x                                   0x4E0860
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4E08D0
#define CharacterZoneClient__CalcAffectChange_x                    0x446730
#define CLootWnd__LootAll_x                                        0x6FE570
#define CLootWnd__RequestLootSlot_x                                0x6FED80

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B09E0
#define CTargetWnd__WndNotification_x                              0x7B04D0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7B0BC0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B5C50

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4DC070

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x498890

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DD0B0
#define CSidlManager__FindAnimation1_x                             0x8D2500

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D0B90
#define CAltAbilityData__GetMercMaxRank_x                          0x4D0B40
#define CAltAbilityData__GetMaxRank_x                              0x4C59F0

//CTargetRing
#define CTargetRing__Cast_x                                        0x58BEC0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x454F00
#define CharacterBase__CreateItemGlobalIndex_x                     0x471D70
#define CharacterBase__CreateItemIndex_x                           0x50D540
#define CharacterBase__GetItemPossession_x                         0x50E9F0
#define CharacterBase__GetItemByGlobalIndex_x                      0x874010

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x686BB0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x686310

//messages
#define msg_spell_worn_off_x                                       0x4EADA0
#define msg_new_text_x                                             0x4F4320
#define msgTokenTextParam_x                                        0x4F0CF0

//SpellManager
#define SpellManager__vftable_x                                    0xAB5FF0
#define SpellManager__SpellManager_x                               0x47AB70
#define Spellmanager__CheckSpellRequirementAssociations_x          0x6032E0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x926E20

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E7310
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43AC80
#define ItemGlobalIndex__IsEquippedLocation_x                      0x444FC0
#define ItemGlobalIndex__IsValidIndex_x                            0x4547F0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x871E20
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x870D60

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F7550
