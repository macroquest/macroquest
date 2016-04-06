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
#define __ExpectedVersionDate                                     "Apr  5 2016"
#define __ExpectedVersionTime                                     "16:26:09"
#define __ActualVersionDate_x                                      0xAD6310
#define __ActualVersionTime_x                                      0xAD631C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59E2B0
#define __MemChecker1_x                                            0x89D730
#define __MemChecker2_x                                            0x6379D0
#define __MemChecker3_x                                            0x637920
#define __MemChecker4_x                                            0x7EB160
#define __EncryptPad0_x                                            0xC73378
#define __EncryptPad1_x                                            0xDFED08
#define __EncryptPad2_x                                            0xCBCE68
#define __EncryptPad3_x                                            0xCBCA68
#define __EncryptPad4_x                                            0xDD6EF8
#define __EncryptPad5_x                                            0x11AAB78
#define __AC1_x                                                    0x7A8405
#define __AC2_x                                                    0x554847
#define __AC3_x                                                    0x569470
#define __AC4_x                                                    0x5701C0
#define __AC5_x                                                    0x57B9FE
#define __AC6_x                                                    0x57F5C9
#define __AC7_x                                                    0x5760FC
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
#define __do_loot_x                                                0x51C180
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
#define __CastRay_x                                                0x533770
#define __ConvertItemTags_x                                        0x520B70
#define __ExecuteCmd_x                                             0x50B930
#define __EQGetTime_x                                              0x89D360
#define __get_melee_range_x                                        0x512570
#define __GetGaugeValueFromEQ_x                                    0x7A7140
#define __GetLabelFromEQ_x                                         0x7A8390
#define __ToggleKeyRingItem_x                                      0x47FA30
#define __GetXTargetType_x                                         0x92E670
#define __LoadFrontEnd_x                                           0x6370A0
#define __NewUIINI_x                                               0x7A6B10
#define __ProcessGameEvents_x                                      0x577E60
#define __ProcessMouseEvent_x                                      0x577600
#define CrashDetected_x                                            0x638A60
#define wwsCrashReportCheckForUploader_x                           0x7FAB60
#define DrawNetStatus_x                                            0x5ADD50
#define Util__FastTime_x                                           0x89CE70
#define Expansion_HoT_x                                            0x101A560
#define __HelpPath_x                                               0x109DC58
#define __STMLToText_x                                             0x8E3480

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4202E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B130
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41AF10

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C6280
#define AltAdvManager__IsAbilityReady_x                            0x4C62F0
#define AltAdvManager__GetAAById_x                                 0x4C66B0
#define AltAdvManager__CanTrainAbility_x                           0x4C6F70
#define AltAdvManager__CanSeeAbility_x                             0x4C6B70

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4654D0
#define CharacterZoneClient__MakeMeVisible_x                       0x46B000
#define CharacterZoneClient__IsStackBlocked_x                      0x449080
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x448540
#define CharacterZoneClient__GetItemCountWorn_x                    0x462D60
#define CharacterZoneClient__GetItemCountInInventory_x             0x462E50
#define CharacterZoneClient__GetCursorItemCount_x                  0x462F50

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6667E0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x674C70

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58D090
#define CButtonWnd__CButtonWnd_x                                   0x8D7680

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68FAB0
#define CChatManager__InitContextMenu_x                            0x690630

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E17E0
#define CContextMenu__dCContextMenu_x                              0x8E19F0
#define CContextMenu__AddMenuItem_x                                0x8E1A00
#define CContextMenu__RemoveMenuItem_x                             0x8E1CF0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E1D10
#define CContextMenuManager__AddMenu_x                             0x8CDBE0
#define CContextMenuManager__RemoveMenu_x                          0x8CDF40
#define CContextMenuManager__PopupMenu_x                           0x8CE390
#define CContextMenuManager__Flush_x                               0x8CDC50
#define CContextMenuManager__GetMenu_x                             0x416790

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x882790
#define CChatService__GetFriendName_x                              0x8827A0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x695880
#define CChatWindow__Clear_x                                       0x695450
#define CChatWindow__WndNotification_x                             0x695DC0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D1A60
#define CComboWnd__Draw_x                                          0x8D1C70
#define CComboWnd__GetCurChoice_x                                  0x8D1830
#define CComboWnd__GetListRect_x                                   0x8D1F10
#define CComboWnd__GetTextRect_x                                   0x8D1AD0
#define CComboWnd__InsertChoice_x                                  0x8D1F80
#define CComboWnd__SetColors_x                                     0x8D17C0
#define CComboWnd__SetChoice_x                                     0x8D17F0
#define CComboWnd__GetItemCount_x                                  0x8D1820
#define CComboWnd__GetCurChoiceText_x                              0x8D1870

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69EFE0
#define CContainerWnd__vftable_x                                   0xADFD08

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B4630
#define CDisplay__GetClickedActor_x                                0x4ACF10
#define CDisplay__GetUserDefinedColor_x                            0x4ABAF0
#define CDisplay__GetWorldFilePath_x                               0x4AAF40
#define CDisplay__is3dON_x                                         0x4AA3C0
#define CDisplay__ReloadUI_x                                       0x4BFC10
#define CDisplay__WriteTextHD2_x                                   0x4B0980

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F7EE0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E5D00
#define CEditWnd__GetCharIndexPt_x                                 0x8E6D90
#define CEditWnd__GetDisplayString_x                               0x8E5EB0
#define CEditWnd__GetHorzOffset_x                                  0x8E61F0
#define CEditWnd__GetLineForPrintableChar_x                        0x8E6860
#define CEditWnd__GetSelStartPt_x                                  0x8E7040
#define CEditWnd__GetSTMLSafeText_x                                0x8E6390
#define CEditWnd__PointFromPrintableChar_x                         0x8E6950
#define CEditWnd__SelectableCharFromPoint_x                        0x8E6AD0
#define CEditWnd__SetEditable_x                                    0x8E6360

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x554F90
#define CEverQuest__CreateTargetIndicator_x                        0x555BC0
#define CEverQuest__DeleteTargetIndicator_x                        0x555C40
#define CEverQuest__DoTellWindow_x                                 0x55A990
#define CEverQuest__DropHeldItemOnGround_x                         0x5638F0
#define CEverQuest__dsp_chat_x                                     0x55C430
#define CEverQuest__Emote_x                                        0x55C690
#define CEverQuest__EnterZone_x                                    0x570B10
#define CEverQuest__GetBodyTypeDesc_x                              0x551720
#define CEverQuest__GetClassDesc_x                                 0x557500
#define CEverQuest__GetClassThreeLetterCode_x                      0x557B00
#define CEverQuest__GetDeityDesc_x                                 0x552000
#define CEverQuest__GetLangDesc_x                                  0x551AB0
#define CEverQuest__GetRaceDesc_x                                  0x557CC0
#define CEverQuest__InterpretCmd_x                                 0x55CF70
#define CEverQuest__LeftClickedOnPlayer_x                          0x574560
#define CEverQuest__LMouseUp_x                                     0x576650
#define CEverQuest__RightClickedOnPlayer_x                         0x575060
#define CEverQuest__RMouseUp_x                                     0x5760B0
#define CEverQuest__SetGameState_x                                 0x555640
#define CEverQuest__UPCNotificationFlush_x                         0x55E2D0
#define CEverQuest__IssuePetCommand_x                              0x55DC30

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AFD20
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AFD80
#define CGaugeWnd__Draw_x                                          0x6B01B0

// CGuild
#define CGuild__FindMemberByName_x                                 0x436E60

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CC800

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D8F50
#define CInvSlotMgr__MoveItem_x                                    0x6D9E90
#define CInvSlotMgr__SelectSlot_x                                  0x6D9000

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D83E0
#define CInvSlot__SliderComplete_x                                 0x6D5C10
#define CInvSlot__GetItemBase_x                                    0x6D5080

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DB290

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A3BC0
#define CItemDisplayWnd__UpdateStrings_x                           0x6DC5E0

// CLabel 
#define CLabel__Draw_x                                             0x6F72F0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8BD6C0
#define CListWnd__dCListWnd_x                                      0x8BE6E0
#define CListWnd__AddColumn_x                                      0x8BE680
#define CListWnd__AddColumn1_x                                     0x8BDEF0
#define CListWnd__AddLine_x                                        0x8BD970
#define CListWnd__AddString_x                                      0x8BDB80
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BA9E0
#define CListWnd__CalculateVSBRange_x                              0x8BCB70
#define CListWnd__ClearSel_x                                       0x8B9CE0
#define CListWnd__ClearAllSel_x                                    0x8B9C90
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8BD550
#define CListWnd__Compare_x                                        0x8BB4F0
#define CListWnd__Draw_x                                           0x8BC780
#define CListWnd__DrawColumnSeparators_x                           0x8BC610
#define CListWnd__DrawHeader_x                                     0x8B9FA0
#define CListWnd__DrawItem_x                                       0x8BBB40
#define CListWnd__DrawLine_x                                       0x8BC2B0
#define CListWnd__DrawSeparator_x                                  0x8BC6B0
#define CListWnd__EnsureVisible_x                                  0x8BAB40
#define CListWnd__ExtendSel_x                                      0x8BBA50
#define CListWnd__GetColumnMinWidth_x                              0x8B9650
#define CListWnd__GetColumnWidth_x                                 0x8B9570
#define CListWnd__GetCurSel_x                                      0x8B8D30
#define CListWnd__GetItemAtPoint_x                                 0x8BADE0
#define CListWnd__GetItemAtPoint1_x                                0x8BAE50
#define CListWnd__GetItemData_x                                    0x8B9080
#define CListWnd__GetItemHeight_x                                  0x8BA630
#define CListWnd__GetItemIcon_x                                    0x8B9260
#define CListWnd__GetItemRect_x                                    0x8BAC20
#define CListWnd__GetItemText_x                                    0x8B9110
#define CListWnd__GetSelList_x                                     0x8BDDE0
#define CListWnd__GetSeparatorRect_x                               0x8BB410
#define CListWnd__RemoveLine_x                                     0x8BDD60
#define CListWnd__SetColors_x                                      0x8B8E80
#define CListWnd__SetColumnJustification_x                         0x8B9920
#define CListWnd__SetColumnWidth_x                                 0x8B9600
#define CListWnd__SetCurSel_x                                      0x8B8D70
#define CListWnd__SetItemColor_x                                   0x8BD230
#define CListWnd__SetItemData_x                                    0x8B9D40
#define CListWnd__SetItemText_x                                    0x8BD070
#define CListWnd__ShiftColumnSeparator_x                           0x8BCF00
#define CListWnd__Sort_x                                           0x8BE7E0
#define CListWnd__ToggleSel_x                                      0x8B9C10

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x710290

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x731700
#define CMerchantWnd__RequestBuyItem_x                             0x738520
#define CMerchantWnd__RequestSellItem_x                            0x738F70
#define CMerchantWnd__SelectRecoverySlot_x                         0x7319B0
#define CMerchantWnd__SelectBuySellSlot_x                          0x730C10
#define CMerchantWnd__ActualSelect_x                               0x735460

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x84F3E0
#define CPacketScrambler__hton_x                                   0x84F3F0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8DC750
#define CSidlManager__CreateLabel_x                                0x799BE0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65DB30
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65DA50
#define CSidlScreenWnd__ConvertToRes_x                             0x8F7DC0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D4410
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D5600
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D56B0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D4B70
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D3DC0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D3510
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D3FB0
#define CSidlScreenWnd__Init1_x                                    0x8D52E0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D44C0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D36D0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D4DC0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D3160
#define CSidlScreenWnd__StoreIniVis_x                              0x8D34C0
#define CSidlScreenWnd__WndNotification_x                          0x8D5060
#define CSidlScreenWnd__GetChildItem_x                             0x8D35E0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C6D90

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F8E40
#define CSkillMgr__GetSkillCap_x                                   0x5F9000
#define CSkillMgr__GetNameToken_x                                  0x5F8A60

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F7090
#define CSliderWnd__SetValue_x                                     0x8F7260
#define CSliderWnd__SetNumTicks_x                                  0x8F79E0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A1860

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F2A10
#define CStmlWnd__CalculateHSBRange_x                              0x8EAF30
#define CStmlWnd__CalculateVSBRange_x                              0x8EAFC0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EB140
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EBA20
#define CStmlWnd__ForceParseNow_x                                  0x8F3360
#define CStmlWnd__GetNextTagPiece_x                                0x8EB920
#define CStmlWnd__GetSTMLText_x                                    0x694CF0
#define CStmlWnd__GetVisibleText_x                                 0x8EC470
#define CStmlWnd__InitializeWindowVariables_x                      0x8EE800
#define CStmlWnd__MakeStmlColorTag_x                               0x8EA230
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EA290
#define CStmlWnd__SetSTMLText_x                                    0x8F0070
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F26B0
#define CStmlWnd__UpdateHistoryString_x                            0x8ED3B0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E98D0
#define CTabWnd__DrawCurrentPage_x                                 0x8E9140
#define CTabWnd__DrawTab_x                                         0x8E8F00
#define CTabWnd__GetCurrentPage_x                                  0x8E9510
#define CTabWnd__GetPageInnerRect_x                                0x8E8BF0
#define CTabWnd__GetTabInnerRect_x                                 0x8E8DF0
#define CTabWnd__GetTabRect_x                                      0x8E8CC0
#define CTabWnd__InsertPage_x                                      0x8E9BC0
#define CTabWnd__SetPage_x                                         0x8E9540
#define CTabWnd__SetPageRect_x                                     0x8E9810
#define CTabWnd__UpdatePage_x                                      0x8E9B60

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432CC0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D1430

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8FD220

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B6ED0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59A7F0
#define CXStr__CXStr1_x                                            0x4E45E0
#define CXStr__CXStr3_x                                            0x899F30
#define CXStr__dCXStr_x                                            0x47AC80
#define CXStr__operator_equal_x                                    0x89A0A0
#define CXStr__operator_equal1_x                                   0x89A0F0
#define CXStr__operator_plus_equal1_x                              0x89B210

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C5F80
#define CXWnd__Center_x                                            0x8CC1E0
#define CXWnd__ClrFocus_x                                          0x8C5B50
#define CXWnd__DoAllDrawing_x                                      0x8CBE10
#define CXWnd__DrawChildren_x                                      0x8CBFC0
#define CXWnd__DrawColoredRect_x                                   0x8C6340
#define CXWnd__DrawTooltip_x                                       0x8C65F0
#define CXWnd__DrawTooltipAtPoint_x                                0x8CAD80
#define CXWnd__GetBorderFrame_x                                    0x8C6A60
#define CXWnd__GetChildWndAt_x                                     0x8CCBA0
#define CXWnd__GetClientClipRect_x                                 0x8C6810
#define CXWnd__GetScreenClipRect_x                                 0x8CB480
#define CXWnd__GetScreenRect_x                                     0x8C6C20
#define CXWnd__GetTooltipRect_x                                    0x8C6480
#define CXWnd__GetWindowTextA_x                                    0x4242F0
#define CXWnd__IsActive_x                                          0x8C1500
#define CXWnd__IsDescendantOf_x                                    0x8C69A0
#define CXWnd__IsReallyVisible_x                                   0x8C9D90
#define CXWnd__IsType_x                                            0x8F9A00
#define CXWnd__Move_x                                              0x8C9470
#define CXWnd__Move1_x                                             0x8CBAD0
#define CXWnd__ProcessTransition_x                                 0x8C5F30
#define CXWnd__Refade_x                                            0x8C5D00
#define CXWnd__Resize_x                                            0x8C6CF0
#define CXWnd__Right_x                                             0x8CB280
#define CXWnd__SetFocus_x                                          0x8C85C0
#define CXWnd__SetFont_x                                           0x8C5BA0
#define CXWnd__SetKeyTooltip_x                                     0x8C6F60
#define CXWnd__SetMouseOver_x                                      0x8CB7D0
#define CXWnd__StartFade_x                                         0x8C5FD0
#define CXWnd__GetChildItem_x                                      0x8CB710

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C2DA0
#define CXWndManager__DrawWindows_x                                0x8C29E0
#define CXWndManager__GetKeyboardFlags_x                           0x8C1030
#define CXWndManager__HandleKeyboardMsg_x                          0x8C1990
#define CXWndManager__RemoveWnd_x                                  0x8C1690

// CDBStr
#define CDBStr__GetString_x                                        0x4A88A0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44F630
#define EQ_Character__Cur_HP_x                                     0x464BA0
#define EQ_Character__Cur_Mana_x                                   0x457BD0
#define EQ_Character__GetAACastingTimeModifier_x                   0x448850
#define EQ_Character__GetCharInfo2_x                               0x86E9C0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43FA40
#define EQ_Character__GetFocusRangeModifier_x                      0x43FC90
#define EQ_Character__Max_Endurance_x                              0x5C0560
#define EQ_Character__Max_HP_x                                     0x45A7D0
#define EQ_Character__Max_Mana_x                                   0x5C0390
#define EQ_Character__doCombatAbility_x                            0x5BD9D0
#define EQ_Character__UseSkill_x                                   0x470200
#define EQ_Character__GetConLevel_x                                0x5B22F0
#define EQ_Character__IsExpansionFlag_x                            0x423840
#define EQ_Character__TotalEffect_x                                0x44C870
#define EQ_Character__GetPCSpellAffect_x                           0x448C50
#define EQ_Character__SpellDuration_x                              0x446B70

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x592900
#define EQ_Item__CreateItemTagString_x                             0x84DD50
#define EQ_Item__IsStackable_x                                     0x842630
#define EQ_Item__GetImageNum_x                                     0x845080
#define EQ_Item__CreateItemClient_x                                0x5934E0
#define EQ_Item__GetItemValue_x                                    0x84CAB0
#define EQ_Item__ValueSellMerchant_x                               0x84F030

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C83F0
#define EQ_LoadingS__Array_x                                       0xC1C738

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C1BC0
#define EQ_PC__GetAlternateAbilityId_x                             0x8572A0
#define EQ_PC__GetCombatAbility_x                                  0x857330
#define EQ_PC__GetCombatAbilityTimer_x                             0x8521D0
#define EQ_PC__GetItemTimerValue_x                                 0x5BB470
#define EQ_PC__HasLoreItem_x                                       0x5B57D0
#define EQ_PC__AlertInventoryChanged_x                             0x5B22C0
#define EQ_PC__GetPcZoneClient_x                                   0x5DC290
#define EQ_PC__RemoveMyAffect_x                                    0x5BA920

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5105B0
#define EQItemList__add_item_x                                     0x5104F0
#define EQItemList__delete_item_x                                  0x5109B0
#define EQItemList__FreeItemList_x                                 0x5108B0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A7B50

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C7170
#define EQPlayer__dEQPlayer_x                                      0x5D0050
#define EQPlayer__DoAttack_x                                       0x5E2220
#define EQPlayer__EQPlayer_x                                       0x5D2470
#define EQPlayer__SetNameSpriteState_x                             0x5CCF20
#define EQPlayer__SetNameSpriteTint_x                              0x5C85A0
#define PlayerBase__HasProperty_j_x                                0x92A8A0
#define EQPlayer__IsTargetable_x                                   0x92B1A0
#define EQPlayer__CanSee_x                                         0x92B6C0
#define PlayerZoneClient__ChangeHeight_x                           0x5E20E0
#define EQPlayer__CanSeeTargetIndicator_x                          0x92B7B0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D6830
#define EQPlayerManager__GetSpawnByName_x                          0x5D6C90
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D6860

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x598BB0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x598BF0
#define KeypressHandler__ClearCommandStateArray_x                  0x5987A0
#define KeypressHandler__HandleKeyDown_x                           0x597100
#define KeypressHandler__HandleKeyUp_x                             0x597420
#define KeypressHandler__SaveKeymapping_x                          0x598870

// MapViewMap 
#define MapViewMap__Clear_x                                        0x708C40
#define MapViewMap__SaveEx_x                                       0x70BF50

#define PlayerPointManager__GetAltCurrency_x                       0x8698E0

// StringTable 
#define StringTable__getString_x                                   0x8642B0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C0010
#define PcZoneClient__RemovePetEffect_x                            0x5BB960
#define PcZoneClient__HasAlternateAbility_x                        0x5BC420

//Doors
#define EQSwitch__UseSwitch_x                                      0x54EAB0

//IconCache
#define IconCache__GetIcon_x                                       0x6A54F0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69C2F0
#define CContainerMgr__CloseContainer_x                            0x69CB10

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x769DF0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58BB30

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E0560
#define EQ_Spell__SpellAffects_x                                   0x4DDC10
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DDC80
#define CharacterZoneClient__CalcAffectChange_x                    0x447C90
#define CLootWnd__LootAll_x                                        0x6FE460

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AF550
#define CTargetWnd__WndNotification_x                              0x7AF040
#define CTargetWnd__UpdateBuffs_x                                  0x7AF730

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B4720

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D9520

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4981B0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E5330
#define CSidlManager__FindAnimation1_x                             0x8DA640

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CFB50
#define CAltAbilityData__GetMercMaxRank_x                          0x4CFB00
#define CAltAbilityData__GetMaxRank_x                              0x4C4940

//CTargetRing
#define CTargetRing__Cast_x                                        0x589430

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x456530

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x686C80
#define CCastSpellWnd__IsBardSongPlaying_x                         0x686440

//messages
#define msg_spell_worn_off_x                                       0x4E8010
#define msg_new_text_x                                             0x4F1440
#define msgTokenTextParam_x                                        0x4EDF20
