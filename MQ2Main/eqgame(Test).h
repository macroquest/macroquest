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
#define __ExpectedVersionTime                                     "16:32:03"
#define __ActualVersionDate_x                                      0xAD6330
#define __ActualVersionTime_x                                      0xAD633C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59E300
#define __MemChecker1_x                                            0x89D710
#define __MemChecker2_x                                            0x6377B0
#define __MemChecker3_x                                            0x637700
#define __MemChecker4_x                                            0x7EAD50
#define __EncryptPad0_x                                            0xC73378
#define __EncryptPad1_x                                            0xDFED08
#define __EncryptPad2_x                                            0xCBCE68
#define __EncryptPad3_x                                            0xCBCA68
#define __EncryptPad4_x                                            0xDD6EF8
#define __EncryptPad5_x                                            0x11AAB78
#define __AC1_x                                                    0x7A7FC5
#define __AC2_x                                                    0x554A47
#define __AC3_x                                                    0x569670
#define __AC4_x                                                    0x5703C0
#define __AC5_x                                                    0x57BBEE
#define __AC6_x                                                    0x57F7A9
#define __AC7_x                                                    0x5762EC
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
#define __do_loot_x                                                0x51C460
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
#define __CastRay_x                                                0x533A50
#define __ConvertItemTags_x                                        0x520E50
#define __ExecuteCmd_x                                             0x50BC60
#define __EQGetTime_x                                              0x89D340
#define __get_melee_range_x                                        0x512860
#define __GetGaugeValueFromEQ_x                                    0x7A6D00
#define __GetLabelFromEQ_x                                         0x7A7F50
#define __ToggleKeyRingItem_x                                      0x47FAF0
#define __GetXTargetType_x                                         0x92E790
#define __LoadFrontEnd_x                                           0x636E80
#define __NewUIINI_x                                               0x7A66E0
#define __ProcessGameEvents_x                                      0x578050
#define __ProcessMouseEvent_x                                      0x5777F0
#define CrashDetected_x                                            0x638840
#define wwsCrashReportCheckForUploader_x                           0x7FA5D0
#define DrawNetStatus_x                                            0x5ADE40
#define Util__FastTime_x                                           0x89CE50
#define Expansion_HoT_x                                            0x101A560
#define __HelpPath_x                                               0x109DC58
#define __STMLToText_x                                             0x8E3030

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420260
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B0B0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41AE90

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C6460
#define AltAdvManager__IsAbilityReady_x                            0x4C64D0
#define AltAdvManager__GetAAById_x                                 0x4C6890
#define AltAdvManager__CanTrainAbility_x                           0x4C7150
#define AltAdvManager__CanSeeAbility_x                             0x4C6D50

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x465550
#define CharacterZoneClient__MakeMeVisible_x                       0x46B080
#define CharacterZoneClient__IsStackBlocked_x                      0x449130
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4485F0
#define CharacterZoneClient__GetItemCountWorn_x                    0x462DE0
#define CharacterZoneClient__GetItemCountInInventory_x             0x462ED0
#define CharacterZoneClient__GetCursorItemCount_x                  0x462FD0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x666740

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x674D90

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58D290
#define CButtonWnd__CButtonWnd_x                                   0x8D72F0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68FA70
#define CChatManager__InitContextMenu_x                            0x6905F0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E1390
#define CContextMenu__dCContextMenu_x                              0x8E15A0
#define CContextMenu__AddMenuItem_x                                0x8E15B0
#define CContextMenu__RemoveMenuItem_x                             0x8E18A0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E18C0
#define CContextMenuManager__AddMenu_x                             0x8CD860
#define CContextMenuManager__RemoveMenu_x                          0x8CDBC0
#define CContextMenuManager__PopupMenu_x                           0x8CE010
#define CContextMenuManager__Flush_x                               0x8CD8D0
#define CContextMenuManager__GetMenu_x                             0x416700

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x882630
#define CChatService__GetFriendName_x                              0x882640

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x695840
#define CChatWindow__Clear_x                                       0x695410
#define CChatWindow__WndNotification_x                             0x695D80

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D16C0
#define CComboWnd__Draw_x                                          0x8D18D0
#define CComboWnd__GetCurChoice_x                                  0x8D1490
#define CComboWnd__GetListRect_x                                   0x8D1B70
#define CComboWnd__GetTextRect_x                                   0x8D1730
#define CComboWnd__InsertChoice_x                                  0x8D1BE0
#define CComboWnd__SetColors_x                                     0x8D1420
#define CComboWnd__SetChoice_x                                     0x8D1450
#define CComboWnd__GetItemCount_x                                  0x8D1480
#define CComboWnd__GetCurChoiceText_x                              0x8D14D0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69EE70
#define CContainerWnd__vftable_x                                   0xADFD28

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B4730
#define CDisplay__GetClickedActor_x                                0x4AD020
#define CDisplay__GetUserDefinedColor_x                            0x4ABC00
#define CDisplay__GetWorldFilePath_x                               0x4AB050
#define CDisplay__is3dON_x                                         0x4AA4D0
#define CDisplay__ReloadUI_x                                       0x4BFD10
#define CDisplay__WriteTextHD2_x                                   0x4B0A80

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F7B80

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E58B0
#define CEditWnd__GetCharIndexPt_x                                 0x8E6950
#define CEditWnd__GetDisplayString_x                               0x8E5A60
#define CEditWnd__GetHorzOffset_x                                  0x8E5DA0
#define CEditWnd__GetLineForPrintableChar_x                        0x8E6410
#define CEditWnd__GetSelStartPt_x                                  0x8E6C10
#define CEditWnd__GetSTMLSafeText_x                                0x8E5F40
#define CEditWnd__PointFromPrintableChar_x                         0x8E6500
#define CEditWnd__SelectableCharFromPoint_x                        0x8E6680
#define CEditWnd__SetEditable_x                                    0x8E5F10

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x555190
#define CEverQuest__CreateTargetIndicator_x                        0x555DC0
#define CEverQuest__DeleteTargetIndicator_x                        0x555E40
#define CEverQuest__DoTellWindow_x                                 0x55AB90
#define CEverQuest__DropHeldItemOnGround_x                         0x563AF0
#define CEverQuest__dsp_chat_x                                     0x55C630
#define CEverQuest__Emote_x                                        0x55C890
#define CEverQuest__EnterZone_x                                    0x570D10
#define CEverQuest__GetBodyTypeDesc_x                              0x551920
#define CEverQuest__GetClassDesc_x                                 0x557700
#define CEverQuest__GetClassThreeLetterCode_x                      0x557D00
#define CEverQuest__GetDeityDesc_x                                 0x552200
#define CEverQuest__GetLangDesc_x                                  0x551CB0
#define CEverQuest__GetRaceDesc_x                                  0x557EC0
#define CEverQuest__InterpretCmd_x                                 0x55D170
#define CEverQuest__LeftClickedOnPlayer_x                          0x574760
#define CEverQuest__LMouseUp_x                                     0x576840
#define CEverQuest__RightClickedOnPlayer_x                         0x575260
#define CEverQuest__RMouseUp_x                                     0x5762A0
#define CEverQuest__SetGameState_x                                 0x555840
#define CEverQuest__UPCNotificationFlush_x                         0x55E4D0
#define CEverQuest__IssuePetCommand_x                              0x55DE30

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AFB90
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AFBF0
#define CGaugeWnd__Draw_x                                          0x6B0020

// CGuild
#define CGuild__FindMemberByName_x                                 0x436EF0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CC670

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D8DA0
#define CInvSlotMgr__MoveItem_x                                    0x6D9CD0
#define CInvSlotMgr__SelectSlot_x                                  0x6D8E50

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D8230
#define CInvSlot__SliderComplete_x                                 0x6D5A60
#define CInvSlot__GetItemBase_x                                    0x6D4EC0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DB0D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A37A0
#define CItemDisplayWnd__UpdateStrings_x                           0x6DC420

// CLabel 
#define CLabel__Draw_x                                             0x6F71D0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8BD520
#define CListWnd__dCListWnd_x                                      0x8BE550
#define CListWnd__AddColumn_x                                      0x8BE4F0
#define CListWnd__AddColumn1_x                                     0x8BDD60
#define CListWnd__AddLine_x                                        0x8BD7E0
#define CListWnd__AddString_x                                      0x8BD9F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BA860
#define CListWnd__CalculateVSBRange_x                              0x8BC9D0
#define CListWnd__ClearSel_x                                       0x8B9B70
#define CListWnd__ClearAllSel_x                                    0x8B9B20
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8BD3B0
#define CListWnd__Compare_x                                        0x8BB360
#define CListWnd__Draw_x                                           0x8BC5E0
#define CListWnd__DrawColumnSeparators_x                           0x8BC470
#define CListWnd__DrawHeader_x                                     0x8B9E30
#define CListWnd__DrawItem_x                                       0x8BB9A0
#define CListWnd__DrawLine_x                                       0x8BC110
#define CListWnd__DrawSeparator_x                                  0x8BC510
#define CListWnd__EnsureVisible_x                                  0x8BA9C0
#define CListWnd__ExtendSel_x                                      0x8BB8B0
#define CListWnd__GetColumnMinWidth_x                              0x8B94E0
#define CListWnd__GetColumnWidth_x                                 0x8B9400
#define CListWnd__GetCurSel_x                                      0x8B8BD0
#define CListWnd__GetItemAtPoint_x                                 0x8BAC60
#define CListWnd__GetItemAtPoint1_x                                0x8BACD0
#define CListWnd__GetItemData_x                                    0x8B8F10
#define CListWnd__GetItemHeight_x                                  0x8BA4C0
#define CListWnd__GetItemIcon_x                                    0x8B90F0
#define CListWnd__GetItemRect_x                                    0x8BAAA0
#define CListWnd__GetItemText_x                                    0x8B8FA0
#define CListWnd__GetSelList_x                                     0x8BDC50
#define CListWnd__GetSeparatorRect_x                               0x8BB290
#define CListWnd__RemoveLine_x                                     0x8BDBD0
#define CListWnd__SetColors_x                                      0x8B8D20
#define CListWnd__SetColumnJustification_x                         0x8B97B0
#define CListWnd__SetColumnWidth_x                                 0x8B9490
#define CListWnd__SetCurSel_x                                      0x8B8C10
#define CListWnd__SetItemColor_x                                   0x8BD090
#define CListWnd__SetItemData_x                                    0x8B9BD0
#define CListWnd__SetItemText_x                                    0x8BCED0
#define CListWnd__ShiftColumnSeparator_x                           0x8BCD60
#define CListWnd__Sort_x                                           0x8BE650
#define CListWnd__ToggleSel_x                                      0x8B9AA0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x710250

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7314D0
#define CMerchantWnd__RequestBuyItem_x                             0x7382E0
#define CMerchantWnd__RequestSellItem_x                            0x738D30
#define CMerchantWnd__SelectRecoverySlot_x                         0x731780
#define CMerchantWnd__SelectBuySellSlot_x                          0x7309E0
#define CMerchantWnd__ActualSelect_x                               0x735220

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x84F310
#define CPacketScrambler__hton_x                                   0x84F320

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8DC300
#define CSidlManager__CreateLabel_x                                0x799740

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65DA80
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65D9A0
#define CSidlScreenWnd__ConvertToRes_x                             0x8F7A60
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D4040
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D5230
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D52E0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D47A0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D39F0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D3180
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D3BE0
#define CSidlScreenWnd__Init1_x                                    0x8D4F00
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D40F0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D3340
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D49F0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D2DD0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D3130
#define CSidlScreenWnd__WndNotification_x                          0x8D4C80
#define CSidlScreenWnd__GetChildItem_x                             0x8D3250
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C6B10

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F8DC0
#define CSkillMgr__GetSkillCap_x                                   0x5F8F80
#define CSkillMgr__GetNameToken_x                                  0x5F89E0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F6D10
#define CSliderWnd__SetValue_x                                     0x8F6EE0
#define CSliderWnd__SetNumTicks_x                                  0x8F7660

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A1450

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F25F0
#define CStmlWnd__CalculateHSBRange_x                              0x8EAB30
#define CStmlWnd__CalculateVSBRange_x                              0x8EABC0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EAD30
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EB610
#define CStmlWnd__ForceParseNow_x                                  0x8F2FB0
#define CStmlWnd__GetNextTagPiece_x                                0x8EB510
#define CStmlWnd__GetSTMLText_x                                    0x694CB0
#define CStmlWnd__GetVisibleText_x                                 0x8EC060
#define CStmlWnd__InitializeWindowVariables_x                      0x8EE3D0
#define CStmlWnd__MakeStmlColorTag_x                               0x8E9E30
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E9E90
#define CStmlWnd__SetSTMLText_x                                    0x8EFC30
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F2290
#define CStmlWnd__UpdateHistoryString_x                            0x8ECF90

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E94C0
#define CTabWnd__DrawCurrentPage_x                                 0x8E8D30
#define CTabWnd__DrawTab_x                                         0x8E8AF0
#define CTabWnd__GetCurrentPage_x                                  0x8E9100
#define CTabWnd__GetPageInnerRect_x                                0x8E87E0
#define CTabWnd__GetTabInnerRect_x                                 0x8E89E0
#define CTabWnd__GetTabRect_x                                      0x8E88B0
#define CTabWnd__InsertPage_x                                      0x8E97B0
#define CTabWnd__SetPage_x                                         0x8E9130
#define CTabWnd__SetPageRect_x                                     0x8E9400
#define CTabWnd__UpdatePage_x                                      0x8E9750

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432D30

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D1090

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8FCF00

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B6E30

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59A800
#define CXStr__CXStr1_x                                            0x8ABA90
#define CXStr__CXStr3_x                                            0x899F10
#define CXStr__dCXStr_x                                            0x8F3A70
#define CXStr__operator_equal_x                                    0x89A080
#define CXStr__operator_equal1_x                                   0x89A0D0
#define CXStr__operator_plus_equal1_x                              0x89B1F0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C5D30
#define CXWnd__Center_x                                            0x8CBE60
#define CXWnd__ClrFocus_x                                          0x8C5900
#define CXWnd__DoAllDrawing_x                                      0x8CBAB0
#define CXWnd__DrawChildren_x                                      0x8CBC50
#define CXWnd__DrawColoredRect_x                                   0x8C60D0
#define CXWnd__DrawTooltip_x                                       0x8C6370
#define CXWnd__DrawTooltipAtPoint_x                                0x8CAA20
#define CXWnd__GetBorderFrame_x                                    0x8C67E0
#define CXWnd__GetChildWndAt_x                                     0x8CC830
#define CXWnd__GetClientClipRect_x                                 0x8C6590
#define CXWnd__GetScreenClipRect_x                                 0x8CB120
#define CXWnd__GetScreenRect_x                                     0x8C69B0
#define CXWnd__GetTooltipRect_x                                    0x8C6200
#define CXWnd__GetWindowTextA_x                                    0x424290
#define CXWnd__IsActive_x                                          0x8C1330
#define CXWnd__IsDescendantOf_x                                    0x8C6720
#define CXWnd__IsReallyVisible_x                                   0x8C9A70
#define CXWnd__IsType_x                                            0x8F9720
#define CXWnd__Move_x                                              0x8C91B0
#define CXWnd__Move1_x                                             0x8CB760
#define CXWnd__ProcessTransition_x                                 0x8C5CD0
#define CXWnd__Refade_x                                            0x8C5AA0
#define CXWnd__Resize_x                                            0x8C6A80
#define CXWnd__Right_x                                             0x8CAF20
#define CXWnd__SetFocus_x                                          0x8C8310
#define CXWnd__SetFont_x                                           0x8C5950
#define CXWnd__SetKeyTooltip_x                                     0x8C6CE0
#define CXWnd__SetMouseOver_x                                      0x8CB470
#define CXWnd__StartFade_x                                         0x8C5D80
#define CXWnd__GetChildItem_x                                      0x8CB3B0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C2BC0
#define CXWndManager__DrawWindows_x                                0x8C2810
#define CXWndManager__GetKeyboardFlags_x                           0x8C0E60
#define CXWndManager__HandleKeyboardMsg_x                          0x8C17D0
#define CXWndManager__RemoveWnd_x                                  0x8C14C0

// CDBStr
#define CDBStr__GetString_x                                        0x4A8A40

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44F6E0
#define EQ_Character__Cur_HP_x                                     0x464C20
#define EQ_Character__Cur_Mana_x                                   0x457C60
#define EQ_Character__GetAACastingTimeModifier_x                   0x448900
#define EQ_Character__GetCharInfo2_x                               0x86E830
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43FB20
#define EQ_Character__GetFocusRangeModifier_x                      0x43FD70
#define EQ_Character__Max_Endurance_x                              0x5C0880
#define EQ_Character__Max_HP_x                                     0x45A860
#define EQ_Character__Max_Mana_x                                   0x5C06B0
#define EQ_Character__doCombatAbility_x                            0x5BDD00
#define EQ_Character__UseSkill_x                                   0x470280
#define EQ_Character__GetConLevel_x                                0x5B2410
#define EQ_Character__IsExpansionFlag_x                            0x4237D0
#define EQ_Character__TotalEffect_x                                0x44C920
#define EQ_Character__GetPCSpellAffect_x                           0x448D00
#define EQ_Character__SpellDuration_x                              0x446C20

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x592B60
#define EQ_Item__CreateItemTagString_x                             0x84DC20
#define EQ_Item__IsStackable_x                                     0x8420F0
#define EQ_Item__GetImageNum_x                                     0x844B10
#define EQ_Item__CreateItemClient_x                                0x593710
#define EQ_Item__GetItemValue_x                                    0x84C930
#define EQ_Item__ValueSellMerchant_x                               0x84EF60

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C8550
#define EQ_LoadingS__Array_x                                       0xC1C738

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C1EE0
#define EQ_PC__GetAlternateAbilityId_x                             0x857260
#define EQ_PC__GetCombatAbility_x                                  0x8572F0
#define EQ_PC__GetCombatAbilityTimer_x                             0x852100
#define EQ_PC__GetItemTimerValue_x                                 0x5BB790
#define EQ_PC__HasLoreItem_x                                       0x5B5900
#define EQ_PC__AlertInventoryChanged_x                             0x5B23E0
#define EQ_PC__GetPcZoneClient_x                                   0x5DC570
#define EQ_PC__RemoveMyAffect_x                                    0x5BAC40

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5108B0
#define EQItemList__add_item_x                                     0x5107F0
#define EQItemList__delete_item_x                                  0x510CB0
#define EQItemList__FreeItemList_x                                 0x510BB0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A7C10

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C7490
#define EQPlayer__dEQPlayer_x                                      0x5D0350
#define EQPlayer__DoAttack_x                                       0x5E2500
#define EQPlayer__EQPlayer_x                                       0x5D2770
#define EQPlayer__SetNameSpriteState_x                             0x5CD240
#define EQPlayer__SetNameSpriteTint_x                              0x5C88C0
#define PlayerBase__HasProperty_j_x                                0x92A980
#define EQPlayer__IsTargetable_x                                   0x92B280
#define EQPlayer__CanSee_x                                         0x92B7A0
#define PlayerZoneClient__ChangeHeight_x                           0x5E23C0
#define EQPlayer__CanSeeTargetIndicator_x                          0x92B890

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D6B60
#define EQPlayerManager__GetSpawnByName_x                          0x5D6FC0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D6B90

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x598BD0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x598C10
#define KeypressHandler__ClearCommandStateArray_x                  0x5987C0
#define KeypressHandler__HandleKeyDown_x                           0x597120
#define KeypressHandler__HandleKeyUp_x                             0x597440
#define KeypressHandler__SaveKeymapping_x                          0x598890

// MapViewMap 
#define MapViewMap__Clear_x                                        0x708C00
#define MapViewMap__SaveEx_x                                       0x70BF10

#define PlayerPointManager__GetAltCurrency_x                       0x869800

// StringTable 
#define StringTable__getString_x                                   0x864290

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C0330
#define PcZoneClient__RemovePetEffect_x                            0x5BBC80
#define PcZoneClient__HasAlternateAbility_x                        0x5BC740

//Doors
#define EQSwitch__UseSwitch_x                                      0x54EC90

//IconCache
#define IconCache__GetIcon_x                                       0x6A53C0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69C180
#define CContainerMgr__CloseContainer_x                            0x69C9A0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x769AF0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58BD30

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E0710
#define EQ_Spell__SpellAffects_x                                   0x4DDDC0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DDE30
#define CharacterZoneClient__CalcAffectChange_x                    0x447D40
#define CLootWnd__LootAll_x                                        0x6FE4F0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AF180
#define CTargetWnd__WndNotification_x                              0x7AEC70
#define CTargetWnd__UpdateBuffs_x                                  0x7AF360

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B4360

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D9750

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4981F0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E4EE0
#define CSidlManager__FindAnimation1_x                             0x8DA200

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CFC80
#define CAltAbilityData__GetMercMaxRank_x                          0x4CFC30
#define CAltAbilityData__GetMaxRank_x                              0x4C4B20

//CTargetRing
#define CTargetRing__Cast_x                                        0x589630

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4565F0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x686B80
#define CCastSpellWnd__IsBardSongPlaying_x                         0x686340

//messages
#define msg_spell_worn_off_x                                       0x4E8190
#define msg_new_text_x                                             0x4F15D0
#define msgTokenTextParam_x                                        0x4EE0B0
