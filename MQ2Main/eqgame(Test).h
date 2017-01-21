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
#if defined(TEST)
#include "eqgame-private(test).h"
#endif
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Jan 20 2017"
#define __ExpectedVersionTime                                     "14:18:09"
#define __ActualVersionDate_x                                      0xAC6A08
#define __ActualVersionTime_x                                      0xAC6A14

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x598120
#define __MemChecker1_x                                            0x88D060
#define __MemChecker2_x                                            0x62DBA0
#define __MemChecker3_x                                            0x62DAF0
#define __MemChecker4_x                                            0x7E0150
#define __EncryptPad0_x                                            0xC20100
#define __EncryptPad1_x                                            0xCFF998
#define __EncryptPad2_x                                            0xC4A2A0
#define __EncryptPad3_x                                            0xC49EA0
#define __EncryptPad4_x                                            0xCED650
#define __EncryptPad5_x                                            0x10A8548
#define __AC1_x                                                    0x79FB35
#define __AC2_x                                                    0x5523B7
#define __AC3_x                                                    0x550550
#define __AC4_x                                                    0x562940
#define __AC5_x                                                    0x57569B
#define __AC6_x                                                    0x57923E
#define __AC7_x                                                    0x56FD0C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FE5620

// Direct Input
#define DI8__Main_x                                                0x10A8520
#define DI8__Keyboard_x                                            0x10A8524
#define DI8__Mouse_x                                               0x10A8528
#define DI8__Mouse_Copy_x                                          0xF16C04
#define DI8__Mouse_Check_x                                         0xFA040C
#define __Attack_x                                                 0xF9B0F3
#define __Autofire_x                                               0xF9B0F4
#define __BindList_x                                               0xBFA608
#define g_eqCommandStates_x                                        0xF05C30
#define __Clicks_x                                                 0xF16CC0
#define __CommandList_x                                            0xBFCD10
#define __CurrentMapLabel_x                                        0x10ADFA8
#define __CurrentSocial_x                                          0xBCC99C
#define __DoAbilityList_x                                          0xF4D3A8
#define __do_loot_x                                                0x5213C0
#define __DrawHandler_x                                            0x1714EAC
#define __GroupCount_x                                             0xF0725A

#define __Guilds_x                                                 0xF0CE70
#define __gWorld_x                                                 0xF09714
#define __HotkeyPage_x                                             0xF93DA8
#define __HWnd_x                                                   0xFA0428
#define __InChatMode_x                                             0xF16BEC
#define __LastTell_x                                               0xF18AA4
#define __LMouseHeldTime_x                                         0xF16D2C
#define __Mouse_x                                                  0x10A852C
#define __MouseLook_x                                              0xF16C86
#define __MouseEventTime_x                                         0xF9B8F4
#define __gpbCommandEvent_x                                        0xF097DC
#define __NetStatusToggle_x                                        0xF16C89
#define __PCNames_x                                                0xF180C0
#define __RangeAttackReady_x                                       0xF17DF4
#define __RMouseHeldTime_x                                         0xF16D28
#define __RunWalkState_x                                           0xF16BF0
#define __ScreenMode_x                                             0xE55928
#define __ScreenX_x                                                0xF16BA4
#define __ScreenY_x                                                0xF16BA0
#define __ScreenXMax_x                                             0xF16BA8
#define __ScreenYMax_x                                             0xF16BAC
#define __ServerHost_x                                             0xF071A4
#define __ServerName_x                                             0xF4D368
#define __ShiftKeyDown_x                                           0xF17280
#define __ShowNames_x                                              0xF17FB4
#define __Socials_x                                                0xF4D468
#define __SubscriptionType_x                                       0x10DBFBC
#define __TargetAggroHolder_x                                      0x10B01F0
#define __ZoneType_x                                               0xF17084
#define __GroupAggro_x                                             0x10B0230
#define __LoginName_x                                              0xF9F004
#define __Inviter_x                                                0xF9B070
#define __AttackOnAssist_x                                         0xF17F70
#define __UseTellWindows_x                                         0xF18258

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF09800
#define instEQZoneInfo_x                                           0xF16E7C
#define instKeypressHandler_x                                      0xF9B8D8
#define pinstActiveBanker_x                                        0xF097B8
#define pinstActiveCorpse_x                                        0xF097BC
#define pinstActiveGMaster_x                                       0xF097C0
#define pinstActiveMerchant_x                                      0xF097B4
#define pinstAggroInfo_x                                           0xD13388
#define pinstAltAdvManager_x                                       0xE569F8
#define pinstAuraMgr_x                                             0xD23AF8
#define pinstBandageTarget_x                                       0xF097A0
#define pinstCamActor_x                                            0xE56348
#define pinstCDBStr_x                                              0xE558BC
#define pinstCDisplay_x                                            0xF097C8
#define pinstCEverQuest_x                                          0x10A86A0
#define pinstCharData_x                                            0xF09784
#define pinstCharSpawn_x                                           0xF097AC
#define pinstControlledMissile_x                                   0xF09780
#define pinstControlledPlayer_x                                    0xF097AC
#define pinstCSidlManager_x                                        0x171429C
#define pinstCXWndManager_x                                        0x1714294
#define instDynamicZone_x                                          0xF16A38
#define pinstDZMember_x                                            0xF16B48
#define pinstDZTimerInfo_x                                         0xF16B4C
#define pinstEQItemList_x                                          0xF05E80
#define pinstEQObjectList_x                                        0xF06C54
#define instEQMisc_x                                               0xBE27A0
#define pinstEQSoundManager_x                                      0xE56FC8
#define instExpeditionLeader_x                                     0xF16A82
#define instExpeditionName_x                                       0xF16AC2
#define pinstGroup_x                                               0xF07256
#define pinstImeManager_x                                          0x17142A0
#define pinstLocalPlayer_x                                         0xF09798
#define pinstMercenaryData_x                                       0xF9BF58
#define pinstMercenaryStats_x                                      0x10B033C
#define pinstMercAltAbilities_x                                    0xE56D80
#define pinstModelPlayer_x                                         0xF097C4
#define pinstPCData_x                                              0xF09784
#define pinstSkillMgr_x                                            0xF9CDC0
#define pinstSpawnManager_x                                        0xF9C6A8
#define pinstSpellManager_x                                        0xF9CF08
#define pinstSpellSets_x                                           0xF93E0C
#define pinstStringTable_x                                         0xF0972C
#define pinstSwitchManager_x                                       0xF06DE8
#define pinstTarget_x                                              0xF097B0
#define pinstTargetObject_x                                        0xF09788
#define pinstTargetSwitch_x                                        0xF0978C
#define pinstTaskMember_x                                          0xE55808
#define pinstTrackTarget_x                                         0xF097A4
#define pinstTradeTarget_x                                         0xF09794
#define instTributeActive_x                                        0xBE27C5
#define pinstViewActor_x                                           0xE56344
#define pinstWorldData_x                                           0xF09768
#define pinstZoneAddr_x                                            0xF1711C
#define pinstPlayerPath_x                                          0xF9C708
#define pinstTargetIndicator_x                                     0xF9D0A0
#define pinstCTargetManager_x                                      0xF9D100
#define EQObject_Top_x                                             0xF09778
#define pinstRealEstateItems_x                                     0xF9CCAC

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE56260
#define pinstCAchievementsWnd_x                                    0xE562BC
#define pinstCTextOverlay_x                                        0xD13880
#define pinstCAudioTriggersWindow_x                                0xD13710
#define pinstCCharacterSelect_x                                    0xE561D4
#define pinstCFacePick_x                                           0xE55F84
#define pinstCNoteWnd_x                                            0xE5618C
#define pinstCBookWnd_x                                            0xE56194
#define pinstCPetInfoWnd_x                                         0xE56198
#define pinstCTrainWnd_x                                           0xE5619C
#define pinstCSkillsWnd_x                                          0xE561A0
#define pinstCSkillsSelectWnd_x                                    0xE561A4
#define pinstCCombatSkillsSelectWnd_x                              0xE561A8
#define pinstCFriendsWnd_x                                         0xE561AC
#define pinstCAuraWnd_x                                            0xE561B0
#define pinstCRespawnWnd_x                                         0xE561B4
#define pinstCBandolierWnd_x                                       0xE561B8
#define pinstCPotionBeltWnd_x                                      0xE561BC
#define pinstCAAWnd_x                                              0xE561C0
#define pinstCGroupSearchFiltersWnd_x                              0xE561C4
#define pinstCLoadskinWnd_x                                        0xE561C8
#define pinstCAlarmWnd_x                                           0xE561CC
#define pinstCMusicPlayerWnd_x                                     0xE561D0
#define pinstCMailWnd_x                                            0xE561D8
#define pinstCMailCompositionWnd_x                                 0xE561DC
#define pinstCMailAddressBookWnd_x                                 0xE561E0
#define pinstCRaidWnd_x                                            0xE561E8
#define pinstCRaidOptionsWnd_x                                     0xE561EC
#define pinstCBreathWnd_x                                          0xE561F0
#define pinstCMapViewWnd_x                                         0xE561F4
#define pinstCMapToolbarWnd_x                                      0xE561F8
#define pinstCEditLabelWnd_x                                       0xE561FC
#define pinstCTargetWnd_x                                          0xE56200
#define pinstCColorPickerWnd_x                                     0xE56204
#define pinstCPlayerWnd_x                                          0xE56208
#define pinstCOptionsWnd_x                                         0xE5620C
#define pinstCBuffWindowNORMAL_x                                   0xE56210
#define pinstCBuffWindowSHORT_x                                    0xE56214
#define pinstCharacterCreation_x                                   0xE56218
#define pinstCCursorAttachment_x                                   0xE5621C
#define pinstCCastingWnd_x                                         0xE56220
#define pinstCCastSpellWnd_x                                       0xE56224
#define pinstCSpellBookWnd_x                                       0xE56228
#define pinstCInventoryWnd_x                                       0xE5622C
#define pinstCBankWnd_x                                            0xE56234
#define pinstCQuantityWnd_x                                        0xE56238
#define pinstCLootWnd_x                                            0xE5623C
#define pinstCActionsWnd_x                                         0xE56240
#define pinstCCombatAbilityWnd_x                                   0xE56248
#define pinstCMerchantWnd_x                                        0xE5624C
#define pinstCTradeWnd_x                                           0xE56250
#define pinstCSelectorWnd_x                                        0xE56254
#define pinstCBazaarWnd_x                                          0xE56258
#define pinstCBazaarSearchWnd_x                                    0xE5625C
#define pinstCGiveWnd_x                                            0xE56278
#define pinstCTrackingWnd_x                                        0xE56280
#define pinstCInspectWnd_x                                         0xE56284
#define pinstCSocialEditWnd_x                                      0xE56288
#define pinstCFeedbackWnd_x                                        0xE5628C
#define pinstCBugReportWnd_x                                       0xE56290
#define pinstCVideoModesWnd_x                                      0xE56294
#define pinstCTextEntryWnd_x                                       0xE5629C
#define pinstCFileSelectionWnd_x                                   0xE562A0
#define pinstCCompassWnd_x                                         0xE562A4
#define pinstCPlayerNotesWnd_x                                     0xE562A8
#define pinstCGemsGameWnd_x                                        0xE562AC
#define pinstCTimeLeftWnd_x                                        0xE562B0
#define pinstCPetitionQWnd_x                                       0xE562CC
#define pinstCSoulmarkWnd_x                                        0xE562D0
#define pinstCStoryWnd_x                                           0xE562D4
#define pinstCJournalTextWnd_x                                     0xE562D8
#define pinstCJournalCatWnd_x                                      0xE562DC
#define pinstCBodyTintWnd_x                                        0xE562E0
#define pinstCServerListWnd_x                                      0xE562E4
#define pinstCAvaZoneWnd_x                                         0xE562F0
#define pinstCBlockedBuffWnd_x                                     0xE562F4
#define pinstCBlockedPetBuffWnd_x                                  0xE562F8
#define pinstCInvSlotMgr_x                                         0xE5633C
#define pinstCContainerMgr_x                                       0xE56340
#define pinstCAdventureLeaderboardWnd_x                            0x10A9050
#define pinstCAdventureRequestWnd_x                                0x10A90C8
#define pinstCAltStorageWnd_x                                      0x10A93A8
#define pinstCAdventureStatsWnd_x                                  0x10A9140
#define pinstCBarterMerchantWnd_x                                  0x10A9F90
#define pinstCBarterSearchWnd_x                                    0x10AA008
#define pinstCBarterWnd_x                                          0x10AA080
#define pinstCChatWindowManager_x                                  0x10AA710
#define pinstCDynamicZoneWnd_x                                     0x10AABC0
#define pinstCEQMainWnd_x                                          0x10AAD58
#define pinstCFellowshipWnd_x                                      0x10AAB54
#define pinstCFindLocationWnd_x                                    0x10AB028
#define pinstCGroupSearchWnd_x                                     0x10AB2F8
#define pinstCGroupWnd_x                                           0x10AB370
#define pinstCGuildBankWnd_x                                       0x10AB3E8
#define pinstCGuildMgmtWnd_x                                       0x10AD4D8
#define pinstCHotButtonWnd_x                                       0x10AD5D4
#define pinstCHotButtonWnd1_x                                      0x10AD5D4
#define pinstCHotButtonWnd2_x                                      0x10AD5D8
#define pinstCHotButtonWnd3_x                                      0x10AD5DC
#define pinstCHotButtonWnd4_x                                      0x10AD600
#define pinstCItemDisplayManager_x                                 0x10AD8F8
#define pinstCItemExpTransferWnd_x                                 0x10AD974
#define pinstCLFGuildWnd_x                                         0x10ADC50
#define pinstCMIZoneSelectWnd_x                                    0x10AE238
#define pinstCConfirmationDialog_x                                 0x10AE940
#define pinstCPopupWndManager_x                                    0x10AE940
#define pinstCProgressionSelectionWnd_x                            0x10AEA30
#define pinstCPvPStatsWnd_x                                        0x10AEB20
#define pinstCLargeDialogWnd_x                                     0x10AF228
#define pinstCTaskWnd_x                                            0x10B05F8
#define pinstCTaskSomething_x                                      0xD243B0
#define pinstCTaskTemplateSelectWnd_x                              0x10B0580
#define pinstCTipWndOFDAY_x                                        0x10B0760
#define pinstCTipWndCONTEXT_x                                      0x10B0764
#define pinstCTitleWnd_x                                           0x10B07E0
#define pinstCContextMenuManager_x                                 0x171420C
#define pinstCVoiceMacroWnd_x                                      0xF9D4D8
#define pinstCHtmlWnd_x                                            0xF9D5C8
#define pinstIconCache_x                                           0x10AAD2C
#define pinstCTradeskillWnd_x                                      0x10B08E0
#define pinstCAdvancedLootWnd_x                                    0xE56330
#define pinstRewardSelectionWnd_x                                  0x10AF048

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x538300
#define __ConvertItemTags_x                                        0x525F20
#define __ExecuteCmd_x                                             0x510650
#define __EQGetTime_x                                              0x88CCF0
#define __get_melee_range_x                                        0x517220
#define __GetGaugeValueFromEQ_x                                    0x79E870
#define __GetLabelFromEQ_x                                         0x79FAC0
#define __ToggleKeyRingItem_x                                      0x480150
#define __GetXTargetType_x                                         0x91D8C0
#define __LoadFrontEnd_x                                           0x62D270
#define __NewUIINI_x                                               0x79E250
#define __ProcessGameEvents_x                                      0x571AA0
#define __ProcessMouseEvent_x                                      0x571240
#define CrashDetected_x                                            0x62EC30
#define wwsCrashReportCheckForUploader_x                           0x7EC1A0
#define DrawNetStatus_x                                            0x5A7B40
#define Util__FastTime_x                                           0x88C990
#define Expansion_HoT_x                                            0xF17F60
#define __HelpPath_x                                               0xF9B660
#define __STMLToText_x                                             0x8D2C90

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420430
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B1D0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41AFB0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C7510
#define AltAdvManager__IsAbilityReady_x                            0x4C7580
#define AltAdvManager__GetAAById_x                                 0x4C7A70
#define AltAdvManager__CanTrainAbility_x                           0x4C86A0
#define AltAdvManager__CanSeeAbility_x                             0x4C8260

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4636C0
#define CharacterZoneClient__MakeMeVisible_x                       0x4680D0
#define CharacterZoneClient__IsStackBlocked_x                      0x447AA0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x446F60
#define CharacterZoneClient__GetItemCountWorn_x                    0x461450
#define CharacterZoneClient__GetItemCountInInventory_x             0x461530
#define CharacterZoneClient__GetCursorItemCount_x                  0x461610

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x65CA40

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66AD80

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5870C0
#define CButtonWnd__CButtonWnd_x                                   0x8C7020

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x685F40
#define CChatManager__InitContextMenu_x                            0x686AC0
#define CChatManager__FreeChatWindow_x                             0x685A20
#define CChatManager__GetLockedActiveChatWindow_x                  0x68B270
#define CChatManager__SetLockedActiveChatWindow_x                  0x685F10
// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D0FF0
#define CContextMenu__dCContextMenu_x                              0x8D1200
#define CContextMenu__AddMenuItem_x                                0x8D1210
#define CContextMenu__RemoveMenuItem_x                             0x8D1500
#define CContextMenu__RemoveAllMenuItems_x                         0x8D1520
#define CContextMenuManager__AddMenu_x                             0x8BD570
#define CContextMenuManager__RemoveMenu_x                          0x8BD900
#define CContextMenuManager__PopupMenu_x                           0x8BDD50
#define CContextMenuManager__Flush_x                               0x8BD5E0
#define CContextMenuManager__GetMenu_x                             0x4168B0
#define CContextMenu__CheckMenuItem_x                              0x8D15A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8711F0
#define CChatService__GetFriendName_x                              0x871200

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x68BDB0
#define CChatWindow__Clear_x                                       0x68B990
#define CChatWindow__WndNotification_x                             0x68C2E0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C13C0
#define CComboWnd__Draw_x                                          0x8C15D0
#define CComboWnd__GetCurChoice_x                                  0x8C1170
#define CComboWnd__GetListRect_x                                   0x8C1870
#define CComboWnd__GetTextRect_x                                   0x8C1430
#define CComboWnd__InsertChoice_x                                  0x8C18E0
#define CComboWnd__SetColors_x                                     0x8C1100
#define CComboWnd__SetChoice_x                                     0x8C1130
#define CComboWnd__GetItemCount_x                                  0x8C1160
#define CComboWnd__GetCurChoiceText_x                              0x8C11B0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6954C0
#define CContainerWnd__vftable_x                                   0xAD04D0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B5A00
#define CDisplay__GetClickedActor_x                                0x4AE330
#define CDisplay__GetUserDefinedColor_x                            0x4ACF10
#define CDisplay__GetWorldFilePath_x                               0x4AC360
#define CDisplay__is3dON_x                                         0x4AB7F0
#define CDisplay__ReloadUI_x                                       0x4C0F70
#define CDisplay__WriteTextHD2_x                                   0x4B1DC0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E7760

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D5530
#define CEditWnd__GetCharIndexPt_x                                 0x8D65D0
#define CEditWnd__GetDisplayString_x                               0x8D56E0
#define CEditWnd__GetHorzOffset_x                                  0x8D5A20
#define CEditWnd__GetLineForPrintableChar_x                        0x8D6090
#define CEditWnd__GetSelStartPt_x                                  0x8D6890
#define CEditWnd__GetSTMLSafeText_x                                0x8D5BC0
#define CEditWnd__PointFromPrintableChar_x                         0x8D6180
#define CEditWnd__SelectableCharFromPoint_x                        0x8D6300
#define CEditWnd__SetEditable_x                                    0x8D5B90

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x552B00
#define CEverQuest__CreateTargetIndicator_x                        0x5539F0
#define CEverQuest__DeleteTargetIndicator_x                        0x553A70
#define CEverQuest__DoTellWindow_x                                 0x472D80
#define CEverQuest__OutputTextToLog_x                              0x4729E0
#define CEverQuest__DropHeldItemOnGround_x                         0x569790
#define CEverQuest__dsp_chat_x                                     0x4730C0
#define CEverQuest__trimName_x                                     0x54F450
#define CEverQuest__Emote_x                                        0x567AE0
#define CEverQuest__EnterZone_x                                    0x562AD0
#define CEverQuest__GetBodyTypeDesc_x                              0x54CEB0
#define CEverQuest__GetClassDesc_x                                 0x5562B0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5568B0
#define CEverQuest__GetDeityDesc_x                                 0x54D790
#define CEverQuest__GetLangDesc_x                                  0x54D240
#define CEverQuest__GetRaceDesc_x                                  0x556A70
#define CEverQuest__InterpretCmd_x                                 0x55A8F0
#define CEverQuest__LeftClickedOnPlayer_x                          0x56E160
#define CEverQuest__LMouseUp_x                                     0x570260
#define CEverQuest__RightClickedOnPlayer_x                         0x56EC70
#define CEverQuest__RMouseUp_x                                     0x56FCC0
#define CEverQuest__SetGameState_x                                 0x5533C0
#define CEverQuest__UPCNotificationFlush_x                         0x54ACC0
#define CEverQuest__IssuePetCommand_x                              0x55B2D0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A62B0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A6310
#define CGaugeWnd__Draw_x                                          0x6A6740

// CGuild
#define CGuild__FindMemberByName_x                                 0x437290
#define CGuild__GetGuildName_x                                     0x437760
#define CGuild__GetGuildIndex_x                                    0x438930

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C27E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6CF970
#define CInvSlotMgr__MoveItem_x                                    0x6D0810
#define CInvSlotMgr__SelectSlot_x                                  0x6CFA20

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6CEE20
#define CInvSlot__SliderComplete_x                                 0x6CC630
#define CInvSlot__GetItemBase_x                                    0x6CBA90
#define CInvSlot__UpdateItem_x                                     0x6CC010

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D1C70
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6D2D90

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79A270
#define CItemDisplayWnd__UpdateStrings_x                           0x6D3DA0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6E0E30
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6E1350
#define CItemDisplayWnd__SetItem_x                                 0x6E6DC0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7D1130

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6DABB0

// CLabel 
#define CLabel__Draw_x                                             0x6EDA90

// CListWnd
#define CListWnd__CListWnd_x                                       0x8AD040
#define CListWnd__dCListWnd_x                                      0x8AE260
#define CListWnd__AddColumn_x                                      0x8AE200
#define CListWnd__AddColumn1_x                                     0x8AD8A0
#define CListWnd__AddLine_x                                        0x8AD300
#define CListWnd__AddString_x                                      0x8AD520
#define CListWnd__CalculateFirstVisibleLine_x                      0x8AA2C0
#define CListWnd__CalculateVSBRange_x                              0x8AC510
#define CListWnd__ClearSel_x                                       0x8A95D0
#define CListWnd__ClearAllSel_x                                    0x8A9580
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8ACED0
#define CListWnd__Compare_x                                        0x8AAE40
#define CListWnd__Draw_x                                           0x8AC110
#define CListWnd__DrawColumnSeparators_x                           0x8ABFA0
#define CListWnd__DrawHeader_x                                     0x8A9890
#define CListWnd__DrawItem_x                                       0x8AB4D0
#define CListWnd__DrawLine_x                                       0x8ABC40
#define CListWnd__DrawSeparator_x                                  0x8AC040
#define CListWnd__EnableLine_x                                     0x8A97B0
#define CListWnd__EnsureVisible_x                                  0x8AA420
#define CListWnd__ExtendSel_x                                      0x8AB3E0
#define CListWnd__GetColumnMinWidth_x                              0x8A8F80
#define CListWnd__GetColumnWidth_x                                 0x8A8EB0
#define CListWnd__GetCurSel_x                                      0x8A8680
#define CListWnd__GetItemAtPoint_x                                 0x8AA6C0
#define CListWnd__GetItemAtPoint1_x                                0x8AA730
#define CListWnd__GetItemData_x                                    0x8A89C0
#define CListWnd__GetItemHeight_x                                  0x8A9F10
#define CListWnd__GetItemIcon_x                                    0x8A8BB0
#define CListWnd__GetItemRect_x                                    0x8AA500
#define CListWnd__GetItemText_x                                    0x8A8A60
#define CListWnd__GetSelList_x                                     0x8AD790
#define CListWnd__GetSeparatorRect_x                               0x8AAD60
#define CListWnd__InsertLine_x                                     0x8AD700
#define CListWnd__RemoveLine_x                                     0x8AD710
#define CListWnd__SetColors_x                                      0x8A87D0
#define CListWnd__SetColumnJustification_x                         0x8A9210
#define CListWnd__SetColumnWidth_x                                 0x8A8F30
#define CListWnd__SetCurSel_x                                      0x8A86C0
#define CListWnd__SetItemColor_x                                   0x8ACBC0
#define CListWnd__SetItemData_x                                    0x8A9630
#define CListWnd__SetItemText_x                                    0x8ACA00
#define CListWnd__ShiftColumnSeparator_x                           0x8AC890
#define CListWnd__Sort_x                                           0x8AE360
#define CListWnd__ToggleSel_x                                      0x8A9500

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x706A70

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x727EC0
#define CMerchantWnd__RequestBuyItem_x                             0x72EF50
#define CMerchantWnd__RequestSellItem_x                            0x72FA20
#define CMerchantWnd__SelectRecoverySlot_x                         0x728170
#define CMerchantWnd__SelectBuySellSlot_x                          0x727370
#define CMerchantWnd__ActualSelect_x                               0x72BE30

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x83FF60
#define CPacketScrambler__hton_x                                   0x83FF70

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8CBFD0
#define CSidlManager__CreateLabel_x                                0x7901E0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8CA4A0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8CC2B0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x653D40
#define CSidlScreenWnd__CalculateVSBRange_x                        0x653C70
#define CSidlScreenWnd__ConvertToRes_x                             0x8E7640
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8C3D60
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C4F40
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C4FF0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C44C0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8C3710
#define CSidlScreenWnd__EnableIniStorage_x                         0x8C2E80
#define CSidlScreenWnd__GetSidlPiece_x                             0x8C3900
#define CSidlScreenWnd__Init1_x                                    0x8C4C10
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C3E10
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8C3040
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C4700
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C2AD0
#define CSidlScreenWnd__StoreIniVis_x                              0x8C2E30
#define CSidlScreenWnd__WndNotification_x                          0x8C4990
#define CSidlScreenWnd__GetChildItem_x                             0x8C2F50
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B6740
#define CSidlScreenWnd__m_layoutCopy_x                             0x1714270

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F2AB0
#define CSkillMgr__GetSkillCap_x                                   0x5F2C90
#define CSkillMgr__GetNameToken_x                                  0x5F26D0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E68F0
#define CSliderWnd__SetValue_x                                     0x8E6AC0
#define CSliderWnd__SetNumTicks_x                                  0x8E7240

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x797ED0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8E2260
#define CStmlWnd__CalculateHSBRange_x                              0x8DA790
#define CStmlWnd__CalculateVSBRange_x                              0x8DA820
#define CStmlWnd__CanBreakAtCharacter_x                            0x8DA9A0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8DB280
#define CStmlWnd__ForceParseNow_x                                  0x8E2BB0
#define CStmlWnd__GetNextTagPiece_x                                0x8DB180
#define CStmlWnd__GetSTMLText_x                                    0x68B230
#define CStmlWnd__GetVisibleText_x                                 0x8DBCD0
#define CStmlWnd__InitializeWindowVariables_x                      0x8DE060
#define CStmlWnd__MakeStmlColorTag_x                               0x8D9A90
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D9AF0
#define CStmlWnd__SetSTMLText_x                                    0x8DF8B0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E1F00
#define CStmlWnd__UpdateHistoryString_x                            0x8DCC10

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8D9120
#define CTabWnd__DrawCurrentPage_x                                 0x8D89B0
#define CTabWnd__DrawTab_x                                         0x8D8770
#define CTabWnd__GetCurrentPage_x                                  0x8D8D60
#define CTabWnd__GetPageInnerRect_x                                0x8D8460
#define CTabWnd__GetTabInnerRect_x                                 0x8D8660
#define CTabWnd__GetTabRect_x                                      0x8D8530
#define CTabWnd__InsertPage_x                                      0x8D9410
#define CTabWnd__SetPage_x                                         0x8D8D90
#define CTabWnd__SetPageRect_x                                     0x8D9060
#define CTabWnd__UpdatePage_x                                      0x8D93B0
#define CTabWnd__GetPageFromTabIndex_x                             0x8D86C0
#define CTabWnd__GetCurrentTabIndex_x                              0x8D83F0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6D2F40
#define CPageWnd__SetTabText_x                                     0x8F0650

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432DF0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C0D70
#define CTextureFont__GetTextExtent_x                              0x8C0AD0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x62B510

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8ECA90

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A6790

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029B0
#define CXStr__CXStr1_x                                            0x7D9020
#define CXStr__CXStr3_x                                            0x889C70
#define CXStr__dCXStr_x                                            0x594A10
#define CXStr__operator_equal_x                                    0x889DE0
#define CXStr__operator_equal1_x                                   0x889E30
#define CXStr__operator_plus_equal1_x                              0x88AF30

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B5950
#define CXWnd__Center_x                                            0x8BBB50
#define CXWnd__ClrFocus_x                                          0x8B5530
#define CXWnd__Destroy_x                                           0x8BC630
#define CXWnd__DoAllDrawing_x                                      0x8BB7A0
#define CXWnd__DrawChildren_x                                      0x8BB940
#define CXWnd__DrawColoredRect_x                                   0x8B5D10
#define CXWnd__DrawTooltip_x                                       0x8B5FC0
#define CXWnd__DrawTooltipAtPoint_x                                0x8BA710
#define CXWnd__GetBorderFrame_x                                    0x8B6400
#define CXWnd__GetChildWndAt_x                                     0x8BC510
#define CXWnd__GetClientClipRect_x                                 0x8B61D0
#define CXWnd__GetScreenClipRect_x                                 0x8BAE10
#define CXWnd__GetScreenRect_x                                     0x8B65E0
#define CXWnd__GetTooltipRect_x                                    0x8B5E50
#define CXWnd__GetWindowTextA_x                                    0x424490
#define CXWnd__IsActive_x                                          0x8B1060
#define CXWnd__IsDescendantOf_x                                    0x8B6340
#define CXWnd__IsReallyVisible_x                                   0x8B9720
#define CXWnd__IsType_x                                            0x8E92B0
#define CXWnd__Move_x                                              0x8B8E40
#define CXWnd__Move1_x                                             0x8BB440
#define CXWnd__ProcessTransition_x                                 0x8B58F0
#define CXWnd__Refade_x                                            0x8B56D0
#define CXWnd__Resize_x                                            0x8B66A0
#define CXWnd__Right_x                                             0x8BAC10
#define CXWnd__SetFocus_x                                          0x8B7FA0
#define CXWnd__SetFont_x                                           0x8B5580
#define CXWnd__SetKeyTooltip_x                                     0x8B6910
#define CXWnd__SetMouseOver_x                                      0x8BB140
#define CXWnd__StartFade_x                                         0x8B59A0
#define CXWnd__GetChildItem_x                                      0x8BB080
#define CXWnd__SetParent_x                                         0x8BC4C0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B2900
#define CXWndManager__DrawWindows_x                                0x8B2540
#define CXWndManager__GetKeyboardFlags_x                           0x8B0BA0
#define CXWndManager__HandleKeyboardMsg_x                          0x8B14F0
#define CXWndManager__RemoveWnd_x                                  0x8B11F0

// CDBStr
#define CDBStr__GetString_x                                        0x4A9DB0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E040
#define EQ_Character__Cur_HP_x                                     0x462CC0
#define EQ_Character__Cur_Mana_x                                   0x456780
#define EQ_Character__GetAACastingTimeModifier_x                   0x447270
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F4E0
#define EQ_Character__GetFocusRangeModifier_x                      0x43F540
#define EQ_Character__GetHPRegen_x                                 0x465ED0
#define EQ_Character__GetEnduranceRegen_x                          0x4620E0
#define EQ_Character__GetManaRegen_x                               0x466470
#define EQ_Character__Max_Endurance_x                              0x5B9460
#define EQ_Character__Max_HP_x                                     0x459400
#define EQ_Character__Max_Mana_x                                   0x5B9290
#define EQ_Character__doCombatAbility_x                            0x5B6980
#define EQ_Character__UseSkill_x                                   0x46D150
#define EQ_Character__GetConLevel_x                                0x5AC110
#define EQ_Character__IsExpansionFlag_x                            0x4239E0
#define EQ_Character__TotalEffect_x                                0x44B2F0
#define EQ_Character__GetPCSpellAffect_x                           0x447670
#define EQ_Character__SpellDuration_x                              0x445570
#define EQ_Character__FindItemByRecord_x                           0x460120
#define EQ_Character__GetAdjustedSkill_x                           0x463470
#define EQ_Character__GetBaseSkill_x                               0x4592E0

//ProfileManager_
#define ProfileManager__GetCurrentProfile_x                        0x85CD50

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5C1100

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x442890
#define CCharacterSelect__EnterWorld_x                             0x442060
#define CCharacterSelect__Quit_x                                   0x440C40

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x58C8C0
#define EQ_Item__CreateItemTagString_x                             0x83E8B0
#define EQ_Item__IsStackable_x                                     0x834050
#define EQ_Item__GetImageNum_x                                     0x836A60
#define EQ_Item__CreateItemClient_x                                0x58D480
#define EQ_Item__GetItemValue_x                                    0x83D5E0
#define EQ_Item__ValueSellMerchant_x                               0x83FBC0
#define EQ_Item__IsKeyRingItem_x                                   0x834A80
#define EQ_Item__CanGoInBag_x                                      0x58CA50
#define EQ_Item__GetMaxItemCount_x                                 0x833F40
#define EQ_Item__GetHeldItem_x                                     0x835880
#define EQ_Item__GetAugmentFitBySlot_x                             0x83F9E0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C9AB0
#define EQ_LoadingS__Array_x                                       0xBEACC8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BB800
#define EQ_PC__GetAlternateAbilityId_x                             0x847FD0
#define EQ_PC__GetCombatAbility_x                                  0x848060
#define EQ_PC__GetCombatAbilityTimer_x                             0x842D70
#define EQ_PC__GetItemRecastTimer_x                                0x5B5030
#define EQ_PC__HasLoreItem_x                                       0x5AF620
#define EQ_PC__AlertInventoryChanged_x                             0x5AC0E0
#define EQ_PC__GetPcZoneClient_x                                   0x5D55D0
#define EQ_PC__RemoveMyAffect_x                                    0x5B4500
#define EQ_PC__GetKeyRingItems_x                                   0x843190
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x855770
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x849F70

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5152B0
#define EQItemList__add_object_x                                   0x541C30
#define EQItemList__add_item_x                                     0x5151F0
#define EQItemList__delete_item_x                                  0x5156A0
#define EQItemList__FreeItemList_x                                 0x5155A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A90F0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C0EA0
#define EQPlayer__dEQPlayer_x                                      0x5C9440
#define EQPlayer__DoAttack_x                                       0x5DB4C0
#define EQPlayer__EQPlayer_x                                       0x5CBB50
#define EQPlayer__SetNameSpriteState_x                             0x5C63B0
#define EQPlayer__SetNameSpriteTint_x                              0x5C22B0
#define PlayerBase__HasProperty_j_x                                0x91A110
#define EQPlayer__IsTargetable_x                                   0x91A3B0
#define EQPlayer__CanSee_x                                         0x91A910
#define PlayerZoneClient__ChangeHeight_x                           0x5DB380
#define EQPlayer__CanSeeTargetIndicator_x                          0x91AA00
#define PlayerBase__GetVisibilityLineSegment_x                     0x91A6A0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5CFC20
#define EQPlayerManager__GetSpawnByName_x                          0x5D0080
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5CFC50

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x592A00
#define KeypressHandler__AttachKeyToEqCommand_x                    0x592A40
#define KeypressHandler__ClearCommandStateArray_x                  0x5925F0
#define KeypressHandler__HandleKeyDown_x                           0x590F50
#define KeypressHandler__HandleKeyUp_x                             0x591270
#define KeypressHandler__SaveKeymapping_x                          0x5926C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6FF400
#define MapViewMap__SaveEx_x                                       0x702730

#define PlayerPointManager__GetAltCurrency_x                       0x85AE40

// StringTable 
#define StringTable__getString_x                                   0x855AA0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B8EF0
#define PcZoneClient__RemovePetEffect_x                            0x5B5500
#define PcZoneClient__HasAlternateAbility_x                        0x5B5EA0
#define PcZoneClient__GetCurrentMod_x                              0x4587A0
#define PcZoneClient__GetModCap_x                                  0x455F00
#define PcZoneClient__CanEquipItem_x                               0x5B6450
#define PcZoneClient__GetItemByID_x                                0x5BACE0
#define PcZoneClient__GetItemByItemClass_x                         0x5BB720

//Doors
#define EQSwitch__UseSwitch_x                                      0x5495F0

//IconCache
#define IconCache__GetIcon_x                                       0x69BAD0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x692860
#define CContainerMgr__CloseContainer_x                            0x693080

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7600B0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x585B30

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E3D10
#define EQ_Spell__SpellAffects_x                                   0x4E13C0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4E1430
#define CharacterZoneClient__CalcAffectChange_x                    0x4466A0
#define CLootWnd__LootAll_x                                        0x6F4CF0
#define CLootWnd__RequestLootSlot_x                                0x6F5500

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7A6E90
#define CTargetWnd__WndNotification_x                              0x7A6980
#define CTargetWnd__RefreshTargetBuffs_x                           0x7A7070

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7ABF90

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4DCA00

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x498B80

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8D4B60
#define CSidlManager__FindAnimation1_x                             0x8C9ED0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D1300
#define CAltAbilityData__GetMercMaxRank_x                          0x4D12B0
#define CAltAbilityData__GetMaxRank_x                              0x4C5BC0

//CTargetRing
#define CTargetRing__Cast_x                                        0x583420

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x454EE0
#define CharacterBase__CreateItemGlobalIndex_x                     0x471F20
#define CharacterBase__CreateItemIndex_x                           0x50E780
#define CharacterBase__GetItemPossession_x                         0x4400F0
#define CharacterBase__GetItemByGlobalIndex_x                      0x86AEC0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x67CFA0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x67C700

//messages
#define msg_spell_worn_off_x                                       0x4EB960
#define msg_new_text_x                                             0x4F4F00
#define msgTokenTextParam_x                                        0x4F18B0

//SpellManager
#define SpellManager__vftable_x                                    0xAAD038
#define SpellManager__SpellManager_x                               0x47AD70
#define Spellmanager__CheckSpellRequirementAssociations_x          0x5F98C0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x91E3F0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E7EB0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43AC60
#define ItemGlobalIndex__IsEquippedLocation_x                      0x444F10
#define ItemGlobalIndex__IsValidIndex_x                            0x454760

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x868CD0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x867C10

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6EDCE0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6976F0
#define CCursorAttachment__Deactivate_x                            0x696C30
