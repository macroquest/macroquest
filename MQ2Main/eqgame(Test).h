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
#define __ExpectedVersionDate                                     "Mar 31 2016"
#define __ExpectedVersionTime                                     "16:40:39"
#define __ActualVersionDate_x                                      0xAD6320
#define __ActualVersionTime_x                                      0xAD632C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59E340
#define __MemChecker1_x                                            0x89DA00
#define __MemChecker2_x                                            0x637AA0
#define __MemChecker3_x                                            0x6379F0
#define __MemChecker4_x                                            0x7EAAC0
#define __EncryptPad0_x                                            0xC73378
#define __EncryptPad1_x                                            0xDFED08
#define __EncryptPad2_x                                            0xCBCE68
#define __EncryptPad3_x                                            0xCBCA68
#define __EncryptPad4_x                                            0xDD6EF8
#define __EncryptPad5_x                                            0x11AAB78
#define __AC1_x                                                    0x7A8475
#define __AC2_x                                                    0x5547E7
#define __AC3_x                                                    0x569410
#define __AC4_x                                                    0x570160
#define __AC5_x                                                    0x57B98E
#define __AC6_x                                                    0x57F559
#define __AC7_x                                                    0x57608C
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
#define __do_loot_x                                                0x51C210
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
#define __CastRay_x                                                0x533800
#define __ConvertItemTags_x                                        0x520C00
#define __ExecuteCmd_x                                             0x50B980
#define __EQGetTime_x                                              0x89D630
#define __get_melee_range_x                                        0x512600
#define __GetGaugeValueFromEQ_x                                    0x7A71B0
#define __GetLabelFromEQ_x                                         0x7A8400
#define __ToggleKeyRingItem_x                                      0x47F8D0
#define __GetXTargetType_x                                         0x92E910
#define __LoadFrontEnd_x                                           0x637170
#define __NewUIINI_x                                               0x7A6B80
#define __ProcessGameEvents_x                                      0x577DF0
#define __ProcessMouseEvent_x                                      0x577590
#define CrashDetected_x                                            0x638B30
#define wwsCrashReportCheckForUploader_x                           0x7FA940
#define DrawNetStatus_x                                            0x5ADD90
#define Util__FastTime_x                                           0x89D140
#define Expansion_HoT_x                                            0x101A560
#define __HelpPath_x                                               0x109DC58
#define __STMLToText_x                                             0x8E3500

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420160
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41AFD0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41ADB0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C6120
#define AltAdvManager__IsAbilityReady_x                            0x4C6190
#define AltAdvManager__GetAAById_x                                 0x4C6550
#define AltAdvManager__CanTrainAbility_x                           0x4C6E10
#define AltAdvManager__CanSeeAbility_x                             0x4C6A10

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x465450
#define CharacterZoneClient__MakeMeVisible_x                       0x46AF80
#define CharacterZoneClient__IsStackBlocked_x                      0x4490F0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4485B0
#define CharacterZoneClient__GetItemCountWorn_x                    0x462CF0
#define CharacterZoneClient__GetItemCountInInventory_x             0x462DE0
#define CharacterZoneClient__GetCursorItemCount_x                  0x462EE0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x666AE0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x674E90

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58D180
#define CButtonWnd__CButtonWnd_x                                   0x8D77D0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68FF10
#define CChatManager__InitContextMenu_x                            0x690A90

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E1860
#define CContextMenu__dCContextMenu_x                              0x8E1A70
#define CContextMenu__AddMenuItem_x                                0x8E1A80
#define CContextMenu__RemoveMenuItem_x                             0x8E1D70
#define CContextMenu__RemoveAllMenuItems_x                         0x8E1D90
#define CContextMenuManager__AddMenu_x                             0x8CDD10
#define CContextMenuManager__RemoveMenu_x                          0x8CE070
#define CContextMenuManager__PopupMenu_x                           0x8CE4C0
#define CContextMenuManager__Flush_x                               0x8CDD80
#define CContextMenuManager__GetMenu_x                             0x416640

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x882980
#define CChatService__GetFriendName_x                              0x882990

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x695CE0
#define CChatWindow__Clear_x                                       0x6958B0
#define CChatWindow__WndNotification_x                             0x696210

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D1B90
#define CComboWnd__Draw_x                                          0x8D1DA0
#define CComboWnd__GetCurChoice_x                                  0x8D1960
#define CComboWnd__GetListRect_x                                   0x8D2040
#define CComboWnd__GetTextRect_x                                   0x8D1C00
#define CComboWnd__InsertChoice_x                                  0x8D20B0
#define CComboWnd__SetColors_x                                     0x8D18F0
#define CComboWnd__SetChoice_x                                     0x8D1920
#define CComboWnd__GetItemCount_x                                  0x8D1950
#define CComboWnd__GetCurChoiceText_x                              0x8D19A0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69F2B0
#define CContainerWnd__vftable_x                                   0xADFD18

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B43C0
#define CDisplay__GetClickedActor_x                                0x4ACCB0
#define CDisplay__GetUserDefinedColor_x                            0x4AB890
#define CDisplay__GetWorldFilePath_x                               0x4AACE0
#define CDisplay__is3dON_x                                         0x4AA160
#define CDisplay__ReloadUI_x                                       0x4BF9A0
#define CDisplay__WriteTextHD2_x                                   0x4B0710

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F8000

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E5D80
#define CEditWnd__GetCharIndexPt_x                                 0x8E6E20
#define CEditWnd__GetDisplayString_x                               0x8E5F30
#define CEditWnd__GetHorzOffset_x                                  0x8E6270
#define CEditWnd__GetLineForPrintableChar_x                        0x8E68E0
#define CEditWnd__GetSelStartPt_x                                  0x8E70E0
#define CEditWnd__GetSTMLSafeText_x                                0x8E6410
#define CEditWnd__PointFromPrintableChar_x                         0x8E69D0
#define CEditWnd__SelectableCharFromPoint_x                        0x8E6B50
#define CEditWnd__SetEditable_x                                    0x8E63E0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x554F30
#define CEverQuest__CreateTargetIndicator_x                        0x555B60
#define CEverQuest__DeleteTargetIndicator_x                        0x555BE0
#define CEverQuest__DoTellWindow_x                                 0x55A930
#define CEverQuest__DropHeldItemOnGround_x                         0x563890
#define CEverQuest__dsp_chat_x                                     0x55C3D0
#define CEverQuest__Emote_x                                        0x55C630
#define CEverQuest__EnterZone_x                                    0x570AB0
#define CEverQuest__GetBodyTypeDesc_x                              0x5516C0
#define CEverQuest__GetClassDesc_x                                 0x5574A0
#define CEverQuest__GetClassThreeLetterCode_x                      0x557AA0
#define CEverQuest__GetDeityDesc_x                                 0x551FA0
#define CEverQuest__GetLangDesc_x                                  0x551A50
#define CEverQuest__GetRaceDesc_x                                  0x557C60
#define CEverQuest__InterpretCmd_x                                 0x55CF10
#define CEverQuest__LeftClickedOnPlayer_x                          0x5744F0
#define CEverQuest__LMouseUp_x                                     0x5765E0
#define CEverQuest__RightClickedOnPlayer_x                         0x574FF0
#define CEverQuest__RMouseUp_x                                     0x576040
#define CEverQuest__SetGameState_x                                 0x5555E0
#define CEverQuest__UPCNotificationFlush_x                         0x55E270
#define CEverQuest__IssuePetCommand_x                              0x55DBD0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B0050
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B00B0
#define CGaugeWnd__Draw_x                                          0x6B04E0

// CGuild
#define CGuild__FindMemberByName_x                                 0x436E20

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CCB70

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D92B0
#define CInvSlotMgr__MoveItem_x                                    0x6DA1F0
#define CInvSlotMgr__SelectSlot_x                                  0x6D9360

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D8740
#define CInvSlot__SliderComplete_x                                 0x6D5F80
#define CInvSlot__GetItemBase_x                                    0x6D53F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DB5B0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A3C00
#define CItemDisplayWnd__UpdateStrings_x                           0x6DC920

// CLabel 
#define CLabel__Draw_x                                             0x6F76D0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8BD870
#define CListWnd__dCListWnd_x                                      0x8BE890
#define CListWnd__AddColumn_x                                      0x8BE830
#define CListWnd__AddColumn1_x                                     0x8BE0B0
#define CListWnd__AddLine_x                                        0x8BDB30
#define CListWnd__AddString_x                                      0x8BDD40
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BABB0
#define CListWnd__CalculateVSBRange_x                              0x8BCD20
#define CListWnd__ClearSel_x                                       0x8B9EB0
#define CListWnd__ClearAllSel_x                                    0x8B9E60
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8BD700
#define CListWnd__Compare_x                                        0x8BB6B0
#define CListWnd__Draw_x                                           0x8BC930
#define CListWnd__DrawColumnSeparators_x                           0x8BC7C0
#define CListWnd__DrawHeader_x                                     0x8BA170
#define CListWnd__DrawItem_x                                       0x8BBCF0
#define CListWnd__DrawLine_x                                       0x8BC460
#define CListWnd__DrawSeparator_x                                  0x8BC860
#define CListWnd__EnsureVisible_x                                  0x8BAD10
#define CListWnd__ExtendSel_x                                      0x8BBC00
#define CListWnd__GetColumnMinWidth_x                              0x8B9820
#define CListWnd__GetColumnWidth_x                                 0x8B9740
#define CListWnd__GetCurSel_x                                      0x8B8F10
#define CListWnd__GetItemAtPoint_x                                 0x8BAFB0
#define CListWnd__GetItemAtPoint1_x                                0x8BB020
#define CListWnd__GetItemData_x                                    0x8B9250
#define CListWnd__GetItemHeight_x                                  0x8BA800
#define CListWnd__GetItemIcon_x                                    0x8B9430
#define CListWnd__GetItemRect_x                                    0x8BADF0
#define CListWnd__GetItemText_x                                    0x8B92E0
#define CListWnd__GetSelList_x                                     0x8BDFA0
#define CListWnd__GetSeparatorRect_x                               0x8BB5D0
#define CListWnd__RemoveLine_x                                     0x8BDF20
#define CListWnd__SetColors_x                                      0x8B9060
#define CListWnd__SetColumnJustification_x                         0x8B9AF0
#define CListWnd__SetColumnWidth_x                                 0x8B97D0
#define CListWnd__SetCurSel_x                                      0x8B8F50
#define CListWnd__SetItemColor_x                                   0x8BD3E0
#define CListWnd__SetItemData_x                                    0x8B9F10
#define CListWnd__SetItemText_x                                    0x8BD220
#define CListWnd__ShiftColumnSeparator_x                           0x8BD0B0
#define CListWnd__Sort_x                                           0x8BE990
#define CListWnd__ToggleSel_x                                      0x8B9DE0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7107F0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x731A80
#define CMerchantWnd__RequestBuyItem_x                             0x7388C0
#define CMerchantWnd__RequestSellItem_x                            0x739330
#define CMerchantWnd__SelectRecoverySlot_x                         0x731D30
#define CMerchantWnd__SelectBuySellSlot_x                          0x730F90
#define CMerchantWnd__ActualSelect_x                               0x735800

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x84F5D0
#define CPacketScrambler__hton_x                                   0x84F5E0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8DC7B0
#define CSidlManager__CreateLabel_x                                0x799C60

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65DD70
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65DC90
#define CSidlScreenWnd__ConvertToRes_x                             0x8F7EE0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D4520
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D5700
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D57B0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D4C70
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D3ED0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D3630
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D40C0
#define CSidlScreenWnd__Init1_x                                    0x8D53E0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D45D0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D37F0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D4EC0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D3290
#define CSidlScreenWnd__StoreIniVis_x                              0x8D35E0
#define CSidlScreenWnd__WndNotification_x                          0x8D5160
#define CSidlScreenWnd__GetChildItem_x                             0x8D3700
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C6F80

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F90E0
#define CSkillMgr__GetSkillCap_x                                   0x5F92A0
#define CSkillMgr__GetNameToken_x                                  0x5F8D00

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F7180
#define CSliderWnd__SetValue_x                                     0x8F7350
#define CSliderWnd__SetNumTicks_x                                  0x8F7AD0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A18B0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F2B00
#define CStmlWnd__CalculateHSBRange_x                              0x8EB000
#define CStmlWnd__CalculateVSBRange_x                              0x8EB090
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EB210
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EBAF0
#define CStmlWnd__ForceParseNow_x                                  0x8F3450
#define CStmlWnd__GetNextTagPiece_x                                0x8EB9F0
#define CStmlWnd__GetSTMLText_x                                    0x695150
#define CStmlWnd__GetVisibleText_x                                 0x8EC540
#define CStmlWnd__InitializeWindowVariables_x                      0x8EE8D0
#define CStmlWnd__MakeStmlColorTag_x                               0x8EA300
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EA360
#define CStmlWnd__SetSTMLText_x                                    0x8F0140
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F27A0
#define CStmlWnd__UpdateHistoryString_x                            0x8ED480

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E9990
#define CTabWnd__DrawCurrentPage_x                                 0x8E9200
#define CTabWnd__DrawTab_x                                         0x8E8FC0
#define CTabWnd__GetCurrentPage_x                                  0x8E95D0
#define CTabWnd__GetPageInnerRect_x                                0x8E8CB0
#define CTabWnd__GetTabInnerRect_x                                 0x8E8EB0
#define CTabWnd__GetTabRect_x                                      0x8E8D80
#define CTabWnd__InsertPage_x                                      0x8E9C80
#define CTabWnd__SetPage_x                                         0x8E9600
#define CTabWnd__SetPageRect_x                                     0x8E98D0
#define CTabWnd__UpdatePage_x                                      0x8E9C20

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432BC0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D1560

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8FD380

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B71C0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59A7E0
#define CXStr__CXStr1_x                                            0x8ABE20
#define CXStr__CXStr3_x                                            0x89A200
#define CXStr__dCXStr_x                                            0x5FBD70
#define CXStr__operator_equal_x                                    0x89A370
#define CXStr__operator_equal1_x                                   0x89A3C0
#define CXStr__operator_plus_equal1_x                              0x89B4E0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C6190
#define CXWnd__Center_x                                            0x8CC300
#define CXWnd__ClrFocus_x                                          0x8C5D60
#define CXWnd__DoAllDrawing_x                                      0x8CBF50
#define CXWnd__DrawChildren_x                                      0x8CC0F0
#define CXWnd__DrawColoredRect_x                                   0x8C6550
#define CXWnd__DrawTooltip_x                                       0x8C6800
#define CXWnd__DrawTooltipAtPoint_x                                0x8CAF00
#define CXWnd__GetBorderFrame_x                                    0x8C6C50
#define CXWnd__GetChildWndAt_x                                     0x8CCCD0
#define CXWnd__GetClientClipRect_x                                 0x8C6A20
#define CXWnd__GetScreenClipRect_x                                 0x8CB600
#define CXWnd__GetScreenRect_x                                     0x8C6E10
#define CXWnd__GetTooltipRect_x                                    0x8C6690
#define CXWnd__GetWindowTextA_x                                    0x424220
#define CXWnd__IsActive_x                                          0x8C1760
#define CXWnd__IsDescendantOf_x                                    0x8C6B90
#define CXWnd__IsReallyVisible_x                                   0x8C9F10
#define CXWnd__IsType_x                                            0x8F9B60
#define CXWnd__Move_x                                              0x8C9600
#define CXWnd__Move1_x                                             0x8CBC10
#define CXWnd__ProcessTransition_x                                 0x8C6140
#define CXWnd__Refade_x                                            0x8C5F10
#define CXWnd__Resize_x                                            0x8C6EE0
#define CXWnd__Right_x                                             0x8CB400
#define CXWnd__SetFocus_x                                          0x8C8740
#define CXWnd__SetFont_x                                           0x8C5DB0
#define CXWnd__SetKeyTooltip_x                                     0x8C7150
#define CXWnd__SetMouseOver_x                                      0x8CB900
#define CXWnd__StartFade_x                                         0x8C61E0
#define CXWnd__GetChildItem_x                                      0x8CB850

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C2FE0
#define CXWndManager__DrawWindows_x                                0x8C2C30
#define CXWndManager__GetKeyboardFlags_x                           0x8C1290
#define CXWndManager__HandleKeyboardMsg_x                          0x8C1BF0
#define CXWndManager__RemoveWnd_x                                  0x8C18F0

// CDBStr
#define CDBStr__GetString_x                                        0x4A8690

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44F680
#define EQ_Character__Cur_HP_x                                     0x464B20
#define EQ_Character__Cur_Mana_x                                   0x457B70
#define EQ_Character__GetAACastingTimeModifier_x                   0x4488C0
#define EQ_Character__GetCharInfo2_x                               0x86EBD0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F9F0
#define EQ_Character__GetFocusRangeModifier_x                      0x43FC40
#define EQ_Character__Max_Endurance_x                              0x5C0300
#define EQ_Character__Max_HP_x                                     0x45A770
#define EQ_Character__Max_Mana_x                                   0x5C0130
#define EQ_Character__doCombatAbility_x                            0x5BD780
#define EQ_Character__UseSkill_x                                   0x470170
#define EQ_Character__GetConLevel_x                                0x5B2410
#define EQ_Character__IsExpansionFlag_x                            0x423760
#define EQ_Character__TotalEffect_x                                0x44C8C0
#define EQ_Character__GetPCSpellAffect_x                           0x448CC0
#define EQ_Character__SpellDuration_x                              0x446BE0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x592AC0
#define EQ_Item__CreateItemTagString_x                             0x84DEF0
#define EQ_Item__IsStackable_x                                     0x842390
#define EQ_Item__GetImageNum_x                                     0x844E00
#define EQ_Item__CreateItemClient_x                                0x593690
#define EQ_Item__GetItemValue_x                                    0x84CC10
#define EQ_Item__ValueSellMerchant_x                               0x84F220

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C8210
#define EQ_LoadingS__Array_x                                       0xC1C738

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C1950
#define EQ_PC__GetAlternateAbilityId_x                             0x857550
#define EQ_PC__GetCombatAbility_x                                  0x8575E0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8523C0
#define EQ_PC__GetItemTimerValue_x                                 0x5BB210
#define EQ_PC__HasLoreItem_x                                       0x5B5900
#define EQ_PC__AlertInventoryChanged_x                             0x5B23E0
#define EQ_PC__GetPcZoneClient_x                                   0x5DBF70
#define EQ_PC__RemoveMyAffect_x                                    0x5BA6C0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x510600
#define EQItemList__add_item_x                                     0x510540
#define EQItemList__delete_item_x                                  0x510A00
#define EQItemList__FreeItemList_x                                 0x510900

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A7980

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C6EF0
#define EQPlayer__dEQPlayer_x                                      0x5CFDD0
#define EQPlayer__DoAttack_x                                       0x5E1EF0
#define EQPlayer__EQPlayer_x                                       0x5D21F0
#define EQPlayer__SetNameSpriteState_x                             0x5CCCA0
#define EQPlayer__SetNameSpriteTint_x                              0x5C8320
#define PlayerBase__HasProperty_j_x                                0x92AB10
#define EQPlayer__IsTargetable_x                                   0x92B410
#define EQPlayer__CanSee_x                                         0x92B930
#define PlayerZoneClient__ChangeHeight_x                           0x5E1DB0
#define EQPlayer__CanSeeTargetIndicator_x                          0x92BA20

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D6580
#define EQPlayerManager__GetSpawnByName_x                          0x5D69E0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D65B0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x598BA0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x598BE0
#define KeypressHandler__ClearCommandStateArray_x                  0x598790
#define KeypressHandler__HandleKeyDown_x                           0x5970F0
#define KeypressHandler__HandleKeyUp_x                             0x597410
#define KeypressHandler__SaveKeymapping_x                          0x598860

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7091A0
#define MapViewMap__SaveEx_x                                       0x70C4B0

#define PlayerPointManager__GetAltCurrency_x                       0x869BB0

// StringTable 
#define StringTable__getString_x                                   0x864580

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BFDB0
#define PcZoneClient__RemovePetEffect_x                            0x5BB700
#define PcZoneClient__HasAlternateAbility_x                        0x5BC1C0

//Doors
#define EQSwitch__UseSwitch_x                                      0x54EAB0

//IconCache
#define IconCache__GetIcon_x                                       0x6A57E0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69C5C0
#define CContainerMgr__CloseContainer_x                            0x69CDE0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76A000

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58BC20

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E0290
#define EQ_Spell__SpellAffects_x                                   0x4DD940
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DD9B0
#define CharacterZoneClient__CalcAffectChange_x                    0x447D00
#define CLootWnd__LootAll_x                                        0x6FE9F0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AF5C0
#define CTargetWnd__WndNotification_x                              0x7AF0B0
#define CTargetWnd__UpdateBuffs_x                                  0x7AF7A0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B47A0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D9230

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x498030

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E53B0
#define CSidlManager__FindAnimation1_x                             0x8DA6B0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CF830
#define CAltAbilityData__GetMercMaxRank_x                          0x4CF7E0
#define CAltAbilityData__GetMaxRank_x                              0x4C47E0

//CTargetRing
#define CTargetRing__Cast_x                                        0x589510

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x456530

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x687040
#define CCastSpellWnd__IsBardSongPlaying_x                         0x686800

//messages
#define msg_spell_worn_off_x                                       0x4E7D30
#define msg_new_text_x                                             0x4F1160
#define msgTokenTextParam_x                                        0x4EDC40
