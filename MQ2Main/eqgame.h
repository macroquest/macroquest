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
#define __ExpectedVersionDate                                     "Jun 21 2016"
#define __ExpectedVersionTime                                     "12:25:04"
#define __ActualVersionDate_x                                      0xACD0B8
#define __ActualVersionTime_x                                      0xACD0C4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59CA30
#define __MemChecker1_x                                            0x895240
#define __MemChecker2_x                                            0x632CD0
#define __MemChecker3_x                                            0x632C20
#define __MemChecker4_x                                            0x7E45F0
#define __EncryptPad0_x                                            0xC6B840
#define __EncryptPad1_x                                            0xDF6140
#define __EncryptPad2_x                                            0xCB4300
#define __EncryptPad3_x                                            0xCB3F00
#define __EncryptPad4_x                                            0xDCCED0
#define __EncryptPad5_x                                            0x11A6900
#define __AC1_x                                                    0x7A4875
#define __AC2_x                                                    0x5568D7
#define __AC3_x                                                    0x554A70
#define __AC4_x                                                    0x567280
#define __AC5_x                                                    0x579DDB
#define __AC6_x                                                    0x57D9AE
#define __AC7_x                                                    0x57449C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1EDE7C

// Direct Input
#define DI8__Main_x                                                0x11A68D8
#define DI8__Keyboard_x                                            0x11A68DC
#define DI8__Mouse_x                                               0x11A68E0
#define DI8__Mouse_Copy_x                                          0x101502C
#define DI8__Mouse_Check_x                                         0x109E7C4
#define __Attack_x                                                 0x1099507
#define __Autofire_x                                               0x1099508
#define __BindList_x                                               0xC2D480
#define g_eqCommandStates_x                                        0x1004490
#define __Clicks_x                                                 0x10150E8
#define __CommandList_x                                            0xC31850
#define __CurrentMapLabel_x                                        0x11AC330
#define __CurrentSocial_x                                          0xBE3FB8
#define __DoAbilityList_x                                          0x104B7BC
#define __do_loot_x                                                0x51B430
#define __DrawHandler_x                                            0x1812D8C
#define __GroupCount_x                                             0x1005A5A

#define __Guilds_x                                                 0x100B670
#define __gWorld_x                                                 0x1007F14
#define __HotkeyPage_x                                             0x10921BC
#define __HWnd_x                                                   0x109E7E0
#define __InChatMode_x                                             0x1015014
#define __LastTell_x                                               0x1016EB8
#define __LMouseHeldTime_x                                         0x1015154
#define __Mouse_x                                                  0x11A68E4
#define __MouseLook_x                                              0x10150AE
#define __MouseEventTime_x                                         0x1099D0C
#define __gpbCommandEvent_x                                        0x1007FDC
#define __NetStatusToggle_x                                        0x10150B1
#define __PCNames_x                                                0x10164D8
#define __RangeAttackReady_x                                       0x1016214
#define __RMouseHeldTime_x                                         0x1015150
#define __RunWalkState_x                                           0x1015018
#define __ScreenMode_x                                             0xF54210
#define __ScreenX_x                                                0x1014FCC
#define __ScreenY_x                                                0x1014FC8
#define __ScreenXMax_x                                             0x1014FD0
#define __ScreenYMax_x                                             0x1014FD4
#define __ServerHost_x                                             0x10059A4
#define __ServerName_x                                             0x104B77C
#define __ShiftKeyDown_x                                           0x10156A0
#define __ShowNames_x                                              0x10163D4
#define __Socials_x                                                0x104B87C
#define __SubscriptionType_x                                       0x11DA3F0
#define __TargetAggroHolder_x                                      0x11AE56C
#define __ZoneType_x                                               0x10154AC
#define __GroupAggro_x                                             0x11AE5AC
#define __LoginName_x                                              0x109D3BC
#define __Inviter_x                                                0x1099484
#define __AttackOnAssist_x                                         0x1016390
#define __UseTellWindows_x                                         0x1016670

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x1008000
#define instEQZoneInfo_x                                           0x10152A4
#define instKeypressHandler_x                                      0x1099CF0
#define pinstActiveBanker_x                                        0x1007FB8
#define pinstActiveCorpse_x                                        0x1007FBC
#define pinstActiveGMaster_x                                       0x1007FC0
#define pinstActiveMerchant_x                                      0x1007FB4
#define pinstAggroInfo_x                                           0xE11D68
#define pinstAltAdvManager_x                                       0xF552D0
#define pinstAuraMgr_x                                             0xE224D8
#define pinstBandageTarget_x                                       0x1007FA0
#define pinstCamActor_x                                            0xF54C24
#define pinstCDBStr_x                                              0xF541A4
#define pinstCDisplay_x                                            0x1007FC8
#define pinstCEverQuest_x                                          0x11A6A58
#define pinstCharData_x                                            0x1007F84
#define pinstCharSpawn_x                                           0x1007FAC
#define pinstControlledMissile_x                                   0x1007F80
#define pinstControlledPlayer_x                                    0x1007FAC
#define pinstCSidlManager_x                                        0x18122CC
#define pinstCXWndManager_x                                        0x18122C4
#define instDynamicZone_x                                          0x1014E60
#define pinstDZMember_x                                            0x1014F70
#define pinstDZTimerInfo_x                                         0x1014F74
#define pinstEQItemList_x                                          0x10046E0
#define pinstEQObjectList_x                                        0x1005454
#define instEQMisc_x                                               0xC07CF8
#define pinstEQSoundManager_x                                      0xF55828
#define instExpeditionLeader_x                                     0x1014EAA
#define instExpeditionName_x                                       0x1014EEA
#define pinstGroup_x                                               0x1005A56
#define pinstImeManager_x                                          0x18122D0
#define pinstLocalPlayer_x                                         0x1007F98
#define pinstMercenaryData_x                                       0x109A340
#define pinstMercenaryStats_x                                      0x11AE6B8
#define pinstMercAltAbilities_x                                    0xF55658
#define pinstModelPlayer_x                                         0x1007FC4
#define pinstPCData_x                                              0x1007F84
#define pinstSkillMgr_x                                            0x109B178
#define pinstSpawnManager_x                                        0x109AA60
#define pinstSpellManager_x                                        0x109B2C0
#define pinstSpellSets_x                                           0x1092220
#define pinstStringTable_x                                         0x1007F2C
#define pinstSwitchManager_x                                       0x10055E8
#define pinstTarget_x                                              0x1007FB0
#define pinstTargetObject_x                                        0x1007F88
#define pinstTargetSwitch_x                                        0x1007F8C
#define pinstTaskMember_x                                          0xF540F0
#define pinstTrackTarget_x                                         0x1007FA4
#define pinstTradeTarget_x                                         0x1007F94
#define instTributeActive_x                                        0xC07D1D
#define pinstViewActor_x                                           0xF54C20
#define pinstWorldData_x                                           0x1007F68
#define pinstZoneAddr_x                                            0x1015544
#define pinstPlayerPath_x                                          0x109AAC0
#define pinstTargetIndicator_x                                     0x109B458
#define pinstCTargetManager_x                                      0x109B4B8

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE12260
#define pinstCAudioTriggersWindow_x                                0xE120F0
#define pinstCCharacterSelect_x                                    0xF54AB4
#define pinstCFacePick_x                                           0xF54864
#define pinstCNoteWnd_x                                            0xF54A6C
#define pinstCBookWnd_x                                            0xF54A74
#define pinstCPetInfoWnd_x                                         0xF54A78
#define pinstCTrainWnd_x                                           0xF54A7C
#define pinstCSkillsWnd_x                                          0xF54A80
#define pinstCSkillsSelectWnd_x                                    0xF54A84
#define pinstCCombatSkillsSelectWnd_x                              0xF54A88
#define pinstCFriendsWnd_x                                         0xF54A8C
#define pinstCAuraWnd_x                                            0xF54A90
#define pinstCRespawnWnd_x                                         0xF54A94
#define pinstCBandolierWnd_x                                       0xF54A98
#define pinstCPotionBeltWnd_x                                      0xF54A9C
#define pinstCAAWnd_x                                              0xF54AA0
#define pinstCGroupSearchFiltersWnd_x                              0xF54AA4
#define pinstCLoadskinWnd_x                                        0xF54AA8
#define pinstCAlarmWnd_x                                           0xF54AAC
#define pinstCMusicPlayerWnd_x                                     0xF54AB0
#define pinstCMailWnd_x                                            0xF54AB8
#define pinstCMailCompositionWnd_x                                 0xF54ABC
#define pinstCMailAddressBookWnd_x                                 0xF54AC0
#define pinstCRaidWnd_x                                            0xF54AC8
#define pinstCRaidOptionsWnd_x                                     0xF54ACC
#define pinstCBreathWnd_x                                          0xF54AD0
#define pinstCMapViewWnd_x                                         0xF54AD4
#define pinstCMapToolbarWnd_x                                      0xF54AD8
#define pinstCEditLabelWnd_x                                       0xF54ADC
#define pinstCTargetWnd_x                                          0xF54AE0
#define pinstCColorPickerWnd_x                                     0xF54AE4
#define pinstCPlayerWnd_x                                          0xF54AE8
#define pinstCOptionsWnd_x                                         0xF54AEC
#define pinstCBuffWindowNORMAL_x                                   0xF54AF0
#define pinstCBuffWindowSHORT_x                                    0xF54AF4
#define pinstCharacterCreation_x                                   0xF54AF8
#define pinstCCursorAttachment_x                                   0xF54AFC
#define pinstCCastingWnd_x                                         0xF54B00
#define pinstCCastSpellWnd_x                                       0xF54B04
#define pinstCSpellBookWnd_x                                       0xF54B08
#define pinstCInventoryWnd_x                                       0xF54B0C
#define pinstCBankWnd_x                                            0xF54B14
#define pinstCQuantityWnd_x                                        0xF54B18
#define pinstCLootWnd_x                                            0xF54B1C
#define pinstCActionsWnd_x                                         0xF54B20
#define pinstCCombatAbilityWnd_x                                   0xF54B24
#define pinstCMerchantWnd_x                                        0xF54B28
#define pinstCTradeWnd_x                                           0xF54B2C
#define pinstCSelectorWnd_x                                        0xF54B30
#define pinstCBazaarWnd_x                                          0xF54B34
#define pinstCBazaarSearchWnd_x                                    0xF54B38
#define pinstCGiveWnd_x                                            0xF54B54
#define pinstCTrackingWnd_x                                        0xF54B5C
#define pinstCInspectWnd_x                                         0xF54B60
#define pinstCSocialEditWnd_x                                      0xF54B64
#define pinstCFeedbackWnd_x                                        0xF54B68
#define pinstCBugReportWnd_x                                       0xF54B6C
#define pinstCVideoModesWnd_x                                      0xF54B70
#define pinstCTextEntryWnd_x                                       0xF54B78
#define pinstCFileSelectionWnd_x                                   0xF54B7C
#define pinstCCompassWnd_x                                         0xF54B80
#define pinstCPlayerNotesWnd_x                                     0xF54B84
#define pinstCGemsGameWnd_x                                        0xF54B88
#define pinstCTimeLeftWnd_x                                        0xF54B8C
#define pinstCPetitionQWnd_x                                       0xF54BA8
#define pinstCSoulmarkWnd_x                                        0xF54BAC
#define pinstCStoryWnd_x                                           0xF54BB0
#define pinstCJournalTextWnd_x                                     0xF54BB4
#define pinstCJournalCatWnd_x                                      0xF54BB8
#define pinstCBodyTintWnd_x                                        0xF54BBC
#define pinstCServerListWnd_x                                      0xF54BC0
#define pinstCAvaZoneWnd_x                                         0xF54BCC
#define pinstCBlockedBuffWnd_x                                     0xF54BD0
#define pinstCBlockedPetBuffWnd_x                                  0xF54BD4
#define pinstCInvSlotMgr_x                                         0xF54C18
#define pinstCContainerMgr_x                                       0xF54C1C
#define pinstCAdventureLeaderboardWnd_x                            0x11A7408
#define pinstCAdventureRequestWnd_x                                0x11A7480
#define pinstCAltStorageWnd_x                                      0x11A7760
#define pinstCAdventureStatsWnd_x                                  0x11A74F8
#define pinstCBarterMerchantWnd_x                                  0x11A8348
#define pinstCBarterSearchWnd_x                                    0x11A83C0
#define pinstCBarterWnd_x                                          0x11A8438
#define pinstCChatManager_x                                        0x11A8AC8
#define pinstCDynamicZoneWnd_x                                     0x11A8F78
#define pinstCEQMainWnd_x                                          0x11A9110
#define pinstCFellowshipWnd_x                                      0x11A8F0C
#define pinstCFindLocationWnd_x                                    0x11A93E0
#define pinstCGroupSearchWnd_x                                     0x11A96B0
#define pinstCGroupWnd_x                                           0x11A9728
#define pinstCGuildBankWnd_x                                       0x11A97A0
#define pinstCGuildMgmtWnd_x                                       0x11AB890
#define pinstCHotButtonWnd_x                                       0x11AB95C
#define pinstCHotButtonWnd1_x                                      0x11AB95C
#define pinstCHotButtonWnd2_x                                      0x11AB960
#define pinstCHotButtonWnd3_x                                      0x11AB964
#define pinstCHotButtonWnd4_x                                      0x11AB988
#define pinstCItemDisplayManager_x                                 0x11ABC80
#define pinstCItemExpTransferWnd_x                                 0x11ABCFC
#define pinstCLFGuildWnd_x                                         0x11ABFD8
#define pinstCMIZoneSelectWnd_x                                    0x11AC5C0
#define pinstCConfirmationDialog_x                                 0x11ACCC8
#define pinstCPopupWndManager_x                                    0x11ACCC8
#define pinstCProgressionSelectionWnd_x                            0x11ACDB8
#define pinstCPvPStatsWnd_x                                        0x11ACEA8
#define pinstCSystemInfoDialogBox_x                                0x11AD5B0
#define pinstCTaskWnd_x                                            0x11AE978
#define pinstCTaskSomething_x                                      0xE22C98
#define pinstCTaskTemplateSelectWnd_x                              0x11AE900
#define pinstCTipWndOFDAY_x                                        0x11AEAE0
#define pinstCTipWndCONTEXT_x                                      0x11AEAE4
#define pinstCTitleWnd_x                                           0x11AEB60
#define pinstCContextMenuManager_x                                 0x181223C
#define pinstCVoiceMacroWnd_x                                      0x109B890
#define pinstCHtmlWnd_x                                            0x109B980
#define pinstIconCache_x                                           0x11A90E4
#define pinstCTradeskillWnd_x                                      0x11AEC60
#define pinstCAdvancedLootWnd_x                                    0xF54C0C
#define pinstRewardSelectionWnd_x                                  0x11AD3D0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x532590
#define __ConvertItemTags_x                                        0x51FF90
#define __ExecuteCmd_x                                             0x50A910
#define __EQGetTime_x                                              0x894E70
#define __get_melee_range_x                                        0x5114D0
#define __GetGaugeValueFromEQ_x                                    0x7A35B0
#define __GetLabelFromEQ_x                                         0x7A4800
#define __ToggleKeyRingItem_x                                      0x47E140
#define __GetXTargetType_x                                         0x925CE0
#define __LoadFrontEnd_x                                           0x6323A0
#define __NewUIINI_x                                               0x7A2F80
#define __ProcessGameEvents_x                                      0x576200
#define __ProcessMouseEvent_x                                      0x5759A0
#define CrashDetected_x                                            0x633D60
#define wwsCrashReportCheckForUploader_x                           0x7F2BD0
#define DrawNetStatus_x                                            0x5AC430
#define Util__FastTime_x                                           0x894980
#define Expansion_HoT_x                                            0x1016380
#define __HelpPath_x                                               0x1099A78
#define __STMLToText_x                                             0x8DAB80

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420470
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B2C0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B0A0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C4F70
#define AltAdvManager__IsAbilityReady_x                            0x4C4FE0
#define AltAdvManager__GetAAById_x                                 0x4C53A0
#define AltAdvManager__CanTrainAbility_x                           0x4C5C60
#define AltAdvManager__CanSeeAbility_x                             0x4C5860

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x462F10
#define CharacterZoneClient__MakeMeVisible_x                       0x468810
#define CharacterZoneClient__IsStackBlocked_x                      0x4472A0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x446760
#define CharacterZoneClient__GetItemCountWorn_x                    0x460930
#define CharacterZoneClient__GetItemCountInInventory_x             0x460A10
#define CharacterZoneClient__GetCursorItemCount_x                  0x460AF0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x661E00

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66FB40

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58B8E0
#define CButtonWnd__CButtonWnd_x                                   0x8CEF00

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68B270
#define CChatManager__InitContextMenu_x                            0x68BDF0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D8EE0
#define CContextMenu__dCContextMenu_x                              0x8D90F0
#define CContextMenu__AddMenuItem_x                                0x8D9100
#define CContextMenu__RemoveMenuItem_x                             0x8D93F0
#define CContextMenu__RemoveAllMenuItems_x                         0x8D9410
#define CContextMenuManager__AddMenu_x                             0x8C5510
#define CContextMenuManager__RemoveMenu_x                          0x8C5860
#define CContextMenuManager__PopupMenu_x                           0x8C5CB0
#define CContextMenuManager__Flush_x                               0x8C5580
#define CContextMenuManager__GetMenu_x                             0x416910

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x879AE0
#define CChatService__GetFriendName_x                              0x879AF0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x691030
#define CChatWindow__Clear_x                                       0x690C10
#define CChatWindow__WndNotification_x                             0x691560

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C9300
#define CComboWnd__Draw_x                                          0x8C9510
#define CComboWnd__GetCurChoice_x                                  0x8C90D0
#define CComboWnd__GetListRect_x                                   0x8C97B0
#define CComboWnd__GetTextRect_x                                   0x8C9370
#define CComboWnd__InsertChoice_x                                  0x8C9820
#define CComboWnd__SetColors_x                                     0x8C9060
#define CComboWnd__SetChoice_x                                     0x8C9090
#define CComboWnd__GetItemCount_x                                  0x8C90C0
#define CComboWnd__GetCurChoiceText_x                              0x8C9110


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69A580
#define CContainerWnd__vftable_x                                   0xAD6A90

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B33E0
#define CDisplay__GetClickedActor_x                                0x4ABCA0
#define CDisplay__GetUserDefinedColor_x                            0x4AA880
#define CDisplay__GetWorldFilePath_x                               0x4A9CD0
#define CDisplay__is3dON_x                                         0x4A9160
#define CDisplay__ReloadUI_x                                       0x4BE8D0
#define CDisplay__WriteTextHD2_x                                   0x4AF730

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8EF530

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DD410
#define CEditWnd__GetCharIndexPt_x                                 0x8DE4A0
#define CEditWnd__GetDisplayString_x                               0x8DD5C0
#define CEditWnd__GetHorzOffset_x                                  0x8DD900
#define CEditWnd__GetLineForPrintableChar_x                        0x8DDF70
#define CEditWnd__GetSelStartPt_x                                  0x8DE750
#define CEditWnd__GetSTMLSafeText_x                                0x8DDAA0
#define CEditWnd__PointFromPrintableChar_x                         0x8DE060
#define CEditWnd__SelectableCharFromPoint_x                        0x8DE1E0
#define CEditWnd__SetEditable_x                                    0x8DDA70

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x557020
#define CEverQuest__CreateTargetIndicator_x                        0x557F10
#define CEverQuest__DeleteTargetIndicator_x                        0x557F90
#define CEverQuest__DoTellWindow_x                                 0x473450
#define CEverQuest__DropHeldItemOnGround_x                         0x56E0C0
#define CEverQuest__dsp_chat_x                                     0x473790
#define CEverQuest__trimName_x                                     0x553970
#define CEverQuest__Emote_x                                        0x56C410
#define CEverQuest__EnterZone_x                                    0x567410
#define CEverQuest__GetBodyTypeDesc_x                              0x5513D0
#define CEverQuest__GetClassDesc_x                                 0x55ACA0
#define CEverQuest__GetClassThreeLetterCode_x                      0x55B2A0
#define CEverQuest__GetDeityDesc_x                                 0x551CB0
#define CEverQuest__GetLangDesc_x                                  0x551760
#define CEverQuest__GetRaceDesc_x                                  0x55B460
#define CEverQuest__InterpretCmd_x                                 0x55F270
#define CEverQuest__LeftClickedOnPlayer_x                          0x5728F0
#define CEverQuest__LMouseUp_x                                     0x5749F0
#define CEverQuest__RightClickedOnPlayer_x                         0x573400
#define CEverQuest__RMouseUp_x                                     0x574450
#define CEverQuest__SetGameState_x                                 0x5578E0
#define CEverQuest__UPCNotificationFlush_x                         0x54F1F0
#define CEverQuest__IssuePetCommand_x                              0x55FC50

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AB1E0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AB240
#define CGaugeWnd__Draw_x                                          0x6AB670

// CGuild
#define CGuild__FindMemberByName_x                                 0x437090

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C75E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D46D0
#define CInvSlotMgr__MoveItem_x                                    0x6D5580
#define CInvSlotMgr__SelectSlot_x                                  0x6D4780

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D3B80
#define CInvSlot__SliderComplete_x                                 0x6D13E0
#define CInvSlot__GetItemBase_x                                    0x6D0840

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D69E0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79EFC0
#define CItemDisplayWnd__UpdateStrings_x                           0x6D8B20

// CLabel 
#define CLabel__Draw_x                                             0x6F21C0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B51A0
#define CListWnd__dCListWnd_x                                      0x8B61D0
#define CListWnd__AddColumn_x                                      0x8B6170
#define CListWnd__AddColumn1_x                                     0x8B59E0
#define CListWnd__AddLine_x                                        0x8B5460
#define CListWnd__AddString_x                                      0x8B5670
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B24F0
#define CListWnd__CalculateVSBRange_x                              0x8B4660
#define CListWnd__ClearSel_x                                       0x8B1800
#define CListWnd__ClearAllSel_x                                    0x8B17B0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B5030
#define CListWnd__Compare_x                                        0x8B2FF0
#define CListWnd__Draw_x                                           0x8B4270
#define CListWnd__DrawColumnSeparators_x                           0x8B4100
#define CListWnd__DrawHeader_x                                     0x8B1AC0
#define CListWnd__DrawItem_x                                       0x8B3630
#define CListWnd__DrawLine_x                                       0x8B3DA0
#define CListWnd__DrawSeparator_x                                  0x8B41A0
#define CListWnd__EnsureVisible_x                                  0x8B2650
#define CListWnd__ExtendSel_x                                      0x8B3540
#define CListWnd__GetColumnMinWidth_x                              0x8B1170
#define CListWnd__GetColumnWidth_x                                 0x8B1090
#define CListWnd__GetCurSel_x                                      0x8B0870
#define CListWnd__GetItemAtPoint_x                                 0x8B28F0
#define CListWnd__GetItemAtPoint1_x                                0x8B2960
#define CListWnd__GetItemData_x                                    0x8B0BB0
#define CListWnd__GetItemHeight_x                                  0x8B2150
#define CListWnd__GetItemIcon_x                                    0x8B0D90
#define CListWnd__GetItemRect_x                                    0x8B2730
#define CListWnd__GetItemText_x                                    0x8B0C40
#define CListWnd__GetSelList_x                                     0x8B58D0
#define CListWnd__GetSeparatorRect_x                               0x8B2F20
#define CListWnd__RemoveLine_x                                     0x8B5850
#define CListWnd__SetColors_x                                      0x8B09C0
#define CListWnd__SetColumnJustification_x                         0x8B1440
#define CListWnd__SetColumnWidth_x                                 0x8B1120
#define CListWnd__SetCurSel_x                                      0x8B08B0
#define CListWnd__SetItemColor_x                                   0x8B4D10
#define CListWnd__SetItemData_x                                    0x8B1860
#define CListWnd__SetItemText_x                                    0x8B4B50
#define CListWnd__ShiftColumnSeparator_x                           0x8B49E0
#define CListWnd__Sort_x                                           0x8B62D0
#define CListWnd__ToggleSel_x                                      0x8B1730

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70B240

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72C610
#define CMerchantWnd__RequestBuyItem_x                             0x733690
#define CMerchantWnd__RequestSellItem_x                            0x734160
#define CMerchantWnd__SelectRecoverySlot_x                         0x72C8C0
#define CMerchantWnd__SelectBuySellSlot_x                          0x72BAC0
#define CMerchantWnd__ActualSelect_x                               0x730560

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x846300
#define CPacketScrambler__hton_x                                   0x846310

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D3EE0
#define CSidlManager__CreateLabel_x                                0x794F60

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x659220
#define CSidlScreenWnd__CalculateVSBRange_x                        0x659150
#define CSidlScreenWnd__ConvertToRes_x                             0x8EF410
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CBCA0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CCE70
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CCF20
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CC3F0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CB650
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CADC0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CB840
#define CSidlScreenWnd__Init1_x                                    0x8CCB40
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CBD50
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CAF80
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CC630
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CAA10
#define CSidlScreenWnd__StoreIniVis_x                              0x8CAD70
#define CSidlScreenWnd__WndNotification_x                          0x8CC8C0
#define CSidlScreenWnd__GetChildItem_x                             0x8CAE90
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BE7B0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F6F70
#define CSkillMgr__GetSkillCap_x                                   0x5F7130
#define CSkillMgr__GetNameToken_x                                  0x5F6B90

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8EE6C0
#define CSliderWnd__SetValue_x                                     0x8EE890
#define CSliderWnd__SetNumTicks_x                                  0x8EF010

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79CC20

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EA070
#define CStmlWnd__CalculateHSBRange_x                              0x8E25C0
#define CStmlWnd__CalculateVSBRange_x                              0x8E2650
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E27D0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E30B0
#define CStmlWnd__ForceParseNow_x                                  0x8EA9C0
#define CStmlWnd__GetNextTagPiece_x                                0x8E2FB0
#define CStmlWnd__GetSTMLText_x                                    0x6904B0
#define CStmlWnd__GetVisibleText_x                                 0x8E3B00
#define CStmlWnd__InitializeWindowVariables_x                      0x8E5E70
#define CStmlWnd__MakeStmlColorTag_x                               0x8E18C0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E1920
#define CStmlWnd__SetSTMLText_x                                    0x8E76C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E9D10
#define CStmlWnd__UpdateHistoryString_x                            0x8E4A30

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E0FD0
#define CTabWnd__DrawCurrentPage_x                                 0x8E0860
#define CTabWnd__DrawTab_x                                         0x8E0620
#define CTabWnd__GetCurrentPage_x                                  0x8E0C10
#define CTabWnd__GetPageInnerRect_x                                0x8E0310
#define CTabWnd__GetTabInnerRect_x                                 0x8E0510
#define CTabWnd__GetTabRect_x                                      0x8E03E0
#define CTabWnd__InsertPage_x                                      0x8E12C0
#define CTabWnd__SetPage_x                                         0x8E0C40
#define CTabWnd__SetPageRect_x                                     0x8E0F10
#define CTabWnd__UpdatePage_x                                      0x8E1260

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432DD0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C8CD0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F4840

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8AEB10

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402A80
#define CXStr__CXStr1_x                                            0x8AFA90
#define CXStr__CXStr3_x                                            0x891AB0
#define CXStr__dCXStr_x                                            0x7D1640
#define CXStr__operator_equal_x                                    0x891C20
#define CXStr__operator_equal1_x                                   0x891C70
#define CXStr__operator_plus_equal1_x                              0x892D70

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BD9B0
#define CXWnd__Center_x                                            0x8C3B10
#define CXWnd__ClrFocus_x                                          0x8BD590
#define CXWnd__DoAllDrawing_x                                      0x8C3770
#define CXWnd__DrawChildren_x                                      0x8C3910
#define CXWnd__DrawColoredRect_x                                   0x8BDD60
#define CXWnd__DrawTooltip_x                                       0x8BE000
#define CXWnd__DrawTooltipAtPoint_x                                0x8C26F0
#define CXWnd__GetBorderFrame_x                                    0x8BE470
#define CXWnd__GetChildWndAt_x                                     0x8C44D0
#define CXWnd__GetClientClipRect_x                                 0x8BE220
#define CXWnd__GetScreenClipRect_x                                 0x8C2DF0
#define CXWnd__GetScreenRect_x                                     0x8BE640
#define CXWnd__GetTooltipRect_x                                    0x8BDE90
#define CXWnd__GetWindowTextA_x                                    0x4244A0
#define CXWnd__IsActive_x                                          0x8B9000
#define CXWnd__IsDescendantOf_x                                    0x8BE3B0
#define CXWnd__IsReallyVisible_x                                   0x8C1730
#define CXWnd__IsType_x                                            0x8F1060
#define CXWnd__Move_x                                              0x8C0E30
#define CXWnd__Move1_x                                             0x8C3430
#define CXWnd__ProcessTransition_x                                 0x8BD960
#define CXWnd__Refade_x                                            0x8BD740
#define CXWnd__Resize_x                                            0x8BE710
#define CXWnd__Right_x                                             0x8C2BF0
#define CXWnd__SetFocus_x                                          0x8BFF80
#define CXWnd__SetFont_x                                           0x8BD5E0
#define CXWnd__SetKeyTooltip_x                                     0x8BE980
#define CXWnd__SetMouseOver_x                                      0x8C3120
#define CXWnd__StartFade_x                                         0x8BDA00
#define CXWnd__GetChildItem_x                                      0x8C3060

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BA890
#define CXWndManager__DrawWindows_x                                0x8BA4D0
#define CXWndManager__GetKeyboardFlags_x                           0x8B8B30
#define CXWndManager__HandleKeyboardMsg_x                          0x8B9490
#define CXWndManager__RemoveWnd_x                                  0x8B9190

// CDBStr
#define CDBStr__GetString_x                                        0x4A7660

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44D740
#define EQ_Character__Cur_HP_x                                     0x462600
#define EQ_Character__Cur_Mana_x                                   0x455D40
#define EQ_Character__GetAACastingTimeModifier_x                   0x446A70
#define EQ_Character__GetCharInfo2_x                               0x865DD0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EDB0
#define EQ_Character__GetFocusRangeModifier_x                      0x43EE10
#define EQ_Character__Max_Endurance_x                              0x5BEB50
#define EQ_Character__Max_HP_x                                     0x458960
#define EQ_Character__Max_Mana_x                                   0x5BE980
#define EQ_Character__doCombatAbility_x                            0x5BC0B0
#define EQ_Character__UseSkill_x                                   0x46D890
#define EQ_Character__GetConLevel_x                                0x5B0AA0
#define EQ_Character__IsExpansionFlag_x                            0x4239E0
#define EQ_Character__TotalEffect_x                                0x44A990
#define EQ_Character__GetPCSpellAffect_x                           0x446E70
#define EQ_Character__SpellDuration_x                              0x444D70

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5911C0
#define EQ_Item__CreateItemTagString_x                             0x844CE0
#define EQ_Item__IsStackable_x                                     0x83A6F0
#define EQ_Item__GetImageNum_x                                     0x83D140
#define EQ_Item__CreateItemClient_x                                0x591DA0
#define EQ_Item__GetItemValue_x                                    0x8439B0
#define EQ_Item__ValueSellMerchant_x                               0x845F90

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C70A0
#define EQ_LoadingS__Array_x                                       0xC14530

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C01C0
#define EQ_PC__GetAlternateAbilityId_x                             0x84E300
#define EQ_PC__GetCombatAbility_x                                  0x84E390
#define EQ_PC__GetCombatAbilityTimer_x                             0x849110
#define EQ_PC__GetItemTimerValue_x                                 0x5B9BD0
#define EQ_PC__HasLoreItem_x                                       0x5B3F70
#define EQ_PC__AlertInventoryChanged_x                             0x5B0A70
#define EQ_PC__GetPcZoneClient_x                                   0x5DA7D0
#define EQ_PC__RemoveMyAffect_x                                    0x5B9080

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50F570
#define EQItemList__add_object_x                                   0x53BCD0
#define EQItemList__add_item_x                                     0x50F4B0
#define EQItemList__delete_item_x                                  0x50F960
#define EQItemList__FreeItemList_x                                 0x50F860

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A6860

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C5770
#define EQPlayer__dEQPlayer_x                                      0x5CE5B0
#define EQPlayer__DoAttack_x                                       0x5E04F0
#define EQPlayer__EQPlayer_x                                       0x5D09D0
#define EQPlayer__SetNameSpriteState_x                             0x5CB530
#define EQPlayer__SetNameSpriteTint_x                              0x5C6BB0
#define PlayerBase__HasProperty_j_x                                0x921EE0
#define EQPlayer__IsTargetable_x                                   0x9227E0
#define EQPlayer__CanSee_x                                         0x922D00
#define PlayerZoneClient__ChangeHeight_x                           0x5E03B0
#define EQPlayer__CanSeeTargetIndicator_x                          0x922DF0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D4D20
#define EQPlayerManager__GetSpawnByName_x                          0x5D5180
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D4D50

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x597290
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5972D0
#define KeypressHandler__ClearCommandStateArray_x                  0x596E80
#define KeypressHandler__HandleKeyDown_x                           0x5957E0
#define KeypressHandler__HandleKeyUp_x                             0x595B00
#define KeypressHandler__SaveKeymapping_x                          0x596F50

// MapViewMap 
#define MapViewMap__Clear_x                                        0x703BD0
#define MapViewMap__SaveEx_x                                       0x706F00

#define PlayerPointManager__GetAltCurrency_x                       0x860DD0

// StringTable 
#define StringTable__getString_x                                   0x85B670

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BE620
#define PcZoneClient__RemovePetEffect_x                            0x5BA0A0
#define PcZoneClient__HasAlternateAbility_x                        0x5BAB50
#define PcZoneClient__GetCurrentMod_x                              0x457D00
#define PcZoneClient__GetModCap_x                                  0x455550

//Doors
#define EQSwitch__UseSwitch_x                                      0x54DB10

//IconCache
#define IconCache__GetIcon_x                                       0x6A0B30

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x697900
#define CContainerMgr__CloseContainer_x                            0x698120

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x765080

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58A380

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DEEA0
#define EQ_Spell__SpellAffects_x                                   0x4DC550
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DC5C0
#define CharacterZoneClient__CalcAffectChange_x                    0x445EA0
#define CLootWnd__LootAll_x                                        0x6F9550

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7ABA00
#define CTargetWnd__WndNotification_x                              0x7AB4F0
#define CTargetWnd__UpdateBuffs_x                                  0x7ABBE0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B0BD0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D7D90

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4967D0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DCA40
#define CSidlManager__FindAnimation1_x                             0x8D1DE0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CE670
#define CAltAbilityData__GetMercMaxRank_x                          0x4CE620
#define CAltAbilityData__GetMaxRank_x                              0x4C3620

//CTargetRing
#define CTargetRing__Cast_x                                        0x587C40

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x454600

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x682290
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6819F0

//messages
#define msg_spell_worn_off_x                                       0x4E6870
#define msg_new_text_x                                             0x4EFBD0
#define msgTokenTextParam_x                                        0x4EC6D0

//SpellManager
#define SpellManager__vftable_x                                    0xAB2DD8
#define SpellManager__SpellManager_x                               0x47AFD0
