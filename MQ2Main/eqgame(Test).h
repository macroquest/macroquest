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
#define __ExpectedVersionDate                                     "Feb  2 2017"
#define __ExpectedVersionTime                                     "11:49:52"
#define __ActualVersionDate_x                                      0xAC6A20
#define __ActualVersionTime_x                                      0xAC6A2C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x5982A0
#define __MemChecker1_x                                            0x88D4D0
#define __MemChecker2_x                                            0x62DFD0
#define __MemChecker3_x                                            0x62DF20
#define __MemChecker4_x                                            0x7E0A00
#define __EncryptPad0_x                                            0xC20100
#define __EncryptPad1_x                                            0xCFF998
#define __EncryptPad2_x                                            0xC4A2A0
#define __EncryptPad3_x                                            0xC49EA0
#define __EncryptPad4_x                                            0xCED650
#define __EncryptPad5_x                                            0x10A8548
#define __AC1_x                                                    0x79FEB5
#define __AC2_x                                                    0x552507
#define __AC3_x                                                    0x5506A0
#define __AC4_x                                                    0x562A90
#define __AC5_x                                                    0x5757EB
#define __AC6_x                                                    0x57938E
#define __AC7_x                                                    0x56FE5C
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
#define pinstEverQuestInfo_x                                       0xF16B98
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
#define __EQGetTime_x                                              0x88D160
#define __get_melee_range_x                                        0x517220
#define __GetGaugeValueFromEQ_x                                    0x79EBF0
#define __GetLabelFromEQ_x                                         0x79FE40
#define __ToggleKeyRingItem_x                                      0x4803E0
#define __GetXTargetType_x                                         0x91D920
#define __LoadFrontEnd_x                                           0x62D6A0
#define __NewUIINI_x                                               0x79E5D0
#define __ProcessGameEvents_x                                      0x571BF0
#define __ProcessMouseEvent_x                                      0x571390
#define CrashDetected_x                                            0x62F060
#define wwsCrashReportCheckForUploader_x                           0x7EC440
#define __AppCrashWrapper_x                                        0xC49E90
#define __pCrashHandler_x                                          0x10BD790
#define __CrashHandler_x                                           0x7EBED0
#define wwsCrashReportPlatformLaunchUploader_x                     0x7EE670
#define DrawNetStatus_x                                            0x5A7FB0
#define Util__FastTime_x                                           0x88CE00
#define Expansion_HoT_x                                            0xF17F60
#define __HelpPath_x                                               0xF9B660
#define __STMLToText_x                                             0x8D2F40

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4205C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B360
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B140

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C7790
#define AltAdvManager__IsAbilityReady_x                            0x4C7800
#define AltAdvManager__GetAAById_x                                 0x4C7CF0
#define AltAdvManager__CanTrainAbility_x                           0x4C8920
#define AltAdvManager__CanSeeAbility_x                             0x4C84E0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463920
#define CharacterZoneClient__MakeMeVisible_x                       0x468330
#define CharacterZoneClient__IsStackBlocked_x                      0x447CC0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x447180
#define CharacterZoneClient__GetItemCountWorn_x                    0x4616B0
#define CharacterZoneClient__GetItemCountInInventory_x             0x461790
#define CharacterZoneClient__GetCursorItemCount_x                  0x461870
#define CharacterZoneClient__FindAffectSlot_x                      0x44D200

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x65CEF0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66B160

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x587230
#define CButtonWnd__CButtonWnd_x                                   0x8C7310

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x686240
#define CChatManager__InitContextMenu_x                            0x686DC0
#define CChatManager__FreeChatWindow_x                             0x685D20
#define CChatManager__GetLockedActiveChatWindow_x                  0x68B570
#define CChatManager__SetLockedActiveChatWindow_x                  0x686210
// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D12A0
#define CContextMenu__dCContextMenu_x                              0x8D14B0
#define CContextMenu__AddMenuItem_x                                0x8D14C0
#define CContextMenu__RemoveMenuItem_x                             0x8D17B0
#define CContextMenu__RemoveAllMenuItems_x                         0x8D17D0
#define CContextMenuManager__AddMenu_x                             0x8BD860
#define CContextMenuManager__RemoveMenu_x                          0x8BDBF0
#define CContextMenuManager__PopupMenu_x                           0x8BE040
#define CContextMenuManager__Flush_x                               0x8BD8D0
#define CContextMenuManager__GetMenu_x                             0x416A40
#define CContextMenu__CheckMenuItem_x                              0x8D1850

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x871630
#define CChatService__GetFriendName_x                              0x871640

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x68C0B0
#define CChatWindow__Clear_x                                       0x68BC90
#define CChatWindow__WndNotification_x                             0x68C5E0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C16B0
#define CComboWnd__Draw_x                                          0x8C18C0
#define CComboWnd__GetCurChoice_x                                  0x8C1460
#define CComboWnd__GetListRect_x                                   0x8C1B60
#define CComboWnd__GetTextRect_x                                   0x8C1720
#define CComboWnd__InsertChoice_x                                  0x8C1BD0
#define CComboWnd__SetColors_x                                     0x8C13F0
#define CComboWnd__SetChoice_x                                     0x8C1420
#define CComboWnd__GetItemCount_x                                  0x8C1450
#define CComboWnd__GetCurChoiceText_x                              0x8C14A0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6957C0
#define CContainerWnd__vftable_x                                   0xAD04E8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B5C80
#define CDisplay__GetClickedActor_x                                0x4AE5B0
#define CDisplay__GetUserDefinedColor_x                            0x4AD190
#define CDisplay__GetWorldFilePath_x                               0x4AC5E0
#define CDisplay__is3dON_x                                         0x4ABA70
#define CDisplay__ReloadUI_x                                       0x4C11F0
#define CDisplay__WriteTextHD2_x                                   0x4B2040

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E7930

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D57D0
#define CEditWnd__GetCharIndexPt_x                                 0x8D6870
#define CEditWnd__GetDisplayString_x                               0x8D5980
#define CEditWnd__GetHorzOffset_x                                  0x8D5CC0
#define CEditWnd__GetLineForPrintableChar_x                        0x8D6330
#define CEditWnd__GetSelStartPt_x                                  0x8D6B30
#define CEditWnd__GetSTMLSafeText_x                                0x8D5E60
#define CEditWnd__PointFromPrintableChar_x                         0x8D6420
#define CEditWnd__SelectableCharFromPoint_x                        0x8D65A0
#define CEditWnd__SetEditable_x                                    0x8D5E30

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5592C0
#define CEverQuest__ClickedPlayer_x                                0x552C50
#define CEverQuest__CreateTargetIndicator_x                        0x553B40
#define CEverQuest__DeleteTargetIndicator_x                        0x553BC0
#define CEverQuest__DoTellWindow_x                                 0x472FE0
#define CEverQuest__OutputTextToLog_x                              0x472C40
#define CEverQuest__DropHeldItemOnGround_x                         0x5698E0
#define CEverQuest__dsp_chat_x                                     0x473320
#define CEverQuest__trimName_x                                     0x54F5A0
#define CEverQuest__Emote_x                                        0x567C30
#define CEverQuest__EnterZone_x                                    0x562C20
#define CEverQuest__GetBodyTypeDesc_x                              0x54D000
#define CEverQuest__GetClassDesc_x                                 0x556400
#define CEverQuest__GetClassThreeLetterCode_x                      0x556A00
#define CEverQuest__GetDeityDesc_x                                 0x54D8E0
#define CEverQuest__GetLangDesc_x                                  0x54D390
#define CEverQuest__GetRaceDesc_x                                  0x556BC0
#define CEverQuest__InterpretCmd_x                                 0x55AA40
#define CEverQuest__LeftClickedOnPlayer_x                          0x56E2B0
#define CEverQuest__LMouseUp_x                                     0x5703B0
#define CEverQuest__RightClickedOnPlayer_x                         0x56EDC0
#define CEverQuest__RMouseUp_x                                     0x56FE10
#define CEverQuest__SetGameState_x                                 0x553510
#define CEverQuest__UPCNotificationFlush_x                         0x54AE10
#define CEverQuest__IssuePetCommand_x                              0x55B420

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A65F0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A6650
#define CGaugeWnd__Draw_x                                          0x6A6A80

// CGuild
#define CGuild__FindMemberByName_x                                 0x437450
#define CGuild__GetGuildName_x                                     0x437920
#define CGuild__GetGuildIndex_x                                    0x438AF0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C2B10

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6CFCA0
#define CInvSlotMgr__MoveItem_x                                    0x6D0B40
#define CInvSlotMgr__SelectSlot_x                                  0x6CFD50

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6CF150
#define CInvSlot__SliderComplete_x                                 0x6CC960
#define CInvSlot__GetItemBase_x                                    0x6CBDC0
#define CInvSlot__UpdateItem_x                                     0x6CC340

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D1FA0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6D30C0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79A610
#define CItemDisplayWnd__UpdateStrings_x                           0x6D40D0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6E1160
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6E1680
#define CItemDisplayWnd__SetItem_x                                 0x6E70F0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7D1540

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6DAEE0

// CLabel 
#define CLabel__Draw_x                                             0x6EDDC0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8AD330
#define CListWnd__dCListWnd_x                                      0x8AE550
#define CListWnd__AddColumn_x                                      0x8AE4F0
#define CListWnd__AddColumn1_x                                     0x8ADB90
#define CListWnd__AddLine_x                                        0x8AD5F0
#define CListWnd__AddString_x                                      0x8AD810
#define CListWnd__CalculateFirstVisibleLine_x                      0x8AA5B0
#define CListWnd__CalculateVSBRange_x                              0x8AC800
#define CListWnd__ClearSel_x                                       0x8A98C0
#define CListWnd__ClearAllSel_x                                    0x8A9870
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8AD1C0
#define CListWnd__Compare_x                                        0x8AB130
#define CListWnd__Draw_x                                           0x8AC400
#define CListWnd__DrawColumnSeparators_x                           0x8AC290
#define CListWnd__DrawHeader_x                                     0x8A9B80
#define CListWnd__DrawItem_x                                       0x8AB7C0
#define CListWnd__DrawLine_x                                       0x8ABF30
#define CListWnd__DrawSeparator_x                                  0x8AC330
#define CListWnd__EnableLine_x                                     0x8A9AA0
#define CListWnd__EnsureVisible_x                                  0x8AA710
#define CListWnd__ExtendSel_x                                      0x8AB6D0
#define CListWnd__GetColumnMinWidth_x                              0x8A9270
#define CListWnd__GetColumnWidth_x                                 0x8A91A0
#define CListWnd__GetCurSel_x                                      0x8A8970
#define CListWnd__GetItemAtPoint_x                                 0x8AA9B0
#define CListWnd__GetItemAtPoint1_x                                0x8AAA20
#define CListWnd__GetItemData_x                                    0x8A8CB0
#define CListWnd__GetItemHeight_x                                  0x8AA200
#define CListWnd__GetItemIcon_x                                    0x8A8EA0
#define CListWnd__GetItemRect_x                                    0x8AA7F0
#define CListWnd__GetItemText_x                                    0x8A8D50
#define CListWnd__GetSelList_x                                     0x8ADA80
#define CListWnd__GetSeparatorRect_x                               0x8AB050
#define CListWnd__InsertLine_x                                     0x8AD9F0
#define CListWnd__RemoveLine_x                                     0x8ADA00
#define CListWnd__SetColors_x                                      0x8A8AC0
#define CListWnd__SetColumnJustification_x                         0x8A9500
#define CListWnd__SetColumnWidth_x                                 0x8A9220
#define CListWnd__SetCurSel_x                                      0x8A89B0
#define CListWnd__SetItemColor_x                                   0x8ACEB0
#define CListWnd__SetItemData_x                                    0x8A9920
#define CListWnd__SetItemText_x                                    0x8ACCF0
#define CListWnd__ShiftColumnSeparator_x                           0x8ACB80
#define CListWnd__Sort_x                                           0x8AE650
#define CListWnd__ToggleSel_x                                      0x8A97F0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x706EE0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x728410
#define CMerchantWnd__RequestBuyItem_x                             0x72F4A0
#define CMerchantWnd__RequestSellItem_x                            0x72FF70
#define CMerchantWnd__SelectRecoverySlot_x                         0x7286C0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7278C0
#define CMerchantWnd__ActualSelect_x                               0x72C380

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x840270
#define CPacketScrambler__hton_x                                   0x840280

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8CC1D0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8CC2B0
#define CSidlManager__CreateLabel_x                                0x7905F0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8CA780
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8CC590

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x654210
#define CSidlScreenWnd__CalculateVSBRange_x                        0x654140
#define CSidlScreenWnd__ConvertToRes_x                             0x8E7810
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8C4050
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C5230
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C52E0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C47B0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8C3A00
#define CSidlScreenWnd__EnableIniStorage_x                         0x8C3170
#define CSidlScreenWnd__GetSidlPiece_x                             0x8C3BF0
#define CSidlScreenWnd__Init1_x                                    0x8C4F00
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C4100
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8C3330
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C49F0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C2DC0
#define CSidlScreenWnd__StoreIniVis_x                              0x8C3120
#define CSidlScreenWnd__WndNotification_x                          0x8C4C80
#define CSidlScreenWnd__GetChildItem_x                             0x8C3240
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B6A30
#define CSidlScreenWnd__m_layoutCopy_x                             0x1714270

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F2F70
#define CSkillMgr__GetSkillCap_x                                   0x5F3150
#define CSkillMgr__GetNameToken_x                                  0x5F2B90

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E6AC0
#define CSliderWnd__SetValue_x                                     0x8E6C90
#define CSliderWnd__SetNumTicks_x                                  0x8E7410

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x798270

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8E2480
#define CStmlWnd__CalculateHSBRange_x                              0x8DA9B0
#define CStmlWnd__CalculateVSBRange_x                              0x8DAA40
#define CStmlWnd__CanBreakAtCharacter_x                            0x8DABC0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8DB4A0
#define CStmlWnd__ForceParseNow_x                                  0x8E2DD0
#define CStmlWnd__GetNextTagPiece_x                                0x8DB3A0
#define CStmlWnd__GetSTMLText_x                                    0x68B530
#define CStmlWnd__GetVisibleText_x                                 0x8DBEF0
#define CStmlWnd__InitializeWindowVariables_x                      0x8DE280
#define CStmlWnd__MakeStmlColorTag_x                               0x8D9CB0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D9D10
#define CStmlWnd__SetSTMLText_x                                    0x8DFAD0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E2120
#define CStmlWnd__UpdateHistoryString_x                            0x8DCE30

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8D93C0
#define CTabWnd__DrawCurrentPage_x                                 0x8D8C50
#define CTabWnd__DrawTab_x                                         0x8D8A10
#define CTabWnd__GetCurrentPage_x                                  0x8D9000
#define CTabWnd__GetPageInnerRect_x                                0x8D8700
#define CTabWnd__GetTabInnerRect_x                                 0x8D8900
#define CTabWnd__GetTabRect_x                                      0x8D87D0
#define CTabWnd__InsertPage_x                                      0x8D96B0
#define CTabWnd__SetPage_x                                         0x8D9030
#define CTabWnd__SetPageRect_x                                     0x8D9300
#define CTabWnd__UpdatePage_x                                      0x8D9650
#define CTabWnd__GetPageFromTabIndex_x                             0x8D8960
#define CTabWnd__GetCurrentTabIndex_x                              0x8D8690

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6D3270
#define CPageWnd__SetTabText_x                                     0x8F0820

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x433060

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C1060
#define CTextureFont__GetTextExtent_x                              0x8C0DC0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x62B930

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8ECC60

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A6C20

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029A0
#define CXStr__CXStr1_x                                            0x7D9470
#define CXStr__CXStr3_x                                            0x88A0A0
#define CXStr__dCXStr_x                                            0x594B80
#define CXStr__operator_equal_x                                    0x88A210
#define CXStr__operator_equal1_x                                   0x88A260
#define CXStr__operator_plus_equal1_x                              0x88B360

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B5C40
#define CXWnd__Center_x                                            0x8BBE40
#define CXWnd__ClrFocus_x                                          0x8B5820
#define CXWnd__Destroy_x                                           0x8BC920
#define CXWnd__DoAllDrawing_x                                      0x8BBA90
#define CXWnd__DrawChildren_x                                      0x8BBC30
#define CXWnd__DrawColoredRect_x                                   0x8B6000
#define CXWnd__DrawTooltip_x                                       0x8B62B0
#define CXWnd__DrawTooltipAtPoint_x                                0x8BAA00
#define CXWnd__GetBorderFrame_x                                    0x8B66F0
#define CXWnd__GetChildWndAt_x                                     0x8BC800
#define CXWnd__GetClientClipRect_x                                 0x8B64C0
#define CXWnd__GetScreenClipRect_x                                 0x8BB100
#define CXWnd__GetScreenRect_x                                     0x8B68D0
#define CXWnd__GetTooltipRect_x                                    0x8B6140
#define CXWnd__GetWindowTextA_x                                    0x4246A0
#define CXWnd__IsActive_x                                          0x8B1350
#define CXWnd__IsDescendantOf_x                                    0x8B6630
#define CXWnd__IsReallyVisible_x                                   0x8B9A10
#define CXWnd__IsType_x                                            0x8E94C0
#define CXWnd__Move_x                                              0x8B9130
#define CXWnd__Move1_x                                             0x8BB730
#define CXWnd__ProcessTransition_x                                 0x8B5BE0
#define CXWnd__Refade_x                                            0x8B59C0
#define CXWnd__Resize_x                                            0x8B6990
#define CXWnd__Right_x                                             0x8BAF00
#define CXWnd__SetFocus_x                                          0x8B8290
#define CXWnd__SetFont_x                                           0x8B5870
#define CXWnd__SetKeyTooltip_x                                     0x8B6C00
#define CXWnd__SetMouseOver_x                                      0x8BB430
#define CXWnd__StartFade_x                                         0x8B5C90
#define CXWnd__GetChildItem_x                                      0x8BB370
#define CXWnd__SetParent_x                                         0x8BC7B0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B2BF0
#define CXWndManager__DrawWindows_x                                0x8B2830
#define CXWndManager__GetKeyboardFlags_x                           0x8B0E90
#define CXWndManager__HandleKeyboardMsg_x                          0x8B17E0
#define CXWndManager__RemoveWnd_x                                  0x8B14E0

// CDBStr
#define CDBStr__GetString_x                                        0x4AA030

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E260
#define EQ_Character__Cur_HP_x                                     0x462F20
#define EQ_Character__Cur_Mana_x                                   0x4569E0
#define EQ_Character__GetAACastingTimeModifier_x                   0x447490
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F6B0
#define EQ_Character__GetFocusRangeModifier_x                      0x43F710
#define EQ_Character__GetHPRegen_x                                 0x466130
#define EQ_Character__GetEnduranceRegen_x                          0x462340
#define EQ_Character__GetManaRegen_x                               0x4666D0
#define EQ_Character__Max_Endurance_x                              0x5B9FA0
#define EQ_Character__Max_HP_x                                     0x459660
#define EQ_Character__Max_Mana_x                                   0x5B9DD0
#define EQ_Character__doCombatAbility_x                            0x5B74C0
#define EQ_Character__UseSkill_x                                   0x46D3B0
#define EQ_Character__GetConLevel_x                                0x5AC550
#define EQ_Character__IsExpansionFlag_x                            0x423BF0
#define EQ_Character__TotalEffect_x                                0x44B510
#define EQ_Character__GetPCSpellAffect_x                           0x447890
#define EQ_Character__SpellDuration_x                              0x445790
#define EQ_Character__FindItemByRecord_x                           0x460380
#define EQ_Character__GetAdjustedSkill_x                           0x4636D0
#define EQ_Character__GetBaseSkill_x                               0x459540

//ProfileManager_
#define ProfileManager__GetCurrentProfile_x                        0x85D1B0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5C1C30

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x442A90
#define CCharacterSelect__EnterWorld_x                             0x442260
#define CCharacterSelect__Quit_x                                   0x440E40

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x58CA30
#define EQ_Item__CreateItemTagString_x                             0x83EBC0
#define EQ_Item__IsStackable_x                                     0x834360
#define EQ_Item__GetImageNum_x                                     0x836D70
#define EQ_Item__CreateItemClient_x                                0x58D5F0
#define EQ_Item__GetItemValue_x                                    0x83D8F0
#define EQ_Item__ValueSellMerchant_x                               0x83FED0
#define EQ_Item__IsKeyRingItem_x                                   0x834D90
#define EQ_Item__CanGoInBag_x                                      0x58CBC0
#define EQ_Item__GetMaxItemCount_x                                 0x834250
#define EQ_Item__GetHeldItem_x                                     0x835B90
#define EQ_Item__GetAugmentFitBySlot_x                             0x83FCF0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C9E70
#define EQ_LoadingS__Array_x                                       0xBEACC8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BC340
#define EQ_PC__GetAlternateAbilityId_x                             0x8482C0
#define EQ_PC__GetCombatAbility_x                                  0x848350
#define EQ_PC__GetCombatAbilityTimer_x                             0x843080
#define EQ_PC__GetItemRecastTimer_x                                0x5B5B70
#define EQ_PC__HasLoreItem_x                                       0x5AFA60
#define EQ_PC__AlertInventoryChanged_x                             0x5AC520
#define EQ_PC__GetPcZoneClient_x                                   0x5D6010
#define EQ_PC__RemoveMyAffect_x                                    0x5B5040
#define EQ_PC__GetKeyRingItems_x                                   0x8434A0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x855A60
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x84A260

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5152B0
#define EQItemList__add_object_x                                   0x541CE0
#define EQItemList__add_item_x                                     0x5151F0
#define EQItemList__delete_item_x                                  0x5156A0
#define EQItemList__FreeItemList_x                                 0x5155A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A9370

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C19D0
#define EQPlayer__dEQPlayer_x                                      0x5C9F70
#define EQPlayer__DoAttack_x                                       0x5DBF00
#define EQPlayer__EQPlayer_x                                       0x5CC680
#define EQPlayer__SetNameSpriteState_x                             0x5C6EE0
#define EQPlayer__SetNameSpriteTint_x                              0x5C2DE0
#define PlayerBase__HasProperty_j_x                                0x91A190
#define EQPlayer__IsTargetable_x                                   0x91A430
#define EQPlayer__CanSee_x                                         0x91A990
#define PlayerZoneClient__ChangeHeight_x                           0x5DBDC0
#define EQPlayer__CanSeeTargetIndicator_x                          0x91AA80
#define PlayerBase__GetVisibilityLineSegment_x                     0x91A720

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D0660
#define EQPlayerManager__GetSpawnByName_x                          0x5D0AC0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D0690

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x592B70
#define KeypressHandler__AttachKeyToEqCommand_x                    0x592BB0
#define KeypressHandler__ClearCommandStateArray_x                  0x592760
#define KeypressHandler__HandleKeyDown_x                           0x5910C0
#define KeypressHandler__HandleKeyUp_x                             0x5913E0
#define KeypressHandler__SaveKeymapping_x                          0x592830

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6FF870
#define MapViewMap__SaveEx_x                                       0x702BA0

#define PlayerPointManager__GetAltCurrency_x                       0x85B2A0

// StringTable 
#define StringTable__getString_x                                   0x855D90

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B9A30
#define PcZoneClient__RemovePetEffect_x                            0x5B6040
#define PcZoneClient__HasAlternateAbility_x                        0x5B69E0
#define PcZoneClient__GetCurrentMod_x                              0x458A00
#define PcZoneClient__GetModCap_x                                  0x456160
#define PcZoneClient__CanEquipItem_x                               0x5B6F90
#define PcZoneClient__GetItemByID_x                                0x5BB820
#define PcZoneClient__GetItemByItemClass_x                         0x5BC260

//Doors
#define EQSwitch__UseSwitch_x                                      0x5496B0

//IconCache
#define IconCache__GetIcon_x                                       0x69BDE0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x692B60
#define CContainerMgr__CloseContainer_x                            0x693380

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x760580

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x585CB0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E3E60
#define EQ_Spell__SpellAffects_x                                   0x4E1510
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4E1580
#define CharacterZoneClient__CalcAffectChange_x                    0x4468C0
#define CLootWnd__LootAll_x                                        0x6F5010
#define CLootWnd__RequestLootSlot_x                                0x6F5820

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7A7280
#define CTargetWnd__WndNotification_x                              0x7A6D70
#define CTargetWnd__RefreshTargetBuffs_x                           0x7A7460

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7AC390

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4DCB20

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x498DC0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8D4E00
#define CSidlManager__FindAnimation1_x                             0x8CA1B0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D1560
#define CAltAbilityData__GetMercMaxRank_x                          0x4D1510
#define CAltAbilityData__GetMaxRank_x                              0x4C5E40

//CTargetRing
#define CTargetRing__Cast_x                                        0x5835A0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4550D0
#define CharacterBase__CreateItemGlobalIndex_x                     0x472180
#define CharacterBase__CreateItemIndex_x                           0x50E7E0
#define CharacterBase__GetItemPossession_x                         0x440310
#define CharacterBase__GetItemByGlobalIndex_x                      0x86B300

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x67D3B0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x67CB10

//messages
#define msg_spell_worn_off_x                                       0x4EBAA0
#define msg_new_text_x                                             0x4F5040
#define msgTokenTextParam_x                                        0x4F19F0

//SpellManager
#define SpellManager__vftable_x                                    0xAAD038
#define SpellManager__SpellManager_x                               0x47B020
#define Spellmanager__CheckSpellRequirementAssociations_x          0x5F9DE0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x91E440

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E7FD0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43AE20
#define ItemGlobalIndex__IsEquippedLocation_x                      0x445110
#define ItemGlobalIndex__IsValidIndex_x                            0x454980

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x869110
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x868050

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6EE010

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6979F0
#define CCursorAttachment__Deactivate_x                            0x696F30
