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
#define __ExpectedVersionDate                                     "Jul 12 2016"
#define __ExpectedVersionTime                                     "15:55:32"
#define __ActualVersionDate_x                                      0xACF230
#define __ActualVersionTime_x                                      0xACF23C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59D670
#define __MemChecker1_x                                            0x8972A0
#define __MemChecker2_x                                            0x634350
#define __MemChecker3_x                                            0x6342A0
#define __MemChecker4_x                                            0x7E63D0
#define __EncryptPad0_x                                            0xC6D8E8
#define __EncryptPad1_x                                            0xDF8440
#define __EncryptPad2_x                                            0xCB63E8
#define __EncryptPad3_x                                            0xCB5FE8
#define __EncryptPad4_x                                            0xDCF010
#define __EncryptPad5_x                                            0x11A8D30
#define __AC1_x                                                    0x7A63C5
#define __AC2_x                                                    0x557687
#define __AC3_x                                                    0x555820
#define __AC4_x                                                    0x568030
#define __AC5_x                                                    0x57AB7B
#define __AC6_x                                                    0x57E74E
#define __AC7_x                                                    0x57523C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E567C

// Direct Input
#define DI8__Main_x                                                0x11A8D08
#define DI8__Keyboard_x                                            0x11A8D0C
#define DI8__Mouse_x                                               0x11A8D10
#define DI8__Mouse_Copy_x                                          0x10173FC
#define DI8__Mouse_Check_x                                         0x10A0BF4
#define __Attack_x                                                 0x109B8D7
#define __Autofire_x                                               0x109B8D8
#define __BindList_x                                               0xC2F4E8
#define g_eqCommandStates_x                                        0x1006860
#define __Clicks_x                                                 0x10174B8
#define __CommandList_x                                            0xC338B8
#define __CurrentMapLabel_x                                        0x11AE790
#define __CurrentSocial_x                                          0xBE5FD0
#define __DoAbilityList_x                                          0x104DB8C
#define __do_loot_x                                                0x51C350
#define __DrawHandler_x                                            0x1815714
#define __GroupCount_x                                             0x1007E2A

#define __Guilds_x                                                 0x100DA40
#define __gWorld_x                                                 0x100A2E4
#define __HotkeyPage_x                                             0x109458C
#define __HWnd_x                                                   0x10A0C10
#define __InChatMode_x                                             0x10173E4
#define __LastTell_x                                               0x1019288
#define __LMouseHeldTime_x                                         0x1017524
#define __Mouse_x                                                  0x11A8D14
#define __MouseLook_x                                              0x101747E
#define __MouseEventTime_x                                         0x109C0DC
#define __gpbCommandEvent_x                                        0x100A3AC
#define __NetStatusToggle_x                                        0x1017481
#define __PCNames_x                                                0x10188A8
#define __RangeAttackReady_x                                       0x10185E4
#define __RMouseHeldTime_x                                         0x1017520
#define __RunWalkState_x                                           0x10173E8
#define __ScreenMode_x                                             0xF565E0
#define __ScreenX_x                                                0x101739C
#define __ScreenY_x                                                0x1017398
#define __ScreenXMax_x                                             0x10173A0
#define __ScreenYMax_x                                             0x10173A4
#define __ServerHost_x                                             0x1007D74
#define __ServerName_x                                             0x104DB4C
#define __ShiftKeyDown_x                                           0x1017A70
#define __ShowNames_x                                              0x10187A4
#define __Socials_x                                                0x104DC4C
#define __SubscriptionType_x                                       0x11DC8BC
#define __TargetAggroHolder_x                                      0x11B09CC
#define __ZoneType_x                                               0x101787C
#define __GroupAggro_x                                             0x11B0A0C
#define __LoginName_x                                              0x109F7EC
#define __Inviter_x                                                0x109B854
#define __AttackOnAssist_x                                         0x1018760
#define __UseTellWindows_x                                         0x1018A40

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x100A3D0
#define instEQZoneInfo_x                                           0x1017674
#define instKeypressHandler_x                                      0x109C0C0
#define pinstActiveBanker_x                                        0x100A388
#define pinstActiveCorpse_x                                        0x100A38C
#define pinstActiveGMaster_x                                       0x100A390
#define pinstActiveMerchant_x                                      0x100A384
#define pinstAggroInfo_x                                           0xE14108
#define pinstAltAdvManager_x                                       0xF576A0
#define pinstAuraMgr_x                                             0xE24878
#define pinstBandageTarget_x                                       0x100A370
#define pinstCamActor_x                                            0xF56FF4
#define pinstCDBStr_x                                              0xF56574
#define pinstCDisplay_x                                            0x100A398
#define pinstCEverQuest_x                                          0x11A8E88
#define pinstCharData_x                                            0x100A354
#define pinstCharSpawn_x                                           0x100A37C
#define pinstControlledMissile_x                                   0x100A350
#define pinstControlledPlayer_x                                    0x100A37C
#define pinstCSidlManager_x                                        0x1814B04
#define pinstCXWndManager_x                                        0x1814AFC
#define instDynamicZone_x                                          0x1017230
#define pinstDZMember_x                                            0x1017340
#define pinstDZTimerInfo_x                                         0x1017344
#define pinstEQItemList_x                                          0x1006AB0
#define pinstEQObjectList_x                                        0x1007824
#define instEQMisc_x                                               0xC09D40
#define pinstEQSoundManager_x                                      0xF57BF8
#define instExpeditionLeader_x                                     0x101727A
#define instExpeditionName_x                                       0x10172BA
#define pinstGroup_x                                               0x1007E26
#define pinstImeManager_x                                          0x1814B08
#define pinstLocalPlayer_x                                         0x100A368
#define pinstMercenaryData_x                                       0x109C740
#define pinstMercenaryStats_x                                      0x11B0B18
#define pinstMercAltAbilities_x                                    0xF57A28
#define pinstModelPlayer_x                                         0x100A394
#define pinstPCData_x                                              0x100A354
#define pinstSkillMgr_x                                            0x109D5A8
#define pinstSpawnManager_x                                        0x109CE90
#define pinstSpellManager_x                                        0x109D6F0
#define pinstSpellSets_x                                           0x10945F0
#define pinstStringTable_x                                         0x100A2FC
#define pinstSwitchManager_x                                       0x10079B8
#define pinstTarget_x                                              0x100A380
#define pinstTargetObject_x                                        0x100A358
#define pinstTargetSwitch_x                                        0x100A35C
#define pinstTaskMember_x                                          0xF564C0
#define pinstTrackTarget_x                                         0x100A374
#define pinstTradeTarget_x                                         0x100A364
#define instTributeActive_x                                        0xC09D65
#define pinstViewActor_x                                           0xF56FF0
#define pinstWorldData_x                                           0x100A338
#define pinstZoneAddr_x                                            0x1017914
#define pinstPlayerPath_x                                          0x109CEF0
#define pinstTargetIndicator_x                                     0x109D888
#define pinstCTargetManager_x                                      0x109D8E8

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE14600
#define pinstCAudioTriggersWindow_x                                0xE14490
#define pinstCCharacterSelect_x                                    0xF56E84
#define pinstCFacePick_x                                           0xF56C34
#define pinstCNoteWnd_x                                            0xF56E3C
#define pinstCBookWnd_x                                            0xF56E44
#define pinstCPetInfoWnd_x                                         0xF56E48
#define pinstCTrainWnd_x                                           0xF56E4C
#define pinstCSkillsWnd_x                                          0xF56E50
#define pinstCSkillsSelectWnd_x                                    0xF56E54
#define pinstCCombatSkillsSelectWnd_x                              0xF56E58
#define pinstCFriendsWnd_x                                         0xF56E5C
#define pinstCAuraWnd_x                                            0xF56E60
#define pinstCRespawnWnd_x                                         0xF56E64
#define pinstCBandolierWnd_x                                       0xF56E68
#define pinstCPotionBeltWnd_x                                      0xF56E6C
#define pinstCAAWnd_x                                              0xF56E70
#define pinstCGroupSearchFiltersWnd_x                              0xF56E74
#define pinstCLoadskinWnd_x                                        0xF56E78
#define pinstCAlarmWnd_x                                           0xF56E7C
#define pinstCMusicPlayerWnd_x                                     0xF56E80
#define pinstCMailWnd_x                                            0xF56E88
#define pinstCMailCompositionWnd_x                                 0xF56E8C
#define pinstCMailAddressBookWnd_x                                 0xF56E90
#define pinstCRaidWnd_x                                            0xF56E98
#define pinstCRaidOptionsWnd_x                                     0xF56E9C
#define pinstCBreathWnd_x                                          0xF56EA0
#define pinstCMapViewWnd_x                                         0xF56EA4
#define pinstCMapToolbarWnd_x                                      0xF56EA8
#define pinstCEditLabelWnd_x                                       0xF56EAC
#define pinstCTargetWnd_x                                          0xF56EB0
#define pinstCColorPickerWnd_x                                     0xF56EB4
#define pinstCPlayerWnd_x                                          0xF56EB8
#define pinstCOptionsWnd_x                                         0xF56EBC
#define pinstCBuffWindowNORMAL_x                                   0xF56EC0
#define pinstCBuffWindowSHORT_x                                    0xF56EC4
#define pinstCharacterCreation_x                                   0xF56EC8
#define pinstCCursorAttachment_x                                   0xF56ECC
#define pinstCCastingWnd_x                                         0xF56ED0
#define pinstCCastSpellWnd_x                                       0xF56ED4
#define pinstCSpellBookWnd_x                                       0xF56ED8
#define pinstCInventoryWnd_x                                       0xF56EDC
#define pinstCBankWnd_x                                            0xF56EE4
#define pinstCQuantityWnd_x                                        0xF56EE8
#define pinstCLootWnd_x                                            0xF56EEC
#define pinstCActionsWnd_x                                         0xF56EF0
#define pinstCCombatAbilityWnd_x                                   0xF56EF4
#define pinstCMerchantWnd_x                                        0xF56EF8
#define pinstCTradeWnd_x                                           0xF56EFC
#define pinstCSelectorWnd_x                                        0xF56F00
#define pinstCBazaarWnd_x                                          0xF56F04
#define pinstCBazaarSearchWnd_x                                    0xF56F08
#define pinstCGiveWnd_x                                            0xF56F24
#define pinstCTrackingWnd_x                                        0xF56F2C
#define pinstCInspectWnd_x                                         0xF56F30
#define pinstCSocialEditWnd_x                                      0xF56F34
#define pinstCFeedbackWnd_x                                        0xF56F38
#define pinstCBugReportWnd_x                                       0xF56F3C
#define pinstCVideoModesWnd_x                                      0xF56F40
#define pinstCTextEntryWnd_x                                       0xF56F48
#define pinstCFileSelectionWnd_x                                   0xF56F4C
#define pinstCCompassWnd_x                                         0xF56F50
#define pinstCPlayerNotesWnd_x                                     0xF56F54
#define pinstCGemsGameWnd_x                                        0xF56F58
#define pinstCTimeLeftWnd_x                                        0xF56F5C
#define pinstCPetitionQWnd_x                                       0xF56F78
#define pinstCSoulmarkWnd_x                                        0xF56F7C
#define pinstCStoryWnd_x                                           0xF56F80
#define pinstCJournalTextWnd_x                                     0xF56F84
#define pinstCJournalCatWnd_x                                      0xF56F88
#define pinstCBodyTintWnd_x                                        0xF56F8C
#define pinstCServerListWnd_x                                      0xF56F90
#define pinstCAvaZoneWnd_x                                         0xF56F9C
#define pinstCBlockedBuffWnd_x                                     0xF56FA0
#define pinstCBlockedPetBuffWnd_x                                  0xF56FA4
#define pinstCInvSlotMgr_x                                         0xF56FE8
#define pinstCContainerMgr_x                                       0xF56FEC
#define pinstCAdventureLeaderboardWnd_x                            0x11A9838
#define pinstCAdventureRequestWnd_x                                0x11A98B0
#define pinstCAltStorageWnd_x                                      0x11A9B90
#define pinstCAdventureStatsWnd_x                                  0x11A9928
#define pinstCBarterMerchantWnd_x                                  0x11AA778
#define pinstCBarterSearchWnd_x                                    0x11AA7F0
#define pinstCBarterWnd_x                                          0x11AA868
#define pinstCChatManager_x                                        0x11AAEF8
#define pinstCDynamicZoneWnd_x                                     0x11AB3A8
#define pinstCEQMainWnd_x                                          0x11AB540
#define pinstCFellowshipWnd_x                                      0x11AB33C
#define pinstCFindLocationWnd_x                                    0x11AB810
#define pinstCGroupSearchWnd_x                                     0x11ABAE0
#define pinstCGroupWnd_x                                           0x11ABB58
#define pinstCGuildBankWnd_x                                       0x11ABBD0
#define pinstCGuildMgmtWnd_x                                       0x11ADCC0
#define pinstCHotButtonWnd_x                                       0x11ADDBC
#define pinstCHotButtonWnd1_x                                      0x11ADDBC
#define pinstCHotButtonWnd2_x                                      0x11ADDC0
#define pinstCHotButtonWnd3_x                                      0x11ADDC4
#define pinstCHotButtonWnd4_x                                      0x11ADDE8
#define pinstCItemDisplayManager_x                                 0x11AE0E0
#define pinstCItemExpTransferWnd_x                                 0x11AE15C
#define pinstCLFGuildWnd_x                                         0x11AE438
#define pinstCMIZoneSelectWnd_x                                    0x11AEA20
#define pinstCConfirmationDialog_x                                 0x11AF128
#define pinstCPopupWndManager_x                                    0x11AF128
#define pinstCProgressionSelectionWnd_x                            0x11AF218
#define pinstCPvPStatsWnd_x                                        0x11AF308
#define pinstCSystemInfoDialogBox_x                                0x11AFA10
#define pinstCTaskWnd_x                                            0x11B0DD8
#define pinstCTaskSomething_x                                      0xE25068
#define pinstCTaskTemplateSelectWnd_x                              0x11B0D60
#define pinstCTipWndOFDAY_x                                        0x11B0F40
#define pinstCTipWndCONTEXT_x                                      0x11B0F44
#define pinstCTitleWnd_x                                           0x11B0FC0
#define pinstCContextMenuManager_x                                 0x1814A74
#define pinstCVoiceMacroWnd_x                                      0x109DCC0
#define pinstCHtmlWnd_x                                            0x109DDB0
#define pinstIconCache_x                                           0x11AB514
#define pinstCTradeskillWnd_x                                      0x11B10C0
#define pinstCAdvancedLootWnd_x                                    0xF56FDC
#define pinstRewardSelectionWnd_x                                  0x11AF830

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5334B0
#define __ConvertItemTags_x                                        0x520EB0
#define __ExecuteCmd_x                                             0x50B860
#define __EQGetTime_x                                              0x896ED0
#define __get_melee_range_x                                        0x512430
#define __GetGaugeValueFromEQ_x                                    0x7A5100
#define __GetLabelFromEQ_x                                         0x7A6350
#define __ToggleKeyRingItem_x                                      0x47E790
#define __GetXTargetType_x                                         0x927F00
#define __LoadFrontEnd_x                                           0x633A20
#define __NewUIINI_x                                               0x7A4AD0
#define __ProcessGameEvents_x                                      0x576FA0
#define __ProcessMouseEvent_x                                      0x576740
#define CrashDetected_x                                            0x6353E0
#define wwsCrashReportCheckForUploader_x                           0x7F4E60
#define DrawNetStatus_x                                            0x5AD200
#define Util__FastTime_x                                           0x8969E0
#define Expansion_HoT_x                                            0x1018750
#define __HelpPath_x                                               0x109BE48
#define __STMLToText_x                                             0x8DCB10

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4204C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B310
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B0F0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C55B0
#define AltAdvManager__IsAbilityReady_x                            0x4C5620
#define AltAdvManager__GetAAById_x                                 0x4C59E0
#define AltAdvManager__CanTrainAbility_x                           0x4C62A0
#define AltAdvManager__CanSeeAbility_x                             0x4C5EA0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463220
#define CharacterZoneClient__MakeMeVisible_x                       0x468B20
#define CharacterZoneClient__IsStackBlocked_x                      0x4475B0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x446A70
#define CharacterZoneClient__GetItemCountWorn_x                    0x460BF0
#define CharacterZoneClient__GetItemCountInInventory_x             0x460CD0
#define CharacterZoneClient__GetCursorItemCount_x                  0x460DB0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x663640

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x671D80

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58C610
#define CButtonWnd__CButtonWnd_x                                   0x8D0E90

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68CAB0
#define CChatManager__InitContextMenu_x                            0x68D630

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DAE70
#define CContextMenu__dCContextMenu_x                              0x8DB080
#define CContextMenu__AddMenuItem_x                                0x8DB090
#define CContextMenu__RemoveMenuItem_x                             0x8DB380
#define CContextMenu__RemoveAllMenuItems_x                         0x8DB3A0
#define CContextMenuManager__AddMenu_x                             0x8C7450
#define CContextMenuManager__RemoveMenu_x                          0x8C77A0
#define CContextMenuManager__PopupMenu_x                           0x8C7BF0
#define CContextMenuManager__Flush_x                               0x8C74C0
#define CContextMenuManager__GetMenu_x                             0x416920

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87B990
#define CChatService__GetFriendName_x                              0x87B9A0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x692890
#define CChatWindow__Clear_x                                       0x692460
#define CChatWindow__WndNotification_x                             0x692DC0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CB260
#define CComboWnd__Draw_x                                          0x8CB470
#define CComboWnd__GetCurChoice_x                                  0x8CB020
#define CComboWnd__GetListRect_x                                   0x8CB710
#define CComboWnd__GetTextRect_x                                   0x8CB2D0
#define CComboWnd__InsertChoice_x                                  0x8CB780
#define CComboWnd__SetColors_x                                     0x8CAFB0
#define CComboWnd__SetChoice_x                                     0x8CAFE0
#define CComboWnd__GetItemCount_x                                  0x8CB010
#define CComboWnd__GetCurChoiceText_x                              0x8CB060


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69BDE0
#define CContainerWnd__vftable_x                                   0xAD8C28

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B3B80
#define CDisplay__GetClickedActor_x                                0x4AC440
#define CDisplay__GetUserDefinedColor_x                            0x4AB020
#define CDisplay__GetWorldFilePath_x                               0x4AA470
#define CDisplay__is3dON_x                                         0x4A9900
#define CDisplay__ReloadUI_x                                       0x4BF070
#define CDisplay__WriteTextHD2_x                                   0x4AFED0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F1500

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DF3A0
#define CEditWnd__GetCharIndexPt_x                                 0x8E0430
#define CEditWnd__GetDisplayString_x                               0x8DF550
#define CEditWnd__GetHorzOffset_x                                  0x8DF890
#define CEditWnd__GetLineForPrintableChar_x                        0x8DFF00
#define CEditWnd__GetSelStartPt_x                                  0x8E06E0
#define CEditWnd__GetSTMLSafeText_x                                0x8DFA30
#define CEditWnd__PointFromPrintableChar_x                         0x8DFFF0
#define CEditWnd__SelectableCharFromPoint_x                        0x8E0170
#define CEditWnd__SetEditable_x                                    0x8DFA00

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x557DD0
#define CEverQuest__CreateTargetIndicator_x                        0x558CC0
#define CEverQuest__DeleteTargetIndicator_x                        0x558D40
#define CEverQuest__DoTellWindow_x                                 0x473760
#define CEverQuest__DropHeldItemOnGround_x                         0x56EE70
#define CEverQuest__dsp_chat_x                                     0x473AA0
#define CEverQuest__trimName_x                                     0x554720
#define CEverQuest__Emote_x                                        0x56D1C0
#define CEverQuest__EnterZone_x                                    0x5681C0
#define CEverQuest__GetBodyTypeDesc_x                              0x552180
#define CEverQuest__GetClassDesc_x                                 0x55BA50
#define CEverQuest__GetClassThreeLetterCode_x                      0x55C050
#define CEverQuest__GetDeityDesc_x                                 0x552A60
#define CEverQuest__GetLangDesc_x                                  0x552510
#define CEverQuest__GetRaceDesc_x                                  0x55C210
#define CEverQuest__InterpretCmd_x                                 0x560020
#define CEverQuest__LeftClickedOnPlayer_x                          0x573690
#define CEverQuest__LMouseUp_x                                     0x575790
#define CEverQuest__RightClickedOnPlayer_x                         0x5741A0
#define CEverQuest__RMouseUp_x                                     0x5751F0
#define CEverQuest__SetGameState_x                                 0x558690
#define CEverQuest__UPCNotificationFlush_x                         0x54FFA0
#define CEverQuest__IssuePetCommand_x                              0x560A00

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AC9D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6ACA30
#define CGaugeWnd__Draw_x                                          0x6ACE60

// CGuild
#define CGuild__FindMemberByName_x                                 0x4372D0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C8E40

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D5EE0
#define CInvSlotMgr__MoveItem_x                                    0x6D6D90
#define CInvSlotMgr__SelectSlot_x                                  0x6D5F90

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D5390
#define CInvSlot__SliderComplete_x                                 0x6D2C00
#define CInvSlot__GetItemBase_x                                    0x6D20A0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D81B0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A0AF0
#define CItemDisplayWnd__UpdateStrings_x                           0x6DA320

// CLabel 
#define CLabel__Draw_x                                             0x6F3990

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B6EF0
#define CListWnd__dCListWnd_x                                      0x8B7F20
#define CListWnd__AddColumn_x                                      0x8B7EC0
#define CListWnd__AddColumn1_x                                     0x8B7740
#define CListWnd__AddLine_x                                        0x8B71B0
#define CListWnd__AddString_x                                      0x8B73D0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B41A0
#define CListWnd__CalculateVSBRange_x                              0x8B63B0
#define CListWnd__ClearSel_x                                       0x8B34B0
#define CListWnd__ClearAllSel_x                                    0x8B3460
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B6D80
#define CListWnd__Compare_x                                        0x8B4D20
#define CListWnd__Draw_x                                           0x8B5FB0
#define CListWnd__DrawColumnSeparators_x                           0x8B5E40
#define CListWnd__DrawHeader_x                                     0x8B3770
#define CListWnd__DrawItem_x                                       0x8B5370
#define CListWnd__DrawLine_x                                       0x8B5AE0
#define CListWnd__DrawSeparator_x                                  0x8B5EE0
#define CListWnd__EnsureVisible_x                                  0x8B4300
#define CListWnd__ExtendSel_x                                      0x8B5280
#define CListWnd__GetColumnMinWidth_x                              0x8B2E60
#define CListWnd__GetColumnWidth_x                                 0x8B2D90
#define CListWnd__GetCurSel_x                                      0x8B2560
#define CListWnd__GetItemAtPoint_x                                 0x8B45A0
#define CListWnd__GetItemAtPoint1_x                                0x8B4610
#define CListWnd__GetItemData_x                                    0x8B28B0
#define CListWnd__GetItemHeight_x                                  0x8B3DF0
#define CListWnd__GetItemIcon_x                                    0x8B2AA0
#define CListWnd__GetItemRect_x                                    0x8B43E0
#define CListWnd__GetItemText_x                                    0x8B2950
#define CListWnd__GetSelList_x                                     0x8B7630
#define CListWnd__GetSeparatorRect_x                               0x8B4C40
#define CListWnd__RemoveLine_x                                     0x8B75B0
#define CListWnd__SetColors_x                                      0x8B26B0
#define CListWnd__SetColumnJustification_x                         0x8B30F0
#define CListWnd__SetColumnWidth_x                                 0x8B2E10
#define CListWnd__SetCurSel_x                                      0x8B25A0
#define CListWnd__SetItemColor_x                                   0x8B6A70
#define CListWnd__SetItemData_x                                    0x8B3510
#define CListWnd__SetItemText_x                                    0x8B68B0
#define CListWnd__ShiftColumnSeparator_x                           0x8B6740
#define CListWnd__Sort_x                                           0x8B8020
#define CListWnd__ToggleSel_x                                      0x8B33E0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70C9B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72DE70
#define CMerchantWnd__RequestBuyItem_x                             0x734F10
#define CMerchantWnd__RequestSellItem_x                            0x7359E0
#define CMerchantWnd__SelectRecoverySlot_x                         0x72E120
#define CMerchantWnd__SelectBuySellSlot_x                          0x72D320
#define CMerchantWnd__ActualSelect_x                               0x731DF0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x848450
#define CPacketScrambler__hton_x                                   0x848460

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D5E80
#define CSidlManager__CreateLabel_x                                0x796A40

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65AA10
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65A930
#define CSidlScreenWnd__ConvertToRes_x                             0x8F13E0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CDC20
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CEDF0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CEEA0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CE370
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CD5D0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CCD20
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CD7C0
#define CSidlScreenWnd__Init1_x                                    0x8CEAC0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CDCD0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CCEE0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CE5B0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CC980
#define CSidlScreenWnd__StoreIniVis_x                              0x8CCCD0
#define CSidlScreenWnd__WndNotification_x                          0x8CE840
#define CSidlScreenWnd__GetChildItem_x                             0x8CCDF0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C0550

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F8770
#define CSkillMgr__GetSkillCap_x                                   0x5F8950
#define CSkillMgr__GetNameToken_x                                  0x5F8390

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F0690
#define CSliderWnd__SetValue_x                                     0x8F0860
#define CSliderWnd__SetNumTicks_x                                  0x8F0FE0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79E740

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EC030
#define CStmlWnd__CalculateHSBRange_x                              0x8E4550
#define CStmlWnd__CalculateVSBRange_x                              0x8E45E0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E4760
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E5040
#define CStmlWnd__ForceParseNow_x                                  0x8EC980
#define CStmlWnd__GetNextTagPiece_x                                0x8E4F40
#define CStmlWnd__GetSTMLText_x                                    0x691D00
#define CStmlWnd__GetVisibleText_x                                 0x8E5A90
#define CStmlWnd__InitializeWindowVariables_x                      0x8E7E20
#define CStmlWnd__MakeStmlColorTag_x                               0x8E3850
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E38B0
#define CStmlWnd__SetSTMLText_x                                    0x8E9680
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EBCD0
#define CStmlWnd__UpdateHistoryString_x                            0x8E69D0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E2F60
#define CTabWnd__DrawCurrentPage_x                                 0x8E27F0
#define CTabWnd__DrawTab_x                                         0x8E25B0
#define CTabWnd__GetCurrentPage_x                                  0x8E2BA0
#define CTabWnd__GetPageInnerRect_x                                0x8E22A0
#define CTabWnd__GetTabInnerRect_x                                 0x8E24A0
#define CTabWnd__GetTabRect_x                                      0x8E2370
#define CTabWnd__InsertPage_x                                      0x8E3250
#define CTabWnd__SetPage_x                                         0x8E2BD0
#define CTabWnd__SetPageRect_x                                     0x8E2EA0
#define CTabWnd__UpdatePage_x                                      0x8E31F0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432E80

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CAC20

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F67E0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B06C0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029D0
#define CXStr__CXStr1_x                                            0x8A56A0
#define CXStr__CXStr3_x                                            0x893AD0
#define CXStr__dCXStr_x                                            0x599F30
#define CXStr__operator_equal_x                                    0x893C40
#define CXStr__operator_equal1_x                                   0x893C90
#define CXStr__operator_plus_equal1_x                              0x894D90

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BF780
#define CXWnd__Center_x                                            0x8C5A10
#define CXWnd__ClrFocus_x                                          0x8BF360
#define CXWnd__DoAllDrawing_x                                      0x8C5660
#define CXWnd__DrawChildren_x                                      0x8C5800
#define CXWnd__DrawColoredRect_x                                   0x8BFB30
#define CXWnd__DrawTooltip_x                                       0x8BFDE0
#define CXWnd__DrawTooltipAtPoint_x                                0x8C45B0
#define CXWnd__GetBorderFrame_x                                    0x8C0200
#define CXWnd__GetChildWndAt_x                                     0x8C63E0
#define CXWnd__GetClientClipRect_x                                 0x8C0000
#define CXWnd__GetScreenClipRect_x                                 0x8C4CB0
#define CXWnd__GetScreenRect_x                                     0x8C03E0
#define CXWnd__GetTooltipRect_x                                    0x8BFC70
#define CXWnd__GetWindowTextA_x                                    0x424460
#define CXWnd__IsActive_x                                          0x8BAD10
#define CXWnd__IsDescendantOf_x                                    0x8C0140
#define CXWnd__IsReallyVisible_x                                   0x8C35C0
#define CXWnd__IsType_x                                            0x8F3060
#define CXWnd__Move_x                                              0x8C2CA0
#define CXWnd__Move1_x                                             0x8C5300
#define CXWnd__ProcessTransition_x                                 0x8BF730
#define CXWnd__Refade_x                                            0x8BF510
#define CXWnd__Resize_x                                            0x8C04B0
#define CXWnd__Right_x                                             0x8C4AB0
#define CXWnd__SetFocus_x                                          0x8C1DF0
#define CXWnd__SetFont_x                                           0x8BF3B0
#define CXWnd__SetKeyTooltip_x                                     0x8C0720
#define CXWnd__SetMouseOver_x                                      0x8C4FF0
#define CXWnd__StartFade_x                                         0x8BF7D0
#define CXWnd__GetChildItem_x                                      0x8C4F30

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BC590
#define CXWndManager__DrawWindows_x                                0x8BC1D0
#define CXWndManager__GetKeyboardFlags_x                           0x8BA840
#define CXWndManager__HandleKeyboardMsg_x                          0x8BB1A0
#define CXWndManager__RemoveWnd_x                                  0x8BAEA0

// CDBStr
#define CDBStr__GetString_x                                        0x4A7DE0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44DA50
#define EQ_Character__Cur_HP_x                                     0x4628C0
#define EQ_Character__Cur_Mana_x                                   0x455FF0
#define EQ_Character__GetAACastingTimeModifier_x                   0x446D80
#define EQ_Character__GetCharInfo2_x                               0x867CA0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EFF0
#define EQ_Character__GetFocusRangeModifier_x                      0x43F050
#define EQ_Character__Max_Endurance_x                              0x5BEF10
#define EQ_Character__Max_HP_x                                     0x458C10
#define EQ_Character__Max_Mana_x                                   0x5BED40
#define EQ_Character__doCombatAbility_x                            0x5BC430
#define EQ_Character__UseSkill_x                                   0x46DBA0
#define EQ_Character__GetConLevel_x                                0x5B1880
#define EQ_Character__IsExpansionFlag_x                            0x4239B0
#define EQ_Character__TotalEffect_x                                0x44ACA0
#define EQ_Character__GetPCSpellAffect_x                           0x447180
#define EQ_Character__SpellDuration_x                              0x445080

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x4423F0
#define CCharacterSelect__EnterWorld_x                             0x441BC0
#define CCharacterSelect__Quit_x                                   0x440720

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x591EA0
#define EQ_Item__CreateItemTagString_x                             0x846E20
#define EQ_Item__IsStackable_x                                     0x83C920
#define EQ_Item__GetImageNum_x                                     0x83F360
#define EQ_Item__CreateItemClient_x                                0x592A80
#define EQ_Item__GetItemValue_x                                    0x845B90
#define EQ_Item__ValueSellMerchant_x                               0x8480B0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C76E0
#define EQ_LoadingS__Array_x                                       0xC16588

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C1430
#define EQ_PC__GetAlternateAbilityId_x                             0x850580
#define EQ_PC__GetCombatAbility_x                                  0x850610
#define EQ_PC__GetCombatAbilityTimer_x                             0x84B270
#define EQ_PC__GetItemTimerValue_x                                 0x5BAB30
#define EQ_PC__HasLoreItem_x                                       0x5B4DB0
#define EQ_PC__AlertInventoryChanged_x                             0x5B1850
#define EQ_PC__GetPcZoneClient_x                                   0x5DBB70
#define EQ_PC__RemoveMyAffect_x                                    0x5B9FE0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5104C0
#define EQItemList__add_object_x                                   0x53CB90
#define EQItemList__add_item_x                                     0x510400
#define EQItemList__delete_item_x                                  0x5108B0
#define EQItemList__FreeItemList_x                                 0x5107B0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A70B0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C6AD0
#define EQPlayer__dEQPlayer_x                                      0x5CF920
#define EQPlayer__DoAttack_x                                       0x5E1880
#define EQPlayer__EQPlayer_x                                       0x5D1D40
#define EQPlayer__SetNameSpriteState_x                             0x5CC8A0
#define EQPlayer__SetNameSpriteTint_x                              0x5C7F10
#define PlayerBase__HasProperty_j_x                                0x924100
#define EQPlayer__IsTargetable_x                                   0x924A00
#define EQPlayer__CanSee_x                                         0x924F20
#define PlayerZoneClient__ChangeHeight_x                           0x5E1740
#define EQPlayer__CanSeeTargetIndicator_x                          0x925010

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D6060
#define EQPlayerManager__GetSpawnByName_x                          0x5D64C0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D6090

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x597F20
#define KeypressHandler__AttachKeyToEqCommand_x                    0x597F60
#define KeypressHandler__ClearCommandStateArray_x                  0x597B10
#define KeypressHandler__HandleKeyDown_x                           0x596470
#define KeypressHandler__HandleKeyUp_x                             0x596790
#define KeypressHandler__SaveKeymapping_x                          0x597BE0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x705340
#define MapViewMap__SaveEx_x                                       0x708670

#define PlayerPointManager__GetAltCurrency_x                       0x862CA0

// StringTable 
#define StringTable__getString_x                                   0x85D8D0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BE9A0
#define PcZoneClient__RemovePetEffect_x                            0x5BB000
#define PcZoneClient__HasAlternateAbility_x                        0x5BB9A0
#define PcZoneClient__GetCurrentMod_x                              0x457FB0
#define PcZoneClient__GetModCap_x                                  0x455800

//Doors
#define EQSwitch__UseSwitch_x                                      0x54E8F0

//IconCache
#define IconCache__GetIcon_x                                       0x6A2390

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x699160
#define CContainerMgr__CloseContainer_x                            0x699980

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7669E0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58B0B0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DF5A0
#define EQ_Spell__SpellAffects_x                                   0x4DCC50
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DCCC0
#define CharacterZoneClient__CalcAffectChange_x                    0x4461B0
#define CLootWnd__LootAll_x                                        0x6FABA0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AD550
#define CTargetWnd__WndNotification_x                              0x7AD040
#define CTargetWnd__UpdateBuffs_x                                  0x7AD730

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B2740

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D8500

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x496FD0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DE9D0
#define CSidlManager__FindAnimation1_x                             0x8D3D70

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CEDF0
#define CAltAbilityData__GetMercMaxRank_x                          0x4CEDA0
#define CAltAbilityData__GetMaxRank_x                              0x4C3C60

//CTargetRing
#define CTargetRing__Cast_x                                        0x588990

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4548F0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x683BF0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x683350

//messages
#define msg_spell_worn_off_x                                       0x4E7010
#define msg_new_text_x                                             0x4F0450
#define msgTokenTextParam_x                                        0x4ECE40

//SpellManager
#define SpellManager__vftable_x                                    0xAB4ED8
#define SpellManager__SpellManager_x                               0x47B6A0
#define Spellmanager__CheckSpellRequirementAssociations_x          0x5FF5C0
