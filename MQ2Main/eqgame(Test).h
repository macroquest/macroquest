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
#define __ExpectedVersionDate                                     "Apr 11 2016"
#define __ExpectedVersionTime                                     "11:19:05"
#define __ActualVersionDate_x                                      0xAD5338
#define __ActualVersionTime_x                                      0xAD5344

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59DE00
#define __MemChecker1_x                                            0x89D380
#define __MemChecker2_x                                            0x6376A0
#define __MemChecker3_x                                            0x6375F0
#define __MemChecker4_x                                            0x7EA5D0
#define __EncryptPad0_x                                            0xC72378
#define __EncryptPad1_x                                            0xDFDD08
#define __EncryptPad2_x                                            0xCBBE68
#define __EncryptPad3_x                                            0xCBBA68
#define __EncryptPad4_x                                            0xDD5EF8
#define __EncryptPad5_x                                            0x11A9B78
#define __AC1_x                                                    0x7A7AD5
#define __AC2_x                                                    0x5543C7
#define __AC3_x                                                    0x568FF0
#define __AC4_x                                                    0x56FD40
#define __AC5_x                                                    0x57B56E
#define __AC6_x                                                    0x57F129
#define __AC7_x                                                    0x575C6C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E7220

// Direct Input
#define DI8__Main_x                                                0x11A9B50
#define DI8__Keyboard_x                                            0x11A9B54
#define DI8__Mouse_x                                               0x11A9B58
#define DI8__Mouse_Copy_x                                          0x10181E4
#define DI8__Mouse_Check_x                                         0x10A1A3C
#define __Attack_x                                                 0x109C6E3
#define __Autofire_x                                               0x109C6E4
#define __BindList_x                                               0xC34478
#define __bCommandEnabled_x                                        0x1007648
#define __Clicks_x                                                 0x10182A0
#define __CommandList_x                                            0xC387E8
#define __CurrentMapLabel_x                                        0x11AF5A8
#define __CurrentSocial_x                                          0xBEB5B8
#define __DoAbilityList_x                                          0x104E998
#define __do_loot_x                                                0x51BD20
#define __DrawHandler_x                                            0x18163D4
#define __GroupCount_x                                             0x1008C12

#define __Guilds_x                                                 0x100E828
#define __gWorld_x                                                 0x100B0CC
#define __HotkeyPage_x                                             0x1095398
#define __HWnd_x                                                   0x10A1A58
#define __InChatMode_x                                             0x10181CC
#define __LastTell_x                                               0x101A094
#define __LMouseHeldTime_x                                         0x101830C
#define __Mouse_x                                                  0x11A9B5C
#define __MouseLook_x                                              0x1018266
#define __MouseEventTime_x                                         0x109CEEC
#define __gpbCommandEvent_x                                        0x100B194
#define __NetStatusToggle_x                                        0x1018269
#define __PCNames_x                                                0x10196B8
#define __RangeAttackReady_x                                       0x10193F4
#define __RMouseHeldTime_x                                         0x1018308
#define __RunWalkState_x                                           0x10181D0
#define __ScreenMode_x                                             0xF573C0
#define __ScreenX_x                                                0x1018184
#define __ScreenY_x                                                0x1018180
#define __ScreenXMax_x                                             0x1018188
#define __ScreenYMax_x                                             0x101818C
#define __ServerHost_x                                             0x1008B5C
#define __ServerName_x                                             0x104E958
#define __ShiftKeyDown_x                                           0x1018878
#define __ShowNames_x                                              0x10195B4
#define __Socials_x                                                0x104EA58
#define __SubscriptionType_x                                       0x11DDAD8
#define __TargetAggroHolder_x                                      0x11B17E4
#define __GroupAggro_x                                             0x11B1824
#define __LoginName_x                                              0x10A0630
#define __Inviter_x                                                0x109C660
#define __AttackOnAssist_x                                         0x1019570

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x100B1B8
#define instEQZoneInfo_x                                           0x101845C
#define instKeypressHandler_x                                      0x109CED0
#define pinstActiveBanker_x                                        0x100B170
#define pinstActiveCorpse_x                                        0x100B174
#define pinstActiveGMaster_x                                       0x100B178
#define pinstActiveMerchant_x                                      0x100B16C
#define pinstAggroInfo_x                                           0xE19720
#define pinstAltAdvManager_x                                       0xF58480
#define pinstAuraMgr_x                                             0xE25688
#define pinstBandageTarget_x                                       0x100B158
#define pinstCamActor_x                                            0xF57DD4
#define pinstCDBStr_x                                              0xF57354
#define pinstCDisplay_x                                            0x100B180
#define pinstCEverQuest_x                                          0x11A9CD0
#define pinstCharData_x                                            0x100B13C
#define pinstCharSpawn_x                                           0x100B164
#define pinstControlledMissile_x                                   0x100B138
#define pinstControlledPlayer_x                                    0x100B164
#define pinstCSidlManager_x                                        0x1815914
#define pinstCXWndManager_x                                        0x181590C
#define instDynamicZone_x                                          0x1018018
#define pinstDZMember_x                                            0x1018128
#define pinstDZTimerInfo_x                                         0x101812C
#define pinstEQItemList_x                                          0x1007898
#define instEQMisc_x                                               0xC0EFD0
#define pinstEQSoundManager_x                                      0xF589E0
#define instExpeditionLeader_x                                     0x1018062
#define instExpeditionName_x                                       0x10180A2
#define pinstGroup_x                                               0x1008C0E
#define pinstImeManager_x                                          0x1815918
#define pinstLocalPlayer_x                                         0x100B150
#define pinstMercenaryData_x                                       0x109D520
#define pinstMercenaryStats_x                                      0x11B1930
#define pinstMercAltAbilities_x                                    0xF5880C
#define pinstModelPlayer_x                                         0x100B17C
#define pinstPCData_x                                              0x100B13C
#define pinstSkillMgr_x                                            0x109E358
#define pinstSpawnManager_x                                        0x109DC40
#define pinstSpellManager_x                                        0x109E4A0
#define pinstSpellSets_x                                           0x10953FC
#define pinstStringTable_x                                         0x100B0E4
#define pinstSwitchManager_x                                       0x10087A0
#define pinstTarget_x                                              0x100B168
#define pinstTargetObject_x                                        0x100B140
#define pinstTargetSwitch_x                                        0x100B144
#define pinstTaskMember_x                                          0xF572A0
#define pinstTrackTarget_x                                         0x100B15C
#define pinstTradeTarget_x                                         0x100B14C
#define instTributeActive_x                                        0xC0EFF5
#define pinstViewActor_x                                           0xF57DD0
#define pinstWorldData_x                                           0x100B120
#define pinstZoneAddr_x                                            0x101871C
#define pinstPlayerPath_x                                          0x109DCA0
#define pinstTargetIndicator_x                                     0x109E638
#define pinstCTargetManager_x                                      0x109E698

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE19C18
#define pinstCAudioTriggersWindow_x                                0xE19AA8
#define pinstCCharacterSelect_x                                    0xF57C64
#define pinstCFacePick_x                                           0xF57A14
#define pinstCNoteWnd_x                                            0xF57C1C
#define pinstCBookWnd_x                                            0xF57C24
#define pinstCPetInfoWnd_x                                         0xF57C28
#define pinstCTrainWnd_x                                           0xF57C2C
#define pinstCSkillsWnd_x                                          0xF57C30
#define pinstCSkillsSelectWnd_x                                    0xF57C34
#define pinstCCombatSkillsSelectWnd_x                              0xF57C38
#define pinstCFriendsWnd_x                                         0xF57C3C
#define pinstCAuraWnd_x                                            0xF57C40
#define pinstCRespawnWnd_x                                         0xF57C44
#define pinstCBandolierWnd_x                                       0xF57C48
#define pinstCPotionBeltWnd_x                                      0xF57C4C
#define pinstCAAWnd_x                                              0xF57C50
#define pinstCGroupSearchFiltersWnd_x                              0xF57C54
#define pinstCLoadskinWnd_x                                        0xF57C58
#define pinstCAlarmWnd_x                                           0xF57C5C
#define pinstCMusicPlayerWnd_x                                     0xF57C60
#define pinstCMailWnd_x                                            0xF57C68
#define pinstCMailCompositionWnd_x                                 0xF57C6C
#define pinstCMailAddressBookWnd_x                                 0xF57C70
#define pinstCRaidWnd_x                                            0xF57C78
#define pinstCRaidOptionsWnd_x                                     0xF57C7C
#define pinstCBreathWnd_x                                          0xF57C80
#define pinstCMapViewWnd_x                                         0xF57C84
#define pinstCMapToolbarWnd_x                                      0xF57C88
#define pinstCEditLabelWnd_x                                       0xF57C8C
#define pinstCTargetWnd_x                                          0xF57C90
#define pinstCColorPickerWnd_x                                     0xF57C94
#define pinstCPlayerWnd_x                                          0xF57C98
#define pinstCOptionsWnd_x                                         0xF57C9C
#define pinstCBuffWindowNORMAL_x                                   0xF57CA0
#define pinstCBuffWindowSHORT_x                                    0xF57CA4
#define pinstCharacterCreation_x                                   0xF57CA8
#define pinstCCursorAttachment_x                                   0xF57CAC
#define pinstCCastingWnd_x                                         0xF57CB0
#define pinstCCastSpellWnd_x                                       0xF57CB4
#define pinstCSpellBookWnd_x                                       0xF57CB8
#define pinstCInventoryWnd_x                                       0xF57CBC
#define pinstCBankWnd_x                                            0xF57CC4
#define pinstCQuantityWnd_x                                        0xF57CC8
#define pinstCLootWnd_x                                            0xF57CCC
#define pinstCActionsWnd_x                                         0xF57CD0
#define pinstCCombatAbilityWnd_x                                   0xF57CD4
#define pinstCMerchantWnd_x                                        0xF57CD8
#define pinstCTradeWnd_x                                           0xF57CDC
#define pinstCSelectorWnd_x                                        0xF57CE0
#define pinstCBazaarWnd_x                                          0xF57CE4
#define pinstCBazaarSearchWnd_x                                    0xF57CE8
#define pinstCGiveWnd_x                                            0xF57D04
#define pinstCTrackingWnd_x                                        0xF57D0C
#define pinstCInspectWnd_x                                         0xF57D10
#define pinstCSocialEditWnd_x                                      0xF57D14
#define pinstCFeedbackWnd_x                                        0xF57D18
#define pinstCBugReportWnd_x                                       0xF57D1C
#define pinstCVideoModesWnd_x                                      0xF57D20
#define pinstCTextEntryWnd_x                                       0xF57D28
#define pinstCFileSelectionWnd_x                                   0xF57D2C
#define pinstCCompassWnd_x                                         0xF57D30
#define pinstCPlayerNotesWnd_x                                     0xF57D34
#define pinstCGemsGameWnd_x                                        0xF57D38
#define pinstCTimeLeftWnd_x                                        0xF57D3C
#define pinstCPetitionQWnd_x                                       0xF57D58
#define pinstCSoulmarkWnd_x                                        0xF57D5C
#define pinstCStoryWnd_x                                           0xF57D60
#define pinstCJournalTextWnd_x                                     0xF57D64
#define pinstCJournalCatWnd_x                                      0xF57D68
#define pinstCBodyTintWnd_x                                        0xF57D6C
#define pinstCServerListWnd_x                                      0xF57D70
#define pinstCAvaZoneWnd_x                                         0xF57D7C
#define pinstCBlockedBuffWnd_x                                     0xF57D80
#define pinstCBlockedPetBuffWnd_x                                  0xF57D84
#define pinstCInvSlotMgr_x                                         0xF57DC8
#define pinstCContainerMgr_x                                       0xF57DCC
#define pinstCAdventureLeaderboardWnd_x                            0x11AA680
#define pinstCAdventureRequestWnd_x                                0x11AA6F8
#define pinstCAltStorageWnd_x                                      0x11AA9D8
#define pinstCAdventureStatsWnd_x                                  0x11AA770
#define pinstCBarterMerchantWnd_x                                  0x11AB5C0
#define pinstCBarterSearchWnd_x                                    0x11AB638
#define pinstCBarterWnd_x                                          0x11AB6B0
#define pinstCChatManager_x                                        0x11ABD40
#define pinstCDynamicZoneWnd_x                                     0x11AC1F0
#define pinstCEQMainWnd_x                                          0x11AC388
#define pinstCFellowshipWnd_x                                      0x11AC184
#define pinstCFindLocationWnd_x                                    0x11AC658
#define pinstCGroupSearchWnd_x                                     0x11AC928
#define pinstCGroupWnd_x                                           0x11AC9A0
#define pinstCGuildBankWnd_x                                       0x11ACA18
#define pinstCGuildMgmtWnd_x                                       0x11AEB08
#define pinstCHotButtonWnd_x                                       0x11AEBD4
#define pinstCHotButtonWnd1_x                                      0x11AEBD4
#define pinstCHotButtonWnd2_x                                      0x11AEBD8
#define pinstCHotButtonWnd3_x                                      0x11AEBDC
#define pinstCHotButtonWnd4_x                                      0x11AEC00
#define pinstCItemDisplayManager_x                                 0x11AEEF8
#define pinstCItemExpTransferWnd_x                                 0x11AEF74
#define pinstCLFGuildWnd_x                                         0x11AF250
#define pinstCMIZoneSelectWnd_x                                    0x11AF838
#define pinstCConfirmationDialog_x                                 0x11AFF40
#define pinstCPopupWndManager_x                                    0x11AFF40
#define pinstCProgressionSelectionWnd_x                            0x11B0030
#define pinstCPvPStatsWnd_x                                        0x11B0120
#define pinstCSystemInfoDialogBox_x                                0x11B0828
#define pinstCTaskWnd_x                                            0x11B1BF0
#define pinstCTaskSomething_x                                      0xE25E48
#define pinstCTaskTemplateSelectWnd_x                              0x11B1B78
#define pinstCTipWndOFDAY_x                                        0x11B1E48
#define pinstCTipWndCONTEXT_x                                      0x11B1E4C
#define pinstCTitleWnd_x                                           0x11B1EC8
#define pinstCContextMenuManager_x                                 0x1815884
#define pinstCVoiceMacroWnd_x                                      0x109EB08
#define pinstCHtmlWnd_x                                            0x109EBF8
#define pinstIconCache_x                                           0x11AC35C
#define pinstCTradeskillWnd_x                                      0x11B1FC8
#define pinstCAdvancedLootWnd_x                                    0xF57DBC
#define pinstRewardSelectionWnd_x                                  0x11B0648

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x533310
#define __ConvertItemTags_x                                        0x520710
#define __ExecuteCmd_x                                             0x50B4D0
#define __EQGetTime_x                                              0x89CFB0
#define __get_melee_range_x                                        0x512110
#define __GetGaugeValueFromEQ_x                                    0x7A6810
#define __GetLabelFromEQ_x                                         0x7A7A60
#define __ToggleKeyRingItem_x                                      0x47FB60
#define __GetXTargetType_x                                         0x92E2B0
#define __LoadFrontEnd_x                                           0x636D70
#define __NewUIINI_x                                               0x7A61E0
#define __ProcessGameEvents_x                                      0x5779D0
#define __ProcessMouseEvent_x                                      0x577170
#define CrashDetected_x                                            0x638730
#define wwsCrashReportCheckForUploader_x                           0x7FA220
#define DrawNetStatus_x                                            0x5ADA00
#define Util__FastTime_x                                           0x89CAC0
#define Expansion_HoT_x                                            0x1019560
#define __HelpPath_x                                               0x109CC58
#define __STMLToText_x                                             0x8E2CA0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420330
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B180
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41AF60

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C6370
#define AltAdvManager__IsAbilityReady_x                            0x4C63E0
#define AltAdvManager__GetAAById_x                                 0x4C67A0
#define AltAdvManager__CanTrainAbility_x                           0x4C7060
#define AltAdvManager__CanSeeAbility_x                             0x4C6C60

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x465570
#define CharacterZoneClient__MakeMeVisible_x                       0x46B0A0
#define CharacterZoneClient__IsStackBlocked_x                      0x4491A0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x448660
#define CharacterZoneClient__GetItemCountWorn_x                    0x462E10
#define CharacterZoneClient__GetItemCountInInventory_x             0x462F00
#define CharacterZoneClient__GetCursorItemCount_x                  0x463000

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x666520

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x674380

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58CC50
#define CButtonWnd__CButtonWnd_x                                   0x8D6F70

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68F7F0
#define CChatManager__InitContextMenu_x                            0x690370

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E1000
#define CContextMenu__dCContextMenu_x                              0x8E1210
#define CContextMenu__AddMenuItem_x                                0x8E1220
#define CContextMenu__RemoveMenuItem_x                             0x8E1510
#define CContextMenu__RemoveAllMenuItems_x                         0x8E1530
#define CContextMenuManager__AddMenu_x                             0x8CD4D0
#define CContextMenuManager__RemoveMenu_x                          0x8CD830
#define CContextMenuManager__PopupMenu_x                           0x8CDC80
#define CContextMenuManager__Flush_x                               0x8CD540
#define CContextMenuManager__GetMenu_x                             0x4167D0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x882470
#define CChatService__GetFriendName_x                              0x882480

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6955C0
#define CChatWindow__Clear_x                                       0x695190
#define CChatWindow__WndNotification_x                             0x695B00

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D1340
#define CComboWnd__Draw_x                                          0x8D1550
#define CComboWnd__GetCurChoice_x                                  0x8D1110
#define CComboWnd__GetListRect_x                                   0x8D17F0
#define CComboWnd__GetTextRect_x                                   0x8D13B0
#define CComboWnd__InsertChoice_x                                  0x8D1860
#define CComboWnd__SetColors_x                                     0x8D10A0
#define CComboWnd__SetChoice_x                                     0x8D10D0
#define CComboWnd__GetItemCount_x                                  0x8D1100
#define CComboWnd__GetCurChoiceText_x                              0x8D1150

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69ECD0
#define CContainerWnd__vftable_x                                   0xADED30

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B4720
#define CDisplay__GetClickedActor_x                                0x4AD010
#define CDisplay__GetUserDefinedColor_x                            0x4ABBF0
#define CDisplay__GetWorldFilePath_x                               0x4AB040
#define CDisplay__is3dON_x                                         0x4AA4C0
#define CDisplay__ReloadUI_x                                       0x4BFD00
#define CDisplay__WriteTextHD2_x                                   0x4B0A70

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F7790

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E5530
#define CEditWnd__GetCharIndexPt_x                                 0x8E65C0
#define CEditWnd__GetDisplayString_x                               0x8E56E0
#define CEditWnd__GetHorzOffset_x                                  0x8E5A20
#define CEditWnd__GetLineForPrintableChar_x                        0x8E6090
#define CEditWnd__GetSelStartPt_x                                  0x8E6870
#define CEditWnd__GetSTMLSafeText_x                                0x8E5BC0
#define CEditWnd__PointFromPrintableChar_x                         0x8E6180
#define CEditWnd__SelectableCharFromPoint_x                        0x8E6300
#define CEditWnd__SetEditable_x                                    0x8E5B90

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x554B10
#define CEverQuest__CreateTargetIndicator_x                        0x555740
#define CEverQuest__DeleteTargetIndicator_x                        0x5557C0
#define CEverQuest__DoTellWindow_x                                 0x55A510
#define CEverQuest__DropHeldItemOnGround_x                         0x563470
#define CEverQuest__dsp_chat_x                                     0x55BFB0
#define CEverQuest__Emote_x                                        0x55C210
#define CEverQuest__EnterZone_x                                    0x570690
#define CEverQuest__GetBodyTypeDesc_x                              0x5512A0
#define CEverQuest__GetClassDesc_x                                 0x557080
#define CEverQuest__GetClassThreeLetterCode_x                      0x557680
#define CEverQuest__GetDeityDesc_x                                 0x551B80
#define CEverQuest__GetLangDesc_x                                  0x551630
#define CEverQuest__GetRaceDesc_x                                  0x557840
#define CEverQuest__InterpretCmd_x                                 0x55CAF0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5740E0
#define CEverQuest__LMouseUp_x                                     0x5761C0
#define CEverQuest__RightClickedOnPlayer_x                         0x574BE0
#define CEverQuest__RMouseUp_x                                     0x575C20
#define CEverQuest__SetGameState_x                                 0x5551C0
#define CEverQuest__UPCNotificationFlush_x                         0x55DE50
#define CEverQuest__IssuePetCommand_x                              0x55D7B0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AF880
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AF8E0
#define CGaugeWnd__Draw_x                                          0x6AFD10

// CGuild
#define CGuild__FindMemberByName_x                                 0x436FE0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CC420

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D8B30
#define CInvSlotMgr__MoveItem_x                                    0x6D9A70
#define CInvSlotMgr__SelectSlot_x                                  0x6D8BE0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D7FC0
#define CInvSlot__SliderComplete_x                                 0x6D57F0
#define CInvSlot__GetItemBase_x                                    0x6D4C70

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DAE50

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A3270
#define CItemDisplayWnd__UpdateStrings_x                           0x6DC190

// CLabel 
#define CLabel__Draw_x                                             0x6F6E90

// CListWnd
#define CListWnd__CListWnd_x                                       0x8BD2A0
#define CListWnd__dCListWnd_x                                      0x8BE2D0
#define CListWnd__AddColumn_x                                      0x8BE270
#define CListWnd__AddColumn1_x                                     0x8BDAE0
#define CListWnd__AddLine_x                                        0x8BD560
#define CListWnd__AddString_x                                      0x8BD770
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BA5E0
#define CListWnd__CalculateVSBRange_x                              0x8BC760
#define CListWnd__ClearSel_x                                       0x8B98F0
#define CListWnd__ClearAllSel_x                                    0x8B98A0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8BD130
#define CListWnd__Compare_x                                        0x8BB0E0
#define CListWnd__Draw_x                                           0x8BC370
#define CListWnd__DrawColumnSeparators_x                           0x8BC200
#define CListWnd__DrawHeader_x                                     0x8B9BB0
#define CListWnd__DrawItem_x                                       0x8BB730
#define CListWnd__DrawLine_x                                       0x8BBEA0
#define CListWnd__DrawSeparator_x                                  0x8BC2A0
#define CListWnd__EnsureVisible_x                                  0x8BA740
#define CListWnd__ExtendSel_x                                      0x8BB640
#define CListWnd__GetColumnMinWidth_x                              0x8B9260
#define CListWnd__GetColumnWidth_x                                 0x8B9180
#define CListWnd__GetCurSel_x                                      0x8B8970
#define CListWnd__GetItemAtPoint_x                                 0x8BA9D0
#define CListWnd__GetItemAtPoint1_x                                0x8BAA40
#define CListWnd__GetItemData_x                                    0x8B8CA0
#define CListWnd__GetItemHeight_x                                  0x8BA240
#define CListWnd__GetItemIcon_x                                    0x8B8E80
#define CListWnd__GetItemRect_x                                    0x8BA810
#define CListWnd__GetItemText_x                                    0x8B8D30
#define CListWnd__GetSelList_x                                     0x8BD9D0
#define CListWnd__GetSeparatorRect_x                               0x8BB000
#define CListWnd__RemoveLine_x                                     0x8BD950
#define CListWnd__SetColors_x                                      0x8B8AC0
#define CListWnd__SetColumnJustification_x                         0x8B9530
#define CListWnd__SetColumnWidth_x                                 0x8B9210
#define CListWnd__SetCurSel_x                                      0x8B89B0
#define CListWnd__SetItemColor_x                                   0x8BCE10
#define CListWnd__SetItemData_x                                    0x8B9950
#define CListWnd__SetItemText_x                                    0x8BCC50
#define CListWnd__ShiftColumnSeparator_x                           0x8BCAE0
#define CListWnd__Sort_x                                           0x8BE3D0
#define CListWnd__ToggleSel_x                                      0x8B9820

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70FEB0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7310F0
#define CMerchantWnd__RequestBuyItem_x                             0x737ED0
#define CMerchantWnd__RequestSellItem_x                            0x738920
#define CMerchantWnd__SelectRecoverySlot_x                         0x7313A0
#define CMerchantWnd__SelectBuySellSlot_x                          0x730600
#define CMerchantWnd__ActualSelect_x                               0x734E20

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x84F040
#define CPacketScrambler__hton_x                                   0x84F050

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8DBF30
#define CSidlManager__CreateLabel_x                                0x7992A0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65D870
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65D7A0
#define CSidlScreenWnd__ConvertToRes_x                             0x8F7670
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D3CD0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D4ED0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D4F80
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D4430
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D3680
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D2DF0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D3870
#define CSidlScreenWnd__Init1_x                                    0x8D4BA0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D3D80
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D2FB0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D4680
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D2A40
#define CSidlScreenWnd__StoreIniVis_x                              0x8D2DA0
#define CSidlScreenWnd__WndNotification_x                          0x8D4920
#define CSidlScreenWnd__GetChildItem_x                             0x8D2EC0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C67D0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F8A40
#define CSkillMgr__GetSkillCap_x                                   0x5F8C00
#define CSkillMgr__GetNameToken_x                                  0x5F8660

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F6910
#define CSliderWnd__SetValue_x                                     0x8F6AE0
#define CSliderWnd__SetNumTicks_x                                  0x8F7260

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A0F20

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F2280
#define CStmlWnd__CalculateHSBRange_x                              0x8EA7A0
#define CStmlWnd__CalculateVSBRange_x                              0x8EA830
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EA9B0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EB290
#define CStmlWnd__ForceParseNow_x                                  0x8F2BD0
#define CStmlWnd__GetNextTagPiece_x                                0x8EB190
#define CStmlWnd__GetSTMLText_x                                    0x694A30
#define CStmlWnd__GetVisibleText_x                                 0x8EBCE0
#define CStmlWnd__InitializeWindowVariables_x                      0x8EE060
#define CStmlWnd__MakeStmlColorTag_x                               0x8E9AA0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E9B00
#define CStmlWnd__SetSTMLText_x                                    0x8EF8C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F1F20
#define CStmlWnd__UpdateHistoryString_x                            0x8ECC20

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E9100
#define CTabWnd__DrawCurrentPage_x                                 0x8E8970
#define CTabWnd__DrawTab_x                                         0x8E8730
#define CTabWnd__GetCurrentPage_x                                  0x8E8D40
#define CTabWnd__GetPageInnerRect_x                                0x8E8420
#define CTabWnd__GetTabInnerRect_x                                 0x8E8620
#define CTabWnd__GetTabRect_x                                      0x8E84F0
#define CTabWnd__InsertPage_x                                      0x8E93F0
#define CTabWnd__SetPage_x                                         0x8E8D70
#define CTabWnd__SetPageRect_x                                     0x8E9040
#define CTabWnd__UpdatePage_x                                      0x8E9390

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432D90

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D0D10

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8FCAF0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B6A10

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59A340
#define CXStr__CXStr1_x                                            0x7D7410
#define CXStr__CXStr3_x                                            0x899B80
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x899CF0
#define CXStr__operator_equal1_x                                   0x899D40
#define CXStr__operator_plus_equal1_x                              0x89AE60

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C5A90
#define CXWnd__Center_x                                            0x8CBAF0
#define CXWnd__ClrFocus_x                                          0x8C5670
#define CXWnd__DoAllDrawing_x                                      0x8CB740
#define CXWnd__DrawChildren_x                                      0x8CB8E0
#define CXWnd__DrawColoredRect_x                                   0x8C5E40
#define CXWnd__DrawTooltip_x                                       0x8C60E0
#define CXWnd__DrawTooltipAtPoint_x                                0x8CA6A0
#define CXWnd__GetBorderFrame_x                                    0x8C64D0
#define CXWnd__GetChildWndAt_x                                     0x8CC4A0
#define CXWnd__GetClientClipRect_x                                 0x8C62E0
#define CXWnd__GetScreenClipRect_x                                 0x8CADA0
#define CXWnd__GetScreenRect_x                                     0x8C6670
#define CXWnd__GetTooltipRect_x                                    0x8C5F70
#define CXWnd__GetWindowTextA_x                                    0x4243E0
#define CXWnd__IsActive_x                                          0x8C10B0
#define CXWnd__IsDescendantOf_x                                    0x8C6420
#define CXWnd__IsReallyVisible_x                                   0x8C9720
#define CXWnd__IsType_x                                            0x8F92F0
#define CXWnd__Move_x                                              0x8C8E20
#define CXWnd__Move1_x                                             0x8CB3F0
#define CXWnd__ProcessTransition_x                                 0x8C5A30
#define CXWnd__Refade_x                                            0x8C5810
#define CXWnd__Resize_x                                            0x8C6730
#define CXWnd__Right_x                                             0x8CABA0
#define CXWnd__SetFocus_x                                          0x8C7F80
#define CXWnd__SetFont_x                                           0x8C56C0
#define CXWnd__SetKeyTooltip_x                                     0x8C69A0
#define CXWnd__SetMouseOver_x                                      0x8CB0E0
#define CXWnd__StartFade_x                                         0x8C5AE0
#define CXWnd__GetChildItem_x                                      0x8CB020

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C2950
#define CXWndManager__DrawWindows_x                                0x8C2590
#define CXWndManager__GetKeyboardFlags_x                           0x8C0BE0
#define CXWndManager__HandleKeyboardMsg_x                          0x8C1540
#define CXWndManager__RemoveWnd_x                                  0x8C1240

// CDBStr
#define CDBStr__GetString_x                                        0x4A8970

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44F750
#define EQ_Character__Cur_HP_x                                     0x464C40
#define EQ_Character__Cur_Mana_x                                   0x457CA0
#define EQ_Character__GetAACastingTimeModifier_x                   0x448970
#define EQ_Character__GetCharInfo2_x                               0x86E5B0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43FB80
#define EQ_Character__GetFocusRangeModifier_x                      0x43FDD0
#define EQ_Character__Max_Endurance_x                              0x5C0090
#define EQ_Character__Max_HP_x                                     0x45A8A0
#define EQ_Character__Max_Mana_x                                   0x5BFEC0
#define EQ_Character__doCombatAbility_x                            0x5BD500
#define EQ_Character__UseSkill_x                                   0x470290
#define EQ_Character__GetConLevel_x                                0x5B1FC0
#define EQ_Character__IsExpansionFlag_x                            0x423920
#define EQ_Character__TotalEffect_x                                0x44C990
#define EQ_Character__GetPCSpellAffect_x                           0x448D70
#define EQ_Character__SpellDuration_x                              0x446C90

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x592560
#define EQ_Item__CreateItemTagString_x                             0x84D960
#define EQ_Item__IsStackable_x                                     0x841E10
#define EQ_Item__GetImageNum_x                                     0x844860
#define EQ_Item__CreateItemClient_x                                0x593130
#define EQ_Item__GetItemValue_x                                    0x84C670
#define EQ_Item__ValueSellMerchant_x                               0x84EC90

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C84F0
#define EQ_LoadingS__Array_x                                       0xC1B738

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C16E0
#define EQ_PC__GetAlternateAbilityId_x                             0x856FD0
#define EQ_PC__GetCombatAbility_x                                  0x857060
#define EQ_PC__GetCombatAbilityTimer_x                             0x851E30
#define EQ_PC__GetItemTimerValue_x                                 0x5BAF90
#define EQ_PC__HasLoreItem_x                                       0x5B54B0
#define EQ_PC__AlertInventoryChanged_x                             0x5B1F90
#define EQ_PC__GetPcZoneClient_x                                   0x5DBD40
#define EQ_PC__RemoveMyAffect_x                                    0x5BA440

// EQItemList 
#define EQItemList__EQItemList_x                                   0x510150
#define EQItemList__add_item_x                                     0x53C9D0
#define EQItemList__delete_item_x                                  0x510550
#define EQItemList__FreeItemList_x                                 0x510450

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A7B70

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C6CA0
#define EQPlayer__dEQPlayer_x                                      0x5CFB80
#define EQPlayer__DoAttack_x                                       0x5E1CC0
#define EQPlayer__EQPlayer_x                                       0x5D1FA0
#define EQPlayer__SetNameSpriteState_x                             0x5CCA50
#define EQPlayer__SetNameSpriteTint_x                              0x5C80D0
#define PlayerBase__HasProperty_j_x                                0x92A400
#define EQPlayer__IsTargetable_x                                   0x92AD00
#define EQPlayer__CanSee_x                                         0x92B220
#define PlayerZoneClient__ChangeHeight_x                           0x5E1B80
#define EQPlayer__CanSeeTargetIndicator_x                          0x92B310

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D62F0
#define EQPlayerManager__GetSpawnByName_x                          0x5D6750
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D6320

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x598700
#define KeypressHandler__AttachKeyToEqCommand_x                    0x598740
#define KeypressHandler__ClearCommandStateArray_x                  0x5982F0
#define KeypressHandler__HandleKeyDown_x                           0x596C50
#define KeypressHandler__HandleKeyUp_x                             0x596F70
#define KeypressHandler__SaveKeymapping_x                          0x5983C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x708860
#define MapViewMap__SaveEx_x                                       0x70BB70

#define PlayerPointManager__GetAltCurrency_x                       0x869580

// StringTable 
#define StringTable__getString_x                                   0x863FD0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BFB40
#define PcZoneClient__RemovePetEffect_x                            0x5BB480
#define PcZoneClient__HasAlternateAbility_x                        0x5BBF40

//Doors
#define EQSwitch__UseSwitch_x                                      0x54E6A0

//IconCache
#define IconCache__GetIcon_x                                       0x6A5200

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69BFE0
#define CContainerMgr__CloseContainer_x                            0x69C800

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x769670

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58B6E0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E04C0
#define EQ_Spell__SpellAffects_x                                   0x4DDB70
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DDBE0
#define CharacterZoneClient__CalcAffectChange_x                    0x447DB0
#define CLootWnd__LootAll_x                                        0x6FE170

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AEC20
#define CTargetWnd__WndNotification_x                              0x7AE710
#define CTargetWnd__UpdateBuffs_x                                  0x7AEE00

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B3E00

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D94E0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x498210

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E4B60
#define CSidlManager__FindAnimation1_x                             0x8D9E20

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CFBE0
#define CAltAbilityData__GetMercMaxRank_x                          0x4CFB90
#define CAltAbilityData__GetMaxRank_x                              0x4C4A30

//CTargetRing
#define CTargetRing__Cast_x                                        0x588FD0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x456650

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x686920
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6860E0

//messages
#define msg_spell_worn_off_x                                       0x4E7F00
#define msg_new_text_x                                             0x4F1340
#define msgTokenTextParam_x                                        0x4EDE20
