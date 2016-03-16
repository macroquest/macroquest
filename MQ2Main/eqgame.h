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
#define __ExpectedVersionDate                                     "Mar 11 2016"
#define __ExpectedVersionTime                                     "15:14:32"
#define __ActualVersionDate_x                                      0xAD6380
#define __ActualVersionTime_x                                      0xAD638C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59E630
#define __MemChecker1_x                                            0x89DB30
#define __MemChecker2_x                                            0x637E70
#define __MemChecker3_x                                            0x637DC0
#define __MemChecker4_x                                            0x7EB040
#define __EncryptPad0_x                                            0xC73378
#define __EncryptPad1_x                                            0xDFED08
#define __EncryptPad2_x                                            0xCBCE68
#define __EncryptPad3_x                                            0xCBCA68
#define __EncryptPad4_x                                            0xDD6EF8
#define __EncryptPad5_x                                            0x11AAB78
#define __AC1_x                                                    0x7A8585
#define __AC2_x                                                    0x554CA7
#define __AC3_x                                                    0x5698D0
#define __AC4_x                                                    0x570620
#define __AC5_x                                                    0x57BE5E
#define __AC6_x                                                    0x57FA29
#define __AC7_x                                                    0x57655C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E5220

// Direct Input
#define DI8__Main_x                                                0x11AAB50
#define DI8__Keyboard_x                                            0x11AAB54
#define DI8__Mouse_x                                               0x11AAB58
#define DI8__Mouse_Copy_x                                          0x10191E4
#define DI8__Mouse_Check_x                                         0x10A2A3C
#define __Attack_x                                                 0x109D6E3
#define __Autofire_x                                               0x109D6E4
#define __BindList_x                                               0xC35478
#define __bCommandEnabled_x                                        0x1008648
#define __Clicks_x                                                 0x10192A0
#define __CommandList_x                                            0xC397E8
#define __CurrentMapLabel_x                                        0x11B05A8
#define __CurrentSocial_x                                          0xBEC5B8
#define __DoAbilityList_x                                          0x104F998
#define __do_loot_x                                                0x51C670
#define __DrawHandler_x                                            0x18173D4
#define __GroupCount_x                                             0x1009C12

#define __Guilds_x                                                 0x100F828
#define __gWorld_x                                                 0x100C0CC
#define __HotkeyPage_x                                             0x1096398
#define __HWnd_x                                                   0x10A2A58
#define __InChatMode_x                                             0x10191CC
#define __LastTell_x                                               0x101B094
#define __LMouseHeldTime_x                                         0x101930C
#define __Mouse_x                                                  0x11AAB5C
#define __MouseLook_x                                              0x1019266
#define __MouseEventTime_x                                         0x109DEEC
#define __gpbCommandEvent_x                                        0x100C194
#define __NetStatusToggle_x                                        0x1019269
#define __PCNames_x                                                0x101A6B8
#define __RangeAttackReady_x                                       0x101A3F4
#define __RMouseHeldTime_x                                         0x1019308
#define __RunWalkState_x                                           0x10191D0
#define __ScreenMode_x                                             0xF583C0
#define __ScreenX_x                                                0x1019184
#define __ScreenY_x                                                0x1019180
#define __ScreenXMax_x                                             0x1019188
#define __ScreenYMax_x                                             0x101918C
#define __ServerHost_x                                             0x1009B5C
#define __ServerName_x                                             0x104F958
#define __ShiftKeyDown_x                                           0x1019878
#define __ShowNames_x                                              0x101A5B4
#define __Socials_x                                                0x104FA58
#define __SubscriptionType_x                                       0x11DEAD8
#define __TargetAggroHolder_x                                      0x11B27E4
#define __GroupAggro_x                                             0x11B2824
#define __LoginName_x                                              0x10A1630
#define __Inviter_x                                                0x109D660
#define __AttackOnAssist_x                                         0x101A570

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x100C1B8
#define instEQZoneInfo_x                                           0x101945C
#define instKeypressHandler_x                                      0x109DED0
#define pinstActiveBanker_x                                        0x100C170
#define pinstActiveCorpse_x                                        0x100C174
#define pinstActiveGMaster_x                                       0x100C178
#define pinstActiveMerchant_x                                      0x100C16C
#define pinstAggroInfo_x                                           0xE1A720
#define pinstAltAdvManager_x                                       0xF59480
#define pinstAuraMgr_x                                             0xE26688
#define pinstBandageTarget_x                                       0x100C158
#define pinstCamActor_x                                            0xF58DD4
#define pinstCDBStr_x                                              0xF58354
#define pinstCDisplay_x                                            0x100C180
#define pinstCEverQuest_x                                          0x11AACD0
#define pinstCharData_x                                            0x100C13C
#define pinstCharSpawn_x                                           0x100C164
#define pinstControlledMissile_x                                   0x100C138
#define pinstControlledPlayer_x                                    0x100C164
#define pinstCSidlManager_x                                        0x1816914
#define pinstCXWndManager_x                                        0x181690C
#define instDynamicZone_x                                          0x1019018
#define pinstDZMember_x                                            0x1019128
#define pinstDZTimerInfo_x                                         0x101912C
#define pinstEQItemList_x                                          0x1008898
#define instEQMisc_x                                               0xC0FFD0
#define pinstEQSoundManager_x                                      0xF599E0
#define instExpeditionLeader_x                                     0x1019062
#define instExpeditionName_x                                       0x10190A2
#define pinstGroup_x                                               0x1009C0E
#define pinstImeManager_x                                          0x1816918
#define pinstLocalPlayer_x                                         0x100C150
#define pinstMercenaryData_x                                       0x109E520
#define pinstMercenaryStats_x                                      0x11B2930
#define pinstMercAltAbilities_x                                    0xF5980C
#define pinstModelPlayer_x                                         0x100C17C
#define pinstPCData_x                                              0x100C13C
#define pinstSkillMgr_x                                            0x109F358
#define pinstSpawnManager_x                                        0x109EC40
#define pinstSpellManager_x                                        0x109F4A0
#define pinstSpellSets_x                                           0x10963FC
#define pinstStringTable_x                                         0x100C0E4
#define pinstSwitchManager_x                                       0x10097A0
#define pinstTarget_x                                              0x100C168
#define pinstTargetObject_x                                        0x100C140
#define pinstTargetSwitch_x                                        0x100C144
#define pinstTaskMember_x                                          0xF582A0
#define pinstTrackTarget_x                                         0x100C15C
#define pinstTradeTarget_x                                         0x100C14C
#define instTributeActive_x                                        0xC0FFF5
#define pinstViewActor_x                                           0xF58DD0
#define pinstWorldData_x                                           0x100C120
#define pinstZoneAddr_x                                            0x101971C
#define pinstPlayerPath_x                                          0x109ECA0
#define pinstTargetIndicator_x                                     0x109F638
#define pinstCTargetManager_x                                      0x109F698

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE1AC18
#define pinstCAudioTriggersWindow_x                                0xE1AAA8
#define pinstCCharacterSelect_x                                    0xF58C64
#define pinstCFacePick_x                                           0xF58A14
#define pinstCNoteWnd_x                                            0xF58C1C
#define pinstCBookWnd_x                                            0xF58C24
#define pinstCPetInfoWnd_x                                         0xF58C28
#define pinstCTrainWnd_x                                           0xF58C2C
#define pinstCSkillsWnd_x                                          0xF58C30
#define pinstCSkillsSelectWnd_x                                    0xF58C34
#define pinstCCombatSkillsSelectWnd_x                              0xF58C38
#define pinstCFriendsWnd_x                                         0xF58C3C
#define pinstCAuraWnd_x                                            0xF58C40
#define pinstCRespawnWnd_x                                         0xF58C44
#define pinstCBandolierWnd_x                                       0xF58C48
#define pinstCPotionBeltWnd_x                                      0xF58C4C
#define pinstCAAWnd_x                                              0xF58C50
#define pinstCGroupSearchFiltersWnd_x                              0xF58C54
#define pinstCLoadskinWnd_x                                        0xF58C58
#define pinstCAlarmWnd_x                                           0xF58C5C
#define pinstCMusicPlayerWnd_x                                     0xF58C60
#define pinstCMailWnd_x                                            0xF58C68
#define pinstCMailCompositionWnd_x                                 0xF58C6C
#define pinstCMailAddressBookWnd_x                                 0xF58C70
#define pinstCRaidWnd_x                                            0xF58C78
#define pinstCRaidOptionsWnd_x                                     0xF58C7C
#define pinstCBreathWnd_x                                          0xF58C80
#define pinstCMapViewWnd_x                                         0xF58C84
#define pinstCMapToolbarWnd_x                                      0xF58C88
#define pinstCEditLabelWnd_x                                       0xF58C8C
#define pinstCTargetWnd_x                                          0xF58C90
#define pinstCColorPickerWnd_x                                     0xF58C94
#define pinstCPlayerWnd_x                                          0xF58C98
#define pinstCOptionsWnd_x                                         0xF58C9C
#define pinstCBuffWindowNORMAL_x                                   0xF58CA0
#define pinstCBuffWindowSHORT_x                                    0xF58CA4
#define pinstCharacterCreation_x                                   0xF58CA8
#define pinstCCursorAttachment_x                                   0xF58CAC
#define pinstCCastingWnd_x                                         0xF58CB0
#define pinstCCastSpellWnd_x                                       0xF58CB4
#define pinstCSpellBookWnd_x                                       0xF58CB8
#define pinstCInventoryWnd_x                                       0xF58CBC
#define pinstCBankWnd_x                                            0xF58CC4
#define pinstCQuantityWnd_x                                        0xF58CC8
#define pinstCLootWnd_x                                            0xF58CCC
#define pinstCActionsWnd_x                                         0xF58CD0
#define pinstCCombatAbilityWnd_x                                   0xF58CD4
#define pinstCMerchantWnd_x                                        0xF58CD8
#define pinstCTradeWnd_x                                           0xF58CDC
#define pinstCSelectorWnd_x                                        0xF58CE0
#define pinstCBazaarWnd_x                                          0xF58CE4
#define pinstCBazaarSearchWnd_x                                    0xF58CE8
#define pinstCGiveWnd_x                                            0xF58D04
#define pinstCTrackingWnd_x                                        0xF58D0C
#define pinstCInspectWnd_x                                         0xF58D10
#define pinstCSocialEditWnd_x                                      0xF58D14
#define pinstCFeedbackWnd_x                                        0xF58D18
#define pinstCBugReportWnd_x                                       0xF58D1C
#define pinstCVideoModesWnd_x                                      0xF58D20
#define pinstCTextEntryWnd_x                                       0xF58D28
#define pinstCFileSelectionWnd_x                                   0xF58D2C
#define pinstCCompassWnd_x                                         0xF58D30
#define pinstCPlayerNotesWnd_x                                     0xF58D34
#define pinstCGemsGameWnd_x                                        0xF58D38
#define pinstCTimeLeftWnd_x                                        0xF58D3C
#define pinstCPetitionQWnd_x                                       0xF58D58
#define pinstCSoulmarkWnd_x                                        0xF58D5C
#define pinstCStoryWnd_x                                           0xF58D60
#define pinstCJournalTextWnd_x                                     0xF58D64
#define pinstCJournalCatWnd_x                                      0xF58D68
#define pinstCBodyTintWnd_x                                        0xF58D6C
#define pinstCServerListWnd_x                                      0xF58D70
#define pinstCAvaZoneWnd_x                                         0xF58D7C
#define pinstCBlockedBuffWnd_x                                     0xF58D80
#define pinstCBlockedPetBuffWnd_x                                  0xF58D84
#define pinstCInvSlotMgr_x                                         0xF58DC8
#define pinstCContainerMgr_x                                       0xF58DCC
#define pinstCAdventureLeaderboardWnd_x                            0x11AB680
#define pinstCAdventureRequestWnd_x                                0x11AB6F8
#define pinstCAltStorageWnd_x                                      0x11AB9D8
#define pinstCAdventureStatsWnd_x                                  0x11AB770
#define pinstCBarterMerchantWnd_x                                  0x11AC5C0
#define pinstCBarterSearchWnd_x                                    0x11AC638
#define pinstCBarterWnd_x                                          0x11AC6B0
#define pinstCChatManager_x                                        0x11ACD40
#define pinstCDynamicZoneWnd_x                                     0x11AD1F0
#define pinstCEQMainWnd_x                                          0x11AD388
#define pinstCFellowshipWnd_x                                      0x11AD184
#define pinstCFindLocationWnd_x                                    0x11AD658
#define pinstCGroupSearchWnd_x                                     0x11AD928
#define pinstCGroupWnd_x                                           0x11AD9A0
#define pinstCGuildBankWnd_x                                       0x11ADA18
#define pinstCGuildMgmtWnd_x                                       0x11AFB08
#define pinstCHotButtonWnd_x                                       0x11AFBD4
#define pinstCHotButtonWnd1_x                                      0x11AFBD4
#define pinstCHotButtonWnd2_x                                      0x11AFBD8
#define pinstCHotButtonWnd3_x                                      0x11AFBDC
#define pinstCHotButtonWnd4_x                                      0x11AFC00
#define pinstCItemDisplayManager_x                                 0x11AFEF8
#define pinstCItemExpTransferWnd_x                                 0x11AFF74
#define pinstCLFGuildWnd_x                                         0x11B0250
#define pinstCMIZoneSelectWnd_x                                    0x11B0838
#define pinstCConfirmationDialog_x                                 0x11B0F40
#define pinstCPopupWndManager_x                                    0x11B0F40
#define pinstCProgressionSelectionWnd_x                            0x11B1030
#define pinstCPvPStatsWnd_x                                        0x11B1120
#define pinstCSystemInfoDialogBox_x                                0x11B1828
#define pinstCTaskWnd_x                                            0x11B2BF0
#define pinstCTaskSomething_x                                      0xE26E48
#define pinstCTaskTemplateSelectWnd_x                              0x11B2B78
#define pinstCTipWndOFDAY_x                                        0x11B2E48
#define pinstCTipWndCONTEXT_x                                      0x11B2E4C
#define pinstCTitleWnd_x                                           0x11B2EC8
#define pinstCContextMenuManager_x                                 0x1816884
#define pinstCVoiceMacroWnd_x                                      0x109FB08
#define pinstCHtmlWnd_x                                            0x109FBF8
#define pinstIconCache_x                                           0x11AD35C
#define pinstCTradeskillWnd_x                                      0x11B2FC8
#define pinstCAdvancedLootWnd_x                                    0xF58DBC
#define pinstRewardSelectionWnd_x                                  0x11B1648

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x533C50
#define __ConvertItemTags_x                                        0x521060
#define __ExecuteCmd_x                                             0x50BE10
#define __EQGetTime_x                                              0x89D760
#define __get_melee_range_x                                        0x512A60
#define __GetGaugeValueFromEQ_x                                    0x7A72C0
#define __GetLabelFromEQ_x                                         0x7A8510
#define __ToggleKeyRingItem_x                                      0x47FE40
#define __GetXTargetType_x                                         0x92EA80
#define __LoadFrontEnd_x                                           0x637540
#define __NewUIINI_x                                               0x7A6C90
#define __ProcessGameEvents_x                                      0x5782C0
#define __ProcessMouseEvent_x                                      0x577A60
#define CrashDetected_x                                            0x638F00
#define wwsCrashReportCheckForUploader_x                           0x7FAB30
#define DrawNetStatus_x                                            0x5AE300
#define Util__FastTime_x                                           0x89D270
#define Expansion_HoT_x                                            0x101A560
#define __HelpPath_x                                               0x109DC58
#define __STMLToText_x                                             0x8E3460

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4203A0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B1F0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C66A0
#define AltAdvManager__IsAbilityReady_x                            0x4C6710
#define AltAdvManager__GetAAById_x                                 0x4C6AD0
#define AltAdvManager__CanTrainAbility_x                           0x4C7390
#define AltAdvManager__CanSeeAbility_x                             0x4C6F90

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x465980
#define CharacterZoneClient__MakeMeVisible_x                       0x46B4B0
#define CharacterZoneClient__IsStackBlocked_x                      0x4495E0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x448AA0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x666C50

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x674BA0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58D520
#define CButtonWnd__CButtonWnd_x                                   0x8D77B0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x690040
#define CChatManager__InitContextMenu_x                            0x690BC0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E17C0
#define CContextMenu__dCContextMenu_x                              0x8E19D0
#define CContextMenu__AddMenuItem_x                                0x8E19E0
#define CContextMenu__RemoveMenuItem_x                             0x8E1CD0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E1CF0
#define CContextMenuManager__AddMenu_x                             0x8CDCF0
#define CContextMenuManager__RemoveMenu_x                          0x8CE040
#define CContextMenuManager__PopupMenu_x                           0x8CE490
#define CContextMenuManager__Flush_x                               0x8CDD60
#define CContextMenuManager__GetMenu_x                             0x416840

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x882A60
#define CChatService__GetFriendName_x                              0x882A70

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x695E10
#define CChatWindow__Clear_x                                       0x6959E0
#define CChatWindow__WndNotification_x                             0x696350

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D1B70
#define CComboWnd__Draw_x                                          0x8D1D80
#define CComboWnd__GetCurChoice_x                                  0x8D1940
#define CComboWnd__GetListRect_x                                   0x8D2020
#define CComboWnd__GetTextRect_x                                   0x8D1BE0
#define CComboWnd__InsertChoice_x                                  0x8D2090
#define CComboWnd__SetColors_x                                     0x8D18D0
#define CComboWnd__SetChoice_x                                     0x8D1900
#define CComboWnd__GetItemCount_x                                  0x8D1930
#define CComboWnd__GetCurChoiceText_x                              0x8D1980


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69F400
#define CContainerWnd__vftable_x                                   0xADFD78

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B4A90
#define CDisplay__GetClickedActor_x                                0x4AD370
#define CDisplay__GetUserDefinedColor_x                            0x4ABF50
#define CDisplay__GetWorldFilePath_x                               0x4AB3A0
#define CDisplay__is3dON_x                                         0x4AA820
#define CDisplay__ReloadUI_x                                       0x4C0070
#define CDisplay__WriteTextHD2_x                                   0x4B0DE0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F7FD0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E5CE0
#define CEditWnd__GetCharIndexPt_x                                 0x8E6D80
#define CEditWnd__GetDisplayString_x                               0x8E5E90
#define CEditWnd__GetHorzOffset_x                                  0x8E61D0
#define CEditWnd__GetLineForPrintableChar_x                        0x8E6840
#define CEditWnd__GetSelStartPt_x                                  0x8E7040
#define CEditWnd__GetSTMLSafeText_x                                0x8E6370
#define CEditWnd__PointFromPrintableChar_x                         0x8E6930
#define CEditWnd__SelectableCharFromPoint_x                        0x8E6AB0
#define CEditWnd__SetEditable_x                                    0x8E6340

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x5553F0
#define CEverQuest__CreateTargetIndicator_x                        0x556020
#define CEverQuest__DeleteTargetIndicator_x                        0x5560A0
#define CEverQuest__DoTellWindow_x                                 0x55ADF0
#define CEverQuest__DropHeldItemOnGround_x                         0x563D50
#define CEverQuest__dsp_chat_x                                     0x55C890
#define CEverQuest__Emote_x                                        0x55CAF0
#define CEverQuest__EnterZone_x                                    0x570F70
#define CEverQuest__GetBodyTypeDesc_x                              0x551B80
#define CEverQuest__GetClassDesc_x                                 0x557960
#define CEverQuest__GetClassThreeLetterCode_x                      0x557F60
#define CEverQuest__GetDeityDesc_x                                 0x552460
#define CEverQuest__GetLangDesc_x                                  0x551F10
#define CEverQuest__GetRaceDesc_x                                  0x558120
#define CEverQuest__InterpretCmd_x                                 0x55D3D0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5749C0
#define CEverQuest__LMouseUp_x                                     0x576AB0
#define CEverQuest__RightClickedOnPlayer_x                         0x5754C0
#define CEverQuest__RMouseUp_x                                     0x576510
#define CEverQuest__SetGameState_x                                 0x555AA0
#define CEverQuest__UPCNotificationFlush_x                         0x55E730
#define CEverQuest__IssuePetCommand_x                              0x55E090

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B0030
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B0090
#define CGaugeWnd__Draw_x                                          0x6B04C0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4372D0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CCBA0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D92A0
#define CInvSlotMgr__MoveItem_x                                    0x6DA1E0
#define CInvSlotMgr__SelectSlot_x                                  0x6D9350

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D8730
#define CInvSlot__SliderComplete_x                                 0x6D5F60
#define CInvSlot__GetItemBase_x                                    0x6D53E0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DB5D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A3CF0
#define CItemDisplayWnd__UpdateStrings_x                           0x6DC900

// CLabel 
#define CLabel__Draw_x                                             0x6F76D0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8BD960
#define CListWnd__dCListWnd_x                                      0x8BE990
#define CListWnd__AddColumn_x                                      0x8BE930
#define CListWnd__AddColumn1_x                                     0x8BE1A0
#define CListWnd__AddLine_x                                        0x8BDC20
#define CListWnd__AddString_x                                      0x8BDE30
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BAC80
#define CListWnd__CalculateVSBRange_x                              0x8BCE10
#define CListWnd__ClearSel_x                                       0x8B9F80
#define CListWnd__ClearAllSel_x                                    0x8B9F30
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8BD7F0
#define CListWnd__Compare_x                                        0x8BB790
#define CListWnd__Draw_x                                           0x8BCA20
#define CListWnd__DrawColumnSeparators_x                           0x8BC8B0
#define CListWnd__DrawHeader_x                                     0x8BA240
#define CListWnd__DrawItem_x                                       0x8BBDE0
#define CListWnd__DrawLine_x                                       0x8BC550
#define CListWnd__DrawSeparator_x                                  0x8BC950
#define CListWnd__EnsureVisible_x                                  0x8BADE0
#define CListWnd__ExtendSel_x                                      0x8BBCF0
#define CListWnd__GetColumnMinWidth_x                              0x8B98F0
#define CListWnd__GetColumnWidth_x                                 0x8B9810
#define CListWnd__GetCurSel_x                                      0x8B8FD0
#define CListWnd__GetItemAtPoint_x                                 0x8BB080
#define CListWnd__GetItemAtPoint1_x                                0x8BB0F0
#define CListWnd__GetItemData_x                                    0x8B9320
#define CListWnd__GetItemHeight_x                                  0x8BA8D0
#define CListWnd__GetItemIcon_x                                    0x8B9500
#define CListWnd__GetItemRect_x                                    0x8BAEC0
#define CListWnd__GetItemText_x                                    0x8B93B0
#define CListWnd__GetSelList_x                                     0x8BE090
#define CListWnd__GetSeparatorRect_x                               0x8BB6B0
#define CListWnd__RemoveLine_x                                     0x8BE010
#define CListWnd__SetColors_x                                      0x8B9120
#define CListWnd__SetColumnJustification_x                         0x8B9BC0
#define CListWnd__SetColumnWidth_x                                 0x8B98A0
#define CListWnd__SetCurSel_x                                      0x8B9010
#define CListWnd__SetItemColor_x                                   0x8BD4D0
#define CListWnd__SetItemData_x                                    0x8B9FE0
#define CListWnd__SetItemText_x                                    0x8BD310
#define CListWnd__ShiftColumnSeparator_x                           0x8BD1A0
#define CListWnd__Sort_x                                           0x8BEA90
#define CListWnd__ToggleSel_x                                      0x8B9EB0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x710700

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x731A40
#define CMerchantWnd__RequestBuyItem_x                             0x738850
#define CMerchantWnd__RequestSellItem_x                            0x7392A0
#define CMerchantWnd__SelectRecoverySlot_x                         0x731CF0
#define CMerchantWnd__SelectBuySellSlot_x                          0x730F50
#define CMerchantWnd__ActualSelect_x                               0x735790

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x84F930
#define CPacketScrambler__hton_x                                   0x84F940

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8DC770
#define CSidlManager__CreateLabel_x                                0x799D20

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65DF90
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65DEB0
#define CSidlScreenWnd__ConvertToRes_x                             0x8F7EB0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D4520
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D5700
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D57B0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D4C70
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D3ED0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D3620
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D40C0
#define CSidlScreenWnd__Init1_x                                    0x8D53D0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D45D0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D37E0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D4EC0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D3280
#define CSidlScreenWnd__StoreIniVis_x                              0x8D35D0
#define CSidlScreenWnd__WndNotification_x                          0x8D5150
#define CSidlScreenWnd__GetChildItem_x                             0x8D36F0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C6F00

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F92C0
#define CSkillMgr__GetSkillCap_x                                   0x5F9480
#define CSkillMgr__GetNameToken_x                                  0x5F8EE0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F7170
#define CSliderWnd__SetValue_x                                     0x8F7340
#define CSliderWnd__SetNumTicks_x                                  0x8F7AC0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A19A0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F2B00
#define CStmlWnd__CalculateHSBRange_x                              0x8EB010
#define CStmlWnd__CalculateVSBRange_x                              0x8EB0A0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EB220
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EBB00
#define CStmlWnd__ForceParseNow_x                                  0x8F3450
#define CStmlWnd__GetNextTagPiece_x                                0x8EBA00
#define CStmlWnd__GetSTMLText_x                                    0x695280
#define CStmlWnd__GetVisibleText_x                                 0x8EC550
#define CStmlWnd__InitializeWindowVariables_x                      0x8EE8E0
#define CStmlWnd__MakeStmlColorTag_x                               0x8EA310
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EA370
#define CStmlWnd__SetSTMLText_x                                    0x8F0150
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F27A0
#define CStmlWnd__UpdateHistoryString_x                            0x8ED490

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E98F0
#define CTabWnd__DrawCurrentPage_x                                 0x8E9160
#define CTabWnd__DrawTab_x                                         0x8E8F20
#define CTabWnd__GetCurrentPage_x                                  0x8E9530
#define CTabWnd__GetPageInnerRect_x                                0x8E8C10
#define CTabWnd__GetTabInnerRect_x                                 0x8E8E10
#define CTabWnd__GetTabRect_x                                      0x8E8CE0
#define CTabWnd__InsertPage_x                                      0x8E9BE0
#define CTabWnd__SetPage_x                                         0x8E9560
#define CTabWnd__SetPageRect_x                                     0x8E9830
#define CTabWnd__UpdatePage_x                                      0x8E9B80

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x433070

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D1540

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8FD350

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B7130

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59AB10
#define CXStr__CXStr1_x                                            0x7437C0
#define CXStr__CXStr3_x                                            0x89A330
#define CXStr__dCXStr_x                                            0x59AEF0
#define CXStr__operator_equal_x                                    0x89A4A0
#define CXStr__operator_equal1_x                                   0x89A4F0
#define CXStr__operator_plus_equal1_x                              0x89B610

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C6100
#define CXWnd__Center_x                                            0x8CC2D0
#define CXWnd__ClrFocus_x                                          0x8C5CD0
#define CXWnd__DoAllDrawing_x                                      0x8CBF20
#define CXWnd__DrawChildren_x                                      0x8CC0C0
#define CXWnd__DrawColoredRect_x                                   0x8C64C0
#define CXWnd__DrawTooltip_x                                       0x8C6770
#define CXWnd__DrawTooltipAtPoint_x                                0x8CAED0
#define CXWnd__GetBorderFrame_x                                    0x8C6BD0
#define CXWnd__GetChildWndAt_x                                     0x8CCCA0
#define CXWnd__GetClientClipRect_x                                 0x8C6980
#define CXWnd__GetScreenClipRect_x                                 0x8CB5D0
#define CXWnd__GetScreenRect_x                                     0x8C6DA0
#define CXWnd__GetTooltipRect_x                                    0x8C6600
#define CXWnd__GetWindowTextA_x                                    0x424470
#define CXWnd__IsActive_x                                          0x8C17B0
#define CXWnd__IsDescendantOf_x                                    0x8C6B10
#define CXWnd__IsReallyVisible_x                                   0x8C9F00
#define CXWnd__IsType_x                                            0x8F9B30
#define CXWnd__Move_x                                              0x8C9600
#define CXWnd__Move1_x                                             0x8CBBD0
#define CXWnd__ProcessTransition_x                                 0x8C60B0
#define CXWnd__Refade_x                                            0x8C5E80
#define CXWnd__Resize_x                                            0x8C6E60
#define CXWnd__Right_x                                             0x8CB3D0
#define CXWnd__SetFocus_x                                          0x8C8770
#define CXWnd__SetFont_x                                           0x8C5D20
#define CXWnd__SetKeyTooltip_x                                     0x8C70D0
#define CXWnd__SetMouseOver_x                                      0x8CB8C0
#define CXWnd__StartFade_x                                         0x8C6150
#define CXWnd__GetChildItem_x                                      0x8CB800

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C3060
#define CXWndManager__DrawWindows_x                                0x8C2CA0
#define CXWndManager__GetKeyboardFlags_x                           0x8C12E0
#define CXWndManager__HandleKeyboardMsg_x                          0x8C1C50
#define CXWndManager__RemoveWnd_x                                  0x8C1940

// CDBStr
#define CDBStr__GetString_x                                        0x4A8CD0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44FB90
#define EQ_Character__Cur_HP_x                                     0x465050
#define EQ_Character__Cur_Mana_x                                   0x4580A0
#define EQ_Character__GetAACastingTimeModifier_x                   0x448DB0
#define EQ_Character__GetCharInfo2_x                               0x86ECB0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43FF30
#define EQ_Character__GetFocusRangeModifier_x                      0x440180
#define EQ_Character__Max_Endurance_x                              0x5C0970
#define EQ_Character__Max_HP_x                                     0x45ACA0
#define EQ_Character__Max_Mana_x                                   0x5C07A0
#define EQ_Character__doCombatAbility_x                            0x5BDDE0
#define EQ_Character__UseSkill_x                                   0x4706A0
#define EQ_Character__GetConLevel_x                                0x5B28C0
#define EQ_Character__IsExpansionFlag_x                            0x4239A0
#define EQ_Character__TotalEffect_x                                0x44CDD0
#define EQ_Character__GetPCSpellAffect_x                           0x4491B0
#define EQ_Character__SpellDuration_x                              0x4470D0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x592D90
#define EQ_Item__CreateItemTagString_x                             0x84E250
#define EQ_Item__IsStackable_x                                     0x842650
#define EQ_Item__GetImageNum_x                                     0x845170
#define EQ_Item__CreateItemClient_x                                0x593950
#define EQ_Item__GetItemValue_x                                    0x84CF70
#define EQ_Item__ValueSellMerchant_x                               0x84F580

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C8850
#define EQ_LoadingS__Array_x                                       0xC1C738

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C1FC0
#define EQ_PC__GetAlternateAbilityId_x                             0x8577F0
#define EQ_PC__GetCombatAbility_x                                  0x857880
#define EQ_PC__GetCombatAbilityTimer_x                             0x852720
#define EQ_PC__GetItemTimerValue_x                                 0x5BB880
#define EQ_PC__HasLoreItem_x                                       0x5B5DB0
#define EQ_PC__AlertInventoryChanged_x                             0x5B2890
#define EQ_PC__GetPcZoneClient_x                                   0x5DC7D0
#define EQ_PC__RemoveMyAffect_x                                    0x5BAD30

// EQItemList 
#define EQItemList__EQItemList_x                                   0x510A90
#define EQItemList__add_item_x                                     0x5109D0
#define EQItemList__delete_item_x                                  0x510E90
#define EQItemList__FreeItemList_x                                 0x510D90

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A7FD0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C7580
#define EQPlayer__dEQPlayer_x                                      0x5D0460
#define EQPlayer__DoAttack_x                                       0x5E2750
#define EQPlayer__EQPlayer_x                                       0x5D2880
#define EQPlayer__SetNameSpriteState_x                             0x5CD330
#define EQPlayer__SetNameSpriteTint_x                              0x5C89B0
#define PlayerBase__HasProperty_j_x                                0x92ACB0
#define EQPlayer__IsTargetable_x                                   0x92B5B0
#define EQPlayer__CanSee_x                                         0x92BAD0
#define PlayerZoneClient__ChangeHeight_x                           0x5E2610
#define EQPlayer__CanSeeTargetIndicator_x                          0x92BBC0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D6C80
#define EQPlayerManager__GetSpawnByName_x                          0x5D70E0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D6CB0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x598EE0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x598F20
#define KeypressHandler__ClearCommandStateArray_x                  0x598AD0
#define KeypressHandler__HandleKeyDown_x                           0x597430
#define KeypressHandler__HandleKeyUp_x                             0x597750
#define KeypressHandler__SaveKeymapping_x                          0x598BA0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7090B0
#define MapViewMap__SaveEx_x                                       0x70C3C0

#define PlayerPointManager__GetAltCurrency_x                       0x869C80

// StringTable 
#define StringTable__getString_x                                   0x864810

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C0420
#define PcZoneClient__RemovePetEffect_x                            0x5BBD70
#define PcZoneClient__HasAlternateAbility_x                        0x5BC830

//Doors
#define EQSwitch__UseSwitch_x                                      0x54EFB0

//IconCache
#define IconCache__GetIcon_x                                       0x6A5930

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69C710
#define CContainerMgr__CloseContainer_x                            0x69CF30

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76A060

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58BFC0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E09D0
#define EQ_Spell__SpellAffects_x                                   0x4DE080
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DE0F0
#define CharacterZoneClient__CalcAffectChange_x                    0x4481F0
#define CLootWnd__LootAll_x                                        0x6FE9B0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AF6D0
#define CTargetWnd__WndNotification_x                              0x7AF1C0
#define CTargetWnd__UpdateBuffs_x                                  0x7AF8B0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B48B0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D9970

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x498570

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E5310
#define CSidlManager__FindAnimation1_x                             0x8DA660

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CFF60
#define CAltAbilityData__GetMercMaxRank_x                          0x4CFF10
#define CAltAbilityData__GetMaxRank_x                              0x4C4D60

//CTargetRing
#define CTargetRing__Cast_x                                        0x5898B0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x456A80

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6870E0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6868A0

//messages
#define msg_spell_worn_off_x                                       0x4E83F0
#define msg_new_text_x                                             0x4F1830
#define msgTokenTextParam_x                                        0x4EE1F0
