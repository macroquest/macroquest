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
#define __ExpectedVersionDate                                     "Jul  1 2016"
#define __ExpectedVersionTime                                     "11:07:13"
#define __ActualVersionDate_x                                      0xAD0240
#define __ActualVersionTime_x                                      0xAD024C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59E680
#define __MemChecker1_x                                            0x898710
#define __MemChecker2_x                                            0x6353D0
#define __MemChecker3_x                                            0x635320
#define __MemChecker4_x                                            0x7E7780
#define __EncryptPad0_x                                            0xC6E8E8
#define __EncryptPad1_x                                            0xDF9440
#define __EncryptPad2_x                                            0xCB73E8
#define __EncryptPad3_x                                            0xCB6FE8
#define __EncryptPad4_x                                            0xDD0010
#define __EncryptPad5_x                                            0x11A9D30
#define __AC1_x                                                    0x7A76C5
#define __AC2_x                                                    0x5585C7
#define __AC3_x                                                    0x556760
#define __AC4_x                                                    0x568F70
#define __AC5_x                                                    0x57BABB
#define __AC6_x                                                    0x57F68E
#define __AC7_x                                                    0x57617C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E767C

// Direct Input
#define DI8__Main_x                                                0x11A9D08
#define DI8__Keyboard_x                                            0x11A9D0C
#define DI8__Mouse_x                                               0x11A9D10
#define DI8__Mouse_Copy_x                                          0x10183FC
#define DI8__Mouse_Check_x                                         0x10A1BF4
#define __Attack_x                                                 0x109C8D7
#define __Autofire_x                                               0x109C8D8
#define __BindList_x                                               0xC304E8
#define g_eqCommandStates_x                                        0x1007860
#define __Clicks_x                                                 0x10184B8
#define __CommandList_x                                            0xC348B8
#define __CurrentMapLabel_x                                        0x11AF790
#define __CurrentSocial_x                                          0xBE6FD0
#define __DoAbilityList_x                                          0x104EB8C
#define __do_loot_x                                                0x51D160
#define __DrawHandler_x                                            0x1816714
#define __GroupCount_x                                             0x1008E2A

#define __Guilds_x                                                 0x100EA40
#define __gWorld_x                                                 0x100B2E4
#define __HotkeyPage_x                                             0x109558C
#define __HWnd_x                                                   0x10A1C10
#define __InChatMode_x                                             0x10183E4
#define __LastTell_x                                               0x101A288
#define __LMouseHeldTime_x                                         0x1018524
#define __Mouse_x                                                  0x11A9D14
#define __MouseLook_x                                              0x101847E
#define __MouseEventTime_x                                         0x109D0DC
#define __gpbCommandEvent_x                                        0x100B3AC
#define __NetStatusToggle_x                                        0x1018481
#define __PCNames_x                                                0x10198A8
#define __RangeAttackReady_x                                       0x10195E4
#define __RMouseHeldTime_x                                         0x1018520
#define __RunWalkState_x                                           0x10183E8
#define __ScreenMode_x                                             0xF575E0
#define __ScreenX_x                                                0x101839C
#define __ScreenY_x                                                0x1018398
#define __ScreenXMax_x                                             0x10183A0
#define __ScreenYMax_x                                             0x10183A4
#define __ServerHost_x                                             0x1008D74
#define __ServerName_x                                             0x104EB4C
#define __ShiftKeyDown_x                                           0x1018A70
#define __ShowNames_x                                              0x10197A4
#define __Socials_x                                                0x104EC4C
#define __SubscriptionType_x                                       0x11DD8BC
#define __TargetAggroHolder_x                                      0x11B19CC
#define __ZoneType_x                                               0x101887C
#define __GroupAggro_x                                             0x11B1A0C
#define __LoginName_x                                              0x10A07EC
#define __Inviter_x                                                0x109C854
#define __AttackOnAssist_x                                         0x1019760
#define __UseTellWindows_x                                         0x1019A40

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x100B3D0
#define instEQZoneInfo_x                                           0x1018674
#define instKeypressHandler_x                                      0x109D0C0
#define pinstActiveBanker_x                                        0x100B388
#define pinstActiveCorpse_x                                        0x100B38C
#define pinstActiveGMaster_x                                       0x100B390
#define pinstActiveMerchant_x                                      0x100B384
#define pinstAggroInfo_x                                           0xE15108
#define pinstAltAdvManager_x                                       0xF586A0
#define pinstAuraMgr_x                                             0xE25878
#define pinstBandageTarget_x                                       0x100B370
#define pinstCamActor_x                                            0xF57FF4
#define pinstCDBStr_x                                              0xF57574
#define pinstCDisplay_x                                            0x100B398
#define pinstCEverQuest_x                                          0x11A9E88
#define pinstCharData_x                                            0x100B354
#define pinstCharSpawn_x                                           0x100B37C
#define pinstControlledMissile_x                                   0x100B350
#define pinstControlledPlayer_x                                    0x100B37C
#define pinstCSidlManager_x                                        0x1815B04
#define pinstCXWndManager_x                                        0x1815AFC
#define instDynamicZone_x                                          0x1018230
#define pinstDZMember_x                                            0x1018340
#define pinstDZTimerInfo_x                                         0x1018344
#define pinstEQItemList_x                                          0x1007AB0
#define pinstEQObjectList_x                                        0x1008824
#define instEQMisc_x                                               0xC0AD40
#define pinstEQSoundManager_x                                      0xF58BF8
#define instExpeditionLeader_x                                     0x101827A
#define instExpeditionName_x                                       0x10182BA
#define pinstGroup_x                                               0x1008E26
#define pinstImeManager_x                                          0x1815B08
#define pinstLocalPlayer_x                                         0x100B368
#define pinstMercenaryData_x                                       0x109D740
#define pinstMercenaryStats_x                                      0x11B1B18
#define pinstMercAltAbilities_x                                    0xF58A28
#define pinstModelPlayer_x                                         0x100B394
#define pinstPCData_x                                              0x100B354
#define pinstSkillMgr_x                                            0x109E5A8
#define pinstSpawnManager_x                                        0x109DE90
#define pinstSpellManager_x                                        0x109E6F0
#define pinstSpellSets_x                                           0x10955F0
#define pinstStringTable_x                                         0x100B2FC
#define pinstSwitchManager_x                                       0x10089B8
#define pinstTarget_x                                              0x100B380
#define pinstTargetObject_x                                        0x100B358
#define pinstTargetSwitch_x                                        0x100B35C
#define pinstTaskMember_x                                          0xF574C0
#define pinstTrackTarget_x                                         0x100B374
#define pinstTradeTarget_x                                         0x100B364
#define instTributeActive_x                                        0xC0AD65
#define pinstViewActor_x                                           0xF57FF0
#define pinstWorldData_x                                           0x100B338
#define pinstZoneAddr_x                                            0x1018914
#define pinstPlayerPath_x                                          0x109DEF0
#define pinstTargetIndicator_x                                     0x109E888
#define pinstCTargetManager_x                                      0x109E8E8

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE15600
#define pinstCAudioTriggersWindow_x                                0xE15490
#define pinstCCharacterSelect_x                                    0xF57E84
#define pinstCFacePick_x                                           0xF57C34
#define pinstCNoteWnd_x                                            0xF57E3C
#define pinstCBookWnd_x                                            0xF57E44
#define pinstCPetInfoWnd_x                                         0xF57E48
#define pinstCTrainWnd_x                                           0xF57E4C
#define pinstCSkillsWnd_x                                          0xF57E50
#define pinstCSkillsSelectWnd_x                                    0xF57E54
#define pinstCCombatSkillsSelectWnd_x                              0xF57E58
#define pinstCFriendsWnd_x                                         0xF57E5C
#define pinstCAuraWnd_x                                            0xF57E60
#define pinstCRespawnWnd_x                                         0xF57E64
#define pinstCBandolierWnd_x                                       0xF57E68
#define pinstCPotionBeltWnd_x                                      0xF57E6C
#define pinstCAAWnd_x                                              0xF57E70
#define pinstCGroupSearchFiltersWnd_x                              0xF57E74
#define pinstCLoadskinWnd_x                                        0xF57E78
#define pinstCAlarmWnd_x                                           0xF57E7C
#define pinstCMusicPlayerWnd_x                                     0xF57E80
#define pinstCMailWnd_x                                            0xF57E88
#define pinstCMailCompositionWnd_x                                 0xF57E8C
#define pinstCMailAddressBookWnd_x                                 0xF57E90
#define pinstCRaidWnd_x                                            0xF57E98
#define pinstCRaidOptionsWnd_x                                     0xF57E9C
#define pinstCBreathWnd_x                                          0xF57EA0
#define pinstCMapViewWnd_x                                         0xF57EA4
#define pinstCMapToolbarWnd_x                                      0xF57EA8
#define pinstCEditLabelWnd_x                                       0xF57EAC
#define pinstCTargetWnd_x                                          0xF57EB0
#define pinstCColorPickerWnd_x                                     0xF57EB4
#define pinstCPlayerWnd_x                                          0xF57EB8
#define pinstCOptionsWnd_x                                         0xF57EBC
#define pinstCBuffWindowNORMAL_x                                   0xF57EC0
#define pinstCBuffWindowSHORT_x                                    0xF57EC4
#define pinstCharacterCreation_x                                   0xF57EC8
#define pinstCCursorAttachment_x                                   0xF57ECC
#define pinstCCastingWnd_x                                         0xF57ED0
#define pinstCCastSpellWnd_x                                       0xF57ED4
#define pinstCSpellBookWnd_x                                       0xF57ED8
#define pinstCInventoryWnd_x                                       0xF57EDC
#define pinstCBankWnd_x                                            0xF57EE4
#define pinstCQuantityWnd_x                                        0xF57EE8
#define pinstCLootWnd_x                                            0xF57EEC
#define pinstCActionsWnd_x                                         0xF57EF0
#define pinstCCombatAbilityWnd_x                                   0xF57EF4
#define pinstCMerchantWnd_x                                        0xF57EF8
#define pinstCTradeWnd_x                                           0xF57EFC
#define pinstCSelectorWnd_x                                        0xF57F00
#define pinstCBazaarWnd_x                                          0xF57F04
#define pinstCBazaarSearchWnd_x                                    0xF57F08
#define pinstCGiveWnd_x                                            0xF57F24
#define pinstCTrackingWnd_x                                        0xF57F2C
#define pinstCInspectWnd_x                                         0xF57F30
#define pinstCSocialEditWnd_x                                      0xF57F34
#define pinstCFeedbackWnd_x                                        0xF57F38
#define pinstCBugReportWnd_x                                       0xF57F3C
#define pinstCVideoModesWnd_x                                      0xF57F40
#define pinstCTextEntryWnd_x                                       0xF57F48
#define pinstCFileSelectionWnd_x                                   0xF57F4C
#define pinstCCompassWnd_x                                         0xF57F50
#define pinstCPlayerNotesWnd_x                                     0xF57F54
#define pinstCGemsGameWnd_x                                        0xF57F58
#define pinstCTimeLeftWnd_x                                        0xF57F5C
#define pinstCPetitionQWnd_x                                       0xF57F78
#define pinstCSoulmarkWnd_x                                        0xF57F7C
#define pinstCStoryWnd_x                                           0xF57F80
#define pinstCJournalTextWnd_x                                     0xF57F84
#define pinstCJournalCatWnd_x                                      0xF57F88
#define pinstCBodyTintWnd_x                                        0xF57F8C
#define pinstCServerListWnd_x                                      0xF57F90
#define pinstCAvaZoneWnd_x                                         0xF57F9C
#define pinstCBlockedBuffWnd_x                                     0xF57FA0
#define pinstCBlockedPetBuffWnd_x                                  0xF57FA4
#define pinstCInvSlotMgr_x                                         0xF57FE8
#define pinstCContainerMgr_x                                       0xF57FEC
#define pinstCAdventureLeaderboardWnd_x                            0x11AA838
#define pinstCAdventureRequestWnd_x                                0x11AA8B0
#define pinstCAltStorageWnd_x                                      0x11AAB90
#define pinstCAdventureStatsWnd_x                                  0x11AA928
#define pinstCBarterMerchantWnd_x                                  0x11AB778
#define pinstCBarterSearchWnd_x                                    0x11AB7F0
#define pinstCBarterWnd_x                                          0x11AB868
#define pinstCChatManager_x                                        0x11ABEF8
#define pinstCDynamicZoneWnd_x                                     0x11AC3A8
#define pinstCEQMainWnd_x                                          0x11AC540
#define pinstCFellowshipWnd_x                                      0x11AC33C
#define pinstCFindLocationWnd_x                                    0x11AC810
#define pinstCGroupSearchWnd_x                                     0x11ACAE0
#define pinstCGroupWnd_x                                           0x11ACB58
#define pinstCGuildBankWnd_x                                       0x11ACBD0
#define pinstCGuildMgmtWnd_x                                       0x11AECC0
#define pinstCHotButtonWnd_x                                       0x11AEDBC
#define pinstCHotButtonWnd1_x                                      0x11AEDBC
#define pinstCHotButtonWnd2_x                                      0x11AEDC0
#define pinstCHotButtonWnd3_x                                      0x11AEDC4
#define pinstCHotButtonWnd4_x                                      0x11AEDE8
#define pinstCItemDisplayManager_x                                 0x11AF0E0
#define pinstCItemExpTransferWnd_x                                 0x11AF15C
#define pinstCLFGuildWnd_x                                         0x11AF438
#define pinstCMIZoneSelectWnd_x                                    0x11AFA20
#define pinstCConfirmationDialog_x                                 0x11B0128
#define pinstCPopupWndManager_x                                    0x11B0128
#define pinstCProgressionSelectionWnd_x                            0x11B0218
#define pinstCPvPStatsWnd_x                                        0x11B0308
#define pinstCSystemInfoDialogBox_x                                0x11B0A10
#define pinstCTaskWnd_x                                            0x11B1DD8
#define pinstCTaskSomething_x                                      0xE26068
#define pinstCTaskTemplateSelectWnd_x                              0x11B1D60
#define pinstCTipWndOFDAY_x                                        0x11B1F40
#define pinstCTipWndCONTEXT_x                                      0x11B1F44
#define pinstCTitleWnd_x                                           0x11B1FC0
#define pinstCContextMenuManager_x                                 0x1815A74
#define pinstCVoiceMacroWnd_x                                      0x109ECC0
#define pinstCHtmlWnd_x                                            0x109EDB0
#define pinstIconCache_x                                           0x11AC514
#define pinstCTradeskillWnd_x                                      0x11B20C0
#define pinstCAdvancedLootWnd_x                                    0xF57FDC
#define pinstRewardSelectionWnd_x                                  0x11B0830

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5342C0
#define __ConvertItemTags_x                                        0x521CC0
#define __ExecuteCmd_x                                             0x50C650
#define __EQGetTime_x                                              0x898340
#define __get_melee_range_x                                        0x513240
#define __GetGaugeValueFromEQ_x                                    0x7A6400
#define __GetLabelFromEQ_x                                         0x7A7650
#define __ToggleKeyRingItem_x                                      0x47E870
#define __GetXTargetType_x                                         0x929420
#define __LoadFrontEnd_x                                           0x634AA0
#define __NewUIINI_x                                               0x7A5DD0
#define __ProcessGameEvents_x                                      0x577EE0
#define __ProcessMouseEvent_x                                      0x577680
#define CrashDetected_x                                            0x636460
#define wwsCrashReportCheckForUploader_x                           0x7F6100
#define DrawNetStatus_x                                            0x5AE300
#define Util__FastTime_x                                           0x897E50
#define Expansion_HoT_x                                            0x1019750
#define __HelpPath_x                                               0x109CE48
#define __STMLToText_x                                             0x8DE130

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420570
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B3C0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B1A0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C5730
#define AltAdvManager__IsAbilityReady_x                            0x4C57A0
#define AltAdvManager__GetAAById_x                                 0x4C5B60
#define AltAdvManager__CanTrainAbility_x                           0x4C6420
#define AltAdvManager__CanSeeAbility_x                             0x4C6020

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463210
#define CharacterZoneClient__MakeMeVisible_x                       0x468B10
#define CharacterZoneClient__IsStackBlocked_x                      0x4474C0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x446980
#define CharacterZoneClient__GetItemCountWorn_x                    0x460BE0
#define CharacterZoneClient__GetItemCountInInventory_x             0x460CC0
#define CharacterZoneClient__GetCursorItemCount_x                  0x460DA0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6647D0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x672E60

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58D550
#define CButtonWnd__CButtonWnd_x                                   0x8D23E0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68DCB0
#define CChatManager__InitContextMenu_x                            0x68E830

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DC480
#define CContextMenu__dCContextMenu_x                              0x8DC690
#define CContextMenu__AddMenuItem_x                                0x8DC6A0
#define CContextMenu__RemoveMenuItem_x                             0x8DC990
#define CContextMenu__RemoveAllMenuItems_x                         0x8DC9B0
#define CContextMenuManager__AddMenu_x                             0x8C8950
#define CContextMenuManager__RemoveMenu_x                          0x8C8CB0
#define CContextMenuManager__PopupMenu_x                           0x8C9100
#define CContextMenuManager__Flush_x                               0x8C89C0
#define CContextMenuManager__GetMenu_x                             0x4169F0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87CD10
#define CChatService__GetFriendName_x                              0x87CD20

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x693A90
#define CChatWindow__Clear_x                                       0x693660
#define CChatWindow__WndNotification_x                             0x693FD0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CC770
#define CComboWnd__Draw_x                                          0x8CC980
#define CComboWnd__GetCurChoice_x                                  0x8CC530
#define CComboWnd__GetListRect_x                                   0x8CCC20
#define CComboWnd__GetTextRect_x                                   0x8CC7E0
#define CComboWnd__InsertChoice_x                                  0x8CCC90
#define CComboWnd__SetColors_x                                     0x8CC4C0
#define CComboWnd__SetChoice_x                                     0x8CC4F0
#define CComboWnd__GetItemCount_x                                  0x8CC520
#define CComboWnd__GetCurChoiceText_x                              0x8CC570

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69CFF0
#define CContainerWnd__vftable_x                                   0xAD9C38

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B3C00
#define CDisplay__GetClickedActor_x                                0x4AC4C0
#define CDisplay__GetUserDefinedColor_x                            0x4AB0A0
#define CDisplay__GetWorldFilePath_x                               0x4AA4F0
#define CDisplay__is3dON_x                                         0x4A9980
#define CDisplay__ReloadUI_x                                       0x4BF0F0
#define CDisplay__WriteTextHD2_x                                   0x4AFF50

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F2B50

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E09C0
#define CEditWnd__GetCharIndexPt_x                                 0x8E1A60
#define CEditWnd__GetDisplayString_x                               0x8E0B70
#define CEditWnd__GetHorzOffset_x                                  0x8E0EB0
#define CEditWnd__GetLineForPrintableChar_x                        0x8E1520
#define CEditWnd__GetSelStartPt_x                                  0x8E1D20
#define CEditWnd__GetSTMLSafeText_x                                0x8E1050
#define CEditWnd__PointFromPrintableChar_x                         0x8E1610
#define CEditWnd__SelectableCharFromPoint_x                        0x8E1790
#define CEditWnd__SetEditable_x                                    0x8E1020

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x558D10
#define CEverQuest__CreateTargetIndicator_x                        0x559C00
#define CEverQuest__DeleteTargetIndicator_x                        0x559C80
#define CEverQuest__DoTellWindow_x                                 0x473780
#define CEverQuest__DropHeldItemOnGround_x                         0x56FDB0
#define CEverQuest__dsp_chat_x                                     0x473AC0
#define CEverQuest__trimName_x                                     0x555660
#define CEverQuest__Emote_x                                        0x56E100
#define CEverQuest__EnterZone_x                                    0x569100
#define CEverQuest__GetBodyTypeDesc_x                              0x5530C0
#define CEverQuest__GetClassDesc_x                                 0x55C990
#define CEverQuest__GetClassThreeLetterCode_x                      0x55CF90
#define CEverQuest__GetDeityDesc_x                                 0x5539A0
#define CEverQuest__GetLangDesc_x                                  0x553450
#define CEverQuest__GetRaceDesc_x                                  0x55D150
#define CEverQuest__InterpretCmd_x                                 0x560F60
#define CEverQuest__LeftClickedOnPlayer_x                          0x5745D0
#define CEverQuest__LMouseUp_x                                     0x5766D0
#define CEverQuest__RightClickedOnPlayer_x                         0x5750E0
#define CEverQuest__RMouseUp_x                                     0x576130
#define CEverQuest__SetGameState_x                                 0x5595D0
#define CEverQuest__UPCNotificationFlush_x                         0x550EE0
#define CEverQuest__IssuePetCommand_x                              0x561940

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6ADCA0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6ADD00
#define CGaugeWnd__Draw_x                                          0x6AE130

// CGuild
#define CGuild__FindMemberByName_x                                 0x4372A0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CA140

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D7200
#define CInvSlotMgr__MoveItem_x                                    0x6D80B0
#define CInvSlotMgr__SelectSlot_x                                  0x6D72B0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D66B0
#define CInvSlot__SliderComplete_x                                 0x6D3F10
#define CInvSlot__GetItemBase_x                                    0x6D33B0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D94D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A1DF0
#define CItemDisplayWnd__UpdateStrings_x                           0x6DB630

// CLabel 
#define CLabel__Draw_x                                             0x6F4CA0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B84F0
#define CListWnd__dCListWnd_x                                      0x8B9530
#define CListWnd__AddColumn_x                                      0x8B94D0
#define CListWnd__AddColumn1_x                                     0x8B8D40
#define CListWnd__AddLine_x                                        0x8B87B0
#define CListWnd__AddString_x                                      0x8B89D0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B57A0
#define CListWnd__CalculateVSBRange_x                              0x8B79B0
#define CListWnd__ClearSel_x                                       0x8B4AB0
#define CListWnd__ClearAllSel_x                                    0x8B4A60
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B8380
#define CListWnd__Compare_x                                        0x8B6320
#define CListWnd__Draw_x                                           0x8B75B0
#define CListWnd__DrawColumnSeparators_x                           0x8B7440
#define CListWnd__DrawHeader_x                                     0x8B4D70
#define CListWnd__DrawItem_x                                       0x8B6970
#define CListWnd__DrawLine_x                                       0x8B70E0
#define CListWnd__DrawSeparator_x                                  0x8B74E0
#define CListWnd__EnsureVisible_x                                  0x8B5900
#define CListWnd__ExtendSel_x                                      0x8B6880
#define CListWnd__GetColumnMinWidth_x                              0x8B4460
#define CListWnd__GetColumnWidth_x                                 0x8B4390
#define CListWnd__GetCurSel_x                                      0x8B3B50
#define CListWnd__GetItemAtPoint_x                                 0x8B5BA0
#define CListWnd__GetItemAtPoint1_x                                0x8B5C10
#define CListWnd__GetItemData_x                                    0x8B3EA0
#define CListWnd__GetItemHeight_x                                  0x8B53F0
#define CListWnd__GetItemIcon_x                                    0x8B4090
#define CListWnd__GetItemRect_x                                    0x8B59E0
#define CListWnd__GetItemText_x                                    0x8B3F40
#define CListWnd__GetSelList_x                                     0x8B8C30
#define CListWnd__GetSeparatorRect_x                               0x8B6240
#define CListWnd__RemoveLine_x                                     0x8B8BB0
#define CListWnd__SetColors_x                                      0x8B3CA0
#define CListWnd__SetColumnJustification_x                         0x8B46F0
#define CListWnd__SetColumnWidth_x                                 0x8B4410
#define CListWnd__SetCurSel_x                                      0x8B3B90
#define CListWnd__SetItemColor_x                                   0x8B8070
#define CListWnd__SetItemData_x                                    0x8B4B10
#define CListWnd__SetItemText_x                                    0x8B7EB0
#define CListWnd__ShiftColumnSeparator_x                           0x8B7D40
#define CListWnd__Sort_x                                           0x8B9630
#define CListWnd__ToggleSel_x                                      0x8B49E0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70DD50

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72F2B0
#define CMerchantWnd__RequestBuyItem_x                             0x736370
#define CMerchantWnd__RequestSellItem_x                            0x736E40
#define CMerchantWnd__SelectRecoverySlot_x                         0x72F560
#define CMerchantWnd__SelectBuySellSlot_x                          0x72E760
#define CMerchantWnd__ActualSelect_x                               0x733240

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x849910
#define CPacketScrambler__hton_x                                   0x849920

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D7400
#define CSidlManager__CreateLabel_x                                0x797D30

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65BBB0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65BAD0
#define CSidlScreenWnd__ConvertToRes_x                             0x8F2A30
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CF130
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D0300
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D03B0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CF880
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CEAE0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CE230
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CECD0
#define CSidlScreenWnd__Init1_x                                    0x8CFFD0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CF1E0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CE3F0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CFAC0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CDE90
#define CSidlScreenWnd__StoreIniVis_x                              0x8CE1E0
#define CSidlScreenWnd__WndNotification_x                          0x8CFD50
#define CSidlScreenWnd__GetChildItem_x                             0x8CE300
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C1AE0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F9710
#define CSkillMgr__GetSkillCap_x                                   0x5F98F0
#define CSkillMgr__GetNameToken_x                                  0x5F9330

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F1CE0
#define CSliderWnd__SetValue_x                                     0x8F1EB0
#define CSliderWnd__SetNumTicks_x                                  0x8F2630

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79FA50

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8ED680
#define CStmlWnd__CalculateHSBRange_x                              0x8E5BA0
#define CStmlWnd__CalculateVSBRange_x                              0x8E5C30
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E5DB0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E6690
#define CStmlWnd__ForceParseNow_x                                  0x8EDFD0
#define CStmlWnd__GetNextTagPiece_x                                0x8E6590
#define CStmlWnd__GetSTMLText_x                                    0x692F00
#define CStmlWnd__GetVisibleText_x                                 0x8E70E0
#define CStmlWnd__InitializeWindowVariables_x                      0x8E9470
#define CStmlWnd__MakeStmlColorTag_x                               0x8E4EA0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E4F00
#define CStmlWnd__SetSTMLText_x                                    0x8EACD0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8ED320
#define CStmlWnd__UpdateHistoryString_x                            0x8E8020

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E45B0
#define CTabWnd__DrawCurrentPage_x                                 0x8E3E40
#define CTabWnd__DrawTab_x                                         0x8E3C00
#define CTabWnd__GetCurrentPage_x                                  0x8E41F0
#define CTabWnd__GetPageInnerRect_x                                0x8E38F0
#define CTabWnd__GetTabInnerRect_x                                 0x8E3AF0
#define CTabWnd__GetTabRect_x                                      0x8E39C0
#define CTabWnd__InsertPage_x                                      0x8E48A0
#define CTabWnd__SetPage_x                                         0x8E4220
#define CTabWnd__SetPageRect_x                                     0x8E44F0
#define CTabWnd__UpdatePage_x                                      0x8E4840

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432EC0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CC130

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F7E40

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B1DB0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402A10
#define CXStr__CXStr1_x                                            0x7D4500
#define CXStr__CXStr3_x                                            0x894F80
#define CXStr__dCXStr_x                                            0x8C05C0
#define CXStr__operator_equal_x                                    0x8950F0
#define CXStr__operator_equal1_x                                   0x895140
#define CXStr__operator_plus_equal1_x                              0x896240

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C0CC0
#define CXWnd__Center_x                                            0x8C6F40
#define CXWnd__ClrFocus_x                                          0x8C08B0
#define CXWnd__DoAllDrawing_x                                      0x8C6B90
#define CXWnd__DrawChildren_x                                      0x8C6D30
#define CXWnd__DrawColoredRect_x                                   0x8C1080
#define CXWnd__DrawTooltip_x                                       0x8C1330
#define CXWnd__DrawTooltipAtPoint_x                                0x8C5AF0
#define CXWnd__GetBorderFrame_x                                    0x8C17A0
#define CXWnd__GetChildWndAt_x                                     0x8C7910
#define CXWnd__GetClientClipRect_x                                 0x8C1550
#define CXWnd__GetScreenClipRect_x                                 0x8C61F0
#define CXWnd__GetScreenRect_x                                     0x8C1980
#define CXWnd__GetTooltipRect_x                                    0x8C11C0
#define CXWnd__GetWindowTextA_x                                    0x4245B0
#define CXWnd__IsActive_x                                          0x8BC2E0
#define CXWnd__IsDescendantOf_x                                    0x8C16E0
#define CXWnd__IsReallyVisible_x                                   0x8C4B00
#define CXWnd__IsType_x                                            0x8F46A0
#define CXWnd__Move_x                                              0x8C4210
#define CXWnd__Move1_x                                             0x8C6820
#define CXWnd__ProcessTransition_x                                 0x8C0C60
#define CXWnd__Refade_x                                            0x8C0A50
#define CXWnd__Resize_x                                            0x8C1A50
#define CXWnd__Right_x                                             0x8C5FF0
#define CXWnd__SetFocus_x                                          0x8C3360
#define CXWnd__SetFont_x                                           0x8C0900
#define CXWnd__SetKeyTooltip_x                                     0x8C1CB0
#define CXWnd__SetMouseOver_x                                      0x8C6500
#define CXWnd__StartFade_x                                         0x8C0D10
#define CXWnd__GetChildItem_x                                      0x8C6440

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BDB60
#define CXWndManager__DrawWindows_x                                0x8BD7A0
#define CXWndManager__GetKeyboardFlags_x                           0x8BBE10
#define CXWndManager__HandleKeyboardMsg_x                          0x8BC770
#define CXWndManager__RemoveWnd_x                                  0x8BC470

// CDBStr
#define CDBStr__GetString_x                                        0x4A7EE0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44D960
#define EQ_Character__Cur_HP_x                                     0x4628B0
#define EQ_Character__Cur_Mana_x                                   0x455FD0
#define EQ_Character__GetAACastingTimeModifier_x                   0x446C90
#define EQ_Character__GetCharInfo2_x                               0x869020
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EF20
#define EQ_Character__GetFocusRangeModifier_x                      0x43EF80
#define EQ_Character__Max_Endurance_x                              0x5BFAF0
#define EQ_Character__Max_HP_x                                     0x458BF0
#define EQ_Character__Max_Mana_x                                   0x5BF920
#define EQ_Character__doCombatAbility_x                            0x5BD010
#define EQ_Character__UseSkill_x                                   0x46DB90
#define EQ_Character__GetConLevel_x                                0x5B28C0
#define EQ_Character__IsExpansionFlag_x                            0x423AE0
#define EQ_Character__TotalEffect_x                                0x44ABB0
#define EQ_Character__GetPCSpellAffect_x                           0x447090
#define EQ_Character__SpellDuration_x                              0x444F90

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x592E60
#define EQ_Item__CreateItemTagString_x                             0x8482D0
#define EQ_Item__IsStackable_x                                     0x83DD50
#define EQ_Item__GetImageNum_x                                     0x8407C0
#define EQ_Item__CreateItemClient_x                                0x593A50
#define EQ_Item__GetItemValue_x                                    0x847040
#define EQ_Item__ValueSellMerchant_x                               0x849560

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C7820
#define EQ_LoadingS__Array_x                                       0xC17588

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C2010
#define EQ_PC__GetAlternateAbilityId_x                             0x8517C0
#define EQ_PC__GetCombatAbility_x                                  0x851850
#define EQ_PC__GetCombatAbilityTimer_x                             0x84C720
#define EQ_PC__GetItemTimerValue_x                                 0x5BB710
#define EQ_PC__HasLoreItem_x                                       0x5B5DE0
#define EQ_PC__AlertInventoryChanged_x                             0x5B2890
#define EQ_PC__GetPcZoneClient_x                                   0x5DC7F0
#define EQ_PC__RemoveMyAffect_x                                    0x5BABC0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5112B0
#define EQItemList__add_object_x                                   0x53D8B0
#define EQItemList__add_item_x                                     0x5111F0
#define EQItemList__delete_item_x                                  0x5116A0
#define EQItemList__FreeItemList_x                                 0x5115A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A7160

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C7630
#define EQPlayer__dEQPlayer_x                                      0x5D0480
#define EQPlayer__DoAttack_x                                       0x5E2510
#define EQPlayer__EQPlayer_x                                       0x5D28A0
#define EQPlayer__SetNameSpriteState_x                             0x5CD400
#define EQPlayer__SetNameSpriteTint_x                              0x5C8A70
#define PlayerBase__HasProperty_j_x                                0x925610
#define EQPlayer__IsTargetable_x                                   0x925F10
#define EQPlayer__CanSee_x                                         0x926430
#define PlayerZoneClient__ChangeHeight_x                           0x5E23D0
#define EQPlayer__CanSeeTargetIndicator_x                          0x926520

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D6C60
#define EQPlayerManager__GetSpawnByName_x                          0x5D70C0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D6C90

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x598F70
#define KeypressHandler__AttachKeyToEqCommand_x                    0x598FB0
#define KeypressHandler__ClearCommandStateArray_x                  0x598B60
#define KeypressHandler__HandleKeyDown_x                           0x5974C0
#define KeypressHandler__HandleKeyUp_x                             0x5977E0
#define KeypressHandler__SaveKeymapping_x                          0x598C30

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7066E0
#define MapViewMap__SaveEx_x                                       0x709A10

#define PlayerPointManager__GetAltCurrency_x                       0x863FB0

// StringTable 
#define StringTable__getString_x                                   0x85EB30

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BF580
#define PcZoneClient__RemovePetEffect_x                            0x5BBBE0
#define PcZoneClient__HasAlternateAbility_x                        0x5BC580
#define PcZoneClient__GetCurrentMod_x                              0x457F90
#define PcZoneClient__GetModCap_x                                  0x4557E0

//Doors
#define EQSwitch__UseSwitch_x                                      0x54F6D0

//IconCache
#define IconCache__GetIcon_x                                       0x6A35B0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69A380
#define CContainerMgr__CloseContainer_x                            0x69ABA0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x767D70

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58BFF0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DF5D0
#define EQ_Spell__SpellAffects_x                                   0x4DCC80
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DCCF0
#define CharacterZoneClient__CalcAffectChange_x                    0x4460C0
#define CLootWnd__LootAll_x                                        0x6FBF70

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AE850
#define CTargetWnd__WndNotification_x                              0x7AE340
#define CTargetWnd__UpdateBuffs_x                                  0x7AEA30

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B3A40

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D8540

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x496F40

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DFFF0
#define CSidlManager__FindAnimation1_x                             0x8D5300

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CEED0
#define CAltAbilityData__GetMercMaxRank_x                          0x4CEE80
#define CAltAbilityData__GetMaxRank_x                              0x4C3DE0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5898E0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4547F0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x684E10
#define CCastSpellWnd__IsBardSongPlaying_x                         0x684570

//messages
#define msg_spell_worn_off_x                                       0x4E70A0
#define msg_new_text_x                                             0x4F04F0
#define msgTokenTextParam_x                                        0x4ECED0

//SpellManager
#define SpellManager__vftable_x                                    0xAB5F08
#define SpellManager__SpellManager_x                               0x47B740
